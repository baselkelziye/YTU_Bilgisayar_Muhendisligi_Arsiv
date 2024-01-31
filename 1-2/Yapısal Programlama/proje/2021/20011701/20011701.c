#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


typedef struct lectures{
	char lectID[10];
	char lectName[40];
	int credit; // dersin kredisi 
	int fullness; // kontenjan
	struct lectures *next;
	
}LECTURE;

typedef struct stdent{
	char stdentID[10];
	char stdentName[15];
	char stdentSurname[15];
	int sOfLect;
	int sOfCred;
	struct stdent *next;
	struct stdent *prev;
}STDENT;

typedef struct stdLectRec{
	char stdState[15];
	LECTURE lectInf; 
	STDENT stdentInf; 
	char date[15];
	struct stdLectRec *next;
}REC;

LECTURE* searchCourse(LECTURE *headL,char search[20]);
LECTURE *addCourse(LECTURE **headL);
void removeCourse(LECTURE **headL);
STDENT* searchStdent(STDENT *headS, char search[20]);
STDENT *addStudent(STDENT**headS);
STDENT *updateStdent(STDENT **headS);
LECTURE *adC(LECTURE *lectures,int *h2,char temp1[25]);
LECTURE *rmC(LECTURE *lectures,int *h2);
STDENT *adS(STDENT *stdents,int *h3);
STDENT *rmS(STDENT *stdents,int *h3,REC *records,int h4);
STDENT *upS(STDENT *stdents,int h3);
REC *adR(REC *records,int *h4,LECTURE *lectures,int h2,STDENT *stdents,int h3,int maxCredit,int maxLect);
REC *removeRec(REC *records,int h4,LECTURE *lectures,int h2,STDENT *stdents,int h3);
void prntStdent(REC *records,int h4,STDENT *stdents,int h3,char temp1[20]);
void printLect(REC *records,int h4,LECTURE *lectures,int h2,char temp1[20]);
int main()
{

	int chs;
	int chs3;
	int count;
	int maxCredit;
	int maxLect;
	int var=0;
	char chs2='b';
	int h=0, h2=0, h3=0,h4=0,e;
	LECTURE *headL=NULL;
	LECTURE *tmpL;
	STDENT  *headS;

	LECTURE *lectures;
	STDENT *stdents;
	REC *records;
	int temp, tmp2,tmp1;
	int d=0; int d2=0; int d3=0;
	printf("\n !!!  : Add lectures Students & record respectively..\n ");
	char temp1[20];
	char temp2[20];
	char temp3[20];
	char tempDosya[30];
	char stdentFile[15],lectFile[15],recFile[15];
	char bos;
	printf("\n\n Enter filename without txt..");

	printf("\n courses file : "); scanf("%s",lectFile);
	printf("\n students file : "); scanf("%s",stdentFile);
	printf("\n records file : "); scanf("%s",recFile); 
	strcat(stdentFile,".txt");  strcat(recFile,".txt");
	strcat(lectFile,".txt");
	printf("\n\n\t Max credit for one student: "); scanf("%d",&maxCredit);
	printf("\n\n\t Max course for one student : "); scanf("%d",&maxLect);
	FILE *fw;
	int i=0;
	printf("\n\n\n Enter number you want to do");
	while(chs!=6)
	{
		chs=0;
		printf("\n\n\n\n   1: Course operations    2: Student operations    3: Record operations    4: EXTRA  5: EXIT Choice :");
		scanf("%d",&chs);
		switch(chs)
		{
					
			case 1:
					
					chs2='b';

				while(chs2!='M' && chs2!='m')
				{
					
					printf("\n\n\tCourse:  Add(A)    Remove(R)    Back Menu (M)    Choice: ");
					scanf(" %c",&chs2);
					
					if(chs2=='A' || chs2=='a')
					{
							e=h2;
							d=0;
							while(e==h2)
							{
								 d=1;
								 lectures=adC(lectures,&h2,temp1);
							}
						fw=fopen(lectFile,"w");
						for(i=0;i<h2;i++)
						{
							fprintf(fw,"%s, %s, %d, %d\n",lectures[i].lectID,lectures[i].lectName,lectures[i].credit,lectures[i].fullness);
						}
						fclose(fw);
					}
					else if(chs2=='R' || chs2=='r')
					{
						e=h2;
							
						while(e==h2)
						{
							lectures=rmC(lectures,&h2);
						}
							
						fw=fopen(lectFile,"w");
						
						for(i=0;i<h2;i++)
						{
							fprintf(fw,"%s, %s, %d, %d\n",lectures[i].lectID,lectures[i].lectName,lectures[i].credit,lectures[i].fullness);
						}
						
						fclose(fw);
					}

					else if(chs2=='M' || chs2=='m')
					{
						printf("\n\n\t\t ------ ---- ------");
					}
					else
					{
						printf("\n\tERROR WRONG INPUT!..");
					}
				}
					break;
						
				case 2: 
					chs2='b';
					while(chs2!='M' && chs2!='m')
					{
						
						printf("\n\n\tStudents :  Add(A)    Remove(R)    Update(U)    Back Menu(M)   Choice: ");
						scanf(" %c",&chs2);
					
						
						if(chs2=='A' || chs2=='a')
						{
							e=h3;
							while(e==h3)
							{
								 stdents=adS(stdents,&h3);
							}
							
							fw=fopen(stdentFile,"w");
							for(i=0;i<h3;i++)
							{
								fprintf(fw,"%s, %s, %s, %d, %d\n",stdents[i].stdentID,stdents[i].stdentName,stdents[i].stdentSurname,stdents[i].sOfLect,stdents[i].sOfCred);
							}
							fclose(fw);
						}
						else if(chs2=='R' || chs2=='r')
						{
							e=h3;
							while(e==h3)
							{
								stdents=rmS(stdents,&h3,records,h4);
								
							}
							fw=fopen(recFile,"w");
							for(i=0;i<h4;i++)
							{
								fprintf(fw,"%s, %s, %s, %s\n",records[i].stdentInf.stdentID,records[i].lectInf.lectID,records[i].date,records[i].stdState);
							}
							fclose(fw);	
							fw=fopen(stdentFile,"w");
							for(i=0;i<h3;i++)
							{
								fprintf(fw,"%s, %s, %s, %d, %d\n",stdents[i].stdentID,stdents[i].stdentName,stdents[i].stdentSurname,stdents[i].sOfLect,stdents[i].sOfCred);
							}
							
						
							fclose(fw);
						}
						else if(chs2=='U' || chs2=='u')
						{
							stdents=upS(stdents,h3);
							fw=fopen(stdentFile,"w");
							for(i=0;i<h3;i++)
							{
								fprintf(fw,"%s, %s, %s, %d, %d\n",stdents[i].stdentID,stdents[i].stdentName,stdents[i].stdentSurname,stdents[i].sOfLect,stdents[i].sOfCred);
							}
							fclose(fw);
						}
					
						else if(chs2=='M' || chs2=='m')
						{
							printf("\n\n\t\t ------ ---- ------");
						}
						else
						{
							printf("\n\tUyari ! : ERROR WRONG INPUT!..");
						}
					}
						break;
						
				case 3: 
					chs2='b';
					if( h2==0 || h3==0)
					{
						printf("\n\n\n\t\tERROR  Record operations can not performed without adding Course-Student!\n");
						chs2='M';
					}
				
					while(chs2!='M' && chs2!='m')
					{
						
						printf("\n\n   Record Student  : Add(A)   Update(U)   Back Menu (M)  Choice : ");
						scanf(" %c",&chs2);
						
						if(chs2=='A' || chs2=='a')
						{
							e=h4;
							while(e==h4)
							{
								 records=adR(records,&h4,lectures,h2,stdents,h3,maxCredit,maxLect);
							}
							fw=fopen(stdentFile,"w");
							for(i=0;i<h3;i++)
							{
								fprintf(fw,"%s, %s, %s, %d, %d\n",stdents[i].stdentID,stdents[i].stdentName,stdents[i].stdentSurname,stdents[i].sOfLect,stdents[i].sOfCred);
							}
							fclose(fw);
							fw=fopen(recFile,"w");
							for(i=0;i<h4;i++)
							{
								fprintf(fw,"%s, %s, %s, %s\n",records[i].stdentInf.stdentID,records[i].lectInf.lectID,records[i].date,records[i].stdState);
							}
							fclose(fw);		
						}
						else if(chs2=='U' || chs2=='u')
						{
							records=removeRec(records,h4,lectures,h2,stdents,h3);
							fw=fopen(stdentFile,"w");
							for(i=0;i<h3;i++)
							{
								fprintf(fw,"%s, %s, %s, %d, %d\n",stdents[i].stdentID,stdents[i].stdentName,stdents[i].stdentSurname,stdents[i].sOfLect,stdents[i].sOfCred);
							}
							fclose(fw);
							fw=fopen(recFile,"w");
							for(i=0;i<h4;i++)
							{
								fprintf(fw,"%s, %s, %s, %s\n",records[i].stdentInf.stdentID,records[i].lectInf.lectID,records[i].date,records[i].stdState);
							}
							fclose(fw);	
						}
						else if(chs2=='M' || chs2=='m')
						{
							printf("\n\n\t\t ------ ---- ------");
						}
						else
						{
							printf("\n\tUyari ! : ERROR WRONG INPUT!..");
						}
					}
				
					chs2='b';
					
				break;
							
					
				case 4:
					
					while(chs3!=3)
					{
						
						printf("\n\n\t EXTRA ");
			
						printf("\n\n\t For see all students given a course ID (1) ");
						printf("\n\n\t For see all courses given a student ID (2) ");
						printf("\n\n\t\t\t\t Back Menu (3)\t\t\t\t\t\t ");
						scanf(" %d",&chs3);
						
						if(chs3==1)
						{
							temp1[0]='\0';
							count=0;
							printf("\n\n\t\t\t --- All Courses ---\n\n");
							for(i=0;i<h2;i++)
							{
								count++;
								printf("   ID: %s  Name: %s ",lectures[i].lectID,lectures[i].lectName);
								if(count%4==0)
								{
									printf("\n\n");
								}
							}
							printf("\n\n Course ID : ");
							scanf("%s",temp1);
							prntStdent(records,h4,stdents,h3,temp1);
							strcat(temp1,".txt");
							fw=fopen(temp1,"w");
							for(i=0;i<h2;i++)
							{
								fprintf(fw,"%s, %s, %s, %d, %d,\n",stdents[i].stdentID,stdents[i].stdentName,stdents[i].stdentSurname,stdents[i].sOfLect,stdents[i].sOfCred);
							}
							fclose(fw);
							
							printf("\n\n\t\t\t------  ------------------- ------ ");
							sleep(2);
						}
						else if(chs3==2)
						{
							temp1[0]='\0';
							count=0;
							printf("\n\n\t\t\t --- All Students ---\n\n");
							for(i=0;i<h3;i++)
							{
								count++;
								printf("   ID: %s  Name: %s %s ",stdents[i].stdentID,stdents[i].stdentName,stdents[i].stdentSurname);
								if(count%4==0)
								{
									printf("\n\n");
								}
							}
							printf("\n\n Student ID : ");
							scanf("%s",temp1);
							for(i=0;i<h;i++)
							{
								if(strcmp(stdents[i].stdentID,temp1)==0)
								{
									printf("\n\n Student ID : %s   %s %s \n",stdents[i].stdentID,stdents[i].stdentName,stdents[i].stdentSurname);							
								}							
							}
							printLect(records,h4,lectures,h2,temp1);
							
							strcat(temp1,".txt");
							fw=fopen(temp1,"w");
							for(i=0;i<h3;i++)
							{
								fprintf(fw,"%s, %s\n",lectures[i].lectID,lectures[i].lectName);
							}
							fclose(fw);
							printf("\n\n\t\t\t------  ------------------- ------ ");
							sleep(2);
						}

						else if(chs3==3)
						{
							printf("\n\n\n\t\t\t\t ------------- ---- -------------");
						}
						
					
					}
						break;
						
						default:
						break;
		}
	}
	return 0;
}

