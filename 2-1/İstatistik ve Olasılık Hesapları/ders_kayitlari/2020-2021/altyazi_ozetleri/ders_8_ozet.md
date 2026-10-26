# Ders 8 Çalışma Özeti

## Genel Konular

- Dersin tarihi 3 Aralık 2020 Perşembe. Ders Zoom üzerinden, İngilizce işlendi.
  - Asıl anlatım yaklaşık 00:03'te başlar. Duyurular Türkçe de tekrarlandı.
- Kesikli dağılım aileleri (devam)
  - Geometrik dağılım (geometric distribution)
  - Negatif binom dağılımı (negative binomial distribution)
  - Poisson dağılımı ve internet servis sağlayıcısı örneği
  - Binom dağılımına Poisson yaklaşımı (Poisson approximation of binomial)
- Sürekli dağılımlara giriş (continuous distributions)
  - Olasılık yoğunluk fonksiyonu (probability density function, PDF) ve kümülatif dağılım fonksiyonu (CDF)
  - Elektronik bileşen ömrü örneği
  - Ortak (joint) ve marjinal (marginal) yoğunluklar, bağımsızlık
  - Sürekli rastgele değişkenlerde beklenen değer
- Sürekli dağılım aileleri
  - Düzgün dağılım (uniform distribution) ve standart düzgün dağılım
  - Üstel dağılım (exponential distribution), yazıcı örneği, belleksizlik özelliği (memoryless property)
  - Gama dağılımı (gamma distribution) ve Poisson ile ilişkisi
  - Normal dağılım (normal distribution), standart normal dağılım, gelir örneği
- Sınav duyuruları
  - İkinci vize 17 Aralık 2020'de. İkinci quiz sürpriz olacak.

## Hocanın Özellikle Vurguladığı Kısımlar

- Poisson problemlerinde $\lambda$'yı sorulan zaman aralığına göre ayarlayın.
  - Günde ortalama 10 olay varsa 2 günde $\lambda = 20$ olur. Hoca örneği bu uyarı için seçtiğini söyledi.
  - 1 günde 8'den fazla olasılığı ile 2 günde 16'dan fazla olasılığı aynı değildir.
- Kümülatif olasılıkları elle hesaplamak zordur.
  - Baron'un kitabının sonundaki tabloları kullanın: Tablo A3 (Poisson), Tablo A4 (standart normal).
  - "Programcıyız": Python veya MATLAB'deki hazır fonksiyonlar da kullanılabilir.
- Sürekli dağılımda tek bir noktanın olasılığı sıfırdır.
  - Bu yüzden $P(X \le x) = P(X < x)$ olur. Olasılık her zaman bir aralık için sorulur.
- Kesikli formüllerdeki toplam, sürekli durumda integrale; PMF de yoğunluğa dönüşür.
- Parçalı tanımlı yoğunlukta integral sınırlarına dikkat edin.
  - Yoğunluğun sıfır olduğu bölgeyi integrale katmayın; alt sınır o bölgenin bittiği yer olur.
- Üstel dağılım örneklerinde birimleri eşitleyin.
  - $\lambda$ saat başına verildiyse dakikayı saate çevirin (veya tersini yapın).
- Olay sayısı, olaylar arası süre ve $k$ olayın toplam süresi birbirine bağlıdır.
  - Sabit sürede nadir olay sayısı Poisson, olaylar arası süre üstel, $\alpha$ olayın toplam süresi gamadır.
- Bu hafta çok hızlı gidildi ve hız devam edecek.
  - Atlanan örnekleri kitaptan çalışın. Baron'dan 3. ve 4. bölüm alıştırmalarını yapın; Pishro-Nik'in kitabı da kullanılabilir.
- İkinci quiz sürpriz olacak; önümüzdeki hafta da olabilir. Çalışmayı bırakmayın.

## Kısa Tekrar Notları

- Geometrik: ilk başarıya kadar gereken bağımsız Bernoulli deneme sayısı.
  - $P(x) = (1-p)^{x-1} p$, $x = 1, 2, \dots$
  - $E[X] = 1/p$, $\mathrm{Var}(X) = (1-p)/p^2$
