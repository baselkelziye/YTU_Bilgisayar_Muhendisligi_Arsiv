#include <stdio.h>
#include <stdlib.h>
int** scanmatris(int **a ,int *n){
	int i,j;
	printf("Kare Matrisin satir sayisi = ?\n");
	scanf("%d",n);
	a=(int**)calloc(n,sizeof(int*));
	for(i=0;i<*n;i++){
		*(a+i)=(int*)calloc(n,sizeof(int));
		for(j=0;j<*n;j++){
			printf("Matrisin [%d][%d] elemani = ?\n",i,j);
			scanf("%d",*(a+i)+j);
		}
	}
	return a;
}
void printmatris(int ** m,int n){
	int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("%d\t",*(*(m+i)+j));}
			printf("\n");
		}
}
void squarematris(int**m,int n){
	int i,j,**matr,k;
	matr=(int**)calloc(n,sizeof(int*));
	for(i=0;i<n;i++){
		*(matr+i)=(int*)calloc(n,sizeof(int));
		for(j=0;j<n;j++){
			for(k=0;k<n;k++){
			*(*(matr+i)+j)+=*(*(m+i)+k)**(*(m+k)+j);
		}
		}
	}
	printmatris(matr,n);
}

int main(){
	int i,n,**m;
	m=scanmatris(m,&n);
	printmatris(m,n);
	squarematris(m,n);
	return 0;
}
