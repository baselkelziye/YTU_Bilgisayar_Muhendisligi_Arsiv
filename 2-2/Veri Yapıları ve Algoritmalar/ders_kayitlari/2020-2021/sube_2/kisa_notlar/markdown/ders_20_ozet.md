# Ders 20 Çalışma Özeti

## Genel Konular

- Renkli BFS (önce genişlemesine arama)
  - Düğümlerin gezilme durumu üç renkle izlenir: beyaz (hiç dokunulmamış), gri (keşfedilmiş, kuyruğa girmiş), siyah (bütün komşuları işlenmiş, işi bitmiş).
  - Siyahın komşuları siyah ya da gri olabilir; grinin komşuları gri ya da beyaz olabilir.
  - Her düğüm için uzaklık `d` ve geldiği düğüm `p` (parent) tutulur. Parent zinciri geriye izlenerek başlangıçtan bir düğüme giden yol bulunur.
  - Yalnız beyaz komşular işlendiği için gri ve siyah düğümlere tekrar bakılmaz.
- Renkli DFS (önce derinlemesine arama)
  - Ek olarak global bir `time` sayacı tutulur. Düğüm griye boyanırken keşif zamanı `d[u]`, siyaha boyanırken bitiş zamanı `f[u]` yazılır.
  - Dış döngü bütün düğümleri dolaşıp beyaz kalan her düğümden yeni bir `DFS-VISIT` başlatır. Böylece yönlü grafta başlangıçtan erişilemeyen düğümler de gezilir.
  - `d` ile `f` arasındaki fark büyükse düğümden derin bir özyinelemeli dallanma yapılmıştır; fark 1 ise düğümden yeni bir çağrı başlamamıştır.
- Açgözlü (greedy) algoritmalar
  - Her adımda yapılabilir, yerel olarak en iyi ve geri alınamaz bir seçim yapılır.
  - Optimal çözüm verdiği örnekler: bozuk para üstü verme, minimum yayılan ağaç, tek kaynaklı en kısa yollar, basit çizelgeleme, Huffman kodlaması.
  - Yakın çözüm verdiği yaklaşımlar: gezgin satıcı problemi, sırt çantası problemi ve diğer kombinatoryal optimizasyon problemleri.
- Özyinelemeli (recursive) algoritmalar
  - Problem aynı cinsten ama daha küçük bir problemle ifade edilebilmelidir ve özyinelemeyi kesen bir durma koşulu olmalıdır.
  - Faktöriyel: $n! = n\cdot(n-1)!$ ($n>1$), aksi hâlde 1. Kendini bir kez çağırır, karmaşıklığı $O(n)$.
  - Fibonacci: $fib(n)=fib(n-1)+fib(n-2)$ ($n\ge 2$), aksi hâlde 1. Kendini iki kez çağırır, karmaşıklığı $O(2^n)$.
- Algoritmik çözüm yaklaşımlarının karşılaştırması
  - Kaba kuvvet (brute force): üs almada $n$ kez çarpma, selection sort, bubble sort.
  - Açgözlü: Huffman kodlaması, para üstü.
  - Azalt ve yönet (decrease and conquer): $a^n = a^{n-1}\cdot a$, insertion sort, Josephus problemi.
- Böl ve yönet (divide and conquer)
  - Problem genellikle eşit boyutlu, aynı tipte küçük problemlere bölünür; alt problemler genellikle özyinelemeli çözülür; bölünemeyecek kadar küçük problem bir yöntemle çözülür; alt çözümler birleştirilir.
  - Her zaman kaba kuvvetten daha verimli olmak zorunda değildir, ama kolayca paralel hesaplamaya uygundur.
- Top-down Merge Sort
  - Dizi `lo`–`hi` aralığında, `mid = lo + (hi - lo)/2` noktasından ikiye bölünür; iki yarı ayrı ayrı sıralanır, sonra `Merge` ile birleştirilir.
  - Tek elemanlı parça zaten sıralıdır; asıl iş birleştirme (merge) aşamasındadır.
  - Merge için sıralanan dizi kadar ek bir yardımcı (aux) diziye ihtiyaç vardır.

