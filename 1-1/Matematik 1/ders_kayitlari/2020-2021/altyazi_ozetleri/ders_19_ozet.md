# Ders 19 Çalışma Özeti

## Genel Konular

- İkinci vize duyurusu ve sınav konuları.
- Belirli integralin özellikleri (properties of definite integration).
- Belirli integral için alt ve üst sınır (min-max eşitsizliği).
- İntegraller için ortalama değer teoremi (mean value theorem for integrals) ve ortalama değer (average value).
- Kalkülüsün temel teoremi (fundamental theorem of calculus), 1. ve 2. kısım.
- Sınırları $x$'e bağlı integralin türevi (temel teoremin genelleştirilmesi).
- Temel teorem ve L'Hôpital kuralıyla limit soruları.
- Temel teorem ile ters fonksiyonun türevi.
- Kısmi integrasyon (integration by parts, partial integration) ve tablo yöntemi (tabular method).

## Hocanın Özellikle Vurguladığı Kısımlar

- **İkinci vize 12. haftada** yapılacak. Kesin gün henüz belli değil. Matematik bölümünün sayfası takip edilmeli.
  - Bu ders 10. hafta. Gelecek hafta (11. hafta) yalnız soru çözülecek: geçmiş yıl soruları ve geçen yılın test soruları.
  - Hoca vizeye kadar olan konuları bitirecek.
- **Sınav konuları:** Rolle teoremi, ortalama değer teoremi, yerel ekstremum, birinci türev testi, konkavlık (concavity), ikinci türev testi, asimptotlar ve grafik çizimi, ters türev (antiderivative), belirsiz integral, sonlu toplamlar ve alan tahmini, Riemann toplamı ve belirli integral.
  - Hoca ikinci türev testini anlatmayı unuttuğunu söylüyor. Gelecek hafta soru üzerinden anlatacak.
  - Hafta hafta konular Bologna sayfasında görülebilir.
- Soruların çoğu son haftalardan (7, 8, 9, 10. haftalar) gelecek. Yaklaşık %15-20'si birinci vize konularıyla harmanlanmış olabilir. Bu yüzden birinci vize konuları da önemli.
- Birinci vizenin cevapları: Hoca sistemden cevaplarla birlikte indiremediğini söylüyor. Ders zamanı soru çözmeye ayrılacak.
- Min-max eşitsizliği önemli. Test sınavında bununla ilgili soru gelebilir.
- İntegraller için ortalama değer teoremi çok önemli. Türevler için ortalama değer teoremiyle karıştırmayın.
- Temel teorem ve L'Hôpital'i birleştiren limit soruları vizede gelebilir.
- Ters fonksiyonun türevi + temel teorem sorusu: birinci ve ikinci vize konularının harmanlanmış hâli. Gelme ihtimali çok yüksek.
- Formülleri ezberlemeyin. İspatın mantığını anlarsanız formülü "5 saniyede" çıkarırsınız.
- Tablo yöntemi ayrı bir yöntem değildir. Kısmi integrasyonun basitleştirilmiş hâlidir.
- İleride diferansiyel denklemler dersinde bu integrallerle çok karşılaşacaksınız.

## Kısa Tekrar Notları

- $\displaystyle\int_b^a f(x)\,dx = -\int_a^b f(x)\,dx$.
- $\displaystyle\int_a^a f(x)\,dx = 0$.
- $[a,b]$'de $f(x) \ge g(x)$ ise $\displaystyle\int_a^b f(x)\,dx \ge \int_a^b g(x)\,dx$.
- $[a,b]$'de $f(x) \ge 0$ ise $\displaystyle\int_a^b f(x)\,dx \ge 0$. Bu integral, grafiğin altındaki bölgenin alanıdır.
- $c \in [a,b]$ ise $\displaystyle\int_a^b f = \int_a^c f + \int_c^b f$.
- **Min-max eşitsizliği:** $\min f \cdot (b-a) \le \displaystyle\int_a^b f(x)\,dx \le \max f \cdot (b-a)$.
- **İntegraller için ortalama değer teoremi:** $f$, $[a,b]$'de sürekliyse öyle bir $c \in [a,b]$ vardır ki $f(c) = \dfrac{1}{b-a}\displaystyle\int_a^b f(x)\,dx$.
  - Sağ taraf $f$'nin $[a,b]$ üzerindeki **ortalama değeridir** (average value). Ortalama değişim oranı değildir.
