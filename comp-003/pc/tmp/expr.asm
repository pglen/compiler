; Data
pp: dd  0
qq: dd  0
hh: dd  0
ff: dd  0
gg: dd  0
tmp_1013_gg_hh: dd  0

START_CODE:

; Code
    mov eax, gg ;div
    div  dword [hh]
    mov  eax, edx
    mov [ff], eax ;assign

