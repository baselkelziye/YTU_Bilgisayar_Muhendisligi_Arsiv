; this is an example of how to make a ".bin" file.

name "bintest"

; directive to create bin file:
#make_bin#

; where to load?
#load_segment=1234#
#load_offset=0000#

; set these values to registers on load:
#al=12#
#ah=34#
#bh=56#
#bl=78#
#ch=9a#
#cl=bc#
#dh=de#
#dl=f0#
#ds=ddee#
#es=abcd#
#si=aaaa#
#di=cccc#
#bp=dddd#
#cs=1234#
#ip=0000#
#ss=3000#
#sp=ffff#

; when loading "bintest.bin" file in emulator
; it will look for a "bintest.binf" file,
; and load ".bin" file to location specified
; in that file, registers are also set using
; information in that file (open this file
; in a text editor to edit or investigate).
;
; ".binf" file is created automatically
; by compiler when it processes the above
; directives.



; this sample just prints out a part of
; some ascii character set, in an eternal
; loop, press [stop] or esc to terminate.


start:

mov     al, '0'
mov     ah, 0eh

print_more:

int     10h
inc     al

; keep original ax:
mov     cx, ax

;============================
; check for esc key to
;    reboot:

; check for keystroke in
; keyboard buffer:
mov     ah, 1
int     16h
jz      key_processed

; get keystroke from keyboard:
; (remove from the buffer)
mov     ah, 0
int     16h

; press 'esc' to exit:
cmp     al, 27
jnz     key_processed
hlt

key_processed:
;============================

; restore original ax:
mov     ax, cx


cmp     al, 'z'
jbe     print_more

mov     al, '0'
jmp     print_more




