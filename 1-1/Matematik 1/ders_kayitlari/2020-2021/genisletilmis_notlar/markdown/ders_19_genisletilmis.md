# Ders 19 Genişletilmiş Notu: Belirli İntegralin Özellikleri, Kalkülüsün Temel Teoremi ve Kısmi İntegrasyon

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Belirli İntegralin Özellikleri
- 2. Min-Max Eşitsizliği ve Bir Uygulama
- 3. Kalkülüsün Temel Teoremi, 1. Kısım
- 4. İntegraller İçin Ortalama Değer Teoremi
- 5. Temel Teoremin İspatı ve Alan Fonksiyonu Yorumu
- 6. Temel Teorem ve L'Hôpital ile Limit Soruları
- 7. Kalkülüsün Temel Teoremi, 2. Kısım
- 8. Sınırları Değişkene Bağlı İntegralin Türevi
- 9. Temel Teorem ve Ters Fonksiyonun Türevi
- 10. Kısmi İntegrasyon
- 11. Tablo Yöntemi: Kısmi İntegrasyonun Kısaltılmış Hâli

## 1. Belirli İntegralin Özellikleri

Hoca derse ikinci vize ile ilgili bilgilendirmeyle başladı. Ardından belirli integralin özelliklerine (properties of definite integration) geçti. Ders İngilizce anlatıldı, yer yer Türkçe açıklamalar yapıldı. Hocanın internet bağlantısı ders boyunca kesik kesikti. Bu yüzden altyazının bazı kısımları anlaşılmıyor.

### 1.1 Belirli integralin tanımını hatırlama

Elimizde kapalı $[a,b]$ aralığında sürekli bir $f$ fonksiyonu olsun. Bu fonksiyonun $[a,b]$ üzerindeki belirli integrali, bir Riemann toplamının limiti olarak tanımlanmıştı:

$$\int_a^b f(x)\,dx = \lim_{n\to\infty}\sum_{k=1}^{n} f(x_k)\,\Delta x_k .$$

Hoca, belirli integrali alt Riemann toplamının ya da üst Riemann toplamının limiti olarak tanıttıklarını hatırlattı. Bunlardan birini yazmak yeterlidir. Genelde bütün $k$'lar için aynı genişlik seçilir:

$$\Delta x_k = \Delta x = \frac{b-a}{n}.$$

$n\to\infty$ iken $\Delta x_k$, $x$ ekseni boyunca sonsuz küçük farkı gösteren $dx$'e dönüşür.

### 1.2 Kural 1: Sınırların yer değiştirmesi

$$\int_b^a f(x)\,dx = -\int_a^b f(x)\,dx .$$

Hocanın gerekçesi şudur: $\Delta x = \dfrac{b-a}{n}$ ifadesinde $a$ ile $b$ yer değiştirirse $\Delta x$ işaret değiştirir. Toplamdaki her terim eksi işaret alır. Limitte de integral eksi işaret alır.

<!-- BELİRSİZ: 00:12:03 - 00:13:31 arasında altyazı döngüye giriyor ("bir süreçte bir süreçte ..."). Kural 1'in tahtaya yazılışı ve ilk açıklaması altyazıda anlaşılmıyor; kural, hemen sonraki sözlü anlatımdan kuruldu. -->

### 1.3 Kural 2: Alt ve üst sınır aynıysa

Kural 1'de $b = a$ yazılır:

$$\int_a^a f(x)\,dx = -\int_a^a f(x)\,dx \;\Longrightarrow\; 2\int_a^a f(x)\,dx = 0 \;\Longrightarrow\; \int_a^a f(x)\,dx = 0 .$$

Yani alt sınır ile üst sınırın aynı olduğu her belirli integral sıfırdır. Bu kural dersin ilerleyen kısmında limit sorularında sürekli kullanıldı: üst sınır $x$ olan bir integral, $x$ alt sınıra yaklaşınca sıfıra gider.

### 1.4 Kural 3: Sıralamanın korunması

$f$ ve $g$, $[a,b]$'de sürekli iki fonksiyon olsun ve bu aralıkta $f(x) \ge g(x)$ olsun. O zaman

$$\int_a^b f(x)\,dx \ge \int_a^b g(x)\,dx .$$

Hoca bu önermenin belirli integralin tanımından görülebileceğini söyledi: Riemann toplamlarında her terim aynı sırayı korur.

<!-- BELİRSİZ: 00:16:10 - 00:16:39 arası altyazıda tekrar eden anlamsız kelimeler var ("konusunda konusunda"). Kural 3'ün tam yazılışı sözlü kısımdan kuruldu. -->

**Özel durum ($g = 0$).** $[a,b]$'deki bütün $x$'ler için $g(x) = 0$ alınırsa: $f(x) \ge 0$ ise

$$\int_a^b f(x)\,dx \ge 0 .$$

Hoca bu integralin, $y = f(x)$ grafiğinin altında ve $[a,b]$ aralığının üstünde kalan bölgenin alanı olduğunu hatırlattı. Bu sonucu daha önceki derslerde göstermişlerdi.

### 1.5 Kural 4: Aralığın bölünmesi

$c \in [a,b]$ ise

$$\int_a^b f(x)\,dx = \int_a^c f(x)\,dx + \int_c^b f(x)\,dx .$$

Önce $a$'dan $c$'ye belirli integral hesaplanır. Sonra $c$'den $b$'ye hesaplanır. İki sonuç toplanınca $a$'dan $b$'ye integral elde edilir. Hoca bu sırada kuralların sayısını sayarken "Bu beş mi oldu? Beş." dedi; kısa notta ve burada kurallar yazılış sırasıyla numaralandı.

## 2. Min-Max Eşitsizliği ve Bir Uygulama

Hoca son kuralın çok önemli olduğunu söyledi.

> **Hocanın vurgusu:** Bu son kuralla (min-max eşitsizliği) ilgili test sınavında soru gelebilir.

**Min-max eşitsizliği.**

- $f$, $[a,b]$'de sürekli olsun.
- $\min f$ ve $\max f$, $f$'nin $[a,b]$ üzerindeki mutlak minimum ve maksimum değerleri olsun.
- O zaman:

$$(b-a)\cdot \min f \;\le\; \int_a^b f(x)\,dx \;\le\; (b-a)\cdot \max f .$$

<!-- BELİRSİZ: 00:21:10 - 00:21:38 arası altyazıda boşluk var. Hoca hemen ardından "This is not necessary condition" diyor; hangi koşulun gerekli olmadığını söylediği altyazıdan anlaşılmıyor. -->

### 2.1 Geometrik açıklama

Hoca, $[a,b]$ üzerinde pozitif değerli sürekli bir fonksiyonun grafiğini çizerek özel durumu açıkladı. $f$ kapalı aralıkta sürekli olduğu için bir yerde mutlak minimum değeri $\min f$'yi, bir yerde de mutlak maksimum değeri $\max f$'yi alır.

- Tabanı $b-a$, yüksekliği $\min f$ olan **küçük dikdörtgen** bölgenin içinde kalır.
- Tabanı $b-a$, yüksekliği $\max f$ olan **büyük dikdörtgen** bölgeyi içine alır.
- Grafiğin altındaki gerçek alan, küçük dikdörtgenin alanından büyük ya da eşit, büyük dikdörtgenin alanından küçük ya da eşittir.

