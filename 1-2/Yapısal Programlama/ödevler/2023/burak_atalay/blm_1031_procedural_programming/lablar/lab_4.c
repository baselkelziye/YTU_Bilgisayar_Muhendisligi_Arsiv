#include <stdio.h>
#include <stdlib.h>

typedef struct siparis{
	int kod;
	int id;
	char name[20];
	char urun[20];
	char gun[20];
}SIPARIS;

typedef struct list{
	SIPARIS siparis;
	struct list* next;
}LIST;

void siraliEkle(LIST** head, SIPARIS s){
	LIST *temp = *head, *temp2;
	
	if(*head == NULL){
		*head = (LIST*) malloc(sizeof(LIST));
		(*head) -> siparis = s;
		(*head) -> next = NULL;
		return;
	}
	
	//baþa ekliyosak, yani head deðiþiyosa
	if((*head) -> siparis.kod >= s.kod){
		temp = (LIST*) malloc(sizeof(LIST));
		temp -> next = *head;
		temp -> siparis = s;
		*head = temp;
		return;
	}
	
	while(temp -> next != NULL && temp -> next -> siparis.kod < s.kod){
		temp = temp -> next;
	}
	
	temp2 = (LIST*) malloc(sizeof(LIST));
	temp2 -> next = temp -> next;
	temp2 -> siparis = s;
	temp -> next = temp2;
}

LIST* readFromFile(char* fileName){
	FILE* f = fopen(fileName, "r");
	if(f == NULL) return NULL;
	LIST *head = NULL;
	SIPARIS siparis;
	while(fscanf(f, "%d,%d,%[^,],%[^,],%[^\n]", &siparis.kod, &siparis.id, siparis.name, siparis.urun, siparis.gun) == 5){
		siraliEkle(&head, siparis);
	}
	fclose(f);
	return head;
}

void printList(LIST* head){
	while(head != NULL){
		printf("%d %d %s %s %s\n", head -> siparis.kod, head -> siparis.id, head -> siparis.name, head -> siparis.urun, head -> siparis.gun);
		head = head -> next;
	}
}

void writeToFile(LIST* head){
	FILE* f;
	char filename[20];
	while(head != NULL){
		sprintf(filename, "%s.txt", head -> siparis.name);
		f = fopen(filename, "w");
		if(f != NULL){
			fprintf(f, "merhaba %s %s gunu tarafýndan siparis kodu %d olan musteri id %d olan %s siparisin gerceklesti.",
			 head -> siparis.name, head -> siparis.gun, head -> siparis.kod, head -> siparis.id, head -> siparis.urun);
			fclose(f);
		}
		head = head -> next;
	}
}

int main(){
	LIST* head = readFromFile("data.txt");
	printList(head);
	writeToFile(head);
	return 0;
}
