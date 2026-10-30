# Veri Yapıları ve Algoritmalar Ders Kayıtları & Çalışma Özetleri

> **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.

### 📋 Genel Bilgiler
* **Ders:** Veri Yapıları ve Algoritmalar (BLM2512)
* **Hoca:** Dr. Göksel Biricik
* **Dönem:** Bahar
* **Akademik Yıl:** 2022-2023
* **Şube:** BLM2512 - 3

Bu dizin, ilgili ders kayıtlarının altyazı özetlerini, çalışma notlarını ve PDF kaynaklarını içermektedir.

## 📚 Ders Müfredatı ve Belge Dizini

Aşağıdaki tabloda her bir dersin konusu, kaynak markdown dosyası ve doğrudan indirilebilir PDF formatındaki derlenmiş halleri listelenmiştir. Ders numaraları, kayıt arşivindeki ders kaydı sıra numaralarıdır (hafta numarası değildir).

| Ders No | Ders İçeriği / Konu Başlıkları | Kaynak Notlar (Markdown) | Çalışma Dosyası (PDF) |
| :---: | :--- | :---: | :---: |
| **Ders 1** | Derse Giriş, Algoritma, Veri Yapısı ve Akış Diyagramı Kuralları | [Özet](altyazi_ozetleri/ders_1_ozet.md) | [PDF (İndir)](ders_1_ozet.pdf) |
| **Ders 3** | Bağlantı Problemi, Öklid Algoritması ve Algoritma Analizinin Temelleri | [Özet](altyazi_ozetleri/ders_3_ozet.md) | [PDF (İndir)](ders_3_ozet.pdf) |
| **Ders 5** | Özyinelemeli Algoritmalar ve Yineleme Denklemleriyle Analiz | [Özet](altyazi_ozetleri/ders_5_ozet.md) | [PDF (İndir)](ders_5_ozet.pdf) |
| **Ders 7** | Bağlantılı Listeler: Ekleme, Silme, Çift Yönlü ve Dairesel Listeler | [Özet](altyazi_ozetleri/ders_7_ozet.md) | [PDF (İndir)](ders_7_ozet.pdf) |
| **Ders 9** | Yığın ve Kuyruk Veri Yapıları, Infix-Postfix Dönüşümü | [Özet](altyazi_ozetleri/ders_9_ozet.md) | [PDF (İndir)](ders_9_ozet.pdf) |
| **Ders 11** | Ağaçlar, İkili Ağaç Gezintileri ve İkili Arama Ağacı | [Özet](altyazi_ozetleri/ders_11_ozet.md) | [PDF (İndir)](ders_11_ozet.pdf) |
| **Ders 13** | Heap Veri Yapısı, Heap Oluşturma ve Heap Sort | [Özet](altyazi_ozetleri/ders_13_ozet.md) | [PDF (İndir)](ders_13_ozet.pdf) |
| **Ders 15** | Öncelikli Kuyruklar, Heap Soruları ve Huffman Kodlama | [Özet](altyazi_ozetleri/ders_15_ozet.md) | [PDF (İndir)](ders_15_ozet.pdf) |
| **Ders 21** | Vize Sorularının Çözümü, Graf Temelleri ve Asgari Tarama Ağacı | [Özet](altyazi_ozetleri/ders_21_ozet.md) | [PDF (İndir)](ders_21_ozet.pdf) |
| **Ders 23** | Minimum Kapsayan Ağaç: Kruskal ve Prim, Dijkstra ile En Kısa Yol | [Özet](altyazi_ozetleri/ders_23_ozet.md) | [PDF (İndir)](ders_23_ozet.pdf) |
| **Ders 25** | Alt Dizgi Arama: Kaba Kuvvet, Horspool, Boyer-Moore ve Rabin-Karp | [Özet](altyazi_ozetleri/ders_25_ozet.md) | [PDF (İndir)](ders_25_ozet.pdf) |
| **Ders 26** | Karşılaştırmasız Sıralama: Counting Sort, Radix Sort ve Sıralama Algoritmalarının Karşılaştırılması | [Özet](altyazi_ozetleri/ders_26_ozet.md) | [PDF (İndir)](ders_26_ozet.pdf) |

