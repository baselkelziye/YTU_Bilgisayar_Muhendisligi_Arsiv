# Veri Yapıları ve Algoritmalar Ders Kayıtları & Çalışma Özetleri

> **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.

### 📋 Genel Bilgiler
* **Ders:** Veri Yapıları ve Algoritmalar (BLM2512)
* **Hoca:** Doç. Dr. M. Amaç Güvensan
* **Dönem:** Bahar
* **Akademik Yıl:** 2022-2023
* **Şube:** BLM2512 - 2

Bu dizin, ilgili ders kayıtlarının altyazı özetlerini, çalışma notlarını ve PDF kaynaklarını içermektedir.

## 📚 Ders Müfredatı ve Belge Dizini

Aşağıdaki tabloda her bir dersin konusu, kaynak markdown dosyası ve doğrudan indirilebilir PDF formatındaki derlenmiş halleri listelenmiştir. Ders numaraları, kayıt arşivindeki ders kaydı sıra numaralarıdır (hafta numarası değildir).

| Ders No | Ders İçeriği / Konu Başlıkları | Kaynak Notlar (Markdown) | Çalışma Dosyası (PDF) |
| :---: | :--- | :---: | :---: |
| **Ders 1** | Dersin Tanıtımı, Akış Diyagramları ve Temel Sıralama Algoritmaları | [Özet](altyazi_ozetleri/ders_1_ozet.md) | [PDF (İndir)](ders_1_ozet.pdf) |
| **Ders 3** | Insertion Sort, Asal Sayı Bulma, İkili Arama ve Algoritma Analizine Giriş | [Özet](altyazi_ozetleri/ders_3_ozet.md) | [PDF (İndir)](ders_3_ozet.pdf) |
| **Ders 5** | Özyinelemeli Problemler ve Bağlı Listeler | [Özet](altyazi_ozetleri/ders_5_ozet.md) | [PDF (İndir)](ders_5_ozet.pdf) |
| **Ders 7** | Bağlı Listenin Değerlendirmesi, Yığın ve Aritmetik İfade Dönüşümleri | [Özet](altyazi_ozetleri/ders_7_ozet.md) | [PDF (İndir)](ders_7_ozet.pdf) |
| **Ders 9** | Yığın Uygulamaları, Infix-Prefix Dönüşümü ve Kuyruk Yapıları | [Özet](altyazi_ozetleri/ders_9_ozet.md) | [PDF (İndir)](ders_9_ozet.pdf) |
| **Ders 11** | Kuyruk Türleri, Ağaçlar, Ağaçta Gezinme ve İkili Arama Ağacı | [Özet](altyazi_ozetleri/ders_11_ozet.md) | [PDF (İndir)](ders_11_ozet.pdf) |
| **Ders 13** | Heap Ağaçları, Heapify, Heap'e Ekleme-Silme ve Heap Sort | [Özet](altyazi_ozetleri/ders_13_ozet.md) | [PDF (İndir)](ders_13_ozet.pdf) |
| **Ders 15** | Öncelikli Kuyruklar ve Heap Alıştırmaları | [Özet](altyazi_ozetleri/ders_15_ozet.md) | [PDF (İndir)](ders_15_ozet.pdf) |
| **Ders 20** | Graflara Giriş, Kapsayan Ağaç ve Kruskal Algoritması | [Özet](altyazi_ozetleri/ders_20_ozet.md) | [PDF (İndir)](ders_20_ozet.pdf) |
| **Ders 22** | Vize Sorularının Çözümü, Prim ve Dijkstra Algoritmaları | [Özet](altyazi_ozetleri/ders_22_ozet.md) | [PDF (İndir)](ders_22_ozet.pdf) |
| **Ders 24** | Metin Arama: Kaba Kuvvet, Boyer-Moore ve Rabin-Karp | [Özet](altyazi_ozetleri/ders_24_ozet.md) | [PDF (İndir)](ders_24_ozet.pdf) |
| **Ders 26** | Sıralama Algoritmalarının Karşılaştırılması, Counting Sort ve Radix Sort | [Özet](altyazi_ozetleri/ders_26_ozet.md) | [PDF (İndir)](ders_26_ozet.pdf) |

> [!NOTE]
> Arşivdeki ara numaralı kayıtlar bulunmamaktadır. 24 Nisan 2023 haftası vize haftası, 1 Mayıs 2023 resmî tatildir.

