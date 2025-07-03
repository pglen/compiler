%{

/* This lexer and parser assumes that int is same size as pointer */

#include <stdio.h>     /* for printf */
#include <stdlib.h>    /* for exit */

#include "../symtab.h"
#include  "../pcomp.h"

//int num_lines = 1, num_chars = 0, backslash = 0, prog = 0;

static    char	tmp_str[MAX_VARLEN];
static    char	tmp_str2[MAX_VARLEN];

char    ppfile2[MAX_VARLEN];
char    ppfile[MAX_VARLEN];

FILE *ppfp3, *ppfp2;

#define YY_INPUT(buf,result,max_size) \
               { \
               int c = getc(ppfp3); \
               result = (c == EOF) ? YY_NULL : (buf[0] = c, 1); \
               }

void preerror(const char *str)

{
     static int count = 0;
      printf("%s  Line: %d  Near '%s'\n", str, num_lines, yytext); count++;
    if(count > 5) exit(0);
}

#define DEBUGLEX

#include "ppre.yacc.c"

%}

%x STR2
%x COM2

%option noyywrap

FN   [\~_a-zA-Z]
FNN  [\~_a-zA-Z0-9]

%%

\/\/.*\n                       { /* comment */
    	    	    	    	num_lines++;

                                if(config.testflex)
                                    printf("[slash comment2] '%s", yytext);

                                yylval.strval = strdup(yytext);
    	    	    	    	return COMMENT;
    	    	    	    	}

#.*\n                          { /* comment */
    	    	    	    	num_lines++;

                                if(config.testflex)
                                    printf("[hash comment2] '%s", yytext);

                                yylval.strval = strdup(yytext);
    	    	    	    	return COMMENT;
    	    	    	    	}

0x[0-9a-fA-F]+                  {
                                if(config.testflex)
                                    printf("[NUM] '%s' ", yytext);

                                yylval.strval = strdup(yytext);
                                return(NUM);
                                }

0y[0-7]+                      	{
                                if(config.testflex)
                                    printf("[NUM] '%s' ", yytext);

                                yylval.strval = strdup(yytext);
                                return(NUM);
                                }

0z[0-1]+                        {
                                if(config.testflex)
                                    printf("[NUM] '%s' ", yytext);

                                yylval.strval = strdup(yytext);

                                return(NUM);
                                }

[0-9]+                          {
                                if(config.testflex)
                                    printf("[NUM] '%s' ", (char*)yytext);

                                yylval.strval = strdup(yytext); return(NUM);
                                }

\>\>                            {
                                if(config.testflex)
                                    printf(" [RSHIFT] '%s' ", yytext);

                                yylval.strval = strdup(yytext); return(RSHIFT);
    	    	    	    	}

\<\<                            {
                                if(config.testflex)
                                    printf(" [LSHIFT] '%s' ", yytext);

                                yylval.strval = strdup(yytext); return(LSHIFT);
    	    	    	    	}

\+                              {
                                yylval.strval = strdup(yytext); return(PLUS);
    	    	    	    	}
\-                              {
                                if(config.testflex)
                                    printf(" [MINUS] '%s' ", yytext);

                                yylval.strval = strdup(yytext); return(MINUS);
    	    	    	    	}
\*                              {
                                if(config.testflex)
                                    printf(" [MULT] '%s' ", yytext);

                                yylval.strval = strdup(yytext); return(MULT);
    	    	    	    	}
\/                              {
                                if(config.testflex)
                                    printf(" [DIV] '%s' ", yytext);

                                yylval.strval = strdup(yytext); return(DIV);
    	    	    	    	}
\%                              {
                                if(config.testflex)
                                    printf(" [MOD] '%s' ", yytext);

                                yylval.strval = strdup(yytext); return(MOD);
    	    	    	    	}
\|                              {
                                if(config.testflex)
                                    printf(" [OR] '%s' ", yytext);

                                yylval.strval = strdup(yytext); return(OR);
    	    	    	    	}
\&                              {
                                if(config.testflex)
                                    printf(" [AND] '%s' ", yytext);

                                yylval.strval = strdup(yytext); return(AND);
    	    	    	    	}
\!                              {
                                yylval.strval = strdup(yytext); return(NOT);
    	    	    	    	}
\^                              {
                                if(config.testflex)
                                    printf(" [XOR] '%s' ", yytext);

                                yylval.strval = strdup(yytext); return(XOR);
    	    	    	    	}
\(                              {
                                if(config.testflex)
                                    printf(" [PAREN1] '%s' ", yytext);

                                yylval.strval = strdup(yytext); return(PAREN1);
    	    	    	    	}
\)                              {
                                if(config.testflex)
                                    printf(" [PAREN2] '%s' ", yytext);

                                yylval.strval = strdup(yytext); return(PAREN2);
    	    	    	    	}
%error                          {
                                if(config.testflex)
                                    printf(" [error] '%s' ", yytext);

                                yylval.strval = strdup(yytext);
    	    	    	    	return ERR;
    	    	    	    	}

%macro                          {
                                if(config.testflex)
                                    printf(" [mmacro] '%s' ", yytext);

                                yylval.strval = strdup(yytext);
    	    	    	    	return MAC;
    	    	    	    	}

