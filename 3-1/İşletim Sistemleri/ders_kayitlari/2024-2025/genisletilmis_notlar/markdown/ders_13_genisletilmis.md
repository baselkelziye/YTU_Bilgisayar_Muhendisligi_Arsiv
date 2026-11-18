# Ders 13 Genişletilmiş Notu: Sayfa Tablosu Yapıları, Sanal Bellek (Demand Paging), Sayfa Değiştirme Algoritmaları (FIFO, Optimal, LRU), Çırpınma (Thrashing), Çalışma Kümesi Modeli ve Disk Zamanlama Algoritmaları

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Sayfalamada Bellek Koruması (Memory Protection) ve Paylaşımlı Sayfalar (Shared Pages)
- 2. Sayfa Tablosu Yapıları (Structure of the Page Table) ve Donanım Mimarileri
- 3. Sanal Bellek (Virtual Memory), İstek Üzerine Sayfalama (Demand Paging) ve Başarım Analizi
- 4. Yazarken Kopyalama (Copy-on-Write) ve Sayfa Değiştirme (Page Replacement) Temelleri
- 5. Sayfa Değiştirme Algoritmaları: FIFO, Belady Anomalisi, Optimal (OPT), LRU ve İkinci Şans
- 6. Çerçeve Tahsisi (Frame Allocation), Çırpınma (Thrashing) ve Çalışma Kümesi (Working-Set) Modeli
- 7. Çekirdek Bellek Yönetimi (Buddy System) ve Program Yapısının Sayfa Hatalarına Etkisi
- 8. Yığın Depolama (Mass Storage) Mimarisi ve Disk Zamanlama (Disk Scheduling) Algoritmaları
- Örnek Sorular
- Dersin Toparlaması

## 1. Sayfalamada Bellek Koruması (Memory Protection) ve Paylaşımlı Sayfalar (Shared Pages)

Dersin başında hoca önceki haftanın hızlı bir özetini yaptı: Bitişik tahsisin (`contiguous allocation`) ve değişken boyutlu kesimlemenin (`segmentation`) yol açtığı **dış parçalanma (`external fragmentation`)** probleminin, fiziksel belleği sabit boyutlu çerçevelere (`frames`) ve mantıksal belleği aynı boyutta sayfalara (`pages`) bölen **sayfalama (`paging`)** mimarisiyle çözüldüğünü; sayfalamada yalnız son çerçevede **iç parçalanma (`internal fragmentation`)** kaldığını (örneğin `2,048 bayt` sayfa boyutunda `72,766 bayt` proses için 36. sayfada `2,048 - 1,086 = 962 bayt` boşluk) ve sayfa tablosunun yarattığı iki bellek erişimi gecikmesinin de **TLB (`Translation Look-aside Buffer`)** önbelleğiyle ($\alpha = \%80$ için $120\text{ ns}$, $\alpha = \%99$ için $101\text{ ns}$) giderildiğini hatırlattı.

### 1.1 Sayfalamada Bellek Koruması ve Geçerli-Geçersiz Biti (`Valid-Invalid Bit`)

Sayfalamalı bir bellek ortamında bellek koruması, her çerçeveyle (sayfa tablosundaki her kayıtla) ilişkilendirilen **koruma bitleri (`protection bits`)** aracılığıyla sağlanır. Bu bitler ilgili sayfanın salt okunur (`read-only`) mu yoksa okuma-yazma (`read-write`) yetkili mi olduğunu belirler.

Buna ek olarak sayfa tablosundaki her satıra bir **geçerli-geçersiz biti (`valid-invalid bit`)** eklenir:
- **`v` (`valid` — geçerli):** İlgili sayfanın prosesin mantıksal adres uzayına ait olduğunu ve bu sayfaya erişimin yasal (`legal`) olduğunu gösterir.
- **`i` (`invalid` — geçersiz):** İlgili sayfanın prosesin mantıksal adres uzayında bulunmadığını gösterir.

Örneğin 14 bitlik bir adres uzayında ($0..16383$) sayfa boyutu $2\text{ KB}$ ($2048\text{ bayt}$) olsun ve prosesin sayfa tablosunda `0..7` arası 8 satır bulunsun. Eğer program yalnızca `0` ile `10468` arasındaki adresleri kullanıyorsa, yalnız `Page 0` ile `Page 5` arasındaki 6 sayfaya sahiptir:

```text
Sayfa Tablosu (Page Table):
Sayfa No   Frame No   Valid-Invalid Bit
   0     [    2     |        v        ]
   1     [    3     |        v        ]
   2     [    4     |        v        ]
   3     [    7     |        v        ]
   4     [    8     |        v        ]
   5     [    9     |        v        ]
   6     [    0     |        i        ]  <-- Prosesin 6. ve 7. sayfası yok!
   7     [    0     |        i        ]
```

Sayfa tablosunun uzunluğu donanımsal olarak 8 satır olsa bile `6.` ve `7.` satırların bitleri **`i` (`invalid`)** olarak işaretlendiği için, proses bu sayfalara ait bir adres üretirse donanım tuzağa (`trap`) düşerek yetkisiz erişimi engeller (veya alternatif olarak `PTLR` — *Page-table length register* ile tablo uzunluğu sınırlandırılır).

### 1.2 Paylaşımlı Sayfalar (Shared Pages) ve Yeniden Girilebilir Kod (`Reentrant Code`)

Sayfalamanın en önemli avantajlarından biri, birden fazla prosesin ortak kullandığı kodların fiziksel bellekte **tek bir kopya** olarak paylaşılabilmesidir (**`Shared Pages`**, ekrandan, 00:10:00, 00:12:00).

Örneğin bir sistemde birden fazla kullanıcının (veya aynı kullanıcının farklı pencerelerde) **MS Word**, bir metin editörü, yazım denetleyici (`spellcheck`) veya bir derleyici çalıştırdığını düşünelim. Bu programların çalıştırılabilir kod bölgesi her proseste aynıdır:
- Eğer bu kod **yeniden girilebilir kod (`reentrant code` / `pure code`)** ise, yani çalışma zamanında **kendi kendini değiştirmeyen (`non-self-modifying` / `read-only`)** salt okunur bir kod ise, fiziksel bellekte bu kod sayfalarının yalnız **tek bir kopyasının** tutulması yeterlidir.
- Her proses kendi özel verilerini (`private code and data`) ise kendi ayrı çerçevelerinde tutar.

Slayttaki 3 prosesli (`P1`, `P2`, `P3`) metin editörü örneğini inceleyelim (ekrandan, 00:12:00):

```text
Proses P1       P1 Sayfa T.       Fiziksel Bellek (RAM)
+--------+       +---+            Frame No
|  ed 1  |     0 | 3 |               0    +--------+
+--------+       +---+                    |        |
|  ed 2  |     1 | 4 |               1    +--------+
+--------+       +---+                    | data 1 | (P1'in verisi)
|  ed 3  |     2 | 6 |               2    +--------+
+--------+       +---+                    | data 3 | (P3'ün verisi)
| data 1 |     3 | 1 |               3    +--------+
+--------+       +---+                    |  ed 1  | <-- Ortak Kod 1
                                     4    +--------+
Proses P2       P2 Sayfa T.               |  ed 2  | <-- Ortak Kod 2
+--------+       +---+               5    +--------+
|  ed 1  |     0 | 3 |                    |        |
+--------+       +---+               6    +--------+
|  ed 2  |     1 | 4 |                    |  ed 3  | <-- Ortak Kod 3
+--------+       +---+               7    +--------+
|  ed 3  |     2 | 6 |                    | data 2 | (P2'nin verisi)
+--------+       +---+                    +--------+
| data 2 |     3 | 7 |
+--------+       +---+

Proses P3       P3 Sayfa T.
+--------+       +---+
|  ed 1  |     0 | 3 |
+--------+       +---+
|  ed 2  |     1 | 4 |
+--------+       +---+
|  ed 3  |     2 | 6 |
+--------+       +---+
| data 3 |     3 | 2 |
+--------+       +---+
```

Görüldüğü üzere `P1`, `P2` ve `P3` proseslerinin sayfa tablolarının ilk üç satırı aynı fiziksel çerçeveleri (`3`, `4` ve `6`) göstermektedir; yalnızca 3. sayfaları olan veri sayfaları (`data 1`, `data 2`, `data 3`) sırasıyla `1`, `7` ve `2` numaralı farklı çerçevelere eşlenmiştir. Ayrıca okuma-yazma izni verilen paylaşımlı sayfalar, prosesler arası haberleşme (**IPC — Shared Memory**) mekanizması olarak da doğrudan kullanılabilir.

---

## 2. Sayfa Tablosu Yapıları (Structure of the Page Table) ve Donanım Mimarileri

### 2.1 Sayfa Tablolarının Büyüklük Problemi

Modern bilgisayarlarda mantıksal adres uzayı çok büyüktür ($2^{32}$ ile $2^{64}$ arası) ve bu durum sayfa tablosunun kendisinin bellekte aşırı yer kaplamasına yol açar.

32 bitlik mantıksal adres uzayına sahip bir sistemi hesaplayalım:
- Mantıksal adres uzayı: $2^{32}\text{ bayt}$ ($4\text{ GB}$).
- Sayfa boyutu (`page size`): $4\text{ KB} = 2^2 \times 2^{10} = 2^{12}\text{ bayt}$.
- Sayfa tablosundaki toplam satır (kayıt / `entry`) sayısı:
  $$\frac{2^{32}}{2^{12}} = 2^{20}\text{ kayıt} \approx 1\text{ milyon kayıt (1,048,576 entry)}$$
