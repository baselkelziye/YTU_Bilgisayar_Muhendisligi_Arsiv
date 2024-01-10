
#include <stdio.h>
#include<stdlib.h>
#define R 10
#define C 10

struct node{
    int row;
    int col;
    int val;
    struct node* next;
};

void show_zerocols(struct node* head, int maxCol){
    int *labels = (int*)calloc(maxCol,sizeof(int));
    int i, flag=0;
    while(head != NULL){
        labels[head->col] = 1;
        head = head->next;
    }
    
    printf("\nZero column: ");
    for(i=0;i<maxCol;i++){
        if(labels[i]==0){
            printf("%d ", i);
            flag = 1;
        }
    }
    if(flag == 0)
        printf("-");
}

void print_list(struct node* head){
    printf("Linked list: \n[r c v]");
    
    while(head != NULL){
        printf("\n[%2d %2d %2d]", head->row, head->col, head->val);
        head = head -> next;
    }
}

void insert(struct node** head, int row, int col,int val){
    
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->row = row;
    newNode->col = col;
    newNode->val = val;
    newNode->next = NULL;
    
    if(*head == NULL)
        *head = newNode;
    else{
        
        struct node* lastNode = *head;
        while(lastNode->next != NULL){
            lastNode = lastNode->next;
        }
        
        lastNode->next = newNode;
    }
    
}

int main()
{
    struct node* list = NULL;
    int i,j, element, n,m;
    
    do{
        printf("Boyutlari giriniz:");
        scanf("%d %d", &n,&m);
    }while(n > R || m > C);
    
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            scanf("%d", &element);
            if(element)
                insert(&list, i,j,element);
        }
    }
    
    print_list(list);
    
    show_zerocols(list, m);

    return 0;
}

