# Ders 9 Genişletilmiş Notu: Eğrisel, Gregory-Newton ve Lagrange Enterpolasyonu

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Enterpolasyona Kısa Dönüş
- 2. Doğrusal Enterpolasyonun Hatırlatılması
- 3. Eğrisel (Kuadratik) Enterpolasyon
- 4. Gregory-Newton Enterpolasyonu
- 5. Değişken Dönüşümlü Gregory-Newton Enterpolasyonu
- 6. Lagrange Enterpolasyonu
- Örnek Sorular

## 1. Enterpolasyona Kısa Dönüş

Önceki derste enterpolasyon (ara değer uydurma) konusuna giriş yapılmıştı. Ders bu konunun kısa bir hatırlatmasıyla başlar. Elimize az denebilecek sayıda, $n$ tane nokta çifti verilir. Bu noktalar tek boyutlu olmak zorunda değildir: $x$, $y$, $z$ gibi birden çok bağımsız değişken ve bunların fonksiyonunun görüntüsü olan bir değer de olabilir. Değerler bir tablo hâlinde verilir.

Enterpolasyon, bu noktaların hepsinden geçen, tek boyutlu durumda bir eğri (ya da doğru), çok boyutlu durumda bir yüzey oluşturmayı sağlar. Bu sayede noktalar arasındaki bir değer tahmin edilebilir. Hoca bazı yöntemlerin enterpolasyon, bazılarının regresyon olduğunu, önce enterpolasyonla devam edileceğini söyler. Enterpolasyon özellikle veri sayısının az olduğu durumlarda kullanılır.

Hocanın verdiği günlük hayat örnekleri:

- Kalitesi düşük bir cihazla kaydedilmiş, yeterli sayıda örneği olmayan bir ses dosyasında örnek sayısını artırarak sesin kalitesini belli ölçüde iyileştirmek.
- Bir görüntüyü yeniden boyutlandırmak (resize). Hoca bir ekran görüntüsünü tutup sürükleyerek büyütür; bu doğrusal bir "lastik gibi çekip sündürme" enterpolasyonudur. Sonra resim düzenleyicinin resize menüsünden piksel boyutunu değiştirir; bu işlem arka planda farklı bir enterpolasyon yöntemi kullanır. Kötü bir yöntemle büyütülen görüntüde detaylar bozulur.
- Telefonda bir fotoğrafa parmakla yakınlaştırma yapmak. Alan aynıdır, aradaki değerleri net görmek için enterpolasyon yapılır.

Amaç bütün noktalardan geçen bilinen bir fonksiyon bulmak, sonra bilinmeyen değerleri bu fonksiyonla tahmin etmektir. Bu bilinen fonksiyonlar genellikle polinomlar ya da sinüzoidal fonksiyonlardır.

> **Hocanın vurgusu:** Bu işleme "tayin etmek", "bulmak" ya da "saptamak" denmez, "tahmin etmek" (prediction, estimation) denir. Bulunan değer gerçek değer olmayabilir; verinin gerçek dağılımında aradaki bir yerde bir sürpriz olabilir. Yine de hiçbir değere ulaşmamaktansa tahmin yapmak doğrudur.

Ekranda bu sırada enterpolasyon fonksiyonu seçimiyle ilgili iki teoremi gösteren bir slayt açıktı (ekrandan, 00:05:00): (1) $f(x)$ fonksiyonu $[a,b]$ aralığında sürekli ise enterpolasyon fonksiyonu olarak polinom kullanılabilir ve bu aralıkta $|f(x) - F(x)| \le \varepsilon$ sağlanır. (2) Periyodu $2\pi$ olan sürekli bir fonksiyon için $F(x) = \sum_{k=0}^{n} a_k \cos kx + \sum_{k=1}^{n} b_k \sin kx$ gibi sonlu bir trigonometrik açılım enterpolasyon fonksiyonu olarak kullanılabilir; belli bir $n$ değeri için $|f(x) - F(x)| < \varepsilon$ sağlanabilir. Bu slayt derste ayrıca sözlü olarak açıklanmadı.

## 2. Doğrusal Enterpolasyonun Hatırlatılması

İlk yapılan yöntem doğrusal enterpolasyondu. İki boyutlu düzlemde bir doğru üretmek için iki noktaya ihtiyaç vardır. $(x_0, y_0)$ ve $(x_1, y_1)$ noktaları birleştirilir ve bu doğrunun $-\infty$ ile $+\infty$ arasında bütün noktalardan geçtiği varsayılır. Aradaki başka $x$'lere karşılık gelen $y$ değerleri tahminlerdir. Bu, iki noktası bilinen doğru denklemini kurmaktan farklı bir şey değildir.

Kurulacak doğru $y = mx + n$ biçimindedir. $m$ doğrunun eğimidir ve iki noktası bilinen doğru denkleminden çıkar. $m$ bulunduktan sonra $n$ bulunur. İki bilinmeyen ($m$ ve $n$) olduğu için iki nokta gerekir.

Ekrandaki slaytta aynı şey $F(x) = Ax + B$ seçimiyle yazılmıştır (ekrandan, 00:10:00). $f(a) = F(a)$ ve $f(b) = F(b)$ bağıntılarından

