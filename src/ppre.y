
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
%token <sym>   PLUS MINUS MULT DIV MOD
%token <sym>   OR AND XOR NOT LSHIFT RSHIFT
%token <sym>   PAREN1 PAREN2

/* laguage elements */
%token <sym>   CH ID SP NL STR COMMENT NUM MAC

/* pre processor strtements */
%token <sym>  IFDEF ENDIF ELSE ELIFDEF DEF UNDEF ERR MSG

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
%type   <sym>   num1
%type   <sym>   expr1
%type   <sym>   expr2
%type   <sym>   expr3
%type   <sym>   expr4
%type   <sym>   expr5
%type   <sym>   misc
%type   <sym>   strx1

%%

all1:   all2
        {
        if(config.testpreyacc > 0)
            printf(" { all2 '%s' }\n ", (char*)$1);
        }
        | all1 all2
        {
        if(config.testpreyacc > 0)
            printf(" { all1 all2 '%s' '%s'}\n ", (char*)$1, (char*)$2);
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
            printf("{ all1 err1 x'%s'  }\n", (char*)$1);
        }
        | msg1
        {
        if(config.testpreyacc > 0)
            printf("{ all1 msg1 x'%s'  }\n", (char*)$1->var);
        }
        | mac1
        {
        if(config.testpreyacc > 0)
            printf("{ all1 mac1 x'%s'  }\n", (char*)$1);
        }
        | ifdef1
        {
        if(config.testpreyacc > 0)
            printf("{ all1 ifdef1 x'%s'  }\n", (char*)$1);
        }
        | elifdef1
        {
        if(config.testpreyacc > 0)
            printf("{ all1 elifdef1 x'%s'  }\n", (char*)$1);
        }
        | else1
        {
        if(config.testpreyacc > 0)
            printf("{ all1 else1 x'%s'  }\n", (char*)$1);
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
        | num1
        {
        if(config.testpreyacc > 0)
            printf("{ all1: num1 x '%s' }\n", (char*)$1);
        $$ = strdup($1);
        }
/*        | sp1m
        {
        if(config.testpreyacc > 0)
            printf("{ all1: space x '%s' }\n", (char*)$1);
        // Ignore
        }   */

;

define1: sp1b DEF sp1m ID sp1m expr1 sp1m
        { // Ignore
        if(config.testpreyacc > 0)
            printf("{ define1 '%s' '%s' '%s'}\n",
                            (char*)$2, (char*)$4, (char*)$6);
        Symbol  *st2 = push_symtab((char*)$2, (char*)$4, (char*)$6, DECL_DEFINE, 0);
        //$$ = $2;
        }
        | sp1b DEF sp1m ID sp1m
        {
        if(config.testpreyacc > 0)
            printf("{ define1 '%s' '%s'}\n", (char*)$2, (char*)$4);
        Symbol  *st2 = push_symtab((char*)$2, (char*)$4, "",  DECL_DEFINE, 0);
        //$$ = $2;
        }

;

undef1:  sp1b UNDEF sp1m ID sp1m
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
        |  sp1b UNDEF sp1m
        { // Ignore
        }
;

err1:   ERR sp1b STR sp1m
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

strx1:  sp1mb STR sp1mb
            {
            printf("msg1 STR '%s'\n", (char*)$2->var);

            //printf("msg1 STR $$ '%s'\n", $$->var);
            $$=$2;
            }
        | sp1mb NUM sp1mb
            {
            printf("msg1 NUM '%s'\n", $2->res);
            $$=$2;
            }
        | sp1mb STR sp1mb PLUS sp1mb STR sp1mb
            {
            printf("double add' %s' '%s' %p\n", $2->var, $6->var, $$);
            dump_symitem($$);

            char *sum = addstrs($2, $6);
            //Symbol  *st2 = push_symtab((char*)$2, (char*)$6, sum,  STR, 0);
            Symbol  *st2 = make_symtab(sum, sum, sum,  STR, 0);
            $$ = sum;
            }
        | sp1mb STR sp1mb PLUS sp1mb strx1 sp1mb
            {
            printf("cumm add' %s' '%s'\n", (char*)$2, (char*)$6);
            char *sum = addstrs($2, $6);
            Symbol  *st2 = push_symtab((char*)$2, (char*)$6, sum,  STR, 0);
            $$=st2;
            }
;

msg1:   MSG strx1
        {
        printf("msg1: '%s'\n", (char *)$2);
        }
;
        //// Erase quotes
        //if(hasdefine == 2)
        //    {
        //    char *tmp_strx = strdup(((char*)$3) + 1);
        //    char *last = strrchr(tmp_strx, '\"');
        //    if(last)
        //        *last = '\0';
        //    printf("%s\n", tmp_strx);
        //    free(tmp_strx);
        //    }
        //}

mac1:   MAC sp1b ID sp1b STR sp1m
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

ifdef1:  sp1b IFDEF sp1m ID sp1m misc
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

elifdef1:  sp1b ELIFDEF sp1m ID sp1m
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

endif1:  sp1b ENDIF sp1m
        {
        if(config.testpreyacc > 0)
            printf("{ endif1 '%s'}\n", (char*)$2);
        hasdefine = 2;
        }
;

else1:  ELSE
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
        | SP   {}   /* single */
        | NL   {}   /* single */
;

sp1m:   SP          {}  /* single */
        | NL        {}
        | sp1m SP   {}  /* multiple */
        | sp1m NL   {}
;

sp1mb:              {}  /* empty */
        | sp1m      {}  /* multiple */
;


ch2:   ch1
      | ch2 ch1
;

//ops1:   PLUS
//     |  MINUS
//     |  MULT
//     |  DIV
//     |  MOD

ch1:   CH
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
      | SP
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
      | NL
      { if(config.testpreyacc > 0)
            printf("{ NL '%s' }", (char*)$1);
      if(hasdefine == 2)
            fprintf(ppfp2, "%s", (char*)$1);
      }
      | STR
      { if(config.testpreyacc > 0)
            printf("{ STR '%s}' ", (char*)$1);
      if(hasdefine == 2)
            fprintf(ppfp2, "%s", (char*)$1);
      }
      | COMMENT
      { if(config.testpreyacc > 0)
            printf("{ COMMENT '%s}' ", (char*)$1);
      if(hasdefine == 2)
            fprintf(ppfp2, "%s", (char*)$1);
      }
;

id1:   ID
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

num1:   expr1
        {
        if(hasdefine == 2)
            fprintf(ppfp2, "%d", str2int((char*)$1));

        $$ = str2int((char*)$1);
        }
;

expr1:  expr2
    {
    }
    |   expr1 OR expr2
        {
        int val = str2int((char*)$1) | str2int((char*)$3);
        sprintf(tmp_str3, "%d", val);
        $$ = (void*)strdup(tmp_str3);
        }
    |  expr1 XOR expr2
        {
        int val = str2int((char*)$1) ^ str2int((char*)$3);
        sprintf(tmp_str3, "%d", val);
        $$ = (void*)strdup(tmp_str3);
        }
    |  expr1 AND expr2
        {
        int val = str2int((char*)$1) & str2int((char*)$3);
        sprintf(tmp_str3, "%d", val);
        $$ = (void*)strdup(tmp_str3);
        }
    |  expr1 RSHIFT expr2
        {
        int val = str2int((char*)$1) >> str2int((char*)$3);
        sprintf(tmp_str3, "%d", val);
        $$ = (void*)strdup(tmp_str3);
        }
    |  expr1 LSHIFT expr2
        {
        int val = str2int((char*)$1) << str2int((char*)$3);
        sprintf(tmp_str3, "%d", val);
        $$ = (void*)strdup(tmp_str3);
        }
;

expr2:   expr3
    {
    }
    |   expr2 PLUS expr3
        {
        int val = str2int((char*)$1) + str2int((char*)$3);
        sprintf(tmp_str3, "%d", val);
        $$ = (void*)strdup(tmp_str3);
        }
    |  expr2 MINUS expr3
        {
        int val = str2int((char*)$1) - str2int((char*)$3);
        sprintf(tmp_str3, "%d", val);
        $$ = (void*)strdup(tmp_str3);
        }
;

expr3:  expr4
    {
    }
    | expr3 MULT expr4
        {
        int val = str2int((char*)$2) * str2int((char*)$2);
        sprintf(tmp_str3, "%d", val);
        $$ = (void*)strdup(tmp_str3);
        }
    |  expr3 DIV expr4
        {
        int val = str2int((char*)$1) / str2int((char*)$3);
        sprintf(tmp_str3, "%d", val);
        $$ = (void*)strdup(tmp_str3);
        }
    |  expr3 MOD expr4
        {
        int val = str2int((char*)$1) % str2int((char*)$3);
        sprintf(tmp_str3, "%d", val);
        $$ = (void*)strdup(tmp_str3);
        }
;

expr4:  expr5
    {
    }
    | sp1mb PAREN1 sp1mb expr1 sp1mb PAREN2 sp1mb
        {
        if(config.testpreyacc > 0)
            printf("{ paren: expr4 '%s}' ", (char*)$4);

        $$ = $4;
        }
    | sp1m MINUS sp1m expr5
        {
        int val = str2int((char*)$4); val = -val;
        sprintf(tmp_str3, "%d", val);
        if(config.testpreyacc > 0)
            printf("MINUS %d %s\n", val, tmp_str3);
        $$ = (void*)strdup(tmp_str3);
        }
;

expr5:  NUM
        {
         if(config.testpreyacc > 0)
            printf("expr5 NUM %s\n", (char*)$1);
        $$ = $1;
        }

misc:   {}   /* empty */

;

%%


// EOF