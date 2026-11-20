# Ders 12 Genişletilmiş Notu: Öğrenci Sunumları: GAN Uygulamaları, Makine Görmesiyle Hastalık Tanıma ve KLT ile Çatlak Tespiti

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dersin Yapısı
- 2. Görsellerden Mobilya Stili Eşleştirme ve VGG16 ile Kümeleme
- 3. Eski Fotoğrafların Renklendirilmesi: GAN, NoGAN ve DeOldify
- 4. Makine Görmesiyle Papaya Hastalığı Tanıma
- 5. GAN ile Sentetik Tıbbi İmge Çoğaltma: Karaciğer Lezyonları
- 6. Yüz Yaşlandırma: GAN Türleri, Conditional GAN ve CycleGAN
- 7. Video İzleme ile Çelik Köprülerde Yorgunluk Çatlağı Tespiti
- 8. TRUBA Altyapısında Derin Öğrenme
- Örnek Sorular
- Dersin Toparlaması

## 1. Dersin Yapısı

Bu derste konu anlatımı yapılmadı. Öğrenciler dönem projelerini ve inceledikleri makaleleri sundu. Her sunumdan sonra hoca sorular sordu ve kısa değerlendirmeler yaptı. Bu sorular ve yorumlar dersin asıl öğretici kısmını oluşturuyor. Sunumlar bir arada şu konuları kapsıyor: önceden eğitilmiş CNN'lerle özellik çıkarımı, üretken çekişmeli ağlar (GAN) ve türevleri, klasik görüntü işlemeye dayalı segmentasyon ve sınıflandırma, ilgi noktası tespiti ve video üzerinde izleme. Not, sunumları ders sırasıyla aktarıyor. Sunum yapanlar adsız, "bir öğrenci" diye anılıyor.

## 2. Görsellerden Mobilya Stili Eşleştirme ve VGG16 ile Kümeleme

### 2.1 Makalenin amacı

İlk sunumda incelenen makalenin konusu, etkileşimli 3B sahne modellemesi için görseller üzerinden mobilya stili eşleştirmekti. Belli bir tarza uygun iç mekân tasarlamak normalde iç mimar gibi uzmanların işidir. Makale bunu otomatikleştiren bir sistem öneriyor. Slayttaki akış şöyle (ekrandan, 00:05:00): müşteri için beklentilerine uygun bir sahneyle işe başlanır, müşteri katalogdan kendi beklentilerine göre seçimler yapar, sistem bu seçimlerle uyumlu mobilyaları önerir. Öneri yazılı bir liste olarak verilmez, 3B sahne olarak oluşturulur.

### 2.2 Mimari ve veri

Altyapıda Keras'taki VGG16 mimarisi kullanılmış. Ağ olduğu gibi alınmamış, son iki katmanı değiştirilmiş. Öğrenci soruya cevaben bu değişikliklerde tam bağlı katmanlar, softmax ve ReLU aktivasyonlarının kullanıldığını söyledi. Veri %80 eğitim, %10 doğrulama ve %10 test olarak bölünmüş. Yaklaşık 670 bin görsel kullanılmış, eğitim NVIDIA Tesla bir GPU'da yaklaşık 5 saat sürmüş.
<!-- BELİRSİZ: Altyazıda girdi için "BGL 94 temelli input" geçiyor (00:04:12, 00:12:10); terim karelerden doğrulanamadı. -->

Benzer ticari uygulamalar daha çok geometri temelli. Köşe bulma gibi yöntemlerle mobilyanın geometrisinden tanımlama yapıyorlar. Bu makale ise farklı açılardan çekilmiş görseller arasında benzerlik kurmayı kolaylaştıran kumaş, renk ve tarz gibi özellikleri de kullanıyor. Yaklaşık 670 bin görselin etiketlenmesinde uzmanlardan yardım alınmış. Uzmanların zevkleri birbirinden farklı olabildiği için 0-1 mantığıyla etiketlemek yerine puanlamaya dayanan "karşılaştırma etiketi" adlı bir yapı kullanılmış. Stiller arasında modern, geleneksel, cottage ve coastal gibi sınıflar var.

Gelecek çalışma önerileri: daha fazla stil ve kategori eklemek, mobil cihazlarda çevrim dışı çalışabilmesi için ağın boyutunu küçültmek ve 2B fotoğraflar yerine doğrudan 3B girdiyle çalışmak. Sistem zaten 3B çıktı ürettiği için son öneri anlamlı.

### 2.3 Öğrencinin denemesi: VGG16 özellikleri ve K-means

Öğrenci kendi denemesinde internetten yaklaşık 4500 mobilya fotoğrafı içeren bir veri seti buldu. Bunlardan yatak, sandalye, koltuk, döner sandalye ve masa sınıflarının her birinden 100'er tane, toplam 500 görsel seçti (ekrandan, 00:15:00). Görseller önceden eğitilmiş VGG16'dan geçirilip özellik vektörleri çıkarıldı. Bu vektörler K-means ile 5 kümeye ayrıldı. Kümelere 0'dan 4'e numara verildi, hangi kümenin hangi sınıfa karşılık geldiği önceden bilinmiyordu.

Slayttaki grafik (ekrandan, 00:10:00):

| Küme | İçerik (yaklaşık, grafikten) |
|---|---|
| Class 0 | Çoğunluk sandalye (yaklaşık %63); yatak, döner sandalye ve masa daha az |
| Class 1 | %100 masa |
| Class 2 | %100 döner sandalye |
| Class 3 | Yatak (yaklaşık %45) ve koltuk (yaklaşık %54) |
| Class 4 | Büyük çoğunluk döner sandalye (yaklaşık %90), az miktarda sandalye |

Slayttaki yorumlar şunlar: Class 2 tamamen döner sandalyelerden oluşuyor, ancak Class 4'te de döner sandalyeler olduğundan yüksek bir başarıdan söz edilemez. Class 3'te yatak ve koltuk için beraberliğe yakın bir kümeleme var. Malzeme benzerliği büyük olasılıkla bu iki sınıfı ayırmayı zorlaştırıyor.

> **Ders sonrası not:** Öğrenci sözlü olarak Class 0'ın büyük çoğunluğunun yatak olduğunu söyledi. Ekrandaki grafikte Class 0'ın çoğunluğu sandalye, yatak ve koltuklar ise Class 3'te.

Kod üç modülden oluşuyordu: özellikleri oluşturan modül, kümeleyen modül ve sonuçları klasörlere dağıtıp istatistik çıkaran modül. Hoca öğrencinin ağının sınıflama mı yoksa yeni tasarım üretimi mi yaptığını sordu. Öğrenci, süre kısıtı nedeniyle yalnız özellik çıkarımı ve sınıflama/kümeleme yaptığını söyledi.

## 3. Eski Fotoğrafların Renklendirilmesi: GAN, NoGAN ve DeOldify

### 3.1 GAN'ın temel fikri

İkinci sunumun konusu siyah-beyaz fotoğrafları renklendiren DeOldify projesiydi. Projenin bir makalesi yok; öğrenci raporu kendisi hazırladı. Proje filmleri de renklendirebiliyor, çünkü film art arda oynatılan resimler olarak düşünülebilir.

GAN 2014'te Goodfellow ve arkadaşları tarafından tanıtıldı. İki ağdan oluşur: üretici (generator) yeni örnek üretir, ayırt edici (discriminator) örneğin gerçek mi sahte mi olduğunu sınıflandırır. Bu yapı sıfır toplamlı bir oyundur: bir ağın kazancı diğer ağın kaybına (loss) karşılık gelir. GAN eğitimi iki ağın eş zamanlı eğitilmesiyle yapılır. Sezgisel benzetme kalpazan ile polistir. Kalpazan polisi yanıltmak için sürekli daha iyi sahte para basar, polis de sahte paraları yakalamak için yöntemlerini geliştirir. İkisi birbirini geliştirdikçe sonuçlar iyileşir.

