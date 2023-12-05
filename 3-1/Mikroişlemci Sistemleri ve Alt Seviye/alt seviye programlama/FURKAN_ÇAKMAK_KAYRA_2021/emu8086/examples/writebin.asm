name "writebin"

; Version 0.02
; Assembled by emu8086 -- must be compatible with major assemblers.
; writebin.com -- a tiny operating system loader.
    
; writebin [filename] [/k]    
    
; This utility is be used from command prompt,
; it reads a specified file and writes it to floppy drive at
; cylinder: 0, head: 0, sector: 1  (boot sector).

; If there is /k parameter after the file name, then the
; file is written at cylinder: 0, head: 0, sector: 2.
; The first sector of a floppy drive is reserved for a boot sector.
; The second and other sectors can be used to store any kind of data
; and code. The kernel module of tiny operating system should be
; written to sector 2.

; This program works with drive A: only.
; For the emulator physical drive A: is this file c:\emu8086\FLOPPY_0
; (for BIOS interrupts: INT 13h and boot).
; Note: for DOS interrupts (INT 21h) drive A: is emulated in this subdirectory:
; c:\emu8086\vdrive\a\

; filename must be in 8.3 format, 
; maximum 8 chars for the name and 3 chars after the dot.

; warning! if you run this program outside of the emulator 
;           it may corrupt existing data. use with caution.
;           do not play with floppies that contain valuable data.



org  100h

jmp st

filename    db 128 dup(0)       ; full path up to 128 chars can be specified.
buffer      db 512 dup (0)
buffer_size =  $ - offset buffer
handle      dw 0
kernel_flag db 0               ; if there is /k parameter, kernel_flag=1.

counter dw 0


sect  db 1 ; sector number (1..18).
cyld  db 0 ; cylinder number (0..79).
head  db 0 ; head number (0..1).
drive db 0 ; drive number (0..3) ; A:=0, B:=1...


; init
st: mov ax, cs
    mov ds, ax
    mov es, ax

call clear_screen


; read cmd parameters
cp: xor cx, cx
    mov cl, [80h]
    jcxz np                    ; this instruction is assembled into OR CX, CX and two JMPs, tutorial 7 tells why.
    mov si, 82h
    mov di, offset filename
    cld
    rep movsb 
    mov [di-1], 0


; check for /k parameter:
    cld
    xor cx, cx
    mov cl, [80h]
    mov di, offset filename
    mov al, '/'
    repne scasb
    jz  fs
    jmp boot
fs: cmp [di-2], ' '
    jne nsp
    mov [di-2], 0
nsp:mov [di-1], 0
    or  [di], 0010_0000b   ; to lower case.
    cmp [di], 'k'
    jne wp
    or kernel_flag, 1
    mov sect, 2            ; start write at sector 2.
    
    
    lea dx, s0
    mov ah, 9
    int 21h
    jmp s0s
    s0 db 0Dh,0Ah,"[/k] - start from sector: 2 " , 0Dh,0Ah, '$'
    s0s:   
    jmp of
    
boot:
    lea dx, s3
    mov ah, 9
    int 21h
    jmp s3s
    s3 db 0Dh,0Ah," boot record ", 1 , 0Dh,0Ah, '$'
    s3s:   


; open file
of: mov ah, 3dh
    mov al, 0
    mov dx, offset filename
    int 21h
    jc  co
    mov handle, ax
    
    
    lea dx, m0
    mov ah, 9
    int 21h
    jmp m0m
    m0 db "opened: $"
    m0m:      
    mov si, offset filename
    call print_string
        

; read bytes from file
rd: mov ah, 3fh
    mov bx, handle
    mov cx, buffer_size
    mov dx, offset buffer
    int 21h
    jc er

    cmp ax, 0  ; no bytes left?
    jz  cf
    

; write bytes to disk
wr: mov ah, 03h
    mov al, 1 ; write 1 sector (512 bytes).
    mov cl, sect  ; sector (1..18)
    mov ch, cyld  ; cylinder (0..79)
    mov dh, head  ; head  (0..1)  
    mov dl, drive ; always 0 (A:)
    mov bx, offset buffer
    int 13h
    jc er
    
    inc counter
    
    ; set cursor at 2,5
    mov ah, 2
    mov dh, 5
    mov bh, 0
    int 10h
    
    ; show current progress:
    lea dx, s1
    mov ah, 9
    int 21h
    jmp s1s
    s1 db 1Dh,0Ah,"writing: $"
    s1s:      
    mov ax, counter
    call print_num_uns

    
    
    
    ; sectors... cylinders... heads...
    cmp kernel_flag, 1
    jne cf
    inc sect
    cmp sect, 18
    jbe rd           ; ^
    mov sect, 1
    inc cyld
    cmp cyld, 79
    jbe rd           ; ^
    mov cyld, 0
    inc head
    cmp head, 1
    jbe rd           ; ^
    
    

; close file
cf: mov bx, handle
    mov ah, 3eh
    int 21h
    jc er

    jmp ex
    

co: lea dx, e0
    mov ah, 9
    int 21h
    jmp e0e
    e0 db "  cannot open the file...",0Dh,0Ah,'$'       
    e0e:
    jmp ex    

np: lea dx, e1
    mov ah, 9
    int 21h
    jmp e1e
    e1 db "  no parameters...",0Dh,0Ah
       db  "==============================================================================",0Dh,0Ah
       db "this program was designed especially to test micro-operating system",0Dh,0Ah
       db "if you are emulating in emu8086, click file->set command line parameters.",0Dh,0Ah
       db "from command prompt type:", 0Dh,0Ah
       db "                           writebin [filename] [/k]",0Dh,0Ah,
       db  "when /k parameter is specified file is written to second sector (kernel area).",0Dh,0Ah,
       db  "==============================================================================",0Dh,0Ah,'$'
