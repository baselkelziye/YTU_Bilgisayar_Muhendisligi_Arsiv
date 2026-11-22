# Ders 21 Genişletilmiş Notu: Uygulama: Bağlı Liste ile Kütüphane Raf Yerleştirme

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Problem: Kitapları Raflara Yerleştirmek
- 2. Veri Yapısı Seçimi: Dizi ve Bağlı Liste
- 3. Programın Genel Yapısı
- 4. findKey: Özyinelemeli ASCII Toplamı
- 5. insert: Listenin Başına Ekleme ve Çift İşaretçi
- 6. display ve search Fonksiyonları
- 7. Programın Çalıştırılması ve Aynı Rafa Düşen Kitaplar
- 8. Programın Tamamı
- Örnek Sorular
- Dersin Toparlaması

## 1. Problem: Kitapları Raflara Yerleştirmek

Bu oturum bir uygulama dersidir. Yeni bir konu anlatılmadı; derste görülen struct, bağlı liste, dinamik bellek, özyineleme, string ve makro konularını pekiştirmek için hazırlanmış bir örnek problem, hazır yazılmış bir C programı üzerinden açıklandı. Kod satır satır yazılmadı, hazır kod üzerinde anlatıldı.

Problem metni ekranda şöyleydi (ekrandan, 00:15:00):

> Bir kütüphanedeki 11 raflı bir kitaplığa çeşitli kitaplar yerleştirilecektir. Raflara hangi kitapların yerleştirileceğine, isimlerine göre hesaplanan birer unique kodla karar verilmektedir.
>
> N harf uzunluğundaki bir kitap ismi için kod şu şekilde hesaplanmaktadır:
>
> Kod = (ascii kodu(Kitap_ismi[0]) + ascii kodu(Kitap_ismi[1]) + ... + ascii kodu(Kitap_ismi[i]) + ... + ascii kodu(Kitap_ismi[n]))
>
> Raf_No = Kod Mod Raf sayısı
>
> Kitap, koda denk gelen rafa yerleştirilecektir.

Yani kitap isminin her karakterinin ASCII karşılığı toplanır ve bir kod elde edilir:

$$\text{Kod} = \sum_{i} \text{ascii}(\text{Kitap\_ismi}[i]), \qquad \text{Raf\_No} = \text{Kod} \bmod \text{Raf sayısı}$$

Raf sayısı bu örnekte 11 olarak sabitlendi; istenirse kullanıcıdan alınan bir girdi de olabilirdi.

### 1.1 Örnek: "Tutunamayanlar"

Metindeki örnekte "Tutunamayanlar" kitabının kodu hesaplanır (ekrandan, 00:15:00). Büyük `T` ile küçük `t`'nin ASCII karşılıkları farklıdır: `T` = 84, `t` = 116.

| Karakter | T | u | t | u | n | a | m | a | y | a | n | l | a | r |
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
| ASCII | 84 | 117 | 116 | 117 | 110 | 97 | 109 | 97 | 121 | 97 | 110 | 108 | 97 | 114 |

$$84+117+116+117+110+97+109+97+121+97+110+108+97+114 = 1494$$

$$1494 \bmod 11 = 9 \quad (\text{çünkü } 11 \cdot 135 = 1485,\ 1494 - 1485 = 9)$$

Kitap 9. rafa yerleştirilir. (Bölme adımı eklendi.)

### 1.2 İstenen işlemler

Metne göre C dilinde şu işleri yapan bir algoritma yazılacaktır (ekrandan, 00:15:00):

- İsmi verilen kitabın raf numarasını belirleyerek listeye ekleyen,
- Kitaplığa eklenen tüm kitapların raf bilgilerini listeleyen,
- İsmi verilen bir kitabı kitaplıkta arayıp bulunursa raf numarasını gösteren, bulunmazsa kısa bir mesaj gösteren.

Her girdi için hem kitap ismi, hem kod, hem de kaçıncı rafta olduğu bilgisi tutulmalıdır. Program buna göre bir ekleme (insert), bir listeleme (display) ve bir arama (search) fonksiyonuna sahip olacaktır.

