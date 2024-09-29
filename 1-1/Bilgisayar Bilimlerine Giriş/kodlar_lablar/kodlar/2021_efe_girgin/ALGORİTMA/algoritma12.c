#include <stdio.h>
int main(){
	
	int N,byk1,byk2,i;
	printf("dizinin eleman sayisini giriniz\n");
	scanf("%d",&N);
	int A[N];

	for(i=0;i<N;i++){
		scanf("%d",&A[i]);
	}
		
	if(A[0]>A[1]){
		byk1=A[0];
		byk2=A[1];
	}
	else{
		byk1=A[1];
		byk2=A[0];
	}
	
	for(i=2;i<N;i++){
		if(A[i]>byk2){
				
			if(A[i]>byk1){
				byk2=byk1;
				byk1=A[i];
			}
			else {
				byk2=A[i];
			}	
		}	
	}
	printf("%d",byk2);
	return 0;
}


//deneme ve compile yapildi
//bir dizinin ikinci buyuk elemanini bulan algoritma ve programi.
//sayfa 11
//kod calýsýyor
