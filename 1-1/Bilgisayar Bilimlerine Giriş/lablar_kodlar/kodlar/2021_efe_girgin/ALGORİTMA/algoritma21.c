#include <stdio.h>
int main(){
	int N,b,m,i,j;
	
	printf("lutfen dizinin boyutunu giriniz\n");
	scanf("%d",&N);
	
	printf("lutfen bir sayi giriniz\n");
	scanf("%d",&b);
	
	int A[N];
	
	for(i=0;i<N;i++){
		scanf("%d",&A[i]);
	}
	
	i=1;
	
	while(N>=b){
		m=N%b;
		N=N/6;
		A[i]=m;
		i=i+1;
	}
	A[i]=N;
	
	for(j=i;i>=1;i--){
		printf("%d",A[j]);
	}
	return 0;
}
//onluk düzendeki sayiyi herhangi bir duzene ceviren algoritma ve programi
//sayfa 16
//2.soru
