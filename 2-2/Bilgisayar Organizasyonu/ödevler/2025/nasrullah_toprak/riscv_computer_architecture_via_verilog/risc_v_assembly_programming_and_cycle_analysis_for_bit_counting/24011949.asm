# File: 24011949.asm
# ARRAY dizisindeki her elemanın 0, 2, 4, ..., 30 numaralı bitlerinde
# bulunan 1'lerin sayısını hesaplar ve sonuçları COUNT dizisine yazar.
# ARRAY base address  = 0
# COUNT base address  = 80

        addi x1, x0, 0          # x1 = ARRAY pointer
        addi x2, x0, 80         # x2 = COUNT pointer
        addi x3, x0, 20         # x3 = number of elements

outer_loop:
        lw   x5, 0(x1)          # x5 = ARRAY[i]
        addi x6, x0, 0          # x6 = count
        addi x7, x0, 1          # x7 = mask, starts from bit 0
        addi x9, x0, 16         # x9 = number of even bit positions

inner_loop:
        and  x8, x5, x7         # check current even-positioned bit
        beq  x8, x0, skip_inc   # if the bit is 0, do not increment count
        addi x6, x6, 1          # count++

skip_inc:
        add  x7, x7, x7         # mask <<= 1
        add  x7, x7, x7         # mask <<= 2, next even bit
        addi x9, x9, -1         # processed bit count--
        beq  x9, x0, store_count
        jal  x0, inner_loop

store_count:
        sw   x6, 0(x2)          # COUNT[i] = count
        addi x1, x1, 4          # next ARRAY element
        addi x2, x2, 4          # next COUNT element
        addi x3, x3, -1         # remaining element count--
        beq  x3, x0, finish
        jal  x0, outer_loop

finish:
        jal  x0, finish         # stop here
