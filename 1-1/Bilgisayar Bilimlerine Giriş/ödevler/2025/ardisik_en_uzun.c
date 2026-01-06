#include <stdio.h>
// -1 girilene kadar renk kodlarını alıp en uzun süre art arda girilen renk sırasının uzunluğunu ve renk kodunu yazdıran kod
int main() {
    
    int sayi;
    int onceki = -2; //-1 ile 255 arasında olmayan bir değere önceki demek istedim
    int uzunluk = 0;
    int maxuzunluk = 0;
    int maxrenk = 0;
    printf("Seri -1 girince sonlanacaktir.\n");
    scanf("%d", &sayi);
    while(sayi > -1) 
    {
       if (sayi == onceki) {
            uzunluk++;
        } 
       else{
           if (uzunluk > maxuzunluk) { // Her bir ardışıklık sonlandığında uzunluğunu kontrole sokuyoruz
               maxuzunluk = uzunluk;
               maxrenk = onceki;
           } 
           uzunluk = 1; //Her ardışıklık bitişinde uzunluğu 1'e çekmeyi unutmamak lazım!
        } 
       onceki = sayi;
       scanf("%d", &sayi);
    }
    
    if (uzunluk > maxuzunluk) //-1 girilince while'dan çıktı ama biz -1'den önceki sırayı kontrol etmedik. O yüzden son bi kez daha kontrole sokuyoruz
    {
        maxuzunluk = uzunluk;
        maxrenk = onceki;
        printf("Renk: %d uzunluk: %d",maxrenk, maxuzunluk);
    }
    else 
    {
        if(maxuzunluk>0) // Kullanıcı bir değer girdiyse 
        {
            printf("Renk: %d uzunluk: %d",maxrenk, maxuzunluk);
        }
        else //Değer girmediyse
        {
            printf("Hiçbir değer girmediniz");
        }
    }
}