- **Temel teorem 1. kısım:** $f$, $[a,b]$'de sürekliyse $F(x) = \displaystyle\int_a^x f(t)\,dt$ sürekli, $(a,b)$'de türevlenebilir ve $F'(x) = f(x)$.
- **Temel teorem 2. kısım:** $F$, $f$'nin bir ters türeviyse $\displaystyle\int_a^b f(x)\,dx = F(b) - F(a)$.
- **Genelleştirme:** $\dfrac{d}{dx}\displaystyle\int_{u(x)}^{v(x)} f(t)\,dt = f(v(x))\,v'(x) - f(u(x))\,u'(x)$.
- **Kısmi integrasyon:** $\displaystyle\int u\,dv = uv - \int v\,du$.
- Ters fonksiyonun türevi: $(f^{-1})'(f(x_0)) = \dfrac{1}{f'(x_0)}$, $f'(x_0) \ne 0$.

## Detaylı Açıklamalar

### Belirli integralin özellikleri

- Tanım: $\displaystyle\int_a^b f(x)\,dx = \lim_{n\to\infty}\sum_{k=1}^{n} f(x_k)\,\Delta x_k$. Alt veya üst Riemann toplamından biri yeterlidir. Genelde $\Delta x_k = \Delta x = \dfrac{b-a}{n}$ seçilir.
- **Kural 1:** Sınırlar yer değiştirirse $\Delta x_k$ işaret değiştirir: $\displaystyle\int_b^a f = -\int_a^b f$.
- **Kural 2:** Kural 1'de $b = a$ yazılırsa $\displaystyle\int_a^a f = -\int_a^a f$, yani $2\displaystyle\int_a^a f = 0$. Alt ve üst sınır aynıysa integral sıfırdır.
- **Kural 3:** $f \ge g$ ise integraller de aynı sırayı korur. Tanımdan görülür.
  - Özel durum $g = 0$: $f \ge 0$ ise integral de $\ge 0$ olur ve alanı verir.
- **Kural 4:** Aralık bölünebilir. Önce $a$'dan $c$'ye, sonra $c$'den $b$'ye hesaplayıp toplarsınız.
- 00:12:03 civarında altyazı döngüye giriyor. Bu kısımda anlatılan özellikler altyazıda anlaşılmıyor.

### Min-max eşitsizliği

- $f$, $[a,b]$'de sürekli olduğu için mutlak minimum ve maksimum değerleri vardır.
- Yüksekliği $\min f$, tabanı $b-a$ olan küçük dikdörtgen, bölgenin içinde kalır.
- Yüksekliği $\max f$, tabanı $b-a$ olan büyük dikdörtgen, bölgeyi içine alır.
- Bu yüzden gerçek alan ikisinin arasındadır.

### Örnek 1: $\displaystyle\int_0^5 \sqrt{x^2+5}\,dx$ için alt ve üst sınır

- Bu integrali kolayca hesaplayamıyoruz. Amaç: değeri için alt ve üst sınır bulmak.
- Kökün içi her zaman pozitif. $f$ her yerde sürekli, dolayısıyla $[0,5]$'te de sürekli. Bu ön koşul olduğu için min ve max vardır.
- $f'(x) = \dfrac{x}{\sqrt{x^2+5}} \ge 0$, $[0,5]$'te $f$ artan.
- $\min f = f(0) = \sqrt{5}$, $\max f = f(5) = \sqrt{30}$.
- Sonuç: $5\sqrt{5} \le \displaystyle\int_0^5 \sqrt{x^2+5}\,dx \le 5\sqrt{30}$.
- Hoca artanlığı önce değer karşılaştırarak göstermeye çalışırken karışıyor. Bir öğrencinin önerisiyle türevin işaretine bakıp düzeltiyor.

