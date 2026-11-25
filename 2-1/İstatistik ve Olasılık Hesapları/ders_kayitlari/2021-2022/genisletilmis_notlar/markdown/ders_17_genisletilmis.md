# Ders 17 Genişletilmiş Notu: Ortalama ve Varyans için Nokta Tahmin Ediciler ve En Çok Olabilirlik Kestirimi

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Ortalama ve Varyans için Nokta Tahmin Ediciler
- 2. Sayısal Örnek: İş Tamamlanma Süresi
- 3. Python ile Hesaplama
- 4. En Çok Olabilirlik Kestirimi: Problem
- 5. Olabilirlik Fonksiyonu
- 6. En Çok Olabilirlik Yöntemi ve Kritik Noktalar
- 7. Log-Olabilirlik
- 8. Örnek: Poisson Parametresinin Tahmini
- Örnek Sorular

## 1. Ortalama ve Varyans için Nokta Tahmin Ediciler

Ders tablet üzerinde el yazısıyla, büyük ölçüde İngilizce anlatıldı; birkaç kısa Türkçe açıklama da yapıldı. Konu, ortalama ve varyans için nokta tahmin edicilerdi (point estimators for mean and variance) (ekrandan, 00:35:00).

### 1.1 Örneklem

Bir örneklem (sample), rastgele değişkenlerin bir topluluğu olarak yazılır:

$$X_1, X_2, \dots, X_n$$

Bu değişkenler bağımsız ve aynı dağılımlıdır (i.i.d., independent and identically distributed). Ekranda örneklem, bir popülasyondan seçilmiş noktalar olarak küçük bir çizimle de gösterildi (ekrandan, 00:35:00).

### 1.2 Ortalama için tahmin edici

Tahmin edilmek istenen büyüklük popülasyon ortalaması $\mu = E X$'tir. Bunun için iyi bir tahmin edici, daha önce öğrenilen örneklem ortalamasıdır (ekrandan, 00:35:00):

$$\overline{X} = \frac{X_1 + X_2 + \dots + X_n}{n}$$

### 1.3 Varyans için tahmin edici

Varyans için iyi bir tahmin edici örneklem varyansıdır (sample variance), $S^2$:

$$S^2 = \frac{1}{n-1}\sum_{k=1}^{n} \left(X_k - \overline{X}\right)^2$$

Hoca formülde bölenin $1/n$ olmadığına özellikle dikkat çekti. $1/n$ ile bölünen tahmin edici yanlı (biased) olur; $S^2$'yi yansız (unbiased) yapmak için $1/n$ yerine $1/(n-1)$ kullanılır. Formülün bu biçimi, aşağıdaki sayısal örnekte ekranda yazılan $\frac{1}{6-1}$ çarpanıyla doğrulanır (ekrandan, 00:50:00).

<!-- BELİRSİZ: S^2'nin genel tanımının yazıldığı anın karesi yok. Hoca "burada da 1/n değil" diyerek ikinci bir ifade daha gösterdi (büyük olasılıkla S^2'nin açılmış başka bir biçimi); bu ifade karelerden okunamadı. -->

> **Ek bilgi (derste anlatılmadı):** $E\left[\frac{1}{n}\sum (X_k - \overline{X})^2\right] = \frac{n-1}{n}\sigma^2$ olduğu için $1/n$'li tahmin edici varyansı sistematik olarak küçük tahmin eder. $\frac{n}{n-1}$ ile düzeltilince beklenen değer tam $\sigma^2$ olur; $S^2$'deki $n-1$ buradan gelir.

### 1.4 Standart sapma için tahmin edici

Popülasyon standart sapması $\sigma$ için iyi bir tahmin edici, örneklem varyansının kareköküdür (ekrandan, 00:40:00):

$$S = \sqrt{S^2}$$

Buna örneklem standart sapması (sample standard deviation) denir. Hoca $S$'nin yanlı olduğunu belirtti. Kitapların verdiği yansız bir tahmin edici olmadığını, $S$'nin yine de kabul edilebilir bir tahmin edici olduğunu ve bunun üzerinde fazla durulmayacağını söyledi.

