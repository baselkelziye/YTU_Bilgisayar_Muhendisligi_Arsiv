# Ders 11 Genişletilmiş Notu: Yapılar (struct) ve Bağlı Liste Gerçeklemesi

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Yapılara Neden İhtiyaç Var?
- 2. struct Tanımı ve typedef
- 3. Alanlara Erişim: Nokta ve Ok İşleçleri
- 4. İç İçe Yapılar
- 5. Struct'ları Fonksiyonlara Aktarmak ve Struct İşaretçileri
- 6. Dizilerin Sınırları ve Bağlı Liste Fikri
- 7. Bağlı Listede Düğüm Yapısı İçin İki Seçenek
- 8. Bağlı Liste Fonksiyonları
- 9. Canlı Kodlama: Listeyi Denemek
- 10. Listeyi Bellekten Silmek ve Özyinelemeye Giriş
- 11. Fonksiyonların Birleştirildiği Tam Program
- Örnek Sorular

## 1. Yapılara Neden İhtiyaç Var?

Ders, bir önceki derste temeline gelinen yapılar (struct) konusunun hızlı bir tekrarıyla başladı. Programlarda çeşitli verileri işleriz. Peki belirli bir varlıkla ilgili birden fazla, üstelik farklı türlerde veri varsa ne yapabiliriz? Hocanın örneği öğrenci bilgileriydi: öğrencinin adı, numarası ve not ortalaması. Bunları ayrı dizilerde tutmak zorunda kalırsak numaralar bir dizide, adlar başka bir dizide, ortalamalar üçüncü bir dizide durur. Ad bir string olduğu için n öğrencinin adlarını tutmak için iki boyutlu bir karakter matrisi gerekir: satır sayısı öğrenci sayısı kadar, sütun sayısı en uzun ad kadar. Dinamik bellek yönetimi kullansak bile arka planda yine iki boyutlu bir alan ayırmak gerekir.

Daha da kötüsü, bu ayrı dizilerde aynı öğrencinin bilgileri hep aynı indiste durur: bir boyutlu dizide aynı indis, iki boyutlu matriste aynı satır indisi. Programcı bunun farkında olmalı ve kodunu buna göre yazmalıdır. Bu ekstra bir karmaşıklıktır.

Slayttaki örnek çalışanlarla ilgiliydi (ekrandan, 00:05:00). Bir çalışanın kaydı için adını ve soyadını string, sicil numarasını tam sayı, maaşını ondalıklı sayı olarak tutmak gerekir. Dizilerde ısrar edersek birden fazla dizi gerekir; bin çalışanı izlemek istiyorsak:

```c
char names[1000][20], surnames[1000][20];
int  IDs[1000]; float salaries[1000];
```

Bir varlığa ait bütün verileri tek bir yapı altında tutamaz mıyız? Tutabiliriz ve tutmalıyız. Bunun yolu `struct` yapısıdır.

## 2. struct Tanımı ve typedef

Bir `struct` bloğu açılır ve ilgilenilen varlığın bütün verileri bu bloğun içinde toplanır. `struct` sözcüğünden sonra yapıya bir ad verilir; çalışan bilgileri tutulacağı için örnekte ad `employee` oldu. Çalışanın 20 karakterlik adı, 20 karakterlik soyadı, tam sayı sicil numarası ve ondalıklı maaşı alan olarak yazılır. Blok kapatıldıktan sonra noktalı virgül konmalıdır; bu unutulmamalıdır. Artık `struct employee`, `int`, `char`, `float` gibi yeni bir veri türüdür. En fazla 1000 çalışanın kaydını tutacak bir dizi tanımlamak için önce tür adı (`struct employee`), sonra dizinin adı, sonra köşeli parantez içinde eleman sayısı yazılır.

`struct employee` her yerde yazılması gereken uzun bir tür adıdır. Kısaltmanın yolu `typedef` (type definition) sözcüğüdür. Tanımın başına `typedef` konur, sonra struct tanımlanır. Struct'ın adı boş bırakılırsa anonim bir struct tanımlanmış olur; `typedef` bu anonim struct'a kapanış parantezinden sonra yazılan adı verir:

```c
typedef struct {
    char name[20], surname[20];
    int ID;
    float salary;
} EMPLOYEE;
```

<!-- BELİRSİZ: Bu tanımın yer aldığı slayt karelerde yok; alanlar 00:05:00 ve 00:10:00 karelerindeki tanımlardan alındı. -->

Kendi tanımladığımız türlere ad verirken adın tamamını büyük harfle yazmak, bunun özel bir tür olduğunu hemen anlamayı sağlar. Bu yüzden ad `EMPLOYEE` oldu. Artık `EMPLOYEE` yazmak, o anonim struct'ı kullanmak anlamına gelir.

## 3. Alanlara Erişim: Nokta ve Ok İşleçleri

Struct türünden bir değişken tanımlandıktan sonra alanlarına `degisken.alan` biçiminde erişilir. Bu sıradan değişkenler içindir. Struct türünden bir işaretçi tanımlandıysa, işaretçinin gösterdiği kaydın alanına gitmek için nokta yerine ok işleci (`->`) kullanılır: bir eksi işareti ile bir büyüktür işareti yan yana gelince oka benzer.

Ok gösterimi arka planda `(*p).alan` biçimine dönüşür. O şekilde yazmak da doğrudur, ama özellikle işaretçi aritmetiğiyle birlikte kullanıldığında fazladan yıldız ve parantezler ifadeyi karıştırır. Bu yüzden ok gösterimi en doğru ve en okunaklı yoldur; derste de o kullanıldı.

## 4. İç İçe Yapılar

