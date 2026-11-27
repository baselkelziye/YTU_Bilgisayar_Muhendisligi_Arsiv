# Ders 5 Genişletilmiş Notu: Merge Sort Tekrarı ve Quicksort: Hoare Bölümlemesi, Karmaşıklık Analizi ve Üç Yollu Bölümleme

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Özyinelemeli bağıntılarda sık yapılan hatalar
- 2. Merge Sort tekrarı
- 3. Sıralama algoritmalarının süre karşılaştırması
- 4. Quicksort'un mantığı ve animasyonla çalışması
- 5. Kitap örneğinin elle izlenmesi
- 6. Quicksort sözde kodu ve Hoare bölümlemesi
- 7. Hibrit kullanım ve özyineleme yükü
- 8. Quicksort'un en iyi, en kötü ve ortalama durum analizi
- 9. Üç yollu bölümleme (3-way partitioning)
- 10. Insertion Sort ile hibrit yapı ve en kötü durumdan kaçınma
- 11. Böl ve yönetin diğer örnekleri (slayt özeti)
- Örnek Sorular

## 1. Özyinelemeli bağıntılarda sık yapılan hatalar

Ders, bir önceki haftada işlenen böl ve yönet (divide and conquer) tekniğinin kısa bir tekrarıyla başladı. Böl ve yönet algoritmalarının çoğu özyinelemelidir (özyinelemeli olmayanları da vardır); ortak noktaları, problemi daha küçük parçalara ayırıp her parçayı çözmek ve parça çözümlerini birleştirmektir. Problem bölündüğü için çözümlemede Master teoremi kullanılır.

### 1.1 Geriye yerine koymada argüman hatası

Hoca, $T(n) = T(n-1) + n$ bağıntısının geriye yerine koyma (backward substitution) yöntemiyle açılışında birkaç kişinin aynı hatayı yaptığını belirtip doğrusunu tahtada gösterdi (ekrandan, 00:05:00). Hatalı açılım şuydu:

$$T(n) = T(n-1) + n = T(n-2) + n + n \quad (\text{yanlış})$$

$T(n-1)$'in açılımı, bağıntıda $n$ yerine $n-1$ yazılarak bulunur: $T(n-1) = T(n-2) + (n-1)$. Bu yüzden eklenen terim $n$ değil $n-1$ olmalıdır:

$$
\begin{aligned}
T(n) &= T(n-1) + n \\
&= T(n-2) + (n-1) + n \\
&= T(n-3) + (n-2) + (n-1) + n \\
&\;\;\vdots \\
&= T(n-k) + (n-k+1) + \dots + (n-1) + n
\end{aligned}
$$

$k$ öyle seçilir ki $n-k$ başlangıç koşuluna ($T(0)$ ya da $T(1)$, hangisi verilmişse) iner. Bu durumda geriye $1$'den $n$'e kadar sayıların toplamı kalır:

$$T(n) = T(0) + \sum_{i=1}^{n} i = T(0) + \frac{n(n+1)}{2} \in \Theta(n^2)$$

Hoca bu sonucu sezgiyle de açıkladı: $n$ boyutlu bir girişte problem her adımda bir küçülerek $n$ kez derinleşir ($n-1, n-2, \dots, 0$) ve her seviyede $n$'e bağlı bir iş yapılır; bu da $n^2$ mertebesinde bir karmaşıklık demektir.

### 1.2 Master teoreminin uygulanma koşulu

Dikkat çekilen ikinci hata, Master teoreminin uygun olmayan bağıntılara uygulanmasıydı. Derste kullanılan Master teoremi yalnız şu biçimdeki bağıntılara uygulanır:

$$T(n) = a\,T(n/b) + f(n)$$

Yani problem $b$'ye **bölünerek** alt parçalara ayrılmalıdır. $T(n-1)$ gibi eksiltmeli (azalt ve fethet tipi) bağıntılar için bu teorem kullanılmaz; hoca bunlar için ayrı bir Master teoremi bulunduğunu ama derste anlatılmayacağını söyledi.

> **Hocanın vurgusu:** Böl ve yönet için kullanılan Master teoreminde $T(n-1)$ gibi eksiltmeli bir terim olmaz; teorem, problemin alt parçalara bölündüğü durumda uygulanır.

## 2. Merge Sort tekrarı

### 2.1 Algoritma

Merge Sort diziyi olabilecek en küçük parçalara böler: önce yarısını, sonra onun yarısını alır ve tek eleman kalınca özyinelemeli bölme sona erer (tek eleman daha fazla bölünemez). Ardından parçalar birleştirilir (merge). Birleştirmede iki parçanın başındaki elemanlardan küçük olan yedek bir diziye kopyalanır; yedek dizi bitince asıl dizideki ilgili yere geri kopyalanır ve diğer özyinelemeli çağrılara geçilir.

Tahtadaki kod (ekrandan, 00:10:00; parça kod, derlenmedi):

```c
void MS(int A[], int p, int r)
{
    if (p < r)            /* # of elements > 1 */
    {
        q = (p + r) / 2;
        MS(A, p, q);
        MS(A, q + 1, r);
        merge(A, p, q, r);
    }
}

merge(int A, p, q, r) {
    int i, j, k, n, *B;   /* B: malloc */
    while ((i <= q) && (j <= r))
    {
        if (A[i] <= A[j])
            B[k++] = A[i++];
        else
            B[k++] = A[j++];
    }
    while (i <= q) B[k++] = A[i++];
    while (j <= r) B[k++] = A[j++];
    copy(A, B);
}
```

### 2.2 En iyi ve en kötü durum

Bölme kısmında en iyi ya da en kötü durum yoktur; elemanlar nasıl olursa olsun dizi ikiye bölünür. Birleştirme kısmında farklı durumlar olabilir ama sonucu değiştirmez. Örneğin $1, 3, 5$ ile $2, 4, 6$ birleştirilirken elemanlar sırayla bir üst diziden bir alt diziden alınır ve ilk `while` döngüsü neredeyse $n$ kez döner. Bir parça erken biterse ilk döngüdeki karşılaştırma sayısı azalır ama kalan elemanlar alttaki `while` döngülerinde kopyalanır. Temel operasyon atama alınırsa her durumda tam $n$ atama yapılır. Bu yüzden her birleştirme $\Theta(n)$'dir.

### 2.3 Bağıntı ve Master teoremi

