#pragma once

#include <stdbool.h>

typedef struct DoublyLinkedListNode {
    int value;
    struct DoublyLinkedListNode* previous;
    struct DoublyLinkedListNode* next;
} DoublyLinkedListNode_t;

/* TODO: Use DoublyLinkedListNode_t in all */
/* Creates linked list node and returns the pointer of the created node */
DoublyLinkedListNode_t* createNode();

/* Prints all nodes in the linked list*/
void printLinkedList(DoublyLinkedListNode_t* head);

void printNode(DoublyLinkedListNode_t* node);

/* TODO: Inserts new node from the rear of the linked list */
DoublyLinkedListNode_t* insertNode(DoublyLinkedListNode_t* tail, int value);

/* TODO: Küçükten büyüğe sıralı bir linki listeye ekleme işlemini sırayı koruyarak yapar */
/* [3 5 9 15] linkli listesine 6 değeri eklemek istersek [3 5 6 9 15] */
/* [3 5 9 15] linkli listesine 1 değeri eklemek istersek [1 3 5 9 15] */
/* [3 5 9 15] linkli listesine 20 değeri eklemek istersek [3 5 9 15 20] */
/* [3 5 9 15] linkli listesine 9 değeri eklemek istersek [3 5 9 9 15] */
DoublyLinkedListNode_t* insertNodeWithOrder(DoublyLinkedListNode_t* head, int value);

/* TODO: Add comment */
bool deleteNode(DoublyLinkedListNode_t* node);

int getLinkedListLength(DoublyLinkedListNode_t* head);

DoublyLinkedListNode_t* getLinkedListNode(DoublyLinkedListNode_t* head, int index);


DoublyLinkedListNode_t* searchValueInLinkedList(DoublyLinkedListNode_t* head, int searchedValue);
