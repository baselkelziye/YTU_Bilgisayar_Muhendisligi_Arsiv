# Ders 10 Genişletilmiş Notu: Main Fonksiyonu Parametreleri, Yapılar (struct), Bağlı Liste ve Bit Alanları

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. `main` fonksiyonunun parametreleri
- 2. Yapı (`struct`) tanımı
- 3. Yapı alanlarına erişim ve iç içe yapılar
- 4. Yapıların fonksiyonlara aktarılması
- 5. Bağlı liste kavramı
- 6. Çalışan listesinin C ile gerçeklenmesi
- 7. Yapı hizalama (structure alignment)
- 8. Bit alanları (bit fields)
- Örnek Sorular
- Dersin Toparlaması

## 1. `main` fonksiyonunun parametreleri

Ders, önceki derste görülen karakter işaretçileri dizisiyle doğrudan bağlantılı bir konuyla başladı: `main` fonksiyonuna parametre aktarmak. `main` fonksiyonunun uzun imzası şöyledir:

```c
int main(int argc, char *argv[])
```

Birinci parametre `argc` (argument count) programa verilen argüman sayısıdır. İkinci parametre `argv` (argument vector) ise her biri ayrı bir metin satırı olan argümanları tutar. Her argüman bir karakter dizisi olduğundan en uygun gösterim karakter işaretçileri dizisidir. Bu yapı iki boyutlu bir metin dizisi gibi düşünülebilir. Her satırın nerede bittiği sondaki `'\0'` (null) karakterinden anlaşılır, ama kaç satır olduğu bu yolla anlaşılamaz. Satır sayısını bildiren `argc` bu yüzden gereklidir.

### 1.1 Parametreler ne işe yarar?

Hoca bunu bir web tarayıcısı örneğiyle anlattı. Bir eklenti yüzünden tarayıcı açılır açılmaz çöküyorsa, kısayolun hedefinde programın yolu ve adından sonra boşluk bırakılıp `-safe-mode` gibi bir parametre yazılabilir. Program o zaman güvenli modda açılır. Tire ile başlayan parametreler yaygın bir tercihtir. Programın içinde `main` önce `argc`'ye bakar; sıfırdan farklı bir sayı varsa parametreleri bir `for` ya da `while` döngüsünde tek tek kontrol eder. Bir parametrenin metni `-safe-mode` ise program kendini güvenli modda başlatır. Yani `main`'in başında bir döngü ve `if-else` yapısı kurulur.

Parametrelerin her biri programın mantığına göre ayrı bir anlam taşıyabilir: "güvenli modda çalış", "ilk girdi şu olsun", "ikinci kez girdi isteme" gibi. Birbirinin alternatifi olmaları, yani hep aynı `if-else` zincirinin kolları olmaları gerekmez. Bu tamamen uygulamanın tasarımına bağlıdır.

### 1.2 Derste çalıştırılan örnek

Slayttaki örnek kod `argc`'yi döngünün her adımında önce azaltıp sonra kullanıyordu ("önce azalt, sonra kullan"). Döngü `argc` sıfırdan büyük olduğu sürece sıradaki parametreyi yazdırıyordu; böylece ilk parametre atlanıyordu. İlk parametre çalıştırılabilir dosyanın kendi adıdır. <!-- BELİRSİZ: argv örneğinin slayttaki kod satırları karelerde görünmüyor; aşağıdaki biçim altyazıdaki anlatımdan kurulmuştur. -->

Program parametre alabilmesi için IDE'den değil komut satırından çalıştırıldı. Çıktı karesi şöyledir (ekrandan, 00:15:00):

```text
C:\DevCpp4\kod>Hafta07p birinci ikinci ucuncu
birinci
ikinci
ucuncu

C:\DevCpp4\kod>Hafta07p birinci ikinci ucuncu
Hafta07p
birinci
ikinci
ucuncu
```

İlk çalıştırma slayttaki koddan, son çalıştırma ise döngünün sıfırdan başlayan düz bir `for` döngüsüyle yeniden yazılmış hâlinden gelir. Hoca döngüde `argc`'nin değerini bozmamak için ayrı bir sayaç kullandı. İşaretçi gösterimiyle erişirken parantezlerin doğru konması gerektiğini, bunun önceki derslerde konuşulduğunu hatırlattı. Sıfırıncı satırda programın adı göründü. Program adını bilmek çoğu zaman gerekmez, bu yüzden ders notundaki kodlar onu atlar.

Aşağıdaki kod iki biçimi birlikte gösterir. Derste ekranda görülmedi; ajan tarafından anlatımdan kuruldu ve `gcc -Wall` ile derlenip `birinci ikinci ucuncu` parametreleriyle çalıştırıldı:

```c
#include <stdio.h>
int main(int argc, char *argv[]) {
    int i;
    for (i = 0; i < argc; i++)        /* argv[0] dahil hepsi */
        printf("%s\n", *(argv + i));
    while (--argc > 0)                 /* önce azalt, sonra kullan */
        printf("%s\n", *++argv);       /* argv[0] atlanır */
    return 0;
}
```

> **Hocanın vurgusu:** Çalıştırılabilir dosyanın parametrelerine erişme mantığını bilmek gerekir; bu bilgi daha önce bir sınavda da sorulmuştu. Parametreleri daha kolay işlemenin Linux türevlerine özgü bir yolu var, ama o ders kapsamı dışında bırakıldı.

> **Ek bilgi (derste anlatılmadı):** Hocanın sözünü ettiği Linux yolu büyük olasılıkla POSIX `getopt` fonksiyonudur. Bu fonksiyon `-a`, `-b deger` gibi seçenekleri `argv` içinden sırayla ayrıştırır.

## 2. Yapı (`struct`) tanımı

Şimdiye kadar `int`, `char`, `float` gibi ilkel türler kullanıldı. Ama problem alanındaki varlıklar tek bir veriyle ifade edilmez. Bir öğrencinin numarası, adı ve dersleri vardır; bir çalışanın adı, soyadı, kimlik numarası ve maaşı vardır. Bunlar dizilerle tutulmak istenirse her alan için ayrı bir tek boyutlu dizi gerekir (ekrandan, 00:20:00):