$$Aa + B = f(a), \qquad Ab + B = f(b)$$

yazılır ve

$$A = \frac{f(a) - f(b)}{a - b}, \qquad B = \frac{b f(a) - a f(b)}{b - a}$$

bulunur. Sonuç olarak

$$F(x) = \frac{f(a) - f(b)}{a - b}\,x + \frac{b f(a) - a f(b)}{b - a}$$

olur.

Bu noktada hocanın bağlantısı koptu; kayıtta yaklaşık dokuz dakikalık bir kesinti vardır. Ders eğrisel enterpolasyonla devam eder.

## 3. Eğrisel (Kuadratik) Enterpolasyon

### 3.1 Üç nokta gerekir

Eğrisel enterpolasyonda farklı eğriler kullanılabilir. Bunlardan biri kuadratik, yani ikinci dereceden polinom üretmektir. İkinci dereceden polinom $ax^2 + bx + c$ biçimindedir ve $a$, $b$, $c$ değerlerinin bulunması gerekir.

**Soru:** $a$, $b$ ve $c$ değerleri nasıl bulunabilir? **Cevap:** Bir öğrenci noktalar biliniyorsa onlara göre bulunacağını söyler. Hoca açıklar: veri setinden üç nokta seçilir; üç nokta yeterlidir. Üç noktanın $x$ ve $y$ değerleri denklemde yerine konunca üç bilinmeyenli üç doğrusal denklem elde edilir. Bulunan $a$, $b$, $c$ ile yeni ara noktalar tahmin edilir.

Slaytta "Uygulanabilmesi için 3 nokta gereklidir" yazar; noktalar $(x_0, y_0)$, $(x_1, y_1)$, $(x_2, y_2)$, istenen $f(x_3)$'tür (ekrandan, 00:20:00). Temel fikir: bir nokta bir doğrunun üzerindeyse o doğrunun denklemini sağlar; aynı şekilde bir nokta bir fonksiyonun üzerindeyse o fonksiyonun denklemini sağlamak zorundadır. $x_2$ fonksiyona verildiğinde mutlaka $y_2$ elde edilmelidir.

### 3.2 Birinci yol: denklem sistemi

$$\begin{aligned} a x_0^2 + b x_0 + c &= y_0 \\ a x_1^2 + b x_1 + c &= y_1 \\ a x_2^2 + b x_2 + c &= y_2 \end{aligned}$$

Üç bilinmeyenli bu denklem sistemi çözülerek $a$, $b$, $c$ bulunur, sonra $f(x_3)$ hesaplanır (ekrandan, 00:20:00). Bu basit bir yöntemdir.

### 3.3 İkinci yol: kökler üzerinden yazmak

İkinci yöntem biraz daha matematiksel manipülasyona dayanır ve "denklem, geçtiği noktaları sağlar" mantığını kullanır (ekrandan, 00:25:00):

$$f(x) = b_0 + b_1 (x - x_0) + b_2 (x - x_0)(x - x_1)$$

Burada $b_0$, $b_1$, $b_2$ bulunacak katsayılardır. $(x - x_0)(x - x_1)$ çarpımı açılınca $x^2$'li, $x$'li ve sabit terimler çıkar; yani bu yine ikinci dereceden bir polinomdur.

- $b_0$: Fonksiyonda $x = x_0$ yazılırsa ikinci ve üçüncü terimler sıfır olur. Dolayısıyla $b_0 = f(x_0)$.
- $b_1$: $b_0$ artık bilinir. $x = x_1$ yazılınca üçüncü terim sıfır olur ve
  $$b_1 = \frac{f(x_1) - f(x_0)}{x_1 - x_0}$$
  elde edilir.
- $b_2$: $b_0$ ve $b_1$ bilindikten sonra $x = x_2$ yazılır, bütün bilinenler arasında $b_2$ yalnız bırakılır:
  $$b_2 = \frac{\dfrac{f(x_2) - f(x_1)}{x_2 - x_1} - \dfrac{f(x_1) - f(x_0)}{x_1 - x_0}}{x_2 - x_0}$$

Hoca programlama açısından şunu ekler: elde $x$ ve $y$ verileri varken kuadratik model bir `double` dizisiyle saklanabilir. Dizinin ilk elemanı sıfırıncı dereceden terimin, ikincisi birinci dereceden terimin, üçüncüsü ikinci dereceden terimin katsayısıdır.

> **Ek bilgi (derste anlatılmadı):** $b_1$ ve $b_2$ ifadeleri sırasıyla birinci ve ikinci bölünmüş farklardır. Bu yazım biçimi Newton'un bölünmüş farklar enterpolasyon polinomu olarak bilinir ve daha fazla noktaya aynı düzenle genişletilebilir.

### 3.4 Örnek: $x = 2.5$ için tahmin

Örnekte üç nokta verilmiş ve $2.5$ değerine karşılık gelen değerin eğrisel enterpolasyonla bulunması istenmiştir. Genel form $f(x) = b_0 + b_1(x - x_0) + b_2(x - x_0)(x - x_1)$'dir; ilk nokta $x_0 = 1$ olduğu için $(x-1)$, ikinci nokta $x_1 = 2$ olduğu için $(x-2)$ yazılır. $f(x_0) = -2$ olduğundan $b_0 = -2$ olur. $b_1$ formülüyle $b_1 = 1$, aynı şekilde $b_2 = 2$ bulunur.

