#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 20 // Bir website'nin en fazla 20 karaktere sahip olabileceği düşünülmüştür.
#define THRESHOLD 10
#define LENGTH 5

typedef struct doubleLinkedList{
    char website[N];
    int counter;
    struct doubleLinkedList *next;
    struct doubleLinkedList *back;

}NODE;

NODE *setFirstHead(char website[N]);
NODE* traverseList_addNode(NODE *head, char website[N],int *nodeAmount);
NODE *setHeadNode(NODE *currHead, char website[N]);
void printList(NODE *head);
NODE *setHeadNodeV2(NODE *currHead, NODE *newHead);
NODE *lastNodeDeleter(NODE *head);
NODE* clearCache(NODE *head, int *nodeAmount);
NODE* readNodeFromFile();

int main(){
    NODE *head= NULL;
    char website[N];
    int choice = 0;
    int flag=1, flag2=1;
    int nodeAmount=0;
    
    while(flag)
    {
        choice =0;
        while(choice != 1 && choice != 2)
        {
            printf("1-Dosya oku:\n2-Deger gir:\n");
            scanf("%d",&choice);
        }
        if(choice == 1)
        {
            head = readNodeFromFile();
            printList(head);        
        }
        else if(choice == 2)
        {
            while(flag2)
            {
                scanf("%s",website);
                head = traverseList_addNode(head, website, &nodeAmount);
                if(nodeAmount > LENGTH)
                {
                    head=lastNodeDeleter(head);
                    nodeAmount--;
                }
                printList(head);
            }
        }
        printf("1-Close\n2-Clear Cache\n3-Continue");
        scanf("%d",&flag);
        flag--;
        if(flag==1)
        {
            head=clearCache(head,&nodeAmount);
        }
    }

    NODE *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
NODE* readNodeFromFile() //Dosyadan veri çekimini sağlayıp node'lara aktarıp LinkedList'in headini döndüren fonksiyon.
{
    NODE* head=NULL;
    FILE *file;
    int nodeAmount=0;
    char line[30];

    file = fopen("websites.txt","r");
    if(file == NULL)
    {
        printf("Error opening the file.\n");
        return NULL;
    }

    while(fgets(line,sizeof(line),file) != NULL){
        size_t length = strlen(line);
            if (line[length - 1] == '\n') //'\n' karakterinden kurtulmayı saglar bu sayede veriler daha guzel şekilde yazdırılır.
            {
                line[length - 1] = '\0';
            }
        head = traverseList_addNode(head,line,&nodeAmount);
        if(nodeAmount > LENGTH)
        {
            head=lastNodeDeleter(head);
            nodeAmount--;
        }
    }
    return head;

}
NODE* clearCache(NODE *head, int *nodeAmount) // Listeyi temizler head'i null olarak döndürür.
{
    NODE *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
    *nodeAmount = 0;
    return NULL;
}

void printList(NODE *head)// Listenin yazdırılmasını sağlar.
{
    NODE* iter=head;
    while(iter != NULL)
    {
        if(iter == head)
        {
            printf("%s,%d",iter->website,iter->counter);
        }
        else
        {
            printf(" <=> %s,%d",iter->website,iter->counter);
        }
        iter= iter->next;
    }
    printf("\n");
}
NODE* traverseList_addNode(NODE *head, char website[N],int *nodeAmount){
    //LinkedList'in icinde gezinip gelen website'nin varlıgı kontrol eder, bulunuyorsa counter'ı 1 arttırır bulunmuyorsa -
    // yeni node oluşturarak onu head yapar. En son head pointerini döndürür.
    // Eger threshold değerini aşan bir websitesi varsa onun head olması için gerekli yönlendirmeyi yapar.
    NODE* iter=head;
    int flag=1;
    while(iter != NULL && flag)
    {
        if(strcmp(iter->website, website) == 0) // websitenin varlığını kontrol etme
        {
            (iter->counter)++;
            if(iter->counter > 10 && iter->counter > head->counter)
            {
                head=setHeadNodeV2(head,iter);
                flag = 0;
                return head;
            }
            return head;
        }
        iter=iter->next;
    }
    if(iter == NULL) // websitesi bulunmuyorsa buraya gelir
    {
        if(head == NULL)// eğer listemiz boşsa 
        {
            head= setFirstHead(website);
            (*nodeAmount)++;
            return head;
        }
        else{
            head=setHeadNode(head, website);
            (*nodeAmount)++;
            return head;
        }
    }    
}
NODE *lastNodeDeleter(NODE *head)// Node sayisi limiti aştığında en sonda bulunan node'u silmeye yarar.
{
    NODE *iter=head;
    while(iter->next != NULL)
    {
        iter=iter->next;
    }
    iter->back->next=NULL;
    free(iter);
    return head;
}
NODE *setFirstHead(char website[N])// Head null ise ilk olarak bu fonksiyonu kullanarak ilk head bağlanır.
{
    NODE *head;
    head=(NODE*)malloc(sizeof(NODE));
    strcpy(head->website, website);
    head->next=NULL;
    head->back=NULL;
    head->counter=1;
    return head;
}
NODE *setHeadNodeV2(NODE *currHead, NODE *newHead)// Bir websitesi threshold değerini aştığında onun head olarak atanmasını sağlar.
{
    if(newHead->next == NULL)
    {
        newHead->back->next=NULL;
        newHead->next=currHead;
        newHead->back=NULL;
        currHead->back=newHead;
        return newHead;
    }
    else
    {
        newHead->back->next=newHead->next;
        newHead->next->back=newHead->back;
        newHead->next=currHead;
        newHead->back=NULL;
        currHead->back=newHead;
        return newHead;
    }
}

NODE *setHeadNode(NODE *currHead, char website[N])// Yeni bir websitesi eklendiğinde onun head olarak depolanmasını sağlar.
{
    NODE *newNode;
    newNode=(NODE*)malloc(sizeof(NODE));
    strcpy(newNode->website, website);
    newNode->back=currHead->back;
    currHead->back = newNode;
    newNode->next = currHead;
    newNode->counter=1;
    return newNode;
}