; simplest virtual device for emu8086 in pure assembly code....

; this example reads and sends ascii codes to virtual port 3.


; for real test, it is required to compile this code and run it outside
; of the emulator (external->run). if you copy the compiled file to c:\emu8086\devices\
; folder it will start automatically. when simplest.com is running it's possible
; to see the interraction with the emulator using this code:

;        #start=simplest.com#
;        mov al, 'a'
;        send_byte:
;        out 3, al
;        inc al
;        jmp send_byte
;        end

;; note: you can uncomment block of code by selecting it and clicking edit->uncomment block.


name "simplest"

org 100h




jmp start


filename db "c:\emu8086.io", 0      ; note: for the emulator this path is c:\emu8086\c\emu8086.io
handle dw ?

print macro x, y, attrib, sdat
LOCAL   s_dcl, skip_dcl, s_dcl_end
    pusha
    mov dx, cs
    mov es, dx
    mov ah, 13h
    mov al, 1
    mov bh, 0
    mov bl, attrib
    mov cx, offset s_dcl_end - offset s_dcl
    mov dl, x
    mov dh, y
    mov bp, offset s_dcl
    int 10h
    popa
    jmp skip_dcl
    s_dcl DB sdat
    s_dcl_end DB 0
    skip_dcl:    
endm


clear_screen macro
    pusha
    mov ax, 0600h
    mov bh, 0000_1111b
    mov cx, 0
    mov dh, 24
    mov dl, 79
    int 10h
    popa
endm



start:
clear_screen
call create_if_missing

simplest:
print 1,1,0010_1111b, " simplest virtual device for emu8086 "
print 1,2,0010_1111b, " press esc to exit - press enter to get byte without sending "
read_byte:
print 1,4,0010_1010b, " get byte from virtual port 0 ---> "
mov bx, 3
call get_byte_from_port
mov ah, 2
int 21h
write_byte:
print 1,5,0010_1010b, " send byte  to virtual port 0 ---> "
mov ah, 1
int 21h
cmp al, 27 ; esc?
je stop
cmp al, 0dh ; enter?
je just_get
mov bx, 3
mov dl, al
call send_byte_to_port
just_get:
call wait_a_bit
clear_screen
jmp simplest

stop:
clear_screen
print 1,1,1110_0000b, " simplest virtual device stoped "
mov ah, 2
mov dl, 0ah
int 21h
mov ah, 2
mov dl, 0dh
int 21h
ret





; entry: bx - port number
; return: dl - value
get_byte_from_port proc
    pusha
    mov i_port, bx
	mov al, 2
	mov dx, offset filename
	mov ah, 3dh
	int 21h   ; open...
	jnc kg
	print 1,7,0000_1100b, "  cannot open c:\emu8086.io      "
	jmp err_i
	kg:
	mov handle, ax
	mov al, 0
	mov bx, handle
	mov cx, 0	
	mov dx, i_port
	mov ah, 42h
	int 21h ; seek...	
	mov bx, handle
	mov dx, offset i_byte
	mov cx, 1
	mov ah, 3fh
	int 21h ; read byte from file...
	mov bx, handle
	mov ah, 3eh
	int 21h ; close file...	
err_i:		
	popa
	mov dl, i_byte ; return.
	ret
	i_port dw ?
	i_byte db ?
endp






; entry: bx - port number
;        dl - value
send_byte_to_port proc
    pusha
    mov o_port, bx
    mov o_byte, dl
	mov al, 2
	mov dx, offset filename
	mov ah, 3dh
	int 21h   ; open...
	jnc ks	
	print 1,7,0000_1100b, "  cannot open c:\emu8086.io      "
	jmp err_s
	ks:
	mov handle, ax
	mov al, 0
	mov bx, handle
	mov cx, 0	
	mov dx, o_port
	mov ah, 42h
	int 21h ; seek...	
	mov bx, handle
	mov dx, offset o_byte
	mov cx, 1
	mov ah, 40h
	int 21h ; write to file...
	mov bx, handle
	mov ah, 3eh
	int 21h ; close file...
err_s:	
	popa
	ret
	o_port dw ?
	o_byte db ?
endp




create_if_missing proc
    pusha
    mov dx, offset filename
    mov ah, 43h
    mov al, 0 
    int 21h  ; get attributes.
    jc create:
    jmp ok_f
create:    
	mov ah, 3ch
	mov cx, 0
	mov dx, offset filename
	mov ah, 3ch
	int 21h  ; create...
	mov bx, ax
	mov ah, 3eh
	int 21h  ; close...
ok_f:
    popa
    ret
endp



wait_a_bit proc
    pusha
    mov ah, 2ch
    int 21h
    mov orig_secs, dh
    wait_more:
    mov ah, 2ch
    int 21h
    cmp orig_secs, dh
    je wait_more
    popa
    ret
    orig_secs db ?
endp


