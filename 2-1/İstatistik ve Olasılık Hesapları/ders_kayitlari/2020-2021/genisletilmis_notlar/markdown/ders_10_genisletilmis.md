# Ders 10 Genişletilmiş Notu: Çeyrekler, Örneklem Varyansı, Standart Hata, IQR ile Aykırı Değerler ve Histogram

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Önceki Dersin Tekrarı: Örneklem Ortalaması, Medyan ve Kantiller
- 2. Kantillerin Diğer Adları: Yüzdelikler ve Çeyrekler
- 3. Ortalama ve Medyandan Dağılımın Şekli
- 4. Merkezi Eğilim Ölçüleri ve Dayanıklılık
- 5. Yayılım Ölçüleri: Örneklem Varyansı ve Örneklem Standart Sapması
- 6. Standart Hata
- 7. Yanlılık ve Standart Hatanın Görsel Karşılaştırması
- 8. Çeyrekler Açıklığı ve Aykırı Değerler
- 9. Grafiksel İstatistik: Veriyi Önce Çizip Bakmak
- 10. Histogram

## 1. Önceki Dersin Tekrarı: Örneklem Ortalaması, Medyan ve Kantiller

Hoca derse, geçen hafta başlanan giriş düzeyi istatistiği hatırlatarak başladı. Önce örneklem ortalaması (sample mean) görülmüş, beklenen değeri, varyansı ve dağılımı konuşulmuştu. Ardından medyan (median) ele alınmış, medyanın hem örneklemde hem popülasyonda nasıl hesaplandığı öğrenilmişti.

Sonra kantillere (quantiles) geçilmişti. Kantil, medyana benzer ama daha genel bir fikirdir. Hocanın hatırlattığı sezgi şuydu: Sürekli dağılımlarda kantil, birikimli dağılım fonksiyonunun (CDF) bir tür tersi gibi görünür. Bu bakış, kantilin ne olduğu hakkında somut bir fikir verir.

### 1.1 Örneklem Kantilini Hesaplama

Örneklem kantilinin tanımı, hocanın deyişiyle, ne söylediğini anlamak için üzerinde biraz düşünmeyi gerektirir. Bu yüzden geçen hafta basit bir hesap yöntemi de verilmişti. Örneklem $p$-kantilini bulmak için:

1. Örneklemi sırala.
2. Eleman sayısının bir fazlasını istenen $p$ ile çarp: $p(n+1)$.
3. Sonucu yuvarla. Çıkan sayı, sıralı dizide aradığımız elemanın sırasıdır.

### 1.2 CPU Verisinde Kantiller

Geçen dersteki örnek, 30 elemanlı CPU verisiydi. Hoca veriyi ekranda gösterdi. Veri listesi bu kaydın altyazısında tam okunmuyor, sıralı hâli geçen dersin kısa notundan alındı:

$$9,\ 15,\ 19,\ 22,\ 24,\ 25,\ 30,\ 34,\ 35,\ 35,\ 36,\ 36,\ 37,\ 38,\ 42,\ 43,\ 46,\ 48,\ 54,\ 55,\ 56,\ 56,\ 59,\ 62,\ 69,\ 70,\ 82,\ 82,\ 89,\ 139$$

Sorular şunlardı: Örneklem 0.25-kantili, 0.50-kantili ve 0.75-kantili nedir? Örneklemden gelen değerler olduklarını göstermek için bunlar şapkalı yazılır, $\hat{q}_{0.25}$ gibi. Hoca 0.50 ve 0.75 için hesabı geçen hafta alıştırma olarak bırakmıştı.

0.25-kantil için hesap derste tekrarlandı:

- Verilen: $n = 30$, $p = 0.25$.
- İşlem: $p(n+1) = 0.25 \cdot 31 = 7.75$ (ara adım eklendi).
- Yuvarlama: $7.75$ yuvarlanınca 8 olur, yani sıralı dizideki 8. elemana bakılır (ara adım eklendi).
- Sonuç: $\hat{q}_{0.25} = 34$.

Hoca derste ilerleyen bir yerde 0.75-kantilin de 59 olduğunu kullandı. Aynı yöntemle bu sonuç şöyle çıkar: $0.75 \cdot 31 = 23.25$, yuvarlanınca 23. eleman, yani $\hat{q}_{0.75} = 59$ (ara adım eklendi).

> **Ders sonrası not:** Hoca 0.50-kantilin sonucunu bu derste söylemedi. Python ile hesaplandı: $0.5 \cdot 31 = 15.5$ tam ortada kalır, 15. eleman 42 ve 16. eleman 43'tür. İkisinin ortası $42.5$'tir. Geçen dersin kısa notu da aynı sonucu verir.

