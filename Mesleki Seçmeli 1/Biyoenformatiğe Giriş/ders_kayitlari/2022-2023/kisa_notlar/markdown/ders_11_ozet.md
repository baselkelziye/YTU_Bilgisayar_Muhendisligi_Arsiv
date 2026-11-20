# Ders 11 Çalışma Özeti

## Genel Konular

- İstatistiksel veri analizine giriş ve veri türleri
  - Veri toplandıktan sonraki adım, büyük resmi görmek için veriyi özetlemektir. Analizden önceki ön adımlar: bilimsel soruyu tanımlamak, ilgilenilen popülasyondan temsilci bir örneklem seçmek ve veriyi gözlemsel çalışmalarla ya da rastgele deneylerle toplamak (ekrandan, 00:15:00).
  - Analiz veri keşfiyle başlar; önce tek bir değişken için keşif teknikleri (veri görselleştirme ve özet istatistikler) kullanılır.
  - Değişkenler iki genel gruba ayrılır: kategorik değişkenler ve sayısal (nicel) değişkenler.
  - Kategorik veri her gruptaki birey sayısıyla, yani frekansla özetlenir. Göreli frekans, bir grubun frekansının toplam gözlem sayısına oranıdır; 100 ile çarpılırsa yüzde olur ve pasta grafiğinin temelini oluşturur.
  - Sayısal veride dağılımın iki önemli yönü vardır: konum (merkezi eğilim, değerlerin toplandığı nokta) ve yayılım.
- Histogramlar
  - Histogram, sayısal değişkenleri görselleştirmek için kullanılan bir frekans dağılımıdır (ekrandan, 00:20:00). Değerler, örtüşmeyen sonlu aralıklara (bin, kutu) gruplanır; bu işleme binning denir.
  - Kutu sayısı için deneysel bir kural olarak Sturges kuralı verildi: $k = 1 + 3.3\log n$ ($k$ kutu sayısı, $n$ örnek sayısı).
  - Histogramı tanımlayan iki ölçü: $i$. kutudaki mutlak frekans $f_i$ ve göreli frekans $f_i/n$ (ekrandan, 00:25:00). Göreli frekans kutu genişliğine bölünürse yoğunluk histogramı elde edilir; bu histogramda her çubuğun alanı o aralığın göreli frekansına eşittir.
  - Histogram biçimleri: simetrik, sağa ya da sola çarpık, tek tepeli (unimodal), iki tepeli (bimodal) ve çok tepeli (multimodal). İki tepeli histogram iki tek tepeli histogramın birleşimi gibi görünür (ekrandan, 00:30:00).
  - Histogram, örneklerin geldiği rastgele sürecin olasılık yoğunluk fonksiyonunun kaba bir kestirimidir.
