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
; Data
var_ccc: dd  	0
var_ddd: dd  	0
var_eee: dd  	0
tmp_1005_ddd_eee: dd  0
tmp_1009_ddd_eee: dd  0
tmp_1013_ddd_eee: dd  0
tmp_1017_ddd_eee: dd  0
tmp_1021_ddd_eee: dd  0

START_CODE:

; Code
    mov eax, var_ddd ;add
    add eax, var_eee
    mov [var_tmp_1005_ddd_eee], eax
    mov eax, tmp_1005_ddd_eee ;assign
    mov [ccc], eax ;assign
    mov eax, var_ddd ;sub
    sub eax, var_eee
    mov [var_tmp_1009_ddd_eee], eax
    mov eax, tmp_1009_ddd_eee ;assign
    mov [ccc], eax ;assign
    mov eax, ddd ;mul
    mul  dword [eee]
    mov [var_tmp_1013_ddd_eee], eax
    mov eax, tmp_1013_ddd_eee ;assign
    mov [ccc], eax ;assign
    mov eax, ddd ;div
    div  dword [eee]
    mov [var_tmp_1017_ddd_eee], eax
    mov eax, tmp_1017_ddd_eee ;assign
    mov [ccc], eax ;assign
    mov eax, ddd ;div
    div  dword [eee]
    mov  eax, edx
    mov [var_tmp_1021_ddd_eee], eax
    mov eax, tmp_1021_ddd_eee ;assign
    mov [ccc], eax ;assign


END_CODE:
    ;End of program

