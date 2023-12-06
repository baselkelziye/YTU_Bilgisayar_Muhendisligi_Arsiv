#include <stdio.h>
#include "mehmet.h"
#include <locale.h>
#include <stdlib.h>
#define sum {\
float x,y; \
printf("Çarpýlacak ilk sayýyý giriniz");\
scanf("%f",&x);\
printf("Çarpýlacak 2. sayýyý giriniz");\
scanf("%f",&y);\
printf("Çarpým = %f",x*y);\
}
#define div {\
float x,y; \
	printf("Bölünen sayýyý giriniz");\
	scanf("%f",&x);\
	printf("Bölen sayýyý giriniz");\
	scanf("%f",&y);\
	printf("Bölüm = %f",x/y);\
} 

int main(){
	 int i=1;
	 setlocale(LC_ALL,"turkish");
	veli;
	scanf("%d",&i);
	while(i!=0){
	switch(i){
	 case 1:
	 	sum;
	 	veli;
	 	scanf("%d",&i);
	 	break;
	case 2:
		div;
		veli;
		scanf("%d",&i);
		break;
	case 3:
		i=0;
		break;
	default:
		printf("Geçerli bir sayý girmediniz lütfen tekrar giriþ yapýnýz");
		veli;
		scanf("%d",&i);}}
	return 0;
}
