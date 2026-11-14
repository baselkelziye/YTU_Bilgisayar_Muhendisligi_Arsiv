# Ders 5 Genişletilmiş Notu: Türevin Tanımı, Türevlenebilme ve Süreklilik, Türev Kuralları ve Zincir Kuralı

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Türevin Anlamı: Anlık Değişim Oranı
- 2. Kesen Doğrudan Teğet Doğrusuna
- 3. Nokta Üzerine Bir Felsefe ve Sonsuz Küçük Üçgen
- 4. Türevin Tanımı ve Teğet Doğrusunun Denklemi
- 5. Denk Tanım: $h$ Biçimi
- 6. Tanımla Türev Hesabı Örnekleri
- 7. Türevlenebilme ve Süreklilik
- 8. Mutlak Değer Fonksiyonu: Sürekli Ama Türevlenemez
- 9. Dikey Teğet ve Tek Taraflı Türevler
- 10. Parçalı Fonksiyonlarda Türev ve Genel Kural
- 11. Türev Kuralları
- 12. Trigonometrik Fonksiyonların Türevleri
- 13. Yatay Teğetler ve Belirli Eğimli Teğetler
- 14. Teğet ile Asimptotu Karıştırmamak
- 15. Zincir Kuralı ve Ağaç Diyagramı
- 16. Zincir Kuralıyla Trigonometrik Türevler
- Örnek Sorular
- Dersin Toparlaması

## 1. Türevin Anlamı: Anlık Değişim Oranı

Hoca derse türev (derivative) konusuyla başladı. Kabaca söylemek gerekirse türev, bağımlı bir değişkenin bağımsız değişkene göre **anlık değişim oranıdır** (instantaneous rate of change). Hoca bu tanımı bir şekil üzerinde açıkladı. Tek değişkenli bir $y = f(x)$ fonksiyonu ve grafiğin üzerinde koordinatları $(a, f(a))$ olan bir $P$ noktası alınır. Bu noktada grafiğe teğet olan bir doğru (kırmızı ile çizilen) düşünülür. Amaç bu teğet doğrusunun eğimini hesaplamaktır.

## 2. Kesen Doğrudan Teğet Doğrusuna

Teğetin eğimini doğrudan bilmiyoruz. Bu yüzden önce kesen doğru (secant line) kullanılır. Grafiğin üzerinde ikinci bir nokta $Q(x, f(x))$ alınır ve $P$ ile $Q$ birleştirilir (mavi doğru). Bu doğru ile bir dik üçgen oluşur:

- Yatay dik kenarın uzunluğu $x - a$ olur.
- Dikey dik kenarın uzunluğu $f(x) - f(a)$ olur.
- Hipotenüs kesen doğrudur ve eğimi dik kenarların oranıdır:

$$m_{PQ} = \frac{f(x) - f(a)}{x - a}$$

Bu oran, $f$ fonksiyonunun $[a, x]$ aralığı üzerindeki **ortalama değişim oranıdır** (average rate of change). Hoca Türkçe açıklamasında şöyle dedi: Bağımsız değişken $a$ anından $x$ anına değişirken bağımlı değişken $f(a)$'dan $f(x)$'e değişir. Bu değişimin ortalaması bu orandır.

Şimdi $x$ değişkeni $a$'ya yaklaşsın, yani "$a$ gibi olmaya çalışsın". O zaman mavi kesen doğrular kırmızı teğet doğrusuna yaklaşır. Üçgenlerin hipotenüsleri teğet doğrusu gibi davranmaya başlar. Dolayısıyla ortalama değişim oranının $x \to a$ iken limitini aldığımızda, teğet doğrusunun eğimini bulmuş oluruz.

## 3. Nokta Üzerine Bir Felsefe ve Sonsuz Küçük Üçgen

Hoca burada "birazcık felsefe" yaptı. **Noktanın matematiksel bir tanımı yoktur.** Okulda öğretilen "kalemi kâğıda bastırınca ortaya çıkan şekil" kesin bir tanım değildir, sadece bir metafordur.

Hocaya göre bu bir dezavantaj değil, avantajdır. Kesin bir tanım olmadığı için bir noktayı yeterince küçük herhangi bir nesne gibi düşünebiliriz: yeterince küçük bir üçgen, yeterince küçük bir kare, hatta yeterince küçük bir küre ya da bir araba. Hoca bunu "zerreden evrene" sözüyle özetledi: Bir noktayı yeterince küçük bir evren, bir âlem olarak düşünebiliriz.

Bu bakış açısıyla limit durumuna geçtiğimizde, şekildeki üçgenler $P$ noktasına doğru "sıkışır". $P$ noktasına yakınlaştırma (zoom) yaparsak orada yeterince küçük bir üçgen (sufficiently small triangle) görürüz. Bu üçgenin hipotenüsü teğet doğrusudur.

Bu üçgenin dik kenarları için Leibniz gösterimi (Leibniz notation) kullanılır:

- $dy$: $y$ ekseni boyunca yeterince küçük fark (sufficiently small difference).
- $dx$: $x$ ekseni boyunca yeterince küçük fark.

Teğetin eğimi de $\dfrac{dy}{dx}$ olur.

$\Delta y$ ile $dy$ arasındaki farka dikkat etmek gerekir. $\Delta y = f(x) - f(a)$ ve $\Delta x = x - a$, limiti alınmamış farklardır. $x$'leri $a$'ya yaklaştırdığımızda $\Delta x$, $dx$'e; $\Delta y$ de $dy$'ye dönüşür. Hoca bunu şöyle vurguladı:

> **Hocanın vurgusu:** Türev almak, sonsuz küçük bir dünyada çalışmak demektir. "Anlık değişim oranı"ndaki "an" kavramı, sonsuz küçüklükte çalıştığımızı ifade eder.

<!-- BELİRSİZ: 00:11:36 ve 00:14:23 civarında altyazı döngüye girmiş; bu aralıkta tahtada yazılanlar altyazıdan okunamıyor. -->

## 4. Türevin Tanımı ve Teğet Doğrusunun Denklemi

Yukarıdaki düşüncenin sonucu türevin tanımıdır.

**Tanım (Türev):**

- $f$ fonksiyonunun $a$ noktasındaki türevi, limit varsa
$$f'(a) = \lim_{x \to a} \frac{f(x) - f(a)}{x - a}$$
ile tanımlanır.
- Bu sayı, grafiğin $(a, f(a))$ noktasındaki teğet doğrusunun eğimidir.

Teğet doğrusunun denklemi için iki bilgi elimizdedir: Doğrunun geçtiği nokta $(a, f(a))$ ve doğrunun eğimi $f'(a)$. Doğru denkleminden:

$$y - f(a) = f'(a)\,(x - a)$$

> **Hocanın vurgusu:** Bu formülü unutmayın, ama ezberlemenize de gerek yok. Formül, $(a, f(a))$ noktasındaki sonsuz küçük üçgenden gelir: $\dfrac{y - y_0}{x - x_0}$ oranı, teğetin eğimine, yani $\dfrac{dy}{dx}$'e eşittir. Ezber yapmayın, işin felsefesini, mantığını öğrenin.

### Örnek 1: Bir parabolün teğeti

Bu örneğin sözlü anlatımı altyazıda büyük ölçüde döngüye girmiştir. Altyazıda yalnız eğimin $64$ bulunduğu (00:17:50) ve b şıkkında teğet denkleminin istendiği duyuluyor. Fonksiyon ve nokta, kısa nottaki ekran bilgisinden alınmıştır: $f(x) = -16x^2 + 96x$, nokta $(1, 80)$.

<!-- BELİRSİZ: Fonksiyonun kuralı altyazıda geçmiyor; kısa nottaki bilgiye dayanılarak yazıldı. Eğimin 64 olduğu altyazıda duyuluyor ve bu fonksiyonla tutarlı. -->

