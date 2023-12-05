; calculate equation with high precision without math coprocessor
          
; this program calculates linear equation: ax + b = 0
; the result is printed with floating point.

; for example: a = 7, b = 2
;              x = -0.28571428....

name "float"  

precision = 30  ; max digits after the dot.

   
dseg    segment 'data'
cr              equ     0Dh
lf              equ     0Ah
new_line        equ     0Dh,0Ah, '$'
mess0           db      'calculation of ax + b = 0', new_line
mess1           db      'enter a (-32768..32767)!', new_line
mess2           db      lf, cr, 'enter b (-32768..32767)!', new_line
mess3           db      cr, lf, cr, lf, 'data:', '$'
mess4           db      cr, lf, ' a = ', '$'
mess5           db      cr, lf, ' b = ', '$'
mess6           db      cr, lf, 'result: ', cr, lf, ' x = ', '$'
mess7           db      cr, lf, cr, lf, 'no solution!', new_line
mess8           db      cr, lf, cr, lf, 'infinite number of solutions!', new_line
error           db      cr, lf, 'the number is out of range!', new_line
twice_nl        db      new_line, new_line 
make_minus      db      ?       ; used as a flag in procedures.
a               dw      ?
b               dw      ?
ten             dw      10      ; used as multiplier.
four            dw      4       ; used as divider.
dseg    ends

sseg    segment stack   'stack'
                dw      100h    dup(?)
sseg    ends

cseg    segment 'code'

;*******************************************************************

start           proc    far

; store return address to os:
                push    ds
                xor     ax, ax
                push    ax
                
; set segment registers:                
                mov     ax, dseg
                mov     ds, ax
                mov     es, ax

; welcome message:
                lea     dx, mess0
                call    puts            ; display the message.

; ask for 'a' :
                lea     dx, mess1
                call    puts            ; display the message.
                call    scan_num        ; input the number into cx.
                mov     a, cx

; ask for 'b' :
                lea     dx, mess2
                call    puts            ; display the message.
                call    scan_num        ; input the number into cx.
                mov     b, cx

; print the data:
                lea     dx, mess3
                call    puts

                lea     dx, mess4
                call    puts
                mov     ax, a
                call    print_num               ; print ax.

                lea     dx, mess5
                call    puts
                mov     ax, b
                call    print_num               ; print ax.


; check data:
                cmp     a, 0
                jne     soluble         ; jumps when a<>0.
                cmp     b, 0
                jne     no_solution     ; jumps when a=0 and b<>0.
                jmp     infinite        ; jumps when a=0 and b=0.
soluble:

; calculate the solution:
; ax + b = 0  ->  ax = -b  ->  x = -b/a

                neg     b

                mov     ax, b

                xor     dx, dx

                ; check the sign, make dx:ax negative if ax is negative:
                cmp     ax, 0
                jns     not_singned
                not     dx
not_singned:
                mov     bx, a   ; divider is in bx.

                ; '-b' is in dx:ax.
                ; 'a' is in bx.

                idiv    bx      ; ax = dx:ax / bx       (dx - remainder).

                ; 'x' is in ax.
                ; remainder is in dx.

                push    dx      ; store the remainder.

                lea     dx, mess6
                call    puts

                pop     dx

                ; print 'x' as float:
                ; ax - whole part
                ; dx - remainder
                ; bx - divider
                call    print_float

                jmp     end_prog
no_solution:
                lea     dx, mess7
                call    puts
                jmp     end_prog
infinite:
                lea     dx, mess8
                call    puts
end_prog:
                lea     dx, twice_nl
                call    puts
                
                ; wait for any key....
                mov     ah, 0
                int     16h
                
                
                ret
 start          endp

;***************************************************************

; prints number in ax and it's fraction in dx.
; used to print remainder of 'div/idiv bx'.
; ax - whole part.
; dx - remainder.
; bx - the divider that was used to get the remainder from divident.
print_float     proc    near
        push    cx
        push    dx

        ; because the remainder takes the sign of divident
        ; its sign should be inverted when divider is negative
        ; (-) / (-) = (+)
        ; (+) / (-) = (-)
        cmp     bx, 0
        jns     div_not_signed
        neg     dx              ; make remainder positive.
div_not_signed:

        ; print_num procedure does not print the '-'
        ; when the whole part is '0' (even if the remainder is
        ; negative) this code fixes it:
        cmp     ax, 0
        jne     checked         ; ax<>0
        cmp     dx, 0
        jns     checked         ; ax=0 and dx>=0
        push    dx
        mov     dl, '-'
        call    write_char      ; print '-'
        pop     dx
checked:

        ; print whole part:
        call    print_num

        ; if remainder=0, then no need to print it:
        cmp     dx, 0
        je      done

        push    dx
        ; print dot after the number:
        mov     dl, '.'
        call    write_char
        pop     dx

        ; print digits after the dot:
        mov     cx, precision
        call    print_fraction
done:
        pop     dx
        pop     cx
        ret
print_float     endp

;***************************************************************

