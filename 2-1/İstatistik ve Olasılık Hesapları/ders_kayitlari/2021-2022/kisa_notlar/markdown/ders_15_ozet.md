# Ders 15 Çalışma Özeti

## Genel Konular

- Karışık (mixed) rastgele değişkenler
  - Kesikli rastgele değişkenin CDF'i basamaklıdır: sıçramalar (jump) arasında sabit kalır. Sürekli rastgele değişkenin CDF'inde hiç sıçrama yoktur (ekrandan, 00:10:00).
  - Karışık rastgele değişkenin CDF'i bir ya da daha fazla sıçrama içerir, ama sıçramalar arasında sabit değildir; sürekli bir değişkenmiş gibi artabilir.
- Örnek: sürekli bir değişkenin fonksiyonu olarak karışık değişken (ekrandan, 00:15:00 ve 00:25:00)
  - $f_X(x) = 2x$, $0 \le x \le 1$; diğer yerlerde 0. $Y = g(X) = X$ ($0 \le X \le \tfrac12$), $Y = \tfrac12$ ($X > \tfrac12$).
  - $R_Y = [0, \tfrac12]$. $P(Y = \tfrac12) = P(X > \tfrac12) = \int_{1/2}^{1} 2x\,dx = \tfrac34$.
  - $0 \le y < \tfrac12$ için $F_Y(y) = P(X \le y) = \int_0^y 2x\,dx = y^2$. Sonuç: $F_Y(y) = 0$ ($y<0$), $y^2$ ($0 \le y < \tfrac12$), $1$ ($y \ge \tfrac12$).
  - Grafikte $y = \tfrac12$'de $\tfrac14$'ten $1$'e $\tfrac34$'lük sıçrama vardır; $Y$ karışık bir değişkendir (ekrandan, 00:30:00).
- Karışık değişkenin sürekli ve kesikli parçaları (ekrandan, 00:40:00)
  - $F_Y(y) = C(y) + D(y)$: $C$ sürekli parça, $D$ kesikli parça.
  - Örnekte $C(y) = 0,\ y^2,\ \tfrac14$ (sırasıyla $y<0$, $0 \le y < \tfrac12$, $y \ge \tfrac12$); $D(y) = 0$ ($y < \tfrac12$), $\tfrac34$ ($y \ge \tfrac12$).
  - $c(y) = \frac{dC(y)}{dy}$ yoğunluğa benzer ama tek başına 1'e integrallenmediği için yoğunluk değildir.
  - $y_k$ sıçrama noktaları ($P(Y = y_k) > 0$) ise $\int_{-\infty}^{\infty} c(y)\,dy + \sum_{y_k} P(Y = y_k) = 1$.
  - Beklenen değer: $EY = \int_{-\infty}^{\infty} y\,c(y)\,dy + \sum_{y_k} y_k\,P(Y = y_k)$ (derste sözlü, 00:40:13).
- Dirac delta fonksiyonu (ekrandan, 00:50:00 ve 00:55:00)
  - Birim basamak: $u(x) = 1$ ($x \ge 0$), $0$ ($x < 0$).
  - $\delta(x) = \infty$ ($x = 0$), $0$ (diğer yerlerde); $\delta(x) = \frac{d}{dx}u(x)$.
  - Grafikte $x=0$'da yüksekliği 1 olarak çizilen bir okla gösterilir.
  - Özellikler: her $\varepsilon > 0$ için $\int_{-\varepsilon}^{\varepsilon}\delta(x)\,dx = 1$; $g$, $(x_0-\varepsilon, x_0+\varepsilon)$ aralığında sürekli ise $\int_{-\infty}^{\infty} g(x)\delta(x-x_0)\,dx = \int_{x_0-\varepsilon}^{x_0+\varepsilon} g(x)\delta(x-x_0)\,dx = g(x_0)$ (ekrandan, 01:00:00).
- Genelleştirilmiş PDF (ekrandan, 01:15:00 ve 01:20:00)
  - Kesikli değişken için: $f_X(x) = \sum_{x_k \in R_X} P_X(x_k)\,\delta(x - x_k)$.
  - Karışık değişken için: $f_X(x) = \sum_k a_k\,\delta(x - x_k) + g(x)$; $a_k = P(X = x_k)$, $g(x) \ge 0$ delta içermez. $\sum_k a_k + \int g(x)\,dx = 1$.
  - Ders sonrası not: Tahtada $a_k = P(X = a_k)$ yazıldı (ekrandan, 01:20:00); doğrusu $a_k = P(X = x_k)$'dır.