**a) Eğim.** $f(1) = -16 + 96 = 80$ olduğundan nokta grafiğin üzerindedir.

$$m = \lim_{x \to 1} \frac{-16x^2 + 96x - 80}{x - 1}$$

Pay çarpanlarına ayrılır (ara adım eklendi): $-16x^2 + 96x - 80 = -16(x^2 - 6x + 5) = -16(x - 5)(x - 1)$. Böylece

$$m = \lim_{x \to 1} \frac{-16(x-5)(x-1)}{x-1} = \lim_{x \to 1} -16(x-5) = -16 \cdot (-4) = 64$$

**b) Teğet denklemi.** $y - 80 = 64(x - 1)$, sadeleştirince $y = 64x + 16$.

## 5. Denk Tanım: $h$ Biçimi

Hoca ardından birinci tanımın denk bir biçimini verdi. Tanımda $h = x - a$ değişken değiştirmesi yapılır. $x \to a$ iken $h \to 0$ olur ve $x = a + h$ yazılır:

**Tanım (Türevin denk biçimi):**

- $$f'(a) = \lim_{h \to 0} \frac{f(a + h) - f(a)}{h}$$

Hoca iki tanımdaki değişkenlerin rolüne dikkat çekti. Sol taraftaki tanımda limit değişkeni $x$'tir ve $a$, limit değişkenine göre sabittir. Dönüşümden sonra sağ tarafta limit değişkeni $h$ olur.

Türev için kullanılan denk gösterimler de verildi. Hepsi aynı anlama gelir:

$$f'(a), \qquad \frac{df}{dx}\Big|_{x=a}, \qquad \frac{dy}{dx}\Big|_{x=a}$$

Hoca bir polinom örneğinde (00:22:24) $x \to 1$ biçimindeki eğim limitini $h$ biçimine çevirdi: $\displaystyle\lim_{x \to 1}\frac{f(x)-f(1)}{x-1} = \lim_{h \to 0}\frac{f(1+h)-f(1)}{h}$. Ardından başka bir örnekte, $a = 2$ noktasında, $h$ biçimiyle $\dfrac{f(2+h) - f(2)}{h}$ oranının limitini alarak teğetin eğimini $-\dfrac{1}{9}$ buldu ve teğet denklemini $y - y_0 = m(x - x_0)$ ile yazdı.

<!-- BELİRSİZ: 00:22:24'teki polinomun ve 00:24:05'teki eğimi -1/9 çıkan fonksiyonun kuralları altyazıda geçmiyor. -->

> **Hocanın vurgusu:** Bazen birinci tanımı, bazen ikinci tanımı kullanmak avantajlıdır. Bu tamamen fonksiyonun kuralına, yapısına bağlıdır. İşlem yaptıkça bu yeteneği kazanacaksınız.

Hoca bu basit örneklerde hızlı ilerlediğini, çünkü amacın işin mantığını göstermek olduğunu söyledi. Basit sorularda çok yavaş ilerlerse gerçek sorulara zaman kalmayacağını, işlemlere değil formülün mantığına odaklanılması gerektiğini ekledi.

## 6. Tanımla Türev Hesabı Örnekleri

### Örnek 2: $f(x) = \sqrt{x^2 + 1}$ için $f'(1)$

Bu örneğe geçmeden bir öğrenci soru sordu.

**Soru:** Bu fonksiyonun türevini doğrudan (türev kurallarıyla) alıp hesaplasam, bu formülü kullanmasam olmaz mı?

**Cevap:** Bu örnekte türev değerini öyle de elde edebilirsin. Ama sınavda doğrudan türev alınarak çözülemeyen sorular var. Bu yüzden bu formülü (türevin tanımını) öğrenmek zorunludur.

> **Hocanın vurgusu:** "Hocam, zaten doğrudan türevini alıp yapıyoruz, ne gerek var?" diyenler kaybeder. Öyle sorular var ki doğrudan türevle hesaplanmaz; yalnız türevin tanımı kullanılarak çözülebilir.

**Birinci tanımla çözüm.** $f(1) = \sqrt{2}$ olduğundan

$$f'(1) = \lim_{x \to 1} \frac{\sqrt{x^2 + 1} - \sqrt{2}}{x - 1}$$

Bu, $\dfrac{0}{0}$ belirsizliği olan olağan bir limit problemidir. Eşlenikle çarpma yöntemi (conjugate method) uygulanır. Pay ve payda $\sqrt{x^2+1} + \sqrt{2}$ ile çarpılır:

$$= \lim_{x \to 1} \frac{(x^2 + 1) - 2}{(x - 1)\left(\sqrt{x^2 + 1} + \sqrt{2}\right)} = \lim_{x \to 1} \frac{(x - 1)(x + 1)}{(x - 1)\left(\sqrt{x^2 + 1} + \sqrt{2}\right)}$$

$x - 1$ çarpanı sadeleşir. $x \to 1$ iken pay $2$'ye, payda $2\sqrt{2}$'ye gider:

$$f'(1) = \frac{2}{2\sqrt{2}} = \frac{1}{\sqrt{2}}$$

Bu, grafiğin $(1, f(1))$ noktasındaki teğet doğrusunun eğimidir. Hoca grafiği bilmediğimizi, kabaca bir eğri çizip bu noktadaki teğetin eğiminin $\dfrac{1}{\sqrt{2}}$ olduğunu gösterdi.

**İkinci tanımla kurulum.** $x - 1 = h$ dönüşümüyle

$$f'(1) = \lim_{h \to 0} \frac{\sqrt{(1 + h)^2 + 1} - \sqrt{2}}{h}$$

<!-- BELİRSİZ: 00:32:29'da altyazıda "h plus 1 square plus 4" duyuluyor; ifadenin doğrusu (1+h)^2 + 1'dir, büyük olasılıkla ses tanıma hatası. -->

Hoca burada sınıfa bir soru sordu: Bu iki işlemden hangisini bilgisayar daha kolay, daha hızlı hesaplar? Bir öğrenci önce birinci, sonra ikinci dedi. Hocanın cevabı: Birincisi. Çünkü ikincisinde bilgisayar önce $(h + 1)$'in karesini alacak, sonra $1$ ekleyecek, sonra karekök alacaktır. Birincisinde böyle bir açma işlemi yoktur; doğrudan $x^2 + 1$ vardır ve eşlenik yöntemi hemen uygulanır. İfade $x^3 + 1$ gibi küplü bir şey olsaydı, ikinci biçim daha da karmaşık işlemler gerektirecekti. İkinci biçimde de eşlenik yöntemi uygulanabilir, ama önce açma gerekir.

> **Hocanın vurgusu:** Trigonometrik fonksiyonlarda genellikle $h$ biçimi (ikinci tanım) daha avantajlıdır.

Bu arada bir öğrenci ikinci formülle ilgili bir soru sordu, ancak hoca soruyu anlamadığını söyledi ve iki tanım arasındaki farkı tekrar açıkladı.

### Örnek 3: $f(x) = \sqrt{2x + 5}$ için türev fonksiyonu

Bu kez tek bir noktadaki değer değil, türev fonksiyonu (derivative function) isteniyor. Hoca birinci tanımı kullandı. $a$ keyfi ama sabit bir sayıdır:

$$f'(a) = \lim_{x \to a} \frac{\sqrt{2x + 5} - \sqrt{2a + 5}}{x - a}$$

Eşlenikle çarpılır:

$$= \lim_{x \to a} \frac{(2x + 5) - (2a + 5)}{(x - a)\left(\sqrt{2x + 5} + \sqrt{2a + 5}\right)} = \lim_{x \to a} \frac{2(x - a)}{(x - a)\left(\sqrt{2x + 5} + \sqrt{2a + 5}\right)}$$

$x - a$ sadeleşir ve $x \to a$ iken

$$f'(a) = \frac{2}{2\sqrt{2a + 5}} = \frac{1}{\sqrt{2a + 5}}$$

