# Veri Yapıları ve Algoritmalar Ders Kayıtları & Çalışma Özetleri

> **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.

### 📋 Genel Bilgiler
* **Ders:** Veri Yapıları ve Algoritmalar (BLM2512)
* **Hoca:** Prof. Dr. M. Elif Karslıgil
* **Dönem:** Bahar
* **Akademik Yıl:** 2022-2023
* **Şube:** BLM2512 - 1

Bu dizin, ilgili ders kayıtlarının altyazı özetlerini, çalışma notlarını ve PDF kaynaklarını içermektedir.

## 📚 Ders Müfredatı ve Belge Dizini

Aşağıdaki tabloda her bir dersin konusu, kaynak markdown dosyası ve doğrudan indirilebilir PDF formatındaki derlenmiş halleri listelenmiştir. Ders numaraları, kayıt arşivindeki ders kaydı sıra numaralarıdır (hafta numarası değildir).

| Ders No | Ders İçeriği / Konu Başlıkları | Kaynak Notlar (Markdown) | Çalışma Dosyası (PDF) |
| :---: | :--- | :---: | :---: |
| **Ders 3** | Algoritma Analizi, Asimptotik Notasyon ve Insertion Sort | [Özet](altyazi_ozetleri/ders_3_ozet.md) | [PDF (İndir)](ders_3_ozet.pdf) |
| **Ders 5** | Özyineleme, Özyinelemeli İkili Arama ve Bağlı Listelere Giriş | [Özet](altyazi_ozetleri/ders_5_ozet.md) | [PDF (İndir)](ders_5_ozet.pdf) |
| **Ders 7** | Tek Yönlü, Çift Yönlü ve Dairesel Bağlı Listeler | [Özet](altyazi_ozetleri/ders_7_ozet.md) | [PDF (İndir)](ders_7_ozet.pdf) |
| **Ders 9** | Yığın, İfade Değerlendirme ve Kuyruk Yapıları | [Özet](altyazi_ozetleri/ders_9_ozet.md) | [PDF (İndir)](ders_9_ozet.pdf) |
| **Ders 11** | Ağaçlar, İkili Ağaçlar ve İkili Arama Ağaçları | [Özet](altyazi_ozetleri/ders_11_ozet.md) | [PDF (İndir)](ders_11_ozet.pdf) |
| **Ders 13** | İkili Arama Ağacında Silme, Heap Ağacı ve Heap Sort | [Özet](altyazi_ozetleri/ders_13_ozet.md) | [PDF (İndir)](ders_13_ozet.pdf) |
| **Ders 15** | Öncelikli Kuyruklar ve Huffman Kodlama | [Özet](altyazi_ozetleri/ders_15_ozet.md) | [PDF (İndir)](ders_15_ozet.pdf) |
| **Ders 19** | Graf Veri Yapısı ve Minimum Yayılan Ağaç | [Özet](altyazi_ozetleri/ders_19_ozet.md) | [PDF (İndir)](ders_19_ozet.pdf) |
| **Ders 20** | Kruskal Algoritmasının Tasarımı ve Dijkstra ile En Kısa Yol | [Özet](altyazi_ozetleri/ders_20_ozet.md) | [PDF (İndir)](ders_20_ozet.pdf) |
| **Ders 22** | Alt Dizgi Arama: Kaba Kuvvet, Boyer-Moore ve Rabin-Karp | [Özet](altyazi_ozetleri/ders_22_ozet.md) | [PDF (İndir)](ders_22_ozet.pdf) |
| **Ders 23** | Anahtar İndeksli Sayma, LSD Dizgi Sıralama ve Vize Sorularının Çözümü | [Özet](altyazi_ozetleri/ders_23_ozet.md) | [PDF (İndir)](ders_23_ozet.pdf) |

> [!NOTE]
> Arşivdeki ara numaralı kayıtlar bulunmamaktadır. 24 Nisan 2023 haftası vize haftası, 1 Mayıs 2023 resmî tatildir.

## 🎯 Derslerin Detaylı Özetleri ve Kazanımları

