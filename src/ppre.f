%{

/* This lexer and parser assumes that int is same size as pointer */

#include <stdio.h>     /* for printf */
#include <stdlib.h>    /* for exit */

#include "../symtab.h"
#include  "../pcomp.h"

static    char    tmp_str[2 * MAX_PATHLEN];
static    char    tmp_str2[2 * MAX_PATHLEN];

char    ppfile2[MAX_PATHLEN];
char    ppfile[MAX_PATHLEN];

FILE *ppfp3, *ppfp2;

//#define YY_INPUT(buf, result, max_size) \
//               { \
//               int c = getc(ppfp3); \
//               result = (c == EOF) ? YY_NULL : (buf[0] = c, 1); \
//               }

// Tag a new line at the end of sequence

int  inputx(char *buf, int max_size)

{
    static int end = 0;
    int ret = 1, cc = getc(ppfp3);
    if(end) {
        end = 0; ret = 0;
        }
    else if(cc == EOF)  {
        buf[0] = '\n';  end = 1;
        }
    else  {
        buf[0] = cc;
        }
    return ret;
}

#define YY_INPUT(buf, result, max_size) \
                result = inputx(buf, max_size);

void    preerror(const char *str)

{
    static int count = 0;
    printf("%s  Line: %d  Near '%s'\n", str, num_lines, yytext); count++;
    if(count > 5) exit(0);
}

#define DEBUGLEX

int prelex();
#include "ppre.yacc.c"

%}

%x STR2
%x COM2

%option noyywrap

FN   [\~_a-zA-Z]
FNN  [\~_a-zA-Z0-9]

%%

\\\n                        {
                            if(config.testpreflex)
                                printf("[BS EOL] '%s", yytext);
                            }

\/\/.*\n                       { /* comment */
                                num_lines++;

                                if(config.testpreflex)
                                    printf("[slash_comment] '%s", yytext);

                                if(config.showcomm)
                                    printf("//comment: '%s", yytext);

                                yylval.sym = make_symstr("", strdup(yytext), STR);
                                return COMMENT;
                                }

#.*\n                          { /* comment */
                                num_lines++;

                                if(config.testpreflex)
                                    printf("[hash_comment] '%s", yytext);

                                if(config.showcomm)
                                    printf("#comment: '%s", yytext);

                                yylval.sym = make_symstr("name", strdup(yytext), COMMENT);
                                return COMMENT;
                                }

0x[0-9a-fA-F]+                  {
                                if(config.testpreflex)
                                    printf("[NUM] '%s' ", yytext);

                                yylval.sym = make_symstr("name", strdup(yytext), NUM);
                                return(NUM);
                                }

0y[0-7]+                          {
                                if(config.testpreflex)
                                    printf("[NUM] '%s' ", yytext);

                                yylval.sym = make_symstr("name", strdup(yytext), NUM);

                                return(NUM);
                                }

0z[0-1]+                        {
                                if(config.testpreflex)
                                    printf("[NUM] '%s' ", yytext);

                                yylval.sym = make_symstr("name", strdup(yytext), NUM);

                                return(NUM);
                                }

[0-9]+                          {
                                if(config.testpreflex)
                                    printf("[NUM] '%s' ", (char*)yytext);

                                yylval.sym = make_symstr("name", strdup(yytext), NUM);

                                return(NUM);
                                }

\>\>                            {
                                if(config.testpreflex)
                                    printf(" [RSHIFT] '%s' ", yytext);

                                yylval.sym = make_symstr("name", strdup(yytext), RSHIFT);

                                return(RSHIFT);
                                }

\<\<                            {
                                if(config.testpreflex)
                                    printf(" [LSHIFT] '%s' ", yytext);

                                yylval.sym = make_symstr("name", strdup(yytext), LSHIFT);
                                return(LSHIFT);
                                }

\+                              {
                                yylval.sym = make_symstr("", strdup(yytext), PLUS);
                                return(PLUS);
                                }
\-                              {
                                if(config.testpreflex)
                                    printf(" [MINUS] '%s' ", yytext);

                                yylval.sym = make_symstr("name", strdup(yytext), MINUS);
                                return(MINUS);
                                }
\*                              {
                                if(config.testpreflex)
                                    printf(" [MULT] '%s' ", yytext);

                                yylval.sym = make_symstr("", strdup(yytext), MULT);
                                return(MULT);
                                }
\/                              {
                                if(config.testpreflex)
                                    printf(" [DIV] '%s' ", yytext);

                                yylval.sym = make_symstr("", strdup(yytext), DIV);
                                return(DIV);
                                }
\%                              {
                                if(config.testpreflex)
                                    printf(" [MOD] '%s' ", yytext);

                                yylval.sym = make_symstr("", strdup(yytext), MOD);
                                return(MOD);
                                }
