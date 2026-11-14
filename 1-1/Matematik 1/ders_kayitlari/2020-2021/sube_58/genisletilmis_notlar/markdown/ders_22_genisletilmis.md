# Ders 22 Genişletilmiş Notu: 2. Vize Hazırlık: Temel Teorem, Riemann Toplamı, Grafik Çizimi ve Mazeret Sınavı Soruları

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dersin Çerçevesi
- 2. Temel Teorem 1. Kısım ile Çözülen Sorular
- 3. Riemann Toplamı ile Alan
- 4. Ortalama Değer ve Ortalama Değişim Oranı
- 5. Belirli İntegralle Tanımlı Fonksiyonlar Üzerine Diğer Sorular
- 6. Grafik Çizimi: $y = \dfrac{x}{x^2-1}$
- 7. Asimptot ve İçbükeylik İlişkisi: Grafik Yorumu
- 8. Final Konusu Olan Sorular: Kısmi İntegrasyon ve İndirgeme Formülü
- 9. Geçen Yılın Mazeret Sınavı Soruları
- 10. Geçen Yılın 1. Vizesinden İçbükeylik Sorusu
- Örnek Sorular
- Dersin Toparlaması

## 1. Dersin Çerçevesi

Bu ders 2. vizeye hazırlık için soru çözümü dersidir. Ders İngilizce anlatıldı, arada Türkçe açıklamalar yapıldı. Çözülen soruların büyük kısmı Pınar Albayrak Hoca'nın hazırladığı uygulama notlarındandır (uygulama 5). Bu sorular geçmiş yılların klasik sınavlarından alınmıştır. Hoca, test sınavında bu tarz soruların çıkabileceğini söyledi. Test sınavına uygun bulduğu soruların yanına üç yıldız koydu.

Hocanın tablet kalemi bozuk olduğu için hoca fareyle yazmaya çalıştı. Bu yüzden bazı çözümler ekranda tam yazılamadı, bazıları sözlü olarak geçildi. Altyazıda yalnız sözlü kısım vardır. Ekrandaki ifadeler altyazıdan tam okunamıyorsa bu not BELİRSİZ işaretiyle belirtir.

> **Hocanın vurgusu:** "Ders derste öğrenilir." Önünüzde kâğıt kalem olsun, soruyu kendiniz çözün. Önemli olan çözümün mantığını anlamaktır.

## 2. Temel Teorem 1. Kısım ile Çözülen Sorular

Bu bölümdeki soruların hepsi kalkülüsün temel teoreminin 1. kısmına (Fundamental Theorem of Calculus, Part 1) dayanır. Hoca soruları çözerken teoremin genelleştirilmiş hâlini hatırlattı.

**Temel Teorem 1. Kısım (genelleştirilmiş hâli)**

- $f$ sürekli, $a(x)$ ve $b(x)$ türevlenebilir olsun.
- $$\frac{d}{dx}\int_{a(x)}^{b(x)} f(t)\,dt = f(b(x))\,b'(x) - f(a(x))\,a'(x)$$
- Sözlü kuralı: üst sınır integrant fonksiyonunda $t$ yerine yazılır ve üst sınırın türeviyle çarpılır; alt sınır için de aynısı yapılıp çıkarılır.
- Alt sınır sabitse onun terimi sıfırdır, çünkü sabitin türevi sıfırdır.

**Belirli integralin bir özelliği**

- Alt ve üst sınır aynıysa integralin değeri sıfırdır: $\displaystyle\int_a^a f(t)\,dt = 0$.

### 2.1 Örnek 1: Belirli integral içeren limit

$$L = \lim_{x\to 0} \frac{\displaystyle\int_0^x \frac{\sin^2 t}{\cos t}\,dt}{\tan x}$$

Hoca önce payın ne olduğuna dikkat çekti. Pay, üst sınırı $x$, alt sınırı $0$ olan bir belirli integralle elde edilmiş bir fonksiyondur. Bu integral hesaplanırsa sonunda $x$'e bağlı bir ifade çıkar. Limit değişkeni de $x$'tir.

- **Belirsizliğin tespiti:** $x \to 0$ iken üst sınır $0$'a yaklaşır. $\int_0^0 = 0$ olduğundan pay $0$'a gider. Payda $\tan x$ da $0$'a gider. $\frac{0}{0}$ belirsizliği vardır.
- **L'Hôpital kuralı:** Payın türevi temel teoremden bulunur. Üst sınır $x$ integrant fonksiyonunda $t$ yerine yazılır ve üst sınırın türevi ($1$) ile çarpılır: $\dfrac{\sin^2 x}{\cos x}\cdot 1$.
- Paydanın türevi: $(\tan x)' = \sec^2 x$.
- **Sadeleştirme:**
  $$L = \lim_{x\to 0} \frac{\sin^2 x/\cos x}{\sec^2 x} = \lim_{x\to 0} \sin^2 x\,\cos x = 0$$

Sonuç $L = 0$'dır.

### 2.2 Örnek 2: $\int_0^{\cos x} f(t)\,dt = \arctan x$ ise $f\!\left(\tfrac{1}{\sqrt 2}\right)$

<!-- BELİRSİZ: Bu sorunun metni ve ilk adımları altyazıda yok (00:05:42-00:06:42 arası anlaşılmıyor). Soru metni kısa nottan alındı; altyazıdan yalnız "f(1/√2)'yi elde etmek için uygun x değeri π/4" cümlesi doğrulanıyor. -->

Soru: $x \in \left(0, \tfrac{\pi}{2}\right)$ için $\displaystyle\int_0^{\cos x} f(t)\,dt = \arctan x$ veriliyor. $f\!\left(\tfrac{1}{\sqrt 2}\right)$ isteniyor.