### 3.2 NoGAN

DeOldify'ın geliştiricisi Jason Antic, GAN eğitimini "NoGAN" adını verdiği bir yöntemle geliştirmiş. Tek başına GAN eğitimi uzun sürer, CPU ile günler alabilir. Ayrıca normal GAN eğitiminde yapay oluşumlar (artefaktlar) sık görülür. Slayttaki açıklama (ekrandan, 00:20:00):

- Bu eğitim, üretici ağın sıradan bir derin ağ gibi eğitilmesiyle başlar.
- Bu ön eğitimden sonra üretici, GAN eğitimi tamamlanmadan bile renklendirmede iyi bir seviyeye gelir.
- Ardından GAN eğitimi yapılarak üretici-ayırt edici ikilisi optimize edilir ve resimlerdeki gerçeklik artırılır.
- Eğitim sırasında örneklere rastgele Gauss gürültüsü uygulanır. Böylece model gürültülü girdilere karşı daha iyi sonuç verir.

NoGAN eğitimiyle artefaktların daha az oluştuğu belirtiliyor.

### 3.3 Başarımın ölçülmesi

İnternette bu proje için bir başarım analizi bulunmadığından öğrenci kendisi bir ölçüm yaptı. 50 renkli resim gri tonlamaya çevrildi, DeOldify ile yeniden renklendirildi ve orijinalle karşılaştırıldı. Kaba kuvvet bir benzerlik ölçüsü kullanıldı: her kanaldaki orijinal değerden tahmin edilen değer çıkarıldı, farklar toplandı ve toplam piksel sayısına bölündü. Pikselde rengi tam tutturma oranı yaklaşık binde 5 çıktı, bu çok düşük. Genel benzerlik oranı ise yaklaşık %70-72. Model bazen orijinal rengi yakalamada büyük hatalar yapıyor, ama genel tonları tutturmada başarılı.

Örnek olarak Golden Gate Köprüsü'nün inşaat dönemi fotoğrafı gösterildi (ekrandan, 00:25:00). Model kuleleri gerçekte olduğu gibi kırmızı değil açık renkte boyadı. Renk tam tutmasa da göze hoş gelen bir boyama yapıyor. Sepya tonlu eski bir fotoğrafta da başarılı sonuç verdiği görüldü. Öğrenci kodu yerelde çalıştırmadı, projenin hazır web API'sini kullandı. API'nin ücretsiz ve ücretli sürümleri var.

### 3.4 Hocanın değerlendirmesi: bilgi kaybı

Hoca, orijinal rengi bulmanın esasen mümkün olup olmadığını sordu. Örnek olarak kendi kamera görüntüsünü verdi: arkadaki bir nesnenin gerçek rengini gri tondan nereden bileceksiniz? Öğrenci siyah-beyaza dönüşümün her zaman kayıplı olduğunu söyledi, hoca da onayladı. Farklı renkler aynı gri değere düşer, model hangisini seçeceğini bilemez.

> **Hocanın vurgusu:** Renkli resmi griye çevirince bilgi kaybediyoruz. Bu yüzden orijinal rengi kesin bulmak mümkün değil. Problemin güzel yanı ise veri setinin kolay hazırlanması: internetteki renkli resimleri indirip griye çevirerek giriş-çıkış çiftleri oluşturabilirsiniz. Yalnız griye çevirmenin de farklı yöntemleri var; nasıl çevrildiği önemli.

## 4. Makine Görmesiyle Papaya Hastalığı Tanıma

### 4.1 Problem ve sistem mimarisi

Üçüncü sunumda, Bangladeş'te yetiştirilen papaya meyvesindeki hastalıkları makine görmesiyle tanıyan bir uzman sistem makalesi incelendi. Çalışmanın gerekçeleri: nüfusun yaklaşık %47'sinin tarımla uğraşması, çiftçilerin teknik eğitim eksikliği ve tarım alanlarına ulaşım güçlüğü. Slayttaki hedefler (ekrandan, 00:30:00): mobil bir cihazla görüntü alma, makine görmesi tabanlı bir yaklaşımla papaya hastalığını tanıma, hastalığı tanıyabilen bir uzman sistem önerme, SVM (destek vektör makinesi) ile hastalıkları sınıflandırma ve gerçek zamanlı sistem çalışması.

Mimaride çiftçi hastalıklı meyvenin fotoğrafını mobil uygulamayla çeker. Görüntü internet üzerinden uzman sistemin kurulu olduğu sunucuya gönderilir, sonuç kullanıcıya SMS olarak geri bildirilir.

### 4.2 İşlem hattı

1. Renkli girdi görüntüsü bikübik interpolasyonla sabit boyuta (300×300 piksel) getirilir. Kullanıcı ve cihaza göre görüntü boyutları farklı olduğu için bu gerekli.
2. Histogram eşitleme ile kontrast artırılır.
3. Görüntü RGB'den L\*a\*b\* renk uzayına dönüştürülür. L açıklığı (parlaklığı), a ve b renk bileşenlerini gösterir. Bu çalışmada k-means'in L\*a\*b\* uzayında RGB'ye göre daha iyi segmentasyon yaptığı belirtiliyor.
4. k-means kümeleme ile görüntü bölgelere ayrılır. Hastalıklı kısımlar sağlıklı kısımlardan ayrılır.
5. Hastalıklı bölgeden istatistiksel ve GLCM özellikleri çıkarılır.
6. Özellik vektörleri doğrusal SVM ile sınıflandırılır.

İncelenen hastalıklar: siyah leke (black spot), külleme (powdery mildew), kahverengi leke (brown spot), Phytophthora yanıklığı ve antraknoz.

### 4.3 Özellikler

İstatistiksel özellikler hastalıklı bölgedeki piksellerin gri tonlama değerleri üzerinden hesaplanır: ortalama, standart sapma, varyans, basıklık ve çarpıklık. Gri seviye eş oluşum matrisi (GLCM) özellikleri ise iki piksel arasındaki ilişkiye bakarak doku bilgisi çıkarır. Bunlar kontrast, korelasyon, enerji, entropi ve homojenliktir. İki özellik setinden toplam 10 özellik kullanılır.

> **Ek bilgi (derste anlatılmadı):** GLCM, belli bir yön ve uzaklıktaki piksel çiftlerinde $i$ ve $j$ gri seviyelerinin birlikte görülme sıklığını tutan bir matristir. Kontrast $\sum_{i,j}(i-j)^2 p(i,j)$, enerji $\sum_{i,j} p(i,j)^2$, entropi $-\sum_{i,j} p(i,j)\log p(i,j)$ biçiminde tanımlanır. Bu ölçüler dokunun pürüzlülüğünü ve düzenliliğini sayısallaştırır.

### 4.4 Segmentasyon başarımı

k-means segmentasyonu elle işaretlenmiş referans (ground truth) bölgelerle karşılaştırıldı. Makaledeki Tablo 1 (ekrandan, 00:35:00):

| Hastalık | Referans bölge | Tahmin edilen bölge | Sapma |
|---|---|---|---|
| Black spot | %100 | %89,76 | -%10,24 |
| Powdery mildew | %100 | %123,09 | +%23,09 |
| Brown spot | %100 | %159,33 | +%59,33 |
| Phytophthora blight | %100 | %109,11 | +%9,11 |
| Anthracnose | %100 | %93,17 | -%6,83 |
| Total | %100 | %114,89 | +%22,46 |

> **Ders sonrası not:** Sunumda "%59 fazlalık oranında Phytophthora yanıklığı sapması" denildi. Tabloya göre +%59,33 kahverengi lekeye (brown spot) ait; Phytophthora yanıklığının sapması +%9,11. Ayrıca beş tahminin ortalaması python ile %114,89 çıkıyor, bu da toplam satırıyla uyumlu. Ancak sapmaların ortalaması +%14,89 olmalıyken tabloda +%22,46 yazıyor. Bu fark büyük olasılıkla makaledeki tablodan kaynaklanıyor.

