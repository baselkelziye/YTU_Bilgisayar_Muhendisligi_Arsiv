; EXE tipinde kesim ici yordam çaðýrma
; Topla isimli yordama AL ve AH giriþ parametresi, 
; islem sonucu da AX uzerinden donecek 
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
r2d2	ends
		end ana