> [!NOTE]
> Arşivdeki ara numaralı kayıtlar bulunmamaktadır. 24 Nisan 2023 haftası vize haftası, 1 Mayıs 2023 resmî tatildir.

## 🎯 Derslerin Detaylı Özetleri ve Kazanımları

### 🔹 Ders 1: Derse Giriş, Algoritma, Veri Yapısı ve Akış Diyagramı Kuralları
* **Genel Konular:**
  - Deprem sonrası online başlayan dönemin işleyişi ve ders düzeni.
  - Değerlendirme ölçütleri, kopya kuralları, ödev teslim ve puanlama kuralları.
  - Kaynak kitaplar ve 14 haftalık ders planı.
  - Algoritma kelimesinin kökeni: El-Harezmi.
  - Algoritma ve algoritma tasarımı kavramları, günlük hayattan örnekler.
  - Bir algoritmanın taşıması gereken özellikler.
  - Genel algoritmik problemler: sıralama (sorting), arama (searching), metin işleme, graf problemleri, kombinatoryal, geometrik ve nümerik problemler.
* **Hocanın Vurgusu:**
  - Değerlendirme ölçütleri dönem boyunca değişebilir.
    - Hoca bunu birçok kez tekrarladı.
  - Dersler online olduğu için kısa ve yoğun tutulacak: yaklaşık 40-45 dakikalık bölümler ve 10 dakikalık aralar.
  - Kopya: kodlar çapraz taranıyor.
    - Değişken adını, döngü yapısını değiştirmek ya da kontrolleri tersten yazmak benzerliği gizlemiyor.
  - Bütün ödev, proje ve sınavlarda yalnız ANSI C kullanılır.
    - C++ ve C# kabul edilmez.
  - Ödevde istenen işlevi hazır kütüphane fonksiyonuyla değil, kendiniz yazmalısınız.
    - Örneğin alt dizgi arama ödevinde hazır fonksiyon çağrılmaz.
* **Detaylı Açıklamalar:** Dizi toplamı örneğinin izlenmesi ($n = 3$, dizi = 3, 5, 8):

### 🔹 Ders 3: Bağlantı Problemi, Öklid Algoritması ve Algoritma Analizinin Temelleri
* **Genel Konular:**
  - Grupların yeniden dağıtılması ve ödev takvimi.
  - Bağlantı problemi (connectivity problem) ve dizi tabanlı, küme kimliği tutan çözüm (quick-find).
  - Neden verimli algoritma tasarlarız: 600 bin kelimede sıralı arama ile ikili arama karşılaştırması.
  - Algoritma tasarım teknikleri: kaba kuvvet (brute force), açgözlü (greedy), böl ve yönet (divide and conquer), azalt ve yönet (decrease and conquer), dönüştür ve yönet (transform and conquer), dinamik programlama (dynamic programming), yinelemeli iyileştirme (iterative improvement), geri izleme (backtracking).
  - Ortak bölenlerin en büyüğü (OBEB, greatest common divisor): asal çarpan yöntemi ve Öklid algoritması.
  - Eratosthenes Kalburu'nun tekrarı ve 0/1 dizisiyle alternatif akış.
  - Algoritma analizi: deneysel (empirical) ve teorik analiz.
