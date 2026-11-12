# Ders 3 Çalışma Özeti

## Genel Konular

- Kaba kuvvet (brute force) algoritmaları
  - Problemin en bariz çözümünü doğrudan koda döker; gücünü bilgisayarın donanımından ve hızından alır. Tasarım maliyeti düşüktür, küçük veri boyutlarında mantıklıdır, veri büyüyünce uygulanamaz hâle gelir.
  - $a^n$'i $a \cdot a \cdots a$ diye $n$ kez çarparak hesaplamak $O(n)$'dir; $a^{16}$'yı $a^8$'den bulmak gibi daha kısa yollar vardır.
  - Örnekler: matris çarpımı ($n^3$), bubble sort ($n^2$), sıralı arama (sequential search, $n$), seçmeli sıralama (selection sort) ve dizgi eşleme (string matching).
  - Selection sort (ekrandan, 00:09:15): her turda kalan kısmın en küçüğü bulunur ve turun başındaki elemanla yer değiştirir. $C(n) = \sum_{i=0}^{n-2}\sum_{j=i+1}^{n-1} 1 = \sum_{i=0}^{n-2}(n-1-i) = \frac{(n-1)n}{2} \in \Theta(n^2)$. Takas (swap) sayısı yalnız dış döngüye bağlıdır.
  - Kaba kuvvet dizgi eşleme (ekrandan, 00:10:00): `for i ← 0 to n − m`, içeride `while j < m and P[j] = T[i + j]` ile ilerlenir; `j = m` ise `i` döner, yoksa $-1$. En kötü durum $O(nm)$, en iyi durum $1$ karşılaştırma; ortalama durum pratikte en iyi duruma daha yakındır.
  - Kareler toplamı, dizideki en büyük ile en küçük farkı ve matrisin simetrik olup olmadığını kontrol eden (geçen haftaki) algoritmalar da düz yinelemeli yazıldıklarında kaba kuvvettir.
- Ağ topolojisi alıştırması (ekrandan, 00:20:00, 00:22:30, 00:23:45)
  - Ring, star ve fully connected mesh topolojileri 0-1 komşuluk matrisiyle verilir; hangi topoloji olduğunu bulan ya da doğrulayan kaba kuvvet algoritmaları tasarlanır.
  - Ring doğrulama: her satırda yalnız $i-1$ ve $i+1$ (mod $n$) sütunları 1'dir; satır satır kontrol $\Theta(n)$. Tanıma (identification) için tüm matris taranır, $n^2$.
  - Star: merkez düğümün satırı ve sütunu boyunca 1'ler, "artı" biçiminde bir desen; ilk satırdaki ilk 1'den sütuna ve satıra inilerek $\Theta(n)$ ile kontrol edilir.
  - Fully connected mesh: köşegen 0, geri kalan her yer 1. Star algoritması ek kontrol olmadan bunu da star sanabilir; kesin karar için tüm matris gezilir, $n^2$.
- Ayrıntılı arama (exhaustive search)
  - Kombinatorik problemlere özgü kaba kuvvettir: bütün aday çözümler (permütasyonlar, kombinasyonlar) üretilir, koşulu sağlayan ve en iyisi seçilir. Örnekler: sırt çantası (knapsack), atama (assignment), gezgin satıcı (traveling salesman).
  - Atama problemi (ekrandan, 00:30:00): $n$ kişi $n$ işe atanır, maliyet matrisi verilir. $\langle 2,3,4,1\rangle$ gösterimi: 1. kişi 2. işe, 2. kişi 3. işe... $1,\dots,n$'in tüm permütasyonları üretilir, her birinin maliyeti hesaplanır, en küçüğü seçilir. Karmaşıklık $n!$.
  - Sıralamaya uygulanırsa: $n!$ permütasyon, her biri için $n-1$ sıra kontrolü; $n!\,(n-1) < (n+1)!$, yani $O((n+1)!)$.
  - Hamilton çevrimi (ekrandan, 00:36:20): her düğümden bir kez geçen ve başladığı yerde biten tur. Düğümlerin permütasyonları ($n!$) üretilir, ardışık düğümler arasında ve son ile ilk düğüm arasında kenar olup olmadığı kontrol edilir ($n-1$); yine $O((n+1)!)$.