## 2. Kantillerin Diğer Adları: Yüzdelikler ve Çeyrekler

Hoca, kantile çok benzeyen iki kavram daha tanıttı. Bunlar farklı adlardır, ama özünde aynı şeyi anlatırlar.

### 2.1 Yüzdelik (Percentile)

Popülasyon için $\gamma$-yüzdelik $\pi_\gamma$ ile yazılır ve $0.01\gamma$-kantile eşittir:

$$\pi_\gamma = q_{0.01\gamma}$$

<!-- BELİRSİZ: Altyazıda sembol "P, let's say, gamma" diye geçiyor. Kısa notta π_γ yazıyor. Tahtadaki gerçek sembol altyazıdan okunamıyor. -->

Hoca "25. yüzdelik nedir?" diye sordu. Yapılacak tek şey sayıyı 100'e bölmektir: 25. yüzdelik, 0.25-kantildir. Bunun nasıl hesaplandığını az önce CPU verisinde görmüştük. Popülasyon yüzdeliği ve örneklem yüzdeliği vardır, her şey kantildeki gibidir. Örneklem yüzdeliği şapkalı yazılır.

### 2.2 Çeyrek (Quartile)

Çeyrekler de kantiller cinsinden tanımlanır ve yalnızca üç tanedir:

- $Q_1$: 0.25-kantil.
- $Q_2$: 0.50-kantil. Bunun medyan olduğunu biliyoruz.
- $Q_3$: 0.75-kantil.

Örneklem karşılıkları yine şapkalıdır: $\hat{Q}_1$, $\hat{Q}_2$, $\hat{Q}_3$. Hoca şapkanın anlamını ayrıca söyledi: Şapka gördüğümüzde değer örneklemden gelir ve bir tahmindir.

## 3. Ortalama ve Medyandan Dağılımın Şekli

Hoca, ortalama ve medyanı anlatırken atladığı bir noktaya döndü. Bir dağılımın ortalamasını ve medyanını biliyorsak, dağılımın şekli hakkında, özellikle çarpıklığı (skewness) hakkında fikir edinebiliriz.

Temel fikir şudur: Ortalama, uç değerlerden (extreme values) medyana göre daha fazla etkilenir. Bu fikir geneldir, hem örneklem ortalaması hem popülasyon ortalaması için yazılabilir. Aşağıda ortalama $\mu$, medyan $M$ ile gösterilir.

- **Simetrik dağılım:** $f(x)$ eğrisi simetrikse ortalama ile medyan aynıdır ya da birbirine çok yakındır. Hoca bunu tersinden de söyledi: $\mu$ ile $M$ aynı görünüyorsa dağılım simetrik olmalıdır.
- **Sağa çarpık dağılım:** Bir tarafta uzun kuyruk varsa dağılım simetrik değildir. Veri sağa doğru daha fazla uzanıyorsa kuyruk sağdadır ve dağılıma sağa çarpık (right skewed) denir. Ortalama çarpık tarafa kayar, medyan onun solunda kalır.
- **Sola çarpık dağılım:** Bu durumun aynası. Uzun kuyruk soldadır ve ortalama yine çarpık taraftadır, medyanın solunda kalır. Çünkü ortalama uç değerlerden daha çok etkilenir.

<!-- BELİRSİZ: Üç eğri ve üzerlerindeki μ ve M işaretleri tahtada çizildi. Altyazıda yalnızca sözlü geçiyor, çizimin tam biçimi okunamıyor. -->

> **Ders sonrası not:** Altyazıda hoca simetri cümlesinde "$\mu$ is same as the mean" diyor. Kastı "$\mu$ medyanla aynıdır" olmalı, çünkü $\mu$ zaten ortalamadır. Ayrıca bu cümlenin ters yönü her zaman geçerli değildir: Simetrik dağılımda ortalama ile medyan eşit olsa da, eşitlik tek başına simetriyi kanıtlamaz. Ortalaması ve medyanı eşit olup simetrik olmayan kesikli bir dağılım tam kesirle python ile hesaplandı. Yani bu ölçüt kesin bir test değil, bir ipucudur.

## 4. Merkezi Eğilim Ölçüleri ve Dayanıklılık

Ortalama $\mu$ ile tahmin edicisi $\bar{X}$ ve medyan $M$ ile tahmin edicisi $\hat{M}$, merkezi eğilim ölçüleri (measures of central tendency) diye anılır. Şu soruyu cevaplarlar: Bu dağılımın merkezi nerededir?

Aralarındaki en büyük fark şudur: Medyan, aykırı değerlere (outliers) ortalamadan daha dayanıklıdır (robust). Aykırı değerler verideki uç değerlerdir. Verideki bir uç değeri değiştirirseniz ortalama çok değişir.

