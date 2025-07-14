#--------------------------------------------------------------------------
# Makefile for pcomp

.PHONY: examples clean

all:
	make -C src

git:
	git add .
	git commit -m autocommit
	git push

clean:
	#find . -type f -name "*.o" -exec rm {} \;
	make -C src clean
	rm -f examples/*.run    rm -f examples/*.o
	rm -f examples/*.bin 	rm -f examples/*.asm
	rm -f prepro/*.run      rm -f prepro/*.o
	rm -f prepro/*.bin     rm -f prepro/*.asm

examples:
	make -C src examples

# EOF
