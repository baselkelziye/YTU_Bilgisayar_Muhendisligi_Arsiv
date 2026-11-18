# Ders 12 Genişletilmiş Notu: Ana Bellek Yönetimi (Main Memory Management): Adres Bağlama, MMU, Takas (Swapping), Bitişik Tahsis, Parçalanma, Kesimleme (Segmentation), Sayfalama (Paging) ve TLB

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Ana Bellek (Main Memory) Mimarisi, Bellek Hiyerarşisi ve Adresleme Temelleri
- 2. Donanımsal Bellek Koruması (Base ve Limit Yazmaçları) ve Adres Bağlama (Address Binding)
- 3. Mantıksal ve Fiziksel Adres Uzayı, MMU, Dinamik Yükleme ve Dinamik Bağlama
- 4. Takas (Swapping) Mekanizması, Bağlam Değişimi Maliyeti ve Mobil Sistemler
- 5. Bitişik Bellek Tahsisi (Contiguous Allocation), Boşluk Seçim Algoritmaları ve Parçalanma (Fragmentation)
- 6. Kesimleme (Segmentation) Mimarisi ve Kesim Tablosu Donanımı
- 7. Sayfalama (Paging) Mimarisi, Adres Dönüşümü ve İç Parçalanma Analizi
- 8. Sayfa Tablosu Gerçeklemesi, TLB (Translation Look-aside Buffer) ve Etkin Erişim Süresi (EAT)
- Örnek Sorular
- Dersin Toparlaması

## 1. Ana Bellek (Main Memory) Mimarisi, Bellek Hiyerarşisi ve Adresleme Temelleri

### 1.1 Bellek Hiyerarşisi ve Ana Belleğin Rolü

Bilgisayar sisteminde kaynakları en verimli şekilde kullanırken işlemci zamanlaması ve senkronizasyondan sonra gelen en kritik bileşen **ana bellek (main memory / RAM — Random Access Memory)** yönetimidir.

