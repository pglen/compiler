
set_VGA_mode:
	mov	ax,13h
	int	10h
	mov	[video_pitch],320
	mov	[video_width],320
	mov	[video_height],200
	mov	[video_window],0
	mov	[video_granularity],0
	mov	[video_linear],0A0000h
	clc
	ret

set_VESA_mode:
; ax = mode number
	push	eax
	mov	ecx,eax
	or	ecx,4000h
	mov	di,mode_info
	mov	ax,4F01h
	int	10h
	pop	ebx
	or	ah,ah
	jnz	.banked
	or	ebx,4000h
	mov	eax,4F02h
	int	10h
	or	ah,ah
	jnz	.error
	movzx	eax,word [mode_info+10h]
	mov	[video_pitch],eax
	movzx	eax,word [mode_info+12h]
	mov	[video_width],eax
	movzx	eax,word [mode_info+14h]
	mov	[video_height],eax
	mov	eax,dword [mode_info+28h]
	mov	[video_linear],eax
	mov	[video_granularity],0
	clc
	ret
      .banked:
	mov	ecx,ebx
	push	ecx
	mov	di,mode_info
	mov	ax,4F01h
	int	10h
	pop	ebx
	or	ah,ah
	jnz	.error
	mov	ax,4F02h
	int	10h
	or	ah,ah
	jnz	.error
	cmp	word [mode_info+6],64
	jne	.error
	xor	bx,bx
	xor	dx,dx
	mov	ax,4F05h
	int	10h
	mov	ax,64
	xor	dx,dx
	div	word [mode_info+4]
	mov	[video_granularity],ax
	mov	[video_window],0
	movzx	eax,word [mode_info+10h]
	mov	[video_pitch],eax
	movzx	eax,word [mode_info+12h]
	mov	[video_width],eax
	movzx	eax,word [mode_info+14h]
	mov	[video_height],eax
	mov	eax,dword [mode_info+0Ch]
	mov	[video_window_select],eax
	clc
	ret
      .error:
	stc
	ret

set_palette:
; esi - palette
	mov	dx,3C8h
	xor	al,al
	out	dx,al
	inc	dl
	mov	ecx,768
      .palette:
	lodsb
	shr	al,2
	out	dx,al
	loop	.palette
	ret

get_palette:
; es:edi - buffer for palette
	mov	dx,3C7h
	xor	al,al
	out	dx,al
	add	dl,2
	mov	ecx,768
      .palette:
	in	al,dx
	shl	al,2
	stosb
	loop	.palette
	ret

wait_for_retrace:
	mov	dx,3DAh
      .retrace:
	in	al,dx
	test	al,1000b
	jnz	.retrace
      .wait:
	in	al,dx
	test	al,1000b
	jz	.wait
	ret

clear_palette:
	mov	dx,3C8h
	xor	al,al
	out	dx,al
	inc	dl
	mov	ecx,768
	xor	al,al
      .palette:
	out	dx,al
	loop	.palette
	ret

fade_in:
; esi - palette
	xor	bx,bx
      .fade:
	mov	dx,3C8h
	xor	al,al
	out	dx,al
	mov	dx,3C9h
	mov	ecx,768
	mov	edi,esi
      .palette:
	lodsb
	shr	al,2
	xor	ah,ah
	imul	ax,bx
	shr	ax,4
	out	dx,al
	loop	.palette
	call	wait_for_retrace
	delay	50000
	mov	esi,edi
	inc	bl
	cmp	bl,16
	jbe	.fade
	ret

fade_out:
; esi - palette
	mov	bx,16
      .fade:
	mov	dx,3C8h
	xor	al,al
	out	dx,al
	mov	dx,3C9h
	mov	ecx,768
	mov	edi,esi
      .palette:
	lodsb
	shr	al,2
	xor	ah,ah
	imul	ax,bx
	shr	ax,4
	out	dx,al
	loop	.palette
	call	wait_for_retrace
	delay	50000
	mov	esi,edi
	sub	bl,1
	jnc	.fade
	ret

clip:
; eax = x, ebx = width
; ecx = y, edx = height
; esi - source
; edi - destination
	cmp	eax,0
	jge	.x_ok
	neg	eax
	sub	ebx,eax
	jc	.nothing
	jz	.nothing
	add	esi,eax
	xor	eax,eax
      .x_ok:
	cmp	ecx,0
	jge	.y_ok
	neg	ecx
	sub	edx,ecx
	jc	.nothing
	jz	.nothing
	imul	ecx,[source_pitch]
	add	esi,ecx
	xor	ecx,ecx
      .y_ok:
	add	ebx,eax
	cmp	ebx,[destination_width]
	jbe	.width_ok
	mov	ebx,[destination_width]
      .width_ok:
	sub	ebx,eax
	jc	.nothing
	jz	.nothing
	add	edx,ecx
	cmp	edx,[destination_height]
	jbe	.height_ok
	mov	edx,[destination_height]
      .height_ok:
	sub	edx,ecx
	jc	.nothing
	jz	.nothing
	mov	ebp,[destination_pitch]
	imul	ebp,ecx
	add	edi,ebp
	add	edi,eax
	ret
      .nothing:
	xor	ebx,ebx
	xor	edx,edx
	ret