### İntegraller için ortalama değer teoremi

- Sonlu sayıda terimin ortalaması: terimlerin toplamı bölü terim sayısı.
- Sürekli fonksiyonlarda da ortalama değerden söz edilebilir: $\dfrac{1}{b-a}\displaystyle\int_a^b f(x)\,dx$.
- Türevler için ortalama değer teoreminde sağ tarafta **ortalama değişim oranı** (ortalama hız gibi) vardı. Burada **ortalama değer** var. İkisini karıştırmayın.

### Temel teorem 1. kısmın ispatı

- $F(x) = \displaystyle\int_a^x f(t)\,dt$. Değişkeni karıştırmamak için integrand değişkeni $t$ seçilir.
- Türev tanımı: $F'(x) = \displaystyle\lim_{h\to 0}\frac{F(x+h) - F(x)}{h}$.
- $F(x+h) - F(x)$, $x$ ile $x+h$ arasındaki şeridin alanıdır: $\displaystyle\int_x^{x+h} f(t)\,dt$.
- $\displaystyle\frac{1}{h}\int_x^{x+h} f(t)\,dt$, $f$'nin $[x, x+h]$ üzerindeki ortalama değeridir.
- İntegraller için ortalama değer teoremiyle bu ifade bir $c \in [x, x+h]$ için $f(c)$'ye eşittir.
- $h \to 0$ iken $c \to x$. $f$ sürekli olduğu için $F'(x) = f(x)$.

### Temel teoremin yorumu

- $F(x)$ bir **alan fonksiyonudur**. Bölge, yüksekliği $f(t)$ olan sonsuz sayıda ince çubuğun yan yana dizilmesiyle oluşur.
- Alan fonksiyonunun türevini alırsanız bölgeyi oluşturan ince çubuğun yüksekliğini, yani $f(x)$'i bulursunuz.
- "Bütünden parçaya, parçadan bütüne" gidiyoruz. Türev kavramı "süt ve sütün türevleri" benzetmesindeki gibi bütünün parçasını verir.

### Örnek 2: Temel teorem 1. kısım

- $F(x) = \displaystyle\int_2^x \sin(t^2 + t)\,dt$ ise $F'(x) = \sin(x^2 + x)$.
- Türev değişkeni ile üst sınır aynı olmalı (tutarlılık). Üst sınır doğrudan integranda yerine yazılır.
- $F(m) = \displaystyle\int_0^m \ln(x^2+x)\,dx$ ise $F'(m) = \ln(m^2 + m)$.

### Örnek 3: $\displaystyle\lim_{x\to 0}\frac{1}{x^2}\int_0^x \sin(t^2+t)\,dt$

- Hoca soruyu önce $\dfrac{1}{x}$ ile yazıyor, sonra zorlaştırmak için paydayı $x^2$ yapıyor.
- $x \to 0$ iken üst sınır $0$'a gider. Alt ve üst sınır aynı olduğu için integral $0$'a gider. $\dfrac{0}{0}$ belirsizliği.
- L'Hôpital ve temel teorem 1. kısım: $\displaystyle\lim_{x\to 0}\frac{\sin(x^2+x)}{2x}$. Yine $\dfrac{0}{0}$.
- Tekrar L'Hôpital: $\displaystyle\lim_{x\to 0}\frac{\cos(x^2+x)\,(2x+1)}{2} = \frac{1}{2}$.
- Not: Paydası $x$ olan ilk hâlinde tek L'Hôpital yeterli: $\displaystyle\lim_{x\to 0}\sin(x^2+x) = 0$.

### Örnek 4 (alıştırma): $\displaystyle\lim_{x\to 0}\frac{1}{\sin^2 x}\int_0^x e^{t^2}\,dt$

