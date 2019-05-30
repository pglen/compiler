# Makefile

example5: example5.c  lex.yy.o
	g++ example5.c lex.yy.o -o example5

example5.c: example5.y
	../lemon example5.y
	cat main_part5 >> example5.c

lex.yy.o: lexer.l
	flex lexer.l
	gcc -c lex.yy.c -o lex.yy.o


clean:
	rm -f *.o ; rm -f example5.c

test:
	@echo "Awaiting implentation"
