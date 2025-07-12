
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

extern  FILE *ppfp, *ppfp2;
static  char    tmp_str3[128];

#define DEBI(lev, str1, var2)               \
    { inf(lev, " { %s '%s' '%s' } ",        \
        str1, var2->name, var2->var); }

//#define YYDEBUG 1
//predebug = 1;

// Global that controls define results
int hasdefine   = 1;

%}

%union {
    Symbol  *sym ;
}

// %debug

/* operators */
%token <sym>   PLUS2 MINUS2 MULT2 DIV2 MOD2 EQ2
%token <sym>   OR2 AND2 XOR2 NOT2 LSHIFT2 RSHIFT2
%token <sym>   VAR2 PAREN12 PAREN22 SEMI2 ENL2 COL2

/* laguage elements */
%token <sym>    CH2 ID2 ID3 SP2 NL2 STR2 COMM2 COMM3 NUM2 MAC2
%token <sym>    IFDEF2 ENDIF2 ELSE2 ELIFDEF2 DEF2 UNDEF2 ERR2 MSG2
%token <sym>    FUNC2 LBRA2 RBRA2 RET2

%type   <sym>   all1
%type   <sym>   all2
%type   <sym>   assn1
%type   <sym>   comm1
%type   <sym>   comm3
%type   <sym>   spnl1
%type   <sym>   semi1
%type   <sym>   decl1
%type   <sym>   func1
%type   <sym>   farg1
%type   <sym>   ret1
%type   <sym>   idd1
%type   <sym>   idd2
%type   <sym>   id2
%type   <sym>   id3
%type   <sym>   msg1

%type   <sym>   define1
%type   <sym>   ifdef1
%type   <sym>   else1
%type   <sym>   endif1

%type   <sym>   expr1
%type   <sym>   expr2
%type   <sym>   expr3
%type   <sym>   expr4
%type   <sym>   expr5

%%

all1:
        |  /* all1 spnl1 {} // enters loop */
        |  all1 all2 {}
;
all2:   comm1
            { DEBI(3, "all2 comm1", $1); }
        | comm3
            { DEBI(3, "all2 comm3", $1); }
        | assn1
            { DEBI(0, "all2 assn1", $1); }
        | decl1
            { DEBI(0, "all2 decl1", $1); }
        | define1
            { DEBI(0, "all2 define1", $1); }
        | ifdef1
            { DEBI(0, "all2 ifdef1", $1); }
        | else1
            { DEBI(0, "all2 else1", $1); }
        | func1
            { DEBI(0, "all2 func1", $1); }
        | msg1
            { DEBI(0, "all2 msg1", $1); }
        /*| spnl1
            { DEBI(0, "all2 spnl", $1); } */
        ;
comm1:  spnl1 COMM2 spnl1
        {  $$=$2; }
;
comm3:  spnl1 COMM3 spnl1
        {  $$=$2;   }
;
idd1:  ID2
       | STR2
;
idd2:  expr1
       | STR2
       | ID2
;
msg1:    MSG2 spnl1 idd2 spnl1
            {
            if(config.testpreyacc > 0)
                { printf(" { msg1: expr1 '%s' } ", $3->var); }
            if(hasdefine)
                fprintf(stderr, "%s", $3->var);
            }
;
define1: DEF2 spnl1 idd1 spnl1
            {
            if(config.testpreyacc > 0)
                {
                printf("{ define1 '%s' } ", $3->var);
                fflush(stdout);
                }
            push_symtab("", $3->var, "", DECL_DEFINE, 0);
            }
         | DEF2 spnl1 idd1 spnl1 idd2 spnl1
            {
            if(config.testpreyacc > 0)
                { printf("{ define1 '%s' arg: %s } ", $3->var, $5->var);
                    fflush(stdout); }
            push_symtab("", $3->var, $5->var, DECL_DEFINE, 0);
            }
;
ifdef1:  IFDEF2 spnl1 idd1 spnl1
        {
        inf(0, "{ ifdef1 '%s' } ", $3->var);
        if(lookup_symtab($3->var, DECL_DEFINE) != NULL)
            {
            inf(0, "{ ifdef1 defined '%s' } ", $3->var);
            hasdefine = 1;
            }
         else
            {
            inf(0, "{ ifdef1 NOT defined '%s' } ", $3->var);
            hasdefine = 0;
            }
        }