Koddan bağıntı doğrudan kurulur: iki tane $T(n/2)$'lik özyinelemeli çağrı ve her çağrıda $cn$ kadar birleştirme maliyeti vardır:

$$T(n) = 2T(n/2) + cn$$

Master teoremi için $a = 2$, $b = 2$ ve $f(n) \in \Theta(n^d)$ ile $d = 1$'dir. $a = b^d$ ($2 = 2^1$) olduğundan:

$$T(n) \in \Theta(n^d \log n) = \Theta(n \log n)$$

Sezgisel olarak da dizi $\log n$ kez bölünür ve her seviyede $n$ iş yapılır.

### 2.4 Animasyonda Merge Sort

Hoca bir animasyon sitesindeki Merge Sort gösterimini adım adım izletti (ekrandan, 00:15:00 ve 00:25:00). Orada birleştirme kodu ana fonksiyonun devamına yazılmıştı:

```text
MERGESORT (beg, end):
  IF beg < end THEN
     m = (beg+end)/2
     MERGESORT (beg, m)
     MERGESORT (m+1, end)
     FOR i = beg TO m
        x[i] = a[i]
     FOR i = m+1 TO end
        j = end + m+1 - i
        x[j] = a[i]
     i = beg
     j = end
     FOR k = beg TO end
        IF x[i] < x[j] THEN
           a[k] = x[i]
           increase i
        ELSE
           a[k] = x[j]
           decrease j
```

8 elemanlı dizide çağrı önce $(0, 7)$ ile başlar, orta nokta bulunur ve $(0, 3)$, sonra $(0, 1)$, sonra $(0, 0)$ çağrılır. $(0, 0)$'da `IF` koşulu sağlanmadığı için çağrı geri döner ve bir sonraki satıra ($(1, 1)$ çağrısı) geçilir. İki tek elemanlı parça hazır olunca birleştirme yapılır. Bu sürümde ikinci yarı yedek `x` dizisine **ters sırada** kopyalanır; böylece $i$ baştan, $j$ sondan ilerleyerek iki uçtan birleştirme yapılır. Hoca, döngülerin `while` yerine `for` ile yazılmasının ya da kopyalamanın farklı yapılmasının bellek ve işlem açısından önemli bir fark yaratmadığını belirtti.

Merge Sort'un farklı varyasyonları vardır: özyinelemeli yerine iteratif yazılabilir ya da yedek dizi kullanmadan yerinde (in-place) yapılmaya çalışılabilir. Hoca, yerinde Merge Sort'u doğru uygulayanların $n^2$'ye yaklaşan bir süre elde ettiğini söyledi; bellek kazancı hız kaybıyla ödenir.

## 3. Sıralama algoritmalarının süre karşılaştırması

Merge Sort'un $n^2$'lik Selection Sort ve Insertion Sort'a göre $n \log n$'ye inmesi büyük bir hız kazancıdır. Hoca, normal bir bilgisayarda yapılmış bir ölçümün sonuçlarını sözlü olarak aktardı:

| Eleman sayısı | Insertion Sort | Merge Sort | Quicksort |
|---|---|---|---|
| Bin | anında | anında | anında |
| Milyon | yaklaşık 2,8 saat | yaklaşık 1 saniye | yaklaşık 0,6 saniye |
| Milyar | (söylenmedi) | yaklaşık 18 dakika | yaklaşık 12 dakika |

**Soru:** Merge Sort ile Quicksort arasında 1 saniye ile 0,6 saniyelik fark nereden geliyor?
**Cevap:** Bu bir bilgisayarda yapılmış bir zaman ölçme deneyidir; iki algoritmanın birebir aynı süreyi vermesi beklenmez. Merge Sort'ta swap yoktur, kopyalama vardır; Quicksort'ta swap yapılır. Bunların makine (assembly) düzeyindeki maliyetleri farklıdır. Uygulama ayrıntıları da etkilidir: birinde swap için fonksiyon kullanılıp diğerinde kullanılmaması gibi. Ayrıca Merge Sort her seviyede elemanları ikişer ikişer mutlaka karşılaştırır; Quicksort'ta ise bir eleman tek bir swap ile çok uzak bir konuma (örneğin 5. konumdan 0. konuma) bir adımda taşınabilir. Daha ayrıntılı analizde ortaya çıkan $n^2 + n$, $n^2 + 5n$ gibi alt terimler bu tür süre farklarını açıklar. Ama asıl odak, Big-O ya da Big-Theta'daki temel fonksiyon sınıfıdır.

> **Hocanın vurgusu:** Kayda değer (istatistiksel olarak anlamlı) fark, $n^2$ olan Insertion Sort'un 2,8 saati ile $n \log n$ olan algoritmaların 1 ya da 0,6 saniyesi arasındaki farktır. Aynı sınıftaki iki algoritma arasındaki küçük fark göz ardı edilebilir.

## 4. Quicksort'un mantığı ve animasyonla çalışması

### 4.1 Temel fikir

Quicksort hem adından da anlaşılacağı gibi hızlı hem de bellek açısından verimli bir algoritmadır. Bir eleman **pivot** (referans) olarak seçilir ve bu elemanın dizide olması gereken gerçek yer bulunur. Bunu Insertion Sort mantığıyla yapmak kaydırma (shift) işlemleri gerektirir. Bunun yerine diziye iki uçtan bakılır: solda pivottan büyük bir eleman, sağda pivottan küçük bir eleman bulununca bu ikisi tek bir swap ile yer değiştirir. Böylece tek bir arama adımında iki eleman birden doğru tarafa taşınmış olur; bu da zaman verimliliği sağlar.

Pivot yerine oturunca solundakilerin tümü pivottan küçük (ya da eşit), sağındakilerin tümü büyük (ya da eşit) olur. Ardından sol ve sağ taraf aynı yöntemle, yeni pivotlar seçilerek kendi içinde sıralanır. Bulunan yer diziyi tam ortadan iki eşit parçaya bölerse bölme çok iyi olmuş olur.

Bu işlemler ek dizi gerektirmez; en fazla swap için bir geçici değişken kullanılır. Merge Sort'un yedek dizi ihtiyacı burada yoktur. Bu yüzden Quicksort yerinde (in-place) bir algoritmadır.

Tahtadaki tanım (ekrandan, 00:35:00):

$$\underbrace{A[0] \dots A[p-1]}_{\text{hepsi } \le A[p]} \quad A[p] \quad \underbrace{A[p+1] \dots A[n-1]}_{\text{hepsi } \ge A[p]}$$

