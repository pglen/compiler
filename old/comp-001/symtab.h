
/* =====[ symbol.h ]=========================================================


      REV     DATE     BY           DESCRIPTION
      ----  --------  ----------    --------------------------------------
      0.00  mm/dd/13  Peter Glen    Initial version.

   ======================================================================= */

#ifndef symbol_defined
#define symbol_defined

#ifdef  EXPORT
#define EXTERN
#else
#define EXTERN extern
#endif

/* -------- Defines: ----------------------------------------------------- */

#define SYMTAB_MAGIC	0x2324567

     
/* -------- Macros: ------------------------------------------------------ */

typedef struct Symbol {    /* symbol table entry */
         char 	*name ;
         short 	type ;      /* VAR, BLTIN, UNDEF  */
		 int 	magic;
		 char 	*var;
         union {
               int    	len;                /* if str */
               char   	*str;               /* if str */
               char   	cval;               /* if VAR */
               int    	ival;               /* if VAR */
               long   	lval;               /* if VAR */
               double 	dval;                /* if VAR */
               double 	(*ptr)() ;      	/* if BUILTIN */
               int    	(*iptr)() ;    		/* if IBUILTIN */
			   int		(*func)();
         } u ;
  struct Symbol *next ;
} Symbol ;

/* -------- Protos ------------------------------------------------------- */

void    init_symtab(void);
void    dump_symtab(void);

Symbol  *lookup_symtab(char *s, int type);
Symbol  *push_symtab(char *name, char *var, int type, double d);
Symbol  *pop_symtab(char *name, char *var, int *type, double *d);

//Symbol  *push_symtab(char *s, int t, double d);
//Symbol  *pop_symtab(char *name, int *type, double *d);

double Log(double x);
double Log10(double x);
double Exp(double x);
double Pow(double x,double y);
double integer(double x);
double Sqrt(double x);

double errcheck( double d, char *s);


/* -------- Declarations: ------------------------------------------------ */


/* -------- Definitions: ------------------------------------------------- */

#undef  EXTERN
#undef  EXPORT

#endif

/* EOF */
