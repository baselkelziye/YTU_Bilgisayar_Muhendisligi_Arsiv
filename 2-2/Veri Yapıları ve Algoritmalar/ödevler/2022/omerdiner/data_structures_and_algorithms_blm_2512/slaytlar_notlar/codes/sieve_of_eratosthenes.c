#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(int argc, char* argv[]) {
	int i,j;
	int N=atoi(argv[1]);
	int* arr=(int*)calloc(N+1,sizeof(int));
	for(arr[1]=0, i=2; i<=N; i++) {
		
		arr[i]=1;
		
	}
	
	for(i=2; i<=N/2; i++) {
		for(j=2; j<=N/i; j++) {
			arr[i*j]=0;
		}
	} 
	for(i=1; i<=N; i++) {
		if(arr[i]) {
			printf("%4d\n",i);
		}
	}
	return 0;
}
