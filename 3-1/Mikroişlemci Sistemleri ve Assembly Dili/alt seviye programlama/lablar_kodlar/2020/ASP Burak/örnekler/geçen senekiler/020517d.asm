		public toplama
mycs	segment para public 'code'
		assume cs:mycs
toplama proc far 
		add al,ah
		mov ah,0
		adc ah,0
		ret 
toplama endp
mycs	ends
		end 
		
			