# Ders 23 Genişletilmiş Notu: Bağlı Liste Uygulaması: Kitaplık Raflarına Kitap Yerleştirme ve Arama

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Uygulama Sorusu: 11 Raflı Kitaplık
- 2. Programın Genel Yapısı
- 3. Anahtar Hesabı: findKey
- 4. Listeye Başa Ekleme: insert
- 5. Neden Çift İşaretçi?
- 6. Kitap Arama: search
- 7. Listeyi Gösterme: display
- 8. Programı Derleme ve Çalıştırma
- 9. Segmentation Fault ve Kontrol Sırasının Düzeltilmesi
- 10. Düzeltilmiş Kodun Tamamı
- Örnek Sorular
- Dersin Toparlaması

## 1. Uygulama Sorusu: 11 Raflı Kitaplık

Bu oturum, konu anlatımından çok bir uygulama oturumudur. Normal dönemde laboratuvarda öğrencilere soru olarak verilip kodlatılacak bir problem, bu kez hazır bir çözüm kodu üzerinden satır satır anlatıldı. Amaç bağlı listelerle (linked list) biraz uğraşmaktır.

Problem şöyledir. Bir kütüphanede 11 raflı bir kitaplık vardır. 11 sayısı bilerek seçilmiştir, çünkü asal sayıdır. Kitaplığa çeşitli kitaplar yerleştirilecektir. Bir kitabın hangi rafa konacağına kitabın adından hesaplanan bir kodla karar verilir; yani kitabın adı rafını belirler.

Kod şöyle hesaplanır: kitap adının her harfinin ASCII kodu toplanır ve bu toplamın raf sayısına göre modu alınır. Mod 11'e göre alındığı için sonuç 0 ile 10 arasında kalır. Sonuç 0 ise kitap birinci rafa, 10 ise on birinci rafa konur diye düşünülebilir.

İki işlem istenir:

- Adı verilen bir kitabın hangi rafa konacağını belirleyip kitabı kitaplığa eklemek.
- Adı verilen bir kitabı kitaplıkta arayıp hangi rafta olduğunu söylemek; kitap yoksa yok demek.

Aynı rafa denk gelen birden fazla kitap olabilir ve kitaplığın sonsuz kitap aldığı varsayılır. Hoca bu varsayımın nedenini de açıkladı: kapasite kısıtlı olsaydı bağlı listeye pek ihtiyaç kalmazdı, iş dinamik bir diziyle de halledilebilirdi.

> **Ek bilgi (derste anlatılmadı):** Bir anahtarı tablo boyutuna göre modunu alarak bir konuma eşleme fikri, karma (hash) tablolarının temelidir. Tablo boyutunun asal seçilmesi, anahtarların konumlara daha düzgün dağılması için sık kullanılan bir tercihtir. Derste yazılan kodda kitapların hepsi tek bir bağlı listede tutulur, raf numarası yalnız düğümün bir alanı olarak saklanır; klasik karma tablosunda ise her raf için ayrı bir liste tutulur.

## 2. Programın Genel Yapısı

Kodun başında üç kütüphane eklenir: giriş-çıkış için `stdio.h`, `malloc` ve `exit` için `stdlib.h`, `strcpy` için `string.h`. Ardından iki sabit tanımlanır (ekrandan, 00:10:00):

```c
#define SHELF 11

#define MAXSIZE 20
```

`SHELF` İngilizcede raf demektir ve raf sayısını tutar. `MAXSIZE` bir kitap adının alabileceği en büyük uzunluktur.

Düğüm yapısı şöyledir (ekrandan, 00:10:00):

```c
struct node
{
    char name[MAXSIZE];
    int data;
    int index;
    struct node *next;
};

typedef struct node List;
```

Yapı kendisinden sonra gelen düğümün adresini (`next`) tuttuğu için bu yapıya bağlı liste denir. Veri kısmında kitabın adı (`name`) tutulur. `data` alanına, birazdan anlatılacak olan ASCII toplamı (anahtar, key) yazılır. `index` alanı kitabın hangi rafa konacağını gösterir. `typedef` ile `struct node` yerine kısaca `List` yazılabilir.

Fonksiyon prototipleri (ekrandan, 00:10:00):

```c
int findKey(char *s);
void insert(List **headRef,char bookName[]);
void search(List *head);
void display(List *head);
```

