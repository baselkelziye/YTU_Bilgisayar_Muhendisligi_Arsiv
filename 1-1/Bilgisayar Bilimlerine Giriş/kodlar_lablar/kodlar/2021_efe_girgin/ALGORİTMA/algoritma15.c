#include <stdio.h>
int main(){
	int j,N,elde,i,top=0;
	printf("lutfen dizinin boyutunu giriniz:\n");
	scanf("%d",&N);
	int A[N];
	int B[N];
	int C[N+1];
	for(i=0;i<=N;i++){
	C[i]=0;
	}
	elde =0;
	printf("lutfen A dizisini giriniz:\n");
	for(i=0;i<N;i++){
		scanf("%d",&A[i]);
		
	}
	printf("lutfen B dizisini giriniz:\n");
	for(i=0;i<N;i++){
		scanf("%d",&B[i]);
	}
	j=N;
	for(i=N-1;i>=0;i--){
		
		top=A[i]+B[i]+elde;
		C[j]=top %10;
		elde=top/10;
		j--;
	}
	C[0]=elde;
	for(i=0;i<=N;i++){
	printf("%d",C[i]);
	
	}
	return 0;
}
//herbir digiti(hanesi) bir dizinin bir elemani olarak verilen 
//N digitlik iki sayi arasinda toplama islemi yaparak elde edeceginiz degeri 
//yeni bir diziye yerlestiren algoritma ve programi
//sayfa 13
//kod calisiyor
