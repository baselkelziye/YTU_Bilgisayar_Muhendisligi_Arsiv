# Ders 22 Genişletilmiş Notu: Quiz Çözümleri, Mergesort Analizi, Tromino Bulmacası ve Quicksort

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Kısa Sınav Sorularının Çözümü
- 2. Top-Down Mergesort: Çağrı Ağacı ve Karmaşıklık
- 3. Sıralama Algoritmalarını Seçme Ölçütleri
- 4. Mergesort'un C Kodu
- 5. Bottom-Up Mergesort
- 6. Tromino Bulmacası
- 7. Quicksort: Değere Göre Bölme
- 8. Hoare Partition
- 9. Quicksort'un C Kodu ve Çağrı Ağacı
- 10. Quicksort İçin İyileştirmeler
- 11. Son Eleman Pivot Olan Partition
- 12. Quicksort'un Karmaşıklığı ve Kararlılığı
- Örnek Sorular

## 1. Kısa Sınav Sorularının Çözümü

Hoca derse, bir önceki hafta yapılan kısa sınavın (quiz) sorularını sınav ekranından açarak çözmekle başladı. Soruların bir kısmı heap, minimum yayılan ağaç (minimum spanning tree, MST), Huffman kodlaması ve karmaşıklık konularındaydı; son soru böl ve yönet (divide and conquer) yaklaşımına bağlanıyordu. Soruların tam metni ve çözümleri "Örnek Sorular" bölümündedir. Burada hocanın çözerken anlattığı mantık özetlenir.

### 1.1 Heap'e Ekleme ve Kökü Silme

Min-heap'e yeni bir değer eklenirken değer her zaman ilk boş göze konur. Bunun sebebi ağacın tam ikili ağaç (complete binary tree) olarak kalması gerektiğidir. Hoca, dizi gösteriminde de elemanın dizinin sonuna eklendiğini hatırlattı. Eklenen değer daha sonra ebeveyniyle (parent) karşılaştırılır; daha küçükse yer değiştirir ve köke doğru bu karşılaştırma sürer. Bazı öğrenciler 8'i ağacın başka bir yerine koymuş ve farklı sayılarla karşılaştırmıştı. Hoca bunun heap yapısını bozduğunu söyledi.

En küçük elemanı silmek (extract-min) için kökteki eleman çıkarılır, son eleman köke taşınır ve boyut bir azaltılır. Köke taşınan eleman bilerek bozulmuş bir heap oluşturur. Bu eleman çocuklarıyla karşılaştırılır, en küçük çocuk (smallest) yukarı çıkar ve işlem yaprağa kadar sürer (heapify). Hoca bu işlemi daha önce max-heap için "largest" ile yaptıklarını hatırlattı.

### 1.2 Kruskal ve MST

Kruskal algoritması kenarları ağırlıklarına göre küçükten büyüğe sıralar. En küçük kenardan başlayarak ya yeni bir ağaç başlatır ya da mevcut ağacı büyütür; çevrim oluşturan kenarı (güvenli olmayan kenarı) atlar. Kenarların artan sırada işlenmesinin sebebi doğruluğu garanti etmektir. Amaç toplam ağırlığı en küçük olan ağacı kurmaktır ve bu ancak en küçükten başlayarak garanti edilir. Gezme yönünün en kötü durum karmaşıklığıyla, bellekle ya da kodlama kolaylığıyla bir ilgisi yoktur.

Kenar ağırlıklarının pozitif ve ayrık (birbirinden farklı) olması önemli bir koşuldur. Derste eşit ağırlıklı kenarların bulunduğu örneklerde hangisinin önce seçildiğine göre farklı MST'ler oluşabildiği görülmüştü. Ağırlıklar ayrıksa Kruskal her adımda tek bir kenar seçer ve bu sıra hiç değişmez; dolayısıyla MST tektir. Sorudaki "kendine döngü içeren düğüm yok" ifadesi bir düğümün kendisine bağlanmadığını, "paralel kenar yok" ifadesi de iki düğüm arasında birden fazla kenar olmadığını anlatır.

### 1.3 Prim ve Öncelikli Kuyruk

Prim algoritmasında her adımda ağaca bağlı kenarlar arasından en küçüğü seçilir. Bu seçimi verimli yapmak için öncelikli kuyruk (priority queue) kullanılır ve karmaşıklık $O(E \log V)$ olur. Hoca, derste Fibonacci heap gibi yapılarla daha da iyileştirilebileceğinin konuşulduğunu hatırlattı. Yığın (stack), ikili ağaç ya da FIFO kuyruk en küçük kenarı seçmeye yaramaz.

Verilen bir grafta Prim çalıştırılırken başlangıç düğümünün bütün kenarları kuyruğa eklenir ve en küçüğü seçilir. Hoca, en sık hatanın kuyruğun tepesinde olan kenar yerine çizimde göze çarpan başka bir kenarla başlamak olduğunu söyledi.

### 1.4 Bağlı Bileşenler

Bağlı bileşen (connected component), kendi içinde birbirine bağlı düğümlerden oluşan bağımsız bir parçadır. Hoca bunu MST anlatımındaki küçük ağaçlara benzetti: iki ayrı ağaç arasına bir kenar eklenince ikisi tek bir bileşen olur. Birleştirme listesi sırayla grafa işlenir ve sonunda kaç ayrı parça kaldığı sayılır. Zaten aynı bileşende olan iki düğüm birleştirilirse bileşen sayısı değişmez; yalnızca bileşen bir çevrim içerir hale gelir.

### 1.5 Huffman Kod Tablosu

Huffman ağacında bir sola gidiş 0, sağa gidiş 1 ile kodlanır. Bir sembol yaprağa yerleştiğinde o düğümün altına başka bir şey gelemez, çünkü kod önek (prefix) özelliğini korumalıdır. Hoca soruyu, tablodaki kısa kodlardan başlayarak ağacı çizip boş kalan tek yaprağı bularak çözdü. Sembolleri iç düğümlere koymaya çalışan cevapların Huffman kodlamasını tamamen yanlış anladığını söyledi.

### 1.6 En Küçük Elemanı Silmenin Karmaşıklığı

Bu soruda beş farklı yapıda en küçük elemanı silmenin en kötü durum karmaşıklığı istendi. Hoca küçük bir dizi çizerek açıkladı: sıralı dizide en küçük eleman baştadır ama silinince kalan elemanların hepsi bir göz kaydırılmalıdır. Bu kaydırma unutulursa karmaşıklık yanlışlıkla $O(1)$ sanılır.

### 1.7 Böl ve Yönete Uygun Problemler

Hoca böl ve yönetin her özyinelemeli (recursive) çözüm demek olmadığını vurguladı. Yığında eleman hep en üste eklenir; yığını bölerek eleman eklemek anlamsızdır. Kuyrukta da elemanlar bir uçtan girip öbür uçtan çıkar (enqueue, dequeue); kuyruğu ortadan bölmek kuyruğun çalışma mantığına aykırıdır.

Fibonacci sayılarında özyineleme vardır ama böl ve yönet yoktur. Örneğin Fibonacci(6) için Fibonacci(5) ve Fibonacci(4), Fibonacci(4) için de Fibonacci(3) ve Fibonacci(2) gerekir. Alt problemler birbirine bağlıdır: bir parçanın sonucu değişirse diğerleri de değişir. Bu yüzden problemi bağımsız parçalara bölüp ayrı ayrı çözemeyiz. Yapılabilecek şey ya kendimizi tekrar tekrar çağırmak ya da önceki adımların sonuçlarını bir dizide tutup sonraki adıma taşımaktır; hoca bunun dinamik programlamaya gittiğini söyledi.

**Soru:** Bir çevrimiçi derste Fibonacci'nin bölünerek özyinelemeli çözüldüğü gösteriliyordu. Bu böl ve yönet sayılmaz mı?
**Cevap:** Hoca, gösterilen yöntem gerçekten böl ve yönet ise bunu kabul edeceğini, ancak bunun büyük olasılıkla azalt ve yönet (decrease and conquer) olduğunu söyledi. Azalt ve yönette problem uzayı küçültülür ve bir önceki sonuç bilinerek ilerlenir; bu böl ve yönetle aynı şey değildir.

> **Hocanın vurgusu:** Böl ve yönette parçalar birbirinden bağımsız çözülebilmelidir. Yalnızca kendini çağırmak bir algoritmayı böl ve yönet yapmaz.

## 2. Top-Down Mergesort: Çağrı Ağacı ve Karmaşıklık

### 2.1 Mergesort'un Hatırlatılması

