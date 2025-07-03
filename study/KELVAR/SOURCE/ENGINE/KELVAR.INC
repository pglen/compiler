
virtual at 0
  plane:
    .background dd ?
    .screen dd ?
    .x dd ?
    .y dd ?
    .width dd ?
    .height dd ?
    .objects dd ?
    .size = $
end virtual

virtual at 0
  image:
    .status db ?
    .file dd ?
    .x dd ?
    .y dd ?
    .picture dd ?
    .source dd ?
    .pitch dd ?
    .width dd ?
    .height dd ?
    .hook_x dd ?
    .hook_y dd ?
    .size = $
end virtual

virtual at 0
  object:
    .id db ?
    .refresh db ?
    .layer db ?
    .image_id dd ?
    .frame_id dw ?
    .x dd ?
    .y dd ?
    .image dd ?
    .frame dd ?
    .previous_x dd ?
    .previous_y dd ?
    .previous_image dd ?
    .previous_frame dd ?
    .size = $
end virtual

init_plane:
; eax = plane x, ecx = plane y
; ebx = plane width, edx = plane height
; gs - segment for plane data
        mov     [gs:plane.x],eax
        mov     [gs:plane.y],ecx
        mov     [gs:plane.width],ebx
        mov     [gs:plane.height],edx
        mov     eax,ebx
        imul    eax,edx
        mov     ecx,eax
        shl     eax,1
        call    get_memory
        jc      .failed
        mov     [gs:plane.background],eax
        add     eax,ecx
        mov     [gs:plane.screen],eax
        clc
        ret
      .failed:
        stc
        ret

refresh_plane:
; gs - segment with plane data
        call    sort_objects
        mov     esi,[gs:plane.background]
        mov     edi,[gs:plane.screen]
        mov     ebx,[gs:plane.width]
        mov     [source_pitch],ebx
        mov     [destination_pitch],ebx
        mov     [destination_width],ebx
        mov     edx,[gs:plane.height]
        mov     [destination_height],edx
        call    fast_blit
        mov     ebx,[gs:plane.objects]
      .prepare:
        cmp     byte [ebx],0
        je      .refresh
        push    ebx
        mov     esi,[ebx+object.image]
        mov     [ebx+object.previous_image],esi
        mov     eax,[esi+image.pitch]
        mov     [source_pitch],eax
        mov     eax,[ebx+object.x]
        mov     ecx,[ebx+object.y]
        mov     [ebx+object.previous_x],eax
        mov     [ebx+object.previous_y],ecx
        mov     edx,[esi+image.hook_x]
        sub     eax,edx
        mov     edx,[esi+image.hook_y]
        sub     ecx,edx
        mov     [ebx+object.refresh],0
        mov     edi,[ebx+object.frame]
        mov     [ebx+object.previous_frame],edi
        mov     ebx,[esi+image.width]
        mov     edx,[esi+image.height]
        mov     esi,[esi+image.picture]
        add     esi,edi
        mov     edi,[gs:plane.screen]
        call    clip
        call    blit
        pop     ebx
        add     ebx,object.size
        jmp     .prepare
      .refresh:
        mov     esi,[gs:plane.screen]
        mov     eax,[gs:plane.x]
        mov     ecx,[gs:plane.y]
        mov     ebx,[gs:plane.width]
        mov     [source_pitch],ebx
        mov     edx,[gs:plane.height]
        call    video_blit
        ret

