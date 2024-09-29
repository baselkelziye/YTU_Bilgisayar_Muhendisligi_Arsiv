#include <stdio.h>
int main(){
	int N,bir=0,i;
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
	}
	printf("%d tane bir:%d tane 2 vardir ",bir,N-bir);
	return 0;
}
//kod calýsýyor
//sayfa 4