- Merkezi eğilim ölçüleri
  - Merkezi eğilim, bir olasılık dağılımının merkezi ya da tipik değeridir; dağılımın konumu da denir. Ölçüleri örneklem ortalaması, örneklem medyanı ve örneklem modudur (ekrandan, 00:40:00).
  - Olasılık tanımıyla ortalama (beklenen değer), her değerin olasılığıyla ağırlıklandırılmış toplamıdır: $E[X]=\sum x\,P(x)$. Değerler eşit olasılıklıysa (örneğin 10 değerin her biri 0.1) bu, değerlerin toplamının örnek sayısına bölünmesine iner.
  - Aritmetik ortalama: $\bar{x} = \dfrac{x_1+x_2+\cdots+x_n}{n}$ (ekrandan, 00:45:00). Veri, orta noktanın iki yanında benzer biçimde yayılmışsa kullanılır. Elektrik sinyalinde DC bileşene karşılık gelir.
  - Geometrik ortalama: $\bar{x} = \sqrt[n]{x_1\times x_2\times\cdots\times x_n}$; büyüme oranları gibi çarpımla yorumlanan pozitif sayılar için kullanılır (ekrandan, 00:50:00).
  - Harmonik ortalama: $\bar{x} = \dfrac{n}{\frac{1}{x_1}+\frac{1}{x_2}+\cdots+\frac{1}{x_n}}$; hız gibi bir birime göre tanımlı büyüklükler için kullanılır (ekrandan, 00:50:00).
  - Ağırlıklı aritmetik ortalama: $\bar{x} = \dfrac{\sum_{i=1}^{n} w_i x_i}{\sum_{i=1}^{n} w_i}$; aynı popülasyondan farklı boyutlu örneklemlerin ortalamalarını birleştirmek için kullanılır (ekrandan, 00:55:00). Konuşma işleme ve Doppler sinyal analizinde ortalama frekansı bulmak için kullanılır.
  - Kuvvet ortalaması (power mean) bütün bu ortalamaları kapsar: $M_{-\infty}$ en küçük değer, $M_{-1}$ harmonik, $M_0$ geometrik, $M_1$ aritmetik, $M_2$ karekök ortalama kare (RMS), $M_{\infty}$ en büyük değerdir.
  - Medyan: sıralı verinin orta noktasıdır; $n$ tekse ortadaki değer, çiftse ortadaki iki değerin ortalamasıdır. Ortalamaya göre aykırı değerlerden daha az etkilenir ve simetrik olmayan (çarpık) dağılımlarda kullanılır.
  - Medyan, çeyrekler arası açıklıkla (IQR) birlikte verilebilir. 1. çeyrek noktasının altında verinin 1/4'ü, 3. çeyrek noktasının altında 3/4'ü vardır; IQR örneğin ortadaki yarısını içerir ve kutu-bıyık grafiğinde gösterilir (ekrandan, 01:00:00).
  - Mod üçüncü merkezi eğilim ölçüsüdür. Simetrik veride ortalama, medyan ve mod çakışır; dağılım çarpıklaştıkça birbirlerinden ayrılırlar.
- Değişkenlik (yayılım) ölçüleri
  - Örneklem varyansı, ortalamadan sapmaların karelerine dayanan yayılım ölçüsüdür; karekökü standart sapmadır. <!-- BELİRSİZ: varyans formülünün slaydı karede görülmedi; korelasyon slaydındaki (n-1) paydası örneklem varyansının $s^2=\frac{1}{n-1}\sum (x_i-\bar{x})^2$ biçiminde verildiğini düşündürüyor. -->
  - Standart sapma normal dağılan veride kullanılır. $\pm1$ standart sapma verinin yaklaşık %68.3'ünü, $\pm2$ standart sapma %95.4'ünü, $\pm3$ standart sapma %99.7'sini içerir.
  - Standart sapmanın özellikleri: kare alındığı için negatif olamaz, en küçük değeri sıfırdır, aykırı değerlerden etkilenir, birimi verinin birimiyle aynıdır (varyansınki birimin karesidir).
  - Normal dağılımda (simetrik histogramda) örneklem ortalaması ve standart sapması, olguyu betimlemek için gereken tek parametrelerdir (ekrandan, 01:25:00).
  - Kantiller örneği eşit büyüklükte bitişik alt gruplara böler: çeyrekler (4 parça), yüzdelikler (100 parça), ondalıklar (10 parça). Medyan 2. çeyrektir ($Q_2$); $Q_1$ medyanın altındaki örneklerin, $Q_3$ üstündekilerin medyanıdır. $Q_1$, $Q_2$, $Q_3$ sırasıyla 25., 50. ve 75. yüzdeliklerdir.
  - Beş sayı özeti: en küçük değer, $Q_1$, medyan, $Q_3$, en büyük değer. Bu özetten iki yayılım ölçüsü çıkar (ekrandan, 01:30:00): açıklık (en büyük − en küçük) ve çeyrekler arası açıklık $IQR = Q_3 - Q_1$.
  - Kutu grafiği beş sayı özetini görselleştirir ve aykırı değerleri bulmayı kolaylaştırır. Derste verilen tanım: $Q_3 + 3\,IQR$ üstündeki ya da $Q_1 - 3\,IQR$ altındaki değerler aykırı değerdir; katsayı 1.5 alınırsa bu sınırları aşan değerler şüpheli aykırı değer sayılır.
  - Değişim katsayısı (coefficient of variation): standart sapmanın örneklem ortalamasına bölümüdür ($CV = s/\bar{x}$, ortalama pozitif varsayılır). Ortalamaları ya da ölçü birimleri çok farklı değişkenlerin yayılımını birimden bağımsız karşılaştırmak için kullanılır (ekrandan, 01:35:00).