STDENT* searchStdent(STDENT *headS, char search[20]){
	STDENT *tmp;
	STDENT *prev=NULL;
	tmp=headS;
	while(strcmp(tmp->stdentID,search)>0){
		prev=tmp;
		tmp->prev=prev;
		tmp=tmp->next;
		
	}
	if(strcmp(tmp->stdentID,search)==0){
		return	0;
	}else{
		return tmp;
	}
	
}

LECTURE* searchCourse(LECTURE *headL,char search[20]){
	LECTURE *tmp;
	tmp=headL;
	while(tmp!= NULL){
		if(strcmp(tmp->lectID,search)==0){
			printf("\n\n\t\t The course ID you entered is not available. Enter another ID \n ");
		}
		tmp = tmp->next;
	}	
	return tmp;
}


LECTURE* addCourse(LECTURE **headL){
	LECTURE *tmp;
	char lectureID[20];
	printf("\n\tCourse ID : "); scanf("%s",lectureID);
	
	tmp = searchCourse(*headL, lectureID);
	if(tmp==NULL){
		tmp = (LECTURE*) malloc(sizeof(LECTURE));
	
		strcpy(tmp->lectID,lectureID);
		printf("\n\tCourse name: "); scanf("%s",&tmp->lectName);
		printf("\n\tCredit: "); scanf("%d",&tmp->credit);
		printf("\n\tFullness: "); scanf("%d",&tmp->fullness);
		tmp->next=*headL;
		*headL=tmp;
		}
	else{
		printf("\n\n\t\t The course ID you entered is not available. Enter another ID \n ");
	}	
	return *headL;
}

