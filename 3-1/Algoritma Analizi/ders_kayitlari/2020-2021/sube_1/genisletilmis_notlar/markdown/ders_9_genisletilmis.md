# Ders 9 Genişletilmiş Notu: Quick Sort, Karmaşıklık Analizi ve Üç Yollu Bölümleme

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Önceki Bir Örneğin Düzeltilmesi: $2n+5 \in \Theta(n)$
- 2. Böl ve Yönet Sıralamaları ve Hız Karşılaştırması
- 3. Quick Sort'un Mantığı ve Bölümleme
- 4. Özyinelemeli Çağrıların İzlenmesi
- 5. Quick Sort Sözde Kodu
- 6. Quick Sort Karmaşıklık Analizi
- 7. Pivot Seçimi
- 8. Dijkstra'nın Üç Yollu Bölümlemesi
- 9. Küçük Parçalar İçin Insertion Sort
- Örnek Sorular
- Dersin Toparlaması

## 1. Önceki Bir Örneğin Düzeltilmesi: $2n+5 \in \Theta(n)$

Ders, asimptotik analiz konusundaki bir örneğin düzeltilmesiyle başladı. O örnekte $2n+5$'in $\Theta(n)$ olup olmadığı inceleniyordu ve verilen sabitlerde bir hata vardı. Hoca eski çözümü tahtada bulamadığı için örneği baştan çözdü.

$\Theta(n)$ bir sıkı sınırdır (tight bound). Bu yüzden $f(n)$ hem Ω'nın koşulunu hem O'nun koşulunu sağlamalıdır:

$$c_2 \cdot n \le f(n) \le c_1 \cdot n$$

Burada $c_1, c_2 > 0$ sabitlerdir ve eşitsizlikler bir $n_0$ noktasından sonraki her $n$ için sağlanmalıdır. İş iki parçaya ayrılır (ekrandan, 00:05:00):

- (1) $f(n) \ge c_2 \cdot n$
- (2) $f(n) \le c_1 \cdot n$

İki koşulda $n_0$ ortaktır, $c_1$ ve $c_2$ farklı olabilir.

### 1.1 Alt sınır

$2n+5 \ge c_2 \cdot n$ için $n_0 = 1$ ve $c_2 = 1$ seçilir. Koşul $2n+5 \ge n$ olur. $n = 2$ için $9 \ge 2$, $n = 3$ için $11 \ge 3$'tür (ekrandan, 00:05:00). Sol taraftaki $2n$ zaten $n$'den büyük olduğu için bu koşul her zaman sağlanır.

### 1.2 Üst sınır

$2n+5 \le c_1 \cdot n$ için $n_0 = 1$ alınmıştı. $n = 1$'de sol taraf $7$'dir; dolayısıyla $c_1 \cdot 1 \ge 7$, yani $c_1 \ge 7$ olmalıdır. $c_1 = 7$ denenir:

- $n = 1$: $7 \le 7$
- $n = 2$: $9 \le 14$
- $n = 8$: $21 \le 56$

Fark $n$ büyüdükçe artar, koşul bozulmaz. Sonuç olarak $c_2 = 1$, $c_1 = 7$, $n_0 = 1$ ile

$$n \le 2n+5 \le 7n$$

elde edilir ve $2n+5 \in \Theta(n)$ olur (python ile $1 \le n < 1000$ için doğrulandı).

> **Hocanın vurgusu:** Asıl yapılacak iş, farklı $c$ ve $n$ değerleri için durumu incelemek ve öyle bir $n_0$ başlangıç noktası bulmaktır ki o noktadan sonra durum artık değişmesin.

## 2. Böl ve Yönet Sıralamaları ve Hız Karşılaştırması

Önceki derste böl ve yönet (divide and conquer) algoritmaları görülmüştü. Bu yaklaşımı en iyi temsil eden iki başarılı algoritma merge sort ve quick sort'tur.

$n$ elemanlı bir dizide her elemanı diğerleriyle karşılaştıran yöntemler en kötü durumda $n^2$'ye gider; selection sort, bubble sort ve insertion sort böyledir. Böl ve yönet yaklaşımının sorusu şudur: Elemanları parçalara ayırarak değerlendirirsem ve her seferinde bütün elemanlara bakmak zorunda kalmazsam daha etkin bir algoritma kurabilir miyim? Merge sort bu fikri uygular ve daha önce anlatılmıştı. Bu ders quick sort ile devam etti.

Tahtadaki tablo, saniyede $10^8$ karşılaştırma yapan bir ev bilgisayarı için yaklaşık süreleri verir (ekrandan, 00:10:00):

| Algoritma | n = bin | n = milyon | n = milyar | Mertebe |
|---|---|---|---|---|
| Insertion sort | anlık | 2.8 saat | 317 yıl | $n^2$ |
| Merge sort | anlık | 1 saniye | 18 dakika | $n \log_2 n$ |
| Quick sort | anlık | 0.6 saniye | 12 dakika | $n \log_2 n$ |

$n$ bin mertebesindeyken üç algoritma da anlık sonuç verir. $n$ milyon ve milyar mertebesine çıkınca fark çok büyür. Tahtanın altında quick sort'un en kötü durumunun yine $n^2$ olduğu not edildi.

