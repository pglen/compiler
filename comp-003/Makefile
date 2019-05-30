#--------------------------------------------------------------------------
# Makefile for pcomp
# Uncomment debug macros before delivery

#CC = gcc

# Debug
CC = gcc -g -nodefaultlibs
CC = gcc -g

YACC = bison -y
BISON = bison -v
LEX = flex

#LDFLAGS = -s -v
LDFLAGS =

LIBS = -lm -lrt -lm

# Debug
#LIBS = -Wl,--no-as-needed -lefence -lm -lrt -lc
LIBS = -lefence -lm -lrt -lc -lpthread -l/lib/ld-linux.so.2 \
# -llinux-gate.so.1

# Debug
#CFLAGS =  -DSETPROCTITLE -Wformat=no

CFLAGS =  -Wformat=no

DEPENDSON = symtab.c symtab.h codegen.c codegen.h emalloc.c emalloc.h \
			 Makefile

#all: pcomp

pcomp: pcomp.y pcomp.f ${DEPENDSON}
	${BISON} -p conf pcomp.y
	${LEX} -Pconf -opcomp.c pcomp.f
	${CC} ${CFLAGS} codegen.c -c -o codegen.o
	${CC} ${CFLAGS} pmath.c -c -o pmath.o
	${CC} ${CFLAGS} symtab.c -c -o symtab.o
	${CC} ${CFLAGS} emalloc.c -c -o emalloc.o
	${CC} ${CFLAGS} ${LIBS} ${LDFLAGS} pcomp.c -o pcomp symtab.o \
				emalloc.o codegen.o pmath.o

clean:
	rm -f *.o  pcomp.c pcomp.tab.c core \#* pcomp

