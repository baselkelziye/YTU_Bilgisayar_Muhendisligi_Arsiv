		public dizitop
		extrn eleman:word, dizi:byte, toplam:word
mycodes	segment para 'code'
		assume cs:mycodes
dizitop proc far 
		; kullanaca��m yazma�lar�n �nceki de�erlerini saklamal�y�m
		push ax
		push cx
		push si
		pushf 	; �art de�il ama �ok isterseniz yapars�n�z 
		lea si,dizi
		mov cx,eleman 
		xor ax,ax
l1:		add al,[si]
		adc ah,0
		inc si
		loop l1
		mov toplam,ax
		popf
		pop si
		pop cx
		pop ax
		ret 
dizitop endp
mycodes	ends
		end 
		
			