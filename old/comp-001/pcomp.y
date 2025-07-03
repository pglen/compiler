// PCOMP parallel compiler

%{

#include <sys/param.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <netinet/in.h>
#include <arpa/ftp.h>
#include <signal.h>
#include <setjmp.h>
#include <syslog.h>
#include <time.h>
#include <stdio.h>
#include <pwd.h>
#include <unistd.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#include "symtab.h"

#define MAX_ARRAY 4

extern int testyacc;

char **ulist = 0;
char **clist = 0;
char **dlist = 0;
char **flist = 0;
char **xdlist = 0;

int add_array(char ***ulist,  char *ptr);
int add_ptr  (char ***list, char *ptr);
int init_array(char ***list);

/* define this to see indivdual parsing */
#define DEBUGYYY
#define TEST

%}
 
%union {                                           /* stack object type    */
    int     val ;                                   /* actual value         */
    long    lngval ;                               /* actual value         */
    double  dblval ;                                  /* actual value         */
	char	*strval;
    Symbol  *sym ;                                 /* symbol table ptr     */
}

%token <val> SP NL NUM ID SEP CLASS SSALC DIR RID DBG LOG
				DENY YNED FUNC BEG END RET
					LCUR RCUR PLUS MINUS COMMENT

%token  <val>   NUMBER
%token  <sym>   VAR BUILTIN IBUILTIN  UNDEF STR
%token  <sym>   TO FROM STORE RESTORE STRVAR

//%type   <val>   expr
//%type   <val>   asgn

%type   <sym>   decl1
%type   <sym>   fdecl1
%type   <sym>   fdecl2
%type   <sym>   func1
%type   <sym>   expr1
%type   <sym>   expr2
%type   <sym>   add1
%type   <sym>   sub1
%type   <sym>   call1
%type   <sym>   ret1
%type   <sym>   val1
%type   <val>   comments

//%type   <sym>   str

%right  '='
%left   '|' '&'
%left   '+' '-'
%left   '*' '/'
%left   UNARYMINUS
%right  '^'                                             /*  exponentiation */

%%

all2:  		all1
		|	all2  all1
;

all1:     class
		| decl1
		| debug1
		| func1
		| comments
;

comments:		COMMENT 
			| comments  COMMENT
	{	
	#ifdef TEST
	//if(testyacc)
	//  printf("{Comment}: %s\r\n", $1);
	#endif
	$$ = $1; 
	}
;		
debug1: DBG NUM 

{
	#ifdef TEST
	if(testyacc)
	  	printf("{Debug level}: %s\r\n", $2);
	#endif
	
	Symbol  *st = push_symtab("Debug", "", DBG, (double)atoi((char*)$2));
	//dump_symtab();
}
;

decl1:
	ID ID  '='  val1  ';' 
	{
	#ifdef TEST
	if(testyacc)
		 printf("{decl}='type=%s var=%s val=%s'\r\n ", $1, $2, $4);
	#endif
	if(lookup_symtab((char*)$2, ID) != NULL)
		{
		printf("Duplicate definition of '%s' on line %d\r\n", $2, num_lines);
		exit(1);
		}
	else
		{
		Symbol  *st = push_symtab((char*)$2, (char*)$1, ID, atoi((char*)$4));
		}

	//dump_symtab();
	}
	| ID ID ';' 
	{
	#ifdef TEST
	if(testyacc)
		 printf("{decl ni}='type=%s var=%s'\r\n", $1, $2);
	#endif
	if(lookup_symtab((char*)$2, ID) != NULL)
		{
		printf("Duplicate definition of '%s' on line %d\r\n", $2, num_lines);
		exit(1);
		}
	else
		{
		Symbol  *st = push_symtab((char*)$2, (char*)$1, ID, 0);
		}
	//dump_symtab();
	}
;

val1: 	NUM
{
	#ifdef TEST
	//if(testyacc)
	//	 printf("{val}='%s' ", $1);
	#endif
}
;	

fdecl1:
	ID ID
	{
	//strcpy($$->name, $1);

	Symbol  *st = push_symtab((char*)$2, (char*)$1, 1002, 0);	
	}
;

fdecl2: fdecl1
	{
	#ifdef TEST
	if(testyacc)
		 printf("{fdecl1}='%s'\r\n", $1);
	#endif

	}
	| fdecl2 ',' fdecl1
	{
	#ifdef TEST
	if(testyacc)
		 printf("{Fdecl2}='%s' '%s'\r\n", $1, $3);
	#endif
	}