> **Ek bilgi (derste anlatılmadı):** $S^2$ yansız olsa da karekök doğrusal olmayan (içbükey) bir fonksiyon olduğu için Jensen eşitsizliğinden $E[S] \le \sqrt{E[S^2]} = \sigma$ çıkar; yani $S$ ortalamada $\sigma$'yı biraz küçük tahmin eder. Fark $n$ büyüdükçe azalır.

## 2. Sayısal Örnek: İş Tamamlanma Süresi

Hoca konuyu bir örnekle somutlaştırdı (ekrandan, 00:45:00).

**Verilen.** $T$, bir fabrikada belirli bir işin tamamlanması için geçen süredir. $T$'nin ortalaması ve varyansı tahmin edilmek isteniyor. Bunun için altı gözlemlik bir rastgele örneklem $T_1, T_2, \dots, T_6$ alınıyor. Değerler:

$$18,\ 21,\ 17,\ 16,\ 24,\ 20$$

$T_i$'ler i.i.d.'dir. İstenen: $\overline{T}$, $S^2$ ve $S = \sqrt{S^2}$.

Hoca rastgele değişken $T$ olduğu için gösterimin de $\overline{T}$ olması gerektiğini, başta yanlış harf yazdığını belirterek düzeltti.

**Örneklem ortalaması.** (ekrandan, 00:45:00)

$$\overline{T} = \frac{T_1 + T_2 + \dots + T_6}{6} = \frac{18+21+17+16+24+20}{6} = \frac{116}{6} \approx 19.33$$

**Örneklem varyansı.** Her gözlemden ortalama çıkarılır, karesi alınır, toplanır ve $6-1 = 5$'e bölünür (ekrandan, 00:50:00):

$$S^2 = \frac{1}{6-1}\left(\sum_{k=1}^{6}\left(T_k - 19.33\right)^2\right) \approx 8.67$$

Ara adımlar (ara adım eklendi): sapmalar yaklaşık $-1.33,\ 1.67,\ -2.33,\ -3.33,\ 4.67,\ 0.67$; kareleri toplamı $\frac{130}{3} \approx 43.33$; $43.33 / 5 \approx 8.67$.

**Örneklem standart sapması.** (ekrandan, 00:50:00)

$$S = \sqrt{S^2} \approx 2.94$$

Üç değer Python ile doğrulandı: $19.333$, $8.667$, $2.944$.

## 3. Python ile Hesaplama

Hoca bu hesapların günümüzde pratikte programlama dilleriyle yapıldığını söyledi. Birçok dil kullanılabilir; derste Python gösterildi (ekrandan, 00:50:00):

```python
import numpy as np
t = [18, 21, 17, 16, 24, 20]
mean_t = np.mean(t)
var_t = np.var(t, ddof=1)
```

- NumPy bir doğrusal cebir paketidir ve birçok kullanışlı işlev içerir.
- Veri bir Python listesi olarak tanımlanır ve `t` değişkenine atanır.
- `np.mean(t)` ortalamayı otomatik hesaplar.
- `np.var(t, ddof=1)` örneklem varyansını verir. `ddof=1` verilmezse NumPy $1/n$ ile böler; bu ders anlatılan $S^2$ değildir. <!-- BELİRSİZ: Hoca ddof parametresini Türkçe açıkladı ama altyazı bu kısımda bozuk; açıklamanın ayrıntısı alınamadı. -->
- Standart sapma için varyansın karekökü alınır: `np.sqrt(var_t)`.

Kod çalıştırıldığında ortalama $19.333$, varyans $8.667$, standart sapma $2.944$ çıkar. `ddof=1` olmadan varyans $7.222$ olurdu.

Hoca bu kısımda soru olup olmadığını sordu; soru gelmedi ve bu bölümün kolay olduğunu söyledi.

