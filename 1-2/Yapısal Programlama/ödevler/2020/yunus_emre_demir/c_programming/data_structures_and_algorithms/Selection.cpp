#include<stdio.h>

/*Selection Sort : En kucugu bulup en basa atan algoritma
*/

int main(){
	int n=0,yer,min,i,j;
	
	printf("Diziniz kac elemanli?");
	scanf("%d",&n);
	int dizi[n];
	
	printf("\nDizinize elemanlarini giriniz.");
	for(i=0; i<n ; i++){  scanf("%d",&dizi[i]);}	 	//dizi yarat  
	printf("\nMevcut diziniz : \n");
	for(i=0; i<n ; i++){  printf("%d ",dizi[i]);	} // dizi yazdýr.
	

	for(i=0; i<n-1 ; i++){   
		min=dizi[i];
		yer=i;
		for(j=i+1; j<n ; j++){  //  Bu for en kucuk sayiyi buluyor
			if(dizi[j]<min){
				min=dizi[j];
				yer=j;
			}
		}
		dizi[yer]=dizi[i];   // fordan ciktiktan sonra en kucuk sayi dizinin en basina atiliyor
		dizi[i]=min;		// sonrak gelenler yanina gelmesi sureyitle iþ tamamlaniyor.
	}
	
	printf("\nSirali diziniz : \n");
	for(i=0; i<n ; i++){  printf("%d ",dizi[i]);	} // dizi yazdýr.
	
	
	return 0;
}


