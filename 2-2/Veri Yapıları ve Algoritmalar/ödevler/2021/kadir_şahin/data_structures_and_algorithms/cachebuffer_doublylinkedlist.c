


#include<stdio.h>
#include<stdlib.h>  
#include<string.h>

struct record{
    char url[20];
    int counter;
    struct record *next,*prev;
    
};

typedef struct record node;

static node *head;
static int buffer_capacity;
static int buffer_counter;
static int threshold;

node *find_node( char * );
void delete_node(char *);
void menu();
void keyboard();
void file();
void add_node(node *);
node * create_list_node(char *); 
void print_list(node *);
void delete_list();

void menu(){

    int secim;
    printf(" klavyeden giris icin:        [1]\n txt dosyasindan okumak icin: [2] \n cikmak icin:                 [0] \n");
    scanf("%d",&secim);

    switch (secim)
    {
    case 1:
        printf("klavye girisinden cikmak istediginizde adres yerine [0] giriniz \n");
        keyboard(1);
        break;
    case 2:
        file();
        break;
    case 0:
        return;
    default:
        printf("Gecersiz secim! Lutfen gecerli bir secenegi giriniz: \n");
        menu();
        break;
    };

}




void insert(node *x){    //en basa eklenecek node'un adresi girildi.
    
    x->next=head;       // yeni giren node'un next'inde bir önceki head gösterildi.
    
    if(head!=NULL){     //bir önceki head NULL değilse onun da prev'ü yeni giren node'u göstermeli
        head->prev=x;
    }
    head=x;             // yeni head , giren node yapıldı.
    x->prev=NULL;       // yeni head'in prev'ü NULL yapıldı.

} 

void delete_list(){

    while (head!=NULL)  // head artık hiçbir node'u göstermeyip NULL kalana kadar 
    {                   // delete_node() fonksiyonuna head node'u gönderiyoruzç
        delete_node(head->url);
    //                  // delete_node() zaten otomatik olarak head'i güncelliyor.
    }
    

}



void keyboard(){
    
    char name[20];

    printf("adres gir: ");
    scanf("%s",&name);

    if(!strcmp(name,"0")){
        return;                //0 girilmediyse fonksiyon aşağıda devam edip işlemleri yapıp tekrar kendisini çağıracak
    }

    add_node(create_list_node(name));
    print_list(head);


    keyboard();
    

}

void file(){


    FILE * pdosya;
    char buffer[200];
    
    char secim;

    char name[20];
    

    printf("dosya okumayi bitirmek istediginizde [Enter] [0] giriniz \n");
            //.txt dosyasi ve her satirda 1 tane URL olacak sekilde olmalidir

   
    pdosya=fopen("input.txt","r");
    while(fscanf(pdosya,"%s",buffer)!=EOF){

        secim=getchar();


        if(secim=='0'){
            break;
        }
        else{
             strcpy(name,buffer);
            add_node(create_list_node(name));
            print_list(head);
        }
       
    }
    return;
}



void add_node_info(node *name){
    

    

    node *tmp;
    tmp= find_node(name->url);

    if(tmp!=NULL){
        (tmp->counter)++;          //      ayni node bulundu, sayac arttirildi
        if((tmp->counter)>threshold){
            {
                if((tmp->next)!=NULL)       // yeri degisecek node son node degilse
                {
                    if(head!=tmp){            // yeri degisecek node ara bir node ise
                        tmp->prev->next=tmp->next;
                        tmp->next->prev=tmp->prev;
                    }
                    else{                    //  yeri degisecek node ilk node ise
                        return;
                    }
                }
                else{                        // yeri degisecek node son node ise;
                    tmp->prev->next=NULL;
                }

                insert(tmp);
                return;
            }        
        }  
    }
}

