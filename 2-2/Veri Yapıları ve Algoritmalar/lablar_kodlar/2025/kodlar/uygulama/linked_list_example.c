#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *createNode(int data);
void appendNode(Node **headRef, int data);
void printList(Node *headRef);
void freeList(Node *head);

int main()
{
    Node *head = createNode(10);

    appendNode(&head, 20);
    appendNode(&head, 30);
    appendNode(&head, 40);
    appendNode(&head, 28);

    printList(head);

    free(head);

    return 0;
}

Node *createNode(int data)
{
    Node *node = (Node *)calloc(1, sizeof(Node));

    if (node == NULL)
    {
        printf("Memory allocation err!!\n");
    }

    node->data = data;
    node->next = NULL;

    return node;
}

void appendNode(Node **headRef, int data)
{
    Node *new_node = createNode(data);

    if (*headRef == NULL)
        *headRef = new_node;

    Node *current = *headRef;

    while (current->next != NULL)
    {
        current = current->next;
    }

    current->next = new_node;
}

void printList(Node *headRef)
{
    Node *current = headRef;

    while (current->next != NULL)
    {
        printf("%d->", current->data);
        current = current->next;
    }
    printf("NULL");
}

void freeList(Node *head)
{
    Node *temp;
    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}