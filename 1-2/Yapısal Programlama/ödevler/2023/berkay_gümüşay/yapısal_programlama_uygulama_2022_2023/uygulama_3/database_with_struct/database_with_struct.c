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

typedef struct database{
	Person** Data;
	int peopleCount;
	int databaseCount;
}Database;

Person* initNewPerson(char *Name, int Age, char* jobName){
	Person* newPerson=(Person*) malloc(1*sizeof(Person));
	Job* newJob=(Job*) malloc(1*sizeof(Job));
	newPerson->Name=(char*) malloc((strlen(Name)+1)*sizeof(char));
	strcpy(newPerson->Name,Name);
	newPerson->Age=Age;
	newJob->Name=(char*) malloc((strlen(jobName)+1)*sizeof(char));
	strcpy(newJob->Name,jobName);
	newPerson->job=newJob;
	return newPerson;
}

void AddNew(Database *personDatabase,Person* newPerson){
	personDatabase->Data[personDatabase->peopleCount++]=newPerson;
	if (personDatabase->peopleCount==personDatabase->databaseCount){
		personDatabase->databaseCount*=2;
		personDatabase->Data=(Person**)realloc(personDatabase->Data,personDatabase->databaseCount*sizeof(Person*));
	}
	
}

int SearchDatabase(Database *personDatabase,char* Name){
	int i;
	for(i=0;i<personDatabase->peopleCount;i++){
		if(strcmp(personDatabase->Data[i]->Name,Name)==0){
			printf("Person Found: \n");
			printf("Name: %s, Age: %d, Job: %s\n",personDatabase->Data[i]->Name,personDatabase->Data[i]->Age,personDatabase->Data[i]->job->Name);
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

void FreeDatabase(Database *personDatabase){
	int i=0;
	while(personDatabase->peopleCount>0){
		FreePerson(personDatabase->Data[personDatabase->peopleCount-1]);
		personDatabase->peopleCount--;
	}
	free(personDatabase->Data);
	
	
}

void DeletePerson(Database *personDatabase, char *Name){
	int personPosition=SearchDatabase(personDatabase,Name);
	int i;
	if (personPosition==-1){
		printf("Person Cannot Be Deleted\n");
		return;
	}
	for(i=personPosition;i<personDatabase->peopleCount-1;i++){
		personDatabase->Data[i]=personDatabase->Data[i+1];
	}
	
	personDatabase->peopleCount--;
}

void ListDatabase(Database *personDatabase){
	int i;
	for(i=0;i<personDatabase->peopleCount;i++){
		printf("Name: %s, Age: %d, Job: %s\n",personDatabase->Data[i]->Name,personDatabase->Data[i]->Age,personDatabase->Data[i]->job->Name);
	}
	free(personDatabase->Data);
}




int main(){
	int peopleCount=0;
	int databaseCount=1;
	Database personDatabase;
	int exitControl=1;
	int cho;
	char Name[100];
	char jobName[100];
	int Age;
	Person* newPerson;
	personDatabase.databaseCount=1;
	personDatabase.peopleCount=0;
	personDatabase.Data=(Person**) malloc (personDatabase.databaseCount*sizeof(Person*));
	
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
				AddNew(&personDatabase,newPerson);
				printf("people in Database: %d, Database Size: %d\n",peopleCount,databaseCount);
				break;
			case 2:
				printf("Enter Searched Person Name: ");
				scanf("%s",Name);
				SearchDatabase(&personDatabase,Name);
				break;
			case 3:
				printf("Enter Person Name: ");
				scanf("%s",Name);
				DeletePerson(&personDatabase,Name);
				break;
			case 4:
				ListDatabase(&personDatabase);
				break;
			case 5:
				exitControl=0;
				break;
			default:
				printf("Wrong choice\n");
		}
			
	}
	
	FreeDatabase(&personDatabase);
	
	
	return 0;
}


