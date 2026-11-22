# Ders 2 Çalışma Özeti

## Genel Konular

- Hata kavramı ve sayısal analizdeki yeri
  - Sayısal yöntemler yaklaşım yöntemleridir; `for` ve `while` döngüleriyle çözüme adım adım yaklaşılır. Döngüyü durdurmak için bir ölçüte ihtiyaç vardır ve bu ölçüt genellikle hatadır.
  - Hata, gerçek değer ile hesaplanan değer arasındaki farktır: $\text{Hata} = \text{Gerçek değer} - \text{Hesaplanan değer}$ (ekrandan, 00:10:00).
  - Gerçek değer için "actual / real", hesaplanan değer için "predicted / estimated / calculated" terimleri kullanılır (ekrandan, 00:15:00).
  - Hata yalnız algoritmadan değil ölçümden de gelir: 5 V kaynak ve 2 Ω dirençli devrede teorik akım $I = V/R = 2{,}5$ A'dir; gerçek dirençlerin toleransı yüzünden ölçüm 2,49 ya da 2,51 A çıkabilir.
  - Önemli olan, bir döngü ya da sistem boyunca biriken toplam hatadır: $\sum_{i=0}^{\infty} \varepsilon_i$.
- Taylor ve Maclaurin seri açılımları
  - Sonsuz defa türevlenebilen karmaşık bir fonksiyon, polinom gibi türevi ve integrali kolay fonksiyonlar cinsinden seri olarak yazılabilir (açılım, "decomposition").
  - Taylor serisi: $f(x) = \sum_{n=0}^{\infty} \dfrac{f^{(n)}(x_0)}{n!}(x-x_0)^n$. Maclaurin serisi, $x_0 = 0$ alınan özel haldir (ekrandan, 00:30:00).
  - Seri sonunda $\sum a_n x^n$ biçiminde bir polinoma dönüşür; polinomun türevi, integrali ve kökleri kolay hesaplanır.
- Hata türleri
  - Kesme hatası (truncation): sonsuz terim gerekirken sonlu terim alınınca oluşur.
  - Bağıl hata (relative error): farkın gerçek değere oranıdır.
  - Mutlak hata: bağıl hatanın mutlak değeri (yüzde olarak da verilebilir). "Absolute error" olarak gerçek ile hesaplanan değerin bölünmemiş farkı da kullanılır.
  - Yuvarlama hatası: bir sayıyı belirli basamağa yuvarlarken oluşan hatadır.
- Doğrusal olmayan denklemler ve kök bulma
  - Doğru denklemi hatırlatması: $y = mx + n$, $m$ eğim (slope, gradient); iki noktası bilinen doğru $\dfrac{y-y_2}{y_2-y_1} = \dfrac{x-x_2}{x_2-x_1}$ (ekrandan, 01:10:00).
  - Doğrusal olmayan denklemlerin çoğunun analitik çözümü yoktur; gerçek kökler sayısal yöntemlerle yaklaşık bulunur.
  - Kapalı yöntemler (bracketing): grafik yöntemi, ikiye bölme (bisection), regula falsi. Açık yöntemler: Newton-Raphson, sekant (kiriş), sabit nokta iterasyonu (ekrandan, 01:20:00).
- Yardımcı teoremler
  - Ortalama değer teoremi: $f$, $[a,b]$'de sürekli ve türevlenebilirse $f'(c) = \dfrac{f(b)-f(a)}{b-a}$ olan bir $c \in (a,b)$ vardır.
  - Ara değer teoremi: $f$, $[a,b]$'de sürekli ve $f(a)\cdot f(b) < 0$ ise aralıkta en az bir gerçek kök vardır (sıfır geçişi, "zero crossing").