### 4.5 Sınıflandırma başarımı

129 görüntü 84'ü eğitim, 45'i test olmak üzere ayrıldı (84 + 45 = 129). Aşırı uyumdan kaçınmak için doğrulama seti de kullanıldı. Beş tekrarın ortalamasıyla çok sınıflı karışıklık matrisi oluşturuldu, ardından ikili karışıklık matrislerine indirgendi. Bunlardan doğruluk, duyarlılık, özgüllük, kesinlik, yanlış pozitif oranı ve yanlış negatif oranı hesaplandı. Sonuçlar: doğruluk %95,2, duyarlılık %85,6, özgüllük %97,12. Duyarlılığın görece düşük olması yanlış negatif oranının biraz yüksek olduğu anlamına geliyor. SVM altı ölçütün hepsinde karar ağacı ve naive Bayes sınıflandırıcılarından iyi çıktı. Karar ağacı da naive Bayes'ten biraz iyiydi.
<!-- BELİRSİZ: Sunumun sonunda genel doğruluk için "%9.15" geçiyor (00:38:30); karede doğrulanamadı, Whisper bozması olabilir. -->

Hoca öğrencinin kod yazıp yazmadığını sordu. Öğrenci benzer bir yaklaşımla cilt kanseri teşhisi üzerine çalışmak istediğini, ancak sonuca ulaşamadığını söyledi. Hoca bu tür çalışmaların konferans makalesine dönüştürülebileceğini belirtti.

## 5. GAN ile Sentetik Tıbbi İmge Çoğaltma: Karaciğer Lezyonları

### 5.1 Makale ve veri

Dördüncü sunumda incelenen makale: "GAN-based synthetic medical image augmentation for increased CNN performance in liver lesion classification" (Frid-Adar, Diamant, Klang, Amitai, Goldberger) (ekrandan, 01:00:00). Amaç, bilgisayarlı tomografi (BT) görüntülerinden karaciğer lezyonu sınıflandırmasının başarımını GAN ile üretilen yapay lezyon görüntüleri sayesinde artırmak. Veri 182 lezyon imgesinden oluşuyor: 53 kist, 64 metastaz ve 65 hemanjiyom (53 + 64 + 65 = 182). Veriler bir tıp merkezinden etik kurul onayıyla alınmış, açık veri değil. Lezyon bölgeleri bir radyolog tarafından işaretlenmiş, tanı biyopsi veya klinik takiple doğrulanmış.

Problem: sağlık alanında veri setleri küçüktür, denetimli öğrenme ise geniş ve etiketli veri ister. Klasik veri çoğaltma ek bilgi açısından sınırlı kalıyor, bu yüzden üretici modellerin fayda sağlayabileceği düşünülmüş. Metastazlar kötü huylu, hemanjiyom ve kistler iyi huylu lezyonlardır. Hemanjiyomlarla metastazların birbirine çok benzemesi sınıflandırmayı zorlaştırıyor. Karaciğer metastazın en sık görüldüğü organlardan biri olduğu için başarımı artırmak önemli.

Özette verilen sonuçlar: klasik çoğaltmayla iki ölçütte %78,6 ve %88,4, GAN ile %85,7 ve %92,4.
<!-- BELİRSİZ: Altyazıda bu iki ölçütün adı geçmiyor; büyük olasılıkla duyarlılık ve özgüllük. -->

### 5.2 Sınıflandırıcı CNN

Girdi 64×64 lezyon imgesidir. Parlaklıklar 0-1 aralığına ölçeklenir ve her imgeden ortalama değer çıkarılır. Makaledeki mimari (ekrandan, 01:05:00): 3×3 filtreli 32 kanallı evrişim, alt örnekleme; 3×3@64 evrişim, alt örnekleme; 3×3@128 evrişim, alt örnekleme; 256 nöronlu tam bağlı katman ve 0,5 dropout; 3 sınıflı softmax çıkışı. Her evrişim katmanında aktivasyon ReLU'dur, her evrişimden sonra boyutu küçültmek için max pooling yapılır.

Dropout eğitim sırasında girişlerin belli bir oranını (burada 0,5) rastgele sıfırlar. Sıfırlanmayan girişler, toplamın beklenen değeri değişmesin diye $1/(1-p)$ ile ölçeklenir. $p=0{,}5$ için bu katsayı 2'dir. Dropout aşırı uyumu önler.

Eğitim parametreleri (ekrandan, 01:05:00): batch boyutu 64, öğrenme oranı 0,001, 150 epoch. Optimizasyonda Nesterov momentumlu stokastik gradyan inişi (SGD) kullanılmış: gradyan mevcut konumda değil, momentumun götüreceği ileri konumda hesaplanır. Böylece minimum noktasının üzerinden atlama azalır, minimuma yaklaşırken adımlar yavaşlar.

> **Ders sonrası not:** Altyazıda öğrenme oranı "0.01" geçiyor; slaytta 0,001 yazıyor.

### 5.3 Klasik veri çoğaltma

Klasik çoğaltmada öteleme, döndürme, ölçekleme ve çevirme kullanılmış. Eğme (shearing) pek kullanılmamış, çünkü lezyonların karakteristik özelliklerini bozabiliyor. Her imge 0-180° arası açılarla 30 kez döndürülmüş. Döndürülen her imge 3 kez çevrilmiş (yukarı-aşağı, sağ-sol), 7 kez ötelenmiş ve 5 kez ölçeklenmiş. Öteleme aralığı lezyon yarıçapına bağlı bir $P$ değeriyle belirleniyor. Toplamda her imgeden yaklaşık 480 yeni imge elde ediliyor.

> **Ek bilgi (derste anlatılmadı):** Toplam sayı büyük olasılıkla $N_{rot}\times(1+N_{flip}+N_{trans}+N_{scale}) = 30\times(1+3+7+5)=480$ formülüyle bulunuyor: döndürülen her imge bir kez olduğu gibi tutulur, sonra çevirme, öteleme ve ölçekleme ayrı ayrı uygulanır. Python ile $30\times16=480$ doğrulandı. Sınıf başına yaklaşık 60 imge olduğundan $480\times60=28.800$, yani sunumda söylenen "sınıf başına yaklaşık 30.000 örnek" ile uyumlu.

### 5.4 DCGAN ve AC-GAN

GAN tabanlı çoğaltmada iki mimari denenmiş: Deep Convolutional GAN (DCGAN) ve Auxiliary Classifier GAN (AC-GAN). Üretici rastgele sayılardan oluşan bir girdi alır, ama gerçek imgelerin dağılımını öğrenerek bu dağılıma uygun imgeler üretmeye çalışır. Ayırt edici girdinin gerçek olma olasılığını döndürür. Kayıp fonksiyonu iki oyunculu bir min-max oyunu olarak kurulur. Üretici, ürettiği örneğin ayırt edici tarafından gerçek sayılmasını, yani $1-D(G(z))$'nin küçülmesini ister. Ayırt edici ise gerçek veride çıktısını büyütmeye çalışır.

DCGAN üreticisi 100 rastgele sayıdan oluşan bir vektör alıp 64×64 lezyon imgesi üretir. Önce 4×4×1024 boyutunda tam bağlı bir katman, ardından imgeyi büyüten 4 ters evrişim (deconvolution) katmanı gelir. Ters evrişim, katman pikselleri arasına sıfır ekleyerek büyütme yapar. Çıkış katmanında tanh, diğer katmanlarda ReLU kullanılır. Çıkış katmanı dışındaki her katmanda batch normalization yapılır, yani her mini batch ortalaması 0, varyansı 1 olacak şekilde normalize edilir.