Hoca buna dayanıklılık (robustness) adını verip basit bir örnek çözdü.

**Birinci örneklem.** $S_1 = (1, 2, 3, 4, 5)$ olsun.

- Ortalama: $\bar{X}_1 = \dfrac{1+2+3+4+5}{5} = \dfrac{15}{5} = 3$ (ara adım eklendi).
- Medyan: sıralı dizinin ortası, $\hat{M}_1 = 3$.

**İkinci örneklem.** Yalnızca son değeri değiştirelim: $S_2 = (1, 2, 3, 4, 500)$.

- Ortalama: $\bar{X}_2 = \dfrac{1+2+3+4+500}{5} = \dfrac{510}{5} = 102$. Hoca bu bölmeyi derste Türkçe söyledi: beş yüz onu beşe böleceğiz.
- Medyan: yine sıralı dizinin ortası, $\hat{M}_2 = 3$.

Tek bir aykırı değer ortalamayı 3'ten 102'ye taşır, medyan ise 3'te kalır. Dayanıklılık budur: Medyan aykırı değerlerden pek etkilenmez, örneklem ortalaması çok etkilenir.

## 5. Yayılım Ölçüleri: Örneklem Varyansı ve Örneklem Standart Sapması

Merkezi eğilim ölçüleri merkezin yerini söyler. Yayılım ölçüleri (measures of spread) ise verinin ne kadar yayıldığını söyleyen istatistiklerdir. Hoca bunlardan ikisini saydı: varyans ya da onun karekökü olan standart sapma ve birazdan görülecek çeyrekler açıklığı (IQR). Varyans mı standart sapma mı dediğimizin burada önemi yoktur.

### 5.1 Örneklem Varyansı

Popülasyon varyansını daha önce görmüştük. Bir beklenen değerdir:

$$\mathrm{Var}(X) = \sigma^2 = E\left[(X - \mu)^2\right]$$

Örneklem varyansı (sample variance) küçük $s$ ile, $s^2$ diye yazılır ve popülasyon varyansını tahmin eder:

$$s^2 = \frac{1}{n-1}\sum_{i=1}^{n}\left(X_i - \bar{X}\right)^2$$

İki formül arasındaki benzerlik açıktır. $\mu$ yerine örneklem ortalaması kullanılır. Örneklem ortalaması bütün değerlerden çıkarılır, farkların kareleri toplanır ve bölme yapılır.

### 5.2 Neden $n$ Değil de $n-1$?

Hoca, bu denklemi ilk gördüğünde kendisini de meraklandıran şeyin bu olduğunu anlattı: Neden $n$'e değil de $n-1$'e bölüyoruz?

Cevap yanlılıktır (bias). Denklemde $\frac{1}{n}$ kullanılırsa tahmin edici yanlı olur. Yani tahmin edicinin beklenen değeri ile tahmin etmeye çalıştığımız parametre arasındaki fark sıfır çıkmaz:

$$E[\hat{\theta}] - \theta \neq 0$$

Burada $\theta$, varyanstır. Bunu düzeltmek için $n$ yerine $n-1$'e bölünür. Hoca, $\frac{1}{n}$ kullanılınca yanlılığın sıfır olmadığını ve $\frac{1}{n-1}$ kullanılınca sıfır olduğunu göstermeyi alıştırma olarak bıraktı.

> **Ders sonrası not:** Hoca, $\frac{1}{n}$ kullanılırsa $n \to \infty$ iken popülasyon varyansı ile örneklem varyansı arasındaki farkın sıfıra gitmediğini söyledi. Doğrusu farkın sıfıra gittiğidir. $\frac{1}{n}$'li tahmin edicinin beklenen değeri $\frac{n-1}{n}\sigma^2$'dir, yanlılığı $-\sigma^2/n$'dir. Python ile küçük örneklemlerde tam sayım ve kesirle hesaplandı. Bu tahmin edici sonlu $n$ için yanlıdır, ama yanlılığı $n$ büyüdükçe küçülür. $n-1$'e bölmek yanlılığı her $n$ için tamamen kaldırır.

> **Ek bilgi (derste anlatılmadı):** Alıştırmanın ana fikri şu özdeşliktir: $\sum_{i}(X_i - \bar{X})^2 = \sum_{i}(X_i - \mu)^2 - n(\bar{X} - \mu)^2$. Sağ tarafın beklenen değerinde ilk terim $n\sigma^2$, ikinci terim $n \cdot \sigma^2/n = \sigma^2$ verir. Sonuç $(n-1)\sigma^2$'dir. Bunu $n-1$'e bölmek tam $\sigma^2$ verir. Sonuç python ile küçük örneklemlerde tam kesirle hesaplandı.

### 5.3 Örneklem Standart Sapması

