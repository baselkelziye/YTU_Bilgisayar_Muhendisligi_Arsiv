# Ders 1 Çalışma Özeti

## Genel Konular

- Dersin yeri ve kapsamı
  - Algoritma analizi; yapısal programlama, veri yapıları ve ayrık matematik derslerinin üzerine kurulan, ön koşullu bir derstir. Bu derslerde görülen dizi, bağlı liste, yığın (stack), kuyruk (queue), ağaç ve çizge (graph) yapıları burada amaç değil, problem çözmek için kullanılan araçlardır.
  - Dersin ilk kısmı algoritmanın ne olduğu, nasıl analiz edildiği, iteratif ve özyinelemeli (rekürsif) algoritmaların analizi, en iyi/en kötü/ortalama durum, böl ve yönet algoritmalarının (merge sort, quicksort) analizi gibi konulardan oluşur.
  - İkinci kısım algoritma tasarım yöntemleridir: kaba kuvvet (brute force), azaltarak yönetme (decrease and conquer), böl ve yönet (divide and conquer), dönüştür ve yönet (transform and conquer), dinamik programlama, açgözlü (greedy) yaklaşım, geri izleme (backtracking), dal ve sınır (branch and bound), yer-zaman ödünleşimi (space and time trade-off).
  - Son kısım problem sınıfları (P, NP, NP-complete, NP-hard) ve alt sınırlar (lower bound) konusudur.
  - Ana kaynak A. Levitin, "Introduction to the Design and Analysis of Algorithms" kitabıdır; slaytlar kitabın 2. baskısına aittir. Yardımcı kaynak olarak Sedgewick'in "Algorithms" kitabı ve Cormen ve arkadaşlarının "Introduction to Algorithms" kitabı anıldı.
- Algoritmanın tanımı (ekrandan, 01:25:00)
  - Algoritma, bir problemi çözmek, yani her geçerli (legitimate) girdi için istenen çıktıyı sonlu bir sürede elde etmek için kullanılan, belirsizlik içermeyen (unambiguous) komutlar dizisidir.
  - Problem → algoritma → "bilgisayar"; girdi bilgisayara verilir, çıktı alınır.
- Algoritmanın özellikleri ve ifade biçimleri (ekrandan, 01:30:00)
  - İfade biçimleri: sözde kod (pseudocode), akış şeması (flowchart), programlama dili, sözlü anlatım.
  - Özellikler: açıklık/belirsizlik içermeme, etkinlik (effectiveness), sonluluk/sonlanma (finiteness/termination), doğruluk (correctness).
- OBEB (GCD) için üç yöntem
  - Ortaokul yöntemi: iki sayı asal çarpanlarına ayrılır, ortak çarpanlar çarpılır.
  - Ardışık tamsayı kontrolü (consecutive integer checking): $t = \min(m,n)$'den başlayıp $t$ iki sayıyı da bölene kadar birer azaltılır.
  - Öklid algoritması: $\gcd(m,n) = \gcd(n, m \bmod n)$, ikinci sayı 0 olunca ilk sayı sonuçtur.
- Algoritmanın üç temel yapısı
  - Sıralı (sequential), koşullu (conditional), tekrarlı (repetitive) işlemler.
- Seçmeli sıralama (selection sort), yerinde (in-place) olma ve kararlılık (stability)
- İyi bilinen hesaplama problemleri (ekrandan, 02:20:00)
  - Sıralama, arama, çizgede en kısa yol, en küçük kapsayan ağaç, asallık testi, gezgin satıcı problemi, sırt çantası problemi, satranç, Hanoi kuleleri, program sonlanması.
- Algoritmalarla ilgili temel sorunlar (ekrandan, 02:30:00)
  - Algoritma tasarımı, ifadesi, doğruluğunun ispatı, verimlilik analizi (teorik ve deneysel), optimallik.
- Temel veri yapılarının tekrarı
  - Dizi ve bağlı liste, yığın, kuyruk, öncelik kuyruğu/yığın (heap), çizge (komşuluk matrisi ve komşuluk listesi), ağaç ve ikili arama ağacı.

