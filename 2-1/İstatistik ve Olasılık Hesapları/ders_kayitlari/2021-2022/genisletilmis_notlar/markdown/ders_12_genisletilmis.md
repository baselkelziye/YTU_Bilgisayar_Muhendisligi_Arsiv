# Ders 12 Genişletilmiş Notu: Sürekli Rastgele Değişkenler: CDF, PDF, Beklenen Değer ve Varyans

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Kesikli Olasılıktan Sürekli Olasılığa
- 2. Sürekli Rastgele Değişkenin Tanımı
- 3. Düzgün Dağılım Örneği ve CDF
- 4. Olasılık Yoğunluk Fonksiyonu (PDF)
- 5. PDF'nin Özellikleri
- 6. Sürekli Rastgele Değişkenin Değer Kümesi
- 7. Örnek: Elektronik Bileşenin Ömrü
- 8. Beklenen Değer
- 9. Varyans
- 10. Sürekli Rastgele Değişkenin Fonksiyonları
- Örnek Sorular

## 1. Kesikli Olasılıktan Sürekli Olasılığa

Ders, sayfa başlığı "Continuous Probabilities" olan yeni bir bölümle açıldı (ekrandan, 00:10:00). Ders İngilizce anlatıldı; hoca yer yer Türkçe açıklama yaptı. Açılışta hoca iyi bilinen bir eşitsizliğe kısaca değindi, ama ayrıntısına girmedi ve kitaplardan okunmasını önerdi. <!-- BELİRSİZ: Hangi eşitsizlik olduğu altyazıda okunmuyor (00:09). -->

Şimdiye kadar kesikli olasılıklar işlenmişti. Kesikli rastgele değişkenlerin ortak özelliği değer kümelerinin (range) **sayılabilir** olmasıdır. Sürekli bir değişkenin değer kümesi ise örneğin 1 ile 2 arası gibi bir aralık olabilir. Bu durumda aralıktaki her gerçel sayı olası bir değerdir ve bu değerlerin sayısı sayılamayacak kadar çoktur.

Bunun önemli bir sonucu vardır: tek bir $x$ değerinin olasılığı **sıfırdır**. Tek noktalara sıfırdan büyük olasılıklar verilseydi, sonsuz sayıda noktanın olasılıkları toplandığında toplam olasılık 1'den büyük olurdu. Oysa toplam olasılık 1 olmalıdır. Bu yüzden sürekli durumda tek değerlerin değil, **aralıkların** olasılığından söz edilir; örneğin "rastgele değişkenin 1 ile 1,2 arasında değer alma olasılığı nedir?" gibi.

### 1.1 Sürekli kurallar kesikli kurallara benzer

Kesikli rastgele değişkenlerde öğrenilen kuralların çoğunda bir toplam bulunuyordu. Örneğin beklenen değer, olası bütün $x$'ler üzerinden $x$ ile olasılık kütle fonksiyonunun (PMF) çarpımlarının toplamıydı. Sürekli rastgele değişkenlerde kurallar çok benzerdir, ama bir farkla: toplamın yerini **integral**, PMF'nin yerini **olasılık yoğunluk fonksiyonu** (PDF) alır ve "olası bütün $x$ değerleri" $-\infty$'dan $+\infty$'a giden bir integrale dönüşür (ekrandan, 00:25:00):

$$EX = \sum_x x\,P(x) \quad (P: \text{PMF}) \qquad\longrightarrow\qquad EX = \int_{-\infty}^{+\infty} x\,f(x)\,dx \quad (f: \text{PDF})$$

Hoca bunu sayfanın başlığına "Continuous r.v. rules ≈ Discrete r.v. rules" diye yazdı.

## 2. Sürekli Rastgele Değişkenin Tanımı

Tanım ekranda şöyle yazıldı (ekrandan, 00:25:00):

- Birikimli dağılım fonksiyonu (CDF) $F_X(x)$ olan bir $X$ rastgele değişkeni, $F_X(x)$ her $x \in \mathbb{R}$ için **sürekli bir fonksiyon** ise sürekli rastgele değişken olarak adlandırılır.
- Ayrıca $F_X(x)$'in **hemen her yerde türevlenebilir** olduğu varsayılır.