- İki tarafın türevi alınır. Sol tarafta temel teorem kullanılır (alt sınır sabit olduğu için ikinci terim sıfır):
  $$f(\cos x)\cdot(-\sin x) = \frac{1}{1+x^2}$$
- Buradan $f(\cos x) = \dfrac{-1}{\sin x\,(1+x^2)}$.
- $f\!\left(\tfrac{1}{\sqrt 2}\right)$'yi bulmak için $\cos x = \tfrac{1}{\sqrt 2}$ olmalıdır. Verilen aralıkta uygun değer $x = \tfrac{\pi}{4}$'tür. Hoca bunu özellikle vurguladı.
- Temel hesaplarla:
  $$f\!\left(\tfrac{1}{\sqrt2}\right) = \frac{-1}{\tfrac{1}{\sqrt2}\left(1+\tfrac{\pi^2}{16}\right)} = \frac{-16\sqrt2}{\pi^2+16}$$

### 2.3 Örnek 3: $f(x) = \int_1^x (2t)^t\,dt$ ise $f''(1)$

Bu soruyu hoca öğrencilere görev olarak verdi ve çözmeleri için süre tanıdı. Soru: $x \ge 1$ için $f(x) = \displaystyle\int_1^x (2t)^t\,dt$. $f''(1)$ değeri isteniyor. Burada üst sınır $x$'e bağlıdır.

- **Birinci türev:** Temel teoremden üst sınır integrant fonksiyonunda $t$ yerine yazılır: $f'(x) = (2x)^x$.
- **Logaritmik türev:** $f'(x)$ üstel-üstel bir fonksiyondur. İkinci türevi hesaplamak için hoca bu ifadeyi "olağan" bir fonksiyona dönüştürmek gerektiğini söyledi. Bunun için eşitliğin iki tarafına doğal logaritma uygulanır:
  $$\ln f'(x) = x\,\ln(2x)$$
