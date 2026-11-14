# Ders 7 Genişletilmiş Notu: Doğrusallaştırma, Terslenebilirlik, Üstel ve Logaritmik Fonksiyonlar ve Ters Fonksiyonun Türevi

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dersin Planı
- 2. Geçen Haftanın Alıştırmaları
- 3. Normal Doğrusu
- 4. Parçalı Fonksiyonda Türev
- 5. Kapalı Formda İkinci Türev
- 6. Doğrusallaştırma
- 7. Doğrusallaştırma Uygulamaları
- 8. Artan ve Azalan Fonksiyonlar
- 9. Terslenebilirlik
- 10. Birebir ve Örten Fonksiyonlar
- 11. Üstel Fonksiyonlar
- 12. Doğal Üstel Fonksiyon ve Doğal Logaritma
- 13. $b$ Tabanlı Logaritma ve Logaritma Kuralları
- 14. Üstel Fonksiyonların Türevi
- 15. Logaritmik Fonksiyonların Türevi
- 16. Ters Fonksiyonun Türevi
- Örnek Sorular

## 1. Dersin Planı

Hoca derse, önceki derslerde de söylediği stratejiyi hatırlatarak başladı: Sınavdan önce bütün konuları bitirmek, ardından genel uygulamalar ve soru çözümü yapmak. Bu yüzden konular planlanandan biraz erken bitirilecek.

Bir öğrencinin sorusuna hoca, sınavda bildiği bir yöntemi kullanabileceğini, ama bazı sorularda o yöntemin iyi çalışmadığını söyledi. Hocaya göre iki yöntemi de bilmek daha iyidir.

<!-- BELİRSİZ: 00:02:23-00:02:57 arasında öğrencinin hangi formül ya da yöntemi sorduğu altyazıdan anlaşılmıyor. -->

Hoca, bir önceki derste zincir kuralı (chain rule) ve kapalı türevin (implicit differentiation) anlatıldığını, ama konunun bitirilmediğini söyledi. Bu yüzden ders, geçen haftanın alıştırmalarıyla başladı.

## 2. Geçen Haftanın Alıştırmaları

Hoca alıştırmaları ekranda paylaştı ve önce öğrencilerin kendilerinin çözmesini istedi. Amacı, geçen haftanın konularından aklınızda ne kaldığını kontrol etmekti.

### 2.1 Örnek 1: Açık Formda Teğet Doğrusu

**Soru:** $y = \sin^2\left(\dfrac{\pi x^3}{6}\right)$ eğrisine $x = 1$ noktasında teğet olan doğrunun denklemini bulun.

Hoca, fonksiyonun açık formda (explicit form) verildiğine dikkat çekti: $y$ doğrudan $x$'e bağlıdır.

**Çözüm.** Zincir kuralı iki kez uygulanır. Önce $u = \sin\left(\dfrac{\pi x^3}{6}\right)$ denir. $y = u^2$ olduğundan dış türev $2u$'dur. Sonra $\sin$'in türevi $\cos$, en içteki $\dfrac{\pi x^3}{6}$'nın türevi de $\dfrac{3\pi x^2}{6}$'dır:

$$\frac{dy}{dx} = 2\sin\left(\frac{\pi x^3}{6}\right)\cos\left(\frac{\pi x^3}{6}\right) \cdot \frac{3\pi x^2}{6}.$$

$x = 1$ yazılınca teğetin eğimi bulunur (ara adım eklendi):

$$m = 2\sin\frac{\pi}{6}\cos\frac{\pi}{6}\cdot\frac{\pi}{2} = 2\cdot\frac{1}{2}\cdot\frac{\sqrt{3}}{2}\cdot\frac{\pi}{2} = \frac{\sqrt{3}\,\pi}{4}.$$

Hoca burada bir noktayı vurguladı: Açık formda $y_0$'ı ayrıca aramak gerekmez. $x_0 = 1$'i fonksiyonda yerine koymak yeterlidir. $y_0 = \sin^2\dfrac{\pi}{6} = \dfrac{1}{4}$ (ara adım eklendi). Teğet doğrusu denklemi $y - y_0 = m(x - x_0)$ olduğundan:

$$y - \frac{1}{4} = \frac{\sqrt{3}\,\pi}{4}(x - 1).$$

Sonuç sympy ile doğrulandı.

## 3. Normal Doğrusu

Teğet doğrusundan hemen sonra hoca normal doğrusunu (normal line) tanıttı.

**Tanım (normal doğrusu):**

- Normal doğrusu, eğrinin $P(x_0, y_0)$ noktasından geçen ve o noktadaki teğete dik (perpendicular) olan doğrudur.
- Teğetin eğimi $m$ ise normalin eğimi $-\dfrac{1}{m}$'dir. İki dik doğrunun eğimlerinin çarpımı $-1$'dir.
- Denklemi: $y - y_0 = -\dfrac{1}{m}(x - x_0)$.

> **Ek bilgi (derste anlatılmadı):** $m = 0$ ise teğet yataydır ve $-\dfrac{1}{m}$ tanımsızdır. Bu durumda normal doğrusu dikeydir ve denklemi $x = x_0$ olur. Tersine teğet dikeyse normal yatay olur: $y = y_0$.

## 4. Parçalı Fonksiyonda Türev

### 4.1 Örnek 2: Kesim Noktasında Türevin Tanımı

**Soru:** Aşağıdaki parçalı (piecewise) fonksiyon veriliyor. a) Türev fonksiyonunu bulun.

$$f(x) = \begin{cases} 2x + x^2\sin\left(\dfrac{1}{x}\right), & x \ne 0 \\ 0, & x = 0 \end{cases}$$

Hoca önce şuna dikkat çekti: Fonksiyon tek bir kuralla değil, parçalı bir kuralla verilmiştir. İkinci parça sabit fonksiyondur ve her yerde türevlenebilir. Ama birinci parça her yerde türevlenebilir değildir. Bu durumda kesim noktasında türevin tanımını kullanmak zorunludur.

> **Hocanın vurgusu:** Parçalardan biri her yerde türevlenebilir değilse, kesim noktasında türevin tanımını kullanmak zorunludur (it is mandatory to use the definition of derivation in such cases).

**$x \ne 0$ için.** Fonksiyonun $\mathbb{R} \setminus \{0\}$ üzerinde türevlenebilir olduğu açıktır. Birinci parçanın doğrudan türevi alınır. Çarpım ve zincir kuralıyla (ara adım eklendi):

$$f'(x) = 2 + 2x\sin\left(\frac{1}{x}\right) + x^2\cos\left(\frac{1}{x}\right)\cdot\left(-\frac{1}{x^2}\right) = 2 + 2x\sin\left(\frac{1}{x}\right) - \cos\left(\frac{1}{x}\right).$$

**$x = 0$ için.** Türevin tanımı kullanılır:

$$f'(0) = \lim_{x\to 0}\frac{f(x) - f(0)}{x - 0}.$$

Hoca burada önemli bir ayrıntıyı belirtti: $x$, $0$'a yaklaşırken hiçbir zaman $0$'a eşit olmaz. Bu yüzden $f(x)$ yerine birinci parça yazılır:

$$f'(0) = \lim_{x\to 0}\frac{2x + x^2\sin(1/x) - 0}{x} = 2 + \lim_{x\to 0} x\sin\left(\frac{1}{x}\right).$$