; prints dx as fraction of division by bx.
; dx - remainder.
; bx - divider.
; cx - maximum number of digits after the dot.
print_fraction  proc    near
        push    ax
        push    dx
next_fraction:
        ; check if all digits are already printed:
        cmp     cx, 0
        jz      end_rem
        dec     cx      ; decrease digit counter.

        ; when remainder is '0' no need to continue:
        cmp     dx, 0
        je      end_rem

        mov     ax, dx
        xor     dx, dx
        cmp     ax, 0
        jns     not_sig1
        not     dx
not_sig1:

        imul    ten             ; dx:ax = ax * 10

        idiv    bx              ; ax = dx:ax / bx   (dx - remainder)

        push    dx              ; store remainder.
        mov     dx, ax
        cmp     dx, 0
        jns     not_sig2
        neg     dx
not_sig2:
        add     dl, 30h         ; convert to ascii code.
        call    write_char      ; print dl.
        pop     dx

        jmp     next_fraction
end_rem:
        pop     dx
        pop     ax
        ret
print_fraction  endp

;***************************************************************

; this procedure prints number in ax,
; used with print_numx to print "0" and sign.
; this procedure also stores the original ax,
; that is modified by print_numx.
print_num       proc    near
        push    dx
        push    ax

        cmp     ax, 0
        jnz     not_zero

        mov     dl, '0'
        call    write_char
        jmp     printed

not_zero:
        ; the check sign of ax,
        ; make absolute if it's negative:
        cmp     ax, 0
        jns     positive
        neg     ax

        mov     dl, '-'
        call    write_char
positive:
        call    print_numx
printed:
        pop     ax
        pop     dx
        ret
print_num       endp

;***************************************************************

; prints out a number in ax (not just a single digit)
; allowed values from 1 to 65535 (ffff)
; (result of /10000 should be the left digit or "0").
; modifies ax (after the procedure ax=0)
print_numx      proc    near
        push    bx
        push    cx
        push    dx

        ; flag to prevent printing zeros before number:
        mov     cx, 1

        mov     bx, 10000       ; 2710h - divider.

        ; check if ax is zero, if zero go to end_show
        cmp     ax, 0
        jz      end_show

begin_print:

        ; check divider (if zero go to end_show):
        cmp     bx,0
        jz      end_show

        ; avoid printing zeros before number:
        cmp     cx, 0
        je      calc
        ; if ax<bx then result of div will be zero:
        cmp     ax, bx
        jb      skip
calc:
        xor     cx, cx  ; set flag.

        xor     dx, dx
        div     bx      ; ax = dx:ax / bx   (dx=remainder).

        ; print last digit
        ; ah is always zero, so it's ignored
        push    dx
        mov     dl, al
        add     dl, 30h    ; convert to ascii code.
        call    write_char
        pop     dx

        mov     ax, dx  ; get remainder from last div.

skip:
        ; calculate bx=bx/10
        push    ax
        xor     dx, dx
        mov     ax, bx
        div     ten     ; ax = dx:ax / 10   (dx=remainder).
        mov     bx, ax
        pop     ax

        jmp     begin_print

end_show:

        pop     dx
        pop     cx
        pop     bx
        ret
print_numx      endp

;***************************************************************

; displays the message (dx-address)
puts    proc    near
        push    ax
        mov     ah, 09h
        int     21h
        pop     ax
        ret
puts    endp

;*******************************************************************

; reads char from the keyboard into al
; (modifies ax!!!)
read_char       proc    near
        mov     ah, 01h
        int     21h
        ret
read_char       endp

;***************************************************************

; gets the multi-digit signed number from the keyboard,
; result is stored in cx. backspace is not supported, for backspace
; enabled input function see c:\emu8086\inc\emu8086.inc
scan_num        proc    near
        push    dx
        push    ax

        xor     cx, cx

        ; reset flag:
        mov     make_minus, 0

next_digit:

        call    read_char

        ; check for minus:
        cmp     al, '-'
        je      set_minus

        ; check for enter key:
        cmp     al, cr
        je      stop_input

        ; multiply cx by 10 (first time the result is zero)
        push    ax
        mov     ax, cx
        mul     ten                     ; dx:ax = ax*10
        mov     cx, ax
        pop     ax

        ; check if the number is too big
        ; (result should be 16 bits)
        cmp     dx, 0
        jne     out_of_range

        ; convert from ascii code:
        sub     al, 30h

        ; add al to cx:
        xor     ah, ah
        add     cx, ax
        jc      out_of_range    ; jump if the number is too big.

        jmp     next_digit

set_minus:
        mov     make_minus, 1
        jmp     next_digit

out_of_range:
        lea     dx, error
        call    puts

stop_input:
        ; check flag:
        cmp     make_minus, 0
        je      not_minus
        neg     cx
not_minus:

        pop     ax
        pop     dx
        ret
scan_num        endp

;***************************************************************

; prints out single char (ascii code should be in dl)
write_char      proc    near
        push    ax
        mov     ah, 02h
        int     21h
        pop     ax
        ret
write_char      endp

;***************************************************************

cseg    ends
        end     start
