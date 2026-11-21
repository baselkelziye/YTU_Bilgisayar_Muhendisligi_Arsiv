# Ders 14 Çalışma Özeti

## Genel Konular

- Proje ilerleme sunumları
  - Ders, üç öğrencinin dönem projelerindeki ilerlemeyi ekran paylaşarak anlattığı ve hocanın her projeye yöntemsel geri bildirim verdiği kısa bir oturum olarak geçti.
  - Konular: servikal sitolojide yama tabanlı sınıflandırma, PanNuke veri setinde çekirdek bölütleme ve beyin tümörü bölütlemesinde U-Net türevi ağlar.
- Cervix93 verisinde çekirdek merkezli yama sınıflandırması
  - 93 görüntüdeki çekirdek merkezlerinin etrafından yamalar kesildi; toplam 2433 yama elde edildi ve her yama görüntünün sınıfıyla etiketlenip bir CSV dosyasına yazıldı (`cervix.csv`, yamalar `frame000_0.png` gibi adlarla; ekrandan, 00:15:00).
  - Veri setinde 3 sınıf var. Yamalar 100×100 boyutunda.
  - Inception ağı ve veri artırma (data augmentation) ile yaklaşık %55 doğruluk elde edildi.
- Herlev verisinde bölütleme ve sınıflandırma
  - Daha önce Herlev verisinde U-Net ile bölütleme yapılmış, yaklaşık %90 doğruluk alınmıştı. Bu veride derin öğrenmeyle sınıflandırma yapılacak.
  - İki veri seti ayrı ayrı ama aynı sınıflandırma mantığıyla karşılaştırılacak.
- PanNuke veri setinde çekirdek bölütleme
  - Veri üç klasör (fold) halinde, toplam 7901 örnek. Görüntüler 256×256×3, maskeler 256×256×6.
  - Görüntüler 19 farklı doku tipinden alınmış. Maskenin ilk beş katmanı çekirdek sınıflarıdır: Neoplastic, Inflammatory, Connective, Dead, Epithelial (ekrandan, 00:20:00). Altıncı katman çekirdek olmayan bölgedir.
  - U-Net modeli kuruldu, başarım Dice ölçütüyle ölçüldü; sunumdaki slaytta Dice katsayısı $\frac{2|X \cap Y|}{|X| + |Y|}$ olarak veriliyor (ekrandan, 00:20:00, slayt küçük resmi).
  - Yaklaşık %82 Dice elde edildi, ama tahminler incelendiğinde modelin yalnız altıncı (çekirdek olmayan) katmanı öğrendiği görüldü.
- Beyin tümörü bölütlemesinde ResUNet ve W-Net denemeleri
  - ResNet ve ResUNet karışımı bir modelde kullanılmayan katmanlar ayıklandı; doğruluk düştü ve model daha fazla bölgeyi tümör olarak almaya başladı.
  - W-Net denemesinde kodlayıcı olarak TensorFlow'daki hazır VGG19 kullanılıyor; bu ağ 3 kanallı girdi beklediği halde veri 4-5 kanallı olduğu için uyumsuzluk çıktı. Düzenlenmiş bir VGG19 ile eğitim çalıştı, tahmin aşamasında sorun sürüyor.
  - Jupyter defterinde model Adam (öğrenme oranı 0.001), `binary_crossentropy` kaybı ve doğruluk, Dice katsayısı, kesinlik, duyarlılık, özgüllük ölçütleriyle derlenmiş; `batch_size=64`, `epochs=100`, `validation_split=0.20` ile eğitimde `ValueError` alınmış (ekrandan, 00:30:00).

## Hocanın Özellikle Vurguladığı Kısımlar

- Yama boyutu ayrışmayı etkiler
  - %55 doğruluk, alınan yama boyutunda sınıfların iyi ayrışmadığını gösterebilir. 100×100 yama yalnız çekirdeği alıp çevredeki dokuyu kaçırıyor olabilir.
  - Merkezler bilindiği için yama boyutu 256×256 ve 512×512'ye, fırsat varsa daha da büyütülmeli. Yama büyüyünce yama sayısı azalır; bu durumda veri artırma kullanılır.
- Farklı önceden eğitilmiş ağlar denenmeli
  - Inception'ın yanında NASNet, DenseNet ve ResNet'ler denenmeli; en yeni önceden eğitilmiş modellere bakılmalı.
  - Önce bilinen standart bir modelle yüksek sonuç alınmalı, sonra diğerleriyle karşılaştırılmalı.
