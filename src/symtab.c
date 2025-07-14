/* -------------------------------------------------------------------------
 *
 *  Symtab implementation.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include <errno.h>
#include <math.h>

#include "pcomp.h"
#include "symtab.h"
#include "pmath.h"
#include "emalloc.h"

Symbol  *symlist = (Symbol *) 0 ;
Symbol  *symend = (Symbol *) 0 ;

Symcoll *symcoll = (Symcoll *) 0 ;
ifstack *ifcoll = (ifstack *)0;

typedef struct
    {
    char *name ;
    double cval;
    }  CONSTS;

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
    } BUILTINS;

BUILTINS    builtins[] =

{
    "sin",      sin,
    "cos",      cos,
    "atan",     atan,
    "log",      log,
    "log10",    log10,
    "exp",      exp,
    "sqrt",     sqrt,
    "int",      integer,
    "abs",      fabs,

    "SIN",      sin,
    "COS",      cos,
    "ATAN",     atan,
    "LOG",      log,
    "LOG10",    log10,
    "EXP",      exp,
    "SQRT",     sqrt,
    "INT",      integer,
    "ABS",      fabs,

    NULL,       (void *) 0
} ;

typedef struct
    {
    char     *name ;
    int      (*ifunc)() ;
    } IBUILTINS;

IBUILTINS    ibuiltins[] =

{
        NULL,       (void *) 0
} ;

//////////////////////////////////////////////////////////////////////////

void    init_symtab(void)

{
    int i ; Symbol *s ;

    for (i=0 ; consts[i].name ; i++)
        {
        //push_symtab( consts[i].name, "", VAR, consts[i].cval) ;
        }

    for (i=0 ; builtins[i].name ; i++)
        {
        //s = push_symtab( builtins[i].name, "", BUILTIN, 0.0) ;
        //s->u.ptr = builtins[i].func ;
        }

    for (i=0 ; ibuiltins[i].name ; i++)
        {
        //s = push_symtab( ibuiltins[i].name, "", IBUILTIN, 0) ;
        //s->u.iptr = ibuiltins[i].ifunc ;
        }
}

// Dump symtab item

void  dump_symitem(Symbol *sp)

{
    //printf("Dumping: %p\n", sp);

    char *opstr = "None";
    pretranslate_type(sp->type, &opstr);
    //printf("'%s' '%s' %s(%d) -> '%s' %.2f\n", sp->name, sp->var,
    //               opstr, sp->type, sp->res, sp->u.dval);
    if(sp->type < ALL_ITEM_EXPR || sp->type > ALL_ITEM_DECL)
        printf("  ");
    //printf("'%s' [%d] %s(%d)  '%s' [%d]  -> '%s' [%d] ", sp->name, sp->con_name,
    //                    opstr,  sp->type, sp->var, sp->con_var,
    //                        sp->res, sp->con_res);
    printf("name: '%s' op: '%s' (%d) var: '%s' res: '%s' type: %d ",
                    sp->name, opstr, sp->type, sp->var, sp->res, sp->type);
    //printf("ret: '%s' \n", sp->res);
    //printf("'%s'  %s(%d)  '%s'  -> '%s'  ",
    //                    sp->name, opstr,  sp->type,
    //                            sp->var, sp->res);
    if(sp->u.dval != 0)
        {
        printf("dval: %.2f", sp->u.dval);
        }
    printf("\n");
}

//////////////////////////////////////////////////////////////////////////

void    dump_symtab(void)

{
    Symbol *sp;
    if (!symlist)
        {
        printf("Empty symtab\n"); return;
        }
    printf("Dumping symtab:\n");
    for (sp = symlist ; sp != (Symbol *) 0 ; sp = sp->next)
        {
        dump_symitem(sp);
        }
    //printf("\n");
}

void    revdump_symtab(void)

{
    Symbol *sp;
    if (!symend)
        {
        printf("Empty symtab\n"); return;
        }
    printf("Reverse dumping symtab:\n");
    for (sp = symend ; sp != (Symbol *) 0 ; sp = sp->prev)
        {
        dump_symitem(sp);
        }
    //printf("\n");
}

/*
 * find var in symbol table
 */

