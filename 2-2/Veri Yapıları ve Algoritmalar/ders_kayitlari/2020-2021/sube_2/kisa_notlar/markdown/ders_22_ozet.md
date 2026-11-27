# Ders 22 Çalışma Özeti

## Genel Konular

- Kısa sınav (quiz) sorularının çözümü
  - Min-heap'e eleman ekleme ve en küçük elemanı silme sırasında karşılaştırmaya giren sayılar.
  - Kruskal algoritmasında kenarların artan sırada işlenmesinin sebebi ve ayrık kenar ağırlıklı grafta MST özellikleri.
  - Prim algoritmasının karmaşıklığını iyileştiren veri yapısı (öncelikli kuyruk) ve verilen bir grafta Prim ile MST kenarlarının eklenme sırası.
  - Birleştirme işlemleri sonunda bağlı bileşen sayısı, Huffman kod tablosunda eksik kodun bulunması.
  - Farklı veri yapılarında en küçük elemanı silmenin en kötü durum karmaşıklığı.
  - Böl ve yönet (divide and conquer) ile çözülmeye uygun problemler.
- Top-down mergesort'un çağrı ağacı ve karmaşıklık analizi
  - 16 elemanlı dizi için `MergeSort(A, 0, 15)` çağrısının özyinelemeli (recursive) dallanması.
  - $\log n$ seviye, her seviyede $n$ eleman: $O(n \log n)$ zaman, $O(n)$ ek bellek (auxiliary space).
  - Mergesort'un C kodu: `mergeSort` ve `merge` fonksiyonları.
- Sıralama algoritmalarını seçme ölçütleri
  - Zaman karmaşıklığı, kararlılık (stability), yerinde (in-place) çalışma, ek bellek ihtiyacı.
- Bottom-up mergesort
  - Özyineleme yerine iki döngüyle 1'lileri, 2'lileri, 4'lüleri, ... birleştirme.
- Tromino bulmacası (böl ve yönet ile alan döşeme)
  - $2^n \times 2^n$ boyutlu, bir gözü dolu panoyu L biçimli üçlü karolarla döşeme.
- Quicksort (hızlı sıralama)
  - Bölmenin konuma göre değil değere göre (pivot ile) yapılması, partition işlemi.
  - Hoare partition: ilk eleman pivot, iki uçtan tarayan `i` ve `j` indisleri.
  - Son eleman pivot olan alternatif partition (Lomuto tarzı) ve kodu.
  - Pivot seçimi, karmaşıklık, iki pivotlu üç bölümleme, küçük parçalarda insertion sort'a geçme, kararlılık.

## Hocanın Özellikle Vurguladığı Kısımlar

- Heap'e ekleme her zaman ilk boş göze yapılır, çünkü ağaç tam ikili ağaç (complete binary tree) olarak kalmalıdır. Yeni eleman başka bir yere konursa yapı artık heap değildir.
- Kruskal'da kenarların küçükten büyüğe işlenmesi doğruluğu garanti etmek içindir. Karmaşıklık, bellek ve kodlama kolaylığıyla ilgisi yoktur.
- Kenar ağırlıkları ayrık (birbirinden farklı) ise Kruskal her zaman aynı sırayla kenar seçer, bu yüzden MST tektir.
- Huffman ağacında iç düğümler sembol tutamaz. Semboller yalnız yapraklardadır ve yaprak sayısı sembol sayısına eşittir.
- Dizide silme işleminde kalan elemanların kaydırılması gerekir; bu adım unutulursa karmaşıklık yanlış hesaplanır.
- Özyineleme ile böl ve yönet aynı şey değildir. Fibonacci özyinelemeli yazılabilir ama alt problemler birbirine bağlı olduğu için böl ve yönet değildir; bu durumda azalt ve yönet (decrease and conquer) ya da dinamik programlama söz konusudur.
- Mergesort'un zayıf noktası dizinin boyutu kadar ek bir diziye ihtiyaç duymasıdır.
- En iyi sıralama algoritması diye tek bir algoritma yoktur. Problem ve çalışılan ortam için zaman, kararlılık ve bellek birlikte düşünülür.
- Quicksort'ta en önemli nokta pivot seçimidir. Kötü pivot seçimi en kötü durumda $O(n^2)$'ye götürür; rastgele pivot seçmek bunu önlemenin iyi bir yoludur.
- Quicksort yerinde çalışır ama kararlı değildir: sürekli yer değiştirme (swap) yapıldığı için eşit değerlerin sırası korunmaz.