Mergesort uzaysal bir bölümleme yapar. Hoca bunu karpuz dilimlemeye benzetti: karpuz önce ortadan ikiye bölünür, sonra her yarı yine ikiye bölünür ve daha fazla bölünemeyen dilimler elde edilince durulur. Böylece bölme (divide) aşaması biter. Yönetme (conquer) aşamasında parçalar birleştirilir (merge). İşin asıl kısmı burasıdır: iki sıralı parçanın elemanları karşılaştırılır, küçük olan harici bir diziye kopyalanır ve parçalar birleştikçe ikililer, dörtlüler, sekizliler oluşur. Bu yönteme yukarıdan aşağıya (top-down) mergesort adı verilir.

### 2.2 Çağrı Ağacı

Hoca 16 elemanlı bir dizi için özyinelemeli çağrı ağacını bütün parametreleriyle gösterdi (ekrandan, 00:50:00):

```text
MergeSort(A, 0, 15)
  MergeSort(A, 0, 7)
    MergeSort(A, 0, 3)
      MergeSort(A, 0, 1)
        Merge(A, 0, 0, 1)
      MergeSort(A, 2, 3)
        Merge(A, 2, 2, 3)
      Merge(A, 0, 1, 3)
    MergeSort(A, 4, 7)
      MergeSort(A, 4, 5)
        Merge(A, 4, 4, 5)
      MergeSort(A, 6, 7)
        Merge(A, 6, 6, 7)
      Merge(A, 4, 5, 7)
    Merge(A, 0, 3, 7)
  MergeSort(A, 8, 15)
    MergeSort(A, 8, 11)
      MergeSort(A, 8, 9)
        Merge(A, 8, 8, 9)
      MergeSort(A, 10, 11)
        Merge(A, 10, 10, 11)
      Merge(A, 8, 9, 11)
    MergeSort(A, 12, 15)
      MergeSort(A, 12, 13)
        Merge(A, 12, 12, 13)
      MergeSort(A, 14, 15)
        Merge(A, 14, 14, 15)
      Merge(A, 12, 13, 15)
    Merge(A, 8, 11, 15)
  Merge(A, 0, 7, 15)
```

`MergeSort(A, 0, 15)` çağrıldığında ilk yapılan iş sol yarı için `MergeSort(A, 0, 7)` çağırmaktır. O da kendi sol yarısını (`0, 3`), o da kendi sol yarısını (`0, 1`) çağırır. Artık iki tek eleman kaldığı için daha fazla bölünemez ve `Merge(A, 0, 0, 1)` ile 0. ve 1. gözler birleştirilir. Sonra sağdaki ikili (`2, 3`) aynı şekilde işlenir. Elde iki sıralı ikili olunca `Merge(A, 0, 1, 3)` ile ilk dörtlü oluşur. İkinci dörtlü (`4, 7`) de aynı yolla tamamlanır ve `Merge(A, 0, 3, 7)` ile ilk sekiz eleman birleşir. Bu noktada ana çağrının sol kanadı bitmiştir. Sağ kanat (`8, 15`) aynı şekilde işlenir ve en son `Merge(A, 0, 7, 15)` ile 16 elemanlı sıralı dizi elde edilir.

### 2.3 Karmaşıklık Analizi

Hoca analizi mümkün olduğunca basit tuttu (ekrandan, 00:55:00). Dizi hiyerarşik olarak hep ikiye bölünür:

```text
A[0..15]
A[0..7]   A[8..15]
A[0..3]   A[4..7]   A[8..11]   A[12..15]
A[0,1]   A[2,3]   . . . . . . . . . .   A[14,15]
```

$n$ eleman için $\log n$ seviyelik bir bölme ağacı oluşur. Her seviyede, parçaların toplamında $n$ eleman işlenir. Bu yüzden toplam iş $n \log n$ mertebesindedir ve karmaşıklık $O(n \log n)$'dir.

Zaman dışında bir de ek bellek (auxiliary space) ihtiyacı vardır. Birleştirme sırasında sıralı parça harici bir diziye kopyalandığı için $n$ boyutlu bir dizi gerekir. Yani ek bellek sabit değildir, $O(n)$'dir.

Hoca daha ayrıntılı bir sayım da verdi: her merge'de $2n$ kopyalama, $2n$ geri taşıma ve $2n$ karşılaştırma yapılır. Toplam $6n$ işlem $\log n$ seviye için yapıldığından $6n \log n$ dizi erişimi bulunur. Büyük O gösteriminde katsayılar yazılmadığı için sonuç $O(n \log n)$ olarak ifade edilir. Hoca, heapsort'un da $n \log n$ olduğunu hatırlattı: her heap düzeltme işlemi $\log n$, $n$ eleman için toplam $n \log n$ eder.

> **Ders sonrası not:** Slaytta "N Seviye, LogN adım" yazıyor. Hocanın anlatımına göre doğrusu, $\log N$ seviye ve her seviyede $N$ elemanın işlenmesidir.

### 2.4 Görsel Anlatım

Hoca, çağrı sırasını daha iyi anlamak için dizi elemanlarının çubuk boylarıyla gösterildiği bir görsel kullandı. Uzun çubuk büyük sayıyı, kısa çubuk küçük sayıyı gösterir (örneğin en büyüğü 100 olan değerler). Dizi önce ortadan, sonra her yarısı ortadan bölünür. Önce en soldaki küçük parça birleştirilir ve kendi içinde sıralanır; sonra hemen sağındaki parça sıralanır; sonra bu ikisi birleştirilir. Sol yarının hepsi kendi içinde sıralı hale gelene kadar sağ yarıya hiç dokunulmaz. Sonra sağ yarı aynı sırayla işlenir. Son birleştirmeden önce dizide kendi içinde sıralı iki parça vardır ve son merge bunları tek sıralı diziye çevirir.

## 3. Sıralama Algoritmalarını Seçme Ölçütleri

**Soru:** Mergesort ile heapsort'un karmaşıklığı aynı. Birbirlerine karşı avantajları ya da dezavantajları var mı?
**Cevap:** Var. Hoca bu dönem sıralama algoritmalarının karşılaştırılması başlığını işlemediklerini, ama bunun birkaç ölçütle yapıldığını anlattı:

- Çalışma zamanı karmaşıklığı: $n^2$ ile $n \log n$ arasında elbette $n \log n$ tercih edilir.
- Kararlılık (stability): girdideki eşit değerlerin sırası çıktıda korunuyor mu? Örneğin quicksort korumaz. Eşit değerlerden ilk geleni çıktıda da önce görmek gerekiyorsa $n \log n$ bir algoritma bile kullanılamayabilir.
- Ek bellek: mergesort ek bir dizi ister. Bellek kısıtlıysa $n \log n$ olmasına rağmen kullanılamayabilir.
- Yerinde (in-place) çalışma.

Hoca en iyi algoritmanın tek olmadığını, problemin ve çalışılacak ortamın özelliklerine göre seçim yapıldığını söyledi. Counting sort, radix sort gibi farklı yaklaşımlar da vardır ama bu derste işlenmeyecektir. Hoca mergesort'un kararlı olup olmadığını o an hatırlayamadığını, bu karşılaştırmaların bir tabloda toplandığını ve Wikipedia gibi kaynaklarda bulunabileceğini söyledi.

> **Ek bilgi (derste anlatılmadı):** Mergesort, eşit elemanlarda sol parçadaki eleman önce alınırsa (karşılaştırma `<=` ile yapılırsa) kararlıdır. Derste gösterilen kodda karşılaştırma `a[i] < a[j]` biçimindedir; eşitlikte sağ parçadaki eleman önce alındığı için bu haliyle kararlı değildir.

**Soru:** Kararlı çalışan en düşük karmaşıklık $n \log n$ mi?
**Cevap:** Hoca, ayrıntıya girmeden basitçe evet denebileceğini söyledi.

## 4. Mergesort'un C Kodu

Hoca kodu `main` fonksiyonundan başlayarak açıkladı (ekrandan, 01:05:00):

```c
void mergeSort(int a[], int lo, int r){
    int q;
    if(lo < r){
        q = (lo + r) / 2;
        mergeSort(a, lo, q);
        mergeSort(a, q+1, r);
        merge(a, lo, q, r);
    }
}

void merge(int a[], int lo, int q, int r){
    int b[5];   //same size of a[]
    int i=lo, j=q+1, k=0;

    while(i <= q && j <= r){
        if(a[i] < a[j]) b[k++] = a[i++];    // same as b[k]=a[i]; k++; i++;
        else b[k++] = a[j++];
    }
    while(i <= q) b[k++] = a[i++];
    while(j <= r) b[k++] = a[j++];

    for(i=r; i >= lo; i--)
       a[i] = b[--k];  // copying back the sorted list to a[]
}

int main(){
    int arr[] = {32, 45, 67, 2, 7};
    int len = sizeof(arr)/sizeof(arr[0]);

    mergeSort(arr, 0, len - 1);
    return 0;
}
```

