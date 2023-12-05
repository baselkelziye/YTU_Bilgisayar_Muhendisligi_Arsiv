name "loops"

org 100h

mov bx, 0  ; total step counter

mov cx, 5
k1: add bx, 1         
    mov al, '1'
    mov ah, 0eh
    int 10h 
    push cx
    mov cx, 5
      k2: add bx, 1  
      mov al, '2'
      mov ah, 0eh
      int 10h      
      push cx
         mov cx, 5
         k3: add bx, 1 
         mov al, '3'
         mov ah, 0eh
         int 10h
         loop k3    ; internal in internal loop.
      pop  cx
      loop  k2      ; internal loop.
    pop cx
loop k1             ; external loop.


; wait any key...
mov ah, 1
int 21h

ret