> **Ders sonrası not:** Metinde kod "unique" diye anılır, ama ASCII toplamı benzersiz değildir: farklı isimler aynı kodu, mod alındıktan sonra da çok daha sık olarak aynı rafı verebilir. Bu durum derste de çakışma olarak tartışıldı (Bölüm 7). Ayrıca N harfli bir isimde son karakterin indeksi büyük olasılıkla `n-1`'dir; metindeki `Kitap_ismi[n]` terimi bir fazladır.

## 2. Veri Yapısı Seçimi: Dizi ve Bağlı Liste

Bir girdide üç bilgi birlikte tutulacağı için ilk akla gelen araç `struct` yapısıdır. Struct'lar bir dizide ya da bir bağlı listede saklanabilir. Derste ikisinin avantajları ve dezavantajları öğrencilerle birlikte sayıldı.

**Soru:** Dizilerin ve bağlı listelerin avantajları ve dezavantajları nelerdir?

**Cevap (öğrencilerden ve derste toplananlar):**

- Dizide istenen elemana indeksle doğrudan erişilir. Bağlı listede ise elemana ulaşmak için baştan itibaren dolaşmak gerekir; çok uzun bir listede sona gitmek uzun sürer.
- Bağlı listenin boyutu kolayca artırılır. Diziyi büyütmek için daha büyük bir dizi açıp elemanları kopyalamak gerekir.
- Bağlı listede ekleme ve silme $O(1)$ karmaşıklıkta yapılabilir. Diziye araya eleman eklemek ya da silmek için diğer elemanların kaydırılması gerekir.

Her ikisinin de kendine göre avantajı ve dezavantajı vardır. Bu örnekte kaç kitap ekleneceği önceden bilinmediği için bağlı liste kullanılır: kullanıcı her kitap eklediğinde dinamik bellekten yeni bir düğüm (node) açılır.

## 3. Programın Genel Yapısı

### 3.1 Kütüphaneler ve makrolar

Programın başında standart giriş-çıkış kütüphanesi ve dinamik bellek ayırma (`malloc`) için gereken kütüphane eklenir. Ardından iki makro tanımlanır: `MAXSIZE` 20, `SHELF` 11. Önişlemci, kodda bu isimlerin geçtiği her yere 20 ve 11 yazar.

> **Ek bilgi (derste anlatılmadı):** `malloc` `stdlib.h` içinde, `strcpy` ve `strcmp` ise `string.h` içinde bildirilir. Ekranda programın ilk satırları görünmediği için bu dosyaların hangilerinin eklendiği karelerden doğrulanamadı.

Makrolar hatırlatılırken, yalnız sabit değil fonksiyon benzeri makroların da tanımlanabildiği ve makroların örneğin hata ayıklarken (debug) de kullanılabildiği söylendi.

### 3.2 struct node ve typedef

Struct yapısında bir kitap ismi, isimden hesaplanan kod ve bu koda göre bulunan raf numarası tutulur. Liste tek yönlü bağlı liste olduğu için bir sonraki düğümü gösteren bir `next` işaretçisi de vardır (ekrandan, 00:20:00; alanların son ikisi ve `typedef` satırı ekranda görünüyor):

```c
struct node {
    char name[MAXSIZE];   /* kitap ismi */
    int code;             /* ASCII toplamı */
    int index;            //Raf_No
    struct node *next;
};

typedef struct node List;
```

<!-- BELİRSİZ: name ve code alanlarının tanım satırları karelerde görünmüyor; alan adları koddaki newnode->name ve newnode->code kullanımından alındı. -->

`typedef struct node List;` satırı, `struct node` yerine artık `List` yazılabileceğini söyler. Bunu ayrı bir satırda yazmak zorunlu değildir: `typedef` struct tanımının önüne, `List` de kapanış parantezinden sonra yazılsaydı tanım tek seferde yapılmış olurdu. Burada fark görülsün diye iki ayrı satır bırakıldı. `typedef` yalnız struct için değil, örneğin `double` gibi bir tür için de başka bir isim vermek amacıyla kullanılabilir.

### 3.3 Fonksiyon bildirimleri

Programda dört fonksiyon vardır (ekrandan, 00:20:00):

```c
void insert(List **headRef, char bookName[]);
void search(List *head);
void display(List *head);
int findKey(char *s);
```

