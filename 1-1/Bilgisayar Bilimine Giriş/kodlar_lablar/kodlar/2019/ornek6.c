#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
int main(){
  //metod kullan 
  
    /*char c1;
    printf("Bir karakter giriniz ->");
    scanf("%c", &c1);
    if(!isdigit(c1)){
        printf("Harftir\n");
    }else{
        printf("Rakamdir\n");
    }
    if(!isdigit(c1)){
        if(isalpha(c1)){
            if(islower(c1)){
                printf("Kucuk harftir: %c\n", c1);
            }else{
                printf("Buyuk harftir\n");
            }
        }else{
            if(isspace(c1)){
                printf("Bosluk karakteri girdiniz.\n");
            }else{
                if(isprint(c1)){
                    printf("%c\n", c1);
                }else{
                    printf("Ekrana basamam: %c\n", c1);
                }
            }
        }
    }else{
        printf("Rakamdir\n");
    }*/
    /*char katar[100], katar2[100];
    printf("String girin: ");
    scanf("%s", katar);
    printf("Bir daha string girin: ");
    scanf("%s", katar2);*/
    /*printf("katar: %s\n", katar);
    double f1;
    f1 = atof(katar);
    printf("Girilen %s katarinin float hali %f dir\n", katar, f1);
    int i1 = atoi(katar);
    printf("Gerilen integer: %d\n",i1);
    strcpy(katar2, katar);
    printf("Katar2: %s\n", katar2);
    strcat(katar, katar2);
    printf("Eklemeli string: %s", katar);*/
    /*if(!strcmp(katar, katar2)){
        printf("Esittir\n");
    }else{
        printf("Esit degildir\n");
    }*/
    char c2 = 'c';
   printf(BuyukMu(c2))

 Buyukmu(char c2) 
{
	printf(islower(c2)?"1\n" : "2\n");	
	return 1;
}

    return 0;
}