```c
char names[1000][20], surnames[1000][20];
int  IDs[1000]; float salaries[1000];
```

Ad ve soyad tek bir değer değil, en fazla 20 karakterlik metinler olduğu için iki boyutlu dizi olmak zorundadır. C'de hazır bir `string` türü olsaydı `string names[1000]` yazılabilirdi. Bu düzende farklı dizilerin aynı indisteki elemanları aynı çalışana aittir. Hoca bunun mantıklı olmadığını, angarya olduğunu söyledi. İhtiyaç, aynı varlığa ait verileri bir araya getiren bir kayıt yapısıdır. Yapılar (struct) bu işi yapar.

### 2.1 `struct` anahtar kelimesiyle tanım

Tanım `struct` anahtar kelimesiyle başlar, yapıya bir ad verilir (örneğin `employee`), süslü parantez içinde alanlar yazılır ve sonuna noktalı virgül konur. Alanlar: 20 karakterlik `name`, 20 karakterlik `surname`, `int` türünde `id` ve `float` türünde `salary`. Bu tanımla adı `struct employee` olan yeni bir veri türü oluşur. Türün adı yalnız `employee` değil, `struct employee`'dir. `int` C'de hazır gelen bir türdür; burada ise C'ye yeni bir tür kazandırılmış olur. 1000 çalışanlık dizi bu türle tanımlanabilir.

### 2.2 `typedef` ile tanım

Her yerde `struct employee` yazmak zahmetlidir. Bunun için `typedef` (type definition) kullanılır (ekrandan, 00:25:00):

```c
typedef struct {
    char name[20], surname [20];
    int  ID;
    float salary;
} EMPLOYEE ;

EMPLOYEE employees[1000];
```

Burada `struct` kelimesinden sonra bir ad yazılmadığı için yapı adsızdır (anonymous). Bu adsız yapıya `typedef` ile `EMPLOYEE` adı verilir. İstenirse `struct`'tan sonra da bir ad yazılabilir. Ama doğrudan kullanılacak `EMPLOYEE` adı verildiği için geçici bir ada gerek yoktur. Artık `EMPLOYEE` bütün yapı tanımını, `struct` kelimesi dahil, temsil eder.

> **Hocanın vurgusu:** `typedef` ile tanımlanan yapı adlarını tamamen büyük harfle yazmak bir gelenektir. Kodda büyük harfli bir tür görüldüğünde bunun bir yapı olduğu hemen anlaşılır. Bu geleneğe uyulması istendi.

## 3. Yapı alanlarına erişim ve iç içe yapılar

### 3.1 Nokta ve ok operatörleri

Yapı türünden tek bir değişken ya da dizi elemanı tanımlandıysa alanlara nokta (`.`) operatörüyle erişilir. Örneğin `EMPLOYEE` türünden `calisan` adlı bir değişkenin kimliği `calisan.ID = 5;` biçiminde değiştirilir.

Tanımlanan şey bir işaretçiyse, örneğin `EMPLOYEE *eptr;` (employee pointer kısaltması), ok operatörü (`->`) kullanılır: `eptr->ID = 5;`. Ok operatörü bir tire ve bir büyüktür işaretinden oluşur ve tek bir operatör olarak algılanır.

Arka planda `eptr->ID` ile `(*eptr).ID` aynıdır. İşaretçinin gösterdiği değeri kullanmak için başa `*` konur. Ama `*` ile `.` operatörlerinin öncelikleri karışır; bu yüzden önce parantezle işaretçi çözülür, sonra nokta ile alana erişilir. Hoca parantezli biçimi ezberlemeye gerek olmadığını, ok operatörünün çok daha rahat bir yazım olduğunu söyledi.

### 3.2 İç içe yapılar

Bir yapının içinde başka bir yapı türünden alan tanımlanabilir. C'nin "kullanmadan önce tanımla" kuralı gereği içteki yapı daha önce tanımlanmış olmalıdır.

Örnek olarak çalışan kaydına işe alınma tarihi eklenmek istendi. Tarih gün, ay ve yıldan oluşan üç tam sayıdır. Bunlar çalışan yapısına üç ayrı alan olarak eklenebilir, ama bu eksik bir tasarım olur. Gün, ay ve yıl ancak birlikte anlamlıdır ve tarihi bütün olarak işleyen ayrı fonksiyonlar yazılacaktır. Bu yüzden tarih için ayrı bir yapı tanımlanır. Gün ve ay büyük sayılar olmadığı için bellekten tasarruf amacıyla `short` seçildi (ekrandan, 00:30:00):

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

Erişim her düzeyde bir nokta daha eklenerek yapılır: `calisan.enlisted.year = <yıl>;`. Değişken bir işaretçiyse yalnız en dıştaki erişim ok olur: `ptr->enlisted.year`. Çünkü `enlisted` alanının kendisi işaretçi değildir.

## 4. Yapıların fonksiyonlara aktarılması

Yapılar fonksiyonlara değerle (call by value) ya da adresle (call by reference) aktarılır; mantık önceki derslerde görülenle aynıdır.

- `printReport` gibi bir raporlama fonksiyonu yalnız okuma yapar. Ona `EMPLOYEE` değerle verilebilir. Fonksiyonun içinde yapılan bir değişiklik kalıcı olmaz.
- `increaseSalary` gibi maaşa zam yapan bir fonksiyonda değişikliğin kalıcı olması gerekir. Bu durumda yapının adresi gönderilir, parametre `EMPLOYEE *` türünde tanımlanır ve fonksiyonda ok operatörüyle `emp->salary += 3000;` gibi bir işlem yapılır.

Yapıyı gösteren bir işaretçi yapının bütün alanlarını birlikte gösterir. `++` gibi operatörlerle kullanıldığında bir yapı dizisinde sıradaki yapıya geçer; yapının kendi alanları arasında ilerlemek diye bir şey yoktur.

## 5. Bağlı liste kavramı