Ana bellek (RAM), elektrik enerjisi var olduğu sürece verileri koruyan **uçucu (volatile)** bir bellektir; adres yolu (*address bus*), veri yolu (*data bus*) ve kontrol yolu (*control bus*) üzerinden işlemciyle haberleşir. Kapasite açısından kalıcı depolama birimleriyle (sabit diskler / SSD'ler) karşılaştırıldığında RAM çok daha küçüktür (kişisel bilgisayarlarda geçmişte 2–8 GB iken günümüzde 32–64 GB, sunucularda daha yüksek; ancak terabaytlarca disk alanına kıyasla oldukça sınırlıdır).

Sistemdeki bellek hiyerarşisi işlemciye yakınlık ve hız sırasına göre şöyle dizilim gösterir:

```text
+-----------------------------------+       +-------------------------+
|                CPU                |       |                         |
|  +-----------+    +------------+  | <---> |     Ana Bellek (RAM)    |
|  | Registers |    | L1 Cache   |  |       |  (OS Kernel + Prosesler)|
|  +-----------+    +------------+  |       +-------------------------+
+-----------------------------------+                    ^
          ^                                              |
          |         +------------+                       v
          +-------> | L2 / L3    |          +-------------------------+
                    | Cache      |          |   Kalıcı Disk (HDD/SSD) |
                    +------------+          | (Programlar / Sanal B.) |
                                            +-------------------------+
```

Disk üzerinde duran çalıştırılabilir dosyalar henüz birer **programdır**. Çalıştırıldıklarında (`run` edildiklerinde) **proses** haline gelerek RAM'e yüklenirler. Ancak burada iki temel darboğaz ortaya çıkar:
1. Disk üzerinde 8–10 GB boyutunda olan büyük bir program, proses haline geldiğinde dinamik veri yapılarıyla birlikte 20 GB bellek gerektirebilir ve tek başına dahi RAM'e sığmayabilir.
2. Tek bir proses 60 MB veya 500 MB gibi küçük bir boyuta sahip olsa bile (örneğin bir önceki derste alınan tek bir `core dump` dosyası bile yaklaşık 50–60 MB yer tutuyordu), bilgisayarda aynı anda hem işletim sistemi çekirdeği (`OS kernel`) hem de yüzlerce/binlerce sistem ve kullanıcı prosesi çalışır. 100 adet 60 MB'lık proses bile 6 GB yer kaplar ve 8 GB'lık bir RAM'i doldurur.

Bu nedenle bir prosesin **tamamı** her zaman RAM'de tutulmaz; yalnızca o an çalışması için gerekli olan bölümleri RAM'de tutulurken, gerekmeyen kısımları disk üzerindeki **sanal bellek (virtual memory)** alanında saklanır.

### 1.2 İkilik Sistemde Bellek Adresleme Hesabı

Bellek, her biri **1 bayt (8 bit)** büyüklüğünde olan ardışık hücrelerden oluşur. $0$. bayttan sonuncu bayta kadar her hücreye erişebilmek için her birine ikilik tabanda benzersiz bir **adres** verilmesi gerekir.

Örneğin **64 GB** büyüklüğünde bir RAM'i adreslemek için kaç bit gerektiğini hesaplayalım:
- $1\text{ KB} = 2^{10}\text{ bayt}$, $1\text{ MB} = 2^{20}\text{ bayt}$, $1\text{ GB} = 2^{30}\text{ bayt}$.
- $64\text{ GB} = 2^6 \times 2^{30}\text{ bayt} = 2^{36}\text{ bayt}$.
- Dolayısıyla $0$. bayttan ($36$ adet `0`: `000...0`) sonuncu bayta ($36$ adet `1`: `111...1`) kadar tüm hücreleri adreslemek için **36 bitlik** bir adres genişliği gerekir.
- Bilgisayar mimarisinde veriler 8 bitin (1 baytın) katları şeklinde saklandığından, 36 bitlik bir adresi bellekte tutmak için bir üst 8'in katı olan **40 bit = 5 bayt** yer ayrılır.

### 1.3 Doğrudan Adresleme ve Bellek Bankası (Memory Bank) Mimarisi

İşlemcinin doğrudan erişebildiği yegâne depolama birimleri **kendi iç yazmaçları (registers)** ve **ana bellektir (main memory)** (ekrandan, 00:20:00):
- **Yazmaç erişimi:** Genellikle **1 CPU saat vuruşu (1 clock cycle)** veya daha kısa sürede gerçekleşir (örneğin `MOV AX, BX` komutu tek saat vuruşunda tamamlanır).
- **Ana bellek erişimi:** `MOV AX, [1234h]` gibi bellekteki bir adresten veri çeken bir komutta önce komutun kendisi bellekten getirilir ve çözülür (`decode`), ardından `1234h` adresindeki işlenen (operand) için belleğe ikinci kez gidilir. Bu işlem birden fazla saat vuruşu sürer; işlemcinin verinin bellekten gelmesini boşta beklemesine **duraklama (`stall`)** denir. Bunu azaltmak için CPU ile RAM arasına hızlı **önbellek (`cache`)** yerleştirilir.

Hoca burada her işlemci mimarisinde bellek erişiminin `8086` assembly dilindeki gibi düz bir cetvel üzerinde doğrudan yapılamadığını vurguladı: Örneğin **PIC16F876** mikrodenetleyicisinde bellek düz bir dizi yerine **4 ayrı bellek bankasına (`Bank 0`, `Bank 1`, `Bank 2`, `Bank 3`)** bölünmüştür. `Bank 3` içindeki `5678` adresinden bir veriyi alıp `Bank 1` içindeki `1234` adresine kopyalamak istediğinizde doğrudan adresi yazamazsınız; önce durum yazmacındaki banka seçim bitlerini `11` yaparak aktif bankayı `Bank 3`'e geçirmeniz, o bankanın başlangıcına göre bağıl adresten veriyi `R0` (`W`) yazmacına almanız, ardından banka bitlerini tekrar değiştirip `Bank 1`'e geçerek hedef adrese yazmanız gerekir. C gibi üst seviye dillerde derleyici bu arka plan adres ve banka dönüşümlerini programcıdan soyutlar.

---

## 2. Donanımsal Bellek Koruması (Base ve Limit Yazmaçları) ve Adres Bağlama (Address Binding)

### 2.1 Donanımsal Adres Koruması (Hardware Address Protection)

Bellekte işletim sistemi çekirdeği ile birlikte birden fazla kullanıcı prosesi ($P_0, P_1, \dots$) aynı anda bulunur. Sistemin doğru çalışabilmesi (`correct operation`) için:
1. Kullanıcı proseslerinin işletim sistemi bellek alanına erişmesi,
2. Bir kullanıcı prosesinin ($P_1$) izinsiz olarak başka bir kullanıcı prosesinin ($P_0$) bellek alanına (kod veya veri bölgesine) müdahale etmesi **kesinlikle engellenmelidir**.

Bu korumayı işletim sistemi yazılımıyla her komutta kontrol etmek sistemi yavaşlatacağından, koruma **donanımsal olarak** işlemci içindeki iki yazmaçla sağlanır (ekrandan, 00:26:30):
- **Taban Yazmacı (`Base Register`):** Prosesin bellekte başladığı en küçük yasal fiziksel adresi tutar.
- **Sınır Yazmacı (`Limit Register`):** Prosesin bellek alanının büyüklüğünü (uzunluğunu / *range*) tutar.

Her prosesin kendine ait `base` ve `limit` değerleri o prosesin **Proses Kontrol Bloğunda (PCB)** (veya işletim sisteminin proses tablosunda `PID` ile ilişkili olarak) saklanır. Bağlam değişimi (context switch) yapıldığında, işlemciye geçen aktif prosesin `base` ve `limit` değerleri PCB'den okunarak CPU içindeki donanım yazmaçlarına yüklenir.

```text
                       +------+          +--------------+
                       | base |          | base + limit |
                       +------+          +--------------+
                          |                     |
+-----+   address      +--+---+   yes    +------+-----+   yes   +--------+
| CPU | -------------> |  >=  | -------> |     <      | ------> | memory |
+-----+                +------+          +------------+         +--------+
                          | no                  | no
                          v                     v
                 trap to operating system
                monitor — addressing error
```

CPU tarafından üretilen her bellek adresi (ister `Program Counter` tarafından istenen bir komut adresi, ister komut içindeki bir veri/operand adresi olsun) belleğe gitmeden önce şu iki koşuldan geçer (ekrandan, 00:26:30):
$$\text{base} \le \text{address} < \text{base} + \text{limit}$$
Her iki karşılaştırma da **evet (`yes`)** ise belleğe erişilir; herhangi biri **hayır (`no`)** ise donanım işletim sistemine bir **tuzak/kesme (`trap to operating system monitor — addressing error`)** üretir ve ilgili proses sonlandırılır.

#### C ve Java'da Dizi Sınırı Aşımı ve Segmentation Fault Farkı

Hoca burada öğrencilerin sıkça karşılaştığı bir durumu açıkladı:
- **Java'da:** 10 elemanlı bir dizi tanımlayıp (`indis 0..9`) 10. indise erişmeye çalıştığınızda Java Sanal Makinesi (JVM) çalışma zamanında doğrudan `ArrayIndexOutOfBoundsException` hatası fırlatır.
- **C dilinde:** Derleyici dizi sınırını kontrol etmez. 10 elemanlı bir dizinin 11. veya 12. indisine eriştiğinizde, eğer o bellek gözü hâlâ sizin prosesinize tahsis edilmiş olan yığın (`stack`) bölgesi sınırları (`base` ile `base + limit` arası) içindeyse donanım tuzağı oluşmaz ve programınız kendi bellek alanınız içinde kaldığı için çalışmaya devam eder ("evdeki bilgisayarda çalışıyordu, laboratuvarda çalışmadı" durumu). Ancak indisi çok büyütüp (örneğin milyonuncu indise gidip) yukarıdan aşağıya büyüyen `stack` ile aşağıdan yukarıya büyüyen `heap` sınırlarını veya prosesin `limit` adresini aşarak başka bir prosesin alanına taşarsanız, donanım **`Segmentation fault`** üretir ve işletim sistemi programı anında kapatır.

### 2.2 Adres Bağlama (Address Binding) ve Çok Adımlı Program İşleme

Disk üzerinde çalıştırılmayı bekleyen programlar bir **giriş kuyruğu (`input queue`)** oluşturur. Bir program henüz belleğe yüklenmeden önce belleğin hangi fiziksel adresine yerleşeceğini bilemeyeceği için, her program kendi içinde `0`. adresten başlayacak şekilde tasarlanır.
- **Sembolik Adresler (Symbolic Addresses):** Kaynak kodda (`source program`) kullandığımız değişken ve fonksiyon adlarıdır (`int x;`, `main()`).
- **Yeri Değiştirilebilir Adresler (Relocatable Addresses):** Derleyici (`compiler`) kaynak kodu derlediğinde sembolik adresleri *"bu modülün başlangıcından itibaren 14. bayt"* gibi bağıl/yer değiştirilebilir adreslere dönüştürür.
- **Mutlak Adresler (Absolute / Physical Addresses):** Bağlayıcı (`linkage editor`) veya yükleyici (`loader`), yeri değiştirilebilir adresleri gerçek fiziksel bellek adreslerine (örneğin `74014` adresi) bağlar.

Bir kullanıcı programının kaynak koddan bellekte çalışan prosese dönüşme adımları şöyledir (ekrandan, 00:34:30):

```text
               ( source program )
                       |
                       v
            +----------------------+
            | compiler or assembler|  } compile time (derleme zamanı)
            +----------------------+
                       |
                       v
               ( object module )
                       |
  ( other object ) --->+
  (   modules    )     v
            +----------------------+
            |    linkage editor    |
            +----------------------+
                       |
                       v
                ( load module )       } load time (yükleme zamanı)
                       |
  ( system  ) -------->+
  ( library )          v
            +----------------------+
            |        loader        |
            +----------------------+
                       |
  ( dynamically  ) --->+              } execution time / run time
  ( loaded sys.  )     v              } (yürütme / çalışma zamanı - dynamic linking)
  (   library    ) +-----------------------+
                   | in-memory binary      |
                   | memory image          |
                   +-----------------------+
```

Komutların ve verilerin bellek adreslerine bağlanması (**address binding**) üç farklı aşamada gerçekleştirilebilir:

1. **Derleme Zamanı (`Compile time`):** Eğer prosesin bellekte hangi fiziksel adreste duracağı önceden (*a priori*) biliniyorsa, derleme sırasında doğrudan **mutlak kod (`absolute code`)** üretilir. Başlangıç adresi ileride değişirse kodun **yeniden derlenmesi (`recompilation`)** gerekir.
2. **Yükleme Zamanı (`Load time`):** Prosesin bellekte nereye yerleşeceği derleme zamanında bilinmiyorsa, derleyici **yeri değiştirilebilir kod (`relocatable code`)** üretir. Son bağlama işlemi program çift tıklanıp belleğe yüklenirken (`load time`) yükleyici tarafından yapılır.
3. **Yürütme Zamanı (`Execution time`):** Eğer bir proses çalışması sırasında bellekte bir segmentten/bölgeden başka bir bölgeye taşınabiliyorsa veya `printf`, matematik kütüphanesi (`exp` vb.) gibi kod parçaları yalnızca ihtiyaç duyulduğu anda belleğe getiriliyorsa, adres bağlama işlemi **yürütme zamanına (`execution time`)** ertelenir. Bunun için MMU gibi özel donanım desteği (`hardware support for address maps`) şarttır.

---

## 3. Mantıksal ve Fiziksel Adres Uzayı, MMU, Dinamik Yükleme ve Dinamik Bağlama

### 3.1 Mantıksal Adres (Logical Address) ve Fiziksel Adres (Physical Address)

Bellek yönetiminin temelini şu iki adres kavramı oluşturur:
- **Mantıksal Adres (`Logical Address` / `Virtual Address`):** İşlemci (CPU) tarafından üretilen adrestir ($0, 1, 2, \dots$ şeklinde programın kendi iç satır/bayt sırası). Bir program tarafından üretilen tüm mantıksal adreslerin kümesine **Mantıksal Adres Uzayı (`Logical Address Space`)** denir.
- **Fiziksel Adres (`Physical Address`):** Ana bellek biriminin (`memory unit` — `MAR` yazmacının) gördüğü gerçek RAM adresidir. Mantıksal adreslere karşılık gelen tüm fiziksel adreslerin kümesine **Fiziksel Adres Uzayı (`Physical Address Space`)** denir.

**Adres Bağlama Zamanlarına Göre Karşılaştırma:**
- **Compile time** ve **Load time** bağlama yöntemlerinde mantıksal adres ile fiziksel adres birbirinin **aynısıdır**.
- **Execution time (yürütme zamanı)** bağlama yönteminde ise mantıksal adres ile fiziksel adres birbirinden **farklıdır**; bu durumda mantıksal adrese **sanal adres (`virtual address`)** de denir.

> **Hocanın vurgusu:** Hoca burada İngilizcedeki iki yakın kelimenin karıştırılmaması gerektiğini vurguladı: Zamanla (time) ilgili süreklilik kavramı için **`continuous`**, mekanla / bellek alanıyla (space) ilgili bitişiklik ve kesintisizlik kavramı için ise **`contiguous`** terimi kullanılır.

### 3.2 Bellek Yönetim Birimi (Memory-Management Unit — MMU)

Çalışma zamanında sanal (mantıksal) adresleri fiziksel adreslere dönüştüren donanım aygıtına **Bellek Yönetim Birimi (MMU — Memory-Management Unit)** denir (ekrandan, 00:41:45).

En temel MMU şemasında, daha önce gördüğümüz `base register` artık **yer değiştirme yazmacı (`relocation register`)** adını alır (örneğin `8086` işlemcisinde bu amaçla 4 adet segment/relocation yazmacı bulunur). CPU'nun ürettiği her mantıksal adrese belleğe gönderilmeden önce `relocation register` içindeki sabit değer eklenir:

```text
                        +---------------------+
                        | relocation register |
                        |     [  14000  ]     |
                        +---------------------+
                                   |
+-------+   logical address       v        physical address   +--------+
|  CPU  | --------------------> ( + ) ----------------------> | memory |
+-------+         346             ^             14346         +--------+
                                  |
                                 MMU
```

Örneğin prosesin `relocation register` değeri `14000` ise ve kullanıcı programı mantıksal olarak `346`. adrese erişmek istiyorsa, MMU donanımı `14000 + 346 = 14346` toplamasını yaparak belleğin `14346` numaralı fiziksel gözüne erişir (ekrandan, 00:41:45). Kullanıcı programı hiçbir zaman gerçek fiziksel adreslerle (`14346`) uğraşmaz; yalnızca kendi `0..max` aralığındaki mantıksal adreslerini (`346`) görür.

### 3.3 Dinamik Yükleme (Dynamic Loading) ve Dinamik Bağlama (Dynamic Linking)

- **Dinamik Yükleme (`Dynamic Loading`):** Bir alt yordam (routine / fonksiyon) çağrılana kadar belleğe yüklenmez; tüm rutinler disk üzerinde yeri değiştirilebilir yükleme formatında (`relocatable load format`) tutulur. Özellikle hata işleme rutinleri gibi büyük miktarda kod içeren ama nadiren çalıştırılan (`infrequently occurring cases`) bölümlerin boşu boşuna belleği işgal etmesini önler ve bellek kullanımını (`memory-space utilization`) iyileştirir. İşletim sisteminden özel bir destek gerektirmez; program tasarımıyla yapılır.
- **Dinamik Bağlama (`Dynamic Linking`) ve Paylaşımlı Kütüphaneler (`Shared Libraries`):**
  - **Statik Bağlamada (`Static Linking`):** Sistem kütüphaneleri (`printf`, matematik kütüphaneleri vb.) yükleyici (`loader`) tarafından her programın ikili bellek görüntüsünün (`binary program image`) içine fiziksel olarak kopyalanır ve birleştirilir.
  - **Dinamik Bağlamada (`Dynamic Linking`):** Bağlama işlemi yürütme zamanına (`execution time`) kadar ertelenir. Kütüphane rutininin çağrıldığı yere bellekteki kütüphaneyi nasıl bulacağını veya yüklü değilse nasıl yükleyeceğini gösteren küçük bir kod parçası, yani **koçan / yer tutucu (`stub`)** yerleştirilir. Çalışma sırasında sıra `stub` noktasına geldiğinde, `stub` ilgili rutinin bellekte olup olmadığını kontrol eder; bellekte yoksa yükler ve kendisini rutinin adresiyle değiştirerek (`replace`) rutini çalıştırır.
  - Windows'taki **`.dll` (Dynamic Link Library)** ve Linux'taki paylaşımlı kütüphaneler (`.so`) bu mantıkla çalışır: Aynı kütüphane bellekte yalnızca tek bir kopya olarak durur ve birden fazla proses tarafından ortaklaşa kullanılır (`shared libraries`).

---

## 4. Takas (Swapping) Mekanizması, Bağlam Değişimi Maliyeti ve Mobil Sistemler

### 4.1 Swapping (Takas) ve Roll Out / Roll In

Bir prosesin çalıştırılabilmesi için bellekte olması gerekir; ancak sistemdeki tüm aktif proseslerin toplam fiziksel bellek talebi mevcut RAM kapasitesini aştığında (örneğin 8 GB RAM'de 50 proses varken 51. proses geldiğinde veya mevcut bir proses dinamik kütüphane bağlayıp büyüdüğünde), bellekte yer açmak için bir proses geçici olarak ana bellekten çıkarılıp diske (**backing store**) yazılır ve daha sonra çalışmasına devam etmek üzere tekrar belleğe alınır. Bu işleme **takas (`swapping`)** denir (ekrandan, 01:00:00).

- **Backing Store (Yedek Depolama):** Tüm kullanıcıların bellek görüntülerini (`memory images`) barındırabilecek kadar büyük ve doğrudan erişim sağlayan hızlı disk bölümüdür.
- **`Swap out`:** Prosesin ana bellekten diske (backing store) çıkarılmasıdır (çoklu programlama derecesini / *degree of multiprogramming* 1 azaltır).
- **`Swap in`:** Prosesin diskten tekrar ana belleğe yüklenmesidir.
- **`Roll out, roll in`:** Öncelik tabanlı (*priority-based*) zamanlama algoritmalarında kullanılan swapping çeşididir; yüksek öncelikli bir proses geldiğinde düşük öncelikli proses bellekten diske çıkarılır (**roll out**), yüksek öncelikli proses işi bittiğinde düşük öncelikli proses geri yüklenir (**roll in**).

### 4.2 Takas Süresinin Bağlam Değişimine Etkisi (Sayısal Örnek)

Klasik swapping mekanizmasında prosesin bir kısmı değil, **tamamı** diske yazılıp okunur. Mekanik sabit diskler dakikada 7200 devir (`7200 RPM`), yani saniyede yalnızca $\frac{7200}{60} = 120$ dönüş yapabildiğinden, GHz hızındaki işlemci ve MHz hızındaki RAM'e kıyasla çok yavaştır.

Slayttaki sayısal örneği adım adım inceleyelim (ekrandan, 01:06:15):
- **Verilenler:**
  - Proses büyüklüğü: $100\text{ MB}$
  - Sabit disk (backing store) aktarım hızı (`transfer rate`): $50\text{ MB/sn}$
- **Hesaplama:**
  1. $100\text{ MB}$'lık prosesin diske çıkarılma süresi (**swap out time**):
     $$t_{\text{swap\_out}} = \frac{100\text{ MB}}{50\text{ MB/sn}} = 2\text{ saniye} = 2000\text{ ms}$$
  2. Aynı büyüklükte ($100\text{ MB}$) hedef prosesin diskten belleğe alınma süresi (**swap in time**):
     $$t_{\text{swap\_in}} = \frac{100\text{ MB}}{50\text{ MB/sn}} = 2\text{ saniye} = 2000\text{ ms}$$
  3. **Toplam bağlam değişimi takas bileşeni süresi:**
     $$t_{\text{toplam}} = 2000\text{ ms} + 2000\text{ ms} = 4000\text{ ms} \quad (\text{4 saniye})$$

Mikrosaniyeler mertebesindeki normal bağlam değişimi (context switch) süresinin yanında 4 saniyelik takas süresi devasa bir gecikmedir. Bu süreyi azaltmak için prosesin kendisine ayrılan 100 MB'ın gerçekte ne kadarını (örneğin yalnız 50 MB'ını) kullandığının bilinmesi ve yalnız kullanılan kısmın takas edilmesi gerekir; bunun için proses `request_memory()` ve `release_memory()` sistem çağrılarıyla işletim sistemini bilgilendirebilir.

### 4.3 Swapping Kısıtları, Bekleyen G/Ç (Pending I/O) ve Çift Tamponlama

- **Aynı fiziksel adrese geri dönme sorunu:** Dışarı atılan (`swap out`) bir prosesin tekrar belleğe alınırken (`swap in`) eski fiziksel adresine mi yerleşmek zorunda olduğu **adres bağlama yöntemine** bağlıdır: Bağlama derleme veya yükleme zamanında yapıldıysa aynı adrese dönmek zorundadır; yürütme zamanında (`execution time` / `relocation register` ile) yapılıyorsa farklı bir boş bellek bölgesine alınıp yalnız `relocation register` değerinin güncellenmesi yeterlidir (ekrandan, 01:00:00).
- **Bekleyen G/Ç (`Pending I/O`) Problemi:** Bir $P_1$ prosesi G/Ç isteği (örneğin diskten veya ağdan veri okuma) başlatıp `waiting` durumuna geçtiğinde, G/Ç aygıtı veriyi $P_1$'in bellekteki adresine yazmak üzere hazırlanır. Eğer bu sırada $P_1$ bellekten diske atılır (`swap out`) ve yerine $P_2$ prosesi alınırsa, tamamlanan G/Ç işlemi veriyi artık $P_2$ prosesine ait olan bellek adresine yazar! Bu sorunu çözmenin iki yolu vardır:
  1. Bekleyen G/Ç işlemi olan bir prosesi asla `swap out` yapmamak,
  2. G/Ç işlemlerini doğrudan kullanıcı belleğine değil, her zaman işletim sistemi çekirdek tamponlarına (**kernel buffers**) yapmak ve proses tekrar `swap in` olduğunda çekirdek tamponundan kullanıcı belleğine aktarmak (**çift tamponlama / `double buffering`** — ancak bu da iki kez kopyalama maliyeti doğurur).
- **Modern İşletim Sistemlerinde Swapping (ekrandan, 01:00:00):** Bu yüksek maliyetler nedeniyle standart swapping günümüz işletim sistemlerinde kullanılmaz; UNIX, Linux ve Windows'ta değiştirilmiş (*modified*) bir versiyonu bulunur:
  - Swapping normalde **devre dışıdır (`disabled`)**.
  - Tahsis edilen bellek miktarı belirli bir **eşik değerini (`threshold`)** aştığında başlatılır.
  - Bellek talebi tekrar eşik değerinin altına düştüğünde yeniden devre dışı bırakılır.
- **Mobil Sistemlerde (iOS ve Android) Swapping:** Mobil cihazlar sabit disk yerine **flash bellek** kullanır. Flash belleğin kapasitesi küçüktür, yazma döngüsü ömrü sınırlıdır (örneğin 10.000–100.000 yazmadan sonra hücreler bozulur) ve RAM ile flash bellek arasındaki veri akış hızı düşüktür. Bu nedenle mobil işletim sistemleri **swapping desteklemez**:
  - **iOS:** Boş bellek belirli bir eşiğin altına indiğinde uygulamalardan ayrılmış belleği **gönüllü olarak bırakmasını (`voluntarily relinquish`)** ister. Salt okunur veriler (örneğin kod) bellekten silinir ve gerekirse flash bellekten yeniden yüklenir; değiştirilmiş veriler (örneğin yığın) hiç silinmez. Belleği boşaltmayan uygulamalar işletim sistemi tarafından kapatılır.
  - **Android:** Boş bellek azaldığında arka plandaki prosesleri sonlandırabilir (`terminate`); ancak uygulamayı yeniden hızlıca başlatabilmek için sonlandırmadan önce **uygulama durumunu (`application state`)** flash belleğe kaydeder.

---

## 5. Bitişik Bellek Tahsisi (Contiguous Allocation), Boşluk Seçim Algoritmaları ve Parçalanma (Fragmentation)

### 5.1 Bitişik Bellek Tahsisi (Contiguous Allocation) ve Çoklu Bölüm Tahsisi

Ana bellek hem işletim sistemini hem de kullanıcı proseslerini barındırmak zorundadır. Bellek genellikle iki bölüme ayrılır:
1. **Düşük bellek adresleri (`Low memory`):** Kesme vektörünü (`interrupt vector`) ve yerleşik işletim sistemi çekirdeğini barındırır.
2. **Yüksek bellek adresleri (`High memory`):** Kullanıcı proseslerini barındırır.

**Bitişik Tahsiste (`Contiguous Allocation`)** her proses, bellekte başından sonuna kadar kesintisiz, **tek bir bitişik (`contiguous`)** bellek bloğuna yerleştirilir. Donanım desteği olarak `relocation register` (en küçük fiziksel adresi tutar) ve `limit register` (mantıksal adreslerin aralığını tutar) birlikte çalışır (ekrandan, 01:15:00):

```text
                      +----------------+      +---------------------+
                      | limit register |      | relocation register |
                      +----------------+      +---------------------+
                              |                          |
+-----+  logical address   +--+---+   yes     +---+      v    physical address  +--------+
| CPU | -----------------> |  <   | --------> | + | <----+--------------------> | memory |
+-----+                    +------+           +---+                             +--------+
                              | no
                              v
                    trap: addressing error
```

Burada daha önceki iki aşamalı kontrol tek bir karşılaştırmaya inmiştir: Mantıksal adres `limit register` değerinden küçükse (`<`), üzerine `relocation register` eklenerek doğrudan fiziksel adres üretilir.

#### Çoklu Bölüm Tahsisi (Multiple-Partition Allocation) ve Boşluklar (Holes)

Prosesler belleğe girip çıktıkça bellek farklı boyutlarda değişken bölümlere (**variable partitions**) ayrılır (ekrandan, 01:20:00):

```text
Başlangıç:          Process 8 çıkar:    Process 9 gelir:    Process 10 gelir:
+------------+      +------------+      +------------+      +------------+
|     OS     |      |     OS     |      |     OS     |      |     OS     |
+------------+      +------------+      +------------+      +------------+
| process 5  |      | process 5  |      | process 5  |      | process 5  |
+------------+      +------------+      +------------+      +------------+
|            |      |            |      | process 9  |      | process 9  |
| process 8  | ===> |    HOLE    | ===> +------------+ ===> +------------+
|            |      |  (Boşluk)  |      |    HOLE    |      | process 10 |
+------------+      +------------+      |  (Boşluk)  |      +------------+
| process 2  |      | process 2  |      +------------+      |    HOLE    |
+------------+      +------------+      | process 2  |      +------------+
                                        +------------+      | process 2  |
                                                            +------------+
```

- **Hole (Boşluk):** Belleğin çeşitli yerlerine dağılmış kullanılabilir boş bellek bloklarıdır. Bir proses sonlandığında bölümü serbest kalır; eğer serbest kalan bölümün bitişiğinde başka boş bölümler varsa bunlar birleştirilerek tek bir büyük boşluk yapılır.
- İşletim sistemi iki listeyi sürekli güncel tutar: **a) Tahsis edilmiş bölümler (`allocated partitions`)**, **b) Boş bölümler (`free partitions / holes`)**.

