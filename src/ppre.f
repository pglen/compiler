%{

/* This lexer and parser assumes that int is same size as pointer */

#include <stdio.h>     /* for printf */
#include <stdlib.h>    /* for exit */
#include <unistd.h>    /* for isatty */

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

// Just to silence the C compiler
int     prelex();

#include "ppre.yacc.c"

%}

%x STRSTATE
%x XTRSTATE
%x EXSTATE

%option noyywrap stack

FN   [\~_a-zA-Z]
FNN  [\~_a-zA-Z0-9]

%%

\\\n            {
                inff(0, "[BS EOL] '%s", yytext);
                // no ret, ignore
                }
<INITIAL,EXSTATE>\/\/.*\n  {
                num_lines++;
                inff(0, "[//COMM2] '%s", yytext);
                yylval.sym = make_symstr("", strdup(yytext), "", STR2);
                return COMM2;
                }
<INITIAL,EXSTATE>#.*\n {
                num_lines++;
                inff(0, "[#COMM2] '%s", yytext);
                yylval.sym = make_symstr("", strdup(yytext), "", COMM2);
                return COMM2;
                }
0x[0-9a-fA-F]+  {
                inff(0, "[xNUM2] '%s' ", yytext);
                yylval.sym = make_symstr("name", strdup(yytext), "", NUM2);
                return(NUM2);
                }
0y[0-7]+        {
                inff(0, "[yNUM2] '%s' ", yytext);
                yylval.sym = make_symstr("name", strdup(yytext), "", NUM2);
                return(NUM2);
                }
0z[0-1]+        {
                inff(0, "[zNUM2] '%s' ", yytext);
                yylval.sym = make_symstr("name", strdup(yytext), "", NUM2);
                return(NUM2);
                }
<INITIAL,EXSTATE>\= {
                inff(0, " [EQ2] '%s' ", yytext);
                yylval.sym = make_symstr("", strdup(yytext), "", EQ2);
                return(EQ2);
                }
<INITIAL,EXSTATE>\+   {
                inff(0, " [PLUS2] '%s' ", yytext);
                yylval.sym = make_symstr("", strdup(yytext), "", PLUS2);
                return(PLUS2);
                }
<INITIAL,EXSTATE>\-   {
                inff(0, " [MINUS2] '%s' ", yytext);
                yylval.sym = make_symstr("name", strdup(yytext), "", MINUS2);
                return(MINUS2);
                }
<INITIAL,EXSTATE>\*   {
                inff(0, " [MULT2] '%s' ", yytext);
                yylval.sym = make_symstr("", strdup(yytext), "", MULT2);
                return(MULT2);
                }
<INITIAL,EXSTATE>\/   {
                inff(0, " [DIV2] '%s' ", yytext);
                yylval.sym = make_symstr("", strdup(yytext), "", DIV2);
                return(DIV2);
                }
<INITIAL,EXSTATE>\%                       {
                inff(0, " [MOD2] '%s' ", yytext);
                yylval.sym = make_symstr("", strdup(yytext), "", MOD2);
                return(MOD2);
                }
<INITIAL,EXSTATE>\|   {
                inff(0, " [OR2] '%s' ", yytext);
                yylval.sym = make_symstr("", strdup(yytext), "", OR2);
                return(OR2);
                }
<INITIAL,EXSTATE>\& {
                  inff(0, " [AND2] '%s' ", yytext);
                yylval.sym = make_symstr("", strdup(yytext), "", AND2);
                return(AND2);
                }
<INITIAL,EXSTATE>\! {
                yylval.sym = make_symstr("", strdup(yytext), "", NOT2);
                return(NOT2);
                }
<INITIAL,EXSTATE>\^ {
                inff(0, " [XOR2] '%s' ", yytext);
                yylval.sym = make_symstr("", strdup(yytext), "", XOR2);
                return(XOR2);
                }
<INITIAL,EXSTATE>\(  {
                inff(0, " [PAREN1] '%s' ", yytext);
                yylval.sym = make_symstr("", strdup(yytext), "", PAREN12);
                return(PAREN12);
                }
<INITIAL,EXSTATE>\) {
                inff(0, " [PAREN2] '%s' ", yytext);
                yylval.sym = make_symstr("", strdup(yytext), "", PAREN22);
                return(PAREN22);
                }
<INITIAL,EXSTATE>[0-9]+ {
                inff(0, "[NUM2] '%s' ", (char*)yytext);
                yylval.sym = make_symstr("name", strdup(yytext), "", NUM2);
                return(NUM2);
                }
<INITIAL,EXSTATE>\>\>   {
                inff(0, " [RSHIFT] '%s' ", yytext);
                yylval.sym = make_symstr("name", strdup(yytext), "", RSHIFT2);
                return(RSHIFT2);
                }
