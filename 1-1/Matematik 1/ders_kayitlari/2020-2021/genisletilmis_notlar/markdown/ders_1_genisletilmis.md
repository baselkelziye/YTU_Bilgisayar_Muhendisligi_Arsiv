# Ders 1 Genişletilmiş Notu: Fonksiyonlar, Trigonometrik Grafikler ve Limite Giriş

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dersin Kapsamı ve Kaynak
- 2. Motivasyon: Başarının Matematiksel Tanımı
- 3. Fonksiyon, Tanım Kümesi ve Görüntü Kümesi
- 4. Düşey Doğru Testi ve Çember Örneği
- 5. Tanım ve Görüntü Kümesi Örnekleri
- 6. Cebirsel İşlemler ve Bileşke
- 7. Simetri: Çift ve Tek Fonksiyonlar
- 8. Temel Fonksiyonlar: Polinom, Rasyonel, Mutlak Değer
- 9. Trigonometrik Fonksiyonlar ve Birim Çember
- 10. Trigonometrik Özdeşlikler ve Periyot
- 11. Trigonometrik Fonksiyonların Grafikleri
- 12. Limit Kavramı
- 13. Tablodan ve Cebirsel İşlemlerle Limit
- 14. Teğet Doğrunun Eğimi
- 15. Limit Kuralları
- 16. Çelişki Yöntemiyle Bir İspat
- 17. Tek Taraflı Limitler
- 18. Sıkıştırma (Sandwich) Teoremi
- Örnek Sorular
- Dersin Toparlaması

## 1. Dersin Kapsamı ve Kaynak

Hoca dersin kodunun MAT1071 olduğunu söyleyerek başladı. Ders İngilizce anlatılıyor, ama hoca yer yer Türkçe açıklamalar da yapıyor. Bu ders tek değişkenli fonksiyonlar teorisi (theory of single variable functions) hakkındadır. Çok değişkenli fonksiyonlar (multi-variable functions) bir sonraki dönemin konusudur.

Dersin ana başlıkları şunlardır:

- Tek değişkenli fonksiyonun tanımı.
- Temel tanımlar: çift fonksiyon (even function), tek fonksiyon (odd function) ve fonksiyon grafiklerinin simetri özellikleri.
- Limit ve süreklilik (continuity).
- Türev (derivation / derivative).
- İntegral (integration).
- Türev ve integralin uygulamaları.

Ana kaynak Thomas' Calculus kitabıdır. Bu başlıklar başka kaynaklardan da çalışılabilir.

**Soru:** Bu konular için Thomas' Calculus kitabını mı öneriyorsunuz? **Cevap:** Evet, ama zorunlu değil. Bu ana başlıkları dikkate alarak başka kitaplardan da çalışabilirsiniz.

## 2. Motivasyon: Başarının Matematiksel Tanımı

Hoca konuya girmeden önce bir soru sordu: "Başarının matematiksel tanımı nedir?" Soru ilk bakışta tuhaf görünebilir, ama hoca bu tanımın öğrenilecek kavramlarla verilebileceğini söyledi. Bir öğrenci başarıyı "soruyu cevaplayabilmek" olarak tarif etti. Hoca ipucu olarak ortalama hız (average velocity) tanımını hatırlattı: ortalama hız, birim zamanda alınan toplam yoldur. Tıpkı ortalama hız ve anlık hız gibi iki çeşit başarı vardır: ortalama başarı ve anlık başarı (instantaneous success).

### 2.1 Sorumluluk Fonksiyonu

Hoca önce "başarı neye bağlıdır?" diye sordu. Öğrencilerden "sorumluluğa" ve "çok çalışmaya" cevapları geldi. Hoca sorumluluk cevabını öne çıkardı: bir hedefle ilgili sorumluluklar belirlenmeden başarı elde edilemez. Sorumluluk öznel ve görelidir, kişinin koşullarına göre değişir. Sorumluluğu etkileyen birçok değişken vardır, ama temel değişken zamandır. Çünkü sorumluluk zamanla değişir.

Bu derste tek değişkenli fonksiyonlarla çalışıldığı için diğer bütün değişkenler göz ardı edilir. Sorumluluk zamanın bir fonksiyonu olarak yazılır:

$$R=f(t)$$

Burada $t$ bağımsız değişken (independent variable), $R$ bağımlı değişkendir (dependent variable). Her kişinin ya da her şirketin farklı bir sorumluluk fonksiyonu vardır. $R(t)$, $t$ anına kadar yerine getirilen sorumlulukların miktarı olarak düşünülebilir.

### 2.2 Ortalama ve Anlık Başarı

Ortalama hıza benzer biçimde, $[t_0,t]$ zaman aralığındaki **ortalama başarı**, sorumluluk fonksiyonunun ortalama değişim hızıdır (average rate of change):

$$\text{ortalama başarı}=\frac{R(t)-R(t_0)}{t-t_0}$$

$t_0$ anındaki **anlık başarı** için $t$, $t_0$'a yaklaştırılır. Bu oranın limiti anlık başarıyı verir:

$$\text{anlık başarı}=\lim_{t\to t_0}\frac{R(t)-R(t_0)}{t-t_0}$$

Bu ifade türevden başka bir şey değildir. Yani anlık başarı, sorumluluk fonksiyonunun türevidir. Türev negatifse bu çok kötü bir durumdur: birim zamana düşen sorumluluklar yerine getirilmiyor demektir. Aynı yorum bir şirket için de yapılabilir.

Hoca bu örnekle şunu göstermek istedi: Sözel bir kavramı bile tanımlamak için limit, süreklilik ve türev gerekir. Burada süreklilik de "saklıdır". Türev, integral, limit ve süreklilik boş kavramlar değildir. Günlük hayatta, mühendislik problemlerinde ve sözel kavramları tanımlarken işe yararlar. Hoca bunun dersin kendisi değil, yalnızca bir motivasyon olduğunu belirtti.

> **Hocanın vurgusu:** Formül ezberlemeyin. Her formülün arkasındaki mantığı (philosophy behind each formula) anlamaya çalışın. Hoca kendisinin de birçok formülü ezbere bilmediğini, gerektiğinde oturup çıkardığını söyledi. Formüle herkes bakabilir; amaç formülün ne anlama geldiğini ve nasıl kullanılacağını kavramaktır.

## 3. Fonksiyon, Tanım Kümesi ve Görüntü Kümesi

**Tanım (Fonksiyon):**

- Bir fonksiyon, bir $D$ kümesindeki her $x$ değerine tek (unique) bir değer atayan kuraldır.
- Bu değer $f(x)$ ile gösterilir.
- $D$ kümesine tanım kümesi (domain) denir. Tanım kümesi, kuralın anlamlı olduğu bütün olası girdilerin kümesidir.

Hoca tanımı bir girdi-kural-çıktı şemasıyla gösterdi. Bir girdi $x$ bir kurala (algoritmaya) girer ve bir çıktı $f(x)$ verir. Burada iki noktaya dikkat edilir:

- Bir girdi yalnız bir çıktıya atanabilir. Bir $x$ hem $a$'ya hem $b$'ye gidiyorsa, fonksiyon olması için $a=b$ olmalıdır. Aksi halde bu bir fonksiyon değildir.
- İki farklı girdi aynı çıktıya atanabilir. Yani $x_1\neq x_2$ iken $f(x_1)=f(x_2)$ olabilir.

$y=f(x)$ gösteriminde $x$ girdidir ve matematik terminolojisinde bağımsız değişken adını alır. $y$ çıktıdır ve bağımlı değişkendir.

**Tanım (Grafik):**

- $y=f(x)$ tek değişkenli bir fonksiyon olsun. $f$'nin grafiği şu kümedir:

$$\text{Grafik}(f)=\{(x,f(x)) : x\in D\}$$

- İkinci koordinat birinci koordinata (girdiye) bağlıdır.
- Grafik $\mathbb{R}^2$ düzleminin bir alt kümesidir.

Fonksiyon genel olarak şöyle yazılır:

$$f: D\subset\mathbb{R}\to\mathbb{R},\qquad x\mapsto y=f(x)$$

Burada sağdaki $\mathbb{R}$ değer kümesidir (codomain). Görüntü kümesi (range) ile karıştırılmamalıdır. $f$'nin görüntüsüne (image) görüntü kümesi denir:

$$\text{Range}(f)=\{f(x): x\in D\}$$