blit:
	or	edx,edx
	jz	.done
	xor	eax,eax
      .blit:
	mov	ecx,ebx
      .line:
	lodsb
	or	al,al
	jz	.transparent
	stosb
	loop	.line
	jmp	.next
      .transparent:
	inc	edi
	loop	.line
      .next:
	mov	eax,[source_pitch]
	sub	eax,ebx
	add	esi,eax
	mov	eax,[destination_pitch]
	sub	eax,ebx
	add	edi,eax
	dec	edx
	jnz	.blit
      .done:
	ret

fast_blit:
	or	edx,edx
	jz	.done
      .blit:
	mov	ecx,ebx
	shr	ecx,2
	rep	movsd
	mov	ecx,ebx
	and	ecx,11b
	rep	movsb
	mov	eax,[source_pitch]
	sub	eax,ebx
	add	esi,eax
	mov	eax,[destination_pitch]
	sub	eax,ebx
	add	edi,eax
	dec	edx
	jnz	.blit
      .done:
	ret

video_blit:
; eax = x, ebx = width
; ecx = y, edx = height
; esi - source
	cmp	eax,0
	jge	.x_ok
	neg	eax
	sub	ebx,eax
	jc	.nothing
	jz	.nothing
	add	esi,eax
	xor	eax,eax
      .x_ok:
	cmp	ecx,0
	jge	.y_ok
	neg	ecx
	sub	edx,ecx
	jc	.nothing
	jz	.nothing
	imul	ecx,[source_pitch]
	add	esi,ecx
	xor	ecx,ecx
      .y_ok:
	add	ebx,eax
	cmp	ebx,[video_width]
	jbe	.width_ok
	mov	ebx,[video_width]
      .width_ok:
	sub	ebx,eax
	jc	.nothing
	jz	.nothing
	add	edx,ecx
	cmp	edx,[video_height]
	jbe	.height_ok
	mov	edx,[video_height]
      .height_ok:
	sub	edx,ecx
	jc	.nothing
	jz	.nothing
	mov	edi,ecx
	imul	edi,[video_pitch]
	add	edi,eax
	cmp	[video_granularity],0
	je	.linear
	push	edx
	mov	edx,edi
	shr	edx,16
	movzx	edi,di
	cmp	dx,[video_window]
	je	.window_ok
	mov	[video_window],dx
	imul	dx,[video_granularity]
	call	.window
      .window_ok:
	pop	edx
	or	edx,edx
	jz	.nothing
	push	es
	mov	eax,0A000h
	mov	es,ax
      .blit:
	mov	bp,bx
	add	bp,di
	jc	.bound
	mov	ecx,ebx
	shr	ecx,2
	rep	movsd
	mov	ecx,ebx
	and	ecx,11b
	rep	movsb
      .next:
	mov	eax,[source_pitch]
	sub	eax,ebx
	add	esi,eax
	mov	eax,[video_pitch]
	sub	eax,ebx
	add	di,ax
	jc	.switch
	dec	edx
	jnz	.blit
	jmp	.done
      .switch:
	push	edx
	inc	[video_window]
	mov	dx,[video_window]
	imul	dx,[video_granularity]
	call	.window
	pop	edx
	dec	edx
	jnz	.blit
	jmp	.done
      .bound:
	movsx	ecx,di
	neg	ecx
	mov	eax,ecx
	shr	ecx,2
	rep	movsd
	mov	ecx,eax
	and	ecx,11b
	rep	movsb
	movzx	edi,di
	push	edx
	inc	[video_window]
	mov	dx,[video_window]
	imul	dx,[video_granularity]
	call	.window
	pop	edx
	movzx	ecx,bp
	shr	ecx,2
	rep	movsd
	movzx	ecx,bp
	and	ecx,11b
	rep	movsb
	jmp	.next
      .done:
	pop	es
      .nothing:
	ret
      .linear:
	or	edx,edx
	jz	.nothing
	push	es
	xor	eax,eax
	mov	es,ax
	add	edi,[video_linear]
      .linear_blit:
	mov	ecx,ebx
	shr	ecx,2
	rep	movsd
	mov	ecx,ebx
	and	ecx,11b
	rep	movsb
	mov	eax,[source_pitch]
	sub	eax,ebx
	add	esi,eax
	mov	eax,[video_pitch]
	sub	eax,ebx
	add	edi,eax
	dec	edx
	jnz	.linear_blit
	pop	es
	ret
      .window:
	call	unreal:switch_real16
	use16
	push	bx
	xor	bx,bx
	call	far [video_window_select]
	pop	bx
	call	unreal:switch_real32
	use32
	ret