<!-- BELİRSİZ: Bu örneğin nokta tablosu ekrandaydı ama o ana ait kare yok; ikinci ve üçüncü noktanın y değerleri altyazıdan okunamadı. Katsayılardan geri hesaplanınca noktalar (1,-2), (2,-1), (3,4) çıkıyor. -->

Hoca önce yazımda bir karışıklık yaptığını fark edip düzeltir: katsayılar $a$, $b$, $c$ değil, $b_0$, $b_1$, $b_2$'dir ve fonksiyon şu biçimde yazılmalıdır:

$$f(x) = -2 + 1\cdot(x - 1) + 2(x - 1)(x - 2)$$

Bu ifade açılırsa $f(x) = 2x^2 - 5x + 1$ olur (ara adım eklendi). $x = 2.5$ konursa

$$f(2.5) = -2 + 1.5 + 2(1.5)(0.5) = 1$$

tahmini bulunur (ara adım eklendi, python ile kontrol edildi).

Hoca, böyle bir tahminin başarısını değerlendiren metrikler olduğunu ama burada kullanmanın anlamı olmadığını söyler: elde yalnız üç nokta vardır ve parabol bu üç noktadan geçecek şekilde kurulmuştur. Otuz nokta olup bunlardan üçü seçilerek enterpolasyon yapılsaydı bir başarı metriğinden söz edilebilirdi. Veri sayısı az olunca bu yöntem çok tercih edilen bir yöntem değildir.

### 3.5 Kübik enterpolasyon

Aynı fikirle kübik enterpolasyon da türetilebilir. Kübik polinom $ax^3 + bx^2 + cx + d$ biçimindedir. Kökler üzerinden yazılırsa

$$f(x) = b_0 + b_1(x - x_0) + b_2(x - x_0)(x - x_1) + b_3(x - x_0)(x - x_1)(x - x_2)$$

olur ve $b_0, b_1, b_2, b_3$ (ya da $a, b, c, d$) bulunur. Ancak bir yerden sonra formülasyon hem algoritmik hem analitik olarak çok güçleşir; yerine koyma sırası önemli hâle gelir. Bunun yerine $x$'teki değişimlere karşılık $y$'deki değişimlere bakarak, yani sonlu farklarla model üretmek algoritmik olarak çok daha kolaydır. Bunun ilk versiyonu Gregory-Newton enterpolasyonudur.

## 4. Gregory-Newton Enterpolasyonu

### 4.1 Formül

Slayttaki formül şöyledir (ekrandan, 00:30:00):

$$F(x) = f_0 + \sum_{i=1}^{n} \binom{k}{i} \Delta^i f_0$$

Açılınca

$$F(x) = f_0 + \binom{k}{1}\Delta f_0 + \binom{k}{2}\Delta^2 f_0 + \cdots + \binom{k}{n}\Delta^n f_0$$

olur. Burada $k = \dfrac{x_i - x_0}{h}$ enterpolasyon değişkeni adını alır ve

$$\binom{k}{i} = \frac{k(k-1)(k-2)\cdots(k-i+1)}{i!}$$

kombinasyona benzer bir ifadedir. $\Delta^i f_0$ değerleri ileri sonlu fark tablosundan alınan sayısal değerlerdir. En açık hâliyle

$$F(x) = f_0 + \frac{k}{1!}\Delta f_0 + \frac{k(k-1)}{2!}\Delta^2 f_0 + \cdots$$

yazılır. Hoca bunun Taylor açılımına benzediğini hatırlatır. Kuadratik enterpolasyonda kökleri yerine yazmaya çok benzer; sonlu fark tablolarından elde edilenler yine bu köklerle çarpılır. $k = (x - x_0)/h$ yerine konunca genel form

$$F(x) = f_0 + \frac{x - x_0}{h}\Delta f_0 + \frac{(x - x_0)(x - x_1)}{h^2}\frac{\Delta^2 f_0}{2!} + \frac{(x - x_0)(x - x_1)(x - x_2)}{h^3}\frac{\Delta^3 f_0}{3!} + \cdots$$

hâlini alır (ekrandan, 00:40:00). $h$ ardışık $x$ değerleri arasındaki sabit uzunluktur; $x_0 + h = x_1$, $x_0 + 2h = x_2$ demektir.

> **Hocanın vurgusu:** Türetmeyi her zaman bilmek gerekmez, mantığını bilmek yeterlidir. Formülün son hâli bilinenleri yerine koymaktan ibarettir.

### 4.2 Örnek: $x_0 = 0$, $h = 1$

Tablo (ekrandan, 00:35:00):

| $x$ | 0 | 1 | 2 | 3 | 4 | 5 | 6 |
|---|---|---|---|---|---|---|---|
| $f(x)$ | $-4$ | $-2$ | 14 | 62 | 160 | 326 | 578 |

Bu değerlerden $2.5$, $3.5$, $4.5$ gibi ara değerler bulunmak istenir. Önce ileri sonlu fark tablosu kurulur: her değerden bir öncekini çıkarıp yanına yazarız.

