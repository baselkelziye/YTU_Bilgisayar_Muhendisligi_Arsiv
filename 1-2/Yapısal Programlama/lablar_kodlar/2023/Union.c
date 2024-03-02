#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
   unsigned int day : 5;
   unsigned int month : 4;
   unsigned int year : 11;
} DATE;

struct personalstat {
    char ps_name[20], ps_tcno[11];
    DATE ps_birth_date;
    unsigned int TCcitizen : 1;
    union{
      char nationality[20];
      char city_of_birth[20];
    } location;
    // pointer to the next element in the linked list:
    struct personalstat *next;
};
// ELEMENT becomes synonymous with struct personalstat:
typedef struct personalstat ELEMENT;

// Always keep a pointer to the beginning of the linked list
static ELEMENT *head;

void printElementP( ELEMENT *emp ) {
    if( emp->TCcitizen == 1 ) {
        printf("Turkish Employee %s %s born in %d.%d.%d in %s\n", emp->ps_tcno, emp->ps_name,
        emp->ps_birth_date.day, emp->ps_birth_date.month, emp->ps_birth_date.year,
        emp->location.city_of_birth  );
    }
    else {
        printf("%s Employee %s %s born in %d.%d.%d\n", emp->location.nationality,
        emp->ps_tcno, emp->ps_name,
        emp->ps_birth_date.day, emp->ps_birth_date.month, emp->ps_birth_date.year);
    }
}
void printList( ) {
    int j; ELEMENT *p;
	for(j=0, p=head; p != NULL; p=p->next, j++)
	    printf("%d-th person: %s\t%s\t%u.%u.%u", j+1, p->ps_name, p->ps_tcno,
	    	p->ps_birth_date.day, p->ps_birth_date.month, p->ps_birth_date.year);
    if(p->TCcitizen == 1 )
        printf(" born in %s\n",p->location.city_of_birth);
    else
        printf(" is of nationality %s\n",p->location.nationality);
}
ELEMENT *create_list_element(){
    ELEMENT *p;
    int val; //ilkel ve bitfield olduðu için geçici deðiþken þart
    char c;
    p=(ELEMENT*) malloc (sizeof (ELEMENT));
    if(p == NULL) { printf("create_list_element (): malloc failed. \n"); exit(1); }
    printf("Enter name of the person:"); scanf("%s", p->ps_name);
    printf("Enter tc no/passport no of the person:"); scanf("%s", p->ps_tcno);
    printf("Enter the birth-date (day) of the person:"); scanf("%u", &val);
    p->ps_birth_date.day=val;
    printf("Enter the birth-date (month) of the person:"); scanf("%u", &val);
    p->ps_birth_date.month=val;
    printf("Enter the birth-date (year) of the person:"); scanf("%u", &val);
    p->ps_birth_date.year=val;

    printf("Is this a Turkish citizen? (y/n) "); scanf("%s",&c);
    if( c == 'n' || c == 'N' ) {  //foreigner
        p->TCcitizen = 0;
        printf("What is the nationality of this person? ");
        scanf("%s", p->location.nationality);
    }
    else {
        p->TCcitizen = 1;
        printf("What is the birth city of this person? ");
        scanf("%s", p->location.city_of_birth);
    }

    p->next=NULL; return p;
}
void add_element(ELEMENT *e){
    ELEMENT *p;
    if(head==NULL){ head=e; return; }
    for (p=head; p->next != NULL; p=p->next); // null statement
    p->next=e;
}
void insert_after(ELEMENT *p, ELEMENT *q){
    // if p and q are same or NULL, or if p already follows q, report that:
    if(p==NULL || q==NULL || p==q || q->next == p){
	   printf("insert_after(): Bad arguments \n");
	   return;
    }
    p->next = q->next;
    q->next = p;
} 
void delete_element(ELEMENT *goner){
    ELEMENT *p;
    if(goner == head)
	head=goner->next;
    else // find element preceding the one to be deleted:
	for(p=head; (p!=NULL) && (p->next != goner); p=p->next); // null statement

    if(p == NULL){
	printf("delete_element(): could not find the element \n"); return;
    }
    p->next=p->next->next;
    free(goner);
}
ELEMENT *find( char * name){
	ELEMENT *p;
    for(p=head; p!= NULL; p=p->next)
	   if(strcmp(p->ps_name, name) == 0) // returns 0, if 2 strings are same
	      return p;
    return NULL;
}
 


int main(int argc, char *argv[])
{
    ELEMENT *p,*q;
    int val, j;
    for(j=0; j<2; j++)
    add_element( create_list_element());
	
    for(j=0, p=head; p != NULL; p=p->next, j++) //for(p=head; p != NULL; p=p->next)
    {
        //printf("%d-th person: %s\t%s\t%u.%u.%u\n", j+1, p->ps_name, p->ps_tcno, p->ps_birth_day, p->ps_birth_month, p->ps_birth_year);
        printf("%d-th person: ",(j+1)); printElementP(p); 
    }

/*
    // CREATE A NEW ELEMENT AND INSERT IT IN BETWEEN THE 1st AND 2nd ELEMENTS IN THE LIST:
    p=create_list_element();

    q=head; // to keep the first element, head and we'll insert p, after q:
    insert_after(p, q);

    printList( );
*/
    system("PAUSE");
    return 0;
}