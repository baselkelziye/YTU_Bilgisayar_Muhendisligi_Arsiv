myseg 	segment para 'code'
		assume cs:myseg, ss:myseg,ds:myseg
		org 100h 
main	proc near
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
		mov nottop[di],ax
		add di,2		; nottop dizisi word oldugu icin artim cift olur.
		inc si			; ic cevrim indisini byte dizi oldugu icin tek arttýr
		pop cx			; dis cevrim indisini yigindan al 
		loop discev
		ret 
main	endp
notdizi	db 100,50,70,80,40,100,30,60,80,40,100,60,75,90,75
ogrsay	dw 5 		; ogrenci sayisi 
odevsay	dw 3		; odev sayýsý 
nottop	dw 5 dup(0) ; ogrecilerin not toplamalarý 	
myseg	ends
		end main 
		