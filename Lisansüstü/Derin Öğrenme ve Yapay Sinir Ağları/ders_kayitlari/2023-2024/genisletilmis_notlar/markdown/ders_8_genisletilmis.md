# Ders 8 Genişletilmiş Notu: Dönem Sonu Proje Sunumları: Dengesiz Veri, Segmentasyon, Hiperparametre Optimizasyonu ve Üretici Modeller

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dersin Biçimi
- 2. Dengesiz Veride Sınıflandırma: Kredi Kartı Dolandırıcılık Tespiti
- 3. Optimizasyon Ayrıntıları: Momentum, Beta ve Weight Decay
- 4. Elektron Mikroskobu Görüntülerinde U-Net ile Segmentasyon
- 5. Segmentasyonda Başarı Nasıl Ölçülmeli?
- 6. Mobil Telefon Fiyat Aralığı Sınıflandırması
- 7. Uydu Görüntülerinde Semantik Segmentasyon
- 8. Otomatik Kodlayıcı ile Film Öneri Sistemi
- 9. Bitcoin Fiyat Tahmininde Grid Search ve Bayes Optimizasyonu
- 10. CNN ve LSTM ile Kuş Sesi Sınıflandırma
- 11. Koşullu GAN ile Tablo Verisinde Sentetik Veri Üretimi
- 12. Örnek Sorular

## 1. Dersin Biçimi

Bu kayıt, dönemin son haftasında yapılan öğrenci proje sunumlarından oluşur. Oturum çevrim içi yapıldı; öğrenciler ekranlarını paylaşarak sunum yaptı. Her sunumun ardından hoca, yöntemdeki ya da değerlendirmedeki sorunları tartıştı ve konuyla ilgili genel bilgiler verdi. Bu notta her sunumun teknik içeriği ve hocanın akademik yorumları sırasıyla verilir. Sunum yapan öğrenciler "bir öğrenci" diye anılır.

Hoca dönem sonunda, sunumlarda vurguladığı noktaların da dersin kapsamına girdiğini söyledi. Bu yüzden bu ders, dönem boyunca anlatılan optimizasyon, kayıp fonksiyonu, CNN, otomatik kodlayıcı ve üretici modeller konularının uygulamadaki karşılığını görmek için yararlıdır.

## 2. Dengesiz Veride Sınıflandırma: Kredi Kartı Dolandırıcılık Tespiti

### 2.1 Problem ve veri

İlk sunum, kredi kartı işlemlerinde dolandırıcılık tespiti (fraud detection) üzerineydi. Kredi kartı kullanımı yaygınlaştıkça dolandırıcılar sistemdeki zafiyetleri kullanır; bankacılıkta bu işlemleri engelleme girişimine dolandırıcılık tespiti denir.

Kaggle'daki bir veri seti kullanıldı. Yaklaşık 283 bin işlem satırı vardı ve bunların yalnız 473'ü dolandırıcılık olarak işaretliydi. Yani veri son derece dengesizdi.

### 2.2 Veri hazırlığı

Veri hazırlığı şu adımlardan geçti (ekrandan, 00:05:00):

- Özelliklerin ve örneklerin önem düzeyi ve birbirleriyle ilişkisi incelendi.
- Özelliklerin korelasyonlarına ve bilgi kazancı (information gain) değerlerine bakıldı. Değerler birbirine yakın çıktığı için özellik çıkarılmadı.
- Tekil, boş ve aykırı (outlier) örnekler kontrol edildi. Veri kullanıma hazırdı.
- Özelliklerin değer aralıkları farklı olduğundan sonuca etkilerini dengelemek için normalizasyon yapıldı.
- Veri eğitim, doğrulama ve test olarak üçe ayrıldı. Dengesizlik nedeniyle tabakalı örnekleme (stratified sampling) kullanıldı: önce %60 eğitim+doğrulama ve %40 test, sonra eğitim+doğrulama kendi içinde yeniden bölündü. Kütüphanede `stratify` parametresine çıktı sütunu verilerek her parçadaki sınıf oranının orijinaldekiyle aynı kalması sağlandı.

Hoca araya girerek tabakalı örneklemeyi netleştirdi. Öğrenci, her sınıfın kendi içinden rastgele seçim yapıldığını teyit etti. Hoca bunun bir tür rastgele örnekleme olduğunu, aynı zamanda "stratified" teriminin de kullanıldığını söyledi. Ardından testin %40 olmasını somutlaştırdı: 300 bin normal ve 400 dolandırıcılık örneği varsayılırsa testte $300000 \times 0{,}4 = 120000$ normal ve $400 \times 0{,}4 = 160$ dolandırıcılık örneği kalır.

### 2.3 Model ve parametre seçimi

Tam bağlantılı çok katmanlı algılayıcı (MLP) kuruldu. Çıkış katmanında olasılık üretmek için sigmoid kullanıldı. Öğrenci parametreleri iki gruba ayırdı:

- **Yapı parametreleri:** girdi boyutu (veri setindeki özellik sayısı, 30), gizli katman sayısı, her gizli katmandaki nöron sayısı, çıkış boyutu (1), aktivasyon fonksiyonları.
- **Eğitim hiperparametreleri:** ağırlık ve bias ilklendirme, öğrenme oranı, momentum, weight decay.

Gizli katman sayısı için 1-5 arasındaki bütün değerler, nöron sayıları için 1-10 arasındaki bütün değerler denendi; en düşük kaybı veren seçildi. Sonuçta 3 gizli katman seçildi. Aktivasyonlar sırasıyla ReLU, ReLU ve tanh oldu.

Eğitim hiperparametreleri tek tek seçildi (ekrandan, 00:15:00):

- İlklendirme için standart, Kaiming ve He yöntemleri denendi; en düşük kaybı He ilklendirmesi verdi.
- Öğrenme oranı için $[0{,}01;\ 0{,}001]$ aralığında azalan değerlerden oluşan bir havuz kullanıldı.
- Momentum, SGD ve RMSProp için aynı biçimde denendi. Adam için denenmedi (bkz. 3.1).
- Weight decay için $[0{,}001;\ 0{,}01]$ aralığında artan değerler denendi.

SGD, Adam ve RMSProp karşılaştırıldı; en düşük kaybı RMSProp verdi. Kayıp grafikleri hâlâ düşmeye devam ediyordu, yani daha uzun eğitimle iyileşme sürebilirdi.

### 2.4 Sonuç ve hocanın değerlendirmesi

Test kümesindeki karışıklık matrisi şöyleydi (ekrandan, 00:20:00):

| | Tahmin: Hayır | Tahmin: Evet |
|---|---|---|
| **Gerçek: Hayır** | 56.651 | 0 |
| **Gerçek: Evet** | 45 | 50 |

Hoca önce doğruluğu hesaplattı:

$$\text{Doğruluk} = \frac{56651 + 50}{56651 + 0 + 45 + 50} = \frac{56701}{56746} \approx 0{,}9992$$

Literatürde bu veri setinde çok yüksek doğruluklar bildiren çalışmalar olduğunu, ama bu yüksekliğin "hayır" sınıfından geldiğini söyledi. Dolandırıcılık sınıfı için duyarlılık:

$$\text{Recall}_{\text{evet}} = \frac{50}{50 + 45} = \frac{50}{95} \approx 0{,}526$$

Yani model normal işlemlerin %100'ünü, dolandırıcılıkların ancak yaklaşık yarısını buluyor.