Hoca, bazı kaynaklarda eşitliğin sol tarafa, bazılarında sağ tarafa konduğunu ve bunun önemli olmadığını söyledi.

### 4.2 Animasyondaki sürüm

Animasyon sitesindeki Quicksort'ta pivot ortadaki eleman seçiliyordu (ekrandan, 00:20:00 ve 00:30:00):

```text
QUICKSORT (beg, end):
   i = beg
   j = end
   pivot = a[(i+j)/2]
   WHILE i <= j
      WHILE a[i] < pivot
         increase i
      WHILE a[j] > pivot
         decrease j
      IF i <= j THEN
         swap a[i] a[j]
         increase i
         decrease j
   IF beg < j THEN
      QUICKSORT (beg, j)
   IF i < end THEN
      QUICKSORT (i, end)
```

İşleyiş: $i$ ve $j$ birbirini geçmediği sürece ($i \le j$) iki uçtan kontrol yapılır. $i$, pivottan küçük eleman gördükçe ilerler ve büyük-eşit bir elemanda durur. $j$, pivottan büyük eleman gördükçe geriler ve küçük-eşit bir elemanda durur. $i \le j$ ise iki eleman yer değiştirir, $i$ bir artar, $j$ bir azalır ve dış döngünün başına dönülür. Animasyonda $j$ sonunda pivotun bulunduğu yere gelir; $A[j]$ pivottan büyük olmadığı (eşit olduğu) için durur, $i \le j$ olduğundan swap yapılır ve pivot asıl yerine oturur. Dış döngü bitince bölümleme (partition) tamamlanır: pivot (örnekte $A[2]$) yerindedir, solundakiler kesinlikle ondan küçük, sağındakiler büyüktür. Sonra `beg < j` ise sol parça, `i < end` ise sağ parça için yeni çağrı yapılır.

Hoca, bu algoritmayı C'de kendiniz yazmanızı önerdi; dersin ilerleyen kısımlarında da karşınıza çıkacaktır. Sitede Bubble Sort gibi başka algoritmaların animasyonları da bulunuyor.

## 5. Kitap örneğinin elle izlenmesi

Hoca, ders kitabındaki $5, 3, 1, 9, 8, 2, 4, 7$ örneğini ilk eleman ($5$) pivot olacak biçimde elle izledi ve bunu öğrencilerin kendilerinin de yapmasını, hatta kodunu yazmasını önerdi (ekrandan, 00:40:00; derste sözlü, 00:35:18).

- Başlangıç: $5, 3, 1, 9, 8, 2, 4, 7$; pivot $p = 5$.
- $i$, $5$'ten büyük görene kadar ilerler: $3$ ve $1$ küçük, $9$'da durur. $j$, $5$'ten küçük görene kadar geriler: $7$ büyük, $4$'te durur.
- $9$ ile $4$ yer değiştirir: $5, 3, 1, 4, 8, 2, 9, 7$.
- Arama sürer: $i$ $8$'de, $j$ $2$'de durur. $8$ ile $2$ yer değiştirir: $5, 3, 1, 4, 2, 8, 9, 7$.
- Arama sürer: $i$ $8$'e, $j$ $2$'ye gelir; işaretçiler birbirini geçtiği için döngü durur.
- Pivot, $j$'nin gösterdiği eleman ($2$) ile yer değiştirir: $2, 3, 1, 4, 5, 8, 9, 7$.

Sonuçta $5$ gerçek yerindedir: solundaki $2, 3, 1, 4$ hepsi $5$'ten küçük, sağındaki $8, 9, 7$ hepsi büyüktür. Bölümleme biter ve Quicksort önce sol, sonra sağ parça için yeniden çağrılır; her parçada yine bir pivot seçilip yeri bulunur.

> **Ders sonrası not:** Hoca ilk denemede $j$'nin $4$'ü atladığını varsayıp $9$ ile $2$'yi değiştirdi; bir öğrencinin uyarısıyla düzeltildi. Doğru ilk swap $9 \leftrightarrow 4$'tür. Yukarıdaki adımlar python ile doğrulandı.

Hoca, döngü durduğunda pivotun nereye konacağı için iki yol olduğunu söyledi: $i$'nin bir önceki yeri geçici olarak tutulabilir ya da (bu algoritmada olduğu gibi) $j$'nin gösterdiği yer kullanılır.

## 6. Quicksort sözde kodu ve Hoare bölümlemesi

### 6.1 Quicksort

Tahtaya yazılan sözde kod (ekrandan, 00:45:00):

```text
QSort(A[l..r])
   if l < r
      s <- Partition(A[l..r])
      QSort(A[l..s-1])
      QSort(A[s+1..r])
```

Önce pivotun yeri belirlenir (dizi iki parçaya bölünür), sonra pivotun solundaki ve sağındaki parçalar aynı fonksiyonla sıralanır. Hoca, bunun C'de yalnız birkaç satır tuttuğunu belirtti. Farklı kaynaklarda bölümleme farklı yapılır; örneğin bir kaynakta pivot için yer önce baştan, sonra sondan aranıyor. Derste anlatılan sürüm hem kullanışlı hem de verimli bir yöntemdir.

### 6.2 Pivot seçimi

Pivot ilk eleman, son eleman ya da ortadaki eleman seçilebilir. Ortadaki eleman tam olarak medyan sayılmaz, çünkü dizi sıralı değildir. Hoare bölümlemesinde pivot ilk elemandır.

### 6.3 Hoare bölümlemesi

Tahtadaki sözde kod (ekrandan, 00:50:00):

```text
Partition(A[l..r])
   p <- A[l]
   i = l
   j = r
   repeat
      repeat i <- i+1  until A[i] >= p
      repeat j <- j-1  until A[j] <= p
      swap(A[i], A[j])
   until i >= j
   swap(A[i], A[j])      // son swap geri alınır
   swap(A[l], A[j])      // pivot yerine konur
   return j
```

`repeat ... until` yapısı `while`'ın tersi gibi çalışır: döngü koşul sağlanana kadar tekrar eder. $i$, pivottan küçük elemanları geçerek ilerler ve $A[i] \ge p$ olduğunda durur; $j$, pivottan büyük elemanları geçerek geriler ve $A[j] \le p$ olduğunda durur. Hoca, bu koşullarda eşitliğin dahil edilip edilmemesinin çok önemli olmadığını söyledi. Dış döngü, işaretçiler birbirini geçince ($i \ge j$) biter.

