# Ders 11 Çalışma Özeti

## Genel Konular

- Dersin yapısı: proje ilerleme sunumları
  - Ders öğrencilerin dönem projelerindeki ilerlemeyi göstermesiyle geçti. Hoca her sunumdan sonra veri seti, yöntem, karşılaştırma ve değerlendirme metrikleri üzerine öneriler verdi.
  - Projelerin ortak konusu tıbbi görüntülerde bölütleme (segmentation) ve sınıflandırma: kan yayması görüntülerinde hücre bölütleme, deri lezyonu sınıflandırma, kolorektal kanser derecelendirme, beyin MR görüntüsünde tümör bölütleme, servikal sitoloji ve çekirdek (nucleus) veri setleri.
- Etiketsiz veriyle anlamsal bölütleme (semantic segmentation)
  - Derin öğrenmeyle anlamsal bölütleme için görüntü ve etiket (label) çiftlerinden oluşan bir eğitim kümesi gerekir; slaytta 500 görüntü ve 500 etiket, eğitim için ResNet18, ResNet50 gibi hazır ağlar gösterildi (ekrandan, 00:10:00).
  - Etiket dosyası (annotation) olmayan bir veri setinde bir öğrenci, bölge tabanlı (region-based) bölütleme ve histogramı üç kutuya ayırarak (`histogram(x4,3)`, beyaz kan hücresi, kırmızı kan hücresi, arka plan) kendi etiketlerini üretmiş, hatalı yerleri elle düzeltmişti (ekrandan, 00:10:00).
  - Hocanın önerileri: etiketli başka bir veri setiyle (MoNuSeg gibi) önce hücre-arka plan ayrımını öğretip kendi verisine uygulamak (bir tür transfer öğrenme); ya da etiket gerektirmeyen eğiticisiz (unsupervised) bölütleme yöntemleri: K-means, Gauss karışım modelleri, bulanık C-ortalamalar (fuzzy c-means), eğiticisiz derin öğrenme ağları.
  - Bölütleme için U-Net, SegNet gibi yapılar ve hazır eğitilmiş modeller önerildi. Yalnız bir kısmı işaretli veri setlerinde işaretli bölgeleri kesip kullanmak mantıklı olabilir.
- Transfer öğrenme ve topluluk (ensemble) öğrenme
  - Deri lezyonu (ISIC) veri setinde InceptionV3 ile transfer öğrenme yapan bir öğrenci yaklaşık %85 doğrulama doğruluğu elde etmiş; sınıf bazında precision, recall, F1 ve support hesaplamıştı (ekranda 9 epokluk eğitim/doğrulama kaybı grafiği, ekrandan, 00:25:00).
  - Hoca transfer öğrenmeden sonra topluluk öğrenmenin denenmesini önerdi. Derin öğrenmede topluluk yöntemleri üç eksende sınıflandırılabilir: eğitim verisini çeşitlendirme (ör. bootstrap), modeli çeşitlendirme ve bunların birleşimi. Yatay oylama (horizontal voting) ve model ortalaması (model averaging) örnek olarak geçti.
  - Bu yöntemleri karşılaştırmalı uygulamak, alana ilk kez uyarlanacaksa yayın değeri taşıyabilir.
- Dengeli ve dengesiz veri seti, veri artırma
  - Sınıflardaki örnek sayıları eşitse veri seti dengelidir (balanced); doğruluk hesabı için daha uygundur.
  - Kolorektal kanser (CRC) veri setinde README'ye göre 300 görüntü vardır: 120 normal, 120 düşük dereceli, 60 yüksek dereceli (ekrandan, 00:35:00).
  - Veri artırma (data augmentation): görüntüleri dört yöne ve köşegen boyunca döndürerek veri yaklaşık beş katına çıkarılabilir.
  - Büyük görüntülerden küçük yamalar (patch) çıkarmak da örnek sayısını artırır. Veri azsa aynı grubun eski (CRC) ve genişletilmiş (extended CRC) veri setleri birleştirilebilir.
