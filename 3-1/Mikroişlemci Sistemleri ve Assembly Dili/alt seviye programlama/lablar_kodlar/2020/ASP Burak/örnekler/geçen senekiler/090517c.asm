myss	segment para stack 'stack'
		dw 12 dup(?)
myss	ends
myds	segment para 'data'
msg1	db 'merhaba dunya','$'
msg2 	db 'macro kullanýmý','$'
myds	ends
mycs	segment para 'code'
		assume cs:mycs,ss:myss, ds:myds
main 	proc far 
		push ds
		xor ax,ax
		push ax
		mov ax,myds
		mov ds,ax
		lea dx,msg1
		mov ah,09h
		int 21h 
		ret 
main 	endp
mycs	ends
		end main 
		
			