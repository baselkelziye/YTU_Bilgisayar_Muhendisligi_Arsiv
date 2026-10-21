myss SEGMENT PARA STACK 'STACK'
	db 20 dup(?) 

myss ENDS

myds SEGMENT PARA 'DATA'
    CR EQU 13
    LF EQU 10
    MSG1 DB '.nci sayi :',0 
    Msg2 DB 'Dizinin boyutunu giriniz:',0
    buyukhata db cr,lf, 'Dikkat!!! Deger 0-100 arasinda olsun' , 0
    hata db cr,lf, 'Dikkat!!!' , 0
    bosmsg db cr,lf, '' , 0
    dizi db 100 dup(?)
    pivot    db  ?
    n dw ?
    son db ?
myds ends

mycs segment para 'code'
assume cs:mycs ,ss:myss ,ds:myds
ana proc far
	push ds
	xor ax,ax
	push ax
	mov ax,myds
	mov ds,ax
   
albak:	
	mov ax,offset msg2
	call put_str
	call getn
	cmp ax,100
	jg error1
	cmp ax,0
	jle error1
	mov n,ax
	jmp atla1
error1:
	mov ax,offset buyukhata
	call put_str
	jmp albak
	
atla1:		
	xor cx,cx
	mov cx,n
	xor si,si
	
input: 
    mov ax,offset bosmsg
    call put_str
    push ax
    mov ax,si
    inc ax
    call putn
    pop ax
	mov ax,offset msg1 
	call put_str
	call getn
	mov dizi[si],al
	inc si
	dec cx
	cmp cx,0
	jne input
      
    xor ax,ax
	mov ax,n
	mov son,al
	
call quick
	  
	xor cx,cx
	mov cx,n
	xor si,si      
              
yazdir: 
    mov ax,offset bosmsg
    call put_str 
    push ax
    mov ax,si
    inc ax
    call putn
    pop ax
    mov ax,offset msg1  
    call put_str
    mov  al,dizi[si] 
    call putn
	inc si
	dec cx
	cmp cx,0
	jne yazdir

	;call getn kullanicidan deger aliniyor
	;mov ax,offset cumle cumlenin ilk adresi ax e ataniyor
	;call put_str   cumle yazdiriliyor
	;call putn   ax te ne varsa yazdırıyor 
	;putc al de hangi simge varsa o yazdiriliyor
	retf
ana endp   

quick proc NEAR 

    ret
 quick endp

 partition proc NEAR 
             
     ret
 partition endp 


getc proc near
	mov ah,1h
	int 21h
	ret
getc endp

putc proc near
	push ax
	push dx
	mov dl,al
	mov ah,2
	int 21h
	pop dx
	pop ax
	ret
putc endp

getn proc near
		push bx
		push cx
		push dx
	getn_start:
		mov dx,1
		xor bx,bx
		xor cx,cx
	new:
		call getc
		cmp al,cr
		je fin_read
		cmp al,'-'
		jne ctrl_num
	negatif:
		mov dx,-1
		jmp new
	ctrl_num:
		cmp al,'0'
		jb error
		cmp al,'9'
		ja error
		sub al,'0'
		mov bl,al
		mov ax,10
		push dx
		mul cx
		pop dx
		mov cx,ax
		add cx,bx
		jmp new
	error:
		mov ax,offset hata
		call put_str
		jmp getn_start 
	fin_read:
		mov ax,cx
		cmp dx,1
		je fin_getn
		neg ax
	fin_getn:
		pop dx
		pop cx
		pop dx
	ret
getn endp

putn proc near
		push cx
		push dx
		xor dx,dx
		push dx
		mov cl,10
		cmp al,0
		jge hesapla 
		neg al
		push ax
		mov al,'-'
		call putc
		pop ax 
	
	hesapla:
		div cx
		add dl,'0'
		push dx
		xor dx,dx
		cmp al,0
		jne hesapla
	goruntu:
		pop ax
		cmp al,0
		je end_goruntu
		call putc 
		jmp goruntu 
		
	end_goruntu:
		pop dx
		pop cx
	ret
putn endp

put_str proc near
		push bx
		mov bx,ax
		mov al, byte ptr[bx]
	put_loop:
		cmp al,0
		je put_fin
		call putc 
		inc bx			
		mov al,byte ptr[bx]
		jmp put_loop
	put_fin:
		pop bx
	ret
put_str endp


mycs ends
end ana



