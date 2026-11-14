# Ders 10 Genişletilmiş Notu: Hiperbolik Fonksiyonlar, L'Hôpital Kuralı ve Belirsiz Formlar

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Birim Çember ve Birim Hiperbol
- 2. Hiperbolik Fonksiyonların Tanımı
- 3. Hiperbolik Özdeşlikler
- 4. Hiperbolik Fonksiyonların Türevleri
- 5. Ters Hiperbolik Fonksiyonlar
- 6. Ters Hiperbolik Fonksiyonların Türevi
- 7. L'Hôpital Kuralı
- 8. $\infty/\infty$ Belirsizliği
- 9. $0\cdot\infty$ ve $\infty-\infty$ Belirsizlikleri
- 10. L'Hôpital Kuralı Üzerine Notlar
- 11. Üstel Belirsizlikler
- 12. $e^a$ Limiti ve Benzetme Yöntemi
- 13. $0^0$ Tipi ve $u^u \to 1$ Kuralı
- 14. Örnek Sorular

## 1. Birim Çember ve Birim Hiperbol

Ders, bir önceki dersin kaldığı yerden başladı. Hoca bu derste hiperbolik fonksiyonlardan (hyperbolic functions) bahsedeceğini, zaman kalırsa genel uygulama olarak soru çözeceğini söyledi. Ders İngilizce anlatıldı, arada Türkçe açıklamalar yapıldı.

Hiperbolik fonksiyonlara geçmeden önce hoca trigonometrik fonksiyonlarla ilgili temel bilgileri hatırlattı. Çünkü iki fonksiyon ailesi arasında güçlü bir benzerlik (analogy) vardır.

### 1.1 Birim çember

Yarıçapı $r$ olan bir çemberde, merkez açısı $\theta$ olan dairesel dilimin alanı açının radyan değeri cinsinden yazılabilir. Hoca burada $\theta$'nın derece değil radyan olduğunu özellikle belirtti ve bu açıya $t$ dedi.

<!-- BELİRSİZ: Dilim alanının formülü altyazıda okunmuyor (00:03:07). Standart formül $\frac{1}{2}r^2\theta$'dır; hoca tahtaya bunu yazmış olabilir. -->

Birim çemberin (unit circle) cebirsel denklemi

$$x^2 + y^2 = 1$$

olup Pisagor teoreminden (Pythagorean theorem) gelir. Çember üzerindeki bir noktanın apsis ve ordinatı açının radyan değeri $t$ cinsinden yazılabilir:

$$x = \cos t, \qquad y = \sin t.$$

Bu, çemberin parametrik denklemidir (parametric equation). Bu ifadeler cebirsel denklemde yerine konunca $\cos^2 t + \sin^2 t = 1$ elde edilir. Yani parametrik denklemler birim çemberin denklemini sağlar.

### 1.2 Birim hiperbol

Birim hiperbol eğrisinin (unit hyperbolic curve) denklemi

$$x^2 - y^2 = 1$$

şeklindedir. Hoca grafiği ayrı bir sayfada çizdi. Grafik birbirinden ayrık iki eğriden (two disjoint curves) oluşur. Birim çemberin denkleminden tek farkı ortadaki eksi işaretidir.

Hoca şu soruyu sordu: Çember için açıya bağlı bir parametrik denklem bulduk; hiperbol için de bir parametrik denklem bulabilir miyiz? Bu sorunun cevabı hiperbolik fonksiyonları verir. Çemberin parametrik denklemi kurulurken trigonometrik kosinüs ve sinüs ortaya çıkar. Hiperbolün parametrik denklemi kurulmaya çalışılınca "trigonometrik hiperbolik fonksiyonlar" ortaya çıkar.

## 2. Hiperbolik Fonksiyonların Tanımı

Hoca ana ders notuna dönerek tanımları verdi. "cosh" gösteriminin yalnız bir gösterim olduğunu söyledi. Trigonometrik fonksiyonlarla benzerlik nedeniyle bu ad tercih edilmiştir. Hoca tanım sembolü için bilgisayar biliminin dilinde ":=" gibi "tanım" anlamına gelen bir sembol kullandığını belirtti.

**Tanım (hiperbolik kosinüs ve hiperbolik sinüs):**

- $x = \cosh t := \dfrac{e^t + e^{-t}}{2}$
- $y = \sinh t := \dfrac{e^t - e^{-t}}{2}$

Bu $x$ ve $y$ ifadeleri $x^2 - y^2 = 1$ denkleminde yerine konunca denklem sağlanır. Yani bunlar birim hiperbolün parametrik denklemleridir.

**Tanım (diğer hiperbolik fonksiyonlar):**

- $\tanh x = \dfrac{\sinh x}{\cosh x}$
- $\coth x = \dfrac{\cosh x}{\sinh x}$
- $\operatorname{sech} x = \dfrac{1}{\cosh x} = \dfrac{2}{e^x + e^{-x}}$
- $\operatorname{csch} x = \dfrac{1}{\sinh x}$

> **Hocanın vurgusu:** Her şeyi ezberlemenize gerek yok. $\cosh$ ve $\sinh$ tanımını bilmek yeterli. Bütün hiperbolik fonksiyonlar bu iki temel tanımdan çıkar.

## 3. Hiperbolik Özdeşlikler

### 3.1 Temel özdeşlik

Trigonometrideki $\cos^2 x + \sin^2 x = 1$ özdeşliği birim çemberdeki Pisagor teoreminden gelir. Hiperbolik fonksiyonlardaki karşılığı birim hiperbolden gelir:

$$\cosh^2 x - \sinh^2 x = 1.$$

Hoca bunun hiperbolik fonksiyonlar için çok önemli bir özdeşlik olduğunu söyledi. Tanımlar yerine konup açılıp sadeleştirilince sonuç 1 çıkar (ara adım eklendi):

$$\left(\frac{e^x+e^{-x}}{2}\right)^2 - \left(\frac{e^x-e^{-x}}{2}\right)^2 = \frac{(e^{2x}+2+e^{-2x}) - (e^{2x}-2+e^{-2x})}{4} = \frac{4}{4} = 1.$$

### 3.2 Bölme ile elde edilen özdeşlik

Temel özdeşliğin iki tarafı $\cosh^2 x$'e bölünürse

$$1 - \tanh^2 x = \operatorname{sech}^2 x$$

elde edilir. Trigonometrideki karşılığı $\sec^2 x = 1 + \tan^2 x$'tir. Hoca iki teori arasındaki tek farkın yine işaret olduğunu gösterdi: birinde eksi, ötekinde artı vardır.

> **Ders sonrası not:** Altyazıda bu özdeşliğin sağ tarafı "sin hyperbolic square x" olarak geçiyor (00:11:23). Doğrusu $1 - \tanh^2 x = \operatorname{sech}^2 x$'tir. Büyük olasılıkla hoca "sech" dedi, otomatik altyazı "sin" diye yazdı.

### 3.3 Çift açı formülü

$$\sinh 2x = 2\sinh x\cosh x.$$

Hoca bunu tanımdan gösterdi. $\sinh a = \dfrac{e^a - e^{-a}}{2}$ tanımında $a = 2x$ alınır:

$$\sinh 2x = \frac{e^{2x} - e^{-2x}}{2} = \frac{(e^x - e^{-x})(e^x + e^{-x})}{2} = 2\cdot\frac{e^x - e^{-x}}{2}\cdot\frac{e^x + e^{-x}}{2}.$$