`main` beş elemanlı bir dizi tanımlar, boyutunu bulur ve `mergeSort`'u 0'dan 4'e kadar çağırır. `mergeSort` sol ve sağ sınırları alır; sol sınıra `l` yerine `lo` denmesinin sebebi `l` harfinin 1 rakamıyla karışmasıdır. `q` ortayı tutar. Sol sınır sağdan küçük olduğu sürece, yani parçada birden fazla eleman olduğu sürece, önce sol yarı (`lo..q`), sonra sağ yarı (`q+1..r`) özyinelemeli sıralanır ve en son ikisi `merge` ile birleştirilir.

`merge` fonksiyonunda `i` sol parçanın başından, `j` ortanın bir sağından, `k` ise çıktı dizisi `b`'nin başından başlar. İki parçada da eleman kaldığı sürece tek bir kontrol yapılır: soldaki küçükse soldan, değilse sağdan bir eleman alınıp `b`'ye yazılır. `b[k++] = a[i++]` satırı `b[k] = a[i]; k++; i++;` ile aynıdır. Döngü bitince parçalardan birinde eleman kalmış olabilir; kalanlar olduğu gibi `b`'ye kopyalanır. En son `b`'deki sıralı elemanlar orijinal diziye geri yazılır. Hoca, sıralı alt parçalarla başka bir iş yapılacaksa doğrudan `b`'nin kullanılabileceğini, ama `a`'nın sıralanması istendiği için bu geri kopyalamanın şart olduğunu belirtti.

Ek dizinin boyutu derste kolaylık için elle 5 yazılmıştır; normalde dizi boyutu parametre olarak verilmelidir. Hoca dizinin boyutu kadar harici bir diziye ihtiyaç duyulmasını mergesort'un "zayıf karnı" olarak niteledi.

## 5. Bottom-Up Mergesort

### 5.1 Fikir

Aradan sonra hoca mergesort'un farklı bir yöntemini anlattı. Top-down yaklaşımda dizi özyinelemeli olarak "solun solu, solun sağı" diye bölünüyordu. Bottom-up (aşağıdan yukarıya) yaklaşımda ise doğrudan birlilerden başlanır: birliler birleştirilip ikililer, ikililer birleştirilip dörtlüler, dörtlüler birleştirilip sekizliler elde edilir. Her turda dizi soldan sağa tamamen işlenir.

Slayttaki akış şeması şöyledir (ekrandan, 01:20:00):

```text
MergeSortBottomUp(A, n)
  s: subarray size (alt dizi boyutu), i: subarray index (alt dizi indisi)
  s <- 1'den başla, s < n iken (son değer n-1), her adımda s <- s+s
      i <- 0'dan başla, i < n-s iken (son değer n-s-1), her adımda i <- i+s+s
          Merge(A, i, i+s-1, min(i+s+s-1, n-1))
  dur
```

Slayttaki özet: "1-1, 2-2, 4-4, ..., N/2-N/2 birleştir"; "1/2NLgN – 6NlgN arası karşılaştırma, 6NlgN dizi erişimi". Hoca bu yöntemin de $n \log n$ mertebesinde ve en çok $6n \log n$ olduğunu, ancak pratikte, özellikle rastgele değerlerle, biraz daha hızlı çalışabildiğini söyledi.

> **Ders sonrası not:** Slayttaki karşılaştırma aralığının üst sınırı büyük olasılıkla yanlış yazılmıştır. Bottom-up mergesort'ta karşılaştırma sayısı büyük olasılıkla $\frac{1}{2} N \lg N$ ile $N \lg N$ arasındadır; $6 N \lg N$ ise dizi erişimi sayısının üst sınırıdır.

### 5.2 Örnek: MERGESORTEXAMPLE

16 harfli "MERGESORTEXAMPLE" dizisi üzerinde (ekrandan, 01:25:00):

- $s = 1$ (ikililer): 0-1 (M, E) birleşip E M; 2-3 (R, G) birleşip G R; 4-5 (E, S) değişmez; 6-7 (O, R) değişmez; 8-9 (T, E) birleşip E T; 10-11 (X, A) birleşip A X; 12-13 (M, P) değişmez; 14-15 (L, E) birleşip E L olur. Toplam 8 birleştirme, yani $n/2$ tane merge yapılır.
- $s = 2$ (dörtlüler): EM ile GR birleşip E G M R (9. adım), ES ile OR birleşip E O R S (10. adım), ET ile AX birleşip A E T X (11. adım), MP ile EL birleşip E L M P (12. adım) olur. Çağrılar 0-3, 4-7, 8-11, 12-15 aralıkları içindir.
- $s = 4$ (sekizliler): E G M R ile E O R S birleşip E E G M O R R S (13. adım), A E T X ile E L M P birleşip A E E L M P T X (14. adım) olur.
- $s = 8$: iki sekizli birleşir ve A E E E E G L M M O P R R S T X (15. adım) elde edilir.

Bu sonuçlar bir python denemesiyle de aynı çıktı.

Eleman sayısı ikinin kuvveti değilse son parça eksik kalabilir. Örneğin 18 eleman varsa son parça ikili olarak kalır ve öyle birleşir. `min(i+s+s-1, n-1)` ifadesi bu yüzden vardır.

### 5.3 Görsel Anlatım

Çubuk görselinde önce birliler birleşip kendi içinde sıralı ikililer oluşur, sonra ikililer birleşip sıralı dörtlüler oluşur. Dizinin sonunda bir ikili kalmışsa onu dörtlüye tamamlamak gerekmez; o parça ikili olarak yoluna devam eder. Sonra dörtlüler birleşip sekizliler oluşur; sonda bir dörtlü ile bir ikili birleşip altılı bir parça kalabilir. Sekizliler on altılıları, on altılılar otuz ikilileri oluşturur ve en son iki büyük parça birleşerek sıralı diziyi verir.

## 6. Tromino Bulmacası

Hoca, böl ve yönetin yalnız sıralama için değil, problem uzayının bölünebildiği her problemde kullanılabileceğini ve paralelleştirmeye de imkan verdiğini söyledi. Örnek olarak tromino bulmacasını verdi.

### 6.1 Problem

Elimizde $2^n \times 2^n$ boyutlu kare bir pano vardır. Boyutun ikinin kuvveti olması, panonun özyinelemeli olarak ikiye bölünebilmesi içindir. Panodaki gözlerden yalnız biri doludur ve hangisinin dolu olduğu bilinir. Elimizde L biçimli, üç kareden oluşan karolar (tromino) vardır. Bunlar dört farklı yönde döndürülebilir. Problem, panonun kalan gözlerini bu üçlük karolarla tamamen kaplamaktır.

Kaba kuvvet (brute force) yaklaşımında karolar rastgele yerleştirilip denenir, tutmazsa geri alınıp başka türlü denenir. Hoca bunun sürekli tekrar tekrar deneme gerektirdiğini ve karmaşıklığının çok yüksek olduğunu söyledi.

### 6.2 Böl ve Yönet Çözümü

Hocanın gösterdiği örnek 8×8'lik bir panodur ($n = 3$) (ekrandan, 01:35:00). Çözüm şu adımlardan oluşur:

1. Pano iki eksende ortadan bölünerek dört eşit çeyreğe ayrılır.
2. Dolu gözün hangi çeyrekte olduğu indisinden bilinir.
3. Dolu gözün olmadığı üç çeyreğin, panonun merkezine komşu olan gözlerine birer kare gelecek şekilde bir L karo yerleştirilir. Böylece her çeyrekte tam bir dolu göz olur.
4. Her çeyrek için aynı işlem özyinelemeli olarak tekrarlanır.
5. 2×2'lik bir parçaya inildiğinde bir göz zaten doludur ve kalan üç göze tek bir L karo oturur. Daha fazla bölmeye gerek yoktur.

Derste dolu göz sol üst çeyrekteydi. İlk L karo merkezde, diğer üç çeyreğin merkeze bakan gözlerine yerleşti. Sonra sol üst çeyrek kendi içinde dörde bölündü ve aynı kural uygulandı. Bir çeyrek bittikten sonra sıradaki çeyreğe geçildi; her çeyrek kendi içinde birinci, ikinci, üçüncü ve dördüncü parçalara ayrılarak bitirildi.

