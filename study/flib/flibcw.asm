; Using libc for assembly multiplatform programming
; win32 platform linked to libc

; Compile with FASM:
;       fasm.exe flibcw.asm flibcw.obj
; Statically Link with MS Link:
;       link.exe flibcw.obj libcmt.obj
; libcmt.obj is redistributable file of MS Visual Studio and other MS products
; you may need also MSPDB**.DLL and KERNEL32.LIB

; you can also link this dynamically to MSVCRT.DLL (Microsoft Visual C Run-Time)
;       link.exe flibcw.obj msvcrt.lib
; again, you will need MSPDB**.DLL and KERNEL32.LIB, and also MSVCR**.DLL to run the file

format MS COFF

; export symbol "_main", which is entry point from libc
public main as '_main'

; import functions from libc
extrn '__errno'  as _errno
extrn '_printf' as printf
extrn '_puts'	as puts
extrn '_scanf'	as scanf
extrn '_exit'	as exit


; code section
section '.text' code readable executable

	main:
	include 'main.inc'


; data section
section '.data' data readable writeable
	include 'data.inc'



;by vid  (vid@inMail.sk)
;see: http://flatassembler.net
;discuss assembly on: http://board.flatassembler.net