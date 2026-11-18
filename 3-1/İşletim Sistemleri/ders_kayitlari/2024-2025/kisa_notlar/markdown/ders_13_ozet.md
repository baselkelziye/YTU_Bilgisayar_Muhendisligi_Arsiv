# Ders 13 Çalışma Özeti

## Genel Konular

- Sayfalamada bellek koruması (Memory Protection) ve paylaşımlı sayfalar (Shared Pages)
  - Sayfa tablosundaki her kayıt için erişim yetkilerini denetleyen koruma bitleri (`protection bits` — salt okunur / okuma-yazma) ve sayfanın prosesin mantıksal adres uzayına ait olup olmadığını belirten **geçerli-geçersiz biti (`valid-invalid bit`: `v` / `i`)**.
  - **Paylaşımlı sayfalar (Shared Pages):** Birden fazla prosesin kullandığı salt okunur ve yeniden girilebilir (**reentrant / pure code** — örneğin metin editörleri, yazım denetleyiciler, derleyiciler) kod sayfalarının fiziksel bellekte tek bir kopya olarak tutulup her prosesin sayfa tablosundan aynı çerçevelere (`3, 4, 6`) işaret edilmesi (ekrandan, 00:10:00, 00:12:00).
- Sayfa tablosu yapıları (Structure of the Page Table) ve donanım mimarisi örnekleri
  - 32 bit ve 64 bit sistemlerde sayfa tablolarının aşırı büyümesi problemi ($2^{32} / 2^{12} = 2^{20} \approx 1\text{ milyon}$ kayıt) ve üç temel çözüm yapısı: **Hiyerarşik Sayfalama (`Hierarchical Paging` / İki ve çok seviyeli sayfa tabloları)**, **Çırpılı Sayfa Tabloları (`Hashed Page Tables`)** ve **Ters Çevrilmiş Sayfa Tabloları (`Inverted Page Tables`)** (ekrandan, 00:18:00, 00:25:00, 00:27:45).
  - SPARC Solaris, Intel IA-32 (`LDT`/`GDT` kesimleme + iki seviyeli sayfalama), x86-64 (48 bit 4 seviyeli sayfalama) ve ARM (RISC) mimarilerinde bellek yönetimi; CISC ve RISC komut kümelerinin dallanma ve bellek erişim farkları.
- Sanal Bellek (Virtual Memory), İstek Üzerine Sayfalama (Demand Paging) ve Yazarken Kopyalama (Copy-on-Write)
  - Bir prosesin çalışması için tamamının RAM'de bulunması yerine yalnızca ihtiyaç duyulan sayfalarının belleğe getirilmesi (**Demand Paging**), **tembel takasçı (`lazy swapper` / `pager`)**, **sayfa hatası (`page fault`)** tuzağı ve **Saf İstek Üzerine Sayfalama (`Pure Demand Paging`)** (ekrandan, 00:50:00).
  - İstek üzerine sayfalamanın başarımı ve **Etkin Erişim Süresi (`EAT = (1 - p) x ma + p x page_fault_time`)** analizi (ekrandan, 00:56:45).
  - **Yazarken Kopyalama (`Copy-on-Write` — COW)** ve `vfork()` sistem çağrısı.
- Sayfa Değiştirme (Page Replacement) algoritmaları
  - Boş çerçeve kalmadığında kurban çerçeve (`victim frame`) seçimi ve disk yazma maliyetini yarıya indiren **değiştirilme / kirli biti (`modify / dirty bit`)**.
  - Referans dizgesi (`reference string`) üzerinde sayfa değiştirme algoritmaları: **FIFO (First-In-First-Out)** ve **Belady Anomalisi (`Belady's Anomaly`)** (ekrandan, 01:30:00), **Optimal (`OPT` / `MIN`) Algoritma** (ekrandan, 01:34:15), **LRU (`Least Recently Used`) Algoritması** (ekrandan, 01:35:30), yığın (`stack`) gerçeklemesi ve **İkinci Şans (`Second-Chance` / `Clock`) Algoritması**.