- $\dfrac{0}{0}$ belirsizliği. L'Hôpital: $\displaystyle\lim_{x\to 0}\frac{e^{x^2}}{2\sin x\cos x}$.
- Pay $1$'e, payda $0^+$ veya $0^-$'a gider. Sonuç $+\infty$ veya $-\infty$. **Limit yok.**
- Dikkat: Payda $\sin^2 x$'tir, $\sin x$ değil.

### Temel teorem 2. kısım

- $f$, $[a,b]$'de sürekli ve $F$, $f$'nin bir ters türevi ($F' = f$) ise $\displaystyle\int_a^b f(x)\,dx = F(b) - F(a)$.
- İspat ödev olarak verildi.
- Belirli integralde integral sabiti $C$ yazmaya gerek yok.
- **Örnek 5:** $\displaystyle\int_0^1 \sqrt{x}\,dx = \left[\frac{2}{3}x^{3/2}\right]_0^1 = \frac{2}{3}$ (tahtadan doğrulandı).
- **Örnek 6:** $\displaystyle\int_0^{\pi}\cos x\,dx = \left[\sin x\right]_0^{\pi} = 0$ (tahtadan doğrulandı).

### Genelleştirme: sınırları $x$'e bağlı integralin türevi

- $F(x) = \displaystyle\int_{u(x)}^{v(x)} f(t)\,dt$, $u$ ve $v$ türevlenebilir.
- $G$, $f$'nin bir ters türevi olsun. 2. kısımdan: $F(x) = G(v(x)) - G(u(x))$.
- Zincir kuralıyla türev: $F'(x) = G'(v)\,v' - G'(u)\,u' = f(v)\,v' - f(u)\,u'$.
- Bu formülü ezberlemeye gerek yok. İspatı anlarsanız saniyeler içinde çıkarırsınız.

### Örnek 7: $\dfrac{d}{dx}\displaystyle\int_{x^2}^{\sin x} e^{t^2}\,dt$

- Üst sınır integranda yazılır, türeviyle çarpılır. Alt sınır için aynısı yapılıp çıkarılır.
- Doğru sonuç: $e^{\sin^2 x}\cos x - e^{x^4}\cdot 2x$.
- Ders sonrası notlara bakın: Hoca alt sınırı yanlış yerine koyuyor.

### Örnek 8: $\displaystyle\lim_{x\to 0}\frac{1}{x^2 - x}\int_{\sin x}^{1-\cos x} t^2\,dt$

- $x \to 0$ iken iki sınır da $0$'a gider. $\dfrac{0}{0}$.
- L'Hôpital ve genelleştirme: $\displaystyle\lim_{x\to 0}\frac{(1-\cos x)^2\sin x - \sin^2 x\cos x}{2x - 1}$.
- Doğrudan $x = 0$ yazılırsa pay $0$, payda $-1$ olur. Belirsizlik yok. **Sonuç: $0$.**
- Hoca önce limiti parçalara ayırmaya çalışıyor, sonra gerek olmadığını söylüyor.
- Bir öğrenci $(1-\cos x)$'in türevinin nerede alındığını soruyor. Cevap: Temel teorem uygulanırken üst sınırın türevi ($\sin x$) ile çarpılıyor.
- Bir öğrenci sağdan ve soldan limitin farklı çıkıp çıkmayacağını soruyor. Burada doğrudan $0$ geldiği için fark çıkmaz.

### Örnek 9: $\dfrac{d}{dx}\displaystyle\int_{x^2}^{\sin x} \tan t\,dt$

- Sonuç: $\tan(\sin x)\cos x - \tan(x^2)\cdot 2x$.

### Örnek 10 (alıştırma): $\displaystyle\lim_{x\to 0}\frac{1}{x^2}\int_{x}^{x^2}\frac{t^2-1}{t^2+1}\,dt$

- Sınırlar $0$'a gider, $\dfrac{0}{0}$. L'Hôpital ve genelleştirme:
  - $\displaystyle\lim_{x\to 0}\frac{\dfrac{x^4-1}{x^4+1}\cdot 2x - \dfrac{x^2-1}{x^2+1}\cdot 1}{2x}$ (tahtadan doğrulandı).
- Doğrudan $x = 0$ yazılır: pay $(-1)\cdot 0 - (-1) = 1$, payda $0^{\pm}$.
- Sonuç $+\infty$ veya $-\infty$. **Limit yok.**
- Bir öğrenci doğrudan sıfır yazmayı öneriyor. Hoca onaylıyor.

### Örnek 11: Temel teorem ve ters fonksiyonun türevi

- $f(x) = \displaystyle\int_1^{e^x}\frac{1}{\sqrt{1+t^2}}\,dt$. $(f^{-1})'(0)$ nedir?
- Formül: $f^{-1}(f(x)) = x$, iki tarafın türevi alınır (zincir kuralı): $(f^{-1})'(f(x_0))\cdot f'(x_0) = 1$.
  - $(f^{-1})'(f(x_0)) = \dfrac{1}{f'(x_0)}$, $f'(x_0) \ne 0$.
