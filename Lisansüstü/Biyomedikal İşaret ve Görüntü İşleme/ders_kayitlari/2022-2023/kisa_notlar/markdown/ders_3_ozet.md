# Ders 3 Çalışma Özeti

## Genel Konular

- Dersin biçimi: proje ilerleme görüşmeleri
  - Bu derste konu anlatımı yapılmadı. Öğrenciler tıbbi görüntü işleme projelerindeki ilerlemeyi ekran paylaşarak sundu, hoca her projeye yöntem önerileri verdi.
  - Projelerin ortak çerçevesi: tıbbi görüntülerde sınıflandırma ve segmentasyon, transfer öğrenme ile kurulan bir karşılaştırma tabanı, ardından daha yeni yöntemlerle (derin ensemble, GAN) bu tabanın geçilmeye çalışılması.
- Meme kanseri görüntülerinde derin ensemble öğrenme
  - Bir öğrenci manifold öğrenmeyi probleme uyarlayamadığı için derin ensemble öğrenmeye yöneldiğini, bu konuda yakın tarihli bir derleme (review) makalesi ve meme kanseri veri setlerine uyarlanmış ensemble modeller incelediğini anlattı.
  - İncelenen örnek çalışmalardan biri histopatolojik görüntülerde CNN modellerini ensemble biçiminde birleştiriyordu.
  - Hocanın önerisi: önce CNN modelleri yerine hazır transfer öğrenme modellerini denemek, sonra bunları ensemble olarak birleştirmek; incelenen makaledeki EWT (Empirical Wavelet Transform) ve VMD (Variational Mode Decomposition) adımlarını da kendi verisine uyarlamak.
- Histopatolojide çekirdek (nuclei) segmentasyonu ve GAN tabanlı segmentasyon
  - Bir öğrenci maskeleri olan veri setleri aradı. Akciğer ve kolon kanseri histopatoloji görüntülerinde maske olmadığı için bu set bırakıldı; maskeli setler olarak PanNuke, MoNuSeg ve TNBC çekirdek segmentasyon seti konuşuldu. Bez (gland) segmentasyonu farklı bir problem olduğu için kapsam dışı bırakıldı.
  - İncelenen kodlar (slaytta): SGAN, Nu-GAN (histopatoloji görüntülerinde GAN ile hücre düzeyinde gözetimsiz temsil öğrenme), TSFD-Net (çekirdek segmentasyonu ve sınıflandırması için doku özgü öznitelik damıtma ağı; PanNuke kullanır, GAN değildir), HoVer-Net (ekrandan, 00:10:00).
  - Nu-GAN'ın bağımlılığı olan HistomicsTK paketi kurulamadı. Hoca kurulum sorununa takılmadan U-Net ailesine geçilmesini önerdi.
  - Önerilen sıra: önce GAN'sız standart segmentasyon (U-Net, U-Net++, U-Net 3+, Swin-Unet, TransUNet), sonra GAN tabanlı segmentasyon yöntemleriyle karşılaştırma. Bunun için 2022 tarihli "Generative Adversarial Networks in Medical Image Segmentation" derlemesi gösterildi.
- Yarı gözetimli öğrenme (self-training)
  - Bir öğrenci self-training ile yarı gözetimli bir çalışma için veri setini indirip etiketlerle görüntüleri eşleştiren ön işleme kodunu yazdığını anlattı.
- Servikal sitoloji görüntülerinde sınıflandırma
  - Bir öğrenci servikal kanser veri setlerini inceledi. Literatürde en çok SIPaKMeD setinin (5 sınıf) kullanıldığını, örnek çalışmalarda ön işleme, öznitelik birleştirme, AlexNet gibi CNN'ler ve SVM sınıflandırıcı kullanıldığını aktardı. <!-- BELİRSİZ: Altyazıda "Fizion", "Şaf", "CNN A", "44 tane özellik" geçiyor; incelenen makalenin iki CNN'den öznitelik çıkarıp birleştirdiği ve SVM ile sınıflandırdığı anlaşılıyor, model adları ve özellik sayısı karede doğrulanamadı. -->
  - Hocanın önerisi: görüntüleri temizlemek, sınıf başına örnek sayısını çıkarmak, görüntü boyutlarına göre yeniden boyutlandırma ya da yama (patch) çıkarma kararı vermek, önce standart transfer öğrenme modelleriyle bir karşılaştırma tabanı kurmak, sonra GAN tabanlı ve değiştirilmiş yapılara geçmek.
- Üç sınıflı görüntü sınıflandırmada transfer öğrenme ve ensemble
  - Bir öğrenci üç sınıflı bir görüntü sınıflandırma problemi için Kaggle'daki CNN ve ensemble örneklerini inceledi (ekrandan, 00:20:00).
  - Hocanın önerisi: önce transfer öğrenme, sonra derin ensemble; ensemble için önce kavramsal altyapı ("Ensemble Deep Learning: A Review" gibi derlemeler) oluşturulmalı.