`main` içinde `List *head=NULL;` ile listenin başı tanımlanır ve başlangıçta NULL atanarak listenin boş olduğu söylenir. Sonra sonsuz bir `while(1)` döngüsü içinde küçük bir menü yazdırılır: `1. Insert`, `2. Display`, `3. Search`, `4.Exit`. Seçim `scanf("%d",&opt);` ile okunur ve `switch(opt)` ile ilgili fonksiyon çağrılır. Ekle seçeneğinde kitap adı okunur ve `insert(&head,bookName);` çağrılır; göster seçeneğinde `display(head);` çağrılır (ekrandan, 00:10:00).

<!-- BELİRSİZ: main'in 43-54. satırları (case 3 ve case 4) hiçbir karede görünmedi. Altyazıya göre arama seçeneği search(head) çağırıyor; çıkış kısmının tam yazımı bilinmiyor. -->

## 3. Anahtar Hesabı: findKey

Kitap adından anahtarı hesaplayan fonksiyon tek satırlık özyinelemeli bir fonksiyondur (ekrandan, 00:15:00):

```c
int findKey(char *s) {

    return *s == 0 ? 0 : *s + findKey(s + 1); //if(s==0){return 0;} else{return *s+findKey(s + 1);}
}
```

Hoca bunu şöyle açıkladı: karakter dizisinde hâlâ bir karakter varsa, yani dizgi sonuna (NULL karakterine) gelinmemişse, geçerli karakterin kodu alınır ve bir sonraki karakterden başlayan kısım yeni bir dizgi gibi kabul edilip fonksiyon onunla yeniden çağrılır. Dizgi sonuna gelindiğinde 0 döner. Çağrılar geri dönerken bütün karakter kodları toplanmış olur.

Koşul operatörünü (`? :`) bilmeyenler için aynı mantığın `if`-`else` sürümü yorum satırına yazılmıştır.

> **Ders sonrası not:** Yorum satırındaki `if` sürümünde koşul `if(s==0)` diye yazılmıştır. Bu, işaretçinin kendisini sıfırla karşılaştırır; dizgi sonunu yakalamak için doğrusu `if(*s==0)` olur. Yorum satırı derlenmediği için programın çalışmasını etkilemez.

Bir örnek (ara adım eklendi): `cc` adı için `'c'` karakterinin ASCII kodu 99'dur. `findKey("cc")` = 99 + `findKey("c")` = 99 + (99 + `findKey("")`) = 99 + 99 + 0 = 198.

## 4. Listeye Başa Ekleme: insert

Ekleme fonksiyonu şöyledir (ekrandan, 00:15:00):

```c
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
```

Kitabın adı kullanıcıdan alındıktan sonra bilgilerini yazmak için yeni bir düğüm oluşturulur. Bu düğüm bağlı liste yapısına (`List`) aittir ve `malloc` ile bellekte yer ayrılır.

Sonra düğümün içi doldurulur. `findKey` ile kitap adındaki harflerin ASCII kodları toplamı, yani anahtar bulunur. Anahtarın raf sayısına göre modu alınarak `i` indeksi elde edilir; bu indeks kitabın hangi rafa konacağını söyler. `index` alanına `i`, `data` alanına anahtar yazılır. Kitap adı, `string.h` kütüphanesindeki `strcpy` ile düğümün içindeki `name` dizisine kopyalanır; bu dizi `MAXSIZE` uzunluğa kadar ad alabilir.

En önemli iki satır en sondadır. `newnode->next = (*headRef);` ile o ana kadarki listenin en baştaki elemanı yeni düğümün `next` alanına konur. Böylece yeni düğümün arkasına listenin geri kalanı bağlanmış olur. Ardından `(*headRef) = newnode;` ile yeni düğüm listenin adresine yazılır. Sonuçta en başa eklenmiş yeni düğüm ve arkasından gelen eski liste birlikte yeni listeyi oluşturur. Yani eleman listenin başına eklenmiştir; bu, derste daha önce anlatılan başa ekleme işlemidir.

## 5. Neden Çift İşaretçi?

Hoca, `insert` fonksiyonuna neden listenin adresinin gönderildiğini bir benzetmeyle anlattı. Bir fonksiyona bir `int` gönderip onu fonksiyonun içinde değiştirmek ve bu değişikliğin kalıcı olmasını istiyorsak değişkenin adresini göndeririz. Örnek olarak `scanf("%d",&opt);` satırı verildi: `opt`'un adresi gönderilir ki `scanf` bittiğinde `opt`'un içinde istenen değer olsun.

