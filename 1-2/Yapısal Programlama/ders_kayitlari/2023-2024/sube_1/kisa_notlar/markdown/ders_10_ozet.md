# Ders 10 Çalışma Özeti

## Genel Konular

- `main` fonksiyonunun parametreleri (`argc`, `argv`)
  - `int main(int argc, char *argv[])` imzasında `argc` komut satırından gelen argüman sayısını, `argv` ise her biri bir karakter dizisi (string) olan argümanları tutan karakter işaretçileri dizisini verir.
  - `argv` iki boyutlu bir metin dizisi gibi düşünülebilir: her satırın sonu `'\0'` ile anlaşılır, ama satır sayısı ancak `argc` ile bilinir.
  - `argv[0]` çalıştırılabilir dosyanın (programın) kendi adıdır; kullanıcının verdiği parametreler `argv[1]`'den başlar.
  - Programın komut satırından çalıştırılması gerekir; parametreler program adının ardından boşlukla verilir (ekrandan, 00:15:00: `Hafta07p birinci ikinci ucuncu`).
  - Kullanım örneği: bir tarayıcının kısayoluna `-safe-mode` gibi bir parametre eklemek. Programın `main`'i `argc`'ye bakar, parametreleri bir döngüde tek tek karşılaştırır ve buna göre davranır.
- Yapı (`struct`) tanımı
  - Diziler aynı türden verileri tutar. Bir varlığa ait farklı türden veriler (ad, soyad, kimlik, maaş) için ayrı ayrı paralel diziler kullanmak zahmetlidir (ekrandan, 00:20:00: `char names[1000][20], surnames[1000][20]; int IDs[1000]; float salaries[1000];`).
  - `struct` ile aynı varlığa ait alanlar tek bir kayıt (record) türünde toplanır; bu, C'ye yeni bir veri türü kazandırmaktır.
  - `struct employee { ... };` tanımından sonra türün adı `struct employee`'dir; tek başına `employee` yazılamaz.
  - `typedef struct { ... } EMPLOYEE;` ile adsız (anonymous) bir yapıya tür adı verilir; sonra `EMPLOYEE employees[1000];` yazılabilir (ekrandan, 00:25:00).
  - Gelenek: `typedef` ile tanımlanan yapı türlerinin adı tamamen büyük harfle yazılır.
- Yapı alanlarına erişim
  - Değişken üzerinden nokta (`.`) operatörü: `calisan.ID = 5;`
  - İşaretçi üzerinden ok (`->`) operatörü: `eptr->ID = 5;`
  - `eptr->ID` ile `(*eptr).ID` aynıdır; `*` ile `.` operatörlerinin öncelik farkı yüzünden parantez gerekir.
- İç içe yapılar
  - Bir yapının içinde başka bir yapı türünden alan olabilir; içteki yapı önce tanımlanmalıdır.
  - Örnek: `DATE` (gün, ay `short`; yıl `int`) ve içinde `DATE enlisted;` alanı olan `EMPLOYEE`; erişim `calisan.enlisted.year = <yıl>;` biçimindedir (ekrandan, 00:30:00).
- Yapıların fonksiyonlara aktarılması
  - Değerle aktarım (call by value): yalnız okuyan, rapor basan fonksiyonlar için yeterlidir; fonksiyondaki değişiklik kalıcı olmaz.
  - Adresle aktarım (call by reference): maaş artırma gibi kalıcı değişiklik için yapının adresi gönderilir, fonksiyonda `emp->salary += ...` yazılır.
  - Yapı işaretçisi `++` ile arttırılırsa bir sonraki yapıya (dizideki sonraki kayda) geçer; yapının alanları arasında dolaşmaz.
