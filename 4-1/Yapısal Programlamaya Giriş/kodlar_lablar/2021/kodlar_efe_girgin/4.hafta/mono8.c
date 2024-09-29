#include <stdio.h>
int main(){
	int V,P,i,j,max,index;
	printf("lutfen vatandas sayisi giriniz\n");
	scanf("%d",&V);
	
	printf("lutfen parti sayisini giriniz\n");
	scanf("%d",&P);
	int A[V][3];
	int B[P];
	for(i=0;i<V;i++){
		for(j=0;j<3;j++){
			scanf("%d",&A[i][j]);
			
		}
	}
	for(i=0;i<P;i++){
		B[i]=0;
	}
	for(i=0;i<V;i++){
		for(j=0;j<3;j++){
			B[A[i][j]]=B[A[i][j]]+1;
		}
	}
	
	max=B[0];
	for(i=1;i<P;i++){
		if(B[i]>max){
			max=B[i];
			index=i;
		}
	}
	printf("%d oyla %d.parti kazandi",max,index);
	

			
		
	
}
//kod calýsýyor
//sayfa 8
