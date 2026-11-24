# Ders 9 Çalışma Özeti

## Genel Konular

- Θ notasyonu örneğinin düzeltilmesi: $2n+5 \in \Theta(n)$
  - Önceki haftalardaki bir örnekte sabitler hatalı verildiği için örnek baştan çözüldü.
  - $\Theta(n)$ için iki koşul birlikte sağlanmalıdır: $c_2 n \le f(n) \le c_1 n$, ortak bir $n_0$ noktasından sonra her $n$ için (ekrandan, 00:05:00).
  - Alt sınır: $n_0 = 1$, $c_2 = 1$ seçilince $2n+5 \ge n$ her zaman sağlanır (n = 2 için 9 ≥ 2, n = 3 için 11 ≥ 3).
  - Üst sınır: $n_0 = 1$ için $2n+5 = 7$ olduğundan $c_1 \ge 7$ olmalıdır; $c_1 = 7$ ile $2n+5 \le 7n$ her $n \ge 1$ için sağlanır (n = 1: 7 ≤ 7, n = 2: 9 ≤ 14).
- Böl ve yönet sıralamalarının neden hızlı olduğu
  - Her elemanı bütün elemanlarla karşılaştıran selection, bubble ve insertion sort en kötü durumda $n^2$ mertebesindedir.
  - Böl ve yönet yaklaşımı diziyi parçalara ayırarak her seferinde bütün elemanlara bakma zorunluluğunu ortadan kaldırır. Bu ailenin iki önemli temsilcisi merge sort ve quick sort'tur.
  - Saniyede $10^8$ karşılaştırma yapan bir ev bilgisayarı için tahtadaki tablo (ekrandan, 00:10:00):

    | Algoritma | n = bin | n = milyon | n = milyar | Mertebe |
    |---|---|---|---|---|
    | Insertion | anlık | 2.8 saat | 317 yıl | $n^2$ |
    | Merge | anlık | 1 saniye | 18 dakika | $n \log_2 n$ |
    | Quick | anlık | 0.6 saniye | 12 dakika | $n \log_2 n$ |

  - Quick sort'un en kötü durumu yine $n^2$'dir.
- Quick sort'un mantığı ve bölümleme (partition)
  - Bir pivot seçilir; pivottan küçükler sola, büyük ya da eşitler sağa yerleştirilir: $A[0..s-1] < A[s]$, $A[s+1..n-1] \ge A[s]$ (ekrandan, 00:30:00).
  - Bölümleme bitince pivot, dizi sıralı olsaydı bulunacağı son konumuna yerleşir ("After partition A[s] is in its final position").
  - Sonra sol ve sağ parça birbirinden bağımsız olarak özyinelemeli sıralanır.
- Bölümleme örneği: 5 3 1 9 8 2 4 7
  - Pivot ilk eleman (5). Sol işaretçi (l) baştan ileri, sağ işaretçi (r) sondan geri gider; l pivottan büyük, r pivottan küçük bir eleman bulunca ikisi yer değiştirir.
  - 9 ile 4, sonra 8 ile 2 yer değiştirir; l, r'yi geçince işlem biter ve pivot, r'nin gösterdiği son küçük elemanla (2) yer değiştirir: 2 3 1 4 [5] 8 9 7, $s = 4$ (ekrandan, 00:35:00).
  - Sol parça (l = 0, r = 3) pivot 2 ile 1 2 3 4 olur, $s = 1$; sağ parça (l = 5, r = 7) pivot 8 ile 7 8 9 olur, $s = 6$. Sonuç 1 2 3 4 5 7 8 9 (ekrandan, 00:50:00).
- Quick sort sözde kodu (ekrandan, 01:05:00)
  - `QuickSort(A[l..r])`, başta $l = 0$, $r = n-1$.
  - `if (l < r)` ise `s <- partition(A[l..r])`, ardından `QuickSort(A[l..s-1])` ve `QuickSort(A[s+1..r])`.
  - Durma şartı $l \ge r$'dir: $l = r$ tek eleman, $l > r$ boş aralık demektir.
  - Çağrılar önce bütün sol tarafı derinlemesine bitirir, sonra sağ tarafa geçer.
- Quick sort karmaşıklık analizi
  - Bölümleme her zaman bütün elemanlara bakar: $\Theta(n)$.
  - En iyi durum (pivot her adımda ortada): $T(n) = 2T(n/2) + cn$, sonuç $\Theta(n \log n)$ (merge sort ile aynı denklem).
  - En kötü durum (dizi zaten sıralı, ilk eleman pivot): $T(n) = T(n-1) + cn$, toplam $\frac{n(n+1)}{2} \in \Theta(n^2)$ (ekrandan, 01:20:00).
  - Ortalama durum (pivotun her konumda olma olasılığı $1/n$): yaklaşık $1.39\, n \log_2 n$, yani $n \log n$ mertebesi.