Hoca çözümün basitliğini vurguladı: yapılan tek şey alanı bölmek ve yönetme aşamasında dolu olmayan çeyreklere merkezde birer kare gelecek şekilde L karo koymaktır.

## 7. Quicksort: Değere Göre Bölme

### 7.1 Tarihçe

Quicksort da tarihi algoritmalardan biridir. 1959'da Charles Anthony Richard Hoare (Tony Hoare) tarafından tasarlanmış ve 1961'de yayımlanmıştır. Hoca, quicksort'un 20. yüzyılın en iyi 10 algoritmasından biri seçildiğini söyledi. Derste yalnız en temel hali işlendi; diziyi ikiye değil üçe bölmek gibi iyileştirilmiş sürümler ileri seviye konulardır.

### 7.2 Konuma Göre Değil Değere Göre Bölme

Şimdiye kadar görülen böl ve yönet örneklerinde bölme hep konuma göre yapıldı: mergesort'ta dizi indislerine göre ortadan, bottom-up'ta ikişer ikişer, tromino'da matris ortadan dörde bölündü. Hoca, bölmenin konuma göre yapılmak zorunda olmadığını, değere göre de yapılabileceğini söyledi.

Dizideki bir eleman karşılaştırma elemanı olarak seçilir; buna pivot denir. Dizi, pivottan küçükler bir tarafta, büyükler diğer tarafta kalacak şekilde düzenlenir; buna bölümleme (partitioning) denir. Sonra her bölüm kendi içinde yine bölümlenir ve tek eleman kalana kadar devam edilir. Her adımda seçilen pivot nihai yerine taşındığı için, tümevarımla bütün dizinin sıralanacağı garanti edilir.

Partition işleminin garantisi slaytta şöyle verildi (ekrandan, 01:45:00):

- `a[j]` final pozisyonundadır.
- `a[lo, ..., j-1]` aralığında `a[j]`'den daha büyük eleman yoktur.
- `a[j+1, ..., hi]` aralığında `a[j]`'den daha küçük eleman yoktur.

Quicksort aynı dizi üzerinde çalıştığı için yerindedir (in-place); özyinelemeli çağrı yığını dışında ek dizi gerekmez. Ancak kararlı değildir. Hoca örnek verdi: dizide önce kırmızı bir 4, sonra sarı bir 4 varsa, quicksort çıktıda bu sıranın korunmasını garanti etmez.

### 7.3 Sayısal Örnek: Ortadaki Eleman Pivot

Dizi: 4, 10, 8, 7, 6, 5, 3, 12, 14, 2 (10 eleman). Bu örnekte pivot olarak ortadaki eleman seçildi (10 elemanlı dizide 5. göz, aşağı yuvarlanarak).

- İlk pivot 6'dır. Partition sonunda 6'nın solunda yalnız ondan küçükler (4, 5, 3, 2), sağında yalnız ondan büyükler (10, 8, 7, 12, 14) kalır. Parçalar kendi içinde henüz sıralı değildir.
- Sol parça 4, 5, 3, 2: ortadaki 5 pivot seçilir. 5'ten büyük eleman olmadığı için 5 en sağda kalır, sağında parça oluşmaz.
- 4, 3, 2: ortadaki 3 pivot seçilir. 2 soluna, 4 sağına geçer. 2 ve 4 tek eleman oldukları için yerlerini bulmuştur. Böylece 2, 3, 4, 5, 6 sıralanmış olur.
- Sağ parça 10, 8, 7, 12, 14: ortadaki 7 pivot seçilir. Solunda 7'den küçük eleman yoktur; 7 yerini bulur.
- 10, 8, 12, 14: pivot 8 seçilir; solunda eleman kalmaz.
- 10, 12, 14: pivot 12 seçilir; solunda 10, sağında 14 kalır; ikisi de tek eleman olduğu için sıralıdır.

Sonuç: 2, 3, 4, 5, 6, 7, 8, 10, 12, 14. Hoca, dizinin hiçbir zaman fiziksel olarak ayrılmadığını, aynı dizi üzerinde parçaların sırayla işlendiğini vurguladı.

<!-- BELİRSİZ: Altyazıda sağ parça bir yerde "18, 7, 12, 14" ve "18, 12, 14" diye geçiyor; dizinin elemanlarına göre bunlar 10, 8, 7, 12, 14 ve 10, 12, 14 olmalı. Bu örneğin karesi okunmadı. -->

### 7.4 Algoritmanın Genel Yapısı

Quicksort'un iskeleti şöyledir: sol sağdan küçük olduğu sürece (parçada birden fazla eleman olduğu sürece) bir bölme noktası bulunur. Bu, partition işleminin seçilen pivotu nihai konumuna taşıması ve solunda küçükleri, sağında büyükleri bırakmasıdır. Sonra sol taraf (`left`'ten bölme noktasının bir eksiğine kadar) quicksort'a, ardından sağ taraf quicksort'a gönderilir. Hoca bunun top-down mergesort ile tamamen aynı yaklaşım olduğunu, farkın bölme noktasının ortadaki indis yerine seçilen bir değere göre belirlenmesi olduğunu söyledi.

Asıl sorun pivotun nasıl seçileceğidir. Pek çok strateji vardır. En iyi yaklaşımlardan biri parçanın içinden rastgele bir eleman seçmektir; bu, en kötü duruma düşmeyi engeller. Pivot seçme stratejisi kötüyse quicksort en kötü durumda $O(n^2)$'ye çıkabilir. Derste en basit strateji kullanıldı: parçadaki ilk elemanı (`low` indisindeki elemanı) pivot seçmek.

## 8. Hoare Partition

### 8.1 İki İndisle Tarama

İlk eleman pivot seçildiğinde amaç, dizinin pivottan küçük ve büyük elemanlarını iki tarafa toplamak ve en sonunda pivotu ikisinin arasına koymaktır. Bunun için iki indis kullanılır (ekrandan, 01:55:00):

- `i` soldan sağa tarar ve pivottan büyük bir eleman bulana kadar ilerler. Bu, sağ tarafa atılması gereken bir elemandır.
- `j` sağdan sola tarar ve pivottan küçük bir eleman bulana kadar ilerler. Bu, sol tarafta olması gereken bir elemandır.
- İkisi de bulununca yer değiştirilir (swap) ve aramaya devam edilir.

Slayttaki şema:

```text
| p | all are <= p | >= p | . . . | <= p | all are >= p |
                     i ->           <- j
```

Hoca örnek verdi: pivot 5 iken `i` 8 diye bir değer bulursa bu sol bölümde kalmaması gereken bir değerdir; `j` 3 diye bir değer bulursa bu sağ bölümde kalmaması gereken bir değerdir. İkisi yer değiştirir. Bu işlem `i` ile `j` kesişene (birbirini geçene) kadar sürer. Kesişme noktası pivotun durması gereken yerdir. En sonunda pivot, `j`'nin gösterdiği elemanla yer değiştirir. `j`'nin gösterdiği eleman pivottan küçük olduğu için pivotla yer değiştirince yine sol tarafta kalır.

**Soru:** Pivotun sağındaki bütün değerler büyükse ama solunda olması gerekenden büyük değer varsa ne olur? `i` ve `j` çakışınca yine swap mı yapılır?
**Cevap:** Evet. Çakışana kadar bulunan bütün çiftler yer değiştirilir. Çakışma noktası küçükleri ve büyükleri arayan iki indisin birbirini geçtiği noktadır ve pivotun durması gereken yer orasıdır.

**Soru:** Bir tarafta hiç uygun eleman yoksa, örneğin pivottan sonra 6, 7, 8 gibi büyük değerler arasında yalnız bir tane 1 varsa, `j` bir değer bulamaz mı?
**Cevap:** `j` pivottan küçük ya da eşit olan elemanı arar. Arada bir 1 varsa `j` onu bulur ve orada durur. Hoca, sayısal örnek üzerinden anlatınca bu durumun daha iyi anlaşılacağını söyledi.

Hoca, her swap ile dizinin sırasının değiştiğini ama küçüklerin solda, büyüklerin sağda toplanmaya devam ettiğini vurguladı. `i > j` olduğunda artık soldaki taramayla bütün küçüklerin, sağdaki taramayla bütün büyüklerin doğru tarafta olduğu garanti edilir.

### 8.2 Sözde Kod

Slayttaki sözde kod (ekrandan, 02:05:00):

