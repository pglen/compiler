
  /* =====[ PPRE ]=========================================================

     Description: PPRE parallel compiler pre processor.

     Revisions:

     REV    DATE                BY             DESCRIPTION
     ----   --------            ----------     ----------------------------
     0.00   dec/1/2013          Peter Glen     Initial
     0.03   dec/23/2013         Peter Glen     Progress.
     0.04   jan/22/2014         Peter Glen     Added new symtab
     0.05   jan/22/2014         Peter Glen     Constant expressions
     0.05   Fri 04.Jul.2025     Peter Glen     Breakout utils

     ======================================================================= */
%{

#include <sys/stat.h>
#include <syslog.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>    /* for isatty */

// We are in a subdir ./parser
#include "../symtab.h"
#include "../xmalloc.h"
#include "../utils.h"

/* define this to see indivdual parsing. Controled by options -y -l */
#define YYERROR_VERBOSE

#define DEBUGYYY
#define TESTPCOMP

extern  FILE *ppfp, *ppfp2;
static  char    tmp_str3[128];

// Global that controls define results
int hasdefine   = 1;

%}

//%union {                                                /* stack object type */
//    int     val ;                                            /* actual value */
//    long    lngval ;                                         /* actual value */
//    float   fltlval;                                         /* actual value */
//    double  dblval ;                                         /* actual value */
//    char    *strval;                                            /* str value */
//    Symbol  *sym ;                                       /* symbol table ptr */
//}

%union {
    //char    *strval;
    Symbol  *sym ;
}

/* operators */
%token <sym>   PLUS2 MINUS2 MULT2 DIV2 MOD2
%token <sym>   OR2 AND2 XOR2 NOT2 LSHIFT2 RSHIFT2
%token <sym>   PAREN12 PAREN22 SEMI2 ENL2

/* laguage elements */
%token <sym>   CH2 ID2 ID3 SP2 NL2 STR2 COMMENT2 NUM2 MAC2

/* pre processor strtements */
%token <sym>  IFDEF2 ENDIF2 ELSE2 ELIFDEF2 DEF2 UNDEF2 ERR2 MSG2

%type   <sym>   all1
%type   <sym>   all2
%type   <sym>   define1
%type   <sym>   err1
%type   <sym>   msg1
%type   <sym>   nl1
%type   <sym>   mac1
%type   <sym>   undef1
%type   <sym>   ifdef1
%type   <sym>   elifdef1
%type   <sym>   endif1
%type   <sym>   sp1
%type   <sym>   sp1b
%type   <sym>   sp1m
%type   <sym>   sp1mb
%type   <sym>   else1
%type   <sym>   strx1
%type   <sym>   idd1
%type   <sym>   expr1
%type   <sym>   expr2
%type   <sym>   expr3
%type   <sym>   expr4
%type   <sym>   expr5
%type   <sym>   semib
%type   <sym>   semibm

%%

all1:   {
        if(config.testpreyacc > 3)
            {
            printf(" { all1 all2 root none } "); fflush(stdout);
            }
        }
       | all1 all2
        {
        if(config.testpreyacc > 3)
            {
            printf(" { all1 all2 root '%s'} ", $2->var); fflush(stdout);
            }
        }
;

