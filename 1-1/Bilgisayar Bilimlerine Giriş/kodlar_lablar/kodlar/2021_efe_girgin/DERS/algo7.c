#include <stdio.h>
#define size 100
//bubble short

int main(void){
	//eleman saysisi okunacak
	
	int i,n,tmp,swapped=1,ar[size];
	printf("please enter size of array:\n");
	scanf("%d",&n);
	
	
	//diziyi okunacak
	for(i=0;i<n;i++){
		printf("please enter %d eleman \n",i+1);
		scanf("%d",&ar[i]);
	}
	while(swapped==1){
		swapped=0;
		for(i=0;i<n-1;i++){
			if(ar[i]>ar[i+1]){
				tmp=ar[i];
				ar[i]=ar[i+1];
				ar[i+1]=tmp;
				swapped=1;
			}
		}
	}
	for(i=0;i<n;i++){
		printf("%d\t",ar[i]);
	}
	printf("\n");
	return 0;
}
//anlasýldý
//deneme yapildi ve compile yapildi
