; Data
ccc: dd  0
ddd: dd  0
eee: dd  0
fff: dd  0
tmp_1005_eee_fff: dd  0
tmp_1006_ddd_tmp_1005_eee_fff: dd  0

START_CODE:

; Code
    mov ax, eee ;mul
    mul  ax
    mov [tmp_1005_eee_fff], ax
    mov ax, ddd ;add
    add ax, tmp_1005_eee_fff
    mov [ccc], ax ;assign