## 3. Düzgün Dağılım Örneği ve CDF

### 3.1 Problem

$[a,b]$ aralığından düzgün (uniformly) ve rastgele bir gerçel sayı seçilsin ve bu sayıya $X$ densin (ekrandan, 00:35:00). $X$ sürekli bir rastgele değişkendir. "Düzgün" demek, $a$ ile $b$ arasındaki bütün değerlerin eşit olasılıklı olması demektir. İlk iş $X$'in CDF'sini bulmaktır.

### 3.2 Gösterim: büyük $X$ ve küçük $x$

Hoca, rastgele değişkeni büyük $X$ ile, onun alabileceği belirli bir değeri küçük $x$ ile gösterdiğini vurguladı (ekranda "Capital: $X$, Lowercase: $x$" kutusu, 00:35:00). CDF'nin tanımı bu gösterimle yazılır:

$$F_X(x) = P(X \le x)$$

### 3.3 CDF'nin parça parça bulunması

- $x < a$ ise: $a$'dan küçük değerlerin olasılığı sıfırdır; bu noktaya kadar toplanan bir şey yoktur. $F_X(x) = 0$.
- $x \ge b$ ise: $a$ ile $b$ arasındaki toplam olasılık 1'dir ve $b$'den büyük değerlerin olasılığı sıfır olduğu için $b$'den sonra eklenecek bir şey yoktur. $F_X(x) = 1$.
- $a < x \le b$ ise: $F_X(x) = P(X \le x) = P(X \in [a, x])$ (ekrandan, 00:35:00). Dağılım düzgün olduğu için bu olasılık $[a,x]$ aralığının uzunluğunun bütün aralığın uzunluğuna oranıdır:

$$F_X(x) = \frac{x-a}{b-a}$$

Hepsi bir arada (ekrandan, 00:40:00):

$$F_X(x) = \begin{cases} 0 & x < a \\[4pt] \dfrac{x-a}{b-a} & a \le x \le b \\[4pt] 1 & x > b \end{cases}$$

### 3.4 $<$ ile $\le$ arasındaki fark

Hoca bir yerde $\le$, başka bir yerde $<$ yazdığını fark etti ve bunun sürekli olasılıkta önemli olmadığını açıkladı. Eşitlik aralığa yalnız bir nokta ekler, tek bir noktanın olasılığı da sıfırdır; bu yüzden sonuç değişmez. Ekrana "Note: $<\ \approx\ \le$ for cont. prob." diye yazdı (ekrandan, 00:40:00).

> **Hocanın vurgusu:** Bu önemli bir noktadır: sürekli olasılıkta "küçüktür" ile "küçük eşittir" aynı sonucu verir.

### 3.5 CDF'nin grafiği

Grafik üç parçadan oluşur (ekrandan, 00:45:00):

- $a$'ya kadar yatay eksen üzerinde 0,
- $a$ ile $b$ arasında 0'dan 1'e çıkan doğrusal bir parça,
- $b$'den sonra 1 yüksekliğinde yatay bir çizgi.

Grafikte kopukluk yoktur; CDF sürekli bir fonksiyondur, bu da tanımdaki koşula uyar.

## 4. Olasılık Yoğunluk Fonksiyonu (PDF)

### 4.1 Tanım

Beklenen değere geçmeden önce olasılık yoğunluk fonksiyonu tanımlandı (ekrandan, 00:45:00). Mutlak sürekli (absolutely continuous) bir $X$ rastgele değişkeninin PDF'si küçük $f$ ile gösterilir ve CDF'nin türevidir:

$$f_X(x) = \frac{d}{dx} F_X(x)$$

Hoca "mutlak sürekli" ifadesini "her yerde sürekli" anlamında açıkladı.

