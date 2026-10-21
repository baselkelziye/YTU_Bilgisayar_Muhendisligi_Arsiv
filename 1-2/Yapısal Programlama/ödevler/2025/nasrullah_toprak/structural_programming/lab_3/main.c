#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct service {
	char *name;
} Service;

typedef struct member {
	char *name;
	int age;
	Service* services[2];
	int serviceCount;
	struct member* next;
} MEMBER;

Service* allocateservice(char*serviceName);
MEMBER* allocatemember(char *name, int age);
void insertstruct(MEMBER **head);
void findstruct(MEMBER **head, char *searchname);
void deletestruct(MEMBER **head,char *deletename);
void liststruct(MEMBER **head);
void freestructs(MEMBER **head);

int main() {
	int choice = 0;
	char searchname[20];
	char deletename[20];
	MEMBER *head = NULL;

	while(choice!=5) {
		printf("\n1. Kisi ekleme\n 2. Kisi arama\n3. Kisi silme\n4. Listeleme\n5. Cikis\n");
		printf("Seciminizi giriniz: ");
		scanf("%d", &choice);

		if(choice==1) {
			insertstruct(&head);
		}
		else if(choice==2) {
			printf("Aranacak adi giriniz:");
			scanf("%s", searchname);
			findstruct(&head, searchname);
		}
		else if(choice==3) {
			printf("Silinecek adi giriniz:");
			scanf("%s", deletename);
			deletestruct(&head, deletename);
		}
		else if(choice==4) {
			liststruct(&head);
		}
		else if(choice==5) {
			freestructs(&head);
		}
		else {
			printf("Gecersiz secim, tekrar deneyiniz.\n");
		}
	}
	return 0;
}

void insertstruct(MEMBER **head) {
	MEMBER *p, *temp;
	int selection, i;
	char name[20];
	int age;
	char c;

	printf("Adi giriniz: ");
	scanf("%s", name);
	printf("Yasi giriniz: ");
	scanf("%d", &age);

	p = allocatemember(name, age);
	if(p==NULL) {
		printf("Bellek ayrilamadi.\n");
		return;
	}

	printf("HIZMETLER:\n1:Yuzme\n2:Gym\n3:Tenis\n4:Yoga&Plates\n5:Beslenme&Diyet\n(max 2)\n");
	printf("1. Secim (1-5): ");
	scanf("%d", &selection);
	if(selection==1){
		p->services[0]=allocateservice("Yuzme");
	}
	else if(selection==2){
		p->services[0]=allocateservice("Gym");
	}
	else if(selection==3){
		p->services[0]=allocateservice("Tenis");
	}
	else if(selection==4){
		p->services[0]=allocateservice("Yoga&Plates");
	}
	else if(selection==5){
		p->services[0]=allocateservice("Beslenme&Diyet");
	}

	p->serviceCount=1;

	printf("Baska hizmet secmek istiyor musunuz? (Y/N): ");
	scanf(" %c", &c);

	if(c=='Y' || c=='y') {
		p->serviceCount=2;
		printf("2. Secim (1-5): ");
		scanf("%d", &selection);
		if(selection==1){
			p->services[1]=allocateservice("Yuzme");
		}
		else if(selection==2){
			p->services[1]=allocateservice("Gym");
		}
		else if(selection==3){
			p->services[1]=allocateservice("Tenis");
		}
		else if(selection==4){
			p->services[1]=allocateservice("Yoga&Plates");
		}
		else if(selection==5){
			p->services[1]=allocateservice("Beslenme&Diyet");
		}
	}

	if(*head==NULL){
		*head=p;
	}else{
		temp=*head;
		while(temp->next!=NULL){
			temp=temp->next;
		}
		temp->next=p;
	}
}

Service* allocateservice(char *serviceName) {
	Service *s=(Service*)malloc(sizeof(Service));
	if(s==NULL) return NULL;
	s->name=(char*)malloc(20 * sizeof(char));
	if(s->name==NULL) {
		free(s);
		return NULL;
	}
	strcpy(s->name, serviceName);
	return s;
}


MEMBER* allocatemember(char *name, int age) {
	MEMBER *m=(MEMBER*)malloc(sizeof(MEMBER));
	if(m==NULL) return NULL;
	m->name=(char*)malloc(20 * sizeof(char));
	if(m->name==NULL) {
		free(m);
		return NULL;
	}
	strcpy(m->name, name);
	m->age=age;
	m->serviceCount=0;
	m->next = NULL;
	m->services[0]=NULL;
	m->services[1]=NULL;
	return m;
}

void findstruct(MEMBER **head, char *searchname) {
	MEMBER *temp;
	int i;
	int flag=0;
	temp = *head;
	while(temp!=NULL && flag==0) {
		if(strcmp(temp->name, searchname)==0){
			printf("Ad: %s\n", temp->name);
			printf("Yas: %d\n", temp->age);
			printf("Hizmetler:\n");
			for(i=0;i<temp->serviceCount;i++){
				printf("%d- %s\n", i+1, temp->services[i]->name);
			}
			flag++;
		}
		temp=temp->next;
	}
	if (flag==0){
		printf("Kisi bulunamadi\n");
	}
}

void deletestruct(MEMBER **head, char *deletename){
	MEMBER *temp, *prev;
	int i;
	int flag=0;
	temp=*head;
	prev=NULL;

	while(temp!=NULL && flag==0){
		if(strcmp(temp->name, deletename)==0){
			if(prev==NULL){
				*head=temp->next;
			} else {
				prev->next=temp->next;
			}
			free(temp->name);
			for(i=0;i<temp->serviceCount;i++){
				if(temp->services[i]!=NULL) {
					free(temp->services[i]->name);
					free(temp->services[i]);
				}
			}
			free(temp);
			printf("Kisi silindi\n");
			flag++;
		}
		prev=temp;
		temp=temp->next;
	}
	if (flag==0){
		printf("Kisi bulunamadi \n");
	}
}

void liststruct(MEMBER **head) {
	MEMBER *temp;
	int i;
	temp=*head;
	while(temp!=NULL) {
		printf("\nAd: %s\n", temp->name);
		printf("Yas: %d\n", temp->age);
		printf("Hizmetler:\n");
		for(i=0;i<temp->serviceCount;i++) {
			printf("%d- %s\n", i+1, temp->services[i]->name);
		}
		temp=temp->next;
	}
}

void freestructs(MEMBER **head) {
	MEMBER *temp, *next;
	int i;
	temp=*head;
	while(temp!=NULL) {
		next=temp->next;
		free(temp->name);
		for(i=0;i<temp->serviceCount;i++) {
			if(temp->services[i]!=NULL) {
				free(temp->services[i]->name);
				free(temp->services[i]);
			}
		}
		free(temp);
		temp=next;
	}
	*head=NULL;
}