> **Ek bilgi (derste anlatılmadı):** Insertion sort satırı doğrudan hesapla uyumludur: $(10^6)^2 / 10^8 = 10^4$ saniye ≈ 2.8 saat, $(10^9)^2 / 10^8 = 10^{10}$ saniye ≈ 317 yıl. Merge ve quick sort satırları ise büyük olasılıkla ölçülmüş sürelerdir ve sabit çarpanları da içerir; bu yüzden yalnız $n \log_2 n$ ile hesaplanan değerden farklıdır.

## 3. Quick Sort'un Mantığı ve Bölümleme

### 3.1 Temel fikir

Quick sort dizide bir pivot eleman seçer. Pivottan küçük elemanlar bir tarafa, büyükler diğer tarafa yerleştirilir. İşlem bitince dizi şu biçimi alır (ekrandan, 00:30:00):

$$\underbrace{A[0] \dots A[s-1]}_{< A[s]} \quad \underbrace{A[s]}_{\text{pivot}} \quad \underbrace{A[s+1] \dots A[n-1]}_{\ge A[s]}$$

Bu "küçükler bir tarafa, büyükler bir tarafa" aşamasına bölümleme (partitioning) denir. Bölümleme bitince pivot, dizi sıralı olsaydı bulunacağı yere yerleşmiş olur ("After partition $A[s]$ is in its final position", ekrandan, 00:35:00).

Bunun kazancı şudur: Pivottan küçük elemanlar solda olduğuna göre onlar kendi aralarında sıralanabilir ve bu sırada sağ tarafa bakmaya gerek kalmaz; sağdakiler pivottan büyük olduğu için sola karışamaz. Pivot dizinin yaklaşık ortasına düşerse dizi her adımda yaklaşık ikiye bölünür ve her seferinde bütün elemanları birbiriyle karşılaştırmak gerekmez. Yarıya böle böle gidildiği için karmaşıklık $n \log n$ olur.

Bölümleme sıralama değildir; yalnız bir eşiğe göre ayırmadır. Hoca bunu birinci sınıfta yapılan "pozitifler başa, negatifler sona" türü alıştırmalara benzetti.

### 3.2 Bölümleme örneği: 5 3 1 9 8 2 4 7

Dizi ve indisler (ekrandan, 00:30:00):

| İndis | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 |
|---|---|---|---|---|---|---|---|---|
| Değer | 5 | 3 | 1 | 9 | 8 | 2 | 4 | 7 |

Genellikle ilk eleman pivot seçilir; pivot 5'tir. Sol işaretçi `l` pivottan sonraki elemandan başlayıp ileri, sağ işaretçi `r` son elemandan başlayıp geri gider. Mümkün olduğunca az yer değiştirme yapmak için büyük eleman bulununca hemen sona atılmaz; sondan da geriye doğru ilerlenip yer değiştirilecek küçük bir eleman aranır.

1. `l`: 3 < 5, ilerle; 1 < 5, ilerle; 9 > 5, dur (indis 3).
2. `r`: 7 > 5, yerinde kalabilir, geri gel; 4 < 5, dur (indis 6).
3. 9 ile 4 yer değiştirir: 5 3 1 4 8 2 9 7. `l` bir ileri (indis 4), `r` bir geri (indis 5) gider.
4. `l`: 8 > 5, dur. `r`: 2 < 5, dur.
5. 8 ile 2 yer değiştirir: 5 3 1 4 2 8 9 7. `l` indis 5'e, `r` indis 4'e gelir.
6. `l > r` oldu: işlem bitti ("l > r ⇒ işlem bitti", ekrandan, 00:35:00).

Pivottan küçük son eleman artık `l`'nin bir gerisindedir, yani `r`'nin gösterdiği yerdedir (değeri 2). Pivot bu elemanla yer değiştirir:

| İndis | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 |
|---|---|---|---|---|---|---|---|---|
| Değer | 2 | 3 | 1 | 4 | **5** | 8 | 9 | 7 |

5 dördüncü göze yerleşti ($s = 4$) ve dizi sıralandığında da burada olacaktır. Artık 5'ten küçükler ve büyükler için ayrı ayrı işlem yapılabilir.

## 4. Özyinelemeli Çağrıların İzlenmesi

İşe başlarken bakılan bölge $l = 0$, $r = 7$'dir ve bölümleme pivotun adresini $s = 4$ olarak verir (ekrandan, 00:40:00). Önce sol taraf bitirilir.

### 4.1 Sol taraf: $l = 0$, $r = 3$

Hoca burada sınıfa sordu: $l = 0$ ise sol bölgenin son indisi ne olmalı? Cevap $s - 1 = 3$'tür; pivotun adresinin bir öncesi. Bölge 2 3 1 4, pivot 2:

1. `l` 3'te: 3 > 2, dur. `r` 4'te: 4 > 2, geri gel; 1 < 2, dur.
2. 3 ile 1 yer değiştirir: 2 1 3 4. `l` bir ileri, `r` bir geri gider; `l > r`, işlem biter.
3. `l`'nin bir gerisindeki eleman (1) ile pivot yer değiştirir: 1 2 3 4.

