
#-noprint-search-dirs

CC = gcc
YACC = bison -y
BISON = bison -v
LEX = flex

#CFLAGS =  -DSETPROCTITLE -Wformat=no
#LDFLAGS = -s -v
CFLAGS =  -Wformat=no

DEPENDSON = symtab.c symtab.h codegen.c codegen.h

#all: pcomp

pcomp: pcomp.y pcomp.f ${DEPENDSON}
	${BISON} -p conf pcomp.y
	${LEX} -Pconf -opcomp.c pcomp.f
	${CC} ${CFLAGS} codegen.c -c -o codegen.o
	${CC} ${CFLAGS} symtab.c -c -o symtab.o
	${CC} ${CFLAGS} pcomp.c -o pcomp symtab.o codegen.o -lm

clean:
	rm -f *.o  pcomp.c pcomp.tab.c core \#*


