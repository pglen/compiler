
  /* =====[ PCOMP ]=========================================================

     Description: PCOMP parallel compiler. See README and SYNTAX.

     Revisions:

     REV    DATE            BY             DESCRIPTION
     ----   --------        ----------     ----------------------------
     0.00   Thu 03.Jul.2025 Peter Glen     Initial

     ======================================================================= */

  /* -------- System includes:  -------------------------------------------- */

#include <sys/stat.h>
#include <syslog.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <getopt.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#include "pcomp.h"
#include "symtab.h"
#include "emalloc.h"
#include "xmalloc.h"

char outfile[MAX_PATHLEN] = {0,};
char usetmp[MAX_PATHLEN] = {0,};

char    *version = "1.0.0";
char    *build = "Thu 03.Jul.2025";

// Flags for operation. Some referenced in other files.

Configx config;

int     help()

{
    printf("\n");
    printf("  ---------------------------------------------------------------\n");
    printf("          Parallel compiler by Peter Glen. 2007-2019-2025        \n");
    printf("  ---------------------------------------------------------------\n");
    printf("\n");
    printf(" Usage: pcomp [options] filename(s)\n");
    printf("\n");
    printf("    -d debug level               |   -c cat assembly to stdout\n");
    printf("    -t do not compile            |   -C extract comments\n");
    printf("    -r no pre processing         |   -n do not show progress\n");
    printf("    -V version                   |   -v verbose\n");
    printf("    -h help (this screen         |   -b show alloc buffers\n");
    printf("    -i interlace symtab in out   |   -m show comments in source\n");
    printf("    -o output file               |   -u use tmp dir\n");
    printf("    -p no prologue for asm       |   -q cat pre proc to stdout\n");
    printf("    -s show symtab               |   -a no assembly phase\n");
    printf("    -f show lex output           |   -y show yacc output \n");
    printf("    -F show preproc lex output   |   -Y show preproc yacc output \n");
    printf("\n");

    exit(1);
}

// Main Entry point

int     main (int argc, char **argv)

{
       int cc, digit_optind = 0, loop, loop2;

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

        cc = getopt_long (argc, argv, "abc012fhilmnpqrstVvykFYXoC:d:u:",
                        long_options, &option_index);
        if (cc == -1)
            break;
        switch (cc)
               {
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

               case 'F':
                   //printf ("Debug FLEX option is on\n");
                   config.testpreflex += 1;
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

               case 'n':
                   //printf ("option n\n");
                     config.noprog = 1;
                       break;

               case 'o':
                   strncpy(outfile, optarg, sizeof(outfile));
                   if(config.verbose > 2)
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
                   //printf ("Showing symtab\n");
                   config.dumpsymtab = 1;
                   break;

               case 't':
                   //printf ("Do not compile\n");
                   config.nocompile = 1;
                   break;

               case 'u':
                    strncpy(usetmp, optarg, sizeof(usetmp));
                    struct stat statbuf;
                    if(stat(usetmp, &statbuf) < 0)
                        {
                        printf("usetmp: '%s' must exist.\n", usetmp);
                        exit(1);
                        }
                    if (!(statbuf.st_mode & S_IFDIR))
                        {
                        printf("usetmp: '%s' must be a dir.\n", usetmp);
                        exit(1);
                        }
                    strcat(usetmp, "/");
                   if(config.verbose > 2)
                       printf("Usetmp: '%s'\n", usetmp);
                    break;

               case 'v':
                   //printf ("option v\n");
                   config.verbose += 1;
                   break;

                case 'V':
                   printf ("Version: %s built: %s\n", version, build);
                   break;

               case 'y':
                   //printf ("Debug YACC option is on\n");
                   config.testyacc += 1;
                   break;

               case 'Y':
                   //printf ("Debug YACC option is on\n");
                   config.testpreyacc += 1;
                   break;

               case '?':
                   break;

               default:
                   printf ("?? getopt returned character code 0%o ??\n", cc);
               }
            }
    if (optind < argc)
        {
        Ts ts;
        clock_gettime(CLOCK_REALTIME, &ts);

        //printf ("non-option ARGV-elements: ");
        while (optind < argc)
            {
            // Fill in defaults
            if(outfile[0] == '\0')
                {
                strcpy(outfile, argv[optind]);
                char *last4 = strrchr(outfile, '.');
                if (last4 != NULL)
                    {
                    *last4 = '\0';
                    }
                strcat(outfile, ".run");
                if(config.verbose > 2)
                    printf("outfile: '%s'\n", outfile);
                }

            // Preprocess and compile
            num_lines = 1; empty_symtab();
            if(config.nopre == 0)
                {
                preprocess(argv[optind]);
                }
             else
                {
                 //strcnpy(ppfile2, argv[optind], sizeof(ppfile2));
                strcpy(ppfile2, argv[optind]);
                }
            if(config.nocompile == 0)
               compile(argv[optind]);
            optind++;
            }
        //printf ("\n");
        if(config.dumpsymtab)
            dump_symtab();

        Ts ts2;
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
    //xmdump(1);
    //printf("\n");
    //print_emalloc();
    //print_estrdup();
    //empty_symtab();
    //efreeall();

    if(config.showallocbuff)
        {
        print_emalloc();
        print_estrdup();
        }
    exit(config.errorcount); // + 127);
}

// EOF