2 birinci göze yerleşti ($s = 1$). Bundan sonra:

- Solu: $l = 0$, $r = s - 1 = 0$. Tek eleman var, yapılacak iş yok.
- Sağı: $l = s + 1 = 2$, $r = 3$. Hoca sol sınırın değer olarak değil adres olarak sorulduğunu hatırlattı: değer 3'tür ama adres 2'dir. Bölge 3 4, pivot 3. Hem `l` hem `r` 4'ü gösterir; 4 > 3 olduğu için `r` geri gelir ve pivotun üstüne düşer. Pivot kendisiyle yer değiştirir, 3 yerinde kalır ($s = 2$).
  - Bunun solu $l = 2$, $r = s - 1 = 1$ olur. $l > r$ anlamsız bir aralıktır; fonksiyon hiçbir şey yapmadan döner. Sol tarafa bakarken yalnız sağ sınır değişir ($s-1$), sol sınır değişmez.
  - Sağı $l = s + 1 = 3$, $r = 3$'tür; tek eleman, iş yok.

Böylece 0-3 aralığı bitti.

### 4.2 Sağ taraf: $l = 5$, $r = 7$

Sağ tarafa bakarken sol sınır pivottan bir sonrası ($s + 1 = 5$) olur, sağ sınır değişmez. Bölge 8 9 7, pivot 8:

1. `l` 9'da: 9 > 8, dur. `r` 7'de: 7 < 8, dur.
2. 9 ile 7 yer değiştirir: 8 7 9. `l` bir ileri, `r` bir geri gider; `l > r`.
3. `l`'nin bir gerisindeki 7 ile pivot yer değiştirir: 7 8 9.

8 altıncı göze yerleşti ($s = 6$). Solu ($l = 5$, $r = 5$) ve sağı ($l = 7$, $r = 7$) tek elemandır. Dizi 1 2 3 4 5 7 8 9 olarak sıralanmıştır (ekrandan, 00:50:00).

### 4.3 Çağrı sırası

Hoca çağrıları tahtadaki ağaçta 1'den 9'a numaraladı (ekrandan, 00:50:00):

| Sıra | Çağrı ($l$, $r$) | Sonuç |
|---|---|---|
| 1 | (0, 7) | $s = 4$ (5) |
| 2 | (0, 3) | $s = 1$ (2) |
| 3 | (0, 0) | tek eleman |
| 4 | (2, 3) | $s = 2$ (3) |
| 5 | (2, 1) | $l > r$, boş |
| 6 | (3, 3) | tek eleman |
| 7 | (5, 7) | $s = 6$ (8) |
| 8 | (5, 5) | tek eleman |
| 9 | (7, 7) | tek eleman |

Bu sıra ve ara diziler python ile doğrulandı. Her çağrı önce kendi solunu, o bitince sağını çağırır. Bu yüzden algoritma önce bütün sol tarafı derinlemesine bitirir; bitirdiği son sol parçanın sağını yapar, sonra yukarı çıkar ve sağ tarafa geçer.

## 5. Quick Sort Sözde Kodu

