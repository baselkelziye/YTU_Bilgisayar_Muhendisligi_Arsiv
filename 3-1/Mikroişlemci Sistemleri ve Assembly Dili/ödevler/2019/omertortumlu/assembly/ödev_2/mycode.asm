myss segment para stack 'stack'
    dw 500 dup(?)
myss ends
myds segment para 'data'
   
dizi1 db  0Dh, 18h, 1Fh, 0FBh, 28h, 0Bh, 01h, 34h, 14h, 0FFh
dizi2 db  01h, 02h, 03h, 1Bh, 0Ah, 0Ah, 0FFh, 19h, 042h, 0FFh 
sonuc dw  20 dup(0)
n     dw  0ah
myds ends
mycs segment para 'code'
    assume cs:mycs,ds:myds,ss:myss    ;omertortumlu-16011110
main proc far
      push ds
      xor ax,ax
      push ax
      mov ax,myds
      mov ds,ax
      xor bx,bx
      mov cx,n 
l1:   xor ax,ax
      mov al,dizi1[bx]
      push ax  
      mov al,dizi2[bx] 
      push ax
      call carp    ;002C
      shl bx,1
      pop sonuc[bx]
      shr bx,1
      add bx,1
      loop l1
      retf   
main endp 
carp proc near    ;002C
      push bp
      push bx
      push dx
      mov bp,sp
      mov bx,[bp+08h]
      mov dx,[bp+0ah]
      cmp bx,1
      jnz l2      
      mov [bp+0ah],dx 
      jmp l3      
l2:   test bx,01h  ;0042
      jz l4       
      shr bx,1
      push bx
      mov bx,dx
      shl dx,1
      push dx
      call carp
      pop [bp+0ah]
      add [bp+0ah],bx
      jmp l3      
l4:   shr bx,1     ;005C
      shl dx,1
      push dx
      push bx
      call carp
      pop [bp+0ah]
l3:   pop dx       ;0068
      pop bx
      pop bp
      ret 2   
    carp endp
mycs ends
    end main
    