- Veri dönüşümleri
  - Dönüşümler bazı özellikleri belirginleştirmek, uç değerlerin etkisini azaltmak, dağılımı normale yaklaştırmak ya da daha bilgilendirici grafikler elde etmek için kullanılır.
  - Ölçekleme $y = a x$: ortalama $a\bar{x}$, standart sapma $|a|\,s$, varyans $a^2 s^2$ olur. Kaydırma $y = x + b$: ortalama $\bar{x} + b$ olur, standart sapma ve varyans değişmez.
  - Standartlaştırma: $z = (x - \bar{x})/s$. Ortalama sıfıra kayar, standart sapma bire eşitlenir. Regresyon ve kümelemede yaygındır; veri ölçeğinden bağımsız genel bir analiz sistemi kurmayı sağlar.
- Değişkenler arasındaki ilişkiler
  - İki sayısal değişken: saçılım grafiğinde pozitif doğrusal, negatif doğrusal, ilişkisiz ya da doğrusal olmayan ilişki görülebilir.
  - Pearson korelasyon katsayısı (ekrandan, 01:45:00): $r_{xy} = \dfrac{\sum_{i=1}^{n}(x_i-\bar{x})(y_i-\bar{y})}{(n-1)s_x s_y}$; $s_x$, $s_y$ örneklem standart sapmalarıdır. $r$ her zaman $-1$ ile $+1$ arasındadır; pozitif değer aynı yönlü, negatif değer ters yönlü ilişki gösterir. Derste mutlak değeri 0.5'ten büyük katsayının güçlü ilişkiye işaret ettiği söylendi.
  - Çapraz korelasyon, iki değişken arasındaki bütün kaydırmaları dikkate alır ve tek değer yerine bir ilişki dağılımı verir; $x$ ve $y$ aynıysa otokorelasyon adını alır. Doğrudan algoritması iç içe iki döngüdür ve yavaştır; hızlı Fourier dönüşümüne dayalı hızlı korelasyon da vardır (ders kapsamı dışında bırakıldı).
  - Örneklem kovaryansı: Pearson formülünün paydasından standart sapmalar çıkarılınca elde edilir, yani $\dfrac{\sum (x_i-\bar{x})(y_i-\bar{y})}{n-1}$.
  - İki kategorik değişken: olumsallık (contingency) tablolarıyla incelenir. İlişkinin gücü oranlar farkı $p_2 - p_1$ ile ölçülebilir (ekrandan, 01:50:00). Aspirin-plasebo örneğinde kalp krizi geçirenlerin oranı aspirin grubunda plaseboya göre 0.0077 düşük, göreli olarak yaklaşık %45 azdır.
  - Göreli oran (iki oranın bölümü) 1 ise ilişki yoktur. Daha yaygın olarak odds karşılaştırılır: $o = p/(1-p)$; odds oranı $OR = o_2/o_1$ 1'e eşitse ilişki yoktur, 1'den uzaklaştıkça ilişki güçlenir. Örnekte $OR \approx 0.54$ bulundu.
  - Sayısal ve kategorik değişken: kategorilere göre nokta grafikleri (strip chart; örnekte farklı kültivarlarda C vitamini biçimi askorbik asit içeriği) ya da her kategori için ayrı kutu grafikleri kullanılır.