## 🎯 Derslerin Detaylı Özetleri ve Kazanımları

### 🔹 Ders 1: Dersin Tanıtımı, Akış Diyagramları ve Temel Sıralama Algoritmaları
* **Genel Konular:**
  - Deprem sonrası dönemin online başlaması, bölümün deprem formu ve dersin işleyiş düzeni.
  - Dersin haftalık programı, değerlendirme ölçütleri, kaynak kitaplar ve ödev kuralları.
  - Algoritma kavramı ve iyi bir algoritmanın özellikleri: doğruluk (correctness), anlaşılabilirlik, kolay gerçeklenme, değiştirilebilirlik.
  - Zaman verimliliği (time efficiency) ve yer verimliliği (space efficiency).
  - Algoritmayı ifade etme yolları: akış diyagramı (flowchart), sözde kod (pseudo code), programlama dili.
  - Akış diyagramı kuralları: başlangıç/bitiş, işlem kutusu, `if`, `for` ve `while` döngüleri.
  - Ödevlerde beklenen C programlama kuralları.
* **Hocanın Vurgusu:**
  - Bir problemi çözerken birinci öncelik kodlamak değil, algoritmayı tasarlamaktır.
  - Akış diyagramında tek bir başlangıç ve tek bir bitiş noktası olur.
    - Sembol hataları değerlendirmede en çok puan kaybettiren konulardan biri.
  - `if` kutusunun true kolu hiçbir zaman boş, false kolu dolu bırakılmaz.
    - Gerekirse koşul ters çevrilir.
  - True/false kolunun hangi tarafta olduğu önemli değil, ama hangisi olduğu mutlaka yazılmalı.
  - Adım sayısı belliyse `for`, belli değilse (koşula bağlıysa) `while` kullanılır.

### 🔹 Ders 3: Insertion Sort, Asal Sayı Bulma, İkili Arama ve Algoritma Analizine Giriş
* **Genel Konular:**
  - Grupların yeniden dağıtılması ve dersin işleyişinin kısa hatırlatması.
  - Insertion sort: akış diyagramı, kaydırma mantığı, en iyi ve en kötü durum.
  - Bir sayının asal olup olmadığını bulma problemi ve adım adım iyileştirilmesi.
  - Eratosthenes Kalburu (Sieve of Eratosthenes) ile $n$'e kadar tüm asal sayıları bulma.
  - Doğrusal arama (linear/sequential search) ve ikili arama (binary search). Azalt ve yönet (decrease and conquer) yaklaşımı.
  - Hash ile aramaya kısa değinme.
  - Temel işlemler (basic/primitive operations) sayılarak zaman karmaşıklığının hesaplanması.
* **Hocanın Vurgusu:**
  - Ders başında herkes mikrofonunu kapalı tutmalı.
    - Söz almak için el kaldırın ya da chat'e yazın.
  - Birden fazla koşul varsa sınır kontrolü ilk sırada yazılmalı.
    - Insertion sort'ta önce `j >= 0`, sonra `a[j] > tmp` kontrol edilir. Ters sırada `a[-1]`'e erişilir ve segmentation fault oluşabilir.
  - İki koşulun birlikte sağlanması gerekiyorsa AND, birinin yetmesi yeterliyse OR kullanılır.
  - Karşılaştırma yapan sıralama algoritmaları iç içe iki döngüye ihtiyaç duyar.
  - Bir probleme önce kaba kuvvet (brute force, naive) çözümle başlayın ve doğru çalışan bir çözüm elde edin.
    - Sonra işlem sayısını, ardından bellek kullanımını azaltmaya çalışın.

### 🔹 Ders 5: Özyinelemeli Problemler ve Bağlı Listeler
* **Genel Konular:**
  - Önceki dersteki asallık testi akış diyagramının düzeltilmesi.
  - Özyineleme (recursion) tekrarı: durma koşulu (base condition), kendini çağırma (self call), çağrı yığını (call stack) ve stack overflow.
  - Özyinelemeli örnekler: iki sayının toplama ile çarpılması, rakamlar toplamı, palindrom kontrolü (sayıyı ters çevirme), asallık testi.
  - Alıştırma: bir dizinin $r$'li kombinasyonlarını özyinelemeli yazdırma.
  - Bağlı liste (linked list): diziyle karşılaştırma, düğüm (node) yapısı, `head` ve `tail`.
  - Bağlı liste türleri: tek yönlü (singly), çift yönlü (doubly), dairesel (circular) ve dairesel çift yönlü.
  - Bağlı liste işlemleri: gezinme (traverse), arama (search), güncelleme (update), ekleme (insert), silme (delete).
