#include <stdio.h>
#include <stdlib.h>
#define SIZE 1000
int main() {
	int i,n,arr[SIZE]={0},temp,count,j=0,mgccount=0,k;
    int mgc[SIZE] = {0};
    printf("Dizinin Boyutunu Giriniz : ");  // DÝZÝ BOYUTUNU ALMA
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("Dizinin %d. elemaninin giriniz: ",i+1); // DÝZÝ ELEMANLARINI ALMA
        scanf("%d",&arr[i]);
    }
    for(i=0;i<n;i++){
        temp = arr[i];  // DÝZÝNÝN ELEMANINI GEÇÝCÝ DEÐÝÞKENE ATAMA
        count=0;        // SAYAÇ DEÐÝÞKEN
        for(k=0;k<n;k++){
            if(arr[k] == temp){     //AYNI ELEMANLARI KONTROL ETME
                    count++;        //SAYACI ARTTIRMA
            }
        }
        if(count == arr[i]){        //SAYAC ÝLE SAYININ KENDÝSÝ EÞÝT ÝSE SAYIYI DÝZÝYE ATMA
            mgc[j] = temp;
            mgccount++;
            j++;
            arr[i] = 0;                //TEKRARDAN SAYMAMAK ÝÇÝN SAYIYI 0 A ÇEVÝRME
        }
    }
    printf("\n\n");
    if(mgccount != 0){
        printf("Bu Dizide Bulunan Sihirli Sayilar :  ");
        for(i=0;i<mgccount;i++){
            printf("%d  ",mgc[i]);
        }
    }
    else{
        printf("Bu Dizide Sihirli Sayi Yoktur");
    }
	return 0;
}