- İki rastgele değişkenin ortak dağılımları (kesikli)
  - Ortak PMF: $P_{XY}(x,y) = P(X = x, Y = y)$; virgül "ve" anlamındadır. $R_{XY} = \{(x,y) \mid P_{XY}(x,y) > 0\}$ (ekrandan, 01:50:00).
  - Bütün çiftlerin olasılıkları toplamı 1'dir.
  - Marjinal PMF: $P_X(x) = \sum_{y_j \in R_Y} P_{XY}(x, y_j)$, $P_Y(y) = \sum_{x_i \in R_X} P_{XY}(x_i, y)$ (ekrandan, 01:55:00).
  - Ortak CDF: $F_{XY}(x,y) = P(X \le x, Y \le y)$.
  - Koşullu PMF: $P_{X|Y}(x_i \mid y_j) = \frac{P_{XY}(x_i, y_j)}{P_Y(y_j)}$.
  - Koşullu beklenen değer: $E[X \mid A] = \sum_{x_i} x_i P_{X|A}(x_i)$, $E[X \mid Y = y_j] = \sum_{x_i} x_i P_{X|Y}(x_i \mid y_j)$ (ekrandan, 02:15:00).
  - Bağımsızlık: her $x, y$ için $P_{XY}(x,y) = P_X(x)P_Y(y)$.
  - İki değişkenin fonksiyonu (LOTUS): $E[g(X,Y)] = \sum_{x_i}\sum_{y_j} g(x_i,y_j) P_{XY}(x_i,y_j)$ (ekrandan, 02:20:00).
- İki rastgele değişkenin ortak dağılımları (sürekli)
  - Ortak sürekli: her $A \subset \mathbb{R}^2$ için $P((X,Y) \in A) = \iint_A f_{XY}(x,y)\,dx\,dy$ olacak biçimde negatif olmayan bir $f_{XY}$ varsa; $\iint f_{XY} = 1$ (ekrandan, 02:25:00).
  - Marjinal PDF: $f_X(x) = \int_{-\infty}^{\infty} f_{XY}(x,y)\,dy$.
  - $F_{XY}(x,y) = \int_{-\infty}^{y}\int_{-\infty}^{x} f_{XY}(u,v)\,du\,dv$, $f_{XY}(x,y) = \frac{\partial^2}{\partial x \partial y}F_{XY}(x,y)$ (ekrandan, 02:30:00).
  - Bağımsızlık: her $x, y$ için $f_{XY}(x,y) = f_X(x)f_Y(y)$. Bağımsız ise $E[XY] = EX\,EY$.
- Kovaryans ve korelasyon (kesikli ve sürekli için geçerli)
  - $\mathrm{Cov}(X,Y) = E[(X - EX)(Y - EY)] = E[XY] - (EX)(EY)$ (ekrandan, 02:35:00).
  - $\rho_{XY} = \frac{\mathrm{Cov}(X,Y)}{\sigma_X \sigma_Y}$, $-1 \le \rho \le 1$.
  - $\mathrm{Var}(aX + bY) = a^2\mathrm{Var}(X) + b^2\mathrm{Var}(Y) + 2ab\,\mathrm{Cov}(X,Y)$; kovaryans 0 ise son terim düşer (ekrandan, 02:45:00).

## Hocanın Özellikle Vurguladığı Kısımlar

- Karışık değişkeni tanımak için CDF grafiğini çizmek
  - Sıçrama varsa ve CDF sıçramalar arasında sabit değilse değişken karışıktır. Hangi tür olduğunu anlamak için önce CDF grafiği çizilir.
- Dirac deltalı integralde integral aralığına dikkat
  - Delta fonksiyonunun noktası integral aralığının içindeyse o terim sıçrama olasılığını verir; dışındaysa terim sıfırdır.
- Delta fonksiyonunun grafiği
  - $\delta(0)$ sonsuzdur; grafikte yükseklik 1 olarak çizilmesi yalnız gösterim içindir. 1 olan, fonksiyonun 0 çevresindeki integralidir.
- Bağımsızlık sınaması
  - İki değişkenin bağımsız olduğunu söylemek için çarpım kuralı bütün $x, y$ değerlerinde denetlenmelidir.