all2:   define1
            {
            if(config.testpreyacc > 1)
                { printf(" { all2 define '%s' } ", $1->var); fflush(stdout); }
            }
        | msg1
            {
            if(config.testpreyacc > 1)
                { printf("{ all2 msg1 '%s' } ", $1->var); fflush(stdout); }
            //to_prev_state();
            }
        | undef1
            {
            if(config.testpreyacc > 1)
                { printf("{ all2 undef1 x'%s' } ", $1->var); fflush(stdout); }
            }
        | err1
            {
            if(config.testpreyacc > 1)
                { printf("{ all2 err1 x'%s' } ", $1->var); fflush(stdout); }
            }
        | nl1
            {
            if(config.testpreyacc > 1)
                { printf("{ all2 nl1 '%s' } ", $1->var); fflush(stdout); }
            }
        | mac1
            {
            if(config.testpreyacc > 1)
                { printf("{ all2 mac1 x'%s' } ", $1->var); fflush(stdout); }
            }
        | ifdef1
            {
            if(config.testpreyacc > 1)
                { printf("{ all2 ifdef1 x'%s' } ", (char*)$1->var); fflush(stdout); }
            }
        | elifdef1
            {
            if(config.testpreyacc > 1)
                { printf("{ all2 elifdef1 x'%s' } ", (char*)$1->var); fflush(stdout); }
            }
        | else1
            {
            if(config.testpreyacc > 1)
                { printf("{ all2 else1 x'%s' } ", (char*)$1->var); fflush(stdout); }
            }
        | endif1
            {
            if(config.testpreyacc > 1)
                { printf("{ all2 endif1 x'%s' } ", (char*)$1->var); fflush(stdout); }
            }
        | COMMENT2
            {
            if(config.testpreyacc > 1)
                { printf("{ all2 comment '%s' } ", (char*)$1->var); fflush(stdout); }
            }
        | sp1mb
            {
            if(config.testpreyacc > 1)
                { printf("{ all2 nl / blank '%s' } ", (char*)$1->var); fflush(stdout); }
            }
        | ID3
            {
            if(config.testpreyacc > 0)
                {   printf("{ all2 id3 '%s' } ", $1->var);
                    fflush(stdout);
                // Find in symtab
                Symbol  *st2 = lookup_symtab($1->var, DECL_DEFINE);
                if(st2)
                    {
                    printf("added %s=%s", st2->var, st2->res);
                    addemitstr(st2->res);
                    }
                else
                    {
                    printf("added: '%s'", $1->var);
                    addemitstr($1->var);
                    }
                }
            }

;
idd1:   strx1       { if(config.testpreyacc > 1)
                        printf("{ idd1 strx1 } ");fflush(stdout); }
        | expr1     { if(config.testpreyacc > 1)
                        printf("{ idd1 expr1 } ");fflush(stdout); }
;
define1: DEF2 sp1mb idd1 sp1mb semibm
            {
            if(config.testpreyacc > 0)
                {
                printf("{ define1 '%s' } ", $3->var);
                fflush(stdout);
                }
            if(hasdefine)
                push_symtab("", $3->var, "", DECL_DEFINE, 0);
            }
        | DEF2 sp1mb idd1 sp1mb idd1 sp1mb semibm
            {
            if(config.testpreyacc > 0)
                { printf("{ define1 '%s' arg: %s } ", $3->var, $5->var);
                    fflush(stdout); }
            if(hasdefine)
                push_symtab("", $3->var, $5->var, DECL_DEFINE, 0);
            }
;
undef1:  UNDEF2 sp1mb idd1 sp1mb semibm
        {
        if(config.testpreyacc > 0)
            { printf("{ undef1 '%s' } ", $3->var); fflush(stdout); }
        Symbol  *st2 = lookup_symtab($3->var, DECL_DEFINE);
        if(st2)
            {
            printf(" { UNDEF removing %s } ", $3->var); fflush(stdout);
            dump_symtab();
            delitem_symtab(st2);
            dump_symtab();
            }
        else
            {
            fprintf(stderr,
                "Preprocess Warning: %%undef '%s' is not defined\n",
                    $3->var); fflush(stdout);
            }
        }
        |  sp1b UNDEF2 sp1m
        { // Ignore
        }
;
err1:   ERR2 sp1mb idd1 sp1mb semibm
            {
            printf(" { err1 %s } ", $3->var); fflush(stdout);
            if(hasdefine == 1)
                {
                if(isatty(2) > 0)
                    fprintf(stderr, "\033[31;1mError Exit:\033[0m ");
                else
                    fprintf(stderr, "Error exit: ");

                fprintf(stderr, "%s\n", $3->var);

                exit(1);
                }
            }
