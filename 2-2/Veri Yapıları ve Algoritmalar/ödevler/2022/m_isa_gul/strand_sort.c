
#include <stdio.h>
#define max 50

int strand(){
    int adim=1,son,a,i,j,n,dizi[max],alt_dizi[max],sonuc[max];

    int dizi_index=0,alt_index=0,sonuc_index=0;

    //Kullanıcıdan sıralanacak dizinin eleman sayısı ve
    //dizi elemanları alınır.
    printf("Eleman sayisi:");
    scanf("%d",&n);
    printf("Dizi elemanlarini giriniz:\n");

    for(i=0;i<n;i++){
        printf("dizi[%d]= ",i);
        scanf("%d",&dizi[i]);
    }

    //Kullanıcının girdiği dizinin ilk elemanı -sonuc[]- dizisine eklenir.
    sonuc[sonuc_index] = dizi[dizi_index];

    //-son- değişkeni -sonuc[]- dizisinin son elemanı olarak güncellenir.
    son = sonuc[sonuc_index];

    //Dizinin ilk elemanını çıkarmak için kaydırma işlemi yapılır.
    for(i=dizi_index;i<n-1;i++){
        dizi[i] = dizi[i+1];
    }

    //Dizinin eleman sayısı güncellenir.
    n -= 1;

    //İlk iterasyon sonuçları -sonuc[]- dizisine eklenir.
    while (dizi_index < n){

        if (dizi[dizi_index] > son){
            sonuc_index += 1;
            sonuc[sonuc_index] = dizi[dizi_index];
            son = sonuc[sonuc_index];

            //-sonuc[]- dizisine eklenen eleman kaydırma işlemi yapılarak
            //ana diziden çıkarılır.
            for(i=dizi_index;i<n-1;i++){
                dizi[i] = dizi[i+1];
            }
            //Dizinin eleman sayısı güncellenir.
            n -= 1;

            //Diziden eleman çıkarıldığı için
            //-dizi_index-'i 1 azaltılır.
            dizi_index -= 1;
        }
        dizi_index += 1;
        
    }
    //İlk adımın sonuçları yazdırılır.
    printf("\n---Adim %d---\n",adim);
        adim += 1;
        printf("Alt dizi: ");
        for ( i = 0; i <= sonuc_index; i++){
            printf("%d ",sonuc[i]);
        }
        printf("\nSonuc dizisi: ");
        for ( i = 0; i <= sonuc_index; i++){
            printf("%d ",sonuc[i]);
        }

    //Ana dizide eleman kalmayana kadar işlemler tekrar eder.
    while(n>0){

        dizi_index = 0;
        alt_index=0;

        alt_dizi[alt_index] = dizi[dizi_index];
        for(i=dizi_index;i<n-1;i++){
            dizi[i] = dizi[i+1];
        }
        n -= 1;

        son = alt_dizi[alt_index];
        
        //while döngüsü ile ana dizi elemanları,
        //-alt_dizi[]-'nin son elemanı ile karşılaştılır.

        
        while (dizi_index < n){

            //-dizi[dizi_index]- elemanı -alt_dizi[]-' nin
            //son elemanından büyükse -alt_dizi[]-' ye eklenir.
            if(dizi[dizi_index] > son){
                alt_index += 1;
                alt_dizi[alt_index] = dizi[dizi_index];

                //-alt_dizi[]-'ye yeni eleman eklendiğinde
                //-son- değişkeni güncellenir.
                son = alt_dizi[alt_index];
                
                //-alt_dizi[]-'ye eklenen eleman,
                //kaydırma işlemi yapılarak ana diziden çıkarılır.
                for(i=dizi_index;i<n-1;i++){
                    dizi[i] = dizi[i+1];
                
                }
                //Dizinin eleman sayısı güncellenir.
                n -= 1;

                //Diziden eleman çıkarıldığı için
                //-dizi_index-'i 1 azaltılır.                
                dizi_index -= 1;
            }
            dizi_index += 1;
        }

        //-alt_dizi[]- ile -sonuc[]- dizileri kendi içlerinde sıralıdır.
        //-alt_dizi[]- elemanları -sonuc[]- dizisinde uygun konumlara yerleştirilir.
        j=0;
        for(i=0;i<=alt_index;i++){
            while(alt_dizi[i] > sonuc[j] && j<=sonuc_index){
                j += 1;
            }
            sonuc_index += 1;
            for(int k=sonuc_index;k >= j;k--){
                sonuc[k+1]= sonuc[k];
            }
            sonuc[j] = alt_dizi[i];
        }
        //Bu işlemler sonrasında -alt_dizi[]- ile -sonuc[]- dizileri birleştirilmiştir.


        //-alt_dizi[]- ve -sonuc[]- dizileri ekrana yazdırılır.
        printf("\n\n---Adim %d---\n",adim);
        adim += 1;
        printf("Alt dizi: ");
        for ( i = 0; i <= alt_index; i++){
            printf("%d ",alt_dizi[i]);
        }
        printf("\n\nSonuc dizisi: ");
        for ( i = 0; i <= sonuc_index; i++){
            printf("%d ",sonuc[i]);
        }
    }

    return 0;
}


int main(){
    int devam=1;

    while(devam == 1){
        strand();
        printf("\n\nDevam etmek ister misiniz? (1-Evet 0-Hayir)\n");
        scanf("%d",&devam);
    }
    return 0;
}

