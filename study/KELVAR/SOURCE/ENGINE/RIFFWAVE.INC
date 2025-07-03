
load_sample:
; esi - file name
; return: eax - sample data, ecx = sample length
	cmp	[sound_card],0
	je	.skip
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
	xor	dx,dx
	mov	cx,12
	mov	ah,3Fh
	int	21h			; read WAVE header
	cmp	dword [0],'RIFF'
	jne	file_error
	cmp	dword [8],'WAVE'
	jne	file_error
	mov	edi,'fmt '
	call	find_RIFF_block
	jc	file_error
	cmp	ecx,10000h
	jae	file_error
	mov	cx,ax
	mov	dx,0E000h
	mov	ah,3Fh
	int	21h		       ; read format information
	cmp	word [0E000h],1        ; check for PCM
	jne	file_error
	cmp	word [0E002h],1        ; check for 1 channel
	jne	file_error
	cmp	word [0E00Eh],8        ; check for 8-bit
	jne	file_error
	mov	edi,'data'
	call	find_RIFF_block
	jc	file_error
	push	main_data
	pop	ds
	mov	ebp,eax
	mul	[sound_frequency]
	div	dword [fs:0E004h]	; wave frequency
	call	get_memory
	jc	.out_of_memory
	push	fs
	pop	ds
	push	eax
	mov	edi,eax
      .load:
	mov	ecx,0E000h
	cmp	ebp,0E000h
	jae	.read
	mov	ecx,ebp
      .read:
	sub	ebp,ecx
	push	ecx
	xor	dx,dx
	mov	ah,3Fh
	int	21h
	pop	ecx
	jc	file_error
	xor	esi,esi
	mov	eax,ecx
	mov	edx,[es:sound_frequency]
	cmp	edx,[0E004h]
	je	.copy
	mul	edx
	div	dword [0E004h]
	mov	edx,ecx
	mov	ecx,eax
	push	ebx ebp
	mov	ebp,ecx
	mov	ebx,ecx
      .convert:
	mov	al,[esi]
      .loop:
	cmp	ebp,edx
	jbe	.next
	sub	ebp,edx
	stosb
	dec	ebx
	jnz	.convert
	pop	ebp ebx
	jmp	.ok
      .next:
	add	ebp,ecx
	inc	esi
	jmp	.loop
      .copy:
	mov	eax,ecx
	shr	ecx,2
	rep	movsd
	mov	ecx,eax
	and	ecx,11b
	rep	movsb
      .ok:
	or	ebp,ebp
	jnz	.load
	mov	ah,3Eh
	int	21h
      .done:
	pop	eax
	mov	ecx,edi
	sub	ecx,eax
	push	main_data
	pop	ds
	clc
	ret
      .skip:
	xor	eax,eax
	xor	ecx,ecx
	clc
	ret
      .out_of_memory:
	stc
	ret

find_RIFF_block:
; edi = block signature
; bx = file handle
	push	ds buffer
	pop	ds
	mov	ax,4200h
	xor	cx,cx
	mov	dx,0Ch
	int	21h
      .find:
	xor	dx,dx
	mov	cx,8
	mov	ah,3Fh
	int	21h			; read signature and size
	jc	.eof
	or	ax,ax
	jz	.eof
	cmp	edi,[0]
	je	.found
	mov	ax,4201h
	mov	cx,[6]
	mov	dx,[4]
	int	21h			; seek next block
	jmp	.find
      .eof:
	pop	ds
	stc
	ret
      .found:
	mov	eax,[4] 		; eax = block size
	pop	ds
	clc
	ret
