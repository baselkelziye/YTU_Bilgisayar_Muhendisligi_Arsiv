#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define LISTSIZE 4 //liste kapasitesi
#define MAXADDRESS 5 //adresin head olmasi icin gereken sinir
#define ADDRESS_SIZE 100 //maksimum adres uzunlugu  

struct node{
	char address[ADDRESS_SIZE];
	int counter;
	struct node* prev;
	struct node* next;
};

struct node* createList();
struct node* createNode();
struct node* addNode(struct node* head, char address[]);
void printList(struct node* head);
int counterQuery(struct node* head, char address[]);
struct node* deleteNode(struct node* head, char address[]);
struct node* deleteAllNodes(struct node* head);
void mainMenu();
void readFromKeyboard();
void readFromFile();

int main(){
	
	mainMenu();
	
	return 0;
}

void mainMenu(){
	int choice;
	
	do{
		printf("1-Read from txt file\n2-Read from keyboard\n3-Quit\nChoice: ");
		
		do{
			scanf("%d",&choice);
			if(choice<0 || choice>3){
				printf("Please enter a valid value\nChoice: ");
			}
		}while(choice<1 || choice>3);
		
		switch(choice){
			case 1:
				readFromFile();
				break;
				
			case 2:
				readFromKeyboard();
				break;
		}
	}while(choice!=3);	
}

struct node* createList(){//bos dugumu baslatir
	return NULL;
}

//@brief dugum olusturur bellekte yer ayirir
//@return olusan node u geri doner

struct node* createNode(){
	struct node* node = (struct node*)malloc(sizeof(struct node));
	
	if(node==NULL){
		printf("\noccured an error while creating node...\n");
		return NULL;
	}
	node->counter = 1;
	node->prev = NULL;
	node->next = NULL;
	
	return node;
}

//@brief listeye yeni dugum ekler, eklerken belli sartlari kontrol eder
//liste dolu mu, gelen node head node olmali mi vs.
//@param head i ve eklenmek istenen adresi alir
//@return node u geri doner

struct node* addNode(struct node* head, char address[]){
	int count = counterQuery(head, address), listSize;//istek sayisi ya da olup olmadigi yoksa 0 varsa count>0
	struct node* temp = head;
	struct node* newNode = createNode();
	
	if(count){  
		if(count>=MAXADDRESS){//max adres sayisindaysa ya da astiysa head olur yani en basa gelir
			head = deleteNode(head, address);//bunu saglamak icin once oldugu yerden sildim sonra da
			head = addNode(head, address);//en basa eski sayisi ne ise eklenmis hali ile yazdim lojigi bu sekilde
			head->counter = count+1;
		}else{
			while(temp!=NULL){
				if(strcmp(temp->address, address) == 0){
					temp->counter++;
				}
				temp=temp->next;
			}
		}
		return head;
	}else{
		if(newNode!=NULL){
			strcpy(newNode->address, address);
			if(head==NULL){
				head=newNode;
			}else{
				newNode->next = head;
				head->prev = newNode;
				head = newNode;
			}
			listSize = countSize(head);//liste kapasiteyi asti ise son eleman silinir
			if(listSize>LISTSIZE){
				temp = head;
				while(temp->next!=NULL){
					temp = temp->next;
				}
				temp->prev->next = NULL;
				free(temp);
				temp = NULL;
			}
			return head;
			
		}else{
			printf("\noccured a problem while adding new node...\n");
			return NULL;
		}
	}
}

//@brief verilen adresi listeden siler, konum fark etmez bas, orta son vs gibi
//@param head i alir silinmek istenen adresi alir
//@return listenin son halini yani head i geri doner

struct node* deleteNode(struct node* head, char address[]){
	struct node* temp = head;
	struct node* temp2 = head;
	
