#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "calculations.h" //Kendi olu�turduklar�m�z� bu �ekilde include ediyoruz
#include "menu.h"
int main(int argc, char *argv[]){
	setlocale(LC_ALL,"turkish");
	int x,y,selection,run=1,result,i;
	MENU
	scanf("%d",&selection);
	while(run){//while'�n i�indeki say� 0'dan farkl�sa while d�ner.
		switch(selection){
			case 1:
				printf("Toplanacak ilk say�: ");
				scanf("%d",&x);
				printf("Toplanacak ikinci say�: ");
				scanf("%d",&y);
				printf("%d + %d = %d\n",x,y,SUM(x,y));
				MENU;
				scanf("%d",&selection);
				break;
			case 2:
				printf("Eksilen say�: ");
				scanf("%d",&x);
				printf("��kan say�: ");
				scanf("%d",&y);
				printf("%d - %d = %d\n",x,y,DIFFRENCE(x,y));
				MENU;
				scanf("%d",&selection);
				break;
			case 3:
				printf("1. �arpan say�: ");
				scanf("%d",&x);
				printf("2. �arpan say�: ");
				scanf("%d",&y);
				printf("%d x %d = %d\n",x,y,PRODUCT(x,y));
				MENU;
				scanf("%d",&selection);
				break;
			case 4:
				printf("B�l�nen say�: ");
				scanf("%d",&x);
				printf("B�len say�: ");
				scanf("%d",&y);
				printf("%d / %d = %d\n",x,y,QUOTIENT(x,y));
				MENU;
				scanf("%d",&selection);
				break;
			case 5:
			run=0;
			break;
			default://caselere e�it olan hi�bir �ey girilmezse bu ��kt�y� veriyor
				printf("ge�erli bir giri� yapmad�n�z, tekrar deneyin...");
				scanf("%d",&selection);
		}
	}
	return 0;
}

