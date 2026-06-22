#include<stdio.h>
#define MAX 50

void get_data(int matrix[MAX][3], int N, char works[MAX]);
int findWork(char works[MAX], int N, char data);
void printWork(int N, int matrix[MAX][3], int head, char works[MAX]);


int main() {
	int N, head, i;
	int matrix[MAX][3];
	char works[MAX];
	printf("N is sayisini giriniz: ");
	do{
		scanf("%d",&N);
	}while(N<0);
	
	get_data(matrix, N, works);
	
	do{
		printf("head degerini girin: ");
		scanf("%d",&head);
		if((head<0) || (head>N-1)){
			printf("lutfen gecerli bir deger gir: ");
		}
	}while((head<0) || (head>N-1));
	
	for(i=0;i<N;i++){
		
		printf("link sirasini girin: ");
		scanf("%d",&matrix[i][2]);
	}
	
	printWork(N, matrix, head, works);
	return 0;
}

void get_data(int matrix[MAX][3], int N, char works[MAX]){
	int i, isThere=0;
	
	for(i=0;i<N;i++){
		printf("%d. isi giriniz: ",i+1);
		
		do{
			scanf(" %c",&works[i]);
			isThere= findWork(works, i ,works[i]);
			if(isThere){
				printf("farkli bir is gir: ");
			}
		}while(isThere);
	}
	
	
	for(i=0;i<N;i++){
		printf("%d. isin suresini gir: ",i+1);
		do{
			scanf("%d",&matrix[i][1]);
			if(matrix[i][1]<1){
				printf("lutfen en az 1 olacak sekilde gecerli bir sure gir: ");
			}
		}while(matrix[i][1]<1);
		
	}
}

int findWork(char works[MAX], int N, char data) {
	
	int i, isThere=0;
	for(i=0;i<N;i++){
		if(works[i]==data){
			isThere=1;
		}
	}
	return isThere;
}

void printWork(int N, int matrix[MAX][3], int head, char works[MAX]){
	
	int i, j;
	for(i=0;i<N;i++){
		for(j=0;j<matrix[head][1];j++){
			printf("%c",works[head]);
		}
		head = matrix[head][2];
	}
	
}

