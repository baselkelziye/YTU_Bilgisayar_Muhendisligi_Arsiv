# Ders 4 Çalışma Özeti

## Genel Konular

- Insertion sort'un en kötü ve en iyi durum analizi
  - En kötü durum, dizinin tersten sıralı olduğu durumdur (örnek: 9 8 7 5). Her yeni eleman dizinin başına kadar taşınır; $i$. eleman için $i$ karşılaştırma yapılır. Toplam karşılaştırma $n^2$ mertebesindedir: $C_{worst} \in O(n^2)$, aynı zamanda $\Theta(n^2)$ (ekrandan, 00:05:00).
  - En iyi durum, dizinin zaten sıralı olduğu durumdur (örnek: 5 7 8 9). Her eleman için tek karşılaştırma yapılır: $\sum_{i=1}^{n-1} 1 = n-1$. Bu yüzden $C_{best} \in \Theta(n)$; $O(n)$ ve $\Omega(n)$ demek de doğrudur (ekrandan, 00:05:00).
- Insertion sort'un ortalama durum analizi
  - İç döngünün koşulu: `j > 0 && tmp < a[j-1]` (ekrandan, 00:10:00).
  - $k$. pozisyondaki eleman $j$. pozisyona yerleşecekse $k-j+1$ karşılaştırma yapılır.
  - $j$, $1$ ile $k$ arasındaki her değeri eşit olasılıkla alırsa iç döngünün ortalama maliyeti $\frac{k+1}{2}$ olur (ekrandan, 00:15:00).
  - Dış döngü $k=2$'den $n$'e kadar döner; toplam ortalama maliyet $\frac{1}{4}n^2 + \frac{3}{4}n - 1$, yani $C_{average} \in O(n^2)$ (ekrandan, 00:20:00).
- O, Θ ve Ω gösterimlerinin bir algoritmanın tamamı için kullanılması
  - Insertion sort'un tamamı için $O(n^2)$ ve $\Omega(n)$ denebilir, $\Theta(n)$ ya da $\Theta(n^2)$ denemez.
  - En büyük elemanı bulma (findMax) her durumda $n$ adım sürdüğü için $\Theta(n)$'dir.
- Karmaşıklık sınıflarının büyüme hızları
  - $\lg n$, $n$, $n \lg n$, $n^2$, $2^n$ ve $n!$ için $n=10$ ve $n=10^8$ değerlerinde çalışma süreleri tablosu (ekrandan, 00:35:00).
  - Üstel ve faktöriyel karmaşıklıklı algoritmalar küçük $n$ için bile pratikte sonuç vermez.

## Hocanın Özellikle Vurguladığı Kısımlar

- "Best case Ω ile, average case Θ ile, worst case O ile gösterilir" kalıbı doğru değildir.
  - Bu üç gösterim üç duruma sabit olarak bağlı değildir. Hangi gösterimin kullanılacağı, sınırın gerçekten sağlanıp sağlanmadığına bakılarak seçilir.
- Θ yalnız karmaşıklık "ne alta iniyor ne üste çıkıyorsa" kullanılır.
  - Insertion sort'ta en iyi durum $n$, en kötü durum $n^2$ olduğu için algoritmanın tamamına $\Theta(n)$ denemez.
  - Sıralı aramada (sequential search) aranan eleman dizide yoksa dizinin sonuna kadar bakmak zorunludur; bu yüzden en kötü durumuna $\Theta(n)$ denebilir.
  - Klasik matris çarpımı her durumda $n^3$ işlem yapar; $\Theta(n^3)$ denebilir.
- Emin değilseniz Big O kullanın.
  - Algoritmanın tamamının karmaşıklığını anlatmanın en anlaşılır yolu, en kötü durumu kapsayan Big O gösterimidir.
- Karmaşıklığa bakarken ifadeye ya da `if` sayısına değil, döngünün (`while`) kaç kez döneceğine bakın.
  - Önce best, worst ve average durumlarını algoritmadan çıkarın, gösterimi sonra seçin.
- $n \lg n$ ile $n^2$ arasındaki fark, $n$ büyüdükçe çok belirginleşir.
  - $n = 10^8$ iken $n \lg n$ bir algoritma yaklaşık 2,66 saniye, $n^2$ bir algoritma yaklaşık 115,7 gün sürer.

## Kısa Tekrar Notları

