#include <stdio.h>
int main(){
	int N,temp,i;
	printf("lutfen N sayisini giriniz\n");
	scanf("%d",&N);
	int A[N];
	
	printf("lutfen diziyi giriniz\n");
	for(i=0;i<N;i++){
		scanf("%d",&A[i]);
	}
	
	for(i=0;i<N/2;i++){
		temp=A[i];
		A[i]=A[N-i-1];
		A[N-i-1]=temp;
	}
	for(i=0;i<N;i++){
		printf("%d",A[i]);
	}
	return 0;
}
//kod calýsýyor
//sayfa 5