> **Ek bilgi (derste anlatılmadı):** Olasılık kuramında "mutlak sürekli" terimi, CDF'nin bir yoğunluk fonksiyonunun integrali olarak yazılabilmesi anlamına gelir. Bu, yalnız sürekli olmaktan daha güçlü bir koşuldur; PDF'nin var olmasını garanti eden koşul budur.

### 4.2 Düzgün dağılımın PDF'si

CDF parçalı bir fonksiyon olduğu için türev her parça için ayrı alınır:

- $x < a$: $\dfrac{d}{dx}0 = 0$,
- $x > b$: $\dfrac{d}{dx}1 = 0$,
- $a \le x \le b$: $\dfrac{d}{dx}\,\dfrac{x-a}{b-a} = \dfrac{1}{b-a}$.

$$f_X(x) = \begin{cases} \dfrac{1}{b-a} & a \le x \le b \\[4pt] 0 & \text{diğer} \end{cases}$$

Grafiğinde yoğunluk $a$'dan önce ve $b$'den sonra sıfırdır; $a$ ile $b$ arasında $1/(b-a)$ yüksekliğinde sabittir. Yani grafik bir dikdörtgendir.

### 4.3 CDF'yi PDF'den bulmak

PDF, CDF'nin türeviyse CDF de PDF'nin integralidir (türevin tersi integraldir) (ekrandan, 01:10:00):

$$F_X(x) = \int_{-\infty}^{x} f_X(u)\,du$$

Hoca burada integral değişkeni olarak $u$ kullandı: üst sınırda $x$ zaten kullanıldığı için integrandda da $x$ yazmak karışıklık yaratır. İntegral değişkeni herhangi bir harf olabilir.

## 5. PDF'nin Özellikleri

### 5.1 Bir aralığın olasılığı

Bir aralığın olasılığı PDF ile bulunabilir (ekrandan, 01:10:00 ve 01:15:00). Kesikli durumda da geçerli olduğu gibi:

$$P(a < X \le b) = F_X(b) - F_X(a)$$

Bu iki CDF değeri yoğunluğun integrali olarak yazılınca, $F_X(b)$'den $F_X(a)$ çıkarıldığında geriye yalnız $a$ ile $b$ arasındaki alan kalır:

$$P(a < X \le b) = \int_a^b f_X(x)\,dx$$

Grafikte bu, yoğunluk eğrisinin altında $a$ ile $b$ arasında kalan taralı alandır.

### 5.2 Bir kümenin olasılığı

Daha genel olarak, herhangi bir $A$ kümesi için (ekrandan, 01:20:00):

$$P(X \in A) = \int_A f_X(x)\,dx$$

Örnek olarak $P(X \in [0,1] \cup [3,4])$ verildi. Burada $A$ kümesi iki aralığın birleşimidir; yoğunluk $0$'dan $1$'e ve $3$'ten $4$'e ayrı ayrı integre edilip toplanır.

### 5.3 Toplam olasılık 1'dir

Bütün gerçel eksen üzerindeki integral, yani toplam olasılık 1'dir (ekrandan, 01:15:00):

$$\int_{-\infty}^{+\infty} f_X(x)\,dx = 1$$

Hoca bunun çok mantıklı olduğunu, kesikli durumdaki "olasılıkların toplamı 1" kuralının karşılığı olduğunu belirtti.

### 5.4 Notlar

- Yoğunluk değerleri hiçbir zaman negatif olmaz: her $x \in \mathbb{R}$ için $f_X(x) \ge 0$ (ekrandan, 01:15:00). Grafik hiçbir yerde sıfırın altına inmez.
- Yoğunluk 1'den **büyük** olabilir. Yoğunluk bir olasılık değil, olasılığın birim uzunluktaki yoğunluğudur; olasılık ancak alan olarak elde edilir.

> **Ek bilgi (derste anlatılmadı):** Örneğin düzgün dağılımda $b - a < 1$ ise yoğunluk $1/(b-a) > 1$ olur; yine de alan (toplam olasılık) 1'de kalır.

## 6. Sürekli Rastgele Değişkenin Değer Kümesi

