; EXE tipinde farklý bir kesimdeki FAR yordami çaðýrma
; Topla isimli yordama 2 tane byte tipinde parametreyi YIGINDAN 
; aktarip , sonucda olusan WORD'u AX geri alacagiz. 
extrn topla:far			; harici topla isimli FAR tipindeki yordami tanimla
						; link asamasinda topla isimli yordami barindiran
						; OBJ kodu ile birlikte LÝNK edilmesi halinde
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
						; yigina koyuyoruz. ancak bunu cagirilan yordam 
						; yigindan kaldiracak 
		call topla		;harici yordami cagir. 
		mov sonuc, ax		; donus degerini AX alaiyorum. 
		ret 
ana 	endp

r2d2	ends
		end ana