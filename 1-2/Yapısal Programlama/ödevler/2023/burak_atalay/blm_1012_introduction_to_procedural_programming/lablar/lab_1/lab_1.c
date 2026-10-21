#include<stdio.h>
#define max 50
int main(){
	int i, j, k, len;
	char kelime[max], temp, cevap;
	do{
		scanf("%s", kelime);
		i=0;
		do{
			i++;
		} while(kelime[i]!='\0');
		len=i, i=0, j=0;
		do{
			temp=kelime[0], j=0, k=0;
			do{
				kelime[j]=kelime[j+1];
				j++;
			} while(j<len-1);
			kelime[len-1]=temp;
			i++;
			do{
				printf("%c", kelime[k]);
				k++;
			} while(k<len);
			printf("\n");
		} while(i<len);
		printf("devam etmek ister misin...\n");
		scanf(" %c", &cevap);
	} while(cevap=='e' || cevap=='E');
	return 0;
}
