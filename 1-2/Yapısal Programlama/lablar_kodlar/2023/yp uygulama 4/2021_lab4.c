#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct flight{
	int flight_code;
	char depart_city[30];
	char landing_city[30];
	char time[6];
	int in_or_out;
	int pist_number;
	struct flight *next;
}flight;



void Split_Data(flight* holder, char buff[255], char delimiter[2]);
flight* FileRead(char *File_Name, char delimiter[2]);
void FileWrite(flight* head);
int* FindFileName(flight* head, int *fileNames);
void PrintList(flight* head);



int main(){
	flight *head = FileRead("flights.txt", " \0");
	FileWrite(head);
	PrintList(head);
	
	
	return 0;
}

flight* FileRead(char *File_Name, char delimiter[2]){
	FILE *fp = fopen(File_Name, "r");
	char buff[255];
	
	flight* head = (flight*)malloc(sizeof(flight));
	flight* curr_flight;
	flight* prev_flight;
	
	if(fgets(buff, 255, fp) != NULL){
		printf("%s", buff);
		Split_Data(head, buff, delimiter);
	}else{
		return NULL;
	}
	
	prev_flight = head;
	while(fgets(buff, 255, fp) != NULL){
		printf("%s", buff);
		curr_flight = (flight*)malloc(sizeof(flight));
		prev_flight->next = curr_flight;
		Split_Data(curr_flight, buff, delimiter);
		prev_flight = curr_flight;
	}
	prev_flight->next = NULL;
	fclose(fp);
	return head;
}

void FileWrite(flight* head){
	int *fileNames;
	char fileName[20];
	int i;
	
	fileNames = FindFileName(head, fileNames);
	flight* temp;
	for(i=0;i<fileNames[49];i++){
		sprintf(fileName, "pist%d.txt",fileNames[i]);
		
		printf("%d\n",fileNames[i]);
		
		FILE *fp = fopen(fileName, "w");
		temp=head;
		while(temp!=NULL){
			if(temp->pist_number == fileNames[i])
				fprintf(fp, "%d %s %s %s %d %d\n", temp->flight_code, temp->depart_city, temp->landing_city, temp->time, temp->in_or_out, temp->pist_number);
			temp=temp->next;	
		}
		fclose(fp);
	}
	
	
}

void Split_Data(flight* holder, char buff[255], char delimiter[2]){
	char *token;
	
	token = strtok(buff, delimiter);
	holder->flight_code = atoi(token);
	
	token=strtok(NULL, delimiter);
	strcpy(holder->depart_city, token);
	
	token=strtok(NULL, delimiter);
	strcpy(holder->landing_city, token);
	
	token=strtok(NULL, delimiter);
	strcpy(holder->time, token);
	
	token=strtok(NULL, delimiter);
	holder->in_or_out = atoi(token);
	
	token=strtok(NULL, delimiter);
	token[strlen(token)-1] = '\0';
	holder->pist_number = atoi(token);
}

int* FindFileName(flight* head, int *fileNames){
	
	int i=0, match, j;
	fileNames = (int *)malloc(50 * sizeof(int));
	for(j=0;j<50;j++){
		*(fileNames+j)=0;
	}
	
	while(head!=NULL){
		match=0;
		for(j=0;j<i+1;j++){
			if(head->pist_number==fileNames[j]){
				match=1;
			}
		}
		if(!match){
			fileNames[i] = head->pist_number;
			i++;
		}
		
		head=head->next;
	}
	
	fileNames[49] = i;
	return fileNames;
}

void PrintList(flight* head){
	while(head!=NULL){
		printf("Flight Code: %d Departing City:%s Landing City: %s Time: %s Inner or Outer: %d Pist Number: %d\n", head->flight_code, head->depart_city, head->landing_city, head->time, head->in_or_out, head->pist_number);
		head=head->next;
	}
}
