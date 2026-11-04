# Ders 6 Çalışma Özeti

## Genel Konular

- Sınıflandırma (classification) ve regresyon (regression) farkı.
- Doğrusal regresyon (linear regression): model, ağırlıklar, hata.
- Hata kareleri toplamı (sum of squared errors) ve türevi sıfıra eşitleyerek minimize etme.
- Gradyan inişi (gradient descent), öğrenme oranı (learning rate), yerel ve global minimum.
- Online (stokastik) doğrusal regresyon algoritması ve ağırlık güncelleme kuralı.
- Batch, stokastik (stochastic) ve mini-batch gradyan inişi.
- Lojistik regresyon (logistic regression): sigmoid fonksiyonu, olasılık çıktısı, eşik değeri.
- Skor çıktısının (0-1 arası değer) gerçek uygulamalarda kullanımı üzerine sınıf tartışması.

## Hocanın Özellikle Vurguladığı Kısımlar

- Öğrenme, hatayı minimum yapan uygun ağırlık değerlerini bulmaktır.
- Öğrenme oranının dengesi önemlidir: çok küçükse öğrenme çok uzun sürer, çok büyükse global minimum atlanabilir.
- Pratikte sabit öğrenme oranı yerine başta büyük (ör. ilk 100 iterasyonda 0,8-0,9), sonra küçülen bir oran kullanılabilir (ör. $\alpha = 1/t$).
- Tavsiye edilen yöntem mini-batch gradyan inişidir. Batch'in yavaşlığından ve stokastiğin gereksiz dalgalanmasından kurtarır.
- Aynı ağırlık güncelleme mantığı perceptron ve çok katmanlı perceptron (multi-layer perceptron) konularında da karşımıza çıkacak.
- Lojistik regresyonun skor çıktısı dikkatli kullanılmalıdır. Skora bakıp karar vermek işin içine insan yorumunu sokar ve makine öğrenmesinin sağladığı genellemeyi bozabilir. Sıralama gereken durumlarda (ör. 50 başvurudan 10 kişi seçmek) skor faydalıdır.
- Eşik değeri insan sezgisiyle değil, verilere bakarak (geçmiş sonuçlarla) belirlenmelidir.
- Çalışan öğrencilere: şirketinizdeki büyük veriye bakın, oradan çok güzel tezler çıkar.
- Sohbet penceresinden (chat) yazılan mesajlar tam ekranda görünmüyor. Hoca soruların sesli sorulmasını istedi.
- Duyuru: bir sonraki hafta ödev verilecek ve yapay sinir ağlarına (perceptron) geçilecek. Öğrencilerin isteğiyle perceptron bir sonraki haftaya bırakıldı.

## Kısa Tekrar Notları

- **Sınıflandırma:** çıkış ayrık bir sınıftır (mutlu/kızgın, spam/değil).
- **Regresyon:** çıkış sürekli bir değerdir (film puanı 3,5; ev fiyatı).
- **Model:** $\hat{y} = f(x) = v_0 + v_1 x_1 + \ldots + v_d x_d = v^T x$ ($x_0 = 1$ kabul edilir).
- **Gerçek çıkış:** $y = v^T x + \varepsilon$ ($\varepsilon$: hata).
- **Hata (SSE):** $E(v) = \frac{1}{2}\sum_{i=1}^{N} \left(y_i - v^T x_i\right)^2$.
- **Gradyan inişi güncelleme kuralı:** $v^{(t+1)} = v^{(t)} + \alpha \left(y_i - f(x_i)\right) x_i$.
- $y_i > \hat{y}_i$ ise ağırlık artar. $y_i < \hat{y}_i$ ise ağırlık azalır.
- **Durma koşulu:** hata $\varepsilon$ eşiğinin altına düşünce (yakınsama, convergence) ya da sabit iterasyon sayısına ulaşınca.
- **Batch GD:** tüm örnekler için hata hesaplanır, ortalamayla bir kez güncellenir. Kararlı ama yavaş.
- **Stokastik (online) GD:** her örnekten sonra güncellenir. Hızlı ama dalgalı.
- **Mini-batch GD:** K örneklik gruplar (ör. 100) için ortalama hatayla güncellenir. Önerilen yöntem.
- **Epoch:** tüm eğitim örneklerinin bir kez gösterilmesi.
- **Sigmoid:** $g(z) = \dfrac{1}{1 + e^{-z}}$, $z = v^T x$. Çıkış 0 ile 1 arasındadır.
- **Lojistik regresyon:** $P(y=1 \mid x, v) = g(v^T x)$, $P(y=0 \mid x, v) = 1 - g(v^T x)$.
- **Karar:** $P(y=1 \mid x) > \theta$ ise sınıf 1, değilse sınıf 0. Genelde $\theta = 0{,}5$.
- **Karar sınırı:** $v^T x = 0$ (doğrusal karar sınırı).

