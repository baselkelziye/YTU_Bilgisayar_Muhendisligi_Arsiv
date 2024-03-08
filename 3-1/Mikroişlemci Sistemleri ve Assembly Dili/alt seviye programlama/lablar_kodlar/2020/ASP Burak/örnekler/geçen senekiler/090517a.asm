		extrn	dizitop:far
		public dizi,eleman, toplam 
myss	segment para stack 'stack'
		dw 12 dup(?)
myss	ends
myds	segment para 'data'
eleman 	dw 10
toplam 	dw ?
dizi	db 255,1,2,3,4,5,6,7,8,9
myds	ends
mycs	segment para 'code'
		assume cs:mycs,ss:myss, ds:myds
main 	proc far 
		push ds
		xor ax,ax
		push ax
		mov ax,myds
		mov ds,ax
		call dizitop 
		ret 
main 	endp
mycs	ends
		end main 
		
			