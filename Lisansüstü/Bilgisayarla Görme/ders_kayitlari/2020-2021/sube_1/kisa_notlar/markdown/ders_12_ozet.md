# Ders 12 Çalışma Özeti

## Genel Konular

- Dersin yapısı
  - Bu ders öğrencilerin makale inceleme ve proje sunumlarından oluştu. Yedi sunum yapıldı; hoca her sunumdan sonra sorular sordu ve yorum yaptı. Sunanlar notta "bir öğrenci" diye anılır.
- Görsellerden mobilya stili eşleştirme (VGG16 ile)
  - İncelenen makale, etkileşimli 3B sahne modellemesi için görsellerden mobilya stili eşleştiren bir sistem öneriyor. Müşteri katalogdan seçim yapıyor, sistem bu seçimlerle uyumlu mobilyaları öneriyor ve sonucu 3B sahne olarak gösteriyor (ekrandan, 00:05:00).
  - Altyapı: Keras'taki VGG16 mimarisinin son iki katmanı değiştirilmiş. Veri %80 eğitim, %10 doğrulama, %10 test olarak bölünmüş, yaklaşık 670 bin görselle çalışılmış.
  - Ticari uygulamalar daha çok geometriye (köşe bulma gibi) dayanıyor. Bu çalışma kumaş, renk ve tarz gibi özellikleri de kullanıyor. Uzmanların farklı zevklerini yönetmek için 0-1 etiket yerine puanlamaya dayanan "karşılaştırma etiketi" kullanılmış.
  - Öğrencinin kendi denemesi: yatak, sandalye, koltuk, döner sandalye ve masadan 100'er görsel (toplam 500), VGG16 ile özellik çıkarımı, ardından K-means ile 5 küme. Masa ve döner sandalye kümeleri temiz çıktı. Döner sandalyeler iki kümeye bölündü, yatak ile koltuk ise aynı kümede yarı yarıya karıştı (ekrandan, 00:10:00).
- Eski fotoğrafların renklendirilmesi (DeOldify, GAN ve NoGAN)
  - GAN iki ağdan oluşur: üretici (generator) ve ayırt edici (discriminator). Bu bir sıfır toplamlı oyundur; biri kazandığında diğeri kaybeder. Sezgi için kalpazan ile polis benzetmesi kullanıldı.
  - NoGAN: üretici önce sıradan bir derin ağ gibi tek başına eğitilir, sonra kısa bir GAN eğitimi yapılır. Böylece eğitim kısalır ve yapay bozulmalar (artefaktlar) azalır. Eğitimde örneklere rastgele Gauss gürültüsü eklenir, model gürültülü girdilere karşı daha dayanıklı olur (ekrandan, 00:20:00).
  - Başarım ölçümü: 50 renkli resim griye çevrilip yeniden renklendirildi. Piksel farklarının toplamı piksel sayısına bölünerek benzerlik hesaplandı. Rengi tam tutturma oranı yaklaşık binde 5, genel benzerlik yaklaşık %70-72 çıktı.
- Makine görmesiyle papaya hastalığı tanıma
  - Mobil cihazla çekilen görüntü sunucudaki uzman sisteme gönderilir, sonuç kullanıcıya geri bildirilir (ekrandan, 00:30:00).
  - İşlem hattı: bikübik interpolasyonla 300×300'e boyutlandırma, histogram eşitleme ile kontrast artırma, RGB'den L\*a\*b\* renk uzayına dönüşüm, k-means ile hastalıklı bölgenin ayrılması, istatistiksel ve GLCM özellikleri, SVM ile sınıflandırma.
  - Özellikler: ortalama, standart sapma, varyans, basıklık ve çarpıklık (istatistiksel); kontrast, korelasyon, enerji, entropi ve homojenlik (gri seviye eş oluşum matrisi, GLCM). Toplam 10 özellik.
  - Veri: 129 görüntü (84 eğitim, 45 test). Doğruluk %95,2, duyarlılık %85,6, özgüllük %97,12. SVM, karar ağacı ve naive Bayes'ten iyi çıktı.
