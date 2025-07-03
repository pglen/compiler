%{
/* This lexer and parser assumes theat int is same size as pointer */


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

//define DEBUGLEX

#include "config.tab.c"
%}


%x STR2
%option noyywrap

FN   [\/\!\~_a-zA-Z]
FNN  [\/\!\~_a-zA-Z0-9]


%%
#.*\n                           /* comment */ {  num_lines++;}
^\n                             /* empty line */ num_lines++;;
            /* commands: */
       /* --------------------------------------------------------- */
\<class\>                           {
#ifdef DEBUGLEX
                                printf("<CLASS> ");
#endif
                                yylval = (int)strdup(yytext); return(CLASS);
                                }
\<ssalc\>                           {
#ifdef DEBUGLEX
                                printf("<SSALC> ");
#endif
                                yylval = (int)strdup(yytext); return(SSALC);
                                }
       /* --------------------------------------------------------- */
\<dir\>                            {
#ifdef DEBUGLEX
                                printf("<DIR> ");
#endif
                                yylval = (int)strdup(yytext); return(DIR);
                                }
\<rid\>                           {
#ifdef DEBUGLEX
                                printf("<RID> ");
#endif
                                yylval = (int)strdup(yytext); return(RID);
                                }

function                        {
#ifdef DEBUGLEX
                                printf("lex: Function ");
#endif

                                yylval = (int)strdup(yytext); return(FUNC);
                                }

begin                          {
#ifdef DEBUGLEX
                                printf("lex: begin ");
#endif

                                yylval = (int)strdup(yytext); return(BEG);
                                }

end                             {
#ifdef DEBUGLEX
                                printf("lex: end ");
#endif

                                yylval = (int)strdup(yytext); return(END);
                                }


       /* --------------------------------------------------------- */

\<deny\>                            {
#ifdef DEBUGLEX
                                printf("<DENY> ");
#endif
                                yylval = (int)strdup(yytext); return(DENY);
                                }
\<yned\>                           {
#ifdef DEBUGLEX
                                printf("<YNED> ");
#endif
                                yylval = (int)strdup(yytext); return(YNED);
                                }
       /* --------------------------------------------------------- */
debug                          {
#ifdef DEBUGLEX
                                printf("<DBG> ");
#endif
                                yylval = (int)strdup(yytext); return(DBG);
                                }
log                             {
#ifdef DEBUGLEX
                                printf("<LOG> ");
#endif
                                yylval = (int)strdup(yytext); return(LOG);
                                }
0y[0-1]+                        {
#ifdef DEBUGLEX
                                printf("!%s! ", yytext);
#endif
                                return(NUM);
                                }
0x[0-9a-zA-z]+                  {            /* hexadecimal */
#ifdef DEBUGLEX
                                printf("|%s| ", yytext);
#endif
                                yylval = (int)strdup(yytext); return(ID);
                                }
[0-9]+                          {
#ifdef DEBUGLEX
                                printf("'%s' ", yytext);
#endif
                                yylval = (int)strdup(yytext); return(NUM);
                                }
{FN}{FNN}*                      {             /* Identity */
#ifdef DEBUGLEX
                                printf("<%s> ", yytext);
#endif
                                yylval = (int)strdup(yytext); return(ID);
                                }

[`@#$%^&\*()-_=\[\]:;'?><,.\\|]   {  /* Separator */
#ifdef DEBUGLEX
                                printf("{%s} ", yytext);
#endif
                                }

'-'                             {
#ifdef DEBUGLEX
                                printf("plus{%s} ", yytext);
#endif
                                yylval = (int)strdup(yytext); return(PLUS);

                                }

\{                              {
#ifdef DEBUGLEX
                                printf("lcur{%s} ", yytext);
#endif
                                yylval = (int)strdup(yytext); return(LCUR);
                                }


\}                              {
#ifdef DEBUGLEX
                                printf("rcur{%s} ", yytext);
#endif
                                yylval = (int)strdup(yytext); return(RCUR);
                                }


\"                              {              /* begin quote */
                                BEGIN(STR2);
#ifdef DEBUGLEX
                                printf("str<<< ");
#endif
                                backslash  = 0;
                                }
[ \t\r\n]+                        {          /* white space */
#ifdef DEBUGLEX
                                printf("[ws] ");
#endif
                                yylval = (int)strdup(yytext); return(SP);
                                }
.                               {
#ifdef DEBUGLEX
                                printf("~%s~ ", yytext);
#endif
                                }
<STR2>\\\"                      printf("\\\"");
<STR2>\\                        printf("\\"); backslash++;
<STR2>\"                        {
                                if( !(backslash %  2)) /* odd backslash */
                                     {  BEGIN(INITIAL);
                                      printf(">>>str "); return(STR);
                                     }
                                }
<STR2>.                backslash  = 0; printf("%s", yytext);

%%

/* ==================================================================== */

#ifdef TEST

int            main(int argc, char *argv[1])

{
      int loop, loop2;

        if(!argv[1])
            {
            printf("Usage ccc filename\n");
            exit(0);
            }

      //printf("Configuration:\n");

      if(!readconfig(argv[1]))
        exit(0);


    if(!xdlist)
        {
        //printf("File does not have anything to parse\n");
        exit(0);
        }

      printf("Configuration:\n");


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
}
#endif

int readconfig(char *ptr)

{
      infp = fopen(ptr, "r");
      if(!infp)
        {
#ifdef TEST
        printf("Cannot open file.\n");
#endif
        //syslog(LOG_DEBUG, "Cannot open config file.\n");
        return 0;
        }
     confparse();
     fclose(infp);

    return 1;
}


