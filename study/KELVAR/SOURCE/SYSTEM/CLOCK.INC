
clock_IRQ:
	IRQ_enter
	push	eax ds
	mov	ax,main_data
	mov	ds,ax
	inc	[clock]
	mov	al,20h			; give finishing information
	out	20h,al			; to interrupt controller
	pop	ds eax
	IRQ_leave

init_clock:
	mov	[clock],0
	xor	bl,bl
	mov	dx,clock_IRQ
	call	set_IRQ
	ret

set_clock_frequency:
; ax = number of ticks per second
	movzx	ebx,ax
	mov	eax,1193180
	xor	edx,edx
	div	ebx
	mov	ebx,eax
	mov	al,36h
	out	43h,al
	mov	al,bl
	out	40h,al
	mov	al,bh
	out	40h,al
	ret

reset_clock:
	cli
	mov	al,36h			; reset interrupt timer
	out	43h,al
	xor	al,al
	out	40h,al
	out	40h,al
    set_time:				; set correct system time
	mov	ah,2
	int	1Ah
	mov	al,ch
	call	convert_BCD
	mov	ch,al
	mov	al,cl
	call	convert_BCD
	mov	cl,al
	mov	al,dh
	call	convert_BCD
	mov	dh,al
	mov	ah,2Dh
	int	21h
    set_date:				; set correct system date
	mov	ah,4
	int	1Ah
	mov	al,cl
	call	convert_BCD
	mov	cl,al
	mov	al,ch
	call	convert_BCD
	mov	ch,100
	mul	ch
	xor	ch,ch
	add	cx,ax
	mov	al,dh
	call	convert_BCD
	mov	dh,al
	mov	al,dl
	call	convert_BCD
	mov	dl,al
	mov	ah,2Bh
	int	21h
	xor	bl,bl
	call	reset_IRQ
	sti
	ret
    convert_BCD:
	mov	bh,al
	and	bh,1111b
	shr	al,4
	mov	bl,10
	mul	bl
	add	al,bh
	ret
