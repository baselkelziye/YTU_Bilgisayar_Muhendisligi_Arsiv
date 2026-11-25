# Ders 16 Genişletilmiş Notu: Limit Teoremleri, İstatistiksel Çıkarım ve Nokta Tahmini

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Bağımsız ve Özdeş Dağılımlı (i.i.d.) Rastgele Değişkenler
- 2. Örneklem Ortalaması, Beklenen Değeri ve Varyansı
- 3. Büyük Sayılar Zayıf Yasası
- 4. Merkezi Limit Teoremi
- 5. CLT Ne Zaman Kullanılır?
- 6. Süreklilik Düzeltmesi
- 7. İstatistiksel Çıkarım
- 8. Basit Rastgele Örnekleme
- 9. Nokta Tahmini
- 10. Tahmin Edicileri Değerlendirme: Yanlılık, MSE, Tutarlılık
- Örnek Sorular

## 1. Bağımsız ve Özdeş Dağılımlı (i.i.d.) Rastgele Değişkenler

Ders, olasılık kısmının son konusu olan limit teoremlerine giriş olarak başladı. Hoca teoremlere geçmeden önce sık karşılaşılan bir kısaltmayı tanımladı: i.i.d., yani "independent and identically distributed" (bağımsız ve özdeş dağılımlı) (ekrandan, 00:15:00).

**Tanım.** $X_1, X_2, \dots, X_n$ rastgele değişkenleri şu iki koşulu sağlıyorsa i.i.d.'dir:

- Bağımsızdırlar.
- Özdeş dağılımlıdırlar, yani marjinal dağılımları aynıdır: her $x \in \mathbb{R}$ için $F_{X_1}(x) = F_{X_2}(x) = \dots = F_{X_n}(x)$.

Bu ortak dağılımı taşıyan değişken $X$ ile gösterilir. Hocanın vurguladığı gibi, elimizde aslında bir "$X$" yoktur; $X_1, X_2, \dots, X_n$ vardır. $X$, bu değişkenlerin hepsinin uyduğu ortak dağılımı temsil eden, o dağılıma göre dağılmış bir rastgele değişkendir.

## 2. Örneklem Ortalaması, Beklenen Değeri ve Varyansı

Hoca istatistik konularına aslında bu kavramla girdiğimizi belirtti. i.i.d. $X_1, \dots, X_n$ için örneklem ortalaması (sample mean) $\bar X$ ya da $M_n(X)$ ile gösterilir (ekrandan, 00:15:00):

$$\bar X = M_n(X) = \frac{X_1 + X_2 + \dots + X_n}{n}.$$

Örneklem ortalaması rastgele değişkenlerin toplamından elde edildiği için kendisi de bir rastgele değişkendir. Bu yüzden onun beklenen değerinden ve varyansından söz edilebilir.

### 2.1 Örneklem ortalamasının beklenen değeri

Beklenen değerin tanımı ve doğrusallığı uygulanır (ekrandan, 00:25:00):

$$E[\bar X] = E\!\left[\frac{X_1 + X_2 + \dots + X_n}{n}\right] = \frac{EX_1 + EX_2 + \dots + EX_n}{n}.$$

$X_i$'ler aynı dağılıma sahip olduğu için her biri için $E[X_i] = EX$'tir. Böylece

$$E[\bar X] = \frac{EX + EX + \dots + EX}{n} = \frac{n\,EX}{n} = EX.$$

> **Hocanın vurgusu:** Bu önemli bir sonuçtur: örneklem ortalamasının beklenen değeri, popülasyonun beklenen değerinin kendisidir.

### 2.2 Örneklem ortalamasının varyansı

Bu kez varyans iki tarafa uygulanır (ekrandan, 00:25:00 ve 00:30:00):

$$\mathrm{Var}(\bar X) = \mathrm{Var}\!\left(\frac{X_1 + \dots + X_n}{n}\right) = \frac{\mathrm{Var}X_1 + \mathrm{Var}X_2 + \dots + \mathrm{Var}X_n}{n^2}.$$

Varyansın toplamlara bu şekilde ayrılabilmesinin nedeni $X_i$'lerin bağımsız olmasıdır. Hoca ilk yazımda paydayı $n$ yazdığını fark edip düzeltti: sabit $\frac1n$ varyansın dışına $\frac1{n^2}$ olarak çıkar. Özdeş dağılım nedeniyle $\mathrm{Var}(X_i) = \mathrm{Var}(X)$ olduğundan

$$\mathrm{Var}(\bar X) = \frac{\mathrm{Var}(X) + \dots + \mathrm{Var}(X)}{n^2} = \frac{n\,\mathrm{Var}(X)}{n^2} = \frac{\mathrm{Var}(X)}{n} = \frac{\sigma^2}{n}.$$

> **Hocanın vurgusu:** Bunu bilmek önemlidir: örneklem ortalamasının varyansı, popülasyon varyansının $n$'e bölünmüşüdür.

## 3. Büyük Sayılar Zayıf Yasası

