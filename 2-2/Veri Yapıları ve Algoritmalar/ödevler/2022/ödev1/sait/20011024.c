#include<stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node{
	int value;
	struct node* next;
	struct node* nextLevel;
}NODE;

NODE* createNode(int val);
void createInitialLinkedList(NODE** head);
void createLinkedList(NODE** head,NODE *prevHead, int length, int prevLength);
void printLinkedList(NODE* head);
int calculateLength(NODE* head);
int calculateHeight(int len);
void createFastLinkedList(NODE** heads, int numOfLinkedLists, int lengthOfLinkedList);
void printLists(int height, NODE** heads);
NODE** search(int height, NODE** heads);
void sortLinkedList(NODE** head);
void insert(NODE** head);
void removeFromList(int height, NODE** heads);
void freeAllLinkedLists(int height, NODE** heads);
void reCreateLinkedLists(int height, int length, NODE** heads);

int main(void){
	NODE** heads;
	NODE* p;
	int i,lengthOfLinkedList,height,menuInput = 15;
	
	srand(time(NULL));
		
	heads = (NODE**)malloc( sizeof(NODE*) );
	heads[0] = NULL;
	createInitialLinkedList(&(heads[0]));
	lengthOfLinkedList = calculateLength(heads[0]);
	height = calculateHeight(lengthOfLinkedList);

	heads = (NODE**)realloc(heads, height*sizeof(NODE*));
	
	for(i=1; i<height; i++){
		if(heads[i] == NULL){
			printf("Allocation Fault\n");
			return -1;
		}
		heads[i] = NULL;
	}
	createFastLinkedList(heads, height,lengthOfLinkedList);
	printLists(height,heads);
	
	while(menuInput != -1){
		printf("MENU\n");
		printf("Arama yapmak icin 1\nEleman eklemek icin 2\nEleman silmek icin 3\nCikmak icin -1 giriniz.\n");
		printf("Seciminiz: ");
		scanf("%d", &menuInput);
		
		if(menuInput == 1){
			printLists(height,heads);
			search(height, heads);		
		}
		else if(menuInput == 2){
			insert(&heads[0]);
			freeAllLinkedLists(height, heads);
			lengthOfLinkedList = calculateLength(heads[0]);
			height = calculateHeight(lengthOfLinkedList);
			
			for(i=1; i<height; i++){
				heads[i] = NULL;
			}
			
			createFastLinkedList(heads, height, lengthOfLinkedList);
			printLists(height,heads);
		}
		else if(menuInput == 3){
			removeFromList(height,heads);
			freeAllLinkedLists(height, heads);
			lengthOfLinkedList = calculateLength(heads[0]);
			height = calculateHeight(lengthOfLinkedList);
			
			for(i=1; i<height; i++){
				heads[i] = NULL;
			}
			
			createFastLinkedList(heads, height, lengthOfLinkedList);
			printLists(height,heads);
		}
		else if(menuInput != -1){
			printf("Hatali giris yaptiniz. Tekrar deneyiniz.\n");
		}
	}
	
	printf("Height: %d\n", height);
	
	return 0;
}

NODE* createNode(int val){
	NODE* p;
	p = (NODE*)malloc( sizeof(NODE) );
	
	p->value = val;
	p->next = NULL;
	p->nextLevel = NULL;
	
	return p;
}

void createInitialLinkedList(NODE** head){
	int input;
	int menuSelection = 0;
	NODE* p;
	
	while(menuSelection != 1){
		printf("Eklemek istediginiz elemani (Cikmak icin -1) giriniz: ");
		scanf("%d", &input);
		
		if(input == -1){
			printf("-1 girdiniz cikmak istiyorsaniz 1,\n-1 degerini listeye eklemek istiyorsaniz 0 giriniz: ");
			scanf("%d", &menuSelection);
			if(menuSelection == 0){
				if(*head == NULL){
					*head = createNode(input);
				}
				else{
					p = *head;
					while(p->next != NULL){
						p = p->next;
					}
					p->next = createNode(input);
				}
			}
		}
		else{
			if(*head == NULL){
				*head = createNode(input);
			}
			else{
				p = *head;
				while(p->next != NULL){
					p = p->next;
				}
				p->next = createNode(input);
			}
		}
	}
}

void createLinkedList(NODE** head,NODE *prevHead, int length, int prevLength){
	NODE* prevPointer;
	NODE* pointer;
	int i,randNum,isPointerGenerated;
	int index,counter = 0;

	i = 0;
	prevPointer = prevHead;
	while(i<length){
		randNum = rand();
		isPointerGenerated = 0;
		if(randNum%6 == 0 && counter < prevLength-i-3){
			counter += 2;
			prevPointer = prevPointer->next->next;
			isPointerGenerated = 1;
			i++;
		}
		else if(randNum%5 == 0){
			counter++;
			prevPointer = prevPointer->next;
			isPointerGenerated = 1;
			i++;
		}
		if(isPointerGenerated == 1){
			if(*head == NULL){
				*head = createNode(prevPointer->value);
				(*head)->nextLevel = prevPointer;
			}
				
			else{
				pointer = *head;
				while(pointer->next != NULL){
					pointer = pointer->next;
				}
				
				pointer->next = createNode(prevPointer->value);
				pointer->next->nextLevel = prevPointer;
			}		
		}
	}
}

