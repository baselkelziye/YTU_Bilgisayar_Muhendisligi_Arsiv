# Ders 8 Çalışma Özeti

## Genel Konular

- Dersin biçimi: dönem sonu öğrenci proje sunumları
  - Bu derste öğrenciler dönem projelerini sundu, hoca her sunumun ardından yöntem ve değerlendirme hatalarını tartıştı. Notta sunumların teknik içeriği ve hocanın akademik yorumları yer alır.
- Dengesiz veride sınıflandırma: kredi kartı dolandırıcılık tespiti (MLP)
  - Yaklaşık 283 bin işlemden yalnız 473'ü dolandırıcılık. Özellikler korelasyon ve bilgi kazancı (information gain) ile incelendi, normalize edildi, veri tabakalı örneklemeyle (stratified sampling) eğitim, doğrulama ve test kümelerine ayrıldı.
  - Tam bağlantılı MLP: 30 girdi, 3 gizli katman, sigmoid çıkış. Gizli katman sayısı ve nöron sayıları ızgara benzeri denemeyle, ağırlık ilklendirme (standard, Kaiming, He), öğrenme oranı, momentum ve weight decay tek tek seçildi. En düşük kaybı RMSProp verdi.
  - Test karışıklık matrisi (ekrandan, 00:20:00): gerçek "hayır" 56.651 doğru, 0 yanlış; gerçek "evet" 45 kaçırıldı, 50 bulundu. Doğruluk yaklaşık %99,9, dolandırıcılık sınıfının duyarlılığı (recall) yaklaşık %52,6.
- Adam'da momentum yerine beta parametreleri
  - SGD ve RMSProp momentum parametresi alır. Adam ailesi (Adam, Nadam, RAdam, AdamW) momentum almaz, momentumun etkisini beta katsayılarıyla karşılar. Aynı sayıyı (örneğin 0,9) momentum ve beta olarak vermek aynı etkiyi doğurmaz.
- Elektron mikroskobu görüntülerinde U-Net ile semantik segmentasyon
  - 465 SEM görüntüsü ve örnek bazlı (instance) etiket haritaları. Etiketler eşikleme ile ikili semantik maskeye çevrildi.
  - Yalnız eğitim kümesine veri artırma: yatay ve dikey aynalama, farklı sigmalarda Gauss filtresi, farklı boyutlarda medyan filtresi. 3260 eğitim örneği elde edildi.
  - 512x512 girdi, 4 aşağı örnekleme ve 4 yukarı örnekleme bloğu, 32x32 darboğaz (ekrandan, 00:35:00). Bloklarda konvolüsyon, normalizasyon, max pooling ve dropout; yukarı örneklemede ters konvolüsyon; ReLU ve sigmoid çıkış; Dice kaybı.
  - Adam, 10 epok, yığın boyutu 12; öğrenme oranı 0,015'ten başlayıp kayıp 2 epok iyileşmezse 0,5 ile çarpıldı; ince ayarda 0,01'den başlayıp 3 epokta 0,33 ile çarpıldı (ekrandan, 00:40:00).
- Instance ve semantik segmentasyon farkı
  - Instance segmentasyonda her nesne ayrı etiketlenir (kalabalık fotoğrafta tek tek kişileri bulmak), semantik segmentasyonda aynı sınıftaki bütün pikseller tek etiket alır (insanları bulmak).
  - Instance etiketini semantiğe çevirmek basit bir betikle yapılır. Tersi için verinin yeniden etiketlenmesi gerekir.
- Segmentasyonda başarı ölçümü
  - Piksel bazlı doğruluk, arka plan pikselleri çoğunlukta olduğu için yanıltıcı yüksek çıkar. IoU (Jaccard) ve Dice daha anlamlıdır.
  - Nesne düzeyinde değerlendirmede tahmin ile gerçek maske arasındaki örtüşme eşiği geçerse (ör. %50: mAP50; hassas işlerde %95) doğru pozitif sayılır, karışıklık matrisi buna göre kurulur.