Bir struct başka bir struct'ın içinde tanımlanabilir ve böylece veri hiyerarşileri kurulur (ekrandan, 00:10:00). Örneğin çalışanların işe giriş tarihleri de saklanacaksa, çalışan struct'ına gün, ay ve yıl için üç ayrı alan eklemek yerine, kendi içinde anlamlı bir bütün oluşturan tarih bilgisi ayrı bir struct olarak tanımlanır. Ayrı tanımlanan yapılar ayrı ayrı da kullanılabilir; gerektiğinde iç içe konur:

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
```

Daha önce tanımlanmış bir çalışan değişkeninin işe giriş yılına ulaşmak için nokta işleci zincirleme kullanılır. Slayttaki satır şu biçimdedir (ekrandan, 00:10:00; slayttaki değişken adı burada genel bir adla yazıldı):

```c
calisan.enlisted.year = 2008;
```

Değişken işaretçi olsaydı noktaların yerini ok işleci alırdı.

## 5. Struct'ları Fonksiyonlara Aktarmak ve Struct İşaretçileri

Sıradan değişkenler gibi struct'lar da fonksiyonlara değer ile (call by value) ya da referans ile (call by reference) aktarılabilir. Hoca burada önemli bir noktayı belirtti: struct'larda referans ile aktarma daha verimlidir. Değer ile aktarmada struct'ın bütün alanları kopyalanır; işaretçi göndermek ise her durumda yalnız bir adres kopyalamaktır. Hoca bunu "işaretçi her yerde aynı hızda çalışır, ama struct'ta değeri kopyalamaya göre kazanç daha büyük olur" diye düzeltti.

Bir struct'a işaretçi tanımlandığında bu işaretçi struct'ın yalnız ilk alanını göstermez, struct'ın tamamını gösterir. Bir `int` işaretçisinin dizinin ilk elemanını göstermesine benzer. `EMPLOYEE` türünden bir işaretçinin adresi bir artırılınca bir sonraki struct kaydına ulaşılır, struct'ın bir sonraki alanına değil.

> **Ek bilgi (derste anlatılmadı):** İşaretçi aritmetiğinde `p + 1`, adresi `sizeof(*p)` bayt ilerletir. Struct'larda derleyici hizalama için alanlar arasına dolgu baytları koyabildiğinden `sizeof(EMPLOYEE)` alanların boyutları toplamından büyük olabilir.

## 6. Dizilerin Sınırları ve Bağlı Liste Fikri

Örnekler dizilerle verildi, ama dizilerin verimsizlikleri daha önce çok görüldü. Boyut sabit olduğu için araya eleman eklemek ve aradan eleman silmek zordur; alanı büyütüp küçültmek mümkün değildir. Daha geniş yeni bir dizi tanımlayıp eski elemanları ona aktarmak olabilir, ama bu ek iş ve performans kaybıdır. Veriyi daha iyi düzenlemenin çeşitli yolları vardır ve bunlarla ilgilenen veri yapıları (data structures) konusu her bilgisayar mühendisinin bilmesi gereken bir bilgi birikimidir. Diziler de en ilk, en temel ve en basit veri yapısı sayılır. Bu derste örnek olarak bağlı liste (linked list) veri yapısı tanıtıldı ve struct'larla birlikte kullanımı gösterildi; ayrıntıları veri yapıları derslerinde görülecek.

### 6.1 Düğüm, Baş ve Kuyruk

Slayttaki örnek, tam sayı tutan bir bağlı listedir (ekrandan, 00:15:00):

```text
[49 | o]--> [15 | o]--> [73 | o]--> [87 | o]--> [10 | NULL]
 Head node                                       Tail node
