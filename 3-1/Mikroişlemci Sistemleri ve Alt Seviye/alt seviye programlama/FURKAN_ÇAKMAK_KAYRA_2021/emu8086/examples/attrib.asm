
name "attrib"

; set and get file attributes...

; note 1: you need to manually create and copy "test.txt" to:
; c:\emu8086\vdrive\c before running this example.

; note 2: it may look like the file suddenly disappears unless
; you set the settings of file manager to show system and hidden files. 

; note 3: file must exist for setting parameters. however reading
; parameters does not require the existance of a file and
; it is usually used to check if file exists or not.

org  100h


jmp start

  filename   db      "c:\test.txt", 0
  sOK        db      "ok! file found. attributes set: system, hidden & read-only. $"
  sERR       db      "file does not exist. (expected i/o error)", 0dh, 0ah
             db      ' you need to manually create and copy "test.txt" to:', 0dh, 0ah
             db      ' "c:\emu8086\vdrive\c"  before running this example.$ '
  
; when running in emulator, the real path of this file is:
;           c:\emu8086\vdrive\c\test.txt



start:
xor cx, cx

; read attributes:
mov     ah, 43h
mov     al, 0
mov     dx, offset filename
int     21h
jc      error
; set new attributes:
mov     ah, 43h
mov     al, 1
mov     cx, 7
mov     dx, offset filename
int     21h
jc      error

mov dx, offset sOK
mov ah, 9
int 21h

jmp wait_any_key






error:
    mov dx, offset sERR
    mov ah, 9
    int 21h





wait_any_key:
    mov ah, 0
    int 16h

ret


