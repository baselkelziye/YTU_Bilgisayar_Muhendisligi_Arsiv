#include<stdio.h>
#include<stdlib.h>
int* array_allocate(int N);
void print_array(int *dizi, int M);

int main(){
	int *dizi;
	int N;
	scanf("%d",&N);
	dizi=array_allocate(N);
	print_array(dizi,N);
	free(dizi);
}

int* array_allocate(int N){
	int *t;
	t=(int*) malloc(N*sizeof(int));
	if(t==NULL){
		return 0;
	}else{
		return t;
	}	
	
}

void print_array(int *dizi, int M){
	int i=0;
	for(i=0;i<M;i++){
		printf("%d \n",dizi[i]);
	}
}

