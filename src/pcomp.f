%{

#include "limits.h"

/* This lexer and parser assumes that int is same size as pointer */

#include "../pcomp.h"
#include "../symtab.h"
#include "../emalloc.h"

static	char tmp_str2[2 * MAX_PATHLEN];
static  FILE    *infp, *ppfp;
FILE    *asmfp;

int num_lines = 1, num_chars = 0, backslash = 0, prog = 0;

#define YY_INPUT(buf,result,max_size) \
               { \
               int c = getc(infp); \
               result = (c == EOF) ? YY_NULL : (buf[0] = c, 1); \
               }

void conferror(const char *str)

{
    static int count = 0;
    printf("%s  Line: %d  Near '%s'\n", str, num_lines, yytext); count++;

    if(count > 5)
        exit(0);
}

#define DEBUGLEX

int conflex();

#include "pcomp.yacc.c"

%}


%x STR2
%option noyywrap

FN   [\~_a-zA-Z]
FNN  [\~_a-zA-Z0-9]

%%

\/\/\/\/.*\n                       { /* comment */
								num_lines++;
	#ifdef DEBUGLEX
                                if(config.testflex)
                                    printf("[double slash comment] '%s", yytext);
	#endif
                                yylval.strval = strdup(yytext);
								return COMMENT2;
								}

\/\/\/.*\n                       { /* comment */
								num_lines++;
	#ifdef DEBUGLEX
                                if(config.testflex)
                                    printf("[slash comment2] '%s", yytext);
	#endif
                                yylval.strval = strdup(yytext);
								return COMMENT2;
								}



\/\/.*\n                       { /* comment */
								num_lines++;
	#ifdef DEBUGLEX
                                if(config.testflex)
                                    printf("[slash comment] '%s", yytext);
	#endif
                                yylval.strval = strdup(yytext);
								return COMMENT;
								}

##.*\n                           {  /* double comment */
								num_lines++;
	#ifdef DEBUGLEX
                                if(config.testflex)
                                    printf("[double comment] '%s", yytext);
	#endif
                                yylval.strval = strdup(yytext);
								return COMMENT2;
								}

#.*\n                           {  /* comment */
								num_lines++;
	#ifdef DEBUGLEX
                                if(config.testflex)
                                    printf("[comment] '%s", yytext);
	#endif
                                yylval.strval = strdup(yytext);
								return COMMENT;
								}

^\r\n                             /* empty line */ {
								if(config.testflex)
                                    printf("[empty line]\r\n");
								num_lines++;
								}

^\r                             /* empty line */ {
								if(config.testflex)
                                    printf("[empty line \\r]\r\n");
								num_lines++;
								}

^\n                             /* empty line */ {
								if(config.testflex)
                                    printf("[empty line \\n]\r\n");
								num_lines++;
								}


	/* commands: ------------------------------------------------------- */

  /*
\<class\>                           {
	#ifdef DEBUGLEX
                                if(config.testflex)
                                    printf("<CLASS> ");
	#endif
                                yylval.strval = strdup(yytext);
                                return(CLASS);
                                }
\<ssalc\>                           {
	#ifdef DEBUGLEX
                                if(config.testflex)
                                    printf("<SSALC> ");
	#endif
                                yylval.strval = strdup(yytext); return(SSALC);
                                }
    /* ----------------------------------------------------------------- */
\<dir\>                            {
	#ifdef DEBUGLEX
                                if(config.testflex)
	                                printf("<DIR> ");
	#endif
                                yylval.strval = strdup(yytext); return(DIR);
                                }
\<rid\>                         {
	#ifdef DEBUGLEX
                                if(config.testflex)
                                printf("<RID> ");
	#endif
                                yylval.strval = strdup(yytext); return(RID);
                                }

function                        {
	#ifdef DEBUGLEX
                                if(config.testflex)
                                printf("[Function] ");
	#endif
                                yylval.strval = strdup(yytext); return(FUNC);
                                }

begin                          {
	#ifdef DEBUGLEX
                                if(config.testflex)
                                printf("lex: begin ");
	#endif

                                yylval.strval = strdup(yytext); return(BEG);
                                }

end                             {
	#ifdef DEBUGLEX
                                if(config.testflex)
                                printf("lex: end ");
	#endif

                                yylval.strval = strdup(yytext); return(END);
                                }

    /* ----------------------------------------------------------------- */

debug                          {
	#ifdef DEBUGLEX
                                if(config.testflex)
                                printf("<DBG> ");
	#endif
                                yylval.strval = strdup(yytext); return(DBG);
                                }

return                         {
	#ifdef DEBUGLEX
                                if(config.testflex)
                                printf("[RET] ");
	#endif
                                yylval.strval = strdup(yytext); return(RET);
                                }

\|\|                             {
	#ifdef DEBUGLEX
                                if(config.testflex)
                                printf("<OR> ");
	#endif
                                yylval.strval = strdup(yytext); return(OR);
                                }

