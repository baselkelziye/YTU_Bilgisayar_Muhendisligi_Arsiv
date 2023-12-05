; hex convertor.
; this example converts a 2 digit hexadecimal number
; into a numeric value and then into decimal/ascii string representation, 
; and finally it prints out the result in binary code.

; to see decimal string:
;   1. click "vars"
;   2. click "result" variable
;   3. enter "3" for the elements and "ascii" for show as.


name "hex"

org 100h

jmp start

; source hex value is 2 char string.
; numeric value is stored into temp,
; and string decimal value is stored into result.

source db '1b', 0     ; 1bh is converted to 27 (decimal) 00011011b (binary)
result db '000', 0
temp   dw ?

start:
; convert first digit to value 0..15 from ascii:
mov al, source[0]
cmp al, '0'
jae  f1

f1:
cmp al, '9'
ja f2     ; jumps only if not '0' to '9'.

sub al, 30h  ; convert char '0' to '9' to numeric value.
jmp num1_ready

f2:
; gets here if it's 'a' to 'f' case:
or al, 00100000b   ; remove upper case (if any).
sub al, 57h  ;  convert char 'a' to 'f' to numeric value.

num1_ready:
mov bl, 16
mul bl      ; ax = al * bl

mov temp, ax




; convert second digit to value 0..15 from ascii:
mov al, source[1]
cmp al, '0'
jae  g1

g1:
cmp al, '9'
ja g2     ; jumps only if not '0' to '9'.

sub al, 30h  ; convert char '0' to '9' to numeric value.
jmp num2_ready

g2:
; gets here if it's 'a' to 'f' case:
or al, 00100000b   ; remove upper case (if any).
sub al, 57h  ;  convert char 'a' to 'f' to numeric value.

num2_ready:
xor ah, ah 
add temp, ax  
; convertion from hex string complete!
push temp ; store original temp value.

; convert to decimal string,
; it has to be 3 decimal digits or less:

mov di, 2  ; point to top of the string.

next_digit:

cmp temp, 0
je stop

mov ax, temp
mov bl, 10
div bl ; al = ax / operand, ah = remainder.
mov result[di], ah
add result[di], 30h ; convert to ascii.

xor ah, ah
mov temp, ax

dec di  ; next digit in string.
jmp next_digit

stop:
pop temp ; re-store original temp value.





; print result in binary:
mov bl, b.temp
mov cx, 8
print: mov ah, 2   ; print function.
       mov dl, '0'
       test bl, 10000000b  ; test first bit.
       jz zero
       mov dl, '1'
zero:  int 21h
       shl bl, 1
loop print

; print binary suffix:
mov dl, 'b'
int 21h

; wait for any key press:
mov ah, 0
int 16h




ret  ; return to operating system.