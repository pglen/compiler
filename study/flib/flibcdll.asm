; Using libc for assembly multiplatform programming
; win32 platform dynamically linked to libc

; Compile with FASM:
;       fasm.exe flibcdll.asm flibcdll.exe
; no linking needed

format PE

; entry point is function main
entry main

; wrappers for imported functions from libc
printf: jmp    [imp_printf]
puts:	jmp    [imp_puts]
scanf:	jmp    [imp_scanf]
exit:	jmp    [imp_exit]

; code section
section '.text' code readable executable

main:	include 'main.inc'

; data section
section '.data' data readable writeable
	include 'data.inc'

; import functions from MS implementation of libc, in MSVCRT.DLL (MicroSoft Visual C Run-Time)
section '.idata' data import readable

include "macro\import32.inc"

library msvcrt, "MSVCRT.DLL"

import msvcrt,\
       imp_printf ,'printf',\
       imp_puts   ,'puts',\
       imp_scanf  ,'scanf',\
       imp_exit   ,'exit'



;by vid  (vid@inMail.sk)
;see: http://flatassembler.net
;discuss assembly on: http://board.flatassembler.net