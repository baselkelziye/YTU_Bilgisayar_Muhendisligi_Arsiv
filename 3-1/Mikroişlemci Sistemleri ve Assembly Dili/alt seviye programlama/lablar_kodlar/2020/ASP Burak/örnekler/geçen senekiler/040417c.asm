mystack	segment para stack 'yigin'
		dw 20 dup(?)		;yiginin bizim i�imiz i�in yeterli
							; ancak elaman say�s� 30-40-50 olsa ne olacakti?
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
l1:		push [si]		; elemanlar� y�g�na koy 
		add si,2		; word tipindeki dizi sonraki eleman 2 ileride 
		loop l1
		mov cx,eleman 
		lea si,dizi1
l2:		pop [si]		; elemanlar� ters sirali olarak y�g�ndan al 
		add si,2		; word dizi olduggu icin artim cift 
		loop l2
		
		ret
ana		endp
	
mycode	ends
		end ana