$a$ keyfi olduğu için sonunda $a$ yerine $x$ yazılır: $f'(x) = \dfrac{1}{\sqrt{2x + 5}}$. Hoca $h$ biçimiyle de aynı cevabın elde edildiğini, ama kendi görüşüne göre bu yöntemin daha kolay olduğunu söyledi.

### Örnek 4: $f(x) = x^3$ için türev fonksiyonu

$a$, $x$'e göre keyfi ama sabittir.

$$f'(a) = \lim_{x \to a} \frac{x^3 - a^3}{x - a}$$

Küp farkı çarpanlarına ayrılır: $x^3 - a^3 = (x - a)(x^2 + ax + a^2)$. Sadeleştirince

$$f'(a) = \lim_{x \to a} \left(x^2 + ax + a^2\right) = 3a^2$$

$a$ yerine $x$ yazılınca $f'(x) = 3x^2$ bulunur.

Hoca ardından $h$ biçimini denedi:

$$f'(x) = \lim_{h \to 0} \frac{(x + h)^3 - x^3}{h}$$

Burada da çarpanlara ayırma uygulanabilir. Ama bilgisayar önce $(x + h)^3$'ü açmak, sonra hesaplamak ister. Çarpanlara ayırsa bile $x + h$ yüzünden daha fazla zaman harcar. Bu yüzden bu örnekte birinci biçim daha hızlıdır.

### Örnek 5: $f(x) = \sqrt{x^3 + x}$ için türev fonksiyonu

Yine eşlenik yöntemi uygulanır. Pay ve payda $\sqrt{x^3 + x} + \sqrt{a^3 + a}$ ile çarpılınca payda şu ifade oluşur:

$$x^3 - a^3 + x - a = (x - a)(x^2 + ax + a^2) + (x - a) = (x - a)(x^2 + ax + a^2 + 1)$$

$x - a$ ortak çarpanı sadeleşir:

$$f'(a) = \lim_{x \to a} \frac{x^2 + ax + a^2 + 1}{\sqrt{x^3 + x} + \sqrt{a^3 + a}} = \frac{3a^2 + 1}{2\sqrt{a^3 + a}}$$

Sonunda $a$ yerine $x$ yazılır:

$$f'(x) = \frac{1 + 3x^2}{2\sqrt{x^3 + x}}$$

Hoca son olarak gösterimi tekrar bağladı: $x \to a$ demek $\Delta x = x - a \to 0$ demektir. Bu durumda $\dfrac{\Delta y}{\Delta x}$ oranı $\dfrac{dy}{dx}$'e dönüşür.

## 7. Türevlenebilme ve Süreklilik

Hoca türev ile süreklilik (continuity) arasındaki ilişkiyi mantık önermeleriyle anlattı. Türevlenebilir (differentiable) demek, o noktada türevin var olması demektir.

**Teorem (Türevlenebilme süreklilik gerektirir):**

- $f$, $a$ noktasında türevlenebilir ise $f$, $a$ noktasında süreklidir.
- Tersi doğru değildir: Bir fonksiyon bir noktada sürekli olduğu hâlde orada türevlenemeyebilir.

Mantık diliyle: $P$ önermesi "$f$, $a$'da türevlenebilirdir", $Q$ önermesi "$f$, $a$'da süreklidir" olsun. Teorem $P \Rightarrow Q$ der. Mantıkta $P \Rightarrow Q$ doğruysa $Q \Rightarrow P$ her zaman doğru değildir.

Hocanın örneği: "Yağmur yağarsa hava bulutludur." Bu doğrudur. Ama tersi, "Hava bulutluysa yağmur yağar" her zaman doğru değildir.

$P \Rightarrow Q$ önermesi ise karşıt tersine (contrapositive) denktir:

$$P \Rightarrow Q \quad \equiv \quad \neg Q \Rightarrow \neg P$$

Yani: **$f$, $a$ noktasında sürekli değilse, $a$ noktasında türevlenebilir değildir.**

Bu tür önermelerde $Q$, $P$ için **gerekli koşuldur** (necessary condition), ama **yeterli koşul** (sufficient condition) değildir.

> **Hocanın vurgusu:** Süreklilik, türevlenebilme için gereklidir ama yeterli değildir. Süreklilik yoksa doğrudan "türev yoktur" diyebilirsiniz. Ama süreklilik var diye "türevlenebilir" diyemezsiniz. Çünkü $P \Rightarrow Q$ ile $Q \Rightarrow P$ her zaman denk değildir; denk olsaydı "ancak ve ancak" bağıntısı olurdu.

### 7.1 Teoremin kanıtı (kısaca)

Hoca kısa bir kanıt gösterdi. $P$ doğru olsun, yani $f$, $a$'da türevlenebilir ve $f'(a)$ limiti var. Sürekliliği göstermek için $\displaystyle\lim_{x \to a} f(x) = f(a)$ olduğunu göstermek gerekir. Bunun için $x \ne a$ iken yeni bir ifade tanımlanır ve $x \to a$ iken $f(x)$'in limiti alınır. Bu yolla süreklilik kolayca gösterilir.

<!-- BELİRSİZ: Kanıtta tanımlanan yardımcı fonksiyonun tam biçimi altyazıda okunmuyor. -->

> **Ek bilgi (derste anlatılmadı):** Bu kanıtta kullanılan standart yol, $x \ne a$ için $f(x) - f(a) = \dfrac{f(x) - f(a)}{x - a}\,(x - a)$ yazmaktır. $x \to a$ iken birinci çarpan $f'(a)$'ya, ikinci çarpan $0$'a gider. Böylece $f(x) - f(a) \to f'(a) \cdot 0 = 0$, yani $\lim_{x \to a} f(x) = f(a)$ olur.

### 7.2 Süreksiz noktada teğet yoktur

Hoca bir şekil üzerinde $a$ noktasında süreksiz olan bir fonksiyon gösterdi. Teğet doğrusu tek (unique) olmalıdır. Ama süreksizlik noktasında $(a, f(a))$'dan geçen sonsuz sayıda doğru vardır ve bunlardan hiçbiri tek teğet olarak seçilemez. Bu yüzden süreksizlik, türevlenemezliği gerektirir.

## 8. Mutlak Değer Fonksiyonu: Sürekli Ama Türevlenemez

Teoremin tersinin doğru olmadığını göstermek için hoca mutlak değer fonksiyonunu ele aldı:

$$f(x) = |x| = \begin{cases} x, & x \ge 0 \\ -x, & x < 0 \end{cases}$$

### Örnek 6: $f(x) = |x|$, $x = 0$'da türev var mı?

> **Hocanın vurgusu:** Parçalı tanımlı (piecewise defined) fonksiyonlarda türevin tanımını kullanmak zorunludur. $x \to 0$ iken $0$'a hem sağdan hem soldan yaklaşmak gerekir.

**Sağdan:** $x > 0$ için $f(x) = x$ kuralı kullanılır. Eşitlik durumu ($x \ge 0$) bu parçada olduğu için $f(0) = 0$'dır:

$$\lim_{x \to 0^+} \frac{x - 0}{x - 0} = 1$$

**Soldan:** $x < 0$ için $f(x) = -x$ kuralı kullanılır:

$$\lim_{x \to 0^-} \frac{-x - 0}{x - 0} = -1$$

Sağdaki eğim $1$, soldaki eğim $-1$ çıktı. Sonuçlar farklı olduğu için $f'(0)$ yoktur. Oysa $f$, $0$ noktasında süreklidir. Bu, "sürekli ama türevlenemez" durumuna bir örnektir.

Grafikte $0$'da bir kırılma noktası (broken point, köşe) vardır. Bu noktadan sonsuz sayıda doğru geçer; tek bir teğet doğrusu çizilemez.