- İki taraf zincir kuralıyla türetilir. Sol tarafta $\ln u$'nun türevi, argümanın türevi bölü argümandır. Sağ tarafta çarpım kuralı uygulanır:
  $$\frac{f''(x)}{f'(x)} = 1\cdot\ln(2x) + x\cdot\frac{2}{2x} = \ln(2x) + 1$$
- İkinci türev $x$ cinsinden: $f''(x) = (2x)^x\,\big[\ln(2x) + 1\big]$.
- $x = 1$ yazılır: $f''(1) = 2\,(\ln 2 + 1)$.

### 2.4 Örnek 4: $f(x) = \cos x - \int_0^{\sin x} \frac{dt}{t^3+8}$ ise $f(\pi)$ ve $f'(\pi)$

Bu sırada hocanın internet bağlantısı koptu. Hoca geri gelince bu soruyu Türkçe anlattı.

- **$f(\pi)$:** Doğrudan $x$ yerine $\pi$ yazılır. $\cos\pi = -1$. İntegralin üst sınırı $\sin\pi = 0$ olur. Alt ve üst sınır aynı olduğu için integral sıfırdır. Böylece $f(\pi) = -1 - 0 = -1$.
- **$f'(x)$:** $\cos x$'in türevi $-\sin x$'tir. İntegral kısmında temel teorem kullanılır: $t$ gördüğümüz yere $\sin x$ yazılır ve $\sin x$'in türevi $\cos x$ ile çarpılır:
  $$f'(x) = -\sin x - \frac{1}{\sin^3 x + 8}\cdot\cos x$$
- **$f'(\pi)$:** $\sin\pi = 0$, $\cos\pi = -1$:
  $$f'(\pi) = -0 - \frac{1}{0+8}\cdot(-1) = \frac18$$

Hoca bunların temel (basic) sorular olduğunu söyledi.

### 2.5 Örnek 5: İkinci türevin $0$'daki değeri (2016 sınavı)

Hoca bu soruyu 2016 yılı sınavından aldı ve test sınavında bu tip soru çıkabileceği için üç yıldız koydu. Öğrencilerden $x = 0$'da ikinci türevin değerini bulmalarını istedi.

<!-- BELİRSİZ: Sorudaki fonksiyonun tam yazımı altyazıda yok. Çözüm adımlarından f'(x) = (x^2+9)^{sin x} olduğu anlaşılıyor. -->

- **Birinci türev:** Temel teoremden $x$ integrant fonksiyonuna yazılır. Çözüm adımlarından anlaşılan: $f'(x) = (x^2+9)^{\sin x}$.
- **Logaritmik türev:** İki tarafa $\ln$ uygulanır: $\ln f'(x) = \sin x \cdot \ln(x^2+9)$.
- Çarpım kuralı ile türev alınır:
  $$\frac{f''(x)}{f'(x)} = \cos x\,\ln(x^2+9) + \sin x\cdot\frac{2x}{x^2+9}$$
- Hoca, ifadeyi sadeleştirmeye gerek olmadığını, doğrudan $x = 0$ yazılabileceğini söyledi.
- Dikkat edilecek nokta: $f'(0) = 9^{\sin 0} = 9^0 = 1$.
- $x = 0$ ve $f'(0) = 1$ yazılırsa: $f''(0) = 1\cdot\big(\cos 0\cdot\ln 9 + 0\big) = \ln 9 = 2\ln 3$.

> **Ders sonrası not:** Hoca önce öğrencilerin çoğunun cevabı "$\ln 2\cdot\ln 3$" bulacağını söyledi; hemen ardından doğru cevabı $2\ln 3$ ya da $\ln 9$ olarak verdi. Doğru cevap $2\ln 3 = \ln 9$'dur (sympy ile doğrulandı).

## 3. Riemann Toplamı ile Alan

### 3.1 Örnek 6: $f(x) = x^3$ grafiği altındaki alan

Soru, $f(x) = x^3$ grafiği ile $[0,1]$ aralığı arasında kalan bölgenin alanını Riemann toplamı (Riemann sum) ile hesaplamayı istiyor.

<!-- BELİRSİZ: Sorunun Türkçe ifadesi altyazıda bozuk (00:22:09-00:22:38). Fonksiyonun x^3, aralığın [0,1] olduğu ve sonucun 1/4 çıktığı altyazıdan doğrulanıyor. -->

- **Aralığı bölme:** $[0,1]$ aralığı $n$ alt aralığa bölünür. Her alt aralığın uzunluğu aynıdır:
  $$\Delta x = \frac{b-a}{n} = \frac{1-0}{n} = \frac1n$$
- **Noktalar:** Aralıktan $n+1$ nokta alınır: $x_0 = 0,\ x_1,\ x_2,\ \dots,\ x_n = 1$. Genel olarak $x_i = \dfrac{i}{n}$. Hoca indisin $i$ ya da $k$ olmasının önemli olmadığını söyledi.
- **Seçilen noktalar:** Her alt aralığın uç noktası alınır ($c_i = x_i$).
- **Toplam:** $f(x) = x^3$ kuralı kullanılır:
  $$\sum_{i=1}^{n} f(x_i)\,\Delta x = \sum_{i=1}^{n} \frac{i^3}{n^3}\cdot\frac1n = \frac{1}{n^4}\sum_{i=1}^{n} i^3$$
- **Toplam formülü:** Sigma notasyonunun özellikleri (sabit çarpanı dışarı alma) ve küplerin toplamı formülü kullanılır:
  $$\sum_{i=1}^{n} i^3 = \left(\frac{n(n+1)}{2}\right)^2 \quad\Rightarrow\quad \frac{1}{n^4}\cdot\frac{n^2(n+1)^2}{4} = \frac{(n+1)^2}{4n^2} \text{ (ara adım eklendi)}$$
- **Limit:** $n \to \infty$ iken hatasız (sıfır hata) gerçek sonuç elde edilir:
  $$A = \lim_{n\to\infty} \frac{(n+1)^2}{4n^2} = \frac14$$

**Soru:** Soru alt Riemann toplamı istiyor, ama toplamda $i = 1$'den $n$'e gidilmiş. $i = 0$'dan $n-1$'e gitmemiz gerekmez mi?
**Cevap:** Hoca, alt ve üst Riemann toplamının limitte aynı gerçek sonuca gittiğini söyledi. Öğrencinin haklı olduğunu kabul etti: notlarda indis yanlış yazılmıştı, hoca sonuca odaklandığı için bunu fark etmemişti.

> **Ders sonrası not:** $x^3$ fonksiyonu $[0,1]$'de artandır. Bu yüzden sol uç noktalar ($i = 0, \dots, n-1$) alt toplamı, sağ uç noktalar ($i = 1, \dots, n$) üst toplamı verir. Notlardaki toplam aslında üst toplamdır. İki toplamın limiti de $\tfrac14$'tür (sympy ile doğrulandı).

Hoca, notlardaki benzer diğer Riemann toplamı sorularının aynı şekilde çözüleceğini söyledi ve onları öğrencilere bıraktı.

## 4. Ortalama Değer ve Ortalama Değişim Oranı

### 4.1 Örnek 7: Ortalama değer sorusu

<!-- BELİRSİZ: Fonksiyon altyazıda "f(x) = 2 plus 1" ve öğrenci sorusunda "f'(x) = 2x + 1" diye geçiyor; aralık ve sonuç altyazıda anlaşılmıyor. Bu sırada hocanın sesi kesildi. -->

Soru, verilen bir $f$ fonksiyonunun verilen aralıktaki ortalama değerini (average value) istiyor. Hoca burada "dikkat" diyerek ortalama değer ile ortalama değişim oranının (average rate of change) farklı kavramlar olduğunu vurguladı.

**Ortalama değer**

- $f$'nin $[a,b]$ üzerindeki ortalama değeri:
  $$f_{\text{ort}} = \frac{1}{b-a}\int_a^b f(x)\,dx$$

**Ortalama değişim oranı**

- $f$'nin $[a,b]$ üzerindeki ortalama değişim oranı: $\dfrac{f(b)-f(a)}{b-a}$.

> **Hocanın vurgusu:** Ortalama değer ile ortalama değişim oranını karıştırmayın.

**Soru:** Bir öğrenci, ilk örnekte verilen $2x+1$ ifadesinin hangi formülde kullanılacağını sordu.
**Cevap:** Hoca, sorunun ortalama değeri istediğini, bu yüzden ortalama değer formülünü (integralli formül) uygulamanın yeterli olduğunu söyledi. Soru "integraller için ortalama değer teoremi"ni (mean value theorem for integrals) sorsaydı, $f(c) = f_{\text{ort}}$ eşitliğini sağlayan özel bir $c$ değeri aranırdı.

**İntegraller için ortalama değer teoremi**

- $f$, $[a,b]$'de sürekli ise $f(c) = \dfrac{1}{b-a}\displaystyle\int_a^b f(x)\,dx$ olacak şekilde en az bir $c \in [a,b]$ vardır.

## 5. Belirli İntegralle Tanımlı Fonksiyonlar Üzerine Diğer Sorular

Hoca bu kısımda birkaç soruyu daha hızlıca geçti. Kalem olmadığı için çözümler ekranda tam yazılamadı.

<!-- BELİRSİZ: 00:31:20-00:36:47 arasındaki soruların metni altyazıda okunmuyor. Aşağıdakiler yalnız sözlü kısımdan çıkarılabilenlerdir. -->

- Bir soruda alt sınırı $1$ olan bir integralle tanımlı fonksiyonun türevinin $1$'deki değeri hesaplandı. Hoca, alt sınır sabit olduğu için türevde o terimin yazılmasına gerek olmadığını söyledi (sabitin türevi sıfır). Fonksiyonun $1$'deki değeri için de $\int_1^1 = 0$ özelliği kullanıldı.
- Hoca bu tip soruları görmenizin çok büyük ihtimal olduğunu söyledi. "Anlamışsanız takır takır yaparsınız."
- Bu yılın mazeret sınavından bir soruda $f'$ yine belirli integralle elde ediliyordu; ifadede "$x^2 + 2x$" geçiyor. Hoca, integrant fonksiyonun üst sınırın türeviyle çarpıldığını, alt sınır $2$ sabit olduğundan türevinin $0$ olduğunu ve türevin $1$'deki değerinin $1$ çıktığını söyledi. İkinci türev için yine doğal logaritma uygulandı.
- Bir başka soruda $g(x)$, alt sınırı $x$, üst sınırı $f(x)$ olan ve integrantında $\cos^2$ geçen bir integralle tanımlanmıştı ($x > 0$). Hoca bu sorunun daha önce derste çözüldüğünü hatırladı ve geçti.

## 6. Grafik Çizimi: $y = \dfrac{x}{x^2-1}$

### 6.1 Örnek 8: Grafik çizim adımları

Hoca grafik çizimini her zamanki adımlarla yaptı.

**Adım 1: Tanım kümesi.** Kuralın anlamlı olduğu bütün $x$ girdilerinin kümesi bulunur. Payda $x^2 - 1 = 0$ olduğunda $x = \pm 1$'dir. Tanım kümesi $\mathbb{R}\setminus\{-1, 1\}$'dir.

**Adım 2: Düşey asimptotlar.** $x = \pm1$'de pay sıfırdan farklı, payda sıfırdır ("$1$ bölü $0$" durumu). Bu yüzden $x = -1$ ve $x = 1$ doğruları düşey asimptottur. Tek taraflı limitler (ara adım eklendi):

| Limit | Değer |
|---|---|
| $x \to -1^-$ | $-\infty$ |
| $x \to -1^+$ | $+\infty$ |
| $x \to 1^-$ | $-\infty$ |
| $x \to 1^+$ | $+\infty$ |

**Adım 3: Yatay asimptot.** $x \to \pm\infty$ iken $y \to 0$. Bu yüzden $y = 0$ doğrusu yatay asimptottur. Hoca kuralı hatırlattı: yatay asimptot varsa eğik asimptot (slant asymptote) yoktur.

**Adım 4: Birinci türev ve kritik noktalar.** Bölüm kuralıyla:
$$y' = \frac{(x^2-1)\cdot 1 - x\cdot 2x}{(x^2-1)^2} = -\frac{x^2+1}{(x^2-1)^2}$$

- $y' = 0$ yapan hiçbir $x$ yoktur (pay hiç sıfır olmaz).
- $x = \pm 1$ türevi tanımsız yapar, ama bu noktalar tanım kümesinde değildir.
- Bu yüzden kritik nokta yoktur, yerel uç değer de yoktur.
- Pay her zaman negatif, payda pozitiftir. Fonksiyon her yerde azalandır.

**Adım 5: İkinci türev ve bükülme noktaları.** Birinci türev ve bölüm kuralıyla:
$$y'' = \frac{2x(x^2+3)}{(x^2-1)^3} = \frac{2x^3+6x}{(x^2-1)^3}$$

- $x = \pm 1$ ikinci türevi tanımsız yapar, ama tanım kümesinde olmadıkları için bükülme noktası olamazlar.
- $x = 0$'da $y'' = 0$'dır. Bu yalnız gerekli koşuldur. Bükülme noktası olup olmadığına karar vermek için içbükeylik durumuna bakılır.

**Adım 6: İşaret tablosu.** $y''$'nün işareti pay $2x^3 + 6x$ ve payda $(x^2-1)^3$ çarpanlarından incelenir. Hoca işaretleri soldan sağa "$-, +, -, +$" sırasıyla okudu.

| Aralık | $y'$ | $y''$ | Grafik |
|---|---|---|---|
| $(-\infty, -1)$ | $-$ | $-$ | azalan, aşağı içbükey (concave down) |
| $(-1, 0)$ | $-$ | $+$ | azalan, yukarı içbükey (concave up) |
| $(0, 1)$ | $-$ | $-$ | azalan, aşağı içbükey |
| $(1, \infty)$ | $-$ | $+$ | azalan, yukarı içbükey |

<!-- BELİRSİZ: Altyazıda hocanın işaret sırası "plus minus plus minus" diye geçiyor; aralık yorumları ise "-, +, -, +" sırasıyla uyumlu. Tablo aralık yorumlarına ve sympy kontrolüne göre yazıldı. -->

$y''$, $x = 0$'da işaret değiştirir ve $0$ tanım kümesindedir. Bu yüzden $(0, 0)$ bükülme noktasıdır.

**Adım 7: Asimptotlarla yorum.** Hoca cebirsel sonuçların grafikte nasıl göründüğünü açıkladı:

- $x \to -1^-$ iken $f(x)$ aşağı doğru sonsuza gider. Bu yüzden $-1$'in solunda grafik aşağı içbükey olmalıdır; aksi hâlde $x = -1$ doğrusu düşey asimptot olamaz.
- $x \to -1^+$ iken $f(x)$ yukarı doğru sonsuza gider. Bu yüzden $-1$'in sağında grafik yukarı içbükey olmalıdır.
- Aynı mantık $x = 1$ için de geçerlidir: solunda aşağı içbükey, sağında yukarı içbükey.
- $y = 0$ doğrusu yatay asimptottur.

Hoca bunu "yukarıda elde edilen cebirsel hesapların grafik cinsinden yorumu" olarak özetledi. Ardından 15 dakika ara verildi.

## 7. Asimptot ve İçbükeylik İlişkisi: Grafik Yorumu

Aradan sonra hoca notlardaki bir başka grafiği yorumladı. Bu grafikte $y = 1$ yatay asimptottur ve bir bükülme noktası vardır.

<!-- BELİRSİZ: Grafiğin kendisi ve aralık sınırları altyazıda tam okunmuyor (01:04:10-01:05:30). -->

- Bükülme noktasından sıfıra doğru grafik yukarı içbükeydir. Bu, ikinci türevin o bölgede pozitif olduğu anlamına gelir.
- $-\infty$'dan bükülme noktasına kadar grafik aşağı içbükey olmalıdır; aksi hâlde bu doğru yatay asimptot olamaz. Aşağı içbükey, ikinci türevin negatif olduğu anlamına gelir.
- Hoca, bu işaret tablosunu kullanarak grafiğin kurulabileceğini söyledi ve diğer grafiği benzer şekilde yorumlamayı öğrencilere bıraktı.

## 8. Final Konusu Olan Sorular: Kısmi İntegrasyon ve İndirgeme Formülü

Hoca uygulama 5 dosyasını açıp kalan sorulara göz attı. Kısmi integrasyon (integration by parts), tablo yöntemi (tabular method) ve indirgeme formülü (reduction formula) içeren soruların **final** konusu olduğunu, 2. vize konusu olmadığını birkaç kez tekrarladı.

> **Hocanın vurgusu:** Bu tip bir sorunun 2. vizede gelme olasılığı hocaya göre yaklaşık %5; %5'ten fazla olacağını düşünmüyor.

- Bir soru kısmi integrasyonla ya da bir yazılım aracıyla çözülebilir. Hoca tablo yöntemini kısmi integrasyonun sadeleştirilmiş hâli olarak tanıttı: bir türev sütunu ve bir integral sütunu kurulur.
- **İndirgeme formülü:** Hoca $I_n$ ile gösterilen bir integral için indirgeme formülünün kısmi integrasyonla nasıl elde edildiğini gösterdi.

<!-- BELİRSİZ: İntegralin tam yazımı altyazıda net değil; "ln x to power n" ifadesinden I_n = ∫ (ln x)^n dx olduğu anlaşılıyor. -->

$I_n = \displaystyle\int (\ln x)^n\,dx$ için $u = (\ln x)^n$, $dv = dx$ seçilir. İki tarafın türevi alınarak diferansiyel ilişki bulunur: $du = n(\ln x)^{n-1}\cdot\dfrac1x\,dx$, $v = x$. Kısmi integrasyon formülü $\int u\,dv = uv - \int v\,du$ uygulanırsa (ara adım eklendi):
$$I_n = x(\ln x)^n - n\int(\ln x)^{n-1}\,dx = x(\ln x)^n - n\,I_{n-1}$$

Hoca, test sınavının ruhuna uygun soru aradığını, bu dosyada pek bulamadığını, çoğunun final sorusu olduğunu söyledi ve bunları geçti.

## 9. Geçen Yılın Mazeret Sınavı Soruları

Hoca daha sonra geçen yılın mazeret sınavının (test) sorularını paylaştı. Kalemi iyi yazmadığı için fareyle yazmaya çalıştı ve öğrencilerden soruları kendilerinin çözmesini istedi.

### 9.1 Örnek 9: Zincir kuralı

Soru: $f$ ve $h$ türevlenebilir fonksiyonlar, $h(0) = 1$, $h'(0) = -1$, $f'(1) = -1$ veriliyor. $k(x) = f\big(h(\ln x)\big)$ ise $k'(1) = ?$

- Zincir kuralı ile (her katmanın türevi, argümanında hesaplanıp çarpılır):
  $$k'(x) = f'\big(h(\ln x)\big)\cdot h'(\ln x)\cdot\frac1x$$
- $x = 1$ yazılır. $\ln 1 = 0$ ve $h(0) = 1$ olduğundan:
  $$k'(1) = f'(1)\cdot h'(0)\cdot\frac11 = (-1)(-1)(1) = 1$$

Cevap $1$'dir (şık A).

### 9.2 Örnek 10: Parçalı fonksiyonun sürekliliği

Soru: $f(x) = \begin{cases} \dfrac{2\arcsin x}{\pi}, & x \le 1 \\[2mm] \dfrac{\ln x + 1}{\arccos x - 1}, & x > 1 \end{cases}$ fonksiyonu için hangi ifade doğrudur?

<!-- BELİRSİZ: x > 1 parçasının tam yazımı altyazıda okunmuyor; ifade kısa nottan alındı. -->

İncelenen ifade: "$f$, $1$ noktasında süreklidir."

- **Soldan limit:** $x \to 1^-$ iken $\arcsin x \to \tfrac{\pi}{2}$. Limit $\dfrac{2\cdot\pi/2}{\pi} = 1$.
- **Sağdan limit:** $x > 1$ kuralı kullanılır. Hoca $\ln 1 = 0$ ve $\arccos 1 = 0$ alarak $\dfrac{0+1}{0-1} = -1$ buldu.
- Sağdan ve soldan limit farklıdır. Bu yüzden $f$, $1$'de sürekli değildir.

> **Ders sonrası not:** $\arccos x$ yalnız $[-1,1]$ aralığında tanımlıdır; $x > 1$ için $\arccos x$ reel sayı değildir. Bu yüzden ekrandaki ifade büyük olasılıkla $\arccos(x-1)$ gibi farklı bir yazımdır. O okumada sağdan limit $\dfrac{1}{\pi/2} = \dfrac{2}{\pi}$ olur. Her iki okumada da sağ ve sol limit farklıdır, $f$ $1$'de sürekli değildir; sonuç değişmez.

Aynı sorunun diğer şıklarında mutlak değerli bir ifadenin türevi ve $x \to 2^+$ iken $\ln$ argümanında $\frac00$ belirsizliği olan bir limit geçiyordu. Hoca mutlak değerli ifadeyi parçalı fonksiyon olarak yazmayı hatırlattı: argüman sıfıra eşit ya da pozitifken argüman aynen, negatifken eksi işaretlisi alınır. Limit için logaritma özelliklerini kullanıp $\ln$'in argümanına L'Hôpital uygulanacağını söyledi ve cevabın D olduğunu belirtti. "$\ln$'i yazmayı unutmayın" uyarısını yaptı.

<!-- BELİRSİZ: Mutlak değerli fonksiyon ve x → 2⁺ limitinin tam ifadesi altyazıda okunmuyor (01:17:15-01:19:30). -->

### 9.3 Örnek 11: $f(x) = \ln(1-x^2)$

Hoca bu soruyu "çok güzel bir soru" olarak niteledi ve bir sonraki vizede bu tip soru görülebileceğini söyledi.

- A şıkkı: "$f$'nin $x = 0$'da yerel maksimum değeri vardır."
- Yerel uç değerler için türev hesaplanır:
  $$f'(x) = \frac{-2x}{1-x^2}$$
- Türev fonksiyonunun işaret tablosu incelenir. Tanım kümesi $(-1,1)$'dir; bu aralıkta payda pozitiftir. $x < 0$ için $f' > 0$, $x > 0$ için $f' < 0$ (ara adım eklendi). Bu yüzden $x = 0$'da yerel maksimum vardır ve değeri $f(0) = \ln 1 = 0$'dır.
- Bir başka şık, ikinci türevin tanım kümesinde pozitif olduğunu, yani grafiğin yukarı içbükey olduğunu söylüyor.

<!-- BELİRSİZ: Sorunun hangi şıkkı istediği ve hocanın vardığı cevap altyazıda anlaşılmıyor (01:20:41-01:21:11). -->

> **Ders sonrası not:** $f''(x) = -\dfrac{2(1+x^2)}{(1-x^2)^2}$ tanım kümesinin her yerinde negatiftir (sympy ile doğrulandı). Yani $f$'nin grafiği aşağı içbükeydir; "ikinci türev pozitiftir, grafik yukarı içbükeydir" ifadesi yanlıştır.

Hoca ayrıca bir limit sorusunun eşlenik (conjugate) yöntemiyle ya da logaritmik türevle çözülebileceğini söyledi; bu tarz soruların 1. vizede zaten olduğunu belirtti.

### 9.4 Örnek 12: Uç değerler ($x \neq 2$)

Soru: $x \neq 2$ olmak üzere verilen bir fonksiyonun uç değerlerinden hangileri doğrudur?

<!-- BELİRSİZ: Fonksiyonun kuralı altyazıda geçmiyor. -->

- Önce birinci türev hesaplanır, yerel uç noktalar bulunur.
- Sonra bu noktalarda $f$'nin değeri hesaplanır.
- Hoca cevabın A olduğunu söyledi; kalemi olmadığı için işlemi öğrencilere bıraktı.

Hoca, zincir kuralı, L'Hôpital kuralı ve doğrusal yaklaşım (linear approximation) sorularının 1. vize konusu olduğunu, konuları hatırlamak için çözülmesini söyledi.

### 9.5 Örnek 13: Kirişe paralel teğet (Soru 19)

Soru: $y = x^2 - 8x$ eğrisi veriliyor. Eğrinin hangi noktasındaki teğet, apsisleri $x = 1$ ve $x = 10$ olan iki noktayı birleştiren kirişe paraleldir?

Şıklar: A) $(7,-7)$, B) $(4,-16)$, C) $(3,-15)$, D) $(5,-15)$, E) $(6,-12)$.

