; this sample shows the use of keyboard functions.
; try typing something into emulator screen. 
;
; keyboard buffer is used, when someone types too fast.
;
; for realistic emulation, run this example at maximum speed
;
; this code will loop until you press esc key,
; all other keys will be printed.

name "keybrd"

org     100h

; print a welcome message:
mov dx, offset msg
mov ah, 9
int 21h

;============================
; eternal loop to get
; and print keys:

wait_for_key:

; check for keystroke in
; keyboard buffer:
        mov     ah, 1
        int     16h
        jz      wait_for_key

; get keystroke from keyboard:
; (remove from the buffer)
mov     ah, 0
int     16h

; print the key:
mov     ah, 0eh
int     10h

; press 'esc' to exit:
cmp     al, 1bh
jz      exit

jmp     wait_for_key
;============================

exit:
ret

msg  db "Type anything...", 0Dh,0Ah
     db "[Enter] - carriage return.", 0Dh,0Ah
     db "[Ctrl]+[Enter] - line feed.", 0Dh,0Ah
     db "You may hear a beep", 0Dh,0Ah
     db "    when buffer is overflown.", 0Dh,0Ah
     db "Press Esc to exit.", 0Dh,0Ah, "$"

end