<!-- BELİRSİZ: 00:53:47'de hoca "derivation function is not continuous at the point zero" ve "has no limit at zero" diyor; kastedilen büyük olasılıkla türev tanımındaki fark oranının 0'da limitinin olmamasıdır. -->

Derse bu noktada ara verildi.

## 9. Dikey Teğet ve Tek Taraflı Türevler

Aradan sonra hoca türevin olmadığı başka durumlara baktı. Grafiği $0$'da sürekli olan, ama $|x|$ gibi kırılan bir fonksiyon gösterdi. Ardından grafiğin $0$ noktasında **dikey teğet doğrusu** (vertical tangent line) olan durumları gösterdi. Dikey doğrunun eğimi sonsuzdur. Eğim sonsuz olduğu için bu noktalarda da türev yoktur.

Parçalı fonksiyonlarda genellikle tek taraflı türevler (one-sided derivatives) kullanılır.

**Tanım (Tek taraflı türevler):**

- Sağdan türev: $f'_+(a) = \displaystyle\lim_{x \to a^+} \frac{f(x) - f(a)}{x - a}$
- Soldan türev: $f'_-(a) = \displaystyle\lim_{x \to a^-} \frac{f(x) - f(a)}{x - a}$

**Teorem (Gerek ve yeter koşul):**

- $f'(a)$ vardır $\iff$ $f'_+(a)$ ve $f'_-(a)$ vardır ve birbirine eşittir.

> **Hocanın vurgusu:** Bu önemlidir.

### Örnek 7: $f(x) = |x - 2|$, $x = 2$

Önce fonksiyon parçalı olarak yazılır:

$$f(x) = \begin{cases} x - 2, & x - 2 \ge 0 \\ 2 - x, & x - 2 < 0 \end{cases}$$

Grafik şöyle elde edilir: $y = x - 2$ doğrusu çizilir. Bu doğrunun $x$ ekseninin altında kalan negatif kısmı, mutlak değerin tanımı gereği yukarı katlanır. Böylece $x = 2$'de bir kırılma noktası olan "V" biçimli bir grafik oluşur.

**Soru:** Grafikteki kırılma noktasını nasıl buluruz?

**Cevap:** Grafiğe bakarak bulamazsın. Grafiği mutlak değerin tanımına göre katlayarak çizdik, ama kırılma noktası olduğunu göstermek için cebirsel olarak, türevin tanımını kullanmak gerekir.

Hoca önce kısa bir gözlem yaptı: $x > 2$ için parça doğrudan türevlenir ve türev $1$'dir. $x < 2$ için türev $-1$'dir. $x = 2$ noktası ayrıca incelenmelidir:

$$f'_+(2) = \lim_{x \to 2^+} \frac{(x - 2) - 0}{x - 2} = 1, \qquad f'_-(2) = \lim_{x \to 2^-} \frac{(2 - x) - 0}{x - 2} = -1$$

Burada $f(2) = 0$'dır. Tek taraflı türevler farklı olduğu için $f'(2)$ yoktur.

> **Hocanın vurgusu:** Sınavda bunlar çıkacak mı diye sormayın. Önce yöntemi anlayın. Sınavda bu kadar basit soru gelmeyecek.

## 10. Parçalı Fonksiyonlarda Türev ve Genel Kural

Hoca, tanımı kullanmadan parçalı fonksiyonların türevini incelemek için bir genel kural verdi.

**Genel kural (Parçalı fonksiyonlarda kısa yol):** $f$, $a$ noktasında $f_1$ ve $f_2$ parçalarıyla tanımlı olsun. Şu iki koşul sağlanıyorsa:

- Birinci koşul: Büyük fonksiyon $f$, $a$ noktasında süreklidir.
- İkinci koşul: Her parça her yerde türevlenebilirdir. Örneğin polinomlar her yerde türevlenebilir. $\sin$ ve $\cos$'un da her yerde türevlenebilir olduğunu öğreneceğiz.

O zaman türevin tanımına gerek yoktur. Parçaların türevleri doğrudan alınır ve $a$ noktasındaki değerleri karşılaştırılır. Değerler eşitse $f'(a)$ vardır, farklıysa yoktur.

### Örnek 8: Sürekli ama köşeli parçalı fonksiyon

$$f(x) = \begin{cases} 4 - x^2, & x \le 1 \\ 2x + 1, & x > 1 \end{cases}$$

<!-- BELİRSİZ: Parçaların kuralı altyazıda geçmiyor, kısa nottan alındı. Altyazıdaki değerler (3, 3, f(1) = 3; türevler -2 ve 2) bu kuralla tutarlı. -->

**Birinci koşul (süreklilik):** Sağdan $f \to 2 \cdot 1 + 1 = 3$, soldan $f \to 4 - 1 = 3$ ve $f(1) = 3$. Fonksiyon $1$'de süreklidir.

**İkinci koşul:** İki parça da polinomdur, her yerde türevlenebilir.

İki koşul da sağlandığı için parçaların türevleri doğrudan alınır. Sabitin türevi $0$ olduğundan:

$$(4 - x^2)' = -2x \;\Rightarrow\; -2 \text{ ($x = 1$'de)}, \qquad (2x + 1)' = 2$$

$-2 \ne 2$ olduğu için $f'(1)$ yoktur. Bir öğrencinin "kırılma noktası mı?" sorusuna hoca "evet" dedi.

Hoca türevin olmadığı durumları şöyle özetledi: Bir noktada türev yoksa ya grafikte o noktada kırılma vardır ya da teğet doğrusu dikeydir (eğimi sonsuz).

> **Ders sonrası not:** Hocanın "türev yoksa ya kırılma ya dikey teğet vardır" özeti eksiktir. Hocanın kendisinin 7.2'de gösterdiği gibi süreksizlik noktalarında da türev yoktur. Ayrıca salınım yapan fonksiyonlarda da türev olmayabilir; örneğin $f(x) = x\sin(1/x)$, $f(0) = 0$ fonksiyonu $0$'da süreklidir, ama fark oranı $\sin(1/x)$'in $x \to 0$ iken limiti yoktur.

### Örnek 9: Yanlış çözüm tuzağı (doğru/yanlış)

$$f(x) = \begin{cases} 3x - 6, & x \ge 1 \\ 3x + 5, & x < 1 \end{cases}$$

İfade: "$f$, $x = 1$ noktasında türevlenebilirdir." Bu doğru mu yanlış mı?

<!-- BELİRSİZ: Parçaların hangi aralıkta tanımlı olduğu altyazıda geçmiyor; kısa nottaki biçim kullanıldı. -->

Hoca sınıfa sordu. Bazı öğrenciler "doğru", bazıları "yanlış" dedi. Hoca önce birçok öğrencinin yaptığı yanlış çözümü bilerek gösterdi:

**Yanlış çözüm:** $(3x - 6)' = 3$, $x = 1$'deki değeri $3$. $(3x + 5)' = 3$, değeri $3$. Eşit oldukları için "türevlenebilir" demek.

Hoca bunun büyük bir hata olduğunu söyledi. Genel kuralın uygulanabilmesi için önce $f$'nin $x = 1$'de sürekli olması gerekir. İkinci koşul sağlanır ($3x - 6$ ve $3x + 5$ her yerde türevlenebilir), ama birinci koşul sağlanmaz: $x = 1$'de sağdan $3 - 6 = -3$'e, soldan $3 + 5 = 8$'e gidilir. Fonksiyon $1$'de sürekli değildir.

**Soru:** Hocam, birincinin değeri zaten $-3$ değil mi? $3x - 6$'ya $1$ koyunca $-3$ olmaz mı?

**Cevap:** Hoca o adımda türevini aldığını, yani yanlış çözümde türevin değerine baktığını söyledi.

> **Ders sonrası not:** Öğrencinin gözlemi doğrudur: $3x - 6$'nın $x = 1$'deki değeri $-3$, $3x + 5$'in limiti $8$'dir. Bu tam da fonksiyonun süreksiz olduğunu, dolayısıyla türevlenemez olduğunu gösterir.

