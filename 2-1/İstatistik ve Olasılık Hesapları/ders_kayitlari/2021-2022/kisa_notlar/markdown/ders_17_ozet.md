# Ders 17 Çalışma Özeti

## Genel Konular

- Ortalama ve varyans için nokta tahmin ediciler (point estimators)
  - Örneklem, $X_1, X_2, \dots, X_n$ rastgele değişkenlerinin bir topluluğu olarak yazılır (ekrandan, 00:35:00).
  - $\mu = E X$ için iyi bir tahmin edici örneklem ortalamasıdır: $\overline{X}$ (ekrandan, 00:35:00).
  - Varyans $\sigma^2$ için iyi bir tahmin edici örneklem varyansıdır: $S^2$. Paydada $n$ değil $n-1$ vardır; bu sayede $S^2$ yansız (unbiased) olur.
  - Standart sapma $\sigma$ için iyi bir tahmin edici $\sqrt{S^2}$, yani örneklem standart sapmasıdır (sample standard deviation) (ekrandan, 00:40:00).
- Sayısal örnek ve Python ile hesaplama
  - Bir fabrikada belirli bir işin tamamlanma süresi $T$; altı gözlem: $18, 21, 17, 16, 24, 20$; $T_i$'ler bağımsız ve aynı dağılımlı (i.i.d.) (ekrandan, 00:45:00).
  - $\overline{T} \approx 19.33$, $S^2 \approx 8.67$, $S \approx 2.94$ (ekrandan, 00:50:00).
  - NumPy ile `np.mean(t)`, `np.var(t, ddof=1)` ve karekök (ekrandan, 00:50:00).
- En çok olabilirlik kestirimi (Maximum Likelihood Estimation, MLE)
  - Bazen ortalama ya da varyans değil, bir dağılımın parametresi tahmin edilmek istenir; örneğin $X \sim \text{Poisson}(\lambda)$ için $\lambda$ (ekrandan, 00:55:00).
  - Olabilirlik fonksiyonu (likelihood function): kesikli durumda olasılıkların, sürekli durumda yoğunlukların çarpımı (ekrandan, 01:00:00).
  - MLE'de tahmin edici, olabilirliği en büyük yapan değerdir: $\hat{\theta} = \arg\max_{\hat{\theta}} L$ (ekrandan, 01:05:00).
  - Analitik çözümde kritik noktalar: türevin sıfır olduğu noktalar ve sınır noktaları (ekrandan, 01:10:00 ve 01:15:00).
  - Olabilirlik yerine logaritması en büyüklenir; çarpım toplama dönüşür, türev kolaylaşır (ekrandan, 01:15:00).
  - Poisson örneği: veri $6, 4, 2$ için $\hat{\lambda} = \overline{X} = 4$ (ekrandan, 01:20:00 ve 01:35:00).

## Hocanın Özellikle Vurguladığı Kısımlar

- $S^2$'de bölen $n$ değil $n-1$'dir
  - $1/n$ ile bölünen tahmin edici yanlı olur; $S^2$'yi yansız yapmak için $n-1$'e bölünür.
  - Python'da `np.var` için `ddof=1` verilmesi bu yüzden gereklidir (ekrandan, 00:50:00).
- Örneklem standart sapması $S$ yanlıdır
  - Hoca, kitapların verdiği yansız bir tahmin edici olmadığını, $S$'nin yine de kabul edilebilir bir tahmin edici olduğunu söyledi.
- Türevi sıfıra eşitlemek her zaman maksimumu vermez
  - Türevin sıfır olduğu yerler minimum, eyer (saddle) noktası ya da maksimum olabilir; sınır noktaları da ayrıca kontrol edilmelidir.
- "Güzel hile" (nice trick): log-olabilirlik
  - Logaritma artan bir fonksiyon olduğu için maksimumun yeri değişmez; çarpımın türevi karmaşıkken toplamın türevi terim terim alınır.
- Türev alma adımında dikkatli olunmalı
  - Hoca, adımlar zor olmasa da çok dikkatli olunması gerektiğini, çünkü kolayca hata yapılabileceğini belirtti; kendisi de bir adımı sonradan düzeltti.

## Kısa Tekrar Notları