## Hocanın Özellikle Vurguladığı Kısımlar

- Belirsizlik içermeme
  - "Karesini al" gibi bir ifade algoritma adımı olamaz; adım "x * x" gibi tam tanımlı olmalıdır. Algoritma en sonunda makine diline ya da bir programlama diline çevrileceği için her adım o dilin kurallarıyla ifade edilebilmelidir.
  - İkinci dereceden denklem örneğinde "diskriminantı hesapla" demek yetmez; $\Delta = b^2 - 4ac$ diye açıkça yazılmalıdır.
- Verimliliğin iki kaynağı: zaman ve bellek
  - Zaman (CPU'nun işi bitirme süresi) ile bellek arasında bir ödünleşim vardır. Hocanın benzetmesi: İstanbul'dan Ankara'ya uçakla gitmek hızlı ama pahalı, yürümek ucuz ama yavaştır.
  - Merge sort ek bellek ister; 4 GB RAM'de 3 GB'lık bir dizi merge sort ile sıralanamaz.
- Doğru sonuç her şeyden önce gelir
  - Algoritma doğru sonuç vermiyorsa verimliliğinin bir anlamı yoktur.
- Öklid algoritması ardışık tamsayı kontrolünden çok daha hızlıdır
  - $\gcd(858, 30)$ için ardışık kontrol 30'dan 6'ya kadar 25 deneme yapar, Öklid algoritması birkaç adımda sonuca ulaşır.
- Veri yapıları bu derste araçtır
  - Bağlı liste, yığın, kuyruk, heap, öncelik kuyruğu, çizge ve ağaç işlemlerinin C kodunu yazabilmek gerekir. Dinamik bellek (malloc, calloc), struct, pointer ve dosya işlemleri bilinmelidir.
  - DFS yığınla, BFS kuyrukla gerçekleştirilir.
- Her problem için verimli bir algoritma yoktur
  - Bazı problemlerin verimli algoritması yoktur, bazılarının hiç algoritması yoktur (program sonlanması).

## Kısa Tekrar Notları

- Algoritma: belirsizlik içermeyen komutların, geçerli her girdi için sonlu sürede doğru çıktı üreten sıralı dizisi.
- Özellikler: açıklık, etkinlik, sonluluk, doğruluk.
- İfade biçimleri: sözde kod, akış şeması, programlama dili, sözlü anlatım.
- Üç temel yapı: sıralı, koşullu (`if`), tekrarlı (`while`, `for`).
- Öklid: $\gcd(m,n) = \gcd(n, m \bmod n)$, $\gcd(m,0) = m$.
  - $\gcd(18,4) = \gcd(4,2) = \gcd(2,0) = 2$.
  - $\gcd(858,30) = \gcd(30,18) = \gcd(18,12) = \gcd(12,6) = \gcd(6,0) = 6$.
- Ardışık tamsayı kontrolü: $t = \min(m,n)$, iki sayıyı da bölene kadar $t$ bir azaltılır.
- Ortaokul yöntemi: asal çarpanlara ayır, ortak çarpanları çarp; asal çarpanlara ayırma ayrıca tarif edilmesi gereken bir alt problemdir.
- Seçmeli sıralama: $i = 1..n$ için $a[i]$ ile $a[i..n]$'nin en küçüğü yer değiştirilir; iç içe iki döngü, kabaca $n^2$ işlem; yerinde çalışır, kararlı değildir.
- Teorik analiz: girdi boyutu $n$'ye bağlı $T(n)$ (zaman) ve $S(n)$ ya da $M(n)$ (bellek) fonksiyonları; $n \to \infty$ iken büyüme incelenir.
- Deneysel (empirical) analiz: zamanlayıcıyla $t_2 - t_1$ ölçülür ya da temel işlem (ör. karşılaştırma, swap) sayacı konur; farklı $n$ değerleri için grafik çizilir.
- Dizi bellekte ardışıktır, indisle erişim hızlıdır, araya ekleme/silme kaydırma gerektirir. Bağlı liste dağınık saklanır, ekleme/silme kaydırmasızdır.
- Seyrek (sparse) çizgede komşuluk listesi, komşuluk matrisinden daha az yer tutar.
- Ağaç: bağlı ve döngüsüz çizge; $|E| = |V| - 1$.
- Sıralı veri ile ikili arama ağacı doğrusal bir listeye dönüşür (1, 2, 3, 4, 5 örneği).

## Detaylı Açıklamalar

- **Algoritma ve problem ilişkisi.** Gerçek dünyadaki bir problem önce zihinde soyut olarak modellenir, sonra çözümün en alt birimi olan algoritma yazılır. Hoca algoritmayı çoğu zaman bir C fonksiyonu gibi düşünür: parametre olarak girdileri alır, gerekiyorsa bir değer döndürür. Bu fonksiyon iteratif de olabilir, kendini çağıran (özyinelemeli) bir fonksiyon da olabilir. Algoritmanın sonlu sürede bitmesi, girdi büyüdüğünde çıktıya ulaşma süresinin aşırı uzamaması anlamına da gelir. Sıra önemlidir: çözüm A, B, C adımlarını bu sırayla gerektiriyorsa B'yi A'dan önce yazmak doğru olmaz (ekrandan, 01:25:00).
- **OBEB örneği ve üç temel yapı.** $\gcd(4,18)$ için ardışık tamsayı kontrolünde $\min(4,18) = 4$'ten başlanır: $4 \bmod 4 = 0$ ama $18 \bmod 4 \ne 0$; $4 \bmod 3 \ne 0$; $4 \bmod 2 = 0$ ve $18 \bmod 2 = 0$, sonuç 2'dir (ekrandan, 01:40:00). Bu çözümde tekrarlı yapı (ne zaman biteceği belli olmadığı için `while`), koşullu yapı (bölünebilme kontrolü, `if`) ve sıralı yapı (önce bir sayının, sonra ötekinin kalanına bakmak) birlikte kullanılır. İlk sayı bölünmüyorsa ikinciye bakmaya gerek yoktur. Ortaokul yönteminde ise iki sayı en küçük asaldan başlayarak bölünür; ikisini birden bölen çarpanlar OBEB'i verir. Aynı tablodan OKEK de çıkar: $\text{OKEK}(4,18) = 3^2 \cdot 2^2 = 36$ (ekrandan, 01:40:00).
- **Öklid algoritması.** Büyük sayı sola, küçük sayı sağa yazılır; her adımda $(m, n) \to (n, m \bmod n)$ yapılır ve ikinci sayı 0 olunca durulur. $\gcd(18,4) = \gcd(4,2) = \gcd(2,0)$, sonuç 2'dir (ekrandan, 01:45:00). Her adımda yalnız bir mod işlemi ve bir kontrol yapılır; adım sayısı da azdır. Küçük sayılarda fark görünmez, ama $\gcd(858,30)$'da ardışık kontrol 30'dan 6'ya 25 deneme yaparken Öklid algoritması dört mod işleminde 6'yı bulur (ekrandan, 01:50:00). Bellek kullanımı iki yöntemde de neredeyse aynıdır (bir `min` ya da bir geçici değişken), fark zamandadır. Hocanın sözlü anlattığı döngü şöyledir (derste ayrı bir program yazılmadı; ajan Python ile aynı mantığı denedi):

  ```c
  while (s2 != 0) {
      t = s1 % s2;
      s1 = s2;
      s2 = t;
  }
  /* sonuç s1 */
  ```

- **Genişletilmiş Öklid algoritması.** Öklid algoritması geriye doğru işletilerek $7x - 8y = 1$ gibi bir eşitliği sağlayan $x, y$ tamsayıları bulunabilir (ekrandan, 01:50:00). Hoca bunun kriptolojide kullanıldığını söyledi ve bakılmasını tavsiye etti.
- **Seçmeli sıralama.** Slayttaki algoritma: `for i = 1 to n: swap a[i] with smallest of a[i], ..., a[n]` (ekrandan, 02:10:00). En küçüğün bulunması gizli bir iç döngüdür ve ayrıca tanımlanması algoritmayı daha açık yapar. Swap için tek bir geçici değişken gerekir: `tmp = a[i]; a[i] = a[j]; a[j] = tmp;` (ekrandan, 02:15:00). İç içe iki döngü kabaca $n^2$ işlem demektir; küçük dizilerde yeterli, çok büyük dizilerde verimsizdir. Dizi yerinde kaldığı ve yalnız bir ek değişken kullanıldığı için algoritma yerinde (in-place) çalışır. Counting sort ise diziyi başka bir alana taşır.
  - Ders sonrası not: Hoca kararlılığı (stability) "en küçük eleman kendisiyse elemanın kendisiyle gereksiz yere yer değiştirmesi" diye açıkladı. Doğrusu: kararlı bir sıralama, eşit anahtarlı elemanların ilk sıradaki göreli düzenini korur. Seçmeli sıralama kararlı değildir, çünkü uzak bir yer değiştirme eşit iki elemanın sırasını bozabilir. Örneğin $[2_a, 2_b, 1]$ dizisinde ilk adımda $2_a$ ile $1$ yer değiştirir ve sonuç $[1, 2_b, 2_a]$ olur.
- **Önemli problemler.** Gezgin satıcı probleminde kaba kuvvet bütün turları dener: A, B, C için A-C-B-A ve A-B-C-A; beş şehirde tur sayısı hızla artar (ekrandan, 02:25:00). Türkiye'nin 81 ili için başlangıç sabitlendiğinde $80!$ sıra denenmelidir; bu bilgisayarın işlem gücünü aşar. Sırt çantası probleminde hacim ve değer bilgisi olan nesnelerle, sınırlı hacimli bir torba en yüksek değerle doldurulmak istenir; deneme yanılma nesne sayısı büyüdükçe işin içinden çıkılmaz hale gelir. Hanoi kulelerinde disk sayısı arttıkça çözüm üstel hızla büyür. Program sonlanması probleminde verilen bir programın durup durmayacağına karar verecek bir program istenir. 100 karakterlik ve her karakteri 256 değerden biri olan bir parolada $256^{100}$ olasılık vardır; bu yüzden kaba kuvvet pratik değildir.
- **Doğruluk, kesin ve yaklaşık çözüm.** Doğruluk, test girdileri ve bilinen çıktılarla sınanır. Bazı problemlerde kesin (exact) çözüm bulmak pratikte mümkün değildir; genetik algoritma ya da karınca kolonisi gibi yöntemler kabul edilebilir bir çözüm verir (ekrandan, 02:30:00).
  - Ders sonrası not: Hoca bu kabul edilebilir çözüme "optimal solution" dedi. Literatürde optimal çözüm en iyi çözüm demektir; hocanın kastettiği, büyük olasılıkla optimale yakın yaklaşık (approximate) ya da sezgisel (heuristic) çözümdür.
- **Teorik ve deneysel analiz.** Teorik analizde girdi boyutuna bağlı $T(n)$ ve $S(n)$ fonksiyonları kurulur ve $n$ büyürken davranışları incelenir. Bu dersin ağırlığı bu kısımdadır. Deneysel analizde algoritmanın başına ve sonuna zamanlayıcı konup $t_2 - t_1$ ölçülür ya da temel işlem (sıralamada karşılaştırma ya da swap) bir sayaçla sayılır. Farklı $n$ değerleri için sonuçların grafiği doğrusal, üstel ya da sabit bir eğilim gösterebilir.
- **Tasarım stratejileri (ekrandan, 02:35:00).** Kaba kuvvet şimdiye kadar en çok kullanılan yaklaşımdır. Böl ve yönete örnek merge sort, azaltarak yönetmeye örnek özyinelemeli faktöriyeldir ($5!$ için $4!$ çağrılır). Açgözlü yaklaşım her zaman tam çözüm vermeyebilir ama kabul edilebilir bir toleransla sonuç verir. Dinamik programlama tekrarlı hesapları önler: $fib(3)$, $fib(2)$ ve $fib(1)$'i çağırır; $fib(2)$ de $fib(1)$ ve $fib(0)$'ı çağırır, yani $fib(1)$ iki kez hesaplanır.
- **Daha iyi algoritma var mı? (ekrandan, 02:45:00).** Sırasız bir dizide en büyük eleman, son elemana bakmadan kesin olarak bilinemez; bu bir alt sınırdır. Dizi küçükten büyüğe sıralıysa en büyük eleman son elemana tek bir bakışla bulunur. Slayta göre bu derste doğruluk (correctness) ispatı büyük ölçüde dışarıda bırakılır; ağırlık zaman ve bellek verimliliği, alt sınırlar ve optimallik üzerindedir.
- **Arama ve dizgi işleme.** Sırasız dizide doğrusal arama yapılır; dizi sıralıysa ikili arama (binary search) ya da interpolasyon araması (interpolation search) kullanılabilir. Bir dizgi içinde başka bir dizgi aranırken karşılaştırmaya baştan mı sondan mı başlamanın daha iyi olduğu ayrıca incelenecektir.
- **Temel veri yapıları (ekrandan, 02:50:00).** Dizi bellekte ardışık hücrelerde durur; indisle erişim kolaydır, ama araya ekleme ya da silmede elemanlar kaydırılır ve büyük bir ardışık bellek alanı bulunamayabilir. Bağlı liste düğümleri bellekte dağınık durur ve pointer ile bağlanır; tek yönlü listede yalnız sonraki, çift yönlü listede önceki ve sonraki düğümün adresi tutulur. Yığın son giren ilk çıkar (push/pop), kuyruk ilk giren ilk çıkar (enqueue/dequeue) mantığıyla çalışır. Öncelik kuyruğunda elemanlar önceliğe göre sıralanır; heap ile ya da doğrudan bir dizi üzerinde gerçekleştirilir ve heap sort ile işletim sistemi zamanlamasında kullanılır.
- **Çizgeler (ekrandan, 02:55:00).** Çizge $G = \langle V, E \rangle$, köşe kümesi $V$ ve köşe çiftlerinden oluşan kenar kümesi $E$ ile tanımlanır. Komşuluk matrisi 0-1 ya da ağırlık değerleri tutar; köşe çok, kenar az ise matris sıfırlarla dolar (seyrek çizge) ve komşuluk listesi daha uygundur. Ağırlıklı çizgede ağırlık mesafe, para ya da zaman olabilir. Yol, bir köşeden ötekine komşu köşeler dizisidir; bütün kenarları farklı olan yola basit yol denir. Bütün köşeler birbirine bağlıysa çizge bağlıdır (connected); değilse bağlı bileşenlerine (connected component) ayrılır. Başladığı noktaya dönen yol döngüdür (cycle); döngüsüz çizgeye asiklik denir, yönlü asiklik çizgeler DAG'dir.
- **Ağaçlar (ekrandan, 03:00:00).** Ağaç (serbest ağaç), bağlı ve döngüsüz bir çizgedir; döngüsüz ama bağlı olmak zorunda olmayan çizge ormandır. Ağaçta kenar sayısı köşe sayısının bir eksiğidir. Herhangi bir köşe kök seçilerek köklü ağaç elde edilir ve seviyeler oluşur. Ata, torun, ebeveyn, çocuk, kardeş ve yaprak kavramları vardır. Bir düğümün derinliği köke uzaklığıdır, ağacın yüksekliği en derin düğümün derinliğidir. İkili ağaçta her düğümün en çok iki çocuğu vardır. İkili arama ağacında büyük değer sağa, küçük (ya da eşit) değer sola gider: 10, 18, 7, 24 sırasıyla 10 köke, 18 sağa, 7 sola, 24 de 18'in sağına yerleşir. 1, 2, 3, 4, 5 sırayla eklenirse ağaç doğrusal bir bağlı listeye dönüşür; bunu düzelten dengeleme algoritmaları ileride görülecektir.
  - Ders sonrası not: Hoca bir yerde "döngü yoksa ağaç" dedi. Doğrusu, ağaç için çizgenin hem bağlı hem döngüsüz olması gerekir; bağlı olmayan döngüsüz çizge ormandır (slaytta da böyle yazıyor).

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
