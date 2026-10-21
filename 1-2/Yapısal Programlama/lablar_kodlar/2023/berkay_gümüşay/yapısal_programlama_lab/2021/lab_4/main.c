#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct data{
	int ucusNo;
	char kalkis[40];
	char inis[40];
	char saat[40];
	int hatTuru;
	int pistNo;
}Data;
typedef struct ucus{
	Data *data;
	struct ucus *next;
}Ucus;
int yeniUcusEkle(Ucus **tmp){
	Ucus *ucus;
	Data *d;
	ucus = (Ucus*)malloc(sizeof(Ucus));
	d = (Data*)malloc(sizeof(Data));
	if((ucus == NULL) || (d == NULL)){
		return -1;
	}
	ucus->data = d;
	printf("Ucus No: ");
	scanf("%d",&ucus->data->ucusNo);
	printf("Kalkis Sehri: ");
	scanf("%s",ucus->data->kalkis);
	printf("Inis Sehri:");
	scanf("%s",ucus->data->inis);
	printf("Saat: ");
	scanf("%s",ucus->data->saat);
	printf("Hat Tipi: ");
	scanf("%d",&ucus->data->hatTuru);
	printf("Pist Numarasý: ");
	scanf("%d",&ucus->data->pistNo);
	ucus->next = *tmp;
	*tmp = ucus;
	return 0;
}
void dosyadanUcuslariAl(Ucus **tmp){
	FILE *file;
	char line[5000];
	int ucusNo;
	char kalkis[40];
	char inis[40];
	char saat[40];
	int hatTuru;
	int pistNo;
	Ucus *ucus;
	Data *d;
	file = fopen("Ucuslar.txt","r");
	
	if((ucus == NULL) || (d == NULL)){
		return;
	}
	while(fgets (line, sizeof(line), file) != NULL){
		sscanf (line, "%d %s %s %s %d %d",&ucusNo,kalkis,inis,saat,&hatTuru,&pistNo);
		ucus = (Ucus*)malloc(sizeof(Ucus));
		d = (Data*)malloc(sizeof(Data));
		ucus->data = d;
		ucus->data->ucusNo = ucusNo;
		strcpy(ucus->data->kalkis,kalkis);
		strcpy(ucus->data->inis,inis);
		strcpy(ucus->data->saat,saat);
		ucus->data->hatTuru = hatTuru;
		ucus->data->pistNo = pistNo;
		ucus->prev = *tmp;
		*tmp = ucus;
	}
}
void ucusYazdir(Ucus *head,int count){
	Ucus *tmp = head;
	int i;
	for(i=0;i<count;i++){
		printf("\n| %d | %s | %s | %s | %d | %d |\n\n",tmp->data->ucusNo,tmp->data->kalkis,tmp->data->inis,tmp->data->saat,tmp->data->hatTuru,tmp->data->pistNo);
		tmp = tmp->next;
	}
}
void swap(Ucus *u1,Ucus *u2){
	Data *tmp = u1->data;
	u1->data = u2->data;
	u2->data = tmp;

}
void bubbleSort(Ucus **head,int count){
	int i,j,swapped;
	Ucus* tmp;
	for(i=0;i<=count;i++){
		tmp = *head;
		swapped = 0;
		for(j=0;j<count-i-1;j++){
			Ucus *u1 = tmp;
			Ucus *u2 = tmp->next;
			if((u2->data->ucusNo) > (u1->data->ucusNo)){
				swap(u1,u2);
				swapped = 1;
			}
			tmp = tmp->next;
		}
		if(swapped = 0){
			return;
		}
	}
}
int main(int argc, char *argv[]) {
	FILE *file;
	char line[5000];
	Data *fileData;
	int secim,res,run=1,count=4;
	Ucus *tmp = NULL;
	dosyadanUcuslariAl(&tmp);
	while(run = 1){
		printf("1 - Ekle\n2 - Listele\n3 - Cikis\nSecim: ");
		scanf("%d",&secim);
		switch(secim){
			case(1):{
				res = yeniUcusEkle(&tmp);
				if(res == 0){
					count++;
				}
				break;
			}
			case(2):{
			//	bubbleSort(&tmp,count);
				ucusYazdir(tmp,count);
				break;
			}
			case(3):{
				
				break;
			}
		}	
	}
	return 0;
}
