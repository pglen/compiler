
  /* -------- System includes:  -------------------------------------------- */

#include <sys/stat.h>
#include <syslog.h>
#include <time.h>
#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>

#include "symtab.h"
#include "pcomp.h"

// Main Entry point

int     help()

{
    printf("\n");
    printf(" ----------------------------------------------------\n");
    printf("  Parallel compiler by Peter Glen. 2007-2019-2025    \n");
    printf(" ----------------------------------------------------\n");
    printf("\n");
    printf(" Usage: pcomp [options] filename(s)\n");
    printf("       -a no assembly phase\n");
    printf("       -b show alloc buffers\n");
    printf("       -c cat assembly to stdout\n");
    printf("       -d debug level\n");
    printf("       -i interlace symtab in output\n");
    printf("       -f show lex output\n");
    printf("       -m show comments in source\n");
    printf("       -n do not show progress\n");
    printf("       -o output file\n");
    printf("       -p no prologue for assembly\n");
    printf("       -r no pre processing\n");
    printf("       -q cat pre processing to stdout\n");
    printf("       -s show symtab\n");
    printf("       -t do not compile\n");
    printf("       -v verbose\n");
    printf("       -y show yacc output\n");
    printf("       -h help (this screen)\n");
    printf("\n");

    exit(1);
}

///////////////////////////////////////////////////////////////////////////
//

void calc_usec_diff(struct timespec *ts, struct timespec *ts2, int *pdts, int *pdtu)

{
	#define CALC_NANO  1000000000
	#define CALC_MICRO 1000000

	// Wrapping nanoseconds
	// --------^------^-----|---------------------|---------------------
	// --------^------------|-----^---------------|----------------------
	// --------^------------|---------------------|-----^----------------
    //            NANO - nsec                       nsec2

	int	dtn, dts = ts2->tv_sec - ts->tv_sec;
	if(dts == 0)    // same sec
		dtn = (ts2->tv_nsec - ts->tv_nsec) / 1000;
	else           // jump sec
		dtn = (ts2->tv_nsec + (CALC_NANO - ts->tv_nsec)) / 1000, dts--;

	if(dtn > CALC_MICRO)	// over a sec
		dtn -= CALC_MICRO, dts++;

	*pdts = dts;
	*pdtu = dtn;

	#undef CALC_NANO 	// Make sure define stays local
	#undef CALC_MICRO
}


int     main (int argc, char **argv)

{
   	int cc, digit_optind = 0, loop, loop2;

    //int *dd = 0;
    //*dd = 1;

    memset(&config, '\0', sizeof(config));

    // Parse command line
   	while (1) {
       int this_option_optind = optind ? optind : 1;
       int option_index = 0;
       static struct option long_options[] = {
           {"help", 0, 0, 0},
           {"add", 1, 0, 0},
           {"append", 0, 0, 0},
           {"delete", 1, 0, 0},
           {"verbose", 0, 0, 0},
           {"create", 1, 0, 'c'},
           {"file", 1, 0, 0},
           {0, 0, 0, 0}
       	};

    	cc = getopt_long (argc, argv, "abcd:012fhio:lmnpqrstvyk",
                        long_options, &option_index);

               if (cc == -1)
                   break;

               switch (cc) {
               case 0:
                   printf ("long option %s", long_options[option_index].name);
                   if (optarg)
                       printf (" with arg %s", optarg);
                   printf ("\n");
                   break;

               case '0': case '1': case '2':
                   if (digit_optind != 0 && digit_optind != this_option_optind)
                     printf ("digits occur in two different argv-elements.\n");
                   digit_optind = this_option_optind;
                   printf ("digits option %c\n", cc);

                case 'a':
                   //printf ("option a\n");
                   config.noassembly = 1;
                   break;

                case 'k':
                   //printf ("option k\n");
                   config.nolink = 1;
                   break;

               case 'b':
                   //printf ("option b\n");
                   config.showallocbuff = 1;
                   break;

               case 'c':
                   //printf ("option c\n");
                   config.catsrc = 1;
                   break;

               case 'd':
                   //printf ("option d with value '%s'\n", optarg);
                   config.debuglevel = atoi(optarg);
                   if(config.debuglevel > 10)
                        config.debuglevel = 10;
                   break;

               case 'f':
                   //printf ("Debug FLEX option is on\n");
                   config.testflex = 1;
                   break;

               case 'h':
                   //printf ("option i\n");
                   //config.interlace_sym = 1;
                   help();
                   break;

                case 'i':
                   //printf ("option i\n");
                   config.interlace_sym = 1;
                   break;

               case 'm':
                   //printf ("option m\n");
					config.showcomm = 1;
                   	break;

                case 'l':
                    //printf ("option l\n");
					config.showcomm = 1;
                   	break;

               case 'n':
                   //printf ("option n\n");
					config.noprog = 1;
                   	break;

               case 'o':
                   //printf ("option o\n");
                   strncpy(outfile, optarg, sizeof(outfile));
                   if(config.verbose)
                       printf("outfile: '%s'\n", outfile);
                   break;

               case 'p':
                   //printf ("option p\n");
                   config.noprologue = 1;
                   break;

                case 'q':
                   //printf ("option c\n");
                   config.catpre = 1;
                   break;

               case 'r':
                   //printf ("option r\n");
                   config.nopre = 1;
                   break;

               case 's':
                   //printf ("option s\n");
                   //printf ("Showing symtab\n");
                   config.dumpsymtab = 1;
                   break;

               case 't':
                   //printf ("Do not compile\n");
                   config.nocompile = 1;
                   break;

               case 'v':
                   //printf ("option v\n");
                   config.verbose = 1;
                   break;

               case 'y':
                   //printf ("Debug YACC option is on\n");
                   config.testyacc = 1;
                   break;

               case '?':
                   break;

               default:
                   printf ("?? getopt returned character code 0%o ??\n", cc);
               }
            }

            if (optind < argc)
                {
				struct timespec ts;
				clock_gettime(CLOCK_REALTIME, &ts);

                //printf ("non-option ARGV-elements: ");
                while (optind < argc)
                    {
                    // Preprocess and compile
					num_lines = 1; empty_symtab();

					if(config.nopre == 0)
						preprocess(argv[optind]);
					else
						strcpy(ppfile2, argv[optind]);

					if(config.nocompile == 0)
	                	compile(argv[optind]);

                    optind++;
                    }

                //printf ("\n");
				//dump_symtab();

				struct timespec ts2;
				clock_gettime(CLOCK_REALTIME, &ts2);

				int dts, dtu; calc_usec_diff(&ts, &ts2, &dts, &dtu);
				if(config.verbose)
            	 	printf("Total %d sec %d usec\n", dts, dtu);
                }
             else
                {
                //help();
                printf("Parallel compiler. Use 'pcomp -h' for options and help.\n");
                exit(0);
                }

	//print_emalloc();
	//print_estrdup();
	//empty_symtab();
	//efreeall();

	if(config.showallocbuff)
		{
		print_emalloc();
		print_estrdup();
		}

	exit(config.errorcount);
}