### 5.2 Dinamik Depolama Tahsis Problemi: First-Fit, Best-Fit ve Worst-Fit

Serbest boşluklar (holes) listesinden $n$ boyutundaki yeni bir proses talebini karşılamak için hangi boşluğun seçileceğine şu üç algoritmadan biriyle karar verilir:

1. **First-Fit (İlk Uyan):** Boşluk listesini baştan tarar ve prosesin sığabileceği kadar büyük **ilk boşluğu (`first hole that is big enough`)** tahsis eder. Tüm listeyi taramak zorunda olmadığı için hızlıdır.
2. **Best-Fit (En İyi Uyan):** Prosesin sığabileceği **en küçük boşluğu (`smallest hole that is big enough`)** tahsis eder. Boşluklar boyuta göre sıralı değilse tüm listenin taranması gerekir; işlem sonunda geriye olabilecek **en küçük artık boşluğu (`smallest leftover hole`)** bırakır.
3. **Worst-Fit (En Kötü Uyan):** Listedeki **en büyük boşluğu (`largest hole`)** tahsis eder (hoca bunu otoparkta sıkışık yer yerine en geniş boş alana park etmeye benzetti). Yine tüm listenin taranması gerekir; işlem sonunda geriye **en büyük artık boşluğu (`largest leftover hole`)** bırakır (bu kalan büyük boşluğa ileride başka bir prosesin sığabileceği düşünülür).