Symbol *lookup_res_symtab(char *var, int type)

{
    Symbol *sp ;
//    printf("lookup_res_symtab '%s'\n", var);

    for (sp = symlist ; sp != (Symbol *) 0 ; sp = sp->next)
        if(sp->type == type)
          if (strcmp(sp->res, var) == 0)
             return sp ;                                 /* found  */

   return (Symbol *) 0 ;                               /* symbol not found */
}

/*
 * Find str in symbol table
 */

Symbol  *lookup_symtab(char *str, int type)

{
    Symbol *retsp = NULL;
    //printf("lookup_symtab '%s' ... ", str);
    for (Symbol *sp = symlist ; sp != (Symbol *) 0 ; sp = sp->next)
        {
        if(sp->type == type)
            {
            //printf("type of: %s ", sp->name);
            if (strcmp(sp->var, str) == 0)
                {
                //printf("Found: %s %p\n", sp->var, sp);
                retsp = sp ;    /* found  */
                break;
                }
            }
        }
    //printf("\n");
    return retsp;
}

Symbol  *make_symstr(char *name, char *var, char *val, int type)

{
    static int nserial = 0;
    char name2[12] = "";
    if (!strlen(name))
        {
        snprintf(name2, sizeof(name2), "name_%d_%x", type, nserial);
        name = name2;
        nserial++;
        }
    return make_symtab(name, var, val, type, 0);
}

Symbol  *make_symtab(char *name, char *var, char *res, int type, double d)

{
    Symbol *sp = (Symbol *) emalloc2( sizeof( Symbol), __LINE__, __FILE__) ;
    //sp = (Symbol *) emalloc( sizeof( Symbol)) ;
    memset(sp, '\0', sizeof(Symbol));
    sp->magic = SYMTAB_MAGIC;
    sp->name = estrdup2(name, __LINE__, __FILE__);
    sp->var = estrdup2(var, __LINE__, __FILE__);
    sp->res = estrdup2(res, __LINE__, __FILE__);
    sp->type = type;
    sp->u.dval = d;
    //sp->prev = NULL;        // Already set by memset
    //sp->next = NULL;
    return sp;
}

/*--------------------------------------------------------------------------
**  Install an item into the symbol in table
*/

Symbol  *push_symtab(char *name, char *var, char *res, int type, double d)

{
    //return NULL;

    Symbol *sp = lookup_symtab(var, type);
    // Duplicate, overwrite
    if(sp)
        {
        sp->name = estrdup2(name, __LINE__, __FILE__);
        sp->var = estrdup2(var, __LINE__, __FILE__);
        sp->res = estrdup2(res, __LINE__, __FILE__);
        sp->type = type;
        sp->u.dval = d;

        return sp;
        }
    sp = make_symtab(name, var, res, type, d);

    if(symlist == NULL)           /* add first one */
        {
        symlist = sp;
        }
    else
        {                           /* add to the end */
        Symbol *sp2;
        for(sp2 = symlist; sp2->next != NULL; sp2 = sp2->next)
            {
            }
        sp2->next = sp;
        sp->prev  = sp2;
        }
    symend = sp ;
    return sp ;
}

// -----------------------------------------------------------------------
//  curr  ^next
//  prev   curr  ^next
//         prev   curr  ^next

void    delitem_symtab(Symbol  *sp)

{
    Symbol *last = symlist;

    if(sp == NULL)
        return;
    if(last == NULL)
        return;
    if(sp->magic != SYMTAB_MAGIC)
        {
        printf("sp->magic != SYMTAB_MAGIC\r\n");
        return;
        }
    Symbol  *prev = sp->prev;
    Symbol  *next = sp->next;
    // Effected terminals?
    if (sp == symlist)
        {
        if (next)
            {
            symlist = next;
            next->prev = NULL;
            }
        else
            {
            symlist = NULL;
            symend = NULL;
            }
        }
   else if (sp == symend)
        {
        if(prev)
            {
            symend = prev;
            prev->next = NULL;
            }
        else
            symend = NULL;
        }
    else
        {// Unlink from chain
        prev->next = sp->next;
        next->prev = prev;
        }
    efree(sp);
}

