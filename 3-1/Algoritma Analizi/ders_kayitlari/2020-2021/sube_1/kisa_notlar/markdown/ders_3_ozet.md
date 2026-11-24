# Ders 3 Çalışma Özeti

## Genel Konular

- Asimptotik analiz ve karmaşıklık ifadelerinin sadeleştirilmesi
  - Bir algoritmanın karmaşıklığı, bilgisayar ve derleyici gibi değişken etkenlerden bağımsız olarak yalnız girişteki eleman sayısı $n$'e bağlı ifade edilir. $n \to \infty$ iken davranışa bakmaya asimptotik analiz denir.
  - Örnek: $2n^2 + 5n + 9$ ile $2n^2 + 4n + 12$ karmaşıklıklı iki kod. $n = 10$ için ilki $200 + 50 + 9 = 259$, ikincisi $200 + 40 + 12 = 252$ adım yapar (ekrandan, 00:05:00). Küçük $n$'de ikinci biraz önde görünse de $n$ büyüdükçe sabitlerin ve katsayıların anlamı kalmaz; ikisi de $n^2$'dir ve eşdeğerdir.
  - Sadeleştirme adımları: (1) sabitler atılır, (2) katsayılar atılır, (3) en yüksek üslü terim bırakılır.
- Sadeleştirmede dikkat edilecek iki durum (ekrandan, 00:10:00)
  - Büyük sabitler: $2n^2 + c \cdot n$ ifadesinde $c$ örneğin $10^7$ gibi çok büyükse $c \cdot n$ terimi pratikte göz ardı edilemez. Atılan sabitlerden kastedilen 3, 5, 1000 gibi makul sabitlerdir.
  - İki değişkenli karmaşıklık: $m \times n$ gibi bir karmaşıklıkta $m$ sabit sayılıp $n$ denemez. $m$, $n$'e yakın olabiliyorsa (ör. $m \times n$ matris) karmaşıklık $n^2$ gibi düşünülmelidir.
- Big-O notasyonu: asimptotik üst sınır (ekrandan, 00:15:00)
  - $f(n) \in O(g(n))$ ancak ve ancak bir $c > 0$ sabiti ve bir $n_0 > 0$ için her $n \ge n_0$ değerinde $0 \le f(n) \le c \cdot g(n)$ sağlanıyorsa.
  - Örnekler: $10n + 30 \in O(n)$ ($n_0 = 1$, $c = 40$); $n^2 + 2n + 1 \in O(n^2)$ ($n_0 = 1$, $c = 4$); $n^2 + n \in O(n^3)$ doğru; $n^2 + n \in O(n)$ yanlış.
- Big-Omega notasyonu: asimptotik alt sınır (ekrandan, 00:35:00)
  - $f(n) \in \Omega(g(n))$ ancak ve ancak bir $c > 0$ ve $n_0 > 0$ için her $n \ge n_0$ değerinde $f(n) \ge c \cdot g(n)$.
  - Örnekler: $5n^2 \in \Omega(n^2)$ ($n_0 = 1$, $c = 1$) ve $5n^2 \in \Omega(n)$ ($n_0 = 1$, $c = 3$).
- Big-Theta notasyonu: sıkı sınır (tight bound)
  - $f(n) \in \Theta(g(n))$ ancak ve ancak $c_1, c_2 > 0$, $c_1 \le c_2$ ve bir $n_0$ için her $n \ge n_0$ değerinde $0 \le c_1 g(n) \le f(n) \le c_2 g(n)$.
  - $f(n) \in O(g(n))$ ve $f(n) \in \Omega(g(n))$ ise $f(n) \in \Theta(g(n))$. Örnek: $2n + 5 \in \Theta(n)$ (ekrandan, 01:05:00).
- Best, worst ve average case
  - Best case en iyi, worst case en kötü durumdur. Average case "rastgele girişte genel olarak ne olur" sorusudur; aritmetik ortalama anlamına gelmez. Ölçmesi zor olduğu için çoğunlukla best ve worst case'e bakılır.
  - Sık kullanılan toplamlar: $\sum_{i=1}^{n} 1 = n$, $\sum_{i=1}^{n} i = \frac{n(n+1)}{2}$; $\sum_{i=1}^{n} i^2$ de sık kullanılır.
- Özyinelemeli olmayan algoritmaların matematiksel analizi
  - En büyük elemanı bulma (findMax): temel işlem döngüdeki karşılaştırmadır, $C(n) = \sum_{i=1}^{n-1} 1 = n - 1$. Best = worst = average olduğundan $\Theta(n)$.
  - Sıralı arama (sequential search): worst case $\Theta(n)$, best case $\Theta(1)$, average case $C_{avg}(n) = p \cdot \frac{n+1}{2} + n(1-p)$, bu yüzden $O(n)$.
  - Insertion sort: algoritma, akış diyagramı ve iz sürme; worst case (ters sıralı dizi) iç döngü $i$ kez çalışır, toplam $n^2$ mertebesindedir.