```text
ALGORITHM HoarePartition(A[l..r])
// Partitions a subarray by Hoare's algorithm, using the first element as a pivot
// Input: Subarray of array A[0..n - 1], defined by its left and right indices l and r (l<r)
// Output: Partition of A[l..r], with the split position returned as this function's value

p <- A[l]
i <- l; j <- r + 1
repeat
    repeat i <- i + 1 until A[i] >= p
    repeat j <- j - 1 until A[j] <= p
    swap(A[i], A[j])
until i >= j
swap(A[i], A[j])   // undo last swap when i >= j
swap(A[l], A[j])   // place pivot to the final position
return j
```

Dış döngüde `i >= j` kontrolü kesişmeyi yakalar. Kesişmeden sonra döngü içinde bir fazla swap yapılmış olur; bu yüzden son swap geri alınır. Sonra pivot (`A[l]`) `j` konumuna taşınır ve `j` döndürülür. Artık `j` indisindeki değer pivotun gerçek yeridir; solundakiler küçük, sağındakiler büyüktür.

> **Ders sonrası not:** Hoca, `i`'nin pivottan büyük eleman bulamadığı durumda dizinin sonunu aşmaması için sözde kodda bir sınır kontrolünün eksik olduğunu söyledi. C kodunda bu kontrol `if(i==r) break;` satırıyla yapılır.

### 8.3 Sayısal Örnek: 5, 3, 1, 9, 8, 2, 4, 7

Bu örnek slayttan alınmıştır (ekrandan, 02:10:00). Pivot ilk eleman 5'tir.

| Adım | Dizi (indis 0-7) | Açıklama |
| --- | --- | --- |
| Başlangıç | 5 3 1 9 8 2 4 7 | Pivot 5 |
| `i` taraması | 5 3 1 **9** 8 2 4 7 | 3 ve 1 küçük, geçilir; `i` 9'da (indis 3) durur |
| `j` taraması | 5 3 1 9 8 2 **4** 7 | 7 büyük, geçilir; `j` 4'te (indis 6) durur |
| swap | 5 3 1 4 8 2 9 7 | 9 ile 4 yer değiştirir |
| `i`, `j` taraması | 5 3 1 4 **8** **2** 9 7 | `i` 8'de (indis 4), `j` 2'de (indis 5) durur |
| swap | 5 3 1 4 2 8 9 7 | 8 ile 2 yer değiştirir |
| Kesişme | 5 3 1 4 2 8 9 7 | `i` 8'e (indis 5), `j` 2'ye (indis 4) gelir; `i > j` |
| exchange | 2 3 1 4 **5** 8 9 7 | Pivot 5, `j` gözündeki 2 ile yer değiştirir |

Bu adımda dizide yalnız bir eleman (5) nihai yerine oturmuştur. Solundaki 2, 3, 1, 4 ondan küçük, sağındaki 8, 9, 7 ondan büyüktür; parçalar henüz sıralı değildir.

**Soru:** `i` ile `j` yer değiştirmek yerine aynı konumda da durabilir. O zaman karşılaştırıp mı yerleştiririz?
**Cevap:** Hoca, uç durumların ayrıca ele alınabileceğini, önce algoritmanın genel çalışma mantığının öğrenilmesi gerektiğini söyledi.

Sol parça 2, 3, 1, 4:

- Pivot 2'dir. `i` 3'te durur (2'den büyük). `j` 4'ü geçer, 1'de durur (2'den küçük). 3 ile 1 yer değiştirir: 2, 1, 3, 4.
- `i` ve `j` kesişir. Pivot 2, `j`'nin gösterdiği 1 ile yer değiştirir: 1, 2, 3, 4.
- 2'nin solunda tek eleman (1) kalır; tek eleman zaten yerindedir.
- 2'nin sağı 3, 4: pivot 3'tür. `i` ve `j` aynı yerde çakışır, 4 büyük olduğu için sağda kalır; 3 ile 4 yer değiştirmez. 4 tek eleman olarak yerini bulur.

Sağ parça 8, 9, 7:

- Pivot 8'dir. `i` 9'da, `j` 7'de durur; yer değiştirirler: 8, 7, 9.
- Kesişme olur; pivot 8, `j`'nin gösterdiği 7 ile yer değiştirir: 7, 8, 9.
- 7 ve 9 tek eleman olarak yerlerini bulur.

Sonuç: 1, 2, 3, 4, 5, 7, 8, 9. Partition, sol quicksort ve sağ quicksort bittikten sonra yapılacak başka iş kalmaz.

## 9. Quicksort'un C Kodu ve Çağrı Ağacı

### 9.1 Kod

Slayttaki kod (ekrandan, 02:20:00):

```c
#define exch(A, B) {int t=A; A=B, B=t;}

int partition(int a[], int l, int r){
        int i = l, j = r+1, v = a[l];
        for(;;){
                while(v>a[++i]) if(i==r) break;
                while(a[--j]>v) if(j==l) break;
                if (i>=j) break;
                exch(a[i],a[j]);
        }
        exch(a[j],a[l]);
        return j;
}

void quicksort(int a[], int l, int r){
        int i;
        if (r<l) return;
        i = partition(a, l, r);
        quicksort(a, l, i-1);
        quicksort(a, i+1, r);
}

int main(){
   int a[] = {8,1,6,4,0,3,9,5};
   int n = sizeof a / sizeof *a;
   quicksort(a,0,n-1);
   return 0;
}
```

`exch` makrosu iki elemanın yerini değiştirir; kod kısa olsun diye tanımlanmıştır. `main` 8, 1, 6, 4, 0, 3, 9, 5 dizisini tanımlar ve `quicksort(a, 0, n-1)` çağırır. `quicksort`, sağ sınır soldan küçükse (parça boşsa) geri döner. Değilse `partition` ile pivotun yerini bulur, sonra solu ve sağı yeniden quicksort'a gönderir.

`partition` içinde `i` sol sınırdan, `j` ise `r+1`'den başlar. `j`'nin `r+1`'den başlamasının sebebi ilk adımda önce eksiltilip son elemana bakılmasıdır. Pivot `v`, parçanın ilk elemanıdır (`a[l]`). İlk `while`, `v > a[++i]` olduğu sürece `i`'yi artırır; yani pivottan büyük ya da eşit bir eleman bulunca durur. `if(i==r) break;` satırı `i`'nin parçanın sonunu aşmasını engeller. İkinci `while`, `a[--j] > v` olduğu sürece `j`'yi azaltır; pivottan küçük ya da eşit bir eleman bulunca ya da başa gelince durur. `i >= j` olmuşsa sonsuz döngüden çıkılır; değilse iki eleman yer değiştirir. Döngüden çıkınca pivot `j` konumuna taşınır ve `j` döndürülür.

**Soru:** Burada `break` kullanılmasının sebebi ne? Bize hep `break` kullanmayın deniyor.
**Cevap:** Hoca, `break` ile döngüden zorla çıkmanın iyi bir yöntem olmadığını ve döngüyü düzgün kurmamak anlamına geldiğini kabul etti. Okunabilirlik için döngünün başının ve sonunun açık olması gerekir. Bu kodun slayta sığması ve hızlı bir uygulama olması için böyle yazıldığını söyledi. İki `break`, `j`'nin sıfırın altına ve `i`'nin sonun ötesine gitmemesini, `if (i>=j) break;` ise kesişmeden sonra daha fazla arama yapılmamasını garanti eder; bu yüzden döngüden her zaman çıkılır. Öğrencilerin daha güzel kod yazabileceğini ekledi.

### 9.2 Çalışma Adımları

Slayttaki ara durumlar (her partition sonrası) şunlardır:

```text
8 1 6 4 0 3 9 5    başlangıç, pivot 8
5 1 6 4 0 3 8 9    8 yerine oturdu (indis 6); sağında yalnız 9
0 1 3 4 5 6 8 9    sol parçada pivot 5 yerine oturdu; solunda 0 1 3 4, sağında 6
0 1 3 4 5 6 8 9    pivot 0: solu boş
0 1 3 4 5 6 8 9    pivot 1: solu boş
0 1 3 4 5 6 8 9    pivot 3: solu boş, 4 sağda
0 1 3 4 5 6 8 9    pivot 4 ve 6 tek eleman
0 1 3 4 5 6 8 9    8'in sağındaki 9 tek eleman
```

İlk partitionda 8'in solunda 5, 1, 6, 4, 0, 3 (hepsi 8'den küçük), sağında 9 kalır. Sol parçada 5 pivot seçilir ve yerine oturur; solunda 0, 1, 3, 4, sağında 6 kalır. Sonra sırasıyla 0, 1, 3 ve 4 pivot seçilir. Hoca, başlangıç durumu sayesinde bu parçanın şans eseri hemen sıralandığını söyledi. Ardından 5'in sağındaki 6 ve en son 8'in sağındaki 9 tek eleman olarak yerlerinde kalır.

