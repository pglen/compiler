
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
#include <stdarg.h>
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

#define DEBI(lev, str1, var2) \
    { inf(lev, " { %s '%s' '%s' } ", str1, var2->name, var2->var); }

// Global that controls define results
int hasdefine   = 1;
%}

%union {
    Symbol  *sym ;
}

/*
// %verbose
// %define parse.trace  true
// %define parse.lac full
*/

/* operators */
%token <sym>   PLUS2 MINUS2 MULT2 DIV2 MOD2 EQ2
%token <sym>   OR2 AND2 XOR2 NOT2 LSHIFT2 RSHIFT2
%token <sym>   PAREN12 PAREN22 SEMI2 ENL2

/* laguage elements */
%token <sym>    CH2 ID2 ID3 SP2 NL2 STR2 COMM2 COMM3 NUM2 MAC2
%token <sym>    IFDEF2 ENDIF2 ELSE2 ELIFDEF2 DEF2 UNDEF2 ERR2 MSG2

%type   <sym>   all1
%type   <sym>   all2
%type   <sym>   assn1
%type   <sym>   comm1
%type   <sym>   spnl1
%type   <sym>   expr1
%type   <sym>   expr2
%type   <sym>   expr3
%type   <sym>   expr4
%type   <sym>   expr5

%%

all1:  %empty {}
       |  all1 all2 {}
;
all2:   comm1
        { DEBI(0, "all2 comm1", $1); }
        | assn1
        { DEBI(0, "all2 assn1", $1); }
        | spnl1
        { DEBI(0, "all2 spnl1", $1); }
;
comm1:  spnl1 COMM2 spnl1
        {
        $$=$2;
        }
assn1:  spnl1 ID2 spnl1 EQ2 spnl1 expr1 spnl1
        {
        inf(" { assn1 '%s' } ", $6->var);
        if(hasdefine)
            addemitstr($6->var);
        $$ = make_symstr($2->var, $6->var, $6->res, NUM2);
        }
;
// -------------------------------------------------------------
expr1:  expr2
        {
        inf(0, " { expr1: '%s' } ", $1->var);
        }
    |   expr1 spnl1 OR2 spnl1 expr2
        {
        inf(0, "expr1 '%s' OR '%s'\n", $1->var, $5->var);
        int val = str2int($1->var) | str2int($5->var);
        sprintf(tmp_str3, "%d", val);
        $$ = make_symstr("", strdup(tmp_str3), "", NUM2);
        }
    |  expr1 spnl1 XOR2 spnl1 expr2
        {
        int val = str2int($1->var) ^ str2int($5->var);
        sprintf(tmp_str3, "%d", val);
        $$ = make_symstr("", strdup(tmp_str3), "", NUM2);
        }
    |  expr1 spnl1 AND2 spnl1 expr2
        {
        int val = str2int($1->var) & str2int($5->var);
        sprintf(tmp_str3, "%d", val);
        $$ = make_symstr("", strdup(tmp_str3), "", NUM2);
        }
    |  expr1 spnl1 RSHIFT2 spnl1 expr2
        {
        int val = str2int($1->var) >> str2int($5->var);
        sprintf(tmp_str3, "%d", val);
        $$ = make_symstr("", strdup(tmp_str3), "", NUM2);
        }
    |  expr1 spnl1 LSHIFT2 spnl1 expr2
        {
        int val = str2int($1->var) << str2int($5->var);
        sprintf(tmp_str3, "%d", val);
        $$ = make_symstr("", strdup(tmp_str3), "", NUM2);
        }
;
expr2:   expr3
        {
        inf(0, "{ expr2 '%s'} ", $1->var);
        }
    |   expr2 spnl1 PLUS2 spnl1 expr3
        {
        inf(0, " { expr2 '%s' PLUS '%s } ", $1->var, $5->var);
        int val = str2int($1->var) + str2int($5->var);
        sprintf(tmp_str3, "%d", val);
        $$ = make_symstr("", strdup(tmp_str3), "", NUM2);
        }
    |  expr2 spnl1 MINUS2 spnl1 expr3
        {
        int val = str2int($1->var) - str2int($5->var);
        sprintf(tmp_str3, "%d", val);
        $$ = make_symstr("", strdup(tmp_str3), "", NUM2);
        }
;
expr3:  expr4
        {
        inf(0, "{ expr3 '%s' } ", $1->var);
        }
    | expr3 spnl1 MULT2 spnl1 expr4
        {
        inf(0, " { expr3 '%s' MUL '%s'\n", $1->var, $5->var);
        int val = str2int($1->var) * str2int($5->var);
        sprintf(tmp_str3, "%d", val);
        $$ = make_symstr("", strdup(tmp_str3), "", NUM2);
        }
    |  expr3 spnl1 DIV2 spnl1 expr4
        {
        int val = str2int($1->var) / str2int($5->var);
        sprintf(tmp_str3, "%d", val);
        $$ = make_symstr("", strdup(tmp_str3), "", NUM2);
        }
    |  expr3 spnl1 MOD2 spnl1 expr4
        {
        int val = str2int($1->var) % str2int($5->var);
        sprintf(tmp_str3, "%d", val);
        $$ = make_symstr("", strdup(tmp_str3), "", NUM2);
        }
;
expr4:  expr5
        {
        inf(0, "{ expr4 '%s' } ", $1->var);
        }
    | spnl1 PAREN12 spnl1 expr1 spnl1 PAREN22  spnl1
        {
        inf(0, " { paren: expr4 '%s' } ", $4->var);
        $$ = make_symstr("", $4->var, "", NUM2);
        }
;
expr5:  spnl1 NUM2 spnl1
        {
        inf(0, " { expr5 '%s' } ", $2->var);
        $$ = make_symstr("", $2->var, "", NUM2);
        }
;
// -----------------------------------------------------------------------

sp1: SP2        {  inf(2, "{ SP2 } ");  }
     | sp1 SP2  {  inf(2, "{ SP2 sp1 } ");  }
;
nl1: NL2        {  inf(2, "{ NL2 } ");  }
     | nl1 NL2  {  inf(2, "{ NL2 nl1 } ");  }
;
spnl1:  %empty {}
        | sp1   {  inf(2, "{ sp1 } ");  }
        | nl1   {  inf(2, "{ sp1 } ");  }
;
%%

// EOF