Görüntü kümesi değer kümesinin bir alt kümesidir. Tanım kümesi $D$'nin bütün gerçel sayılar olması gerekmez.

## 4. Düşey Doğru Testi ve Çember Örneği

Düzlemde bir eğri verildiğinde, bu eğrinin bir fonksiyonun grafiği olup olmadığını düşey doğru testiyle (vertical line test) anlayabiliriz. Yatay eksen girdilerin, düşey eksen çıktıların eksenidir.

**Düşey doğru testi:**

- Bir düşey doğru eğriyi iki farklı noktada kesiyorsa, o $x$ girdisi iki farklı çıktıya atanmış olur.
- Bu, fonksiyon tanımıyla çelişir. Böyle bir eğri $y=f(x)$ biçimindeki tek değişkenli bir fonksiyonun grafiği olamaz.
- Her düşey doğru eğriyi en fazla bir noktada kesiyorsa eğri bir fonksiyonun grafiğidir.

### 4.1 Yatay Doğru ile $x=f(y)$ Biçimi

Hoca, düşey doğru testinden geçemeyen bir eğri çizdi. Bu eğri $y=f(x)$ biçiminde bir fonksiyona karşılık gelmez. Ama $x=f(y)$ biçiminde bir fonksiyona karşılık gelebilir. Bu durumda düşey eksen bağımsız değişkenin ekseni olarak düşünülür: $y$ bağımsız, $x$ bağımlı değişkendir.

> **Hocanın vurgusu:** Böyle bir grafik $y=f(x)$'e karşılık gelmez, ama $x=f(y)$ biçiminde bir fonksiyona karşılık gelir. Buna dikkat edin.

### 4.2 Çember Örneği

Hoca bir çember çizip "Bu eğri bir fonksiyonun grafiği midir?" diye sordu. Öğrenciler "hayır" dedi. Gerçekten de en az bir düşey doğru çemberi iki farklı noktada keser.

Birim çemberin denklemi $x^2+y^2=1$ ikinci dereceden (quadratic) bir ifadedir. $y$'yi $x$ cinsinden yazmaya çalışırsak $y^2=1-x^2$ olur ve iki seçenek çıkar:

- $y_+=\sqrt{1-x^2}$: $y$ koordinatları pozitif olan **üst yarım çember**.
- $y_-=-\sqrt{1-x^2}$: $y$ koordinatları negatif olan **alt yarım çember**.

Her iki yarım çember de düşey doğru testinden geçer. Bu yüzden ikisi de birer fonksiyonun grafiğidir.

Benzer şekilde $x$ değişkeni $y$ cinsinden yazılırsa:

- $x_+=\sqrt{1-y^2}$: **sağ yarım çember**.
- $x_-=-\sqrt{1-y^2}$: **sol yarım çember**.

Çemberin tamamı $y=f(x)$ biçiminde bir fonksiyonun grafiği değildir. Ama yerel parçaları (local parts) $y=f(x)$ ya da denk biçimde $x=g(y)$ şeklinde fonksiyonlara karşılık gelebilir. Hoca, bu gösterimlerdeki $f$ harflerinin farklı fonksiyonları gösterdiğini, aynı olmadıklarını ayrıca belirtti.

Genelde $y=f(x)$ biçimi kullanılır ve girdiler yatay eksende gösterilir. Görüntü kümesi düşey eksenin bir alt kümesidir. Bu bir alışkanlıktır, zorunluluk değildir.

## 5. Tanım ve Görüntü Kümesi Örnekleri

### Örnek 1: $y=x^2+1$

- **Tanım kümesi:** $x^2+1$ kuralına her gerçel sayı yazılabilir. Bu bir polinomdur. $D(f)=\mathbb{R}$.
- **Değer kümesi:** $\mathbb{R}$.
- **Görüntü kümesi:** $x^2\ge 0$ olduğundan $y=x^2+1\ge 1$. Çıktılar her zaman 1'e eşit ya da 1'den büyüktür (ara adım eklendi). $\text{Range}(f)=[1,\infty)$.
- Görüntü kümesi değer kümesinin bir alt kümesidir.

### Örnek 2: $z=f(t)=\sqrt{4-t^2}$ (üst yarım çember)

Gerçel sayılarla çalışıyoruz, karmaşık sayılarla değil. Karekök kuralının gerçel sayılarda anlamlı olması için kökün içi negatif olmamalıdır:

$$4-t^2\ge 0 \;\Rightarrow\; t^2\le 4 \;\Rightarrow\; |t|\le 2 \;\Rightarrow\; -2\le t\le 2$$

Uç noktalar da dahil olduğundan tanım kümesi kapalı aralıktır: $D(f)=[-2,2]$.

Görüntü kümesi, tanım kümesindeki değerler yerine konarak bulunur. $t=\pm2$ için $f(t)=0$, $t=0$ için $f(0)=\sqrt4=2$ (ara adım eklendi). Görüntü kümesi $[0,2]$'dir.

> **Ders sonrası not:** Hoca görüntü kümesini sözlü olarak "sıfırdan üçe" dedi; doğrusu $[0,2]$. Fonksiyonun en büyük değeri $t=0$'da $\sqrt4=2$'dir. Bu sonuç python (sympy) ile de doğrulandı.

### Örnek 3: $w=f(u)=\dfrac{1}{u-1}$ (döndürülmüş hiperbol)

Bu örnekte $u$ bağımsız, $w$ bağımlı değişkendir. Grafik döndürülmüş bir hiperboldür.

$$f: D(f)\subset\mathbb{R}\to\mathbb{R},\qquad u\mapsto\frac{1}{u-1}$$

$u=1$ noktasında payda sıfır olur. Tanım kümesi, 1 dışındaki bütün gerçel sayılardır: $D(f)=\mathbb{R}\setminus\{1\}$.

Hoca burada önemli bir gösterim uyarısı yaptı. $u=1$'e soldan ya da sağdan yaklaşırken "$\frac10=\infty$" yazmak yanlıştır.

> **Hocanın vurgusu:** $\frac{1}{0}=\infty$ diye bir gösterim yoktur. Bazı lise hocaları böyle anlatıyor, ama mantıksal olarak yanlıştır. $\frac10$ tanımsızdır. Bu gösterimi kullanmayın.

Hoca basitleştirme olarak şu gösterimi önerdi. Birçok kaynakta bulunmadığını, öğrenciler için yaptığı bir basitleştirme olduğunu söyledi:

- $\frac{1}{0^+}$: 1 bölü sıfıra çok yakın **pozitif** bir sayı. Sonuç yeterince büyük pozitif bir sayıdır, $+\infty$'a gider.
- $\frac{1}{0^-}$: 1 bölü sıfıra çok yakın **negatif** bir sayı. Sonuç yeterince büyük negatif bir sayıdır, $-\infty$'a gider.

Bu yazım $\frac10$ yazmaktan daha doğrudur, ama tam doğru değildir. Asıl doğru olan limit kavramını kullanmaktır. Böylece limit kavramı burada ortaya çıkar.

Grafikte:

- $u$, 1'e sağdan yaklaşırken (örneğin $1{,}0001$) payda $0^+$ olur. Grafik sonsuza doğru yukarı çıkar.
- $u$, 1'e soldan yaklaşırken (örneğin $0{,}9999$) payda $0^-$ olur. Grafik sonsuza doğru aşağı iner ($-\infty$).

Sympy ile: $\lim_{u\to1^+}\frac{1}{u-1}=+\infty$, $\lim_{u\to1^-}\frac{1}{u-1}=-\infty$.

### 5.1 Tanım Kümesi Grafikten Nasıl Okunur?

Fonksiyonun grafiğinin yatay eksen üzerine dik izdüşümü (orthogonal projection) alınırsa fonksiyonun tanım kümesi elde edilir. Yani tanım kümesi grafik üzerinden de belirlenebilir.

## 6. Cebirsel İşlemler ve Bileşke

### 6.1 Cebirsel İşlemler

İki fonksiyon $f$ ve $g$ verildiğinde toplam, fark, çarpım ve bölüm tanımlanabilir:

- $(f+g)(x)=f(x)+g(x)$
- $(f-g)(x)=f(x)-g(x)$
- $(fg)(x)=f(x)g(x)$
- $\left(\dfrac fg\right)(x)=\dfrac{f(x)}{g(x)}$, $g(x)\neq0$

Bu yeni fonksiyonların tanım kümeleri $f$ ve $g$'nin tanım kümelerinden farklı olabilir.