Sonuç: Süreklilik gerekli koşul olduğu ve sağlanmadığı için $f'(1)$ yoktur. İfade **yanlıştır**.

> **Hocanın vurgusu:** Bu yöntemi uygulamak için önce büyük fonksiyonun $a$ noktasındaki sürekliliğini, sonra her parçanın her yerde türevlenebilir olduğunu kontrol edin.

### Örnek 10: Bilinmeyen sabit

$$f(x) = \begin{cases} 2x^2, & x \le 1 \\ ax - 2, & x > 1 \end{cases}$$

Hangi $a$ değeri için $f'(1)$ vardır, yani $f$, $x = 1$'de türevlenebilirdir?

> **Hocanın vurgusu:** Hemen yapmayın. Kuralları zihninizden iyice geçirin, bütün koşullar gerçekten sağlanıyor mu bakın. Çok basit görünen sorular düşürücü olabilir.

**Süreklilik:** Süreklilik gerekli koşul olduğundan önce o sağlanmalıdır. Hoca bunu tek taraflı limitlerle yazdı:

$$\lim_{x \to 1^+} (ax - 2) = \lim_{x \to 1^-} 2x^2 = f(1) = 2 \;\Rightarrow\; a - 2 = 2 \;\Rightarrow\; a = 4$$

**Türevlenebilme:** $a = 4$ için $f$, $1$'de süreklidir; birinci koşul sağlanır. İki parça da polinomdur; ikinci koşul sağlanır. Parçaların türevleri:

$$(2x^2)' = 4x \;\Rightarrow\; 4 \text{ ($x = 1$'de)}, \qquad (4x - 2)' = 4$$

Değerler eşit olduğu için $f$, $1$'de türevlenebilirdir. Cevap $a = 4$.

**Soru:** Fonksiyonun sağdan ve soldan limitleri eşitse fonksiyonun sürekli olduğunu söyleyebilir miyiz?

**Cevap:** Hoca "evet" dedi ve sürekliliğin tanımını yazdı: $\displaystyle\lim_{x \to a} f(x) = f(a)$ ise $f$, $a$'da süreklidir. Bunu daha önce konuştuklarını hatırlattı.

> **Ders sonrası not:** Sağdan ve soldan limitlerin eşit olması yalnız $\lim_{x \to a} f(x)$'in var olduğunu gösterir. Süreklilik için ayrıca $f(a)$ tanımlı olmalı ve bu limite eşit olmalıdır. Örneğin $x \ne 0$ için $f(x) = x$, $f(0) = 1$ fonksiyonunda iki taraflı limit $0$'dır, ama fonksiyon $0$'da sürekli değildir.

## 11. Türev Kuralları

### 11.1 Sabit kural

Türev anlık değişim oranıdır. Sabit bir fonksiyonun değeri hiç değişmediği için değişim oranının $0$ olduğu doğal olarak açıktır: $(c)' = 0$.

<!-- BELİRSİZ: 01:38:26 ile 01:38:51 arasında altyazı döngüye girmiş. -->

### 11.2 Kuvvet kuralı

Başlangıçta $n$ tam sayı (sonradan pozitif tam sayı olarak düzeltildi) kabul edilir. Türevin tanımında $x^n - a^n$ ifadesi binom açılımı benzeri çarpanlara ayırma ile yazılır, $x - a$ sadeleşir ve $x \to a$ iken sonuç bulunur:

$$(x^n)' = n\,x^{n-1}$$

Hoca bu çarpanlara ayırma formülünün yalnız bu durumda kullanılabildiğini, $n$'nin herhangi bir gerçel sayı olduğu durumu ileride öğreneceğimizi söyledi.

> **Ek bilgi (derste anlatılmadı):** Kullanılan çarpanlara ayırma, pozitif tam sayı $n$ için $x^n - a^n = (x - a)(x^{n-1} + x^{n-2}a + \dots + a^{n-1})$ özdeşliğidir. Parantez içinde $n$ terim vardır ve $x \to a$ iken her biri $a^{n-1}$'e gider; toplam $n\,a^{n-1}$ olur.

### 11.3 Sabitle çarpım kuralı

$(c\,f)' = c\,f'$. Kanıt türevin tanımıyla yapılır:

$$\lim_{x \to a} \frac{c f(x) - c f(a)}{x - a} = \lim_{x \to a} c\,\frac{f(x) - f(a)}{x - a} = c \lim_{x \to a} \frac{f(x) - f(a)}{x - a} = c\,f'(a)$$

$c$ sabit olduğu için limitin dışına alınır.

### 11.4 Çarpım ve bölüm kuralları

**Çarpım kuralı (product rule):** Birinci çarpanın türevi çarpı ikinci çarpan, artı ikinci çarpanın türevi çarpı birinci çarpan:

$$(f g)' = f' g + f g'$$

Kanıtta paya bir terim eklenip çıkarılır. Hoca bu kanıttan sorumlu olunmadığını söyledi.

**Bölüm kuralı (quotient rule):** Hoca bölüm kuralının çarpım kuralının özel bir durumu olduğunu, çarpım kuralında $g(x)$ yerine $\dfrac{1}{g(x)}$ yazılarak elde edildiğini söyledi:

$$\left(\frac{f}{g}\right)' = \frac{f' g - f g'}{g^2}$$

> **Ders sonrası not:** Hoca kuralı sözlü olarak "pay çarpı paydanın türevi eksi pay çarpı paydanın türevi" diye karışık söyledi. Doğrusu: payın türevi çarpı payda, eksi pay çarpı paydanın türevi, bölü paydanın karesi.

### 11.5 Kuvvet kuralının negatif tam sayılara genişletilmesi

Bölüm kuralı ve pozitif tam sayılar için kuvvet kuralı kullanılarak aynı formülün negatif tam sayılar için de geçerli olduğu gösterilir: $n$ negatif tam sayı iken de $(x^n)' = n\,x^{n-1}$.

> **Ders sonrası not:** Hoca burada "$n \ne -1$ olmalı, yoksa anlamlı olmaz" dedi. Türev için böyle bir istisna yoktur: $(x^{-1})' = -x^{-2}$. Hoca büyük olasılıkla integraldeki $\int x^{-1}\,dx$ istisnasını ya da slayttaki farklı bir koşulu kastetti.

## 12. Trigonometrik Fonksiyonların Türevleri

### 12.1 $\sin x$'in türevi

$\sin$ ve $\cos$'un türevini bulmak için $h$ biçimi kullanılır:

$$(\sin x)' = \lim_{h \to 0} \frac{\sin(x + h) - \sin x}{h}$$

Toplam formülüyle $\sin(x + h) = \sin x \cos h + \cos x \sin h$ yazılır. $\sin x$ ortak çarpan alınır ve oran ikiye ayrılır:

$$= \lim_{h \to 0} \left[ \sin x \cdot \frac{\cos h - 1}{h} + \cos x \cdot \frac{\sin h}{h} \right]$$

Burada limit değişkeni $h$'dir; $x$, $h$'ye göre sabittir. $h \to 0$ iken $\dfrac{\cos h - 1}{h} \to 0$ ve $\dfrac{\sin h}{h} \to 1$ olduğunu biliyoruz. Sonuç:

$$(\sin x)' = \cos x$$

Benzer şekilde $(\cos x)' = -\sin x$ bulunur.

### 12.2 Kurallarla örnekler

Hoca çarpım kuralına örnek olarak $x \cos x$'in türevini gösterdi: $(x \cos x)' = 1 \cdot \cos x + x \cdot (-\sin x)$. Ardından $1 + \sin x$ ve $1 - \sin x$ içeren bir bölümün türevinin de bölüm kuralıyla bulunduğunu söyledi ve bunları basit hesaplar olarak geçti.