```

İki dikdörtgenden oluşan her parça bir düğümdür (node). Düğümün ilk parçası veri (data), ikinci parçası bir sonraki düğümü gösteren bağlantıdır (link), yani bir işaretçidir. Liste adını bu bağlantılardan alır. Hoca, slayttaki okların ucunun aslında veri alanını değil düğümün tamamını göstermesi gerektiğini belirtti: bağlantı işaretçisi bir sonraki değeri değil, bir sonraki düğümü (o da bir struct olacak) gösterir. Bu işaretçiye `next` denir.

Bu liste tek yönlüdür (single linked): baştan sona doğru izlenebilecek tek bir yön vardır. Her düğümde hem önceki (previous) hem sonraki düğümü gösteren iki işaretçi varsa çift bağlı liste (double linked list) olur. Tek ya da çift bağlı olmasından bağımsız olarak, son düğüm ilk düğümü gösteriyorsa liste daireseldir (circular single / circular double linked list). Derste en basit tür, yani tek bağlı ve dairesel olmayan liste kullanıldı.

Listenin son düğümünde, başka düğüm olmadığını göstermek için `next` işaretçisinin değeri `NULL`'dur. İşaretçi aritmetiğinde "ayrılan alanın başlangıcını gösteren işaretçiyi kaybetmeyin" kuralı burada da geçerlidir: bağlı listenin ilk düğümü (head node) kaybedilmemelidir. Liste üzerinde dolaşırken ya ne kadar ilerlendiğini tutup head'i geri getirmek gerekir, ya da daha doğrusu ve daha sağlamı, yeni bir işaretçi tanımlayıp onu head'e eşitlemek ve yalnız o işaretçiyi ilerletmektir.

## 7. Bağlı Listede Düğüm Yapısı İçin İki Seçenek

Düğümde bir veri kısmı ve bir `next` işaretçisi olacağına göre, bağlı liste iki türlü gerçeklenebilir.

### 7.1 Birinci Seçenek: next İşaretçisi Verinin İçinde

`next` işaretçisi tutulan verinin struct'ının içine gömülür. Çalışan örneğinde `EMPLOYEE` struct'ı hem çalışanın verilerini hem de düğümün `next` işaretçisini içerir. Bu, işleri daha basit yapar. Ancak bu durumda struct anonim tanımlanamaz: struct'ın tanımı içindeyken struct'ın kendi türünden bir `next` işaretçisi tanımlamak gerekir ve bunun tek yolu, tanımlanmakta olan struct'a bir ad vermektir. `typedef` sonradan bütün yapıya `EMPLOYEE` adını verse de, tanımın içinde bu ad henüz kullanılamaz. Bu yüzden `typedef struct employee` denir ve `next` işaretçisinin türü `struct employee *` olarak yazılır. Derste ve uygulamalarda bu seçenek kullanıldı. Canlı kodlamadaki tanım şu yapıdadır:

```c
typedef struct employee {
    char name[20];
    int ID;
    float salary;
    struct employee *next;
} EMPLOYEE;
EMPLOYEE *head;
```

<!-- BELİRSİZ: Bu tanımın slaytı ve editördeki hali karelerde görünmüyor; alanlar 00:20:00 karesindeki EMPLOYEE tanımı, 00:25:00 ve 00:30:00 karelerindeki emp->next kullanımı ve altyazıdaki "typedef struct employee" anlatımından kuruldu. -->

### 7.2 İkinci Seçenek: Veri ve Düğüm Ayrı

İkinci seçenekte veri ile verinin saklanış biçimi ayrı tutulur (ekrandan, 00:20:00). `EMPLOYEE` struct'ı yalnız problem alanıyla ilgili verileri içerir. Bağlı listenin düğümü ayrı bir struct'tır: içinde `EMPLOYEE` türünden bir veri alanı ve kendi türünden bir `next` işaretçisi vardır. Listenin başı da artık düğüm türünden (`EMP_NODE *`) tanımlanır:

```c
#include <stdio.h>
typedef struct {
    char name[20];
    int  ID;
    float salary;
} EMPLOYEE;
typedef struct emp_node {
    EMPLOYEE data;
    struct emp_node *next;
} EMP_NODE;
EMP_NODE *head;
```

Slayttaki gerekçe: bu tanım, problem alanıyla ilgili struct'ı veri gösterimiyle ilgili struct'tan ayrı tutar. Bu daha esnek bir yapıdır, çünkü çalışanlar başka veri yapılarında da saklanmak istenebilir. Hoca şöyle bir örnek verdi: bağlı listede belirli bir sicil numarasına sahip çalışanı bulmak için listenin başından başlayıp her düğümü kontrol etmek gerekir; sona gelip `next`'in `NULL` olduğu görülürse çalışan listede yoktur. Bu sorgu çok sık yapılıyorsa, istenen kayda doğrudan ulaşmayı sağlayan hash tablosu (hash table, hash map) gibi bir anahtar-değer yapısı daha uygundur; bu derste o tarafa girilmedi. Veri ileride farklı veri yapılarında kullanılacaksa ikinci seçenek tercih edilmelidir, yoksa veri boşu boşuna bir `next` işaretçisi taşır. Birinci seçenekte verinin türü ile saklanma biçimi birbirine sıkıca bağlanır (bağlaşım fazladır); ikinci seçenekte ise kod biraz daha zahmetli olur. Seçim programın ihtiyaçlarına göre yapılır. Struct yapısını da birlikte öğrenmek amaçlandığı için derste daha hızlı çözüm olan birinci seçenekle ilerlendi. Slaytta ikinci seçenek öğrencilere alıştırma olarak bırakıldı.

## 8. Bağlı Liste Fonksiyonları

Bu bölümde slaytlardaki temel işlemler sırayla anlatıldı; sonra canlı kodlamayla denendi.

### 8.1 Bir Çalışanı ve Bütün Listeyi Yazdırmak

Bir çalışanın bilgilerini konsola yazdırmak için `printElementP` fonksiyonu parametre olarak çalışanın adresini (işaretçi) alır, çünkü struct'larda işaretçi aktarmanın daha verimli olduğu söylenmişti. Alanlara ok işleciyle erişilir. Bütün listeyi yazdırmak için baş düğümden başlayan bir dolaşma işaretçisi tanımlanır ve her adımda o işaretçiye sıradaki düğümün adresi (`p->next`) atanır. Liste sonunda `p` `NULL` olur ve döngü biter (ekrandan, 00:25:00):

```c
void printElementP( EMPLOYEE *emp ) {
    printf("Employee %d %s has a salary of %f\n",
        emp->ID, emp->name, emp->salary );
}
void printList( ) {
    int j; EMPLOYEE *p;
        for(j=0, p=head; p != NULL; p=p->next, j++)
            printf("%d-th person: %d\t%s\t%f\n",
             j+1, p->ID, p->name, p->salary);
}
```

Hoca `for` döngüsünün başlangıç kısmında ve artırım kısmında virgülle ayrılarak birden fazla ifade verilebildiğini hatırlattı; burada sayaç `j` ile dolaşma işaretçisi `p` birlikte başlatılıp birlikte ilerletiliyor. Döngü `while` ile de yazılabilir. Ayrıca, madem tek eleman yazdıran `printElementP` var, `printList` içinde onu çağırmak daha mantıklı olabilirdi; ama tek düğümü ve listeyi farklı biçimlerde göstermek gerekiyorsa böyle ayrı yazılır.

### 8.2 Yeni Bir Çalışan Oluşturmak

Dinamik bellek yönetiminde önce `main` içinde n eleman alacak kadar yer ayırıp fonksiyonlara başlangıç adresini vermek öğrenilmişti. Bağlı listede durum farklıdır: her çalışan için ayrı ayrı bellekte yer ayrılır, veriler kullanıcıdan alınır ve listenin yapısını sürdürecek ek işlemler yapılır (ekrandan, 00:30:00):

```c
EMPLOYEE* create_list_element(  ) {
    EMPLOYEE *emp; int i; float s;
    emp = (EMPLOYEE*) malloc( sizeof( EMPLOYEE ) );
    if( emp == NULL ) {
        printf("create_employee: out of memory."); exit(1);
    }
    printf("Enter name of the person: "); scanf("%s", emp->name);
    //can't get non-pointer struct fields directly in some platforms
    printf("Enter ID of the person: ");
    scanf("%d", &i); emp->ID = i;
    printf("Enter salary of the person: ");
    scanf("%f", &s); emp->salary = s;
    emp->next=NULL; return emp;
}
```

Fonksiyon geriye `EMPLOYEE` türünden bir işaretçi, yani yeni oluşturulan düğümü döndürür. Tek kayıt oluşturulduğu için `malloc`'a "1 çarpı" yazmaya gerek yoktur; tür artık `EMPLOYEE` olduğundan bir kaydın kaç bayt tuttuğunu `sizeof(EMPLOYEE)` hesaplar. `malloc`'un döndürdüğü `void *` işaretçi `EMPLOYEE *`'a dönüştürülür. Bellekte yer kalmamış olabileceği için `NULL` denetimi yapılır; yer yoksa mesaj yazılıp `exit(1)` ile programdan çıkılır.

Ad alanı struct'ın içinde dizi olarak yer aldığı için ona doğrudan girdi alınabilir: `scanf("%s", emp->name)`. Sicil numarası ve maaş için ise slayttaki yoruma göre bazı derleyici ve platformlarda ilkel türden (primitive) alanlara doğrudan okuma yapılamayabilir. Bu yüzden değer önce `i` ve `s` geçici değişkenlerine (adres verilerek) okunur, sonra alana atanır. Yeni kayıtlar hep listenin sonuna ekleneceği için yeni düğüm listenin son düğümü olacaktır; bu yüzden `next` işaretçisi `NULL` yapılır. Düğümü listeye bağlamak, bu fonksiyonu çağıran tarafa kalır.

> **Ders sonrası not:** Standart C'de `scanf("%d", &emp->ID);` geçerlidir; `&emp->ID` ifadesi `&(emp->ID)` olarak çözülür ve alanın adresini verir. Geçici değişken kullanmak yanlış değildir, ama standart bunu zorunlu kılmaz. Slayttaki uyarı büyük olasılıkla eski bir derleyici ya da platform deneyimine dayanıyor.

> **Ek bilgi (derste anlatılmadı):** `scanf("%s", ...)` okunacak uzunluğu sınırlamaz; 20 karakterlik alana daha uzun bir ad girilirse taşma olur. `scanf("%19s", emp->name)` biçiminde genişlik vermek bu riski kaldırır.

### 8.3 Listenin Sonuna Eklemek

`add_element` fonksiyonu parametre olarak eklenecek düğümü alır ve geriye bir şey döndürmez. Listenin yalnız başı saklandığı için yeni elemanı eklemek üzere mevcut sona kadar ilerlemek gerekir; bunun için geçici `p` işaretçisi kullanılır. Her olasılık düşünülmelidir: belki eklenen eleman listenin ilk elemanıdır. Daha önce hiç eleman eklenmemişse `head` `NULL`'dur ve yeni düğüm doğrudan baş olur. Yeni düğümün `next`'i bir önceki fonksiyonda zaten `NULL` yapıldığı için başka bir şey gerekmez (ekrandan, 00:35:00):

```c
void add_element(EMPLOYEE *e){
    EMPLOYEE *p;
    // if the 1st element (head) has not been created, create it now:
    if(head == NULL){ head=e; return; }
    // otherwise, find the last element in the list:

    //Span through each element testing to see whether p.next is NULL.
    //If not NULL, p.next must point to another element.
    //If NULL, we have found the end of the list and we end the loop.
    for (p=head; p->next != NULL; p=p->next); // null statement

    // append a new structure to the end of the list
    p->next=e;
}
```

Döngünün gövdesine ihtiyaç yoktur: `for`'un üç bileşeni dolaşma işaretçisini zaten listenin sonuna getirir. Bu yüzden döngü doğrudan noktalı virgülle biter; buna boş deyim (null statement) denir. Döngüden çıkıldığında `p` listenin son düğümünü gösterir ve `p->next=e;` ile eski son düğüm artık yeni düğümü gösterir.

Hoca bunu şekil üzerinde gösterdi. Önce `p = head` ile `p` ilk düğümü gösterir. Koşul yanlışlıkla `p != NULL` yazılsaydı `p` her adımda bir sonraki düğüme geçer ve en sonunda `NULL` olurdu. O zaman yeni düğüm nereye bağlanacaktı? Eski son düğümün `next` işaretçisinin değiştirilmesi gerekir. Bu yüzden koşul `p->next != NULL`'dır: `p` son düğümde, yani `next`'i `NULL` olan düğümde durur.

> **Hocanın vurgusu:** Sona eklemede döngü `p->next` `NULL` olmadığı sürece sürer, `p` `NULL` olmadığı sürece değil. Aksi halde son düğüm kaybedilir ve yeni düğüm bağlanamaz.

### 8.4 Bir Elemanı Silmek

Dizilerde silme zordu; bağlı listede ise görece kolaydır. Yalnız hangi işlemin hangi sırada yapılacağı unutulmamalıdır. Hoca şekildeki sayıların çalışanların sicil numaraları olduğunu varsaydı ve 73 numaralı çalışanın "işten çıkarılacağını" söyledi. Silinecek düğümü gösteren işaretçiye goner adı verildi (ekrandan, 00:40:00).

Goner işaretçisine ulaşmak için çıkarılacak kişinin sicil numarası girilir ve ilgili kişiyi bulana kadar liste dolaşılır. Silme için goner'dan bir önceki düğüm de gerekir. Dolaşma işaretçisi `p`, `p->next` goner olana kadar (yani `next`'in gösterdiği düğümün sicili aranan sicil olana kadar) ilerletilir; bu örnekte 15 düğümünde durur. Sonra yapılması gereken tek şey 15'in `next`'inin 87'yi göstermesidir: `p->next = goner->next;`. Ardından `free(goner)` ile düğüm bellekten silinir; düğümün verisi ve `next` işaretçisi de onunla birlikte gider. Böylece dizide silmeye göre çok daha az işle eleman listeden çıkarılır.

Yine her durum düşünülmelidir:

- Silinecek eleman listenin ilk elemanıysa `head` değiştirilmelidir: `head`, silinen elemanın `next`'ini gösterir. Listede tek eleman varsa onun `next`'i `NULL` olduğu için `head` de `NULL` olur, yani liste boşalır. Diğer fonksiyonlar boş listeyi zaten ele aldığı için bu sorun çıkarmaz.
- Aranan eleman listede bulunmayabilir. Bu yüzden döngü koşulu, `p->next` goner olmadığı sürece devam etmenin yanında `p`'nin `NULL` olmadığını da VE işleciyle denetler. Döngünün gövdesi yine boş deyimdir.
- Döngüden iki yoldan biriyle çıkılır: ya aranan bulunur (`p->next` goner olur) ya da bulunamaz (`p` `NULL` olur). Bulunamadıysa ekrana bu durum yazılıp `return` ile çıkılır. Hoca, önce sorunlu durumu ele alıp sonra asıl işi yapmanın kendi alışkanlıkları olduğunu, ters mantığın da kullanılabileceğini söyledi.

Hoca ayrıca `p->next` zaten goner olduğu için `p->next = goner->next;` yerine `p->next = p->next->next;` da yazılabileceğini belirtti. Silme fonksiyonunun slayt kodu karelerde bulunmuyor; aşağıdaki kod altyazıdaki anlatıma göre kuruldu ve bölüm 11'deki programla derlenip denendi:

<!-- BELİRSİZ: Slayttaki silme kodunun birebir hali karelerde yok; aşağıdaki kod anlatımdan kuruldu. -->

```c
void delete_element(EMPLOYEE *goner) {
    EMPLOYEE *p;
    if (goner == head) {
        head = goner->next;
    } else {
        for (p = head; p != NULL && p->next != goner; p = p->next);
        if (p == NULL) { printf("delete_element(): not found\n"); return; }
        p->next = goner->next;
    }
    free(goner);
}
```

### 8.5 Eleman Aramak

Hangi alana göre aranacaksa ona göre ayrı bir arama fonksiyonu yazılır. Slayttaki örnek ada göre arar; string karşılaştırması gerektirdiği için sicile göre aramadan bir adım daha karmaşıktır (ekrandan, 00:45:00):

```c
/* Finding an Element in the Linked List:
   There is no easy way to create a general-purpose find() function
   because you usually search for an element based on one of its data fields
   (e.g. person's name), which depends on the structure being used.
   To write a general-purpose find() function, you can use function pointers
   (will be studied later).
   The following function, based on the personalstat structure,
   searches for an element, whose name field matches with the given argument.*/