- Korelasyonun neden kullanıldığı
  - Kovaryans her gerçel değeri alabildiği için büyük mü küçük mü olduğu yorumlanamaz. Korelasyon standart sapmalarla normalleştirildiği için $[-1, 1]$ aralığındadır ve yorumlanması kolaydır.

## Kısa Tekrar Notları

- Kesikli CDF: basamaklı; sürekli CDF: sıçramasız; karışık CDF: sıçramalı ve sıçramalar arasında değişen.
- Örnek: $f_X = 2x$ ($[0,1]$), $X \le \tfrac12$ iken $Y = X$, aksi halde $Y = \tfrac12$; $F_Y = y^2$ ($0 \le y < \tfrac12$), $y = \tfrac12$'de $\tfrac34$ sıçrama.
- $F_Y = C + D$; $\int c(y)\,dy + \sum P(Y = y_k) = 1$.
- $\delta(x) = u'(x)$; $\int g(x)\delta(x - x_0)\,dx = g(x_0)$.
- Genelleştirilmiş PDF: $f_X(x) = \sum_k a_k\delta(x - x_k) + g(x)$.
- Karışık örnek: $f_X(x) = \tfrac14\delta(x) + \tfrac14\delta(x-1) + \tfrac12 e^{-x}u(x)$; $P(X > 0.5) = \tfrac14 + \tfrac12 e^{-0.5} \approx 0.5533$.
- Ortak PMF tablosundan: satır toplamı marjinal, hücre / marjinal koşullu olasılık.
- Bağımsızlık: ortak = marjinallerin çarpımı (her değer için).
- $\mathrm{Cov}(X,Y) = E[XY] - EX\,EY$; $\rho = \mathrm{Cov}/(\sigma_X\sigma_Y) \in [-1,1]$.
- $\mathrm{Var}(aX+bY) = a^2\mathrm{Var}X + b^2\mathrm{Var}Y + 2ab\,\mathrm{Cov}(X,Y)$.

## Detaylı Açıklamalar

- Karışık rastgele değişken örneğinin çözümü
  - $X$'in yoğunluğu $f_X(x) = 2x$ ($0 \le x \le 1$) olsun ve $Y$, $X \le \tfrac12$ iken $X$'e eşit, $X > \tfrac12$ iken $\tfrac12$ olsun. $R_X = [0,1]$ aralığı $[0,\tfrac12]$ ve $(\tfrac12, 1]$ diye ikiye ayrılır. İlk parçada $Y = X$ olduğundan $Y$ değerleri $[0, \tfrac12]$ arasındadır; ikinci parçada $Y$ hep $\tfrac12$'dir. Böylece $R_Y = [0, \tfrac12]$ bulunur (ekrandan, 00:15:00).
  - $X$'in bir aralığı ($(\tfrac12, 1]$) tek bir $Y$ değerine ($\tfrac12$) gittiği için $P(Y = \tfrac12)$ sıfır değildir: $\int_{1/2}^{1} 2x\,dx = 1 - \tfrac14 = \tfrac34$.
  - $0 \le y < \tfrac12$ aralığında $Y = X$ olduğu için $F_Y(y) = P(X \le y) = \int_0^y 2x\,dx = y^2$. Alt sınır $-\infty$ yerine 0 alınır, çünkü $X$'in yoğunluğu 0'dan başlar. Aralığın sol ucundaki eşitlik önemsizdir, çünkü bu parça süreklidir ve tek noktanın olasılığı 0'dır (ekrandan, 00:25:00).
  - Grafik: $y < 0$ için 0; $0$ ile $\tfrac12$ arasında $y^2$ eğrisi $\tfrac14$'e kadar yükselir ve $y = \tfrac12$'de içi boş bir noktada biter; $y = \tfrac12$'de değer 1'e sıçrar. Sıçrama miktarı $1 - \tfrac14 = \tfrac34$'tür (ekrandan, 00:30:00).
  > **Ders sonrası not:** Hoca sıçramayı söylerken önce "1 minus 1 over 2, 3 over 2" dedi (00:26:18), hemen ardından "3 over 4" diye düzeltti. Doğrusu $1 - \tfrac14 = \tfrac34$'tür.