<!-- BELİRSİZ: 01:45:56 civarındaki örneklerin tam fonksiyonları (bölüm hâlinde olanlar) altyazıdan okunamıyor. -->

### 12.3 $\tan x$'in türevi

$\tan x = \dfrac{\sin x}{\cos x}$ özdeşliğinden bölüm kuralı uygulanır:

$$(\tan x)' = \frac{\cos x \cdot \cos x - \sin x \cdot (-\sin x)}{\cos^2 x} = \frac{\cos^2 x + \sin^2 x}{\cos^2 x} = \frac{1}{\cos^2 x}$$

Böylece üç denk ifade elde edilir:

$$(\tan x)' = \sec^2 x = 1 + \tan^2 x = \frac{1}{\cos^2 x}$$

Hoca bunu ezberlemeye gerek olmadığını, $\sin$ ve $\cos$'un türevleri ile bölüm kuralından çıkarılabileceğini söyledi.

### 12.4 Bütün trigonometrik türevler ve ezber kolaylığı

$\cot x = \dfrac{\cos x}{\sin x}$ için de bölüm kuralı uygulanır. Hoca türevleri bir tabloda topladı:

| Fonksiyon | Türev |
|---|---|
| $\sin x$ | $\cos x$ |
| $\cos x$ | $-\sin x$ |
| $\tan x$ | $\sec^2 x$ |
| $\cot x$ | $-\csc^2 x$ |
| $\sec x$ | $\sec x \tan x$ |
| $\csc x$ | $-\csc x \cot x$ |

> **Ders sonrası not:** Hoca 01:48:16'da $(\cot x)'$ için "$-\cos^2 x$" der gibi söyledi; hemen ardından doğrusunu, $-\csc^2 x$'i yazdı. Doğru sonuç $(\cot x)' = -\csc^2 x$'tir.

Hoca ezber için bir kolaylık gösterdi: $\sin$–$\cos$, $\tan$–$\cot$ ve $\sec$–$\csc$ çiftleri birbirinin tümleridir (hoca "conjugate" dedi). Bir fonksiyonun türev formülünde her fonksiyon tümleriyle değiştirilir ve başa eksi işareti konursa, tümler fonksiyonun türevi elde edilir. Örneğin $(\sec x)' = \sec x \tan x$ ise $(\csc x)' = -\csc x \cot x$ olur.

> **Ders sonrası not:** Bu çiftler için doğru terim "cofunction"dır (tümler fonksiyon); "conjugate" (eşlenik) başka bir kavramdır.

> **Hocanın vurgusu:** Ezberlemek istiyorsanız böyle ezberleyin. Ama "direkt çıkarırım" diyorsanız, $\sin$ ve $\cos$'un türevlerini ve bölüm kuralını bilmeniz yeterli; çıkarmak 5-10 saniyenizi alır.

Hoca bir örnekte paydasında $x^3$ olan bir bölümün türevini bölüm kuralıyla kurdu ve türevin bir noktadaki değeri sorulursa, örneğin $y'(1)$, $x = 1$'in doğrudan türev ifadesine yazılacağını söyledi.

<!-- BELİRSİZ: 01:50:10'daki bölüm örneğinin fonksiyonu altyazıdan tam okunamıyor (payda x^3, payda cos x ve x içeren terimler var). -->

### Örnek 11: $y = x \cos x \sin x$

İkinci aradan sonra hoca bu örneği (57 numaralı soru) çözdü. Böyle durumlarda gruplama yapmak gerekir: $f = x$ ve $g = \cos x \sin x$ olsun. Çarpım kuralı $y' = f' g + f g'$ verir. $g'$ için de çarpım kuralı uygulanır:

$$g' = (\cos x)' \sin x + \cos x (\sin x)' = -\sin x \cdot \sin x + \cos x \cdot \cos x$$

Sonuç:

$$y' = 1 \cdot \cos x \sin x + x\left(-\sin^2 x + \cos^2 x\right)$$

## 13. Yatay Teğetler ve Belirli Eğimli Teğetler

### Örnek 12: $g(x) = x - \sin x$

**a) Yatay teğetler.** Yatay teğet doğrusunun eğimi $0$'dır. Yani yatay teğetler, türev fonksiyonunun köklerinde bulunur.

$$g'(x) = 1 - \cos x = 0 \;\Rightarrow\; \cos x = 1$$

Bu denklemin sonsuz sayıda çözümü vardır: $x = 0$, $x = 2\pi$, ... Genel olarak $x = 2k\pi$, $k \in \mathbb{Z}$. Yani $x - \sin x$ fonksiyonunun grafiğinde teğetin yatay olduğu sonsuz sayıda nokta vardır.

**b) Eğimin $1$ olduğu yerler.** Türev fonksiyonu eğim fonksiyonudur. $g'(x) = 1$ denklemi çözülür:

$$1 - \cos x = 1 \;\Rightarrow\; \cos x = 0$$

$\cos$ periyodik olduğu için bu denklemin de sonsuz çözümü vardır: $x = \dfrac{\pi}{2}$, $x = -\dfrac{\pi}{2}$, $x = \dfrac{3\pi}{2}$, ... Genel olarak $x = \dfrac{\pi}{2} + k\pi$.

**Soru:** Hocam, böyle olunca cevapları denklem olarak mı yazacağız?

**Cevap:** Cevaplar bunlardır. Sonsuz sayıda cevap olduğu için şıklarda "türev değerini $1$ yapan sonsuz sayıda $x$ değeri vardır" gibi bir ifade olur. Hep sayısal değer yazmaya alıştınız; artık işin mantığını kavradıktan sonra yorumlama kısmı size kalıyor.

## 14. Teğet ile Asimptotu Karıştırmamak

**Soru:** Hocam, teğet doğru dediğimiz asimptot mu oluyor?

**Cevap:** Hayır. Asimptotla karıştırmayın. Asimptot, fonksiyonun sonsuzda düz bir doğru gibi davranmasıdır. Yatay asimptotta fonksiyon yatay bir doğru gibi, dikey asimptotta dikey bir doğru gibi davranır. Burada (yatay teğetlerde) asimptot kavramı yoktur.

Hoca konuyu açmak için Zoom beyaz tahtasında iki durum çizdi.

**Yatay asimptot:** $\displaystyle\lim_{x \to \pm\infty} f(x) = L$ ise $y = L$ yatay asimptottur. Hoca, grafik sonsuzda yatay bir doğruya benzediği ve yatay doğrunun eğimi $0$ olduğu için, yeterince büyük sayılarda türev fonksiyonunun $0$'a yaklaştığını, yani $\displaystyle\lim_{x \to \infty} f'(x) = 0$ olduğunu söyledi.

> **Ders sonrası not:** Bu çıkarım her zaman doğru değildir. Yatay asimptot olması, türevin sonsuzda $0$'a gitmesini garanti etmez. Örneğin $f(x) = \dfrac{\sin(x^2)}{x}$ için $\lim_{x \to \infty} f(x) = 0$'dır, ama $f'(x) = 2\cos(x^2) - \dfrac{\sin(x^2)}{x^2}$ sonsuzda $0$'a gitmez (salınır). Türevin limiti varsa, o limit $0$ olmak zorundadır.

**Dikey asimptot:** $x = a$ dikey asimptot ise $f$, $a$ noktasında sürekli değildir. Süreklilik gerekli koşul olduğu için $x = a$'da türev yoktur.

<!-- BELİRSİZ: 02:12:23 ve 02:14:39 civarında altyazı döngüye girmiş; çizimlerin ayrıntısı okunmuyor. -->

## 15. Zincir Kuralı ve Ağaç Diyagramı

Zincir kuralı (chain rule), iki fonksiyonun bileşkesinin (composition) türevini verir. Hoca kuralı ezberletmek yerine bir ağaç diyagramı (tree diagram) ile kurdu.

