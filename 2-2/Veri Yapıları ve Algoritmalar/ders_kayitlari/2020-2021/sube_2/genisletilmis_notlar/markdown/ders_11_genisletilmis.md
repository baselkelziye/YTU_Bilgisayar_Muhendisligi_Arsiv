# Ders 11 Genişletilmiş Notu: Bağlı Liste ile Kuyruk, Ağaçlar, İkili Ağaç Gezintileri ve İkili Arama Ağacı

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Bağlı Liste ile Kuyruk
- 2. Ağacın Tanımı
- 3. Günlük Hayatta ve Bilgisayarda Ağaçlar
- 4. İkili, Üçlü ve M Dereceli Ağaçlar
- 5. Temel Kavramlar
- 6. İkili Ağacı Dizi ile Gösterme
- 7. İkili Ağacı İşaretçi ile Gösterme
- 8. İkili Ağacın Özel Durumları
- 9. İkili Ağaçta Ekleme ve Silme
- 10. Derinlik Öncelikli Gezintiler
- 11. Alternatif Gezintiler: Yığıt ve Kuyruk ile
- 12. Gezintilerin Uygulamaları: Kopyalama ve Eşitlik
- 13. Genel Ağacı İkili Ağaç Olarak Gösterme
- 14. İkili Arama Ağacı
- Örnek Sorular
- Dersin Toparlaması

## 1. Bağlı Liste ile Kuyruk

### 1.1 Önceki dersten hatırlatma

Ders, bir önceki hafta başlanan yığıt (stack) ve kuyruk (queue) konusunun tamamlanmasıyla açıldı. Kuyruk FIFO (first in, first out) çalışan, yani ilk gelenin ilk çıktığı bir veri yapısıdır; hoca onu "verilerin organize olmasını sağlayan" bir yapı olarak tanımladı. Önceki derste kuyruk önce statik dizi ile gerçeklenmişti. O gerçeklemede front ve rear indisleri kullanılarak, her ekleme ve çıkarmada elemanları tek tek kaydırmaya gerek kalmadan, tek bir iç içe `if` ile dizinin sonuna gelindiğinde başa sarılıyordu. Böylece işlemler $O(1)$'de kalıyordu; kaydırma yapılsaydı her işlem $O(n)$ olurdu. Önceki dersin "Alternatif Gerçekleme" slaytındaki kod şöyledir (ekrandan, 00:05:00):

```c
#define MAX 6

int intArray[MAX];
int front = 0;
int rear = -1;
int itemCount = 0;

int isEmpty() { return itemCount == 0;}
int isFull() { return itemCount ==MAX;}
int size() { return itemCount; }

void enqueue(int data) {
   if(!isFull()) {
      if(rear == MAX-1) {
         rear = -1;
      }
      intArray[++rear] = data;
      itemCount++;
   }
}

int dequeue() {
   int data = intArray[front++];
   if(front == MAX) {
      front = 0;
   }
   itemCount--;
   return data;
}
```

### 1.2 Kuyruğun bağlı liste ile yapısı

Kuyruğu bağlı liste ile gerçeklemek için dizi yerine A, B, C değerlerini tutan bir bağlı liste kurulur. Düğüm tipi her zamanki gibi bir `data` alanı ve kendi tipinden bir `next` işaretçisi içerir. Hoca tip adını karışmasın ve okunaklı olsun diye büyük harfle `Node` yazdıklarını söyledi. Kuyruk ise başka bir yapı değildir; ön (front), arka (rear) ve eleman sayısını (count) tutan üç değişkenin bir arada durmasıdır (ekrandan, 00:10:00):

```c
#define FULL 10

typedef struct node{
    int data;
    struct node *next;
} Node;

typedef struct queue{
    int count;
    Node *front;
    Node *rear;
}Queue;
```

Slayttaki şekilde A → B → C → NULL listesi vardır; kuyruk yapısında `count` 3'tür, `front` A'yı, `rear` C'yi gösterir. Hoca `count` alanının aslında zorunlu olmadığını, onsuz da kuyruğun çalışacağını ama o zaman "sonsuz uzunlukta" bir kuyruk olacağını söyledi. Her zaman bir sınır koymak faydalıdır: `FULL` 10 olarak tanımlanmıştır ve `count` bu değere ulaşınca kuyruğa yeni eleman alınmaz.

### 1.3 İlklendirme ve boşluk kontrolü

Hiç eleman yokken kuyruk şöyle ilklendirilir: kuyruk yapısı oluşturulup bir adrese bağlanır, `count` sıfırlanır, `front` ve `rear` `NULL` yapılır. Bu, elimizde hiç düğüm olmayan, yeni oluşturulmuş boş bir kuyruktur.

Boş mu kontrolü birkaç yolla yapılabilir: sayacın 0 olup olmadığına, `rear`'ın `NULL` olup olmadığına ya da `front`'un `NULL` olup olmadığına bakılabilir. Hoca bunun tercihe bağlı olduğunu söyledi.

### 1.4 enqueue: kuyruğa ekleme

Boş bir kuyruğa eleman eklemek için önce yeni bir düğüm oluşturulur, değeri (örnekte 4) yazılır ve `next` işaretçisi `NULL` yapılır, çünkü bu düğüm son eleman olacaktır. Kuyruk boşsa tek eleman olduğu için hem `front` hem `rear` bu yeni düğüme bağlanır. Kuyruk boş değilse `front` ile işimiz yoktur, çünkü `front` çıkarma (dequeue) işleminde kullanılan işaretçidir. Ekleme kuyruğun sonuna yapılır: önce eski son düğümün `next`'i yeni düğüme bağlanarak bağlı liste yapısı korunur, sonra `rear` yeni düğümü gösterecek şekilde güncellenir. En son sayaç bir artırılır.

Hoca bunu adım adım çizdi: A eklenince `front` ve `rear` A'yı gösterir. B eklenince A'nın `next`'i B'ye bağlanır ve `rear` B'ye taşınır. C eklenince B'nin `next`'i C'ye bağlanır ve `rear` C'ye taşınır. Böylece kuyruğa ne kadar eleman gelirse gelsin hem öne hem arkaya her zaman doğrudan erişilebilir. Kod (ekrandan, 00:15:00):

```c
void enqueue(Queue *q, int value){
    if (q->count < FULL){
        Node *tmp;
        tmp = malloc(sizeof(Node));
        tmp->data = value;
        tmp->next = NULL;
        if(!isempty(q)){
            q->rear->next = tmp;
            q->rear = tmp;
        }
        else{
            q->front = q->rear = tmp;
        }
        q->count++;
    }
    else{
        printf("List is full\n");
    }
}
```

Kuyruk doluysa `else` kolunda bir hata mesajı verilir; hoca burada başka bir eylem ya da fonksiyon da çalıştırılabileceğini söyledi. Ayrıca bellek ayrılıp ayrılamadığı kontrolünün slaytta gösterilmediğini, öğrencilerin bunu kendilerinin eklemesi gerektiğini belirtti.

### 1.5 dequeue: kuyruktan çıkarma

Eleman kuyruğun önünden (front) çekilir. Önce silinecek düğümü gösterecek geçici bir işaretçi oluşturulur. Düğüm serbest bırakılacağı için tuttuğu değer, çağırana döndürülebilmek için önce bir değişkene kopyalanır. Sonra `front` işaretçisi bir sonraki düğüme kaydırılır; artık kuyruktaki ikinci kişi öndedir. Geçici işaretçi sayesinde eski ön düğüm `free` edilir. Sayaç bir azaltılır (örnekte 3'ten 2'ye) ve kopyalanan değer döndürülür. Kod (ekrandan, 00:20:00):

```c
int dequeue(Queue *q)
{
    Node *tmp;
    int n = q->front->data;
    tmp = q->front;
    q->front = q->front->next;
    q->count--;
    free(tmp);
    return(n);
}
```

Hoca bu işlemin zor olmadığını, yalnız işaretçilerin sırasına dikkat etmek gerektiğini vurguladı: önce `front` kaydırılır, sonra eski düğüm silinir; sayacı artırmayı ya da azaltmayı unutmamak gerekir.

> **Ek bilgi (derste anlatılmadı):** Slayttaki `dequeue`, son eleman da çıkarıldığında `rear`'ı `NULL` yapmaz; `front` `NULL` olur ama `rear` serbest bırakılmış düğümü göstermeye devam eder. Boşluk kontrolü `rear == NULL` ile yapılıyorsa bu durumda kuyruk boş görünmez. Bu yüzden ya boşluk `count` ya da `front` ile kontrol edilmeli ya da `front` `NULL` olduğunda `rear` da `NULL` yapılmalıdır.

### 1.6 Kuyruk işlemlerinin karmaşıklığı

- `enqueue`: sabit sayıda işlem yapılır, döngü yoktur; $O(1)$. Dizi ve bağlı liste gerçeklemesinde aynıdır.
- `dequeue`: front ve rear işaretçileri sayesinde $O(1)$.
- `peek` (ilk elemana bakıp çekmemek): tek bir indise ya da `front` işaretçisine bakmak olduğu için $O(1)$.
- `isEmpty`, `isFull`: sayaçla ya da işaretçinin `NULL` olup olmadığıyla yapılır; $O(1)$.

Hoca kuyruk ve yığıtın çok temel veri yapıları olduğunu, işlem sırasında elemanlara belirli bir mantıkla erişilmesini sağladıklarını ve $O(1)$ işlemleri sayesinde toplam işlem karmaşıklığını düşürdüklerini söyledi. Bu yapılar başka pek çok veri yapısının içinde kullanılacaktır.

## 2. Ağacın Tanımı

Kuyruğun ardından yeni konuya, ağaç (tree) veri yapısına geçildi. Hoca bu haftanın sorularını şöyle koydu: ağaç nedir, üzerinde hangi işlemler yapılır ve özellikle arama ya da veriye erişimde karmaşıklığı nasıl azaltır?

Slayttaki ilk tanım şudur (ekrandan, 00:25:00): ağaç, **hiyerarşik yapıda birbirine bağlı ve kapalı çevrim oluşturmayan sonlu düğümler kümesidir**. Hoca "kapalı çevrim oluşturmayan" ve "sonlu düğümler" ifadelerinin altını çizdi ve tanıma aslında bağlantıların da dahil olduğunu, "düğümler ve bağlantılar kümesi" demenin daha doğru olacağını ekledi. Hiyerarşi tamamen bizim kafamızdadır: örneğin en üstte bir düğüm, ortada iki, en altta beş düğüm olmak üzere sekiz düğümlük bir yapı çizip herkesi üstündekine bağladığımızda seviyeler oluşur.

