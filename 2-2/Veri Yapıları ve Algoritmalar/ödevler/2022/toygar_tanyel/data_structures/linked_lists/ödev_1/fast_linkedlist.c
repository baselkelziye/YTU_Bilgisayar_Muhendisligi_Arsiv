#include <stdio.h>
#include <stdlib.h>

struct n{
    int data;
    struct n * next_row;
    struct n * next_col;
};
typedef struct n node;

// ***********************************************************************************************************
// important to not get confused -> "next_row" is not for up-down, it basically points next element of same row
// row can be considered as same linked list (same stage)
// column can be considered as helper pointer to be able to reach next linked list (next stage)
// "next_col" points connected element of next stage
// ***********************************************************************************************************


int count_dimension(int);  // It is a function that gets stage count using linked list size, will be used for search
void print(node *);        // It is a function for printing every element of stages in order.
node* initialize(node*, int); // It is a function for creating first linked list and for other functions to create new nodes.
void search(node*, int, int); // It is a function for search specific element.
node* insert(node*, int, int*); // It is a function that insert given element and updates the stages.
node* delete(node*, int, int*); // It is a function that delete given element and updates the stages.
node* createNewDimensions(node*, int); // It is a function that create new stages and written as ...
                                      //...recursive and will be used in the insert, delete and first init.

int main(){

    int n, dim, i, new_element, expression, x;
    printf("\nIf you have no existing linked list please initialize a linked list first by using 1.");
    int flag = 1;
    while(flag){
        
        printf("\n\
                1) Initialize a new linked list.\n\
                2) Search for element.\n\
                3) Insert new element to current linked list.\n\
                4) Delete element from the current linked list.\n\
                5) Print current state of linked list.\n\
                6) Quit\n\
                Choice: ");

        scanf("%d", &expression);

        switch (expression)
        {
        case 1:
            printf("\nEnter how many elements you will enter: ");
            scanf("%d", &n);
            node*head = (node*) malloc(sizeof(node));
            head -> data = -1;
            head -> next_row = NULL;
            head -> next_col = NULL;

            for (i=0; i<n; i++){
                printf("Enter new element: ");
                scanf("%d", &new_element);
                head = initialize(head, new_element);
            }
            head = createNewDimensions(head, n);
            print(head);
            break;
        case 2:
            printf("\nEnter the count of element that you will search: ");
            scanf("%d", &x);
            for(i=0; i<x; i++){
                printf("\nEnter the element that you want to search for: ");
                scanf("%d", &new_element);
                dim = count_dimension(n) + 2; // this is the amount of stages for first initialization.
                search(head, new_element, dim);
            }
            break;
        case 3:
            printf("\nEnter the count of element that you will add: ");
            scanf("%d", &x);
            for(i=0; i<x; i++){
                printf("\nEnter the element that you want to insert to the list: ");
                scanf("%d", &new_element);
                head = insert(head, new_element, &n);
                print(head);
            }

            break;
        case 4:
            printf("\nEnter the count of element that you will delete: ");
            scanf("%d", &x);
            for (i=0; i<x; i++){
                printf("\nEnter the element that you want to delete from the list: ");
                scanf("%d", &new_element);
                head = delete(head, new_element, &n);
                print(head); 
            } 
            break;
        case 5:
            print(head);  
            break;        
        case 6:
            flag = 0;
            break;
        
        default:
            break;
        }
    }    
}

int count_dimension(int n){
    if((n+1)/2 == 1)
        return 1;
    return count_dimension((n+1)/2) + 1;
}

node * insert(node*head, int new_element, int *n){
    
    while(head->next_col!=NULL)
        head = head -> next_col;  // get cursor onto the main linked list

    head = initialize(head, new_element);
    *n = *n+1; // we use pointer and address of n because we cannot pass n's value back with return in C language.
    head = createNewDimensions(head, *n);
    printf("\nNew element has been added to stages.\n");

    return head;
}

node * delete(node*head, int element, int *n){

    node*safe_quit = head; // we use head in trace to functionalize the other methods
                           // so if we cannot find element we do not want to send new head pointer
                           // we should protect the pointer which points head of the stages.
    while(head->next_col!=NULL)
        head = head -> next_col;  // get cursor onto the main linked list

    node * iter = head;
    while(iter -> next_row != NULL && iter -> next_row -> data != element)
        iter = iter -> next_row;

    if(iter -> next_row == NULL){
        printf("\n('%d') is not in the list.\n", element);
        return safe_quit;
    }

    node * tmp = iter -> next_row;
    iter -> next_row = iter -> next_row -> next_row;
    free(tmp);
    *n = *n-1;
    head = createNewDimensions(head, *n);
    return head;
}


node * initialize(node*head, int new_element){

    node* current = head;
    while(current -> next_row != NULL && new_element >= current -> next_row -> data)
        current = current -> next_row;
    
    node * temp = (node*) malloc(sizeof(node));

    temp -> next_row = current -> next_row;
    temp -> next_col = NULL;
    temp -> data = new_element;
    current -> next_row = temp;
    return head;
}


node * createNewDimensions(node* head, int dim){
    int t = (dim+1)/2;

    node * new_stage_head = (node*)malloc(sizeof(node));
    new_stage_head -> data = -1;
    new_stage_head -> next_row = NULL;
    new_stage_head -> next_col = head;

    int i;
    node*iter = head->next_row;
    while(t >= 1){
        int new_element;
        new_element = iter->data;
        new_stage_head = initialize(new_stage_head, new_element); // we use past init function for creating new nodes
        node*finder=new_stage_head->next_row;
        while(finder->data != new_element)
            finder = finder -> next_row;

        finder->next_col = iter;
        if(iter->next_row != NULL)
            iter = iter -> next_row -> next_row;              
        t--;
    }
    if (dim == 1){
        node * new_stage_head = (node*)malloc(sizeof(node));
        new_stage_head -> data = -1;
        new_stage_head -> next_row = NULL;
        new_stage_head -> next_col = head;
        return new_stage_head;   
    }

    return createNewDimensions(new_stage_head, (dim+1)/2);
}

void search(node*head, int element, int dim){

    node*iter = head;
    iter = iter -> next_col; // first stage has no element
    int t=2;
  
    while(t!=dim+1){

        while (iter->next_row != NULL && element >= iter->next_row->data)
            iter = iter -> next_row;
        
        if(element == iter->data){
            printf("\nElement '%d' found at %d. stage\n", element, t);
            t=dim;
        }
        else if(t == dim)
            printf("\nThere is no such element that matched with %d\n", element);
        
        
        iter = iter -> next_col;
        t++;
    }
}

void print(node*head){
    int t = 1;
    printf("1. stage: \nhead->NULL\n");
    head = head -> next_col; // we pass the first stage because there is no element.
    while(head != NULL){
        printf("%d. stage: \nhead->", ++t);
        node* iter = head;
        while(iter->next_row != NULL){ // we will travel until we reach the NULL at the end
            printf("%d ->", iter->next_row->data);
            iter = iter -> next_row;
        }
        printf("NULL\n");
        head = head -> next_col;
    }
}