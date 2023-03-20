#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct LinkedList{
    int date;
    struct LinkedList *Next;
    struct LinkedList *NextLevel;
};

struct LinkedList* constructList(struct LinkedList*,int, int*);
void LinkedListYazdir(struct LinkedList**,int); // Skip Listeyi seviyeleri ile yazdirma fonksiyonu
void FreeNodes(struct LinkedList*); // nodelari freeleme fonksiyonu
int Randomized(int,int);// Random Node secme fonksiyonu
void LeveledLinkedList(struct LinkedList*, struct LinkedList**,int ,int); // SkipList olusturma fonksiyonu
void ElemanArama(struct LinkedList** , int ); // Eleman Arama Fonksiyonu
void sortedInsert(struct LinkedList**,int*);// Eleman Ekleme Fonksiyonu ( Mainliste ekler sonra tekrar Reconstruct eder)
void deleteNode(struct LinkedList**, int*);// Ekleme Fonksiyonu gibi silme yapar sonra tekrar re construct eder.

int SeviyeSayac(int MainListUzunluk){ // seviye sayma fonksiyonu
   int SeviyeSayaci = 0;
    while(MainListUzunluk != 0){
        MainListUzunluk = MainListUzunluk/2;
        SeviyeSayaci++;
    }
    return SeviyeSayaci;
}

int main(){
    int i = 0, selection = 0;
    int RecursiveCallNumber = 0;
    int array[20];
    srand(time(NULL));
    int MainListUzunluk;
     printf("Main List Kac elemanli Olmasini istiyorsunuz?\n");
     scanf(" %d", &MainListUzunluk);

     for(i = 0; i < MainListUzunluk; i++){
        printf("\n-->%d. Elemani Girin", i+1);
        scanf(" %d", &array[i]);
     }
  
    int SeviyeSayaci = SeviyeSayac(MainListUzunluk);// girilen input e gore seviye sayisi belirleme

    struct LinkedList* MainHead = NULL;
    struct LinkedList** HeadlerDizisi = (struct LinkedList**)(malloc(sizeof(struct LinkedList*)*SeviyeSayaci * 2)); 

    MainHead=constructList(MainHead,MainListUzunluk,array); //Girilen Input a gore Main Linked Listimizi olusturma
    MainHead->NextLevel =  NULL;
    HeadlerDizisi[0] = MainHead; // headleri tutan dizinin 0. elemanina main listemizin headini atama

    /*  -----MENU----*/
    while(selection != -1){
        printf("\n\n\n\n\n\n");
        printf("--------->SkipList VeriYapisi<---------\t\t\t\t\t20011906 Basel Kelziye\n");
        printf("-> 1-SkipList Olusturma\n");
        printf("-> 2-SkipList Butun Seviyeleri Ile Ekrana Yazdirma\n");
        printf("-> 3-SkipList'e Eleman Ekleme\n");
        printf("-> 4-SkipListten Eleman Silme\n");
        printf("-> 5-SkipListte Eleman Arama\n");
        printf("->-1 -Cikis\n");
        scanf("%d", &selection);
        switch (selection){
            case 1:
                LeveledLinkedList(MainHead,HeadlerDizisi,MainListUzunluk,RecursiveCallNumber);
                break;

            case 2:
                SeviyeSayaci = SeviyeSayac(MainListUzunluk);
                LinkedListYazdir(HeadlerDizisi,SeviyeSayaci);
                break;

            case 3:
                sortedInsert(&MainHead,&MainListUzunluk);
                LeveledLinkedList(MainHead,HeadlerDizisi,MainListUzunluk,RecursiveCallNumber);
                SeviyeSayaci = SeviyeSayac(MainListUzunluk);
                LinkedListYazdir(HeadlerDizisi,SeviyeSayaci);
                break;

            case 4:
                deleteNode(&MainHead,&MainListUzunluk);
                SeviyeSayaci = SeviyeSayac(MainListUzunluk);
                LeveledLinkedList(MainHead,HeadlerDizisi,MainListUzunluk,RecursiveCallNumber);
                break;

            case 5:
                ElemanArama(HeadlerDizisi,SeviyeSayaci);
                break;

            case -1:

                break;

            default:
                printf("Yanlis Giris!");
                break;

        }
    }

    free(MainHead);
    printf("\n");
    return 0;
}

