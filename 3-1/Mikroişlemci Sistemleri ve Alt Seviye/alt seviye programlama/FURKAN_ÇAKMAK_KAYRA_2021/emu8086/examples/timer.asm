; this sample shows the use of a timer function (int 15h / 86h)
; this code prints some chars with 1 second delay.

; note: Windows XP does not support this interrupt (always sets CF=1),
; to test this program in real environment write it to a floppy disk using 
; compiled writebin.asm. after sucessfull  compilation of both files,
; type this from command prompt:   writebin timer.bin   

; note: floppy disk boot record will be overwritten.
;       the floppy will not be useable under windows/dos until
;       you reformat it, data on floppy disk may be lost.
;       use empty floppy disks only.

name "timer"

#make_boot#
org     7c00h

; set the segment registers
mov     ax, cs
mov     ds, ax
mov     es, ax


call set_video_mode
call clear_screen


next_char:
cmp     count, 0
jz      stop

; print char:
mov     al, c1
mov     ah, 0eh
int     10h

; next ascii char:
inc     c1
dec     count

; set 1 million microseconds interval (1 second)
mov     cx, 0fh
mov     dx, 4240h
mov     ah, 86h
int     15h

; stop any error:
jc      stop    

jmp     next_char

stop:

; print message using bios int 10h/13h function
mov al, 1
mov bh, 0
mov bl, 0010_1111b
mov cx, msg_size
mov dl, 4
mov dh, 15
mov bp, offset msg
mov ah, 13h
int 10h

; wait for any key...
mov ah, 0
int 16h


int 19h            ; reboot


count   db      10
c1      db      'a'


msg db "remove floppy disk and press any key to reboot..."
msg_size = $ - msg



; set video mode and disable blinking (for compatibility).
set_video_mode proc
mov     ah, 0
mov     al, 3 ; text mode 80x25, 16 colors, 8 pages
int     10h
; blinking disabled for compatibility with dos,
; emulator and windows prompt do not blink anyway.
mov     ax, 1003h
mov     bx, 0    ; disable blinking.
int     10h
ret
set_video_mode endp




; clear the screen by scrolling entire screen window,
; and set cursor position on top.
; default attribute is changed to black on white.
clear_screen proc near
        push    ax      ; store registers...
        push    ds      ;
        push    bx      ;
        push    cx      ;
        push    di      ;

        mov     ax, 40h
        mov     ds, ax  ; for getting screen parameters.
        mov     ah, 06h ; scroll up function id.
        mov     al, 0   ; scroll all lines!
        mov     bh, 1111_0000b  ; attribute for new lines.
        mov     ch, 0   ; upper row.
        mov     cl, 0   ; upper col.
        mov     di, 84h ; rows on screen -1,
        mov     dh, [di] ; lower row (byte).
        mov     di, 4ah ; columns on screen,
        mov     dl, [di]
        dec     dl      ; lower col.
        int     10h

        ; set cursor position to top
        ; of the screen:
        mov     bh, 0   ; current page.
        mov     dl, 0   ; col.
        mov     dh, 0   ; row.
        mov     ah, 02
        int     10h

        pop     di      ; re-store registers...
        pop     cx      ;
        pop     bx      ;
        pop     ds      ;
        pop     ax      ;

        ret
clear_screen endp