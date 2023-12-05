; PrinterDemo.asm - Andrew Nelis
;
; simple demonstration of the printer emulation.

; Note: this is not a realistic emulation.
;       in real IBM PC there is no printer on PORT 130d
;
; "Printer.exe" is started automatically from "c:\emu8086\devices".
#start=printer.exe#

name "printemu"

#make_bin#

lea bx, message
mov cx, offset message_end - offset message     ; length of the message

xor ax, ax

put_char:
    mov al, [bx]    ; put char into al
    out 130d, al    ; push char out port
                    ; (ie. into printer)
    
    inc bx          ; inc pointer
    
    wait:           ; loop to ensure the printer
    in al, 130d     ; is ready, it clears
    or al, 0        ; the port when this is true.
    jnz wait

loop put_char       ; go back and repeat if we're
                    ; not finished

    ; bell... 
    ; not all laser printers support it, only the old telegraphs do:
    mov al, 7
    out 130d, al


hlt

message db "Hello World!", 0Ah, 0Dh, "------------"
message_end db 0
