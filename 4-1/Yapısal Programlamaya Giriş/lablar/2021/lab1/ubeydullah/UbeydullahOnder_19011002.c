#include<stdio.h>


int main(){
	int a,dizi[100],i,k,orta,b;
	printf("Dizi kac elemanlý?\n");
	scanf("%d",&a);
	printf("Dizi Elemanlarýný giriniz...\n");
	for(i=0;i<a;i++){
		scanf("%d",&dizi[i]);
}
	b=a-1;
	k=0;
	orta=(b+k)/2;
	if(dizi[0]+a-1 != dizi[a]){
	
		while(k<=b){
			orta=(b+k)/2;
			if (dizi[orta] < dizi[k]+orta-k){
			
            k = orta + 1;
}
        	else{
			
            b =orta - 1;
		}
			}
		
		printf("bulunmayan sayi= %d ",dizi[orta-1]+1);
		
	
	
		}
	else{
		printf("girdiginiz sayilarda bulunmayan sayi yok!");
	}
	
	
	
	
	
	
	return 0;
}
