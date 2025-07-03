#--------------------------------------------------------------------------
# Makefile for pcomp

all:
	make -C src

git:
	git add .
	git commit -m autocommit
	git push

clean:
	#find . -type f -name "*.o" -exec rm {} \;
	make -C src clean
	rm -f tests/*.
	rm -f tests/*.o
	rm -f tests/*.bin
	rm -f tests/*.asm

test:
	make -C src test