Döngüden sonraki iki swap şu işe yarar: işaretçiler birbirini geçtikten sonra yapılan son swap yanlıştır ve ilk swap ile geri alınır (bir adım geri alma gibi). İkinci swap pivotu ($A[l]$) $A[j]$ ile değiştirerek gerçek yerine koyar. Kitap örneğinde son adımda $8$ ile $2$ önce yer değiştirir, sonra bu değişim geri alınır ve $2$ ile $5$ yer değiştirerek $5$ yerine oturur. Ek bellek gerekmez; yalnız swap için bir geçici değişken kullanılır.

> **Ders sonrası not:** Tahtada başlangıç `j = r` yazıldı (hoca `right` ile `right-1` arasında kısa bir tartışma da yaptı). `repeat j ← j−1` önce azalttığı için bu başlangıçla $A[r]$ hiç pivotla karşılaştırılmaz. Doğrusu, Levitin'deki gibi `j = r + 1`'dir. Dış döngünün bitiş koşulu tahtada $i > j$ gibi okunuyor, hoca sözlü olarak "i büyük eşit j olana kadar" dedi; Levitin'de `until i ≥ j`'dir.

> **Ek bilgi (derste anlatılmadı):** Levitin'in bu sürümünde $i$, $A[l..r]$'de pivottan büyük-eşit eleman yoksa dizinin sonunu aşabilir. Bunu önlemek için ya $i$ için ayrıca $i \le r$ denetimi konur ya da dizinin sonuna bir bekçi (sentinel) eleman eklenir.

## 7. Hibrit kullanım ve özyineleme yükü

Aradan sonra Y. Daniel Liang'ın bölümleme animasyonu üzerinde tekrar yapıldı (ekrandan, 01:05:00). Bu animasyonda ilk eleman pivottur; `low` soldan pivottan büyük eleman görene kadar, `high` sağdan pivottan küçük eleman görene kadar ilerler ve bulunan elemanlar yer değiştirir. Bir denemede pivot dizinin en küçük elemanı çıktı: `high` neredeyse dizinin başına kadar gelmek zorunda kaldı ve pivot yerinden hiç oynamadı. Hoca bunun Quicksort'un en kötü pivot seçimi durumunu iyi örneklediğini söyledi; ters sıralı ya da neredeyse sıralı dizilerde aynı durum ortaya çıkar. Başka bir denemede daha makul bir pivot ($54$) seçildi; $87$ ile $23$ gibi eleman çiftleri yer değiştirdi ve sonunda $54$'ün solunda hep küçük, sağında hep büyük sayılar kaldı.

Quicksort özyinelemeli olduğu için fonksiyon çağrılarının bir yükü (overhead) vardır; iteratif bir sürüm hiç fonksiyon çağrısı yapmadan ilerlerdi. Bu yüzden Java'nın hazır dizi sıralama fonksiyonu ve birçok başka uygulamada Quicksort, Insertion Sort ile hibrit kullanılır: eleman sayısı yaklaşık 10-11'in altına düşünce Insertion Sort çalışır. Örneğin 500 elemanlı dizide pivot 300. konuma oturduysa sol taraftaki 300 eleman yine bölünür; sol tarafın pivotu 15. konuma oturduysa kalan 15 eleman için Quicksort'u tekrar çağırmak yerine Insertion Sort çağrılır. Özyinelemeli çağrılardan iteratif yapı ve benzeri küçük değişikliklerle kurtulmak mümkündür.

> **Ders sonrası not:** Hoca eşiği yaklaşık 10 olarak verdi. Java 7 ve sonrasında ilkel diziler için kullanılan çift pivotlu Quicksort'ta Insertion Sort eşiği büyük olasılıkla 47 elemandır; eşik uygulamaya göre değişir.

## 8. Quicksort'un en iyi, en kötü ve ortalama durum analizi

Analiz için kod kısaca tekrar yazıldı (ekrandan, 01:10:00):

```text
QuickSort(A[l..r]) {
   if (l < r)
   {  s = partition( )
      QuickSort(A[l..s-1])
      QuickSort(A[s+1, r])
   }
}
```

### 8.1 En iyi durum

En iyi durumda pivot her seferinde dizinin ortasına düşer (pivot is in the middle). Dizi iki eşit parçaya bölünür ve iki tane $T(n/2)$'lik özyinelemeli çağrı yapılır. Buna bölümlemenin maliyeti eklenir:

$$
T(n) =
\begin{cases}
\Theta(1), & n = 0, 1 \\
2T(n/2) + n, & \text{aksi halde}
\end{cases}
$$

Tek eleman varsa sol ve sağ sınır aynıdır; yalnız bir karşılaştırma yapılıp dönülür, bu da $\Theta(1)$'dir.

Bölümlemenin maliyetinin neden $n$ olduğu şöyle açıklandı: temel operasyon karşılaştırmadır. $i$ soldan, $j$ sağdan karşılaştıra karşılaştıra gelir ve buluşur. İki işaretçi birlikte çalıştığı için her biri yolun bir kısmını yürür ama toplam karşılaştırma yine yaklaşık $n$'dir. Örneğin $n = 100$ iken $i$ 30 karşılaştırma yaparak, $j$ 70 karşılaştırma yaparak gelirse toplam 100 karşılaştırma olur. Bu yüzden $n$ elemanlı bir parçada bölümleme her durumda yaklaşık $n$ karşılaştırma yapar.

**Master teoremi ile:** $a = 2$, $b = 2$, $d = 1$; $2 = 2^1$ olduğundan $T(n) \in \Theta(n \log n)$.

**Geriye yerine koyma ile (ekrandan, 01:15:00):**

$$
\begin{aligned}
T(n) &= 2T(n/2) + n \\
&= 2\left[2T(n/4) + n/2\right] + n = 4T(n/4) + 2n \\
&= 8T(n/8) + 3n \\
&\;\;\vdots \\
&= 2^i\,T(n/2^i) + i \cdot n
\end{aligned}
$$

$n/2^i = 1$, yani $i = \log_2 n$ alınınca $T(n) = n\,T(1) + n\log_2 n \in \Theta(n \log n)$ olur.

