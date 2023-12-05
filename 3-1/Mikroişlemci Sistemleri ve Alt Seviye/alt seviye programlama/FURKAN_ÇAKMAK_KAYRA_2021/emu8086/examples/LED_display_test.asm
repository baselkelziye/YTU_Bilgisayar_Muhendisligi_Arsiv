; this example shows how to access virtual ports (0 to 65535).
; these ports are emulated in this file: c:\emu8086.io

; this technology allows to make external add-on devices
; for emu8086, such as led displays, robots, thermometers, stepper-motors, etc... etc...

; anyone can create an animated virtual device.

; c:\emu8086\devices\led_display.exe

#start=led_display.exe#


#make_bin#

name "led"

mov ax, 1234
out 199, ax

mov ax, -5678
out 199, ax

; Eternal loop to write
; values to port:
mov ax, 0
x1:
  out 199, ax  
  inc ax
jmp x1

hlt