`findKey` kitap isminden kodu üretir. Dikkat edilmesi istenen nokta, `insert`'in çift işaretçi (`List **`) aldığı, diğerlerinin ise tek işaretçi aldığıdır. Bunun nedeni Bölüm 5'te açıklanır.

### 3.4 main ve menü

`main` içinde listenin başını tutan bir `head` işaretçisi tanımlanır. Listenin başı kaybedilmemelidir; sıralı arama (sequential search) yapmak ve birçok adımda listeyi baştan dolaşmak için `head` gerekir. Başlangıçta liste boş olduğu için `head` NULL'dır. Kullanıcıdan alınacak kitap ismi için bir karakter dizisi tanımlanır (ekrandan, 00:20:00):

```c
int opt;
List *head = NULL;
char bookName[MAXSIZE];

while (1)
{
    printf("\nPress 1. Insert\t 2. Display \t3. Search \t4.Exit \n");
    scanf("%d", &opt);
    switch (opt)
    {
        case 1:
            printf("\nEnter Book Name\n");
            scanf("%s", &bookName);
            insert(&head, bookName);
            break;
        case 2:
            display(head);
            ...
```

Kullanıcı menüden bir seçenek seçer ve `switch-case` ile ilgili `case`'e gidilir. Çıkış seçeneğinde program sonlanır; kodun sonunda `default: exit(1);` satırı görünür (ekrandan, 00:35:00).

> **Hocanın vurgusu:** Döngülerde `break` komutunu genellikle kullanmamaya, daha akıllı döngü koşulları yazmaya çalışıyoruz. `break`'i nadiren kullandığımız yapılardan biri `switch-case`'tir.

> **Ders sonrası not:** Ekrandaki kodda `scanf("%s", &bookName)` yazılıdır. Dizi adı `bookName` zaten ilk elemanın adresine dönüştüğü için doğru yazım `scanf("%s", bookName)` biçimidir. `&bookName` türü `char (*)[20]` olduğundan `gcc -Wall` biçim uyarısı (`-Wformat`) verir; adres değeri aynı olduğu için program yine de çalışır.

### 3.5 Boşluk içeren isimler ve scanf

**Soru (derste soruldu):** Kitap ismi olarak "Şeker Portakalı" girilseydi, `scanf("%s", ...)` iki kelimeyi de alır mıydı?

**Cevap:** Almaz, yalnız "Şeker" okunur. `scanf` `%s` biçimiyle boşluk karakterine (whitespace) kadar okur. Boşluklarla birlikte okumak için ya `scanf`'in biçimi satır sonuna kadar okuyacak şekilde yazılmalı ya da `gets`/`fgets` gibi başka fonksiyonlar kullanılmalıdır. Derste satır sonuna kadar okuyan biçim olarak `%[^\n]` (yüzde, köşeli parantez içinde şapka ve `\n`) hatırlatıldı. Bu konu dosya işlemlerinde, dosyadan okuma yapılırken daha ayrıntılı görülecektir.

> **Ek bilgi (derste anlatılmadı):** `scanf(" %19[^\n]", bookName)` biçimi baştaki boşlukları atlayıp satır sonuna kadar en çok 19 karakter okur; bu biçimle "Seker Portakali" girdisi tek string olarak okundu (derleyiciyle denendi). `gets` taşma güvenliği olmadığı için C11'de standarttan çıkarılmıştır; yerine `fgets` kullanılır.

## 4. findKey: Özyinelemeli ASCII Toplamı

`insert` içinde kitap ismi `findKey` fonksiyonuna gönderilip kod elde edilir. Fonksiyon tek satırlık bir özyinelemedir (ekrandan, 00:25:00):

```c
int findKey(char *s) {
    return *s == 0 ? 0 : *s + findKey(s + 1); //if(s==0){return 0;} else{return *s+findKey(s + 1);}
}
```

Koşul operatörü (`?:`) şunu söyler: string boşsa (o anki karakter `'\0'` ise) 0 döndür; değilse o anki karakterin değerini al ve ona, bir sonraki karakterden (`s + 1`) başlayan alt stringin toplamını ekle. Yorum satırında aynı mantığın `if-else` hâli yazılıdır.

