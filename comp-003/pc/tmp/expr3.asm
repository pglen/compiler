; Data
ccc: dd  0
ddd: dd  0
eee: dd  0
fff: dd  0
ggg: dd  0
tmp_1006_ddd_eee: dd  0
tmp_1007_fff_ggg: dd  0
tmp_1008_tmp_1006_ddd_eee_tmp_1007_fff_ggg: dd  0

START_CODE:

; Code
    mov ax, ddd ;add
    add ax, eee
    mov [tmp_1006_ddd_eee], ax
    mov ax, fff ;add
    add ax, ggg
    mov [tmp_1007_fff_ggg], ax
    mov ax, tmp_1006_ddd_eee ;mul
    mul  word [tmp_1007_fff_ggg]
    mov [ccc], ax ;assign