\!\!                            {
	#ifdef DEBUGLEX
                                if(config.testflex)
                                printf("<LNOT> ");
	#endif
                                yylval.strval = strdup(yytext); return(LNOT);
                                }

\&\&                             {
	#ifdef DEBUGLEX
                                if(config.testflex)
                                printf("<AND> ");
	#endif
                                yylval.strval = strdup(yytext); return(AND);
                                }

\=\=                             {
	#ifdef DEBUGLEX
                                if(config.testflex)
                                printf("<EQEQ> ");
	#endif
                                yylval.strval = strdup(yytext); return(EQEQ);
                                }

!\=                            {
	#ifdef DEBUGLEX
                                if(config.testflex)
                                printf("<NEQ> ");
	#endif
                                yylval.strval = strdup(yytext); return(NEQ);
                                }

\^\^                             {
	#ifdef DEBUGLEX
                                if(config.testflex)
                                printf("<XOR> ");
	#endif
                                yylval.strval = strdup(yytext); return(XOR);
                                }

\>\=                             {
	#ifdef DEBUGLEX
                                if(config.testflex)
                                printf("<GEQ> ");
	#endif
                                yylval.strval = strdup(yytext); return(GEQ);
                                }


\<\=                            {
	#ifdef DEBUGLEX
                                if(config.testflex)
                                printf("<SEQ> ");
	#endif
                                yylval.strval = strdup(yytext); return(SEQ);
                                }


\<\<\<                          {
	#ifdef DEBUGLEX
                                if(config.testflex)
                                printf("<ROL> ");
	#endif
                                yylval.strval = strdup(yytext); return(ROL);
                                }

\>\>\>                          {
	#ifdef DEBUGLEX
                                if(config.testflex)
                                printf("<ROR> ");
	#endif
                                yylval.strval = strdup(yytext); return(ROR);
                                }


if                             {
	#ifdef DEBUGLEX
                                if(config.testflex)
                                printf("<IF> ");
	#endif
                                yylval.strval = strdup(yytext); return(IF);
                                }

else                             {
	#ifdef DEBUGLEX
                                if(config.testflex)
                                printf("<ELSE> ");
	#endif
                                yylval.strval = strdup(yytext); return(ELSE);
                                }

log                             {
	#ifdef DEBUGLEX
                                if(config.testflex)
                                printf("<LOG> ");
	#endif
                                yylval.strval = strdup(yytext); return(LOG);
                                }
0y[0-1]+                        {
	#ifdef DEBUGLEX
                                if(config.testflex)
                                	printf("[NUM] '%s' ", yytext);
	#endif
                                return(NUM);
                                }
0x[0-9a-fA-f]+                  {            /* hexadecimal */
	#ifdef DEBUGLEX
                                if(config.testflex)
                                	printf("[ID] '%s' ", (char*)yytext);
	#endif
                                yylval.strval = strdup(yytext); return(ID);
                                }
[0-9]+                          {
	#ifdef DEBUGLEX
                                if(config.testflex)
 	                               printf("[NUM] '%s' ", (char*)yytext);
	#endif
                                yylval.strval = strdup(yytext); return(NUM);
                                }
{FN}{FNN}*                      {             /* Identity */
	#ifdef DEBUGLEX
                                if(config.testflex)
                                	printf("[ID] '%s' ", (char*)yytext);
	#endif
                                yylval.strval = strdup(yytext); return(ID);
                                }

[ \t\r\n]+                        {          /* white space */
	#ifdef DEBUGLEX
                                if(config.testflex)
                                	printf("[SP] '%d' len=%ld ",
													yytext[0], strlen(yytext));
	#endif
                                yylval.strval = strdup(yytext);

								if(yytext[0] == '\r')
									num_lines++;

								//return(SP);
                                }

\"                              {              /* begin quote */
                                BEGIN(STR2);
	#ifdef DEBUGLEX
                                if(config.testflex)
                                    printf(" str<<<");
	#endif
                                prog = 0; backslash  = 0;
							   	tmp_str2[prog++] = yytext[0];

                                backslash  = 0;
                                }

.                               {
                                if(config.testflex)
                                    printf("[CHAR] '%c' ", yytext[0]);

                                return(yytext[0]);
                                }

<STR2>\\                        {
								//printf("\\");
								backslash++;
								}

<STR2>\"                        {  			/* end quote */
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

<STR2>.                         {
                                backslash  = 0;

                                if(config.testflex)
                                    printf("%s", yytext);

								tmp_str2[prog++] = yytext[0];
                                }

%%

/* ========================= End of LEX ================================ */

#include <stdio.h>     /* for printf */
#include <stdlib.h>    /* for exit */
#include <getopt.h>

#include "../codegen.h"

char outdir[MAX_VARLEN];

///////////////////////////////////////////////////////////////////////////
//

int     compile(char *ptr)