Son limit için hoca ifadeyi $\dfrac{\sin(1/x)}{1/x}$ biçimine dönüştürdü ve $t = \dfrac{1}{x}$ değişken değişimini yaptı. $x \to 0$ iken $t \to \pm\infty$ olur. $t \to \pm\infty$ iken $\dfrac{\sin t}{t} \to 0$'dır. Sonuç:

$$f'(0) = 2.$$

Böylece türev fonksiyonu: $x \ne 0$ için yukarıdaki kural, $x = 0$ için $f'(0) = 2$. Sonuç sympy ile doğrulandı.

> **Ders sonrası not:** Hoca 00:20:10 civarında "türev fonksiyonunun 2 noktasındaki değerini tanımla hesaplarız" diyor. Bağlamdan kastettiği $0$ noktasıdır; doğrusu $f'(0)$.

> **Ek bilgi (derste anlatılmadı):** $\dfrac{\sin t}{t} \to 0$ sonucu sıkıştırma teoremiyle (squeeze theorem) gösterilir: $-\dfrac{1}{|t|} \le \dfrac{\sin t}{t} \le \dfrac{1}{|t|}$ ve iki sınır da $0$'a gider. Aynı şekilde doğrudan $-|x| \le x\sin(1/x) \le |x|$ eşitsizliği de kullanılabilir. Bu limit, $x \to 0$ iken $\dfrac{\sin x}{x} \to 1$ limitiyle karıştırılmamalıdır.

**Soru:** Neden türev kuralını doğrudan uygulamıyoruz?

**Cevap:** Tanımda $x \ne 0$ koşulu var. Birinci parçanın türevine yalnız sıfırdan farklı $x$ değerleri yazılabilir. $x = 0$ yazmaya kalkarsanız $\cos\dfrac{1}{0}$ gibi bir ifade çıkar. $\dfrac{1}{0}$ tanımsızdır. Yani $f'(0)$'ı birinci parçanın doğrudan türevinden bulamazsınız; tanımı kullanmanız gerekir.

<!-- BELİRSİZ: 00:21:41 civarında altyazı döngüye girmiş. Sorunun b şıkkının (varsa) derste ele alınıp alınmadığı anlaşılmıyor. -->

## 5. Kapalı Formda İkinci Türev

### 5.1 Örnek 3: $x^3 + 2y^3 = 5xy$, $(2,1)$ Noktası

**Soru:** $x^3 + 2y^3 = 5xy$ eğrisi veriliyor. $(2, 1)$ noktasında $\dfrac{d^2y}{dx^2}$ değerini bulun.

Hoca, eğrinin kapalı formda (implicit form) verildiğini ve istenenin birinci değil, **ikinci mertebeden türev** olduğunu özellikle vurguladı. Nokta eğri üzerindedir: $8 + 2 = 10 = 5\cdot 2\cdot 1$ (ara adım eklendi).

**Birinci türev.** Eşitliğin iki tarafının $x$'e göre türevi alınır. $2y^3$'ün türevinde $y$, $x$'e bağlı olduğu için zincir kuralı gerekir: $2y^3$ önce $y$'ye göre türevlenir ($6y^2$), sonra $y'$ ile çarpılır. Sağ tarafta çarpım kuralı kullanılır:

$$3x^2 + 6y^2\,y' = 5y + 5x\,y'.$$

$(2, 1)$ yazılır (ara adım eklendi): $12 + 6m = 5 + 10m \Rightarrow 4m = 7 \Rightarrow m = \dfrac{7}{4}$. Bu, teğetin eğimidir.

**İkinci türev.** Hoca burada şunu vurguladı: Kapalı formun türevinden elde edilen bu denklem çok önemlidir. Bu denklemin iki tarafı bir kez daha $x$'e göre türevlenir. Denklemde $x$, $y$ ve $y'$ değişkenleri vardır ve $y$ ile $y'$ ikisi de $x$'e bağlıdır.

