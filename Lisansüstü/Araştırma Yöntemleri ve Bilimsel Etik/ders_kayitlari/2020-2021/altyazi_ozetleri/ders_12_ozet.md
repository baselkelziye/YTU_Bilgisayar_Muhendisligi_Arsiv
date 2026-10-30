# Ders 12 Çalışma Özeti

## Genel Konular

- Bu ders (3 Haziran 2021) dönem projesi sunumlarının üçüncü haftasıdır. Konu anlatımı yoktur.
- Öğrenciler çoğunlukla TÜBİTAK 1002 Hızlı Destek Programı formatında hazırladıkları araştırma projesi önerilerini sunar.
- Hoca fakültedeki bir toplantı nedeniyle derse biraz geç başlar.
- Bu derste 8 sunum yapılır:
  - 1. sunum: Görme engelliler için derin öğrenme tabanlı mobil yol asistanı (dokunsal parke yüzeyi tespiti).
  - 2. sunum (grup 3): CNC tezgahlarında çarpışmaların derinlik kamerası ve görüntü işleme ile önceden tespiti.
  - 3. sunum (grup 5): Kolon kanseri histopatolojik görüntülerinde hücre çekirdeklerinin sınıflandırılması.
  - 4. sunum (grup 7): Yapay sinir ağları ile güncel saldırıların ve sıfırıncı gün (zero-day) ataklarının tespiti.
  - 5. sunum (grup 17): Düşme tespiti yöntemiyle deprem enkazı tespit eden mobil uygulama.
  - 6. sunum (grup 20): Çevrim içi ve çevrim dışı imza doğrulamanın birleştirilmesi (İngilizce).
  - 7. sunum (grup 28): Veri ambarında kişisel veri tespiti için uygulama geliştirme.
  - 8. sunum (grup 30): Büyük veri ile makine öğrenmesi teknikleri: CNN ile hava tahmini (İngilizce).
- Hiçbir sunumdan sonra dinleyicilerden soru gelmez.

## Hocanın Özellikle Vurguladığı Kısımlar

- **Soru-cevap:** Hoca her sunumdan sonra soru olup olmadığını sorar. Soru gelmeyince "herhalde her zaman olduğu gibi soru yok" diyerek bu durumu yine hatırlatır.
- **Risk yönetimi gerçek hayatta:** 7. sunumda grubun bir üyesi kaydını dondurduğu için sunum tek kişiyle yapılır. Sunumdaki risklerden biri de "ekipten birinin projeden ayrılması"dır. Hoca "senin risklerden biri aslında gerçekleşti" der. Sunan öğrenci, rapor hocaya nasıl teslim edildiyse sunumun da öyle kalması için ekibi değiştirmediğini açıklar; hoca bunu uygun bulur.
- **Sunum düzeni:** Hoca grupları numara sırasıyla çağırır, ekran paylaşım yetkisini verir ve sunuma geçer.

## Kısa Tekrar Notları

- Sunumların ortak iskeleti TÜBİTAK proje önerisi bölümleridir:
  - Konunun önemi ve özgün değer
  - Amaç, hedefler ve başarı ölçütleri
  - Yöntem
  - İş paketleri, zaman planı ve her iş paketinin projeye katkı oranı
  - Risk yönetimi (B planı)
  - Yaygın etki: akademik, ekonomik, sosyal, ulusal güvenlik çıktıları
  - Bütçe: makine-teçhizat, hizmet alımı, bursiyer, seyahat, danışmanlık
- İyi bir risk tablosu her risk için somut bir B planı verir:
  - Veri yetersizliği: sentetik veri üretimi, hazır etiketli veri setleri, veri artırma.
  - Başarı ölçütünün tutturulamaması: hiperparametre ayarı, farklı mimari.
  - Kişi kaybı: aynı yetkinlikte yeni bir araştırmacının bursla projeye alınması.
- Sunumlarda geçen önemli kavramlar:
  - Uçuş süresi (Time of Flight, ToF) derinlik kamerası
  - Nokta bulutu kaydı (point cloud registration), ICP
  - Topluluk öğrenmesi (ensemble learning)
  - İmza tabanlı ve anomali tabanlı saldırı tespiti
  - Yanlış kabul oranı (FAR) ve yanlış ret oranı (FRR)
  - ETL ve yükleme logları

