#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 200
int main() {
	int i,j,k,x=0,y=0;
	int map[SIZE][SIZE]={{2}},mapSizeX,mapSizeY;
	int point;
	int count1=0,count2=0;
	int dir;
	int path[SIZE]={0};
	
	srand(time(NULL));
	
	
	printf("Matrisin Satir Sayisini Giriniz: ");
	scanf("%d",&mapSizeX);
	printf("Matrisin Sutun Sayisini Giriniz : ");
	scanf("%d",&mapSizeY);
	printf("0 veya 1 giriniz\n\n");
	for(i=0;i<mapSizeX;i++){
		for(j=0;j<mapSizeY;j++){
			printf("(%d)(%d) = ",i+1,j+1);
			scanf("%d",&map[i][j]);
		}
	}
	printf("\n---- Mevcut Harita ----\n");
	for(i=0;i<mapSizeX;i++){
		for(j=0;j<mapSizeY;j++){
			printf("%d ",map[i][j]); // KONTROL BÖLGESÝ
		}
		printf("\n");
	}
	printf("\n\n");
	point = map[x][y];
	while(count2 == 0){
		if((map[x+1][y] == 1) || (map[x][y+1] == 1)){
			if((map[x+1][y] == 1) && (map[x][y+1] == 1)){  //  HEM AÞÝAÐIDA HEM SAÐDA 1 VARSA RASTGELE KARAR VERME
				dir = rand();
				if(dir % 2 == 0){
					path[count1] = 1;
					y++; 				//  HEM AÞÝAÐIDA HEM SAÐDA 1 VARSA RASTGELE KARAR VERME
					count1++;
				} 
				else{
					path[count1] = 2;	
					x++;					//  HEM AÞÝAÐIDA HEM SAÐDA 1 VARSA RASTGELE KARAR VERME
					count1++;
					
				}
			}
			else {
				if(map[x+1][y] == 1){
					path[count1] = 2;			// SAÐA GÝTME
					x++;
					count1++;
				}
				else if(map[x][y+1] == 1){		//AÞAÐI GÝTME
					path[count1] = 1;
					y++;
					count1++;
				}
			}		
		}
		else{
			count2 = 1;
		}
	}
	if(count1 == 0){
		printf("!! Bu Haritada Rota Bulunmamaktadir !!");
	}
	else{
		k=0;
		printf("Mevcut Rota =  ");
		while(path[k] != 0){
			printf("%d\t",path[k]);
			k++;
		}
	}
	
	return 0;
}
