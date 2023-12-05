; this example demonstrates the use of pages (double-buffering).
; this program uses first 4 pages of video memory by writing
; some random data to them, and waits for any key press,
; pressing any key will show all pages one after another.

name "pages"

org 100h

; set video mode:
; text mode 80x25, 16 colors, 8 pages
mov     ah, 0
mov     al, 3
int     10h

; ======== print chars on different pages:

mov al, '0' ; char to print.
mov bh, 0 ; page number.
mov bl, 0000_1110b  ; attributes.

do_print:

mov cx, 200         ; number of chars to write.
mov ah, 09h         ; write char function.
int 10h

inc al  ; next char.
inc bh  ; next page.

rol bl, 1  ; select another attribute.

cmp al, '4'
jb  do_print


; ===== modify pages by writing directly
;       to video memory:

push    ds

mov ax, 0b800h
mov ds, ax

; first byte is a color attribute
; (0f2h = white background, green char),
; second byte is an ascii code
; (41h = 'a', 42h = 'b', 43h = 'c'...)

mov di, 0           ; page 0.
mov w.[di], 0f241h

add di, 4096        ; page 1.
mov w.[di], 0f242h

add di, 4096        ; page 2.
mov w.[di], 0f243h

add di, 4096        ; page 3.
mov w.[di], 0f244h

pop ds

; ======= show pages one after another:

mov  al, 0   ; page number

show_next_page:

mov  ah, 05h ; change page function.
int  10h

push ax
; wait for any key:
xor  ax, ax
int  16h
pop  ax

inc  al

cmp  al, 4
jb   show_next_page




ret ; return control to operating system.

