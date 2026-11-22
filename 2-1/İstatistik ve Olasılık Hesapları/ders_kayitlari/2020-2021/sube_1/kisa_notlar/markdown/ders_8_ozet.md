# Ders 8 Çalışma Özeti

## Genel Konular

- Olasılığın çoktan seçmeli sınav analizinde kullanılması (ekrandaki soru)
  - 20 soruluk, her sorusu 5 seçenekli bir ara sınava 100 öğrenci giriyor. İki öğrencinin en az 5 soruyu aynı yanlış seçeneği işaretleyerek yanlış yapma olasılığı soruluyor; bu olasılık çok çok küçükse olayın gerçekleşmesi nasıl yorumlanır (ekrandan, 00:10:00 ve 00:15:00).
  - Böyle bir analiz için her öğrenci ve soru için kimlik, soruyu görme zamanı, cevaplama zamanı, seçilen şık ve doğru/yanlış bilgisi tutulabileceği bir veri tablosu örneği gösterildi (ekrandan, 00:15:00).
- Üstel (exponential) dağılım
  - $X \sim \mathrm{Exp}(\lambda)$; $\lambda$, ortalamanın tersidir.
  - PDF: $f_X(x) = \lambda e^{-\lambda x}$ ($x \ge 0$), $x < 0$ için $0$. Negatif değerlerde sıfır olduğu için negatif olmayan bir dağılımdır (ekrandan, 00:25:00).
  - Toplam alan: $\int_0^\infty \lambda e^{-\lambda x}\,dx = \lambda \cdot \frac{1}{\lambda} = 1$ (ekrandan, 00:30:00).
  - CDF: $F_X(x) = 1 - e^{-\lambda x}$ ($x \ge 0$), $x < 0$ için $0$.
  - $E[X] = \lambda \int_0^\infty x e^{-\lambda x}\,dx = \lambda \cdot \frac{1}{\lambda^2} = \frac{1}{\lambda}$; $\mathrm{Var}(X) = E[X^2] - E[X]^2 = \frac{1}{\lambda^2}$ (ekrandan, 00:45:00).
  - Kullanım alanı: arıza ya da bekleme sürelerini modellemek; "bir şey olana kadar ne kadar süre geçer?" biçimindeki deneyleri tanımlamak.
  - Örnekler (ekrandan, 00:35:00 ve 00:40:00): çoktan seçmeli bir soruyu gördükten sonra şık seçene kadar geçen süre; bankaya art arda gelen iki müşterinin geliş zamanları arasındaki süre; aynı kişiye/gruba art arda atılan iki tweet arasındaki süre; Java'da yazılan kodda art arda iki programlama hatası (bug) arasındaki satır sayısı.
  - Anahtar kelime "art arda" (consecutive): art arda iki olay arasındaki süre ya da mesafe üstel dağılımla modellenir.
  - Geometrik dağılımın sürekli zamandaki karşılığıdır.
  - Belleksizlik: $\Pr(X > r + s \mid X > s) = \Pr(X > r)$ (ekrandan, 00:50:00).
  - Nadir olaylar arasındaki süre ya da uzaydaki mesafe üstel dağılımlıdır.
- Gama fonksiyonu
  - $\Gamma(m) = \int_0^\infty x^{m-1} e^{-x}\,dx$: faktöriyelin gerçel sayılara genişletilmiş hâli.
  - $\Gamma(1) = 1$, $\Gamma(0.5) = \sqrt{\pi}$, $\Gamma(k+1) = k\,\Gamma(k)$, $n$ pozitif doğal sayı için $\Gamma(n) = (n-1)!$; örnek $0.78! = \Gamma(1.78)$ (ekrandan, 01:25:00 ve 01:30:00).
  - Rastgele değişkenlerin momentleri çoğu zaman gama fonksiyonları cinsinden ifade edilir (Mellin dönüşümü adıyla anıldı).
- Gama dağılımı
  - Bu derste kullanılan gösterim: $X \sim \mathrm{Gamma}(m, \Omega)$, $m \ge \tfrac12$ biçim (shape) parametresi, $\Omega > 0$ ortalama (ekrandan, 01:40:00).
  - PDF: $f_X(x) = \frac{1}{\Gamma(m)} \left(\frac{m}{\Omega}\right)^m x^{m-1} \exp\!\left(-\frac{m}{\Omega}x\right)$ ($x \ge 0$), $x<0$ için $0$; negatif olmayan bir dağılımdır.
  - $m = 1$ için üstel dağılım elde edilir ($f_X(0) = 1/\Omega$). $m = 2, 3, 10$ için tepe sağa kayar ve sivrileşir; $m \to \infty$ için Dirac delta fonksiyonuna dönüşür (ekrandan, 01:30:00).
  - Ortalama $\Omega$, varyans $\mathrm{Var}(X) = \Omega^2/m$; $m \to \infty$ için varyans sıfıra gider.
  - $k$ adet bağımsız $E_i \sim \mathrm{Exp}(k/\Omega)$ değişkeninin toplamı $G = \sum_{i=1}^{k} E_i$ gama dağılımlıdır (ekrandan, 01:45:00).