- Azalt ve fethet (decrease and conquer)
  - Bir problem örneğinin çözümü ile daha küçük bir örneğinin çözümü arasındaki ilişki kullanılır. Yukarıdan aşağı (özyinelemeli) ya da aşağıdan yukarı uygulanabilir.
  - Üç türü vardır: sabit kadar azaltma (decrease by a constant), sabit çarpanla azaltma (decrease by a constant factor), değişken boyutlu azaltma (variable size decrease).
  - Bir azaltma (ekrandan, 00:40:00): $f(n) = f(n-1)\cdot a$ ($n>0$), $f(0) = 1$. Aşağıdan yukarı hâli $a \cdot a \cdots a$'dır; verimlilik kazancı yoktur, $n$.
  - Yarıya azaltma (ekrandan, 00:42:20): $a^n = (a^{n/2})^2$ ($n$ çift ve pozitif), $(a^{(n-1)/2})^2 \cdot a$ ($n$ tek), $1$ ($n=0$). Karmaşıklık $\Theta(\log n)$.
  - Değişken boyutlu azaltma: Öklid algoritması, $\gcd(u, v) = \gcd(v, u \bmod v)$. $\gcd(180,146) \to \gcd(146,34) \to \gcd(34,10) \to \gcd(10,4) \to \dots$; her adımdaki azalma miktarı farklıdır.
  - İkili arama (binary search) sabit çarpanla azaltmanın tipik örneğidir: `l = 0`, `r = n − 1`, `m = ⌊(l + r)/2⌋`; $K < A[m]$ ise `r = m − 1`, büyükse `l = m + 1`. En kötü durum $\lfloor \log_2 n \rfloor + 1$ karşılaştırma.
- İkili arama alıştırması (ekrandan, 01:10:00 ve 01:12:20)
  - Dizi: 3, 14, 27, 31, 39, 42, 55, 70, 74, 81, 85, 93, 98 ($n = 13$). En fazla karşılaştırma $\lfloor\log_2 13\rfloor + 1 = 4$.
  - Arama ağacı: kök 55; ikinci seviye 27 ve 81; üçüncü seviye 3, 39, 70, 93; yapraklar 14, 31, 42, 74, 85, 98. En çok karşılaştırma isteyen anahtarlar yapraklardır.
  - Başarılı aramada ortalama karşılaştırma: $C_{avg}^{yes} = \frac{1\cdot1 + 2\cdot2 + 4\cdot3 + 6\cdot4}{13} = \frac{41}{13} \approx 3{,}15$.
- Böl ve fethet (divide and conquer)
  - Problem aynı tipte, mümkünse eşit boyutlu alt problemlere bölünür; alt problemler genelde özyinelemeli çözülür; sonuçlar birleştirilir (merge).
  - $n$ sayıyı iki yarıya bölerek toplamak mümkündür ama verimli değildir; böl ve fethet her zaman verimli olmaz, paralel çalıştırmada avantaj sağlar.
  - Azalt ve fethetten farkı: azalt ve fethet veriyi bölmez, parça ile bütün arasındaki matematiksel ilişkiyi kullanır; böl ve fethet veriyi böler, her parçayı ayrı çözer ve birleştirir.
- Master teoremi (ekrandan, 01:20:00)
  - $T(n) = aT(n/b) + f(n)$, $f(n) \in \Theta(n^d)$, $d \ge 0$ ise: $a < b^d$ için $\Theta(n^d)$; $a = b^d$ için $\Theta(n^d \log n)$; $a > b^d$ için $\Theta(n^{\log_b a})$. Aynı sonuçlar $O$ ve $\Omega$ için de geçerlidir.
  - $n$ sayının toplamı (ekrandan, 01:22:00): $A(n) = 2A(n/2) + 1$; $a = 2$, $b = 2$, $d = 0$, $a > b^d$, $A(n) \in \Theta(n^{\log_2 2}) = \Theta(n)$.
