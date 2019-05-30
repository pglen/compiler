; Data
ccc: dd  0
ddd: dd  0
eee: dd  0
tmp_1005_ddd_eee: dd  0
tmp_1009_ddd_eee: dd  0
tmp_1013_ddd_eee: dd  0
tmp_1017_ddd_eee: dd  0
tmp_1021_ddd_eee: dd  0

START_CODE:

; Code
    mov ax, ddd ;add
    add ax, eee
    mov [tmp_1005_ddd_eee], ax
    mov ax, tmp_1005_ddd_eee ;assign
    mov [ccc], ax ;assign
    mov ax, ddd ;sub
    sub ax, eee
    mov [tmp_1009_ddd_eee], ax
    mov ax, tmp_1009_ddd_eee ;assign
    mov [ccc], ax ;assign
    mov ax, ddd ;mul
    mul  word [eee]
    mov [tmp_1013_ddd_eee], ax
    mov ax, tmp_1013_ddd_eee ;assign
    mov [ccc], ax ;assign
    mov ax, ddd ;div
    div  word [eee]
    mov [tmp_1017_ddd_eee], ax
    mov ax, tmp_1017_ddd_eee ;assign
    mov [ccc], ax ;assign
    mov ax, ddd ;div
    div  word [eee]
    mov [tmp_1021_ddd_eee], ax
    mov ax, tmp_1021_ddd_eee ;assign
    mov [ccc], ax ;assign