EMPLOYEE* find(char *name) {
    EMPLOYEE *p;
    for(p=head; p!= NULL; p=p->next)
        if(strcmp(p->name, name) == 0) // returns 0, if 2 strings are same
            return p;
    return NULL;
}
```

Bu kez dolaşma işaretçisi `NULL` olmadığı sürece ilerlenir ve döngü gövdesi yazılır. `strcmp` iki string'i karşılaştırır: hangisinin büyük olduğuna göre negatif ya da pozitif bir değer, eşitse 0 döndürür. `p`'nin gösterdiği düğümün `name` alanı parametre olarak gelen adla aynıysa bulunan düğüm döndürülür. Döngü bittiği halde eşleşme bulunmadıysa `NULL` döner. Bu yüzden `find`'ı çağıran yerde `NULL` dönüp dönmediği ayrıca denetlenmelidir.

Fonksiyonun adı belki `findByName` olmalıydı, çünkü bir de `findById` gibi fonksiyonlar yazılabilir. Farklı alanlara göre aramayı tek bir noktadan yapmanın yolu fonksiyon işaretçileridir; bu konu ileride çalışılacak. Hoca fonksiyon işaretçisinin de sihirli değnek olmadığını, yine her alan için ayrı karşılaştırma fonksiyonu yazıp uygun olanı işaret etmek gerektiğini söyledi.

### 8.6 Araya Eklemek

İki çalışanın arasına yeni bir çalışan eklemek için yeni elemanın nereye ekleneceği belirtilmelidir. `insert_after` fonksiyonu `p` ve `q` adlı iki işaretçi alır ve `p`'nin gösterdiği yapıyı `q`'nun gösterdiği yapının hemen arkasına ekler (ekrandan, 00:50:00):

```c
/* To insert an element in a linked list, you must specify
   where you want the new element inserted.
   The following function accepts 2 pointer arguments, p and q,
   and inserts the structure pointed by p,
   just after the structure pointed by q. */