;
else1:  spnl1 ELSE2 spnl1
        {
        if(config.testpreyacc > 0)
            { printf("{ else1 '%s'} ", $1->var); }
        hasdefine = !hasdefine;
        }
;
endif1: spnl1 ENDIF2 spnl1
        {
        inf(0, "{ endif1 '%s'} ", $1->var);
        hasdefine = 1;
        }
;
decl1:  spnl1 ID2 spnl1 COL2 spnl1 assn1 semi1
        {
        inf(0, " { decl '%s' '%s' '%s'} ", $2->var, $6->var, $6->res);
        $$ = make_symstr($2->var, $6->var, $6->res, NUM2);
        }
;
farg1:  decl1
        |  farg1 spnl1 decl1
;
func1:  spnl1 FUNC2 spnl1 ID2 spnl1 PAREN12 spnl1 farg1 spnl1 PAREN22
                    spnl1 LBRA2 all1 ret1 RBRA2 spnl1
        {
        inf(0, " { func '%s' } ", $4->var);
        $$ = make_symstr($4->var, "", "", FUNC2);
        }
;
ret1:
        | spnl1 RET2 spnl1 semi1
        |  spnl1 RET2 spnl1 ID2 spnl1 semi1
        |  spnl1 RET2 spnl1 expr1 spnl1 semi1
;
id3:    ID2
    /* id2
        | id3 spnl1 id2 */
;
id2:      ID2
        | NUM2
;

dval1:  spnl1 COL2 spnl1 assn1 spnl1

assn1:  spnl1 ID2 spnl1 EQ2 spnl1 expr1 spnl1 semi1
        {
        inf(0, " { assn1 '%s' } ", $6->var);
        if(hasdefine)
            addemitstr($6->var);
        $$ = make_symstr($2->var, $6->var, $6->res, NUM2);
        }
;
semi1:
        | SEMI2
        | semi1 spnl1 SEMI2
        | semi1 spnl1 nl1
;
sp1: SP2          {  inf(2, "{ SP2 } ");  }
     | sp1 SP2    {  inf(2, "{ SP2 sp1 } ");  }
;
nl1: NL2        {  inf(2, "{ NL2 } ");  }
     | nl1 NL2  {  inf(2, "{ NL2 nl1 } ");  }
;
spnl1:
        | spnl1 sp1    {  inf(2, "{ sp1 } ");  }
        | spnl1 nl1    {  inf(2, "{ nl1 } ");  }
        | spnl1 COMM3  {  inf(3, "{ comm3 } ");  }
;
spnl2:   spnl1 sp1    {  inf(2, "{ sp1 } ");  }
        | spnl1 nl1    {  inf(2, "{ nl1 } ");  }
        | spnl1 COMM3  {  inf(3, "{ comm3 } ");  }
;

// -------------------------------------------------------------
expr1:  expr2
        {
        inf(0, " { expr1: '%s' } ", $1->var);
        }
    |   expr1 spnl1 OR2 spnl1 expr2
        {
        inf(1, " { expr1 '%s' OR '%s'\n", $1->var, $5->var);
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
        inf(1, "{ expr2 '%s'} ", $1->var);
        }
    |   expr2 spnl1 PLUS2 spnl1 expr3
        {
        inf(1, " { expr2 '%s' PLUS '%s } ", $1->var, $5->var);
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
        inf(1, "{ expr3 '%s' } ", $1->var);
        }
    | expr3 spnl1 MULT2 spnl1 expr4
        {
        inf(1, " { expr3 '%s' MUL '%s'\n", $1->var, $5->var);
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
        inf(1, "{ expr4 '%s' } ", $1->var);
        }
    | spnl1 PAREN12 spnl1 expr1 spnl1 PAREN22  spnl1
        {
        inf(0, " { paren: expr4 '%s' } ", $4->var);
        $$ = make_symstr("", $4->var, "", NUM2);
        }
;
expr5:  spnl1 NUM2 spnl1
        {
        inf(1, " { expr5 num '%s' } ", $2->var);
        $$ = make_symstr("", $2->var, "", NUM2);
        }
      |  spnl1 ID2 spnl1
        {
        inf(1, " { expr5 id '%s' } ", $2->var);
        $$ = make_symstr("", $2->var, "", ID2);
        }
;
// -----------------------------------------------------------------------

%%

// EOF
