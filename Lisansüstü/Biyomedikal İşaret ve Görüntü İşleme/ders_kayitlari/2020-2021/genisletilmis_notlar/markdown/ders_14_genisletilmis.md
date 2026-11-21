# Ders 14 Genişletilmiş Notu: Proje İlerleme Sunumları: Yama Tabanlı Sınıflandırma ve Derin Bölütleme Yöntemleri

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dersin Yapısı
- 2. Cervix93 Verisinde Çekirdek Merkezli Yama Sınıflandırması
- 3. Herlev Verisi ve İki Veri Setiyle Karşılaştırma
- 4. PanNuke Veri Setinde Çekirdek Bölütleme
- 5. Bölütleme ile Sınıflandırmayı Ayırmak: İki Aşamalı Yöntem
- 6. Değerlendirme Düzeni ve Güncel Derin Bölütleme Yöntemleri
- 7. Beyin Tümörü Bölütlemesinde ResUNet ve W-Net Denemeleri
- Örnek Sorular
- Dersin Toparlaması

## 1. Dersin Yapısı

Bu kayıt, dönemin son haftalarındaki proje ilerleme oturumlarından biridir. Üç öğrenci ekranını paylaşarak bir haftada yaptıklarını gösterdi, hoca da her projeye veri hazırlama, model seçimi ve değerlendirme açısından geri bildirim verdi. Projelerin ortak ekseni histopatolojik ve sitolojik görüntülerde hücre çekirdeği sınıflandırma ile tıbbi görüntü bölütlemedir. Bu notta sunumlar hocanın yorumlarıyla birlikte ders sırasıyla anlatılır; sunum yapanlar "bir öğrenci" diye anılır.

## 2. Cervix93 Verisinde Çekirdek Merkezli Yama Sınıflandırması

### 2.1 Yama çıkarma ve etiketleme

İlk öğrencinin verisi Cervix93 servikal sitoloji veri setidir. Veri setinde yalnız 93 görüntü vardır ve 3 sınıf bulunur. Görüntü sayısı derin öğrenme için az olduğundan hoca bir önceki hafta, verilen çekirdek merkezlerinin etrafından yamalar (patch) alınarak örnek sayısının artırılmasını önermişti. Öğrenci daha önce çekirdekleri doğrudan çıkarmayı denemişti; bu hafta yama yaklaşımına geçti.

Her görüntüden çekirdek merkezli 100×100 yamalar kesildi ve toplam 2433 yama elde edildi. Veri görüntü düzeyinde zaten etiketliydi; öğrenci her yamayı, alındığı görüntünün sınıfıyla yeniden etiketledi. Ekranda Google Drive'daki `patches` klasörü görünüyor: yamalar `frame000_0.png`, `frame000_1.png` gibi adlarla kaydedilmiş, yanında bir `cervix.csv` dosyası duruyor (ekrandan, 00:15:00). CSV dosyasında her satırda yamanın yolu ve sınıf adı var; eğitim kodu görüntüleri doğrudan bu yoldan okuyor.

Böylece problem şu hale geliyor: çekirdeklerin çevresinden alınan yamalarla görüntünün ait olduğu 3 sınıf ayırt edilmeye çalışılıyor. Yani tek tek hücre tipleri değil, görüntü sınıfı yama düzeyinde öğreniliyor.

### 2.2 İlk sonuç ve hocanın yorumu

Öğrenci Python'da önceden eğitilmiş Inception ağını kullandı ve veri artırma (data augmentation) uyguladı. Doğruluk yaklaşık %55 çıktı. Öğrenci parametreleri değiştirmeyi ve görüntülere ön işlem uygulamayı planlıyor.

