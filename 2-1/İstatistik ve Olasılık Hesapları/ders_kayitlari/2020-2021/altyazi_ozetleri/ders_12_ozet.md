# Ders 12 Çalışma Özeti

## Genel Konular

- Dersin tarihi 31 Aralık 2020 Perşembe. Ders Zoom üzerinden işlendi.
  - Önceki dersin tekrarı Türkçe, geri kalanı İngilizce anlatıldı.
  - Hocanın saat 15:00'te toplantısı olduğu için ders erken bitti.
- Tekrar: histogram ve göreli frekans histogramı
- Sık görülen histogram şekilleri
  - Düzgün, üstel ve normal görünümlü histogramlar
  - Karışım dağılımları (mixture distributions): iki tepeli (iki hörgüçlü) histogram
- Kutu grafiği (box plot) ve paralel kutu grafikleri
- Saçılım grafiği (scatter plot): antivirüs örneği
- Zaman grafiği (time plot): dünya nüfusu örneği
- Baron'un kitabında 8. bölüm bitti.
- 9. bölüme giriş: istatistiksel çıkarım (statistical inference) ve parametre tahmini (parameter estimation)
  - Momentler yöntemi (method of moments) ve gama örneği
  - En çok olabilirlik yöntemi (method of maximum likelihood) ve Poisson örneğinin kurulması

## Hocanın Özellikle Vurguladığı Kısımlar

- Göreli frekans histogramı, gözleme dayalı (empirical) bir olasılık dağılımı verir.
  - Örnek: CPU verisinde bir gözlemin 0–14 aralığında olma olasılığı yaklaşık $1/30$'dur.
- Histogramın şekli, veriyi üreten dağılım ailesi hakkında fikir verir. Verinin homojen mi yoksa bir karışım mı olduğu da histogramdan görülür.
- Dağılımın parametresini bulursanız dağılımı bilirsiniz.
  - Sonra ortalama, medyan gibi her şeyi hesaplayabilir, gelecek değerleri tahmin edebilirsiniz.
- Momentler yöntemi çok kolaydır: kaç bilinmeyen varsa o kadar moment eşitliği yazıp çözün.
- Momentler yöntemiyle bir kez genel formül çıkarırsanız aynı aileden her veri için tekrar kullanabilirsiniz.
- Tahminleri şapkalı yazın ($\hat{\lambda}$, $\hat{\alpha}$).
- En çok olabilirlikte olabilirliğin kendisi yerine logaritmasını maksimize edin.
  - Çarpım toplama dönüşür, terimlerin türevi ayrı ayrı alınır, hesap kolaylaşır. Maksimumun yeri değişmez.
- Kritik noktalarda sınır noktalarını unutmayın. Türevin sıfır olduğu her nokta maksimum değildir (minimum veya büküm noktası olabilir).
- Poisson ile en çok olabilirlik örneğinin çözümü ev ödevi.

## Kısa Tekrar Notları

- Histogram şekli ve aday dağılım:
  - Sayılar yaklaşık sabit: düzgün dağılım.
  - Büyük değerden başlayıp azalıyor: üstel dağılım.
  - Simetrik, çan şeklinde: normal dağılım.
  - İki tepe: iki dağılımın karışımı.
