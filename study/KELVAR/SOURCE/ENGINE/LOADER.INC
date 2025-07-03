
virtual at 0
  plane_definition:
    .image_id dd ?
    .x dd ?
    .y dd ?
    .size = $
end virtual

load_file:
; esi - file name
; return: eax - loaded data
        mov     ax,buffer
        mov     fs,ax
        mov     edi,file_path
      .name:
        lodsb
        stosb
        or      al,al
        jnz     .name
        mov     dx,file_path
        mov     ax,3D00h
        int     21h
        jc      file_error
        mov     ebx,eax
        mov     ax,4202h
        xor     cx,cx
        xor     dx,dx
        int     21h
        shl     edx,16
        mov     dx,ax
        mov     ebp,edx
        xor     cx,cx
        xor     dx,dx
        mov     ax,4200h
        int     21h
        mov     eax,ebp
        inc     eax
        call    get_memory
        jc      .out_of_memory
        mov     byte [eax+ebp],0
        push    fs
        pop     ds
        push    eax
        mov     edi,eax
      .load:
        mov     ecx,0E000h
        cmp     ebp,0E000h
        jae     .read
        mov     ecx,ebp
      .read:
        sub     ebp,ecx
        push    ecx
        xor     dx,dx
        mov     ah,3Fh
        int     21h
        pop     ecx
        jc      file_error
        xor     esi,esi
        mov     dl,cl
        and     dl,11b
        shr     ecx,2
        rep     movsd
        mov     cl,dl
        rep     movsb
        or      ebp,ebp
        jnz     .load
        mov     ah,3Eh
        int     21h
      .done:
        pop     eax
        push    main_data
        pop     ds
        clc
        ret
      .out_of_memory:
        stc
        ret

init_world:
; esi - file with world data
        call    load_file
        jc      out_of_memory
        mov     esi,eax
        mov     [world],esi
        mov     eax,[esi]
        add     eax,esi
        mov     [images],eax
        mov     eax,[memory_current]
        mov     [images_data],eax
        mov     [memory_method],1
        ret

load_image:
; ebx - entry of image to load
        push    ebx
        mov     [memory_method],0
        mov     esi,[ebx+image.file]
        add     esi,[world]
        call    load_picture
        pop     ebx
        jnc     .make
        push    ebx
        call    release_unused_images
        jc      out_of_memory
        pop     ebx
        jmp     load_image
      .make:
        mov     [ebx+image.status],2
        mov     esi,[picture]
        mov     [ebx+image.source],esi
        mov     eax,[picture_width]
        mov     [ebx+image.pitch],eax
        mov     edx,[ebx+image.y]
        imul    eax,edx
        add     esi,eax
        mov     edx,[ebx+image.x]
        add     esi,edx
        mov     [ebx+image.picture],esi
        mov     eax,[ebx+image.file]
        mov     ebx,[images]
      .more:
        cmp     byte [ebx],0
        je      .done
        cmp     [ebx+image.status],1
        ja      .next
        cmp     eax,[ebx+image.file]
        je      .make
      .next:
        add     ebx,image.size
        jmp     .more
      .done:
        mov     [memory_method],1
        clc
        ret

release_last_image:
        mov     esi,[images]
        mov     eax,[images_data]
      .find:
        cmp     byte [esi],0
        je      .release
        cmp     [esi+image.status],2
        jb      .next
        cmp     eax,[esi+image.source]
        jae     .next
        mov     eax,[esi+image.source]
      .next:
        add     esi,image.size
        jmp     .find
      .release:
        cmp     eax,[memory_current]
        je      .failed
        mov     [memory_current],eax
        mov     esi,[images]
      .fix:
        cmp     byte [esi],0
        je      .done
        cmp     [esi+image.status],2
        jb      .fix_next
        cmp     eax,[esi+image.source]
        jne     .fix_next
        mov     [esi+image.status],1
      .fix_next:
        add     esi,image.size
        jmp     .fix
      .done:
        clc
        ret
      .failed:
        stc
        ret

