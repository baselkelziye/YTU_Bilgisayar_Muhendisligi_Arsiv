myStack segment para stack 'stack'
    dw 20 dup(?)
myStack ends
myData segment para 'data'
    
    tekTop DD 0
    ciftTop DD 0
    dizi DW 3,5,9,12,0,6,5,13
    tekSay DW 0
    ciftSay DW 0
    eleman DW 8
    tekOrt DW 0
    ciftOrt DW ?
myData ends
myCode segment para 'code'
    assume cs:myCode,ss:myStack,ds:myData
ANA proc far
    push ds
    xor ax,ax
    push ax 
    mov ax,myData
    mov ds,ax
    mov cx,eleman
    lea SI,dizi
don:mov ax , [SI]
    ;shr ax , 1
    test ax,1
    jz cift
    add word ptr[tekTop],ax
    add word ptr[tekTop+2],0
    inc tekSay
    jmp arttir
cift:add word ptr[ciftTop],ax
    add word ptr[ciftTop+2],0
    inc ciftSay
arttir:add SI,2
    loop don
    mov dx,word ptr[tekTop+2]
    mov ax,word ptr[tekTop]
    div tekSay
    mov tekOrt,ax
    mov dx,word ptr[tekTop+2]
    mov ax,word ptr[tekTop]
    div tekSay
    mov tekOrt,ax    
    retf
endp
ends
end ANA
    
