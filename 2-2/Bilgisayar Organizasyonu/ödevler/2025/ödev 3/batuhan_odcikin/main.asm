    .text
    .globl main
main:
    # --- Değişken Başlatma ---
    # s1 = 0x99999999
    lui   x10, 0x99999               # upper 20 bit ← 0x99999                                    :contentReference[oaicite:0]{index=0}
    addi  x10, x10, 0x999            # lower 12 bit ekle → x10 = 0x99999999                   :contentReference[oaicite:1]{index=1}

    # s2 = 1
    addi  x11, x0, 1                 # x11 = 1                                                 :contentReference[oaicite:2]{index=2}

    # ctr = 0
    addi  x12, x0, 0                 # x12 = 0                                                 :contentReference[oaicite:3]{index=3}

    # limit = 0xFFFFFFFFF
    lui   x13, 0xFFFFF             # upper 20 bit ← 0xFFFFF                                  :contentReference[oaicite:4]{index=4}
    addi  x13, x13, 0xFFF            # lower 12 bit ekle → x13 = 0xFFFFFFFFF                   :contentReference[oaicite:5]{index=5}

loop:
    # if (s2 >= limit) break;
    bgeu  x11, x13, end              # unsigned karşılaştırma, x11 ≥ x13 ise dallan (break)   :contentReference[oaicite:6]{index=6}

    # if ((s1 & s2) == s2) ctr++;
    and   x5,  x10, x11              # x5 = s1 & s2                                            :contentReference[oaicite:7]{index=7}
    beq   x5,  x11, do_inc           # eşitse → sayaç arttır                                    :contentReference[oaicite:8]{index=8}

    # s2 <<= 1
    slli  x11, x11, 1                # x11 = x11 << 1                                         :contentReference[oaicite:9]{index=9}
    jal   x0, loop                   # döngü başına atla                                     :contentReference[oaicite:10]{index=10}

do_inc:
    addi  x12, x12, 1                # ctr++                                                 :contentReference[oaicite:11]{index=11}
    slli  x11, x11, 1                # s2 <<= 1                                              :contentReference[oaicite:12]{index=12}
    jal   x0, loop                   # döngü başına                                          :contentReference[oaicite:13]{index=13}

end:
    # return ctr; a0=x10 olarak
    addi  x10, x12, 0                # a0 = ctr                                             :contentReference[oaicite:14]{index=14}
    jalr  x0, x1, 0                  # ret (x1=ra üzerinden)                                 :contentReference[oaicite:15]{index=15}