Ayırt edici (ekrandan, 01:10:00) 64×64×1 boyutunda imge alır. 5×5 çekirdekli 4 evrişim katmanı ve bir tam bağlı katman içerir. Giriş ve çıkış katmanı hariç batch normalization uygulanır. Uzaysal boyutu küçültmek için havuzlama yerine her katmanda adımlı evrişim (strided convolution) kullanılmış. Adım sayısı ve neden havuzlamanın tercih edilmediği makalede yazmıyor. Aktivasyon çıkış katmanında sigmoid, diğer katmanlarda Leaky ReLU'dur:

$$f(x) = \max(x,\; \text{leak}\times x), \qquad \text{leak}=0{,}2$$

Leaky ReLU'nun ReLU'dan farkı, negatif girişlerde sıfır yerine küçük bir eğim (leak katsayısı) vermesidir. Örneğin $x=-2$ için çıktı $-0{,}4$ olur (python ile doğrulandı).

DCGAN eğitiminde batch boyutu 64'tür. İmgeler eğitimden önce $[-1,1]$ aralığına ölçeklenmiş, üreticiye de $[-1,1]$ aralığında düzgün dağılımlı örnekler verilmiş. Ağırlıklar sıfır ortalamalı ve 0,02 standart sapmalı normal dağılımla başlatılmış. 70 epoch boyunca Adam optimizer ile eğitilmiş. Adam birinci moment (ortalama) ve ikinci moment (varyans) tahminlerini $\beta_1$, $\beta_2$ parametreleriyle tutar ve her parametre için ayrı bir adım büyüklüğü üretir.

AC-GAN'da ayırt edici gerçek/sahte kararının yanında bir sınıf etiketi de üretir. DCGAN daha iyi sonuç verdiği için makalede AC-GAN'ın mimarisine ayrıntılı girilmemiş. Her lezyon sınıfı için ayrı GAN eğitilmiş.

### 5.5 Deneyler ve sonuçlar

CNN Keras'ta, GAN TensorFlow'da gerçeklenmiş. Eğitim bir GTX 980 Ti GPU'da yapılmış. 3 katlı çapraz doğrulama kullanılmış (her katta yaklaşık 62-63 imge). Ölçütler doğruluk, duyarlılık ve özgüllük. Yalnız klasik çoğaltma "CNN-AUG", klasik çoğaltmanın üzerine DCGAN ile çoğaltma "CNN-AUG-GAN" diye adlandırılmış.

Veri az olduğu için GAN doğrudan ham veriyle eğitilmemiş. Önce klasik yöntemle çoğaltılmış veri elde edilmiş, GAN bu çoğaltılmış veriyle eğitilmiş. Deneyde örnek sayısı 0, 500, 1000 diye artırılarak başarım izlenmiş. Grafikte (ekrandan, 01:15:00):

- Kırmızı çizgi (yalnız klasik çoğaltma): hiç örnek eklenmediğinde doğruluk yaklaşık %57, büyük olasılıkla aşırı uyum yüzünden. Doğruluk hızla artıyor, sonra sabitleniyor. Bu doyma noktası "optimal nokta" diye adlandırılmış: yaklaşık 5000 örnekte %78,6.
- Mavi çizgi (optimal noktadan sonra GAN imgeleri eklenince): doğruluk yaklaşık %85,7'ye çıkıyor, yaklaşık 8000 örnekten sonra yine sabitleniyor.
- Yeşil çizgi: karşılaştırma için tıp merkezinden daha önce kullanılmamış 78 gerçek imge daha alınmış ve klasik yöntemle çoğaltılmış. Bu yalnız yaklaşık %2'lik bir doğruluk artışı sağlamış.

Slayttaki yoruma göre GAN, gerçek örnek eklemeye kıyasla çeşitliliğe daha çok katkı sağlıyor. Son deneyde GAN tabanlı olmayan, sözlük oluşturmaya dayalı bir yaklaşım ve SVM sınıflandırıcı varyasyonları da denenmiş. En iyi sonucu yine GAN vermiş. Yazarların önerdiği geliştirmeler: 2B yerine 3B veriyle çalışmak ve her sınıf için ayrı GAN eğitmenin getirdiği karmaşıklığı azaltmak için çok sınıflı örnek üreten mimarileri incelemek. Yazarlar AC-GAN'ın daha iyi olmasını bekliyormuş, ancak bu çalışmada öyle olmamış.

### 5.6 Hocanın soruları: tavuk-yumurta problemi ve adil karşılaştırma

Hoca, programla (öğrenen bir modelle) veri çoğaltmanın bir "tavuk-yumurta" problemi içerip içermediğini sordu. Nihai amaç sınıflandırma, ancak veri üretmek için de eğitilmiş bir model kullanılıyor. Öğrenci veri az olduğu için GAN'ın da klasik çoğaltmayla elde edilen veriyle eğitildiğini, bu yüzden klasik yöntemin üzerine kurulan GAN'ın başarımı doğal olarak artırdığını söyledi.

> **Hocanın vurgusu:** Burada yapılan yalnız bir karşılaştırma değil. GAN ile elde edilen en iyi sonuç sunuluyor ve GAN zaten klasik çoğaltmanın üzerine kuruluyor. Bu yüzden klasik yöntemle yapılan karşılaştırma çok adil görünmüyor.

Öğrenci GAN'ın her sınıf için ürettiği imgeleri gösterdi. Hoca bu imgelerin anlamlı olup olmadığını bakarak değerlendirmenin zor olduğunu, bunun için çalışılan tıbbi alanı ve veri setini bilmek gerektiğini söyledi.

## 6. Yüz Yaşlandırma: GAN Türleri, Conditional GAN ve CycleGAN

### 6.1 Projenin amacı ve GAN türleri

Beşinci sunumda bir kişinin yaşlı halini üreten bir uygulama anlatıldı. Kod Python ile yazıldı, model Colab'da eğitildi (ekrandan, 01:25:00). Önce GAN'ın yapısı özetlendi: üretici rastgele bir gürültü alıp yukarı örnekleme (up sampling) ile resim üretir, ayırt edici resmin gerçek mi sahte mi olduğuna karar verir.

GAN türleri üç biçimde çeşitleniyor: hata fonksiyonları (WGAN, LSGAN gibi), mimari değişiklikler ve yapılan iş. DCGAN iç yapısında evrişim katmanları kullanır. Progressive Growing GAN eğitime küçük çözünürlükle başlar ve eğitim ilerledikçe ağı büyütür. GAN'lar büyük resim üretmekte zorlanır, bu yöntem bunu aşmak için geliştirilmiş. Conditional GAN'da gürültünün yanında bir sınıf bilgisi de verilir. AC-GAN'da sınıf bilgisi ayırt ediciden çıktı olarak alınır. CycleGAN ise sıfırdan resim üretmek yerine imgeden imgeye çeviri (image translation) yapar.

### 6.2 GAN eğitiminin zorlukları

Slayttaki maddeler (ekrandan, 01:30:00): GAN eğitimi çok zordur, GAN'lar stabil değildir, farklı kayıp fonksiyonları (WGAN gibi) biraz stabilite katar. İki büyük problem mode collapse ve convergence failure'dır. Üretici ile ayırt edici arasında dengesizlik olursa eğitim çöker.

- **Mode collapse:** Üretici yalnız tek tip veri üretmeye başlar. Slayttaki MNIST örneğinde ilerleyen adımlarda bütün örnekler aynı rakama dönüşüyor. WGAN bunu biraz stabilize edebilir. AC-GAN da bu konuda iyidir: ayırt edici sınıf tahmini de yaptığı için tek tip veri üretmek büyük hataya yol açar, bu da çöküşü engeller.
- **Convergence failure:** Üretici veriyi öğrenemez ve gürültü üretir.

Google'ın farklı GAN türlerini karşılaştıran bir çalışmasına göre, farklı bir model ya da farklı bir hata fonksiyonu kullanmak yerine iyi bir hiperparametre optimizasyonu yapıldığında bütün GAN modelleri yaklaşık aynı sonucu verebiliyor. Bu yüzden GAN eğitiminde en önemli adım hiperparametre optimizasyonudur.