Hoca %55'in, alınan yama boyutunda sınıfların iyi ayrışmadığını gösterebileceğini söyledi. 100×100'lük yama çekirdeği içine alıyor ama çevresindeki dokuyu kaçırıyor olabilir; sınıfı belirleyen bilgi yalnız çekirdekte değil, çekirdeğin bulunduğu dokuda da olabilir. Hocanın önerisi, merkezler zaten bilindiği için yama boyutunun 256×256 ve 512×512'ye, fırsat varsa daha da büyütülmesidir.

<!-- BELİRSİZ: Altyazıda "156'ya 256 ve 512'ye 512" geçiyor; büyük olasılıkla "256'ya 256 ve 512'ye 512". -->

Öğrencinin belirttiği gibi yama büyüyünce bir görüntüden çıkan yama sayısı azalır ve 2433'ten daha küçük bir veri kümesi oluşur. Hoca bunun veri artırmayla telafi edilebileceğini söyledi. Öğrenci 128 ve 256 boyutlarını sırayla deneyecek.

> **Ek bilgi (derste anlatılmadı):** Yama boyutu, ağın gördüğü bağlamı (receptive context) belirler. Küçük yama hücre içi ayrıntıya odaklanır, büyük yama ise hücrelerin dizilişini ve çevre dokuyu da içerir. Önceden eğitilmiş ağlar genelde 224×224 ya da 299×299 civarında girdi beklediği için farklı boyuttaki yamalar ağa verilmeden önce yeniden boyutlandırılır.

### 2.3 Model karşılaştırması

Hoca Inception'ın yanında NASNet, DenseNet ve ResNet ailelerinin de denenmesini, en yeni önceden eğitilmiş modellere bakılmasını istedi. Yaklaşımı şuydu: önce bilinen standart bir modelle sonuç yükseltilir, sonuç yüksek çıkmaya başlayınca diğer modellerle karşılaştırma yapılır.

## 3. Herlev Verisi ve İki Veri Setiyle Karşılaştırma

Aynı öğrenci daha önce Herlev servikal hücre verisinde U-Net ile bölütleme yapmış ve yaklaşık %90 doğruluk almıştı. Bu veriye daha alışkın olduğu için burada da derin öğrenmeyle doğrudan sınıflandırma yapacak.

Hoca iki veri setinin birlikte kullanılmasını istedi: iki ayrı veri seti olacak ama aynı sınıflandırma mantığıyla denenecek ve sonuçlar karşılaştırmalı raporlanacak. Hoca bunun bir yayına dönüşebileceğini düşündüğünü söyledi.

> **Hocanın vurgusu:** Yöntemin nasıl kurulduğunu gösteren bir akış şeması (flowchart) mutlaka çizilmeli.

## 4. PanNuke Veri Setinde Çekirdek Bölütleme

### 4.1 Veri setinin yapısı

İkinci öğrencinin verisi PanNuke veri setidir. Proje başta sınıflandırma olarak başlamış, ama veri seti bölütlemeye daha uygun olduğu için bölütlemeye geçilmişti. Sunum slaytlarının başlığı "PanNuke Dataset Nuclei Segmentation"dır (ekrandan, 00:20:00).

Öğrencinin anlattığı yapı şöyledir:

- Veri üç klasör (fold) halinde verilmiş; toplam 7901 örnek var.
- Görüntüler 256×256 boyutunda ve 3 bantlıdır (RGB).
- Maskeler 256×256×6 boyutundadır.
- Görüntüler 19 farklı doku tipinden alınmıştır.
- Maskenin ilk beş katmanı çekirdek sınıflarıdır. Slaytta bu sınıflar Neoplastic, Inflammatory, Connective, Dead ve Epithelial olarak renklerle gösteriliyor (ekrandan, 00:20:00). Altıncı katman çekirdek olmayan (non-nucleus) bölgedir.

Slaytta ayrıca örnek görüntüler üzerinde çekirdek olan ve olmayan noktalar işaretlenmiş durumda.

### 4.2 Çekirdek olmayan katmanın dönüştürülmesi

