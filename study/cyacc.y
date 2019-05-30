%{

  /* =====[ PCALC.C ]=========================================================

     Description: Programmers calculator.

     Revisions:

     REV     DATE     BY           DESCRIPTION
     ----  --------  ----------    --------------------------------------
     0.00  xx.xx.94  Peter Glen    Initial version.

     ======================================================================= */

  /* -------- System includes:  -------------------------------------------- */

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <memory.h>
#include <signal.h>
#include <setjmp.h>

//#include "hocdecl.h"             /* data declarations, function prototypes */
//#include "symbol.h"
//#include "help.h"
//#include "store.h"
//#include "print.h"

  int     fSilent = 0;

  extern  FILE * yyin ;

  char    work_str[128];

/*
**  pcalc LEX
*/

#include "ctype.h"
#include "string.h"

//#include "hocdecl.h"
//#include "symbol.h"
//#include "pcalc.h"
//#include "convert.h"

extern YYSTYPE yylval;
extern  int lineno;

/* default yywrap function - always treat EOF as an EOF */
#define yywrap() 1

char    *name;
int     nchar, nword, nline ;

int     count(void);

//define TEST
#define RET_EACH

#define YYBISON 1  /* Identify Bison output.  */

%union {                                           /* stack object type    */
    int     intval ;                               /* actual value         */
    long    lngval ;                               /* actual value         */
    double  val ;                                  /* actual value         */
    Symbol  *sym ;                                 /* symbol table ptr     */
}

%}

%%

%token CONSTANT IDENTIFIER STRING_LITERAL SIZEOF;
%token PTR_OP INC_OP DEC_OP LEFT_OP RIGHT_OP LE_OP GE_OP EQ_OP NE_OP;
%token AND_OP OR_OP MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN ADD_ASSIGN;
%token SUB_ASSIGN LEFT_ASSIGN RIGHT_ASSIGN AND_ASSIGN;
%token XOR_ASSIGN OR_ASSIGN TYPE_NAME;

%token TYPEDEF EXTERN STATIC AUTO REGISTER;
%token CHAR SHORT INT LONG SIGNED UNSIGNED FLOAT DOUBLE CONST VOLATILE VOID;
%token STRUCT UNION ENUM ELLIPSIS;

%token CASE DEFAULT IF ELSE SWITCH WHILE DO FOR GOTO CONTINUE BREAK RETURN;

%start translation_unit;

%%

primary_expression
	: IDENTIFIER
	| CONSTANT
	| STRING_LITERAL
	| '(' expression ')'
	;

postfix_expression
	: primary_expression
	| postfix_expression '[' expression ']'
	| postfix_expression '(' ')'
	| postfix_expression '(' argument_expression_list ')'
	| postfix_expression '.' IDENTIFIER
	| postfix_expression PTR_OP IDENTIFIER
	| postfix_expression INC_OP
	| postfix_expression DEC_OP
	;

argument_expression_list
	: assignment_expression
	| argument_expression_list ',' assignment_expression
	;

unary_expression
	: postfix_expression
	| INC_OP unary_expression
	| DEC_OP unary_expression
	| unary_operator cast_expression
	| SIZEOF unary_expression
	| SIZEOF '(' type_name ')'
	;

unary_operator
	: '&'
	| '*'
	| '+'
	| '-'
	| '~'
	| '!'
	;

cast_expression
	: unary_expression
	| '(' type_name ')' cast_expression
	;

multiplicative_expression
	: cast_expression
	| multiplicative_expression '*' cast_expression
	| multiplicative_expression '/' cast_expression
	| multiplicative_expression '%' cast_expression
	;

additive_expression
	: multiplicative_expression
	| additive_expression '+' multiplicative_expression
	| additive_expression '-' multiplicative_expression
	;

shift_expression
	: additive_expression
	| shift_expression LEFT_OP additive_expression
	| shift_expression RIGHT_OP additive_expression
	;

relational_expression
	: shift_expression
	| relational_expression '<' shift_expression
	| relational_expression '>' shift_expression
	| relational_expression LE_OP shift_expression
	| relational_expression GE_OP shift_expression
	;

equality_expression
	: relational_expression
	| equality_expression EQ_OP relational_expression
	| equality_expression NE_OP relational_expression
	;

and_expression
	: equality_expression
	| and_expression '&' equality_expression
	;

exclusive_or_expression
	: and_expression
	| exclusive_or_expression '^' and_expression
	;

inclusive_or_expression
	: exclusive_or_expression
	| inclusive_or_expression '|' exclusive_or_expression
	;

logical_and_expression
	: inclusive_or_expression
	| logical_and_expression AND_OP inclusive_or_expression
	;

logical_or_expression
	: logical_and_expression
	| logical_or_expression OR_OP logical_and_expression
	;

conditional_expression
	: logical_or_expression
	| logical_or_expression '?' expression ':' conditional_expression
	;

assignment_expression
	: conditional_expression
	| unary_expression assignment_operator assignment_expression
	;

