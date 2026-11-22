# Ders 10 Çalışma Özeti

## Genel Konular

- Örneklem ortalaması (sample mean)
  - $X$ popülasyonundan toplanan örneklem kümesi $S = (X_1, X_2, \dots, X_n)$, $n = |S|$ toplam örnek sayısıdır. Örneklem ortalaması $\bar{X} = \dfrac{X_1 + X_2 + \dots + X_n}{n}$ diye tanımlanır (ekrandan, 00:10:00).
  - Örnekler bir rastgele değişkenden alındığı için her $X_i$ bir rastgele değişken gibi düşünülür; bu yüzden örneklem ortalaması rastgele değişkenlerin toplamıdır ve kendisi de bir rastgele değişkendir.
  - Sezgisel örnek: İstanbul'dan rastgele seçilen üç ayrı 1000 kişilik grubun ortalama ağırlığı 70 kg, 70,5 kg ve 68 kg çıkabilir. Ortalama $\bar{W}$ örneklem kümesinden örneklem kümesine değişir, yani bir dağılımı vardır (ekrandan, 00:15:00).
  - Merkezi limit teoremine dayanarak $\bar{X}$'in yaklaşık normal (Gauss) dağıldığı söylenir: $\bar{X} = \mu + \text{hata}$, hata sıfır ortalamalı Gauss rastgele değişkendir (ekrandan, 00:20:00).
- Ortalama kestiriminin özellikleri
  - Yansızlık (unbiasedness): kestirimin beklenen değeri gerçek değere eşittir. $E[\bar{X}] = \dfrac{E[X_1] + \dots + E[X_n]}{n} = \dfrac{n\mu}{n} = \mu$.
  - Tutarlılık (consistency): kestirim hatasının varyansı örnek sayısı sonsuza giderken sıfıra gider (ekrandan, 00:25:00). İspat Chebyshev eşitsizliğiyle yapılır.
  - $X_i$'ler bağımsız olduğundan $i \ne j$ için $\mathrm{Cov}(X_i, X_j) = 0$, $i = j$ için $\mathrm{Cov}(X_i, X_i) = \mathrm{Var}(X_i)$ (ekrandan, 00:30:00). Buradan $\mathrm{Var}(\bar{X}) = \dfrac{1}{n^2}\cdot n\sigma^2 = \dfrac{\sigma^2}{n}$.
  - Chebyshev: $\Pr(|\bar{X} - \mu| > \varepsilon) \le \dfrac{\mathrm{Var}(\bar{X})}{\varepsilon^2} = \dfrac{\sigma^2}{n\varepsilon^2} \to 0$; yani $\lim_{n\to\infty}\Pr(|\bar{X} - \mu| > \varepsilon) = 0$, "$n = \infty$ için $\bar{X} = \mu$" (ekrandan, 00:35:00).
  - Asimptotik normallik: örneklem büyüklüğü yeterince büyükse örneklem ortalamaları yaklaşık normal dağılır. Standartlaştırılmış $Z$ için $E[Z] = 0$, $\mathrm{Var}(Z) = E[Z^2] = 1$ gösterilir; $Z$, $n \to \infty$ iken standart normal dağılıma yakınsar (ekrandan, 00:40:00).
- Örneklem varyansı ve örneklem standart sapması
  - Amaç: $\mathrm{Var}(X) = \sigma^2$'yi yalnız $X_1, \dots, X_n$ verisinden kestirmek (ekrandan, 00:45:00).
  - Örneklem varyansı: $s^2 = \dfrac{1}{n-1}\sum_{i=1}^{n}(X_i - \bar{X})^2$ (1. denklem). Hoca $s^2$'yi "kestirilmiş (hatalı) varyans", $\bar{X}$'i "kestirilmiş (hatalı) ortalama" diye etiketledi (ekrandan, 00:50:00).
  - Eşdeğer biçim: $s^2 = \dfrac{1}{n-1}\sum_{i=1}^{n}X_i^2 - \dfrac{n}{n-1}\bar{X}^2$ (2. denklem). İkisinin eşitliğinin ispatı alıştırma olarak bırakıldı.
  - Özellikler: (i) yansız, $E[s^2] = \sigma^2$; (ii) tutarlı, $\lim_{n\to\infty}\Pr(|s^2 - \sigma^2| > \varepsilon) = 0$, yani hata sıfıra gider; (iii) hocaya göre $s^2$ ortalaması $\sigma^2$, varyansı $\Sigma^2$ olan Gauss dağılımı izler (ekrandan, 01:10:00).
  - Örneklem standart sapması: $s = \sqrt{s^2} = \sqrt{\dfrac{1}{n-1}\sum_{i=1}^{n}(X_i - \bar{X})^2}$; tutarlılık $\lim_{n\to\infty}\Pr(|s - \sigma| > \varepsilon) = 0$ (ekrandan, 01:15:00).