- Mobil telefon fiyat aralığı sınıflandırması (yapay sinir ağı)
  - 2000 örnek, 20 özellik, dengeli 4 sınıf (her sınıfta 500). Standart ölçekleme, %80-%20 ayırma.
  - 7 model denendi. Bütün katmanlarda softmax kötü sonuç verdi. En iyisi 128-64-4 nöron, ReLU-ReLU-softmax, Adam, sparse categorical crossentropy, 20 epok, yığın 64: %93,50. Aynı yapıda SGD %76,75, RMSProp %93,25 (ekrandan, 01:00:00).
- SGD'nin sabit öğrenme oranlı olmak zorunda olmaması
  - SGD'ye momentum eklenebilir, öğrenme oranı zamanla düşürülebilir (scheduling). Momentum ve zamanlama yoksa SGD yerel bir noktaya takılıp kalabilir.
- Uydu görüntülerinde semantik segmentasyon
  - 72 görüntü, 6 sınıf (bina, arazi, yol, bitki örtüsü, su, etiketsiz). Veri artırma ile çoğaltıldı.
  - U-Net'in kodlayıcısı olarak önceden eğitilmiş Inception-ResNet-V2 kullanıldı. VGG16 kodlayıcı da denendi.
  - Hoca: sınıf dengesizliği görüntü sayısıyla değil piksel sayısıyla, sınıf başına piksel histogramıyla değerlendirilmeli.
- Otomatik kodlayıcı ile film öneri sistemi
  - İşbirlikçi filtreleme: kullanıcı tabanlı ve ürün tabanlı.
  - MovieLens 100K: 943 kullanıcı, 1682 film, 18 tür, 100.000 oy (1-5).
  - Her film için 18 bitlik tür vektörü kullanıcının verdiği oyla çarpılarak tür-oy matrisi $G$ kuruldu, otomatik kodlayıcıdan geçirilip $G'$ yeniden üretildi (ekrandan, 01:30:00 ve 01:35:00).
  - Hoca: otomatik kodlayıcıda kodlayıcı özellik çıkarıcıdır, darboğaz özellikleri toparlar, kod çözücü onları anlamlı çıktıya çevirir. Transformer'daki kodlayıcı-kod çözücü yapısı da bu mantıktadır.
- Bitcoin fiyat tahmininde Grid Search ve Bayes optimizasyonu
  - LSTM, dropout, GRU, dropout ve yoğun katmandan oluşan hibrit model; 1, 3 ve 5 günlük tahmin.
  - İki aşamalı arama: önce nöron sayısı, yığın boyutu, dropout; sonra öğrenme oranı ve weight decay.
  - Bayes araması: 50 kombinasyon, 3 katlı çapraz doğrulama ve 25 epok, toplam 3750 epok (ekrandan, 02:10:00). Izgara araması 6075 epok sürdü.
  - Bayes optimizasyonu üç ufukta da daha iyi sonuç verdi; ızgara aramasında 1 günlük tahminde $R^2$ negatif çıktı.
- CNN ve LSTM ile kuş sesi sınıflandırma
  - Xeno-canto platformundan kayıtlar alındı. MP3 kayıtlar WAV'a çevrildi, 3 saniyelik parçalara bölündü, RMS eşiği (15) ile sessiz parçalar atıldı, STFT ile 224x224 spektrogram üretildi.
  - İncelenen makale MobileNet kullanmıştı; renkli harita (jet) gri tonlamadan iyiydi. 10 tür ve 4314 parça ile DenseNet121 yaklaşık %90 doğruluğa ulaştı ama çok uzun eğitildi. MFCC (13 ve 20) girdili LSTM daha hızlı, ona yakın sonuç verdi.
  - Hoca: önce türden bağımsız kuş sesi tespit edilip yalnız o bölgeler etiketlenirse veri daha doğru olur. MFCC katsayıları PCA ya da LDA ile seçilmeli.