* **Hocanın Vurgusu:**
  - Algoritma tasarımında doğru veri yapısını seçmek çözümü çok basitleştirir.
    - Bağlantı problemi tek bir diziyle çözülebilir.
  - Problem çok zorsa, işe yarar bilgiyi veren daha basit bir probleme dönüştürülebilir.
    - Örneğin "hangi yolla bağlı?" yerine yalnız "bağlı mı?" sorusu cevaplanır.
  - Coding challenge sitelerindeki problemleri önce kendiniz çözün, sonra hazır çözümlerle karşılaştırın.
  - Bir algoritmanın her adımı açık ve tanımlı olmalı. "Asal çarpanlarını bul" diyen ama nasıl bulunacağını söylemeyen bir yöntem algoritma sayılmaz.
  - Çalışma süresini kronometreyle ölçmek, algoritmayı değil gerçekleştirmeyi (implementation) karşılaştırır.
    - Bu yüzden teorik analiz tercih edilir.
* **Detaylı Açıklamalar:** for (i = 0; i < n; i++) /* n * n: O(n^2) */ for (j = 0; j < n; j++) ...

### 🔹 Ders 5: Özyinelemeli Algoritmalar ve Yineleme Denklemleriyle Analiz
* **Genel Konular:**
  - Özyineleme (recursion) kavramı ve özyinelemeli algoritma tasarımı.
  - Özyinelemeli bir yapının üç şartı.
  - Hatalı özyineleme örneği: kendini koşulsuz çağıran `main`.
  - Üs alma (power) örneği ve çağrıların izlenmesi.
  - Özyinelemenin artıları ve eksileri: kod kolaylığına karşı zaman ve bellek maliyeti, fonksiyon çağrı yığını (function call stack).
  - `mystery` fonksiyonu: basamakları tekrar tekrar toplama.
  - Hanoi Kuleleri (Tower of Hanoi) problemi.
* **Hocanın Vurgusu:**
  - Özyineleme kodlamayı çok kolaylaştırır ve kısaltır.
    - Ama genellikle zaman karmaşıklığını ve bellek ihtiyacını artırır.
  - Her özyinelemeli algoritmada kendini çağırmayan bir temel durum (base case) olmalıdır.
    - Yoksa çağrılar sonsuza kadar sürer.
  - Her özyinelemeli çağrı, problemi küçültmeli ve temel duruma yaklaştırmalıdır.
  - Özyinelemeli çağrılar, her çağrının nereden yapıldığını ve parametrelerini saklamak için ek bellek ister.
    - Çok derin özyineleme stack overflow'a yol açar.
  - Özyinelemeli bir fonksiyon kendini birden fazla kez ve farklı parametrelerle çağırabilir.
    - Örneğin Fibonacci $n-1$ ve $n-2$ ile çağırır.