- Negatif binom: $k$ başarıya kadar gereken deneme sayısı; $k$ geometriğin toplamı.
  - $P(x) = \binom{x-1}{k-1} (1-p)^{x-k} p^k$, $x = k, k+1, \dots$
  - $E[X] = k/p$, $\mathrm{Var}(X) = k(1-p)/p^2$
- Poisson: sabit sürede nadir olay sayısı.
  - $P(x) = e^{-\lambda} \lambda^x / x!$, $x = 0, 1, 2, \dots$
  - $E[X] = \mathrm{Var}(X) = \lambda$
- Poisson yaklaşımı: $n \ge 30$ ve $p \le 0.05$ ise $\mathrm{Binom}(n,p) \approx \mathrm{Poisson}(\lambda = np)$.
- Sürekli dağılım:
  - $f(x) = F'(x)$, $P(a \le X \le b) = \int_a^b f(x)\,dx = F(b) - F(a)$
  - $\int_{-\infty}^{\infty} f(x)\,dx = 1$
- Ortak ve marjinal yoğunluk:
  - $f(x,y) = \frac{\partial^2 F(x,y)}{\partial x \, \partial y}$
  - $f_X(x) = \int_{-\infty}^{\infty} f(x,y)\,dy$, $f_Y(y) = \int_{-\infty}^{\infty} f(x,y)\,dx$
  - Bağımsızlık: her $x, y$ için $f(x,y) = f_X(x) f_Y(y)$
- Beklenen değer: $E[g(X)] = \int g(x) f(x)\,dx$, $E[g(X,Y)] = \iint g(x,y) f(x,y)\,dy\,dx$
- Düzgün $U(a,b)$: $f(x) = 1/(b-a)$, $E[X] = (a+b)/2$, $\mathrm{Var}(X) = (b-a)^2/12$
  - Standart düzgün $U(0,1)$'den dönüşüm: $X = a + (b-a)Y$
- Üstel: $f(x) = \lambda e^{-\lambda x}$, $F(x) = 1 - e^{-\lambda x}$ ($x > 0$), $E[X] = 1/\lambda$, $\mathrm{Var}(X) = 1/\lambda^2$
- Belleksizlik: $P(T > t + x \mid T > t) = P(T > x)$. Kesikli karşılığı geometrik dağılımdır.
- Gama: $f(x) = \frac{\lambda^\alpha}{\Gamma(\alpha)} x^{\alpha-1} e^{-\lambda x}$, $E[X] = \alpha/\lambda$, $\mathrm{Var}(X) = \alpha/\lambda^2$
  - $\alpha$ şekil (shape), $\lambda$ frekans parametresi. Tamsayı $\alpha$ için $\Gamma(\alpha) = (\alpha-1)!$
- Normal $N(\mu, \sigma)$: $f(x) = \frac{1}{\sigma\sqrt{2\pi}} e^{-(x-\mu)^2/(2\sigma^2)}$
  - Standartlaştırma: $Z = (X-\mu)/\sigma$, $X = \mu + \sigma Z$. Standart normalin yoğunluğu $\phi$, CDF'si $\Phi$.

## Detaylı Açıklamalar

### Geometrik ve negatif binom dağılımı

- Geometrik dağılım, ilk başarıya kadar yapılan bağımsız Bernoulli deneme sayısını modeller.
  - $p$, tek bir denemenin başarı olasılığıdır.
  - $E[X]$ ve $\mathrm{Var}(X)$ formüllerinin ispatı ev ödevi. İspatta geometrik seri kullanılır.
- Negatif binom dağılımı, $k$ başarı elde etmek için gereken deneme sayısını modeller.
  - Hoca bunu $k$ tane geometrik değişkenin toplamı olarak açıkladı. Bu yüzden ortalama ve varyans geometriğinkinin $k$ katıdır.

### Poisson dağılımı

