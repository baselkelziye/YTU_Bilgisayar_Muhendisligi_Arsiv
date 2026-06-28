#include <stdio.h>
int main(){
	int bolum,kalan,bolunen,bolen;
	printf("lutfen bolunen sayiyi giriniz\n");
	scanf("%d",&bolunen);
	
	printf("lutfen bolen sayiyi giriniz\n");
	scanf("%d",&bolen);
	
	bolum=bolunen/bolen;
	kalan=bolunen%bolen;
	
	printf("bolum =%d ve kalan=%d",bolum,kalan);
	return 0;
}
//Program to Compute Quotient and Remainder