* **Detaylı Açıklamalar:** printf("%d", power(5, 3)); ```

### 🔹 Ders 7: Bağlantılı Listeler: Ekleme, Silme, Çift Yönlü ve Dairesel Listeler
* **Genel Konular:**
  - Dizilerin (array) kısa tekrarı: indisleme türleri, statik ve dinamik diziler, ekleme/silme maliyeti.
  - Bağlantılı liste (linked list) kavramı: düğüm (node), veri ve `next` işaretçisi, `head` işaretçisi.
  - C'de düğüm tanımı (`typedef struct ...`), listeyi `for` döngüsüyle gezme.
  - Listeye eleman ekleme: başa, araya, sona; sıralı listeye ekleme.
  - İki dizi (`A` veri dizisi, `L` link dizisi) ile linked list gösterimi ve akış diyagramları.
  - Listeden eleman silme ve `free` ile belleği geri verme.
  - Linked list ile insertion sort.
* **Hocanın Vurgusu:**
  - C'de dizi sınırlarını ve indisleri kontrol etmek programcının sorumluluğudur.
    - Dikkatsiz kod başka bellek alanlarını okuyup yazabilir.
  - Sıralı diziye araya eleman eklemek ya da aradan silmek kaydırma gerektirir.
    - En kötü durumda $O(n)$ işlem yapılır.
  - Linked list'te yer bulunduktan sonra ekleme ve silme sabit sayıda işlemle, yani $O(1)$ ile yapılır.
  - Listeye erişmek için yalnız ilk düğümün adresini (`head`) bilmek yeterlidir.
    - Son düğümün `next` alanı `NULL` gösterir.
  - Araya eklemede işaretçi güncelleme sırası önemlidir.
    - Önce yeni düğümün `next`'i bağlanır, sonra öncekinin `next`'i yeni düğüme çevrilir. Sıra ters olursa listenin geri kalanı kaybedilir.
* **Detaylı Açıklamalar:** Dizinin en önemli özelliği, her elemana indisle sabit zamanda ($O(1)$) erişilmesidir. Vektör, matris, string, stack, queue, heap gibi pek çok yapı dizinin üzerine kurulur.

### 🔹 Ders 9: Yığın ve Kuyruk Veri Yapıları, Infix-Postfix Dönüşümü
* **Genel Konular:**
  - Yığın (stack) veri yapısı: LIFO düzeni, `push`, `pop`, `peek`/`top`, `isEmpty`, `isFull`.
  - Stack overflow ve stack underflow durumları.
  - Yığının kullanım alanları: fonksiyon çağrı yığını, ifade ayrıştırma, parantez kontrolü, ters çevirme, Hanoi Kuleleri, N-vezir.
  - Yığının dizi ve bağlantılı liste (linked list) ile gerçeklenmesi.
  - Örnekler: string'i ters çevirme, palindrom kontrolü, parantez dengesi kontrolü.
  - Infix ifadeyi postfix'e çevirme (parantezleme yöntemi ve yığın yöntemi) ve postfix ifadeyi hesaplama.
  - Kuyruk (queue) veri yapısı: FIFO düzeni, `enqueue`, `dequeue`.
* **Hocanın Vurgusu:**
  - "Yığın" kelimesi Türkçede bazen heap için de kullanılıyor.
    - Karışmasın diye derste "stack" adı tercih edildi.
  - Yığında yalnız en üstteki elemana erişilir.
    - Ortadaki bir elemana doğrudan erişilemez.
  - Temel işlemler `push` ve `pop`'tur.
    - `isEmpty` ve `isFull` bunların güvenli çalışması için yardımcı fonksiyonlardır.
  - `peek` nadiren gerekir.
    - Yığındaki asıl amaç ekleme-çıkarma düzenini korumaktır.
  - Dinamik yığın teoride dolmaz.
    - Ancak fiziksel bellek sınırlı olduğu için pratikte stack overflow yaşanabilir.
* **Detaylı Açıklamalar:** Masaya üst üste konan kitaplar gibi düşünülür. Yalnız en üstteki kitap alınabilir. İlk konan kitap en son alınır.

### 🔹 Ders 11: Ağaçlar, İkili Ağaç Gezintileri ve İkili Arama Ağacı
* **Genel Konular:**
  - 1. ödevin video anlatımı hakkında bilgilendirme.
  - Ağaç (tree) veri yapısının tanımı ve günlük hayattan örnekleri.
  - Ağaç terminolojisi: düğüm, kök, ebeveyn, çocuk, yaprak, kardeş, derece, yükseklik, derinlik, seviye, alt ağaç.
  - Ağacın dizi ile gösterimi ve bellek israfı.
  - Ağacın bağlantılı liste (linked list) ile gösterimi.
  - İkili ağaç (binary tree) ve özel türleri: full, complete, perfect, balanced, dejenere.
  - İkili ağaca eleman ekleme ve silme.
* **Hocanın Vurgusu:**
  - Ödev videosunda önce öğrenci kendini tanıtmalı, sonra çözüm yöntemini ve alt problemleri nasıl çözdüğünü anlatmalı. "Kod çalışıyor" demek yeterli değil.
  - Talimatta 5-10 dakika yazıyor.
    - Hocaya göre iyi hazırlanmış bir anlatım 3 dakikaya sığar.
  - Video, değerlendirmede neyin neden yapıldığını görmeyi kolaylaştırıyor.
    - Teknik bir sorun (bulanık ya da boğuk ses) yoksa videoya geri dönüş yapılmaz, doğrudan puanlanır.
  - Ağaçta kapalı çevrim (cycle) olamaz.
    - Kökten her düğüme tek bir yol vardır.
  - Ağaçlar kök yukarıda, yapraklar aşağıda olacak şekilde ters çizilir.
* **Detaylı Açıklamalar:** İki tanım verildi:

### 🔹 Ders 13: Heap Veri Yapısı, Heap Oluşturma ve Heap Sort
* **Genel Konular:**
  - Yığın ağacı (heap) veri yapısının tanımı. Dönemin 7. haftası.
  - Complete binary tree hatırlatması.
  - Max heap ve min heap koşulları.
  - Heap'in dizi ile gösterimi: çocuk ve ebeveyn indisleri.
  - Heap'in yüksekliği ($\lg n$).
  - En büyük elemanı okuma ($O(1)$).
  - Heap oluşturma (build max heap): aşağıdan yukarı (bottom-up) yaklaşım ve `MAX-HEAPIFY`.
* **Hocanın Vurgusu:**
  - Heap iki koşulu aynı anda sağlar:
    - Complete binary tree olmalıdır.
  - Heap yalnız tek bir şeyi garanti eder: en büyük (max heap) ya da en küçük (min heap) eleman köktedir.
  - Heap bir ikili arama ağacı (BST) değildir.
    - Sol alt ağaçta küçükler, sağda büyükler diye bir kural yoktur. Kardeşler arasında sıra yoktur.
  - Veri yapısı olan heap, Java gibi dillerdeki bellek alanı "heap space" ile aynı şey değildir.
  - Türkçede "yığın/yığıt" hem stack hem heap için kullanılabildiği için derste İngilizce adlar tercih ediliyor.
* **Detaylı Açıklamalar:** Derste üç ağaç incelendi (dizi gösterimiyle):

### 🔹 Ders 15: Öncelikli Kuyruklar, Heap Soruları ve Huffman Kodlama
* **Genel Konular:**
  - Vize sınavının biçimi ve ödevlerle ilgili duyurular.
  - Öncelikli kuyruk (priority queue): tanım, max ve min öncelikli kuyruk.
  - Öncelikli kuyruğun gerçek hayattaki kullanımları: işlem zamanlayıcı (process scheduler), olay güdümlü benzetim (event-driven simulation).
  - Heap işlemlerinin tekrarı: `maximum`, `extract_max`, `increase_key`, `decrease_key`, `insert`.
  - Max öncelikli kuyruğun C kodu.
  - Heap soruları: bir dizi heap mi, $k$'ıncı en küçük eleman, min heap'i max heap'e çevirme.
  - Huffman ağacı ile kayıpsız veri sıkıştırma.
* **Hocanın Vurgusu:**
  - Öncelikli kuyruk FIFO değildir.
    - Elemanlar bir anahtar (öncelik) değerine göre sıralanır. Banka sıra makinesi ya da acil servisteki triyaj gibi.
  - Öncelikli kuyruk heap ile gerçekleştirilir.
    - En öncelikli eleman her zaman köktedir ($O(1)$). Ekleme ve çıkarma $O(\log n)$'dir.
  - Yeni eleman eklenirken önce $-\infty$ yazılır.
    - Böylece işlem yarıda kesilse bile heap düzeni bozulmaz. Sonra `increase_key` ile gerçek değere çıkarılır.
  - Sınavda bir problemin "düz" çözümü genelde herkesin aklına gelir.
    - Asıl ölçülen, veri yapısının gücünü kullanan daha iyi çözümü görebilmektir.
  - Bir problem için en iyi veri yapısını seçmenin hazır kuralı yoktur.
    - Problemin doğasına bakıp hangi işlemin sık yapılacağını düşünmek gerekir. Sonra veri yapısının varyantlarıyla daha da iyileştirilebilir.
* **Detaylı Açıklamalar:** void swap(int *a, int *b) { int t = *a; *a = *b; *b = t; }

### 🔹 Ders 21: Vize Sorularının Çözümü, Graf Temelleri ve Asgari Tarama Ağacı
* **Genel Konular:**
  - Vize sınavının birinci oturumundaki soruların çözümü.
  - Graf (çizge) veri yapısı: tanım, düğüm (vertex) ve kenar (edge).
  - Grafların kullanım alanları.
  - Temel kavramlar: self-loop, paralel kenar, multigraf, basit graf, yol (path), çevrim (cycle), bağlantılı bileşen (connected component).
  - Graf türleri: yönlü/yönsüz, ağırlıklı/ağırlıksız.
  - Çevrimsiz (acyclic) graf ve ağaç ilişkisi.
  - Seyrek (sparse) ve yoğun (dense) graf. İki parçalı (bipartite) graf.
* **Hocanın Vurgusu:**
  - Sınav sorularında "şeytan ayrıntıda gizlidir". "En kötü durum", "tamamı aynı sayıdan oluşan", "ilk büyük değer" gibi ifadeler dikkatle okunmalıdır.
  - Soruda istenenden fazlasını yazmak puan getirmez.
    - Fazla sayı yazmak ya da yanlış ek bilgi vermek puan kaybettirebilir.
  - Graf algoritmalarının karmaşıklığı $n$ ile değil, düğüm ve kenar sayısı ($V$ ve $E$) ile ifade edilir.
  - Bir grafın düzlemde nasıl çizildiği önemli değildir.
    - Aynı düğümler ve aynı bağlantılar varsa iki çizim aynı grafı gösterir.
  - Ağaçlar grafların özel bir hâlidir.
* **Detaylı Açıklamalar:** Soruların sırası öğrenciden öğrenciye değiştiği için aşağıdaki numaralar derste anlatılan sırayı gösterir.

### 🔹 Ders 23: Minimum Kapsayan Ağaç: Kruskal ve Prim, Dijkstra ile En Kısa Yol
* **Genel Konular:**
  - En küçük kapsayan ağaç (minimum spanning tree, MST) problemi: köy ve muhtar örneği.
  - Jenerik MST algoritması: güvenli kenar (safe edge), kesim (cut) ve hafif kenar (light edge).
  - Kruskal algoritması: ayrık kümelerle (disjoint set) çalışma, kitaptaki 9 düğümlü örnek, karmaşıklık.
  - Prim algoritması: öncelikli kuyrukla (priority queue) tek bir ağacı büyütme, aynı örnek, karmaşıklık.
  - Tek kaynaklı en kısa yol (single source shortest path) problemi ve kullanım alanları.
  - Dijkstra algoritması: gevşetme (relax) işlemi, üç örnek (iki yönlü graf, bir yönsüz graf).
  - Ödevdeki girdi okuma şekli hakkında açıklama.
* **Hocanın Vurgusu:**
  - MST'de $V$ düğüm $V-1$ kenarla bağlanır.
    - Ağaçta döngü (cycle) olmamalı.
  - Bir graf için birden fazla MST olabilir.
    - Toplam ağırlıkları aynıdır. Eşit ağırlıklı kenarlarda seçim sırası değişirse farklı bir MST çıkar.
  - Güvenli kenar: iki farklı bileşeni en ucuz şekilde bağlayan kenar.
    - Aynı bileşendeki iki düğümü bağlayan kenar güvenli değildir, "boşuna masraftır".
  - Kruskal ile Prim'in çalışma mantığı terstir:
    - Kruskal $V$ ayrı bileşenle başlar, hafif kenarlarla bileşenleri birleştirir.
  - Karmaşıklık açısından ikisi arasında "aman aman bir kazanç yok": ikisi de $O(E \log V)$.
* **Detaylı Açıklamalar:** RELAX(u, v, w) eğer d[v] > d[u] + w(u, v) d[v] = d[u] + w(u, v) π[v] = u ```

