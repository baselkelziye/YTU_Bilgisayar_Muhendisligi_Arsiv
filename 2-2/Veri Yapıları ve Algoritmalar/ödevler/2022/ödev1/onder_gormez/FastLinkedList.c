#include "FastLinkedList.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ELEMENT_COUNT 10

int calculateMaxLevelSize(int arrayLength)
{
    int levelSize = 2; /* Level 1 and Last Level(Empty Level) is guaranteed. */
    int tempArrayLength = arrayLength;

    while (tempArrayLength > 1) {
        tempArrayLength = (tempArrayLength + 1) / 2;
        levelSize++;
    }

    return levelSize;
}

FastLinkedListNode_t* createFastLinkedListNode()
{
    /* TODO: initializes all bytes in the allocated storage to zero */
    FastLinkedListNode_t* newNode = (FastLinkedListNode_t*)malloc(sizeof(FastLinkedListNode_t));

    if (newNode == NULL) {
        printf("In function createFastLinkedListNode(): Memory allocation error");
        exit(EXIT_FAILURE);
    }

    newNode->previous = NULL;
    newNode->next = NULL;
    newNode->value = NULL;

    return newNode;
}

FastLinkedListNode_t* insertHead(FastLinkedListNode_t* tail, DoublyLinkedListNode_t* value)
{
    FastLinkedListNode_t* newNode = createFastLinkedListNode();
    tail->next = newNode;

    newNode->previous = tail;
    newNode->next = NULL;
    newNode->value = value;

    return newNode;
}

void printHeads(FastLinkedListNode_t* tail)
{
    printf("********************* Heads *********************\n");

    /* Reversed print operation */
    FastLinkedListNode_t* current = NULL;
    for (current = tail; current != NULL; current = current->previous)
        if (current->value != NULL)
            printf("Node Address: 0x%p, Head Address Value: 0x%p\n", current, current->value);
}

FastLinkedListNode_t* createFastLinkedListLevels(FastLinkedListNode_t* headsOfFastLinkedList, DoublyLinkedListNode_t* downLevelHead, int downLevelNodeCount)
{
    static int level = 2;
    static FastLinkedListNode_t* tailOfHeadsLinkList = NULL;
    bool isAlreadyGenerated[MAX_ELEMENT_COUNT] = { 0 };

    int nodeCount = (downLevelNodeCount + 1) / 2;

    /* seed with current time */
    srand((unsigned)time(NULL));

    int generatedNodeCount = 0;
    while (generatedNodeCount < nodeCount) {

        /* Get random index to first linked list node */
        int index = rand() % downLevelNodeCount;

        if (isAlreadyGenerated[index])
            continue;

        isAlreadyGenerated[index] = true;

        ++generatedNodeCount;
    }

    DoublyLinkedListNode_t* head = createNode();
    DoublyLinkedListNode_t* currentNode = NULL;
    DoublyLinkedListNode_t* tail = NULL;
    int index = 0;
    for (index = 0; index < MAX_ELEMENT_COUNT; ++index) {

        if (isAlreadyGenerated[index] == false)
            continue;

        currentNode = getLinkedListNode(downLevelHead, index);

        if (tail == NULL)
            tail = insertNode(head, currentNode->value);
        else
            tail = insertNode(tail, currentNode->value);
    }

    printf("********************* %d. Level *********************\n", level++);
    printf("Head Address: 0x%p\n", (void*)head);
    printLinkedList(head);

    if (tailOfHeadsLinkList == NULL)
        tailOfHeadsLinkList = insertHead(headsOfFastLinkedList, downLevelHead);

    tailOfHeadsLinkList = insertHead(tailOfHeadsLinkList, head);

    if (nodeCount == 1) {
        return tailOfHeadsLinkList;
    }

    return createFastLinkedListLevels(tailOfHeadsLinkList, head, nodeCount);
}

void findValue(FastLinkedListNode_t* tailOfHeadsLinkedList, int searchedValue)
{
    /* TODO: Use function for max level :) */
    int currentLevel = 5;
    /* TODO: reverse search heads of linked list */
    FastLinkedListNode_t* current = NULL;
    for (current = tailOfHeadsLinkedList; current != NULL; current = current->previous) {
        printf("Searching in the level %d...\n", currentLevel);
        if (current->value != NULL) {
            DoublyLinkedListNode_t* node = searchValueInLinkedList(current->value, searchedValue);

            if (node != NULL) {
                printf("Find in the %d. Level\n", currentLevel);
                return;
            }
        }

        --currentLevel;
    }

    printf("Value not find in any level!\n");
}

void insertValueEachLevel(FastLinkedListNode_t* headsOfFastLinkedList, int valueToBeAdd)
{
    int currentLevel = 1;

    /* actualLength getLinkedListLength(currentHead->value); */

    FastLinkedListNode_t* currentHead = NULL;
    for (currentHead = headsOfFastLinkedList->next; currentHead != NULL; currentHead = currentHead->next) {

        /* İlk seviye ise kesin ekle */
        if (currentHead->previous == headsOfFastLinkedList) {
            insertNodeWithOrder(currentHead->value, valueToBeAdd);
            /* TODO: Debug print */
            printf("Adding to the %d. Level...\n", currentLevel++);
            printLinkedList(currentHead->value);
            continue;
        }

        /* TODO: Son seviyedeysek? */

        int expectedLength = (getLinkedListLength(currentHead->previous->value) + 1) / 2;
        int actualLength = getLinkedListLength(currentHead->value);

        if (expectedLength != actualLength) {
            insertNodeWithOrder(currentHead->value, valueToBeAdd);
            printf("Adding to the %d. Level...\n", currentLevel++);
            printLinkedList(currentHead->value);
            continue;
        }

        ++currentLevel;
    }

    /* 5. Seviye: 1  5. Seviye: 1 */
    /* 4. Seviye: 2  4. Seviye: 2 */
    /* 3. Seviye: 3  3. Seviye: 3 */
    /* 2. Seviye: 5  2. Seviye: 5 */
    /* 1. seviye: 9  1. seviye: 10 */

    /* 5. Seviye: 1   5. Seviye: 1 */
    /* 4. Seviye: 2   4. Seviye: 2 */
    /* 3. Seviye: 3   3. Seviye: 3 */
    /* 2. Seviye: 5   2. Seviye: 6 */
    /* 1. seviye: 10  1. seviye: 11 */

    /* 5. Seviye: 1   5. Seviye: 1 */
    /* 4. Seviye: 2   4. Seviye: 2 */
    /* 3. Seviye: 25   3. Seviye: 26 */
    /* 2. Seviye: 50   2. Seviye: 51 */
    /* 1. seviye: 100  1. seviye: 101 */
}

void deleteValueFromEachLevel(FastLinkedListNode_t* headsOfFastLinkedList, int valueToBeDeleted)
{
    int currentLevel = 1;
    FastLinkedListNode_t* currentHead = NULL;
    for (currentHead = headsOfFastLinkedList->next; currentHead != NULL; currentHead = currentHead->next) {
        DoublyLinkedListNode_t* nodeToBeDeleted = searchValueInLinkedList(currentHead->value, valueToBeDeleted);

        /* Silinecek değer zaten bu seviyede yok! */
        if (nodeToBeDeleted == NULL) {
            printf("Value not found in %d. Level. Skipping...\n", currentLevel++);
            continue;
        }

        printf("Deleting value from the %d. Level...\n", currentLevel++);

        deleteNode(nodeToBeDeleted);
    }
}