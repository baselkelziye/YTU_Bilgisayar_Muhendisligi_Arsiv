a#include <stdio.h>
#include <stdlib.h>

typedef struct data{
	char name[20];
	char surname[20];
	char id[12];
}DATA;

typedef struct Employee{
	DATA *d;
	struct Employee *next;
}EMPLOYEE;

int addRecord(EMPLOYEE **head);
int removeRecord(EMPLOYEE **head);
void printRecords(EMPLOYEE *head, void (*fptr)(EMPLOYEE*));
void printNameFirst(EMPLOYEE *e);
void printSurNameFirst(EMPLOYEE *e);
void printIDFirst(EMPLOYEE *e);
EMPLOYEE* swap(EMPLOYEE* ptr1, EMPLOYEE* ptr2);

int bubbleSort(EMPLOYEE** head, int count, int feature, int (*fptr)(EMPLOYEE*, EMPLOYEE*,int));

int AscComp(EMPLOYEE* ptr1, EMPLOYEE* ptr2, int feature){
	if(feature == 0){
		return strcmp(ptr1->d->id,ptr2->d->id);
	}
	else if(feature == 1){
		return strcmp(ptr1->d->name,ptr2->d->name);
	}
	return strcmp(ptr1->d->surname, ptr2->d->surname);
	
}

int DescComp(EMPLOYEE* ptr1, EMPLOYEE* ptr2, int feature){
	
	if(feature == 0){
		return strcmp(ptr2->d->id,ptr1->d->id);
	}
	else if(feature == 1){
		return strcmp(ptr2->d->name,ptr1->d->name);
	}
	return strcmp(ptr2->d->surname, ptr1->d->surname);	
}

int main(){
	int (*ftpr[2])(EMPLOYEE*, EMPLOYEE*, int)= {AscComp, DescComp};
	EMPLOYEE *head = NULL;
	int option = 0;
	int sortType;
	int count = 0;
	int res;
	while(option!=6){
		printf("1-Add\n2-Remove\n3-Sort id\n4-Sort Name\n5-Sort Surname: ");
		scanf("%d",&option);
		switch(option){
			case 1:
				res = addRecord(&head);
				if(res==0){
					count++;
				}
				printRecords(head,printIDFirst);
				break;
			case 2:
				res = removeRecord(&head);
				if(res == 0){
					count -- ;
				}
				printRecords(head, printNameFirst);
				break;
			case 3:
				//feature 0 ise id
				printf(" how to sort : 1 -ASC, 2-DESC ");
				scanf("%d",&sortType);
				bubbleSort(&head,count,0,ftpr[sortType-1]);
				printRecords(head,printIDFirst);
				break;
			case 4: 
				printf(" how to sort : 1 -ASC, 2-DESC ");
				scanf("%d",&sortType);
				bubbleSort(&head,count,1,ftpr[sortType-1]);
				printRecords(head,printNameFirst);
				break;
			
			case 5:
				printf(" how to sort : 1 -ASC, 2-DESC ");
				scanf("%d",&sortType);
				bubbleSort(&head,count,2,ftpr[sortType-1]);
				printRecords(head,printSurNameFirst);
				break;
				
			
		}
	}
	
}

int addRecord(EMPLOYEE **head){
	
	EMPLOYEE *emp;
	emp = (EMPLOYEE*)malloc(sizeof(EMPLOYEE));
	DATA* d = (DATA*)malloc(sizeof(DATA));
	
	if((emp == NULL)||(d==NULL)){
		return -1;
	}
	
	emp->d = d;
	printf("Enter name, surname, and id, respectively ");
	scanf("%s %s %s",emp->d->name,emp->d->surname,emp->d->id);
	emp->next = *head;
	*head = emp;
	return 0;
}

void printRecords(EMPLOYEE *head, void (*fptr)(EMPLOYEE *)){
	
	EMPLOYEE *tmp = head;
	while(tmp != NULL){
		fptr(tmp);
		tmp = tmp->next;
	}
}
void printNameFirst(EMPLOYEE *e){
	printf("%s %s %s\n",e->d->name,e->d->surname,e->d->id);
}
void printSurNameFirst(EMPLOYEE *e){
	printf("%s %s %s\n",e->d->surname,e->d->name,e->d->id);
}

void printIDFirst(EMPLOYEE *e){
	printf("%s %s %s\n",e->d->id, e->d->surname,e->d->name); }
	
int removeRecord(EMPLOYEE **head){
	char id[12];
	int found = 0;
	printf("Enter id :");
	scanf("%s",id);
	EMPLOYEE *tmp = *head;
	EMPLOYEE *prev = NULL;
	while(tmp !=NULL && !found){
		if (strcmp(tmp->d->id,id)==0){
			found =1;
			if(prev== NULL){
				*head = tmp->next;
			}
			else{
				prev->next= tmp->next;
			}
			free(tmp);
		}
		prev = tmp;
		tmp = tmp ->next;
	}
	return found;
	
}

EMPLOYEE* swap(EMPLOYEE* ptr1, EMPLOYEE* ptr2){
	DATA* tmp = ptr2->d;
	ptr2->d = ptr1->d;
	
	ptr1->d = tmp;
	
	return ptr2;
}

int bubbleSort(EMPLOYEE** head, int count, int feature, int (*fptr)(EMPLOYEE*, EMPLOYEE*,int)){
	EMPLOYEE* h ;
	int i, j, swapped;
	for (i = 0; i<=count; i++){
		h = *head;
		swapped = 0;
		for (j= 0; j< count-i-1; j++){
			EMPLOYEE* p1 = h;
			EMPLOYEE* p2 = p1->next;
			if (fptr(p1,p2,feature)>0){
				swap(p1,p2);
				swapped =1;
			}
			h = h ->next;
		}
		if ( swapped == 0){
			return;
		}
		
	}
}