<!-- BELİRSİZ: Şıklar altyazıda geçmiyor; kısa nottan alındı. -->

Hoca önce öğrencilere bu sorunun neyi hatırlattığını sordu. Cevap: türevler için ortalama değer teoreminin (mean value theorem for derivatives) geometrik yorumu.

**Türevler için ortalama değer teoremi (geometrik yorum)**

- $f$, $[a,b]$'de sürekli ve $(a,b)$'de türevlenebilir ise $f'(c) = \dfrac{f(b)-f(a)}{b-a}$ olacak şekilde bir $c \in (a,b)$ vardır.
- Geometrik olarak: $(a, f(a))$ ile $(b, f(b))$ noktalarını birleştiren kirişe paralel bir teğet vardır. Değme noktası $(c, f(c))$'dir.

Hoca fareyle kaba bir grafik çizdi: grafik üzerinde $x = 1$ ve $x = 10$ noktaları, bunları birleştiren kiriş ve kirişe paralel teğetin değdiği $c$ noktası. Gerçek grafiğin bir parabol olduğunu, çizdiğinin yalnız fikir verdiğini belirtti. Ardından eşitliği kurdu:
$$f'(c) = \frac{f(10) - f(1)}{10 - 1}$$

Hoca, bu eşitlik çözülürse $c = 5$, $f(c) = -15$ çıktığını ve cevabın D olduğunu söyledi.

