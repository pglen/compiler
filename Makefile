# Compiler studies

all:
	@echo Targets: git help

help:
	@echo Help ...

git:
	git add .
	git commit -m autocheck

clean:
	find -type f -name "*.o" -exec rm {} \;
