# Ders 12 Çalışma Özeti

## Genel Konular

- Oturumun niteliği: birinci ödevin çözümü
  - Bu oturum bir uygulama oturumudur. Birinci ödevdeki iki problem slayt üzerinden sözde kodla, sonra C koduyla çözüldü. Odak kod söz diziminden çok algoritmik düşünceyi kurmaktır.
- Problem 1: tek boyutta en yakın iki eleman
  - Soru: $N$ elemanlı bir dizide birbirine en yakın değere sahip iki eleman bulunacak. (a) brute-force çözüm C ile yazılıp verimliliği analiz edilecek; (b) brute-force'tan daha az karmaşık bir algoritmik yöntemle çözülüp analiz edilecek ve C ile kodlanacak (ekrandan, 00:20:00).
  - Dizi tek boyutludur. Elemanlar bir doğru üzerinde, $y$ koordinatı 0 olan karışık noktalar gibi düşünülür.
- Brute-force (kaba kuvvet) çözüm
  - Her eleman kendinden sonraki bütün elemanlarla karşılaştırılır. Tek boyut olduğu için uzaklık mutlak değer farkıdır.
  - Minimum başlangıçta çok büyük bir değere (örn. float'ın en büyük değeri) kurulur. Daha küçük fark bulununca minimum ve iki nokta güncellenir.
  - Karmaşıklık $O(n^2)$.
- Böl ve yönet (divide and conquer) çözümü
  - Önce dizi verimli bir sıralama algoritmasıyla sıralanır.
  - Adımlar (ekrandan, 00:30:00):
    - $m = \text{median}(S)$
    - $S$, $m$ noktasında $S_1$ ve $S_2$'ye bölünür.
    - $\delta_1 = \text{Closest-Pair}(S_1)$, $\delta_2 = \text{Closest-Pair}(S_2)$
    - $\delta_{12}$: kesimin iki yanı arasındaki en küçük uzaklık.
    - Sonuç: $\delta = \min(\delta_1, \delta_2, \delta_{12})$.
  - Yalnız iki yarının en iyilerini karşılaştırmak yetmez. Örnekte $p_3$ sol yarıda, $q_3$ sağ yarıdadır; ikisi birbirine çok yakındır ama bölme yüzünden karşılaştırılmaz. Bu yüzden orta noktanın iki yanında $d$ uzaklığındaki noktalar (şerit, strip) ayrıca incelenir.
  - Eleman sayısı 3 veya daha azsa artık bölmenin anlamı yoktur; brute-force ile sonuç döndürülür (özyinelemenin durma koşulu).
- Quicksort mu, merge sort mu
  - Quicksort'un en kötü durumu $O(n^2)$'dir. Pivot ilk eleman seçilir ve dizi sıralıysa (ya da pivot hep en küçük/en büyük eleman olursa) dizi ikiye bölünemez.
  - Merge sort en kötü durumda da $O(n \log n)$ garanti eder ama $O(n)$ ek bellek ister. Quicksort pratikte daha çok kullanılır.
- Sıralamadan sonra tek döngü
  - Bir öğrencinin önerisi: sıralı dizide en yakın çift mutlaka ardışık iki elemandır. Sıralamadan sonra $a_i$ ile $a_{i+1}$ karşılaştırılır ($n-1$ karşılaştırma, $O(n)$). Toplam $O(n \log n) + O(n) = O(n \log n)$. Asistan aynı karmaşıklığı verdiği için bu çözümü kabul etti.
- Problem 2: Von Neumann komşuluğu
  - Merkez $(x_0, y_0)$ olmak üzere $N_{(x_0,y_0)} = \{(x,y) : |x-x_0| + |y-y_0| \le r\}$. Manhattan uzaklığı $r$'den küçük veya eşit olan hücreler siyah (1) yapılır; şekil baklava (diamond) biçimindedir (ekrandan, 00:50:00).
  - Toplam siyah hücre sayısı $2r(r+1)+1$ (Delannoy sayıları). Matris boyutu $2n+3$ (ödevde yarıçap $n$ diye verilmiş) (ekrandan, 00:50:00).
  - Satır başına siyah hücre sayısı 1, 3, 5, ... diye artıp yeniden azalır.
- Özyinelemeli çözüm (ekrandan, 00:55:00)
  - `vonNeumann(row, col)`: hücrenin merkeze Manhattan uzaklığı $\le n$ ise hücre 1 yapılır; sütun artırılır; son sütuna gelinince sütun 0'lanır, satır artırılır; satır < size ise fonksiyon kendini yeniden çağırır.
  - Matris `calloc` ile ayrıldığı için hücreler zaten 0'dır; ayrıca 0 atamaya gerek yoktur.
- Yinelemeli (iteratif) karşılığı
  - Aynı mantık bir `while` döngüsüyle yazılabilir: satır size'dan küçük olduğu sürece hücre kontrol edilir, sütun ilerletilir, son sütunda satır artırılır.
- İki boyutlu dinamik bellek ayırma
  - Önce satır işaretçileri dizisi (`int**`), sonra bir döngüyle her satır `calloc` ile ayrılır. Matris tek boyutlu, size $\times$ size uzunlukta bir dizi olarak da tutulabilir (ekrandan, 01:10:00).

## Hocanın Özellikle Vurguladığı Kısımlar

- Algoritmik düşünce koddan önce gelir
  - Asıl beklenen, problemi uygun algoritma yapısıyla kurabilmektir. Bir soru belirli bir yaklaşıma (örn. böl ve yönet) bağlıysa o yaklaşımla çözülmelidir.
- Birleştirme adımı unutulmamalı
  - Böl ve yönette yalnız iki yarının sonucunu karşılaştırmak yanlış sonuç verebilir; orta noktanın $d$ yakınındaki elemanlar da incelenmelidir.
- Quicksort'ta pivot seçimi karmaşıklığı belirler
  - Kötü pivot (en küçük ya da en büyük eleman) diziyi bölemez ve $O(n^2)$'ye götürür.
- Özyinelemeden kaçmak için kaçmamak
  - Özyineleme yığın taşması (stack overflow) ve bellek kullanımı riski taşır, ama bu onu hiç kullanmamak için gerekçe değildir. Kurala göre sürekli büyüyen, üst üste binen bir yapı (Von Neumann şekli gibi) özyinelemeli bir yaklaşımı akla getirmelidir.
- Hazır fonksiyonlara yaslanmamak
  - Kütüphanedeki `qsort` kullanılabilir ama ödevlerde algoritmanın kendisinin yazılması tercih edilir.

## Kısa Tekrar Notları

- Tek boyutta en yakın çift: brute-force $O(n^2)$.
- Sırala + böl ve yönet: $\delta = \min(\delta_1, \delta_2, \delta_{12})$; taban durumu $n \le 3$ için brute-force.
- Sıralı dizide en yakın çift ardışıktır: sıralama + tek döngü $O(n \log n)$.
- Quicksort en kötü $O(n^2)$ (kötü pivot); merge sort $O(n \log n)$ ama $O(n)$ ek bellek.
- Von Neumann komşuluğu: $|x-x_0|+|y-y_0| \le r$; siyah hücre $2r(r+1)+1$; matris $2n+3$.
- $r = 0, 1, 2, 3$ için siyah hücre sayısı $1, 5, 13, 25$.
- İki boyutlu dizi: `int**` + her satıra `calloc`; `calloc` sıfırla başlatır.

## Detaylı Açıklamalar

Birinci problemde dizi tek boyutlu olduğu için noktalar bir doğru üzerinde karışık sırada durur. Kaba kuvvet çözümünde iç içe iki döngüyle her çift bir kez karşılaştırılır ve en küçük mutlak fark ile o farkı veren iki eleman tutulur. Bu yaklaşım hiçbir algoritmik fikir kullanmaz ve $O(n^2)$ karşılaştırma yapar.

Böl ve yönet çözümünde önce dizi sıralanır. Sonra `closestPoint` fonksiyonu diziyi orta indiste ikiye böler (`mid = size/2`, `midPoint = P[mid]`), sol yarı için `closestPoint(P, mid)`, sağ yarı için `closestPoint(P + mid, size - mid)` çağrılır. `P + mid` dizinin orta noktadan başlayan kısmını, `size - mid` de o kısmın uzunluğunu verir; böylece sol yarı atılmış olur. İki sonucun küçüğü $d$'dir. Ardından bütün elemanlar taranır ve `|P[i] - midPoint| < d` olanlar `strip` dizisine konur. Şeritteki en küçük uzaklık bulunur ve `min(d, min_strip)` döndürülür (ekrandan, 00:35:00). Eleman sayısı 3 veya daha azsa fonksiyon doğrudan brute-force sonucunu döndürür. Özyineleme önce sol tarafı en küçük parçalara kadar böler, sol taraf bitince sağ tarafa geçer.

C kodunda `qsort(P, n, sizeof(int), cmpfunc)` ile sıralama yapılır ve `closestUtil(P, n)` çağrılır. Örnek dizi `{9, 5, 0, 20, 35, 1, 11}`dir (ekrandan, 01:05:00). Sıralanmış hali $0, 1, 5, 9, 11, 20, 35$; en küçük uzaklık 1'dir (0 ile 1). Bu değer python ile hem brute-force hem böl ve yönetle doğrulandı. Asistan, en yakın elemanları da döndürmek için bir yapı (struct) ya da işaretçi kullanılabileceğini belirtti.

İkinci problemde matris boyutu $2n+3$'tür: şekil her yöne $n$ kadar uzanır ($2n$), merkez hücre (+1) ve iki yanda birer boş satır/sütun (+2) eklenir. Siyah hücre sayısı $2r(r+1)+1$ formülüyle bulunur; $r=3$ için $9 \times 9$ matriste satır başına siyah hücreler $0, 1, 3, 5, 7, 5, 3, 1, 0$ olur ve toplam 25'tir (python ile doğrulandı). Asistanın çözümünde her çağrı bir hücreye bakar, sütunu ilerletir ve satır sona gelince bir alt satıra geçer; çağrı sayısı tek, iki ya da dört olabilir, önemli olan aynı karmaşıklıkta etkili bir yaklaşım kurmaktır. Kodda satır başına siyah hücre sayısı `rowBlac` dizisinde tutulup yazdırıldı (ekrandan, 01:10:00).

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
