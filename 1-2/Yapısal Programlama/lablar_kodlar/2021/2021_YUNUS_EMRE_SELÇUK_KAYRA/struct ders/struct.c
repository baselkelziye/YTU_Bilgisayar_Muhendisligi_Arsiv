#include <stdio.h>
typedef struct Employee {
char name[20], surname [20];
int ID;
float salary;
struct Employee *next;
} EMPLOYEE;
EMPLOYEE *head;
void printElementP( EMPLOYEE *emp ) {
printf("Employee %d %s has a salary of %f ---%s\n",
emp->ID, emp->name, emp->salary,emp->surname );
}
void printList( ) {
int j; EMPLOYEE *p;
for(j=0, p=head; p != NULL; p=p->next, j++)
printf("%d-th person: %d\t%s\t%f\n",
j+1, p->ID, p->name, p->salary);
}
EMPLOYEE* create_list_element( ) {
EMPLOYEE *a; int i; float d;
a = (EMPLOYEE*) malloc( sizeof( EMPLOYEE ) );
if( a == NULL ) {
printf("create_employee: out of memory."); exit(1);
}
	printf("isim"); scanf("%s",a->name);
		printf("soyisim"); scanf("%s",a->surname);
	printf("no"); scanf("%d",&i);a->ID=i;
	printf("maas"); scanf("%f",&d);a->salary=d;
	a->next=NULL;
	return a;
}
void add_element(EMPLOYEE *e){
EMPLOYEE *p;
if(head == NULL){ head=e; return; }
for (p=head; p->next != NULL; p=p->next); 
p->next=e;
}
void delete_element(EMPLOYEE *goner){
EMPLOYEE *p;
if(goner == head)
head=goner->next;
else // find element preceding the one to be deleted:
for(p=head; (p!=NULL) && (p->next != goner); p=p->next);
if(p == NULL){
printf("delete_element(): could not find the element \n"); return;
}
p->next=p->next->next; free(goner);
}
EMPLOYEE* find(char *name) {
EMPLOYEE *p;
for(p=head; p!= NULL; p=p->next)
if(strcmp(p->name, name) == 0) // returns 0, if 2 strings are same
return p;
return NULL;
}
void insert_after(EMPLOYEE *p, EMPLOYEE *q){
// if p and q are same or NULL, or if p already follows q, report that:
if(p==NULL || q==NULL || p==q || q->next == p){
printf("insert_after(): Bad arguments \n");
return;
}
p->next = q->next;
q->next = p;
} 
int main(){
EMPLOYEE *p,*q;
int val, j;
for(j=0; j<2; j++)
add_element( create_list_element());
for(j=0, p=head; p != NULL; p=p->next, j++)
//for(p=head; p != NULL; p=p->next)
{
printf("%d-th person: ",(j+1)); printElementP(p);
}
p=create_list_element();
q=head; //to keep the first element, head
insert_after(p, q); //and we insert p, after q:
printList( );
return 0;
}
