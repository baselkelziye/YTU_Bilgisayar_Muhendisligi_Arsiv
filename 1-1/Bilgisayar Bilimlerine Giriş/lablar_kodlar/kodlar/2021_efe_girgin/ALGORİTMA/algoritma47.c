#include <stdio.h>
int main(){
	int k,N,i,j,x;
	printf("lutfen dizinin boyutunu giriniz \n");
	scanf("%d",&N);
	printf("lutfen bir sayi giriniz \n");
	scanf("%d",&x);
	int A[N];
	printf("lutfen diziyi giriniz:\n");
	for(i=0;i<N;i++){
		scanf("%d",&A[i]);
	}
	i=0;
	while(x>A[i]){
		i=i+1;
	}
	for(j=N;j>=i;j--){
		A[j+1]=A[j];
	}
	A[i]=x;
	for(i=0;i<=N;i++){
		printf("%d",A[i]);
	}
	return 0;
}
//verilen kucukten büyüge sirali bir diziye bir sayinin yerlestirilmesini saglayan algoritma ve programi
//sayfa 41
//1.soru
//kod calýsmadi