> **Hocanın vurgusu:** Bu tür dengesiz veri çalışmalarında doğruluk (accuracy) çok önemli değildir. Önemli olan sınıf bazlı duyarlılıktır (recall). Azınlık sınıfındaki başarı, yöntemin gerçek başarısını gösterir.

Hoca aynı sorunun yalnız kredi kartında değil, telekom şirketlerinin müşteri kaybı (churn) tahmininde de görüldüğünü belirtti. Dengesizlik, farklı kayıp fonksiyonlarının kullanılmasına yol açar:

- Muhtemelen kullanılan çapraz entropi kaybında 56 bin normal örnek kaybı domine eder; model azınlık sınıfından yeterince öğrenemez.
- Kaybın ağırlıklı olması gerekir: normal örnek kayba 1 kat katkı veriyorsa, dolandırıcılık örneği belki 100 kat katkı vermelidir. Böylece parametreler epoklar boyunca azınlık sınıfına göre de güncellenir.
- Dengesiz veride en çok kullanılan kayıplardan biri **focal loss**'tur.

Hoca, tez yapacaklar için güncel bir araştırma yönünü de işaret etti: dengesiz veride veriyi sentetik olarak dengelemeye çalışmak yerine kayıp fonksiyonunu ağırlıklandırmak. Çünkü iki sınıf arasındaki fark çok büyük olduğunda ne kadar sentetik veri üretilebileceği sınırlıdır. Bu yüzden dengesiz veriyle çalışmak hâlâ zordur.

> **Ek bilgi (derste anlatılmadı):** Focal loss, ikili çapraz entropiye $(1-p_t)^\gamma$ çarpanı ekler: $FL(p_t) = -\alpha_t (1-p_t)^\gamma \log p_t$. Model bir örneği zaten yüksek olasılıkla doğru tahmin ediyorsa ($p_t$ büyük) bu çarpan küçülür ve örneğin kayba katkısı azalır; zor ve azınlık örnekleri öne çıkar. $\alpha_t$ sınıf ağırlığıdır.

## 3. Optimizasyon Ayrıntıları: Momentum, Beta ve Weight Decay

### 3.1 Adam neden momentum parametresi almaz?

Sunumdaki öğrenci, SGD ve RMSProp oluşturulurken momentum parametresi verilebildiğini, Adam'da ise verilemediğini fark etmişti. Araştırınca Adam'a özgü `betas` parametresinin momentumun yerine kullanıldığını görmüştü (ekrandan, 00:15:00).

Hoca bunu doğruladı. Derste anlatılan Adam formülünde, SGD'deki momentumun etkisi beta parametresiyle karşılanır. Beta doğrudan momentum değildir ama momentumun etkisini taşır. Bu yüzden:

- SGD ve RMSProp'a momentum verilebilir (RMSProp'ta başka parametreler de vardır).
- Adam'a momentum değil beta verilir. Nadam, RAdam ve AdamW de beta ile çalışır.
- SGD'de momentumu 0,9 ve öğrenme oranını 0,01 vermek ile Adam'da betayı 0,9 ve öğrenme oranını 0,01 vermek matematiksel olarak aynı etkiyi doğurmaz.

> **Ek bilgi (derste anlatılmadı):** Adam'da iki beta vardır. $\beta_1$ (genelde 0,9) gradyanın üstel hareketli ortalamasını, yani momentuma benzeyen birinci momenti; $\beta_2$ (genelde 0,999) gradyan karesinin hareketli ortalamasını, yani RMSProp'taki ikinci momenti kontrol eder. Güncelleme, birinci momentin ikinci momentin kareköküne bölünmesiyle yapılır.

### 3.2 Weight decay

Hoca, sunumda weight decay kullanıldığını görünce diğer öğrencilere derste anlatılan öğrenme oranı zamanlamasını (learning rate scheduling) hatırlattı. Anlatımına göre öğrenme oranı sabit tutulmaz; belirlenen adım sayısı (epok) geçtikçe öğrenme oranı weight decay ile çarpılarak düşürülür ($LR \leftarrow LR \times \text{decay}$).

> **Ders sonrası not:** Hoca weight decay'i öğrenme oranını düşüren bir zamanlama olarak anlattı. Doğrusu: weight decay, her güncellemede ağırlıkları sıfıra doğru biraz küçülten bir düzenlileştirme yöntemidir (L2 cezasına benzer; PyTorch'taki `weight_decay` parametresi budur). Öğrenme oranını belirli adımlarda bir katsayıyla çarparak düşürmek ise "learning rate decay" ya da "step decay" adlı ayrı bir yöntemdir. Sunumdaki slaytta da weight decay "bias ve weight değerlerini optimize ederken kullanılan parametre" diye tanımlanmıştı.

## 4. Elektron Mikroskobu Görüntülerinde U-Net ile Segmentasyon

### 4.1 Uygulama alanı ve veri

İkinci sunum, U-Net mimarisiyle taramalı elektron mikroskobu (SEM) görüntülerinin semantik segmentasyonu üzerineydi. Uygulama bağlamı metal eklemeli imalattı (toz yatak füzyon yöntemi). Bu yöntemde üretim tablasına katman katman toz serilir ve lazerle parçanın kesiti eritilerek parça üretilir (ekrandan, 00:25:00). Uygun parametreler seçilmezse yetersiz ergime, gözeneklilik (porozite), deformasyon, çatlak, sıçrama ve topaklanma gibi hatalar oluşur. Bu hataların tespitinde taramalı elektron mikroskobu, mikroskobik inceleme ve mikrotomografi kullanılır.

Kaggle'daki bir elektron mikroskobu parçacık segmentasyonu veri seti kullanıldı: 465 SEM görüntüsü ve 465 etiket haritası. Haritalar örnek bazlıydı: her parçacık farklı bir değerle (ör. 0,34, 0,44) etiketlenmişti.

### 4.2 Instance ve semantik segmentasyon

Hoca burada araya girip segmentasyonun iki alt türünü hatırlattı (CNN haftasının sonunda kısaca değinilmişti):

- **Instance (örnek bazlı) segmentasyon:** Her nesne ayrı bir sınıf gibi etiketlenir. Görüntüdeki üç üçgenin her biri ayrı bir etikettir. Kalabalık bir fotoğrafta belirli kişileri tek tek bulmak instance segmentasyondur.
- **Semantik segmentasyon:** Aynı türdeki bütün pikseller tek etiket alır. Aynı fotoğrafta "insanları" bulmak semantik segmentasyondur.

Öğrenci instance etiketlerini eşikleyerek ikili semantik maskeye çevirmişti. Hoca bunun sorun olmadığını, hatta veri toplarken akılda tutulması gereken bir ilke olduğunu söyledi: Instance olarak etiketlenmiş veri, basit bir betikle semantik segmentasyona çevrilebilir. Ama yalnız semantik olarak etiketlenmiş veriyi instance problemi için kullanmak isterseniz verinin yeniden etiketlenmesi gerekir.

### 4.3 Ön işleme ve veri artırma

Görüntüler 512x512 boyutuna getirildi, etiketler eşiklenerek segmentasyon maskesine çevrildi, veri eğitim, doğrulama ve test olarak ayrıldı. Veri az geldiği için yalnız eğitim kümesine veri artırma uygulandı:

- X eksenine ve Y eksenine göre aynalama,
- Farklı sigma değerleriyle Gauss filtresi (farklı bulanıklıklar),
- Farklı disk boyutlarıyla medyan filtresi.

Filtreli görüntülerde çıktı maskesi değişmedi; aynı maske kullanıldı. Böylece 3260 eğitim örneği elde edildi. Test ve doğrulama verisine dokunulmadı.