void removeCourse(LECTURE **headL){
	char rem1[20];
	printf("\n\n Corse ID: ");		
	scanf("%s",rem1);
	
	LECTURE *tmp, *current;
	if(strcmp((*headL)->lectID,rem1)==0){
		tmp = *headL;
		*headL = (*headL)->next;
		free(tmp);
		printf("%s removed",rem1);
	}
	else{
		current=*headL;
		while(current->next!=NULL ){
			if(strcmp(current->lectID,rem1)==0){
				tmp = current->next;
				current->next=current->next->next;
				free(tmp);
				printf("%s removed",rem1);
			}
			current = current->next;
		}
		
	}
}

		
LECTURE *adC(LECTURE *lectures,int *h2,char temp1[20])
{
	char tempID[20];
	char e;
	int i;
	if(*h2==0)
	{
		(*h2)++;
		lectures=(LECTURE*)malloc((*h2)*sizeof(LECTURE));
		printf("\n\tCourse ID for add: "); scanf("%s",lectures[(*h2)-1].lectID);
		scanf("%c",&e);
		printf("\tCourse Name    : "); gets(lectures[(*h2)-1].lectName);	
		printf("\tCredit    : "); scanf("%d",&lectures[(*h2)-1].credit);
		printf("\tFullness : "); scanf("%d",&lectures[(*h2)-1].fullness);
		return lectures;
	}
	else
	{
		tempID[0]='\0';
		printf("\n\tCourse ID  for add: "); 
		scanf("%s",tempID);
		for(i=0;i<*h2;i++)
		{
			if(strcmp(lectures[i].lectID,tempID)==0) 
			{
				printf("\n\n\t\t The course ID you entered is not available. Enter another ID \n ");
				return lectures;				
			}
		}
		(*h2)++;
		lectures=(LECTURE*)realloc(lectures,(*h2)*sizeof(LECTURE));
//		strcpy(lectures[(*h2)-1].dershoca.hocaID,temp1);
		strcpy(lectures[(*h2)-1].lectID,tempID);
		scanf("%c",&e);
		printf("\tCourse ID for add: "); gets(lectures[(*h2)-1].lectName);	
		printf("\tCredit    : "); scanf("%d",&lectures[(*h2)-1].credit);
		printf("\tFullness : "); scanf("%d",&lectures[(*h2)-1].fullness);
		return lectures;
	}
}	
	
