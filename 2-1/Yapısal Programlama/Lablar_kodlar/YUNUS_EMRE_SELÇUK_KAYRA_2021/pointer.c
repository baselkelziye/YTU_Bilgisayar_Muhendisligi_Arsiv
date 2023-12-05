#include <stdio.h>
#include <stdlib.h>
int main(){
	int *t;
	int i,n=10;
	t=(int*)calloc(100,sizeof(int));//=malloc(100*sizeof(int))
	if(t==NULL){
		printf("yer verilmedi");
	}
	srand(time(NULL));
	for(i=0;i<n;i++){
		*(t+i)=rand()%123+5;
		printf("%d\t",*(t+i));
		scanf("%d",(t+i));
	}
	*(t+5)=-5;
	printf("%d\t",*(t+1));
	free(t);
	return 0;
}
