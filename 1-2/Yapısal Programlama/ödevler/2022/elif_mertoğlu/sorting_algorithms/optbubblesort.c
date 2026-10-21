#include<stdio.h>
#include<stdlib.h>
//optimized bubble sort (küçükten büyüðe sýralar)
int main(){
	
	int n,*dizi,i,temp,j,xchg;
	printf("dizinin eleman sayisini giriniz.\n");
	scanf("%d",&n);
	dizi=(int*)malloc(n*sizeof(int));
	printf("dizinin elemanlarini giriniz.\n");
	for(i=0;i<n;i++){
		scanf("%d",&dizi[i]);
	}
	
	xchg=1;
	i=0;
	
	while(i<n-1 && xchg==1){
		xchg=0;
		for(j=0;j<=n-2-i;j++){
			printf("x\n");
			if(dizi[j]>dizi[j+1]){
				temp=dizi[j];
				dizi[j]=dizi[j+1];
				dizi[j+1]=temp;		
			}
		}
		i=i+1;
	}
	
	for(i=0;i<n;i++){
		printf("%d	",dizi[i]);
	}
	
	return 0;
}