- Normal (Gauss) dağılım
  - $X \sim N(\mu, \sigma^2)$, $\mu \in \mathbb{R}$ ortalama, $\sigma > 0$ standart sapma ($\sigma = \sqrt{\mathrm{Var}(X)}$).
  - PDF: $f_X(x) = \frac{1}{\sqrt{2\pi\sigma^2}} \exp\!\left(-\frac{(x-\mu)^2}{2\sigma^2}\right)$, $-\infty < x < \infty$ (ekrandan, 01:50:00).
  - Ortalamanın iki yanında alan $1/2$; $\mu-\sigma$'nın solunda alan yaklaşık $0.16$; $\mu-\sigma$ ile $\mu$ arasında yaklaşık $0.34$ (ekrandan, 01:55:00).
  - Standart normal: $Y \sim N(0,1)$, $f_Y(y) = \frac{1}{\sqrt{2\pi}} e^{-y^2/2}$; dağılım fonksiyonu $\Phi(x) = \Pr(Y \le x)$ tablolardan okunur.
  - Standartlaştırma: $Z = \frac{X-\mu}{\sigma}$ için $E[Z] = 0$, $\mathrm{Var}(Z) = 1$, $Z \sim N(0,1)$ (ekrandan, 02:00:00).
  - $\Pr(X < b) = \Phi\!\left(\frac{b-\mu}{\sigma}\right)$, $\Pr(a < X \le b) = \Phi\!\left(\frac{b-\mu}{\sigma}\right) - \Phi\!\left(\frac{a-\mu}{\sigma}\right)$ (ekrandan, 02:05:00).
- Teori ve teorem
  - Teorem ispatlanmış önermedir; teori bir teoremler kümesidir (ör. olasılık teorisi: Markov, toplam olasılık, Bayes, merkezi limit teoremi...).
- Merkezi limit teoremi (CLT)
  - $X_1, \dots, X_n$ bağımsız, ortalamaları $\mu$, standart sapmaları $\sigma$ aynı; $S_n = X_1 + \dots + X_n$, $E[S_n] = n\mu$, $\mathrm{Var}(S_n) = n\sigma^2$ (ekrandan, 02:30:00).
  - Standartlaştırılmış toplam $Z_n = \frac{S_n - E[S_n]}{\sqrt{\mathrm{Var}(S_n)}}$, $n \to \infty$ için $N(0,1)$'e yaklaşır; $\Pr(S_n < s) \approx \Phi\!\left(\frac{s - n\mu}{\sqrt{n}\,\sigma}\right)$ (ekrandan, 02:35:00).
  - Pratikte $n \ge 30$ yeterince büyük sayılır.
  - Tam dağılım sonuçları: bağımsız ve özdeş dağılımlı üstellerin toplamı tam olarak gama; özdeş olmayan bağımsız üstellerin toplamı Gauss ile yaklaşıklanabilir; negatif binom bağımsız geometriklerin, binom bağımsız Bernoulli'lerin toplamının tam dağılımıdır (ekrandan, 02:40:00).
- İstatistiğe giriş (kitabın 8. bölümü)
  - İstatistik bilimlerin evrensel dilidir; verilerin toplanması, sınıflandırılması, sunulması ve yorumlanması bilimidir.
  - Betimsel (descriptive) ve çıkarımsal (inferential) istatistik ayrımı.
  - Temel terimler: popülasyon, örneklem, değişken, veri, deney, parametre, istatistik (ekrandan, 02:55:00 ve 03:00:00).

## Hocanın Özellikle Vurguladığı Kısımlar

- Dağılımları ve kullanım amaçlarını çok iyi bilmek
  - Her dağılım belli bir amaca hizmet eder; hangi problemde hangi dağılımın kullanılacağını bilmek, olasılık ve istatistiği gerçek problemlere uygulamanın anahtarıdır.
- "Art arda" anahtar kelimesi
  - Art arda gelen iki olay arasındaki süre/mesafe görülünce üstel dağılım düşünülmelidir.
  - Art arda birden fazla olay için geçen toplam süre/mesafe gama dağılımlıdır (ör. bir öğrencinin art arda üç soruyu cevaplama süresi, $n$ müşterinin art arda gelmesi için geçen süre, bir elektronun metal içinde art arda $n$ elektronla çarpışması için geçen süre).
