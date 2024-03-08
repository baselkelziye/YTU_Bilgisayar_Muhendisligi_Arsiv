; topla isimli yordam 2 byte degeri yigindan alarak toplayýp sonucunu 
; yine yigina birarak doner
public topla		; bu yordamýn basþkalarý tarafýndan kullanýlacaginý
					; gosterir.
abc		segment para 'code'
		assume cs:abc
topla	proc far    ; yordam kesim icinde ancak far tanýmlý 
					; oldugu icin CS yazmacý yýgýna girip cikacak..
		push bp		; kullanýcý yigina sadece BP kullarak erisir.
					; onun yiginda saklanmasi gerekir.
		mov bp,sp	; BP ile SP ayni adresi gosterecek sekide ayarlanýr
		mov ax,[bp+6] ; bu deger yýgýn organizasyonunun ne sdekilde olduguna
					; gore degisebilir. DÝKKAT
		add al,ah
		mov ah,0 
		adc ah,0
		mov [bp+6],ax	; sonuc, buyuklugu itibari ile giris parametresi ile 
					; ayný . bu neden ile ayný yýgýn adresi uzerinden doner
		pop bp		; sakladigimiz BP degerini geri alalim.
		ret 
topla	endp
abc		ends
		end				; bu kendi basina calismayacagi icin end pseudo
						; komutundan sonra yordam ismi YAZILMAZ....