## 4. En Çok Olabilirlik Kestirimi: Problem

Yeni konu en çok olabilirlik kestirimidir (Maximum Likelihood Estimation, MLE) (ekrandan, 00:55:00).

Şimdiye kadar dağılımların ortalaması ve varyansı ($\mu$, $\sigma^2$) için tahmin ediciler görüldü. Bazen ise bir dağılımın bir parametresi tahmin edilmek istenir. Örnek olarak verinin Poisson dağılımına uyduğu biliniyor olsun:

$$X \sim \text{Poisson}(\lambda), \qquad p(x) = e^{-\lambda}\frac{\lambda^{x}}{x!}$$

Buradaki parametre $\lambda$'dır. Dağılımın Poisson olduğu biliniyorsa ve $\lambda$ bulunabilirse bütün dağılım belirlenmiş olur. Bunun için veri toplanır; ekrandaki örnek veri $6, 4, 2, \dots$ idi (ekrandan, 00:55:00). Hoca gerçekte bundan çok daha fazla veri toplanması gerektiğini söyledi. Soru şudur: bu veriden $\lambda$ nasıl tahmin edilir?

## 5. Olabilirlik Fonksiyonu

### 5.1 Kesikli durum

Kesikli bir rastgele değişken $X$ için olabilirlik (likelihood) $L$, verinin olasılığıdır (ekrandan, 01:00:00):

$$L = P(X_1 = x_1, X_2 = x_2, \dots, X_n = x_n)$$

$X_i$'ler i.i.d. olduğu için bağımsızdırlar; ortak olasılık tek tek olasılıkların çarpımı olarak yazılabilir:

$$L = P_{X_1}(x_1)\, P_{X_2}(x_2) \cdots P_{X_n}(x_n) = \prod_{i=1}^{n} P_{X_i}(x_i)$$

Hoca $\prod$ sembolünü toplam sembolünün çarpma için olan karşılığı olarak tanıttı. Yani olabilirlik, her gözlemin olasılığının çarpımıdır.

### 5.2 Sürekli durum

Sürekli bir $X$ için de $X_i$'ler yine i.i.d.'dir (ekrandan, 01:00:00). Bu kez olabilirlik ortak yoğunluktur (joint density):

$$L = f_{X_1 X_2 \dots X_n}(x_1, x_2, \dots, x_n)$$

Bağımsızlık sayesinde ortak yoğunluk marjinal yoğunlukların çarpımına ayrılır:

$$L = f_{X_1}(x_1)\, f_{X_2}(x_2) \cdots f_{X_n}(x_n) = \prod_{i=1}^{n} f_{X_i}(x_i)$$

İki durum çok benzerdir: kesikli durumda olasılık kütleleri (olasılık değerleri), sürekli durumda yoğunluklar çarpılır.

## 6. En Çok Olabilirlik Yöntemi ve Kritik Noktalar

### 6.1 Yöntem

Hatırlatma: tahmin edilmek istenen parametre $\theta$'dır. Tahmin edici, geleneksel olarak $\hat{\theta}$ ile gösterilir ve "theta hat" (theta şapka) diye okunur (ekrandan, 01:05:00). En çok olabilirlik yönteminde tahmin edici, olabilirliği en büyük yapan değerdir:

$$\hat{\theta} = \arg\max_{\hat{\theta}} L$$

### 6.2 Analitik çözüm

Problem analitik olarak çözülecekse türev alınıp sıfıra eşitlenir. Ancak hoca, optimizasyonda türevi sıfıra eşitlemenin her zaman maksimumu vermediğini hatırlattı. Bu yüzden doğru ifade şudur: $\hat{\theta}$, $\frac{dL}{d\hat{\theta}} = 0$ için kritik noktalar listesindedir (ekrandan, 01:10:00).

Derste çizilen grafikte yatay eksende $\hat{\theta}$, düşey eksende $L$ vardı ve olabilirlik $[a, b]$ aralığında tanımlıydı (ekrandan, 01:10:00 ve 01:15:00):

