#include "DoublyLinkedList.h"

#include <stdio.h>
#include <stdlib.h>

DoublyLinkedListNode_t* createNode()
{
    /* TODO: initializes all bytes in the allocated storage to zero */
    DoublyLinkedListNode_t* newNode = (DoublyLinkedListNode_t*)malloc(sizeof(DoublyLinkedListNode_t));

    if (newNode == NULL) {
        printf("In function createNode(): Memory allocation error");
        exit(EXIT_FAILURE);
    }

    newNode->previous = NULL;
    newNode->next = NULL;
    newNode->value = 0;

    return newNode;
}

void printLinkedList(DoublyLinkedListNode_t* head)
{
    DoublyLinkedListNode_t* current = NULL;
    for (current = head->next; current != NULL; current = current->next)
        printf("Node Address: 0x%x, Node Value: %d\n", current, current->value);
}

void printNode(DoublyLinkedListNode_t* node)
{
    printf("Node Address: 0x%x, Node Value: %d\n", node, node->value);
}

DoublyLinkedListNode_t* insertNode(DoublyLinkedListNode_t* tail, int value)
{
    DoublyLinkedListNode_t* newNode = createNode();
    tail->next = newNode;

    newNode->previous = tail;
    newNode->next = NULL;
    newNode->value = value;

    return newNode;
}

DoublyLinkedListNode_t* insertNodeWithOrder(DoublyLinkedListNode_t* head, int value)
{
    DoublyLinkedListNode_t* newNode = createNode();
    newNode->value = value;

    /* [] boş bir linkli listeye 10 değeri eklemek istersek [10] */
    if (head->next == NULL) {
        head->next = newNode;

        newNode->previous = head;
        newNode->next = NULL;
        return newNode;
    }

    DoublyLinkedListNode_t* currentNode = NULL;
    for (currentNode = head->next; currentNode != NULL; currentNode = currentNode->next) {

        if (value > currentNode->value) {
            /* [3 5 9 15] linkli listesine 20 değeri eklemek istersek [3 5 9 15 20] */
            if (currentNode->next == NULL) {
                currentNode->next
                    = newNode;

                newNode->previous = currentNode;
                newNode->next = NULL;
                return newNode;
            }
            continue;
        }

        /* [3 5 9 15] linkli listesine 1 değeri eklemek istersek [1 3 5 9 15] */
        if (currentNode->previous == head) {
            head->next = newNode;

            newNode->previous = head;
            newNode->next = currentNode;
            currentNode->previous = newNode;

            return newNode;
        }

        /* [3 5 9 15] linkli listesine 6 değeri eklemek istersek [3 5 6 9 15] */
        /* [3 5 9 15] linkli listesine 9 değeri eklemek istersek [3 5 9 9 15] */
        newNode->previous = currentNode->previous;
        currentNode->previous->next = newNode;
        currentNode->previous = newNode;
        newNode->next = currentNode;

        return newNode;
    }

    return newNode;
}

bool deleteNode(DoublyLinkedListNode_t* node)
{
    if (node == NULL) {
        printf("In function deleteNode(): Null node pointer supplied");
        return true;
    }

    /* Head */
    if (node->previous == NULL) {

        /* 1 element in the linked list */
        if (node->next == NULL) {
            free(node);
            return true;
        }

        /* Remove the pointer to head and become a new head */
        node->next->previous = NULL;
        free(node);
        return true;
    }

    /* Tail */
    if (node->next == NULL) {
        node->previous->next = NULL;
        free(node);
        return true;
    }

    /* In the middle */
    node->previous->next = node->next;
    node->next->previous = node->previous;
    free(node);
    return true;
}

int getLinkedListLength(DoublyLinkedListNode_t* head)
{
    int length = 0;
    DoublyLinkedListNode_t* current = NULL;
    for (current = head->next; current != NULL; current = current->next)
        ++length;

    return length;
}

DoublyLinkedListNode_t* getLinkedListNode(DoublyLinkedListNode_t* head, int index)
{
    int currentIndex = 0;
    DoublyLinkedListNode_t* current = NULL;
    for (current = head->next; current != NULL; current = current->next) {
        if (currentIndex == index) {
            return current;
        }

        ++currentIndex;
    }

    printf("In function getLinkedListNode(): Index not found in the linked list!\n");
    return NULL;
}

DoublyLinkedListNode_t* searchValueInLinkedList(DoublyLinkedListNode_t* head, int searchedValue)
{
    int currentIndex = 0;
    DoublyLinkedListNode_t* current = NULL;
    for (current = head->next; current != NULL; current = current->next) {

        if (current->value == searchedValue) {
            printf("Value found  in the %d. index of linked list\n", currentIndex);
            return current;
        }

        ++currentIndex;
    }

    return NULL;
}