- $f(x_0) = 0$ olmalı. Alt sınır $1$; integralin $0$ olması için üst sınır da $1$ olmalı: $e^{x_0} = 1$, yani $x_0 = 0$.
- $f'(x) = \dfrac{e^x}{\sqrt{1+e^{2x}}}$ (alt sınır sabit, türevi $0$).
- $f'(0) = \dfrac{1}{\sqrt{2}}$.
- Sonuç: $(f^{-1})'(0) = \dfrac{1}{f'(0)} = \sqrt{2}$.

### Kısmi integrasyon

- Çarpım kuralı: $d(uv) = v\,du + u\,dv$.
- İki tarafın integrali alınır. $uv$ bir bütündür; $d(uv)$ onun sonsuz küçük parçalarıdır. Parçalar birleştirilince bütün elde edilir: $uv = \displaystyle\int v\,du + \int u\,dv$.
- $\displaystyle\int u\,dv = uv - \int v\,du$.
- Formülü ezberlemenize gerek yok. Çarpım kuralını biliyorsanız hemen çıkarırsınız.
- $u$ seçimi için sıralama: hoca polinom ($P$), trigonometrik ($T$) ve üstel ($E$) fonksiyonlardan söz ediyor. Sıralamada önce gelen $u$ seçilir. Polinom ile üstel çarpımında polinom $u$ olur.

### Örnek 12: $\displaystyle\int x e^x\,dx$

- $u = x$, $du = dx$. $dv = e^x\,dx$, $v = e^x$.
- $\displaystyle\int x e^x\,dx = x e^x - \int e^x\,dx = x e^x - e^x + C = e^x(x-1) + C$.

### Örnek 13: $\displaystyle\int x^2 e^x\,dx$

- $u = x^2$, $du = 2x\,dx$. $dv = e^x\,dx$, $v = e^x$.
- $\displaystyle\int x^2 e^x\,dx = x^2 e^x - 2\int x e^x\,dx$.
- Kalan integral Örnek 12'deki gibi tekrar kısmi integrasyonla çözülür.
- Sonuç: $x^2 e^x - 2e^x(x-1) + C = e^x(x^2 - 2x + 2) + C$.

### Tablo yöntemi

- Bir türev sütunu ($u$'nun ardışık türevleri) ve bir integral sütunu ($dv$'nin ardışık integralleri) açılır.
- $u$'nun türevleri bir adımdan sonra $0$ oluyorsa ve $dv$'nin integralleri kolay alınıyorsa uygulanabilir. Bu "şanslı" durumdur. Her zaman uygulanamaz.
- Çapraz çarpımlar alınır, işaretler $+, -, +, -, \dots$ diye gider. İşaretler kısmi integrasyondaki $uv$'nin $+$ ve $\int v\,du$'nun $-$ katsayısından gelir.
- Örnek 13 tablo ile: $x^2 \to 2x \to 2 \to 0$; $e^x \to e^x \to e^x$. Sonuç: $x^2e^x - 2xe^x + 2e^x + C$.

