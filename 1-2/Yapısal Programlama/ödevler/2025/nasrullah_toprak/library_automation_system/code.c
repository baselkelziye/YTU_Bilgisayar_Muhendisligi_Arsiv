#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct yazarlar{
	int yazarID;
	char name[20];
	char surname[20];
	struct yazarlar *next;
}YAZARLAR;

typedef struct ogrenciler{
	struct ogrenciler *prev;
	int ID;
	char name[20];
	char surname[20];
	int grade;
	struct ogrenciler *next;
}OGRENCILER;

typedef struct kitapornekleri{
	long long int ISBN;
	int number;
	union{
		char Rafta[6];
		int ogrenciID;
	};
	struct kitapornekleri *next;
}KITAPORNEKLERI;

typedef struct kitaplar{
	char name[20];
	long long int ISBN;
	int number;
	KITAPORNEKLERI *kitapdurumu;
	struct kitaplar *next;
}KITAPLAR;

typedef struct kitapyazar{
	long long int ISBN;
	int ID;
}KITAPYAZAR;

typedef struct kitapodunc{
	long long int ISBN;
	int ISBNnumber;
	int stdID;
	unsigned int durumu : 1;
	int day;
	int month;
	int year;
	struct kitapodunc *next;
}KITAPODUNC;

YAZARLAR* loadyazarlar(char *Yazarlarcsv);
void removenewline(char *str);
OGRENCILER* loadogrenciler(char *Ogrencilercsv);
KITAPLAR* loadKitaplar( char* filename);
void loadKitapOrnekleri(KITAPLAR* kitaplarList, const char* filename);
KITAPYAZAR* loadKitapYazar(char *filename, int *kitapYazarNo);
KITAPODUNC* loadkitapodunc(char *filename);

void addstudent(OGRENCILER** headogrenciler);
OGRENCILER* deletestudent(OGRENCILER* head, int id, int *check);
KITAPODUNC* deletestudent2(KITAPODUNC *headkitapodunc, int id);
KITAPLAR* deletestudent3(KITAPLAR* headkiatplar, int id);
void updatestudent(OGRENCILER **headogrenciler);
int idstd(OGRENCILER* headogrenciler);
void viewallstdinfo(OGRENCILER* headogrenciler,KITAPODUNC* headkitapodunc,KITAPLAR* headkitaplar, int id);
void didntreturnbooks(KITAPODUNC *headkitapodunc,OGRENCILER *headogrenciler);
void penaltizedstds(OGRENCILER *headogrenciler);
void liststudents(OGRENCILER *headogrenciler);
void borrowbook(OGRENCILER* headogrenciler, KITAPLAR* headkitaplar,KITAPODUNC** headkitapodunc);
void finddate(int *day,int *month,int *year);
void returnbook(OGRENCILER** headogrenciler, KITAPLAR* headkitaplar,KITAPODUNC** headkitapodunc);
int variation(int day, int month, int year, int oldday, int oldmonth, int oldyear) ;

void addbook(KITAPLAR **headkitaplar);
void deletebook(KITAPLAR** headkitaplar, KITAPYAZAR *kitapyazar, int *kitapyazarno, KITAPODUNC **headkitapodunc);
void updatebook(KITAPLAR **headkitaplar);
void viewbook(KITAPLAR *headkitaplar, OGRENCILER *headogrenciler, KITAPYAZAR *kitapyazar, int kitapyazarno, YAZARLAR *headyazarlar);
void listbooksnotreturnedontime(KITAPODUNC *headkitapodunc);
void listbooksonshelf(KITAPLAR *headkitaplar);
void matchbookandauthor(KITAPLAR* headkitaplar,YAZARLAR* headyazarlar, KITAPYAZAR *kitapyazar,int kitapyazarno);
void updatebookauthor(KITAPLAR* headkitaplar,YAZARLAR* headyazarlar, KITAPYAZAR **kitapyazar,int*kitapyazarno);

void addauthor(YAZARLAR** headyazarlar);
void deleteauthor(YAZARLAR **headyazarlar,KITAPYAZAR *kitapyazar,int kitapyazarno);
void updateauthor(YAZARLAR **headyazarlar);
void viewauthorinfo(YAZARLAR *headyazarlar, KITAPYAZAR *kitapyazar, int kitapyazarno,KITAPLAR* headkitaplar);

void saveKitaplar(KITAPLAR* kitaplarList,  char* filename);
void saveKitapOrnekleri(KITAPLAR* kitaplarList, const char* filename);
void savekitapyazar(KITAPYAZAR *head, int kitapyazarno);
void saveList(void* head, void (*saveFunction)(void*));
void saveyazarlar(void* head);
void saveogrenciler(void* head);
void savekitapodunc(void* head);
void freeKitaplarList(KITAPLAR* kitaplarList);
void freeYazarlar(YAZARLAR *head);
void freeOgrenciler(OGRENCILER *head);
void freeKitapOdunc(KITAPODUNC *head);