### 4.4 Model

U-Net seçilme nedeni, az örnekle bile yüksek doğruluk vermesi ve biyomedikal görüntülerde hassas segmentasyonda başarılı olmasıydı. Son mimari (ekrandan, 00:35:00):

```text
Girdi 512x512
  Aşağı örnekleme: 512 -> 256 -> 128 -> 64 -> 32 (darboğaz, 32x32)
  Yukarı örnekleme: 32 -> 64 -> 128 -> 256 -> 512
  Her seviyede kodlayıcıdan kod çözücüye atlamalı bağlantı
Çıktı 512x512 ikili maske
```

- Aşağı örnekleme bloğu: konvolüsyon, normalizasyon, max pooling, dropout.
- Yukarı örnekleme bloğu: ters konvolüsyon (transposed convolution) içerir.
- Bütün ara katmanlarda ReLU, çıkışta sigmoid.
- Filtre sayıları 32'den başlayıp 64, 128, 256, 512 diye artırıldı. Örnek alınan notebook'ta max pooling yerine adım (stride) kullanılmıştı; öğrenci her bloğa max pooling ekledi.
- Toplam 2.164.305 parametre, 2.161.161'i eğitilebilir.

Hoca burada Kaggle notebook'larını temel almanın sorun olmadığını, ama katkının mimarinin içindeki yapılarda olması gerektiğini söyledi; yalnızca parametre değiştirmek yeterli katkı değildir.

Hiperparametreler (ekrandan, 00:40:00):

- Optimizasyon: Adam (Adagrad da denendi), 10 epok, yığın boyutu 12.
- Öğrenme oranı: U-Net'te 0,015'ten başlayıp kayıp 2 epok iyileşmezse 0,5 ile çarpıldı. İnce ayarlı modelde 0,01'den başlayıp 3 epokta 0,33 ile çarpıldı.
- Kayıp fonksiyonu: Dice kaybı. Dice katsayısı tahmin ile gerçek maske arasındaki benzerliği ölçer; kayıp $1 - \text{Dice}$ olarak hesaplanır.

İlk 10 epoktan sonra kayıp hâlâ düştüğü için model 10 epok daha eğitildi (ince ayar). Doğruluk yaklaşık %91'e çıktı.

> **Ek bilgi (derste anlatılmadı):** İki küme $A$ (tahmin) ve $B$ (gerçek) için $\text{Dice} = \dfrac{2|A \cap B|}{|A| + |B|}$, $\text{IoU} = \dfrac{|A \cap B|}{|A \cup B|}$ olarak tanımlanır. İkisi birbirine bağlıdır: $\text{Dice} = \dfrac{2\,\text{IoU}}{1+\text{IoU}}$.

## 5. Segmentasyonda Başarı Nasıl Ölçülmeli?

### 5.1 Piksel bazlı doğruluğun yanıltıcılığı

Öğrenci, test maskelerini düzleştirip (flatten) piksel piksel karşılaştırarak bir sınıflandırma raporu çıkarmıştı (ekrandan, 00:45:00):

| Sınıf | Precision | Recall | F1 | Destek (piksel) |
|---|---|---|---|---|
| False (arka plan) | 0,89 | 0,85 | 0,87 | 16.879.601 |
| True (ön plan) | 0,70 | 0,77 | 0,73 | 7.499.791 |
| Doğruluk | | | 0,83 | 24.379.392 |

Doğruluk 0,8267, IoU (Jaccard indeksi) 0,6752 idi.

Hoca önce destek sütununda 24 milyonu görünce bunun görüntü sayısı değil piksel sayısı olduğunu anladı. Sonra şunu açıkladı: maskelerde siyah (arka plan) piksel çok fazla olduğu için doğruluk yüksek çıkar. Asıl bakılması gereken ölçü IoU ya da Dice skorudur. Bu modelde IoU 0,67, yani bulunan maskeler gerçek maskelerle ortalama %67 örtüşüyor; bu çok iyi bir değer değildir.

İnce ayardan sonra doğruluk %82'den %91'e çıkarken IoU 0,67'den 0,81'e çıktı. Hoca, doğruluktaki artışın IoU'daki artışı tam yansıtmadığını vurguladı; çünkü doğruluk piksel sayılarına, özellikle kalabalık arka plan sınıfına dayanıyor.

### 5.2 Nesne düzeyinde doğru pozitif

Hoca, segmentasyonda karışıklık matrisinin piksel bazlı değil nesne (bölge) bazlı kurulması gerektiğini anlattı:

- Gerçek maskedeki bir ön plan bölgesi ile modelin bulduğu bölgenin örtüşme oranı (IoU) belirli bir eşiğin üstündeyse o tahmin **doğru pozitif** sayılır.
- Eşik %50 ise ölçüye **mAP50** denir. Hassas veri setlerinde eşik %95 alınır; amaç bulguyu keskin hatlarıyla gerçek maskeyle kıyaslamaktır.
- Örnek: gerçekte bir daire var, model ortasında daha küçük bir daire çizmiş ve örtüşme %50'nin altında. Bu tahmin doğru pozitif sayılmamalıdır; aslında yanlış negatiftir.
- Tek sınıflı (ön plan / arka plan) bir problemde ön plan sınıfı için doğru pozitifler bu eşiğe göre sayılır.

Görsel karşılaştırmada (ekrandan, 00:50:00) ilk U-Net, koyu parçacıkların merkezini bulup kenarlarını daraltıyordu; ince ayarlı model kenarlarla birlikte gerçek maskeye çok daha yakındı. Hoca, %95 eşikte ilk modelin bazı tahminlerinin doğru pozitif sayılmayacağını, ince ayarlı modelinkilerin sayılacağını söyledi. Model büyük nesnelerde ve birbirine çok yakın parçacıklarda başarısız oluyordu.

Hoca ayrıca terim düzeltmesi yaptı: slaytta "görsel muayene" yazıyordu; bu bağlamda "görsel analiz" denir.

## 6. Mobil Telefon Fiyat Aralığı Sınıflandırması

### 6.1 Veri ve hazırlık

Bu çalışmada telefon özelliklerinden fiyat aralığı tahmin edildi. Veri setinde 2000 örnek ve 20 özellik vardı; hedef değişken 4 sınıflı fiyat aralığıydı (0 en düşük, 3 en yüksek). Boş hücre yoktu. 8 kategorik ve 13 sayısal değişken vardı. Her sınıfta 500 örnek bulunduğundan veri dengeliydi.

Adımlar (ekrandan, 00:55:00): veri setini ayırma, özellikleri ölçekleme, model oluşturma, model derleme, modeli eğitme, model değerlendirme. Özelliklerin bir kısmı binler mertebesinde, bir kısmı 0,5 civarında olduğu için standart ölçekleme yapıldı: her özellik ortalaması 0, standart sapması 1 olacak şekilde dönüştürüldü. Veri %80 eğitim, %20 test ayrıldı.

### 6.2 Yedi modelin karşılaştırılması

Model yapısı, aktivasyon, optimizasyon algoritması, kayıp fonksiyonu, epok sayısı ve yığın boyutu değiştirilerek 7 model denendi:

- **Model 1 ve 2:** Bütün katmanlarda softmax kullanan model çok düşük doğruluk verdi. Softmax çıktıyı olasılık dağılımına çevirdiği için genelde son katmanda kullanılır. Ara katmanlarda ReLU, sonda softmax kullanan Model 2 çok daha iyiydi.
- **Model 3:** Kayıp fonksiyonu değiştirildi. Sparse categorical crossentropy hedefleri tamsayı olarak, categorical crossentropy one-hot kodlanmış olarak alır. Sonuçlar çok yakındı.
- **Model 4 ve 5:** Optimizasyon algoritması değiştirildi (ekrandan, 01:00:00).

| Model | Nöronlar | Aktivasyon | Optimizasyon | Epok | Yığın | Doğruluk |
|---|---|---|---|---|---|---|
| Model 2 | 128-64-4 | ReLU-ReLU-Softmax | Adam | 20 | 64 | %93,50 |
| Model 4 | 128-64-4 | ReLU-ReLU-Softmax | SGD | 20 | 64 | %76,75 |
| Model 5 | 128-64-4 | ReLU-ReLU-Softmax | RMSprop | 20 | 64 | %93,25 |

- **Model 6:** Epok 20'den 30'a, yığın boyutu 64'ten 128'e çıkarıldı; doğruluk %92,75'e düştü.
- **Model 7:** Nöron sayıları artırıldı; doğruluk %92,25'e düştü. Bu veri için küçük ve basit modeller daha iyiydi.

En iyi model Model 2 oldu: 3 katman, ReLU ve son katmanda softmax, Adam, sparse categorical crossentropy, %93,50.

> **Ders sonrası not:** Sunumda daha büyük yığın boyutunun gradyanları "daha düzensiz" yaptığı söylendi. Doğrusu: büyük yığın, gradyan tahminindeki gürültüyü azaltır; küçük yığın daha gürültülü gradyan verir. Büyük yığınla epok başına güncelleme sayısı azalır, bu da aynı epok sayısında daha az öğrenmeye yol açabilir.

### 6.3 SGD neden düşük kaldı?

Öğrenci SGD'nin düşük sonucunu sabit öğrenme oranına bağlamıştı. Hoca buna itiraz etti:

- SGD'de öğrenme oranı sabit olmak zorunda değildir. Momentum eklenebilir; momentum ince bir ayar yapar.
- Derste anlatılan zamanlama (scheduling) ile öğrenme oranı zamanla düşürülebilir.
- SGD tek boyutlu tablo verilerinde genelde daha yüksek öğrenme oranlarında, $10^{-1}$ ile $10^{-2}$ civarında daha etkili çalışır.
- SGD kötü bir yöntem değildir; ama momentum açılmamış ve zamanlama yapılmamışsa bir noktaya takılıp kalabilir ("kilitlenme") ve kurtulamaz.

Slayttaki "RMSprop yalnız gradyan büyüklüğünü, Adam hem büyüklüğünü hem yönünü dikkate alır" açıklaması da sunumda yer aldı (ekrandan, 01:00:00).

> **Ek bilgi (derste anlatılmadı):** Daha doğru bir ifadeyle RMSProp yalnız gradyan karelerinin hareketli ortalamasını (ikinci moment) kullanarak her parametrenin adımını ölçekler. Adam buna ek olarak gradyanın kendisinin hareketli ortalamasını (birinci moment, momentum) da kullanır; ayrıca ilk adımlardaki sapmayı düzelten bias düzeltmesi yapar.

### 6.4 Literatürle karşılaştırma

Test kümesi $2000 \times 0{,}2 = 400$ örnekti. Hoca, internette aynı veride 600 test örneğiyle %96 bulan bir çalışma olduğunu, %99 bildiren bir çalışmada ise bir sorun olduğunu düşündüğünü söyledi. Bu verinin eski ve üzerinde çok çalışılmış bir veri olduğunu, %93,5'in kötü olmadığını belirtti ve karışıklık matrisinin de rapora eklenmesini istedi.

## 7. Uydu Görüntülerinde Semantik Segmentasyon

### 7.1 Problem ve veri

Uydu görüntüleri uydulardan, insansız hava araçlarından ve yüksek irtifada uçan uçaklardan elde edilir. Coğrafi değişimleri izlemek, doğal afetleri takip etmek ve bölgeleri sınıflandırmak için kullanılır. Semantik segmentasyon piksel düzeyinde sınıflandırma yaptığı için bir bölgenin arazi mi, su mu, tarım alanı mı olduğu görüntüden çıkarılabilir (ekrandan, 01:10:00).

Veri seti, Dubai üzerinden alınmış 72 uydu görüntüsünden oluşuyordu ve 6 sınıf vardı: bina, arazi, yol, bitki örtüsü, su ve etiketsiz. Veri az olduğu için veri artırma ile (döndürme, çevirme, ölçekleme) yaklaşık 400 görüntüye çıkarıldı. Yaklaşık %70-75'i eğitimde, kalanı doğrulamada kullanıldı.

### 7.2 Model

CNN tabanlı U-Net kullanıldı. U-Net'in kodlayıcı ve kod çözücü yapısı vardır: kodlayıcı görüntüyü küçük parçalara bölerek özellik çıkarır, kod çözücü görüntüyü yeniden aynı boyuta getirip her pikseli sınıflandırır. Kodlayıcı olarak Keras'taki önceden eğitilmiş **Inception-ResNet-V2** seçildi; uzaktan algılama görüntülerinde iyi çalıştığı okunmuştu. VGG16 kodlayıcı ile de denendi ama tahminler beklenen düzeyde değildi. Inception-ResNet-V2 ile tahmin maskeleri gerçek maskelere çok yakındı.

### 7.3 Hocanın soruları: sınıf dengesizliği piksel düzeyindedir

Hoca, segmentasyonda sınıf dağılımının nasıl anlatılması gerektiğini sordu: Bir görüntüde bitki örtüsü ve su çok, arazi az olabilir. Bu durumda etiket histogramı görüntü sayısıyla değil **piksel sayısıyla** çıkarılmalıdır: 72 görüntünün tamamında kaç piksel bina, kaç piksel su, kaç piksel etiketsiz? Öğrencide bu histogram yoktu.

Ayrıca "etiketsiz" sınıfın ne anlama geldiği tartışıldı. Hoca, bazı çalışmalarda (ör. hiperspektral görüntülerde) görüntünün bir kısmının bilerek etiketsiz bırakıldığını ve modelin etiketli piksellerden öğrenerek etiketsiz piksellerin sınıfını tamamlamaya çalıştığını anlattı. Bu çalışmadaki durumun böyle olmadığı, etiketli ve etiketsiz görüntülerin ayrı olduğu anlaşıldı.

## 8. Otomatik Kodlayıcı ile Film Öneri Sistemi

### 8.1 Öneri sistemleri ve otomatik kodlayıcılar

Bu sunumda otomatik kodlayıcının parametre analizi yapıldı ve film önerisinde kullanıldı.

İşbirlikçi filtreleme (komşuluk tabanlı) iki türlüdür (ekrandan, 01:25:00):

- **Kullanıcı tabanlı:** Kullanıcıların birbirine benzerliği esas alınarak öneri üretilir.
- **Ürün tabanlı:** Kullanıcının daha önce beğendiği ürünlere benzer ürünler önerilir ("bunu alanlar şunu da aldı").

Otomatik kodlayıcı simetrik bir mimaridir: kodlayıcı (encoder), darboğaz (bottleneck) ve kod çözücü (decoder). Çıkış katmanı giriş katmanıyla aynı boyuttadır, ağ girdinin sıkıştırılmış bir temsilini öğrenir. Birden fazla gizli katman varsa derin otomatik kodlayıcı, tek gizli katman varsa sığ ağ denir.

