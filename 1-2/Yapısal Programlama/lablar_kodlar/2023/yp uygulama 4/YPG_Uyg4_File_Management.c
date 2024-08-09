#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct data{
	int ID;
	char Name[50];
	char Department[20];
	struct data *next;
}data;

void Split_Data(data* holder, char buff[255], char delimiter[2]){
	char *token;
	
	token=strtok(buff, delimiter);
	holder->ID = atoi(token);
	
	token=strtok(NULL, delimiter);
	strcpy(holder->Name, token);
	
	token=strtok(NULL, delimiter);
	token[strlen(token)-1]='\0';
	strcpy(holder->Department, token);
}

data* File_Read(char *File_Name, char delimiter[2]){
	FILE *fp =fopen(File_Name, "r");
	char buf[255];
	
	data* head=(data*)malloc(sizeof(data));
	data* curr_data;
	data* prev_data;
	
	if(fgets(buf, 255, fp) != NULL){
		printf("%s", buf);
		Split_Data(head, buf, delimiter);
	}else{
		return NULL;
	}
	
	prev_data=head;
	while(fgets(buf,255,fp) != NULL){
		printf("%s", buf);
		curr_data=(data*)malloc(sizeof(data));
		prev_data->next=curr_data;
		Split_Data(curr_data,buf,delimiter);
		prev_data = curr_data;
	}
	
	prev_data -> next=NULL;
	fclose(fp);
	return head;
	
	}
	
void File_Write(data* head, char *File_Name, char delimiter){
	FILE *fp = fopen(File_Name, "w");
	char tmp[20];
	
	while(head!=NULL){
		itoa(head->ID, tmp, 10);
		fputs(tmp, fp);
		fputc(delimiter, fp);
		fputs(head->Name, fp);
		fputc(delimiter, fp);
		fputs(head->Department, fp);
		fputc('\n', fp);
		head=head->next;
	}
	
	fclose(fp);
	return;
}
	
	
void Print_List(data* head){
	while(head!=NULL){
		printf("ID: %d, Name: %s, Department: %s\n", head->ID, head->Name, head->Department);
		head=head->next;
	}
}

int Sort_Ascending(int first, int second){
	return first<second;
}

int Sort_Descending(int first, int second){
	return first>second;
}

data* Sort_Data(data* head, int (*Sort_Condition)(int, int)){
	if(head == NULL || head->next == NULL)
		return head;
	
	int min_max = head->ID;
	data *prev = head;
	data *new_max = NULL;
	data *cur = head -> next;
	
	while(cur != NULL){
		if(Sort_Condition(cur->ID, min_max)){
			min_max = cur->ID;
			new_max = prev;
		}
		prev = cur;
		cur = cur -> next;
	}
	
	if(new_max == NULL){
		head -> next = Sort_Data(head->next, Sort_Condition);
		return head;
	}
	
	prev = new_max;
	new_max = prev->next;
	prev -> next = new_max->next;
	
	new_max-> next = Sort_Data(head, Sort_Condition);
	
	return new_max;
	
}

int main(){
	data* head;
	head=File_Read("Dataset.txt", ",\0");
	Print_List(head);
	head=Sort_Data(head, Sort_Descending);
	printf("Descending\n");
	Print_List(head);
	File_Write(head, "New_dataset_descending.txt", ',');
	
	head=Sort_Data(head, Sort_Ascending);
	printf("Ascending\n");
	Print_List(head);
	File_Write(head, "New_dataset_Ascending.txt", ',');
	
}
