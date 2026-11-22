# Ders 10 Genişletilmiş Notu: Örneklem Ortalaması, Örneklem Varyansı, Medyan ve Kantiller

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Örneklem ortalaması
- 2. Örneklem ortalamasının yansızlığı
- 3. Tutarlılık ve Chebyshev eşitsizliği
- 4. Asimptotik normallik
- 5. Örneklem varyansı ve örneklem standart sapması
- 6. Popülasyon medyanı
- 7. Örneklem medyanı
- 8. Kantiller, yüzdelikler ve dörttebirlikler
- Örnek Sorular

## 1. Örneklem ortalaması

Ders iPad üzerinde "BLM2011 Lecture Notes (2020 Fall)" başlıklı el yazısı not defteriyle yürütüldü; anlatım çoğunlukla İngilizce, yer yer Türkçe açıklamalarla yapıldı. Bir önceki derste parametre kestirimi (parameter estimation) konusuna girilmiş, parametre ve istatistik kavramları ile tutarlılık tanımı görülmüştü. Bu derse kalınan yerden, örneklem ortalamasından (sample mean) devam edildi. Hoca örneklem ortalamasını bir merkezi eğilim (central tendency) ölçüsü olarak tanıttı.

### 1.1 Tanım

Elimizde bir $X$ popülasyonundan toplanmış bir örneklem kümesi olsun (ekrandan, 00:10:00):

$$S = (X_1, X_2, \dots, X_n).$$

Bunlar aslında ölçümlerdir. $S$ kümesinin örneklem ortalaması

$$\bar{X} = \frac{X_1 + X_2 + \dots + X_n}{n}$$

ile tanımlanır. Burada $n = |S|$ toplam örnek sayısıdır, yani örneklem kümesinin büyüklüğüdür.

Hoca örnekleri neden büyük harfle, yani rastgele değişken olarak yazdığını açıkladı: bu değerler bir rastgele değişkenden alınmış örneklerdir. Örnekler alındıktan sonra elbette sabit sayılardır, ama hangi değerlerin geleceği rastgeledir; bu yüzden her biri bir rastgele değişken gibi düşünülür. Ekrandaki vurgu şuydu: "Sample mean can be considered as the sum of random variables." (ekrandan, 00:10:00)

### 1.2 Sezgisel örnek: üç grubun ortalama ağırlığı

Hoca bu fikri bir örnekle anlattı (ekrandan, 00:15:00). İstanbul'da yaşayan insanlardan rastgele 1000 kişi alınsın ve ortalama ağırlıkları hesaplansın; 70 kg çıksın. Başka bir 1000 kişi alındığında ortalama 70,5 kg, üçüncü bir 1000 kişilik grupta 68 kg çıkabilir. Üç grubun hepsi İstanbul'da yaşayan insanlardan oluşur, toplam 3000 kişi vardır. Ortalama ağırlık $\bar{W}$ her 1000 kişilik grupta değişir. Yani örneklem ortalaması örneklem kümesine göre değişir; bu yüzden örneklem ortalamasının kendisi de bir dağılım izler.

### 1.3 Örneklem ortalamasının dağılımı

Hoca, bağımsız rastgele değişkenlerin toplamının Gauss (normal) dağılımla yaklaşıklanabildiğini hatırlattı. Buna göre örneklem ortalaması ortalaması $\mu$ ve varyansı $\sigma^2$ olan bir Gauss dağılımı izler diye yazdı ve şöyle modelledi (ekrandan, 00:20:00):

$$\bar{X} = \mu + \text{hata},$$

burada hata sıfır ortalamalı bir Gauss rastgele değişkendir (zero-mean Gaussian RV). Ekranda $\bar{X}$'in PDF'si şöyle yazıldı:

$$f_{\bar{X}}(x) = \frac{1}{\sqrt{2\pi\sigma^2}}\exp\!\left(-\frac{(x-\mu)^2}{2\sigma^2}\right).$$

Amaç $\mu$'yü belirlemek, yani kestirmektir; $\bar{X}$, $\mu$'nün kestirimidir.

> **Ders sonrası not:** Merkezi limit teoremi "herhangi bağımsız" rastgele değişkenlerin toplamı için değil, tipik olarak aynı dağılımlı, sonlu varyanslı bağımsız değişkenler için ve büyük $n$'de yaklaşık olarak geçerlidir. Ayrıca aşağıda (Bölüm 3) gösterildiği gibi $\mathrm{Var}(\bar{X}) = \sigma^2/n$'dir; ekrandaki PDF'de varyans yerine $\sigma^2/n$ yazılmalıdır.

