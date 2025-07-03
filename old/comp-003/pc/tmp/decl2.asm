; Data
tmp_1002_200_300: ø²¿1	˜äÓŽE  0
var_bbb: dw  0
var_ddd: dd  	10

START_CODE:

; Code
    mov eax, var_200 ;add
    add eax, var_300
    mov [tmp_1002_200_300], eax
    mov [bbb], eax

