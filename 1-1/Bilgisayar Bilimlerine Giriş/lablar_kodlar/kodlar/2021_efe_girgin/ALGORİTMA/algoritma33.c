#include <stdio.h>
int main(){
	int N,i;
	printf("lutfen dizinin boyutunu giriniz \n");
	scanf("%d",&N);
	
	int A[N];
	int B[N];
	int C[N];
	printf("A dizisini giriniz\n");
	for(i=0;i<N;i++){
		scanf("%d",&A[i]);
	}
	printf("B dizisini giriniz\n");
	for(i=0;i<N;i++){
		scanf("%d",&B[i]);
	}
	for(i=0;i<N;i++){
		C[i]=(float)((A[i]+B[i]+1)/2);
	}
	printf("C dizimiz:\n");
	for(i=0;i<N;i++){
		printf("%d\n",C[i]);
	}
	return 0;
}
//kod calýsýyor
//0 ve 1 lerden olusan diziler veriliyor c dizisi,a veya b den en az birinin 1 oldugu yerde 1 oluyor.c dizisini veren algoritma ve program.
//sayfa 25
//1.soru
 
 
