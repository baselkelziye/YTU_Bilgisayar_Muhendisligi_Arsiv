# Ders 9 Çalışma Özeti

## Genel Konular

- Dersin tarihi 10 Aralık 2020 Perşembe. Ders Zoom üzerinden, İngilizce işlendi.
  - Asıl anlatım yaklaşık 00:06'da başlar. Öğrenci soruları üzerine bazı kısımlar Türkçe tekrar edildi.
- Merkezi limit teoremi (central limit theorem, CLT)
  - Bağımsız ve özdeş dağılmış (i.i.d.) değişkenlerin toplamı
  - Sabit disk ve 300 resim örneği
  - Binom, gama ve negatif binomun normal ile yaklaşık hesaplanması
  - Süreklilik düzeltmesi (continuity correction)
- Baron'un kitabında 4. bölüm (sürekli dağılımlar) bitti. Olasılık kısmı tamamlandı.
- İstatistiğe giriş (Baron, 8. bölüm)
  - Popülasyon (population), parametre, örneklem (sample), örnekleme (sampling)
  - İstatistik = tahmin (estimate); $\hat{\theta}$ gösterimi
  - Örnekleme hatası (sampling error) ve örnekleme dışı hata (non-sampling error)
  - Basit rastgele örnekleme (simple random sampling) ve banka hesabı örneği
- Betimleyici istatistikler (descriptive statistics)
  - Örneklem ortalaması (sample mean): beklenen değeri, varyansı, dağılımı
  - İyi tahmin edicinin özellikleri: yansızlık (unbiasedness), tutarlılık (consistency), asimptotik normallik (asymptotic normality)
  - Popülasyon medyanı ve örneklem medyanı (median)
  - Kantiller (quantiles) ve CPU verisi örneği
- İkinci vize duyurusu (17 Aralık 2020)

## Hocanın Özellikle Vurguladığı Kısımlar

- CLT pratikte $n \ge 30$ ise kullanılır.
  - Teorem aslında $n \to \infty$ için geçerlidir. Bu yüzden CLT ile yapılan hesap yaklaşık bir hesaptır.
- Toplanan değişkenler zaten normal ise toplam her $n$ için normaldir. $n < 30$ olsa da normal kabul edilir.
- Süreklilik düzeltmesi yalnızca kesikli bir dağılımı sürekli bir dağılımla yaklaşık hesaplarken yapılır.
  - Gama (sürekli) normal ile (sürekli) yaklaşık hesaplanırken düzeltme yapılmaz.
- Tahmin, gerçek parametre değildir. İkisini karıştırmayın.
  - Popülasyonun gerçek değerini hiçbir zaman bulamayız; her tahminde bir hata vardır. Bu yüzden tahminler şapkalı yazılır.
  - Çok önemli parametrelerin tahminlerine özel ad verilir: $\mu$'nün tahmini $\bar{X}$ (örneklem ortalaması), varyansın tahmini $s^2$ (örneklem varyansı).
- Örnekleme dışı hatayı yok etmek için basit rastgele örnekleme kullanın.
  - Türkiye'deki ağırlıkları ölçmek için yalnızca İstanbul'dan örnek almak yanlıştır.
- Örneklem ortalamasının beklenen değeri popülasyonun beklenen değeridir. Hoca bunu "önemli" diye işaretledi.
- Kantil hesabında yuvarlama bir uzlaşımdır (convention). Bu derste "round" kullanılacak.
- İkinci vize, bu dersin sonuna kadar işlenen konuları kapsıyor.

## Kısa Tekrar Notları

- CLT: $X_1, \dots, X_n$ i.i.d., $E[X_i] = \mu$, $\mathrm{Var}(X_i) = \sigma^2$ ise $S_n = X_1 + \dots + X_n$ için:
  - $n$ büyüdükçe $S_n \approx N(n\mu, \; n\sigma^2)$ (ortalama $n\mu$, varyans $n\sigma^2$).
  - Standartlaştırma: $Z = \frac{S_n - n\mu}{\sigma\sqrt{n}}$
