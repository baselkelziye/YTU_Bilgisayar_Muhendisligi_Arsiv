
; interrupt vector (memory from 00000h to 00400h)
; keeps addresses of all interrupts (from 00h to 0ffh).
; you can add new interrupt or modify existing interrupts.
; address of interrupt M is stored in vector at offset M * 4,
; for example: interrupt 10h is stored at offset 10h * 4.
; first goes the offset, then segment (total of 2 bytes).

; for more information refer to "global memory table" in c:\emu8086\documentation.
 
; note: this is simplified example, it is not recommended to make changes to it
; and run it on the real computer, especially it is not recommended to replace disk
; processing interrupts because this may cause data loss and other instability problems.

 
name "custint"

 
org 100h

start:
 
; set video mode to 3 - 16 color 80x25
mov ah, 0
mov al, 3
int 10h
 
 
; set es to "0000":
mov ax, 0       
mov es, ax
; calculate vector address for interrupt 90h:
mov al, 90h    
; multiply 90h by 4, store result in ax:
mov bl, 4h       
mul bl          
mov bx, ax
; copy offset into interrupt vector:
mov si, offset [test1]
mov es:[bx], si
add bx, 2   
; copy segment into interrupt vector:    
mov ax, cs     
mov es:[bx], ax
         

int 90h    ; test newly created interrupt.
 
; wait for any key press:
mov ah, 0
int 16h
 
 
int 20h     ; halt execution.





; interrupt 90h starts here:
test1: pusha  ; store all registers.

; make sure data segment is code segment:
       push cs
       pop ds

; set segment register to video memory:
       mov     ax, 0b800h
       mov     es, ax

; print message, each character is written as
; a word, high byte is color and low byte is
; ascii code:
      lea si, msg      ; load offset of msg to si.
      mov di, 0        ; point to start of the screen.
print:
      cmp [si], 0      ; if "0" then stop.
      je stop
      mov bl,  [si]    ; read ascii code from msg.
      mov bh, 0f1h     ; set colors: white background, blue text.
      mov es:[di], bx  ; write to video memory.
      add di, 2        ; go to next position on screen.
      inc si           ; next char.
      jmp print
stop:
      popa  ; re-store all registers.
      iret  ; return from interrupt.
 
msg db "test of custom interrupt!", 0