- $\Delta f$: $2, 16, 48, 98, 166, 252$
- $\Delta^2 f$: $14, 32, 50, 68, 86$
- $\Delta^3 f$: $18, 18, 18, 18$
- $\Delta^4 f$: yok (sıfır)

<!-- BELİRSİZ: Kare yalnız Δf sütununu gösteriyor; Δ² ve Δ³ sütunları python ile tablodan hesaplandı ve altyazıdaki 14, 32 ve 18 değerleriyle uyuşuyor. -->

Hoca bu yöntemin bir güzelliğini vurgular: doğru oluştururken dokuz noktadan yalnız ikisi dikkate alınabiliyordu, oysa bütün noktalar dikkate alınarak bir model üretilirse çok daha doğru sonuç bulunur. Sonlu fark tablosu bunu sağlar. Dördüncü dereceden sonlu farkın olmaması, dördüncü dereceden polinom üretmeye gerek olmadığı anlamına gelir.

Formülde tablonun en üst satırındaki değerler kullanılır: $f_0 = -4$, $\Delta f_0 = 2$, $\Delta^2 f_0 = 14$, $\Delta^3 f_0 = 18$. $h = 1$ ve $x_0 = 0$ olduğu için kökler $x$, $x-1$, $x-2$'dir:

$$F(x) = -4 + 2\frac{x}{1!} + 14\frac{x(x-1)}{2!} + 18\frac{x(x-1)(x-2)}{3!}$$

Ara adımlar: $14/2 = 7$ ve $18/6 = 3$ olduğundan $F(x) = -4 + 2x + 7(x^2 - x) + 3(x^3 - 3x^2 + 2x) = 3x^3 - 2x^2 + x - 4$ (ara adım eklendi, python ile kontrol edildi).

Test için $F(4)$ hesaplanınca 160 bulunmalıdır; gerçekten $3\cdot 64 - 2\cdot 16 + 4 - 4 = 160$'tır. $x = 3.5$ konursa enterpolasyon, $x = 8.5$ konursa ekstrapolasyon yapılmış olur. Hepsi bulunan modelin tahminidir.

> **Ders sonrası not:** Derste $F(3.5)$ ve $F(8.5)$ sayısal olarak hesaplanmadı. Bulunan modelle $F(3.5) = 103.625$, $F(8.5) = 1702.375$ çıkar (python ile hesaplandı).

### 4.3 Örnek: $x_0 \ne 0$, $h \ne 1$

Tablo (ekrandan, 00:40:00):

| $x$ | 2 | 4 | 6 | 8 | 10 |
|---|---|---|---|---|---|
| $f(x)$ | 10 | 50 | 122 | 226 | 362 |

Sonlu farklar: $\Delta f = 40, 72, 104, 136$; $\Delta^2 f = 32, 32, 32$. İkinci farklar sabitlendiği için daha ileri gitmeye gerek yoktur.

$h = 1$ olduğunda paydalarda $1^2$, $1^3$ yazmanın anlamı yoktu; $h \ne 1$ olduğunda yapılan tek şey her terimin paydasına $h^i$ çarpanını eklemektir. Burada $x$ değerleri ikişer ikişer arttığı için $h = 2$'dir:

$$F(x) = 10 + \frac{x - 2}{2}\cdot 40 + \frac{(x - 2)(x - 4)}{4}\cdot\frac{32}{2!}$$

İkinci terimde $40/2 = 20$, üçüncü terimde $32/4 = 8$ ve $8/2! = 4$ olur:

$$F(x) = 10 + 20(x - 2) + 4(x - 2)(x - 4) = 4x^2 - 4x + 2$$

(sadeleştirme ara adımı eklendi, python ile kontrol edildi). $F(8) = 256 - 32 + 2 = 226$ bulunur; tabloda da 226 vardır.

**Soru (hocanın sorusu):** Formülde $(x-2)$ ve $(x-4)$ var ama $(x-6)$, $(x-8)$, $(x-10)$ kullanılmadı. Bunları kullanmak gerekmez miydi? **Cevap:** Bir öğrenci değişimin sabitlendiği için, yani en sonda 32 kaldığı için gerekmediğini söyler. Hoca açar: bir sonraki terimi yazmak istesek $\dfrac{(x - x_0)(x - x_1)(x - x_2)}{h^3}\dfrac{\Delta^3 f_0}{3!}$ yazardık. Ama farklar sabitlendiği için $\Delta^3 f_0 = 0$'dır ve bu terim sıfır olur; sonraki bütün katsayılar da sıfırdır. Sonlu farklar zaten bütün noktalardaki değişimi yansıtır; örneğin 32, tablodaki bütün değerlerden elde edilmiştir. Değişim bir yerde oturmasaydı terimler eklenmeye devam edilirdi.

## 5. Değişken Dönüşümlü Gregory-Newton Enterpolasyonu

### 5.1 Neden gerekir?

