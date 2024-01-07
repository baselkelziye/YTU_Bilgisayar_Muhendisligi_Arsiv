; harici siralama yordamini kullanarak ve sahip oldugu diziyi referans ile 
; paylaþarak calisan program 
extrn sirala:far
public dizi, eleman

myss 	segment para stack 'yigin'
		dw 12 dup (?) 
myss	ends
myds	segment para 'data'
dizi	dw 1,2,3,4,5,6,7,8,9,10
eleman 	dw 10 
myds	ends
mycs	segment para 'code'
		assume cs:mycs, ds:myds, ss:myss
ana 	proc far
		push ds
		xor ax,ax
		push ax
		mov ax,myds
		mov ds,ax
		; 
		call sirala
		;
		ret
ana 	endp
mycs	ends
		end ana 
		