#include <stdio.h>
int main(){
	int N,i;
	printf("lutfen dizinin boyutunu giriniz\n");
	scanf("%d",&N);
	int A[N];
	
	for(i=0;i<N;i++){
		printf("%d.eleman=",i+1);
			scanf("%d",&A[i]);
		
	}
	i=1;
	while(A[i]<A[i+1]&&i<N-2){
		i=i+1;
	}
		if(i==N-2){
			printf("sirali");
		}
		else{
			printf("degil");
		}
	
}
//kod calýsýyor
//sayfa 2