| Nokta | Ne olduğu | Neden kritik |
|---|---|---|
| $a$ | sınır noktası | aralığın ucu |
| $c$ | minimum | $\frac{dL}{d\hat{\theta}} = 0$ |
| $d$ | eyer (saddle) noktası | $\frac{dL}{d\hat{\theta}} = 0$ |
| $e$ | maksimum | $\frac{dL}{d\hat{\theta}} = 0$ |
| $b$ | sınır noktası | aralığın ucu |

Sınır noktalarında türev tanımlı olmayabilir, ama yine de kontrol edilmeleri gerekir. Yöntem şöyle özetlenir:

1. Türev alınır, sıfıra eşitlenir ve çözülür; çözümler kritik noktaları verir.
2. Bu listeye sınır noktaları ($a$ ve $b$) eklenir.
3. Fonksiyonun en büyük değerini bu noktalardan hangisinde aldığı kontrol edilir.

> **Ders sonrası not:** Hoca $c, d, e$ için sözlü olarak "boundary points" dedi; ekranda doğru olarak bunların türevin sıfır olduğu noktalar ($\frac{dL}{d\hat{\theta}} = 0$) olduğu yazılıdır. Sınır noktaları yalnız $a$ ve $b$'dir.

## 7. Log-Olabilirlik

Hoca bunu "güzel bir hile" (nice trick) diye tanıttı: olabilirliği en büyüklemek yerine olabilirliğin logaritması en büyüklenir (ekrandan, 01:15:00).

**Neden aynı sonucu verir?** Ekrandaki grafikte $L$ eğrisi ile $\log(L)$ eğrisi alt alta çizildi; $\log(L)$'nin maksimumu da aynı yerde, "still max." (hâlâ maksimum). Çözüm aynıdır, maksimumlar aynı yerdedir.

**Neden tercih edilir?** Olabilirlik bir çarpımdır. $\frac{d}{d\hat{\theta}}\prod_{i=1}^{n} p(x_i)$ ifadesinin türevi karmaşıktır ("complicated"). Logaritma alınca çarpım toplama döner (ekrandan, 01:20:00):

$$\log(L) = \log\left(\prod_{i=1}^{n} p(x_i)\right) = \sum_{i=1}^{n} \log p(x_i)$$

Olasılıklar yerine log-olasılıklar toplanır. Türev her terim için ayrı alındığından genelde çok daha basittir.

> **Ek bilgi (derste anlatılmadı):** Logaritma kesin artan bir fonksiyon olduğu için $L(\theta_1) > L(\theta_2)$ ile $\log L(\theta_1) > \log L(\theta_2)$ denktir; maksimumun yerinin değişmemesinin nedeni budur. Ayrıca çok sayıda küçük olasılığın çarpımı bilgisayarda sıfıra yuvarlanabilirken logaritmaların toplamı bu sorunu yaşamaz.

## 8. Örnek: Poisson Parametresinin Tahmini

**Verilen.** $X \sim \text{Poisson}(\lambda)$; $\lambda$ tahmin edilecek. Basitlik için veri yalnız $6, 4, 2$'dir. $p(x) = e^{-\lambda}\frac{\lambda^{x}}{x!}$ (ekrandan, 01:20:00).

**Adım 1: olabilirlik.** $\hat{\lambda}$, $\lambda$ için MLE tahmin edicisi olsun. Poisson kesikli bir dağılım olduğu için olasılıklar çarpılır (ekrandan, 01:20:00):

$$L = \prod_{i=1}^{n} p(x_i) = \prod_{i=1}^{n} e^{-\lambda}\frac{\lambda^{x_i}}{x_i!}$$

**Adım 2: log-olabilirliğin türevini sıfıra eşitleme.** (ekrandan, 01:25:00)

$$\frac{d \log(L)}{d\hat{\lambda}} = 0$$

