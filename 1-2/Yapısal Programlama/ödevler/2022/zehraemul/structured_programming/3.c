#include<stdio.h>

int main(){
	
	
	int i,j,matris[10][10],boyut;
	
	
	int counter=0;
	
	printf("matrisin satir ve sutun degeri olcak sekilde bir sayi girin: ");
	
	scanf("%d",&boyut);
	
	for(i=0;i<boyut;i++){
		for(j=0;j<boyut;j++){
			
			printf("matrisin [%d][%d]. elemanini girin: ",i+1,j+1);
			scanf("%d",&matris[i][j]);
			
			
		}
	}
	
	
		for(i=0;i<boyut;i++){
			printf("\n");
		for(j=0;j<boyut;j++){
			
			printf("  %d ",matris[i][j]);
		
			
			
		}
	}
	
	printf("\n");
	for(i=0;i<boyut;i++){
		for(j=0;j<i;j++){
			
			if(matris[i][j]!=matris[j][i]){
				counter++;
			}
		}
	}
	
	printf("yapmaniz gereken degisiklik sayisi: %d",counter);
	
	
	return 0;
	
}








