#include <stdio.h>
int main(){
	int year;
	printf("lutfen yili giriniz\n");
	scanf("%d",&year);
	
	if(year%400==0){
		printf("%d bir artik yildir\n",year);
	}
	else if(year%100==0){
		printf("%d bir artik yildir\n",year);
	}
	else if(year%4==0){
		printf("%d bir artik yildir\n",year);
	}
	else{
		printf("%d bir artik yil degildir\n",year);
	}
	return 0;
}
//Program to Check Leap Year