> **Hocanın vurgusu:** Tanımdaki en önemli kısım kapalı çevrim oluşturmamaktır.

Bu yapıda iki düğüm arasına fazladan bir bağlantı çizilirse kapalı bir çevrim oluşur. Çevrim nerede oluşursa oluşsun tanımı ve hiyerarşiyi bozar; böyle bir yapıya ağaç değil graf denir. Graflar ileriki haftalarda ele alınacaktır.

Slayttaki ikinci tanım şudur: aralarında yönlü bağlantılar bulunan ve şu özellikleri içeren düğümler topluluğu:

- Kendisine doğru kenar içermeyen ve kök (root) olarak adlandırılan özel bir düğüm vardır.
- Kök dışındaki tüm düğümlere gelen tek bir kenar bulunur.
- Kök düğümden tüm düğümlere ulaşılan (düğüm ve kenarlardan oluşan) yol tektir.

Hoca yön kavramının uygulamaya bağlı olduğunu açıkladı: oklar kökten çocuklara doğru da, çocuklardan köke doğru da çizilebilir; çift yönlü bağlantılarda ok çizmeye gerek yoktur. Önemli olan, bütün düğümlerin kaynağı olan bir kökün bulunması ve kök dışındaki her düğüme bir kenarın gelmesidir (ya da ters yönde düşünülürse bir kenarın çıkmasıdır).

Son maddede iki fikir iç içedir: kökten bütün düğümlere ulaşılabilir ve bu yollar tekildir. Örneğin kökten bir düğüme yalnız tek bir yoldan gidilebilir. Fazladan bir bağlantı olsaydı aynı düğüme kökten hem soldan hem sağdan gidilebilirdi; bu hem tek yol koşulunu hem de ilk tanımdaki çevrimsizlik koşulunu bozardı. Bu tür yapılar graftır. Ağaçlar aslında grafların özel bir hâlidir; hoca önce daha özel olan ağacı tanımanın anlamayı kolaylaştıracağı için ağaçlardan başladıklarını söyledi.

## 3. Günlük Hayatta ve Bilgisayarda Ağaçlar

Hoca önce doğadaki ağacı çizdi: toprağın altında kökler, üstünde gövde, gövdeden çıkan dallar ve dalların ucunda yapraklar vardır. Bilgisayar bilimindeki ağaç bunun ters çevrilmiş hâlidir: kök en üstte, yapraklar en alttadır.

Hayattan ağaç örnekleri:

- **Soy ağacı:** her insanın bir annesi ve babası vardır; onların da kendi anne ve babaları vardır. Teyze, dayı, hala, amca ve kuzen gibi akrabalık ilişkileri bu hiyerarşide gezinerek bulunur (örneğin kuzen, annenin kardeşinin çocuğudur).
- **Organizasyon şemaları:** yönetim kurulu, genel müdür, bölüm müdürleri ve onların altındaki birimler hiyerarşik bir ağaçtır.
- **Tenis turnuvası tablosu:** tenis iki kişiyle oynandığı için tablo tam bir ikili ağaçtır. Her maçtan tek kazanan bir üst tura çıkar; yukarı çıkıldıkça düğüm sayısı yarıya iner ve en tepede şampiyon (kök) kalır. Futbol fikstürleri de böyle kurulabilir.
- **İçindekiler tablosu:** kitap, tez ya da projelerdeki 1, 1.1, 1.2, 1.2.1 biçimindeki numaralandırma bir ağaçtır.
- **Dosya sistemi:** kök dizin, içinde klasörler, onların içinde alt klasörler ve dosyalar.
- **Veritabanı indeksleri:** tablolar ağaç yapısındaki indekslerle tutulur (hoca R-tree gibi farklı ağaç türlerini örnek verdi).

Hoca ağaçların hem hayatın her yerinde hem de bilgi sistemlerinde ve algoritmalarda çok kullanıldığını söyledi.

## 4. İkili, Üçlü ve M Dereceli Ağaçlar

En çok kullanılacak ağaç ikili ağaçtır (binary tree). Bir düğümden hiç bağlantı çıkmayabilir, bir ya da en fazla iki bağlantı çıkabilir. Örneğin kökten yalnız tek bir düğüm çıkıyorsa diğer taraf `NULL`'dır; bu da ikili ağaca uyar. Hiç bağlantısı çıkmayan düğümlere uç düğüm (external node) ya da daha yaygın adıyla **yaprak (leaf)** denir; ağacın dallarının ucundaki yapraklara benzetilmiştir.

Bir düğümden en fazla üç bağlantı çıkabiliyorsa ağaca üçlü ağaç (ternary tree) denir. Genel olarak bir düğümden en fazla M bağlantı çıkabiliyorsa M dereceli ağaç (M-ary tree) denir: binary, ternary, quaternary ve benzeri.

Bir kök düğümü özel olarak belirlenmişse ağaca **köklü ağaç** denir; derste hep köklü ağaçlarla çalışılacaktır. Kökü belirlenmemiş ama çevrim içermeyen ağaca **serbest ağaç** denir. Serbest ağaçta istenen herhangi bir düğüm kök seçilebilir. Hocanın gösterdiği serbest ağaç örneğinde bir düğümden altı bağlantı çıktığı için bu ağaç 6 dereceli bir ağaç olarak düşünülebilir.

## 5. Temel Kavramlar

### 5.1 Kök, ebeveyn, çocuk, yaprak, kardeş

Slayttaki örnek ağaç (ekrandan, 00:40:00):

```text
        A   <- kök
       / \
      B   C
         / \
        D   E
       / \
      F   G
          |
          H
```

