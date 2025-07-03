
virtual at 0
  event:
    .id db ?
    .data dd ?
    .size = $
end virtual

EVENT_PLACE  = 1
EVENT_PLAYER = 2
EVENT_TEXT   = 3

play:

        mov     esi,[music_data]
        mov     ecx,[music_length]
        call    play_sample

        mov     [memory_method],2
        push    control_plane
        pop     gs
        mov     ebx,[world]
        mov     esi,[ebx+4]
        add     esi,ebx
        call    prepare_plane

        mov     [memory_method],1
        mov     eax,[memory_current_end]
        mov     [place_memory],eax
        push    main_plane
        pop     gs
        mov     ebx,[world]
        mov     esi,[ebx+8]
        add     esi,ebx
        call    prepare_plane
        mov     [place_zones],esi

        mov     [rotation],1
        mov     [mouse_x],320
        mov     [mouse_y],240
        call    refresh_planes

        mov     ebx,[world]
        mov     esi,[ebx+12]
        add     esi,ebx
        call    process_event

    main_loop:
        cmp     [keyboard+KEY_ESC],1
        je      end_playing
        cmp     [clock],1
        jb      main_loop
        mov     [clock],0

        call    read_mouse

        push    control_plane
        pop     gs
        call    move_objects
        call    refresh_objects

        push    main_plane
        pop     gs
        call    move_objects
        call    sort_objects
        call    refresh_objects

        jmp     main_loop

    end_playing:
        ret

refresh_planes:
        push    main_plane
        pop     gs
        call    update_cursor
        call    refresh_plane
        push    control_plane
        pop     gs
        call    update_cursor
        call    refresh_plane
        ret

process_event:
        mov     al,[esi+event.id]
        or      al,al
        jz      event_done
        cmp     al,EVENT_PLACE
        je      event_place
        cmp     al,EVENT_PLAYER
        je      event_player
        cmp     al,EVENT_TEXT
        je      event_text
        add     esi,event.size
        jmp     process_event
    event_place:
        push    esi
        mov     eax,[place_memory]
        mov     [memory_current_end],eax
        mov     esi,[esi+event.data]
        add     esi,[world]
        push    main_plane
        pop     gs
        call    prepare_plane
        mov     [place_zones],esi
        pop     esi
        add     esi,event.size
        jmp     process_event
    event_player:
        push    esi
        mov     esi,[esi+event.data]
        add     esi,[world]
        push    main_plane
        pop     gs
        mov     edi,[gs:plane.objects]
      .find:
        mov     al,[edi]
        or      al,al
        jz      .done
        cmp     al,ID_PLAYER
        jne     .next
        mov     ecx,object.size
        rep     movsb
        jmp     .done
      .next:
        add     edi,object.size
        jmp     .find
      .done:
        call    prepare_plane_images
        pop     esi
        add     esi,event.size
        jmp     process_event
    event_text:
        push    esi
        mov     esi,[esi+event.data]
        add     esi,[world]
        push    esi
        call    refresh_planes
        pop     esi
        call    show_text
        pop     esi
        add     esi,event.size
        jmp     process_event
    event_done:
        call    refresh_planes
        ret