LECTURE *rmC(LECTURE *lectures,int *h2)
{
	
	
	int j,i;
	char tempID[20];
	tempID[0]='\0';
	printf("\n\n course ID for remove : ");		
	scanf("%s",tempID);

	for(i=0;i<*h2;i++)			
	{
		if(strcmp(lectures[i].lectID,tempID)==0) 
		{
			if(i==*h2-1){
				(*h2)--;
				lectures=(LECTURE*)realloc(lectures,(*h2)*sizeof(LECTURE));
				printf("\n\n\t\t\t Course ID :  %s  removed..",tempID);
				return lectures;
			}
			
			else
			{
								
				for(j=i;j<*h2-1;j++) 
				{
					strcpy(lectures[j].lectName,lectures[j+1].lectName);
					strcpy(lectures[j].lectID,lectures[j+1].lectID);
					lectures[j].credit=lectures[j+1].credit;
					lectures[j].fullness=lectures[j+1].fullness;
				}	
			}
			(*h2)--;
			lectures=(LECTURE*)realloc(lectures,(*h2)*sizeof(LECTURE));
			printf("\n\n\t\t\t Course ID:  %s  removed..",tempID);
			return lectures;
		}
	}
					
		printf("\n\n\t\t\t There is no Course ID :  %s ..",tempID);			
		return lectures;
}