- Koşullu GAN ile tablo verisinde sentetik veri üretimi
  - Kalp hastalığı verisi (918 satır, 12 öznitelik; hedef değişken kalp hastalığı var/yok, 0 ve 1). Üretici ağa gürültüyle birlikte sınıf etiketi verilir, ayırıcı ağ gerçek ve sentetik örnekleri ayırt eder.
  - Sentetik ve gerçek birleşik veriyle SGD ve Adam farklı öğrenme oranlarında karşılaştırıldı.
  - Hoca: dengeli veriden dengesiz sentetik veri üretmek sorunludur; test kümesi yalnız orijinal veriden ayrılmalıdır.

## Hocanın Özellikle Vurguladığı Kısımlar

- Dengesiz veride doğruluk (accuracy) değil sınıf bazlı duyarlılık (recall) önemlidir
  - Çoğunluk sınıfını bilmek doğruluğu yüzde 99'un üstüne çıkarır, azınlık sınıfında başarı yarıda kalabilir.
- Dengesiz veride kayıp fonksiyonu seçimi
  - Focal loss gibi azınlık sınıfına ağırlık veren kayıplar kullanılır. Veriyi sentetik olarak dengelemek yerine kaybı ağırlıklandırmak güncel bir araştırma yönüdür.
- Segmentasyonda piksel bazlı karışıklık matrisi yanıltır
  - IoU ya da Dice'a bakılmalı. Nesne düzeyinde, örtüşme eşiğine göre doğru pozitif sayılmalı.
- Instance etiketli veri, semantik segmentasyonda da kullanılabilir; tersi yeniden etiketleme ister.
- Adam'a momentum verilmez, beta verilir; SGD sabit öğrenme oranına mahkûm değildir.
- GAN ile üretilen veri test kümesine girmemelidir
  - Kabul gören yöntem, orijinal veriyi önce eğitim ve teste ayırmak, sentetik veriyi yalnız eğitimde kullanmaktır.
- Ses verisinde önce sesin bulunduğu bölgeyi tespit edip sonra sınıflandırmak
  - Biyomedikalde önce hücreyi bulup kırpıp sonra sınıflandırmaya benzer; konuşma tespiti ile konuşanı tanıma ayrı problemlerdir.

## Kısa Tekrar Notları

- Tabakalı örnekleme, sınıf oranlarını eğitim, doğrulama ve test kümelerinde korur.
- Dengesiz veri: recall, focal loss, ağırlıklı kayıp.
- Adam ailesi: beta1, beta2; SGD ve RMSProp: momentum.
- Weight decay, ağırlıkları küçülten bir düzenlileştirmedir; öğrenme oranı zamanlaması ayrı bir yöntemdir.
- U-Net: kodlayıcı, darboğaz, kod çözücü ve atlamalı bağlantılar; segmentasyonda Dice kaybı.
- Segmentasyon ölçüleri: IoU = kesişim / birleşim; Dice; mAP50, mAP95.
- Önceden eğitilmiş kodlayıcı (Inception-ResNet-V2, VGG16) az veride işe yarar.
- Otomatik kodlayıcıda girdi ve çıktı boyutu eşittir, darboğaz sıkıştırılmış temsildir.
- Izgara araması bütün kombinasyonları dener ve pahalıdır; Bayes optimizasyonu olasılıksal bir modelle akıllı arama yapar.
- Ses sınıflandırma: STFT spektrogramı ile CNN, MFCC ile LSTM.
- Koşullu GAN: üretici ve ayırıcıya sınıf koşulu verilir; sentetik veri yalnız eğitimde kullanılmalıdır.

## Detaylı Açıklamalar