//////////////////////////////////////////////////////////////////////////

Symbol  *pop_symtab(char *name, char *var, char *res, int *type, double *d)

{
    //return NULL;

    Symbol *last = symlist;

    if(last == NULL)
        return NULL;

    if(last->magic != SYMTAB_MAGIC)
        {
        printf("simlist->magic != SYMTAB_MAGIC\r\n");
        }

    strcpy(name, symlist->name);
    strcpy(var, symlist->var);
    strcpy(res, symlist->res);

    if(type)
        *type = symlist->type;

    if(d)
        *d = symlist->u.dval;

    efree(symlist->name);
    efree(symlist->var);
    efree(symlist->res);

    symlist = symlist->next;
    efree(last);

    return symlist;
}

///////////////////////////////////////////////////////////////////////////
//

void    empty_symtab()

{
    //return;

    char name[MAX_VARLEN], var[MAX_VARLEN], res[MAX_VARLEN];
    int itype;  double dd;

    while(1==1)
        {
        Symbol  *sp = pop_symtab(name, var, res, &itype, &dd);
        if(sp == NULL)
            break;
        }
    //dump_symtab();
}

///////////////////////////////////////////////////////////////////////////
// Stack of if statements

ifstack *push_ifstack(char *name, char *ifname, char *elname, int val)

{
    //return;

    ifstack *iptr;

    iptr = (ifstack *) emalloc( sizeof(ifstack)) ;

    iptr->magic = IFSTACK_MAGIC;

    iptr->name = emalloc( strlen(name) + 1) ;
    strcpy(iptr->name, name) ;
    iptr->ifname = emalloc( strlen(ifname) + 1) ;
    strcpy(iptr->ifname, ifname) ;
    iptr->elname = emalloc( strlen(elname) + 1) ;
    strcpy(iptr->elname, elname) ;

    iptr->val = val;

    iptr->next = ifcoll;
    ifcoll =  iptr;

    return iptr ;
}

ifstack *pop_ifstack(char *name, char *ifname, char *elname, int *val)

{
    ifstack *last = ifcoll;

    if(last == NULL)
        return NULL;

    if(last->magic !=  IFSTACK_MAGIC)
        {
        printf("ifstack->magic != IFSTACK_MAGIC\r\n");
        }

    strcpy(name, ifcoll->name);
    strcpy(ifname, ifcoll->ifname);
    strcpy(elname, ifcoll->elname);

    if(val)
        *val = ifcoll->val;

    efree(ifcoll->name);
    efree(ifcoll->ifname);
    efree(ifcoll->elname);

    ifcoll = ifcoll->next;

    efree(last);

    return ifcoll;
}

ifstack *peek_ifstack(char *name, char *ifname, char *elname, int *val)

{
    ifstack *last = ifcoll;

    if(last == NULL)
        return NULL;

    if(last->magic !=  IFSTACK_MAGIC)
        {
        printf("ifstack->magic != IFSTACK_MAGIC\r\n");
        }

    strcpy(name, ifcoll->name);
    strcpy(ifname, ifcoll->ifname);
    strcpy(elname, ifcoll->elname);

    if(val)
        *val = ifcoll->val;

    return ifcoll;
}

///////////////////////////////////////////////////////////////////////////
//  Stack of strings or integers or stacks

int add_ddef(outstr **root, char *str)

{
    //return;

    //printf("ddef (%p) %s", *root, str);

    outstr *sp = (outstr *) emalloc( sizeof( outstr)) ;

    sp->state = 0;
    sp->magic = OUTSRIN_MAGIC;
    sp->line = emalloc2( strlen(str) + 1, __LINE__, __FILE__) ;
    strcpy( sp->line, str) ;
    sp->next = NULL;
    sp->ptr = NULL;

    if(*root == NULL)             /* add first one */
        {
        *root = sp;
        }
    else
        {                           /* add to the end */
        outstr *sp2;
        for(sp2 = *root; sp2->next != NULL; sp2 = sp2->next)
            {
            }
        sp2->next = sp;
        }
}

