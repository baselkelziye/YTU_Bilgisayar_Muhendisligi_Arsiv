#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "calculations.h" //Kendi oluþturduklarýmýzý bu þekilde include ediyoruz
#include "menu.h"
int main(int argc, char *argv[]){
	setlocale(LC_ALL,"turkish");
	int x,y,selection,run=1,result,i;
	MENU
	scanf("%d",&selection);
	while(run){//while'ýn içindeki sayý 0'dan farklýsa while döner.
		switch(selection){
			case 1:
				printf("Toplanacak ilk sayý: ");
				scanf("%d",&x);
				printf("Toplanacak ikinci sayý: ");
				scanf("%d",&y);
				printf("%d + %d = %d\n",x,y,SUM(x,y));
				MENU;
				scanf("%d",&selection);
				break;
			case 2:
				printf("Eksilen sayý: ");
				scanf("%d",&x);
				printf("Çýkan sayý: ");
				scanf("%d",&y);
				printf("%d - %d = %d\n",x,y,DIFFRENCE(x,y));
				MENU;
				scanf("%d",&selection);
				break;
			case 3:
				printf("1. çarpan sayý: ");
				scanf("%d",&x);
				printf("2. çarpan sayý: ");
				scanf("%d",&y);
				printf("%d x %d = %d\n",x,y,PRODUCT(x,y));
				MENU;
				scanf("%d",&selection);
				break;
			case 4:
				printf("Bölünen sayý: ");
				scanf("%d",&x);
				printf("Bölen sayý: ");
				scanf("%d",&y);
				printf("%d / %d = %d\n",x,y,QUOTIENT(x,y));
				MENU;
				scanf("%d",&selection);
				break;
			case 5:
			run=0;
			break;
			default://caselere eþit olan hiçbir þey girilmezse bu çýktýyý veriyor
				printf("geçerli bir giriþ yapmadýnýz, tekrar deneyin...");
				scanf("%d",&selection);
		}
	}
	return 0;
}

