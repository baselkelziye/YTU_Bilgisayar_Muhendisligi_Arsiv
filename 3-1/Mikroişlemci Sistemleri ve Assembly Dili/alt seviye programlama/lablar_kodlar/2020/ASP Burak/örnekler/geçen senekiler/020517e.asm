		; yıgın uzerinden paremetre akyarimi 
		extrn	toplama:far
myss	segment para stack 'stack'
		dw 20 dup(?)
myss	ends
myds	segment para 'data'
sayiw1	dw 1234h
sayiw2 	dw 0fedch
toplam 	dd ?
myds	ends
mycs	segment para 'code'
		assume cs:mycs,ss:myss, ds:myds
main 	proc far 
		push ds
		xor ax,ax
		push ax
		mov ax,myds
		mov ds,ax
		lea si,toplam 
		push sayiw1
		push sayiw2
		call toplama ; toplama yigindan 2 word alir. toplar sonucu yine 
					 ; yigindan 2 word olarak, low work ustte olacak sekilde
					 ; dondurur. 
		pop [si]	; yiginin en ustunde low word -> low adrese
		pop [si+2]	; sonraki high word -> high adrese 
		ret 
main 	endp
mycs	ends
		end main 
		
			