- Kapalı yöntemler
  - Grafik yöntemi: $x_0$'dan başlayıp $\Delta x$ adımlarıyla ilerlenir, işaret değişince $\Delta x$ yarıya bölünür.
  - İkiye bölme: aralığın orta noktası $c = \dfrac{a+b}{2}$ alınır; ikili arama (binary search) ile aynı mantıktadır.
  - Regula falsi: orta nokta yerine $(a, f(a))$ ve $(b, f(b))$ noktalarından geçen doğrunun $x$ eksenini kestiği nokta alınır; ikili aramaya karşılık gelen fikir interpolasyon aramasıdır.

## Hocanın Özellikle Vurguladığı Kısımlar

- Hata örtülecek bir şey değildir
  - Yapay zeka modellerinin eğitimi de yüksek hatayla başlar, hata iterasyonlarla azaltılarak bir düzene oturur. Çeviri sistemlerinin kelime kelime çeviriden anlamı yakalayan çeviriye geçmesi örnek olarak verildi.
- Hatanın işareti yanıltıcı olabilir
  - +2 ve −2 hatalar toplanınca sıfır çıkar, ama aslında 4 birimlik bir sapma vardır. Bu yüzden mutlak değer ya da karesel hata kullanılır.
- Bağıl hatada büyüklük mertebesi önemlidir
  - 1 cm'lik hata 100 m'lik bir köprü için önemsizken 10 cm'lik bir perçin için çok önemlidir (ekrandan, 00:50:00). Farklı ölçekteki büyüklükler (boy ve kilo gibi) ancak bağıl hata ile karşılaştırılabilir.
- Sınavda "mutlak hata" sorulduğunda
  - Hoca, sınavda mutlak hata denince bölmeli formülü (bağıl hatanın mutlak değeri) beklediklerini, bölmesiz farkı istediklerinde bunu soruda açıkça belirteceklerini söyledi.
- Kök arama için süreklilik şarttır
  - Aralıkta süreksizlik (parçalı fonksiyon, tanımsız nokta) varsa sıfır geçişi kökün varlığını garanti etmez.
- Durdurma ölçütü
  - Gerçek kök biliniyorsa (yalnız algoritmayı test ederken) gerçek değere uzaklık; bilinmiyorsa ardışık iki iterasyonun farkı $|x_{i+1} - x_i| < \varepsilon$, aralık genişliği, $\Delta x$'in değişimi ya da $|f(x)|$'in sıfıra yakınlığı kullanılabilir. Ne zaman biteceği belli olmadığı için `while` döngüsü uygundur.
- Kapalı yöntemlerin zayıflığı
  - Hep yakınsarlar ama yavaştırlar; bu yüzden sonraki derste Newton-Raphson ve sekant gibi açık yöntemlere geçilecek.

## Kısa Tekrar Notları

- $\text{Hata} = \text{Gerçek} - \text{Hesaplanan}$; örnek $f(x)=x^2$, $f(5)=25$ yerine 10 bulunursa hata $25-10=15$ (ekrandan, 00:10:00).
- Taylor: $f(x) = \sum \frac{f^{(n)}(x_0)}{n!}(x-x_0)^n$; Maclaurin: $x_0 = 0$.
- $\cos x \approx 1 - \frac{x^2}{2} + \frac{x^4}{24}$ (yalnız çift dereceli terimler, çünkü $\cos$ çift fonksiyondur) (ekrandan, 00:25:00).
- $e^{2x} = \sum \frac{2^n x^n}{n!} = 1 + 2x + 2x^2 + \frac{4}{3}x^3 + \dots$
- $e^x$'in $x=4$ çevresindeki Taylor serisi: $\sum \frac{e^4 (x-4)^n}{n!}$ (ekrandan, 00:30:00).
- Polinomun Taylor açılımı kendi derecesinde tam sonuç verir; derste 4. dereceden polinom için 4. derecede kesme hatası sıfır oldu (ekrandan, 00:40:00).
- Bağıl hata $= \frac{\text{Gerçek} - \text{Hesaplanan}}{\text{Gerçek}}$; köprü %0,01, perçin %10 (ekrandan, 00:50:00).
- Kapalı yöntem: alt ve üst sınır gerekir (iki girdi). Açık yöntem: tek başlangıç değeri yeterlidir, ama ıraksayabilir.
- $f(a)\cdot f(b) < 0$ ise $[a,b]$'de en az bir kök var.
- İkiye bölme: $c = \frac{a+b}{2}$. Regula falsi: $c = \frac{a\,f(b) - b\,f(a)}{f(b)-f(a)}$ (ekrandan, 02:40:00).
- Arama karmaşıklıkları: doğrusal arama $n$, ikili arama $\log_2 n$, interpolasyon araması $\log_2 \log_2 n$.