- Olasılık
  - Her ölçümde belirsizlik vardır; istatistikte belirsizlik olasılıkla ölçülür. Popülasyonun bütün üyelerine erişilemediği ve bulgular örnekleme göre değişebildiği için örneklemden popülasyona genelleme yaparken belirsizlik açıkça belirtilmelidir (ekrandan, 01:55:00).
  - Sonucu önceden kesin bilinemeyen olgu rastgeledir. Bütün olası sonuçlar örnek uzayını oluşturur; olay örnek uzayının bir alt kümesidir. Bir olayın olasılığı içerdiği sonuçların olasılıkları toplamıdır; tümleyenin olasılığı $1 - P(E)$'dir. Olayın odds'u $P(E)/(1-P(E))$'dir.
  - $P(E_1 \cap E_2)$ ortak (joint) olasılık, $P(E_1)$ ve $P(E_2)$ marjinal olasılıklardır. $P(E_1 \cup E_2) = P(E_1) + P(E_2) - P(E_1 \cap E_2)$. Hiç birlikte gerçekleşmeyen olaylar ayrık (mutually exclusive) olaylardır (ekrandan, 02:00:00).
  - Bağımsız olaylarda ortak olasılık marjinal olasılıkların çarpımıdır. Bayes kuralı, $P(E_2 \mid E_1)$ ile $P(E_1 \mid E_2)$ arasındaki ilişkiyi verir.
  - Tekrarlanabilen rastgele olgularda (denemeler) olasılık göreli frekans olarak yorumlanabilir; bunun için olasılığın denemeden denemeye değişmediği varsayılır.
- Dağılımlar
  - Verinin yayılımı düzenli, çarpık, Gauss ya da başka biçimde olabilir. Gauss (normal) dağılımında $\mu$ gerçek (popülasyon) ortalaması, $\sigma$ gerçek standart sapmadır; verinin yaklaşık %68'i $\mu \pm \sigma$ aralığındadır.
  - Poisson olasılık dağılımı radyoaktif bozunma olaylarını, sayaçtan geçen hücreleri ya da gelen ışık fotonlarını betimleyebilir (ekrandan, 02:05:00). Ortalama $m$ iken $k$ olayın gerçekleşme olasılığı $P(k) = \dfrac{m^k e^{-m}}{k!}$, standart sapması $\sqrt{m}$'dir. Kesikli bir dağılımdır; derste $m = 3$ için örnek dağılım gösterildi.
- Parametre kestirimi ve hipotez testi
  - İstatistiğin amacı örneklemdeki bilgiyle popülasyon hakkında çıkarım yapmaktır. Popülasyonu betimleyen sayısal ölçüler (ortalama, medyan, standart sapma, oran) parametrelerdir. Çıkarım iki yolla yapılır: parametreyi kestirmek ya da parametre hakkında hipotez test etmek.
  - Kestirimde yalnız gözlenen veriye bağlı bir fonksiyon olan istatistik (kestirici) kullanılır. Tek değer verilirse nokta kestirimi olur; belirsizliği yansıtmak için olası değerler aralığı verilirse aralık kestirimi olur.
  - Hipotez, iki ya da daha fazla değişken arasındaki ilişki hakkında test edilebilir bir önermedir; hipotez testi bilimsel yöntemin özüdür (ekrandan, 02:10:00).
  - Sıfır hipotezi ($H_0$) mevcut durumu ya da "ilginç bir şey yok" durumunu, alternatif hipotez ($H_A$) araştırmacının iddiasını temsil eder. Birinci tip hata olasılığı $\alpha$, ikinci tip hata olasılığı $\beta$ ile gösterilir; test, reddedilmesi gereken $H_0$'ı $1-\beta$ olasılıkla doğru biçimde reddeder (ekrandan, 02:15:00).
  - $H_0$'a karşı kanıt, test istatistiği ile ölçülür. Bir istatistiğin test istatistiği olabilmesi için $H_0$ altındaki örnekleme dağılımı tam bilinmelidir; bu dağılıma sıfır dağılımı denir.