- **Düğüm:** veri ve diğer düğümlere bağlantı içeren yapı.
- **Kök (root):** bütün düğümlerin atası olan düğümdür; hiyerarşik çizimde en üste konur. Bağlı listenin head'i ya da kuyruğun front'u gibi ağaca erişim noktasıdır; kök bilinirse hiyerarşi sayesinde bütün düğümlere ulaşılabilir.
- **Ebeveyn (parent):** alt ağaçlar olarak düzenlenmiş evlat düğümleri olan düğüm. Örnekte C, D ve G ebeveyndir (A da öyle).
- **Çocuk/evlat (child):** bir ebeveynin altındaki, ona bağlı düğüm. Bir düğümün sıfır ya da daha fazla çocuğu olabilir. C hem bir ebeveyndir hem A'nın çocuğudur; E ve D C'nin, G D'nin, H G'nin çocuğudur. Hocanın özetiyle: alttaysanız çocuksunuz, üstteyseniz ebeveynsiniz.
- **Yaprak (leaf):** alt ağacı olmayan düğüm. Örnekte B, E, F ve H yapraktır.
- **Kardeş (sibling):** aynı ebeveynin çocukları. Örnekte D ile E (C'nin çocukları), F ile G (D'nin çocukları), B ile C (A'nın çocukları) kardeştir. D'nin X, Y, Z gibi başka çocukları da olsaydı F, G, X, Y, Z hepsi kardeş olurdu.

### 5.2 Derece, yükseklik, derinlik, seviye

Slayttaki tanımlar (ekrandan, 00:45:00):

- **Derece (degree):** bir düğümün doğrudan evlat sayısı. Ağacın derecesi, düğüm derecelerinin en büyüğüdür: $\max(\text{degree})$. Örnekte A'nın 2, C'nin 2, D'nin 2, G'nin 1 çocuğu vardır; ağacın derecesi 2'dir, yani bu bir ikili ağaçtır.
- **Yükseklik (height):** ağaçta kök ile yapraklar arasındaki en uzun yolun kenar sayısı. Slayta göre kökün (çocuğu varsa) yüksekliği 1'dir; hoca bunu "bir kenar gittim" diye açıkladı. Örnekte A'dan H'ye A–C–D–G–H yolu 4 kenardır; ağacın yüksekliği 4'tür.
- **Derinlik (depth):** bir düğümden köke olan kenar sayısı. Kökün derinliği 0'dır. Örnekte C'nin derinliği 1, D'nin 2, G'nin 3, H'nin 4'tür.
- **Seviye (level):** kökün seviyesi 1, çocuklarının 2'dir ve böyle devam eder: $\text{Level} = \text{Depth} + 1$, çünkü derinlik 0'dan, seviye 1'den başlar.

$h$ yükseklikteki bir ikili ağaçta en fazla kaç düğüm olabileceği soruldu. Hoca yüksekliği 2 olan ve bütün düğümleri dolu bir ikili ağaç çizdi: düğümler sayılınca 7 çıkar.

```text
        o
      /   \
     o     o
    / \   / \
   o   o o   o
```

Slaytta bu sayı $2^h - 1$ olarak yazılmıştı. Dersin ilerleyen kısmında bir öğrenci bunun yanlış olduğunu fark etti (bkz. 5.5); doğrusu $2^{h+1} - 1$'dir: $h = 2$ için $2^3 - 1 = 7$. Hoca bu tür dolu ağaçların ileride özel bir adla ayrıca tanımlanacağını söyledi.

### 5.3 Ata, torun ve alt ağaç

A'dan B'ye bir kenar varsa A, B'nin ebeveyni, B de A'nın evladıdır. A'dan B'ye bir yol varsa (iki ya da daha fazla seviye aşağıda olabilir) A, B'nin **atası (ancestor)**, B de A'nın **torunudur (descendant)**. Bir düğüm bütün torunlarıyla birlikte bir **alt ağaç (subtree)** oluşturur; ağacın içinde, kendi başına bir ağaç olan küçük ağaçlardır. Hiç evladı olmayan düğüm yaprak, hiç atası olmayan düğüm köktür.

### 5.4 Derinlik ile yükseklik ilişkisi

Hoca bu iki kavramın karıştırılmaması için bir örnek üzerinde ikisini birlikte gösterdi. Yüksekliği 3 olan bir ağaçta:

- Kökün derinliği 0, yüksekliği 3'tür (en uzak yaprağa 3 kenar).
- Kökün iki çocuğunun derinliği 1'dir, çünkü kardeştirler. Ama birinin altından yaprağa 1 kenarla, diğerinin altından 2 kenarla gidiliyorsa yükseklikleri 1 ve 2 olur. Kardeşler arasında böyle farklar olabilir.
- Derinliği 2 olan yaprakların yüksekliği 0'dır. Aynı seviyedeki başka bir düğümün altında hâlâ bir yaprak varsa onun yüksekliği 1'dir.
- En derindeki yaprağın derinliği 3, yüksekliği 0'dır.

Yani kök ile en derin yaprak arasında derinlik ve yükseklik birbirinin tersidir (0 ve 3, 3 ve 0), ama ara seviyelerde farklı değerler çıkabilir. Hoca yüksekliğin daha çok kullanıldığını, derinliğin de kullanılabilen bir kavram olduğunu söyledi.

İkinci örnek (ekrandan, 00:50:00):

```text
Seviye 1:            A
                  /     \
Seviye 2:        B       C
                / \    / | \
Seviye 3:      D   E  F  G  H
                            |
Seviye 4:                   I
```

- A köktür. B, D ve E'nin ebeveynidir. C, B'nin kardeşidir. D ve E B'nin çocuklarıdır.
- D, E, F, G, I dış düğüm, yani yapraktır. A, B, C, H iç düğümdür (internal node).
- E'nin seviyesi 3'tür. Ağacın yüksekliği (derinliği) 3'tür: en dipteki yaprağa 3 kenarlık bir yolla ulaşılır. Ağaç 4 seviyelidir; seviye sayısını kabaca yükseklik artı 1 olarak düşünebiliriz.
- B'nin derecesi 2'dir. Ağacın derecesi 3'tür, çünkü C'den üç kenar çıkar.
- I'nın ataları H, C ve A'dır. C'nin alt soyu F, G, H ve I'dır.

### 5.5 Bir öğrenci sorusu: en fazla düğüm sayısı

**Soru:** Yüksekliği $h$ olan ikili ağaçta en fazla düğüm sayısı $2^h - 1$ denmişti. Ama yalnız A, B, C'den oluşan ağacın yüksekliği 1'dir ve bu formül 1 düğüm verir. Doğrusu $2^{h+1} - 1$ olmamalı mı?

**Cevap:** Hoca önce A, B, C ağacını, sonra büyük örnek ağacın H ve I olmadan kalan kısmını çizdi. İkincisinin yüksekliği 2'dir ve en fazla $2^3 - 1 = 7$ düğüm alır. Hoca slayttaki formülde $+1$'in eksik yazıldığını kabul etti ve doğru ifadenin $2^{h+1} - 1$ olduğunu söyledi: yükseklik tanımına bakıldığında bu açıkça görülür.

## 6. İkili Ağacı Dizi ile Gösterme

### 6.1 Temel fikir

Ağacı oluşturmanın akla gelen ilk yolu dizi kullanmak, alternatifi ise bağlı liste kullanmaktır. Hoca anlatımı ikili ağaç üzerinden yaptı, çünkü anlatması daha kolaydır. Üçlü ya da beşli ağaçlara geçmek için yapılacak tek şey çocuk sayısını artırmaktır.

Slayttaki temel fikir (ekrandan, 01:00:00):

- Sol ve sağ evladı göstermek için dizi indisleri kullanılabilir.
- Yeni bir eleman gerektiğinde nereye eklenebileceğini gösteren **boş değişkeni** kullanılabilir. Sonraki boş alan bu adresin sol ya da sağ evladında yer alabilir.
- Birlikte, dizide kullanılabilir yerlerin listesi **boş listesi (free list)** olarak adlandırılır.

### 6.2 Tablo gösterimi

Dizi iki boyutlu bir tablo gibi düşünülür (ekrandan, 01:10:00):

| İndis | Veri | Sol Evlat | Sağ Evlat |
|---|---|---|---|
| 0 | Jane | 1 | 2 |
| 1 | Bob | 3 | 4 |
| 2 | Tom | 5 | -1 |
| 3 | Alan | -1 | -1 |
| 4 | Ellen | -1 | -1 |
| 5 | Nancy | 6 | -1 |
| 6 | Mary | -1 | -1 |
| 7 | ? | -1 | 8 |
| 8 | ? | -1 | 9 |
| 9 | ... | ... | ... |

Ağaca erişmek için kökün yeri bilinmelidir: kök 0. gözdedir (Jane). Jane'in sol evladı 1. indisteki Bob, sağ evladı 2. indisteki Tom'dur. Bob'un çocukları 3 ve 4'teki Alan ile Ellen'dır. Tom'un sol çocuğu 5'teki Nancy'dir; sağ evlat sütununda $-1$ olduğu için Tom'un sağ çocuğu yoktur. Alan, Ellen ve Nancy'nin iki evlat indisi de $-1$ olduğundan yapraktırlar (Mary eklenmeden önce). Üçlü ya da beşli ağaçta birinci, ikinci, üçüncü evlat diye yeni sütunlar açmak gerekirdi.

Bir de ilk boş gözü gösteren "boş" değişkeni tutulur. Başlangıçta ilk boş göz 6'dır. Mary, Nancy'nin çocuğu olarak eklenmek istenince 6. göze yazılır, Mary'nin evlat indisleri $-1$ yapılır (yapraktır) ve Nancy'nin sol evladı 6 yapılır. Boş değişkeni artık 7'yi gösterir (karede `kök = 0`, `boş = 7`).

Silme örneğinde hoca 4. indisteki düğümü sildi. Bu düğüm Bob'un evladı olduğu için Bob'un ilgili evlat indisi de $-1$ yapılmalıdır; hoca bunun slaytta güncellenmediğini sözlü olarak belirtti. Silmeden sonra 4. göz boşalır ve ilk yazılabilecek yer olduğu için boş değişkeni 7 yerine 4'ü göstermelidir.

<!-- BELİRSİZ: Altyazıda silinen düğümün adı "Alan" ve "Elan" diye geçiyor; karede 3. indiste Alan, 4. indiste Ellen var. Anlatım (4. indis, Bob'un sağ evladı) silinenin büyük olasılıkla Ellen olduğunu gösteriyor. -->

Gerçeklemede `data`, `left` ve `right` alanlı bir `node` yapısı ve örneğin 100 elemanlık (`MAX`) `node` tipinden bir ağaç dizisi tutulur. Ayrıca kökün indisi (`root`) ve boş gözün indisi tutulur. Hoca bu değişkene `free` fonksiyonuyla karışmasın diye "boş" adını verdiğini söyledi.

### 6.3 Dizi tabanlı gösterim

Diğer bir dizi gösteriminde ağaç düğümleri doğrudan konumlarına göre yerleşir. Kök 0. indistedir ve $j$ indisindeki düğüm için:

- sol çocuk: $2j + 1$
- sağ çocuk: $2j + 2$
- ebeveyn: $\lfloor (j - 1)/2 \rfloor$ (aşağı yuvarlanır)

Bu gösterimde ağaç tam dolu değilse boş kalan yerler için de yer ayrılması gerekir, çünkü oralar ileride dolabilir. Hocanın çizdiği 3 seviyeli örnekte en fazla 7 düğüm olabilir. Yalnız 4 düğüm varken de 7'lik dizi açmak gerekir; örneğin yalnız 1, 3 ve 7. gözler doluysa (bir zincir gibi) 3 değer için 7'lik alan harcanır.

Slayttaki örnekler (ekrandan, 01:15:00):

```text
        p
      /   \
     g     r
    / \     \
   b   h     v
        \
         k

İndis: 0 1 2 3 4 5 6 7 8 9 10 ...
Değer: p g r b h _ v _ _ _ k  ...
```

h, g'nin (indis 1) sağ çocuğu olduğu için $2 \cdot 1 + 2 = 4$. indiste; k, h'nin sağ çocuğu olduğu için $2 \cdot 4 + 2 = 10$. indistedir. 5. göz boş, v'den sonra üç göz boş, k'den sonra da boş gözler vardır.

En kötü durum, ağacın zincir şeklinde olmasıdır:

```text
p
 \
  r
   \
    v
     \
      z

İndis: 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 ...
Değer: p _ r _ _ _ v _ _ _ _  _  _  _  z  ...
```

Burada yalnız 4 eleman vardır ama z 14. indise düşer; ağaç hiyerarşisini korumak için çok büyük bir yer israfı olur. Bellek gereksinimi $2^n$ mertebesindedir. Hocanın sonucu: dizi kullanmak ağacı göstermek için çok mantıklı bir yol değildir, çünkü kullanılmasa bile çok fazla bellek harcanır.

## 7. İkili Ağacı İşaretçi ile Gösterme

### 7.1 Düğüm yapısı

Yalnız kullanılan düğümler kadar bellek harcamak için işaretçilere geçilir. İkili ağaçta sol ve sağ evlat indisleri yerine sol ve sağ işaretçiler tutulur. Bu, çift bağlantılı listeye benzer, ama işaretçiler "önceki/sonraki" değil "sol/sağ"dır. Kökü gösteren bir işaretçi tutulur; kökün `left`'i ve `right`'ı ile çocuklara, onların `left`/`right`'ları ile daha alttaki düğümlere erişilir. İki işaretçisi de `NULL` olan düğüm yapraktır.

Hocanın çizdiği örnekte 11 düğüm ve 5 seviye vardı. İşaretçili gösterimde yalnız 11 düğümlük bellek yeterlidir. Hoca aynı ağaç dizi ile tutulsaydı ne kadar yer gerektiğini sordu (bkz. Örnek Sorular).

Kod (ekrandan, 01:20:00):

```c
typedef struct node *tree;
typedef struct node{
      int data;
      tree left, right;
      // tree child, sibling;
}node;

tree createTree(int data){
      tree T = (tree)malloc(sizeof(tree));
      T->data = data;
      T->left = NULL;
      T->right = NULL;
      return T;
}
```

`tree`, `struct node` işaretçisinin tip adıdır. Bu yüzden düğümün sol tarafında bir ağaç, sağ tarafında bir ağaç vardır diye düşünülür; `left` ve `right` alt ağaçları gösterir. Gri renkle yorum satırı yapılmış `child, sibling` alanları ileride kullanılacaktır: böylece herhangi dereceden bir ağaç (örneğin 5 dereceli) "ilk çocuğum budur, kardeşlerim bunlardır" diye yalnız iki işaretçiyle ikili ağaç olarak tutulabilir (bkz. bölüm 13).

`createTree` önce `malloc` ile yeni düğümün belleğini ayırır, verisini yazar, `left` ve `right`'ı `NULL` yapar. Hoca bellek ayrılıp ayrılamadığı kontrolünü göstermediklerini, öğrencilerin eklemesi gerektiğini söyledi. Çizimde verisi 8 olan, iki işaretçisi `NULL`'a giden tek bir kök düğüm oluştu.

> **Ders sonrası not:** Slayttaki `malloc(sizeof(tree))` ifadesi, `tree` bir işaretçi tipi olduğu için yalnız bir işaretçi boyutu kadar yer ayırır; bir düğümün tamamına yetmez. Doğrusu `malloc(sizeof(node))` (ya da `sizeof(struct node)`) olmalıdır. Bu nokta derste konuşulmadı.

### 7.2 Özyinelemeli tanım ve temel işlemler

İkili ağaçta hiçbir düğümün ikiden fazla çocuğu yoktur. Özyinelemeli tanımı şudur: ikili ağaç ya boştur ya da bir kök düğüm ve buna bağlı, sol ve sağ alt ağaç denen iki bağımsız ikili ağaçtan oluşan sonlu düğümler kümesidir. Hoca bunu şöyle açıkladı: bütün alt ağaçların ikili ağaç olduğu özyinelemeli olarak garanti edilirse, tümevarımla bütün ağacın da ikili ağaç olduğu garanti edilmiş olur.

İkili ağaç üzerinde tanımlanabilecek işlemler:

- Oluşturma: iki alt ağaç ve bir kök verildiğinde ağaç kuran bir fonksiyon (örneğin "make binary tree").
- Sol çocuğu alma: yoksa boş, varsa işaretçisi döndürülür. Sağ çocuk için de aynısı.
- Bir düğümün verisini okuma: düğüm yoksa hata döndürülür, varsa değeri döndürülür.

### 7.3 Hangileri ikili ağaçtır?

Hoca slayttaki birkaç şekil üzerinden şunları söyledi: yalnız tek kök düğümden oluşan yapı teoride ikili ağaçtır. Yalnız sol alt ağacı olan ya da yalnız sağ alt ağacı olan yapılar da ikili ağaçtır. Her düğümün en fazla iki çocuğu olan yapılar ikili ağaçtır. Bu şekillerin bazıları ikili ağacın özel durumlarını oluşturur.

## 8. İkili Ağacın Özel Durumları

Bu özel durumlar ileride, örneğin heap'lerde "bunun full olması, şunun complete olması gerekir" gibi tanımlarda kullanılacağı için bilinmelidir. Slayttaki tanımlar ve örnekler (ekrandan, 01:25:00):

**Full binary tree:** her düğümün 0 ya da 2 çocuğu vardır; yapraklar hariç tüm düğümlerin 2 çocuğu vardır, tekli kalan düğüm yoktur.

```text
        18
       /  \
     15    20
    /  \
  40    50
 /  \
30   50
```

**Complete binary tree:** son düzey hariç tüm düzeylerin tam dolu olduğu ve son düzeyin de en soldan dolduğu ikili ağaçtır.

```text
          18
        /    \
      15      30
     /  \    /  \
   40   50 100   40
  / \   /
 8   7 9
```

Bu ağaçta ilk üç seviyedeki bütün gözler doludur; dördüncü seviye soldan başlanarak doldurulmuştur. Bu yüzden complete'tir. Ama full değildir, çünkü 50'nin yalnız bir çocuğu vardır. Hoca 50'nin altına bir 25 daha eklendiğinde ağacın hem full hem complete olacağını gösterdi.

> **Hocanın vurgusu:** Complete binary tree kavramı önemlidir, çünkü heap'ler complete binary tree olacaktır.

**Perfect binary tree:** tüm iç düğümlerin iki çocuğu vardır ve tüm yapraklar aynı seviyededir. Hocanın örneğinde kökün iki çocuğu, onların da ikişer çocuğu, toplam dört yaprak vardır ve bütün yapraklar aynı seviyededir. Perfect ağaç aynı zamanda hem full hem complete'tir; son seviyesinin de tam dolu olması onu özel kılar.

**Balanced (dengeli) binary tree:** $n$ düğümlü ağacın yüksekliği $\log n$ mertebesinde kalıyorsa ağaç dengelidir. Perfect ağaç aynı zamanda dengelidir. Yükseklik $\log n$'den fazlaysa ağaca **degenerate** ya da **pathological binary tree** denir.

En kötü durum, dizi gösterimindeki p, r, v, z örneğidir: 4 düğüm vardır ve yükseklik 3'tür; bu $\log n$ mertebesinde değildir. Aynı 4 düğüm dengeli yerleştirilseydi yükseklik 2 olurdu (hoca hesabı derste tam yapamadığını söyledi; bkz. Örnek Sorular). Degenerate ağaç aslında bağlı listeye dönüşür, ağaç olmaktan çıkıp düz bir zincir olur.

### 8.1 Ağacın etkinliği nereden gelir?

Perfect ya da complete ağaçta yükseklik $\log n$ mertebesinde kalır. Kök işaretçisinden başlayarak sağ ya da sol çocuğa inerek bir yaprağa ulaşmak için en fazla yükseklik kadar, yani $\log n$ hamle gerekir. Hoca slayttaki complete ağaç üzerinden örnek verdi: 100'e erişmek için 18'in sol tarafıyla, sonra 30'un sağ tarafıyla hiç ilgilenmeye gerek kalmaz. Ağaç 10–20 seviyeli olsaydı da yalnız $\log n$ karşılaştırmayla bir düğüme ulaşılabilirdi. Bu yüzden arama yöntemlerinde ve hızlı erişim gerektiren indeks mekanizmalarında hep ağaç yapıları kullanılır.

Degenerate ağaçta ise 4 elemanlı zincirin sonuna erişmek için 4 adım gerekir (köke gel 1, sonra 2, 3, 4); bu $O(n)$'dir. Dengeli dağılmış olsaydı en fazla 3 adım yeterdi. Hoca 4 yerine 3'ün küçük bir fark gibi görünebileceğini, ama seviye sayısı arttıkça $\log n$ mertebesinin büyük fayda sağladığını söyledi. Slayttaki başka bir patolojik örnekte kökten hep sola gidilerek bir zincir oluşur; dengeli ağaçta ise aynı E değerine iki adımda ulaşılır.

Ağacı dengeli tutmanın yolları vardır, ama bu ders kapsamında yalnız adları verilecektir. Hoca bunlara girerse konunun bitmeyeceğini, merak edenlerin araştırabileceğini söyledi.

## 9. İkili Ağaçta Ekleme ve Silme

### 9.1 Ziyaret ve ekleme

Bu slayttaki yapı aynıdır, yalnız düğümler bu kez tamsayı yerine karakter tutar. `createTree` ile verisi örneğin 'A' olan ve iki işaretçisi `NULL` olan ilk ağaç oluşturulur. Ağacın bir düğümünü gezmek için `visit` adlı bir fonksiyon tanımlanabilir; en basitinden düğümdeki değeri ekrana yazar, ama içinde o değerle yapılması gereken her şey yazılabilir.

Eleman eklerken bir düzen kurgulamak gerekir. Örneğin "değer atasından büyükse sağına, küçükse soluna ekle" kuralı konabilir. Hoca bu kuralla şu harfleri sırayla ekledi:

- K ilk gelir ve kök olur.
- D, K'den küçük olduğu için K'nin soluna eklenir.
- M, K'den büyük olduğu için K'nin sağına eklenir.
- R: K'den büyük → sağa, M'den büyük → sağa; M'nin sağ çocuğu olur.
- L: K'den büyük → sağa, M'den küçük → sola; M'nin sol çocuğu olur.
- N: K'den büyük, M'den büyük, R'den küçük; R'nin sol çocuğu olur.
- A: K'den küçük, D'den küçük; D'nin sol çocuğu olur.

```text
        K
      /   \
     D     M
    /     / \
   A     L   R
            /
           N
```

Bunun için özyinelemeli bir çağrı gerekir. Ağaç boşsa (düğüm `NULL` ise) yeni düğüm oluşturulur. Veri düğümün verisinden küçükse "git sol alt ağaçta eklemeyi yap", büyükse "git sağ alt ağaçta eklemeyi yap" denir. Bu, `NULL` görülene kadar sürer; orada yeni düğüm oluşturulur ve `return node` sayesinde ebeveynin işaretçisine bağlanır. Kod (ekrandan, 01:35:00):

```c
tree insert(tree node, char data){
      if (node == NULL) return createTree(data);

      if(data < node->data)
            node->left = insert(node->left, data);
      else if (data > node->data)
            node->right = insert(node->right, data);

      return node;
}
```

N örneğinde olduğu gibi sağa git, sağa git, sola git, boş yere gelince yarat.

### 9.2 Silme ve üç durum

Silme daha karmaşıktır, çünkü birkaç durum oluşabilir. Önce silinecek düğüm bulunmalıdır. Ağaç boşsa `NULL` döndürülür. Küçükler solda, büyükler sağda düzeni kurulduğu için arama da aynı kuralla yapılır. Örneğin L'yi silmek için: L, K'den büyük → sağda sil; L, M'den küçük → solda sil; L bulunur. Kod (ekrandan, 01:40:00):

```c
tree del(tree root, char data){
      if (root==NULL) return root;

      // silinecek küçükse soldadır
      if(data < root->data)
            root->left = del(root->left, data);
      //silinecek büyükse sağdadır
      else if(data > root->data)
            root->right = del(root->right, data);
      // bu nodu sileceğiz
      else{
            //node with 1 or 0 child
            if (root->left == NULL){
                  tree temp = root->right;
                  free(root);
                  return temp;
            }
            else if (root->right == NULL){
                  tree temp = root->left;
                  free(root);
                  return temp;
            }
            tree temp = minValueNode(root->right);
            root->data = temp->data;

            root->right = del(root->right, temp->data);
      }
      return root;
}
```

Üç durum şöyledir:

1. **Silinecek düğüm yapraktır:** hiç çocuğu yoktur, doğrudan `free` edilir. Örnekte L böyledir.
2. **Tek çocuğu vardır:** düğüm silinirken çocuğu ortada bırakılamaz. Çocuk geçici bir değişkenle tutulur, düğümün atasına (dedesine) bağlanır ve düğüm `free` edilir. Örnekte R silinirken çocuğu N, M'ye bağlanır.
3. **İki çocuğu vardır:** örnekte M'nin hem sol (L) hem sağ (R, N) alt ağacı vardır. Büyüklük-küçüklük düzenini bozmamak için iki yaklaşım vardır:
    - Sol alt ağacın en büyük elemanını alıp silinecek düğümün yerine yazmak. M'nin yerine L yazılırsa K, L, R, N düzeni bozulmaz: R L'den büyük olduğu için sağında, N R'den küçük olduğu için solunda kalır.
    - Sağ alt ağacın en küçük elemanını (sağ alt ağaçta gidilebildiği kadar sola giderek bulunur) alıp yerine yazmak. M'nin yerine N yazılırsa L yine N'den küçük, R yine N'den büyük kalır.

İki yol da geçerlidir. Slayttaki kod sağ alt ağacın en küçüğünü (`minValueNode`) alıp düğümün yerine yazar, sonra o değeri sağ alt ağaçtan yine `del` çağırarak siler. Birinci ve ikinci durumlar kodda aynı biçimde ele alınır: sol çocuk `NULL` ise sağ çocuk, sağ çocuk `NULL` ise sol çocuk yukarı bağlanır; yaprakta ikisi de `NULL` olduğu için sonuç `NULL` olur.

Hoca özetle şunu söyledi: eklemede dikkat edilecek tek şey bir düzen kararı vermektir; genellikle küçükler sola, büyükler sağa eklenir. Silmede ise üç durum ayrı ayrı düşünülmeli, iki çocuklu düğümde kopyalanan düğüm de özyinelemeli olarak alttan silinmelidir.

## 10. Derinlik Öncelikli Gezintiler

### 10.1 Gezinti nedir, hangi sıralar mümkündür?

Gezinti (traversal), ağaçtaki bütün düğümlere birer kez erişmek, yani her değeri bir kez "ziyaret etmek" (visit) demektir. İki temel yaklaşım vardır: **derinlik öncelikli** gezintide önce derinlere inilip sonra yukarı çıkılır; **genişlik öncelikli** gezintide önce bir seviye bitirilir, sonra bir alttaki seviyeye geçilir.

Bir düğümde yapılabilecek üç hamle vardır:

- **L (left):** sol işaretçinin gösterdiği sol alt ağaca gitmek.
- **V (visit):** üzerinde bulunulan düğümü ziyaret etmek, yani verisini kullanmak.
- **R (right):** sağ alt ağaca gitmek.

Bu üç hamlenin altı sıralaması vardır: LVR, LRV, VLR, VRL, RVL, RLV. Hoca ağacı ortadan bölüp ayna görüntüsünü alarak bazılarının aynı olduğunu gösterdi: VLR ile VRL, LVR ile RVL, LRV ile RLV birbirinin ayna görüntüsüdür; ağaç aynalandığında aynı gezinti yapılmış olur. Bu yüzden her çiftten birini, önce sola bakılan sırayı seçmek yeterlidir:

- **LVR:** ziyaret ortada olduğu için **inorder** (kök ortada) gezinti.
- **LRV:** ziyaret sonda olduğu için **postorder** (kök sonda) gezinti.
- **VLR:** ziyaret önde olduğu için **preorder** (kök önde) gezinti.

Genişlik öncelikli gezintiye daha sonra dönüldü.

### 10.2 Preorder (kök önde) gezinti

Slayttaki temel fikir (ekrandan, 01:50:00):

1. Kökü ziyaret et.
2. Özyineli olarak sol alt ağacı kök önde dolaş.
3. Özyineli olarak sağ alt ağacı kök önde dolaş.

Örnek ağaç:

```text
          60
        /    \
      20      70
     /  \
   10    40
        /  \
      30    50
```

Adım adım (hocanın anlatımından):

- 60 ziyaret edilir (1.). Sonra sol alt ağaca gidilir.
- 20'de yine V-L-R uygulanır: 20 ziyaret edilir (2.), sonra soluna gidilir.
- 10 ziyaret edilir (3.). 10'un solu ve sağı yoktur; 10 için VLR biter, 20'ye dönülür.
- 20'nin ziyareti ve solu bitti; sağına, 40'a gidilir. 40 ziyaret edilir (4.).
- 40'ın soluna gidilir: 30 ziyaret edilir (5.); solu ve sağı yok, 40'a dönülür.
- 40'ın sağına gidilir: 50 ziyaret edilir (6.); solu ve sağı yok, geri dönülür.
- 40 bitti, 20 bitti; 60'a dönülür. 60'ın solu bitti, sağına gidilir: 70 ziyaret edilir (7.).

Sonuç: **60, 20, 10, 40, 30, 50, 70** (ekrandan, 01:55:00).

Kod üç satırdır. Özyinelemenin durması için önce `T` `NULL` ise geri dönülür; bu, "solu yok, sağı yok" durumlarıdır. Sonra düğüm ziyaret edilir, sonra fonksiyon sol çocuk, sonra sağ çocuk için kendini çağırır:

```c
void preTraverse(tree T){
    if (T == NULL) return;
    visit(T);
    preTraverse(T->left);
    preTraverse(T->right);
}
```

<!-- BELİRSİZ: Preorder, inorder ve postorder kodlarının slaytları karelerde yok; kod hocanın anlatımından kurulmuştur ("t eşittir nullsa return", "visit T", "pre-traverse soldaki düğüm", "pre-traverse sağdaki düğüm"). Fonksiyon adları slayttakinden farklı olabilir. -->

### 10.3 Inorder (kök ortada) gezinti

Slayttaki temel fikir (ekrandan, 02:10:00):

1. Özyineli olarak sol alt ağacı kök ortada dolaş.
2. Kökü ziyaret et.
3. Özyineli olarak sağ alt ağacı kök ortada dolaş.

Kod aynıdır, yalnız ziyaret ortaya alınır:

```c
void inTraverse(tree T){
    if (T == NULL) return;
    inTraverse(T->left);
    visit(T);
    inTraverse(T->right);
}
```

Aynı ağaçta adım adım:

- 60'tan başlanır ama ziyaret edilmez; soluna, 20'ye gidilir. 20 de ziyaret edilmez; soluna, 10'a gidilir.
- 10'un solu `NULL`, geri dönülür; 10 ziyaret edilir (1.). Sağı `NULL`; 10 biter.
- 20'ye dönülür: solu bitti, 20 ziyaret edilir (2.). Sonra sağına, 40'a gidilir.
- 40 ziyaret edilmeden soluna, 30'a gidilir: solu `NULL`, 30 ziyaret edilir (3.), sağı `NULL`.
- 40'a dönülür: solu bitti, 40 ziyaret edilir (4.). Sağına, 50'ye gidilir: solu `NULL`, 50 ziyaret edilir (5.), sağı `NULL`.
- 40 ve 20 biter; 60'a dönülür. 60'ın solu bitti, 60 ziyaret edilir (6.).
- Sağına, 70'e gidilir: solu `NULL`, 70 ziyaret edilir (7.), sağı `NULL`. Bitti.

Sonuç: **10, 20, 30, 40, 50, 60, 70**. Hoca slayttaki düğüm numaralarının bu gezinti için yanlış durduğunu söyleyip ziyaret sırasını kırmızı kalemle yeniden numaralandırdı.

### 10.4 Postorder (kök sonda) gezinti

Slayttaki temel fikir (ekrandan, 02:15:00):

1. Özyineli olarak sol alt ağacı kök sonda dolaş.
2. Özyineli olarak sağ alt ağacı kök sonda dolaş.
3. Kökü ziyaret et.

```c
void postTraverse(tree T){
    if (T == NULL) return;
    postTraverse(T->left);
    postTraverse(T->right);
    visit(T);
}
```

Adım adım:

- 60 → sol 20 → sol 10: solu `NULL`, sağı `NULL`, 10 ziyaret edilir (1.).
- 20'ye dönülür; solu bitti, sağına, 40'a gidilir. Önce sol: 30'un solu ve sağı `NULL`, 30 ziyaret edilir (2.).
- 40'a dönülür, sağına gidilir: 50 ziyaret edilir (3.). 40'ın solu ve sağı bitti, 40 ziyaret edilir (4.).
- 20'nin solu ve sağı bitti, 20 ziyaret edilir (5.).
- 60'a dönülür; sağına gidilir: 70 ziyaret edilir (6.). 60'ın solu ve sağı bitti, 60 ziyaret edilir (7.).

Sonuç: **10, 30, 50, 40, 20, 70, 60**. Hoca RLV sırasının bunun ayna görüntüsü olduğunu, ayrıca anlatmaya ya da gerçeklemeye gerek olmadığını tekrarladı. Bu üç gezinti de önce derinlemesine gider.

## 11. Alternatif Gezintiler: Yığıt ve Kuyruk ile

### 11.1 Yığıt ile inorder gezinti

Inorder gezinti özyinelemeli çağrı yapmadan bir yığıt (stack) kullanılarak da yapılabilir. Hoca burada yapılan tek şeyin, fonksiyon çağrı yığıtına (function call stack) basılan şeyi açık bir yığıta basmak olduğunu söyledi. Hocanın anlattığı sözde kodun mantığı:

```text
current = root
döngü:
    current NULL olmadıkça:
        current'ı yığıta it (push)      // daha ziyaret etmedim, unutmamak için
        current = current->left          // sola, sola, sola
    current NULL ve yığıt boş değilse:
        x = yığıttan çek (pop)
        x'i ziyaret et (print)
        current = x->right
yığıt boş ve current NULL olunca bitir
```

<!-- BELİRSİZ: Yığıtlı inorder sözde kodunun slaytı karelerde yok; yukarıdaki yapı hocanın sözlü anlatımından kurulmuştur, slayttaki satır düzeni farklı olabilir. -->

Ajan bu mantığı küçük bir C programıyla örnek ağaç üzerinde denedi; sonuç özyinelemeli inorder ile aynı çıktı: 10, 20, 30, 40, 50, 60, 70.

### 11.2 Genişlik öncelikli (seviye sıralı) gezinti

Slayttaki ifadeler (ekrandan, 02:20:00):

- Genişlik öncelikli gezinti (seviye sıralı gezinti): her seviyede inorder gezinti yapılır; kuyruk ile gerçekleştirilebilir.
- Kuyruk boşalıncaya kadar yinele; ağacı seviye sırasında soldan sağa dolaş:
    - Kökü dolaş ve evlatlarını soldan sağa kuyruğa ekle.
    - Kuyruktan bir düğüm al, dolaş, evlatlarını kuyruğa ekle.

Hoca yığıt yerine kuyruk (FIFO) kullanıldığında bir seviyelendirme yapılmış olacağını ve işlemin kuyruk boşalana kadar bir `while` döngüsüyle tekrarlanacağını söyledi.

Örnek ağaç:

```text
            f
         /     \
        c       j
       / \     / \
      a   d   h   k
              |
              i
```

Kuyruğun adım adım durumu (hoca bunu slaytın yanına yazdı):

| Adım | Kuyruktan çekilen | Kuyruğa eklenen | Kuyruk |
|---|---|---|---|
| 0 | – | f | f |
| 1 | f | c, j | c, j |
| 2 | c | a, d | j, a, d |
| 3 | j | h, k | a, d, h, k |
| 4 | a | – | d, h, k |
| 5 | d | – | h, k |
| 6 | h | i | k, i |
| 7 | k | – | i |
| 8 | i | – | boş |

Ziyaret sırası: **f, c, j, a, d, h, k, i**. Önce birinci seviye, sonra ikinci, üçüncü ve dördüncü seviye soldan sağa gezilmiştir.

> **Hocanın vurgusu:** Yığıt kullanıldığında derinlemesine, kuyruk kullanıldığında enlemesine gidilir. LIFO ile FIFO arasındaki fark, ağaç gezerken tek bir veri yapısı değişikliğiyle derinlik temelli gezintiden seviye temelli gezintiye geçmeyi sağlar. Önceki haftaların veri yapıları üst üste konarak kullanılmaya devam edilmektedir.

> **Ders sonrası not:** Slaytta "her seviyede inorder gezinti yapılır" yazıyor ve hoca yığıtlı inorder kodunda yığıt yerine kuyruk konmasını söyledi. Seviye sıralı gezintide her seviye yalnız soldan sağa gezilir; yöntem de tam olarak tablodaki gibidir: kuyruktan bir düğüm çek, ziyaret et, çocuklarını soldan sağa kuyruğa ekle. Yığıtlı inorder kodunda yalnız `push`/`pop` yerine `enqueue`/`dequeue` yazmak bu sırayı vermez. Ajanın küçük bir C programıyla yaptığı denemede tablodaki yöntem f, c, j, a, d, h, k, i sırasını verdi.

## 12. Gezintilerin Uygulamaları: Kopyalama ve Eşitlik

### 12.1 Ağacı kopyalama

Bir ağacı başka bir ağaca kopyalamak için gezinti kullanılır. Hoca bunun için postorder gezintinin uygun olduğunu söyledi: önce bütün sol ve sağ alt ağaçların keşfedilmesi, ağacın yapısının öğrenilmesi gerekir; ondan sonra kopyalama işlemi (yani "ziyaret") yapılır. Hocanın anlattığı fonksiyonun mantığı:

- Orijinal ağacın kökü parametre olarak verilir. `NULL` ise `NULL` döndürülür.
- `NULL` değilse `malloc` ile geçici (kopya) düğüm oluşturulur. Hoca bellek kontrollerinin öğrenciye bırakıldığını söyledi.
- Kopyanın solu, orijinalin solu için fonksiyon kendini çağırarak; sağı, orijinalin sağı için kendini çağırarak oluşturulur.
- Son olarak orijinal düğümün verisi kopya düğüme atanır ve kopya döndürülür.

<!-- BELİRSİZ: Kopyalama kodunun slaytı karelerde yok; fonksiyon ve değişken adları (copy tree, temp, original) altyazıdan alınmıştır. -->

Postorder gezinti örneğindeki ağaçta düğümler sırasıyla 10, 30, 50, 40, 20, 70 ve en son 60 kopyalanır.

### 12.2 İki ağacın eşitliğini kontrol etme

İki ağacın eşit olup olmadığını kontrol eden bir fonksiyon (hocanın deyişiyle "is equal tree") iki ağaç alır. Hocanın anlattığı dönüş ifadesinin mantığı şudur: iki ağaç da boşsa eşittir; değilse ikisi de tanımlı olmalı, düğüm verileri eşit olmalı, fonksiyon iki ağacın sol çocuklarıyla ve sağ çocuklarıyla kendini çağırdığında ikisi de eşit sonuç vermelidir.

<!-- BELİRSİZ: Eşitlik kodunun slaytı karelerde yok; koşulların sırası ve yazımı altyazıdan tam çıkmıyor. -->

Hoca yanına ikinci bir ağaç çizdi: 60; 20, 70; 10, 45; 30, 50. Bu, gezinti örneğindeki ağacın 40 yerine 45 içeren hâlidir. Hoca bu kontrolü preorder mantığıyla yapmanın daha doğru olacağını söyledi: önce düğümler karşılaştırılır (60 = 60, devam; sola git, 20 = 20; 10 = 10; geri gel, sağa git), 40 ile 45 karşılaştırılınca eşitsizlik yakalanır. Eşitsizlik bulunduğu anda ağaçların geri kalanını gezmeye gerek kalmaz; 0 döndürülür ve bu sonuç yukarı doğru yayılır.

Hocanın bu bölümden çıkardığı ders: farklı işlemler farklı önceliklendirme gerektirir. Kopyalarken önce alt ağaçlar bulunur, sonra düğüm işlenir; eşitlik kontrolünde önce düğüme bakılır, sonra derinlere inilir.

## 13. Genel Ağacı İkili Ağaç Olarak Gösterme

Çok çocuklu (M-ary) ağaçlar aslında ikili ağaç olarak ifade edilebilir. Gereken yalnız iki işaretçidir: "ilk çocuğum kimdir" ve "kardeşim kimdir". Hoca önce Wikipedia'dan alındığını hatırladığı bir örnek gösterdi. Bu örnekte A'nın ilk çocuğu B'dir; B'nin kardeşleri C, D, E, F, G bir bağlı liste gibi sıralanır. B'nin ilk çocuğu H, H'nin kardeşleri I ve J'dir. E'nin ilk çocuğu K, K'nin kardeşi L'dir; G'nin tek çocuğu M'dir. K'nin çocuğu P, L'nin çocuğu Q'dur. Böylece her düğümden en fazla iki kenar çıkar ve ağaç ikili ağaç olarak tutulur.

<!-- BELİRSİZ: Bu örneğin ağaç şekli karelerde yok; düğüm adları ve ilişkiler altyazıdan alınmıştır, bazı harfler (özellikle N ve O düğümleri) altyazıda net değil. -->

İkinci örnek hocanın elle çizdiği slayttır (ekrandan, 02:30:00). Düğüm yapısı `[veri | çocuk | kardeş]` biçimindedir; çocuk işaretçisi aşağı, kardeş işaretçisi yana çizilir.

Genel ağaç:

```text
                 v0
       /      /      \      \
     v1      v2       v3     v4
    /  \            /  |  \
  v5    v6        v7   v8  v9
                  |
                 v10
```

İlk çocuk ve kardeş işaretçileriyle gösterimi:

| Düğüm | İlk çocuk | Sağdaki kardeş |
|---|---|---|
| v0 (kök) | v1 | yok |
| v1 | v5 | v2 |
| v2 | yok | v3 |
| v3 | v7 | v4 |
| v4 | yok | yok |
| v5 | yok | v6 |
| v6 | yok | yok |
| v7 | v10 | v8 |
| v8 | yok | v9 |
| v9 | yok | yok |
| v10 | yok | yok |

Hoca "vertex"in düğüm demek olduğunu, literatürde düğüm ve kenar için çoğunlukla vertex ve edge terimlerinin kullanıldığını, derste ise bağlı liste düğümleriyle gerçekleştirdikleri için "node" dediklerini belirtti. Bu gösterimde seviye sayısı artar (v0'dan v10'a giden yolda 3 seviye yerine 5 seviye oluşur), ama bunun dışında bir kayıp olmadan ikili ağaçta yapılan bütün işlemler genel ağaçlarda da yapılabilir.

## 14. İkili Arama Ağacı

### 14.1 Tanım

İkili ağacın bir uygulaması ikili arama ağacıdır (binary search tree, BST). Derste temel hâli görüldü; dengeyi ve $\log n$ mertebesinde kalmayı garanti eden çeşitleri anlatılmayacak, ama kötü duruma nasıl gidilebildiği görülecektir.

Slayttaki tanım (ekrandan, 02:35:00): ikili arama ağacı, her A düğümünün şu özellikleri taşıdığı ağaçtır:

- A'nın değeri sol alt ağacındaki ($T_L$) düğümlerin değerlerinden büyüktür.
- A'nın değeri sağ alt ağacındaki ($T_R$) düğümlerin değerlerinden küçüktür.
- $T_L$ ve $T_R$ de birer ikili arama ağacıdır.

Özyinelemeli olarak yapraklara kadar her sol ve sağ alt ağaç ikili arama ağacıysa ağacın tamamı da ikili arama ağacıdır. Değerlerin sayı olması gerekmez; slayttaki ilk örnek alfabetik sıralı adlarla kurulmuştur (kökte K harfiyle başlayan bir ad; solunda B, sağında S ile başlayan adlar; B'nin solunda A, S'nin solunda M, sağında T ile başlayan adlar). İkinci örnek sayısaldır:

```text
          21
        /    \
       3      34
      / \       \
     2   8       55
        / \
       5   13
```

21, solundaki her değerden büyük, sağındaki 34 ve 55'ten küçüktür.

Alfabetik örnekte M ile başlayan adı aramak için kök, ardından S ile başlayan ad, ardından aranan ad görülür: üç karşılaştırma yeter. Teker teker baksaydık $O(n)$ bakış gerekirdi. İkili arama ağacında yapılacak karşılaştırma sayısı ağacın seviyesi kadardır, yani $\log n$ mertebesindedir. Hoca "$\log n$ varken neden $n$ karmaşıklık kullanayım?" diye sordu.

### 14.2 Hangileri ikili arama ağacıdır?

Hoca slayttaki üç ağacı tek tek kontrol etti:

- Kök 20; çocukları 15 ve 25; 15'in çocukları 12 ve 10 (10 sağda). 10, 15'ten küçük olduğu halde sağdadır; bu yüzden **ikili arama ağacı değildir**.
- Kök 30; çocukları 5 ve 40; 5'in sol çocuğu 2. Düzen doğrudur; **ikili arama ağacıdır**.
- Kök 60, sol alt ağacı yok; sağında 70; 70'in çocukları 65 ve 80. Düzen doğrudur; **ikili arama ağacıdır**, ama sol tarafın hiç olmaması istenen bir şey değildir.

<!-- BELİRSİZ: Bu üç ağacın slaytı karelerde yok; ağaç şekilleri altyazıdaki anlatımdan kurulmuştur. -->

**Soru:** İkili aramada genelde ortadaki sayıdan başlarız. Sağdaki (kökü 60 olan) ağaçta bu yapı bozulmuş olmuyor mu, yine $\log n$ karmaşıklıkta mı arama yapıyoruz?

**Cevap:** Hoca bunun dejenere bir ağaç olduğunu, iyi bir ikili arama ağacı değil kötü bir örnek olduğunu söyledi. Ama genele bakıldığında düzgün oluşturulmuş bir ikili arama ağacı ortalamada $\log n$ mertebesinde kalır. Dengeli tutmanın birden fazla yolu vardır; derste yalnız adları verilecektir.

### 14.3 Arama

Arama özyinelemelidir: aranan veri o anki kökün verisinden küçükse sol alt ağaçta, büyükse sağ alt ağaçta aranır. Eşitse ya da kök `NULL` ise iki durumda da kök döndürülür: `NULL` döndürülmüşse bulunamadı, bir düğüm döndürülmüşse bulundu demektir.

<!-- BELİRSİZ: Arama kodunun slaytı karelerde yok; mantık altyazıdan alınmıştır. -->

Yukarıdaki sayısal ağaçta:

- **21'i ara:** 21, 21'den ne küçük ne büyük; kök döndürülür, bulundu.
- **8'i ara:** 8 < 21 → sola, kök 3. 8 > 3 → sağa, kök 8. Ne küçük ne büyük; 8 döndürülür.
- **80'i ara:** 80 > 21 → sağa, 34. 80 > 34 → sağa, 55. 80 > 55 → sağa; orası `NULL`. `NULL` döndürülür, 80 bulunamadı.

Başka bir slaytta (kök 44) iki arama daha gösterildi:

- **25'i ara:** 25 < 44 → sola (17); 25 > 17 → sağa (32); 25 < 32 → sola (28); 25 < 28 → sola; `NULL`. 25 yok.
- **76'yı ara:** 76 > 44 → sağa (88); 76 < 88 → sola (65); 76 > 65 → sağa (82); 76 < 82 → sola (76); eşit, 76 döndürülür.

<!-- BELİRSİZ: Kökü 44 olan ağacın tamamı karelerde yok; yalnız arama yollarındaki düğümler altyazıdan alınmıştır. -->

### 14.4 Ekleme

İkili arama ağacına ekleme, bölüm 9.1'deki `insert` ile birebir aynıdır: değer düğümün değerinden küçükse sola gidilip oraya, büyükse sağa gidilip oraya eklenir; `NULL`'a gelinince yeni düğüm yaratılır ve düğüm ağaca döndürülür. Hoca bunun işin kolay tarafı olduğunu söyledi.

### 14.5 Silme ve görsel örnekler

Silme örnekleri şu ağaçta gösterildi:

```text
          94
        /    \
      10      97
     /  \
    5    24
        /
      11
        \
         17
```

Hoca bu ağacın da dejenere olduğunu, daha dengeli kurulsaydı $\log n$'de kalmanın garanti edileceğini söyledi.

**Yaprak silme (5):** 5 < 94 → sola; 5 < 10 → sola; 5 bulunur. Çocuğu olmadığı için doğrudan `free` edilir.

**Tek çocuklu düğüm silme (24, sol çocuğu var):** 24 < 94 → sola; 24 > 10 → sağa; 24 bulunur. Altında 11 ve 17 vardır ve bunlar kaybolmamalıdır. 24 geçici bir değişkenle gösterilir, çocuğu (11) 24'ün ebeveynine (10) bağlanır ve 24 serbest bırakılır. Artık 10'un sağ çocuğu 11'dir (ekrandan, 02:45:00). Hoca bunu "çocuk başıboş kalmasın diye dedesine bağlıyoruz" diye anlattı.

**Tek çocuklu düğüm silme (11, sağ çocuğu var):** sonraki slaytta 11 silindi. Yapılan iş aynıdır: çocuğu (17) 11'in ebeveynine (24) bağlanır, 11 serbest bırakılır. 24 ve 17 ile hiyerarşi bozulmaz.

**İki çocuklu düğüm silme (10):** hoca örneği zenginleştirmek için 5'in sağına 9, 9'un soluna 8 ekledi:

```text
          94
        /    \
      10      97
     /  \
    5    24
     \   /
      9 11
     /    \
    8      17
```

10'un hem sol hem sağ alt ağacı vardır. İki yol vardır:

- **Sol alt ağacın en büyüğü:** 9'dur. 9, 10'un yerine kopyalanır; solundakiler hep 9'dan küçük, sağındakiler hep 9'dan büyük kalır. Sonra aşağıdaki 9 silinmelidir; 9'un tek çocuğu (8) olduğu için 8, 5'e bağlanır. Sonuçta kökün solunda 9 vardır; 9'un solunda 5 ve 8, sağında 24, 11, 17 kalır; düzen bozulmaz.
- **Sağ alt ağacın en küçüğü:** sağ alt ağaç 24, 11, 17'dir; en küçüğü 11'dir. 11, 10'un yerine kopyalanır. Aşağıda kalan 11'in kopyası silinmelidir; tek çocuğu (17) olduğu için 17, 24'e bağlanır ve 11 serbest bırakılır.

Hoca ikinci yolu genellikle daha çok tercih ettiğini, bunun özel bir sebebi olmadığını, ikisinin de aynı olduğunu söyledi. Kopyalanan düğümün de iki alt ağacı olabileceği için silme özyinelemeli gerçeklenmelidir.

> **Ders sonrası not:** Hoca sağ alt ağacın en küçüğünü anlatırken bir an "sol ağacına bakıyorum, 24, 11, 17" dedi. 24, 11, 17 10'un **sağ** alt ağacıdır; anlatımın devamı da sağ alt ağacın en küçüğüne göredir.

Ajanın küçük bir C programıyla yaptığı denemede (slayttaki `insert` ve `del` mantığıyla) 94, 10, 97, 5, 24, 11, 17, 9, 8 sırayla eklenip 10 silindiğinde ağacın preorder sırası 94, 11, 5, 9, 8, 24, 17, 97 oldu; bu, sağdaki en küçüğün (11) kopyalandığı sonuçtur.

### 14.6 findMin, findMax ve BST silme kodu

İki çocuklu silmede gereken yardımcı fonksiyonlar (ekrandan, 02:50:00):

```c
tree findMin(tree T){
   if(T && T->left)
      return findMin(T->left);
   else
      return T;
}
tree findMax(tree T){
   if(T && T->right)
      return findMax(T->right);
   else
      return T;
}
```

En küçük eleman gidilebildiği kadar sola, en büyük eleman gidilebildiği kadar sağa gidilerek bulunur. Hoca bu slayt için öğrencilerin videoyu durdurup kodu incelemesini önerdi.

Ardından BST silme kodunun üzerinden geçildi. Mantığı bölüm 9.2'deki `del` ile aynıdır: kök `NULL` ise `NULL` döndürülür; bu, özyinelemenin durduğu noktadır ve ilk kontrol mutlaka bu olmalıdır. Veri küçükse silme sol alt ağaçta, büyükse sağ alt ağaçta çağrılır. Düğüm bulunduğunda iki çocuğu varsa sağ alt ağacın en küçüğü bulunup verisi düğüme yazılır, sonra sağ alt ağaçta o değer için silme yeniden çağrılır; bu sayede kopyalanan düğüm yaprak da olsa, tek çocuklu da olsa özyinelemeli olarak doğru silinir. Tek çocuk ya da hiç çocuk yoksa sol ya da sağ alt ağaç döndürülerek sonuç ağacı geri verilir.

<!-- BELİRSİZ: BST silme kodunun slaytı karelerde yok (karede yalnız findMin/findMax var); yapının bölüm 9.2'deki koda benzediği altyazıdan anlaşılıyor, satır düzeni farklı olabilir. -->

### 14.7 Yükseklik, denge ve karmaşıklık

İkili arama ağacının yüksekliği elemanların geliş sırasına, yani şansa bağlıdır. Örneğin 10, 20, 30, 40 sırasıyla gelen değerler hep sağa eklenir; $n$ eleman için $n$ yükseklikte bir zincir oluşur ve diğer taraflar boş kalır. Hoca bunu "berbat bir yapı" diye niteledi. Ekleme ve silmeler rastgele değerlerle, rastgele sırayla yapılırsa ağaç ortalamada $\log n$ yükseklikte ya da ona yakın kalır; $n$ eleman için $\log n$ yükseklikteki ağaca dengeli ikili arama ağacı denir.

> **Hocanın vurgusu:** İkili arama ağacında arama ortalamada $O(\log n)$, en kötü durumda $O(n)$'dir. Geldiği sırayla yerleştirilen basit ikili arama ağaçlarında en kötü durum $O(n)$'dir. Big-O'da hep en kötü durum düşünüldüğü için böyle söylenir.

Hoca bu noktanın, daha önce soru soran öğrencinin söylediği şey olduğunu belirtti. Bunu engellemek için ekleme ve silme sırasında bir dengeleme politikası gerekir. En basit örnek: 10 ve 20 geldikten sonra 30 gelince, düz mantıkla 30 20'nin sağına konup yükseklik 2 olurdu. Bunun yerine 30 eklendiği anda ağaç 20 kökte olacak şekilde düzenlenirse 10 solda, 30 sağda kalır. Sonra 40 ve 50 geldiğinde de benzer düzenlemelerle yükseklik düşük tutulabilir; hocanın çizdiği örnekte üç seviye yerine iki seviyede kalındı.

Bu tür dengeleme yaklaşımlarıyla yapılmış ikili arama ağacı çeşitleri: AVL ağaçları, B-ağaçları, 2-3 ve 2-3-4 ağaçları, red-black ağaçları ve splay ağaçları. Hoca merak edenlerin en basitleri olan AVL ağaçlarına (biraz önceki 10-20-30 örneğindeki gibi döndürme yapan) ve red-black ağaçlarına bakabileceğini, bunlardan sorumlu olunmadığını belirtti.

Derste elemanların rastgele geldiği, ekleme ve silmelerin rastgele yapıldığı varsayıldığı için ikili arama ağacıyla aramanın $\log n$ mertebesinde olduğu söylenir.

> **Hocanın vurgusu:** Bir problemde verilen ağaç aksi söylenmedikçe dengeli kabul edilir ve aramanın $O(\log n)$ olduğu varsayılabilir. Özellikle "dengesiz ağaç" denirse $O(n)$ düşünülmelidir.

Hoca son olarak ikili arama ağacını kendilerinin gerçeklemesini, kodlarını yazmalarını önerdi: ekleme ve silme mantığı, sol ve sağ alt ağaçları gezen işaretçiler ve inorder, preorder, postorder gezintilerinin nasıl çalıştığı birinci elden deneyerek daha iyi öğrenilir.

## Örnek Sorular

### Soru 1: Yükseklik ve en fazla düğüm sayısı

(ekrandan, 00:45:00; derste sözlü, 00:51:52) Yüksekliği $h$ olan bir ikili ağaçta en fazla kaç düğüm olabilir? Slaytta $2^h - 1$ yazıyordu; doğru mu?

**Çözüm (derste verildi):** Doğrusu $2^{h+1} - 1$'dir. Yalnız A, B, C'den oluşan ağacın yüksekliği 1'dir ve 3 düğümü vardır: $2^{1+1} - 1 = 3$. Yüksekliği 2 olan dolu ağaçta 7 düğüm vardır: $2^3 - 1 = 7$. Genel olarak $0, 1, \dots, h$ seviyelerinde $1 + 2 + \dots + 2^h = 2^{h+1} - 1$ düğüm bulunur (ara adım eklendi).

### Soru 2: Örnek ağacın kavramları

(ekrandan, 00:50:00) Bölüm 5.4'teki ikinci ağaçta (A; B, C; D, E, F, G, H; I) kök, yapraklar, iç düğümler, E'nin seviyesi, ağacın yüksekliği, B'nin derecesi, ağacın derecesi, I'nın ataları ve C'nin alt soyu nedir?

**Çözüm (derste verildi):** Kök A; yapraklar D, E, F, G, I; iç düğümler A, B, C, H. E'nin seviyesi 3; ağacın yüksekliği 3; B'nin derecesi 2; ağacın derecesi 3; I'nın ataları A, C, H; C'nin alt soyu F, G, H, I.

### Soru 3: Dizi ile gösterimde gereken yer

(derste sözlü, 01:17:16) Hocanın işaretçiyle çizdiği 11 düğümlü, 5 seviyeli ağaç dizi tabanlı gösterimle tutulsaydı kaç gözlük dizi gerekirdi?

**Çözüm (derste verilmedi):** Hoca önce "256 eksi 1 mi?" diye sordu, sonra "63 değil mi?" dedi ve hesabı öğrencilere bıraktı. Dizi tabanlı gösterimde $L$ seviyeli bir ağaç için en kötü durumda $2^L - 1$ göz gerekir. 5 seviye (yükseklik 4) için $2^5 - 1 = 31$ göz eder. 63 göz 6 seviyeli bir ağaca karşılık gelir.

> **Ders sonrası not:** Hocanın ağaç çizimi karelerde görünmüyor; hesap, hocanın saydığı 5 seviyeye göre yapılmıştır. Ağaç gerçekten 5 seviyeliyse doğru değer büyük olasılıkla 31'dir.

### Soru 4: Dengeli ağaçta yükseklik

(derste sözlü, 01:28:23) 4 düğümlü bir ikili ağaç dengeli yerleştirilirse yüksekliği kaç olur? 4'ün 2 tabanında logaritması nedir?

**Çözüm (derste verilmedi):** $\log_2 4 = 2$. 4 düğümlü dengeli bir ikili ağaçta kökün iki çocuğu ve bunlardan birinin bir çocuğu olur; yükseklik $2 = \lfloor \log_2 4 \rfloor$'tür. Zincir şeklindeki p, r, v, z ağacının yüksekliği ise 3'tür. Hoca hesabı derste tam yapamadığını söyleyip öğrencilere bıraktı.

### Soru 5: Preorder, inorder ve postorder sırası

(ekrandan, 01:50:00, 02:10:00 ve 02:15:00) Kökü 60 olan örnek ağaçta (60; 20, 70; 10, 40; 30, 50) üç derinlik öncelikli gezintinin ziyaret sırası nedir?

**Çözüm (derste verildi):**

- Preorder (VLR): 60, 20, 10, 40, 30, 50, 70
- Inorder (LVR): 10, 20, 30, 40, 50, 60, 70
- Postorder (LRV): 10, 30, 50, 40, 20, 70, 60

Ajanın C ile yaptığı denemede üç sıra da aynı çıktı.

### Soru 6: Seviye sıralı gezinti

(ekrandan, 02:20:00) Kökü f olan ağaçta (f; c, j; a, d, h, k; i) genişlik öncelikli gezinti sırası nedir?

**Çözüm (derste verildi):** Bölüm 11.2'deki kuyruk tablosuna göre f, c, j, a, d, h, k, i.

### Soru 7: Hangileri ikili arama ağacıdır?

(derste sözlü, 02:35:13) Şu üç ağaçtan hangileri ikili arama ağacıdır? (a) kök 20; çocukları 15 ve 25; 15'in sol çocuğu 12, sağ çocuğu 10. (b) kök 30; çocukları 5 ve 40; 5'in sol çocuğu 2. (c) kök 60; yalnız sağ çocuğu 70; 70'in çocukları 65 ve 80.

<!-- BELİRSİZ: Ağaç şekilleri karelerde yok, altyazıdaki anlatımdan kurulmuştur. -->

**Çözüm (derste verildi):** (a) değildir, çünkü 10, 15'ten küçük olduğu halde sağ alt ağaçtadır. (b) ikili arama ağacıdır. (c) ikili arama ağacıdır; ama sol alt ağacın olmaması dengesizliğe yol açar.

### Soru 8: İkili arama ağacında arama

(ekrandan, 02:35:00) Kökü 21 olan ağaçta (21; 3, 34; 2, 8, 55; 5, 13) 21, 8 ve 80 değerleri aranırsa hangi yollar izlenir ve sonuç ne olur?

**Çözüm (derste verildi):** 21 kökte bulunur. 8: 21 → 3 → 8, bulunur. 80: 21 → 34 → 55 → `NULL`; bulunamaz, `NULL` döndürülür.

### Soru 9: İki çocuklu düğüm silme

(ekrandan, 02:45:00) Bölüm 14.5'teki ağaca 9 (5'in sağ çocuğu) ve 8 (9'un sol çocuğu) eklendikten sonra 10 silinirse, sol alt ağacın en büyüğü ve sağ alt ağacın en küçüğü yöntemleriyle ağaç nasıl olur?

**Çözüm (derste verildi):**

- Soldaki en büyük (9) kullanılırsa: 10'un yerine 9 yazılır, eski 9 silinip çocuğu 8, 5'e bağlanır. Kökün sol alt ağacı 9 olur; 9'un solunda 5 (sağ çocuğu 8), sağında 24 (sol çocuğu 11, onun sağ çocuğu 17).
- Sağdaki en küçük (11) kullanılırsa: 10'un yerine 11 yazılır, eski 11 silinip çocuğu 17, 24'e bağlanır. Kökün sol alt ağacı 11 olur; 11'in solunda 5 (sağında 9, onun solunda 8), sağında 24 (sol çocuğu 17).

## Dersin Toparlaması

Ders, bağlı liste ile kuyruk gerçeklemesinin tamamlanmasıyla başladı: `count`, `front` ve `rear` tutan bir kuyruk yapısıyla ekleme sona, çıkarma baştan yapılır ve bütün kuyruk işlemleri $O(1)$'de kalır. Ardından haftanın asıl konusu olan ağaçlara geçildi. Ağaç, kapalı çevrim içermeyen ve kökten her düğüme tek yol bulunan hiyerarşik bir yapıdır. Kök, ebeveyn, çocuk, kardeş, yaprak, derece, yükseklik, derinlik ve seviye kavramları örneklerle tanımlandı. İkili ağaç önce dizi ile (tablo ve indis tabanlı gösterim) gösterildi; dizi gösteriminin dolu olmayan ağaçlarda büyük bellek israfına yol açtığı görüldü ve işaretçili gösterime geçildi. Full, complete, perfect ve balanced ağaçlar tanımlandı. Ağacın etkinliğinin yüksekliğin $\log n$ mertebesinde kalmasından geldiği, degenerate ağacın ise bağlı listeye dönüştüğü vurgulandı.

Dersin ikinci yarısında ikili ağaçta ekleme ve üç durumlu silme, preorder, inorder ve postorder gezintileri, yığıtla özyinelemesiz inorder ve kuyrukla seviye sıralı gezinti anlatıldı. Kopyalamada postorder, eşitlik kontrolünde preorder mantığının kullanılması, genel ağaçların ilk çocuk ve kardeş işaretçileriyle ikili ağaç olarak tutulması gösterildi. Son olarak ikili arama ağacında arama, ekleme ve silme görsel örneklerle işlendi. Aramanın ortalamada $O(\log n)$, en kötü durumda $O(n)$ olduğu ve dengeyi koruyan AVL ve red-black gibi ağaç çeşitlerinin bulunduğu belirtildi. Hoca, ileride heap'lerin complete binary tree olacağını hatırlattı.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