- Birleştirmeli sıralama (merge sort)
  - Dizi tek eleman kalana kadar ikiye bölünür, sonra sıralı parçalar Merge ile birleştirilir. Merge üç indisle çalışır: `B[i] ≤ C[j]` ise `B[i]` A'ya yazılır ve `i` artar, değilse `C[j]` yazılır ve `j` artar; biri biterse diğerinin kalanı sona eklenir.
  - Örnek: 8, 3, 2, 9, 7, 1, 5, 4 → 3 8 | 2 9 | 1 7 | 4 5 → 2 3 8 9 | 1 4 5 7 → 1 2 3 4 5 7 8 9.
  - Analiz (ekrandan, 01:30:00): $C(n) = 2C(n/2) + C_{merge}(n)$, $C(1) = 0$. En kötü durumda $C_{merge}(n) = n-1$ (örnek: 1, 3, 5, 7 ile 2, 4, 6, 8; sırayla iki diziden alınır, 7 karşılaştırma). $C_{worst}(n) = n\log_2 n - n + 1$.
  - Master teoremiyle: $a = 2$, $b = 2$, $d = 1$, $a = b^d$, $\Theta(n \log n)$.
- Dışbükey örtü (convex hull)
  - Düzlemde $n$ nokta verilir; hepsini içine alan en küçük dışbükey çokgen bulunur. Kabul: iki noktanın x ya da y koordinatı aynı değildir. Örtü çift yönlü bağlı listeyle saklanabilir. Kullanım alanları: graf teorisi, örüntü tanıma, coğrafi bilgi sistemleri.
  - Kaba kuvvet (ekrandan, 01:40:00): her nokta çifti için doğru $ax + by = c$ kurulur; diğer bütün noktalar denkleme konur. İşaretler hep aynıysa (bütün noktalar doğrunun bir tarafındaysa) bu kenar örtüye aittir. $O(n^2)$ kenar, her biri için $O(n)$ test: $O(n^3)$.
  - Böl ve fethet: noktalar x'e göre sıralanır, iki gruba (A, B) ayrılır; sabit zamanda çözülebilecek boyuta (örneğin 3 nokta) kadar bölünür. Asıl iş birleştirmedir: üst ve alt teğet bulunur.
  - Birleştirme, kaba hâli: A'daki x'i en büyük nokta $a_1$ ile B'deki x'i en küçük nokta $b_1$ arasından dikey L doğrusu geçirilir. Her $(a_i, b_j)$ çifti için doğrunun L'yi kestiği yükseklik $y(i,j)$ hesaplanır; en büyüğü üst teğettir. $n^2$; $T(n) = 2T(n/2) + n^2 \Rightarrow \Theta(n^2)$.
  - Birleştirme, iyileştirilmiş hâli (ekrandan, 02:00:00): $i = j = 1$ ile başlanır; `while (y(i, j+1) > y(i, j) or y(i−1, j) > y(i, j))` döngüsünde, `y(i, j+1) > y(i, j)` ise sağ parmak saat yönünde ilerler ($j = j + 1 \bmod q$), değilse sol parmak saat yönünün tersine ilerler ($i = i - 1 \bmod p$). Döngü bitince $(a_i, b_j)$ üst teğettir; alt teğet benzer şekilde bulunur. Birleştirme $n$'e iner; $a = 2$, $b = 2$, $d = 1$, $\Theta(n \log n)$.
  - İki örtünün yalnız en yüksek noktalarını birleştirmek doğru teğeti vermez (karşı örnek: en yüksek noktalar $a_4$-$b_2$ iken doğru teğet $a_3$-$b_1$).
