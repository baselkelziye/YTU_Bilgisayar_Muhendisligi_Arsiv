#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
} Node;

Node *createNode(int data);
void appendNode(Node **headRef, int data);
void printList(Node *headRef);
void freeList(Node *head);
void insertList(Node **headRef, int data);

int main()
{
    Node *head = createNode(10);

    appendNode(&head, 20);
    appendNode(&head, 30);
    appendNode(&head, 40);
    appendNode(&head, 50);

    insertList(&head, 25);

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
    node->prev = NULL;

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

void insertList(Node **headRef, int data)
{
    Node *current = *headRef;
    Node *new_node = createNode(data);

    if (*headRef == NULL)
    {
        *headRef = new_node;
    }

    while (current->next != NULL && current->next->data < data)
    {
        current = current->next;
    }
    printf("Current: %d\n", current->data);

    Node *temp = current->next;

    current->next = new_node;
    new_node->next = temp;
}

void deleteNode(Node **headRef, int data)
{
    Node *current = *headRef;
    Node *prev = NULL;

    // Handle the case where the head node is to be deleted
    if (current != NULL && current->data == data)
    {
        *headRef = current->next;
        free(current);
        return;
    }

    // Traverse the list to find the node to delete
    while (current != NULL && current->data != data)
    {
        prev = current;
        current = current->next;
    }

    // If the node was not found
    if (current == NULL)
    {
        printf("Node not exists!\n");
        return;
    }

    // Update the pointers to remove the node
    prev->next = current->next;

    free(current);
}
