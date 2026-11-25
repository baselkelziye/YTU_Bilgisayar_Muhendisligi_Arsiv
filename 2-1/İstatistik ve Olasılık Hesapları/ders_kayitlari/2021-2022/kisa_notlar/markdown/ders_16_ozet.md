# Ders 16 Çalışma Özeti

## Genel Konular

- Bağımsız ve özdeş dağılımlı (i.i.d.) rastgele değişkenler
  - $X_1, X_2, \dots, X_n$ rastgele değişkenleri şu iki koşul sağlanırsa i.i.d.'dir: (1) bağımsızdırlar; (2) marjinal dağılımları aynıdır, yani her $x \in \mathbb{R}$ için $F_{X_1}(x) = F_{X_2}(x) = \dots = F_{X_n}(x)$ (ekrandan, 00:15:00).
  - Bu ortak dağılımı taşıyan değişken $X$ ile gösterilir; $X$ verinin geldiği alttaki (underlying) dağılımı temsil eder.
- Örneklem ortalaması (sample mean)
  - Tanım: $\bar{X} = M_n(X) = \frac{X_1 + X_2 + \dots + X_n}{n}$ (ekrandan, 00:15:00).
  - $\bar{X}$ rastgele değişkenlerin toplamından elde edildiği için kendisi de bir rastgele değişkendir; beklenen değeri ve varyansı konuşulabilir.
  - Beklenen değer: $E[\bar{X}] = \frac{EX_1 + \dots + EX_n}{n} = \frac{n\,EX}{n} = EX$ (ekrandan, 00:25:00).
  - Varyans: bağımsızlık sayesinde varyans toplamlara ayrılır; $\frac1n$ dışarı $\frac{1}{n^2}$ olarak çıkar. $\mathrm{Var}(\bar{X}) = \frac{n\,\mathrm{Var}(X)}{n^2} = \frac{\sigma^2}{n}$ (ekrandan, 00:30:00).
- Büyük sayılar zayıf yasası (WLLN)
  - $X_1, \dots, X_n$ i.i.d., $EX_i = \mu < \infty$ ise her $\varepsilon > 0$ için $\lim_{n\to\infty} P(|\bar{X} - \mu| \ge \varepsilon) = 0$ (ekrandan, 00:35:00).
  - Chebyshev eşitsizliğiyle kanıtlanabilir; kanıt alıştırma olarak bırakıldı.
- Merkezi limit teoremi (CLT)
  - Sözel ifade: çok sayıda rastgele değişkenin toplamı dağılım bakımından yaklaşık olarak normaldir (ekrandan, 00:40:00).
  - Matematiksel ifade: $X_1, \dots, X_n$ i.i.d., $EX_i = \mu < \infty$ ve $0 < \mathrm{Var}(X_i) = \sigma^2 < \infty$ olsun. $Z_n = \frac{\bar{X} - \mu}{\sigma/\sqrt{n}} = \frac{X_1 + \dots + X_n - n\mu}{\sqrt{n}\,\sigma}$ için her $x \in \mathbb{R}$'de $\lim_{n\to\infty} P(Z_n \le x) = \Phi(x)$; $\Phi$ standart normal CDF'tir (ekrandan, 00:45:00).
  - Payda $\sigma/\sqrt{n}$, örneklem ortalamasının standart sapmasıdır ($\sqrt{\mathrm{Var}(\bar{X})}$).
  - Alternatif yorum: büyük ve sabit bir $n$ için $Y = X_1 + \dots + X_n$ yaklaşık olarak $N(n\mu, n\sigma^2)$ dağılımlıdır (ekrandan, 01:00:00).
- Banka gişesi örneği (ekrandan, 00:50:00 - 01:05:00)
  - Müşteri $i$'nin hizmet süresi $X_i$: $EX_i = 2$ dk, $\mathrm{Var}(X_i) = 1$ dk$^2$, i.i.d. $Y$: 50 müşteriye harcanan toplam süre. $P(90 < Y < 110) = ?$
  - $Y = X_1 + \dots + X_{50}$; CLT ile $Z_{50} = \frac{Y - 50\cdot 2}{\sqrt{50}\cdot 1} \sim N(0,1)$ yaklaşık.
  - $P(90<Y<110) = P\!\left(\frac{90-100}{\sqrt{50}} < Z_{50} < \frac{110-100}{\sqrt{50}}\right) = P(-\sqrt2 < Z_{50} < \sqrt2) \approx \Phi(\sqrt2) - \Phi(-\sqrt2) = 0.8427$.
  - Alternatif yorumla: $Y \sim N(100, 50)$ yaklaşık; aynı standartlaştırma aynı sonuca götürür.
