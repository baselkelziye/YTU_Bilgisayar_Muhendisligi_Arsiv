#include <stdlib.h>
#include <stdio.h>
#include <string.h>
typedef struct ucus{
	int ID;
	char nereden[50];
	char nereye[50];
	char saat[20];
	int ic_dis;
	int kapi;
	int kullanildi;
	struct ucus *next;
	struct ucus *prev;
}UCUS;
void printlist(UCUS * head){
	while(head!=NULL){
		printf("%d %s %s %s %d %d\n",head->ID,head->nereden,head->nereye,head->saat,head->ic_dis,head->kapi);
		head=head->next;
	}
}
UCUS * durum_oku(UCUS * son){
	FILE * fp;
	UCUS * head;
	int a,b,c;
	char nereden[50],nereye[50],saat[20];
	fp=fopen("ucusBilgi.txt","r");
	son=(UCUS*)malloc(sizeof(UCUS));
	fscanf(fp,"%d %s %s %s %d %d\n",&a,nereden,nereye,saat,&b,&c);
	son->ic_dis=b;
	son->kapi=c;
	son->ID=a;
	strcpy(son->nereden,nereden);
	strcpy(son->nereye,nereye);
	strcpy(son->saat,saat);
	son->kullanildi=0;
	son->next=NULL;

	while(fscanf(fp,"%d %s %s %s %d %d\n",&a,nereden,nereye,saat,&b,&c)==6){
		head=(UCUS*)malloc(sizeof(UCUS));
		strcpy(head->nereden,nereden);
		strcpy(head->nereye,nereye);
		strcpy(head->saat,saat);
		head->ic_dis=b;
		head->kapi=c;
		head->ID=a;
		head->kullanildi=0;
		son->prev=head;
		head->next=son;
		son=head;
		head=NULL;
	}
	fclose(fp);
	son->prev=NULL;
	return son;
}
void pist_yazdir(UCUS * head){
	FILE * fp;
	UCUS * headd;
	int deger=0;
	char dosya[30];
	int suanki;
	headd=head;
	while(head!=NULL){
		headd=head;
		suanki=head->kapi;
	if(head->kullanildi==0){
		itoa(headd->kapi,dosya,10);
		strcat(dosya,".pist.txt");
		fp=fopen(dosya,"w");
		deger=1;
	while(headd!=NULL ){
		if(headd->kapi==suanki){
		fprintf(fp,"%d %s %s %s %d %d\n",headd->ID,headd->nereden,headd->nereye,headd->saat,headd->ic_dis,headd->kapi);
		headd->kullanildi=1;}
		headd=headd->next;
	}}
	fclose(fp);
	deger=0;
	head=head->next;
}
	
	
}
int main()
{
	FILE * fp;
	UCUS * head;
    int i,j;
	  head=durum_oku(head);
	  printlist(head);
	  pist_yazdir(head);
    return 0;
}