## Hocanın Özellikle Vurguladığı Kısımlar

- $m \times n$ karmaşıklığında $m$ sabit sayılıp atılamaz
  - Hoca buna özellikle dikkat edilmesini istedi; $m$, $n$ kadar büyük olabiliyorsa karmaşıklık $n^2$ gibi değerlendirilir.
- Big-O'da "en yakın üst sınır" seçilmeli
  - $n^2 + n$'yi $O(n^3)$ ya da $O(n^5)$ ile göstermek yanlış değildir, ama emek verilerek yazılmış $n^2$'lik bir algoritmayı $n^3$ diye göstermek istenmez. Asimptotik üst sınırdan kastedilen olabilecek en düşük üst sınırdır.
- Eşitsizlik $n_0$'dan sonraki her $n$ için sağlanmalı
  - Birkaç $n$ değerinde sağlanması yetmez. Bir kez seçilen $c$ ile $n_0$'dan itibaren eşitsizlik hiç bozulmamalıdır. Tek bir uygun $c$ bulmak yeterlidir; mantıklı bir $c$ seçmek hesabı kısaltır.
- Theta, best = worst = average olduğunda tercih edilmeli
  - findMax için $O(n)$ demek de doğrudur, ama karmaşıklığın her durumda tam $n$ olduğunu bakar bakmaz anlatan gösterim $\Theta(n)$'dir. Hoca bunu "çok önemli" diye vurguladı.
- Insertion sort'un kullanım yeri
  - Yarı sıralı (sıralıyken zamanla kısmen bozulmuş) dizilerde ve az elemanlı dizilerde, quicksort ve merge sort gibi özyinelemeli algoritmaların fonksiyon çağırma yükü olmadığından tercih edilir.

## Kısa Tekrar Notları

- Asimptotik analiz: sabitleri at, katsayıları at, en yüksek üslü terimi bırak.
- Çok büyük sabitlerde ve $m \times n$ türü iki değişkenli karmaşıklıklarda dikkat.
- $O$: üst sınır, $f(n) \le c\,g(n)$; $\Omega$: alt sınır, $f(n) \ge c\,g(n)$; $\Theta$: ikisi birden, $c_1 g(n) \le f(n) \le c_2 g(n)$.
- $n^2 + n \notin O(n)$: $c = 5$ ile $n = 5$'te $30 > 25$ olur ve eşitsizlik bozulur.
- findMax: $C(n) = n - 1$, $\Theta(n)$.
- Sıralı arama: worst $\Theta(n)$, best $\Theta(1)$, average $p\frac{n+1}{2} + n(1-p)$; $p = 1$ için $\frac{n+1}{2}$, $p = 0$ için $n$.
- Insertion sort worst case: ters sıralı dizi, $\sum i \approx \frac{n^2}{2}$, yani $n^2$ mertebesi.

## Detaylı Açıklamalar

- Asimptotik analizin gerekçesi
  - Aynı işi yapan iki kodun karmaşıklıkları $2n^2 + 5n + 9$ ve $2n^2 + 4n + 12$ olsun. $n = 10$ için ilk kod 259, ikinci kod 252 adım yapar ve ikinci "kıl payı" kazanır. $n$ büyüdükçe bu farkın hiçbir anlamı kalmaz, çünkü sonsuza giden bir değere 9 eklemenin ya da $n^2$ yerine $2n^2$ yazmanın bir etkisi yoktur. Bu yüzden ikisi de $n^2$ olarak gösterilir ve karmaşıklıkları eşdeğerdir.
- Big-O tanımının kullanımı (ekrandan, 00:20:00)
  - $f(n) = 10n + 30$ için $g(n) = n$ denenir: $10n + 30 \le c \cdot n$, yani $30 \le (c - 10)n$. $n_0 = 1$ ve $c = 40$ alınırsa $30 \le 30$ sağlanır; $n = 2$ için $30 \le 60$ olur ve $n$ büyüdükçe hep sağlanır. Demek ki $10n + 30 \in O(n)$.
  - $n^2 + 2n + 1$ için $n_0 = 1$, $c = 4$ seçilirse $4 \le 4$ olur; $n^2 + 2n + 1 \in O(n^2)$.
  - $n^2 + n \in O(n)$ mi? $c = 5$, $n_0 = 1$ ile $n = 1$'de $2 \le 5$, $n = 2$'de $6 \le 10$, $n = 3$'te $12 \le 15$, $n = 4$'te $20 \le 20$ sağlanır; ama $n = 5$'te $30 \le 25$ bozulur (ekrandan, 00:30:00). $n_0$'dan sonraki her $n$ için sağlanmadığından $n^2 + n \notin O(n)$.