int main (){
	int choice, flag=0, kitapyazarno=0,check=0,id;
	YAZARLAR *headyazarlar=NULL;
	OGRENCILER *headogrenciler=NULL;
	KITAPORNEKLERI *headkitapornekleri=NULL;
	KITAPLAR *headkitaplar=NULL;
	KITAPYAZAR *kitapyazar;
	KITAPODUNC *headkitapodunc=NULL;
	
	headyazarlar=loadyazarlar("Yazarlar.csv");
	headogrenciler=loadogrenciler("Ogrenciler.csv");
	headkitaplar = loadKitaplar("Kitaplar.csv");
    if (headkitaplar != NULL) {
        loadKitapOrnekleri(headkitaplar, "KitapOrnekleri.csv");
    }
	kitapyazar=loadKitapYazar("KitapYazar.csv", &kitapyazarno);
	headkitapodunc=loadkitapodunc("KitapOdunc.csv");
	
	while(flag==0){
		check=0;
		printf("1. Add/Delete/Update Student \n");
		printf("2. View Student Information \n");
		printf("3. List Students Who Haven’t Returned Books \n"); 
		printf("4. List Penalized Students \n");
		printf("5. List All Studnets \n"); 
		printf("6. Borrow/Return Book \n");	
		printf("7. Add/Delete/Update Book\n");
		printf("8. View Book Information \n"); 
		printf("9. List Books on the Shelf \n"); 
		printf("10. List Books Not Returned on Time \n"); 
		printf("11. Match Book and Author \n"); 
		printf("12. Update the Book's Author \n");
		printf("13. Add/Delete/Update Author \n"); 
		printf("14. View Author Information \n");
		printf("15. Save and Exit \n"); 
		printf("CHOICE: ");
		scanf("%d",&choice);
		if(choice==1){
			do{
				printf("\n1. Add Student\n2. Delete Student\n3. Update Student\nCHOICE: ");
				scanf("%d",&choice);
			}while(choice<1 || choice>3);
			
			if(choice==1){
				addstudent(&headogrenciler);
			} else if(choice==2){
				printf("Enter id: ");
				scanf("%d",&id);
				headogrenciler=deletestudent(headogrenciler, id, &check);
				if(check==1){
					headkitapodunc=deletestudent2(headkitapodunc, id);
					headkitaplar=deletestudent3(headkitaplar,  id);
				}
			}else{
				updatestudent(&headogrenciler);
			}
			
		}else if(choice==2){
			do{
				printf("Seatch by id (1) or seatch by name and surname (2) : ");
				scanf("%d",&choice);
			}while(choice!=1 && choice!=2);
			if(choice==1){
				printf("Enter id: ");
				scanf("%d", &id);
				viewallstdinfo(headogrenciler, headkitapodunc, headkitaplar, id);
			} else{
				id = idstd(headogrenciler);
				if(id!=0){
					viewallstdinfo(headogrenciler, headkitapodunc, headkitaplar, id);
				} else{
					printf("The student is not found");
				}
			}	
		}else if (choice==3){
			didntreturnbooks(headkitapodunc, headogrenciler);
		}else if (choice==4){
			penaltizedstds(headogrenciler);
		}else if(choice==5){
			liststudents(headogrenciler);
		}else if(choice==6){
			do{
				printf("Borrow Book (1); Return book (2) \nCHOICE: ");
				scanf("%d",&choice);
			}while(choice!=1 && choice!=2);
			if(choice==1){
				borrowbook(headogrenciler, headkitaplar, &headkitapodunc);
			} else{
				returnbook(&headogrenciler, headkitaplar, &headkitapodunc);
			}
		}else if(choice==7){
			do{
				printf("\n1. Add Book\n2. Delete Book\n3. Update book\nCHOICE: ");
				scanf("%d",&choice);
			}while(choice<1 || choice>3);
			if(choice==1){
				addbook(&headkitaplar);
			} else if(choice==2){
				deletebook(&headkitaplar, kitapyazar, &kitapyazarno, &headkitapodunc);
			}else{
				updatebook(&headkitaplar);
			}
		}else if (choice==8){
			viewbook(headkitaplar,headogrenciler, kitapyazar, kitapyazarno, headyazarlar);
		}else if(choice==9){
			listbooksonshelf(headkitaplar);
		}else if(choice==10){
			listbooksnotreturnedontime(headkitapodunc);
		}else if(choice==11){
			matchbookandauthor(headkitaplar, headyazarlar,kitapyazar,kitapyazarno);
		}else if(choice==12){
			updatebookauthor(headkitaplar, headyazarlar,&kitapyazar,&kitapyazarno);
		}else if(choice==13){
			do{
				printf("\n1. Add Author\n2. Delete Author\n3. Update Author\nCHOICE: ");
				scanf("%d",&choice);
			}while(choice<1 || choice>3);
			if(choice==1){
				addauthor(&headyazarlar);
			} else if(choice==2){
				deleteauthor(&headyazarlar, kitapyazar,kitapyazarno);
			}else{
				updateauthor(&headyazarlar);
			}
		}else if(choice==14){
			viewauthorinfo(headyazarlar, kitapyazar,kitapyazarno, headkitaplar);
		}else if(choice==15){
			flag=1;
		}else{
			printf("Wrong Choice number \n");
		}
		printf("\n\n\n\n\n");
	}
	
	void (*saveFunc)(void*);

	saveFunc=saveyazarlar;
	saveList(headyazarlar, saveFunc);
	saveFunc=saveogrenciler;
	saveList(headogrenciler, saveFunc);
	saveFunc=savekitapodunc;
	saveList(headkitapodunc, saveFunc);
	
	saveKitaplar(headkitaplar, "Kitaplar.csv");
    saveKitapOrnekleri(headkitaplar, "KitapOrnekleri.csv");
	savekitapyazar(kitapyazar, kitapyazarno);
	
	freeKitaplarList(headkitaplar);
	free(kitapyazar);
	freeYazarlar(headyazarlar);
	freeOgrenciler(headogrenciler);
	freeKitapOdunc(headkitapodunc);
	return 0;
}

YAZARLAR* loadyazarlar(char *Yazarlarcsv){
	FILE *file;
	YAZARLAR *head=NULL, *temp, *last=NULL;
	char line[50];
	char *token, name[20], surname[20];
	int id;
	
	file=fopen(Yazarlarcsv,"r");
	if(file==NULL){
		printf("Can't open yazarlar.csv");
		return NULL;
	}
	
	while(fgets(line,50,file)!=NULL){
		token=strtok(line,",");
		if(token!=NULL){
			id=atoi(token);
		}
		token=strtok(NULL,",");
		if(token!=NULL){
			strncpy(name,token,19);
			name[19]='\0';
		}
		token=strtok(NULL,",");
		if(token!=NULL){
			strncpy(surname,token,19);
			surname[19]='\0';
			removenewline(surname);
		}
		
		temp=(YAZARLAR*)malloc(sizeof(YAZARLAR));
		if(temp==NULL){
			printf("No enough memory");
			fclose(file);
			exit(-1);
		}
		
		temp->yazarID=id;
		strcpy(temp->name,name);
		strcpy(temp->surname,surname);
		temp->next=NULL;
		
		if(head==NULL){
			head=temp;
			last=temp;
		} else{
			last->next=temp;
			last=temp;
		}
	}
	fclose(file);
	return head;
}

void removenewline(char *str){
	int i;
	for(i=0;str[i]!='\0';i++){
		if(str[i]=='\n'){
			str[i]='\0';
			return;
		}
	}
}


OGRENCILER* loadogrenciler(char *Ogrencilercsv){
	FILE *file;
	OGRENCILER *head=NULL, *temp, *last=NULL;
	char line[100];
	char *token, name[20], surname[20];
	int id, grade;
	
	file=fopen(Ogrencilercsv,"r");
	if (file==NULL){
		printf("Can't open Ogrenciler.csv");
		return NULL;
	}
	while(fgets(line,100,file)!=NULL){
		token=strtok(line,",");
		if(token!=NULL){
			id=atoi(token);
		}
		token=strtok(NULL,",");
		if(token!=NULL){
			strncpy(name,token,19);
			name[19]='\0';
		}
		token=strtok(NULL,",");
		if(token!=NULL){
			strncpy(surname,token,19);
			surname[19]='\0';
		}
		token=strtok(NULL,",");
		if(token!=NULL){
			grade=atoi(token);
		}
		
		temp=(OGRENCILER*)malloc(sizeof(OGRENCILER));
		if(temp==NULL){
			printf("No enough memory");
			fclose(file);
			exit(-1);
		}
		
		temp->ID=id;
		strcpy(temp->name,name);
		strcpy(temp->surname,surname);
		temp->grade=grade;
		temp->next=NULL;
		temp->prev=NULL;
		
		if(head==NULL){
			head=temp;
			last=temp;
		} else{
			last->next=temp;
			temp->prev=last;
			last=temp;
		}
	}
	fclose(file);
	return head;
}

KITAPLAR* loadKitaplar( char* filename){
	FILE* file;
	KITAPLAR* head;
	KITAPLAR* tail;
	KITAPLAR* newBook;
	char line[256];
	char* name;
	char* isbnStr;
	char* numberStr;
	size_t len;

	head=NULL;
	tail=NULL;

	file=fopen(filename,"r");
	if(file==NULL){
		perror("Error opening Kitaplar.csv");
		return NULL;
	}

	while(fgets(line,sizeof(line),file)){
		len=strlen(line);
		if(len>0&&line[len-1]=='\n'){
			line[len-1]='\0';
		}

		newBook=(KITAPLAR*)malloc(sizeof(KITAPLAR));
		if(newBook==NULL){
			fclose(file);
			return NULL;
		}

		name=strtok(line,",");
		isbnStr=strtok(NULL,",");
		numberStr=strtok(NULL,",");

		if(name&&isbnStr&&numberStr){
			strncpy(newBook->name,name,sizeof(newBook->name)-1);
			newBook->name[sizeof(newBook->name)-1]='\0';
			newBook->ISBN=atoll(isbnStr);
			newBook->number=atoi(numberStr);
			newBook->kitapdurumu=NULL;
			newBook->next=NULL;

			if(head==NULL){
				head=newBook;
				tail=newBook;
			} else{
				tail->next=newBook;
				tail=newBook;
			}
		} else{
			free(newBook);
		}
	}

	fclose(file);
	return head;
}

