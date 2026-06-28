#include <stdio.h>
int main(){
	
	int N,i,e,s;
	printf("lutfen dizinin boyutunu giriniz\n");
	scanf("%d",&N);
	
	int A[N];
	int B[N];
	int C[N];
	
	printf("lutfen A dizisini giriniz\n");
	
	for(i=0;i<N;i++){
		scanf("%d",&A[i]);
	}
	printf("lutfen B dizisini giriniz\n");
	for(i=0;i<N;i++){
		scanf("%d",&B[i]);
	}
	e=0;
	
	
	for(i=N;i>0;i--){
		s=A[i]-e;
		if(s>=B[i]){
			C[i]=s-B[i];
			e=0;
		}
		else{
			C[i]=s-B[i]+10;
			e=1;
		}
	}
	for(i=0;i<N;i++){
		printf("%d\t",C[i]);
	}
	return 0;
}
//iki sayinin farkini bulan algoritma ve programi
//sayfa 41
//2.soru
//kod calýsmýyor