- Medyan bulma (median finding, selection)
  - $n$ elemanlı sırasız dizide $i$. sıradaki elemanı bulmak; medyan $\frac{n+1}{2}$. sıradaki elemandır. Sıralayıp almak $n\log n$'dir; amaç bunun altına inmektir.
  - SELECT(S, i) (ekrandan, 02:20:00): bir $x \in S$ seçilir (pivot), $k = rank(x)$; $B = \{y < x\}$ ($k-1$ eleman), $C = \{y > x\}$ ($h-k$ eleman). $k = i$ ise $x$ döner; $k > i$ ise SELECT(B, i); $k < i$ ise SELECT(C, i − k).
  - Derste izlenen örnek (ekrandan, 02:30:00): S = 8, 9, 5, 14, 7, 13, 21, 6, 12, 3, 16; medyan 9 bulundu.
  - Dengeli bölme varsayılırsa $T(n) = T(n/2) + n$: $a = 1$, $b = 2$, $d = 1$, $\Theta(n)$. Her seferinde $7n/10$'luk parça kalsa bile $b = 10/7$, $a < b^d$, yine $\Theta(n)$.
  - En kötü durum: pivot her seferinde en küçük ya da en büyük seçilirse $n, n-1, n-2, \dots$ boyutlu bölmeler yapılır; gerçek çalışma süresi $O(n^2)$ (ekrandan, 02:40:00).
  - Medyanların medyanı: dizi 5'erli sütunlara ayrılır ($\lceil n/5 \rceil$ sütun), her sütun sabit zamanda sıralanır, sütun medyanları alınır, bunların medyanı SELECT ile özyinelemeli bulunur ve pivot yapılır. Örnek (ekrandan, 02:42:20): sütun medyanları 8, 6, 10, 4, 7; medyanların medyanı 7.
  - Sonsuz özyinelemeyi önlemek için çıkış koşulu: eleman sayısı makul bir sabitin altına inince dizi doğrudan sıralanır.
  - Özyineleme bağıntısı (ekrandan, 02:50:00): en az $3(\lceil n/10 \rceil - 2) \approx 3n/10 - 6$ eleman $x$'ten büyüktür (simetrik olarak küçüktür). $T(n) = O(1)$ ($n \le 140$), $T(n) = T(\lceil n/5 \rceil) + T(7n/10 + 6) + \Theta(n)$ ($n > 140$). Çözümü (master teoremi uygulanamadığı için tümevarımla yerine koyma) sonraki derse kaldı.

## Hocanın Özellikle Vurguladığı Kısımlar

- Kaba kuvveti küçümsememek
  - Kaba kuvvet ve ayrıntılı arama kolay gerçeklenir; küçük girdilerde hızla sonuca götürür. Önemli olan probleme uygun çözümü seçmektir.
- Azalt ve fethet ile böl ve fethet ayrı mekanizmalardır
  - Bir öğrencinin sorusu üzerine hoca, $2^8$'i $2^4$ üzerinden, $2^9$'u $2^4 \cdot 2^4 \cdot 2$ diye bulmanın veriyi bölmek olmadığını, yalnız parça-bütün ilişkisini kullanmak olduğunu açıkladı. Böl ve fethette dizi ya da matris bölünür, her parça ayrı çözülür.
- Ayrıntılı aramada $n!$ neden alınır
  - Hamilton çevriminde bütün düğümler birbirine bağlı olmadığı için gerçek aday sayısı $n!$'den azdır. Ama ayrıntılı aramanın mantığı, bilgisayar gücüyle bütün permütasyonları döküp sonra bağlantıları kontrol etmektir; yalnız bağlı düğümler üzerinden permütasyon üretmek ek kontrol ister.
- Formülü rakamla görmek
  - Ortalama karşılaştırma örneğinde hoca, önce rakam koyup sonra genellemenin formül çıkarmayı kolaylaştırdığını söyledi.
- Böl ve fethette asıl iş birleştirmedir
  - Dışbükey örtüde bölmek kolaydır; küçük örtüleri doğru bir büyük örtüye birleştirecek mekanizma önemlidir ve karmaşıklığı o belirler.
- Pivot seçimi karmaşıklığı belirler
  - Medyan bulmada pivot dengeli bölmelidir. Tam yarıya bölünemese de sabit oranlı bölme $\Theta(n)$'i korur; en küçük ya da en büyük seçilirse $n^2$ olur.
- Özyinelemede çıkış koşulu
  - Hangi dilde yazılırsa yazılsın özyinelemeli fonksiyonun mutlaka karşılaşılacak bir çıkış durumu olmalıdır; yoksa sonsuz döngü oluşur.

## Kısa Tekrar Notları

