#include <stdio.h>
#define N 50

int main()
{
    int sayac=0;
    char temp;
    char input;
    int flag=1;
    int adim=0;
    int kelimeUzunluk=0;

    char dizi[N];

    printf("Kelimeyi giriniz: ");
    scanf("%s",&dizi);

    printf("\n");

    do
    {
        kelimeUzunluk++;                 // kelimenin uzunlugunu bulma
    }while(dizi[kelimeUzunluk]!='\0');

    

    while(flag==1)
    {
        adim++;

        do
        {
            printf("%c",dizi[sayac]);
            sayac++;                        // kelimeyi yazdir

        }while(sayac<=kelimeUzunluk);

        printf("\n");

        sayac=0;
        temp=dizi[0];  // ilk eleman kaydirmada kaybolacagindan degiskende tuttum ve sonda son elemana eşitledim              

        if(adim!=kelimeUzunluk+1)          // Eger son adim degilse dizinin elemanlarini kaydir
        {
            do
            {
                dizi[sayac]=dizi[sayac+1];
                sayac++;
            }while(sayac<=kelimeUzunluk-1);
            dizi[kelimeUzunluk-1]=temp;
            sayac=0;
        }

        if(adim==kelimeUzunluk+1)       // Son adima geldiginde devam edip etmeyecegini sor
        {
            adim=0;

            printf("\nDevam etmek icin e veya E tuslayiniz: ");
            scanf(" %c",&input);

            if(input=='e' || input=='E')
            {
                flag=1;
            }
            else
            {
                flag=0;
            }

            printf("-------------------------\n");
        }
    
    }
        
    return 0;
}