Son ifade $2\sinh x\cosh x$'tir (iki kare farkı açılımı ara adım olarak eklendi).

### 3.4 Tek ve çift olma

<!-- BELİRSİZ: 00:13:11 civarında altyazı döngüye giriyor ("bu yukarıda" tekrarı); bu kısımdaki anlatım okunmuyor. Sonraki kısımdan tek/çift olma konusu işlendiği anlaşılıyor. -->

$\sinh a$ tanımında $a$ yerine $-a$ konunca

$$\sinh(-x) = -\sinh x$$

bulunur. Yani $f(-x) = -f(x)$; $\sinh$ tek fonksiyondur (odd function). Benzer şekilde $\cosh(-x) = \cosh x$ olur; $\cosh$ çift fonksiyondur (even function). $\tanh x = \dfrac{\sinh x}{\cosh x}$ tanımı ve bu tek/çift bilgisi kullanılınca $\tanh x$'in de tek fonksiyon olduğu görülür (tek bölü çift tektir).

### 3.5 Toplama formülleri

Hoca bu özdeşliklerin hepsinin temel tanımlarla ispatlanabileceğini söyledi.

- $\cosh(a+b) = \cosh a\cosh b + \sinh a\sinh b$. Trigonometrideki $\cos(a+b) = \cos a\cos b - \sin a\sin b$ formülünden tek farkı işarettir.
- $\sinh(a+b) = \sinh a\cosh b + \cosh a\sinh b$. Bu, trigonometrideki $\sin(a+b)$ formülüyle aynı yapıdadır; fark yoktur.
- $\cosh 2x = \cosh^2 x + \sinh^2 x$. Trigonometride $\cos 2x = \cos^2 x - \sin^2 x$'tir; burada artı, orada eksi vardır.

<!-- BELİRSİZ: 00:14:36 civarında altyazı bozuk ("x'y'y'ye kadar yüksek"); bu kısımda hangi özdeşliğin ispatlandığı okunmuyor. -->

## 4. Hiperbolik Fonksiyonların Türevleri

### 4.1 Sık yapılan hata: tanımları karıştırmak

Hoca türevlere geçmeden önce öğrencilerin sıkça $\cosh$ ile $\sinh$ tanımını karıştırdığını söyledi. Tanımı unuttuğunuzu varsayın. Bildiğiniz tek şey hiperbolün cebirsel denklemi $x^2 - y^2 = 1$ olsun. Hoca tanımları bilerek ters yazdı:

$$\cosh t \overset{?}{=} \frac{e^t - e^{-t}}{2}, \qquad \sinh t \overset{?}{=} \frac{e^t + e^{-t}}{2}.$$

Bu parametrik denklemler $x^2 - y^2 = 1$ denkleminde yerine konunca bir çelişki çıkar (sonuç $-1$ olur, ara adım eklendi). Bu yüzden tanımların yeri değiştirilmelidir. Doğru tanım Bölüm 2'deki tanımdır.

> **Hocanın vurgusu:** Öğrenciler genellikle bu iki tanımı karıştırıyor. Şüphedeyseniz $x^2 - y^2 = 1$ denklemine koyup kontrol edin.

### 4.2 $\cosh$ ve $\sinh$ türevi

Tanımda $t$ yerine $x$ yazılıp $x$'e göre türev alınır:

$$(\cosh x)' = \left(\frac{e^x + e^{-x}}{2}\right)' = \frac{e^x - e^{-x}}{2} = \sinh x,$$

$$(\sinh x)' = \left(\frac{e^x - e^{-x}}{2}\right)' = \frac{e^x + e^{-x}}{2} = \cosh x.$$

Hoca bunun trigonometrik fonksiyonların türevine çok benzediğini söyledi. Fark şudur: trigonometride $(\cos x)' = -\sin x$'tir, burada eksi işareti yoktur.

### 4.3 Diğer hiperbolik fonksiyonların türevi

**Türev tablosu:**

- $(\tanh x)' = \operatorname{sech}^2 x = 1 - \tanh^2 x$
- $(\coth x)' = -\operatorname{csch}^2 x$
- $(\operatorname{sech} x)' = -\operatorname{sech} x\tanh x$
- $(\operatorname{csch} x)' = -\operatorname{csch} x\coth x$

$\tanh x$'in türevi trigonometrideki $(\tan x)' = \sec^2 x = 1 + \tan^2 x$ ile aynı yapıdadır; tek fark $1 - \tanh^2 x$'teki eksidir. $\coth x$'in türevinde ise trigonometrideki gibi bir eksi işareti vardır.

$\operatorname{sech} x = \dfrac{1}{\cosh x}$ olduğu için türevi bölüm kuralıyla (quotient rule) bulunur:

$$(\operatorname{sech} x)' = \frac{0\cdot\cosh x - 1\cdot\sinh x}{\cosh^2 x} = -\frac{1}{\cosh x}\cdot\frac{\sinh x}{\cosh x} = -\operatorname{sech} x\tanh x.$$

Aynı yolla $\operatorname{csch} x = \dfrac{1}{\sinh x}$ türevlenince $-\operatorname{csch} x\coth x$ bulunur (ara adımlar eklendi).

<!-- BELİRSİZ: 00:18:38-00:18:52 arasında altyazı bozuk ("derivation of x as sin x", "1 minus sin x is 1 minus tan x"); $\tanh$ türevinin anlatıldığı anlaşılıyor, ifadeler kısa nottaki tabloyla uyumlu olarak verildi. -->

> **Hocanın vurgusu:** Hepsini ezberlemenize gerek yok. Tanımdan ve bölüm kuralından çıkar.

## 5. Ters Hiperbolik Fonksiyonlar

### 5.1 Ters fonksiyonun şartı

Bir fonksiyonun tersinden bahsetmek için fonksiyon bire bir (one-to-one) ve örten (onto) olmalıdır.

$y = \cosh x = \dfrac{e^x + e^{-x}}{2}$ fonksiyonu tüm reel sayılarda bire bir değildir; çift fonksiyon olduğu için grafiği $y$ eksenine göre simetriktir. Bu yüzden grafiğin yalnız bir parçası alınır: $x \ge 0$ olan kısım. Bu parçanın $y$ eksenine dik izdüşümü (orthogonal projection) değer kümesini (range) verir: $[1, \infty)$.

**Tanım ($\operatorname{arccosh}$):**

- $\cosh: [0, \infty) \to [1, \infty)$ bire bir ve örtendir.
- Tersi $\operatorname{arccosh}: [1, \infty) \to [0, \infty)$ fonksiyonudur.
- $y = \operatorname{arccosh} x \iff \cosh y = x$.

Hoca burada önce aralığı "1'den sonsuza" diye söyledi, sonra düzeltip $\cosh$'un tanım kümesinin $0$'dan sonsuza olduğunu belirtti.

Ters fonksiyonun grafiği, $f$'nin grafiğinin $y = x$ doğrusuna göre simetriği alınarak elde edilir.

**Tanım ($\operatorname{arcsinh}$):** $\sinh$ tüm reel sayılarda bire bir ve örtendir. Bu yüzden kısıtlama gerekmez:

$$y = \operatorname{arcsinh} x \iff x = \sinh y.$$

Hoca benzer şekilde $\operatorname{arctanh}$'in de tanımlanabileceğini söyleyip geçti.

### 5.2 $\operatorname{arcsinh}$'in logaritma ile ifadesi

