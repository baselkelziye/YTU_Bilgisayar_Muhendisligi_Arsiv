#include<stdio.h>
#include<stdlib.h>

int main(){
	int N,i;
	int *dizi, *tmp;
	printf("Enter N");
	scanf("%d",&N);
	tmp=dizi = (int*) calloc(N,sizeof(int));
	if(dizi!=NULL){
		printf("Array allocated\n");
	
	for(i=0;i<N;i++){
		printf("Enter %dth value",i);
		//scanf("%d",(dizi+i));
		//scanf("%d",&dizi[i]);
		scanf("%d",tmp); tmp++;
		tmp++;
	}
	for(i=0;i<N;i++){
		printf("%dth value=%d\n",i,*(dizi+i));
	}
	
	free(dizi);	
	return 0;
	}else{
		printf("Array not allocated");
		return -1;
	}
	
}