e1e: jmp ex
    

er: lea dx, e2
    mov ah, 9
    int 21h
    jmp e2e
    e2 db "   i/o error...",0Dh,0Ah,'$'
    e2e:
    jmp ex

wp: lea dx, e3
    mov ah, 9
    int 21h
    jmp e3e
    e3 db "   wrong parameter. only [/k] is supported. use 8.3 short file names only.",0Dh,0Ah,'$'
    e3e:
   

ex: lea dx, m1
    mov ah, 9
    int 21h
    jmp m1m
    m1 db 0Dh,0Ah,"   total sectors: $"
    m1m:   
    mov ax, counter
    call print_num_uns

    lea dx, m2
    mov ah, 9
    int 21h
    jmp m2m
    m2 db 0Dh,0Ah, "thank your for using writebin!   - emu8086.com - 2005 (c) freeware",0Dh,0Ah
       db " press any key...",0Dh,0Ah, '$'
    m2m:


    ; wait for any key...
    mov ah, 0
    int 16h
    

    ret        ; exit.
    

    
; this macro prints a char in AL and advances
; the current cursor position:
PUTC    MACRO   char
        PUSH    AX
        MOV     AL, char
        MOV     AH, 0Eh
        INT     10h     
        POP     AX
PUTC    ENDM
    
    
; prints out an unsigned value of AX register.
; allowed values from 0 to 65535   
print_num_uns   proc    near
        push    ax
        push    bx
        push    cx
        push    dx
        ; flag to prevent printing zeros before number:
        mov     cx, 1
        ; (result of "/ 10000" is always less or equal to 9).
        mov     bx, 10000       ; 2710h - divider.
        ; ax is zero?
        cmp     ax, 0
        jz      print_zero
begin_print:
        ; check divider (if zero go to end_print):
        cmp     bx,0
        jz      end_print
        ; avoid printing zeros before number:
        cmp     cx, 0
        je      calc
        ; if ax<bx then result of div will be zero:
        cmp     ax, bx
        jb      skip
calc:
        mov     cx, 0   ; set flag.
        mov     dx, 0
        div     bx      ; ax = dx:ax / bx   (dx=remainder).
        ; print last digit
        ; ah is always zero, so it's ignored
        add     al, 30h    ; convert to ascii code.
        putc    al
        mov     ax, dx  ; get remainder from last div.
skip:
        ; calculate bx=bx/10
        push    ax
        mov     dx, 0
        mov     ax, bx
        div     cs:ten  ; ax = dx:ax / 10   (dx=remainder).
        mov     bx, ax
        pop     ax
        jmp     begin_print        
print_zero:
        putc    '0'        
end_print:
        pop     dx
        pop     cx
        pop     bx
        pop     ax
        ret
ten             dw      10      ; used as divider.      
print_num_uns   endp





; print null terminated string at ds:si
print_string proc near
push    ax      ; store registers...
push    si      ;

nxtch:  mov     al, [si]
        cmp     al, 0
        jz      printed
        inc     si
        mov     ah, 0eh ; teletype function.
        int     10h
        jmp     nxtch
printed:

pop     si      ; re-store registers...
pop     ax      ;

ret
print_string endp




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
        mov     bh, 07  ; attribute for new lines.
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


; some interrupt info:

; -----------------------------------------------------------
;   INT 21h / AH= 3Dh - open existing file.     
;   entry: ;    
;   AL = access and sharing modes (if unsure set to zero). 
;   DS:DX -> ASCIZ filename.
;   return: 
;   CF clear if successful, AX = file handle.
;   CF set on error AX = error code. 
;   Note: file pointer is set to start of file. 
; -----------------------------------------------------------
;   INT 21h / AH= 3Fh - read from file. 
;   entry: 
;   BX = file handle. 
;   CX = number of bytes to read. 
;   DS:DX -> buffer for data. 
;   return: 
;   CF is clear if successful - AX = number of bytes actually read; 0 if at EOF (end of file) before call. 
;   CF is set on error AX = error code. 
;   note: data is read beginning at current file position, and the file position is updated after
;         a successful read the returned AX may be smaller than the request in CX if a partial read occurred. 
; -----------------------------------------------------------   
;   INT 21h / AH= 3Eh - close file.     
;   entry: BX = file handle     
;   return:     
;   CF clear if successful, AX destroyed. 
;   CF set on error, AX = error code (06h). 
; -----------------------------------------------------------
;   INT 13h / AH = 03h - write disk sectors.
;   input:
;   AL = number of sectors to read/write (must be nonzero)
;   CL = sector number (1..18).
;   CH = cylinder number (0..79).
;   DH = head number (0..1).
;   DL = drive number (0..3 , for the emulator it depends on quantity of FLOPPY_ files).
;   ES:BX points to data buffer.
;   return:
;   CF set on error.
;   CF clear if successful.
;   AH = status (0 - if successful).
;   AL = number of sectors transferred. 
;   Note: each sector has 512 bytes. 
; -----------------------------------------------------------
; INT 10h / AH = 02h - set cursor position.
;  input:
;  DH = row.
;  DL = column.
;  BH = page number (0..7).
; -----------------------------------------------------------
;  INT 21h / AH=09h - output of a string at DS:DX.
;  string must be terminated by '$' character. 
; -----------------------------------------------------------