### 9.3 Çağrı Ağacı

Hoca, 8.3'teki 5, 3, 1, 9, 8, 2, 4, 7 örneği için quicksort'un özyinelemeli çağrı ağacını indisleriyle gösterdi. 0'dan 7'ye olan çağrıda bölme noktası 4 olur; bu çağrı 0'dan 3'e olan parçayı çağırır. O, tek elemanlı ya da boş parçalar için hemen geri döner; 2'den 3'e olan parçayı işler. Sol taraf tamamlanınca 5'ten 7'ye olan parçaya geçilir; bölme noktası 6 olduğu için 5'ten 5'e ve 7'den 7'ye olan tek elemanlı çağrılar hiçbir işlem yapmadan geri döner.

<!-- BELİRSİZ: Bu çağrı ağacı slaydının karesi okunmadı; indisler altyazıdan aktarıldı. -->

Hoca, tek elemanlı parçalara inildiğinde partition işlemi yapılmadığını, bu yüzden oralarda bir kazanç oluştuğunu söyledi. Ama ağacın alt kısımlarında çok sayıda boş ya da tek elemanlı çağrı yapılır.

## 10. Quicksort İçin İyileştirmeler

### 10.1 Pivot Seçimi

Pivotu her zaman ilk eleman seçmek çok sevilen bir yaklaşım değildir. Son eleman seçmek de çok etkili değildir. Rastgele pivot seçmek başka bir yaklaşımdır.

### 10.2 İki Pivot ile Üç Bölüm

Hoca şu soruyu sordu: Neden tek pivotla ilerliyoruz? Örneğin baştaki ve sondaki elemanı iki pivot (P1 ve P2) seçip diziyi üç bölüme ayırabiliriz:

```text
| <= P1 | P1 | P1 < x < P2 | P2 | >= P2 |
```

Birinci pivotun solunda ondan küçükler, ikinci pivotun sağında ondan büyükler, ikisinin arasında da P1'den büyük ve P2'den küçük değerler kalır. Hoca bunun yapılabileceğini ve çalışma zamanını biraz daha iyileştirdiğini söyledi. Ona göre en verimli quicksort uygulamaları her parçanın içinde iki rastgele pivot seçerek yapılır.

> **Ek bilgi (derste anlatılmadı):** İki pivotla üç bölüm oluşturan yönteme "dual-pivot quicksort" denir; Java'nın ilkel tipler için kullandığı sıralama bu yaklaşımı kullanır. "Three-way partitioning" adı ise literatürde genellikle tek pivotla küçük, eşit ve büyük olmak üzere üç bölüm oluşturan (çok sayıda eşit anahtar için tasarlanmış) yöntem için kullanılır.

**Soru (hocanın sorusu):** Üç pivotla dört bölüm yapabilir miyiz? Neden?
**Cevap:** Hoca, dörde bölmenin aslında ikiye bölmeyi iki kez yapmakla aynı olduğunu söyledi. Özyinelemeli ağaç zaten o noktada bölünecektir; elle bölmeye çalışmak fazladan iki pivot işlemi ve boşuna işlem karmaşıklığı getirir. Bu yüzden dörtlü bölme mantıklı değildir, üçlü bölme mantıklıdır.

### 10.3 Küçük Parçalarda Insertion Sort

