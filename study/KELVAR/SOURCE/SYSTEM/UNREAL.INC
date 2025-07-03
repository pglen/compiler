
; unREAL 32-bit mode server  version 1.02
; Copyright (c) 2000-2015, Tomasz Grysztar.
; All rights reserved.

segment unreal use16

init:
	mov	ax,7202h
	push	ax
	popf
	pushf
	pop	bx
	cmp	ax,bx
	je	processor_ok
	call	init_error
	db	'required 80386 or better',0
    processor_ok:
	smsw	ax
	test	al,1
	jz	mode_ok
	call	init_error
	db	'processor is in protected mode',0
    mode_ok:
	mov	eax,cs			; calculate linear address of GDT
	shl	eax,4
	or	dword [cs:real32_GDT+10],eax
	or	dword [cs:real16_GDT+10],eax
	add	[cs:real32_GDT_address],eax
	add	[cs:real16_GDT_address],eax
	cli
	lgdt	[cs:real32_GDTR]
	mov	eax,cr0
	or	al,1
	mov	cr0,eax
	jmp	1 shl 3:test_pm32
    no_rm32:
	sti
	call	init_error
	db	'processor is not able to enter 32-bit real mode',0
    test_pm32:
	use32
	mov	eax,cr0
	and	al,not 1
	mov	cr0,eax
	mov	ebx,0FFFFh
	jmp	unreal:test_rm32
    test_rm32:
	inc	ebx
	jz	short no_rm32
	lgdt	[cs:real16_GDTR]
	mov	eax,cr0
	or	al,1
	mov	cr0,eax
	jmp	1 shl 3:test_pm16
    test_pm16:
	use16
	mov	eax,cr0
	and	al,not 1
	mov	cr0,eax
	jmp	unreal:test_rm16
    test_rm16:
	sti

	mov	bx,400h+(100h*interrupt.size) shr 4
	mov	ah,48h
	int	21h
	jnc	mem_ok
	call	init_error
	db	'not enough conventional memory',0
    mem_ok:
	push	ds es
	mov	es,ax
	push	cs
	pop	ds
	movzx	eax,ax
	shl	eax,4
	mov	[real32_IDT_base],eax
	mov	dx,100h
	xor	bx,bx
	mov	di,400h
    init_interrupts:
	mov	si,interrupt
	mov	[si+interrupt.vector],bx
	mov	word [es:bx],di
	mov	word [es:bx+2],es
	mov	cx,interrupt.size
	rep	movsb
	add	bx,4
	dec	dx
	jnz	init_interrupts
	pop	es ds
	call	unreal:switch_real32
	use32
	retfw
	use16
    init_error:
	push	cs
	pop	ds
	mov	si,init_error_prefix
	mov	bl,0Ch
	call	.text
	pop	si
	mov	bl,4
	call	.text
      .finish:
	mov	si,init_error_suffix
	mov	bl,7
	call	.text
	mov	bx,7
	mov	cx,80
	mov	ax,920h
	int	10h
	mov	ax,4CFFh
	int	21h
      .text:
	xor	bh,bh
	mov	cx,1
      .display:
	lodsb
	or	al,al
	jz	.end
	cmp	al,0Dh
	je	.type
	cmp	al,0Ah
	je	.type
	mov	ah,9
	int	10h
      .type:
	mov	ah,0Eh
	int	10h
	jmp	.display
      .end:
	ret

switch_real32:
	pushfw
	push	eax
	push	word ds
	push	word es
	push	word fs
	push	word gs
	cli
	mov	eax,ss
	mov	cr3,eax
	lgdt	[cs:real32_GDTR]	; load GDT register
	mov	eax,cr0 		; switch to protected mode
	or	al,1
	mov	cr0,eax
	jmp	1 shl 3:pm32_start
    pm32_start:
	use32
	mov	ax,2 shl 3		; load 32-bit data descriptor
	mov	ds,ax			; to all data segment registers
	mov	es,ax
	mov	fs,ax
	mov	gs,ax
	mov	ss,ax
	mov	eax,cr0 		; switch back to real mode
	and	al,not 1
	mov	cr0,eax
	jmp	unreal:pm32_end
    pm32_end:
	mov	eax,cr3
	mov	ss,ax
	lidt	[cs:real32_IDTR]
	pop	word gs
	pop	word fs
	pop	word es
	pop	word ds
	pop	eax
	popfw
	retfw

switch_real16:
	pushfw
	push	eax
	cli
	lgdt	[cs:real16_GDTR]	; load GDT register
	mov	eax,cr0 		; switch to protected mode
	or	al,1
	mov	cr0,eax
	jmp	1 shl 3:pm16_start
    pm16_start:
	use16
	mov	eax,cr0 		; switch back to real mode
	and	al,not 1
	mov	cr0,eax
	jmp	unreal:pm16_end
    pm16_end:
	lidt	[cs:real16_IDTR]
	pop	eax
	popfw
	retfd
	use32

interrupt:
	call	unreal:switch_real16
	use16
	movzx	esp,sp
	push	word [esp+4]
	push	cs
	call	.real16
	pushfw
	pop	word [esp+4]
	call	unreal:switch_real32
	use32
	iretw
      .real16:
	use16
	push	eax
	push	ds
	xor	ax,ax
	mov	ds,ax
	mov	eax,[word 0]
	label	.vector word at $-2-interrupt
	pop	ds
	xchg	eax,[esp]
	retfw
      .size = $-interrupt

label real32_GDTR pword
real32_GDT_limit dw 3*8-1		; limit of GDT
real32_GDT_address dd real32_GDT	; linear address of GDT
real32_GDT rw 4 			; null descriptor
	   dw 0FFFFh,0,9A00h,0CFh	; 32-bit code descriptor
	   dw 0FFFFh,0,9200h,08Fh	; 4 GB data descriptor
label real16_GDTR pword
real16_GDT_limit dw 2*8-1		; limit of GDT
real16_GDT_address dd real16_GDT	; linear address of GDT
real16_GDT rw 4 			; null descriptor
	   dw 0FFFFh,0,9A00h,0		; 16-bit code descriptor

label real32_IDTR pword
real32_IDT_limit dw 3FFh
real32_IDT_base dd ?
label real16_IDTR pword
real16_IDT_limit dw 3FFh
real16_IDT_base dd 0

init_error_prefix db 'error: ',0
init_error_suffix db 0Dh,0Ah,0
