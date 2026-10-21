#include<stdio.h>
int main(){
	
	int dizi[100],i,boyut;
	
	printf("Dizi boyutunu girin: ");
	scanf("%d",&boyut);
	
	printf("Dizi elemanlarini girin: ");
	for(i=0;i<boyut;i++){
		scanf("%d",&dizi[i]);
	}
	 i=0;	
	int x;
	int flag=1;
		while(true){
			
			if(dizi[i+1]-dizi[i]!=1){
				flag=0;
				x=dizi[i]+1;
			}
			
			i++;
			
		break;
		}
	if(flag==0){
		printf("kayip sayi var, kayip sayi: %d",x);
		
	}
	
	
	else{
		printf("kayip sayi yok");
	}
	
	return 0;
}