Popülasyon standart sapmasına benzer biçimde, örneklem standart sapması (sample standard deviation) örneklem varyansının kareköküdür ve popülasyon standart sapmasını tahmin eder:

$$s = \sqrt{s^2}$$

### 5.4 Bu Tahmin Edicilerin Özellikleri

Hoca, $s$ ve $s^2$'nin üç güzel özelliği olduğunu söyledi: yansız (unbiased), tutarlı (consistent) ve asimptotik normal (asymptotically normal). Sonra bunları tek tek hatırlattı.

- **Yansızlık:** Az önce konuşuldu. Beklenen değer ile parametre arasındaki fark sıfır olmalıdır.
- **Tutarlılık:** Hoca bunun Chebyshev özelliğinden geldiğini söyledi. Bir $\hat{\theta}$ tahmin edicisi, seçebileceğimiz herhangi bir $\varepsilon$ değeri için, $n \to \infty$ iken hatanın $\varepsilon$'dan büyük olma olasılığı sıfıra gidiyorsa tutarlıdır:

$$\lim_{n\to\infty} P\left(|\hat{\theta} - \theta| > \varepsilon\right) = 0$$

- **Asimptotik normallik:** $n \to \infty$ iken $s$ ve $s^2$'nin olasılık dağılımı normal dağılıma gider.

Hocanın özetiyle, ilk ikisi şunu söyler: Daha fazla veri kullandıkça tahminimiz ile popülasyon parametresi arasındaki fark sıfıra gider.

<!-- BELİRSİZ: Altyazıda asimptotik normalliğin yazılışı "Probability distribution of s and s squared goes to" diye yarım kalıyor. Tahtadaki gösterim okunamıyor. -->

> **Ders sonrası not:** Hoca $s$ ile $s^2$'nin ikisinin de yansız olduğunu söyledi. Doğrusu yalnız $s^2$ yansızdır. Python ile küçük örneklemlerde tam sayımla hesaplandı: $E[s^2]$ her $n$ için tam $\sigma^2$ çıktı, $E[s]$ ise $\sigma$'dan küçük kaldı ve $n$ büyüdükçe ona yaklaştı. Bu, kısa nottaki Jensen eşitsizliği gerekçesiyle uyumludur. Ayrıca hoca yansızlığı $n \to \infty$ limitiyle anlattı. Yansızlıkta fark her $n$ için sıfırdır. Farkın yalnız limitte sıfıra gitmesine asimptotik yansızlık denir ve $s$ için geçerli olan budur.

> **Ek bilgi (derste anlatılmadı):** Hocanın Chebyshev'den kastettiği yol büyük olasılıkla şudur: Chebyshev eşitsizliği $P(|\hat{\theta} - E[\hat{\theta}]| > \varepsilon) \le \mathrm{Var}(\hat{\theta})/\varepsilon^2$ der. Tahmin edici yansızsa ve varyansı $n \to \infty$ iken sıfıra gidiyorsa sağ taraf sıfıra gider. Tutarlılık da bu demektir.

> **Ek bilgi (derste anlatılmadı):** "Dağılım normale gider" cümlesinde büyük olasılıkla standartlaştırılmış biçim kastedilir. Çünkü tutarlılık nedeniyle $s^2$'nin dağılımı $n$ büyüdükçe $\sigma^2$ etrafında daralır. Normal olan, farkın kendi standart hatasına bölünmüş hâlidir.

## 6. Standart Hata

Standart sapmanın başka bir adı standart hatadır (standard error). Bu ad özellikle bir tahmin edicinin standart sapmasından söz ederken kullanılır.

Hocanın gerekçesi şuydu: Şimdiye kadar konuştuğumuz tahminler de rastgele değişkendir. Bu yüzden onların ortalamasından ve standart sapmasından söz edebiliriz. Hoca buna bir tür özyineleme (recursion) dedi: Tahmin edicinin kendisi bir rastgele değişkendir ve standart sapması vardır. Tahmin edicilerin standart sapmalarına standart hata denir.

Örnek olarak hoca şunu sordu: Örneklem ortalamasının standart hatası nedir? Bu, onun standart sapmasıdır. Hoca bu değeri daha önce hesapladıklarını söyleyip Türkçe hatırlattı: Örneklem ortalamasının standart sapması, popülasyonun standart sapması bölü kullanılan veri sayısının kareköküdür. Ortalaması da doğrudan popülasyonun beklenen değeridir:

$$\mathrm{SE}(\bar{X}) = \frac{\sigma}{\sqrt{n}}, \qquad E[\bar{X}] = \mu$$

Standart hatası düşük tahmin ediciler isteriz. Böylece iyi bir tahmin edicinin şu ana kadarki özellikleri şöyle sıralanır:

