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

void addNew(PERSON*** database, PERSON *newPerson, int *peopleCount, int *databaseCount)
{
	(*database)[(*peopleCount)++] = newPerson;
	
	if(*peopleCount == *databaseCount){
		*databaseCount *= 2;
		(*database) = (PERSON**) realloc(*database, sizeof(PERSON*) * (*databaseCount));
	}	
}

int ID_check(PERSON **database, int peopleCount, int personID)
{
	int i;
	
	for(i=0; i<peopleCount; i++){
		
		if(database[i]->ID == personID){
			printf("\nThis ID number has its owner. Please choose another ID number...\n\n\n");
			
			return 1;
		}
	}
	
	return 0;
}

int searchDatabase(PERSON** database, int peopleCount, int personID)
{
	int i;
	
	for(i=0; i<peopleCount; i++){
		
		if(database[i]->ID == personID){
			printf("- Found Person:\n\n");
			printf("-> ID      : %d\n", database[i]->ID);
			printf("-> Name    : %s\n", database[i]->name);
			printf("-> Surname : %s\n", database[i]->surname);
			printf("-> Age     : %d\n", database[i]->age);
			printf("-> Job     : %s\n\n\n", database[i]->job->name);
			
			return i;
		}		
	}
	
	printf("-> Person not found...\n\n\n");
	
	return -1;
}

void deletePerson(PERSON **database, int *peopleCount, int personID)
{
	int personPosition = searchDatabase(database, *peopleCount, personID);
	int i;
	
	if(personPosition == -1){
		return;
	}
	
	database[personPosition] = database[(*peopleCount) - 1];
	
	/*
	for(i=personPosition; i<(*peopleCount)-1; i++){
		database[i] = database[i+1];
	}
	*/
	
	(*peopleCount)--;
}

void listDatabase(PERSON **database, int peopleCount)
{
	int i;
	
	for(i=0; i<peopleCount; i++){
		printf("PERSON %d\n\n", i + 1);
		printf("-> ID      : %d\n", database[i]->ID);
		printf("-> Name    : %s\n", database[i]->name);
		printf("-> Surname : %s\n", database[i]->surname);
		printf("-> Age     : %d\n", database[i]->age);
		printf("-> Job     : %s\n\n\n", database[i]->job->name);
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

void freeDatabase(PERSON **database, int peopleCount)
{
	int i;
	
	for(i=0; i<peopleCount; i++){
		freePerson(database[i]);
	}
	
	free(database);
}

int main()
{
	int exit_control = 0;
	int ID_control = 0;
	int peopleCount = 0;
	int databaseCount = 1;
	int choice;
	int personID;
	int personAge;
	char personName[50];
	char personSurname[50];
	char jobName[50];
	PERSON **database;
	PERSON *newPerson;
	
	database = (PERSON**) malloc(sizeof(PERSON*) * databaseCount);
	
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
				
					ID_control = ID_check(database, peopleCount, personID);
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
				addNew(&database, newPerson, &peopleCount, &databaseCount);
				
				printf("- People in database : %d\n", peopleCount);
				printf("- Database size      : %d\n\n\n", databaseCount);
				
				break;
				
			case 2:
				system("cls");
				
				printf("--- SEARCH FOR PERSON IN THE DATABASE ---\n\n");
				
				printf("Enter the person's ID number: ");
				scanf("%d", &personID);
				printf("\n");
				
				searchDatabase(database, peopleCount, personID);
				
				break;
				
			case 3:
				system("cls");
				
				printf("--- DELETE PERSON FROM THE DATABASE ---\n\n");
				
				printf("Enter the person's ID number: ");
				scanf("%d", &personID);
				printf("\n");
				
				deletePerson(database, &peopleCount, personID);
				
				break;
				
			case 4:
				system("cls");
				
				printf("--- PEOPLE IN THE DATABASE ---\n\n");
				
				listDatabase(database, peopleCount);
				
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
	
	freeDatabase(database, peopleCount);
	
	getch();
	
	return 0;
}

