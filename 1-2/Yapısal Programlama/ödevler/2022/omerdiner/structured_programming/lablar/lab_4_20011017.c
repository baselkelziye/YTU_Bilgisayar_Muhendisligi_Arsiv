#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int id;
    int v1;
    int v2;
    struct Node *next;
} NODE;

void printList(NODE *n);
void insert(NODE **head_ref, int id, int value1, int value2);
NODE *intersection(NODE *start1, NODE *start2, int (*compare)(NODE *, NODE *));
int compare_by_value1(NODE *Node1, NODE *Node2);
int compare_by_value2(NODE *Node1, NODE *Node2);

int main(){
    NODE *start = NULL;
    insert(&start, 1, 10, 15);
    insert(&start, 2, 20, 15);
    insert(&start, 4, 20, 15);
    insert(&start, 7, 30, 20);
    insert(&start, 10, 30, 40);
    NODE *start2 = NULL;
    insert(&start2, 1, 10, 15);
    insert(&start2, 4, 25, 15);
    insert(&start2, 7, 25, 20);
    insert(&start2, 10, 30, 41);

    NODE *node3 = intersection(start, start2, compare_by_value1);
    printList(node3);
    NODE *node4 = intersection(start, start2, compare_by_value2);
    printList(node4);
    return 0;
}
void printList(NODE *head){
    NODE *tmp = head;
    while (tmp != NULL)
    {
        printf("%d %d %d\n", tmp->id, tmp->v1, tmp->v2);
        tmp = tmp->next;
    }
    printf("\n");
}

void insert(NODE **head_ref, int id, int value1, int value2){
    NODE *newNode = (NODE *)malloc(sizeof(NODE));
    newNode->id = id;
    newNode->v1 = value1;
    newNode->v2 = value2;
    newNode->next = NULL;
    if (*head_ref == NULL)
    {
        *head_ref = newNode;
    }
    else
    {
        NODE *tmp = *head_ref;
        while (tmp->next != NULL)
        {
            tmp = tmp->next;
        }
        tmp->next = newNode;
    }
}
int compare_by_value1(NODE *Node1, NODE *Node2){
    if (Node1->id == Node2->id && Node1->v1 == Node2->v1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int compare_by_value2(NODE *Node1, NODE *Node2){
    if (Node1->id == Node2->id && Node1->v2 == Node2->v2)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

NODE *intersection(NODE *start1, NODE *start2, int (*compare)(NODE *, NODE *)){
    NODE *head = NULL;
    NODE *tmp1 = start1;
    NODE *tmp2 = start2;
    while (tmp1 != NULL)
    {
        while (tmp2 != NULL)
        {
            if (compare(tmp1, tmp2) == 1)
            {
                insert(&head, tmp1->id, tmp1->v1, tmp1->v2);
                insert(&head, tmp2->id, tmp2->v1, tmp2->v2);
            }
            tmp2 = tmp2->next;
        }
        tmp2 = start2;
        tmp1 = tmp1->next;
    }
    return head;
}