## 2. Örneklem ortalamasının yansızlığı

Hoca önce $\bar{X}$'in beklenen değerini hesapladı. Beklenen değerin doğrusallığından:

$$E[\bar{X}] = E\!\left[\frac{X_1 + X_2 + \dots + X_n}{n}\right] = \frac{E[X_1] + E[X_2] + \dots + E[X_n]}{n}.$$

Her $X_i$ aynı popülasyondan geldiği için $E[X_i] = \mu$'dür. Payda $n$ tane $\mu$ vardır:

$$E[\bar{X}] = \frac{n\mu}{n} = \mu.$$

Bu sonuç yansızlık (unbiasedness) demektir. Hocanın tanımıyla yansızlık, kestirimin beklenen değerinin gerçek (exact) değere eşit olmasıdır. Burada $E[\bar{X}] = \mu$ olduğu için $\bar{X}$, $\mu$'nün yansız bir kestiricisidir.

## 3. Tutarlılık ve Chebyshev eşitsizliği

### 3.1 Tanım

Ekrandaki tanım (ekrandan, 00:25:00): bir kestirimin tutarlılığı (consistency), kestirim hatasının varyansının örnek sayısı sonsuza giderken sıfıra gitmesiyle ilgilidir. Hoca kestirim hatasını $\bar{X} - \mu$ diye gösterdi: $\bar{X}$ kestirim, $\mu$ gerçek değer, aradaki fark kestirim hatasıdır. İspat için Chebyshev eşitsizliği kullanılır:

$$\Pr\big(|\bar{X} - \mu| > \varepsilon\big) \le \frac{\mathrm{Var}(\bar{X})}{\varepsilon^2}.$$

### 3.2 Örneklem ortalamasının varyansı

Örnekler bağımsızdır: $i \ne j$ için $X_i$ ve $X_j$ bağımsızdır. Bu yüzden (ekrandan, 00:30:00)

$$\mathrm{Cov}(X_i, X_j) = 0 \quad (i \ne j), \qquad \mathrm{Cov}(X_i, X_j) = \mathrm{Var}(X_i) \quad (i = j).$$

Hoca varyansı tanımdan açtı: $\mathrm{Var}(\bar{X}) = E\big[(\bar{X} - E[\bar{X}])^2\big] = E\big[(\sum_i X_i/n - \mu)^2\big]$. Bu kare açıldığında $i = j$ terimleri (karesel terimler) ile $i \ne j$ çapraz terimleri çıkar. Çapraz terimlerin beklenen değeri kovaryanstır ve bağımsızlıktan sıfırdır; geriye yalnız varyans terimleri kalır (ara adımlar düzenlendi):

$$\mathrm{Var}(\bar{X}) = \frac{1}{n^2}\sum_{i=1}^{n}\mathrm{Var}(X_i) = \frac{1}{n^2}\cdot n\sigma^2 = \frac{\sigma^2}{n}.$$

Hoca tahtada açılımı yaparken $\mu$'nün yerini birkaç kez düzeltti; sonuç olarak her $\mathrm{Var}(X_i) = \sigma^2$ olduğu için $n\sigma^2/n^2 = \sigma^2/n$ elde edildi.

### 3.3 Sonuç

Chebyshev eşitsizliğine konunca:

$$\Pr\big(|\bar{X} - \mu| > \varepsilon\big) \le \frac{\sigma^2}{n\varepsilon^2}.$$

Sağ taraf $n \to \infty$ iken sıfıra gider. Dolayısıyla (ekrandan, 00:35:00)

$$\lim_{n\to\infty}\Pr\big(|\bar{X} - \mu| > \varepsilon\big) = 0,$$

ekrandaki ifadeyle "which means that we have $\bar{X} = \mu$ for $n = \infty$". Hoca bunu şöyle yorumladı: örnek sayısı arttıkça kestirim ile gerçek değer arasındaki farkın herhangi bir $\varepsilon$ değerinden büyük olma olasılığı sıfıra iner. Buna göre $\mu$'nün kestirimi olan $\bar{X}$ tutarlıdır.

> **Hocanın vurgusu:** Bu sonuç "çok önemli" diye belirtildi: örnek sayısını artırmak kestirim hatasının büyük olma olasılığını sıfıra götürür.

