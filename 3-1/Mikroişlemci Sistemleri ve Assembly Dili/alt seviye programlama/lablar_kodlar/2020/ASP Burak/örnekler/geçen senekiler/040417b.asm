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
		; d�n��a adreslerinin y���na saklanmas� 
		push ds
		xor ax,ax
		push ax
		; kendi veri alan�na eri�mek i�in yap�lmas� gerekenler 
		mov ax,mydata
		mov ds,ax
		; i�lemin esas k�sm� bundan sonra ba�lar
		
		mov cx,eleman 	; i�lemin tekrar say�s� 
		lea si,dizi1	; dizi1'in ilk adresini g�sterir.
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