; harici macro kullanim ornegi ve makroya parametre aktarimi
include makrolar.ati
myss	segment para stack 'stack'
		dw 12 dup(?)
myss	ends
myds	segment para 'data'
dizi 	dw 1,2,3,4,5,6,7,8,9,10
eleman	dw 10
myds	ends
mycs	segment para public 'code'
		assume cs:mycs, ss:myss, ds:myds
		
ana 	proc far
		push ds
		xor ax,ax
		push ax
		mov ax,myds
		mov ds,ax
		push_all
		mov ax,0ffffh
		carp2 eleman 
		pop_all
		
		ret 
ana 	endp

	
mycs	ends
		end ana 