### 🔹 Ders 25: Alt Dizgi Arama: Kaba Kuvvet, Horspool, Boyer-Moore ve Rabin-Karp
* **Genel Konular:**
  - Alt dizgi arama (substring search) problemi ve kullanım alanları.
  - Kaba kuvvet (brute force) arama ve geri dönüş alanlı (backup) sürümü.
  - Horspool algoritması: kötü eşleşme tablosu (bad match table, shift table), BARBER ve TOOTH örnekleri.
  - Boyer-Moore algoritması: kötü karakter ve iyi son ek (good suffix) kaydırmaları, BAOBAB örneği.
  - Rabin-Karp algoritması: özet (hash) ile arama ve kayan özet (rolling hash) hesabı.
  - Algoritmaların karşılaştırma tablosu.
  - Final sınavı ve proje duyurusu.
* **Hocanın Vurgusu:**
  - Problemde genellikle metin uzunluğu $n$, aranan desen (pattern) uzunluğu $m$'den çok büyüktür ($n \gg m$).
  - Kaba kuvvette eşleşme olmayınca desen yalnız 1 karakter kaydırılır.
    - Daha fazla kaydırılırsa bir eşleşme kaçırılabilir.
  - Akan veride (stream) kaba kuvvet geri dönmek zorunda kalır.
    - Bunun için $m$ karakterlik bir geri dönüş alanı (backup) gerekir.
  - Horspool, Boyer-Moore'un basitleştirilmiş hâlidir.
    - İnternette ikisi sık sık karıştırılır:
  - Horspool desenin son karakterinden başlayarak sağdan sola karşılaştırır.
    - Kaydırma miktarı her zaman desenin hizasındaki son metin karakterine göre tablodan okunur.