\|                              {
                                if(config.testpreflex)
                                    printf(" [OR] '%s' ", yytext);

                                yylval.sym = make_symstr("", strdup(yytext), OR);
                                return(OR);
                                }
\&                              {
                                if(config.testpreflex)
                                    printf(" [AND] '%s' ", yytext);

                                yylval.sym = make_symstr("", strdup(yytext), AND);
                                return(AND);
                                }
\!                              {
                                yylval.sym = make_symstr("", strdup(yytext), NOT);
                                return(NOT);
                                }
\^                              {
                                if(config.testpreflex)
                                    printf(" [XOR] '%s' ", yytext);

                                yylval.sym = make_symstr("", strdup(yytext), XOR);
                                return(XOR);
                                }
\(                              {
                                if(config.testpreflex)
                                    printf(" [PAREN1] '%s' ", yytext);

                                yylval.sym = make_symstr("", strdup(yytext), PAREN1);
                                return(PAREN1);
                                }
\)                              {
                                if(config.testpreflex)
                                    printf(" [PAREN2] '%s' ", yytext);

                                yylval.sym = make_symstr("", strdup(yytext), PAREN2);
                                return(PAREN2);
                                }
%error                          {
                                if(config.testpreflex)
                                    printf(" [error] '%s' ", yytext);

                                yylval.sym = make_symstr("", strdup(yytext), ERR);
                                return ERR;
                                }

%macro                          {
                                if(config.testpreflex)
                                    printf(" [mmacro] '%s' ", yytext);

                                yylval.sym = make_symstr("", strdup(yytext), MAC);
                                return MAC;
                                }

%message|%msg                   {
                                if(config.testpreflex)
                                    printf(" [message] '%s' ", yytext);

                                yylval.sym = make_symstr("", strdup(yytext), MSG);
                                return MSG;
                                }
%define                           {
                                if(config.testpreflex)
                                    printf(" [define] '%s' ", yytext);

                                yylval.sym = make_symstr("", strdup(yytext), DEF);
                                return DEF;
                                }

%undef                           {
                                if(config.testpreflex)
                                    printf(" [undef] '%s' ", yytext);

                                yylval.sym = make_symstr("", strdup(yytext), UNDEF);
                                return UNDEF;
                                }

%ifdef                           {
                                if(config.testpreflex)
                                    printf(" [ifdef] '%s' ", yytext);

                                yylval.sym = make_symstr("", strdup(yytext), IFDEF);
                                return IFDEF;
                                }

%elifdef                           {
                                if(config.testpreflex)
                                    printf(" [elifdef] '%s' ", yytext);

                                yylval.sym = make_symstr("", strdup(yytext), ELIFDEF);
                                return ELIFDEF;
                                }

%else                           {
                                if(config.testpreflex)
                                    printf(" [else] '%s' ", yytext);

                                yylval.sym = make_symstr("", strdup(yytext), ELSE);
                                return ELSE;
                                }

%endif                           {
                                if(config.testpreflex)
                                    printf(" [ifdef] '%s' ", yytext);

                                yylval.sym = make_symstr("", strdup(yytext), ENDIF);
                                return ENDIF;
                                }

{FN}{FNN}*                        {
                                if(config.testpreflex)
                                    printf(" [ID] '%s'\n", yytext);

                                yylval.sym = make_symstr("", strdup(yytext), ID);
                                return ID;
                                }

[ \t]                            {
                                if(config.testpreflex)
                                    printf(" [SP] '%s' ", yytext);
                                yylval.sym = make_symstr("", strdup(yytext), SP);
                                return SP;
                                }

\r                                {
                                // Ignore
                                if(config.testpreflex)
                                    printf(" [rnl] '%d'\n", yytext[0]);
                                num_lines++;
                                yylval.sym = make_symstr("", strdup(yytext), NL);
                                return NL;
                                }

\n                                {
                                if(config.testpreflex)
                                    printf(" [NL] '%d'\n", yytext[0]);

                                num_lines++;
                                yylval.sym = make_symstr("", strdup(yytext), NL);
                                return NL;
                                }

\"                              {              /* begin quote */
                                BEGIN(STR2);

                                //if(config.testpreflex)
                                //    printf(" str<<<");

                                prog = 0; backslash  = 0;
                                //tmp_str2[prog++] = yytext[0];
                                }

<STR2>\\                        {
                                if(config.testpreflex)
                                    printf("STR2 \\");

                                tmp_str2[prog++] = yytext[0];
                                backslash++;
                                }

<STR2>\\$                       {
                                if(config.testpreflex)
                                    printf("[STR2 BS EOL] '%s", yytext);
                                // Skipping ...
                                }