- Insertion sort: $C_{worst} \in \Theta(n^2)$, $C_{best} \in \Theta(n)$, $C_{average} \in \Theta(n^2)$.
- Insertion sort'un tamamı için: $O(n^2)$ ve $\Omega(n)$. $\Theta$ ile tek bir ifade yoktur.
- İç döngüde $k$. elemanı $j$. pozisyona taşımak $k-j+1$ karşılaştırmadır; ortalaması $\frac{k+1}{2}$.
- Ortalama toplam: $\sum_{k=2}^{n} \frac{k+1}{2} = \frac{n^2}{4} + \frac{3n}{4} - 1$.
- findMax her durumda $n$: $\Theta(n)$.
- Klasik matris çarpımı: $\Theta(n^3)$.
- Sıralı aramanın en kötü durumu: $\Theta(n)$.
- Büyüme sırası: $\lg n < n < n \lg n < n^2 < 2^n < n!$.
- $n=100$ için $2^n$ adımlı bir algoritma yaklaşık $4 \times 10^{13}$ yıl, $n=20$ için $n!$ adımlı bir algoritma yaklaşık 77,1 yıl sürer (adım başına 1 ns).

## Detaylı Açıklamalar

- **En kötü durum.** Insertion sort her adımda yeni elemanı soldaki sıralı kısma yerleştirir. Dizi tersten sıralıysa (9 8 7 5) her yeni eleman sıralı kısmın en küçüğünden de küçüktür ve en başa kadar gitmek zorundadır. $i$. eleman için $i$ karşılaştırma yapılır, toplam $\sum_{i=1}^{n-1} i$ karşılaştırma olur. Bu toplam $n^2$ mertebesindedir. Tersten sıralı dizide bu sayı her zaman aynı olduğu için en kötü durum için hem $O(n^2)$ hem $\Theta(n^2)$ yazılabilir.
  - Ders sonrası not: Tahtada $\sum_{i=1}^{n-1} i = \frac{n(n+1)}{2}$ yazıldı (ekrandan, 00:05:00); doğrusu $\frac{n(n-1)}{2}$'dir. Mertebe değişmez, sonuç yine $n^2$'dir.
- **En iyi durum.** Dizi zaten sıralıysa (5 7 8 9) her eleman yalnız solundaki komşusuyla karşılaştırılır, yer değiştirmez ve iç döngü hemen biter. $n-1$ eleman için birer karşılaştırma yapılır: $n-1$. Bir öğrencinin belirttiği gibi en iyi durumda bile dizinin bir kez baştan sona gezilmesi gerekir; bu yüzden en iyi durum $n$'in altına inemez ve $\Theta(n)$ rahatlıkla söylenebilir.
- **Ortalama durum: iç döngü.** Dizi ne küçükten büyüğe ne büyükten küçüğe sıralıdır, elemanlar rastgele yerlerdedir. Hesap iç döngünün koşulu (`j > 0 && tmp < a[j-1]`) üzerinden yapılır. Dizi indisleri hesap kolaylığı için 1'den başlatıldı. $k$. pozisyondaki bir eleman sonunda $j$. pozisyona yerleşiyorsa $k-j+1$ karşılaştırma yapılır. Örnek: 3 5 7 4 dizisinde 4 ($k=4$) önce 7 ile, sonra 5 ile, sonra 3 ile karşılaştırılır ve $j=2$ pozisyonuna yerleşir: $4-2+1 = 3$ karşılaştırma. $j$'nin $1, 2, \dots, k$ değerlerinden her birini eşit olasılıkla aldığı kabul edilirse:
  - $\frac{1}{k}\sum_{j=1}^{k}(k-j+1) = \frac{1}{k}\left(k^2 - \frac{k(k+1)}{2} + k\right) = \frac{k+1}{2}$ (ekrandan, 00:15:00).
  - Burada $\sum_{j=1}^{k} k = k^2$, $\sum_{j=1}^{k} j = \frac{k(k+1)}{2}$ ve $\sum_{j=1}^{k} 1 = k$ kullanıldı.
