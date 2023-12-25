#include <stdio.h>
//#include <stdlib.h>
//#include <time.h>

int main() {
	//srand(time(NULL));
	int N;
	printf("Dizi boyutu : ");scanf("%d",&N);
	
	int A[N],B[N];
	for(int i = 0; i < N; i++){
		printf("%d. elemani giriniz : ",i+1);scanf("%d",&A[i]);
		//A[i] = rand() % 10+1;
	}
	
	int MAX = A[0];
	for(int i = 1; i < N; i++){
		if(A[i] > MAX){
			MAX = A[i];
		}
	}
	//Counter dizisi sýfýrlanýyor...
	int C[MAX];
	for(int i = 0; i < MAX; i++){
		C[i] = 0;
	}
	//A dizisinin en büyük elemaný kadar boyutu olan C dizisi saymaya baþlýyor...
	for(int i = 0; i < N; i++){
		C[A[i]] = C[A[i]] + 1;
	}
	
	/*for(int j=0; j<N; j++){
      B[C[A[j]]]=A[j];
      
    }*/
    
    for(int i=1; i<MAX; i++){
      C[i]=C[i]+C[i-1];
	}
    
   
    for(int j=0; j < N; j++){
      B[C[A[j]]]=A[j];
      C[A[j]]=C[A[j]]-1;
    }
    
	//YAZHANE
	for(int i = 0; i < N; i++){
		printf("%d |", A[i]);
	}
	printf("\n");
	for(int i = 0; i < MAX; i++){
		printf("%d |", C[i]);
	}
	printf("\n");
	for(int i = 0; i < N; i++){
		printf("%d |", B[i]);
	}


	return 0;
}