Hoca bir gösterim noktasını açıkladı: türevi sıfıra eşitleyip çözdüğümüz andan itibaren popülasyon değeri $\lambda$ değil, tahmin edici $\hat{\lambda}$ kullanılır; bu noktaya kadar yazılanlar popülasyon değeriyle ilgilidir. Buradan sonrası yalnız matematiktir (kalkülüs).

**Adım 3: logaritmayı içeri alma.** Ekranda $\log = \ln$ olduğu not edildi (ekrandan, 01:25:00):

$$\frac{d}{d\hat{\lambda}}\sum_{i=1}^{n}\log\left(e^{-\hat{\lambda}}\frac{\hat{\lambda}^{x_i}}{x_i!}\right) = 0$$

Logaritma çarpım ve bölümü toplam ve farka çevirir. $\ln e = 1$ olduğu için ilk terim $-\hat{\lambda}$ olur; $\hat{\lambda}^{x_i}$'nin logaritması $x_i\log\hat{\lambda}$'dır; $x_i!$ paydada olduğu için eksiyle gelir (ekrandan, 01:30:00):

$$\frac{d}{d\hat{\lambda}}\sum_{i=1}^{n}\left[(-\hat{\lambda}) + x_i\log\hat{\lambda} - \log x_i!\right] = 0$$

**Adım 4: terimleri ayırma.** Son terim $\log x_i!$, $\hat{\lambda}$ içermez; türevi sıfırdır. İlk terim $n$ kez toplanınca $-n\hat{\lambda}$ olur. İkinci terimde $\log\hat{\lambda}$, $i$'ye bağlı olmadığı için toplamın dışına alınır (ekrandan, 01:30:00):

$$\frac{d}{d\hat{\lambda}}\left(-n\hat{\lambda} + \log\hat{\lambda}\sum_{i=1}^{n}x_i\right) = 0$$

$\sum x_i$, örneklem ortalamasına benzer ama $n$'e bölünmemiştir; dolayısıyla $\sum_{i=1}^{n} x_i = n\overline{X}$'tir (ekrandan, 01:35:00).

**Adım 5: türev.** $\frac{d}{d\hat{\lambda}}\log\hat{\lambda} = \frac{1}{\hat{\lambda}}$ olduğu için (ekrandan, 01:35:00):

$$-n + \frac{1}{\hat{\lambda}}\,n\overline{X} = 0 \quad\Rightarrow\quad \frac{\overline{X}}{\hat{\lambda}} = 1 \quad\Rightarrow\quad \hat{\lambda} = \overline{X}$$

**Adım 6: sayısal sonuç.** (ekrandan, 01:35:00)

$$\hat{\lambda} = \overline{X} = \frac{6+4+2}{3} = 4$$

> **Ders sonrası not:** Hoca Adım 4'te önce $\sum x_i$ yerine $\overline{X}/n$ yazdı, sonra bunu $n\overline{X}$ olarak düzeltti (ekrandan, 01:30:00 ve 01:35:00). Düzeltme sırasında sözlü olarak "standard deviation" dedi; ekrandaki ve doğru ifade örneklem ortalaması $\overline{X}$'tir. Sonuç $\hat{\lambda} = \overline{X}$'tir.

**Adım 7: sınırlar.** $\lambda$, belirli bir sürede gerçekleşen olay sayısının ortalamasıdır; $x$ $0$'dan sonsuza değer alır, $\lambda > 0$'dır. Bu yüzden $\hat{\lambda} = 0$ ve $\hat{\lambda} = \infty$ sınırları da kontrol edilmelidir; oralarda olabilirlik daha büyük çıkarsa onlar daha iyi bir tahmin olurdu. Hoca bunu alıştırma (exercise) olarak bıraktı ve bu sınırlarda olabilirliğin daha küçük değerler almasını beklediğini söyledi (ekrandan, 01:35:00).

> **Hocanın vurgusu:** Türev alındıktan sonra işlem zor değildir, ama çok dikkatli olunması gerekir.

## Örnek Sorular

### Soru 1: Örneklem ortalaması, varyansı ve standart sapması