Hoca $\operatorname{arcsinh}$'i logaritmik fonksiyon cinsinden yazdı. Amaç $x = \sinh y$ eşitliğinden $y$'yi $x$ cinsinden çözmektir.

**Adım 1.** Tanımı yaz:

$$x = \sinh y = \frac{e^y - e^{-y}}{2} \quad\Longrightarrow\quad e^y - 2x - e^{-y} = 0.$$

**Adım 2.** Denklemi $e^y$ ile çarp:

$$e^{2y} - 2x\,e^y - 1 = 0.$$

Bu, $e^y$ cinsinden ikinci derece (quadratic) bir denklemdir.

> **Ders sonrası not:** Altyazıda bu adım "iki tarafın karesini al" diye geçiyor (00:25:06). Doğru adım denklemi $e^y$ ile çarpmaktır; böylece $e^y$ cinsinden ikinci derece denklem elde edilir.

**Adım 3.** Hoca lisede öğrenilen ikinci derece denklem çözümünü hatırlattı. $ax^2 + bx + c = 0$ için diskriminant $\Delta = b^2 - 4ac$'dir. $\Delta > 0$ ise iki reel kök vardır:

$$\frac{-b \pm \sqrt{\Delta}}{2a}.$$

Hoca diskriminantı önce kök içinde yazdı, sonra "burada kök yok" diyerek düzeltti.

<!-- BELİRSİZ: 00:26:09 civarında altyazı döngüye giriyor ("bu kısımda" tekrarı); kökler bulunurken söylenen ara adımlar okunmuyor. -->

Denklemde $a = 1$, $b = -2x$, $c = -1$ alınınca (ara adım eklendi):

$$e^y = \frac{2x \pm \sqrt{4x^2 + 4}}{2} = x \pm \sqrt{x^2 + 1}.$$

**Adım 4.** $e^y > 0$ olmalıdır. $x - \sqrt{x^2+1}$ her zaman negatiftir. Bu yüzden pozitif kök seçilir:

$$e^y = x + \sqrt{x^2 + 1}.$$

Hoca bunun tanım ve değer kümelerinden geldiğini vurguladı: negatif kök seçilemez.

**Sonuç:**

$$\operatorname{arcsinh} x = \ln\left(x + \sqrt{x^2 + 1}\right).$$

### 5.3 Diğer ters hiperbolik fonksiyonlar

Hoca benzer formüllerin ders notunda olduğunu söyledi ve Türkçe açıkladı:

- $\operatorname{arccosh} x = \ln\left(x + \sqrt{x^2 - 1}\right)$, $x \ge 1$. Sinüsteki ile tek farkı kök içindeki işarettir: sinüste artı, kosinüste eksi.
- $\operatorname{arctanh} x = \dfrac{1}{2}\ln\dfrac{1+x}{1-x}$, $|x| < 1$. İkisinin oranı alınıp biraz düzenleme yapılınca gelir; doğrudan gelmez.

<!-- BELİRSİZ: $\operatorname{arccosh}$ ve $\operatorname{arctanh}$ formüllerinin tam hali altyazıda okunmuyor; hoca yalnız sözlü farkı anlattı. Formüller kısa notla uyumlu standart formüllerdir. -->

> **Hocanın vurgusu:** Sınavda hiperbolik fonksiyon soruları basit gelir, bundan daha karmaşık olmaz. Hiperbolik fonksiyonlarda yalnız birkaçını çıkarmayı bilmeniz yeterli. $\cosh x$'i bilin. İkinci derece denklemin kök formülünü biliyorsanız ters fonksiyonu 30 saniyede bulursunuz.

## 6. Ters Hiperbolik Fonksiyonların Türevi

Hoca $\operatorname{arcsinh} x$'in türevini çıkardı. Burada $y$, $x$'e bağlıdır; $x$ bağımsız değişkendir ve $\dfrac{dy}{dx}$ aranır.

**Adım 1.** Denk ifadenin sağ tarafını kullan: $x = \sinh y$.

**Adım 2.** İki tarafın $x$'e göre türevini al. $y$, $x$'e bağlı olduğu için zincir kuralı (chain rule) gerekir:

$$1 = \cosh y\cdot\frac{dy}{dx} \quad\Longrightarrow\quad \frac{dy}{dx} = \frac{1}{\cosh y}.$$

**Adım 3.** $\cosh y$'yi $\sinh y$ cinsinden yaz. $\cosh^2 y - \sinh^2 y = 1$ ve $\cosh y > 0$ olduğundan $\cosh y = \sqrt{1 + \sinh^2 y} = \sqrt{x^2 + 1}$ olur.

**Sonuç:**