<!-- BELİRSİZ: Hocanın tahtaya yazdığı tanım kümesi ifadeleri (ör. kesişim) altyazıda okunmuyor; burada yalnız işlemlerin kendisi verildi. -->

### 6.2 Bileşke (Composition)

Bileşke cebirsel bir işlem değildir. Hoca bunu bir şemayla anlattı: Girdiye önce $g$ uygulanır ve $g(x)$ çıktısı elde edilir. Sonra bu çıktıya $f$ uygulanır. Sonuç $f(g(x))$'tir ve buna "$f$ bileşke $g$" denir:

$$(f\circ g)(x)=f(g(x))$$

**Bileşkenin tanımlı olma koşulu:**

- $g$'nin görüntü kümesi ile $f$'nin tanım kümesinin kesişimi boş olmamalıdır:

$$\text{Range}(g)\cap D(f)\neq\emptyset$$

- Aksi halde bileşkeden söz edilemez.
- Örneğin bir $x_2$ girdisi için $g(x_2)$, $f$'nin tanım kümesinde değilse, bileşke o noktada tanımlı olmaz.

### Örnek 4: $f(x)=3x^2-x$, $g(x)=\dfrac1x$

- $f$ bir polinomdur, $D(f)=\mathbb{R}$.
- $g$, $x=0$ dışında her yerde tanımlıdır, $D(g)=\mathbb{R}\setminus\{0\}$.
- $f(5p+1)$: kuraldaki $x$ yerine $5p+1$ argümanı yazılır. Hoca bunun da aslında iki fonksiyonun bileşkesi olduğunu söyledi. Hesap derste yapılmadı; açılırsa (ara adım eklendi):

$$f(5p+1)=3(5p+1)^2-(5p+1)=75p^2+25p+2$$

- Benzer şekilde $g$'nin kuralına $\frac1x$ argümanı yazılır.

<!-- BELİRSİZ: Tahtadaki ikinci ifadenin tam biçimi (g(1/x) mi, başka bir bileşke mi) altyazıda net değil. g(1/x) ise sonuç x'tir (x ≠ 0). -->

Hoca bu hesapların liseden bilindiğini söyleyip hızlı geçti.

### Örnek 5: Tablodan Bileşke

İki fonksiyon $y=f(x)$ ve $y=g(x)$ bir tabloyla verilmiş. $(f\circ g)(5)$ isteniyor.

- Tablodan $g(5)=1$.
- Sonra $f(1)$ tablodan okunur: $f(1)=6$.
- Sonuç: $(f\circ g)(5)=f(g(5))=f(1)=6$.

<!-- BELİRSİZ: Tablonun diğer değerleri altyazıda okunmuyor; hoca "diğer değerleri siz hesaplayabilirsiniz" dedi. -->

## 7. Simetri: Çift ve Tek Fonksiyonlar

### 7.1 Çift Fonksiyon

Hoca $y$ eksenine göre simetrik bir grafik çizdi. $x$ girdisi $f(x)$'e gider. $-x$, $x$'in orijine göre simetriğidir ve aynı değere gider.

Simetrik fonksiyonlardan söz etmek için önce tanım kümesine bakılır.

**Tanım (Çift fonksiyon):**

- **Ön koşul:** $D(f)$ orijine göre simetrik olmalıdır. Aksi halde çift fonksiyondan söz edilemez.
- Her $x\in D(f)$ için ($\forall$ evrensel niceleyici) $f(-x)=f(x)$ ise $f$, $D(f)$ üzerinde çift fonksiyondur.
- Çift fonksiyonun grafiği $y$ eksenine göre simetriktir.

### 7.2 $x$ Eksenine Göre Simetrik Grafik

Hoca $x$ eksenine göre simetrik bir grafik de çizdi. Bu grafik $x=f(y)$ biçiminde bir fonksiyona karşılık gelir. Burada $x$ bağımlı, $y$ bağımsız değişkendir. Tanım kümesi, grafiğin düşey eksene dik izdüşümüdür. Görüntü kümesi yatay eksendedir.

Bu fonksiyon da çift fonksiyondur, ama $x=f(y)$ biçimindedir. Yani grafik görüntü kümesi eksenine (burada $x$ eksenine) göre simetriktir. Bu varsayım (hangi değişkenin bağımsız olduğu) dikkate alınmalıdır.

### 7.3 Tek Fonksiyon

Orijine göre simetri de bir simetri türüdür. Hoca grafikte $x$ ve $-x$ noktalarını işaretledi. $f(x)$ ile $f(-x)$'in uzaklıkları eşittir, tek fark işarettir.

**Tanım (Tek fonksiyon):**

- **Ön koşul:** $D(f)$ orijine göre simetrik olmalıdır.
- Her $x\in D(f)$ için $f(-x)=-f(x)$ ise $f$ tek fonksiyondur.
- Tek fonksiyonun grafiği orijine göre simetriktir.

### 7.4 Örnekler ve Genelleme

- $y=x^2$ çift fonksiyondur.
- $y=x^3$ tek fonksiyondur. Grafiği orijine göre simetriktir.
- Genelleme: Kuvveti çift olan tek terimliler ($x^{2n}$) çift fonksiyondur. Kuvveti tek olan tek terimliler ($x^{2n+1}$) tek fonksiyondur.
- Hoca son olarak ne orijine ne de düşey eksene göre simetrisi olan bir grafik gösterdi. Bu fonksiyon ne çift ne tektir.

<!-- BELİRSİZ: Monomiyal genellemesinin tahtadaki tam yazımı altyazıda bölük pörçük; burada x^{2n} ve x^{2n+1} biçimi verildi. -->

## 8. Temel Fonksiyonlar: Polinom, Rasyonel, Mutlak Değer

### 8.1 Polinomlar

**Tanım (Polinom):**

- Polinomlar $x^n$ tek terimlilerinin doğrusal birleşimidir (linear combination):

$$p(x)=a_nx^n+a_{n-1}x^{n-1}+\dots+a_1x+a_0$$

- $a_0,a_1,\dots,a_n$ gerçel katsayılardır.
- $a_n\neq0$ olmalıdır. Aksi halde $n$. dereceden bir polinom elde edilmez.
- Her polinomun tanım kümesi bütün gerçel sayılardır. Yani polinom her yerde tanımlıdır.

### 8.2 Rasyonel Fonksiyonlar

**Tanım (Rasyonel fonksiyon):**

- İki polinomun oranıdır. Pay bir polinom, payda başka bir polinomdur.
- Tanım kümesi, paydayı sıfır yapan noktalar dışındaki bütün gerçel sayılardır.

Hoca paydası 3. dereceden bir polinom olan bir rasyonel fonksiyon örneği verdi. Tanım kümesini bulmak için paydanın kökleri hesaplanmalıdır. Hoca bu köklerin MATLAB gibi bir araçla da bulunabileceğini söyledi.

<!-- BELİRSİZ: Bu rasyonel fonksiyonun ifadesi ve kökleri altyazıda okunmuyor (01:12-01:14 arası altyazı döngüye girmiş). Ardından gösterilen parçalı tanımlı fonksiyon örneği de altyazıda anlaşılmıyor. -->

### 8.3 Kuralları Özdeş, Fonksiyonları Farklı

Hoca önemli bir incelik gösterdi. Şu iki ifadeye bakalım:

$$\frac{x^2-5x+6}{x-2}=\frac{(x-2)(x-3)}{x-2}\qquad\text{ve}\qquad x-3$$

$x-2$ çarpanı sadeleşince kural $x-3$'e özdeş (identical) olur. Ama bu iki fonksiyon aynı değildir:

- $x-3$'ün tanım kümesi bütün gerçel sayılardır. $x=2$'de $-1$ değerini alır.
- $\frac{x^2-5x+6}{x-2}$ ise $x=2$'de tanımlı değildir.

> **Hocanın vurgusu:** Kuralları birbirine özdeş olan fonksiyonlar aynı fonksiyon olmayabilir. Dikkatinizi çekerim, tanım kümeleri farklıdır.

> **Ders sonrası not:** Hoca konuşurken bir an "$y=x-2$" ve "$x^2-5x+6$, $x-2$'ye özdeştir" dedi, sonra kendisi düzeltti: sadeleşmeden sonra kalan ifade $x-3$'tür. Sympy ile $\frac{x^2-5x+6}{x-2}$ sadeleştirilince $x-3$ çıkar.

### 8.4 Mutlak Değer Fonksiyonu