- Her sayfa tablosu kaydının $4\text{ bayt}$ ($32\text{ bit}$) olduğunu düşünürsek, **yalnızca tek bir prosesin sayfa tablosu bellekte $4\text{ MB}$ yer kaplar!** Sistemde 100 proses çalışıyorsa yalnız sayfa tabloları için $400\text{ MB}$ RAM gerekir ve üstelik bu $4\text{ MB}$'lık tablonun ana bellekte bitişik olarak tutulması istenmez.

> **Ders sonrası not:** Hoca derste $2^{20}$ kayıtlı tablonun boyutunu hesaplarken önce her kaydı 1 bayt gibi düşünerek *"1 milyon tane entry'den oluşan bir page tablomuz... yani ne oluyor? 1 megabyte'lık bir alandan oluşan"* (00:14:00) demiş, sınıftan bir öğrencinin her kaydın 4 bayt olduğunu söylemesi üzerine ise *"O zaman 4 byte olunca... iki üzeri ikiye böleceğiz. Bu da gigabyte seviyesinde çok çok daha fazla olacak"* (00:14:44) diyerek sayfa boyutunun $4\text{ KB}$ yerine $4\text{ bayt}$ olması durumuyla ($\frac{2^{32}}{2^2} = 2^{30}$) karıştırmıştır. Büyük olasılıkla Silberschatz kitabındaki (Bölüm 8.5) doğru hesaba göre: Sayfa boyutu $4\text{ KB}$ ($2^{12}\text{ bayt}$) iken tablo $2^{20}$ satırdan oluşur ve her satır (entry) $4\text{ bayt}$ olduğundan tablo boyutu $2^{20} \times 4\text{ bayt} = \mathbf{4\text{ MB}}$'tır.

Bu büyük sayfa tablosunu parçalamak ve yönetmek için üç temel yapı geliştirilmiştir:
1. **Hiyerarşik Sayfalama (`Hierarchical Paging`)**
2. **Çırpılı Sayfa Tabloları (`Hashed Page Tables`)**
3. **Ters Çevrilmiş Sayfa Tabloları (`Inverted Page Tables`)**

### 2.2 Hiyerarşik Sayfalama (Hierarchical Paging / Two-Level Page Tables)

Sayfa tablosunu bellekte tek bir bitişik blok olarak tutmak yerine, **sayfa tablosunun kendisi de sayfalanır** (**`Forward-Mapped Page Table`**).

İki seviyeli sayfalama şemasında (ekrandan, 00:18:00), 32 bitlik mantıksal adres üç parçaya bölünür:
- **`p1` (Dış sayfa tablosu indisi — `outer page table`):** Örneğin 12 bit (veya $4\text{ KB}$ sayfada 10 bit).
- **`p2` (İç sayfa tablosu kayması — `page of page table`):** 10 bit.
- **`d` (Sayfa içi kayma — `page offset`):** 10 bit (veya $4\text{ KB}$ sayfada 12 bit).

```text
Mantıksal Adres:
+------+------+------+
|  p1  |  p2  |  d   |
+--+---+--+---+--+---+
   |      |      |
   |      |      |       Dış Sayfa Tablosu      İç Sayfa Tablosu       Fiziksel Bellek
   |      |      |      (Outer Page Table)    (Page of Page Table)        (Bellek)
   |      |      |          +--------+
   +------|------|--------> |   *----|-------> +--------+
          |      |          +--------+         |        |
          +------|---------------------------> |   *----|------------> +--------+
                 |                             +--------+              |        |
                 +---------------------------------------------------> | Hedef  |
                                                                       +--------+
```

**64 Bitlik Sistemlerde Hiyerarşik Sayfalamanın Yetersizliği:**
64 bitlik mantıksal adres uzayında ($2^{64}\text{ bayt}$) sayfa boyutu $4\text{ KB}$ ($2^{12}\text{ bayt}$) alındığında sayfa tablosu $2^{52}$ kayıt içerir! Eğer iki seviyeli sayfalama yapılıp adres `p1 (42 bit) + p2 (10 bit) + d (12 bit)` olarak bölünürse, dış sayfa tablosunun kendisi $2^{42}$ satırdan ($2^{44}\text{ bayt}$) oluşur. Dış tabloyu bir kez daha bölersek (`p1(32 bit) + p2(10 bit) + p3(10 bit) + d(12 bit)`) dış tablo hâlâ $2^{34}\text{ bayt}$ ($16\text{ GB}$) olur ve her bellek erişimi için 4–5 kez sayfa tablosuna erişmek gerekir. Dolayısıyla 64 bit mimarilerde saf hiyerarşik sayfalama çok maliyetlidir.

### 2.3 Çırpılı Sayfa Tabloları (Hashed Page Tables)

32 bitten büyük adres uzaylarında yaygın olarak kullanılan yaklaşımdır (ekrandan, 00:25:00). Sanal sayfa numarası $p$, ortalama $O(1)$ sürede arama sağlayan bir **çırpı fonksiyonundan (`hash function`)** geçirilir:

```text
Mantıksal Adres:                                         Fiziksel Adres:
+-----+-----+                                              +-----+-----+   +----------+
|  p  |  d  | -------------------------------------------> |  r  |  d  | ->| Physical |
+--+--+-----+                                              +-----+-----+   |  Memory  |
   |                                                          ^            +----------+
   v                                                          |
( hash function )                                             |
   |               Hash Table     Bağlı Liste (Çakışma Zinciri)
   |               +--------+     +---+---+---+   +---+---+---+
   +-------------> |   *----|---> | q | s | *-|-> | p | r | *-|-> ...
                   +--------+     +---+---+---+   +---+---+---+
```

- Çırpı tablosundaki her kayıt, aynı çırpı değerine düşen (çakışan / *collision*) elemanların tutulduğu bir **bağlı listeye (`linked list` — kapalı adresleme / zincirleme)** işaret eder.
- Bağlı listedeki her düğüm üç alandan oluşur: **1) Sanal sayfa numarası (`p`)**, **2) Eşlenen fiziksel çerçeve numarası (`r`)**, **3) Listedeki bir sonraki düğümün işaretçisi (`next pointer`)**.
- Arama yapılırken bağlı listedeki birinci düğümün sanal sayfa numarasına (`q`) bakılır; aranan `p` değilse sonraki düğüme geçilir, `p` bulunduğunda karşısındaki `r` çerçeve numarası alınıp `d` kaymasıyla birleştirilerek fiziksel adrese ulaşılır.

### 2.4 Ters Çevrilmiş Sayfa Tabloları (Inverted Page Tables)

Normal sayfalamada her prosesin kendine ait bir sayfa tablosu vardır ve tablo sanal sayfalara göre indekslenir. **Ters Çevrilmiş Sayfa Tablosunda (`Inverted Page Table`)** ise yaklaşım tam tersine çevrilir: Tüm sistemde yalnızca **tek bir sayfa tablosu** tutulur ve bu tablo fiziksel bellekteki **çerçeve numaralarına (`frame number`)** göre indekslenir (ekrandan, 00:27:45).

```text
             Mantıksal Adres:
+-----+      +-----+-----+-----+          Fiziksel Adres:
| CPU | ---> | pid |  p  |  d  | ------> +-----+-----+      +-----------------+
+-----+      +--+--+--+--+-----+         |  i  |  d  | ---> | Physical Memory |
                |     |                  +-----+-----+      +-----------------+
                v     v                     ^
              +---------+                   |
     search   |   ...   |  } i (kaçıncı     |
       |      +----+----+    satırda        |
       v      | pid|  p | ---bulunduysa o---+
              +----+----+    indis = frame no)
              |   ...   |
              +---------+
           Inverted Page Table
```

- Fiziksel bellekte $N$ adet çerçeve varsa, ters çevrilmiş sayfa tablosunda da tam olarak $N$ adet satır vardır (`0`. satır 0. çerçeveyi, `i`. satır `i`. çerçeveyi temsil eder).
- Her satırda o çerçeveye hangi prosesin (**`pid` — Process ID**) hangi sanal sayfasının (**`p`**) yüklendiği bilgisi (`<pid, p>`) tutulur.
- **Avantajı:** Her proses için ayrı tablo tutma maliyetini ortadan kaldırır; tablo boyutu sanal adres uzayına değil, yalnız fiziksel RAM miktarına bağlıdır.
- **Dezavantajı:** Bir adres referansı geldiğinde tablo fiziksel adrese göre sıralı olduğu için `<pid, p>` ikilisini bulmak üzere tüm tablonun taranması gerekir (arama süresini uzatır; bunu hızlandırmak için çırpı tablosu veya TLB kullanılır). Ayrıca fiziksel bir çerçeveye aynı anda tek bir `<pid, p>` yazılabildiği için **paylaşımlı bellek (`shared memory`)** gerçeklemesi zordur.

### 2.5 Gerçek Mimari Örnekleri: SPARC Solaris, Intel IA-32 / x86-64 ve ARM (CISC vs. RISC)

Hoca bölüm sonunda gerçek işlemci mimarilerinin bellek yönetimini karşılaştırdı:
- **Oracle SPARC Solaris (64-bit):** Düz hiyerarşik tablolar yerine biri çekirdek (`kernel`), diğeri kullanıcı prosesleri (`user processes`) için olmak üzere **iki adet çırpı tablosu (TSB — Translation Storage Buffer)** ve TLB kullanır.
- **Intel IA-32 Mimarisi:** Hem saf kesimlemeyi hem de **sayfalamalı kesimlemeyi (`segmentation with paging`)** destekler:
  $$\text{CPU (Mantıksal Adres)} \to \text{Segmentation Unit (Doğrusal / Linear Adres)} \to \text{Paging Unit (Fiziksel Adres)}$$
  Her kesim $4\text{ GB}$'a kadar olabilir; proses başına en fazla $16\text{ K}$ kesim ikiye ayrılır: birinci $8\text{ K}$ kesim prosese özel **Yerel Tanımlayıcı Tablosunda (`LDT — Local Descriptor Table`)**, ikinci $8\text{ K}$ kesim ise diğer proseslerle paylaşılan **Küresel Tanımlayıcı Tablosunda (`GDT — Global Descriptor Table`)** tutulur. Sayfalama birimi ise $4\text{ KB}$ (veya $4\text{ MB}$) sayfalarla iki seviyeli (`Page Directory (10 bit) + Page Table (10 bit) + Offset (12 bit)`) çalışır.
