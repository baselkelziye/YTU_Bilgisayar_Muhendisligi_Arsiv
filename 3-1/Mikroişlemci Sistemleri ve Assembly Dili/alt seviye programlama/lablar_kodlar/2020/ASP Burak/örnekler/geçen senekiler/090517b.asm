		public dizitop
		extrn eleman:word, dizi:byte, toplam:word
mycodes	segment para 'code'
		assume cs:mycodes
dizitop proc far 
		; kullanacaðým yazmaçlarýn önceki deðerlerini saklamalýyým
		push ax
		push cx
		push si
		pushf 	; þart deðil ama çok isterseniz yaparsýnýz 
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
		
			