Bu özellik, belirli integralin değeri için bir alt sınır ve bir üst sınır verir.

> **Ek bilgi (derste anlatılmadı):** $\min f$ ve $\max f$'nin var olduğunu garanti eden sonuç, uç değer teoremidir (extreme value theorem): Kapalı ve sınırlı bir aralıkta sürekli bir fonksiyon, o aralıkta mutlak minimum ve mutlak maksimum değerlerini alır. Hocanın derste "ön koşul" dediği süreklilik bu yüzden gereklidir.

### 2.2 Örnek 1: $\displaystyle\int_0^5 \sqrt{x^2+5}\,dx$ için alt ve üst sınır

**Soru.** $\displaystyle\int_0^5 \sqrt{x^2+5}\,dx$ belirli integralinin değeri için uygun bir alt ve üst sınır bulun.

Hoca, bu integrali kolayca hesaplayamadığımızı söyledi. Sorunun ruhu, integrali hesaplamak değil, değeri için alt ve üst sınır bulmaktır.

**Çözüm.**

- **Adım 1, süreklilik:** Kökün içi $x^2 + 5$ her zaman pozitiftir. Bu yüzden $f(x) = \sqrt{x^2+5}$ her yerde süreklidir, dolayısıyla $[0,5]$'te de süreklidir. Hoca bunun bir ön koşul olduğunu vurguladı: $\max f$ ve $\min f$'nin varlığından ancak bu sayede söz edebiliriz.
- **Adım 2, artanlık:** Türev (zincir kuralıyla):

$$f'(x) = \frac{2x}{2\sqrt{x^2+5}} = \frac{x}{\sqrt{x^2+5}} \ge 0 \quad (x \in [0,5]).$$

Yani $f$, $[0,5]$'te artandır.

- **Adım 3, uç değerler:**

$$\min f = f(0) = \sqrt{5}, \qquad \max f = f(5) = \sqrt{25+5} = \sqrt{30}.$$

- **Adım 4, eşitsizlik:** Taban $b - a = 5$'tir:

$$5\sqrt{5} \;\le\; \int_0^5 \sqrt{x^2+5}\,dx \;\le\; 5\sqrt{30}.$$

$5\sqrt{5}$ alt sınır, $5\sqrt{30}$ üst sınırdır.

Hoca artanlığı göstermeye çalışırken önce değer karşılaştırmasıyla ilerledi ve karıştı. Bir ara aralığın alt ucunu sıfır yerine bir yazmayı önerdi, $\frac{1}{2}$ ile $\frac{1}{3}$ noktalarındaki değerleri karşılaştırdı. Bir öğrenci "türevini alırsak?" diye sordu. Hoca bunu onayladı: türevin işaretine bakmak yeterlidir. Ardından "Uzattım ben. Şunu sıfır yapabilirsiniz, sıkıntı yok." diyerek aralığı yeniden $[0,5]$ olarak düzeltti.

<!-- BELİRSİZ: 00:28:18 - 00:31:10 arasındaki değer karşılaştırması (1/2 ve 1/3 noktaları, "kafam tanıma gitti") altyazıda tam takip edilemiyor; hangi fonksiyon değerlerinin karşılaştırıldığı net değil. -->

> **Ders sonrası not:** Hocanın tahtada söylediği türev ifadesi altyazıda "2x over 2 times x squared plus 5" olarak geçiyor; paydada kök eksik kalmış görünüyor. Doğrusu $f'(x) = \dfrac{x}{\sqrt{x^2+5}}$'tir. İşaret ($\ge 0$) ve sonuç değişmez. Sayısal kontrol: integralin değeri yaklaşık $17{,}55$'tir; bu değer $5\sqrt{5} \approx 11{,}18$ ile $5\sqrt{30} \approx 27{,}39$ arasındadır.

Hoca "Bu tarz sorular gelebilir arkadaşlar." diyerek konuyu kapattı.

## 3. Kalkülüsün Temel Teoremi, 1. Kısım

Hoca, integral için temel teoremin (fundamental theorem of calculus) iki kısımdan oluştuğunu söyledi ve birinci kısımla başladı.

**Temel Teorem, 1. Kısım.**

- $f$, $[a,b]$'de sürekli olsun.
- $F(x) = \displaystyle\int_a^x f(t)\,dt$, $x \in [a,b]$ olarak tanımlansın.
- O zaman $F$, $[a,b]$'de süreklidir ve $(a,b)$ açık aralığında türevlenebilirdir.
- Türevi:

$$F'(x) = \frac{d}{dx}\int_a^x f(t)\,dt = f(x).$$

Hoca integrandın değişkenini bilinçli olarak $t$ seçti: "Farklı bir değişken kullanayım, yoksa kafanızı karıştırabilir." İntegralin alt sınırı $a$, üst sınırı $x$'tir. $x$ belirli integralin tanımına üst sınır olarak girdiği için ortaya çıkan ifade $x$'e bağlıdır. Bu ifadenin $x$'e göre türevi alınınca, $x$ doğrudan integrandaki $t$'nin yerine yazılır ve cevap $f(x)$ olur.

Hoca ispat için önce integraller için ortalama değer teoremine ihtiyaç olduğunu söyledi.

<!-- BELİRSİZ: 00:37:04 - 00:37:34 arasında Türkçe açıklama altyazıda bozuk ("bu definiçin dekineşirmeyi yöntem bir"). -->

## 4. İntegraller İçin Ortalama Değer Teoremi

> **Hocanın vurgusu:** Bu teorem çok önemli. Çözümü bu teoreme dayanan sorular görebilirsiniz.

**İntegraller için ortalama değer teoremi (mean value theorem for integrals).**

- $f$, $[a,b]$'de sürekli olsun.
- O zaman öyle bir $c \in [a,b]$ vardır ki:

$$f(c) = \frac{1}{b-a}\int_a^b f(x)\,dx .$$

<!-- BELİRSİZ: 00:39:38 - 00:39:51 arası altyazıda boşluk var; c'nin ait olduğu aralığın tahtaya kapalı aralık olarak mı yazıldığı altyazıdan anlaşılmıyor. İspatta hoca c için x <= c <= x+h yazdığı için kapalı aralık alındı. -->

Eşitliğin sağ tarafına $f$'nin $[a,b]$ üzerindeki **ortalama değeri** (average value) denir.

> **Hocanın vurgusu:** Bu teoremi diferansiyel hesaptaki (türevler için) ortalama değer teoremiyle karıştırmayın. İki ayrı ortalama değer teoremi var: biri türevler için, biri integraller için. Buradaki sağ taraf ortalama değerdir, ortalama değişim oranı (average rate of change) değildir.

Hoca ortalama değer kavramını sonlu terimlerle açıkladı. Örneğin 10 sayının ortalamasını bulmak için toplamlarını 10'a bölersiniz. Kesikli (discrete) değişkenlerde ortalama, terimlerin toplamının terim sayısına bölümüdür. Sürekli fonksiyonlarda da ortalama değerden söz edilebilir: toplamın yerini integral, terim sayısının yerini aralık uzunluğu $b - a$ alır.

