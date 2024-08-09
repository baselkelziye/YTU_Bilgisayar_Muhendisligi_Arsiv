#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct siparis{
	int siparisKodu;
	int musteriID;
	char musteriAdi[30];
	char urunTipi[30];
	char islemTarihi[20];
	struct siparis *next;
}siparis;


siparis* File_Read(char *File_Name, char delimiter[2]);
void Split_Data(siparis* holder, char buff[255], char delimiter[2]);
void Print_List(siparis* head);
siparis* Sort_Data(siparis* head);


int main() {
	siparis* head = File_Read("input.txt", " \0");
	printf("\n");
	head = Sort_Data(head);
	Print_List(head);
	MailWrite(head);
	
	return 0;
}

siparis* File_Read(char *File_Name, char delimiter[2]){
	FILE *fp =fopen(File_Name, "r");
	char buff[255];
	
	siparis* head=(siparis*)malloc(sizeof(siparis));
	siparis* curr_siparis;
	siparis* prev_siparis;
	
	if(fgets(buff, 255, fp) != NULL){
		printf("%s", buff);
		Split_Data(head, buff, delimiter);
	}else{
		return NULL;
	}
	
	prev_siparis=head;
	while(fgets(buff,255,fp) != NULL){
		printf("%s", buff);
		curr_siparis=(siparis*)malloc(sizeof(siparis));
		prev_siparis->next=curr_siparis;
		Split_Data(curr_siparis,buff,delimiter);
		prev_siparis = curr_siparis;
	}
	
	prev_siparis -> next=NULL;
	fclose(fp);
	return head;
	
}

void Print_List(siparis* head){
	while(head!=NULL){
		printf("%d %d %s %s %s\n",head->siparisKodu, head->musteriID, head->musteriAdi, head->urunTipi, head->islemTarihi);
		head=head->next;
	}
}

void Split_Data(siparis* holder, char buff[255], char delimiter[2]){
	char *token;
	
	token=strtok(buff, delimiter);
	holder->siparisKodu = atoi(token);
	
	token=strtok(NULL, delimiter);
	holder->musteriID = atoi(token);
	
	token=strtok(NULL, delimiter);
	strcpy(holder->musteriAdi, token);
	
	token=strtok(NULL, delimiter);
	strcpy(holder->urunTipi, token);
	
	token=strtok(NULL, delimiter);
	token[strlen(token)-1]='\0';
	strcpy(holder->islemTarihi, token);
}

siparis* Sort_Data(siparis* head){
	if(head == NULL || head->next == NULL)
		return head;
	
	int min_max = head->siparisKodu;
	siparis *prev = head;
	siparis *new_max = NULL;
	siparis *cur = head -> next;
	
	while(cur != NULL){
		if(cur->siparisKodu < min_max){
			min_max = cur->siparisKodu;
			new_max = prev;
		}
		prev = cur;
		cur = cur -> next;
	}
	
	if(new_max == NULL){
		head -> next = Sort_Data(head->next);
		return head;
	}
	
	prev = new_max;
	new_max = prev->next;
	prev -> next = new_max->next;
	
	new_max-> next = Sort_Data(head);
	
	return new_max;
	
}

void MailWrite(siparis *head){
	siparis *temp  = head;
	char fileName[20];
	while(temp!=NULL){
		sprintf(fileName, "%s.txt",temp->musteriAdi);
		FILE *fp = fopen(fileName,"w");
		fprintf("Merhaba %s, %s gunu tarafinizdan siparis numarasi %d olan musteri id %d olan %s alisverisi gerceklestirilmistir.iyi gunler", temp->musteriAdi, temp->islemTarihi, temp->siparisKodu, temp->musteriID, temp->urunTipi);
		fclose(fp);
		temp = temp->next;
		
	}
}