;

func1:  FUNC  ID  LCUR expr2 RCUR
	{
	#ifdef TEST
	if(testyacc)
		 printf("{Function}='%s' '%s'\r\n", $2, $4);
	#endif
	
	if(lookup_symtab((char*)$2, FUNC) != NULL)
		{
		printf("Duplicate function '%s' on line %d\r\n", $2, num_lines);
		exit(1);
		}
	else
		{
		Symbol  *st = push_symtab((char*)$2, (char*)$1, FUNC, 0);	
		}
	}
	|	FUNC  ID  LCUR  RCUR
	{
	#ifdef TEST
	if(testyacc)
		 printf("{Function (empty)}='%s'\r\n", $2);
	#endif

	if(lookup_symtab((char*)$2, FUNC) != NULL)
		{
		printf("Duplicate function '%s' on line %d\r\n", $2, num_lines);
		exit(1);
		}
	else
		{
		Symbol  *st = push_symtab((char*)$2, "", FUNC, 0);	
		}
	}
	| FUNC  ID  '(' fdecl2 ')' LCUR expr2 RCUR
	{
	#ifdef TEST
	if(testyacc)
		 printf("{Function}='%s' '%s'\r\n", $2, $4);
	#endif
	if(lookup_symtab((char*)$2, FUNC) != NULL)
		{
		printf("Duplicate function '%s' on line %d\r\n", $2, num_lines);
		exit(1);
		}
	else
		{
		Symbol  *st = push_symtab((char*)$2, "", FUNC, 0);	
		}
	}
;

expr2:  expr1
	{
	#ifdef TEST
	if(testyacc)
	  	printf("{expr2}='%s' \r\n", $1);
	#endif
	}
		| expr2  expr1
	{
	#ifdef TEST
	if(testyacc)
	  	printf("{expr2}='%s' '%s'  \r\n", $1, $2);
	#endif
	//strcat($$,  ",");
	//strcat($$,  $2);
	}
;

ret1:
	RET 
	{
	#ifdef TEST
	if(testyacc)
	  	printf("{ret}='%s'\r\n", $1);
	#endif
	Symbol  *st = push_symtab("", "", RET, 0);	
	}

	| RET ID
	{
	#ifdef TEST
	if(testyacc)
	  	printf("{ret}='%s' '%s' \r\n", $1, $2);
	#endif
	Symbol  *st = push_symtab((char*)$2, "", RET, 0);	
	}
;
	
expr1:    add1 
		| sub1
		| call1
		| ret1
{
	#ifdef TEST
	//if(testyacc)
	//  	printf("{expr1}='%s' ", $1);
	#endif
	//$$ = $1;
}
;

call1:  ID '(' ID ')'
	{
	#ifdef TEST
	if(testyacc)
	  printf("{CALL} '%s + %s'\n", $3);
	#endif
	Symbol  *st = push_symtab((char*)$1, (char*)$3, 1000, 0);	
	}
;

add1:  ID PLUS ID

{
	#ifdef TEST
		if(testyacc)
		  printf("{ADD} '%s + %s'\n", $1, $3);
	#endif

	Symbol  *st = push_symtab((char*)$1, (char*)$3, PLUS, 0);	

}
;

sub1:  ID  MINUS  ID

{
	#ifdef TEST
	if(testyacc)
	  printf("{SUB} '%s - %s'\n", $1, $3);
	#endif

	Symbol  *st = push_symtab((char*)$1, (char*)$3, MINUS, 0);	
}
;

class: CLASS SP ID ids SSALC
{
  int loop;

#ifdef TEST
if(testyacc)
  printf("List of Classes: %s\n", $3);
#endif

  for(loop = 0; loop < (int)ulist[1]; loop++)
    {
     add_array(&clist, ulist[loop+2]);
#ifdef TEST
if(testyacc)
     printf(" '%s' ", ulist[loop+2]);
#endif
    }

#ifdef TEST
if(testyacc)
    printf("\n");
#endif

        }
;


ids:   ID
     {
       free_array(&ulist);
       //add_array(&ulist, $1);

      #ifdef DEBUGYYY
		if(testyacc)
			  printf("ID: '%s' ", $1);
      #endif
     }
       | ids ID
      {
      //add_array(&ulist, (char*)$2);

        #ifdef DEBUGYYY
		//if(testyacc)
		//	printf("ID list: '%s' ",(char*)$2);
        #endif
      }
    ;

