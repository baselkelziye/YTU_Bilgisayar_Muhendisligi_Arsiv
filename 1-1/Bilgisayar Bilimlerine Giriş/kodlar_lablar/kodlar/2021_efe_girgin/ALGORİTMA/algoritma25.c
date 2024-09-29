#include <stdio.h>
int main(){
	int k,N,byk,j,i,say;
	printf("lutfen dizinin boyutunu giriniz\n");
	scanf("%d",&N);
	
	int A[N];
	
	int B[N];
	
	j=N-1;
	say=0;
	k=0;
	
	for(i=0;i<N;i++){
		scanf("%d",&A[i]);
	}
	byk=A[0];
	for(i=1;i<N;i++){
		if(A[i]>byk){
			B[k]=A[i];
			k=k+1;
			say=say+1;
		}
		else if(A[i]<byk){
			B[j]=A[i];
			j=j-1;
		}
	}
	B[say]=byk;
	printf("\nbyk=%d\n",byk);
	for(i=0;i<N;i++){
		printf("%d\n",B[i]);
		
	}
}
//kod calýsýyor
//bir dizinin ilk gözündeki elemani büyük kabul ederek,ondan büyük olanlari yeni bir dizinin basýndan,kücük olanlari sonundan itibaren yerlestiren algoritma ve programi.
//sayfa 19
//2.soru

