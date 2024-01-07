		extrn	toplama:far
myss	segment para stack 'stack'
		dw 12 dup(?)
myss	ends
myds	segment para 'data'
sayi1	db 18h
sayi2 	db 0eeh
toplam 	dw ?
myds	ends
mycs	segment para 'code'
		assume cs:mycs,ss:myss, ds:myds
main 	proc far 
		push ds
		xor ax,ax
		push ax
		mov ax,myds
		mov ds,ax
		mov al,sayi1
		mov ah,sayi2
		call toplama 
		mov toplam,ax
		ret 
main 	endp
mycs	ends
		end main 
		
			