	if(temp==NULL){
		printf("\nList is empty\n");
		return head;
	}else if(!counterQuery(head, address)){
		printf("\nThere is no such address in the list\n");
	}else{
		while(temp!=NULL){
			if(strcmp(temp->address, address) == 0){
				//delete only one element
				if(temp->prev==NULL && temp->next==NULL){
					free(temp);
					head=NULL;
					return head;
				//delete first element	
				}else if(temp->prev==NULL){
					head=head->next;
					free(head->prev);
					head->prev = NULL;
					return head;
				//delete last element
				}else if(temp->next==NULL){
					temp2=temp->prev;
					temp2->next = NULL;
					free(temp);
					temp = NULL;
					return head;
				//delete mid element
				}else{
					temp2= temp->prev;
					temp2->next = temp->next;
					temp->next->prev = temp2;
					free(temp);
					temp=NULL;
					return head;
				}	
			}
			temp=temp->next;
		}
	}
}

//@brief listeyi tamamen bosaltir, cache buffer temizlemek icin
//@param head i yani listeyi alir
//@return null olarak geri doner

struct node* deleteAllNodes(struct node* head){  
	struct node* current = head;
	struct node* next;
	while(current!=NULL){
		next = current->next;
		free(current);
		current= next;
	}
	head = NULL;
	system("cls");
	printList(head);
	return head;
}

void printList(struct node* head){
	struct node* temp = head;
	
	if(temp==NULL){
		printf("\nList is empty\n");
	}else{
		printf("\n");
		while(temp!=NULL){
			printf("%s,%d",temp->address, temp->counter);
			if(temp->next!=NULL){
				printf(" <--> ");
			}
			temp=temp->next;
		}
		printf("\n");
	}
}

//@brief gelen adres daha onceden var mi onu kontrol eder
//@param kontrol edecegi listeyi ve adresi alir
//@return onceden varsa sayisini doner yoksa 0 doner

int counterQuery(struct node* head, char address[]){
	struct node* temp = head;
	
	while(temp!=NULL){
		if(strcmp(temp->address, address) == 0){  return temp->counter;}
		temp=temp->next;
	}
	return 0;
}

//@brief listenin o an ki doluluk oranini gosterir
//@param lsiteyi alir
//@return kac istek varsa onu doner mesela A,2 B,3 C,4 3 tane istek var A, B, C
int countSize(struct node* head){
	int counter = 0;
	struct node* temp = head;
	
	while(temp!=NULL){
		counter++;
		temp=temp->next;
	}
	return counter;
}

//@brief klavyeden istekleri okumak icin fonksiyon 

void readFromKeyboard() {
	struct node* head;
	head = createList();
    char yn, address[ADDRESS_SIZE];
    do {
        printf("Enter an address (exit with 'q'): ");
        scanf("%s",address);
        while (getchar() != '\n');
		if(strcmp(address, "q") != 0){
			head = addNode(head, address);
			printList(head);
			printf("\nDo you want to clear cache ? (y for yes and no for any key)");
			fflush(stdin);
			yn = getchar();
			while (getchar() != '\n');
			if(yn=='y' || yn=='Y'){
				head = deleteAllNodes(head);
			} 
		}
		
    }while (strcmp(address, "q") != 0);
    system("cls");
}

//@param dosyadan istekleri okumak icin fonksiyon

void readFromFile(){
	FILE *file;
	struct node* head = createList();
    char filename[] = "data.txt";
    char address[ADDRESS_SIZE], yn;
    
    file = fopen(filename, "r");
    if (file == NULL) {
        perror("\nFile is couldn't open\n");
    }

	while((fscanf(file, "%s", address) != EOF) && (yn!='y' && yn!='Y')){
        head = addNode(head, address);
        printList(head);
        printf("\nDo you want to clear cache ? (y for yes and no for any key)");
		scanf(" %c",&yn);
		while (getchar() != '\n');
		if(yn=='y' || yn=='Y'){
			head = deleteAllNodes(head);
		}
    }
    fclose(file);
    system("cls");
}
