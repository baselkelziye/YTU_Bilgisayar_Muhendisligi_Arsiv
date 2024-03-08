; macroya parametre aktarma 
myss 	segment para stack 'yigin'
		dw 12 dup (?) 
myss	ends
myds	segment para 'data'
msg1 	db "hello world","$"
msg2	db "macroya parametre aktarma ornegi", "$"
crlf	db 0ah,0dh,"$"
myds	ends
mycs	segment para 'code'
		assume cs:mycs, ds:myds, ss:myss
		
yaz		macro txt1
		lea dx,txt1
		mov ah,09h
		int 21h 
 	endm

yazln	macro txt1
		lea dx,txt1
		mov ah,09h
		int 21h 
		lea dx,crlf
		mov ah,09h
		int 21h 
		endm		
		
ana 	proc far
		push ds
		xor ax,ax
		push ax
		mov ax,myds
		mov ds,ax
		yazln msg1
		yaz msg2
		ret
ana 	endp		

mycs	ends
		end ana 
		