- Sürekli ve kesikli parçalara ayırma
  - Sürekli parça $C(y)$ sıçramasız devam etmelidir; bu yüzden $y \ge \tfrac12$ için $\tfrac14$'te sabit kalır. Kesikli parça $D(y)$, $y < \tfrac12$'de 0'dır ve $\tfrac12$'den sonra 1'e ulaşmak için gereken $\tfrac34$'e eşittir (ekrandan, 00:40:00).
  - $c(y) = C'(y)$ yoğunluğa benzer; sıçrama olasılıklarıyla birlikte toplamı 1 eder. Bu yüzden yoğunluk gibi kullanılabilir ve beklenen değer, sürekli parçada integral, sıçrama noktalarında değer çarpı olasılık toplamı olarak yazılır.
- Karışık değişken örneği: CDF'ten genelleştirilmiş PDF'e (ekrandan, 01:20:00, 01:30:00, 01:35:00)
  - $F_X(x) = \tfrac12 + \tfrac12(1 - e^{-x})$ ($x \ge 1$), $\tfrac14 + \tfrac12(1 - e^{-x})$ ($0 \le x < 1$), $0$ ($x < 0$).
  - Grafikte $x = 0$'da $0$'dan $0.25$'e, $x = 1$'de $\tfrac14$'lük iki sıçrama vardır ve aradaki parça artar; değişken karışıktır.
  - Sıçramalar delta terimleri, sürekli parçanın türevi $\tfrac12 e^{-x}$ ise sürekli terimdir; bu terim yalnız $x \ge 0$'da geçerli olduğu için birim basamakla çarpılır: $f_X(x) = \tfrac14\delta(x) + \tfrac14\delta(x-1) + \tfrac12 e^{-x}u(x)$.
  - $P(X > 0.5) = \int_{0.5}^{\infty} f_X(x)\,dx$: $\delta(x)$ terimi aralık dışında kaldığı için 0, $\delta(x-1)$ terimi aralık içinde olduğu için $\tfrac14$, üstel terim $\tfrac12 e^{-0.5}$ verir. Toplam $\approx 0.5533$ (python ile doğrulandı).
- Ortak PMF tablosu örneği (ekrandan, 01:45:00)
  - Tablo: $x=0$ satırı $\tfrac16, \tfrac14, \tfrac18$; $x=1$ satırı $\tfrac18, \tfrac16, \tfrac16$ ($y = 0, 1, 2$). Toplam 1'dir.
  - Ders sonrası not: Hoca marjinal $P_X(0)$'ı ilk kez yazarken tablonun kenarına $\tfrac16 + \tfrac18 + \tfrac18$ yazdı (ekrandan, 01:50:00); doğrusu $x=0$ satırının toplamı $\tfrac16 + \tfrac14 + \tfrac18 = \tfrac{13}{24}$'tür. Hoca koşullu olasılık hesabında doğru toplamı kullandı (ekrandan, 02:00:00).
  - Ders sonrası not: Tahtada $R_{XY} = R_X \times R_Y$ yazıldı; hoca bunun "bazen" böyle yazıldığını söyledi. Genelde $R_{XY}$, $R_X \times R_Y$'nin bir alt kümesidir; eşitlik yalnız bütün çiftlerin olasılığı sıfırdan büyükse geçerlidir.
  - $P(Y=1 \mid X=0) = \frac{P_{XY}(0,1)}{P_X(0)} = \frac{1/4}{1/6 + 1/4 + 1/8} = \frac{6}{13}$ (sonuç python ile hesaplandı; derste kesir biçiminde bırakıldı).
  - $E[XY] = \sum_{x=0}^{1}\sum_{y=0}^{2} xy\,P_{XY}(x,y)$; $x=0$ satırının bütün terimleri 0'dır, kalan $1\cdot1\cdot\tfrac16 + 1\cdot2\cdot\tfrac16 = \tfrac12$ (ekrandan, 02:20:00; son toplam derste söylenmedi, python ile hesaplandı).
- Kovaryans ve korelasyon sezgisi (ekrandan, 02:40:00)
  - Veri noktaları artan bir doğru çevresinde toplanıyorsa kovaryans pozitif, azalan bir doğru çevresinde toplanıyorsa negatif, belirgin bir yön yoksa sıfıra yakındır.
  - Kovaryans değişkenlerin ölçeğine bağlı olduğundan büyüklüğü tek başına anlamlı değildir; korelasyon bu yüzden tercih edilir. $\rho$ 1'e yakınsa güçlü pozitif, $-1$'e yakınsa güçlü negatif ilişki, 0 çevresindeyse ilişki yok demektir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
