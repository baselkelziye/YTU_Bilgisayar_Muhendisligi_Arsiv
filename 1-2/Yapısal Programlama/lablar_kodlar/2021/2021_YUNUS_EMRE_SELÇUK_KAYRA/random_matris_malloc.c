#include <stdio.h>
#include <locale.h>
#define merhaba(m,n){\
	matris=(int**)malloc(n*sizeof(int*));\
	for(i=0;i<n;i++){\
		*(matris+i)=(int*)malloc(m*sizeof(int));\
		\
	}\
}
int main(){
	int** matris;
	int i,j;
	srand(time(NULL));
	int m=rand()%2+4,n=rand()%2+2;
	merhaba(m,n);
		setlocale(LC_ALL,"turkish");
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			printf("matrisin %d. satýr %d. sütundaki elemanýný giriniz",i+1,j+1);
			scanf("%d",(*(matris+i)+j));
		}
			printf("\n");
	}
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			printf("%d\t",*(*(matris+i)+j));
		}
			printf("\n");
	}
	return 0;
}
