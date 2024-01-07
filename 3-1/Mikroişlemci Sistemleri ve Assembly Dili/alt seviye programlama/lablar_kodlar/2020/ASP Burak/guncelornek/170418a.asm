; yordama poarametre aktarimi 
; AX ve BX uzerinden yollanan iki iþaretsiz sayýdan olusan parametre
; arasýndaki farký bularak yine yazmaç üzerinden döndüren program 
; donuste ax<- parm1 - parm2 
; 		  bx<- parm2 - parm1 olsun 

myss	segment para stack 'yigin'
		dw 12 dup(?)
myss	ends
myds 	segment para 'data'
parm1 	dw 5
parm2   dw 10 
p1_2	dw ?  			; parm1 - parm2
p2_1 	dw ?			; parm2 - parm1
myds	ends
mycs	segment para 'cd'
		assume cs: mycs, ss:myss, ds:myds
ana 	proc far
		push ds
		xor ax,ax
		push ax
		mov ax, myds
		mov ds,ax
		; parametreleri ilgili yazmaçlarý koyalým 
		mov ax, parm1
		mov bx, parm2
		call yavru 
		; donus degerlerini ilgli degiskenler aktar
		mov p1_2,ax		
		mov p2_1,bx 
		ret 
ana 	endp 
yavru 	proc near
		; ax den paprm1 , bx den parm2 geliyor
		; ax <- parm1-parm2  bx<-parm2 - parm1
		push cx
		mov cx,ax
		sub ax,bx
		sub bx,cx
		pop cx
		ret 
yavru 	endp
mycs	ends
		end ana  