- **Ortalama durum: dış döngü.** $\frac{k+1}{2}$ yalnız bir elemanı yerine yerleştirmenin ortalama maliyetidir. Dış döngü ikinci elemandan $n$. elemana kadar bu işi tekrarlar:
  - $\sum_{k=2}^{n}\frac{k+1}{2} = \sum_{k=1}^{n-1}\frac{k+2}{2} = \frac{1}{4}n^2 + \frac{3}{4}n - 1$.
  - Sonuç: $C_{average} \in O(n^2)$; tahtada $\Theta(n^2)$ da yazıldı (ekrandan, 00:20:00).
  - Ders sonrası not: Tahtadaki ara adımda toplam $\frac{1}{2}\cdot\frac{(n+1)(n+2)}{2}$ olarak yazıldı ve son ifade $\frac{1}{4}n^2 + \frac{3}{n} - 1$ biçiminde görünüyor (ekrandan, 00:20:00). Doğrusu $\sum_{k=1}^{n-1}\frac{k+2}{2} = \frac{1}{2}\left(\frac{(n-1)n}{2} + 2(n-1)\right) = \frac{n^2}{4} + \frac{3n}{4} - 1$'dir (python ile doğrulandı). Mertebe sonucu ($n^2$) değişmez.
- **Gösterim seçimi.** Insertion sort'un tamamını tek ifadeyle anlatmak için $O(n^2)$ en anlaşılır seçimdir: $n^2$ hem en kötü ve ortalama durumu hem de en iyi durumdaki $n$'i kapsar. $\Omega(n)$ demek de doğrudur; algoritmanın en iyi ihtimalle $n$ adımda biteceğini, alt sınırın $n$ olduğunu söyler. $\Theta(n)$ ya da $\Theta(n^2)$ denemez, çünkü karmaşıklık her zaman aynı mertebede kalmaz. Tersine, 1'den $n$'e kadar sayıları toplayan bir döngü ya da dizinin en büyük elemanını bulan algoritma her durumda tam $n$ adım yapar; bunlar için $\Theta(n)$ çok doğrudur.
- **Büyüme hızları tablosu.** Adım başına 1 nanosaniye varsayımıyla (ekrandan, 00:35:00):

  | $n$ | $\lg n$ | $n$ | $n \lg n$ | $n^2$ | $2^n$ | $n!$ |
  |---|---|---|---|---|---|---|
  | 10 | 0,003 µs | 0,01 µs | 0,033 µs | 0,1 µs | 1 µs | 3,66 ms |
  | $10^8$ | 0,027 µs | 0,1 s | 2,66 s | 115,7 gün | — | — |

  - Ayrıca: $n = 100$ için $2^n$ → $4 \times 10^{13}$ yıl; $n = 20$ için $n!$ → 77,1 yıl.
  - $\lg n$ için $n=10$ ile $n=10^8$ arasında pratikte fark yoktur; logaritmik algoritma iyi bir algoritmadır.
  - $n \lg n$ karmaşıklıklı algoritmalar (quicksort, mergesort, heapsort) $10^8$ eleman için saniyeler mertebesinde, selection sort gibi $n^2$ karmaşıklıklı bir algoritma ise aylar mertebesinde sonuç verir.
  - Ders sonrası not: Hoca $n \lg n$ satırını sözlü olarak 1,66 saniye diye okudu; tahtada 2,66 saniye yazıyor ve doğru değer de yaklaşık 2,66 saniyedir. Tahtadaki $10!$ değeri 3,66 ms; tam hesap $3.628.800$ ns $\approx 3{,}63$ ms'dir. Diğer değerler python ile doğrulandı.
- **Polinomsal olmayan algoritmalar.** $n^2$, $n^4$ gibi karmaşıklıklar polinomsaldır; $2^n$ ve $n!$ polinomsal değildir. Bu tür algoritmalar $n$ küçükken bile pratikte sonuç vermez. Ders boyunca önce polinom zamanda çözülebilen problemler işlenecek, son derslerde bu tür problemler ele alınacaktır.
  - Ders sonrası not: Hoca $2^n$ ve $n!$ karmaşıklıklı algoritmalar için "non-deterministik polinomsal" ve "çözümü olmayan" ifadelerini kullandı. Doğrusu: NP (nondeterministic polynomial), "polinomsal olmayan" anlamına gelmez; çözümü polinom zamanda doğrulanabilen problemlerin sınıfıdır. Üstel zamanlı bir algoritmanın varlığı problemin çözümsüz olduğunu göstermez, yalnız pratikte büyük girdilerde sonucun alınamayacağını gösterir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
