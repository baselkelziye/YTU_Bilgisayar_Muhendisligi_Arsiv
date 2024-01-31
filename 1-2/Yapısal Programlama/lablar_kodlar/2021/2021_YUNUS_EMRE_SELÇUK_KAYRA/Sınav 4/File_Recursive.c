#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct DATA{
	int ID;
	char Name[50];
	char department[20];
	struct DATA *next;
}data;

int Sort_Ascending(int first,int second){
	return first<second;
}

int Sort_Descending(int first,int second){
	return first>second;
}

void Split_Data(data* holder,char buff[255],char delimiter[2]){
	char *token;
	// strtok(); Delim parametresi ile gösterilen karakter dizisi içindeki sýnýrlayýcý karakterleri kullanarak str parametresi ile gösterilen karakter dizisini parçalara ayýrýr.
	token=strtok(buff,delimiter);
	// atoi(); Str parametresi ile gösterilen karakter dizisini int bir deðere çevirir.
	holder->ID=atoi(token);
	// NULL; strtok() fonksiyonuna yapýlan ilk çaðrý, parçalanacak C dizesini iletmelidir 
	// ve sonraki çaðrýlar, ilk argüman olarak NULL'u belirtmelidir; bu, fonksiyona, ilk olarak ilettiðiniz diziyi parçalamaya devam etmesini söyler.
	token=strtok(NULL,delimiter);
	strcpy(holder->Name,token);
	token=strtok(NULL,delimiter);
	token[strlen(token)-1]='\0';
	strcpy(holder->department,token);
	
}

data* File_Read(char File_Name[20],char delimiter[2]){
	FILE *fp=fopen(File_Name,"r");
	char buf[255];
	
	data* head=(data*)malloc(sizeof(data));
	data* curr_data;
	data* prev_data;
	if(fgets(buf,255,fp)!=NULL){
		printf("%s",buf);
		Split_Data(head,buf,delimiter);		
	}
	prev_data=head;
	while(fgets(buf,255,fp)!=NULL){
		printf("%s",buf);
		curr_data=(data*)malloc(sizeof(data));
		prev_data->next=curr_data;
		Split_Data(curr_data,buf,delimiter);
		prev_data=curr_data;
	}
	prev_data->next=NULL;
	fclose(fp);
	return head;
}




void File_Write(data* head, char File_Name[20],char delimiter ){
	FILE *fp=fopen(File_Name,"w");
	char tmp[20];
	while(head!=NULL){
		// itoa () function in C language converts int data type to string data type. 
		// 10 means decimal, 2 means binary, 16 means hexadecimal
		itoa(head->ID,tmp,10);
		fputs(tmp,fp);
		fputc(delimiter,fp);
		fputs(head->Name,fp);
		fputc(delimiter,fp);
		fputs(head->department,fp);
		fputc('\n',fp);	
		head=head->next;	
	}
	fclose(fp);
	return ;
}

void File_Write_wfprintf(data* head, char File_Name[20],char delimiter ){
	FILE *fp=fopen(File_Name,"w");
	char tmp[20];
	while(head!=NULL){
		fprintf(fp,"%d,%s,%s\n",head->ID,head->Name,head->department);	
		head=head->next;	
	}
	fclose(fp);
	return ;
}

data* Sort_Data(data* head,int (*Sort_Condition)(int,int)){
	if(head == NULL || head->next == NULL)
        return head;

    int max = head->ID;
    data *prev = head;
    data *to_move = NULL;
    data *tmp = head->next;

    //find maximum value in rest(head->next)
    while(tmp != NULL) {
        if(Sort_Condition(tmp->ID,max)) {
            max = tmp->ID;
            to_move = prev;//save previous node for remove link
        }
        prev = tmp;
        tmp = tmp->next;
    }

	// Eðer eleman zaten en büyükse
    if(to_move == NULL) {//not find in rest
        head->next = Sort_Data(head->next,Sort_Condition);
        return head;
    }

    prev = to_move;
    to_move = prev->next;//max node
    prev->next = prev->next->next;//max node remove from link
    to_move->next = Sort_Data(head,Sort_Condition);
    return to_move;
	
	
}

void Print_List(data* head){
	
	while(head!=NULL){
		printf("ID: %d, Name: %s, Department: %s\n",head->ID,head->Name,head->department);
		head=head->next;	
	}
	
}



int main(){
	data* head;
	head=File_Read("Dataset.txt",",\0");
	Print_List(head);
	head=Sort_Data(head,Sort_Descending);
	printf("Descending\n");
	Print_List(head);
	File_Write(head,"New_dataset.txt",',');
	
	head=Sort_Data(head,Sort_Ascending);
	printf("Ascending\n");
	Print_List(head);
	File_Write(head,"New_dataset_v2.txt",',');

	
}