- Çalışmanın akış şeması (flowchart) çizilmeli.
- Bölütleme ile sınıflandırmayı ayırmak
  - U-Net ile hem bölütleme hem sınıflandırma yaptırmak pek mümkün değildir.
  - Önce yalnız altıncı katmandan ikili bir yer doğruluk (ground truth) maskesi oluşturulmalı: hücreler 1, arka plan 0. U-Net yalnız bu maskeyle eğitilip çekirdekler bulunmalı (ekrandan, 00:25:00).
  - İkinci aşamada bulunan hücrelerin etrafından yamalar alınıp sınıflandırma yapılabilir.
- Değerlendirme düzeni
  - Üç klasör birleştirilmeli, 5 katlı çapraz doğrulama yapılmalı; her seferinde bir kat test olur, işlem 5 kez tekrarlanır.
  - Ortalama genel doğruluk, F-ölçütü, Dice ölçütü ve Kappa değerleri raporlanmalı.
- U-Net yetmez, güncel derin bölütleme yöntemleri uyarlanmalı
  - U-Net ve SegNet ile aynı veri setinde lisans öğrencileri de sonuç alabiliyor; lisansüstü projede bunun üstüne çıkmak gerekir.
  - "Image Segmentation Using Deep Learning: A Survey" makalesindeki yöntemler önerildi: çok ölçekli piramit ağları, R-CNN tabanlı modeller, DeepLab V3 / V3+, dikkat (attention) tabanlı modeller, üretken modeller ve çekişmeli eğitim (adversarial training).
- Tek bir mimariye takılıp kalmamak
  - VGG19 yerine Inception V3 ya da ResNet50 gibi başka kodlayıcılar kullanılabilir; bunların daha iyi sonuç vereceği belirtildi.
  - W-Net çalışmıyorsa diğer derin bölütleme yöntemlerine, özellikle çok ölçekli ve dikkat tabanlı olanlara geçilmeli. Temel problem tümörlü bölgenin bölütlenmesidir.

## Kısa Tekrar Notları

- Çekirdek merkezli yama sınıflandırmasında yama küçükse doku bağlamı kaybolur; yama boyutu büyütülerek (128, 256, 512) denenmeli.
- Büyük yamada örnek sayısı azalır; veri artırma ile telafi edilir.
- Karşılaştırılacak ağlar: Inception, NASNet, DenseNet, ResNet.
- PanNuke: 7901 örnek, 3 fold, görüntü 256×256×3, maske 256×256×6, 19 doku tipi, 5 çekirdek sınıfı + çekirdek olmayan katman.
- Çekirdek olmayan katmanın 0 ve 1 değerleri yer değiştirilirse bütün çekirdekleri gösteren bir maske elde edilir.
- Baskın katman yüzünden yüksek Dice yanıltıcı olabilir; tahminler görsel olarak kontrol edilmeli.
- İki aşamalı yol: önce ikili çekirdek bölütleme (U-Net), sonra bulunan çekirdeklerin yamalarıyla sınıflandırma.
- 5 katlı çapraz doğrulama, ortalama doğruluk, F-ölçütü, Dice ve Kappa.
- Önerilen bölütleme aileleri: çok ölçekli piramit, R-CNN tabanlı, DeepLab V3/V3+, dikkat tabanlı, GAN/çekişmeli eğitim.
- Hazır VGG19 3 kanallı girdi bekler; çok kanallı (4-5 kanal) veride kodlayıcı uyarlanmalı ya da başka mimari seçilmeli.

## Detaylı Açıklamalar

- **Cervix93'te yama tabanlı sınıflandırma.** Görüntü sayısı 93 ile sınırlı olduğu için hoca daha önce çekirdek merkezlerinin etrafından yama alarak örnek sayısının artırılmasını önermişti. Öğrenci her görüntüden 100×100 yamalar kesti ve 2433 yama elde etti. Veri zaten görüntü düzeyinde etiketliydi; her yama, alındığı görüntünün sınıfıyla etiketlendi ve dosya yolları ile sınıf adları bir CSV dosyasına yazıldı (ekrandan, 00:15:00). Python'da Inception ve veri artırma ile yaklaşık %55 doğruluk alındı. Hoca bunun, yamanın sınıfları ayırt edecek kadar bilgi taşımadığını gösterebileceğini söyledi: yama çekirdeği alıyor ama çevresindeki dokuyu alamıyor olabilir. Önerisi, merkezler bilindiği için yamaların 256×256 ve 512×512'ye büyütülmesi, sayının azalmasının veri artırmayla telafi edilmesidir. Öğrenci 128 ve 256 boyutlarını sırayla deneyecek.
  <!-- BELİRSİZ: Altyazıda "156'ya 256 ve 512'ye 512" geçiyor; büyük olasılıkla "256'ya 256 ve 512'ye 512". -->
