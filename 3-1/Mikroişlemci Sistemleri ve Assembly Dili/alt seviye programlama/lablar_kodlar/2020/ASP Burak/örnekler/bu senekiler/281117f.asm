public topla		; bu yordam�n bas�kalar� taraf�ndan kullan�lacagin�
					; gosterir.
abc		segment para 'code'
		assume cs:abc
topla	proc far    ; yordam kesim icinde ancak far tan�ml� 
					; oldugu icin CS yazmac� y�g�na girip cikacak..
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