- Beyin tümörü bölütleme (BraTS, LGG)
  - BraTS 2020 eğitim setinde 369 örnek vardır; maskeler yalnız eğitim setinde olduğu için %66 eğitim (243), kalanı doğrulama (126) olarak ayrıldı (ekrandan, 00:50:00).
  - Hoca karşılaştırma için Papers with Code sitesini önerdi: veri setine göre yöntemler, sonuçlar ve kodlar bir arada bulunur.
  - Bölütleme başarımı için Dice (F1 ile aynı) ve IoU (Intersection over Union) kullanılır; aynı veri setindeki çalışmalarla aynı metrikler kullanılmalıdır.
  - Görüntü işleme kütüphanesinde renk haritasını (colormap) değiştirmek nicemleme (quantization) etkisi yaratır ve bölütleme yapılmış gibi görünür. Hoca hem bu hâlin hem özgün görüntünün ağa verilip metriklerle karşılaştırılmasını önerdi.
  - Derin öğrenme bölütleme taramasından (survey) aday modeller: tam evrişimli ağ (FCN), Mask R-CNN, DeepLab ailesi (v3, v3+), piramit yapıları, dikkat (attention) ağları, yinelemeli ağlar, üretici çekişmeli (adversarial) eğitim. Temel karşılaştırma için tam bağlantılı katmanlı basit bir yapı da kullanılabilir.
  - MR verisi kesitlerden (slice) oluşur; derinlik değiştikçe tümör kaybolur ya da beyin alanı daralır. Makalelerin kesit bazında mı, hasta bazında hacimsel (volumetric) mi değerlendirme yaptığı incelenmelidir.
  - LGG veri setini kullanan makalede U-Net kullanılmıştı; hoca önce U-Net'in veri artırmayla temel (baseline) olarak çalıştırılmasını, sonra başka yöntemlerle geçilmeye çalışılmasını istedi.
- Servikal sitoloji: Herlev ve Cervix93
  - Herlev veri setinde 917 görüntü vardır. Cervix93'te 93 yığın (stack) ve her yığında farklı odak kesitlerinden 10-20 görüntü vardır; bunlar birleştirilerek tek bir EDF görüntüsü oluşturulmuş, çekirdek merkezleri ayrı dosyada verilmiştir. EDF görüntüsü 1280×960 boyutundadır.
  - Hocanın önerdiği yöntem (tahtada çizildi, ekrandan, 01:35:00): her çekirdek merkezinin çevresinden 512×512 (ya da 256×256, 128×128) yamalar alınır, yama görüntünün sınıf etiketini alır. Böylece sınıflandırma için çok sayıda yama elde edilir, veri artırmayla sayı artırılır; önce sıfırdan eğitilmiş CNN, sonra transfer öğrenme (ResNet, DenseNet, Inception) denenir.
  - İleri aşama: tek EDF yerine en az ortak sayıdaki kesit (ör. 10) üst üste konarak $M\times N\times 10$ boyutlu çok kanallı girdi kullanılabilir.
- Büyük veri setleriyle çalışma
  - PanNuke veri seti: yaklaşık 200 bin etiketli çekirdek, 5 çekirdek tipi, 19 doku tipi; her biri 11-12 GB olan 3 parça (fold) numpy dizisi olarak paylaşılmış.
  - Büyük veri için verinin normalize edilip HDF5 (H5) dosyası olarak saklanması önerilir. Kaggle ortamı GPU (hocanın aktardığına göre Tesla P100) ve veri depolama imkânı sunar.
- Araştırmadan yayına yöntem
  - Makalede kullanılan yöntemi ve kodlarını bulup uygulamak, sonra yenilik (novelty) için değişiklik ve yeni model önermek, makalenin metrikleriyle sonucu geçmeye çalışmak, aynı veri setini kullanan yeni yayın ve taramaları incelemek, referansları baştan kaydetmek.

## Hocanın Özellikle Vurguladığı Kısımlar

- Etiket yoksa iki yol vardır
  - Etiketli başka bir veri setinden öğrenip kendi verisine aktarmak (transfer öğrenme) ya da hiç etiket gerektirmeyen eğiticisiz yöntemleri (K-means, Gauss karışım modeli, fuzzy c-means, eğiticisiz derin ağlar) kullanmak. Elle üretilen bölge tabanlı etiketlerin kalitesi soru işaretidir.
- Önce bölütleme, sonra sınıflandırma
  - Hücre sınıflandırma projelerinde hücrelerin önce iyi bölütlenmesi gerekir; sınıflandırma bunun üzerine kurulur.
- Karşılaştırma için aynı metrikler
  - Aynı veri setindeki yayınların kullandığı metrikler (Dice, IoU vb.) kullanılmalı, sonuçlar onlarla karşılaştırılmalıdır.