## 4. Asimptotik normallik

Merkezi limit teoremine göre, örneklem büyüklüğü $n$ yeterince büyükse örneklem ortalamaları yaklaşık normal dağılır. Hoca iki koşulun altını çizdi: örneklem büyüklüğünün "yeterince büyük" olması ve dağılımın "yaklaşık" normal olması.

> **Hocanın vurgusu:** "Sufficiently large" ve "approximately normal" ifadeleri ayrı ayrı önemli diye işaretlendi.

Hoca yeni bir rastgele değişken tanımladı:

$$Z = \frac{\bar{X} - \mu}{\sigma}.$$

$Z$'nin beklenen değeri (ekrandan, 00:40:00):

$$E[Z] = \frac{E[\bar{X}] - \mu}{\sigma} = \frac{\mu}{\sigma} - \frac{\mu}{\sigma} = 0.$$

Varyansı için $\mathrm{Var}(Z) = E[Z^2] - (E[Z])^2$ yazıldı; $E[Z] = 0$ olduğundan $\mathrm{Var}(Z) = E[Z^2]$, yani ikinci moment olur. $E[Z^2] = \frac{1}{\sigma^2}E[(\bar{X} - \mu)^2]$; hoca $E[(\bar{X} - \mu)^2]$'yi $\sigma^2$ alarak $\mathrm{Var}(Z) = 1$ buldu. Sonra $Z$'nin PDF'sini standart normal yoğunluğu olarak yazdı ve $-\infty < z < \infty$ dedi. Sonuç: $Z$, $n \to \infty$ iken standart normal dağılıma yakınsar. Hoca bunu da çok önemli bir sonuç olarak belirtti.

> **Ders sonrası not:** Hoca $Z = (\bar{X} - \mu)/\sigma$ yazdı ve $E[(\bar{X} - \mu)^2] = \sigma^2$ aldı. Oysa Bölüm 3'te $\mathrm{Var}(\bar{X}) = \sigma^2/n$ bulundu. Varyansı 1 olan standartlaştırma $Z = \dfrac{\bar{X} - \mu}{\sigma/\sqrt{n}}$'dir. Hoca PDF'yi sözlü olarak $\exp\big(-z^2/(2\sigma^2)\big)$ ile söyledi; standart normalin PDF'si $f_Z(z) = \frac{1}{\sqrt{2\pi}}e^{-z^2/2}$'dir.

## 5. Örneklem varyansı ve örneklem standart sapması

### 5.1 Amaç

Ortalama kestiriminden sonra varyans ve standart sapma kestirimine geçildi (ekrandan, 00:45:00). Yine $S = (X_1, \dots, X_n)$ örnekleri vardır. Teorik varyans $\mathrm{Var}(X) = \sigma^2$'dir. Amaç, $\sigma^2$'yi yalnız $X$'ten toplanmış $X_1, X_2, \dots, X_n$ verisiyle kestirmektir. Bu kestirim örneklem varyansı (sample variance) diye adlandırılır ve küçük $s^2$ ile gösterilir.

### 5.2 İki formül

Ekrandaki birinci formül (ekrandan, 00:50:00):

$$s^2 = \frac{1}{n-1}\sum_{i=1}^{n}\big(X_i - \bar{X}\big)^2 \qquad (1)$$

Hoca terimleri etiketledi: $X_i$'ler örneklerdir, $\bar{X}$ kestirilmiş ortalamadır, $s^2$ kestirilmiş varyanstır. Gerçek ortalama elimizde olmadığı için kestirilmiş ortalama kullanılır; bu yüzden ikisine de "hatalı" (erroneous mean, erroneous variance) dedi. Gerçek ortalamayı ve gerçek varyansı bilmiyoruz, ama değerlerini bulmaya çalışıyoruz.

İkinci formül:

$$s^2 = \frac{1}{n-1}\sum_{i=1}^{n}X_i^2 - \frac{n}{n-1}\bar{X}^2 \qquad (2)$$

Ekranda "Prove that (1) is equal to (2)" yazıldı; ispat alıştırma olarak bırakıldı (bkz. Örnek Sorular).