- Bağlı liste (linked list)
  - Düğümlerden (node) oluşur; her düğümde veri ve sonraki düğümü gösteren bir işaretçi vardır.
  - İlk düğüm baş düğüm (head), son düğüm kuyruk düğümü (tail); son düğümün `next` işaretçisi `NULL`'dur.
  - Baş düğümün adresi her zaman saklanmalıdır; kaybedilirse listeye ulaşılamaz.
  - Sona ekleme, araya ekleme ve aradan silme yalnız birkaç işaretçi değişikliğiyle yapılır; dizilerdeki gibi kaydırma gerekmez.
  - Tek dezavantajı: $k$'inci elemana doğrudan erişilemez, baştan `next` işaretçileri izlenmelidir.
- C ile çalışan listesi gerçeklemesi
  - `EMPLOYEE` yapısı hem veri hem düğüm olarak kullanılır (`struct Employee *next;` alanı); baş işaretçisi global `EMPLOYEE *head;`.
  - Fonksiyonlar: `printElementP`, `printList`, `create_list_element`, `add_element`, `insert_after`, `find`, `delete_element`.
  - Listenin boşaltılması: liste boşalana kadar baştaki düğüm silinir.
- Yapı hizalama (structure alignment)
  - Bazı mimarilerde `char`'dan büyük nesneler çift adreslerde başlamak zorundadır; bu durumda alanlar arasında boşluklar (hole) oluşur.
  - Alanların sırası değiştirilerek boşluklar azaltılabilir.
- Bit alanları (bit fields)
  - Yapı içinde `char`'dan küçük, bit düzeyinde alanlar tanımlanabilir: `int a : 3;`
  - Bit alanlarından dizi yapılamaz ve adresleri alınamaz.
  - Toplam bit sayısını alabilecek en küçük temel tür seçilir; alanların bellekteki sırası derleyiciye bağlıdır.

## Hocanın Özellikle Vurguladığı Kısımlar

- `argv[0]` programın adıdır
  - Kullanıcı parametreleri 1. indisten başlar. Çalıştırılabilir dosyanın parametrelerine erişme mantığı bilinmelidir.
- `typedef` ile tanımlanan yapı adları büyük harfle yazılmalı
  - Kodda büyük harfli bir tür adı görüldüğünde bunun bir yapı olduğu hemen anlaşılır; bu geleneğe uyulması istendi.
- Bağlı listede işlem sırası
  - Araya eklerken önce yeni düğümün `next`'i önceki düğümün `next`'ine eşitlenir, sonra önceki düğümün `next`'i yeni düğümü gösterir. Sıra ters olursa listenin geri kalanına ulaşım kaybolur.
  - Silerken silinecek düğümden önceki düğüm bulunur, bağ atlanır, sonra silinen düğüm `free` edilir.
- Baş düğüm (head) asla kaybedilmemeli
  - İpin ucu kaçırılırsa listeye geri dönmenin yolu yoktur.
- Kendine başvuran yapıda adsız yapı kullanılamaz
  - Yapı kendi türünden bir işaretçi içereceği için `typedef struct Employee { ... struct Employee *next; } EMPLOYEE;` biçiminde `struct` adı verilmek zorundadır.
- Test ederken bütün durumlar denenmeli
  - Silme işlevi baştaki, aradaki ve sondaki düğüm için ayrı ayrı denenmelidir; biri doğru çalışırken diğeri hatalı olabilir.
- Yapı alanlarının sırası bellek israfını etkiler
  - Hizalama boşluklarına yol açmayacak sırada tanımlama önemli bir not olarak verildi.

## Kısa Tekrar Notları

- `argc`: argüman sayısı; `argv`: `char *` dizisi; `argv[0]` = program adı.
- `struct` farklı türden alanları tek kayıtta toplar; `typedef` ile kısa tür adı verilir.
- Değişkende `.`, işaretçide `->`; `p->x` ≡ `(*p).x`.
- İç içe yapıda iç yapı önce tanımlanır; erişim `a.b.c` ya da `p->b.c`.
- Kalıcı değişiklik isteyen fonksiyona yapının adresi gönderilir.
- Bağlı liste: veri + `next`; son düğümün `next`'i `NULL`; `head` saklanır.
- Araya ekleme: `p->next = q->next; q->next = p;` (sıra önemli).
- Silme: önceki düğüm `p` bulunur, `p->next = p->next->next;`, sonra `free`.
- Liste diziye göre ekleme ve silmede üstün, doğrudan erişimde zayıftır.
- `malloc` dönüşü her zaman `NULL` için denetlenir.
- Hizalama: `char, short, char` sırası boşluk bırakabilir; `char, char, short` bırakmaz.
- Bit alanı: `tür ad : bit_sayısı;`, dizi ve adres yok, sıra derleyiciye bağlı.

