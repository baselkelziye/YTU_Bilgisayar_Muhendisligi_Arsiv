; yordama parametre aktarimi 
; AX ve BX uzerinden yollanan iki i�aretsiz say�dan olusan parametre
; aras�ndaki fark� bularak yine yazma� �zerinden d�nd�ren program 
; donuste ax<- parm1 - parm2 
; 		  bx<- parm2 - parm1 olsun 
;
; bu programlarin kod kesimlerini de birle�tirelim..
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