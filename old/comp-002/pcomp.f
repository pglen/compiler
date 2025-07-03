%{

/* This lexer and parser assumes theat int is same size as pointer */

int   testflex = 0;
int   testyacc = 0;
int	  showcomm = 0;


FILE *infp;

int num_lines = 1, num_chars = 0, backslash = 0;

#define YY_INPUT(buf,result,max_size) \
               { \
               int c = getc(infp); \
               result = (c == EOF) ? YY_NULL : (buf[0] = c, 1); \
               }
void conferror(char *str)
{
 static int count = 0;
       printf("%s  Line: %d  Near '%s'\n", str, num_lines, yytext); count++;
       if(count > 5) exit(0);
}

#define DEBUGLEX

#include "pcomp.tab.c"

%}


%x STR2
%option noyywrap

FN   [\!\~_a-zA-Z]
FNN  [\!\~_a-zA-Z0-9]

%%

\/\/\/\/.*\n                       { /* comment */
								num_lines++;
	#ifdef DEBUGLEX
                                if(testflex)
                                    printf("[double slash comment] '%s", yytext);
	#endif
                                yylval.strval = strdup(yytext);
								return COMMENT2;
								}

\/\/.*\n                       { /* comment */
								num_lines++;
	#ifdef DEBUGLEX
                                if(testflex)
                                    printf("[slash comment] '%s", yytext);
	#endif
                                yylval.strval = strdup(yytext);
								return COMMENT;
								}

##.*\n                           {  /* double comment */
								num_lines++;
	#ifdef DEBUGLEX
                                if(testflex)
                                    printf("[double comment] '%s", yytext);
	#endif
                                yylval.strval = strdup(yytext);
								return COMMENT2;
								}

#.*\n                           {  /* comment */
								num_lines++;
	#ifdef DEBUGLEX
                                if(testflex)
                                    printf("[comment] '%s", yytext);
	#endif
                                yylval.strval = strdup(yytext);
								return COMMENT;
								}

^\r\n                             /* empty line */ {
								if(testflex)
                                    printf("[empty line]\r\n");
								num_lines++;
								}

^\r                             /* empty line */ {
								if(testflex)
                                    printf("[empty line \\r]\r\n");
								num_lines++;
								}

^\n                             /* empty line */ {
								if(testflex)
                                    printf("[empty line \\n]\r\n");
								num_lines++;
								}


	/* commands: ------------------------------------------------------- */

  /*
\<class\>                           {
	#ifdef DEBUGLEX
                                if(testflex)
                                    printf("<CLASS> ");
	#endif
                                yylval.strval = strdup(yytext);
                                return(CLASS);
                                }
\<ssalc\>                           {
	#ifdef DEBUGLEX
                                if(testflex)
                                    printf("<SSALC> ");
	#endif
                                yylval.strval = strdup(yytext); return(SSALC);
                                }
    /* ----------------------------------------------------------------- */
\<dir\>                            {
	#ifdef DEBUGLEX
                                if(testflex)
	                                printf("<DIR> ");
	#endif
                                yylval.strval = strdup(yytext); return(DIR);
                                }
\<rid\>                         {
	#ifdef DEBUGLEX
                                if(testflex)
                                printf("<RID> ");
	#endif
                                yylval.strval = strdup(yytext); return(RID);
                                }

function                        {
	#ifdef DEBUGLEX
                                if(testflex)
                                printf("[Function] ");
	#endif
                                yylval.strval = strdup(yytext); return(FUNC);
                                }

begin                          {
	#ifdef DEBUGLEX
                                if(testflex)
                                printf("lex: begin ");
	#endif

                                yylval.strval = strdup(yytext); return(BEG);
                                }

end                             {
	#ifdef DEBUGLEX
                                if(testflex)
                                printf("lex: end ");
	#endif

                                yylval.strval = strdup(yytext); return(END);
                                }

    /* ----------------------------------------------------------------- */

debug                          {
	#ifdef DEBUGLEX
                                if(testflex)
                                printf("<DBG> ");
	#endif
                                yylval.strval = strdup(yytext); return(DBG);
                                }

return                         {
	#ifdef DEBUGLEX
                                if(testflex)
                                printf("[RET] ");
	#endif
                                yylval.strval = strdup(yytext); return(RET);
                                }

\|\|                             {
	#ifdef DEBUGLEX
                                if(testflex)
                                printf("<OR> ");
	#endif
                                yylval.strval = strdup(yytext); return(OR);
                                }

\&\&                             {
	#ifdef DEBUGLEX
                                if(testflex)
                                printf("<AND> ");
	#endif
                                yylval.strval = strdup(yytext); return(AND);
                                }

\=\=                             {
	#ifdef DEBUGLEX
                                if(testflex)
                                printf("<EQEQ> ");
	#endif
                                yylval.strval = strdup(yytext); return(EQEQ);
                                }

\^\^                             {
	#ifdef DEBUGLEX
                                if(testflex)
                                printf("<XOR> ");
	#endif
                                yylval.strval = strdup(yytext); return(XOR);
                                }

if                             {
	#ifdef DEBUGLEX
                                if(testflex)
                                printf("<IF> ");
	#endif
                                yylval.strval = strdup(yytext); return(IF);
                                }

else                             {
	#ifdef DEBUGLEX
                                if(testflex)
                                printf("<ELSE> ");
	#endif
                                yylval.strval = strdup(yytext); return(ELSE);
                                }

log                             {
	#ifdef DEBUGLEX
                                if(testflex)
                                printf("<LOG> ");
	#endif
                                yylval.strval = strdup(yytext); return(LOG);
                                }