Türevler için ortalama değer teoreminde eşitliğin sağ tarafında ortalama değişim oranı vardı, ortalama hız gibi. Burada ise değişim oranı yoktur, ortalama değer vardır. Teorem, ortalama değerin $f$'nin bir $c$ noktasındaki değerine eşit olduğunu söyler.

## 5. Temel Teoremin İspatı ve Alan Fonksiyonu Yorumu

### 5.1 İspat

$F(x) = \displaystyle\int_a^x f(t)\,dt$ olsun. Türev tanımından başlanır:

$$F'(x) = \lim_{h\to 0}\frac{F(x+h) - F(x)}{h} = \lim_{h\to 0}\frac{1}{h}\left[\int_a^{x+h} f(t)\,dt - \int_a^{x} f(t)\,dt\right].$$

Hoca burada bir grafik çizdi. $y = f(t)$, $[a,b]$ üzerinde sürekli bir fonksiyon olsun ve yatay eksen $t$ ekseni olsun.

- $a$'dan $x$'e kadar grafiğin altındaki bölgenin alanı $F(x)$'tir.
- $a$'dan $x + h$'ye kadar olan bölgenin alanı $F(x+h)$'tir.
- $F(x+h) - F(x)$ farkı, $x$ ile $x+h$ arasında kalan ince şeridin alanıdır. Hoca bu şeridi siyah renkle taradı.

Bu fark aslında $x$'ten $x + h$'ye integraldir:

$$F(x+h) - F(x) = \int_x^{x+h} f(t)\,dt .$$

Böylece

$$F'(x) = \lim_{h\to 0}\;\underbrace{\frac{1}{h}\int_x^{x+h} f(t)\,dt}_{\text{kutu}} .$$

Hoca "Bu kadar basit mi diyeceksiniz, ama burayı anlamaya çalışın." dedi. Kutunun içindeki ifade, $f$'nin $[x, x+h]$ aralığındaki ortalama değeridir (aralığın uzunluğu $h$'dir). İntegraller için ortalama değer teoremine göre öyle bir $c$ vardır ki

$$x \le c \le x + h \quad\text{ve}\quad \frac{1}{h}\int_x^{x+h} f(t)\,dt = f(c).$$

Dolayısıyla $F'(x) = \displaystyle\lim_{h\to 0} f(c)$. $h \to 0$ iken $c$, $x$ ile $x+h$ arasına sıkıştığı için $c \to x$ olur. $f$ sürekli olduğundan $f(c) \to f(x)$. Sonuç:

$$F'(x) = f(x).$$

> **Ders sonrası not:** İspatta hoca "average value of f over a, b" diyor, hemen ardından düzeltip $[x, x+h]$ aralığını söylüyor. Kutudaki ifade $[x, x+h]$ üzerindeki ortalama değerdir. Ayrıca $h < 0$ için de aynı akıl yürütme $[x+h, x]$ aralığıyla yapılır; ders yalnız $h > 0$ resmini çizdi.

### 5.2 Alan fonksiyonu yorumu

Hoca teoremin anlamını şöyle açıkladı. $F(x)$ bir **alan fonksiyonudur** (area function). Bahsedilen bölge, yüksekliği $f(t)$ olan sonsuz sayıda ince çubuğun yan yana dizilmesiyle oluşur. Bu şekilde oluşan bölgenin alanını veren fonksiyonun türevini alırsanız, bölgeyi meydana getiren yeterince ince bir çubuğun yüksekliğini, yani $f(x)$'i bulursunuz.

> **Hocanın vurgusu:** Bütünden parçaya, parçadan bütüne gidiyoruz. Alanın türevini alınca alanı meydana getiren parçayı, $f(x)$'i bulursunuz. Temel teorem 1 bunu söyler.

Hoca bunu bir benzetmeyle de anlattı: "Süt ve sütün türevleri" deriz. Sütün türevleri sütten elde edilen ürünlerdir. Türev kavramı da bunun gibi bütünün parçasını verir. Hocaya göre "derivation" kelimesini "türev" diye çevirenler doğru bir çeviri yapmıştır. İşin mantığını anlarsanız formülleri ezberlemek zorunda kalmazsınız.

### 5.3 Örnek 2: Temel teorem 1. kısmın doğrudan uygulanışı

**(a)** $F(x) = \displaystyle\int_2^x \sin(t^2 + t)\,dt$ ise

$$F'(x) = \frac{d}{dx}\int_2^x \sin(t^2+t)\,dt = \sin(x^2 + x).$$

Hoca burada tutarlılığa dikkat çekti: Türevi $x$'e göre alıyoruz ve üst sınır da $x$. İkisi arasında tutarlılık (consistency) olmalı. Bu sağlandığında $x$ doğrudan integranda $t$'nin yerine yazılır.

**(b)** $F(m) = \displaystyle\int_0^m \ln(x^2 + x)\,dx$ ise $F$'nin değişkeni $m$'dir ve

$$F'(m) = \frac{d}{dm}\int_0^m \ln(x^2+x)\,dx = \ln(m^2 + m).$$

Bu örnekte integrandın değişkeni $x$, alan fonksiyonunun değişkeni $m$'dir. Kural aynıdır: $m$ doğrudan integranda yerine yazılır.

> **Ders sonrası not:** $\ln(x^2 + x)$ yalnız $x > 0$ ya da $x < -1$ için tanımlıdır; $x = 0$'da tanımsızdır. Bu yüzden alt sınırı $0$ olan bu integral büyük olasılıkla has olmayan (improper) bir integral olarak düşünülmelidir. Hoca örneği yalnız temel teoremin uygulanışını göstermek için yazdı; $m > 0$ için $F'(m) = \ln(m^2+m)$ sonucu geçerlidir.

## 6. Temel Teorem ve L'Hôpital ile Limit Soruları

> **Hocanın vurgusu:** Böyle bir soruyu sınavda görebilirsiniz. Bu çok önemli bir soru.

### 6.1 Örnek 3: $\displaystyle\lim_{x\to 0}\frac{1}{x^2}\int_0^x \sin(t^2+t)\,dt$

Hoca soruyu önce $\dfrac{1}{x}\displaystyle\int_0^x \sin(t^2+t)\,dt$ biçiminde yazdı. Çözüm sırasında, soruyu öncekinden daha karmaşık yapmak için paydayı $x^2$ olarak değiştirdi.

**Adım 1, belirsizlik türü.** $\dfrac{1}{x^2}$ terimi sonsuza (ya da eksi sonsuza) gider. $x \to 0$ iken üst sınır $0$'a yaklaşır. Alt ve üst sınır aynı olduğunda integral $0$ olduğu için (Kural 2) integral $0$'a gider. Belirsizlik "$\infty \cdot 0$" biçimindedir.

**Adım 2, düzenleme.** L'Hôpital kuralını uygulamak için ifade kesir hâline getirilir:

$$\lim_{x\to 0}\frac{\displaystyle\int_0^x \sin(t^2+t)\,dt}{x^2}.$$

Şimdi pay ve payda $0$'a gider: $\dfrac{0}{0}$ belirsizliği. Hoca limit değişkeninin $x$ olduğuna ve üst sınırın da $x$ olduğuna dikkat çekti.

**Adım 3, L'Hôpital ve temel teorem 1. kısım.** Payın türevi temel teoremle bulunur, paydanın türevi $2x$'tir:

