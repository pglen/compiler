
macro delay nms
 {
	mov	ah,86h
	if	nms < 10000h
	xor	cx,cx
	else
	mov	cx,nms shr 16
	end if
	mov	dx,nms and 0FFFFh
	int	15h
 }

init_console:
	mov	ah,0Fh
	int	10h
	cmp	al,3
	je	.text
	mov	ax,3
	int	10h
      .text:
	mov	[console_status],1
	push	ds cs
	pop	ds
	mov	esi,_logo
	mov	bl,0Ah
	call	display_text
	mov	esi,_version
	mov	bl,2
	call	display_text
	mov	esi,cr_lf
	mov	bl,7
	call	display_text
	pop	ds
	ret

close_console:
	cmp	[console_status],0
	je	short .ok
	push	ds es
	push	console_screen
	pop	es
	xor	edi,edi
	push	0B800h
	pop	ds
	xor	esi,esi
	mov	ecx,1000h
	rep	movsd
	pop	es ds
	mov	ah,3
	xor	bh,bh
	int	10h
	mov	[console_cursor],dx
	mov	[console_status],0
	mov	edi,palette
	call	get_palette
	mov	esi,palette
	call	fade_out
      .ok:
	ret

open_console:
	cmp	[console_status],1
	je	short .ok
	mov	ax,3
	int	10h
	mov	edi,palette
	call	get_palette
	call	clear_palette
	push	ds es
	push	console_screen
	pop	ds
	xor	esi,esi
	push	0B800h
	pop	es
	xor	edi,edi
	mov	ecx,1000h
	rep	movsd
	pop	es ds
	mov	ah,2
	xor	bh,bh
	mov	dx,[console_cursor]
	int	10h
	mov	[console_status],1
	mov	esi,palette
	call	fade_in
      .ok:
	ret

return_console:
	call	open_console
	mov	bx,7
	mov	cx,80
	mov	ax,920h
	int	10h
	ret

display_character:
; al = character
; bl = color
	xor	bh,bh
	mov	cx,1
	mov	ah,9
	int	10h
	mov	ah,0Eh
	int	10h
	ret
display_text:
; ds:esi - text
; bl = color
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
display_number:
; eax = number
; bl - color
	mov	ecx,1000000000
	xor	edx,edx
	xor	bh,bh
	xor	ebp,ebp
      .loop:
	div	ecx
	push	edx
	cmp	ecx,1
	je	.digit
	or	ebp,ebp
	jnz	.digit
	or	al,al
	jz	.digit_ok
	not	ebp
      .digit:
	push	ecx
	add	al,30h
	mov	ah,9
	mov	cx,1
	int	10h
	mov	ah,0Eh
	int	10h
	pop	ecx
	cmp	ecx,1000
	je	.comma
	cmp	ecx,1000000
	je	.comma
	cmp	ecx,1000000000
	je	.comma
	jmp	.digit_ok
      .comma:
	push	eax ecx
	mov	ax,900h + ','
	mov	cx,1
	int	10h
	mov	ah,0Eh
	int	10h
	pop	ecx eax
      .digit_ok:
	mov	eax,ecx
	xor	edx,edx
	mov	ecx,10
	div	ecx
	mov	ecx,eax
	pop	eax
	or	ecx,ecx
	jnz	.loop
	ret
display_hex:
; eax = number
; bl = color
	push	ds cs
	pop	ds
	mov	esi,eax
	xor	ebp,ebp
	mov	cl,28
      .loop:
	shr	eax,cl
	and	eax,0Fh
	or	cl,cl
	jz	.digit
	or	ebp,ebp
	jnz	.digit
	or	al,al
	jz	.digit_ok
	not	ebp
      .digit:
	push	ebx
	mov	ebx,hex_digits
	xlatb
	pop	ebx
	push	ecx
	mov	ah,9
	mov	cx,1
	int	10h
	mov	ah,0Eh
	int	10h
	pop	ecx
      .digit_ok:
	mov	eax,esi
	sub	cl,4
	jnc	.loop
	pop	ds
	ret

startup_messages:
	push	ds cs
	pop	ds
	push	main_data
	pop	es
	mov	esi,_extended_memory
	mov	bl,9
	call	display_text
	mov	eax,[es:memory_end]
	sub	eax,[es:memory_start]
	shr	eax,10
	mov	bl,1
	call	display_number
	mov	al,'K'
	mov	bl,1
	call	display_character
	mov	esi,cr_lf
	mov	bl,7
	call	display_text
	cmp	[es:sound_card],1
	je	.sound_blaster
	jmp	.done
      .sound_blaster:
	mov	esi,_sound_blaster
	mov	bl,9
	call	display_text
	mov	esi,_sb_port
	mov	bl,1
	call	display_text
	movzx	eax,[es:SB_port]
	call	display_hex
	mov	esi,_sb_irq
	call	display_text
	movzx	eax,[es:SB_IRQ]
	call	display_number
	mov	esi,_sb_dma
	call	display_text
	movzx	eax,[es:SB_DMA]
	call	display_number
	mov	esi,cr_lf
	mov	bl,7
	call	display_text
      .done:
	pop	ds
	ret

error:
	call	.prepare
	pop	esi
	mov	bl,4
	call	display_text
	jmp	.finish
      .prepare:
	push	main_data
	pop	ds
	call	open_console
	push	cs
	pop	ds
	mov	esi,error_prefix
	mov	bl,0Ch
	call	display_text
	ret
      .file:
	call	.prepare
	pop	esi
	mov	bl,4
	call	display_text
	push	main_data
	pop	ds
	mov	esi,file_path
	mov	bl,4
	call	display_text
	push	cs
	pop	ds
      .finish:
	mov	esi,cr_lf
	mov	bl,7
	call	display_text
	jmp	exit_program

no_extended_memory:
	call	error
	db	'extended memory unavailable',0
out_of_dos_memory:
	call	error
	db	'not enough free conventional memory',0
out_of_memory:
	call	error
	db	'out of memory',0
video_error:
	call	error
	db	'could not set video mode',0
file_error:
	call	error.file
	db	'cannot load file ',0

error_prefix db 'error: ',0
cr_lf db 0Dh,0Ah,0
hex_digits db '0123456789ABCDEF'

_logo db 'kelvar unREAL engine: ',0
_version db 'version 0.2.4',0
_extended_memory db 'available extended memory: ',0
_sound_blaster db 'sound blaster detected: ',0
_sb_port db 'port ',0
_sb_irq db ', IRQ ',0
_sb_dma db ', DMA ',0