STDENT *addStudent(STDENT **headS){
	STDENT *tmp;
	tmp=*headS;
	char stdentID[20];
	printf("\n\tCourse ID : "); scanf("%s",stdentID);
	
	if(headS==NULL){
		tmp = (STDENT*) malloc(sizeof(STDENT));
	
		strcpy(tmp->stdentID,stdentID);
		printf("\n\tStudent Name: "); scanf("%s",&tmp->stdentName);
		printf("\n\tStudent Surname "); scanf("%s",&tmp->stdentSurname);
		printf("\tStudent Courses : 0  ");
		printf("\tStudent Credit: 0 	\n");
		
		tmp->next=NULL;
		tmp->prev=*headS;
		*headS=tmp;
		}
	else{
		STDENT *tmp1;
		STDENT *tmp2;
		tmp2=*headS;
		tmp2=searchStdent(tmp2,stdentID);
		if(tmp2==0){
			printf("\n\n\t\t\t\t\t The student ID you entered is not available. Enter another ID \n ");
		}else{
			tmp1 = (STDENT*) malloc(sizeof(STDENT));
			strcpy(tmp1->stdentID,stdentID);//
			printf("\n\tStudent Name: "); scanf("%s",&tmp1->stdentName);
			printf("\n\tStudent Surname "); scanf("%s",&tmp1->stdentSurname);
			printf("\tStudent Courses : 0  ");
			printf("\tStudent Credit: 0 	\n");
		
		tmp1->next=tmp2;
		tmp2->prev=tmp1;
			
		}
		
	}
		
	return *headS;
	
}


STDENT *adS(STDENT *stdents,int *h3)
{
	char tempID[15];
	int i;
	if(*h3==0) 
	{
		(*h3)++;
		stdents=(STDENT*)malloc((*h3)*sizeof(STDENT));
		printf("\n\tStudent ID      : "); scanf("%s",stdents[(*h3)-1].stdentID);
		printf("\tStudent Name      : "); scanf("%s",stdents[(*h3)-1].stdentName);	
		printf("\tStudent Surname   : "); scanf("%s",stdents[(*h3)-1].stdentSurname);
		printf("\tStudent Courses : 0  ");
		printf("\tstudent Credit: 0 	\n");
		stdents[(*h3)-1].sOfCred=0;
		stdents[(*h3)-1].sOfLect=0;
		return stdents;
	}
	else
	{
		tempID[0]='\0';
		printf("\n\tStudent ID     : ");
		scanf("%s",tempID);
		
		for(i=0;i<*h3;i++)
		{
			if(strcmp(stdents[i].stdentID,tempID)==0) 
			{
				printf("\n\n\t\t The student ID you entered is not available. Enter another ID: \n ");
				return stdents;				
			}
		}
		(*h3)++;
		stdents=(STDENT*)realloc(stdents,(*h3)*sizeof(STDENT));
		strcpy(stdents[*h3-1].stdentID,tempID);
		printf("\tStudent Name      : "); scanf("%s",stdents[(*h3)-1].stdentName);	
		printf("\tStudent Surname    : "); scanf("%s",stdents[(*h3)-1].stdentSurname);
		printf("\tStudent Courses : 0  ");
		printf("\tStudent Credit: 0 	\n");
		stdents[(*h3)-1].sOfCred=0;
		stdents[(*h3)-1].sOfLect=0;
		
		return stdents;
	}
}

void *removeStdent(STDENT **headS){
	char rem1[20];
	printf("\n\n Student ID: ");		
	scanf("%s",rem1);
	
	STDENT *prev, *tmp, *current;
	if(strcmp((*headS)->stdentID,rem1)==0){
		tmp = *headS;
		*headS = (*headS)->next;
		(*headS)->prev = *headS;
		free(tmp);
		printf("%s removed",rem1);
	}
	else{
		current=*headS;
		while(current->next!=NULL ){
			if(strcmp(current->stdentID,rem1)==0){
				tmp = current->next;
				current->next->next->prev = current;
				current->next=current->next->next;
				free(tmp);
				printf("%s removed",rem1);
			}
			current = current->next;
		}
		
	}
	
}



