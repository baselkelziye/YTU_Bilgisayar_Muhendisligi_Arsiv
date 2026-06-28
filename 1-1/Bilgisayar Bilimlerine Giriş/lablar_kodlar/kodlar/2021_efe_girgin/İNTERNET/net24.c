#include <stdio.h>
int main(){
	long long sayi;
	int count=0;
	printf("bir sayi giriniz\n");
	scanf("%lld",&sayi);
	
	while(sayi!=0){
		sayi=sayi/10;
		count++;
	}
	printf("%d haneli bir sayidir",count);
	return 0;
	
	
}
//Program to Count the Number of Digits
