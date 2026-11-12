# Ders 8 Çalışma Özeti

## Genel Konular

- Dinamik tablo (dynamic table) (ekrandan, 00:10:00)
  - Dinamik tablo, içindeki veri miktarı değiştikçe boyutu büyütülüp küçültülebilen tablodur. Tablo alanının bellekte ardışık olması gerektiği için büyütme, daha büyük yeni bir tablo açıp bütün eski elemanları ona taşımak demektir.
  - Kullanım örneği: hash tablolarında yeniden hash'leme (rehashing). Doluluk oranı (load factor) $\alpha = n/m$ bir sınırı aşınca daha büyük tablo açılır; silmelerle belirli bir oranın altına inince tablo küçültülebilir.
  - Genel yaklaşım, yeni alanı eskisinin iki katı açmaktır. Yalnız ekleme varsa doluluk oranı her an en az $1/2$'dir; boş kalan alan tablonun yarısını aşmaz.
  - Alanlar: `T.table` (bellek bloğunu gösteren işaretçi), `T.num` (tablodaki eleman sayısı), `T.size` (tablodaki yuva sayısı). Başlangıçta `T.num = T.size = 0`.
- `TABLE_INSERT(T, x)` sözde kodu (ekrandan, 00:13:20)
  - `T.size == 0` ise tek yuvalı tablo ayrılır, `T.size = 1`.
  - `T.num == T.size` ise genişletme (expansion): `2 * T.size` yuvalı yeni tablo ayrılır, eski elemanlar yeni tabloya eklenir, eski tablo serbest bırakılır, `T.table = new_table`, `T.size = 2 * T.size`.
  - Sonra `x` tabloya eklenir ve `T.num = T.num + 1` yapılır. Maliyet, temel ekleme (insert) işlemlerinin sayısıyla ölçülür.
- Toplam (aggregate) analiz: yalnız ekleme (ekrandan, 00:18:50)
  - $i$'inci eklemenin gerçek maliyeti: $c_i = i$ ($i - 1$, 2'nin kuvvetiyse; $i - 1$ eleman taşınır, 1 ekleme yapılır), değilse $c_i = 1$.
  - $\sum_{i=1}^{n} c_i \le n + \sum_{j=0}^{\lfloor \lg n \rfloor} 2^j < n + 2n = 3n$. $n$ ekleme $O(n)$, işlem başına $O(1)$.
- Muhasebe (accounting) yöntemi (ekrandan, 00:26:00)
  - Her eklemeye 3 kredi biçilir: 1'i elemanın kendi eklenmesine, 1'i elemanın üstünde bir sonraki genişletmede kendini taşımak için, 1'i de tablonun eski yarısındaki bir elemanın (örnekte $x_1$) taşınması için harcanır.
  - Örnek: 4 yuvalı dolu tabloya $x_5$ gelince genişletme yapılır, toplam kredi 0 olur. $x_5, \dots, x_8$ eklenirken her biri 3 kredi getirir. Tablo dolunca $x_1, \dots, x_8$'in her birinin üstünde birer kredi vardır; $x_9$ gelince bu krediler taşımayı karşılar, toplam kredi yeniden 0 olur.
  - Her işlemin amortize maliyeti sabittir; $n$ işlem $O(n)$.
- Potansiyel (potential) yöntemi: yalnız ekleme (ekrandan, 00:30:00 ve 00:35:10)
  - $\Phi(T) = 2 \cdot T.num - T.size$. Genişletmeden hemen sonra $T.num = T.size/2$, $\Phi = 0$. Genişletmeden hemen önce $T.num = T.size$, $\Phi = T.num$ (taşıma maliyetini karşılar). Tablo hep en az yarı dolu olduğu için $\Phi \ge 0$.
  - $num_i$, $size_i$, $\Phi_i$: $i$'inci işlemden sonraki eleman sayısı, tablo boyutu ve potansiyel.
  - Genişletme yoksa: $size_i = size_{i-1}$, $num_{i-1} = num_i - 1$, $\hat{c}_i = 1 + (2 num_i - size_i) - (2(num_i - 1) - size_i) = 3$.
  - Genişletme varsa (ekrandan, 00:40:00): $c_i = num_i$, $size_{i-1} = num_{i-1} = num_i - 1$, $size_i = 2(num_i - 1)$. $\hat{c}_i = num_i + (2 num_i - 2(num_i - 1)) - (2(num_i - 1) - (num_i - 1)) = 3$.
  - İki durumda da amortize maliyet 3'tür; işlem başına $O(1)$, $n$ işlem $O(n)$.