$f$ her yerde tanımlı olsun. Mutlak değerin genel tanımı:

$$|f(x)|=\begin{cases} f(x), & f(x)\ge 0\\ -f(x), & f(x)<0\end{cases}$$

Özel olarak $f(x)=x$ için:

$$|x|=\begin{cases} x, & x\ge 0\\ -x, & x<0\end{cases}$$

Grafik, $x\ge0$ için $y=x$ doğrusu, $x<0$ için $y=-x$ doğrusudur.

## 9. Trigonometrik Fonksiyonlar ve Birim Çember

Altı trigonometrik fonksiyon vardır: sinüs, kosinüs, tanjant, kotanjant, sekant ve kosekant. Liseden bilinen dik üçgen tanımları şunlardır:

- $\sin\theta=\dfrac{\text{karşı dik kenar}}{\text{hipotenüs}}$
- $\cos\theta=\dfrac{\text{komşu dik kenar}}{\text{hipotenüs}}$
- $\tan\theta=\dfrac{\text{karşı dik kenar}}{\text{komşu dik kenar}}$

Hoca bu fonksiyonların kurallarının birim çember üzerinden nasıl elde edildiğini gösterdi.

### 9.1 Eksenler

- **Kosinüs ekseni:** yatay eksen. Sıfırdan $+\infty$'a pozitif kosinüs, sıfırdan $-\infty$'a negatif kosinüs yarı doğrusudur.
- **Sinüs ekseni:** düşey eksen. Sıfırdan yukarısı pozitif sinüs, aşağısı negatif sinüstür.
- **Tanjant ekseni:** birim çembere $(1,0)$ noktasında teğet olan düşey doğru. "Tanjant" adı bu teğet doğrudan (tangent line) gelir. $(1,0)$'dan yukarısı pozitif tanjant, aşağısı negatif tanjanttır.
- **Kotanjant ekseni:** birim çembere $(0,1)$ noktasında teğet olan yatay doğru. $(0,1)$'den sağa doğru pozitif kotanjant, sola doğru negatif kotanjanttır.

### 9.2 Değerlerin Okunması

Orijin etrafında dönen bir çubuk (bar) ve bu çubuğun yaptığı $\theta$ açısı düşünülür. Önce $0<\theta<\frac\pi2$ durumuna bakılır.

- Çubuğun çember üzerindeki uç noktasının kosinüs eksenine dik izdüşümü $\cos\theta$ değerini verir. Bu nokta pozitif kosinüs üzerindedir.
- Uç noktanın sinüs eksenine dik izdüşümü $\sin\theta$ değerini verir.
- Çubuğun uzantısı pozitif tanjant eksenini bir noktada keser. Bu noktanın uzaklığı $\tan\theta$'dır.
- Çubuğun uzantısının kotanjant eksenini kestiği nokta $\cot\theta$ değerini verir.

Üçgenlerin benzerliğinden (similarity) şu özdeşlikler çıkar:

$$\tan\theta=\frac{\sin\theta}{\cos\theta},\quad \cos\theta\neq0$$

$$\cot\theta=\frac{\cos\theta}{\sin\theta},\quad \sin\theta\neq0$$

Kosekant ve sekant ise:

$$\csc\theta=\frac{1}{\sin\theta},\qquad \sec\theta=\frac{1}{\cos\theta}$$

## 10. Trigonometrik Özdeşlikler ve Periyot

### 10.1 Pisagor Özdeşliği

Birim çemberde Pisagor teoreminden:

$$\sin^2\theta+\cos^2\theta=1$$

Hoca bunun nasıl elde edildiğini ayrıca göstermedi. Bu formüllerin ezberlenmesine gerek olmadığını, çıkarılabileceğini söyledi.

### 10.2 Toplam Formülleri

Hoca öğrencilere lisede karmaşık sayıları görüp görmediklerini sordu. Öğrenciler çok az gördüklerini, kutupsal gösterimi görmediklerini söyledi. Hoca, karmaşık sayılar bilinseydi toplam formüllerinin "5-10 saniyede" çıkarılabileceğini, aksi halde geometriden çıkarılması gerektiğini söyledi. Bunun nasıl elde edildiğini incelemeyi ödev olarak bıraktı.

> **Ek bilgi (derste anlatılmadı):** Hocanın kastettiği yol büyük olasılıkla Euler formülüdür: $e^{i\theta}=\cos\theta+i\sin\theta$. $e^{i(a+b)}=e^{ia}e^{ib}$ eşitliğinde iki taraf açılıp gerçel ve sanal kısımlar eşitlenirse $\cos(a+b)$ ve $\sin(a+b)$ formülleri birlikte çıkar.

İki ana formül:

$$\sin(a+b)=\sin a\cos b+\cos a\sin b$$

$$\cos(a+b)=\cos a\cos b-\sin a\sin b$$

Fark formülleri için bu formüllerde $b$ yerine $-b$ yazılır. Kosinüs çift fonksiyondur: $\cos(-x)=\cos x$. Sinüs tek fonksiyondur: $\sin(-x)=-\sin x$. Bu, birim çember çiziminden de görülebilir. Böylece:

$$\sin(a-b)=\sin a\cos(-b)+\cos a\sin(-b)=\sin a\cos b-\cos a\sin b$$

$$\cos(a-b)=\cos a\cos b+\sin a\sin b$$

> **Hocanın vurgusu:** Yalnız iki ana formülü ($\sin(a+b)$ ve $\cos(a+b)$) bilmek ya da çıkarabilmek yeterlidir. Gerisi bunlardan elde edilir.

### 10.3 Çift Açı ve Kuvvet İndirme Özdeşlikleri

Toplam formüllerinde $a=b=\theta$ alınırsa:

$$\sin2\theta=2\sin\theta\cos\theta$$

$$\cos2\theta=\cos^2\theta-\sin^2\theta$$

İkinci formülde Pisagor özdeşliği ($\sin^2\theta+\cos^2\theta=1$) yerine konursa (ara adım eklendi: $\cos2\theta=2\cos^2\theta-1=1-2\sin^2\theta$):

$$\cos^2\theta=\frac{1+\cos2\theta}{2},\qquad \sin^2\theta=\frac{1-\cos2\theta}{2}$$

> **Hocanın vurgusu:** Bu özdeşlikler integral konusunda çok önemlidir. Sol tarafta kuvvet 2'dir; sağ tarafta trigonometrik fonksiyon 1. kuvvettendir.

Bu özdeşliklerin hepsi sympy ile doğrulandı.

### 10.4 Periyot

**Tanım (Periyot):**

- Her $x$ için $f(x+T)=f(x)$ koşulunu sağlayan sonsuz çoklukta $T$ değeri olabilir.
- Bu koşulu sağlayan **en küçük pozitif** $T$ değerine periyot denir.

Periyotlar:

- $\sin$, $\cos$, $\sec$, $\csc$: periyot $2\pi$.
- $\tan$, $\cot$: periyot $\pi$.

Hoca bunların toplam formülleriyle elde edilebileceğini söyledi.

## 11. Trigonometrik Fonksiyonların Grafikleri

Hoca grafikleri ezberlemek yerine nereden geldiğini göstermek istediğini, en önemli kısmın burası olduğunu söyledi.

### 11.1 Işınlar

Birim çember üzerinde şu ışınlar (ray) işaretlenir: $\theta=0$, $\theta=\frac\pi4$, $\theta=\frac\pi2$, $\theta=\pi$, $\theta=\frac{3\pi}2$. $\theta=2\pi$ ışını $\theta=0$ ışınıyla aynı konumdadır. Hoca bunlara "eşit değil, denk (equivalent)" dedi: Işın farklı zamanlarda aynı konuma geliyormuş gibi düşünülür.

### 11.2 Sinüs Grafiği

Çubuk döndükçe uç noktanın sinüs eksenine izdüşümü izlenir:

- $\theta=0$: $\sin0=0$.
- $\theta=\frac\pi4$: Pisagor teoreminden $\sin\frac\pi4=\frac{\sqrt2}2$. Burada iki dik kenar eşittir.
- $\theta=\frac\pi2$: izdüşüm uzunluğu 1, $\sin\frac\pi2=1$.
- $\theta=\pi$: $\sin\pi=0$.
- $\theta=\frac{3\pi}2$: $\sin\frac{3\pi}2=-1$.

Sinüs periyodik olduğu için grafik dalgalar biçiminde tekrar eder.

