#include <stdio.h>
int main(){
	int N,T,i,tmp;
	printf("lutfen dizinin boyutunu giriniz\n");
	scanf("%d",&N);
	
	int A[N];
	T=N/2;
	for(i=0;i<N;i++){
		scanf("%d",&A[i]);
	}
	
	for(i=0;i<T;i++){
		tmp=A[i];
		A[i]=A[N-1-i];
		A[N-1-i]=tmp;
	}
	for(i=0;i<N;i++){
		printf("%d",A[i]);
	}
	return 0;
}
//kod calýsti
//bir dizide dizi elemanlarinin sondan basa gelecek sekilde düzenlenmesini saglayan algoritma ve programi
//sayfa 15