Hoca altıncı katman hakkında bir soru sordu: bu katman çekirdek olmayan bölgeyi gösteriyorsa, bütün çekirdekleri gösteren bir maskeye dönüştürülebilir mi? Öğrencinin cevabı evetti: bu katmanda 0'lar 1, 1'ler 0 yapılırsa bütün çekirdekler 1, arka plan 0 olan maske elde edilir. Çekirdek tipi belirtilmeden yalnız "çekirdek mi, değil mi" sorusu için bu katman kullanılabilir. Hoca da bütün hücrelerin yerini gösteren bu katmanın proje için yararlı olduğunu belirtti.

### 4.3 U-Net ve Dice ölçütü

Öğrenci bölütleme için U-Net modeli kurdu ve başarımı Dice ölçütüyle ölçtü. Slayt listesinde U-Net mimarisi ve "Dice Metric - Dice Coefficient" başlıklı slaytlar var; ikincisinde ölçüt şu biçimde veriliyor (ekrandan, 00:20:00, slayt küçük resmi):

$$\text{Dice}(X, Y) = \frac{2\,|X \cap Y|}{|X| + |Y|}$$

Burada $X$ tahmin edilen maske, $Y$ gerçek maskedir. Değer 0 ile 1 arasındadır; tam örtüşmede 1 olur.

İki klasör birleştirilip eğitim, üçüncü klasör test için kullanılmak istendi. Ancak iki klasör birleştirilince her eğitim 40 dakika ile 1 saat arasında sürdüğü için bu düzen tam denenemedi.

### 4.4 Baskın katman sorunu

Altı katmanın tamamı çıkış olarak verildiğinde Dice yaklaşık %82 çıktı. Ama öğrenci sunum için tahmin görüntülerini incelediğinde modelin yalnız altıncı katmana evrildiğini fark etti. Tahminlerde altıncı katman tamamen 1'lerle doluydu, diğer katmanlarda hiç çekirdek tahmini yoktu. Çekirdek olmayan piksellerin oranı çok yüksek olduğu için başarım tamamen bu katmandan geliyordu.

Rastgele seçilen örneklerde bazı gerçek maske katmanları renksiz görünüyordu. Bunun nedeni o görüntüde o çekirdek sınıfına ait hiç piksel olmaması, yani katmanın tamamen sıfırlardan oluşmasıdır. Ortadaki renkli görünüm de Python'un matris değerlerini boyamasından kaynaklanır.

Öğrenci bu katmanı çıkararak yeni bir eğitim başlattı.

> **Ek bilgi (derste anlatılmadı):** Sınıflar arasında piksel sayısı çok dengesizse, model en sık sınıfı her yerde tahmin ederek yüksek bir ortalama başarım elde edebilir. Bu yüzden bölütlemede başarım sınıf başına ayrı hesaplanır ya da arka plan sınıfı ortalamadan çıkarılır; ağırlıklı kayıp ya da Dice kaybı gibi dengesizliğe duyarlı kayıplar da kullanılır.

## 5. Bölütleme ile Sınıflandırmayı Ayırmak: İki Aşamalı Yöntem

### 5.1 Hocanın sorusu ve teşhisi

Hoca öğrenciye U-Net eğitiminde giriş ve çıkışın ne olduğunu sordu. Öğrenci giriş olarak orijinal görüntüyü, çıkış olarak altı katmanlı maskenin tamamını verdiğini söyledi. Hoca bu veri setinde bölütlemenin başarılıp başarılmadığını da sordu; öğrenci bu konuda çok çalışma olmadığını, ama veri setinin bölütleme ve sınıflandırma için hazırlandığını belirtti. Öğrenci de sorunun hem bölütleme hem sınıflandırmanın aynı anda yaptırılmasından kaynaklandığını düşündüğünü söyledi.

Hocaya göre U-Net ile sınıflandırma yaptırmak pek mümkün değildir. U-Net'in güçlü olduğu iş, verilen bir görüntüde hedef bölgeyi arka plandan ayırmaktır.