- Regresyon analizi ve denetimli öğrenme
  - Regresyon, bir yanıt (bağımlı) değişkeni ile bir ya da daha fazla açıklayıcı (bağımsız) değişken arasındaki fonksiyonel ilişkiyi modeller (ekrandan, 02:20:00). Hangi açıklayıcı değişkenlerin yanıtı etkilediğini ve gözlenmemiş değerlerde yanıtın ne olacağını kestirmeyi sağlar (ör. geçmiş satışlardan gelecek satış tahmini).
  - Basit doğrusal regresyon: $y = \alpha + \beta x + \varepsilon$; $\alpha$ kesişim, $\beta$ eğim (regresyon katsayısı), $\varepsilon$ hata terimidir. Parametreleri bulmaya modeli veriye uydurma denir.
  - Doğrusal regresyon modelleri önceki verilerle kurulup yanıt değişkenini tahmin ettiği için denetimli öğrenme sayılır (ekrandan, 02:25:00).
- Denetimsiz öğrenme ve kümeleme
  - Verinin altta yatan yapısını bulmaya yönelik modeller denetimsiz öğrenmedir; en önemli sınıfı kümelemedir. Kümeleme, aynı gruptaki gözlemlerin farklı gruptakilere göre daha benzer olduğu alt gruplar bulur.
  - Uzaklık ölçüsü kümelemenin temel kavramıdır. Benzerlik, nesneler benzedikçe artar ve genelde 0-1 arasındadır; benzemezlik (uzaklık) için üst sınır yoktur. Yakınlık (proximity) ikisini kapsayan şemsiye kavramdır.
  - Öklid uzaklığı, kare farklar toplamının kareköküdür. Minkowski uzaklığında $r = 1$ şehir bloğu (Manhattan, taksi, L1 normu), $r = 2$ Öklid, $r \to \infty$ supremum uzaklığıdır (ekrandan, 02:30:00).
  - K-ortalamalar (k-means): gözlemler rastgele $k$ gruba ayrılıp merkezler bulunur; sonra her gözlem en yakın merkeze (kare Öklid uzaklığı) atanır ve merkezler yeniden hesaplanır. Kümeler değişmeyene kadar tekrarlanır.
  - Hiyerarşik kümeleme k-ortalamaların sorunlarına alternatiftir: bölücü (divisive) ve birleştirici (agglomerative) yaklaşımlar vardır. Filogenetik ağaçlarda görülen UPGMA bu yöntemlerdendir.

## Hocanın Özellikle Vurguladığı Kısımlar

- Hangi merkezi eğilim ölçüsünün seçileceği
  - Hoca, ölçünün başkaları kullandığı için körü körüne seçilmemesini, histogramın biçimine (dağılıma) bakılarak seçilmesini vurguladı.
  - Simetrik dağılımda aritmetik ortalama; çarpık dağılımda medyan, geometrik ya da harmonik ortalama seçilebilir. Aritmetik ortalama veri çarpık değilken, uç aykırı değer yokken ve veriler bağımsızken uygundur. Geometrik ortalama veriler birbiriyle ilişkiliyse, harmonik ortalama çoğu değer düzgün dağılmışken birkaç çok yüksek aykırı değer varsa uygundur.
- Ortalamalar arasındaki eşitsizlik
  - Geometrik ve harmonik ortalama hiçbir zaman aritmetik ortalamadan büyük olmaz. Üçü yalnız bütün değerler eşitse birbirine eşittir.
- Standart sapmanın kullanım koşulu
  - Standart sapma normal dağılan veri için kullanılır. Normal dağılımda ortalama ve standart sapma olguyu betimlemeye yeter.
- Histogramın önemi
  - Histogram, örneklerin geldiği sürecin olasılık yoğunluk fonksiyonunun kaba kestirimidir; bu yüzden derste ona ayrıca zaman ayrıldı.
- İstatistiğin biyoenformatikle bağı
  - Hoca bu kavramları, biyoenformatik algoritmalarında (olasılık, dağılımlar, kümeleme, filogenetik ağaçlar) sürekli kullanıldıkları için hatırlattığını belirtti.

## Kısa Tekrar Notları

