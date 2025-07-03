
virtual at 0
  character:
    .data dd ?
    .width dd ?
    .height dd ?
    .position dd ?
    .size = $
end virtual

virtual at 0
  font:
    .pitch dd ?
    .height dd ?
    .characters rb 0E0h*character.size
    .size = $
end virtual

load_font:
; esi - file name
; return: ebp - font
	call	load_picture
	jc	out_of_memory
	mov	eax,font.size
	call	get_memory
	jc	.error
	mov	ebp,eax
	lea	ebx,[eax+font.characters]
	mov	edi,ebx
	mov	ecx,(0E0h*character.size) shr 2
	xor	eax,eax
	rep	stosd
	mov	eax,[picture_width]
	mov	[ebp+font.pitch],eax
	push	ebp
	mov	esi,[picture]
	mov	edi,esi
	mov	ecx,[picture_width]
	lea	ebp,[esi+ecx]
	xor	edx,edx
      .find_first_frame:
	cmp	byte [edi],0
	jne	.first_frame
	add	edi,ecx
	inc	edx
	cmp	edx,[picture_height]
	jb	.find_first_frame
	jmp	file_error
      .first_frame:
	mov	al,[edi]
      .get_base_position:
	cmp	[edi],al
	jne	.base_position_ok
	add	edi,ecx
	inc	edx
	cmp	edx,[picture_height]
	jb	.get_base_position
      .base_position_ok:
	dec	edx
	push	edx
      .get_character:
	inc	esi
	cmp	esi,ebp
	jae	file_error
	mov	edi,esi
	mov	ecx,[picture_width]
	xor	edx,edx
      .find_character:
	cmp	[edi],al
	je	.character_found
	add	edi,ecx
	inc	edx
	cmp	edx,[picture_height]
	jb	.find_character
	jmp	file_error
      .character_found:
	add	edi,ecx
	inc	edx
	cmp	edx,[picture_height]
	je	file_error
	mov	[ebx+character.data],edi
	push	edx
      .get_character_position:
	cmp	[edi],al
	je	.character_position_ok
	add	edi,ecx
	inc	edx
	cmp	edx,[picture_height]
	jb	.get_character_position
	jmp	file_error
      .character_position_ok:
	pop	ecx
	mov	[ebx+character.height],edx
	sub	[ebx+character.height],ecx
	mov	ecx,edx
	pop	edx
	mov	[ebx+character.position],edx
	sub	[ebx+character.position],ecx
	mov	edi,[ebx+character.data]
	xor	ecx,ecx
      .get_character_width:
	cmp	[edi],al
	je	.character_width_ok
	inc	ecx
	inc	esi
	cmp	esi,ebp
	ja	file_error
	inc	edi
	jmp	.get_character_width
      .character_width_ok:
	mov	[ebx+character.width],ecx
	inc	esi
	cmp	esi,ebp
	je	.font_ok
	dec	esi
	push	edx
	add	ebx,character.size
	jmp	.get_character
      .font_ok:
	pop	ebp
	mov	ecx,0E0h
	lea	esi,[ebp+font.characters]
	xor	eax,eax
	xor	ebx,ebx
      .get_global_height:
	mov	edx,[esi+character.height]
	add	edx,[esi+character.position]
	cmp	edx,eax
	jle	.upper_ok
	mov	eax,edx
      .upper_ok:
	mov	edx,[esi+character.position]
	neg	edx
	cmp	edx,ebx
	jle	.lower_ok
	mov	ebx,edx
      .lower_ok:
	add	esi,character.size
	loop	.get_global_height
	add	eax,ebx
	mov	[ebp+font.height],eax
	clc
	ret
      .error:
	stc
	ret

blit_text:
; eax = x, ecx = y
; esi - text
; ebp - font
; edi - destination
	mov	[current_x],eax
	mov	[current_y],ecx
	push	eax
	mov	eax,[ebp+font.pitch]
	mov	[source_pitch],eax
      .text:
	lodsb
	or	al,al
	jz	.end
	cmp	al,0Dh
	je	.cr
	cmp	al,0Ah
	je	.lf
	cmp	al,20h
	jb	.text
      .standard:
	movzx	eax,al
	sub	al,20h
	imul	eax,character.size
	lea	ebx,[ebp+font.characters+eax]
	cmp	[ebx+character.data],0
	je	.text
	push	esi edi ebp
	mov	eax,[current_x]
	mov	ecx,[current_y]
	mov	esi,[ebx+character.data]
	sub	ecx,[ebx+character.position]
	mov	edx,[ebx+character.height]
	mov	ebx,[ebx+character.width]
	sub	ecx,edx
	add	[current_x],ebx
	call	clip
	call	blit
	pop	ebp edi esi
	jmp	.text
      .cr:
	mov	eax,[esp]
	mov	[current_x],eax
	jmp	.text
      .lf:
	mov	eax,[ebp+font.height]
	add	[current_y],eax
	jmp	.text
      .end:
	pop	eax
	ret