Değer kümesi (range), rastgele değişkenin alabileceği değerlerin kümesidir. $X$ sürekliyse $R_X$, yoğunluğu sıfırdan büyük olan gerçel sayıların kümesi olarak tanımlanabilir (ekrandan, 01:25:00):

$$R_X = \{x \mid f_X(x) > 0\}$$

## 7. Örnek: Elektronik Bileşenin Ömrü

### 7.1 Problem

Hoca örneği kendi notlarından aldığını söyledi. Bir elektronik bileşenin yıl cinsinden ömrü, yoğunluğu aşağıdaki gibi olan sürekli bir rastgele değişkendir (ekrandan, 01:30:00):

$$f_X(x) = \begin{cases} \dfrac{k}{x^3} & x \ge 1 \\[4pt] 0 & x < 1 \end{cases}$$

İstenenler: (a) $k = ?$ (b) $F_X(x) = ?$ ve grafiği (c) ömrün 5 yılı aşma olasılığı.

### 7.2 (a) $k$'nın bulunması

$k$'yı bulmanın birden fazla yolu vardır; burada toplam olasılığın 1 olması kullanıldı (ekrandan, 01:35:00):

$$\int_{-\infty}^{+\infty} f_X(x)\,dx = 1$$

Sınırlar teorik olarak $-\infty$ ve $+\infty$'dır, ama olasılığın sıfırdan farklı olmaya başladığı yer dikkate alınmalıdır. 1'e kadar yoğunluk sıfırdır, dolayısıyla $-\infty$'dan 1'e kadar olan integral sıfırdır ve alt sınır 1'e çekilir. Yoğunluğun grafiği 1'de başlayıp azalan bir eğridir.

$$\int_{-\infty}^{1} 0\,dx + \int_1^{\infty} \frac{k}{x^3}\,dx = \left[-\frac{k}{2x^2}\right]_{x=1}^{\infty} = 0 - \left(-\frac{k}{2}\right) = \frac{k}{2} = 1 \;\Rightarrow\; k = 2$$

Hoca integrali bir de "türevi bu olan fonksiyon hangisi?" diye düşünerek açıkladı (ekranda "what's derivative you are?", 01:35:00). $k$ sabittir, bir kenara bırakılır; aranan, türevi $x^{-3}$ olan fonksiyondur. $x^{-2}$'nin türevi $-2x^{-3}$'tür; başa $-\tfrac{1}{2}$ konursa $-2$'ler sadeleşir ve geriye $x^{-3}$ kalır. Yani $\int x^{-3}\,dx = -\tfrac{1}{2}x^{-2} + C$. Bu adımı sohbetten bir öğrenci de yazarak doğruladı.

Polinom integrali için kısa yol da hatırlatıldı (ekrandan, 01:45:00):

$$\int x^n\,dx = \frac{x^{n+1}}{n+1} + C$$

Bu kuralla $\int_1^{\infty} k x^{-3}\,dx = k\left[\dfrac{x^{-2}}{-2}\right]_1^{\infty}$ olur. İki yol da aynı sonucu verir.

> **Hocanın vurgusu:** Temel integral formüllerini hatırlamayanlar bunları tekrar etmeli ("review basic integration formulas"); bu konularda sürekli kullanılacak.

> **Ek bilgi (derste anlatılmadı):** $\int x^n\,dx = \dfrac{x^{n+1}}{n+1} + C$ kuralı $n \ne -1$ için geçerlidir. $n = -1$ durumunda integral $\ln x$ olur; bu durum dersin ilerisinde $EX^2$ hesabında kullanıldı.

### 7.3 (b) CDF ve grafiği

Aynı integral, yalnız sınırları değişerek kullanılır (ekrandan, 01:45:00). $x$ 1'den küçükken her şey sıfırdır; $x > 1$ için integral 1'den başlar ve $x$'e kadar gider:

$$F_X(x) = \int_{-\infty}^{x} f_X(u)\,du = \int_1^{x} \frac{2}{u^3}\,du = \left[-\frac{1}{u^2}\right]_1^{x} = 1 - \frac{1}{x^2} \quad (x > 1)$$

