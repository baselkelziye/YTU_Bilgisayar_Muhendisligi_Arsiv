; EXE tipinde farkl� bir kesimdeki FAR yordami �a��rma
; Topla isimli yordama 2 tane byte tipinde parametreyi YIGINDAN 
; aktarip , sonucda olusan WORD'u yine YIGINDAN geri alacagiz. 
extrn topla:far			; harici topla isimli FAR tipindeki yordami tanimla
						; link asamasinda topla isimli yordami barindiran
						; OBJ kodu ile birlikte L�NK edilmesi halinde
						; calisir
myss	segment para stack 'stack'
		dw 12 dup (?)
myss	ends
myds	segment para 'data'
sayi1 	db 5 
sayi2	db 75 
sonuc	dw ?
myds	ends
r2d2	segment para 'code'
		assume cs:r2d2, ss:myss, ds:myds
ana		proc far
		push ds
		xor ax,ax
		push ax
		mov ax,myds
		mov ds,ax
		mov al,sayi1
		mov ah,sayi2
		push ax			; yigin bir seferde 16 bit alir. iki degeri AX ile 
						; yigina koyuyoruz
		call topla		;harici yordami cagir. 
		pop sonuc		; donus degerini y�gindan alaiyorum. 
		ret 
ana 	endp

r2d2	ends
		end ana