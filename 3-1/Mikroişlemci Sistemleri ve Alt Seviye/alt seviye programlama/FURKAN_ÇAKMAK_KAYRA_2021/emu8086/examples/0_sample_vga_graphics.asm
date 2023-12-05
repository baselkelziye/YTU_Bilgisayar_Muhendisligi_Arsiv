name "vga"

; this program draws a tiny rectangle in vga mode.

org  100h

jmp code

; dimensions of the rectangle:
; width: 10 pixels
; height: 5 pixels

w equ 10
h equ 5


; set video mode 13h - 320x200

code:   mov ah, 0
        mov al, 13h 
        int 10h


; draw upper line:

    mov cx, 100+w  ; column
    mov dx, 20     ; row
    mov al, 15     ; white
u1: mov ah, 0ch    ; put pixel
    int 10h
    
    dec cx
    cmp cx, 100
    jae u1
 
; draw bottom line:

    mov cx, 100+w  ; column
    mov dx, 20+h   ; row
    mov al, 15     ; white
u2: mov ah, 0ch    ; put pixel
    int 10h
    
    dec cx
    cmp cx, 100
    ja u2
 
; draw left line:

    mov cx, 100    ; column
    mov dx, 20+h   ; row
    mov al, 15     ; white
u3: mov ah, 0ch    ; put pixel
    int 10h
    
    dec dx
    cmp dx, 20
    ja u3 
    
    
; draw right line:

    mov cx, 100+w  ; column
    mov dx, 20+h   ; row
    mov al, 15     ; white
u4: mov ah, 0ch    ; put pixel
    int 10h
    
    dec dx
    cmp dx, 20
    ja u4     
 

; pause the screen for dos compatibility:

;wait for keypress
  mov ah,00
  int 16h			

; return to text mode:
  mov ah,00
  mov al,03 ;text mode 3
  int 10h



ret