Yapıların kullanımı bağlı liste (linked list) veri yapısı gerçeklenerek gösterildi. Hoca ayrıntıların veri yapıları dersinde görüleceğini, bu derste yalnız ilk tanışmanın yapılacağını söyledi.

### 5.1 Neden bağlı liste?

Diziler yeterince verimli değildir. Boyutları kendiliğinden büyüyüp küçülmez, bu yüzden en kalabalık senaryoya göre yer ayırmak gerekir ve bu bellek israfıdır. Dinamik bellek yönetimiyle ayrılan alanlarda bile araya eleman yerleştirmek ya da aradan eleman silmek zordur. Aradaki bir eleman silinince sağındaki bütün elemanlar bir adım sola kaydırılmalıdır, çünkü o hücre boş kalamaz. Bağlı liste bu sorunları çözmek için ortaya çıkmıştır. Hoca listeyi tespih tanelerine benzetti; kaynak kitapta da birbirine iple bağlı sosisler örneği verilir.

### 5.2 Yapısı

Slayttaki örnek tam sayı tutan bir listedir (ekrandan, 00:35:00):

```text
[49 | •] -> [15 | •] -> [73 | •] -> [87 | •] -> [10 | NULL]
  ^                                              ^
  Head node                                      Tail node
```

- Liste birbirine bağlı düğümlerden (node) oluşur; her düğüm bir yapı olarak modellenir.
- Düğümün ilk bileşeni veridir (burada bir tam sayı), ikincisi listedeki bir sonraki düğümü gösteren işaretçidir.
- İşaretçi aslında düğümün içindeki sayıyı değil, düğümün bütününü gösterir. Hoca okun düğümün kenarına çizilmesinin daha doğru olacağını belirtti.
- Son düğümün sonraki işaretçisi `NULL`'dur; listenin bittiği buradan anlaşılır.
- İlk düğüme baş düğüm (head node) denir ve her zaman saklanmalıdır. İpin ucu bir kez kaçırılırsa listeye geri dönmenin yolu yoktur.
- Son düğüme kuyruk düğümü (tail node) denir. Onu saklamak zorunlu değildir, çünkü baştan başlayıp `next`'i `NULL` olan düğüme kadar gidilerek bulunur. Ama ekleme genelde sona yapıldığı için kuyruğu gösteren bir işaretçi tutmak işi hızlandırır.

### 5.3 Sona ekleme

Listeyi yeniden boyutlandırmaya gerek yoktur. `malloc` (ya da `calloc`) ile tek bir düğüm oluşturulur ve değeri yazılır (tahtada 3). Sona eklendiği için yeni düğümün `next`'i `NULL` yapılır. Mevcut kuyruğun (10) `next`'i yeni düğümü gösterecek şekilde güncellenir ve kuyruk işaretçisi yeni düğüme kaydırılır (ekrandan, 00:40:00).

### 5.4 Araya ekleme

Tahtada 87 ile 10 arasına değeri 4 olan yeni bir düğüm eklendi (ekrandan, 00:45:00). Önce eklenecek yerdeki düğüme (87) gelinir ve yeni düğüm `malloc` ile oluşturulur. Burada işlem sırası kritiktir. İlk iş olarak 87'nin `next`'i yeni düğüme yönlendirilirse 10'u gösteren bağ kaybolur. 10'u gösteren başka işaretçi kalmaz ve listenin geri kalanına ulaşılamaz. Doğru sıra şöyledir:

- 1. adım: yeni düğümün `next`'i, 87'nin `next`'inin gösterdiği yere (10) eşitlenir.
- 2. adım: 87'nin `next`'i yeni düğümü gösterir.

### 5.5 Aradan silme

Tahtada 73 silindi (ekrandan, 00:45:00). Silinecek düğüm bir işaretçide (`sil`) tutulur. Bu düğüm zaten bellekte olduğu için `malloc`'a gerek yoktur. Silinecek düğümden bir önceki düğüm (15) `p` işaretçisiyle bulunur. Bunun için ilk düğümden başlanır ve `p`'nin `next`'i silinecek düğüm olmadığı sürece `p` ilerletilir. Sonra `p->next = sil->next` yapılır; bağ silinen düğümün üzerinden atlar. En sonda `free(sil)` ile bellek geri verilir.

### 5.6 Dizi ile karşılaştırma