* **Hocanın Vurgusu:**
  - Bu örneklerin amacı özyinelemenin verimliliğini göstermek değil.
    - Amaç bir problemi özyinelemeli olarak nasıl tasarlayacağınızı göstermek.
  - Her özyinelemeli fonksiyonda bir durma koşulu ve bir kendini çağırma adımı olmalı.
  - Kendini çağırırken parametre mutlaka değiştirilmeli (azaltılmalı, 10'a bölünmeli vb.).
    - Parametreyi aynen geçirmek durma koşuluna ulaşmayı sağlamaz.
  - Özyineleme ne kadar derine inerse yığında o kadar yer kullanılır.
    - Yığın taşarsa stack overflow ve segmentation fault oluşur. Yığın boyutunuzu bilin.
  - Çağrı yığını LIFO (son giren ilk çıkar) çalışır.
    - Değerler en alttaki durma koşulundan yukarı doğru döner.
* **Detaylı Açıklamalar:** struct node *head = NULL;

### 🔹 Ders 7: Bağlı Listenin Değerlendirmesi, Yığın ve Aritmetik İfade Dönüşümleri
* **Genel Konular:**
  - Bağlı listenin (linked list) avantajları, dezavantajları ve kullanım alanları.
  - Dairesel bağlı listenin (circular linked list) kullanım alanları.
  - Yığın (stack): soyut veri tipi (abstract data type), LIFO (son giren ilk çıkar) mantığı.
  - Yığının kullanım alanları: aritmetik ifadeler, özyinelemeli çağrılar, dizgi ters çevirme, geri izleme (backtracking), parantez kontrolü, sayı tabanı dönüşümü, geri al (undo).
  - Yığın işlemleri: `initStack`, `isEmpty`, `isFull`, `push`, `pop`, `peek`/`top`, `size`.
  - Parantez dengesi kontrolü.
  - Dizi ile yığın gerçekleştirme ve tek yönlü bağlı liste ile yığın gerçekleştirme.
* **Hocanın Vurgusu:**
  - İlk ödev, bir aksilik olmazsa bir sonraki hafta verilecek.
    - Konusu bağlı liste ya da yığın olabilir.
  - Yığın ve kuyruk hem diziyle hem bağlı listeyle gerçekleştirilebilir.
    - Hangisinin seçileceği senaryoya bağlıdır.
  - Önbellek verimsizliği (cache inefficiency) bağlı listenin en çok dikkat edilmesi gereken dezavantajlarından biridir.
  - `push`'tan önce `isFull`, `pop`'tan önce `isEmpty` kontrolü mutlaka yapılmalı.
    - Yoksa segmentation fault oluşabilir.
  - `top` değişkeninin 0'dan mı 1'den mi başladığı ve neyi gösterdiği gerçekleştirmeye bağlıdır.
    - Farklı kaynaklarda farklı kabuller görebilirsiniz. Kendi içinde tutarlı olması yeterlidir.
* **Detaylı Açıklamalar:** struct stack { int item[MAX]; int top; };

### 🔹 Ders 9: Yığın Uygulamaları, Infix-Prefix Dönüşümü ve Kuyruk Yapıları
* **Genel Konular:**
  - Yığın (stack) yapısının kullanım alanları, avantajları ve dezavantajları.
  - Infix ifadeyi prefix ifadeye dönüştürme (infix to prefix).
  - Ekstra yığın kullanmadan, bağlı liste ile kurulmuş bir yığını ters çevirme.
  - Kuyruk (queue) yapısı: FIFO mantığı, `front` ve `rear` işaretçileri, `enqueue` ve `dequeue`.
  - Kuyruğun dizi ve bağlı liste ile gerçeklenmesi.
  - Dairesel kuyruk (circular queue): boşluk ve doluluk koşulları, modüler aritmetik.
  - Yığın ile kuyruğun karşılaştırılması.
* **Hocanın Vurgusu:**
  - Yığın, LIFO (last in first out) çalışır.
    - Gelen sıranın tersine hizmet verir. Bu yapıya uyan problemler yığınla kurgulanmalıdır.
  - Infix'ten prefix'e dönüşüm üç adımdır: ifadeyi ters çevir, postfix'e dönüştür, sonucu tekrar ters çevir.
  - Ters çevirmede parantezler de yer değiştirir: `(` yerine `)`, `)` yerine `(` yazılır.
  - Prefix dönüşümü postfix'ten daha zahmetlidir.
    - Bu yüzden derleyiciler genelde postfix üzerinden çalışır.
  - Yığında yalnız en üstteki elemana (`top`) erişilir.
    - Dizi ile gerçeklense bile alttaki elemanlara erişilmez; yığın soyut veri tipidir (abstract data type).
* **Detaylı Açıklamalar:** Örnek: $A * B + C / D$.

### 🔹 Ders 11: Kuyruk Türleri, Ağaçlar, Ağaçta Gezinme ve İkili Arama Ağacı
* **Genel Konular:**
  - Ödev ve derse yüz yüze katılım hakkında duyurular.
  - Kuyruk türleri: girişi kısıtlı (input restricted), çıkışı kısıtlı (output restricted), çift uçlu (double ended) ve öncelikli (priority) kuyruk.
  - Doğrusal olmayan (non-linear) veri yapılarına giriş: ağaçlar (tree).
  - Ağaç terminolojisi ve ağaçların kullanım alanları.
  - Ağaçta gezinme (tree traversal): inorder, preorder, postorder ve seviye seviye gezinme.
  - Özyinelemeli gezinme fonksiyonları.
  - İkili ağaç türleri: full, perfect, complete, balanced, degenerate ve skewed.
* **Hocanın Vurgusu:**
  - Her ağaç bir graftır, ama her graf ağaç değildir.
  - Ağacın bir tarafa yaslı (skewed) olması istenmez.
    - Bu durumda işlemler $O(\log n)$ yerine $O(n)$ olur; diziden farkı kalmaz.
  - Mümkün olduğunca dengeli ağaçlar kullanılır ya da ağaç dengeli hale getirilir.
  - Ağaçta gezinmeyi özyinelemeli (recursive) yazmak çok daha kolaydır.
    - Ancak çok derin ağaçta stack overflow riski vardır.
  - İkili arama ağacı (BST) ile ikili arama (binary search) algoritması farklı kavramlardır.
* **Detaylı Açıklamalar:** Örnek ağaç:

### 🔹 Ders 13: Heap Ağaçları, Heapify, Heap'e Ekleme-Silme ve Heap Sort
* **Genel Konular:**
  - Sınav ve ödev duyuruları.
  - İkili yığın ağacı (binary heap tree): max heap ve min heap.
  - Heapify işlemi ve karmaşıklığı.
  - Rastgele bir ağacı (diziyi) max heap'e dönüştürme (build max heap).
  - Heap'in avantajları, dezavantajları ve kullanım alanları.
  - Heap'e ekleme (insertion, up-heap) ve heap'ten silme (deletion, down-heap).
  - Yığın sıralaması (heap sort) ve karmaşıklığı.
* **Hocanın Vurgusu:**
  - Bir ağacın heap olması için iki koşul vardır:
    - Complete binary tree olmalıdır.
  - Kardeşler arasında bir sıra kuralı yoktur.
    - Sol çocuğun sağdan büyük ya da küçük olması önemli değildir.
  - Ekleme ve silme ağacın yapısını bozabilir.
    - Bu yüzden her değişiklikten sonra heapify yapılır.
  - Ağaç complete olduğu için tek tarafa yaslanamaz.
    - Bu yüzden ekleme ve silme en kötü durumda da $O(\log n)$'dir.
  - Heap, arama (search) için uygun değildir.
    - Bir değeri aramak için tüm ağaç gezilir.
* **Detaylı Açıklamalar:** Heapify, ağacı heap kurallarına uydurma işlemidir. Ayrıca bir diziden heap oluşturma işlemi için de kullanılır.

### 🔹 Ders 15: Öncelikli Kuyruklar ve Heap Alıştırmaları
* **Genel Konular:**
  - Ara sınav, ödevler ve dönem planı duyuruları.
  - Öncelikli kuyruk (priority queue) ve temel işlemleri: `insert`, `remove` (delete), `peek`.
  - Öncelikli kuyruğun farklı veri yapılarıyla gerçeklenmesi ve karmaşıklık karşılaştırması.
  - Öncelikli kuyruğun kullanım alanları.
  - Binary heap ile ekleme ve çıkarma örneği.
  - Geçen haftanın alıştırmaları:
    - İkili ağacın heap olup olmadığını kontrol eden kod.
* **Hocanın Vurgusu:**
  - Öncelikli kuyruk yalnız heap ile değil, dizi, bağlı liste ve dengeli ikili arama ağacı ile de gerçeklenebilir.
  - Heap ile gerçekleme işlemleri $O(\log n)$'e indirir ve en öncelikli elemana $O(1)$'de erişim sağlar.
    - Bu yüzden genelde tercih edilir.
  - Dengesiz bir ağaçla öncelikli kuyruk kurmanın faydası yoktur; dengeli (AVL gibi) ağaç gerekir.
  - `peek` ile `remove` farklıdır: `peek` yalnız değeri okur, `remove` elemanı çıkarıp yapıyı yeniden düzenler.
  - Heap'e ekleme yaparken bütün iç düğümleri heapify etmek gerekmez.
    - Yalnız yeni elemanın aşağıdan yukarı (bottom-up) yerleşmesi yeterlidir. Hoca bunu bilerek önce yanlış anlatıp öğrencilerin fark etmesini bekledi.
* **Detaylı Açıklamalar:** Başlangıç max heap'i: `9, 3, 5, 1, 4, 2` (sıradaki müşteri 9).

### 🔹 Ders 20: Graflara Giriş, Kapsayan Ağaç ve Kruskal Algoritması
* **Genel Konular:**
  - Vize ve 1 Mayıs tatilinden sonraki ilk ders. Graflar konusuna giriş yapıldı.
  - Graf türleri: null, trivial, yönlü/yönsüz, bağlı, tam, döngülü, DAG, iki parçalı, ağırlıklı graf.
  - Grafın saklanması: komşuluk matrisi (adjacency matrix) ve komşuluk listesi (adjacency list).
  - Yoğun (dense) ve seyrek (sparse) graf ayrımı, hangi gösterimin ne zaman seçileceği.
  - Graf üzerindeki temel işlemler: düğüm/kenar ekleme, silme, arama, gezinme (DFS, BFS).
  - Kapsayan ağaç (spanning tree) ve en küçük kapsayan ağaç (minimum spanning tree, MST).
  - Açgözlü (greedy) yaklaşım; Prim ve Kruskal algoritmalarının fikri.
* **Hocanın Vurgusu:**
  - Bir graf sorusunda önce grafın yönlü mü yönsüz mü olduğuna bakın.
    - Çözüm buna göre değişir.
  - Yönsüz grafın komşuluk matrisi simetrik olmak zorundadır.
    - Simetrik değilse ya bilgi hatası vardır ya da graf yönlüdür.
  - "Matris mi liste mi daha iyi?" sorusunun mutlak cevabı yok.
    - Karar, kenar sayısına (yoğunluğa) bağlıdır.
  - Ağaç, grafın özel bir hâlidir.
    - Bir graftan ağaç çıkabilmesi için döngü (cycle) olmamalıdır.
  - Kapsayan ağacın iki şartı: bağlılık (connectivity) ve döngüsüzlük (acyclic).
* **Detaylı Açıklamalar:** Hoca türleri tahtaya numaralandırarak yazdı.

### 🔹 Ders 22: Vize Sorularının Çözümü, Prim ve Dijkstra Algoritmaları
* **Genel Konular:**
  - Vize sorularının çözümü: yığın, kuyruk, bağlı liste, heap, özyineleme, sıralama, ikili arama ağacı soruları ve kod sorusu.
  - En küçük kapsayan ağaç için Prim algoritması: iki örnek.
  - Prim ve Kruskal karşılaştırması.
  - En kısa yol problemi için Dijkstra algoritması: elle çözüm ve matrisle çözüm.
* **Hocanın Vurgusu:**
  - Kod sorusunda puanların çoğu algoritmanın akışından kırıldı.
    - Önce sayfanın listede olup olmadığına bakılmalıydı.
  - Bağlı listede bir düğümü bulduktan sonra onu tekrar aramak için listeyi baştan gezmeyin.
    - Gezerken `prev` ve `current` adreslerini tutun.
  - Hoca `while` içinde `break` kullanılmasını istemiyor.
    - `while` zaten adım sayısı belli olmayan döngüler içindir. Fonksiyondan `return` ile çıkmak sorun değil.
  - Bağlı liste istenen soruda dizi kullananların puanı ciddi kırıldı.
  - Online vize notları yüksek çıktı.
    - Finale ciddi hazırlanın. Kâğıt üzerinde soru çözmek bilgisayar başında çözmekten farklıdır.
* **Detaylı Açıklamalar:** Hoca soruları Word belgesi üzerinden tek tek çözdü.

### 🔹 Ders 24: Metin Arama: Kaba Kuvvet, Boyer-Moore ve Rabin-Karp
* **Genel Konular:**
  - Metin arama (string matching / pattern matching) problemi ve kullanım alanları.
  - Kaba kuvvet (brute force) yöntemi ve en kötü durum karmaşıklığı.
  - Boyer-Moore-Horspool algoritması: kaydırma tablosu (shift table) ve eşleştirme sözde kodu.
  - Boyer-Moore algoritması: kötü karakter kaydırması (bad symbol shift) ve iyi sonek kaydırması (good suffix shift).
  - BAOBAB örneğiyle Boyer-Moore'un adım adım çözümü.
  - Rabin-Karp algoritması: modüler aritmetik ve kayan özet (rolling hash).
  - Algoritmaların karmaşıklık karşılaştırması.
* **Hocanın Vurgusu:**
  - Kaba kuvvet yöntemi, eşleşme ihtimali olmayan konumları da tek tek dener.
    - Bu "körebe gibi" bir yaklaşımdır.
  - Daha iyi yöntemlerin fikri: uyuşmazlık olduğunda örüntüyü bir değil, mümkün olduğunca fazla kaydırmak.
  - Boyer-Moore ön işlem ister.
    - Ön işlem metin üzerinde değil, örüntü üzerinde yapılır. Örüntü ($m$) metinden ($n$) çok kısa olduğu için maliyet düşüktür.
  - Boyer-Moore karşılaştırmayı sağdan sola, Knuth-Morris-Pratt soldan sağa yapar.
  - Kaydırma tablosunu doldururken örüntünün son karakteri hesaba katılmaz.
* **Detaylı Açıklamalar:** Karşılaştırma örüntünün sonundan başlar. Uyuşmazlık olunca kaydırma miktarı, örüntünün o anki son karakterinin hizasındaki metin karakterine ($c$) göre belirlenir.

### 🔹 Ders 26: Sıralama Algoritmalarının Karşılaştırılması, Counting Sort ve Radix Sort
* **Genel Konular:**
  - Dönemin son dersi. Dönem projesi ve final sınavıyla ilgili sorular.
  - Karşılaştırmaya dayalı sıralama algoritmalarının zaman ve bellek karmaşıklığı tablosu.
  - Sıralama algoritmalarını karşılaştırma ölçütleri: kararlılık (stable), yerinde (in-place) sıralama, çevrim içi (online) ve çevrim dışı (offline) sıralama.
  - Hangi durumda hangi algoritmanın seçileceği.
  - Karşılaştırma yapmayan sıralama algoritmaları: sayma sıralaması (counting sort) ve taban sıralaması (radix sort).
  - LSD ve MSD radix sort; sayılar ve dizgiler üzerinde kullanım.
* **Hocanın Vurgusu:**
  - Sıralı veri birçok problemin çözümünü kolaylaştırır.
    - Bu yüzden veri çoğu zaman önce sıralanır.
  - Karşılaştırmaya dayalı sıralamada $O(n \log n)$ bir alt sınırdır.
    - Daha iyisi tasarlanamaz.
  - Karşılaştırma yapmayan algoritmalar bu sınırın altına iner.
    - Bunun bedeli ek bellek kullanımıdır.
  - Bubble sort'un en iyi durumu $O(n)$ olabilmesi için iyileştirilmiş sürümü gerekir: dış döngü, değişiklik olup olmadığını kontrol eden bir `while` döngüsü olmalıdır.
  - Kararlılık her problemde gerekmez.
    - Ama eşit değerlerin sırası önemliyse kararlı algoritma seçilmelidir.
* **Detaylı Açıklamalar:** Örnek dizi: `4 2 2 8 3 3 1`. En büyük değer 8.

**Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
