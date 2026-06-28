#include <stdio.h>
#include <conio.h>


int main() {
	
	int N;
	printf("Dizinin eleman sayisi : ");scanf("%d",&N);int A[N];
	for(int i = 0; i <= N-1; i++){
		scanf("%d",&A[i]);
	}
	for(int i = 0; i <= N-1; i++){
		printf("%d ",A[i]);
	}
	for(int i = 0; i < N/2; i++){
		int tmp = A[i];
		A[i] = A[N-i-1];
		A[N-i-1] = tmp;
	}
	for(int i = 0; i < N; i++){
		printf("%d ",A[i]);
	}
	
	
	
	
	
	getch();
	return 0;
}