refresh_objects:
; gs - segment with plane data
        call    check_objects
        mov     eax,[gs:plane.width]
        mov     [source_pitch],eax
        mov     [destination_pitch],eax
        mov     [destination_width],eax
        mov     eax,[gs:plane.height]
        mov     [destination_height],eax
        mov     ebx,[gs:plane.objects]
      .clear:
        cmp     byte [ebx],0
        je      .cleared
        cmp     [ebx+object.refresh],0
        je      .clear_next
        push    ebx
        xor     edi,edi
        mov     esi,[ebx+object.previous_image]
        mov     eax,[ebx+object.previous_x]
        mov     ecx,[ebx+object.previous_y]
        sub     eax,[esi+image.hook_x]
        sub     ecx,[esi+image.hook_y]
        mov     ebx,[esi+image.width]
        mov     edx,[esi+image.height]
        call    clip
        mov     esi,[gs:plane.background]
        add     esi,edi
        add     edi,[gs:plane.screen]
        call    fast_blit
        pop     ebx
      .clear_next:
        add     ebx,object.size
        jmp     .clear
      .cleared:
        mov     ebx,[gs:plane.objects]
      .prepare:
        cmp     byte [ebx],0
        je      .prepared
        cmp     [ebx+object.refresh],0
        je      .prepare_next
        push    ebx
        mov     esi,[ebx+object.image]
        mov     eax,[esi+image.pitch]
        mov     [source_pitch],eax
        mov     eax,[ebx+object.x]
        sub     eax,[esi+image.hook_x]
        mov     ecx,[ebx+object.y]
        sub     ecx,[esi+image.hook_y]
        mov     edi,[ebx+object.frame]
        mov     [ebx+object.previous_frame],edi
        mov     ebx,[esi+image.width]
        mov     edx,[esi+image.height]
        mov     esi,[esi+image.picture]
        add     esi,edi
        mov     edi,[gs:plane.screen]
        call    clip
        call    blit
        pop     ebx
      .prepare_next:
        add     ebx,object.size
        jmp     .prepare
      .prepared:
        mov     eax,[gs:plane.width]
        mov     [source_pitch],eax
        mov     ebx,[gs:plane.objects]
      .refresh:
        cmp     byte [ebx],0
        je      .refreshed
        cmp     [ebx+object.refresh],0
        je      .refresh_next
        push    ebx
        mov     esi,[ebx+object.previous_image]
        mov     eax,[ebx+object.previous_x]
        mov     ecx,[ebx+object.previous_y]
        sub     eax,[esi+image.hook_x]
        sub     ecx,[esi+image.hook_y]
        mov     ebx,[esi+image.width]
        mov     edx,[esi+image.height]
        mov     edi,[gs:plane.screen]
        call    clip
        add     eax,[gs:plane.x]
        add     ecx,[gs:plane.y]
        mov     esi,edi
        call    video_blit
        mov     ebx,[esp]
        mov     esi,[ebx+object.image]
        mov     [ebx+object.previous_image],esi
        mov     eax,[ebx+object.x]
        mov     ecx,[ebx+object.y]
        mov     [ebx+object.previous_x],eax
        mov     [ebx+object.previous_y],ecx
        mov     edx,[esi+image.hook_x]
        sub     eax,edx
        mov     edx,[esi+image.hook_y]
        sub     ecx,edx
        mov     [ebx+object.refresh],0
        mov     ebx,[esi+image.width]
        mov     edx,[esi+image.height]
        mov     edi,[gs:plane.screen]
        call    clip
        add     eax,[gs:plane.x]
        add     ecx,[gs:plane.y]
        mov     esi,edi
        call    video_blit
        pop     ebx
      .refresh_next:
        add     ebx,object.size
        jmp     .refresh
      .refreshed:
        ret

