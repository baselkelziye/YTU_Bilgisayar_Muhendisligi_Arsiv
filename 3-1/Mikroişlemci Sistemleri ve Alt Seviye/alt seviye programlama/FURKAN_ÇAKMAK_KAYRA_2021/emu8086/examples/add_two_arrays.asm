name "add-2"

; this example calculates the sum of a vector with
; another vector and saves result in third vector.

; you can see the result if you click the "vars" button.
; set elements for vec1, vec2 and vec3 to 4 and show as "signed".

org 100h

jmp start

vec1 db 1, 2, 5, 6
vec2 db 3, 5, 6, 1
vec3 db ?, ?, ?, ?

start:

lea si, vec1
lea bx, vec2
lea di, vec3

mov cx, 4

sum:       
    mov al, [si]
    add al, [bx]
    mov [di], al
   
    inc si
    inc bx
    inc di
   
    loop sum

ret