- Kaba kuvvet: bariz çözüm, düşük tasarım maliyeti, küçük girdiler için uygun.
- Selection sort: $\frac{(n-1)n}{2}$ karşılaştırma, $\Theta(n^2)$; swap sayısı $n-1$.
- Kaba kuvvet dizgi eşleme: en kötü $O(nm)$, en iyi $1$.
- Ayrıntılı arama: tüm adayları üret, en iyisini seç; atama $n!$, sıralama ve Hamilton çevrimi $O((n+1)!)$.
- Azalt ve fethet: bir azaltma ($a^n = a^{n-1}a$), sabit çarpanla azaltma ($a^n = (a^{n/2})^2$, ikili arama), değişken boyut (Öklid).
- İkili arama: en kötü $\lfloor\log_2 n\rfloor + 1$; 13 elemanda 4; ortalama başarılı arama $41/13 \approx 3{,}15$.
- Master teoremi: $a < b^d \Rightarrow n^d$; $a = b^d \Rightarrow n^d\log n$; $a > b^d \Rightarrow n^{\log_b a}$.
- $n$ sayının toplamı $\Theta(n)$; merge sort $\Theta(n\log n)$, $C_{worst}(n) = n\log_2 n - n + 1$.
- Dışbükey örtü: kaba kuvvet $O(n^3)$; böl ve fethet kaba birleştirmeyle $\Theta(n^2)$, akıllı teğet aramasıyla $\Theta(n\log n)$.
- SELECT: dengeli pivot $\Theta(n)$, kötü pivot $O(n^2)$; medyanların medyanı ile $T(n) = T(\lceil n/5\rceil) + T(7n/10+6) + \Theta(n)$.

## Detaylı Açıklamalar

- **Atama problemi örneği** (ekrandan, 00:30:00). Maliyet matrisi satırları kişiler, sütunları işlerdir:
  $C = \begin{bmatrix} 9 & 2 & 7 & 8 \\ 6 & 4 & 3 & 7 \\ 5 & 8 & 1 & 8 \\ 7 & 6 & 9 & 4 \end{bmatrix}$.
  Slayttaki ilk permütasyonlar: $\langle1,2,3,4\rangle$: $9+4+1+4 = 18$; $\langle1,2,4,3\rangle$: $9+4+8+9 = 30$; $\langle1,3,2,4\rangle$: $9+3+8+4 = 24$; $\langle1,3,4,2\rangle$: $9+3+8+6 = 26$; $\langle1,4,2,3\rangle$: $9+7+8+9 = 33$; $\langle1,4,3,2\rangle$: $9+7+1+6 = 23$. Bütün $4! = 24$ permütasyon bu şekilde hesaplanır. Permütasyon üretimi $n!$, en küçüğü aramak $n$; toplam yaklaşık $n!$.