- Dengesiz veri ve başarı ölçüsü
  - Dolandırıcılık tespiti projesinde test kümesindeki 56.746 işlemin 95'i dolandırıcılıktı. Model 56.651 normal işlemin hepsini doğru bildi, dolandırıcılıkların 50'sini buldu. Doğruluk $(56651+50)/56746 \approx 0{,}9992$ olur. Bu yüksek değer neredeyse tamamen çoğunluk sınıfından gelir. Dolandırıcılık sınıfının duyarlılığı ise $50/95 \approx 0{,}526$'dır. Hoca bu tür problemlerde (kredi kartı dolandırıcılığı, telekom şirketlerinde müşteri kaybı yani churn) asıl ölçünün sınıf bazlı recall olduğunu söyledi.
  - Çözüm önerisi kayıp fonksiyonundaydı: çoğunluk sınıfındaki örnekler kaybı domine ediyor; azınlık sınıfının kayba katkısı çok daha büyük (ör. 100 kat) olmalı ki parametreler epoklar boyunca o sınıfa göre değişsin. Focal loss bu amaçla kullanılır.
  - Hoca, tabakalı örneklemenin içinde rastgele seçim yapıldığını teyit etti. Testin %40 gibi büyük bir oran olmasını da sorguladı: 300 bin normal ve 400 dolandırıcılık örneği varsayımıyla testte 120 bin normal ve 160 dolandırıcılık örneği kalır.
- Adam ve momentum
  - Adam'ın güncellemesinde momentumun etkisi birinci moment tahmini ve onun beta katsayısıyla gelir. Bu yüzden Adam'ı oluştururken momentum parametresi verilemez. Nadam, RAdam ve AdamW de beta ile çalışır.
- Weight decay ile ilgili hocanın açıklaması
  - Hoca weight decay'i öğrenme oranı zamanlaması gibi anlattı: belirli bir adım sayısından sonra öğrenme oranı weight decay ile çarpılarak düşürülür.
  - **Ders sonrası not:** Hoca weight decay'i öğrenme oranını azaltan bir zamanlama olarak anlattı. Doğrusu: weight decay her adımda ağırlıkları sıfıra doğru küçülten bir düzenlileştirmedir (L2 cezasına benzer). Öğrenme oranını adım adım bir katsayıyla çarparak düşürmek "learning rate decay" ya da "step decay" diye ayrı bir yöntemdir.
- U-Net projesi ve değerlendirme
  - Model piksel düzeyinde değerlendirildi: test maskeleri düzleştirilince 24.379.392 piksel çıktı; 16.879.601'i arka plan, 7.499.791'i ön plan. Doğruluk 0,8267, IoU 0,6752 (ekrandan, 00:45:00). İnce ayar sonrasında doğruluk yaklaşık %91'e, IoU 0,81'e çıktı.
  - Hoca, piksellerin yaklaşık %69'u arka plan olduğundan hep "arka plan" diyen bir modelin bile %69 doğruluk alacağını, bu yüzden doğruluk farkının (%82'den %91'e) IoU farkını (0,67'den 0,81'e) iyi yansıtmadığını anlattı. Görsel örnekte ilk model koyu nesnelerin merkezini bulup kenarları daraltıyordu, ince ayarlı model kenarları da yakaladı (ekrandan, 00:50:00).
  - Hoca terim olarak "görsel muayene" değil "görsel analiz" denmesi gerektiğini belirtti.
- SGD'nin düşük çıkması
  - Mobil fiyat projesinde SGD %76,75'te kaldı. Öğrenci bunu sabit öğrenme oranına bağladı. Hoca, SGD'nin momentum ve öğrenme oranı zamanlamasıyla ayarlanabildiğini, tek boyutlu tablo verilerinde $10^{-1}$-$10^{-2}$ civarı öğrenme oranlarında iyi çalıştığını, momentum ve zamanlama yoksa bir noktaya takılıp kalabileceğini söyledi.
  - **Ders sonrası not:** Sunumda daha büyük yığın boyutunun gradyanları "daha düzensiz" yaptığı söylendi. Doğrusu: büyük yığın, gradyan tahminindeki gürültüyü azaltır; küçük yığın daha gürültülü gradyan verir.
