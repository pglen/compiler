%{

/* This lexer and parser assumes that int is same size as pointer */

#include <stdio.h>     /* for printf */
#include <stdlib.h>    /* for exit */

#include "../symtab.h"
#include  "../pcomp.h"
#include  "../utils.h"

static    char    tmp_str[2 * MAX_PATHLEN];
static    char    tmp_str2[2 * MAX_PATHLEN];

char    ppfile2[MAX_PATHLEN];
char    ppfile[MAX_PATHLEN];

FILE    *ppfp3, *ppfp2;

#define YY_INPUT(buf, result, max_size) \
        result = inputx(buf, max_size, ppfp3);

//#define YY_INPUT(buf, result, max_size) \
//               { \
//               int c = getc(ppfp3); \
//               result = (c == EOF) ? YY_NULL : (buf[0] = c, 1); \
//               }

#define DEBUGLEX

// Just to silence C compiler
int     prelex();

#include "ppre.yacc.c"

%}

%x STRSTATE
%x EMITSTATE

%option noyywrap stack

FN   [\~_a-zA-Z]
FNN  [\~_a-zA-Z0-9]

%%

\\\n                 {
                     if(config.testpreflex)
                         { printf("[BS EOL] '%s", yytext); fflush(stdout); }
                     // Ignore
                     }

\/\/.*\n             { /* comment */
                         num_lines++;

                         if(config.testpreflex)
                             { printf("[slash_comment] '%s", yytext); fflush(stdout); }

                         if(config.showcomm)
                             printf("//comment: '%s", yytext);

                         yylval.sym = make_symstr("", strdup(yytext), STR2);
                         return COMMENT2;
                     }

#.*\n                { /* comment */
                         num_lines++;

                         if(config.testpreflex)
                             { printf("[hash_comment] '%s", yytext); fflush(stdout); }

                         if(config.showcomm)
                             printf("#comment: '%s", yytext);

                         yylval.sym = make_symstr("name", strdup(yytext), COMMENT2);
                         return COMMENT2;
                     }

0x[0-9a-fA-F]+       {
                         if(config.testpreflex)
                             { printf("[NUM] '%s' ", yytext); fflush(stdout); }

                         yylval.sym = make_symstr("name", strdup(yytext), NUM2);
                         return(NUM2);
                     }
0y[0-7]+             {
                         if(config.testpreflex)
                             { printf("[NUM] '%s' ", yytext); fflush(stdout); }

                         yylval.sym = make_symstr("name", strdup(yytext), NUM2);

                         return(NUM2);
                         }
0z[0-1]+                 {
                         if(config.testpreflex)
                             { printf("[NUM] '%s' ", yytext); fflush(stdout); }

                         yylval.sym = make_symstr("name", strdup(yytext), NUM2);

                         return(NUM2);
                         }
\+                       {
                         if(config.testpreflex)
                             { printf(" [PLUS] '%s' ", yytext); fflush(stdout); }
                          yylval.sym = make_symstr("", strdup(yytext), PLUS2);
                         return(PLUS2);
                         }
\-                       {
                         if(config.testpreflex)
                             { printf(" [MINUS] '%s' ", yytext); fflush(stdout); }

                         yylval.sym = make_symstr("name", strdup(yytext), MINUS2);
                         return(MINUS2);
                         }
\*                       {
                         if(config.testpreflex)
                             { printf(" [MULT] '%s' ", yytext); fflush(stdout); }

                         yylval.sym = make_symstr("", strdup(yytext), MULT2);
                         return(MULT2);
                         }
\/                       {
                         if(config.testpreflex)
                             { printf(" [DIV] '%s' ", yytext); fflush(stdout); }

                         yylval.sym = make_symstr("", strdup(yytext), DIV2);
                         return(DIV2);
                         }
\%                       {
                         if(config.testpreflex)
                             { printf(" [MOD] '%s' ", yytext); fflush(stdout); }

                         yylval.sym = make_symstr("", strdup(yytext), MOD2);
                         return(MOD2);
                         }
\|                       {
                         if(config.testpreflex)
                             { printf(" [OR] '%s' ", yytext); fflush(stdout); }

                         yylval.sym = make_symstr("", strdup(yytext), OR2);
                         return(OR2);
                         }
\&                       {
                         if(config.testpreflex)
                             { printf(" [AND] '%s' ", yytext); fflush(stdout); }

                         yylval.sym = make_symstr("", strdup(yytext), AND2);
                         return(AND2);
                         }
\!                       {
                         yylval.sym = make_symstr("", strdup(yytext), NOT2);
                         return(NOT2);
                         }
\^                       {
                         if(config.testpreflex)
                             { printf(" [XOR] '%s' ", yytext); fflush(stdout); }

                         yylval.sym = make_symstr("", strdup(yytext), XOR2);
                         return(XOR2);
                         }
