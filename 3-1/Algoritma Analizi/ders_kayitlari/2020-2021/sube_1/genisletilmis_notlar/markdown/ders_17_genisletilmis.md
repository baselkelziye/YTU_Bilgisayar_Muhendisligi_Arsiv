# Ders 17 Genişletilmiş Notu: Ayrık Zincirleme, Hashing Analizi ve Dinamik Programlamaya Giriş

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Açık Adreslemenin Hatırlatılması ve Ayrık Zincirleme
- 2. Ayrık Zincirleme İçin Veri Yapısı ve Ekleme
- 3. Açık Adreslemede Silme Sorunu ve Bayrak Kullanımı
- 4. Hashing Analizi: Doluluk Oranı ve Beklenen Deneme Sayısı
- 5. Tablo Uzunluğu Neden Asal Seçilir ve Yeniden Özetleme
- 6. Hash'e Yönelik Saldırı ve Hashing Uygulamaları
- 7. Dinamik Programlamaya Giriş: Fibonacci
- 8. 0-1 Sırt Çantası Problemi
- Örnek Sorular
- Dersin Toparlaması

## 1. Açık Adreslemenin Hatırlatılması ve Ayrık Zincirleme

Ders, hashing konusunda kalınan yerden başladı. Açık adreslemede (open addressing) bir eleman hash fonksiyonundan geçirilir ve ürettiği adrese yerleştirilmeye çalışılır. Adres boşsa sorun yoktur; doluysa boş bir adres bulunana kadar aranır ve eleman bulunan ilk boş adrese yerleşir.

İkinci yaklaşım ayrık zincirlemedir (separate chaining). Burada bir çakışma (collision) olduğunda yeni bir boş göz aranmaz. Örneğin bir anahtar hash fonksiyonundan geçip 1. adresi üretmiş, ama 1. adreste başka bir değer varsa, eleman bağlı liste (linked list) mantığıyla o adresteki elemanlara uç uca eklenir. Aynı adresi gösteren elemanlar böylece bir zincir (chain) oluşturur.

Ayrık zincirlemede tablo uzunluğu $M$, eleman sayısı $N$'den küçük seçilir; en fazla $N$'e eşit olur. $M$ çok büyük alınırsa gereksiz yer kaybı olur, çok küçük alınırsa zincirler çok uzar. <!-- BELİRSİZ: 00:04:15-00:04:43 arasında hocanın verdiği oran altyazıda bozuk ("3-4 uzunlukta"); ders sonunda net olarak M ≈ N/5 verildi. --> Hoca dersin ilerleyen kısmında, ayrık zincirleme için en uygun tablo uzunluğunun yaklaşık $N/5$ olduğunun bulunduğunu söyledi; örneğin 100 eleman için 20 gözlük tablo yeterlidir (ekrandan, 01:05:00).

### 1.1 Tablonun bir adres tablosu olması

Ayrık zincirlemede tablonun gözleri verinin kendisini değil, o göze düşen zincirin başlangıç adresini (head) tutar. Tahtadaki örnek şöyledir (ekrandan, 00:10:00):