void loadKitapOrnekleri(KITAPLAR* kitaplarList,const char* filename){
	FILE* file;
	char line[256];
	int len;
	char* id;
	char* status;
	char* underscore;
	long long int isbn;
	int number;
	KITAPLAR* currentBook;
	KITAPORNEKLERI* newStatus;
	KITAPORNEKLERI* lastStatus;

	file=fopen(filename,"r");
	if(file==NULL){
		printf("KitapOrnekleri.csv didn't open");
		return;
	}

	while(fgets(line,sizeof(line),file)){
		len=strlen(line);
		if(len>0&&line[len-1]=='\n'){
			line[len-1]='\0';
		}

		id=strtok(line,",");
		status=strtok(NULL,",");

		if(id&&status){
			underscore=strchr(id,'_');
			if(underscore!=NULL){
				*underscore='\0';
				isbn=atoll(id);
				number=atoi(underscore+1);

				currentBook=kitaplarList;
				while(currentBook!=NULL){
					if(currentBook->ISBN==isbn){
						newStatus=(KITAPORNEKLERI*)malloc(sizeof(KITAPORNEKLERI));
						if(newStatus==NULL){
							fclose(file);
							return;
						}

						newStatus->ISBN=isbn;
						newStatus->number=number;

						if(strcmp(status,"Rafta")==0){
							strcpy(newStatus->Rafta,"Rafta");
						}else{
							newStatus->ogrenciID=atoi(status);
						}

						newStatus->next=NULL;

						if(currentBook->kitapdurumu==NULL){
							currentBook->kitapdurumu=newStatus;
						} else{
							lastStatus=currentBook->kitapdurumu;
							while(lastStatus->next!=NULL){
								lastStatus=lastStatus->next;
							}
							lastStatus->next=newStatus;
						}
					}
					currentBook=currentBook->next;
				}
			}
		}
	}

	fclose(file);
}

KITAPYAZAR* loadKitapYazar(char *filename, int *kitapYazarNo) {
	FILE *file;
	char line[100];
	long long int kitapID;
	int yazarID, kitapYazarCount;
	char *token;
	KITAPYAZAR *tmp;
	KITAPYAZAR *kitapYazarhead=NULL;

	file = fopen(filename, "r");
	if(file==NULL) {
		printf("Can't open KitapYazar.csv file");
		return NULL;
	}

	free(kitapYazarhead);
	kitapYazarhead=NULL;
	kitapYazarCount=0;

	while(fgets(line, sizeof(line), file)!=NULL) {
		line[strcspn(line, "\r\n")] = 0;
		if(line[0]=='\0') {

		} else if(!(line[0]>='0' && line[0]<='9')) {

		} else {
			token = strtok(line, ",");
			if(token!=NULL) {
				kitapID=atoll(token);
				token=strtok(NULL, ",");
				if(token!=NULL) {
					yazarID = atoi(token);

					tmp = (KITAPYAZAR*)realloc(kitapYazarhead, (kitapYazarCount+1)*sizeof(KITAPYAZAR));
					if(tmp==NULL) {
						printf("No enough memory");
						exit(-1);
					}

					kitapYazarhead=tmp;
					kitapYazarhead[kitapYazarCount].ISBN = kitapID;
					kitapYazarhead[kitapYazarCount].ID = yazarID;
					kitapYazarCount++;
				}
			}
		}
	}
	fclose(file);

	*kitapYazarNo = kitapYazarCount;
	return kitapYazarhead;
}

KITAPODUNC* loadkitapodunc(char *filename){
	FILE *file;
	KITAPODUNC *head=NULL, *last=NULL, *temp;
	char line[100], *token, isbnstr[30], date[15];
	long long int isbn;
	int no, stdID, durum, day, month, year, i;

	file=fopen(filename,"r");
	if(file==NULL){
		printf("Can't open KitapOdunc.csv\n");
		return NULL;
	}

	while(fgets(line,100,file)!=NULL){
		token=strtok(line,",");
		if(token!=NULL){
			strncpy(isbnstr,token,29);
			isbnstr[29]='\0';
			char *ptr=strrchr(isbnstr,'_');
			if(ptr!=NULL){
				no=atoi(ptr+1);
				*ptr='\0';
				isbn=atoll(isbnstr);
			}
		}
		token=strtok(NULL,",");
		if(token!=NULL){
			stdID=atoi(token);
		}
		token=strtok(NULL,",");
		if(token!=NULL){
			durum=atoi(token);
		}
		token=strtok(NULL,",\n");
		if(token!=NULL){
			strncpy(date,token,14);
			date[14]='\0';
			day=(date[0]-'0')*10 + (date[1]-'0');
			month=(date[3]-'0')*10 +(date[4]-'0');
			year=(date[6]-'0')*1000 + (date[7]-'0')*100 + (date[8]-'0')*10 + (date[9]-'0');
		}

		temp=(KITAPODUNC*)malloc(sizeof(KITAPODUNC));
		if(temp==NULL){
			printf("Memory allocation failed for KITAPODUNC\n");
			fclose(file);
			exit(-1);
		}
		temp->ISBN=isbn;
		temp->ISBNnumber=no;
		temp->stdID=stdID;
		temp->durumu=durum;
		temp->day=day;
		temp->month=month;
		temp->year=year;
		temp->next=NULL;
		
		if(head==NULL){
			head=temp;
			last=temp;
		}else{
			last->next=temp;
			last=temp;
		}
	}
	fclose(file);
	return head;
}


void addstudent(OGRENCILER** headogrenciler){
	OGRENCILER *newstudent, *temp;
	int id, exists=0;
	char name[20], surname[20];
	
	newstudent=(OGRENCILER*)malloc(sizeof(OGRENCILER));
	if(newstudent==NULL){
		printf("no enough memory\n");
		exit(-1);
	}
	
	printf("Enter student ID: ");
	scanf("%d",&id);
	
	temp=*headogrenciler;
	while(temp!=NULL && exists==0){
		if(temp->ID==id){
			exists=1;
		}
		temp=temp->next;
	}
	if(exists==1){
		printf("Student with this ID already exists.\n");
		free(newstudent);
		return;
	}
	
	printf("Enter name: ");
	scanf("%s",name);
	printf("Enter surname: ");
	scanf("%s",surname);
	
	newstudent->ID=id;
	strcpy(newstudent->name,name);
	strcpy(newstudent->surname,surname);
	newstudent->grade=100;
	newstudent->next=NULL;
	newstudent->prev=NULL;
	
	if(*headogrenciler==NULL){
		*headogrenciler=newstudent;
	}else{
		temp=*headogrenciler;
		while(temp->next!=NULL){
			temp=temp->next;
		}
		temp->next=newstudent;
		newstudent->prev=temp;
	}
	
	printf("Student is added successfully\n");
}

