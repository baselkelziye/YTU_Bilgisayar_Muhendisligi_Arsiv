# Ders 11 Çalışma Özeti

> Tarih: 10 Kasım 2020 (Salı). Ders İngilizce anlatıldı, arada Türkçe açıklamalar var. Hoca bu dersten itibaren Zoom'un beyaz tahtası yerine tablet uygulamasıyla yazıyor.

## Genel Konular

- 1. vize sınavı hakkında bilgi: konular, soru sayısı, tarih.
- Türevin uygulamaları (applications of derivatives) bölümüne giriş.
- Mutlak maksimum ve minimum (absolute maximum/minimum): nokta ve değer kavramları.
- Uç değer teoremi (extreme value theorem): kapalı aralıkta sürekli fonksiyon.
- Yerel (local) maksimum ve minimum.
- Kritik nokta (critical point) tanımı ve örnekler.
- Yerel uç değer ile kritik nokta ilişkisi: gerek şart, yeter şart değil.
- Kapalı aralıkta mutlak uç değerlerin bulunması.
- Birinci türev testi (first derivative test).
- Rolle teoremi (Rolle's theorem) ve ortalama değer teoremi (mean value theorem).

## Hocanın Özellikle Vurguladığı Kısımlar

- **Bugünkü konuların hiçbiri 1. vizeye dahil değil.** Ekstremumlar, kritik noktalar, Rolle ve ortalama değer teoremi final konusudur.
- 1. vize L'Hôpital kuralına (belirsiz formlar dahil) kadar olan konuları kapsar.
- "An absolute maximum point" ama "**the** absolute maximum value": değer tektir, nokta birden fazla olabilir.
- Uç değer teoreminde iki şart şarttır: süreklilik ve aralığın **kapalı** olması.
- Kritik nokta olabilmesi için noktanın önce tanım kümesinde olması gerekir. Önce tanım kümesini bulun; yoksa hata yaparsınız.
- Yerel uç değer kritik noktada aranır. Ama her kritik noktada uç değer olmak zorunda değildir.
- Tanımların "ruhunu" kavrayın. Ezber yaparsanız karıştırırsınız.
- Sınavda sorunun yapısına odaklanın. Fonksiyon değiştirilerek benzer soru sorulabilir.
- Ortalama değer teoremi sorusunda yalnız süreklilikten $a$ bulup bırakmayın. Türevlenebilirliği de kontrol edin. Şıklarda "öyle bir $a$ yoktur" da olabilir.

## Kısa Tekrar Notları

- $c \in D$, her $x \in D$ için $f(c) \ge f(x)$ ise $c$ bir mutlak maksimum noktası, $f(c)$ mutlak maksimum değeridir.
- Uç değer teoremi: $f$, $[a,b]$'de sürekli ise $[a,b]$'de mutlak maksimum ve mutlak minimum değeri vardır.
- Yerel maksimum: $c$'yi içeren bir **açık** $I \subset D$ aralığı var ve her $x \in I$ için $f(c) \ge f(x)$.
- Her mutlak uç değer yereldir; her yerel uç değer mutlak değildir.
- Kritik nokta: $c \in D(f)$ ve ($f'(c) = 0$ ya da $f'(c)$ yok).
- $f$'nin $c$'de yerel uç değeri varsa $c$ kritik noktadır (gerek şart). Tersi her zaman doğru değil: $f(x) = x^3$, $c = 0$.
- Birinci türev testi: $c$'de $f'$ işaret değiştirirse uç değer var:
  - $+ \to -$: yerel maksimum.
  - $- \to +$: yerel minimum.
  - İşaret değişmezse uç değer yok.
- Rolle: $[a,b]$'de sürekli, $(a,b)$'de türevlenebilir ve $f(a) = f(b)$ ise $f'(c) = 0$ olan en az bir $c \in (a,b)$ vardır.
- Ortalama değer teoremi: $[a,b]$'de sürekli, $(a,b)$'de türevlenebilir ise $f'(c) = \dfrac{f(b) - f(a)}{b - a}$ olan en az bir $c \in (a,b)$ vardır.
- Rolle teoremi ortalama değer teoreminin özel hâlidir.

## Detaylı Açıklamalar

### 1. vize bilgileri

- **Konular:**
  - Limit ve süreklilik.
  - Türev: zincir kuralı, kapalı (implicit) türev, türevin tanımı.
  - Teğet ve normal doğrular. Bir soru kapalı türevle birleştirilebilir.
  - Aşkın fonksiyonlar (transcendental functions): üstel, logaritmik, ters trigonometrik, hiperbolik.
  - Belirsiz formlar: $\dfrac{0}{0}$, $\dfrac{\infty}{\infty}$, $\infty - \infty$, üstel belirsizlikler ($1^\infty$ vb.). L'Hôpital kuralı.
- **Format:** Büyük ihtimalle çoktan seçmeli test, yaklaşık 20 soru. Süreyi hoca hatırlamıyor.
- **Dağılım tahmini:**
  - Limit ve süreklilikle ilgili en az 5-6 soru.
  - Hiperbolik fonksiyonlardan en fazla 1-2 soru.
  - Türevin tanımı ve kapalı türevden soru gelir.
- **Tarih:** Hocaya bildirilmedi. Büyük ihtimalle 7. veya 8. haftadan sonra. Kesin tarih için Matematik Bölümü'nün web sayfası takip edilmeli.
- **Plan:** Hoca 7. haftanın konularını (kritik noktalar, Rolle, ortalama değer teoremi) hızlıca bitirip vize öncesi bol soru çözmek istiyor.
- Hoca, şubede tatil nedeniyle eksik ders olmadığını, 6. haftada olduklarını söyledi.

### Mutlak maksimum ve minimum

**Tanım:**

- $f: D \to \mathbb{R}$ ve $c \in D$.
- Her $x \in D$ için $f(c) \ge f(x)$ ise $c$ **bir** mutlak maksimum noktası (an absolute maximum point), $f(c)$ **the** mutlak maksimum değeridir.
- Her $x \in D$ için $f(c) \le f(x)$ ise $c$ bir mutlak minimum noktası, $f(c)$ mutlak minimum değeridir.
- Kısaca $\max f$ ve $\min f$ yazılır.

**Örnekler:**

- $f(x) = x^2$, $D = \mathbb{R}$:
  - Her $x$ için $f(0) \le f(x)$. $x = 0$ mutlak minimum noktası, $f(0) = 0$ mutlak minimum değeri.
  - Mutlak maksimum yok.
- $f(x) = x^2$, $D = [0, 2]$:
  - Grafik kalem kaldırmadan çizilir (sürekli).
  - $x = 2$ mutlak maksimum noktası, $f(2) = 4$ mutlak maksimum değeri.
  - $x = 0$ mutlak minimum noktası, $f(0) = 0$ mutlak minimum değeri.
- $f(x) = x^2$, $D = (0, 2]$:
  - Mutlak maksimum var ($x = 2$, değer 4).
  - Mutlak minimum noktası yok, bu yüzden mutlak minimum değeri de yok.
- $f(x) = \sin x$, $D = \mathbb{R}$:
  - $\max f = 1$, $\min f = -1$; değerler tek.
  - Mutlak maksimum noktaları ($\frac{\pi}{2} + 2k\pi$) ve mutlak minimum noktaları ($-\frac{\pi}{2} + 2k\pi$) sonsuz tane.
- $f(x) = \sin x$, $D = \left(0, \dfrac{\pi}{4}\right)$: mutlak maksimum da mutlak minimum da yok.
- $f(x) = \sin x$, $D = (0, \pi)$:
  - Sürekli. $x = \dfrac{\pi}{2}$ mutlak maksimum noktası, $\max f = 1$.
  - Mutlak minimum yok (uç noktalar dahil değil).

**Öğrenci soruları:**

- Soru: İçi boş uç noktada "nokta var ama değer yok" mu denir? Cevap: İkisi de yok. Nokta tanım kümesinde değil. Değer olması için noktanın olması gerek şarttır.
- Soru: $x \to 0^+$ limiti alınarak minimum denemez mi? Cevap: Limit, fonksiyonun yaklaştığı değerdir. Fonksiyonun o değeri alması gerekmez (sürekli değilse). Burada $f(0)$ tanımlı değil. Limit ile fonksiyon değeri çok farklı kavramlardır.

### Uç değer teoremi

- **Teorem:** $f$, kapalı $[a,b]$ aralığında sürekli ise $[a,b]$ üzerinde mutlak maksimum değeri ($\max f$) ve mutlak minimum değeri ($\min f$) vardır.
- Şartlar: süreklilik ve kapalılık. Bunlar olmadan teorem kullanılamaz.
- Hoca, ispatı fikir olarak bir grafik üzerinde gösterdi.
- Aralık kapalı değilse de fonksiyonun mutlak uç değeri olabilir (ör. $\sin x$, $\mathbb{R}$'de). Ama garanti yoktur.

### Yerel maksimum ve minimum

**Tanım:**

- $f: D \to \mathbb{R}$, $c \in D$.
- $c$'yi içeren bir açık $I \subset D$ aralığı varsa ve her $x \in I$ için $f(c) \ge f(x)$ ise $c$ bir yerel maksimum noktası, $f(c)$ yerel maksimum değeridir.
- Yerel minimum benzer şekilde ($f(c) \le f(x)$).
- Hoca bir ara $I$'yı kapalı yazdı, sonra düzeltti: $I$ açık aralık olmalı.

**Grafik üzerinde:**

- $c_1$ ve $c_2$ etrafında açık aralıklar $I_1$, $I_2$ seçilir. Bu aralıklarda $f(c_1)$ ve $f(c_2)$ en büyüktür. İkisi de yerel maksimumdur.
- Yerel maksimum değeri birden fazla olabilir. Mutlak maksimum değeri ise tektir.
- Tüm yerel minimum değerler karşılaştırılarak mutlak minimum, tüm yerel maksimum değerler karşılaştırılarak mutlak maksimum bulunur.
- Her mutlak uç değer yereldir; tersi doğru değildir.
- Ekstremum (extremum) yerel maksimum veya yerel minimumun genel adıdır.

### Kritik nokta

**Tanım:**

- $c \in D(f)$ olsun. $f'(c) = 0$ veya $f'(c)$ yoksa $c$ bir kritik noktadır.
- $c \in D(f)$ ön şarttır. Bu olmadan kritik noktadan söz edilemez.

**Örnek 1: Üst yarım çember** $f(x) = \sqrt{1 - x^2}$

- $D(f) = [-1, 1]$.
- $f'(x) = \dfrac{-2x}{2\sqrt{1 - x^2}} = \dfrac{-x}{\sqrt{1-x^2}}$.
- $f'(0) = 0$ ve $0 \in D$: $c_1 = 0$ kritik nokta.
- $f'(-1)$ ve $f'(1)$ yok (payda sıfır), $\pm 1 \in D$: $c_2 = -1$, $c_3 = 1$ kritik nokta.

**Örnek 2:** $f(x) = |x|$

- $f'(0)$ yok ve $0 \in D(f)$. Bu yüzden $c = 0$ kritik nokta.

**Örnek 3:** $f(x) = x + \dfrac{1}{x}$, tüm kritik noktaları bulun.

- Önce tanım kümesi: $D(f) = \mathbb{R} \setminus \{0\}$.
- $f'(x) = 1 - \dfrac{1}{x^2} = \dfrac{x^2 - 1}{x^2}$.
- $f'(\pm 1) = 0$ ve $\pm 1 \in D$: $x = 1$ ve $x = -1$ kritik nokta.
- $f'(0)$ yok ama $0 \notin D(f)$. Bu yüzden **0 kritik nokta değildir.**
- Hoca: Herkes aynı hatayı yaptı (0'ı kritik nokta saydı).
- Bir öğrenci kritik nokta ile kırılma noktasının (köşe) aynı olup olmadığını sordu. Cevap: Hayır. 0'da fonksiyon tanımlı değil. Grafikte kırılma noktasından söz etmek için noktanın tanım kümesinde olması gerekir ($|x|$'te olduğu gibi).

### Yerel uç değer ve kritik nokta teoremi

- **Teorem:** $f$'nin $c$'de yerel maksimumu veya minimumu varsa, bu değer bir kritik noktada oluşur.
- Mantık diliyle $p \Rightarrow q$. Burada $q$ (kritik nokta olması) **gerek şart**tır, yeter şart değildir.
- Her kritik noktada yerel uç değer olmak zorunda değildir.

**Örnek:** $f(x) = x^2$

- $f(0) \le f(x)$, $0$'ı içeren her aralıkta. $f(0) = 0$ yerel (ve mutlak) minimum değeri.
- $f'(x) = 2x$, $f'(0) = 0$: $x = 0$ kritik nokta. Teoremle uyumlu.

**Karşı örnek:** $f(x) = x^3$

- $f'(x) = 3x^2$, $f'(0) = 0$ ve $0 \in D$: $x = 0$ kritik nokta.
- Ama $0$'ı içeren hiçbir açık aralıkta tüm $x$'ler için $f(x) \ge f(0)$ ya da $f(x) \le f(0)$ olmaz. Bazı $x$'ler için $f(x) < 0$, bazıları için $f(x) > 0$.
- Yerel uç değer yok. Yani $q \Rightarrow p$ her zaman doğru değil.

**Not:** Uç değerler kritik noktalarda aranır. Ama $f$'nin her kritik noktada mutlak ya da yerel uç değeri olmak zorunda değildir.

### Örnek 4: $f(x) = x^4 - 2x^3$, $[-2, 2]$

- (a) Yerel uç değerleri, (b) mutlak uç değerleri inceleyin.
- **Kritik noktalar:**
  - $f'(x) = 4x^3 - 6x^2 = 2x^2(2x - 3)$.
  - Türevi tanımsız yapan $x$ yok. Kökler: $c_1 = 0$, $c_2 = \dfrac{3}{2}$. İkisi de aralıkta.
- **Uç noktalar dahil değerler:**
  - $f(-2) = 16 + 16 = 32$.
  - $f(2) = 16 - 16 = 0$.
  - $f(0) = 0$.
  - $f\!\left(\dfrac{3}{2}\right) = \dfrac{81}{16} - \dfrac{108}{16} = -\dfrac{27}{16}$.
- **Mutlak:** Mutlak maksimum değeri 32 ($x = -2$), mutlak minimum değeri $-\dfrac{27}{16}$ ($x = \dfrac{3}{2}$).
- Bir öğrenci $x = 0$'ın uç değer olduğunu nereden bildiklerini sordu. Hoca öğrencinin haklı olduğunu, bunu kontrol etmek için bir teste ihtiyaç olduğunu söyledi ve birinci türev testine geçti. Test sonucu: $x = 0$'da uç değer **yok** (aşağıya bakın).

### Birinci türev testi

- $c$ bir kritik nokta ($f'(c) = 0$ veya $f'(c)$ yok).
- **Durum 1:** $c$'nin solunda $f' > 0$, sağında $f' < 0$:
  - $f$ solda artan, sağda azalan. $c$'de **yerel maksimum** vardır.
  - Örnek: $y = -x^2$ ($f'(0) = 0$), $y = -|x|$ ($f'(0)$ yok).
- **Durum 2:** Solda $f' < 0$, sağda $f' > 0$:
  - $f$ solda azalan, sağda artan. $c$'de **yerel minimum** vardır.
  - Örnek: $y = x^2$, $y = |x|$.
- **Durum 3:** $f'$ işaret değiştirmez ($+ +$ veya $- -$):
  - $c$ kritik nokta olsa bile uç değer **yoktur**.
  - Örnek: $f(x) = x^3$, $f'(x) = 3x^2$; $0$'ın iki yanında da $+$.

**Örnek 4'e uygulama** ($f'(x) = 2x^2(2x - 3)$):

| Aralık | $x < 0$ | $0 < x < \frac{3}{2}$ | $x > \frac{3}{2}$ |
|---|---|---|---|
| $x^2$ | $+$ | $+$ | $+$ |
| $2x - 3$ | $-$ | $-$ | $+$ |
| $f'$ | $-$ | $-$ | $+$ |
| $f$ | azalan | azalan | artan |

- $x = 0$: $f'$ işaret değiştirmiyor (çift katlı kök). Uç değer yok.
- $x = \dfrac{3}{2}$: $- \to +$. Yerel minimum, değer $f\!\left(\dfrac{3}{2}\right) = -\dfrac{27}{16}$.
- Hoca: Kök çift katlıysa ($x^2$, $x^4$...) işaret değişmez; tek katlıysa ($x^3$...) durum değişir.

### Örnek 5 (test tipi): $f(x) = 3x^4 - 4x^3 - 6x^2 + 12x + 1$

- (a) Artan/azalan olduğu aralıkları, (b) yerel uç değerleri bulun.
- **Türev:**
  - $f'(x) = 12x^3 - 12x^2 - 12x + 12 = 12(x^3 - x^2 - x + 1)$.
  - $x = 1$ bir kök. Bölme ile: $f'(x) = 12(x + 1)(x - 1)^2$.
- **İşaret:** $(x-1)^2 \ge 0$ işaret değiştirmez. Yalnız $x + 1$ belirleyicidir.
  - $x < -1$: $f' < 0$, $f$ azalan. Azalan aralık $(-\infty, -1)$.
  - $x > -1$: $f' > 0$ ($x = 1$ hariç sıfır), $f$ artan. Artan aralık $(-1, \infty)$.
- **Uç değerler:**
  - $x = -1$: $- \to +$, yerel minimum.
  - $f(-1) = 3 + 4 - 6 - 12 + 1 = -10$.
  - $x = 1$: işaret değişmiyor, uç değer yok. Yerel maksimum yok.
- Hoca önce $-1$'i yanlışlıkla türev fonksiyonuna koydu; bir öğrenci uyardı, hoca düzeltti.

### Rolle teoremi

- **Teorem:** $f$ şu şartları sağlasın:
  - $[a,b]$ kapalı aralığında sürekli.
  - $(a,b)$ açık aralığında türevlenebilir.
  - $f(a) = f(b)$.
- O zaman $f'(c) = 0$ olacak şekilde en az bir $c \in (a,b)$ vardır.
- Süreklilik: grafik kalem kaldırmadan çizilir. Türevlenebilirlik: grafikte kırılma noktası yok.
- Geometrik anlam: Grafikte yatay teğet doğrunun olduğu en az bir iç nokta vardır.
- Fiziksel yorum: Bir araç $t = -1$'den $t = 1$'e kadar düzgün hareket ediyor ve başladığı konuma geri dönüyor. Arada anlık hızının sıfır olduğu bir an vardır.

**Örnek 6:** $a$'nın hangi değeri için Rolle teoremi $f(x) = x^2 - ax$ fonksiyonuna $[-1, 1]$ aralığında uygulanabilir?

- Polinom: her $a$ için her yerde sürekli ve türevlenebilir ($f'(x) = 2x - a$).
- Uç nokta şartı: $f(-1) = 1 + a$, $f(1) = 1 - a$. $1 + a = 1 - a \Rightarrow a = 0$.
- Uygulama: $f(x) = x^2$, $f'(c) = 2c = 0 \Rightarrow c = 0 \in (-1, 1)$.
- Hoca: Böyle bir $a$ değeri olmak zorunda değil; soru yapısı önemli.

### Ortalama değer teoremi

- **Teorem:** $f$, $[a,b]$'de sürekli ve $(a,b)$'de türevlenebilir ise:

$$f'(c) = \frac{f(b) - f(a)}{b - a}$$

  olacak şekilde en az bir $c \in (a, b)$ vardır.
- Sol taraf: $c$ anındaki anlık değişim oranı (instantaneous rate of change).
- Sağ taraf: $[a,b]$ üzerindeki ortalama değişim oranı (average rate of change).
- Fiziksel yorum: Düzgün hareket eden bir aracın anlık hızının ortalama hıza eşit olduğu en az bir iç an vardır.
- Geometrik yorum: Uç noktaları birleştiren kirişin (üçgenin hipotenüsü) eğimi $\tan\theta = \dfrac{f(b) - f(a)}{b - a}$. Bu kirişe paralel teğet doğrusu olan en az bir iç nokta vardır.
- Rolle teoremi, $f(a) = f(b)$ olan özel durumdur.

**Örnek 7:** Ortalama değer teoremini $f(x) = x^3 - x^2 + 1$ fonksiyonuna $[-1, 1]$ aralığında uygulayın.

- Polinom: şartlar sağlanır.
- $f(1) = 1$, $f(-1) = -1 - 1 + 1 = -1$.
- Ortalama değişim: $\dfrac{1 - (-1)}{1 - (-1)} = 1$.
- $f'(c) = 3c^2 - 2c = 1 \Rightarrow 3c^2 - 2c - 1 = 0 \Rightarrow (3c + 1)(c - 1) = 0$.
- $c = -\dfrac{1}{3}$ veya $c = 1$. Yalnız $c = -\dfrac{1}{3}$ açık aralıkta.
- Cevap: $c = -\dfrac{1}{3}$ anında anlık hız ortalama hıza eşittir.
- Bir öğrenci dosyanın paylaşılmasını istedi. Hoca benzer örneklerin paylaştığı kitapta olduğunu, final öncesi bol örnek çözeceklerini söyledi.

### Örnek 8 (test tipi): Parçalı fonksiyon

- **Soru:** $a$'nın hangi değeri için ortalama değer teoremi şu fonksiyona $[-1, 1]$'de uygulanabilir?

$$f(x) = \begin{cases} \dfrac{e^{ax} - 1}{x}, & x \neq 0 \\ 1, & x = 0 \end{cases}$$

- **Süreklilik ($x = 0$):**
  - $\displaystyle\lim_{x\to 0}\frac{e^{ax} - 1}{x}$ → $\dfrac{0}{0}$. L'Hôpital: $\dfrac{a e^{ax}}{1} \to a$.
  - $f(0) = 1$ olmalı: $a = 1$.
  - Bu gerek şarttır, yeterli değildir.
- **Türevlenebilirlik ($x = 0$):**
  - $x \neq 0$ için türev doğrudan alınır. $x = 0$'da türev formülüne 0 konamaz ($\frac{1}{0}$ tanımsız). Türevin limit tanımı kullanılır.
  - $f'(0) = \displaystyle\lim_{x\to 0}\frac{\frac{e^x - 1}{x} - 1}{x} = \lim_{x\to 0}\frac{e^x - 1 - x}{x^2}$.
  - L'Hôpital: $\dfrac{e^x - 1}{2x}$ → yine $\dfrac{0}{0}$. Tekrar: $\dfrac{e^x}{2} \to \dfrac{1}{2}$.
  - Limit var: $f'(0) = \dfrac{1}{2}$. $f$, $(-1, 1)$'de türevlenebilir.
- **Cevap:** $a = 1$.
- **Devamı (ödev):**
  - $f'(x) = \dfrac{e^x x - (e^x - 1)}{x^2}$ ($x \neq 0$), $f'(0) = \dfrac{1}{2}$.
  - Ortalama değişim: $\dfrac{f(1) - f(-1)}{2} = \dfrac{(e - 1) - (1 - e^{-1})}{2}$.
  - $c$ değerini bulmak hesap makinesi gerektirir. Test sınavında yalnız $a$ sorulur.
- Öğrenci sorusu: Türevlenebilirlik için sağ ve sol türev ayrı ayrı mı hesaplanır? Hoca: Burada iki tarafta da aynı kural geçerli, tek limit yazmak yeterli.
- Hoca'nın uyarısı: Test sınavında yalnız süreklilikten $a = 1$ bulup işaretlemeyin. Bağlantı noktasında türevlenebilirliği kontrol edin; cevap "öyle bir $a$ yoktur" olabilir.

### Ders sonu

- Bir öğrenci bugünkü konuların vizeye dahil olup olmadığını tekrar sordu. Hoca: Dahil değil, final konusu. L'Hôpital ve belirsiz formlar dahil; iki gün öncesine kadarki her şey dahil.
- "See you tomorrow."

### Ders sonrası notlar

- **$f(-1)$ hesabı (Örnek 5):** Altyazıda "7, 1..." diye yarım kalan hesap var. Doğrusu $3 + 4 - 6 - 12 + 1 = -10$.
- **Örnek 6:** Altyazıda $f(-1)$ için "1 minus 1 plus a" geçiyor. Doğrusu $f(-1) = (-1)^2 - a(-1) = 1 + a$.
- **Uç noktalar ve yerel uç değer:** Hoca Örnek 4'te uç noktalardaki değerleri de yerel uç değer saydı. Ders kitaplarında (ör. Thomas) uç noktadaki yerel uç değer, açık aralık yerine yarı açık aralıkla tanımlanır. Derste verilen tanımla (açık aralık) uç noktalar yerel uç nokta olamaz. Sınavda kitaptaki tanımı esas alın.
- **"Her mutlak uç değer yereldir":** Yukarıdaki tanım farkı nedeniyle bu ifade uç noktada oluşan mutlak uç değerler için ancak kitap tanımıyla doğrudur.
- **Örnek 1 (yarım çember):** Altyazıda "$f'(1)$, 0" geçiyor. Doğrusu $f'(1)$ yoktur (payda sıfır); $x = 1$ bu yüzden kritik noktadır.
- Altyazıda birkaç kısa döngü ve anlaşılmayan yer var (ör. 00:32:44, 00:44:02, 02:39:44-02:41:09). Bu kısımlar altyazıda anlaşılmıyor; içerik ekran görüntüleri ve çevredeki anlatımdan tamamlandı.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
