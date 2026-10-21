#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	int A[5000];
	int i,temp,bas,bit,mid,num,guessnum=1;
	srand(time(NULL));
	printf("***Istediginiz Sayi Araligini Giriniz***");
	printf("\nBaslangic: ");
	scanf("%d",&bas);
	printf("\nBitis: ");
	scanf("%d",&bit);
	printf("Bulunmasýný Istediginiz Sayiyi Giriniz: ");
	scanf("%d",&num);
	mid = (bit+bas)/2;
	temp = 0;
	for(i=bas;i<=bit;i++){
		
		A[temp]=i;
		temp++;
	}
	while(mid!=num){
		
		mid = (bit+bas)/2;
		printf("Tahmin= %d - Bitis = %d - Baslangic = %d\n",mid,bit,bas);
		if(mid == num){
			printf("Tebirkler Dogru Sonucu Buldunuz");
			printf("\nDeneme Sayisi= %d",guessnum);
		}
		else if(mid > num){
			bit = mid;
		}
		else if(mid<num){
			bas=mid;
		}
	guessnum++;	
	}
	
	return 0;
}