Önce durma şartı belirlenir; özyinelemeli bir algoritmada ilk iş sonsuza kadar dönmemesini sağlamaktır. $l = r$ ise tek eleman vardır, karşılaştırılacak başka eleman yoktur. $l > r$ ise bakılacak eleman kalmamıştır (4.1'deki (2, 1) çağrısı gibi). Öyleyse durma şartı $l \ge r$'dir; algoritma yalnız $l < r$ iken çalışır.

Tahtadaki sözde kod (ekrandan, 01:05:00):

```text
QuickSort(A[l..r])          initial: l <- 0, r <- n-1
{
    if (l < r)
    {
        s <- partition(A[l..r])     // s: pivotun adresi
        QuickSort(A[l..s-1])
        QuickSort(A[s+1..r])
    }
}
```

`partition` diziyi alır, pivottan küçükleri bir tarafa, büyükleri diğer tarafa koyar, son küçük elemanı pivotla (baştaki elemanla) yer değiştirir ve pivotun adresini döndürür. Quick sort bu adresin öncesi ve sonrası için arka arkaya çağrılır.

> **Hocanın vurgusu:** Bölümleme fonksiyonunu ve quick sort'u, internetteki çözümlere bakmadan önce bu taslakla kendi başınıza, adım adım yazmaya çalışın.

> **Ders sonrası not:** Altyazıda bir yerde sağ parça "S-1'den R'ye" diye geçiyor (00:48:20); tahtadaki ve doğru olan sınır $s+1$'den $r$'ye kadardır (ekrandan, 01:05:00).

## 6. Quick Sort Karmaşıklık Analizi

### 6.1 Bölümlemenin karmaşıklığı

Analize geçmeden önce hoca sınıfa sordu: $n$ elemanlı bir dizide bir sayıdan küçükleri bir tarafa, büyükleri diğer tarafa koymanın karmaşıklığı nedir? Hoca pivotu 2 olan küçük bir dizide bakılan elemanları tek tek işaretledi: pivot dışındaki $n - 1$ elemanın hepsine bakılır, gerekirse yer değiştirilir. <!-- BELİRSİZ: Bu örnek dizinin tam sırası karelerde görünmüyor; altyazıda 3, 8, 5, 4, 1 elemanlarına bakıldığı geçiyor. --> Toplam iş $c \cdot n$'dir.

**Soru:** Bütün elemanlar ters dizilmişse hepsinin yerini değiştirmek gerekmez mi, bu $n^2$'ye gitmez mi?

**Cevap:** Gitmez. Bölümlemede iç içe iki döngü yoktur. En fazla $n$ karşılaştırma ve $n$ yer değiştirme yapılır; bu $2n$, $3n$ gibi bir değer olur, ama $n^2$ olmaz. Sabit katsayılar asimptotik analizde atılır. Bütün elemanlara bakmak zorunlu olduğu için $\log n$'e de inmez. Bu yüzden bölümlemenin karmaşıklığı her durumda sıkı sınırla $\Theta(n)$'dir.

### 6.2 En iyi durum

En iyi durum, her bölümleme adımında pivotun tam ortada olmasıdır ("the pivot is in the MIDDLE at each partition step", ekrandan, 01:10:00). Bu durumda quick sort kendini iki kez, her seferinde $n/2$ eleman için çağırır; bir de $cn$'lik bölümleme vardır:

$$T(n) = \begin{cases} \Theta(1) & n = 0, 1 \\ 2\,T(n/2) + c\,n & n > 1 \end{cases}$$

Bu, merge sort'un denkleminin aynısıdır (orada bölümleme yerine birleştirme vardı). Geriye doğru yerine koyma ile:

$$T(n) = 2T(n/2) + n = 4T(n/4) + n + n = \dots = n \log_2 n + n \cdot T(1)$$

olur (ara adım eklendi; $T(1) = 1$ ve $n$ ikinin kuvveti iken python ile doğrulandı). Sonuç $T(n) \in \Theta(n \log n)$'dir. Pivotun hep ortada olduğu varsayıldığından en iyi durumda sonuç kesin olarak $n \log n$ çıkar; bu yüzden Θ ile yazılır.

### 6.3 En kötü durum

En kötü durum, dizinin zaten sıralı olmasıdır ("when the array is already sorted", ekrandan, 01:20:00). Tahtadaki dizi 1 4 5 9 12 21'dir. Pivot 1 seçilir; dizi sıralı olduğu için 1'den küçük eleman yoktur ve bölümleme diziyi ikiye bölemez. 1 yerleşir ama geriye kalan elemanların hepsine bakılmıştır. Sonra 4 için kalan bütün elemanlara, sonra 5 için kalanlara bakılır. Her adımda yalnız bir eleman yerleşir ve kestirme yol yoktur:

$$T(n) = \begin{cases} \Theta(1) & n = 0, 1 \\ T(n-1) + c\,n & \text{aksi halde} \end{cases}$$

Yerine koyma:

$$T(n) = T(n-1) + n = T(n-2) + (n-1) + n = \dots$$

Toplam tahtada $\frac{n(n+1)}{2} \in \Theta(n^2)$ olarak yazıldı (ekrandan, 01:20:00). Elemanlar küçükten büyüğe sıralı olduğu sürece sonuç kesin olarak $n^2$ mertebesi çıktığı için yine Θ ile gösterilir.

> **Ders sonrası not:** Tahtadaki $\frac{n(n+1)}{2}$, $T(n) = T(n-1) + n$ ve $T(1) = 1$ alındığında $n + (n-1) + \dots + 1$ toplamıdır (python ile $n = 10$ için 55). Yalnız karşılaştırmalar sayılırsa adımlar $n-1, n-2, \dots, 1$ olur ve toplam $\frac{n(n-1)}{2}$ çıkar. İki durumda da sonuç $\Theta(n^2)$'dir. Altyazıdaki "n-1 bölü 2" ifadesi (01:18:03) büyük olasılıkla bu toplamın eksik yazılmasıdır.

### 6.4 Ortalama durum

Ortalama durumda elemanlar rastgele sıradadır; ne küçükten büyüğe ne de büyükten küçüğe sıralıdır. Pivotun bölümleme sonrasında herhangi bir konumda olma olasılığı eşittir; $n$ eleman varsa her konumun olasılığı $1/n$'dir. Pivot $k$. konuma yerleşirse solda $k-1$ elemanlık bir alt dizi, sağda $n-k$ elemanlık bir alt dizi kalır. $T(k-1)$ sol parçayı, $T(n-k)$ sağ parçayı sıralama süresidir. $k$'nın $n$ farklı değeri için bu süreler toplanıp $n$'e bölünür ve bölümleme maliyeti eklenir:

$$T(n) = c\,n + \frac{1}{n} \sum_{k=1}^{n} \big[ T(k-1) + T(n-k) \big]$$

<!-- BELİRSİZ: Ortalama durum denkleminin tahtadaki tam yazımı karelerde görünmüyor (01:20:00 karesi en kötü durumda, 01:25:00 karesi boş sayfa); denklem altyazıdaki anlatımdan kuruldu. -->

Hoca bu denklemi derste çözmedi; çözümün yaklaşık $1.39\, n \log n$ çıktığını söyledi. Yani ortalama durum da en iyi durum gibi $n \log n$ mertebesindedir. Bu yüzden quick sort genellikle en çok kullanılan sıralama algoritmasıdır.

> **Ek bilgi (derste anlatılmadı):** Bilinen sonuç, ortalama karşılaştırma sayısının $2n \ln n \approx 1.39\, n \log_2 n$ olmasıdır ($2 \ln 2 \approx 1.386$). Yani 1.39 katsayısı 2 tabanlı logaritmaya göredir.

## 7. Pivot Seçimi

En kötü durum dizinin sıralı olmasından kaynaklandığına göre, bu duruma düşmemek için ne yapılabilir? Hoca sınıfa sordu ve gelen önerileri tartıştı.

- **Ortadaki eleman:** Bir öğrenci pivotu bakılan bölgenin tam ortasından, yani $n/2$. adresten seçmeyi önerdi. Bu mantıklı bir ilk çözümdür.
- **Diziyi karıştırmak:** Bir başka öneri diziyi biraz karıştırıp sonra baştaki elemanı pivot almaktı. Hoca pek çok uygulamanın bunu yaptığını söyledi: dizi işe başlarken yalnız bir kez karıştırılır (shuffle). Karıştırmanın karmaşıklığı $n$'dir ve varsa mevcut sıralamayı bozar. Ardından klasik quick sort uygulanır.
- **Üç rastgele elemanın medyanı:** Rastgele üç eleman seçilir, ikinci büyüğü (ortancası) pivot olur. Tahtadaki örnekte 4, 2, 3 seçilince pivot 3; 1, 5, 9 seçilince pivot 5 olur. Bu biraz masraflı görünse de uygulamada yapılır. Ortadaki elemanı seçmede de, düşük olasılıkla, her seferinde küçük bir elemana denk gelme riski vardır; medyan yöntemi bu olasılığı iyice düşürür.

<!-- BELİRSİZ: Pivot seçimi sırasında tahtaya yazılanlar karelerde görünmüyor (01:25:00 ve 01:30:00 kareleri boş sayfa); örnek sayılar altyazıdan alındı. -->

> **Hocanın vurgusu:** Pivot hangi yöntemle seçilirse seçilsin önce dizinin başına (birinci göze) taşınmalı, bölümleme dizinin geri kalanı üzerinde yapılmalıdır. Aksi halde pivotu bölümleme sırasında sürekli sağa sola kaydırmak gerekir; bu gereksiz bir iştir ve sık yapılan bir hatadır.

**Soru:** Veriler sabit bir dizide değil de bağlı listede olsaydı, ortadaki elemanı bulup pivot yapmak çok masraflı olurdu. Rastgele bir eleman pivot alınsa mantıklı olur muydu?

**Cevap:** Bağlı listede bu şekilde sıralama yapmak, linkleri bozup elemanların yerini değiştirmek gerektiğinden zaten etkin değildir. Gerçekten bağlı liste gerekiyorsa (örneğin sürekli ekleme-çıkarma olan ama sıralı erişim de istenen bir yapı), veriler önce bir tampon bölgeye alınıp sıralanabilir, sonra bağlı listeye aktarılıp ekleme-çıkarmalar sırayı bozmayacak biçimde yapılabilir. Bağlı listede quick sort önerilmez. Bununla birlikte ortadaki eleman yerine rastgele bir elemanı pivot seçmek de olabilir.

### 7.1 En kötü durumdan neden bu kadar kaçınılır?

**Soru:** Pivot için bu kadar uğraşılmasının, en kötü duruma düşme olasılığının bu kadar azaltılmaya çalışılmasının sebebi nedir?

**Cevap:** Hesaplama süresinin uzaması doğru ama eksik bir cevaptır. Gerçek dünya problemlerinde sistemler genellikle algoritmaların ortalama durumuna göre planlanır. Hocanın örneği: Deprem anında herkes yakınlarını aynı anda aradığında telefon şebekesi kilitlenir. Bunun sebebi beceriksizlik değil, altyapının pahalı olması ve ortalama yüke göre kurulmasıdır; herkesin aynı anda araması çok düşük olasılıklı bir durumdur. O durum (en kötü durum) gerçekleştiğinde sistem yükü kaldıramaz. Benzer biçimde quick sort'un kullanıldığı zaman açısından kritik bir uygulamada en kötü duruma düşmek hesapların ciddi biçimde gecikmesi demektir. Üç rastgele elemanın medyanını almak gibi yöntemler bu olasılığı olabildiğince düşürmek içindir.

## 8. Dijkstra'nın Üç Yollu Bölümlemesi

### 8.1 Motivasyon

Bazı sıralama problemlerinde çok sayıda tekrar eden anahtar vardır. Örneğin bir grup insanı doğum tarihine göre sıralarken aynı doğum tarihine sahip çok kişi olabilir; yaşadıkları şehre göre sıralarken de aynı şehirde yaşayan çok kişi olacaktır. Bu durumda quick sort'un performansı iyileştirilebilir mi?

Klasik bölümlemede tek bir pivot vardır: solunda pivottan küçük ya da eşitler, sağında büyük ya da eşitler bulunur. Üç yollu bölümlemede ise sonuç üç bölgedir (ekrandan, 01:50:00):

| Pivottan küçükler | Pivota eşitler | Pivottan büyükler |
|---|---|---|

Pivot artık tek bir eleman değil, pivota eşit elemanlardan oluşan bir bölgedir. Quick sort bu bölgenin içine bir daha bakmaz; yalnız öncesi ve sonrası için çağrılır. Böylece gereksiz işlem azalır.

Bunun için birden fazla yöntem vardır; derste Dijkstra'nın yöntemi anlatıldı. Hoca Dijkstra'yı en kısa yol algoritmasıyla da bilinen bilim insanı olarak tanıttı ("E. W. Dijkstra 3-way partitioning", ekrandan, 01:55:00).

### 8.2 İşaretçiler

- `lt` (less than): pivotun (eşitler bloğunun başının) bulunduğu yer; başta `low`.
- `i`: incelenen eleman; başta `low + 1`.
- `gt` (greater than): büyükler bölgesinin bir öncesi; başta `high`.

Üç durum vardır:

- `a[i] < pivot`: `a[lt]` ile `a[i]` yer değiştirir, `lt` ve `i` bir artar. Küçük eleman eşitler bloğunun başına geçer, blok bir sağa kayar.
- `a[i] > pivot`: `a[i]` ile `a[gt]` yer değiştirir, `gt` bir azalır. `i` artmaz, çünkü sondan gelen eleman henüz incelenmemiştir. Hoca bunu "büyük olanı hiç düşünmeden sona atıyorum" diye anlattı.
- `a[i] == pivot`: yalnız `i` bir artar, yer değiştirme yapılmaz.

İşlem `i > gt` olunca biter.

### 8.3 Birinci örnek: pivot 3

Başlangıç dizisi (ekrandan, 01:55:00): 3 4 2 8 3 6 1 3 3 7 2. Hoca anlatım sırasında bir adımı karıştırıp düzeltti; aşağıdaki adımlar algoritmanın kurallarına göre python ile izlenmiştir.

| Adım | İncelenen | İşlem | Dizi |
|---|---|---|---|
| 1 | 4 > 3 | `gt` ile değiş, `gt--` | 3 2 2 8 3 6 1 3 3 7 4 |
| 2 | 2 < 3 | `lt` ile değiş, `lt++`, `i++` | 2 3 2 8 3 6 1 3 3 7 4 |
| 3 | 2 < 3 | `lt` ile değiş, `lt++`, `i++` | 2 2 3 8 3 6 1 3 3 7 4 |
| 4 | 8 > 3 | `gt` ile değiş, `gt--` | 2 2 3 7 3 6 1 3 3 8 4 |
| 5 | 7 > 3 | `gt` ile değiş, `gt--` | 2 2 3 3 3 6 1 3 7 8 4 |
| 6 | 3 = 3 | `i++` | aynı |
| 7 | 3 = 3 | `i++` | aynı |
| 8 | 6 > 3 | `gt` ile değiş, `gt--` | 2 2 3 3 3 3 1 6 7 8 4 |
| 9 | 3 = 3 | `i++` | aynı |
| 10 | 1 < 3 | `lt` ile değiş, `lt++`, `i++` | 2 2 1 3 3 3 3 6 7 8 4 |

`i > gt` olduğu için işlem biter. Sonuç: küçükler 2 2 1, eşitler 3 3 3 3, büyükler 6 7 8 4.

> **Ders sonrası not:** Hoca sonucu "2-1-3-3-3-6-7-8" diye özetledi (01:57:50); bu özet bazı elemanları atlıyor. Kurallara göre tam sonuç 2 2 1 | 3 3 3 3 | 6 7 8 4'tür (python ile doğrulandı). Üç bölge yalnız pivota göre ayrılmıştır, bölgelerin kendi içi sıralı değildir.

### 8.4 İkinci örnek: pivot 4

Hoca karışık gelmiş olabileceğini düşünerek ikinci bir örnek çözdü. Dizi (ekrandan, 02:00:00): 4 2 4 6 4 8 7 3 4 1 5. Hareket ettirilen eleman pivotun kendisidir.

| Adım | İncelenen | İşlem | Dizi |
|---|---|---|---|
| 1 | 2 < 4 | pivot ile değiş, `lt++`, `i++` | 2 4 4 6 4 8 7 3 4 1 5 |
| 2 | 4 = 4 | `i++` | aynı |
| 3 | 6 > 4 | `gt` ile değiş, `gt--` | 2 4 4 5 4 8 7 3 4 1 6 |
| 4 | 5 > 4 | `gt` ile değiş, `gt--` | 2 4 4 1 4 8 7 3 4 5 6 |
| 5 | 1 < 4 | `lt` ile değiş, `lt++`, `i++` | 2 1 4 4 4 8 7 3 4 5 6 |
| 6 | 4 = 4 | `i++` | aynı |
| 7 | 8 > 4 | `gt` ile değiş, `gt--` | 2 1 4 4 4 4 7 3 8 5 6 |
| 8 | 4 = 4 | `i++` | aynı |
| 9 | 7 > 4 | `gt` ile değiş, `gt--` | 2 1 4 4 4 4 3 7 8 5 6 |
| 10 | 3 < 4 | `lt` ile değiş, `lt++`, `i++` | 2 1 3 4 4 4 4 7 8 5 6 |

`i > gt` olunca işlem kesilir. Sonuç hocanın söylediğiyle aynıdır: 2 1 3 | 4 4 4 4 | 7 8 5 6 (python ile doğrulandı).

Pivota eşit bir elemanla karşılaşınca hiç yer değiştirmeden ilerlenir. Çoğunluğu birbirine eşit elemanlardan oluşan bir veri üzerinde çalışılıyorsa bu bir avantajdır.

### 8.5 Sözde kod

Tahtadaki program parçası (ekrandan, 02:05:00):

```text
lt = low;   i = low + 1;   gt = high;      piv = a[low]
while (i <= gt)
{
    if (a[i] < pivot)
    {
        a[lt] <-> a[i]
        i++;  lt++;
    }
    if (a[i] > pivot)
    {
        a[i] <-> a[gt]
        gt--;
    }
    else
        i++;
}
```

> **Ders sonrası not:** Tahtada ikinci koşul `if` olarak yazılmış; doğrusu `else if (a[i] > pivot)`'tur. Aksi halde birinci dal çalıştıktan sonra aynı turda yeni `a[i]` için ikinci koşul da denetlenir ve `else` dalı fazladan `i++` yapabilir. Ayrıca hoca anlatırken büyük eleman için sondaki indisin "bir arttırıldığını" söyledi (02:04:16); tahtadaki ve doğru olan `gt--`'dir.

### 8.6 Özyinelemeli çağrı

Bölümleme sonunda pivota eşit elemanlar bir blok halindedir. Klasik quick sort'ta pivot tek bir konumdu ve öncesi ile sonrası ayrı işlenirdi. Burada quick sort, bloğun başlangıcından öncesi ve bitişinden sonrası için çağrılır; bloğun içi bir daha işlenmez. Tahtadaki örnekte 2 1 3 4 | 5 5 5 5 | 7 18 9 15 11 dizisinde 5'lerin solu ve sağı ayrı ayrı sıralanır (ekrandan, 02:10:00). Bu, eşit elemanların çok olduğu bilinen durumlarda yer değiştirme sayısını azaltan bir iyileştirmedir.

## 9. Küçük Parçalar İçin Insertion Sort

Bölümleme ilerledikçe parçalar küçülür. Başta bir milyon eleman olsa da bir noktada 10-15 elemanlık parçalar kalır. Az elemanlı bir parçaya quick sort uygulamak etkin değildir, çünkü özyinelemeli fonksiyonların alt program (fonksiyon) çağırma yükü vardır.

Bu yüzden pratikte parçanın büyüklüğü (`high - low`) bir $M$ eşiğinin altına inince (genelde 10-15 eleman civarı) quick sort yerine insertion sort uygulanır. Hoca Java'nın sıralama için quick sort kullandığını ve aynı kontrolü yaptığını söyledi. Tahtadaki örnekte pivot 8'in solunda kalan 2 4 7 3 5 1 parçası artık özyinelemeyle bölünmez, insertion sort ile sıralanır (ekrandan, 02:10:00).

**Soru:** Küçük parçalarda hangi sıralama kullanılır? Selection sort olabilir mi?

**Cevap:** Insertion sort kullanılır. Bir öğrenci sebebini, insertion sort'un sıralıya yakın dizilerde daha iyi çalışması olarak hatırladı ve bu doğrudur. Örneğin 2 3 5 yerleşmiş ve 4 eklenecekse insertion sort 4'ü önce 5 ile, sonra 3 ile karşılaştırır; 3 küçük olduğu için durur ve 4'ü araya yerleştirir. Dizinin başına kadar gitmesi gerekmez. Selection sort ise her adımda bakılan bölgenin en küçüğünü bulmak için bütün bölgeyi taramak zorundadır. İkisinin de en kötü durumu $n^2$'dir, ama insertion sort pratikte daha hızlıdır. Bu yüzden küçük dizilerde insertion sort daha avantajlıdır.

> **Ek bilgi (derste anlatılmadı):** Güncel Java sürümlerinde ilkel tipler için `Arrays.sort` iki pivotlu (dual-pivot) bir quick sort kullanır ve büyük olasılıkla birkaç on elemanın altındaki parçalarda insertion sort'a geçer. Nesne dizilerinde ise merge sort tabanlı TimSort kullanılır.

## Örnek Sorular

### Soru 1

(ekrandan, 00:05:00) $f(n) = 2n+5 \in \Theta(n)$ olduğunu uygun $c_1$, $c_2$ ve $n_0$ bularak gösterin.

> **Çözüm (derste verildi):** $c_2 = 1$, $n_0 = 1$ ile $2n+5 \ge n$ her zaman sağlanır. $n_0 = 1$ için $2n+5 = 7$ olduğundan $c_1 \ge 7$ olmalıdır; $c_1 = 7$ ile $2n+5 \le 7n$ her $n \ge 1$ için sağlanır. Böylece $n \le 2n+5 \le 7n$ ve $2n+5 \in \Theta(n)$.

### Soru 2

(ekrandan, 00:30:00) 5 3 1 9 8 2 4 7 dizisini, ilk elemanı pivot alan quick sort ile sıralayın; her bölümlemeden sonraki diziyi ve pivotun yerleştiği indisi yazın.

> **Çözüm (derste verildi):** (0, 7): 2 3 1 4 5 8 9 7, $s = 4$. (0, 3): 1 2 3 4, $s = 1$. (2, 3): değişiklik yok, $s = 2$. (5, 7): 7 8 9, $s = 6$. Sonuç: 1 2 3 4 5 7 8 9.

### Soru 3

(derste sözlü, 00:36:21) Bölümleme $l = 0$, $r = 7$ aralığında pivotu $s = 4$'e yerleştirdi. Sol parçanın sağ sınırı ve sağ parçanın sol sınırı nedir?

> **Çözüm (derste verildi):** Sol parça $l = 0$, $r = s - 1 = 3$; sağ parça $l = s + 1 = 5$, $r = 7$. Sol parçada yalnız sağ sınır, sağ parçada yalnız sol sınır değişir.

### Soru 4

(derste sözlü, 00:44:47) Quick sort hangi koşulda durmalıdır?

> **Çözüm (derste verildi):** $l \ge r$ olduğunda. $l = r$ tek eleman, $l > r$ boş aralık demektir; algoritma yalnız $l < r$ iken bölümleme yapar.

### Soru 5

(derste sözlü, 01:09:25) $n$ elemanlı bir dizide bir sayıdan küçükleri bir tarafa, büyükleri diğer tarafa yerleştirmenin (bölümlemenin) karmaşıklığı nedir? O, Θ ve Ω'dan hangisiyle yazılmalıdır?

> **Çözüm (derste verildi):** Her durumda bütün elemanlara bakılır ve en fazla $n$ mertebesinde yer değiştirme yapılır: $c \cdot n$. Ne $n^2$'ye çıkar ne $\log n$'e iner; bu yüzden $\Theta(n)$ yazılır.

### Soru 6

(derste sözlü, 01:24:42) Quick sort'ta en kötü duruma düşmemek için pivot nasıl seçilebilir?

> **Çözüm (derste verildi):** Bakılan bölgenin ortasındaki eleman seçilebilir; dizi başta bir kez karıştırılabilir; ya da rastgele seçilen üç elemanın medyanı pivot alınabilir. Hangisi seçilirse seçilsin pivot önce dizinin başına taşınır.

### Soru 7

(derste sözlü, 01:31:16) En kötü duruma düşme olasılığını azaltmak için neden bu kadar uğraşılır?

> **Çözüm (derste verildi):** Sistemler ortalama duruma göre planlanır; en kötü durum gerçekleştiğinde (deprem anında telefon şebekesinin kilitlenmesi gibi) sistem yükü kaldıramaz. Zamanın kritik olduğu uygulamalarda en kötü duruma düşmek ciddi gecikme yaratır.

### Soru 8

(ekrandan, 02:00:00) 4 2 4 6 4 8 7 3 4 1 5 dizisine pivot 4 ile Dijkstra'nın üç yollu bölümlemesini uygulayın.

> **Çözüm (derste verildi):** Sonuç 2 1 3 | 4 4 4 4 | 7 8 5 6. Adımlar 8.4'teki tablodadır.

### Soru 9

(derste sözlü, 02:07:46) Quick sort'ta parça boyu 10-15 elemanın altına inince hangi sıralama kullanılır ve neden selection sort değil de o?

> **Çözüm (derste verildi):** Insertion sort. Özyinelemeli çağrı yükü küçük parçalarda kazancı aşar. Insertion sort, yerleştireceği elemandan küçük bir eleman bulunca durur ve sıralıya yakın dizilerde hızlıdır; selection sort ise her adımda kalan bölgenin tamamını tarayıp en küçüğü bulmak zorundadır.

## Dersin Toparlaması

Ders, $2n+5 \in \Theta(n)$ örneğinin sabitlerinin düzeltilmesiyle başladı ve böl ve yönet sıralamalarının ikinci büyük temsilcisi olan quick sort ile devam etti. Quick sort bir pivot seçer, bölümleme ile pivottan küçükleri ve büyükleri ayırır ve pivotu son konumuna yerleştirir. Ardından sol ve sağ parçayı bağımsız olarak özyinelemeli sıralar. 5 3 1 9 8 2 4 7 örneğinde bölümleme adımları ve özyinelemeli çağrıların sırası ayrıntılı izlendi, ardından sözde kod yazıldı.

Karmaşıklık analizinde bölümlemenin her durumda $\Theta(n)$ olduğu gösterildi. Pivot hep ortada olursa $T(n) = 2T(n/2) + cn$ ile $\Theta(n \log n)$, dizi sıralıysa $T(n) = T(n-1) + cn$ ile $\Theta(n^2)$, ortalamada yaklaşık $1.39\, n \log n$ elde edilir. En kötü durumdan kaçınmak için orta eleman, karıştırma ve üç rastgele elemanın medyanı gibi pivot seçme yöntemleri tartışıldı. Son olarak çok tekrar eden anahtarlar için Dijkstra'nın üç yollu bölümlemesi iki örnekle anlatıldı. Küçük parçalarda özyineleme yerine insertion sort kullanmanın neden avantajlı olduğu da açıklandı.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
