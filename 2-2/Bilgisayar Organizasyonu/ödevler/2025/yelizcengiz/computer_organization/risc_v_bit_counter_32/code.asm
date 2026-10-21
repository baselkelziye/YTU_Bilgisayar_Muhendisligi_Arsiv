    addi s0, zero, ARRAY_ADDR
    addi s1, zero, COUNT_ADDR
    addi t0, zero, 20  
loop:
    lw   t1, 0(s0)
    addi t2, zero, 0 
    addi t3, zero, 32 
poploop:
    andi t4, t1, 1
    add  t2, t2, t4
    srl  t1, t1, 1
    addi t3, t3, -1
    bne  t3, zero, poploop
    sw   t2, 0(s1)
    addi s0, s0, 4
    addi s1, s1, 4 
    addi t0, t0, -1
    bne  t0, zero, loop