- Uydu görüntüsü segmentasyonu
  - Hoca, sınıf dağılımının görüntü sayısıyla değil piksel sayısıyla anlatılması gerektiğini, kısmen etiketlenmiş görüntülerde etiketsiz piksellerin tamamlanmasının ayrı bir araştırma problemi olduğunu (hiperspektral görüntülerde yapılan çalışmalar gibi) anlattı.
- Otomatik kodlayıcılı öneri sistemi
  - Kullanıcının 144 numaralı filme verdiği 4 oyu, filmin tür vektöründeki 1'lerin (aksiyon, gerilim) yerine yazılır. Ağın çıktısında bu değerler 3,8 ve 3,4 gibi tahminlere dönüşür, ortalama tahmin 3,6 olur (ekrandan, 01:35:00). Sapmalar MSE ve RMSE ile ölçülür.
  - Parametreler sırayla, diğerleri sabit tutularak seçildi: optimizasyon algoritması (Adam, RMSProp, Adadelta, Adagrad), aktivasyon (ReLU ve altyazıda bozuk geçen iki fonksiyon <!-- BELİRSİZ: altyazıda "Jeloo" ve "Celu"; büyük olasılıkla GELU ve SELU ya da CELU, karede görülmedi -->), gizli katman yapısı (20-10), öğrenme oranı, weight decay. Sonuçta RMSE yaklaşık 0,86 bildirildi.
- Bayes ve ızgara araması
  - Izgara araması verilen değerlerin bütün kombinasyonlarını dener (her parametre için 3 değer: ör. 32, 64, 128 nöron). Bayes araması bir aralık alır (32-128 nöron, %10-%50 dropout) ve olasılıksal bir modelle sıradaki denemeyi seçer; 36 nöron ya da 0,25 dropout gibi ara değerleri de deneyebilir.
  - **Ders sonrası not:** Sunumda ızgara aramasının 1 günlük tahminde doğrulama kaybının eğitim kaybının üstünde olması "yetersiz öğrenme" (underfitting) diye yorumlandı. Doğrulama kaybının eğitim kaybından belirgin yüksek olması genelde aşırı öğrenme işaretidir; negatif $R^2$ ise modelin ortalama tahminden bile kötü olduğunu gösterir.
- Kuş sesi sınıflandırma
  - Hoca 3 saniyelik pencerelemenin mantığını şöyle bağladı: kuş bir dakika boyunca sürekli ötmez; uzun bir spektrogramda öttüğü kısa bölgeler kaybolur. RMS eşiği sessizliği atar ama yağmur gibi gürültüleri ayırt etmez. Bu yüzden önce türden bağımsız "kuş sesi var mı" tespiti, sonra yalnız o pencerelerin sınıflandırılması önerildi.
  - MFCC'de pek çok katsayı bilgi taşımayabilir; katsayılar PCA ya da LDA sonuçlarına göre seçilmelidir. LSTM'e karıştırılmış (shuffle) pencereler vermenin zaman bilgisini bozup bozmadığı da tartışıldı.
- Koşullu GAN
  - Ayırıcı kaybı yaklaşık 330. iterasyona kadar çok büyük negatif değerlere inip birden sıfıra sıçradı (ekrandan, 02:50:00). Hoca bu davranışı sorguladı.
  - Orijinal veri yaklaşık %55-%45 dengeliyken bir sınıftan yaklaşık 19 bin, diğerinden 6.290 örnek üretilip veri dengesiz hale getirilmişti. Hoca bunun gerekçesini sordu.
  - Asıl değerlendirme sorunu: 918 satırlık orijinal veri %80-%20 ayrılırsa test yaklaşık 184 örnek olur. Sentetik ve orijinal veri birleştirilip sonra ayrılırsa test kümesine sentetik örnekler girer ve performans olduğundan yüksek görünebilir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