## Detaylı Açıklamalar

### 1. sunum: Görme engelliler için mobil yol asistanı

- **Problem:** Görme engelliler için yollara dokunsal parke yüzeyleri (tactile paving) döşenir. Bu yüzeyler yanlış döşenebilir ya da üzerlerinde engel olabilir.
  - Baston yerdeki engeli algılar, ama baş hizasındaki bir engeli (ör. alçak bir üst geçit) algılayamaz.
  - Sunuma göre görme engellilerin kazalarının büyük kısmı çarpma ve düşmeden kaynaklanır.
- **Amaç:**
  - Dokunsal parke yüzeyini tespit etmek.
  - Yüzeyin üzerindeki engeli algılamak.
  - Kullanıcıyı sesli olarak uyarmak.
  - Bunları ek donanım olmadan yalnızca cep telefonuyla yapmak.
- **Literatür analizi (slayttaki tablo):**

| Yöntem | Doğruluk | FPS | Ürün |
| --- | --- | --- | --- |
| Canny, Laplace, Sobel kenar bulma ve karar ağaçları | %88,48 | 16,27 | - |
| Gri seviyeli eş-oluşum matrisi (GLCM) ve SVM | - | - | - |
| Çok renkli segmentasyon ve Kirsch kenar bulma | - | 2 | - |
| OpenCV ile geleneksel görüntü işleme | %91,65 | 10,51 | Derinlik kamerası ve mikrodenetleyici kartı |
| YOLOv3-Dense (grubun önceki çalışması) | %92 (mAP) | 60 | - |

- **Özgün değer:**
  - Önceki çalışmalar ek donanım ister ve düşük FPS ile çalışır.
  - Grubun kendi oluşturduğu 4580 etiketli görüntülük bir veri seti vardır. Bu veri setinde iç ve dış mekan görüntüleri bulunur.
  - Bilgisayarda 60 FPS ile çalışan YOLOv3-Dense modeli mobil ortama taşınacaktır.
- **Yöntem ve iş paketleri:**
  - Altyapı çalışmaları: %10
  - Veri setinin 4 katına çıkarılması: %20
  - Modellerin belirlenmesi ve eğitimi: %25
  - Modelin mobil uygulamaya aktarılması (iOS ve Android, native ya da cross-platform): %35
  - Arayüz tasarımı ve uygulamanın markette yayımlanması: %10
  - Uygulamaya sesli asistan özelliği de eklenecektir.
- **Riskler ve B planları:**
  - Veri seti 4 katına çıkarılamazsa (ör. pandemi): Unity gibi simülasyon ortamlarında yapay veri üretilecek.
  - Doğruluk en az %3 artırılamazsa: katman sayısı, hiperparametreler ve optimizasyon yöntemi değiştirilecek. Olmazsa mevcut model kullanılacak.
  - Mobilde en az 30 FPS sağlanamazsa: doğruluktan biraz feragat edilip katman sayısı azaltılacak.
- **Çıktılar ve etki:** Bir konferans bildirisi ve markette yayımlanan bir uygulama. Görme engellilerin yaşam kalitesine katkı. Sunumda 11. Kalkınma Planı'nın ilgili maddelerine de atıf yapılır.
- **Bütçe:**
  - TÜBİTAK'tan talep: yaklaşık 40.807 TL. Kalemler: MacBook Pro, iPhone ve Android test cihazları, geliştirici hesapları, danışmanlık.
  - Kurum katkısı: yaklaşık 44.560 TL (derin öğrenme bilgisayarı, aksiyon kameraları).
  - Toplam: yaklaşık 85.368 TL.

### 2. sunum (grup 3): CNC tezgahlarında çarpışma önleme

- **Problem:** CNC tezgahları G-code ile programlanır. İşleme sırasında eksenler birbirine, iş parçasına ya da bağlantı elemanlarına çarpabilir. Bu da maddi kayba yol açar.
  - Nedenler: iş parçasının yanlış yerleştirilmesi, takım ofset ayarlarının yanlış yapılması, malzemeye uygun olmayan hız veya derinlik.
  - Sunumda 2012'de Almanya'da 150 CNC yangınının incelendiği bir çalışmaya atıf yapılır. Bu çalışmada çarpışma ("bindirme") yaklaşık %12'lik pay alır.
