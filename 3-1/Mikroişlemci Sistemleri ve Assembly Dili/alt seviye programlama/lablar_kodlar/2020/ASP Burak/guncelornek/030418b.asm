; verilen dizi icinde bir aleman�n kac defa gectigini bulan 
; com tipindeki program tip -1 
myseg	segment para 'code'
		org 100h
		assume cs:myseg, ds:myseg, ss:myseg
bul		proc near 
		mov cx, eleman		; dizinin eleman say�s� 
		xor si,si			; indis ilk deger sifir 
		mov ax, aranan		; aranacak eleman�n degerini ax de tut
l1:		cmp dizi[si],ax		; dizi eleman� ile aranan� karsilastir
		jne devam
		inc sayac			; esitlik oldu sayaci artt�r
devam:	add si,2			; dizi word artim cift 
		loop l1 
		ret 
bul 	endp
dizi 	dw 2,3,4,5,6,7,7,5,3,2,7,5,3,7,7	; dizi elemanlar�
eleman	dw 15 								; dizi eleman say�s� 		
aranan 	dw 7 								; aranacak say� 
sayac   db 0								; 15 eleman icin db yeterli 
myseg	ends
		end bul 
