; topla isimli yordam 2 byte degeri yigindan alarak toplayýp sonucunu 
; AX den  doner
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
		adc ah,0	; sonuc ax den donecek 
		pop bp		; sakladigimiz BP degerini geri alalim.
		ret 2		; cagiran yodamin yigina koydugu degeri oradan kaldirmak
					; icin yigina konan byte sayýsý kadar bir degeri yaz.
topla	endp
abc		ends
		end				; bu kendi basina calismayacagi icin end pseudo
						; komutundan sonra yordam ismi YAZILMAZ....