* **Detaylı Açıklamalar:** int horspool(char *text, char *pat, int table[]) { int n = strlen(text), m = strlen(pat); int i = m - 1; while (i <= n - 1) { int k = 0; while (k <= m - 1 && pat[m - 1 - k] == text[i - k]) k++; if (k == m) return i - m + 1; // eşleşme i += table[(unsigned char)text[i]]; } return -1; } ```

### 🔹 Ders 26: Karşılaştırmasız Sıralama: Counting Sort, Radix Sort ve Sıralama Algoritmalarının Karşılaştırılması
* **Genel Konular:**
  - Karşılaştırma yapmadan sıralama: sayarak sıralama (counting sort).
  - Karşılaştırmalı sayma (comparison counting sort).
  - Dağılım sayımı (distribution counting sort).
  - Basamak sıralama (radix sort): LSD (least significant digit) ve MSD (most significant digit).
  - Sıralama algoritmalarını karşılaştırma ölçütleri: performans, ek bellek (in-place / out-of-place), kararlılık (stable).
  - Algoritma tasarım yaklaşımlarına göre sıralama yöntemleri ve karşılaştırma tablosu.
  - Dönemin son dersi: proje, mazeret sınavı ve final duyuruları.
* **Hocanın Vurgusu:**
  - Counting sort hiçbir anahtar karşılaştırması (`if`) yapmadan, yalnız sayarak sıralar.
    - Karşılaştırmanın pahalı olduğu bir mimaride işe yarar.
  - Counting sort doğrusal zamanda çalışır ama bedeli ek alandır: sayaç dizisi ve girdi kadar bir çıktı dizisi gerekir.
    - Dizi yerinde sıralanamaz.
  - Counting sort, farklı değer sayısı az, tekrar sayısı çok olan verilerde idealdir.
    - Örnek: ilkokul öğrencilerini yaşa göre sıralamak (5-11 arası değerler, milyonlarca tekrar).
  - Radix sort her basamakta counting sort yapar.
    - Counting sort kararlı olduğu için önceki basamaklardaki sıra korunur.
  - LSD, sabit uzunluklu anahtarlar için biçilmiş kaftandır: IBAN, T.C. kimlik numarası, GUID, veritabanı indeksleri.

**Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