Son integrali hoca eve bıraktı (ara adım eklendi).

$$F_X(x) = \begin{cases} 0 & x \le 1 \\[4pt] 1 - \dfrac{1}{x^2} & x > 1 \end{cases}$$

Grafiği çizmek öğrencilere bırakıldı ("draw yourself").

### 7.4 (c) Ömrün 5 yılı aşma olasılığı

İstenen $P(X > 5)$'tir ve yoğunluğun 5'ten sonsuza integraliyle bulunur (ekrandan, 01:55:00):

$$P(X > 5) = \int_5^{\infty} f_X(x)\,dx$$

Ekranda sonuç yazılmadı, ders bu noktada araya girdi. <!-- BELİRSİZ: Hoca sonucu sözlü söylemiş olabilir; altyazıda bu kısım okunmuyor (01:45). --> Sonuç için bkz. Örnek Sorular.

## 8. Beklenen Değer

### 8.1 Tanım

Beklenen değerin ne olduğu kesikli rastgele değişkenlerden bilinmektedir. Sürekli rastgele değişkende toplamın yerini integral alır; $x$, yoğunluk fonksiyonuyla çarpılıp $-\infty$'dan $+\infty$'a integre edilir. Beklenen değer $\mu_X$ ile de gösterilir (ekrandan, 02:10:00):

$$EX = \int_{-\infty}^{+\infty} x\,f_X(x)\,dx = \mu_X$$

### 8.2 Örnek: $f_X(x) = 2x^{-3}$

Önceki örneğin yoğunluğu ($k = 2$ ile) kullanıldı: $f_X(x) = 2x^{-3}$, $x \ge 1$. Yine 1'e kadar her şey sıfır olduğu için integral 1'den başlar (ekrandan, 02:10:00):

$$EX = \int_1^{\infty} x \cdot 2x^{-3}\,dx = 2\int_1^{\infty} x^{-2}\,dx = \left[-2x^{-1}\right]_1^{\infty} = 0 - (-2) = 2$$

### 8.3 Bir fonksiyonun beklenen değeri

$Y = g(X)$ olsun. $Y$'nin beklenen değeri, $x$ yerine $g(x)$ yazılarak bulunur (ekrandan, 02:05:00):

$$EY = \int_{-\infty}^{+\infty} g(x)\,f_X(x)\,dx$$

Örnek olarak aynı yoğunluk için $EX^2$ hesaplandı. $x^2$ ile $x^{-3}$ çarpılınca $x^{-1}$ kalır ve $\int \frac{1}{x}\,dx = \ln x + C$ kullanılır (ekrandan, 02:10:00):

$$EX^2 = \int_1^{\infty} x^2 \cdot 2x^{-3}\,dx = \int_1^{\infty} 2x^{-1}\,dx = \left[2\ln x\right]_1^{\infty} = 2\ln(\infty) - 2\ln 1 = \infty$$

Bu örnekte $X^2$'nin beklenen değeri sonsuzdur; hoca bunun mümkün olduğunu belirtti.

### 8.4 Beklenen değer doğrusaldır

Beklenen değer doğrusal bir işlemdir (ekrandan, 02:15:00):

$$E(aX + b) = a\,EX + b \qquad \forall\, a, b \in \mathbb{R}$$

$$E(X_1 + X_2 + \dots + X_n) = EX_1 + EX_2 + \dots + EX_n$$

Bu özellikler bazı dağılımların beklenen değerini bulmayı kolaylaştırır: $X_1, \dots, X_n$'in beklenen değerleri kolayca bulunabiliyorsa toplamın beklenen değeri de bulunur. Hoca örnek olarak gamma dağılımını ve negatif binom dağılımını verdi. Gamma dağılımı üstel dağılımların toplamıdır; bu iki dağılım henüz işlenmedi ama ileride işlenecek ve gamma dağılımının beklenen değeri bu özellikle bulunabilecek.

## 9. Varyans

### 9.1 İki biçim