void insert_after(EMPLOYEE *p, EMPLOYEE *q){
    // if p and q are same or NULL, or if p already follows q, report that:
    if(p==NULL || q==NULL || p==q || q->next == p){
            printf("insert_after(): Bad arguments \n");
            return;
    }
    p->next = q->next;
    q->next = p;
}
```

Hangisinin hangisinin arkasına ekleneceğini karıştırmamak için yorum satırı yazıldı; fonksiyonun adı `insert_p_after_q` gibi de olabilirdi. Hoca "bizim meslekte biraz şüpheci olmak gerekir" diyerek denetimleri açıkladı:

- `p` ya da `q` `NULL` olmamalıdır. `NULL`'un arkasına bir şey eklenemez; bir düğümün arkasına `NULL` eklenirse ve o düğüm listenin sonu değilse liste o noktadan koparılmış olur.
- `p` ile `q` aynı düğüm olmamalıdır. Bir düğüm kendi arkasına eklenirse liste dolaşılırken bütün dolaşma fonksiyonları sonsuz döngüye girer.
- `p` zaten `q`'nun arkasındaysa yapılacak bir şey yoktur.

Bu dört durumdan biri varsa tek bir hata mesajı yazılıp fonksiyondan çıkılır.

Hoca şekle yeni oluşturulmuş bir 50 düğümü çizdi (yeni olduğu için `next`'i `NULL`) ve onu 15 düğümünün arkasına eklemeyi gösterdi. Son durumda 15'in 50'yi, 50'nin de 73'ü göstermesi gerekir. Atama sırası çok önemlidir: en başta `q->next = p;` yazılırsa `q`'nun daha önce gösterdiği 73 düğümüne giden işaretçi kaybolur. Bu yüzden önce o adres saklanmalıdır:

1. `p->next = q->next;` ile 50 artık 73'ü gösterir.
2. `q->next = p;` ile 15 artık 50'yi gösterir.

> **Hocanın vurgusu:** Araya eklemede önce `p->next = q->next;`, sonra `q->next = p;` yazılmalıdır. Sıra ters olursa listenin geri kalanına giden bağlantı kaybolur.

### 8.7 Örnek main Fonksiyonu

Slayttaki örnek `main` iki `EMPLOYEE` işaretçisi ve bir geçici değişken kullanır. Önce iki eleman eklenir: `create_list_element`'in oluşturduğu düğüm doğrudan `add_element`'e verilir. Listenin durumu ekrana yazdırılır. Sonra üçüncü eleman oluşturulup birinci ile ikinci elemanın arasına eklenir (ekrandan, 00:55:00):

```c
// CREATE A NEW ELEMENT AND INSERT IT IN
// BETWEEN THE 1st AND 2nd ELEMENTS IN THE LIST:
p=create_list_element();

q=head; //to keep the first element, head
insert_after(p, q); //and we insert p, after q:

printList( );

return 0;
```

Yeni eleman baş düğümün hemen arkasına ekleneceği için `p`'yi `q`'nun arkasına koymadan önce `q=head;` yapılır. `head` doğrudan fonksiyona verilmez: `insert_after` düzgün düşünülmüş bir fonksiyon olsa da ileride değiştirilip yanlış yapılmayacağının garantisi yoktur. Listenin ilk düğümü, "ipin ucu", çok sıkı ve kıskanç bir biçimde korunur.

## 9. Canlı Kodlama: Listeyi Denemek

Aradan sonra kod Dev-C++ ortamında çalıştırıldı. Kolaylık için `head` global değişken olarak tanımlandı. Hoca daha doğru yolun `head`'i `main` içinde tanımlayıp diğer fonksiyonlara parametre olarak vermek olduğunu söyledi, ama o ana kadar görülen kodun çalıştığını görmek için böyle devam edildi. Editördeki `main` şu biçimdeydi (ekrandan, 01:10:00):

```c
EMPLOYEE *p,*q;
int val, j;
for(j=0; j<2; j++)
    add_element( create_list_element());

for(j=0, p=head; p != NULL; p=p->next, j++)
{
    printf("%d-th person: ",(j+1)); printElementP(p);
}
// CREATE A NEW ELEMENT AND INSERT IT IN
// BETWEEN THE 1st AND 2nd ELEMENTS IN THE LIST:
p=create_list_element();