- **Intel x86-64 Mimarisi:** 64 bitin tamamı çok devasa (*ginormous*) olduğu için pratikte **48 bitlik** sanal adresleme ve **4 seviyeli hiyerarşik sayfalama** (`Page Map Level 4 -> Page Directory Pointer -> Page Directory -> Page Table -> 12-bit Offset`) kullanılır.
- **ARM Mimarisi (32-bit) ve CISC / RISC Farkı:** Telefon ve tabletlerde yaygın olan ARM işlemciler `4 KB`/`16 KB` sayfalar ile `1 MB`/`16 MB` bölümleri (*sections*) bir arada ve bir/iki seviyeli sayfalama ile kullanır.
  - Hoca burada Intel/AMD (**CISC — Complex Instruction Set Computer**) ile ARM/PIC (**RISC — Reduced Instruction Set Computer**) arasındaki mimari farkı açıkladı:
  - **CISC (`8086` vb.):** Çok sayıda ve çok yetenekli komut içerir (`CMP AX, BX`, `JC label`, `LOOP` gibi komutlarla doğrudan karşılaştırma ve etikete dallanma yapılabilir); komut uzunlukları (1 bayt, 2 bayt vb.) ve çalışma süreleri (1 veya birkaç clock cycle) değişkendir.
  - **RISC:** Az sayıda, sabit uzunluklu ve basit komutlar içerir. Doğrudan `CMP` ve etiketli koşullu dallanma yerine çıkarma (`SUB`) sonrası elde bayrağını (`Carry/Borrow flag`) test edip bir sonraki komutu atlayan (`BTFSC` — *Bit Test File, Skip if Clear* gibi) komutlar kullanılır. Bu nedenle RISC mimaride dallanmalar ve bellek adres geçişleri daha sık gerçekleşir ve bellek yönetimi doğrudan donanım mimarisine bağımlıdır.

---

## 3. Sanal Bellek (Virtual Memory), İstek Üzerine Sayfalama (Demand Paging) ve Başarım Analizi

### 3.1 Sanal Bellek (Virtual Memory) Neden Gereklidir?

8. Bölüm'de incelenen bellek yönetimi stratejilerinde, bir prosesin çalıştırılabilmesi için **tüm sayfalarının (veya kesimlerinin) çalışma öncesinde ana bellekte (RAM'de) bulunması gerektiği** varsayılmıştı. Oysa gerçekte:
- Nadiren oluşan hata durumlarını işleyen kodlar (`error-handling routines`),
- Kullanılmayan alt yordamlar (`unusual routines`),
- İhtiyaç duyulandan çok daha büyük tanımlanmış diziler, listeler ve tablolar
çoğu zaman hiç kullanılmaz. Üstelik bir proses bellekte ne kadar büyük yer kaplarsa kaplasın, işlemci (CPU) herhangi bir $t$ anında o prosesin yalnızca **tek bir komut satırını** ve o komutun ihtiyaç duyduğu **tek bir veriyi** işler.

**Sanal Bellek (`Virtual Memory`):** Kullanıcıların gördüğü mantıksal belleği fiziksel RAM'den tamamen ayırarak, bir programın **yalnızca o an ihtiyaç duyulan kısmının** ana bellekte tutulmasını, geri kalan sayfalarının ise sabit disk üzerindeki rezerve alanda (`backing store`) bekletilmesini sağlayan tekniktir. Sağladığı temel kazanımlar şunlardır:
1. Mantıksal adres uzayı fiziksel RAM boyutundan çok daha büyük olabilir.
2. Her proses RAM'de çok daha az çerçeve işgal edeceği için aynı anda bellekte 5 proses yerine 50 proses tutulabilir; böylece **çoklu programlama derecesi (`degree of multiprogramming`)**, **etkileşimlilik (`interactivity`)** ve **işlemci kullanımı (`CPU utilization`)** artar.
3. Proseslerin bütün halinde diske yazılıp okunması (`swapping`) yerine yalnız tekil sayfalar taşındığı için G/Ç yükü azalır.

### 3.2 İstek Üzerine Sayfalama (Demand Paging) ve Tembel Takasçı (Lazy Swapper)

Sanal bellek genellikle **İstek Üzerine Sayfalama (`Demand Paging`)** ile gerçeklenir: Bir sayfa, çalışan proses tarafından açıkça **talep edilmedikçe (referans verilmedikçe)** ana belleğe getirilmez.

- **Tembel Takasçı (`Lazy Swapper` / `Pager`):** Bir sayfayı ihtiyaç duyulmadıkça hiçbir zaman belleğe getirmeyen takas mekanizmasıdır (bütün proseslerle uğraşan *swapper* yerine tekil sayfalarla ilgilenen birime **`pager`** denir).
- **Geçerli-Geçersiz Biti (`Valid-Invalid Bit`) ile Kontrol (ekrandan, 00:50:00):**

```text
Mantıksal Bellek     Sayfa Tablosu        Fiziksel Bellek (RAM)       Disk (Backing Store)
   0 [ A ]            0 [ 4 | v ]            0 [   ]
   1 [ B ]            1 [   | i ]            ...                      [ A ] [ B ]
   2 [ C ]            2 [ 6 | v ]            4 [ A ]                  [ C ] [ D ]
   3 [ D ]            3 [   | i ]            5 [   ]                  [ E ] [ F ]
   4 [ E ]            4 [   | i ]            6 [ C ]                  [ G ] [ H ]
   5 [ F ]            5 [ 9 | v ]            ...
   6 [ G ]            6 [   | i ]            9 [ F ]
   7 [ H ]            7 [   | i ]
```

Burada prosesin `0..7` (`A..H`) sayfalarının tamamının kopyası disk üzerinde durmaktadır; ancak ana bellekte yalnızca `A` (Frame 4), `C` (Frame 6) ve `F` (Frame 9) sayfaları yüklüdür ve sayfa tablosunda yalnız bu üç satırın biti **`v` (`valid`)** durumundadır. Diğer tüm sayfaların biti **`i` (`invalid`)** olarak işaretlenmiştir.

### 3.3 Sayfa Hatası (Page Fault) ve İşlenme Adımları

Proses çalışırken bellekte yüklü olan (`v`) sayfalara eriştiğinde işlem normal hızında devam eder. Ancak proses, sayfa tablosunda biti **`i` (`invalid`)** olan bir sayfaya (örneğin yukarıdaki tabloda 3. sayfadaki `D` verisine) erişmeye çalışırsa donanım işletim sistemine bir **Sayfa Hatası Tuzağı (`Page Fault Trap`)** üretir ve şu 6 adım sırasıyla işletilir:

```text
1. CPU bellekte olmayan bir sayfaya referans verir (load M).
2. Sayfa tablosunda bit 'i' olduğu için işletim sistemine tuzak (Page Fault Trap) üretilir.
3. İşletim sistemi iç tablodan referansın geçersiz mi (abort) yoksa sadece diskte mi olduğuna bakar;
   diskte ise ilgili sayfayı backing store üzerinde bulur.
4. Boş bir çerçeve (free frame) bulunur ve diskten okuma işlemiyle sayfa bu çerçeveye getirilir.
5. Disk okuması bittiğinde iç tablo ve sayfa tablosu güncellenir (bit 'v' yapılır).
6. Kesintiye uğrayan komut (instruction) baştan yeniden çalıştırılır (restart instruction).
```

#### Saf İstek Üzerine Sayfalama (`Pure Demand Paging`):

En uç yaklaşım, bir prosesi başlatırken ana belleğe **hiçbir sayfasını yüklemeden** başlatmaktır (**`Pure Demand Paging`** — *"hiçbir sayfayı talep edilmeden belleğe getirme"*). Hoca bunu "sipariş gelmeden tek bir vida bile üretmeyen bir fabrikaya" benzetti: İlk komut çalıştırılır çalıştırılmaz sayfa hatası oluşur, ardı ardına gelen sayfa hataları ve komutların sürekli yarıda kesilip baştan başlatılması (`instruction restart`) işlemciyi boşta bekletir ve başlangıçta ciddi gecikme yaratır. Neyse ki programların **referans yerelliği (`locality of reference`)** özelliği sayesinde bir grup sayfa belleğe alındıktan sonra sayfa hatası oranı hızla düşer.

### 3.4 İstek Üzerine Sayfalamanın Başarımı ve Etkin Erişim Süresi (EAT)

