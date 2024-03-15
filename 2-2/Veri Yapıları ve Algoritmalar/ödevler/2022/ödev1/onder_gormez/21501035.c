/* ****************** DoublyLinkedList.h ****************** */

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

/* ****************** DoublyLinkedList.c ****************** */
/* #include "DoublyLinkedList.h" */

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

/* ****************** FastLinkedList.h ****************** */

/* #include "DoublyLinkedList.h" */

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

/* ****************** FastLinkedList.c ****************** */

/* #include "FastLinkedList.h" */

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

/* ****************** main.c ****************** */

#include <stdbool.h>
#include <stdio.h>

/* #include "DoublyLinkedList.h" */
/* #include "FastLinkedList.h" */

int main(void)
{
    printf("Fast Linked List Implementation\n");
    /* FastLinkedListNode_t* list = NULL;  TODO: malloc and zerois */
    DoublyLinkedListNode_t* firstLevelHead = createNode();

    DoublyLinkedListNode_t* tail = insertNode(firstLevelHead, 0);
    tail = insertNode(tail, 1);
    tail = insertNode(tail, 2);
    tail = insertNode(tail, 3);
    tail = insertNode(tail, 4);
    tail = insertNode(tail, 5);
    tail = insertNode(tail, 6);
    tail = insertNode(tail, 7);
    tail = insertNode(tail, 8);
    tail = insertNode(tail, 9);

    printLinkedList(firstLevelHead);

    int length = getLinkedListLength(firstLevelHead);
    printf("Length of the linked list: %d\n", length);

    /*    createLevel((length + 1) / 2); */

    DoublyLinkedListNode_t* currentNode = getLinkedListNode(firstLevelHead, 7);
    printNode(currentNode);

    currentNode = getLinkedListNode(firstLevelHead, 12);

    printf("********************* 1. Level *********************\n");
    printf("Head Address: 0x%x\n", firstLevelHead);
    printLinkedList(firstLevelHead);

    FastLinkedListNode_t* headsOfFastLinkedList = createFastLinkedListNode();
    FastLinkedListNode_t* tailOfHeadsLinkedList = createFastLinkedListLevels(headsOfFastLinkedList, firstLevelHead, length);
    printHeads(tailOfHeadsLinkedList);

    findValue(tailOfHeadsLinkedList, 8);

    /* TODO: Küçükten büyüğe sıralı bir linki listeye ekleme işlemini sırayı koruyarak yapar */
    /* [{3, 5, 9, 15}] linkli listesine 6 değeri eklemek istersek [3 5 6 9 15] */
    /* [{3, 5, 9, 15}] linkli listesine 1 değeri eklemek istersek [1 3 5 9 15] */
    /* [{3, 5, 9, 15}] linkli listesine 20 değeri eklemek istersek [3 5 9 15 20] */
    /* [{3, 5, 9, 15}] linkli listesine 9 değeri eklemek istersek [3 5 9 9 15] */
    /* DoublyLinkedListNode_t* insertNodeWithOrder(DoublyLinkedListNode_t* head, int value); */
    DoublyLinkedListNode_t* testHead = createNode();
    DoublyLinkedListNode_t* testTail = NULL;

    int inputData2[4] = { 3, 5, 9, 15 };
    int arraySize = sizeof(inputData2) / sizeof(inputData2[0]);
    printf("Size of inputArray is %d \n", arraySize);

    int k = 0;
    for (k = 0; k < arraySize; k++) {
        if (k == 0) {
            testTail = insertNode(testHead, inputData2[k]);
            continue;
        }

        testTail = insertNode(testTail, inputData2[k]);
    }

    printLinkedList(testHead);
    printf("********************* 6 Ekliyoruz *********************\n");
    insertNodeWithOrder(testHead, 6);
    printLinkedList(testHead);
    printf("********************* 1 Ekliyoruz *********************\n");
    insertNodeWithOrder(testHead, 1);
    printLinkedList(testHead);
    printf("********************* 20 Ekliyoruz *********************\n");
    insertNodeWithOrder(testHead, 20);
    printLinkedList(testHead);
    printf("********************* 9 Ekliyoruz *********************\n");
    insertNodeWithOrder(testHead, 9);
    printLinkedList(testHead);

    insertValueEachLevel(headsOfFastLinkedList, 30);

    deleteValueFromEachLevel(headsOfFastLinkedList, 30);

    return 0;
}
