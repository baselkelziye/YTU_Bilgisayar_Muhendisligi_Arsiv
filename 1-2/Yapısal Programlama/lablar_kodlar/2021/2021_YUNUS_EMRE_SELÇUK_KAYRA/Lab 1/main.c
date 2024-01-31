#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "calculations.h"
#include "menu.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	setlocale(LC_ALL,"turkish");
	int x, y, selection, run = 1, result, i;
	MENU;
	scanf("%d", &selection);  
	
	while(run){
		switch(selection){
			case 1:
				printf("Toplanacak ilk say�: ");
				scanf("%d", &x);  
				printf("Toplanacak ikinci say�: ");
				scanf("%d", &y); 
				printf("%d + %d = %d \n", x, y, SUM(x,y));
				MENU;
				scanf("%d", &selection); 
				break;
			case 2:
				printf("Eksilen say�: ");
				scanf("%d", &x);  
				printf("��kan say�: ");
				scanf("%d", &y); 
				printf("%d - %d = %d \n", x, y, DIFFERENCE(x,y));
				MENU;
				scanf("%d", &selection); 
				break;
			case 3:
				printf("1.�arpan say�: ");
				scanf("%d", &x);  
				printf("2.�arpan say�: ");
				scanf("%d", &y); 
				printf("%d * %d = %d \n", x, y, PRODUCT(x,y));
				MENU;
				scanf("%d", &selection); 
				break;
			case 4:
				printf("B�l�nen say�: ");
				scanf("%d", &x);  
				printf("B�len say�: ");
				scanf("%d", &y); 
				printf("%d / %d = %d \n", x, y, QUOTIENT(x,y));
				MENU;
				scanf("%d", &selection); 
				break;
			case 5:
				printf("n! , n'i giriniz: ");
				scanf("%d", &x);
				result = x;
				i = x;
				while(x>1){
					result = result * --x;
				} 
				printf("%d! = ", i);
				for(i; i>0; i--)
				{					
					if(i == 1){
						printf("%d = %d \n", i, result);
					}
					else
					{
						printf("%d * ", i);	
					}
				} 
				MENU;
				scanf("%d", &selection); 
				break;				
			case 6:
				run = 0;
				break;
			default:
				printf("Ge�erli bir giri� yapmad�n�z, tekrar deneyin...");
				scanf("%d", &selection); 	
		}
	}
	
	return 0;
}
