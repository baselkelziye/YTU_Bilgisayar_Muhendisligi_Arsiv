# Ders 13 Çalışma Özeti

## Genel Konular

- Proje ilerleme sunumları
  - Ders, öğrencilerin dönem projelerindeki ilerlemeyi ekran paylaşarak gösterdiği ve hocanın her projeye yöntemsel geri bildirim verdiği bir oturum olarak geçti.
  - Projeler: kolon kanseri histoloji görüntülerinde çekirdek sınıflandırma, MR görüntülerinde beyin tümörü bölütleme (iki ayrı proje), servikal sitoloji (Cervix93, Herlev) ve kan yaymasında akyuvar sınıflandırma.
- Kolon kanseri çekirdek sınıflandırma ve transfer öğrenme
  - Veri seti: 100 görüntü, 500×500 piksel; slayta göre 9 hastanın 10 tam slaytından, 0,55 µm/piksel (20x optik büyütme) ile elde edilmiş, hem normal hem kanserli bölgeler içeriyor (ekrandan, 00:10:00).
  - Her görüntüde dört çekirdek sınıfı bir arada bulunabiliyor: fibroblast, epitel, kanserli (hastalıklı) hücre ve diğerleri. Çekirdekler merkezde kalacak biçimde 27×27 yamalar kırpıldı.
  - Doğrulama doğruluğu: SqueezeNet %80,04, ResNet50 %79,05 (ekrandan, 00:10:00).
  - Hoca MATLAB "Pretrained Deep Neural Networks" sayfasını gösterdi: ağı yükle, son katmanları değiştir, yeni veriye göre yeniden eğit (ince ayar). Önerilen ağlar: NASNet, DenseNet, Inception, Xception, DarkNet, ResNet.
  - ONNX: MATLAB ve Python (Caffe, PyTorch vb.) arasında model paylaşmaya yarayan ortak bir ara katman.
- Bölütleme sonucunu değerlendirme: yer gerçeği (ground truth) dosyası
  - Bir bölütleme yönteminin başarısı, sonucun uzman tarafından işaretlenmiş yer gerçeği maskesiyle karşılaştırılmasıyla ölçülür (ekrandan, 00:25:00).
  - Metrikler: tümör bölgesine düşen piksel yüzdesi, kesişim/birleşim (IoU), Dice ölçüsü (ekrandan, 00:35:00).
  - Sınıflandırma için hazırlanmış (tümör var/yok) bir veri setinde maske yoktur; bölütleme için BraTS gibi yer gerçeği içeren bir kıyaslama (benchmark) veri seti gerekir.
- BraTS 2020 ile beyin tümörü bölütleme
  - Bir öğrencinin setinde 349 hacim var; her hacim 155 kesitten oluşuyor. Dört çekim yöntemi (FLAIR, T1, T1CE, T2) ve bir bölütleme maskesi veriliyor.
  - Tümör 3B bir nesnedir; uçtaki kesitlerde maske boştur ya da çok küçüktür.
  - Hocanın önerisi: yalnız yer gerçeğinde tümör bulunan kesitleri kullan, birkaç piksellik (25 pikselin altı) bölgeleri dışarıda bırak; aynı kesitin dört çekim yöntemini dört kanal olarak ver.
  - Kullanılan ağlar: U-Net ve ResUNet benzeri bir melez; hoca Double U-Net'e de bakılmasını önerdi.
- Cervix93 ve Herlev servikal sitoloji veri setleri
  - Cervix93: 93 gerçek EDF (genişletilmiş alan derinliği) görüntüsü ve odak katmanları (stack); üç derece: Negative, LSIL, HSIL; 2705 çekirdek elle işaretlenmiş (ekrandan, 00:40:00).
  - Makaledeki derin öğrenme yöntemi: iki evrişim ve iki tam bağlantılı katmanlı bir CNN; gri seviye karelerden 75×75 yamalar çıkarılmış (ekrandan, 00:45:00).
  - Hocanın önerisi: çekirdek merkezleri etrafından yamalar al, veri artırma (döndürme ve köşegen yansıtma) uygula, önceden eğitilmiş ağlarla transfer öğrenme yap; 64, 128 ve 256 yama boyutlarını karşılaştır.
  - Herlev: 7 sınıf; U-Net ile bölütlemede çekirdek, sitoplazma ve arka plan ayrıldı, yaklaşık %85 başarı.
