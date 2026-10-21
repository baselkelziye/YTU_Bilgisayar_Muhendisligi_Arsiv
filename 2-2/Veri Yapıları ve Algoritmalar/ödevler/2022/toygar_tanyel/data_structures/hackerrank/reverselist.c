// https://www.hackerrank.com/challenges/reverse-a-doubly-linked-list/problem

DoublyLinkedListNode* reverse(DoublyLinkedListNode* head) {
    DoublyLinkedListNode* iter = head;
    DoublyLinkedListNode* temp;
    
    while(iter != NULL){
        temp = iter->next;
        iter->next = iter->prev;
        iter->prev = temp;
        head = iter;
        iter = temp;
    }
    
    return head;
}