## Detaylı Açıklamalar

`main` fonksiyonu iki parametreyle yazıldığında programa komut satırından bilgi aktarılabilir. `argc` kaç argüman geldiğini, `argv` ise bu argümanları karakter dizileri olarak gösteren işaretçileri tutar. Derste program önce `birinci ikinci ucuncu` parametreleriyle komut satırından çalıştırıldı. Slayttaki örnek `argc`'yi önce azaltıp sonra kullanarak ilk parametreyi, yani program adını atlıyordu. Ardından döngü sıfırdan başlayan düz bir `for` döngüsüyle yeniden yazıldı. Bu durumda çıktının ilk satırında programın kendi adı (`Hafta07p`) göründü (ekrandan, 00:15:00). <!-- BELİRSİZ: argv örneğinin slayttaki ve editördeki kod satırları karelerde görünmüyor; mantık altyazıdan kuruldu. --> Parametrelerin her biri programın mantığına göre ayrı bir anlam taşıyabilir (güvenli modda açıl, ilk girdiyi şu kabul et vb.); birbirinin alternatifi olmaları gerekmez.

Yapılar, bir problem alanındaki varlığı tek bir kayıtla modellemeyi sağlar. 1000 çalışanın adı, soyadı, kimliği ve maaşı ayrı dizilerde tutulursa aynı indisteki elemanlar aynı kişiye aittir ve bu düzeni korumak angaryadır. Bunun yerine şöyle bir yapı tanımlanır:

```c
typedef struct {
    char name[20], surname [20];
    int  ID;
    float salary;
} EMPLOYEE;

EMPLOYEE employees[1000];
```

(ekrandan, 00:25:00) Tarih gibi kendi içinde anlamlı bir bütün oluşturan veriler ayrı bir yapı olarak tanımlanıp başka yapının içine konur. Bu sayede tarihi bütün olarak işleyen fonksiyonlar yazılabilir (ekrandan, 00:30:00):

```c
typedef struct {
    short day, month;
    int year;
} DATE ;
typedef struct {
    char name[20], surname [20];
    int  ID;
    float salary;
    DATE enlisted;
} EMPLOYEE ;
/* kullanım: calisan.enlisted.year = <yıl>; */
```

Değişken bir işaretçiyse yalnız en dıştaki erişim ok operatörüyle yapılır: `ptr->enlisted.year`.

Bağlı liste, dizilerin iki zayıflığına çözüm olarak anlatıldı. Dizilerin boyutu kendiliğinden büyüyüp küçülmez, araya eleman eklemek ya da aradan silmek ise elemanların kaydırılmasını gerektirir. Hoca listeyi bir tespihe ya da birbirine iple bağlı sosislere benzetti. Slayttaki örnek liste 49 → 15 → 73 → 87 → 10 düğümlerinden oluşur; 49 baş, 10 kuyruk düğümüdür ve 10'un `next`'i `NULL`'dur (ekrandan, 00:35:00). Tahtada üç işlem gösterildi (ekrandan, 00:40:00 ve 00:45:00):