Hoca ikinci formülü neden tercih ettiğini Türkçe anlattı. Birinci formülde her değerden ortalama çıkarılır, karesi alınır, toplanır ve $n-1$'e bölünür; yani $X_i - \bar{X}$ biçiminde üçüncü bir veri oluşturulur. İkincisinde her değerin doğrudan karesi alınır, toplanır, $n-1$'e bölünür ve $\frac{n}{n-1}\bar{X}^2$ çıkarılır; hesap çok daha basittir. Hoca literatürde ve internette genelde birinci formülün kullanıldığını, kendisinin ise hesaplaması kolay olduğu için ikinciyi kullandığını söyledi.

> **Hocanın vurgusu:** İki formülün eşitliğini kendiniz ispatlayın; "çok iyi bir alıştırma".

### 5.3 Özellikler

Aradan sonra hoca $s^2$'nin özelliklerini sıraladı (ekrandan, 01:05:00 ve 01:10:00):

- Yansız: $E[s^2] = \sigma^2$.
- Tutarlı: $\lim_{n\to\infty}\Pr\big(|s^2 - \sigma^2| > \varepsilon\big) = 0$. Kestirilmiş varyans ile gerçek varyans arasındaki farkın bir $\varepsilon$ değerinden büyük olma olasılığı sıfıra gider; örnek sayısı arttıkça hata sıfır olur (error = 0).
- Hocaya göre $s^2$ Gauss dağılımı izler: $E[s^2] = \sigma^2$, $\mathrm{Var}(s^2) = \Sigma^2$ ve

$$f_{s^2}(u) = \frac{1}{\sqrt{2\pi\Sigma^2}}\exp\!\left(-\frac{(u - \sigma^2)^2}{2\Sigma^2}\right), \qquad -\infty < u < \infty.$$

Ekranda bu "The PDF of the variance estimation" diye adlandırıldı. Hoca değişken adı olarak $u$'yu seçti, çünkü $s$ ve $\sigma$ zaten kullanılıyordu.

> **Ders sonrası not:** Hoca yansızlığı önce ekranda "$\lim_{n\to\infty} s^2 = \sigma^2$" diye yazdı (ekrandan, 01:05:00), sonra sözlü olarak yansızlığın $E[s^2] = \sigma^2$ olduğunu söyleyerek düzeltti. Doğrusu $E[s^2] = \sigma^2$'dir; limitli ifade tutarlılığa aittir.

> **Ders sonrası not:** $s^2$ tam olarak Gauss dağılmaz. Popülasyon normal ise $(n-1)s^2/\sigma^2$, $n-1$ serbestlik dereceli ki-kare dağılımı izler; $s^2$ ancak büyük $n$ için yaklaşık normal sayılabilir. Ayrıca $s^2 \ge 0$ olduğundan $u$ aslında $(-\infty, \infty)$ aralığında değil, $[0, \infty)$ aralığındadır.

### 5.4 Örneklem standart sapması

Örneklem standart sapması $s$ ile gösterilir ve örneklem varyansının kareköküdür:

$$s = \sqrt{s^2} = \sqrt{\frac{1}{n-1}\sum_{i=1}^{n}\big(X_i - \bar{X}\big)^2} = \sqrt{\frac{1}{n-1}\sum_{i=1}^{n}X_i^2 - \frac{n}{n-1}\bar{X}^2}.$$

Bu, standart sapmanın kestirimidir. Hoca $s$'nin yansız ve tutarlı olduğunu söyledi; tutarlılık (ekrandan, 01:15:00):

$$\lim_{n\to\infty}\Pr\big(|s - \sigma| > \varepsilon\big) = 0.$$

Ekranda "Prove these by yourself" yazıldı; ispatlar öğrencilere bırakıldı.

> **Ders sonrası not:** Hoca $s$'nin de yansız olduğunu söyledi (01:13:04). $s^2$ yansız olsa da karekök doğrusal olmadığından $s$ genelde yansız değildir; Jensen eşitsizliğinden $E[s] \le \sigma$ olur. $s$ tutarlıdır, yani büyük $n$'de bu sapma kaybolur.

## 6. Popülasyon medyanı

### 6.1 Tanım

Medyan, merkezi eğilim ve konum (position) ölçüsüdür. Hoca popülasyon medyanını, $X$'in $M$'den büyük olma olasılığı ve küçük olma olasılığı en fazla $1/2$ olacak biçimde tanımlanan $M$ sayısı olarak verdi. Bu iki koşuldan ekranda şu sonuç çıkarıldı (ekrandan, 01:20:00):