OGRENCILER* deletestudent(OGRENCILER* head, int id, int *check){
	OGRENCILER *temp;
	temp=head;
	char name[20], surname[20];
	printf("Enter name: ");
	scanf("%s",name);
	printf("Enter surname: ");
	scanf("%s",surname);

	printf("Student ");
	while(temp!=NULL){
		if(temp->ID==id && strcmp(temp->name,name)==0 && strcmp(temp->surname,surname)==0){
			if(temp->prev!=NULL){
				temp->prev->next=temp->next;
			}else{
				head=temp->next;
			}
			if(temp->next!=NULL){
				temp->next->prev=temp->prev;
			}
			free(temp);
			printf(" with id: ");
			(*check)=1;
			return head;
		}
		temp=temp->next;
	}
	printf(" with ID %d and name surname %s %s not found.\n", id,name,surname);
	return head;
}

KITAPODUNC* deletestudent2(KITAPODUNC *headkitapodunc, int id){
	printf("%d is deleted", id);
	KITAPODUNC *temp=headkitapodunc, *prev=NULL;

	while(temp!=NULL){
		if(temp->stdID==id){
			if(prev==NULL){
				headkitapodunc=temp->next;
				free(temp);
				temp=headkitapodunc;
			}else{
				prev->next=temp->next;
				free(temp);
				temp=prev->next;
			}
		}
		prev=temp;
		temp=temp->next;
	}
	return headkitapodunc;
}

KITAPLAR* deletestudent3(KITAPLAR* headkitaplar, int id){
	printf(" successfully \n");
	KITAPLAR *temp;
	KITAPORNEKLERI *current;
	int i;
	
	temp=headkitaplar;
	while(temp!=NULL){
		current=temp->kitapdurumu;
		while(current!=NULL){
			if(current->ogrenciID==id){
				strcpy(current->Rafta,"Rafta");
			}
			current=current->next;
		}
		temp=temp->next;
	}
	return headkitaplar;
}

int idstd(OGRENCILER* headogrenciler){
	OGRENCILER* temp=headogrenciler;
	char name[20], surname[20], tempname[20], tempsurname[20];
	int m,n; 
	
	printf("Enter name: ");
	scanf("%s", name);
	printf("Enter surname: ");
	scanf("%s", surname);
	strcpy(tempname,temp->name);
	strcpy(tempsurname,temp->surname);
	m=strcmp(tempname,temp->name);
	n=strcmp(tempsurname,temp->surname);
	
	while(temp!=NULL){
		if(m==0 && n==0){
			printf("Student found");
			return temp->ID;
		}
		temp=temp->next;
	}
	return 0;
}

void viewallstdinfo(OGRENCILER* headogrenciler,KITAPODUNC* headkitapodunc,KITAPLAR* headkitaplar, int id){
	OGRENCILER* temp=headogrenciler;
	KITAPODUNC* temp2=headkitapodunc;
	KITAPLAR *temp3=headkitaplar;
	int flag=0;
	char name[20], surname[20];
	
	while(temp!=NULL && flag==0){
		if(temp->ID==id){
			flag=1;
			printf("Student name surname: %s %s\nGrade: %d\n", temp->name, temp->surname, temp->grade);
			while(temp2!=NULL){
				if(temp2->stdID==id){
					temp3=headkitaplar;
					while(temp3!=NULL){
						if(temp3->ISBN==temp2->ISBN){
							if(temp2->durumu==0){
								printf("Student Borrow book %s of ISBN: %lld (book count %d) at %2d,%2d,%4d\n",temp3->name,temp2->ISBN, temp2->ISBNnumber,temp2->day,temp2->month,temp2->year);
							} else if(temp2->durumu==1){
								printf("Student Returned book %s of ISBN: %lld (book count %d) at %2d,%2d,%4d\n",temp3->name,temp2->ISBN, temp2->ISBNnumber,temp2->day,temp2->month,temp2->year);
							}
						}
						temp3=temp3->next;
					}
				}
				temp2=temp2->next;
			}
		}
		temp=temp->next;
	}
	if(flag==0){
		printf("Student with id: %d is not found",id);
	}
}

void updatestudent(OGRENCILER **headogrenciler){
	int id, flag=0, choice;
	char name[20], surname[20];
	OGRENCILER *temp = *headogrenciler;
	printf("Enter id of the student: ");
	scanf("%d",&id);
	while(temp!=NULL && flag==0){
		if(temp->ID==id){
			printf("OLD INFORMATION: Name: %s ; Surname: %s \n",temp->name,temp->surname);
			do{
				printf("Do you want to change name? (1: yes -1: no) ");
				scanf("%d",&choice);
			}while(choice!=1 && choice!=-1);
			if(choice==1){
				printf("Enter new name: ");
				scanf("%s",temp->name);
			}
			do{
				printf("Do you want to change surname? (1: yes -1: no)  ");
				scanf("%d",&choice);
			}while(choice!=1 && choice!=-1);
			if(choice==1){
				printf("Enter new name: ");
				scanf("%s",temp->surname);
			}
			flag=1;
		}
		temp=temp->next;
	}
	if(flag==0){
		printf("person with id: %d is not found", id);
	}
}

void didntreturnbooks(KITAPODUNC *headkitapodunc,OGRENCILER *headogrenciler){
	int number=0,flag=0;
	KITAPODUNC* temp = headkitapodunc;
	OGRENCILER* temp2 = headogrenciler;

	while(temp!=NULL){
		flag=0;
		if(temp->durumu==0){
			temp2 = headogrenciler;
			while(temp2!=NULL && flag==0){
				if(temp2->ID==temp->stdID){
					printf("Name: %s \t\t Surname: %s \t\t ID: %d \n", temp2->name, temp2->surname, temp2->ID);
					flag++;
					number++;
				}
				temp2=temp2->next;
			}
		}
		temp=temp->next;
	}
	if(number==0){
		printf("All students returned books");
	}
}

void penaltizedstds(OGRENCILER *headogrenciler){
	int number=0;
	OGRENCILER* temp = headogrenciler;
	while(temp!=NULL){
		if(temp->grade<0){
			printf("Name: %s \t\t Surname: %s \t\t ID: %d \n", temp->name, temp->surname, temp->ID);
			number++;
		}
		temp=temp->next;
	}
	if (number!=0){
		printf("Total %d student(s) is/are penaltized",number);
	} else{
		printf("Their are penaltized student ");
	}
}

void liststudents(OGRENCILER *headogrenciler){
	OGRENCILER* temp = headogrenciler;
	while(temp!=NULL){
		printf("Name & Surname: %s %s \nID: %d\nGrade%d \n\n", temp->name, temp->surname, temp->ID, temp->grade);
		temp=temp->next;
	}
}