- Göreli frekans = grup frekansı / toplam gözlem; ör. 20 öğede 5 ve 15 için 0.25 ve 0.75.
- Sturges kuralı: $k = 1 + 3.3\log n$.
- Yoğunluk histogramı: yükseklik = göreli frekans / kutu genişliği; çubuk alanı = göreli frekans.
- Merkezi eğilim: ortalama, medyan, mod. Yayılım: varyans, standart sapma, IQR, açıklık.
- Kuvvet ortalaması: $M_{-1}$ harmonik, $M_0$ geometrik, $M_1$ aritmetik, $M_2$ RMS, $M_{\pm\infty}$ en büyük/en küçük.
- Harmonik ≤ geometrik ≤ aritmetik; eşitlik yalnız bütün değerler eşitse.
- Medyan aykırı değerlere ortalamadan daha dayanıklıdır.
- Normal dağılım: %68.3, %95.4, %99.7 ($\pm1$, $\pm2$, $\pm3$ standart sapma).
- Beş sayı özeti: en küçük, $Q_1$, medyan, $Q_3$, en büyük. $IQR = Q_3 - Q_1$.
- Aykırı değer (derste): $Q_3 + 3IQR$ üstü ya da $Q_1 - 3IQR$ altı; 1.5 katsayısıyla şüpheli aykırı değer.
- $CV = s/\bar{x}$: birimden bağımsız yayılım; ölçeklemeyle değişmez, kaydırmayla değişir.
- Standartlaştırma $z=(x-\bar{x})/s$: ortalama 0, standart sapma 1.
- Pearson $r \in [-1, +1]$; kovaryans = paydasında standart sapmalar olmayan Pearson formülü.
- Odds $= p/(1-p)$; $OR = 1$ ilişki yok.
- $P(E_1 \cup E_2) = P(E_1) + P(E_2) - P(E_1 \cap E_2)$; bağımsızsa $P(E_1 \cap E_2) = P(E_1)P(E_2)$.
- Poisson: $P(k) = m^k e^{-m}/k!$, standart sapma $\sqrt{m}$.
- $\alpha$: birinci tip hata, $\beta$: ikinci tip hata, $1-\beta$: doğru red olasılığı.
- Doğrusal regresyon $y = \alpha + \beta x + \varepsilon$ → denetimli öğrenme; kümeleme → denetimsiz öğrenme.
- Minkowski: $r=1$ Manhattan, $r=2$ Öklid, $r=\infty$ supremum.

## Detaylı Açıklamalar

