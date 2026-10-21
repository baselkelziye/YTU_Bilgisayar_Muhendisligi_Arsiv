#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct job{
	char* Name;
}Job;

typedef struct Person{
	int Age;
	char* Name;
	Job* job;
}Person;



Person* initNewPerson(char *Name, int Age, char* jobName){
	Person* newPerson=(Person*) malloc(1*sizeof(Person));
	Job* newJob=(Job*) malloc(1*sizeof(Job));
	newPerson->Name=(char*) malloc((strlen(Name)+1)*sizeof(char));// Neden 1
	strcpy(newPerson->Name,Name);
	newPerson->Age=Age;
	newJob->Name=(char*) malloc((strlen(jobName)+1)*sizeof(char));
	strcpy(newJob->Name,jobName);
	newPerson->job=newJob;
	return newPerson;
}

void AddNew(Person*** Database,int *peopleCount,int *databaseCount,Person* newPerson){// Neden ***
	(*Database)[(*peopleCount)++]=newPerson;
	
	if (*peopleCount==*databaseCount){
		*databaseCount*=2;
		(*Database)=(Person**)realloc(*Database,(*databaseCount)*sizeof(Person*));
	}
	
}

int SearchDatabase(Person** Database,int peopleCount,char* Name){
	int i;
	for(i=0;i<peopleCount;i++){
		if(strcmp(Database[i]->Name,Name)==0){
			printf("Person Found: \n");
			printf("Name: %s, Age: %d, Job: %s\n",Database[i]->Name,Database[i]->Age,Database[i]->job->Name);
			return i;
		}
			
	}
	printf("Person Not Found\n");
	return -1;
}

void FreePerson(Person *person){
	free(person->Name);
	free(person->job->Name);
	free(person->job);
	free(person);
}

void FreeDatabase(Person ** Database,int peopleCount){
	int i=0;
	for(i=0;i<peopleCount;i++){
		FreePerson(Database[i]);
	}
	free(Database);
}

void DeletePerson(Person** Database, int *peopleCount, char *Name){
	int personPosition=SearchDatabase(Database,*peopleCount,Name);
	int i;
	if (personPosition==-1){
		printf("Person Cannot Be Deleted\n");
		return;
	}
	Database[personPosition]=Database[(*peopleCount)-1];
	
	/*
	for(i=personPosition;i<*peopleCount-1;i++){
		Database[i]=Database[i+1];
	}*/
	
	(*peopleCount)--;
}

void ListDatabase(Person** Database,int peopleCount){
	int i;
	for(i=0;i<peopleCount;i++){
		printf("Name: %s, Age: %d, Job: %s\n",Database[i]->Name,Database[i]->Age,Database[i]->job->Name);
	}
}



int main(){
	int peopleCount=0;
	int databaseCount=1;
	Person **Database;
	int exitControl=1;
	int cho;
	char Name[100];
	char jobName[100];
	int Age;
	Person* newPerson;
	Database=(Person**) malloc (databaseCount*sizeof(Person*));
	
	while(exitControl){
		printf("Choose Action:\n");
		printf("1 For Adding\n");
		printf("2 For Searching\n");
		printf("3 For Deleting\n");
		printf("4 For Listing\n");
		printf("5 For Exiting\n");
		printf("Your Choice: ");
		scanf("%d",&cho);
		switch(cho){
			case 1:
				printf("Enter Person Name: ");
				scanf("%s",Name);
				printf("Enter Person Age: ");
				scanf("%d",&Age);
				printf("Enter Job Name: ");
				scanf("%s",jobName);
				newPerson=initNewPerson(Name,Age,jobName);
				AddNew(&Database,&peopleCount,&databaseCount,newPerson);
				printf("people in Database: %d, Database Size: %d\n",peopleCount,databaseCount);
				break;
			case 2:
				printf("Enter Searched Person Name: ");
				scanf("%s",Name);
				SearchDatabase(Database,peopleCount,Name);
				break;
			case 3:
				printf("Enter Person Name: ");
				scanf("%s",Name);
				DeletePerson(Database,&peopleCount,Name);
				break;
			case 4:
				ListDatabase(Database,peopleCount);
				break;
			case 5:
				exitControl=0;
				break;
			default:
				printf("Wrong choice\n");
		}
			
	}
	
	
	
	
	return 0;
}
