# Ders 23 Çalışma Özeti

## Genel Konular

- Uygulama sorusu: kitaplık rafları ve bağlı liste
  - Bu oturum bir uygulama oturumudur. Amaç bağlı listeyle (linked list) çalışmaktır.
  - Kütüphanede 11 raflı bir kitaplık vardır. 11 asal sayı olduğu için seçilmiştir.
  - Bir kitabın hangi rafa konacağı adından hesaplanan bir kodla belirlenir: adın her harfinin ASCII kodu toplanır, toplamın raf sayısına göre modu alınır.
  - Mod 11'e göre alındığı için sonuç 0 ile 10 arasındadır. 0 birinci rafa, 10 on birinci rafa karşılık gelir.
  - Aynı rafa birden fazla kitap düşebilir. Kitaplığın sonsuz kitap aldığı varsayılır. Kapasite sınırlı olsaydı bağlı listeye pek gerek kalmaz, dinamik bir dizi yeterdi.
  - İstenenler: adı verilen kitabın rafını belirleyip kitaplığa eklemek, adı verilen kitabı arayıp hangi rafta olduğunu söylemek.
- Program yapısı (ekrandan, 00:10:00)
  - `stdio.h`, `stdlib.h` ve `string.h` kullanılır. `#define SHELF 11` raf sayısı, `#define MAXSIZE 20` kitap adının en büyük uzunluğudur.
  - Düğüm yapısı: `char name[MAXSIZE]; int data; int index; struct node *next;`. `typedef struct node List;` ile kısa ad verilir.
  - `data` alanında ASCII toplamı (anahtar, key), `index` alanında raf numarası tutulur.
  - `main` içinde `List *head=NULL;` ile boş liste kurulur. Sonsuz döngüde dört seçenekli bir menü vardır: 1 ekle, 2 göster, 3 ara, 4 çık.
- Anahtar hesabı: `findKey` (ekrandan, 00:15:00)
  - Özyinelemeli tek satır: `return *s == 0 ? 0 : *s + findKey(s + 1);`
  - Dizgi sonuna (`'\0'`) gelinmişse 0 döner. Değilse geçerli karakterin kodu, bir sonraki karakterden başlayan dizginin toplamına eklenir.
  - Koşul operatörünü bilmeyenler için aynı kodun `if`-`else` sürümü yorum satırında verilmiştir.
- Başa ekleme: `insert(List **headRef, char bookName[])` (ekrandan, 00:15:00)
  - `malloc(sizeof(List))` ile yeni düğüm açılır.
  - `key = findKey(bookName); i = key % SHELF;` hesaplanır. `data`'ya anahtar, `index`'e raf yazılır, ad `strcpy` ile `name` alanına kopyalanır.
  - `newnode->next = (*headRef);` ile o ana kadarki listenin ilk elemanı yeni düğümün arkasına bağlanır. `(*headRef) = newnode;` ile yeni düğüm listenin başı olur.
  - `head` işaretçisinin kendisi değiştiği için fonksiyona adresi (`&head`) gönderilir, parametre çift işaretçidir. Benzetme: `scanf("%d", &opt)` ile değişkenin adresini vermek gibi.
- Arama: `search(List *head)` (ekrandan, 00:20:00)
  - Liste yalnız okunur, değiştirilmez. Bu yüzden adres değil, `head`'in kendisi gönderilir.
  - Aranan adın anahtarı aynı yolla hesaplanır. Liste boşsa kitap yoktur.
  - `tempNode = head;` ile başlanır. `while(tempNode != NULL && tempNode->data != key)` döngüsü bir sonraki düğüme ilerler.
  - Döngü iki nedenle biter: liste bitmiştir (`tempNode == NULL`) ya da anahtar bulunmuştur. Hangisi olduğu döngüden sonra kontrol edilir.
- Gösterme: `display(List *node)` (ekrandan, 00:20:00)
  - `while(node != NULL)` ile düğümler gezilir ve `printf("%s (%d) -> %d\n", node->name, node->data, node->index);` ile ad, anahtar ve raf yazdırılır.
- Çalıştırma ve hata ayıklama
  - Derlemede iki uyarı çıktı: `scanf("%s", &bookName)` için `%s` `char *` bekler, `&bookName` ise `char (*)[20]` türündedir. Dizinin adı zaten adres olduğu için `&` kaldırıldı (ekrandan, 00:30:00).
  - `aa`, `bb`, `cc` eklenip listelendi. `cc` için anahtar 198'dir ve 11'e tam bölünür, raf 0 çıkar. Ekranda daha doğal görünmesi için yazdırırken `index + 1` kullanıldı.
  - Listede olmayan bir kitap arandığında program segmentation fault verdi.

## Hocanın Özellikle Vurguladığı Kısımlar

- Arama sonrasındaki kontrollerin sırası
  - İlk sürümde önce `tempNode->data == key`, sonra `tempNode == NULL` kontrol ediliyordu. Bir öğrenci bunu sordu.
  - Liste bitince `tempNode` NULL olur ve `tempNode->data`'ya erişmek segmentation fault verir. Önce NULL kontrolü yapılacak şekilde sıra değiştirildi, hata gitti.
  - Segmentation fault, var olmayan bir adrese ya da erişim yetkisi olmayan bir belleğe ulaşmaya çalışınca çıkar.
