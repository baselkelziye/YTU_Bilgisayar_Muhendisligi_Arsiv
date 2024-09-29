#include <stdio.h>
int main(){
	int N,i,bir=0,iki=0;
	printf("lutfen N sayisini giriniz\n");
	scanf("%d",&N);
	int A[N];
	for(i=0;i<N;i++){
		printf("%d.eleman=",i+1);
		scanf("%d",&A[i]);
	}
	
	for(i=0;i<N;i++){
		if(A[i]==1){
			bir=bir+1;
		}
		else{
			iki=iki+1;
		}
	}
	printf("%d tane 1 %d tane 2 vardir",bir,iki);
	return 0;
}
//kod calýsýyor
//sayfa 3