assignment_operator
	: '='
	| MUL_ASSIGN
	| DIV_ASSIGN
	| MOD_ASSIGN
	| ADD_ASSIGN
	| SUB_ASSIGN
	| LEFT_ASSIGN
	| RIGHT_ASSIGN
	| AND_ASSIGN
	| XOR_ASSIGN
	| OR_ASSIGN
	;

expression
	: assignment_expression
	| expression ',' assignment_expression
	;

constant_expression
	: conditional_expression
	;

declaration
	: declaration_specifiers ';'
	| declaration_specifiers init_declarator_list ';'
	;

declaration_specifiers
	: storage_class_specifier
	| storage_class_specifier declaration_specifiers
	| type_specifier
	| type_specifier declaration_specifiers
	| type_qualifier
	| type_qualifier declaration_specifiers
	;

init_declarator_list
	: init_declarator
	| init_declarator_list ',' init_declarator
	;

init_declarator
	: declarator
	| declarator '=' initializer
	;

storage_class_specifier
	: TYPEDEF
	| EXTERN
	| STATIC
	| AUTO
	| REGISTER
	;

type_specifier
	: VOID
	| CHAR
	| SHORT
	| INT
	| LONG
	| FLOAT
	| DOUBLE
	| SIGNED
	| UNSIGNED
	| struct_or_union_specifier
	| enum_specifier
	| TYPE_NAME
	;

struct_or_union_specifier
	: struct_or_union IDENTIFIER '{' struct_declaration_list '}'
	| struct_or_union '{' struct_declaration_list '}'
	| struct_or_union IDENTIFIER
	;

struct_or_union
	: STRUCT
	| UNION
	;

struct_declaration_list
	: struct_declaration
	| struct_declaration_list struct_declaration
	;

struct_declaration
	: specifier_qualifier_list struct_declarator_list ';'
	;

specifier_qualifier_list
	: type_specifier specifier_qualifier_list
	| type_specifier
	| type_qualifier specifier_qualifier_list
	| type_qualifier
	;

struct_declarator_list
	: struct_declarator
	| struct_declarator_list ',' struct_declarator
	;

struct_declarator
	: declarator
	| ':' constant_expression
	| declarator ':' constant_expression
	;

enum_specifier
	: ENUM '{' enumerator_list '}'
	| ENUM IDENTIFIER '{' enumerator_list '}'
	| ENUM IDENTIFIER
	;

enumerator_list
	: enumerator
	| enumerator_list ',' enumerator
	;

enumerator
	: IDENTIFIER
	| IDENTIFIER '=' constant_expression
	;

type_qualifier
	: CONST
	| VOLATILE
	;

declarator
	: pointer direct_declarator
	| direct_declarator
	;

direct_declarator
	: IDENTIFIER
	| '(' declarator ')'
	| direct_declarator '[' constant_expression ']'
	| direct_declarator '[' ']'
	| direct_declarator '(' parameter_type_list ')'
	| direct_declarator '(' identifier_list ')'
	| direct_declarator '(' ')'
	;

pointer
	: '*'
	| '*' type_qualifier_list
	| '*' pointer
	| '*' type_qualifier_list pointer
	;

type_qualifier_list
	: type_qualifier
	| type_qualifier_list type_qualifier
	;


parameter_type_list
	: parameter_list
	| parameter_list ',' ELLIPSIS
	;

parameter_list
	: parameter_declaration
	| parameter_list ',' parameter_declaration
	;

parameter_declaration
	: declaration_specifiers declarator
	| declaration_specifiers abstract_declarator
	| declaration_specifiers
	;

identifier_list
	: IDENTIFIER
	| identifier_list ',' IDENTIFIER
	;

type_name
	: specifier_qualifier_list
	| specifier_qualifier_list abstract_declarator
	;

abstract_declarator
	: pointer
	| direct_abstract_declarator
	| pointer direct_abstract_declarator
	;

direct_abstract_declarator
	: '(' abstract_declarator ')'
	| '[' ']'
	| '[' constant_expression ']'
	| direct_abstract_declarator '[' ']'
	| direct_abstract_declarator '[' constant_expression ']'
	| '(' ')'
	| '(' parameter_type_list ')'
	| direct_abstract_declarator '(' ')'
	| direct_abstract_declarator '(' parameter_type_list ')'
	;

initializer
	: assignment_expression
	| '{' initializer_list '}'
	| '{' initializer_list ',' '}'
	;

initializer_list
	: initializer
	| initializer_list ',' initializer
	;

statement
	: labeled_statement
	| compound_statement
	| expression_statement
	| selection_statement
	| iteration_statement
	| jump_statement
	;

labeled_statement
	: IDENTIFIER ':' statement
	| CASE constant_expression ':' statement
	| DEFAULT ':' statement
	;

compound_statement
	: '{' '}'
	| '{' statement_list '}'
	| '{' declaration_list '}'
	| '{' declaration_list statement_list '}'
	;

declaration_list
	: declaration
	| declaration_list declaration
	;

statement_list
	: statement
	| statement_list statement
	;

expression_statement
	: ';'
	| expression ';'
	;