- **İki veri setiyle karşılaştırmalı çalışma.** Öğrenci Herlev verisinde daha önce U-Net bölütlemesiyle yaklaşık %90 doğruluk almıştı ve bu veride de derin öğrenmeyle sınıflandırma yapacak. Hoca iki veri setinin aynı sınıflandırma mantığıyla ayrı ayrı denenip birlikte raporlanmasını, yöntemin bir akış şemasıyla gösterilmesini istedi.
- **PanNuke'da baskın katman sorunu.** Maskenin altıncı katmanı çekirdek olmayan bölgeyi gösterir ve piksellerin büyük bölümü bu katmandadır. Model altı katmanın tamamıyla eğitildiğinde yaklaşık %82 Dice verdi; ama tahmin görüntüleri incelendiğinde yalnız altıncı katmanın 1'lerle doldurulduğu, diğer katmanlarda hiç çekirdek tahmini yapılmadığı görüldü. Başarım tamamen bu baskın katmandan geliyordu. Bazı tahmin katmanlarının renksiz görünmesi, o görüntüde o çekirdek sınıfına ait hiç piksel olmamasındandır; renkler yalnız Python'un matris değerlerini boyamasıdır.
- **Hocanın önerdiği iki aşamalı yöntem.** Hoca beyaz tahtada şu şemayı çizdi: orijinal görüntü girdi, altıncı katmandan türetilen maske yer doğruluk (GT); bu maskede hücreler 1, arka plan 0 olur ve U-Net bu ikili maskeyle eğitilir (ekrandan, 00:25:00). Çekirdek olmayan katmandaki 0 ve 1 değerleri yer değiştirilerek bütün çekirdekleri gösteren maske elde edilir. Böylece önce yalnız çekirdekler bölütlenir. İkinci aşamada bulunan çekirdeklerin çevresinden yamalar alınır, bu yamalar için de sınıf etiketleri oluşturulur ve sınıflandırma yapılır.- **Değerlendirme ve yöntem seçimi.** Üç klasörden ikisini eğitim, birini test için kullanmak yerine hoca üç klasörün birleştirilip 5 katlı çapraz doğrulama yapılmasını, ortalama genel doğruluk, F-ölçütü, Dice ve Kappa değerlerinin çıkarılmasını önerdi. U-Net'in yetmeyeceğini, derin öğrenmeyle görüntü bölütleme üzerine bir derleme makalesindeki güncel yöntemlerin uyarlanması gerektiğini vurguladı.
- **Çok kanallı veride hazır kodlayıcı sorunu.** Üçüncü projede W-Net mimarisinin kodlayıcısı VGG19'dur. TensorFlow'daki hazır VGG19 3 kanallı girdi beklediği için 4-5 kanallı veriyle çakıştı. Öğrenci düzenlenmiş bir VGG19 ile eğitimi çalıştırdı, ama tahminde veri okuma ya da kanal seçimiyle ilgili bir hata sürüyor. Ekrandaki defterde model Adam (öğrenme oranı 0.001) ve `binary_crossentropy` ile derlenmiş, Dice katsayısı, kesinlik, duyarlılık ve özgüllük ölçütleri izleniyor; veri `train_test_split` ile %15 test olarak ayrılmış (ekrandan, 00:30:00). Hoca VGG19 yerine Inception V3 ya da ResNet50'nin kullanılabileceğini, W-Net olmuyorsa çok ölçekli ve dikkat tabanlı bölütleme yöntemlerine geçilmesini söyledi.
  <!-- BELİRSİZ: Altyazıda mimari "Wnet", "W-Yunet" ve "Double Unet" diye geçiyor. VGG19 kodlayıcılı yapı büyük olasılıkla Double U-Net'tir; derste hangisinin kastedildiği netleşmedi. -->

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