q=head; //to keep the first element, head
insert_after(p, q); //and we insert p, after q:
printList( );

system("pause"); return 0;
```

İki çalışan girildi, sonra üçüncü çalışan oluşturulup ikisinin arasına eklendi. Son listede ilk girilen kişi birinci, araya eklenen kişi ikinci, daha önce ikinci olan kişi üçüncü sırada çıktı; sicil numaraları ve maaşlar doğru aktarıldı.

### 9.1 Arama Denemesi

Sonra `find` denendi. Aranacak ad için bir string gerekir; bunun için `malloc` ile yer ayrıldı ve program sonunda `free` edildi. Önce tek bir arama yazıldı, ardından aramanın baş, orta ve son elemanda denenmesi için döngüye alındı (ekrandan, 01:15:00 ve 01:20:00):

```c
n = (char*) malloc(20*sizeof(char));
if( n == NULL ) {
    printf("Out of memory"); exit(1);
}

for(j=0; j<3; j++) {
    printf("Enter name to be searched: "); scanf("%s",n);
    p = find(n);
    if(p!=NULL) printElementP(p);
    else        printf("Not Found\n");
}

free(n);
system("pause"); return 0;
```

İlk denemede `find` sonucu doğrudan yazdırıldı; olmayan bir ad girilince `NULL` dönebileceği düşünülerek `if`/`else` ile "Not Found" mesajı eklendi. Ad küçük harfle başlatılarak yazılınca bulunamadı: `strcmp` büyük-küçük harfe duyarlıdır, bu yüzden ad listeye nasıl girildiyse öyle aranmalıdır. Program "patlamadan" bulunamadığını düzgün biçimde söyledi. Üçlü döngüde baştaki, ortadaki ve sondaki eleman bulundu.

> **Hocanın vurgusu:** Kapsamlı test için listenin başından, sonundan ve ortasından birer eleman aranır; olmayan bir eleman da denenir. Silme de baş, orta ve son düğüm için ayrı ayrı denenmelidir.

### 9.2 Silme Denemesi

Sonra silme denendi. Silme fonksiyonu düğüm (işaretçi) aldığı için önce `find` ile silinecek kişi bulundu, `NULL` değilse silindi, ardından liste yeniden yazdırıldı. Silinen kişi son listede görünmedi. Orta düğüm, son düğüm ve ilk düğüm silmeleri ayrı ayrı denendi ve üçü de düzgün çalıştı. Sona ekleme (`add_element`) zaten ilk iki elemanı eklerken denenmişti.

### 9.3 Liste İçin Ayrıca malloc Gerekir mi?

Hoca, programda yalnız aranacak string için `malloc` ile yer ayrıldığını hatırlatıp liste için ayrıca yer ayırmak gerekip gerekmediğini sordu. Cevap: kesinlikle gerekmez. Listeye düğüm düğüm eleman oluşturulup eklenir; yeni düğüm bellekte nerede oluşursa oluşsun mevcut son düğümün arkasına bağlanabilir. Bu yüzden yalnız düğümler için `malloc` gerekir, listenin tamamı için değil.

### 9.4 printList'in while ile Yazılması

`printList` fonksiyonu `while` döngüsüyle de yazıldı: önce dolaşma işaretçisi `p = head` yapılır ve sayaç sıfırlanır; `p` `NULL` olmadığı sürece kişi yazdırılır, `p = p->next` ile ilerlenir ve sayaç artırılır. Liste eksiksiz ve fazlasız yazdırıldı.

<!-- BELİRSİZ: while sürümünün editördeki hali karelerde yok; yapı altyazıdan aktarıldı. -->

## 10. Listeyi Bellekten Silmek ve Özyinelemeye Giriş

Düğümler için yer ayrıldığına göre program biterken listedeki bütün elemanları tek tek `free` etmek en doğrusudur. Bunun için ayrı bir fonksiyon yazıldı. Liste tek hamlede silinemez, düğümler tek tek silinir. Ancak silmeye baştan başlanamaz: ilk düğüm silinirse onun gösterdiği sonraki düğüm kaybolur. Aslında son düğümden başlayıp hep bir öncekine doğru silmek gerekir; ama liste tek yönlü olduğu için geriye doğru gidilemez. Çözüm özyinelemedir (recursion).

### 10.1 Özyineleme

Bir fonksiyonun kendisini çağırmasına özyineleme denir. Bu kendini çağırma sonsuza kadar sürmemelidir. Bir fonksiyondan başka bir fonksiyon çağrıldığında yeni fonksiyon için yeni bir bağlam alanı oluşturulup yığına atılır, fonksiyon bitince yığından çekilir. Fonksiyon durmadan kendini çağırırsa yığın belleği dolar ve uygulama beklenmedik biçimde sonlanır. Bu yüzden özyinelemede çıkış koşulu iyi düşünülmelidir.

> **Ders sonrası not:** Altyazıda bu bağlam alanı için "heap memory" sözcüğü geçiyor, hemen ardından "yığına atılıyor" deniyor. Fonksiyon çağrılarının bağlam alanları (yerel değişkenler, dönüş adresi) heap'te değil, yığın (stack) bölgesinde tutulur; dinamik olarak `malloc` ile ayrılan alan ise heap'tedir. Altyazıdaki ifade büyük olasılıkla Whisper hatası ya da dil sürçmesidir.

### 10.2 freeList

Çıkış koşulu şudur: son düğüme gelindiyse (`n->next == NULL`) o düğüm silinir ve dönülür. Değilse fonksiyon kendini `n->next` ile çağırır. Hoca bunun sonsuza kadar gitmeyeceğini, `n->next`'in `NULL` olduğu yerde duracağını gösterdi. Karede kodun ilk hali görünüyor (ekrandan, 01:35:00):

```c
void freeList( EMPLOYEE *n ) {
    if( n->next==NULL ) {
        free(n); return;
    }
    else {
        freeList( n->next );
    }
}
```

Hoca ardından çağrı zincirini geriye doğru izledi: en son çağrı son düğümü silip döner, bir önceki çağrıya gelinir. Bu çağrının düğümünün sonrası silinmiştir, ama kendisi hâlâ bellektedir. Hoca "kendisinden sonrasının silinmesini sağladıktan sonra kendisinin de silinmesi lazım" diyerek `else` dalında özyinelemeli çağrının ardından `free(n)` yapılması gerektiğini belirtti. Tamamlanmış hali:

```c
void freeList(EMPLOYEE *n) {
    if (n->next == NULL) { free(n); return; }
    else { freeList(n->next); free(n); }
}
```

<!-- BELİRSİZ: free(n) eklenmiş son hal karelerde görünmüyor; altyazıdaki anlatıma göre tamamlandı. -->

Hoca, zaten var olan silme fonksiyonunun burada kullanılmadığını da açıkladı: o fonksiyon silinecek düğümün bir öncesini bulmak için her seferinde listeyi baştan dolaşır, bu yüzden bütün listeyi silmek için verimsiz olur. Ders sonunda `freeList` çağrısıyla program çalıştırıldı; Dev-C++'ta konsol penceresinin beklenenden hızlı kapanmasının nedeni derste çözülmedi ve sonraya bırakıldı.

> **Ek bilgi (derste anlatılmadı):** Bu `freeList` boş listeyle (`n == NULL`) çağrılırsa `n->next` okunurken program çöker; çağırmadan önce `head != NULL` denetlenmeli ya da fonksiyonun başına `if (n == NULL) return;` eklenmelidir. Silmeden sonra `head = NULL;` yapmak, serbest bırakılmış belleğe yanlışlıkla erişilmesini önler. Ayrıca özyineleme olmadan da silinebilir: sıradaki düğümün adresi önce bir geçici işaretçide saklanır, sonra baştaki düğüm silinir; bu döngü listenin uzunluğundan bağımsız olarak yığını büyütmez.

## 11. Fonksiyonların Birleştirildiği Tam Program

Derste kullanılan dosyanın tamamı karelerde görünmediği için aşağıdaki program, slaytlardaki ve ekrandaki fonksiyon parçalarının birleştirilmesiyle kuruldu. Silme fonksiyonu altyazıdaki anlatımdan kuruldu, `freeList` anlatıldığı gibi tamamlandı, `main` sonunda ekrandaki arama döngüsüne bir silme adımı eklendi ve `system("pause")` taşınabilirlik için çıkarıldı. Program `gcc -Wall` ile uyarısız derlendi ve şu girdiyle denendi: üç çalışan (ikincisi araya eklenecek biçimde), ardından üç aranacak ad (var olan ve olmayan adlarla) ve silinecek bir ad; silme ayrı çalıştırmalarda baş, orta ve son düğüm için denendi. Ekleme, araya ekleme, arama ("Not Found" dahil) ve baş, orta, son düğüm silmeleri beklenen sonuçları verdi; AddressSanitizer ile bellek hatası ya da sızıntı görülmedi.

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct employee {
    char name[20];
    int ID;
    float salary;
    struct employee *next;
} EMPLOYEE;

EMPLOYEE *head = NULL;

void printElementP(EMPLOYEE *emp) {
    printf("Employee %d %s has a salary of %f\n",
           emp->ID, emp->name, emp->salary);
}

void printList() {
    int j; EMPLOYEE *p;
    for (j = 0, p = head; p != NULL; p = p->next, j++)
        printf("%d-th person: %d\t%s\t%f\n",
               j + 1, p->ID, p->name, p->salary);
}

EMPLOYEE *create_list_element() {
    EMPLOYEE *emp; int i; float s;
    emp = (EMPLOYEE *) malloc(sizeof(EMPLOYEE));
    if (emp == NULL) {
        printf("create_employee: out of memory."); exit(1);
    }
    printf("Enter name of the person: "); scanf("%s", emp->name);
    printf("Enter ID of the person: ");
    scanf("%d", &i); emp->ID = i;
    printf("Enter salary of the person: ");
    scanf("%f", &s); emp->salary = s;
    emp->next = NULL; return emp;
}

void add_element(EMPLOYEE *e) {
    EMPLOYEE *p;
    if (head == NULL) { head = e; return; }
    for (p = head; p->next != NULL; p = p->next); /* null statement */
    p->next = e;
}

void delete_element(EMPLOYEE *goner) {
    EMPLOYEE *p;
    if (goner == head) {
        head = goner->next;
    } else {
        for (p = head; p != NULL && p->next != goner; p = p->next);
        if (p == NULL) { printf("delete_element(): not found\n"); return; }
        p->next = goner->next;
    }
    free(goner);
}

EMPLOYEE *find(char *name) {
    EMPLOYEE *p;
    for (p = head; p != NULL; p = p->next)
        if (strcmp(p->name, name) == 0)
            return p;
    return NULL;
}

void insert_after(EMPLOYEE *p, EMPLOYEE *q) {
    if (p == NULL || q == NULL || p == q || q->next == p) {
        printf("insert_after(): Bad arguments \n");
        return;
    }
    p->next = q->next;
    q->next = p;
}

void freeList(EMPLOYEE *n) {
    if (n->next == NULL) { free(n); return; }
    else { freeList(n->next); free(n); }
}

int main(void) {
    EMPLOYEE *p, *q; char *n; int j;
    for (j = 0; j < 2; j++)
        add_element(create_list_element());
    for (j = 0, p = head; p != NULL; p = p->next, j++) {
        printf("%d-th person: ", (j + 1)); printElementP(p);
    }
    p = create_list_element();
    q = head;
    insert_after(p, q);
    printList();

    n = (char *) malloc(20 * sizeof(char));
    if (n == NULL) { printf("Out of memory"); exit(1); }
    for (j = 0; j < 3; j++) {
        printf("Enter name to be searched: "); scanf("%s", n);
        p = find(n);
        if (p != NULL) printElementP(p);
        else printf("Not Found\n");
    }
    printf("Enter name to be deleted: "); scanf("%s", n);
    p = find(n);
    if (p != NULL) delete_element(p);
    printList();
    free(n);
    if (head != NULL) freeList(head);
    head = NULL;
    return 0;
}
```