void printLinkedList(NODE* head){
	NODE* p;
	
	p = head;
	
	if(p == NULL){
		printf("Head NULL");
	}
	
	while(p != NULL){
		printf("%d ", p->value);
		p = p->next;
	}	
	printf("\n");
}

int calculateLength(NODE* head){
	int counter = 0;
	NODE *p;
	
	p = head;
	
	while(p!= NULL){
		p = p->next;
		counter++;
	}
	
	return counter;
}

int calculateHeight(int len){
	int counter = 0;
	while(len > 1){
		counter++;
		len = (len+1)/2;
	}
	return ++counter;
}

void createFastLinkedList(NODE** heads, int numOfLinkedLists, int lengthOfLinkedList){
	int i;
	for(i=1; i<numOfLinkedLists; i++){
		createLinkedList(&heads[i], heads[i-1], (lengthOfLinkedList+1)/2, lengthOfLinkedList);
		lengthOfLinkedList = (lengthOfLinkedList+1)/2;
	}
}

void printLists(int height, NODE** heads){
	int i;
	NODE *p;
	for(i=height-1; i>=0; i--){
		printf("Seviye %2d: ",i);
		printLinkedList(heads[i]);
	}	
}

// returns either found pointer and previous pointer of the found pointer or NULL
NODE** search(int height, NODE** heads){
	int i,soughtValue;
	NODE** prevAndCurrentPointer;
	NODE* p;
	NODE* prev;
	
	prevAndCurrentPointer = (NODE**)malloc(2*sizeof(NODE*));
	
	printf("Lutfen Aranacak Degeri Giriniz: ");
	scanf("%d", &soughtValue);
	
	i = height-1;
	p = heads[height-1];
	
	while(i>=0){
		prev = NULL;
		printf("Su an %5d. seviye\n", i);
		while(p != NULL && p->value < soughtValue){
			prev = p;
			p = p->next;
		}
		
		if(p != NULL){
			if(p->value == soughtValue){
				printf("%d degeri %d. seviyede bulundu.\n",soughtValue, i);
				prevAndCurrentPointer[0] = prev;
				prevAndCurrentPointer[1]  = p;
				return prevAndCurrentPointer;
			}
			
			else if(p->value > soughtValue){
				if(prev == NULL){
					p = heads[--i];
				}
				else{
					p = prev->nextLevel;
					i--;
				}
			}		
		}
		else{
			if(prev != NULL){
				p = prev->nextLevel;
				i--;
			}
			else{
				p = heads[--i];
			}
		}		
	}
	
	printf("%d degeri dizide bulunmamaktadir.\n", soughtValue);
	
	return NULL;
}

void insert(NODE** head){
	int input;
	NODE* p;
	NODE* prev;
	NODE* ptr;
	
	printf("Listeye eklenecek degeri giriniz: ");
	scanf("%d", &input);
	
	ptr = createNode(input);	
	p = *head;
	
	if((*head)->value >= input){
		ptr->next = *head;
		*head = ptr;
	}
	
	while(p->next != NULL && p->value < input){
		prev = p;
		p = p->next;
	}
	
	if(p->next == NULL){
		p->next = ptr;
	}
	
	else if(p->value >= input){
		prev->next = ptr;
		ptr->next = p;
	}
	printf("%d degeri listeye eklendi\n", input);
}

void removeFromList(int height, NODE** heads){
	NODE* p;
	NODE* prev;
	NODE** prevAndCurrentPointer;
	int input;
	
	printf("Listeden silmek istediginiz elemani giriniz: ");
	scanf("%d", &input);
	
	if(heads[0]->value == input)
		heads[0] = heads[0]->next;
	
	p = heads[0];
	
	while(p->next != NULL && p->value<input){
		prev = p;
		p = p->next;
	}

	if(input == p->value){
		prev->next = p->next;
		free(p);
		printLinkedList(heads[0]);
		return;
	}
	printf("Silinmek istenen eleman bulunamadigi icin silinemedi.\n");
}

void freeAllLinkedLists(int height, NODE** heads){
	NODE *p;
	NODE *temp;
	int i;
	
	for(i=height-1; i>=1; i--){
		while(heads[i]->next != NULL){
			temp = heads[i]->next;
			heads[i]->next = heads[i]->next->next;
			free(temp);
		}
		free(heads[i]);
	}	
}
