aa: dd  0
dddd: dd  0
; Data
tmp_1002_ddd_ccc: tmp_1002_ddd_ccc: tmp_1002_ddd_ccc: tmp_1002_ddd_cc  0
tmp_1004_aaaa_ddd: tmp_1004_aaaa_ddd: tmp_1004  0

START_CODE:

; Code
declfunc: ;-------- function declfunc -----------

    mov ax, ddd ;add
    add ax, ccc
    add ax, ddd
    mov [ddd], ax ;assign
    ret    ;declfunc


