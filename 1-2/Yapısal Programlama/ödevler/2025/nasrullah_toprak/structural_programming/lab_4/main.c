#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct kargo{
	int id;
	char isim[20];
	char sehir[10];
	char gun[10];
	char durumu[20];
	struct kargo *next;
}KARGO;

KARGO* openfile(KARGO **head);
void kargolarsirala(KARGO **head);
void ekranayazdir(KARGO * head);
void raporolustur(KARGO *head);
void bekleyenler(KARGO *head);
void isimler(KARGO *head);

int main(){
	KARGO *head=NULL;

	head=openfile(&head);
	kargolarsirala(&head);
	printf(" kargolar: \n");
	ekranayazdir(head);
	raporolustur(head);
	bekleyenler(head);
	isimler(head);
	
	return 0;
}

KARGO* openfile(KARGO **head){
	FILE *file;
	KARGO *newnode, *temp;
	char line[100];
	char *token;
	int id;
	char isim[20], sehir[20], gun[20], durumu[20];

	file=fopen("kargolar.txt","r");
	if(file==NULL){
		printf("Dosya acilmadi\n");
		return NULL;
	}

	*head=NULL;

	while(fgets(line, 100, file)!=NULL){
		line[strcspn(line, "\n")]='\0';

		token=strtok(line, " ");
		if(token!=NULL){
			id=atoi(token);
		}

		token=strtok(NULL, " ");
		if(token!=NULL){
			strcpy(isim, token);
		}

		token=strtok(NULL, " ");
		if(token!=NULL){
			strcpy(sehir, token);
		}

		token=strtok(NULL, " ");
		if(token!=NULL) strcpy(gun, token);

		token=strtok(NULL, " ");
		if(token!=NULL){
			strcpy(durumu, token);
		} 

		newnode=(KARGO*)malloc(sizeof(KARGO));
		if(newnode==NULL){
			printf("bellek yetersiz  \n");
			fclose(file);
			return *head;
		}

		newnode->id=id;
		strcpy(newnode->isim, isim);
		strcpy(newnode->sehir, sehir);
		strcpy(newnode->gun, gun);
		strcpy(newnode->durumu, durumu);
		newnode->next=NULL;

		if(*head==NULL){
			*head=newnode;
		}else{
			temp=*head;
			while(temp->next!=NULL){
				temp=temp->next;
			}
			temp->next=newnode;
		}
	}
	fclose(file);
	return *head;
}

void kargolarsirala(KARGO **head){
	KARGO *i, *j, *min;
	int tempId;
	char tempisim[20], tempsehir[10], tempgun[10], tempdurum[20];

	for(i=*head;i!=NULL;i=i->next){
		min=i;
		for(j=i->next;j!=NULL;j=j->next){
			if(j->id < min->id){
				min=j;
			}
		}
		if(min!=i){
			tempId=i->id;
			i->id=min->id;
			min->id=tempId;

			strcpy(tempisim,i->isim);
			strcpy(i->isim,min->isim);
			strcpy(min->isim,tempisim);

			strcpy(tempsehir,i->sehir);
			strcpy(i->sehir,min->sehir);
			strcpy(min->sehir,tempsehir);

			strcpy(tempgun,i->gun);
			strcpy(i->gun,min->gun);
			strcpy(min->gun,tempgun);

			strcpy(tempdurum,i->durumu);
			strcpy(i->durumu,min->durumu);
			strcpy(min->durumu,tempdurum);
		}
	}
}

void ekranayazdir(KARGO * head){
	KARGO *temp=head;
	while(temp!=NULL){
		printf("%d %s %s %s %s  \n",temp->id,temp->isim,temp->sehir,temp->gun,temp->durumu);
		temp=temp->next;
	}
}

void raporolustur(KARGO *head){
	KARGO *temp1, *temp2;
	char sehirler[100][20];
	int teslimEdildiSayilari[100]={0};
	int beklemedeSayilari[100]={0};
	int sehirSayisi=0;
	int i, bulundu, flag;

	temp1=head;
	while(temp1!=NULL){
		bulundu=0;
		i=0;
		flag=0;
		while(flag==0 && i<sehirSayisi){
			if(strcmp(sehirler[i], temp1->sehir)==0){
				bulundu=1;
				flag=1;
			}
			i++;
		}
		if(bulundu==0){
			strcpy(sehirler[sehirSayisi], temp1->sehir);
			sehirSayisi++;
		}
		temp1=temp1->next;
	}

	for(i=0;i<sehirSayisi;i++){
		temp2=head;
		while(temp2!=NULL){
			if(strcmp(sehirler[i], temp2->sehir)==0){
				if(strcmp(temp2->durumu, "TeslimEdildi")==0){
					teslimEdildiSayilari[i]++;
				}else if(strcmp(temp2->durumu, "Beklemede")==0){
					beklemedeSayilari[i]++;
				}
			}
			temp2=temp2->next;
		}
	}

	FILE *rapor=fopen("rapor.txt", "w");
	if(rapor==NULL){
		printf("rapor.txt dosyasi olusturulamadi.\n");
		return;
	}
	for(i=0;i<sehirSayisi;i++){
		fprintf(rapor, "%s -> TeslimEdildi: %d, Beklemede: %d\n",
			sehirler[i], teslimEdildiSayilari[i], beklemedeSayilari[i]);
	}
	fclose(rapor);
}

void bekleyenler(KARGO *head){
	FILE *file = fopen("bekleyenler.txt", "w");
	if(file==NULL){
		printf("bekleyenler.txt dosyasi olusturulamadi.\n");
		return;
	}
	KARGO *temp = head;
	while(temp!=NULL){
		if(strcmp(temp->durumu, "Beklemede")==0){
			fprintf(file, "%d %s %s %s %s\n", temp->id, temp->isim, temp->sehir, temp->gun, temp->durumu);
		}
		temp = temp->next;
	}
	fclose(file);
}

void isimler(KARGO *head){
	KARGO *temp;
	char isimler[20][20];
	int isimSayisi=0,i, bulundu, flag=0;
	FILE *file;
	char dosyaAdi[30];

	temp=head;
	while(temp!=NULL){
		bulundu=0;
		i=0;
		flag=0;
		while(flag==0 && i<isimSayisi){
			if(strcmp(isimler[i], temp->isim)==0){
				bulundu=1;
				flag=1;
			}
			i++;
		}
		if(bulundu==0){
			strcpy(isimler[isimSayisi], temp->isim);
			isimSayisi++;
		}
		temp=temp->next;
	}

	for(i=0;i<isimSayisi;i++){
		strcpy(dosyaAdi, isimler[i]);
		strcat(dosyaAdi,".txt");

		file=fopen(dosyaAdi,"w");
		if(file==NULL){
			printf("%s dosyasi olusturulamadi.\n", dosyaAdi);
			exit(-1);
		}
		temp=head;
		while(temp!=NULL){
			if(strcmp(temp->isim, isimler[i])==0){
				fprintf(file, "%s adli gondericiye %d no'lu kargo,\n", isimler[i], temp->id);
				fprintf(file, "%s gunu %s sehrine gonderildi,\n", temp->gun, temp->sehir);
				fprintf(file, "Durum : %s\n\n", temp->durumu);
			}
			temp=temp->next;
		}
		fclose(file);
	}
}


