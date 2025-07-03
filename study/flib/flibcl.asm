; Using libc for assembly multiplatform programming
; linux platform dynamically linked to libc

; Compile with:
;       fasm flibcl.asm flibcw.o
; Link with:
;       ld -lc -e main -dynamic-linker /lib/ld-linux.so.2 flibcl.o -o flibcl

format ELF

; export symbol "main", which is name used as entry point of application
public main as 'main'

; import functions from libc
extrn 'printf'	as printf
extrn 'puts'	as puts
extrn 'scanf'	as scanf
extrn 'exit'	as exit

; code section
section '.text' executable

	;include platform-independent code
	main:
	include 'main.inc'


; data section
section '.data' writeable

	;include platform-independent data
	include 'data.inc'



;by vid  (vid@inMail.sk)
;see: http://flatassembler.net
;discuss assembly on: http://board.flatassembler.net