$y$, $x$'e bağlı bir fonksiyon olsun. $y$ bağımlı, $x$ bağımsız değişkendir. $y$'nin $x$'e göre anlık değişim oranı $\dfrac{dy}{dx}$'tir: $dy$, $y$ ekseni boyunca; $dx$, $x$ ekseni boyunca yeterince küçük farktır.

Şimdi $y$'nin bir $u$ değişkenine, $u$'nun da $x$'e bağlı olduğunu düşünelim:

```
y
|
u
|
x
```

Bu diyagramda:

- $y$, $u$'ya bağlıdır. $u$, $y$'ye göre bağımsız değişkendir.
- $u$, $x$'e bağlıdır. Yani $u$, $x$'e göre bağımlı değişkendir.
- $x$, hem $u$'ya hem $y$'ye göre bağımsız değişkendir.

> **Hocanın vurgusu:** $u$ burada $y$'ye göre bağımsız değişken, ama $x$'e göre bağımlı değişkendir. Buna dikkat edin.

Diyagramın her dalı bir anlık değişim oranıdır: üst dal $\dfrac{dy}{du}$, alt dal $\dfrac{du}{dx}$. $y$'nin $x$'e göre anlık değişim oranı bu oranların çarpımıdır:

$$\frac{dy}{dx} = \frac{dy}{du} \cdot \frac{du}{dx}$$

**Soru (sohbet kutusundan):** <!-- BELİRSİZ: sorunun tam metni altyazıda yok; büyük olasılıkla du'ların sadeleştirilip sadeleştirilemeyeceği soruldu. -->

**Cevap:** Elbette, $dy$ ve $du$ yeterince küçük farklardır; bölebilirsiniz. Ama biçim olarak $\dfrac{dy}{du} \cdot \dfrac{du}{dx}$ yazın.

### Örnek 13: $y = (5x + 4)^3$

$u = 5x + 4$ denir. O zaman $y = u^3$ olur. Ağaç diyagramına göre $y$, $u$'ya; $u$, $x$'e bağlıdır:

$$\frac{dy}{dx} = \frac{dy}{du} \cdot \frac{du}{dx} = 3u^2 \cdot 5 = 15(5x + 4)^2$$

### 15.1 Genel hâl

Hoca fikri genelleştirdi. $y = f(u(x))$ biçiminde bir fonksiyon verilirse:

$$\frac{dy}{dx} = f'(u) \cdot u'(x) = \frac{df}{du} \cdot \frac{du}{dx}$$

Bu da ağaçtan gelir: $x$'i görmezden gelirsek $f$, $u$'ya bağlıdır; $u$ da $x$'e bağlıdır. Çarpımda $du$'lar sadeleşiyormuş gibi düşünülür ve sonunda $\dfrac{df}{dx}$ kalır.

### Örnek 14: $y = \sin^3(x^2)$

Hoca önce doğrudan yazdı: $3\sin^2(x^2)$ çarpı $\sin(x^2)$'nin türevi, yani $\cos(x^2)$ çarpı $x^2$'nin türevi olan $2x$. Ardından aynı şeyi ağaç diyagramıyla sistemli olarak tekrar yazdı:

- $u = x^2$
- $v = \sin u$
- $y = v^3$

Ağaç: $y \to v \to u \to x$. Buna göre

$$\frac{dy}{dx} = \frac{dy}{dv} \cdot \frac{dv}{du} \cdot \frac{du}{dx} = 3v^2 \cdot \cos u \cdot 2x$$

$dv$'ler ve $du$'lar sadeleşir. Geri yerine koyma ($v = \sin u$, $u = x^2$) yapılınca:

$$\frac{dy}{dx} = 3\sin^2(x^2) \cdot \cos(x^2) \cdot 2x$$

> **Hocanın vurgusu:** $dy$'lerin, $du$'ların, $dv$'lerin sonsuz küçüklükte farklar olduğunu düşünün. $y$ yönündeki yeterince küçük farkı $x$ yönündeki yeterince küçük farka oranlamak, anlık değişim oranını bulmak demektir. Bu oranları düşündüğünüzde aslında zincir kuralını inşa etmiş olursunuz. Ezberlemeden, yaptığınız cebirsel işlemlerin ne anlama geldiğini zihninizde canlandırın. Bunu ancak ağaç diyagramıyla görebilirsiniz.

### Örnek 15: $y = \tan^2(x^3 + \sin^2 x)$

Hoca slayttaki diğer soruları öğrencilere bıraktı ve beyaz tahtaya kendi sorusunu yazdı. Sınavda böyle gelmeyeceğini, bunun bir alıştırma olduğunu söyledi. Kafası karışanlar için farklı renklerle dönüşüm yapmayı önerdi:

- $y = v^2$
- $v = \tan u$
- $u = x^3 + \sin^2 x$

$$\frac{dy}{dx} = \frac{dy}{dv} \cdot \frac{dv}{du} \cdot \frac{du}{dx}$$

Sırayla:

- $\dfrac{dy}{dv} = 2v = 2\tan(x^3 + \sin^2 x)$
- $\dfrac{dv}{du} = \sec^2 u = \sec^2(x^3 + \sin^2 x)$
- $\dfrac{du}{dx} = 3x^2 + (\sin^2 x)' = 3x^2 + 2\sin x \cos x$

Sonuç:

$$y' = 2\tan(x^3 + \sin^2 x) \cdot \sec^2(x^3 + \sin^2 x) \cdot \left(3x^2 + 2\sin x \cos x\right)$$

**$\sin^2 x$'in türevi.** Burada da zincir kuralı kullanılır. Hoca karışmasın diye harfi değiştirdi: $h = u^2$, $u = \sin x$. Ağaç: $h \to u \to x$.

$$\frac{dh}{dx} = \frac{dh}{du} \cdot \frac{du}{dx} = 2u \cdot \cos x = 2\sin x \cos x$$

> **Hocanın vurgusu:** Bu işlemleri artık zihninizden "tak tak" yaparsınız. Ama çok değişkenli fonksiyonlara geçince zincir kuralını kafadan yapamayacaksınız, bu ağaç mantığını kullanacaksınız. Sistemli gitmeyi öğrenin. İleride büyük bir proje yaptığınızda sistemsiz giderseniz projenizi kimse anlayamaz ve proje başarısız olur. Matematikle aslında sistemli gitmeyi öğreniyorsunuz.

### Örnek 16: $y = \sec^3\!\left((x^2 + 2x)^3 \sin x\right)$

Hoca bu soruyu herkesin defterinde çözmesini istedi ve bir süre bekledi. Sınavda böyle gelmeyeceğini, yalnız zincir kuralında pratik yapmak için karmaşık bir problem yazdığını söyledi. Bu kez ağaç diyagramı kullanmadan doğrudan, dıştan içe doğru türev aldı.

$w = (x^2 + 2x)^3 \sin x$ diyelim (hoca harf kullanmadan aynı ifadeyi her adımda tekrar yazdı).

**1. Dış kuvvet:** Kuvvet bir düşürülür: $3\sec^2(w) \cdot (\sec w)'$.

**2. Sekant:** $(\sec w)' = \sec w \tan w \cdot w'$.

**3. İç çarpım:** Çarpım kuralıyla

$$w' = \left[(x^2 + 2x)^3\right]' \sin x + (x^2 + 2x)^3 \cos x$$

ve $(x^2 + 2x)^3$'ün türevi yine zincir kuralıyla $3(x^2 + 2x)^2 (2x + 2)$ olur.

Hepsi birleşince:

$$y' = 3\sec^2(w) \cdot \sec w \tan w \cdot \left[3(x^2 + 2x)^2(2x + 2)\sin x + (x^2 + 2x)^3 \cos x\right], \quad w = (x^2 + 2x)^3 \sin x$$

<!-- BELİRSİZ: Fonksiyonun yazımı altyazıdan "sekant küp", "x kare artı 2x", "ve bu 3'e" ve sin x olarak kuruldu; tahtadaki yazımın tamamı okunmuyor. -->

