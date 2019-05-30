
#include <stdio.h>    

#include "symtab.h"

static int		gen_expr(Symbol *sp);
static Symbol *do_expr(Symbol *sp);
static	int		show_item(Symbol *sp);
 
//////////////////////////////////////////////////////////////////////////
//

int	gen_code()

{
    Symbol *sp ;

    for (sp = symlist ; sp != (Symbol *) 0 ; sp = sp->next)
        {
		if(sp->type == ALL_ITEM_EXPR)
			{
			gen_expr(sp);	
			}
		}
}

//////////////////////////////////////////////////////////////////////////
//

int		gen_expr(Symbol *sp)

{
    Symbol *sp2 = sp;

    //printf("'%s\n", sp->name);
	
	show_item(sp);			
	do_expr(sp2);		
	printf("\n");
}

Symbol *do_expr(Symbol *sp)

{
	if(sp == NULL)
		return NULL;

	Symbol *sp3;
	for (sp3 = sp->next; sp3 != (Symbol *) 0 ; sp3 = sp3->next)
		{		
		if(strcmp(sp->name, sp3->res) == 0)
			{
			show_item(sp3);
			do_expr(sp3);
			}
		if(strcmp(sp->var, sp3->res) == 0)
			{
			show_item(sp3);
			do_expr(sp3);
			}
		}
	return sp3;
}


int		show_item(Symbol *sp)

{
	char *opstr; translate_type(sp->type, &opstr);

	printf("'%s' '%s' %s(%d) -> '%s' %.2f\n", sp->name, sp->var,
					 opstr, sp->type, sp->res, sp->u.dval);

	return 0;
}
	
