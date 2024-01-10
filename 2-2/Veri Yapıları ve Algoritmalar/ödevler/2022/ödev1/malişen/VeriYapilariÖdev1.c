#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>
typedef struct Link {
    int val;
    struct Link* next;
    struct Link* down;
}link;
link* createSkipList(link* head, int n) ;
void printList(link* head) {
    link* curr;
    while (head->down != NULL) {
        head = head->down;
        curr = head->next;
        while (curr != NULL) {
            printf("%d--", curr->val);
            curr = curr->next;
        }
        printf("\n-----------------------------------\n");
    }

}
link * freeBeforeHead(link * head){
	link * curr,* headPrev,*prev;
	while (head->down != NULL) {
	headPrev=head;
	head = head->down;
	curr=headPrev->next;
	free(headPrev);
	while (curr != NULL) {
            prev=curr;
            curr = curr->next;
            free(prev);
        }
	}
	return head;
}
link * deleteElement(link * head, int val){
	link * curr,*prev;
	int i=1;
	head=freeBeforeHead(head);
	curr=head->next;
	while(curr->next!=NULL){
		curr=curr->next;
		i++;
	}
	curr=head->next;
	prev=curr->next;
	while(curr->val!=val){
		prev=curr;
		curr=curr->next;
	}
    if(curr != NULL){
        if(curr->next!=NULL)
	prev->next=curr->next->next;
	else
	prev->next=NULL;
	free(curr);
	i--;
    }else
    printf("Eleman Bulunamadi \n");

    return createSkipList(head, (i+1)/2);
	

}
link * addElement(link * head, int val){
	link * curr,*add;
	int i=1;
	add=(link*)malloc(sizeof(link));
	add->val=val;
	add->down=NULL;
	add->next=NULL;
	head=freeBeforeHead(head);
	curr=head->next;
	while(curr->next!=NULL || curr->val != val){
		curr=curr->next;
		i++;
	}
    if(curr->val != val){
        curr->next=add;
    	i++;
    }else{
        printf("Eleman mevcuttur. Ekleme yapamazsiniz. \n");
    }
	
	return createSkipList(head, (i+1)/2);
	
}
link* elemanBul(link* head, int loc) {
    int i;
    for (i = 0; i < loc; i++) {
        head = head->next;
    }
    return head;
}
link* getRandomLink(link* head, int n, int* lower) {
    int randomSayi;
    srand(time(NULL));
    randomSayi = rand() % 2 + ((*lower)+1);
    if(randomSayi==(*lower)){
    	randomSayi++;
	}
	if(randomSayi>n){
		randomSayi=n-1;
	}
    (*lower) = randomSayi;
    return elemanBul(head, randomSayi);

}
link* createSkipList(link* head, int n) {
    link* currHead, * prev, * current, * newNode, * tmp;
    int i, lower = 0;
    if (n == 1) {
        currHead = (link*)malloc(1 * sizeof(link));
        currHead->down = head;
        newNode = (link*)malloc(sizeof(link));
        currHead->next = newNode;
        newNode->next = NULL;
        tmp = getRandomLink(head, n, &lower);
        newNode->val = tmp->val;
        newNode->down = tmp;
        prev = (link*)malloc(sizeof(link));
        prev->down = currHead;
        prev->next = NULL;
        return prev;
    }
    else {
        currHead = (link*)malloc(1 * sizeof(link));
        currHead->down = head;
        current = currHead;
        for (i = 0; i < n; i++) {
            newNode = (link*)malloc(sizeof(link));
            current->next = newNode;
            tmp = getRandomLink(head, n, &lower);
            newNode->val = tmp->val;
            newNode->down = tmp;
            current = newNode;
            newNode = NULL;
        }
        current->next = NULL;
        head = createSkipList(currHead, (n + 1) / 2);
        return head;
    }
}
int main(){
    int i, n, tmp, choice;
    link* head, * linkTmp, * curr;
    head = (link*)malloc(sizeof(link));
    head->down=NULL;
    head->next=NULL;
    curr = head;
    printf("Lutfen eleman sayisini giriniz\n");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        linkTmp = (link*)malloc(sizeof(link));
        printf("Lutfen %d. elemani giriniz\n", i + 1);
        scanf("%d", &tmp);
        linkTmp->val = tmp;
        linkTmp->down = NULL;
        linkTmp->next = NULL;
        curr->next = linkTmp;
        curr = curr->next;
    }
    head = createSkipList(head, (n + 1) / 2);
    do{
        printf("Eklemek icin 1 \n Silmek icin 2 \n Aramak icin 3 \n Cikis icin 0");
        scanf("%d",&choice);
        switch (choice){
            case 1:
                printf("eklenecek elemani giriniz");
                scanf("%d",&tmp);
                head = addElement(head,tmp); 
                break;
            case 2:
                printf("silinecek elemani giriniz");
                scanf("%d",&tmp);
                head = deleteElement(head,tmp); 
                break;  
            case 3:
                printf("aranacak elemani giriniz");
                scanf("%d",&tmp);
                //arama finksiyonu ekle
                break;
            case 0:
                printf("Cikis yapildi\n");
                break;
            default:
                printf("Duzgun deger gir\n");
        }

    }while(choice);
    
    printList(head);
    head=addElement(head,15);
    printf("\n\n");
    printList(head);
    head=deleteElement(head,15);
    printf("\n\n");
    printList(head);
    return 0;
}
