; this sample shows how to access virtual ports (0 to 0FFFFh).
; these ports are emulated in this file: c:\emu8086.io

; this new technology allows to make external add-on devices
; for emu8086, such as led displays, thermostat, stepper-motor, etc...

; "devices" folder contains sample device that works with this sample.
; (with visual basic source code).

#start=simple.exe#

#make_bin#

name "simple"

; write byte value 0A7h into the port 110:
mov al, 0A7h
out 110, al

; write word value 1234h into the port 112:
mov ax, 1234h
out 112, ax

mov ax, 0 ; reset register.

; read byte from port 110 into AL:
in al, 110

; read word from port 112 into AX:
in ax, 112


hlt