### 6.3 Face Aging Conditional GAN

İncelenen ilk makale Face Aging Conditional GAN. Burada üretici gürültü yerine resmin gizil (latent) vektörünü alır. Bu vektör bir otokodlayıcı (autoencoder) ile elde edilir: resim bir darboğaz (bottleneck) katmanına kadar küçültülür, sonra büyütülerek orijinal haline döndürülür. Model orijinal resimle yeniden oluşturulan resim arasındaki farka göre eğitilir ve darboğaz katmanı resmi temsil eden bir vektöre dönüşür. Bu vektör ve koşul olarak yaş grubu üreticiye verilir, yaşlı hal üretilir.

Sorun kimliğin korunmasında. Piksel bazlı (pixel-wise) karşılaştırmayla eğitilen otokodlayıcıda kimlik bilgisinin kaybolduğu görülüyor. Yazarlar bunun için Identity Preservation Optimization (IPO) adlı bir teknik öneriyor. Otokodlayıcı eğitilirken resimler piksel piksel karşılaştırılmaz. Orijinal resim ve yeniden oluşturulan resim yüz tanıma yapan bir modele verilir, iki gömme (embedding) vektörü arasındaki fark kayıp olarak kullanılır. Yüz tanıma modeli kimliği bulmaya çalıştığından otokodlayıcı kimliği korumayı öğrenir. Öğrenciye göre IPO biraz daha iyi sonuç verse de kimlik yine tam korunamıyor.

Slayttaki değerlendirme (ekrandan, 01:35:00):

- Avantajlar: oluşturulacak resmin yaş grubu belirtilebiliyor (örneğin 15 yaşındaki birinin 25, 35 ve 45 yaşındaki halleri ayrı ayrı üretilebilir). Esnek yapısı resim üzerinde daha fazla oynama imkânı sunuyor.
- Dezavantajlar: iki farklı model (GAN ve otokodlayıcı) eğitmek gerekiyor. Kimlik bilgisi yapılan hamlelere rağmen hâlâ kayboluyor. Yaş grubu belirtmek iyi bir özellik, ancak eğitimi karmaşıklaştırıyor.

Proje yalnız yaşlı hali üretmeyi hedeflediği için öğrenci bu yaklaşımı gereğinden karmaşık buldu ve CycleGAN'ı seçti.

### 6.4 CycleGAN

CycleGAN eşleşmemiş (unpaired) imgeden imgeye çeviri algoritmasıdır. İmgeden imgeye çeviri, bir alandaki (domain) resmi başka bir alandaki resme dönüştürmektir. Örneğin gerçek bir fotoğraf farklı ressamların üslubuna taşınabilir. "Eşleşmemiş" şu anlama gelir: gerçek fotoğraf ile Van Gogh alanındaki resmin aynı sahneyi göstermesi gerekmez. Eşleşmiş veri isteyen diğer çeviri yöntemleri veri seti sıkıntısı yaşar, CycleGAN'da bu sıkıntı yoktur.

CycleGAN iki GAN içerir: A alanında resim üreten bir GAN ve B alanında resim üreten bir GAN. Amaç resmin içeriğini koruyarak alanını değiştirmektir. İki GAN ayrı ayrı eğitilirse bu başarılamaz. Bu yüzden ayırt ediciden gelen çekişmeli kaybın yanına iki kayıp daha eklenmiş:

- **Döngü tutarlılığı kaybı (cycle consistency loss):** Fikir doğal dil işlemedeki geri çeviri sınamasına benzer. İngilizce bir metin Türkçeye çevrilir, sonra Türkçe metin yeniden İngilizceye çevrilir ve orijinalle arasındaki farka bakılır. CycleGAN'da da A alanındaki resim B'ye, sonra yeniden A'ya çevrildiğinde aynı ya da çok yakın bir resim elde edilmelidir. Kayıp, döngüden sonraki piksel bazlı ortalama mutlak farktır. Hoca bu yolla ağın iki yönlü geçişi birlikte öğrendiğini (yaşlandırmanın yanında gençleştirmeyi de) belirtti.
- **Özdeşlik kaybı (identity loss):** A'dan B'ye çeviren üreticiye zaten B alanında olan bir resim verilirse, aynı resmi geri vermesi gerekir.

Toplamda üç kayıp vardır: resmin gerçek olup olmadığını öğreten ayırt edici kaybı, iki alan arasındaki ilişkiyi öğreten döngü tutarlılığı kaybı ve alan içi değişimi sınırlayan özdeşlik kaybı.

Mimari (ekrandan, 01:40:00): üretici kodlayıcı-kod çözücü (encoder-decoder) yapısındadır. 7×7 ve 3×3 evrişimlerle resmi küçülterek kodlar, ardından 256 filtreli 3×3 evrişimlerden oluşan ResNet bloklarından geçirir, en sonda ters evrişim katmanlarıyla resmi orijinal boyuta getirir. Projede 9 ResNet bloğu kullanıldı, bu sayı değiştirilebilir. Öğrencinin anlatımıyla bir blokta giriş iki evrişim katmanından geçer, sonuç bloğun girişiyle birleştirilir. Ayırt edici PatchGAN'dır: 4×4 filtreli, adımı 2 olan 64, 128, 256 ve 512 kanallı evrişim katmanlarından ve instance normalization ile Leaky ReLU'dan oluşur, sonda 1 filtreli bir katman ve sigmoid gelir. Slaytta makalede batch boyutunun 1 alınmasının önerildiği yazıyor.

PatchGAN tek bir değer yerine bir matris verir. Matrisin her elemanı resmin belli bir bölümüne, yaklaşık 70×70 piksellik bir bölgeye bakarak o bölgenin gerçek olup olmadığına karar verir. Örneğin 4×4'lük bir çıktı matrisi, resim 70×70'lik parçalara ayrılıp her parça ayrı bir ayırt ediciye verilmiş gibi sonuç üretir. Bu daha iyi sonuç sağlıyor.

> **Ek bilgi (derste anlatılmadı):** PatchGAN çıktısındaki her elemanın baktığı bölge, o elemanın girdideki alıcı alanıdır (receptive field). 70×70 değeri, ayırt edicideki evrişim katmanlarının çekirdek boyutları ve adımları üst üste konunca ortaya çıkan alıcı alan büyüklüğüdür. Bu yüzden resim gerçekten bölünmeden her eleman yalnız kendi yamasını "görür".

CycleGAN'ın avantajı eşleşmemiş veriyle çalışması ve stil aktarımını başarıyla yapmasıdır. Dezavantajları:

- Birebir (one-to-one) eşleme yapar, yalnız iki alan vardır. Farklı yaş grupları için ayrı ayrı CycleGAN'lar eğitmek gerekir (örneğin 15→25, 25→35, 35→45), bu da esnek değildir.
- Üretilen resim üzerinde fazla kontrol yoktur. Örneğin Van Gogh tarzı bir resim üretilirken renk şeması seçilemez. Model alanı nasıl öğrendiyse resmi o alana taşır.

### 6.5 Uygulama ve sonuçlar

Veri seti iki veri setinin birleştirilmesiyle oluşturuldu (ekrandan, 01:45:00). UTK Face 20 binden fazla yüz içeriyor. Flickr Faces HQ 70 binden fazla yüz içeriyor, ancak yaş bilgisi yok. Bu yüzden başka bir projede bir yaş tahmin modeliyle belirlenmiş yaşlar kullanıldı. Kesin yaş gerekmiyordu, çünkü yaşlar zaten gruplanacaktı. Resimler 128×128 boyutuna getirildi. 20-30 yaş arası "genç" (yaklaşık 25 bin, %65), 50 yaş üstü "yaşlı" (yaklaşık 13 bin, %35) olarak alındı. Toplam yaklaşık 38 bin resim kullanıldı. Yaş dağılımı çok dengesizdi, bu yüzden veri setinden kesmeler yapıldı. 50 yaş çok yaşlı sayılmadığından bazı çıktılarda belirgin kırışıklık oluşmadı, yalnız yaş biraz arttı.

