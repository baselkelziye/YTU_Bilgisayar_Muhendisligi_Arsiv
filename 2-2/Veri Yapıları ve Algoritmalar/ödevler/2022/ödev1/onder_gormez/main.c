#include <stdio.h>
#include <stdbool.h>

#include "DoublyLinkedList.h"
#include "FastLinkedList.h"

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