$$\Pr(X > M) = \Pr(X < M) \;\Rightarrow\; 1 - \Pr(X < M) = \Pr(X < M) \;\Rightarrow\; 1 = 2\Pr(X < M) \;\Rightarrow\; \Pr(X < M) = \tfrac{1}{2}.$$

<!-- BELİRSİZ: Tanımdaki eşitsizliklerin yönü altyazıda karışık okunuyor ("less than half", "greater than half" düzeltmeleri); karede yalnız sonuç satırları görünüyor. -->

Hoca CDF tanımını hatırlattı: $F_X(x) = \Pr(X \le x)$, yani rastgele değişkenin küçük bir $x$ değerinden küçük ya da eşit olma olasılığı. Sürekli rastgele değişkende "küçük" ile "küçük eşit" arasında fark yoktur. Böylece medyan

$$F_X(M) = \frac{1}{2} \quad\Rightarrow\quad M = F_X^{-1}\!\left(\tfrac{1}{2}\right)$$

ile bulunur. Ekrandaki ifade: "We can find the median by inverse of the CDF." (ekrandan, 01:25:00)

> **Hocanın vurgusu:** Medyanı bulmak için CDF'nin tersi alınır; bu önemli diye belirtildi.

### 6.2 Örnek: üstel dağılımın medyanı

Ekranda "Example: Let $X$ be an exponential distribution with $\lambda$" yazıldı (ekrandan, 01:25:00). Ortalaması $\lambda = 2$ olan üstel dağılımlı $X$'in medyanı istendi.

Verilen: hocanın parametrelemesiyle PDF

$$f_X(x) = \frac{1}{\lambda}e^{-x/\lambda}, \qquad 0 \le x < \infty,$$

ve $E[X] = \lambda = 2$. Hoca bu PDF'nin ezberlenmesi gerektiğini, yoksa problemin çözülemeyeceğini söyledi.

Adım 1, CDF: tanım gereği PDF'nin integralidir.

$$F_X(x) = \int_0^x \frac{1}{\lambda}e^{-t/\lambda}\,dt = 1 - e^{-x/\lambda}, \qquad 0 \le x < \infty.$$

Adım 2, medyan denklemi: $F_X(M) = 1/2$.

$$1 - e^{-M/\lambda} = \frac{1}{2} \;\Rightarrow\; e^{-M/\lambda} = \frac{1}{2} \;\Rightarrow\; -\frac{M}{\lambda} = -\ln 2 \;\Rightarrow\; M = \lambda\ln 2.$$

Adım 3, sayısal değer: $\lambda = 2$ için $M = 2\ln 2 \approx 1{,}386$ (python ile doğrulandı).

Hoca sonucu grafikle gösterdi (ekrandan, 01:30:00): $f_X(x) = \frac{1}{2}e^{-x/2}$ eğrisi $x = 0$'da $1/2$ değerinden başlayıp azalır. $M = 2\ln 2$ noktasının solundaki alan $A_1$ (yeşil), sağındaki alan $A_2$ (kırmızı) olarak taralandı ve

$$A_1 = A_2 = \frac{1}{2}$$

yazıldı.

> **Ek bilgi (derste anlatılmadı):** Üstel dağılım çoğu kaynakta oran parametresiyle $f_X(x) = \lambda e^{-\lambda x}$ biçiminde yazılır; o zaman $E[X] = 1/\lambda$ ve medyan $\ln 2/\lambda$ olur. Hocanın kullandığı biçimde $\lambda$ ortalamanın kendisidir. Üstel dağılım sağa çarpık olduğundan medyan ($\lambda\ln 2 \approx 0{,}693\lambda$) ortalamadan ($\lambda$) küçüktür.

## 7. Örneklem medyanı

### 7.1 Tanım

Hoca "Can we estimate the median from samples?" sorusuyla gerçek medyanın, $X$ popülasyonundan toplanan örneklerden nasıl kestirileceğine geçti. Örneklem medyanı $\hat{M}$ ile gösterilir ve gözlemlerin en fazla yarısını aşan, en fazla yarısı tarafından aşılan sayıdır.

Önce veri büyüklüğüne göre sıralanır. Hoca "data" kelimesinin çoğul olduğunu not ederek "sıralıyoruz" diye Türkçe açıkladı. Sıralanmış veri $Y_1 < Y_2 < \dots < Y_n$ ile gösterilir; örneğin $Y_1 = X_3$, $Y_2 = X_1$, $Y_3 = X_{10}$, $Y_n = X_2$ olabilir.