- Tablo 0-4 arasında gözlerden oluşur.
- 11 anahtarı hash'ten geçip 4. adresi üretir. Tablo boş olduğu için 11 için bir düğüm açılır (1500 numaralı adreste) ve 4. göz bu düğümü gösterir; 11'in next alanı NULL'dur.
- Sonra 8 gelir ve o da 4. adresi üretir. 8 için de dinamik olarak bir düğüm açılır (1000 numaralı adreste). Tablonun 4. gözü artık 1000'i (8'i) gösterir, 8'in next alanı da 1500'ü (11'i) gösterir.

Yani yeni gelen eleman zincirin başına eklenmiştir.

## 2. Ayrık Zincirleme İçin Veri Yapısı ve Ekleme

### 2.1 Düğüm ve tablo yapıları

Her düğümde bir anahtar, örneğin bir kişinin ad bilgisi ve bir sonraki elemanın adresi saklanır. Tablonun her gözü ise zincirin başını ve isteğe bağlı olarak zincirdeki eleman sayısını tutar (ekrandan, 00:10:00):

```c
struct node {
    int key;
    char name[40];
    struct node *next;
};

struct hash {
    struct node *head;
    int count;
};

struct hash *hashTable = NULL;

int main() {
    int key;
    char name[40];
    // OKUMA
    hashTable = (struct hash *) calloc(M, sizeof(struct hash));
    ...
}
```

`hashTable`, $M$ elemanlı bir `struct hash` dizisidir; her eleman bir zincirin başını gösterdiği için bu yapı aslında bir "bağlı liste dizisi"dir. `calloc` kullanıldığı için başlangıçta bütün head'ler sıfırlanmış (NULL) olur. Okuma ve diğer bildirimler varsayılmıştır.

Tablo uzunluğu $M$ bütün fonksiyonlarda kullanıldığı için global ya da makro olarak tanımlanabilir; istenirse fonksiyondan fonksiyona parametre olarak da aktarılabilir. Bu tamamen tasarım tercihidir.

### 2.2 Ekleme fonksiyonu

Ekleme fonksiyonu okunan anahtar ve ad için tabloya bir eleman ekler. Önce adres hesaplanır, sonra yeni eleman için yer ayrılır (ekrandan, 00:15:00 ve 00:20:00):

```c
void insertToHash(int key, char name[]) {
    int hashIndex;
    hashIndex = key % M;                         /* M global */
    struct node *newNode = createNode(key, name); /* yeni eleman için yer tutma */
    if (!hashTable[hashIndex].head) {
        hashTable[hashIndex].head = newNode;
        hashTable[hashIndex].count = 1;
    }
    else {
        newNode->next = hashTable[hashIndex].head;
        hashTable[hashIndex].head = newNode;     /* (altyazıdan) */
        hashTable[hashIndex].count++;            /* (altyazıdan) */
    }
}
```

İki durum vardır:

- **Gözde hiç eleman yoksa** (head NULL ise) zincir ilk kez oluşacaktır. Örneğin 5 anahtarı 2. göze yerleşecek ve düğümü 3000 numaralı adreste olsun. Elemanı kaybetmemek için tablonun head'i 3000 olmalıdır. Bu yüzden head yeni düğümün adresi yapılır ve count 1 olur.
- **Gözde zaten elemanlar varsa** iki seçenek vardır. Birincisi yeni elemanı zincirin sonuna eklemektir; ama bu boşu boşuna zincirde ilerlemek demektir (zincirde 8 eleman varsa 8.'yi bulup arkasına eklemek gerekir). İkincisi yeni elemanı zincirin başına koymaktır: yeni düğümün next'i eski head'i gösterir, head yeni düğüm olur. Derste bu ikinci yol seçildi. Ardından zincirdeki eleman sayısı (count) bir artırılır.

**Soru:** Bağlı liste için count'a gerçekten ihtiyaç var mı? **Cevap:** Yoktur; zincirin ne kadar uzadığını görmek için tutulur. Zincirin çok uzadığı fark edilirse önlem alınabilir; örneğin count bir eşik değeri geçtiğinde yeniden özetleme (rehash) yapılabilir. Mantıken zincirin $N$'e bağlı olarak uzamayacağı varsayılır, ama kontrol dışında çok uzarsa karmaşıklığın gereksiz artmaması için rehash gerekir.

### 2.3 Düğüm oluşturma fonksiyonu

Fonksiyonun dönüş tipi `struct node *`'dır, çünkü ayrılan yerin adresi geri döndürülür (ekrandan, 00:25:00):

```c
struct node *createNode(int key, char name[]) {
    struct node *newNode;
    newNode = (struct node *) malloc(sizeof(struct node));
    /* CONTROL: yer ayrılamadıysa uyarı verip dön */
    newNode->key = key;
    strcpy(newNode->name, name);
    newNode->next = NULL;
    return newNode;
}
```

Bir düğüm için `struct node` büyüklüğü kadar bayt yer ayrılır, `main`'de okunan anahtar ve ad düğüme yazılır, next NULL yapılır ve adres döndürülür. Kodun tamamı derste parça parça yazıldı; bu not için derlenmedi.

> **Hocanın vurgusu:** Dinamik bellek ayırmanın başarısız olma ihtimali her zaman vardır ve kontrol edilmelidir. Güvenlik açısından kritik (safety critical) bir yazılımda, örneğin uzaya füze gönderen ya da bankanın önemli işlem yazılımında, "olmaz" denen problemler de mutlaka kontrol edilir; yüzyılda bir olsa bile çok ciddi sonuç doğurabilir.

### 2.4 Dinamik ayrılan adres ile yerel dizi farkı

Öğrencilerin sık yaptığı bir hataya değinildi. Dinamik bellek ayırma ile tutulan bir adres fonksiyondan rahatça döndürülebilir, çünkü dinamik ayrılan yer yığın (heap) bölgesindedir ve program çalıştığı sürece geçerlidir. Fonksiyondaki `newNode` göstericisi yerel olduğu için kaybolur, ama gösterdiği heap bölgesi kaybolmaz.

Buna karşılık bir `F1` fonksiyonu içinde yerel bir `A` dizisi tanımlayıp doldurup `return A` demek sözdizimi hatası vermez, ama fonksiyondan çıkınca o bellek bölgesi kullanıma açılır. O bölgeyi başka bir şey kullanmadıysa dizi hâlâ okunabilir, kullandıysa okunamaz. Program "bazen çalışan, bazen çalışmayan" bir hâle gelir ve nedenini anlamak zordur.

Arama ve silme kodları derste yazılmadı; bağlı liste bilgisiyle yazılabileceği söylendi.

## 3. Açık Adreslemede Silme Sorunu ve Bayrak Kullanımı

Ayrık zincirlemenin açık adreslemeye göre en büyük avantajı silmenin kolay olmasıdır. Bunu göstermek için açık adreslemedeki silme sorunu yeniden ele alındı.

### 3.1 Sorunun gösterilmesi

Doğrusal yoklama (linear probing) ve $M = 5$ uzunluklu bir tablo kullanılır (ekrandan, 00:35:00):

- $h(3) = 3 \bmod 5 = 3$: 3, 3. göze yerleşir.
- $h(8) = 8 \bmod 5 = 3$: 3. göz dolu, 8 bir sonraki göze, 4. göze yerleşir.
- $h(13) = 13 \bmod 5 = 3$: 3. ve 4. gözler dolu, tablo başa döner ve 13 0. göze yerleşir.

Gerçekte tabloda yalnız anahtar durmaz; anahtara bağlı bir kayıt (örneğin öğrencinin adı, bir dersten aldığı not) yapı (struct) olarak saklanır. Önce kayıt anahtarla bulunur, sonra ona bağlı bilgiler kullanılır.

**8'i aramak:** 8'in olması gereken yer $8 \bmod 5 = 3$, yani 3. gözdür. Orada 3 vardır. Tablo doğrusal yoklamayla doldurulduğu için bir sonraki göze bakılır ve 8, 4. gözde bulunur.

**11'i aramak:** $11 \bmod 5 = 1$. 1. göz boştur (NULL). Bu, 11'in hiç yerleştirilmediği anlamına gelir; 11 tabloda olsaydı en azından 1. gözde olurdu. "11 bu tabloda yok" denir ve aramadan çıkılır.

**3'ü silmek:** 3 silinip 3. göz boşaltılsın. Şimdi 8 arandığında 3. göze gelinir, göz boştur ve "8 tabloda yok" denir. Oysa 8 4. gözdedir; 3. göz dolu olduğu için oraya kaymıştı. Algoritma aşağıya bakmayı düşünemez.

8'i yukarı çekmek de çözüm değildir. Bu, silinen elemanın altındaki her şeyi yeniden kontrol etmek, yani rehash yapmak demektir. Örneğin 4. gözde aslında 4 olabilir ve 3. göze yerleşmesi gereken 13 aşağıya, 0. göze kaymış olabilir. Sorun yalnızca silinen elemanın hemen altına bakarak çözülemez.

### 3.2 Bayrak (flag) çözümü

Her göz için bir bayrak değişkeni tutulur (ekrandan, 00:40:00; tahtada `int flag;`). Bayrak, bir durumu gösteren sıradan bir tam sayı değişkenidir; "flag" yalnızca bu tür değişkenler için kullanılan terimdir.

- Hiç eleman yerleşmemiş göz: **EMPTY**.
- Elemanı silinmiş göz: **DELETED**.

Arama sırasında DELETED bir göz görülürse aramaya devam edilir; bu, gözde eskiden bir eleman olduğu ve aranan elemanın o yüzden aşağılara kaymış olabileceği anlamına gelir. EMPTY bir göz görülürse arama durur.

**Soru (hoca sordu):** Aramada EMPTY ile DELETED'e bakış nasıl farklıdır? **Cevap (bir öğrenci):** DELETED ile karşılaşınca, sonraki adreslere yoklamada nasıl ilerleniyorsa öyle bakmaya devam edilir; EMPTY ile karşılaşınca durulur. Hoca cevabı doğru buldu.

### 3.3 DELETED bir göz EMPTY yapılabilir mi?

Derste bir sınav sorusu üzerinden iki durum tartışıldı (ekrandan, 00:30:00 - 00:45:00). Soru yalnız doğrusal yoklama içindir; çift özetleme (double hashing) gibi başka bir yoklamada durum farklıdır.

- **Durum 1:** 2. gözün bayrağı DELETED, 3. gözün bayrağı EMPTY. 3. gözün EMPTY olması oraya hiç kimsenin yerleşmediği demektir. 2. gözde bir çakışma olsaydı taşan eleman 3. göze yerleşirdi ve 3. göz EMPTY olmazdı. Demek ki 2. gözden taşan eleman yoktur; 2. göz güvenle EMPTY yapılabilir. Örneğin 4. gözde bir 6 varsa bu 6 kendi yerindedir; 3. göz boş olduğuna göre zaten 3. göze taşmış olamaz.
- **Durum 2:** 2. gözün bayrağı DELETED, 3. gözde doğru yerleşmiş bir eleman (örneğin 3) var. Bu durumda 2. göz EMPTY yapılamaz. Hocanın senaryosu: 2. gözde 15, 3. gözde 3 vardı; 2 geldi, $2 \bmod 5 = 2$ ama 2. göz dolu, 3. göz de dolu, 2 4. göze yerleşti. Sonra 15 silindi ve 2. göz DELETED oldu. 2. göz EMPTY yapılırsa 2 arandığında 2. gözde durulur ve 2 bulunamaz (ekrandan, 00:45:00).

Altta doğru yerleşmiş tek bir eleman görmek, o gözden taşan başka eleman olmadığını kanıtlamaz; daha aşağıda çakışma yüzünden kaymış elemanlar olabilir. Bunu bilmek için aşağıdaki bütün elemanları kontrol etmek gerekir ve bunun sonu yoktur. Bu yüzden birinci durum doğru, ikinci durum yanlıştır.

**Soru:** Bu sonuç yalnız indeksleri birer birer artırdığımız durumda mı geçerli? **Cevap:** Evet, soru doğrusal yoklama içindir. Çift özetleme gibi bir yöntemde başka bir durumdan bahsediliyor olurdu.

**Soru:** Soruda tablonun geri kalanı verilmediği için tabloyu boş kabul etmek mümkün değil miydi? **Cevap:** Hayır. Soru yalnızca "alt gözde doğru yerleşmiş bir eleman var" bilgisini veriyor; tablonun geri kalanında hiç eleman olmadığı söylenmediyse genel düşünmek gerekir. Gerçek bir tabloda bir değerin altında başka değerler olabilir de olmayabilir de; tek bir alt değere bakarak karar verilemez.

### 3.4 Ayrık zincirlemede silme

Ayrık zincirlemede silme hiçbir şeyi etkilemez. Örneğin 8 silindiğinde, çakışan elemanlar zaten uç uca eklendiği için zincirden bir düğüm çıkarılır ve bir sorun oluşmaz. Açık adreslemede ise bayrak kullanılmazsa bir süre sonra "delik deşik" bir tablo oluşur ve bir gözdeki elemanın silindiğini bir şekilde belirtmek gerekir. Bu nedenle çok silme yapılan uygulamalarda açık adresleme etkin bir çözüm değildir; ayrık zincirleme bu açıdan daha avantajlıdır.

## 4. Hashing Analizi: Doluluk Oranı ve Beklenen Deneme Sayısı

Derste başından beri hashing'de arama ve ekleme karmaşıklığının $N$'e bağlı olmadığı söylenmişti. Bu bölümde bunun nasıl sağlandığı gösterildi (ekrandan, 00:50:00).

### 4.1 Doluluk oranı

Doluluk oranı (load factor), tablonun ne kadar dolu olduğunu gösterir:

$$\alpha = \frac{N}{M}$$

$\alpha = 0$ boş tablo, $\alpha = 1$ tamamen dolu tablodur.

### 4.2 Boş göz bulma olasılığı

Anahtarları rastgele, üst üste yığılmadan dağılmış bir tablo düşünülür. Bir gözün dolu olma olasılığına $\lambda$ (occupied) denirse, boş olma olasılığı $1 - \lambda$ (free) olur. Bir eleman yerleştirilirken:

- İlk bakılan göz dolu, ikincisi boşsa olasılık $\lambda (1-\lambda)$.
- İlk iki göz dolu, üçüncüsü boşsa olasılık $\lambda^2 (1-\lambda)$.
- İlk $k-1$ göz dolu, $k$. göz boşsa olasılık $\lambda^{k-1}(1-\lambda)$.

Bu bir geometrik seridir. Serinin açılımından, doğrusal yoklamada (tek tek sırayla bütün adreslere bakma) boş yer bulmak için ortalama kaç deneme (probe) yapılacağı hesaplanır. Hoca türetmenin ayrıntısına girmedi ve sonucu tablo olarak verdi (ekrandan, 00:55:00):

| $\lambda$ | Deneme sayısı (# of probes) |
|---|---|
| 0,1 | 1,11 |
| 0,2 | 1,28 |
| 0,3 | 1,52 |
| 0,4 | 1,89 |
| 0,5 | 2,5 |
| 0,6 | 3,62 |
| 0,7 | 6,06 |
| 0,8 | 13 |
| 0,9 | 50,5 |

<!-- BELİRSİZ: Hocanın tabloyu üreten formülü tahtaya yazıp yazmadığı karelerde görünmüyor. -->

> **Ek bilgi (derste anlatılmadı):** Bu değerler büyük olasılıkla Knuth'un doğrusal yoklama için verdiği başarısız arama (ve ekleme) formülünden gelir: $\frac{1}{2}\left(1 + \frac{1}{(1-\lambda)^2}\right)$. Python ile kontrol edildiğinde formül tablodaki bütün değerleri verir; yalnız $\lambda = 0{,}1$ için sonuç 1,117'dir, tahtada 1,11 olarak yazılmıştır.

### 4.3 Tablonun yorumlanması

$\lambda = 0{,}1$, %90'ı boş bir tablo demektir; örneğin 10 eleman için 100'lük tablo açılmıştır. Bu durumda ortalama 1,11 denemede, yani neredeyse ilk denemede boş yer bulunur. Değerler matematiksel olarak hesaplandığı için tam sayı değildir; bunlar ortalamadır: bazen hemen, bazen iki adım sonra bulunur.

0,4 ile 0,5 arasında büyük fark yoktur. %50'si boş bir tabloda ortalama 2,5 adımda aranan elemana ulaşılır; arama ve ekleme (boş yer bulma) süresi 2,5'tir. 0,6'da değerler birden bozulur: 0,7'de 6, 0,8'de 13, 0,9'da 50 adım gerekir. 0,9, örneğin $N = 90$ için $M = 100$ almak demektir (ekrandan, 01:05:00).

Bu nedenle açık adreslemede tablo uzunluğu eleman sayısının yaklaşık iki katı seçilir:

$$M \approx 2N$$

Çok ideal olsun istenirse %10 dolu bir tablo kurulabilir, ama $M \approx 2N$ zaten yeterlidir.

**Soru:** Ortalama durumu Büyük-O gösterimiyle $O(1)$ diye yazabilir miyiz? **Cevap:** Kesinlikle. Uygun bir tablo uzunluğu seçildiğinde ortalama durumda genellikle 3 ile 5 arasında denemeyle sonuca ulaşılır ve bu sayı $N$'e bağlı değildir. Bu yüzden ortalama durumda ekleme ve arama karmaşıklığı $O(1)$'dir (ekrandan, 01:05:00). Karşılaştırma için sıralı aramada (sequential search) ortalama durum $n$, ikili aramada (binary search) $\log n$'dir. Silme, açık adreslemede ayrıca değerlendirilmelidir.

Ayrık zincirlemede de ortalama karmaşıklık $O(1)$'dir; orada en uygun tablo uzunluğunun $M \approx N/5$ olduğu bulunmuştur.

> **Hocanın vurgusu:** Bunun matematiksel olarak, olasılık hesabıyla kanıtlanmış olması önemlidir. Çakışma olursa ne olur diye tereddüt etmek yerine, $\lambda = 0{,}5$ iken ortalama 2,5 adımda elemana ulaşıldığı bilinir.

## 5. Tablo Uzunluğu Neden Asal Seçilir ve Yeniden Özetleme

### 5.1 Asal tablo uzunluğu

İlk derste sorulan ikinci soru, tablo uzunluğunun neden asal sayı alındığıydı. Örnek (ekrandan, 01:00:00):

- Anahtarlar: 64, 100, 128, 200, 300, 400, 500.
- Tablo uzunluğu: $M = 8$.

Bölme yöntemiyle $h(x) = x \bmod 8$ hesaplanırsa (ara adım eklendi):

| Anahtar | $x \bmod 8$ | $x \bmod 11$ |
|---|---|---|
| 64 | 0 | 9 |
| 100 | 4 | 1 |
| 128 | 0 | 7 |
| 200 | 0 | 2 |
| 300 | 4 | 3 |
| 400 | 0 | 4 |
| 500 | 4 | 5 |

$M = 8$ iken bütün anahtarlar yalnız 0 ve 4 adreslerine düşer. Bunun nedeni anahtarların 8 ile büyük ortak bölenlere sahip olmasıdır; anahtarlar ortak bölenlerinde birleşir ve sürekli çakışma olur. Hash fonksiyonu basit bir mod alma işlemi olduğu için asal olmayan bir tablo uzunluğu çakışmayı çok artırır.

$M = 11$ (asal) seçilirse anahtarlarla 11'in en büyük ortak böleni 1 olur. Bütün anahtarların 11'in katı olması gibi bir şanssızlık olmadıkça yığılma olmaz. Bu örnekte adresler 9, 1, 7, 2, 3, 4, 5'tir ve hiç çakışma yoktur. Elbette genelde yine bazı çakışmalar olacaktır; asal uzunluk yalnız çakışma olasılığını azaltır. Bu, anahtarların düzgün dağılmış olmasına da bağlıdır.

> **Ders sonrası not:** Hoca 4. adrese 300 ile 500'ün yerleşeceğini söyledi; $100 \bmod 8 = 4$ olduğu için 100 de 4. adrese yerleşir. Hoca ayrıca 200, 300, 400, 500 ile 8'in en büyük ortak böleninin 4 olduğunu söyledi; doğrusu $\mathrm{ebob}(300,8) = \mathrm{ebob}(500,8) = 4$, $\mathrm{ebob}(200,8) = \mathrm{ebob}(400,8) = 8$'dir (python ile kontrol edildi). Sonuç değişmez: hepsi 0 ya da 4'e düşer.

### 5.2 Özet kurallar

- Açık adreslemede tablo uzunluğu eleman sayısının yaklaşık iki katı alınır.
- Ayrık zincirlemede tablo uzunluğu eleman sayısının yaklaşık beşte biri alınır.
- Hash fonksiyonu $key \bmod M$ biçimindeyse tablo uzunluğu asal seçilir.

### 5.3 Yeniden özetleme (rehash)

Başlangıçta eleman sayısının en fazla 100 olacağı düşünülüp tablo buna göre kurulmuş, ama zamanla fark edilmeden çok daha fazla eleman gelmiş olabilir. Doluluk oranı %70'leri geçip %80'e ulaştığında tehlikeli sınıra girilmiştir: %80 dolu bir tabloda ortalama 13. adımda yer bulunur. Bu durumda mutlaka rehash yapılır: yeni ve daha büyük bir yer ayrılır (dosyaysa yeni dosyaya geçilir) ve bütün elemanlar yeniden yerleştirilir. Tablo uzunluğu değiştiği için her eleman başka bir adrese gidecektir. Rehash yapılırken yeni tablo uzunluğunun yine asal olmasına dikkat edilir.

## 6. Hash'e Yönelik Saldırı ve Hashing Uygulamaları

### 6.1 Hizmet engelleme (denial of service) saldırısı

Çok sık yapılan bir saldırı türü olmasa da şöyle bir durum vardır: bir sistem bilgileri hash tablolarında saklar. Saldırgan sistemin hash fonksiyonunu öğrenir ve hepsi aynı adresi (örneğin 5 numaralı adresi) üreten anahtarlar gönderir. Düzgün dağılımda elemanlar böyle dizilmez, ama bu saldırıda ayrık zincirlemede bütün elemanlar "tren gibi" tek bir zincirde arka arkaya dizilir ve erişim süresi $N$'e çıkar.

Önlem: farklı hash fonksiyonları arasından çalışma zamanında rastgele biri seçilir ve tablo buna göre kurulur. Rastgele seçim, örneğin tablo uzunluğunun farklı olması ya da çift özetlemede çakışma olduğunda kaç adım sonraya yerleştirileceğinin farklı olması demektir. Saldırgan hangi fonksiyonun seçildiğini bilemeyeceği için saldırıyı düzenleyemez. Hocanın aktardığına göre bu saldırı Java API'leri üzerinden yapılmıştır.

**Soru:** Hash fonksiyonunu rastgele seçiyorsak, saldıran bilmeyecek de biz hangisini seçtiğimizi nereden bileceğiz? **Cevap:** Kişi olarak bilmek gerekmez. Sistem çalışma zamanında fonksiyonu seçer, tabloyu ona göre kurar ve o fonksiyonla çalışır.

### 6.2 Hashing uygulamaları

Hashing, doğrudan erişim avantajı sağladığı için çok kullanılan bir yöntemdir. Derste verilen örnekler:

- **Yazım denetleyici (spell checker):** Kelime anahtar olarak kullanılır, hash tablosunda bir sözlük tutulur ve kelimenin sözlükte olup olmadığına bakılır.
- **Tarayıcı:** Gidilen sayfaların bilgileri hash tablosunda tutulur; URL anahtar olarak kullanılarak bir sayfaya gidilip gidilmediği kontrol edilir.
- **Spam filtresi:** IP adresi anahtar olarak tutulur; tabloda spam adresler vardır ve gelen IP'nin spam olup olmadığına bakılır.
- **Kredi kartı sahtecilik tespiti (credit card fraud detection):** Çalıntı kartların bilgileri bir tabloda tutulur. Büyük bir veri sızıntısında bütün kartları yeniden basmak pahalı olduğu için bankalar bu kartları bir "gri bölge" tablosunda saklayıp şüpheli işlemlerde kartın bu tabloda olup olmadığına bakar.
- **Arama motorları:** Her sorguda bütün dokümanlara bakmak yerine her kelimenin geçtiği dokümanların listesi tutulur ve hash tablosu üzerinden bu listeye erişilir.

## 7. Dinamik Programlamaya Giriş: Fibonacci

Aradan sonra yeni konuya, dinamik programlamaya (dynamic programming) geçildi. Şimdiye kadar özyinelemeli olmayan ve özyinelemeli algoritma tasarımları görülmüştü; dinamik programlama problemlere farklı bir bakış açısıyla çözüm getirir.

### 7.1 Tanım

Dinamik programlama 1950'lerde Richard Bellman tarafından geliştirilmiştir. Adındaki "programming" sözcüğü bilgisayar programından değil, planlamadan (planning) gelir (ekrandan, 01:35:00). Üst üste çakışan, birbirinin devamı olan işleri yine küçük alt problemlere bölerek çözmek için kullanılır.

Böl ve yönetten (divide and conquer) farkı şudur: böl ve yönette problem bağımsız parçalara bölünüp çözülür. Dinamik programlamada ise alt problemler birbirine bağlıdır (subproblems are dependent); bir alt problemin sonucu alınıp başka bir yerde kullanılır, yani alt problemler arasında örtüşme (overlap) vardır.

### 7.2 Fibonacci örneği

Fibonacci sayıları 0, 1, 1, 2, 3, 5, 8, 13, ... diye gider; her sayı kendisinden önceki iki sayının toplamıdır (örneğin 3 + 5 = 8). Rekürans bağıntısı (ekrandan, 01:35:00):

$$fib(n) = fib(n-1) + fib(n-2)$$

Özyinelemeli fonksiyon (ekrandan, 01:35:00):

```c
int fibonacci(int n) {
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    else
        return (fibonacci(n - 1) + fibonacci(n - 2));
}
```

Durma koşulu $n$'in 0 ya da 1 olmasıdır. Fonksiyon $n = 6$ için çağrılırsa $n = 5$ ve $n = 4$ için çağrılır; $n = 5$ çağrısı $4$ ve $3$'ü, $4$ çağrısı $3$ ve $2$'yi, $3$ çağrısı $2$ ve $1$'i çağırır ve ağaç böyle aşağı iner.

Burada $F(6)$ için $F(5)$ ile $F(4)$ çağrılır, ama $F(4)$ $F(5)$'in içinde de yeniden çağrılır. $F(5)$ için $F(4)$ ile $F(3)$ çağrılır, ama $F(3)$ başka dallarda da çağrılır. Özyinelemenin belleği olmadığı için aynı $n$ değeri, başka bir noktada hesaplanmış olmasına rağmen defalarca hesaplanır.

> **Hocanın vurgusu:** Böyle bir özyinelemeli fonksiyonun maliyeti $n$'e bağlı olarak üsteldir. Özyinelemeli yazınca hızlı yaptığımızı zannederken yaklaşık $1{,}6^n$ toplama yapılır.

> **Ek bilgi (derste anlatılmadı):** 1,6 büyük olasılıkla altın oranı ($\varphi \approx 1{,}618$) ifade eder. Python ile sayıldığında `fibonacci(6)` toplam 25 fonksiyon çağrısı yapar.

### 7.3 Sonuçları saklayarak çözüm

Daha önce hesaplanan bir sonucu sonraki adımlarda kullanma imkânı varsa, özyineleme yerine sonuçlar bir dizide saklanır (ekrandan, 01:40:00):

```text
for i = 2 to n do
    f[i] = f[i-1] + f[i-2];
```

$i-1$. ve $i-2$. değerler bir kez hesaplanıp $i$ için kullanılır; aynı şeyleri tekrar tekrar hesaplamaya gerek kalmaz. Fibonacci için dizi kullanmak aslında gerekli değildir, iki değişkenle de hesaplanabilir; örnek, rekürans bağıntısı yazmak ve göstermek çok kolay olduğu için seçildi.

### 7.4 Dinamik programlamanın adımları

Tahtadaki adımlar (ekrandan, 01:40:00) ve hocanın anlatımı:

- **1. Alt problemleri tanımla (define subproblems):** Böl ve yönette olduğu gibi problemi oluşturan parçaları ve her parçada ne yapılacağını belirle.
- **2. Rekürans bağıntısını yaz (write the recurrence):** Dinamik programlamada da problemler rekürans bağıntılarıyla çözülür; $n$. adımdaki sonuç önceki adımlarda elde edilen sonuçlara bağlıdır. Rekürans geriye doğru gittiği için başlangıç durumları (ilk değerler) mutlaka belirlenir. Fibonacci için $fib(n) = fib(n-1) + fib(n-2)$, $n \ge 2$; ilk değerler $fib(0) = 0$, $fib(1) = 1$.
- **3. Sonuçları sakla:** Farkı şudur: sistemin belleği vardır. Hesaplanan sonuçlar her seferinde yeniden hesaplanmaz; problemin gerektirdiği bir dizide, matriste ya da tabloda tutularak kullanılır.

## 8. 0-1 Sırt Çantası Problemi

Bu problem gerçekten dinamik programlamayla çözülen bir problemdir (ekrandan, 01:45:00 ve 01:50:00).

### 8.1 Problem

Bir hırsızın sırt çantası (knapsack) vardır ve gittiği evdeki eşyaları bu çantaya doldurup götürecektir. Çantanın bir kapasitesi vardır, örneğin 15 kilo. Hırsız 15 kiloyu geçmeyen ama "yükte hafif, pahada ağır" eşyaları seçmelidir.

Adındaki "0-1", her eşya için verilecek karardır: 0 alma (abandon), 1 al (select). Tahtadaki gösterim (ekrandan, 01:50:00):

- $W$: çantanın kapasitesi (knapsack capacity).
- $n$: eşya sayısı (number of items).
- $1 \le i \le n$ için ağırlıklar $w_1, \dots, w_n$, değerler $v_1, \dots, v_n$.

Amaç, taşınabilecek yüke bağlı olarak toplam kazancı en büyük yapmaktır.

### 8.2 Kaba kuvvet

En kötü ihtimalle her şey denenir: birinci eşyayı al (5 lira), ikinciyi de al (8 lira, toplam 13 lira), üçüncüyü alırsam çanta taşar mı, kaç lira kazanırım... Bütün kombinasyonları denemek kaba kuvvettir (brute force) ya da tüketici aramadır (exhaustive search): hiçbir şey düşünmeden bütün olasılıklar denenir (1-2-3'ü alsam, 1-2-4'ü alsam ...). $n$ eşya için $2^n$ olasılık vardır; 5 eşya için bile $2^5 = 32$ olasılık denenir. Hocanın esprisiyle, illa en iyi sonucu bulmak isteyen bir hırsız evi soyamadan çıkar.

Kaba kuvvetin sıkıntısı, her kombinasyonda önceki bilgiyi aklında tutmadan başa dönmesidir. Önceki bilgiler tutularak olasılıklar hesaplanırsa problem dinamik programlamayla çözülebilir.

### 8.3 Hangi bilgi saklanmalı?

Dinamik programlamayla çözerken önce bilginin tek boyutlu bir dizide mi yoksa matriste mi saklanacağına karar verilir. Hoca derslerinde genelde dizi ya da matris kullanıldığını, üç boyutlu bilgiye gidilmediğini söyledi.

**Soru (hoca sordu):** Eşyalarla ilgili hangi bilgiler kullanılarak problem çözülecek? **Cevap (bir öğrenci):** Ağırlık ve değer. Hoca bunu doğruladı: durmadan eşya alınırsa çantanın kapasitesi aşılabilir, bu yüzden ağırlık önemlidir; aynı ağırlıkta iki eşyadan (örneğin son kalan 2 kiloluk yer için 3 liralık ve 9 liralık iki eşya) değerli olan seçilmelidir, bu yüzden değer önemlidir.

Bunlara ek olarak hangi eşyada olunduğu da bilinmelidir: birinciyi ve ikinciyi aldım, şu anda çantada kaç kilo var ve toplam kaç lira kazandım? Bu kadar bilgi tek boyutlu bir dizide tutulamaz. Bu yüzden bir matris kullanılır:

- Satırlar: kaçıncı eşyaya gelindiği ($i$).
- Sütunlar: çantada biriken ağırlık ($w$).
- Hücre: o noktadaki en büyük kazanç (profit) $P[i, w]$.

Örneğin "1. ve 2. eşyalar değerlendirildi, toplam 2 kilo, kazanç 8 lira" bilgisi ilgili satır ve sütundaki gözde durur. $P[i, w]$, $i$. eşyaya gelindiğinde ve ağırlık $w$ iken elde edilebilecek en büyük kazançtır. Ders burada bitti; problemin çözümüne bir sonraki derste devam edilecektir. <!-- BELİRSİZ: 01:57:43-01:58:38 arasındaki matris örneğinin ("3 kilo / 2 kilo, 8 lira") ayrıntısı altyazıda bozuk ve o ana ait kare yok. -->

## Örnek Sorular

**Soru 1** (derste sözlü, 00:28:45; tabloları ekrandan, 00:30:00): Doğrusal yoklama kullanan bir hash tablosunda her gözde EMPTY/DELETED bayrağı tutuluyor.

- a) 2. gözün bayrağı DELETED, 3. gözün bayrağı EMPTY ise 2. göz EMPTY yapılabilir mi?
- b) 2. gözün bayrağı DELETED, 3. gözde doğru yerine yerleşmiş bir eleman varsa 2. göz EMPTY yapılabilir mi?

> **Çözüm (derste verildi):** a) Evet. 3. göz EMPTY olduğuna göre 2. gözde çakışan hiçbir eleman aşağı taşmamıştır; 2. göz EMPTY yapılınca hiçbir aramanın sonucu değişmez. b) Hayır. 3. gözdeki elemanın doğru yerde olması, 2. gözden taşıp daha aşağıya yerleşmiş elemanların olmadığını kanıtlamaz. Örneğin 2. gözde 15, 3. gözde 3 varken gelen 2, 4. göze yerleşmiştir; 15 silinip 2. göz EMPTY yapılırsa 2 aranırken 2. gözde durulur ve 2 bulunamaz.