- **Ayrıntılı aramayla sıralama.** Hoca $n!$ permütasyon ve her biri için $n-1$ kontrol yapıldığını, $n!\,(n-1) < (n+1)!$ olduğu için Big O'da $(n+1)!$ yazılabileceğini gösterdi. $(n+1)! = (n+1)\,n!$ olduğundan eşitsizlik her $n$ için doğrudur.
- **Öklid örneği.** $180 \bmod 146 = 34$, $146 \bmod 34 = 10$, $34 \bmod 10 = 4$; hoca burada durdu. Devamı $10 \bmod 4 = 2$, $4 \bmod 2 = 0$, yani $\gcd(180,146) = 2$ (ara adım eklendi, python ile doğrulandı).
- **İkili arama ağacı.** Ağaç, her adımda ortadaki elemanı köke koyarak kurulur: sağ yarının ortası (81) sağ çocuk, sol yarının ortası (27) sol çocuk olur ve böyle devam eder. 98'i bulmak için 55 → 81 → 93 → 98, 74 için 55 → 81 → 70 → 74 yolu izlenir; her seviye bir karşılaştırmadır (seviyedeki bütün elemanlarla değil, tek bir yol boyunca karşılaştırma yapılır). Dolu bir ağaçta $i$. seviyede $2^{i-1}$ düğüm vardır ve her birine $i$ karşılaştırmayla ulaşılır; dengeli ağaç varsayımıyla ortalama $\log_2 n$ mertebesine varılır. Yaprak seviyesi dolu olsaydı 6 değil 8 düğüm olurdu.
- **Ders sonrası not (ikili arama ağacı).** Hoca sol çocuğu "20" diye andı (01:07:52); slaytta 27'dir (ekrandan, 01:10:00). Slayttaki açıklama satırında kök "5" diye yazılmış (ekrandan, 01:12:20); kök 55'tir. Her anahtar için karşılaştırma sayısı python ile ikili aramayla sayıldı, slayttaki seviyelerle aynı çıktı.
- **Ders sonrası not (merge sort ve master teoremi).** Hoca derste önce $d$ için yanlış değer yazdığını fark etti, aradan sonra düzeltti (02:17:00): birleştirme $n-1$, yani $\Theta(n)$ olduğundan $d = 1$, $a = b^d$ ve sonuç $\Theta(n\log n)$. Slayttaki $C_{worst}(n) = n\log_2 n - n + 1$ formülü $n = 2, 4, 8, 16, 1024$ için recurrence ile python'da doğrulandı.
- **Dışbükey örtü, kaba kuvvet testi.** Bir öğrenci noktaların "içeride" olduğunun nasıl garanti edildiğini sordu. Hoca, test edilen şeyin içeride olmak değil, diğer bütün noktaların doğru denklemine konunca aynı işareti (hep pozitif ya da hep negatif) vermesi olduğunu açıkladı. Örneğin TU doğrusu çizildiğinde Q öbür tarafta kalıyorsa TU örtünün kenarı değildir; şekli ikiye bölen her doğru elenir (ekrandan, 01:40:00).
- **Dışbükey örtü, birleştirme izlemesi** (ekrandan, 01:50:00 ve 02:00:00). Başlangıç $y_{11}$ ($a_1$-$b_1$). $y_{12} > y_{11}$ olduğu için $j = 2$. Sonra $y_{13} > y_{12}$ değildir; $i$ saat yönünün tersine azaltılır (mod ile $i = 5$), $y_{52} > y_{12}$, yeni maksimum $y_{52}$. Ardından $y_{42}$ daha yüksektir, maksimum $y_{42}$ olur. Bu noktada iki yönde de daha yüksek kesişim yoktur, döngü biter; üst teğet $a_4$-$b_2$'dir.
- **L doğrusu sorusu.** Bir öğrenci L'nin bir noktanın üzerinden geçebilir mi diye sordu. Hoca, L'nin A'nın en sağdaki ($a_1$) ve B'nin en soldaki ($b_1$) noktası arasından geçirildiğini, aynı x koordinatına sahip nokta olmadığı kabul edildiğinden L üzerinde nokta olamayacağını; daha solda bir nokta olsaydı onun B'nin yeni en sol noktası olacağını ve L'nin kayacağını söyledi.
- **Ders sonrası not (SELECT örneğindeki indisler).** Hoca 0 tabanlı indis kullandı: medyan için $i = 5$, pivot $x = 7$ için $k = 4$ (7'nin dizideki konumu) aldı ve SELECT(C, 1) ile devam etti (ekrandan, 02:30:00). Slayttaki tanımda $k = rank(x)$ ve B $k-1$ eleman içerdiği için sıra 1 tabanlıdır: 7'den küçük 3 eleman (5, 3, 6) olduğundan $rank(7) = 4$, medyan için $i = 6$, çağrı SELECT(C, 2) olur. Hocanın izlemesinin devamı: C = {8, 9, 12, 13, 14, 16, 21} içinde pivot 13, $k = 3 > i = 1$, SELECT(B, 1) ile B = {8, 9, 12}; pivot 9, $k = 1 = i$, sonuç 9. 0 tabanlı sırada $rank(7) = 3$ olduğundan doğru çağrı SELECT(C, $i-k-1$) = SELECT(C, 1)'dir; hocanın konumdan aldığı $k = 4$ ile $i - k$ aynı sayıyı tesadüfen verdi. İki yolda da sonuç 9'dur (python ile sıralanmış dizinin ortası: 3, 5, 6, 7, 8, 9, 12, 13, 14, 16, 21).
- **Ders sonrası not (en kötü durum ve master teoremi).** Hoca kötü pivot durumu için $a = 1$, "$b = n/(n-1)$", $d = 1$ diyerek master teoremini zorladı. $b$ sabit olmadığı için master teoremi bu duruma uygulanamaz; bağıntı $T(n) = T(n-1) + n$'dir ve yerine koyma ile $T(n) \approx \frac{n(n+1)}{2} \in \Theta(n^2)$ çıkar. Hocanın vardığı $n^2$ sonucu doğrudur.
- **Ders sonrası not (medyanların medyanı örneği).** Hoca sütun medyanlarını "8, 6, 14 ve 7" diye okudu; ekranda medyanlar 8, 6, 10, 4, 7'dir (ekrandan, 02:42:20). Medyanların medyanı her iki durumda 7'dir. Hoca ayrıca $x$'in bir tarafındaki sütun sayısını "$x$ bölü 10" dedi; doğrusu $n/10$'dur. Altyazıdaki "7 bölü 16" ifadesi büyük olasılıkla slayttaki $7n/10 + 6$'dır.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