STDENT *rmS(STDENT *stdents,int *h3,REC *records,int h4)
{
	int j,i,k;
	char tempID2[20]="Not Recorded";
	char tempID[15];
	tempID[0]='\0';
	printf("\n\n Student ID for remove : ");		
	scanf("%s",tempID);

	for(i=0;i<*h3;i++)				
	{
		if(strcmp(stdents[i].stdentID,tempID)==0) 
		{
			if(i==*h3-1) 
			{
				(*h3)--;
				stdents=(STDENT*)realloc(stdents,(*h3)*sizeof(STDENT));
				printf("\n\n\t\t\t Student ID :  %s  Removed..",tempID);
				if(h4>0)
				{
					for(k=0;k<h4;k++)
					{
						if(strcmp(records[k].stdentInf.stdentID,tempID)==0)
						{
							strcpy(records[k].stdState,tempID2);
						}
					}
					
				}
				
				return stdents;
			}
			
			else 
			{
								
				for(j=i;j<*h3-1;j++) 
				{
					strcpy(stdents[j].stdentName,stdents[j+1].stdentName);
					strcpy(stdents[j].stdentSurname,stdents[j+1].stdentSurname);
					strcpy(stdents[j].stdentID,stdents[j+1].stdentID);
					stdents[j].sOfCred=stdents[j+1].sOfCred;
					stdents[j].sOfLect=stdents[j+1].sOfLect;
				}	
			}
			(*h3)--;
			stdents=(STDENT*)realloc(stdents,(*h3)*sizeof(STDENT));
			printf("\n\n\t\t\t Student ID :  %s  removed..",tempID);
			if(h4>0)
			{
				for(k=0;k<h4;k++)
				{
					if(strcmp(records[k].stdentInf.stdentID,tempID)==0)
					{
						strcpy(records[k].stdState,tempID2);
					}
				}
					
			}
			return stdents;
		}
	}
					
		printf("\n\n\t\t\t  There is no student ID :  %s  .",tempID);				
		return stdents;
}

STDENT *upS(STDENT *stdents,int h3){
	
	char tempName[20];
	char tempSurname[20];
	int j,i;
	char tempID[15];
	tempID[0]='\0';
	printf("\n\n Student ID for update : ");		
	scanf("%s",tempID);

	for(i=0;i<h3;i++)
	{
		if(strcmp(stdents[i].stdentID,tempID)==0) 
		{
			printf("\n\tStudent New Name : "); scanf("%s",tempName);	
			printf("\tStudent New Surname : "); scanf("%s",tempSurname);
			strcpy(stdents[i].stdentName,tempName);
			strcpy(stdents[i].stdentSurname,tempSurname);
			return stdents;
			
		}
	}
	printf("\n\n\t\t\tThere is no student ID : %s",tempID);
	return upS(stdents,h3);
	
}

STDENT *updateStudent(STDENT **headS){
	STDENT *tmp;
	tmp=*headS;
	printf("/n/n/t/t Student ID for update: \n");
	char stdentID[20];
	scanf("%s",stdentID);
	tmp=searchStdent(tmp,stdentID);
	if(tmp==0){
		printf("\n\tStudent Name: "); scanf("%s",&tmp->stdentName);
		printf("\n\tStudent Surname "); scanf("%s",&tmp->stdentSurname);;
	}else{
		printf("\n\n\t\t\tThere is no student ID : %s",stdentID);
	}
	
	
}

