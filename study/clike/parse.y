%{

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symtab.h"

#define DEBUG 0
#define TRUE 1
#define FALSE 0
#define MAX_MSG_LEN 50
#define YYDEBUG 1

int errcnt = 0;
char errmsg[40];
extern char *yytext;
extern FILE *yyin;
extern FILE *yyout;
extern int yyparse();
extern int lineno;
int yydebug = 1;
int t;
%}

/* no warning for fewer than 1 shift/reduce conflicts and 0 reduce/reduce */
%expect 1
%union { int tokid;
         char *tokname;
       }

%token <tokname> IDENT NUMBER
%token <tokid> ASSIGN PLUS LBRACE RBRACE LPAREN RPAREN SEMI ERROR FLOAT INTEGER
/* ADDED */
%token <tokid> IF THEN ELSE WHILE RETURN GOTO READ WRITE VOID CHAR
/* ADDED */
%token <tokid> NE EQ LT LE GT GE AND OR MINUS TIMES OVER MOD INT REAL
/* ADDED */
%token <tokid> LBRACK RBRACK COMMA CHRLIT STRLIT
%type <tokid> block stmt_seq stmt decl expr term assignmnt decltype error

%start block

%%

block       : LBRACE stmt_seq RBRACE
            | LPAREN stmt_seq RPAREN
            | error { yyerrok; return 0; }
            ;

stmt_seq    : stmt_seq stmt SEMI
            | stmt SEMI
            | error  { yyerrok; return 0;}
            ;

stmt        : expr
            | decl
            | assignmnt { $$ = $1; }
            | error  { yyerrok; return 0;}
            ;

decl        : decltype IDENT {
                setType($2,$1);
                fprintf(stdout,"set decltype to: %d for %s\n",$$,$2);
            }
            ;

expr        : expr PLUS term
              { /* add constraint here */ }

            | term { $$ = $1; }
            | error    { yyerrok; return 0;}
            ;

assignmnt   : IDENT ASSIGN expr
              { /* add constraint here */ }
            ;

term        : NUMBER { $$ = lookupType($1); }

            | IDENT  { $$ = lookupType($1); }
            ;

decltype    : INTEGER  { $$ = INT_TYPE; }
            | FLOAT { $$ = REAL_TYPE; }
            ;

%%

int main( int argc,char *argv[] )
{
   strcpy(errmsg,"type error\n");
   int i;
   if(argc < 2) {
      printf("Usage: ./cfc <source filename>\n");
      exit(0);
   }
   FILE *fp = fopen(argv[1],"r");
   if(!fp) {
     printf("Unable to open file for reading\n");
     exit(0);
   }
   yyin = fp;

   fp = fopen("dump.symtab","w");
   if(!fp) {
     printf("Unable to open file for writing\n");
     exit(0);
   }

   int flag = yyparse();

   /* dump symtab for debugging if necessary  */
   symtab_dump(fp);
   lineno--;  /* don't count the last newline */
   printf("\nsemantic error cnt: %d \tlines of code: %d\n",errcnt,lineno);

   /* cleanup */
   fclose(fp);
   fclose(yyin);

   return flag;
}


yywrap()
{
   return(1);
}

int yyerror(char * msg)
{ fprintf(stderr,"%s: line %d: \n",msg,lineno);
  return 0;
}

And in case you need it, here is the symbol table that I'm using:

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symtab.h"

/* maximum size of hash table */
#define SIZE 200
#define MAXTOKENLEN 40

/* power of two multiplier in hash function */
#define SHIFT 4

/* the hash function */
static int hash ( char * key )
{ int temp = 0;
  int i = 0;
  while (key[i] != '\0')
  { temp = ((temp << SHIFT) + key[i]) % SIZE;
    ++i;
  }
  return temp;
}

/* a linked list of references (line nos) for each variable */
typedef struct RefListRec {
     int lineno;
     struct RefListRec * next;
     /* ADDED */
     int type;
} * RefList;


/* hash entry holds variable name and its reference list */
typedef struct HashRec {
     char st_name[MAXTOKENLEN];
     int st_size;
     RefList lines;
     int st_value;
     /* ADDED */
     int st_type;
     struct HashRec * next;
} * Node;

/* the hash table */
static Node hashTable[SIZE];

 /* insert an entry with its line number - if entry
  *  already exists just add its reference line no.
  */
void insert( char * name, int len, int type, int lineno )
{
  /* ADDED */
  /*int len = strlen(name);*/
  int h = hash(name);
  Node l =  hashTable[h];
  while ((l != NULL) && (strcmp(name,l->st_name) != 0))
    l = l->next;
  if (l == NULL) /* variable not yet in table */
  { l = (Node) malloc(sizeof(struct HashRec));
    strncpy(l->st_name, name, len);
    /* ADDED */
    l->st_type = type;
    l->lines = (RefList) malloc(sizeof(struct RefListRec));
    l->lines->lineno = lineno;
    l->lines->next = NULL;
    l->next = hashTable[h];
    hashTable[h] = l; }
  else /* found in table, so just add line number */
  { RefList t = l->lines;
    while (t->next != NULL) t = t->next;
    t->next = (RefList) malloc(sizeof(struct RefListRec));
    t->next->lineno = lineno;
    t->next->next = NULL;
  }
}

/* return value (address) of symbol if found or -1 if not found */
int lookup ( char * name )
{ int h = hash(name);
  Node l =  hashTable[h];
  while ((l != NULL) && (strcmp(name,l->st_name) != 0))
    l = l->next;
  if (l == NULL) return -1;
  else return l->st_value;
}

/* return type value of symbol or -1 if symbol not found */
int lookupType( char * name )
{
  int h = hash(name);
  Node l =  hashTable[h];
  while ((l != NULL) && (strcmp(name,l->st_name) != 0))
    l = l->next;
  if (l == NULL) return -1;
  else return l->st_type;
}

/* set datatype of symbol returns 0 if symbol not found */
int setType( char * name, int t )
{
   int h = hash(name);
   Node l =  hashTable[h];
   while ((l != NULL) && (strcmp(name,l->st_name) != 0))
     l = l->next;
   if (l == NULL) return -1;
   else {
     l->st_type = t;
     return 0;
   }
}

/* print to stdout by default */
void symtab_dump(FILE * of) {
  int i;
  fprintf(of,"------------ ------ ------------\n");
  fprintf(of,"Name         Type   Line Numbers\n");
  fprintf(of,"------------ ------ -------------\n");
  for (i=0; i < SIZE; ++i)
  { if (hashTable[i] != NULL)
    { Node l = hashTable[i];
      while (l != NULL)
      { RefList t = l->lines;
        fprintf(of,"%-12s ",l->st_name);

        if (l->st_type == INT_TYPE)
           fprintf(of,"%-7s","int ");
        if (l->st_type == REAL_TYPE)
           fprintf(of,"%-7s","real");
        if (l->st_type == STR_TYPE)
           fprintf(of,"%-7s","string");


        while (t != NULL)
        { fprintf(of,"%4d ",t->lineno);
          t = t->next;
        }
        fprintf(of,"\n");
        l = l->next;
      }
    }
  }
}

