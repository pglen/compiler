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