$$\sin:\mathbb{R}\to\mathbb{R},\qquad D(\sin)=\mathbb{R},\qquad \text{Range}(\sin)=[-1,1]$$

### 11.3 Kosekant Grafiği

$\csc\theta=\frac1{\sin\theta}$. Bu fonksiyon $\sin\theta$'yı sıfır yapan noktalar dışında her yerde tanımlıdır. Örneğin $\theta=\pi$'de tanımsızdır.

- $\pi$'ye soldan yaklaşırken $\sin\theta$ küçük pozitif değerler alır. İfade $\frac{1}{0^+}$ biçimindedir ve $+\infty$'a gider.
- $0$'a sağdan yaklaşırken de $\frac{1}{0^+}$ biçimi çıkar, $+\infty$'a gider.
- Bu noktalarda düşey asimptotlar vardır. Grafik periyodiktir, kendini tekrar eder.

Sympy: $\lim_{\theta\to\pi^-}\csc\theta=+\infty$, $\lim_{\theta\to0^+}\csc\theta=+\infty$.

### 11.4 Kosinüs ve Sekant Grafikleri

Aynı birim çember çiziminden: $\cos0=1$, $\cos\frac\pi2=0$, $\cos\pi=-1$. Grafik buna göre ilerler. Hoca bu değerlerin ezberlenmesine gerek olmadığını, unutulursa nasıl çıkarılacağının bilindiğini söyledi.

$\sec\theta=\frac1{\cos\theta}$. Kosinüs $\frac\pi2$ ve $\frac{3\pi}2$'de sıfırdır, bu yüzden sekant bu noktalarda tanımsızdır.

$$\lim_{x\to\frac\pi2^-}\frac1{\cos x}=+\infty$$

Çünkü $\frac\pi2$'ye soldan yaklaşırken $\cos x$ küçük pozitif değerler alır ve ifade $\frac{1}{0^+}$ biçimindedir. Ayrıca $\sec\pi=\frac{1}{\cos\pi}=-1$.

> **Ders sonrası not:** Hoca önce "$\frac\pi2$'ye sağdan yaklaşırken" dedi, sonra yazdığı eksi işaretinin soldan yaklaşma anlamına geldiğini açıkladı. $+\infty$ sonucu soldan yaklaşma içindir. Sağdan yaklaşınca $\cos x<0$ olur ve sonuç $-\infty$'dur.

Özetle: Sinüs grafiği bilinirse kosekant, kosinüs grafiği bilinirse sekant grafiği hemen çıkarılır.

Hoca neden bu kadar uğraştığını da açıkladı: "Zaten bilgisayarlar çiziyor" diye düşünmeyin. İleride bu mantığı kullanabilirsiniz. Nasıl çıkarıldığına odaklanın.

### 11.5 Tanjant Grafiği

Yine birim çember ve dönen çubuk kullanılır.

- $0<\theta<\frac\pi2$: çubuğun uzantısı pozitif tanjant eksenini keser. $\theta$ büyüdükçe kesişim noktası yukarı çıkar, $y$ değeri artar. $\theta$, $\frac\pi2$'ye soldan yaklaşırken:

$$\lim_{\theta\to\frac\pi2^-}\tan\theta=+\infty$$

- Bu yüzden $\theta=\frac\pi2$'de düşey asimptot vardır.
- $\frac\pi2<\theta<\pi$: çubuğun ters yöndeki uzantısı negatif tanjant eksenini keser. Tanjant negatiftir.
- $\theta$, $\frac{3\pi}2$'ye soldan yaklaşırken çubuğun uzantısı yine pozitif tanjant eksenini keser ve değer $+\infty$'a gider.

<!-- BELİRSİZ: 01:40:23-01:41:47 arası altyazı döngüye girmiş; tanjant grafiğinin bu bölümdeki tahta çizimi altyazıdan kurulamıyor. -->

Hoca işaretlerin $\frac{\sin\theta}{\cos\theta}$ üzerinden de belirlenebileceğini söyledi: pay ve paydanın işaretine bakarak sonucun $+\infty$ mu, $-\infty$ mu olduğu görülür. Tanjantın periyodu $\pi$'dir.

Sympy: $\lim_{\theta\to\frac\pi2^-}\tan\theta=+\infty$, $\lim_{\theta\to\frac{3\pi}2^-}\tan\theta=+\infty$, $\lim_{\theta\to\frac\pi2^+}\tan\theta=-\infty$.

### 11.6 Kotanjant Grafiği

Kotanjant grafiği tanjant grafiğinden elde edilir. Hoca bunu bir benzetmeyle anlattı: Tanjant grafiğini tutup üç boyutlu uzayda havada döndürür gibi (ya da büker gibi, "twist eder gibi") yerleştirirseniz kotanjant grafiğini elde edersiniz. Bu bir simetri değil, havada döndürme hareketidir.

Hoca bu kısımların liseden bilindiğini düşündüğünü ve hızlı geçtiğini söyledi. Amacı konuları bitirip soru çözmeye geçmekti.

## 12. Limit Kavramı

**Tanım (Limit, kaba tanım):**

- $f$ bir fonksiyon, $L$ bir sabit olsun.
- $x$, $a$'ya soldan ya da sağdan yaklaşırken $f(x)$ değerleri **tek (unique)** ve **sonlu (finite)** bir $L$ sayısına yaklaşıyorsa, $f$'nin $a$ noktasında limiti vardır denir.
- Gösterim: $\displaystyle\lim_{x\to a}f(x)=L$.
- Teklik önemlidir.

Hoca bunun genel ve kaba bir tanım olduğunu, tam matematiksel tanım olmadığını belirtti.

> **Ek bilgi (derste anlatılmadı):** Limitin kesin tanımı $\varepsilon$-$\delta$ tanımıdır: her $\varepsilon>0$ için öyle bir $\delta>0$ vardır ki $0<|x-a|<\delta$ olduğunda $|f(x)-L|<\varepsilon$ olur. Kaba tanımdaki "yaklaşır" sözü bu tanımla kesinleştirilir.

### 12.1 Grafik Üzerinde Üç Durum

Hoca bir grafik üzerinde üç farklı durumu inceledi.

- **$x=1$:** Grafiğe göre $f(1)=2$. $x$, 1'e soldan ya da sağdan yaklaşırken (örneğin $1{,}0001$ gibi değerler) $f(x)$ değerleri 2'ye yaklaşır. $\lim_{x\to1}f(x)=2$. Burada limit değeri ile fonksiyonun değeri aynıdır.
- **$x=2$:** Grafiğe göre $f(2)=5$, yani $f$ bu noktada tanımlıdır. Ama $x$, 2'ye soldan ya da sağdan yaklaşırken $f(x)$ değerleri 3'e yaklaşır. $\lim_{x\to2}f(x)=3$. Fonksiyonun değeri ile limit değeri farklıdır.
- **$x=3$:** Grafiğe göre $f(3)$ tanımlı değildir. Ama $x$, 3'e soldan ya da sağdan yaklaşırken $f(x)$ değerleri 4'e yaklaşır. $\lim_{x\to3}f(x)=4$. Fonksiyon tanımsız olsa da limit vardır.

$f(1)$ ile $\lim_{x\to1}f(x)$ farklı ifadelerdir. $f(1)$, $f$'nin 1 noktasındaki değeridir. $\lim_{x\to1}f(x)$ ise $x$ 1'e soldan ya da sağdan yaklaşırken $f(x)$ değerlerinin neye yaklaştığıdır.

> **Ders sonrası not:** Hoca önce $f(2)$'nin tanımlı olmadığını söyledi, sonra grafiğin üst kısmını görmediğini fark edip kendisi düzeltti: $f(2)=5$ tanımlıdır, ama limit değeri olan 3'e eşit değildir.

**Soru:** Limitleri tekrar anlatabilir misiniz? **Cevap:** Hoca üç durumu yeniden, adım adım anlattı (yukarıdaki açıklama). Sonunda şunu söyledi: Fonksiyon bir noktada tanımlı olmasa bile o noktada limiti olabilir. "$x$'ler 3'e yaklaşırken $f(x)$'ler nereye yaklaşır?" sorusunun cevabı bulunabiliyorsa limit vardır.

## 13. Tablodan ve Cebirsel İşlemlerle Limit

### Örnek 6: $\displaystyle\lim_{x\to1}\frac{\sqrt x-1}{x-1}$ (tablodan ve cebirle)

