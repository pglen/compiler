; Data
var1: db  0
var2: dd  200
tmp_1007_var1_var2: dd  0
var3: dd  0

START_CODE:

; Code
    mov ax, var1 ;add
    add ax, var2
    mov [tmp_1007_var1_var2], ax
    mov [var3], ax