> **Hocanın vurgusu:** Yapılan istatistiksel ve deneysel simülasyon çalışmalarında, hem **hız (speed)** hem de **bellek kullanımı (storage utilization)** açısından **`First-fit`** ve **`Best-fit`** algoritmalarının **`Worst-fit`** algoritmasından daha başarılı olduğu gösterilmiştir (`First-fit` hız açısından genellikle daha avantajlıdır).

### 5.3 Parçalanma (Fragmentation): Dış Parçalanma, İç Parçalanma ve Sıkıştırma (Compaction)

Bellek tahsis yöntemlerinde iki tür bellek israfı (**parçalanma / `fragmentation`**) görülür:

- **Dış Parçalanma (`External Fragmentation`):** Proseslerin dışında, prosesler arasında kalan boşlukların **toplam büyüklüğü** yeni gelen bir prosesin bellek talebini karşılamaya yettiği halde, bu boşlukların bellekte dağınık olması (**bitişik / `contiguous` olmaması**) nedeniyle talebin karşılanamaması durumudur.
  - **%50 Kuralı (`50-percent rule`):** `First-fit` algoritmasının istatistiksel analizine göre, bellekte tahsis edilmiş $N$ adet blok varsa, dış parçalanma nedeniyle ortalama **$0.5 N$ blok** kaybedilir. Yani toplam belleğin $\frac{0.5N}{N + 0.5N} = \frac{1}{3}$'ü kullanılamaz durumdadır!
- **İç Parçalanma (`Internal Fragmentation`):** Bellek sabit boyutlu bloklar halinde tahsis edildiğinde, bir prosese ayrılan bellek bloğunun prosesin gerçekte talep ettiğinden biraz daha büyük olması ve **o bloğun içinde proses tarafından kullanılmayan artık alanın** başka hiçbir prosese verilememesi durumudur.

```text
Dış Parçalanma (External Fragmentation):   İç Parçalanma (Internal Fragmentation):
+------------+                             +-----------------------+
|  Proses A  |                             |  Proses A'ya Ayrılan  |
+------------+                             |  Blok: [ Kullanılan ] |
| Boş (30KB) | <-- Tek başına yetmiyor     |        [ Kullanılmayan| <-- İçeride kalan
+------------+                             |          Boşluk (İç) ]|     ve kimseye
|  Proses B  |                             +-----------------------+     verilemeyen
+------------+                                                           alan
| Boş (40KB) | <-- Toplamı 70KB ama
+------------+     bitişik değil!
```

#### Sıkıştırma (Compaction) ve Dezavantajları