$$\frac{d}{dx}\operatorname{arcsinh} x = \frac{1}{\sqrt{x^2+1}}, \qquad \frac{d}{dx}\operatorname{arcsinh} u(x) = \frac{u'(x)}{\sqrt{u(x)^2+1}}.$$

İkinci formül zincir kuralıyla elde edilir. Hoca $\operatorname{arccosh} x$, $\operatorname{arctanh} x$ ve $\operatorname{arcsech} x$ türevlerinin de benzer şekilde bulunabileceğini söyledi ve bunları öğrencilere bıraktı (sonuçlar Örnek Sorular bölümünde).

## 7. L'Hôpital Kuralı

Hoca hiperbolik fonksiyonları bitirip L'Hôpital kuralına (L'Hôpital's rule) geçti.

### 7.1 Teorem

**Teorem (L'Hôpital kuralı, $0/0$ hali):**

- $f$ ve $g$, $a$ noktasını içeren açık bir $I$ aralığında türevlenebilir olsun.
- $x \neq a$ iken $I$ üzerinde $g'(x) \neq 0$ olsun.
- $\displaystyle\lim_{x\to a} f(x) = 0$ ve $\displaystyle\lim_{x\to a} g(x) = 0$ olsun. Yani $\dfrac{0}{0}$ belirsizliği (indeterminate form) vardır.
- Bu durumda

$$\lim_{x\to a}\frac{f(x)}{g(x)} = \lim_{x\to a}\frac{f'(x)}{g'(x)}.$$

Hoca kuralı şöyle yorumladı: $x \to a$ iken $f$ ile $g$'nin anlık değişim oranlarının (instantaneous rate of change) oranının limiti, fonksiyonların oranının limitine eşittir. Türkçe olarak da tekrarladı: "Fonksiyonların oranının limiti, değişim oranlarının oranının limitine eşit oluyor."

> **Hocanın vurgusu:** L'Hôpital'ı uygulamak için $\dfrac{0}{0}$ belirsizliğini yakalamanız lazım. Aksi durumda uygulayamazsınız.

> **Ek bilgi (derste anlatılmadı):** Kitaplarda kural, sağdaki $\lim f'/g'$ limiti var olduğunda (ya da $\pm\infty$ olduğunda) geçerli diye verilir. Kural tek yönlü limitler ($x \to a^+$, $x \to a^-$) ve $x \to \pm\infty$ için de geçerlidir.

### 7.2 Basit örnek: iki doğrusal fonksiyon

Hoca kuralı daha iyi anlatmak için iki doğrusal fonksiyon aldı. $f(a) = g(a) = 0$, $f'(x) = 4$ ve $g'(x) = 2$ olsun. Yani $f(x) = 4(x-a)$, $g(x) = 2(x-a)$ (ara adım eklendi).

<!-- BELİRSİZ: Fonksiyonların tam ifadesi altyazıda okunmuyor (00:35:54); yalnız $f(a)=g(a)=0$, $f'=4$, $g'=2$ söyleniyor. -->

- Oran: $\dfrac{f(x)}{g(x)} = \dfrac{4(x-a)}{2(x-a)} = \dfrac{4}{2} = 2$.
- Burada 4 ve 2, $f$ ve $g$'nin anlık değişim oranlarıdır; yani türevleridir.
- L'Hôpital ile de $\displaystyle\lim_{x\to a}\frac{f'(x)}{g'(x)} = \frac{4}{2} = 2$ bulunur. Sonuç aynıdır.
- Doğrudan yerine koyulursa $\dfrac{f(a)}{g(a)} = \dfrac{0}{0}$ çıkar.

### 7.3 İspat fikri: doğrusallaştırma

Hoca ispatın aslında çok basit olduğunu söyledi. Bir $f$ fonksiyonunun $a$'daki türevi, o noktadaki teğet doğrusunun eğimidir. $g$ için de aynısı geçerlidir.

Doğrusallaştırma (linearization) ile $a$ yakınında

$$f(x) \approx f(a) + f'(a)(x-a) = f'(a)(x-a), \qquad g(x) \approx g'(a)(x-a)$$

yazılır, çünkü $f(a) = g(a) = 0$'dır. Buradan

$$\frac{f(x)}{g(x)} \approx \frac{f'(a)(x-a)}{g'(a)(x-a)} = \frac{f'(a)}{g'(a)}.$$

Hoca buradaki sembolün eşitlik değil yaklaşıklık sembolü olduğunu vurguladı. İki tarafın limiti alınınca kural elde edilir. Hoca doğrusallaştırmanın geçen hafta işlendiğini hatırlattı.

### 7.4 Örnek 1: $0/0$ tipi limitler

**(a)** $\displaystyle\lim_{x\to 1}\frac{x^3 + x^2 - 2x}{x - 1}$

<!-- BELİRSİZ: Payın tam ifadesi altyazıda söylenmiyor; hoca yalnız türevini ($3x^2 + 2x - 2$) okudu. Pay, bu türevle ve kısa notla uyumlu olarak $x^3 + x^2 - 2x$ alındı. -->

- $x \to 1$ iken pay ve payda $0$'a gider. Belirsizlik $\dfrac{0}{0}$'dır.
- L'Hôpital: payın türevi bölü paydanın türevi:

$$\lim_{x\to 1}\frac{3x^2 + 2x - 2}{1} = 3 + 2 - 2 = 3.$$

- Türev alındıktan sonra belirsizliği yaratan $(x - 1)$ çarpanı ortadan kalkar. Cevap $3$'tür.

**(b)** $\displaystyle\lim_{x\to 0}\frac{\sqrt{9 + 3x} - 3}{x}$

<!-- BELİRSİZ: Fonksiyon altyazıda okunmuyor (00:40:14); hoca yalnız $0/0$ olduğunu ve cevabın $1/2$ çıktığını söyledi. İfade kısa nottan alındı. -->

- $x \to 0$ iken $\dfrac{0}{0}$ belirsizliği vardır.
- L'Hôpital (ara adım eklendi):

$$\lim_{x\to 0}\frac{\dfrac{3}{2\sqrt{9 + 3x}}}{1} = \frac{3}{2\cdot 3} = \frac{1}{2}.$$

### 7.5 Denk limitler

Hoca bilinen bazı limitleri L'Hôpital ile yeniden gösterdi.

- $\displaystyle\lim_{x\to 0}\frac{\sin ax}{bx} = \frac{a}{b}$. Bunu daha önce hesaplamayı biliyorduk. L'Hôpital ile doğrudan görülür: $\dfrac{a\cos ax}{b} \to \dfrac{a}{b}$.
- $\displaystyle\lim_{x\to 0}\frac{\arcsin ax}{bx}$: yine $\dfrac{0}{0}$. $\arcsin ax$'in türevi $\dfrac{a}{\sqrt{1 - a^2x^2}}$, $bx$'in türevi $b$'dir. $x \to 0$ iken sonuç $\dfrac{a}{b}$'dir.
- Hoca üçüncü bir limitin de aynı şekilde $\dfrac{0}{0}$ verdiğini, türevler alınınca aynı sonuca ulaşıldığını söyledi.

> **Hocanın vurgusu:** Bu dört limit birbirine denktir. Hepsi $\dfrac{a}{b}$'yi verir. L'Hôpital'dan görebilirsiniz.

<!-- BELİRSİZ: Dört denk limitten yalnız ikisi ($\sin$ ve $\arcsin$) altyazıda açıkça geçiyor; diğer ikisi büyük olasılıkla $\tan ax/bx$ ve $\arctan ax/bx$'tir. -->

## 8. $\infty/\infty$ Belirsizliği

L'Hôpital kuralının uygulanabildiği ikinci durum şudur: $x \to a$ iken $f(x) \to \pm\infty$ ve $g(x) \to \pm\infty$. Bu durumda $\dfrac{\infty}{\infty}$ belirsizliği vardır ve yine

$$\lim_{x\to a}\frac{f(x)}{g(x)} = \lim_{x\to a}\frac{f'(x)}{g'(x)}$$

denkliği geçerlidir.

> **Hocanın vurgusu:** L'Hôpital yalnız iki durumda uygulanır: $\dfrac{0}{0}$ ve $\dfrac{\infty}{\infty}$. Bunları yakalayamamışsanız ifadeyi bunlara benzetmeye çalışırsınız.

### 8.1 Örnek 2: polinom oranı

$$\lim_{x\to\infty}\frac{4x^3 - 6x^2 + 1}{2x^3 - 10x + 3}$$

<!-- BELİRSİZ: 00:43:04-00:43:30 arasında altyazı döngüye giriyor ("bu konuda" tekrarı). Fonksiyon altyazıda okunmuyor; yalnız "4 over 2", "3" ve "L'Hôpital's rule is 2" parçaları seçiliyor. İfade kısa nottan alındı. -->

- $x \to \infty$ iken pay ve payda $\infty$'a gider: $\dfrac{\infty}{\infty}$.
- L'Hôpital üç kez uygulanır (ara adımlar eklendi):

$$\frac{12x^2 - 12x}{6x^2 - 10} \;\to\; \frac{24x - 12}{12x} \;\to\; \frac{24}{12} = 2.$$

- Cevap $2$'dir. En yüksek dereceli terimlerin katsayı oranı $\dfrac{4}{2}$ ile aynıdır.

### 8.2 Örnek 3: $\dfrac{1 + \tan x}{\sec x}$

$$\lim_{x\to (\pi/2)^-}\frac{1 + \tan x}{\sec x}$$

Hoca $\tan x$'in grafiğini çizerek $x \to (\pi/2)^-$ iken $\tan x \to +\infty$ olduğunu gösterdi. $\sec x$ de $+\infty$'a gider. Belirsizlik $\dfrac{\infty}{\infty}$'dur.

<!-- BELİRSİZ: 00:44:31 civarında altyazı döngüye giriyor ("yukarı ile" tekrarı); çözüm adımları okunmuyor. Aşağıdaki adımlar standart çözümdür (ara adımlar eklendi). -->

$$\lim_{x\to(\pi/2)^-}\frac{\sec^2 x}{\sec x\tan x} = \lim_{x\to(\pi/2)^-}\frac{\sec x}{\tan x} = \lim_{x\to(\pi/2)^-}\frac{1}{\sin x} = 1.$$

## 9. $0\cdot\infty$ ve $\infty-\infty$ Belirsizlikleri

$0\cdot\infty$ ve $\infty - \infty$ da belirsizliktir. Bu belirsizliklere L'Hôpital doğrudan uygulanamaz. Önce fonksiyonun kuralı üzerinde oynanarak $\dfrac{0}{0}$ ya da $\dfrac{\infty}{\infty}$ formu elde edilir.

### 9.1 Örnek 4: $0\cdot\infty$ tipi

$$\lim_{x\to\infty} x^2\sin\frac{1}{4x^2}$$

- $x \to \infty$ iken $x^2 \to \infty$, $\sin\dfrac{1}{4x^2} \to \sin 0 = 0$. Belirsizlik $0\cdot\infty$'dur.
- $x^2$ paydaya $\dfrac{1}{x^2}$ olarak taşınır:

$$\lim_{x\to\infty}\frac{\sin\dfrac{1}{4x^2}}{\dfrac{1}{x^2}}.$$

- Şimdi pay ve payda $0$'a gider: $\dfrac{0}{0}$. L'Hôpital uygulanabilir.
- Payın türevi: $\cos\dfrac{1}{4x^2}\cdot\left(-\dfrac{1}{2x^3}\right)$. Paydanın türevi: $-\dfrac{2}{x^3}$ (ara adım eklendi).
- Oran: $\dfrac{1}{4}\cos\dfrac{1}{4x^2} \to \dfrac{1}{4}$.

<!-- BELİRSİZ: 00:46:13-00:46:41 arasında altyazı bozuk; sadeleştirme ve sonuç okunmuyor. Sonuç $1/4$ sympy ile doğrulandı. -->

### 9.2 Örnek 5: $\infty-\infty$ tipi

$$\lim_{x\to\infty}\left(x - \sqrt{x^2 - 3x}\right)$$

<!-- BELİRSİZ: Fonksiyon altyazıda söylenmiyor; yalnız $\infty-\infty$ olduğu, $x$'in ortak paranteze alındığı ve $t = 1/x$ değişken değiştirmesi yapıldığı söyleniyor. İfade kısa nottan alındı. -->

Hoca bu soruya önceki derslerdeki eşlenik yönteminin (conjugate method) de uygulanabileceğini söyledi. Ama burada eşlenik kullanmadan L'Hôpital ile çözdü.

- $x$ ortak paranteze alınır ($x > 0$): $x\left(1 - \sqrt{1 - \dfrac{3}{x}}\right)$.
- $\dfrac{0}{0}$ formu için $x$ paydaya $\dfrac{1}{x}$ olarak taşınır:

$$\lim_{x\to\infty}\frac{1 - \sqrt{1 - 3/x}}{1/x}.$$

- Hoca doğrudan türev almak yerine değişken değiştirmenin (change of variable) problemi basitleştirdiğini söyledi: $t = \dfrac{1}{x}$, $x \to \infty$ iken $t \to 0^+$.

$$\lim_{t\to 0^+}\frac{1 - \sqrt{1 - 3t}}{t}.$$

- L'Hôpital (ara adım eklendi): $\displaystyle\lim_{t\to 0^+}\frac{\dfrac{3}{2\sqrt{1 - 3t}}}{1} = \frac{3}{2}$.

### 9.3 Formül ezberi üzerine soru

**Soru:** $\infty - \infty$ için başka bir formül de kullanabilir miyiz?

**Cevap:** Hoca başka formül ezberlemediğini, yalnız eşlenik yöntemini ve L'Hôpital'ı bildiğini söyledi. Ders kitaplarında ve lise kitaplarında bir sürü formül verildiğini, bunun doğru olmadığını düşündüğünü ekledi. Öğrencinin söylediği formülle de aynı sonuç bulunur, ama o formül de bu iki yöntemden gelir.

> **Hocanın vurgusu:** Diğer bütün formüller bu iki ana yönteme dayanır. Formül ezberleyerek zihninizi zorlamayın. Belli başlı yöntemleri öğrenin; önemli formülleri nasıl çıkarıldığını göz önünde bulundurarak öğrenin.

Bu noktada 10 dakikalık ara verildi.

## 10. L'Hôpital Kuralı Üzerine Notlar

Aradan sonra hoca L'Hôpital kuralı hakkında vurgulamak istediği iki notu anlattı.

### 10.1 Not 1: Kural art arda uygulanabilir

L'Hôpital'ı uygulamak için $\dfrac{0}{0}$ ya da $\dfrac{\infty}{\infty}$ belirsizliği gerekir. Bir kez uygulandıktan sonra kesin bir sonuç bulunamazsa, yani yine belirsizlik varsa, işleme devam edilir. Kesin bir limit sonucu bulunana kadar kural tekrar tekrar uygulanır.

> **Hocanın vurgusu:** L'Hôpital bir defa uygulanacak diye bir şey yok. Gerçek sonucu elde edinceye kadar arka arkaya uygulanabilir.

### 10.2 Not 2: Limiti parçalamak

$$\lim_{x\to 0}\frac{x\cos^2 x}{\sin(x^2 - x)}$$

**Yol 1 (doğrudan L'Hôpital):** Kural doğrudan uygulanabilir. Ama paydaki $x\cos^2 x$ teriminin türevi için çarpım kuralı (product rule) gerekir. İşlem kalabalıklaşır.

**Yol 2 (parçalama):** $\cos^2 x \to 1$'dir. Bu çarpan $0$ ya da $\infty$ vermez, yani belirsizliğe katkı yapmaz. Limit için çarpım kuralı kullanılarak bu çarpan ayrılır:

$$\lim_{x\to 0}\cos^2 x\cdot\lim_{x\to 0}\frac{x}{\sin(x^2 - x)} = 1\cdot\lim_{x\to 0}\frac{x}{\sin(x^2 - x)}.$$

Kalan limit $\dfrac{0}{0}$ formundadır. L'Hôpital:

$$\lim_{x\to 0}\frac{1}{\cos(x^2 - x)\cdot(2x - 1)} = \frac{1}{1\cdot(-1)} = -1.$$

Cevap $-1$'dir.

> **Hocanın vurgusu:** Bazen doğrudan L'Hôpital uygulamak yerine limiti parçalamayı düşünün. Bazı parçalar zaten belli bir değere yaklaşır; burada $\cos^2 x \to 1$ gibi. Onları ayırın, L'Hôpital'ı yalnız belirsizliği veren kısma uygulayın. Hoca klasik sınav kâğıtlarında öğrencilerin buna dikkat etmediğini, işin "çorba olduğunu" söyledi.

## 11. Üstel Belirsizlikler

Hoca üstel belirsizliklere (exponential indeterminate forms) geçti. Bunları ezberlemeye gerek olmadığını söyledi. Bir ifadenin belirsiz olup olmadığını anlamak için logaritma alınır. Hoca bunun mantıksal açıdan kesin bir yol olmadığını, ama bu soruyu cevaplamak için kullanılabileceğini belirtti. Logaritma, üstel belirsizlikleri bilinen $0\cdot\infty$ belirsizliğine dönüştürür.

### 11.1 Belirsizlik tablosu

- $1^\infty$: $\ln\left(1^\infty\right) = \infty\cdot\ln 1 = \infty\cdot 0$. Belirsizdir.
- $0^0$: Burada taban $0^+$'dır, yani sıfıra yeterince yakın pozitif bir sayıdır. $0\cdot\ln 0^+ = 0\cdot(-\infty)$. Belirsizdir.
- $\infty^0$: $0\cdot\ln\infty = 0\cdot\infty$. Belirsizdir.
- $\infty^\infty$: $\infty\cdot\ln\infty = \infty\cdot\infty$. Belirsiz değildir, sonuç doğrudan $\infty$'dur.

$\ln 0^+$'ın değeri için hoca $\ln x$'in grafiğini hatırlattı. $x$ sağdan $0$'a yaklaşınca grafik sonsuza kadar aşağı iner:

$$\lim_{x\to 0^+}\ln x = -\infty.$$

Hoca tabloyu yazarken bir yerde $0^0$ durumunu önce "belirsiz değil, cevap $-\infty$" diye değerlendirdi. Sonra tahtada üsse $0$ yerine $\infty$ yazdığını fark edip düzeltti: $0^0$ belirsizdir.

<!-- BELİRSİZ: 01:11:43-01:14:41 arasında tahtadaki hatalı satırın tam hali altyazıdan okunmuyor. -->

> **Ek bilgi (derste anlatılmadı):** Büyük olasılıkla tahtadaki hatalı satır $0^\infty$ durumuna denk geliyordu. $0^\infty$ belirsiz değildir: $\ln\left(0^\infty\right) = \infty\cdot(-\infty) = -\infty$ olduğundan değer $e^{-\infty} = 0$'dır.

### 11.2 $1^\infty$ neden 1 değildir?

**Soru:** Bunun en yalın hali neydi? Logaritmayı neden aldınız?

**Cevap:** Hoca $1^\infty$'un belirsizlik olup olmadığını anlamaya çalıştığını söyledi. "1 üzeri sonsuz 1'e mi eşit, başka bir şeye mi?" Logaritma uygulayınca $\ln 1 = 0$ gelir ve $\infty\cdot 0$ elde edilir. Bu bilinen bir belirsizliktir. O halde $1^\infty$ da belirsizliktir.

> **Hocanın vurgusu:** Limitte $1^\infty$ yakalarsanız cevap 1 değildir. Bu bir belirsizliktir.

### 11.3 $\infty^\infty$ belirsiz değildir

Örneğin $\displaystyle\lim_{x\to\infty} x^x$ limitinde $\infty^\infty$ elde edilir. Bu belirsiz olmadığı için ifade üzerinde oynamaya gerek yoktur. Cevap doğrudan $\infty$'dur.

Hoca özetle üç tür üstel belirsizlik olduğunu söyledi: $0^0$, $1^\infty$, $\infty^0$. Bunları ezberlemeye gerek yoktur; logaritma uygulanarak belirsiz olup olmadığına karar verilebilir.

## 12. $e^a$ Limiti ve Benzetme Yöntemi

### 12.1 Temel limit: $\displaystyle\lim_{x\to 0}(1 + ax)^{1/x}$

Hoca bir $a$ sabiti alarak şu limiti hesapladı:

$$\lim_{x\to 0}(1 + ax)^{1/x}.$$

$x \to 0$ iken $1^{\infty}$ ya da $1^{-\infty}$ belirsizliği vardır (hangisi olduğu fark etmez). Cevap $1$ değildir.

**Adım 1.** $A = (1 + ax)^{1/x}$ olsun. İki tarafa doğal logaritma uygulanır. Logaritma kuralıyla $\dfrac{1}{x}$ üssü katsayı olarak öne gelir:

$$\ln A = \frac{1}{x}\ln(1 + ax) = \frac{\ln(1 + ax)}{x}.$$

Hoca bunu "problemi logaritma ile başka bir bölgeye taşımak" diye anlattı. $A$'nın limiti yerine $\ln A$'nın limiti hesaplanır.

**Adım 2.** $x \to 0$ iken $\ln(1 + ax) \to \ln 1 = 0$ ve $x \to 0$. Belirsizlik $\dfrac{0}{0}$'dır. L'Hôpital:

$$\lim_{x\to 0}\ln A = \lim_{x\to 0}\frac{\dfrac{a}{1 + ax}}{1} = a.$$

**Adım 3.** Bu, $\ln A$'nın limitidir. Geri dönmek için üstel fonksiyon uygulanır. Üstel fonksiyon logaritmanın tersidir:

$$\lim_{x\to 0} A = \lim_{x\to 0} e^{\ln A} = e^a.$$

**Sonuç:**

$$\lim_{x\to 0}(1 + ax)^{1/x} = e^a.$$

### 12.2 Denk biçim

Hoca ezberlemeye gerek olmadığını söyleyerek $t = \dfrac{1}{x}$ değişken değiştirmesi yaptı. $x \to 0^+$ iken $t \to +\infty$, $x \to 0^-$ iken $t \to -\infty$ olur. $ax = \dfrac{a}{t}$ olduğundan

$$\lim_{t\to\pm\infty}\left(1 + \frac{a}{t}\right)^t = e^a.$$

Bu da $1^\infty$ belirsizliğidir. Hoca bazen birinin, bazen ötekinin kullanılmasının daha iyi olduğunu söyledi. Hangisinin seçileceği limit probleminde verilen fonksiyonun yapısına bağlıdır. Bu formülün çok önemli olduğunu vurguladı.

### 12.3 Örnek 6: $\displaystyle\lim_{x\to 0}\left(\frac{\sin x}{x}\right)^{1/x}$

$x \to 0$ iken $\dfrac{\sin x}{x} \to 1$ ve $\dfrac{1}{x} \to \pm\infty$. Belirsizlik $1^\infty$'dur.

**Yöntem 1 (genel yöntem):** $A = \left(\dfrac{\sin x}{x}\right)^{1/x}$ deyip iki tarafa doğal logaritma uygulamak. Hoca bunun bu tür durumlarda genel yöntem olduğunu söyledi ve bunu ödev bıraktı. Ama genel yöntemi kullanmak istemediğini, olayı basitleştirmek istediğini belirtti.

**Yöntem 2 (benzetme):** Hoca soruyu $e^a$ limitine benzetti. Önce belirsizliğin türüne bakmak gerekir. Belirsizlik $1^\infty$ olduğu için "şanslısınız": bu soru iyi bilinen $e^a$ limitine benzetilebilir.

- Tabana $1$ ekleyip çıkarılır; hiçbir şey değişmez:

$$\frac{\sin x}{x} = 1 + \left(\frac{\sin x}{x} - 1\right).$$

- $u = \dfrac{\sin x}{x} - 1$ denir. $x \to 0$ iken $u \to 0$. Hoca "burada $u \to 0$, doğru yoldasınız" dedi.
- $e^a$ kalıbında $a$, $u$'nun katsayısıdır; burada $a = 1$'dir. Kalıp için üste $\dfrac{1}{u}$ gerekir. Orijinal soruda ise üste $\dfrac{1}{x}$ vardır. Bu yüzden üs $\dfrac{1}{u}\cdot\dfrac{u}{x}$ diye yazılır; sadeleşince bir şey değişmez:

$$\left(1 + u\right)^{1/x} = \left[(1 + u)^{1/u}\right]^{u/x}.$$

- Köşeli parantez içindeki "paket", $u \to 0$ iken $e^1 = e$'ye gider.
- Üsteki ifade:

$$\frac{u}{x} = \frac{\dfrac{\sin x}{x} - 1}{x} = \frac{\sin x - x}{x^2}.$$

- Bu $\dfrac{0}{0}$ belirsizliğidir. L'Hôpital: $\displaystyle\lim_{x\to 0}\frac{\cos x - 1}{2x} = 0$.
- Cevap: $e^0 = 1$.

### 12.4 Genel kural

**Teorem (benzetme kuralı):** $x \to a$ iken $u(x) \to 0$ ise

$$\lim_{x\to a}\big(1 + a\,u(x)\big)^{1/u(x)} = \lim_{u\to 0}(1 + a\,u)^{1/u} = e^a.$$

Bu, değişken değiştirme ile doğrudan $e^a$ limitine indirgenir.

> **Ek bilgi (derste anlatılmadı):** Hocanın gösteriminde aynı harf $a$ hem limit noktası ($x \to a$) hem de katsayı için kullanılıyor. Bunlar farklı şeylerdir; kuralda $e^a$'daki $a$, $u$'nun katsayısıdır.

### 12.5 Örnek 7: $\displaystyle\lim_{x\to 0}(2 - \cos x)^{1/x^2}$

$x \to 0$ iken $2 - \cos x \to 1$, $\dfrac{1}{x^2} \to \infty$. Belirsizlik $1^\infty$'dur.

- Önce $1 + u$ terimi elde edilir: $2 - \cos x = 1 + (1 - \cos x)$.
- $u = 1 - \cos x$ değişken değiştirmesi yapılır. $x \to 0$ iken $u \to 0$.
- Üste $\dfrac{1}{u}$ gerekir; üs $\dfrac{1}{1 - \cos x}\cdot\dfrac{1 - \cos x}{x^2}$ diye yazılır:

$$\lim_{x\to 0}\left[\big(1 + (1 - \cos x)\big)^{\frac{1}{1 - \cos x}}\right]^{\frac{1 - \cos x}{x^2}}.$$

- $u$'nun katsayısı $1$ olduğu için köşeli parantez $e$'ye gider.
- Üsteki kalan terim: $\dfrac{1 - \cos x}{x^2}$. L'Hôpital: $\dfrac{\sin x}{2x} \to \dfrac{1}{2}$.
- Cevap: $e^{1/2}$.

**Soru:** $\dfrac{1}{x^2}$ orada nereye gitti?

**Cevap:** Hiçbir yere gitmedi. Üst kısma taşındı: üste $\dfrac{1}{x^2}\cdot(1 - \cos x)$ olarak yazıldı.

Hoca bu soru için "burada genel yöntemi kullanmak daha avantajlıydı, ama bir öncekinde genel yöntemi kullanmak avantajlı değildi" dedi ve bir önceki soruyu genel yöntemle yapmaya çalışmayı önerdi.

<!-- BELİRSİZ: 01:36:30'daki cümlede "genel yöntem" mi "benzetme yöntemi" mi kastedildiği net değil; bağlama göre büyük olasılıkla hoca bu soruda benzetmenin avantajlı olduğunu kastetti. -->

### 12.6 Örnek 6'nın genel yöntemle çözümü

Hoca benzetme yönteminin neden daha kısa olduğunu göstermek için Örnek 6'yı genel yöntemle çözmeye başladı.

- $A = \left(\dfrac{\sin x}{x}\right)^{1/x}$, $\ln A = \dfrac{\ln\left(\frac{\sin x}{x}\right)}{x}$.
- $x \to 0$ iken $\ln 1 = 0$: belirsizlik $\dfrac{0}{0}$'dır. L'Hôpital:

$$\lim_{x\to 0}\frac{\left(\dfrac{\sin x}{x}\right)'}{\dfrac{\sin x}{x}}.$$

- $\dfrac{\sin x}{x}$'in türevi bölüm kuralıyla bulunur:

$$\left(\frac{\sin x}{x}\right)' = \frac{x\cos x - \sin x}{x^2}.$$

- Sadeleşince ifade $\dfrac{x\cos x - \sin x}{x\sin x}$ olur. Bu yine $\dfrac{0}{0}$'dır; tekrar L'Hôpital gerekir.

**Soru (öğrencinin düzeltmesi):** Hocam nerede hata yaptınız? Orada $\sin x$ çarpı $1$ olması gerekmiyor mu?

**Cevap:** Hoca hatayı kabul etti. Türev alırken önce $\sin x\cdot x$ yazmıştı; doğrusu $\cos x\cdot x - \sin x\cdot 1$'dir. "Gördünüz mü? Bir sürü hata yapabiliyoruz. Öyle ha deyince kolay olmuyor" dedi.

Hoca bu yolda en az 3-4 kez L'Hôpital uygulamak gerekebileceğini söyledi. Benzetme yöntemiyle ise basit bir düzenleme ve bir kez L'Hôpital yeterlidir. Genel yöntemin tamamlanmış çözümü Örnek Sorular bölümündedir.

> **Hocanın vurgusu:** Bu soru, klasik yöntem (benzetme yöntemi) ile L'Hôpital'ın birlikte kullanıldığı en zor soru tiplerinden biridir. Test sınavında bu tarz sorular gelmez.

## 13. $0^0$ Tipi ve $u^u \to 1$ Kuralı

### 13.1 Örnek 8: $\displaystyle\lim_{x\to 0^+} x^x$

Önce belirsizliğin türü belirlenir. Logaritma alınınca $0\cdot\ln 0^+ = 0\cdot(-\infty)$ çıkar. Belirsizlik $0^0$'dır.

- Şu yazılabilir: $x^x = e^{\ln x^x} = e^{x\ln x}$.
- Üstel fonksiyon sürekli olduğu için limit üsse geçer: $\displaystyle\lim_{x\to 0^+} x^x = e^{\lim_{x\to 0^+} x\ln x}$.
- L'Hôpital için ifade düzenlenir: $x\ln x = \dfrac{\ln x}{1/x}$. Bu $\dfrac{\infty}{\infty}$ formudur.
- L'Hôpital:

$$\lim_{x\to 0^+}\frac{1/x}{-1/x^2} = \lim_{x\to 0^+}(-x) = 0.$$

- Cevap: $e^0 = 1$.

Hoca bunun farklı bir yöntem olmadığını, $A = x^x$ deyip doğal logaritma uygulamakla aynı şey olduğunu söyledi.

### 13.2 Genelleme

**Teorem ($u^u$ kuralı):** $x \to a$ iken $u(x) \to 0^+$ ise

$$\lim_{x\to a} u(x)^{u(x)} = \lim_{u\to 0^+} u^u = 1.$$

### 13.3 Örnek 9: $\displaystyle\lim_{x\to 0^+}\left(1 - \frac{\sin x}{x}\right)^x$ (derste cevapsız kaldı)

Hoca bu soruyu kuralın bir uygulaması olarak kafasından yazdı.

- Belirsizlik $0^0$'dır.
- $u = 1 - \dfrac{\sin x}{x}$ denir. $x \to 0$ iken $u \to 0$; hoca sağdan yaklaştığını belirtti.
- $u^u$ kalıbı için üste $u$ gerekir. Orijinal soruda üste $x$ vardır. Bu yüzden üs $u\cdot\dfrac{x}{u}$ diye yazılır:

$$\lim_{x\to 0^+}\left[u^u\right]^{x/u}.$$

- Köşeli parantez $1$'e gider.
- Üsteki ifade:

$$\frac{x}{u} = \frac{x}{\dfrac{x - \sin x}{x}} = \frac{x^2}{x - \sin x}.$$

- Hoca önce bunun $\dfrac{0}{0}$ olduğunu söyleyip L'Hôpital uyguladı: $\dfrac{2x}{1 - \cos x}$. Bunun $0$'a gittiğini düşünerek cevabı $1^0 = 1$ diye verdi.

**Soru:** Hocam, yine $\dfrac{0}{0}$ gelmiyor mu? Bir kez daha L'Hôpital almamız gerekmiyor mu?

**Cevap:** Hoca haklı olduğunu söyledi ve L'Hôpital'ı bir kez daha uyguladı: $\dfrac{2}{\sin x}$. Bu kez tüm limitleri sağdan aldı. Ama yine bir belirsizlik çıktığını söyledi.

**Soru:** Payda $1 - \sin x$ değil mi, $x - \sin x$ değil mi?

**Cevap:** Hoca işlemi tekrar kontrol etti: $1 - \dfrac{\sin x}{x} = \dfrac{x - \sin x}{x}$, tersi çarpılınca $\dfrac{x^2}{x - \sin x}$. İşlem hatası olmadığını söyledi.

Hoca soruyu kafasından yazdığı için soruda bir sıkıntı olabileceğini, haftaya tekrar bakıp neden böyle çıktığını açıklayacağını söyledi. Ders bu soru cevapsız kalarak bitti.

> **Ders sonrası not:** Hoca $\dfrac{2x}{1 - \cos x} \to 0$ diye düşünüp "$1^0$" dedi; doğrusu bu ifadenin $+\infty$'a gitmesidir. İkinci L'Hôpital sonrası $\dfrac{2}{\sin x}$ de $x \to 0^+$ iken $+\infty$'a gider; bu bir belirsizlik değil, kesin bir sonuçtur. Dolayısıyla $\dfrac{x}{u} \to +\infty$ ve ifade $\left[u^u\right]^{x/u}$ biçiminde $1^\infty$ belirsizliğine dönüşür. Benzetme yöntemi bu soruda belirsizliği çözmez. Limitin doğru değeri $1$'dir (sympy ile doğrulandı); çözüm Örnek Sorular bölümündedir.

## Örnek Sorular

Bu derste video karesi kullanılmadı. Aşağıdaki sorular derste sözlü olarak bırakılan ya da cevapsız kalan sorulardır.

**Soru 1** (derste sözlü, 00:33:42): $\operatorname{arcsinh} x$'in türevine benzer şekilde $\operatorname{arccosh} x$, $\operatorname{arctanh} x$ ve $\operatorname{arcsech} x$ fonksiyonlarının türevlerini bulun.

> **Çözüm (derste verilmedi):** Her biri $y = f^{-1}(x) \iff x = f(y)$ yazılıp kapalı türev alınarak bulunur (sympy ile doğrulandı).
>
> - $y = \operatorname{arccosh} x$: $1 = \sinh y\, y'$, $\sinh y = \sqrt{\cosh^2 y - 1} = \sqrt{x^2 - 1}$ ($y \ge 0$). Sonuç: $\dfrac{1}{\sqrt{x^2 - 1}}$, $x > 1$.
> - $y = \operatorname{arctanh} x$: $1 = \operatorname{sech}^2 y\, y' = (1 - \tanh^2 y)\,y'$. Sonuç: $\dfrac{1}{1 - x^2}$, $|x| < 1$.
> - $y = \operatorname{arcsech} x$: $1 = -\operatorname{sech} y\tanh y\, y'$, $\tanh y = \sqrt{1 - x^2}$ ($y \ge 0$). Sonuç: $-\dfrac{1}{x\sqrt{1 - x^2}}$, $0 < x < 1$.

**Soru 2** (derste sözlü, 01:25:50; ödev): $\displaystyle\lim_{x\to 0}\left(\frac{\sin x}{x}\right)^{1/x}$ limitini genel yöntemle (logaritma alarak) hesaplayın.

> **Çözüm (derste verilmedi):** Hoca ilk L'Hôpital adımına kadar gösterdi (Bölüm 12.6). Devamı:
>
> - $\displaystyle\lim_{x\to 0}\ln A = \lim_{x\to 0}\frac{x\cos x - \sin x}{x\sin x}$, $\dfrac{0}{0}$.
> - 2. L'Hôpital: pay türevi $\cos x - x\sin x - \cos x = -x\sin x$, payda türevi $\sin x + x\cos x$. Oran $\dfrac{-x\sin x}{\sin x + x\cos x}$, yine $\dfrac{0}{0}$.
> - 3. L'Hôpital: $\dfrac{-\sin x - x\cos x}{2\cos x - x\sin x} \to \dfrac{0}{2} = 0$.
> - $\ln A \to 0$, dolayısıyla $A \to e^0 = 1$. Benzetme yöntemiyle bulunan sonuçla aynıdır; toplam üç kez L'Hôpital gerekti.

**Soru 3** (derste sözlü, 01:45:22; derste cevapsız kaldı): $\displaystyle\lim_{x\to 0^+}\left(1 - \frac{\sin x}{x}\right)^x$ limitini hesaplayın.

> **Çözüm (derste verilmedi):** Sonuç sympy ile doğrulandı.
>
> - $\ln L = \displaystyle\lim_{x\to 0^+} x\ln\left(1 - \frac{\sin x}{x}\right) = \lim_{x\to 0^+} x\ln\frac{x - \sin x}{x}$.
> - $\ln\dfrac{x - \sin x}{x} = \ln(x - \sin x) - \ln x$. Buradan $\ln L = \displaystyle\lim_{x\to 0^+}\big[x\ln(x - \sin x) - x\ln x\big]$.
> - $x\ln x \to 0$ (Örnek 8). Ayrıca $x\ln(x - \sin x) = \dfrac{\ln(x - \sin x)}{1/x}$, $\dfrac{\infty}{\infty}$. L'Hôpital: $\dfrac{\frac{1 - \cos x}{x - \sin x}}{-1/x^2} = -\dfrac{x^2(1 - \cos x)}{x - \sin x}$. Pay ve payda $x^3$ mertebesinde küçüldüğü için (pay $\approx x^4/2$, payda $\approx x^3/6$) bu ifade $0$'a gider.
> - $\ln L = 0 - 0 = 0$, yani $L = e^0 = 1$.

## Dersin Toparlaması

Ders iki ana konudan oluştu. İlk bölümde hiperbolik fonksiyonlar birim hiperbol $x^2 - y^2 = 1$'in parametrik denklemi olarak tanımlandı. Tüm özdeşlikler, türevler ve ters fonksiyonlar $\cosh$ ve $\sinh$ tanımından türetildi. Trigonometrik fonksiyonlarla aradaki fark çoğu zaman yalnız bir işarettir. $\operatorname{arcsinh}$'in logaritmik ifadesi $e^y$ cinsinden ikinci derece denklem çözülerek bulundu, türevi kapalı türevle elde edildi.

İkinci bölümde L'Hôpital kuralı işlendi. Kural yalnız $\dfrac{0}{0}$ ve $\dfrac{\infty}{\infty}$ belirsizliklerinde uygulanır; $0\cdot\infty$ ve $\infty - \infty$ önce bu formlara çevrilir. Kural art arda uygulanabilir, ama belirsizliğe katkı yapmayan çarpanları önce ayırmak işlemi kısaltır. Üstel belirsizlikler ($1^\infty$, $0^0$, $\infty^0$) logaritma ile tespit edilir. $1^\infty$ tipi sorular $e^a$ kalıbına, $0^0$ tipi sorular $u^u \to 1$ kalıbına benzetilerek çoğu zaman genel yöntemden daha kısa çözülür. Son örnek derste cevapsız kaldı; hoca bir sonraki derste bu soruya döneceğini söyledi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