## Detaylı Açıklamalar

### Sınıflandırma ve regresyon

- Şimdiye kadarki derslerde hep sınıflandırma yapıldı: yüz ifadesinden duygu, e-postanın spam olup olmadığı.
- Bazı problemlerde çıkış bir sınıf değil, sürekli bir değerdir: bir filmin puanı, bir bölgedeki ev fiyatı.
- Girişler her iki problemde de ayrık (discrete) ya da sürekli (continuous) olabilir. Fark çıkıştadır.

**Örnek 1: Beşiktaş'ta ev fiyatı**

- Giriş (x): yıl. Çıkış (y): ev fiyatı.
- Geçmiş yıllardaki fiyatlar eğitim örnekleridir.
- Amaç: $y = f(x)$ eşlemesini (mapping) öğrenip 2020 için fiyatı tahmin etmek.
- Doğrusal regresyonda bu eşleme bir doğrudur.
- Hoca, paranın değer kaybı yüzünden fiyatın hep artıyor gibi göründüğünü, bunun biraz yapay bir örnek olduğunu belirtti.

### Doğrusal regresyon modeli

- $x$: bağımsız değişkenler (independent variables). $y$: bağımlı değişken (dependent variable).
- Eğitim kümesi: $N$ tane $(x_i, y_i)$ çifti.
- $\hat{y}_i$: modelin hesapladığı çıkış. $y_i$: istenen (gerçek) çıkış.
- Hata: $y_i - \hat{y}_i$. İşaretin önemi olmadığı için kare (ya da mutlak değer) alınır.

**Tek özellik**

- $y = v_1 x + \varepsilon$. Tek özellik varsa tek ağırlık vardır.
- Bir de sabit terim $v_0$ eklenir: $y = v_0 + v_1 x + \varepsilon$.
- Tek özellik için kapalı çözüm (derste sözlü verildiği haliyle):

$$v_0 = \frac{1}{N}\sum_{i=1}^{N} \left(y_i - v_1 x_i\right), \qquad v_1 = \frac{\sum_{i=1}^{N} x_i \left(y_i - v_0\right)}{\sum_{i=1}^{N} x_i^2}$$

- Bu iki denklem, hatanın $v_0$ ve $v_1$'e göre türevini sıfıra eşitlemekten gelir. Birbirine bağlı oldukları için birlikte çözülür.

**Çok özellik**

- Örnek: film puanı için yıl, tür, oyuncular gibi $K$ tane özellik.

$$y = v_0 + v_1 x_1 + v_2 x_2 + \ldots + v_K x_K + \varepsilon$$

- Kodlama kolaylığı için $x_0 = 1$ kabul edilir. Böylece $f(x) = \sum_{j=0}^{d} v_j x_j = v^T x$ olur.

**Hata fonksiyonu**

$$E(v) = \sum_{i=1}^{N} \left(y_i - f(x_i)\right)^2 = \sum_{i=1}^{N} \left(y_i - v^T x_i\right)^2$$

- Hatanın ağırlıklara göre türevi sıfıra eşitlenirse minimum bulunur.

### Gradyan inişi

- Ağırlıklar iteratif olarak, hatayı azaltacak yönde değiştirilir. Gradyan, bu yönü gösterir.
- Hoca ağırlık-hata grafiği çizdi: hata başta yüksek, adım adım düşüyor, global minimumda en düşük değere ulaşıyor.
- **Yerel minimum (local minimum):** hatanın yakın çevresinde en düşük olduğu ama global minimum olmayan noktalar. Bunlara takılıp kalınmamalıdır.
- **Adım büyüklüğü:**
  - Küçük adımlar (ör. 3 → 3,05 → 3,1): doğru sonuca ulaşır ama çok iterasyon gerekir.
  - Büyük adımlar: hızlıdır ama global minimum atlanabilir.