<INITIAL,EXSTATE>\<\<   {
                inff(0, " [LSHIFT] '%s' ", yytext);
                yylval.sym = make_symstr("name", strdup(yytext), "", LSHIFT2);
                return(LSHIFT2);
                }
<INITIAL,EXSTATE>;   {
                inff(0, " [SEMI] '%s' ", yytext);
                yylval.sym = make_symstr("name", strdup(yytext), "", SEMI2);
                return(SEMI2);
                }
<INITIAL,EXSTATE>[ \t]  {
                inff(0, " [SP2] '%s' ", yytext);
                yylval.sym = make_symstr("", strdup(yytext), "", SP2);
                return SP2;
                }
<INITIAL,EXSTATE>\r  {
                inff(0, " [rnl] '%d'", yytext[0]);
                num_lines++;
                yylval.sym = make_symstr("", strdup(yytext), "", NL2);
                return NL2;
                }
<INITIAL,EXSTATE>\n  {
                inff(0, " [NL2] '%d' ", yytext[0]);
                num_lines++;
                yylval.sym = make_symstr("", strdup(yytext), "", NL2);
                return NL2;
                }

<INITIAL,EXSTATE>\'   {
                to_new_state(XTRSTATE);
                inff(0, " xtr<<<");
                prog = 0; backslash  = 0;
                //tmp_str2[prog++] = yytext[0];
                }
<INITIAL,EXSTATE>\"     {
                to_new_state(STRSTATE);
                inff(0, " str<<<");
                prog = 0; backslash  = 0;
                //tmp_str2[prog++] = yytext[0];
                }
<INITIAL,EXSTATE>%error  {
                inff(0, " [error] '%s' ", yytext);
                //to_new_state(INITIAL);
                yylval.sym = make_symstr("", strdup(yytext), "", ERR2);
                return ERR2;
                }
<INITIAL,EXSTATE>%mac|%macro  {
                inff(0, " [MAC2] '%s' ", yytext);
                //to_new_state(INITIAL);
                yylval.sym = make_symstr("", strdup(yytext), "", MAC2);
                return MAC2;
                }

<INITIAL,EXSTATE>%nl|%newline   {
                inff(0, " [enl] '%s' ", yytext);
                //to_new_state(INITIAL);
                yylval.sym = make_symstr("", strdup(yytext), "", MSG2);
                return ENL2;
                }
<INITIAL,EXSTATE>%msg|%message  {
                inff(0, " [MSG2] '%s' ", yytext);
                //to_new_state(INITIAL);
                yylval.sym = make_symstr("", strdup(yytext), "", MSG2);
                return MSG2;
                }
<INITIAL,EXSTATE>%def|%define  {
                inff(0, " \n[DEF2] '%s' ", yytext);
                //to_new_state(INITIAL);
                yylval.sym = make_symstr("", strdup(yytext), "", DEF2);
                return DEF2;
                }
<INITIAL,EXSTATE>%undef  {
                inff(0, " [undef] '%s' ", yytext);
                //to_new_state(INITIAL);
                yylval.sym = make_symstr("", strdup(yytext), "", UNDEF2);
                return UNDEF2;
                }
<INITIAL,EXSTATE>%ifdef {
                inff(0, " [ifdef] '%s' ", yytext);
                //to_new_state(INITIAL);
                yylval.sym = make_symstr("", strdup(yytext), "", IFDEF2);
                return IFDEF2;
                }

<INITIAL,EXSTATE>%elifdef  {
                inff(0, " [elifdef] '%s' ", yytext);
                //to_new_state(INITIAL);
                yylval.sym = make_symstr("", strdup(yytext), "", ELIFDEF2);
                return ELIFDEF2;
                }
<INITIAL,EXSTATE>%else    {
                inff(0, " [else] '%s' ", yytext);
                //to_new_state(INITIAL);
                yylval.sym = make_symstr("", strdup(yytext), "", ELSE2);
                return ELSE2;
                }
<INITIAL,EXSTATE>%endif     {
                inff(0, "%s", " [ %endif ] ");
                inff(0, "emit: '%s'\n", emitline);
                //hd(emitline, strlen(emitline) + 12);

                BEGIN(INITIAL);
                }
{FN}{FNN}*      {
                inff(0, " [ID2] '%s' ", yytext);
                yylval.sym = make_symstr("", strdup(yytext), "", ID2);
                return ID2;
                }
<INITIAL,EXSTATE>{FN}{FNN}*   {
                inff(0, " [ID2] '%s' ", yytext);
                yylval.sym = make_symstr("", strdup(yytext), "", ID3);
                return ID2;
                }
<EXSTATE>.      {
                // default emit charater
                inff(0, " [emit] '%c' ", yytext[0]);
                if(hasdefine)
                    {
                    //if(config.testpreflex > 0)
                    //    inff(0, " [emitx] '%c' ", yytext[0]);
                    addemit(yytext[0]);
                    }
                }