- Medyan (popülasyon medyanı)
  - Merkezi eğilim ve konum ölçüsüdür. $M$ sayısı için $\Pr(X > M) = \Pr(X < M)$ yazılır; $1 - \Pr(X < M) = \Pr(X < M)$ eşitliğinden $\Pr(X < M) = \tfrac{1}{2}$ çıkar (ekrandan, 01:20:00).
  - Sürekli rastgele değişkende bu $F_X(M) = \tfrac{1}{2}$ demektir; medyan CDF'nin tersiyle bulunur: $M = F_X^{-1}(1/2)$ (ekrandan, 01:25:00).
  - Örnek: ortalaması $\lambda = 2$ olan üstel dağılımda $f_X(x) = \tfrac{1}{2}e^{-x/2}$, $F_X(x) = 1 - e^{-x/\lambda}$, $M = \lambda\ln 2 = 2\ln 2 \approx 1{,}386$; medyanın solundaki ve sağındaki alanlar $A_1 = A_2 = \tfrac{1}{2}$ (ekrandan, 01:30:00).
- Örneklem medyanı
  - Veri büyüklüğüne göre sıralanır: $Y_1 < Y_2 < \dots < Y_n$ (ör. $Y_1 = X_3$, $Y_2 = X_1$). Örneklem medyanı $\hat{M}$, sıralı veriyi eşit büyüklükte iki kümeye bölen sayıdır (ekrandan, 01:40:00).
  - $n = 2k+1$ (tek) ise $\hat{M} = Y_{k+1}$.
  - $n = 2k$ (çift) ise $\hat{M}$, $Y_k$ ile $Y_{k+1}$ arasındaki herhangi bir sayı olabilir. Hocanın "en olası örneklem medyanı": $\hat{M} = \dfrac{(\#Y_k)\,Y_k + (\#Y_{k+1})\,Y_{k+1}}{(\#Y_k) + (\#Y_{k+1})}$; $\#Y_k$, değeri $Y_k$ olan örnek sayısıdır (ekrandan, 01:45:00).
  - Sayısal örnek: 15 değerlik veri $1,2,2,2,3,3,4,4,4,5,6,7,7,7,8$ için $\hat{M} = 4$ (ekrandan, 01:50:00). Çift sayıda veride ortadaki iki değer 4 ve 5, verideki 4 sayısı 2 ve 5 sayısı 3 iken $\hat{M} = (2\cdot 4 + 3\cdot 5)/5 = 4{,}6$.
- Kantil, yüzdelik ve dörttebirlikler (quantiles, percentiles, quartiles)
  - Bu ölçüler, belirli bir verinin örneklemin geri kalanına göre konumunu tanımlar (ekrandan, 02:15:00).
  - Popülasyonun $p$-kantili $x_p$: $X$'in $x_p$'den küçük olma olasılığı en fazla $p$, büyük olma olasılığı en fazla $1-p$ olan sayıdır; buradan $F_X(x_p) = p$, $x_p = F_X^{-1}(p)$.
  - Örneklem $p$-kantili: gözlemlerin en fazla $100p\%$'sini aşan ve gözlemlerin en fazla $100(1-p)\%$'si tarafından aşılan sayıdır (ekrandan, 02:20:00 ve 02:25:00).
  - PDF grafiğinde $x_p$'nin solundaki alan $p = F_X(x_p)$'dir (ekrandan, 02:25:00). Medyan $p = 1/2$ durumudur.

## Hocanın Özellikle Vurguladığı Kısımlar

- Örneklem ortalaması rastgele değişkenlerin toplamıdır
  - Farklı örneklem kümeleri farklı ortalama verir; bu yüzden $\bar{X}$'in bir dağılımı vardır. Hoca bunu "çok önemli" diye işaretledi.
- Tutarlılık ve Chebyshev eşitsizliği
  - Örnek sayısı arttıkça kestirim ile gerçek değer arasındaki farkın herhangi bir $\varepsilon$'dan büyük olma olasılığı sıfıra gider; hoca bunun önemini vurguladı.
- Asimptotik normallik
  - Örneklem büyüklüğünün "yeterince büyük" olması ve dağılımın "yaklaşık" normal olması koşulları ayrıca önemli diye belirtildi.
- Örneklem varyansının ikinci formülü
  - Hoca 2. denklemi tercih ettiğini söyledi: her değerden ortalamayı çıkarıp yeni bir veri oluşturmak yerine doğrudan kareler toplanır, hesap daha kolaydır. Literatürde genelde 1. denklemin kullanıldığını belirtti. İki formülün eşitliğini ispatlamak "çok iyi bir alıştırma" olarak verildi.
- Medyan CDF'nin tersiyle bulunur
  - $M = F_X^{-1}(1/2)$. Hoca üstel dağılımın PDF'sinin ezberlenmesi gerektiğini, yoksa problemin çözülemeyeceğini söyledi.
- Örneklem medyanı için önce veri sıralanır
  - Sıralama adımı önemli diye vurgulandı.

## Kısa Tekrar Notları

- $\bar{X} = \frac{1}{n}\sum X_i$; $E[\bar{X}] = \mu$ (yansız); $\mathrm{Var}(\bar{X}) = \sigma^2/n$.
- Tutarlılık: $\Pr(|\bar{X} - \mu| > \varepsilon) \le \sigma^2/(n\varepsilon^2) \to 0$.
- Merkezi limit teoremi: büyük $n$ için $\bar{X}$ yaklaşık normal; standartlaştırılmış değişken standart normale yakınsar.
- $s^2 = \frac{1}{n-1}\sum (X_i - \bar{X})^2 = \frac{1}{n-1}\sum X_i^2 - \frac{n}{n-1}\bar{X}^2$; $E[s^2] = \sigma^2$.
- $s = \sqrt{s^2}$ örneklem standart sapmasıdır.
- Medyan: $F_X(M) = 1/2$, $M = F_X^{-1}(1/2)$.
- Üstel dağılım ($E[X] = \lambda$): $F_X(x) = 1 - e^{-x/\lambda}$, $M = \lambda\ln 2$.
- Örneklem medyanı: tek $n = 2k+1$ için $Y_{k+1}$; çift $n = 2k$ için $Y_k$ ile $Y_{k+1}$ arasında.
- $p$-kantil: $F_X(x_p) = p$; medyan $0{,}5$-kantildir.

## Detaylı Açıklamalar

- **Örneklem ortalaması neden bir rastgele değişkendir?** Bir popülasyondan $n$ ölçüm alındığında elde edilen değerler sabit sayılardır, ama hangi değerlerin geleceği rastgeledir. Her ölçüm $X$ ile aynı dağılımlı bir rastgele değişken $X_i$ olarak düşünülür. İstanbul örneğinde üç farklı 1000 kişilik grup üç farklı ortalama (70, 70,5 ve 68 kg) verir. Bu yüzden $\bar{X}$ de bir rastgele değişkendir. Hoca $\bar{X}$'i "gerçek ortalama $\mu$ artı sıfır ortalamalı Gauss hata" diye modelledi.
- **Yansızlık ispatı:** Beklenen değerin doğrusallığı kullanılır: $E[\bar{X}] = \frac{1}{n}\sum_{i=1}^{n}E[X_i] = \frac{1}{n}\cdot n\mu = \mu$. Kestirimin beklenen değeri kestirilen gerçek değere eşit olduğu için $\bar{X}$, $\mu$'nün yansız kestiricisidir.
- **Tutarlılık ispatı:** Bağımsızlıktan dolayı çapraz kovaryans terimleri sıfırdır. Bu yüzden $\mathrm{Var}\big(\sum_i X_i/n\big) = \frac{1}{n^2}\sum_i \mathrm{Var}(X_i) = \frac{n\sigma^2}{n^2} = \frac{\sigma^2}{n}$. Chebyshev eşitsizliğine konunca $\Pr(|\bar{X} - \mu| > \varepsilon) \le \frac{\sigma^2}{n\varepsilon^2}$ olur; sağ taraf $n \to \infty$ iken sıfıra gider. Yani örnek sayısı arttıkça kestirimin gerçek değerden belirli bir miktardan fazla sapma olasılığı sıfırlanır.
- **Asimptotik normallik:** Merkezi limit teoremine göre örneklem büyüklüğü yeterince büyükse örneklem ortalaması yaklaşık normal dağılır. Hoca standartlaştırılmış $Z$ değişkeni tanımladı ve $E[Z] = 0$, $\mathrm{Var}(Z) = E[Z^2] - (E[Z])^2 = E[Z^2] = 1$ olduğunu gösterdi.
  - **Ders sonrası not:** Hoca $Z = (\bar{X} - \mu)/\sigma$ yazdı ve $E[(\bar{X} - \mu)^2] = \sigma^2$ aldı. Oysa aynı derste $\mathrm{Var}(\bar{X}) = \sigma^2/n$ bulundu; doğru standartlaştırma $Z = \dfrac{\bar{X} - \mu}{\sigma/\sqrt{n}}$'dir. Hoca standart normal PDF'sini de $\exp(-z^2/(2\sigma^2))$ ile söyledi; standart normalde $\sigma = 1$ olduğundan doğrusu $f_Z(z) = \frac{1}{\sqrt{2\pi}}e^{-z^2/2}$'dir. Benzer biçimde $\bar{X}$'in PDF'si ekranda varyans $\sigma^2$ ile yazıldı (ekrandan, 00:20:00); $\bar{X}$'in varyansı $\sigma^2/n$'dir.
- **Örneklem varyansı:** Gerçek ortalama bilinmediği için onun yerine kestirilmiş ortalama $\bar{X}$ kullanılır; bu yüzden hoca hem $\bar{X}$'i hem $s^2$'yi "hatalı" (erroneous) diye etiketledi. Bölende $n-1$ vardır. İkinci formülde fark terimleri oluşturulmaz, yalnız kareler toplamı ve ortalamanın karesi gerekir; hoca hesap kolaylığı için bunu tercih ediyor.
  - **Ders sonrası not:** Hoca önce yansızlığı "$\lim_{n\to\infty} s^2 = \sigma^2$" diye yazdı (ekrandan, 01:05:00), sonra yansızlığın $E[s^2] = \sigma^2$ olduğunu söyleyerek düzeltti. Doğrusu $E[s^2] = \sigma^2$'dir; limit ifadesi tutarlılıkla ilgilidir.
  - **Ders sonrası not:** Hoca $s^2$'nin Gauss dağılımı izlediğini söyledi. Popülasyon normal ise $(n-1)s^2/\sigma^2$ ki-kare dağılımı ($n-1$ serbestlik derecesi) izler; $s^2$ ancak büyük $n$ için yaklaşık normal kabul edilebilir.
  - **Ders sonrası not:** Hoca $s$'nin de yansız olduğunu söyledi (01:13:04). $s^2$ yansız olsa da $s = \sqrt{s^2}$ genelde yansız değildir; Jensen eşitsizliğinden $E[s] \le \sigma$ olur. $s$ tutarlıdır.
- **Medyan:** Medyan, olasılık kütlesini ikiye bölen noktadır. Sürekli rastgele değişkende $\Pr(X = M) = 0$ olduğundan $\Pr(X < M) = \Pr(X \le M) = F_X(M) = 1/2$ olur ve $M = F_X^{-1}(1/2)$ ile bulunur. Üstel dağılım örneğinde (hocanın parametrelemesiyle $f_X(x) = \frac{1}{\lambda}e^{-x/\lambda}$, $x \ge 0$, $E[X] = \lambda$) CDF $1 - e^{-x/\lambda}$'dır; $1 - e^{-M/\lambda} = 1/2$ denkleminden $M = \lambda\ln 2$ ve $\lambda = 2$ için $M = 2\ln 2 \approx 1{,}386$ bulunur (python ile doğrulandı). Medyan ortalamadan ($2$) küçüktür.
- **Örneklem medyanı:** Önce veri küçükten büyüğe sıralanır. Tek sayıda veride ortadaki eleman medyandır. Çift sayıda veride ortadaki iki değer eşitse medyan o değerdir; farklıysa hoca, bu iki değeri verideki tekrar sayılarıyla ağırlıklandırarak "en olası" medyanı hesapladı (4 ve 5 örneğinde 4,6).
- **Kantiller:** $p$-kantil $x_p$, CDF'nin $p$ değerini aldığı noktadır ($x_p = F_X^{-1}(p)$). Örneklem $p$-kantili, gözlemlerin en fazla $100p\%$'sinden büyük ve en fazla $100(1-p)\%$'sinden küçük olan sayıdır. Hoca bu konum ölçülerinin veri madenciliği, makine öğrenmesi ve çok değişkenli veri analizinde çok kullanıldığını söyledi.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
