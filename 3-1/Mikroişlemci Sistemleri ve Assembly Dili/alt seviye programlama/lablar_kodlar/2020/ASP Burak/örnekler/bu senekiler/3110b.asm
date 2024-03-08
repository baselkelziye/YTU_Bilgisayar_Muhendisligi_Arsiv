; word tanýmlý iki sayýyý toplama 
myss	segment para stack 'stack'
		dw 20 dup(?)
myss	ends 
myds	segment para 'data'
toplam	dd 0
sayi1	dw 0ae13h
sayi2 	dw 0e123h		

myds	ends
mycs	segment para 'code'
		assume cs:mycs, ds:myds, ss:myss
main 	proc far
		push ds		; geri donus icin gerekli degerleri 
		xor ax,ax	; yigini koymak ana yordamýn gorevidir.
		push ax		; once kesim sonra goreli konum 
		mov ax,myds	; kendi tanýmladýgým veri alanina 
		mov ds,ax	; erismek icin yapýlmasý gerekenler 
		xor dx,dx	; elde olmasý durumunda kullanýlacak sýfýrla 
		mov ax,sayi1
		add ax,sayi2
		adc dx,0	; toplamýn yuksek 16 biti DX, alcak 16 biti AX'de
		lea si,toplam	
		mov [si],ax
		mov [si+2],dx
		ret 
main 	endp
mycs	ends
		end main ; ilk calisacak yordamýn ismi 