\(                       {
                         if(config.testpreflex)
                             { printf(" [PAREN1] '%s' ", yytext); fflush(stdout); }

                         yylval.sym = make_symstr("", strdup(yytext), PAREN12);
                         return(PAREN12);
                         }
\)                       {
                         if(config.testpreflex)
                             { printf(" [PAREN2] '%s' ", yytext); fflush(stdout); }

                         yylval.sym = make_symstr("", strdup(yytext), PAREN22);
                         return(PAREN22);
                         }

[0-9]+                  {
                         if(config.testpreflex)
                             { printf("[NUM] '%s' ", (char*)yytext); fflush(stdout); }

                         yylval.sym = make_symstr("name", strdup(yytext), NUM2);

                         return(NUM2);
                         }

\>\>                     {
                         if(config.testpreflex)
                             { printf(" [RSHIFT] '%s' ", yytext); fflush(stdout); }

                         yylval.sym = make_symstr("name", strdup(yytext), RSHIFT2);

                         return(RSHIFT2);
                         }

\<\<                     {
                         if(config.testpreflex)
                             { printf(" [LSHIFT] '%s' ", yytext); fflush(stdout); }

                         yylval.sym = make_symstr("name", strdup(yytext), LSHIFT2);
                         return(LSHIFT2);
                         }
;                        {
                         if(config.testpreflex)
                             { printf(" [SEMI] '%s' ", yytext); fflush(stdout); }

                         yylval.sym = make_symstr("name", strdup(yytext), SEMI2);
                         return(SEMI2);
                         }
[ \t]                   {
                        if(config.testpreflex)
                            { printf(" [SP2] '%s' ", yytext); fflush(stdout); }
                        yylval.sym = make_symstr("", strdup(yytext), SP2);
                        return SP2;
                        }
<EMITSTATE>%error                   {
                         if(config.testpreflex)
                             { printf(" [error] '%s' ", yytext); fflush(stdout); }

                         yylval.sym = make_symstr("", strdup(yytext), ERR2);
                         return ERR2;
                         }

<EMITSTATE>%mac|%macro         {
                                if(config.testpreflex)
                                    { printf(" [mmacro] '%s' ", yytext); fflush(stdout); }

                                yylval.sym = make_symstr("", strdup(yytext), MAC2);
                                return MAC2;
                                }

<EMITSTATE>%nl|%newline         {
                                if(config.testpreflex)
                                    { printf(" [e nl] '%s' ", yytext); fflush(stdout); }
                                yylval.sym = make_symstr("", strdup(yytext), MSG2);
                                return ENL2;
                                }
<EMITSTATE>%msg|%message        {
                                if(config.testpreflex)
                                    { printf(" [message] '%s' ", yytext); fflush(stdout); }
                                to_init_state();
                                yylval.sym = make_symstr("", strdup(yytext), MSG2);
                                return MSG2;
                                }
<EMITSTATE>%def|%define         {
                                if(config.testpreflex)
                                    { printf(" [define] '%s' ", yytext); fflush(stdout); }

                                yylval.sym = make_symstr("", strdup(yytext), DEF2);
                                return DEF2;
                                }

<EMITSTATE>%undef               {
                                if(config.testpreflex)
                                    { printf(" [undef] '%s' ", yytext); fflush(stdout); }

                                yylval.sym = make_symstr("", strdup(yytext), UNDEF2);
                                return UNDEF2;
                                }

<EMITSTATE>%ifdef               {
                                if(config.testpreflex)
                                    { printf(" [ifdef] '%s' ", yytext); fflush(stdout); }

                                yylval.sym = make_symstr("", strdup(yytext), IFDEF2);
                                return IFDEF2;
                                }

<EMITSTATE>%elifdef                           {
                                if(config.testpreflex)
                                    { printf(" [elifdef] '%s' ", yytext); fflush(stdout); }

                                yylval.sym = make_symstr("", strdup(yytext), ELIFDEF2);
                                return ELIFDEF2;
                                }

<EMITSTATE>%else                           {
                                if(config.testpreflex)
                                    { printf(" [else] '%s' ", yytext); fflush(stdout); }

                                yylval.sym = make_symstr("", strdup(yytext), ELSE2);
                                return ELSE2;
                                }

<EMITSTATE>%endif                          {
                                if(config.testpreflex)
                                    { printf(" [ifdef] '%s' ", yytext); fflush(stdout); }

                                yylval.sym = make_symstr("", strdup(yytext), ENDIF2);
                                return ENDIF2;
                                }

[ \t]                {
                                if(config.testpreflex)
                                    { printf(" [SP2] '%s' ", yytext); fflush(stdout); }
                                yylval.sym = make_symstr("", strdup(yytext), SP2);
                                return SP2;
                                }

\r                              {
                                // Ignore
                                if(config.testpreflex)
                                    { printf(" [rnl] '%d'", yytext[0]); fflush(stdout); }
                                num_lines++;
                                yylval.sym = make_symstr("", strdup(yytext), NL2);
                                return NL2;
                                }

\n                              {
                                if(config.testpreflex)
                                    { printf(" [NL] '%d' ", yytext[0]); fflush(stdout); }

                                num_lines++;
                                yylval.sym = make_symstr("", strdup(yytext), NL2);
                                return NL2;
                                }

