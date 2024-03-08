#include <stdio.h>
#define MAXROW 10
#define MAXCOLUMN 10
void fillMatrix(char text[][MAXCOLUMN], int M, int N);
void searchPattern(char text[][MAXCOLUMN], int M, int N,char pattern[]);
void searchPattern1(char text[][MAXCOLUMN], int M, int N,char pattern[]);
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
	searchPattern(text,M,N,pattern);  //grup1
	searchPattern1(text,M,N,pattern); //grup2
	
	return 0;
}

void fillMatrix(char text[][MAXCOLUMN], int M, int N){
	int i,j=0;
	printf("RANDOM TEXT\n");
	printf("   ");
	for(i=0;i<N;i++)
		printf("%3d",i);
	printf("\n");
	for(i=0;i<M;i++){
		printf("%3d",i);
		for(j=0;j<N;j++){
			text[i][j] = (char) (rand()%2+'A'); 
			printf("%3c",text[i][j]);
		} 
		printf("\n");
	}	
}

/* grup-1*/
void searchPattern(char text[][MAXCOLUMN], int M, int N,char pattern[]) {
	printf("\n--------------------\nsearch on rows\n");
	int i=0,j=0,k=0, bound,c=0;
	int length=0, flag=0; 	
	while(pattern[++length]!='\0'){} // pattern uzunluðu


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

	if(!flag){
		printf("No Words\n");
	}
	else 
	printf("Counter=%d",c);	
}
/* grup-2*/
void searchPattern1(char text[][MAXCOLUMN], int M, int N,char pattern[]) {
	printf("\n--------------------\nsearch on columns\n");
	int i=0,j=0,k=0, bound,c=0;
	int length=0, flag=0; 	
	while(pattern[++length]!='\0'){} // pattern uzunluðu 
		 

	printf("Pattern Length:%d\n",length);
	
	for(k=0;k<N;k++){
		bound=M-length;
		i=0;
		while(i<=bound){
			j = 0;
			while (j < length && text[i+j][k] == pattern[j]) {
				j++;
			}
			if (j == length) {
				flag=1; c++;
				printf("Pattern Starts: %d. row %d. column\n",i,k);
			}
		i++;
		}
	}

	if(!flag){
		printf("No Words\n");
	}
	else 
	printf("Counter=%d",c);	
}