## Detaylı Açıklamalar

### Kesme hatası ve Taylor örnekleri

Bir fonksiyonu Taylor serisiyle temsil etmek için sonsuz terim gerekir. Belli bir terimde durulursa geri kalan terimlerin toplamı kesme hatasıdır. Slayttaki tanım şöyledir: "Bir değerin hesaplanabilmesi için sonsuz sayıda terim alınması gerekirken sonlu sayıda terim alınıyorsa oluşan hataya kesme hatası denir. Eklenen her yeni terim sonucu değiştirir ama bu değişim çok az olduğu için göz ardı edilir." (ekrandan, 00:35:00).

Burada "sonsuz" göreli bir kavramdır: $x^3 + x^2 - x + 1$ polinomunun türevleri $3x^2+2x-1$, $6x+2$, $6$, $0$ diye biter, bu yüzden açılım üç türevde tamamlanır. $e^{2x}$'in türevleri ($2e^{2x}$, $4e^{2x}$, ...) ise hiç bitmez (ekrandan, 00:20:00). Hoca bunu $e^{jx} = \cos x + j\sin x$ ilişkisiyle açıkladı: sinüs ve kosinüsün sonsuz türevi olduğu için üstel fonksiyonun da vardır.

$\cos x$'in Maclaurin açılımında sıfırdan farklı ilk üç terim isteniyor (ekrandan, 00:25:00). Türevler $f'(x) = -\sin x$, $f''(x) = -\cos x$, $f'''(x) = \sin x$, $f^{(4)}(x) = \cos x$'tir. $x=0$'da 2. ve 4. terimler sıfır olduğundan beşinci terime kadar gitmek gerekir:

$$\cos x \approx 1 - \frac{x^2}{2} + \frac{x^4}{24}$$

Derste $\cos(\pi/5)$ (yani $\cos 36^\circ$) bu açılımla hesaplandı. Python ile kontrol: $x = \pi/5 \approx 0{,}6283$ için açılım $0{,}80910$, gerçek değer $0{,}80902$, kesme hatası yaklaşık $-8{,}5\times10^{-5}$. <!-- BELİRSİZ: Slayttaki sayısal sonuçlar karelerde görülmedi; değerler ajan tarafından hesaplandı. -->

Polinom örneğinde (ekrandan, 00:40:00) $x=0$'dan başlanıp $h=1$ adımla $f(1)$ tahmin edildi. Ekrandaki katsayılara göre açılım $f(1) \approx 1{,}2 - 0{,}25x - 0{,}5x^2 - 0{,}15x^3 - 0{,}1x^4$ olur. Sıfırıncı dereceden dördüncü dereceye kadar tahminler 1,2; 0,95; 0,45; 0,3; 0,2'dir. Gerçek değer $f(1) = 0{,}2$'dir. Fonksiyonun kendisi 4. dereceden olduğu için 4. dereceden açılım fonksiyonu birebir verir ve kesme hatası sıfırlanır (python ile doğrulandı).

### Bağıl, mutlak ve yuvarlama hataları

Bağıl hata $\dfrac{\text{Gerçek} - \text{Hesaplanan}}{\text{Gerçek}}$'tir (ekrandan, 00:45:00); yüzde ile çarpılırsa yüzde sapma elde edilir. $f(x)=x^3$ için $f(2)=8$ yerine 6 bulunursa bağıl hata $(8-6)/8 = 0{,}25$, yani %25'tir. Gerçek değer 50 iken 25 ya da 75 bulmak iki durumda da %50 sapmadır.

Köprü-perçin sorusunda (ekrandan, 00:50:00) köprü 9.999 cm (gerçeği 10.000 cm), perçin 9 cm (gerçeği 10 cm) ölçülmüştür. İki durumda da gerçek hata 1 cm'dir. Bağıl hatalar köprü için $\frac{10000-9999}{10000}\cdot 100 = \%0{,}01$, perçin için $\frac{10-9}{10}\cdot 100 = \%10$'dur. Perçindeki sapma çok daha ciddidir.

Mutlak hata örneğinde $f(x) = x^2 - 3x$, $x=2$ için gerçek değer $f(2) = 4 - 6 = -2$, hesaplanan değer 10'dur. Ekrandaki çözüm: $\left|\frac{-2-10}{-2}\right| = 6$ (ekrandan, 00:55:00).

- **Ders sonrası not:** Hoca sonucu yüzdeye çevirirken önce "yüzde 6", sonra "yüzde 15 küsur" dedi. $6 \times 100$, yani sonuç %600'dür. Bölmesiz farkla hesaplanırsa mutlak hata $|-2-10| = 12$ olur.

Yuvarlama hatası, sayının belirli bir basamağa yuvarlanmasından doğar. Programda iki gerçel sayının eşitliği `==` ile değil, farkın mutlak değerinin küçük bir eşikten (ör. 0,0001) küçük olup olmadığıyla kontrol edilir. <!-- BELİRSİZ: 27.35 ile anlatılan yuvarlama örneğinin sayıları altyazıda karışık, kare yok. -->

### Kök bulma: teoremler

Ortalama değer teoreminde $f(x) = x^2 + 5$ fonksiyonu $[1,5]$ aralığında incelenir (ekrandan, 01:25:00). $f(1) = 6$, $f(5) = 30$, $\frac{30-6}{5-1} = 6$; $f'(c) = 2c = 6$ ise $c = 3$. Hoca bulunan $c$ sayısının fonksiyondaki dalgalanma (tepe noktası sayısı) hakkında bilgi verdiğini anlattı. İkinci örnekte $f'(c) = 3c^2 + 2 = 3$ eşitliğinden $c = \pm 1/\sqrt{3}$ bulundu. <!-- BELİRSİZ: İkinci örneğin fonksiyonu ve aralığı karede görülmedi; altyazıya göre aralık [-1, 1] ve ortalama eğim 3. -->

Parçalı fonksiyon örneğinde $f(x) = 2x+1$ ($x>3$), $f(x) = x^2+1$ ($x \le 3$) için $f(0) = 1$, $f(4) = 9$ hesaplandı (ekrandan, 01:30:00). Kritik nokta olan $x=3$'te süreklilik ayrıca incelenmelidir.

### Grafik yöntemi

Algoritma adımları (ekrandan, 01:35:00): $x_0$ ve $\Delta x$ seçilir; $f(x_0)$, $f(x_0+\Delta x)$, ... hesaplanır; son iki değer ters işaretli olunca ilk iterasyon biter; sonraki iterasyon ters işaretli iki $x$ arasında, $\Delta x$ yarıya bölünerek yapılır; ters işaretli değerleri veren $x$'lerin farkı verilen hatadan küçük olunca durulur.

Örnek: $f(x) = x^2 - 6x + 5$, $x_0 = 1{,}5$, $\Delta x = 0{,}75$, $\varepsilon = 0{,}0235$ (ekrandan, 01:40:00 ve 01:50:00). İlk iterasyonda $x$ = 1,5; 2,25; 3; 3,75; 4,5; 5,25 için $f$ = −1,75; −3,43; −4; −3,43; −1,75; +1,0625; kök 4,5 ile 5,25 arasındadır. $\Delta x$ 0,375; 0,1875; 0,094; 0,047; 0,0235 diye yarılanır. Son adımda $f(4{,}9925) = -0{,}0299$, $f(5{,}016) = 0{,}0640$ bulunur ve $x_{\text{kök}} \approx 5$'tir (gerçek kökler 1 ve 5; python ile doğrulandı).

### İkiye bölme (bisection)

İkili aramanın sürekli sayı doğrusundaki karşılığıdır. Örnek: $f(x) = x^3 - 7x^2 + 14x - 6$, $[0,1]$, $\varepsilon = 0{,}01$ (ekrandan, 02:20:00).

| İterasyon | Aralık | $c$ | $f(c)$ | Hata $\frac{b-a}{2^n}$ |
|---|---|---|---|---|
| 1 | $[0,\ 1]$ | 0,5 | −0,625 | 0,5 |
| 2 | $[0,5;\ 1]$ | 0,75 | 0,9844 | 0,125 |
| 3 | $[0,5;\ 0,75]$ | 0,625 | 0,2598 | 0,03125 |
| 4 | $[0,5;\ 0,625]$ | 0,5625 | −0,1618 | 0,0078 |

Dördüncü iterasyonda hata 0,01'in altına düştüğü için $x_{\text{kök}} \approx 0{,}5625$ alınır.

- **Ders sonrası not:** Hoca anlatırken $f(0{,}75)$ için 0,098, $f(0{,}625)$ için 0,025 dedi; ekrandaki ve python ile hesaplanan değerler 0,9844 ve 0,2598'dir. Fonksiyonun gerçek kökü $2-\sqrt{2} \approx 0{,}5858$'dir ve son aralık $[0{,}5625;\ 0{,}625]$ içindedir.

### Regula falsi (yanlış nokta, doğrusal interpolasyon)

$(a, f(a))$ ve $(b, f(b))$ noktalarından geçen doğru çizilir, doğrunun $x$ eksenini kestiği nokta yeni $c$ olur. Üçgen benzerliğinden $\frac{-f(a)}{c_1-a} = \frac{f(b)}{b-c_1}$ ve buradan $c_1 = \frac{b\,f(a) - a\,f(b)}{f(a)-f(b)}$ elde edilir (ekrandan, 02:45:00). $f(a)\cdot f(c) < 0$ ise $b = c$, $> 0$ ise $a = c$ yapılır. Durdurma ölçütü olarak $|c_i - c_{i+1}| < \varepsilon$ kullanılabilir (ekrandan, 02:35:00).

Örnek: $x^3 - 2x^2 - 5 = 0$, $[2,3]$, hata 0,01 (ekrandan, 02:40:00). $f(2) = -5$, $f(3) = 4$; $c_1 = \frac{2\cdot 4 - 3\cdot(-5)}{4-(-5)} = \frac{23}{9} \approx 2{,}556$, $f(c_1) \approx -1{,}37$. Kök $[2{,}556;\ 3]$'tedir. $c_2 \approx 2{,}669$, $f(c_2) \approx -0{,}23$; sonraki adımda $\approx 2{,}69$ bulunur (python ile doğrulandı: $c_3 \approx 2{,}6873$, gerçek kök $\approx 2{,}6906$).

Dizilerde aynı fikir interpolasyon aramasıdır: ikili aramadaki $\frac{1}{2}$ çarpanı yerine verinin dağılımına göre hesaplanan bir oran kullanılır. $2^{16}$ elemanlı bir dizide doğrusal arama 65.536, ikili arama yaklaşık 17, interpolasyon araması yaklaşık $\log_2\log_2 2^{16} = 4$ adım sürer.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