Varyansın kesikli dağılımlarda öğrenilen kanonik tanımı burada da geçerlidir. İki biçimi vardır (ekrandan, 02:20:00):

$$\text{Biçim I:}\quad \mathrm{Var}(X) = E\big((X - \mu_X)^2\big)$$

$$\text{Biçim II:}\quad \mathrm{Var}(X) = EX^2 - \mu_X^2$$

Biçim I varyansın ne olduğunu anlamak için daha yararlıdır: varyans, ortalamadan farkın karesinin beklenen değeridir. Biçim II hesap yapmak için daha kolaydır, çünkü beklenen değer zaten elde olur ve geriye yalnız $EX^2$'yi hesaplamak kalır. Uygulamada çoğunlukla biçim II kullanılacak.

Sürekli rastgele değişkenler için iki biçim integral olarak yazılır (ekrandan, 02:20:00):

$$\text{Biçim I:}\quad \mathrm{Var}(X) = \int_{-\infty}^{\infty} (x - \mu_X)^2 f_X(x)\,dx$$

$$\text{Biçim II:}\quad \mathrm{Var}(X) = \int_{-\infty}^{\infty} x^2 f_X(x)\,dx - \mu_X^2$$

### 9.2 Örnek (devam)

Aynı yoğunluk $f_X(x) = 2x^{-3}$ ($x \ge 1$) için $EX = 2$ ve $EX^2 = \infty$ bulunmuştu. Biçim II ile (ekrandan, 02:25:00):

$$\mathrm{Var}(X) = EX^2 - \mu_X^2 = \infty - 2^2 = \infty$$

Bu örnekte varyans sonsuzdur; bu da mümkündür.

### 9.3 Varyansın özellikleri

Hatırlatma olarak (ekrandan, 02:25:00):

- $\mathrm{Var}(aX + b) = a^2\,\mathrm{Var}(X)$. Bir sabitin varyansı sıfır olduğu için $b$ ifadede hiç görünmez.
- Genelde $X$ ve $Y$ rastgele değişkenleri için $\mathrm{Var}(X+Y) = \mathrm{Var}(X) + \mathrm{Var}(Y)$ yazılamaz. Bu eşitlik ancak bir koşul sağlanınca geçerlidir: $X$ ile $Y$ **bağımsız** olmalıdır.

$$X, Y \text{ bağımsız} \;\Rightarrow\; \mathrm{Var}(X+Y) = \mathrm{Var}(X) + \mathrm{Var}(Y)$$

## 10. Sürekli Rastgele Değişkenin Fonksiyonları

### 10.1 Genel yöntem

$X$ sürekli bir rastgele değişken ve $Y = g(X)$ ise $Y$ de bir rastgele değişkendir; onun da CDF'si, yoğunluğu ve diğer özellikleri bulunabilir (ekrandan, 02:30:00). Bunu yaparken genelde CDF'den başlamak daha kolaydır: CDF bulunursa türevi alınarak yoğunluk bulunur. Ama her şeyden önce değer kümesi bulunmalıdır. Adımlar (ekrandan, 02:35:00):

```text
1) R_Y'yi bul:  R_Y = { g(x) | f_X(x) > 0 }
2) F_Y(y) = P(Y <= y) = P(g(X) <= y)
3) f_Y(y) = d/dy F_Y(y)
```

İkinci adımda $y$ bilinen bir sayıdır; $g(X) \le y$ olayının olasılığı $X$ cinsinden yazılarak hesaplanır.

> **Ders sonrası not:** Ekranda birinci adım $\{g(x) \mid f(x) \ge 0\}$ olarak yazıldı (ekrandan, 02:30:00). Hoca sözlü olarak "sıfırdan büyük" dedi ve değer kümesini Bölüm 6'da $f_X(x) > 0$ ile tanımlamıştı. Doğrusu büyük olasılıkla $f_X(x) > 0$'dır; $\ge 0$ koşulu bütün gerçel sayılarda sağlanır.

### 10.2 Örnek: $X \sim \mathrm{Uniform}(0,1)$, $Y = e^X$

