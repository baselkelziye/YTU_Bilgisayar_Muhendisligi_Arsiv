mystack	segment para stack 'yigin'
		dw 20 dup(?)
mystack	ends
mydata	segment para 'veri'
sayi1	db 12
sayi2  	db 23h
sonuc	dw ?
mydata 	ends
mycode	segment para 'kod'
		assume cs:mycode, ss:mystack, ds:mydata
ana		proc far
		; d�n��a adreslerinin y���na saklanmas� 
		push ds
		xor ax,ax
		push ax
		; kendi veri alan�na eri�mek i�in yap�lmas� gerekenler 
		mov ax,mydata
		mov ds,ax
		; i�lemin esas k�sm� bundan sonra ba�lar
		xor ax,ax
		mov al,sayi1
		add al,sayi2
		adc ah,0
		mov sonuc,ax
		ret
ana		endp
baba	proc far
		
		ret 
baba	endp		
mycode	ends
		end ana