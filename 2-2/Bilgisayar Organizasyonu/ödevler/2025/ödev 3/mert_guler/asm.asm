
# Brian Kernighan'in popcount algoritmasi kullanilmistir.
# Sagdan baslayip sayiyi shift ederek N zamanda bulmak yerine:
# Her adimda N = (N and N - 1) yapacagiz ve N = 0 olana kadar devam edecegiz.
# Ornegin 1010 icin: 
# 1010 & 1001 = 1000, popcount = 1;
# 1000 & 0111 = 0000, popcount = 2;
# Bu sayede konum fark etmekeden O(LogN) karmasiklikta sonuca ulasmis oluruz. 

    add t0, x0, x0  # t0'i mem[0] adresinden baslat 
    addi t1, x0, 80  # t1'i mem[20] adresinden baslat (20 x 4 = 80)
    li t2, 20  # t2: hesaplanacak eleman sayisi

loop:
    beq t2, x0, end  # Hesaplanacak eleman kalmadiysa algoritmayi bitir
    lw t3, 0(t0)  # t3 = ARRAY[i]
    li t4, 0  # t4: t3'un popcount adet sayisi

count:
    beq t3, x0, save  # t3 = 0 ise sayimi bitir ve sayaci hafizaya kaydet
    addi t6, t3, -1   # t3'den bir cikart ve t6'ya yaz. Ornegin 0110 ise 0101 kalacak. 
    and t3, t3, t6   # t3 ve t6'yi ANDle. 0100 kalacak. tekrarla -> 0100 & 0011 = 0000; sayac = 2;
    addi t4, t4, 1  # popcount sayacini bir arttir. 
    jal count

save:
    sw t4, 0(t1)  # COUNT[i] adresine t4'u yaz
    addi t0, t0, 4   # ARRAY adresini sonraki elemana arttir
    addi t1, t1, 4    # COUNT adresini sonraki elemana arttir
    addi t2, t2, -1  # Kalan eleman sayacini bir azalt
    jal loop

end:
    jal end