<STR2>\"                        {              /* end quote */
                                if( (backslash % 2) == 0) /* odd backslash */
                                     {
                                     BEGIN(INITIAL);

                                     //tmp_str2[prog++] = yytext[0];
                                     tmp_str2[prog] = '\0';
                                     yylval.sym = make_symstr("", strdup(tmp_str2), STR);

                                     if(config.testpreflex)
                                        printf("[STR] '%s'\n", yylval.sym->var);
                                     return(STR);
                                     }
                                  else
                                      {  /* add quote */
                                      //  tmp_str2[prog++] = yytext[0];
                                      }
                                }

<STR2>.                         {   // default string charater
                                backslash  = 0;

                                if(config.testpreflex > 1)
                                    printf("'%s'", yytext);

                                tmp_str2[prog++] = yytext[0];
                                }

.                                {  // default character

                                if(config.testpreflex)
                                    printf(" [char] '%s' ", yytext);

                                yylval.sym = make_symstr("", strdup(yytext), CH);
                                return CH;
                                }
%%

//<<EOF>>                 {
//                        //printf("got EOF");
//                        yyterminate();
//                        //return NL;
//                        }

//void    yywrap()
//{
//    return 1;
//}

/* ========================= End of LEX ================================ */

///////////////////////////////////////////////////////////////////////////

int     preprocess(char *ptr)

{
    int ret_val = 1;
    struct stat buf;

    // re - initialize preprocessor
    num_lines = 1;

    if(stat(ptr, &buf) < 0)
        {
        printf("Cannot stat file '%s'.\n", ptr);
        //if(config.debuglevel > 0)
        //    syslog(LOG_DEBUG, "Cannot stat file %s\n", ptr);
        return 0;
        }
    if(S_ISDIR(buf.st_mode))
        {
        //printf("Cannot operate on directory '%s'.\n", ptr);
        //if(config.debuglevel > 0)
        //    syslog(LOG_DEBUG, "cannot operate on dir %s\n", ptr);
        return 0;
        }

    ppfp3 = fopen(ptr, "r");
    if(!ppfp3)
        {
        printf("Cannot open file '%s'.\n", ptr);
        //if(config.debuglevel > 0)
        //    syslog(LOG_DEBUG, "Cannot open file %s\n", ptr);
        return 0;
        }
    char outdir[MAX_VARLEN];
    strcpy(outdir, ptr);
    char *last2 = strrchr(outdir, '/');
    if (last2 != NULL)
        {
        *last2 = '\0';
        }
    else
        {
        outdir[0] = '.'; outdir[1] = '\0';
        }
    strcat(outdir, "/tmp/");

    //printf("outdir: '%s'\n", outdir);

    if(stat(outdir, &buf) < 0)
        {
        if(mkdir(outdir, 0777) < 0)
            {
            printf("Cannot create tmp dir: '%s'\n", outdir);
            exit(1);
            //return 0;
            }
        }
    strcpy(ppfile, ptr);
    char *last = strrchr(ppfile, '/');
    if (last != NULL)
        {
        strcpy(ppfile, last + 1);
        }
    strcpy(ppfile2, outdir);
    strcat(ppfile2, ppfile);
    char *last3 = strrchr(ppfile2, '.');
    if (last3 != NULL)
        {
        *last3 = '\0';
        strcat(ppfile2, ".pcp");
        //printf("asm2: '%s'\n", ppfile2);
        }
    ppfp2 = fopen(ppfile2, "w");
    if(!ppfp2)
        {
        printf("Cannot create file '%s'.\n", ppfile);
        //syslog(LOG_DEBUG, "pcomp: Cannot create preprocessed file.\n");
        return 0;
        }

    int    olderrcnt = config.errorcount;

    if(config.verbose > 0)
        printf ("Pre processing: '%s' ", ptr);

    struct timespec ts;
    clock_gettime(CLOCK_REALTIME, &ts);

    preparse();

    struct timespec ts2;
    //sleep(2); // test time measurement
    clock_gettime(CLOCK_REALTIME, &ts2);
    fclose(ppfp3);
    int dts, dtu; calc_usec_diff(&ts, &ts2, &dts, &dtu);
    int ret = getretcode();
    if(config.verbose)
        {
        if(ret == 0 && (olderrcnt == config.errorcount))
            printf ("OK %d sec %d usec\n", dts, dtu);
        else
            printf ("Compiled: '%s' ERR %d sec %d usec\n", ptr, dts, dtu);
        }
    fclose(ppfp2);

    if(config.catpre)
        {
        printf("Displaying pre processed file:\n\n");
        sprintf(tmp_str, "cat %s\n", ppfile2);
        int ret = system(tmp_str);
        printf("\n");
        }
    return ret_val;
}

// EOF