- CLT ne zaman kullanılır? (ekrandan, 01:20:00)
  - $n \ge 30$ ise normal yaklaşım çok iyidir.
  - $X_i$'ler normal dağılımlıysa toplam her zaman normaldir; $n$ küçük olsa da (2, 3, 4) kullanılabilir.
  - Toplam olarak yazılabilen dağılımlar için normal yaklaşım: binom (Bernoulli toplamı), negatif binom (geometrik toplamı), gama (üstel toplamı) (ekrandan, 01:25:00).
- Süreklilik düzeltmesi (continuity correction) (ekrandan, 01:25:00 ve 01:30:00)
  - Kesikli bir dağılım normal gibi sürekli bir dağılımla yaklaşıklanırken kullanılır.
  - Sürekli dağılımda tek bir noktanın olasılığı 0'dır: binom için $P_X(5) = \frac16$ iken normalde $P_Y(5) = 0$. Bu yüzden 5 değeri $[4.5, 5.5]$ aralığı olarak düşünülür: $P_X(5) \approx P(4.5 < Y < 5.5)$.
  - $P(5 \le X \le 6) \approx P(5 - \tfrac12 < Y < 6 + \tfrac12)$; eşitsizliğin $<$ ya da $\le$ olmasına göre sınır grafik üzerinden belirlenir.
- İstatistiksel çıkarım (statistical inference) (ekrandan, 01:40:00)
  - Bilinmeyen bir nicelik vardır, veri toplanır, nicelik veriye dayanarak tahmin edilir.
  - İki yaygın yaklaşım: frekansçı (klasik) çıkarım ve Bayesçi çıkarım.
  - Frekansçı: bilinmeyen $\theta$ sabittir (rastgele değildir); tahmini $\hat\theta$ ("teta şapka") veriye bağlı olduğu için rastgele değişkendir (ekrandan, 01:45:00).
  - Bayesçi: $\theta$ bir rastgele değişkendir; dağılımı hakkında bir ilk tahmin vardır ve bu dağılım veriye göre Bayes kuralıyla güncellenir. Derste frekansçı çıkarım işlenecek.
- Basit rastgele örnekleme (ekrandan, 01:55:00)
  - $X_1, \dots, X_n$ i.i.d. ise $n$ boyutlu (basit) rastgele örneklemdir.
  - Basit rastgele örneklemle şu varsayımlar yapılır: $X_i$ i.i.d.; $EX_i = EX = \mu < \infty$; $\mathrm{Var}(X_i) = \mathrm{Var}(X) = \sigma^2 < \infty$.
- Nokta tahmini ve aralık tahmini
  - Nokta tahmini tek bir değer verir; aralık tahmini $\theta$'nın belli bir olasılıkla bir aralıkta olduğunu söyler. Ders nokta tahminiyle başladı (ekrandan, 02:15:00).
  - Tahmin edici (estimator) örneklemin bir fonksiyonudur: $\hat\theta = h(X_1, \dots, X_n)$.
  - $\theta = EX$ için olası tahmin ediciler: $\bar{X}$, $\hat\theta_1 = X_1$, $\hat\theta_2 = \frac{X_1 + X_n}{2}$.
- Tahmin edicileri değerlendirme
  - Yanlılık (bias): $B(\hat\theta) = E[\hat\theta] - \theta$ (ekrandan, 02:25:00). Her $\theta$ için $B(\hat\theta) = 0$ ise tahmin edici yansızdır (unbiased).
  - $B(\bar{X}) = EX - EX = 0$; $\bar{X}$ yansızdır. $B(\hat\theta_1) = E X_1 - EX_1 = 0$; $X_1$ de yansızdır (ekrandan, 02:35:00).
  - Ortalama kare hata: $\mathrm{MSE}(\hat\theta) = E[(\hat\theta - \theta)^2]$; MSE'si küçük olan tahmin edici daha iyidir (ekrandan, 02:40:00).
  - $\mathrm{MSE}(\bar{X}) = \frac{\sigma^2}{n}$, $\mathrm{MSE}(\hat\theta_1) = E[(X_1 - EX)^2] = \mathrm{Var}(X) = \sigma^2$. $n > 1$ için $\bar{X}$ MSE ölçütüne göre daha iyidir (ekrandan, 02:45:00).
  - MSE-yanlılık-varyans ilişkisi: $\mathrm{MSE}(\hat\theta) = \mathrm{Var}(\hat\theta) + B(\hat\theta)^2$.
  - Tutarlılık (consistency): $\hat\theta_1, \hat\theta_2, \dots$ bir tahmin edici dizisi olsun. Her $\varepsilon > 0$ için $\lim_{n\to\infty} P(|\hat\theta_n - \theta| \ge \varepsilon) = 0$ ise $\hat\theta_n$ tutarlıdır (ekrandan, 02:50:00). Örnek: WLLN gereği $\bar{X}$ tutarlıdır.
  - İkinci tanım: $\lim_{n\to\infty} \mathrm{MSE}(\hat\theta_n) = 0$ ise $\hat\theta_n$ tutarlıdır.