REC *adR(REC *records,int *h4,LECTURE *lectures,int h2,STDENT *stdents,int h3,int maxCredit,int maxLect)
{
	int count,i,j;
	int tmp1,tmp2;
	int d=0; 
	int d2=0; 
	char temp1[20]; char temp2[20]; char temp3[20]="Recorded";
	temp1[0]='\0';
	temp2[0]='\0';
	while(d2!=1)
	{
	 	printf("\n\n\tStudent ID for course record :");
	 	scanf("%s",temp2);
 	
	 	for(i=0;i<h3;i++)
	 	{
	 		if(strcmp(stdents[i].stdentID,temp2)==0)
	 		{
	 			d2=1;
	 			tmp2=i;
			}
		}
		if(d2==0)
		{
			count=0;
			printf("\n\t\t There is no student ID. Enter another\n");
			printf("\n\n\n\t\t --- All Students ---\n\n");				
		
			for(i=0;i<h3;i++)
			{
				count++;
				printf("    No: %s  Ad: %s %s",stdents[i].stdentID,stdents[i].stdentName,stdents[i].stdentSurname);
				if(count%4==0)		
				{
					printf("\n\n");
				}
			}
		}
		
	}
										
	d2=1;
	while(d!=1)				 
	{
		printf("\n\n\tCourse ID for student record:  ");
	 	scanf("%s",temp1);
	 	for(i=0;i<h2;i++)
		{
									 						 		 
			if(strcmp(lectures[i].lectID,temp1)==0)
	 		{
	 			tmp1=i;
	 			d=1;			
			}							
		}
		
		if(d==0)
		{
			count=0;				
			printf("\n\t\t There is no course ID. Enter another \n");
			printf("\n\n\t\t--- All Courses ---\n\n");
			for(i=0;i<h2;i++)
			{
				count++;
				printf("  Course ID: %s  Name: %s ",lectures[i].lectID,lectures[i].lectName);
				if(count%4==0)
				{
					printf("\n\n");
				}
			}
		}
	}
		d=1;
		
		if(*h4==0)
		{
			(*h4)++;
			records=(REC*)malloc((*h4)*sizeof(REC));
			strcpy(records[(*h4)-1].stdentInf.stdentID,temp2);
			strcpy(records[(*h4)-1].lectInf.lectID,temp1);
			printf("\n\tStudent status: %s ",temp3);
			strcpy(records[(*h4)-1].stdState,temp3);
			printf("\n\tStudent record date : "); scanf("%s",records[(*h4)-1].date);
			stdents[tmp2].sOfCred+=lectures[tmp1].credit;
			stdents[tmp2].sOfLect++;
			return records;
		}
		else if(*h4>0)
		{
			for(i=0;i<*h4;i++)
			{
				if(strcmp(records[i].stdentInf.stdentID,temp2)==0 && strcmp(records[i].lectInf.lectID,temp1)==0)
				{
					printf("\n\n\t\tERROR     --- Student already taking this course!--- ");
					return records;
				}
			}
			stdents[tmp2].sOfCred+=lectures[tmp1].credit;
			stdents[tmp2].sOfLect++;
			if(stdents[tmp2].sOfCred>maxCredit)
			{
				printf("\n\n\t\t No : %s   %s %s Over the Maximum Credit. Credit: %d Course can not taken",stdents[tmp2].stdentID,stdents[tmp2].stdentName,stdents[tmp2].stdentSurname,stdents[tmp2].sOfCred);
				stdents[tmp2].sOfCred-=lectures[tmp1].credit;
				return records;
			}
			else if(stdents[tmp2].sOfLect>maxLect)
			{
				printf("\n\n\t\t No : %s   %s %s Over the Maximum Courses. Credit: %d Course can not taken",stdents[tmp2].stdentID,stdents[tmp2].stdentName,stdents[tmp2].stdentSurname,stdents[tmp2].sOfLect);
				stdents[tmp2].sOfLect--;
				return records;
			}
			else
			{
				(*h4)++;
				records=(REC*)realloc(records,(*h4)*sizeof(REC));
				strcpy(records[(*h4)-1].stdentInf.stdentID,temp2);
				strcpy(records[(*h4)-1].lectInf.lectID,temp1);
				printf("\n\tStudent status : %s ",temp3);
				strcpy(records[(*h4)-1].stdState,temp3);
				printf("\n\tStudent record date : "); scanf("%s",records[(*h4)-1].date);
				return records;
			}
		}
}
REC *removeRec(REC *records,int h4,LECTURE *lectures,int h2,STDENT *stdents,int h3)
{
	int count,i,j;
	int tmp1=0;
	int tmp2=0;
	int d=0; 
	int d2=0; 
	char temp1[20]; char temp2[20]; char temp3[20]="Not Recorded";
	temp1[0]='\0';
	temp2[0]='\0';
	while(d2!=1)
	{
	 	printf("\n\n\t Student ID for update record status:");
	 	scanf("%s",temp2);
 	
	 	for(i=0;i<h3;i++)
	 	{
	 		if(strcmp(stdents[i].stdentID,temp2)==0)
	 		{
	 			d2=1;
	 			tmp2=i;
			}
		}
		if(d2==0)
		{
			count=0;
			printf("\n\t\t\t There is no student ID. Enter another \n");
			printf("\n\n\n\t\t --- All Students ---\n\n");				
		
			for(i=0;i<h3;i++)
			{
				count++;
				printf("    ID: %s  Name: %s %s",stdents[i].stdentID,stdents[i].stdentName,stdents[i].stdentSurname);
				if(count%4==0)		
				{
					printf("\n\n");
				}
			}
		}
		
	}
										
	d2=1;
	while(d!=1)				 
	{
		printf("\n\n\tCourse ID for update record status: ");
	 	scanf("%s",temp1);
	 	for(i=0;i<h2;i++)
		{
									 						 		 
			if(strcmp(lectures[i].lectID,temp1)==0)
	 		{
	 			tmp1=i;
	 			d=1;			
			}							
		}
		
		if(d==0)
		{
			count=0;				
			printf("\n\t\t There is no course ID. Enter another \n");
			printf("\n\n\t\t ---All Courses ---\n\n");
			for(i=0;i<h2;i++)
			{
				count++;
				printf("  Course ID: %s  Name: %s ",lectures[i].lectID,lectures[i].lectName);
				if(count%4==0)
				{
					printf("\n\n");
				}
			}
		}
	}
		d=1;
			
		for(i=0;i<h4;i++)
		{
			if(strcmp(records[i].lectInf.lectID,temp1)==0 && strcmp(records[i].stdentInf.stdentID,temp2)==0)
			{
				strcpy(records[i].stdState,temp3);
				stdents[tmp2].sOfCred-=lectures[tmp1].credit;
				stdents[tmp2].sOfLect--;
				return records;
			}
		}
		printf("\n\n\t\t There is no course %s for student ID: %s ! ",temp1,temp2);
	return removeRec(records,h4,lectures,h2,stdents,h3);
	
}


