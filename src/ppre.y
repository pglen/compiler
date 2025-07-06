
  /* =====[ PPRE ]=========================================================

     Description: PPRE parallel compiler pre processor.

     Revisions:

     REV    DATE            BY             DESCRIPTION
     ----   --------        ----------     -----------------------------------
     0.00   dec/1/2013      Peter Glen     Initial
     0.03   dec/23/2013     Peter Glen     Progress.
     0.04   jan/22/2014     Peter Glen     Added new symtab
     0.05   jan/22/2014     Peter Glen     Constant expressions
     0.05   Fri 04.Jul.2025 Peter Glen     Breakout utils

     ======================================================================= */

%{

#include <sys/stat.h>
#include <syslog.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// We are in a subdir ./parser

#include "../symtab.h"
#include "../xmalloc.h"
#include "../utils.h"

/* define this to see indivdual parsing. Controled by ptions -y -l */

#define YYERROR_VERBOSE

#define DEBUGYYY
#define TESTPCOMP

extern  FILE *ppfp, *ppfp2;
static  char    tmp_str3[128];

int hasdefine = 2;

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
%token <sym>   PAREN12 PAREN22

/* laguage elements */
%token <sym>   CH2 ID2 SP2 NL2 STR2 COMMENT2 NUM2 MAC2

/* pre processor strtements */
%token <sym>  IFDEF2 ENDIF2 ELSE2 ELIFDEF2 DEF2 UNDEF2 ERR2 MSG2

%type   <sym>   all1
%type   <sym>   all2
%type   <sym>   ch1
//%type   <sym>   ops1
%type   <sym>   id1
%type   <sym>   define1
%type   <sym>   err1
%type   <sym>   msg1
%type   <sym>   mac1
%type   <sym>   undef1
%type   <sym>   ifdef1
%type   <sym>   elifdef1
%type   <sym>   endif1
%type   <sym>   sp1b
%type   <sym>   sp1m
%type   <sym>   sp1mb
%type   <sym>   else1
%type   <sym>   misc
%type   <sym>   strx1
%type   <sym>   numx1

%type   <sym>   expr1
%type   <sym>   expr2
%type   <sym>   expr3
%type   <sym>   expr4
%type   <sym>   expr5

%right EQ2
%left AND2 OR2
%left PLUS2 MINUS2
%left MUL2 DIV2
%right UMINUS

%%

all1:   all2
        {
        if(config.testpreyacc > 0)
            printf(" { all2 '%s' }\n ", (char*)$1->var);
        }
        | all1 all2
        {
        if(config.testpreyacc > 0)
            printf(" { all1 all2 '%s' '%s'}\n ", $1->var, $2->var);
        }
;

all2:   define1
        {
        if(config.testpreyacc > 0)
            printf(" { all1 define '%s' }\n ", (char*)$1);
        }
        | undef1
        {
        if(config.testpreyacc > 0)
            printf("{ all1 undef1 x'%s' }\n", (char*)$1);
        }
        | err1
        {
        if(config.testpreyacc > 0)
            printf("{ all1 err1 x'%s' }\n", (char*)$1);
        }
        | msg1
        {
        if(config.testpreyacc > 0)
            printf("{ all1 msg1 '%s' }\n", (char*)$1->var);
        }
        | mac1
        {
        if(config.testpreyacc > 0)
            printf("{ all1 mac1 x'%s' }\n", (char*)$1);
        }
        | ifdef1
        {
        if(config.testpreyacc > 0)
            printf("{ all1 ifdef1 x'%s' }\n", (char*)$1);
        }
        | elifdef1
        {
        if(config.testpreyacc > 0)
            printf("{ all1 elifdef1 x'%s' }\n", (char*)$1);
        }
        | else1
        {
        if(config.testpreyacc > 0)
            printf("{ all1 else1 x'%s' }\n", (char*)$1);
        }
        | endif1
        {
        if(config.testpreyacc > 0)
            printf("{ all1 endif1 x'%s' }\n", (char*)$1);
        }
        | ch2
        {
        //if(config.testpreyacc > 0)
        //    printf("{ all1: ch2 x '%s'  '%s'}\n", (char*)$1);
        }
;

define1: sp1b DEF2 sp1m ID2 sp1m expr1 sp1m
        { // Ignore
        if(config.testpreyacc > 0)
            printf("{ define1 '%s' '%s' '%s'}\n",
                            (char*)$2, (char*)$4, (char*)$6);
        Symbol  *st2 = push_symtab((char*)$2, (char*)$4, (char*)$6, DECL_DEFINE, 0);
        //$$ = $2;
        }
        | sp1b DEF2 sp1m ID2 sp1m
        {
        if(config.testpreyacc > 0)
            printf("{ define1 '%s' '%s'}\n", (char*)$2, (char*)$4);
        Symbol  *st2 = push_symtab((char*)$2, (char*)$4, "",  DECL_DEFINE, 0);
        //$$ = $2;
        }
;

undef1:  sp1b UNDEF2 sp1m ID2 sp1m
        {
        if(config.testpreyacc > 0)
            printf("{ undef1 '%s' '%s'}\n", (char*)$2, (char*)$4);
        Symbol  *st2 = lookup_symtab((char*)$4, DECL_DEFINE);
        if(st2)
            {
            //printf("UNDEF removing %s\n", (char*)$4);
            st2->name = strdup("");
            }
        else
            {
            printf("Preprocess Warning: '%s' not defined, cannot undefine.\n",
                (char *) $4);
            }
        }
        |  sp1b UNDEF2 sp1m
        { // Ignore
        }
;

err1:   ERR2 sp1b STR2 sp1m
    {
        // Erase quotes
        if(hasdefine == 2)
            {
            char *tmp_strx = strdup(((char*)$3) + 1);
            char *last = strrchr(tmp_strx, '\"');
            if(last)
                *last = '\0';
            printf("Error: %s\n", tmp_strx);
            free(tmp_strx);
            }
        exit(1);
    }
;

strx1:  STR2 sp1mb
            {
            //printf("strx1 '%s'\n", $1->var);
            //Symbol *ss = make_symstr("", $1->var, STR2);
            //$$->var = $1->var;
            //$$->var = $1->var;
            //$$ = $1;
            }
        | STR2 sp1mb PLUS2 sp1mb strx1 sp1mb
            {
            //printf("msg add' %s' '%s'\n", (char*)$1->var, (char*)$5->var);
            char *sum = addstrs($1->var, $5->var);
            //printf("sum: '%s'\n", sum);
            Symbol *ss = make_symstr("", sum, STR2);
            $$ = ss;
            }
;
numx1:  expr1 sp1mb
            {
            if(config.testpreyacc > 0)
                printf("{ numx1 expr1 '%s' }\n", $1->var);
            }
;
msg1:   MSG2 sp1mb strx1
            {
            if(config.testpreyacc > 0)
                printf(" { msg1: '%s' } ", $3->var);
            printf("%s\n", $3->var);
            }
        | MSG2 sp1mb numx1
            {
            if(config.testpreyacc > 0)
                printf(" { msg1: numx '%s' } ", $3->var);
            printf("%s\n", $3->var);
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
ifdef1:  sp1b IFDEF2 sp1m ID2 sp1m misc
        {
        if(config.testpreyacc > 0)
            printf("{ ifdef1 '%s' '%s'}\n", (char*)$2, (char*)$4);

        if(lookup_symtab((char*)$4, DECL_DEFINE) != NULL)
            {
            hasdefine = 2;
            }
         else
            {
            hasdefine = 1;
            }
        }
;
elifdef1:  sp1b ELIFDEF2 sp1m ID2 sp1m
        {
        if(config.testpreyacc > 0)
            printf("{ elifdef1 '%s' '%s'}\n", (char*)$2, (char*)$4);

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
endif1:  sp1b ENDIF2 sp1m
        {
        if(config.testpreyacc > 0)
            printf("{ endif1 '%s'}\n", (char*)$2);
        hasdefine = 2;
        }
;
else1:  ELSE2
        {
        if(config.testpreyacc > 0)
            printf("{ else1 '%s'}\n", (char*)$1);

        if(hasdefine == 1)
            hasdefine = 2;
        else
            hasdefine = 1;
        }
;

// Space combos

sp1b:          {}   /* empty */
        | SP2   {}   /* single */
        | NL2   {}   /* single */
;

sp1m:   SP2          {}  /* single */
        | NL2        {}
        | sp1m SP2   {}  /* multiple */
        | sp1m NL2   {}
;

sp1mb:              {}  /* empty */
        | sp1m      {}  /* multiple */
;

ch2:   ch1
      | ch2 ch1
;
ch1:   CH2
      {
      //if(config.testpreyacc > 0)
      //      printf(" { CH '%s' }", (char*)$2);
      if(hasdefine == 2)
            fprintf(ppfp2, "%s", (char*)$1);
      }
      | id1
      { if(config.testpreyacc > 0)
            printf("{ ID '%s' }", (char*)$1);
      if(hasdefine == 2)
            fprintf(ppfp2, "%s", (char*)$1);
      }
      | SP2
      { if(config.testpreyacc > 0)
            printf("{ SP '%s' }", (char*)$1);
      if(hasdefine == 2)
            fprintf(ppfp2, "%s", (char*)$1);
      }
      //| ops1
      //{ if(config.testpreyacc > 0)
      //      printf("{ ops '%s' }", (char*)$1);
      //if(hasdefine == 2)
      //      fprintf(ppfp2, "%s", (char*)$1);
      //}
      | NL2
      { if(config.testpreyacc > 0)
            printf("{ NL '%s' }", (char*)$1);
      if(hasdefine == 2)
            fprintf(ppfp2, "%s", (char*)$1);
      }
      | STR2
      { if(config.testpreyacc > 0)
            printf("{ STR '%s}' ", (char*)$1);
      if(hasdefine == 2)
            fprintf(ppfp2, "%s", (char*)$1);
      }
      | COMMENT2
      { if(config.testpreyacc > 0)
            printf("{ COMMENT '%s}' ", (char*)$1);
      if(hasdefine == 2)
            fprintf(ppfp2, "%s", (char*)$1);
      }
;
id1:   ID2
    {
    if(config.testpreyacc > 0)
            printf("{ id1 : ID '%s}' ", (char*)$1);
    Symbol *sp = lookup_symtab((char*)$1, DECL_MACRO);
    if(sp)
        {
        printf("Macro expansion '%s to %s'\n",  sp->name, sp->var);
        $$ = (void*)strdup(sp->var);
        }
    else
        $$ = $1;
    }
;
expr1:  expr2
        {
        //if(config.testpreyacc > 0)
        //    printf("{ expr1 '%s' } '\n", $1->var);
        }
    |   expr1 sp1mb OR2 sp1mb expr2
        {
        if(config.testpreyacc > 0)
            printf("expr1 '%s' OR '%s'\n", $1->var, $5->var);
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
        //if(config.testpreyacc > 0)
        //    printf("{ expr2 '%s'} \n", $1->var);
        }
    |   expr2 sp1mb PLUS2 sp1mb expr3
        {
        //if(config.testpreyacc > 0)
        //    printf("{ expr2 '%s' PLUS '%s } '\n", $1->var, $5->var);
        int val = str2int($1->var) + str2int($5->var);
        sprintf(tmp_str3, "%d", val);
        $$ = make_symstr("", strdup(tmp_str3), NUM2);
        }
    |  expr2  sp1mb MINUS2 sp1mb expr3
        {
        //if(config.testpreyacc > 0)
        //    printf("{ expr2 '%s' MINUS '%s } '\n", $1->var, $5->var);
        int val = str2int($1->var) - str2int($5->var);
        sprintf(tmp_str3, "%d", val);
        $$ = make_symstr("", strdup(tmp_str3), NUM2);
        }
;
expr3:  expr4
    {
    //if(config.testpreyacc > 0)
    //    printf("{ expr3 '%s' } \n", $1->var);
    $$=$1;
    }
    | expr3 sp1mb MULT2 sp1mb expr4
        {
        //if(config.testpreyacc > 0)
        //    printf("expr3 '%s' MUL '%s'\n", $1->var, $5->var);
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
    //if(config.testpreyacc > 0)
    //    printf("{ expr4 '%s' } \n", $1->var);
    }
    | sp1mb PAREN12 sp1mb expr1 sp1mb PAREN22 sp1mb
        {
        //if(config.testpreyacc > 0)
        //    printf("{ paren: expr4 '%s}' ", (char*)$4);
        $$ = make_symstr("", $4->var, NUM2);
        //$$ = $4;
        }
    | sp1m MINUS2 sp1mb expr5
        {
        int val = str2int($4->var);
        sprintf(tmp_str3, "%d", -val);
        $$ = make_symstr("", strdup(tmp_str3), NUM2);
        }
;
expr5:  NUM2
        {
        //if(config.testpreyacc > 0)
        //    printf("{ expr5 '%s' } \n", $1->var);
        $$ = make_symstr("", $1->var, NUM2);
        //$$ = $1;
        }
;
misc:   {}   /* empty */

;

%%

// EOF