## Kısa Tekrar Notları

- Min-heap'e 8 eklenince karşılaştırılan sayılar: 15, 13, 9, 1. Kökü silince karşılaştırmaya girenler: 17, 9, 2, 5, 3, 4.
- Ayrık ağırlıklı grafta Kruskal: MST en küçük kenarı mutlaka içerir; en büyük kenarı içerebilir; MST tektir; tüm kenarlara aynı sabit eklenirse MST değişmez; yalnız bir düğümün kenarları artırılırsa MST değişebilir.
- Prim'i $O(E \log V)$ yapan yapı öncelikli kuyruktur.
- Huffman tablosunda (A=00, E=10, T=11, P=0111, B=01100, R=01101) S'nin kodu yalnız 010 olabilir.
- En küçük elemanı silme (en kötü durum): sıralı dizi $O(n)$, sırasız dizi $O(n)$, sıralı tek bağlı liste $O(1)$, sırasız bağlı liste $O(n)$, ikili min-heap $O(\log n)$.
- Böl ve yönet: yığına ya da kuyruğa ekleme ve Fibonacci uygun değildir; diziyi sıralama (mergesort) uygundur.
- Top-down mergesort: önce sol yarı tamamen sıralanır, sonra sağ yarı, en son ikisi birleştirilir. $O(n \log n)$ zaman, $O(n)$ ek bellek; toplam yaklaşık $6n \log n$ dizi erişimi.
- Bottom-up mergesort: alt dizi boyutu `s` 1, 2, 4, 8, ... diye ikiye katlanır; her turda `Merge(A, i, i+s-1, min(i+s+s-1, n-1))` çağrılır.
- Tromino: panoyu dörde böl, dolu gözün olmadığı üç çeyreğin merkeze bakan gözlerine bir L karo koy, her çeyrekte aynısını özyinelemeli yap.
- Quicksort: pivotu nihai yerine taşı, solunda küçükler, sağında büyükler kalsın; sonra sol ve sağ parçayı özyinelemeli sırala.
- Hoare partition: `i` soldan pivottan büyük, `j` sağdan pivottan küçük eleman arar; ikisi bulununca swap; `i` ve `j` kesişince pivot `j` gözüne konur.
- Quicksort ortalama $O(n \log n)$, en kötü $O(n^2)$; yerinde, kararsız.
- İyileştirmeler: iki pivot ile üç bölüm, belli bir boyuttan küçük parçalarda insertion sort.

## Detaylı Açıklamalar

