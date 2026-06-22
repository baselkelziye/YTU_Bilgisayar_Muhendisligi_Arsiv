#include <stdio.h>
int main(){
	int N,i,j,t;
	printf("lutfe N sayisini giriniz\n");
	scanf("%d",&N);
	t=0;
	for(i=0;i<N;i++){
		for(j=0;j<=i;j++){
			t=t+1;
			printf("%d",t);
		}
		
		printf("\n");
	}
	
	return 0;
}
//kod calýsýyor
//sayfa 3
