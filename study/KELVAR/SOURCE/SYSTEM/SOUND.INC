
SOUND_BUFFER_SIZE = 1000h

init_sound:
        call    detect_SB
        or      al,al
        jz      SB_detected
    no_sound:
        ret
    SB_detected:
        mov     [sound_card],1
        call    init_sound_buffer
        mov     bl,[SB_IRQ]
        mov     dx,sound_IRQ
        call    set_IRQ
        mov     bl,0D1h
        call    send_to_DSP
        mov     ecx,11025
        mov     [sound_frequency],ecx
        call    set_SB_frequency
        cli
        call    fill_sound_buffer
        mov     ebx,[sound_buffer]
        mov     esi,ebx
        shr     ebx,16
        mov     cx,SOUND_BUFFER_SIZE
        call    start_auto_DAC_transfer
        mov     [sound_offset],SOUND_BUFFER_SIZE
        call    fill_sound_buffer
        sti
        ret
end_sound:
        cmp     [sound_card],1
        je      reset_SB
        ret
    reset_SB:
        mov     bl,0D0h
        call    send_to_DSP
        mov     bl,0DAh
        call    send_to_DSP
        mov     bl,0DAh
        call    send_to_DSP
        mov     bl,[SB_IRQ]
        call    reset_IRQ
        call    init_SB
        ret

play_sample:
; esi - sample data
; ecx = sample length
        cli
        mov     [sample_data],esi
        mov     [sample_length],ecx
        call    fill_sound_buffer
        sti
        ret

init_sound_buffer:
        mov     eax,4*SOUND_BUFFER_SIZE
        call    get_dos_memory
        jc      out_of_dos_memory
        mov     [sound_buffer],eax
        mov     [sound_offset],0
        mov     [sample_length],0
        lea     ebx,[eax+2*SOUND_BUFFER_SIZE]
        shr     ebx,16
        shr     eax,16
        cmp     ebx,eax
        je      .ok
        shl     ebx,16
        mov     [sound_buffer],ebx
      .ok:
        ret
fill_sound_buffer:
        push    es 0
        pop     es
        mov     edi,[sound_buffer]
        add     edi,[sound_offset]
        mov     eax,[sample_length]
        mov     ecx,SOUND_BUFFER_SIZE
        cmp     eax,SOUND_BUFFER_SIZE
        jae     .length_ok
        mov     ecx,eax
      .length_ok:
        sub     [sample_length],ecx
        mov     ebx,ecx
        mov     esi,[sample_data]
        shr     ecx,2
        rep     movsd
        mov     ecx,ebx
        and     ecx,11b
        rep     movsb
        mov     [sample_data],esi
      .silence:
        mov     ecx,SOUND_BUFFER_SIZE
        sub     ecx,ebx
        mov     eax,80808080h
        mov     ebx,ecx
        shr     ecx,2
        rep     stosd
        mov     ecx,ebx
        and     ecx,11b
        rep     stosb
        pop     es
        ret

sound_IRQ:
        IRQ_enter
        push    ds es
        pushad
        push    main_data
        pop     ds
        mov     dx,[SB_port]
        add     dx,0Eh
        in      al,dx
        mov     al,20h
        out     20h,al
        out     0A0h,al
        xor     [sound_offset],SOUND_BUFFER_SIZE
        call    fill_sound_buffer
        popad
        pop     es ds
        IRQ_leave

start_DAC_transfer:
; bl = page
; si = offset
; cx = length
        dec     cx
        mov     bh,48h
        call    programm_DMA
        mov     bl,14h
        call    send_to_DSP
        mov     bl,cl
        call    send_to_DSP
        mov     bl,ch
        call    send_to_DSP
        ret

start_ADC_transfer:
; bl = page
; si = offset
; cx = length
        dec     cx
        mov     bh,44h
        call    programm_DMA
        mov     bl,24h
        call    send_to_DSP
        mov     bl,cl
        call    send_to_DSP
        mov     bl,ch
        call    send_to_DSP
        ret

start_auto_DAC_transfer:
; bl = page
; si = offset
; cx = length
        push    cx
        shl     cx,1
        dec     cx
        mov     bh,58h
        call    programm_DMA
        pop     cx
        dec     cx
        mov     bl,48h
        call    send_to_DSP
        mov     bl,cl
        call    send_to_DSP
        mov     bl,ch
        call    send_to_DSP
        mov     bl,1Ch
        call    send_to_DSP
        inc     cx
        shl     cx,1
        dec     cx
        mov     bl,cl
        call    send_to_DSP
        mov     bl,ch
        call    send_to_DSP
        ret

start_auto_ADC_transfer:
; bl = page
; si = offset
; cx = length
        push    cx
        shl     cx,1
        dec     cx
        mov     bh,54h
        call    programm_DMA
        pop     cx
        dec     cx
        mov     bl,48h
        call    send_to_DSP
        mov     bl,cl
        call    send_to_DSP
        mov     bl,ch
        call    send_to_DSP
        mov     bl,2Ch
        call    send_to_DSP
        inc     cx
        shl     cx,1
        dec     cx
        mov     bl,cl
        call    send_to_DSP
        mov     bl,ch
        call    send_to_DSP
        ret

