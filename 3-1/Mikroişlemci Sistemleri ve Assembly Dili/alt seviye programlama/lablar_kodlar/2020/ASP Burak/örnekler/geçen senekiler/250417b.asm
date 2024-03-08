myseg	segment para 'myseg1'
		org 100h 
		assume cs:myseg, ss:myseg, ds:myseg 
verim:	jmp fibon
dizi 	db 1,1, 10 dup(?)
eleman 	dw 10 		
fibon	proc near
		mov cx,eleman
		lea si,dizi
l1:		mov al,[si]
		add al,[si+1]
		mov [si+2],al
		inc si
		loop l1 
		ret 
fibon 	endp
myseg	ends
		end verim 
		