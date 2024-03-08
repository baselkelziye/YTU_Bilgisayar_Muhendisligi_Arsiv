#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define KISISIZE 12
typedef struct id{
int currID;
struct id * nextID; 	
}ID;
typedef struct kisi{
char * isim;
char * soyisim;
int id;
ID * next;
}KISI;
void kisiOlustur(int id,char * isim, char * soyisim,KISI * kisi){
	kisi->id = id;
	kisi->isim= (char*)malloc(50*sizeof(char));
	kisi->soyisim= (char*)malloc(50*sizeof(char));
	strcpy(kisi->isim,isim);
	strcpy(kisi->soyisim,soyisim);
	kisi->next=(ID*)malloc(sizeof(ID));
}
void kisiYazdir(KISI * kisi){
	ID * id;
	printf("ID->%d\nISIM->%s\nSOYISIM->%s\n",kisi->id,kisi->isim,kisi->soyisim);
	id = kisi->next;
	while(id!=NULL){
		printf("%d,",id->currID);
		id=id->nextID;
	}
	printf("\n");
}
KISI ** readFile(){
	FILE * fp;
	fp = fopen("socialNET.txt","r");
	int id,i,tmpID;
	KISI ** kisi;
	ID * tmp=NULL,*tmpPrev=NULL,*tmp2Prev=NULL;
	char * isim, *soyisim,*charID;
	charID= (char*)malloc(5*sizeof(char));
	isim= (char*)malloc(50*sizeof(char));
	soyisim= (char*)malloc(50*sizeof(char));
	kisi = (KISI **)malloc(KISISIZE*sizeof(KISI*));
	for(i=0;i<KISISIZE;i++){
		kisi[i]=(KISI*)malloc(sizeof(KISI));
	}
	i=0;
	fscanf(fp,"%d,",&id);
	while(fscanf(fp,"%[^,],%s\n",isim,soyisim)==2){
		kisiOlustur(i+1,isim,soyisim,kisi[i]);
		tmp = kisi[i]->next;
		fscanf(fp,"%d,",&tmpID);
		tmp->currID=tmpID;
		tmp->nextID = (ID*)malloc(sizeof(ID));
		tmpPrev=tmp;
		tmp=tmp->nextID;
		while(fscanf(fp,"%d,",&tmpID)==1){
			tmp->currID=tmpID;
			tmp->nextID = (ID*)malloc(sizeof(ID));
			tmp2Prev=tmpPrev;
			tmpPrev=tmp;
			tmp=tmp->nextID;
		}
		if(tmpPrev!=NULL)
			tmpPrev->nextID = NULL;
		tmp2Prev->nextID=NULL;
		free(tmp);
		free(tmpPrev);
		tmp =kisi[i]->next;
		i++;
	}

	fclose(fp);
	return kisi;
}

int main(){
	KISI ** kisi;
	int i;
	kisi = readFile();
	for(i=0;i<KISISIZE;i++)
		free(kisi[i]);
	free(kisi);
	return 0;
}
