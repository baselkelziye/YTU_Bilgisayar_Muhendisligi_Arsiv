; topla isimli yordam 2 byte degeri yigindan alarak toplay�p sonucunu 
; AX den  doner
public topla		; bu yordam�n bas�kalar� taraf�ndan kullan�lacagin�
					; gosterir.
abc		segment para 'code'
		assume cs:abc
topla	proc far    ; yordam kesim icinde ancak far tan�ml� 
					; oldugu icin CS yazmac� y�g�na girip cikacak..
		push bp		; kullan�c� yigina sadece BP kullarak erisir.
					; onun yiginda saklanmasi gerekir.
		mov bp,sp	; BP ile SP ayni adresi gosterecek sekide ayarlan�r
		mov ax,[bp+6] ; bu deger y�g�n organizasyonunun ne sdekilde olduguna
					; gore degisebilir. D�KKAT
		add al,ah
		mov ah,0 
		adc ah,0	; sonuc ax den donecek 
		pop bp		; sakladigimiz BP degerini geri alalim.
		ret 2		; cagiran yodamin yigina koydugu degeri oradan kaldirmak
					; icin yigina konan byte say�s� kadar bir degeri yaz.
topla	endp
abc		ends
		end				; bu kendi basina calismayacagi icin end pseudo
						; komutundan sonra yordam ismi YAZILMAZ....