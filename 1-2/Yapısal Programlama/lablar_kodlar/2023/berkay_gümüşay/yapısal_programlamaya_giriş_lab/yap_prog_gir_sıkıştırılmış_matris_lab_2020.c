#include <stdio.h>
#include <stdlib.h>
#define SIZE 200

int main() {
	int mtU[SIZE][SIZE]={{0}},menu=1,ch,i,j;
	int mt1[SIZE][SIZE]={{0}},mt1x,mt1y,mtA1x[SIZE]={0},mtA1y[SIZE]={0},count1=0,mtA1[SIZE]={0},mtprnt[SIZE][3]={{0}};
	
	while(menu == 1){
		printf("\tMenu :\n");
		printf("\t(1)Seyrek Matristen Sikistirilmis Matris\n");
		printf("\t(2)Sikistirilmis Matristen Seyrek Matris\n");
		printf("\t(3)Cikis\n");
		printf("\tSeciminizi Yaziniz :");
		scanf("%d",&ch);
		switch(ch){
			case 1 :{
				system("cls");
				printf("Matrisin Sutun Sayisini Giriniz:");
				scanf("%d",&mt1y);
				printf("Matrisin Satir Sayisini Giriniz:");
				scanf("%d",&mt1x);
				for(i=0;i<mt1x;i++){
					for(j=0;j<mt1y;j++){
						printf("(%d)(%d): ",i+1,j+1);
						scanf("%d",&mt1[i][j]);
					}
				}
				for(i=0;i<mt1x;i++){
					for(j=0;j<mt1y;j++){
						printf("%d ",mt1[i][j]);		
					}
					printf("\n");
				}
				printf("\n\n");
				for(i=0;i<mt1x;i++){
			 		for(j=0;j<mt1y;j++){
			 			if(mt1[i][j] != 0){
			 				mtA1[count1]=mt1[i][j];
			 				mtA1x[count1] = i;
							mtA1y[count1] = j;
				 			count1++;
						 }
			 		}
			 	}
				printf("\t***** Sikistirilmis Matris *****\n");
				for(i=0;i<count1;i++){
					printf("\t%d %d %d\n",mtA1x[i],mtA1y[i],mtA1[i]);
				}
				 	
				break;
			}
			case 2 :{
				break;
			}
			case 3 :{
				menu = 0;
				break;
			}
		}
	}
	
	return 0;
}