- Gama fonksiyonu formülleri ezberlenmeli
  - $\Gamma(1)$, $\Gamma(0.5)$, $\Gamma(k+1) = k\Gamma(k)$, $\Gamma(n) = (n-1)!$ moment hesaplarında sık kullanılır.
- Varyans ve ölçüm doğruluğu
  - Varyansın sıfır olması değerin hep aynı olması (sabit) demektir. Hep aynı sonucu veren ölçüm cihazının varyansı sıfırdır; ölçümleri çok farklı çıkan barometre için belirsizlik ve hata fazladır.
  - Gama dağılımında $m$ ölçümlerin doğruluğunu gösteren bir parametre gibi düşünülebilir; $m$ büyüdükçe varyans azalır.
- Histograma bakarak dağılım seçimi
  - Histogram çan biçimindeyse Gauss varsayılabilir; ortalama ve varyans hesaplanınca PDF bilinmiş olur.
- Tam dağılımlar (gama, negatif binom, binom) ve CLT ilişkisi çok önemli noktalar olarak işaretlendi.

## Kısa Tekrar Notları

- $\mathrm{Exp}(\lambda)$: $f = \lambda e^{-\lambda x}$, $F = 1 - e^{-\lambda x}$, $E = 1/\lambda$, $\mathrm{Var} = 1/\lambda^2$, belleksiz.
- Üstel = art arda iki olay arası süre; geometriğin sürekli karşılığı.
- $\Gamma(n) = (n-1)!$, $\Gamma(0.5) = \sqrt\pi$, $\Gamma(k+1) = k\Gamma(k)$.
- $\mathrm{Gamma}(m,\Omega)$ (derste kullanılan gösterim): ortalama $\Omega$, varyans $\Omega^2/m$; $m=1$ üstel, $m\to\infty$ delta.
- Bağımsız özdeş üstellerin toplamı gama dağılımlıdır.
- $N(\mu,\sigma^2)$: $\mu-\sigma$'nın solu $\approx 0.16$, $[\mu-\sigma,\mu]$ arası $\approx 0.34$.
- $Z = (X-\mu)/\sigma \sim N(0,1)$; $\Pr(X<b) = \Phi((b-\mu)/\sigma)$.
- CLT: $S_n \approx N(n\mu, n\sigma^2)$, $n \ge 30$.
- Negatif binom = geometriklerin toplamı; binom = Bernoulli'lerin toplamı.
- Popülasyon ⊃ örneklem; parametre popülasyona (Yunan harfi), istatistik örnekleme (Latin harfi) aittir.

## Detaylı Açıklamalar

- **Üstel dağılımın türetmeleri.** Toplam alan $\lambda\int_0^\infty e^{-\lambda x}dx = \lambda\cdot\frac1\lambda = 1$ olur. CDF, PDF'in $0$'dan $x$'e integralidir: $F_X(x) = 1 - e^{-\lambda x}$. Ortalama için $\int_0^\infty x e^{-\lambda x}dx = 1/\lambda^2$ olduğundan $E[X] = 1/\lambda$ bulunur. Varyans, ikinci momentten ilk momentin karesi çıkarılarak $1/\lambda^2$ çıkar. Python ile sayısal integralle doğrulandı.
- **Belleksizliğin ispatı.** $X > r+s$ olayı $X > s$ olayının içinde kaldığından $\Pr(X > r+s \mid X > s) = \frac{\Pr(X > r+s)}{\Pr(X>s)} = \frac{1 - F_X(r+s)}{1 - F_X(s)} = \frac{e^{-\lambda(r+s)}}{e^{-\lambda s}} = e^{-\lambda r} = \Pr(X > r)$. Sonuç $s$'ye bağlı değildir: $s$ kadar beklemiş olmanın bilgisi geri kalan süreyi etkilemez.
- **Paralel evrenler örneği.** Hoca nadir olaylar arası mesafenin üstel olduğunu sezdirmek için varsayımsal bir örnek kullandı: art arda iki evren arasındaki mesafe $D$ üstel dağılımlı olsun; $\lambda = 1/E[D]$ ve ortalama mesafe yaklaşık $10^{10}$ alındı (ekrandan, 01:05:00). Örneğin amacı ortalama bilinince $\lambda$'nın, dolayısıyla PDF'in bulunabildiğini göstermektir.
- **Genişletilmiş genelleştirilmiş K (EGK) dağılımı.** Evde çalışılmak üzere verildi; optik kablosuz (Li-Fi) kanalların modellenmesinde kullanıldığı söylendi. <!-- BELİRSİZ: EGK dağılımının ekranda yazılan tanımı karelerde görünmüyor. -->
- **Gama dağılımının ortalaması.** $E[X] = \frac{1}{\Gamma(m)}\left(\frac{m}{\Omega}\right)^m \int_0^\infty x^m e^{-\frac{m}{\Omega}x}dx$ olarak kuruldu (ekrandan, 01:35:00). Bu integral $\Gamma(m+1)\left(\frac{\Omega}{m}\right)^{m+1}$ değerindedir; yerine konunca $E[X] = \Omega$ çıkar. Varyans aynı yolla $\Omega^2/m$ bulunur.
  - Ders sonrası not: Ekranda integral $\frac{\Gamma(m)\,\Omega^{m-1}}{m^m}$ ve sonuç $E[X] = 1/\Omega$ diye yazıldı, varyansta da $1/\Omega^2$ çıkarıldı. Doğrusu integral $\Gamma(m+1)(\Omega/m)^{m+1}$, $E[X] = \Omega$ ve $\mathrm{Var}(X) = E[X^2] - \Omega^2 = \Omega^2/m$'dir. Bu, hocanın kendi tanımıyla ("$\Omega$ is the average of $X$") da uyumludur; $m=3$, $\Omega=2$ için python ile doğrulandı.