- $3x^2$'nin türevi $6x$'tir.
- $6y^2\,y'$ teriminde çarpım kuralı kullanılır. Birinci çarpanın türevi $12y\,y'$, ikinci çarpanla çarpılınca $12y\,(y')^2$ olur. Artı, birinci çarpan çarpı ikincinin türevi: $6y^2\,y''$.
- $5y$'nin türevi $5y'$'dür.
- $5x\,y'$ teriminde yine çarpım kuralı: $5y' + 5x\,y''$.

Sonuç:

$$6x + 12y\,(y')^2 + 6y^2\,y'' = 5y' + 5y' + 5x\,y''.$$

$x = 2$, $y = 1$, $y' = \dfrac{7}{4}$ yazılır (ara adım eklendi):

$$12 + 12\cdot\frac{49}{16} + 6y'' = 10\cdot\frac{7}{4} + 10y'' \Rightarrow 12 + \frac{147}{4} - \frac{70}{4} = 4y'' \Rightarrow 4y'' = \frac{125}{4} \Rightarrow y'' = \frac{125}{16}.$$

Sonuç sympy ile doğrulandı.

<!-- BELİRSİZ: 00:27:14 ve 00:28:27 civarında altyazı döngüye girmiş ve hoca tahtada yer kalmadığı için yazıyı başka yere taşıyor. Ara adımlar hocanın sözlü anlatımı ve kısa nottan kuruldu. -->

**Soru:** En üstte $y'$'nin karesi nereden geldi?

**Cevap:** $6y^2 \cdot y'$ ifadesinin türevini alıyorsunuz. Çarpım kuralına göre önce birinci terimin türevi alınır. $6y^2$, $y$'ye bağlıdır; $y$ de $x$'e bağlıdır. Bu yüzden $6y^2$'nin $x$'e göre türevi $12y\cdot y'$'dür. Bu, bir tane $y'$ getirir. İkinci terim zaten $y'$'dür. İkisi çarpılınca $(y')^2$ çıkar. Sonra birinci terim $6y^2$, ikinci terimin türevi $y''$ ile çarpılır.

> **Hocanın vurgusu:** Bu $(y')^2$'dir, $y''$ değildir. Dikkat edin, birinci mertebeden türevin karesi ile ikinci mertebeden türev farklı şeylerdir. İsterseniz $y$ yerine $f(x)$ yazın, daha rahat görürsünüz.

Bu örnekten sonra hoca ekrandaki bir sorunun tam çıkmadığını söyleyip o soruyu iptal etti.

## 6. Doğrusallaştırma

### 6.1 Sezgi: Dünya Neden Düz Sanıldı?

Hoca yeni konuya, doğrusallaştırmaya (linearization), bir tarihsel örnekle başladı. Eskiden insanların büyük çoğunluğu Dünya'nın yüzeyini düz sanıyordu. Hocaya göre bu yanlış anlamanın arkasında matematiksel bir gerçek vardır: Bir yüzeye yeterince yaklaşırsanız, yüzey kendisi düz olmasa da düz bir doğru ya da düzlem gibi görünür. Biz Dünya'nın yüzeyine çok yakın yaşadığımız için onu düz algılarız. Bu, aslında doğrusallaştırma kavramının ta kendisidir.

<!-- BELİRSİZ: 00:34:19 civarında hocanın "zoom" ile verdiği görsel açıklama altyazıda döngüye girmiş. -->

### 6.2 Formülün Elde Edilmesi

$y = f(x)$ grafiği ve üzerinde $x = a$ noktası alınsın. Bu noktadaki teğet doğrusunun eğimi:

$$f'(a) = \lim_{x\to a}\frac{f(x) - f(a)}{x - a}.$$

Hoca limit gösterimine dikkat çekti: Bu gösterim, $x$'in $a$'ya sürekli yaklaştığı anlamına gelir. Şimdi $x$'in $a$'ya yeterince yaklaştığını ve bir yerde durduğunu varsayalım. Yani limit süreci kaldırılır. O zaman eşitlik yerine yaklaşık eşitlik ($\approx$) kullanılır:

$$\frac{f(x) - f(a)}{x - a} \approx f'(a).$$

Bu ifade düzenlenince doğrusallaştırma formülü çıkar:

**Tanım (doğrusallaştırma):**

- $x$, $a$'ya yeterince yakınsa $f(x) \approx f(a) + f'(a)(x - a)$.
- Sağ taraftaki $L(x) = f(a) + f'(a)(x - a)$, $f$'nin $a$ noktasındaki doğrusallaştırmasıdır (linearization).
- $L(x)$, $a$'daki teğet doğrusunun denklemidir. $L(x) = mx + n$ biçiminde bir doğrudur.

Hoca bunu şöyle yorumladı: Doğrusal olmayan $f(x)$ grafiği, $x$ $a$'ya yeterince yakınken bir doğru gibi görünür. Dünya örneğindeki durum budur.

### 6.3 Diferansiyel Yaklaşım

Aynı ifadede $f(x) - f(a)$ farkına $\Delta y$ (ya da $\Delta f$), $x - a$ farkına $\Delta x$ denir. Limit olmadığı için:

$$f'(a) \approx \frac{\Delta y}{\Delta x} \quad\Rightarrow\quad \Delta y \approx f'(a)\,\Delta x.$$

Buna diferansiyel yaklaşım ilişkisi (differential approximation relation) denir.

Hoca bunu daha önce görülen diferansiyel ilişkiyle karşılaştırdı: $\dfrac{dy}{dx} = f'(x)$, yani $dy = f'(x)\,dx$. Burada $dy$ ve $dx$ sonsuz küçük farklardır ve limit süreciyle elde edilir. Limit süreci kaldırılınca $dy$, $\Delta y$'ye dönüşür ve eşitlik yaklaşık eşitlik olur.

<!-- BELİRSİZ: 00:38:43 ve 00:39:39 civarında altyazı döngüye girmiş. -->

## 7. Doğrusallaştırma Uygulamaları

### 7.1 Örnek 4: $\sqrt{8{,}9}$'un Yaklaşık Değeri

Hoca, kitaptaki örnekten önce daha basit bir örnek çözdü.

**Soru:** Doğrusallaştırma yöntemiyle $\sqrt{8{,}9}$'u yaklaşık hesaplayın.

**Çözüm.** $f(x) = \sqrt{x}$ alınır. Bu grafik bir doğru değildir. Uygun bir $a$ noktası seçilmelidir. $a = 9$ seçilir, çünkü $9$, $8{,}9$'a yeterince yakındır ve $\sqrt{9} = 3$ hesap makinesiz bulunur.

- $f(a) = \sqrt{9} = 3$.
- $f'(x) = \dfrac{1}{2\sqrt{x}}$, $f'(9) = \dfrac{1}{6}$.
- $L(x) = 3 + \dfrac{1}{6}(x - 9)$. Bu yaklaşım $x$, $9$'a yakınken geçerlidir.
- $x = 8{,}9$ yazılır: $\sqrt{8{,}9} \approx 3 + \dfrac{1}{6}(8{,}9 - 9) = 3 + \dfrac{1}{6}(-0{,}1) = 3 - \dfrac{1}{60} = \dfrac{179}{60} \approx 2{,}9833$.

Hoca formülü yazarken önce $f(a)$ yerine $f'(a)$ yazıp hemen düzeltti; doğru formül yukarıdaki gibidir. sympy ile kontrol: $\sqrt{8{,}9} \approx 2{,}98329$. Yaklaşık değerle fark yaklaşık $0{,}00005$'tir.

**Soru:** $a$'yı neden $9$ aldık?

**Cevap:** $f(x)$'in yapısına bakın. $\sqrt{x}$'in $9$'daki değerini hesap makinesiz bulabiliriz ve $9$, $8{,}9$'a yakındır. Başka bir $a$ seçerseniz, o noktadaki kökü hesaplamak için yeni bir problem çıkar. Bu yüzden $a = 9$ seçmek daha iyidir.

**Soru:** $4$ ile $9$'a eşit uzaklıktaki orta noktayı seçsek olmaz mı?

**Cevap:** Orta noktanın karekökünü rahat hesaplayamazsın. Karekökü rahatça dışarı çıkabilen, hesap makinesi kullanma ihtiyacı doğurmayan bir değer seçmelisin.

### 7.2 Örnek 5: $f(x) = \sqrt{x+3}$, $a = 1$

**Soru:** $f(x) = \sqrt{x + 3}$ fonksiyonunun $a = 1$ noktasındaki doğrusallaştırmasını bulun. Bunu kullanarak $\sqrt{3{,}98}$ ve $\sqrt{4{,}05}$ değerlerini yaklaşık hesaplayın.

**Çözüm.** Hoca bu kez kökü doğrudan $x$'e değil, $x + 3$'e uygulayan bir fonksiyon kullanıldığına dikkat çekti.

- $f(1) = \sqrt{4} = 2$.
- $f'(x) = \dfrac{1}{2\sqrt{x+3}}$, $f'(1) = \dfrac{1}{4}$.
- $L(x) = 2 + \dfrac{1}{4}(x - 1)$.

$\sqrt{3{,}98}$ için $x + 3 = 3{,}98$, yani $x = 0{,}98$ seçilmelidir:

$$\sqrt{3{,}98} \approx 2 + \frac{1}{4}(0{,}98 - 1) = 2 - \frac{0{,}02}{4} = 1{,}995.$$

$\sqrt{4{,}05}$ için $x = 1{,}05$:

$$\sqrt{4{,}05} \approx 2 + \frac{1}{4}(1{,}05 - 1) = 2 + 0{,}0125 = 2{,}0125.$$

<!-- BELİRSİZ: 00:51:13-00:52:16 arası sözlü hesap altyazıda eksik. Altyazıda yalnız $x = 0{,}98$ ve $x = 1{,}05$ seçimleri net; sonuçlar yöntemle yeniden hesaplandı. -->

sympy ile kontrol: $\sqrt{3{,}98} \approx 1{,}99499$, $\sqrt{4{,}05} \approx 2{,}01246$. Yaklaşık değerler gerçeğe çok yakındır.

Hoca ileride bu tür daha karmaşık örnekler çözüleceğini söyledi. Ardından 15 dakikalık ara verildi.

## 8. Artan ve Azalan Fonksiyonlar

### 8.1 Tanım

Hoca aradan sonra artan ve azalan fonksiyonlara (increasing and decreasing functions) geçti. Ekrandaki grafikte pozitif $x$ ekseninde artan bir fonksiyon vardı. $x_1 < x_2$ alınınca $f(x_1)$, $f(x_2)$'nin altında kalıyordu.

**Tanım (artan ve azalan fonksiyon):**

- $f$, $I$ aralığında artandır $\iff$ $I$ içindeki her $x_1, x_2$ için $x_1 < x_2 \Rightarrow f(x_1) < f(x_2)$.
- $f$, $I$ aralığında azalandır $\iff$ $I$ içindeki her $x_1, x_2$ için $x_1 < x_2 \Rightarrow f(x_1) > f(x_2)$.

### 8.2 Türevin İşaretiyle Test

Hoca grafiğin artan mı azalan mı olduğunu türev fonksiyonunun işaretinden anlayabileceğimizi gösterdi. Grafiğin üzerine teğet noktasında merkezli bir çember koyup bu çemberi grafik boyunca gezdirdi. Artan grafikte çizilen bütün teğetlerin eğimi pozitifti.

- $f'(x) > 0$ olan yerde $f$ artandır.
- $f'(x) < 0$ olan yerde $f$ azalandır.

Hocanın benzetmesi: Bu bir "sorumluluk fonksiyonu" gibidir. Sorumluluk fonksiyonunuzun türevi pozitifse sorumluluklarınızı yerine getiriyorsunuz, başarılısınız demektir. Türev negatifse her geçen gün sorumluluklarınızı ihmal ediyorsunuz ve başarısız oluyorsunuz demektir.

> **Ders sonrası not:** Hoca bu testi "$f$, $I$'da artandır $\iff$ $f'(x) > 0$" diye denk tanım olarak verdi. Ters yön her zaman doğru değildir. $f' > 0$ ise $f$ artandır, ama artan bir fonksiyonun türevi bir noktada sıfır olabilir. Örnek: $f(x) = x^3$ her yerde artandır, ama $f'(0) = 0$.

### 8.3 Grafik Örneği

Hoca bir grafik üzerinden şu bilgileri okudu:

- $(-\infty, 0)$ aralığında türev pozitif, grafik yukarı gidiyor: $f$ artan.
- $(0, 4)$ aralığında türev negatif: $f$ azalan.
- $(4, \infty)$ aralığında türev pozitif: $f$ artan.
- $x = 0$'da grafikte bir kırılma noktası (broken point) var. Bu yüzden $f'(0)$ tanımsız.

## 9. Terslenebilirlik

### 9.1 Tanım

**Tanım (terslenebilirlik):**

- $f: A \to B$ terslenebilirdir (invertible) $\iff$ öyle bir $g: B \to A$ fonksiyonu vardır ki $f \circ g = \text{id}$ ve $g \circ f = \text{id}$.
- Burada $\text{id}$, özdeşlik fonksiyonudur (identity function): $\text{id}(x) = x$.
- Bu durumda $g$, $f$'nin tersidir ($g = f^{-1}$). $f$, $g$'nin tersiyse $g$ de $f$'nin tersidir.

Hoca tanımda "vardır" sözü için mantık dilindeki varlık niceleyicisini ($\exists$, existential quantifier) kullandı.

### 9.2 Ters Özellik

Tanımdan iki eşitlik çıkar (hoca bunları tek yıldız ile işaretledi):

$$f\big(f^{-1}(x)\big) = x, \qquad f^{-1}\big(f(x)\big) = x. \qquad (\star)$$

Şimdi $y = f(x)$ açık formu verilsin. Eşitliğin iki tarafına $f^{-1}$ uygulanırsa:

$$f^{-1}(y) = f^{-1}\big(f(x)\big) = x. \qquad (\star\star)$$

Hoca $(\star\star)$'ın $(\star)$'ın, yani terslenebilme özelliğinin, bir sonucu olduğunu söyledi.

> **Hocanın vurgusu:** Bu çok önemli. İleride sıklıkla kullanacağız; dönüp dolaşıp buraya geleceğiz. Terslenebilme formülü birçok uygulamada kullanılıyor.

### 9.3 Sezgi: Girdi ve Çıktı

**Soru:** Bir kere daha anlatabilir misiniz?

**Cevap:** Şöyle düşün: Bir nesnen var. Bu nesneyi $x$'ten $y$'ye $f$ ile taşıdın: $y = f(x)$. $x$ girdi, $y$ çıktıdır. Bu nesneyi tutup tekrar geri alabiliyorsan, yani çıktı verildiğinde girdiyi bulabiliyorsan, işlemi tersine döndürebiliyorsun demektir. Çıktı ($y$) verilmiştir, amaç girdiyi ($x$) bulmaktır. Bunun için $f^{-1}$ uygulanır: $f^{-1}(y)$. $y$ yerine $f(x)$ yazınca $f^{-1}$ ile $f$'nin bileşkesi alınmış olur ve sonuç $x$'tir.

Hoca bunun her zaman mümkün olmadığını vurguladı. Çıktı verildiğinde girdiyi her zaman tek türlü belirleyemezsiniz. Tek türlü belirleyebiliyorsanız $f$ işlemi terslenebilirdir.

Hocanın benzetmesi: Tek yönlü su borularını düşünün. Su gelince kapak açılıyor, ama su geri dönemiyor. Çıkış var, giriş yok. Bu taşıma işlemi terslenebilir değildir. Terslenebilir olması için suyun borunun içinden iki yönde de geçebilmesi gerekir.

Hoca ayrıca bu fikrin makine öğrenmesinde (machine learning) önemli olduğunu söyledi: Çoğu zaman çıktılar verilir ve girdiler sorulur; bazen de girdiler verilir, çıktılar istenir.

## 10. Birebir ve Örten Fonksiyonlar

### 10.1 Birebir Fonksiyon

**Tanım (birebir):**

- $f$ birebirdir (one-to-one) $\iff$ farklı girdiler farklı çıktılara gider: $x_1 \ne x_2 \Rightarrow f(x_1) \ne f(x_2)$.

Hoca bu tanıma denk bir tanımı mantık kurallarıyla türetti. Bu tanımda "$x_1 \ne x_2$" önermesine $p$, "$f(x_1) \ne f(x_2)$" önermesine $q$ denirse tanım $p \Rightarrow q$ biçimindedir. Mantıkta $p \Rightarrow q$, karşıt tersine ($\neg q \Rightarrow \neg p$) denktir. Buradan:

- Denk tanım: $f(x_1) = f(x_2) \Rightarrow x_1 = x_2$.

Hocaya göre bazen ilk tanımı kullanmak avantajlı değildir; ikinci tanım işleri kolaylaştırır.

### 10.2 Yatay Doğru Testi

Hoca, daha önce görülen dikey doğru testini (vertical line test) hatırlattı: O test bir eğrinin bir fonksiyonun grafiği olup olmadığını sınar. Birebirlik için ise yatay doğru testi (horizontal line test) kullanılır.

- Bir yatay doğru grafiği birden fazla noktada kesiyorsa, farklı girdiler aynı çıktıya gidiyor demektir. Bu, birebirliğin tanımıyla çelişir. Fonksiyon birebir değildir.

Hoca iki örnek gösterdi. İlkinde $y = x^2$ kuralı yalnız pozitif $x$ ekseni üzerinde tanımlıydı. Orada farklı girdiler farklı çıktılara gidiyordu; fonksiyon birebirdi. İkincisinde grafik bir yatay doğru tarafından birden fazla noktada kesiliyordu: $f(x_1) = f(x_2) = f(x_3)$. Bu fonksiyon birebir değildi.

> **Hocanın vurgusu:** Birebirlik tanım kümesine bağlıdır. Aynı kural bir tanım kümesinde birebir olmayabilir, başka bir tanım kümesinde birebir olabilir.

### 10.3 Örten Fonksiyon ve Terslenebilirlik Teoremi

**Tanım (örten):**

- $f: A \to B$ örtendir (onto) $\iff$ $f(A) = B$. Yani $A$'nın görüntüsü $B$'nin tamamıdır.

**Teorem (terslenebilirlik):**

- $f: A \to B$ terslenebilirdir $\iff$ $f$ hem birebir hem örtendir.
- Hoca iki yönün de geçerli olduğunu vurguladı: Terslenebilirse birebir ve örtendir; birebir ve örtense terslenebilirdir.

Hoca özel bir durumu da belirtti: $f$'yi $D$ tanım kümesinden görüntüsü $f(D)$'ye tanımlarsanız örtenlik kendiliğinden sağlanır; ayrıca yazmanıza gerek yoktur. O zaman $f$'nin $D$ üzerinde birebir olması yeterlidir. Bu durumda $f^{-1}$ vardır ve $y = f(x) \Rightarrow f^{-1}(y) = x$ yazılabilir.

> **Hocanın vurgusu:** Bu teorem çok önemli bir teoremdir.

### 10.4 Tanım Kümesini Kısıtlamak

Hoca $f(x) = x^2$ kuralını iki farklı tanım kümesiyle karşılaştırdı:

- $f_1: \mathbb{R} \to [0, \infty)$, $f_1(x) = x^2$ terslenebilir değildir, çünkü $\mathbb{R}$'de birebir değildir.
- $f_2: [0, \infty) \to [0, \infty)$, $f_2(x) = x^2$ terslenebilirdir. Birebirdir; görüntü kümesine tanımlandığı için örtenliği ayrıca yazmaya gerek yoktur.

Grafiğin $y$ eksenine dik izdüşümü (orthogonal projection) alınınca tanım kümesinin görüntüsü elde edilir.

<!-- BELİRSİZ: $f_1$ ve $f_2$'nin tam tanım ve değer kümeleri altyazıda söylenmiyor; ekranda yazılı. Yukarıdaki kümeler kısa nottaki ve sözlü anlatımdaki "$x^2$, pozitif $x$ ekseni" bilgisinden kuruldu. -->

> **Hocanın vurgusu:** Bir fonksiyon birebir ve örten olmasa bile, kuralını değiştirmeden yalnız tanım bölgesini kısıtlayarak birebir ve örten, yani terslenebilir bir fonksiyon elde edebilirsiniz. Bu çok önemli bir fikirdir; ileride kullanacağız.

> **Ders sonrası not:** Hoca 01:41:32'de "bir fonksiyonun kendisi türevlenebilir olmasa dahi" diyor. Bağlamdan ve hemen ardından gelen İngilizce cümleden ("even if your function is not one-to-one and onto") kastettiği "birebir olmasa dahi"dir.

## 11. Üstel Fonksiyonlar

**Tanım (üstel fonksiyon):**

- $f(x) = b^x$ biçimindeki fonksiyona üstel fonksiyon (exponential function) denir.
- Koşullar: $b > 0$ ve $b \ne 1$.

Hoca $b \ne 1$ koşulunun nedenini açıkladı: $b = 1$ yazılırsa $f(x) = 1^x = 1$ sabit fonksiyonu elde edilir. Sabit fonksiyon birebir değildir ve üstel fonksiyon sayılmaz.

<!-- BELİRSİZ: 01:43:44-01:44:33 arasında $b$'nin pozitifliği ve $0 < b < 1$ durumu anlatılırken altyazı döngüye girmiş. -->

Hoca iki grafik gösterdi:

- $y = 2^x$: $x = 0$'da $y = 1$'dir. $b = 2 > 1$ olduğu için grafik artandır.
- $y = \left(\dfrac{1}{2}\right)^x = 2^{-x}$: Burada $0 < b < 1$'dir. Bu grafik, $y = 2^x$ grafiğinin $y$ eksenine göre simetriği alınarak elde edilir.

## 12. Doğal Üstel Fonksiyon ve Doğal Logaritma

### 12.1 $e$ Sayısı ve $e^x$

Hoca, evrende her yerde görülebilen bazı özel sabitler olduğunu söyledi: altın oran (golden ratio), $\pi$ ve doğal üstel sabit $e$. $e \approx 2{,}718\ldots$ olup ondalık basamakları sonsuza kadar gider.

$e$ tabanlı üstel fonksiyona doğal üstel fonksiyon (natural exponential function) denir. Bazı kaynaklar $\exp(x)$ gösterimini kullanır; genelde $e^x$ yazılır.

- Tanım kümesi: $\mathbb{R}$ (her yerde tanımlı).
- Grafiğin $y$ eksenine dik izdüşümü alınınca görüntü kümesi $(0, \infty)$ bulunur.
- $e^x: \mathbb{R} \to (0, \infty)$ birebir ve örtendir. Bu yüzden tersinden söz edebiliriz.

### 12.2 Doğal Logaritma

**Tanım (doğal logaritma):**

- Doğal üstel fonksiyonun tersine doğal logaritma fonksiyonu (natural logarithmic function) denir: $\ln: (0, \infty) \to \mathbb{R}$.
- Ters özellikten: $e^{\ln x} = x$ ($x > 0$) ve $\ln(e^x) = x$ ($x \in \mathbb{R}$).

Hoca, ters fonksiyonu $\exp^{-1}$ diye yazmak yerine $\ln$ gösterimini tercih ettiğimizi söyledi.

Bu özellikten şu sonuç çıkar: $b = \ln a$ verilmişse, iki tarafa $\ln$'in tersi ($e^{\square}$) uygulanır:

$$b = \ln a \iff e^b = a.$$

> **Hocanın vurgusu:** Formül ezberlemiyorsunuz. Yalnız terslenebilme özelliğinden faydalanarak $b = \ln a$ ise $e^b = a$ olduğunu biliyorsunuz.

### 12.3 Grafikler

$y = e^x$ grafiğinin $y = x$ doğrusuna göre simetriği alınınca tersinin, yani $y = \ln x$'in grafiği elde edilir.

Hoca aynı grafiğin iki denk adı olduğunu gösterdi. $y = \ln x$ eşitliğinin iki tarafına $\ln$'in tersi uygulanırsa $e^y = x$ çıkar. Benzer şekilde $y = e^x$ eşitliğine $\ln$ uygulanırsa $\ln y = x$ çıkar. Yani bir grafik için bazen $y = \ln x$, bazen $e^y = x$ ifadesi kullanılır.

> **Hocanın vurgusu:** Ezber yaparsanız kafanız karışır. Terslenebilme özelliğini göz önünde bulundurursanız grafiklerin nasıl isimlendirildiğini görürsünüz.

### 12.4 Örnek 6: $\ln(x^2 - 1)$'in Tanım Kümesi

Hoca önce şunu vurguladı: Doğal logaritmanın argümanı pozitif olmalıdır; sıfır ya da negatif olamaz.

**Soru:** $f(x) = \ln(x^2 - 1)$ fonksiyonunun tanım kümesi nedir?

**Çözüm.** $\ln$'in anlamlı olması için argüman pozitif olmalıdır:

$$x^2 - 1 > 0 \Rightarrow x^2 > 1 \Rightarrow |x| > 1.$$

İki durum vardır: $x < -1$ ya da $x > 1$. Tanım kümesi:

$$D_f = (-\infty, -1) \cup (1, \infty).$$

Bu kümedeki $x$ değerleri için kural anlamlıdır; dışındakiler için $\ln$ anlam taşımaz. Sonuç sympy ile doğrulandı.

> **Ders sonrası not:** Hoca 01:56:30'da iki durumu "$x > -1$ ya da $x > 1$" diye söylüyor. Doğrusu "$x < -1$ ya da $x > 1$"dir. Hocanın yazdığı son küme $(-\infty, -1) \cup (1, \infty)$ doğrudur.

> **Hocanın vurgusu:** Bunlar basit kısımlar ama önemli kısımlar.

## 13. $b$ Tabanlı Logaritma ve Logaritma Kuralları

### 13.1 Tanım

Genel üstel fonksiyon $f(x) = b^x$'tir ($b > 0$, $b \ne 1$). $b^x: \mathbb{R} \to (0, \infty)$ her yerde tanımlıdır, görüntü kümesi pozitif reel sayılardır. Birebir ve örten olduğundan tersi vardır.

**Tanım ($b$ tabanlı logaritma):**

- $b^x$'in tersine $b$ tabanlı logaritma fonksiyonu (logarithmic function with base $b$) denir: $\log_b: (0, \infty) \to \mathbb{R}$.
- Ters özellik: $b^{\log_b x} = x$ ($x > 0$) ve $\log_b(b^x) = x$.
- Sonuç: $\log_b a = c \iff b^c = a$. İkinci eşitlik, birincinin iki tarafına $\log_b$'nin tersi uygulanarak elde edilir.

### 13.2 Grafikler

$y = b^x$ grafiğinin $y = x$ doğrusuna göre simetriği $y = \log_b x$ grafiğidir. Hoca şu gözleme dikkat çekti: Taban ($b$) arttıkça logaritma grafiği $x$ eksenine doğru eğilir (yatıklaşır).

### 13.3 Logaritma Kuralları ve Sık Yapılan Hatalar

Hoca şu kuralları "çok önemli" diye verdi:

- $\ln(ab) = \ln a + \ln b$.
- $\ln\dfrac{a}{b} = \ln a - \ln b$.

Bunlar ters özellik kullanılarak gösterilebilir. Hoca öğrencilerin sık yaptığı hataları da sıraladı:

- $\ln(a + b) \ne \ln a + \ln b$.
- $\ln\dfrac{a}{b} \ne \dfrac{\ln a}{\ln b}$.
- $\ln(ab) \ne \ln a \cdot \ln b$.

> **Ek bilgi (derste anlatılmadı):** $\ln(ab) = \ln a + \ln b$ kuralı ters özellikle şöyle gösterilir: $a = e^{\ln a}$ ve $b = e^{\ln b}$ yazılır. Üs kuralından $ab = e^{\ln a}e^{\ln b} = e^{\ln a + \ln b}$ olur. İki tarafa $\ln$ uygulanınca $\ln(ab) = \ln a + \ln b$ çıkar. Bölüm kuralı da aynı yolla $\dfrac{a}{b} = e^{\ln a - \ln b}$ eşitliğinden elde edilir.

## 14. Üstel Fonksiyonların Türevi

### 14.1 $e^x$'in Türevi: Sonsuz Seri Fikri

Hoca, bu kısmın gelecek dönemin konusu olduğunu ve müfredat dışı olduğunu, ama bilmenin iyi olacağını söyledi. Doğal üstel fonksiyon "sonsuz dereceli bir polinom" gibi düşünülebilir:

$$e^x \approx 1 + x + \frac{x^2}{2!} + \frac{x^3}{3!} + \cdots + \frac{x^n}{n!} + \cdots$$

Bu ifade terim terim türevlenir. Sabit terimin türevi $0$'dır; $x$'in türevi $1$, $\dfrac{x^2}{2!}$'nin türevi $x$, $\dfrac{x^3}{3!}$'nin türevi $\dfrac{x^2}{2!}$ olur ve bu böyle devam eder (ara adım eklendi). Her terim bir öncekine dönüşür. Sonuçta aynı seri, yani $e^x$ tekrar elde edilir:

$$(e^x)' = e^x.$$

Hoca bunun çok ilginç olduğunu söyledi: Üstel fonksiyonun türevi yine kendisidir. Doğal üstel fonksiyonun bir başka tanımı da buna dayanır.

<!-- BELİRSİZ: 02:04:34-02:06:21 arasında serinin genel terimi ve terim terim türev adımları altyazıda bozuk ("4! x2 n over n!", "let's dengue this"). Yukarıdaki seri ve adımlar hocanın 02:08:15'teki Türkçe açıklamasından ("1 artı x artı x kare bölü 2 faktöriyel ... x üzeri n bölü n faktöriyel") kuruldu. -->

> **Ders sonrası not:** Hoca 02:07:09'da doğal üstel fonksiyonu "$f(a \cdot b) = f(a) + f(b)$ ve $f'(x) = f(x)$" koşullarıyla tanımladı. Birinci koşul logaritmanın özelliğidir. Üstel fonksiyon için doğrusu büyük olasılıkla şudur: her $a, b$ için $f(a + b) = f(a)\cdot f(b)$, $f' = f$ ve $f(0) = 1$. ($f' = f$ ve $f(0) = 1$ koşulları tek başına $e^x$'i belirler.)

**Soru:** Bu seri nereden geliyor?

**Cevap:** Formülden, örüntüden geliyor. $1 + x + \dfrac{x^2}{2!} + \dfrac{x^3}{3!} + \cdots + \dfrac{x^n}{n!}$ örüntüsü gibi düşünebilirsin. Nasıl elde edildiğini önümüzdeki dönem öğreneceksin. Şimdi anlatmıyorum, çünkü konumuzun dışında. Ben yalnız üstel fonksiyonun türevinin kendisine eşit olduğunu göstermek için verdim; başka türlü bunu şu an gösteremezsin.

> **Ek bilgi (derste anlatılmadı):** Bu seriye $e^x$'in Taylor (Maclaurin) serisi denir. Seride yaklaşık eşitlik değil, tam eşitlik vardır: sonsuz toplam her $x$ için $e^x$'e eşittir. Sonlu sayıda terim alınınca yaklaşık değer elde edilir. Taylor serileri büyük olasılıkla Matematik 2 dersinde işlenir.

Kayıtta bu noktada kısa bir ara verildi (02:08 ile 02:21 arası).

### 14.2 Zincir Kuralıyla $e^{u(x)}$

Aradan sonra hoca, $u$ herhangi bir $x$ fonksiyonu olmak üzere $e^{u(x)}$'in türevine geçti. $e^u$, $u$'ya bağlıdır; $u$ da $x$'e bağlıdır. Zincir kuralıyla:

$$\frac{d}{dx}e^{u} = \frac{d}{du}e^{u}\cdot\frac{du}{dx} = e^{u}\cdot u'.$$

**Örnek 7:** $y = e^{\cos^2 x}$ için $u = \cos^2 x$ alınır:

$$y' = e^{\cos^2 x}\cdot 2\cos x\cdot(-\sin x) = -2\sin x\cos x\,e^{\cos^2 x}.$$

Sonuç sympy ile doğrulandı.

### 14.3 $b^x$'in Türevi

Hoca doğal üstel fonksiyonun türevini bildiğimizi, şimdi herhangi bir üstel fonksiyonun türevini bulacağımızı söyledi.

$b > 0$ olduğu için $b = e^h$ olacak şekilde bir $h$ seçilebilir; çünkü $e^x$'in görüntü kümesi $(0, \infty)$'dur. O zaman:

$$y = b^x = \left(e^h\right)^x = e^{hx}.$$

$h$ sabittir. Zincir kuralıyla:

$$y' = e^{hx}\cdot h = b^x\cdot h.$$

$b = e^h$ eşitliğine ters özellik uygulanırsa $h = \ln b$ bulunur. Sonuç:

$$(b^x)' = b^x \ln b.$$

Özel durum $b = e$: $(e^x)' = e^x \ln e = e^x$. Çünkü ters özellikten $\ln e = 1$'dir. Böylece doğal üstel fonksiyonun türevi yeniden elde edilir.

## 15. Logaritmik Fonksiyonların Türevi

### 15.1 $\ln x$'in Türevi

Hoca $\ln x$'in türevini bulmak için iki yöntem olduğunu söyledi.

**Birinci yöntem.** $y = \ln x$ eşitliğinin iki tarafına ters özellik uygulanır: $e^y = x$. İki tarafın $x$'e göre türevi alınır; $y$, $x$'e bağlıdır:

$$e^y\cdot y' = 1 \Rightarrow y' = \frac{1}{e^y} = \frac{1}{x}.$$

Sonuç: $(\ln x)' = \dfrac{1}{x}$.

<!-- BELİRSİZ: 02:28:39-02:29:39 arasında hocanın "ikinci yöntemi" anlatımı altyazıda döngüye girmiş; yöntemin içeriği anlaşılmıyor. -->

### 15.2 Zincir Kuralıyla $\ln u(x)$

$u$ herhangi bir $x$ fonksiyonu olsun. $y = \ln u$ için zincir kuralıyla:

$$y' = \frac{1}{u}\cdot u' = \frac{u'}{u}.$$

Yani türev, argümanın türevinin argümana bölümüdür.

**Örnek 8:** $y = \ln\big(\sec(x^2 + \sin x)\big)$.

Önce argüman $\sec(x^2 + \sin x)$ $u$ gibi düşünülür: $y' = \dfrac{\big(\sec(x^2 + \sin x)\big)'}{\sec(x^2 + \sin x)}$. Payın türevi için bu kez $x^2 + \sin x$ yeni $u$ olarak alınır. $(\sec u)' = \sec u\tan u\cdot u'$ olduğundan:

$$y' = \frac{\sec(x^2 + \sin x)\tan(x^2 + \sin x)\,(2x + \cos x)}{\sec(x^2 + \sin x)} = \tan(x^2 + \sin x)\,(2x + \cos x).$$

$\sec$ çarpanları sadeleşir. Sonuç sympy ile doğrulandı.

> **Hocanın vurgusu:** Ezber yapmayın. Hepsini adım adım gösteriyorum.

### 15.3 Örnek 9: $\log_b x$'in Türevi

Hoca öğrencilerden, ezbere başvurmadan, $b$ tabanlı logaritmanın türevini kendilerinin bulmasını istedi.

**Çözüm.** $y = \log_b x$ eşitliğine ters özellik uygulanır: $b^y = x$. İki tarafın $x$'e göre türevi alınır. Sol tarafta $(b^x)' = b^x\ln b$ kuralı ve zincir kuralı kullanılır:

$$b^y\ln b\cdot y' = 1 \Rightarrow y' = \frac{1}{b^y\ln b} = b^{-y}\cdot\frac{1}{\ln b} = \frac{1}{x\ln b}.$$

Sonuç: $(\log_b x)' = \dfrac{1}{x\ln b}$. sympy ile doğrulandı.

Özel durum $b = e$: $\log_e x = \ln x$ ve $(\ln x)' = \dfrac{1}{x}\cdot\dfrac{1}{\ln e} = \dfrac{1}{x}$. Yani doğal logaritma, $b$ tabanlı logaritmanın özel hâlidir.

**Soru:** $b^y$'nin türevi nasıl alınır?

**Cevap:** Bir önceki paylaşımda $b^x$'in türevini $b^x\ln b$ diye göstermiştik. Burada aynısı geçerli, ama bu kez $y$, $x$'e bağlıdır. Bu yüzden $b^y\ln b$ ile $y$'nin $x$'e göre türevi çarpılır. Sağ taraf $x$'in $x$'e göre türevi, yani $1$'dir.

## 16. Ters Fonksiyonun Türevi

### 16.1 Teorem

Hoca dersin son teoremini "çok önemli" diye tanıttı.

**Teorem (ters fonksiyonun türevi):**

- $f'(a)$ var ve $f'(a) \ne 0$ olsun.
- O zaman $a$'yı içeren bir $I$ aralığı vardır ki $f$, $I$ üzerinde (görüntüsüne) terslenebilirdir.
- Tersi $f^{-1}$, $b = f(a)$ noktasında türevlenebilirdir ve
$$\left(f^{-1}\right)'(b) = \frac{1}{f'(a)}.$$

<!-- BELİRSİZ: 02:38:20-02:39:31 arasında teoremin tam ifadesi (aralığın görüntüsü, "differentiable at") altyazıda parçalı. Yukarıdaki ifade sözlü anlatım ve 02:42:42'deki Türkçe özetten kuruldu. -->

> **Ders sonrası not:** Hoca 02:38:20'de "$f'(a)$'yı içeren bir $I$ aralığı" diyor; doğrusu "$a$'yı içeren bir $I$ aralığı"dır. Ayrıca teoremin tam ifadesinde $f'$'nin $a$ çevresinde sürekli olması da büyük olasılıkla gerekir; ders düzeyindeki örneklerde bu koşul sağlanır.

### 16.2 Kanıt

Hocaya göre kanıt kolaydır. Ters özellikten:

$$f^{-1}\big(f(x)\big) = x.$$

İki tarafın $x$'e göre türevi alınır. Sağ tarafın türevi $1$'dir. Sol tarafta $u = f(x)$ denirse zincir kuralıyla $f^{-1}$'in $u$'ya göre türevi ile $u$'nun $x$'e göre türevi çarpılır:

$$\left(f^{-1}\right)'\big(f(x)\big)\cdot f'(x) = 1 \Rightarrow \left(f^{-1}\right)'\big(f(x)\big) = \frac{1}{f'(x)}.$$

$x = a$ ve $f(a) = b$ yazılınca teoremdeki formül çıkar. Son eşitlik ancak $f'(a) \ne 0$ ise yazılabilir.

> **Hocanın vurgusu:** $f'(a) \ne 0$ koşulu çok önemlidir. Bu koşul olmadan son eşitliği yazamayız.

Hocanın Türkçe özeti: Bir fonksiyonun bir noktadaki türevi sıfırdan farklıysa, o noktayı içeren bir aralık bulabilirsiniz. Fonksiyonu o aralığa kısıtladığınızda birebir ve örten, yani terslenebilir bir fonksiyon elde edersiniz. Ters fonksiyon da türevlenebilirdir. Çok ilginç olarak, tersin $f(a)$'daki türevi, fonksiyonun $a$'daki türevinin çarpımsal tersidir (multiplicative inverse).

### 16.3 Örnek 10: Ters Fonksiyonun Bir Noktadaki Eğimi

**Soru:** $f(x) = \sqrt{x} + x^2 + 1$ fonksiyonu $x \ge 0$ için birebirdir. $y = f^{-1}(x)$ eğrisinin $(3, 1)$ noktasındaki eğimini bulun.

<!-- BELİRSİZ: Fonksiyonun kuralı altyazıda söylenmiyor (02:44:03-02:45:09 arası bozuk). Kural kısa nottan alındı; altyazıdaki "f üstü 1", "f'nin tersi 3" ve "2 over 5" ifadeleriyle tutarlıdır. -->

**Çözüm.** Hoca önce noktaların rolünü açıkladı: $f^{-1}$'e göre $(3, 1)$ noktasında $y_0 = 3$ girdi tarafında, $x_0 = 1$ çıktı tarafındadır. Ters özellikten $f(x_0) = y_0 \iff f^{-1}(y_0) = x_0$.

- $f(1) = \sqrt{1} + 1 + 1 = 3$. Yani $(1, 3)$, $f$'nin grafiğinde, $(3, 1)$ da $f^{-1}$'in grafiğindedir.
- $f'(x) = \dfrac{1}{2\sqrt{x}} + 2x$, $f'(1) = \dfrac{1}{2} + 2 = \dfrac{5}{2}$ (ara adım eklendi).
- Teoremden: $\left(f^{-1}\right)'(3) = \dfrac{1}{f'(1)} = \dfrac{2}{5}$.

Sonuç sympy ile doğrulandı. $f^{-1}$'in açık formülünü bulmaya gerek kalmadan eğim hesaplanmıştır.

> **Hocanın vurgusu:** Bu çok önemli bir teoremdir.

## Örnek Sorular

Bu derste kare ya da video yoktur. Aşağıdaki sorular, hocanın derste öğrencilere çözmeleri için verdiği ya da sözlü sorduğu sorulardır.

**Soru 1** (derste sözlü, 00:08:28) — $y = \sin^2\left(\dfrac{\pi x^3}{6}\right)$ eğrisine $x = 1$ noktasında teğet olan doğrunun denklemini bulun.

> **Çözüm (derste verildi):** $m = \dfrac{\sqrt{3}\,\pi}{4}$, $y_0 = \dfrac{1}{4}$; teğet $y - \dfrac{1}{4} = \dfrac{\sqrt{3}\,\pi}{4}(x - 1)$. Ayrıntı Bölüm 2.1'de.

**Soru 2** (derste sözlü, 00:15:24) — $f(x) = 2x + x^2\sin(1/x)$ ($x \ne 0$), $f(0) = 0$ için türev fonksiyonunu bulun.

> **Çözüm (derste verildi):** $x \ne 0$ için $f'(x) = 2 + 2x\sin(1/x) - \cos(1/x)$; $x = 0$'da tanımla $f'(0) = 2$. Ayrıntı Bölüm 4.1'de.

**Soru 3** (derste sözlü, 00:23:13 ve 00:24:23) — $x^3 + 2y^3 = 5xy$ eğrisi için $(2, 1)$ noktasında ikinci mertebeden türevin değerini bulun.

> **Çözüm (derste verildi):** $y' = \dfrac{7}{4}$, $y'' = \dfrac{125}{16}$. Ayrıntı Bölüm 5.1'de.

**Soru 4** (derste sözlü, 00:46:39) — $\sqrt{8{,}9}$ için doğrusallaştırmada $a$'yı neden $9$ seçtik?

> **Çözüm (derste verildi):** $9$, $8{,}9$'a yakındır ve $\sqrt{9} = 3$ hesap makinesiz bulunur. Sonuç $\sqrt{8{,}9} \approx \dfrac{179}{60}$. Ayrıntı Bölüm 7.1'de.

**Soru 5** (derste sözlü, 00:48:14) — $f(x) = \sqrt{x+3}$ fonksiyonunun $a = 1$'deki doğrusallaştırmasını kullanarak $\sqrt{3{,}98}$ ve $\sqrt{4{,}05}$'i yaklaşık hesaplayın.

> **Çözüm (derste verildi, sayısal sonuçlar yeniden hesaplandı):** $L(x) = 2 + \dfrac{1}{4}(x - 1)$; $\sqrt{3{,}98} \approx L(0{,}98) = 1{,}995$, $\sqrt{4{,}05} \approx L(1{,}05) = 2{,}0125$. sympy ile doğrulandı.

**Soru 6** (derste sözlü, 01:55:53) — $f(x) = \ln(x^2 - 1)$ fonksiyonunun tanım kümesi nedir?

> **Çözüm (derste verildi):** $x^2 - 1 > 0 \Rightarrow |x| > 1$; $D_f = (-\infty, -1) \cup (1, \infty)$.

**Soru 7** (derste sözlü, 02:32:36) — Ezbere başvurmadan $y = \log_b x$ fonksiyonunun türevini bulun.

> **Çözüm (derste verildi):** $b^y = x \Rightarrow b^y\ln b\cdot y' = 1 \Rightarrow y' = \dfrac{1}{x\ln b}$.

**Soru 8** (derste sözlü, 02:44:03) — $f(x) = \sqrt{x} + x^2 + 1$ ($x \ge 0$) için $y = f^{-1}(x)$ eğrisinin $(3, 1)$ noktasındaki eğimini bulun.

> **Çözüm (derste verildi):** $f(1) = 3$, $f'(1) = \dfrac{5}{2}$, $\left(f^{-1}\right)'(3) = \dfrac{2}{5}$. Fonksiyonun kuralı altyazıda okunmuyor; kısa nottan alındı.

<!-- BELİRSİZ: 00:32:55'te hoca ekrandaki bir sorunun "tam çıkmadığını" söyleyip iptal ediyor; sorunun metni altyazıda yok. -->

## Dersin Toparlaması

Ders, geçen haftanın üç alıştırmasıyla başladı: açık formda teğet, parçalı fonksiyonda kesim noktasında türevin tanımla bulunması ve kapalı formda ikinci türev. Ardından normal doğrusu tanıtıldı. Doğrusallaştırma, "Dünya'nın düz sanılması" sezgisiyle açıklandı: Türevin limit tanımından limit süreci kaldırılınca $f(x) \approx f(a) + f'(a)(x - a)$ yaklaşımı ve $\Delta y \approx f'(a)\Delta x$ diferansiyel ilişkisi elde edildi. $a$ noktasının hesap makinesi gerektirmeyecek biçimde seçilmesi gerektiği iki örnekle gösterildi.

Dersin ikinci yarısının merkezinde terslenebilirlik vardı. Bir fonksiyonun terslenebilir olması için birebir ve örten olması gerektiği, tanım kümesi kısıtlanarak terslenebilir fonksiyon elde edilebileceği anlatıldı. Bu fikirle $e^x$'in tersi olarak $\ln x$, $b^x$'in tersi olarak $\log_b x$ tanımlandı; logaritma kuralları ve tanım kümesi ters özellikten çıkarıldı. $(e^x)' = e^x$ sonsuz seri fikriyle, $(b^x)' = b^x\ln b$ ise $b = e^{\ln b}$ yazılarak bulundu. $\ln x$ ve $\log_b x$'in türevleri ters özellik ve kapalı türevle elde edildi. Ders, ters fonksiyonun türevi teoremi $\left(f^{-1}\right)'(f(a)) = \dfrac{1}{f'(a)}$ ve bir uygulamasıyla bitti. Hoca terslenebilirlik fikrine ileride sık sık dönüleceğini söyledi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
