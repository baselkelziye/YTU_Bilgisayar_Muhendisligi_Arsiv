#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "calculations.h"
#include "menu.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	setlocale(LC_ALL, "turkish");
	int selection, run = 1, x, y, result;
	
	while(run){
		MENU;
		scanf("%d", &selection);
		switch(selection){
			case 1: //Toplama
				printf("input 1 : ");
				scanf("%d", &x);
				printf("input 2 : ");
				scanf("%d", &y);
				printf("%d + %d = %d\n", x, y, SUM(x,y));
				break;	
			case 2: // Çýkarma
				printf("input 1 : ");
				scanf("%d", &x);
				printf("input 2 : ");
				scanf("%d", &y);
				
				printf("%d - %d = %d\n", x, y, DIFFERENCE(x, y));
				break;
			case 3: // Çarpma
				printf("input 1 : ");
				scanf("%d", &x);
				printf("input 2 : ");
				scanf("%d", &y);
				printf("%d * %d = %d\n", x, y, PRODUCT(x, y));
				break;
			case 4: // Bölme
				printf("input 1 : ");
				scanf("%d", &x);
				printf("input 2 : ");
				scanf("%d", &y);
				printf("%d / %d = %d\n", x, y, QUOTIENT(x, y));
				break;
			case 5:
				printf("n! , n deðerini giriniz.");
				scanf("%d", &x);
				result = x;
				y = x;
				while(x > 1){
					result = result * --x;
				}
				printf("%d! = ", y);
				for(y; y>0; y--)
				{
					if(y == 1)
					{
						printf("%d = %d \n", y, result);
					}
					else
					{
						printf("%d * ", y);
					}
				}
				break;
			case 6: // Çýkýþ 
				run = 0;
				break;
			default:
				printf("Geçerli bir giriþ yapmadýnýz, lütfen tekrar deneyiniz.. \n");
				break;	
		}
		
	}
	
	return 0;
}
