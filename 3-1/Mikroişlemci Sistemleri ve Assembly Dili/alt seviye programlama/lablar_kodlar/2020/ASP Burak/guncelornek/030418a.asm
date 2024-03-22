; 10 word elaman� dizinin elemanlar�n�n ters yuz edilmesi 
; ilk eleman son son eleman basa olacak �ekilde
myss	segment para stack 'stack'
		dw 15 dup(?)
myss	ends
myds	segment para 'data'
dizi	dw 1,2,3,4,5,6,7,8,9,0  ; ters yuz edilecek dizi 
eleman 	dw 10 					; dizinin eleman say�s� 
myds	ends
mycs	segment para 'code'
		assume cs:mycs,ss:myss,ds:myds
tersdon	proc far 
		push ds
		xor ax,ax
		push ax					; geri donus adreslerini koydum 
		mov ax,myds
		mov ds,ax				; veri alanima eri�ebilmem icin 
		
		xor si,si				; si dizinin ilk eleman�n�n adresi 
		mov di,eleman
		shl di,1
		sub di,2				; di dizinin son eleman�n�n adresini tutar
		mov cx,eleman 
		shr cx,1				; i�lem dizinin eleman say�s�n� yarisi kadar
l1: 	mov ax, dizi[si]
		xchg ax, dizi[di]
		mov dizi[si],ax			; elemanlar� ax �zerin yer de�i�tirdim
		add si,2				; ilk indis dizi word oldugu icin +2 
		sub di,2				; son indis dizi word oldugu icin -2
		loop l1
		ret 
tersdon	endp
mycs	ends
		end tersdon