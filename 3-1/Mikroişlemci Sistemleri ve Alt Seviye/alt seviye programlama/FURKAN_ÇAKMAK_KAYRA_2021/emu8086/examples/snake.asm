; this is the screen eating snake game...
;
; this game pushes the emulator to its limits,
; and even with maximum speed it still runs slowly.
; to enjoy this game it's recommended to run it on real
; computer, however the emulator can be useful to debug
; tiny games and other similar programs such as this before
; they become bug-free and workable.
;
; you can control the snake using arrow keys on your keyboard.
;
; all other keys will stop the snake.
;
; press esc to exit.


name "snake"

org     100h

; jump over data section:
jmp     start

; ------ data section ------

s_size  equ     7

; the snake coordinates
; (from head to tail)
; low byte is left, high byte
; is top - [top, left]
snake dw s_size dup(0)

tail    dw      ?

; direction constants
;          (bios key codes):
left    equ     4bh
right   equ     4dh
up      equ     48h
down    equ     50h

; current snake direction:
cur_dir db      right

wait_time dw    0

; welcome message
msg 	db "==== how to play ====", 0dh,0ah
	db "this game was debugged on emu8086", 0dh,0ah
	db "but it is not designed to run on the emulator", 0dh,0ah
	db "because it requires relatively fast video card and cpu.", 0dh,0ah, 0ah
	
	db "if you want to see how this game really works,", 0dh,0ah
	db "run it on a real computer (click external->run from the menu).", 0dh,0ah, 0ah
	
	db "you can control the snake using arrow keys", 0dh,0ah	
	db "all other keys will stop the snake.", 0dh,0ah, 0ah
	
	db "press esc to exit.", 0dh,0ah
	db "====================", 0dh,0ah, 0ah
	db "press any key to start...$"

; ------ code section ------

start:

; print welcome message:
mov dx, offset msg
mov ah, 9 
int 21h


; wait for any key:
mov ah, 00h
int 16h


; hide text cursor:
mov     ah, 1
mov     ch, 2bh
mov     cl, 0bh
int     10h           


game_loop:

; === select first video page
mov     al, 0  ; page number.
mov     ah, 05h
int     10h

; === show new head:
mov     dx, snake[0]

; set cursor at dl,dh
mov     ah, 02h
int     10h

; print '*' at the location:
mov     al, '*'
mov     ah, 09h
mov     bl, 0eh ; attribute.
mov     cx, 1   ; single char.
int     10h

; === keep the tail:
mov     ax, snake[s_size * 2 - 2]
mov     tail, ax

call    move_snake


; === hide old tail:
mov     dx, tail

; set cursor at dl,dh
mov     ah, 02h
int     10h

; print ' ' at the location:
mov     al, ' '
mov     ah, 09h
mov     bl, 0eh ; attribute.
mov     cx, 1   ; single char.
int     10h



check_for_key:

; === check for player commands:
mov     ah, 01h
int     16h
jz      no_key

mov     ah, 00h
int     16h

cmp     al, 1bh    ; esc - key?
je      stop_game  ;

mov     cur_dir, ah

no_key:



; === wait a few moments here:
; get number of clock ticks
; (about 18 per second)
; since midnight into cx:dx
mov     ah, 00h
int     1ah
cmp     dx, wait_time
jb      check_for_key
add     dx, 4
mov     wait_time, dx



; === eternal game loop:
jmp     game_loop


stop_game:

; show cursor back:
mov     ah, 1
mov     ch, 0bh
mov     cl, 0bh
int     10h

ret

; ------ functions section ------

; this procedure creates the
; animation by moving all snake
; body parts one step to tail,
; the old tail goes away:
; [last part (tail)]-> goes away
; [part i] -> [part i+1]
; ....

move_snake proc near

; set es to bios info segment:  
mov     ax, 40h
mov     es, ax

  ; point di to tail
  mov   di, s_size * 2 - 2
  ; move all body parts
  ; (last one simply goes away)
  mov   cx, s_size-1
move_array:
  mov   ax, snake[di-2]
  mov   snake[di], ax
  sub   di, 2
  loop  move_array


cmp     cur_dir, left
  je    move_left
cmp     cur_dir, right
  je    move_right
cmp     cur_dir, up
  je    move_up
cmp     cur_dir, down
  je    move_down

jmp     stop_move       ; no direction.


move_left:
  mov   al, b.snake[0]
  dec   al
  mov   b.snake[0], al
  cmp   al, -1
  jne   stop_move       
  mov   al, es:[4ah]    ; col number.
  dec   al
  mov   b.snake[0], al  ; return to right.
  jmp   stop_move

move_right:
  mov   al, b.snake[0]
  inc   al
  mov   b.snake[0], al
  cmp   al, es:[4ah]    ; col number.   
  jb    stop_move
  mov   b.snake[0], 0   ; return to left.
  jmp   stop_move

move_up:
  mov   al, b.snake[1]
  dec   al
  mov   b.snake[1], al
  cmp   al, -1
  jne   stop_move
  mov   al, es:[84h]    ; row number -1.
  mov   b.snake[1], al  ; return to bottom.
  jmp   stop_move

move_down:
  mov   al, b.snake[1]
  inc   al
  mov   b.snake[1], al
  cmp   al, es:[84h]    ; row number -1.
  jbe   stop_move
  mov   b.snake[1], 0   ; return to top.
  jmp   stop_move

stop_move:
  ret
move_snake endp


