mystack	segment para stack 'yigin'
		dw 20 dup(?)		
mystack	ends
mydata	segment para 'veri'
dizi1	dw 3,5,7,9,2
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
		lea si,dizi1
		mov di,cx		; di dizinin son indisini g�stermeli
		shl di,1		; bunun icin dizin eleman say�s� x eleman tipi-2  
		sub di,2		; i�lemi yapilmali 
		add di,si
		shr cx,1		; i�lem say�s� eleman say�s�n�n yar�s� olmal� 
l1:		mov ax,[si]		; bastaki elaman� al sondaki ile yer degisitir.
		xchg [di],ax
		mov [si],ax
		add si,2		; dizi word indisler 2ser 2ser de�i�meli 
		sub di,2
		loop l1 
		ret
ana		endp
	
mycode	ends
		end ana