<XTRSTATE,STRSTATE>\\$  {
                inff(0, "[STRSTATE BSL EOL] '%s", yytext);
                // Skipping ...
                }
<STRSTATE>\"    {
                if( (backslash % 2) == 0) /* odd backslash */
                    {
                    //BEGIN(INITIAL);
                    to_prev_state();

                    //tmp_str2[prog++] = yytext[0];
                    tmp_str2[prog] = '\0';
                    yylval.sym = make_symstr("", strdup(tmp_str2), "", STR2);
                    inff(0, "[STR2] '%s' ", yylval.sym->var);
                    return(STR2);
                    }
                  else
                    {  /* add quote */
                    //  tmp_str2[prog++] = yytext[0];
                    }
                }
<XTRSTATE>\'    {
                if( (backslash % 2) == 0) /* odd backslash */
                     {
                     //BEGIN(INITIAL);
                     to_prev_state();

                     //tmp_str2[prog++] = yytext[0];
                     tmp_str2[prog] = '\0';
                     yylval.sym = make_symstr("", strdup(tmp_str2), "", STR2);
                     inff(0, "[STR2] '%s' ", yylval.sym->var);
                     return(STR2);
                     }
                  else
                      {  /* add quote */
                      //  tmp_str2[prog++] = yytext[0];
                      }
                }
<XTRSTATE,STRSTATE>. {   // default string charater
                backslash  = 0;
                inff(0, "'%s'", yytext);
                tmp_str2[prog++] = yytext[0];
                }
<INITIAL,EXSTATE>.  {  // default character
                inff(0, " [CH2] '%s' ", yytext);
                yylval.sym = make_symstr("", strdup(yytext), "", CH2);
                return CH2;
                }
%%

/* ========================= End of LEX ================================ */

int     to_new_state(int state)
{
    int old = YY_START;
    yy_push_state(state);
    //printf("new state from %d to %d\n", old, YY_START);
    return 0;
}

int     to_prev_state()
{
    int old = YY_START;
    yy_pop_state();
    //printf("reset state from %d to %d\n", old, YY_START);
    return 0;
}

///////////////////////////////////////////////////////////////////////////

int     preprocess(char *ptr)

{
    int ret_val = 1;
    struct stat buf;

    // re - initialize preprocessor
    num_lines = 1;

    //printf("states %d %d %d\n", INITIAL, STRSTATE, EXSTATE);
    //to_new_state(EXSTATE);

    if(stat(ptr, &buf) >= 0)
        {
        //fprintf(stderr, "Cannot stat file '%s'\n", ptr);
        //if(config.debuglevel > 0)
        //    syslog(LOG_DEBUG, "Cannot stat file %s\n", ptr);
        if(S_ISDIR(buf.st_mode))
            {
            fprintf(stderr, "Cannot operate on directory '%s'.\n", ptr);
            //if(config.debuglevel > 0)
            //    syslog(LOG_DEBUG, "cannot operate on dir %s\n", ptr);
            //return 0;
            }
        }
    ppfp3 = fopen(ptr, "r");
    if(!ppfp3)
        {
        fprintf(stderr, "Cannot open file: '%s'.\n", ptr);
        //if(config.debuglevel > 0)
        //    syslog(LOG_DEBUG, "Cannot open file %s\n", ptr);
        //return 0;
        exit(1);
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
        fprintf(stderr, "Cannot create file '%s'.\n", ppfile);
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
    fprintf(ppfp2, "%s", emitline);
    fclose(ppfp2);
    if(config.catpre)
        {
        printf("\nPre processed file:\n");
        sprintf(tmp_str, "cat %s", ppfile2);
        int ret = system(tmp_str);
        printf("EOF\n");
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

    // Is term?
    if(isatty(2) > 0)
        {
        fprintf(stderr, "\033[31;1mERROR\033[0m ");
        }
    else
        {
        fprintf(stderr, "ERROR ");
        //fprintf(stderr, "\033[31;1mERROR\033[0m ");
        }

    if(currprog == 0)
        {
        if(strlen(prevline))
            {
            fprintf(stderr, "%s\n      ", prevline);
            for(int aa = currprog; aa < strlen(prevline)-1; aa++)
                {
                fprintf(stderr, "-");
                }
            fprintf(stderr, "^\n");
            }
        }
     else
        {
        if(strlen(currline))
            {
            fprintf(stderr, "Line: '%s'\n             ", currline);
            for(int aa = 0; aa < currprog; aa++)
                {
                fprintf(stderr, "-");
                }
            fprintf(stderr, "^");
            for(int aa = currprog; aa < strlen(currline)-1; aa++)
                {
                fprintf(stderr, "-");
                }
            fprintf(stderr, "\n");

            //hd(currline, 200);
            }
        }
    fprintf(stderr, "emitline: '%s'\n", emitline);
    fseek(ppfp3, pos, SEEK_SET);
    //if(count > 5)
        exit(0);
}

// EOF