- Yansız olmalıdır.
- Mümkünse tutarlı ve asimptotik normal olmalıdır.
- Mümkünse standart hatası düşük olmalıdır.

## 7. Yanlılık ve Standart Hatanın Görsel Karşılaştırması

Hoca yansızlık ile düşük standart hatayı bir çizimle karşılaştırdı. Yatay eksen parametre tahminleri eksenidir ve üzerinde parametrenin gerçek değeri $\theta$ işaretlidir. Rastgele bir örneklem alıp $\hat{\theta}$ hesaplıyoruz, sonra başka bir rastgele örneklem alıp yeni bir $\hat{\theta}$ hesaplıyoruz ve böyle devam ediyoruz. Eksende bir tahminler bulutu oluşur.

Dört durum vardır:

| Durum | Tahminlerin yerleşimi | Standart hata | Yanlılık | Değerlendirme |
| :---- | :-------------------- | :------------ | :------- | :------------ |
| 1 | Birbirine yakın, merkezleri $\theta$'dan uzak | Düşük | Yanlı | Orta |
| 2 | Dağınık, merkezleri $\theta$ üzerinde | Yüksek | Yansız | Orta |
| 3 | Birbirine yakın, $\theta$ etrafında toplanmış | Düşük | Yansız | En iyi |
| 4 | Dağınık, merkezleri $\theta$'dan uzak | Yüksek | Yanlı | En kötü |

Aşağıdaki çizim yalnızca temsilîdir, hocanın sözlü anlatımından kuruldu:

```text
Durum 1:  -----|---------------xxxxx------   theta solda, tahminler sıkı ama uzakta
Durum 2:  ---x---x---x-|-x---x---x--------   tahminler dağınık, merkez theta üzerinde
Durum 3:  ----------xx|xx-----------------   tahminler sıkı, merkez theta üzerinde
Durum 4:  ---|----------x---x----x---x---x   tahminler dağınık, merkez thetadan uzak
```

<!-- BELİRSİZ: Dört çizimin gerçek biçimi ekranda kaldı. Altyazıda yalnızca sözlü anlatım var, yukarıdaki yerleşim temsilîdir. -->

Hoca karşılaştırmayı adım adım yaptı. İlk çizimde tahminler birbirine yakındır, yani standart hata düşüktür. Ama hikâye burada bitmez: Tahminlerin çoğu, parametrenin gerçek değerinden uzaktadır. Tahminlerin merkezi, başka bir deyişle beklenen değeri, parametreden uzak olduğu için bu tahmin edici yanlıdır. İkinci çizimde standart hata yüksektir, ki bu kötüdür, ama beklenen değer tam parametrenin üzerinde görünür ve tahmin edici yansız görünür. Bu ikisi ortada kalır, ne gerçekten iyi ne gerçekten kötüdür. Gerçekten iyi olan üçüncü durumdur. Tahminler birbirine yakındır ve parametre etrafında toplanır. En kötüsü de dördüncü durumdur.

## 8. Çeyrekler Açıklığı ve Aykırı Değerler

### 8.1 Çeyrekler Açıklığı (IQR)

Yayılım ölçülerine devam ederken hoca çeyrekler açıklığını (interquartile range, IQR) tanıttı. Bu, üçüncü çeyrek ile birinci çeyrek arasındaki farktır:

$$\mathrm{IQR} = Q_3 - Q_1 = q_{0.75} - q_{0.25}$$

Hoca bir yazım uzlaşımını da hatırlattı: Bir şey söylenmiyorsa, yani "örneklem" denmiyorsa, kastedilen genellikle popülasyondur. Yukarıdaki popülasyon çeyrekler açıklığıdır. Örneklem karşılığı şapkalı yazılır, bir tahmindir ve çeyreklerin tahminlerinden hesaplanır:

$$\widehat{\mathrm{IQR}} = \hat{Q}_3 - \hat{Q}_1$$

### 8.2 Aykırı Değerin Tanımı

Şimdiye kadar aykırı değerlere uç değerler demiştik, ama kesin bir tanım vermemiştik. Baron'un tanımına göre aykırı değerler, $Q_1$–$Q_3$ aralığının 1.5 IQR'den daha dışında kalan gözlemlerdir. Yani bir $x$ gözlemi şu durumda aykırıdır:

$$x < Q_1 - 1.5\,\mathrm{IQR} \quad \text{ya da} \quad x > Q_3 + 1.5\,\mathrm{IQR}$$

