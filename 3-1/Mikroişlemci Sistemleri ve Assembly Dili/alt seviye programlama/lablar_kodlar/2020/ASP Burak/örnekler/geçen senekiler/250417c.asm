myss	segment para stack 'yigin'
		dw 12 dup (?)
myss	ends
myds	segment para 'data'
dizi 	db 1,1, 10 dup(?)
eleman 	dw 10 
myds	ends		
mycs	segment para 'code'
		assume cs:mycs, ss:myss, ds:myds 
fibon	proc far
		push ds
		xor ax,ax
		push ax
		mov ax,myds
		mov ds,ax
		mov cx,eleman
		lea si,dizi
l1:		mov al,[si]
		add al,[si+1]
		mov [si+2],al
		inc si
		loop l1 
		ret 
fibon 	endp
mycs	ends
		end fibon 
	