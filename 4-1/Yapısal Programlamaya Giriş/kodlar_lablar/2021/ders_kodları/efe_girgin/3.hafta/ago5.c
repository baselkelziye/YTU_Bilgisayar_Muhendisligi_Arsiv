#include <stdio.h>
int main(){
	int N,i;
	printf("lutfen N sayisini giriniz\n");
	scanf("%d",&N);
	int A[N];
	for(i=0;i<N;i++){
		scanf("%d",&A[i]);
	}
	i=0;
	while(A[i]==A[N-i-1]&& i<N/2){
		i=i+1;
	}
	if(i<N/2){
		printf("palindrom degil");
	}
	else{
		printf("palindrom");
	}
	return 0;
}
//kod calýsýyor
//sayfa 6
