#include <stdio.h>
int main(){ // klavyeden girilen bir sayinin asal bolenlerini ekrana yazan program
	int N, i=2, counter=0;
	do{
		printf("N ");
		scanf("%d",&N);
	}while(N<=1);
    
	while(i<=N){
		if(N % i==0){
			N/=i;
            if(counter !=i)
            {
                printf("%d ",i);
                counter = i;
            }
		}
		else
			i++;	
	}
}