- Sabit bir zaman aralığındaki nadir olayların (rare events) sayısını modeller.
  - Nadir olay: çok yakın iki anda iki kez olma olasılığı çok düşük olan olay. Örnekler: meteor çarpması, çağrı merkezine yeni arama gelmesi.
  - Öğrenci "çağrı merkezine arama nadir olay mı?" diye sordu. Hoca Türkçe açıkladı: zaman gerçel (real) bir büyüklüktür. İki arama tam aynı anda gelmez, bu yüzden nadir olay kabul edilebilir.
- $\lambda$, birim zamandaki ortalama olay sayısıdır (frekans).
- Örnek: Bir internet servis sağlayıcısı günde ortalama 10 yeni hesap açıyor.
  - (a) Bugün 8'den fazla yeni hesap açılma olasılığı: $\lambda = 10$.
    - $P(X > 8) = 1 - F(8)$. Sonsuz toplam yerine tümleyen kullanılır.
    - Tablo A3'ten $F(8) = 0.333$, sonuç $1 - 0.333 = 0.667$.
  - (b) 2 günde 16'dan fazla yeni hesap olasılığı: 2 günde ortalama 20 olay olduğu için $\lambda = 20$.
    - $P(X > 16) = 1 - F(16) \approx 0.779$. Hesabın kalanı ev ödevi.
- Binom olasılıklarında $n$ büyükse $n!$ çok büyür ve hesap zorlaşır.
  - $n \ge 30$ ve $p \le 0.05$ ise binom, $\lambda = np$ olan Poisson ile yaklaşık hesaplanır.

### Sürekli dağılımlar

- Sürekli rastgele değişkenler gerçel sayı değerleri alır: ağırlık, boy, uzaklık, sıcaklık.
- Sürekli dağılımda olasılık kütle fonksiyonu her noktada sıfırdır. Bunun yerine olasılık yoğunluğu kullanılır.
  - CDF: $F(x) = P(X \le x)$.
  - Yoğunluk, CDF'nin türevidir: $f(x) = dF(x)/dx$.
- Olasılık, yoğunluk eğrisinin altındaki alandır. Alan integral ile hesaplanır.
  - $F(b) = \int_{-\infty}^{b} f(x)\,dx$ olduğu için $P(a \le X \le b) = F(b) - F(a)$.
- Bütün eğrinin altındaki alan 1'dir.

### Örnek: Elektronik bileşen ömrü

- Bir elektronik bileşenin yıl cinsinden ömrünün yoğunluğu: $x \ge 1$ için $f(x) = k/x^3$, aksi hâlde 0.
  - (a) $k$ nedir? $\int_1^{\infty} k/x^3\,dx = k/2 = 1$, buradan $k = 2$.
    - Alt sınır $-\infty$ değil 1'dir, çünkü 1'e kadar yoğunluk sıfırdır.
  - (b) CDF'nin grafiği: $F(x) = \int_1^x 2/y^3\,dy = 1 - 1/x^2$ ($x \ge 1$), $x < 1$ için 0.
    - İntegral değişkeni, sınırdaki $x$ ile karışmasın diye $y$ yazıldı.
    - Grafik 1'den itibaren artar ve 1'e yaklaşır.
  - (c) Ömrün 5 yılı aşma olasılığı: $P(X > 5) = 1 - F(5) = 1/25 = 0.04$.

### Ortak yoğunluk, marjinal yoğunluk ve beklenen değer

- Ortak CDF: $F(x,y) = P(X \le x, Y \le y)$. Ortak yoğunluk, bu CDF'nin $x$ ve $y$'ye göre kısmi türevidir.
- Marjinal yoğunluk, ortak yoğunluğun diğer değişkenin tüm değerleri üzerinden integralidir.
- Bir dikdörtgen bölgenin olasılığı çift katlı integralle bulunur: $P(a \le X \le b, c \le Y \le d) = \int_a^b \int_c^d f(x,y)\,dy\,dx$.
- Beklenen değer: $E[X] = \mu = \int_{-\infty}^{\infty} x f(x)\,dx$.
  - Örnek: $E[XY] = \iint xy\, f(x,y)\,dy\,dx$.

