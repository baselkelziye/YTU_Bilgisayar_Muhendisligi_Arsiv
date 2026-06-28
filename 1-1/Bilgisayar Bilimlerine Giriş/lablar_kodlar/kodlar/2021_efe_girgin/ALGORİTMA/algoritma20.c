#include <stdio.h>
int main(){
	int N,B,C,T,i;
	printf("lutfen dizinin boyutunu giriniz:\n");
	scanf("%d",&N);
	printf("bir sayi giriniz\n");
	scanf("%d",&B);
	int A[N];
	C=1;
	T=0;
	printf("A dizisini giriniz\n");
	for(i=0;i<N;i++){
		scanf("%d",&A[i]);
	}
	for(i=N-1;i>=1;i--){
		T=T+(A[i]*C);
		C=C*B;
		
	}
	printf("%d",T);
}
//herhangi bir düzendeki bir sayinin onluk düzene cevrilmesini saglayan algoritma ve programi
//sayfa 16
