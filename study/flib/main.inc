; Using libc for assembly multiplatform programming
; This file is platform-independent code of application

; Do not compile this file directly. It is included from "flibcw.asm" and
; "flibcl.asm". Compile those instead.

	; write welcome text and prompt text
	; puts("Hello\nPlease type a number: ")
	push	_hello
	call	puts
	add	esp, 4

	; read number
	; scanf("%d", &num1)
	push	num1
	push	_format_input
	call	scanf
	add	esp, 8

	; error if we failed to read the number
	; scanf returns number of things it has readen
	cmp	eax, 1
	jne	error

	; write prompt   for another number
	push	_prompt2
	call	puts
	add	esp, 4

	; read another number
	; scanf("%d", &num2)
	push	num2
	push	_format_input
	call	scanf
	add	esp, 8

	; error if we failed to read the number
	; scanf returns number of things it has readen
	cmp	eax, 1
	jne	error

	; calculate average of numbers
	mov	eax, [num1]
	add	eax, [num2]
	shr	eax, 1

	; display the average
	; printf("Average of numbers is %d\n", eax)
	push	eax
	push	_format_output
	call	printf
	add	esp, 8

	; exit(0)
	push	0
	call	exit

error:
	; display error
	; puts("Error!\n")
	push	_error
	call	puts
	add	esp, 4

	; exit(-1)
	push	-1
	call	exit