### Öğrenme oranı

- $\alpha$: öğrenme oranı. Ağırlıkların ne hızla değişeceğini belirler.
- 1'e yaklaştıkça hızlı, 0'a yaklaştıkça yavaş öğrenir.
- **Değişken öğrenme oranı:**
  - Başta global minimumdan uzak olunduğu bilinir. İlk iterasyonlarda büyük $\alpha$ (ör. 0,8-0,9) kullanılır.
  - Sonra $\alpha$ küçültülür. Ör. $\alpha = 1/t$ ($t$: iterasyon sayısı). Böylece minimum kaçırılmaz.
- Sabit bir değer de seçilebilir (0 ile 1 arasında).

### Online doğrusal regresyon algoritması

1. Ağırlıkları $[0, 1]$ aralığında küçük rastgele değerlerle başlat. $d$ özellik varsa $d+1$ ağırlık vardır ($v_0$ dahil).
2. Tekrarla:
   1. Bir eğitim örneği $(x_i, y_i)$ seç.
   2. Çıkışı hesapla: $f(x_i) = v^T x_i$.
   3. Ağırlıkları güncelle:

$$v^{(t+1)} = v^{(t)} + \alpha \left(y_i - f(x_i)\right) x_i$$

3. Hata $\varepsilon$'un altına düşene (yakınsama) ya da belirlenen iterasyon sayısına ulaşana kadar devam et.

- Bir öğrenci formülde eksik bir parantezi fark etti. Hoca düzeltti.
- **Yorumu:**
  - $y_i - \hat{y}_i > 0$ ise (model az tahmin etmiş) ağırlık artar.
  - $y_i - \hat{y}_i < 0$ ise (model fazla tahmin etmiş) ağırlık azalır.

**Güncelleme kuralı nereden geliyor? (öğrenci sorusu)**

- Soru: "Türevi alıp sıfıra eşitlemiştik, bu kodda nerede kullandık?"
- Cevap: hata şöyle yazılır:

$$E_i = \frac{1}{2}\left(y_i - v^T x_i\right)^2$$

- Ağırlıklara göre türevi:

$$\frac{\partial E_i}{\partial v} = -\left(y_i - v^T x_i\right) x_i$$

- Ağırlık, gradyanın tersi yönünde $\alpha$ kadar hareket ettirilir. Güncelleme kuralındaki $x_i$ çarpanı bu türevden gelir.
- $\frac{1}{2}$ çarpanı, türevde gelen 2'yi sadeleştirmek içindir.

### Batch, stokastik ve mini-batch gradyan inişi

**Batch gradient descent**

- Tüm eğitim örnekleri için hata tek tek hesaplanır. Bir epoch bitince ortalama hatayla ağırlıklar bir kez güncellenir.
- Epoch'lar ilerledikçe ortalama hata düzgün bir şekilde azalır.
- Dezavantaj (bir öğrencinin cevabı: "çok fazla zaman gerekiyor"):
  - Örnek sayısı çok büyükse (ör. 10 bin, 1 milyon) tek bir güncelleme için tüm örneklerin gösterilmesi gerekir.
  - Ortalama alındığı için ağırlıklar küçük adımlarla değişir.
- Örnek sayısı milyonlarca değilse kullanılır.
- Derin öğrenmede yapay sinir ağları da gradyan inişi kullanır. Milyonlarca örnekte batch yöntemi büyük sorun olur.

**Stokastik gradient descent**

- Her örnek gösterildikten sonra ağırlıklar güncellenir.
- Bir örnekte ağırlık artar, sonrakinde azalır. Hata dalgalanarak ilerler.
- Genel durumu görmeden güncelleme yapıldığı için global minimuma çok yaklaşıp tam ulaşamayabilir.
- Online doğrusal regresyon, stokastik gradyan inişidir (bir öğrencinin sorusu üzerine hoca bunu netleştirdi).

**Mini-batch gradient descent**

