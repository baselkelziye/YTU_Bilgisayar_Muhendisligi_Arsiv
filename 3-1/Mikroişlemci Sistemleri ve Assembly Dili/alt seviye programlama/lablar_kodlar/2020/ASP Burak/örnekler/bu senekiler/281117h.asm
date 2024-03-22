; topla isimli yordam 2 byte degeri yigindan alarak toplay�p sonucunu 
; yine yigina birarak doner
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
		adc ah,0
		mov [bp+6],ax	; sonuc, buyuklugu itibari ile giris parametresi ile 
					; ayn� . bu neden ile ayn� y�g�n adresi uzerinden doner
		pop bp		; sakladigimiz BP degerini geri alalim.
		ret 
topla	endp
abc		ends
		end				; bu kendi basina calismayacagi icin end pseudo
						; komutundan sonra yordam ismi YAZILMAZ....