Dış parçalanmayı gidermek için bellekteki proseslerin yerleri kaydırılarak tüm prosesler bir tarafa toplanır ve dağınık boşluklar tek bir büyük boş blok haline getirilir; buna **sıkıştırma (`compaction`)** denir. Ancak sıkıştırmanın ciddi maliyetleri vardır:
1. Yalnızca adres bağlama **yürütme zamanında (`execution time`)** dinamik olarak yapılıyorsa uygulanabilir.
2. Çalışmakta olan (`running`) ve hazır kuyruktaki (`ready`) proseslerin duraklatılıp bellek bloklarının kopyalanması ve tüm `relocation register` değerlerinin güncellenmesi gerekir; bu sırada işlemci kullanımı (CPU utilization) düşer.
3. Bekleyen G/Ç (`pending I/O`) işlemleri varsa prosesin yerinin değişmesi G/Ç verisinin yanlış adrese yazılmasına yol açar.

---

## 6. Kesimleme (Segmentation) Mimarisi ve Kesim Tablosu Donanımı

Bir prosesi tek bir bitişik blok olarak belleğe yerleştirmek çok fazla dış boşluk (hole) oluşturduğu için, programı daha küçük ve anlamlı parçalara bölerek her parçayı bellekte bulduğu uygun boşluğa yerleştirme fikri ortaya çıkmıştır. Buna **Saf Kesimleme (`Pure Segmentation`)** denir.

### 6.1 Kullanıcının Belleğe Bakışı ve Kesimler (Segments)

Bir programcı programını düz bir bayt dizisi olarak değil, mantıksal olarak anlamlı birimlerin birleşimi olarak görür. Kesimleme bu kullanıcı bakışını destekler; bir program aşağıdaki gibi **farklı uzunluklarda** kesimlerden (`segments`) oluşur:
- Ana program (`main program`),
- Prosedür (`procedure`), fonksiyon (`function`), metot (`method`),
- Nesne (`object`), yerel değişkenler (`local variables`), global değişkenler (`global variables`),
- Ortak blok (`common block`), yığın (`stack`), sembol tablosu (`symbol table`), diziler (`arrays`).

Örneğin bir programın mantıksal uzayında 0 numaralı kesim `subroutine`, 1 numaralı kesim `sqrt` fonksiyonu, 2 numaralı kesim `main program`, 3 numaralı kesim `stack` ve 4 numaralı kesim `symbol table` olsun. Bu kesimlerin her biri kendi içinde bitişiktir, ancak fiziksel bellekte birbirinden bağımsız, farklı adreslerdeki uygun boşluklara yerleştirilir.

### 6.2 Kesimleme Donanımı (Segmentation Hardware) ve Adres Dönüşümü

Proses tek bir blok olmaktan çıktığı için tek bir `relocation register` artık yeterli değildir. Bunun yerine her proses için bir **Kesim Tablosu (`Segment Table`)** tutulur ve işlemcinin ürettiği mantıksal adres iki bileşenli bir ikili (tuple) haline gelir (ekrandan, 01:38:30):
$$\langle \text{segment-number } (s), \text{ offset } (d) \rangle$$
- **$s$ (`segment number`):** Erişilmek istenen kesimin numarasıdır (kesim tablosunda indis olarak kullanılır).
- **$d$ (`offset`):** O kesimin başlangıcından itibaren kaçıncı bayta/satıra ($0, 1, \dots$) erişileceğini gösteren kayma değeridir.

Kesim tablosunun her satırı (`entry`) ilgili kesim için iki bilgi içerir:
1. **`base` (Taban):** Kesimin fiziksel bellekte başladığı başlangıç adresidir.
2. **`limit` (Sınır):** Kesimin uzunluğunu (büyüklüğünü) belirtir.

```text
                                      segment table
                                    +-------+-------+
                 +----------------> | limit | base  | (s. satır)
                 |                  +-------+-------+
                 |                      |       |
+-----+    +-----+-----+                |       |                  +-----------------+
| CPU | -> |  s  |  d  |                v       |                  |                 |
+-----+    +-----+-----+             +-----+    v                  |                 |
                    |                |  <  | --yes--> ( + ) -----> | physical memory |
                    +--------------> +-----+                        |                 |
                                        | no                       |                 |
                                        v                          +-----------------+
                              trap: addressing error
```

Kesim tablosunun kendisi de ana bellekte (prosesin adres uzayında/PCB ile ilişkili olarak) tutulduğu için işlemci içinde bu tabloyu işaret eden iki yazmaç bulunur:
- **`STBR` (`Segment-table base register`):** Kesim tablosunun fiziksel bellekteki başlangıç adresini tutar.
- **`STLR` (`Segment-table length register`):** Program tarafından kullanılan toplam kesim sayısını tutar. Bir $s$ kesim numarası yalnızca **$s < \text{STLR}$** ise geçerlidir.

**Adres Dönüşüm Adımları:**
1. Kesim numarası $s$'nin geçerli olup olmadığı kontrol edilir ($s < \text{STLR}$).
2. Kesim tablosunun $s$. satırından o kesime ait `limit` ve `base` değerleri okunur (ayrıca satırdaki geçerlilik biti `validation bit = 0` ise yasal olmayan kesim erişimi yakalanır ve okuma/yazma/çalıştırma `protection bits` yetkileri denetlenir).
3. Kesim içi kayma $d$'nin $0 \le d < \text{limit}$ aralığında olup olmadığı kontrol edilir:
   - Eğer **$d < \text{limit}$ (`yes`)** ise: $\text{Fiziksel Adres} = \text{base} + d$ toplanarak belleğe erişilir.
   - Eğer **$d \ge \text{limit}$ (`no`)** ise: **`trap: addressing error`** üretilir.

**Kesimlemenin Sınırlılığı:** Kesimler programın fonksiyon ve veri yapılarına göre **farklı uzunluklarda (variable length)** olduğu için, kesimlerin belleğe yerleştirilmesi yine bir *dinamik depolama tahsisi* problemidir (`first-fit` / `best-fit` gerektirir) ve kesimlemede hâlâ **dış parçalanma (`external fragmentation`)** problemi devam eder.

---

## 7. Sayfalama (Paging) Mimarisi, Adres Dönüşümü ve İç Parçalanma Analizi

Hem bitişik tahsisin hem de kesimlemenin çözemediği **dış parçalanma (`external fragmentation`)** ve sıkıştırma (`compaction`) ihtiyacını tamamen ortadan kaldırmak için geliştirilen ve günümüzdeki tüm işletim sistemlerinde kullanılan temel yöntem **Sayfalama (`Paging`)** mimarisidir.

### 7.1 Çerçeveler (Frames), Sayfalar (Pages) ve Sayfa Tablosu (Page Table)

Sayfalamada değişken boyutlu parçalar yerine **sabit ve birbirine eşit boyutlu** bloklar kullanılır (ekrandan, 01:50:00):
- **Çerçeveler (`Frames`):** Fiziksel bellek (RAM), boyutu 2'nin kuvveti olan (tipik olarak $512\text{ bayt}$ ile $16\text{ MB}$ arasında değişen) sabit uzunluklu bloklara bölünür; bu fiziksel blokların her birine **frame (çerçeve)** denir.
- **Sayfalar (`Pages`):** Prosesin mantıksal belleği (`logical memory`) de çerçevelerle **tam olarak aynı boyutta** sabit bloklara bölünür; bu mantıksal blokların her birine **page (sayfa)** denir.

> **Hocanın vurgusu:** Örneğin $64\text{ GB}$ ($2^6 \times 2^{30} = 2^{36}\text{ bayt}$) fiziksel belleği $512\text{ baytlık}$ ($2^9\text{ bayt}$) çerçevelere bölersek sistemde $\frac{2^{36}}{2^9} = 2^{27}$ adet çerçeve (`Frame 0, Frame 1, ...`) oluşur. İşletim sistemi tüm boş çerçevelerin kaydını tutar; $n$ sayfalık bir programı çalıştırmak için bellekte (yan yana olması gerekmeden herhangi bir yerde) **$n$ adet boş çerçeve** bulunması yeterlidir. Her proses için mantıksal sayfaları fiziksel çerçevelerle eşleştiren bir **Sayfa Tablosu (`Page Table`)** kurulur.

Slayttaki sayfalama modelini inceleyelim (ekrandan, 01:50:00):

```text
Mantıksal Bellek         Sayfa Tablosu          Fiziksel Bellek (RAM)
(Logical Memory)         (Page Table)           (Physical Memory)
                                                Frame No
+----------+                                       0    +----------+
|  page 0  |               0 [  1  ]                    |          |
+----------+                 +-----+               1    +----------+
|  page 1  |               1 [  4  ]                    |  page 0  |
+----------+                 +-----+               2    +----------+
|  page 2  |               2 [  3  ]                    |          |
+----------+                 +-----+               3    +----------+
|  page 3  |               3 [  7  ]                    |  page 2  |
+----------+                 +-----+               4    +----------+
                                                        |  page 1  |
                                                   5    +----------+
                                                        |          |
                                                   6    +----------+
                                                        |          |
                                                   7    +----------+
                                                        |  page 3  |
                                                        +----------+
```