- Big-Omega örneği
  - $5n^2 \ge c \cdot n^2$: $c = 1$ alınınca $(5 - 1)n^2 \ge 0$, yani $4 \ge 0$ olur; $5n^2 \in \Omega(n^2)$.
  - $5n^2 \ge c \cdot n$: $n_0 = 1$ için $5 \ge c$, $c = 3$ seçilince sağlanır; $5n^2 \in \Omega(n)$. Hoca bunun mantıksız görünebileceğini, ama alt sınırın böyle de kullanılabildiğini söyledi.
- Big-Theta örneği: $f(n) = 2n + 5$
  - Üst sınır: $2n + 5 \le c_1 n$, $(c_1 - 2)n \ge 5$; $n_0 = 1$, $c_1 = 7$ ile sağlanır, $f(n) \in O(n)$.
  - Alt sınır: $2n + 5 \ge c_2 n$, $(2 - c_2)n \ge -5$; $c_2 = 1$ ile her $n \ge 1$ için sağlanır, $f(n) \in \Omega(n)$. İkisi birlikte $f(n) \in \Theta(n)$ verir.
  - Ders sonrası not: Derste alt sınır kısmında eşitsizlik birkaç kez yeniden düzenlendi ve sonunda $c_2 = 4$ önerildi. $2n + 5 \ge 4n$ yalnız $n \le 2$ için doğrudur, $n = 3$'te $11 \ge 12$ bozulur. Doğrusu: $(2 - c_2)n \ge -5$ eşitsizliği her $n$ için $c_2 \le 2$ ile sağlanır; derste ilk seçilen $c_2 = 1$ doğru bir seçimdir.
- findMax analizi (ekrandan, 01:15:00)
  - Algoritma: `max = A[0]`, sonra `for (i = 1; i < n; i++) if (A[i] > max) max = A[i];`, en sonda `return max;`.
  - Temel işlem (basic operation) her turda mutlaka yapılan `A[i] > max` karşılaştırmasıdır; atama yalnız koşul doğruysa yapılır. Karşılaştırma sayısı $C(n) = \sum_{i=1}^{n-1} 1 = n - 1$, yani $O(n)$.
  - En büyük eleman dizinin neresinde olursa olsun bütün diziye bakmak gerekir; best, worst ve average case aynıdır ve karmaşıklık $\Theta(n)$ olarak gösterilir.
- Sıralı arama analizi (ekrandan, 01:20:00 ve 01:25:00)
  - `while ((i < n) && (a[i] != x)) i++;` döngüsü eleman bulunana ya da dizi bitene kadar ilerler.
  - Worst case: dizinin sonuna kadar gidilir, $\Theta(n)$. Best case: eleman ilk gözdedir, $\Theta(1)$.
  - Average case: başarılı arama olasılığı $p$ ($0 \le p \le 1$), elemanın $i$. konumda olma olasılığı $\frac{p}{n}$ ve o durumda $i$ karşılaştırma yapılır. Başarısız aramada $n$ karşılaştırma, olasılığı $1 - p$:
    $C_{avg}(n) = \left[1 \cdot \frac{p}{n} + 2 \cdot \frac{p}{n} + \dots + n \cdot \frac{p}{n}\right] + n(1-p) = \frac{p}{n} \cdot \frac{n(n+1)}{2} + n(1-p) = p \cdot \frac{n+1}{2} + n(1-p)$.
  - $p = 1$ (eleman kesin var) için $\frac{n+1}{2}$, $p = 0$ (eleman yok) için $n$ çıkar. Average case bazen $n$'den küçük olabildiğinden $O(n)$ ile gösterilir.
- Insertion sort (ekrandan, 01:45:00, 01:50:00 ve 01:55:00)
  - Her eleman, kendisinden önceki sıralı kısımla geriye doğru karşılaştırılıp sırayı bozmayacağı yere yerleştirilir.
  - Akış: $i = 1$'den $n-1$'e kadar `tmp = a[i]`, `j = i`; `(j > 0) && (tmp < a[j-1])` olduğu sürece `a[j] = a[j-1]`, `j = j - 1`; döngüden çıkınca `a[j] = tmp`.
  - İz sürme: 3, 1, 2, 0 dizisi adım adım 1, 3, 2, 0 → 1, 2, 3, 0 → 0, 1, 2, 3 olur; son adımda `tmp = 0` iken $j$ sırasıyla 3, 2, 1, 0 değerlerini alır.
  - Worst case dizinin ters sıralı olduğu durumdur: her eleman en başa kadar taşınır, iç döngü $i$ kez çalışır. Toplam $\sum i \approx \frac{n^2}{2}$, yani worst case $n^2$ mertebesindedir. Best case analizi bu kayıtta yapılmadı.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
