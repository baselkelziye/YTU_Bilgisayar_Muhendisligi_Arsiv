mystack	segment para stack 'yigin'
		dw 20 dup(?)		
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
		mov di,cx		; di dizinin son indisini göstermeli
		shl di,1		; bunun icin dizin eleman sayýsý x eleman tipi-2  
		sub di,2		; iþlemi yapilmali 
		add di,si
		shr cx,1		; iþlem sayýsý eleman sayýsýnýn yarýsý olmalý 
l1:		mov ax,[si]		; bastaki elamaný al sondaki ile yer degisitir.
		xchg [di],ax
		mov [si],ax
		add si,2		; dizi word indisler 2ser 2ser deðiþmeli 
		sub di,2
		loop l1 
		ret
ana		endp
	
mycode	ends
		end ana