**Soru 2** (ekrandan, 00:35:00): $M = 5$, $h(k) = k \bmod 5$, doğrusal yoklama. 3, 8, 13 sırayla yerleştiriliyor. Tablonun son hâli nedir? 8 ve 11 nasıl aranır? 3 silinip göz boş bırakılırsa 8'in araması ne olur?

> **Çözüm (derste verildi):** 3 → 3. göz; 8 → 3 dolu, 4. göz; 13 → 3 ve 4 dolu, 0. göz. 8 aranırken 3. göze, sonra 4. göze bakılır ve bulunur. $11 \bmod 5 = 1$, 1. göz boş olduğu için 11 yoktur. 3 silinip göz boş bırakılırsa 8'in araması 3. gözde boşluk görüp "yok" der; bu yüzden DELETED bayrağı gerekir.

**Soru 3** (ekrandan, 01:00:00): Anahtarlar 64, 100, 128, 200, 300, 400, 500. Tablo uzunluğu 8 ve 11 iken bölme yöntemiyle adresler nedir? Neden asal tablo uzunluğu tercih edilir?

> **Çözüm (derste verildi, ara değerler python ile kontrol edildi):** $M = 8$: 0, 4, 0, 0, 4, 0, 4; anahtarlar yalnız iki adreste yığılır. $M = 11$: 9, 1, 7, 2, 3, 4, 5; çakışma yoktur. Asal uzunlukta anahtarlarla $M$'nin ortak böleni olmadığı için mod işlemi adresleri daha iyi dağıtır.

