
; Simulate MASM's syntax

struc struct
 { struct .
   name@struct equ . }

struc ends
 { match =.,name@struct \{ ends \} }

struc proc [params]
 { common define@proc .,<params>
   name@proc equ . }

struc endp
 { match =.,name@proc \{ endp \} }

macro option setting
 { match =prologue:macro, setting \{ prologue@proc equ macro \}
   match =epilogue:macro, setting \{ epilogue@proc equ macro \} }

macro none procname,flag,parmbytes,localbytes,reglist { }