İlk örnekte $x$'ler sıfırdan başlayıp birer birer, ikincisinde ikişer ikişer artıyordu; üçer üçer de artabilirdi. Bu durumda paydaya yalnız bir $h$ katsayısı eklenir. Ancak $x$'ler sabit artmıyorsa, örneğin artışlar $1, 3, 5, 7, 9$ ise, bağımsız değişkende bir düzensizlik vardır. Formül $h$ değerini eşit kabul ettiği için bu durumda doğrudan uygulanamaz. Yine de artışların kendisinde bir düzen görülüyorsa değişken dönüşümüyle Gregory-Newton enterpolasyonu kullanılır.

Fikir şudur: $x$'i kontrol eden, sıfırdan başlayıp birer birer artan geçici (dummy) bir $z$ değişkeni tanımlanır ve $x = F(z)$ ilişkisi kurulur. Hoca, bunun daha kolay yolunun bir sonraki konu olan Lagrange enterpolasyonu olduğunu söyler.

### 5.2 Örnek: $x$ artışları 1, 3, 5, 7, 9

Tablo ve sonlu farklar (ekrandan, 00:45:00):

| $z$ | $x$ | $f(x)$ | $\Delta f$ | $\Delta^2 f$ | $\Delta^3 f$ | $\Delta^4 f$ |
|---|---|---|---|---|---|---|
| 0 | $-1$ | 2 | $-1$ | 10 | 36 | 24 |
| 1 | 0 | 1 | 9 | 46 | 60 | 24 |
| 2 | 3 | 10 | 55 | 106 | 84 | |
| 3 | 8 | 65 | 161 | 190 | | |
| 4 | 15 | 226 | 351 | | | |
| 5 | 24 | 577 | | | | |

Dördüncü mertebe farklar sabittir (24).

**Adım 1: $x = F(z)$.** $z$ ile $x$ arasında ayrı bir sonlu fark tablosu kurulur: $\Delta x = 1, 3, 5, 7, 9$; $\Delta^2 x = 2, 2, 2, 2$ (ekrandan, 00:45:00). $z$ birer birer arttığı için $h$ yazmaya gerek yoktur:

$$x = -1 + z\cdot\frac{1}{1!} + \frac{z(z-1)}{2!}\cdot 2 = -1 + z + z^2 - z = z^2 - 1$$

**Adım 2: $f$'nin $z$'ye göre enterpolasyonu.** $z$ düzenli arttığı için ana tablodaki sonlu farklar doğrudan kullanılır ($f_0 = 2$, $\Delta f_0 = -1$, $\Delta^2 f_0 = 10$, $\Delta^3 f_0 = 36$, $\Delta^4 f_0 = 24$):

$$f(z) = 2 - \frac{z}{1!} + 10\frac{z(z-1)}{2!} + 36\frac{z(z-1)(z-2)}{3!} + 24\frac{z(z-1)(z-2)(z-3)}{4!}$$

Toparlanınca

$$f(z) = z^4 - 2z^2 + 2$$

bulunur (python ile kontrol edildi; $z = 0..5$ için tablodaki $2, 1, 10, 65, 226, 577$ değerleri çıkar).

**Adım 3: $z$ yerine $x$.** $z^2 = x + 1$ olduğundan

$$f(x) = (x+1)^2 - 2(x+1) + 2 = x^2 + 1$$

olur (ara adım eklendi). Yani o kadar uğraşılan fonksiyon aslında $x^2 + 1$'dir. Kontrol: $8^2 + 1 = 65$, $24^2 + 1 = 577$. Hoca bu yaptığımız şeyin aynı işlemi iki defa yapmaktan ibaret olduğunu söyler: önce $x$ ile $z$, sonra $f$ ile $z$ arasında enterpolasyon.

### 5.3 Örnek: eşit aralıklı veride iki yol

Bu örnekte $x$ zaten ikişer ikişer artar, $h$ sabittir ve sonlu fark doğrudan da uygulanabilir. Örnek, değişken dönüşümünü pekiştirmek için eklenmiştir (ekrandan, 00:50:00).

| $x$ | $z$ | $f(x)$ | $\Delta f$ | $\Delta^2 f$ |
|---|---|---|---|---|
| 2 | 0 | 3 | 4 | 8 |
| 4 | 1 | 7 | 12 | 8 |
| 6 | 2 | 19 | 20 | 8 |
| 8 | 3 | 39 | 28 | |
| 10 | 4 | 67 | | |

**Birinci yol (değişken dönüşümüyle).** $z$ ile $x$ tablosunda $\Delta x = 2$ sabittir: $x = F(z) = x_0 + z\,\Delta x = 2 + 2z$, dolayısıyla $z = \dfrac{x - 2}{2}$ (ekrandan, 00:50:00). Sonra

$$f(z) = 3 + 4\frac{z}{1!} + 8\frac{z(z-1)}{2!} = 4z^2 + 3$$

bulunur. $z = (x-2)/2$ konunca

$$f(x) = (x - 2)^2 + 3 = x^2 - 4x + 7$$

elde edilir. Test edildiğinde tablodaki değerler birebir çıkar (örneğin $f(10) = 100 - 40 + 7 = 67$).

**İkinci yol (dönüşümsüz).** Doğrudan $h = 2$ ile:

$$F(x) = 3 + \frac{x - 2}{2}\cdot 4 + \frac{(x - 2)(x - 4)}{2^2}\cdot\frac{8}{2!}$$

Bu da $3 + 2(x-2) + (x-2)(x-4) = x^2 - 4x + 7$ verir (ara adım eklendi, python ile kontrol edildi). Fark sabit olduğunda iki yol da kullanılabilir.

Farkın sabit olmadığı ve değişken dönüşümünün gerektiği durumlar ekstra iş çıkarır; elde edilen dummy değişkenin kökleriyle ilgili sorunlar yaşanabilir. Bunun yerine daha genel, her durumda kullanılabilen Lagrange enterpolasyonu vardır.

## 6. Lagrange Enterpolasyonu

### 6.1 Tanım

Slayttaki tanım (ekrandan, 01:10:00): bir $f(x)$ fonksiyonunun $x_0, x_1, x_2, \dots, x_n$ gibi ayrık noktalardaki bilinen $y_0, y_1, y_2, \dots, y_n$ değerleri varsa (bu noktaların aralıkları eşit olsun ya da olmasın) ve $f(x)$'in enterpolasyon fonksiyonuna $g(x)$ dersek

$$g(x) = \sum_{i=0}^{n} L_i(x)\, y_i$$

biçimindedir. $L_i(x)$ katsayıları

$$L_i(x) = \prod_{\substack{j=0 \\ j \ne i}}^{n} \frac{x - x_j}{x_i - x_j}$$

şeklinde hesaplanır.

Fonksiyon $n+1$ terimin toplamıdır. Her terimin $y_i$ biçiminde bir katsayısı vardır; bu, tablodan gelen sayısal değerdir. Bu katsayı $L_i(x)$ Lagrange fonksiyonuyla çarpılır. $L_i(x)$ tablodaki bütün noktalara bakan bir çarpımdır; $j$ sıfırdan $n$'e kadar gider ama $i$'den farklı olmalıdır. $j = i$ olsaydı payda $x_i - x_i = 0$ olurdu; bu yüzden o terim yazılmaz. Paydaki $x$ denklemin değişkenidir. Hoca, formülün Gregory-Newton'dan türetildiğini, ama değişken dönüşümüyle uğraştırmadan doğrudan kullanılabildiğini söyler.

### 6.2 Örnek: üç nokta

Hoca örneği önce kendisi yazar (ekrandan, 01:15:00):

| $i$ | $x_i$ | $y_i$ |
|---|---|---|
| 0 | 0 | $-5$ |
| 1 | 1 | 1 |
| 2 | 3 | 25 |

Üç terim vardır ($n = 2$):

$$f(x) = \sum_{i=0}^{2} y_i L_i(x) = -5 L_0(x) + 1\cdot L_1(x) + 25 L_2(x)$$

**$L_0(x)$** ($i = 0$, $j = 0$ atlanır) (ekrandan, 01:20:00):

$$L_0(x) = \frac{x - x_1}{x_0 - x_1}\cdot\frac{x - x_2}{x_0 - x_2} = \frac{(x - 1)(x - 3)}{(0 - 1)(0 - 3)} = \frac{(x - 1)(x - 3)}{3}$$

Payda düzeni dikkat çekicidir: payda hep $x$'ten $x_1$, $x_2$ çıkarılır; paydada $x_0$'dan $x_1$, $x_2$ çıkarılır. Dört nokta olsaydı $x - x_3$ ve $x_0 - x_3$ de eklenecekti.

**$L_1(x)$** ($i = 1$, $j = 1$ atlanır):

$$L_1(x) = \frac{x - x_0}{x_1 - x_0}\cdot\frac{x - x_2}{x_1 - x_2} = \frac{x(x - 3)}{(1)(-2)} = -\frac{1}{2}\,x(x - 3)$$

**$L_2(x)$** ($i = 2$, $j = 2$ atlanır):

$$L_2(x) = \frac{x - x_0}{x_2 - x_0}\cdot\frac{x - x_1}{x_2 - x_1} = \frac{x(x - 1)}{(3)(2)} = \frac{x(x - 1)}{6}$$

Hoca burada paydayı önce yanlış yazdığını fark edip düzeltir: $x_2 - x_0 = 3$, $x_2 - x_1 = 2$, çarpım 6'dır.

Hepsi yerine konunca:

$$f(x) = -\frac{5}{3}(x - 1)(x - 3) - \frac{1}{2}x(x - 3) + \frac{25}{6}x(x - 1)$$

$x = 2$ için tahmin:

- Birinci terim: $(2-1)(2-3) = -1$, dolayısıyla $-\frac{5}{3}\cdot(-1) = +\frac{5}{3}$.
- İkinci terim: $2\cdot(2-3) = -2$, dolayısıyla $-\frac{1}{2}\cdot(-2) = +1$.
- Üçüncü terim: $2\cdot 1 = 2$, dolayısıyla $\frac{25}{6}\cdot 2 = \frac{25}{3}$.

$$f(2) = \frac{5}{3} + 1 + \frac{25}{3} = \frac{30}{3} + 1 = 11$$

Yani 1'den 3'e geçerken arada $x = 2$'ye karşılık 11 tahmin edilir. Slayttaki aynı örnekte de $g(1) = 1$ ve $g(2) = 11$ bulunur.

