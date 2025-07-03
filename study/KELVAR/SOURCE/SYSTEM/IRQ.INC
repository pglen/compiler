
macro IRQ_enter
      { use16
	call	unreal:switch_real32
	use32 }

macro IRQ_leave
      { call	unreal:switch_real16
	use16
	iretw
	use32 }

set_IRQ:
; bl = IRQ number
; cs:dx - IRQ handler
	push	ds
	cmp	bl,8
	jae	.slave
      .master:
	mov	cl,bl
	add	bl,8			; IRQ 0-7 = INT 08-0F
	mov	ah,1
	shl	ah,cl
	not	ah
	in	al,21h
	and	al,ah
	out	21h,al
	jmp	.set_vector
      .slave:
	sub	bl,8
	mov	cl,bl
	add	bl,70h			; IRQ 8-F = INT 70-77
	mov	ah,1
	shl	ah,cl
	not	ah
	in	al,0A1h
	and	al,ah
	out	0A1h,al
      .set_vector:
	push	0
	pop	ds
	xor	bh,bh
	shl	bx,2
	cli
	mov	ax,cs
	xchg	[bx],dx
	xchg	[bx+2],ax
	push	interrupts
	pop	ds
	mov	[bx],dx
	mov	[bx+2],ax
	sti
	pop	ds
	ret

reset_IRQ:
; bl = IRQ number
	push	ds
	cmp	bl,8
	jae	.slave
      .master:
	mov	cl,bl
	add	bl,8			; IRQ 0-7 = INT 08-0F
	mov	ah,1
	shl	ah,cl
	mov	bh,[cs:IRQ_master_mask]
	and	bh,ah
	not	ah
	in	al,21h
	and	al,ah
	or	al,bh
	out	21h,al
	jmp	.reset_vector
      .slave:
	sub	bl,8
	mov	cl,bl
	add	bl,70h			; IRQ 8-F = INT 70-77
	mov	ah,1
	shl	ah,cl
	mov	bh,[cs:IRQ_slave_mask]
	and	bh,ah
	not	ah
	in	al,0A1h
	and	al,ah
	or	al,bh
	out	0A1h,al
      .reset_vector:
	push	interrupts
	pop	ds
	xor	bh,bh
	shl	bx,2
	cli
	mov	dx,[bx]
	mov	ax,[bx+2]
	push	0
	pop	ds
	mov	[bx],dx
	mov	[bx+2],ax
	sti
	pop	ds
	ret

IRQ_master_mask db ?			; stored master PIC IRQ mask
IRQ_slave_mask db ?			; stored slave PIC IRQ mask