- Örneklem: $X_1, \dots, X_n$ i.i.d.
- $\mu$ için: $\overline{X} = \frac{1}{n}\sum_{k=1}^{n} X_k$.
- $\sigma^2$ için: $S^2 = \frac{1}{n-1}\sum_{k=1}^{n} (X_k - \overline{X})^2$ (yansız).
- $\sigma$ için: $S = \sqrt{S^2}$ (yanlı ama kullanılır).
- Örnek: $18, 21, 17, 16, 24, 20$ → $\overline{T} = 19.33$, $S^2 = 8.67$, $S = 2.94$.
- NumPy: `np.var(t)` varsayılan olarak $1/n$ ile böler; örneklem varyansı için `ddof=1`.
- Kesikli: $L = P(X_1 = x_1, \dots, X_n = x_n) = \prod_{i=1}^{n} P_{X_i}(x_i)$.
- Sürekli: $L = f_{X_1 \dots X_n}(x_1, \dots, x_n) = \prod_{i=1}^{n} f_{X_i}(x_i)$.
- MLE: $\hat{\theta} = \arg\max L$; aday noktalar: $\frac{dL}{d\hat{\theta}} = 0$ çözümleri + sınır noktaları.
- $\log L = \sum_{i=1}^{n} \log P(x_i)$; burada $\log = \ln$.
- Poisson için MLE: $\hat{\lambda} = \overline{X}$.

## Detaylı Açıklamalar