selection_statement
	: IF '(' expression ')' statement
	| IF '(' expression ')' statement ELSE statement
	| SWITCH '(' expression ')' statement
	;

iteration_statement
	: WHILE '(' expression ')' statement
	| DO statement WHILE '(' expression ')' ';'
	| FOR '(' expression_statement expression_statement ')' statement
	| FOR '(' expression_statement expression_statement expression ')' statement
	;

jump_statement
	: GOTO IDENTIFIER ';'
	| CONTINUE ';'
	| BREAK ';'
	| RETURN ';'
	| RETURN expression ';'
	;

translation_unit
	: external_declaration
	| translation_unit external_declaration
	;

external_declaration
	: function_definition
	| declaration
	;

function_definition
	: declaration_specifiers declarator declaration_list compound_statement
	| declaration_specifiers declarator compound_statement
	| declarator declaration_list compound_statement
	| declarator compound_statement
	;

%%
#include <stdio.h>

extern char yytext[];
extern int column;

yyerror(s)
char *s;
{
	fflush(stdout);
	printf("\n%*s\n%*s\n", column, "^", column, s);
}

char *progname ;
int lineno = 1;
jmp_buf begin ;

/*-------------------------------------------------------------------------
**  MAIN     (pcalc.y)
*/

int     (*ptr_getchar)();
int     (*ptr_ungetc)();

FILE    *in_fp = NULL;

int     len;
char    buff[512];

FILE    *in_fp;

int     main(int argc, char *argv[])

{
    int     comm = 0, args;
    char    *env;

    args = parse_comline(argc, argv);

    progname = argv[0];

    if(!argv[1])
        {
        printf ("\nProgrammer's calculator by Peter Glen. Version 1.0\n\n");
        help_help();
        exit(0);
        }
    if(*argv[1] == 'f' && argv[1][1] == '\0')
        {
        funchelp();  exit(0);
        }
    if(*argv[1] == 'l' && argv[1][1] == '\0')
        {
        cbhelp();   exit(0);
        }
    if(*argv[1] == 'o' && argv[1][1] == '\0')
        {
        ophelp();   exit(0);
        }
    if(*argv[1] == 'c'&& argv[1][1] == '\0')
        {
        conshelp();   exit(0);
        }

    if(*argv[1] == '@' )
        {
        // we got file:

        yyin = fopen(&argv[1][1], "rt");
        if(!yyin)
            {
            printf("Cannot find file.\n");
            exit(0);
            }
        }
    else
        {
        // we got command line, write to a file, fake file:

        char    *commandline;
        int     len, cnt;

        for(cnt = args+1; cnt < argc; cnt++)
            {
            strcat(buff, argv[cnt]); strcat(buff, " ");
            }

        //printf("CMDLINE='%s'\n", buff);

        len = strlen(buff);
        yyin = fopen("pcalc.tmp", "w");

        if(!yyin)
            {
            execerror( "cannot create tmp file\n", NULL); exit(0);
            }
        fwrite(buff, len, 1, yyin);
        fputc('\n', yyin);
	//fputc(0x1a,  yyin);
        fclose(yyin);

        yyin = fopen("pcalc.tmp", "r");
        comm = 1;
        }

    init_sym() ;
    setjmp(begin) ;
    signal( SIGFPE, fpecatch) ;                /* Turbo-C uses "ssignal()" */
    yyparse() ;

    if(yyin)
        fclose(yyin);

    if(comm)
        unlink("pcalc.tmp");

    return 0 ;
}


/*-------------------------------------------------------------------------
**  EXECERROR
*/
void    execerror( char *s, char *t)
{
    warning( s, t) ;
    longjmp( begin, 0) ;
}

/*-------------------------------------------------------------------------
**  FPECATCH
*/
void    fpecatch( int aa)
{
    execerror("floating point exception", (char *) 0) ;
}

/*-------------------------------------------------------------------------
**  YYERROR
*/
void    yyerror( char *s)                      /* called by yacc syntax error */
{
    warning( s, (char *) 0) ;
    exit(0);
}

/*-------------------------------------------------------------------------
**  WARNING
*/

void    warning( char *s, char *t)
{
    fprintf( stderr, "%s: %s", progname, s) ;

    //fprintf( stderr, "pcalc WARNING: %s", s) ;

    if (t)
        fprintf( stderr, " %s", t) ;

    fprintf( stderr, " near line %d\n", lineno) ;
}

/*-------------------------------------------------------------------------*/


int     parse_comline(int argc, char *argv[])

{
    int i, j = 0;
    char *ptr;

    for(i=1; i < argc; ++i)
        {
        if (*argv[i] == '-')
            {
            switch(argv[i][1])
                {
                case 'S' :          /* quiet mode */
                case 's' :
                    fSilent = 1;
                    j++;
                    break;

                case 'B' :
                case 'b' :
                    fSilent = 1;
                    j++;
                    break;

                case 'v' :
                    printf (
                "\nProgrammer's calculator by Peter Glen. Version 1.0\n");
                    exit(0);
                    break;

                default:
                    // break on first non switch entry:
                    break;
                }
            }
        }
    return(j);
}

/* EOF */