- Pivot seçimi
  - Ortadaki elemanı pivot seçmek, diziyi başta bir kez karıştırmak (shuffle, $O(n)$) ya da rastgele seçilen üç elemanın medyanını almak.
  - Seçilen pivot önce dizinin başına taşınır, bölümleme öyle yapılır.
- Dijkstra'nın üç yollu bölümlemesi (3-way partitioning)
  - Çok sayıda tekrar eden anahtar varken dizi üç bölgeye ayrılır: pivottan küçükler, pivota eşitler, pivottan büyükler (ekrandan, 01:50:00).
  - İşaretçiler: `lt = low`, `i = low+1`, `gt = high`, pivot `a[low]`; `a[i] < pivot` ise `a[lt]` ile `a[i]` değişir, `i++`, `lt++`; `a[i] > pivot` ise `a[i]` ile `a[gt]` değişir, `gt--`; eşitse yalnız `i++` (ekrandan, 02:05:00).
  - Örnek: 4 2 4 6 4 8 7 3 4 1 5 → 2 1 3 4 4 4 4 7 8 5 6 (ekrandan, 02:00:00).
  - Özyineleme yalnız eşitler bloğunun solu ve sağı için çağrılır; eşitler bloğu bir daha işlenmez.
- Küçük parçalar için insertion sort
  - Parça boyu belli bir eşiğin (yaklaşık 10-15 eleman) altına inince özyinelemeli çağrı yükünden kaçınmak için insertion sort kullanılır (ekrandan, 02:10:00).

## Hocanın Özellikle Vurguladığı Kısımlar

- Θ ispatında asıl iş uygun $c_1$, $c_2$ ve ortak $n_0$'ı bulmaktır
  - Önemli olan, o noktadan sonra eşitsizliğin artık hiç bozulmadığı bir başlangıç noktası bulmaktır.
- Bölümlemenin karmaşıklığı her durumda $\Theta(n)$'dir
  - Dizi tersten sıralı olsa bile yer değiştirme sayısı en fazla $n$ mertebesindedir; iç içe iki döngü olmadığı için $n^2$'ye çıkmaz. Bütün elemanlara bakmak zorunlu olduğu için $\log n$'e de inmez.
- Sıralı dizi quick sort için en kötü durumdur
  - Pivot hep en küçük eleman olur, dizi ikiye bölünemez, her adımda tek bir eleman yerleşir.
- En kötü duruma düşme olasılığını azaltmak neden önemlidir
  - Sistemler genelde ortalama duruma göre tasarlanır. Hoca deprem anında telefon şebekesinin kilitlenmesini örnek verdi: altyapı ortalama yüke göre kurulduğu için herkes aynı anda arayınca sistem yükü kaldıramaz. Zamanın kritik olduğu bir uygulamada en kötü duruma düşmek ciddi gecikme demektir.
- Bölümleme kodunu bir kaynağa bakmadan kendiniz yazmaya çalışın
  - Bölümlemede yapılacak iş: ilk elemandan küçükleri bir tarafa, büyükleri diğer tarafa koymak, son küçük elemanla pivotu yer değiştirmek ve pivotun adresini döndürmek.
- Pivot ortada değil başta tutulmalıdır
  - Aksi halde bölümleme sırasında pivotu sürekli kaydırmak gerekir; bu sık yapılan bir hatadır.

## Kısa Tekrar Notları

- $2n+5 \in \Theta(n)$: $c_2 = 1$, $c_1 = 7$, $n_0 = 1$ ile $n \le 2n+5 \le 7n$.
- Quick sort: pivot seç, böl (partition), sol ve sağ parçayı özyinelemeli sırala.
- Bölümleme sonrası pivot son konumundadır.
- Sol parça $A[l..s-1]$, sağ parça $A[s+1..r]$; durma şartı $l \ge r$.
- Bölümleme: $\Theta(n)$.
- En iyi durum: $T(n) = 2T(n/2) + cn \Rightarrow \Theta(n \log n)$.
- En kötü durum (sıralı dizi): $T(n) = T(n-1) + cn \Rightarrow \Theta(n^2)$.
- Ortalama durum: yaklaşık $1.39\, n \log_2 n$.
- Pivot seçimi: orta eleman, başta karıştırma, rastgele üç elemanın medyanı; pivot dizinin başına taşınır.
- Üç yollu bölümleme: küçükler / eşitler / büyükler; eşit elemanda yalnız `i++`, eşitler bloğu yeniden sıralanmaz.
- Küçük parçalarda (yaklaşık 10-15 eleman) insertion sort: neredeyse sıralı dizide erken durur, selection sort ise her adımda en küçüğü aramak zorundadır.

## Detaylı Açıklamalar

