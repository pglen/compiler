;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;                                                                         
;   Compile with FASM                                                     
;                                                                         
                                                                          
use32                                                                     
               org    0x0                                                 
                                                                          
               db    'SIMOS01'               ; 8 byte id                  
               dd     0x01                   ; header version             
               dd     START_CODE             ; start of code              
               dd     END_CODE               ; size of image              
               dd     0x100000               ; memory for app             
               dd     0x7fff0                ; esp                        
               dd     0x0 , 0x0              ; I_Param , I_Icon           
aa: dd  100
; Data
tmp_1004_ee_ff: tmp_1004_ee_ff: tmp_1004_ee_ff: tmp_1004_ee_ff: tmp_1  0
tmp_1006_qq_vv: tmp_1006_qq_vv: tmp_1006_  0

START_CODE:

; Code
declfunc2: ;-------- function declfunc2 -----------

    mov ax, ee ;add
    add ax, ff
    mov [aa], ax ;assign
    mov ax, qq ;add
    add ax, vv
    mov [tmp_1006_qq_vv], ax
    ret    ;declfunc2



END_CODE:
    ;End of program