Eğitimin ilk 2000-3000 iterasyonunda model resimde neredeyse hiçbir değişiklik yapmadı, yüzün hangi bölgelerinde değişiklik yapacağını öğreniyormuş gibi davrandı. Ardından gerçekçi olmayan değişiklikler başladı, eğitimin sonlarına doğru daha net ve güzel sonuçlar çıktı. Veri setindeki dengesizlikler yüzünden sorunlar görüldü: bazen kadın yüzüne bıyık benzeri izler eklendi, ırksal dengesizlik nedeniyle siyahi kişilerin resimlerinde hiç değişiklik yapılmadığı durumlar oldu.

### 6.6 Hocanın önerisi ve bir öğrencinin yorumu

Hoca, veri setinde aynı kişinin farklı yaşlardaki resimlerinin bulunmadığını teyit etti. Ardından bir öneride bulundu:

> **Hocanın vurgusu:** Önce veri setini sınıflayan bir ön ağ ekleyebilirsin. Cinsiyet, ırk ya da ten rengi gibi temel özellikleri ayırt edip birbirine benzeyen insanları önceden gruplarsan, eğitimi bunun üzerine kurduğunda büyük ihtimalle çok daha başarılı sonuçlar alırsın.

Hoca, 38 bin resmin elle etiketlenmesinin zor olduğunu, ancak Amazon Mechanical Turk gibi kitle hizmetleriyle ücret karşılığı yaptırılabileceğini de ekledi. Başka bir öğrenci kendi çalışmasının da bu fikre yakın olduğunu anlattı. Kendi stil aktarımı çalışmasında çıkarılan özellik vektörleri önce bir gömme uzayına yerleştiriliyor. Yeni veri geldiğinde önce bu gömmeye bakılıp bir koşul atanıyor (örneğin hangi yaş aralığında olduğu), sonra yeniden oluşturma (reconstruction) yapılıyor.

## 7. Video İzleme ile Çelik Köprülerde Yorgunluk Çatlağı Tespiti

### 7.1 Problem

Altıncı sunumda, çelik köprülerdeki yorgunluk çatlaklarını video izleme ile görüntü tabanlı tespit eden bir makale incelendi. Yorgunluk çatlağı, yapının araç yükü ve rüzgâr gibi sürekli değişken yüklere maruz kalması sonucu oluşan çatlaktır. Çatlaklar zamanla büyüyüp yapının çökmesine, can ve mal kaybına yol açabilir. Makale yapı mühendisliği alanında olduğu için daha temel teknikler kullanıyor, ancak doğrudan dersin konusu olan ilgi noktası tespiti ve ilgi noktası izleme yöntemlerine dayanıyor.

Klasik çözüm, çatlakları büyümeden tespit etmek için periyodik denetimdir. Bunun için gözle denetim, akustik emisyon ve piezoelektrik sensörlerle ölçüm gibi yöntemler kullanılıyor. Bunlar zaman ve yoğun emek gerektiriyor, ayrıca güvenilir değil. Alternatif olarak temel görüntü işleme teknikleri kullanılabilir. Bunların başında derste görülen Canny ve Sobel ile kenar bulma geliyor. Slaytta bir çatlak görüntüsüne farklı eşiklerle ($T_P$ = 0,01; 0,02; 0,05; 0,1) uygulanan kenar bulma sonuçları gösterildi (ekrandan, 02:05:00). Küçük eşikte çok fazla gürültü kenarı, büyük eşikte kopuk çatlak kenarı çıkıyor. Daha gelişmiş bir yöntem olan sayısal imge korelasyonu (digital image correlation, DIC) çok etkili, ancak mikroskop, özel ışık kaynakları ve yüzeyin işaretlenmesi gibi pahalı ekipman ve ön hazırlık gerektiriyor.

Önerilen yaklaşım, değişken yük altındaki çelik yüzeyin video kaydından hareketleri görüntü işlemeyle tespit edip izlemektir. Üç adımdan oluşur:

1. İlgi noktası tespiti (feature point detection).
2. İlgi noktalarının video kareleri boyunca izlenmesi (feature tracking).
3. Bu noktalardan yararlanarak çatlak bölgesinin yerelleştirilmesi (localization).

Test düzeneğinde değişken yük uygulayan bir mekanizma, bir kamera ve görüntü işleme sonuçlarını doğrulamak için bir sensör vardı. Kullanılan metal parçada bir yorgunluk çatlağı mevcuttu.

### 7.2 Shi-Tomasi ilgi noktası detektörü

İlgi noktası tespiti araç takibi, görüntü mozaiği, 3B geri çatım ve nesne tanıma gibi birçok alanda kullanılır. Derste Harris, SIFT ve FAST gibi detektörler görülmüştü. Bu uygulamada Shi-Tomasi detektörü kullanılmış. Slayttaki açıklama (ekrandan, 02:10:00): Harris yöntemine benzer, imgenin gradyan değerleriyle ikinci moment matrisi hesaplanır, ilgi bölgeleri bu matrisin özdeğerlerine bağlı olarak belirlenir. Farkı, ilgi bölgelerini belli bir eşik değerine göre seçmesidir.

$$M = \sum_{x,y} w(x,y) \begin{bmatrix} I_x I_x & I_x I_y \\ I_x I_y & I_y I_y \end{bmatrix} \tag{1}$$

$$R = \min\{\lambda_1, \lambda_2\} > \text{cutoff threshold} = q \times R_{\max} \tag{2}$$

Harris'te köşe ölçütü determinant ve izden hesaplanıyordu. Shi-Tomasi ise iki özdeğerden küçük olanını doğrudan ölçüt olarak alır ve en yüksek değerlerin bir oranını eşik olarak kullanır. Slayttaki kartal resminde Harris çok daha fazla nokta buluyor. Shi-Tomasi ise öğrencinin yorumuyla en iyi noktaları bulmak için tasarlanmış. Python'da OpenCV'nin `cv2.goodFeaturesToTrack()` fonksiyonu hem Harris hem Shi-Tomasi ile nokta tespiti yapabiliyor.

> **Hocanın vurgusu:** Harris'te determinant ve iz (trace) kullanılması hızlandırmak için düşünülmüş bir şeydir. Shi-Tomasi "ben doğrudan özdeğeri kullanırım" diyor.

Makalede önce bir ilgi bölgesi (region of interest, ROI) seçiliyor, Shi-Tomasi bu bölgede uygulanıyor. Bulunan her noktanın etrafındaki 11×11 piksellik yamalar üzerinde işlem yapılıyor.

### 7.3 KLT izleyici

İkinci adım, tespit edilen noktaların video kareleri boyunca nasıl hareket ettiğinin analizidir. Örneğin videoda hareket eden bir aracın izlediği yol çizgilerle gösterilebilir. Makalede Kanade, Lucas ve Tomasi'nin geliştirdiği KLT izleyicisi kullanılmış. Yöntem tek seferde ortaya çıkmamış: önce Lucas ve Kanade yöntemi geliştirilmiş, 1991'de bugünkü KLT algoritması ortaya çıkmış, 1994'te Shi ve Tomasi "iyi izlenecek özellikler" (good features to track) yöntemini geliştirmiş.

Slayttaki algoritma (ekrandan, 02:15:00):

1. $\min(\lambda_1,\lambda_2) > \lambda$ koşulunu sağlayan köşeleri bul.
2. Her köşe için sonraki kareye yer değiştirmeyi Lucas-Kanade yöntemiyle hesapla.
3. Her köşenin yer değiştirmesini kaydet, köşe konumunu güncelle.
4. (İsteğe bağlı) Her M karede bir, 1. adımı kullanarak yeni köşe noktaları ekle.
5. 2-3. (ve 4.) adımları tekrarla.
6. Her köşe noktası için uzun yörüngeler (trajectories) döndür.