Hoca bunu bir eksen üzerinde gösterdi. Eksen veri değerleri eksenidir. Ortada medyan, yani $Q_2$ vardır, sağında $Q_3$, solunda $Q_1$. IQR, $Q_1$ ile $Q_3$ arasındaki bölgedir. $Q_3$'ten sağa 1.5 IQR uzunluğunda gidilir ve bu noktanın ötesindeki her değer aykırıdır. Sol tarafta da aynı biçimde $Q_1$'den sola 1.5 IQR gidilir ve bu noktanın gerisindeki her değer aykırıdır.

```text
 aykırı   |<- 1.5 IQR ->|<---- IQR ---->|<- 1.5 IQR ->|   aykırı
----------+-------------+-------+-------+-------------+----------
                       Q1     Q2=M     Q3
```

> **Ders sonrası not:** Hoca tanımda iki kez "$Q_1$–$Q_2$ aralığı", bir kez de "$Q_1$'i $Q_2$'den çıkar" dedi. Doğrusu $Q_1$–$Q_3$ aralığı ve $Q_3 - Q_1$'dir. Hocanın kendi tanımı ve CPU hesabı da bunu gösterir. Eksen anlatımında geçen "mean is $Q_2$" ifadesinde de doğrusu medyandır.

### 8.3 Örnek: CPU Verisinde Aykırı Değer Var mı?

Hoca, CPU verisinde aykırı değer olup olmadığını sordu. Hesap için önce sıralı verinin iki ucuna bakıldı. En küçük değer 9, ondan sonra 15 gelir. En büyük değer 139, ondan önce 89 gelir. Bu uç değerler aykırı adayıdır.

**Verilen:** Sıralı CPU verisinden $\hat{Q}_1 = 34$ ve $\hat{Q}_3 = 59$. Bunlar tahmin olduğu için şapkalı yazılır.

**Çeyrekler açıklığı:**

$$\widehat{\mathrm{IQR}} = 59 - 34 = 25$$

$$1.5 \cdot \widehat{\mathrm{IQR}} = 1.5 \cdot 25 = 37.5$$

**Üst sınır:**

$$59 + 37.5 = 96.5$$

96.5'ten büyük her değer aykırıdır. Veride böyle tek bir değer vardır: 139. 89 ise sınırın altında kalır. Yani 139 aykırı değerdir.

**Alt sınır:**

$$34 - 37.5 = -3.5$$

Bütün veriler $-3.5$'in üstündedir, dolayısıyla sol tarafta, yani küçük değerler tarafında aykırı değer yoktur.

**Sonuç:** CPU verisinin tek aykırı değeri 139'dur. Sınırlar ve aykırı değer python ile hesaplandı, aynı sonuç çıktı.

### 8.4 Aykırı Değer Bulunca Ne Yapmalı?

Hoca şu soruyu sordu: Veri topladınız ve aykırı değerler gördünüz. Ne yapmalısınız? İki görüş var.

Bazıları aykırı değerleri silmeyi önerir. Gerekçe şudur: Aykırı değerler ortalamayı ve varyansı çok değiştirir. Silinirse ortalama ve varyans tahminleri daha az etkilenir, belki daha iyi olur.

Başkaları ise silmenin iyi bir fikir olmayabileceğini, aykırı değerleri raporlamak gerektiğini söyler. Çünkü bunlar veride yeni bir eğilime (trend) ya da ilginç özel bir duruma işaret edebilir. Hocanın örneği: CPU birden daha yavaş çalışmaya başlamış olabilir. Belki sistemde bir sorun vardır.

Üçüncü bir yol da aykırı değerlerden çok etkilenmek istemiyorsanız dayanıklı istatistikler kullanmaktır: medyan ve IQR. Hoca burada daha önce söylemediği bir şeyi ekledi: IQR de dayanıklıdır. Gerekçesi şuydu: Önce sıralama yapıyoruz ve aritmetik yapmıyoruz, yalnızca veriyi sıralayıp içinden seçim yapıyoruz. Buna karşılık ortalama ve varyans dayanıklı değildir. Hoca karşılaştırma için varyans yerine standart sapmayı yazdı, çünkü birimi IQR'ye benzerdir. Yani bazı durumlarda ortalama ve standart sapma yerine medyan ve IQR kullanmak isteyebilirsiniz.

> **Ders sonrası not:** Hoca IQR için "aritmetik yapmıyoruz" dedi. IQR'nin kendisinde iki çeyreğin çıkarılması vardır, ama bu iki değer sıralamayla seçilir. Bu yüzden uçtaki bir değerin büyüklüğü sonuca girmez. CPU verisinde en büyük değer büyütülerek python ile hesaplandı: $\hat{Q}_1$, $\hat{Q}_3$ ve medyan değişmedi, ortalama ve standart sapma değişti.

## 9. Grafiksel İstatistik: Veriyi Önce Çizip Bakmak