(ekrandan, 00:45:00) $T$, bir fabrikada belirli bir işin tamamlanma süresidir. i.i.d. rastgele örneklem $T_1, \dots, T_6$'nın değerleri $18, 21, 17, 16, 24, 20$'dir. $\overline{T}$, $S^2$ ve $\sqrt{S^2}$'yi bulun.

> **Çözüm (derste verildi):** $\overline{T} = \frac{116}{6} \approx 19.33$; $S^2 = \frac{1}{6-1}\sum_{k=1}^{6}(T_k - 19.33)^2 \approx 8.67$; $S = \sqrt{S^2} \approx 2.94$ (ekrandan, 00:50:00). Python'da `np.mean(t)` ve `np.var(t, ddof=1)` ile aynı değerler elde edilir.

### Soru 2: Poisson parametresinin en çok olabilirlik tahmini

(ekrandan, 01:20:00) $X \sim \text{Poisson}(\lambda)$, $p(x) = e^{-\lambda}\frac{\lambda^{x}}{x!}$. Veri: $6, 4, 2$. $\lambda$'yı en çok olabilirlik yöntemiyle tahmin edin.

> **Çözüm (derste verildi):** $\log L = \sum_{i=1}^{n}\left(-\hat{\lambda} + x_i\log\hat{\lambda} - \log x_i!\right) = -n\hat{\lambda} + n\overline{X}\log\hat{\lambda} - \sum\log x_i!$. Türev: $-n + \frac{n\overline{X}}{\hat{\lambda}} = 0 \Rightarrow \hat{\lambda} = \overline{X} = \frac{6+4+2}{3} = 4$ (ekrandan, 01:35:00).

### Soru 3: Sınır noktalarının kontrolü (alıştırma)

(ekrandan, 01:35:00) Soru 2'de $\lambda > 0$ olduğuna göre $\hat{\lambda} = 0$ ve $\hat{\lambda} = \infty$ sınırlarını da kontrol edin.

> **Çözüm (derste verilmedi):** Veri $6, 4, 2$ için $L(\lambda) = \frac{e^{-3\lambda}\lambda^{12}}{6!\,4!\,2!}$. $\lambda \to 0^{+}$ iken $\lambda^{12} \to 0$ olduğundan $L \to 0$; $\lambda \to \infty$ iken üstel terim $e^{-3\lambda}$ polinomdan hızlı küçüldüğünden yine $L \to 0$. İç noktada $L(4) \approx 2.98 \times 10^{-3}$ pozitif olduğu için iki sınır da daha küçük olabilirlik verir; maksimum $\hat{\lambda} = 4$'tedir. Değerler Python ile kontrol edildi (örneğin $L(3) \approx 1.90 \times 10^{-3}$, $L(5) \approx 2.16 \times 10^{-3}$).

## Dersin Toparlaması

Ders iki parçadan oluştu. İlk bölümde ortalama, varyans ve standart sapma için nokta tahmin ediciler görüldü: $\overline{X}$, $n-1$ ile bölünen yansız $S^2$ ve yanlı ama kullanışlı $S = \sqrt{S^2}$. Bu tahmin ediciler bir iş tamamlanma süresi örneğinde elle ve NumPy ile hesaplandı; `np.var` için `ddof=1` verilmesi gerektiği görüldü.

İkinci bölümde bir dağılımın parametresini tahmin etmek için en çok olabilirlik kestirimi tanıtıldı. Olabilirlik, i.i.d. gözlemlerin olasılık ya da yoğunluklarının çarpımıdır; tahmin edici bu fonksiyonu en büyük yapan değerdir. Kritik noktalar hem türevin sıfır olduğu yerleri hem de sınır noktalarını içerir. Hesap kolaylığı için log-olabilirlik kullanılır. Poisson örneğinde MLE tahmin edicisinin örneklem ortalaması olduğu bulundu. Hoca bir sonraki konunun aralık tahmini (interval estimation) olacağını söyledi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
