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

link * deleteElement(link * head, int val,int* n){
	link * curr,*add,*support,*forFree;
	int i=1;
	for(support = head; support->down!=NULL; support = support->down){}	
	curr=support;
	while(curr->next != NULL && curr->next->val < val){
		curr=curr->next;
		i++;
	}
    if(curr->next != NULL && curr->next->val != val){
    	printf("eleman mevcut degil.  Gormek icin yazdir.\n\n");
    	return head;
    }
	else if(curr->next == NULL){
		printf("eleman mevcut degil.  Gormek icin yazdir.\n\n");
		return head;
	}
	else{
        printf("Eleman Silindi!  Gormek icin yazdir. \n\n");
        forFree = curr->next;
        curr->next =curr->next->next;
        free(forFree);
        head=freeBeforeHead(head);
		return createSkipList(head, --(*n));
        return head;
    }	
	
}
link * addElement(link * head, int val,int* n){
	link * curr,*add,*support;
	int i=1;
	add=(link*)malloc(sizeof(link));
	add->val=val;
	add->down=NULL;
	add->next=NULL;
	for(support = head; support->down!=NULL; support = support->down){}	
	curr=support;
	while(curr->next != NULL && curr->next->val < val){
		curr=curr->next;
		i++;
	}
    if(curr->next != NULL && curr->next->val != val){//araya eklemek için
    	add->next = curr->next;
    	curr->next = add;
    	printf("\nEleman Eklendi!  Gormek icin yazdir. \n");
    	head=freeBeforeHead(head);
    	return createSkipList(head, ++(*n));
    }
	else if(curr->next == NULL){
		curr->next=add;
		printf("\nEleman Eklendi! Gormek icin yazdir. \n");
		head=freeBeforeHead(head);
		return createSkipList(head, ++(*n));
	}
	else{
        printf("Eleman mevcuttur. Ekleme yapamazsiniz.  Gormek icin yazdir. \n\n");
        return head;
    }	
	
}
link* elemanBul(link* head, int loc) {
    int i;
    for (i = 0; i < loc; i++) {
        head = head->next;
    }
    return head;
}
link* getRandomLink(link* head, int ndown,int hangi_eleman, int* kalan) {
    int randomSayi,n;
    srand(time(NULL));
    n = (ndown+1)/2;
    randomSayi = rand() % (*kalan+hangi_eleman-n);
    *kalan -= randomSayi+1;
    return elemanBul(head, randomSayi+1);

}
link* createSkipList(link* head, int ndown) {
    link* currHead, * prev, * current, * newNode, * tmp, *starter;
   // int * headList = head;
   int *kat = 0;
    int i, lower = 0,n,kalan;
    n = (ndown+1)/2;
    kalan = ndown;
    if (n == 1) {
        currHead = (link*)malloc(1 * sizeof(link));
        currHead->down = head;
        newNode = (link*)malloc(sizeof(link));
        currHead->next = newNode;
        newNode->next = NULL;
        kalan = 2;
        tmp = getRandomLink(head, ndown,1,&kalan);
        newNode->val = tmp->val;
        newNode->down = tmp;
        prev = (link*)malloc(sizeof(link));
        prev->down = currHead;
        prev->next = NULL;
      //  headList = (int*)malloc(1*sizeof(int));
        *kat++;
        //printf("\n\n kat sayimiz: %d \n\n",kat);
        return prev;
    }
    else {
        currHead = (link*)malloc(1 * sizeof(link));
        currHead->down = head;
        current = currHead;
        starter = head;
        for (i = 0; i < n; i++) {
            newNode = (link*)malloc(sizeof(link));
            current->next = newNode;
            tmp = getRandomLink(starter, ndown,i+1,&kalan);
            starter = tmp;
            newNode->val = tmp->val;
            newNode->down = tmp;
            current = newNode;
            newNode = NULL;
        }
        *kat++;
        //printf("\n\n kat sayimiz: %d",kat);
        current->next = NULL;
        head = createSkipList(currHead, (ndown + 1) / 2);
        return head;
    }
}
void * searchElement(link *curr, int num){
	while(curr->next != NULL && curr->next->val<=num){
		curr = curr->next;
	}
	if(curr->val == num){
				link * support;
				int kat = 1;
				for(support = curr; support->down!=NULL; support = support->down){
				kat++;
				}
				printf("aranan sayi %d. seviyede bulundu.  Gormek icin yazdir.\n\n",kat);
				return;
	}else{
			if(curr->down == NULL){
				printf("%d numarali eleman listede yok.  Gormek icin yazdir. \n\n", num);
				return;				
				}
			else{
				curr=curr->down;//yeni starter ile arama
				searchElement(curr,num);
			}	
		}
	
}
	


int main(){
    int i, n, tmp, choice;
    link* head, * linkTmp, * curr, *currv2;
    head = (link*)malloc(sizeof(link));
    head->down=NULL;
    head->next=NULL;
    curr = head;
    printf("Lutfen eleman sayisini giriniz\t");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        linkTmp = (link*)malloc(sizeof(link));
        printf("Lutfen %d. elemani giriniz\t", i + 1);
        scanf("%d", &tmp);
        linkTmp->val = tmp;
        linkTmp->down = NULL;
        linkTmp->next = NULL;
        curr->next = linkTmp;
        curr = curr->next;
    }
    head = createSkipList(head, n);
    printf("\n\n");
    do{
    	printf("\n\n");
        printf("Eklemek icin 1 \n Silmek icin 2 \n Aramak icin 3 \n Yazdirmak icin 4\n Cikis icin 0\n: \t");
        printf("\n");
        scanf("%d",&choice);
        printf("\n");
        switch (choice){
            case 1:
                printf("eklenecek elemani giriniz: \t");
                scanf("%d",&tmp);
                printf("\n");
                head = addElement(head,tmp,&n);
                break;
            case 2:
                printf("silinecek elemani giriniz: \t");
                scanf("%d",&tmp);
                printf("\n");
                head = deleteElement(head,tmp,&n); 
                break;  
            case 3:
                printf("aranacak elemani giriniz: \t");
                scanf("%d",&tmp);
                printf("\n");
                searchElement(head,tmp);
                break;
            case 4:
                printf("\n\n~");
                printList(head);
                
                break;
            case 0:
                printf("Cikis yapildi\n\n\n");
                break;
            default:
                printf("Duzgun deger gir\n\n");
        }

    }while(choice);
    
    return 0;
}
