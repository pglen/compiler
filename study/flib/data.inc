; Using libc for assembly multiplatform programming
; This file is platform-independent data definitions

; Do not compile this file directly. It is included from "flibcw.asm" and
; "glibcl.asm". Compile those instead.


; initialized data first
_hello		   db "Hello",10,"Please type a number: ",0
_prompt2	   db "Type another number: ",0
_format_input	   db "%d",0
_format_output	   db "Average of numbers is %d",10,0
_error		   db "Error!",10,0

; uninitialized data at the end
num1 dd ?
num2 dd ?