- GAN ile sentetik tıbbi imge çoğaltma (karaciğer lezyonları)
  - Makale: "GAN-based synthetic medical image augmentation for increased CNN performance in liver lesion classification". BT'den 182 lezyon imgesi kullanılmış: 53 kist, 64 metastaz, 65 hemanjiyom (ekrandan, 01:00:00).
  - Sınıflandırıcı CNN: 64×64 girdi, 3×3 filtreli 32, 64 ve 128 kanallı üç evrişim katmanı ve alt örnekleme, 256'lık tam bağlı katman, 0,5 dropout, 3 sınıflı softmax. Eğitimde batch 64, öğrenme oranı 0,001, 150 epoch ve Nesterov momentumlu SGD kullanılmış (ekrandan, 01:05:00).
  - Klasik çoğaltma: döndürme, çevirme, öteleme ve ölçekleme. Her imgeden yaklaşık 480 yeni imge üretilmiş.
  - DCGAN: üretici 100 boyutlu rastgele vektörden 64×64 imge üretir. Ayırt edicide 5×5 çekirdekli 4 evrişim katmanı var; havuzlama yerine adımlı evrişim (strided convolution) kullanılmış. Çıkışta sigmoid, diğer katmanlarda Leaky ReLU ($f(x)=\max(x,\,0{,}2x)$) var (ekrandan, 01:10:00). Bir diğer model AC-GAN, sınıf etiketi de üretiyor.
  - Sonuç: yalnız klasik çoğaltmada doğruluk yaklaşık %78,6'da doyuma ulaşıyor. Bu noktadan sonra DCGAN imgeleri eklenince yaklaşık %85,7'ye çıkıyor. 78 ek gerçek imge ise yalnız yaklaşık %2 kazandırıyor (ekrandan, 01:15:00).
- Yüz yaşlandırma: GAN türleri, Conditional GAN ve CycleGAN
  - GAN çeşitleri: WGAN, LSGAN, DCGAN, Progressive Growing GAN, Conditional GAN, AC-GAN, CycleGAN.
  - GAN eğitimindeki iki büyük sorun: mode collapse (üretici tek tip veri üretir) ve convergence failure (üretici öğrenemez, gürültü üretir). Karşılaştırmalı bir çalışmaya göre iyi hiperparametre optimizasyonu, hangi GAN türü kullanılırsa kullanılsın benzer sonuç veriyor (ekrandan, 01:30:00).
  - Face Aging cGAN: üretici gürültü yerine otokodlayıcıdan gelen gizil (latent) vektörü alır, koşul olarak yaş grubu verilir. Kimliği korumak için piksel farkı yerine yüz tanıma ağının gömme (embedding) vektörleri karşılaştırılır (Identity Preservation Optimization) (ekrandan, 01:35:00).
  - CycleGAN: eşleşmemiş (unpaired) imgeden imgeye çeviri yapar. İki üretici ve iki ayırt edici kullanır. Kayıplar: çekişmeli kayıp, döngü tutarlılığı kaybı (A→B→A sonucu orijinale yakın olmalı) ve özdeşlik kaybı. Ayırt edici olarak PatchGAN kullanılır, üreticide ResNet blokları vardır (ekrandan, 01:40:00).
  - Uygulama: UTK Face ile Flickr Faces HQ birleştirildi, resimler 128×128'e getirildi. 20-30 yaş "genç" (yaklaşık 25 bin), 50 yaş üstü "yaşlı" (yaklaşık 13 bin) sayıldı (ekrandan, 01:45:00). Veri dengesizliği yüzünden cinsiyet ve ten rengine bağlı hatalar görüldü.
- Video izleme ile çelik köprülerde yorgunluk çatlağı tespiti
  - Klasik yöntemler (gözle denetim, akustik emisyon, piezoelektrik sensörler) emek ve zaman ister. Canny/Sobel kenar bulma ve sayısal imge korelasyonu (DIC) alternatifleri var, ancak DIC pahalı ekipman gerektiriyor (ekrandan, 02:05:00).
  - Önerilen hat üç adımlıdır: ilgi noktası tespiti (Shi-Tomasi), noktaların KLT ile izlenmesi, çatlağın yerelleştirilmesi.
  - Shi-Tomasi: Harris'teki ikinci moment matrisi $M$ hesaplanır, ancak köşe ölçütü $R=\min(\lambda_1,\lambda_2)$ olur. Eşik $q\times R_{\max}$'tır. OpenCV'de `cv2.goodFeaturesToTrack()` ile kullanılır (ekrandan, 02:10:00).
  - KLT algoritması: $\min(\lambda_1,\lambda_2)>\lambda$ olan köşeleri bul, her köşenin sonraki kareye yer değiştirmesini Lucas-Kanade ile hesapla, kaydet, konumu güncelle, gerekirse her M karede yeni köşe ekle (ekrandan, 02:15:00).
  - Çatlak yerelleştirme: her noktanın göreli yer değiştirmesi $\delta^i(t)=\sqrt{x_r^i(t)^2+y_r^i(t)^2}$ ile hesaplanır. Dairesel komşuluk (LCR) içinde merkez noktaya göre farkların standart sapmaları alınır ve değişim katsayısı (CV) bulunur. $CV>\Gamma$ olan noktalar çatlak çevresi sayılır (ekrandan, 02:20:00).