- Çerçeve Tahsisi (Frame Allocation), Çırpınma (Thrashing) ve Çalışma Kümesi (Working-Set) Modeli
  - **Eşit tahsis (`Equal allocation`)**, **orantılı tahsis (`Proportional allocation`)**, **yerel (`local`)** ve **küresel (`global`)** değiştirme politikaları.
  - Proseslerin yeterli çerçeveye sahip olmaması nedeniyle yürütmeden çok sayfa takasıyla vakit kaybetmesi (**Çırpınma / `Thrashing`**), yerellik modeli (`locality model`) ve **Çalışma Kümesi Modeli (`Working-Set Model` — $\Delta$ penceresi ve $WSS_i$)** (ekrandan, 01:50:00).
  - Çekirdek bellek tahsisinde **Buddy System** ($2^k$ katlarıyla bölme), program yapısının (matrislerde satır/sütun döngü sırasının) sayfa hatası sayısına etkisi.
- Yığın Depolama (Mass Storage) yapısı ve Disk Zamanlama (Disk Scheduling) algoritmaları
  - Manyetik sabit disklerin fiziksel yapısı (plaka, silindir, iz / `track`, sektör), erişim süresi bileşenleri (**arama süresi / `seek time`** ve **dönme gecikmesi / `rotational latency`**) ile SSD ve manyetik teyp karşılaştırması.
  - Disk kafa hareketini en aza indiren zamanlama algoritmaları: **FCFS** (ekrandan, 02:15:00), **SSTF (`Shortest Seek Time First`)**, **SCAN (Asansör algoritması)**, **C-SCAN (`Circular SCAN`)** ve **C-LOOK**; önyükleme bloğu (**Boot block / MBR**).

## Hocanın Özellikle Vurguladığı Kısımlar

- Paylaşımlı sayfalarda (Shared Pages) kodun "reentrant" (salt okunur) olma zorunluluğu
  - Birden fazla prosesin ortak kullandığı kod sayfalarının (`ed1, ed2, ed3`) fiziksel bellekte tek kopya olarak tutulabilmesi için bu kodun çalışma sırasında kendi kendini değiştirmeyen (**reentrant / read-only**) yapıda olması gerekir; aksi halde bir prosesin yaptığı değişiklik diğer proseslerin çalışmasını bozar.
- İstek Üzerine Sayfalamada (Demand Paging) sayfa hatası oranının ($p$) kritikliği ve Değiştirilme Biti (Dirty Bit)
  - Bellek erişimi 200 ns iken diskten sayfa getirme süresi 8 ms (8.000.000 ns) mertebesindedir. Binde birlik ($p = 0.001$) bir sayfa hatası oranı bile sistemi **40 kat** yavaşlatır (ekrandan, 00:56:45). Ayrıca kurban seçilen bir sayfa belleğe alındığından beri hiç değiştirilmemişse (`dirty bit == 0`), diske geri yazılmasına gerek olmadığı için takas maliyeti yarıya iner.
- Optimal (OPT) algoritmanın neden gerçekte kullanılamadığı ve ne işe yaradığı
  - Gelecekte en uzun süre kullanılmayacak sayfayı çıkaran **Optimal algoritma**, işlemcinin ileride hangi sayfaları talep edeceğini önceden bilemeyeceği için gerçek bir işletim sisteminde uygulanamaz; ancak geliştirilen diğer algoritmaların (FIFO, LRU vb.) başarımını ölçmek için **teorik üst sınır (benchmark / kıyaslama ölçütü)** olarak kullanılır (ekrandan, 01:34:15).
- Çırpınma (Thrashing) ve Proaktif bir yaklaşım olarak Çalışma Kümesi (Working-Set) Modeli
  - Çoklu programlama derecesi aşırı artırıldığında proseslere düşen çerçeve sayısı azalır, sürekli sayfa hatası oluşur ve işlemci kullanımı (CPU utilization) aniden çakılır (**thrashing**). Hoca, FIFO ve LRU'nun sayfa hatası olduktan sonra tepki veren **reaktif** yaklaşımlar olduğunu, **Working-Set** modelinin ise $\Delta$ penceresindeki geçmiş referanslara bakarak prosesin ihtiyaç duyduğu çerçeve sayısını önceden tahmin eden **proaktif** bir yaklaşım olduğunu vurguladı (ekrandan, 01:50:00).
- Programlama yapısının (satır-öncelikli / sütun-öncelikli matris erişiminin) sayfa hatalarına etkisi
  - Bellekte satır satır saklanan $128 \times 128$ boyutlu bir matriste dış döngüye sütun (`j`), iç döngüye satır (`i`) yazılırsa her adımda farklı bir sayfaya erişilerek $128 \times 128 = 16.384$ sayfa hatası oluşurken; dış döngüye satır (`i`), iç döngüye sütun (`j`) yazıldığında yalnızca $128$ sayfa hatası oluşur. Hoca, üst seviye kod yazarken bile alt seviye bellek yerleşimini bilmenin performansı doğrudan etkilediğini vurguladı.

