#include <stdio.h>

int main()
{
    int i,j,k,y;
    int M,N,K;
    int filtreToplam=0,toplam=0;
    int filtreSatir=0,filtreSutun=0,sonucSatir=0,sonucSutun=0;
    
    printf("Konvolusyon islemi uygulanacak matrisin satir ve sutun sayisini aralarinda bir bosluk birakarak giriniz: ");
    scanf("%d %d",&M,&N);
    
    printf("Konvolusyon matrisinin satir ve sutun sayisindan kucuk ve tek olan kare filtre matrisinin derecesini giriniz:  ");
    scanf("%d",&K);

    int konvoMatris[M][N];
    int filtreMatris[K][K];
    int sonucMatris[M-K+1][N-K+1];

    printf("Konvolusyon islemi uygulanacak matrisin elemanlarini teker teker giriniz!\n");
    for(i=0;i<M;i++)
    {
        for(j=0;j<N;j++)
        {
            scanf("%d",&konvoMatris[i][j]);
        }
    }

    printf("Filtre matrisinin elemanlarini teker teker giriniz!\n");
    for(i=0;i<K;i++)
    {
        for(j=0;j<K;j++)
        {
            scanf("%d",&filtreMatris[i][j]);
            filtreToplam+=filtreMatris[i][j];
        }
    }
    
    // Konvolusyon islemlerini gerceklestirme
    for(i=0;i<M-K+1;i++)
    {
        for(y=0;y<N-K+1;y++)
        {
            for(j=i;j<i+K;j++)
            {
                for(k=y;k<y+K;k++)
                {
                    toplam+=konvoMatris[j][k]*filtreMatris[filtreSatir][filtreSutun];
                    filtreSutun++;                        
                }
                filtreSatir++;
                filtreSutun=0;
            }
            filtreSatir=0;
            sonucMatris[sonucSatir][sonucSutun]=toplam/filtreToplam;
            sonucSutun++;
            toplam=0;
        }
        sonucSatir++;
        sonucSutun=0;
    }
    
    printf("Konvolusyon Sonucu:\n");

    // Konvolusyon sonucunu ekrana yazdirma
    for(i=0;i<M-K+1;i++)
    {
        for(j=0;j<N-K+1;j++)
        {
            printf("%d ",sonucMatris[i][j]);
        }
        printf("\n");
    }


    return 0;
}