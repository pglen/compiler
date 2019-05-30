
%include {
//#include <iostream>

#include <stdlib.h>
#include "example1.h"
#include "extdef.h"

}

%token_type {Token}
%default_type {Token}

%left PLUS MINUS.
%left DIVIDE TIMES.

%syntax_error {
   //std::cout << "Syntax error!" << std::endl;
   printf("Syntax error!");
 }

 program ::= expr(A).   {
            //std::cout << "Result=" << A << std::endl;
            printf("Result %d\n", A);
             }

 expr(A) ::= expr(B) MINUS  expr(C).   { A = B - C; }
 expr(A) ::= expr(B) PLUS  expr(C).   { A = B + C; }
 expr(A) ::= expr(B) TIMES  expr(C).   { A = B * C; }
 expr(A) ::= expr(B) DIVIDE expr(C).  {


          if(C != 0){
            A = B / C;
           }else{
            //std::cout << "divide by zero" << std::endl;
            printf("divide by zero\n");
            }
    }  /* end of DIVIDE */


 expr(A) ::= INTEGER(B). { A = B; }