**Soru:** Bir öğrenci, kiriş eğiminin $\tfrac{27}{9} = 3$ çıktığını ve türevi $3$'e eşit olan noktanın $x = \tfrac{11}{2}$ olduğunu söyledi.
**Cevap:** Hoca, o zaman anahtarın yanlış olabileceğini söyledi. Elindeki dosyanın sınavın son hâli değil taslak hâli olduğunu, son anda düzeltmeler yapılmış olabileceğini belirtti. Önemli olanın mantığı anlamak olduğunu, hatasız işlem yapılırsa doğru cevabın bulunacağını ekledi.

Doğru hesap:

- $f(1) = 1 - 8 = -7$, $f(10) = 100 - 80 = 20$.
- Kiriş eğimi: $\dfrac{20-(-7)}{9} = \dfrac{27}{9} = 3$.
- $f'(c) = 2c - 8 = 3 \Rightarrow c = \dfrac{11}{2}$.
- $f\!\left(\tfrac{11}{2}\right) = \dfrac{121}{4} - 44 = -\dfrac{55}{4}$.

> **Ders sonrası not:** Öğrencinin bulduğu $c = \tfrac{11}{2}$ doğrudur; değme noktası $\left(\tfrac{11}{2}, -\tfrac{55}{4}\right)$'tür ve şıklarda yoktur. Anahtardaki D şıkkı $(5,-15)$, ikinci nokta $x = 9$ olsaydı doğru olurdu: $f(9) = 9$, eğim $\tfrac{16}{8} = 2$, $2c - 8 = 2 \Rightarrow c = 5$, $f(5) = -15$ (sympy ile doğrulandı). Soru metninde büyük olasılıkla yazım hatası vardır.