## Kısa Tekrar Notları

- **Valid-Invalid Bit (`v`/`i`):** Sayfalama korumasında `v` sayfanın yasal ve bellekte olduğunu, `i` ise sayfanın prosesin adres uzayında olmadığını veya (sanal bellekte) şu an ana bellekte olmayıp diskte durduğunu gösterir.
- **Sayfa Tablosu Yapıları:**
  - *Hierarchical Paging:* Sayfa tablosunu dış (*outer*) ve iç (*inner*) tablolara böler (32 bitte örn. `p1(10-12 bit) + p2(10 bit) + d(10-12 bit)`). 64 bit mimarilerde çok fazla bellek erişimi gerektirdiği için tek başına uygun değildir.
  - *Hashed Page Table:* Sanal sayfa numarası $p$ bir hash fonksiyonundan geçirilir; çakışmalar bağlı liste (`<q, s, next> -> <p, r, next>`) ile çözülür (32 bitten büyük adres uzaylarında yaygındır, ekrandan, 00:25:00).
  - *Inverted Page Table:* Proses başına tablo tutmak yerine tüm sistem için fiziksel çerçeve sayısı kadar satırı olan **tek bir tablo** tutar; her satır `<pid, p>` içerir. Bellekten tasarruf sağlar ancak arama süresini uzatır (ekrandan, 00:27:45).
- **Demand Paging EAT Formülü:** $p$ sayfa hatası olasılığı ($0 \le p \le 1$) olmak üzere:
  $$\text{EAT} = (1 - p) \times \text{bellek erişim süresi} + p \times \text{sayfa hatası servis süresi}$$
- **Copy-on-Write (COW):** `fork()` sonrasında ebeveyn ve çocuk prosesler başlangıçta aynı fiziksel sayfaları paylaşır; yalnızca bir proses ortak sayfaya **yazma** yaptığında o sayfanın kopyası oluşturulur.
- **Sayfa Değiştirme Algoritmaları (`7,0,1,2,0,3,0,4,2,3,0,3,2,1,2,0,1,7,0,1` dizgesi, 3 çerçeve):**
  - **FIFO:** Belleğe ilk giren sayfayı çıkarır $\implies$ **15 page fault**. Çerçeve sayısı artırıldığında sayfa hatası sayısının artması durumuna **Belady Anomalisi** denir (ekrandan, 01:30:00).
  - **Optimal (OPT):** Gelecekte en geç kullanılacak sayfayı çıkarır $\implies$ **9 page fault** (ekrandan, 01:34:15).
  - **LRU (Least Recently Used):** Geçmişte en uzun süredir kullanılmayan sayfayı çıkarır $\implies$ **12 page fault** (ekrandan, 01:35:30). OPT ve LRU yığın (*stack*) algoritmalarıdır, Belady anomalisi göstermezler.
  - **Second-Chance (Clock):** FIFO sırasıyla bakar; referans biti `1` olan sayfaya ikinci şans verip bitini `0` yapar ve sıradakine geçer, biti `0` olanı çıkarır.