/* MainListUzunlugu kadar ve arrayimizdeki elemanlari ile linked-list olusturur ve butun baglari duzenler.*/
struct LinkedList* constructList(struct LinkedList* MainHead, int MainListUzunluk, int array[]){ 
    int i; 
    struct LinkedList* TmpNode = (struct LinkedList*)malloc(sizeof(struct LinkedList));
    MainHead = TmpNode;
    for(i=0; i < MainListUzunluk; i++)
    {
        struct LinkedList* TmpNode2 = (struct LinkedList*)malloc(sizeof(struct LinkedList));
        TmpNode->Next = TmpNode2;
        TmpNode2->date = array[i];
        TmpNode2->Next = NULL;
        TmpNode = TmpNode->Next;
    }
    return MainHead;
}

void LinkedListYazdir(struct LinkedList** HeadlerDizisi, int SeviyeSayaci){ //rekursiv yazdirmada olmadigi icin seviye sayaci tutarak yazdirma fonksiyonu olusturdum
    int i;
    struct LinkedList* tmp;
    for(i = 0; i <SeviyeSayaci; i++ ){
        tmp = HeadlerDizisi[i]->Next;
        while(tmp != NULL){
            printf(" %d -> ", tmp->date);
            tmp  = tmp->Next;
        }
        printf("\n  \n");
    }
}
void FreeNodes(struct LinkedList* MainHead){ // nodelari freeleme fonksiyonu calisma prensipi 2 pointer ile butun nodelari gezip freeler
    struct LinkedList *before = MainHead;
    struct LinkedList *last = MainHead;
    while(last->Next != NULL){
        before = last;
        last = last->Next;
        free(before);
    }
}
int Randomized(int RecursiveCallNumber,int MainListUzunluk){ // random olusturma fonksiyonu
    int sonuc = rand()%MainListUzunluk+1 + (RecursiveCallNumber+2)*(RecursiveCallNumber+1);
    //eleman sayisini kadar random deger uretir ve mainuzunluk/2 den buyuk deger gelirse o node u secer.
    // seviye arttikca secme hassasiyetimiz arttigi icin her rekursive cagirisimda node secme olasiligini arttirdim.
    if( sonuc > (MainListUzunluk/2) ){
        return 1;
    }
    else{
        return -1;
    }
    //5
    //
}

void LeveledLinkedList(struct LinkedList* MainHead, struct LinkedList** HeadlerDizisi,int MainListUzunluk, int RecursiveCallNumber){
    if(MainListUzunluk == 0 || MainListUzunluk == 1){ //construct etme fonksiyonu rekursif sekilde olusturur
   
  
   
        return ;
    }
    else{
        int i =0;
        HeadlerDizisi[RecursiveCallNumber+1] = (struct LinkedList*)(malloc(sizeof(struct LinkedList))); 
        //calisma mantigi headlerin[i+1]. den baslayarak(i = 0 baslangicta) headlerin[i] si ile paralel bir sekilde ilerler.
        HeadlerDizisi[RecursiveCallNumber+1]->NextLevel = HeadlerDizisi[RecursiveCallNumber];

        struct LinkedList* Tmp = HeadlerDizisi[RecursiveCallNumber+1];
        struct LinkedList* TmpBelow = HeadlerDizisi[RecursiveCallNumber];
        while(TmpBelow != NULL && i < (MainListUzunluk+1)/2){
            if(Randomized(RecursiveCallNumber,MainListUzunluk) == 1 )
            {
                  //ve random olusturma fonksiyonu her nodeda cagirir. eger random fonksiyonum pozitif deger dondururse o node alir ve gereken baglari olusturur.
                struct LinkedList *NewNode = (struct LinkedList*)(malloc(sizeof(struct LinkedList)));
                Tmp->Next = NewNode;
                NewNode->Next = NULL;
                NewNode->NextLevel = TmpBelow->Next;
                NewNode->date = NewNode->NextLevel->date;
                Tmp = Tmp->Next;
                TmpBelow = TmpBelow->Next;
                i++;
            }
            else
            {
                 //yoksa onu atlar ve diger tum nodelar icin ayni islemi gerceklestirmektedir.
                TmpBelow = TmpBelow->Next;
            }

        }
        RecursiveCallNumber++;
        LeveledLinkedList(MainHead,HeadlerDizisi,MainListUzunluk/2,RecursiveCallNumber);
    }
}