- **Mevcut çözüm:** Titreşim sensörleri. Çarpışma olunca titreşim artar, sensör makineyi durdurur. Ancak önlem çarpışmadan sonra alındığı için kayıp tam önlenemez.
- **Önerilen yaklaşım:**
  1. Tezgahın içi iki derinlik kamerasıyla 3B olarak modellenir.
  2. G-code'dan eksenlerin hareket koordinatları çıkarılır.
  3. Koordinatlar 3B kamera görüntüsüyle karşılaştırılır.
  4. Çarpışma öngörülürse operatör uyarılır.
- **Teknik ayrıntılar:**
  - Kamera: Microsoft Azure Kinect DK. RGB görüntüyle birlikte her pikselin uzaklığını verir.
  - Derinlik ölçümü uçuş süresi (Time of Flight) yöntemiyle yapılır: yansıyan kızılötesi ışığın dönüş süresi ölçülür.
  - Kalibrasyon satranç tahtasına benzeyen bir kalibrasyon tahtasıyla yapılır.
  - İki kameranın nokta bulutları nokta bulutu kaydı (point cloud registration) ile birleştirilir. Bunun için ICP (Iterative Closest Point) kullanılacaktır.
  - Gereksiz noktalar arka plan çıkarma (background subtraction) ile atılır.
  - Segmentasyonda bölge tabanlı (region-based) yöntem kullanılacaktır.
- **Hizmet alımı:** G-code ve test danışmanlığı için bir otomasyon firması, gerçek ortam testi için CNC kiralama.

### 3. sunum (grup 5): Kolon kanseri görüntülerinde çekirdek sınıflandırma

- **Konu:** Histopatoloji, doku ve hücre değişikliklerinin mikroskopla incelenmesidir. Kanser teşhisinde önemlidir. Hücre çekirdeklerinin sınıflandırılması, hücrelerin homojen olmayan yapısı nedeniyle zordur.
- **Literatür:** Yerel ikili örüntü (Local Binary Pattern, LBP), yönlü gradyan histogramı (HOG) ve Gabor gibi öznitelikler kullanılmış. Sunuma göre bu yöntemlerin başarısı yeterli değil.
- **Yöntem:**
  - Evrişimsel sinir ağının (CNN) evrişim katmanlarıyla öznitelik çıkarılır.
  - Öznitelik sayısı azaltılır.
  - SVM, yapay sinir ağı ve rastgele orman (random forest) ile sınıflandırma yapılır.
  - Sınıflandırıcıların kararları topluluk öğrenmesi (ensemble learning) ile birleştirilir.
- **Veri:** Kalın bağırsak kanserine ait 100 boyanmış histoloji görüntüsü, en az 22.000 çekirdek. Etiketler: epitel, inflamatuar, fibroblast ve "çeşitli".
- **İş paketleri (7 adet):**
  1. Etiketleme modülü
  2. Çekirdeklerin ayrıştırılması
  3. Veri kümesinin oluşturulması
  4. CNN ile öznitelik çıkarma
  5. Sınıflandırma algoritmaları
  6. Literatürle karşılaştırma
  7. Raporlama
- **Riskler:**
  - Sağlık verisinin mahremiyeti: diferansiyel mahremiyet (differential privacy) gibi çözümler.
  - Çekirdeklerin etiketlenememesi: hazır etiketli veri setleri.
  - Hesaplama yükünün aşılması: yüksek başarımlı hesaplama ortamı.
- **Etki:** Kongre bildirisi, dergi makalesi, kanser teşhisine yardımcı yazılım modülleri.

### 4. sunum (grup 7): Sıfırıncı gün ataklarının tespiti

- **Arka plan:** Saldırı tespit sistemleri (intrusion detection system, IDS) iki türdür:
  - Kötüye kullanım (imza) tabanlı tespit: Snort ve Bro gibi kural tabanlı sistemler. Bilinen saldırıları yakalar.
  - Anomali tabanlı tespit: normal dışı davranışı yakalar, ama yanlış pozitif oranı yüksektir.
  - Snort 1998'de geliştirilmeye başlanmış, açık kaynaklı (GPLv2) bir sistemdir. Snort imzasındaki `content` parametresi paketin yükünü (payload) denetler.