### 5.2 Beyaz tahtadaki şema

Hoca ekranını paylaşarak beyaz tahtada şu şemayı çizdi (ekrandan, 00:25:00):

```text
orijinal görüntü (çekirdekler)  --->  GT: maskenin 6. katmanından türetilen ikili maske
                                         hücre pikselleri    -> 1
                                         arka plan pikselleri -> 0
                                      bu çift ile U-Net eğitilir
```

Yani yer doğruluk (ground truth) olarak yalnız bütün çekirdekleri gösteren ikili maske verilir: hücreler 1, arka plan 0. Önce bu maskeler oluşturulur, U-Net bu ikili problem üzerinde eğitilir ve çekirdekler bulunur.

### 5.3 İkinci aşama: bulunan çekirdeklerin sınıflandırılması

Çekirdekler bulunduktan sonra ikinci aşamada her çekirdeğin çevresinden yamalar alınır, tıpkı ilk sunumdaki yama yaklaşımında olduğu gibi. Bu yamalar için de sınıf etiketleri (ikinci bir yer doğruluk) oluşturulur ve yamalar sınıflandırılır. Böylece bölütleme ve sınıflandırma iki ayrı problem olarak çözülür. Öğrenci de çekirdek sınıflarını şimdilik göz ardı edip yalnız altıncı katmanla bölütleme yapacağını söyledi.

## 6. Değerlendirme Düzeni ve Güncel Derin Bölütleme Yöntemleri

### 6.1 5 katlı çapraz doğrulama

Hoca, iki klasörü eğitim ve bir klasörü test olarak kullanmak yerine şu düzeni önerdi: üç klasör birleştirilir, sonra 5 katlı çapraz doğrulama (5-fold cross-validation) yapılır. Her seferinde katlardan biri test, kalanı eğitim olur ve işlem 5 kez tekrarlanır. Sonuçların ortalaması alınır.

Raporlanacak değerler: ortalama genel doğruluk (overall accuracy), F-ölçütü (F-measure), Dice ölçütü ve Kappa.

### 6.2 U-Net'in üstüne çıkmak

> **Hocanın vurgusu:** U-Net ve SegNet ile aynı veri setinde lisans öğrencileri de sonuç alabiliyor. Lisansüstü projede bunun üstüne çıkmak, birkaç farklı, kaliteli ve en güncel bölütleme yöntemini uyarlamak gerekir.

Hoca daha önce paylaştığı "Image Segmentation Using Deep Learning: A Survey" derleme makalesini açarak denenebilecek yöntem ailelerini gösterdi:

- Çok ölçekli ve piramit ağ tabanlı modeller (Multiscale Pyramid Networks).
- R-CNN tabanlı modeller.
- DeepLab ailesi: V3 ya da V3+.
- Dikkat (attention) tabanlı modellerden en az biri.
- Üretken modeller ve çekişmeli eğitim (generative models, adversarial training).

> **Ders sonrası not:** Hoca "DeepLab V3 Plus veya V4" dedi. DeepLab ailesinin yaygın bilinen son sürümü büyük olasılıkla DeepLabV3+'tır; resmi bir "DeepLab V4" sürümü yaygın değildir.

> **Ek bilgi (derste anlatılmadı):** Söz konusu derleme büyük olasılıkla Minaee ve arkadaşlarının 2020 tarihli makalesidir. R-CNN tabanlı bölütlemenin en bilinen örneği Mask R-CNN'dir; tespit edilen her nesne için ayrı bir maske üretir. DeepLab ailesi genişletilmiş (atrous) evrişim ve çok ölçekli havuzlama (ASPP) kullanır.

## 7. Beyin Tümörü Bölütlemesinde ResUNet ve W-Net Denemeleri

### 7.1 Katman ayıklama denemesi

