; 10 word elamaný dizinin elemanlarýnýn ters yuz edilmesi 
; ilk eleman son son eleman basa olacak þekilde
myss	segment para stack 'stack'
		dw 15 dup(?)
myss	ends
myds	segment para 'data'
dizi	dw 1,2,3,4,5,6,7,8,9,0  ; ters yuz edilecek dizi 
eleman 	dw 10 					; dizinin eleman sayýsý 
myds	ends
mycs	segment para 'code'
		assume cs:mycs,ss:myss,ds:myds
tersdon	proc far 
		push ds
		xor ax,ax
		push ax					; geri donus adreslerini koydum 
		mov ax,myds
		mov ds,ax				; veri alanima eriþebilmem icin 
		
		xor si,si				; si dizinin ilk elemanýnýn adresi 
		mov di,eleman
		shl di,1
		sub di,2				; di dizinin son elemanýnýn adresini tutar
		mov cx,eleman 
		shr cx,1				; iþlem dizinin eleman sayýsýný yarisi kadar
l1: 	mov ax, dizi[si]
		xchg ax, dizi[di]
		mov dizi[si],ax			; elemanlarý ax üzerin yer deðiþtirdim
		add si,2				; ilk indis dizi word oldugu icin +2 
		sub di,2				; son indis dizi word oldugu icin -2
		loop l1
		ret 
tersdon	endp
mycs	ends
		end tersdon