> **Ders sonrası not:** Yorumdaki `if(s==0)` koşulu işaretçinin kendisini sınar; asıl koddaki gibi karakteri sınamak için büyük olasılıkla `if(*s==0)` olmalıdır.

### 4.1 "book" örneğiyle çağrı zinciri

Anlatım Paint'te "book" kelimesi üzerinden çizildi (ekrandan, 00:40:00). Her çağrıda `s + 1` ile başlangıç noktası bir sağa kayar:

```text
f("book") = 'b' + f("ook")
f("ook")  = 'o' + f("ok")
f("ok")   = 'o' + f("k")
f("k")    = 'k' + f("")
f("")     = 0            (karakter '\0', özyineleme durur)
```

En içteki çağrı 0 döndürünce `f("k")` `k`'nin ASCII değerini döndürür. `f("ok")` buna `o`'yu ekler, `f("ook")` bir `o` daha ekler, en dışta `f("book")` `b`'yi ekler ve bütün karakterlerin toplamı elde edilir.

$$f(\text{"book"}) = 98 + 111 + 111 + 107 = 427 \quad \text{(sayılar eklendi)}$$

Sonradan gelen bir soru üzerine özyineleme bir kez daha anlatıldı. Kullanıcıdan bir string alındığında `scanf` sonuna `'\0'` karakterini ekler; böylece stringin nerede bittiği bellidir ve özyineleme bu karakterde durur. Bilgisayar karakterleri zaten ASCII değerleriyle tuttuğu için karakterleri toplamak doğrudan sayı toplamak demektir. Bu tekrar anlatımda hoca, mekanizmayı göstermek için farazi küçük sayılar kullandı: en içten 0 döner, `k + 0` örneğin 2 olur, bir üst seviye `o` ile 2'nin toplamını (örneğin 5) döndürür ve böylece her seviyede dönen değer bir öncekine eklenerek kod oluşur.

## 5. insert: Listenin Başına Ekleme ve Çift İşaretçi

### 5.1 Kod

`insert` fonksiyonu (ekrandan, 00:25:00 ve 00:30:00):

```c
void insert(List **headRef, char bookName[])
{
    List * newnode = (List*) malloc(sizeof(List));

    int i,key;
    key=findKey(bookName);
    i=key%SHELF;

    newnode->code  = key;
    newnode->index  = i;
    strcpy(newnode->name,bookName);

    newnode->next = (*headRef);

    (*headRef)     = newnode;
}
```

Yeni bir düğüm oluşturulacağı için önce `malloc` ile dinamik bellek ayrılır. Ardından kitap ismi `findKey`'e gönderilerek kod (`key`) bulunur, kodun 11'e göre modu alınarak raf numarası (`i`) bulunur. Kod ve raf numarası düğümün alanlarına atanır.

> **Hocanın vurgusu:** `malloc`'tan sonra ayırmanın başarılı olup olmadığı, yani dönüşün NULL olup olmadığı kontrol edilseydi daha iyi olurdu. Örnek kodda bu kontrol atlanmıştır.

Stringlerde doğrudan atama yapılamaz. `newnode->name = bookName` yazmanın anlamı yoktur; bu yüzden isim `strcpy` ile kopyalanır.

### 5.2 Başa ekleme adımları

Son iki satır yeni düğümü listenin başına ekler. Önce yeni düğümün `next`'i, `head`'in o anda gösterdiği düğümü gösterecek şekilde ayarlanır. Sonra `head` yeni düğüme eşitlenir; artık listenin başı yeni düğümdür. Bu, derste Paint'te kutularla çizildi (ekrandan, 00:45:00):

```text
Önce:     head -> [A] -> [B] -> [C] -> NULL
                  newnode = [N]

1) newnode->next = *headRef;   [N] -> [A] -> [B] -> [C] -> NULL
2) *headRef = newnode;         head -> [N] -> [A] -> [B] -> [C] -> NULL
```

Liste boşken `head` NULL olduğundan ilk eklenen düğümün `next`'i NULL olur; yani aynı iki satır boş listede de doğru çalışır (ara adım eklendi). Tek yönlü bağlı listede her düğüm tek bir işaretçi tutar ve bu işaretçi bir sonraki düğümün adresini gösterir; son düğümün `next`'i NULL'dır ve listenin sonuna gelinip gelinmediği NULL ile kontrol edilir.

