#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct customer{
	int code;
	int customerId;
	char customerName[20];
	char productType[20];
	char day[10];
	struct customer *next;
}CUSTOMER;

void printList(CUSTOMER *currData);
CUSTOMER* readFromFile(char *fileName, char delimiter[2]);
void writeToFile(CUSTOMER *head);
CUSTOMER* sortData(CUSTOMER* head);

int main(){
	CUSTOMER *head;
	head=readFromFile("input.txt"," \0");
	head=sortData(head);
	printList(head);
	writeToFile(head);
	return 0;
}

void printList(CUSTOMER *currData){
	printf("Sorted Linked List:\n");
	while(currData!=NULL){
		printf("\n%d %d %s %s %s",currData->code,currData->customerId,currData->customerName,currData->productType,currData->day);
		currData=currData->next;
	}
}

void writeToFile(CUSTOMER *head){
	char tmp[20];
	int pantolonNumber=0,kazakNumber=0,kabanNumber=0;
	
	while(head!=NULL){
		char *fileName=(char*)calloc(1,sizeof(char));
		sprintf(fileName,"%s.txt",head->customerName);
		
		FILE *fp=fopen(fileName,"w");
		
		fputs("Merhaba ",fp);
		fputs(head->customerName,fp);
		fputc(',',fp);
		fputs(head->day,fp);
		fputs(" günü tarafýnýzdan sipariþ numarasý ",fp);
		itoa(head->code, tmp, 10);
		fputs(tmp,fp);
		fputs(" olan müþteri ýd ",fp);
		itoa(head->customerId, tmp, 10);
		fputs(tmp,fp);
		fputs(" olan ",fp);
		fputs(head->productType,fp);
		fputs(" alýþveriþi gerçekleþtirilmiþtir.Ýyi günler\0",fp);
		
		if(strcmp(head->productType,"Pantolon")==0)
			pantolonNumber++;
		else if(strcmp(head->productType,"Kazak")==0)
			kazakNumber++;
		else
			kabanNumber++;
	
		fclose(fp);
		free(fileName);
		head=head->next;
	}
	
	FILE *fp=fopen("rapor.txt","w");
	fprintf(fp,"Pantolon sipariþ sayýsý %d\nKazak sipariþ sayýsý %d\nKaban sipariþ sayýsý %d\0",pantolonNumber,kazakNumber,kabanNumber);
	fclose(fp);
}

void splitData(CUSTOMER *holder, char buff[255], char delimiter[2]){
	char *token;
	
	token=strtok(buff,delimiter);
	holder->code=atoi(token);
	
	token=strtok(NULL,delimiter);
	holder->customerId=atoi(token);
	
	token=strtok(NULL,delimiter);
	strcpy(holder->customerName,token);
	
	token=strtok(NULL,delimiter);
	strcpy(holder->productType,token);
	
	token=strtok(NULL,delimiter);
	token[strlen(token)-1]='\0';
	strcpy(holder->day,token);
}

CUSTOMER* sortData(CUSTOMER* head){
	if(head==NULL || head->next==NULL){
		return head;
	}
	
	int minOrMax=head->code;
	
	CUSTOMER *prev=head;
	CUSTOMER *newMax=NULL;
	CUSTOMER *curr=head->next; 
	
	while(curr!=NULL){
		if(curr->code<minOrMax){
			minOrMax=curr->code;
			newMax=prev;
		}
		prev=curr;
		curr=curr->next;
	}
	
	if(newMax==NULL){
		head->next=sortData(head->next);
		return head;
	}
	
	prev=newMax;
	newMax=prev->next;
	prev->next=newMax->next;
	
	newMax->next=sortData(head);
	return newMax;
}

CUSTOMER* readFromFile(char *fileName, char delimiter[2]){
	FILE *fp=fopen(fileName,"r");
	char buf[255];
	
	CUSTOMER *head=(CUSTOMER*)calloc(1,sizeof(CUSTOMER));
	CUSTOMER *prevData;
	CUSTOMER *currData;
	
	if(fgets(buf,255,fp)!=NULL){
		splitData(head,buf,delimiter);
	}
	else{
		return NULL;
	}
	
	prevData=head;
	while(fgets(buf,255,fp)!=NULL){
		currData=(CUSTOMER*)calloc(1,sizeof(CUSTOMER));
		prevData->next=currData;
		splitData(currData,buf,delimiter);
		prevData=currData;
	}
	
	prevData->next=NULL;
	fclose(fp);
	
	return head;
}