> **Ders sonrası not:** Tahtada açılım $2 \cdot 2\,T(n/4) + n/2 + n$ ve $2 \cdot 2 \cdot 2\,T(n/8) + n/4 + n/2 + n$ olarak, genel terim de $2^i + T(n/2^i) + n/2^{i-1} + \dots + n$ olarak yazıldı. Hoca "$2^i$ ile $T$ arasında artı değil çarpı var" diyerek ilkini düzeltti. İkinci hata da var: $2T(n/2)$ açılırken içteki $n/2$ terimi de $2$ ile çarpılır, yani her seviye $n/2, n/4$ değil toplam $n$ ekler. Doğru genel terim $2^i\,T(n/2^i) + i \cdot n$'dir; sonuç yine $\Theta(n \log n)$'dir. $T(1) = 0$ ile $T(8) = 24 = 8\log_2 8$ olduğu python ile doğrulandı.

**Özyineleme ağacı ile:** $n$'lik problem $n/2$ ve $n/2$'ye, onlar da $n/4$'lere ayrılır. Her seviyede düğümlerin maliyetleri toplamı yine $n$'dir ($n/2 + n/2 = n$, $4 \cdot n/4 = n$). Ağaç $n/2^i = 1$ olana kadar, yani $\log n$ seviye derinleşir. Toplam maliyet $n \log n$'dir. Hoca, Master teoremi akla gelmezse sonucun bu yolla ya da geriye yerine koymayla da bulunabileceğini söyledi.

### 8.2 En kötü durum

**Soru (derste sözlü):** Quicksort'un en kötü durumu nasıl oluşur?
**Cevap:** Bölümlemenin dengesiz olması gerekir. Bunun temel sebebi dizinin sıralı ya da ters sıralı olması ve pivotun uygun yerden (örneğin baştan ya da sondan) seçilmemesidir.

Örnek: $1, 2, 3, 4, 5, 6$ dizisinde pivot ilk eleman ($1$) seçilsin (ekrandan, 01:20:00). Pivottan küçük eleman yoktur; $i$ hemen durur, $j$ ise dizinin başına kadar gelir. Pivot yerinden hiç oynamaz ve sağ tarafta kalan $n-1$ eleman için aynı işlem tekrarlanır. Her adımda problem yalnız bir eleman küçülür: önce yaklaşık $n$, sonra $n-1$, sonra $n-2$ karşılaştırma yapılır. Toplam $n(n+1)/2$ mertebesinde, yani $n^2$'dir. Ters sıralı dizi ($6, 5, 4, 3, 2, 1$) ya da pivotun sondan seçilmesi de aynı sonucu verir.

Daha ayrıntılı sayım için $1, 2, 3, 4, 5, 6, 7$ dizisi kullanıldı (ekrandan, 01:25:00). İlk bölümlemede $i$ ikinci elemana bakıp durur (1 karşılaştırma), $j$ ise sondan başa kadar $n$ elemana bakar; toplam $n+1$ karşılaştırma yapılır. Sonra sol taraf boş kalır, sağ tarafta yeni pivotla $n$ karşılaştırma, sonra $n-1$ yapılır ve son adımda 3 karşılaştırmaya inilir:

$$C_{worst}(n) = (n+1) + n + (n-1) + \dots + 3 = \frac{(n+1)(n+2)}{2} - 3 \approx n^2 \in \Theta(n^2)$$

Tahtada en kötü duruma yol açan tarama şöyle özetlendi: soldan sağa tarama (left to right scan) ya da sağdan sola tarama (right to left scan) en kötü duruma götürür (lead to worst case). İki tür sebep vardır: kötü pivot seçimi ya da dizinin sıralı veya ters sıralı olması (reverse ordered array; pivot ilk ya da son konumda).

**Soru:** Son adımda 7 ile 6'yı karşılaştırdık; neden 3 karşılaştırma oldu?
**Cevap:** Son parçada pivot $6$'dır. $i$ ile $7$'ye bakılır (1. karşılaştırma). $j$ ile önce $7$'ye (2. karşılaştırma), sonra pivotun kendisine (3. karşılaştırma) bakılır. $i$ indisiyle bir, $j$ indisiyle iki karşılaştırma olduğu için toplam 3 olur. Kitapta da 3 olarak verilir. Hoca, her adımda 1 bile olsaydı sonucun yine $\Theta(n^2)$ olacağını, ama bu ayrıntıyı sormanın algoritmayı ne kadar iyi anladığınızı gösterdiğini söyledi.

### 8.3 Ortalama durum

Ortalama durum için iki kabul yapılır (ekrandan, 01:30:00 ve 01:35:00):

- Dizi rastgele sıralıdır (randomly ordered array).
- Bölme noktası $s$ her konumda ($0 \le s \le n-1$) aynı olasılıkla ($1/n$) oluşabilir. Bu bir kabuldür; en iyi ve en kötü durumlar da bu konumların içindedir.

Her konum için bölümleme $n+1$ karşılaştırma yapar ve iki özyinelemeli çağrı gelir: sol parça için $C_{avg}(s)$, sağ parça için $C_{avg}(n-1-s)$. Bütün konumların ortalaması alınır:

$$C_{avg}(n) = \frac{1}{n}\sum_{s=0}^{n-1}\left[(n+1) + C_{avg}(s) + C_{avg}(n-1-s)\right], \quad n > 1$$

$$C_{avg}(0) = 0, \quad C_{avg}(1) = 0$$

$(n+1)$ terimi $s$'ye bağlı olmadığından toplamın dışına alınabilir; bağıntı bazı kaynaklarda bu biçimde görülür.

Bu bağıntıya Master teoremi uygulanamaz. İki alt problem farklı boyuttadır ve biri bölme parametresi içermez. Örneğin 10 elemanlı dizide pivot 3. konuma oturursa bir tarafta 2, diğer tarafta 7 eleman kalır; bu durum Master teoreminin biçimine uymaz. Hoca, bağıntının karakteristik denklem yöntemiyle çözülebildiğini ama çözümün çok uzun olduğunu söyledi ve yalnız sonucu verdi:

$$C_{avg}(n) \approx 2n \ln n \approx 1{,}38\, n \log_2 n \in \Theta(n \log n)$$

Yani ortalama durumda, en iyi duruma göre yaklaşık %38 daha fazla karşılaştırma yapılır (ekrandan, 01:35:00). Ortalama durum en kötü duruma değil, en iyi duruma yakındır.