- **Sıfırıncı gün atağı:** Daha önce görülmemiş ataktır. Örnek: Stuxnet (2010).
- **Araştırma sorusu:** Güncel ve sıfırıncı gün ataklarını tespit eden bir sistem yapılabilir mi?
- **Literatürdeki eksikler ve özgün değer:**
  - Literatürde eski veri setleri (KDD Cup 99, NSL-KDD) çok kullanılır. Grup Kanada Siber Güvenlik Enstitüsü'nün (CIC) 2017 ve 2018 veri setlerini kullanacak.
  - Birçok çalışma yalnızca belirli saldırı türlerine (botnet, kaba kuvvet vb.) odaklanır.
  - Çalışmalar genelde yalnızca istatistiksel özniteliklerle model eğitir. Grup bunlara Snort ile yapılan paket içeriği analizini de ekleyecek. Asıl özgün değer budur.
- **Yöntem:**
  - Ham paketler SplitCap ile bölünür.
  - Paketler Snort'tan geçirilir. Snort her paket için bir vektör döndürür.
  - Bu vektörler istatistiksel özniteliklerle birleştirilir.
  - Çok katmanlı algılayıcı (MLP) ve otomatik kodlayıcı (autoencoder) eğitilir.
  - Sonuç Snort'un tek başına performansıyla karşılaştırılır.
- **İş paketleri (10 ay):** veri inceleme, öznitelik uzayının oluşturulması (Snort `content` parametrelerinden yeni imza kümesi), veri parçalama, veri setinin oluşturulması, model eğitimi.
- **Risk:** Snort imzalarının lisansının iptali. B planı: başka kuruluşların paylaştığı imza kümeleri.
- **Etki:** SCI dergi makalesi. Başarılı olursa kamu kurumlarında kullanım ve ticari ürün.

### 5. sunum (grup 17): Düşme tespitiyle enkaz tespit uygulaması

- **Problem:** Depremden sonra yardımın enkaz bölgesine hızlı ve doğru ulaşması.
- **Literatür:** Düşme tespiti çalışmaları çoğunlukla yaşlıların düşmesi ve hareket sınıflandırması üzerinedir. Düşme tespitini enkaz tespitine uygulayan çalışma bulunmamaktadır.
- **Hedefler:**
  - Mobil cihazların %90'ını kapsayan bir uygulama.
  - Yüksek doğruluklu bir düşme tespiti modeli.
  - Sunucu tabanlı iletişim altyapısı.
  - Enkaz altındaki yaklaşık kişi sayısının tahmini.
- **Yöntem:**
  - **Model:** MobiFall veri kümesi kullanılır (ivmeölçer ve jiroskop verisi, 4 düşme türü, 9 günlük aktivite). Literatürde en iyi sonuçları KNN ve SVM vermiştir. Grup ikisini de deneyecek.
  - **Uygulama akışı:**
    1. Sensör verisi modele verilir.
    2. Düşme yoksa uygulama çalışmaya devam eder.
    3. Düşme varsa bir süre beklenir: kişi korunma pozisyonu almış olabilir.
    4. Bekleme sonunda düşme durumu sürüyorsa acil durum mekanizması tetiklenir; kişi ve konum bilgisi sunucuya gönderilir.
  - **Mobil enkaz belirleme algoritması (MEBA):** Gelen konumlar diğer kullanıcıların konumlarıyla bir çember içinde karşılaştırılır. Kandilli Rasathanesi'nden gelen deprem merkez üssüyle yakınlık kontrol edilir. Yakınlık eşiğini bir jeofizik mühendisi danışman belirleyecek.
- **Riskler:**
  - İnternet kesintisi: sürekli yeniden deneme, olmazsa Bluetooth.
  - Kullanıcının izin vermemesi: bilgilendirme mesajları.
  - Bölgede az kullanıcı olması: doğrudan Kandilli verisiyle kontrol.
  - Sunucunun aşırı yüklenmesi: yeni sunucu ve yük dengeleyici (load balancer).
  - GPS arızası: çevredeki cihazlardan Bluetooth ile konum.
- **Çıktılar:** Bir dergi makalesi, 3 konferans bildirisi, MEBA için patent, bir yüksek lisans bursiyeri.
- **Bütçe:** Toplam yaklaşık 31.288 TL (monitör, taşınabilir disk, sunucu kiralama, geliştirici hesapları, 1000 TL seyahat, 6600 TL burs, jeofizik danışmanı).

