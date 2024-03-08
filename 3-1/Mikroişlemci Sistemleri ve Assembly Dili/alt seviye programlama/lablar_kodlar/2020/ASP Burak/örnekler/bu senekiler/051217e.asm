; macro kullanim ornegi 

myss	segment para stack 'stack'
		dw 12 dup(?)
myss	ends
myds	segment para 'data'
dizi 	dw 1,2,3,4,5,6,7,8,9,10
eleman	dw 10
myds	ends
mycs	segment para public 'code'
		assume cs:mycs, ss:myss, ds:myds
pop_all		macro
			pop di
			pop si
			pop dx
			pop cx
			pop bx
			pop ax
			endm 	
		
		push_all	macro 
			push ax
			push bx
			push cx
			push dx
			push si
			push di
			endm

			
ana 	proc far
		push ds
		xor ax,ax
		push ax
		mov ax,myds
		mov ds,ax
		push_all
		pop_all
		
		ret 
ana 	endp

	
mycs	ends
		end ana 