Sezgisel açıklama: $s$ değerlerine göre parça boyutları $(0, n-1)$, $(1, n-2)$, $(2, n-3)$, ... biçiminde gider. Bu çiftlerin ortalaması $(n/2, n/2)$'ye yaklaşır; bu da en iyi durumdaki gibi $n$ maliyetli ve $\log n$ derinlikli bir yapıya, dolayısıyla $n \log n$'ye götürür.

> **Ek bilgi (derste anlatılmadı):** $2 \ln n = 2 \ln 2 \cdot \log_2 n \approx 1{,}386 \log_2 n$ olduğu için $2n\ln n \approx 1{,}39\, n\log_2 n$'dir; tahtadaki $1{,}38$ bu sabitin yuvarlanmış halidir.

## 9. Üç yollu bölümleme (3-way partitioning)

Şimdiye kadarki bölümleme iki yolludur: dizi iki parçaya bölünür ve pivota eşit olanlar bir tarafa dahil edilir. Üç yollu bölümlemede dizi üç parçaya ayrılır (ekrandan, 01:40:00):

```text
| less than pivot | equals to pivot | greater than pivot |
```

Dizide pivota eşit çok sayıda eleman varsa (örneğin en baskın eleman pivot seçilirse) bu yöntem daha hızlıdır, çünkü ortadaki "eşit" bölge zaten sıralıdır ve sonraki özyinelemeli çağrılara girmez. Örneğin bu bölgede 300 eleman varsa, bunlar bir daha hiç işlenmez. İşaretçiler: `lt` (lower than, küçük bölgenin sınırı), `i` (taranan eleman) ve `gt` (greater than, büyük bölgenin sınırı).

Kurallar (ekrandan, 01:45:00):

- $a[i] < \text{pivot}$: $a[lt] \leftrightarrow a[i]$; `lt++`, `i++`.
- $a[i] > \text{pivot}$: $a[i] \leftrightarrow a[gt]$; `gt--` ($i$ artmaz).
- $a[i] = \text{pivot}$: `i++`.

Sözde kod (ekrandan, 01:50:00):

```text
lt = low
i = low + 1
gt = high
pivot = a[low]
while (i <= gt) {
    if (a[i] < pivot) { a[lt] <-> a[i]; i++; lt++; }
    else if (a[i] > pivot) { a[i] <-> a[gt]; gt--; }
    else i++;
}
```

> **Ders sonrası not:** Tahtadaki sözde kodda ilk `if` dalında swap yazılmamış (yalnız `i++; lt++;`) ve ikinci koşul `else if` yerine ayrı bir `if` olarak yazılmıştı. Bir önceki slayttaki kurallara göre ilk dalda $a[lt] \leftrightarrow a[i]$ swap'ı gerekir; ikinci koşul da `else if` olmalıdır, yoksa aynı turda iki dal birden çalışabilir.

### 9.1 Örnek: $4, 2, 4, 6, 4, 8, 7, 3, 4, 1, 5$

Pivot ilk eleman ($4$), `lt` = 0, `i` = 1, `gt` = 10 (ekrandan, 01:45:00). Hoca önce iki uçtan arama yaparak izlemeye başladı, takılınca kurallara geçip baştan izledi. Kurallara göre adımlar (ara adımlar eklendi):

| Adım | $a[i]$ | İşlem | Dizi | lt, i, gt |
|---|---|---|---|---|
| 1 | 2 | $< 4$: $a[0] \leftrightarrow a[1]$ | 2 4 4 6 4 8 7 3 4 1 5 | 1, 2, 10 |
| 2 | 4 | $= 4$: i++ | 2 4 4 6 4 8 7 3 4 1 5 | 1, 3, 10 |
| 3 | 6 | $> 4$: $a[3] \leftrightarrow a[10]$ | 2 4 4 5 4 8 7 3 4 1 6 | 1, 3, 9 |
| 4 | 5 | $> 4$: $a[3] \leftrightarrow a[9]$ | 2 4 4 1 4 8 7 3 4 5 6 | 1, 3, 8 |
| 5 | 1 | $< 4$: $a[1] \leftrightarrow a[3]$ | 2 1 4 4 4 8 7 3 4 5 6 | 2, 4, 8 |
| 6 | 4 | $= 4$: i++ | 2 1 4 4 4 8 7 3 4 5 6 | 2, 5, 8 |
| 7 | 8 | $> 4$: $a[5] \leftrightarrow a[8]$ | 2 1 4 4 4 4 7 3 8 5 6 | 2, 5, 7 |
| 8 | 4 | $= 4$: i++ | 2 1 4 4 4 4 7 3 8 5 6 | 2, 6, 7 |
| 9 | 7 | $> 4$: $a[6] \leftrightarrow a[7]$ | 2 1 4 4 4 4 3 7 8 5 6 | 2, 6, 6 |
| 10 | 3 | $< 4$: $a[2] \leftrightarrow a[6]$ | 2 1 3 4 4 4 4 7 8 5 6 | 3, 7, 6 |

$i > gt$ olunca döngü biter. Sonuç: $2, 1, 3 \mid 4, 4, 4, 4 \mid 7, 8, 5, 6$. Bu, hocanın derste bulduğu sonuçla aynıdır ve python ile doğrulandı. Dört tane $4$ ortada yerini almıştır; sonraki adımda yalnız $2, 1, 3$ ve $7, 8, 5, 6$ parçalarına kendi içinde yine üç yollu bölümleme uygulanır. Bu algoritma "Quick3" (Quicksort 3) adıyla da bulunur; hoca animasyon sitesindeki karşılaştırmalı gösterimde Quick3'ün çalışmasını da gösterdi.

## 10. Insertion Sort ile hibrit yapı ve en kötü durumdan kaçınma

### 10.1 Küçük parçalarda Insertion Sort

Bölümleme sonucunda kalan parça belli bir sınırın (10-15 eleman gibi) altındaysa Insertion Sort'a geçmek işi daha da hızlandırır. Animasyon sitesinde bütün algoritmalar birlikte çalıştırıldığında Quick3 ve Quick önce, ardından Insertion, Selection ve Bubble Sort bitti. Hoca, Quicksort'a ya da Quick3'e hibrit bir Insertion Sort eklenirse işin çok daha hızlı olacağını, aynı şeyin Merge Sort'un temel durumuna da eklenebileceğini söyledi. Sayma tabanlı doğrusal sıralama (counting sort) gibi algoritmalar da vardır; bunlarda elemanlar değere dayalı yeni bir diziye doğrudan yerleştirilir, sonra sırayla eski diziye geri yazılır.

