
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

#define     DECL_VAR    	1003
#define     DECL_VAR2   	1004
#define     DECL_VAR3   	1005

#define     DECL_CALL   	1012
#define     DECL_CALL2  	1013
#define     DECL_IF  		1015
#define     DECL_ELSE  		1016
#define     DECL_VAR4  		1017

#define     ALL_ITEM_EXPR	1060
#define     ALL_ITEM_ASSN	1061
#define     ALL_ITEM_DEBUG	1062
#define     ALL_ITEM_FUNC	1063
#define     ALL_ITEM_DECL	1064

#define     ALL_ITEM_COMM	1065

#define     FUNC_ASSN		1100
#define     FUNC_DECL		1101
#define     FUNC_DECL_ARG	1102
#define     FUNC_DECL_NAME 	1103

#define     RET_EXPR   	 	1200
#define     RET_VAL    	 	1201
#define     RET_NUM    	 	1202

/* -------- Macros: ------------------------------------------------------ */

typedef struct Symbol {    /* symbol table entry */
         char 	*name ;
         short 	type ;      /* VAR, BLTIN, UNDEF  */
		 int 	magic;
		 char 	*var;
         char 	*res;
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
Symbol  *pop_symtab(char *name, char *var, char *res, int *type, double *d);
Symbol  *push_symtab(char *name, char *var, char *res, int type, double d);

double Log(double x);
double Log10(double x);
double Exp(double x);
double Pow(double x,double y);
double integer(double x);
double Sqrt(double x);

double errcheck( double d, char *s);


/* -------- Declarations: ------------------------------------------------ */


/* -------- Definitions: ------------------------------------------------- */

extern Symbol *symlist;

#undef  EXTERN
#undef  EXPORT

#endif

/* EOF */
