#include <stdio.h>
#include <stdlib.h>
#define size 100

int main(){
	int i,j,k,Y,N,M,K,PA[size],PB[size],PC[size],A[size],B[size],C[size];
	printf("A dizisinin boyutu : ");scanf("%d",&N);
	for(i = 1; i <= N; i++){
		printf("A[%d] <-- ",i);scanf("%d",&A[i]); 
		C[i] = A[i];
	}
	printf("B dizisinin boyutu : ");scanf("%d",&M);
	for(i = 1; i <= M; i++){
		printf("B[%d] <-- ",i);scanf("%d",&B[i]);
	}
	K = N + M;
	
	PA[0] = 1;PA[1] = -1;
	for(i = 2; i <= N; i++){
		k = 0;
		j = PA[0];
		Y = A[i];
		while( (j > 0) && (Y > A[j]) ){
			k = j;
			j = PA[j];
		}
		PA[k] = i;
		PA[i] = j;
	}
	
	PB[0] = 1;PB[1] = -1;
	for(i = 2; i <= M; i++){
		k = 0;
		j = PB[0];
		Y = B[i];
		while( (j > 0) && (Y > B[j]) ){
			k = j;
			j = PB[j];
		}
		PB[k] = i;
		PB[i] = j;
	}
	for(i = 0; i<=N; i++){
		printf("%d  ",PA[i]);
		PC[i] = PA[i];
	}
	printf("<-- P[A] dizisi\n");
	for(i = 0; i<=M; i++){
		printf("%d  ",PB[i]);
	}
	printf("<-- P[B] dizisi\n");
	printf("<-- P[C] dizisinin ilk hali\n");
	int z;
	i = 0;
	j = 0;
	int imlec = 0;
	while(PA[i] != 0 && PB[j] != 0){
		if( A[PA[i]] < B[PB[j]]){
			PC[imlec] = PA[i];
			imlec = PA[i];
			i = PA[i];
			//if(PA[i] == -1)
				
		} 
		else if( (A[PA[i]] > B[PB[j]]) ){
			PC[imlec] = N + PB[j];
			imlec = N + PB[j];
			j = PB[j];
		}
		/*Y = B[i];
		k = 0; j = PC[0];
		while( (j > 0) && (Y > C[j]) ){
			k = j;
			j = PC[j];
		}
		N = N+1;
		C[N] = Y; 
		PC[k] = N;
		PC[N] = j;*/
	}
	if(PA[i] == 0){
	
	}
	else{
		
	}
	PC[imlec] = -1;
	/*for(i = 1; i<=N+M; i++){
		printf("%d  ",C[i]);
	}*/
	
	/*PC[0] = 1; PC[1] = -1;
	for(i = 2; i <= N+M; i++){
		k = 0;
		j = PC[0];
		Y = C[i];
		while( (j > 0) && (Y > C[j]) ){
			k = j;
			j = PC[j];
		}
		PC[k] = i;
		PC[i] = j;
	}*/
	
	for(i = 0; i <= K; i++){
		printf("%d  ",PC[i]);
	}
	printf("<-- istenen");
	return 0;
}