Hoca önce bir bölümü bitirdiklerini söyledi, sonra kendini düzeltti: Hâlâ 8. bölümdeyiz. Bu bölümün son konusu grafiksel istatistiktir.

> **Hocanın vurgusu:** Kitap şunu söylüyor: Elinizde veri varsa, ortalama ya da medyan hesaplamak veya başka yöntemler kullanmak dahil, herhangi bir şey yapmadan önce veriyi çizin ve şekline bakın.

Bu grafikler bize şu konularda yardımcı olan bilgiler verir:

- Veri hangi olasılık dağılımından geliyor, hangi dağılım tarafından üretilmiş?
- Veride aykırı değer var mı?
- Zaman eğilimleri nelerdir? Veride zaman varsa, zaman geçtikçe bir şeyin artıp azaldığı görülebilir.
- Birden fazla değişken varsa, değişkenler arasındaki ilişkiler nelerdir?

Kullanılabilecek grafik türlerinden hoca şunları saydı:

- **Histogram:** Çok kullanışlıdır. Verinin olasılık dağılımı hakkında fikir verir.
- **Kutu grafiği (box plot).**
- **Zaman grafiği (time plot).**
- **Saçılım grafiği (scatter plot).**

Liste böyle devam eder. Veriyi görselleştirmenin birçok yolu vardır ve hepsi çok yardımcıdır. Bu derste histogramlar görüldü.

## 10. Histogram

### 10.1 Histogram Nasıl Çizilir?

Hoca önce çizimi gösterip özelliklerini sonra konuşmayı tercih etti. Adımlar şöyledir:

1. Veriyi sırala.
2. Kova genişliğine (bin size) ve kovalara karar ver.
3. Her kovaya düşen veri sayısını say.
4. Yatay eksene veri değerlerini, dikey eksene sayıyı koyarak çiz.

Hoca bu noktada Türkçeye geçti: "Bin" Türkçede galiba kova demektir. Küçük kovalar ayarlıyorsunuz ve her kovaya kaç veri düştüğünü hesap ediyorsunuz. Kısa nottaki "kutu" ile aynı şeydir.

Kovalara karar vermek için veriye bakmak gerekir. Bir de uzlaşım belirlemek gerekir: Bir sınır değer hangi kovaya düşecek? Hocanın seçimi alt sınırın dahil, üst sınırın hariç olmasıydı. Yani 0 ilk kovadadır, 14 ilk kovada değildir. Sonraki kova 14'ten 28'e gider, 28 ise bir sonrakine düşer.

### 10.2 CPU Verisinin Frekans Histogramı

CPU verisi için kova genişliği 14 seçildi. Kovalar $[0, 14)$, $[14, 28)$, $[28, 42)$ biçiminde devam eder. Hoca sayımı sırayla yaptı. İlk kovada yalnız bir değer vardır, o da 9'dur. $[14, 28)$ kovasında 5 değer vardır. Sonra sayılar artar ve daha sonra azalır. $[84, 98)$ kovasında tek değer vardır: 89. $[98, 112)$ ve $[112, 126)$ boştur, çünkü dizi 89'dan sonra doğrudan en büyük değere atlar. Son kova $[126, 140)$ içinde yine tek değer vardır: 139.

Sayımın tamamı aşağıdadır. Python ile hesaplandı ve toplam 30 çıktı.

| Kova | Sayı | Düşen değerler | Göreli frekans |
| :--- | :--: | :------------- | :------------- |
| $[0, 14)$ | 1 | 9 | $1/30$ |
| $[14, 28)$ | 5 | 15, 19, 22, 24, 25 | $5/30$ |
| $[28, 42)$ | 8 | 30, 34, 35, 35, 36, 36, 37, 38 | $8/30$ |
| $[42, 56)$ | 6 | 42, 43, 46, 48, 54, 55 | $6/30$ |
| $[56, 70)$ | 5 | 56, 56, 59, 62, 69 | $5/30$ |
| $[70, 84)$ | 3 | 70, 82, 82 | $3/30$ |
| $[84, 98)$ | 1 | 89 | $1/30$ |
| $[98, 112)$ | 0 | yok | $0$ |
| $[112, 126)$ | 0 | yok | $0$ |
| $[126, 140)$ | 1 | 139 | $1/30$ |

<!-- BELİRSİZ: Hoca [42, 56), [56, 70) ve [70, 84) kovalarının sayısını sözlü söylemedi, yalnızca çubukları çizdi. Tablodaki bu değerler veriden python ile sayıldı. -->

> **Ders sonrası not:** Hoca $[28, 42)$ kovası için 9 gözlem dedi ve göreli frekansı da $9/30$ yazdı. Doğrusu 8'dir, göreli frekans $8/30$'dur. 42, alt sınır dahil olduğu için bir sonraki kovaya düşer. Python ile hesaplandı. Ayrıca son kovadaki değer için altyazıda "135" ve "125" geçer. Veride bu değer 139'dur.

