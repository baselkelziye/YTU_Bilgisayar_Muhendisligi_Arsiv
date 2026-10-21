// https://www.hackerrank.com/challenges/merge-two-sorted-linked-lists/problem

SinglyLinkedListNode* mergeLists(SinglyLinkedListNode *headA, SinglyLinkedListNode* headB)
{
    if (headA == NULL) 
        return headB;
    if (headB == NULL) 
        return headA;
        
    // Ensure that list A starts with the smaller number
    if (headA->data > headB->data) {
        SinglyLinkedListNode *tmp = headB;
        headB = headA;
        headA = tmp;
    }

    // Create an iteration pointer to traverse on the list A without losing its head
    SinglyLinkedListNode *iter = headA;

    while (headB) {
        /* Traverse through nodes in list A until the next node
         has data bigger than data at current node of list B */
        while (iter->next != NULL && headB->data > iter->next->data) 
            iter = iter->next;
        
        // Insert current node in list B into list A
        SinglyLinkedListNode* nextB = headB->next;
        headB->next = iter->next;
        iter->next = headB;
        headB = nextB;
    }
    return headA;
}