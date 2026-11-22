# Ders 4 Çalışma Özeti

## Genel Konular

- Birikimli dağılım fonksiyonu (CDF) tekrarı
  - $X$ bir rastgele değişken (RV) ve $\Omega_X = \{x_1, x_2, \dots, x_n\}$ olsun. $|\Omega_X| = n < \infty$ olduğundan $X$ kesikli (discrete) bir rastgele değişkendir (ekrandan, 00:10:00).
  - CDF tanımı: $F_X(x) = \Pr(X \le x) = \sum_{x_k \le x} \Pr(X = x_k)$. Zar atmada örnek uzay $\{1, 2, 3, 4, 5, 6\}$ idi ve CDF basamaklı bir grafik veriyordu.
- CDF'in temel özellikleri (ekrandan, 00:15:00)
  - $0 \le F_X(x) \le 1$.
  - $F_X(-\infty) = \lim_{x \to -\infty} F_X(x) = 0$ ve $F_X(+\infty) = \lim_{x \to \infty} F_X(x) = 1$.
  - CDF artan bir fonksiyondur ve basamak (staircase) karakteristiği vardır; hiç azalmaz.
- CDF ile aralık olasılıkları (ekrandan, 00:20:00, 00:25:00, 00:30:00)
  - $\Pr(X > b) = 1 - \Pr(X \le b)$. Gerekçe: $\Omega = \{-\infty < X < +\infty\}$ evrensel kümedir ve olasılığı 1'dir; $A = \{X > b\}$ ile $B = \{X \le b\}$ bu kümeyi ikiye ayırır.
  - $a < b$ için:
    - $\Pr(a < X \le b) = \Pr(X \le b) - \Pr(X \le a) = F_X(b) - F_X(a)$ (hocanın kutu içine aldığı formül).
    - $\Pr(a \le X < b) = \Pr(X = a) + F_X(b) - F_X(a) - \Pr(X = b)$.
    - $\Pr(a \le X \le b) = \Pr(X = a) + F_X(b) - F_X(a)$.
    - $\Pr(a < X < b) = F_X(b) - F_X(a) - \Pr(X = b)$.
- Rastgele değişkenlerle işlemler (ekrandan, 00:30:00)
  - $X$ ve $Y$, $\Omega$ örnek uzayı üzerinde tanımlı fonksiyonlar olarak görülürse toplam $X + Y$, çarpım $X \cdot Y$ ve skaler çarpım $kX$ ($k \in \mathbb{R}$) tanımlanabilir.
  - Yeni rastgele değişkenin önce örnek uzayı (alabileceği değerler), sonra her değerin olasılığı bulunur. Buradan PMF tablosu ve CDF elde edilir.
  - Örnekte $X \in \{0, 1\}$ ($3/4$, $1/4$) ve $Y \in \{1, \dots, 6\}$ (her biri $1/6$) bağımsız alındı; $Z = X + Y$ ve $W = 2X^2/(X + Y)$ incelendi (ekrandan, 00:35:00).
- Rastgele vektörün dağılımı (ekrandan, 00:50:00)
  - Aynı $\Omega$ üzerinde tanımlı iki kesikli RV: $X \in \{x_1, \dots, x_k\}$, $p_i = \Pr(X = x_i)$, $\sum_i p_i = 1$; $Y \in \{y_1, \dots, y_l\}$, $q_j = \Pr(Y = y_j)$, $\sum_j q_j = 1$.
  - $(X, Y)$ çiftine **rastgele vektör** (random vector) denir. Örnek uzayı bütün $(x_i, y_j)$ çiftleridir; büyüklüğü $k \cdot l$'dir.
- Ortak dağılım (joint distribution) ve ortak PMF (ekrandan, 01:10:00, 01:15:00)
  - Ortak PMF: $p_{(X,Y)}(x, y) = \Pr\big((X, Y) = (x, y)\big) = \Pr(X = x \cap Y = y)$.
  - Tabloda satırlar $x_i$, sütunlar $y_j$'dir; hücre $r_{ij} = \Pr(X = x_i \cap Y = y_j)$.
  - Satır toplamı: $\sum_{j=1}^{l} r_{ij} = p_i$; sütun toplamı: $\sum_{i=1}^{k} r_{ij} = q_j$.
  - $\sum_{i=1}^{k} \sum_{j=1}^{l} r_{ij} = 1$, çünkü $(X = x_i \cap Y = y_j)$ olayları ($1 \le i \le k$, $1 \le j \le l$) örnek uzayın bir parçalanışıdır (ekrandan, 01:25:00).
- Marjinal dağılım (ekrandan, 01:30:00, 01:35:00)
  - $X$'in dağılımı tablonun marjinal sütunuyla, $Y$'nin dağılımı marjinal satırıyla verilir. Tablonun ilk sütunu ile son sütunu birlikte $X$'in marjinal dağılımını oluşturur ($Y$ için ilk ve son satır).
