#include <stdio.h>
int main(){
	int N,i,j;
	printf("lutfen satir sayisini giriniz\n");
	scanf("%d",&N);
	
	for(i=0;i<N;i++){
		for(j=0;j<=i;j++){
			printf("* ");
		}
		printf("\n");
	}
	return 0;
}
//Example 1: Half Pyramid of *