;
strx1:  STR2 sp1mb
            {
            }
        | ID2 sp1mb
            {
            }
        | STR2 sp1mb PLUS2 sp1mb strx1 sp1mb
            {
            if(config.testpreyacc > 0)
                { printf("msg str add' %s' '%s'\n", (char*)$1->var, (char*)$5->var); fflush(stdout); }
            char *sum = addstrs($1->var, $5->var);
            //printf("sum: '%s'\n", sum); fflush(stdout);
            Symbol *ss = make_symstr("", sum, STR2);
            $$ = ss;
            }
        | STR2 sp1mb PLUS2 sp1mb expr1 sp1mb
            {
            if(config.testpreyacc > 2)
                { printf("strx1 STR + expr1' %s' '%s'\n", (char*)$1->var, (char*)$5->var); fflush(stdout); fflush(stdout); fflush(stdout); fflush(stdout); fflush(stdout); }
            char *sum = addstrs($1->var, $5->var);
            Symbol *ss = make_symstr("", sum, STR2);
            $$ = ss;
            }
       | expr1 sp1mb PLUS2 sp1mb STR2 sp1mb
            {
            if(config.testpreyacc > 2)
                { printf("strx1 expr1 + str2 '%s' '%s'\n", (char*)$1->var, (char*)$5->var); }
            char *sum = addstrs($1->var, $5->var);
            Symbol *ss = make_symstr("", sum, STR2);
            $$ = ss;
            }
      | STR2 sp1mb PLUS2 sp1mb STR2
            {
            if(config.testpreyacc > 2)
                { printf("strx1 expr1 + str2 '%s' '%s'\n", (char*)$1->var, (char*)$5->var); }
            char *sum = addstrs($1->var, $5->var);
            Symbol *ss = make_symstr("", sum, STR2);
            $$ = ss;
            }
;
semib:
        | NL2
        | sp1mb NL2
        | SEMI2
        | sp1mb SEMI2
;
semibm: semib   {
                if(config.testpreyacc > 0)
                    printf(" { semibm '%s' } ", $1->var); fflush(stdout);
                to_prev_state();
                }
;
nl1:     ENL2 sp1mb semibm
            {
            if(hasdefine == 1)
                fprintf(stderr, "\n");
            //to_prev_state();
            }
;
msg1:    MSG2 sp1mb idd1 sp1mb semibm
            {
            if(config.testpreyacc > 0)
                { printf(" { msg1: expr1 '%s' } ", $3->var); }
            if(hasdefine)
                fprintf(stderr, "%s", $3->var);
            }
;
mac1:   MAC2 sp1b ID2 sp1b STR2 sp1m
        {
        // Erase quotes
        char *tmp_strx = strdup(((char*)$5) + 1);
        char *last = strrchr(tmp_strx, '\"');
        if(last)
            *last = '\0';

        Symbol  *st = lookup_symtab((char*)$3, DECL_MACRO);
        if(st)   // replace
            {
            if(st->var) free(st->var);
            st->var = strdup(tmp_strx);
            }
        else
            push_symtab((char*)$3, tmp_strx, "",  DECL_MACRO, 0);

        free(tmp_strx);
        }
;
ifdef1:  IFDEF2 sp1mb idd1 sp1mb semibm
        {
        //to_emit_state();
        //emitprog = 0;
        if(config.testpreyacc > 0)
            { printf("{ ifdef1 '%s' } ", $3->var); }
        if(lookup_symtab($3->var, DECL_DEFINE) != NULL)
            {
            if(config.testpreyacc > 0)
              { printf("{ ifdef1 defined '%s' } ", $3->var); }
            hasdefine = 1;
            }
         else
            {
            if(config.testpreyacc > 0)
              { printf("{ ifdef1 NOT defined '%s' } ", $3->var); }
            //to_init_state();
            hasdefine = 0;
            }
        printf("Has define: %d\n", hasdefine);
        }
;
elifdef1:  sp1b ELIFDEF2 sp1m ID2 sp1m
        {
        if(config.testpreyacc > 0)
            { printf("{ elifdef1 '%s' '%s'} ", (char*)$2, (char*)$4); }

        if(hasdefine == 1)
            {
            if(lookup_symtab((char*)$4, DECL_DEFINE) != NULL)
                {
                hasdefine = 2;
                }
            }
        else
            {
            hasdefine = 0;
            }
        }
;
endif1:  ENDIF2 sp1mb semibm
        {
        if(config.testpreyacc > 0)
            { printf("{ endif1 '%s'} ", (char*)$1->var); }
        hasdefine = 1;
        }
;
else1:  ELSE2 sp1mb semibm
        {
        if(config.testpreyacc > 0)
            { printf("{ else1 '%s'} ", (char*)$1); }
        hasdefine = !hasdefine;
        }
;
// Space combos
sp1:      SP2   {}   /* single */
        | NL2   {}   /* single */
;
sp1b:           {}   /* empty */
        | sp1   {}
