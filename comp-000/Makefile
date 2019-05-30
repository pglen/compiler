# If you do not have the shadow-3.3.1 package installed do:
# - remove "-DSHADOW_PWD" in this Makefile
# - remove "-lshadow" in this Makefile

CC = gcc
CFLAGS = -O2 -fomit-frame-pointer -m486 \
	-include /usr/include/bsd/bsd.h -I/usr/include/bsd \
	-include ftphack.h -DSETPROCTITLE -I../ftp
YACC = bison -y
BISON = bison
LEX = flex
LDFLAGS = -s -v
LDLIBS = -lbsd
OBJS =  config.o

all: showconfig

config.o: config.y config.f
	${BISON} -p conf config.y
	${LEX} -Pconf -oconfig.c config.f
	${CC} config.c -c -o $@

install: ftpd
	install -m755 ftpd /usr/sbin/in.ftpd
	install -m644 ftpd.8 /usr/man/man8

clean:
	rm -f *.o ftpd showconfig config.c core \#*

#useful tool for testing what ftp will do

showconfig: config.y config.f
	bison -p conf config.y
	flex -Pconf -oconfig.c config.f
	gcc -D TEST config.c -o $@

#please use this one with care, overwrites old FTPD

copy:
	cp ftpd /usr/sbin/in.ftpd