## Hocanın Özellikle Vurguladığı Kısımlar

- Renk kodlaması
  - Grafın herhangi bir anında hangi düğümlerin hiç görülmediği, hangilerinin işlendiği ve hangileriyle işin bittiği takip edilebilir. Bu takip ileride en kısa yol gibi graf algoritmalarında yolu (path) izlemek için kullanılır.
- DFS'in dış döngüsü
  - Eski DFS başlangıç düğümünden erişilebilen düğümler bitince durur. Renkli DFS beyaz düğüm kaldıkça yeni bir gezinti başlatır, böylece grafın tamamı keşfedilir.
- Özyinelemede durma noktası
  - Faktöriyel için `if (n <= 1) return 1;` yazılması negatif girişlerde de sorunu önler. Slayttaki `return n;` hâli `fact(0)` için 0 döndürür.
- Birden fazla özyinelemeli çağrının maliyeti
  - Kendini bir kez çağıran faktöriyel doğrusal, kendini iki kez çağıran Fibonacci üstel ($2^n$) büyür. Fibonacci çağrı ağacında aynı alt ağaçlar tekrar tekrar hesaplanır; bu nedenle düz özyinelemeli Fibonacci iyi bir çözüm değildir.
- Böl ve yönetin gücü paralelleştirmeden gelir
  - Tek işlemcide her zaman daha hızlı olmayabilir. Parçalar farklı çekirdeklerde aynı anda çözülürse toplam süre kısalır; birleştirme aşaması ayrıca bir ek yük (overhead) getirir.
- Merge Sort'ta zor olan birleştirmedir
  - Bölmek kolaydır (yalnız `mid` hesaplanır); sıralı iki parçayı sırayı bozmadan birleştirmek asıl işlemdir.

## Kısa Tekrar Notları

- Renkli BFS: beyaz → gri (kuyruğa girerken) → siyah (komşuları bitince). `v.d = u.d + 1`, `v.p = u`.
- BFS FIFO kuyruk kullanır; önce birinci derece komşular, sonra ikinci derece komşular işlenir.
- Renkli DFS: `time` sayacı; gri olurken `d[u] = ++time`, siyah olurken `f[u] = ++time`.
- DFS'te dış döngü beyaz kalan her düğümden yeniden başlar.
- Greedy: yapılabilir, yerel optimum, geri alınamaz seçim. 48 kuruş para üstü: 25 + 10 + 10 + 1 + 1 + 1.
- Huffman kodlaması greedy'dir: her adımda en küçük frekanslı iki düğüm birleştirilir.
- Özyineleme için iki koşul: aynı tipte daha küçük alt problem ve durma koşulu.
- Faktöriyel $O(n)$; özyinelemeli Fibonacci $T(n)=T(n-1)+T(n-2)+c$, $O(2^n)$.
- Böl ve yönet: böl, alt problemleri çöz, birleştir.
- Merge Sort: `mid = lo + (hi - lo)/2`; `MergeSort(A, lo, mid)`, `MergeSort(A, mid+1, hi)`, `Merge(A, lo, mid, hi)`.
- Merge: sol parça bittiyse sağdan, sağ parça bittiyse soldan kopyala; ikisi de varsa küçük olanı çıktıya yaz. Eşitlikte sol parçadan alınır.

## Detaylı Açıklamalar

Renkli BFS, başlangıç düğümü `s` dışındaki bütün düğümleri beyaza boyar, uzaklıklarını $\infty$, parent değerlerini NIL yapar. `s` griye boyanır, uzaklığı 0 olur ve kuyruğa eklenir. Kuyruk boşalana kadar baştaki düğüm `u` çekilir. `u`'nun her beyaz komşusu `v` griye boyanır, `v.d = u.d + 1` ve `v.p = u` yapılır, `v` kuyruğa eklenir. `u`'nun bütün komşuları bittiğinde `u` siyaha boyanır (ekrandan, 00:25:00). Slayttaki 8 düğümlü yönsüz grafta (`r, s, t, u` üstte, `v, w, x, y` altta) `s`'den başlanınca uzaklıklar `r=1, w=1, t=2, x=2, v=2, u=3, y=3` olur. Kuyruk sırası `s, w, r, t, x, v, u, y`'dir (ekrandan, 00:20:00). Örneğin `v`'nin parent'ı `r`, `r`'nin parent'ı `s` olduğundan `s → r → v` yolu bulunur.

