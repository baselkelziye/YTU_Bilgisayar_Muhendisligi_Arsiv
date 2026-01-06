#include <stdio.h>
// Verilen dizide neg. sayılar mutlak değeri kadar sayıyı ve kendisini yok edecek. İki bombanın alanının çakışmadığı uygun dizi girilmesi istensin
// Tüm bombalar patlayınca dizide kalan elemanı yazdıralım
int main () {
int N;
int dizi[100];
int alan[100];
int elverisli =0;
int cakisma;
int etki;
//Dizi dersinde gordugumuz ve sınavda da sorulan histogram mantıgını kullanacagım. 0 olan değerleri yazdıracagım
while (elverisli == 0) {
    cakisma=0;
    printf("Oyuna baslamak icin dizi boyutunu giriniz ");
    scanf("%d", &N);
    printf("Elemanlari giriniz ");
    for(int i=0; i<N; i++) {
        scanf("%d", &dizi[i]);
        alan[i]=0;
    }
    for(int i=0; i<N; i++) {
        if (dizi[i] <0) {
            etki= dizi[i]* -1;
        
         for (int j= i-etki; j<= i+etki; j++) {
            if (j >= 0 && j < N) {
                if(alan [j] ==1) {
                    cakisma =1;
                } else {
                    alan[j] =1;
                }
            }
        }
        }
    }
//Simdi döngü bitti, her seyi gördük, karar verecegiz
if(cakisma==1) {
    printf("Oyuna elverisli degildir \n");
    elverisli=0;
} else {
    elverisli=1;
}
}
//Buraya kadar gelmisse demektir ki uygun diziyi aldık, patlatıp sonucu yazdırmaya gececegiz
printf("Bombalar patladi \n");
for (int i=0; i<N; i++) {
    if(alan[i]==0) {
        printf("%d ", dizi[i]);
    }
}
return 0;
}