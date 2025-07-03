
virtual at 0
  text_definition:
    .image_id dd ?
    .x dd ?
    .y dd ?
    .file dd ?
    .size = $
end virtual

show_text:
; esi - text definition
        push    [memory_current_end]
        mov     ebx,[esi+text_definition.image_id]
        imul    ebx,image.size
        add     ebx,[images]
      .init:
        push    esi ebx
        mov     eax,[ebx+image.width]
        mov     edx,[ebx+image.height]
        mov     ecx,640
        sub     ecx,eax
        sar     ecx,1
        mov     [window_x],ecx
        mov     ecx,480
        sub     ecx,edx
        sar     ecx,1
        mov     [window_y],ecx
        imul    eax,edx
        call    get_memory
        jnc     .prepare
        call    release_unused_images
        jc      out_of_memory
        pop     ebx esi
        jmp     .init
      .prepare:
        pop     ebx
        cmp     [ebx+image.status],1
        ja      .image_ok
        push    eax ebx esi
        call    load_image
        pop     esi ebx eax
      .image_ok:
        push    eax ebx
        mov     edi,eax
        mov     edx,[ebx+image.height]
        mov     [destination_height],edx
        mov     ebx,[ebx+image.width]
        mov     [destination_pitch],ebx
        mov     [destination_width],ebx
        push    main_plane
        pop     gs
        call    .get_plane
        push    control_plane
        pop     gs
        call    .get_plane
        pop     ebx edi
        push    edi
        mov     esi,[ebx+image.picture]
        mov     eax,[ebx+image.pitch]
        mov     [source_pitch],eax
        mov     ebx,[destination_width]
        mov     edx,[destination_height]
        xor     eax,eax
        xor     ecx,ecx
        call    clip
        call    blit
        mov     ebx,[esp+4]
        mov     esi,[ebx+text_definition.file]
        add     esi,[world]
      .load:
        push    esi
        call    load_file
        jnc     .text
        call    release_unused_images
        jc      out_of_memory
        pop     esi
        jmp     .load
      .text:
        pop     esi
        mov     esi,eax
        pop     edi ebx
        push    edi
        mov     ebp,[simple_font]
        mov     eax,[ebx+text_definition.x]
        mov     ecx,[ebx+text_definition.y]
        call    blit_text
        pop     esi
        mov     eax,[window_x]
        mov     ecx,[window_y]
        mov     ebx,[destination_width]
        mov     [source_pitch],ebx
        mov     edx,[destination_height]
        call    video_blit
      .wait:
        cmp     [keyboard+KEY_SPACE],1
        je      .end
        cmp     [keyboard+KEY_ESC],1
        je      .end
        call    get_mouse_buttons
        or      bx,bx
        jz      .wait
      .end:
        pop     [memory_current_end]
        ret
      .get_plane:
        push    edi
        mov     esi,[gs:plane.screen]
        mov     ebx,[gs:plane.width]
        mov     [source_pitch],ebx
        mov     edx,[gs:plane.height]
        mov     eax,[gs:plane.x]
        sub     eax,[window_x]
        mov     ecx,[gs:plane.y]
        sub     ecx,[window_y]
        call    clip
        call    fast_blit
        pop     edi
        ret