Problem (ekrandan, 02:35:00): $X \sim \mathrm{Uniform}(0,1)$ ve $Y = e^X$ olsun. (a) $F_Y(y) = ?$ (b) $f_Y(y) = ?$ (c) $EY = ?$

**$X$ hakkında bilinenler.** Bu, dersin başında görülen düzgün dağılımdır; $a = 0$, $b = 1$. Buna göre:

$$f_X(x) = \begin{cases} 0 & x < 0 \\ \dfrac{1}{1-0} = 1 & 0 \le x \le 1 \\ 0 & x > 1 \end{cases} \qquad F_X(x) = \begin{cases} 0 & x < 0 \\ \dfrac{x-0}{1-0} = x & 0 \le x \le 1 \\ 1 & x > 1 \end{cases}$$

Yoğunluk yalnız 0 ile 1 arasında sıfırdan büyüktür, başka her yerde sıfırdır; dolayısıyla $X$'in değer kümesi $[0,1]$'dir.

**Adım 1: $R_Y$.** Yalnız yoğunluğun pozitif olduğu $[0,1]$ aralığındaki değerlerle ilgilenilir; 0'dan önceki ve 1'den sonraki değerler değer kümesinde değildir. $g(x) = e^x$ artan olduğundan (ekrandan, 02:45:00):

$$R_Y = [g(0), g(1)] = [e^0, e^1] = [1, e]$$

**CDF'nin hazır parçaları.** Değer kümesinden hemen CDF'nin bazı değerleri yazılır: 1'den küçük $y$'ler için yoğunluk sıfır olduğundan $F_Y(y) = 0$, $e$'den büyük $y$'ler için $F_Y(y) = 1$. Soru, $1 \le y \le e$ için CDF'nin ne olduğudur (ekrandan, 02:45:00):

$$F_Y(y) = \begin{cases} 0 & y < 1 \\ ? & 1 \le y \le e \\ 1 & y > e \end{cases}$$

**Adım 2: aradaki parça.** CDF'nin tanımından başlanır:

$$F_Y(y) = P(Y \le y) = P(e^X \le y)$$

Bu doğrudan hesaplanamaz, çünkü elimizde $P(X \le x)$ biçiminde olasılıklar vardır; olasılığın içinde $X$'in bir fonksiyonu değil, $X$'in kendisi bulunmalıdır. Bunun için $g$'nin tersi uygulanır. $g$ üs alma olduğu için tersi logaritmadır; yani iki tarafın logaritması alınır (ekrandan, 02:50:00):

$$F_Y(y) = P(e^X \le y) = P(X \le \ln y) = F_X(\ln y) = \ln y$$

Son adımda $F_X(x) = x$ ($0 \le x \le 1$) kullanıldı; $1 \le y \le e$ iken $0 \le \ln y \le 1$ olduğu için bu parça geçerlidir.

**Sonuç (a):**

$$F_Y(y) = \begin{cases} 0 & y < 1 \\ \ln y & 1 \le y \le e \\ 1 & y > e \end{cases}$$

Kalan kısımları (yoğunluk ve beklenen değer) hoca "artık kolayca bulunur" diyerek eve bıraktı. Çözümleri Örnek Sorular bölümündedir.

## Örnek Sorular

**Soru 1** (ekrandan, 00:35:00): $[a,b]$ aralığından düzgün ve rastgele seçilen sayı $X$ olsun. $X$'in CDF'si ve PDF'si nedir?

> **Çözüm (derste verildi):** $F_X(x) = 0$ ($x < a$), $\dfrac{x-a}{b-a}$ ($a \le x \le b$), $1$ ($x > b$). Türev alınarak $f_X(x) = \dfrac{1}{b-a}$ ($a \le x \le b$), dışarıda 0.

**Soru 2** (ekrandan, 01:30:00): Bir elektronik bileşenin yıl cinsinden ömrü, $f_X(x) = k/x^3$ ($x \ge 1$), $0$ ($x < 1$) yoğunluklu sürekli bir rastgele değişkendir. (a) $k = ?$ (b) $F_X(x) = ?$ Grafiğini çizin. (c) P{ömrün 5 yılı aşması} = ?