void borrowbook(OGRENCILER* headogrenciler, KITAPLAR* headkitaplar, KITAPODUNC** headkitapodunc){
	OGRENCILER* temp=headogrenciler;
	KITAPLAR *temp2=headkitaplar;
	KITAPODUNC *temp3=*headkitapodunc, *newborrow=NULL;
	KITAPORNEKLERI *temp4;
	int id, flag=0, day, month, year, bookno, borrowing=0;
	long long int ISBN;

	printf("Enter id of student: ");
	scanf("%d",&id);

	while(temp!=NULL && flag==0){
		if(temp->ID==id){
			flag=1;
		}
		temp=temp->next;
	}

	if(flag==0){
		printf("Student with id %d is not found\n", id);
	} else{
		printf("Enter book ISBN that you need to borrow: ");
		scanf("%lld",&ISBN);
		printf("Enter book no: ");
		scanf("%d",&bookno);

		flag=0;
			while(temp2!=NULL && flag==0){
		if(temp2->ISBN==ISBN){
			if(bookno>temp2->number){
				printf("Book number %d not found in ISBN %lld\n",bookno,ISBN);
				flag=1;
			} else {
				temp4=temp2->kitapdurumu;
				while(temp4!=NULL){
					if(temp4->number==bookno){
						if(strcmp(temp4->Rafta,"Rafta")==0){
							newborrow=(KITAPODUNC*)malloc(sizeof(KITAPODUNC));
							if(newborrow==NULL){
								printf("Memory allocation failed\n");
								exit(-1);
							}
							finddate(&day, &month, &year);
							newborrow->durumu=0;
							newborrow->ISBNnumber=bookno;
							newborrow->stdID=id;
							newborrow->ISBN=ISBN;
							newborrow->day=day;
							newborrow->month=month;
							newborrow->year=year;
							newborrow->next=NULL;
							borrowing=1;
							flag=1;
							temp4->ogrenciID=id;
						} else {
							printf("This book is currently borrowed by another student.\n");
							flag=1;
						}
						break;
					}
					temp4=temp4->next;
				}
			}
		}
		temp2=temp2->next;
	}

	}

	if(borrowing==1){
		if(*headkitapodunc==NULL){
			*headkitapodunc=newborrow;
		} else{
			temp3=*headkitapodunc;
			while(temp3->next!=NULL){
				temp3=temp3->next;
			}
			temp3->next=newborrow; 
		}
		printf("Book successfully borrowed.\n");
	}
}

void finddate(int *day,int *month,int *year) {
	char dateStr[] = __DATE__;
	char monthStr[4];
	char dayStr[3];
	char yearStr[5];
	int i,j;

	monthStr[0]=dateStr[0];
	monthStr[1]=dateStr[1];
	monthStr[2]=dateStr[2];
	monthStr[3]='\0';

	if(strcmp(monthStr,"Jan")==0) *month=1;
	else if(strcmp(monthStr,"Feb")==0) *month=2;
	else if(strcmp(monthStr,"Mar")==0) *month=3;
	else if(strcmp(monthStr,"Apr")==0) *month=4;
	else if(strcmp(monthStr,"May")==0) *month=5;
	else if(strcmp(monthStr,"Jun")==0) *month=6;
	else if(strcmp(monthStr,"Jul")==0) *month=7;
	else if(strcmp(monthStr,"Aug")==0) *month=8;
	else if(strcmp(monthStr,"Sep")==0) *month=9;
	else if(strcmp(monthStr,"Oct")==0) *month=10;
	else if(strcmp(monthStr,"Nov")==0) *month=11;
	else if(strcmp(monthStr,"Dec")==0) *month=12;
	else *month=0;

	if(dateStr[4] == ' '){
		*day = dateStr[5] - '0';
	}
	else{
		*day = (dateStr[4]-'0')*10 + (dateStr[5]-'0');
	}

	*year = (dateStr[7]-'0')*1000 + (dateStr[8]-'0')*100 + (dateStr[9]-'0')*10 + (dateStr[10]-'0');
}

void returnbook(OGRENCILER** headogrenciler, KITAPLAR* headkitaplar,KITAPODUNC** headkitapodunc){
	OGRENCILER *temp=*headogrenciler;
	KITAPLAR *temp2=headkitaplar;
	KITAPODUNC* temp3 = *headkitapodunc, *returnbook;
	KITAPORNEKLERI *temp4=NULL;
	int id, no, day, year, month, flag=0, oldday, oldmonth, oldyear, difference;
	long long int ISBN;
	printf("Enter student id: ");
	scanf("%d",&id);
	printf("Enter ISBN: ");
	scanf("%lld", &ISBN);
	printf("Enter book no: ");
	scanf("%d",&no);
	
	while(temp3!=NULL && flag==0){
		if(temp3->stdID==id && temp3->durumu==0 && temp3->ISBN==ISBN && temp3->ISBNnumber==no){
			oldday=temp3->day;
			oldmonth=temp3->month;
			oldyear=temp3->year;
			flag=1;
		}
		temp3=temp3->next;
	}
	if(flag==0){
		printf("Their is no book borrowed with %lld_%d for %d student \n", ISBN,no,id);
	} else{
		returnbook=(KITAPODUNC*)malloc(sizeof(KITAPODUNC));
		if(returnbook==NULL){
			printf("No enough memory ");
			exit(-1);
		}
		finddate(&day, &month, &year);
		returnbook->day=day;
		returnbook->month=month;
		returnbook->year=year;
		returnbook->ISBN=ISBN;
		returnbook->durumu=1;
		returnbook->ISBNnumber=no;
		returnbook->stdID=id;
		returnbook->next==NULL;
		temp3=*headkitapodunc;
		if(*headkitapodunc==NULL){
			*headkitapodunc=temp3;
		} else{
			while(temp3->next!=NULL){
				temp3=temp3->next;
			}
			temp3->next=returnbook;
		}
	}
	if(flag=1){
		temp2=headkitaplar;
		while(temp2!=NULL){
			temp4=temp2->kitapdurumu;
			while(temp4!=NULL && flag==1){
				if(temp4->ISBN==ISBN && temp4->number==no && temp4->ogrenciID==id){
					flag=0;
					strcpy(temp4->Rafta,"Rafta");
				}
				temp4=temp4->next;
			}
			temp2=temp2->next;
		}
	}
	
	difference = variation(day,month,year,oldday,oldmonth,oldyear);
	if(difference>15){
		temp=*headogrenciler;
		while(temp!=NULL){
			if(temp->ID==id){
				temp->grade=temp->grade-10;
			}
			temp=temp->next;
		}
	}
}

int variation(int day,int month,int year,int oldday,int oldmonth,int oldyear) {
	int daysInMonth[12]={31,28,31,30,31,30,31,31,30,31,30,31};
	int i;
	int total1=0;
	int total2=0;
	int leap;

	total1=oldday+(oldyear*365)+(oldyear/4)-(oldyear/100)+(oldyear/400);
	for(i=0;i<oldmonth-1;i++) {
		total1=total1+daysInMonth[i];
		if(i==1) { 
			leap=0;
			if(oldyear%4==0) {
				if(oldyear%100!=0) {
					leap=1;
				} else {
					if(oldyear%400==0) {
						leap=1;
					}
				}
			}
			if(leap==1) {
				total1=total1+1;
			}
		}
	}

	total2=day+(year*365)+(year/4)-(year/100)+(year/400);
	for(i=0;i<month-1;i++) {
		total2=total2+daysInMonth[i];

		if(i==1) {
			leap=0;
			if(year%4==0) {
				if(year%100!=0) {
					leap=1;
				} else {
					if(year%400==0) {
						leap=1;
					}
				}
			}
			if(leap==1) {
				total2=total2+1;
			}
		}
	}

	return total2-total1;
}