Burada prosesin `page 0` sayfası 1 numaralı çerçeveye, `page 1` sayfası 4 numaralı çerçeveye, `page 2` sayfası 3 numaralı çerçeveye ve `page 3` sayfası 7 numaralı çerçeveye yerleşmiştir. Aradaki boş çerçeveler (`0, 2, 5, 6`) dış parçalanma oluşturmaz; başka herhangi bir prosesin sayfalarına doğrudan tahsis edilebilir.

> **Ek bilgi (derste anlatılmadı):** Hoca derste bu bölümde anlatılan temel sayfalamanın (pure paging) bir prosesin çalışmaya başlaması için tüm sayfalarının belleğe yüklenmesini gerektirdiğini, bir sonraki derste işlenecek olan **İstek Üzerine Sayfalama (`Demand Paging`)** yönteminde ise prosesin tüm sayfaları yerine başlangıçta yalnızca birkaç sayfasının belleğe alınıp diğer sayfaların ihtiyaç duyuldukça yükleneceğini belirtti.

### 7.2 Sayfalamada Adres Dönüşümü (Address Translation Scheme)

İşlemci tarafından üretilen mantıksal adres iki parçaya ayrılır:
- **Sayfa Numarası (`Page number` — $p$):** Sayfa tablosunda indis olarak kullanılır; ilgili sayfanın fiziksel bellekte hangi çerçevede (`frame number` — $f$) tutulduğunu verir.
- **Sayfa Kayması (`Page offset` — $d$):** Çerçevenin içindeki hangi bayta/satıra erişileceğini verir; adres dönüşümü sırasında değişmeden doğrudan fiziksel adrese eklenir (bit düzeyinde yan yana birleştirilir / *concatenation*).

Eğer mantıksal adres uzayı $2^m$ bayt ve bir sayfanın boyutu $2^n$ bayt ise, $m$ bitlik mantıksal adres şöyle bölünür:

```text
  |<--- m - n bit --->|<----- n bit ----->|
  +-------------------+-------------------+
  |  page number (p)  |  page offset (d)  |
  +-------------------+-------------------+
```

#### Sayısal Adres Dönüşüm Örneği ($m = 4, n = 2$, Slayt 8.37):

Mantıksal adres uzayı $2^4 = 16\text{ bayt}$ (`a`..`p` harfleriyle gösterilen 0..15 adresleri) ve sayfa boyutu $2^2 = 4\text{ bayt}$ olsun. Fiziksel bellek 32 bayt (8 çerçeve: `Frame 0..7`) olsun. Sayfa tablosu eşleşmesi şu şekildedir:
- `Page 0` (`a, b, c, d` — mantıksal adres `0, 1, 2, 3`) $\to$ **`Frame 5`**
- `Page 1` (`e, f, g, h` — mantıksal adres `4, 5, 6, 7`) $\to$ **`Frame 6`**
- `Page 2` (`i, j, k, l` — mantıksal adres `8, 9, 10, 11`) $\to$ **`Frame 1`**
- `Page 3` (`m, n, o, p` — mantıksal adres `12, 13, 14, 15`) $\to$ **`Frame 2`**

Her çerçeve 4 bayt olduğundan:
- Mantıksal adres **`0`** (`a` harfi: $p = 0, d = 0$), 5 numaralı çerçevenin 0. baytına, yani fiziksel adres $5 \times 4 + 0 =$ **`20`**'ye eşlenir.
- Mantıksal adres **`3`** (`d` harfi: $p = 0, d = 3$), fiziksel adres $5 \times 4 + 3 =$ **`23`**'e eşlenir.
- Mantıksal adres **`4`** (`e` harfi: $p = 1, d = 0$), 6 numaralı çerçevenin 0. baytına, yani fiziksel adres $6 \times 4 + 0 =$ **`24`**'e eşlenir.
- Mantıksal adres **`13`** (`n` harfi: $p = 3, d = 1$), 2 numaralı çerçevenin 1. baytına, yani fiziksel adres $2 \times 4 + 1 =$ **`9`**'a eşlenir.

### 7.3 Sayfalamada İç Parçalanma (Internal Fragmentation) Hesabı

Sayfalama dış parçalanmayı (`external fragmentation`) tamamen yok eder; ancak bir prosesin toplam boyutu sayfa boyutunun tam katı değilse, prosese tahsis edilen **son çerçevede** kullanılmayan bir boşluk kalır. Yani sayfalamada **iç parçalanma (`internal fragmentation`)** vardır:
- **En kötü durum (`Worst-case fragmentation`):** Proses son sayfadan yalnızca 1 bayt kullanırsa, $\text{1 frame} - \text{1 byte}$ iç parçalanma oluşur.
- **Ortalama durum (`On average fragmentation`):** Ortalama olarak proses başına $\frac{1}{2}\text{ frame size}$ (yarım çerçeve boyutu) iç parçalanma oluşur.

#### Sayısal İç Parçalanma Örneği (ekrandan, 01:52:00):

- **Verilenler:**
  - Sayfa boyutu ($\text{Page size}$) $= 2{,}048\text{ bayt}$
  - Proses boyutu ($\text{Process size}$) $= 72{,}766\text{ bayt}$
- **Adım Adım Çözüm:**
  1. Prosesin kaç sayfaya ihtiyaç duyduğunu bulmak için proses boyutunu sayfa boyutuna böleriz:
     $$\frac{72{,}766}{2{,}048} = 35\text{ tam sayfa} \quad (\text{kalan: } 72{,}766 - 35 \times 2{,}048 = 72{,}766 - 71{,}680 = 1{,}086\text{ bayt})$$
  2. Kalan $1{,}086\text{ bayt}$ için 36. çerçeve tahsis edilir (toplam **36 sayfa/çerçeve**).
  3. 36. çerçevenin içinde kullanılmayan **iç parçalanma (`internal fragmentation`)** miktarı:
     $$\text{Internal Fragmentation} = 2{,}048 - 1{,}086 = 962\text{ bayt}$$

#### Derste Yapılan Sayfa Boyutu Küçültme Analizi (`1024 bayt` ve `512 bayt`):

Hoca derste sınıfa şu soruyu yöneltti: *"İç parçalanmayı azaltmak için sayfa boyutunu `2048 bayt` yerine yarıya indirip `1024 bayt` yapsaydık bu örnekte iç parçalanma azalır mıydı?"*
- Sayfa boyutu $1{,}024\text{ bayt}$ yapılırsa:
  $$\frac{72{,}766}{1{,}024} = 71\text{ tam sayfa} + 62\text{ bayt kalan} \quad (71 \times 1{,}024 = 72{,}704\text{ bayt})$$
  Toplam $71 + 1 = 72\text{ sayfa}$ ($72 \times 1{,}024 = 73{,}728\text{ bayt}$) tahsis edilir. Son sayfadaki iç parçalanma:
  $$73{,}728 - 72{,}766 = 1{,}024 - 62 = 962\text{ bayt}$$
  Son sayfada kalan $1{,}086\text{ bayt}$, $1{,}024$'ten büyük olduğu için $1{,}024\text{ baytlık}$ sayfaya geçişte iç parçalanma yine **`962 bayt`** kalır!
- Ancak sayfa boyutu **$512\text{ bayt}$** yapılırsa:
  $$\frac{72{,}766}{512} = 142\text{ tam sayfa} + 62\text{ bayt kalan} \implies \text{Internal Fragmentation} = 512 - 62 = 450\text{ bayt}$$
  olarak iç parçalanma azalır.
- **Küçük Sayfa Boyutunun Dezavantajı:** Çerçeve/sayfa boyutunu çok küçültmek (örneğin uç durumda 1 bayt yapmak) iç parçalanmayı azaltır ama çerçeve sayısını ve dolayısıyla her proses için tutulan **sayfa tablosunun (`page table`) satır sayısını** aşırı büyütür; bu kez sayfa tablolarının kendisi RAM'de devasa yer kaplar. Bu nedenle zaman içinde işletim sistemlerinde sayfa boyutları büyümüştür (örneğin **Solaris** işletim sistemi hem **`8 KB`** hem de **`4 MB`** olmak üzere iki farklı sayfa boyutunu destekler).

### 7.4 Boş Çerçeve Listesi (Free-Frame List)

İşletim sistemi boş çerçevelerin listesini (`free-frame list`) tutar. Örneğin boş çerçeve listesinde `[14, 13, 18, 20, 15]` çerçeveleri varken 4 sayfalık yeni bir proses geldiğinde:
- `Page 0` $\to$ `Frame 14`, `Page 1` $\to$ `Frame 13`, `Page 2` $\to$ `Frame 18`, `Page 3` $\to$ `Frame 20` olarak yeni prosesin sayfa tablosuna yazılır ve boş çerçeve listesinde yalnızca `[15]` kalır.

---

## 8. Sayfa Tablosu Gerçeklemesi, TLB (Translation Look-aside Buffer) ve Etkin Erişim Süresi (EAT)

