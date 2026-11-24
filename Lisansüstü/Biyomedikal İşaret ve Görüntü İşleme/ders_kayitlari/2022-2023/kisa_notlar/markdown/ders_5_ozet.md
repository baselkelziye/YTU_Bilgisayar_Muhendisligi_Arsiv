# Ders 5 Çalışma Özeti

## Genel Konular

- Dersin biçimi: proje ilerleme görüşmeleri
  - Bu kayıtta konu anlatımı yoktur. Öğrenciler sırayla ekranlarını paylaşıp tıbbi görüntü projelerinde (COVID görüntüleri, hücre görüntüleri, çekirdek segmentasyonu, servikal sitoloji, meme kanseri histopatolojisi, karın BT organ segmentasyonu) geldikleri noktayı anlattı; hoca her projeye yöntemsel yön verdi.
- Grafik evrişim ağlarında (GCN) komşuluk matrisi
  - Bir öğrenci, çok etiketli görüntü tanıma için GCN kullanan bir CVPR 2019 çalışmasının (Multi-Label Image Recognition with Graph Convolutional Networks) kodunu kendi 4 sınıflı COVID problemine uyarlıyordu (ekrandan, 00:05:00).
  - Kodda komşuluk (adjacency) matrisi dışarıdan bir pickle dosyasıyla yükleniyor; COCO'nun 80 sınıfı için 80x80'lik bir matris. Matrisi üreten fonksiyon sınıf sayısını, bir eşik değerini (`t`) ve bu dosyayı alıyor.
  - Aynı dosyada her sınıf için bir sayı listesi de var (80 satır; örneğin 14. satırda 5968) (ekrandan, 00:10:00). Hoca bunun sınıflardaki örnek sayısıyla ilişkili olabileceğini, kontrol edilmesi gerektiğini söyledi.
  - Hocanın önerileri: matrisi Python ya da MATLAB'da görüntü gibi iki boyutlu çizdirip yapısına bakmak; makalede değerlerin nasıl elde edildiğini okumak; 4 sınıf için 4x4 matrisi rastgele başlatıp denemek; kümeleme yapıp sınıf merkezlerinin birbirine uzaklığından matris kurmak; matrisi iteratif olarak iyileştirmeyi araştırmak; sağlıklı sınıf dışındaki hastalık sınıfları arasındaki ilişkiyi kullanmak.
  - Hoca, matrisin probleme göre yeniden tasarlanmasının çalışmanın yeniliği olabileceğini belirtti.
- Hücre görüntülerinde yamalarla sınıflandırma
  - Bir öğrenci, yüzlerce hücre içeren görüntüleri yamalara (patch) bölüp sabit boyutlu yeni görüntüler oluşturdu ve bunları bir CNN'e vermeyi planladı.
  - Hoca sıfırdan CNN yerine standart transfer öğrenme modellerini (Inception, EfficientNet, ResNet, DenseNet) önerdi; ardından yarı gözetimli (semi-supervised) yönteme geçilmesi gerekiyor.
- Öz-gözetimli öğrenmeye geçmeden önce taban kurmak
  - Öz-gözetimli (self-supervised) yöntemi ağır bulan bir öğrenciye hoca önce transfer öğrenmeyle veri setinde hangi sınıflandırma başarısının elde edildiğini ölçmesini, veri setini (sınıf sayısı, yapısı) tanıtmasını söyledi. Gidişat bu tabana göre yeniden belirlenecek.
- Çekirdek segmentasyonu ve GPU bellek hatası
  - Bir öğrenci çekirdek (nucleus) segmentasyonu için PSPNet dahil altı segmentasyon modelini tanımlayıp sırayla eğitiyordu. Ekrandaki kodda Adam (`lr=1e-4`), `BCEWithLogitsLoss`, eğitim/test Dice geçmişi, `epochs = 20`, `batch_size = 32` kullanılıyor (ekrandan, 00:20:00).
  - 4 GB GPU belleğinde "CUDA out of memory" hatası alındı. Öneriler: batch boyutunu düşürmek, işlenen eski görüntüleri bellekten atmak (bellek yönetimi), arka planda belleği tutan nesneleri temizlemek, Google Colab ya da Kaggle not defterine taşımak, gerekirse eğitim verisini küçültmek, hatayı aratıp benzer sorunların çözümlerine bakmak.