$$\lim_{x\to 0}\frac{\sin(x^2+x)}{2x}.$$

Yine $\dfrac{0}{0}$ belirsizliği vardır.

**Adım 4, ikinci L'Hôpital.** $\sin(x^2+x)$'in türevi zincir kuralıyla $\cos(x^2+x)\,(2x+1)$'dir. Paydanın türevi $2$'dir:

$$\lim_{x\to 0}\frac{\cos(x^2+x)\,(2x+1)}{2} = \frac{\cos 0 \cdot 1}{2} = \frac{1}{2}.$$

**Sonuç:** $\dfrac{1}{2}$.

Paydası $x$ olan ilk hâlinde tek bir L'Hôpital yeterli olurdu: $\displaystyle\lim_{x\to 0}\frac{\sin(x^2+x)}{1} = 0$ (ara adım eklendi).

Hoca çözümden sonra temel teoremin mantığını bir kez daha özetledi: $f$ sürekliyse $\displaystyle\int_a^x f(t)\,dt$ bir alan fonksiyonudur; türevi, bölgeyi oluşturan ince çubukların yüksekliğini verir.

### 6.2 Örnek 4 (alıştırma): $\displaystyle\lim_{x\to 0}\frac{1}{\sin^2 x}\int_0^x e^{t^2}\,dt$

Hoca bu soruyu öğrencilere alıştırma olarak verdi, ardından 15-20 dakikalık bir ara verildi (01:02:16 - 01:21:15). Aradan sonra birlikte çözüldü.

**Adım 1.** $x \to 0$ iken $\displaystyle\int_0^x e^{t^2}\,dt \to 0$, çünkü alt ve üst sınır aynı değere gider. $\sin^2 x \to 0$. Belirsizlik $\dfrac{0}{0}$.

**Adım 2, L'Hôpital.** Pay temel teoremle türetilir: $x$ doğrudan integranda yerine yazılır, $e^{x^2}$ olur. Paydanın türevi zincir kuralıyla $2\sin x\cos x$'tir:

$$\lim_{x\to 0}\frac{e^{x^2}}{2\sin x\cos x}.$$

**Adım 3.** $x \to 0$ iken pay $e^0 = 1$'e gider. Payda $0$'a gider: sağdan $0^+$, soldan $0^-$. Bu yüzden ifade sağdan $+\infty$'a, soldan $-\infty$'a gider.

**Sonuç: Limit yoktur.**

Hoca öğrencilere "Sin kare x yaptık orayı. Dikkat edin. Bir bölü sinüs x değil." diyerek paydanın $\sin^2 x$ olduğunu hatırlattı.

## 7. Kalkülüsün Temel Teoremi, 2. Kısım

**Temel Teorem, 2. Kısım.**

- $f$, $[a,b]$'de sürekli bir fonksiyon olsun.
- $F$, $f$'nin bir ters türevi (antiderivative) olsun: $F'(x) = f(x)$.
- O zaman:

$$\int_a^b f(x)\,dx = F(b) - F(a).$$

<!-- BELİRSİZ: 01:26:13 - 01:27:42 arası altyazıda boşluklar var; teoremin tahtadaki yazılışı ("from a to b f' x dx") sözlü parçalardan kuruldu. -->

> **Hocanın vurgusu:** Bu teorem çok önemli. İspatı size ödev.

### 7.1 Örnek 5: $\sqrt{x}$'in belirli integrali

Önce belirsiz integral hesaplanır, yani $\sqrt{x}$'in bir ters türevi aranır:

$$\int \sqrt{x}\,dx = \frac{2}{3}x^{3/2} + C.$$

Hoca belirli integralde $C$ yazmaya gerek olmadığını söyledi; $C$ çıkarma işleminde birbirini götürür. Sınırlar yerine yazılınca cevap $\dfrac{2}{3}$ çıktı. Bu cevap $[0,1]$ aralığına karşılık gelir:

$$\int_0^1 \sqrt{x}\,dx = \left[\frac{2}{3}x^{3/2}\right]_0^1 = \frac{2}{3} - 0 = \frac{2}{3}.$$

<!-- BELİRSİZ: Altyazıda Örnek 5'in sınırları sözlü olarak geçmiyor; yalnız sonuç (2/3) geçiyor. Sınırlar kısa nottan ve sonuçla tutarlılıktan alındı. -->

### 7.2 Örnek 6: $\cos x$'in belirli integrali

$\cos x$'in ters türevi $\sin x$'tir. Temel teorem 2. kısma göre üst ve alt sınır yerine yazılır, cevap $0$ çıkar:

$$\int_0^{\pi}\cos x\,dx = \Big[\sin x\Big]_0^{\pi} = \sin\pi - \sin 0 = 0.$$

<!-- BELİRSİZ: Örnek 6'nın sınırları altyazıda geçmiyor; yalnız "the answer is 0" geçiyor. [0, pi] sınırları kısa nottan alındı. -->

## 8. Sınırları Değişkene Bağlı İntegralin Türevi

Hoca bu sonucu temel teorem 1. kısmın genelleştirmesi (bir "remark") olarak verdi.

**Genelleştirme.**

- $f$ sürekli, $u$ ve $v$ türevlenebilir fonksiyonlar olsun.
- $F(x) = \displaystyle\int_{u(x)}^{v(x)} f(t)\,dt$ olsun.
- O zaman:

$$F'(x) = f\big(v(x)\big)\,v'(x) - f\big(u(x)\big)\,u'(x).$$

Sözle: Üst sınır integranda yerine yazılır ve üst sınırın türeviyle çarpılır; alt sınır integranda yerine yazılır, alt sınırın türeviyle çarpılır ve çıkarılır.

### 8.1 İspat

$G$, $f$'nin bir ters türevi olsun: $G' = f$. Temel teorem 2. kısımdan

$$F(x) = \int_{u(x)}^{v(x)} f(t)\,dt = G\big(v(x)\big) - G\big(u(x)\big).$$

Her iki tarafın türevi zincir kuralıyla alınır:

$$F'(x) = G'\big(v(x)\big)\,v'(x) - G'\big(u(x)\big)\,u'(x) = f\big(v(x)\big)\,v'(x) - f\big(u(x)\big)\,u'(x).$$

> **Hocanın vurgusu:** Bu formülü ezberlemenize gerek yok. İspatını anlarsanız bu formülü saniyeler içinde çıkarırsınız; zihninize oturur.

Hoca ispatı ders içinde iki kez anlattı: önce genelleştirmeyi verirken, sonra Örnek 9'dan sonra tekrar.

### 8.2 Örnek 7: $\dfrac{d}{dx}\displaystyle\int_{x^2}^{\sin x} e^{t^2}\,dt$

Üst sınır $v(x) = \sin x$, alt sınır $u(x) = x^2$, integrand $f(t) = e^{t^2}$.

- Üst sınır integranda yerine yazılır ve türeviyle çarpılır: $e^{\sin^2 x}\cdot(\sin x)' = e^{\sin^2 x}\cos x$.
- Alt sınır integranda yerine yazılır ve türeviyle çarpılır: $e^{(x^2)^2}\cdot(x^2)' = e^{x^4}\cdot 2x$.

**Doğru sonuç:**

$$\frac{d}{dx}\int_{x^2}^{\sin x} e^{t^2}\,dt = e^{\sin^2 x}\cos x - 2x\,e^{x^4}.$$