- Toplam olarak yazılabilen dağılımlar ($n \ge 30$ ise normal ile yaklaşık hesaplanabilir):
  - Binom = Bernoulli toplamı (kesikli)
  - Gama = üstel toplamı (sürekli)
  - Negatif binom = geometrik toplamı (kesikli)
- Süreklilik düzeltmesi: $P(X = 5) \approx P(4.5 < Y < 5.5)$, $P(X < 10) \approx P(Y < 9.5)$
- Örnekleme hatası örneklem büyüklüğünden gelir; $n \to \infty$ iken sıfıra gider. Örnekleme dışı hata yanlış yöntemden gelir.
- Basit rastgele örnekleme: birimler bütün popülasyondan, birbirinden bağımsız ve eşit olasılıkla seçilir.
- Örneklem ortalaması: $\bar{X} = \frac{1}{n}\sum_{i=1}^n X_i$
  - $E[\bar{X}] = \mu$, $\mathrm{Var}(\bar{X}) = \sigma^2/n$, $\mathrm{Std}(\bar{X}) = \sigma/\sqrt{n}$
  - $n$ büyükse $\bar{X}$ normal dağılır (CLT). $n$ küçükse $t$ dağılımı kullanılır.
- Yanlılık: $\mathrm{Bias}(\hat{\theta}) = E[\hat{\theta} - \theta]$. Yanlılık sıfırsa $\hat{\theta}$ yansızdır.
- Tutarlılık: her $\varepsilon > 0$ için $n \to \infty$ iken $P(|\hat{\theta} - \theta| > \varepsilon) \to 0$.
- Asimptotik normallik: $n \to \infty$ iken $\hat{\theta}$'nın dağılımı normale gider.
- $\bar{X}$ yansız, tutarlı ve asimptotik normaldir.
- Popülasyon medyanı $M$: $P(X > M) \le 0.5$ ve $P(X < M) \le 0.5$. Sürekli dağılımda $F(M) = 0.5$.
  - Örnek: $F(x) = 1 - e^{-\lambda x}$ için $M = \ln 2 / \lambda$.
- $p$-kantil $q_p$: $P(X < q_p) \le p$ ve $P(X > q_p) \le 1 - p$. Sürekli dağılımda $F(q_p) = p$, yani $q_p = F^{-1}(p)$.
- Örneklem $p$-kantili için basit yöntem: veriyi sırala; $p(n+1)$. sıradaki değeri al. Tamsayı değilse yuvarla.

## Detaylı Açıklamalar

### Merkezi limit teoremi

- $X_1, \dots, X_n$ bağımsız ve özdeş dağılmış (independent and identically distributed) olsun.
  - Bağımsız: $X_1$'in aldığı değer $X_2$'nin değerini etkilemez.
  - Özdeş dağılmış: hepsi aynı dağılımdan gelir; ortalamaları ve varyansları aynıdır.
- Toplamları $S_n$ da bir rastgele değişkendir.
- CLT: $n \to \infty$ iken $S_n$'nin dağılımı normal dağılıma gider. Ortalama $n\mu$, varyans $n\sigma^2$ olur.

### Örnek: Sabit diskte yer yeter mi?

- Sabit diskte 330 MB boş yer var. 300 bağımsız resim indirilecek.
- Resimlerin boyutunun dağılımı bilinmiyor. Ortalama 1 MB, standart sapma 0.5 MB (varyans $0.25$ MB²).
- İstenen: $P(S_{300} \le 330)$.
  - Hoca Türkçe açıkladı: Resimler daha indirilmediği için her birinin boyutu bir rastgele değişkendir. Ortalama boyutu önceki bir çalışmadan biliyoruz.
- $n = 300 \ge 30$ olduğu için CLT kullanılır:
  - $S_{300} \approx N(300 \cdot 1, \; 300 \cdot 0.25) = N(300, 75)$
  - $P(S_{300} \le 330) = \Phi\left(\frac{330 - 300}{\sqrt{75}}\right) = \Phi(3.46) \approx 0.9997$
