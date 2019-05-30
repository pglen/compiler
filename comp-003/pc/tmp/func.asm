var5: dd  0
var5: dd  0
var5: dd  0
var5: dd  0
aa: dd  100
var5: dd  0
aa: dd  100
; Data
var1: dd  0
var2: db  32
var3: dd  0
tmp_1047_var2_var3: dd  0
tmp_1048_var1_tmp_1047_var2_var3: dd  0
var4: dd  0
tmp_1053_bb_cc: tmp_1053_bb_cc: tmp_1053_bb_cc: tmp_1053_bb_cc: tmp_1053_  0
tmp_1055_ee_ff: tmp_1055_ee_ff: tmp_1055_  0
tmp_1059_bb_cc: tmp_1059_bb_cc: tmp_1059_bb_cc: tmp_1059_bb_cc: tmp  0
tmp_1065_ee_ff: tmp_1065_ee_ff: tmp_1065_ee_ff: tmp_1065_ee_ff: tmp_1  0
tmp_1071_qq_vv: tmp_1071_qq_vv: tmp_1071_  0
aaa: dd  0
tmp_1076_ee_ff: tmp_1076_ee_ff: tmp_1076_ee_ff: tmp_1076_ee_ff: tmp  0

START_CODE:

; Code
emptyfunc: ;-------- function emptyfunc -----------

    ret    ;

emptyfunc2: ;-------- function emptyfunc2 -----------

    ret    ;

exprfunc: ;-------- function exprfunc -----------

    mov ax, var2 ;mul
    mul  word [var3]
    mov [tmp_1047_var2_var3], ax
    mov ax, var1 ;add
    add ax, tmp_1047_var2_var3
    mov [var3], ax ;assign
    ret    ;exprfunc

declfuncarg: ;-------- function declfuncarg -----------

    mov ax, bb ;add
    add ax, cc
    mov [aa], ax ;assign
    mov ax, ee ;mul
    mul  word [ff]
    mov [dd], ax ;assign
    ret    ;declfuncarg

declfunc: ;-------- function declfunc -----------

    mov ax, bb ;add
    add ax, cc
    mov [aa], ax ;assign
    ret    ;declfunc

declfunc2: ;-------- function declfunc2 -----------

    mov ax, ee ;add
    add ax, ff
    mov [vv], ax ;assign
    mov ax, ret_1069_callfunc_arg_1068_arg_1067_gg_hh_ii ;assign
    mov [xx], ax ;assign
    mov ax, qq ;add
    add ax, vv
    mov [tmp_1071_qq_vv], ax
    ret    ;declfunc2

heaven3a: ;-------- function heaven3a -----------

    mov ax, ee ;add
    add ax, ff
    mov [cc], ax ;assign
    ret    ;heaven3a


