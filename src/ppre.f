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
%x COMSTATE

%option noyywrap stack

FN   [\~_a-zA-Z]
FNN  [\~_a-zA-Z0-9]

%%

\\\n            {
                inff(0, "[BS EOL] '%s", yytext);
                // no ret, ignore
                }
<INITIAL,EXSTATE>\/\/.*$  {
                num_lines++;
                inff(1, "[//COMM2] '%s", yytext);
                yylval.sym = make_symstr("", strdup(yytext), "", STR2);
                return COMM2;
                }
<INITIAL,EXSTATE>#.*$ {
                num_lines++;
                inff(1, "[#COMM2] '%s", yytext);
                yylval.sym = make_symstr("", strdup(yytext), "", COMM2);
                return COMM2;
                }
<INITIAL,EXSTATE>var {
                inff(0, "[VAR2] '%s", yytext);
                yylval.sym = make_symstr("", strdup(yytext), "", VAR2);
                return VAR2;
                }
<INITIAL,EXSTATE>func {
                inff(0, "[FUNC2] '%s", yytext);
                yylval.sym = make_symstr("", strdup(yytext), "", FUNC2);
                return FUNC2;
                }
<INITIAL,EXSTATE>return {
                inff(0, "[RET2] '%s", yytext);
                yylval.sym = make_symstr("", strdup(yytext), "", RET2);
                return RET2;
                }
<INITIAL,EXSTATE>\{ {
                inff(0, "[LBRA2] '%s", yytext);
                yylval.sym = make_symstr("", strdup(yytext), "", LBRA2);
                return LBRA2;
                }
<INITIAL,EXSTATE>\} {
                inff(0, "[RBRA2] '%s", yytext);
                yylval.sym = make_symstr("", strdup(yytext), "", RBRA2);
                return RBRA2;
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
                inff(0, " [PAREN12] '%s' ", yytext);
                yylval.sym = make_symstr("", strdup(yytext), "", LPAREN2);
                return(LPAREN2);
                }
<INITIAL,EXSTATE>\) {
                inff(0, " [RPAREN2] '%s' ", yytext);
                yylval.sym = make_symstr("", strdup(yytext), "", RPAREN2);
                return(RPAREN2);
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
                inff(0, " [SEMI2] '%s' ", yytext);
                yylval.sym = make_symstr("name", strdup(yytext), "", SEMI2);
                return(SEMI2);
                }
<INITIAL,EXSTATE>:   {
                inff(0, " [COL2] '%s' ", yytext);
                yylval.sym = make_symstr("name", strdup(yytext), "", COL2);
                return(COL2);
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
                inff(1, " xtr<<<");
                prog = 0; backslash  = 0;
                //tmp_str2[prog++] = yytext[0];
                }
<INITIAL,EXSTATE>\"     {
                to_new_state(STRSTATE);
                inff(1, " str<<<");
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
                //inff(0, "emit: '%s'\n", emitline);
                //hd(emitline, strlen(emitline) + 12);
                BEGIN(INITIAL);
                return ENDIF2;
                }
<INITIAL,EXSTATE>type     {
                inff(0, "%s", " [TYPE2] ");
                //hd(emitline, strlen(emitline) + 12);
                yylval.sym = make_symstr("", strdup(yytext), "", TYPE2);
                return TYPE2;
                }
{FN}{FNN}*      {
                inff(0, " [ID2] '%s' ", yytext);
                yylval.sym = make_symstr("", strdup(yytext), "", ID2);
                return ID2;
                }
\/\*            {
                inff(1, " [COM/*] '%s' ", yytext);
                BEGIN(COMSTATE);
                }
<COMSTATE>\*\/  {
                //inff(0, " [COM*/] '%s' ", yytext);
                BEGIN(INITIAL);
                yylval.sym = make_symstr("", strdup(tmp_str2), "", COMM3);
                inff(1, "[COMM3] '%s' ", yylval.sym->var);
                return COMM3;
                }
<COMSTATE>\n    {
                tmp_str2[prog++] = yytext[0];
                //printf("");
                inff(1, " [COM3] nl '%s' ", yytext);
                }
<COMSTATE>.     {
                tmp_str2[prog++] = yytext[0];
                //printf("");
                inff(1, " [COM3] char '%s' ", yytext);
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
                if(!backslash)
                    {
                    to_prev_state();
                    tmp_str2[prog] = '\0';
                    yylval.sym = make_symstr("", strdup(tmp_str2), "", STR2);
                    inff(0, "[STR2] '%s' ", yylval.sym->var);
                    return(STR2);
                    }
                  else
                    {  /* add backslash char */
                    tmp_str2[prog++] = '\\';
                    tmp_str2[prog++] = yytext[0];
                    backslash = 0;
                    }
                }
<XTRSTATE>\'    {
                if(!backslash)
                     {
                     to_prev_state();
                     //tmp_str2[prog++] = yytext[0];
                     tmp_str2[prog] = '\0';
                     yylval.sym = make_symstr("", strdup(tmp_str2), "", STR2);
                     inff(0, "[STR2] '%s' ", yylval.sym->var);
                     return(STR2);
                     }
                  else
                      {  /* add quote */
                      tmp_str2[prog++] = '\\';
                      tmp_str2[prog++] = yytext[0];
                      backslash = 0;
                      }
                }
<XTRSTATE,STRSTATE>\\ {
                inff(0, "[BSL] '%s' ", yytext);
                backslash++;
                }
<XTRSTATE,STRSTATE>. {   // default string charater
                inff(1, "'%s'", yytext);
                if(backslash)
                    {
                    tmp_str2[prog++] = '\\';
                    backslash = 0;
                    }
                tmp_str2[prog++] = yytext[0];
                }
<INITIAL,EXSTATE>. {  // default character
                inff(1, " [CH2] '%s' ", yytext);
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

    if(config.debpreyacc)
        predebug = 1;

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
        printf("makeing '%s'\n", outdir);
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
        fprintf(stderr, "Cannot create file '%s'.\n", ppfile2);
        if(config.verbose)
            {
            fprintf(stderr, "'%s' %s.\n", ppfile, strerror(errno));
            }
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
    int pos = ftell(ppfp3);

    // Is term?
    char *errstr = "\nPreprocess Error:";
    if(isatty(2) > 0)
        {
        fprintf(stderr, "\033[31;1m%s\033[0m ", errstr);
        }
    else
        {
        fprintf(stderr, "%s ", errstr);
        }
    fprintf(stderr, "%s  Line: %d  Col: %d Near: '%s'\n",
                                str, num_lines, currprog, yytext);
    //int cnt = strlen(errstr);
    //while(cnt)
    //        {
    //        fprintf(stderr, "a");
    //        cnt--;
    //        }
    // Get current line to line end
    int ppp = currprog;
    while(ppp < sizeof(currline))
        {
        char ccc = fgetc(ppfp3);
        if(ccc == '\n' || ccc == EOF)
            {
            currline[ppp] = '\0';
            break;
            }
        currline[ppp] = ccc;
        ppp++;
        }
    //fprintf(stderr, "Context:\n");
    fprintf(stderr, "%s\n", prevline);
    fprintf(stderr, "%s\n", currline);
    int cnt = currprog;
    while(cnt)
            {
            fprintf(stderr, "-");
            cnt--;
            }
    fprintf(stderr, "^");
    int cnt2 = strlen(currline) - currprog - 2;
    while(cnt2 >= 0)
            {
            fprintf(stderr, "-");
            cnt2--;
            }
    fprintf(stderr, "\n");

    fseek(ppfp3, pos, SEEK_SET);
    exit(2);
}

// EOF
