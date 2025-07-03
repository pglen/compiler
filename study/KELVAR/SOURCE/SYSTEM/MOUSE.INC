
read_mouse:
        xor     ecx,ecx
        xor     edx,edx
        mov     ax,0Bh
        int     33h
        mov     eax,edx
        cwde
        add     eax,[mouse_y]
        mov     ebx,eax
        mov     eax,ecx
        cwde
        add     eax,[mouse_x]
        xor     ecx,ecx
        cmp     eax,ecx
        jl      .x_edge
        mov     ecx,[video_width]
        dec     ecx
        cmp     eax,ecx
        jg      .x_edge
        jmp     .x_ok
      .x_edge:
        mov     eax,ecx
      .x_ok:
        xor     edx,edx
        cmp     ebx,edx
        jl      .y_edge
        mov     edx,[video_height]
        dec     edx
        cmp     ebx,edx
        jg      .y_edge
        jmp     .y_ok
      .y_edge:
        mov     ebx,edx
      .y_ok:
        mov     [mouse_x],eax
        mov     [mouse_y],ebx
        ret

get_mouse_buttons:
        mov     ax,3
        xor     bx,bx
        int     33h
        ret