### Düzgün dağılım

- Yoğunluk $[a, b]$ aralığında sabittir, dışında sıfırdır. Alanın 1 olması için sabit $1/(b-a)$ olur.
- $a = 0$, $b = 1$ ise standart düzgün dağılım elde edilir. Bu durumda $[0,1]$ aralığında $f(x) = 1$'dir.
- Dönüşüm: $Y = (X-a)/(b-a)$, tersi $X = a + (b-a)Y$.
- Programlamadaki kullanım:
  - `rand` gibi fonksiyonlar $U(0,1)$ değer üretir.
  - 10 ile 20 arası değer için $X = 10 + (20-10)R$ yazılır.

### Üstel dağılım ve yazıcı örneği

- Zamanı modeller: bekleme süreleri, çağrı merkezinde iki arama arasındaki süre.
- $\lambda$ frekans parametresidir: birim zamandaki olay sayısı.
- Hocanın ilişki şeması:
  - Belli bir sürede nadir olay sayısı Poisson dağılır.
  - Ardışık nadir olaylar arasındaki süre üstel dağılır.
  - $k$ olay için gereken toplam süre gama dağılır.
- Örnek: Bir yazıcıya saatte ortalama 3 iş geliyor.
  - (a) İşler arası beklenen süre: $\lambda = 3$ iş/saat, $E[X] = 1/3$ saat = 20 dakika.
  - (b) Sonraki işin 5 dakika içinde gelme olasılığı:
    - 5 dakika $= 5/60$ saattir.
    - $F(5/60) = 1 - e^{-3 \cdot 5/60} = 1 - e^{-0.25} \approx 0.2212$.
- Belleksizlik: Yazıcının yanında 10 dakika beklemiş olmanız, 5 dakikadan fazla bekleme olasılığını değiştirmez.

### Gama dağılımı

- Arka arkaya $\alpha$ bağımsız adımın, her adım arası süre üstel ise, toplam süresi gama dağılır.
- $\Gamma(\alpha) = \int_0^{\infty} x^{\alpha-1} e^{-x}\,dx$ ($\alpha > 0$). $\alpha$ tamsayı olmak zorunda değildir.
- Şekil $\alpha$'ya göre çok değişir:
  - $\alpha = 1$: üstel dağılım.
  - $\alpha > 1$: tepeli bir eğri.
  - $\alpha < 1$: sıfıra yakın bölgede hızla artan, azalan eğri.
  - Esnek şekli yüzünden mühendislikte zaman dışındaki şeyleri modellemekte de kullanılır.
- Gama olasılıkları Poisson ile hesaplanabilir. $T \sim \mathrm{Gamma}(\alpha, \lambda)$ ve $X \sim \mathrm{Poisson}(\lambda t)$ ise:
  - $P(T > t) = P(X < \alpha)$
  - $P(T \le t) = P(X \ge \alpha)$
  - Gamanın CDF'sinin kapalı bir formu yoktur. Bu yüzden Poisson tabloları kullanılır.

### Normal dağılım ve gelir örneği

- Normal dağılım ortalamaları, toplamları ve hataları modeller. Ağırlık ve sıcaklık gibi büyüklükler için de kullanılır.
- Parametreleri ortalama $\mu$ ve standart sapma $\sigma$'dır. Grafik çan şeklindedir ve $\mu$ etrafında simetriktir.
- Standart normal: $\mu = 0$, $\sigma = 1$. Genellikle $Z$ ile gösterilir.
  - Yoğunluğu $\phi(z) = \frac{1}{\sqrt{2\pi}} e^{-z^2/2}$, CDF'si $\Phi$.
- CDF'nin kapalı bir formu yoktur. Tablo A4 veya programlama dilindeki fonksiyonlar kullanılır.
- Örnek: Bir oyun ülkesinde hane geliri ortalaması 900 jeton, standart sapması 200 jeton. Gelir normal dağılıyor.
  - Orta sınıfın (geliri 600 ile 1200 jeton arası) oranı:
    - $P(600 \le X \le 1200) = \Phi\left(\frac{1200-900}{200}\right) - \Phi\left(\frac{600-900}{200}\right) = \Phi(1.5) - \Phi(-1.5)$
    - $= 0.9332 - 0.0668 = 0.8664$. Nüfusun yaklaşık %87'si orta sınıftır.