- K örneklik gruplar seçilir (ör. K = 100).
- Her grup için hatalar hesaplanır, ortalama hatayla ağırlıklar güncellenir. Sonra bir sonraki gruba geçilir.
- Tüm gruplar bitince başa dönülür. Yakınsama olmadıysa devam edilir.
- Hem stokastiğin gereksiz dalgalanmasından hem de batch'in yavaşlığından kurtarır. Biraz dalgalanma yine olur ama daha verimlidir.

**Örnek 2: Mini-batch grupları (öğrenci sorusu)**

- 1.000 örnek var, gruplar 100'lük olsun.
- 1-100 arası örneklerle ortalama hata hesaplanır, ağırlıklar güncellenir.
- Sonra 101-200, 201-300, ... diye devam edilir.
- Hep aynı grup kullanılmaz. Tüm gruplar bitince bir epoch tamamlanır ve başa dönülür.

### Lojistik regresyon

- Doğrusal regresyon sürekli bir değer verir (ör. "2020'de Beşiktaş'ta ev 3 milyon TL"). Lojistik regresyon ise bir sınıflandırıcıdır.
- Çıkışı 0 ile 1 arasında bir değerdir (ör. 0,8; 0,3). Bu yüzden skor görmek isteyenler tarafından çok tercih edilir.
- Çok basittir ve en çok kullanılan modellerden biridir.
- Naive Bayes, k-NN ve karar ağacı kesin sınıf kararı verir. Lojistik regresyon ise 0-1 arası bir değer üretir.
- Doğrusal karar sınırı kullanır: $v^T x = 0$ sınırdır. $v^T x > 0$ bir tarafta, $v^T x < 0$ diğer tarafta kalır.

**Sigmoid (lojistik) fonksiyon**

- Girişler ağırlıklarla çarpılıp toplanır: $z = \sum_{i=0}^{d} v_i x_i = v^T x$.
- $z$ sigmoid fonksiyonundan geçirilir:

$$g(z) = \frac{1}{1 + e^{-z}}$$

- Adı S harfine benzemesinden gelir.
- Basamak fonksiyonu gibi 0'dan 1'e birden geçmez. Yumuşak (smooth) bir geçiş sağlar.

**Olasılık yorumu**

$$P(y = 1 \mid x, v) = g(v^T x) = \frac{1}{1 + e^{-v^T x}}$$

$$P(y = 0 \mid x, v) = 1 - P(y = 1 \mid x, v)$$

- Örnek: "bu kişiyi 0,8 olasılıkla işe almak iyi olur."

**Karar kuralı**

- Bir eşik $\theta$ seçilir:
  - $P(y=1 \mid x) > \theta$ ise sınıf 1.
  - Değilse sınıf 0.
- Böylece ikili (binary) çıkış elde edilir. İstenirse skor olarak bırakılır ve kararı kullanıcı verir.
- Mantıken $\theta = 0{,}5$ seçilebilir.

**Öğrenme algoritması**

- Doğrusal regresyonla aynı mantıktadır:
  1. Ağırlıkları küçük rastgele değerlerle başlat.
  2. Her örnek için çıkışı hesapla: $f(x_i) = \dfrac{1}{1 + e^{-v^T x_i}}$.
  3. Ağırlıkları güncelle: $v^{(t+1)} = v^{(t)} + \alpha \left(y_i - f(x_i)\right) x_i$.
- Derste online (stokastik) sürüm yazıldı. Batch ya da mini-batch sürüm de kullanılabilir.

### Skor mu, kesin karar mı? (sınıf tartışması)

- Hoca TÜBİTAK projelerinde hakemlik yaptığı en az 4-5 projede lojistik regresyonun işe alımda kullanıldığını anlattı:
  - Önceki işe alımlardaki kişilerin profilleri (okul, not ortalaması, iş tecrübesi vb.) giriş olarak kullanılıyor.
  - Etiketi işe alan kurum veriyor: "bu profili aldık, memnun kaldık" ya da "bir yıl sonra ayrıldı, memnun kalmadık".
  - Yeni başvuran için bir uygunluk skoru üretiliyor.