> **Ders sonrası not:** Hoca alt sınır için "exponential x squared times derivation of x" dedi ve sonucu $e^{\sin^2 x}\cos x - e^{x^2}$ olarak verdi. Burada alt sınır $x^2$ değil $x$ gibi yerine konmuş. Doğrusu: $t$ yerine $x^2$ yazılır, $e^{(x^2)^2} = e^{x^4}$ olur ve $(x^2)' = 2x$ ile çarpılır. Doğru sonuç $e^{\sin^2 x}\cos x - 2x\,e^{x^4}$'tür (sympy ile doğrulandı).

### 8.3 Örnek 8: $\displaystyle\lim_{x\to 0}\frac{1}{x^2 - x}\int_{\sin x}^{1-\cos x} t^2\,dt$

Hoca önce integranda tanjant yazmayı düşündü, sonra "sıkıntı olur" diyerek vazgeçti ve $t^2$ yazdı. Soruları kafasından yazdığı için güzel sonuçlar gelmeyebileceğini de ekledi.

**Adım 1.** $x \to 0$ iken $\sin x \to 0$ ve $1 - \cos x \to 0$. İki sınır da $0$'a gider, integral $0$'a gider. $x^2 - x \to 0$. Belirsizlik $\dfrac{0}{0}$.

**Adım 2, L'Hôpital ve genelleştirme.** Pay için: üst sınır integranda yerine yazılır, türeviyle çarpılır; alt sınır için aynısı yapılıp çıkarılır. Paydanın türevi $2x - 1$'dir:

$$\lim_{x\to 0}\frac{(1-\cos x)^2\cdot(1-\cos x)' - \sin^2 x\cdot(\sin x)'}{2x-1} = \lim_{x\to 0}\frac{(1-\cos x)^2\sin x - \sin^2 x\cos x}{2x-1}.$$

**Adım 3.** Hoca önce limiti parçalara ayırmaya başladı, sonra "Gerçi $x$ yerine sıfır yazarsak direkt geliyor, yapmamıza gerek yokmuş." dedi. Doğrudan $x = 0$ yazılınca pay $0 \cdot 0 - 0 \cdot 1 = 0$, payda $-1$ olur. Belirsizlik yoktur.

**Sonuç:** $\dfrac{0}{-1} = 0$.

**Soru:** $(1 - \cos x)$'in karesinin türevini neden almıyoruz, o $2$'yi başa atmamız gerekmiyor mu?
**Cevap:** Hoca önce temel teoremin uygulandığını hatırlattı. Temel teorem uygulanırken integrand $t^2$'ye üst sınır yazılıyor ve yalnız **üst sınırın** türeviyle, yani $(1-\cos x)' = \sin x$ ile çarpılıyor. $t^2$'nin kendisi türetilmez. Bundan sonra belirsizlik kalmadığı için doğrudan $x = 0$ yazılır.

**Soru:** Sıfıra sağdan ve soldan yaklaşırsak sonuç farklı çıkmaz mı?
**Cevap:** Burada çıkmaz. Sonuç doğrudan $0$ geliyor, sıfıra bölme yok. Başka sorularda çıkabilir, ama burada çıkmaz.

### 8.4 Örnek 9: $\dfrac{d}{dx}\displaystyle\int_{x^2}^{\sin x} \tan t\,dt$

Üst sınır $\sin x$ integranda yerine yazılır ve türeviyle çarpılır, alt sınır $x^2$ için aynısı yapılıp çıkarılır:

$$\frac{d}{dx}\int_{x^2}^{\sin x}\tan t\,dt = \tan(\sin x)\cos x - \tan(x^2)\cdot 2x.$$

Hoca "Cevap bu. Daha fazla devam etmenize gerek yok." dedi.

<!-- BELİRSİZ: 01:42:32 civarında hoca alt sınır terimini yalnız "tangent x squared" diye söylüyor; (x^2)' = 2x çarpanını söyleyip söylemediği altyazıdan anlaşılmıyor. Sonuç genelleştirme formülüne göre yazıldı (sympy ile doğrulandı). -->

### 8.5 Örnek 10 (alıştırma): $\displaystyle\lim_{x\to 0}\frac{1}{x^2}\int_{x}^{x^2}\frac{t^2-1}{t^2+1}\,dt$

Hoca "Herkes kendisi çözsün bunu." diyerek bu soruyu alıştırma olarak verdi. Öğrencilerden cevap gelmeyince "Bir kere L'Hôpital falan geliyor, biraz uğraştırır sanki." dedi ve cevabın sonsuz ya da eksi sonsuz olacağını, yani limit olmadığını önceden söyledi.

<!-- BELİRSİZ: Soru 01:45:01 - 01:45:34 arasında tahtaya yazılırken altyazı bozuk ("has exposed to 0 from extra from"). Integrand, sınırlar ve payda, çözümde söylenen L'Hôpital adımlarından kuruldu: üst sınır x^2, alt sınır x, integrand (t^2-1)/(t^2+1), payda x^2. -->

**Adım 1.** $x \to 0$ iken iki sınır da $0$'a gider. Hoca: "From $A$ to $A$ integral $0$; burada $A$ sıfır." Payda $x^2 \to 0$. Belirsizlik $\dfrac{0}{0}$.

**Adım 2, L'Hôpital ve genelleştirme.**

$$\lim_{x\to 0}\frac{\dfrac{x^4-1}{x^4+1}\cdot 2x - \dfrac{x^2-1}{x^2+1}\cdot 1}{2x}.$$

Hoca önce payı düzenlemeye başladı ($2x^5 - 2x$ gibi terimler) ve işlem kalabalığı oluştuğunu söyledi.

**Soru:** Direkt sıfırı yerine yazsanız olmaz mı?
**Cevap:** Evet. Hoca belirsizlik gelir diye düzenlemek istediğini, ama doğrudan yazmanın yeterli olduğunu söyledi. "Siz daha iyi görüyorsunuz" diyerek öneriyi onayladı.

**Adım 3, doğrudan yerine koyma.** $x \to 0$ iken:

- $\dfrac{x^4-1}{x^4+1}\cdot 2x \to (-1)\cdot 0 = 0$,
- $\dfrac{x^2-1}{x^2+1}\cdot 1 \to -1$,
- pay $\to 0 - (-1) = 1$,
- payda $2x \to 0^{+}$ ya da $0^{-}$.

Sağdan ifade $+\infty$'a, soldan $-\infty$'a gider.

**Sonuç: Limit yoktur.**

> **Ders sonrası not:** Hoca İngilizce anlatımda "minus 1 over 0 plus or 0 minus" dedi. Pay $-1$'e değil $+1$'e gider: $(-1)\cdot 0 - (-1) = 1$. Türkçe kısımda hoca da öğrenci de "bir bölü sıfır" demişti; doğrusu budur. Sonuç değişmez: limit yoktur (sympy ile doğrulandı: sağdan $+\infty$, soldan $-\infty$).

## 9. Temel Teorem ve Ters Fonksiyonun Türevi

### 9.1 Örnek 11

**Soru.** $f(x) = \displaystyle\int_1^{e^x}\frac{1}{\sqrt{1+t^2}}\,dt$ veriliyor. $(f^{-1})'(0)$ değerini bulun.