Yani ilk karede ilgi noktaları tespit edilir, sonraki karede her noktanın etrafında arama yapılır, bulunan yeni koordinattan arama sonraki karelerde sürer. Yer değişimi bir vektör olarak kaydedilir. Nesne yalnız yatay ve dikey hareket etmez, kameraya yaklaşıp uzaklaşabilir de. Bunun için derste görülen Gauss farkı (DoG) ölçek uzayına benzer biçimde alt örneklenmiş seviyelerde de arama yapılır. Bu hesaplama maliyetini artırır, ama videoda yakınlaşma ve uzaklaşma kaçınılmaz olduğu için gereklidir.

> **Ek bilgi (derste anlatılmadı):** Lucas-Kanade yöntemi, küçük bir pencere içindeki bütün piksellerin aynı hareketi yaptığını varsayar ve parlaklık sabitliği denkleminden $M\,[u\;v]^T = -\sum w\,[I_x I_t\;\; I_y I_t]^T$ biçiminde bir sistem kurar. Buradaki $M$, Shi-Tomasi'deki ikinci moment matrisinin aynısıdır. Bu yüzden iki özdeğeri de büyük olan noktalar izleme için en güvenilir noktalardır. Alt örneklenmiş seviyelerde arama yapmaya piramit (pyramidal) Lucas-Kanade denir.

### 7.4 Çatlak yerelleştirme

İlk karede çok sayıda ilgi noktası bulunur, ama yalnız çatlak çevresindekiler gereklidir. Bunları ayırmak için her noktanın değişken yük altındaki hareketi zamana bağlı bir eğriye dönüştürülür. Slayttaki formüller (ekrandan, 02:20:00):

$$x_r^i(t) = x^i(t) - x^i(1), \qquad y_r^i(t) = y^i(t) - y^i(1) \tag{3}$$

$$\delta^i(t) = \sqrt{x_r^i(t)^2 + y_r^i(t)^2} \tag{4}$$

Burada $x_r^i, y_r^i$, $i$. noktanın ilk kareye göre göreli konumu, $\delta^i(t)$ ise yer değiştirmenin büyüklüğüdür. Her nokta için bir yerel dairesel bölge (localized circular region, LCR) tanımlanır. Bu bölgedeki komşu noktaların hareketi merkez noktanın hareketiyle karşılaştırılır: merkez noktanın eğrisi komşularınkinden çıkarılır ve farkın standart sapması ($S$) alınır. Standart sapmalar değişim katsayısı (coefficient of variation, CV) ile tek bir sayıl değere dönüştürülür. $CV > \Gamma$ eşiğini geçen noktalar çatlak çevresindeki noktalar olarak işaretlenir.

Slayttaki örnekte LCR 1 (nokta 1-7) çatlaksız bölgededir. Komşular merkez nokta 1 ile aynı hareketi yaptığından farklar düz çizgi verir, CV küçük çıkar. LCR 2'de (nokta 21-26) merkez nokta 21'dir. 22, 23 ve 24 numaralı noktalar çatlağın aynı (üst) tarafında olduğu için 21'e göre farklı hareket etmez. Çatlağın diğer tarafındaki 25 ve 26 numaralı noktalar az da olsa farklı salınır. Bu yüzden CV eşiğin üstüne çıkar ve bu bölge işaretlenir. Son olarak çatlak bölgesi iki kutucukla işaretlenir. İki kutucuk arasındaki hareket farkından çatlağın boyutu kestirilir: hareket farkı ne kadar büyükse çatlak o kadar büyüktür.

### 7.5 Hocanın sorusu ve canlı demo

Hoca yaklaşımın nasıl çalıştığını sorguladı: rijit bir yapıda süreklilik vardır, çatlaktaki noktalar neden farklı hareket etsin? Öğrenci, OpenCV'deki hazır KLT örneğiyle telefon kamerasından canlı bir demo yaptı. Program en güçlü 10 ilgi noktasını bulup kareler boyunca izliyordu. Öğrenci koda tek bir ekleme yapmıştı: noktalar ekrandan kaybolunca program hata veriyordu, artık yeni noktalar tespit ediliyor. Kağıt üzerindeki noktalar ile kağıdın kenarı dışındaki noktalar, kağıt oynatıldığında farklı hareket ediyordu. Öğrenciye göre çatlağın iki yakası da birbirinden bağımsız iki yapı gibi düşünülebilir, aradaki hareket farkı küçük de olsa ölçülebilir. Hızlı kamera hareketinde izleyici noktaları kaybediyor.

> **Hocanın vurgusu:** İzleme (tracking), yani video üzerinde noktaların ya da nesnelerin izlenmesi, bilgisayarla görmenin önemli bir uygulamasıdır. Optik akış ve KLT izleyicileri gibi önemli konular var. Bu sunum konuya kısa bir giriş oldu.

## 8. TRUBA Altyapısında Derin Öğrenme

### 8.1 TRUBA nedir

Yedinci sunum bir makaleye dayanmıyordu. TÜBİTAK'ın yüksek başarımlı hesaplama altyapısı TRUBA'nın (Türkiye Ulusal Bilimsel e-Altyapısı) derin öğrenme için kullanımı tanıtıldı. Üyelik e-Devlet ile yapılıyor, akademisyen, araştırmacı ya da doktora öğrencisi olunduğu YÖKSİS entegrasyonundan anlaşılıyor. Sunuma göre yoğunluk nedeniyle lisans ve yüksek lisans öğrencilerine kullanım kapatılmış. Varsayılan kaynak 128 çekirdeğe kadar kullanım, toplam 4000 çekirdek saati ve 1 TB disk kotası. Ek kaynak e-posta ile ücretsiz isteniyor. Karşılığında yayınlarda TRUBA'ya teşekkür edilmesi (acknowledgement) ve yayının sisteme eklenmesi isteniyor. Sunucuya ULAKNET'e bağlı bir bilgisayardan doğrudan, dışarıdan OpenVPN ile bağlanılıyor. Open OnDemand teknolojisi sayesinde sistem tarayıcıdan da kullanılabiliyor.

Web arayüzünün üst menüsü (ekrandan, 02:35:00):

- **Files:** dosya sistemi ve dizinlere ulaşım, yükleme/indirme, düzenleme/silme, terminal açma.
- **Jobs:** aktif çalışan işlerin görüntülenmesi ve yeni iş oluşturulması.
- **Clusters:** TRUBA kabuk ekranının açılması.
- **Interactive Apps:** hazır sistemler ve yazılımlar (TRUBA Desktop, GNUPLOT, MATLAB, RStudio, VMD, Jupyter Notebook).
- **Non-Interactive Apps:** Gaussian uygulaması.
- **My Interactive Sessions:** çalışan uygulamalar ve çalışması bitmiş ama günlüğü (log) görülebilen uygulamalar.

Jupyter Notebook başlatılırken hesap adı, çalışma süresi (saat) ve düğüm sayısı girilir. İstenen kaynak arttıkça bekleme süresi uzayabilir. Her yeni oturum boş bir ortamla açıldığı için gerekli kütüphaneler ilk seferde kurulmalı.

### 8.2 Örnek uygulama

Öğrenci yaklaşık 500 imgelik ve 7 sınıflı bir veri setiyle çalıştı. Veri az olduğu için veri çoğaltma yapıldı. Model Keras ile kendisi yazdığı bir CNN'di: evrişim, dropout, max pooling ve dense katmanları. Ara katmanlarda ReLU, 7 sınıf olduğu için çıkış katmanında softmax kullanıldı. Softmax ile uyumlu kayıp olarak `categorical_crossentropy` seçildi. Optimizer olarak RMSprop kullanıldı; Adam da denenmiş, daha kötü sonuç vermiş. Ekrandaki kod (ekrandan, 02:40:00):