- Ekleme ve silme birlikte: yanlış küçültme stratejisi (ekrandan, 00:50:00)
  - Strateji: tablo dolunca boyutu iki katına çıkar, doluluk $1/2$'nin altına inince yarıya indir.
  - En kötü dizi ($n$ 2'nin kuvveti): ilk $n/2$ işlem ekleme ($\Theta(n)$, sonunda `T.num = T.size = n/2`). Sonraki $n/2$ işlem: ekle, sil, sil, ekle, ekle, sil, sil, ...
  - Her ekleme çifti genişletmeye, her silme çifti küçültmeye (contraction) yol açar. Her genişletme ve küçültme $\Theta(n)$'dir ve bunlardan $\Theta(n)$ tane olur: toplam $\Theta(n^2)$.
  - Sorun: genişletmeden sonra küçültmenin maliyetini karşılayacak kadar silme, küçültmeden sonra da genişletmeyi karşılayacak kadar ekleme yapılmıyor.
- Düzeltilmiş strateji ve potansiyel fonksiyonu (ekrandan, 00:53:40)
  - Tablo dolunca boyut iki katına çıkar; doluluk $1/4$'ün altına inince yarıya indirilir.
  - $\Phi(T) = 2 \cdot T.num - T.size$ ($\alpha(T) \ge 1/2$ ise), $\Phi(T) = T.size/2 - T.num$ ($\alpha(T) < 1/2$ ise).
  - $\alpha = 1/4$ iken $T.size = 4 \cdot T.num$ ve $\Phi = T.num$: küçültmede taşınacak eleman sayısı kadar potansiyel birikmiştir.
  - Başlangıç: $num_0 = 0$, $size_0 = 0$, $\alpha_0 = 1$ (0/0 yerine 1 alınır), $\Phi_0 = 0$.
- Ekleme durumları (ekrandan, 01:00:00 ve 01:08:30)
  - $\alpha_{i-1} \ge 1/2$: önceki analizle aynı, $\hat{c}_i \le 3$.
  - $\alpha_{i-1} < 1/2$ ve $\alpha_i < 1/2$: genişletme yok, $\hat{c}_i = 1 + (size_i/2 - num_i) - (size_i/2 - (num_i - 1)) = 0$.
  - $\alpha_{i-1} < 1/2$ ve $\alpha_i \ge 1/2$: genişletme yok, $\hat{c}_i = 1 + (2(num_{i-1} + 1) - size_{i-1}) - (size_{i-1}/2 - num_{i-1}) = 3\alpha_{i-1} size_{i-1} - \frac{3}{2} size_{i-1} + 3 < 3$.
- Silme durumları (ekrandan, 01:12:00 ve 01:20:00)
  - $num_i = num_{i-1} - 1$.
  - $\alpha_{i-1} < 1/2$, küçültme yok: $\hat{c}_i = 1 + (size_i/2 - num_i) - (size_i/2 - (num_i + 1)) = 2$.
  - $\alpha_{i-1} < 1/2$, küçültme var: $c_i = num_i + 1$ (taşıma ve silme). Örnek: $size_{i-1} = 8$, $num_{i-1} = 2$; bir silmeden sonra $num_i = 1$, $size_i = 4$. Genel ilişki: $size_i/2 = size_{i-1}/4 = num_{i-1} = num_i + 1$. Sonuç $\hat{c}_i = 1$.
  - $\alpha_{i-1} \ge 1/2$ durumu derste çözülmedi, öğrencilere bırakıldı; yine sabit çıkar. Bütün ekleme ve silmeler $O(1)$ amortize, $n$ işlem $O(n)$.
- Tekrar soruları: kaba kuvvet ve ikili arama (ekrandan, 01:40:00 ve 01:41:55)
  - Doğru üzerindeki $n$ noktada en yakın çift (closest pair): kaba kuvvet bütün çiftlere bakar, $O(n^2)$. Önce sıralama $O(n \log n)$, sonra ardışık çiftlere bakma $O(n)$; toplam $O(n \log n) + O(n) = O(n \log n)$.
  - İkili arama dizide $\Theta(\log n)$'dir, çünkü ortadaki elemana $O(1)$'de erişilir. Sıralı bağlı listede ortadaki elemana erişim $O(n)$'dir; hoca sonucu $\log n \cdot n$ olarak verdi.
- Ana teorem (master theorem) tekrarı (ekrandan, 01:44:55)
  - $T(n) = aT(n/b) + f(n)$, $f(n) \in \Theta(n^d)$ ise: $a < b^d$ için $\Theta(n^d)$, $a = b^d$ için $\Theta(n^d \log n)$, $a > b^d$ için $\Theta(n^{\log_b a})$.
  - Örnek: $T(n) = 4T(n/2) + n$; $a = 4$, $b = 2$, $d = 1$, $a > b^d$, sonuç $\Theta(n^{\log_2 4}) = \Theta(n^2)$.
- Hash tekrarı (ekrandan, 01:50:00)
  - Düzgün (uniform) hash ile $m$ yuvalı tabloya $n$ anahtar: iki farklı anahtarın çakışma olasılığı $1/m$. Beklenen çakışma sayısı $\binom{n}{2} \frac{1}{m} = \frac{n(n-1)}{2} \cdot \frac{1}{m}$.
  - Düğümlerinde uzun dizgiler olan bağlı listede arama $n \cdot$ dizgi uzunluğu kadar sürer. Her düğümde dizginin hash değeri de tutulursa yalnız hash'ler karşılaştırılır. Hash'ler eşleşince çakışma ihtimaline karşı dizgi bir kez tam olarak karşılaştırılır.
- Matematiksel tümevarımla yerine koyma (ekrandan, 01:55:10, 01:57:50 ve 02:00:00)
  - $T(n) = 4T(n/4) + n$. Tahmin 1: $T(n) \le cn$. $m = n/4$ için varsayımla $T(n) \le cn + n$; bu $cn$'i aşar, tahmin tutmaz.
  - Tahmin 2: $T(n) \le n \log_2 n$. $\log_2(n/4) = \log_2 n - 2$ ile $T(n) \le n \log_2 n - 2n + n = n \log_2 n - n$; tahmin tutar.
  - Tahmin 3: $T(n) \le n \log_4 n$. $T(n) \le n(\log_4 n - 1) + n = n \log_4 n$; ispatlanmak istenenin aynısı çıkar, daha sıkı sınır.
- Özyineleme ağacı (recursion tree) (ekrandan, 02:03:40 ve 02:06:55)
  - Birleştirmeli sıralama: $T(n) = 2T(n/2) + n$, $T(1) = 0$. Her seviyenin toplam işi $n$, derinlik $1 + \log_2 n$; sonuç $n \log_2 n$.
  - $T(n) = 2T(n/2) + n^2$: $i$'inci seviyenin işi $n^2/2^i$. Toplam $n^2 \sum_{i=0}^{\log_2 n} 1/2^i$; seri sabitle sınırlı olduğu için $O(n^2)$.

## Hocanın Özellikle Vurguladığı Kısımlar

- Potansiyel yönteminde formül kurulduktan sonra bütün durumlar tek tek denenmelidir.
  - Doluluk oranına göre parçalı tanımlanan fonksiyonda her durum için kritik soru, işlemin genişletmeye ya da küçültmeye yol açıp açmadığıdır. Eşitlikler buna göre yazılır.
- Potansiyel fonksiyonu genişletmeden hemen sonra sıfırlanmalı, tablo doldukça değer kazanmalıdır.
  - Ayrıca hiçbir zaman negatif olmamalıdır.
- Küçültme sınırı $1/2$ seçilirse ekleme-silme dizisi $\Theta(n^2)$'ye çıkar.
  - Genişletme ile küçültme arasında maliyeti karşılayacak kadar işlem birikmesi için küçültme sınırı $1/4$ alınır.
- Ana teorem önemlidir.
  - Yineleme bağıntısı için ana teorem, özyineleme ağacı ve tümevarımla yerine koyma arasından uygun olan seçilmelidir.

## Kısa Tekrar Notları

- Dinamik tablo: dolunca boyut iki katı, bütün elemanlar yeni tabloya taşınır.
- Ekleme maliyeti: $i - 1$ 2'nin kuvvetiyse $c_i = i$, değilse 1.
- Toplam analiz: $\sum c_i < 3n$.
- Muhasebe: her eklemeye 3 kredi (kendisi, kendi taşınması, eski bir elemanın taşınması).
- Yalnız ekleme için $\Phi = 2 \cdot num - size$; her ekleme $\hat{c}_i = 3$.
- Küçültme sınırı $1/2$ olursa ekle-sil-sil-ekle-ekle-... dizisi $\Theta(n^2)$.
- Doğru strateji: dolunca 2 katı, $\alpha < 1/4$ olunca yarıya.
- $\Phi = 2 \cdot num - size$ ($\alpha \ge 1/2$), $\Phi = size/2 - num$ ($\alpha < 1/2$).
- Ekleme: $\hat{c}_i \le 3$; silme: $\hat{c}_i \le 2$; ekleme-silme dizisi $O(n)$.
- En yakın çift: sırala $+$ ardışıkları tara $= O(n \log n)$.
- Ana teorem: $a$ ile $b^d$ karşılaştırılır; $4T(n/2) + n = \Theta(n^2)$.
- Beklenen çakışma: $\frac{n(n-1)}{2m}$.
- $T(n) = 4T(n/4) + n$: $cn$ tutmaz, $n \log_2 n$ ve $n \log_4 n$ tutar.
- $2T(n/2) + n$: $n \log_2 n$; $2T(n/2) + n^2$: $O(n^2)$.

## Detaylı Açıklamalar

- Toplam analizde gerçek maliyetler sırayla 1, 2, 3, 1, 5, 1, 1, 1, 9, ... biçimindedir: genişletmeler $i = 2, 3, 5, 9, \dots$ adımlarında olur. Toplam, her işlemin 1 birimlik ekleme maliyeti ($n$) ile taşıma maliyetlerinin toplamından ($\le \sum_{j=0}^{\lfloor \lg n \rfloor} 2^j < 2n$) oluşur. Hoca sınırı tam eşitlik olarak değil, üst sınır olarak verdi. Değerler $n = 1, 16, 17, 100, 1024, 1025$ için python ile denendi; toplam hep $3n$'den küçüktür (örneğin $n = 16$ için 31, $n = 1025$ için 3072).
- Muhasebe yönteminde hoca önceki dersteki restoran tabakları benzetmesine döndü: yığında PUSH'a fazladan kredi verildiği gibi burada da eklemeye fazladan kredi verilir. Genişletmeden hemen sonra tablonun yarısı doludur ve üzerlerinde kredi yoktur. Sonraki yarı doldurulurken her yeni eleman hem kendi taşınmasını hem de eski yarıdaki bir elemanın taşınmasını öder.
- Potansiyel yöntemiyle genişletmeli eklemede ara adımlar (ekrandan, 00:40:00): $\hat{c}_i = num_i + (2 num_i - 2(num_i - 1)) - (2(num_i - 1) - (num_i - 1)) = num_i + 2 - (num_i - 1) = 3$ (son sadeleştirme ara adım olarak eklendi).
- Yanlış stratejide (küçültme sınırı $1/2$) tablo $n/2$ boyutunda ve dolu iken gelen ekleme tabloyu $n$ boyutuna çıkarır. İki silmeden ikincisi doluluğu $1/2$'nin altına indirir ve tablo yeniden $n/2$'ye küçülür. Sonraki iki eklemenin ikincisi yine genişletme yapar. Bu dizi $n = 64, 256, 1024$ için python ile denendi; toplam maliyet yaklaşık $n^2/8$ büyüdü, yani $\Theta(n^2)$.
- Düzeltilmiş stratejide amortize maliyetlerin sabit kaldığı, rastgele ekleme-silme dizileriyle python ile denendi; gözlenen en büyük amortize maliyet 3'tür ve potansiyel hiç negatif olmadı.
- Silmede küçültme durumunun hesabı (ekrandan, 01:20:00): $\hat{c}_i = (num_i + 1) + ((num_i + 1) - num_i) - ((2 num_i + 2) - (num_i + 1)) = 1$. Burada $size_i/2 = num_i + 1$ ve $size_{i-1}/2 = 2(num_i + 1)$ kullanıldı.
- Ders sonrası not: Hoca yalnız eklemenin potansiyel analizinin sonunda "N işlem için de O1'e tekabül edecek" dedi (00:40:10); doğrusu işlem başına $O(1)$, $n$ işlem için toplam $O(n)$'dir.
- Ders sonrası not: Tahtada küçültmesiz silme durumunun bir satırı $-(size_i/2 - num_i + 1)$ diye yazıldı (ekrandan, 01:12:00); doğrusu $-(size_i/2 - (num_i + 1))$'dir. Tahtadaki sonuç (2) bu doğru yazımla çıkar.
- Ders sonrası not: Hoca $T(n) = 2T(n/2) + n^2$ ağacında $\sum_{i=0}^{\log_2 n} 1/2^i$ toplamını "birden küçük" diye yazdı (ekrandan, 02:06:55). $i = 0$ terimi zaten 1 olduğu için doğrusu toplamın 2'den küçük olmasıdır. Sonuç değişmez: $T(n) < 2n^2$, yani $O(n^2)$.
- Ders sonrası not: Sıralı bağlı listede ikili arama için hocanın verdiği $n \log n$, doğru bir üst sınırdır ama sıkı değildir. Her adımda ortaya yürümek kalan aralığın yarısı kadar sürer: $n/2 + n/4 + \cdots < n$. Yürüme toplamı $O(n)$, karşılaştırma sayısı $O(\log n)$'dir; yani arama $O(n)$'de biter ve sıralı bağlı listede doğrusal aramadan asimptotik olarak daha iyi değildir.
- Bağlı listede uzun dizgi örneğinde hoca, hash karşılaştırmasının ve hash hesaplamanın $O(1)$ olduğunu kabul etti; aramanın yalnız liste uzunluğuna bağlı kalması bu sayededir. Hash eşleşmesinden sonraki tam dizgi karşılaştırması yalnız eşleşen düğüm için bir kez yapılır.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