- Karışım dağılımı: $F(x) = p_1 F_1(x) + p_2 F_2(x)$, $p_1 + p_2 = 1$.
- Kutu grafiği: kutu $Q_1$'den $Q_3$'e uzanır. İçteki çizgi medyan, artı işareti ortalamadır.
  - Bıyıklar (whiskers) aykırı olmayan en küçük ve en büyük gözleme kadar uzanır.
  - Aykırı değerler (kutudan 1.5 IQR'den daha uzaktakiler) ayrı noktalar olarak çizilir.
- Saçılım grafiği: aynı anda (aynı durumda) ölçülen iki değişkenin $(x, y)$ çiftleri.
- Zaman grafiği: yatay eksen zamandır; eğilimleri ve dış değer kestirimini (extrapolation) gösterir.
- Moment:
  - $k$. popülasyon momenti: $\mu_k = E[X^k]$
  - $k$. örneklem momenti: $m_k = \frac{1}{n}\sum_{i=1}^n X_i^k$
  - $k$. popülasyon merkezi momenti: $\mu'_k = E[(X - \mu)^k]$
  - $k$. örneklem merkezi momenti: $m'_k = \frac{1}{n}\sum_{i=1}^n (X_i - \bar{X})^k$
  - $\mu_1$ ortalama, $\mu'_2$ varyanstır.
- Momentler yöntemi: $\mu_1 = m_1$, $\mu'_2 = m'_2$, ... eşitliklerini bilinmeyen sayısı kadar yaz ve çöz.
- Gama için momentler tahmini: $\hat{\lambda} = \frac{\bar{X}}{m'_2} = \frac{n}{n-1}\cdot\frac{\bar{X}}{s^2}$, $\hat{\alpha} = \hat{\lambda}\bar{X}$.
- Olabilirlik (i.i.d. veri):
  - Kesikli: $L = \prod_{i=1}^n P(x_i)$
  - Sürekli: $L = \prod_{i=1}^n f(x_i)$
- En çok olabilirlik: $\ln L$'yi maksimize eden parametreyi bul. $\frac{d \ln L}{d\theta} = 0$ çöz, sınırları da kontrol et.

## Detaylı Açıklamalar

### Tekrar: histogram (Türkçe anlatıldı)

- Veri aralığı kutulara (bin) bölünür. Her kutudaki gözlem sayısı bir çubukla gösterilir.
- CPU verisi 9'dan 139'a kadar gider. 14 genişliğinde kutularla 0–14, 14–28, 28–42, ... aralıkları kullanıldı.
- Histogram, verinin geldiği dağılımın şeklini kabaca gösterir. CPU verisinin şekli gamaya benziyordu. Grafikte bir aykırı değer vardı. Veri homojendi, yani birden çok dağılımın karışımı değildi.
- Sayılar toplam gözlem sayısına bölünürse göreli frekans histogramı elde edilir. Bu değerlerin toplamı 1'dir ve bir olasılık dağılımı gibi okunur.

### Sık görülen histogram şekilleri

- Sayılar az çok sabitse veri muhtemelen düzgün dağılımdan gelir.
- Sayılar büyük bir değerden başlayıp azalıyorsa veri üstel dağılımdan gelebilir.
- Simetrik ve çan şeklindeyse normal dağılım olabilir.
- Karışım dağılımları:
  - Histogramda iki tepe (hump) görülebilir. Hoca Türkçe karşılığını "devenin hörgücü" diye verdi.
  - Bu, örneklemde iki farklı grubun karıştığını gösterir. Örnekler: kadın ve erkek, lisans ve lisansüstü öğrenciler, gündüz ve gece internet kullanımı.
  - Örneğin ağırlık verisinde bir grup $\mu_1$, diğeri $\mu_2$ etrafında toplanabilir. Bu durumda veri iki normal dağılımın karışımıdır.
  - Bir gözlem $p_1$ olasılıkla birinci dağılımdan, $p_2$ olasılıkla ikinci dağılımdan gelir. CDF: $F(x) = p_1 F_1(x) + p_2 F_2(x)$.
  - $F_1$ ve $F_2$, histogramda gördüğünüz dağılımlara göre seçilir. İkisinin normal olması gerekmez.

### Kutu grafiği

- Kutu $Q_1$ (0.25-kantil) ile $Q_3$ (0.75-kantil) arasındadır.
- Kutunun içindeki çizgi medyanı ($Q_2$), artı işareti ortalamayı gösterir.
- Kutudan iki yana çizgiler çıkar. Bu çizgiler verinin en küçük ve en büyük değerine kadar uzanır.
- Aykırı değerler bu çizgilerin dışında ayrı noktalar olarak gösterilir.
  - Bu yüzden çizginin ucu, aykırı olmayan en büyük değerdir. Sınır $Q_3 + 1.5\,\mathrm{IQR}$'dir; alt tarafta da $Q_1 - 1.5\,\mathrm{IQR}$ kullanılır.
- Kutu grafiği veriyi kısa ve öz biçimde özetler.
- Paralel kutu grafikleri:
  - Veri önce kategorilere ayrılır (örneğin haftanın günleri), her kategori için bir kutu çizilir.
  - Örnek: Günlere göre internet kullanımı. Cuma günü (tatilden hemen önce) kullanım yüksek. Cumadan salıya düşüyor, salıdan sonra tekrar artıyor.
  - Kutuların dışında, iki tarafta da aykırı değerler görülebilir.

### Saçılım grafiği

- İki rastgele değişken aynı zamanda veya aynı durumda ölçülürse kullanılır.
- Kitaptaki örnek:
  - $X$: bir ayda antivirüs yazılımının kaç kez çalıştırıldığı.
  - $Y$: o ay bulunan virüs sayısı.
  - Örnek veriler: (30, 0), (30, 0), (30, 1), (15, 0), (15, 1), (10, 2), (6, 1), (6, 2), ...
- Her $(x, y)$ çifti grafikte bir nokta olur.
  - Bu grafikle "daha sık tarama daha çok virüs bulur mu?" gibi sorular cevaplanabilir.
- Sorun: Aynı çift birden çok kez gözlenince tek bir nokta gibi görünür. (30, 0) iki kez görülse de grafikte (30, 1) ile aynı ağırlıkta görünür.
  - Çözüm: sayıyı gösteren farklı semboller kullanmak. Kitapta 1 gözlem için A, 2 için B, 3 için C yazılır.
  - Daire, üçgen, kare gibi şekiller veya renkler de kullanılabilir.
  - Sayıyı üçüncü eksene koyan 3 boyutlu grafik veya yüzey de çizilebilir.
- Python'da `matplotlib` kütüphanesi bu grafiklerin çoğunu çizer.

### Zaman grafiği

- Saçılım grafiğine benzer, ama yatay eksen zamandır.
- Örnek: 1950'lerden 2020'lere dünya nüfusu.
- Eğilimleri gösterir. Eğilim kullanılarak ileriye doğru kestirim yapılabilir; örneğin 2030'daki nüfus.

### İstatistiksel çıkarım ve parametre tahmini

- Baron'un 9. bölümü istatistiksel çıkarımdır: veriden bilgi çıkarmak. İlk konu parametre tahminidir.
- Senaryo:
  - Elimizde veri var. Histogramı çiziyoruz ve verinin üstel dağılımdan geldiğini düşünüyoruz.
  - Üstel yoğunluk $f(x) = \lambda e^{-\lambda x}$'tir. Her $\lambda$ farklı bir üstel dağılım verir.
  - $\lambda$'yı bilirsek veriyi üreten dağılımı biliriz.
  - Veri için $\lambda$ sabittir; $x$ değişkendir. $\lambda$ bir parametredir ve tahmin edilmesi gerekir.
- Diğer örnekler: gamada $\alpha$ ve $\lambda$, normalde $\mu$ ve $\sigma$.
- İki yöntem görülecek: momentler yöntemi ve en çok olabilirlik yöntemi.

### Momentler

- $X$'in $k$. momenti, $X^k$'nın beklenen değeridir: $E[X]$ birinci, $E[X^2]$ ikinci, $E[X^3]$ üçüncü momenttir.
- Popülasyon momentleri parametreye bağlı ifadelerdir. Örneklem momentleri ise veriden hesaplanan sayılardır.
  - Örneklem momentinde beklenen değer yerine ortalama alınır: $m_k = \frac{1}{n}\sum X_i^k$.
- Merkezi momentlerde önce ortalama çıkarılır, böylece ortalama sıfıra çekilir.
  - Popülasyonda $\mu$ çıkarılır. Örneklemde $\mu$ bilinmediği için onun tahmini $\bar{X}$ çıkarılır.
- Bildiğimiz iki moment:
  - Birinci moment ortalamadır.
  - İkinci merkezi moment varyanstır.

### Momentler yöntemi

- Popülasyon momentleri ile örneklem momentleri birbirine eşitlenir.
  - Sol taraf parametreye bağlı bir ifade, sağ taraf veriden hesaplanan bir sayıdır. Böylece bir denklem elde edilir.
- Bilinmeyen sayısı kadar denklem yazılır ve bilinmeyenler için çözülür.
- Örnek: Veri $(4, 6, 2)$, gama dağılımından geldiği varsayılıyor. Bilinmeyenler $\alpha$ ve $\lambda$, yani iki denklem gerekir.
  - Gama için $E[X] = \alpha/\lambda$, $\mathrm{Var}(X) = \alpha/\lambda^2$.
  - $\mu_1 = m_1$: $\alpha/\lambda = (4+6+2)/3 = 4$.
  - $\mu'_2 = m'_2$: $\alpha/\lambda^2 = \frac{(4-4)^2 + (6-4)^2 + (2-4)^2}{3} = 8/3$.
  - İkinci denklemde $\alpha/\lambda = 4$ yerine konur: $4/\lambda = 8/3$, buradan $\hat{\lambda} = 3/2$.
  - Sonra $\hat{\alpha} = 4\hat{\lambda} = 6$. Bu adım ev ödevi olarak bırakıldı.
- Genel formül (gama):
  - $\alpha/\lambda = \bar{X}$.
  - $\alpha/\lambda^2 = \frac{1}{n}\sum (X_i - \bar{X})^2 = \frac{n-1}{n}s^2$.
  - Bölünce: $\hat{\lambda} = \frac{\bar{X}}{\frac{n-1}{n}s^2} = \frac{n}{n-1}\cdot\frac{\bar{X}}{s^2}$.
  - Bu formül her gama verisi için tekrar kullanılabilir.

### En çok olabilirlik yöntemi

- Olabilirlik (likelihood) $L$, gözlenen verinin olasılığıdır.
- Genel durumda zincir kuralı gerekir: $P(x_1)P(x_2 \mid x_1)P(x_3 \mid x_1, x_2)\cdots$
- Veri basit rastgele örneklemeyle toplandıysa gözlemler bağımsız ve özdeş dağılmıştır (i.i.d.). Koşullar kalkar:
  - Kesikli durum: $L = \prod_{i=1}^n P(x_i)$ (PMF'lerin çarpımı).
  - Sürekli durum: $L = \prod_{i=1}^n f(x_i)$ (yoğunlukların çarpımı).
- Yöntem: $L$'yi maksimize eden parametreleri bul. Bu bir optimizasyon problemidir.
  - Parametreye göre türev al ve sıfıra eşitle. Çözümler kritik noktalardır.
  - Kritik noktaların hepsi maksimum değildir: minimum veya büküm noktası (inflection point) olabilir.
  - Parametre bir $[a, b]$ aralığında aranıyorsa $a$ ve $b$ sınır noktaları da kritik noktadır. Orada türev sıfır olmasa da olabilirlik çok büyük olabilir.
  - Bütün kritik noktalarda olabilirliği karşılaştır, en büyüğü seç.
- Logaritma hilesi:
  - $\ln L$, $L$ ile aynı noktada maksimum olur.
  - $\ln \prod P(x_i) = \sum \ln P(x_i)$. Çarpımın türevi yerine terimlerin türevleri ayrı ayrı alınır.
- Örnek (kurulum): Verinin Poisson dağılımından geldiği varsayılıyor. $P(x) = e^{-\lambda}\lambda^x/x!$, tek parametre $\lambda$.
  - $\frac{d}{d\hat{\lambda}} \ln \prod_{i=1}^n \frac{e^{-\lambda}\lambda^{x_i}}{x_i!} = 0$ çözülecek.
  - Hoca çözümü ev ödevi olarak bıraktı.

### Ders sonrası notlar

- Poisson örneğinin çözümü (ev ödevi için kontrol):
  - $\ln L = -n\lambda + \left(\sum x_i\right)\ln\lambda - \sum \ln(x_i!)$
  - $\frac{d \ln L}{d\lambda} = -n + \frac{\sum x_i}{\lambda} = 0$, buradan $\hat{\lambda} = \bar{X}$.
  - İkinci türev $-\sum x_i/\lambda^2 < 0$ olduğu için bu nokta maksimumdur.
  - Altyazıda veri "464 to" diye geçiyor; $(4, 6, 4, 2)$ veya $(4, 6, 2)$ olabilir. İki durumda da $\hat{\lambda} = 4$ çıkar.
- Gama örneğinin tamamı (Python ile kontrol): $\hat{\lambda} = 1.5$, $\hat{\alpha} = 6$. Kontrol: $6/1.5 = 4 = \bar{X}$, $6/1.5^2 = 8/3$.
- Hoca üstel dağılımın birinci momentini "$\lambda$", varyansını "$\lambda^2$ galiba" dedi. Doğrusu $E[X] = 1/\lambda$, $\mathrm{Var}(X) = 1/\lambda^2$'dir.
- Üçüncü örneklem momentini anlatırken hoca "$X_i$'nin karesi" dedi. Doğrusu $m_3 = \frac{1}{n}\sum X_i^3$'tür.
- Merkezi moment ilk önce $E[X^k - \mu]$ gibi yazıldı. Hoca sonra bunu düzeltti: üs parantezin dışındadır, $E[(X-\mu)^k]$.
- Tekrar kısmında hoca "0–28 arasında beş gözlem" ve "28–42 arasında 9 gözlem" dedi. Doğrusu 14–28 aralığında 5, 28–42 aralığında 8 gözlemdir. Verinin en büyük değeri 135 değil, 139'dur.
- Zincir kuralı yazılırken altyazıda çarpanlar arasında "plus" geçiyor. Olabilirlik bir çarpımdır, toplam değildir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz. Bu ders İngilizce anlatıldığı için altyazı da İngilizcedir.