- **Θ örneği.** $f(n) = 2n+5$ için $\Theta(n)$ göstermek, hem Ω hem O koşulunu aynı $n_0$ ile sağlamak demektir. Alt sınırda $2n$ zaten $n$'den büyük olduğu için $c_2 = 1$, $n_0 = 1$ yeterlidir. Üst sınırda $n_0 = 1$ alındığında sol taraf 7 olduğundan $c_1$ en az 7 olmalıdır. $c_1 = 7$ ile $n = 1$'de $7 \le 7$, $n = 2$'de $9 \le 14$, $n = 8$'de $21 \le 56$ olur ve fark büyüyerek sürer. Böylece $n \le 2n+5 \le 7n$ elde edilir.
- **Bölümlemenin işleyişi.** 5 3 1 9 8 2 4 7 dizisinde pivot 5'tir. Sol işaretçi 3 ve 1'i geçer, 9'da durur. Sağ işaretçi 7'yi geçer, 4'te durur. 9 ile 4 yer değiştirir ve iki işaretçi birer adım ilerler. Sol işaretçi 8'de, sağ işaretçi 2'de durur; bunlar da yer değiştirir. Şimdi sol işaretçi sağdakini geçmiştir: işlem biter. Son küçük eleman artık sol işaretçinin bir gerisindedir (sağ işaretçinin gösterdiği yer). Pivot bu elemanla (2) yer değiştirir ve dizi 2 3 1 4 5 8 9 7 olur. 5 dördüncü gözdedir ve artık hiç yer değiştirmeyecektir.
- **Özyineleme ağacı.** Sol parça 2 3 1 4'te pivot 2'dir; 3 ile 1 yer değiştirir, pivot 1 ile yer değiştirince 1 2 3 4 olur ($s = 1$). Onun solu (l = 0, r = 0) tek elemandır, sağı (l = 2, r = 3) pivot 3 ile değişmeden kalır ($s = 2$); oradan çıkan (l = 2, r = 1) boş aralık ve (l = 3, r = 3) tek eleman çağrıları hemen döner. Sağ parça 8 9 7'de 9 ile 7 yer değiştirir, pivot 7 ile değişir ve 7 8 9 olur ($s = 6$). Çağrı sırası tahtada 1'den 9'a numaralanmıştır: (0,7), (0,3), (0,0), (2,3), (2,1), (3,3), (5,7), (5,5), (7,7) (ekrandan, 00:50:00; python ile doğrulandı).
- **Karmaşıklık.** En iyi durumda iki yarım boyutlu çağrı ve doğrusal bölümleme vardır; geriye doğru yerine koyma ile merge sort'taki gibi $n \log n$ çıkar. En kötü durumda (sıralı dizi, pivot ilk eleman) her bölümleme yalnız pivotu yerleştirir ve geriye $n-1$ elemanlık bir parça kalır; $n + (n-1) + \dots + 1 = \frac{n(n+1)}{2}$ olur. Ortalama durumda pivotun $k$. konumda olma olasılığı $1/n$'dir; $T(k-1)$ sol, $T(n-k)$ sağ parçanın süresidir ve bunların ortalaması alınır. Çözümün yaklaşık $1.39\, n \log_2 n$ çıktığı belirtildi; çözüm derste yapılmadı. Bu yüzden quick sort en çok kullanılan sıralama algoritmalarındandır.
- **Pivot seçimi.** Sıralı girdi en kötü duruma yol açtığı için ortadaki eleman pivot seçilebilir, dizi başta bir kez karıştırılabilir ya da rastgele seçilen üç elemanın ortancası alınabilir. Bu son yöntem, kötü bir pivot seçme olasılığını iyice düşürür. Hangi eleman seçilirse seçilsin önce dizinin başına taşınır.
- **Üç yollu bölümleme.** Doğum tarihi ya da şehir gibi çok tekrar eden anahtarlar sıralanırken pivota eşit elemanların hepsi ortada bir blokta toplanır. Eşit elemanla karşılaşınca yer değiştirme yapılmadan yalnız `i` ilerletilir. Sonra quick sort yalnız bloğun solu ve sağı için çağrılır. Örneğin tahtadaki 2 1 3 4 | 5 5 5 5 | 7 18 9 15 11 dizisinde ortadaki 5'ler bir daha işlenmez (ekrandan, 02:10:00).
- **Küçük parçalar.** Parça boyu bir eşiğin altına inince özyinelemeli çağrının fonksiyon çağırma yükü kazancı aşar. Bu durumda insertion sort kullanılır. Insertion sort, 2 3 5 sıralı kısmına 4 eklenirken yalnız 5 ve 3 ile karşılaştırır ve durur; selection sort ise her adımda kalan bölgenin en küçüğünü bulmak için bütün bölgeyi taramak zorundadır.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
