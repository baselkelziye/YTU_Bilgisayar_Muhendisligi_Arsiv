
; Macroinstructions for HLL-style conditional operations

macro .if [arg]
{
  common
  __IF equ
  local ..endif
  __ENDIF equ ..endif
  local ..else
  __ELSE equ ..else
  JNCOND __ELSE,arg
}

macro .else
{
  jmp __ENDIF
  __ELSE:
  restore __IF
  __IF equ ,
}

macro .elseif [arg]
{
  common
  jmp __ENDIF
  __ELSE:
  restore __ELSE
  local ..else
  __ELSE equ ..else
  JNCOND __ELSE,arg
}

macro .endif
{
  if __IF eq
   __ELSE:
  end if
  __ENDIF:
  restore __ELSE
  restore __ENDIF
  restore __IF
}

macro .while [arg]
{
  common
  local ..while
  __WHILE equ ..while
  local ..endw
  __ENDW equ ..endw
  __WHILE:
  JNCOND __ENDW,arg
}

macro .endw
{
  jmp __WHILE
  __ENDW:
  restore __ENDW
  restore __WHILE
}

macro .repeat
{
  local ..repeat
  __REPEAT equ ..repeat
  __REPEAT:
}

macro .until [arg]
{
  common
  JNCOND __REPEAT,arg
  restore __REPEAT
}

macro JNCOND label,[cond]
{
 common
 match =COND v1>==v2, COND cond
 \{
   cmp v1,v2
   jb label
   COND equ
 \}
 match =COND v1<==v2, COND cond
 \{
   cmp v1,v2
   ja label
   COND equ
 \}
 match =COND v1==v2, COND cond
 \{
   cmp v1,v2
   jne label
   COND equ
 \}
 match =COND v1<>v2, COND cond
 \{
   cmp v1,v2
   je label
   COND equ
 \}
 match =COND v1>v2, COND cond
 \{
   cmp v1,v2
   jbe label
   COND equ
 \}
 match =COND v1<v2, COND cond
 \{
   cmp v1,v2
   jae label
   COND equ
 \}
 match =COND v1=,c=,v2, COND cond
 \{
   cmp v1,v2
   jn\#c label
   COND equ
 \}
 match =COND v, COND cond
 \{
   if v eqtype 0
    if ~ v
     jmp label
    end if
   else if v eqtype eax
    test v,v
    jz label
   else
    cmp v,0
    je label
   end if
   COND equ
 \}
 restore COND
}

jnne equ je
jnna equ ja
jnnb equ jb
jnng equ jg
jnnl equ jl
jnnae equ jae
jnnbe equ jbe
jnnge equ jge
jnnle equ jle
