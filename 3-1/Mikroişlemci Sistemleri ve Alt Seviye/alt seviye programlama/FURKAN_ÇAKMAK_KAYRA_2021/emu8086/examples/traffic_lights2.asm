
; Traffic ligts test 2 for
; c:\emu8086\devices\Traffic_Lights.exe

; This is just an example of how to set the lights,
; better if you run it in step-by-step mode.
; DO NOT RUN AT MAXIMUM SPEED, DO NOT USE REAL CARS.
;)


#start=Traffic_Lights.exe#

name "traffic2"

yellow_and_green equ      0000_0110b
red              equ      0000_0001b
yellow_and_red   equ      0000_0011b
green            equ      0000_0100b

all_red          equ      0010_0100_1001b

start:
nop


; 0,1,2

mov ax, green
out 4, ax

mov ax, yellow_and_green 
out 4, ax

mov ax,red
out 4, ax

mov ax, yellow_and_red
out 4, ax


; 3,4,5

mov ax, green << 3
out 4, ax

mov ax, yellow_and_green << 3
out 4, ax

mov ax,red << 3
out 4, ax

mov ax, yellow_and_red << 3
out 4, ax



; 6,7,8

mov ax, green << 6
out 4, ax

mov ax, yellow_and_green << 6
out 4, ax

mov ax,red << 6
out 4, ax

mov ax, yellow_and_red << 6
out 4, ax



; 9,A,B

mov ax, green << 9
out 4, ax

mov ax, yellow_and_green << 9
out 4, ax

mov ax,red << 9
out 4, ax

mov ax, yellow_and_red << 9
out 4, ax


; all

mov ax, all_red
out 4, ax

mov ax, all_red << 1  ; all yellow
out 4, ax

mov ax, all_red << 2  ; all green :)
out 4, ax


jmp start
