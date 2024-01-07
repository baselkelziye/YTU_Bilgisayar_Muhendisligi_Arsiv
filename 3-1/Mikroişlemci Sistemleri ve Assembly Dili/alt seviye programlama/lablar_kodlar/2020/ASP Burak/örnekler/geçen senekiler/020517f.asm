		public toplama
mycodes	segment para 'code'
		assume cs:mycodes
toplama proc far 
	; yigindan aldigi 2 wordu topla , sonucu yine yigindan dondur. 
	;burada kullanilacak yazmaclarin oncekid egerlerinin bozulamsini engelle
		push ax	
		push dx		; ax ve dx toplam icin
		push bp		; yigindaki parametreler erismek icin kullanilacak
		mov bp,sp	; bp ve sp yiginin en ustunu gostersin 
		xor dx,dx	; toplamda high word olacak, sifirlayalim
		mov ax,[bp+12] ; sayiw1 yigindan ax'e alalim. 
		add ax,[bp+10] ; sayiw2'i ekleyelimç 
		adc dx,0	; elde olabilir bunu dx'e tasiyalim. 
		mov [bp+10],ax ; ustte kalan parametre toplamin low wordu olacak 
		mov [bp+12],dx ; altta kalan parametre toplamin high wordu olacak 
		pop bp		; sakladigimi degerleri ters sirada yigindan almaliyiz  
		pop dx
		pop ax
		ret 
toplama endp
mycodes	ends
		end 
		
			