- Servikal sitoloji: derin özellik + makine öğrenmesi
  - Bir öğrenci SIPaKMeD servikal hücre veri setinde, derin özellikleri birleştiren bir çalışmayı (Cervical Net: feature fusion) temel aldı (ekrandan, 00:35:00).
  - Akış: ön işlem olarak filtreleme, Keras'taki önceden eğitilmiş modellerden seçim, derin özellik çıkarımı, ölçekleme, PCA, makine öğrenmesi sınıflandırıcıları ve hiperparametre iyileştirme. Ekranda KNN, CART, RF ve XGBoost için en iyi parametreler ile yumuşak oylamalı (soft voting) bir topluluk sınıflandırıcısı görünüyor (ekrandan, 00:25:00).
- Meme kanseri histopatolojisi: transfer öğrenme ve derin topluluk
  - Bir öğrenci 7 sınıflı bir meme kanseri veri setinde VGG, ResNet ve Inception ile transfer öğrenme denedi; ekrandaki kod VGG19'u `include_top=True`, `input_shape=(224,224,3)` ile yükleyip katmanları eğitilebilir yapıyor, 11. katman çıkışına Flatten ve 100 nöronlu Dense ekliyor (ekrandan, 00:30:00).
  - Colab'de eğitim çok yavaştı. Görüntüleri Drive'a tek tek değil zip olarak yükleyip Colab'in yerel diskine açmak hızlandırır; çalışma zamanının GPU'ya alınması da kontrol edilmeli.
  - Hoca, sınıflandırma sonuçlarını birleştiren derin topluluk (deep ensemble) yaklaşımları için anlatım sitelerine bakmayı önerdi.
- Dört sınıflı histopatoloji (ICIAR 2018 BACH) sınıflandırması
  - Hocanın önerileri: veri az olduğu için mutlaka veri artırma (data augmentation); %10 doğrulama ayırmak yerine k-katlı çapraz doğrulama ($k=5$); başarım ölçütleri olarak accuracy, precision, recall ve F1; modeller olarak Inception, EfficientNet, DenseNet, ResNet.
  - Öğrencinin slaytında ölçütler (accuracy, sensitivity, specificity, precision, recall, f-measure, g-mean, AUC) ve modeller (Inception, ShuffleNet, Xception, GoogLeNet) listeleniyor (ekrandan, 00:40:00).
- Çok organlı bölütleme, son işleme ve SinGAN-Seg
  - Bir öğrenci karın BT görüntülerinde TransUNet ile organ bölütlemesi yapıyordu. Önceki denemede model tek organ buluyordu; epoch sayısı 100'e çıkarılıp batch boyutu değiştirilince ve görüntü boyutu büyütülünce farklı organları da bulmaya başladı (ekrandan, 00:45:00).
  - Hoca güncel bölütleme ağlarıyla (UNet++, UNet 3+, Swin-UNet) devam etmeyi, ardından son işleme (post-processing) olarak Markov Random Field uygulamayı önerdi.
  - SinGAN-Seg tek bir görüntüden maskeleriyle birlikte sentetik görüntüler üretiyor (ekrandaki örnek polip görüntüleri) (ekrandan, 00:50:00). Hoca GAN tarafını ikinci plan olarak bıraktı; tek görüntü yerine birden fazla görüntü alabilen GAN yapılarına bakılabileceğini söyledi.

## Hocanın Özellikle Vurguladığı Kısımlar

- Hazır kodu anlamadan uyarlamamak
  - Dışarıdan yüklenen bir matrisin (örneğin GCN komşuluk matrisi) ne anlama geldiği, kod debug edilerek o noktaya kadar çalıştırılıp çizdirilerek anlaşılmalıdır. Kendi problemine göre yeniden kurulması çalışmanın katkısı olabilir.
- Önce taban, sonra yenilik
  - Yeni bir yönteme (öz-gözetimli, yarı gözetimli, topluluk) geçmeden önce standart transfer öğrenme modelleriyle başarı ölçülmelidir.
- Doğru değerlendirme
  - Az veride veri artırma ve k-katlı çapraz doğrulama şarttır; sabit küçük bir doğrulama ayrımı yeterli değildir.