**Tablodan:** Bağımsız değişken için 1'e soldan ($0{,}9;\ 0{,}99;\ 0{,}999$) ve sağdan yaklaşan ayrık değerler alınır. Değerler bilgisayarla hesaplanabilir. Değerler 1'e yaklaştıkça fonksiyon değerleri $0{,}5$ civarına yaklaşır.

Python ile hesaplanan değerler (derste tablonun sayıları okunmuyor, buradaki değerler doğrulama içindir):

| $x$ | $0{,}9$ | $0{,}99$ | $0{,}999$ | $1{,}001$ | $1{,}01$ | $1{,}1$ |
|---|---|---|---|---|---|---|
| $f(x)$ | $0{,}51317$ | $0{,}50126$ | $0{,}50013$ | $0{,}49988$ | $0{,}49876$ | $0{,}48809$ |

**Cebirle:** $x=1$ doğrudan yazılırsa $\frac00$ çıkar. Bilgisayar için bu belirsiz (indeterminate) bir durumdur. Bunun yerine özdeş bir kural kullanılır. $x-1$ çarpanlarına ayrılır:

$$x-1=(\sqrt x-1)(\sqrt x+1)$$

$$\lim_{x\to1}\frac{\sqrt x-1}{x-1}=\lim_{x\to1}\frac{\sqrt x-1}{(\sqrt x-1)(\sqrt x+1)}=\lim_{x\to1}\frac{1}{\sqrt x+1}$$

$\sqrt x-1$ çarpanları sadeleşir. Elde edilen limit problemi öncekine denktir. Kurallar özdeştir, ama fonksiyonlar farklıdır. Artık $x=1$ doğrudan yazılabilir, belirsizlik yoktur:

$$\lim_{x\to1}\frac{1}{\sqrt x+1}=\frac{1}{1+1}=\frac12$$

Fonksiyon $x=1$'de tanımlı değildir, ama 1 noktasında limiti $\frac12$'dir. Sympy sonucu: $\frac12$.

Hoca burada programlamayla bağlantı kurdu: Programlama dersinde bir döngü açıp $x$ değerlerini 1'e yeterince yakın (ama tam 1 değil) seçerseniz, bilgisayar $\frac{\sqrt x-1}{x-1}$'i yaklaşık $\frac12$ bulur. Cebirsel olarak ise belirsizliği veren çarpanları sadeleştirecek bir düzenleme yapıp denk bir limit problemi elde edersiniz.

### Örnek 7: Eşlenik Yöntemi, L'Hôpital Kullanmadan

Hoca "L'Hôpital kullanmadan" çözülmesi istenen bir soru verdi:

$$\lim_{x\to5}\frac{4-\sqrt{3x+1}}{x^2-7x+10}$$

<!-- BELİRSİZ: Paydanın tam ifadesi altyazıda okunmuyor (yalnız "x² −" duyuluyor). x²−7x+10 kısa nottan alındı; derste söylenen sonuç (−1/8) bu payda ile tutarlı. -->

$x=5$ doğrudan yazılırsa $\frac00$ belirsizliği çıkar. Kök içeren bir ifade görüldüğünde eşlenik yöntemi (conjugate method) uygulanır: pay ve payda, $4-\sqrt{3x+1}$'in eşleniği olan $4+\sqrt{3x+1}$ ile çarpılır. Hiçbir şey değişmez, çünkü ifade 1 ile çarpılmış olur.

Hoca burada şunu vurguladı: Eşlenikle çarpınca farklı bir kural elde edilir, ama bu kural öncekine özdeştir. Bilgisayar açısından yapılacak iş artmıştır, çünkü yeni bir kural tanımlanmıştır.

$(a-b)(a+b)=a^2-b^2$ özdeşliği kullanılır:

$$\lim_{x\to5}\frac{16-(3x+1)}{(x^2-7x+10)(4+\sqrt{3x+1})}=\lim_{x\to5}\frac{15-3x}{(x^2-7x+10)(4+\sqrt{3x+1})}$$

Pay $-3(x-5)$, payda $(x-2)(x-5)(4+\sqrt{3x+1})$ olarak yazılır (ara adım eklendi):

$$=\lim_{x\to5}\frac{-3(x-5)}{(x-2)(x-5)(4+\sqrt{3x+1})}=\lim_{x\to5}\frac{-3}{(x-2)(4+\sqrt{3x+1})}$$

$x=5$ yazılır: $x-2=3$, $\sqrt{16}=4$, $4+4=8$.

$$=\frac{-3}{3\cdot8}=-\frac18$$

Hocanın söylediği sonuç $-\frac18$'dir. Sympy sonucu da $-\frac18$.

Hoca bazen bu yolun, bazen de L'Hôpital kuralının avantajlı olduğunu söyledi. L'Hôpital kuralı ileride öğretilecek. Ama önce bir fonksiyonun limitini L'Hôpital'siz hesaplamayı öğrenmek gerekir, çünkü L'Hôpital kuralının uygulanamadığı sorular vardır.

## 14. Teğet Doğrunun Eğimi

### Örnek 8: Eğimi Limit Olarak Yazma

**Soru:** $m$, bir fonksiyonun grafiğine $(-3,-9)$ noktasında teğet olan doğrunun eğimi olsun. $m$'yi limit olarak ifade edin. $m$'yi hesaplamayın.

Hoca grafiğin nasıl olduğunun önemli olmadığını söyledi ve temsili bir eğri çizdi. $x=-3$ noktasında fonksiyon değeri $-9$'dur. Grafik üzerinde $(x,f(x))$ noktası ile $(-3,-9)$ noktasını birleştiren kesenin eğimi bir açının tanjantıdır:

$$\frac{f(x)-f(-3)}{x-(-3)}$$

$x\to-3$ iken bu kesen teğet doğruya yaklaşır:

$$m=\lim_{x\to-3}\frac{f(x)-f(-3)}{x-(-3)}$$

<!-- BELİRSİZ: Soruda verilen f(x)'in kuralı (hoca "bu rasyonel fonksiyon" diyor) altyazıda okunmuyor. -->

### 14.1 Genel Durum

$[x_0,x]$ aralığında

$$\frac{\Delta f}{\Delta x}=\frac{f(x)-f(x_0)}{x-x_0}$$

oranı $f$'nin ortalama değişim hızıdır. Bu oran, kesen doğrunun eğimidir (bir açının tanjantı). $x\to x_0$ iken $(x_0,f(x_0))$ noktasındaki teğet doğrunun eğimi elde edilir:

$$m=\lim_{x\to x_0}\frac{f(x)-f(x_0)}{x-x_0}$$

$h=x-x_0$ yazılırsa $x\to x_0$ iken $h\to0$ olur. Denk limit problemi:

$$m=\lim_{h\to0}\frac{f(x_0+h)-f(x_0)}{h}$$

Bu iki limit problemi birbirine denktir. Hoca burada limit kavramıyla bir fonksiyonun grafiğine teğet olan doğrunun eğiminin tanımlanabildiğine dikkat çekti.

## 15. Limit Kuralları

**Teorem (Limit kuralları):**

- **Ön koşul:** $f$ ve $g$'nin $a$ noktasında limiti olsun: $\lim_{x\to a}f(x)=L$, $\lim_{x\to a}g(x)=M$. $n$ pozitif tam sayı, $c$ sabit olsun.
- **Toplam ve fark:** $\lim_{x\to a}(f(x)\pm g(x))=L\pm M$.
- **Sabitle çarpım:** $\lim_{x\to a}cf(x)=cL$. $c$, limit değişkeni $x$'e göre sabit olduğu için dışarı alınır.
- **Çarpım:** $\lim_{x\to a}f(x)g(x)=LM$.
- **Bölüm:** $\lim_{x\to a}\dfrac{f(x)}{g(x)}=\dfrac LM$, $M\neq0$.
- **Kuvvet:** $\lim_{x\to a}[f(x)]^n=L^n$, $n$ pozitif tam sayı.
- **Kök:** $\lim_{x\to a}\sqrt[n]{f(x)}=\sqrt[n]{L}$. Burada $f$'nin pozitif ya da sıfır olduğu varsayılır.

> **Hocanın vurgusu:** Limit işlemini toplama, farka, çarpıma ya da bölüme dağıtmak ancak her terimin limiti varsa yapılabilir. Aksi halde bu işlem yapılamaz.