node * create_list_node(char name[20]){

    
    
    node *tmp;
    tmp=(node *)malloc(sizeof(node));    //girilen adres için node sorgulamak ve yoksa yeni node oluşturmak için
    //                                   // bellek ayrıldı


    if(tmp == NULL){                      // bellek ayrılamadı

        printf("create_list_node(): malloc hatası. \n"); 
        exit(1);
    }
    strcpy(tmp->url,name);                 //add_node_info'nun kontrol yapması için oluşturulan tmp node'un
    //                                     // adres bilgisine parametrede giren adres atandı.
    add_node_info(tmp);

    
    if(find_node(tmp->url)!=(NULL)){        //bulunan node add_node_info'da güncellendiği için

        free(tmp);                          //yeni oluşturduğumuz node'u siliyoruz.
        return NULL;
    }

    //                                      // girilen adrese sahip node daha önce eklenmemiş
    //                                      // counter'ını 1 yapıp next-prev NULL yapıp add_node()
//                                          // bu node'u döndürüyoruz.
    tmp->counter=1;
    tmp->next=NULL;
    tmp->prev=NULL;
    
    return tmp;
}

void add_node(node *e){


    node *p;

    if(e==NULL){        //node güncellenmiş. yeni node eklemeden çıkıyoruz. 
        return;
    }
    else
    {   
        buffer_counter++;  // yeni node ekleneceği için buffer_counter'ı arttırıyoruz.
    }

    if(head==NULL){         // yeni node ilk eklenen node ise
        head=e;
        head->prev=NULL;    
        return;
    }


    if(buffer_counter<=buffer_capacity) // yeni node eklenince buffer_capacity aşılmamışsa
    {   
        insert(e);
    }
    else{                               // yeni node eklenince buffer_capacity aşılmamışsa 
        for(p=head; p->next!=NULL; p=p->next);
        delete_node(p->url);            // son node'u silip yeni node'u öyle insert() ediyoruz.
        buffer_counter--;               //silinen son node için buffer_counter tekrar azal
        insert(e);
        
    }    


    
}


node *find_node( char * name){   // aranacak olan node'un adresi alındı
	node *p;
    for(p=head; p!= NULL; p=p->next) // strcmp fonksiyonu 0 dönerse girilen node ile aynı isimde
	if(strcmp(p->url, name) == 0)    // bir node daha önce girilmiştir. ve bu node return edilir.
    {
	    return p; 
    }
    //                              // if içerisine hiç girilmeyip bir node return edilmemişse
    return NULL;                    // NULL return edilir.
}

void delete_node(char *x){          //silinecek olan node'un adresi alındı

    node *del;
    del=find_node(x);               // node arandı ve dönüş değeri del pointer'ına atandı.
    
    //                                ///    silinecek node bulunamadı ise del==NULL olmuştur
    if(del==NULL){
        printf("Node bulunamadi \n");
    }

    else if(del==head){         //  SİLİNECEK NODE HEAD NODE İSE
                                   
        if(head->next!=NULL){         ///  head node silinecekse ve listede birden fazla eleman varsa
            head=head->next;
            head->prev=NULL;
        }
        
        else{                         ///  listede kalan son eleman siliniyorsa
            head=NULL;
        }
    }

    else if(del->next==NULL){          ///  listenin en ucundaki eleman silinecekse       
        del->prev->next=NULL;
    }
                     
    else{                              ///  aradan bir eleman siliniyorsa
        del->prev->next=del->next;                  
        del->next->prev=del->prev;
    }

    free(del);                          /// bulunan node bellekten silindi.
}



void print_list(node *p){       // liste en baştan yazdırılacağı için parametre daima head node olur
    int i;
    if(head==NULL){                           
        printf("print_list():    Liste bos \n");
        return;
    }
    printf("BUFFERCOUNTER: %d \n",buffer_counter);
    for(i=0, p=head; p!=NULL ; p=p->next, i++){    //gezici pointer NULL gösterene kadar bütün node'lar yazdırılır.
        printf("Listenin %d. node'undaki url: %s    istek sayisi: %d  \n", i+1,p->url, p->counter);
    }
}

int main(){

    char list_sil[20];

    

    printf("buffer kapasitesini giriniz: ");
    scanf("%d",&buffer_capacity);

    printf("URL sayaclari icin esik degeri giriniz: ");
    scanf("%d",&threshold);
    printf("\n");

    menu();

    printf("Liste silinsin mi?   Y\\N \n");

    scanf("%s",&list_sil);

    if(!strcmp(list_sil,"Y")){

        delete_list();
    }
    print_list(head);


        getch();
    return 0;
}