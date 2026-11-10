# Ders 17 Genişletilmiş Notu: Konkavlık, Büküm Noktası, Eğik Asimptot, Belirsiz İntegral ve Yerine Koyma Yöntemi

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Derse Giriş
- 2. Konkavlık: Yukarı ve Aşağı Bükümlü Grafik
- 3. Konkavlık Örnekleri: $y=x^2$ ve $y=x^3$
- 4. Büküm Noktası
- 5. Eğik Asimptot
- 6. Ters Türev ve Belirsiz İntegral
- 7. Belirsiz İntegralin Parça-Bütün Felsefesi
- 8. Temel Ters Türev Formülleri ve Özellikler
- 9. Diferansiyel Bağıntılar
- 10. Yerine Koyma (Değişken Dönüşümü) Yöntemi
- 11. Yerine Koyma Örnekleri
- Örnek Sorular

## 1. Derse Giriş

Bu ders, birinci vizeden sonraki ilk derstir. Ders İngilizce anlatıldı, arada Türkçe açıklamalar yapıldı. Hoca tablete yazarak anlattı. Altyazıda yalnız sözlü kısım olduğu için formüller hocanın sözlü anlatımından kuruldu.

Hoca derse, bir önceki derslerde Rolle teoremi (Rolle's theorem) ve ortalama değer teoremi (mean value theorem) konularını gördüklerini hatırlatarak başladı. Bu derste önce konkavlık (concavity), büküm noktası (inflection point) ve eğik asimptot (slant asymptote) anlatıldı. Aradan sonra yeni bir konuya, integrale (integration) geçildi. Hoca integrali ters türev (antiderivative) ve belirsiz integral (indefinite integral) kavramlarıyla başlattı, ardından yerine koyma yöntemini (substitution method) birçok örnekle çalıştı.

## 2. Konkavlık: Yukarı ve Aşağı Bükümlü Grafik

### 2.1 Tanımın Çerçevesi

Hoca tanımı şöyle kurdu: $f$, bir açık $I$ aralığında ikinci mertebeden türevlenebilir (second order differentiable) bir fonksiyon olsun. Konkavlık bu ikinci türev üzerinden tanımlanır.

**Tanım (yukarı bükümlü, concave up / convex):**

- $f$, $I$ üzerinde yukarı bükümlüdür $\iff$ her $x\in I$ için $f''(x)>0$.
- Bunun diğer adı konvekstir (convex).
- Hoca Türkçede "yukarı bükümlü" terimini tercih ettiğini söyledi. Bazı kaynaklar "yukarı konkav" diye çeviriyor.

**Tanım (aşağı bükümlü, concave down):**

- $f$, $I$ üzerinde aşağı bükümlüdür $\iff$ her $x\in I$ için $f''(x)<0$.
- Bazı kaynaklar buna kısaca "concave" der. Hoca "concave down" demeyi tercih ediyor.

Hoca, tanım vermek için genellikle mantıksal ifadeler (logical statements) kullandığımızı vurguladı.

### 2.2 Yukarı Bükümlünün Geometrik Anlamı

$f''>0$ ne demektir? İkinci türev, türev fonksiyonunun türevidir. Türev fonksiyonunun türevi pozitifse türev fonksiyonu $f'$ artandır (increasing).

Hoca bunu bir grafik üzerinde gösterdi. Grafiğe iki noktada teğet çizdi. Bu noktaların $x$ eksenindeki izdüşümleri $x_1$ ve $x_2$ olsun, $x_1\le x_2$. Birinci teğetin eğimi $m_1=f'(x_1)$, ikinci teğetin eğimi $m_2=f'(x_2)$ olsun. Yukarı bükümlü bir grafikte

$$x_1\le x_2 \implies m_1=f'(x_1)\le f'(x_2)=m_2$$

olur. Hocanın Türkçe anlatımıyla: $x$ ekseni üzerinde soldan sağa yürürken, ayağınızı bastığınız her noktaya karşılık gelen teğetin eğimi gittikçe artar. Bu, artanlık tanımına göre $f'$'nin $I$ üzerinde artan olması demektir. $f'$ artan olduğundan da türev fonksiyonunun türevi, yani $f''$, $I$ üzerinde pozitiftir.

"Up" adı bu geometrik yorumdan gelir. Yukarı bükümlü bir grafikte **her teğet doğru grafiğin altında kalır.** Hoca bunu şöyle özetledi: teğet doğrular grafiğin altındaysa grafik yukarı bükümlüdür.

### 2.3 Aşağı Bükümlünün Geometrik Anlamı

Aşağı bükümlü durumda teğet doğrular grafiğin **üstünde** kalır. Hoca yine iki teğet çizdi ve teğet noktalarının izdüşümlerini $x_1<x_2$ diye adlandırdı. Bu kez eğimler ters sıradadır:

$$x_1<x_2 \implies m_1=f'(x_1)>f'(x_2)=m_2$$

Bu mantıksal ifade, türev fonksiyonunun $I$ üzerinde azalan (decreasing) olduğunu söyler. Azalanlık tanımına göre bu, ikinci türevin $I$ üzerinde negatif olması demektir. Böylece $f$, $I$ üzerinde aşağı bükümlüdür.

### 2.4 Özet ve Hocanın Uyarısı

Hoca tanımları Türkçe olarak özetledi:

- Türev fonksiyonu azalansa fonksiyonun grafiği aşağı bükümlüdür. Türev fonksiyonunun azalan olması, ikinci türevin negatif olması demektir.
- Türev fonksiyonu bir $I$ aralığında artansa, türev fonksiyonunun türevi (ikinci türev) $I$ üzerinde pozitiftir. Grafik yukarı bükümlüdür, kısaca konvekstir.

Bu sırada hoca bir öğrenciye, önceden bildiklerini bir kenara koymasını söyledi. Ona göre bir şey öğrenmek için önce bildiğinizi unutmanız gerekir. Bu konular lisede çoğu zaman eksik ya da yanlış öğretiliyor ya da zihne yanlış kodlanıyor. Önce işin mantığını kavramak gerekir.

> **Hocanın vurgusu:** Bu konuda mantığa dayalı, özellikle grafik üzerinden yorum soruları gelir. Konkavlığın birinci ve ikinci türevle ilişkisini iyi anlayan, bu sorulardan en az bir ikisini yapabilir.

> **Ders sonrası not:** Hoca yukarı bükümlülüğü "$f''>0$ olması" ile tanımladı. Ders kitaplarının çoğu tanımı "$f'$, $I$ üzerinde artan" biçiminde verir. $f''>0$ bunun için yeterli koşuldur ama gerekli değildir. Örneğin $f(x)=x^4$ her yerde yukarı bükümlüdür (teğetleri grafiğin altında kalır), ama $f''(0)=0$'dır. Aşağı bükümlü için de durum aynıdır.

## 3. Konkavlık Örnekleri: $y=x^2$ ve $y=x^3$

### 3.1 Örnek 1: $y=x^2$

Hoca önce parabolü (parabolic curve) ele aldı.

- **$(-\infty,0)$ aralığı:** Fonksiyon azalandır. Azalan olması, birinci türevin bu aralıkta negatif olması demektir. Aynı zamanda grafik yukarı bükümlüdür, yani ikinci türev bu aralıkta pozitiftir.
- **$(0,\infty)$ aralığı:** Fonksiyon artandır, yani birinci türev pozitiftir. Grafik yine yukarı bükümlüdür, ikinci türev pozitiftir.

Hesapla doğrularsak $f'(x)=2x$ ve $f''(x)=2>0$'dır (ara adım eklendi). Her noktada teğet doğrular grafiğin altında kalır. Bu yüzden grafik bütün reel sayılarda yukarı bükümlüdür.

Bu örneğin asıl dersi şudur: Fonksiyon bir aralıkta azalan, ötekinde artandır, ama iki aralıkta da yukarı bükümlüdür.

> **Hocanın vurgusu:** Konkavlık (yukarı ya da aşağı bükümlülük), fonksiyonun artan ya da azalan olmasından bağımsızdır. Konkavlık ikinci türevle ilgilidir.

### 3.2 Örnek 2: $y=x^3$

Hoca, ikinci türevi hesaplamadan da grafiğe bakarak sonucu görebileceğimizi söyledi: $(0,\infty)$ kısmında grafik yukarı bükümlü, $(-\infty,0)$ kısmında aşağı bükümlüdür. Fonksiyon iki kısımda da artandır.

Hesapla:

$$f'(x)=3x^2,\qquad f''(x)=6x$$

- $(-\infty,0)$ aralığında $f''(x)=6x<0$. Bu aralıkta grafik aşağı bükümlüdür.
- $(0,\infty)$ (pozitif yarı doğru) üzerinde $f''(x)>0$. Bu aralıkta grafik yukarı bükümlüdür, yani konvekstir.

Hoca terimleri bir kez daha eşleştirdi: "concave up" ile "convex" aynı şeydir; "concave down" için yalnızca "concave" de denir.

## 4. Büküm Noktası

### 4.1 Tanım

**Tanım (büküm noktası, inflection point):**

- İkinci türev fonksiyonunun işaret değiştirdiği noktaya büküm noktası denir.
- Hocaya göre bu, bir noktanın büküm noktası olması için yeterli koşuldur.
- Bu noktada konkavlık değişir: yukarı bükümlüden aşağı bükümlüye ya da aşağı bükümlüden yukarı bükümlüye geçilir.

Hoca bunu bir işaret şeması üzerinde gösterdi. Şemanın ikinci türevin işaretini gösterdiğini, birinci türevin değil, özellikle vurguladı. İkinci türevin işaretinin $-$'den $+$'ya geçtiği yerde grafik aşağı bükümlüden yukarı bükümlüye geçer ve o nokta bir büküm noktasıdır.

<!-- BELİRSİZ: 00:29:57-00:30:58 arasında hocanın tahtaya çizdiği işaret şeması ve grafik anlatılıyor; altyazı bu kısımda döngüye giriyor ("bu şekilde" tekrarı). Şemadaki aralıkların tam sırası okunmuyor. -->

### 4.2 Yanlış Tanım ve Karşı Örnek

Hoca, bazı öğretmenlerin ve bazı YouTuber'ların, maalesef bazı öğrencilerin de şu yanlış tanımı kullandığını söyledi:

$$f''(x_0)=0 \implies x_0 \text{ büküm noktasıdır.} \qquad (\text{YANLIŞ})$$

Bu mantıksal ifade yanlıştır. Önce hoca $y=x^3$'e döndü. Bu örnekte $0$ gerçekten bir büküm noktasıdır, çünkü $0$'ın solunda grafik aşağı bükümlü, sağında yukarı bükümlüdür. Ama bunun nedeni $f''(0)=0$ olması değil, konkavlığın değişmesidir.

Yanlış ifadeyi çürütmek için hoca bir karşı örnek (counterexample) verdi: $f(x)=x^4$.

- Birinci türev: $f'(x)=4x^3$.
- İkinci türev: $f''(x)=12x^2$.
- $f''(0)=0$'dır. Yanlış tanıma göre $0$ büküm noktası olmalıydı.
- Ama $f''(x)=12x^2$, $0$'ın hem solunda hem sağında pozitiftir. İşaret değişmez, grafik iki tarafta da yukarı bükümlüdür.
- Bu yüzden $0$, $x^4$ için büküm noktası **değildir.**

> **Hocanın vurgusu:** Bir mantıksal ifade örnek vererek doğrulanamaz, ama örnek vererek çürütülebilir. Hoca bunu "bilimin en temel kanunu" olarak nitelendirdi: örnekle doğrulama olmaz, örnekle çürütme olur.

### 4.3 Örnek 3: Büküm Noktalarını Bulma

Hoca bir fonksiyonun bütün büküm noktalarını hesaplattı. Altyazıda verilenler şunlardır:

- Birinci türev $3x^2-\dots x$ biçiminde, ikinci türevin kökü $x=\dfrac43$.
- Bu bilgilerle uyumlu olan fonksiyon $f(x)=x^3-4x^2$'dir (kısa notta da bu biçim alınmıştır).

<!-- BELİRSİZ: 00:38:02'de fonksiyon "x kare artı 2x" diye geçiyor; tahtadaki fonksiyonun tamamı okunmuyor. Birinci türevdeki katsayı da altyazıda "3x² minus x" diye bozuk. Aşağıdaki çözüm, ikinci türevin kökü 4/3 olacak biçimde f''(x)=6x-8 alınarak yazıldı. Fonksiyonda ek doğrusal terim (ör. +2x) olsa bile f'' değişmez. -->

**Çözüm:**

$$f'(x)=3x^2-8x,\qquad f''(x)=6x-8$$

- $f''(x)=0 \iff x=\dfrac43$.
- $x<\dfrac43$ için $f''(x)<0$: grafik $\left(-\infty,\dfrac43\right)$ aralığında aşağı bükümlüdür.
- $x>\dfrac43$ için $f''(x)>0$: grafik $\left(\dfrac43,\infty\right)$ aralığında yukarı bükümlüdür.
- Konkavlık $x=\dfrac43$ noktasında değiştiği için bu nokta büküm noktasıdır.

Hoca, birinci türevin işaretini inceleyerek artan ve azalan olduğu aralıkları bulmayı öğrencilere bıraktı.

### 4.4 Hocanın Benzetmesi: Bükülen Doğru

Hoca büküm noktasını akılda tutmak için bir benzetme yaptı. Bir doğru alın. Doğru yatay ya da eğimli olabilir, fark etmez. Bir doğru kendi başına ne yukarı ne aşağı bükümlüdür. Doğruyu bir noktasından sabitleyin. Sabitlediğiniz noktanın sağ tarafını yukarı doğru, sol tarafını aşağı doğru bükün.

- Sağ taraf yukarı bükümlü olur.
- Sol taraf aşağı bükümlü olur.
- Sabitlediğiniz nokta büküm noktasıdır.

Aynı şey ters yönde bükerek de yapılabilir. Hoca, terimlere takılmadan arkadaki mantığa bakmayı önerdi.

## 5. Eğik Asimptot

### 5.1 Tanım ve Limit Problemine Dönüştürme

Hoca, daha önce eğik asimptottan (slant asymptote) bahsetmediğini söyleyip konuyu açtı. Grafikte $x$ yeterince büyüdükçe (sonsuza giderken) $y=f(x)$ grafiğinin $y=mx+n$ doğrusuna benzediği bir durum çizdi.

**Tanım (eğik asimptot):** $x\to\infty$ iken $f(x)$, $mx+n$'ye yaklaşıyorsa

$$f(x)\approx mx+n \quad (x\to\infty)$$

$y=mx+n$ doğrusuna $f$'nin sonsuzdaki eğik asimptotu denir.

Hoca bu mantıksal ifadenin (tanımın) cebirsel bir hesaba, yani bir limit problemine nasıl dönüştürüleceğini gösterdi. Yaklaşık eşitliğin iki tarafı $x$'e bölünür:

$$\frac{f(x)}{x}\approx m+\frac{n}{x}\quad (x\to\infty)$$

$x\to\infty$ iken $\dfrac{n}{x}\to0$ olduğundan

$$m=\lim_{x\to\infty}\frac{f(x)}{x}\qquad (\ast)$$

olur. Hoca $m$'yi **$f$'nin sonsuzdaki eğimi** (slope at infinity) diye yorumladı. $f(x)$'i $x$'e bölüp limit almak, sonsuzdaki eğimin var olup olmadığını araştırmaktır.

$m$ varsa sabit terim $n$'nin varlığı araştırılır:

$$n=\lim_{x\to\infty}\big(f(x)-mx\big)\qquad (\ast\ast)$$

$(\ast)$ ve $(\ast\ast)$ limitlerinin ikisi de varsa sonsuzda bir eğik asimptot vardır.

### 5.2 Yatay Asimptot ile İlişki

Fonksiyonun yatay asimptotu (horizontal asymptote) varsa sonsuzdaki eğim $m=0$'dır. Yani yatay asimptot, eğimi sıfır olan özel bir eğik asimptottur. Hoca bu yüzden, yatay asimptot bulunan durumda ayrıca eğik asimptot araştırmaya gerek olmadığını söyledi.

> **Ek bilgi (derste anlatılmadı):** Aynı limitler $x\to-\infty$ için de hesaplanır. Bir fonksiyonun $+\infty$ ve $-\infty$'daki asimptotları farklı olabilir. Bu yüzden "yatay asimptot varsa eğik asimptot aranmaz" kuralı, aynı uç ($+\infty$ ya da $-\infty$) için geçerlidir.

### 5.3 Neden Genel Yöntem?

Rasyonel fonksiyonlarda eğik asimptot polinom bölmesiyle (quotient algorithm for polynomials) kolayca bulunur. Ama üstel (exponential) ve logaritmik (logarithmic) fonksiyonlarda polinom bölmesi yapılamaz. Bu durumlarda yukarıdaki limitli tanım kullanılmalıdır. Hoca, lisede öğrenilen polinom bölmesini değil, hangi fonksiyon gelirse gelsin her zaman kullanılabilecek genel yolu göstermek istediğini söyledi.

### 5.4 Örnek 4: $f(x)=\dfrac{x^2+1}{x+1}$

<!-- BELİRSİZ: 00:50:49'da fonksiyon "x² plus 1 over x minus 1" diye geçiyor; sonraki bütün hesaplar (00:52:07-00:55:39) payda x+1 ile yapılıyor. Not x+1 alınarak yazıldı. -->

**1. adım: Sonsuzdaki eğim.**

$$m=\lim_{x\to\infty}\frac{f(x)}{x}=\lim_{x\to\infty}\frac{x^2+1}{(x+1)\,x}=\lim_{x\to\infty}\frac{x^2+1}{x^2+x}=1$$

Fonksiyonun sonsuzdaki eğimi 1'dir, yani $m=1$. O hâlde sonsuzda $f(x)\approx x+n$ olur. Hoca, bu yaklaşıklık sembolünü eşitliğe çevirmek için ikinci limitin kullanılması gerektiğini söyledi.

**2. adım: Sabit terim.**

$$n=\lim_{x\to\infty}\left(\frac{x^2+1}{x+1}-1\cdot x\right)=\lim_{x\to\infty}\frac{x^2+1-x^2-x}{x+1}=\lim_{x\to\infty}\frac{1-x}{x+1}=-1$$

**Sonuç:** $m=1$, $n=-1$. Sonsuzdaki eğik asimptot

$$y=x-1$$

**İkinci yol: Polinom bölmesi.** Hoca aynı sonucu polinom bölmesiyle de buldu. $x^2+1$, $x+1$'e bölünür:

- $x^2$'yi yok etmek için $x+1$, $x$ ile çarpılır: $x^2+x$. Fark: $(x^2+1)-(x^2+x)=1-x$.
- Kalan $1-x$'in derecesi 1, bölenin derecesi de 1 olduğu için işlem tekrarlanır.
- $-x$'i yok etmek için $x+1$, $-1$ ile çarpılır: $-x-1$. Fark: $(1-x)-(-x-1)=2$.
- Kalanın derecesi 0'dır, bölme biter.

$$x^2+1=(x+1)(x-1)+2 \quad\Longrightarrow\quad \frac{x^2+1}{x+1}=x-1+\frac{2}{x+1}$$

Bölüm $x-1$ eğik asimptotu verir. Sonuç birinci yolla aynıdır.

Hoca, başka bir fonksiyonun eğik asimptotunu araştırmayı ödev olarak verdi (bkz. Örnek Sorular).

Aradan sonra bir öğrenci, bu asimptotun "oblique asymptote" ile aynı şey olup olmadığını sordu.

**Soru:** Bu asimptot, eğik asimptot (oblique asymptote) ile aynı mı? **Cevap:** Hoca "evet" dedi. Slant asymptote ve oblique asymptote aynı kavramın iki adıdır.

## 6. Ters Türev ve Belirsiz İntegral

Aradan sonra hoca yeni konuya, integrale geçti. Konuları bitirip sınav öncesi yine soru çözeceğini, bu yüzden biraz hızlı gideceğini söyledi.

### 6.1 Ters Türev

**Tanım (ters türev, antiderivative):**

- $f$ bir fonksiyon, $F$ de bir tanım kümesi üzerinde türevlenebilir bir fonksiyon olsun.
- $F'=f$ ise $F$'ye $f$'nin bir ters türevi denir.

**Örnek 5.** $f(x)=2x$ olsun.

- $F_1(x)=x^2$, $f$'nin bir ters türevidir, çünkü $(x^2)'=2x$.
- $F_2(x)=x^2+1$ de $f$'nin bir ters türevidir.
- Genel olarak her reel $C$ sabiti için $x^2+C$, $f$'nin bir ters türevidir.

Demek ki bir fonksiyonun sonsuz tane ters türevi vardır.

### 6.2 Belirsiz İntegral

**Tanım (belirsiz integral, indefinite integral):** $f$'nin belirsiz integrali, $f$'nin bütün ters türevlerinin kümesidir.

Hoca önce bunu küme gösterimiyle yazdı, ama bu gösterimin pek iyi olmadığını söyleyip yerine şu standart gösterimi tercih etti:

$$\int f(x)\,dx=F(x)+C,\qquad \text{burada } F'(x)=f(x)$$

> **Hocanın vurgusu:** $C$'yi unutmayın. Belirsiz integral bir kümedir. Bu kümeyi oluşturan şey $C$ sabitidir. $C$ değiştikçe bütün ters türevlerin kümesini belirlemiş olursunuz.

İntegralin parçalarının adları:

- $x$: integral değişkeni (integral variable). Bunu $dx$ gösterir.
- $f(x)$: integrant fonksiyon (integrand).

## 7. Belirsiz İntegralin Parça-Bütün Felsefesi

Hoca belirsiz integralin "felsefesinden" bahsetti. Bu felsefeyi daha sonra diferansiyel bağıntılarda ve yerine koyma yönteminde sık sık kullanacaklarını söyledi.

Bir nesne düşünelim, herhangi bir şey olabilir. Bu nesnenin ölçülebilir bir niceliği (quantity) olsun. Hoca önce kütleyi (mass) örnek verdi, sonra genel konuşmayı tercih etti. Bu ölçülebilir niceliği $u$ ile gösterelim. Kütle, ağırlık, yoğunluk gibi bir şey olabilir.

- **$u$:** Nesnenin bütününe ait nicelik. Bütünü temsil eder.
- **$du$:** Nesnenin yeterince küçük bir parçasına ait nicelik. Aynı zamanda $u$ ekseni boyunca yeterince küçük bir farktır (sufficiently small difference along the $u$-axis). Hoca bunu o parçaya karşılık gelen bir noktanın değeri gibi düşünebileceğimizi söyledi.
- **$\displaystyle\int du$:** Bütün yeterince küçük parçaların toplanması (collection). İntegral sembolü bu "toplama, birleştirme" anlamını taşır.

Parçaları birleştirirsek bütünü elde ederiz:

$$\int du=u+C$$

Gerçekten $u$, $1$'in bir ters türevidir, çünkü $u$'nun $u$'ya göre türevi 1'dir.

**Türev parçalamaktır.** Bütünün diferansiyelini aldığınızda ($u\to du$) bütünü yeterince küçük parçalara ayırmış olursunuz. Hocanın ifadesiyle türev almak, parçalamak demektir.

**İntegral birleştirmektir.** Olayı tersten alırsak, yani ters türev aldığımızda, bütün parçaları toplar ve bütünü elde ederiz.

**$C$ bir öteleme parametresidir.** Hoca $C$'yi bir taşıma, öteleme (translation) parametresi olarak yorumladı. Nesneyi $C$ birim ötelediğinizde, hareket sırasında nesnenin ölçülebilir değeri değişmez. $u+C$'nin diferansiyelini aldığınızda yine $du$ elde edersiniz, çünkü sabitin türevi sıfırdır.

## 8. Temel Ters Türev Formülleri ve Özellikler

### 8.1 Temel Formüller

Hoca her formülü "türevi şu olan bir fonksiyon arıyoruz" diye okudu. Bu yüzden temel türev formüllerini bilmenin çok önemli olduğunu söyledi.

- $\displaystyle\int u^n\,du=\frac{u^{n+1}}{n+1}+C$, $\quad n\ne-1$.
- $\displaystyle\int u^{-1}\,du=\int\frac{du}{u}=\ln|u|+C$.
- $\displaystyle\int\cos u\,du=\sin u+C$.
- $\displaystyle\int\sin u\,du=-\cos u+C$.
- $\displaystyle\int\frac{du}{1+u^2}=\arctan u+C$.
- $\displaystyle\int\frac{-du}{1+u^2}=\operatorname{arccot}u+C$.
- $\displaystyle\int\frac{du}{\sqrt{1-u^2}}=\arcsin u+C$.
- $\displaystyle\int\frac{-du}{\sqrt{1-u^2}}=\arccos u+C$.
- $\displaystyle\int\frac{du}{u\sqrt{u^2-1}}=\operatorname{arcsec}u+C$. Kök sembolünün anlamlı olması için kökün içi pozitif olmalıdır: $u^2-1>0$.
- $\displaystyle\int\frac{-du}{u\sqrt{u^2-1}}=\operatorname{arccsc}u+C$.
- $\displaystyle\int e^u\,du=e^u+C$.
- $\displaystyle\int a^u\,du=\frac{a^u}{\ln a}+C$, $\quad a>0$ ve $a\ne1$.

<!-- BELİRSİZ: 01:39:21-01:40:59 arasında altyazı bozuk. arccot satırı "arctan u plus u" diye, arcsin/arccos satırları "R cosin U plus C", "Minus R cosin U plus C", "Minus R sin U plus C" diye geçiyor. Hoca büyük olasılıkla aynı integrali iki biçimde (ör. arcsin u + C = -arccos u + C) yazdı. Yukarıdaki satırlar standart formüllerdir. -->

> **Ders sonrası not:** Altyazıda $\displaystyle\int\frac{-du}{1+u^2}$ için sonuç "arctan u plus u" diye geçiyor. Doğrusu $\operatorname{arccot}u+C$'dir. Bu, $-\arctan u+C$ ile aynı kümedir, çünkü $\operatorname{arccot}u+\arctan u$ sabittir.

> **Ek bilgi (derste anlatılmadı):** Bazı kaynaklar arcsec formülünü $\displaystyle\int\frac{du}{|u|\sqrt{u^2-1}}=\operatorname{arcsec}|u|+C$ biçiminde verir. Hocanın yazdığı $u\sqrt{u^2-1}$ biçimi $u>1$ için bununla aynıdır.

### 8.2 Belirsiz İntegralin Özellikleri

- **Toplama ve çıkarma:** İntegral sembolü toplama ve çıkarma üzerine dağılır.

$$\int\big(f(x)\pm g(x)\big)\,dx=\int f(x)\,dx\pm\int g(x)\,dx$$

- **Sabitle çarpma:** $c$ sabitse

$$\int c\,f(x)\,dx=c\int f(x)\,dx$$

- **Çarpım üzerine dağılmaz:** Hoca bazı öğrencilerin bu hatayı yaptığını söyledi. Böyle bir kural yoktur:

$$\int f(x)\,g(x)\,dx\ne\int f(x)\,dx\cdot\int g(x)\,dx$$

> **Hocanın vurgusu:** İntegral çarpımın üzerine dağılmaz. Bunlar ters türev ve belirsiz integralle ilgili önemli kurallardır.

## 9. Diferansiyel Bağıntılar

### 9.1 Diferansiyel Nedir?

Hoca "çok önemli" diye bir başlık açtı: diferansiyel bağıntıları (differential relations) ya da denklemlere karşılık gelen diferansiyel ilişkileri hesaplamak.

Önce $x^2$ örneğini verdi. $x^2$'nin diferansiyeli, $x^2$'nin türevi çarpı $dx$'tir:

$$d(x^2)=2x\,dx$$

Genel olarak:

$$dF=F'(x)\,dx$$

### 9.2 Örnek 6: $u=(x^2+10x)^{10}$

<!-- BELİRSİZ: 01:47:32'de denklemin sol tarafı "X2'ye equal to X2 plus 10X2'ye equal to 10" diye bozuk geçiyor. Hoca "U'yu U'ya göre türetelim, DU koyalım" dediği için sol taraf büyük olasılıkla u'dur. Not u = (x²+10x)^10 alınarak yazıldı. -->

Bir denklemin iki tarafının diferansiyeli alınır. Kural şudur: Her taraf kendi değişkenine göre türetilir, sonra o tarafın değişkenine karşılık gelen diferansiyelle çarpılır.

- Sol tarafta $u$ değişkeni var. $u$, $u$'ya göre türetilir ve $du$ yazılır.
- Sağ tarafta $x$ değişkeni var. Sağ taraf $x$'e göre türetilir ve $dx$ ile çarpılır.

$$du=10\,(x^2+10x)^9\,(2x+10)\,dx$$

Hoca önce iç türevi yazmayı unuttu. Bir öğrenci "içinin türevini almadık mı?" diye sordu. Hoca öğrencinin haklı olduğunu söyledi ve $(2x+10)$ çarpanını ekledi.

### 9.3 Örnek 7: $\cos(t^2)+\sin t=x^2+10x$

Burada sol tarafta $t$, sağ tarafta $x$ değişkeni vardır.

- Sol taraf $t$'ye göre türetilir. $\cos(t^2)$'nin türevi $-\sin(t^2)$ çarpı iç türev $2t$'dir. $\sin t$'nin türevi $\cos t$'dir. Sol tarafa $dt$ konur.
- Sağ taraf $x$'e göre türetilir: $2x+10$. Sağ tarafa $dx$ konur.

$$\big(-2t\sin(t^2)+\cos t\big)\,dt=(2x+10)\,dx$$

Hoca bu yöntemin, yani diferansiyel bağıntıyı elde etmenin, değişken dönüşümlerinde çok sık kullanılacağını söyledi. Sınavlarda bu kadar karmaşık dönüşümler gelmeyecek, ama bazen standarttan biraz farklı dönüşümler gelebilir.

### 9.4 Neden $dt$ ve $dx$ Yazıyoruz?

**Soru:** Normalde türev alırken türevden sonra $dt$ ya da $dx$ koymuyorduk. Burada koymamızın sebebi ne? **Cevap:** İntegral alırken $dx$, $du$ gibi parçalarla çalışırız. $u$ bir bütünü gösteriyorsa $du$ onun parçasını gösterir. Diferansiyellerin oranı türevi verir:

$$\frac{dF}{dx}=F'(x)$$

Sol taraf diferansiyellerin oranı, sağ taraf türevdir. Türevin tanımı zaten yeterince küçük farkların oranıydı. Bu farklar bir bütünün parçalarına karşılık gelir. Bütünün parçalarının oranını aldığınızda türevi elde edersiniz. O hâlde bir $F$ bütününün yeterince küçük parçası, $F$'nin türevi ile $F$'nin bağlı olduğu $x$ değişkeninin yeterince küçük parçasının çarpımına eşittir: $dF=F'(x)\,dx$.

Hoca, felsefeyi boşuna anlatmadığını, bu cebirsel işlemlerin arkasında bütün-parça felsefesinin bulunduğunu söyledi.

## 10. Yerine Koyma (Değişken Dönüşümü) Yöntemi

### 10.1 Yöntem

Yerine koyma yönteminin (substitution method) diğer adı integralde değişken dönüşümüdür (change of variable).

**Yerine koyma kuralı:**

$$\int f\big(u(x)\big)\,u'(x)\,dx=\int f(u)\,du$$

Hoca kuralın mantığını şöyle anlattı:

- Sol taraftaki integralde integral değişkeni $x$'tir.
- $u'(x)\,dx$ ifadesi $u$'nun diferansiyelinden başka bir şey değildir. $\dfrac{du}{dx}=u'(x)$ olduğundan $du=u'(x)\,dx$'tir.
- Bu diferansiyel bağıntı sayesinde $x$'e bağlı belirsiz integral problemi, yeni bir belirsiz integral problemine dönüşür: $\displaystyle\int f(u)\,du$. Burada integral değişkeni $u$'dur.
- Böylece problem basitleştirilmiş olur.

### 10.2 Sorulması Gereken Soru

Hoca her örnekte aynı soruyu sordurdu:

> **Hocanın vurgusu:** "Bu problemi basitleştirmek için integrant fonksiyonun hangi parçası $u$ olmalı?" sorusunu kendinize sorun.

Hocaya göre kontrol şudur: İntegrantın bir parçasına $u$ dedikten ve diferansiyel bağıntıyı hesapladıktan sonra, tamamen $x$'e bağlı olan integrali tamamen $u$ cinsinden yazabiliyor musunuz?

- Yazabiliyorsanız yaptığınız değişken dönüşümü anlamlıdır.
- Yazamıyorsanız ya bir yerde işlem hatası yapıyorsunuzdur ya da seçtiğiniz dönüşüm yanlıştır.

Sonucu bulduktan sonra eski değişkene ($x$'e) geri dönmek gerekir.

## 11. Yerine Koyma Örnekleri

### 11.1 Örnek 8: $\displaystyle\int (x^2+x)^{10}(2x+1)\,dx$

Hoca bunun çok basit bir soru olduğunu, ama çok önemli bir kavram içerdiğini söyledi.

**Hangi parça $u$ olmalı?** $u=x^2+x$ denir. Neden? Bu dönüşüme karşılık gelen diferansiyel bağıntı

$$du=(2x+1)\,dx$$

integralin içinde zaten bulunmaktadır. Dolayısıyla $x^2+x$'e $u$ demek bir anlam ifade eder. Hoca, her şeye $u$ demenin anlamlı olmadığını vurguladı: $2x+1$'e $u$ denseydi bu hiçbir anlam ifade etmezdi.

**Dönüşüm:**

$$\int (x^2+x)^{10}(2x+1)\,dx=\int u^{10}\,du=\frac{u^{11}}{11}+C$$

**Eski değişkene dönüş:**

$$=\frac{(x^2+x)^{11}}{11}+C$$

<!-- BELİRSİZ: 01:58:09-01:58:45 arasında altyazı döngüye giriyor ("bu sebeple" tekrarı); hocanın tahtadaki ara adımları okunmuyor. Son satır u^{10} için temel formülle kuruldu (ara adım eklendi). -->

Hoca, sorunun basitliğine ya da zorluğuna değil, buradaki mantığa odaklanılması gerektiğini söyledi.

### 11.2 Örnek 9: $\displaystyle\int\frac{\cos(\sqrt x+1)}{\sqrt x}\,dx$

Türevi $\dfrac{\cos(\sqrt x+1)}{\sqrt x}$ olan bir fonksiyon arıyoruz. Hoca öğrencilere birkaç dakika verip dönüşümü kendilerinin yapmasını istedi.

**Dönüşüm:** $u=\sqrt x+1$. İki tarafın diferansiyeli alınır:

$$\frac{1}{2\sqrt x}\,dx=du \quad\Longrightarrow\quad \frac{dx}{\sqrt x}=2\,du$$

İntegralde $\dfrac{dx}{\sqrt x}$ zaten vardır. Böylece $x$'e bağlı integral tamamen $u$'ya bağlı bir integrale dönüşür:

$$\int\cos u\cdot 2\,du=2\sin u+C=2\sin(\sqrt x+1)+C$$

Hoca bu sırada değişken adının önemli olmadığını, $u$ yerine $t$ ya da istenen başka bir harfin kullanılabileceğini söyledi.

### 11.3 Örnek 10: $\displaystyle\int\frac{\sqrt{\ln x+2}}{x}\,dx$

**Hangi parça $u$ olmalı?** Bir öğrenci "ln kısmı" dedi. Hoca, kök sembolünün argümanının, yani $\ln x+2$'nin $u$ olması gerektiğini söyledi.

**Dönüşüm:** $u=\ln x+2$. İki tarafın diferansiyeli alınır:

$$\frac{1}{x}\,dx=du$$

Bu, integrali $f(u(x))\,u'(x)\,dx$ yapısına getirir. Burada $f(u)=\sqrt u$'dur. Hoca, bu yapıda başta bir sabit katsayının da bulunabileceğini ekledi.

$$\int\sqrt u\,du=\frac{u^{3/2}}{3/2}+C=\frac23u^{3/2}+C$$

Hoca $\dfrac{3}{2}$'ye bölmenin, ters çevirip $\dfrac{2}{3}$ ile çarpmak olduğunu söyledi.

**Eski değişkene dönüş:**

$$=\frac23(\ln x+2)^{3/2}+C$$

### 11.4 Örnek 11: İki Dönüşümlü Örnek

<!-- BELİRSİZ: İntegralin tamamı altyazıda okunmuyor. Hocanın dönüşümlerinden (u = e^x + 1, du = e^x dx, sonra "cos^{3/2} u sin u du") integral aşağıdaki gibi kuruldu. -->

$$\int\cos^{3/2}(e^x+1)\,\sin(e^x+1)\,e^x\,dx$$

Hoca, bu soruları "kafanıza göre" değil, kurallara dikkat ederek yapmanız gerektiğini söyledi.

**1. dönüşüm:** Bir öğrencinin de söylediği gibi $u=e^x+1$ denir. O zaman $du=e^x\,dx$ olur:

$$\int\cos^{3/2}u\,\sin u\,du$$

**2. dönüşüm:** Problemi daha da basitleştirmek için yine "hangi parça yeni değişken olmalı?" diye sorulur. $t=\cos u$ denir:

$$-\sin u\,du=dt \quad\Longrightarrow\quad \sin u\,du=-dt$$

$$\int t^{3/2}\,(-dt)=-\frac{t^{3/2+1}}{3/2+1}+C=-\frac{2}{5}t^{5/2}+C$$

**Eski değişkenlere dönüş:** $t=\cos u$ ve $u=e^x+1$:

$$=-\frac25\cos^{5/2}(e^x+1)+C$$

**Soru:** Neden $\cos u$'ya $t$ dedik, neden $\sin u$ değil? **Cevap:** Hoca öğrenciyle birlikte denedi: $\sin u=a$ deyip diferansiyel bağıntıyı yazınca ($\cos u\,du=da$) problem tamamen $a$ cinsinden kolayca yazılamaz. Öncekinden daha karmaşık terimler çıkar, problem sadeleşmez. Bu yüzden $\cos u=t$ dönüşümü tercih edilir. Hedef her zaman genel yapıyı, yani $f(u(x))\,u'(x)\,dx$ biçimini elde etmektir.

### 11.5 Örnek 12: $\displaystyle\int\tan x\,dx$

Türevi $\tan x$ olan bir fonksiyon arıyoruz. Bir öğrenci "$\tan x=u$" önerdi. Bir başka öğrenci bu tür integrallerin ezberlenmesinin daha uygun olup olmadığını sordu. Hoca ezberlememeyi, önce genel kuralları öğrenmeyi, ezberi ondan sonra yapmayı önerdi. Tanjant ile kotanjant arasında küçük ama önemli farklar olduğu için ezberle işin içinden çıkılamayacağını söyledi.

**Çözüm:** Önce $\tan x$, sinüs ve kosinüs cinsinden yazılır:

$$\int\tan x\,dx=\int\frac{\sin x}{\cos x}\,dx$$

Böyle rasyonel ifadelerde problemi $\dfrac{du}{u}$ biçimine getirmeye çalışırız. $u=\cos x$ denir:

$$du=-\sin x\,dx$$

$\sin x\,dx$ integralin içinde vardır. Bu yüzden dönüşüm yapılabilir:

$$\int\frac{\sin x}{\cos x}\,dx=-\int\frac{du}{u}=-\ln|u|+C=-\ln|\cos x|+C$$

Hoca $\displaystyle\int\cot x\,dx$ integralini ödev olarak bıraktı (bkz. Örnek Sorular).

### 11.6 Örnek 13: $\displaystyle\int\sec x\,dx$

Türevi $\sec x$ olan bir fonksiyon arıyoruz. Hoca, bu biçimde doğrudan yerine koyma yönteminin uygulanamayacağını söyledi. $\sec x=\dfrac{1}{\cos x}$ diye açılsa bile uygun bir değişken dönüşümü yoktur. Önce integrant fonksiyon üzerinde düzenleme yapıp yerine koymanın uygulanabileceği yeni bir probleme dönüştürmek gerekir.

Hoca önce şu türevleri hatırlattı:

$$(\sec x)'=\sec x\tan x,\qquad (\tan x)'=\sec^2x$$

**Genişletme:** $\sec x$, $\sec x+\tan x$ ile çarpılıp bölünür. İfade değişmez:

$$\int\sec x\,dx=\int\frac{\sec x\,(\sec x+\tan x)}{\sec x+\tan x}\,dx=\int\frac{\sec^2x+\sec x\tan x}{\sec x+\tan x}\,dx$$

**Dönüşüm:** Paydaya $u$ denir: $u=\sec x+\tan x$. İki tarafın diferansiyeli alınır:

$$du=(\sec x\tan x+\sec^2x)\,dx$$

Bu tam olarak paydaki ifadedir. Problem $\dfrac{du}{u}$'ya dönüşür:

$$\int\frac{du}{u}=\ln|u|+C=\ln|\sec x+\tan x|+C$$

> **Hocanın vurgusu:** İfadeyi uygun çarpanlarla genişletmek işimizi çok kolaylaştıran bir yöntemdir. Burada $\sec x+\tan x$ ile çarpıp bölmenin amacı, paydaya $u$ dediğimizde $\dfrac{du}{u}$'yu yakalamaktır.

Hoca bir başka öğrencinin daha önce sorduğu soruya ("değişken dönüşümü her zaman uygulanabilir mi?") bu örnekle cevap verdi: Her zaman doğrudan uygulanamaz, bazen önce belli bir düzenleme yapmak gerekir.

### 11.7 Örnek 14: $\displaystyle\int\frac{dx}{2x-3}$

**Dönüşüm:** $u=2x-3$ denir. O zaman $2\,dx=du$, yani $dx=\dfrac12\,du$:

$$\int\frac{dx}{2x-3}=\frac12\int\frac{du}{u}=\frac12\ln|u|+C=\frac12\ln|2x-3|+C$$

### 11.8 Örnek 15: $\displaystyle\int\frac{dx}{\sqrt x\,\big(3-e^{-\sqrt x}\big)}$

Hoca iki yol önerdi: pay ve paydayı $e^{\sqrt x}$ ile çarpmak ya da doğrudan $\sqrt x=u$ dönüşümü yapmak. İşi bilerek biraz uzatıp önce $\sqrt x=u$ dönüşümünü yaptı. Öğrencilere bir süre çözme zamanı verdi.

**1. dönüşüm:** $u=\sqrt x$:

$$\frac{1}{2\sqrt x}\,dx=du \quad\Longrightarrow\quad \frac{dx}{\sqrt x}=2\,du$$

$\dfrac{dx}{\sqrt x}$ integralin içinde vardır:

$$\int\frac{2\,du}{3-e^{-u}}$$

**Genişletme:** Pay ve payda $e^u$ ile çarpılır:

$$\int\frac{2e^u\,du}{3e^u-1}$$

**2. dönüşüm:** $t=e^u$, $dt=e^u\,du$. $e^u\,du$ integralin içinde vardır:

$$2\int\frac{dt}{3t-1}$$

**3. adım:** $a=3t-1$ dönüşümüyle $3\,dt=da$, yani $dt=\dfrac13\,da$ olur. Hoca bu adımı kısa yoldan yaptı:

$$2\int\frac{dt}{3t-1}=\frac23\int\frac{da}{a}=\frac23\ln|a|+C=\frac23\ln|3t-1|+C$$

**Eski değişkenlere dönüş:** $t=e^u$, $u=\sqrt x$:

$$=\frac23\ln\left|3e^{\sqrt x}-1\right|+C$$

Bir öğrenci aradaki katsayıyı sordu (bkz. Örnek Sorular).

> **Ders sonrası not:** Hoca ara adımda bir an "$2\cdot\dfrac12\ln|3t-1|$" yazdı. $\displaystyle\int\frac{dt}{3t-1}=\frac13\ln|3t-1|+C$ olduğundan doğru katsayı $2\cdot\dfrac13=\dfrac23$'tür. Hoca sonucu zaten $\dfrac23$ olarak verdi.

## Örnek Sorular

Bu derste kare kullanılmadı. Aşağıdaki sorular derste sözlü sorulan ya da ödev olarak verilen sorulardır.

**Soru 1** (derste sözlü, 00:55:47). Hoca, aşağıdaki fonksiyonun eğik asimptotunu araştırmayı ödev verdi.

<!-- BELİRSİZ: Fonksiyon altyazıda "x times x minus x" diye geçiyor; tam ifade okunmuyor. Kısa notta bu fonksiyon y = x e^{-x} olarak okunmuş. Aşağıdaki çözüm bu okumaya göredir. -->

> **Çözüm (derste verilmedi):** $f(x)=xe^{-x}$ alınırsa $x\to\infty$ iken $\displaystyle\lim_{x\to\infty}xe^{-x}=0$ olur. Yani $+\infty$'da $y=0$ yatay asimptotu vardır ($m=0$ olan eğik asimptot). $x\to-\infty$ iken $\displaystyle m=\lim_{x\to-\infty}\frac{f(x)}{x}=\lim_{x\to-\infty}e^{-x}=\infty$ olduğundan $-\infty$'da eğik asimptot yoktur.

**Soru 2** (derste sözlü, 01:20:57). Bu asimptot, eğik asimptot (oblique asymptote) ile aynı mı?

- Hocanın cevabı: Evet. Slant ve oblique asymptote aynı kavramdır.

**Soru 3** (derste sözlü, 01:51:04). Normal türevde $dt$ ya da $dx$ yazmıyorduk; diferansiyel bağıntıda neden yazıyoruz?

- Hocanın cevabı Bölüm 9.4'te verildi: Diferansiyellerin oranı türevdir, bu yüzden $dF=F'(x)\,dx$.

**Soru 4** (derste sözlü, 02:03:02). Yerine koyma yöntemini uygulamadan önce sağlanması gereken bir kural ya da koşul var mı? Yöntem her integrale uygulanabilir mi?

- Hocanın cevabı: Hayır, her probleme uygulanamaz. İntegral $\displaystyle\int f(u(x))\,u'(x)\,dx$ yapısındaysa $u'(x)\,dx=du$ olduğu için $\displaystyle\int f(u)\,du$'ya dönüştürülüp basitleştirilebilir. Bu yapı yoksa doğrudan uygulanamaz. Hoca daha sonra $\sec x$ örneğinde, bazen önce genişletme yapılması gerektiğini gösterdi.

**Soru 5** (derste sözlü, 02:14:05). Örnek 11'de neden $\cos u=t$ seçildi, neden $\sin u$ değil?

- Hocanın cevabı Örnek 11'de verildi: $\sin u=a$ dönüşümü daha karmaşık terimler verir, problem sadeleşmez.

**Soru 6** (derste sözlü, 02:18:43). Ödev: $\displaystyle\int\cot x\,dx$ integralini hesaplayın.

> **Çözüm (derste verilmedi):** $\cot x=\dfrac{\cos x}{\sin x}$ yazılır. $u=\sin x$ ise $du=\cos x\,dx$ olur. $\displaystyle\int\frac{du}{u}=\ln|u|+C=\ln|\sin x|+C$.

**Soru 7** (derste sözlü, 02:20:10). $\displaystyle\int\sec x\,dx$ için $u=x$ denemez mi? ($x$'in türevi 1.)

- Hocanın cevabı: $x=u$ dersek aynı ifadeyi yeniden elde ederiz. Hiçbir şey değişmez, problem basitleşmez.

**Soru 8** (derste sözlü, 02:20:43). $\displaystyle\int\sec x\,dx$ için $1=\cos^2x+\sin^2x$ özdeşliğini kullanmak bir şey değiştirir mi?

- Hocanın cevabı: Maalesef hayır. Bu rasyonel ifadeyi uygun çarpanla genişletmek gerekir ($\sec x+\tan x$ ile çarpıp bölmek).

**Soru 9** (derste sözlü, 02:24:00). Aynı yöntem kosekant için de kullanılır mı? Ödev: $\displaystyle\int\csc x\,dx$.

- Hocanın cevabı: Elbette. $(\csc x)'=-\csc x\cot x$ olduğunu hatırlatıp hesabı ödev bıraktı. Formülün nasıl çıkarıldığını anladıktan sonra ezberlemeyi önerdi.

> **Çözüm (derste verilmedi):** Pay ve payda $\csc x+\cot x$ ile çarpılır: $\displaystyle\int\frac{\csc^2x+\csc x\cot x}{\csc x+\cot x}\,dx$. $u=\csc x+\cot x$ ise $du=(-\csc x\cot x-\csc^2x)\,dx$, yani pay $-du$'dur. Sonuç: $\displaystyle-\int\frac{du}{u}=-\ln|\csc x+\cot x|+C$.

**Soru 10** (derste sözlü, 02:31:20). Örnek 15'te bir katsayıyı dışarı aldık; tam bölünmüyor gibi, orada bir hata mı var?

- Hocanın cevabı: Hoca, $\displaystyle\int\frac{dx}{2x-3}$ ile aynı mantığı kullandığını açıkladı. $a=3t-1$ dersek $3\,dt=da$ olur ve integral $\dfrac23\displaystyle\int\frac{da}{a}=\dfrac23\ln|3t-1|+C$'ye dönüşür. Sonuçtaki katsayı $\dfrac23$'tür.

## Dersin Toparlaması

Dersin ilk yarısında türevin uygulamaları tamamlandı. Konkavlık ikinci türevle tanımlandı: $f''>0$ olan aralıkta $f'$ artandır, teğetler grafiğin altında kalır ve grafik yukarı bükümlüdür; $f''<0$ olan aralıkta ise grafik aşağı bükümlüdür. Konkavlığın artanlık ve azalanlıktan bağımsız olduğu $x^2$ ve $x^3$ örnekleriyle görüldü. Büküm noktası, ikinci türevin işaret değiştirdiği nokta olarak tanımlandı. "$f''(x_0)=0$ ise $x_0$ büküm noktasıdır" ifadesinin yanlış olduğu $x^4$ karşı örneğiyle çürütüldü. Ardından eğik asimptot, $m=\lim f(x)/x$ (sonsuzdaki eğim) ve $n=\lim\big(f(x)-mx\big)$ limitleriyle hesaplandı. Yatay asimptotun, eğimi sıfır olan özel bir eğik asimptot olduğu belirtildi.

İkinci yarıda integrale geçildi. Ters türev ve belirsiz integral tanımlandı. Belirsiz integralin bir küme olduğu, bu kümeyi $C$ sabitinin oluşturduğu vurgulandı. Hoca integrali "parçaları toplayıp bütünü elde etmek", türevi ise "bütünü parçalamak" olarak yorumladı. Temel formüller ve özellikler verildi, diferansiyel bağıntılar ($dF=F'(x)\,dx$) çalışıldı. Son olarak yerine koyma yöntemi, "integrantın hangi parçası $u$ olmalı?" sorusu etrafında birçok örnekle uygulandı. Gerektiğinde integrantı uygun bir çarpanla genişletmenin ($\sec x$ ve $3-e^{-\sqrt x}$ örnekleri) yöntemi uygulanabilir kıldığı gösterildi. Hoca integral konusuna bir sonraki derste devam edeceğini söyledi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