Çağrı ağacında belli bir derinlikten sonra çok sayıda boş ya da tek elemanlı çağrı yapılır. Bu fazla özyinelemeli çağrılar toplam çalışma süresini artırır. Hoca bir iyileştirme anlattı: quicksort belli bir derinliğe kadar (örneğin parçalar 3-5 elemana inene kadar; bu sınırı $n$'ye bağlı hesaplamanın yolları vardır) uygulanır. O noktada pivotlar sayesinde parçalar kendi içinde büyük ölçüde düzenlenmiş olur.

**Soru (hocanın sorusu):** Neredeyse sıralı küçük parçalarda hangi algoritmanın iyi çalıştığını söylemiştik?
**Cevap:** Insertion sort. Neredeyse sıralı dizileri doğrusala yakın sürede sıralar.

Böylece kalan küçük parçalar insertion sort ile tamamlanır. Hoca bunu bayrak yarışına benzetti: bir algoritmanın getirdiği fayda bir yere kadar taşınır, sonra doğal olarak oluşan alt sıralı parçalarda daha iyi çalıştığı bilinen başka bir algoritmayla yola devam edilir. Bir algoritmayı körü körüne sonuna kadar kullanmak zorunlu değildir.

## 11. Son Eleman Pivot Olan Partition

### 11.1 Sözde Kod

Hoca, pivotun son eleman seçildiği ve `i`, `j` indislerinin anlamının farklı olduğu bir partition yöntemi gösterdi (ekrandan, 02:35:00). Sözde kodda kitapta kullanıldığı gibi `p` ve `r` harfleri kullanılmıştır:

```text
QuickSort(A,p,r)
if (p<r)
  q=Partition(A,p,r)
  QuickSort(A,p,q-1)
  QuickSort(A,q+1,r)

Partition (A, p, r)
v=A[r]
i=p-1
for j= p to r-1
   if A[j] <= x
      i=i+1
      A[i] <=> A[j]
A[i+1] <=> A[r]
return i+1
```

> **Ders sonrası not:** Slaytta pivot `v=A[r]` diye tanımlanmış ama karşılaştırma `A[j] <= x` diye yazılmıştır. Buradaki `x`, pivot `v` ile aynı değerdir.

Burada `i` ve `j` ikisi de baştan başlar. `j` diziyi `r-1`'e kadar tarar. `A[j]` pivottan küçük ya da eşitse `i` bir artırılır ve `A[i]` ile `A[j]` yer değiştirir. Tarama boyunca şu düzen korunur:

- `p..i` aralığı pivottan küçük değerleri tutar.
- `i+1..j-1` aralığı pivottan büyük ya da eşit değerleri tutar.
- `j..r-1` aralığı henüz işlenmemiş elemanlardır.
- `r` gözünde pivot durur.

Tarama bitince pivot `A[i+1]` ile yer değiştirir. Pivot küçüklerin yanına değil büyüklerin başına konur; böylece büyüklerin sağda kalması garanti edilir.

### 11.2 Sayısal Örnek: 8, 1, 6, 4, 0, 3, 9, 5

Pivot son eleman 5'tir. `i` başlangıçta dizinin başının bir solundadır.

| `j`'nin gördüğü | Karar | Dizi |
| --- | --- | --- |
| 8 | 5'ten büyük, geç | 8 1 6 4 0 3 9 5 |
| 1 | küçük: `i` artar, swap | 1 8 6 4 0 3 9 5 |
| 6 | büyük, geç | 1 8 6 4 0 3 9 5 |
| 4 | küçük: `i` artar, swap | 1 4 6 8 0 3 9 5 |
| 0 | küçük: `i` artar, swap | 1 4 0 8 6 3 9 5 |
| 3 | küçük: `i` artar, swap | 1 4 0 3 6 8 9 5 |
| 9 | büyük, geç | 1 4 0 3 6 8 9 5 |
| son | pivot `A[i+1]` ile swap | 1 4 0 3 **5** 8 9 6 |

<!-- BELİRSİZ: Bu tablonun ara satırları altyazıdaki anlatımdan ve sözde kodun bir python denemesinden kuruldu; slaydın karesi okunmadı. Hoca anlatırken 0 ile 6'nın ve 3 ile 8'in yer değiştirdiğini söylüyor; tablo bununla uyumludur. -->

Sonra sol parça 1, 4, 0, 3 işlenir: pivot 3'tür. 1 küçük olduğu için yerinde kalır, 4 geçilir, 0 bulununca 4 ile yer değiştirir (1, 0, 4, 3); en son pivot 3, 4 ile yer değiştirir: 1, 0, 3, 4. Ardından 1, 0 parçasında pivot 0'dır; 1 büyük olduğu için geçilir ve 0 ile 1 yer değiştirir: 0, 1. 4 tek elemandır. Sol taraf 0, 1, 3, 4 olarak sıralanır. Sağ parça 8, 9, 6'da pivot 6 seçilir ve aynı yolla işlenir. Sonuç 0, 1, 3, 4, 5, 6, 8, 9 olur.

### 11.3 C Kodu

Slayttaki kod (ekrandan, 02:45:00):

```c
#define exch(A, B) {int t=A; A=B, B=t;}

int partitionR(int a[], int l, int r){
        int i = l-1, j = r, v = a[r];
        for(;;){
                while(a[++i]<v);
                while(v<a[--j]) if(j==l) break;
                if (i>=j) break;
                exch(a[i],a[j]);
        }
        exch(a[i],a[r]);
        return i;
}

void quicksort(int a[], int l, int r){
        int i;
        if (r<l) return;
        i = partitionR(a, l, r);
        quicksort(a, l, i-1);
        quicksort(a, i+1, r);
}

int main(){
   int a[] = {8,1,6,4,0,3,9,5};
   int n = sizeof a / sizeof *a;
   quicksort(a,0,n-1);
   return 0;
}
```

`main` ve `quicksort` aynıdır; tek fark `partitionR` fonksiyonudur. Bu kodda `i` soldan pivottan küçük olmayan bir eleman, `j` sağdan pivottan büyük olmayan bir eleman arar; `j` sol sınıra gelince durur. Hoca, `while` yapısı yüzünden ara durumların slayttaki sözde koddan biraz farklı olabileceğini söyledi: sözde kodda ilk adım 1, 4, 0, 3, 5, ... verirken bu kod 3, 1, 0, 4, 5, 8, 9, 6 verir.

Slayttaki ara durumlar:

```text
8 1 6 4 0 3 9 5    başlangıç, pivot 5
3 1 0 4 5 8 9 6    5 yerine oturdu
3 1 0 4 5 8 9 6    sol parçada pivot 4: solundakiler zaten küçük
0 1 3 4 5 8 9 6    3 1 0 parçasında pivot 0 başa geçti
0 1 3 4 5 8 9 6    1 3 parçasında pivot 3; 1 tek eleman
0 1 3 4 5 8 9 6    sağ parça 8 9 6, pivot 6
0 1 3 4 5 6 9 8    6 yerine oturdu
0 1 3 4 5 6 8 9    9 8 parçasında pivot 8 yerine oturdu
0 1 3 4 5 6 8 9    9 tek eleman
```

> **Ek bilgi (derste anlatılmadı):** Bu notta tam verilen üç C kodu (mergesort, `partition` ile quicksort, `partitionR` ile quicksort) derste gösterildiği haliyle `gcc -Wall` ile derlendi ve çalıştırıldı. Mergesort 32, 45, 67, 2, 7 dizisini 2, 7, 32, 45, 67 olarak sıraladı. İki quicksort kodunda her partition sonrası yazdırılan diziler slayttaki satırlarla aynı çıktı; `partition` 5, 3, 1, 9, 8, 2, 4, 7 dizisinde de ilk adımda 8.3'teki tabloyla aynı sonucu (2, 3, 1, 4, 5, 8, 9, 7) verdi. `partitionR`'deki ilk `while` döngüsünde sınır kontrolü yoktur; pivot parçanın son elemanı olduğu için `i` en geç pivotta durur.

## 12. Quicksort'un Karmaşıklığı ve Kararlılığı

Hoca quicksort'un analizine uzun uzun girmedi. Ortalama durumda, pivot seçiminin rastgele ya da düzgün yapıldığı varsayılarak karmaşıklık $O(n \log n)$'dir. Ancak pivot seçme politikasına bağlı olarak en kötü durumda $O(n^2)$'ye çıkılabilir.

Hoca iyileştirmeleri tekrar özetledi: tek pivot yerine iki pivot ve üç bölüm kullanmak; çok büyük dizilerde (milyonluk, milyarlık) parçaları belli bir boyuta kadar quicksort ile bölüp kalanları insertion sort ile bitirmek. Amaç quicksort'un gereksiz yere tek elemana kadar özyinelemeye düşmesini engellemek, hocanın deyişiyle "özyinelemenin lanetinden" (curse of recursion) mümkün olduğunca kaçınmaktır.

Quicksort yerinde çalışır, ek bir dizi kullanmaz. Ama eşit değerlerin başlangıçtaki sırasının sonda korunmasını garanti edemez, çünkü sürekli yer değiştirme yapılır. Hoca son örnekteki 8, 9, 6 parçasını gösterdi: elemanlar swap işlemleri sırasında sürekli yer değiştirdi. Eşit değerlerde sıranın korunması gerekiyorsa quicksort kullanılamaz.

> **Hocanın vurgusu:** Quicksort'ta da dizi bölünür ama bölme bir değere göre yapılır. Seçilen pivottan küçükler solda, büyükler sağda kalır. Her adımda pivot doğru konumuna taşındığı için tek eleman kalana kadar sürdürüldüğünde bütün dizi sıralanmış olur.

## Örnek Sorular

Aşağıdaki sorular dersin başında çözülen kısa sınavdandır. Şıkların sırası öğrenciden öğrenciye karışık gelebilir.

### Soru 1 (derste sözlü, 00:05:26)

Aşağıdaki min-heap'e 8 değeri eklenmek isteniyor. Min-heap özelliğinin korunması için hangi sayılarla karşılaştırma yapılır?

Heap (düzey düzey; 2. sorudaki ağaçla aynıdır, ekrandan, 00:10:00): 1; 9, 2; 13, 10, 5, 3; 15, 14, 11, 21, 7, 6, 4, 17.

<!-- BELİRSİZ: Bu sorunun karesi okunmadı; ağaç, hocanın "yine aynı heap ağacı" demesine dayanarak 2. sorunun karesinden alındı. 17'nin konumu karede silinmiş, anlatımdan kuruldu. -->

> **Çözüm (derste verildi):** 8 ilk boş göze, 15'in sol çocuğu olarak eklenir. 8 < 15 olduğu için yer değiştirir; 8 < 13 olduğu için yer değiştirir; 8 < 9 olduğu için yer değiştirir; 8 > 1 olduğu için durur. Karşılaştırılan sayılar: 15, 13, 9, 1.

### Soru 2 (ekrandan, 00:10:00)

Verilen min-heap ağacındaki en küçük eleman silinmek isteniyor. Ağacın min-heap özelliğini koruması için hangi sayılar karşılaştırma işlemine dahil olur?

> **Çözüm (derste verildi):** Kök 1 silinir, son eleman 17 köke taşınır. 17 çocukları 9 ve 2 ile karşılaştırılır; en küçük 2 yukarı çıkar. 17 yeni çocukları 5 ve 3 ile karşılaştırılır; 3 yukarı çıkar. 17 tek çocuğu 4 ile karşılaştırılır; 4 yukarı çıkar. Karşılaştırmaya giren sayılar: 17, 9, 2, 5, 3, 4.

### Soru 3 (derste sözlü, 00:11:25)

Kruskal'ın minimum spanning tree algoritmasında kenarların azalan yerine artan sırada işlenmesinin sebebini açıklayan en uygun cevap hangisidir? Seçenekler: en kötü durum karmaşıklığını azaltmak; doğruluğu garanti etmek; daha az bellek alanı kullanmak; kodlama basitliği; hiçbiri.

> **Çözüm (derste verildi):** Doğruluğu garanti etmek. Toplam ağırlığı en küçük ağaç ancak en küçük kenardan başlanarak garanti edilir. Gezme yönünün karmaşıklık, bellek ya da kodlama ile ilgisi yoktur.

### Soru 4 (ekrandan, 00:15:00)

Kenar ağırlıkları pozitif ve ayrık tamsayılardan oluşan (eşit değerli kenar ağırlıkları bulunmayan), kendisine döngü içeren düğümü olmayan ve paralel kenar içermeyen (düğümler arasında tekil bağlantıları olan) bir G grafı veriliyor. G grafına ait Kruskal algoritması ile minimum spanning tree (MST) için aşağıdaki ifadelerden doğru olanları yazınız.

1. G'nin herhangi bir MST'si en küçük ağırlıklı kenarı mutlaka içerir.
2. G'nin herhangi bir MST'si en büyük ağırlıklı kenarı hiçbir zaman içermez.
3. G'nin her zaman tek bir MST'si vardır.
4. G'nin herhangi bir V düğümünün bağlı olduğu kenar ağırlıkları 10 arttırılırsa; G'nin herhangi bir MST'si, güncellenen grafın da MST'sidir.
5. G'deki tüm kenar ağırlıkları 10 arttırılırsa; G'nin herhangi bir MST'si, güncellenen grafın da MST'sidir.

> **Çözüm (derste verildi):** Doğru olanlar 1, 3 ve 5'tir.
>
> - 1 doğrudur: Kruskal en küçük kenarı seçerek başlar.
> - 2 yanlıştır: hocanın örneğinde 1, 2 ve 5 ağırlıklı kenarlar bir üçgen oluşturur, 15 ağırlıklı kenar dördüncü düğüme giden tek kenardır. 1 ve 2 seçilir, 5 çevrim oluşturduğu için atlanır, 15 seçilmek zorundadır.
> - 3 doğrudur: ağırlıklar ayrık olduğu için Kruskal her seferinde aynı tek kenarı seçer.
> - 4 yanlıştır: aynı örnekte 1 ve 2 ağırlıklı kenarların ortak düğümünün kenarları 11 ve 12 olur. Kruskal bu kez 5, 11 ve 15'i seçer; MST değişmiştir.
> - 5 doğrudur: bütün ağırlıklara aynı sabit eklenince sıralama değişmez ve aynı MST elde edilir.

<!-- BELİRSİZ: Hocanın tahtaya çizdiği örnek graf altyazıdan kuruldu; çizimin karesi okunmadı. -->

### Soru 5 (derste sözlü, 00:20:09)

Prim algoritmasının karmaşıklığını iyileştirmek, yani $O(E \log V)$ yapmak için aşağıdakilerden hangisinin kullanılması en uygundur?

<!-- BELİRSİZ: Şıkların tam metni okunamadı; altyazıda yığın, ikili ağaç, FIFO kuyruk, öncelikli kuyruk ve "hepsi kullanılabilir" seçenekleri geçiyor. -->

> **Çözüm (derste verildi):** Öncelikli kuyruk. Yığın, ikili ağaç ve FIFO kuyruk en küçük kenarı seçmeye yaramaz; hepsi aynı anda doğru olamaz.

### Soru 6 (derste sözlü, 00:21:01)

0'dan 9'a kadar numaralı düğümler aşağıdaki çiftler halinde birleştirildiğinde graf üzerinde kaç adet bağlı bileşen oluşur? Birleştirilen çiftler (altyazıdaki sırayla): 1-2, 3-4, 5-6, 7-8, 7-9, 2-8, 0-5, 1-9.

<!-- BELİRSİZ: Bu sorunun karesi okunmadı; çiftler altyazıdan alındı. -->

> **Çözüm (derste verildi):** Bileşenler {1, 2, 7, 8, 9}, {3, 4} ve {0, 5, 6} olur. 1-9 birleştirmesi zaten aynı bileşendeki düğümleri bağladığı için bileşen sayısını değiştirmez, yalnız bir çevrim oluşturur. Cevap 3'tür.

### Soru 7 (ekrandan, 00:25:00)

Aşağıda verilen Huffman kodunda S sembolünün kod karşılığı ne olabilir?

| Sembol | Kod |
| --- | --- |
| A | 00 |
| B | 01100 |
| E | 10 |
| P | 0111 |
| R | 01101 |
| S | ? |
| T | 11 |

> **Çözüm (derste verildi, ekrandan, 00:30:00):** A (00), E (10) ve T (11) yapraktır; S, 01 ile başlamak zorundadır. 011 dalının altı P (0111), B (01100) ve R (01101) ile tamamen doludur. Geriye tek boş yer 010 kalır. Toplam 7 sembol vardır ve ağaçta 7 yaprak oluşur; S daha derine (örneğin 0100) konursa boş yapraklar kalır, bu mümkün değildir. İç düğümlere sembol konamaz. Cevap: 010.

### Soru 8 (derste sözlü, 00:31:38)

n elemanlı yapılarda en küçük elemanı silmenin en kötü durum işlem karmaşıklığını sırasıyla yazınız: küçükten büyüğe sıralı dizi, sırasız dizi, küçükten büyüğe sıralı tek bağlı liste (singly linked list), sırasız bağlı liste, ikili min-heap.

> **Çözüm (derste verildi):** $O(n)$, $O(n)$, $O(1)$, $O(n)$, $O(\log n)$. Sıralı dizide en küçük eleman baştadır ama silinince kalan elemanlar kaydırılmalıdır. Sırasız dizide önce en küçük bulunur, sonra kaydırma yapılır. Sıralı tek bağlı listede baştaki düğüm silinir. Sırasız bağlı listede $n$ düğüm gezilir. Min-heap'te silmeden sonra heapify ağacın yüksekliği kadar, yani $\log n$ işlem yapar.

### Soru 9 (ekrandan, 00:35:00)

Aşağıda verilen graf için işaretli olan s düğümünden başlanarak Prim algoritması ile minimum spanning tree (MST) elde ediliyor. MST'de bulunan kenarların ağırlık değerlerini MST'ye eklenme sırası ile yazınız.

Graf iki sıra halinde sekiz düğümden oluşur. Üst sıradaki düğümlere soldan sağa a, b, c, s, alt sıradakilere e, f, g, h diyelim (adlar nota eklendi). Kenarlar: a-b 10, b-c 20, c-s 70, a-e 100, b-f 50, a-f 40, c-f 30, c-g 80, s-g 60, s-h 130, e-f 110, f-g 90, g-h 120.

> **Çözüm (derste verildi):** s'nin kenarları 70, 60 ve 130 kuyruğa eklenir; önce 60 (s-g) seçilir. g'nin kenarları 80, 90, 120 eklenir; en küçük 70 (s-c) seçilir. c'nin kenarları 20, 30, 80 eklenir; 20 (c-b) seçilir. b'nin kenarları 10, 50 eklenir; 10 (b-a) seçilir. a'nın kenarları 40, 100 eklenir; kuyrukta hâlâ duran 30 (c-f) seçilir. 40, 50, 80 ve 90 artık çevrim oluşturduğu için atlanır. e'ye ulaşmak için 110 yerine 100 (a-e) seçilir. Son olarak h için 130 yerine 120 (g-h) seçilir. Sıra: 60, 70, 20, 10, 30, 100, 120. En sık hata 60 yerine 70 ile başlamaktır.

### Soru 10 (ekrandan, 00:40:00)

Aşağıdaki problemlerden hangisinin veya hangilerinin böl ve yönet (divide and conquer) yaklaşımı ile çözülmesi uygundur?

1. Yığına yeni bir eleman ekleme
2. Kuyruğa (FIFO) yeni bir eleman ekleme
3. Verilen bir N sayısına kadar olan Fibonacci sayılarını elde etme
4. Bir diziyi küçükten büyüğe sıralama

> **Çözüm (derste verildi):** Yalnız 4. Yığına ve kuyruğa ekleme yapıyı bölerek yapılmaz. Fibonacci'de özyineleme vardır ama alt problemler birbirine bağlıdır; bu böl ve yönet değildir. Diziyi sıralama mergesort ile böl ve yönet yaklaşımıyla yapılır. En sık verilen yanlış cevap 3 ve 4 idi.

### Soru 11 (derste sözlü, 02:48:34)

Quicksort'ta üç pivot kullanarak diziyi dört bölüme ayırmak mantıklı mıdır? Neden?

> **Çözüm (derste verildi):** Mantıklı değildir. Dörde bölmek ikiye bölmeyi iki kez yapmakla aynıdır; özyinelemeli ağaç zaten o noktada bölünecektir. Fazladan pivot işlemleri boşuna karmaşıklık getirir. İki pivotla üç bölüm ise mantıklıdır.

## Dersin Toparlaması

Ders, kısa sınav sorularının çözümüyle heap, Kruskal, Prim, bağlı bileşen, Huffman ve karmaşıklık konularını tekrar ederek başladı. Son soru böl ve yönete bağlandı: her özyinelemeli çözüm böl ve yönet değildir, parçaların bağımsız çözülebilmesi gerekir. Ardından top-down mergesort'un çağrı ağacı ve $O(n \log n)$ zaman, $O(n)$ ek bellek gerektiren karmaşıklığı incelendi, C kodu gösterildi. Bottom-up mergesort ile aynı işin özyineleme olmadan, alt dizi boyutunu ikiye katlayan iki döngüyle yapılabileceği görüldü. Tromino bulmacası böl ve yönetin sıralama dışındaki bir kullanımını gösterdi.

Dersin ikinci yarısında quicksort işlendi. Quicksort da diziyi böler, ama bölmeyi konuma göre değil seçilen bir pivot değerine göre yapar. Hoare partition (ilk eleman pivot) ve son elemanı pivot alan partition, sayısal örnekler ve C kodlarıyla adım adım izlendi. Quicksort ortalamada $O(n \log n)$, kötü pivot seçiminde $O(n^2)$'dir; yerinde çalışır ama kararlı değildir. İki pivotlu üç bölümleme ve küçük parçalarda insertion sort'a geçme, pratikte kullanılan iyileştirmeler olarak anlatıldı. Hoca bir sonraki haftada arama algoritmalarına, özellikle metin (string) aramaya geçileceğini söyledi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