Sona ekleme de yapılabilir. Bunun için yine bir struct işaretçisi tanımlanır, onunla son elemana kadar gidilir ve ekleme oraya yapılır.

### 5.3 Neden çift işaretçi?

`insert` listenin başını, yani `head`'i değiştirir. `main`'deki `head` değişkeninin de değişmesi gerektiği için onun adresi gönderilir: `insert(&head, bookName)`. Fonksiyon içinde `*headRef` yazmak, `main`'deki `head`'in kendisine erişmek demektir.

> **Hocanın vurgusu:** `head`'i değiştirmenin üç yolu vardır:
>
> 1. `head`'i global tanımlamak; böylece her fonksiyon `head`'i değiştirebilir. Bu tercih edilmeyen bir yöntemdir.
> 2. `head`'i diğer fonksiyonlardaki gibi tek işaretçi olarak göndermek, fonksiyon içinde değiştirdikten sonra yeni `head`'i `return` etmek (ör. `newnode`'u `head`'e eşitleyip `return head;`).
> 3. Çift işaretçi kullanmak; böylece geri dönüş değerine gerek kalmadan ve hataya yer bırakmadan `head` fonksiyon içinde değiştirilir.

`display` ve `search` listede değişiklik yapmadığı için tek işaretçi alır. İstenirse onlara da çift işaretçi gönderilebilir; bu programcıya kalmıştır.

## 6. display ve search Fonksiyonları

### 6.1 display

`display` listedeki bütün düğümlerin verilerini yazdırır: ismi, kodu ve raf numarasını. Bir düğüm işaretçisi baştan başlatılır ve her adımda `node = node->next` ile bir sonraki düğüme ilerletilir; böylece işaretçi sırayla her elemanı gösterir ve onun bilgileri yazılır. Çıktı biçimi ekranda `nutuk (567) -> 6` şeklindedir (ekrandan, 00:35:00).

<!-- BELİRSİZ: display fonksiyonunun kodu karelerde görünmüyor; Bölüm 8'deki gövde, anlatıma ve ekrandaki çıktı biçimine göre tamamlandı. -->

### 6.2 search

Arama için listeyi taramak gerekir. Bunun için geçici bir işaretçi (`tempNode`) ve kullanıcının aradığı ismi tutacak yeni bir `bookName` dizisi tanımlanır (ekrandan, 00:30:00):

```c
void search(List *head)
{
    List *tempNode;
    char bookName[MAXSIZE];

    printf("\nEnter A Book Name to Search on Bookshelf\n");
    scanf("%s",&bookName);

    if(head == NULL)
        printf("\n Book Could Not be Found \n");
    ...
```

Önce `head`'in NULL olup olmadığına, yani listenin boş olup olmadığına bakılır; liste boşsa aranacak eleman yoktur. Değilse `tempNode` `head`'e eşitlenir, çünkü liste en baştan gezilecektir. Döngü iki koşul sağlandıkça devam eder: sona ulaşılmamıştır (`tempNode` NULL değildir) ve o anki düğümün ismi aranan isme eşit değildir. Her adımda `tempNode = tempNode->next` ile ilerlenir.

İsimler `strcmp` ile karşılaştırılır. `strcmp`, birinci string ikinciden ASCII karşılığı olarak büyükse pozitif, küçükse negatif, eşitse 0 döndürür. Sonuç 0 değilse iki kitap ismi aynı değildir.

Döngüden çıkınca `tempNode`'un NULL olup olmadığına bakılır. NULL ise liste sonuna kadar gezilmiş ve kitap bulunamamıştır. Değilse karşılaştırma 0 vermiş, yani kitap bulunmuştur ve bulunduğu raf yazdırılır.

<!-- BELİRSİZ: search fonksiyonunun döngü ve if-else kısmı karelerde görünmüyor; Bölüm 8'deki kod anlatıma ve ekrandaki çıktılara göre tamamlandı. -->

### 6.3 Dolaşmanın çizimle anlatımı