Üçüncü öğrenci önceki haftalarda ResNet ile ResUNet karışımı bir modelle sonuç almıştı. Hocanın önerisiyle modelde kullanılmayan katmanları ayıkladı. Ancak hem U-Net'te hem ResNet tabanlı modelde doğruluk düştü ve model daha fazla bölgeyi hedef olarak almaya başladı. Ekranda Kaggle'da "ResUNet Segmentation" defteri ve yerel bir Jupyter defteri açık; Kaggle defterinde bir artık blok (`resblock`) fonksiyonu ve verinin `train_test_split(..., test_size=0.15, random_state=32)` ile ayrılması görülüyor (ekrandan, 00:30:00).

Jupyter defterinde model şu ayarlarla derlenip eğitilmeye çalışılıyor (ekrandan, 00:30:00):

```python
Adam = optimizers.Adam(lr=0.001)
seg_model.compile(optimizer=Adam, loss='binary_crossentropy',
                  metrics=['accuracy', dice_coef, precision, sensitivity, specificity])
history = seg_model.fit(x=X_train, y=Y_train, batch_size=64, epochs=100,
                        validation_split=0.20, verbose=1, initial_epoch=0)
```

Bu hücre ilk epokta `ValueError` ile durmuş. Defterde ayrıca doğruluk ve Dice katsayısının epoklara göre grafiğini çizen fonksiyonlar var.

### 7.2 W-Net ve kanal sayısı uyumsuzluğu

Hoca daha önce W-Net'e bakılmasını önermişti. Öğrenci bu mimariyi çalıştırmakta uzun süre zorlandı. Sorunun nedeni şuydu: mimari kodlayıcı olarak VGG19 kullanıyor ve TensorFlow'daki hazır VGG19 3 kanallı girdi bekliyor; öğrencinin verisi ise 4-5 kanallı. Öğrenci düzenlenmiş bir VGG19 ile eğitimi çalıştırmayı başardı, ama tahmin aşamasında sorun sürüyor; ya veri okuma biçiminde ya da eğitimde kullanılan kanal seçiminde bir hata olduğunu düşünüyor.

<!-- BELİRSİZ: Altyazıda mimari "Wnet", "W-Yunet" ve öğrencinin önerisi olarak "Double Unet" diye geçiyor. VGG19 kodlayıcılı yapı büyük olasılıkla Double U-Net'tir; derste hangisinin kastedildiği netleşmedi. -->

> **Ek bilgi (derste anlatılmadı):** ImageNet'te eğitilmiş bir kodlayıcı 3 kanallı girdiye göre ağırlıklandırılmıştır. Çok kanallı (örneğin çok modlu MR) veride ya ilk evrişim katmanı yeni kanal sayısına göre değiştirilir, ya girdinin önüne kanalları 3'e indiren bir 1×1 evrişim konur, ya da kodlayıcı rastgele ağırlıklarla eğitilir.

### 7.3 Hocanın yönlendirmesi

**Soru:** VGG19 yerine başka mimariler de kullanılabilir mi? **Cevap:** Evet. Öğrenci Inception V3 ve ResNet50'yi de denemiş, ama VGG19 ile başkalarının çalıştırmış olmasından dolayı ona zaman harcamıştı. Hoca bunların daha iyi sonuç vereceğinden emin olduğunu söyledi.

Hoca öğrenciyi tek bir mimariye sıkışıp kalmamaya yönlendirdi: W-Net yapılamıyorsa ikinci öğrenciye gösterilen derin bölütleme yöntemlerine geçilmeli, özellikle çok ölçekli ve dikkat tabanlı olanlar denenmeli. İkinci öğrenciye söylenenler bu proje için de geçerlidir. Temel problem tümörlü bölgenin bölütlenmesidir ve çalışma buna göre ilerleyecek.

## Örnek Sorular

**Soru 1** (derste sözlü, 00:15:11): Çekirdek merkezli 100×100 yamalarla yapılan 3 sınıflı sınıflandırmada doğruluk yaklaşık %55 kaldı. Olası neden nedir, ne yapılmalıdır?

