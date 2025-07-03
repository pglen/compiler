
init_memory:
	mov	ah,48h			; get free conventional memory size
	mov	bx,-1
	int	21h
	movzx	ecx,bx
	shl	ecx,4
	mov	[dos_memory_end],ecx
	mov	ah,48h			; allocate all conventional memory
	int	21h
	movzx	edx,ax
	shl	edx,4
	mov	[dos_memory_start],edx
	mov	[dos_memory_current],edx
	add	[dos_memory_end],edx
	mov	ax,4300h		; check for XMS
	int	2Fh
	cmp	al,80h			; XMS present?
	je	xms_init
	mov	ah,88h			; how much extended memory free?
	int	15h
	or	ax,ax
	jz	no_extended_memory
	movzx	eax,ax			; convert AX kilobytes to pointer
	shl	eax,10
	add	eax,100000h
	mov	ebx,main_data
	shl	ebx,4
	sub	eax,ebx
	mov	[memory_end],eax
	mov	[memory_current_end],eax
	push	ds
	push	0			; DS := 0
	pop	ds
	call	enable_a20		; enable A20
	call	test_a20		; is A20 enabled?
	jz	a20_ok
	pop	ds
	jmp	no_extended_memory
    a20_ok:
	lds	bx,dword [4*19h]
	mov	eax,100000h		; initial free extended memory base
	cmp	dword [bx+12h],'VDIS'	; VDISK memory allocation?
	jne	short no_vdisk		; if present, get base of free memory
	mov	eax,dword [bx+2Ch]	; get first free extended memory byte
	add	eax,0Fh 		; align on paragraph
	and	eax,0FFFFF0h		; address is only 24bit
    no_vdisk:
	push	0FFFFh			; DS := FFFFh for ext mem addressing
	pop	ds
	cmp	dword [13h],'VDIS'	; VDISK memory allocation?
	jne	short vdisk_ok		; if present, get base of free memory
	movzx	ebx,word [2Eh]		; get first free kilobyte
	shl	ebx,10
	cmp	eax,ebx 		; pick larger of 2 addresses
	ja	short vdisk_ok
	mov	eax,ebx
    vdisk_ok:
	pop	ds
	mov	ebx,main_data
	shl	ebx,4
	sub	eax,ebx
	mov	[memory_start],eax
	mov	[memory_current],eax
	mov	[memory_method],0
	ret
    enable_a20:
	call	test_a20		; is A20 already enabled?
	jz	a20_enabled		; if yes, done
	in	al,92h			; PS/2 A20 enable
	or	al,2
	out	92h,al
	call	test_a20		; is A20 enabled?
	jz	a20_enabled		; if yes, done
	call	kb_wait 		; AT A20 enable
	jnz	a20_enabled
	mov	al,0D1h
	out	64h,al
	call	kb_wait
	jnz	a20_enabled
	mov	al,0DFh
	out	60h,al
	call	kb_wait
    a20_enabled:
	ret
    kb_wait:				; wait for safe to write to 8042
	xor	cx,cx
      .loop:
	in	al,64h			; read 8042 status
	test	al,2			; buffer full?
	loopnz	.loop			; if yes, loop
	ret
    test_a20:				; test for enabled A20
	mov	al,[0]			; get byte from 0:0
	mov	ah,al			; preserve old byte
	not	al			; modify byte
	xchg	al,[100000h]		; put modified byte to 0FFFFh:10h
	cmp	ah,[0]			; set zero if byte at 0:0 not modified
	mov	[100000h],al		; restore byte at 0FFFFh:10h
	ret				; return, zero if A20 enabled
    xms_init:
	push	es
	mov	ax,4310h		; get XMS driver address
	int	2Fh
	mov	word [cs:xms_call],bx	; store XMS driver address
	mov	word [cs:xms_call+2],es
	pop	es
	mov	ah,3			; enable A20
	call	xms_driver
	cmp	ax,1			; error enabling A20?
	jne	no_extended_memory
	mov	ah,8			; get free extended memory size
	xor	bl,bl
	call	xms_driver
	or	bl,bl
	jnz	no_extended_memory
	mov	dx,ax
	movzx	eax,ax
	shl	eax,10
	mov	[memory_end],eax
	mov	ah,9			; allocate largest memory block
	call	xms_driver
	mov	[cs:xms_handle],dx
	cmp	ax,1
	jne	no_extended_memory
	mov	ah,0Ch			; lock extended memory block
	call	xms_driver
	cmp	ax,1
	jne	no_extended_memory
	shl	edx,16
	mov	dx,bx
	mov	ebx,main_data
	shl	ebx,4
	sub	edx,ebx
	mov	[memory_start],edx	; store memory block address
	mov	[memory_current],edx
	add	edx,[memory_end]
	mov	[memory_end],edx
	mov	[memory_current_end],edx
	mov	[memory_method],0
	ret
    xms_driver:
	call	unreal:switch_real16
	use16
	call	far dword [cs:xms_call]
	call	unreal:switch_real32
	use32
	ret

free_memory:
	push	eax
	cmp	[cs:xms_handle],0
	je	short .xms_ok
	mov	ah,0Dh			; unlock extended memory block
	mov	dx,[cs:xms_handle]
	call	xms_driver
	mov	ah,0Ah			; free extended memory block
	call	xms_driver
      .xms_ok:
	push	es
	mov	eax,[dos_memory_start]
	shr	eax,4
	mov	es,ax
	mov	ah,49h			; free conventional memory block
	int	21h
	pop	es
	pop	eax
	ret

get_memory:
; eax = number of bytes
; return: eax - allocated memory
	cmp	[memory_method],1
	je	.from_top
	ja	.from_dos_or_top
	add	eax,[memory_current]
	jc	.out_of_memory
	cmp	eax,[memory_current_end]
	ja	.out_of_memory
	xchg	eax,[memory_current]
	clc
	ret
      .from_top:
	sub	[memory_current_end],eax
	jc	.out_of_memory
	mov	eax,[memory_current_end]
	cmp	eax,[memory_current]
	jb	.out_of_memory
	clc
	ret
      .from_dos_or_top:
	call	get_dos_memory
	jc	.from_top
	push	ebx
	mov	ebx,main_data
	shl	ebx,4
	sub	eax,ebx
	pop	ebx
	clc
	ret
      .out_of_memory:
	stc
	ret

get_dos_memory:
; eax = number of bytes
; return: eax = linear address of allocated memory
	add	eax,[dos_memory_current]
	jc	.out_of_memory
	cmp	eax,[dos_memory_end]
	ja	.out_of_memory
	xchg	eax,[dos_memory_current]
	clc
	ret
      .out_of_memory:
	stc
	ret

xms_call dd ?				; XMS driver pointer
xms_handle dw ? 			; handle of XMS memory block