> **Ek bilgi (derste anlatılmadı):** Bu üç noktadan geçen tek ikinci dereceden polinom $2x^2 + 4x - 5$'tir; Lagrange ifadesi açılınca aynı polinom çıkar (python ile kontrol edildi). Lagrange ve Newton biçimleri aynı enterpolasyon polinomunun farklı yazılışlarıdır.

### 6.3 Örnek: dört nokta

Slayttaki örnek (ekrandan, 01:25:00):

| $i$ | $x$ | $y$ |
|---|---|---|
| 0 | 3 | 1 |
| 1 | 7 | $-8$ |
| 2 | 15 | $-22$ |
| 3 | 22 | $-9$ |

$n = 3$ olduğundan $g(x) = \sum_{i=0}^{3} L_i(x)\, y_i$. $L_i$'ler ezberden de yazılabilir: paydada $x_i$ dışındaki bütün $x_j$'ler $x$'ten, paydada $x_i$'den çıkarılır.

$$L_0(x) = \frac{x - x_1}{x_0 - x_1}\cdot\frac{x - x_2}{x_0 - x_2}\cdot\frac{x - x_3}{x_0 - x_3} = -\frac{1}{912}(x - 7)(x - 15)(x - 22)$$

$$L_1(x) = \frac{x - x_0}{x_1 - x_0}\cdot\frac{x - x_2}{x_1 - x_2}\cdot\frac{x - x_3}{x_1 - x_3} = \frac{1}{480}(x - 3)(x - 15)(x - 22)$$

$$L_2(x) = \frac{x - x_0}{x_2 - x_0}\cdot\frac{x - x_1}{x_2 - x_1}\cdot\frac{x - x_3}{x_2 - x_3} = -\frac{1}{672}(x - 3)(x - 7)(x - 22)$$

$$L_3(x) = \frac{x - x_0}{x_3 - x_0}\cdot\frac{x - x_1}{x_3 - x_1}\cdot\frac{x - x_2}{x_3 - x_2} = \frac{1}{1995}(x - 3)(x - 7)(x - 15)$$

Paydalar: $(3-7)(3-15)(3-22) = -912$, $(7-3)(7-15)(7-22) = 480$, $(15-3)(15-7)(15-22) = -672$, $(22-3)(22-7)(22-15) = 1995$ (python ile kontrol edildi). Her $L_i$ önüne kendi $y_i$ değeri konunca uzun bir enterpolasyon formülü elde edilir; sonrası istenen noktada tahmindir.

> **Ders sonrası not:** Hoca sözlü anlatımda katsayıları $3 L_0 + 7 L_1 + 15 L_2 + 22 L_3$ diye söyledi; bunlar tablodaki $x$ değerleridir. Formülde $y_i$ kullanılır, doğrusu $g(x) = 1\cdot L_0(x) - 8 L_1(x) - 22 L_2(x) - 9 L_3(x)$'tir. Hoca bu slaytta önceki dönemde küçük bir hata bulunduğunu ve düzelttiğini de belirtti.

## Örnek Sorular

**Soru 1** (derste sözlü, 00:20:20): İkinci dereceden $ax^2 + bx + c$ polinomunun $a$, $b$, $c$ katsayıları nasıl bulunur?

> **Cevap (derste verildi):** Veri setinden üç nokta seçilir ve denklemde yerine konur. Üç bilinmeyenli üç doğrusal denklem çözülerek $a$, $b$, $c$ bulunur. Alternatif olarak $f(x) = b_0 + b_1(x-x_0) + b_2(x-x_0)(x-x_1)$ yazılıp $b_0 = f(x_0)$, $b_1$ ve $b_2$ bölünmüş fark formülleriyle hesaplanır.

**Soru 2** (derste sözlü, 00:25:16): İlk noktası $x_0 = 1$, $f(x_0) = -2$ olan üç noktadan geçen ikinci dereceden enterpolasyonla $x = 2.5$ için tahmin yapınız. <!-- BELİRSİZ: Diğer iki noktanın değerleri ekrandaydı, kare ve altyazıda yok. Derste bulunan katsayılar b1 = 1, b2 = 2. -->

> **Çözüm (derste kısmen verildi):** $b_0 = -2$, $b_1 = 1$, $b_2 = 2$; $f(x) = -2 + (x-1) + 2(x-1)(x-2)$. $f(2.5) = -2 + 1.5 + 1.5 = 1$ (sayısal sonuç derste söylenmedi, python ile hesaplandı).

**Soru 3** (ekrandan, 00:35:00): $x = 0, 1, \dots, 6$ için $f(x) = -4, -2, 14, 62, 160, 326, 578$ veriliyor ($x_0 = 0$, $h = 1$). Gregory-Newton enterpolasyon polinomunu bulunuz.

> **Çözüm (derste verildi):** $\Delta f_0 = 2$, $\Delta^2 f_0 = 14$, $\Delta^3 f_0 = 18$ (sabit). $F(x) = -4 + 2x + 14\frac{x(x-1)}{2!} + 18\frac{x(x-1)(x-2)}{3!} = 3x^3 - 2x^2 + x - 4$. Kontrol: $F(4) = 160$.

