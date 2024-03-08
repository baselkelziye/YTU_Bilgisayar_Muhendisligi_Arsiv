myss	segment para stack 'stack'
		dw 15 dup(?)
		
myss	ends
myds	segment para 'data'


myds	ends
mycs	segment para 'code'
		assume cs:mycs,ss:myss,ds:myds
main		proc far 
mov ax, myds
mov ds, ax


endless:
;select cntr0
;set square wave format
mov al, 00110110
out 6fh, al
xor ax, ax
;set as counting back from 2000
mov al, 0d0h
out 69h,al
mov ah,07h
out 69h,ah

;select cntr1 
;set square wave format 
mov al, 0110110
out 6fh, al


;set as counting back from 100
mov al, 64h
out 6bh,al

jmp endless


mainn	endp
mycs	ends
		end main
		
		
		
		;---------------v2
		myss	segment para stack 'stack'
		dw 15 dup(?)
		
myss	ends
myds	segment para 'data'


myds	ends
mycs	segment para 'code'
		assume cs:mycs,ss:myss,ds:myds
main		proc far 
mov ax, myds
mov ds, ax


endless:
;select cntr0
;set square wave format
mov al, 00110110b
out 6fh, al
xor ax, ax
;set as counting back from 2000
mov al, 0d0h
out 69h,al
mov al,07h
out 69h,al

;select cntr1 
;set square wave format 
mov al, 01010110b
out 6fh, al


;set as counting back from 100
mov al, 64h
out 6bh,al

jmp endless

retf
main	endp
mycs	ends
		end main
		;-----------v2end-
		
		
		;-working one-
		myss	segment para stack 'stack'
		dw 15 dup(?)
		
myss	ends
myds	segment para 'data'


myds	ends
mycs	segment para 'code'
		assume cs:mycs,ss:myss,ds:myds
main		proc far 
mov ax, myds
mov ds, ax



;select cntr0
;set square wave format
mov al, 00110110b
out 6fh, al
xor ax, ax
;set as counting back from 2000
mov al, 0d0h
out 69h,al
mov al,07h
out 69h,al

;select cntr1 
;set square wave format 
mov al, 01010110b
out 6fh, al


;set as counting back from 100
mov al, 64h
out 6bh,al

endless:

jmp endless

retf
main	endp
mycs	ends
		end main
		;-working one end