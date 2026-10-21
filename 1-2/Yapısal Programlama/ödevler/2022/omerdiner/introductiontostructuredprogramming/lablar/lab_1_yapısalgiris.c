#include <stdio.h>
#define SIZE 500
int main(){
	
	int n,alinanDizi[SIZE],kontrolDizi[SIZE];	
    int i;
    int adet=0;
    
    printf("Kac elemanli bir dizi gireceksiniz:");
    scanf("%d",&n);
    
    //kontrol dizisini kullanýrken sýkýntý olmasýn diye en baþta degerlerini sýfýrladým
	for(i=0;i<n;i++){
		kontrolDizi[i]=0;
	}
	
	
	// 0.indis boþ kalmasýn diye diziyi 0'dan baþlayarak yerleþtirdim
	for(i=0;i<n;i++){
		printf("%d. elemani giriniz:",i+1);
		scanf("%d",&alinanDizi[i]);
		
		if(alinanDizi[i]<=n){
			kontrolDizi[alinanDizi[i]-1]++;
		}
	}
	
	printf("\n");
	
	// dongu sýfýrda baþladýðý için i+1. sayý kontrolDizi[i] ye eþit mi diye bakýyoruz
	for(i=0;i<n;i++){
		if(i+1==kontrolDizi[i]){
			printf("%d ",i+1);
			adet++;
		}
	}
	
	//sihirli sayý yoksa kullanýcýya belirtir
	if(adet==0){
		printf("Bu dizide hic sihirli sayi yok.");
	}
	
	return 0;   
	
}
