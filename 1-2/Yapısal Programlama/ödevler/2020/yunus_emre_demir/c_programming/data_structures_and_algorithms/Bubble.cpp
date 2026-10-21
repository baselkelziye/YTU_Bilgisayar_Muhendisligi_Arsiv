#include<stdio.h>

/* Bubble Sort Algorithm :ikili ikili kiyaslar, her seferinde en buyuk sayiyi en sona atar.
Onemli nokta su ki: ic ici iki for var ilki  (n-1)'e ve ikincisi (n-1-i)'e kadar doner
*/
int main(){
	int n=0,i,j,tmp=0;
	
	printf("Diziniz kac elemanli?");
	scanf("%d",&n);
	int dizi[n];
	
	printf("\nDizinize elemanlariný giriniz.");
	for(i=0; i<n ; i++){  scanf("%d",&dizi[i]);}	 	//dizi yarat  
	printf("\nMevcut diziniz : \n");
	for(i=0; i<n ; i++){  printf("%d ",dizi[i]);	} // dizi yazdýr.
	
	for(i=0; i<n-1 ; i++){   
		for(j=0; j<n-1-i ; j++){  
			if(dizi[j]>dizi[j+1]){
				tmp=dizi[j];
				dizi[j]=dizi[j+1];
				dizi[j+1]=tmp;
			}
		}
	}
	
	printf("\nSirali diziniz : \n");
	for(i=0; i<n ; i++){  printf("%d ",dizi[i]);	} // dizi yazdýr.
	
	
	return 0;
}