Sayfa hatası oluşmadığı sürece etkin erişim süresi ana bellek erişim süresine ($\text{ma}$) eşittir. Ancak $p$ olasılıkla ($0 \le p \le 1$; $p = 0$ hiç sayfa hatası yok, $p = 1$ her erişim sayfa hatası) bir sayfa hatası oluştuğunda:
1. İşletim sistemine tuzak (`trap`) kurulması ve proses durumunun (yazmaçların / PCB'nin) kaydedilmesi,
2. Kesmenin bir sayfa hatası olduğunun ve referansın yasal olduğunun belirlenmesi,
3. Diskten sayfanın boş çerçeveye okunması (kuyrukta bekleme + arama süresi `seek` + dönme gecikmesi `latency` + aktarım süresi — en büyük zaman maliyeti burasıdır!),
4. Bu sırada işlemcinin başka bir prosese tahsis edilmesi ve disk G/Ç tamamlandığında kesmeyle sayfa tablosunun güncellenip prosesin tekrar hazır (`ready`) kuyruğuna alınması gerekir.

Buna göre **Etkin Erişim Süresi (`Effective Access Time — EAT`)** formülü (ekrandan, 00:56:45):
$$\text{EAT} = (1 - p) \times \text{bellek erişim süresi} + p \times \text{sayfa hatası servis süresi}$$

#### Sayısal Başarım Örneği (ekrandan, 00:56:45):

- **Verilenler:**
  - Ana bellek erişim süresi (`memory access time`): $200\text{ nanosaniye (ns)}$
  - Ortalama sayfa hatası servis süresi (`average page-fault service time`): $8\text{ milisaniye (ms)} = 8{,}000\text{ }\mu\text{s} = 8{,}000{,}000\text{ ns}$
- **Genel Denklemin Kurulması:**
  $$\text{EAT} = (1 - p) \times 200 + p \times 8{,}000{,}000 = 200 - 200p + 8{,}000{,}000p = 200 + p \times 7{,}999{,}800\text{ ns}$$
- **Durum 1: Binde 1 erişimde sayfa hatası olursa ($p = \frac{1}{1{,}000} = 0.001$):**
  $$\text{EAT} = 200 + 0.001 \times 7{,}999{,}800 = 200 + 7{,}999.8 = 8{,}199.8\text{ ns} \approx \mathbf{8.2\text{ mikrosaniye ($\mu$s)}}$$
  Normalde $200\text{ ns}$ olan erişim süresi $8{,}200\text{ ns}$'ye çıkmıştır; yani sistem $\frac{8200}{200} \approx \mathbf{40\text{ kat yavaşlamıştır}}$ (`slowdown by a factor of 40`)!
- **Durum 2: Başarım kaybının (yavaşlamanın) %10'dan az olması istenirse ($\text{EAT} < 200 \times 1.10 = 220\text{ ns}$):**
  $$220 > 200 + 7{,}999{,}800 \times p \implies 20 > 7{,}999{,}800 \times p \implies p < \frac{20}{7{,}999{,}800} \approx \mathbf{0.0000025}$$
  Bu sonuç, %10'dan az başarım kaybı için **her $400{,}000$ bellek erişiminde en fazla 1 sayfa hatası** oluşması gerektiğini gösterir!

---

## 4. Yazarken Kopyalama (Copy-on-Write) ve Sayfa Değiştirme (Page Replacement) Temelleri

### 4.1 Yazarken Kopyalama (Copy-on-Write — COW) ve `vfork()`

`fork()` sistem çağrısıyla yeni bir alt proses (`child process`) oluşturulduğunda, klasik yaklaşımda ebeveyn prosesin tüm sayfaları çocuk proses için kopyalanır. Oysa birçok çocuk proses `fork()` sonrasında hemen `exec()` çağırarak kendi adres uzayına bambaşka bir program yükler ve kopyalanan sayfaları hiç kullanmaz.

- **Copy-on-Write (COW):** Ebeveyn ve çocuk proseslerin başlangıçta bellekteki **aynı fiziksel sayfaları ortak paylaşmasını** sağlar. Ortak sayfalar "yazarken kopyala" olarak işaretlenir. İki prosesten hiçbiri yazma yapmadığı sürece (`Page A` ve `Page B` gibi) aynı çerçeveler paylaşılır; ancak proseslerden biri paylaşılan bir sayfayı (örneğin `Page C`'yi) değiştirmeye (yazmaya) kalkarsa, yalnız o anda `Page C`'nin yeni bir kopyası (`copy of Page C`) boş bir çerçevede oluşturulur.
- **`vfork()` (Virtual Memory Fork):** Ebeveyn prosesi askıya alır (`suspend`) ve çocuk prosesin doğrudan ebeveynin adres uzayını (Copy-on-Write kullanmadan) kullanmasını sağlar; çocuk proses hemen `exec()` çağırdığı durumlarda çok hızlıdır, ancak çocuk proses ebeveynin sayfalarını değiştirirse ebeveyn tekrar uyandığında bu değişiklikleri görür.

### 4.2 Sayfa Değiştirme (Page Replacement) ve Kirli Bit (`Modify / Dirty Bit`)

Bellek aşırı tahsis edildiğinde (`over-allocation`), bir sayfa hatası oluştuğunda boş çerçeve (`free frame`) bulunamayabilir. Bu durumda işletim sistemi bellekteki mevcut çerçevelerden birini **kurban (`victim`)** seçip diske çıkararak boşaltmak zorundadır.

#### Değiştirilme / Kirli Biti (`Modify / Dirty Bit`):

Kurban seçilen bir çerçeve boşaltılırken her seferinde diske yazılması gerekmez. Donanım tarafından sayfa tablosundaki her satır için bir **değiştirilme biti (`modify bit` veya `dirty bit`)** tutulur:
- Sayfa belleğe yüklendiğinde `dirty bit = 0` olarak başlar.
- İşlemci o sayfaya herhangi bir **yazma (değişiklik)** işlemi yaparsa donanım `dirty bit = 1` yapar (hoca bunu Word belgesinde değişiklik yapıldığında dosya adının yanında beliren `*` işaretine benzetti).
- Sayfa kurban seçilip bellekten çıkarılırken:
  - Eğer **`dirty bit == 1`** ise: Sayfa bellekteyken değiştirilmiştir; güncel halinin kaybolmaması için **diske geri yazılması zorunludur** (1 disk yazma + 1 yeni sayfa okuma = **2 sayfa aktarımı**).
  - Eğer **`dirty bit == 0`** ise: Sayfa belleğe geldiğinden beri hiç değiştirilmemiştir, diskteki kopyası zaten bire bir aynıdır; diske geri yazmadan doğrudan üzerine yeni sayfa okunur (**yalnız 1 sayfa aktarımı**, G/Ç süresi yarıya iner!).

#### Temel Sayfa Değiştirme Adımları:

1. İstenen sayfanın disk üzerindeki konumunu bul.
2. Boş bir çerçeve (`free frame`) bul:
   - Boş çerçeve varsa onu kullan.
   - Boş çerçeve yoksa **kurban çerçeveyi (`victim frame`)** seçmek için bir **sayfa değiştirme algoritması** çalıştır.
   - Eğer kurban çerçevenin `dirty` biti `1` ise kurban sayfayı diske yaz; sayfa ve çerçeve tablolarını güncelle (`i` yap).
3. İstenen sayfayı boşaltılan çerçeveye oku; sayfa ve çerçeve tablolarını güncelle (`v` yap).
4. Kesilen kullanıcı prosesini kaldığı komuttan devam ettir (`restart`).

---

## 5. Sayfa Değiştirme Algoritmaları: FIFO, Belady Anomalisi, Optimal (OPT), LRU ve İkinci Şans

Sayfa değiştirme algoritmalarının amacı **en düşük sayfa hatası oranını (`lowest page-fault rate`)** sağlamaktır. Algoritmaları değerlendirmek için ardışık bellek referanslarından oluşan bir **referans dizgesi (`reference string`)** kullanılır.

Ders boyunca tüm algoritmalar şu 20 elemanlı standart referans dizgesi ve **3 çerçeve (`3 frames`, başlangıçta boş)** üzerinde karşılaştırılmıştır:
$$\text{Referans Dizgesi: } \mathbf{7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2, 1, 2, 0, 1, 7, 0, 1}$$

### 5.1 İlk Giren İlk Çıkar (FIFO — First-In-First-Out) Algoritması

Belleğe **en erken girmiş (en yaşlı) olan sayfayı** kurban seçip çıkarır; gerçeklemesi için sayfaların geliş sırasını tutan basit bir **FIFO kuyruğu** yeterlidir (ekrandan, 01:30:00).

**3 Çerçeve İçin Adım Adım FIFO Çözümü (`*` = Sayfa Hatası):**

```text
Referans:  7*  0*  1*  2*  0   3*  0*  4*  2*  3*  0*  3   2   1*  2*  0   1   7*  0*  1*
         +---+---+---+---+   +---+---+---+---+---+   +   +---+---+   +   +---+---+---+
Çerçeve 1| 7 | 7 | 7 | 2 | . | 2 | 2 | 4 | 4 | 4 | 0 | . | . | 0 | 0 | . | . | 7 | 7 | 7 |
         +---+---+---+---+   +---+---+---+---+---+   +   +---+---+   +   +---+---+---+
Çerçeve 2|   | 0 | 0 | 0 | . | 3 | 3 | 3 | 2 | 2 | 2 | . | . | 1 | 1 | . | . | 1 | 0 | 0 |
         +---+---+---+---+   +---+---+---+---+---+   +   +---+---+   +   +---+---+---+
Çerçeve 3|   |   | 1 | 1 | . | 1 | 0 | 0 | 0 | 3 | 3 | . | . | 3 | 2 | . | . | 2 | 2 | 1 |
         +---+---+---+---+   +---+---+---+---+---+   +   +---+---+   +   +---+---+---+
```

1. `7, 0, 1`: İlk 3 çerçeve boş olduğu için sırasıyla yerleşirler (**3 sayfa hatası**; bellekteki geliş sırası: `7, 0, 1`).
2. `2`: Bellekte yok (**4. hata**). İlk giren `7` çıkarılır, yerine `2` konur (`[2, 0, 1]`).
3. `0`: Bellekte var (hata yok).
4. `3`: Bellekte yok (**5. hata**). En eski kalan `0` çıkarılır, yerine `3` konur (`[2, 3, 1]`).
5. `0`: Az önce çıkarılan `0` hemen tekrar istendi! (**6. hata**). En eski kalan `1` çıkarılır, yerine `0` konur (`[2, 3, 0]`).
6. `4`: Bellekte yok (**7. hata**). `2` çıkarılır, yerine `4` konur (`[4, 3, 0]`).
7. `2`: Bellekte yok (**8. hata**). `3` çıkarılır, yerine `2` konur (`[4, 2, 0]`).
8. `3`: Bellekte yok (**9. hata**). `0` çıkarılır, yerine `3` konur (`[4, 2, 3]`).
9. `0`: Bellekte yok (**10. hata**). `4` çıkarılır, yerine `0` konur (`[0, 2, 3]`).
10. `3, 2`: Her ikisi de bellekte var (hata yok).
11. `1`: Bellekte yok (**11. hata**). `2` çıkarılır, yerine `1` konur (`[0, 1, 3]`).
12. `2`: Bellekte yok (**12. hata**). `3` çıkarılır, yerine `2` konur (`[0, 1, 2]`).
13. `0, 1`: Her ikisi de bellekte var (hata yok).
14. `7`: Bellekte yok (**13. hata**). `0` çıkarılır, yerine `7` konur (`[7, 1, 2]`).
15. `0`: Bellekte yok (**14. hata**). `1` çıkarılır, yerine `0` konur (`[7, 0, 2]`).
16. `1`: Bellekte yok (**15. hata**). `2` çıkarılır, yerine `1` konur (`[7, 0, 1]`).
- **Sonuç:** FIFO algoritması 3 çerçeveyle toplam **15 sayfa hatası** üretmiştir.

#### Derste 4 Çerçeve İçin Çözülen FIFO Uygulaması (`01:31:53`):

Hoca aynı referans dizgesini (`7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2, 1, 2, 0, 1, 7, 0, 1`) sınıfla birlikte **4 çerçeve** için adım adım çözdü:
- `7, 0, 1, 2` $\implies$ `[7, 0, 1, 2]` (4 hata),
- `0` $\implies$ bellekte var,
- `3` $\implies$ `7` çıkar, `[3, 0, 1, 2]` (5. hata),
- `0` $\implies$ bellekte var,
- `4` $\implies$ `0` çıkar, `[3, 4, 1, 2]` (6. hata),
- `2, 3` $\implies$ bellekte var,
- `0` $\implies$ `1` çıkar, `[3, 4, 0, 2]` (7. hata),
- `3, 2` $\implies$ bellekte var,
- `1` $\implies$ `2` çıkar, `[3, 4, 0, 1]` (8. hata),
- `2` $\implies$ `3` çıkar, `[2, 4, 0, 1]` (9. hata),
- `0, 1` $\implies$ bellekte var,
- `7` $\implies$ `4` çıkar, `[2, 7, 0, 1]` (10. hata — *Not: Hoca slayt üzerinde hızlıca yazarken bu adımda `0` yerine `7` yazıp son iki adımda `0` ve `1` için de değişim göstermiştir; kesin FIFO sırasıyla `4` en eski olduğundan `4` çıkar ve son iki referans olan `0, 1` zaten bellekte bulunduğu için toplam **10 sayfa hatası** oluşur*).

#### Belady Anomalisi (`Belady's Anomaly`, ekrandan, 01:30:00):

Normalde bir prosese verilen çerçeve sayısı artırıldığında sayfa hatası sayısının azalması beklenir. Ancak **`1, 2, 3, 4, 1, 2, 5, 1, 2, 3, 4, 5`** referans dizgesi FIFO algoritmasıyla çalıştırıldığında:
- **1 çerçeve:** 12 sayfa hatası,
- **2 çerçeve:** 12 sayfa hatası,
- **3 çerçeve:** **9 sayfa hatası**,
- **4 çerçeve:** **10 sayfa hatası**!
Görüldüğü gibi çerçeve sayısı 3'ten 4'e çıkarıldığında sayfa hatası sayısı azalmak yerine **9'dan 10'a yükselmiştir**. Prosese tahsis edilen çerçeve sayısı artırıldığında sayfa hatası oranının artması durumuna **Belady Anomalisi (`Belady's Anomaly`)** denir.

> **Ders sonrası not:** Hoca derste çerçeve sayısı – sayfa hatası grafiğini ilk gösterirken *"Bir prosese atanan frame sayısının çok fazla olması illaki page fault hatasını azaltacak, minimize edecek değil, bir yerden sonra sabit bırakıyor. Buna Belady'nin anomalisi demişler"* (01:28:02) demiş, hemen ardından slayt 9.32 ve 9.33'teki grafikte (`01:33:20`) *"Üç olduğunda biraz azalıyormuş, dört olduğunda artıyormuş. Her proses için illaki arttırdığında azalacağı anlamına gelmiyor"* diyerek doğru durumu açıklamıştır. Büyük olasılıkla literatürdeki kesin tanıma göre **Belady Anomalisi**, çerçeve sayısı arttığında sayfa hatalarının sabit kalması değil, **artması** olgusudur.

### 5.2 Optimal (OPT / MIN) Sayfa Değiştirme Algoritması

Belady anomalisinin keşfinden sonra, tüm algoritmalar arasında en düşük sayfa hatası oranını veren ve Belady anomalisinden hiç etkilenmeyen **Optimal Algoritma** tanımlanmıştır (ekrandan, 01:34:15):
- **Kural:** **Gelecekte en uzun süre boyunca kullanılmayacak olan sayfayı (`page that will not be used for longest period of time`)** kurban seçip değiştir.

**3 Çerçeve İçin Adım Adım Optimal Çözüm (`*` = Sayfa Hatası):**

```text
Referans:  7*  0*  1*  2*  0   3*  0   4*  2   3   0   3   2   1*  2   0   1   7*  0   1
         +---+---+---+---+   +---+   +---+                   +---+           +---+
Çerçeve 1| 7 | 7 | 7 | 2 | . | 2 | . | 2 | .   .   .   .   . | 2 | .   .   . | 7 | .   .
         +---+---+---+---+   +---+   +---+                   +---+           +---+
Çerçeve 2|   | 0 | 0 | 0 | . | 0 | . | 4 | .   .   .   .   . | 0 | .   .   . | 0 | .   .
         +---+---+---+---+   +---+   +---+                   +---+           +---+
Çerçeve 3|   |   | 1 | 1 | . | 3 | . | 3 | .   .   .   .   . | 1 | .   .   . | 1 | .   .
         +---+---+---+---+   +---+   +---+                   +---+           +---+
```

1. `7, 0, 1`: İlk 3 boş çerçeveye yerleşir (**3 sayfa hatası**).
2. `2`: Bellekte `[7, 0, 1]` var (**4. hata**). İleriye (`0, 3, 0, 4, 2, 3, 0, 3, 2, 1, 2, 0, 1, 7...`) bakılır: `0` hemen 1 adım sonra, `1` 10 adım sonra, `7` ise 14 adım sonra kullanılacaktır. En geç kullanılacak olan **`7` çıkarılır**, yerine `2` konur (`[2, 0, 1]`).
3. `0`: Bellekte var.
4. `3`: Bellekte `[2, 0, 1]` var (**5. hata**). İleriye bakılır: `0` hemen 1 adım sonra, `2` 3 adım sonra, `1` ise 8 adım sonra kullanılacaktır. En geç kullanılacak olan **`1` çıkarılır**, yerine `3` konur (`[2, 0, 3]`).
5. `0`: Bellekte var.
6. `4`: Bellekte `[2, 0, 3]` var (**6. hata**). İleriye bakılır: `2` 1 adım sonra, `3` 2 adım sonra, `0` ise 3 adım sonra kullanılacaktır. **`0` çıkarılır**, yerine `4` konur (`[2, 4, 3]`).
7. `2, 3`: Bellekte var.
8. `0`: Bellekte `[2, 4, 3]` var (**7. hata**). İleride `4` bir daha hiç kullanılmayacağı için **`4` çıkarılır**, yerine `0` konur (`[2, 0, 3]`).
9. `3, 2`: Bellekte var.
10. `1`: Bellekte `[2, 0, 3]` var (**8. hata**). İleride `3` bir daha hiç kullanılmayacağı için **`3` çıkarılır**, yerine `1` konur (`[2, 0, 1]`).
11. `2, 0, 1`: Bellekte var.
12. `7`: Bellekte `[2, 0, 1]` var (**9. hata**). İleride `2` bir daha kullanılmayacağı için **`2` çıkarılır**, yerine `7` konur (`[7, 0, 1]`).
13. `0, 1`: Bellekte var.
- **Sonuç:** Optimal algoritma yalnızca **9 sayfa hatası** üretmiştir.

**Soru:** Gelecekte hangi sayfanın ne zaman isteneceğini bilemeyeceğimize göre, gerçekte uygulayamayacağımız Optimal algoritmayı neden öğreniyoruz?
**Cevap:** Hoca bunu Gezgin Satıcı Problemindeki (TSP) veya bir optimizasyon fonksiyonundaki teorik optimum noktaya benzetti: Optimal algoritma gerçek zamanlı işletim sisteminde uygulanamaz (çünkü geleceği okuyamayız); ancak tasarladığımız diğer algoritmaların (FIFO, LRU vb.) **ne kadar iyi çalıştığını ölçmek için bir kıyaslama ölçütü (`benchmark`)** olarak kullanılır. Bir algoritma 9 hataya ne kadar yaklaşıyorsa o kadar başarılıdır.

### 5.3 En Uzun Süredir Kullanılmayan (LRU — Least Recently Used) Algoritması

Optimal algoritma geleceğe bakarken, **LRU (`Least Recently Used`)** algoritması yakın geçmişi geleceğin bir tahmini olarak kullanır ve **geçmişte en uzun süredir kullanılmamış (erişilmemiş) olan sayfayı** kurban seçer (ekrandan, 01:35:30).

**3 Çerçeve İçin Adım Adım LRU Çözümü (`*` = Sayfa Hatası):**

```text
Referans:  7*  0*  1*  2*  0   3*  0   4*  2*  3*  0*  3   2   1*  2   0*  1   7*  0   1
         +---+---+---+---+   +---+   +---+---+---+---+       +---+   +---+   +---+
Çerçeve 1| 7 | 7 | 7 | 2 | . | 2 | . | 4 | 4 | 4 | 0 | .   . | 1 | . | 1 | . | 1 | .   .
         +---+---+---+---+   +---+   +---+---+---+---+       +---+   +---+   +---+
Çerçeve 2|   | 0 | 0 | 0 | . | 0 | . | 0 | 0 | 3 | 3 | .   . | 3 | . | 0 | . | 0 | .   .
         +---+---+---+---+   +---+   +---+---+---+---+       +---+   +---+   +---+
Çerçeve 3|   |   | 1 | 1 | . | 3 | . | 3 | 2 | 2 | 2 | .   . | 2 | .   2 | . | 7 | .   .
         +---+---+---+---+   +---+   +---+---+---+---+       +---+   +---+   +---+
```

1. `7, 0, 1`: İlk 3 çerçeveye yerleşir (**3 hata**).
2. `2`: Bellekte `[7, 0, 1]` var (**4. hata**). Geriye doğru bakıldığında en son `1`, ondan önce `0`, en eski `7` kullanılmıştır; **`7` çıkarılır** (`[2, 0, 1]`).
3. `0`: Bellekte var (ve `0` en yakın kullanılan sayfa haline gelir!).
4. `3`: Bellekte `[2, 0, 1]` var (**5. hata**). Geriye doğru bakıldığında en son `0`, ondan önce `2`, en eski ise `1` kullanılmıştır. Dolayısıyla FIFO'dan farklı olarak `0` değil, **`1` çıkarılır** (`[2, 0, 3]`).
5. `0`: Bellekte var.
6. `4`: Bellekte `[2, 0, 3]` var (**6. hata**). Geriye bakıldığında en eski kullanılan **`2` çıkarılır** (`[4, 0, 3]`).
7. `2`: Bellekte `[4, 0, 3]` var (**7. hata**). En eski kullanılan **`3` çıkarılır** (`[4, 0, 2]`).
8. `3`: Bellekte `[4, 0, 2]` var (**8. hata**). En eski kullanılan **`0` çıkarılır** (`[4, 3, 2]`).
9. `0`: Bellekte `[4, 3, 2]` var (**9. hata**). En eski kullanılan **`4` çıkarılır** (`[0, 3, 2]`).
10. `3, 2`: Bellekte var.
11. `1`: Bellekte `[0, 3, 2]` var (**10. hata**). En eski kullanılan **`0` çıkarılır** (`[1, 3, 2]`).
12. `2`: Bellekte var.
13. `0`: Bellekte `[1, 3, 2]` var (**11. hata**). En eski kullanılan **`3` çıkarılır** (`[1, 0, 2]`).
14. `1`: Bellekte var.
15. `7`: Bellekte `[1, 0, 2]` var (**12. hata**). En eski kullanılan **`2` çıkarılır** (`[1, 0, 7]`).
16. `0, 1`: Bellekte var.
- **Sonuç:** LRU algoritması **12 sayfa hatası** üretmiştir (FIFO'nun 15 hatasından çok daha iyi, Optimal'in 9 hatasına yakındır).

#### LRU Gerçeklemesi ve Yığın (Stack) / İkinci Şans (Second-Chance) Algoritmaları:

- **Sayaç (`Counter`) veya Yığın (`Stack`) Gerçeklemesi:** LRU'yu gerçeklemek için ya her sayfa referansında zaman sayacı kaydedilir ya da çift yönlü bağlı liste şeklinde bir **yığın (`stack`)** tutulur; bir sayfaya erişildiğinde o sayfa yığının ortasından çekilip en tepeye (`top`) konur, böylece en altta (`bottom`) her zaman LRU sayfası kalır. Hem OPT hem de LRU **yığın algoritmaları (`stack algorithms`)** sınıfındadır ve **Belady anomalisi göstermezler**.
- **İkinci Şans (`Second-Chance` / `Clock`) Algoritması:** Tam LRU donanım desteği olmadığında kullanılan bir LRU yaklaşıklamasıdır. Temelde FIFO sırasıyla ilerler ancak her sayfanın bir **referans biti (`reference bit`)** vardır:
  - Sıradaki sayfanın referans biti **`0`** ise $\implies$ doğrudan kurban seçilip değiştirilir.
  - Sıradaki sayfanın referans biti **`1`** ise $\implies$ sayfaya **ikinci bir şans (`second chance`)** verilir: referans biti `0` yapılır, geliş zamanı güncellenerek kuyruğun sonuna bırakılır ve bir sonraki sayfaya bakılır.

---

## 6. Çerçeve Tahsisi (Frame Allocation), Çırpınma (Thrashing) ve Çalışma Kümesi (Working-Set) Modeli

### 6.1 Çerçeve Tahsisi: Eşit (Equal) ve Orantılı (Proportional) Tahsis

Sistemdeki toplam $m$ adet boş çerçeveyi $n$ adet aktif proses arasında nasıl paylaştıracağımızı belirleyen iki temel sabit tahsis yöntemi vardır:
1. **Eşit Tahsis (`Equal Allocation`):** Her prosese eşit sayıda ($m / n$) çerçeve verilir (örneğin 100 çerçeve ve 5 proses varsa her birine 20 çerçeve). Ancak 8 sayfalık küçük bir prosese 20 çerçeve vermek bellek israfıdır.
2. **Orantılı Tahsis (`Proportional Allocation`):** Her prosese kendi sanal boyutuyla ($s_i$) orantılı sayıda çerçeve verilir:
   $$S = \sum_{i} s_i, \qquad a_i = \frac{s_i}{S} \times m$$
   - **Slayttaki Örnek:** Boş çerçeve sayısı $m = 62$ (64 çerçevenin 2'si işletim sisteminde), $P_1$'in boyutu $s_1 = 10\text{ sayfa}$ ve $P_2$'nin boyutu $s_2 = 127\text{ sayfa}$ ($S = 10 + 127 = 137$) olsun:
     $$a_1 = \frac{10}{137} \times 62 \approx 4\text{ çerçeve}, \qquad a_2 = \frac{127}{137} \times 62 \approx 57\text{ çerçeve}$$
- **Küresel (`Global`) ve Yerel (`Local`) Değiştirme:** Sayfa hatası olduğunda kurban çerçeveyi tüm proseslerin çerçeveleri arasından seçebilen (yüksek öncelikli prosesin düşük öncelikliden çerçeve alabildiği) politikaya **küresel değiştirme (`global replacement`)**, yalnız prosesin kendi çerçeveleri arasından seçmesine izin veren politikaya ise **yerel değiştirme (`local replacement`)** denir.

### 6.2 Çırpınma (Thrashing)

Bir prosesin aktif olarak kullandığı sayfaları tutmaya yetecek sayıda çerçevesi yoksa, proses sürekli sayfa hatası (`page fault`) üretir. Yürütülmekte olan bir sayfayı çıkarıp hemen bir sonraki komutta ona tekrar ihtiyaç duyar:
- **Tanım:** Bir prosesin **çalıştırmadan (yürütmeden) çok sayfa takası (`paging / swapping`) ile zaman harcaması** durumuna **Çırpınma (`Thrashing`)** denir (hoca bunu *"müflis tüccarın iş yapmak yerine eski defterleri karıştırmasına"* benzetti).

```text
   CPU
Utilization
   ^
   |                  .---.
   |              .--'     \
   |          .--'          \  <-- Thrashing (Çırpınma) Başlangıcı!
   |      .--'               |
   |  .--'                   |
   | /                       v
   +------------------------------> Degree of Multiprogramming
```

1. Çoklu programlama derecesi (`degree of multiprogramming`) başlangıçta artırıldıkça işlemci kullanımı (`CPU utilization`) yükselir.
2. Ancak belleğe çok fazla proses alındığında her prosese düşen çerçeve sayısı kritik sınırın altına iner ve prosesler sürekli sayfa hatası yaparak disk G/Ç kuyruğunda beklemeye başlar.
3. İşlemci boşta kaldıkça işletim sistemi zamanlayıcısı "işlemci boş, belleğe daha fazla proses alayım" diyerek durumu daha da kötüleştirir ve işlemci kullanımı aniden dibe çakılır; fare ve ekran donmaya başlar (**thrashing**).

### 6.3 Çalışma Kümesi Modeli (Working-Set Model, ekrandan, 01:50:00)

Çırpınmayı önlemek için bir prosesin o anki **yerelliğinde (`locality`)** gerçekten kaç çerçeveye ihtiyaç duyduğunu bilmek gerekir. Hoca, FIFO ve LRU algoritmalarının sayfa hatası gerçekleştikten sonra devreye giren **reaktif (`reactive`)** yöntemler olduğunu, **Çalışma Kümesi Modelinin (`Working-Set Model`)** ise prosesin yakın geçmişteki davranışından o anki çerçeve ihtiyacını belirleyen **proaktif (`proactive`)** bir yöntem olduğunu vurguladı.

- **$\Delta$ (`Working-set window`):** Sabit sayıda bellek referansından oluşan kayan zaman penceresidir (örneğin $10{,}000\text{ komut}$).
- **$WS(t_i)$ ve $WSS_i$ (`Working-Set Size of Process` $P_i$):** $P_i$ prosesinin son $\Delta$ referans içinde eriştiği **farklı (tekil) sayfaların kümesi** ve bu kümenin eleman sayısıdır (ekrandan, 01:50:00):
  - Örneğin slayt üzerindeki referans dizgesinde $t_1$ anındaki son $\Delta = 10$ referans içinde `{1, 2, 5, 6, 7}` sayfalarına erişilmişse **$WS(t_1) = \{1, 2, 5, 6, 7\}$** (5 çerçeve gerekir);
  - İlerleyen $t_2$ anındaki $\Delta$ penceresinde yalnız `{3, 4}` sayfalarına erişilmişse **$WS(t_2) = \{3, 4\}$** olur (artık yalnız 2 çerçeve yeterlidir, boşa çıkan 3 çerçeve başka proseslere verilebilir).
  - $\Delta$ çok küçük seçilirse tüm yerelliği kapsamaz; çok büyük seçilirse birden fazla yerelliği kapsar; $\Delta = \infty$ seçilirse programın tamamını kapsar.
- **Toplam Çerçeve Talebi ($D$) ve Çırpınma Kontrolü:**
  $$D = \sum_{i} WSS_i$$
  Eğer sistemdeki tüm proseslerin çalışma kümelerinin toplamı mevcut toplam çerçeve sayısını aşarsa (**$D > m$**), **thrashing** oluşacaktır! İşletim sistemi $D > m$ olduğunu gördüğü anda proseslerden birini askıya alıp diske çıkarır (**`suspend / swap out`**) ve çerçevelerini diğer proseslere dağıtarak çırpınmayı önler.

---

## 7. Çekirdek Bellek Yönetimi (Buddy System) ve Program Yapısının Sayfa Hatalarına Etkisi

### 7.1 Çekirdek Belleği İçin Buddy System (Arkadaş Sistemi)

İşletim sistemi çekirdeği (`kernel`) kendi veri yapıları için bellek ayırırken kullanıcı sayfalarından farklı olarak kimi zaman çok küçük ve bitişik bellek bloklarına ihtiyaç duyar. **Buddy System** algoritması, sabit boyutlu bitişik bir bellek kesimini **2'nin kuvvetleri ($2^k$)** şeklinde ikişer eşit parçaya (*two buddies*) bölerek tahsis yapar:
- Örneğin başlangıçta `256 KB` bitişik fiziksel bellek varken `21 KB` talep gelirse:
  - `256 KB` $\to$ iki adet `128 KB` $\to$ iki adet `64 KB` $\to$ iki adet `32 KB` parçaya bölünür ve `21 KB`'lık talep bir `32 KB` bloğa yerleştirilir. Serbest bırakıldığında kardeş bloklar tekrar birleştirilir (*coalescing*).

### 7.2 Program Yapısının Sayfa Hatalarına Etkisi ($128 \times 128$ Matris Örneği)

Programcının üst seviye dilde yazdığı döngü sırası, alt seviyedeki sayfa hatası sayısını dramatik biçimde değiştirir. Her sayfanın `128 kelime` (`128 words`) büyüklüğünde olduğunu ve `int data[128][128]` matrisinin bellekte **satır-öncelikli (`row-major` — her satır 1 sayfada)** saklandığını düşünelim:

- **Program 1 (Sütun-öncelikli / Kötü erişim):**

  ```c
  int data[128][128];
  for (j = 0; j < 128; j++)
      for (i = 0; i < 128; i++)
          data[i][j] = 0;
  ```

  Dış döngüde `j`, iç döngüde `i` arttığı için program sırasıyla `data[0][0]` (Sayfa 0), `data[1][0]` (Sayfa 1), `data[2][0]` (Sayfa 2)... şeklinde **her adımda farklı bir sayfaya** sıçrar! Çerçeve sayısı azsa her erişimde sayfa hatası oluşur:
  $$\text{Toplam Sayfa Hatası} = 128 \times 128 = \mathbf{16{,}384\text{ page fault}}$$

- **Program 2 (Satır-öncelikli / İyi erişim):**

  ```c
  int data[128][128];
  for (i = 0; i < 128; i++)
      for (j = 0; j < 128; j++)
          data[i][j] = 0;
  ```

  İç döngüde `j` arttığı için önce 0. satırdaki tüm elemanlar (`data[0][0..127]`, yani Sayfa 0'ın tamamı) tek bir sayfa hatasıyla sıfırlanır, ardından Sayfa 1'e geçilir:
  $$\text{Toplam Sayfa Hatası} = \mathbf{128\text{ page fault}}$$
  Yalnızca `i` ve `j` döngülerinin yerini değiştirmek sayfa hatası sayısını **128 kat** azaltmıştır!

---

## 8. Yığın Depolama (Mass Storage) Mimarisi ve Disk Zamanlama (Disk Scheduling) Algoritmaları

Dersin son bölümünde hoca, kalıcı yığın depolama birimlerine (**Bölüm 10: Mass-Storage Structure**) giriş yaptı.

### 8.1 Manyetik Sabit Disklerin Fiziksel Yapısı, Performansı ve SSD Karşılaştırması

- **Fiziksel Yapı:** Mekanik sabit diskler (HDD), bir mil (`spindle`) etrafında yüksek hızda dönen (örneğin `7200 RPM` — dakikada 7200, saniyede 120 devir) üst üste dizilmiş dairesel **plakalardan (`platters`)** oluşur:
  - CD/DVD'lerdeki tek bir spiral (yumak gibi) izden farklı olarak, sabit disk plakalarının yüzeyi eşmerkezli dairesel **izlere (`tracks`)** bölünmüştür.
  - Her iz, blok okuma/yazma birimi olan **sektörlere (`sectors`)** ayrılır.
  - Farklı plakaların aynı yarıçaptaki izlerinin üst üste oluşturduğu kümeye **silindir (`cylinder`)** denir. Hareketli kol (`arm assembly`) üzerindeki okuma/yazma kafası (`read-write head`) ileri-geri hareket ederek hedef silindire konumlanır.
  - **Dosya Silme ve Veri Kurtarma:** Diskten bir dosya silindiğinde fiziksel yüzeydeki manyeto-rezistif `0` ve `1` kayıtları gerçekte silinmez; yalnız mantıksal tablodan adres kaydı kaldırılır. Üzerine yeni veri yazılmadığı sürece veri kurtarma yazılımları dosya biçimi başlıklarını (PDF, MP3, Word imzalarını) tarayarak veriyi kurtarabilir.
- **Disk Erişim Süresi Bileşenleri:**
  1. **Arama Süresi (`Seek Time`):** Okuma/yazma kolunun hedef silindire (ize) gitmesi için geçen süredir (tipik olarak $3\text{ ms}$ – $12\text{ ms}$ arası).
  2. **Dönme Gecikmesi (`Rotational Latency`):** Plakanın dönerek hedef sektörün okuma/yazma kafasının altına gelmesi için geçen süredir (örneğin `7200 RPM` bir diskte bir tam tur $\frac{60}{7200} = 8.33\text{ ms}$, ortalama yarım tur gecikmesi ise **$4.17\text{ ms}$**'dir).
- **SSD (`Solid-State Disk`) ve Manyetik Teyp (`Magnetic Tape`):**
  - **SSD:** Hareketli mekanik parçası olmadığı için arama (`seek`) ve dönme (`rotational latency`) gecikmesi yoktur; sabit disk darboğazını (*bottleneck*) ortadan kaldırır (hoca laboratuvardaki 2008 model Core 2 Duo bilgisayarlara SSD takıldığında, mekanik sabit diskli 2016–2017 model i5 bilgisayarlardan daha hızlı açıldığını ve Boğaz Köprüsü darboğazı benzetmesini örnek verdi). Dezavantajı MB başına maliyetinin daha yüksek olması ve sınırlı yazma ömrüdür.
  - **Manyetik Teyp:** Rastgele erişimi çok yavaştır ancak kapasitesi yüksek ve maliyeti düşüktür; bankalar ve üniversiteler gibi kurumlarda günlük/haftalık veritabanı yedeklemesi için kullanılır.

### 8.2 Disk Zamanlama (Disk Scheduling) Algoritmaları

Mekanik bir sabit diskte birden fazla prosesin G/Ç isteklerini en az kafa hareketiyle (`head movement`) karşılamak için kullanılan algoritmaları, `0..199` numaralı **200 silindirli** bir disk üzerinde inceleyelim (ekrandan, 02:15:00):
- **Başlangıç kafa konumu:** **`53`**
- **İstek kuyruğu (`queue`):** **`98, 183, 37, 122, 14, 124, 65, 67`**

#### 1. FCFS (First-Come, First-Served — İlk Gelen İlk Hizmet Alır, ekrandan, 02:15:00):

İstekleri hiçbir sıralama yapmadan kuyruktaki geliş sırasıyla karşılar (hoca bunu çay bahçesinde her masaya tek tek çay götürüp mutfağa geri dönen garsona benzetti):
- **Rota:** `53 -> 98 -> 183 -> 37 -> 122 -> 14 -> 124 -> 65 -> 67`
- **Toplam Kafa Hareketi:**
  $$|98-53| + |183-98| + |37-183| + |122-37| + |14-122| + |124-14| + |65-124| + |67-65|$$
  $$= 45 + 85 + 146 + 85 + 108 + 110 + 59 + 2 = \mathbf{640\text{ silindir}}$$

#### 2. SSTF (Shortest Seek Time First — En Kısa Arama Süresi Önce):

Mevcut kafa konumuna **en yakın** olan silindir isteğine öncelik verir (CPU zamanlamadaki SJF algoritmasının karşılığıdır ve uzak silindirlerdeki istekler için **açlık / `starvation`** riski taşır):
- **Rota:** `53 -> 65 -> 67 -> 37 -> 14 -> 98 -> 122 -> 124 -> 183`
- **Toplam Kafa Hareketi:**
  $$|65-53| + |67-65| + |37-67| + |14-37| + |98-14| + |122-98| + |124-122| + |183-124|$$
  $$= 12 + 2 + 30 + 23 + 84 + 24 + 2 + 59 = \mathbf{236\text{ silindir}}$$

#### 3. SCAN (Asansör Algoritması — Elevator Algorithm):

Disk kolu bir uçtan başlayıp diğer uca kadar ilerlerken yol üzerindeki tüm isteklere hizmet verir; diskin sonuna (`0` veya `199`) ulaştığında yönünü tersine çevirip diğer uca doğru taramaya devam eder:
- **Rota (Kafa başlangıçta `0` yönüne doğru gidiyorsa):** `53 -> 37 -> 14 -> 0 -> 65 -> 67 -> 98 -> 122 -> 124 -> 183`
- **Toplam Kafa Hareketi:**
  $$(53 - 0) + (183 - 0) = 53 + 183 = \mathbf{236\text{ silindir}}$$

#### 4. C-SCAN (Circular SCAN) ve C-LOOK:

- **C-SCAN:** SCAN algoritmasında kafa uçtan dönerken o uçtaki yeni istekler hemen hizmet alıp diğer uçtakiler daha uzun beklediği için, C-SCAN **yalnızca tek yönde** hizmet verir: `53`'ten yukarı doğru `199` ucuna kadar (`53 -> 65 -> 67 -> 98 -> 122 -> 124 -> 183 -> 199`) tüm isteklere hizmet verir, ardından dönüş yolunda hiçbir isteğe bakmadan doğrudan `0` başına dönüp `0 -> 14 -> 37` şeklinde devam eder.
- **C-LOOK:** C-SCAN'in diskin fiziksel uçlarına (`199` ve `0`) kadar boşuna gitmesini önleyen versiyonudur; kafa yalnızca o yöndeki **son isteğe (`183`)** kadar gider ve oradan doğrudan diğer uçtaki **ilk isteğe (`14`)** döner (`53 -> 65 -> 67 -> 98 -> 122 -> 124 -> 183 -> 14 -> 37`).

### 8.3 Disk Yönetimi ve Önyükleme Bloğu (Boot Block / MBR)

Bilgisayar ilk açıldığında (`power-up` veya `reboot`) işlemci ROM'daki **önyükleyici (`bootstrap loader`)** programını çalıştırır. Bu program, sabit diskin bilinen ilk sektöründe yer alan **Ana Önyükleme Kaydını (`MBR — Master Boot Record`)** ana belleğe yükler. MBR içerisinde **önyükleme kodu (`boot code`)** ve diskin bölümlerini gösteren **bölüm tablosu (`partition table`)** bulunur; sistem buradan önyükleme bölümünü (`boot partition`) bularak işletim sistemi çekirdeğini başlatır.

---

## Örnek Sorular

### Soru 1: İstek Üzerine Sayfalamada (Demand Paging) Etkin Erişim Süresi (EAT) Hesabı (ekrandan, 00:56:45)

**Soru:** Ana bellek erişim süresinin **200 nanosaniye (ns)** ve ortalama sayfa hatası servis süresinin **8 milisaniye (ms)** olduğu bir sanal bellek sisteminde:
a) Her 1,000 bellek erişiminden 1'i sayfa hatasına (`page fault`) neden oluyorsa ($p = 0.001$) etkin erişim süresi (`EAT`) kaç mikrosaniyedir ve sistem yaklaşık kaç kat yavaşlar?
b) Sayfa hatalarından kaynaklanan başarım kaybının (yavaşlamanın) **%10'un altında** kalması için sayfa hatası olasılığı $p$ en fazla ne olmalıdır?

**Çözüm (derste verildi):**
- **a)** $8\text{ ms} = 8{,}000{,}000\text{ ns}$ olduğundan:
  $$\text{EAT} = (1 - p) \times 200 + p \times 8{,}000{,}000 = 200 + 7{,}999{,}800 \times p$$
  $p = 0.001$ için:
  $$\text{EAT} = 200 + 0.001 \times 7{,}999{,}800 = 8{,}199.8\text{ ns} \approx \mathbf{8.2\text{ }\mu\text{s}}$$
  Sistem $\frac{8200\text{ ns}}{200\text{ ns}} \approx \mathbf{40\text{ kat}}$ yavaşlar.
- **b)** %10'dan az yavaşlama için $\text{EAT} < 220\text{ ns}$ olmalıdır:
  $$200 + 7{,}999{,}800 \times p < 220 \implies p < \frac{20}{7{,}999{,}800} \approx \mathbf{0.0000025}$$
  Yani her **400,000 bellek erişiminde 1'den az** sayfa hatası oluşmalıdır.

### Soru 2: FIFO, Optimal ve LRU Sayfa Değiştirme Algoritmalarının Karşılaştırılması (ekrandan, 01:30:00, 01:34:15, 01:35:30)

**Soru:** Başlangıçta boş olan **3 çerçeveli (`3 frames`)** bir bellekte şu sayfa referans dizgesi çalıştırılmaktadır:
`7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2, 1, 2, 0, 1, 7, 0, 1`
**FIFO**, **Optimal (OPT)** ve **LRU** algoritmalarının her biri için toplam kaç sayfa hatası (`page fault`) oluşacağını bulunuz ve 6. referans olan `3` geldiğinde FIFO ile LRU'nun neden farklı sayfa çıkardığını açıklayınız.

**Çözüm (derste verildi):**
- **FIFO:** İlk giren sayfayı çıkarır $\implies$ toplam **15 sayfa hatası** oluşur.
- **Optimal (OPT):** Gelecekte en geç kullanılacak sayfayı çıkarır $\implies$ toplam **9 sayfa hatası** oluşur.
- **LRU:** Geçmişte en uzun süredir kullanılmayan sayfayı çıkarır $\implies$ toplam **12 sayfa hatası** oluşur.
- **6. referans (`3`) farkı:** `7, 0, 1, 2, 0` referanslarından sonra bellekte `[2, 0, 1]` sayfaları vardır. `3` geldiğinde FIFO, belleğe `1` ve `2`'den daha önce girmiş olan **`0` sayfasını** çıkarır (ve hemen bir sonraki referans `0` olduğu için tekrar hata yapar); LRU ise `0` sayfası bir önceki adımda kullanıldığı için en eski erişilmiş olan **`1` sayfasını** çıkarır ve `0`'ı bellekte tutar.

### Soru 3: Disk Zamanlama Algoritmaları (FCFS, SSTF, SCAN) Kafa Hareketi Hesabı (ekrandan, 02:15:00)

**Soru:** `0..199` arası silindirlere sahip bir diskte okuma/yazma kafası başlangıçta **`53`** numaralı silindirdedir. Kuyruktaki istekler sırasıyla **`98, 183, 37, 122, 14, 124, 65, 67`** olduğuna göre:
a) **FCFS**,
b) **SSTF**,
c) **SCAN** (başlangıç yönü `0`'a doğru)
algoritmaları için kafanın izlediği rotayı ve toplam silindir hareket miktarını hesaplayınız.

**Çözüm (derste verildi):**
- **a) FCFS:** Rota: `53 -> 98 -> 183 -> 37 -> 122 -> 14 -> 124 -> 65 -> 67`.
  Toplam hareket: $45 + 85 + 146 + 85 + 108 + 110 + 59 + 2 = \mathbf{640\text{ silindir}}$.
