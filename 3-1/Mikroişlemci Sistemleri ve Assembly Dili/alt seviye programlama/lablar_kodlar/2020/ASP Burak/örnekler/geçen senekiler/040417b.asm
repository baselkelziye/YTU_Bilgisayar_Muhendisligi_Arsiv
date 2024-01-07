mystack	segment para stack 'yigin'
		dw 20 dup(?)
mystack	ends
mydata	segment para 'veri'
dizi1	db 3,5,7,9,2
dizi2  	db 5 dup(?)
eleman	dw 5
mydata 	ends
mycode	segment para 'kod'
		assume cs:mycode, ss:mystack, ds:mydata
ana		proc far
		; dönüþa adreslerinin yýðýna saklanmasý 
		push ds
		xor ax,ax
		push ax
		; kendi veri alanýna eriþmek için yapýlmasý gerekenler 
		mov ax,mydata
		mov ds,ax
		; iþlemin esas kýsmý bundan sonra baþlar
		
		mov cx,eleman 	; iþlemin tekrar sayýsý 
		lea si,dizi1	; dizi1'in ilk adresini gösterir.
		lea di,dizi2	; dizi2'in ilk adresi 
		add di,eleman	
		dec di			; dizi2 nin son adresi 
l1:		mov al,[si]
		mov [di],al
		inc si			; dizi1'in indisini arttir. 
		dec di			; dizi2'nin indisini azalt
		loop l1
		ret
ana		endp
	
mycode	ends
		end ana