Hoca burada araya girip yapının dönüştürücü (Transformer) modellerle bağlantısını kurdu: Kodlayıcı bir özellik çıkarıcı (feature extractor) olarak çalışır. Darboğaz bu özellikleri toparlayıp karıştırır. Kod çözücü özellikleri daha anlamlı hale getirip bize bilgi sunar. Transformer'daki kodlayıcı-kod çözücü yapısı da bu mantıkla düşünülebilir.

### 8.2 Veri ve tür-oy matrisi

MovieLens 100K verisi kullanıldı: 943 kullanıcı, 1682 film, 18 film türü ve 1-5 arası toplam 100.000 oy. Bir film birden fazla türe ait olabilir.

Tür-oy matrisi şöyle kuruldu (ekrandan, 01:30:00):

1. Her film için 18 bitlik bir vektör oluşturulur; filmin ait olduğu türlere 1, diğerlerine 0 yazılır. Örneğin 144 numaralı film aksiyon ve gerilim, 562 numaralı film aksiyon, macera ve western türündedir.
2. Kullanıcının filme verdiği oy bu vektörle çarpılır. 58 numaralı kullanıcı 144 numaralı filme 4 verdiyse aksiyon ve gerilim sütunlarına 4 yazılır; 7 numaralı kullanıcı 562 numaralı filme 5 verdiyse üç türe 5 yazılır.
3. Böylece her kullanıcıya ait tür-oy matrisi $G$ oluşur.
4. $G$ ağa verilir, ağın çıktısı $G'$ olur (ekrandan, 01:35:00). Örneğin 4 olan değerler 3,8 ve 3,4'e, ortalama tahmin 3,6'ya dönüşür; 5 olan değerler 4,6, 4,8 ve 5 olur, ortalama 4,8 olur.

Gerçek oy ile tahmin arasındaki sapmalar, sistemin ne kadar iyi öğrendiğini gösterir. Hata ölçüsü olarak MSE ve RMSE, ayrıca precision, recall ve F1 kullanıldı.

### 8.3 Verinin boyutu üzerine soru-cevap

**Soru (hoca):** Slayttaki "18 girdi" film mi? Satırlar 943 kullanıcı mı, 1682 film mi?

**Cevap:** Girdi ve çıktı katmanı 1682 boyutluydu. Hoca sonunda yapıyı şöyle özetledi: Satırlar 1682 film; sütunlar 18 tür; hücrelerde o türe ait oyların toplamı var, yani $1682 \times 18$ boyutlu bir matris. Hoca anlatımda bir kopukluk olduğunu da belirtti.

**Soru (bir öğrenci):** Amaç kişinin hangi türleri sevdiğini bulmaksa, hangi filme kaç puan verdiğinin ne önemi var?

**Cevap (hoca):** Bir kullanıcı 1682 filmin hepsini izlememiştir; örneğin 78 film izlemiş ve oylamıştır. Amaç, bu 1682 film arasından o kullanıcıya hangisinin önerileceğini bulmaktır. Verilen puan, kullanıcının o filmi ve dolayısıyla o türü ne kadar sevdiğini gösterir.

### 8.4 Parametre seçimi

Parametreler sırayla, diğerleri sabit tutularak seçildi: önce optimizasyon algoritması (Adam, RMSProp, Adadelta, Adagrad), sonra aktivasyon (ReLU ve iki başka fonksiyon <!-- BELİRSİZ: altyazıda "Jeloo" ve "Celu"; büyük olasılıkla GELU ve SELU ya da CELU, karede görülmedi -->), sonra gizli katman yapısı, sonra öğrenme oranı, en son weight decay. ReLU daha kararlı göründüğü için seçildi; gizli katmanlar 20 ve 10 nöron, öğrenme oranı %1, weight decay 0,01 oldu. Tür bilgisi kullanılmadan yapılan analizlere göre hata çok daha düşük çıktı: kullanıcının yalnız oylarını değil oyladığı filmlerin türlerini de kullanmak daha güçlü öneri veriyordu. Bildirilen sonuçlar: RMSE 0,860, F1 0,551, precision 0,608, recall 0,621.

## 9. Bitcoin Fiyat Tahmininde Grid Search ve Bayes Optimizasyonu

### 9.1 Amaç ve iki aşamalı arama

Bu çalışmada Bitcoin'in kısa dönem fiyatı, LSTM ve GRU'yu birlikte kullanan hibrit bir modelle 1, 3 ve 5 gün sonrası için tahmin edildi. Hiperparametreleri rastgele seçmek yerine Grid Search ve Bayes optimizasyonu karşılaştırıldı. Arama iki aşamalıydı:

1. LSTM ve GRU katmanlarındaki nöron sayısı, dropout oranı ve yığın boyutu bulunur.
2. Bunlar modele yerleştirildikten sonra öğrenme oranı ve weight decay bulunur.

Performans ölçüleri: RMSE, MSE, MAE, MAPE, medyan mutlak hata ve $R^2$. Veri min-max normalizasyonundan geçtiği için ölçüler hem normalize hem de geri dönüştürülmüş (denormalize) değerlerle verildi; böylece iki türlü raporlayan çalışmalarla karşılaştırılabildi. Hiperparametre seçiminde ölçüt olarak $R^2$ kullanıldı.

### 9.2 Grid Search ve Bayes araması

- **Grid Search:** Belirli bir hiperparametre uzayında bütün kombinasyonları sistematik olarak dener. Karşılaştırılan parametre sayısı arttıkça hesaplama maliyeti çok yükselir.
- **Bayes optimizasyonu:** Amaç fonksiyonunun olasılıksal bir modelini kurar ve "akıllı bir strateji" ile sıradaki denemeyi seçer. Bütün kombinasyonları denemez; maliyeti daha düşüktür.

Bayes aramasında aralık verildi (nöron sayısı 32-128, dropout %10-%50); algoritma gerekirse 36 nöron ya da 0,25 dropout gibi ara değerleri deneyebilir. Grid Search'te ise her parametre için 3 değer verildi (ör. 32, 64, 128); yalnız bunlar denenir. İkinci aşamada Bayes araması için weight decay $10^{-3}$-$10^{-2}$, öğrenme oranı $10^{-4}$-$10^{-2}$ aralığında arandı; 15 iterasyon içinde hedef değeri en düşük olan seçildi.

Çevrim sayısı (ekrandan, 02:10:00): BayesSearchCV'de `n_iter = 50` kombinasyon ve `cv = 3` katlı çapraz doğrulama vardır, yani $50 \times 3 = 150$ model eğitilir. Her biri 25 epok eğitildiği için toplam $150 \times 25 = 3750$ epok olur. Grid Search tarafında toplam 6075 epok bildirildi; Grid Search daha uzun sürdü (Bayes 20-25 dakika, Grid Search 45 dakika ile 1 saat arası).

### 9.3 Zaman adımı seçimi

Veri, Yahoo Finance API'den alınan günlük kapanış fiyatlarıydı. Tahmin ufku (1, 3, 5 gün) için kaç günlük geçmişe bakılacağı (zaman adımı, pencere boyutu) seçildi: 1 günlük geçmişle 1 gün sonrası, 3 günlük geçmişle 3 gün sonrası, 5 günlük geçmişle 5 gün sonrası. Seçimde üç etken göz önüne alındı (ekrandan, 02:05:00):