### 8.1 Sayfa Tablosu Donanımı ve İki Aşamalı Bellek Erişimi Problemi

Her prosesin kendine ait bir sayfa tablosu vardır ve bu tablo ana bellekte (RAM'de) tutulur. İşlemci içinde aktif prosesin sayfa tablosunu gösteren iki yazmaç bulunur:
- **`PTBR` (`Page-table base register`):** Sayfa tablosunun fiziksel bellekteki başlangıç adresini işaret eder.
- **`PTLR` (`Page-table length register`):** Sayfa tablosunun büyüklüğünü tutar.

**Problem (İki Bellek Erişimi):** Bu şemada işlemci tek bir veriye veya komuta (instruction/data) erişmek istediğinde **iki kez ana belleğe** gitmek zorunda kalır:
1. **1. Bellek Erişimi:** `PTBR` ve sayfa numarası $p$'yi kullanarak ana bellekteki **sayfa tablosuna** erişip çerçeve numarasını ($f$) öğrenmek.
2. **2. Bellek Erişimi:** Elde edilen çerçeve numarası $f$ ile kayma $d$'yi birleştirip ana bellekteki **gerçek veriye veya komuta** erişmek.

Bu durum bellek erişimini iki kat yavaşlatır.

### 8.2 İlişkisel Önbellek: TLB (Translation Look-aside Buffer)

İki bellek erişimi problemini çözmek için MMU içerisine **ilişkisel bellek (`associative memory`)** adı verilen, paralel arama ($O(1)$ karmaşıklıkta tek adımda arama) yapabilen küçük ve çok hızlı bir donanım önbelleği yerleştirilir. Buna **TLB (`Translation Look-aside Buffer`)** denir.

- TLB genellikle **64 ile 1024 kayıt (`entries`)** tutacak büyüklüktedir ve sık kullanılan sayfa-çerçeve (`<page #, frame #>`) eşleşmelerini saklar. (Yarı iletken teknolojisinde önbellek boyutunu aşırı büyütmek iletken tel uzunluğunu artırarak dirençsel/rezistif, kapasitif ve ısıl gecikmelere yol açtığı için TLB ve L1/L2/L3 önbellek boyutları sınırlı tutulur).
- **TLB Çalışma Akışı:**

```text
                       TLB (Hızlı Donanım Önbelleği)
                       +--------------+--------------+
                  +--> | page #       | frame #      | --(TLB Hit)-->+
                  |    +--------------+--------------+               |
                  |           | (TLB Miss)                           v
+-----+    +---+---+          v                                  +-------+---+
| CPU | -> | p | d |   Sayfa Tablosu (RAM'de)                    |   f   | d | -> Fiziksel
+-----+    +---+---+   +--------------+                          +-------+---+    Bellek
               |       | frame #      | ---------------------------->+   ^
               |       +--------------+    (Hem adresi oluşturur         |
               |                            hem TLB'ye kaydeder)         |
               +---------------------------------------------------------+
```

1. CPU `<p, d>` mantıksal adresini ürettiğinde önce $p$ sayfa numarası **TLB** içinde paralel olarak aranır.
2. **TLB Hit (İsabet):** Sayfa numarası TLB'de bulunursa çerçeve numarası $f$ anında alınır ve bellekteki sayfa tablosuna hiç gidilmeden doğrudan fiziksel bellekteki veriye erişilir (**tek bellek erişimi**).
3. **TLB Miss (Iskalama):** Sayfa numarası TLB'de bulunamazsa ana bellekteki sayfa tablosuna gidilir (**1. bellek erişimi**), çerçeve numarası alınarak veriye ulaşılır (**2. bellek erişimi**) ve bir sonraki erişimde hızlı bulunması için bu `<p, f>` çifti TLB'ye eklenir (TLB doluysa en sık kullanılanları koruyan bir **yer değiştirme politikası / `replacement policy`** işletilir).
4. **ASID (`Address-Space Identifier`):** Bazı TLB'ler her kaydın yanında o kaydın hangi prosese ait olduğunu gösteren **ASID** bilgisini tutar. Eğer TLB donanımı ASID desteklemiyorsa, bir prosesten diğerine her bağlam değişimi (context switch) yapıldığında eski prosesin sayfa numaralarının yeni prosesle karışmaması için TLB'nin tamamen temizlenmesi (**`flush`** edilmesi) zorunludur.

### 8.3 Etkin Erişim Süresi (Effective Access Time — EAT)

TLB kullanımının sağladığı hız kazancı **Etkin Erişim Süresi (`Effective Access Time — EAT`)** ile ölçülür (ekrandan, 02:04:30):
- **$\varepsilon$ (`Associative Lookup`):** TLB üzerinde arama süresi (ana bellek erişim süresinin %10'undan bile az olabilir).
- **$\alpha$ (`Hit Ratio` — İsabet Oranı):** Aranan bir sayfa numarasının TLB'de bulunma yüzdesidir (olasılığıdır; bulunamama / *miss* olasılığı ise $1 - \alpha$'dır).
- Ana belleğe tek bir erişim süresini **1 birim** (veya $m\text{ ns}$) kabul edersek:
  - **TLB Hit durumunda** ($\alpha$ olasılıkla): TLB araması ($\varepsilon$) + 1 bellek erişimi (veri/komut) $= 1 + \varepsilon$ (veya $m + \varepsilon$).
  - **TLB Miss durumunda** ($1 - \alpha$ olasılıkla): TLB araması ($\varepsilon$) + 2 bellek erişimi (1. sayfa tablosu + 2. veri/komut) $= 2 + \varepsilon$ (veya $2m + \varepsilon$).

Genel formül:
$$\text{EAT} = (1 + \varepsilon)\alpha + (2 + \varepsilon)(1 - \alpha) = 2 + \varepsilon - \alpha$$

#### Slayttaki Sayısal Örnekler (ekrandan, 02:04:30):

Ana bellek erişim süresi $100\text{ ns}$ ve TLB arama süresi $\varepsilon = 20\text{ ns}$ olsun:
1. **İsabet oranı $\alpha = \%80$ ($0.80$) iken (slayttaki hesap):**
   $$\text{EAT} = 0.80 \times 100 + 0.20 \times 200 = 80 + 40 = 120\text{ ns}$$
   (TLB olmasaydı her erişim $200\text{ ns}$ sürecekken $120\text{ ns}$'ye, yani %40 oranında iyileşmeye ulaşılmıştır).
2. **Daha gerçekçi bir isabet oranı olan $\alpha = \%99$ ($0.99$) iken (slayttaki hesap):**
   $$\text{EAT} = 0.99 \times 100 + 0.01 \times 200 = 99 + 2 = 101\text{ ns}$$
   ($200\text{ ns}$ yerine neredeyse tek bellek erişimi süresi olan $100\text{ ns}$'ye inilmiştir).

> **Ders sonrası not:** Slaytta (ekrandan, 02:04:30, Silberschatz 9. Baskı Slayt 8.44) üst satırda $\varepsilon = 20\text{ ns}$ ve formül $\text{EAT} = (1 + \varepsilon)\alpha + (2 + \varepsilon)(1 - \alpha)$ olarak verildiği halde, alt satırdaki sayısal hesaplamalarda (`0.80 x 100 + 0.20 x 200 = 120ns` ve `0.99 x 100 + 0.01 x 200 = 101ns`) $\varepsilon = 20\text{ ns}$ değeri toplama dahil edilmemiştir (Silberschatz kitabının 9. baskısında TLB aramasının işlemci boru hattında paralel/ihmal edilebilir sürede yapıldığı kabulüne geçilirken slaytta eski $\varepsilon = 20\text{ ns}$ satırı kalmıştır). Büyük olasılıkla sınavda $\varepsilon = 20\text{ ns}$ ardışık gecikme olarak hesaba katılırsa:
> - $\alpha = \%80$ için: $\text{EAT} = 0.80 \times (100 + 20) + 0.20 \times (200 + 20) = 0.80 \times 120 + 0.20 \times 220 = 96 + 44 = \mathbf{140\text{ ns}}$
> - $\alpha = \%99$ için: $\text{EAT} = 0.99 \times (100 + 20) + 0.01 \times (200 + 20) = 0.99 \times 120 + 0.01 \times 220 = 118.8 + 2.2 = \mathbf{121\text{ ns}}$
> olarak bulunur; $\varepsilon$ ihmal edilirse slayttaki gibi **`120 ns`** ve **`101 ns`** elde edilir.

**Soru:** Kesim tablosu (segment table) ve sayfa tablosu (page table) fiziksel olarak nerede tutulur ve işlemci bu tablolara nasıl ulaşır?
**Cevap:** Hoca, her prosesin kendine ait bir kesim tablosu veya sayfa tablosu bulunduğunu; bu tabloların fiziksel olarak ana bellekte (ilgili prosesin adres uzayı / veri bölgesi içinde) saklandığını ve işletim sisteminin aktif proseslerin bağlı listesinde (`PID` ile birlikte) bu tabloların adreslerini tuttuğunu açıkladı. Bir proses `running` durumuna getirildiğinde (context switch sırasında), o prosesin tablo başlangıç ve uzunluk bilgileri işlemci içindeki `STBR`/`STLR` veya `PTBR`/`PTLR` yazmaçlarına yüklenir.

---

## Örnek Sorular

### Soru 1: Bellek Adresleme Bit ve Bayt Hesabı (derste sözlü ve tahtada, 00:12:01)

**Soru:** Bayt adreslemeli (her adreste 1 bayt veri tutulan) **64 GB** kapasiteli bir ana bellekte (RAM) tüm bellek hücrelerini tekil olarak adresleyebilmek için en az kaç bitlik adres genişliği gerekir? Bu adresler bellekte 1 baytın (8 bitin) tam katları şeklinde saklanırsa tek bir adres kaç bayt yer kaplar?

**Çözüm (derste verildi):**
- $1\text{ GB} = 2^{30}\text{ bayt}$ ve $64 = 2^6$ olduğundan toplam bellek hücresi sayısı:
  $$64\text{ GB} = 2^6 \times 2^{30} = 2^{36}\text{ bayt}$$
- $2^{36}$ farklı baytı `00...0` ile `11...1` arasında adreslemek için en az **36 bit** gerekir.
- 36 bit, 8 bitin (1 baytın) tam katına yukarı yuvarlandığında **40 bit = 5 bayt** yer kaplar.

### Soru 2: Yer Değiştirme Yazmacı (Relocation Register) ile Fiziksel Adres Hesabı (ekrandan, 00:41:45, 01:15:00)

**Soru:** Bitişik bellek tahsisi kullanılan bir sistemde aktif prosesin `relocation register` değeri `14000` ve `limit register` değeri `5000` olsun. İşlemci (CPU) mantıksal adres olarak **`346`** ürettiğinde MMU hangi fiziksel adresi üretir? Eğer işlemci mantıksal adres olarak **`5200`** üretirse ne olur?

**Çözüm (derste verildi):**
- Mantıksal adres `346 < 5000` (`limit register`) koşulunu sağladığı için geçerlidir; MMU mantıksal adrese `relocation register` değerini ekleyerek fiziksel adresi üretir:
  $$\text{Fiziksel Adres} = 14000 + 346 = \mathbf{14346}$$
- Mantıksal adres `5200 < 5000` koşulunu sağlamadığı (`no` kolu) için MMU belleğe erişimi engeller ve işletim sistemine **`trap: addressing error`** kesmesi üretir.

### Soru 3: Takas (Swapping) Süresinin Bağlam Değişimine Etkisi (ekrandan, 01:06:15)

**Soru:** Bellekte yer açmak için **100 MB** büyüklüğündeki bir proses sabit diske çıkarılacak (`swap out`) ve yerine aynı büyüklükte (**100 MB**) başka bir proses diskten belleğe alınacaktır (`swap in`). Sabit diskin veri aktarım hızı **50 MB/saniye** olduğuna göre, bu bağlam değişiminin toplam takas bileşeni süresi kaç milisaniyedir (ve kaç saniyedir)?

**Çözüm (derste verildi):**
- $\text{Swap out süresi} = \frac{100\text{ MB}}{50\text{ MB/sn}} = 2\text{ sn} = 2000\text{ ms}$.
- $\text{Swap in süresi} = \frac{100\text{ MB}}{50\text{ MB/sn}} = 2\text{ sn} = 2000\text{ ms}$.
- $\text{Toplam takas süresi} = 2000\text{ ms} + 2000\text{ ms} = \mathbf{4000\text{ ms}}$ (**4 saniye**).

### Soru 4: Sayfalamada (Paging) Sayfa Sayısı ve İç Parçalanma Hesabı (ekrandan, 01:52:00)

**Soru:** Sayfa boyutunun (`page size`) **2,048 bayt** olduğu bir sistemde **72,766 bayt** büyüklüğündeki bir proses belleğe yüklenecektir:
a) Bu prosese kaç adet çerçeve (`frame`) tahsis edilir ve kaç baytlık iç parçalanma (`internal fragmentation`) oluşur?
b) Sayfa boyutu **1,024 bayt** ve **512 bayt** olarak değiştirilirse iç parçalanma miktarı nasıl değişir?

**Çözüm (derste verildi):**
- **a)** $\frac{72{,}766}{2{,}048} = 35\text{ tam sayfa}$ ve kalan $72{,}766 - (35 \times 2{,}048) = 72{,}766 - 71{,}680 = 1{,}086\text{ bayt}$'tır. Kalan kısım için 1 çerçeve daha ayrılır; toplam **36 çerçeve** tahsis edilir. Son çerçevedeki iç parçalanma:
  $$\text{Internal Fragmentation} = 2{,}048 - 1{,}086 = \mathbf{962\text{ bayt}}$$
