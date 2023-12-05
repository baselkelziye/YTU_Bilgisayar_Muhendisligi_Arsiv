name "fileio"

; general rules for file system emulation:

; 1. the emulator emulates all drive paths in c:\emu8086\vdrive\
;    for example: the real path for "c:\test1" is "c:\emu8086\vdrive\c\test1"

; 2. paths without drive letter are emulated to c:\emu8086\MyBuild\
;    for example: the real path for "myfile.txt" is "c:\emu8086\MyBuild\myfile.txt"

; 3. if compiled file is running outside of the emulator rules 1 and 2 do not apply.

; ==================================================================================
; run this example slowly in step-by-step mode and observe what it does.
; ==================================================================================

org  100h

jmp start

dir1 db "c:\test1", 0
dir2 db "test2", 0
dir3 db "newname", 0
file1 db "c:\test1\file1.txt", 0
file2 db "c:\test1\newfile.txt", 0
file3 db "t1.txt", 0
handle dw ?

text db "lazy dog jumps over red fox."
text_size = $ - offset text
text2 db "hi!"
text2_size = $ - offset text2

start:
mov ax, cs
mov dx, ax
mov es, ax


; create c:\emu8086\vdrive\C\test1
mov dx, offset dir1
mov ah, 39h
int 21h

; create  c:\emu8086\MyBuild\test2
mov dx, offset dir2
mov ah, 39h
int 21h

; rename directory: c:\emu8086\MyBuild\test2 to c:\emu8086\MyBuild\newname
mov ah, 56h
mov dx, offset dir2   ; existing.
mov di, offset dir3   ; new.
int 21h



; create and open file: c:\emu8086\vdrive\C\test1\file1.txt
mov ah, 3ch
mov cx, 0
mov dx, offset file1
int 21h
jc err
mov handle, ax
; write to file:
mov ah, 40h
mov bx, handle
mov dx, offset text
mov cx, text_size
int 21h
; close c:\emu8086\vdrive\C\test1\file1.txt
mov ah, 3eh
mov bx, handle
int 21h
err:
nop


; rename fileL c:\emu8086\vdrive\C\test1\file1.txt to c:\test1\newfile.txt
mov ah, 56h
mov dx, offset file1   ; existing.
mov di, offset file2   ; new.
int 21h


; delete file c:\emu8086\vdrive\C\test1\newfile.txt
mov ah, 41h
mov dx, offset file2
int 21h


; delete directory: c:\emu8086\vdrive\C\test1
mov ah, 3ah
mov dx, offset dir1
int 21h






; create and open file: c:\emu8086\MyBuild\t1.txt
mov ah, 3ch
mov cx, 0
mov dx, offset file3
int 21h
jc err2
mov handle, ax
; seek:
mov ah, 42h
mov bx, handle
mov al, 0
mov cx, 0
mov dx, 10
int 21h
; write to file:
mov ah, 40h
mov bx, handle
mov dx, offset text
mov cx, text_size
int 21h
; seek:
mov ah, 42h
mov bx, handle
mov al, 0
mov cx, 0
mov dx, 2
int 21h
; write to file:
mov ah, 40h
mov bx, handle
mov dx, offset text2
mov cx, text2_size
int 21h
; close c:\emu8086\MyBuild\t1.txt
mov ah, 3eh
mov bx, handle
int 21h
err2:
nop



; delete file  c:\emu8086\MyBuild\t1.txt
mov ah, 41h
mov dx, offset file3
int 21h




; delete directory: c:\emu8086\MyBuild\newname
mov ah, 3ah
mov dx, offset dir3
int 21h


ret