## Hocanın Özellikle Vurguladığı Kısımlar

- Önce karşılaştırma tabanı
  - Her projede ilk adım standart transfer öğrenme modelleriyle (DenseNet, ResNet, Inception, Xception, NASNet, EfficientNet) sonuç almaktır. Yeni yöntemin başarısı ancak bu tabana göre değerlendirilebilir.
- Yama çıkarmada hücre içeriği
  - Büyük görüntülerden yama kesilecekse yamalar hücre içermelidir. Arka plandan (hücre dışı bölgeden) kesilen yamalar normal ve anormal sınıflarda aynı görünür. Hastalık hücrelerin dağılımından ve morfolojik yapısından anlaşılır.
- Giriş boyutu
  - Hazır transfer öğrenme modelleri tipik olarak $224 \times 224$ giriş kabul eder; küçük görüntüler yeniden boyutlandırılır, büyük görüntülerden yama alınır.
- Yenilik
  - Literatürdeki bir makale temel alınabilir, ama sonunda ortaya yeni bir şey (yeni bir birleşim ya da yapı) konmalıdır.

## Kısa Tekrar Notları

- Transfer öğrenme tabanı: DenseNet, ResNet, Inception, Xception, NASNet, EfficientNet.
- Derin ensemble: birden çok derin modelin (örnekte üç model) çıktılarını birleştirir; önce kavramsal altyapı, sonra kod.
- EWT: Empirical Wavelet Transform. VMD: Variational Mode Decomposition. İkisi de işareti bileşenlere ayıran yöntemlerdir; incelenen makalede derin modellerle birlikte kullanılmıştır.
- Çekirdek segmentasyonu için maskeli setler: PanNuke, MoNuSeg, TNBC. Maskesiz set segmentasyon için kullanılamaz.
- Segmentasyon sırası: U-Net ailesi (U-Net, U-Net++, U-Net 3+, Swin-Unet, TransUNet), sonra GAN tabanlı segmentasyon.
- Servikal sitoloji: SIPaKMeD 5 sınıflıdır.
- Yama kesilecekse hücre içeren bölgeden kes; arka plan yaması sınıflar arasında ayırt edici değildir.
- Transfer öğrenme modelleri için tipik giriş $224 \times 224$.

## Detaylı Açıklamalar

- Derin ensemble ve sinyal ayrıştırma
  - İncelenen meme kanseri çalışmasında derin öğrenme modelleri ensemble biçiminde birleştirilmiş, bir kısmı sıfırdan eğitilmiş ("fully trained") olarak işaretlenmişti. Hoca, modellerin yerine transfer öğrenme modelleri konulmasını, ayrıca makalede kullanılan EWT ve VMD ayrıştırmalarının da yöntemde denenmesini istedi. Bu iki yöntem bir girdiyi frekans ya da kip (mode) bileşenlerine ayırır; böylece modele ham görüntünün yanında ayrıştırılmış bileşenler de verilebilir.
- Segmentasyon için veri seçimi
  - Segmentasyon eğitimi için her görüntünün piksel düzeyinde maskesi gerekir. Yalnız sınıf etiketi olan histopatoloji seti bu yüzden bırakıldı. PanNuke setinde görüntüler ve maskeler NumPy (`.npy`) dosyaları olarak geliyor. MoNuSeg ve TNBC setleri de çekirdek segmentasyonu için ek seçenek olarak önerildi.
- Kurulum sorunlarında yol seçimi
  - Bir kodun bağımlılığı (HistomicsTK) kurulamıyorsa, aynı işi yapan başka kodlarla devam etmek daha verimlidir. Hoca bu durumda TransUNet, Swin-Unet gibi segmentasyon ağlarına geçilmesini, GAN'lı yapılara ise karşılaştırma aşamasında dönülmesini önerdi.
- Servikal sitolojide yama mantığı
  - Pap smear tabanlı servikal görüntülerde hastalık, hücrelerin şeklinden ve dağılımından okunur. Bu yüzden büyük görüntüden rastgele yama kesmek yerine hücre içeren bölgelerden yama alınmalıdır. Aksi halde farklı sınıflardan gelen arka plan yamaları birbirinin aynısı olur ve model ayırt edici bilgi öğrenemez.
- Ensemble örneği
  - Ekranda gösterilen Kaggle örneğinde bir CNN, `Sequential` yapıyla art arda `Conv2D` (3×3, `same` dolgu, ReLU), `MaxPooling2D(2,2)` ve `BatchNormalization` katmanlarıyla kuruluyor, giriş boyutu `(50, 50, 3)`; aynı defterde birkaç modelin birleştirildiği bir ensemble bölümü bulunuyor (ekrandan, 00:20:00).

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