Hoca ters fonksiyonun türevinin birinci vizenin konusu olduğunu, ama ikinci vize konularıyla birleştirilebileceğini söyledi.

> **Hocanın vurgusu:** Birinci ve ikinci vizenin konuları harmanlanabilir; bu yüzden birinci vize konularını bilmeniz önemli. Bu tarz soruların gelme ihtimali çok yüksek. Formülü unutsanız bile mantığını kavradıysanız 5 saniyede çıkarırsınız.

Öğrenciler bir süre uğraştı. Bir öğrenci cevabın sıfır olduğunu önerdi; hoca "Hayır, sıfır değil." dedi ve birlikte çözdüler.

**Adım 1, ters fonksiyonun türevi formülü.** Formülü unuttuğunuzu varsayın. Ters fonksiyon özelliğinden $f^{-1}\big(f(x)\big) = x$'tir. İki tarafın türevi zincir kuralıyla alınır:

$$(f^{-1})'\big(f(x)\big)\cdot f'(x) = 1 .$$

$x = x_0$ yazılırsa:

$$(f^{-1})'\big(f(x_0)\big) = \frac{1}{f'(x_0)}, \qquad f'(x_0) \ne 0 .$$

**Adım 2, $x_0$'ı bulma.** Formüle göre $f(x_0) = 0$ olmalıdır:

$$f(x_0) = \int_1^{e^{x_0}}\frac{1}{\sqrt{1+t^2}}\,dt = 0 .$$

Alt sınır $1$'dir. Hangi $x_0$ için üst sınır da $1$ olur? Alt ve üst sınır aynı olunca integral $0$ olur. Bu yüzden $e^{x_0} = 1$, yani $x_0 = 0$.

**Adım 3, $f'(x)$.** Genelleştirme formülü kullanılır. Alt sınır sabit olduğu için türevi $0$'dır ve o terim düşer:

$$f'(x) = \frac{1}{\sqrt{1+(e^x)^2}}\cdot e^x - \frac{1}{\sqrt{2}}\cdot 0 = \frac{e^x}{\sqrt{1+e^{2x}}}.$$

**Adım 4.**

$$f'(0) = \frac{1}{\sqrt{1+1}} = \frac{1}{\sqrt{2}} .$$

**Adım 5, sonuç.**

$$(f^{-1})'(0) = \frac{1}{f'(0)} = \sqrt{2}.$$

<!-- BELİRSİZ: 01:59:42 - 02:00:34 arasında hoca önce "the answer is 1 over square root of 2" diyor (bu f'(0) değeri), ardından bağlantı sorunu oluyor ve son adım ("F'x0'a 1'a 2'a") altyazıda anlaşılmıyor. -->

> **Ders sonrası not:** Altyazıda "the answer is 1 over square root of 2" geçiyor; bu değer $f'(0)$'dır. İstenen $(f^{-1})'(0)$, bunun tersi olan $\sqrt{2}$'dir (sympy ile doğrulandı). İkisini karıştırmayın.

## 10. Kısmi İntegrasyon

Hoca, temel teoremlerin anlaşılıp anlaşılmadığını sorduktan sonra kısmi integrasyona (integration by parts) geçti. Bazı kişilerin bu yönteme "partial integration" dediğini de söyledi. Türkçesi **kısmi integrasyondur**.

### 10.1 Formülün çıkarılışı

$u$ ve $v$ türevlenebilir iki fonksiyon olsun. Türev için çarpım kuralından:

$$d(uv) = v\,du + u\,dv .$$

İki tarafın integrali alınır:

$$\int d(uv) = \int v\,du + \int u\,dv .$$

Hoca burada integralin ruhunu hatırlattı. Sol tarafta $u \cdot v$ ile temsil edilen bütün bir nesne var. $d(uv)$'ler, $uv$'nin yeterince küçük parçalarıdır. Sonsuz sayıdaki $d(uv)$'yi toplarsak, yani integre edersek, birbirine kaynaştırırsak bütünü, $uv$'yi elde ederiz:

$$uv = \int v\,du + \int u\,dv .$$

Hoca "Burada yaptığım bir şey yok." diyerek adımların basitliğini vurguladı. $\int u\,dv$ yalnız bırakılınca kısmi integrasyon formülü çıkar:

$$\int u\,dv = uv - \int v\,du .$$

> **Hocanın vurgusu:** Bu formülü ezberlemenize gerek yok. Türev için çarpım kuralını biliyorsanız formülü hemen çıkarırsınız.

### 10.2 $u$ seçimi

Hoca, integrandın iki farklı türden fonksiyonun çarpımı olduğu durumu ele aldı. Üç fonksiyon sınıfından söz etti:

- $P$: polinom fonksiyonlar (polynomial),
- $T$: trigonometrik fonksiyonlar (trigonometric),
- $E$: üstel fonksiyonlar (exponential).

Hoca bu sıralamayı unutmamak gerektiğini söyledi. Sıralamada önce gelen harfe karşılık gelen fonksiyon $u$ seçilir. Polinom ile üstel fonksiyonun çarpımında $P$, $E$'den önce geldiği için polinom $u$, geri kalan kısım $dv$ olur.

<!-- BELİRSİZ: 02:09:17 - 02:09:41 arasında hoca sıralamanın adını söylüyor ("Lap t" gibi duyuluyor); tahtadaki sıralamanın tam hâli altyazıdan anlaşılmıyor. -->

> **Ek bilgi (derste anlatılmadı):** Ders kitaplarında $u$ seçimi için yaygın bir kural LIATE kuralıdır: Logaritmik, ters (inverse) trigonometrik, cebirsel (algebraic, polinom), trigonometrik, üstel (exponential). Listede önce gelen $u$ seçilir. Hocanın söylediği $P$, $T$, $E$ sırası bu kuralın son üç adımına karşılık gelir. Kural kesin bir yasa değil, büyük olasılıkla işe yarayan bir pratik yoldur.

### 10.3 Örnek 12: $\displaystyle\int x e^x\,dx$

Polinom ile üstel fonksiyonun çarpımı. $P$ önce geldiği için:

- $u = x \;\Rightarrow\; du = dx$,
- $dv = e^x\,dx \;\Rightarrow\; v = \displaystyle\int e^x\,dx = e^x$ (iki tarafın integrali alınır).

Formüle yerleştirilir:

$$\int x e^x\,dx = x e^x - \int e^x\,dx = x e^x - e^x + C = e^x(x - 1) + C .$$

### 10.4 Örnek 13: $\displaystyle\int x^2 e^x\,dx$

Hoca "Bir tane daha çözelim. Basitleştireceğim şimdi, bu kadar uzun sürmeyecek. Ama önce genel yoldan öğrenelim." dedi.

- $u = x^2 \;\Rightarrow\; du = 2x\,dx$,
- $dv = e^x\,dx \;\Rightarrow\; v = e^x$.

$$\int x^2 e^x\,dx = x^2 e^x - \int e^x\cdot 2x\,dx = x^2 e^x - 2\int x e^x\,dx .$$

Kalan integral için kısmi integrasyon tekrar uygulanır. Bu integral Örnek 12'de çözülmüştü: $\displaystyle\int x e^x\,dx = e^x(x-1) + C$. Yerine yazılır:

$$\int x^2 e^x\,dx = x^2 e^x - 2e^x(x-1) + C = e^x\left(x^2 - 2x + 2\right) + C .$$

Son sadeleştirme (ara adım eklendi).

## 11. Tablo Yöntemi: Kısmi İntegrasyonun Kısaltılmış Hâli

### 11.1 Fikir

Örnek 13'teki hesaplamada $u$ olarak hep polinomun türevi alınıyor, $dv$ olarak hep $e^x$'in integrali alınıyordu. Hocanın amacı bu hesaplamaları basitleştirmekti.

- **Türev sütunu:** $x^2$ adım adım türetilir. Sıfırıncı mertebe türev fonksiyonun kendisidir: $x^2$. Birinci mertebe $2x$, ikinci mertebe $2$, üçüncü mertebe $0$.
- **İntegral sütunu:** $e^x$ adım adım integre edilir: $e^x, e^x, e^x, \dots$

Türev sütununda $0$ elde ederseniz "şanslısınız" demektir. Bu durumda basitleştirilmiş yöntem uygulanabilir.

<!-- BELİRSİZ: 02:15:01 - 02:15:52 arası ("Şimdi bu devletin") ve 02:18:12 civarındaki döngü ("İntegration, İntegration, ...") altyazıda anlaşılmıyor; tablonun tahtadaki çizimi sözlü anlatımdan kuruldu. -->

### 11.2 İşaretlerin kaynağı

Kısmi integrasyon formülü $\displaystyle\int u\,dv = uv - \int v\,du$'da $uv$ teriminin katsayısı $+$, $\displaystyle\int v\,du$ teriminin katsayısı $-$'dir. Formül her tekrar uygulandığında bu işaretler birbirini izler. Bu yüzden tabloda çapraz çarpımların işaretleri $+, -, +, -, \dots$ diye gider.

Örnek 13 tablo ile:

| İşaret | Türev sütunu ($u$) | İntegral sütunu ($dv$) |
|---|---|---|
| $+$ | $x^2$ | $e^x$ |
| $-$ | $2x$ | $e^x$ |
| $+$ | $2$ | $e^x$ |
| | $0$ | $e^x$ |

Her satırdaki türev, bir alt satırdaki integralle çapraz çarpılır ve satırın işaretini alır:

$$\int x^2 e^x\,dx = +x^2 e^x - 2x\,e^x + 2e^x + C .$$

Bu, Örnek 13'teki sonuçla aynıdır.

<!-- BELİRSİZ: 02:18:54 civarında hoca ikinci terimi "minus exponential 2x times exponential x" diye okuyor; kastedilen 2x e^x terimidir. -->

### 11.3 Ayrı bir yöntem mi?

> **Hocanın vurgusu:** Bazı kitaplar buna tablo yöntemi (tabular method) diye ayrı bir konu olarak anlatıyor. Bu kesinlikle ayrı bir yöntem değildir. Kısmi integrasyonun basitleştirilmiş hâlidir, özel bir durumudur.

Hoca bu yöntemin her zaman uygulanamayacağını vurguladı. Uygulanabilmesi için iki koşul gerekir:

- $u$'nun türevleri belli bir adımdan sonra $0$ olmalı (polinomlarda olduğu gibi),
- $dv$'nin ardışık integralleri kolay alınabilmeli ($e^x$'in integrali hep $e^x$ gelir).