### 🔹 Ders 3: Algoritma Analizi, Asimptotik Notasyon ve Insertion Sort
* **Genel Konular:**
  - Bir algoritmanın sağlaması gereken şartlar: doğru, basit, genel, kolay gerçeklenebilir ve verimli (efficient) olmak.
  - Verimlilik iki kaynakla ölçülür: zaman (time) ve yer (space).
  - Çalışma süresinin giriş boyutu $n$ ile nasıl büyüdüğü: $\log n$, $n$, $n \log n$, $n^2$, $2^n$, $n!$ karşılaştırması.
  - Çalışma süresini etkileyen faktörler: donanım, derleyici (compiler), programlama dili ve veri.
  - Adım sayma ile karmaşıklık hesabı, temel işlem (basic operation) kavramı.
  - Asimptotik analiz (asymptotic analysis) ve asimptotik notasyon: Big O, Big Theta, Big Omega.
  - En iyi durum (best case), en kötü durum (worst case) ve ortalama durum (average case).
* **Hocanın Vurgusu:**
  - Sorular chat'ten değil, sesli olarak sorulmalı.
    - Hoca tam ekranda chat'i görmüyor.
  - Algoritmaya doğrudan kodla başlamayın.
    - Önce akış diyagramı veya yarı kod (pseudo code) ile tasarlayın. Koddaki hata düzeltmeleri "yama" gibi olur ve algoritmayı gereksiz büyütür.
  - Çalışma süresini saniye ile ölçmek iyi bir yöntem değil.
    - Süre donanıma, derleyiciye ve dile bağlıdır. Algoritma sistemden bağımsız değerlendirilmeli.
  - Karmaşıklık hesabında sabitler, katsayılar ve küçük terimler önemsizdir.
    - Önemli olan $n$'e bağlı en büyük terimdir.
  - Bu dönem yalnız Big O kullanılacak.
    - Theta ve Omega algoritma analizi dersinde (3. sınıf) işlenecek.
* **Detaylı Açıklamalar:** Hoca, her işlemin yaklaşık 1 ns sürdüğü bir bilgisayarda ölçülmüş/hesaplanmış şu değerleri verdi:

### 🔹 Ders 5: Özyineleme, Özyinelemeli İkili Arama ve Bağlı Listelere Giriş
* **Genel Konular:**
  - Özyinelemeli (recursive) fonksiyonların mantığı ve ne zaman kullanılması gerektiği.
  - Faktöriyelin iteratif ve özyinelemeli yazımı.
  - Dizi elemanlarının toplamını özyinelemeli bulma.
  - Özyineleme yazmanın adımları: temel durum (base case), özyinelemeli durum (recursive case), sonlanmanın garanti edilmesi.
  - Doğrudan (direct) ve dolaylı (indirect) özyineleme.
  - Özyinelemenin maliyeti: stack kullanımı, fonksiyon çağırma yükü (overhead), stack overflow.
  - Kötü özyineleme örneği: Fibonacci'de aynı alt problemlerin tekrar tekrar hesaplanması.
* **Hocanın Vurgusu:**
  - Bir problem döngüyle (iteratif) aynı açıklıkta çözülebiliyorsa döngü kullanılmalı.
    - Özyineleme gerçekten gerektiğinde kullanılmalı.
  - Quicksort, merge sort, ağaç ve graf algoritmaları gibi problemlerde özyinelemeli çözüm çok daha basit ve anlaşılırdır.
    - Bu durumlarda özyineleme doğru seçimdir.
  - Faktöriyel özyinelemeye örnek olarak gösterilir ama aslında iteratif yazmak daha uygundur.
  - Sınavlarda her şeyi özyinelemeli yazmaya çalışan öğrenciler oluyor ve genelde hata yapıyorlar. "Sofistike görünsün" diye özyineleme kullanmayın.
  - Her özyinelemeli fonksiyonda mutlaka bir temel durum olmalı.
    - Yoksa fonksiyon sonsuza kadar kendini çağırır.
* **Detaylı Açıklamalar:** Tanım:

### 🔹 Ders 7: Tek Yönlü, Çift Yönlü ve Dairesel Bağlı Listeler
* **Genel Konular:**
  - Bağlı listenin (linked list) neden gerektiği: eleman sayısının çalışma sırasında sürekli değiştiği durumlar.
  - Tek yönlü bağlı liste (singly linked list) düğüm yapısı, `head` ve düğüm oluşturma (`createNode`).
  - Başa ekleme (insert at front), sona ekleme (insert at end) ve sıralı listeye araya ekleme (ödev olarak bırakıldı).
  - Listeyi baştan sona dolaşıp ekrana yazdırma (display).
  - Listeden eleman silme (delete) ve olası durumlar.
  - Çift yönlü bağlı liste (doubly linked list): düğüm yapısı, başa ve sona ekleme.
  - Dairesel bağlı liste (circular linked list): `last` pointer'ı ile başa ve sona ekleme, listeyi yazdırma.