%message                          {
                                if(config.testflex)
                                    printf(" [message] '%s' ", yytext);

                                yylval.strval = strdup(yytext);
    	    	    	    	return MSG;
    	    	    	    	}
%define                           {
                                if(config.testflex)
                                    printf(" [define] '%s' ", yytext);

                                yylval.strval = strdup(yytext);
    	    	    	    	return DEF;
    	    	    	    	}

%undef                           {
                                if(config.testflex)
                                    printf(" [undef] '%s' ", yytext);

                                yylval.strval = strdup(yytext);
    	    	    	    	return UNDEF;
    	    	    	    	}

%ifdef                           {
                                if(config.testflex)
                                    printf(" [ifdef] '%s' ", yytext);

                                yylval.strval = strdup(yytext);
    	    	    	    	return IFDEF;
    	    	    	    	}

%elifdef                           {
                                if(config.testflex)
                                    printf(" [elifdef] '%s' ", yytext);

                                yylval.strval = strdup(yytext);
    	    	    	    	return ELIFDEF;
    	    	    	    	}

%else                           {
                                if(config.testflex)
                                    printf(" [else] '%s' ", yytext);

                                yylval.strval = strdup(yytext);
    	    	    	    	return ELSE;
    	    	    	    	}

%endif                           {
                                if(config.testflex)
                                    printf(" [ifdef] '%s' ", yytext);

                                yylval.strval = strdup(yytext);
    	    	    	    	return ENDIF;
    	    	    	    	}

{FN}{FNN}*                		{
                                if(config.testflex)
                                    printf(" [ID] '%s'\n", yytext);

                                yylval.strval = strdup(yytext);
    	    	    	    	return ID;
    	    	    	    	}

[ \t]    						{
                                if(config.testflex)
                                    printf(" [SP] '%s' ", yytext);
                                yylval.strval = strdup(yytext);
    	    	    	    	return SP;
    	    	    	    	}

\r    			    	    	{
    	    	    	    	// Ignore
    	    	    	    	}

\n    			    	    	{
                                if(config.testflex)
                                    printf(" [nl] '%d'\n", yytext[0]);

    	    	    	    	num_lines++;
                                yylval.strval = strdup(yytext);
    	    	    	    	return NL;
    	    	    	    	}

\"                              {              /* begin quote */
                                BEGIN(STR2);

                                if(config.testflex)
                                    printf(" str<<<");

                                prog = 0; backslash  = 0;
    	    	    	           tmp_str2[prog++] = yytext[0];
                                }

<STR2>\\                        {
                                if(config.testflex)
    	    	    	    	    printf("\\");

    	    	    	    	tmp_str2[prog++] = yytext[0];
    	    	    	    	backslash++;
    	    	    	    	}

<STR2>\"                        {      		/* end quote */
                                if( (backslash % 2) == 0) /* odd backslash */
                                     {
                                     BEGIN(INITIAL);

                                     if(config.testflex)
                                        printf(">>>str ");

    	    	    	    	     tmp_str2[prog++] = yytext[0];
    	    	    	    	     tmp_str2[prog] = '\0';
                                     yylval.strval = strdup(tmp_str2);
                                     return(STR);
                                     }
                                  else
                                      {  /* add quote */
    	    	    	    	    tmp_str2[prog++] = yytext[0];
                                      }
                                }

<STR2>.                         {   // default string charater
                                backslash  = 0;

                                if(config.testflex)
                                    printf("'%s'", yytext);

    	    	    	    	tmp_str2[prog++] = yytext[0];
                                }


.    		    	    	    {  // default character

                                if(config.testflex)
                                    printf(" [char] '%s' ", yytext);

                                yylval.strval = strdup(yytext);
    	    	    	    	return CH;
    	    	    	    	}

%%

/* ========================= End of LEX ================================ */

///////////////////////////////////////////////////////////////////////////

int     preprocess(char *ptr)

{
    int ret_val = 1;
    struct stat buf;

    // re - initialize preprocessor
    num_lines = 1;

    #if 1
    if(stat(ptr, &buf) < 0)
    	{
    	//printf("Cannot stat file '%s'.\n", ptr);
    	//if(config.debuglevel > 0)
    	//    syslog(LOG_DEBUG, "Cannot stat file %s\n", ptr);
    	return 0;
    	}
    if(S_ISDIR(buf.st_mode))
    	{
    	//printf("Cannot operate on directory '%s'.\n", ptr);
    	if(config.debuglevel > 0)
    	    syslog(LOG_DEBUG, "cannot operate on dir %s\n", ptr);
    	return 0;
    	}
    #endif

    ppfp3 = fopen(ptr, "r");
    if(!ppfp3)
    	{
    	printf("Cannot open file '%s'.\n", ptr);
    	if(config.debuglevel > 0)
    	    syslog(LOG_DEBUG, "Cannot open file %s\n", ptr);
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

    #if 1
    if(stat(outdir, &buf) < 0)
    	{
    	if(mkdir(outdir, 0777) < 0)
    	    {
    	    printf("Cannot create tmp dir: '%s'\n", outdir);
    	    return 0;
    	    }
    	}
    #endif

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
    	syslog(LOG_DEBUG, "pcomp: Cannot create preprocessed file.\n");
    	return 0;
    	}

    int    olderrcnt = config.errorcount;

    if(config.verbose)
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
