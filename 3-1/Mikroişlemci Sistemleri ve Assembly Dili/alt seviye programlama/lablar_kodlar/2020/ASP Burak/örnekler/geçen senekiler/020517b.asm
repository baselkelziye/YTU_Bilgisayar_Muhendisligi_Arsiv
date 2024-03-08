		public toplama
mycodes	segment para 'code'
		assume cs:mycodes
toplama proc far 
		add al,ah
		mov ah,0
		adc ah,0
		ret 
toplama endp
mycodes	ends
		end 
		
			