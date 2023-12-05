; Date and time functions
; Get date and time and save to file using Disk Operating System interrupts.

; The program prints the date and saves it to file when running from emu8086 the path is:
; c:\emu8086\vdrive\c\date.txt
; when running from dos prompt the path is:
; c:\date.txt

name "datefile"

org 100h  

TAB EQU 9   ; ASCII CODE

mov ah, 2ah                  ; get date 
int 21h 
lea bx, week_table
xlat
mov w. week, al                 ; 0=sunday  
add cx, 0f830h               ; for years 
mov ax, cx 
call deci 
mov w. year, ax 
mov al, dh                   ; month 
call deci 
mov w. mont, ax 
mov al, dl                   ; day 
call deci 
mov w. day, ax 


mov ah, 2ch                  ; get time 
int 21h 
mov al, ch                   ; hour 
call deci 
mov w. hour, ax 
mov al, cl                   ; minute 
call deci 
mov w. minu, ax 
mov al, dh                   ; second 
call deci 
mov w. seco, ax 


mov ah, TAB 
mov dx, offset txt 
int 21h 


mov cx, 0                    ; file attribute
mov ax, 3c00h                ; create new file 
mov dx, offset fildat 
int 21h 
jb error                     ; error

mov w. handle, ax

mov ax, 4200h 
mov bx, w. handle 
xor cx, cx                   ; begin byte 0 
xor dx, dx                   ;  
int 21h 
jb error 

mov ah, 40h                  ; write to file 
mov bx, w. handle 
mov cx, offset seco - offset txt  ; 34 bytes 
mov dx, offset dat 
int 21h 
jb error 


mov ah, 3eh                  ; close file.
mov bx, w. handle 
int 21h 



; wait for any key press:
mov ah, 0
int 16h

error:                       ; leave program (unconditionally). 
mov ax, 4c00h
int 21h


deci:                        ; calculate in decimal 
push cx
xor ah, ah 
mov cl, 10 
div cl 
add ax, 3030h
pop cx
ret 


fildat db "c:\date.txt",0    ; where to save date and time.
handle db 0,0 


; here's data to display the date and time 

txt  db 0Dh, 0Ah, 0Ah, TAB, TAB          ; jump line and go two tabs right 
dat  db "week day: "
week db 0, TAB                           ; put the day 1=monday   9 jump a colon (tab)
     db "20"
year db 0, 0, '-'        
mont db 0, 0, '-' 
day  db 0, 0, TAB  


hour db 0, 0, ':'       
minu db 0, 0, ':' 
seco db 0, 0, ' '
      db 0Dh, 0Ah, 24h         ; line feed   return   and  stop symbol 24h=$ (ASCII). 
                    
                    
week_table db "SMTWTFS" 