Bağlantılar dikkatle ve doğru sırayla güncellendiği sürece sona ekleme, araya ekleme ve aradan silme hızlı ve verimli yapılır. Listelerin tek dezavantajı doğrudan erişimdir. Dizide dördüncü elemana `dizi[3]` ile hemen ulaşılır (indisler 0'dan başladığı için bir eksiği). Listede ise baştan başlayıp o kadar kez `next` izlemek gerekir. Doğrudan erişim dışındaki bütün işlemlerde bağlı liste daha avantajlıdır. Hoca, ileride görülecek map ve tablo yapılarında aradaki bir elemana erişimin, sıralı dizide ikili aramadaki hıza yakın olacağını da ekledi.

## 6. Çalışan listesinin C ile gerçeklenmesi

### 6.1 Veri ile düğümü birleştirmek ya da ayırmak

Derste `EMPLOYEE` yapısı hem veri hem düğüm olarak kullanıldı; sonraki çalışanı gösteren işaretçi yapının içine kondu (ekrandan, 00:50:00):

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

Bu tanımda adsız yapı kullanılamaz. Yapı kendi türünden bir işaretçi alanı içerdiği için o türün adı yapının içinde kullanılabilmelidir. C her şeyin kullanılmadan önce tanımlanmasını ister; bu yüzden `struct Employee` adı yapının başında verilir. `typedef` sayesinde liste başını tutan `head` de `EMPLOYEE *` olarak tanımlanır.

Hoca aslında verinin kendisinin ve saklandığı veri yapısının iki ayrı kavram olduğunu belirtti. İyi bir tasarım, problem hangi düzeyde parçalanabiliyorsa o düzeyde parçalanan tasarımdır. Bu tanıma göre en doğrusu veriyi (`EMPLOYEE`) bir yapıda, düğümü (`EMPLOYEE_NODE`: bir `EMPLOYEE` alanı ve kendi türünden `next` işaretçisi) ayrı bir yapıda tanımlamaktır. Bu durumda erişim `head->data.ID` gibi biraz daha uzun olur. Veri yapıları dersinde ya da gerçek uygulamalarda böyle yapılabilir. Bu derste konu adım adım ilerlesin diye birleşik biçim kullanıldı. İsteyenler ders notlarındaki kodları ikinci biçime çevirerek ya da ilgi alanlarına göre kendi yapı ve listelerini tanımlayarak alıştırma yapabilir.

### 6.2 Yazdırma fonksiyonları

Fonksiyonlar parametre almadığı için baş işaretçisi global değişken olarak tutuldu. Baş işaretçisi `main` içinde tanımlansaydı fonksiyonlara parametre olarak verilmesi gerekirdi. Baş işaretçisi kaybedilmemesi gerektiği için dolaşmada ayrı bir işaretçi (`p`) kullanılır (ekrandan, 01:10:00; editörde `surname` alanı çıkarılmış hâli 01:20:00):

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

`for` başlığının ilk ve son bölümünde virgülle birden fazla komut verilebilir. Döngü başında `j` sıfırlanır ve `p` baş düğümü gösterir. Döngü `p` `NULL` olmadığı sürece sürer, her adımda `p` sıradaki düğüme geçer ve `j` bir artar. Hoca, sonlanma koşulu `j`'ye bağlı olmadığı için `j`'nin 1'den başlatılıp yazdırmadaki `+1`'in kaldırılabileceğini de söyledi.

`printList` içinde `printElementP` çağrılabilirdi. Hoca şöyle açıkladı: listenin tamamını yazarken kullanılan biçim tek elemanı gösterirken kullanılandan farklı olacaksa iki ayrı fonksiyon yazılabilir. Fark yoksa aynı kodu iki kez yazmanın anlamı yoktur. Burada biri döküm biçiminde, diğeri cümle biçiminde yazdığı için ayrı tutuldu. Fonksiyon elemanı değiştirmese de liste işaretçilerle kurulduğu için parametre işaretçi türündendir.

Biçim dizgesi derste önce `%f.2` yazıldı; çalıştırınca hatalı biçimlendirme görüldü ve `%.2f` olarak düzeltildi.

> **Ders sonrası not:** `%f.2` biçiminde `%f` sayıyı altı ondalık basamakla yazar, `.2` ise düz metin olarak arkasına eklenir (ör. `11000.000000.2`). Virgülden sonra iki basamak için doğru yazım `%.2f`'dir.

### 6.3 Yeni eleman oluşturma

Yeni bir çalışan için bellekte bir düğüm ayrılmalı ve geri döndürülmelidir. Fonksiyon parametre almadığı için yeni elemanın verileri kullanıcıdan sorulur (ekrandan, 01:15:00):

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

- `sizeof(EMPLOYEE)` yapının kaç bayt tuttuğunu verir; `malloc` o kadar baytlık alan ayırır, dönen adres `EMPLOYEE *`'a dönüştürülür.
- Bellek her zaman yetmeyebilir; bu yüzden `NULL` kontrolü yapılır ve bellek yoksa program hata koduyla çıkar.
- Ad alanı bir dizi olduğu için `scanf("%s", emp->name)` ile doğrudan okunabilir.
- Bazı platformlarda (işletim sistemi, işlemci ya da derleyici kaynaklı) yapının işaretçi olmayan ilkel alanlarını `scanf` ile doğrudan okumakta sorun yaşanabiliyor. Tedbir olarak değer önce yerel değişkene (`i`, `s`) okunur, sonra alana atanır.
- Yeni eleman sona ekleneceği için `next` `NULL` yapılır. Bu fonksiyon yalnız düğümü oluşturur, listeye eklemez.

> **Ders sonrası not:** `scanf("%s", emp->name)` genişlik sınırı vermez; 19 karakterden uzun bir ad 20 baytlık diziyi taşırır ve bu tanımsız davranıştır. Güvenli yazım `scanf("%19s", emp->name)`'dir. Ayrıca derste ekranda görülen dosyada yalnız `<stdio.h>` vardı. `malloc` ve `exit` için `<stdlib.h>`, `strcmp` için `<string.h>` eklenmelidir. Eski derleyiciler bildirimsiz kullanıma uyarıyla izin verir, ama C99 ve sonrasında bu bir hatadır.

### 6.4 Listeye ekleme

`add_element` eklenecek elemanı işaretçiyle alır ve dolaşma için bir işaretçi tanımlar. Liste henüz boşsa (`head == NULL`), gelen eleman artık baş düğümdür: `head = e;` yapılır ve fonksiyondan `return` ile çıkılır. Tek elemanın `next`'i zaten `NULL`'dur. Fonksiyon `void` olsa da `return` ile erken çıkmak tamamen kabul edilebilir.

Liste boş değilse son düğüm bulunur. `p` baştan başlatılır ve `next`'i `NULL` olmadığı sürece ilerletilir. Bütün iş `for` başlığında olduğu için döngünün gövdesi boştur; `for(...)`'un hemen arkasına noktalı virgül konur. Aynı şey `while` ile `p = p->next;` gövdesi yazılarak da yapılabilir. Döngüden çıkınca `p` son düğümdür ve `p->next = e;` ile ekleme tamamlanır. <!-- BELİRSİZ: add_element'in slayt kodu karelerde görünmüyor; aşağıdaki kod altyazıdaki anlatımdan kurulmuştur. -->

```c
void add_element( EMPLOYEE *e ) {
    EMPLOYEE *p;
    if( head == NULL ) { head = e; return; }
    for( p = head; p->next != NULL; p = p->next );
    p->next = e;
}
```

`main` içinde iki çalışan bir döngüyle oluşturulup listeye eklendi. `create_list_element()`'in döndürdüğü işaretçi doğrudan `add_element`'e verildi; çağrılar zincirleme kullanıldı. Sonra düğümler tek tek ve liste bütün olarak yazdırıldı (ekrandan, 01:50:00):

```c
for(j=0; j<2; j++)
    add_element( create_list_element() );

for(j=0, p=head; p != NULL; p=p->next, j++)
{
    printf("%d-th person: ",(j+1)); printElementP(p);
}
```

Hoca serbest bellek konusunu da hatırlattı. Program sonunda listeyi boşaltan bir fonksiyon (delete list / free list) yazmak gerekir; bu fonksiyon özyinelemeli de yazılabilirdi. Konu dersin sonunda ele alındı (bkz. 6.8).

### 6.5 Araya ekleme: `insert_after`

Araya eklemek için iki bilgi gerekir: hangi elemanın ardına eklenecek ve eklenecek yeni eleman ne. Bunlar `q` ve `p` işaretçileridir. Hangisinin hangisinin ardına eklendiği yalnız harflerden anlaşılmayabilir; bu yüzden ya bir yorum yazılmalı ya da parametrelere `newEmployee`, `after` gibi anlamlı adlar verilmelidir (ekrandan, 01:35:00):

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

Aksilik kontrolleri şunlardır: `p` ve `q` `NULL` olmamalı, ikisi aynı olmamalı ve `p` zaten `q`'dan hemen sonra gelmemelidir. Hoca daha ayrıntılı bir sürümde eklenecek elemanın önce listede aranabileceğini, yoksa eklenebileceğini de söyledi.

Hoca işlemi yeniden çizdi. `q` 3 değerli düğümü, 3'ün `next`'i 8 değerli düğümü, `p` ise yeni oluşturulan 6 değerli düğümü gösteriyor. İlk iş olarak `q->next = p` yazılırsa 8'i gösteren bağ kaybolur. Bu yüzden önce `p->next = q->next` (1. işlem), sonra `q->next = p` (2. işlem) yapılır. Böylece 6, 3'ten sonra yerleşir ve zincir kırılmaz.

Gösterimde listenin birinci ve ikinci elemanı arasına yeni bir eleman eklendi (ekrandan, 01:25:00):

```c
// CREATE A NEW ELEMENT AND INSERT IT IN
// BETWEEN THE 1st AND 2nd ELEMENTS IN THE LIST:
p=create_list_element();

q=head; //to keep the first element, head
insert_after(p, q); //and we insert p, after q:

printList( );
```

Çalıştırınca üçüncü eleman ilk ikisinin arasında listelendi.

### 6.6 Arama: `find`

Arama isme ya da kimliğe göre yapılabilir; parametre buna göre seçilir. Birden fazla alana göre arama gerekiyorsa C'de aynı adla birden çok fonksiyon yazılamadığı için `findByName`, `findById` gibi ayrı sürümler yazılır. Derste isme göre arama yazıldı (ekrandan, 01:45:00):

```c
EMPLOYEE* find(char *name) {
    EMPLOYEE *p;
    for(p=head; p!= NULL; p=p->next)
        if(strcmp(p->name, name) == 0) // returns 0, if 2 strings are same
            return p;
    return NULL;
}
```

`strcmp` iki dizgi aynıysa 0 döndürür; bu durumda bulunan düğüm döndürülür. Döngü bittiğinde bulunamamışsa `NULL` döner. `main`'de aranacak ad için 20 karakterlik bir alan `malloc` ile ayrıldı, `NULL` kontrolü yapıldı ve program sonunda `free(name)` çağrıldı. Hoca uzunluk için `#define` ile bir sabit tanımlamanın daha doğru olacağını söyledi (ekrandan, 01:50:00 ve 02:00:00):

```c
char *name = (char*)malloc(20*sizeof(char));
if( name == NULL ) { printf("out of memory"); exit(1); }
...
printf("Enter a name to be searched:"); scanf("%s",name);
q = find(name);
if( q == NULL )  printf("Not found");
else             printElementP(q);
...
free(name);
```

`scanf` adres bekler; `name` zaten bir adres olduğu için başına `&` konmaz. Derlemede ilk denemede bir sözdizimi hatası çıktı (ekranda `parse error before 'int'`, 01:50:00); değişken bildirimleri bloğun başına alınınca program derlendi.

### 6.7 Silme: `delete_element`

Silme fonksiyonu silinecek düğümü (goner) parametre olarak alır (ekrandan, 01:55:00):

```c
/* To delete an element in a linked list,
   you need to find the element before the one you are deleting
   so that you can bond the list back together after removing one of the links.
   You also need to use the free() func,
   to free up the memory used by the deleted element.  */
void delete_element(EMPLOYEE *goner){
    EMPLOYEE *p;
    if(goner == head) {  head=goner->next; }
    else { // find element preceding the one to be deleted:
        for(p=head; (p!=NULL) && (p->next != goner); p=p->next);
        if(p == NULL){
            printf("delete_element(): could not find the element \n"); return;
        }
        p->next=p->next->next;
    }
    free(goner);
}
```

- Silinecek düğüm baş düğümse, düğüm sayısından bağımsız olarak global `head` doğru güncellenmelidir: yeni baş, silinen düğümün gösterdiği düğümdür.
- Değilse amaç, `next`'i silinecek düğüm olan `p`'yi bulmaktır.
- Silinecek düğüm listede olmayabilir. Döngü yalnız `p->next != goner` koşuluyla kurulsaydı listenin sonunda `NULL` bir işaretçinin `next`'ine erişilmeye çalışılırdı. Bu bir bellek erişim hatasıdır ve program çöker. Bu yüzden koşula `p != NULL` de eklenir.
- Döngüden iki yolla çıkılır: `p` `NULL` olmuştur (eleman yok, bildirilir) ya da `p` önceki düğümdür.

Hoca tahtada yine çizdi: 7 içeren düğüm 10 içeren silinecek düğümü (G), o da 8 içeren düğümü gösteriyor. `p->next = goner->next;` yazmak ile `p->next = p->next->next;` yazmak aynı sonuca çıkar, çünkü `p->next` zaten goner'dır. Slayttaki kod ikinci biçimi tek satırda kullanır. Son olarak goner `free` edilir.

Gösterimde önce iki çalışan eklendi, araya üçüncüsü eklendi, sonra bu araya eklenen eleman silindi. Silinen elemanın adı arandığında "Not found" alındı ve liste ilk iki çalışanla yazdırıldı. Silme fonksiyonu doğrudan düğüm beklediği için, `create_list_element` ile oluşturulan işaretçi ya da `find` ile bir isme göre bulunan düğüm verilebilir.

> **Hocanın vurgusu:** Testte bütün durumlar denenmelidir. Aradan, baştan ve sondan düğüm silme üç ayrı vakadır. Kod aradan silerken doğru çalışıp baştan ya da sondan silerken hatalı olabilir.

### 6.8 Listenin boşaltılması

Bellek tasarrufu için program sonunda liste boşaltılmalıdır. En makul yol, liste boşalana kadar sürekli baştaki düğümü silmektir. `printList`'e de liste boşsa bunu bildiren bir satır eklendi. <!-- BELİRSİZ: bu kısmın kodu karelerde görünmüyor; aşağıdaki kod altyazıdaki anlatımdan kurulmuştur. -->

```c
while( head != NULL )
    delete_element( head );
printList();   /* head NULL ise "List is empty" yazar */
```

Program çalıştırıldığında bütün elemanlar sorunsuz silindi ve liste boş olarak raporlandı.

### 6.9 Bütünleşik program (ajan tarafından derlendi)

Aşağıdaki program derste ekranda görülen fonksiyonların birleşimidir. `add_element` ve boşaltma döngüsü anlatımdan kuruldu. Eksik başlık dosyaları eklendi, `%.2f` düzeltmesi ve boş liste satırı uygulandı. Kod `gcc -Wall` (ve `-fsanitize=address,undefined`) ile uyarısız derlendi. Üç çalışan girilip araya eklenen silindi, adı arandı ve liste boşaltıldı; çıktı beklendiği gibiydi, bellek sızıntısı görülmedi.

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Employee {
    char name[20];
    int  ID;
    float salary;
    struct Employee *next;
} EMPLOYEE;
EMPLOYEE *head;
void printElementP( EMPLOYEE *emp ) {
    printf("Employee %d %s has a salary of %.2f\n",
        emp->ID, emp->name, emp->salary );
}
void printList( ) {
    int j; EMPLOYEE *p;
    if (head == NULL) { printf("List is empty\n"); return; }
    for(j=0, p=head; p != NULL; p=p->next, j++)
        printf("%d-th person: %d\t%s\t%.2f\n",
            j+1, p->ID, p->name, p->salary);
}
EMPLOYEE* create_list_element(  ) {
    EMPLOYEE *emp; int i; float s;
    emp = (EMPLOYEE*) malloc( sizeof( EMPLOYEE ) );
    if( emp == NULL ) {
        printf("create_employee: out of memory."); exit(1);
    }
    printf("Enter name of the person: "); scanf("%19s", emp->name);
    printf("Enter ID of the person: ");
    scanf("%d", &i); emp->ID = i;
    printf("Enter salary of the person: ");
    scanf("%f", &s); emp->salary = s;
    emp->next=NULL; return emp;
}
void add_element( EMPLOYEE *e ) {
    EMPLOYEE *p;
    if( head == NULL ) { head = e; return; }
    for( p = head; p->next != NULL; p = p->next );
    p->next = e;
}
void insert_after(EMPLOYEE *p, EMPLOYEE *q){
    if(p==NULL || q==NULL || p==q || q->next == p){
        printf("insert_after(): Bad arguments \n");
        return;
    }
    p->next = q->next;
    q->next = p;
}
EMPLOYEE* find(char *name) {
    EMPLOYEE *p;
    for(p=head; p!= NULL; p=p->next)
        if(strcmp(p->name, name) == 0)
            return p;
    return NULL;
}
void delete_element(EMPLOYEE *goner){
    EMPLOYEE *p;
    if(goner == head) { head=goner->next; }
    else {
        for(p=head; (p!=NULL) && (p->next != goner); p=p->next);
        if(p == NULL){
            printf("delete_element(): could not find the element \n"); return;
        }
        p->next=p->next->next;
    }
    free(goner);
}
int main(int argc, char *argv[])
{
    EMPLOYEE *p,*q;
    char *name = (char*)malloc(20*sizeof(char));
    int j;
    if( name == NULL ) { printf("out of memory"); exit(1); }
    for(j=0; j<2; j++)
        add_element( create_list_element() );
    for(j=0, p=head; p != NULL; p=p->next, j++)
    {
        printf("%d-th person: ",(j+1)); printElementP(p);
    }
    p=create_list_element();
    q=head;
    insert_after(p, q);
    printList();
    delete_element(p);
    printf("Enter a name to be searched:"); scanf("%19s",name);
    q = find(name);
    if( q == NULL ) printf("Not found\n");
    else            printElementP(q);
    printList();
    while( head != NULL ) delete_element(head);
    printList();
    free(name);
    return 0;
}
```

> **Ek bilgi (derste anlatılmadı):** `delete_element(p)` çağrısından sonra `p` hâlâ eski adresi tutar, ama o bellek artık serbesttir. Bu "sarkan işaretçi" (dangling pointer) üzerinden erişim tanımsız davranıştır. Silmeden sonra işaretçiyi `NULL` yapmak iyi bir alışkanlıktır.

## 7. Yapı hizalama (structure alignment)

Yapıya alanlar iş mantığına göre eklenir, ama bellekte nasıl yerleştikleri mimariye bağlıdır. Bazı bilgisayar mimarilerinde `char`'dan geniş türden değişkenler ya da alanlar yalnız ikinin katı (çift) adreslerde saklanabilir. Bu programcıya görünmez, ama arka planda verimsiz kullanılan boşluklar oluşabilir.

Slayttaki örnek şöyledir (ekrandan, 02:25:00):

```c
struct ALIGN_EXAMP { char mem1; short mem2; char mem3; } s1;
```

Hizalama kısıtı yoksa alanlar peş peşe yerleşir:

| Adres | 1000 | 1001–1002 | 1003 |
|---|---|---|---|
| Alan | mem1 | mem2 | mem3 |

`char`'dan büyük nesnelerin çift adreste başlaması gerekiyorsa:

| Adres | 1000 | 1001 | 1002–1003 | 1004 | 1005 |
|---|---|---|---|---|---|
| Alan | mem1 | boşluk (hole) | mem2 | mem3 | boşluk (hole) |

Sonraki kayıt 1006'dan başlar ve her kayıtta mem1 ile mem2 arasında ve mem3'ten sonra 1 baytlık boşluk oluşur. Hoca bunun alanların tanımlama sırası değiştirilerek kolayca önlenebileceğini söyledi. Sıra `char mem1; char mem3; short mem2;` olursa iki `char` peş peşe iki bayt kaplar ve `short` yine çift adresten başlar.

> **Hocanın vurgusu:** Alanlar tanımlanırken olası boşluklar düşünülmeli ve sıralama buna göre yapılmalıdır. Bu önemli bir not olarak verildi; "yapıyı hizalama boşluğu oluşturmayacak şekilde tanımlayın" biçiminde sorulabildiği söylendi.

> **Ek bilgi (derste anlatılmadı):** Ajanın x86-64 üzerinde gcc ile yaptığı denemede `sizeof(struct ALIGN_EXAMP)` 6, sırası `char, char, short` olan yapınınki 4 bayt çıktı. Bu, slayttaki boşluk hesabıyla uyumludur.

## 8. Bit alanları (bit fields)

Normalde en küçük veri türü 8 bitlik (1 baytlık) `char`'dır. Yapı içinde bundan da küçük alanlar tanımlanabilir; bunlara bit alanı (bit field) denir. Bit alanları `int` değişkenler gibi davranır, ama iki kısıtları vardır:

- Bit alanlarından dizi tanımlanamaz.
- Bit alanının adresi alınamaz. Bir baytın içindeki alt alanların başlangıcı keyfi bir bit olabileceği için adreslenemez.

Tanımlarken önce alanların toplam kaç bit edeceği hesaplanır ve bu toplamı alabilecek en küçük temel tür (base type) seçilir. Örneğin 1, 2 ve 1 bitlik üç alan toplam 4 bittir ve `char`'a sığar. Toplam 14 bit ise 2 baytlık bir alan gerekir. Sonra alanın adı, iki nokta ve bit sayısı yazılır.

### 8.1 `a:3, b:7, c:2` örneği

```c
struct {
    int a : 3;
    int b : 7;
    int c : 2;
} s;
```

Hoca yerleşimi bir hesap tablosunda gösterdi. 1000 adresinden başlayan 16 bitlik bir `int` içinde (ekrandan, 02:30:00):

| Bitler | 0–2 | 3–9 | 10–11 | 12–15 |
|---|---|---|---|---|
| Alan | a | b | c | boş (EMPTY) |

Bu tanımın kazancı şudur: üç alan için ayrı ayrı `short` ayırmak yerine tek bir `int` yeterli olur ve yerden tasarruf edilir.

Hoca önce tarih yapısını da bu yolla küçültmeyi denedi. Gün en fazla 31 olduğu için 5 bit ($2^5 = 32$), ay en fazla 12 olduğu için 4 bit ($2^4 = 16$) yeter. 16 bitlik alanda gün ve aydan sonra kalan bitler yıl için yetmez. Yılın yalnız son iki hanesi tutulsa bile 2 üzeri birkaç bitlik aralık kısa sürede dolar. Hoca bu yüzden tarih örneğini bu biçimde geri aldı: gün ve ayı tek bir bit alanında, yılı ayrı bir `short`'ta tutmak az bir kazanç sağlar.

> **Ders sonrası not:** Hoca 16 bitlik alanda gün (5) ve aydan (4) sonra "6 bit" kaldığını söyledi; doğrusu $16 - 9 = 7$ bittir. Sonuç değişmez: 7 bit ($2^7 = 128$) dört haneli bir yıl için yetmez.

- Temel tür, kullanılan toplam bit sayısını alabilecek kapasitede olmalıdır. Örneğin `int` 2 bayt ise 17 bitlik bir alan `int` içinde tanımlanamaz, `long int` gerekir. `int` 4 bayt olan platformlarda bu sorun olmaz.
- Alanlar kodda `a, b, c` sırasıyla yazılsa da derleyici bunları bellekte `a, c, b` ya da `c, b, a` gibi farklı bir sırayla, artan ya da azalan bit sırasında saklayabilir. Garanti olan yalnız her alana istenen sayıda bit ayrılmasıdır.
- Örneğin `A` 10 bit ve `B` 10 bit tanımlanırsa iki alan tek bir 16 bitlik birime sığmaz; böyle bir tanımla fazla tasarruf yapılmış olmaz.

> **Ek bilgi (derste anlatılmadı):** Düz `int` ile tanımlanan bir bit alanının işaretli mi işaretsiz mi olduğu derleyiciye bağlıdır (implementation-defined). Negatif değer tutulmayacaksa `unsigned int` yazmak bu belirsizliği ortadan kaldırır.

### 8.2 `DATE` yapısıyla bit alanları

Slayttaki tarih yapısı şöyledir (ekrandan, 02:35:00):

```c
struct DATE{
    unsigned int day : 5;
    unsigned int month : 4;
    unsigned int year : 11;
};
```

Negatif sayılarla uğraşılmayacağı için `unsigned` kullanılır. Gün için 5 bit ($2^5 = 32$), ay için 4 bit ($2^4 = 16$) yeterlidir. Yıl için 11 bit $2^{11} = 2048$'e kadar değer tutar. Hoca bunun biraz az olduğunu, 12 bitin ($2^{12} = 4096$) daha mantıklı olacağını söyledi; kitaptaki şema bu konuda cimri davranmış. Toplam $5 + 4 + 11 = 20$ bittir.

Slayttaki iki şekil, derleyicinin yerleşim kuralına göre farklı israf oluştuğunu gösterir:

- Derleyici bit alanlarını en yakın `char`'a yerleştiriyor ve alanların `int` sınırını aşmasına izin veriyorsa: day 0–4, month 5–8, year 9–19 bitlerini kaplar. Sonraki kayıt bir sonraki bayttan başlar, yani her kayıt arasında birkaç bitlik boşluk kalır.
- Derleyici en yakın `short`'a yerleştiriyor ve alanların `int` sınırını aşmasına izin vermiyorsa: day 0–4, month 5–8 bitlerini kaplar, 9–15 boş kalır. year 16–26 bitlerine yerleşir, 27–31 yine boş kalır. Her kayıt 4 bayt tutar ve sonraki kayıt 1004'ten başlar.

| Bitler | 0–4 | 5–8 | 9–15 | 16–26 | 27–31 |
|---|---|---|---|---|---|
| Alan (short paketleme) | day | month | boş | year | boş |

Bu ikinci durumda çok daha fazla bellek israf edilir. Hoca çözüm olarak sırayı değiştirmeyi önerdi: gün (5), yıl (11), ay (4). Gün ve yıl birlikte tam 16 bit eder ve tek başına bir birimi doldurur. Ay bir bayta konduğunda $8 - 4 = 4$ bit boş kalır. Yerleşim hangi kurala göre yapılırsa yapılsın kayıt başına yalnız 4 bitlik bir israf olur. Yıl için 12 bit seçilirse ay ile yer yer değiştirilip yıl sona alınabilir; o durumda ilk baytta $8 - 5 = 3$ bitlik bir kayıp kalır.

Slayttaki sonuç cümlesine göre en iyi bellek kullanımı için ortamın bazı ayrıntılarını bilmek gerekir. Ama alanların sırasını değiştirmek ya da daha fazla tasarruf için birkaç fazla bit ayırmak gibi önlemler her zaman alınabilir. Tarihi "gün, ay, yıl" sırasıyla yazmak bir alışkanlıktır, ama bellekte israfa yol açabilir. Kullanıcıdan veri yine alışılmış sırayla istenebilir; yalnız yapı tanımlanırken alanlar daha verimli bir sırayla yazılır.

## Örnek Sorular

**Soru 1** (ekrandan, 01:25:00): Listenin birinci ve ikinci elemanı arasına yeni bir çalışan ekleyen `main` kodunu yazın.

> **Çözüm (derste verildi):**
>
> `p = create_list_element(); q = head; insert_after(p, q); printList();`
>
> `q` baş düğümü gösterir; `insert_after` önce `p->next = q->next`, sonra `q->next = p` yapar. Böylece yeni eleman ilk iki elemanın arasına girer.

**Soru 2** (derste sözlü, 01:29:41): Çalışanların adı en fazla 20 karakterlik bir metin, kimliği bir tam sayı ve maaşı bir ondalıklı sayıdır. Çalışanlar bir bağlı listede tutulacaktır. Verilen kod iskeletindeki boş bırakılan yapı tanımını doldurun.

> **Çözüm (derste verilmedi):**
>
> `typedef struct Employee { char name[20]; int ID; float salary; struct Employee *next; } EMPLOYEE;`
>
> Yapı kendi türünden bir işaretçi içerdiği için `struct` adı (`Employee`) verilmek zorundadır; adsız yapı burada kullanılamaz.

**Soru 3** (derste sözlü, 02:25:03): `struct ALIGN_EXAMP { char mem1; short mem2; char mem3; };` yapısını, `char`'dan büyük nesnelerin çift adreste başlaması gereken bir makinede hizalama boşluğu oluşturmayacak şekilde yeniden tanımlayın.

> **Çözüm (derste verildi):**
>
> `struct ALIGN_EXAMP { char mem1; char mem3; short mem2; };`
>
> İki `char` 1000 ve 1001 adreslerini kaplar, `short` 1002'den (çift adres) başlar; yapı 4 bayt olur ve boşluk kalmaz. Eski sırada her kayıt 6 bayt tutar (iki 1 baytlık boşluk).

**Soru 4** (ekrandan, 02:35:00): `struct DATE { unsigned int day:5; unsigned int month:4; unsigned int year:11; };` yapısı, bit alanlarını `short`'a paketleyen ve alanların `int` sınırını aşmasına izin vermeyen bir derleyicide nasıl yerleşir? İsrafı azaltmak için ne yapılabilir?

> **Çözüm (derste verildi):**
>
> day 0–4, month 5–8, 9–15 boş; year 16–26, 27–31 boş. Yani 32 bitte 12 bit israf edilir.
>
> Sıra day (5), year (11), month (4) yapılırsa ilk 16 bit tam dolar ve ay bir bayta konduğunda yalnız 4 bit boş kalır.

## Dersin Toparlaması

Derste önce `main` fonksiyonunun `argc` ve `argv` parametreleriyle programa komut satırından bilgi aktarma görüldü; `argv[0]`'ın programın kendi adı olduğu gösterildi. Ardından yapılar anlatıldı: farklı türden verileri tek kayıtta toplama, `typedef` ile büyük harfli tür adı verme, nokta ve ok operatörleri, iç içe yapılar ve yapıların değerle ya da adresle fonksiyonlara aktarılması.

Dersin ağırlık merkezi, yapılarla bir bağlı liste gerçeklemekti. Düğüm oluşturma, sona ekleme, araya ekleme, arama, silme ve listeyi boşaltma fonksiyonları yazıldı ve çalıştırıldı. Her işlemde işaretçi güncelleme sırasının ve baş işaretçisini korumanın önemi vurgulandı. Son bölümde yapı hizalamasının yol açtığı bellek boşlukları ve bit alanları anlatıldı. Her ikisinde de alanların tanımlanma sırasının bellek kullanımını doğrudan etkilediği görüldü. Bit alanlarının yalnız teorisi görüldü; hoca bit alanlarıyla çalışan modelleme uygulamasının sonraya kaldığını belirtti. Dersin başındaki planda yer alan union yapısına bu derste gelinmedi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