- Dikkat: Paydada varyans değil, standart sapma ($\sqrt{75}$) kullanılır.

### Süreklilik düzeltmesi

- Kesikli dağılımda tek bir noktanın olasılığı vardır (PMF). Sürekli dağılımda tek noktanın olasılığı sıfırdır.
- Bu yüzden kesikli bir değeri sürekli yaklaşımda 1 birim genişliğinde bir aralık olarak düşünürüz.
  - $P(X = 5)$ yerine $P(4.5 < Y < 5.5)$ hesaplanır.
- Örnek: $X$ negatif binom olsun ve normal ile yaklaşık hesaplansın.
  - Yaklaşımda 10 değeri $[9.5, 10.5]$ aralığına karşılık gelir.
  - $P(X < 10)$ için $P(Y < 9.5)$ hesaplanır.

### İstatistiğe giriş: popülasyon ve örneklem

- Popülasyon: ilgilendiğimiz bütün birimler. Örnek: Türkiye'deki herkesin ağırlığı.
- Popülasyonun bir olasılık dağılımı, bu dağılımın da parametreleri vardır.
  - Ağırlıklar normal dağılıyorsa parametreler $\mu$ ve $\sigma$'dır. Parametreleri bilirsek bütün dağılımı biliriz.
- Gerçek $\mu$ için yaklaşık 83 milyon kişinin ağırlığı gerekir. Bu çok pahalıdır, pratikte yapılamaz.
- Bunun yerine rastgele 1000 kişi seçilir ve ağırlıkları ölçülür. Buna örnekleme denir.
  - Örnekleme bir veri toplama işidir. Toplanan verinin popülasyonu temsil etmesi beklenir.
- Örneklemden hesaplanan değer gerçek $\mu$ değil, onun tahminidir.
  - Genel gösterim: $\theta$ parametresinin tahmini $\hat{\theta}$. Örneğin gamanın $\alpha$ ve $\lambda$ parametreleri $\hat{\alpha}$ ve $\hat{\lambda}$ ile tahmin edilir.
  - Tahminlere istatistik (statistics) denir.

### Hata kaynakları

- Örneklem ile popülasyon arasındaki fark tahminlerde hata olarak görünür. İki kaynağı vardır:
  - Örnekleme hatası: örneklemin sınırlı olmasından gelir. Daha çok örnek alınırsa azalır. Bütün popülasyon kullanılırsa sıfır olur.
  - Örnekleme dışı hata: yanlış yöntemden gelir. Basit rastgele örnekleme ile önlenir.
- Basit rastgele örneklemenin şartları:
  - Birimler bütün popülasyondan seçilir.
  - Seçimler birbirinden bağımsızdır. Benim seçilmem, aynı apartmandaki birinin seçilme olasılığını etkilemez.
  - Bütün birimlerin seçilme olasılığı eşittir.
- Banka örneği: Bir banka $N$ hesabından 1000'ini rastgele seçmek istiyor.
  - $X_1 \sim U(0, N)$ sayısı üretilir. Hesap numarası $\lceil X_1 \rceil$ olur.
  - Seçilen hesap tekrar seçilmemeli. Sonraki sayı $X_2 \sim U(0, N-1)$ ile kalan hesaplar arasından seçilir.

### Örneklem ortalaması

- Örneklem, toplanmadan önce bir rastgele değişken listesi (tuple) olarak düşünülür: $S = (X_1, \dots, X_n)$.
  - Hoca Türkçe açıkladı: Değerleri toplamadan önce bilmediğimiz için her birine rastgele değişken gözüyle bakarız.
