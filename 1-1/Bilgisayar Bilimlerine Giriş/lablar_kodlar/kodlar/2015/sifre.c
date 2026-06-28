#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	char c;
	char cumle[100];//cumle icin dizi tanimlaniyor
	int i=0,j=0;//cevrim degiskeni
	int n;//cumlenin uzunlugunu tutacak degisken
	
/*	puts("Cumle giriniz:");
	gets(cumle);*/
printf("Cumle giriniz:");

  while(c!='\n'){
  	c=getchar();
  	cumle[j]=c;
  	j++;
  }
	cumle[j]='\0';
	
	
	for(n=0;cumle[n]!='\0';n++);//girilen cumlenin uzunlugu olculuyor.
	
	//puts(cumle);
	
	printf("\nSifre:");
	while(i<n){
		if(cumle[i]!=' '){
			printf("%c",cumle[i+1]);
			i+=2;
			while(cumle[i]!=' ' && cumle[i]!='\0'){
				i++;
			}
		}
		else{
			i++;
		}
	}

	
	return 0;
}
