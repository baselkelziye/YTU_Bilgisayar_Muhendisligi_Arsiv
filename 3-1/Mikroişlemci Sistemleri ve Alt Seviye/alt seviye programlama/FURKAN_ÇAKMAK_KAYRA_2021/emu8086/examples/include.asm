
; this sample shows the use of emu8086.inc
; this is library of predefined macros and procedures for easy input/output.

name "inc"

include "emu8086.inc"

; it is also possible to just copy and paste ready procedures from emu8086.inc
; and use them in your program, this way it is possible to step through original
; source code.


; note, that some declarations of "emu8086.inc"
; are macro procedure declarations, and you
; have to use "define_..." macro somewhere
; in your program if you want to use
; these functions:

;   call scan_num
;   call print_string
;   call pthis
;   call get_string
;   call clear_screen
;   call print_num
;   call print_num_uns

; you can define all these procedures in your
; source code, but compilation time may slow down
; sufficiently because of that, only declare
; functions that you plan to use:


;   define_scan_num
;   define_print_string
;   define_pthis
;   define_get_string
;   define_clear_screen
;   define_print_num
;   define_print_num_uns

;  the above declarations should be made in
;  your code once only! better somewhere
;  in the end of your file, but before "end"
;  directive. you can also declare them
;  in the beginning of the file, but it should
;  be after "org 100h" directive (for com files).








org     100h


jmp start  ; skip over the declarations

;=================================
; here we define the functions
; from emu8086.inc

; scan_num reads a
; number from the user and stores
; it in cx register:
define_scan_num

; print_string prints a null
; terminated string, the address
; of the string is in ds:si 
define_print_string

; print_num prints a signed
; number in ax.
; (print_num requires the declaration
; of print_num_uns).
; print_num_uns prints an unsigned
; number in ax:

define_print_num
define_print_num_uns

;=================================


start:

; print out some chars,
; using macro:
putc    'H'
putc    'e'
putc    'l'
putc    'l'
putc    'o'
putc    ' '
putc    't'
putc    'h'
putc    'e'
putc    'r'
putc    'e'
putc    '!'

; new line:
putc    0Dh
putc    0Ah

; print string using macro
; with carriage return in the end:
printn "Assembly language programming is fun!"

; print string using procedure:
lea     si, msg
call    print_string

; input a number into cx
; using procedure:
call    scan_num

; new line:
putc    0Dh
putc    0Ah

print "Your lucky number is: "
mov     ax, cx
; print out the number in ax
; using procedure:
call    print_num


printn ""
printn ""

printn "press any key..."
mov ah, 0
int 16h





ret

msg     db      "enter any number between -32768 and 32767: ", 0