* **Hocanın Vurgusu:**
  - Bağlı listede elemanlara sırayla erişilir.
    - Ortadaki bir elemana doğrudan atlanamaz.
  - Ekleme yapılacak yerin özel bir önemi yoksa başa ekleyin.
    - Başa ekleme $O(1)$, sona ekleme tek yönlü listede $O(n)$'dir.
  - Sona ekleme, sıralamanın önemli olduğu durumlarda yapılır.
    - Örneğin kuyrukta (queue) ilk gelene ilk hizmet verilir.
  - `malloc` ile yer ayrıldıktan sonra mutlaka `NULL` kontrolü yapın.
    - Yer ayrılamadıysa üzerinde işlem yapmaya çalışmayın.
  - Gereksiz yere global değişken tanımlamayın; hata ayıklamayı zorlaştırır.
    - `head` hemen her fonksiyonda kullanıldığı için bu derste kolaylık olsun diye global tanımlandı. Parametre olarak fonksiyondan fonksiyona aktarmak da mümkündür.
* **Detaylı Açıklamalar:** typedef struct node { int value; struct node *next; } node;

### 🔹 Ders 9: Yığın, İfade Değerlendirme ve Kuyruk Yapıları
* **Genel Konular:**
  - Erişim şekline göre veri yapıları: dizi (rastgele erişim), bağlı liste (sıralı erişim), yığın (stack).
  - Yığın (stack) ve LIFO (last in first out) mantığı: undo/redo, tarayıcıda geri gitme, fonksiyon çağrıları.
  - Dizi ile yığın gerçekleştirme: `push`, `pop`, `isEmpty`, `isFull`, `peek`.
  - Yığın uygulaması: aritmetik ifade değerlendirme (expression evaluation).
    - İki yığınla infix ifadeyi doğrudan çözme.
  - Kuyruk (queue) ve FIFO (first in first out) mantığı.
  - Basit kuyruk, dairesel kuyruk (circular queue) ve bağlı liste ile kuyruk.
  - Soru: Yığındaki en büyük elemanı her an bilmek (max stack).
* **Hocanın Vurgusu:**
  - Yığında yalnız en üstteki elemana erişilebilir.
    - Aradaki elemanlara erişmek yasaktır; yapının anlamı budur.
  - Bu derste gerçekleştirilen yığın, donanımdaki stack bölgesi değil, dizi kullanılarak yazılan yüksek seviyeli (high level) bir yapıdır.
  - `pop` öncesi yığının boş, `push` öncesi dolu olup olmadığı mutlaka kontrol edilmeli.
    - Bu kontroller atlanırsa program yanlış çalışır.
  - Eleman sayısı yaklaşık biliniyorsa yığın için dizi yeterlidir.
    - Bağlı liste de kullanılabilir.
  - Basit kuyrukta eleman çıkarmak $O(n)$'dir, çünkü tüm elemanlar bir öne kaydırılır.
    - Dairesel kuyruk ve bağlı liste ile kuyruk bu sorunu çözer.
* **Detaylı Açıklamalar:** Örnekler:

### 🔹 Ders 11: Ağaçlar, İkili Ağaçlar ve İkili Arama Ağaçları
* **Genel Konular:**
  - Ağaç (tree) veri yapısı: neden gerekli, nerede kullanılır.
  - Ağaç terminolojisi: kök, düğüm, kenar, iç düğüm, yaprak, derece, seviye, yükseklik, derinlik, alt ağaç, orman.
  - Genel ağacın bilgisayarda saklanması: dizi ile ve bağlı liste (left child - right sibling) ile.
  - İkili ağaç (binary tree) ve saklama yöntemleri: dizi ($2i+1$, $2i+2$) ve bağlı liste.
  - Tam ikili ağaç (complete binary tree) ve dengeli ikili ağaç (balanced binary tree).
  - Yüksekliği $h$ olan ikili ağaçta en çok/en az yaprak ve düğüm sayısı.
  - Ağaç gezinme (traversal): preorder, postorder, inorder.
* **Hocanın Vurgusu:**
  - Dizi, bağlı liste, yığın, kuyruk doğrusal (linear) veri yapılarıdır.
    - Ağaç doğrusal olmayan (non-linear) bir veri yapısıdır.
  - Ağaç, bilginin hiyerarşik olarak saklanması ve erişilmesi gerektiğinde kullanılır.
    - Örnekler: dosya sistemi, aile ağacı, karar ağaçları (decision tree).
  - Çocuk sayısı belli olmayan bir ağacı saklamanın en uygun yolu bağlı listedir.
  - Dizi ile saklamada iki sorun var:
    - Bir düğümün en fazla kaç çocuğu olacağını önceden bilmek gerekir.
  - İkili ağaçta seçim uygulamaya göre yapılır.
    - Ağaçta az boşluk varsa (ör. tam ikili ağaç) dizi uygundur.