```python
optimizer = RMSprop(lr=0.001, rho=0.9, epsilon=1e-08, decay=0.0)
#optimizer=Adam(learning_rate=0.001, beta_1=0.9, beta_2=0.999, epsilon=1e-07),
model.compile(loss='categorical_crossentropy',
              optimizer = optimizer,
              metrics=['accuracy'])

model.fit_generator(
    train_generator,
    steps_per_epoch=100,
    epochs=100,
    validation_data=validation_generator,
    validation_steps=100,
    callbacks=[callback])
```

Eğitimde 100 epoch kullanıldı, her epoch ve doğrulama 100 adımdan oluşuyordu. Ek olarak, doğrulama doğruluğu 0,7'yi geçince eğitimi durduran bir callback fonksiyonu yazıldı. Model iyi sonuç vermedi. Öğrenciye göre nedenler: 7 sınıf için toplam yaklaşık 500 imgenin yetersizliği ve sınıflar arasında gözle görülür benzerlikler olması, yani ayırt edici özelliklerin az olması.

### 8.3 Değerlendirme

Sunumda TRUBA'nın avantajları: yeterli kaynağı olmayan araştırmacıların derin öğrenme ve büyük veri çalışmaları yapabilmesi, ücretsiz olması ve verinin sistemde kalıcı tutulabilmesi (Colab'da verinin sürekli yeniden yüklenmesi gerekiyor). Dezavantajları: sistemin henüz stabil olmaması, sık hatalar, sınırlı dokümantasyon ve Colab'a göre daha yavaş sonuç vermesi. Hoca, öğrencinin GPU'lu bir kümeye erişim için ek kaynak istemesinin ve sonucu paylaşmasının yararlı olacağını söyledi. Ayrıca araştırmacılar için güçlü donanıma erişimin önemli bir sorun olduğunu belirtti.

## Örnek Sorular

**Soru 1** (derste sözlü, 00:22:44): Gri tonlamalı bir resimden orijinal renkli resmi kesin olarak elde etmek mümkün müdür?

> **Çözüm (derste verildi):** Hayır. Renkli resim griye çevrilirken bilgi kaybolur; farklı renkler aynı gri değere düşebilir. Model ancak eğitim verisinden öğrendiği olası (makul) renkleri atayabilir. Golden Gate örneğinde kulelerin gerçek rengi tutturulamadı.

**Soru 2** (derste sözlü, 00:25:28): Renkli bir resim griye nasıl çevrilir? Renklendirme veri seti hazırlarken bunun önemi nedir?

> **Çözüm (derste verilmedi):** En basit yöntem üç kanalın aritmetik ortalamasıdır: $Y=(R+G+B)/3$. Yaygın kullanılan diğer yöntem, gözün yeşile daha duyarlı olmasını hesaba katan ağırlıklı toplamdır (ITU-R BT.601): $Y = 0{,}299R + 0{,}587G + 0{,}114B$. Örneğin saf kırmızı (255, 0, 0) ortalamayla 85, ağırlıklı yöntemle yaklaşık 76 gri değerine düşer (python ile hesaplandı). Eğitim çiftlerinde kullanılan dönüşüm ile modelin sonradan karşılaşacağı gerçek siyah-beyaz fotoğrafların oluşum biçimi farklıysa model büyük olasılıkla daha kötü genelleşir.

**Soru 3** (derste sözlü, 01:18:02): Karaciğer lezyonu çalışmasında sınıflandırma başarımını artırmak için GAN ile veri üretiliyor. Burada bir "tavuk-yumurta" problemi var mı? Klasik çoğaltmayla yapılan karşılaştırma adil mi?

> **Çözüm (derste verildi):** Nihai amaç sınıflandırma, ama veri üretmek için de eğitilmiş bir model kullanılıyor. GAN, az veri nedeniyle klasik yöntemle çoğaltılmış veriyle eğitildi ve GAN imgeleri klasik çoğaltmanın doyduğu noktanın üzerine eklendi. Bu yüzden "klasik" ile "klasik + GAN" karşılaştırması tam adil değil, çünkü GAN tarafı klasik çoğaltmayı zaten içeriyor.

**Soru 4** (derste sözlü, 01:40:58): CycleGAN'da kullanılan PatchGAN ayırt edicisi resmi 70×70'lik parçalara böldüğü için daha mı hızlıdır?

> **Çözüm (derste verildi):** Hayır, hızı normaldir. Resim gerçekte parçalara bölünmez; resmin tamamı verilir ve çıktı bir matris olur (örneğin 4×4). Matrisin her elemanı girdinin yaklaşık 70×70'lik bir bölgesine karşılık gelir, yani sonuç resim parçalara bölünüp ayrı ayrı değerlendirilmiş gibidir.

**Soru 5** (derste sözlü, 02:09:46): Shi-Tomasi detektörünün Harris'ten farkı nedir?

> **Çözüm (derste verildi):** İkisi de aynı ikinci moment matrisi $M$'yi kullanır. Harris köşe ölçütünü $M$'nin determinantı ve izinden hesaplar; bu, özdeğerleri açıkça hesaplamadan hızlı sonuç almak içindir. Shi-Tomasi doğrudan $R=\min(\lambda_1,\lambda_2)$ ölçütünü kullanır ve $R > q\times R_{\max}$ olan noktaları seçer (ekrandan, 02:10:00).

**Soru 6** (derste sözlü, 02:16:46): Rijit bir çelik parçada çatlak çevresindeki ilgi noktaları neden komşularından farklı hareket eder? Yöntem çatlağı nasıl yakalar?

> **Çözüm (derste verildi):** Çatlak parçayı yerel olarak iki yakaya ayırır. Değişken yük altında iki yaka birbirine göre az da olsa farklı salınır. Çatlaksız bölgede komşu noktaların merkez noktaya göre farkı düz bir çizgi verir. Çatlağın karşı yakasındaki noktaların farkı ise salınım gösterir. Farkların standart sapmaları değişim katsayısına (CV) dönüştürülür; $CV>\Gamma$ olan bölgeler çatlak olarak işaretlenir (ekrandan, 02:20:00).

## Dersin Toparlaması

Bu derste yedi öğrenci sunumu üzerinden bilgisayarla görmenin güncel uygulamaları görüldü. Önceden eğitilmiş VGG16 ağının özellik çıkarıcı olarak kullanılması, transfer öğrenmenin en basit biçimini gösterdi. GAN tabanlı üç çalışma (DeOldify ile renklendirme, karaciğer lezyonu için sentetik veri çoğaltma ve CycleGAN ile yüz yaşlandırma), üretici-ayırt edici yapısını, NoGAN, DCGAN, AC-GAN, Conditional GAN ve CycleGAN gibi türevleri, döngü tutarlılığı ve özdeşlik kayıplarını, PatchGAN'ı ve mode collapse gibi eğitim sorunlarını somutlaştırdı. Hocanın soruları bu çalışmaların sınırlarına dikkat çekti: renklendirmede gri tonlamadaki bilgi kaybı, GAN ile çoğaltmada adil olmayan karşılaştırma ve "tavuk-yumurta" sorunu, tıbbi imgelerde alan bilgisinin gerekliliği, dengesiz veri setinde ön sınıflandırmanın yararı.

Papaya hastalığı çalışması, derin öğrenme kullanmadan histogram eşitleme, L\*a\*b\* renk uzayı, k-means segmentasyonu, istatistiksel ve GLCM doku özellikleri ve SVM ile kurulan klasik bir işlem hattını gösterdi. Çelik köprü çalışması ise dersin ilgi noktaları konusunu videoya taşıdı: Shi-Tomasi detektörü, KLT izleyicisi ve komşu noktaların hareket farkından değişim katsayısıyla çatlak yerelleştirme. Hoca, derste ayrıca işlenemeyen izleme ve optik akış konularının önemine dikkat çekti ve bu sunumun bu konulara bir giriş olduğunu belirtti. Son sunum, derin öğrenme çalışmaları için TRUBA altyapısını ve basit bir Keras CNN eğitim kurgusunu tanıttı.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