- **Veri durumu:** Veri yeterince büyükse daha büyük zaman adımı (ör. 5) kullanmak mantıklı olabilir; model daha geniş bir zaman dilimine bakarak daha iyi öngörü yapar.
- **Piyasa dalgalanması:** Piyasa çok dalgalıysa daha büyük zaman adımı daha mantıklıdır. Bir gün %20 artıp ertesi gün %10 düşebilen bir varlıkta tek güne bakıp 5 gün sonrasını tahmin etmek yanıltır.
- **Modelin karmaşıklığı:** Büyük zaman adımı modeli daha karmaşık ve esnek yapar. Çok karmaşık bir modelle birlikte kullanılırsa aşırı öğrenme riski artar.

### 9.4 Model ve sonuçlar

Model: LSTM katmanı, dropout, GRU katmanı, dropout ve yoğun (dense) çıkış katmanı. Dropout katmanı, verilen oran ölçüsünde nöron bağlantılarını keserek aşırı öğrenmeyi engellemeye çalışır.

Bayes optimizasyonu üç tahmin ufkunda da daha iyi ölçüler verdi; en iyi sonuç 1 günlük tahminde alındı ($R^2 \approx 0{,}98$). Grid Search'ün bulduğu parametrelerle 1 günlük tahminde $R^2$ yaklaşık $-5{,}32$ çıktı; doğrulama kaybı eğitim kaybının üstündeydi. Sunumda bu "yetersiz öğrenme" diye yorumlandı ve 3 ile 5 günlük tahminlerde sorun olmadığı için nedenin veri değil optimizasyon (yerel minimuma takılma) olabileceği söylendi.

> **Ders sonrası not:** Doğrulama kaybının eğitim kaybından belirgin yüksek olması genelde yetersiz öğrenmenin değil aşırı öğrenmenin işaretidir. Negatif $R^2$ ise modelin, her zaman ortalamayı tahmin eden basit bir modelden bile kötü olduğunu gösterir.

Hoca sunumun ayrıntılı kısımlarını kısaltmasını istedi; merak edenlerin bu kısımları araştırabileceğini söyledi.

## 10. CNN ve LSTM ile Kuş Sesi Sınıflandırma

### 10.1 Problem ve Xeno-canto platformu

Bu sunum, kuş seslerinin CNN ile sınıflandırılmasını öneren bir makalenin incelenmesi ve geliştirilmesi üzerineydi. Çok sınıflı bir sınıflandırma problemiydi: kuş sesinin hangi türe ait olduğu bulunacaktı. Makalede önceden eğitilmiş bir ağ, seslerin görsel temsili olan spektrogramlarla ince ayar (fine-tuning) yapılarak kullanılıyordu.

Veri kaynağı Xeno-canto'ydu: herkesin doğada kaydettiği kuş seslerini yükleyebildiği, topluluk tarafından geliştirilen açık bir platform (ekrandan, 02:20:00). Sunum sırasında 10.488 tür ve yaklaşık 12.334 saatlik kayıt vardı. Türü bilinmeyen kayıtlar "Mysteries" bölümünde paylaşılır, başka uzmanlar türü belirler. Kayıtlar A'dan E'ye kalite derecesiyle etiketlenir (gürültü, başka kuşlarla örtüşme vb.); ayrıca cinsiyet, ötüş türü, ülke, tarih gibi etiketler vardır. Kayıtlar RESTful API ile MP3 olarak indirilebilir.

**Soru (hoca):** Birisi bir kuş sesini yanlış türle yüklese, bunu kontrol eden bir mekanizma var mı?

**Cevap (öğrenci):** Muhtemelen var; yüklenen kayıt doğrudan yayımlanmıyor, incelemeden geçtiği düşünülüyor ve platform pek çok akademik çalışmaya konu oluyor.

Kaggle'da düzenlenen BirdCLEF yarışmalarında da hazır veri setleri sunulur (incelenen makalede 2017'de 1500 türe ait 36 bin kayıt). Makaledeki araştırmacı bunun yerine Xeno-canto'dan 50 Avrupa kuş türüne ait kayıtları, her türden eşit sayıda indirmişti.

### 10.2 Ön işleme

```text
MP3 kayıt
  -> WAV'a dönüştürme (eşit parçalara bölmek için daha uygun)
  -> 3 saniyelik parçalara bölme (sonda kalan kısa parça atılır)
  -> RMS filtresi: çok sessiz, bilgi taşımayan parçalar elenir
  -> STFT ile spektrogram (MobileNet girdisi için 224x224)
  -> renkli harita (jet) ve gri tonlama olmak üzere iki sürüm
```

RMS eşiği deneme yanılmayla belirlendi: parçaların RMS değerleri sıralandı, düşük değerli parçalar tek tek dinlendi; 15'in altında gerçekten ses duyulmadığı için eşik 15 alındı. Kısa zamanlı Fourier dönüşümü (STFT), Fourier dönüşümünün pencerelenmiş, kısa sürelere uygulanan bir türüdür.

### 10.3 Makalenin sonuçları ve önerileri

Makalede 2, 10 ve 50 sınıflı deneyler yapılmıştı. İki sınıf neredeyse %100 ayrılırken 10 ve özellikle 50 sınıfta ciddi düşüş vardı. Renkli harita her durumda gri tonlamadan iyiydi; bunun nedeni MobileNet'in renkli görüntülerle önceden eğitilmiş olmasıydı. Araştırmacının önerileri: ResNet gibi daha büyük bir ağ kullanmak, gri tonlu görüntülerle eğitilmiş bir ağ kullanmak, farklı gama değerleriyle ek özellik eklemek.

### 10.4 Geliştirme: DenseNet121 ve LSTM

Mobil cihazlar için tasarlanmış CNN'leri karşılaştıran bir çalışmada DenseNet121'in top-1 doğruluğu en yüksekler arasındaydı (ekrandan, 02:30:00):

| CNN | Top-1 doğruluk (%) | Model boyutu (KB, TF) |
|---|---|---|
| DenseNet121 | 98,18 | 28.249 |
| DenseNet201 | 98,18 | 72.907 |
| MobileNet | 95,15 | 12.900 |
| MobileNetV2 | 94,54 | 9.271 |
| ResNet50 | 94,54 | 92.703 |
| VGG16 | 91,51 | 57.607 |

Öğrenci 10 Avrupa türü seçip her türden 20 kayıt indirdi (A kalitesinde, net ve örtüşmesiz kayıtlar). 3 saniyelik bölme ve RMS filtresinden sonra 4314 parça elde edildi. DenseNet121 çapraz entropi kaybı, SGD (momentum 0,9), 10 epok, yığın boyutu 32 ve karıştırma (shuffle) ile eğitildi. CPU'da 6-7 saat sürdü ama doğruluk yaklaşık %90'a çıktı; makaledeki 10 sınıflı MobileNet sonucunu açıkça geçti.

Konuşma tanımada LSTM sık kullanıldığı için MFCC özellikleriyle sıfırdan bir LSTM de eğitildi (ekrandan, 02:40:00): MFCC sayısı 13 ve 20, çapraz entropi, Adam, öğrenme oranı 0,001, 10 ve 20 epok, yığın 32, karıştırma açık. 10 epok ve 13 MFCC ile kayıp 0,6'da kaldı; 20 epokta 0,4'e, 20 epok ve 20 MFCC ile 0,29'a düştü. Eğitim yaklaşık 1 saat sürdü, yani DenseNet'in yaklaşık beşte biri. Öğrencinin vardığı sonuç: ses sınıflandırmada sesin görselleştirilmesinden çok frekans karakteristiklerinin analizi daha verimli bir çözüm sunuyor.

