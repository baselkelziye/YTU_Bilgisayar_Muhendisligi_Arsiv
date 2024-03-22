public topla		; bu yordamýn basþkalarý tarafýndan kullanýlacaginý
					; gosterir.
abc		segment para 'code'
		assume cs:abc
topla	proc far    ; yordam kesim icinde ancak far tanýmlý 
					; oldugu icin CS yazmacý yýgýna girip cikacak..
		push bx
		mov bl,ah
		xor ah,ah
		add al,bl
		adc ah,0
		pop bx
		ret 
topla	endp
abc		ends
		end				; bu kendi basina calismayacagi icin end pseudo
						; komutundan sonra yordam ismi YAZILMAZ....