**Soru 4** (ekrandan, 00:40:00): $x = 2, 4, 6, 8, 10$ için $f(x) = 10, 50, 122, 226, 362$ veriliyor ($x_0 \ne 0$, $h \ne 1$). Enterpolasyon polinomunu bulunuz. Neden $(x-6)$, $(x-8)$ gibi terimler gerekmez?

> **Çözüm (derste verildi):** $\Delta f_0 = 40$, $\Delta^2 f_0 = 32$ (sabit), $h = 2$. $F(x) = 10 + 20(x - 2) + 4(x - 2)(x - 4) = 4x^2 - 4x + 2$, $F(8) = 226$. İkinci farklar sabit olduğundan üçüncü ve daha yüksek mertebe farklar sıfırdır; $(x-6)$ ve sonrasını içeren terimlerin katsayısı sıfır olur.

**Soru 5** (ekrandan, 00:45:00): $x = -1, 0, 3, 8, 15, 24$ için $f(x) = 2, 1, 10, 65, 226, 577$ veriliyor. Değişken dönüşümüyle enterpolasyon fonksiyonunu bulunuz.

> **Çözüm (derste verildi):** $z = 0..5$; $x = z^2 - 1$. $f(z) = 2 - z + 10\frac{z(z-1)}{2!} + 36\frac{z(z-1)(z-2)}{3!} + 24\frac{z(z-1)(z-2)(z-3)}{4!} = z^4 - 2z^2 + 2$. $z^2 = x + 1$ ile $f(x) = x^2 + 1$.

**Soru 6** (ekrandan, 00:50:00): $x = 2, 4, 6, 8, 10$ için $f(x) = 3, 7, 19, 39, 67$ veriliyor. Enterpolasyon fonksiyonunu değişken dönüşümüyle ve dönüşümsüz bulunuz.

> **Çözüm (derste verildi):** $x = 2 + 2z$, $f(z) = 3 + 4z + 8\frac{z(z-1)}{2!} = 4z^2 + 3$, $f(x) = x^2 - 4x + 7$. Dönüşümsüz: $3 + \frac{x-2}{2}\cdot 4 + \frac{(x-2)(x-4)}{4}\cdot\frac{8}{2!}$ aynı sonucu verir.

**Soru 7** (ekrandan, 01:15:00): $(0, -5)$, $(1, 1)$, $(3, 25)$ noktaları için Lagrange enterpolasyonuyla $f(2)$'yi tahmin ediniz.

> **Çözüm (derste verildi):** $L_0 = \frac{(x-1)(x-3)}{3}$, $L_1 = -\frac{x(x-3)}{2}$, $L_2 = \frac{x(x-1)}{6}$. $f(2) = \frac{5}{3} + 1 + \frac{25}{3} = 11$.

**Soru 8** (ekrandan, 01:25:00): $x = 3, 7, 15, 22$ için $y = 1, -8, -22, -9$ veriliyor. Lagrange enterpolasyon fonksiyonunu yazınız.

> **Çözüm (derste verildi, katsayı düzeltmesiyle):** $L_0 = -\frac{1}{912}(x-7)(x-15)(x-22)$, $L_1 = \frac{1}{480}(x-3)(x-15)(x-22)$, $L_2 = -\frac{1}{672}(x-3)(x-7)(x-22)$, $L_3 = \frac{1}{1995}(x-3)(x-7)(x-15)$; $g(x) = L_0 - 8L_1 - 22L_2 - 9L_3$.

> **Çözüm (derste verilmedi):** Hoca "dördün değeri yaklaşık olarak buymuş" diyerek örnek bir tahmine değindi ama değeri söylemedi. Bu formülle $g(4) = -\frac{2739}{2660} \approx -1.0297$ çıkar (python ile hesaplandı).

## Dersin Toparlaması

Bu derste enterpolasyonun amacı hatırlatıldıktan sonra doğrusal enterpolasyondan eğrisel enterpolasyona geçildi. İkinci dereceden polinom için üç nokta gerektiği, katsayıların ya doğrusal denklem sistemiyle ya da $b_0 + b_1(x-x_0) + b_2(x-x_0)(x-x_1)$ biçimiyle bulunabileceği gösterildi. Derece arttıkça bu yaklaşım zorlaştığı için sonlu fark tablosuna dayanan Gregory-Newton enterpolasyonu anlatıldı: tablonun en üst satırındaki farklar, $k = (x-x_0)/h$ enterpolasyon değişkeni ve faktöriyellerle polinom kurulur, farklar sabitlendiği mertebede durulur. $x$ değerleri eşit aralıklı değilse ama artışları düzenliyse geçici bir $z$ değişkeniyle değişken dönüşümlü Gregory-Newton yöntemi kullanılır.

Son olarak aralıkların eşit olmasını gerektirmeyen, daha genel Lagrange enterpolasyonu $g(x) = \sum y_i L_i(x)$ formülüyle ve üç ve dört noktalı örneklerle işlendi. Hoca bir sonraki konunun regresyon olacağını, vakit kalırsa diferansiyel denklemlerin sayısal çözümüne kısaca giriş yapılacağını söyledi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
