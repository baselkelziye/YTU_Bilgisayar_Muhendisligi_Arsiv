; procedures inside another procedure.


org 100h
      
mov ax, abc               
mov abc_off, ax     
mov abc_seg, cs
     

call far abc_off
call abc1
call abc2
ret
   
abc_off dw ?
abc_seg dw ?

abc    proc     far 
  mov ax, -1
  jmp r
  
  abc1   proc   near 
         mov ax, 1 
         ret 
  endp 


  abc2   proc   near
         mov ax, 2
         ret 
  endp 
  
  r:
  retf
endp 
 
 
 