### 9.6 Örnek 14: $g'$ grafiğinden yanlış ifadeyi bulma

Soru: Türevlenebilir bir $g$ fonksiyonunun türevinin ($g'$) grafiği veriliyor. Hoca dikkat çekti: bu $g$'nin değil, $g'$'nün grafiğidir. Yanlış olan ifade aranıyor.

<!-- BELİRSİZ: Grafik ve şıkların tam sırası altyazıda yok; aşağıdaki aralıklar hocanın sözlü anlatımından alındı. -->

- **"$(-\infty, -3)$'te $g$ artandır":** Bu aralıkta $g' > 0$'dır. Bu yüzden ifade doğrudur; aranan şık değildir.
- **"$(2, 5)$'te ..."**: Bu aralıkta $g' < 0$'dır, yani $g$ azalandır. Hoca bu şıkkın da cevap olmadığını söyledi.
- **"$g$'nin grafiğinin $(-5, 0)$ aralığında bükülme noktası vardır":** Bükülme noktası olması için ikinci türevin işaret değiştirmesi, yani türev fonksiyonunun artandan azalana (ya da tersine) geçmesi gerekir. Hoca bu aralıkta böyle bir durum olup olmadığına bakmayı öğrencilere bıraktı.
- **"$g$'nin $x = 5$'te yerel minimumu vardır":** $5$'in solunda $g' < 0$, yani $g$ azalandır. $5$'in sağında $g' > 0$, yani $g$ artandır. Birinci türev testine göre $x = 5$'te yerel minimum vardır. İfade doğrudur.
- **"$x = 2$ bükülme noktası değildir":** $0$'dan $2$'ye türev fonksiyonu artandır. Türev fonksiyonunun türevi olan ikinci türev $2$'nin solunda pozitiftir. $2$'den $4$'e türev fonksiyonu azalandır, ikinci türev $2$'nin sağında negatiftir. İkinci türev $2$'de işaret değiştirdiği için $x = 2$ bükülme (büküm) noktasıdır. Bu yüzden ifade yanlıştır.

Cevap E'dir.

**Soru:** Bir öğrenci, D şıkkının (yerel minimum) neden doğru olduğunu tekrar açıklamasını istedi.
**Cevap:** Hoca açıklamayı tekrarladı: $5$'in sağında $g'$ pozitif olduğu için $g$ artan, solunda $g'$ negatif olduğu için $g$ azalandır. Birinci türev testine göre $x = 5$ yerel minimum noktasıdır.

> **Hocanın vurgusu:** Bu tip sorular bir sonraki vizede çıkabilir. Bükülme noktası ve içbükeylik tanımlarının yorumunu iyi geliştirin. 2. vize ağırlıklı olarak 1. vizeden sonraki konulardan gelir.

## 10. Geçen Yılın 1. Vizesinden İçbükeylik Sorusu

Hoca son olarak geçen yılın 1. vizesinden, o zaman 1. vize konusu olmadığı için çözülmeyen bir soruyu gösterdi. Bu soru 2. vize konusudur.

### 10.1 Örnek 15: Türev grafiğinden içbükeylik ve monotonluk

Soru: Tüm reel sayılarda tanımlı bir $f$ fonksiyonunun türevinin grafiği veriliyor. Aşağıdakilerden hangisi yanlıştır?

- A) $f$'nin grafiği verilen bir aralıkta yukarı içbükeydir.
- B) $f$'nin grafiği verilen bir başka aralıkta yukarı içbükeydir.
- C) $f$ verilen bir aralıkta aşağı içbükeydir.
- D) $f$ verilen bir aralıkta azalandır.
- E) $f$'nin $x = 1$'de yerel uç değeri yoktur.