\"                              {              /* begin quote */
                                //BEGIN(STRSTATE);
                                yy_push_state(STRSTATE);
                                //if(config.testpreflex)
                                //    printf(" str<<<");

                                prog = 0; backslash  = 0;
                                //tmp_str2[prog++] = yytext[0];
                                }

<EMITSTATE>%endif               {
                                printf("%s", " [ %endif ] ");
                                printf("emit: '%s'\n", emitline);
                                //hd(emitline, strlen(emitline) + 12);

                                BEGIN(INITIAL);
                                }
<EMITSTATE>\n                   {
                                //printf("emit newline");
                                if(hasdefine)
                                    {
                                    addemit(yytext[0]);
                                    }
                                }
<EMITSTATE>{FN}{FNN}*           {
                                if(config.testpreflex)
                                    { printf(" [ID] '%s' ", yytext); fflush(stdout); }

                                yylval.sym = make_symstr("", strdup(yytext), ID2);
                                return ID2;
                                }
<EMITSTATE>.                    {
                                // default emit charater
                                if(config.testpreflex > 1)
                                    { printf(" [emit] '%c' ", yytext[0]); fflush(stdout); }
                                if(hasdefine)
                                    {
                                    //if(config.testpreflex > 0)
                                    //    printf(" [emitx] '%c' ", yytext[0]);
                                    addemit(yytext[0]);
                                    }
                                }
<STRSTATE>\\$                       {
                                if(config.testpreflex)
                                    { printf("[STRSTATE BSL EOL] '%s", yytext); fflush(stdout); }
                                // Skipping ...
                                }

<STRSTATE>\"                    {              /* end quote */
                                if( (backslash % 2) == 0) /* odd backslash */
                                     {
                                     //BEGIN(INITIAL);
                                     yy_pop_state();

                                     //tmp_str2[prog++] = yytext[0];
                                     tmp_str2[prog] = '\0';
                                     yylval.sym = make_symstr("", strdup(tmp_str2), STR2);

                                     if(config.testpreflex)
                                        {
                                        //dump_symitem(yylval.sym);
                                        printf("\n[STR] '%s'", yylval.sym->var); fflush(stdout);
                                        }
                                     //printf("STR2 %d\n", STR2);
                                     return(STR2);
                                     }
                                  else
                                      {  /* add quote */
                                      //  tmp_str2[prog++] = yytext[0];
                                      }
                                }
<STRSTATE>.                     {   // default string charater
                                backslash  = 0;

                                if(config.testpreflex > 1)
                                    { printf("'%s'", yytext); fflush(stdout); }

                                tmp_str2[prog++] = yytext[0];
                                }
.                               {  // default character

                                if(config.testpreflex)
                                    { printf(" [char] '%s' ", yytext); fflush(stdout); }

                                yylval.sym = make_symstr("", strdup(yytext), CH2);
                                return CH2;
                                }
%%

/* ========================= End of LEX ================================ */

int     to_emit_state()
{
    //printf("states %d %d %d\n", INITIAL, STRSTATE, EMITSTATE);
    //printf("start state %d\n", YY_START);
    yy_push_state(EMITSTATE);
    //printf("new state %d\n", YY_START);
    return 0;
}

int     to_init_state()
{
    //printf("states %d %d %d\n", INITIAL, STRSTATE, EMITSTATE);
    //printf("start state %d\n", YY_START);
    yy_push_state(INITIAL);
    printf("to_init_state %d\n", YY_START);
    return 0;
}

int     to_prev_state()
{
    yy_pop_state();
    printf("rset old state %d\n", YY_START);
    return 0;
}

///////////////////////////////////////////////////////////////////////////

int     preprocess(char *ptr)

{
    int ret_val = 1;
    struct stat buf;

    // re - initialize preprocessor
    num_lines = 1;

    to_emit_state();

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

void    preerror(const char *str)

{
    static int count = 0;
    count++;
    fprintf(stderr, "%s  Line: %d  Col: %d Near: '%s'\n",
                                str, num_lines, currprog, yytext);
    //fprintf(stderr, "Line at offset: %ld\n",
    int pos = ftell(ppfp3);
    int ppp = currprog;
    while(ppp < sizeof(currline))
        {
        char ccc = fgetc(ppfp3);
        if(ccc == '\n' || ccc == EOF)
            break;
        currline[ppp] = ccc;
        ppp++;
        }
    currline[ppp] = '\0';
    fprintf(stderr, "Line: '%s'\n      ", currline);
    for(int aa = 0; aa < currprog; aa++)
        {
        fprintf(stderr, "-");
        }
    fprintf(stderr, "^");
    for(int aa = currprog; aa < strlen(currline); aa++)
        {
        fprintf(stderr, "-");
        }
    fprintf(stderr, "\n");
    fprintf(stderr, "emitline: '%s'\n", emitline);

    //hd(currline, 200);
    fseek(ppfp3, pos, SEEK_SET);
    if(count > 5)
        exit(0);
}

// EOF