void addbook(KITAPLAR **headkitaplar){
	KITAPLAR *temp=*headkitaplar, *newbook;
	KITAPORNEKLERI *current;
	long long int ISBN;
	int flag=0, number, i;
	char name[20];
	printf("Enter book ISBN No: ");
	scanf("%lld",&ISBN);
	while(temp!=NULL && flag==0){
		if(temp->ISBN==ISBN){
			flag=1;
			printf("The ISBN you entered already exists ");
		}
		temp=temp->next;
	}
	
	if(flag==0){
		printf("Enter books name: ");
		scanf(" %[^\n]", name);
		printf("how many books are there: ");
		scanf("%d",&number);
		
		newbook=(KITAPLAR*)malloc(sizeof(KITAPLAR));
		if(newbook==NULL){
			printf("No enough memory");
			exit(-1);
		}
		newbook->ISBN=ISBN;
		newbook->number=number;
		strcpy(newbook->name,name);
		newbook->next=NULL;
		newbook->kitapdurumu=(KITAPORNEKLERI*)malloc(sizeof(KITAPORNEKLERI));
		current=newbook->kitapdurumu;
		
		if(*headkitaplar==NULL){
			*headkitaplar=newbook;
		}else{
			temp=*headkitaplar;
			while(temp->next!=NULL){
				temp=temp->next;
			}
			temp->next=newbook;
		}
		
		for(i=0;i<number;i++){
			current->ISBN=ISBN;
			current->number=i+1;
			strcpy(current->Rafta,"Rafta");
			if(i<number-1){
				current->next=(KITAPORNEKLERI*)malloc(sizeof(KITAPORNEKLERI));
				current=current->next;
			}else{
				current->next=NULL;
			}
		}
	}
}

void deletebook(KITAPLAR** headkitaplar, KITAPYAZAR *kitapyazar, int *kitapyazarno, KITAPODUNC **headkitapodunc){
	KITAPLAR *temp=*headkitaplar, *prev=NULL;
	KITAPORNEKLERI *temp2, *next2;
	KITAPODUNC *temp3 = *headkitapodunc,*prev3, *next3;
	KITAPYAZAR *temp4;
	long long int ISBN;
	char name[20];
	int i, number, flag=0,j;
	printf("Enter ISBN no: ");
	scanf("%lld", &ISBN);
	printf("Enter book name: ");
	scanf(" %[^\n]", name);
	printf("Enter how many book are: ");
	scanf("%d",&number);
	
	while(temp!=NULL && flag==0){
		if(temp->ISBN==ISBN && temp->number==number && strcmp(temp->name,name)==0){
			printf("The book ");
			flag=1;
			temp2=temp->kitapdurumu;
			while(temp2!=NULL){
				next2=temp2->next;
				free(temp2);
				temp2=next2;
			}

			if(prev==NULL){
				*headkitaplar=temp->next;
			}else{
				prev->next=temp->next;
			}
			free(temp);
		}else{
			prev=temp;
			temp=temp->next;
		}
	}
	
	if(flag==1){
		printf("is deleted ");
		for(i=0;i<*kitapyazarno;i++){
			if(kitapyazar[i].ISBN==ISBN){
				for(j=i;j<*kitapyazarno-1;j++){
					kitapyazar[j]=kitapyazar[j+1];
				}
				(*kitapyazarno)--;
				kitapyazar=(KITAPYAZAR*)realloc(kitapyazar,(*kitapyazarno)*sizeof(KITAPYAZAR));
				if(kitapyazar==NULL && *kitapyazarno>0){
					printf("Memory reallocation error after deleting KITAPYAZAR element.\n");
					exit(-1);
				}
				i--;
			}
		}		
	}

	if(flag==1){
		temp3=*headkitapodunc;
			prev3=NULL;
			while(temp3!=NULL){
				next3=temp3->next;
				if(temp3->ISBN==ISBN){
					if(prev3==NULL){
						*headkitapodunc=next3;
					}else{
						prev3->next=next3;
					}
					free(temp3);
				}else{
					prev3=temp3;
				}
				temp3=next3;
		}	
	}

	if(flag==0){
		printf("Book not found.\n");
	}
}

void updatebook(KITAPLAR **headkitaplar){
	KITAPLAR* temp=*headkitaplar;
	KITAPORNEKLERI* temp2, *newcopy, *tail;
	int newnumber, flag=0, choice, i, diff, maxcopy, tailfound;
	long long int ISBN;

	printf("Enter book ISBN: ");	
	scanf("%lld",&ISBN);
	
	while(temp!=NULL && flag==0){
		if(temp->ISBN==ISBN){
			flag=1;
			printf("OLD INFORMATION: Book name: %s ; Book count: %d\n",temp->name,temp->number);
			
			do{
				printf("Do you want to change name? (1: yes -1: no): ");
				scanf("%d",&choice);
			}while(choice!=1 && choice!=-1);
			
			if(choice==1){
				printf("Enter new name: ");
				scanf("%s",temp->name);
			}
			
			do{
				printf("Do you want to change book number? (1: yes -1: no): ");
				scanf("%d",&choice);
			}while(choice!=1 && choice!=-1);
			
			if(choice==1){
				printf("Enter new book count: ");
				scanf("%d",&newnumber);
				
				if(newnumber>temp->number){
					diff=newnumber-temp->number;

					tail=temp->kitapdurumu;
					maxcopy=0;
					tailfound=0;

					while(tail!=NULL && tailfound==0){
						if(tail->number>maxcopy){
							maxcopy=tail->number;
						}
						if(tail->next==NULL){
							tailfound=1;
						}else{
							tail=tail->next;
						}
					}

					for(i=1;i<=diff;i++){
						newcopy=(KITAPORNEKLERI*)malloc(sizeof(KITAPORNEKLERI));
						if(newcopy==NULL){
							printf("Memory allocation failed!\n");
							return;
						}
						newcopy->ISBN=temp->ISBN;
						newcopy->number=maxcopy+i;
						strcpy(newcopy->Rafta,"RAFTA");
						newcopy->next=NULL;

						if(tail==NULL){
							temp->kitapdurumu=newcopy;
							tail=newcopy;
						}else{
							tail->next=newcopy;
							tail=newcopy;
						}
					}
					
					temp->number=newnumber;

				}else if(newnumber<temp->number){
					diff=temp->number-newnumber;

					i=0;
					while(i<diff){
						temp2=temp->kitapdurumu;
						if(temp2!=NULL){
							temp->kitapdurumu=temp2->next;
							free(temp2);
							i=i+1;
						}else{
							printf("No more copies to remove.\n");
							i=diff;
						}
					}

					temp->number=newnumber;
				}
			}
		}
		if(flag==0){
			temp=temp->next;
		}
	}
	if(flag==1){
		printf("Book updated successfully");
	} else{
		printf("Book doesn't exist ");
	}
}

void viewbook(KITAPLAR *headkitaplar, OGRENCILER *headogrenciler, KITAPYAZAR *kitapyazar, int kitapyazarno, YAZARLAR *headyazarlar){
	KITAPLAR *temp=headkitaplar;
	OGRENCILER *temp2;
	YAZARLAR *temp3=headyazarlar;
	KITAPORNEKLERI *temp1;
	long long int ISBN;
	int flag=0,i;
	
	printf("Enter ISBN: ");
	scanf("%lld",&ISBN);
	while(temp!=NULL && flag==0){
		if(temp->ISBN==ISBN){
			flag=1;
			printf("Book name: %s \nBook Count: %d\n",temp->name,temp->number);
			temp1=temp->kitapdurumu;
			while(temp1!=NULL){
				if(temp1->ogrenciID>=10000000 && temp1->ogrenciID<=99999999){
					temp2=headogrenciler;
					while(temp2!=NULL){
						if(temp1->ogrenciID==temp2->ID){
							printf("Borrowed by student: %s %s of id: %d  \n", temp2->name,temp2->surname,temp2->ID);
						}
						temp2=temp2->next;
					}
				}
				temp1=temp1->next;
			}
		}
		temp=temp->next;
	}
	if (flag==1){
		for(i=0;i<kitapyazarno;i++){
			if(kitapyazar[i].ISBN==ISBN){
				temp3=headyazarlar;
				while(temp3!=NULL){
					if(temp3->yazarID==kitapyazar[i].ID){
						printf("The book is written by Author %s %s (of id %d)\n", temp3->name, temp3->surname, temp3->yazarID);
					}
					temp3=temp3->next;
				}
			}
		}
	}
	if(flag==0){
		printf("Book with ISBN %lld is not found ", ISBN);
	}
}

