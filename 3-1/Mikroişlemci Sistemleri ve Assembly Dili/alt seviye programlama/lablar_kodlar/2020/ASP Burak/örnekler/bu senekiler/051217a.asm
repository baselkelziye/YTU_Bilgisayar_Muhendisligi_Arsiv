; bu program cagiracagi harici yordama ortak veri tanimi ile bir DIZI ve 
; yazmac (CX) ile dizinin eleman sayýsýný aktatýr. 
		public dizi   
		; DÝZÝ isimli degiskene kesim disindan eriþilebilsin
		extrn yardimci:far  
		; YARDIMCI isimli bir harici yordama erismek istiyorum
myss	segment para stack 'stack'
		dw 12 dup(?)
myss	ends
myds	segment para 'data'
dizi 	dw 1,2,3,4,5,6,7,8,9,10
eleman	dw 10
myds	ends
mycs	segment para 'code'
		assume cs:mycs, ss:myss, ds:myds
ana 	proc far
		push ds
		xor ax,ax
		push ax
		mov ax,myds
		mov ds,ax
		
	; yodam cagirmak icin on hazirlik CX 'de eleman sayýsý olacak 
		mov cx,eleman 
	; yukarida DIZI degiskenine eriþim icin gerekli satýr yazýldý.	
		call yardimci 
	; yukarida EXTRN olarak tarýnlanmýþ yordami cagiracgiz.	
		ret 
ana 	endp
mycs	ends
		end ana 