#include <stdio.h>
int main(){
	int N,i,j;
	printf("satir sayisini giriniz\n");
	scanf("%d",&N);
	
	for(i=1;i<=N;i++){
		for(j=1;j<=i;j++){
			printf("%d",j);
		}
		printf("\n");
	}
	return 0;
}
//Example 2: Half Pyramid of Numbers
