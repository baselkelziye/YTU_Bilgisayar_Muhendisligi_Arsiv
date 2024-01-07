myss	segment para stack 'stack'
		dw 12 dup(?)
myss	ends
myds	segment para 'data'
msg1	db 'merhaba dunya','$'
msg2 	db 'macro kullanýmý','$'
ln		db 0ah,0dh,'$'
myds	ends
mycs	segment para 'code'
		assume cs:mycs,ss:myss, ds:myds

		
yazdirln macro necla
		yazdir necla
		yazdir ln 
		endm
yazdir	macro mualla	
		lea dx,mualla
		mov ah,09
		int 21h
		endm
main 	proc far 
		push ds
		xor ax,ax
		push ax
		mov ax,myds
		mov ds,ax
		yazdirln msg1
		yazdirln msg2
		ret 
main 	endp

mycs	ends
		end main 
		
			