- Akyuvar (beyaz kan hücresi) sınıflandırma ve K-katlı çapraz doğrulama
  - Dört sınıf: eozinofil, lenfosit, monosit, nötrofil. Akış: ön işlem (histogram, RGB'den griye, medyan süzgeç), bölge tabanlı bölütleme, derin öğrenmeyle anlamsal bölütleme (ekrandan, 01:15:00).
  - ResNet50 ile %90 doğruluk; tek bir eozinofil görüntüsü için softmax çıktısı 0,9647 (ekrandan, 01:20:00).
  - Hoca %70/%30 elle ayırma yerine K-katlı çapraz doğrulamayı anlattı (ekrandan, 01:25:00).

## Hocanın Özellikle Vurguladığı Kısımlar

- Bölütlemede yer gerçeği olmadan sayısal sonuç olmaz
  - Bir yöntemin başarısını göstermek için sonucun yer gerçeğiyle örtüşmesi ölçülmelidir; %100 örtüşme beklenmez, IoU ve Dice gibi metrikler kullanılır.
  - Hoca 2018 sonrası MR bölütleme makalelerinin hangi veri setlerini ve hangi değerlendirme metriklerini kullandığının okunmasını istedi; başlangıç için BraTS 2015, sonra diğer BraTS yılları.
- Transfer öğrenmede yeni ağlar
  - VGG eskide kaldı; NASNet, Inception, Xception, DenseNet, DarkNet, ResNet denenmeli ve sonuçlar karşılaştırılmalı.
- Önce sınıflandırma, sonra bölütleme
  - Akyuvar projesinde önce dört hücre tipinin ayrıştırılması tam yapılmalı; derin öğrenmeyle bölütleme ayrı bir çalışma olarak sonraya bırakılır.
- K-katlı çapraz doğrulama
  - Verinin her parçası bir kez test kümesi olur; sonuçların ortalaması alınır. Bu, elle yapılan tek bir ayırmadan daha sağlam sonuç verir. Genelde 5 kat (%80 eğitim, %20 test) yeterlidir.
- Küçük maskeler
  - Birkaç piksellik tümör bölgesinde ağ çevredeki dokuyu (texture) yakalayamaz; bu kesitler başarıyı düşürür, ayıklanmalıdır.

## Kısa Tekrar Notları

- Transfer öğrenme: ImageNet'te eğitilmiş ağın alt katmanları genel özellikleri zaten öğrenmiştir; son katmanlar yeni sınıflara göre değiştirilip yeniden eğitilir (ince ayar).
- Yer gerçeği (GT) dosyası: tümörün gerçek konumunu gösteren maske; bölütleme sonucu bununla karşılaştırılır.
- IoU = kesişim / birleşim; Dice ölçüsü de örtüşmeyi ölçer.
- BraTS: 155 kesitli hacimler, dört çekim yöntemi (FLAIR, T1, T1CE, T2), kesit başına maske. Dört yöntem aynı kesitte dört kanal olarak verilebilir.
- Yalnız tümör içeren ve maskesi belli bir büyüklüğün üstünde olan kesitlerle çalış.
- Yama tabanlı sınıflandırma: çekirdek merkezi etrafından yama, ardından veri artırma (dört yöne döndürme, köşegen yansıtma).
- K-katlı çapraz doğrulama: veri K parçaya bölünür, her turda bir parça test, kalanı eğitim; test sonuçlarının ortalaması alınır. MATLAB'de `cvpartition`.
- Önceden eğitilmiş ağlarda doğrulama eğrisi başta yüksek bir değerden başlayabilir; bu tek başına hata işareti değildir.

## Detaylı Açıklamalar

- Kolon kanseri çekirdek sınıflandırma projesinde öğrenci, her görüntüde birden çok sınıftan çekirdek bulunduğu için görüntünün tamamını değil, verilen çekirdek konumlarının etrafından kırptığı 27×27 yamaları sınıflandırıyordu. Sınıflara göre binlerce yama elde edilmişti (fibroblast için yaklaşık 5149, epitel için 7069). <!-- BELİRSİZ: kanserli ve "diğer" sınıflarının yama sayıları altyazıda bozuk ("altı bir", "1700-21") --> SqueezeNet ve ResNet50 ile yaklaşık %80 doğrulama doğruluğu elde etmişti (ekrandan, 00:10:00). Öğrenci, MATLAB'de doğrulama sabrı (validation patience) değerini `Inf` yapınca eğitimin erken durmadan sonuna kadar sürdüğünü fark ettiğini anlattı. Hoca önceden eğitilmiş ağırlıkların yüklenip yüklenmediğini sordu; öğrenci ağı ağırlıksız (sıfırdan) çalıştırmıştı. Bunun üzerine hoca MATLAB belgelerinden önceden eğitilmiş ağları ve transfer öğrenme bölümünü gösterdi: ImageNet'in yaklaşık bir milyon görüntüsü ve bin sınıfıyla eğitilmiş ağlar alt seviye özellikleri zaten öğrenmiştir; son katmanlar yeni veri setine özgü özellikleri öğrenecek biçimde değiştirilir ve ağırlıklar ince ayarla güncellenir. Ayrıca MATLAB ile Python çerçeveleri arasında model aktarmayı sağlayan ONNX biçimini gösterdi ve listedeki bütün ağların denenmesini istedi.

- Beyin tümörü projesinde öğrenci, ikili eşikleme, bulanık K-ortalama ile öz düzenlemeli harita (FKM-SOM), ayrık dalgacık dönüşümü (DWT) ile öznitelik çıkarma, PCA ile boyut indirgeme ve SVM ile sınıflandırma (RBF, doğrusal, polinom çekirdek) kullanan bir makaleyi ve bu makalenin MATLAB arayüzünü (GUI) gösterdi (ekrandan, 00:15:00 ve 00:20:00). Makalede 13 öznitelik kullanılıyor; F-ölçüsü, kesinlik (precision), doğruluk, özgüllük ve duyarlılık (recall) raporlanıyor. Hoca bölütleme doğruluğunun neye göre ölçüldüğünü sordu ve beyaz tahtada açıkladı: MR görüntüsünde bir tümör vardır; uzmanın işaretlediği yer gerçeği dosyası tümörün nerede olduğunu gösterir. Yöntemin ürettiği bölütlenmiş görüntüde tümör bölgesinin yanında artefaktlar da bulunabilir. İki görüntü karşılaştırılarak örtüşme yüzdesi, IoU ya da Dice ölçüsü hesaplanır (ekrandan, 00:25:00 ve 00:35:00). Öğrencinin gösterdiği Kaggle veri seti yalnız "yes/no" klasörlerinden oluşan bir sınıflandırma setiydi, maskesi yoktu (ekrandan, 00:30:00). Hoca bu yüzden BraTS 2015 gibi eğitim ve test vakalarıyla birlikte yer gerçeği veren bir bölütleme kıyaslama setinin kullanılmasını, U-Net ve SegNet gibi derin öğrenme yöntemleriyle bölütleme yapılmasını ve sonucun yer gerçeğiyle karşılaştırılmasını istedi. Arayüz gerekmediğini, yalnız sonuçların yeterli olduğunu söyledi.

- Cervix93 projesinde öğrenci, verilen çekirdek koordinatlarını işaretleyip bağlantılı bileşen analizi uygulamıştı. Makaleye göre veri seti 93 EDF görüntüsünden ve her görüntünün odak katmanlarından (stack, yaklaşık 20 katman) oluşur; görüntü düzeyinde üç derece vardır (Negative, LSIL, HSIL) ve 2705 çekirdek işaretlenmiştir (ekrandan, 00:40:00). Makaledeki CNN, gri seviye karelerden 15 piksel aralıkla alınan 75×75 yamaları "çekirdek / çekirdek değil" diye sınıflandırır; elle işaretli noktaya 15 pikselden yakın yamalar pozitif sayılır; öğrenme oranı 0,001, 100 dönem; toplam 654.948 yama, bunların %1,71'i pozitif (ekrandan, 00:45:00). Hoca, bir görüntüdeki hücrelerin hepsinin o görüntünün sınıfına ait kabul edilebileceğini, bu yüzden çekirdek merkezleri etrafından yamalar alınıp sınıflandırılabileceğini söyledi. Örnek hesap: her sınıftan yaklaşık 30 görüntü varsa ve her görüntüden yaklaşık 20 yama çıkıyorsa sınıf başına 600 yama olur; bunlar dört yöne döndürülüp köşegen boyunca yansıtılarak çoğaltılır. Görüntüler 960×1280 kadar büyük olduğundan 64, 128 ve 256 boyutlu yamalar karşılaştırılmalı; büyük yama daha çok uzamsal bilgi taşır. Herlev setinde (7 sınıf) U-Net ile çekirdek, sitoplazma ve arka plan bölütlemesinde yaklaşık %85 başarı elde edilmişti.

- BraTS 2020 projesinde 349 beyin hacmi, her biri 155 kesit, dört çekim yöntemi ve bir maske vardır (ekrandan, 00:55:00). Hoca 3B düşünmeyi önerdi: tümör hacmin içinde bir nesnedir; kesitler ilerledikçe tümör kesiti küçük başlar, büyür, sonra küçülüp kaybolur. Bu yüzden yalnız yer gerçeği içeren kesitler kullanılmalı; örneğin her hacimde 100 kesit tümör içeriyorsa 349 × 100 = 34.900 kesitlik bir veri değerlendirilir (ekrandan, 01:05:00). Aynı kesit numarasının dört çekim yöntemi dört kanal olarak (256×256×4) ve aynı kesitin maskesi çıktı olarak verilir; bu dört farklı özniteliği birlikte kullanmak sonucu iyileştirir. <!-- BELİRSİZ: öğrenci kesit boyutunu 256×256 dedi; ekrandaki BraTS çizimi ve kodda input_shape = (240, 240, 1) görünüyor (ekrandan, 00:55:00 ve 01:00:00) --> Öğrenci ResUNet modelini Jupyter'de gösterdi: ana yolda 1×1 ve 3×3 evrişim, toplu normalleştirme ve ReLU; kısayol yolunda 1×1 evrişim ve toplu normalleştirme; iki yol `Add()` ile toplanır (ekrandan, 01:00:00).

- Akyuvar projesinde öğrenci ön işlem (histogram, RGB'den griye, medyan süzgeç), bölge tabanlı bölütleme ile kırmızı ve beyaz kan hücresi veri setleri üretme ve derin öğrenmeyle anlamsal bölütleme adımlarını gösterdi (ekrandan, 01:15:00). ResNet50 ile dört sınıfta %90 doğruluk elde etmişti; MATLAB'de doğruluk `accuracy = mean(YPred == YValidation)` satırıyla hesaplanıyordu ve tek bir eozinofil görüntüsü için ağın çıktısı [0,9647; 0,0058; 0,0191; 0,0104] idi (ekrandan, 01:20:00). Hoca K-katlı çapraz doğrulamayı beyaz tahtada anlattı: dört sınıftan 1000'er örnek, toplam 4000 örnek; veri 5 kata bölünür, her katta 800 örnek (her sınıftan 200) vardır. Her turda 4 kat (3200 örnek) eğitim, 1 kat (800 örnek) test için kullanılır; beş turun test sonuçlarının ortalaması alınır (ekrandan, 01:25:00). Böylece verinin her parçası test olarak kullanılmış olur. MATLAB'de bunun için `cvpartition` komutu vardır. Son olarak MATLAB'in önceden eğitilmiş ağları karşılaştıran grafiğinde ResNet-50, ResNet-101, Inception-v3, DarkNet-53, Xception, Inception-ResNet-v2, DenseNet-201 ve NASNet-Large işaretlenerek denenmesi istendi (ekrandan, 01:30:00).

- Bir öğrencinin, doğrulama eğrisinin bir anda çok yükselip sonra düştüğünü sorması üzerine hoca, önceden eğitilmiş ağların ağırlıkları hazır olduğu için eğitime belli bir doğrulukla başladığını, biyomedikal görüntülerin çok karmaşık olmadığını ve bunun verinin iyi ayrıştığını gösterebileceğini, tek başına hata anlamına gelmediğini söyledi.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
