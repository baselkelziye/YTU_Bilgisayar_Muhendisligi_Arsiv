; COM tipinde kesim ici yordam �a��rma
; Topla isimli yordama AL ve AH giri� parametresi, 
; islem sonucu da AX uzerinden donecek 
r2d2	segment para 'code'
		assume cs:r2d2, ss:r2d2, ds:r2d2
		org 100h 
ana		proc near
		mov al,sayi1
		mov ah,sayi2
		call topla
		mov sonuc,ax
		ret 
ana 	endp
topla	proc near
		push bx
		mov bl,ah
		xor ah,ah
		add al,bl
		adc ah,0
		pop bx
		ret 
topla	endp
sayi1 	db 5 
sayi2	db 75 
sonuc	dw ?
r2d2	ends
		end ana 