## Hocanın Özellikle Vurguladığı Kısımlar

- $E[\bar{X}] = EX$ ve $\mathrm{Var}(\bar{X}) = \sigma^2/n$
  - İkisi de "önemli sonuç" olarak vurgulandı. Örneklem ortalamasının beklenen değeri popülasyon ortalamasıdır, varyansı popülasyon varyansının $n$'e bölünmüşüdür.
  - Hoca ilk yazımda $\frac1n$'in varyanstan $\frac1{n^2}$ olarak çıkması gerektiğini atladığını fark edip düzeltti.
- Merkezi limit teoremi önemlidir
  - Birçok rastgele değişken başka rastgele değişkenlerin toplamıdır; CLT toplamın kümülatif olasılıklarını standart normal CDF ile yaklaşık hesaplamayı sağlar.
  - Hoca alternatif yorumu ($Y \approx N(n\mu, n\sigma^2)$) düşünmek için daha kolay bulduğunu, ama $n \to \infty$ için teorik olarak sorunlu olduğunu ve kesin matematiksel tanımın da öğrenilmesi gerektiğini söyledi.
- Süreklilik düzeltmesi
  - Kesikli bir dağılım sürekli bir dağılımla yaklaşıklandığında her tek nokta, çevresindeki yarım birimlik aralıkla değiştirilir. Binom ve negatif binom yaklaşımında kullanılır.
- Basit rastgele örnekleme
  - Verinin basit rastgele örneklemeyle toplandığından emin olmak ilk adımdır; sonraki bütün varsayımlar (i.i.d., sonlu ortalama ve varyans) buna dayanır.
- İyi bir tahmin edicinin üç özelliği
  - Yansız olmak, MSE'sinin küçük olması ve tutarlı olmak.

## Kısa Tekrar Notları

- i.i.d.: bağımsız + aynı marjinal CDF.
- $\bar{X} = \frac1n\sum X_i$; $E[\bar X] = \mu$, $\mathrm{Var}(\bar X) = \sigma^2/n$.
- WLLN: $P(|\bar X - \mu| \ge \varepsilon) \to 0$.
- CLT: $Z_n = \frac{\sum X_i - n\mu}{\sqrt n\,\sigma} \to N(0,1)$; pratikte $\sum X_i \approx N(n\mu, n\sigma^2)$.
- $n \ge 30$ yeterli; $X_i$ normal ise her $n$ için toplam normal.
- Kesikli → sürekli yaklaşımında süreklilik düzeltmesi: $k \to [k - \tfrac12, k + \tfrac12]$.
- Frekansçı çıkarım: $\theta$ sabit, $\hat\theta$ rastgele. Bayesçi: $\theta$ rastgele, dağılımı Bayes kuralıyla güncellenir.
- Bias $= E\hat\theta - \theta$; MSE $= E(\hat\theta-\theta)^2 = \mathrm{Var}(\hat\theta) + B^2$.
- $\bar X$ ve $X_1$ ikisi de yansız; MSE'leri $\sigma^2/n$ ve $\sigma^2$, bu yüzden $\bar X$ daha iyi.
- Tutarlılık: $P(|\hat\theta_n - \theta| \ge \varepsilon) \to 0$ ya da $\mathrm{MSE}(\hat\theta_n) \to 0$.

## Detaylı Açıklamalar