- **Heap soruları (ekrandan, 00:10:00).** Soruda verilen min-heap düzey düzey 1; 9, 2; 13, 10, 5, 3; 15, 14, 11, 21, 7, 6, 4, 17 elemanlarından oluşur (17'nin konumu ekranda silinmiş, anlatımdan kuruldu). 8 eklenirken ilk boş göz 15'in sol çocuğudur. 8 sırasıyla 15, 13 ve 9 ile yer değiştirir, sonra 1 ile karşılaştırılır ve durur. Kök silinince son eleman 17 köke taşınır; 17 çocukları 9 ve 2 ile karşılaştırılır, 2 yukarı çıkar; sonra 5 ve 3 ile karşılaştırılır, 3 yukarı çıkar; en son tek çocuk 4 ile karşılaştırılır, 4 yukarı çıkar.
- **Kruskal ve MST soruları (ekrandan, 00:15:00).** En büyük ağırlıklı kenar, bir düğüme giden tek kenar ise MST'ye girmek zorundadır. Hocanın örneğinde 1, 2 ve 5 ağırlıklı kenarlar bir üçgen oluşturur, 15 ağırlıklı kenar dördüncü düğüme giden tek kenardır. 5 çevrim oluşturduğu için atlanır ama 15 seçilmek zorundadır. Aynı örnekte 1 ve 2 ağırlıklı kenarların ortak düğümünün kenarları 10 artırılınca (11 ve 12) Kruskal önce 5'i, sonra 11'i, sonra 15'i seçer; MST değişmiştir. Bütün kenarlara 10 eklenince sıralama değişmediği için MST aynı kalır. Doğru seçenekler 1, 3 ve 5'tir.
- **Prim sorusu (ekrandan, 00:35:00).** s düğümünün komşu kenarları 70, 60 ve 130'dur. Öncelikli kuyruktan sırasıyla 60, 70, 20, 10, 30, 100, 120 seçilir. Aradaki 40, 50, 80 ve 90 çevrim oluşturduğu için atlanır. En sık hata 60 yerine 70 ile başlamaktır.
- **Huffman sorusu (ekrandan, 00:30:00).** A=00, E=10 ve T=11 yaprak olduğu için altlarına düğüm gelemez; S 01 ile başlamalıdır. 011 dalının altı P (0111), B (01100) ve R (01101) ile doludur. Geriye tek boş yaprak 010 kalır. Ağaçta 7 sembol vardır ve 7 yaprak oluşur; S'yi daha derine koymak boş yapraklar bırakır, iç düğüme koymak ise Huffman kurallarına aykırıdır.
- **Top-down mergesort analizi (ekrandan, 00:50:00 ve 00:55:00).** `MergeSort(A, 0, 15)` önce `MergeSort(A, 0, 7)`, o da `MergeSort(A, 0, 3)` ve `MergeSort(A, 0, 1)` çağırır; tek elemana inince `Merge(A, 0, 0, 1)` yapılır. Sol yarının bütün birleştirmeleri bitince sağ yarıya geçilir ve en son `Merge(A, 0, 7, 15)` çağrılır. Dizi $\log n$ seviyeye bölünür; her seviyede toplam $n$ eleman işlenir. Slayttaki ayrıntılı sayım: her merge'de $2N$ kopya, $2N$ geri taşıma, $2N$ karşılaştırma, toplam $6N \log N$ dizi erişimi.
- **Mergesort kodu (ekrandan, 01:05:00).**

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

  - Ek dizinin boyutu derste kolaylık için elle 5 yazıldı. Kod derste yazıldığı haliyle `gcc -Wall` ile derlendi ve çalıştırıldı; çıktı 2, 7, 32, 45, 67 oldu.
- **Bottom-up mergesort (ekrandan, 01:20:00 ve 01:25:00).** Akış şemasında dış döngü `s ← 1`'den başlar, `s ← s+s` ile ilerler, `n-1`'e kadar sürer; iç döngü `i ← 0`'dan başlar, `i ← i+s+s` ile ilerler, `n-s-1`'e kadar sürer ve `Merge(A, i, i+s-1, min(i+s+s-1, n-1))` çağrılır. "MERGESORTEXAMPLE" örneğinde $s=1$ sonrası EM GR ES OR ET AX MP EL, $s=2$ sonrası EGMR EORS AETX ELMP, $s=4$ sonrası EEGMORRS AEELMPTX, $s=8$ sonrası AEEEEGLMMOPRRSTX elde edilir. Eleman sayısı ikinin kuvveti değilse sondaki parça eksik kalır ve öyle birleşir. Slayta göre karşılaştırma sayısı $\frac{1}{2} N \lg N$'den başlar, dizi erişimi en çok $6 N \lg N$'dir.
- **Tromino bulmacası (ekrandan, 01:35:00).** 8×8 panoda tek bir göz doludur. Pano iki eksende ortadan bölünür. Dolu gözün olmadığı üç çeyreğin merkeze komşu gözlerine bir L karo yerleştirilir. Böylece her çeyrekte tam bir dolu göz olur ve her çeyrek aynı yöntemle çözülür. 2×2'lik parçaya inildiğinde bir göz dolu olduğu için kalan üç göze tek bir L karo oturur. Bölme yönetmenin kendisidir; ayrıca bir birleştirme adımı yoktur.
- **Quicksort'un fikri (ekrandan, 01:45:00).** Partition sonunda `a[j]` nihai yerindedir; `a[lo..j-1]` içinde `a[j]`'den büyük eleman, `a[j+1..hi]` içinde `a[j]`'den küçük eleman yoktur. Derste 4, 10, 8, 7, 6, 5, 3, 12, 14, 2 dizisinde ortadaki eleman (6) pivot seçildi: solda 4, 5, 3, 2, sağda 10, 8, 7, 12, 14 kaldı ve parçalar aynı biçimde sıralandı. Quicksort 1959'da Tony Hoare tarafından tasarlanmış, 1961'de yayımlanmıştır.
- **Hoare partition (ekrandan, 02:05:00 ve 02:10:00).** `p ← A[l]`, `i ← l`, `j ← r+1`; `repeat i ← i+1 until A[i] ≥ p`, `repeat j ← j−1 until A[j] ≤ p`, `swap(A[i], A[j])`, `until i ≥ j`; son yer değiştirme geri alınır, pivot `A[j]` ile yer değiştirir, `j` döndürülür. 5, 3, 1, 9, 8, 2, 4, 7 dizisinde 9 ile 4, sonra 8 ile 2 yer değiştirir; `i` ve `j` kesişince pivot 5 ile 2 yer değiştirir ve dizi 2, 3, 1, 4, 5, 8, 9, 7 olur. Hoca sözde kodda `i`'nin dizinin sonunu aşmaması için bir sınır kontrolünün eksik olduğunu belirtti.
- **Quicksort C kodu (ekrandan, 02:20:00 ve 02:45:00).** İlk eleman pivot olan `partition` ile 8, 1, 6, 4, 0, 3, 9, 5 dizisi ilk adımda 5, 1, 6, 4, 0, 3, 8, 9 olur. Son eleman pivot olan `partitionR` ile ilk adımda 3, 1, 0, 4, 5, 8, 9, 6 elde edilir. İki kod da derste gösterildiği haliyle derlendi ve ara adımlar slaytlardaki satırlarla aynı çıktı.
- **Son eleman pivot olan partition (ekrandan, 02:35:00).** `v = A[r]`, `i = p-1`; `j` için `p`'den `r-1`'e kadar `A[j] <= v` ise `i` bir artırılır ve `A[i]` ile `A[j]` yer değiştirir; en son `A[i+1]` ile `A[r]` yer değiştirir ve `i+1` döndürülür. `p..i` aralığı pivottan küçükleri, `i+1..j-1` aralığı pivottan büyükleri tutar; `j`'den sonrası henüz taranmamıştır.
- **İyileştirmeler.** İki pivot seçilip dizi üç parçaya bölünebilir (P1'den küçükler, P1 ile P2 arasındakiler, P2'den büyükler). Hocaya göre en verimli quicksort uygulamaları her parçada iki rastgele pivot kullanır. Üç pivotla dört parçaya bölmek ise ikiye bölmeyi iki kez yapmakla aynıdır ve fazladan iş getirir. Büyük dizilerde belli bir derinlikten sonra küçük parçaları insertion sort ile bitirmek gereksiz özyinelemeli çağrıları azaltır.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
