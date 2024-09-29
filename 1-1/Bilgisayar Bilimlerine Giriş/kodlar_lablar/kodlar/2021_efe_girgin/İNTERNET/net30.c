#include <stdio.h>
int main(){
	printf("lutfen bir sayi giriniz\n");
	scanf("%d",&sayi);
	
	while(sayi!=0){
		tutucu=sayi%10;
		hane=hane+tutucu*tutucu*tutucu;
		sayi=sayi/10;
	}
	if(hane==sayi){
		printf("%d bir armstrong sayidir\n",sayi);
		
	}
	else{
		printf("%d bir armstrong sayi degildir\n");
		
	}
	return 0;
}
//Check Armstrong Number of three digits