* **Detaylı Açıklamalar:** Hocanın tahtadaki örneği şöyleydi:

### 🔹 Ders 13: İkili Arama Ağacında Silme, Heap Ağacı ve Heap Sort
* **Genel Konular:**
  - İkili arama ağacı (binary search tree, BST) tekrarı.
  - BST'ye özyinelemeli (recursive) ekleme.
  - BST'den silme (delete): yaprak, tek çocuklu düğüm, iki çocuklu düğüm.
  - Heap ağacı (heap tree): tanımı, üç şartı, max heap ve min heap.
  - Heap'in dizide saklanması.
  - Heap'e ekleme ve yukarı taşıma (sift up).
  - Heap sıralama (heap sort) ve aşağı taşıma (sift down), `findBigChild` fonksiyonu.
* **Hocanın Vurgusu:**
  - Dengeli bir BST'de arama, ekleme ve silme $O(\log n)$ sürer.
    - Denge bozulup ağaç tek tarafa yığılırsa $O(n)$ olur ve BST kullanmanın avantajı kalmaz.
  - Ekleme her zaman uygun yaprağa yapılır.
    - Silmede ise silinecek eleman ağacın herhangi bir yerinde olabilir, bu yüzden üç durum ayrı ele alınır.
  - Hoca özyinelemeli ekleme yerine döngülü (klasik) eklemeyi tercih ettiğini söyledi.
    - Özyinelemeli sürümün belirgin bir avantajı yok, sadece örnek olsun diye gösterildi.
  - Sürekli ekleme/silme yapılan ağaçlar bağlı listede saklanmalıdır.
  - Buradaki heap, bellekteki heap bölgesi (dinamik bellek ayırma) ile aynı şey değildir.
    - Bir ağaç türüdür.
* **Detaylı Açıklamalar:** struct node *newNode(int value) { struct node *temp = malloc(sizeof(struct node)); /* temp == NULL ise bellek ayrılamadı; programın ihtiyacına göre hata verilmeli */ temp->value = value; temp->left = temp->right = NULL; return temp; }

### 🔹 Ders 15: Öncelikli Kuyruklar ve Huffman Kodlama
* **Genel Konular:**
  - Vize sınavı duyurusu: online, üç bölüm, soru başına süre.
  - Heap sort tekrarı ve sıralama algoritmalarının karşılaştırması (best, average, worst case, ek bellek).
  - Öncelikli kuyruk (priority queue): sıralı dizi, sıralı bağlı liste, sırasız dizi ve heap ile gerçekleştirme; karmaşıklıklar.
  - Heap ile öncelikli kuyruk: en öncelikli elemanı çıkarma ve ekleme.
  - Huffman kodlama (Huffman coding): kayıpsız sıkıştırma, prefix kod, öncelikli kuyruk ile Huffman ağacı oluşturma.
  - Sınav hazırlığı soruları: max heap'te ikinci en büyük eleman, bir ağacın heap olup olmadığını kontrol etme, BST kontrolü, min heap'te $k$. küçük eleman (ev çalışması).
* **Hocanın Vurgusu:**
  - Heapify (sift up ya da sift down) her adımda bakılan bölgenin yarısını eler.
    - Bu yüzden karmaşıklığı $O(\log n)$'dir.
  - Heap sort her durumda $O(n \log n)$'dir.
    - Dizinin baştan sıralı olması bir şey değiştirmez. Ek bellek olarak sadece yer değiştirme için bir yedek değişken kullanır.
  - En sık kullanılan $O(n \log n)$ sıralama quicksort'tur, çünkü pratikte daha hızlıdır.
    - Kötü durumdan kaçınmak için dizi önce karıştırılabilir (shuffle). Ama heap sort da ihtiyaca göre kullanılabilecek etkili bir algoritmadır.
  - Öncelikli kuyrukta sık ekleme yapılıyorsa (ör. acil servis) en uygun yapı ikili heap'tir.
    - Ekleme nadirse sıralı dizi ya da sıralı liste de kullanılabilir.
  - Ağaçlarla çalışırken bir düğümün iki çocuğu mu, tek çocuğu mu var, yoksa hiç çocuğu yok mu, mutlaka kontrol edilmelidir.
    - Eski sınavlarda öğrencilerin yaklaşık üçte ikisi bu kontrolü atladığı için yanlış yapmış.

