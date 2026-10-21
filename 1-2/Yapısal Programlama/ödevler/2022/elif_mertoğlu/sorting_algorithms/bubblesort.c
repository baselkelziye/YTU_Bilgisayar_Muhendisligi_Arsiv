#include<stdio.h>
#include<stdlib.h>
//Bubble sort (küçükten büyüðe sýralar)
int main(){
	
	int n,i,j,temp,*dizi;
	printf("dizinin eleman sirasini giriniz.\n");
	scanf("%d",&n);
	dizi=(int*)malloc(n*sizeof(int));
	printf("dizinin elemanlarini giriniz.\n");
	for(i=0;i<n;i++){
		scanf("%d",&dizi[i]);
	}
	for(i=0;i<=n-2;i++){
		for(j=0;j<=n-2-i;j++){
			if(dizi[j]>dizi[j+1]){
				temp=dizi[j];
				dizi[j]=dizi[j+1];
				dizi[j+1]=temp;
			}
		}
	}
	for(i=0;i<n;i++){
		printf("%d	",dizi[i]);
	}	
	return 0;
}
