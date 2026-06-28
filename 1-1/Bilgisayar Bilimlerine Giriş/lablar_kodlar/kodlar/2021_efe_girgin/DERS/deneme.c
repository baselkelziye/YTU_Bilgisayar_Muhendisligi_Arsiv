#include <stdio.h>
#define size 100
int main(){
	int A[size],N,start,end,tmp,i;
	do{
		printf("lutfen dizinin boyutunu giriniz\n ");
		scanf("%d",&N);
	}while(N>size);
	
	printf("dizinin elemanlarini giriniz=\n");
	for(i=0;i<N;i++){
		scanf("%d",&A[i]);
	}
	start=0;
	end=N-1;
	
	while(start<end){
		tmp=A[start];
		A[start]=A[end];
		A[end]=tmp;
		
		start++;
		end--;
	}
	printf("sonuc dizimiz\n");
	for(i=0;i<N;i++){
		printf("%d",A[i]);
	}
	return 0;
	}