- Rastgele değişkenlerin bağımsızlığı
  - $X$ ve $Y$, her $(x, y)$ değer çifti için $\Pr(X = x \cap Y = y) = \Pr(X = x)\Pr(Y = y)$ ise bağımsızdır. Tablo diliyle: her $i, j$ için $r_{ij} = p_i q_j$.
  - Örnek tabloda her hücre satır ve sütun marjinallerinin çarpımı çıktığı için $X$ ve $Y$ bağımsızdır (ekrandan, 01:45:00).
- Koşullu olasılık (ekrandan, 02:10:00, 02:15:00)
  - $X$ ve $Y$ bağımsız değilse koşullu olasılıklar kullanılır: $\Pr(X = x_i \mid Y = y_j) = \dfrac{r_{ij}}{q_j}$, $\Pr(Y = y_j \mid X = x_i) = \dfrac{r_{ij}}{p_i}$.
- Beklenen değer (expectation) (ekrandan, 02:20:00)
  - $E[X] = \sum_k x_k \Pr(X = x_k) = \sum_k x_k\, p_X(x_k)$.
  - $E[X]$ rastgele değişkenin aldığı değerlerin ortalamasının (average value, mean) ölçüsüdür. Gösterim: $\mu = E[X]$ ya da $\mu_X = E[X]$.
- Beklenen değerin özellikleri (ekrandan, 02:25:00)
  - $E[a] = a$; $E[aX] = aE[X]$; $E[X + Y] = E[X] + E[Y]$ (doğrusallık, her $X, Y$ için).
  - $X, Y$ bağımsızsa $E[XY] = E[X]E[Y]$.
  - $\inf X \le E[X] \le \sup X$; $E\big[X - E[X]\big] = 0$.
  - $E[g(X)] = \sum_k g(x_k)\Pr(X = x_k)$.
- Momentler, varyans ve standart sapma (ekrandan, 02:30:00, 02:35:00, 02:40:00)
  - $g(x) = x^\gamma$ için $E[X^\gamma]$, $X$'in $\gamma$'ıncı momentidir; $\gamma = 2$ ikinci, $\gamma = 3$ üçüncü moment.
  - $g(x) = (x - E[X])^\gamma$ için $E\big[(X - E[X])^\gamma\big]$, $\gamma$'ıncı merkezî momenttir (centered moment). $\gamma = 2$ varyanstır.
  - $\mathrm{Var}(X) = E\big[(X - E[X])^2\big] = \sum_k (x_k - \mu)^2 \Pr(X = x_k) = E[X^2] - E[X]^2$.
  - Varyans dağılımın yayılımını (spread) ölçer ve $\sigma^2$ ya da $\sigma_X^2$ ile gösterilir. Standart sapma $\sigma_X = \sqrt{\mathrm{Var}(X)}$'tir ve $X$ ile aynı ölçü birimine sahiptir (ekrandan, 02:45:00).
- Varyansın özellikleri (ekrandan, 02:50:00, 02:55:00)
  - $\mathrm{Var}(a) = 0$; $\mathrm{Var}(aX) = a^2\,\mathrm{Var}(X)$.
  - $X$ ve $Y$ bağımsızsa $\mathrm{Var}(X + Y) = \mathrm{Var}(X) + \mathrm{Var}(Y)$.

## Hocanın Özellikle Vurguladığı Kısımlar

- $\Pr(a < X \le b) = F_X(b) - F_X(a)$
  - Hoca bu formülü kırmızıyla çevirip "çok önemli" diye işaretledi. Diğer aralık türleri bu formüle uç noktalardaki olasılıklar eklenip çıkarılarak elde edilir.
- Yeni rastgele değişkenin örnek uzayı dikkatle bulunmalı
  - $Z = X + Y$ örneğinde $Y$'nin en küçük değeri 1 olduğu için $Z$ sıfır olamaz; $\Omega_Z = \{1, \dots, 7\}$'dir. Değerleri körü körüne toplamak her zaman doğru sonuç vermez.
  - $W$ örneğinde örnek uzayın değerleri eşit olasılıklı değildir. $\Pr(W = 0)$ için "1/7" demek yanlıştır; doğrusu $3/4$'tür.
  - Örnek uzayda bulunmayan bir değerin olasılığı sıfırdır (örneğin $\Pr(W = 2) = 0$).
