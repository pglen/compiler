/*--------------------------------------------------------------------------
**  Symtab
*/
   
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include <math.h>
#include <math.h>
#include <errno.h>

#include "symtab.h"

#define 	 VAR  281
#define      BUILTIN  282
#define      IBUILTIN  283
#define 	 STR 285

static  Symbol *symlist = (Symbol *) 0 ;

typedef struct
        {
        char *name ;
        double cval;
        }
        CONSTS;

CONSTS consts[] =

{
        "PI",    3.14159265358979323846,
        "E",     2.71828182845904523536,
        "GAMMA", 0.57721566490153286060,
        "DEG",   57.29577951308322087680,
        "PHI",   1.61803389974989484820,
        NULL,    0.0
} ;

typedef struct
        {
        char     *name ;
        double   (*func)() ;
        }
        BUILTINS;

BUILTINS    builtins[] =

{
        "sin",      sin,
        "cos",      cos,
        "atan",     atan,
        "log",      Log,
        "log10",    Log10,
        "exp",      Exp,
        "sqrt",     Sqrt,
        "int",      integer,
        "abs",      fabs,

        "SIN",      sin,
        "COS",      cos,
        "ATAN",     atan,
        "LOG",      Log,
        "LOG10",    Log10,
        "EXP",      Exp,
        "SQRT",     Sqrt,
        "INT",      integer,
        "ABS",      fabs,

        NULL,       (void *) 0
} ;

typedef struct
        {
        char     *name ;
        int      (*ifunc)() ;
        }
        IBUILTINS;

IBUILTINS    ibuiltins[] =

{
        NULL,       (void *) 0
} ;

/*--------------------------------------------------------------------------
**  Support routines
*/

void	execerror(char * str, char *str2)
{
	printf("%s - %s", str, str2);
	exit(1);
}

double errcheck( double d, char *s)
{
    if (errno == EDOM) {
        errno = 0 ;
        execerror( s, "argument out of domain") ;
    }
    else if (errno == ERANGE) {
        errno = 0 ;
        execerror(s, "result out of range") ;
    }

    return d ;
}
/*--------------------------------------------------------------------------
**  EMALLOC -   allocate memory for string, complain on error.
*/

char    *emalloc(unsigned n)

{
 char *p ;

   p = (char *) malloc( n) ;
   if (p == (char *)0)
      execerror("out of memory", (char *) 0) ;

   return p ;
}

//////////////////////////////////////////////////////////////////////////

void    init_symtab(void)

{
    int i ; Symbol *s ;

    for (i=0 ; consts[i].name ; i++)
		{
      	push_symtab( consts[i].name, "", VAR, consts[i].cval) ;
		}

    for (i=0 ; builtins[i].name ; i++)
        {
        s = push_symtab( builtins[i].name, "", BUILTIN, 0.0) ;
        s->u.ptr = builtins[i].func ;
        }

    for (i=0 ; ibuiltins[i].name ; i++)
        {
        s = push_symtab( ibuiltins[i].name, "", IBUILTIN, 0) ;
        s->u.iptr = ibuiltins[i].ifunc ;
        }
}

//////////////////////////////////////////////////////////////////////////

void    dump_symtab(void)

{
    Symbol *sp ;

    for (sp = symlist ; sp != (Symbol *) 0 ; sp = sp->next)
        {
		char *str;
		translate_type(sp->type, &str);

        printf("Symbol: '%s' '%s' %d %s %f.2\n", sp->name, sp->var, 
						sp->type, str, sp->u.dval);
        }
	printf("\r\n");
}

/*
 * find s in symbol table
 */

Symbol  *lookup_symtab(char *s, int type)

{
    Symbol *sp ;

    for (sp = symlist ; sp != (Symbol *) 0 ; sp = sp->next)
		if(sp->type == type)			
    	  if (strcmp(sp->name, s) == 0)
	         return sp ;                                 /* found  */

   return (Symbol *) 0 ;                               /* symbol not found */
}

/*--------------------------------------------------------------------------
**  INSTALL -   install an item into the symbol in table
*/

Symbol  *push_symtab(char *name, char *var, int type, double d)

{	
    Symbol *sp = lookup_symtab(name, type);
	
	// Duplicate
	//if(sp)
	//	return NULL;

    sp = (Symbol *) emalloc( sizeof( Symbol)) ;

	sp->magic = SYMTAB_MAGIC;
    sp->name = emalloc( strlen(name) + 1) ;
    strcpy( sp->name, name) ;

    sp->var = emalloc( strlen(var) + 1) ;
    strcpy( sp->var, var) ;

    sp->type = type;
    sp->u.dval = d;
    sp->next = symlist ;                    /* add symbol to front of list */
    symlist = sp ;

    return sp ;
}

//////////////////////////////////////////////////////////////////////////

Symbol  *pop_symtab(char *name, char *var, int *type, double *d)

{
	Symbol *last = symlist;
	if(last == NULL)
		return NULL;

	if(symlist->magic != SYMTAB_MAGIC)
		{ 
		printf("simlist->magic != SYMTAB_MAGIC\r\n");
		}

	strcpy(name, symlist->name);
	strcpy(var, symlist->var);
	*type = symlist->type;
	*d = symlist->u.dval;
	
	free(symlist->name);
	free(symlist->var);
	symlist = symlist->next;
	free(last);
}

/*--------------------------------------------------------------------------
**  Math functions
*/

double Log( double x)

{
   return errcheck( log(x), "log") ;
}

double Log10( double x)
{
   return errcheck( log10(x), "log10") ;
}

double Exp( double x)
{
   return errcheck( exp(x), "exp") ;
}

double Pow( double x, double y)
{
   return errcheck( pow(x, y), "exponentiation") ;
}

double integer( double x)
{
   return (double)(long) x ;
}

double Sqrt( double x)
{
   return errcheck( sqrt(x), "sqrt") ;
}


