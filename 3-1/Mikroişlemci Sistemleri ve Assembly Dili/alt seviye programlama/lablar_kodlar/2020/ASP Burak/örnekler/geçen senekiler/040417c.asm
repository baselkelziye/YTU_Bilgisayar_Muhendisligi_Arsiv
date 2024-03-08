mystack	segment para stack 'yigin'
		dw 20 dup(?)		;yiginin bizim iþimiz için yeterli
							; ancak elaman sayýsý 30-40-50 olsa ne olacakti?
mystack	ends
mydata	segment para 'veri'
dizi1	dw 3,5,7,9,2
eleman	dw 5
mydata 	ends
mycode	segment para 'kod'
		assume cs:mycode, ss:mystack, ds:mydata
ana		proc far
		; dönüþa adreslerinin yýðýna saklanmasý 
		push ds
		xor ax,ax
		push ax
		; kendi veri alanýna eriþmek için yapýlmasý gerekenler 
		mov ax,mydata
		mov ds,ax
		; iþlemin esas kýsmý bundan sonra baþlar
		
		mov cx,eleman 	; iþlemin tekrar sayýsý 
		lea si,dizi1
l1:		push [si]		; elemanlarý yýgýna koy 
		add si,2		; word tipindeki dizi sonraki eleman 2 ileride 
		loop l1
		mov cx,eleman 
		lea si,dizi1
l2:		pop [si]		; elemanlarý ters sirali olarak yýgýndan al 
		add si,2		; word dizi olduggu icin artim cift 
		loop l2
		
		ret
ana		endp
	
mycode	ends
		end ana