Ekrandaki tanım (ekrandan, 01:40:00): sıralı veri $Y_1 < Y_2 < \dots < Y_n$ kullanılarak örneklem medyanı, veri kümesini aynı büyüklükte iki kümeye bölen sayıdır.

- $n = 2k + 1$ ise (örnek sayısı tek), $\hat{M} = Y_{k+1}$; yani sıralamada $k+1$'inci değer.
- $n = 2k$ ise (örnek sayısı çift), $\hat{M}$, $Y_k$ ile $Y_{k+1}$ arasındaki herhangi bir sayı olabilir.

### 7.2 En olası örneklem medyanı

Çift sayıda örnek için hoca bir "en olası" (most probable) örneklem medyanı formülü verdi. $\#Y_k$, değeri $Y_k$'ye eşit olan örnek sayısını göstermek üzere (ekrandan, 01:45:00):

$$\hat{M} = \frac{(\#Y_k)\,Y_k + (\#Y_{k+1})\,Y_{k+1}}{(\#Y_k) + (\#Y_{k+1})}.$$

Yani ortadaki iki değer, verideki tekrar sayılarıyla ağırlıklandırılarak ortalanır.

> **Ek bilgi (derste anlatılmadı):** Ders kitaplarında ve yazılımlarda çift $n$ için yaygın uzlaşı ortadaki iki değerin basit ortalamasıdır: $\hat{M} = (Y_k + Y_{k+1})/2$. Hocanın ağırlıklı formülü bu yaygın tanımdan farklıdır; sınavda hangi tanımın beklendiğine dikkat etmek gerekir.

### 7.3 Sayısal örnek

Hoca öğrencilerden 0 ile 10 arasında tam sayılar söylemelerini istedi ve veri kümesini birlikte oluşturdu. Sıralama sırasında bir öğrenci verideki 7'lerin sayısını düzeltti. Ekranda sonunda şu küme yer aldı (ekrandan, 01:50:00):

$$S = (2, 5, 4, 7, 2, 3, 4, 4, 6, 7, 1, 2, 3, 7, 8).$$

Sıralanmış hali:

$$1, 2, 2, 2, 3, 3, 4, 4, 4, 5, 6, 7, 7, 7, 8.$$

Adımlar:

- Örnek sayısı $n = 15 = 2\cdot 7 + 1$, tektir; $k = 7$.
- Ortadaki eleman $Y_8$'dir: solunda 7, sağında 7 eleman kalır.
- $Y_8 = 4$, yani $\hat{M} = 4$ (python ile doğrulandı).

Hoca sonra çift sayıda veri örneği için kümeden 8, 1 ve 2 değerlerini sildi ve 12 elemanlı bir küme elde etti. Ortadaki iki değer 4 ve 4 olduğunda medyan doğrudan 4'tür, çünkü iki değerin arası yine 4'tür. Daha sonra bazı değerleri 5 yaparak ortadaki iki değeri 4 ve 5'e çevirdi. Bu durumda medyan 4 ile 5 arasındadır ve en olası değer formülle hesaplanır. Verideki 4 sayısı 2, 5 sayısı 3 olduğunda:

$$\hat{M} = \frac{2\cdot 4 + 3\cdot 5}{2 + 3} = \frac{23}{5} = 4{,}6.$$

<!-- BELİRSİZ: Değiştirilen 12 elemanlı kümenin son hali karelerde yok; altyazıda "6 is 5", "one 4 is also 5" gibi parçalı ifadeler var. 4 ve 5 sayıları (2 ve 3) 4,6 sonucundan ve altyazıdaki "exactly" onayından çıkarıldı. -->

Ekrandaki sonuç: medyan 4 ile 5 arasındadır ve 4,6, örneklem medyanı $\hat{M}$'nin en olası değeridir (ekrandan, 01:55:00). Hoca konunun "çok basit" olduğunu söyledi.

## 8. Kantiller, yüzdelikler ve dörttebirlikler

### 8.1 Adlandırma

İkinci aradan sonra kantiller (quantiles), yüzdelikler (percentiles) ve dörttebirlikler (quartiles) konusuna geçildi. Hoca "-tile" ekini Türkçe açıkladı: desen gibi bir anlamı vardır. Kuanta Türkçede de kullanılır (kuantalama; birinci, ikinci, üçüncü kuanta); "percentile" yüzde deseni, "quartile" ise "quarta = dört" olduğundan dörtlü desen demektir. Bunlar histogramın ya da örneklerin desenleridir ve konumla ilgilidir.

Ekrandaki tanım (ekrandan, 02:15:00): bu ölçüler (kantiller, yüzdelikler ve dörttebirlikler), belirli bir verinin örneklemin geri kalanına göre konumunu tanımlamak için kullanılır.

### 8.2 Popülasyon $p$-kantili

Bir popülasyonun $p$-kantili, $X$'in bu sayıdan küçük olma olasılığı en fazla $p$ ve büyük olma olasılığı en fazla $1 - p$ olan bir $x$ sayısıdır. Hoca ikinci koşulu $1 - \Pr(X \le x)$ biçiminde yazıp iki eşitsizlikten

$$\Pr(X \le x_p) = F_X(x_p) = p \quad\Rightarrow\quad x_p = F_X^{-1}(p)$$

sonucunu çıkardı. Bu değere $p$-kantil denir (ekrandan, 02:20:00). Medyan, $p = 1/2$ alınan özel durumdur.

<!-- BELİRSİZ: Popülasyon p-kantilinin eşitsizlikleri altyazıda parçalı; karede yalnız tanımın başı ve "This value is called the p-quantile" satırı görünüyor. -->

### 8.3 Örneklem $p$-kantili

Ekrandaki soru: "How to estimate the $p$-quantile from the samples (data) collected from the same population?" (ekrandan, 02:20:00). Tanım (ekrandan, 02:25:00): örneklem $p$-kantili, gözlemlerin en fazla $100p\%$'sini aşan ve gözlemlerin en fazla $100(1-p)\%$'si tarafından aşılan sayıdır. Hoca $100p$ ifadesindeki işlemin çarpma olduğunu ayrıca belirtti ("multiplication of 100 by $p$").

Hoca bir PDF grafiği çizdi (ekrandan, 02:25:00): $f_X(x)$ eğrisinin altında $x_p$ noktasının solundaki alan taralandı ve

$$\text{Alan} = p = F_X(x_p)$$

yazıldı. Hoca gösterimi değiştirerek bu noktaya $x_p$ dedi ve "$x_p$ is a $p$-quantile of $X$" diye bitirdi. Ders bu noktada sona erdi.

> **Ek bilgi (derste anlatılmadı):** Yüzdelikler $p$'nin yüzde olarak verildiği kantillerdir (ör. 90. yüzdelik $= 0{,}90$-kantil). Dörttebirlikler $p = 0{,}25$, $0{,}50$ ve $0{,}75$ kantilleridir; ikinci dörttebirlik medyandır.

Hoca dersin sonunda bu konum ölçülerinin (percentiles, quantiles, quartiles) veri madenciliği, makine öğrenmesi ve çok değişkenli veri analizinde çok kullanılan araçlar olduğunu söyledi.

## Örnek Sorular

**Soru 1** (ekrandan, 00:50:00): Örneklem varyansının iki formülünün eşit olduğunu ispatlayın:

$$\frac{1}{n-1}\sum_{i=1}^{n}\big(X_i - \bar{X}\big)^2 = \frac{1}{n-1}\sum_{i=1}^{n}X_i^2 - \frac{n}{n-1}\bar{X}^2.$$

> **Çözüm (derste verilmedi):** Kare açılır: $\sum_{i}(X_i - \bar{X})^2 = \sum_i X_i^2 - 2\bar{X}\sum_i X_i + n\bar{X}^2$. $\sum_i X_i = n\bar{X}$ olduğundan orta terim $-2n\bar{X}^2$ olur ve toplam $\sum_i X_i^2 - n\bar{X}^2$'ye iner. İki taraf $n-1$'e bölünürse ikinci formül çıkar. Eşitlik rastgele bir veri kümesiyle python'da da kontrol edildi.

**Soru 2** (ekrandan, 01:25:00): Ortalaması $\lambda = 2$ olan üstel dağılımlı $X$'in medyanını bulun.

> **Çözüm:** $F_X(x) = 1 - e^{-x/\lambda}$; $F_X(M) = 1/2$ denkleminden $M = \lambda\ln 2 = 2\ln 2 \approx 1{,}386$.

**Soru 3** (ekrandan, 01:50:00): $S = (2, 5, 4, 7, 2, 3, 4, 4, 6, 7, 1, 2, 3, 7, 8)$ verisinin örneklem medyanı nedir?

> **Çözüm:** Sıralı veri $1, 2, 2, 2, 3, 3, 4, 4, 4, 5, 6, 7, 7, 7, 8$; $n = 15 = 2\cdot 7 + 1$ olduğundan $\hat{M} = Y_8 = 4$.

**Soru 4** (derste sözlü, 01:52:20): Çift sayıda örnekte ortadaki iki değer 4 ve 5, verideki 4 sayısı 2 ve 5 sayısı 3 ise en olası örneklem medyanı nedir?

> **Çözüm:** $\hat{M} = (2\cdot 4 + 3\cdot 5)/(2 + 3) = 4{,}6$.

**Soru 5** (derste sözlü, 03:00:14; quiz sonrası tartışma): Verilen bir PDF'de bilinmeyen $a$ parametresi ne olmalıdır?

> **Çözüm (derste sözlü):** PDF'nin altındaki alan 1 olmalıdır; PDF $-1$'den $1$'e integre edilip 1'e eşitlenir. Öğrenciler $a = 2$ bulduklarını söyledi, hoca da doğru dedi.

<!-- BELİRSİZ: PDF'nin tam ifadesi ekranda gösterilmedi; altyazıda yalnız "x üzeri a" ve "-1'den 1'e integral" geçiyor. Bu yüzden a = 2 sonucu bağımsız olarak doğrulanamadı. -->

**Soru 6** (derste sözlü, 03:01:22; quiz sonrası tartışma): Verilen bir ortak CDF geçerli (valid) bir CDF midir?

> **Çözüm (derste sözlü):** $y \to \infty$ iken ortak CDF $F_X(x)$'i, $x \to \infty$ iken $F_Y(y)$'yi vermelidir. Verilen fonksiyonda bu sağlanmıyor ve yoğunluğun altındaki alan 1'den büyük çıkıyordu; bu yüzden geçerli değildir.

<!-- BELİRSİZ: Fonksiyonun ifadesi ekranda gösterilmedi. -->

**Soru 7** (derste sözlü, 03:02:12; quiz sonrası tartışma): Sürekli bir rastgele değişken için $\Pr(X = 1)$ nedir?

> **Çözüm (derste sözlü):** Sürekli rastgele değişkenin tek bir noktayı alma olasılığı sıfırdır; $\Pr(X = 1) = 0$.

**Soru 8** (derste sözlü, 03:03:18; quiz sonrası tartışma): $X$ ortalaması 20, varyansı 25 olan bir rastgele değişkendir. Aşağıdakilerden hangisi doğrudur?

> **Çözüm (derste sözlü):** Hoca bu sorunun Chebyshev eşitsizliğiyle çözüldüğünü söyledi: $\Pr(|X - 20| \ge d) \le 25/d^2$.

<!-- BELİRSİZ: Seçenekler okunmadı ve ekranda gösterilmedi. Quizde ayrıca bir ortak dağılımda XY çarpımının beklenen değeri ve p = 0,1 olan bir binom dağılımı sorusu olduğu söylendi; ayrıntıları kayıtta yok. -->

## Dersin Toparlaması

Bu derste parametre kestirimi konusu, örneklemden hesaplanan istatistiklerle sürdürüldü. Örneklem ortalaması $\bar{X}$ rastgele değişkenlerin toplamı olarak ele alındı; $\mu$'nün yansız ($E[\bar{X}] = \mu$) ve tutarlı ($\mathrm{Var}(\bar{X}) = \sigma^2/n \to 0$, Chebyshev ile) kestiricisi olduğu gösterildi ve merkezi limit teoremiyle büyük örneklemde yaklaşık normal dağıldığı söylendi. Ardından örneklem varyansının iki eşdeğer formülü, yansızlığı ve tutarlılığı, örneklem standart sapması verildi. Konum ölçülerinde popülasyon medyanı CDF'nin tersiyle ($M = F_X^{-1}(1/2)$) tanımlandı, üstel dağılımda $M = \lambda\ln 2$ bulundu; örneklem medyanı sıralı veriden tek ve çift $n$ için hesaplandı.

Dersin son kısmında kantil kavramı tanıtıldı: popülasyon $p$-kantili $x_p = F_X^{-1}(p)$ ve örneklem $p$-kantili. Hoca yüzdelikler ve dörttebirliklerle devam edileceğini, bu araçların veri madenciliği ve makine öğrenmesinde çok kullanıldığını belirtti.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