{
	int ret_val = 1;
	struct stat buf;

    if(config.verbose > 0)
        printf("Compile: '%s'\n", ptr);

	// re - initialize compiler for preprocess
    // ??

	if(stat(ptr, &buf) < 0)
		{
		printf("Cannot stat file '%s'.\n", ptr);
		//if(config.debuglevel > 0)
		//	syslog(LOG_DEBUG, "log: cannot stat file %s\n", ptr);
		return 0;
		}
	if(S_ISDIR(buf.st_mode))
		{
		printf("Cannot operate on directory '%s'.\n", ptr);
		//if(config.debuglevel > 0)
		//	syslog(LOG_DEBUG, "cannot operate on dir %s\n", ptr);
		return 0;
		}
	infp = fopen(ppfile2, "r");
	if(!infp)
		{
		printf("Cannot open file '%s'.\n", ptr);
		//if(config.debuglevel > 0)
		//	syslog(LOG_DEBUG, "Cannot open file %s\n", ptr);
		return 0;
		}
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
	strcat(outdir, "/");
    strcat(usetmp, outdir);
	if(stat(usetmp, &buf) < 0)
		{
		if(mkdir(usetmp, 0777) < 0)
			{
			printf("Cannot create tmp dir: '%s'\n", usetmp);
			return 0;
			}
		}
	char asmfile[MAX_VARLEN];
	strcpy(asmfile, ptr);
	char *last = strrchr(asmfile, '/');
	if (last != NULL)
		{
		strcpy(asmfile, last + 1);
		}
	char asmfile2[MAX_VARLEN];
	strcpy(asmfile2, usetmp);
	strcat(asmfile2, asmfile);
	char *last3 = strrchr(asmfile2, '.');
	if (last3 != NULL)
		{
		*last3 = '\0';
		strcat(asmfile2, ".asm");
		if(config.verbose > 1)
            printf("asm2: '%s'\n", asmfile2);
		}
	char objfile2[MAX_VARLEN];
	strcpy(objfile2, usetmp);
	strcat(objfile2, asmfile);
	char *last4 = strrchr(objfile2, '.');
	if (last4 != NULL)
		{
		*last4 = '\0';
		strcat(objfile2, ".o");
		if(config.verbose > 2)
    		printf("obj2: '%s'\n", objfile2);
		}

    char outfile2[MAX_VARLEN];
	//strcpy(outfile2, usetmp);
	//strcat(outfile2, outfile);
	strcpy(outfile2, outfile);
	char *last5 = strrchr(outfile2, '.');
    asmfp = fopen(asmfile2, "w");
	if(!asmfp)
		{
		printf("Cannot create file '%s'.\n", asmfile);
		syslog(LOG_DEBUG, "pcomp: Cannot create asm file.\n");
		return 0;
		}
	int	olderrcnt = config.errorcount;
	if(!config.noprog)
		printf ("Compiling: '%s' ", ptr);

	struct timespec ts;
	clock_gettime(CLOCK_REALTIME, &ts);
    confparse();
	struct timespec ts2;
	//sleep(2); // test time measurement
	clock_gettime(CLOCK_REALTIME, &ts2);
    fclose(infp);

	int dts, dtu; calc_usec_diff(&ts, &ts2, &dts, &dtu);
	int ret = getretcode();
	if(config.verbose)
		{
		if(ret == 0 && (olderrcnt == config.errorcount))
			printf ("OK %d sec %d usec\n", dts, dtu);
		else
			printf ("Compiled: '%s' ERR %d sec %d usec\n", ptr, dts, dtu);
		}
    if(!config.noprog)
		printf ("OK\n");

	config.errorcount += ret;
	if(!config.showcomm)
		{
		//printf("\n");
		if(config.dumpsymtab)
			{
			//dump_symtab();
			//printf("\n");
			}
		gen_code();
		//printf("\n");
		}
	fclose(asmfp);

	if(!config.noassembly)
		{
		//sprintf(tmp_str, "nasm -felf64 %s > /dev/null", asmfile2);
        sprintf(tmp_str, "nasm -felf64 %s ", asmfile2);
        if(config.verbose)
            printf("Assembly: '%s'\n", tmp_str);

		int ret = system(tmp_str);
		if(ret != 0)
			{
			printf("Assembly failed.\n\n");
			ret_val = 0;
			}
		}
	if(!config.nolink)
		{
		//sprintf(tmp_str, "gcc -no-pie %s -o %s > /dev/null",
        sprintf(tmp_str, "gcc -no-pie %s -o %s ",
                                objfile2, outfile2);
        if(config.verbose)
            printf("Linking: '%s'\n", tmp_str);
		int ret = system(tmp_str);
		if(ret != 0)
			{
			printf("Linking failed.\n\n");
			ret_val = 0;
			}
		}
	if(config.catsrc)
		{
		printf("Displaying source file:\n\n");
		sprintf(tmp_str, "cat %s\n", asmfile2);
		int ret = system(tmp_str);
		}
    return ret_val;
}

// EOF
