#include <stdio.h>
int main(){
	int N,i,j,k,l,r,nn;
	printf("lutfen dizinin boyutunu giriniz \n");
	scanf("%d",&N);
	nn=N-1;
	int A[N];
	int C[N];
	for(i=0;i<N;i++){
		scanf("%d",&A[i]);
	}
	for(i=0;i<N;i++){
		k=A[i]%10;
		l=A[i]/10;
		r=(k*10)+l;
		C[nn-i]=r;
	}
	for(j=0;j<N;j++){
		printf("%d\n",C[j]);
	}
	
}
//deneme ve compile yapildi
//47-29-34-11 dizisinden 11-43-92-74 dizisini elde eden algoritma ve programi
//sayfa 15
//kod calýsýyor