void listbooksonshelf(KITAPLAR *headkitaplar){
	KITAPLAR* temp=headkitaplar;
	KITAPORNEKLERI *temp2;
	int flag=0;
	printf("BOOKS ON SHELF:");
	while(temp!=NULL){
		flag=0;
		printf("\nBook Name: %s ",temp->name);
		temp2=temp->kitapdurumu;
		while(temp2!=NULL){
			if(strcmp(temp2->Rafta,"Rafta")==0){
				printf("\n%lld _ %d",temp2->ISBN,temp2->number);
				flag++;
			}
			temp2=temp2->next;
		}
		if(flag=0) printf("doesn't have any on shelves\n");
		temp=temp->next;
	}
}

void listbooksnotreturnedontime(KITAPODUNC *headkitapodunc){
	KITAPODUNC *temp1=headkitapodunc, *temp2=NULL;
	int flag=0;
	int day, month, year, oldday, oldmonth, oldyear;
	int difference;

	finddate(&day,&month,&year);

	while(temp1!=NULL){
		if(temp1->durumu==0){
			flag=0;
			temp2=headkitapodunc;
			while(temp2!=NULL){
				if(temp1->ISBN==temp2->ISBN && temp1->stdID==temp2->stdID && temp2->durumu==1){
					flag=1;
				}
				temp2=temp2->next;
			}

			if(flag==0){
				oldday=temp1->day;
				oldmonth=temp1->month;
				oldyear=temp1->year;
				difference=variation(day,month,year,oldday,oldmonth,oldyear);

				if(difference>15){
					printf("Book ISBN: %lld_%d; Borrowed Date: %02d/%02d/%04d by student: %d\n",temp1->ISBN,temp1->ISBNnumber,temp1->day,temp1->month,temp1->year,temp1->stdID);
				}
			}
		}
		temp1=temp1->next;
	}
}

void matchbookandauthor(KITAPLAR* headkitaplar,YAZARLAR* headyazarlar, KITAPYAZAR *kitapyazar, int kitapyazarno ){
	KITAPLAR *temp=headkitaplar;
	YAZARLAR *temp2=headyazarlar;
	int i;
	
	while(temp!=NULL){
		for(i=0;i<kitapyazarno;i++){
			if(kitapyazar[i].ISBN==temp->ISBN){
				temp2=headyazarlar;
				while(temp2!=NULL){
					if(temp2->yazarID==kitapyazar[i].ID){
						printf("Book name: %s; \nISBN: %lld; \nAuthor name surname: %s %s; \nAuthor id: %d\n\n",temp->name,temp->ISBN,temp2->name,temp2->surname,temp2->yazarID);
					}
					temp2=temp2->next;
				}
			}
		}
		temp=temp->next;
	}
}

void updatebookauthor(KITAPLAR* headkitaplar,YAZARLAR* headyazarlar, KITAPYAZAR **kitapyazar,int *kitapyazarno){
	KITAPLAR *temp=headkitaplar;
	YAZARLAR *temp2=headyazarlar;
	int i, flag=0, newauthor=0, choice=0, deleteID, j, newid;
	long long int ISBN;
	char name[20];
	
	printf("Enter book name: ");
	scanf(" %[^\n]", name);
	
	while(temp!=NULL && flag==0){
		if(strcmp(temp->name,name)==0){
			flag=1;
			ISBN=temp->ISBN;
		}
		temp=temp->next;
	}
	
	if(flag==0){
		printf("Book not found ");
	}
	else{
		printf("Current Authors \n");
		for(i=0;i<*kitapyazarno;i++){
			if((*kitapyazar)[i].ISBN==ISBN){
				temp2=headyazarlar;
				while(temp2!=NULL){
					if(temp2->yazarID==(*kitapyazar)[i].ID){
						printf("Author: %s %s; id: %d\n",temp2->name, temp2->surname, (*kitapyazar)[i].ID);
					}
					temp2=temp2->next;
				}
			}
		}
		do{
			printf("Add new authors (1), delete authors (2), change current authors (3): ");
			scanf("%d",&choice);
		}while(choice!=1 && choice!=2 && choice!=3);
		if(choice==1){
			printf("How many authors will you add? ");
			scanf("%d",&newauthor);
			*kitapyazarno = *kitapyazarno+newauthor;
			(*kitapyazar)=(KITAPYAZAR*)realloc(*kitapyazar,(*kitapyazarno) * sizeof(KITAPYAZAR));
			for(i=*kitapyazarno-newauthor;i<*kitapyazarno;i++){
				printf("Enter author id ");
				(*kitapyazar)[i].ISBN=ISBN;
				scanf("%d",&newid);
				(*kitapyazar)[i].ID=newid;
			}
		}else if(choice==2){
			printf("Enter the author ID to delete: ");
			scanf("%d",&deleteID);
			
			i=0;
			while(i<*kitapyazarno&&flag==1){
				if((*kitapyazar)[i].ISBN==ISBN && (*kitapyazar)[i].ID==deleteID){
					for(j=i;j<*kitapyazarno-1;j++){
						(*kitapyazar)[j]=(*kitapyazar)[j+1];
					}
					(*kitapyazarno)--;
					*kitapyazar=(KITAPYAZAR*)realloc(*kitapyazar, (*kitapyazarno)*sizeof(KITAPYAZAR));
					printf("Author with ID %d removed from book '%s'.\n", deleteID, name);
					flag=0;
				}
				i++;
			}
			if(flag==1){
				printf("Author with ID %d is not associated with this book.\n", deleteID);
			}
		} else if(choice==3){			
			for(i=0;i<*kitapyazarno;i++){
				if((*kitapyazar)[i].ISBN==ISBN){
					printf("Current author ID: %d\n", (*kitapyazar)[i].ID);
					printf("Enter new author ID: ");
					scanf("%d", &newid);
					(*kitapyazar)[i].ID=newid;
				}
			}
			printf("Author information successfully updated for book '%s'.\n", name);
		}

	}
}

void addauthor(YAZARLAR** headyazarlar){
	YAZARLAR* temp=*headyazarlar;
	YAZARLAR *newauthor=(YAZARLAR*)malloc(sizeof(YAZARLAR));
	if(newauthor==NULL){
		printf("No enough memory to add \n");
		return;
	}
	char name[20], surname[20];

	printf("Enter name: ");
	scanf("%s",name);
	printf("Enter surname: ");
	scanf("%s",surname);
	
	newauthor->next=NULL;
	strcpy(newauthor->name,name);
	strcpy(newauthor->surname,surname);

	if(temp==NULL){
		newauthor->yazarID=1;
		*headyazarlar=newauthor;
	} else{
		temp=*headyazarlar;
		while(temp->next!=NULL){
			temp=temp->next;
		}
		newauthor->yazarID=temp->yazarID+1;
		temp->next=newauthor;
	}
}

