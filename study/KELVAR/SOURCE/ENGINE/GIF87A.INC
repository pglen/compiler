
load_picture:
; esi - file name
; return: esi - picture data, ebx = picture width, edx = picture height
	mov	eax,buffer
	mov	fs,ax
	mov	edi,file_path
      .name:
	lodsb
	stosb
	or	al,al
	jnz	.name
	mov	dx,file_path
	mov	ax,3D00h
	int	21h
	jc	file_error
	mov	ebx,eax
	push	fs
	pop	ds
	xor	ebp,ebp
      .load:
	xor	dx,dx
	mov	ecx,0E000h
	mov	ah,3Fh
	int	21h
	jc	file_error
	movzx	eax,ax
	add	ebp,eax
	cmp	eax,0E000h
	jb	.loaded
	cmp	ebp,30000h
	je	.loaded
	mov	eax,ds
	add	eax,0E00h
	mov	ds,ax
	jmp	.load
      .loaded:
	mov	ah,3Eh
	int	21h
	mov	eax,ebp
	push	main_data
	pop	ds
	cmp	dword [fs:0],'GIF8'
	jne	file_error
	cmp	word [fs:4],'7a'
	jne	file_error
	mov	al,[fs:0Ah]
	and	al,111b
	cmp	al,111b
	jne	file_error
	mov	esi,13+768
      .find_image:
	cmp	esi,ebp
	jae	file_error
	lods	byte [fs:esi]
	cmp	al,','
	jne	.find_image
	add	esi,4
	xor	eax,eax
	lods	word [fs:esi]
	mov	[picture_width],eax
	lods	word [fs:esi]
	mov	[picture_height],eax
	add	esi,2
	push	es buffer
	pop	es
	mov	edi,esi
	mov	edx,esi
      .link_streams:
	cmp	esi,ebp
	jae	.damaged
	lods	byte [fs:esi]
	movzx	ecx,al
	rep	movs byte [es:edi],[fs:esi]
	or	al,al
	jnz	.link_streams
	pop	es
	mov	eax,[picture_width]
	mov	ebx,[picture_height]
	imul	eax,ebx
	call	get_memory
	jc	.out_of_memory
	mov	[picture],eax
	mov	edi,eax
	mov	ebx,edx
	mov	[LZW_bits],0
      .clear:
	xor	edx,edx
      .decompress_loop:
	mov	ch,9
	cmp	edx,(100h-2)*8
	jbe	.read_bits
	mov	ch,10
	cmp	edx,(300h-2)*8
	jbe	.read_bits
	mov	ch,11
	cmp	edx,(700h-2)*8
	jbe	.read_bits
	mov	ch,12
      .read_bits:
	mov	cl,[LZW_bits]
	mov	eax,[fs:ebx]
	shr	eax,cl
	xchg	cl,ch
	mov	esi,1
	shl	esi,cl
	dec	esi
	and	eax,esi
	add	cl,ch
      .read_bits_count:
	cmp	cl,8
	jbe	.read_bits_ok
	sub	cl,8
	inc	ebx
	jmp	.read_bits_count
      .read_bits_ok:
	mov	[LZW_bits],cl
	cmp	eax,100h
	jb	.single_byte
	je	.clear
	sub	eax,102h
	jc	.end
	shl	eax,3
	cmp	eax,edx
	ja	file_error
	mov	ecx,[LZW_table+eax]
	mov	esi,[LZW_table+eax+4]
	mov	[LZW_table+edx+4],edi
	rep	movsb
	mov	eax,[LZW_table+eax]
	inc	eax
	mov	[LZW_table+edx],eax
	jmp	.decompress_next
      .single_byte:
	mov	[LZW_table+edx],2
	mov	[LZW_table+edx+4],edi
	stosb
      .decompress_next:
	add	edx,8
	jmp	.decompress_loop
      .end:
	mov	esi,[picture]
	mov	ebx,[picture_width]
	mov	edx,[picture_height]
	clc
	ret
      .damaged:
	pop	es
      .out_of_memory:
	stc
	ret

load_palette:
; esi - file name
; return: esi - palette data
	mov	ax,buffer
	mov	fs,ax
	mov	di,file_path
      .name:
	lods	byte [ds:esi]
	stos	byte [es:di]
	or	al,al
	jnz	.name
	mov	dx,file_path
	mov	ax,3D00h
	int	21h
	jc	file_error
	mov	bx,ax
	push	fs
	pop	ds
	xor	dx,dx
	mov	cx,13+768
	mov	ah,3Fh
	int	21h
	jc	file_error
	mov	ah,3Eh
	int	21h
	mov	ax,main_data
	mov	ds,ax
	cmp	dword [fs:0],'GIF8'
	jne	file_error
	cmp	word [fs:4],'7a'
	jne	file_error
	mov	al,[fs:0Ah]
	and	al,111b
	cmp	al,111b
	jne	file_error
	mov	esi,13
	mov	edi,palette
	mov	ecx,768/4
	rep	movs dword [es:edi],[fs:esi]
	mov	esi,palette
	ret