- Veri setinin nasıl kullanıldığı önemlidir
  - Makalelerin veriyi nasıl ele aldığı (kesit mi, hacim mi; hangi kesitler) incelenmeden yöntem karşılaştırması anlamlı olmaz.
- Temel model (baseline)
  - Makaledeki yöntem (ör. U-Net) önce temel olarak çalıştırılır, amaç onu geçmektir.
- Yamalarla veri üretme
  - Büyük görüntüde çekirdek merkezleri biliniyorsa merkez çevresinden alınan sabit boyutlu yamalar hem örnek sayısını artırır hem sınıflandırmayı kolaylaştırır.

## Kısa Tekrar Notları

- Anlamsal bölütleme için görüntü-etiket çiftleri gerekir; etiket yoksa transfer öğrenme ya da eğiticisiz bölütleme.
- Eğiticisiz bölütleme: K-means, GMM, fuzzy c-means, eğiticisiz derin ağlar.
- Bölütleme ağları: U-Net, SegNet, FCN, Mask R-CNN, DeepLab v3/v3+, piramit ve dikkat yapıları.
- Bölütleme metrikleri: Dice (F1) ve IoU.
- Dengeli veri seti: sınıf başına örnek sayısı eşit.
- Veri artırma: döndürme (dört yön + köşegen) ile veri yaklaşık beş katı.
- Büyük görüntüden yama çıkarma örnek sayısını artırır.
- Topluluk öğrenme: eğitim verisini, modeli ya da ikisini çeşitlendirme; bootstrap, yatay oylama, model ortalaması.
- MR'da kesit bazında mı hacimsel mi değerlendirme yapıldığına bakılmalı.
- Büyük veri: normalize et, HDF5 olarak sakla; Kaggle GPU ortamı bir seçenek.
- Papers with Code: veri setine göre yöntem, sonuç ve kodlar.

## Detaylı Açıklamalar

- Etiketsiz kan yayması görüntüsünde bölütleme
  - Bir öğrenci, eozinofil gibi beyaz kan hücresi tiplerini sınıflandırmayı amaçlayan projesinde önce hücreleri bölütlemek istiyordu. Derin öğrenmeyle anlamsal bölütleme görüntü ve aynı boyutta piksel etiketlerinden oluşan bir eğitim kümesi ister. Seçtiği veri setinde etiket dosyası olmadığı için bölge tabanlı bir yöntemle ön bölütleme yapmış, ardından histogramı üç kutuya ayırarak (ekrandan, 00:10:00) her pikseli beyaz kan hücresi, kırmızı kan hücresi ya da arka plan diye etiketlemiş ve hatalı bölgeleri elle düzeltmişti.
  - Hoca bu yöntemin mantıklı ama kalitesinin belirsiz olduğunu söyledi. Etiketli MoNuSeg veri setinde (eğitim verisinde "Annotations" ve "Tissue Images" klasörleri, ekrandan, 00:15:00) hücre ile arka planı ayıran bir ağ eğitilip öğrencinin kendi verisine uygulanabilir. Alternatif olarak hiç etiket gerektirmeyen K-means, Gauss karışım modelleri, fuzzy c-means ya da eğiticisiz derin öğrenme ağları denenebilir. Sonuçlar birbirleriyle karşılaştırılabilir.
- Topluluk öğrenme ile deri lezyonu sınıflandırma
  - ISIC yarışma veri setlerinin farklı yılları farklı büyüklükte ve etiket yapısındadır: öğrenciye göre 2018'de yaklaşık 10 bin, 2019'da yaklaşık 25 bin görüntü vardır ve sınıf etiketleri bulunur; 2020'de yaklaşık 33 bin görüntü olsa da 7 sınıf ayrıntılı etiketlenmemiş, çoğunlukla iyi huylu/kötü huylu ayrımı vardır. Bu yüzden 2019 setinin kullanılması kararlaştırılmıştı.
  - InceptionV3 ile transfer öğrenmede eğitim kaybı ilk epokta yaklaşık 3'ten hızla düşüp 9. epokta 0,8 civarına, doğrulama kaybı 0,6 civarına inmişti (ekrandan, 00:25:00).
  - Hoca sonraki adım olarak topluluk öğrenmeyi önerdi ve derin öğrenme için topluluk yöntemlerini eğitim verisini değiştiren (bootstrap gibi), modeli değiştiren ve birleşim yöntemlerini değiştiren gruplar hâlinde özetleyen bir kaynağı gösterdi. Bunlardan birkaçını aynı veri setinde karşılaştırmalı uygulamak çalışmayı bildiri düzeyinin üstüne, dergi düzeyine taşıyabilir.