Bağlı liste yapısı bir soru üzerine Paint'te tekrar çizildi (ekrandan, 00:45:00). Her kutuda veri ve `next` işaretçisi vardır. Arama için `tempNode` `head`'in gösterdiği düğümden başlatılır. Buradaki isim aranan isme eşitse döngüden çıkılır. Eşit değilse `tempNode = tempNode->next` denir ve bir sonraki düğüme geçilir. Bu, eşleşme bulunana ya da `tempNode` NULL olana kadar sürer. NULL olunca döngüden çıkılır ve `if` ile `tempNode`'un NULL olduğu görülerek "bulamadım" mesajı verilir.

### 6.4 Sık yapılan hata: NULL düğümün alanını okumak

**Soru (derste soruldu):** Döngüden sonra önce `tempNode`'un NULL olup olmadığını değil de doğrudan `tempNode->name` ile `bookName`'in eşit olup olmadığını sorsaydık, kitap bulunamadığında ne olurdu? Neden hata alırdık?

**Cevap:** Kitap bulunamadıysa döngü `tempNode` NULL olduğu için bitmiştir. Bu durumda `tempNode->name` yazmak, var olmayan bir düğümün ismini istemek demektir; NULL olan bir düğümün `name` alanı yoktur ve program hata verir. Bunu önlemek için ya önce döngüden neden çıkıldığı kontrol edilip `return` edilmeli, ya `if-else` sırası NULL kontrolü önce gelecek şekilde kurulmalı, ya da döngünün içinde NULL olunca `return` edilmelidir. Hangisinin seçileceği programcıya kalmıştır.

> **Ek bilgi (derste anlatılmadı):** Döngü koşulundaki `tempNode != NULL && strcmp(...) != 0` sırası da aynı nedenle önemlidir. `&&` kısa devre çalışır: ilk koşul yanlışsa ikincisi hiç değerlendirilmez, bu yüzden NULL düğümde `strcmp` çağrılmaz.

## 7. Programın Çalıştırılması ve Aynı Rafa Düşen Kitaplar

### 7.1 Deneme çalıştırması

Program çalıştırılıp şu girdiler verildi (ekrandan, 00:35:00):

- `aa` eklendi: `a`'nın ASCII değeri 97, iki tane olduğu için $194$; $194 \bmod 11 = 7$ (çünkü $11 \cdot 17 = 187$), 7. raf.
- `Tutunamayanlar` (büyük T ile) eklendi: $1494$, 9. raf.
- `nutuk` eklendi: $110+117+116+117+107 = 567$, $567 \bmod 11 = 6$ (çünkü $11 \cdot 51 = 561$), 6. raf. (Toplama ve bölme adımları eklendi.)

Listeleme çıktısı:

```text
nutuk (567) -> 6
Tutunamayanlar (1494) -> 9
aa (194) -> 7
```

Liste başa eklemeyle kurulduğu için son eklenen kitap en üstte görünür. Arama denemelerinde `nutuk` için "Book is on the 6th shelf", olmayan bir isim olan `zz` için "Book Is not In the Bookshelf" yazıldı.

### 7.2 Aynı rafa birden fazla kitap

**Soru:** Kitaplar aynı rafa nasıl yerleşebiliyor?

**Cevap:** Gerçek bir kitaplıkta bir rafa birden fazla kitap konabildiği gibi burada da aynı rafa birden fazla kitap yerleşebilir. Derste `nutuk` ikinci kez eklendi ve listede iki kez göründü. Aynı ismin iki kez eklenmesi istenmiyorsa ekleme öncesine ismi kontrol eden tek bir `if` konabilir; aynı isimse eklenmez, yalnız kodu ya da rafı aynıysa eklenir. Örnekte aynı kitabı yerleştirmekte sakınca görülmediği için bu yapılmadı; bu programcıya kalmıştır.

Gerçek bir kütüphanede bir kitaptan tek kopya olmak zorunda değildir; aynı kitaptan belki 100 tane vardır. Stok takibi gibi uygulamalarda her fiziksel kitaba ayrı bir kimlik (ID) verilir ve bu, veritabanında ayrı bir değer ya da programda ayrı bir değişkenle saklanır.