### 10.5 Hocanın yorumları

**Pencereleme mantığı:** Hoca, kayıtlarda kuşun bir dakika boyunca sürekli ötmediğini teyit ettirdi; kuş kesik kesik öter. Bütün kayda tek bir STFT uygulanırsa öttüğü kısa bölgeler o çözünürlükte görünmez. 3 saniyelik pencerelerin mantığı buradan gelir: kuşun öttüğü kısımları yakalamak.

**Etiketleme sorunu:** Bir kaydın türü belliyse (örneğin çalı kuşu), kayıt 3 saniyelik parçalara bölündüğünde her parça bu türle etiketlenir; oysa bazı parçalarda kuş hiç ötmüyor olabilir. Hoca bunun yerine iki aşamalı bir yaklaşım önerdi:

1. Türden bağımsız olarak "kuş sesi var mı" tespiti yapılır (doğada araç gürültüsü gibi sesler azdır).
2. Yalnız kuş sesi tespit edilen bölgeler 3 saniyelik pencerelere alınır ve tür etiketi onlara yazılır.

RMS eşiği sessiz parçaları atar, ama kuş sesine özgü değildir: yağmur gibi bir gürültü de eşiği geçebilir. Hoca bunu biyomedikal görüntülerle karşılaştırdı: bir hücreyi sınıflandırmak için önce hücre tespit edilip kırpılır, sonra sınıflandırılır, çünkü görüntüde birden fazla hücre olabilir. Seste de durum benzerdir: insan sesinin tespiti ile sesin kime ait olduğunun tespiti iki ayrı çalışmadır. Kuş sesi tespit edilen bölgelerin parçalanıp sonra sınıflandırılması bir yenilik içerebilirdi.

**MFCC seçimi:** MFCC 20'den fazla katsayı üretebilir ama bunların çoğu bilgi taşımayabilir. Genelde katsayılar çıkarıldıktan sonra PCA ya da LDA gibi yöntemlerle hangi katsayıların kullanılacağı seçilir; 13 ve 20 rastgele seçilmişti.

**LSTM ve karıştırma:** LSTM zaman serilerinde başarılıdır. Hoca, 3 saniyelik parçaları karıştırarak vermenin anlamlı olup olmadığını sorguladı; sıralı verilmeleri LSTM'e daha iyi öğretebilirdi. Öğrenci karıştırmayı ezberlemeyi önlemek için yaptığını söyledi.

## 11. Koşullu GAN ile Tablo Verisinde Sentetik Veri Üretimi

### 11.1 Amaç ve yöntem

Son sunumda ikili sınıflandırma problemi için koşullu GAN (conditional GAN) ile sentetik tablo verisi üretildi. Ardından orijinal veri ve sentetik+orijinal veri, Adam ve SGD ile farklı öğrenme oranlarında eğitilip karşılaştırıldı.

GAN bir üretici (generator) ve bir ayırıcı (discriminator) ağdan oluşur. "Koşullu" denmesinin nedeni, üretici ağa gürültüyle birlikte hedef değişkenin değerinin (0 ya da 1) de verilmesidir. Ayırıcı ağ, üretilen sentetik örnekleri gerçek örneklerle kıyaslayarak ayırt etmeye çalışır. İncelenen makalede Adam optimizasyonu kullanılmıştı.

Veri: kalp hastalığı veri seti, 918 satır ve 12 öznitelik; hedef değişken kalp hastalığı var (1) / yok (0). Kategorik değişkenler Label Encoder ile sayısala çevrildi, bütün değerler 0-1 aralığına normalize edildi. Boş değer yoktu. Korelasyon matrisine göre hedefle en ilişkili öznitelik "Oldpeak" idi.

### 11.2 GAN kayıpları ve üretilen veri

Üretici kaybı sıfır civarında kalırken ayırıcı kaybı yaklaşık 100. iterasyondan sonra büyük negatif değerlere indi, yaklaşık 330. iterasyonda $-120000$ civarından birden sıfıra sıçradı ve 500. iterasyona kadar orada kaldı (ekrandan, 02:50:00).

**Soru (hoca):** Ayırıcı kaybının önce bu kadar artıp (negatif yönde büyüyüp) sonra birden düşmesini nasıl yorumluyorsun?

**Cevap:** Öğrenci kesin bir yorum veremedi; veri elde edildikten sonra sıfıra indiğini söyledi. Hoca, ayırıcının üretilen satırın gerçek veriye benzerliğini ayırt etmeye çalıştığını, üreticinin de bu ayırt etmeye bakarak veri ürettiğini hatırlattı. Kayıp arttıkça üretici farklı örnekler üretecektir; bu kadar ani bir düşüşü beklemediğini söyledi.

Toplam yaklaşık 26 bin yeni örnek üretildi: bir sınıftan 19 bin küsur, diğerinden 6.290 örnek, yani yaklaşık 3'e 1 oranında.

**Soru (hoca):** Orijinal veri yaklaşık %55-%45 dengeliyken neden bir sınıftan diğerinin üç katı örnek ürettin?

**Cevap:** Öğrenci literatürdeki çalışmanın bu şekilde ürettiğini söyledi. Hoca, bir buçuk katı anlayabileceğini ama üç katın dengeli bir veriyi gereksiz yere dengesiz hale getirdiğini belirtti. Ayrıca istatistik tablosundaki değerlerin normalize mi orijinal ölçekte mi olduğunu sordu: yaş özelliğinde en büyük değerin 0,99 olması, verinin normalize olduğunu ve orijinal ölçeğe çevrilerek yorumlanması gerektiğini gösteriyordu.

### 11.3 Eğitim sonuçları

Orijinal veride SGD ve Adam ile 0,01, 0,1 ve 1 öğrenme oranları denendi. Adam'da 0,01 öğrenme oranında kayıp yaklaşık 0,46'dan 0,1 civarına hızla düştü; 0,1 ve 1 oranlarında kayıp hiç değişmedi (ekrandan, 02:55:00). Orijinal veride Adam ile test sonucu: doğruluk 0,88; sınıf 0 için precision 0,89, recall 0,86; sınıf 1 için precision 0,86, recall 0,89; test destek toplamı 184. Sentetik+orijinal veride Adam ile doğruluk 0,91'e kadar çıktı.

<!-- BELİRSİZ: Sonuç bölümünde öğrenci en iyi modeli "Adam ve 0,1 öğrenme oranı" diye özetledi; oysa gösterilen kayıp grafiğinde en düşük kayıp 0,01 oranındaydı. Hangisinin doğru olduğu altyazıdan ve karelerden kesinleşmedi. -->

### 11.4 Hocanın değerlendirmesi: sentetik veri teste girmemeli

Hoca, Kaggle'da bu veride lojistik regresyon ve CatBoost ile %93-94'e varan sonuçlar olduğunu belirtti. Ardından asıl değerlendirme sorununu açıkladı: Öğrenci sentetik ve orijinal veriyi birleştirip sonra %80-%20 ayırmıştı. Bu durumda GAN'ın ürettiği örnekler test kümesine girer.

> **Hocanın vurgusu:** Kabul gören yöntem, paylaşılan orijinal veriyi önce eğitim ve test olarak ayırmak, testi yalnız orijinal veriyle yapmaktır. 918 örnek %80-%20 ayrılırsa yaklaşık 184 örnek test, 734 örnek eğitim olur. Sentetik veri yalnız eğitim kısmına eklenir. GAN'ın ürettiği verinin teste girebileceğini savunanlar da var, ama o zaman performans yüksek çıkar; orijinal testle değerlendirildiğinde performansın düşme ihtimali yüksektir.