Neden Selection Sort değil de Insertion Sort tercih edilir? İkisi de $n^2$'dir; fark, baskın terimden sonraki terimlerde ve karşılaştırma sayısındadır. Insertion Sort, kart sıralarken kartı uygun yere sokmaya benzer: eleman zaten doğru yerdeyse ona dokunmaz, gereksiz kontrol yapmaz. Dizinin çoğu sıralıysa Insertion Sort Selection Sort'tan çok daha az karşılaştırma yapar.

> **Ders sonrası not:** Hoca bu karşılaştırmayı anlatırken "kuralı bozmuyorsa hiç dokunmuyor" davranışını bir an Selection Sort'a bağladı; bu davranış Insertion Sort'a aittir. Selection Sort her durumda $n(n-1)/2$ karşılaştırma yapar; Insertion Sort ise sıralıya yakın dizilerde doğrusal süreye yaklaşır.

### 10.2 En kötü durumdan kaçınma

**Soru (derste sözlü):** Quicksort'ta en kötü durumdan kaçınmak için ne yapılabilir?
**Cevap:** Bir öğrenci pivotun rastgele seçilmesini önerdi. Hoca bunun bir çözüm olduğunu kabul etti: dizi düz ya da ters sıralı olsa bile rastgele pivot ortalama duruma kaydırır. Ancak pivot ortadan uzak düşerse (örneğin 10 elemanlı dizide 3. konum) büyük taraf (7 eleman) maliyet çıkarır ve süre uzar; karmaşıklık sınıfı değişmese de $n^2$'ye doğru yaklaşma başlar. Daha iyi bir çözüm, pivotu medyana yakın seçmektir; dersin başında gösterilen animasyondaki sürüm pivotu ortadan alır. Başka bir çözüm de diziyi önceden karıştırmaktır (shuffle); sıra bozulunca baştan ya da sondan alınan pivotun kötü olma olasılığı düşer. Karıştırmanın da kendi maliyeti olduğu ayrıca düşünülmelidir.

Levitin'in slaytlarında da şu iyileştirmeler sıralanır (ekrandan, slayt özeti): daha iyi pivot seçimi, küçük alt dizilerde Insertion Sort'a geçme ve özyinelemenin ortadan kaldırılması (bazı yerlerde iteratif yapı ve ek kontrollerle). Hoca bu iyileştirmelerin birlikte yaklaşık %20-25 kazanç sağladığının görüldüğünü ve Quicksort'un 10.000 ve üzeri boyuttaki verilerde iyi bir seçim olduğunun ifade edildiğini aktardı. Bunlar istatistiksel çalışmalardır; farklı veri boyutlarında Quicksort'a yapılan değişiklikleri inceleyen makaleler vardır.

## 11. Böl ve yönetin diğer örnekleri (slayt özeti)

Dersin sonunda Levitin'in kitabının böl ve yönet slaytları üzerinden kısa bir özet yapıldı. Böl ve yönette dikkat edilecek nokta, bölünen her parçaya **aynı** algoritmanın uygulanmasıdır; bir parçaya bir yöntem, diğerine başka bir yöntem uygulanmaz. Hoca, slaytlardaki Quicksort örneğinin çok açıklayıcı olmadığını, bu yüzden konuyu yazarak ve animasyonlarla anlatmayı tercih ettiğini söyledi. İkili arama da daha önce konuşulmuştu.

### 11.1 İkili ağaç algoritmaları

İkili ağaç, böl ve yönete hazır bir yapıdır (ekrandan, 02:00:00). Klasik dolaşımlar (preorder, inorder, postorder) böl ve yönet algoritmalarıdır:

```text
Algorithm Inorder(T)
if T ≠ ∅
   Inorder(T_left)
   print(root of T)
   Inorder(T_right)
```

Verimlilik $\Theta(n)$'dir, çünkü her düğüm bir kez ziyaret edilir (yazdırılır). Alt ağaçlar önce çözülür, sonra alt çözümler birleştirilerek bütün ağacın sonucu elde edilir. Hoca bu konuların ayrıntısının Veri Yapıları dersinde anlatıldığını belirtti.

İkinci örnek ağacın yüksekliğidir: sol alt ağacın ve sağ alt ağacın yüksekliği özyinelemeli olarak bulunur, büyüğüne 1 eklenir:

$$h(T) = \max\{h(T_{left}), h(T_{right})\} + 1, \quad h(\emptyset) = -1$$

Boş ağaç için $-1$ döndürülür.

### 11.2 Büyük sayıların çarpımı

Büyük sayılar klasik yöntemde basamak basamak çarpılır. Örneğin $386 \times 120$ hesaplanırken $120 = 100 + 20$ diye ayrılıp $386 \times 100 + 386 \times 20$ yapılabilir; $386$ da $300 + 86$ diye ayrılabilir. Böylece yapılacak çarpmalar daha basit çarpmalara indirgenir; burada da bir böl ve yönet mekanizması vardır. Sonuç $386 \times 120 = 46320$'dir.

### 11.3 Strassen matris çarpımı

Klasik matris çarpımında üç iç içe döngü (birinci matrisin satırı, ikinci matrisin sütunu ve çarpım toplamı) vardır ve karmaşıklık $n^3$'tür. Strassen matris çarpımı bunu yaklaşık $n^{2,8}$'e indirir.

> **Ek bilgi (derste anlatılmadı):** Strassen yöntemi iki $n \times n$ matrisin çarpımını $n/2$ boyutlu 7 çarpıma indirger: $T(n) = 7T(n/2) + \Theta(n^2)$. Master teoremiyle $T(n) \in \Theta(n^{\log_2 7}) \approx \Theta(n^{2,807})$ bulunur.

### 11.4 En yakın nokta çifti

$n$ nokta arasında birbirine en yakın iki noktayı bulmak için normalde her nokta her noktayla karşılaştırılır; bu $n^2$'dir. Böl ve yönet yaklaşımında noktalar önce $x$ eksenine göre sıralanır, ortadaki nokta bir pivot gibi alınır. Sol tarafta ve sağ tarafta en yakın çiftler özyinelemeli olarak bulunur, ayrıca orta çizginin çevresindeki belli bir aralıkta da en yakın çiftlere bakılır. Bunlardan en küçüğü seçilir. Karmaşıklık $n^2$'den $n \log n$'e düşer.

### 11.5 Dışbükey örtü ve Quickhull

