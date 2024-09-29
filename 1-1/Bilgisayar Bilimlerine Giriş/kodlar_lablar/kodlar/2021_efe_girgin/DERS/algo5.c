#include <stdio.h>
#define size 100
//kucukten buyuge siralanmis iki diziyi siralanmis tek diziye aktarma

int main(void){
	int i,j,k;
	int N,M;
	
	printf("please enter # of elements for array a:");
	scanf("%d",&N);
	
	int a[N];
	
	for(i=0;i<N;i++){
		printf("please enter %d. element:",i+1);
		scanf("%d",&a[i]);
	}
	printf("please enter # of elements for array b:");
	scanf("%d",&M);
	
	int b[M],c[N+M];
	
	for(i=0;i<M;i++){
		printf("please enter %d.element:",i+1);
		scanf("%d",&b[i]);
	}
	i=0;
	j=0;
	k=0;
	while(i<N && j<M){
		if(a[i]<b[j]){
			c[k]=a[i];
			i++;
		}
		else{
			c[k]=b[j];
			j++;
		}
		k++;
	}
	if(i==N){
		for(i=j;i<M;i++){
			c[k]=b[i];
			k++;
		}
	}
	else{
		for(j=i;j<N;j++){
			c[k]=a[j];
			k++;
		}
	}
	for(i=0;i<N+M;i++){
		printf("%d\t",c[i]);
		printf("\n");
	}
	return 0;
}
//anlasýldý 
//deneme ve compile yapildi