Böyle durumlarda bu basitleştirilmiş hâl uygulanabilir. Hoca sonradan "Biz de bundan sonra tabular yöntem diyelim, ama farklı bir yöntem değil, onu bilin." dedi. İleride diferansiyel denklemler dersinde bu tür integrallerle çok karşılaşılacağı için bu kısa yolu anlattığını söyledi.

**Soru:** Şu an Türkçe olarak kısmi integral mi işliyoruz?
**Cevap:** Evet, kısmi integrasyon. $\displaystyle\int u\,dv = uv - \int v\,du$. $u$'ların türevi alındığında sıfırlanıyorsa ve $dv$'lerin integralleri kolay alınıyorsa kısmi integrasyon basitleştirilebilir. Bir türev sütunu ve bir integral sütunu açılır. $uv$'lerin katsayısı artı, $\int v\,du$'ların katsayısı eksi olduğu için işaretler artı, eksi, artı, eksi diye gider. Sütunlar çapraz çarpılır, işaretlere dikkat edilir. Aslında kısmi integrasyon hızlı bir şekilde uygulanmış olur.

### 11.4 Örnek 14: $\displaystyle\int x^5 e^x\,dx$

| İşaret | Türev sütunu | İntegral sütunu |
|---|---|---|
| $+$ | $x^5$ | $e^x$ |
| $-$ | $5x^4$ | $e^x$ |
| $+$ | $20x^3$ | $e^x$ |
| $-$ | $60x^2$ | $e^x$ |
| $+$ | $120x$ | $e^x$ |
| $-$ | $120$ | $e^x$ |
| | $0$ | $e^x$ |

Türev yönünde aşağı doğru türev, integral yönünde aşağı doğru integral alınır. $0$ elde edildiği için "şanslıyız". $e^x$ ortak çarpan olarak dışarı alınır:

$$\int x^5 e^x\,dx = e^x\left(x^5 - 5x^4 + 20x^3 - 60x^2 + 120x - 120\right) + C .$$

Daha fazla devam etmeye gerek yoktur, çünkü $0$ ile çarpılan her terim $0$'dır.

Hocaya göre kısmi integrasyonu doğrudan uygulasaydık, bu basitleştirilmiş hâlinden çok daha fazla zaman harcardık. (Sonuç sympy ile doğrulandı.)

### 11.5 Örnek 15 (alıştırma): $\displaystyle\int x^3 e^{3x}\,dx$

Hoca bu soruyu öğrencilere bıraktı; ister uzun yoldan, ister tablo yöntemiyle çözülebileceğini söyledi. Ardından birlikte çözdüler.

| İşaret | Türev sütunu | İntegral sütunu |
|---|---|---|
| $+$ | $x^3$ | $e^{3x}$ |
| $-$ | $3x^2$ | $\frac{1}{3}e^{3x}$ |
| $+$ | $6x$ | $\frac{1}{9}e^{3x}$ |
| $-$ | $6$ | $\frac{1}{27}e^{3x}$ |
| | $0$ | $\frac{1}{81}e^{3x}$ |

Hoca son integrali sorarken "81 mi geliyor?" dedi; evet, $\frac{1}{81}e^{3x}$ gelir. $0$ ile çarpılan terimleri hesaplamaya gerek yoktur. $e^{3x}$ ortak çarpandır:

$$\int x^3 e^{3x}\,dx = e^{3x}\left(\frac{x^3}{3} - \frac{3x^2}{9} + \frac{6x}{27} - \frac{6}{81}\right) + C .$$

Hoca "Bu terimleri sadeleştirebilirsiniz." dedi. Sadeleştirilmiş hâli (ara adım eklendi):

$$\int x^3 e^{3x}\,dx = e^{3x}\left(\frac{x^3}{3} - \frac{x^2}{3} + \frac{2x}{9} - \frac{2}{27}\right) + C = \frac{e^{3x}}{27}\left(9x^3 - 9x^2 + 6x - 2\right) + C .$$