check_objects:
; gs - segment with plane data
        mov     ebx,[gs:plane.objects]
      .prepare:
        cmp     byte [ebx],0
        je      .prepared
        mov     eax,[ebx+object.image]
        cmp     eax,[ebx+object.previous_image]
        jne     .changed
        mov     eax,[ebx+object.frame]
        cmp     eax,[ebx+object.previous_frame]
        jne     .changed
        mov     eax,[ebx+object.x]
        cmp     eax,[ebx+object.previous_x]
        jne     .changed
        mov     eax,[ebx+object.y]
        cmp     eax,[ebx+object.previous_y]
        je      .prepare_next
      .changed:
        mov     [ebx+object.refresh],1
      .prepare_next:
        add     ebx,object.size
        jmp     .prepare
      .prepared:
        mov     ebx,[gs:plane.objects]
      .check:
        cmp     byte [ebx],0
        je      .checked
        cmp     [ebx+object.refresh],0
        jne     .check_next
        mov     esi,[gs:plane.objects]
      .scan:
        cmp     byte [esi],0
        je      .check_next
        cmp     [esi+object.refresh],0
        je      .scan_next
        mov     edi,[ebx+object.image]
        mov     eax,[ebx+object.x]
        sub     eax,[edi+image.hook_x]
        add     eax,[edi+image.width]
        mov     edi,[esi+object.image]
        mov     edx,[esi+object.x]
        sub     edx,[edi+image.hook_x]
        cmp     eax,edx
        jle     .no_collision
        mov     edi,[ebx+object.image]
        mov     eax,[ebx+object.y]
        sub     eax,[edi+image.hook_y]
        add     eax,[edi+image.height]
        mov     edi,[esi+object.image]
        mov     edx,[esi+object.y]
        sub     edx,[edi+image.hook_y]
        cmp     eax,edx
        jle     .no_collision
        mov     eax,[esi+object.x]
        sub     eax,[edi+image.hook_x]
        add     eax,[edi+image.width]
        mov     edi,[ebx+object.image]
        mov     edx,[ebx+object.x]
        sub     edx,[edi+image.hook_x]
        cmp     eax,edx
        jle     .no_collision
        mov     edi,[esi+object.image]
        mov     eax,[esi+object.y]
        sub     eax,[edi+image.hook_y]
        add     eax,[edi+image.height]
        mov     edi,[ebx+object.image]
        mov     edx,[ebx+object.y]
        sub     edx,[edi+image.hook_y]
        cmp     eax,edx
        jle     .no_collision
        mov     [ebx+object.refresh],1
        mov     ebx,[gs:plane.objects]
        jmp     .check
      .no_collision:
        mov     edi,[ebx+object.image]
        mov     eax,[ebx+object.x]
        sub     eax,[edi+image.hook_x]
        add     eax,[edi+image.width]
        mov     edi,[esi+object.previous_image]
        mov     edx,[esi+object.previous_x]
        sub     edx,[edi+image.hook_x]
        cmp     eax,edx
        jbe     .scan_next
        mov     edi,[ebx+object.image]
        mov     eax,[ebx+object.y]
        sub     eax,[edi+image.hook_y]
        add     eax,[edi+image.height]
        mov     edi,[esi+object.previous_image]
        mov     edx,[esi+object.previous_y]
        sub     edx,[edi+image.hook_y]
        cmp     eax,edx
        jbe     .scan_next
        mov     edi,[esi+object.previous_image]
        mov     eax,[esi+object.previous_x]
        sub     eax,[edi+image.hook_x]
        add     eax,[edi+image.width]
        mov     edi,[ebx+object.image]
        mov     edx,[ebx+object.x]
        sub     edx,[edi+image.hook_x]
        cmp     eax,edx
        jbe     .scan_next
        mov     edi,[esi+object.previous_image]
        mov     eax,[esi+object.previous_y]
        sub     eax,[edi+image.hook_y]
        add     eax,[edi+image.height]
        mov     edi,[ebx+object.image]
        mov     edx,[ebx+object.y]
        sub     edx,[edi+image.hook_y]
        cmp     eax,edx
        jbe     .scan_next
        mov     [ebx+object.refresh],1
        mov     ebx,[gs:plane.objects]
        jmp     .check
      .scan_next:
        add     esi,object.size
        jmp     .scan
      .check_next:
        add     ebx,object.size
        jmp     .check
      .checked:
        ret

sort_objects:
; gs - segment with plane data
        mov     ebx,[gs:plane.objects]
      .sort:
        cmp     byte [ebx],0
        je      .sorted
        mov     esi,ebx
        mov     edx,esi
        mov     eax,[ebx+object.y]
      .search:
        add     esi,object.size
        cmp     byte [esi],0
        je      .search_done
        mov     cl,[esi+object.layer]
        cmp     cl,[ebx+object.layer]
        ja      .next
        jb      .nearer
        cmp     [esi+object.y],eax
        jae     .next
        mov     eax,ecx
      .nearer:
        mov     edx,esi
      .next:
        jmp     .search
      .search_done:
        cmp     ebx,edx
        je      .sort_next
        mov     esi,edx
        mov     edi,ebx
        mov     [esi+object.refresh],1
        mov     [edi+object.refresh],1
        mov     ecx,object.size shr 2
      .exchange:
        mov     eax,[edi]
        xchg    eax,[esi]
        stos    dword [edi]
        add     esi,4
        loop    .exchange
        repeat  object.size and 11b
        mov     al,[edi]
        xchg    al,[esi]
        stos    byte [edi]
        inc     esi
        end     repeat
      .sort_next:
        add     ebx,object.size
        jmp     .sort
      .sorted:
        ret
