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

//char    *linearr[] = NULL;
char    currline[1024] = {0};
int     currprog = 0;

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
    else {
        buf[0] = cc;
        }

    currline[currprog] = cc;
    currprog++;
    currline[currprog] = '\0';

    // Restart
    if (cc == '\n')
        currprog = 0;

    return ret;
}

#define YY_INPUT(buf, result, max_size) \
                result = inputx(buf, max_size);

void    preerror(const char *str)

{
    static int count = 0;

    count++;

    printf("%s  Line: %d  Near: '%s'\n", str, num_lines, yytext);
    //printf("Line offset: %ld\n",  ftell(ppfp3));
    //printf("Line so far: '%s'\n", currline);

    if(count > 5)
        exit(0);
}

#define DEBUGLEX

int prelex();
#include "ppre.yacc.c"

%}

%x STRSTATE

%option noyywrap

FN   [\~_a-zA-Z]
FNN  [\~_a-zA-Z0-9]

%%

\\\n                        {
                            if(config.testpreflex)
                                printf("[BS EOL] '%s", yytext);
                            // Ignore
                            }

\/\/.*\n                       { /* comment */
                                num_lines++;

                                if(config.testpreflex)
                                    printf("[slash_comment] '%s", yytext);

                                if(config.showcomm)
                                    printf("//comment: '%s", yytext);

                                yylval.sym = make_symstr("", strdup(yytext), STR2);
                                return COMMENT2;
                                }

#.*\n                          { /* comment */
                                num_lines++;

                                if(config.testpreflex)
                                    printf("[hash_comment] '%s", yytext);

                                if(config.showcomm)
                                    printf("#comment: '%s", yytext);

                                yylval.sym = make_symstr("name", strdup(yytext), COMMENT2);
                                return COMMENT2;
                                }

0x[0-9a-fA-F]+                  {
                                if(config.testpreflex)
                                    printf("[NUM] '%s' ", yytext);

                                yylval.sym = make_symstr("name", strdup(yytext), NUM2);
                                return(NUM2);
                                }

0y[0-7]+                          {
                                if(config.testpreflex)
                                    printf("[NUM] '%s' ", yytext);

                                yylval.sym = make_symstr("name", strdup(yytext), NUM2);

                                return(NUM2);
                                }

0z[0-1]+                        {
                                if(config.testpreflex)
                                    printf("[NUM] '%s' ", yytext);

                                yylval.sym = make_symstr("name", strdup(yytext), NUM2);

                                return(NUM2);
                                }

\+                              {
                                if(config.testpreflex)
                                    printf(" [PLUS] '%s' ", yytext);
                                 yylval.sym = make_symstr("", strdup(yytext), PLUS2);
                                return(PLUS2);
                                }
\-                              {
                                if(config.testpreflex)
                                    printf(" [MINUS] '%s' ", yytext);

                                yylval.sym = make_symstr("name", strdup(yytext), MINUS2);
                                return(MINUS2);
                                }
\*                              {
                                if(config.testpreflex)
                                    printf(" [MULT] '%s' ", yytext);

                                yylval.sym = make_symstr("", strdup(yytext), MULT2);
                                return(MULT2);
                                }
\/                              {
                                if(config.testpreflex)
                                    printf(" [DIV] '%s' ", yytext);

                                yylval.sym = make_symstr("", strdup(yytext), DIV2);
                                return(DIV2);
                                }
\%                              {
                                if(config.testpreflex)
                                    printf(" [MOD] '%s' ", yytext);

                                yylval.sym = make_symstr("", strdup(yytext), MOD2);
                                return(MOD2);
                                }
\|                              {
                                if(config.testpreflex)
                                    printf(" [OR] '%s' ", yytext);

                                yylval.sym = make_symstr("", strdup(yytext), OR2);
                                return(OR2);
                                }
\&                              {
                                if(config.testpreflex)
                                    printf(" [AND] '%s' ", yytext);

                                yylval.sym = make_symstr("", strdup(yytext), AND2);
                                return(AND2);
                                }
\!                              {
                                yylval.sym = make_symstr("", strdup(yytext), NOT2);
                                return(NOT2);
                                }
\^                              {
                                if(config.testpreflex)
                                    printf(" [XOR] '%s' ", yytext);

                                yylval.sym = make_symstr("", strdup(yytext), XOR2);
                                return(XOR2);
                                }
\(                              {
                                if(config.testpreflex)
                                    printf(" [PAREN1] '%s' ", yytext);

                                yylval.sym = make_symstr("", strdup(yytext), PAREN12);
                                return(PAREN12);
                                }
\)                              {
                                if(config.testpreflex)
                                    printf(" [PAREN2] '%s' ", yytext);

                                yylval.sym = make_symstr("", strdup(yytext), PAREN22);
                                return(PAREN22);
                                }

[0-9]+                          {
                                if(config.testpreflex)
                                    printf("[NUM] '%s' ", (char*)yytext);

                                yylval.sym = make_symstr("name", strdup(yytext), NUM2);

                                return(NUM2);
                                }

\>\>                            {
                                if(config.testpreflex)
                                    printf(" [RSHIFT] '%s' ", yytext);

                                yylval.sym = make_symstr("name", strdup(yytext), RSHIFT2);

                                return(RSHIFT2);
                                }