- TRUBA ile derin öğrenme
  - TRUBA, TÜBİTAK'ın yüksek başarımlı hesaplama altyapısıdır. Web arayüzünde Files, Jobs, Clusters, Interactive Apps (Jupyter Notebook, MATLAB, RStudio vb.), Non-Interactive Apps ve My Interactive Sessions menüleri var (ekrandan, 02:35:00).
  - Örnek uygulama: 7 sınıflı ve yaklaşık 500 imgelik bir veri seti, veri çoğaltma, Keras CNN (evrişim, dropout, max pooling, dense; ReLU ve softmax), RMSprop, `categorical_crossentropy`, 100 epoch, doğrulama doğruluğu 0,7'yi geçince eğitimi durduran bir callback (ekrandan, 02:40:00).

## Hocanın Özellikle Vurguladığı Kısımlar

- Renklendirmede bilgi kaybı
  - Renkli resim griye çevrilince bilgi kaybolur. Farklı renkler aynı gri değere düşebilir, bu yüzden orijinal rengi kesin bulmak esasen mümkün değildir. Buna karşın problemin veri setini hazırlamak kolaydır: renkli resimler griye çevrilip eğitim çifti yapılabilir. Hoca griye çevirmenin de farklı yöntemleri olduğunu hatırlattı.
- GAN ile çoğaltmada "tavuk-yumurta" sorunu
  - Nihai amaç sınıflandırmadır, ancak eğitim verisi üretmek için de bir öğrenen model kullanılıyor. GAN zaten klasik yöntemle çoğaltılmış veriyle eğitildiği için klasik yöntemle yapılan karşılaştırma tam adil görünmüyor.
- Alan bilgisi
  - Üretilen tıbbi imgelerin anlamlı olup olmadığını değerlendirmek için o tıbbi alanı ve veri setini bilmek gerekir.
- Shi-Tomasi ile Harris farkı
  - Harris'te determinant ve iz (trace) hesaplamayı hızlandırmak için kullanılır. Shi-Tomasi doğrudan özdeğerleri kullanır.
- Veri setinin önceden sınıflandırılması
  - Yüz yaşlandırmada cinsiyet ve ten rengi gibi temel özellikleri önceden ayıran bir sınıflayıcı eklemek, benzer yüzleri gruplayıp eğitimi bunun üzerine kurmak sonuçları büyük olasılıkla çok iyileştirir.
- İzleme (tracking)
  - Video üzerinde nokta ve nesne izleme, optik akış ve KLT bilgisayarla görmenin önemli konularıdır. Bu sunum konuya kısa bir giriş oldu.

## Kısa Tekrar Notları

- GAN = üretici + ayırt edici, sıfır toplamlı oyun. Eğitim kararsızdır: mode collapse ve convergence failure.
- NoGAN: önce üreticiyi tek başına eğit, sonra kısa GAN eğitimi yap. Daha az artefakt çıkar.
- Gri resimden renk: kayıplı dönüşüm, tek doğru cevap yok.
- Papaya: bikübik boyutlandırma, histogram eşitleme, L\*a\*b\*, k-means segmentasyon, 5 istatistik + 5 GLCM özelliği, SVM.
- Karaciğer lezyonu: klasik çoğaltma yaklaşık %78,6'da doyuyor, DCGAN eklenince yaklaşık %85,7'ye çıkıyor.
- DCGAN ayırt edicisi: havuzlama yerine adımlı evrişim, Leaky ReLU (eğim 0,2), çıkışta sigmoid.
- CycleGAN: eşleşmemiş veri, döngü tutarlılığı ve özdeşlik kaybı, PatchGAN ayırt edici, ResNet bloklu üretici. Yalnız iki alan arasında birebir eşleme yapar.
- Shi-Tomasi: $R=\min(\lambda_1,\lambda_2)$; OpenCV `goodFeaturesToTrack`.
- KLT: köşe bul, Lucas-Kanade ile yer değiştirmeyi hesapla, güncelle, tekrarla. Ölçek değişimi için alt örneklenmiş seviyelerde de aranır.
- Çatlak: komşu noktalarla hareket farkı → standart sapma → değişim katsayısı → eşik.

