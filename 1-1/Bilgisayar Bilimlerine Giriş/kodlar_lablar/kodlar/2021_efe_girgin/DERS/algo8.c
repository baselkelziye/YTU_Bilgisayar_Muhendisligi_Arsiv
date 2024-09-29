#include <stdio.h>
#define size 100
//selection short
int main(){
	int i,j,min,tmp,n,ar[size];
	printf("please enter # of elements:");
	scanf("%d",&n);
	
	for(i=0;i<n;i++){
		printf("please enter element %d:",i);
		scanf("%d",&ar[i]);
	}
	
	
	
	for(i=0;i<n-1;i++){
		min=i;
		for(j=i+1;j<n;j++){
			if(ar[min]>ar[j]){
				min=j;
				tmp=ar[min];
				ar[min]=ar[i];
				ar[i]=tmp;
			}
		}
	}

	for(i=0;i<n;i++){
		printf("%d\t",ar[i]);
	}
	return 0;
}
//anlasýldý



