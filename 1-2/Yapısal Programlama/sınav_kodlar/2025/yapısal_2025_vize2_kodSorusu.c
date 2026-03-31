/*
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//5 points 
//fill the structs:
//you need to save departments with id betweem 1-80, name with 20 max lenght and number of students
//then create a one-way single linked list to have the departments inside
//------------------------------------
typedef struct {
	
}Department;

typedef struct Node{
	
}NODE;
//------------------------------------

//6 points
//write funciton called createNode(), must create a new node with 1-80 id check. If the entered value is out of the range, ID must be 0
//------------------------------------
NODE* createNode(...){
	
}
//-------------------------------------

//5 points?
//add a new node to the start of the list using createNode() and return it
//-------------------------------------
... pushFront(...){
	
}
//-------------------------------------

//5 points?
//Update student count of a department. Reach department using Department ID.
//If ID doesn't exist print a message that says department doesn't exist
//-------------------------------------
... updateDepartment(...){
	
}
//--------------------------------------

//5 points
//write printNode function that lists the given node's department ID, name and count
//--------------------------------------
void printNode(NODE* node){
	
}
//-------------------------------------

//5points
//write listNodes function that will print every department
//!!!must be done with printNode usage
//------------------------------------
void listNodes(NODE* head){
	
}

//------------------------------------

//20 points?
//find the two departments with closest number of students
//Print the found departments using printNode function
//----------------------------------------------------------
... findClosestDepartments(...){
	
}
//---------------------------------------------------------
	
//10 points?
//write everything wanted below
//--------------------------------------------------------
int main(){
	
//1: declare a null head and create departments until -1 is entered
	
	
//2: update a departments student count using updateDepartment function

	
//3: Use listNodes() to list everything	
	
		
//4: Use findClosestDepartments suiting instructions in the question	
	

//5: Free everything	
	
	
	return 0;
}
*/
// example answer below, might not be the perfect answer 

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//5 points 
//fill the structs:
//you need to save departments with id betweem 1-80, name with 20 max lenght and number of students
//then create a one-way single linked list to have the departments inside
typedef struct {
	int id;
	char name[20];
	int studentCount;
}Department;

typedef struct Node{
	Department data;
	struct Node *next;
}NODE;

//6 points
//must create a new node with 1-80 id check. If the entered value is out of the range, ID must be 0
NODE* createNode(){
	NODE* newNode = (NODE*)malloc(sizeof(NODE));
	int ID;
	printf("Enter ID: ");
	scanf("%d",&ID);
	if(ID<1 && ID>80){
		ID = 0;
	}
	newNode->data.id=ID;
	printf("Enter Department Name: ");
	scanf("%s", newNode->data.name);                
	printf("Enter student count: ");
	scanf("%d", &newNode->data.studentCount);
	newNode->next = NULL;
	return newNode;
}

//5 points?
//add a new node to the start of the list using createNode() and return it
void pushFront(NODE **head){
	NODE *newNode = createNode();
	if(head == NULL){
		*head = newNode;
	}else{
		newNode->next = *head;
		*head = newNode;
	}
}

//5 points?
//Update student count of a department. Reach department using Department ID.
//If ID doesn't exist print a message that says department doesn't exist
void updateDepartment(NODE** head, int ID, int newCount){
	NODE *tmp = *head;
	while(tmp->next != NULL && tmp->data.id != ID){
		tmp = tmp->next;
	}
	if(tmp->data.id == ID){
		tmp->data.studentCount = newCount;
		printf("Department student count updated.");
	}else{
		printf("Department with the given ID doesn't exist.");
	}
}

//5 points
//write printNode function that lists the given node's department ID, name and count
void printNode(NODE* node){
	printf("Department ID: %d\n",node->data.id);
	printf("Department name: %s\n",node->data.name);
	printf("Number of Students: %d\n",node->data.studentCount);
}

//5points
//write listNodes function that will print every department
//!!!must be done with recursive printNode usage
void listNodes(NODE* head){
	printNode(head);
	if(head->next != NULL){
		listNodes(head->next);
	}
}

//20 points?
//find the two departments with closest number of students
//Print the found departments using printNode function
void findClosestDepartments(NODE* head){
	int diff = 100;  		
	//there is a safer way with an min integer and diff integer  (this code will print incorrect 100 answer if studentCount differences are too high)	
		
	if(head == NULL||head->next == NULL){
		printf("not enough departments to search.");
		return;
	}
	NODE *d1,*d2,*f1,*f2;
	for(d1=head; d1!=NULL; d1=d1->next){
		for(d2=head; d2!=NULL; d2=d2->next){
			if(abs(d1->data.studentCount - d2->data.studentCount) < diff && d1 != d2){
				diff =   (d1->data.studentCount > d2->data.studentCount) 
					   ? (d1->data.studentCount - d2->data.studentCount) 
					   : (d2->data.studentCount - d1->data.studentCount);
				//or just abs(d1->data.studentCount - d2->data.studentCount) instead 
				//(abs : <math.h> absolute value function)
				f1 = d1;
				f2 = d2;
			}
		}
	}
	printf("Department with closest number of students are listed below:");
	printNode(f1);
	printNode(f2);
}
	
//10 points?
//write everything wanted below
int main(){
	
//1: declare a null head and create departments until -1 is entered
	NODE *head = NULL;
	int flag = 0, newCount, ID;
	while (flag!=-1){
		pushFront(&head);
		printf("type -1 to continue, any other value to add more");
		scanf("%d",&flag);
	}
	
//2: update a departments student count using updateDepartment function

	printf("Enter the new value: ");
	scanf("%d", &newCount);
	printf("Enter Department ID:");
	scanf("%d", &ID);
	updateDepartment(&head, ID, newCount);
	
//3: Use listNodes() to list everything	
	listNodes(head);
		
//4: Use findClosestDepartments suiting instructions in the question	
	findClosestDepartments(head);

//5: Free everything	
	NODE *temp = head;
	while(temp->next != NULL){
		head = head->next;
		free(temp);
}
	return 0;
}