- Veri toplandıktan sonra elimizde gerçek değerler olur. Örnek veri olarak Baron'un kitabındaki CPU verisi ($n = 30$) kullanıldı.
- $\bar{X} = \frac{1}{n}\sum X_i$ popülasyon ortalaması $\mu$'yü tahmin eder.
- $\bar{X}$ de bir rastgele değişkendir, çünkü rastgele değişkenlerin toplamıdır.
- Beklenen değeri:
  - $E[\bar{X}] = \frac{1}{n}\left(E[X_1] + \dots + E[X_n]\right) = \frac{1}{n} \cdot n\mu = \mu$
  - Bir gözlemin, seçilmeden önceki beklenen değeri popülasyonun beklenen değeridir.
- Varyansı: $\mathrm{Var}(\bar{X}) = \sigma^2/n$. İspatı ev ödevi.
- Dağılımı: $n$ büyükse normal (CLT). $n$ küçükse $t$ dağılımı kullanılır.

### İyi bir tahmin edicinin özellikleri

- Yansızlık:
  - Yanlılık, hatanın beklenen değeridir: $\mathrm{Bias}(\hat{\theta}) = E[\hat{\theta} - \theta]$.
  - Yanlı bir tahmin edicinin tahminleri hep aynı yönde kayar. Yansız bir tahmin edicinin tahminleri $\theta$ etrafında toplanır.
  - $\bar{X}$ yansızdır. Gösterilmesi ev ödevi.
- Tutarlılık:
  - $n \to \infty$ iken hatanın bir eşiği ($\varepsilon$) aşma olasılığı sıfıra gider.
  - $\bar{X}$ tutarlıdır. Gösterilmesi ev ödevi.
- Asimptotik normallik:
  - $n \to \infty$ iken tahmin edicinin dağılımı normale gider.
  - $\bar{X}$ asimptotik normaldir; bu CLT'den gelir.

### Medyan

- Medyan, popülasyonun merkezini ölçen başka bir değerdir. Aykırı değerlere (outliers) karşı dayanıklıdır (robust).
- Popülasyon medyanı $M$, tahmini (örneklem medyanı) $\hat{M}$.
- Sürekli dağılım: $F(M) = 0.5$ denklemi çözülür.
  - Örnek: $F(x) = 1 - e^{-\lambda x}$ ($x > 0$). $1 - e^{-\lambda M} = 0.5$, buradan $M = \ln 2 / \lambda$.
- Kesikli dağılım: CDF basamaklıdır. İki durum vardır:
  - Çok kök: 0.5 değeri CDF'nin yatay bir basamağına denk gelir. O basamaktaki bütün değerler medyandır. Örnek: CDF $[1, 2)$ aralığında 0.5 ise $[1, 2)$'deki her sayı medyandır.
  - Kök yok: CDF 0.5'i atlar. Bu durumda $F(x) \ge 0.5$ olan en küçük $x$ medyandır.
- Örneklem medyanı: veriyi sırala, ortadaki değeri al.
  - Örnek: $(2, 2, 3)$ için medyan 2.
  - Eleman sayısı çift ise iki orta değer olur. $(2, 2, 3, 3)$ için Baron'a göre $[2, 3]$ aralığındaki her sayı medyandır.

### Kantiller

- Kantil, medyanın genelleştirilmiş hâlidir. Medyan 0.5-kantildir.
- Popülasyon $p$-kantili $q_p$: $P(X < q_p) \le p$ ve $P(X > q_p) \le 1-p$.
  - Sürekli dağılımda $F(q_p) = p$. Kantil, CDF'nin tersi gibi düşünülebilir: $q_p = F^{-1}(p)$.
  - Yoğunluk grafiğinde $q_p$'nin solundaki alan $p$'dir.
- Örneklem $p$-kantili $\hat{q}_p$: örneklemin en fazla $100p$%'si ondan küçük, en fazla $100(1-p)$%'si ondan büyüktür.
- Basit yöntem:
  - Örneklemi sırala.
  - $\hat{q}_p$, sıralı örneklemde $p(n+1)$. sıradaki değerdir.
  - $p(n+1)$ tamsayı değilse yuvarlanır (bu derste uzlaşım) ya da iki komşu değerin ortalaması alınır.
