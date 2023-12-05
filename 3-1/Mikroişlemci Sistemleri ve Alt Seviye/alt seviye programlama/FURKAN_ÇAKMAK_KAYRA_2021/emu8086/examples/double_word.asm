org 100h

jmp a
; double word definition is supported:  
mydouble dd 12345678h

; it is equal to:  
mywords   dw 5678h
          dw 1234h

;  and it is equal to:  
mybytes   db  78h
          db  56h
          db  34h
          db  12h

; exactly 32 bits  
binn dd 00010010001101000101011001111000b
; load double word to dx:ax  
a: mov ax, binn
   mov dx, [binn+2]

ret