Hoca ardından bir uygulama verdi: $f$'nin 2 noktasındaki limiti 4, $g$'nin 2 noktasındaki limiti 5 olsun. Sabit kuralı, toplama kuralı ve kuvvet kuralı kullanılarak verilen bir ifadenin limiti hesaplanır. Bu dağıtma işlemleri yapılabilir, çünkü her terimin limiti vardır.

<!-- BELİRSİZ: Bu uygulamada limiti istenen ifade ve sonucu altyazıda okunmuyor (02:26:27-02:27:30 arası altyazı kopuk). -->

## 16. Çelişki Yöntemiyle Bir İspat

### Örnek 9: Bölümün Limiti Yoktur

**Soru:** $\lim_{x\to c}f(x)\neq0$ ve $\lim_{x\to c}g(x)=0$ olsun. $\lim_{x\to c}\dfrac{f(x)}{g(x)}$ limitinin var olmadığını gösterin.

**Çözüm (çelişki yöntemi, proof by contradiction):**

- Verilenler hipotezdir ($p$), gösterilmesi istenen amaçtır ($q$). Mantıksal ifade: $p\Rightarrow q$.
- Amacın değili (negation) doğru kabul edilir: $\lim_{x\to c}\frac{f(x)}{g(x)}$ var olsun ve değeri $L$ olsun. Limit varsa tektir.
- Pay ve payda $g(x)$ ile çarpılıp bölünür. Bu özdeş bir limit problemidir. Kabule göre bölümün limiti vardır, hipoteze göre $g$'nin limiti vardır. Bu yüzden çarpım kuralı uygulanabilir:

$$\lim_{x\to c}f(x)=\lim_{x\to c}\left(\frac{f(x)}{g(x)}\cdot g(x)\right)=\lim_{x\to c}\frac{f(x)}{g(x)}\cdot\lim_{x\to c}g(x)=L\cdot0=0$$

- Oysa soruda $\lim_{x\to c}f(x)\neq0$ verilmiştir. Bu bir çelişkidir.
- Çelişki, amacın değilini doğru kabul ederek elde edildi. Demek ki kabul yanlıştır.
- Kabul yanlışsa kabulün değili doğrudur. Yani limit yoktur.

**Soru:** Çözümü tekrar anlatabilir misiniz? **Cevap:** Hoca mantığı genel olarak yeniden anlattı:

- Bir amacınız var: bir önermenin doğru olduğunu göstermek.
- Önce önermenin değilini doğru kabul edersiniz.
- Bu kabulle ilerleyip bir çelişki elde ederseniz, önermenin değili yanlıştır.
- İki tarafın değili alınır: önermenin değilinin değili doğrudur.
- Bir şeyin değilinin değili kendisidir. Doğru bir şeyin değili yanlış, yanlış bir şeyin değili doğrudur.

Hoca bir benzetme yaptı: Göstermeye çalıştığınız şeyin aksini kabul edip gidiyorsunuz, gidiyorsunuz, tünelin ucu görünmüyor, ışık yok. O zaman kabulünüz yanlıştır.

> **Hocanın vurgusu:** Bu mantık ileride çok sık kullanılacak. Test biçimindeki sorularda bile çelişki yöntemi işe yarayabilir.

## 17. Tek Taraflı Limitler

**Tanım (Tek taraflı limitler, one-sided limits):**

- Sağ limit: $\lim_{x\to a^+}f(x)=L_1$. $x$, $a$'ya sağdan yaklaşır.
- Sol limit: $\lim_{x\to a^-}f(x)=L_2$. $x$, $a$'ya soldan yaklaşır.
- Parçalı tanımlı (piecewise defined) fonksiyonlarda $L_1$ ile $L_2$ farklı olabilir.
- $f$'nin $a$ noktasında limiti olması için sağ ve sol limit aynı olmalıdır: $\lim_{x\to a}f(x)$ var $\iff L_1=L_2$.

### Örnek 10: Grafikten Tek Taraflı Limit

Bir $g$ fonksiyonunun grafiğinde:

- $x\to2^+$ iken $g(x)\to1$.
- $x\to2^-$ iken $g(x)\to4$.

Sağ ve sol limit farklı olduğu için bu fonksiyonun $x=2$ noktasında limiti yoktur.

### Örnek 11: $x\to100^+$ İçin Limit

Hoca $x$ 100'e sağdan yaklaşırken bir $g(x)$ ifadesinin limitini sordu. İfadede kök vardır. Çözüm yolu: eşlenikle çarpıp bölmek. Eşlenik yöntemi, kurala özdeş yeni bir kural elde etmek için uygulanır. $x-100$ çarpanları sadeleşir ve geriye $\sqrt x+10$ kalır. Hoca limitin konmasını öğrencilere bıraktı.

<!-- BELİRSİZ: g(x)'in tam ifadesi altyazıda okunmuyor. Sadeleşmeden sonra √x+10 kaldığı söyleniyor. -->

> **Çözüm (derste verilmedi):** Sadeleşmeden sonra kalan ifade $\sqrt x+10$ ise, bu ifade $x=100$'de süreklidir ve doğrudan yerine koyma yapılır: $\lim_{x\to100^+}(\sqrt x+10)=\sqrt{100}+10=20$. Bu sonuç, hocanın söylediği sadeleşmiş ifadeye dayanır; özgün ifade altyazıda olmadığı için büyük olasılıkla doğrudur, ama kontrol edilmelidir.

## 18. Sıkıştırma (Sandwich) Teoremi

Hoca son konu olarak sıkıştırma teoremini (Sandwich Theorem / Squeezing Theorem) anlattı ve teoremin arkasındaki mantığa odaklanılmasını istedi.

**Teorem (Sıkıştırma teoremi):**

- $a$ civarındaki (around $a$) $x$ değerleri için $f(x)\le g(x)\le h(x)$ olsun.
- $\lim_{x\to a}f(x)=\lim_{x\to a}h(x)=L$ olsun.
- O zaman $\lim_{x\to a}g(x)=L$.
- $a$ sonlu bir sayı olmak zorunda değildir; $+\infty$ ya da $-\infty$ olabilir.

Sezgi: $g$'nin grafiği, $h$ ile $f$'nin grafikleri arasında kalır. Alt ve üst sınır aynı değere yaklaşıyorsa aradaki grafik de aynı değere yaklaşmak zorundadır.

**Soru:** Bunu tekrar anlatabilir misiniz? **Cevap:** Hoca basit bir örnek üzerinden anlattı (Örnek 12).

### Örnek 12: $\displaystyle\lim_{x\to\infty}\frac{\sin x}{x}$

- Sinüs için $-1\le\sin x\le1$.
- $x\to\infty$ olduğundan $x>0$ alınabilir. Eşitsizliğin her tarafı $x$'e bölünür, yön değişmez:

$$-\frac1x\le\frac{\sin x}{x}\le\frac1x$$

- $x\to\infty$ iken $-\frac1x\to0$ ve $\frac1x\to0$. Sabit bir terim bölü yeterince büyük bir sayı sıfıra gider.
- Alt ve üst sınır aynı değere (0) gittiği için, sıkıştırma teoremine göre ortadaki terim de 0'a gider:

$$\lim_{x\to\infty}\frac{\sin x}{x}=0$$

Sympy sonucu: 0. Hocanın yorumu: Sınırlı (bounded) bir ifade bölü sınırsız (unbounded) bir ifade, $x$ ilgili değere giderken sıfıra gider.

### Örnek 13: $\displaystyle\lim_{x\to0}\sin x=0$

Soru "sıkıştırma teoremini kullanarak aşağıdaki limitleri doğrulayın" biçimindeydi. Bunun için $\sin x$'i sıkıştıracak bir sıralama bulmak gerekir.

Hoca önce sınıfa sözlü olarak "$x$ sıfıra sağdan da soldan da giderken sinüs pozitif değer almaz mı?" diye sordu ve "evet" cevabını kabul etti. Sonra $0<x<1$ için $\sin x<x$ yazdı. Ama bu sıralamadan sonuca gidilemediğini fark etti. Sıkıştırma için iki taraflı bir sıralama gerekir.

> **Ders sonrası not:** $x$ sıfıra soldan yaklaşırken $\sin x$ negatiftir, sağdan yaklaşırken pozitiftir. Bu yüzden "iki taraftan da pozitif" ifadesi doğru değildir. Hoca da bu yoldan sonuç çıkmadığını görüp mutlak değerli sıralamaya geçti.

Hoca $y=|x|$ ve $y=\sin x$ grafiklerini birlikte gösterdi. Grafikten şu sıralama okunur:

$$-|x|\le\sin x\le|x|$$

> **Hocanın vurgusu:** Bu sıralama çok önemlidir.

- $x\to0$ iken $|x|\to0$ ve $-|x|\to0$. Burada belirsizlik yoktur.
- Sıkıştırma teoremine göre ortadaki terim de 0'a gider: $\lim_{x\to0}\sin x=0$.

Sympy ile $[-3,3]$ aralığında sayısal kontrol: $|\sin x|\le|x|$ her noktada sağlanıyor.

> **Ek bilgi (derste anlatılmadı):** $|\sin x|\le|x|$ eşitsizliği birim çemberden görülebilir: $\theta$ açısının gördüğü yayın uzunluğu $|\theta|$'dır, $\sin\theta$ ise uç noktanın sinüs eksenine izdüşümüdür. Dik izdüşüm, yayın uzunluğundan uzun olamaz.

### Örnek 14: $\displaystyle\lim_{x\to0}\cos x=1$

Üç fonksiyon tanımlanır:

- $f(x)=0$ (sabit fonksiyon),
- $g(x)=1-\cos x$,
- $h(x)=|x|$.

Sıralama:

$$0\le1-\cos x\le|x|$$

- $x\to0$ iken $f(x)=0$ sabit olduğundan limiti 0'dır.
- $x\to0$ iken $h(x)=|x|\to0$.
- Alt ve üst sınır fonksiyonları aynı limite sahiptir. Sıkıştırma teoremine göre $\lim_{x\to0}(1-\cos x)=0$.
- Her terimin limiti olduğu için limit işlemi farka dağıtılır. Sabitin limiti kendisidir:

$$\lim_{x\to0}(1-\cos x)=1-\lim_{x\to0}\cos x=0\;\Rightarrow\;\lim_{x\to0}\cos x=1$$

Bir öğrencinin isteği üzerine hoca bu ispatı bir kez daha adım adım anlattı. Sympy ile $0\le1-\cos x\le|x|$ sıralaması $[-3,3]$ aralığında sayısal olarak doğrulandı; limit sonucu 1'dir.

> **Hocanın vurgusu:** Sıkıştırma teoremi önemlidir. Bu tür ispatlar klasik sorularda gelir. Ama bu sorulardaki yaklaşım test biçimindeki sorularda da kullanılabilir. Sıkıştırma teoremini kullanan çözümün arkasındaki mantığı anlayın. Bu tür soruları göz ardı etmeyin.

Ders sonunda bir öğrenci "biraz daha yavaş gitmek daha iyi olur" dedi. Hoca şu tavsiyeyi verdi: Önce her tanımın arkasındaki mantığı anlamaya çalışın, çözümlere odaklanmayın. Alıştırma derslerinde çözümlere odaklanılacak ve önceki dönemlerin test soruları da çözülecek.

## Örnek Sorular

Bu derste video karesi yok. Aşağıdaki sorular yalnız derste tahtada çözülen ya da sözlü sorulan sorulardır. Ayrıntılı çözümler ilgili bölümlerdedir.

**Soru 1** (derste sözlü, 00:06:43): Başarının matematiksel tanımı nedir?

- **Çözüm (derste verildi):** Sorumluluk fonksiyonu $R=f(t)$ ile ortalama başarı $\frac{R(t)-R(t_0)}{t-t_0}$, anlık başarı $\lim_{t\to t_0}\frac{R(t)-R(t_0)}{t-t_0}$, yani $R$'nin türevidir (Bölüm 2).

**Soru 2** (derste sözlü, 00:27:44): Çember bir fonksiyonun grafiği midir?

- **Çözüm (derste verildi):** Hayır. Bir düşey doğru çemberi iki noktada keser. Ama $y_\pm=\pm\sqrt{1-x^2}$ ve $x_\pm=\pm\sqrt{1-y^2}$ yarım çemberleri birer fonksiyonun grafiğidir (Bölüm 4.2).

**Soru 3** (derste, 00:46:10): Tabloyla verilen $f$ ve $g$ için $(f\circ g)(5)$ nedir?

- **Çözüm (derste verildi):** $g(5)=1$, $f(1)=6$, sonuç 6 (Örnek 5). <!-- BELİRSİZ: Tablonun kendisi altyazıda yok. -->

**Soru 4** (derste, 01:54:42): $\lim_{x\to1}\frac{\sqrt x-1}{x-1}$ limitini tablodan ve cebirle bulun.

- **Çözüm (derste verildi):** $\frac12$ (Örnek 6).

**Soru 5** (derste, 01:59:20): L'Hôpital kullanmadan $\lim_{x\to5}\frac{4-\sqrt{3x+1}}{x^2-7x+10}$ limitini bulun.

- **Çözüm (derste verildi):** Eşlenikle çarpılır; sonuç $-\frac18$ (Örnek 7). <!-- BELİRSİZ: Payda altyazıda tam okunmuyor. -->

**Soru 6** (derste, 02:18:38): $m$, grafiğe $(-3,-9)$ noktasında teğet olan doğrunun eğimi olsun. $m$'yi limit olarak ifade edin, hesaplamayın.

- **Çözüm (derste verildi):** $m=\lim_{x\to-3}\frac{f(x)-f(-3)}{x-(-3)}$ (Örnek 8). <!-- BELİRSİZ: f(x)'in kuralı altyazıda yok. -->

**Soru 7** (derste, 02:27:48): $\lim_{x\to c}f(x)\neq0$ ve $\lim_{x\to c}g(x)=0$ ise $\lim_{x\to c}\frac{f(x)}{g(x)}$'in var olmadığını gösterin.

- **Çözüm (derste verildi):** Çelişki yöntemi (Örnek 9).

**Soru 8** (derste, 02:37:49): Grafikte $x\to2^+$ iken $g(x)\to1$, $x\to2^-$ iken $g(x)\to4$. $x=2$'de limit var mı?

- **Çözüm (derste verildi):** Yok, çünkü sağ ve sol limit farklı (Örnek 10).

**Soru 9** (derste, 02:38:33): Kök içeren bir $g(x)$ için $\lim_{x\to100^+}g(x)$ limitini bulun. <!-- BELİRSİZ: g(x)'in ifadesi altyazıda yok. -->

> **Çözüm (derste verilmedi):** Hoca eşlenikle sadeleştirme sonrası $\sqrt x+10$ kaldığını söyledi. Buradan $\lim_{x\to100^+}(\sqrt x+10)=20$ (Örnek 11).

**Soru 10** (derste, 02:46:51): Sıkıştırma teoremini kullanarak şu limitleri doğrulayın: $\lim_{x\to0}\sin x=0$ ve $\lim_{x\to0}\cos x=1$.

- **Çözüm (derste verildi):** $-|x|\le\sin x\le|x|$ ve $0\le1-\cos x\le|x|$ sıralamaları ile (Örnek 13 ve 14). Aynı yaklaşımla $\lim_{x\to\infty}\frac{\sin x}{x}=0$ da gösterildi (Örnek 12).

## Dersin Toparlaması

Bu ilk derste önce dersin kapsamı çizildi ve "başarının matematiksel tanımı" sorusuyla limit ve türevin neden gerekli olduğu gösterildi: anlık başarı, sorumluluk fonksiyonunun türevidir. Ardından fonksiyon, tanım kümesi, değer kümesi ve görüntü kümesi tanımlandı. Düşey doğru testi, çember örneği, cebirsel işlemler, bileşke ve çift/tek fonksiyon simetrisi işlendi. Polinom, rasyonel ve mutlak değer fonksiyonlarından sonra trigonometrik fonksiyonlar birim çember üzerinden kuruldu. Toplam, çift açı ve kuvvet indirme özdeşlikleri ile periyot verildi. Sinüs, kosekant, kosinüs, sekant, tanjant ve kotanjant grafiklerinin ezberlenmeden nasıl çıkarılacağı gösterildi.

Dersin ikinci yarısında limit kavramına girildi. Bir noktadaki değer ile o noktadaki limitin farklı şeyler olduğu üç durumla gösterildi. Limit tablodan, çarpanlara ayırarak ve eşlenik yöntemiyle hesaplandı. Teğet doğrunun eğimi limit olarak yazıldı. Limit kuralları, çelişki yöntemiyle bir ispat, tek taraflı limitler ve sıkıştırma teoremi işlendi. Hoca bir sonraki derste bu konular üzerine soru çözüleceğini söyledi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