### Örnek 14: $\displaystyle\int x^5 e^x\,dx$ (tablo yöntemi)

- Türevler: $x^5, 5x^4, 20x^3, 60x^2, 120x, 120, 0$.
- İntegraller: hep $e^x$.
- Sonuç: $e^x\left(x^5 - 5x^4 + 20x^3 - 60x^2 + 120x - 120\right) + C$.
- Doğrudan kısmi integrasyonla çok daha uzun sürerdi.

### Örnek 15 (alıştırma): $\displaystyle\int x^3 e^{3x}\,dx$ (tablo yöntemi)

- Türevler: $x^3, 3x^2, 6x, 6, 0$.
- İntegraller: $\dfrac{1}{3}e^{3x}, \dfrac{1}{9}e^{3x}, \dfrac{1}{27}e^{3x}, \dfrac{1}{81}e^{3x}$.
- Sonuç: $e^{3x}\left(\dfrac{x^3}{3} - \dfrac{3x^2}{9} + \dfrac{6x}{27} - \dfrac{6}{81}\right) + C = e^{3x}\left(\dfrac{x^3}{3} - \dfrac{x^2}{3} + \dfrac{2x}{9} - \dfrac{2}{27}\right) + C$.
- Bir öğrenci $e^{3x}$'in integralinin $3e^{3x}$ olup olmadığını soruyor. Hoca: O türevdir. İntegral $\dfrac{1}{3}e^{3x}$'tir; türevi $e^{3x}$'i verir.

### Ders sonrası notlar

- **Örnek 7'de hoca alt sınırı yanlış yerine koyuyor.** Tahtada $e^{\sin^2 x}(\sin x)' - e^{x^2}\cdot x'$ yazıyor (tahtadan doğrulandı). Alt sınır $x^2$ olduğu için doğrusu $e^{(x^2)^2}\cdot(x^2)' = 2x\,e^{x^4}$. Doğru sonuç: $e^{\sin^2 x}\cos x - 2x\,e^{x^4}$.
- **Örnek 10'da pay $-1$'e değil $+1$'e gider.** Hoca "eksi bir bölü sıfır" diyor. Doğrusu $(-1)\cdot 0 - (-1)\cdot 1 = 1$. Sonuç değişmez: limit yok.
- **Örnek 11'de son adım:** Altyazıda hoca $f'(0) = \dfrac{1}{\sqrt{2}}$ diyor, sonrası anlaşılmıyor. İstenen $(f^{-1})'(0) = \dfrac{1}{f'(0)} = \sqrt{2}$'dir. $\dfrac{1}{\sqrt{2}}$ ile karıştırmayın.
- **Örnek 2'deki $\ln(x^2+x)$:** Bu fonksiyon yalnız $x > 0$ veya $x < -1$ için tanımlıdır. $x = 0$'da tanımsızdır. Alt sınırı $0$ olan integral aslında has olmayan (improper) bir integral olur. Hoca bunu yalnız temel teoremin uygulanışını göstermek için yazıyor.
- **Tablo yöntemi için:** Hocanın söylediği $P$-$T$-$E$ sıralaması yaygın LIATE kuralının (Logaritma, ters trigonometrik, cebirsel, trigonometrik, üstel) bir parçasıdır. Sırada önce gelen $u$ seçilir.
- Min-max örneğinde hoca önce artanlığı değer karşılaştırarak göstermeye çalışıyor ve karışıyor. En kolay yol türevin işaretine bakmak: $f'(x) = \dfrac{x}{\sqrt{x^2+5}} \ge 0$.
- Ders boyunca hocanın internet bağlantısı kesik kesik. Bazı açıklamalar ve 00:12:03, 00:16:17, 02:18:12 civarındaki kısımlar altyazıda anlaşılmıyor.
- 01:02:16 ile 01:21:15 arası ara verilmiş.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