- Bankalar da kredi kartı sahtekârlığı (fraud) tespitinde skor istiyor. Ör. "bu işlemin fraud skoru 0,4" ya da "0,9".
- Öğrencilerin görüşleri:
  - Skor daha iyi: sıralama yapılabilir, en yüksek skorlular seçilir.
  - Skor eşik değerini kişi kendi belirleyebilir (ör. 10 üzerinden 7).
  - İşe almada sıralama önemli olduğu için skor faydalı. Ama fraud kesin bir durumdur ("biri daha az fraud, biri daha çok fraud" denemez). Bu yüzden fraud için kesin karar daha mantıklı.
- Hocanın görüşü:
  - 50 başvurudan 10 kişi seçilecekse skorun sıralama faydası vardır.
  - Tek bir kişiyi alma ya da fraud kararı gibi ikili bir kararda skor işin içine insan yorumunu sokar. Biri 0,7'ye "almam" der, başka biri "0,5'i geçti, alalım" der. Bu tehlikelidir.
  - Daha iyi yol, eşiği verilerle belirlemektir. Ör. 0,6 ve 0,7 skorla alınanlardan memnun kalınmamış, 0,8'i geçenlerden hep memnun kalınmışsa eşik 0,8 olmalıdır.
  - Etiketleme de insan kararı içerir. Ör. duygu analizinde (sentiment analysis) bir yorumu biri olumlu, başkası nötr etiketleyebilir.
- Bir öğrenci kişinin kendine puan vermesinin beklentiyi bozup bozmayacağını sordu. Hoca, skoru kişinin kendisinin değil modelin verdiğini, etiketi de işe alanın verdiğini açıkladı.

### Ders sonrası notlar

- **$v_0$'ın (bias) rolü:** hoca $v_0$'ın "doğrunun orijine oturmasını sağladığını" söyledi. Doğrusu tam tersidir. $v_0$ (sabit terim, intercept) doğrunun orijinden geçmek zorunda kalmamasını sağlar. $v_0$ olmadan $y = v_1 x$ doğrusu her zaman orijinden geçer.
- **Doğrusal regresyonda yerel minimum:** kare hata fonksiyonu doğrusal regresyonda dışbükeydir (convex). Bu yüzden tek bir global minimum vardır, yerel minimum sorunu yoktur. Hocanın çizdiği yerel minimumlu eğri, ileride görülecek yapay sinir ağları gibi doğrusal olmayan modeller için geçerlidir.
- **Ayrık ve sürekli veri:** hoca boy, kilo, yaş gibi özellikleri "ayrık (discrete)" diye örnekledi. Bunlar aslında sürekli (continuous) sayısal değişkenlerdir. Ayrık değişkene örnek: tür, şehir, öğrenci sayısı.
- **Bağımsız değişken:** regresyondaki "bağımsız değişken" ifadesi, girişlerin birbirinden istatistiksel olarak bağımsız olduğu anlamına gelmez. Çıkışı açıklayan (açıklayıcı) değişkenler demektir.
- **Öğrenme oranı aralığı:** $\alpha$ 1'den büyük de seçilebilir. Ama genelde küçük değerler (0,001-0,1 gibi) kullanılır. Uygun değer probleme ve verinin ölçeğine bağlıdır.
- **Lojistik regresyonun hata fonksiyonu:** lojistik regresyonda genelde kare hata yerine çapraz entropi (log-loss) kullanılır: $E = -\sum_i \left[ y_i \log f(x_i) + (1 - y_i)\log(1 - f(x_i)) \right]$. Bu hatanın gradyanı da derste yazılan $\left(y_i - f(x_i)\right) x_i$ biçimindeki güncelleme kuralını verir.
- **Altyazıdaki bozulmalar:** "Fırat/fraat" kelimeleri "fraud" (sahtekârlık) anlamındadır. "İPOK" epoch demektir. 01:03-01:04 arası altyazı kopuk, mini-batch algoritmasının slayttaki adımları okunamıyor.
- **TÜBİTAK:** hocanın hakemlik yaptığı programlar altyazıda "TÜBİTAK-TEDEF" diye geçiyor. Büyük olasılıkla TÜBİTAK TEYDEB (sanayi Ar-Ge projeleri) kastediliyor.
- Ders 10:00 civarında başladı. 10:40'ta 15 dakika ara verildi. Ders 11:35 civarında bitti.

NotebookLM gibi bir araca altyazı dosyasını yükleyerek bu ders hakkında daha ayrıntılı soru-cevap yapabilirsiniz.