- CPU verisi örneği ($n = 30$), sıralı veri:
  - 9, 15, 19, 22, 24, 25, 30, 34, 35, 35, 36, 36, 37, 38, 42, 43, 46, 48, 54, 55, 56, 56, 59, 62, 69, 70, 82, 82, 89, 139
  - 0.25-kantil: $0.25 \cdot 31 = 7.75$, yuvarlanınca 8. değer, yani 34.
  - 0.75-kantil: $0.75 \cdot 31 = 23.25$, yuvarlanınca 23. değer, yani 59.
  - Medyan (0.5-kantil): ev ödevi olarak bırakıldı. Sonuç için "Ders sonrası notlar"a bakın.

### İkinci vize duyurusu

- İkinci vize gelecek hafta, 17 Aralık 2020'de, Online YıldızEdu üzerinden yapılacak.
  - Vizeden sonra normal ders işlenecek.
  - Kapsam: bugün işlenen konular dahil.
  - Hoca sınavın büyük ihtimalle (yaklaşık %90) test olacağını söyledi.
  - Başlangıç saati altyazıda net değil. Hoca önce "dokuz" dedi, sonra 13 diye düzeltti gibi görünüyor.
  - Derste bir öğrenci sınav gününde değişiklik olup olmadığını sordu. Hoca "şimdilik 17 Aralık, değişirse e-postayla bildiririm" dedi.
  - Sonraki kayıtlara göre tarih değişmiş: 17 Aralık'ta (ders 10) bir quiz yapıldı ve ikinci vize bir hafta sonraya (24 Aralık) kaydı.

### Ders sonrası notlar

- Disk örneğinin sonucu Python ile doğrulandı: $\Phi(30/\sqrt{75}) = \Phi(3.464) \approx 0.99973$.
- Hoca $\mathrm{Var}(\bar{X})$'i açıklarken "popülasyondaki birim sayısına bölünür" dedi. Doğrusu: $\sigma^2$, örneklemdeki birim sayısı $n$'e bölünür.
- Medyan örneğinde hoca $F(x) = 1 - e^{-\lambda x}$ ifadesine "$f$ of $x$" dedi. Bu ifade yoğunluk değil, CDF'dir (üstel dağılımın CDF'si).
- Kantil tanımında hoca "$P(X < q_p) = p$" dedi. Genel tanım eşitsizliktir: $P(X < q_p) \le p$ ve $P(X > q_p) \le 1-p$. Eşitlik sürekli dağılımlarda geçerlidir.
- CPU örneğinde hoca "34 ile 35 arasındaki her değer 0.25-kantildir" dedi. Baron'un tanımıyla kontrol: 34'ten küçük 7 değer var ($\le 7.5$), büyük 22 değer var ($\le 22.5$); iki koşul da sağlanır. 35 için küçük değer sayısı 8'dir ve 7.5'i aşar. Bu yüzden 0.25-kantil tam olarak 34'tür.
- Hoca derste medyanın "S16, yani 48" olduğunu söyledi. Sıralı veride 16. değer 43'tür, 48 değil (Python ile kontrol edildi).
  - $0.5 \cdot 31 = 15.5$; 15. değer 42, 16. değer 43. İki değerin ortası olarak medyan $42.5$ alınır. Baron'un tanımına göre 42 ile 43 arasındaki her sayı medyandır.
- Altyazıda "teta het", "Bayes of theta hat" gibi geçen terim "bias" (yanlılık) demektir. "Bayes" teoremiyle ilgisi yoktur.
- 00:27:38–00:34:31 ve 01:13:57–01:20:03 arasındaki Türkçe açıklamalar İngilizce modunda bozuk çevrildi; bu kısımlarda uzun döngüler var. Özette yalnızca anlaşılır kısımlar kullanıldı.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz. Bu ders İngilizce anlatıldığı için altyazı da İngilizcedir.