- **Çerçeve Tahsisi:** *Equal allocation* ($m / n$), *Proportional allocation* ($a_i = \frac{s_i}{S} \times m$).
- **Working-Set Modeli:** $\Delta$ penceresindeki tekil sayfa kümesi $WS(t)$'dir; toplam talep $D = \sum WSS_i > m$ (toplam çerçeve) olursa **thrashing** başlar ve bir proses askıya alınır (`suspend` / `swap out`).
- **Disk Zamanlama (`53` başlangıç, `98, 183, 37, 122, 14, 124, 65, 67` kuyruğu):**
  - **FCFS:** İstek sırasıyla gider $\implies$ **640 silindir** hareketi (ekrandan, 02:15:00).
  - **SSTF:** Mevcut konumdan en yakın silindire gider $\implies$ **236 silindir** hareketi (*starvation* riski vardır).
  - **SCAN:** Disk kolu bir uçtan (`0`) diğer uca (`199`) asansör gibi tarayarak gider $\implies$ **236 silindir** hareketi.
  - **C-SCAN / C-LOOK:** Tek yönde hizmet verir, sona (veya C-LOOK'ta son isteğe) ulaşınca hizmet vermeden başa döner.

## Detaylı Açıklamalar

- **Paylaşımlı Sayfalar (Shared Pages) ve Sayfa Tablosu Yapıları.**
  - **Paylaşımlı Sayfalar Örneği (ekrandan, 00:12:00):** Üç ayrı kullanıcı prosesi ($P_1, P_2, P_3$) aynı metin editörü programını çalıştırıyor olsun. Editörün salt okunur (*reentrant*) kod sayfaları `ed1`, `ed2`, `ed3` (her biri örneğin 50 KB) fiziksel bellekte sırasıyla `3`, `4` ve `6` numaralı çerçevelere yalnızca bir kez yüklenir; her prosesin kendi sayfa tablosunun ilk üç satırı `[3, 4, 6]` değerlerini tutar. Her prosesin kendine özel veri sayfası ise (`data1`, `data2`, `data3`) farklı çerçevelerde (`1`, `7`, `2`) saklanır. Böylece 3 proses için $9$ kod çerçevesi yerine yalnız $3$ kod çerçevesi harcanır.
  - **Hiyerarşik, Çırpılı ve Ters Çevrilmiş Sayfa Tabloları:**
    - $32$ bitlik mantıksal adres uzayında ($2^{32}\text{ bayt}$) sayfa boyutu $4\text{ KB}$ ($2^{12}\text{ bayt}$) seçildiğinde sayfa tablosunda $\frac{2^{32}}{2^{12}} = 2^{20}$ (yaklaşık 1 milyon) kayıt bulunur.
      - **Ders sonrası not:** Hoca derste $2^{20}$ kayıtlı tablonun boyutunu söylerken *"1 milyon tane entry'den oluşan bir page tablomuz... yani ne oluyor? 1 megabyte'lık bir alandan oluşan"* (00:14:00) demiş, ardından bir öğrencinin her kaydın 4 bayt olduğunu hatırlatması üzerine *"O zaman 4 byte olunca... iki üzeri ikiye böleceğiz"* (00:14:44) diyerek sayfa boyutunun 4 bayt olması durumuyla karıştırmıştır. Büyük olasılıkla Silberschatz kitabındaki (Bölüm 8.6) hesaba göre: $2^{20}$ adet sayfa tablosu kaydının her biri $4\text{ bayt}$ (32 bit) yer kapladığından, tek bir prosesin sayfa tablosu bellekte $2^{20} \times 4\text{ bayt} = \mathbf{4\text{ MB}}$ yer tutar.
    - **İki Seviyeli (Hierarchical) Sayfalama (ekrandan, 00:18:00):** 4 MB'lık sayfa tablosunu bellekte tek parça (contiguous) tutmak yerine sayfa tablosunun kendisi de sayfalanır. Mantıksal adres `<p1, p2, d>` olarak üçe bölünür: $p_1$ dış sayfa tablosunun (*outer page table*) indisini, $p_2$ iç sayfa tablosu sayfasının (*page of page table*) içindeki indisi, $d$ ise sayfa içi kaymayı (*offset*) gösterir. $64$ bitlik sistemlerde ise $4\text{ KB}$ sayfa boyutuyla $2^{52}$ kayıt oluşacağından iki seviyeli yapı (`42 + 10 + 12`) bile dış tabloyu aşırı büyütür; bu yüzden 3 veya 4 seviyeli sayfalama (örneğin x86-64 mimarisinde 48 bitlik adres için `PML4 -> Directory Pointer -> Page Directory -> Page Table -> Offset`) kullanılır.
    - **Çırpılı Sayfa Tablosu (Hashed Page Table, ekrandan, 00:25:00):** 32 bitten büyük adres uzaylarında sanal sayfa numarası $p$ bir çırpı fonksiyonundan (`hash function`) geçirilerek çırpı tablosuna (`hash table`) erişilir. Çakışmaları çözmek için her tablo gözü üç alanlı düğümlerden oluşan bir bağlı liste (`<sanal sayfa no (p), çerçeve no (r), sonraki işaretçisi>`) tutar; listede $p$ eşleştiğinde $r$ çerçeve numarası alınıp $d$ ile birleştirilir.
    - **Ters Çevrilmiş Sayfa Tablosu (Inverted Page Table, ekrandan, 00:27:45):** Her prosese ayrı sayfa tablosu açmak yerine tüm sistemde fiziksel bellekteki çerçeve sayısı kadar satırı olan **tek bir tablo** tutulur. Tablonun $i$. satırı, $i$ numaralı fiziksel çerçevede hangi prosesin (`pid`) hangi sanal sayfasının (`p`) durduğunu (`<pid, p>`) gösterir. CPU `<pid, p, d>` ürettiğinde tabloda `<pid, p>` aranır; $i$. indiste bulunduğunda fiziksel adres `<i, d>` olur. Tablo boyutunu çok küçültür ancak tabloyu baştan sona aramak zaman aldığı için hash tablosu veya TLB ile hızlandırılır.
- **İstek Üzerine Sayfalama (Demand Paging) ve Başarım Hesabı (ekrandan, 00:50:00, 00:56:45).**
  - Proses çalışırken `valid-invalid` biti `i` olan bir sayfaya erişildiğinde donanım işletim sistemine **sayfa hatası tuzağı (`page fault trap`)** üretir. İşletim sistemi adresin geçerli olup olmadığını kontrol eder, geçerliyse boş bir çerçeve bulur, diskin sanal bellek (backing store) alanından istenen sayfayı boş çerçeveye okur, sayfa tablosunda ilgili satırı `v` olarak günceller ve kesilen komutu yeniden başlatır (`restart instruction`). Hiçbir sayfa yüklemeden başlatılan prosese **Pure Demand Paging** denir.
  - **Etkin Erişim Süresi Sayısal Örneği (ekrandan, 00:56:45):**
    - Bellek erişim süresi ($\text{ma}$) $= 200\text{ ns}$, ortalama sayfa hatası servis süresi $= 8\text{ ms} = 8{,}000{,}000\text{ ns}$.
    - Sayfa hatası olasılığı $p$ ($0 \le p \le 1$) iken:
      $$\text{EAT} = (1 - p) \times 200 + p \times 8{,}000{,}000 = 200 + 7{,}999{,}800 \times p\text{ (ns)}$$
    - Her $1{,}000$ erişimde $1$ sayfa hatası olursa ($p = 0.001$): $\text{EAT} = 200 + 7{,}999.8 \approx 8{,}200\text{ ns} = 8.2\text{ }\mu\text{s}$ olur ($\frac{8200}{200} = 41 \approx \mathbf{40\text{ kat yavaşlama}}$).
    - Başarım kaybının (performance degradation) $\%10$'dan az olması ($\text{EAT} < 220\text{ ns}$) istenirse:
      $$200 + 7{,}999{,}800 \times p < 220 \implies p < \frac{20}{7{,}999{,}800} \approx 0.0000025$$
      Yani her **$400{,}000$ bellek erişiminde en fazla 1 sayfa hatası** oluşmalıdır.
- **Sayfa Değiştirme Algoritmaları Karşılaştırması (ekrandan, 01:30:00, 01:34:15, 01:35:30).**
  - 3 çerçeveli bir proseste `7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2, 1, 2, 0, 1, 7, 0, 1` referans dizgesi (20 referans) çalıştırıldığında:
    - **FIFO (First-In-First-Out):** Belleğe ilk giren sayfayı çıkarır. İlk üç referansta (`7, 0, 1`) 3 hata oluşur; `2` geldiğinde en eski olan `7` çıkarılır (`[2, 0, 1]`), `0` bellekte olduğu için hata olmaz, `3` geldiğinde `0` çıkarılır (`[2, 3, 1]`), `0` geldiğinde `1` çıkarılır (`[2, 3, 0]`), `4` geldiğinde `2` çıkarılır (`[4, 3, 0]`)... Toplam **15 sayfa hatası** oluşur.
      - **Belady Anomalisi (`Belady's Anomaly`):** Genel beklenti prosese verilen çerçeve sayısı arttıkça sayfa hatası sayısının azalması veya sabit kalmasıdır; ancak FIFO algoritmasında bazı referans dizgelerinde (örneğin `1, 2, 3, 4, 1, 2, 5, 1, 2, 3, 4, 5`) 3 çerçeve verildiğinde **9 sayfa hatası** oluşurken, 4 çerçeve verildiğinde **10 sayfa hatası** oluşur! Çerçeve sayısı artırıldığında sayfa hatası oranının artması durumuna **Belady Anomalisi** denir.
      - **Ders sonrası not:** Hoca derste grafik üzerinde çerçeve sayısı ile sayfa hatası ilişkisini anlatırken önce *"Bir prosese atanan frame sayısının çok fazla olması illaki page fault hatasını azaltacak, minimize edecek değil, bir yerden sonra sabit bırakıyor. Buna Belady'nin anomalisi demişler"* (01:28:02) demiş, birkaç dakika sonra slayt 9.32 ve 9.33'te (`01:33:20`) *"Üç olduğunda biraz azalıyormuş, dört olduğunda artıyormuş. Her proses için illaki arttırdığında azalacağı anlamına gelmiyor"* diyerek doğru tanımı vermiştir. Büyük olasılıkla literatürdeki kesin tanımıyla **Belady Anomalisi**, çerçeve sayısı artırıldığında sayfa hatalarının sabit kalması değil, **artması** durumudur.
    - **Optimal (OPT) Algoritma (ekrandan, 01:34:15):** Gelecekte en uzun süre kullanılmayacak sayfayı kurban seçer. `[7, 0, 1]` bellekteyken `2` geldiğinde ileriye bakılır (`0` hemen bir sonraki adımda, `1` ileride, `7` ise en sonda kullanılacaktır); `7` çıkarılıp `[2, 0, 1]` yapılır. `3` geldiğinde `1` çıkarılıp `[2, 0, 3]` yapılır. Toplam **9 sayfa hatası** ile olabilecek en düşük hata sayısını verir.
    - **LRU (Least Recently Used) Algoritması (ekrandan, 01:35:30):** Geleceği bilemediği için geçmişe bakar ve en uzun süredir kullanılmamış (en eski erişilmiş) sayfayı çıkarır. `[7, 0, 1]` sonrası `2` geldiğinde en eski kullanılan `7` çıkarılır (`[2, 0, 1]`). Ardından `0` kullanılır (taze kalır). `3` geldiğinde geriye doğru bakıldığında en son `0`, ondan önce `2`, en eski olarak da `1` kullanıldığı için (FIFO'daki gibi `0` değil) **`1` çıkarılır** (`[2, 0, 3]`). Toplam **12 sayfa hatası** üretir (FIFO'nun 15'inden iyi, OPT'nin 9'undan fazladır).
- **Disk Zamanlama Algoritmaları (ekrandan, 02:15:00).**
  - `0..199` numaralı 200 silindirli bir sabit diskte okuma/yazma kafası başlangıçta **`53`** numaralı silindirdedir ve istek kuyruğu sırasıyla **`98, 183, 37, 122, 14, 124, 65, 67`** şeklindedir:
    - **FCFS (First-Come, First-Served):** İstekleri geliş sırasıyla karşılar: `53 -> 98 -> 183 -> 37 -> 122 -> 14 -> 124 -> 65 -> 67`. Toplam kafa hareketi: $|98-53| + |183-98| + |37-183| + |122-37| + |14-122| + |124-14| + |65-124| + |67-65| = 45 + 85 + 146 + 85 + 108 + 110 + 59 + 2 =$ **`640 silindir`**.
    - **SSTF (Shortest Seek Time First):** Her adımda mevcut kafa konumuna en yakın silindire gider: `53 -> 65 -> 67 -> 37 -> 14 -> 98 -> 122 -> 124 -> 183`. Toplam kafa hareketi: $(67-53) + (67-14) + (183-14) = 14 + 53 + 169 =$ **`236 silindir`**. Ancak uzak silindirlerdeki isteklerde **açlık (`starvation`)** oluşturabilir.
    - **SCAN (Asansör Algoritması):** Kafa önce `0` ucuna doğru hareket ederek yol üzerindeki istekleri toplar (`53 -> 37 -> 14 -> 0`), `0` ucuna çarpıp yön değiştirerek yukarı doğru kalan tüm istekleri toplar (`0 -> 65 -> 67 -> 98 -> 122 -> 124 -> 183`). Toplam kafa hareketi: $53 + 183 =$ **`236 silindir`**.
    - **C-SCAN ve C-LOOK:** **C-SCAN**, yukarı doğru (`53 -> 65 -> 67 -> 98 -> 122 -> 124 -> 183 -> 199`) taradıktan sonra hiçbir isteğe bakmadan doğrudan `0` noktasına döner ve `0 -> 14 -> 37` şeklinde tarayarak daha dengeli bekleme süresi sağlar. **C-LOOK** ise diskin fiziksel sonuna (`199` ve `0`) kadar gitmek yerine yalnızca o yöndeki son isteğe (`183`) kadar gidip oradan en küçük isteğe (`14`) döner.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
