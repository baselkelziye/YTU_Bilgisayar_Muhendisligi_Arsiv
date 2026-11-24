# Ders 6 Çalışma Özeti

## Genel Konular

- Ders, dönem projelerinin ilerleme görüşmeleri biçiminde yürütüldü
  - Kayıtta iki proje konuşuldu: TransUNet ile bölütleme sonuçlarına son işleme (post-processing) eklenmesi ve meme histopatoloji görüntülerinde iyi huylu / kötü huylu sınıflandırma.
  - Hoca öğrencinin ekranındaki veri seti klasörlerini, karışıklık matrisini ve görüntüleri inceleyerek deney tasarımına yön verdi.
- TransUNet bölütmesine son işleme
  - TransUNet ile elde edilen bölütme çıktısında gürültülü bölgeler kalmıştı. Bu gürültüyü gidermek için Markov rastgele alanları (Markov Random Fields, MRF) ile son işleme uygulanmasına karar verilmişti.
  - Hazır bir MRF kodu projenin girdi verisini alacak biçimde uyarlandı ve çalıştırıldı; sonuçların değerlendirmesi henüz yapılmamıştı.
  - Karşılaştırma için Swin-Unet ve UNet++ gibi başka bölütme modellerinin de denenmesi ve bunlara da son işleme eklenmesi planlandı. <!-- BELİRSİZ: altyazıda "Unet++++" diye de geçen bir model adı var; UNet 3+ kastedilmiş olabilir. -->
- Meme histopatolojisinde sınıflandırma: BreakHis veri seti
  - Veri seti BreakHis; 400 kat büyütmeli (400X) görüntülerle, iyi huylu (benign) ve kötü huylu (malignant) iki sınıf ayrılıyor.
  - Öğrencinin klasöründe görüntüler 299x299 ve 224x224 boyutlu iki ayrı kopya halinde duruyordu; her sınıf klasöründe 1146 görüntü vardı (ekrandan, 00:15:00 ve 00:25:00).
  - Hoca, hazır indirilen 224x224 görüntülerin, daha büyük olan özgün görüntülerin içinde 224x224'lük bir pencere gezdirilerek elde edildiğini açıkladı. <!-- BELİRSİZ: öğrencinin söylediği özgün boyut altyazıda bozuk ("yedi yüz çarpı ... altmış"); BreakHis görüntüleri büyük olasılıkla 700x460 pikseldir. -->
  - Inception ağıyla bir katın (Fold 2) karışıklık matrisi gösterildi (ekrandan, 00:20:00): benign 229 doğru / 1 yanlış, malignant 5 yanlış / 224 doğru.
- Sonuç tablosu için istenen modeller ve ölçütler
  - Modeller: Inception, ResNet-101, DenseNet-201, NASNet ve EfficientNet. ShuffleNet istenmedi; her ağın büyük sürümü tercih edilmeli.
  - Bütün modeller 224x224 girdiyle çalıştırılmalı.
  - Her model için doğruluk (accuracy), kesinlik (precision), duyarlılık (recall) ve F-ölçütü (F-measure) bir tabloda verilmeli.
- İkinci veri seti: ICIAR 2018 BACH
  - Dört sınıflı: Benign, InSitu, Invasive, Normal (ekrandan, 00:35:00). Görüntüler 2048x1536 piksel ve sınıf başına yaklaşık 100 görüntü var.
  - Bu boyuttaki görüntüler doğrudan ağa verilemez; yeniden boyutlandırma başarımı çok düşürür. Bu yüzden görüntülerden 224x224'lük yamalar (patch) kesilmeli.
- Hücre yoğunluğuna göre otomatik yama çıkarma
  - Eşikleme (threshold) ile koyu (mor boyanmış) bölgeler, yani hücrelerin yoğun olduğu yerler bulunur.
  - 224x224'lük bir pencere görüntü üzerinde hem yatayda hem düşeyde 50'şer piksel kaydırılarak gezdirilir; 1 piksellik kaydırma yapılmaz.
  - Penceredeki hücre oranı belirli bir eşiğin (örneğin %40) üstündeyse o pencere yeni bir yama olarak kaydedilir. Yamalar üst üste binebilir; hücre içermeyen boş bölgeler alınmaz.
  - Böylece her sınıftaki 100 civarı görüntüden binlerce yama elde edilir ve sınıflandırma kalitesi artar.
- Görüntü gösterim sorunu
  - Görüntüler 0-1 aralığına ölçeklenip kaydedildiğinde, 0-255 aralığı bekleyen bir görüntüleyici onları siyaha yakın gösterir; bu bir biçim (format) sorunudur, veride hata yoktur.

## Hocanın Özellikle Vurguladığı Kısımlar

- Ağlara verilen girdi boyutu tutarlı olmalı
  - Hoca, görüntülerin neden 299x299'a getirildiğini sordu; genellikle 224x224 kullanıldığını söyledi ve bütün modellerin 224x224 ile çalıştırılmasını istedi.
- Sonuçlar karşılaştırma tablosu halinde verilmeli
  - Tek bir modelin doğruluğu yetmez; birden çok önceden eğitilmiş modelin accuracy, precision, recall ve F-measure değerleri aynı tabloda yan yana olmalı. Aynı tablo ikinci veri seti için de hazırlanmalı.
- Büyük görüntüyü küçültme, yamalara böl
  - 2048x1536 gibi büyük histopatoloji görüntüleri yeniden boyutlandırılırsa hücre ayrıntısı kaybolur. Hücre yoğun bölgelerden kesilen yamalar hem ayrıntıyı korur hem veri sayısını artırır.
