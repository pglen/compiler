#if 0
[`@#$%^&\*-_=\[\]:;'?><,\.\\]   {  /* Separator */
	#ifdef DEBUGLEX
                                if(testflex)
                                	printf("[SEP] '%s' ", (char*)yytext);
	#endif
                                }
#endif


sp1mb STR2 sp1mb
            {
            printf("msg1 STR '%s'\n", $2->var);
            Symbol  *st2 = make_symstr("", $2->var, STR2);
            $$ = st2;
            }
        | sp1mb NUM2 sp1mb
            {
            printf("msg1 NUM '%s'\n", $2->var);
            $$=$2;
            }


/* <STRSTATE>\\                 {
                                if(config.testpreflex)
                                    printf("STRSTATE \\");
                                tmp_str2[prog++] = yytext[0];
                                backslash++;
                                }
*/

STR2 sp1mb
            {
            printf("strx1 '%s'\n", $1->var);
            //dump_symitem($1);
            //Symbol *ss = make_symstr("", $1->var, STR2);
            //$$->var = $1->var;
            //$$->var = $1->var;
            $$ = $1;
            }

adder:  NUM2 sp1mb PLUS2 sp1mb NUM2
        {
        int val = str2int($1->var) + str2int($5->var);
        char *numx = xmalloc(24);
        sprintf(numx, "%d",val);
        Symbol *ss = make_symstr("", numx, NUM2);
        printf("adder: %s %s -> %s",  $1->var, $5->var, numx);
        $$ = ss;
        }
      | adder sp1mb PLUS2 sp1mb NUM2
        {
        int val = str2int($1->var) + str2int($5->var);
        char *numx = xmalloc(24);
        sprintf(numx, "%d",val);
        Symbol *ss = make_symstr("", numx, NUM2);
        printf("adder2: %s %s -> %s",  $1->var, $5->var, numx);
        $$ = ss;
        }
;

expr4:  expr5
    {
    //if(config.testpreyacc > 0)
    //    printf("{ expr4 '%s' } \n", $1->var);
    }
    | sp1mb PAREN12 sp1mb expr1 sp1mb PAREN22 sp1mb
        {
        //if(config.testpreyacc > 0)
        //    printf("{ paren: expr4 '%s}' ", (char*)$4);
        $$ = make_symstr("", $4->var, NUM2);
        //$$ = $4;
        }
    | sp1m MINUS2 sp1mb expr5
        {
        int val = str2int($4->var);
        sprintf(tmp_str3, "%d", -val);
        $$ = make_symstr("", strdup(tmp_str3), NUM2);
        }
;
| MSG2 sp1mb expr1 sp1mb semib
            {
            if(config.testpreyacc > 0)
                printf(" { msg1: numx1 '%s' } ", $3->var);
            printf("%s\n", $3->var);
            }
;

| expr1 sp1mb PLUS2 sp1mb strx1 sp1mb
            {
            //printf("msg add' %s' '%s'\n", (char*)$1->var, (char*)$5->var);
            char *sum = addstrs($1->var, $5->var);
            //printf("sum: '%s'\n", sum);
            Symbol *ss = make_symstr("", sum, STR2);
            $$ = ss;
            }

 | sp1mb MINUS2 sp1mb expr5
        {
        int val = str2int($4->var);
        sprintf(tmp_str3, "%d", -val);
        $$ = make_symstr("", strdup(tmp_str3), NUM2);
        }

| sp1mb
        {
        if(config.testpreyacc > 0)
            printf("{ all2 blank '%s' }\n", (char*)$1->var);
        }

all2
        {
        if(config.testpreyacc > 0)
            printf(" { all2 root '%s' }\n ", (char*)$1->var);
        }
        |

| NL2
        {
        if(config.testpreyacc > 0)
            printf("{ all2 newline '%s' }\n", (char*)$1->var);
        }
#%nl
# %msg 1234 + 1111 %msg " Stand tall." %nl
# %msg (5+10) * 2 / 4  %msg " Hello" %nl