Örnek çalıştırmada girdi sırası "Ali 111 1000", "Veli 333 3000", araya eklenen "Ayse 222 2000" olduğunda (adlar ajanın deneme verisidir) araya eklemeden sonraki liste şöyle çıktı:

```text
1-th person: 111	Ali	1000.000000
2-th person: 222	Ayse	2000.000000
3-th person: 333	Veli	3000.000000
```

Arama girdileri "Ali", "ali" ve "Veli" için sonuçlar sırasıyla bulundu, "Not Found" ve bulundu oldu; "Ali" silindikten sonra liste 222 ve 333 numaralı iki kişiden oluştu.

## Örnek Sorular

### Soru 1: Düğüm yapısının ikinci seçeneğiyle bağlı liste (ekrandan, 00:20:00)

Slaytta verinin (`EMPLOYEE`) ve düğümün (`EMP_NODE`, içinde `EMPLOYEE data;` ve `struct emp_node *next;`) ayrı tanımlandığı ikinci seçenek "Left to students as an exercise" notuyla alıştırma olarak bırakıldı. Bu tanımla listenin sonuna ekleme, listeyi yazdırma, sicile göre arama ve listeyi silme fonksiyonlarını yazın.

> **Çözüm (derste verilmedi):** Aşağıdaki çözüm ajan tarafından yazıldı, `gcc -Wall` ile derlendi ve üç çalışanlık bir girdiyle denendi (liste doğru sırada yazıldı, 222 sicilli çalışan bulundu, AddressSanitizer bellek hatası ya da sızıntı göstermedi). Farklar: düğüm `EMP_NODE` türündedir, veri alanlarına `p->data.ID` biçiminde (ok, sonra nokta) erişilir ve `EMPLOYEE` struct'ı düğüme atama ile kopyalanır.

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[20];
    int ID;
    float salary;
} EMPLOYEE;