- Sona ekleme: değeri 3 olan yeni düğüm oluşturulur, `next`'i `NULL` yapılır, eski kuyruk 10'un `next`'i yeni düğümü gösterir ve kuyruk 3 olur.
- Araya ekleme (87 ile 10 arasına 4): önce `yeni->next = 87'nin next'i` (1. adım), sonra `87'nin next'i = yeni` (2. adım).
- Silme (73'ü silmek): 73'ten önceki düğüm 15, `p` ile bulunur; silinecek düğüm `sil` işaretçisinde tutulur; `p->next = sil->next` yapılır ve `free(sil)` çağrılır.

Ders kodunda veri ve düğüm aynı yapıdır (ekrandan, 00:50:00). Hoca daha doğru tasarımın, veriyi (`EMPLOYEE`) ve düğümü (`EMPLOYEE_NODE`) iki ayrı yapı olarak tanımlamak olduğunu da söyledi. Derste basitlik için ilk biçim kullanıldı:

```c
#include <stdio.h>
typedef struct Employee {
    char name[20], surname [20];
    int  ID;
    float salary;
    struct Employee *next;
} EMPLOYEE;
EMPLOYEE *head;
```

Ders kodundaki işlevler şunlardır (kod ekrandan, 01:10:00, 01:15:00, 01:35:00, 01:45:00, 01:55:00; editörde `surname` alanı çıkarıldı):

- `printElementP(EMPLOYEE *emp)`: tek çalışanı yazar.
- `printList()`: `for(j=0, p=head; p != NULL; p=p->next, j++)` döngüsüyle bütün listeyi yazar.
- `create_list_element()`: `malloc(sizeof(EMPLOYEE))` ile yer ayırır, `NULL` denetimi yapar, adı, kimliği ve maaşı kullanıcıdan alır, `next = NULL` yapar ve düğümü döndürür. Bazı platformlarda işaretçi olmayan alanlar `scanf` ile doğrudan okunamadığı için kimlik ve maaş önce yerel değişkene okunup sonra alana atanır.
- `add_element(EMPLOYEE *e)`: liste boşsa `head = e` yapılır. Değilse son düğüm gövdesiz bir `for` döngüsüyle bulunur ve `next`'i `e` yapılır.
- `insert_after(p, q)`: `p`'yi `q`'dan hemen sonra ekler. `p` ya da `q` `NULL` ise, ikisi aynıysa ya da `p` zaten `q`'dan sonra geliyorsa hata verir.
- `find(char *name)`: `strcmp` ile adı arar, bulamazsa `NULL` döndürür. Birden fazla alana göre arama gerekirse C'de aşırı yükleme olmadığı için `findByName`, `findById` gibi ayrı adlar verilir.
- `delete_element(goner)`: silinecek düğüm `head` ise `head` kaydırılır. Değilse önceki düğüm `(p!=NULL) && (p->next != goner)` koşuluyla aranır. `p` `NULL` çıkarsa düğüm bulunamamıştır; bulunduysa `p->next = p->next->next` yapılır. En sonda `free(goner)` çağrılır.

Listeyi boşaltmak için `while (head != NULL) delete_element(head);` yeterlidir.

Yapı hizalamasında slayttaki örnek `struct ALIGN_EXAMP { char mem1; short mem2; char mem3; } s1;` idi (ekrandan, 02:25:00). Kısıt yoksa yapı 1000–1003 adreslerine sığar (mem1 1000, mem2 1001–1002, mem3 1003). Çift adres kısıtı varsa yerleşim şöyle olur: mem1 1000, boşluk 1001, mem2 1002–1003, mem3 1004, boşluk 1005. Sıra `char mem1; char mem3; short mem2;` yapılırsa boşluk kalmaz.

Bit alanlarında örnek `struct { int a : 3; int b : 7; int c : 2; } s;` idi. 16 bitlik bir `int` içinde a 0–2, b 3–9, c 10–11 bitlerini kaplar; 12–15 boş kalır (ekrandan, 02:30:00). `DATE` örneğinde gün 5 bit ($2^5=32$), ay 4 bit ($2^4=16$), yıl 11 bit ($2^{11}=2048$) alır; toplam 20 bittir (ekrandan, 02:35:00). Derleyici alanları `short` sınırına yerleştirip alanın `int` sınırını aşmasına izin vermezse day–month ile year arasında ve kaydın sonunda boşluk kalır. Hoca sırayı gün (5), yıl (11), ay (4) yapmayı önerdi: ilk 16 bit tam dolar, ayın bulunduğu baytta yalnız 4 bit boş kalır.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