- **Nokta tahmin ediciler.** Ders, tablet üzerinde el yazısıyla ve büyük ölçüde İngilizce anlatıldı. Bir örneklem, aynı dağılımdan gelen $X_1, X_2, \dots, X_n$ rastgele değişkenleri olarak düşünülür. Popülasyon ortalaması $\mu = E X$ için iyi bir tahmin edici daha önce öğrenilen örneklem ortalaması $\overline{X}$'tir (ekrandan, 00:35:00). Varyans için iyi bir tahmin edici örneklem varyansı $S^2$'dir. Hoca, formülde $1/n$ yerine $1/(n-1)$ bulunduğuna dikkat çekti: $1/n$ ile bölünen tahmin edici yanlıdır, $S^2$'yi yansız yapmak için $n-1$'e bölünür. <!-- BELİRSİZ: S^2'nin genel formülünün yazıldığı anın karesi yok; hoca "burada da 1/n değil" diyerek ikinci bir ifade daha gösterdi, bu ifade karelerden okunamadı. --> Standart sapma için varyansın karekökü alınır ve buna örneklem standart sapması denir (ekrandan, 00:40:00). $S$ yanlıdır; hoca kitaplarda yansız bir tahmin edicinin verilmediğini ve $S$'nin kabul edilebilir bir tahmin edici olduğunu söyledi.
- **Sayısal örnek.** $T$, bir fabrikadaki belirli bir işin tamamlanma süresidir ve ortalaması ile varyansı tahmin edilmek isteniyor. Altı gözlemlik rastgele örneklem $T_1, \dots, T_6$ i.i.d. ve değerleri $18, 21, 17, 16, 24, 20$'dir (ekrandan, 00:45:00). Örneklem ortalaması $\overline{T} = \frac{T_1 + \dots + T_6}{6} = \frac{116}{6} \approx 19.33$; örneklem varyansı $S^2 = \frac{1}{6-1}\sum_{k=1}^{6}(T_k - 19.33)^2 \approx 8.67$; örneklem standart sapması $S = \sqrt{S^2} \approx 2.94$ (ekrandan, 00:50:00). Değerler Python ile doğrulandı.
- **Python ile hesaplama.** Hoca bu hesapların pratikte programlama dilleriyle yapıldığını söyledi ve Python'da NumPy (bir doğrusal cebir paketi) ile şu adımları yazdı (ekrandan, 00:50:00): `import numpy as np`, `t = [18, 21, 17, 16, 24, 20]`, `mean_t = np.mean(t)`, `var_t = np.var(t, ddof=1)`. Standart sapma için varyansın karekökü (`np.sqrt`) alınır.
- **En çok olabilirlik kestirimi.** Ortalama ve varyans tahmini görüldükten sonra, bir dağılımın parametresinin tahmini ele alındı. Örneğin verinin Poisson dağılımına uyduğu biliniyorsa, $p(x) = e^{-\lambda}\frac{\lambda^x}{x!}$ ifadesindeki tek parametre $\lambda$ bulunduğunda bütün dağılım belirlenmiş olur (ekrandan, 00:55:00). Bunun için veri toplanır (gerçekte çok daha fazla veri istenir) ve $\lambda$ tahmin edilir.
- **Olabilirlik fonksiyonu.** Kesikli bir $X$ için olabilirlik, verinin gözlenme olasılığıdır: $L = P(X_1 = x_1, X_2 = x_2, \dots, X_n = x_n)$. $X_i$'ler i.i.d. olduğu için ortak olasılık tek tek olasılıkların çarpımına ayrılır: $L = \prod_{i=1}^{n} P_{X_i}(x_i)$ (ekrandan, 01:00:00). Sürekli durumda olasılıkların yerini ortak yoğunluk alır; bağımsızlık sayesinde o da marjinal yoğunlukların çarpımıdır: $L = \prod_{i=1}^{n} f_{X_i}(x_i)$.
- **Yöntemin kendisi.** Tahmin edilmek istenen parametre $\theta$, tahmin edicisi $\hat{\theta}$ ("theta şapka") ile gösterilir. MLE'de $\hat{\theta} = \arg\max_{\hat{\theta}} L$, yani olabilirliği en büyük yapan değerdir (ekrandan, 01:05:00). Analitik çözümde $\hat{\theta}$, $\frac{dL}{d\hat{\theta}} = 0$ için kritik noktalar listesindedir. Derste çizilen grafikte $[a, b]$ aralığında tanımlı bir olabilirlik eğrisi vardı: $c$'de minimum, $d$'de eyer noktası, $e$'de maksimum. Kritik noktalar $a$ ve $b$ (sınır noktaları; türev orada tanımlı olmayabilir ama yine de kontrol edilir) ile türevin sıfır olduğu $c, d, e$'dir (ekrandan, 01:10:00 ve 01:15:00). Bu adayların hangisinde olabilirliğin en büyük olduğu kontrol edilir.
- **Log-olabilirlik.** Olabilirlik yerine logaritması en büyüklenir. Grafikte $L$ ile $\log(L)$ eğrileri aynı noktada en büyük değerini alır ("still max."). $\prod$ içeren bir ifadenin türevi karmaşıktır; logaritma çarpımı toplama çevirir: $\log L = \sum_{i=1}^{n} \log P(x_i)$ ve türev her terim için ayrı alınır (ekrandan, 01:15:00 ve 01:20:00).
- **Poisson örneği.** $X \sim \text{Poisson}(\lambda)$, veri $6, 4, 2$. $L = \prod_{i=1}^{n} e^{-\lambda}\frac{\lambda^{x_i}}{x_i!}$ yazılır ve $\frac{d \log L}{d\hat{\lambda}} = 0$ çözülür (ekrandan, 01:20:00). Logaritma toplamın içine girince her terim $-\hat{\lambda} + x_i \log\hat{\lambda} - \log x_i!$ olur; $\log x_i!$ terimi $\hat{\lambda}$ içermediği için türevi sıfırdır (ekrandan, 01:30:00). Kalan ifade $-n\hat{\lambda} + \log\hat{\lambda}\sum x_i = -n\hat{\lambda} + n\overline{X}\log\hat{\lambda}$'dır; türevi $-n + \frac{n\overline{X}}{\hat{\lambda}} = 0$ verir. Buradan $\hat{\lambda} = \overline{X} = \frac{6+4+2}{3} = 4$ bulunur (ekrandan, 01:35:00). Hoca, $\lambda > 0$ olduğu için $\hat{\lambda} = 0$ ve $\hat{\lambda} = \infty$ sınırlarının da kontrol edilmesini alıştırma olarak bıraktı; bu sınırlarda olabilirliğin daha küçük olmasını beklediğini söyledi.
- **Ders sonrası not.** Hoca türev adımında önce $\sum x_i$ yerine $\overline{X}/n$ yazdı, sonra bunu $n\overline{X}$ olarak düzeltti (ekrandan, 01:30:00 ve 01:35:00). Düzeltme sırasında sözlü olarak "standard deviation" dedi; ekrandaki ve doğru ifade örneklem ortalaması $\overline{X}$'tir. Ayrıca kritik noktaları sayarken $c, d, e$ için sözlü olarak "boundary points" dedi; ekranda doğru olarak "$\frac{dL}{d\hat{\theta}} = 0$" olan noktalar diye yazılıdır.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