- Kolorektal kanser derecelendirme
  - Genişletilmiş CRC veri setinin README dosyasına göre (ekrandan, 00:35:00) görüntüler 4548×7548 ve 5000×7300 piksel boyutunda, 20× büyütmede, örtüşmeyen görüntülerdir. Her biri uzman patologlarca normal doku (Grade1), düşük dereceli (Grade2) ya da yüksek dereceli (Grade3) tümör olarak etiketlenmiştir. Toplam 300 görüntü vardır: 120 normal, 120 düşük, 60 yüksek dereceli. Öğrenci arşivi açtığında bazı dosyaların bozuk olduğunu ve daha az görüntü elde ettiğini söyledi. <!-- BELİRSİZ: öğrencinin bozuk dosyalar çıkarıldıktan sonra okuduğu sınıf sayıları altyazıda karışık (171, 53, 88 gibi), kesin dağılım çıkarılamadı. -->
  - Hoca sınıf sayıları arasındaki farkın büyük olmadığını (10'a 100 gibi bir fark olsaydı dengesiz sayılacağını) söyledi. Veri artırma ve büyük görüntülerden küçük yamalar çıkarma ile örnek sayısı artırılabilir; ekrandaki makalede (IEEE TMI, 2020) görüntüler 224×224 yamalara bölünüp bağlam (context) bilgisiyle derecelendirme yapılıyordu (ekrandan, 00:40:00). Ayrıca eski CRC veri seti genişletilmiş setle birleştirilebilir.
- Beyin tümörü bölütleme
  - BraTS 2020'nin yalnız eğitim setinde maske olduğu için 369 örnek %66 eğitim (243) ve doğrulama (126) olarak ayrıldı; genelleme için TCIA'daki başka bir MR veri setinde test planlandı (ekrandan, 00:50:00). Ekrandaki LGG slaytına göre bu veri setinde 110 hastanın MR görüntüsü vardır, her hastada 40-70 arası MR-maske kesit çifti bulunur; görüntüler TCIA'nın FLAIR görüntüleridir (ekrandan, 00:45:00).
  - Bir öğrenci kesitleri renk haritasıyla gösterince tümörlü bölgenin belirginleştiğini fark etmişti. Hoca bunun nicemleme etkisi olduğunu açıkladı: renk geçişleri tam yapılamaz, değerler bir üst ya da alt seviyeye atanır ve bu bölütleme gibi görünür. Öneri: hem bu hâli hem özgün görüntüyü ağa verip metriklerle karşılaştırmak.
  - Bir başka öğrenci, iki bölge arasındaki değişimi türevle bulup önce kenarı çizen, sonra bölütleyen bir yöntem düşünüyordu. Hoca önce alandaki son çalışmalara ve kullandıkları metriklere (Dice, IoU) bakılmasını, bölütleme taramasındaki modellerin (DeepLab ailesi, dikkat ağları, piramit yapıları, çekişmeli eğitim) iki öğrenci arasında paylaştırılmasını önerdi. Bölütleme sonrası tümör hacmini milimetreküp olarak raporlama fikri için hoca, piksel sayısı ve piksel başına düşen alandan bu raporun çıkarılabileceğini, ama önce bölütlemenin yapılması gerektiğini söyledi.
- Servikal sitoloji veri setlerinde yama tabanlı sınıflandırma
  - Cervix93'te her yığın farklı odak kesitlerinden oluşur ve kesitler birleştirilerek odak derinliği genişletilmiş tek bir görüntü (EDF) elde edilmiştir; çekirdek merkezlerinin koordinatları ayrı dosyalarda verilmiştir (bir örnekte 28 çekirdek). Hoca tahtada (ekrandan, 01:35:00) bir sınıfa ait görüntüde her çekirdek merkezinin çevresinden 512×512 yama alınmasını gösterdi: çizimdeki örnekte bir görüntüden 7 yama çıkıyor ve hepsi 1 numaralı sınıfa atanıyor. Aynı işlem 2. ve 3. sınıf için yapılır, döndürme ile veri artırılır, sonra önce ön eğitimsiz CNN, ardından transfer öğrenme denenir.
  - İleri aşamada her yığından en az ortak kesit sayısı (ör. 10) alınarak $M\times N\times 10$ boyutlu çok kanallı girdi oluşturulabilir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
