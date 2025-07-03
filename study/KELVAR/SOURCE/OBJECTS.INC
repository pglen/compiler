
virtual at 0
  zone:
    .id db ?
    .x dd ?
    .y dd ?
    .width dd ?
    .height dd ?
    .data dd ?
    .size = $
end virtual

ID_STATIC = 1
ID_CURSOR = 2
ID_PLAYER = 3

ZONE_ILLEGAL = 1
ZONE_EVENT   = 2

WALK_SPEED = 5

move_objects:
; gs - segment with plane data
	mov	esi,[gs:plane.objects]
      .move:
	mov	al,[esi]
	or	al,al
	jz	.done
	cmp	al,ID_STATIC
	je	.next
	cmp	al,ID_CURSOR
	je	move_cursor
	cmp	al,ID_PLAYER
	je	move_player
      .next:
	add	esi,object.size
	jmp	.move
      .done:
	call	prepare_plane_images
	ret
    move_cursor:
	mov	eax,[mouse_x]
	mov	ebx,[mouse_y]
	sub	eax,[gs:plane.x]
	sub	ebx,[gs:plane.y]
	mov	[esi+object.x],eax
	mov	[esi+object.y],ebx
	jmp	move_objects.next
    move_player:
	push	esi
	mov	esi,move_keys
	xor	ebx,ebx
	mov	dl,-1
	cli
      .check_keys:
	movzx	edi,byte [esi+ebx]
	cmp	[keyboard+edi],1
	je	.new_key
	cmp	bl,[direction]
	je	.check_key
	cmp	dl,-1
	jne	.next_key
      .check_key:
	cmp	[keyboard+edi],0
	je	.next_key
	mov	dl,bl
	jmp	.next_key
      .new_key:
	mov	dl,bl
	mov	[keyboard+edi],2
	sti
	jmp	.move
      .next_key:
	inc	ebx
	cmp	ebx,8
	jb	.check_keys
	sti
	cmp	dl,-1
	jne	.move
      .no_move:
	pop	esi
	mov	byte [esi+object.frame_id],0
	jmp	move_objects.next
      .move:
	pop	esi
	mov	[direction],dl
	mov	al,byte [esi+object.frame_id+1]
	cmp	al,dl
	je	.walk
	mov	bl,dl
	sub	bl,al
	and	bl,111b
	mov	bh,al
	sub	bh,dl
	and	bh,111b
	mov	cl,1
	cmp	bl,bh
	jb	.rotate
	mov	cl,-1
	ja	.rotate
	mov	cl,[rotation]
      .rotate:
	add	al,cl
	and	al,111b
	mov	byte [esi+object.frame_id+1],al
	mov	[rotation],cl
	jmp	move_objects.next
      .walk:
	mov	eax,[esi+object.x]
	mov	ebx,[esi+object.y]
	or	dl,dl
	jz	.walk_down
	cmp	dl,1
	je	.walk_down_right
	cmp	dl,2
	je	.walk_right
	cmp	dl,3
	je	.walk_up_right
	cmp	dl,4
	je	.walk_up
	cmp	dl,5
	je	.walk_up_left
	cmp	dl,6
	je	.walk_left
      .walk_down_left:
	add	ebx,WALK_SPEED*100/141
	sub	eax,WALK_SPEED*100/141
	jmp	.walk_check
      .walk_down:
	add	ebx,WALK_SPEED
	jmp	.walk_check
      .walk_down_right:
	add	ebx,WALK_SPEED*100/141
	add	eax,WALK_SPEED*100/141
	jmp	.walk_check
      .walk_right:
	add	eax,WALK_SPEED
	jmp	.walk_check
      .walk_up_right:
	sub	ebx,WALK_SPEED*100/141
	add	eax,WALK_SPEED*100/141
	jmp	.walk_check
      .walk_up:
	sub	ebx,WALK_SPEED
	jmp	.walk_check
      .walk_up_left:
	sub	ebx,WALK_SPEED*100/141
	sub	eax,WALK_SPEED*100/141
	jmp	.walk_check
      .walk_left:
	sub	eax,WALK_SPEED
	jmp	.walk_check
      .walk_check:
	call	check_zone
	cmp	dl,ZONE_ILLEGAL
	je	.illegal
	cmp	dl,ZONE_EVENT
	je	.event
      .walk_ok:
	mov	dl,byte [esi+object.frame_id]
	inc	dl
	cmp	dl,12
	jb	.animation_ok
	mov	dl,1
      .animation_ok:
	mov	byte [esi+object.frame_id],dl
      .finish_move:
	mov	[esi+object.x],eax
	mov	[esi+object.y],ebx
	jmp	move_objects.next
      .illegal:
	mov	byte [esi+object.frame_id],0
	jmp	move_objects.next
      .event:
	mov	esi,[edi+zone.data]
	add	esi,[world]
	call	process_event
	ret

check_zone:
; eax = x, ebx = y
	mov	edi,[place_zones]
      .check:
	mov	dl,[edi+zone.id]
	or	dl,dl
	jz	.ok
	mov	ecx,[edi+zone.x]
	cmp	eax,ecx
	jl	.next
	add	ecx,[edi+zone.width]
	cmp	eax,ecx
	jge	.next
	mov	ecx,[edi+zone.y]
	cmp	ebx,ecx
	jl	.next
	add	ecx,[edi+zone.height]
	cmp	ebx,ecx
	jge	.next
      .ok:
	ret
      .next:
	add	edi,zone.size
	jmp	.check

update_cursor:
	mov	esi,[gs:plane.objects]
      .move:
	mov	al,[esi]
	or	al,al
	jz	.done
	cmp	al,ID_STATIC
	je	.next
	cmp	al,ID_CURSOR
	jne	.next
	mov	eax,[mouse_x]
	mov	ebx,[mouse_y]
	sub	eax,[gs:plane.x]
	sub	ebx,[gs:plane.y]
	mov	[esi+object.x],eax
	mov	[esi+object.y],ebx
      .next:
	add	esi,object.size
	jmp	.move
      .done:
	ret
