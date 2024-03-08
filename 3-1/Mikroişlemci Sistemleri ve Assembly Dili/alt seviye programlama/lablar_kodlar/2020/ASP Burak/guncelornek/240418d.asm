; sýralama yordamýn harici olarak kullandýran
; siralayacagi dizi ve eleman sayýsýna ortek veri(degisken) uzerinden 
; ersim yapan program 

extrn dizi:word, eleman:word
public sirala

mycodes	segment para 'codes'
		assume cs:mycodes
sirala	proc far
		; kullandýðým yazmaçlarýn önceki degerlerinin bozulmamasý icin saklarim
		push si
		push di
		push cx
		push bx
		push ax
		;  siralama iþlemi 
		xor si,si ; dýþ çevrim indisi
		mov cx, eleman
		dec cx
dis:	mov ax,dizi[si]  	;dizinin ilk elemanýný buyuk kabul et 
		mov bx,si		 	;bx de buyuk olan elemanýn indisi olsun 
		push cx				; dýþ çevrim döngü sayýsýný sakla 
		; dýþ ve iç çevrim sayýlarý ayný oldugu için CX'in yeniden ilk 
		; degerlendirmesi yapýlmasýna gerek yoktur. 
		mov di,si
ic:		add di,2			; dizi word olunca bir sonraki indir +2 ileride
		cmp dizi[di],ax		; iþaretsiz deðerlendireceðiz
		jb donus
		mov ax, dizi[di]
		mov bx,di
donus:	loop ic		
		xchg ax,dizi[si]	; dizi elemanlarýnýn yerlerini degiþtirdik. 
		mov dizi[bx],ax
		pop cx				; dýþ cevrim degerini yýgýndan geri al 
		add si,2			; dýþ cçverim indisini word dizi icin +2 yap
		loop dis
		; kullandýðým yazmaçlarýn önceki degerlerinin geri almalýyým 
		pop ax
		pop bx
		pop cx
		pop di
		pop si		
		ret 
sirala	endp
mycodes ends
		end 