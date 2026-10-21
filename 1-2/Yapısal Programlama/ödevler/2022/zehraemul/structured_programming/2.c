#include<stdio.h>

int main(){
	
	int i,boyut,dizi[20];
	
	printf("dizi boyutu girin: ");
	scanf("%d",&boyut);
	
	printf("dizi elemanlarini girin:");
	for(i=0;i<boyut;i++){
		
		scanf("%d",&dizi[i]);
		
	}
	int tmp;
	for(i=0;i<boyut/2;i++){
		
		tmp=dizi[i];
		dizi[i]=dizi[boyut-i-1];
		dizi[boyut-i-1]=tmp;
		
	}
	
		for(i=0;i<boyut;i++){
		
		printf("%d ",dizi[i]);
		
	}
	
	return 0;
}
