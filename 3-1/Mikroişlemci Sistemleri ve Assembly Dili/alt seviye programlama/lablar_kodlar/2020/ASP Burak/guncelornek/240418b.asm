; yordama parametre aktarimi 
; AX ve BX uzerinden yollanan iki iþaretsiz sayýdan olusan parametre
; arasýndaki farký bularak yine yazmaç üzerinden döndüren program 
; donuste ax<- parm1 - parm2 
; 		  bx<- parm2 - parm1 olsun 
;
; bu programlarin kod kesimlerini de birleþtirelim..
;

public yavru
mycs	segment page public 'cd'
		assume cs: mycs
yavru 	proc far
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
		end