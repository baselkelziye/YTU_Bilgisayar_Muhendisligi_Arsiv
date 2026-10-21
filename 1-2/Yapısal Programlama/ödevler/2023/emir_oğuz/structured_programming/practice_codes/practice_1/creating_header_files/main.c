#include <stdio.h>
#include "menu.h"
#include "calculation.h"
#include "functions.h"

int main(int argc, char *argv[]) 
{
	int x, y;
	int selection;
	int run = 1;
	int result;
	int i; 
	
	while(run){
		MENU;
		
		scanf("%d", &selection);
		
		switch(selection){
			case 1:
				system("cls");
				printf("-> Toplanacak ilk sayi: ");
				scanf("%d", &x);
				printf("-> Toplanacak ikinci sayi: ");
				scanf("%d", &y);
				printf("-> %d + %d = %d\n\n", x, y, topla(x, y));
				break;
				
			case 2:
				system("cls");
				printf("-> Eksilen sayiyi giriniz: ");
				scanf("%d", &x);
				printf("-> Cikan sayiyi giriniz: ");
				scanf("%d", &y);
				printf("-> %d - %d = %d\n\n", x, y, cikar(x, y));
				break;
				
			case 3:
				system("cls");
				printf("-> Ilk carpani giriniz: ");
				scanf("%d", &x);
				printf("-> Ikinci carpani giriniz: ");
				scanf("%d", &y);
				printf("-> %d x %d = %d\n\n", x , y, carp(x, y));
				break;
				
			case 4:
				system("cls");
				printf("-> Bolunen sayiyi giriniz: ");
				scanf("%d", &x);
				printf("-> Bolen sayiyi giriniz: ");
				scanf("%d", &y);
				printf("-> %d / %d = %d\n\n", x, y, bol(x, y));
				break;
				
			case 5:
				system("cls");
				printf("-> Faktoriyeli alinacak sayiyi giriniz: ");
				scanf("%d", &x);
				faktoriyel(x);
				break;
				
			case 6:
				system("cls");
				printf("-> Gorusmek uzere!\n");
				run = 0;
				break;
				
			default:
				system("cls");
				printf("-> Gecerli bir giris yapmadiniz, tekrar deneyin...\n\n");
		}
	}
	
	getch();
	
	return 0;
}