detect_SB:
        mov     [SB_port],210h
    check_port:
        call    init_SB
        or      al,al
        jz      port_detected
        add     [SB_port],10h
        cmp     [SB_port],260h
        jna     check_port
        mov     [SB_port],280h
        call    init_SB
        or      al,al
        jz      port_detected
        mov     al,1
        ret
    port_detected:
        mov     ecx,11025
        call    set_SB_frequency
        mov     [SB_IRQ],5
        call    check_IRQ
        jnc     IRQ_ok
        mov     [SB_IRQ],7
        call    check_IRQ
        jnc     IRQ_ok
        mov     [SB_IRQ],2
        call    check_IRQ
        jnc     IRQ_ok
        mov     [SB_IRQ],3
        call    check_IRQ
        jnc     IRQ_ok
        mov     [SB_IRQ],10
        call    check_IRQ
        jnc     IRQ_ok
        mov     [SB_IRQ],11
        call    check_IRQ
        jnc     IRQ_ok
        mov     al,2
        ret
    IRQ_ok:
        mov     [SB_DMA],1
        call    check_SB
        jnc     SB_ok
        mov     [SB_DMA],0
        call    check_SB
        jnc     SB_ok
        mov     [SB_DMA],3
        call    check_SB
        jnc     SB_ok
        mov     al,3
        ret
    SB_ok:
        xor     al,al
        ret
    check_IRQ:
        mov     bl,[SB_IRQ]
        mov     dx,check_SB.IRQ
        call    set_IRQ
        call    init_SB
        mov     bl,0F2h                 ; IRQ request
        call    send_to_DSP
        delay   1000
        test    [SB_IRQ],10h
        jnz     check_SB.ok
        mov     dx,[SB_port]
        add     dx,0Eh
        in      al,dx
        mov     bl,[SB_IRQ]
        call    reset_IRQ
        stc
        ret
    check_SB:
        mov     bl,[SB_IRQ]
        mov     dx,.IRQ
        call    set_IRQ
        call    init_SB
        xor     bl,bl
        xor     si,si
        mov     cx,1
        call    start_DAC_transfer
        delay   10000
        mov     al,[SB_DMA]
        or      al,100b
        out     0Ah,al
        test    [SB_IRQ],10h
        jnz     .ok
        mov     bl,[SB_IRQ]
        call    reset_IRQ
        stc
        ret
      .ok:
        and     [SB_IRQ],0Fh
        mov     bl,[SB_IRQ]
        call    reset_IRQ
        clc
        ret
      .IRQ:
        IRQ_enter
        push    eax edx ds
        push    main_data
        pop     ds
        or      [SB_IRQ],10h
        mov     dx,[SB_port]
        add     dx,0Eh
        in      al,dx
        mov     al,20h
        out     20h,al
        out     0A0h,al
        pop     ds edx eax
        IRQ_leave

init_SB:
        mov     dx,[SB_port]
        add     dx,6
        mov     al,1
        out     dx,al
        push    dx
        delay   4
        pop     dx
        xor     al,al
        out     dx,al
        push    dx
        delay   100
        pop     dx
        add     dx,-6+0Eh
        in      al,dx
        shl     al,1
        jnc     SB_init_error
        add     dx,-0Eh+0Ah
        in      al,dx
        sub     al,0AAh
        jnz     SB_init_error
        ret
    SB_init_error:
        mov     al,1
        ret

programm_DMA:
; bh = DMA mode
; bl = page
; si = offset
; cx = length
        mov    al,[SB_DMA]
        movzx  dx,al
        or     al,100b
        out    0Ah,al
        out    0Ch,al
        mov    al,dl
        or     al,bh
        out    0Bh,al
        shl    dx,1
        mov    ax,si
        out    dx,al
        mov    al,ah
        out    dx,al
        inc    dx
        mov    al,cl
        out    dx,al
        mov    al,ch
        out    dx,al
        shr    dx,1
        sub    dx,1
        jc     DMA0
        jnz    DMA_page
        mov    dx,3
        jmp    DMA_page
      DMA0:
        mov    dx,7
      DMA_page:
        add    dx,80h
        mov    al,bl
        out    dx,al
        mov    al,[SB_DMA]
        out    0Ah,al
        ret

send_to_DSP:
; bl = value to send
        mov     dx,[SB_port]
        add     dx,0Ch
    DSP_not_ready:
        in      al,dx
        shl     al,1
        jc      DSP_not_ready
        mov     al,bl
        out     dx,al
        ret

set_SB_frequency:
; ecx = frequency
        mov     bl,40h
        call    send_to_DSP
        xor     edx,edx
        mov     eax,1000000
        div     ecx
        neg     al
        mov     bl,al
        call    send_to_DSP
        ret