> **Çözüm (a ve b derste verildi):** (a) $\int_1^{\infty} k x^{-3}\,dx = k/2 = 1 \Rightarrow k = 2$. (b) $F_X(x) = 1 - 1/x^2$ ($x > 1$), $0$ ($x \le 1$).

> **Çözüm (derste verilmedi):** (c) $P(X > 5) = \int_5^{\infty} 2x^{-3}\,dx = \left[-x^{-2}\right]_5^{\infty} = \dfrac{1}{25} = 0{,}04$. Aynı sonuç $1 - F_X(5) = 1 - 1/25$ ile de bulunur. Sonuç python ile sayısal integralle kontrol edildi.

**Soru 3** (ekrandan, 02:05:00 – 02:25:00): $f_X(x) = 2x^{-3}$ ($x \ge 1$) için $EX$, $EX^2$ ve $\mathrm{Var}(X)$ nedir?

> **Çözüm (derste verildi):** $EX = 2\int_1^{\infty} x^{-2}\,dx = 2$; $EX^2 = \int_1^{\infty} 2x^{-1}\,dx = \infty$; $\mathrm{Var}(X) = EX^2 - \mu_X^2 = \infty - 4 = \infty$.

**Soru 4** (ekrandan, 02:35:00): $X \sim \mathrm{Uniform}(0,1)$ ve $Y = e^X$ olsun. (a) $F_Y(y) = ?$ (b) $f_Y(y) = ?$ (c) $EY = ?$

> **Çözüm (a derste verildi):** $R_Y = [1, e]$; $F_Y(y) = 0$ ($y < 1$), $\ln y$ ($1 \le y \le e$), $1$ ($y > e$).

> **Çözüm (derste verilmedi):** (b) $f_Y(y) = \dfrac{d}{dy}\ln y = \dfrac{1}{y}$ ($1 \le y \le e$), dışarıda 0. Kontrol: $\int_1^e \frac{1}{y}\,dy = \ln e - \ln 1 = 1$. (c) $EY = \int_1^e y \cdot \dfrac{1}{y}\,dy = e - 1 \approx 1{,}718$. Aynı sonuç $EY = E\,e^X = \int_0^1 e^x\,dx = e - 1$ ile de bulunur. Python ile benzetim yapılarak kontrol edildi ($P(Y \le 2) \approx \ln 2 \approx 0{,}693$, ortalama $\approx 1{,}718$).

## Dersin Toparlaması

Bu derste kesikli olasılıktan sürekli olasılığa geçildi. Sürekli bir rastgele değişkende tek bir noktanın olasılığı sıfırdır; olasılıklar aralıklar ve kümeler üzerinden, yoğunluk fonksiyonunun integraliyle hesaplanır. CDF sürekli bir fonksiyondur, PDF onun türevidir, CDF de PDF'nin $-\infty$'dan $x$'e integralidir. Yoğunluk negatif olmaz, 1'i aşabilir ve bütün eksen üzerindeki integrali 1'dir. Düzgün dağılım ve $k/x^3$ yoğunluklu ömür örneği bu kuralları somutlaştırdı.

Kesikli durumdaki beklenen değer ve varyans tanımları toplamın integrale dönüşmesiyle aynen taşındı; beklenen değerin doğrusallığı ve bağımsız değişkenler için varyansın toplanabilirliği hatırlatıldı. $2x^{-3}$ örneğinde beklenen değerin sonlu, varyansın sonsuz olabileceği görüldü. Son olarak $Y = g(X)$ biçimindeki dönüşümlerin dağılımını bulmak için "önce değer kümesi, sonra CDF, sonra türevle yoğunluk" yöntemi $Y = e^X$ örneğiyle uygulandı. Hoca ileride üstel ve gamma dağılımlarının işleneceğini, gamma dağılımının beklenen değerinin doğrusallıkla bulunabileceğini söyledi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