void ElemanArama(struct LinkedList** HeadlerDizisi, int SeviyeSayaci){
    //arama isleminde en ust seviyeden baslayarak gezer.
   
 
    //
    int aranan,i;
    printf("\n Lutfen Aramak Istediginiz elemani giriniz\n");
    scanf("%d", &aranan);
    struct LinkedList* tmp;
    int Exit_while = 0,counter = 0;
    for(i = SeviyeSayaci -1; i >= 0; i--){
        Exit_while = 0;
        HeadlerDizisi[i]->date = -1000;
        tmp = HeadlerDizisi[i];
        while(tmp != NULL && tmp->date != aranan && Exit_while == 0 /*&& tmp->NextLevel != NULL*/)
        {
            if(tmp->date < aranan && tmp->Next !=NULL){
                tmp = tmp->Next; //eger nodedaki degerim aradigimdan kucuk ve node null gostermiyorsa bir sagdaki node a ilerlerim.
            }
            else if(tmp->date < aranan && tmp->Next == NULL && tmp->NextLevel != NULL){
                tmp = tmp->NextLevel; //eger nodedaki degerim aradigimdan kucum ve node null gosteriyorsa bir alt seviyeye inerim(cunku bu seviyedeki nodelar bitmis demektir)
                i--;
            }
            else if(tmp->date < aranan && tmp->Next == NULL && tmp->NextLevel == NULL){
                printf("\n--> Aradiginiz Eleman bulunmamaktadir!");//eger node daki deger aradigimdan kucuk ve sag isaretcim null ve alti null ise aradigim deger yok demektir.
                return;
            }
            else if(tmp->date > aranan){//aradigim deger suanki degerimden buyuk ise bu seviyeden aramayi durdurur ve diger seviyeden aramaya baslar.
                Exit_while = 1;
            }
            else if(tmp->date == aranan){
                printf("\n ---> %d Elemeani ---> %d. Seviyede bulundu!\n", tmp->date,i);// aradigim deger node daki degere esit ise bulundu demektir.
                return;
            }
            counter++;
        }
        if(tmp->date == aranan){
            printf("\n ---> %d Elemani ---> %d. Seviyede bulundu!\n", tmp->date,i);
            return;
        }
    }
    printf("\n Aradiginiz eleman Bulunmamaktadir.");
}

void sortedInsert(struct LinkedList** head_ref, int* MainListUzunluk)
{// main listte elemani ekler sonra construct eder.
    struct LinkedList* new_node = (struct LinkedList*)(malloc(sizeof(struct LinkedList)));
    printf("\n Eklemek Istediginiz Elemani Giriniz\n");
    scanf(" %d", &(new_node->date));
    struct LinkedList* current;
    if (*head_ref == NULL
        || (*head_ref)->date
           >= new_node->date) {
        new_node->Next = *head_ref;
        *head_ref = new_node;
    }
    else {
        current = *head_ref;
        while (current->Next != NULL
               && current->Next->date < new_node->date) {
            current = current->Next;
        }
        new_node->Next = current->Next;
        current->Next = new_node;
    }
    *MainListUzunluk= *MainListUzunluk +1;
}
void deleteNode(struct LinkedList** head_ref, int* MainListUzunluk)
{// mainlistte elemani siler daha sonra da constuct eder.
    int key;
    struct LinkedList *temp = *head_ref, *prev;
    printf("\n Silmek Istediginiz Elemani Giriniz");
    scanf("%d", &key);
    if (temp != NULL && temp->date == key) {
        *head_ref = temp->Next; // Changed head
        free(temp); // free old head
        *MainListUzunluk = *MainListUzunluk -1;
        return;
    }
    while (temp != NULL && temp->date != key) {
        prev = temp;
        temp = temp->Next;
    }
    if (temp == NULL){
        printf("\n Silmek istediginiz eleman bulunmamaktadir");
        return;
    }
    prev->Next = temp->Next;
    free(temp);
    *MainListUzunluk = *MainListUzunluk -1;
}