`insert`'e de aynı nedenle `head`'in adresi gönderilir. `head`, `main` içinde tanımlanmış bir bağlı listedir; yapı türünden bir düğümü gösterir. Hoca başka bir şeyle kafayı karıştırmaya gerek olmadığını söyledi: bir şeyin içinde değişiklik yapmak istiyorsak onun adresini göndeririz. `head`'in zaten bir adres, yani bir işaretçi olması bu kuralı değiştirmez.

Bu yüzden `insert` çift işaretçi (`List **headRef`) alır. Bağlı listenin kendisi, ilk elemanın bulunduğu yerin adresidir. `headRef` ise listeyi gösteren adresin adresidir.

> **Hocanın vurgusu:** Fonksiyon içinde değiştirilmesi istenen her şeyin adresi gönderilir; değiştirilecek şey bir işaretçi olsa bile.

## 6. Kitap Arama: search

Arama fonksiyonunun derste ilk gösterilen hali şöyledir (ekrandan, 00:20:00):

```c
void search(List *head)
{
    List *tempNode;
    char bookName[MAXSIZE];
    int key,index;
    printf("\nEnter A Book Name to Search on Bookshelf\n");
    scanf("%s",&bookName);
    key=findKey(bookName);
    index=key%SHELF;
    if(head == NULL)
        printf("\n Book Could Not be Found \n");
    else
    {
        tempNode=head;
        while(tempNode!=NULL && tempNode->data != key)
            tempNode=tempNode->next;
        if(tempNode->data == key)
            printf("Book is on the %dth shelf\n",index);
        else if(tempNode==NULL)
            printf("\n Book Is not In the Bookshelf\n");

    }

}
```

Burada liste yalnız okunur, içinde değişiklik yapılmaz. `search` döndüğünde `head`'de bir değişiklik olmayacağı için adresini göndermeye gerek yoktur; fonksiyon `List *head` alır.

Fonksiyonda geçici bir düğüm işaretçisi (`tempNode`) tanımlanır. Kullanıcıya hangi kitabı aramak istediği sorulur, kitabın adı alınır, anahtarı ve indeksi ekleme fonksiyonundaki gibi hesaplanır.

Liste boşsa kitap kesinlikle yoktur. Değilse `tempNode`'a `head` atanır; artık liste `tempNode` üzerinden gezilir. `while` döngüsü, `tempNode` NULL olmadığı ve aynı zamanda `tempNode`'un `data`'sı hesaplanan anahtara eşit olmadığı sürece bir sonraki düğüme (`next`) geçer.

Bu döngüden iki şekilde çıkılır: ya `next`, `next`, `next` diye ilerlerken `tempNode` NULL olmuştur, yani liste bitmiştir; ya da `tempNode`'un `data`'sı anahtara eşittir. Döngüden neden çıkıldığı hemen ardından kontrol edilmelidir. Anahtar eşit olduğu için çıkıldıysa kitap bulunmuştur ve kitabın, `tempNode`'un indeksinin gösterdiği rafta olduğu söylenir. Liste bittiği için çıkıldıysa liste sonuna kadar gelinmiş ama kitap bulunamamıştır.

Bu ilk haldeki kontrol sırası bir öğrencinin sorusuyla tartışıldı ve çalıştırma sırasında hata verdi (Bölüm 9).

## 7. Listeyi Gösterme: display

Gösterme fonksiyonu daha önce yapılmış olduğu varsayılarak kısaca geçildi (ekrandan, 00:20:00):

```c
void display(List *node)
{
    while(node != NULL)
    {
        printf("%s (%d) -> %d\n",node->name,node->data,node->index);
        node = node->next;
    }
}
```

Bir `while` döngüsüyle düğümler üzerinde ilerlenir ve her düğümün adı, anahtarı ve raf indeksi yazdırılır.

## 8. Programı Derleme ve Çalıştırma

Kod Linux terminalinde `gcc YP_Uygulamav2.c` ile derlendi ve `./a.out` ile çalıştırıldı (ekrandan, 00:30:00). İlk denemede dosya adı yanlış yazıldığı için "No such file or directory" hatası alındı; dosya adındaki bir harfin büyük olduğu fark edilip düzeltildi.

