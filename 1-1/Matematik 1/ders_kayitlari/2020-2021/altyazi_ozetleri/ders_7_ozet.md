# Ders 7 Çalışma Özeti

## Genel Konular

- Geçen haftanın alıştırmaları: açık formda teğet doğrusu, parçalı fonksiyonda türev, kapalı formda ikinci türev.
- Normal doğrusu (normal line).
- Doğrusallaştırma (linearization) ve diferansiyel yaklaşım (differential approximation).
- Artan ve azalan fonksiyonlar (increasing and decreasing functions).
- Terslenebilirlik (invertibility), birebir (one-to-one) ve örten (onto) fonksiyonlar, yatay doğru testi (horizontal line test).
- Üstel fonksiyonlar (exponential functions) ve doğal üstel fonksiyon $e^x$.
- Logaritma fonksiyonları: doğal logaritma $\ln x$ ve $b$ tabanlı logaritma $\log_b x$.
- Üstel ve logaritmik fonksiyonların türevleri.
- Ters fonksiyonun türevi (derivative of the inverse function).

## Hocanın Özellikle Vurguladığı Kısımlar

- Strateji: Sınavdan önce bütün konuları bitirip genel uygulamalar çözmek. Bu yüzden tatil yapmıyoruz.
- 28 Ekim yarım gün tatil (29 Ekim Cumhuriyet Bayramı arifesi). Ertesi günkü ders 11.00–12.00 arası, 1 saat yapılacak.
  - Diğer grup tatiller yüzünden 5 saat geride kaldı. Hoca iki grubu birlikte götürmek istiyor.
  - Telafi dersi (compensatory lesson) de yapılabilir. Değişiklik olursa hoca e-posta atacak.
- Parçalı fonksiyonda, parçalardan biri her yerde türevlenebilir değilse kesim noktasında türevin tanımı zorunludur.
- Doğrusallaştırmada $a$ noktası, hesap makinesi gerektirmeyecek biçimde seçilmelidir (ör. $\sqrt{9}$).
- Terslenebilirlik özelliği çok önemli. İleride sürekli bu özelliğe döneceğiz. Makine öğrenmesinde çıktıdan girdiyi bulmak gibi uygulamaları var.
- Logaritmanın argümanı pozitif olmalıdır.
- Sık yapılan hatalar: $\ln(a+b) \ne \ln a + \ln b$, $\ln\dfrac{a}{b} \ne \dfrac{\ln a}{\ln b}$, $\ln(ab) \ne \ln a \cdot \ln b$.
- Ezber yapmayın. Logaritma ve üstel formülleri terslenebilirlik özelliğinden çıkarın.
- Ters fonksiyonun türevi teoremi çok önemli.

## Kısa Tekrar Notları

- Teğet doğrusu: $y - y_0 = m(x - x_0)$.
- Normal doğrusu teğete diktir. Eğimi $-\dfrac{1}{m}$ olur: $y - y_0 = -\dfrac{1}{m}(x - x_0)$. Eğimlerin çarpımı $-1$'dir.
- Doğrusallaştırma: $f(x) \approx L(x) = f(a) + f'(a)(x - a)$ ($x$, $a$'ya yeterince yakınsa).
- Diferansiyel yaklaşım: $\Delta y \approx f'(a)\,\Delta x$. Limitle $dy = f'(x)\,dx$.
- $f'(x) > 0$ olan aralıkta $f$ artan, $f'(x) < 0$ olan aralıkta azalandır.
- $f: A \to B$ terslenebilir $\iff$ $f$ birebir ve örtendir.
- Ters özellik: $f^{-1}(f(x)) = x$ ve $f(f^{-1}(y)) = y$.
- $e^{\ln x} = x$ ($x > 0$), $\ln(e^x) = x$. $\ln a = b \iff e^b = a$.
- $b^{\log_b x} = x$, $\log_b(b^x) = x$. $\log_b a = c \iff b^c = a$.
- Türevler:
  - $(e^x)' = e^x$, $(e^u)' = e^u \cdot u'$
  - $(b^x)' = b^x \ln b$
  - $(\ln x)' = \dfrac{1}{x}$, $(\ln u)' = \dfrac{u'}{u}$
  - $(\log_b x)' = \dfrac{1}{x \ln b}$
- Ters fonksiyonun türevi: $(f^{-1})'(y_0) = \dfrac{1}{f'(x_0)}$, $y_0 = f(x_0)$, $f'(x_0) \ne 0$.

