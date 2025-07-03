dd: dd  10
; Data
aa: dd  0
bb: dd  0
cc: db  0
tmp_1004_cc_12: db  0
tmp_1011_tmp_1010_2: tmp_1011_tmp_1010_2: tmp_1011_tmp_1010_2: tmp  0

START_CODE:

; Code
    cwd cc ; cast u32 to u8
    mov ax, cc ;add
    add ax, 12
    mov [tmp_1004_cc_12], ax
    mov ax, tmp_1004_cc_12 ;assign
    mov [aa], ax ;assign
    call func1
    mov [call_1007_func1_void], ax
    mov ax, call_1007_func1_void ;assign
    mov [aa], ax ;assign

func1: ;-------- function func1 -----------
    mov ax, tmp_1010 ;add
    add ax, 2
    mov [tmp_1011_tmp_1010_2], ax
    mov ax, tmp_1011_tmp_1010_2
    ret    ;func1


