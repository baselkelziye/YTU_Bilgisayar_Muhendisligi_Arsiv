#include <stdio.h>
#include "mull_div_menu.h"
#include <locale.h>
#include <stdlib.h>
#define sum {\
float x,y; \
printf("�arp�lacak ilk say�y� giriniz");\
scanf("%f",&x);\
printf("�arp�lacak 2. say�y� giriniz");\
scanf("%f",&y);\
printf("�arp�m = %f",x*y);\
}
#define div {\
float x,y; \
	printf("B�l�nen say�y� giriniz");\
	scanf("%f",&x);\
	printf("B�len say�y� giriniz");\
	scanf("%f",&y);\
	printf("B�l�m = %f",x/y);\
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
		printf("Ge�erli bir say� girmediniz l�tfen tekrar giri� yap�n�z");
		veli;
		scanf("%d",&i);}}
	return 0;
}