## Detaylı Açıklamalar

### Örnek 1: Açık formda teğet (alıştırma 16)

- $y = \sin^2\left(\dfrac{\pi x^3}{6}\right)$, $x = 1$ noktasında teğet.
- Zincir kuralı: $\dfrac{dy}{dx} = 2\sin\left(\dfrac{\pi x^3}{6}\right) \cos\left(\dfrac{\pi x^3}{6}\right) \cdot \dfrac{3\pi x^2}{6}$.
- $x = 1$'de: $2\sin\dfrac{\pi}{6}\cos\dfrac{\pi}{6} \cdot \dfrac{\pi}{2} = \dfrac{\sqrt{3}\pi}{4}$.
- $y(1) = \sin^2\dfrac{\pi}{6} = \dfrac{1}{4}$.
- Teğet: $y - \dfrac{1}{4} = \dfrac{\sqrt{3}\pi}{4}(x - 1)$.
- Açık formda $y_0$'ı ayrıca bulmak kolaydır: $x_0$'ı fonksiyonda yerine koymak yeter.

### Örnek 2: Parçalı fonksiyonda türev (alıştırma 17)

- $f(x) = 2x + x^2 \sin\left(\dfrac{1}{x}\right)$ ($x \ne 0$), $f(0) = 0$.
- $x \ne 0$ için doğrudan türev alınır:
  - $f'(x) = 2 + 2x\sin\left(\dfrac{1}{x}\right) - \cos\left(\dfrac{1}{x}\right)$.
- $x = 0$'da türevin tanımı zorunludur, çünkü $x^2\sin(1/x)$ parçası $0$'da tanımlı değildir:
  - $f'(0) = \displaystyle\lim_{x \to 0} \frac{2x + x^2\sin(1/x) - 0}{x} = 2 + \lim_{x \to 0} x\sin\left(\frac{1}{x}\right)$.
  - $t = \dfrac{1}{x}$ dönüşümü: $x \sin\dfrac{1}{x} = \dfrac{\sin t}{t}$ ve $t \to \pm\infty$ iken $\dfrac{\sin t}{t} \to 0$.
  - Sonuç: $f'(0) = 2$.
- Bir öğrenci neden doğrudan türev kuralını uygulamadığımızı soruyor.
  - Hoca: Türev ifadesinde $x = 0$ yazarsak $\dfrac{1}{0}$ çıkar, tanımsızdır. Bu yüzden $0$'daki türev ayrıca tanımla bulunur.