Hoca örneklem ortalamasının bir başka önemli özelliği olarak büyük sayılar yasalarından ilkini, zayıf yasayı (Weak Law of Large Numbers, WLLN) yazdı (ekrandan, 00:30:00 ve 00:35:00).

**Teorem (WLLN).** $X_1, X_2, \dots, X_n$ i.i.d. rastgele değişkenler olsun ve $EX_i < \infty$, $EX_i = \mu$ olsun. Bu durumda her $\varepsilon > 0$ için

$$\lim_{n\to\infty} P\big(|\bar X - \mu| \ge \varepsilon\big) = 0.$$

Hoca anlamını şöyle açıkladı: elimizde gittikçe daha çok örnek oldukça örneklem ortalaması ile $\mu$ arasındaki fark o kadar küçülür ki, farkın verilen herhangi bir $\varepsilon$'dan büyük olma olasılığı sıfıra gider. Hoca önce $\{X_i\}$ kümesi diye yazdığı tanımı, $n$'i göstermek için $X_1, \dots, X_n$ biçiminde yeniden yazdı.

Teorem Chebyshev eşitsizliğiyle kanıtlanabilir; kanıt alıştırma olarak bırakıldı, kitaptan da bakılabilir (ekrandan, 00:35:00).

> **Ek bilgi (derste anlatılmadı):** Chebyshev eşitsizliği $P(|\bar X - \mu| \ge \varepsilon) \le \frac{\mathrm{Var}(\bar X)}{\varepsilon^2}$ verir. Bölüm 2.2'deki sonuçla sağ taraf $\frac{\sigma^2}{n\varepsilon^2}$ olur ve $n \to \infty$ iken sıfıra gider. Bu kanıt, büyük olasılıkla kitaptaki gibi sonlu varyans varsayımını kullanır.

## 4. Merkezi Limit Teoremi

### 4.1 Sözel ve matematiksel ifade

Hoca merkezi limit teoremini (Central Limit Theorem, CLT) "önemli" diye işaretleyerek başlattı (ekrandan, 00:35:00 ve 00:40:00).

**Sözel ifade.** Çok sayıda rastgele değişken toplanırsa, toplam dağılım bakımından yaklaşık olarak normaldir. Yani bazı rastgele değişkenlerin toplamıyla uğraşıyorsanız hesap için temelde normal dağılımı kullanabilirsiniz.

**Matematiksel ifade** (ekrandan, 00:40:00 ve 00:45:00). $X_1, X_2, \dots, X_n$ i.i.d. rastgele değişkenler, $EX_i = \mu < \infty$ ve $0 < \mathrm{Var}(X_i) = \sigma^2 < \infty$ olsun. Bu durumda

$$Z_n = \frac{\bar X - \mu}{\sigma/\sqrt n} = \frac{X_1 + X_2 + \dots + X_n - n\mu}{\sqrt n\,\sigma}$$

rastgele değişkeni şu özelliğe sahiptir:

$$\lim_{n\to\infty} P(Z_n \le x) = \Phi(x), \quad \text{her } x \in \mathbb{R} \text{ için.}$$

Burada $\Phi(x)$ standart normal dağılımın kümülatif dağılım fonksiyonudur (CDF).

$Z_n$'nin tanımında örneklem ortalamasından ortalama çıkarılıp $\sigma/\sqrt n$'e bölünür. Hoca bu paydanın, Bölüm 2.2'de bulunan örneklem ortalaması varyansının karekökü, yani $\bar X$'in standart sapması olduğunu hatırlattı. Pay ve payda $n$ ile çarpılınca ikinci biçim elde edilir: değişkenlerin toplamından $n\mu$ çıkarılır ve $\sqrt n\,\sigma$'ya bölünür.

