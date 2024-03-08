; verilen dizi icinde bir alemanýn kac defa gectigini bulan 
; com tipindeki program tip -2
 
myseg	segment para 'code'
		org 100h
		assume cs:myseg, ds:myseg, ss:myseg
verim: 	jmp bul 							; verinin üzerinden atla gec 
dizi 	dw 2,3,4,5,6,7,7,5,3,2,7,5,3,7,7	; dizi elemanlarý
eleman	dw 15 								; dizi eleman sayýsý 		
aranan 	dw 7 								; aranacak sayý 
sayac   db 0								; 15 eleman icin db yeterli 
bul		proc near 
		mov cx, eleman		; dizinin eleman sayýsý 
		xor si,si			; indis ilk deger sifir 
		mov ax, aranan		; aranacak elemanýn degerini ax de tut
l1:		cmp dizi[si],ax		; dizi elemaný ile arananý karsilastir
		jne devam
		inc sayac			; esitlik oldu sayaci arttýr
devam:	add si,2			; dizi word artim cift 
		loop l1 
		ret 
bul 	endp
myseg	ends
		end verim 
