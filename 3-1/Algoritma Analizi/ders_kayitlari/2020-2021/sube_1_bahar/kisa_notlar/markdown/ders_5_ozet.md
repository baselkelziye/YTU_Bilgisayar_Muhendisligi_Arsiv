# Ders 5 Çalışma Özeti

## Genel Konular

- Özyinelemeli bağıntıların çözümünde sık yapılan hata
  - $T(n) = T(n-1) + n$ geriye yerine koymayla açılırken $T(n-1)$ yerine $T(n-2) + (n-1)$ yazılmalıdır; $T(n-2) + n + n$ yazmak yanlıştır (ekrandan, 00:05:00).
  - Doğru açılım: $T(n) = T(n-2) + (n-1) + n = T(n-3) + (n-2) + (n-1) + n = \dots = T(n-k) + (n-k+1) + \dots + n$. Sonuçta $1$'den $n$'e kadar sayıların toplamı gelir: $\frac{n(n+1)}{2} \in \Theta(n^2)$.
  - Master teoremi yalnız $T(n) = aT(n/b) + f(n)$ biçimindeki, problemi alt parçalara **bölen** bağıntılara uygulanır; $T(n-1)$ gibi eksiltmeli bağıntılara bu biçimiyle uygulanmaz.
- Merge Sort tekrarı (böl ve yönet)
  - Dizi tek eleman kalana kadar yarılanır, sonra parçalar `merge` ile birleştirilir. Birleştirmede iki parçanın baştaki elemanlarından küçüğü yedek diziye kopyalanır, sonra yedek dizi asıl diziye geri kopyalanır (ekrandan, 00:10:00).
  - Bölme kısmında en iyi/en kötü durum yoktur; dizi her durumda ikiye bölünür. Birleştirmede durumlar farklı olabilir ama her birleştirme $\Theta(n)$ sürer.
  - Bağıntı: $T(n) = 2T(n/2) + cn$. Master teoremi: $a = 2$, $b = 2$, $d = 1$, $a = b^d$ olduğundan $T(n) \in \Theta(n \log n)$.
  - Bir animasyon sitesindeki Merge Sort sözde kodu da incelendi; orada ikinci yarı yedek diziye ters sırada kopyalanıp iki uçtan birleştiriliyor (ekrandan, 00:15:00).
  - Yedek dizi kullanmayan (in-place) Merge Sort denemeleri $n^2$'ye yaklaşan süre verebilir.
- Sıralama algoritmalarının süre karşılaştırması (derste sözlü verilen istatistik)
  - 1 milyon eleman: Insertion Sort yaklaşık 2,8 saat, Merge Sort yaklaşık 1 saniye, Quicksort yaklaşık 0,6 saniye.
  - 1 milyar eleman: Merge Sort yaklaşık 18 dakika, Quicksort yaklaşık 12 dakika.
  - Kayda değer fark $n^2$ ile $n \log n$ arasındadır; aynı sınıftaki iki algoritma arasındaki küçük fark uygulama ayrıntısından (swap ile kopyalama, fonksiyon çağrısı vb.) gelir.
- Quicksort'un mantığı
  - Bir eleman **pivot** seçilir (baştan, sondan ya da ortadan). Pivot, solunda kendisinden küçük-eşit, sağında büyük-eşit elemanlar kalacak biçimde gerçek yerine konur (partition).
  - Sonra pivotun solu ve sağı aynı yöntemle özyinelemeli olarak sıralanır.
  - Arama iki uçtan aynı anda yapılır; soldan pivottan büyük, sağdan pivottan küçük eleman bulununca ikisi tek swap ile yer değiştirir.
  - Ek dizi gerekmez; yalnız swap için bir geçici değişken kullanılır. Quicksort yerinde (in-place) bir algoritmadır.
  - Tanım (ekrandan, 00:35:00): $A[0] \dots A[p-1]$ hepsi $\le A[p]$; $A[p+1] \dots A[n-1]$ hepsi $\ge A[p]$.