<!-- BELİRSİZ: Şıklardaki aralıklar altyazıda okunmuyor; yalnız D şıkkının aralığının (-1, 1) olduğu hocanın açıklamasından anlaşılıyor. -->

Hoca cevabın D olduğunu söyledi ve öğrencilerden bunu kafalarında doğrulamalarını, bütün şıkları incelemelerini istedi.

Hocanın D için açıklaması:

- $(-1, 1)$ aralığında $f'$ azalandır.
- Ancak türev fonksiyonu bu aralıkta pozitiftir, çünkü türevin grafiği $x$ ekseninin üstündedir.
- $f' > 0$ olduğundan $f$ bu aralıkta artandır. "$f$ azalandır" diyen D şıkkı yanlıştır.

> **Ek bilgi (derste anlatılmadı):** Bu soruda sık yapılan hata, "$f'$ azalan" bilgisini "$f$ azalan" diye okumaktır. $f$'nin artan ya da azalan olması $f'$'nün **işaretine**, $f$'nin içbükeyliği ise $f'$'nün **artan ya da azalan** olmasına bakılarak belirlenir.

## Örnek Sorular

Bu bölümde derste öğrencilere çözmeleri için verilen ya da sözlü sorulan sorular toplanmıştır. Video ve kare olmadığı için yalnız altyazıdan çıkarılabilen sorular alınmıştır.