### 6. sunum (grup 20): Çevrim içi ve çevrim dışı imza doğrulama

- Sunum İngilizce yapılır. Altyazının büyük kısmı bozuk ya da döngüye girmiş. Aşağıdakiler anlaşılan kısımlar ve slayttır.
- **Konu:** İmza analizi iki türdür:
  - Çevrim içi (online): imza atılırken kamera veya hassas tablet ile kaydedilir.
  - Çevrim dışı (offline): taranmış imza görüntüsü.
- **Yöntem:**
  - Çevrim içi öznitelik: video karelerinde kalem ucunun izlenmesi (pen tip tracking). Ön işleme: gürültü süzme, ikilileştirme (binarization), küçük beyaz bölgelerin silinmesi (area opening). Kalem ucu her karedeki en alt beyaz piksel olarak alınır.
  - Çevrim dışı öznitelik: gradyan öznitelikleri. Gradyan yönü 12 yöne nicemlenir. Görüntü 4x4 bloğa bölünür, her blokta yön sayıları çıkarılır.
  - Eşleştirme: çevrim içi için dinamik zaman bükme (Dynamic Time Warping, DTW), çevrim dışı için Öklid uzaklığı.
  - İki yaklaşımın birleştirilmesi SVM ile yapılır.
- **Sonuçlar (slayttaki tablo):**

| Yaklaşım | Doğruluk | FAR | FRR | Ortalama hata (AER) |
| --- | --- | --- | --- | --- |
| Çevrim içi | 63,46 | 45,38 | 27,69 | 36,54 |
| Çevrim dışı | 74,04 | 19,23 | 32,69 | 25,96 |
| Birleşik | 76,92 | 11,54 | 34,62 | 23,08 |

- Birleşik yaklaşım en yüksek doğruluğu ve en düşük FAR'ı verir. FRR'si ise en yüksektir.
- AER, FAR ile FRR'nin ortalamasıdır.

### 7. sunum (grup 28): Veri ambarında kişisel veri tespiti

- **Temel kavramlar:**
  - Kaynak sistem: verinin ilk oluştuğu yer (uygulama ön yüzü, faturalama süreci vb.).
  - Veri ambarı (data warehouse): farklı kaynaklardan gelen verinin analiz ve raporlama için toplandığı ortam.
  - ETL (Extract, Transform, Load): veriyi kaynaktan çıkarma, dönüştürme ve ambara yükleme süreci. ODI gibi araçlarla ya da PL/SQL paketleriyle yönetilir.
  - Yükleme logları: hangi verinin nereden, ne zaman, hangi dönüşümle nereye yazıldığını tutar.
  - Kişisel veri: bir kişiyi belirlenebilir kılan veri. Kişisel Verilerin Korunması Kanunu (KVKK) kurumlara saklama, işleme ve erişim sorumlulukları yükler.
- **Mevcut yaklaşım:** Her veri, yerinden bağımsız değerlendirilir. Varlık ismi tanıma (Named Entity Recognition), kural tabanlı yöntemler ya da makine öğrenmesi kullanılır.
- **Önerilen yaklaşım:** Yükleme logları analiz edilip kaynak-hedef eşleştirmesi çıkarılır. Kaynak sistemde bulunan kişisel verinin izi bu eşleştirme üzerinden sürülür ve ambarda nereye yüklendiği bulunur. Böylece kesinlik (precision) ve duyarlılık (recall) artırılmak istenir.
- **Yöntem (6 ay):**
  1. Veri simülasyonu ve etiketleme (%30): Kurumlar log paylaşmadığı için kamuya açık veriler toplanır. Bu veriler farklı kaynak sistemlermiş gibi gruplanır ve yanlarına sentetik kişisel veri üretilir. Hepsi MySQL'e yüklenir. Talend Open Studio ile ETL süreçleri tasarlanır, böylece loglar üretilir. Başarıyı ölçmek için kişisel verilerin yerleri baştan etiketlenir.
  2. Açık kaynaklı uygulamanın geliştirilmesi (%60).
  3. Kullanım rehberi ve dokümantasyon (%10).
