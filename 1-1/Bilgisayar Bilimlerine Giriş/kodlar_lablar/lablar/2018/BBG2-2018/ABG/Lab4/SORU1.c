#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAXROW 10
#define MAXCOLUMN 10
void fillMatrix(char text[][MAXCOLUMN], int M, int N);
void searchPattern(char text[][MAXCOLUMN], int M, int N,char pattern[]);
int main() {
	srand(time(NULL));
	char pattern[MAXCOLUMN];
	char text[MAXROW][MAXCOLUMN];
	int M,N;
	printf("Number of Row="); scanf("%d",&M);
	printf("Number of Column="); scanf("%d",&N);
    fillMatrix(text,M,N);	
	
	printf("ENTER PATTERN\n");
	scanf("%s",pattern);
	searchPattern(text,M,N,pattern);

	system("pause");
	return 0;
}

void fillMatrix(char text[][MAXCOLUMN], int M, int N){
	int i,j;
	printf("RANDOM TEXT\n");
	for(i=0;i<M;i++){
		for(j=0;j<N;j++){
			text[i][j] = (char) (rand()%5+'A'); 
			printf("%3c",text[i][j]); //3 karakterlik yer ayiriyor her karaktere
		} 
		printf("\n");
	}	
}

void searchPattern(char text[][MAXCOLUMN], int M, int N,char pattern[]) {
	int i=0,j=0,k=0, bound,c=0;
	int length=0, flag=0; 	
	while(pattern[length]!='\0') 
		{length++; } // pattern uzunluðu 

	printf("Pattern Length:%d\n",length);
	
	for(k=0;k<M;k++){
		bound=N-length;
		for (i = 0; i <=bound; i++) {
			j = 0;
			while (j < length && text[k][i+j] == pattern[j]) {
				j++;
			}
			if (j == length) {
				flag=1; c++;
				printf("Pattern Starts: %d. row %d. column\n",k,i);
			}
		}
	}

	if(!flag)
	{
		printf("No Words\n");
	}
	else 
	printf("Counter=%d",c);
	
}