- **b)** Sayfa boyutu **1,024 bayt** yapılırsa: $\frac{72{,}766}{1{,}024} = 71\text{ tam sayfa} + 62\text{ bayt kalan}$ olur (toplam 72 çerçeve, $72 \times 1{,}024 = 73{,}728\text{ bayt}$). İç parçalanma $1{,}024 - 62 = \mathbf{962\text{ bayt}}$ olarak aynı kalır. Sayfa boyutu **512 bayt** yapılırsa: $\frac{72{,}766}{512} = 142\text{ tam sayfa} + 62\text{ bayt kalan}$ olur ve iç parçalanma $512 - 62 = \mathbf{450\text{ bayt}}$'a düşer.

### Soru 5: TLB ile Etkin Erişim Süresi (Effective Access Time — EAT) Hesabı (ekrandan, 02:04:30)

**Soru:** Sayfalamalı bir bellek sisteminde ana belleğe erişim süresi **100 ns**, TLB arama süresi $\varepsilon = 20\text{ ns}$ ve TLB isabet oranı ($\text{hit ratio}$, $\alpha$) **%80** (ikinci durumda **%99**) olarak verilmiştir. Etkin bellek erişim süresini ($\text{EAT}$) hesaplayınız.

**Çözüm (derste verildi):**
- Slayttaki hesaplamaya göre ($\varepsilon$ arama süresi ihmal edildiğinde, TLB isabetinde $100\text{ ns}$, ıskalamada 2 bellek erişimiyle $200\text{ ns}$):
  - $\alpha = \%80$ için: $\text{EAT} = 0.80 \times 100 + 0.20 \times 200 = \mathbf{120\text{ ns}}$.
  - $\alpha = \%99$ için: $\text{EAT} = 0.99 \times 100 + 0.01 \times 200 = \mathbf{101\text{ ns}}$.
- ($\varepsilon = 20\text{ ns}$ formüle doğrudan eklendiğinde ise $\alpha = \%80$ için $\text{EAT} = 0.80 \times 120 + 0.20 \times 220 = \mathbf{140\text{ ns}}$ ve $\alpha = \%99$ için $\text{EAT} = 0.99 \times 120 + 0.01 \times 220 = \mathbf{121\text{ ns}}$ olur).

---

## Dersin Toparlaması

Bu derste işletim sistemlerinde **Ana Bellek Yönetimi (Main Memory Management)** konusunun temelleri ele alınmıştır. İlk olarak işlemci, önbellek, RAM ve disk arasındaki hiyerarşi ile ikilik adresleme mantığı incelenmiş; ardından proseslerin birbirinin bellek alanına müdahale etmesini önleyen **`base` ve `limit` yazmaçları**, **adres bağlama (`compile time`, `load time`, `execution time`)**, **MMU (Memory-Management Unit)** ile mantıksal adresten fiziksel adrese dönüşüm, **dinamik yükleme (`dynamic loading`)** ve **dinamik bağlama (`dynamic linking` / `stub` / `DLL`)** kavramları açıklanmıştır. Bellek dolduğunda proseslerin diske çıkarılıp alınmasını sağlayan **takas (`swapping`)** mekanizmasının yüksek zaman maliyeti, bekleyen G/Ç (`pending I/O`) problemi ve mobil işletim sistemlerinin flash bellek kısıtları nedeniyle swapping kullanmaması tartışılmıştır. Son olarak bitişik bellek tahsisinde (`contiguous allocation`) boşluk seçim algoritmaları (**First-fit**, **Best-fit**, **Worst-fit**), **dış parçalanma (`external fragmentation`)**, **iç parçalanma (`internal fragmentation`)** ve sıkıştırma (`compaction`) incelenmiş; ardından bitişik olmayan tahsis yöntemleri olan değişken boyutlu **Kesimleme (`Segmentation`)** ile sabit boyutlu **Sayfalama (`Paging`)** mimarileri ve sayfa tablosu erişimlerini hızlandıran **TLB (`Translation Look-aside Buffer`)** önbelleğinin etkin erişim süresi (`EAT`) analiz edilmiştir. Gelecek derste sayfalama mimarisinde koruma, paylaşımlı sayfalar, sayfa tablosu yapıları ve sanal bellek (*demand paging*) konularıyla devam edilecektir.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