- **i.i.d. ve örneklem ortalaması.** Limit teoremlerinin ortak varsayımı, toplanan rastgele değişkenlerin bağımsız ve özdeş dağılımlı olmasıdır. Özdeş dağılım, her $X_i$'nin CDF'inin aynı olması demektir; bu ortak dağılımı taşıyan değişkene $X$ denir. Örneklem ortalaması $\bar X$ bu değişkenlerin ortalamasıdır ve kendisi de rastgeledir. Beklenen değerin doğrusallığıyla $E[\bar X] = \frac{1}{n}\sum EX_i = EX$ bulunur. Varyansta ise bağımsızlık gerekir: bağımsız değişkenlerin toplamının varyansı varyansların toplamıdır, sabit çarpan $\frac1n$ ise karesi alınarak dışarı çıkar. Sonuç $\mathrm{Var}(\bar X) = \frac{n\sigma^2}{n^2} = \frac{\sigma^2}{n}$'dir; yani örneklem büyüdükçe ortalama, gerçek ortalamanın etrafında daha dar bir şekilde toplanır.
- **WLLN.** Bu daralmanın olasılık diliyle ifadesi büyük sayılar zayıf yasasıdır: $n$ arttıkça $\bar X$ ile $\mu$ arasındaki farkın herhangi bir $\varepsilon$'dan büyük olma olasılığı sıfıra gider. Hoca kanıtın Chebyshev eşitsizliğinden çıktığını söyleyip alıştırma olarak bıraktı.
- **CLT ve banka gişesi örneği.** CLT, standartlaştırılmış toplamın dağılımının standart normale yakınsadığını söyler. Pay ve payda $n$ ile çarpılınca $Z_n = \frac{\sum X_i - n\mu}{\sqrt n\,\sigma}$ biçimi elde edilir. Banka gişesi örneğinde 50 müşterinin toplam hizmet süresinin beklenen değeri $50\cdot 2 = 100$ dk, varyansı $50 \cdot 1 = 50$ dk$^2$'dir. 90 ve 110 dakika standartlaştırılınca $\mp 10/\sqrt{50} = \mp\sqrt2$ olur ve olasılık $\Phi(\sqrt2) - \Phi(-\sqrt2) \approx 0.8427$ bulunur. Alternatif yorumda doğrudan $Y \sim N(100, 50)$ kabul edilir; normal dağılımla çalışırken zaten ortalama çıkarılıp standart sapmaya bölündüğü için aynı noktaya varılır.
- **Normal yaklaşımın kapsamı.** Binom dağılımı Bernoulli değişkenlerinin, negatif binom geometrik değişkenlerin, gama ise üstel değişkenlerin toplamıdır. Bu yüzden bu dağılımların olasılıkları, $n$ yeterince büyükse CLT ile normal dağılımdan yaklaşık hesaplanabilir.
- **Süreklilik düzeltmesi.** Binom gibi kesikli bir dağılımda her tam sayının pozitif bir olasılığı vardır, normal dağılımda ise tek noktanın olasılığı sıfırdır. Bu farkı kapatmak için $k$ değeri $[k-\tfrac12, k+\tfrac12]$ aralığı olarak alınır. Örnekte $P(5 \le X \le 6)$, 5'in sol kenarı 4.5'ten 6'nın sağ kenarı 6.5'e kadar olan alanla, $P(4.5 < Y < 6.5)$ ile yaklaşıklanır. Eşitsizlik katı ise ilgili uç nokta dahil edilmez ve sınır buna göre kayar; hoca bunun grafik üzerinden düşünülmesini önerdi.
  <!-- BELİRSİZ: Hoca "P(X < 6)" için de bir örnek başlattı (01:31:47) ama altyazıda sonucu okunmuyor ve karesi yok. -->
- **İstatistiksel çıkarım.** Her veri toplandığında farklı değerler gelir; veri rastgeledir. İstatistiksel çıkarım bu veriden ortalama, varyans gibi parametreler ya da dağılım hakkında sonuç çıkarma yöntemleridir. Frekansçı yaklaşımda bilinmeyen $\theta$ sabittir ama bilinmez; tahmin $\hat\theta$ rastgele veriye bağlı olduğundan rastgeledir. Bayesçi yaklaşımda $\theta$ rastgele kabul edilir, onun için bir ilk dağılım (ör. normal, üstel, Poisson ve parametreleri) varsayılır ve veri geldikçe Bayes kuralıyla güncellenir. Giriş düzeyindeki derslerde geleneksel olarak frekansçı çıkarım işlenir.
- **Tahmin edicilerin karşılaştırılması.** $\theta = EX$ için $\bar X$ ve yalnız ilk gözlemi kullanan $\hat\theta_1 = X_1$ ikisi de yansızdır; yanlılık ölçütü aralarında ayrım yapamaz. Sezgi $\bar X$'in daha iyi olduğunu söyler; bunu MSE gösterir: $\mathrm{MSE}(\bar X) = \sigma^2/n$, $\mathrm{MSE}(X_1) = \sigma^2$. MSE tanımı varyans tanımına çok benzer; yansız bir tahmin edicide MSE varyansa eşittir. Genel ilişki $\mathrm{MSE} = \mathrm{Var} + B^2$'dir; kanıtı okunması ya da kendiniz yapmanız için bırakıldı. Son olarak tutarlılık, $n$ arttıkça tahmin hatasının olasılıkta ya da MSE anlamında sıfıra gitmesidir; $\bar X$'in tutarlılığı doğrudan WLLN'den gelir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