typedef struct emp_node {
    EMPLOYEE data;
    struct emp_node *next;
} EMP_NODE;

EMP_NODE *head = NULL;

void add_element(EMPLOYEE e) {
    EMP_NODE *yeni, *p;
    yeni = (EMP_NODE *) malloc(sizeof(EMP_NODE));
    if (yeni == NULL) { printf("Out of memory"); exit(1); }
    yeni->data = e;          /* struct atamasi: alanlar kopyalanir */
    yeni->next = NULL;
    if (head == NULL) { head = yeni; return; }
    for (p = head; p->next != NULL; p = p->next);
    p->next = yeni;
}

EMP_NODE *find_by_id(int id) {
    EMP_NODE *p;
    for (p = head; p != NULL; p = p->next)
        if (p->data.ID == id) return p;
    return NULL;
}

void printList(void) {
    EMP_NODE *p; int j;
    for (j = 0, p = head; p != NULL; p = p->next, j++)
        printf("%d-th person: %d\t%s\t%f\n", j + 1,
               p->data.ID, p->data.name, p->data.salary);
}

void freeList(void) {
    EMP_NODE *p;
    while (head != NULL) { p = head; head = head->next; free(p); }
}

int main(void) {
    EMPLOYEE e;
    int j;
    for (j = 0; j < 3; j++) {
        printf("Enter name, ID, salary: ");
        if (scanf("%19s %d %f", e.name, &e.ID, &e.salary) != 3) return 1;
        add_element(e);
    }
    printList();
    printf("%s\n", find_by_id(222) ? "222 found" : "222 not found");
    freeList();
    return 0;
}
```

### Soru 2: Sona eklemede döngü koşulu (derste sözlü, 00:37:41)

`add_element` içindeki döngü neden `p != NULL` değil de `p->next != NULL` koşuluyla yazılır?

**Cevap:** Döngü `p` `NULL` olana kadar sürerse `p` son düğümü geçer ve `NULL` olur; yeni düğümü bağlayacak bir düğüm kalmaz. Yeni düğümü bağlamak için eski son düğümün `next` işaretçisinin değiştirilmesi gerekir. `p->next != NULL` koşuluyla döngü `p` son düğümdeyken durur ve `p->next = e;` yapılabilir.

### Soru 3: Araya eklemede atama sırası (derste sözlü, 00:51:50)

Slayttaki listede yeni 50 düğümü 15 düğümünün arkasına eklenecek. `insert_after(p, q)` içinde önce `q->next = p;` yazılırsa ne olur?

**Cevap:** `q`'nun (15) eski sonraki düğümüne (73) giden tek işaretçi kaybolur; listenin geri kalanına artık ulaşılamaz. Doğru sıra önce `p->next = q->next;` (50, 73'ü gösterir), sonra `q->next = p;` (15, 50'yi gösterir) şeklindedir.

### Soru 4: Liste için ayrıca malloc gerekir mi? (derste sözlü, 01:22:41)

Programda yalnız aranacak string için `malloc` ile yer ayrıldı. Liste için ayrıca `malloc` ile yer ayırmak gerekmez miydi?

**Cevap:** Gerekmez. Listeye düğüm düğüm eleman oluşturulup eklenir ve her düğüm `create_list_element` içinde kendi `malloc`'uyla oluşturulur. Yeni düğüm bellekte nerede olursa olsun son düğümün arkasına bağlanabilir. Listenin tamamı için toplu bir alan gerekmez.

### Soru 5: Tek yönlü listeyi silmek (derste sözlü, 01:27:33)

Bütün listeyi bellekten silerken neden ilk düğümden başlanamaz ve bu nasıl çözülür?

**Cevap:** İlk düğüm silinirse onun `next` işaretçisi de gider ve sonraki düğümlere ulaşılamaz. Sondan başa doğru silmek gerekir, ama tek yönlü listede geriye gidilemez. Çözüm özyinelemedir: `freeList(n)` önce `freeList(n->next)` ile kendisinden sonrasını sildirir, sonra `free(n)` ile kendini siler; son düğümde (`n->next == NULL`) yalnız kendini silip döner.

## Dersin Toparlaması

Bu derste farklı türdeki verileri tek bir türde toplayan `struct` yapısı, `typedef` ile tür adı verme, nokta ve ok işleçleri, iç içe yapılar ve struct işaretçileri tekrar edildi. Ardından dizilerin sabit boyut ve araya ekleme-silme zorlukları yüzünden bağlı liste veri yapısı tanıtıldı: veri ve `next` işaretçisinden oluşan düğümler, `NULL` ile biten liste ve asla kaybedilmemesi gereken baş işaretçisi. Düğüm yapısı için `next`'in verinin içine konduğu ve veriyle düğümün ayrıldığı iki seçenek karşılaştırıldı; derste ilki kullanıldı.

Liste üzerinde yazdırma, yeni düğüm oluşturma, sona ekleme, silme, ada göre arama ve araya ekleme fonksiyonları slaytlardan anlatıldı, sonra canlı kodlamayla baş, orta ve son düğüm üzerinde denendi. Ders, bütün listeyi özyinelemeli olarak bellekten silen `freeList` fonksiyonuyla ve özyinelemeye kısa bir girişle bitti. Genel amaçlı arama için fonksiyon işaretçileri ve özyineleme konularının ileride ayrıntılı işleneceği söylendi; bir sonraki uygulamada da aynı konular üzerinde çalışılacak.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