> **Cevap (derste verildi):** Bu yama boyutunda sınıflar iyi ayrışmıyor olabilir; yama çekirdeği alıyor ama çevredeki dokuyu kaçırıyor olabilir. Merkezler bilindiği için yama boyutu 256×256 ve 512×512'ye büyütülür, azalan örnek sayısı veri artırmayla telafi edilir, farklı önceden eğitilmiş ağlar (NASNet, DenseNet, ResNet) karşılaştırılır.

**Soru 2** (derste sözlü, 00:19:30): PanNuke maskesinin altıncı katmanı çekirdek olmayan bölgeyi gösteriyor. Bu katman bütün çekirdekleri gösteren bir maskeye dönüştürülebilir mi?

> **Cevap (derste verildi):** Evet. Katmandaki 0'lar 1, 1'ler 0 yapılırsa çekirdekler 1, arka plan 0 olan ikili maske elde edilir.

**Soru 3** (derste sözlü, 00:21:54): U-Net'e giriş olarak orijinal görüntü, çıkış olarak altı katmanlı maskenin tamamı verildiğinde model yalnız baskın katmanı öğrendi. Nasıl bir düzen önerilir?

> **Cevap (derste verildi):** U-Net ile sınıflandırma yaptırmak pek mümkün değildir. Önce yalnız altıncı katmandan türetilen ikili maske (hücreler 1, arka plan 0) ile çekirdek bölütlemesi yapılır. İkinci aşamada bulunan çekirdeklerin çevresinden yamalar alınıp sınıflandırılır. Değerlendirme üç klasör birleştirilerek 5 katlı çapraz doğrulamayla yapılır; ortalama doğruluk, F-ölçütü, Dice ve Kappa raporlanır.

**Soru 4** (derste sözlü, 00:31:01): Hazır VGG19 kodlayıcısı 3 kanallı girdi beklerken veri 4-5 kanallıysa ne yapılabilir?

> **Cevap (derste verildi):** Kodlayıcı uyarlanabilir (öğrenci düzenlenmiş bir VGG19 kullandı) ya da VGG19 yerine Inception V3, ResNet50 gibi başka mimariler kullanılabilir. Mimari yine çalışmıyorsa çok ölçekli ve dikkat tabanlı güncel bölütleme yöntemlerine geçilir.

## Dersin Toparlaması

Bu derste proje ilerlemeleri üzerinden tıbbi görüntü analizinde iki temel tasarım kararı öne çıktı. Birincisi, yama tabanlı sınıflandırmada yama boyutunun ağın gördüğü bağlamı belirlemesidir: çekirdek merkezli küçük yamalar dokuyu kaçırabilir, bu yüzden yama boyutu büyütülerek denenmeli ve azalan örnek sayısı veri artırmayla telafi edilmelidir. Farklı önceden eğitilmiş ağlar karşılaştırılmalı, yöntem bir akış şemasıyla sunulmalıdır.

İkincisi, bölütleme ile sınıflandırmanın ayrılmasıdır. PanNuke'da altı katmanlı maskeyle eğitilen U-Net, piksellerin çoğunu tutan çekirdek olmayan katmanı öğrenerek yanıltıcı biçimde yüksek bir Dice verdi. Hocanın önerdiği yol önce ikili çekirdek bölütlemesi, sonra bulunan çekirdeklerin yamalarıyla sınıflandırmadır. Değerlendirme 5 katlı çapraz doğrulamayla ve ortalama doğruluk, F-ölçütü, Dice ve Kappa ile yapılmalıdır. Lisansüstü düzeyde U-Net ve SegNet yetmez; çok ölçekli piramit, R-CNN tabanlı, DeepLab, dikkat tabanlı ve çekişmeli eğitimli güncel yöntemler uyarlanmalı, tek bir mimariye takılıp kalınmamalıdır.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