- b şıkkı ($f'$'nin $0$'da sürekli olmadığını gösterme) derste çözülmedi. Not: $\cos(1/x)$ terimi $x \to 0$ iken salınır, bu yüzden $\lim_{x\to 0} f'(x)$ yoktur.

### Örnek 3: Kapalı formda ikinci türev

- $x^3 + 2y^3 = 5xy$, $(2, 1)$ noktası. Nokta eğri üzerinde: $8 + 2 = 10$.
- Birinci türev: $3x^2 + 6y^2 y' = 5y + 5x y'$.
  - $(2,1)$'de: $12 + 6m = 5 + 10m \Rightarrow m = \dfrac{7}{4}$.
- İkinci türev için birinci türev denkleminin iki tarafı yeniden $x$'e göre türevlenir:
  - $6x + 12y(y')^2 + 6y^2 y'' = 5y' + 5y' + 5x y''$.
  - $(2,1)$ ve $y' = \dfrac{7}{4}$ yazılır: $12 + 12\left(\dfrac{7}{4}\right)^2 + 6y'' = 10 \cdot \dfrac{7}{4} + 10y''$.
  - Sonuç: $y'' = \dfrac{125}{16}$.
- Bir öğrenci $(y')^2$'nin nereden geldiğini soruyor:
  - $6y^2 \cdot y'$ teriminin türevinde çarpım kuralı kullanılır.
  - $6y^2$'nin türevi $12y \cdot y'$'dir (zincir kuralı). Bu, ikinci $y'$'yü getirir.
  - Dikkat: $(y')^2$ ile $y''$ farklıdır.
- İsterseniz $y$ yerine $f(x)$ yazarak daha rahat görebilirsiniz.

### Normal doğrusu

- Normal doğrusu, teğet doğrusuna dik olan ve aynı noktadan geçen doğrudur.
- Teğetin eğimi $m$ ise normalin eğimi $-\dfrac{1}{m}$'dir.
- Denklemi: $y - y_0 = -\dfrac{1}{m}(x - x_0)$.

### Doğrusallaştırma

- Eskiden insanlar Dünya'yı düz sanıyordu. Bunun matematiksel bir nedeni var:
  - Bir yüzeye yeterince yaklaşırsanız, yüzey düz olmasa da düz bir doğru ya da düzlem gibi görünür.
- Teğetin eğimi $\displaystyle\lim_{x \to a}\frac{f(x)-f(a)}{x-a}$'dır.
- Limit sürecini kaldırıp $x$'i $a$'ya yeterince yakın seçersek:
  - $\dfrac{f(x)-f(a)}{x-a} \approx f'(a)$
  - $f(x) \approx f(a) + f'(a)(x-a) = L(x)$
- $L(x)$ teğet doğrusunun denklemidir. Doğrusal olmayan $f$, $a$ yakınında bu doğru gibi davranır.
- Diferansiyel ilişki: $\Delta y \approx f'(a)\,\Delta x$. Limitte $dy = f'(x)\,dx$ olur.

### Örnek 4: $\sqrt{8{,}9}$ yaklaşık değeri

- $f(x) = \sqrt{x}$, $a = 9$ seçilir. Çünkü $\sqrt{9} = 3$ hesap makinesiz bulunur ve $9$, $8{,}9$'a yakındır.
- $f'(x) = \dfrac{1}{2\sqrt{x}}$, $f'(9) = \dfrac{1}{6}$.
- $L(x) = 3 + \dfrac{1}{6}(x - 9)$.
- $\sqrt{8{,}9} \approx 3 + \dfrac{1}{6}(-0{,}1) = 3 - \dfrac{1}{60} = \dfrac{179}{60} \approx 2{,}983$.
- Bir öğrenci $a$'nın neden $9$ seçildiğini soruyor. Hoca: $a$'yı başka seçersen kökü hesaplamak için yeni bir problem çıkar.
- Başka bir öğrenci $4$ ile $9$'un ortasını seçmeyi soruyor. Hoca: Kökü kolayca dışarı çıkabilen bir değer seçmelisin.

### Örnek 5: $f(x) = \sqrt{x + 3}$, $a = 1$

- $f(1) = 2$, $f'(x) = \dfrac{1}{2\sqrt{x+3}}$, $f'(1) = \dfrac{1}{4}$.
- $L(x) = 2 + \dfrac{1}{4}(x - 1)$.
- $\sqrt{3{,}98}$ için $x = 0{,}98$: $\sqrt{3{,}98} \approx 2 + \dfrac{1}{4}(-0{,}02) = 1{,}995$.
- $\sqrt{4{,}05}$ için $x = 1{,}05$: $\sqrt{4{,}05} \approx 2 + \dfrac{1}{4}(0{,}05) = 2{,}0125$.
- Hesap adımlarının sözlü kısmı altyazıda tam anlaşılmıyor. Değerler yöntemle yeniden hesaplandı.

### Artan ve azalan fonksiyonlar

- **Tanım:** $I$ aralığındaki her $x_1 < x_2$ için:
  - $f(x_1) < f(x_2)$ ise $f$, $I$ üzerinde artandır.
  - $f(x_1) > f(x_2)$ ise $f$, $I$ üzerinde azalandır.
- Türevle test: Grafik boyunca teğetlerin eğimi pozitifse fonksiyon artar, negatifse azalır.
  - $f'(x) > 0 \Rightarrow f$ artan. $f'(x) < 0 \Rightarrow f$ azalan.
- Hocanın benzetmesi: Sorumluluk fonksiyonunuzun türevi pozitifse sorumluluklarınızı yerine getiriyorsunuz. Negatifse her geçen gün onları ihmal ediyorsunuz.
- Grafik örneği:
  - $(-\infty, 0)$'da $f' > 0$, artan.
  - $(0, 4)$'te $f' < 0$, azalan.
  - $(4, \infty)$'da $f' > 0$, artan.
  - $x = 0$'da grafikte kırılma var. $f'(0)$ tanımsız.

### Terslenebilirlik

- **Tanım:** $f: A \to B$ terslenebilirdir $\iff$ $g: B \to A$ diye bir fonksiyon vardır ve
  - $f \circ g = \text{id}_B$ ve $g \circ f = \text{id}_A$.
  - Bu durumda $g = f^{-1}$'dir. $f$, $g$'nin tersiyse $g$ de $f$'nin tersidir.
- Sonuç: $y = f(x)$ ise $f^{-1}(y) = f^{-1}(f(x)) = x$.
- Hocanın açıklaması:
  - $f$, girdiyi ($x$) çıktıya ($y$) taşır. Çıktı verildiğinde girdiyi tek türlü bulabiliyorsanız işlem terslenebilir.
  - Bu her zaman mümkün değildir. Örnek: Tek yönlü su borusu. Su geçer ama geri dönemez. Bu taşıma terslenebilir değildir.

### Birebir ve örten fonksiyonlar

- **Birebir:** Farklı girdiler farklı çıktılara gider: $x_1 \ne x_2 \Rightarrow f(x_1) \ne f(x_2)$.
  - Denk tanım (karşıt ters): $f(x_1) = f(x_2) \Rightarrow x_1 = x_2$.
- **Yatay doğru testi:** Bir yatay doğru grafiği birden fazla noktada kesiyorsa fonksiyon birebir değildir.
  - Dikey doğru testi ise bir eğrinin fonksiyon grafiği olup olmadığını sınar.
- Birebirlik tanım kümesine bağlıdır. $f(x) = x^2$, $\mathbb{R}$'de birebir değil, $[0, \infty)$'da birebirdir.
- **Örten:** $f: A \to B$ için $f(A) = B$ ise $f$ örtendir.
- **Teorem:** $f: A \to B$ terslenebilir $\iff$ $f$ birebir ve örten.
- $f$'yi $D$'den $f(D)$'ye tanımlarsak örtenlik kendiliğinden sağlanır. O zaman birebirlik yeterlidir.
- Önemli fikir: Kuralı değiştirmeden tanım kümesini kısıtlayarak birebir ve örten, yani terslenebilir bir fonksiyon elde edebiliriz. Bu fikir ileride kullanılacak.
- Görüntü kümesi, grafiğin $y$ eksenine dik izdüşümüdür.

### Üstel fonksiyonlar

- $f(x) = b^x$, $b > 0$ ve $b \ne 1$.
  - $b = 1$ olursa sabit fonksiyon elde edilir. Birebir olmaz, üstel fonksiyon değildir.
- $y = 2^x$: $x = 0$'da $y = 1$. $b > 1$ olduğu için artan.
- $y = \left(\dfrac{1}{2}\right)^x = 2^{-x}$: $0 < b < 1$. $y = 2^x$ grafiğinin $y$ eksenine göre simetriğidir.
- $e \approx 2{,}718...$ evrende sık görülen özel bir sabittir ($\pi$ ve altın oran gibi).
- Doğal üstel fonksiyon $e^x$ (ya da $\exp(x)$):
  - Tanım kümesi $\mathbb{R}$, görüntü kümesi $(0, \infty)$.
  - Birebir ve örtendir. Bu yüzden tersi vardır.

### Logaritma fonksiyonları

- $e^x$'in tersi doğal logaritmadır: $\ln: (0, \infty) \to \mathbb{R}$.
- Ters özellik: $e^{\ln x} = x$ ($x > 0$) ve $\ln(e^x) = x$.
- $\ln a = b$ ise iki tarafa $\ln$'in tersini uygularız: $e^b = a$. Formül ezberlemeye gerek yok.
- $y = e^x$ ve $y = \ln x$ grafikleri $y = x$ doğrusuna göre simetriktir.
- $y = \ln x$ eğrisi $e^y = x$ biçiminde de yazılabilir. Bu iki gösterim aynı grafiği verir.
- **Örnek 6:** $f(x) = \ln(x^2 - 1)$ fonksiyonunun tanım kümesi.
  - $x^2 - 1 > 0 \Rightarrow |x| > 1 \Rightarrow x < -1$ ya da $x > 1$.
  - Tanım kümesi: $(-\infty, -1) \cup (1, \infty)$.
- $b$ tabanlı logaritma: $b^x$'in tersi $\log_b x$'tir.
  - $b^{\log_b x} = x$, $\log_b(b^x) = x$.
  - $\log_b a = c \iff b^c = a$.
  - Taban büyüdükçe $\log_b x$ grafiği $x$ eksenine doğru yatıklaşır.
- Kurallar:
  - $\ln(ab) = \ln a + \ln b$
  - $\ln\dfrac{a}{b} = \ln a - \ln b$
  - Bunlar ters özellikle gösterilebilir.

### $e^x$'in türevi

- Ders dışı bilgi (bir sonraki dönemin konusu): $e^x \approx 1 + x + \dfrac{x^2}{2!} + \dfrac{x^3}{3!} + \dots + \dfrac{x^n}{n!} + \dots$
- Terim terim türev alınca aynı seri tekrar çıkar. Yani $(e^x)' = e^x$.
- Hoca bunu yalnız $e^x$'in türevinin kendisine eşit olduğunu göstermek için anlatıyor. Serinin nasıl elde edildiği gelecek dönem öğrenilecek.
- Zincir kuralıyla: $(e^{u(x)})' = e^{u} \cdot u'$.
- **Örnek 7:** $y = e^{\cos^2 x}$. $y' = e^{\cos^2 x} \cdot 2\cos x \cdot (-\sin x)$.

### $b^x$'in türevi

- $b > 0$ olduğu için $b = e^h$ yazılabilir. Ters özellikten $h = \ln b$.
- $y = b^x = e^{hx}$. $y' = e^{hx} \cdot h = b^x \ln b$.
- Özel durum $b = e$: $(e^x)' = e^x \ln e = e^x$, çünkü $\ln e = 1$.

### $\ln x$ ve $\log_b x$'in türevi

- $y = \ln x \Rightarrow e^y = x$.
- İki tarafın $x$'e göre türevi: $e^y \cdot y' = 1 \Rightarrow y' = \dfrac{1}{e^y} = \dfrac{1}{x}$.
- Zincir kuralıyla: $(\ln u)' = \dfrac{u'}{u}$.
- **Örnek 8:** $y = \ln\big(\sec(x^2 + \sin x)\big)$.
  - $y' = \dfrac{\sec(x^2+\sin x)\tan(x^2+\sin x)(2x + \cos x)}{\sec(x^2 + \sin x)} = \tan(x^2+\sin x)(2x+\cos x)$.
- **Örnek 9:** $y = \log_b x \Rightarrow b^y = x$.
  - $b^y \ln b \cdot y' = 1 \Rightarrow y' = \dfrac{1}{b^y \ln b} = \dfrac{1}{x \ln b}$.
  - $b = e$ için $\dfrac{1}{x}$ çıkar. $\ln x$, $\log_b x$'in özel hâlidir.
- Bir öğrenci $b^y$'nin türevini soruyor. Hoca: $(b^x)' = b^x \ln b$ idi. Burada $y$, $x$'e bağlı olduğu için $b^y \ln b \cdot y'$ olur.

### Ters fonksiyonun türevi

- **Teorem:** $f'(a)$ var ve $f'(a) \ne 0$ olsun. O zaman $a$'yı içeren bir $I$ aralığı vardır:
  - $f$, $I$ üzerinde terslenebilirdir.
  - $f^{-1}$, $b = f(a)$ noktasında türevlenebilirdir.
  - $(f^{-1})'(b) = \dfrac{1}{f'(a)}$.
- Kanıt: $f^{-1}(f(x)) = x$ eşitliğinin iki tarafı $x$'e göre türevlenir.
  - Zincir kuralı: $(f^{-1})'(f(x)) \cdot f'(x) = 1$.
  - $f'(x) \ne 0$ ise $(f^{-1})'(f(x)) = \dfrac{1}{f'(x)}$.
- Yorum: Türev bir noktada sıfırdan farklıysa fonksiyon o noktanın çevresinde terslenebilir. Tersin türevi, türevin çarpımsal tersidir.

### Örnek 10: Ters fonksiyonun bir noktadaki türevi

- $f(x) = \sqrt{x} + x^2 + 1$, $x \ge 0$ için birebirdir.
- $y = f^{-1}(x)$ eğrisinin $(3, 1)$ noktasındaki eğimi isteniyor.
- $(1, 3)$, $f$'nin grafiğindedir: $f(1) = 3$. Bu yüzden $(3, 1)$, $f^{-1}$'in grafiğindedir.
- $f'(x) = \dfrac{1}{2\sqrt{x}} + 2x$, $f'(1) = \dfrac{1}{2} + 2 = \dfrac{5}{2}$.
- $(f^{-1})'(3) = \dfrac{1}{f'(1)} = \dfrac{2}{5}$.
- $f^{-1}$'in formülünü bulmaya gerek yoktur.

### Ders sonrası notlar

- Hoca doğal üstel fonksiyonu "$f(a \cdot b) = f(a) + f(b)$ ve $f' = f$" diye tanımlıyor. Birinci koşul logaritmanın özelliğidir. Doğrusu: $f(a + b) = f(a) \cdot f(b)$, $f' = f$ ve $f(0) = 1$.
- "$f$, $I$'da artandır $\iff$ $f' > 0$" ifadesi tam doğru değil. $f' > 0$ ise $f$ artandır, ama tersi her zaman doğru değil. Örnek: $f(x) = x^3$ artandır ama $f'(0) = 0$.
- $\ln(x^2 - 1)$ örneğinde hoca bir yerde "$x > -1$" diyor. Doğrusu $x < -1$ ya da $x > 1$.
- Hoca bir yerde "fonksiyon türevlenebilir olmasa dahi" diyor. Kastettiği "birebir olmasa dahi": tanım kümesini kısıtlayarak birebir fonksiyon elde edilebilir.
- Ters fonksiyon teoreminde tam ifade için $f'$'nin $a$ çevresinde sürekli olması da gerekir. Ders düzeyinde örneklerde bu sağlanır.
- Hoca $b^y$'nin türevini anlatırken "$b^{-y} \cdot \dfrac{1}{\ln b}$" ara adımını yazıyor. Bu, $\dfrac{1}{b^y \ln b}$ ile aynıdır.
- Kayıtta kısa ara verildiği için 02:08 ile 02:21 arası boştur.
- Bazı bölümlerin sözlü anlatımı (ör. 00:21:41, 00:27:14, 00:34:19, 01:43:44, 02:29:09) altyazıda döngüye girmiş. Bu kısımlar altyazıda anlaşılmıyor. Çözümler ekrandaki ders notlarından tamamlandı.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