- **b) SSTF:** Rota: `53 -> 65 -> 67 -> 37 -> 14 -> 98 -> 122 -> 124 -> 183`.
  Toplam hareket: $12 + 2 + 30 + 23 + 84 + 24 + 2 + 59 = \mathbf{236\text{ silindir}}$.
- **c) SCAN (`0` yönüne):** Rota: `53 -> 37 -> 14 -> 0 -> 65 -> 67 -> 98 -> 122 -> 124 -> 183`.
  Toplam hareket: $(53 - 0) + (183 - 0) = \mathbf{236\text{ silindir}}$.

---

## Dersin Toparlaması

Bu derste ilk olarak sayfalama mimarisinde koruma bitleri (`valid-invalid bit`), salt okunur (**reentrant**) **paylaşımlı sayfalar (`shared pages`)** ve büyük adres uzaylarında sayfa tablolarını yönetmek için kullanılan **Hiyerarşik Sayfalama (`Hierarchical Paging`)**, **Çırpılı Sayfa Tabloları (`Hashed Page Tables`)** ve **Ters Çevrilmiş Sayfa Tabloları (`Inverted Page Tables`)** ile IA-32, x86-64 ve ARM mimarileri incelenmiştir. Ardından **Sanal Bellek (`Virtual Memory`)** bölümüne geçilerek **İstek Üzerine Sayfalama (`Demand Paging`)**, sayfa hatası (`page fault`) adımları, etkin erişim süresi (`EAT`), **Yazarken Kopyalama (`Copy-on-Write`)** ve değiştirilme biti (`dirty bit`) ele alınmıştır. Boş çerçeve kalmadığında çalıştırılan **FIFO** (ve **Belady Anomalisi**), **Optimal (`OPT`)**, **LRU** ve **İkinci Şans (`Second-Chance`)** sayfa değiştirme algoritmaları sayısal örneklerle çözülmüş; çerçeve tahsis politikaları, **Çırpınma (`Thrashing`)**, **Çalışma Kümesi Modeli (`Working-Set Model`)**, **Buddy System** ve matris erişim sırasının sayfa hatalarına etkisi analiz edilmiştir. Dersin son bölümünde ise sabit disklerin fiziksel mimarisi, SSD karşılaştırması ve **FCFS, SSTF, SCAN, C-SCAN, C-LOOK** disk zamanlama algoritmaları işlenmiştir. Dönemin son dersinde yığın depolamanın kalan kısımları (RAID vb.) ve dosya sistemi (File-System Interface & Implementation) konuları ele alınacaktır.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