void prntStdent(REC *records,int h4,STDENT *stdents,int h3,char temp1[20])
{
	int var=0;
	char temp2[20]="Recorded";
	int i,j;
	printf("\n");
	for(i=0;i<h4;i++)
	{
		if(strcmp(records[i].lectInf.lectID,temp1)==0 && strcmp(records[i].stdState,temp2)==0)
		{
			for(j=0;j<h3;j++)
			{
				if(strcmp(records[i].stdentInf.stdentID,stdents[j].stdentID)==0)
				{
					printf("\n\tStudent ID : %s, Student Name & Surname: %s %s",stdents[j].stdentID,stdents[j].stdentName,stdents[j].stdentSurname);
					var=1;
				}
			}
		}
	}
	if(var==0)
	{
		printf("\n\n\tThere is no course for this student ID.");
	}
	
}

void printLect(REC *records,int h4,LECTURE *lectures,int h2,char temp1[20])
{
	int var=0;
	char temp2[20]="Recorded";
	int i,j;
	printf("\n");
	for(i=0;i<h4;i++)
	{
		if(strcmp(records[i].stdentInf.stdentID,temp1)==0 && strcmp(records[i].stdState,temp2)==0)
		{
			for(j=0;j<h2;j++)
			{
				if(strcmp(records[i].lectInf.lectID,lectures[j].lectID)==0)
				{
					printf("\n\tCourse ID: %s, Course Name : %s ",lectures[j].lectID,lectures[j].lectName);
					var=1;
				}
			}
		}
	}
	if(var==0)
	{
		printf("\n\n\tThere is no student for this course ID.");
	}
	
}
void printAll(REC *records,int h4,STDENT *stdents,int h3,char temp1[20])
{
	int i,j;
	char tempDosya[30];
	tempDosya[0]='\0';
	strcpy(tempDosya,temp1);
	strcat(tempDosya,"_List.txt");
	FILE *fw;
	int var=0;
	char temp2[20]="Recorded";
	printf("\n");
	fw=fopen(tempDosya,"w");
	for(i=0;i<h4;i++)
	{
		if(strcmp(records[i].lectInf.lectID,temp1)==0 && strcmp(records[i].stdState,temp2)==0)
		{
			for(j=0;j<h3;j++)
			{
				if(strcmp(records[i].stdentInf.stdentID,stdents[j].stdentID)==0)
				{
					fprintf(fw,"\n\tStudent ID : %s, Student Name & Surname : %s %s",stdents[j].stdentID,stdents[j].stdentName,stdents[j].stdentSurname);
					var=1;
				}
			}
		}
	}
	fclose(fw);
}