Sonuç sympy ile doğrulandı.

**Soru:** $e^{3x}$'in integrali $3e^{3x}$ değil miydi?
**Cevap:** O türevdir. İntegral alırken öyle bir fonksiyon aranır ki türevi $e^{3x}$'i versin. $\frac{1}{3}e^{3x}$'in türevi $e^{3x}$'tir. Tabloda integral sütununda yukarıdan aşağıya integral alarak iniyoruz.

Hoca dersin sonunda kısmi integrasyonla ilgili başka basitleştirmelerden bir sonraki derste bahsedeceğini söyledi.

## Örnek Sorular

Bu derste kayıt videosu ve hazır kare yoktu. Aşağıdaki sorular, derste hocanın öğrencilere sözlü olarak sorduğu ya da alıştırma olarak bıraktığı sorular ile öğrencilerin sorduğu akademik sorulardır.

### Soru 1 (derste sözlü, 00:28:48)

Örnek 1'de ($\displaystyle\int_0^5\sqrt{x^2+5}\,dx$) $f$'nin $[0,5]$ üzerinde artan olduğunu göstermek için ne yapılmalı? Hoca bir ara aralığın sol ucunu sıfır almanın yanlış olduğunu düşünüp öğrencilere "Neden yanlış oluyor?" diye sordu.

<!-- BELİRSİZ: Hocanın sorusunun tam metni ve karşılaştırdığı değerler (1/2 ve 1/3 noktaları) altyazıdan net çıkmıyor. -->

**Derste verilen cevap:** Bir öğrenci türevin işaretine bakmayı önerdi. $f'(x) = \dfrac{x}{\sqrt{x^2+5}} \ge 0$ olduğundan $f$, $[0,5]$'te artandır. Aralığın sol ucu $0$ olarak kalabilir; hoca da "Şunu sıfır yapabilirsiniz, sıkıntı yok." dedi.

### Soru 2 (derste sözlü, 01:00:16)

$\displaystyle\lim_{x\to 0}\frac{1}{\sin^2 x}\int_0^x e^{t^2}\,dt$ limitini hesaplayın.

**Derste verilen çözüm:** $\dfrac{0}{0}$ belirsizliği; L'Hôpital ve temel teorem 1. kısım ile $\displaystyle\lim_{x\to 0}\frac{e^{x^2}}{2\sin x\cos x}$. Pay $1$'e, payda $0^{\pm}$'a gider. Limit yoktur (bkz. Örnek 4).

### Soru 3 (derste sözlü, 01:44:43)

$\displaystyle\lim_{x\to 0}\frac{1}{x^2}\int_{x}^{x^2}\frac{t^2-1}{t^2+1}\,dt$ limitini hesaplayın.

<!-- BELİRSİZ: Sorunun tahtaya yazılışı altyazıda bozuk; soru, çözüm adımlarından kuruldu. -->

**Derste verilen çözüm:** $\dfrac{0}{0}$ belirsizliği; L'Hôpital ve genelleştirme formülüyle pay $\dfrac{x^4-1}{x^4+1}\cdot 2x - \dfrac{x^2-1}{x^2+1}$, payda $2x$ olur. Doğrudan $x = 0$ yazılınca pay $1$'e, payda $0^{\pm}$'a gider. Limit yoktur (bkz. Örnek 10 ve oradaki ders sonrası not).

### Soru 4 (derste sözlü, 01:50:51)

$f(x) = \displaystyle\int_1^{e^x}\frac{1}{\sqrt{1+t^2}}\,dt$ ise $(f^{-1})'(0)$ nedir?

**Derste verilen çözüm:** $f(x_0) = 0$ için $e^{x_0} = 1$, $x_0 = 0$. $f'(x) = \dfrac{e^x}{\sqrt{1+e^{2x}}}$, $f'(0) = \dfrac{1}{\sqrt 2}$. Buradan $(f^{-1})'(0) = \dfrac{1}{f'(0)} = \sqrt 2$ (bkz. Örnek 11; son adım altyazıda anlaşılmıyor, sonuç sympy ile kesinleştirildi).

### Soru 5 (derste sözlü, 02:24:26)

$\displaystyle\int x^3 e^{3x}\,dx$ integralini tablo yöntemiyle hesaplayın.

**Derste verilen çözüm:** Türevler $x^3, 3x^2, 6x, 6, 0$; integraller $\frac13 e^{3x}, \frac19 e^{3x}, \frac1{27}e^{3x}, \frac1{81}e^{3x}$. Sonuç $e^{3x}\left(\frac{x^3}{3} - \frac{x^2}{3} + \frac{2x}{9} - \frac{2}{27}\right) + C$ (bkz. Örnek 15).

### Soru 6 (derste sözlü, 01:40:15)

Örnek 8'de $(1-\cos x)^2$'nin türevi neden alınmıyor?

**Derste verilen cevap:** Temel teorem uygulanırken integrand türetilmez; üst sınır integranda yerine yazılır ve yalnız üst sınırın türeviyle ($\sin x$) çarpılır.

### Soru 7 (derste sözlü, 01:41:20)

Örnek 8'de sıfıra sağdan ve soldan yaklaşınca sonuç farklı çıkmaz mı?

**Derste verilen cevap:** Hayır. Doğrudan yerine koyunca pay $0$, payda $-1$ olur; sıfıra bölme olmadığı için iki taraftan da limit $0$'dır.

### Soru 8 (derste sözlü, 02:31:19)

$e^{3x}$'in integrali $3e^{3x}$ mi?

**Derste verilen cevap:** Hayır, $3e^{3x}$ türevdir. İntegral $\frac13 e^{3x} + C$'dir, çünkü bunun türevi $e^{3x}$'i verir.

## Dersin Toparlaması

Bu derste önce belirli integralin temel özellikleri görüldü: sınırların yer değiştirmesi işareti değiştirir, aynı sınırlı integral sıfırdır, fonksiyonlar arasındaki sıralama integrallerde korunur ve aralık parçalara bölünebilir. Min-max eşitsizliği, hesaplanması zor bir belirli integralin değeri için alt ve üst sınır vermeyi sağladı. Ardından integraller için ortalama değer teoremi tanıtıldı; burada sağ taraf ortalama değişim oranı değil, fonksiyonun ortalama değeridir. Bu teorem kullanılarak kalkülüsün temel teoreminin birinci kısmı ispatlandı: $\int_a^x f(t)\,dt$ bir alan fonksiyonudur ve türevi, alanı oluşturan ince çubuğun yüksekliği olan $f(x)$'tir.

Temel teoremin ikinci kısmı belirli integrali bir ters türevin uç değerleri farkı olarak hesaplatır. İki kısım birleştirilince sınırları $x$'e bağlı integralin türevi için genel formül elde edildi. Bu formül L'Hôpital kuralıyla birlikte limit sorularında ve birinci vize konusu olan ters fonksiyonun türeviyle birlikte kullanıldı. Son olarak türevin çarpım kuralından kısmi integrasyon formülü çıkarıldı ve polinom ile üstel fonksiyon çarpımlarında işi hızlandıran tablo yöntemi, kısmi integrasyonun özel bir durumu olarak gösterildi. Hoca bir sonraki derste kısmi integrasyonla ilgili başka basitleştirmelerden bahsedeceğini söyledi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