\<\<                            {
                                if(config.testpreflex)
                                    printf(" [LSHIFT] '%s' ", yytext);

                                yylval.sym = make_symstr("name", strdup(yytext), LSHIFT2);
                                return(LSHIFT2);
                                }
;                             {
                                if(config.testpreflex)
                                    printf(" [SEMI] '%s' ", yytext);

                                yylval.sym = make_symstr("name", strdup(yytext), SEMI2);
                                return(SEMI2);
                                }
%error                          {
                                if(config.testpreflex)
                                    printf(" [error] '%s' ", yytext);

                                yylval.sym = make_symstr("", strdup(yytext), ERR2);
                                return ERR2;
                                }

%macro                          {
                                if(config.testpreflex)
                                    printf(" [mmacro] '%s' ", yytext);

                                yylval.sym = make_symstr("", strdup(yytext), MAC2);
                                return MAC2;
                                }

%message|%msg                   {
                                if(config.testpreflex)
                                    printf(" [message] '%s' ", yytext);

                                yylval.sym = make_symstr("", strdup(yytext), MSG2);
                                return MSG2;
                                }
%define                         {
                                if(config.testpreflex)
                                    printf(" [define] '%s' ", yytext);

                                yylval.sym = make_symstr("", strdup(yytext), DEF2);
                                return DEF2;
                                }

%undef                           {
                                if(config.testpreflex)
                                    printf(" [undef] '%s' ", yytext);

                                yylval.sym = make_symstr("", strdup(yytext), UNDEF2);
                                return UNDEF2;
                                }

%ifdef                           {
                                if(config.testpreflex)
                                    printf(" [ifdef] '%s' ", yytext);

                                yylval.sym = make_symstr("", strdup(yytext), IFDEF2);
                                return IFDEF2;
                                }

%elifdef                           {
                                if(config.testpreflex)
                                    printf(" [elifdef] '%s' ", yytext);

                                yylval.sym = make_symstr("", strdup(yytext), ELIFDEF2);
                                return ELIFDEF2;
                                }

%else                           {
                                if(config.testpreflex)
                                    printf(" [else] '%s' ", yytext);

                                yylval.sym = make_symstr("", strdup(yytext), ELSE2);
                                return ELSE2;
                                }

%endif                           {
                                if(config.testpreflex)
                                    printf(" [ifdef] '%s' ", yytext);

                                yylval.sym = make_symstr("", strdup(yytext), ENDIF2);
                                return ENDIF2;
                                }

{FN}{FNN}*                        {
                                if(config.testpreflex)
                                    printf(" [ID] '%s'\n", yytext);

                                yylval.sym = make_symstr("", strdup(yytext), ID2);
                                return ID2;
                                }

[ \t]                            {
                                if(config.testpreflex)
                                    printf(" [SP2] '%s' ", yytext);
                                yylval.sym = make_symstr("", strdup(yytext), SP2);
                                return SP2;
                                }

\r                                {
                                // Ignore
                                if(config.testpreflex)
                                    printf(" [rnl] '%d'", yytext[0]);
                                num_lines++;
                                yylval.sym = make_symstr("", strdup(yytext), NL2);
                                return NL2;
                                }

\n                              {
                                if(config.testpreflex)
                                    printf(" [NL] '%d' ", yytext[0]);

                                num_lines++;
                                yylval.sym = make_symstr("", strdup(yytext), NL2);
                                return NL2;
                                }

\"                              {              /* begin quote */
                                BEGIN(STRSTATE);

                                //if(config.testpreflex)
                                //    printf(" str<<<");

                                prog = 0; backslash  = 0;
                                //tmp_str2[prog++] = yytext[0];
                                }

<STRSTATE>\\$                       {
                                if(config.testpreflex)
                                    printf("[STRSTATE BSL EOL] '%s", yytext);
                                // Skipping ...
                                }

<STRSTATE>\"                        {              /* end quote */
                                if( (backslash % 2) == 0) /* odd backslash */
                                     {
                                     BEGIN(INITIAL);

                                     //tmp_str2[prog++] = yytext[0];
                                     tmp_str2[prog] = '\0';
                                     yylval.sym = make_symstr("", strdup(tmp_str2), STR2);

                                     if(config.testpreflex)
                                        {
                                        //dump_symitem(yylval.sym);
                                        printf("\n[STR] '%s'", yylval.sym->var);
                                        }
                                     //printf("STR2 %d\n", STR2);
                                     return(STR2);
                                     }
                                  else
                                      {  /* add quote */
                                      //  tmp_str2[prog++] = yytext[0];
                                      }
                                }

<STRSTATE>.                         {   // default string charater
                                backslash  = 0;

                                if(config.testpreflex > 1)
                                    printf("'%s'", yytext);

                                tmp_str2[prog++] = yytext[0];
                                }

.                                {  // default character

                                if(config.testpreflex)
                                    printf(" [char] '%s' ", yytext);

                                yylval.sym = make_symstr("", strdup(yytext), CH2);
                                return CH2;
                                }
%%

//<<EOF>>                 {
//                        //printf("got EOF");
//                        yyterminate();
//                        //return NL2;
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