- Fonksiyon parametreyi değiştirecekse adresi gönderilir
  - `head`'in zaten bir işaretçi olması bunu değiştirmez. İşaretçinin kendisi değişecekse işaretçinin adresi gönderilir.

## Kısa Tekrar Notları

- Raf = (adın ASCII kodları toplamı) mod 11. Asal sayı olan 11 raf seçildi.
- `findKey`: özyinelemeli toplam, `'\0'`'da 0 döner.
- Başa ekleme: `newnode->next = *headRef; *headRef = newnode;`
- Listeyi değiştiren fonksiyon `List **` alır ve `&head` ile çağrılır. Yalnız okuyan fonksiyon `List *` alır.
- Arama döngüsünden sonra önce `tempNode == NULL` kontrol edilir, sonra `tempNode->data`.
- Dizi adı zaten adrestir: `scanf("%s", bookName)`; `&` gerekmez.
- `aa` = 194 (raf 7), `bb` = 196 (raf 9), `cc` = 198 (raf 0).

## Detaylı Açıklamalar

- Kodun düzeltilmiş tam hali aşağıdadır. Ekranda `main`'in 43-54. satırları hiç görünmedi; `case 2` sonrası kısım (`case 3: search(head);` ve `case 4` çıkış) ajan tarafından tamamlanmıştır. Diğer satırlar karelerden alınmıştır (ekrandan, 00:10:00, 00:15:00, 00:20:00, 00:30:00). Kod `gcc -Wall` ile derlendi ve `aa`, `bb`, `cc` ekleme, gösterme, `cc` ve `dd` arama girdisiyle çalıştırıldı. Yalnız kullanılmayan değişken uyarıları (`i` ve `search` içindeki `index`) verdi.
  <!-- BELİRSİZ: main'in case 3 ve case 4 kısmı ekranda görünmedi; menü seçeneklerinden ajan tamamladı. -->

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SHELF 11

#define MAXSIZE 20

struct node
{
    char name[MAXSIZE];
    int data;
    int index;
    struct node *next;
};

typedef struct node List;

int findKey(char *s);
void insert(List **headRef,char bookName[]);
void search(List *head);
void display(List *head);

int main()
{
    int i,opt;
    List *head=NULL;
    char bookName[MAXSIZE];
    while(1)
    {
        printf("\nPress 1. Insert\t 2. Display \t3. Search \t4.Exit \n");
        scanf("%d",&opt);
        switch(opt)
        {
            case 1:
                printf("\nEnter Book Name To Insert The Bookshelf\n");
                scanf("%s",bookName);
                insert(&head,bookName);
                break;
            case 2:
                display(head);
                break;
            case 3:                 /* ajan tamamladı */
                search(head);
                break;
            case 4:                 /* ajan tamamladı */
                exit(0);
        }
    }
}

int findKey(char *s) {

    return *s == 0 ? 0 : *s + findKey(s + 1); //if(s==0){return 0;} else{return *s+findKey(s + 1);}
}

void insert(List **headRef,char bookName[])
{
    List * newnode = (List*) malloc(sizeof(List));

    int i,key;
    key=findKey(bookName);
    i=key%SHELF;

    newnode->data  = key;
    newnode->index  = i;
    strcpy(newnode->name,bookName);

    newnode->next = (*headRef);

    (*headRef)    = newnode;
}

void search(List *head)
{
    List *tempNode;
    char bookName[MAXSIZE];
    int key,index;
    printf("\nEnter A Book Name to Search on Bookshelf\n");
    scanf("%s",bookName);
    key=findKey(bookName);
    index=key%SHELF;
    if(head == NULL)
        printf("\n Book Could Not be Found \n");
    else
    {
        tempNode=head;
        while(tempNode!=NULL && tempNode->data != key)
            tempNode=tempNode->next;

        if(tempNode==NULL)
            printf("\n Book Is not In the Bookshelf\n");
        else if(tempNode->data == key)
            printf("Book is on the %dth shelf\n",(tempNode->index)+1);
    }

}

void display(List *node)
{
    while(node != NULL)
    {
        printf("%s (%d) -> %d\n",node->name,node->data,node->index);
        node = node->next;
    }
}
```

- Ders sonrası not: `findKey` satırının yanındaki yorumda koşul `if(s==0)` diye yazılmıştır. Gerçek kodda karşılaştırılan işaretçi değil karakterdir; doğrusu `if(*s==0)` olur. Yorum satırı derlenmediği için programı etkilemez.
- Ek bilgi (derste anlatılmadı): Arama yalnız anahtarı (ASCII toplamını) karşılaştırır, adı karşılaştırmaz. Aynı harflerden oluşan farklı adlar (örneğin `ab` ve `ba`, ikisinin toplamı da 195) aynı anahtarı verir; listede `ab` varken `ba` aranınca kitap bulunmuş gibi görünür. Ajan bunu derlenmiş kodla denedi. Adın da `strcmp` ile karşılaştırılması bu durumu önler.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