- **Riskler:** Bütçe desteğinin kesilmesi (B planı: özel sektör desteği). Ekipten birinin ayrılması (B planı: bursla yetkin bir yüksek lisans öğrencisi alınması). İkinci risk sunum günü gerçekleşmiştir.

### 8. sunum (grup 30): CNN ile hava tahmini

- Sunum İngilizce yapılır. Altyazının büyük kısmı bozuk ya da döngüye girmiş; aşağıdakiler anlaşılan kısımlardır.
- **Konu:** Makine öğrenmesinin hava tahmininde kullanımı. Anlatılan problem kategorileri:
  - Sayısal hava tahmini (Numerical Weather Prediction, NWP) çıktılarındaki sistematik hataların düzeltilmesi.
  - Uç olayların (extreme events) tespiti: nadir olayları tahmin etmeye yönelik bir sınıflandırma problemi.
  - Doğrusal regresyon modellerinin yalnızca yanlılık düzeltmesinden daha geniş bir bağlamda kullanılması.
- **Önerilen yöntem:**
  - Girdi: atmosferin farklı basınç seviyelerindeki jeopotansiyel yükseklik (Z) alanları.
  - 2B CNN: iki evrişim katmanı, 3x3 çekirdek, 2x2 maksimum havuzlama (max pooling), tam bağlantılı katman ve softmax çıktısı.
  - 3B CNN: aynı yapı, 3x3x3 çekirdek ve 2x2x2 havuzlama.
  - TensorFlow ile, verinin %80'i eğitim (300 epoch), %20'si doğrulama.

### Ders sonrası notlar

- **3. sunum:** "Derin öğrenme yöntemleri olarak yapay sinir ağları, destek vektör makineleri ve rastgele orman kullanılacaktır" deniyor. SVM ve rastgele orman derin öğrenme yöntemi değildir, klasik makine öğrenmesi yöntemleridir. Projede derin öğrenme, öznitelik çıkaran CNN kısmıdır.
- **3. sunum:** Tarif edilen veri seti (100 boyanmış görüntü, epitel, inflamatuar, fibroblast ve "çeşitli" sınıfları) literatürdeki CRCHistoPhenotypes veri setine uyuyor. Sunumda adı geçmiyor.
- **4. sunum:** Anomali tabanlı sistemler için "sıfırıncı gün ataklarında kullanılamaz" denmesi yanlış. Yeni atakları yakalama potansiyeli olan asıl yaklaşım anomali tabanlı tespittir; sorunu yüksek yanlış pozitif oranıdır. Başarı ölçütü de "yanlış pozitif oranını sağlamak" değil "düşük tutmak" olmalıdır.
- **4. sunum:** Snort'un topluluk kuralları GPLv2 ile dağıtılır. Kayıtlı ve abone kural setlerinin ayrı lisans koşulları vardır.
- **5. sunum:** Sunumdaki "hayat üçgeni" önerisi tartışmalıdır. AFAD gibi kurumlar deprem anında "çök, kapan, tutun" hareketini önerir. Bu fark, bekleme süresi tasarımını etkilemez.
- **5. sunum:** Literatür kısmında geçen modeller altyazıda "KÖNEM ve SEM" diye yazılmış. Doğrusu KNN ve SVM.
- **8. sunum:** Basınç seviyelerinin yükseklik karşılığı yaklaşık olarak şöyledir: 1000 hPa yüzeyi deniz seviyesine yakındır (yaklaşık 100 m), 700 hPa yaklaşık 3000 m, 500 hPa yaklaşık 5500 m. Sunumdaki "1000 m" değeri 1000 hPa için doğru değildir.
- **Whisper hataları:**
  - "dokusal/dokursal parke" → dokunsal parke
  - "Kinect DK Azure" → Azure Kinect DK
  - "iteratif closed point" → Iterative Closest Point
  - "kibor" → Gabor
  - "ervişimsel/evlişimsel" → evrişimsel
  - "buro / Bura" → Bro (bugünkü adı Zeek)
  - "KAP99" → KDD Cup 99
  - "Perceptor" → perceptron
  - "pick-up dosyaları" → pcap dosyaları
  - "Kandililer'e rastathanesi" → Kandilli Rasathanesi
  - "Tensörflor" → TensorFlow
  - "Talent Open Studio" → Talend Open Studio
  - "mayosukal" → MySQL

**Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