///////////////////////////////////////////////////////////////////////////

int push_ddef(outstr **root, int state)

{
    //return;

    outstr *sp = (outstr *) emalloc( sizeof( outstr)) ;

    sp->state = 0;
    sp->magic = OUTSRIN_MAGIC;
    sp->line = NULL;
    sp->next = NULL;
    sp->ptr = NULL;

    sp->next = *root;
    *root = sp;

    return state;
}

///////////////////////////////////////////////////////////////////////////

int push_ddef_ptr(outstr **root, void *ptr)

{
    //return;

    outstr *sp = (outstr *) emalloc( sizeof( outstr)) ;

    sp->state = 0;
    sp->magic = OUTSRIN_MAGIC;
    sp->line = NULL;
    sp->next = NULL;
    sp->ptr = ptr;

    sp->next = *root;
    *root = sp;

    return 0;
}

///////////////////////////////////////////////////////////////////////////

int pop_ddef(outstr **root, int *state)

{
    if(*root == NULL)
        return 0;

    outstr *last = *root;

    *state = (*root)->state;
    *root = (*root)->next;

    efree(last);

    return *state;
}

int pop_ddef_ptr(outstr **root, void **ptr)

{
    outstr *last = *root;

    *ptr = (*root)->ptr;
    *root = (*root)->next;

    efree(last);

    return 0;
}

///////////////////////////////////////////////////////////////////////////

int peek_ddef_ptr(outstr **root, void **ptr)

{
    *ptr = (*root)->ptr;
    return 0;
}

int print_ddata(outstr *root)

{
    #ifndef TEST
    outstr *sp2;
    //  printf("print data %p\n", root);
    for(sp2 = root; sp2 != NULL; sp2 = sp2->next)
        {
        if(sp2->line)
            fprintf(asmfp, "%s", sp2->line);
        }
    #endif
    return 0;
}

int     parse_line(char *str, char **ptr1, char **ptr2, char **ptr3)

{
    int loop, loop2, loop3, len = strlen(str);

    *ptr1 = str + len; *ptr2 = str + len; *ptr3 = str + len;

    // skip initial blanks
    for (loop = 0; loop < len; loop++)
        {
        if(str[loop] != ' ' && str[loop] != '\t')
            break;
        }
    //printf("skipped blanks '%s'\n", str + loop);
    //*ptr1 = strdup(str + loop);

    // skip till non blank
    for (loop2 = loop; loop2 < len; loop2++)
        {
        if(str[loop2] == ' ' || str[loop2] == '\t' ||
            str[loop2] == ',')
            break;
        }
     //(*ptr1)[loop2 - loop] = '\0';

    *ptr1 =  strndup(str + loop, loop2 - loop);

    // skip initial blanks
    for (loop3 = loop2 + 1; loop3 < len; loop3++)
        {
        if(str[loop3] != ' ' && str[loop3] != '\t')
            break;
        }

    //*ptr2 = strdup(str + loop3);

    // skip till non blank
    for (loop2 = loop3 + 1; loop2 < len; loop2++)
        {
        if(str[loop2] == ' ' || str[loop2] == '\t' ||
            str[loop2] == ',' || str[loop2] == '\n' || str[loop2] == '\r')
            break;
        }
     //(*ptr2)[loop2 - loop3] = '\0';
     *ptr2 =  strndup(str + loop3, loop2 - loop3);

    // skip initial blanks
    for (loop3 = loop2 + 1; loop3 < len; loop3++)
        {
        if(str[loop3] != ' ' && str[loop3] != '\t')
            break;
        }

    //*ptr3 = strdup(str + loop3);

    // skip till non blank
    for (loop2 = loop3 + 1; loop2 < len; loop2++)
        {
        if(str[loop2] == ' ' || str[loop2] == '\t' ||
            str[loop2] == ',' || str[loop2] == '\n'|| str[loop2] == '\r')
            break;
        }
     //(*ptr3)[loop2 - loop3] = '\0';
     *ptr3 =  strndup(str + loop3, loop2 - loop3);
}


// print with code duplication left out

int print_ddcode(outstr *root)

