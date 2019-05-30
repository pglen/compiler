
#-noprint-search-dirs

CC = gcc
YACC = bison -y
BISON = bison
LEX = flex

#CFLAGS =  -DSETPROCTITLE -Wformat=no 
#LDFLAGS = -s -v
CFLAGS =  -Wformat=no 

#all: pcomp
	
pcomp: pcomp.y pcomp.f symtab.c symtab.h
	${BISON} -p conf pcomp.y
	${LEX} -Pconf -opcomp.c pcomp.f
	${CC} ${CFLAGS} symtab.c -c -o symtab.o
	${CC} ${CFLAGS} pcomp.c -o pcomp symtab.o -lm

clean:
	rm -f *.o  pcomp.c pcomp.tab.c core \#*


