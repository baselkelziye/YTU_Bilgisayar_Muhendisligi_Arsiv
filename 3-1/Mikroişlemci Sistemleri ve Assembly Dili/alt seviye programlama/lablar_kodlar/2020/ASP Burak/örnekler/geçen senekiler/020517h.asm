		public toplama
mycodes	segment para 'code'
		assume cs:mycodes
toplama proc far 
	; yigindan aldigi 2 wordu topla , sonucu dx:ax'den dondur. 

		push bp		; yigindaki parametreler erismek icin kullanilacak
		mov bp,sp	; bp ve sp yiginin en ustunu gostersin 
		xor dx,dx	; toplamda high word olacak, sifirlayalim
		mov ax,[bp+8] ; sayiw1 yigindan ax'e alalim. 
		add ax,[bp+6] ; sayiw2'i ekleyelimç 
		adc dx,0	; elde olabilir bunu dx'e tasiyalim. 
		
		pop bp		; sakladigimi degerleri ters sirada yigindan almaliyiz  
		ret 4		; ret 4 oldugu icin caðýran tarafta pop etmeye gerek yok
toplama endp
mycodes	ends
		end 
		
			