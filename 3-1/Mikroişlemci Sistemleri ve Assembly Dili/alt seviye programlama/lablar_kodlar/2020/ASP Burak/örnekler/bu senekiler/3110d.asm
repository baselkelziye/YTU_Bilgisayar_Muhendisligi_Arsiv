; 10 ogrenciden kac tanesinin esik degeri ve altinda oldugunu bulan program 
myss	segment para stack 'stack'
		dw 20 dup(?)
myss	ends 
myds	segment para 'data'
eleman	dw 10 ; dizinin eleman sayýsý 
yas 	db 19,21,45,18,18,10,22,21,20,9
; sinavda buyuk diziler icin yas db 100 dup(?) kullanýlacak
sayac	db 0 ; hepsi kosulu saglasa bile sayac yeter oluyor onun icin byte
esik	db 20 
myds	ends
mycs	segment para 'code'
		assume cs:mycs, ds:myds, ss:myss
ana 	proc far
		push ds		; geri donus icin gerekli degerleri 
		xor ax,ax	; yigini koymak ana yordamýn gorevidir.
		push ax		; once kesim sonra goreli konum 
		mov ax,myds	; kendi tanýmladýgým veri alanina 
		mov ds,ax	; erismek icin yapýlmasý gerekenler 
		mov cx,eleman ; cevrim sayisi
		mov al,esik	
		xor si,si
l2: 	cmp al,yas[si]
		jb l1
		inc sayac
l1: 	inc si ; dzi byte tanýmli bir sonraki eleman icin 1 artar
		loop l2 
		ret 
ana 	endp
mycs	ends
		end ana ; ilk calisacak yordamýn ismi 