**Soru 1** (derste sözlü, 00:07:07): $x \ge 1$ için $f(x) = \displaystyle\int_1^x (2t)^t\,dt$ ise $f''(1)$ kaçtır?

> **Çözüm (derste verildi):** $f'(x) = (2x)^x$. $\ln f'(x) = x\ln(2x)$ türetilirse $f''(x) = (2x)^x[\ln(2x)+1]$. $f''(1) = 2(\ln 2 + 1)$. Ayrıntı için Örnek 3.

**Soru 2** (derste sözlü, 00:17:34): $f'(x) = (x^2+9)^{\sin x}$ olacak şekilde belirli integralle tanımlı fonksiyonun ikinci türevinin $0$'daki değeri kaçtır? (2016 sınavı)

<!-- BELİRSİZ: Soru metnindeki integralin tam yazımı altyazıda yok; f'(x) çözüm adımlarından çıkarıldı. -->

> **Çözüm (derste verildi):** $\dfrac{f''}{f'} = \cos x\ln(x^2+9) + \sin x\dfrac{2x}{x^2+9}$, $f'(0) = 1$. $f''(0) = \ln 9 = 2\ln 3$. Ayrıntı için Örnek 5.

**Soru 3** (derste sözlü, 01:12:17): $h(0) = 1$, $h'(0) = -1$, $f'(1) = -1$ ve $k(x) = f(h(\ln x))$ ise $k'(1)$ kaçtır?

> **Çözüm (derste verildi):** $k'(1) = f'(h(0))\cdot h'(0)\cdot 1 = (-1)(-1) = 1$. Ayrıntı için Örnek 9.

**Soru 4** (derste sözlü, 01:24:39): $y = x^2 - 8x$ eğrisinin hangi noktasındaki teğet, apsisleri $x = 1$ ve $x = 10$ olan noktaları birleştiren kirişe paraleldir? Bu soru hangi teoremin geometrik yorumudur?

> **Çözüm (derste verildi, düzeltilmiş):** Türevler için ortalama değer teoreminin geometrik yorumu. Kiriş eğimi $3$, $2c - 8 = 3 \Rightarrow c = \tfrac{11}{2}$, nokta $\left(\tfrac{11}{2}, -\tfrac{55}{4}\right)$. Hocanın verdiği $(5,-15)$ anahtar hatasıdır. Ayrıntı için Örnek 13.

**Soru 5** (derste sözlü, 01:31:08): $g'$ grafiği verilen bir $g$ için yanlış ifade hangisidir? ("$x = 2$ bükülme noktası değildir" ifadesinin incelenmesi)

> **Çözüm (derste verildi):** $g'$, $2$'nin solunda artan, sağında azalandır; $g''$ $2$'de işaret değiştirir, $x = 2$ bükülme noktasıdır. Yanlış ifade E. Ayrıntı için Örnek 14.

**Soru 6** (derste sözlü, 01:40:38): Türev grafiği verilen $f$ için yanlış ifadenin D ("$f$, $(-1,1)$'de azalandır") olduğunu doğrulayın.

> **Çözüm (derste verildi):** $(-1,1)$'de $f'$ azalan ama pozitif; bu yüzden $f$ artandır, D yanlıştır. Ayrıntı için Örnek 15.

## Dersin Toparlaması

Bu derste 2. vizeye hazırlık için soru çözüldü. İlk kısımda kalkülüsün temel teoreminin 1. kısmı ile belirli integralle tanımlı fonksiyonların türevi alındı. Bu teknik bir limit sorusunda L'Hôpital kuralıyla, üstel-üstel türevlerde logaritmik türevle birlikte kullanıldı. Ardından $x^3$ fonksiyonunun $[0,1]$ altındaki alanı Riemann toplamıyla $\tfrac14$ bulundu ve alt-üst toplam farkı tartışıldı. Ortalama değer ile ortalama değişim oranının farkı vurgulandı. $y = \dfrac{x}{x^2-1}$ grafiği tanım kümesi, asimptotlar, birinci ve ikinci türev işaret tablosuyla çizildi; asimptotlar ile içbükeylik arasındaki zorunlu ilişki açıklandı.

İkinci kısımda geçen yılın mazeret sınavından zincir kuralı, süreklilik, yerel uç değer, türevler için ortalama değer teoremi ve türev grafiğinden yorum soruları çözüldü. Kısmi integrasyon, tablo yöntemi ve indirgeme formülünün final konusu olduğu belirtildi. Hoca bir sonraki derste de 2. vize için soru çözeceğini, henüz görülmeyen soru tiplerini göstereceğini ve 12. haftanın konusunu bitirirse biraz da konu işleyeceğini söyledi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
