; byte tan�ml� iki say�y� toplama 
myss	segment para stack 'stack'
		dw 20 dup(?)
myss	ends 
myds	segment para 'data'
sayi1	db 13
sayi2 	db 0e3h		
toplam	dw 0
myds	ends
mycs	segment para 'code'
		assume cs:mycs, ds:myds, ss:myss
main 	proc far
		push ds		; geri donus icin gerekli degerleri 
		xor ax,ax	; yigini koymak ana yordam�n gorevidir.
		push ax		; once kesim sonra goreli konum 
		mov ax,myds	; kendi tan�mlad�g�m veri alanina 
		mov ds,ax	; erismek icin yap�lmas� gerekenler 
		xor ax,ax	; toplam icin ax kullan�lacak s�f�rla
		mov al,sayi1; ilk say� al de 
		add al,sayi2; ikinci sayiyi al ye ekle 
		adc ah,0	; elde olu�ma olas�l�g� var unutma 
		mov toplam,ax ; ax de elde edilen degeri veri kesimine sakla 
		ret 
main 	endp
mycs	ends
		end main ; ilk calisacak yordam�n ismi 