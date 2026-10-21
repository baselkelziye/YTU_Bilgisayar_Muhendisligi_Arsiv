#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
typedef struct arac{
	char *model;
	int yil;
	int fiyat;
	int adet;
	
}Arac;
Arac *aracYarat(char *model,int yil,int fiyat,int adet){
	Arac *yeniArac = (Arac*)malloc(1*sizeof(Arac));
	yeniArac->model = (char*)calloc(30, sizeof(char));
	strcpy(yeniArac->model,model);
	yeniArac->yil = yil;
	yeniArac->fiyat = fiyat;
	yeniArac->adet = adet;
	return yeniArac;
}
void aracEkle(Arac*** database,int *aracCount,int *databaseCount,Arac* yeniArac){
	(*database)[(*aracCount)++] = yeniArac;
	if((*aracCount) == (*databaseCount)){
		(*databaseCount)*=2;
		(*database) = (Arac**)realloc((*database),(*databaseCount)*sizeof(Arac));
	}
	
}
void aracBastanYazdir(Arac** database,int aracCount){
	int i;
	for(i=0;i<aracCount;i++){
		printf("\nModel: %s\nYil: %d\nFiyat: %d\nAdet: %d\n--------------------------\n",database[i]->model,database[i]->yil,database[i]->fiyat,database[i]->adet);
	}
}
void aracSondanYazdir(Arac** database,int aracCount){
	int i;
	for(i=aracCount-1;i>=0;i--){
		printf("\nModel: %s\nYil: %d\nFiyat: %d\nAdet: %d\n--------------------------\n",database[i]->model,database[i]->yil,database[i]->fiyat,database[i]->adet);
	}
}
void bubbleSort(Arac** database,int aracCount){
	int i,j;
	Arac tmp;
	for(i=0;i<aracCount-1;i++){
		for(j=0;j<aracCount-1-i;j++){
			if(strcmp(database[j]->model,database[j+1]->model) > 0){
				tmp = *database[j];
				*database[j] = *database[j+1];
				*database[j+1] = tmp;
			}
		}
	}
}
void freeArac(Arac *arac){
	free(arac->model);
	free(arac);
}
void freeDB(Arac **database,int databaseCount,int aracCount){
	int i;
	for(i=0;i<aracCount;i++){
		freeArac(database[i]);
	}
	for(i=aracCount;i<databaseCount;i++){
		free(database[i]);
	}
	free(database);
}
int main() {
	int exit = 0;
	int menu;
	int menu2;
	char model[50];
	int yil, fiyat, adet;
	Arac *yeniArac;
	int aracCount=0,databaseCount=1;
	Arac **database;
	database = (Arac**)malloc(databaseCount*sizeof(Arac*));	
	while(exit == 0){
		printf("1. Arac Ekle\n2. Arac Listesi\n3. Cikis\nSecim: ");
		scanf("%d",&menu);
		switch(menu){
			case 1:{	
				printf("Arac Ismi: ");
				scanf("%s",model);
				printf("Arac Yili: ");
				scanf("%d",&yil);
				printf("Arac Fiyati: ");
				scanf("%d",&fiyat);
				printf("Arac Adedi: ");
				scanf("%d",&adet);
				yeniArac = aracYarat(model,yil,fiyat,adet);
				aracEkle(&database,&aracCount,&databaseCount,yeniArac);
				break;
			}
			case 2:{
				bubbleSort(database,aracCount);
				printf("1. Bastan Sona\n2. Sondan Basa\nSecim: ");
				scanf("%d",&menu2);
				switch(menu2){
					case 1:{
						aracBastanYazdir(database,aracCount);
						break;
					}
					case 2:{
						aracSondanYazdir(database,aracCount);
						break;
					}
				}				
				break;
			}
			case 3:{
				exit = 1;
				break;
			}
		}
	}
	
	return 0;
}