- Bağımsızlık değerlere göre değil olasılıklara göre belirlenir
  - İki rastgele değişkenin aynı değerleri (örneğin ikisinin de $\{0, 1\}$) alması onları bağımlı yapmaz. Bağımsızlık, ortak olasılıkların marjinal olasılıkların çarpımına eşit olup olmadığına bakılarak söylenir.
  - Hoca literatürde sık yapılan bir hataya dikkat çekti: iki dizi de 0 ve 1'lerden oluşuyor diye "bağımlıdır" demek yanlıştır; 0 ve 1'lerin ayrı ve birlikte oluşma olasılıkları hesaplanmalıdır.
- "Beklenti" ile "beklenen" aynı şey değildir
  - Zar atıldığında 1-6 arası değerlerden biri beklenir (bu daha çok örnek uzayı anlatır). Beklenen değer ise ortalamadır: $(1 + 2 + \dots + 6)/6 = 3{,}5$.
- Varyans ortalamadan uzaklığı ölçer
  - Zaman ekseninde çizilen iki deney dizisinde ortalamadan daha uzak dağılan noktaların varyansı daha büyüktür.
- Olasılık ve istatistik, makine öğrenmesi, yapay zekâ, bilgisayarla görme, robotik ve insansız hava araçları gibi alanların temelidir.

## Kısa Tekrar Notları

- $F_X(x) = \Pr(X \le x)$; $0 \le F_X \le 1$, $F_X(-\infty) = 0$, $F_X(+\infty) = 1$, artan ve basamaklı.
- $\Pr(X > b) = 1 - F_X(b)$; $\Pr(a < X \le b) = F_X(b) - F_X(a)$.
- Kapalı uç eklenirse $\Pr(X = a)$ eklenir, açık uç çıkarılırsa $\Pr(X = b)$ çıkarılır.
- $X + Y$, $XY$, $kX$ yeni rastgele değişkenlerdir; önce örnek uzay, sonra olasılıklar.
- Bağımsız $X, Y$ için $\Pr(X = x, Y = y) = \Pr(X = x)\Pr(Y = y)$.
- Rastgele vektör $(X, Y)$: örnek uzay büyüklüğü $k \cdot l$; ortak tablo $r_{ij}$.
- Satır toplamı $p_i$, sütun toplamı $q_j$, bütün hücrelerin toplamı 1.
- Bağımsızlık: her hücrede $r_{ij} = p_i q_j$.
- Koşullu: $\Pr(X = x_i \mid Y = y_j) = r_{ij}/q_j$.
- $E[X] = \sum_k x_k p_X(x_k)$; doğrusal; bağımsızsa $E[XY] = E[X]E[Y]$.
- $\mathrm{Var}(X) = E[X^2] - E[X]^2$; $\mathrm{Var}(aX) = a^2\mathrm{Var}(X)$; bağımsızsa $\mathrm{Var}(X + Y) = \mathrm{Var}(X) + \mathrm{Var}(Y)$.
- $\sigma_X = \sqrt{\mathrm{Var}(X)}$, $X$ ile aynı birimde.

## Detaylı Açıklamalar

- **CDF ve aralıklar.** Kesikli bir $X$ için $F_X(x)$, $x$ eşiğine kadar olan bütün değerlerin olasılıklarının toplamıdır. Bu yüzden $F_X(b) - F_X(a)$ farkı tam olarak $(a, b]$ aralığındaki değerlerin olasılığını verir. $a$ noktası da dahil edilmek isteniyorsa $\Pr(X = a)$ eklenir; $b$ noktası hariç tutulmak isteniyorsa $\Pr(X = b)$ çıkarılır. $\Pr(X > b)$ ise tümleyen kuralıyla bulunur: $\{X > b\}$ ve $\{X \le b\}$ olayları evrensel kümeyi ($-\infty < X < +\infty$) ayrık iki parçaya böler, toplam olasılık 1 olduğundan $\Pr(X > b) = 1 - \Pr(X \le b)$ olur.
- **Rastgele değişkenlerle işlem örneği.** $X$: $\Pr(X = 0) = 3/4$, $\Pr(X = 1) = 1/4$; $Y$: 1'den 6'ya her değer $1/6$ olasılıklı; $X$ ile $Y$ bağımsız (ekrandan, 00:35:00).
  - $Z = X + Y$ için $\Omega_Z = \{1, 2, \dots, 7\}$.
  - $\Pr(Z = 1) = \Pr(X = 0)\Pr(Y = 1) = \frac{3}{4} \cdot \frac{1}{6} = \frac{1}{8}$.
  - $\Pr(Z = 2) = \Pr(X = 0)\Pr(Y = 2) + \Pr(X = 1)\Pr(Y = 1) = \frac{1}{8} + \frac{1}{24} = \frac{4}{24} = \frac{1}{6}$. Çarpım yazılmasının nedeni $X$ ile $Y$'nin bağımsız olmasıdır.
  - $W = \dfrac{2X^2}{X + Y}$ için $X = 0$ iken $W = 0$; $X = 1$ iken $W = \frac{2}{1+Y} \in \{1, \frac{2}{3}, \frac{1}{2}, \frac{2}{5}, \frac{1}{3}, \frac{2}{7}\}$. $\Pr(W = 0) = 3/4$, $\Pr(W = 1) = \frac{1}{4} \cdot \frac{1}{6} = \frac{1}{24}$, $\Pr(W = 2) = 0$.
  - Bulunan olasılıklarla yeni değişkenin PMF tablosu ve CDF'i çıkarılabilir.
