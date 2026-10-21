// A BASELINE FOR FEATURES OF DOUBLY LINKED LISTS IN C LANG.

#include <stdio.h>
#include <stdlib.h>

struct n{
    int x;
    struct n * next;
    struct n * prev;
};
typedef struct n node;

// circular linked list has no end, the last element of list points root again
void print(node *); // display the list elements
node * add(node *, int); // adding to the end without sorting
node * insert(node *, int); // adding with ascending sort
node * delete(node *, int);   // deleting an element from linked list


int main(){
    node * root; // pointer for holding the head of list
    root = NULL;

    // node*head will be used to point root
    // linked lists use sequential access

    int i, new_element;
    root = delete(root, 1);
    for(i=0; i<4; i++){
        printf("enter new element: ");
        scanf("%d", &new_element);
        root = insert(root, new_element);
    }
    printf("Before Deletion: \n");
    print(root);

    root = delete(root, 3);
    root = delete(root, 7);
    root = delete(root, 2);
    root = delete(root, 4);

    printf("After Deletion: \n");
    print(root);
}

void print(node*head){
    int i = 0;
    while(head != NULL){ // we will travel until we reach the NULL at the end
        i++;
        printf("%d. element: %d\n", i, head -> x);
        head = head -> next;
    }
    if(i == 0)
        printf("0 element left.");
}


node * add(node*head, int new_element){ // add new element to the end of the list

    if (head == NULL){
        head = (node*) malloc(sizeof(node));
        head -> x = new_element;
        head -> prev = NULL;
        head -> next = NULL;
        return head;
    }

    node * iter = head; 
    while(iter -> next != NULL){
        iter = iter -> next;
    }
    
    node * tmp = (node*) malloc(sizeof(node));
    tmp -> next = NULL;
    tmp -> prev = iter;
    iter -> next = tmp;
    tmp -> x = new_element;
    return head;
}

node * insert(node*head, int new_element){

    if(head == NULL){          // if linked list is empty
        head = add(head, new_element);
        return head;
    }

    else{
        node * temp = (node*) malloc(sizeof(node));

        if (head -> x >= new_element){        // add element as root
            temp -> next = head;
            temp -> prev = NULL;
            temp -> x = new_element;
            head -> prev = temp;
            return temp; // send temp as new root, it is important to update root's pointer in main
        }

        node * iter = head;
        while(iter -> next != NULL && iter -> next -> x < new_element)
            iter = iter -> next;

        temp -> next = iter -> next; 
        temp -> prev = iter;   
        temp -> x = new_element;
        iter -> next = temp;
        if(iter -> next != NULL)
            iter -> next -> prev = temp;
        return head;
    }
}

node * delete(node*head, int element){

    if(head == NULL){
        printf("There is no element to remove. List has 0 element.\n");
        return head;
    }
    else if(head -> next == NULL && head -> x == element){
        printf("Your last element has removed. From now, you have 0 element in the list.\n");
        node * tmp = head;
        head = NULL; // 0 element has remained.
        free(tmp);
        return head; 
    }
    else if(head -> x == element){ // if the root equals to element we search (in other words first element of the list)
        node * tmp = head;
        head = head -> next;
        head -> prev = NULL;
        free(tmp);
        return head;      
    }
    else{
        node * iter = head;
        while(iter -> next != NULL && iter -> next -> x != element)
            iter = iter -> next;

        if(iter -> next == NULL){
            printf("There is no element matched with '%d' in the list.\n", element);
            return head;
        }

        node * tmp = iter -> next;
        iter -> next = iter -> next -> next;
        free(tmp);
        if(iter -> next != NULL)
            iter -> next -> prev = iter;
        return head;
    }
}