> **Ders sonrası not:** Hoca paydayı bir yerde "sample standard deviation" diye adlandırdı (00:38:37). Doğrusu, $\sigma/\sqrt n$ örneklem ortalamasının ($\bar X$'in) standart sapmasıdır; "örneklem standart sapması" terimi genelde verinin kendisinden hesaplanan $S$ için kullanılır.

> **Hocanın vurgusu:** Bu önemlidir, çünkü pek çok rastgele değişken başka rastgele değişkenlerin toplamıdır. CLT, böyle bir toplamın kümülatif olasılıklarını standart normal dağılımın kümülatif değerleriyle hesaplamamızı sağlayan bir yaklaşım verir.

### 4.2 Örnek: banka gişesi

Hoca teoremi bir örnekle uyguladı (ekrandan, 00:50:00).

**Verilen.** Bir banka gişesi müşterilere tek tek hizmet veriyor. Müşteri $i$'nin hizmet süresi $X_i$'nin ortalaması $EX_i = 2$ dakika, varyansı $\mathrm{Var}(X_i) = 1$ dk$^2$. $X_i$'lerin i.i.d. olduğu varsayılıyor. $Y$, gişenin 50 müşteriye hizmet ederken harcadığı toplam süre. $P(90 < Y < 110) = ?$

**Çözüm** (ekrandan, 00:55:00 ve 01:00:00). Her $X_i$ bir müşteriye harcanan süredir; hepsi toplanınca 50 müşteri için harcanan toplam süre elde edilir:

$$Y = X_1 + X_2 + \dots + X_{50}.$$

Bu süreler henüz gözlenmemiş rastgele değişkenlerdir. Elde oldukça çok sayıda rastgele değişken var ve $Y$ bunların toplamı; bu yüzden CLT kullanılabilir:

$$Z_{50} = \frac{Y - n\mu}{\sqrt n\,\sigma} \sim N(0,1) \quad (\text{yaklaşık, standart normal dağılım}).$$

İstenen olasılıktaki eşitsizliğin her yerinden $n\mu$ çıkarılır ve $\sqrt n\,\sigma$'ya bölünür. $n = 50$, $\mu = 2$, $\sigma^2 = 1$ olduğundan $\sigma = 1$'dir:

$$P(90 < Y < 110) = P\!\left(\frac{90 - 50\cdot 2}{\sqrt{50}\cdot 1} < Z_{50} < \frac{110 - 50\cdot 2}{\sqrt{50}\cdot 1}\right).$$

$\frac{-10}{\sqrt{50}} = -\sqrt2$ ve $\frac{10}{\sqrt{50}} = \sqrt2$ olduğundan (ara adım eklendi)

$$= P(-\sqrt2 < Z_{50} < \sqrt2) \approx \Phi(\sqrt2) - \Phi(-\sqrt2) = 0.8427.$$

Sonuç karede $0.8427$ olarak yazılıdır (ekrandan, 01:00:00); python ile de $\Phi(\sqrt2) - \Phi(-\sqrt2) \approx 0.84270$ doğrulandı.

### 4.3 Alternatif yorum

Hoca teoremin matematiksel tanımının yanında bir de alternatif yorum verdi (ekrandan, 01:00:00 ve 01:05:00). $Y = X_1 + X_2 + \dots + X_n$ ve $X_i$'ler i.i.d. olsun. Büyük ve sabit bir $n$ için

$$Y \sim N(n\mu,\ n\sigma^2), \qquad \mu = EX_i,\quad \sigma^2 = \mathrm{Var}(X_i)$$

varsayılabilir; burada "$\sim$" "yaklaşık olarak bu dağılıma uyar" anlamındadır. Yani toplamın ortalaması $n\mu$, varyansı $n\sigma^2$ olan bir normal dağılım gibi davrandığı kabul edilir.

**Aynı örnek bu yorumla** (ekrandan, 01:05:00). $Y \sim N(50 \cdot 2\text{ dk},\ 50 \cdot 1) = N(100, 50)$ kabul edilir. İstenen, bu normal eğrinin altında 90 ile 110 arasındaki alandır; ortalama 100 bu aralığın tam ortasındadır. Normal dağılımla çalışırken problem her zaman ortalama çıkarılıp standart sapmaya bölünerek standart normale çevrilir. 90'dan ortalama 100 çıkarılıp standart sapma $\sqrt{50}$'ye bölünür, 110 için de aynısı yapılır:

$$P(90 < Y < 110) = P\!\left(\frac{90-100}{\sqrt{50}} < Z < \frac{110-100}{\sqrt{50}}\right) = P(-\sqrt2 < Z < \sqrt2) = \Phi(\sqrt2) - \Phi(-\sqrt2).$$

Görüldüğü gibi aynı noktaya varılır.

Hoca alternatif yorumu kendisi için çok daha kolay bulduğunu söyledi ve neden herkesin doğrudan bunu kullanmadığını tartıştı:

**Soru:** (Ders sırasında gelen bir soru, BELİRSİZ biçimde aktarıldı) Toplam kesikli olabilir, normal dağılım ise kesikli değildir; o zaman toplam nasıl normal sayılır?
**Cevap:** Toplanan değişkenler kesikli olabilir, bu durumda toplamın tam olarak normal dağılım olduğu söylenemez, çünkü normal dağılım süreklidir. Ayrıca $n$ sonsuza giderken ortalama ($n\mu$) da sonsuza gider; teorik olarak bu yorum sorunludur. Ama büyük ve sabit bir $n$ için böyle düşünülebilir ve bu, CLT hakkında düşünmeyi kolaylaştırır. Yine de kesin matematiksel tanım yukarıdakidir ve onun da öğrenilmesi gerekir.

<!-- BELİRSİZ: 01:04:32 civarında "Bir soru var" denmesi bir öğrencinin sohbetten sorduğu soruya mı, hocanın kendi kendine sorduğu soruya mı işaret ediyor, altyazıdan net değil. -->

## 5. CLT Ne Zaman Kullanılır?

Aradan sonra hoca, "yeterince çok" rastgele değişkenin ne demek olduğunu, yani $n$'in ne kadar büyük olması gerektiğini ele aldı (ekrandan, 01:20:00):

- $n \ge 30$ ise normal yaklaşım çok iyidir. 30 ya da daha fazla değişken topluyorsanız CLT ile normal yaklaşım yapabilirsiniz.
- Toplanan $X_i$'lerin kendisi normal dağılımlıysa toplam her zaman normaldir. Bu durumda $n$ küçük olsa da (2, 3, 4 gibi) normal dağılım kullanılabilir, çünkü normallerin toplamı da normaldir.

Ardından hoca, normal yaklaşımın hangi hesaplamalarda işe yaradığını önceki derslerden hatırlattı (ekrandan, 01:25:00):

- Binom dağılımı: Bernoulli rastgele değişkenlerinin toplamıdır.
- Negatif binom dağılımı: geometrik rastgele değişkenlerin toplamıdır.
- Gama dağılımı: üstel rastgele değişkenlerin toplamıdır.

Bu dağılımlarda bir olasılık hesaplamak gerektiğinde CLT ile normal yaklaşım yapılabilir.

## 6. Süreklilik Düzeltmesi

### 6.1 Neden gerekir?

CLT ile sürekli bir dağılım olan normali kullanırız. Kesikli bir dağılımı normal gibi sürekli bir dağılımla yaklaşıkladığımızda süreklilik düzeltmesi (continuity correction) yapmamız gerekir (ekrandan, 01:25:00).

Hoca bunu bir binom dağılımının olasılık kütle fonksiyonu (PMF) üzerinde gösterdi (ekrandan, 01:30:00). $X$ binom dağılımlı olsun ve 5 ile 6'da nokta kütleleri bulunsun; örneğin $P_X(5) = \frac16$, $P_X(6) = \frac15$ olsun. Aynı değerleri yaklaşıklayan normal dağılımlı değişken $Y$ olsun.

- Binomda $P_X(5) = \frac16$'dır.
- Normal dağılım sürekli olduğu için tek bir noktanın olasılığı sıfırdır: $P_Y(5) = 0$.

Bu iki değer eşit değildir, hatta çok farklıdır. Çözüm, 5'i tek bir nokta olarak değil, 4.5'ten 5.5'e uzanan bir aralık olarak düşünmektir:

$$P_X(5) \approx P(4.5 < Y < 5.5).$$

Bu çok daha iyi bir yaklaşımdır. Kısacası 5 yerine 4.5 ile 5.5 kullanılır; buna süreklilik düzeltmesi denir.

### 6.2 Aralık için düzeltme

Örnek devam ederken hoca 5 ile 6 arasındaki olasılığı ele aldı (ekrandan, 01:30:00). 5'in kendisi dahilse alt sınır 5 yerine $5 - \frac12 = 4.5$ olur. 6 dahilse 6'nın bütün alanı, yani 6.5'e kadarki kısım alınır:

$$P(5 \le X \le 6) \approx P\!\left(5 - \tfrac12 < Y < 6 + \tfrac12\right) = P(4.5 < Y < 6.5).$$

Karede hoca önce "$P(5 < X < 6)$" yazmaya başlamış, sözlü anlatımda ise eşitsizlikleri "küçük eşit" olarak düzeltmiştir. Eşitsizliğin $<$ ya da $\le$ olması yazılacak sınırı değiştirir; bu yüzden her durumda bu grafiksel fikir kullanılmalıdır. Bütün fikir şudur: normal yaklaşımda tek noktalar yerine noktanın çevresindeki aralık kullanılır.

<!-- BELİRSİZ: Hoca ardından "P(X < 6)" için bir örnek başlattı (01:31:47), ama altyazıda ve incelenen karelerde sonucu okunmuyor. -->

> **Ek bilgi (derste anlatılmadı):** Aynı grafik fikriyle, tam sayı değerli $X$ için $P(X < 6) = P(X \le 5)$ olduğundan büyük olasılıkla $P(X < 6) \approx P(Y < 5.5)$ yazılır; $P(X \le 6)$ için ise $P(Y < 6.5)$ kullanılır.

### 6.3 Hangi yaklaşımlarda kullanılır?

Hoca süreklilik düzeltmesinin, kesikli bir dağılımı sürekli bir dağılımla yaklaşıkladığımızda kullanıldığını tekrarladı ve sınıfa sordu:

**Soru:** Binom dağılımını normalle yaklaşıklarken süreklilik düzeltmesi kullanmalı mıyız?
**Cevap:** Evet, çünkü binom kesikli bir dağılımdır.

**Soru:** Negatif binom yaklaşımında kullanmalı mıyız?
**Cevap:** Evet, negatif binom da kesiklidir.

<!-- BELİRSİZ: 01:33:27-01:33:54 arasında gama dağılımı için ne söylendiği altyazıda bozuk; ilgili an karelerde yok. -->

> **Ders sonrası not:** Gama dağılımı sürekli bir dağılımdır; bu yüzden gamayı normalle yaklaşıklarken büyük olasılıkla süreklilik düzeltmesi gerekmez. Altyazının bu kısmı bozuk olduğu için hocanın gama hakkında tam olarak ne dediği doğrulanamadı.

## 7. İstatistiksel Çıkarım

Hoca istatistiksel çıkarım (statistical inference) konusu için yeni bir defter sayfası açtı ve artık istatistik üzerinde çalıştığımızı belirtti.

İstatistiksel çıkarım, rastgele veriden sonuç çıkarmak için kullanılan yöntemlerdir. Her veri toplandığında farklı değerler elde edilir; yani veri değerleri rastgeledir. Bu veriden sonuç çıkarmak, örneğin verinin ortalamasını, varyansını, bazı parametreleri ya da verinin geldiği dağılımı öğrenmek isteriz.

**İstatistiksel çıkarım problemi** şu kalıba uyar (ekrandan, 01:40:00):

- Tahmin edilecek bilinmeyen bir nicelik vardır.
- Bir miktar veri elde ederiz.
- Niceliği veriye dayanarak tahmin ederiz.

Yaygın kullanılan iki yaklaşım vardır: frekansçı (klasik) çıkarım ve Bayesçi çıkarım. Hocaya göre Bayesçi çıkarım biraz daha sonra geliştirilmiştir; frekansçı yöntemler daha önce geliştirildiği için "klasik" diye anılır.

### 7.1 Frekansçı çıkarım

(ekrandan, 01:45:00)

- Bilinmeyen nicelik $\theta$ ile gösterilir.
- $\theta$ sabittir, rastgele değildir; yalnızca onu bilmiyoruz.
- $\theta$'nın tahmini $\hat\theta$ ile gösterilir ("teta şapka" diye okunur).
- $\hat\theta$ bir rastgele değişkendir, çünkü veriye bağlıdır ve veri rastgeledir.

### 7.2 Bayesçi çıkarım

(ekrandan, 01:45:00)

- Bilinmeyen nicelik $\theta$ bir rastgele değişkendir; $\theta$'nın kendisi de değişebilir.
- $\theta$'nın dağılımı hakkında bir ilk tahminimiz vardır: normal, üstel, Poisson ya da başka bir dağılım olabilir; örneğin normal ise ortalaması ve varyansı, başka bir dağılımsa $\lambda$ gibi parametreleri hakkında bir ilk tahmin.
- $\theta$'nın dağılımı veriye dayanarak Bayes kuralıyla güncellenir.

Hoca, giriş düzeyindeki olasılık ve istatistik derslerinde geleneksel olarak frekansçı çıkarımın öğretildiğini, Bayesçi çıkarımın işlenmediğini söyledi. Bu derste de frekansçı çıkarım işlenecek; Bayesçi çıkarıma büyük olasılıkla zaman kalmayacak, ama ders kitaplarında bununla ilgili bir bölüm vardır ve isteyen bakabilir.

## 8. Basit Rastgele Örnekleme

Frekansçı çıkarımda ilk iş veri toplamaktır ve veri toplanırken (basit) rastgele örnekleme kullanılması gerekir (ekrandan, 01:55:00).

**Tanım.** $X_1, X_2, \dots, X_n$ rastgele değişkenlerinden oluşan bir topluluk, i.i.d. ise $n$ boyutlu (basit) rastgele örneklemdir.

Yani örneklemin bağımsız ve özdeş dağılımlı olması yeterlidir.

> **Hocanın vurgusu:** Dikkat edin: emin olmanız gereken ilk şey, verinin basit rastgele örneklemeyle toplanmış olmasıdır. Çünkü basit rastgele örnekleme kullandığımızda bazı varsayımlar yapıyoruz.

**Basit rastgele örnekleme kullandığımız için şunları varsayabiliriz** (ekrandan, 01:55:00):

- $X_i$'ler i.i.d.'dir.
- $EX_i = EX = \mu < \infty$. Burada $X$, verinin alındığı alttaki dağılımdır.
- $\mathrm{Var}(X_i) = \mathrm{Var}(X) = \sigma^2 < \infty$; çünkü değişkenler özdeş dağılımlıdır. $\sigma^2$ sonsuz olmamalıdır.

Hoca, kitaplardan birinde "sıra istatistikleri" (order statistics) adlı bir bölüm olduğunu, zaman kısıtı nedeniyle bu kısmı atladığını ve okunması gerektiğini belirtti.

## 9. Nokta Tahmini

### 9.1 Nokta tahmini ve aralık tahmini

$\theta$'yı tahmin etmenin iki farklı türü vardır:

- **Nokta tahmini (point estimation):** tahmin olarak tek bir değer, bir nokta bulunur.
- **Aralık tahmini (interval estimation):** $\theta$'nın belli bir olasılıkla belli bir aralıkta olduğu söylenir. Ayrıntıları sonraki bölümlerdedir.

Ders nokta tahminiyle başladı.

### 9.2 Nokta tahmininin kurgusu

Hoca kurguyu yeniden özetledi (ekrandan, 02:15:00):

- Bilinmeyen bir parametre $\theta$ vardır. Örneğin $\theta = EX$, yani bir $X$ rastgele değişkeninin beklenen değeri bulunmak isteniyor olabilir.
- $\theta$ sabittir (rastgele değildir).
- $\theta$'yı tahmin etmek için veri toplanır: $X_i$'ler $X$ ile aynı dağılıma sahip olacak biçimde bir basit rastgele örneklem $X_1, X_2, \dots, X_n$.

Fikir şudur: $X$'in bir parametresini bulmak istiyoruz; veriyi öyle toplarız ki her $X_i$, $X$ ile aynı dağılıma sahip olsun. Böylece elimizde i.i.d. veri olur ve $X_i$'lerin dağılımı $X$'in dağılımıyla aynıdır.

**Nokta tahmin edici (point estimator).** $\hat\theta$, rastgele örneklemin bir fonksiyonudur:

$$\hat\theta = h(X_1, X_2, \dots, X_n).$$

**Örnek.** Parametre $\theta = EX$ olsun. İyi bir nokta tahmin edici örneklem ortalaması olabilir:

$$\hat\theta = \bar X = \frac{X_1 + X_2 + \dots + X_n}{n}.$$

Hoca, bir parametre için birden fazla tahmin edici olabileceğini vurguladı. Örneğin örneklem ortalaması yerine yalnızca ilk değeri kullanmak da bir tahmin edicidir: $\hat\theta_1 = X_1$. Ya da $\hat\theta_2 = \frac{X_1 + X_n}{2}$ alınabilir. Soru şudur: bu tahmin edicilerden hangisi daha iyidir?

Hoca, iyi bir tahmin edicinin üç özelliği olduğunu söyledi; bunlar öğrenildikten sonra bir tahmin edicinin iyi mi kötü mü olduğu ya da birinin diğerinden daha iyi olduğu söylenebilir:

- Yansızdır (unbiased).
- MSE'si (ortalama kare hata) daha küçüktür.
- Tutarlıdır (consistent).

## 10. Tahmin Edicileri Değerlendirme: Yanlılık, MSE, Tutarlılık

### 10.1 Yanlılık (bias)

**Tanım** (ekrandan, 02:25:00). Bir nokta tahmin edici $\hat\theta$'nın yanlılığı

$$B(\hat\theta) = E[\hat\theta] - \theta$$

ile tanımlanır. Burada $B$ yanlılık (bias), $\hat\theta$ nokta tahmin edici, $E$ beklenen değer, $\theta$ ise tahmin etmek istediğimiz gerçek parametredir.

Hoca burada doğal bir soruyu dile getirdi: $\theta$'yı bilmiyoruz, onu tahmin etmeye çalışıyoruz; o zaman $\theta$'ya bağlı olan yanlılığı nasıl hesaplayacağız? Cevap: tahmin edicinin beklenen değeri $\theta$ çıkarsa ifade $\theta - \theta = 0$ olur ve $\theta$'yı bilmeye gerek kalmaz.

**Yansızlık (unbiasedness).** $\theta$'nın bütün olası değerleri için $B(\hat\theta) = 0$ ise $\hat\theta$, $\theta$'nın yansız bir tahmin edicisidir. Yanlılığın sıfır olmasını isteriz; o durumda tahmin edici yansız olur.

**Örnek: örneklem ortalamasının yanlılığı.** Örneklem ortalaması $\theta = EX_i$'yi tahmin eder. Tanımdan

$$B(\bar X) = E[\bar X] - \theta = E[\bar X] - EX.$$

Dersin başında $E[\bar X] = EX$ bulunmuştu. Böylece

$$B(\bar X) = EX - EX = 0.$$

Örneklem ortalaması yansız bir tahmin edicidir (ekrandan, 02:35:00). Bu güzel bir özelliktir ve $\bar X$, $EX$ için iyi bir tahmin edici gibi görünür. Ama öyle midir?

**Örnek: yalnız ilk gözlem** (ekrandan, 02:35:00). $\theta = EX$ ve $\hat\theta_1 = X_1$ olsun. $\hat\theta_1$ yansız mıdır? $X_1, X_2, \dots$ hepsi aynı beklenen değere sahip olduğu için $\theta$ yerine $EX_1$ yazılabilir:

$$B(\hat\theta_1) = E(\hat\theta_1) - \theta = E(X_1) - EX_1 = 0.$$

Yani $\hat\theta_1$ de yansızdır. Hangisi daha iyi, $\hat\theta_1$ mi $\bar X$ mi? Sezgimiz örneklem ortalamasının yalnız ilk elemanı kullanmaktan daha iyi olduğunu söyler, ama yanlılık ölçütüyle bunu ayırt edemeyiz. Bunun için ortalama kare hata kullanılır.

### 10.2 Ortalama kare hata (MSE)

**Tanım** (ekrandan, 02:40:00). Bir nokta tahmin edici $\hat\theta$'nın ortalama kare hatası (mean squared error)

$$\mathrm{MSE}(\hat\theta) = E\big[(\hat\theta - \theta)^2\big]$$

ile tanımlanır. Burada $\hat\theta$ tahmin edici, $E$ beklenen değer, $\theta$ tahmin etmek istediğimiz parametredir.

İki tahmin ediciden MSE'si daha küçük olan, daha iyi tahmin edicidir.

**Örnek: $\mathrm{MSE}(\bar X)$** (ekrandan, 02:40:00).

$$\mathrm{MSE}(\bar X) = E\big[(\bar X - EX)^2\big] = \frac{\sigma^2}{n}.$$

Hoca tanımın varyans tanımına çok benzediğine dikkat çekti: $E[\bar X] = EX$ olduğu için bu ifade aslında $\bar X$'in varyansıdır ve Bölüm 2.2'deki sonuç $\sigma^2/n$ verir. Ayrıntılı işlemi okumayı ya da kendiniz kanıtlamayı önerdi.

**Örnek: $\mathrm{MSE}(\hat\theta_1)$.**

$$\mathrm{MSE}(\hat\theta_1) = E\big[(X_1 - EX)^2\big].$$

$X_1$ ile $X$ aynı dağılıma sahip olduğundan $EX = EX_1$'dir; ifade $E[(X_1 - EX_1)^2] = \mathrm{Var}(X_1) = \mathrm{Var}(X) = \sigma^2$ olur.

**Karşılaştırma** (ekrandan, 02:45:00). $n > 1$ için

$$\mathrm{MSE}(\bar X) = \frac{\sigma^2}{n} < \sigma^2 = \mathrm{MSE}(\hat\theta_1),$$

yani MSE ölçütüne göre $\bar X$, $\hat\theta_1$'den daha iyidir.

### 10.3 MSE, yanlılık ve varyans ilişkisi

(ekrandan, 02:45:00)

$$\mathrm{MSE}(\hat\theta) = \mathrm{Var}(\hat\theta) + B(\hat\theta)^2.$$

Yani bir tahmin edicinin ortalama kare hatası, varyansı ile yanlılığının karesinin toplamıdır. Kanıtın okunması ya da kendiniz yapılması önerildi (ekrandan, 02:50:00).

> **Ek bilgi (derste anlatılmadı):** Kanıt için $\hat\theta - \theta = (\hat\theta - E\hat\theta) + (E\hat\theta - \theta)$ yazılıp kare açılır. Çapraz terimin beklenen değeri $2(E\hat\theta - \theta)\,E[\hat\theta - E\hat\theta] = 0$ olduğundan geriye $\mathrm{Var}(\hat\theta) + B(\hat\theta)^2$ kalır. Yansız bir tahmin edicide MSE varyansa eşittir; $\bar X$ örneğinde bu yüzden MSE $\sigma^2/n$ çıkmıştır.

### 10.4 Tutarlılık (consistency)

İyi bir tahmin ediciden istenen son özellik tutarlı olmasıdır.

**Tanım** (ekrandan, 02:50:00). $\hat\theta_1, \hat\theta_2, \dots, \hat\theta_n, \dots$ $\theta$'nın nokta tahmin edicilerinden oluşan bir dizi olsun. Her $\varepsilon > 0$ için

$$\lim_{n\to\infty} P\big(|\hat\theta_n - \theta| \ge \varepsilon\big) = 0$$

ise $\hat\theta_n$, $\theta$'nın tutarlı bir tahmin edicisidir. Yani tahmin ile gerçek değer arasındaki farkın mutlak değerinin bir $\varepsilon$'dan büyük olma olasılığı $n$ büyüdükçe sıfıra gider.

**Örnek.** Örneklem ortalaması tutarlıdır. Bunu aslında daha önce, örneklem ortalamasının bir özelliği olarak görmüştük: büyük sayılar zayıf yasası tam olarak bunu söyler (Bölüm 3).

**İkinci tanım (MSE ile).** $\hat\theta_1, \hat\theta_2, \dots$ $\theta$'nın nokta tahmin edicilerinden oluşan bir dizi olsun. Eğer

$$\lim_{n\to\infty} \mathrm{MSE}(\hat\theta_n) = 0$$

ise $\hat\theta_n$, $\theta$'nın tutarlı bir tahmin edicisidir.

<!-- BELİRSİZ: MSE ile tutarlılık tanımının yazıldığı an (02:51-02:52) karelerde incelenmedi; ifade altyazıdan kuruldu. -->

Hoca iki tanımı şöyle bağladı: tutarlılık bu iki limitle tanımlanabilir. $n$ arttıkça ya ortalama kare hatanın sıfıra gitmesini ya da hatanın $\varepsilon$'dan büyük olma olasılığının sıfıra gitmesini isteriz. İki tanımda da söz konusu olan, $\hat\theta_n$ ile $\theta$ arasındaki hatadır.

> **Ek bilgi (derste anlatılmadı):** İkinci tanım birinciyi gerektirir: Markov eşitsizliğiyle $P(|\hat\theta_n - \theta| \ge \varepsilon) \le \frac{\mathrm{MSE}(\hat\theta_n)}{\varepsilon^2}$ olduğundan MSE sıfıra giderse olasılık da sıfıra gider. Örneğin $\mathrm{MSE}(\bar X) = \sigma^2/n \to 0$ olduğu için $\bar X$ bu tanıma göre de tutarlıdır.

## Örnek Sorular

**Soru 1** (ekrandan, 00:50:00)

Bir banka gişesinde müşteri $i$'nin hizmet süresi $X_i$'nin ortalaması $EX_i = 2$ dakika, varyansı $\mathrm{Var}(X_i) = 1$ dk$^2$'dir. $X_i$'lerin i.i.d. olduğunu varsayın. $Y$, gişenin 50 müşteriye hizmet ederken harcadığı toplam süre olsun. $P(90 < Y < 110) = ?$

> **Çözüm (derste verildi, ekrandan, 00:55:00 ve 01:00:00):** $Y = X_1 + \dots + X_{50}$. CLT ile $Z_{50} = \frac{Y - 50\cdot 2}{\sqrt{50}\cdot 1} \approx N(0,1)$. $P(90<Y<110) = P\!\left(\frac{90-100}{\sqrt{50}} < Z_{50} < \frac{110-100}{\sqrt{50}}\right) = P(-\sqrt2 < Z_{50} < \sqrt2) \approx \Phi(\sqrt2) - \Phi(-\sqrt2) = 0.8427$. Alternatif yorumla $Y \approx N(100, 50)$ alınıp aynı standartlaştırma yapılır ve aynı sonuç çıkar.

**Soru 2** (ekrandan, 01:30:00)

$X$ binom dağılımlı ve $P_X(5) = \frac16$, $P_X(6) = \frac15$ olsun; $X$'i yaklaşıklayan normal değişken $Y$ olsun. $P_X(5)$ ve $P(5 \le X \le 6)$ normal yaklaşımla nasıl yazılır?

> **Çözüm (derste verildi):** Normalde tek noktanın olasılığı sıfırdır ($P_Y(5) = 0 \ne \frac16$), bu yüzden süreklilik düzeltmesi yapılır: $P_X(5) \approx P(4.5 < Y < 5.5)$ ve $P(5 \le X \le 6) \approx P(5 - \tfrac12 < Y < 6 + \tfrac12) = P(4.5 < Y < 6.5)$.

**Soru 3** (derste sözlü, 01:32:43)

Binom dağılımını ve negatif binom dağılımını normal dağılımla yaklaşıklarken süreklilik düzeltmesi kullanmalı mıyız?

> **Çözüm (derste verildi):** Evet; ikisi de kesikli dağılımdır ve sürekli bir dağılımla yaklaşıklanmaktadır.

**Soru 4** (ekrandan, 02:35:00)

$\theta = EX$ olsun. $\hat\theta_1 = X_1$ tahmin edicisi yansız mıdır? $\hat\theta_1$ mi $\bar X$ mi daha iyidir?

> **Çözüm (derste verildi, ekrandan, 02:35:00 - 02:45:00):** $B(\hat\theta_1) = E(X_1) - EX_1 = 0$, yani $\hat\theta_1$ yansızdır; $\bar X$ de yansızdır, bu yüzden yanlılık ölçütü ayırt edemez. MSE ile: $\mathrm{MSE}(\bar X) = \sigma^2/n$, $\mathrm{MSE}(\hat\theta_1) = \mathrm{Var}(X) = \sigma^2$. $n > 1$ için $\mathrm{MSE}(\bar X) < \mathrm{MSE}(\hat\theta_1)$ olduğundan $\bar X$ daha iyidir.

## Dersin Toparlaması

Ders, i.i.d. rastgele değişkenler ve örneklem ortalamasıyla başladı. Örneklem ortalamasının beklenen değerinin popülasyon ortalamasına, varyansının $\sigma^2/n$'e eşit olduğu gösterildi. Bu sonuçlar üzerine büyük sayılar zayıf yasası ($\bar X$'in olasılıkta $\mu$'ye yakınsaması) ve merkezi limit teoremi (standartlaştırılmış toplamın standart normale yakınsaması) kuruldu. Banka gişesi örneğiyle CLT'nin hem kesin biçimi hem de "toplam yaklaşık $N(n\mu, n\sigma^2)$" yorumu uygulandı; CLT'nin $n \ge 30$ için iyi çalıştığı, normallerin toplamının her zaman normal olduğu ve kesikli dağılımlar normalle yaklaşıklanırken süreklilik düzeltmesi gerektiği görüldü.

Dersin ikinci yarısında istatistiğe geçildi. İstatistiksel çıkarım problemi, frekansçı ve Bayesçi yaklaşımlar, basit rastgele örnekleme ve bunun getirdiği varsayımlar tanıtıldı. Nokta tahmini kurgusu içinde iyi bir tahmin edicinin üç ölçütü ele alındı: yansızlık, küçük MSE ve tutarlılık. $\bar X$'in yansız, MSE bakımından tek gözlemden daha iyi ve WLLN sayesinde tutarlı olduğu gösterildi. Aralık tahmini ilerideki bölümlere bırakıldı.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