Derleyici iki uyarı verdi. Uyarı, `bookName`'in neden adresle gönderildiğini soruyordu: `%s` biçimi bir karakter dizisi (`char *`) bekler, ama `&bookName` yazıldığında karakter dizisinin adresi, yani `char (*)[20]` gönderilir. Aynı durum hem `main`'deki hem `search`'teki `scanf` satırında vardı. Karakter dizisinin adı zaten adres olduğu için `&` kaldırıldı; düzeltilmiş kodda `scanf("%s",bookName);` yazılıdır (ekrandan, 00:30:00).

Sonra `aa`, `bb` ve `cc` adlı kitaplar eklendi ve liste gösterildi. <!-- BELİRSİZ: hoca "dört tane kitabımız olsun" dedi ama altyazıda yalnız üç kitap adı geçiyor. --> Gösterimde `cc` için anahtar 198 çıktı ve 198 sayısı 11'e tam bölündüğü için raf indeksi 0 oldu. Ara adımlar (ara adım eklendi):

- `aa`: 97 + 97 = 194, 194 mod 11 = 7.
- `bb`: 98 + 98 = 196, 196 mod 11 = 9.
- `cc`: 99 + 99 = 198 = 11 · 18, 198 mod 11 = 0.

Liste başa ekleme yaptığı için gösterim son eklenenden başlar: önce `cc`, sonra `bb`, sonra `aa`.

İndeksin 0'dan başlaması ekranda "0. raf" gibi görünüyordu. Hoca, kullanıcıya rafı söylerken indeksin bir fazlasının yazılmasının daha güzel görüneceğini söyledi ve arama sonucundaki yazdırmayı `(tempNode->index)+1` olarak değiştirdi (ekrandan, 00:30:00). Ardından listede bulunan `cc` arandı; bu aramada bir hata çıkmadı.

## 9. Segmentation Fault ve Kontrol Sırasının Düzeltilmesi

Sonra hata beklenen bir arama yapıldı: listede olmayan bir kitap arandı. Program segmentation fault verdi.

Hatanın nedeni şudur. `while` döngüsünden liste sonuna gelindiği için çıkıldıysa `tempNode` NULL'dır. İlk sürümde döngüden sonra önce `tempNode->data == key` kontrol ediliyordu. `tempNode` NULL iken onun `data` alanına ulaşmaya çalışmak segmentation fault verir. Hoca segmentation fault'u şöyle tanımladı: var olmayan bir adrese ulaşmaya çalışıyorsak ya da üzerindeki veriye ulaşmaya yetkimiz olmayan bir belleğe ulaşmaya çalışıyorsak bu hata alınır.

Çözüm, öğrencinin önerdiği gibi NULL kontrolünü yukarı almaktır (ekrandan, 00:30:00):

```c
        if(tempNode==NULL)
            printf("\n Book Is not In the Bookshelf\n");
        else if(tempNode->data == key)
            printf("Book is on the %dth shelf\n",(tempNode->index)+1);
```

Düzeltmeden sonra program yeniden derlendi. Liste boşken arama yapılırsa yukarıdaki `head == NULL` dalına girileceği için önce `aa` eklendi, sonra listede olmayan `cc` arandı ve program bu kez çökmeden "Book Is not In the Bookshelf" yazdı (ekrandan, 00:30:00).

> **Hocanın vurgusu:** Döngüden çıkınca `tempNode` NULL olabilir. NULL bir işaretçinin alanına erişmek segmentation fault verir; bu yüzden önce NULL kontrolü yapılır.

> **Ek bilgi (derste anlatılmadı):** C'de `&&` ve `||` operatörleri kısa devre ile değerlendirilir. `while(tempNode!=NULL && tempNode->data != key)` koşulunda `tempNode` NULL ise ikinci kısım hiç değerlendirilmez; döngü koşulu bu yüzden güvenlidir. Hata, döngüden sonraki ayrı `if` satırında NULL kontrolü yapılmadan `data` alanına erişilmesinden kaynaklanıyordu.

## 10. Düzeltilmiş Kodun Tamamı

Aşağıdaki kod, karelerdeki satırlar ve derste yapılan iki düzeltme (`&` kaldırma ve kontrol sırası) ile kurulmuştur. Ekranda `main`'in `case 2` sonrasındaki kısmı görünmediği için `case 3` ve `case 4` satırları ajan tarafından tamamlanmıştır. Kod `gcc -Wall` ile derlendi ve `aa`, `bb`, `cc` ekleme, gösterme, `cc` ve `dd` arama girdisiyle çalıştırıldı. Gösterim `cc (198) -> 0`, `bb (196) -> 9`, `aa (194) -> 7` verdi; `cc` için "Book is on the 1th shelf", `dd` için "Book Is not In the Bookshelf" yazdı. Derleyici yalnız kullanılmayan değişken uyarıları verdi (`main`'deki `i` ve `search`'teki `index`). Derste gösterilen ilk sürüm (ters kontrol sırası) de derlendi ve listede olmayan kitap arandığında segmentation fault verdiği doğrulandı.

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

