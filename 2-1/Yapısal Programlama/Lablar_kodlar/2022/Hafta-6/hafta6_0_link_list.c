/* cd /Users/zeyneb/Desktop/DERSLER/BLM2031_YapisalProg_20191/hafta6_codes
cc -o test hafta6_0_link_list.c 
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct personalstat {    char ps_name[20], ps_tcno[11];
    unsigned int ps_birth_day : 5;
    unsigned int ps_birth_month : 4;
    unsigned int ps_birth_year : 11;

    // pointer to the next element in the linked list:
    struct personalstat *next;};

// ELEMENT becomes synonymous with struct personalstat:
typedef struct personalstat ELEMENT;

ELEMENT *create_list_element(){
    ELEMENT *p; 
    p=(ELEMENT*) malloc (sizeof (ELEMENT));
    if(p == NULL) {
	printf("create_list_element (): malloc failed. \n");
	exit(1);
    }
    p->next=NULL;
    return p;
}

// The create_list_element() function allocates memory, but it doesn't link the element to the list. For this, we need an additional function, add_element():

static ELEMENT *head; // serves as a pointer to the beginning of the linked list
void add_element(ELEMENT *e){
    ELEMENT *p;
    // if the 1st element (head) has not been created, create it now:
    if(head==NULL){
	head=e;
	return;
    }
    // otherwise, find the last element in the list:

    // Span through each element testing to see whether p.next is NULL. 
    // If not NULL, p.next must point to another element. 
    // If NULL, we have found the end of the list and we end the for loop. 
    for (p=head; p->next != NULL; p=p->next); // null statement

    // append a new structure to the end of the list
    p->next=e;
}
 
// To insert an element in a linked list, you must specify where you want the new element inserted. The following function accepts 2 pointer arguments, p and q, and inserts the structure pointed by p just after the structure pointed by q.
void insert_after(ELEMENT *p, ELEMENT *q){
    // if p and q are same or NULL, or if p already follows q, report that:
    if(p==NULL || q==NULL || p==q || q->next == p){
	printf("insert_after(): Bad arguments \n");
	return;
    }
    p->next=q->next;
    q->next=p;
} 

// To delete an element in a linked list, you need to find the element before the one you are deleting so that you can bond the list back together after removing one of the links.
// You also need to use the free() func, to free up the memory used by the deleted element. 
void delete_element(ELEMENT *goner){
	ELEMENT *p;
    if(goner == head)
	head=goner->next;
    else // find element preceding the one to be deleted:
	for(p=head; (p!=NULL) && (p->next != goner); p=p->next); // null statement

    if(p == NULL){
		printf("delete_element(): could not find the element \n");
		return;
    }
    p->next=p->next->next;
    free(goner);
}

// Finding an Element in the Linked List:
// There is no easy way to create a general-purpose find() function because you usually search for an element based on one of its data fields (e.g. person's name), which depends on the structure being used. 
// To write a general-purpose find() function, you can use function pointers (remember earlier classes!!)
// The following function, based on the personalstat structure, searches for an element, whose ps_name field matches with the given argument.
ELEMENT *find( char * name){
	ELEMENT *p;
    for(p=head; p!= NULL; p=p->next)
	if(strcmp(p->ps_name, name) == 0) // returns 0, if 2 strings are same
	    return p; 
    return NULL;
}
int main(){
	ELEMENT *p;
	int val, j;
	for(j=0; j<2; j++)		add_element( create_list_element());
	
	for(j=0, p=head; p != NULL; p=p->next, j++){
		printf("Enter name of the %d-th person:\n", j+1);
		scanf("%s", p->ps_name);
		printf("Enter tcno of the %d-th person:\n", j+1);
		scanf("%s", p->ps_tcno);
		printf("Enter the birth-date (day) of the %d-th person:\n", j+1);
		scanf("%u", &val); p->ps_birth_day=val;
		printf("Enter the birth-date (month) of the %d-th person:\n", j+1);
		scanf("%u", &val); p->ps_birth_month=val;
		printf("Enter the birth-date (year) of the %d-th person:\n", j+1);
		scanf("%u", &val); p->ps_birth_year=val;
	}

	for(j=0, p=head; p != NULL; p=p->next, j++) //for(p=head; p != NULL; p=p->next)
	    printf("%d-th person: %s\t%s\t%u.%u.%u\n", j+1, p->ps_name, p->ps_tcno,
	    	p->ps_birth_day, p->ps_birth_month, p->ps_birth_year);	


	// CREATE A NEW ELEMENT AND INSERT IT IN BETWEEN THE 1st AND 2nd ELEMENTS IN THE LIST:
	p=create_list_element();
	// ask for the info to fill in the fields of this new record to be added to the list:
 	printf("Enter name of the new person:\n");
	scanf("%s", p->ps_name);
	printf("Enter tcno of the new person:\n");
	scanf("%s", p->ps_tcno);
	printf("Enter the birth-date (day) of the new person:\n");
	scanf("%u", &val); p->ps_birth_day=val;
	printf("Enter the birth-date (month) of the new person:\n");
	scanf("%u", &val); p->ps_birth_month=val;
	printf("Enter the birth-date (year) of the new person:\n");
	scanf("%u", &val); p->ps_birth_year=val;
    ELEMENT *q=head; // to keep the first element, head and we'll insert p, after q:
    insert_after(p, q);
	for(j=0, p=head; p != NULL; p=p->next, j++)
	    printf("%d-th person: %s\t%s\t%u.%u.%u\n", j+1, p->ps_name, p->ps_tcno,
	    	p->ps_birth_day, p->ps_birth_month, p->ps_birth_year);	

    return 0;
}
