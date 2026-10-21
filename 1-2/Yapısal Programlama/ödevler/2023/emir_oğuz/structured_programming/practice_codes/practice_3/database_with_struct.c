#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct job
{
	char *name;
} JOB;

typedef struct person
{
	int ID;
	char *name;
	char *surname;
	int age;
	JOB *job;
} PERSON;

typedef struct database
{
	PERSON **data;
	int peopleCount;
	int databaseCount;
} DATABASE;

PERSON *initNewPerson(int personID, char *personName, char *personSurname, int personAge, char *jobName)
{
	PERSON *newPerson = (PERSON*) malloc(sizeof(PERSON) * 1);
	JOB *newJob = (JOB*) malloc(sizeof(JOB) * 1);
	
	newPerson->ID = personID;
	
	newPerson->name = (char*) malloc(sizeof(char) * (strlen(personName) + 1));
	strcpy(newPerson->name, personName);
	
	newPerson->surname = (char*) malloc(sizeof(char) * (strlen(personSurname) + 1));
	strcpy(newPerson->surname, personSurname);
	
	newPerson->age = personAge;
	
	newJob->name = (char*) malloc(sizeof(char) * (strlen(jobName) + 1));
	strcpy(newJob->name, jobName);
	newPerson->job = newJob;
	
	return newPerson;
}

void addNew(DATABASE *personDatabase, PERSON *newPerson)
{
	personDatabase->data[personDatabase->peopleCount++] = newPerson;
	
	if(personDatabase->peopleCount == personDatabase->databaseCount){
		personDatabase->databaseCount *= 2;
		personDatabase->data = (PERSON**) realloc(personDatabase->data, sizeof(PERSON*) * personDatabase->databaseCount);
	}	
}

int ID_check(DATABASE *personDatabase, int personID)
{
	int i;
	
	for(i=0; i<personDatabase->peopleCount; i++){
		
		if(personDatabase->data[i]->ID == personID){
			printf("\nThis ID number has its owner. Please choose another ID number...\n\n\n");
			
			return 1;
		}
	}
	
	return 0;
}

int searchDatabase(DATABASE *personDatabase, int personID)
{
	int i;
	
	for(i=0; i<personDatabase->peopleCount; i++){
		
		if(personDatabase->data[i]->ID == personID){
			printf("- Found Person:\n\n");
			printf("-> ID      : %d\n", personDatabase->data[i]->ID);
			printf("-> Name    : %s\n", personDatabase->data[i]->name);
			printf("-> Surname : %s\n", personDatabase->data[i]->surname);
			printf("-> Age     : %d\n", personDatabase->data[i]->age);
			printf("-> Job     : %s\n\n\n", personDatabase->data[i]->job->name);
			
			return i;
		}
	}
	
	printf("-> Person not found...\n\n\n");
	
	return -1;
}

void deletePerson(DATABASE *personDatabase, int personID)
{
	int personPosition = searchDatabase(personDatabase, personID);
	int i;
	
	if(personPosition == -1){
		return;
	}
	
	for(i=personPosition; i<personDatabase->peopleCount - 1; i++){
		personDatabase->data[i] = personDatabase->data[i + 1];
	}
	
	personDatabase->peopleCount--;
}

void listDatabase(DATABASE *personDatabase)
{
	int i;
	
	for(i=0; i<personDatabase->peopleCount; i++){
		printf("PERSON %d\n\n", i + 1);
		printf("-> ID      : %d\n", personDatabase->data[i]->ID);
		printf("-> Name    : %s\n", personDatabase->data[i]->name);
		printf("-> Surname : %s\n", personDatabase->data[i]->surname);
		printf("-> Age     : %d\n", personDatabase->data[i]->age);
		printf("-> Job     : %s\n\n\n", personDatabase->data[i]->job->name);
	}
}

void freePerson(PERSON *person)
{
	free(person->name);
	free(person->surname);
	free(person->job->name);
	free(person->job);
	free(person);
}

void freeDatabase(DATABASE *personDatabase)
{
	int i = 0;
	
	while(personDatabase->peopleCount > 0){
		freePerson(personDatabase->data[personDatabase->peopleCount - 1]);
		personDatabase->peopleCount--;
	}
	
	free(personDatabase->data);
}

int main()
{
	int exit_control = 0;
	int ID_control = 0;
	int choice;
	int personAge;
	int personID;
	char personName[50];
	char personSurname[50];
	char jobName[50];
	DATABASE personDatabase;
	PERSON* newPerson;
	personDatabase.databaseCount = 1;
	personDatabase.peopleCount = 0;
	
	personDatabase.data = (PERSON**) malloc(sizeof(PERSON*) * personDatabase.databaseCount);
	
	while(!exit_control){
		printf("Choose Action...\n\n");
		printf("-> 1 for Adding\n");
		printf("-> 2 for Searching\n");
		printf("-> 3 for Deleting\n");
		printf("-> 4 for Listing\n");
		printf("-> 5 for Exiting\n\n");
		printf("-> Your Choice: ");
		scanf("%d", &choice);
		printf("\n");
		
		switch(choice){
			case 1:
				system("cls");
				
				printf("--- ADD A NEW PERSON TO THE DATABASE ---\n\n");
				
				do{
					printf("ID      : ");
					scanf("%d", &personID);
				
					ID_control = ID_check(&personDatabase, personID);
				}while(ID_control);
				
				printf("Name    : ");
				fflush(stdin);
				scanf("%[^\n]s", personName);
				
				printf("Surname : ");
				fflush(stdin);
				scanf("%[^\n]s", personSurname);
				
				printf("Age     : ");
				scanf("%d", &personAge);
				
				printf("Job     : ");
				fflush(stdin);
				scanf("%[^\n]s", jobName);
				
				printf("\n");
				
				newPerson = initNewPerson(personID, personName, personSurname, personAge, jobName);
				addNew(&personDatabase, newPerson);
				
				printf("- People in database : %d\n", personDatabase.peopleCount);
				printf("- Database size      : %d\n\n\n", personDatabase.databaseCount);
				
				break;
				
			case 2:
				system("cls");
				
				printf("--- SEARCH FOR PERSON IN THE DATABASE ---\n\n");
				
				printf("Enter the person's ID number: ");
				scanf("%d", &personID);
				printf("\n");
				
				searchDatabase(&personDatabase, personID);
				
				break;
				
			case 3:
				system("cls");
				
				printf("--- DELETE PERSON FROM THE DATABASE ---\n\n");
				
				printf("Enter the person's ID number: ");
				scanf("%d", &personID);
				printf("\n");
				
				deletePerson(&personDatabase, personID);
				
				break;
				
			case 4:
				system("cls");
				
				printf("--- PEOPLE IN THE DATABASE ---\n\n");
				
				listDatabase(&personDatabase);
				
				break;
				
			case 5:
				exit_control = 1;
				
				printf("Logged out...\n");
				printf("-\n");
				printf("-\n");
				printf("-\n");
				
				break;
				
			default:
				system("cls");
				
				printf("--- WRONG CHOICE! ---\n\n");
		}	
	}
	
	freeDatabase(&personDatabase);
	
	getch();
	
	return 0;
}