**Soru 4** (derste sözlü, 00:56:37): Hashing'de ortalama durumu Büyük-O gösterimiyle $O(1)$ diye yazabilir miyiz?

> **Çözüm (derste verildi):** Evet. Uygun tablo uzunluğunda ortalama deneme sayısı $N$'e değil doluluk oranına bağlıdır (örneğin $\lambda = 0{,}5$ için 2,5); bu yüzden ortalama ekleme ve arama $O(1)$'dir.

## Dersin Toparlaması

Dersin ilk yarısında hashing konusu tamamlandı. Ayrık zincirlemede çakışan elemanlar bağlı listede tutulur; tablo zincir başlarını saklar, yeni eleman zincirin başına eklenir ve silme sorun yaratmaz. Açık adreslemede ise silinen gözler DELETED bayrağıyla işaretlenmelidir; aksi hâlde çakışma yüzünden kaymış elemanlar bulunamaz. Doluluk oranına bağlı olasılık analizi, doğrusal yoklamada $\lambda = 0{,}5$ civarında ortalama 2-3 denemenin yettiğini, $0{,}7$'den sonra deneme sayısının hızla arttığını gösterir. Bu yüzden açık adreslemede $M \approx 2N$, ayrık zincirlemede $M \approx N/5$ alınır, $M$ asal seçilir ve doluluk %70-80'i geçince rehash yapılır; bu koşullarda ortalama ekleme ve arama $O(1)$'dir.

İkinci yarıda dinamik programlamaya giriş yapıldı. Böl ve yönetten farklı olarak alt problemler birbirine bağlıdır ve sonuçları bir tabloda saklanarak tekrar hesaplama önlenir. Fibonacci örneği bu farkı gösterdi; ardından 0-1 sırt çantası problemi tanımlandı ve en büyük kazancı tutan $P[i,w]$ matrisi kuruldu. Problemin dinamik programlamayla çözümüne bir sonraki derste devam edilecektir.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
