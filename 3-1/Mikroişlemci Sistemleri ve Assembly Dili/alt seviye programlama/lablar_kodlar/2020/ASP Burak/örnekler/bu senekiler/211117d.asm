myss	segment para stack 'stack'
		dw 20 dup (?)
myss	ends
myds	segment para 'data'
notdizi	db 100,50,70,80,40,100,30,60,80,40,100,60,75,90,75
ogrsay	dw 5 		; ogrenci sayisi 
odevsay	dw 3		; odev sayýsý 
nottop	dw 5 dup(0) ; ogrecilerin not toplamalarý 	
snotop	dw 0		; sýnýf not toplamý 
kalan 	db 0		; kalan ogrenci sayisi 
myds	ends 		
macit	segment para 'code'
		assume cs:macit, ss:myss,ds:myds
main 	proc far 
		push ds
		xor ax,ax
		push ax
		mov ax,myds
		mov ds,ax

		mov cx,ogrsay	; dýs cevrim tekrar sayýsý
		xor si,si		; dis cevrim degiskeni notdizisine indis olacak.,
		xor di,di		; bunu nottop dizisinin indisi olrak kullan 
discev:	xor ax,ax		; toplami bulacagim yazmaci sifirlarim
		mov bx,si		; bu da toplam dizisine indis olarak kullanilacak
		push cx			; dýs cevrim tekrar sayýsýný kaybetme 
		mov cx,odevsay	; ic cevrim saysisini CX'e koy 
iccev:	add al,notdizi[bx]
		adc ah,0		; elde olanbilir unutmayalým
		add bx,ogrsay	; indisi bir sonraki sinav notunun oldugu yere getir.
		loop iccev		; ic cevrimi tamamla. 
		xor dx,dx		; toplam AX'de bunu Odev sayýsýna bolmek lazim
		div odevsay		; odevsay word iken dx:ax /odev say olacaktir.
		add dx,dx		; kalan DX'de bunun x2 kati odev saydan buyuk ise  
		cmp dx,odevsay	; AX' bir artarmalý aksi halde ayni kalmalý 
		jb devam 		; kucuk ise devam et 
		inc ax			; buyuk ise yuvarlama yap
devam:	mov nottop[di],ax ; ortalamyi diziye koyalim
		add snotop,ax	; kenardan sini not toplamini da hesaplayalim
		add di,2		; nottop dizisi word oldugu icin artim cift olur.
		inc si			; ic cevrim indisini byte dizi oldugu icin tek arttýr
		pop cx			; dis cevrim indisini yigindan al 
		loop discev
		xor dx,dx
		mov ax,snotop
		div ogrsay		; AX'de sinif ortalamasi var 
		xor si,si		; nottop dizisine indis olacak
		mov cx,ogrsay	; ogrenci sayisi kadar islem yapilacak 
l1:		cmp ax, nottop[si]	
		jbe sonraki 	; sinif ort. ogrencininkinden dusuk esit ise gecer  
		inc kalan		; aksi halde kalir.
sonraki:add si,2		; nottop dizisi word oldugu icin indis iki artat
		loop l1
		ret 
main	endp
macit	ends
		end main 
		