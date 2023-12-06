#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int* f(int N);
int main(){
    int N,i;
    printf("N degeri");
    scanf("%d",&N);
    int *p=f(N);
    for(i=0;i<N;i++){
    	printf("%d ",p[i]);
	}
    
    free(p);
    return 0;
}
int* f(int N){	
    int i,*dizi;// = (int*) malloc(N*sizeof(int));
    dizi = (int*) calloc(N,sizeof(int));
    for(i=0;i<N;i++){
    	//dizi[i]=0;
    	//*(dizi+i)=1;
	}
    return dizi;
}
