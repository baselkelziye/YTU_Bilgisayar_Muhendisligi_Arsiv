#include<stdio.h>

int main()

{
	int sayi1=16, sayi2=3	, toplam,fark;

	toplam=sayi1+sayi2;
	fark=sayi1-sayi2;	
    float bolum=(float)sayi1/(float) sayi2;
	
	printf("TOPLAM = %d",toplam);
	printf("\nFARK= %d", fark);
	printf("\nbol=%.2f",bolum);
}