**Soru:** İkinci satırda $\sec\!\left((x^2 + 2x)^3 \sin x\right)$ yazdınız ve bunun türevini aldınız. Sekantın türevi nasıl tanjant içeriyor?

**Cevap:** Sekantın türevi sekant çarpı tanjanttır. $u$, $x$'e bağlı ise $(\sec u)' = \sec u \tan u \cdot u'$.

## 16. Zincir Kuralıyla Trigonometrik Türevler

Hoca bu soruyu fırsat bilip temel trigonometrik türevlerin zincir kuralıyla genel hâllerini yazdı. $u$, $x$'e bağlı ve $u' = \dfrac{du}{dx}$ olmak üzere:

- $(\sin u)' = \cos u \cdot u'$
- $(\cos u)' = -\sin u \cdot u'$
- $(\tan u)' = \sec^2 u \cdot u'$
- $(\cot u)' = -\csc^2 u \cdot u'$
- $(\sec u)' = \sec u \tan u \cdot u'$
- $(\csc u)' = -\csc u \cot u \cdot u'$

$\csc$ ve $\cot$ için yine tümler fikri kullanılır: $\sec$'in tümleri $\csc$'tir ve başa eksi gelir. $u = x$ özel durumunda temel formüller geri elde edilir.

### Örnek 17: $y = \sec(x^2 + \sin x)$

$u = x^2 + \sin x$ alınır.

$$y' = \sec u \tan u \cdot u' = \sec(x^2 + \sin x)\tan(x^2 + \sin x)\,(2x + \cos x)$$

### Örnek 18: $y = \tan(x^3 + \cos x)$

$u = x^3 + \cos x$ alınır.

$$y' = \sec^2 u \cdot u' = \sec^2(x^3 + \cos x)\,(3x^2 - \sin x)$$

Hoca önce "artı" deyip hemen "eksi" diye düzeltti: $\cos x$'in türevi $-\sin x$'tir. Sınavda bu tarz soruların gelebileceğini söyledi.

## Örnek Sorular

Bu bölümdeki sorular derste sınıfa sözlü olarak sorulan ya da öğrencilerin defterde çözmesi istenen sorulardır. Video karesi kullanılmamıştır.

**Soru 1** (derste sözlü, 00:44:16): $P \Rightarrow Q$ doğruysa $Q \Rightarrow P$ de doğru mudur? "Yağmur yağarsa hava bulutludur" önermesinin tersi doğru mudur?

> **Çözüm (derste verildi):** Hayır. $P \Rightarrow Q$ doğruyken $Q \Rightarrow P$ her zaman doğru değildir. "Hava bulutluysa yağmur yağar" doğru değildir. $P \Rightarrow Q$'ya denk olan önerme $\neg Q \Rightarrow \neg P$'dir.

**Soru 2** (derste sözlü, 00:32:41): $f(x) = \sqrt{x^2 + 1}$ için $f'(1)$'i $x \to 1$ biçimiyle ve $h \to 0$ biçimiyle kurduk. Bilgisayar hangisini daha kolay ve hızlı hesaplar?

> **Çözüm (derste verildi):** Birinci biçim ($x \to 1$). İkinci biçimde önce $(1 + h)^2$ açılmalı, sonra $1$ eklenip karekök alınmalıdır. Birincisinde doğrudan eşlenik yöntemi uygulanır. Sonuç her iki yolla $f'(1) = \dfrac{1}{\sqrt{2}}$'dir.

**Soru 3** (derste sözlü, 01:28:34): $f(x) = 3x - 6$ ($x \ge 1$), $f(x) = 3x + 5$ ($x < 1$) için "$f$, $x = 1$'de türevlenebilirdir" ifadesi doğru mu, yanlış mı?

<!-- BELİRSİZ: Parçaların aralıkları altyazıda geçmiyor; kısa nottaki biçim kullanıldı. -->

> **Çözüm (derste verildi):** Yanlış. Parçaların türevleri ($3$ ve $3$) eşit görünse de $x = 1$'de sağdan $-3$'e, soldan $8$'e gidilir; $f$ sürekli değildir. Süreklilik gerekli koşul olduğu için $f'(1)$ yoktur.

**Soru 4** (derste sözlü, 01:33:12): $f(x) = 2x^2$ ($x \le 1$), $f(x) = ax - 2$ ($x > 1$) fonksiyonu hangi $a$ değeri için $x = 1$'de türevlenebilirdir?

> **Çözüm (derste verildi):** Süreklilik: $a - 2 = 2 \Rightarrow a = 4$. Türevler: $(2x^2)'|_{x=1} = 4$ ve $(4x - 2)' = 4$; eşit. Cevap $a = 4$.

**Soru 5** (derste sözlü, 02:07:15): $g(x) = x - \sin x$ fonksiyonunun hangi $x$ değerlerinde yatay teğeti vardır? Hangi $x$ değerlerinde eğim $1$'dir?

> **Çözüm (derste verildi):** $g'(x) = 1 - \cos x$. Yatay teğet: $\cos x = 1 \Rightarrow x = 2k\pi$. Eğim $1$: $\cos x = 0 \Rightarrow x = \dfrac{\pi}{2} + k\pi$. İki durumda da sonsuz sayıda $x$ değeri vardır.

**Soru 6** (derste sözlü, 02:29:54): $y = \tan^2(x^3 + \sin^2 x)$ fonksiyonunun türevini bulun.

> **Çözüm (derste verildi):** $y' = 2\tan(x^3 + \sin^2 x)\sec^2(x^3 + \sin^2 x)\left(3x^2 + 2\sin x \cos x\right)$.

**Soru 7** (derste sözlü, 02:35:41): $y = \sec^3\!\left((x^2 + 2x)^3 \sin x\right)$ için $\dfrac{dy}{dx}$'i defterinizde bulun.

<!-- BELİRSİZ: Fonksiyonun tahtadaki yazımı altyazıdan tam okunmuyor. -->

> **Çözüm (derste verildi):** $w = (x^2 + 2x)^3 \sin x$ olmak üzere $y' = 3\sec^3 w \tan w \left[3(x^2 + 2x)^2(2x + 2)\sin x + (x^2 + 2x)^3 \cos x\right]$.

## Dersin Toparlaması

Bu derste türev, anlık değişim oranı olarak tanıtıldı. Kesen doğruların eğimi olan ortalama değişim oranının $x \to a$ iken limiti, teğet doğrusunun eğimini, yani $f'(a)$'yı verdi. Hoca bunu "noktayı yeterince küçük bir üçgen olarak düşünme" felsefesiyle bağladı ve $dy$, $dx$'i sonsuz küçük farklar olarak yorumladı. Türevin $x \to a$ ve $h \to 0$ biçimindeki iki denk tanımı karşılaştırıldı; hangisinin daha kolay olduğunun fonksiyonun yapısına bağlı olduğu, trigonometrik fonksiyonlarda genelde $h$ biçiminin avantajlı olduğu görüldü.

Ardından türevlenebilmenin sürekliliği gerektirdiği, ama tersinin doğru olmadığı mantık diliyle gösterildi. $|x|$ ve $|x - 2|$ örnekleriyle tek taraflı türevler ve kırılma noktaları incelendi. Parçalı fonksiyonlar için genel kuralın ancak süreklilik ve parçaların türevlenebilirliği kontrol edildikten sonra uygulanabileceği, aksi hâlde yanlış sonuca varılacağı vurgulandı. Son olarak sabit, kuvvet, sabitle çarpım, çarpım ve bölüm kuralları, trigonometrik türevler ve zincir kuralı ağaç diyagramıyla kuruldu. Hoca bu ağaç mantığının çok değişkenli fonksiyonlarda zincir kuralı için gerekeceğini söyledi ve öğrencilerin kendi örneklerini yazarak bol pratik yapmasını istedi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