- **Neden özetleme?** Toplanan veri ham hâlde büyük resmi göstermez. Önce problem tanımlanır, temsilci örneklem seçilir ve veri toplanır; sonra her değişken türüne uygun görselleştirme ve özet istatistikle keşif yapılır. Kategorik değişkenler frekans ve göreli frekansla sayısala çevrilir. Örneğin 20 öğenin 5'i A grubunda, 15'i B grubundaysa frekanslar 5 ve 15, göreli frekanslar $5/20 = 0.25$ ve $15/20 = 0.75$'tir; toplamları 1'dir ve 100 ile çarpılınca pasta grafiğindeki yüzdeler elde edilir.
- **Histogramdan dağılıma.** Sayısal değişkende değerler kutulara ayrılıp her kutudaki örnek sayılır. Sturges kuralı kutu sayısı için kaba bir başlangıç verir. Göreli frekans kutu genişliğine bölündüğünde her çubuğun alanı göreli frekans olur; bu yoğunluk histogramı, örneklerin geldiği sürecin olasılık yoğunluk fonksiyonunu kabaca kestirir. Derste ortalaması 0, standart sapması 1 olan normal dağılımdan çekilmiş 1000 örneğin histogramı tipik örnek olarak gösterildi. Histogramın biçimi (simetrik, çarpık, tek ya da çok tepeli) hangi betimsel istatistiğin seçileceğini belirler.
- **Ortalamalar ailesi.** Aritmetik ortalama en basit ölçüdür, ama her veri için doğru seçim değildir. Geometrik ortalama çarpımsal büyümeye, harmonik ortalama hız gibi oran büyüklüklerine uygundur. Ağırlıklı ortalama, farklı boyutlu örneklemlerin ortalamalarını birleştirir ya da bazı örneklere daha çok önem verir. Kuvvet ortalaması $M_p$ bütün bu ortalamaları $p$ parametresiyle tek formülde toplar.
- **Medyan ve çeyrekler.** Medyan, sıralı verinin ortasıdır ve uç değerlerden az etkilenir. Medyanın altındaki yarının medyanı $Q_1$, üstündeki yarının medyanı $Q_3$'tür. Beş sayı özeti ve kutu grafiği verinin hem merkezini hem yayılımını hem de aykırı değerlerini tek bakışta gösterir.
- **Varyans, standart sapma ve dönüşümler.** Standart sapma ortalamadan uzaklığa dayandığı için aykırı değerlerden etkilenir ve en çok normal dağılımda anlamlıdır. Ölçekleme ve kaydırma ortalama, standart sapma ve varyansı öngörülebilir biçimde değiştirir; değişim katsayısı ölçeklemeyle değişmez ama kaydırmayla değişir. Standartlaştırma verinin ortalamasını 0, standart sapmasını 1 yapar ve analizi ölçekten bağımsız kılar.
- **İlişkileri ölçmek.** İki sayısal değişkende Pearson katsayısı doğrusal ilişkinin yönünü ve gücünü verir; doğrusal olmayan ilişkiyi yakalamaz. Çapraz korelasyon bütün kaydırmaları tarar. Kategorik değişkenlerde oranlar farkı, göreli oran ve odds oranı kullanılır. Aspirin örneğinde oran farkı −0.0077, göreli azalma yaklaşık %45 ve odds oranı yaklaşık 0.54'tür.
- **Olasılıktan çıkarıma.** Olasılık belirsizliğin ölçüsüdür; belirsizlik yoksa olgu deterministiktir. Toplama kuralı, bağımsızlık ve Bayes kuralı biyoenformatik algoritmalarında sık kullanılır. Normal ve Poisson dağılımları en yaygın modellerdir. Popülasyon parametreleri örneklemden nokta ya da aralık kestirimiyle bulunur; hipotez testinde $H_0$ ile $H_A$ karşılaştırılır ve iki tip hata ($\alpha$, $\beta$) göz önüne alınır.
- **Regresyon ve kümeleme.** Regresyon açıklayıcı değişkenlerle yanıt değişkeni arasında bir model kurar ve gözlenmemiş değerler için tahmin üretir; bu yüzden denetimli öğrenmedir. Kümeleme ise etiket olmadan, uzaklık ölçüsüne dayanarak veriyi benzer gruplara ayırır. K-ortalamalar basit ve yinelemelidir; hiyerarşik kümeleme (ör. UPGMA) filogenetik ağaçlardan tanıdık bir alternatiftir.

> **Ders sonrası not:** Hoca $\pm1$ standart sapmanın verinin "%62.2"sini içerdiğini söyledi (altyazıda böyle geçiyor); doğrusu yaklaşık %68.3'tür. Hoca da dersin ilerisinde "yaklaşık %68" dedi.

> **Ders sonrası not:** Aykırı değer tanımında hoca bir yerde "Q2'nin üstünde" dedi; hemen ardından söylediği gibi doğrusu $Q_3 + 3\,IQR$'dir.

> **Ders sonrası not:** Hoca standartlaştırılmış verinin "0 ile 1 arasına normalize edildiğini" söyledi. $z = (x-\bar{x})/s$ dönüşümü ortalamayı 0, standart sapmayı 1 yapar; değerleri 0-1 aralığına sıkıştırmaz (negatif değerler de olur).

> **Ders sonrası not:** Hoca bir yerde değişim katsayısının ölçekleme ve kaydırmadan etkilenmediğini söyledi, ardından $ax+b$ dönüşümünde değiştiğini belirtti. Doğrusu: pozitif $a$ ile ölçekleme CV'yi değiştirmez, $b$ ile kaydırma değiştirir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