> **Ek bilgi (derste anlatılmadı):** Arama yalnız anahtarı (ASCII toplamını) karşılaştırır, adı karşılaştırmaz. Aynı harflerden oluşan farklı adlar aynı anahtarı verir: `ab` ve `ba` için toplam 97 + 98 = 195'tir. Listede `ab` varken `ba` arandığında program kitabı bulmuş gibi raf numarası yazar; bu, derlenen kodla denendi. Anahtar eşleştiğinde adların `strcmp` ile ayrıca karşılaştırılması bu yanlış eşleşmeyi önler.

## Örnek Sorular

**Soru 1** (derste sözlü, 00:06:48): 11 raflı bir kitaplığa kitaplar yerleştirilecektir. Kitabın rafı, adındaki harflerin ASCII kodları toplamının 11'e göre modu alınarak belirlenir. Aynı rafa sınırsız kitap konabilir. Adı verilen kitabı uygun rafa ekleyen ve adı verilen kitabı arayıp hangi rafta olduğunu söyleyen programı bağlı liste kullanarak yazınız.

> **Çözüm:** Derste verilen çözüm Bölüm 10'daki koddur. Her kitap bir düğümde tutulur (`name`, `data` = ASCII toplamı, `index` = raf); ekleme listenin başına yapılır; arama anahtarı hesaplayıp listeyi gezer.

**Soru 2** (derste sözlü, 00:22:29): `search` fonksiyonunda döngüden sonra önce `tempNode->data == key`, sonra `tempNode == NULL` kontrol ediliyor. `tempNode` NULL ise ilk `if` hata vermez mi; bu iki kontrolün yeri değişmeli değil mi?

> **Çözüm:** Asistan önce bunun fark etmeyeceğini düşündü, çalıştırırken bakılacağını söyledi. Çalıştırmada listede olmayan bir kitap arandığında program segmentation fault verdi; öğrenci haklı çıktı. Döngü liste sonunda biterse `tempNode` NULL olur ve `tempNode->data`'ya erişmek geçersiz bellek erişimidir. Önce `tempNode == NULL`, sonra `tempNode->data == key` kontrol edilmelidir (Bölüm 9).

**Soru 3** (derste sözlü, 00:23:46): Başta `head == NULL` kontrolü yapmak zorunlu mu? Liste boşsa doğrudan `tempNode = head` yapılınca `while` döngüsünden zaten hemen çıkılmaz mı?

> **Cevap:** Asistan, yalnız `tempNode = head` atanıp döngüye girilse de olabileceğini kabul etti: `tempNode` NULL olduğu için döngüye hiç girilmez. 

> **Çözüm (derste verilmedi, ajan tamamladı):** Bu yaklaşım yalnız düzeltilmiş kontrol sırasıyla güvenlidir. Liste boşken döngüden sonra önce `tempNode == NULL` kontrol edilirse "kitap yok" yazılır. İlk sürümdeki sırayla ise boş listede de `tempNode->data`'ya erişilip segmentation fault alınırdı.

## Dersin Toparlaması

Bu oturumda bağlı listeyle çalışan küçük bir problem, hazır bir çözüm kodu üzerinden baştan sona incelendi. Kitap adının ASCII kodları toplamı özyinelemeli bir fonksiyonla anahtar olarak hesaplandı ve 11'e göre modu alınarak raf belirlendi. Kitaplar `malloc` ile açılan düğümlerde tutulup listenin başına eklendi; listeyi değiştiren `insert` fonksiyonunun neden `head`'in adresini, yani çift işaretçi aldığı, `scanf`'e değişken adresi verme benzetmesiyle açıklandı. Yalnız okuyan `search` ve `display` fonksiyonlarına ise işaretçinin kendisi gönderildi.

Kod çalıştırılırken iki ders çıktı: `scanf` ile karakter dizisi okurken dizinin adı zaten adres olduğu için `&` kullanılmaz; bir listede gezinme döngüsünden çıkıldığında işaretçi NULL olabileceği için önce NULL kontrolü yapılmalıdır, aksi halde segmentation fault alınır.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
