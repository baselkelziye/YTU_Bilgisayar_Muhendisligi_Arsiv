#pragma once

#include "DoublyLinkedList.h"

typedef struct FastLinkedListNode {
    DoublyLinkedListNode_t* value;
    struct FastLinkedListNode* previous;
    struct FastLinkedListNode* next;
} FastLinkedListNode_t;

/* TODO: Use DoublyLinkedListNode_t in all */
/* Creates linked list node and returns the pointer of the created node */
FastLinkedListNode_t* createFastLinkedListNode();

/* TODO: Inserts new node from the rear of the linked list */
FastLinkedListNode_t* insertHead(FastLinkedListNode_t* tail, DoublyLinkedListNode_t* value);

/* TODO: Prints all nodes in the linked list */
void printHeads(FastLinkedListNode_t* head);

FastLinkedListNode_t* createFastLinkedListLevels(FastLinkedListNode_t* headsOfFastLinkedList, DoublyLinkedListNode_t* downLevelHead, int downLevelNodeCount);

void findValue(FastLinkedListNode_t* tailOfHeadsLinkedList, int searchedValue);

void deleteValueFromEachLevel(FastLinkedListNode_t* headsOfFastLinkedList, int valueToBeDeleted);