## 12. Örnek Sorular

**Soru 1** (derste sözlü, 00:07:33-00:08:51): Bir veri setinde 300 bin normal ve 400 dolandırıcılık örneği var. Veri tabakalı örneklemeyle %60 eğitim+doğrulama ve %40 test olarak ayrılırsa test kümesinde her sınıftan kaç örnek olur?

> **Çözüm (derste verildi):** Tabakalı örnekleme sınıf oranlarını korur. Normal: $300000 \times 0{,}40 = 120000$. Dolandırıcılık: $400 \times 0{,}40 = 160$.

**Soru 2** (ekrandan, 00:20:00; derste sözlü, 00:19:46-00:20:40): Karışıklık matrisi gerçek "hayır" için 56.651 doğru / 0 yanlış, gerçek "evet" için 45 kaçırılmış / 50 bulunmuş ise doğruluk ve "evet" sınıfının duyarlılığı nedir? Bu problemde hangi ölçü daha anlamlıdır?

> **Çözüm (derste verildi, sayılar python ile doğrulandı):** Toplam $56651 + 0 + 45 + 50 = 56746$. Doğruluk $= (56651 + 50)/56746 \approx 0{,}9992$. "Evet" recall $= 50/95 \approx 0{,}526$. Dengesiz veride sınıf bazlı recall daha anlamlıdır; doğruluk çoğunluk sınıfı yüzünden şişer.

**Soru 3** (ekrandan, 00:45:00; derste sözlü, 00:44:13-00:46:37): Bir segmentasyon modelinin test maskelerinde 16.879.601 arka plan ve 7.499.791 ön plan pikseli var. Piksel bazlı doğruluk 0,83, IoU 0,675 çıkmıştır. Doğruluk neden yanıltıcıdır, hangi ölçüye bakılmalıdır?

> **Çözüm (derste verildi; çoğunluk oranı hesabı eklendi):** Piksellerin $16879601/24379392 \approx 0{,}692$'si arka plandır; her piksele "arka plan" diyen bir model bile yaklaşık %69 doğruluk alır. Bu yüzden doğruluk, ön plandaki başarıyı iyi göstermez. IoU ya da Dice'a, nesne düzeyinde ise örtüşme eşiğine (mAP50, mAP95) göre sayılan doğru pozitiflere bakılmalıdır.

**Soru 4** (derste sözlü, 00:46:56-00:50:20): Gerçek maskede bir daire var; model ortasında daha küçük bir daire bulmuş ve örtüşme %50'nin altında. mAP50 ölçütüne göre bu tahmin nasıl sayılır?

> **Çözüm (derste verildi):** Örtüşme eşiğin altında kaldığı için doğru pozitif sayılmaz; nesne kaçırılmış kabul edilir, yani yanlış negatiftir. Eşik %95 alınırsa (hassas veri setleri) yalnız hatları çok iyi örtüşen tahminler doğru pozitif olur.

**Soru 5** (derste sözlü, 01:02:34-01:02:43): 2000 örneklik bir veri %80 eğitim, %20 test olarak ayrılırsa test kümesinde kaç örnek olur?

> **Çözüm (derste verildi):** $2000 \times 0{,}20 = 400$.

**Soru 6** (derste sözlü, 01:12:33-01:14:00): Semantik segmentasyon verisinde etiket dağılımını gösteren histogram neyin sayısıyla çıkarılmalıdır?

> **Çözüm (derste verildi):** Görüntü sayısıyla değil, her sınıfa ait piksel sayısıyla. Bir görüntüde birden fazla sınıf olabileceği ve sınıfların kapladığı alan çok farklı olabileceği için dengesizlik piksel düzeyinde değerlendirilir (bütün veri setinde kaç piksel bina, kaç piksel su, kaç piksel etiketsiz).

**Soru 7** (ekrandan, 02:10:00): BayesSearchCV'de `n_iter = 50` ve `cv = 3` ise ve her model 25 epok eğitiliyorsa toplam kaç model ve kaç epok eğitilir?

> **Çözüm (ekrandan; python ile doğrulandı):** Model sayısı $50 \times 3 = 150$, toplam epok $150 \times 25 = 3750$.

**Soru 8** (derste sözlü, 02:31:19-02:34:12): Bir kuş türüne ait uzun kayıt 3 saniyelik parçalara bölünüp her parça o türle etiketlenirse ne sorun çıkar, nasıl giderilebilir?

> **Çözüm (derste verildi):** Kuş sürekli ötmediği için bazı parçalarda kuş sesi olmayabilir, ya da yalnız gürültü (ör. yağmur) olabilir; bu parçalar da tür etiketi alır ve etiketler kirlenir. RMS eşiği sessizliği atar ama gürültüyü ayırmaz. Önce türden bağımsız kuş sesi tespiti yapılıp yalnız sesin bulunduğu bölgeler pencerelenirse ve etiketlenirse veri daha doğru olur.

**Soru 9** (derste sözlü, 02:52:09 ve 02:57:14-02:58:05): Dengeli (yaklaşık %55-%45) 918 satırlık bir veri setine koşullu GAN ile 26 bin sentetik örnek eklenip birleşik veri %80-%20 ayrılmıştır. Bu kurgunun iki sorunu nedir?

> **Çözüm (derste verildi; sayılar python ile doğrulandı):** (1) Bir sınıftan diğerinin yaklaşık üç katı ($19000/6290 \approx 3$) örnek üretmek, dengeli veriyi gereksiz yere dengesiz hale getirir. (2) Birleşik veri ayrıldığı için sentetik örnekler test kümesine girer; performans olduğundan yüksek görünebilir. Doğrusu, orijinal 918 örneği önce ayırmak (yaklaşık 734 eğitim, 184 test), sentetik veriyi yalnız eğitime eklemek ve testi yalnız orijinal 184 örnekle yapmaktır.

## Dersin Toparlaması

Bu son derste öğrenci projeleri üzerinden dönem boyunca görülen konuların uygulamadaki tuzakları tartışıldı. Dengesiz veride doğruluk yerine sınıf bazlı duyarlılığa bakmak ve kaybı ağırlıklandırmak (focal loss) gerektiği; Adam ailesinde momentumun beta katsayılarıyla karşılandığı; SGD'nin momentum ve öğrenme oranı zamanlamasıyla ayarlanabildiği öne çıktı. Segmentasyonda instance ve semantik etiketler arasındaki dönüşüm, piksel bazlı doğruluğun arka plan yüzünden şişmesi, IoU ve Dice ile nesne düzeyinde eşik tabanlı değerlendirme (mAP50, mAP95) anlatıldı. U-Net, önceden eğitilmiş kodlayıcılar, otomatik kodlayıcının kodlayıcı-darboğaz-kod çözücü yapısı ve bunun Transformer'la bağlantısı, Grid Search ile Bayes optimizasyonunun maliyet farkı, ses sınıflandırmada spektrogram ile CNN ve MFCC ile LSTM yaklaşımları örneklerle görüldü.

Son olarak koşullu GAN ile sentetik veri üretiminde değerlendirmenin nasıl yapılması gerektiği vurgulandı: test kümesi yalnız orijinal veriden ayrılmalı, sentetik veri yalnız eğitimde kullanılmalıdır. Hoca, derste kısaca değinilen GAN'ın üretici-ayırıcı mantığının ve sunumlarda vurguladığı noktaların da dersin kapsamına girdiğini belirtti.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
