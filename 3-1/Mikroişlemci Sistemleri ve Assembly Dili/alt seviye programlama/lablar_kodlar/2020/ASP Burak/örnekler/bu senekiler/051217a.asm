; bu program cagiracagi harici yordama ortak veri tanimi ile bir DIZI ve 
; yazmac (CX) ile dizinin eleman say�s�n� aktat�r. 
		public dizi   
		; D�Z� isimli degiskene kesim disindan eri�ilebilsin
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
		
	; yodam cagirmak icin on hazirlik CX 'de eleman say�s� olacak 
		mov cx,eleman 
	; yukarida DIZI degiskenine eri�im icin gerekli sat�r yaz�ld�.	
		call yardimci 
	; yukarida EXTRN olarak tar�nlanm�� yordami cagiracgiz.	
		ret 
ana 	endp
mycs	ends
		end ana 