- **Üstellerin toplamı.** Bir işlem $k$ adımdan oluşuyor ve her adım ortalaması $\Omega/k$ olan üstel süre alıyorsa toplam süre gama dağılımlıdır. Ekranda $G \sim \mathrm{Gamma}(k, \Omega/k)$ yazıldı (ekrandan, 01:45:00).
  - Ders sonrası not: Derste kullanılan $\mathrm{Gamma}(m,\Omega)$ gösteriminde ikinci parametre ortalamadır; toplamın ortalaması $k \cdot \Omega/k = \Omega$, varyansı $\Omega^2/k$ olduğundan bu gösterimle $G \sim \mathrm{Gamma}(k, \Omega)$ yazılmalıdır. $\Omega/k$ ise biçim-ölçek (shape-scale) gösterimindeki ölçek parametresidir. Benzetimle doğrulandı ($k=3$, $\Omega=2$: ortalama $\approx 2$, varyans $\approx 4/3$).
- **Normal dağılım alanları.** $\Phi(-1) \approx 0.1587$ ve $\Phi(0) - \Phi(-1) \approx 0.3413$ olduğundan derste verilen $0.16$ ve $0.34$ değerleri doğrudur.
- **Standartlaştırma ve olasılık hesabı.** $E[Z] = \frac1\sigma E[X] - \frac\mu\sigma = 0$; sabit eklemek varyansı değiştirmediği için $\mathrm{Var}(Z) = \frac{1}{\sigma^2}\mathrm{Var}(X) = 1$. $X = \sigma Z + \mu$ yazılır, $\sigma > 0$ olduğundan eşitsizlik iki taraf $\sigma$'ya bölünerek $\Pr(X<b) = \Pr\left(Z < \frac{b-\mu}{\sigma}\right) = \Phi\left(\frac{b-\mu}{\sigma}\right)$ bulunur. Sürekli dağılımda $\Pr(a<X\le b) = \Pr(a<X<b)$'dir.
  - Ders sonrası not: Altyazıda bu fonksiyon için "Q function" ve "quantile function" adları geçiyor; ekranda ise $\Phi$ yazılı (ekrandan, 02:05:00). $\Phi(x) = \Pr(Y \le x)$ standart normalin dağılım fonksiyonudur (CDF); quantile fonksiyonu ise büyük olasılıkla onun tersi $\Phi^{-1}$'dir, mühendislikte $Q(x)$ ise genelde $1-\Phi(x)$ için kullanılır.
- **Merkezi limit teoremi.** Toplamın beklenen değeri doğrusallıktan $n\mu$, varyansı bağımsızlıktan $n\sigma^2$, standart sapması $\sqrt n\,\sigma$ olur. $S_n = \sqrt n\,\sigma Z_n + n\mu$ yazılıp aynı standartlaştırma adımlarıyla $\Pr(S_n < s) \approx \Phi\left(\frac{s - n\mu}{\sqrt n\,\sigma}\right)$ elde edilir.
- **İstatistiğe giriş tanımları.** Popülasyon, özellikleri incelenecek bireyler, nesneler ya da ölçümler kümesidir; örneklem popülasyonun alt kümesidir. Hoca bunu olasılık teorisiyle eşledi: kümeler teorisindeki evrensel küme olasılıkta örnek uzay, istatistikte popülasyon olur; alt küme olasılıkta olay, istatistikte örneklem olur. Değişken her elemanın ilgilenilen bir özelliğidir (ör. öğrencilerin boyu). Veri, değişken için her elemandan toplanan değerler kümesidir. Deney, sonuçları bir veri kümesi veren planlı etkinliktir. Parametre tüm popülasyonun sayısal özelliğidir (Yunan harfiyle gösterilir); istatistik örneklemin sayısal özelliğidir (Latin harfiyle gösterilir).

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
