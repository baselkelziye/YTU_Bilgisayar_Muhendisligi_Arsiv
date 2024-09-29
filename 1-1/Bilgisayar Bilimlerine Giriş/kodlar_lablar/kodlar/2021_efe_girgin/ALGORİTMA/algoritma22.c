#include <stdio.h>
int main(){
	int N,i,k,s,j;
	printf("lutfen dizinin boyutunu giriniz:\n");
	scanf("%d",&N);
	
	int A[N];
	for(i=0;i<N;i++){
		scanf("%d",&A[i]);
	}
	for(i=0;i<N-1;i++){
		k=i;
		s=A[i];
		for(j=i+1;j<N;j++){
			if(A[j]>s){
				s=A[j];
				k=j;
			}
			s=A[k];
			A[k]=A[i];
			A[i]=s;	
		
		}
	}
	
	for(i=0;i<N;i++){
		printf("dizimiz:%d\n",A[i]);
	}
	return 0;
	}



//dizi elemanlarinin büyükten kucuge sýralanmasini saglayan algoritma ve programi(selection short)
//sayfa 17
//kod calýsýyor