void deleteauthor(YAZARLAR **headyazarlar,KITAPYAZAR *kitapyazar,int kitapyazarno){
	YAZARLAR *temp = *headyazarlar, *prev = NULL;
	int i,id, flag=0;
	char name[20], surname[20];
	
	printf("Enter id: ");
	scanf("%d",&id);
	printf("Enter name: ");
	scanf("%s",name);
	printf("Enter surname: ");
	scanf("%s",surname);
	
	while(temp!=NULL && flag==0){
		if(temp->yazarID==id && (strcmp(name,temp->name)==0 ) && (strcmp(surname,temp->surname)==0)){
			if(prev==NULL){
				*headyazarlar=temp->next;
			} else{
				prev->next = temp->next;
			}
			free(temp);
			flag=1;
			printf("The author is deleted successfully");
		}
		prev=temp;
		temp=temp->next;
	}
	if(flag==0){
		printf("Author didn't found");
	} else{
		for(i=0;i<kitapyazarno;i++){
			if(kitapyazar[i].ID==id){
				kitapyazar[i].ID=-1;
			}
		}
	}
}

void updateauthor(YAZARLAR **headyazarlar){
	YAZARLAR *temp=*headyazarlar;
	int id, flag=0;
	printf("Enter id of author: ");
	scanf("%d",&id);
	while(temp!=NULL && flag==0){
		if(temp->yazarID==id){
			flag=1;
			printf("Enter new name: ");
			scanf("%s",temp->name);
			printf("Enter new surname: ");
			scanf("%s",temp->surname);
		}
		temp=temp->next;
	}
	if(flag==0){
		printf("Author wil id: %d is not found",id);
	}
}

void viewauthorinfo(YAZARLAR *headyazarlar, KITAPYAZAR *kitapyazar, int kitapyazarno,KITAPLAR* headkitaplar){
	YAZARLAR* temp=headyazarlar;
	KITAPLAR *temp2 = NULL;
	int id, flag=0,i;
	printf("Enter id ");
	scanf("%d",&id);
	while(temp!=NULL && flag==0){
		if(temp->yazarID==id){
			flag=1;
			printf("Author name surname: %s %s \n",temp->name,temp->surname);
			for(i=0;i<kitapyazarno;i++){
				temp2 = headkitaplar;
				while(temp2!=NULL){
					if(temp2->ISBN==kitapyazar[i].ISBN && kitapyazar[i].ID==temp->yazarID){
						printf("Book: %s of ISBN: %lld \n", temp2->name, kitapyazar[i].ISBN);
					}
					temp2=temp2->next;
				}
			}
		}
		temp=temp->next;
	}
}

void saveList(void* head, void (*saveFunction)(void*)) {
	(*saveFunction)(head);
}

void saveyazarlar(void* head) {
	FILE *file;
	YAZARLAR *temp=(YAZARLAR*)head;

	file=fopen("Yazarlar.csv","w");
	if(file==NULL){
		printf("Can't open file\n");
		exit(-1);
	}
	while(temp!=NULL) {
		fprintf(file,"%d,%s,%s\n", temp->yazarID, temp->name, temp->surname);
		temp=temp->next;
	}
	fclose(file);
	printf("Yazarlar.csv is saved\n");
}

void saveogrenciler(void* head) {
	FILE* file;
	OGRENCILER* temp=(OGRENCILER*)head;

	file=fopen("Ogrenciler.csv","w");
	if(file==NULL) {
		printf("Can't open file\n");
		exit(-1);
	}
	while(temp!=NULL) {
		fprintf(file,"%d,%s,%s,%d\n",temp->ID,temp->name,temp->surname,temp->grade);
		temp=temp->next;
	}
	fclose(file);
	printf("Ogrenciler.csv is saved\n");
}

void savekitapodunc(void* head) {
	FILE* file;
	KITAPODUNC* temp=(KITAPODUNC*)head;

	file=fopen("KitapOdunc.csv","w");
	if(file==NULL) {
		printf("Can't open file\n");
		exit(-1);
	}
	while(temp!=NULL) {
		fprintf(file, "%lld_%d,%d,%d,%02d.%02d.%d\n", 
			temp->ISBN, temp->ISBNnumber, temp->stdID, 
			temp->durumu, temp->day, temp->month, temp->year);
		temp=temp->next;
	}
	fclose(file);
	printf("KitapOdunc.csv is saved\n");
}

void saveKitaplar(KITAPLAR* kitaplarList, char* filename){
	FILE* file;
	KITAPLAR* current;

	file=fopen(filename,"w");
	if(file==NULL){
		perror("Error opening Kitaplar.csv for writing");
		return;
	}

	current=kitaplarList;
	while(current!=NULL){
		fprintf(file,"%s,%lld,%d\n",current->name,current->ISBN,current->number);
		current=current->next;
	}
	printf("Kitaplar.csv is saved\n");
	fclose(file);
}

void saveKitapOrnekleri(KITAPLAR* kitaplarList,const char* filename){
	FILE* file;
	KITAPLAR* currentBook;
	KITAPORNEKLERI* currentStatus;

	file=fopen(filename,"w");
	if(file==NULL){
		perror("Error opening KitapOrnekleri.csv for writing");
		exit(-1);
	}

	currentBook=kitaplarList;
	while(currentBook!=NULL){
		currentStatus=currentBook->kitapdurumu;
		while(currentStatus!=NULL){
			fprintf(file,"%lld_%d,",currentStatus->ISBN,currentStatus->number);
			if(currentStatus->ogrenciID>=10000000 && currentStatus->ogrenciID<=999999999){
			
				fprintf(file,"%d\n",currentStatus->ogrenciID);
			} else{
				fprintf(file,"Rafta\n");
			}
			currentStatus=currentStatus->next;
		}
		currentBook=currentBook->next;
	}
	printf("KitapOrnekleri.csv is saved\n");
	fclose(file);
}

void savekitapyazar(KITAPYAZAR *head, int kitapyazarno){
	int i;
	FILE* file;
	KITAPYAZAR* temp=head;
	
	file=fopen("KitapYazar.csv","w");
	if(file==NULL) {
		printf("Can't open file \n");
		exit(-1);
	}

	for(i=0;i<kitapyazarno;i++){
		fprintf(file,"%lld,%d\n",temp[i].ISBN,temp[i].ID);
	}
	fclose(file);
	printf("KitapYazar.csv is saved\n");
}

void freeKitaplarList(KITAPLAR* kitaplarList){
	KITAPLAR *currentBook, *nextBook;
	KITAPORNEKLERI *currentStatus, *nextStatus;

	currentBook=kitaplarList;
	while(currentBook!=NULL){
		currentStatus=currentBook->kitapdurumu;
		while(currentStatus!=NULL){
			nextStatus=currentStatus->next;
			free(currentStatus);
			currentStatus=nextStatus;
		}

		nextBook=currentBook->next;
		free(currentBook);
		currentBook=nextBook;
	}
}

void freeYazarlar(YAZARLAR *head) {
	YAZARLAR *temp;
	while(head != NULL) {
		temp = head->next;
		free(head);
		head = temp;
	}
}

void freeOgrenciler(OGRENCILER *head) {
	OGRENCILER *temp;
	while(head != NULL) {
		temp = head->next;
		free(head);
		head = temp;
	}
}

void freeKitapOdunc(KITAPODUNC *head) {
	KITAPODUNC *temp;
	while(head != NULL) {
		temp = head->next;
		free(head);
		head = temp;
	}
}