Dışbükey örtü (convex hull), verilen noktaları içeren en küçük dışbükey kümedir; sonuç bir çokgendir (ekrandan, 02:05:00). Kaba kuvvetle $O(n^3)$ sürer (Levitin, 3. bölüm). Quickhull algoritmasının adımları:

- Noktaların $x$ koordinatına göre sıralı olduğu kabul edilir.
- En soldaki ve en sağdaki uç noktalar $P_1$ ve $P_2$ belirlenir.
- Üst örtü özyinelemeli olarak bulunur:
  - $P_1P_2$ doğrusuna en uzak nokta $P_{max}$ bulunur.
  - $P_1P_{max}$ doğrusunun solundaki noktaların üst örtüsü hesaplanır.
  - $P_{max}P_2$ doğrusunun solundaki noktaların üst örtüsü hesaplanır.
- Alt örtü benzer biçimde bulunur.

Hoca, iyileştirilmiş yöntemlerle bu problemin $n^2$'ye, hatta $n \log n$'e indirilebileceğini, dışbükey örtünün birçok uygulamada kullanılan zor bir problem olduğunu söyledi.

## Örnek Sorular

### Soru 1

(ekrandan, 00:05:00) $T(n) = T(n-1) + n$ bağıntısını geriye yerine koyma yöntemiyle çözün.

> **Çözüm:** $T(n) = T(n-1) + n = T(n-2) + (n-1) + n = T(n-3) + (n-2) + (n-1) + n = \dots = T(0) + \sum_{i=1}^{n} i = T(0) + \frac{n(n+1)}{2}$. Dolayısıyla $T(n) \in \Theta(n^2)$. $T(n-1)$ açılırken eklenen terimin $n$ değil $n-1$ olduğuna dikkat edilmelidir.

### Soru 2

(ekrandan, 00:40:00; derste sözlü, 00:35:18) $5, 3, 1, 9, 8, 2, 4, 7$ dizisinde ilk eleman pivot alınarak Hoare bölümlemesini elle izleyin.

> **Çözüm:** İlk swap $9 \leftrightarrow 4$: $5, 3, 1, 4, 8, 2, 9, 7$. İkinci swap $8 \leftrightarrow 2$: $5, 3, 1, 4, 2, 8, 9, 7$. İşaretçiler birbirini geçer; pivot $A[j] = 2$ ile değiştirilir: $2, 3, 1, 4, 5, 8, 9, 7$. Pivot $5$, 4. konumda (0'dan sayınca) yerindedir. Ayrıntı için Bölüm 5'e bakın.

### Soru 3

(ekrandan, 01:45:00) $4, 2, 4, 6, 4, 8, 7, 3, 4, 1, 5$ dizisine ilk eleman pivot alınarak üç yollu bölümleme uygulayın.

> **Çözüm:** Sonuç $2, 1, 3 \mid 4, 4, 4, 4 \mid 7, 8, 5, 6$; döngü sonunda `lt` = 3, `gt` = 6. Adım adım tablo Bölüm 9.1'dedir.

### Soru 4

(ekrandan, 01:25:00) Sıralı dizide ilk eleman pivot seçildiğinde Quicksort'un karşılaştırma sayısını bulun.

> **Çözüm:** İlk bölümlemede $n+1$, sonra $n$, $n-1$, ..., son adımda 3 karşılaştırma yapılır: $C_{worst}(n) = \sum_{k=3}^{n+1} k = \frac{(n+1)(n+2)}{2} - 3 \in \Theta(n^2)$. Örneğin $n = 5$ için $6 + 5 + 4 + 3 = 18$ (python ile doğrulandı).

### Soru 5

(derste sözlü, 01:25:16) En kötü durum sayımında son adımda neden 3 karşılaştırma vardır?

> **Çözüm:** Son parçada pivotla $i$ tarafında bir eleman, $j$ tarafında iki eleman (son eleman ve pivotun kendisi) karşılaştırılır; toplam 3. Bölüm 8.2'ye bakın.

### Soru 6

(derste sözlü, 00:22:18) Merge Sort ve Quicksort aynı karmaşıklık sınıfında olduğu halde ölçülen süreleri neden farklıdır?

> **Çözüm:** Fark uygulama ayrıntılarından gelir: Merge Sort kopyalama, Quicksort swap yapar; Merge Sort her seviyede elemanları ikişer ikişer karşılaştırırken Quicksort bir elemanı tek swap ile uzak bir konuma taşıyabilir. Bu fark alt terimlerdedir ve karmaşıklık sınıfını değiştirmez. Bölüm 3'e bakın.

### Soru 7

(derste sözlü, 01:56:23) Quicksort'ta en kötü durumdan kaçınmak için neler yapılabilir?

> **Çözüm:** Rastgele pivot seçmek, medyana yakın (ortadaki) pivotu seçmek ya da diziyi önceden karıştırmak (shuffle). Karıştırmanın da bir maliyeti vardır. Bölüm 10.2'ye bakın.

## Dersin Toparlaması

Bu derste böl ve yönet tekniğinin iki temel sıralama algoritması karşılaştırıldı. Merge Sort her durumda $\Theta(n \log n)$ sürer ama birleştirme için yedek dizi ister. Quicksort ise pivot etrafında yerinde bölümleme yaparak ek bellek kullanmaz. Hoare bölümlemesinde iki işaretçi iki uçtan ilerler ve yanlış tarafta kalan elemanları tek swap ile değiştirir. Quicksort'un en iyi durumu (pivot ortada) $T(n) = 2T(n/2) + n$ ile $\Theta(n \log n)$, en kötü durumu (sıralı ya da ters sıralı dizi ve uçtan seçilen pivot) $\frac{(n+1)(n+2)}{2} - 3 \in \Theta(n^2)$, ortalama durumu ise yaklaşık $1{,}38\, n \log_2 n$ karşılaştırmadır. Pratikte rastgele ya da medyana yakın pivot, karıştırma, küçük parçalarda Insertion Sort ve pivota eşit elemanların çok olduğu dizilerde üç yollu bölümleme kullanılır. Dersin sonunda ikili ağaç dolaşımları, büyük sayıların çarpımı, Strassen matris çarpımı, en yakın nokta çifti ve Quickhull gibi diğer böl ve yönet örneklerine kısaca değinildi.

Hoca bir sonraki derste hash (karma) yöntemleri ve arama algoritmalarının iyileştirilmesi ile analizine geçileceğini söyledi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