### 🔹 Ders 19: Graf Veri Yapısı ve Minimum Yayılan Ağaç
* **Genel Konular:**
  - Vize sonrası değerlendirme: kopya ve derse katılım üzerine uyarılar.
  - Graf (graph) veri yapısı: neden doğrusal olmayan bir yapıdır, gerçek hayattaki kullanım alanları.
  - Graf terminolojisi: düğüm, kenar, komşuluk, derece, yol, döngü, bağlı bileşen, ağaç, yayılan ağaç, klik, bağlı/bağlı olmayan graf, iki parçalı graf, ağırlıklı graf.
  - Sembol tablosu ve sembol graf.
  - Grafın saklanması: komşuluk matrisi (adjacency matrix) ve komşuluk listesi (adjacency list); yoğun ve seyrek graflar; C ile komşuluk listesi.
  - Yönlü graf (directed graph, digraph): giriş derecesi ve çıkış derecesi.
  - Minimum yayılan ağaç (minimum spanning tree, MST): Prim ve Kruskal algoritmaları, döngü kontrolü için etiket dizisi, karmaşıklıklar.
* **Hocanın Vurgusu:**
  - Hoca vizede çok fazla kopya çekildiğini söyledi.
    - Bazı cevaplar internetten kopyalanıp yapıştırılmış kitap cümleleriydi.
  - Diğer öğretim üyeleri de derse katılımın çok düşük olduğunu söylüyor.
    - Bir öğrenci, kayıtların sonradan hızlandırılarak izlenmesini sebep olarak gösterdi.
  - Dizi, bağlı liste, yığın ve kuyruk doğrusal (linear) yapılardır.
    - Graf doğrusal değildir: bilgiler aralarındaki ilişkiye göre birbirine bağlanır, sıralı bir erişim yoktur.
  - Graf, günlük hayatta en çok kullanılan veri yapılarından biridir.
    - En temel örnek internettir.
  - Düğümlerin ve kenarların neyi göstereceğine uygulamaya göre siz karar verirsiniz.
* **Detaylı Açıklamalar:** struct Graph { int numVertices; struct node **adjLists; /* her düğüm için liste başı pointer'ı */ };

### 🔹 Ders 20: Kruskal Algoritmasının Tasarımı ve Dijkstra ile En Kısa Yol
* **Genel Konular:**
  - Minimum yayılan ağaç (minimum spanning tree, MST) tekrarı: Prim ve Kruskal algoritmaları.
  - Kruskal algoritmasının etiket dizisiyle (label array) tasarımı ve C koduna dökülmesi.
  - `union` fonksiyonu ile iki alt grafın birleştirilmesi.
  - Kruskal ile Prim'in karşılaştırılması: seyrek (sparse) ve yoğun (dense) graflar.
  - En kısa yol (shortest path) problemi ve Dijkstra algoritması.
  - Dijkstra'nın öncelik kuyruğu (priority queue) ile çalışması ve sözde kodu (pseudo code).
  - Derinlik öncelikli arama (depth-first search, DFS) ve genişlik öncelikli arama (breadth-first search, BFS) bu dönem anlatılmadı. Hoca bunların önümüzdeki dönem anlatılacağını söyledi.
* **Hocanın Vurgusu:**
  - Prim ve Kruskal ikisi de açgözlü (greedy) algoritmadır.
    - Mantık: yerelde en iyi seçim, globalde de en iyi sonucu verir.
  - Kruskal'da ilk iş kenarları ağırlığa göre küçükten büyüğe sıralamaktır.
    - Karmaşıklık bu sıralamadan gelir: $O(E \log V)$.
  - $n$ düğümlü bir grafın MST'sinde $n-1$ kenar vardır.
    - Döngü bu yüzden `i < nV - 1` koşuluyla döner.
  - Kruskal'da iki düğümün etiketine bakılır.
    - Dört durum vardır:
  - Yoğun graflarda Prim, seyrek graflarda Kruskal daha iyi çalışır.
    - Prim bir düğüme birden çok kez bakmak zorunda kalır. Kruskal'da bir kenarla işi biten düğüme geri dönülmez.
* **Detaylı Açıklamalar:** Hoca 8 düğümlü (A-H) bir graf çizdi. Kenarlar ağırlığa göre sıralandı:

### 🔹 Ders 22: Alt Dizgi Arama: Kaba Kuvvet, Boyer-Moore ve Rabin-Karp
* **Genel Konular:**
  - Duyurular: final ve bütünleme sınavları online; proje ödevi ve vize notları ilanı.
  - Alt dizgi arama (substring search) problemi: uzun bir metinde (text) kısa bir örüntüyü (pattern) bulmak.
  - Kaba kuvvet (brute force) arama: algoritma, C kodu ve karmaşıklık analizi.
  - Boyer-Moore yöntemi: örüntüyü sondan başa karşılaştırma ve uyumsuz karaktere göre kaydırma.
  - Kaydırma tablosu (`rightSkip`, Horspool yaklaşımı) ile kaydırma miktarının önceden hesaplanması.
  - Rabin-Karp parmak izi (fingerprint) yöntemi: modüler özetleme (modular hashing) ve kayan özet (rolling hash).
  - Üç yöntemin karmaşıklık karşılaştırması.
* **Hocanın Vurgusu:**
  - Arama ve sıralama, en sık ihtiyaç duyulan algoritmalardır.
    - Bu ders tek eleman yerine bir grup bilgiyi (DNA dizisi içinde parça, metin içinde kelime) aramayı ele alıyor.
  - Kaba kuvvet aramada her uyumsuzlukta örüntü bir karakter kaydırılır ve karşılaştırma örüntünün başından yeniden başlar.
    - Metindeki karakterlere defalarca bakılır.
  - Arama `i <= n - m` noktasına kadar sürer.
    - Geriye örüntüden kısa bir parça kaldığında aramaya gerek yoktur.
  - Fonksiyon içinden `return` ile çıkmak, döngüyü `break` ile kırmakla aynı şey değildir.
    - Hoca `break` ile döngü kırmamayı, okunabilirlik için `while` ve `found` bayrağı kullanmayı önerdi.
  - Boyer-Moore'da karşılaştırma örüntünün sonundan başına doğru yapılır.
* **Detaylı Açıklamalar:** Örüntü metnin başına oturtulur. Karakterler soldan sağa karşılaştırılır. Uyumsuzluk çıkarsa örüntü bir sağa kaydırılır ve karşılaştırma örüntünün başından yeniden başlar.

### 🔹 Ders 23: Anahtar İndeksli Sayma, LSD Dizgi Sıralama ve Vize Sorularının Çözümü
* **Genel Konular:**
  - Dönemin son dersi.
  - Dizgi (string) sıralamanın sayı sıralamasından farkı.
  - Anahtar indeksli sayma (key-indexed counting): her karakterin sıralı dizide nereden başlayacağını sayarak bulma.
  - LSD dizgi sıralama (least significant digit first string sort): sabit uzunluklu dizgileri sağdan sola karakter karakter sıralama.
  - Kararlı sıralama (stable sorting) kavramı.
  - Yedek dizi kullanmanın bellek açısından değerlendirmesi.
  - Vize sınavı sorularının çözümü ve sık yapılan hatalar.
* **Hocanın Vurgusu:**
  - Sayılar bir bütün olarak karşılaştırılır (34 ile 45 gibi).
    - Dizgilerde her karakter ayrı bir değerdir; karşılaştırma karakter karakter yapılır. İlk farklı karakterde karar verilir.
  - C'de karakterler sayı gibi kullanılabilir: `'a' - 'a' = 0`, `'c' - 'a' = 2`.
    - Bu fark doğrudan dizi indisi olarak kullanılır.
  - `count` dizisi mutlaka sıfırlanmalıdır.
    - Sıfırlanmazsa bellekte kalan değerlerin üzerine eklenir.
  - LSD sıralama kararlıdır: aynı değere sahip iki elemanın önceki adımdaki göreli sırası korunur.
    - Korunmazsa önceki adımlarda yapılan sıralama boşa gider.
  - Yedek dizi kullanan algoritmalar (merge sort, key-indexed counting) zaman kazandırır ama bellek harcar.
    - Eleman sayısı çok büyükse bu bir sorun olabilir. Selection sort, insertion sort, quicksort gibi algoritmalar bu yüzden dizinin kendisi üzerinde çalışır.
* **Detaylı Açıklamalar:** Varsayım: anahtarlar 0 ile $R-1$ arasında tam sayılardır ve dizi indisi olarak kullanılabilir. Burada $R$ sembol sayısıdır (örnekte `a`-`f`, yani $R = 6$).

**Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
