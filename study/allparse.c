 #include <stdio.h>
 #include <string.h>
 #include <ctype.h>
 #include <stdlib.h>

 #define MAXTOKENS 100
 #define MAXTOKENLEN 64

 enum type_tag { IDENTIFIER, QUALIFIER, TYPE };

 struct token {
 char type;
 char string[MAXTOKENLEN];
 };

 int top=-1;
 struct token stack[MAXTOKENS];
 struct token this;

 #define pop stack[top--]
 #define push(s) stack[++top]=s

/* figure out the identifier type */
enum type_tag classify_string(void)
{
     char *s = this.string;
     if (!strcmp(s,"const")) {
     strcpy(s,"read-only");
     return QUALIFIER;
     }
     if (!strcmp(s,"volatile")) return QUALIFIER;
     if (!strcmp(s,"void")) return TYPE;
     if (!strcmp(s,"char")) return TYPE;
     if (!strcmp(s,"signed")) return TYPE;
     if (!strcmp(s,"unsigned")) return TYPE;
     if (!strcmp(s,"short")) return TYPE;
     if (!strcmp(s,"int")) return TYPE;
     if (!strcmp(s,"long")) return TYPE;
     if (!strcmp(s,"float")) return TYPE;
     if (!strcmp(s,"double")) return TYPE;
     if (!strcmp(s,"struct")) return TYPE;
     if (!strcmp(s,"union")) return TYPE;
     if (!strcmp(s,"enum")) return TYPE;
     return IDENTIFIER;
}

void gettoken() /* read next token into "this" */
{
     char *p = this.string;

     /* read past any spaces */
     while ((*p = getchar()) == ' ' ) ;

     if (isalnum(*p)) {
         /* it starts with A-Z,0-9 read in identifier */

         while ( isalnum(*++p=getchar()) );
         ungetc(*p,stdin);
         *p = '\0';
         this.type=classify_string();
         return;
        }

     if (*p=='*') {
         strcpy(this.string,"pointer to");
         this.type = '*';
         return;
         }
     this.string[1]= '\0';
     this.type = *p;
}


 /* The piece of code that understandeth all parsing. */

void  read_to_first_identifier() {
    gettoken();
    while (this.type!=IDENTIFIER) {
        push(this);
        gettoken();
    }
    printf("%s is ", this.string);
    gettoken();
 }

void deal_with_arrays() {
    while (this.type=='[') {
        printf("array ");
        gettoken(); /* a number or ']' */
        if (isdigit(this.string[0])) {
            printf("0..%d ",atoi(this.string)-1);
            gettoken(); /* read the ']' */
        }
    gettoken(); /* read next past the ']' */
    printf("of ");
    }
 }

 void deal_with_function_args() {
     while (this.type!=')') {
         gettoken();
         }
     gettoken();
     printf("function returning ");
}

 void deal_with_pointers() {
     while ( stack[top].type== '*' ) {
     printf("%s ", pop.string );
     }
 }

 /* deal with possible array/function following
 identifier */

void deal_with_declarator() {
     switch (this.type) {
     case '[' : deal_with_arrays(); break;
     case '(' : deal_with_function_args();
     }

    deal_with_pointers();

 /* process tokens that we stacked while reading identifier */
 while (top>=0) {
     if (stack[top].type == '(' ) {
         pop;
         gettoken(); /* read past ')' */
         deal_with_declarator();
         } else {
         printf("%s ",pop.string);
         }
     }
}

int main(int argc, char *argv[])

{
     /* put tokens on stack until we reach identifier */
     read_to_first_identifier();
     deal_with_declarator();
     printf("\n");
     return 0;
}