Bu sayılardan çizilen grafiğe frekans histogramı (frequency histogram) denir. Hoca yatay eksene veri değerlerini, dikey eksene sayıyı koydu. Aşağıda aynı sayılar yatay çubuklarla gösterilmiştir:

```text
kova          sayı
[0, 14)         1  #
[14, 28)        5  #####
[28, 42)        8  ########
[42, 56)        6  ######
[56, 70)        5  #####
[70, 84)        3  ###
[84, 98)        1  #
[98, 112)       0
[112, 126)      0
[126, 140)      1  #
```

### 10.3 Göreli Frekans Histogramı

Histogramın bir başka sürümü göreli frekans histogramıdır (relative frequency histogram). Yatay eksen aynıdır. Dikey eksende sayı yerine sayının toplam eleman sayısına bölümü vardır. CPU verisinde 30 eleman olduğu için ilk çubuk $1/30$, ikinci çubuk $5/30$ olur ve böyle devam eder.

Göreli frekans histogramının güzel yanı, bütün yüksekliklerin toplamının 1 olmasıdır:

$$\frac{1}{30} + \frac{5}{30} + \frac{8}{30} + \frac{6}{30} + \frac{5}{30} + \frac{3}{30} + \frac{1}{30} + 0 + 0 + \frac{1}{30} = \frac{30}{30} = 1$$

Bu neye benziyor? Bir olasılık dağılımına. Olasılık dağılımında da değerlerin olasılıkları toplanınca 1 eder. Dolayısıyla bu değerler oranlardır ve olasılıkları tahmin ederler.

> **Hocanın vurgusu:** Göreli frekans histogramı, verinin olasılık dağılımı hakkında fikir verir. Düşününce bu çok önemlidir. Çünkü dönemin neredeyse başından beri rastgele değişkenlerle ve onların olasılık dağılımlarıyla çalışıyoruz. Elimizde veri varsa ve göreli histogramını çizebiliyorsak, "verinin şu aralıkta olma olasılığı şudur" diyerek bir olasılık dağılımı benzeri kurmuş oluruz.

### 10.4 CPU Histogramından Ne Okuyoruz?

Hoca, çizdiği frekans histogramına bakarak şunları çıkardı:

- **Dağılım simetrik değildir.** Aslında sağa çarpıktır, sağ tarafta uzun bir kuyruk vardır.
- **Bir aykırı değer göze çarpar.** Daha IQR hesaplamadan görülür: Diğer değerler bir arada toplanmıştır, 139 ise tek başına uzakta durur. Bu, Bölüm 8.3'teki hesapla aynı sonuçtur.
- **Aykırı değer dışında veri homojendir.** Aykırı değeri saymazsak boş kova kalmaz ve sayılar önce artıp sonra azalır.
- **Olası model gama dağılımıdır.** Şekil bir gama dağılımına benzemektedir.

> **Hocanın vurgusu:** Belki de buradan öğrenebileceğimiz en önemli şey şudur: Bu veri için iyi bir model nedir? Şekil gamaya benzediği için veri büyük ihtimalle bir gama dağılımı tarafından üretilmiştir diyebiliriz. Sonra o gamanın $\alpha$ ve $\lambda$ parametrelerini bulmaya çalışırız. Bunları bulursak, o dağılımla birçok şey yapabiliriz.

## Dersin Toparlaması

Bu derste kantil fikri yüzdelik ve çeyrek adlarıyla genişletildi, ortalama ile medyanın farkı üzerinden iki kavram öne çıktı: çarpıklık ve dayanıklılık. Ortalama çarpık tarafa kayar ve tek bir uç değerle çok değişir, medyan ise neredeyse hiç etkilenmez. Yayılım tarafında örneklem varyansı $s^2$ ve onun neden $n-1$'e bölündüğü görüldü. Tahminlerin de rastgele değişken olduğu fikrinden standart hataya, oradan da iyi bir tahmin edicinin yansız ve standart hatası düşük olması gerektiğine varıldı.

Son olarak IQR tanımlandı ve aykırı değerin kesin ölçütü olarak 1.5 IQR kuralı CPU verisinde uygulandı, tek aykırı değerin 139 olduğu bulundu. Veriye bakmanın en temel yolu olarak histogram çizildi. Göreli frekans histogramı, veriden olası bir olasılık dağılımı modeline, burada gama dağılımına geçişi sağladı. Hoca 8. bölümün sonuna yaklaşıldığını, sonraki bölüm olarak büyük ihtimalle 10. bölüme başlanacağını söyledi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