%%

/*
 * Array of pointers.
 * First entry is number of current allocated pointers,
 * second entry next available index.
 *
 * Note:
 *     
 *  The first two array entries are used as integers. (nty noty)
 *
 * Input: pointer to root list, pointer to string to add
 *
 * Reading the list:
 *
 *  for(loop = 0; loop < (int)list[1]; loop++)
 *     {
 *     item =  list[loop+2]);
 *     }
 */

int add_array(char ***list, char *ptr)

{
  char *tmp;

      /* init list: */
    if (*list == 0)
        {
        //printf ("add_array(newlist)\n"); fflush(stdout);
        tmp = malloc((MAX_ARRAY + 2) * sizeof(char *));
        if(!tmp) printf("Out of memory.\n"), exit(0);

        *list = (char**)tmp;
        (*list)[0] = (char*)MAX_ARRAY;  /* limit */
        (*list)[1] = (char*)0;          /* index */
        }

    //printf ("add_array(list) len = %d idx = %d str= %s\n", (int)(*list)[0], (int)(*list)[1], ptr);

      /*  expand the list if needed */
     if((*list)[1] >= (*list)[0])
        {
        tmp = malloc( ((int)(*list)[0] + MAX_ARRAY + 2) * sizeof(char *));
        if(!tmp) printf("Out of memory.\n"), exit(0);

      //  printf ("add_array(expandlist)\n"); fflush(stdout);

        memcpy(tmp, *list, ((int)(*list)[1] + 2) * sizeof(char*));

        if(*list) free(*list);
        *list = (char **)tmp;
        (*list)[0] += MAX_ARRAY;
        }
    //printf ("add_array(assignlist)\n"); fflush(stdout);

     (*list)[(int)(*list)[1] + 2] = ptr;
     (*list)[1]++;
}

int free_array(char ***list)

{
  //printf("Free array \n"); fflush(stdout);

  if(*list)
    {
    free(*list);
    *list = 0;
    }
}

int init_array(char ***list)

{
    char *tmp;

    tmp = malloc((MAX_ARRAY + 2) * sizeof(char *));
    if(!tmp) printf("Out of memory.\n"), exit(0);

    *list = (char**)tmp;
    (*list)[0] = (char*)MAX_ARRAY;  /* limit */
    (*list)[1] = (char*)0;          /* index */
}

int	 translate_type(int type, char **str)

{
	switch(type)
	{
	 case SP:  *str = "SP"; break;
	 case NL:  *str = "NL"; break;
	 case NUM:  *str = "NUM"; break;
	 case SEP:  *str = "SEP"; break;
	 case CLASS:  *str = "CLASS"; break;
	 case SSALC:  *str = "SSALC"; break;
	 case DIR:  *str = "DIR"; break;
	 case RID:  *str = "RID"; break;
	 case DBG:  *str = "DBG"; break;
	 case LOG:  *str = "LOG"; break;
	 case DENY:  *str = "DENY"; break;
	 case YNED:  *str = "YNED"; break;
	 case FUNC:  *str = "FUNC"; break;
	 case BEG:  *str = "BEG"; break;
	 case END:  *str = "END"; break;
	 case RET:  *str = "RET"; break;
	 case LCUR:  *str = "LCUR"; break;
	 case RCUR:  *str = "RCUR"; break;
	 case PLUS:  *str = "PLUS"; break;
	 case MINUS:  *str = "MINUS"; break;
	 case COMMENT:  *str = "COMMENT"; break;
	 case NUMBER:  *str = "NUMBER"; break;
	 case VAR:  *str = "VAR"; break;
	 case BUILTIN:  *str = "BUILTIN"; break;
	 case IBUILTIN:  *str = "IBUILTIN"; break;
	 case UNDEF:  *str = "UNDEF"; break;
	 case STR:  *str = "STR"; break;
	 case FROM:  *str = "FROM"; break;
	 case STORE:  *str = "STORE"; break;
	 case RESTORE:  *str = "RESTORE"; break;
	 case STRVAR:  *str = "STRVAR"; break;
	 case UNARYMINUS:  *str = "UNARYMINUS"; break;
	
	default:
		*str = "XX";	
	}

	return 0;
}


