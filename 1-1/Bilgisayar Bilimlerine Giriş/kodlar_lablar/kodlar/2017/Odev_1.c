#include<stdio.h>
int main(){
	printf("Dizinin eleman sayisini giriniz.\n");
	int n,b,c,i;
	scanf("%d",&n);
	int dizi[2*n-1];
	printf("Dizinin sirasiyla elemanlarini veriniz.\n");
	
	for(i=1;i<=n;i++){
		scanf("%d",&dizi[i]);
		
	}
	
	for(b=0;b<(2*n-1);b++){  
		
		c=dizi[b]+dizi[b+1];
		c=2*n-1;
			
		while(c>=dizi[b+2]){
			
				for(i=b+2;b+2<=2*n-1;b+3){
					dizi[b+3]=dizi[b+4];
					/*Dizinin b�y�k olan de�erlerini b�yle 
					yaparak bir sa�a kayd�ramazm�y�m? */
				}
				c=dizi[b+2];
			}
			
			
			printf("%d\t",dizi[i++]);
		}
	for(i=0;i<(2*n-1);i++){
		
			printf("%d\t",dizi[i]);
	}
	return 0;
}	
		
			
				
		