0y[0-1]+                        {
	#ifdef DEBUGLEX
                                if(testflex)
                                printf("[NUM] '%s' ", yytext);
	#endif
                                return(NUM);
                                }
0x[0-9a-zA-z]+                  {            /* hexadecimal */
	#ifdef DEBUGLEX
                                if(testflex)
                                	printf("[ID] '%s' ", (char*)yytext);
	#endif
                                yylval.strval = strdup(yytext); return(ID);
                                }
[0-9]+                          {
	#ifdef DEBUGLEX
                                if(testflex)
 	                               printf("[NUM] '%s' ", (char*)yytext);
	#endif
                                yylval.strval = strdup(yytext); return(NUM);
                                }
{FN}{FNN}*                      {             /* Identity */
	#ifdef DEBUGLEX
                                if(testflex)
                                	printf("[ID] '%s' ", (char*)yytext);
	#endif
                                yylval.strval = strdup(yytext); return(ID);
                                }

\"                              {              /* begin quote */
                                BEGIN(STR2);
	#ifdef DEBUGLEX
                                if(testflex)
                                    printf(" str<<<");
	#endif
                                backslash  = 0;
                                }
[ \t\r\n]+                        {          /* white space */
	#ifdef DEBUGLEX
                                if(testflex)
                                	printf("[SP] '%d' len=%d ",
													yytext[0], strlen(yytext));
	#endif
                                yylval.strval = strdup(yytext);

								if(yytext[0] == '\r')
									num_lines++;

								//return(SP);
                                }

.                               {
                                if(testflex)
                                    printf("[CHAR] '%c' ", yytext[0]);
                                return(yytext[0]);
                                }

<STR2>\\\"                      printf("\\\"");
<STR2>\\                        printf("\\"); backslash++;

<STR2>\"                        {
                                if( !(backslash %  2)) /* odd backslash */
                                     {
                                     BEGIN(INITIAL);
                                     if(testflex)
                                        printf(">>>str ");
                                      return(STR);
                                     }
                                }
<STR2>.                         {
                                backslash  = 0;
                                if(testflex)
                                    printf("%s", yytext);
                                }


%%

/* ==================================================================== */


#include <stdio.h>     /* for printf */
#include <stdlib.h>    /* for exit */
#include <getopt.h>


#include "codegen.h"

int     main (int argc, char **argv)

{
   int cc, digit_optind = 0;

      int loop, loop2;

    // Parse command line

   while (1) {
       int this_option_optind = optind ? optind : 1;
       int option_index = 0;
       static struct option long_options[] = {
           {"add", 1, 0, 0},
           {"append", 0, 0, 0},
           {"delete", 1, 0, 0},
           {"verbose", 0, 0, 0},
           {"create", 1, 0, 'c'},
           {"file", 1, 0, 0},
           {0, 0, 0, 0}
       };

        cc = getopt_long (argc, argv, "abc:d:012fym",
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

               case '0':
               case '1':
               case '2':
                   if (digit_optind != 0 && digit_optind != this_option_optind)
                     printf ("digits occur in two different argv-elements.\n");
                   digit_optind = this_option_optind;
                   printf ("digits option %c\n", cc);


                case 'a':
                   printf ("option a\n");
                   break;

               case 'm':
                   printf ("option m\n");
					showcomm = 1;
                   break;

               case 'b':
                   printf ("option b\n");
                   break;

               case 'f':
                   printf ("Debug FLEX option is on\n");
                   testflex = 1;
                   break;

               case 'y':
                   printf ("Debug YACC option is on\n");
                   testyacc = 1;
                   break;

               case 'c':
                   printf ("option c with value '%s'\n", optarg);
                   break;

               case 'd':
                   printf ("option d with value '%s'\n", optarg);
                   break;

               case '?':
                   break;

               default:
                   printf ("?? getopt returned character code 0%o ??\n", cc);
               }
            }

            if (optind < argc)
                {
                //printf ("non-option ARGV-elements: ");

                while (optind < argc)
                    {
	                 int res = compile(argv[optind]);
					if(res)
						printparse();

                    optind++;
                    }
                //printf ("\n");
                }
             else
                {
                printf("Usage: pcomp [options] filename(s)\n");
                printf("       -y show yacc output\n");
                printf("       -l show lex output\n");

        		exit(0);
                }

      //printf("Configuration:\n");

}
//endif

int compile(char *ptr)

{
      infp = fopen(ptr, "r");
      if(!infp)
        {
        printf("Cannot open file '%s'.\n", ptr);
        syslog(LOG_DEBUG, "Cannot open file.\n");
        return 0;
        }

	 printf ("Compiling: '%s'\n", ptr);
     confparse();
     fclose(infp);

	if(!showcomm)
		{
		dump_symtab();
		//printf("\n");
		//gen_code();
		}

    return 1;
}


//////////////////////////////////////////////////////////////////////////

int		printparse()

{
	int loop, loop2;

#if 0
    if(!xdlist)
        {
        //printf("Empty file.\n");
        exit(0);
        }

	printf("Parse tree:\n");

      for(loop = 0; loop < (int)xdlist[1]; loop++)
          {
          char **list = (char **)xdlist[loop + 2];

          printf("ptr %p ", xdlist[loop+2]);

          printf("User: '%s'\n", list[2]);

          for(loop2 = 1; loop2 < (int)list[1]; loop2++)
                {
                printf("'%s' ", list[loop2 + 2]);
                }
          printf("\n");
          }
      printf("\n");
#endif

}

