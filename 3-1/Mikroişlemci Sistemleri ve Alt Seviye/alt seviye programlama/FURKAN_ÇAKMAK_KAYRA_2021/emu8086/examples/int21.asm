; this sample gets a string from a user, then it prints it out.
; this example uses dos interrupt: 21h

name "int21"

org  100h

jmp start


; when no file path is specified the default file path is:
;   c:\emu8086\MyBuild

; if path is specified, it is emulated in:
;   c:\emu8086\vdrive\
; for example, c:\test.txt is c:\emu8086\vdrive\c\test.txt
; this is done to prevent disasters and accidental overwriting of valuable files.
; relative paths such as "c:\mydir\..\autoexec.bat" are disabled for the same reasons.


; declarations:

; buffers hold ascii chars for INT 21h/0Ah input function,
; first byte is its maximum size, second byte: actual size.

; format of INT 21h/0Ah input buffer:
;  -byte-offset-     -number-of-bytes-             -description- 
;      00                  1                        buffer size
;      01                  1                        number of characters actually read (excluding cr).
;      02             1 to buffer-size              actual buffer contents (including cr). 

s1        db 100,?, 100 dup(' ') 
t2        db 100,?, 100 dup(' ')
filename  db 30,?, 30 dup(' ')   ; file name should be in 8.3 - dos compatible format.


; file handle:
handle   dw   0


; set segment registers to code:
start:  mov ax, cs
        mov ds, ax
        mov es, ax

jmp m1
msg1    db  "enter any text: $"
m1:     mov dx, offset msg1
        mov ah, 9
        int 21h
; input a string:
        mov dx, offset s1
        mov ah, 0ah
        int 21h



jmp m2
msg2    db  0Dh,0Ah,"enter file name: $"
m2:     mov dx, offset msg2
        mov ah, 9
        int 21h
; input filename:
        mov dx, offset filename
        mov ah, 0ah
        int 21h

; set 0 to the end of the filename:
        xor bx, bx
        mov bl, filename[1]  ; get actual size.
        mov filename[bx+2], 0

; create new file:
        mov cx, 0
        mov ah, 3ch
        mov dx, offset filename+2
        int 21h
        jc  error
        mov handle, ax
; write buffer to file:
        mov ah, 40h
        mov bx, handle        
        mov dx, offset s1+2
        xor cx, cx
        mov cl, s1[1]
        int 21h
        jc  error
; close file
        mov bx, handle
        mov ah, 3eh
        int 21h
        jc error
        
        
        
; open existing file:
        mov al, 0     ; read.
        mov ah, 3dh
        mov dx, offset filename+2
        int 21h
        jc  error
        mov handle, ax       
; read bytes from file
        mov ah, 3fh
        mov bx, handle
        xor cx, cx
        mov cl, t2[0]
        mov dx, offset t2[2]
        int 21h
        jc error
        mov t2[1], al
; close file
        mov bx, handle
        mov ah, 3eh
        int 21h
        jc error    
jmp m3
msg3    db  0Dh,0Ah,"read from file: $"
m3:     mov dx, offset msg3
        mov ah, 9
        int 21h
; set '$' to the end of the buffer:
        xor bx, bx
        mov bl, t2[1]        ; get actual size.
        mov t2[bx+2], '$'
; print the buffer:
        mov dx, offset t2[2] ; skip 2 control bytes.
        mov ah, 9
        int 21h
        
        
        jmp ok

; print error message:
error:  jmp m5
        msg5    db  0Dh,0Ah,"error...",0Dh,0Ah,'$'
        m5:     mov dx, offset msg5
                mov ah, 9
                int 21h


ok:     
jmp m4
msg4    db  0Dh,0Ah,"press any key...",0Dh,0Ah,'$'
m4:     mov dx, offset msg4
        mov ah, 9
        int 21h        
        mov ah, 0
        int 16h


; exit to the operating system:
        mov ah, 4ch
        int 21h



