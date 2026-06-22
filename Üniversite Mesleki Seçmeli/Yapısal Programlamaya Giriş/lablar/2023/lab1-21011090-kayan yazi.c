#include<stdio.h>

#define MAX 200
int main() {
	
	int i=0,uzunluk=0,j=0;
	char kelime[MAX];
	char cevap,temp;
	
	do {
		printf("\nLutfen Kelimeyi Girin\n");
		scanf("%s",&kelime);
		
		do{
			i++;
		}while(kelime[i]!='\0');
		
		uzunluk=i;
		j=0;
		do{
			printf("%dth step:%s\n",j+1,kelime);
			i=0;
			temp=kelime[0];
			do{
				kelime[i]=kelime[i+1];
				i++;
			}while(i<uzunluk-1);
			kelime[i] = temp;
			j++;
		}while(j!=uzunluk+1);
		
		printf("Devam Etmek istiyor musun(E/e) ?");
		cevap = getch(stdin);
		i=0;
	}while((cevap == 'E') || (cevap == 'e'));
	
	return 0;
}