{
    #ifndef TEST
    outstr *sp2; int opt = 0;
    char *prev = 0, *ptr1, *ptr2, *ptr3;
    char *ptr11, *ptr12, *ptr13;

    //  printf("print data %p\n", root);

    for(sp2 = root; sp2 != NULL; sp2 = sp2->next)
        {
        if(!sp2->line)
            continue;

        if(prev)
            {
            parse_line(sp2->line, &ptr1, &ptr2, &ptr3);
            //printf("parse:      '%s'  '%s'  '%s'\n", ptr1, ptr2, ptr3);

            parse_line(prev, &ptr11, &ptr12, &ptr13);
            //printf("parse prev: '%s'  '%s'  '%s'\n", ptr11, ptr12, ptr13);

            if(strcmp(ptr1, "mov") == 0)
                {
                if(strcmp(ptr11, "mov") == 0)
                    {
                    if(strcmp(ptr2, ptr13) == 0)
                        {
                        //printf("cmp '%s' '%s'\n", ptr2, ptr13);
                        if(strstr(ptr12, ptr3) != 0)
                            {
                            //printf("opt '%s' '%s'\n", ptr12, ptr3);
                            // Mark here
                            //opt = 2;
                            }
                        }
                    }
                }
            }

        if(prev && opt == 0)
            {
            fprintf(asmfp, "%s", prev);
            }

        // Skip two
        if(opt)
            opt--;

        // Get a copy of the prevline
        if(prev)
            free(prev);

        prev = strdup(sp2->line);
        }

     if(prev)
        {
        fprintf(asmfp, "%s", prev);
        free(prev);
        }
    #endif

    return 0;
}

void    empty_ddef(outstr **root)

{
    int state;
    while(1==1)
        {
        pop_ddef(root, &state);

        if(*root == 0)
            break;
        }
}

///////////////////////////////////////////////////////////////////////////

static int  curr_unique = 1000;

char    *create_unique(char *prefix)

{
    char *ret = malloc(MAX_VARLEN);
    snprintf(ret, MAX_VARLEN, "%s_%d", prefix, curr_unique);
    curr_unique++;
    return ret;
}

int     create_unique2(char *str, char *prefix, char *str1, char *str2)

{
    snprintf(str, MAX_VARLEN, "%s_%d_%s_%s", prefix, curr_unique, str1, str2);
    curr_unique++;
    return 0;
}

///////////////////////////////////////////////////////////////////////////

#ifdef TEST

void execerror(char *str, char *str2)
{

}

int translate_type(int, char **pstr)
{
    return 0;
}

double integer(double)
{
    return 0;
}

int main(int argc, char *argv[])

{
    printf("test symtab\n");
    for (int aa = 0 ; aa < 3; aa ++)
        {
        char strx[24];
        snprintf(strx, sizeof(strx), "hello_%d", aa);
        //printf("%s", strx);
        push_symtab("", strx, "", DECL_DEFINE, 0);
        }
    Symbol  *st2 = lookup_symtab("1234", DECL_DEFINE);
    if (st2) printf("found %s\n", st2->var);

    Symbol  *st3 = lookup_symtab("hello", DECL_DEFINE);
    //if (st3) printf("found: %s\n", st3->var);

    dump_symtab();
    revdump_symtab();

    Symbol  *st4 = lookup_symtab("hello_0", DECL_DEFINE);
    //if (st4) printf("found: %s\n", st4->var);
    delitem_symtab(st4);

    dump_symtab();
    revdump_symtab();

    Symbol  *st5 = lookup_symtab("hello_2", DECL_DEFINE);
    //if (st5) printf("found: %s\n", st5->var);
    delitem_symtab(st5);

    dump_symtab();
    revdump_symtab();

    Symbol  *st6 = lookup_symtab("hello_1", DECL_DEFINE);
    //if (st6) printf("found: %s\n", st6->var);
    delitem_symtab(st6);

    dump_symtab();
    revdump_symtab();

    //empty_symtab();
    //dump_symtab();

    //print_emalloc();
    //print_estrdup();
}

int isdefined(char *def)
{
    int ret = 0;


}

#endif
