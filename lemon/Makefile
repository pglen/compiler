


all:
	./lemon example1.y
	flex example1.l
	cat main.c >> example1.c
	gcc example1.c lex.yy.c -o example1