- Quicksort sözde kodu ve Hoare bölümlemesi (ekrandan, 00:50:00)
  - `QSort(A[l..r])`: `if l < r` ise `s ← Partition(A[l..r])`, sonra `QSort(A[l..s-1])` ve `QSort(A[s+1..r])`.
  - `HoarePartition`: $p \leftarrow A[l]$; `repeat i ← i+1 until A[i] ≥ p`; `repeat j ← j−1 until A[j] ≤ p`; `swap(A[i], A[j])`; dış döngü `until i ≥ j`; son yanlış swap geri alınır ve `swap(A[l], A[j])` ile pivot yerine konur.
  - Ders sonrası not: tahtada başlangıç `i = l`, `j = r` yazıldı. `repeat j ← j−1` önce azalttığı için bu başlangıçla $A[r]$ hiç kontrol edilmez; doğrusu (Levitin'deki gibi) `j = r + 1`'dir.
- Quicksort'un en iyi, en kötü ve ortalama durumu
  - En iyi durum: pivot her seferinde ortaya düşer. $T(n) = 2T(n/2) + n$, $T(n) \in \Theta(n \log n)$. Partition'da $i$ ve $j$ birlikte toplam yaklaşık $n$ karşılaştırma yapar.
  - En kötü durum: dizi sıralı ya da ters sıralı ve pivot baştan/sondan seçilmiş. Bölme dengesiz olur: $C_{worst}(n) = (n+1) + n + \dots + 3 = \frac{(n+1)(n+2)}{2} - 3 \in \Theta(n^2)$ (ekrandan, 01:25:00).
  - Ortalama durum: rastgele dizi, bölme noktası $s$ her konuma ($0 \le s \le n-1$) $1/n$ olasılıkla düşer. $C_{avg}(n) = \frac{1}{n}\sum_{s=0}^{n-1}\left[(n+1) + C_{avg}(s) + C_{avg}(n-1-s)\right]$, $C_{avg}(0) = C_{avg}(1) = 0$. Çözüm $C_{avg}(n) \approx 2n \ln n \approx 1{,}38\, n\log_2 n \in \Theta(n \log n)$ (ekrandan, 01:35:00).
- Quicksort iyileştirmeleri
  - Küçük alt dizilerde (yaklaşık 10-15 eleman) Insertion Sort'a geçen hibrit kullanım.
  - Özyinelemeyi azaltmak (iteratif yapı), daha iyi pivot seçimi.
  - Üç yollu bölümleme (3-way partitioning): dizi "pivottan küçük", "pivota eşit", "pivottan büyük" üç parçaya ayrılır; pivota eşit çok eleman varsa daha hızlıdır (ekrandan, 01:40:00).
  - En kötü durumdan kaçınmak için: rastgele pivot, medyana yakın pivot ya da diziyi önceden karıştırma (shuffle).
- Böl ve yönet ile ilgili diğer örnekler (Levitin slaytlarından kısa özet)
  - İkili ağaç dolaşımları (inorder, preorder, postorder) $\Theta(n)$; ağaç yüksekliği $h(T) = \max\{h(T_L), h(T_R)\} + 1$, boş ağaç için $-1$ (ekrandan, 02:00:00).
  - Büyük sayıların çarpımı, Strassen matris çarpımı ($n^3$ yerine yaklaşık $n^{2,8}$), en yakın nokta çifti ($n^2$ yerine $n \log n$), dışbükey örtü (Quickhull; kaba kuvvette $O(n^3)$) (ekrandan, 02:05:00).

## Hocanın Özellikle Vurguladığı Kısımlar

- Geriye yerine koymada her adımda $n$ yerine doğru argüman yazılmalı
  - $T(n-1)$ açılırken eklenen terim $n$ değil $n-1$'dir; aksi halde toplam yanlış çıkar.
- Master teoreminin uygulanma koşulu
  - Bağıntı $aT(n/b) + f(n)$ biçiminde olmalı; problem alt parçalara bölünmelidir.
- Quicksort'ta asıl iş pivot seçimi ve pivotun yerini bulmaktır
  - İki uçtan aynı anda arama, tek swap ile iki elemanı doğru tarafa taşır.
- Quicksort'un en kötü durumu
  - Sıralı ya da ters sıralı dizide pivotun baştan/sondan seçilmesi bölmeyi dengesizleştirir ve $\Theta(n^2)$ verir.
- Hocanın önerisi: Quicksort'u C'de kendiniz yazın, kitaptaki örneği elle izleyin
  - $5, 3, 1, 9, 8, 2, 4, 7$ dizisini ilk eleman pivotken elle izlemek önerildi.
- Karmaşıklık karşılaştırmasında asıl ölçüt temel fonksiyon sınıfıdır
  - $n^2$ ile $n \log n$ arasındaki fark anlamlıdır; aynı sınıftaki küçük süre farkları uygulama ayrıntısıdır.
- Ayrıntıyı sorgulamak öğrenmenin bir üst basamağıdır
  - En kötü durumda son adımdaki "3 karşılaştırma"nın nereden geldiğini sormak, algoritmayı anlamak için önemli bir ayrıntı olarak övüldü.

## Kısa Tekrar Notları

- $T(n) = T(n-1) + n \Rightarrow T(n) = \frac{n(n+1)}{2} \in \Theta(n^2)$.
- Master teoremi: $T(n) = aT(n/b) + \Theta(n^d)$; $a = b^d$ ise $\Theta(n^d \log n)$.
- Merge Sort: her durumda $\Theta(n \log n)$; ek bellek gerekir.
- Quicksort: en iyi ve ortalama $\Theta(n \log n)$, en kötü $\Theta(n^2)$; yerinde çalışır.
- Ortalama durum yaklaşık $1{,}38\, n \log_2 n$ karşılaştırma, yani en iyi duruma göre yaklaşık %38 fazla.
- En kötü durum karşılaştırma sayısı: $\frac{(n+1)(n+2)}{2} - 3$.
- Hoare bölümlemesi: soldan $A[i] \ge p$, sağdan $A[j] \le p$ bulununca swap; $i \ge j$ olunca dur, pivotu $A[j]$ ile değiştir.
- Üç yollu bölümleme: $< p$, $= p$, $> p$; eşit elemanlar tekrar sıralanmaz.
- İyileştirmeler: küçük parçalarda Insertion Sort, rastgele/medyan pivot, shuffle, özyinelemeyi azaltma.

## Detaylı Açıklamalar

Dersin başında bir önceki konunun (böl ve yönet) tekrarı yapıldı. Hoca, $T(n) = T(n-1) + n$ bağıntısının geriye yerine koymayla açılışında yapılan yaygın hatayı tahtada düzeltti. $T(n-1)$, bağıntıda $n$ yerine $n-1$ yazılarak elde edilir: $T(n-1) = T(n-2) + (n-1)$. Dolayısıyla $T(n) = T(n-2) + (n-1) + n$ olur; ikinci kez açınca $T(n-3) + (n-2) + (n-1) + n$ gelir. $k$ adım sonra $T(n-k)$ ve $n-k+1$'den $n$'e kadar terimlerin toplamı kalır. $k = n$ alındığında başlangıç koşuluna ($T(0)$ ya da $T(1)$) inilir ve toplam $\frac{n(n+1)}{2}$, yani $\Theta(n^2)$ olur. Sezgisel olarak da her seviyede $n$'e bağlı iş yapılıp $n$ seviye derinleşildiği için $n^2$ beklenir.

Merge Sort tekrarında tahtadaki C benzeri kod (ekrandan, 00:10:00) şu yapıdaydı: `MS(A, p, r)` içinde `if (p < r)` (eleman sayısı 1'den büyükse) `q = (p+r)/2`, `MS(A, p, q)`, `MS(A, q+1, r)`, `merge(A, p, q, r)`. `merge` fonksiyonu yedek `B` dizisine, iki parçadan küçük olanı kopyalar; parçalardan biri bitince kalan elemanlar iki ayrı `while` ile kopyalanır ve sonunda `B`, `A`'ya geri yazılır. Her birleştirme, karşılaştırma ya da atama temel operasyon alınsa da $\Theta(n)$'dir. Dizi $\log n$ kez bölündüğü için toplam $\Theta(n \log n)$ çıkar.

Quicksort, Merge Sort'un hızını korurken ek bellek ihtiyacını ortadan kaldırır. Pivot seçildikten sonra $i$ soldan pivottan küçük elemanları geçerek ilerler ve büyük-eşit bir elemanda durur; $j$ sağdan büyük elemanları geçerek gelir ve küçük-eşit bir elemanda durur. $i < j$ ise iki eleman yer değiştirir. İşaretçiler çakışınca bölümleme biter, pivot $A[j]$ ile yer değiştirerek gerçek yerine oturur. Bu noktadan sonra pivotun solundakilerin hepsi pivottan küçük-eşit, sağındakilerin hepsi büyük-eşittir.

En iyi durumda partition $n$ karşılaştırma yapar (iki işaretçinin yürüdüğü toplam yol $n$'dir) ve dizi iki eşit parçaya bölünür. $T(n) = 2T(n/2) + n$ bağıntısı Master teoremiyle ya da özyineleme ağacıyla (her seviyede toplam $n$ maliyet, $\log n$ seviye) $\Theta(n \log n)$ verir. En kötü durumda, örneğin sıralı dizide pivot ilk eleman seçilirse, pivot olduğu yerde kalır ve problem yalnız bir eleman küçülür; karşılaştırma sayıları $n+1, n, \dots, 3$ biçiminde azalır ve toplam $\Theta(n^2)$ olur. Ortalama durumda bölme noktasının her konuma eşit olasılıkla düştüğü kabul edilir; iki alt problemin boyutları farklı olduğundan Master teoremi kullanılamaz. Bağıntının çözümü $2n \ln n \approx 1{,}38\, n \log_2 n$'dir; ortalama durum en iyi duruma çok yakındır.

Pratikte Quicksort'u hızlandırmak için küçük alt dizilerde Insertion Sort'a geçilir, pivot daha iyi seçilir (rastgele, medyana yakın) ya da dizi önceden karıştırılır. Pivota eşit elemanların çok olduğu dizilerde üç yollu bölümleme kullanılır: `lt`, `i`, `gt` işaretçileriyle dizi $< p$, $= p$, $> p$ bölgelerine ayrılır ve özyineleme yalnız $< p$ ve $> p$ bölgelerine uygulanır.

Dersin sonunda Levitin'in böl ve yönet slaytlarından kısa bir özet geçildi: ikili ağaç dolaşımları ve ağaç yüksekliği (sol ve sağ alt ağaçların yüksekliklerinin maksimumuna 1 eklenir), büyük sayıların parçalara ayrılarak çarpılması (ör. $386 \times 120 = 386 \times 100 + 386 \times 20$), Strassen matris çarpımı, en yakın nokta çifti ve dışbükey örtü (Quickhull) problemleri.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
