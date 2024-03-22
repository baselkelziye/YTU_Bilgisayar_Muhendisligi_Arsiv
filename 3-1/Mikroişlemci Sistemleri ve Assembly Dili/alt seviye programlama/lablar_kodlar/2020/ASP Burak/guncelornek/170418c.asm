; yordama parametre aktarimi 
; parametrelern dizi elemanlar� oldugunu dusunerek 
; AX ve BX uzerinden yollanan iki i�aretsiz say�dan olusan parametre
; aras�ndaki fark� bularak yine yazma� �zerinden d�nd�ren program 
; donuste ax<- parm1 - parm2 
; 		  bx<- parm2 - parm1 olsun 
extrn 	yavru:far
myss	segment para stack 'yigin'
		dw 12 dup(?)
myss	ends
myds 	segment para 'data'
parm1 	dw 5,10,20,30,40
parm2   dw 10,20,30,40,50 
p1_2	dw 5 dup (?)  			; parm1 - parm2
p2_1 	dw 5 dup (?)			; parm2 - parm1
eleman 	dw 5 					; 5 elemanl� dizi i�in 
myds	ends
mycs	segment para 'cd'
		assume cs: mycs, ss:myss, ds:myds
ana 	proc far
		push ds
		xor ax,ax
		push ax
		mov ax, myds
		mov ds,ax
		xor si,si
		mov cx,eleman
l1:		
		; parametreleri ilgili yazma�lar� koyal�m 
		mov ax, parm1[si]
		mov bx, parm2[si]
		call yavru 
		; donus degerlerini ilgli degiskenler aktar
		mov p1_2[si],ax		
		mov p2_1[si],bx 
		add si,2 			; word tan�ml� diziler ile i�lem yap�l�yotr
		loop l1 
		ret 
ana 	endp 
mycs	ends
		end ana  