## Detaylı Açıklamalar

- Mobilya stili çalışması, önceden eğitilmiş bir CNN'in (VGG16) özellik çıkarıcı olarak kullanılabileceğini gösterdi. Öğrencinin denemesinde etiket kullanılmadan, yalnız VGG16 özellikleri üzerinde K-means ile beş küme bulundu. Masalar ve döner sandalyeler iyi ayrıldı. Yatak ile koltuk ise malzeme ve doku benzerliği yüzünden karıştı. Hoca makalenin üretici bir ağ (GAN) kullanıp kullanmadığını sordu. Öğrenci makalenin hazır VGG16 mimarisine dayandığını söyledi.
- DeOldify renklendirme projesinde başarım, 50 resimde orijinal renkli resim ile yeniden renklendirilmiş resim arasındaki piksel farklarıyla ölçüldü. Piksel düzeyinde tam isabet çok düşük çıktı (binde 5), ancak genel ton benzerliği yaklaşık %70 oldu. Golden Gate Köprüsü'nün inşaat dönemi fotoğrafında model kuleleri kırmızı yerine açık renkte boyadı (ekrandan, 00:25:00). Hoca bunu bilgi kaybıyla açıkladı: gri tonda aynı değere düşen farklı renkleri model ayırt edemez.
- Papaya çalışmasında k-means segmentasyonu, elle işaretlenmiş referans bölgelerle karşılaştırıldı (ekrandan, 00:35:00). Kahverengi lekede (brown spot) tahmin edilen bölge referansın %159,33'ü (+%59,33), siyah lekede %89,76'sı (-%10,24) oldu.
  - Ders sonrası not: Sunumda %59'luk sapma Phytophthora yanıklığına atfedildi. Tablodaki +%59,33 brown spot satırına aittir; Phytophthora yanıklığında sapma +%9,11'dir.
- Karaciğer lezyonu makalesinde GAN, az olan veriyi çeşitlendirmek için kullanıldı. GAN'ın eğitilebilmesi için veri önce klasik yöntemle çoğaltıldı. Klasik çoğaltmanın doyduğu "optimal nokta"dan sonra GAN imgeleri eklendi. Ek gerçek veriyle elde edilen küçük kazanç, GAN'ın çeşitliliğe daha çok katkı sağladığı şeklinde yorumlandı. Hoca, sınıflandırıcıyı eğitmek için öğrenen bir üretici kullanılmasını "tavuk-yumurta" problemi olarak sorguladı.
- CycleGAN'da döngü tutarlılığı fikri çeviri benzetmesiyle anlatıldı: İngilizce bir metin Türkçeye, sonra yeniden İngilizceye çevrilir ve orijinalle karşılaştırılır. PatchGAN ayırt edicisi tek bir değer yerine bir matris verir. Matrisin her elemanı girdinin yaklaşık 70×70'lik bir bölgesinin gerçek olup olmadığına karar verir. Resim gerçekte parçalara bölünmez.
- Çatlak tespitinde temel fikir şudur: sağlam bir parçada komşu ilgi noktaları değişken yük altında aynı biçimde hareket eder. Çatlağın iki yakasındaki noktalar ise birbirinden az da olsa farklı salınır. Hoca bu yaklaşımın nasıl çalıştığını sorguladı. Öğrenci kağıt ile arka plan üzerindeki noktaların farklı hareket ettiği bir canlı demo ile açıkladı (OpenCV, 10 ilgi noktası, kaybolan noktaların yerine yeniden tespit).
- TRUBA sunumunda sistemin ücretsiz olduğu ve veriyi kalıcı tutabildiği belirtildi. Dezavantajları kararsız çalışması ve sınırlı dokümantasyonuydu. Sunulan 7 sınıflı CNN modeli az veri ve sınıflar arası benzerlik yüzünden düşük başarım verdi.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