Renkli DFS'te bütün düğümler önce beyaza boyanır ve `time = 0` yapılır. Dış döngü her beyaz düğüm için `DFS-VISIT(u)` çağırır. `DFS-VISIT(u)` önce `u`'yu griye boyar, `time`'ı bir artırıp keşif zamanını `d[u]`'ya yazar. Sonra `u`'nun her beyaz komşusu için kendini çağırır. Komşular bitince `u` siyaha boyanır, `time` bir artırılır ve bitiş zamanı `f[u]`'ya yazılır (ekrandan, 00:30:00). Slayttaki yönlü grafta `u`'dan başlanınca `u 1/8, v 2/7, y 3/6, x 4/5` elde edilir. `w` ve `z` bu gezintide erişilemez; dış döngü `w`'dan yeniden başlar ve `w 9/12, z 10/11` olur (ekrandan, 00:35:00). Yönsüz labirent grafında `0`'dan başlanınca keşif/bitiş zamanları `0: 1/12, 2: 2/11, 1: 3/4, 3: 5/10, 5: 6/7, 4: 8/9` olur (ekrandan, 00:45:00).

Açgözlü yaklaşımda her adım o anki en iyi seçimdir ve sonradan değiştirilmez. Para üstü probleminde bozuk paralar 1 TL, 50, 25, 10, 5 ve 1 kuruştur. 48 kuruş için her adımda kalan miktarı en çok azaltan para seçilir: 25 (23 kaldı), 10 (13 kaldı), 10 (3 kaldı), 1, 1, 1 (ekrandan, 01:00:00). Huffman kodlamasında da her adımda en düşük frekanslı iki düğüm birleştirilir.

Özyinelemeli bir algoritma problemi aynı tipte daha küçük bir problem cinsinden yazar ve bir durma koşulunda doğrudan bir değer döndürür. Faktöriyelde `fact(5)` çağrısı `5 * fact(4)`, o da `4 * fact(3)` diye `fact(1) = 1`'e kadar iner; sonra değerler geri dönerek $2, 6, 24, 120$ elde edilir. Fibonacci'de ise her çağrı iki çağrı yapar. Zaman bağıntısı $T(n)=T(n-1)+T(n-2)+c$'dir. Üstten sınırlamak için $T(n-2)\approx T(n-1)$ alınırsa:

$$T(n) = 2T(n-1)+c = 4T(n-2)+3c = 8T(n-3)+7c = 2^k T(n-k) + (2^k-1)c$$

$k=n$ için $T(n) = 2^n T(0) + (2^n-1)c = 2^n(1+c) - c$, yani $O(2^n)$ olur (ekrandan, 01:40:00).

Böl ve yönet yaklaşımında Merge Sort, diziyi tek elemanlı parçalara kadar böler. Örneğin `3 5 2 1 8 4 6 9` önce `3 5 2 1 | 8 4 6 9`, sonra ikililere ve tekillere bölünür. Birleştirme aşamasında `3 5`, `1 2`, `4 8`, `6 9`; sonra `1 2 3 5`, `4 6 8 9`; en sonda `1 2 3 4 5 6 8 9` elde edilir. Merge işlemi önce `lo..hi` aralığını `aux` dizisine kopyalar. Sonra `i = lo`, `j = mid + 1` ile her `k` için şu kontrol yapılır: `i > mid` ise sağdan al; `j > hi` ise soldan al; `aux[j] < aux[i]` ise sağdan al; değilse soldan al (ekrandan, 02:25:00). `EEGMR | ACERT` dizisinin birleştirilmesi `ACEEEGMRRT` sonucunu verir (ekrandan, 02:30:00).

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