- **Ortak dağılım tablosu.** $(X, Y)$ rastgele vektörünün dağılımı $k \times l$'lik bir tabloyla verilir. Bir satırdaki bütün hücreler toplandığında $Y$'nin bütün olası değerleri üzerinden toplama yapılmış olur ve $Y$ "yok edilir"; sonuç $\Pr(X = x_i) = p_i$'dir. Sütun toplamı da benzer şekilde $q_j$'yi verir. Bu satır ve sütun toplamları tablonun kenarına yazıldığı için bunlara marjinal dağılım denir. Toplama sırası değiştirilerek de $\sum_i \sum_j r_{ij} = \sum_i p_i = 1$ ve $\sum_j \sum_i r_{ij} = \sum_j q_j = 1$ gösterildi.
- **Bağımsızlık örneği.** $\Pr(X = 0) = 1/4$, $\Pr(X = 1) = 3/4$ ve $Y$ yine 1-6 arası eşit olasılıklı alındı. Bağımsız durumda tablo $X = 0$ satırında her hücre $1/24$, $X = 1$ satırında her hücre $3/24$ olur; her hücre $p_i q_j$'ye eşit olduğu için $X$ ve $Y$ bağımsızdır (ekrandan, 01:45:00). Ardından hoca $X, Y \in \{0, 1\}$ için $r_{11} = 1/16$, $r_{21} = 3/16$ ve marjinalleri $1/2, 1/2$ ile $1/4, 3/4$ olan bir tabloyla bağımlı bir durum kurdu: $1/16 \ne \frac{1}{2} \cdot \frac{1}{4} = \frac{1}{8}$ olduğundan $X$ ve $Y$ bağımlıdır. Bağımsız olsaydı hücreler $1/8, 3/8, 1/8, 3/8$ olurdu (ekrandan, 01:55:00).
- **Koşullu olasılık tablodan.** Tabloda bir hücreyi bulunduğu sütunun toplamına bölmek $\Pr(X = x_i \mid Y = y_j)$'yi, bulunduğu satırın toplamına bölmek $\Pr(Y = y_j \mid X = x_i)$'yi verir. Örneğin $r_{32}/q_2 = \Pr(X = x_3 \mid Y = y_2)$.
- **Varyansın türetilmesi.** $\mathrm{Var}(X) = E\big[(X - \mu)^2\big] = E[X^2 - 2\mu X + \mu^2]$. $\mu = E[X]$ sabit olduğu için beklenen değerin dışına çıkar: $E[X^2] - 2E[X]E[X] + E[X]^2 = E[X^2] - E[X]^2$. Yani varyans, ikinci moment ile birinci momentin karesinin farkıdır (ekrandan, 02:40:00).
- **$\mathrm{Var}(aX)$ ve $\mathrm{Var}(X + Y)$.** $\mathrm{Var}(aX) = E[a^2X^2] - (aE[X])^2 = a^2\big(E[X^2] - E[X]^2\big) = a^2\,\mathrm{Var}(X)$. Toplam için $\mathrm{Var}(X + Y) = E[(X + Y)^2] - (E[X] + E[Y])^2$ açılır; bağımsızlıkta $E[XY] = E[X]E[Y]$ olduğundan $2E[XY]$ ile $-2E[X]E[Y]$ terimleri birbirini götürür ve $\mathrm{Var}(X) + \mathrm{Var}(Y)$ kalır (ekrandan, 02:55:00). Hoca bu sonucun ilişkisiz (uncorrelated) değişkenler için de geçerli olduğunu, ilişkisizliğin ileride işleneceğini söyledi.
- **Ders sonrası not.** Hoca 4. özelliği "$E[XY] = E[X]E[Y]$ ancak ve ancak $X$ ve $Y$ bağımsızsa" diye yazdı (ekrandan, 02:25:00). Doğrusu tek yönlüdür: bağımsızlık bu eşitliği gerektirir, ama eşitlik bağımsızlığı gerektirmez (eşitlik, değişkenlerin ilişkisiz olması demektir). Hoca $\mathrm{Var}(X + Y)$ için de önce "ancak ve ancak" dedi, sonra "if" diye düzeltti; eşitlik tam olarak kovaryans sıfırken sağlanır.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
