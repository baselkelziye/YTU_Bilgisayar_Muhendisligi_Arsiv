#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N,k,i;
    printf("Ucaklarin sayisini giriniz: ");
    scanf("%d",&N);
    while(N<=0){
        printf("Ucaklarin sayisini tekrar pozitif olarak giriniz: \n");
        scanf("%d",&N);
    }

    printf("\nIki ucak arasinda kalkis icin verilen dakika araligini giriniz: ");
    scanf("%d",&k);

    int ucakno[N], klkzmn[N];

    printf("\nUcaklarin numaralarini giriniz: \n");
    for(i=0;i<N;i++){
            scanf("%d",&ucakno[i]);
    }
    printf("\nUcaklarin kalkis zamanlarini giriniz ustteki ucaklarin sirasiyla giriniz: \n");
    for(i=0;i<N;i++){
        scanf("%d",&klkzmn[i]);
    }

    int Pist1[N],klkzmn1[N],Pist2[N],klkzmn2[N];
    int sayac1=0,sayac2=0;
    double gec1=0, gec2=0;

    for(i=0;i<N;i++){
        if(sayac1==0){
            Pist1[sayac1]=ucakno[i];
            klkzmn1[sayac1]=klkzmn[i];
            sayac1++;
        }
        else if(sayac2==0){
            Pist2[sayac2]=ucakno[i];
            klkzmn2[sayac2]=klkzmn[i];
            sayac2++;
        }
        else if  (klkzmn[i] >= (klkzmn1[sayac1 - 1] + k) || klkzmn[i] >= (klkzmn2[sayac2 - 1] + k)) {
            if(klkzmn2[sayac2-1] > klkzmn1[sayac1-1]){
                Pist1[sayac1]=ucakno[i];
                klkzmn1[sayac1]=klkzmn[i];
                sayac1++;
                }
            else if(klkzmn2[sayac2-1] < klkzmn1[sayac1-1]){
                Pist2[sayac2]=ucakno[i];
                klkzmn2[sayac2]=klkzmn[i];
                sayac2++;
                }
                else{
                    if(sayac1>sayac2){
                        Pist2[sayac2]=ucakno[i];
                        klkzmn2[sayac2]=klkzmn[i];
                        sayac2++;
                    }
                    else{
                        Pist1[sayac1]=ucakno[i];
                        klkzmn1[sayac1]=klkzmn[i];
                        sayac1++;
                    }
                }
            }
        else if (sayac1>sayac2){
            Pist2[sayac2]=ucakno[i];
            klkzmn2[sayac2]=klkzmn2[sayac2-1]+k;
            gec2 = gec2 + (klkzmn2[sayac2] - klkzmn[i]);
            sayac2++;
        }
        else{
            Pist1[sayac1]=ucakno[i];
            klkzmn1[sayac1]=klkzmn1[sayac1-1]+k;
            gec1 = gec1 + (klkzmn1[sayac1] - klkzmn[i]);
            sayac1++;
        }
    } 
    double ort1, ort2;
    ort1 = gec1/(sayac1);
    if(sayac2 != 0){
        ort2 = gec2/(sayac2);
    }

    printf("\nPist1_Ucaklar: ");
    for (i = 0; i < sayac1; i++) {
        printf("%d ", Pist1[i]);
    }

    printf("\nPist1_Saatler: ");
    for (i = 0; i < sayac1; i++) {
        printf("%d ", klkzmn1[i]);
    }

    printf("\nPist1 Ortalama Gecikme: %.4f\n", ort1);

    printf("\n\nPist2_Ucaklar: ");
    for (i = 0; i < sayac2; i++) {
        printf("%d ", Pist2[i]);
    }
    printf("\nPist2_Saatler: ");
    for (i = 0; i < sayac2; i++) {
        printf("%d ", klkzmn2[i]);
    }
    printf("\nPist2 Ortalama Gecikme: %.4f\n", ort2);

    return 0;
}