release_unused_images:
        mov     ecx,[images_data]
        mov     ebx,[images]
        mov     ebp,[memory_current]
      .search:
        cmp     byte [ebx],0
        je      .search_done
        cmp     [ebx+image.status],2
        jb      .search_next
        mov     edx,[ebx+image.source]
        cmp     edx,ecx
        jb      .search_next
        cmp     edx,ebp
        ja      .search_next
        push    control_plane
        pop     fs
        mov     esi,[fs:plane.objects]
      .check:
        cmp     byte [esi],0
        je      .objects_checked
        mov     eax,[esi+object.image_id]
        imul    eax,image.size
        add     eax,[images]
        cmp     [eax+image.status],2
        jb      .check_next
        cmp     edx,[eax+image.source]
        je      .used
      .check_next:
        add     esi,object.size
        jmp     .check
      .objects_checked:
        mov     ax,fs
        cmp     ax,main_plane
        je      .search_next
        push    main_plane
        pop     fs
        mov     esi,[fs:plane.objects]
        jmp     .check
      .used:
        mov     ebp,edx
      .search_next:
        add     ebx,image.size
        jmp     .search
      .search_done:
        mov     edx,ebp
        mov     esi,[images]
        mov     eax,[memory_current]
      .free:
        cmp     byte [esi],0
        je      .move
        cmp     [esi+image.status],2
        jb      .release_next
        mov     edi,[esi+image.source]
        cmp     edi,ecx
        jb      .release_next
        cmp     edi,edx
        jb      .release
        je      .fix
        cmp     edi,eax
        ja      .release_next
        mov     eax,edi
        jmp     .release_next
      .fix:
        mov     [esi+image.source],ecx
        mov     edi,ecx
        sub     edi,edx
        add     [esi+image.picture],edi
        push    eax esi
        push    control_plane
        pop     fs
        mov     esi,[fs:plane.objects]
      .mark_for_refresh:
        cmp     byte [esi],0
        je      .objects_marked
        mov     eax,[esi+object.image_id]
        imul    eax,image.size
        add     eax,[images]
        cmp     eax,[esp]
        jne     .mark_next
        mov     [esi+object.refresh],1
      .mark_next:
        add     esi,object.size
        jmp     .mark_for_refresh
      .objects_marked:
        mov     eax,fs
        push    main_plane
        pop     fs
        mov     esi,[fs:plane.objects]
        cmp     eax,main_plane
        jne     .mark_for_refresh
        pop     esi eax
        jmp     .release_next
      .release:
        mov     [esi+image.status],1
      .release_next:
        add     esi,image.size
        jmp     .free
      .move:
        mov     esi,edx
        mov     edi,ecx
        mov     ecx,eax
        cmp     esi,edi
        je      .moved
        sub     ecx,edx
        mov     dl,cl
        and     dl,11b
        shr     ecx,2
        rep     movsd
        mov     cl,dl
        rep     movsb
        mov     ecx,edi
      .moved:
        mov     ebx,[images]
        cmp     ebp,[memory_current]
        je      .freed
        mov     ebp,[memory_current]
        jmp     .search
      .freed:
        cmp     ecx,[memory_current]
        je      .failed
        mov     [memory_current],ecx
        clc
        ret
      .failed:
        stc
        ret

prepare_plane:
; esi - plane definition
; gs - buffer for plane data
        mov     edx,esi
        add     esi,plane_definition.size
        mov     ebx,[edx+plane_definition.image_id]
        imul    ebx,image.size
        add     ebx,[images]
        xor     edi,edi
        mov     di,gs
        sub     di,main_data
        shl     edi,4
        add     edi,plane.size
        mov     [gs:plane.objects],edi
      .objects:
        cmp     byte [esi],0
        je      .init
        mov     ecx,object.size
        rep     movsb
        jmp     .objects
      .init:
        xor     al,al
        stosb
        inc     esi
        push    esi ebx
        mov     eax,[edx+plane_definition.x]
        mov     ecx,[edx+plane_definition.y]
        sub     eax,[ebx+image.hook_x]
        sub     ecx,[ebx+image.hook_y]
        mov     edx,[ebx+image.height]
        mov     ebx,[ebx+image.width]
        call    init_plane
        jnc     .done
      .error:
        call    release_unused_images
        jc      out_of_memory
        jmp     .init
      .done:
        pop     ebx
        cmp     [ebx+image.status],1
        ja      .image_ok
        push    ebx esi
        call    load_image
        pop     esi ebx
      .image_ok:
        mov     esi,[ebx+image.picture]
        mov     edi,[gs:plane.background]
        mov     eax,[ebx+image.pitch]
        mov     [source_pitch],eax
        mov     edx,[gs:plane.height]
        mov     [destination_height],edx
        mov     ebx,[gs:plane.width]
        mov     [destination_pitch],ebx
        mov     [destination_width],ebx
        xor     eax,eax
        xor     ecx,ecx
        call    fast_blit
        call    prepare_plane_images
        pop     esi
        ret

prepare_plane_images:
        mov     esi,[gs:plane.objects]
      .prepare:
        cmp     byte [esi],0
        je      .prepared
        mov     ebx,[esi+object.image_id]
        imul    ebx,image.size
        add     ebx,[images]
        cmp     [ebx+image.status],1
        ja      .image_ok
        push    ebx esi
        call    load_image
        pop     esi ebx
      .image_ok:
        mov     eax,[ebx+image.height]
        movzx   edx,[esi+object.frame_id]
        shr     edx,8
        mul     edx
        mov     edx,[ebx+image.pitch]
        mul     edx
        mov     ecx,[ebx+image.width]
        mov     dl,byte [esi+object.frame_id]
        imul    ecx,edx
        add     eax,ecx
        mov     [esi+object.frame],eax
        mov     [esi+object.image],ebx
        add     esi,object.size
        jmp     .prepare
      .prepared:
        ret