Farklı isimlerin de aynı kodu ya da aynı rafı vermesi mümkündür; yalnız `nutuk`'un değil, başka bir kitabın da rafı 6 olabilir. Buna çakışma denir. Aramayı hızlandırmak için hash veri yapısında bağlı listeler ve hash birlikte kullanılır: aynı anahtara düşen değerler bir bağlı listede belli bir düzende tutulur. Çakışmaların farklı çözüm yöntemleri vardır; bunlar veri yapıları dersinde görüleceği için bu derste girilmedi. Bu derste önemli olan temel programlama yapılarını öğrenmektir.

> **Ek bilgi (derste anlatılmadı):** Bu örnekteki "kod mod raf sayısı" hesabı basit bir hash fonksiyonudur. Aynı rafa düşen kitapları her raf için ayrı bir bağlı listede tutmaya "ayrı zincirleme" (separate chaining) denir; arama o zaman yalnız ilgili rafın listesinde yapılır.

Oturumun sonunda, örneklerin struct, özyineleme ve fonksiyonlara işaretçi aktarma gibi o ana kadar ayrı ayrı görülen konuların hepsini birlikte içerecek şekilde devam edeceği belirtildi.

## 8. Programın Tamamı

Aşağıdaki kod, karelerde görünen kısımlar (`struct` alanlarının son ikisi, `typedef`, fonksiyon bildirimleri, `main`'in menü kısmı, `findKey`, `insert` ve `search`'ün başı) birebir alınarak, görünmeyen kısımlar (kütüphaneler, `name` ve `code` alanları, `case 3` ve `display` gövdesi, `search`'ün döngüsü) anlatıma ve ekrandaki çıktılara göre tamamlanarak yazılmıştır. Tamamlanan kısımlar derste ekranda gösterilmedi. `scanf` satırlarında `&` kaldırıldı. Kod `gcc -Wall` ile uyarısız derlendi ve derste girilen verilerle (aa, Tutunamayanlar, nutuk, arama: nutuk ve zz) çalıştırılarak ekrandaki çıktıların aynısı alındı.

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXSIZE 20
#define SHELF 11

struct node {
    char name[MAXSIZE];   /* kitap ismi */
    int code;             /* ASCII toplamı */
    int index;            /* Raf_No */
    struct node *next;
};

typedef struct node List;

void insert(List **headRef, char bookName[]);
void search(List *head);
void display(List *head);
int findKey(char *s);

int main()
{
    int opt;
    List *head = NULL;
    char bookName[MAXSIZE];

    while (1)
    {
        printf("\nPress 1. Insert\t 2. Display \t3. Search \t4.Exit \n");
        scanf("%d", &opt);
        switch (opt)
        {
            case 1:
                printf("\nEnter Book Name\n");
                scanf("%s", bookName);
                insert(&head, bookName);
                break;
            case 2:
                display(head);
                break;
            case 3:
                search(head);
                break;
            default:
                exit(1);
        }
    }
    return 0;
}

void display(List *head)
{
    List *node = head;
    while (node != NULL) {
        printf("%s (%d) -> %d\n", node->name, node->code, node->index);
        node = node->next;
    }
}

int findKey(char *s) {
    return *s == 0 ? 0 : *s + findKey(s + 1);
}

void insert(List **headRef, char bookName[])
{
    List *newnode = (List *) malloc(sizeof(List));
    int i, key;
    key = findKey(bookName);
    i = key % SHELF;
    newnode->code = key;
    newnode->index = i;
    strcpy(newnode->name, bookName);
    newnode->next = (*headRef);
    (*headRef) = newnode;
}

void search(List *head)
{
    List *tempNode;
    char bookName[MAXSIZE];

    printf("\nEnter A Book Name to Search on Bookshelf\n");
    scanf("%s", bookName);

    if (head == NULL)
        printf("\n Book Could Not be Found \n");
    else {
        tempNode = head;
        while (tempNode != NULL && strcmp(tempNode->name, bookName) != 0)
            tempNode = tempNode->next;
        if (tempNode == NULL)
            printf("\n Book Is not In the Bookshelf\n");
        else
            printf("Book is on the %dth shelf\n", tempNode->index);
    }
}
```

## Örnek Sorular

**Soru 1** (ekrandan, 00:15:00): Bir kütüphanedeki 11 raflı bir kitaplığa çeşitli kitaplar yerleştirilecektir. Raflara hangi kitapların yerleştirileceğine, isimlerine göre hesaplanan birer kodla karar verilmektedir. N harf uzunluğundaki bir kitap ismi için kod, isimdeki bütün karakterlerin ASCII kodlarının toplamıdır; $\text{Raf\_No} = \text{Kod} \bmod \text{Raf sayısı}$ ve kitap koda denk gelen rafa yerleştirilir. Örneğin "Tutunamayanlar" için kod 1494'tür ve $1494 \bmod 11 = 9$ olduğundan kitap 9. rafa yerleştirilir. İsmi verilen kitabın raf numarasını belirleyerek listeye ekleyen, kitaplığa eklenen tüm kitapların raf bilgilerini listeleyen ve ismi verilen bir kitabı kitaplıkta arayıp bulunursa raf numarasını gösteren, bulunmazsa kısa bir mesaj gösteren bir algoritmayı C dilinde gerçekleyiniz.

> **Çözüm:** Derste verilen çözüm Bölüm 3-6'da anlatıldı, programın tamamı Bölüm 8'dedir. Kayıtlar `struct node` düğümlerinden oluşan tek yönlü bağlı listede tutulur; `findKey` kodu özyinelemeyle hesaplar, `insert` düğümü çift işaretçiyle listenin başına ekler, `display` listeyi dolaşıp yazar, `search` doğrusal arama yapar.

**Soru 2** (derste sözlü, 00:21:15): Kitap ismi olarak "Şeker Portakalı" girilirse `scanf("%s", bookName)` iki kelimeyi de okur mu?

> **Çözüm:** Okumaz; `%s` boşluğa kadar okuduğu için yalnız "Şeker" alınır. Bütün satırı okumak için `%[^\n]` biçimi ya da `fgets` kullanılır (Bölüm 3.5).

**Soru 3** (derste sözlü, 00:45:42): Arama döngüsünden sonra önce NULL kontrolü yapmadan `strcmp(tempNode->name, bookName) == 0` diye sorulsaydı, kitap bulunamadığında ne olurdu?

> **Çözüm:** Kitap bulunamadıysa döngü `tempNode` NULL olduğu için bitmiştir; `tempNode->name` NULL işaretçiyi kullanmak olur ve program hata verir. NULL kontrolü karşılaştırmadan önce yapılmalıdır (Bölüm 6.4).

**Soru 4** (derste sözlü, 00:15:00): Dizilerin ve bağlı listelerin avantajları ve dezavantajları nelerdir?

> **Çözüm:** Dizi indeksle doğrudan erişim sağlar ama büyütmek için kopyalama, araya ekleme için kaydırma gerektirir. Bağlı liste kolayca büyür ve ekleme/silmeyi sabit zamanda yapar ama elemana ulaşmak için baştan dolaşmak gerekir (Bölüm 2).

## Dersin Toparlaması

Bu uygulama oturumunda tek bir problem üzerinden dönemin birçok konusu birlikte kullanıldı: makrolarla sabit tanımlama, `struct` ve `typedef`, `malloc` ile dinamik düğüm ayırma, tek yönlü bağlı listede başa ekleme ve doğrusal arama, `strcpy` ve `strcmp` ile string işlemleri ve tek satırlık bir özyinelemeli fonksiyon. Kitap isminden ASCII toplamıyla kod üretip raf sayısına göre modunu almak basit bir hash fikridir; aynı rafa düşen kitaplar çakışma örneğidir ve bunun sistemli çözümleri veri yapıları dersine bırakıldı.

Akılda tutulması gereken noktalar şunlardır: listenin başını değiştiren fonksiyon `head`'in adresini (çift işaretçi) almalı ya da yeni `head`'i döndürmelidir; `%s` ile okunan stringler boşlukta kesilir; stringler `=` ile değil `strcpy` ile kopyalanır; NULL olabilecek bir düğümün alanına erişmeden önce NULL kontrolü yapılmalıdır. Derste, sonraki örneklerin bu konuların hepsini birlikte içerecek şekilde devam edeceği ve string okumanın dosya işlemleri konusunda daha ayrıntılı ele alınacağı belirtildi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