- Gelecek hafta: Merkezi limit teoremi (central limit theorem).

### Sınav ve çalışma duyuruları

- İkinci vize 17 Aralık 2020'de olacak.
  - O gün 1 saat sınav, ardından 2 saat normal ders yapılması planlanıyor.
- İkinci quiz sürpriz olacak; gelecek haftadan dönem sonuna kadar herhangi bir derste olabilir.
- Hoca chat'e bir alıştırma yapıştırdı. Bu alıştırma kendi başınıza çözülecek.
- Birinci vize ve quiz sonuçları açıklandı. Notlar paylaşılan Excel dosyasında.
- Tatil yüzünden bir hafta kaybedildi, bu yüzden ders hızlı ilerliyor. Yılbaşı öncesi perşembe tatil olursa bir hafta daha kaybedilebilir.

### Ders sonrası notlar

- Poisson PMF'si anlatımda "$\lambda$ over $x$" gibi okundu. Doğrusu $P(x) = e^{-\lambda}\lambda^x/x!$'dir.
- (a) şıkkında soru "8'den fazla" ($X > 8$) idi. Hoca sonucu söylerken "eight or more" dedi ve 0.668 yazdı. Doğru ifade $P(X > 8) = 1 - F(8) \approx 0.667$'dir. "8 veya daha fazla" olsaydı $1 - F(7)$ gerekirdi.
- (b) için Python ile kontrol: $1 - F_{\mathrm{Poisson}(20)}(16) = 0.7789$. Hocanın 0.779 değeri doğru.
- Gelir örneğinde hoca önce "600 ile 900 arası" dedi, sonra aralığı 600–1200 olarak düzeltti. Doğru aralık 600–1200'dür; sonuç $\Phi(1.5) - \Phi(-1.5) = 0.8664$ (Python ile doğrulandı).
- Yazıcı örneğinde altyazıda "five over six dollars" geçiyor. Doğrusu 5/60 saattir. Sonuç $1 - e^{-0.25} = 0.2212$.
- Gama yoğunluğu anlatımda karışık okundu ("$x$ to the alpha $x$ or minus one, $e$ to the minus alpha $x$"). Doğrusu $f(x) = \frac{\lambda^\alpha}{\Gamma(\alpha)} x^{\alpha-1} e^{-\lambda x}$ ($x > 0$).
- Hoca gamanın ortalamasını açıklarken "her biri $1/\alpha$ beklenen değerli $\alpha$ üstel" dedi. Doğrusu: her üstel değişkenin beklenen değeri $1/\lambda$'dır. $\alpha$ tanesinin toplamı $\alpha/\lambda$ eder.
- Hoca $\Gamma(\alpha) = (\alpha-1)!$ eşitliği için "$\alpha > 1$" şartını söyledi. Eşitlik $\alpha = 1$ için de geçerlidir: $\Gamma(1) = 0! = 1$.
- Düzgün dağılım yoğunluğu bir yerde "one minus B" diye okundu. Doğrusu $1/(b-a)$'dır.
- Normal dağılımın parametreleri anlatılırken altyazıda "standart versiyonda mu sıfır ve mu sıfır" geçiyor. Doğrusu $\mu = 0$ ve $\sigma = 1$'dir.
- Altyazıda kitap adı "Barron", "Barun" ve "Barone" gibi farklı yazılmış. Doğru adı Baron'dur.
- 00:51:41 ile 00:52:51 arasındaki Türkçe duyuru, İngilizce modunda bozuk çevrildi. Anlamlı kısım: ikinci vize 17 Aralık'ta, ikinci quiz sürpriz.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz. Bu ders İngilizce anlatıldığı için altyazı da İngilizcedir.