- Yama çıkarma elle değil programla yapılmalı
  - Eşikleme + kayan pencere + hücre oranı ölçütüyle çalışan bir program yazılmalı; adım 50 piksel, hücre oranı eşiği örneğin %40.
- Çalışma sırası
  - Önce BreakHis ile bütün modellerin deneyleri bitirilmeli, ardından BACH veri setine geçilmeli.

## Kısa Tekrar Notları

- TransUNet çıktısındaki gürültü için son işleme: Markov rastgele alanları.
- BreakHis: 400X, benign / malignant; hazır 224x224 görüntüler özgün görüntüden kayan pencereyle kesilmiş.
- Inception, Fold 2: 229 / 1 ve 5 / 224; doğruluk yaklaşık %98,7.
- İstenen modeller: Inception, ResNet-101, DenseNet-201, NASNet, EfficientNet; hepsi 224x224 girdiyle.
- Ölçütler: accuracy, precision, recall, F-measure; tablo halinde, her veri seti için.
- BACH: 4 sınıf (Benign, InSitu, Invasive, Normal), 2048x1536 görüntüler, sınıf başına yaklaşık 100 görüntü.
- Yama çıkarma: eşikleme ile hücre bölgeleri, 224x224 pencere, 50 piksel adım, hücre oranı > %40 ise kaydet.
- Yeniden boyutlandırma büyük histopatoloji görüntüsünde başarımı düşürür.
- 0-1 aralığındaki görüntü 0-255 bekleyen görüntüleyicide siyaha yakın görünür.

## Detaylı Açıklamalar

- **TransUNet sonrası son işleme.** Bir öğrenci, TransUNet ile elde ettiği bölütme haritalarında küçük, dağınık gürültü bölgeleri kaldığını, bunları gidermek için Markov rastgele alanlarına dayalı bir son işleme adımı eklediğini anlattı. MRF, bir pikselin etiketini komşularının etiketleriyle birlikte değerlendirdiği için tek başına kalmış yanlış etiketleri düzeltmeye uygundur. Hazır bir MRF kodu, projenin veri biçimini girdi olarak alacak şekilde değiştirildi ve çalıştırıldı. Sonraki adım olarak Swin-Unet ve UNet++ gibi başka bölütme modelleri de çalıştırılıp aynı son işlemenin onlara da eklenmesi planlandı.

- **BreakHis ile ikili sınıflandırma.** İkinci projede meme dokusu histopatoloji görüntüleri iyi huylu ve kötü huylu olarak sınıflandırılıyor. Öğrenci 400X büyütmeli görüntüleri hem 299x299 hem 224x224 boyutlarında tutuyordu. Hoca önce özgün görüntülerin boyutunu sordu ve 224x224'lük kopyaların, özgün görüntünün içinde kare bir pencere gezdirilerek daha çok görüntü elde edilmesiyle hazırlandığını açıkladı. Bu yüzden 224x224'lük yamalarla çalışılmasını istedi. Inception ile alınan bir katın sonucunda (ekrandan, 00:20:00) benign sınıfından 229 görüntü doğru, 1 görüntü yanlış; malignant sınıfından 224 görüntü doğru, 5 görüntü yanlış sınıflandırılmıştı. Bu matristen doğruluk $\frac{229+224}{459} \approx \%98{,}7$ bulunur (python ile doğrulandı).

- **Karşılaştırma tablosu.** Hoca, Inception'a ek olarak ResNet-101, DenseNet-201, NASNet ve EfficientNet ile de deney yapılmasını, model adlarını sohbet (chat) kısmına yazdığını söyledi. Her ağın büyük sürümünün kullanılmasını, ShuffleNet'in ise gerekmediğini belirtti. Sonuçlar accuracy, precision, recall ve F-measure sütunlarından oluşan bir tabloda verilecek; aynı tablo BACH veri seti için de hazırlanacak.

- **BACH veri seti ve yama çıkarma.** ICIAR 2018 BACH veri seti dört sınıflıdır (Benign, InSitu, Invasive, Normal) ve görüntüleri 2048x1536 pikseldir. Hoca bir görüntüyü öğrencinin ekranında açıp üzerine 224x224'lük kareler çizerek nasıl kesileceğini gösterdi. Yalnız hücrelerin yoğun olduğu, mor boyanmış bölgelerden yama alınmalı; kenardaki boş alanlardan alınmamalı. Bunun için eşikleme ile koyu bölgeler bulunur, 224x224'lük pencere 50'şer piksel adımlarla sağa ve aşağı kaydırılır, penceredeki hücre oranı örneğin %40'ı geçiyorsa yama kaydedilir. Yamalar üst üste binebilir. Öğrencinin "veri artırma (augmentation) gibi mi?" sorusuna hoca, amacın ayrıntıyı korumak olduğunu, görüntünün çok büyük olduğu için doğrudan ağa verilemeyeceğini ve yeniden boyutlandırmanın başarımı çok düşüreceğini söyledi; yan etkisi olarak da yama sayısı binlere çıkar.

- **Görüntülerin siyah görünmesi.** Ekranda bazı görüntüler siyaha yakın görünüyordu. Bunun nedeni görüntülerin 0-1 aralığına ölçeklenmiş olması, görüntüleyicinin ise 0-255 aralığı beklemesidir; farklı kaynaklardan gelen farklı biçimdeki verileri doğru açmak da projenin öğrenilecek bir parçası olarak anıldı.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
