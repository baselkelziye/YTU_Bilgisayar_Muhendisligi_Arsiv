#include <stdio.h>
int main(){
	int N,s,k,i;
	printf("lutfen dizinin boyutunu giriniz \n");
	scanf("%d",&N);
	
	int A[N];
	
	
	s=N;
	for(k=1;k<N/2+1;k++){
		A[k-1]=2*k-1;
		
		A[s-k]=2*k;
			
	}
	A[N/2]=N;
	
	
	for(k=0;k<N;k++){
		printf("%d\t",A[k]);
	}
	return 0;
}
//deneme ve compile yapildi
//verilen bir N sayisina göre 1 3 5 7.....N.....6 4 2 dizisini olusturan algoritma ve programi
//sayfa 39
//2.soru
//kod calýsiyor