;
sp1m:     SP2        {}  /* single */
        | sp1m SP2   {}  /* multiple */
;
sp1mb:      {  /* empty */
            //printf(" spb ");
            //$$ = make_symstr("", " ", STR2);
            }
        | sp1m  /* multiple */
            {
            //printf(" spm ");
            //$$ = make_symstr("", " ", STR2);
            }
;
expr1:  expr2
        {
        //printf(" { expr1: %s } ", $1->var);
        }
    |   expr1 sp1mb OR2 sp1mb expr2
        {
        if(config.testpreyacc > 1)
            { printf("expr1 '%s' OR '%s'\n", $1->var, $5->var); }
        int val = str2int($1->var) | str2int($5->var);
        sprintf(tmp_str3, "%d", val);
        $$ = make_symstr("", strdup(tmp_str3), NUM2);
        }
    |  expr1 sp1mb XOR2 sp1mb expr2
        {
        int val = str2int($1->var) ^ str2int($5->var);
        sprintf(tmp_str3, "%d", val);
        $$ = make_symstr("", strdup(tmp_str3), NUM2);
        }
    |  expr1 sp1mb AND2 sp1mb expr2
        {
        int val = str2int($1->var) & str2int($5->var);
        sprintf(tmp_str3, "%d", val);
        $$ = make_symstr("", strdup(tmp_str3), NUM2);
        }
    |  expr1 sp1mb RSHIFT2 sp1mb expr2
        {
        int val = str2int($1->var) >> str2int($5->var);
        sprintf(tmp_str3, "%d", val);
        $$ = make_symstr("", strdup(tmp_str3), NUM2);
        }
    |  expr1 sp1mb LSHIFT2 sp1mb expr2
        {
        int val = str2int($1->var) << str2int($5->var);
        sprintf(tmp_str3, "%d", val);
        $$ = make_symstr("", strdup(tmp_str3), NUM2);
        }
;
expr2:   expr3
        {
        if(config.testpreyacc > 0)
            { printf("{ expr2 '%s'} ", $1->var); }
        }
    |   expr2 sp1mb PLUS2 sp1mb expr3
        {
        if(config.testpreyacc > 0)
           { printf(" { expr2 '%s' PLUS '%s } ", $1->var, $5->var); }
        int val = str2int($1->var) + str2int($5->var);
        sprintf(tmp_str3, "%d", val);
        $$ = make_symstr("", strdup(tmp_str3), NUM2);
        }
    |  expr2 sp1mb MINUS2 sp1mb expr3
        {
        int val = str2int($1->var) - str2int($5->var);
        sprintf(tmp_str3, "%d", val);
        $$ = make_symstr("", strdup(tmp_str3), NUM2);
        }
;
expr3:  expr4
    {
    if(config.testpreyacc > 0)
        { printf("{ expr3 '%s' } ", $1->var); }
    }
    | expr3 sp1mb MULT2 sp1mb expr4
        {
        //if(config.testpreyacc > 1)
        //  {  printf("expr3 '%s' MUL '%s'\n", $1->var, $5->var); }
        int val = str2int($1->var) * str2int($5->var);
        sprintf(tmp_str3, "%d", val);
        $$ = make_symstr("", strdup(tmp_str3), NUM2);
        }
    |  expr3 sp1mb DIV2 sp1mb expr4
        {
        int val = str2int($1->var) / str2int($5->var);
        sprintf(tmp_str3, "%d", val);
        $$ = make_symstr("", strdup(tmp_str3), NUM2);
        }
    |  expr3 sp1mb MOD2 sp1mb expr4
        {
        int val = str2int($1->var) % str2int($5->var);
        sprintf(tmp_str3, "%d", val);
        $$ = make_symstr("", strdup(tmp_str3), NUM2);
        }
;
expr4:  expr5
    {
    }
    |    sp1mb PAREN12 sp1mb expr1 sp1mb PAREN22  sp1mb
        {
        if(config.testpreyacc > 0)
            { printf(" { paren: expr4 '%s' } ", $4->var); }
        $$ = make_symstr("", $4->var, NUM2);
        }
;
expr5:  sp1mb NUM2 sp1mb
        {
        if(config.testpreyacc > 0)
            { printf(" { expr5 '%s' } ", $2->var); }
        $$ = make_symstr("", $2->var, NUM2);
        }
;

%%

// EOF