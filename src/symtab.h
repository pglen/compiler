
/* =====[ symbol.h ]=========================================================


      REV     DATE         BY             DESCRIPTION
      ----  --------       ----------    --------------------------------------
      0.00  mm/dd/13       Peter Glen    Initial version.
      0.00  dec/23/2013  Peter Glen    Progress.

   ======================================================================= */

#ifndef symbol_defined
#define symbol_defined

#ifdef  EXPORT
#define EXTERN
#else
#define EXTERN extern
#endif

/* -------- Defines: ----------------------------------------------------- */

#define MAX_ARRAY 4

#define     SYMTAB_MAGIC    0x2324567
#define     IFSTACK_MAGIC    0x2323432
#define     OUTSRIN_MAGIC    0x2332543

#define     DECL_VAR        11003
#define     DECL_VAR2       11004
#define     DECL_VAR3       11005
#define     DECL_VAR4          11006
#define     DECL_VARLIST    11007
#define     DECL_VARITEM    11008
#define     DECL_MACITEM    11009

#define     DECL_CALL       11012
#define     DECL_CALL2      11013
#define     DECL_CALL3      11014

#define     DECL_IF          11020
#define     DECL_ELSE       11021
#define     TERM_IF          11022
#define     TERM_ELSE       11023

#define     ALL_ITEM_EXPR    1060
#define     ALL_ITEM_ASSN    1061
#define     ALL_ITEM_DEBUG    1062
#define     ALL_ITEM_FUNC    1063
#define     ALL_ITEM_DECL    1064
#define     ALL_ITEM_COMM    1065
#define     ALL_ITEM_IF        1066

#define     FUNC_ASSN        1100
#define     FUNC_DECL        1101
#define     FUNC_DECL_ARG    1102
#define     FUNC_DECL_NAME     1103

#define     RET_EXPR            1200
#define     RET_VAL             1201
#define     RET_NUM             1202

#define     CALL_FUNC        1300

#define     DECL_CAST        1400
#define     DECL_DEREF        1401
#define     DECL_ADDOF        1402

#define     DECL_DEFINE        1500
#define     DECL_MACRO        1501

int print_emalloc();

/* -------- Symtab ------------------------------------------------------ */

typedef struct _Symbol {    /* symbol table entry */
         int        magic;
         short      type ;      /* VAR, BLTIN, UNDEF  */
         char       *name ;
         char       *var;
         char       *res;
         int        con_name, con_var, con_res;
         union {
               int        len;                  /* if str */
               char       *str;                 /* if str */
               char       cval;                 /* if VAR */
               int        ival;                 /* if VAR */
               long       lval;                 /* if VAR */
               double     dval;                 /* if VAR */
               double     (*ptr)() ;            /* if BUILTIN */
               int        (*iptr)() ;           /* if IBUILTIN */
               int        (*func)();
         } u ;

      struct _Symbol *prev ;
      struct _Symbol *next ;
} Symbol ;

// List of symbol entries as parsed

typedef struct Symcoll {

    int     magic;
    int        optype;

      struct _Symbol left;
      struct _Symbol right;
      struct _Symbol outp;
      struct _Symcoll *next ;

} Symcoll;

/* -------- Declarations: ------------------------------------------------ */

void    dump_symitem(Symbol *sp);
int     if_func(int type);

///////////////////////////////////////////////////////////////////////////

void    init_symtab(void);
void    dump_symtab(void);
void    revdump_symtab(void);
void    delitem_symtab(Symbol  *sp);
void    empty_symtab();

Symbol  *make_symstr(char *name, char *var, char *val, int type);
Symbol  *make_symtab(char *name, char *var, char *res, int type, double d);
Symbol  *lookup_res_symtab(char *var, int type);
Symbol  *lookup_symtab(char *s, int type);
Symbol  *pop_symtab(char *name, char *var, char *res, int *type, double *d);
Symbol  *push_symtab(char *name, char *var, char *res, int type, double d);

/* -------- If Stack: ---------------------------------------------------- */

typedef struct ifstack {

        int magic;
        char *name;
        char *ifname;
        char *elname;
        int val;
          struct ifstack *next ;

} ifstack;

ifstack *push_ifstack(char *name, char *ifname, char *elname, int val);
ifstack *pop_ifstack(char *name, char *ifname, char *elname, int *val);

/* -------- Out string: ---------------------------------------------------- */

typedef struct outstr {

        int magic;
        char *line;
        void *ptr;
        int      state;
        struct outstr *next ;
} outstr;

int     print_ddata(outstr *root);
int     print_ddcode(outstr *root);

int     add_ddef(outstr **root, char *str);
int     push_ddef(outstr **root, int state);
int     push_ddef_ptr(outstr **root, void *ptr);

int     pop_ddef(outstr **root, int *state);
int     pop_ddef_ptr(outstr **root, void **ptr);
int     peek_ddef_ptr(outstr **root, void **ptr);
void    empty_ddef(outstr **root);

ifstack *peek_ifstack(char *name, char *ifname, char *elname, int *val);

char    *create_unique(char *prefix);
int     create_unique2(char *str, char *prefix, char *str1, char *str2);

/* -------- Definitions: ------------------------------------------------- */

extern  Symbol *symlist;
extern  FILE *asmfp;

#undef  EXTERN
#undef  EXPORT

#endif

/* EOF */