- Hatalar projenin doğası
  - Bellek hataları ve yavaşlık gibi sorunlar bu tür projelerin doğal parçasıdır; hata mesajı aratılarak, batch boyutu düşürülerek ve bulut ortamına taşınarak çözülür.
- Bölütlemede son işleme
  - Bölütleme sonucu ground truth'a tam benzemiyorsa, Markov Random Field gibi orijinal görüntüyü de kullanan bir son işlemle delikler ve tutarsız bölgeler düzeltilebilir.

## Kısa Tekrar Notları

- ML-GCN kodunda komşuluk matrisi pickle dosyasından gelir; COCO için 80x80'dir, kendi problemi için $C \times C$ (burada 4x4) kurulmalıdır.
- Komşuluk matrisi kurma fikirleri: rastgele başlatma, sınıf merkezleri arası uzaklık, iteratif iyileştirme, sınıflar arası birlikte görülme.
- Transfer öğrenme taban modelleri: Inception, EfficientNet, ResNet, DenseNet (ayrıca VGG, Xception, ShuffleNet, GoogLeNet).
- CUDA out of memory: batch boyutunu düşür, belleği temizle, Colab ya da Kaggle'a taşı.
- Colab'de veri: Drive'a zip yükle, Colab'in yerel diskine aç; çalışma zamanı GPU olsun.
- Servikal sitoloji akışı: filtre, derin özellik, ölçekleme, PCA, ML sınıflandırıcı, hiperparametre iyileştirme, oylama.
- Az veride: veri artırma + 5 katlı çapraz doğrulama; ölçütler accuracy, precision, recall, F1.
- Organ bölütleme: TransUNet, UNet++, UNet 3+, Swin-UNet; son işleme olarak MRF.
- SinGAN-Seg: tek görüntüden maske ile birlikte sentetik eğitim verisi.

## Detaylı Açıklamalar

- **GCN komşuluk matrisi.** Çok etiketli tanımada GCN, etiketleri düğüm kabul eden bir grafikte bilgi yayar. Grafiğin kenarları komşuluk matrisinde tutulur. İncelenen kodda bu matris önceden hesaplanıp pickle dosyasına kaydedilmişti; ayrıca her sınıfın kaç kez geçtiğini gösteren bir sayı listesi vardı. Hoca, bu sayıların sınıf dağılımıyla uyuşup uyuşmadığına bakılmasını, matrisin satırlarının çizdirilip her satırda en büyük değerin nerede olduğunun ve diğer sınıflara küçük bağlantıların incelenmesini istedi. Kendi dört sınıflı problemi için matris rastgele başlatılabilir, kümeleme ile sınıf merkezlerinin uzaklıklarından ya da bir ön sınıflandırıcının çıktılarından kurulabilir.
  <!-- BELİRSİZ: Altyazıda "bir ön sınıflandırıcıya verip" sözü yarım kalıyor; önerinin ayrıntısı anlaşılmıyor. -->
- **GPU belleği.** 4 GB GPU belleği, 32'lik batch ile segmentasyon modelleri için yetmeyebilir. Batch boyutu düşürülür, kullanılmayan tensörler bellekten çıkarılır; Colab'de yaklaşık 12 GB GPU belleği vardır, ama batch büyütülünce orada da aynı hata alınabilir.
- **Servikal sitoloji akışı.** Önceden eğitilmiş ağlardan çıkarılan derin özellikler ölçeklenir, PCA ile boyutu düşürülür ve klasik sınıflandırıcılara verilir. Sınıflandırıcıların parametreleri ızgara araması gibi bir yöntemle iyileştirilir, sonra en iyi modeller yumuşak oylamayla birleştirilir. Öğrenci ileride farklı derin modellerin özelliklerini birleştirip kendi modelini kurmayı planlıyor.
- **Değerlendirme.** Veri az olduğunda tek bir eğitim/test ayrımı yanıltıcıdır. K-katlı çapraz doğrulamada veri $k$ parçaya bölünür, her parça bir kez test olur ve sonuçların ortalaması alınır. Hoca $k=5$ seçilmesini önerdi.
- **Son işleme.** Markov Random Field, bölütleme haritasını orijinal görüntüyle birlikte kullanarak komşu piksellerin etiketlerini tutarlı hale getirir; örneğin bir organın içindeki deliği, çevresi aynı organa ait olduğu için kapatabilir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
