#include <stdio.h>
int main(){
	int orijinal,sayi,tutucu,hane;
	printf("bir sayi giriniz\n");
	scanf("%d",&sayi);
	orijinal=sayi;
	
	while(sayi!=0){
		tutucu=sayi%10;
		hane=hane*10+tutucu;
		sayi=sayi/10;
	}
	if(orijinal==hane){
		printf("%d bir palindrom sayidir\n",orijinal);
	}
	else{
		printf("%d bir palindrom degildir\n",orijinal);
	}
	return 0;
}
//Program to Check Palindrome
