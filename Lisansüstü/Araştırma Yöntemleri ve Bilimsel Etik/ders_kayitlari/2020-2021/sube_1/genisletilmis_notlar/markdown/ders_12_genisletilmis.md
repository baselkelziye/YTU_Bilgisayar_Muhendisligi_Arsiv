# Ders 12 Genişletilmiş Notu: Proje Önerisi Sunumları III: Görme Engelli Asistanı, Saldırı Tespiti, Enkaz Tespiti ve Kişisel Veri

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dersin Yapısı ve Sunumların Ortak İskeleti
- 2. 1. Sunum: Görme Engelliler İçin Mobil Yol Asistanı
- 3. 2. Sunum: CNC Tezgahlarında Çarpışmanın Önceden Tespiti
- 4. 3. Sunum: Kolon Kanseri Görüntülerinde Çekirdek Sınıflandırma
- 5. 4. Sunum: Güncel Saldırıların ve Sıfırıncı Gün Ataklarının Tespiti
- 6. 5. Sunum: Düşme Tespiti Yöntemiyle Enkaz Tespiti
- 7. 6. Sunum: Çevrim İçi ve Çevrim Dışı İmza Doğrulama
- 8. 7. Sunum: Veri Ambarında Kişisel Veri Tespiti
- 9. 8. Sunum: CNN ile Hava Tahmini

## 1. Dersin Yapısı ve Sunumların Ortak İskeleti

Bu derste konu anlatımı yoktur. Ders, öğrenci gruplarının araştırma projesi önerilerini sunduğu haftalardan biridir. Hoca grupları numara sırasıyla çağırır, ekran paylaşım yetkisini verir ve sözü gruba bırakır. Toplam sekiz sunum yapılır. İkisi büyük ölçüde İngilizcedir ve altyazıları yer yer bozuktur.

Sunumların çoğu TÜBİTAK 1002 Hızlı Destek Programı başvurusu biçiminde hazırlanmıştır. Bu yüzden konuları çok farklı olsa da aynı iskeleti izlerler:

- Konunun önemi ve literatürdeki boşluk
- Özgün değer
- Amaç, hedefler ve başarı ölçütleri
- Yöntem
- İş paketleri ve her iş paketinin projeye katkı oranı
- Risk yönetimi ve B planları
- Yaygın etki: akademik, ekonomik, sosyal ve ulusal güvenlik çıktıları
- Bütçe

Bu notu okurken her sunumu aynı zamanda bir proje önerisi örneği olarak düşünmek yararlıdır. Her sunumda aynı sorular yanıtlanır: Problem neden önemli, mevcut çözümler neden yetmiyor, önerilen yöntem neyi farklı yapıyor, işler ters giderse ne yapılacak?

Hoca her sunumdan sonra soru olup olmadığını sorar. Bu derste dinleyicilerden soru gelmez. Hoca bunu bir noktada "herhalde her zaman olduğu gibi soru yok" diye dile getirir. Sunumlara içerik yönünden ayrıntılı bir değerlendirme yapmaz. Tek somut yorumu 7. sunumdaki risk yönetimi üzerinedir (bkz. 8.5).

## 2. 1. Sunum: Görme Engelliler İçin Mobil Yol Asistanı

### 2.1 Konu ve Motivasyon

İlk grubun önerisi, görme engelli bireyler için derin öğrenme tabanlı bir mobil yol asistanıdır. Grup önce problemin büyüklüğünü sayılarla verir. Dünya Sağlık Örgütü'ne göre dünyada yaklaşık 2,2 milyar insan görme bozukluğu yaşamaktadır. Bunların 36 milyonu görme yetisini tamamen kaybetmiştir.

Grup, literatüre göre bu kişilerin günlük hayatta karşılaştığı kazaların dağılımını şöyle verir:

| Kaza nedeni | Oran |
| --- | --- |
| Çarpma | %47 |
| Platformdan düşme | %31 |
| Merdivenden düşme | %10 |
| Diğer | %12 |

Görme engelliler için belediyeler ve kurumlar yollara dokunsal parke yüzeyleri (tactile paving) döşer. Fakat bu yüzeyler yanlış döşenebilir ya da üzerlerinde engel bulunabilir. Bu da kazaları artırır. Grup, slaytta yanlış konumlandırılmış ve üzerinde engel olan yol örnekleri gösterir.

Bastonun sınırı da önemli bir motivasyondur. Baston yerdeki engeli algılamayı sağlar. Ancak slayttaki diğer örnekte kişinin üzerinden bir üst geçit geçmektedir ve böyle bir engeli bastonla algılamak pek mümkün değildir.

### 2.2 Amaç

Projenin hedefi üç adımdır:

1. Dokunsal parke yüzeyini tespit etmek.
2. Bu yüzeyin üzerinde engel olup olmadığını algılamak.
3. Engele göre kullanıcıyı uyarmak.

### 2.3 Literatür ve Özgün Değer

Grubun literatür incelemesine göre dokunsal parke yüzeyi tespiti çoğunlukla geleneksel görüntü işleme yöntemleriyle yapılmıştır. Bu çalışmaların genelinde kullanıcı kamera veya mini bilgisayar gibi ek donanım taşımak zorundadır ve sistemler düşük FPS değerleriyle çalışır. Slayttaki tablonun kısa notta aktarılan hali şöyledir:

| Yöntem | Doğruluk | FPS | Ek ürün |
| --- | --- | --- | --- |
| Canny, Laplace, Sobel kenar bulma ve karar ağaçları | %88,48 | 16,27 | - |
| Gri seviyeli eş-oluşum matrisi (GLCM) ve SVM | - | - | - |
| Çok renkli segmentasyon ve Kirsch kenar bulma | - | 2 | - |
| OpenCV ile geleneksel görüntü işleme | %91,65 | 10,51 | Derinlik kamerası ve mikrodenetleyici kartı |
| YOLOv3-Dense (grubun önceki çalışması) | %92 (mAP) | 60 | - |

<!-- BELİRSİZ: Tablonun satırları altyazıda okunmuyor; değerler kısa nottaki slayt aktarımından alındı. Altyazıda doğrulanan yalnız son satırdır: 60 FPS ve yaklaşık %92 ortalama kesinlik. -->

Son satır grubun kendi çalışmasıdır. Bu model bilgisayar üzerinde gerçek zamanlı (real time) olarak 60 FPS ile çalışmaktadır. Projede bu çalışma mobil ortama aktarılacaktır.

Grubun saydığı özgün değerler şunlardır:

- Derin öğrenme mimarileri kullanan, doğruluğu ve FPS değeri yüksek bir sistem henüz yoktur.
- Sistem farklı bir donanım gerektirmez. Kullanıcı yalnızca cep telefonunu kullanır.
- Veri seti grubun kendisi tarafından oluşturulmuştur. Metro ve AVM gibi iç mekanlardan, yürüyüş yolu gibi dış mekanlardan alınmış 4580 etiketli görüntü içerir.

### 2.4 Yöntem

Proje iki temel kısımdan oluşur: derin öğrenme modellerinin belirlenmesi ve mobil uygulamanın geliştirilmesi. Uygulama hem iOS hem de Android cihazlarda çalışacaktır. Native mi yoksa cross-platform mu geliştirileceğine performans, zaman ve maliyet göz önüne alınarak karar verilecektir. Modeller farklı framework'ler kullanılarak mobil uygulamaya aktarılacaktır. Kullanıcıya yardımcı olması için sesli asistan özelliği eklenecek, uygulamanın performansını ve geri dönüşleri izlemek için de farklı araçlar entegre edilecektir.

### 2.5 İş Paketleri

| İş paketi | İçerik | Katkı |
| --- | --- | --- |
| Altyapı çalışmaları | Yazılım kütüphanelerinin belirlenmesi ve çalışma ortamının kurulması | %10 |
| Veri setinin hazırlanması | Mevcut veri setinin dört katına çıkarılması | %20 |
| Modellerin belirlenmesi ve eğitilmesi | Optimum modelin elde edilmesi | %25 |
| Mobil aktarım | Modellerin mobil uygulamada çalışır hale getirilmesi | %35 |
| Arayüz ve yayın | Arayüz tasarımı ve uygulamanın markette yayımlanabilir hale getirilmesi | %10 |

En büyük payın modelin eğitilmesine değil, mobil ortama aktarılmasına verilmesi dikkat çekicidir. Çünkü modelin bilgisayardaki sürümü zaten vardır, projenin asıl yeni işi onu telefonda çalıştırmaktır.

### 2.6 Risk Yönetimi

Grup en önemli üç riski ve B planlarını şöyle verir:

- **Veri seti dört katına çıkarılamazsa:** Pandemi gibi durumlarda veri toplanamayabilir. Bu durumda Unity gibi simülasyon ortamlarında yapay veri üretilecektir.
- **Doğruluk en az %3 artırılamazsa:** Bu, başarı ölçütlerinden biridir. Katman sayısı, hiperparametreler ve optimizasyon yöntemi danışman gözetiminde değiştirilecektir. Bu da sonuç vermezse elde bulunan mevcut model kullanılacaktır.
- **Mobilde en az 30 FPS sağlanamazsa:** Uygulama gerçek zamanlı kullanılacağı için FPS kritik bir değerdir. Doğruluktan biraz feragat edilip katman sayısı azaltılarak daha hızlı bir model kurulacaktır.

Üçüncü risk, doğruluk ile hız arasındaki ödünleşimi (trade-off) açıkça ortaya koyar. İkinci riskteki başarı ölçütü de sayısaldır. Böylece projenin başarılı olup olmadığı ölçülebilir hale gelir.

### 2.7 Çıktılar ve Etki

Grup iki çıktı öngörür: ulusal ve uluslararası konferanslarda yayımlanmak üzere bir bildiri ve markette yayımlanan bir mobil uygulama. Uygulama 12 aylık sürenin sonuna doğru hazır olacaktır. Beklenen etki görme engelli bireylerin yaşam kalitesine katkıdır. Grup ayrıca 11. Kalkınma Planı'nın 152, 646 ve 675 numaralı maddelerine atıf yapar.

### 2.8 Bütçe

| Kalem | Tutar |
| --- | --- |
| Makine ve teçhizat | yaklaşık 31.000 TL |
| Hizmet alımı | yaklaşık 4.000 TL |
| Bursiyer | yaklaşık 5.250 TL |
| **TÜBİTAK'tan talep** | **40.807 TL** |
| Kurum katkısı (derin öğrenme bilgisayarı, aksiyon kameraları) | 44.560 TL |
| **Genel toplam** | **85.368 TL** |

Talebin büyük kısmı donanımdır: uygulamayı geliştirmek için bir MacBook Pro, test için iPhone 11 ve Xiaomi Redmi Note 9. Ayrıca iki market için yıllık geliştirici hesabı ve model seçimi ile geliştirilmesi için danışmanlık hizmeti istenir.

> **Ders sonrası not:** Sunumda geçen tutarlarla toplam 40.807 + 44.560 = 85.367 TL eder; sunumda 85.368 TL denir. Aradaki 1 TL'lik fark büyük olasılıkla tutarların kuruşlarının yuvarlanmasından kaynaklanır.

> **Ders sonrası not:** Altyazıda programın adı "12. Yıldızlı Destek Programı" diye geçer. Bu büyük olasılıkla, diğer sunumlarda da geçen "1002 Hızlı Destek Programı"nın yanlış yazılmış halidir.

## 3. 2. Sunum: CNC Tezgahlarında Çarpışmanın Önceden Tespiti

### 3.1 Konu ve Motivasyon

Bu grubun önerisi (grup 3), CNC tezgahlarında gerçekleşen çarpışmaların görüntü işleme teknikleriyle anlaşılmasıdır. Sunum, CNC tezgahlarının kullanımının 1940'lı yıllara dayandığını ve imalat sektöründe metal, ahşap ve kompozit gibi malzemelerin işlenmesinde önemli yer tuttuğunu hatırlatarak başlar.

CNC tezgahları G-code adı verilen betiklerle programlanır. Grup, slaytta bir şekli ve onu işleyen G-code'u yan yana gösterir. G-code içinde eksenlerin koordinat değerleri ve işlenecek malzemenin cinsine göre başlığın dönme hızı gibi bilgiler bulunur.

Temel problem, işleme sırasında eksenlerin birbirine, iş parçasına ya da ortamdaki bağlantı elemanlarına çarpması ve bunun maddi kayba yol açmasıdır. Grubun saydığı nedenler şunlardır:

- İş parçasının operatör tarafından tezgaha uygun yerleştirilmemesi
- Takım ofset ayarlarının uygun yapılmaması
- İşleme hızı veya derinliğin malzemeye uygun olmaması
- Bağlantı elemanları

Grup, 2012'de Almanya merkezli bir çalışmaya atıf yapar. Bu çalışmada 150 CNC yangınının nedenleri analiz edilmiştir. Eksenlerin çarpışması olarak tanımlanan "bindirme" durumu bunların yaklaşık %12'sini oluşturur.

<!-- BELİRSİZ: Altyazıda "150 adet CNC yangını" geçiyor. Çalışmanın kapsamı ve oranlar slaytta; altyazıdan doğrulanamadı. -->

### 3.2 Mevcut Çözüm ve Özgün Yaklaşım

Bugün sunulan çözümler titreşim sensörüne dayanır. İşleme sırasında tezgahın içinde rutin bir titreşim vardır. Çarpışma olunca titreşim artar, sensör bunu yakalar ve makineyi durdurur. Sorun şudur: Önlem kaza gerçekleştikten sonra alındığı için maddi kayıp istenen ölçüde azaltılamaz.

Grubun önerisi, çarpışmayı gerçekleşmeden yakalamaktır. Bunun için tezgahın içi derinlik kameralarıyla izlenir ve 3 boyutlu modeli çıkarılır. Derinlik kameraları oyun, 3 boyutlu modelleme, ürün tasarımı, haritalama ve konum belirleme gibi alanlarda kullanılmaktadır.

<!-- BELİRSİZ: Son kullanım alanı altyazıda "kolum gelirleme" diye geçiyor; "konum belirleme" olarak okundu. -->

### 3.3 Yöntem

Yaklaşım dört adımdan oluşur:

1. Tezgah içindeki çalışma ortamı iki farklı derinlik kamerasıyla 3 boyutlu olarak modellenir.
2. G-code verisinden hareket koordinatları çıkarılır.
3. Koordinat değerleri 3 boyutlu kamera görüntüsüyle karşılaştırılarak kontrol edilir.
4. Çarpışma tespit edilirse operatör bilgilendirilir ve uyarılır.

#### Kamera

Piyasada farklı marka ve modellerde derinlik kameraları vardır. Bunların bir kısmı endüstriyel kullanım içindir, Microsoft'un ürünleri ise oyun amaçlı da satılmaktadır. Grup, daha yüksek hassasiyet ve çözünürlüğe sahip Microsoft Azure Kinect DK modelini seçmiştir. Bu kamera RGB görüntüyle birlikte her pikselin uzaklığını, yani derinlik bilgisini de verir.

Derinlik, uçuş süresi (Time of Flight) yöntemiyle ölçülür: Kızılötesi ışığın yansıma süresi hesaplanarak mesafe bulunur. Grup, kameranın bir önceki sürümü için yapılmış bir çalışmaya atıf yapar. Bu çalışmada 2 metreye kadar olan mesafelerde 2 mm'den daha iyi bir hassasiyet ölçülmüştür. Grup, yeni sürümün daha hassas olmasını beklemektedir.

#### Kalibrasyon

Kameralar yerleştirildikten sonra kalibrasyon gerekir. Bunun için dört parametre ayarlanır ve genellikle satranç tahtasına benzeyen bir kalibrasyon tahtası kullanılır. Grup kalibrasyonun gerekçesi olarak kameraların farklı ışık ortamlarında farklı sonuçlar vermesini gösterir.

<!-- BELİRSİZ: Dört kalibrasyon parametresinin hangileri olduğu slaytta; altyazıda geçmiyor. -->

> **Ders sonrası not:** Sunumda kalibrasyonun nedeni olarak yalnız ışık ortamı söylenir. Satranç tahtası tipi kalibrasyon büyük olasılıkla kameranın iç parametrelerini ve kameralar arası konum ilişkisini bulmak için de gereklidir.

#### Literatürdeki Örnekler

Grup, derinlik kameralarının makine sektöründeki kullanımına üç örnek verir:

- Aynı ortamda çalışan insan ve endüstriyel robot kolların çarpışmasını önleme. Burada da iki farklı açıdan derinlik kamerası kullanılmıştır, yani yöntem grubunkine benzer.
- Derinlik kamerasının insan hareketi algılama özelliğinden yararlanarak makineleri hareketle kontrol etme. Kinect kullanılmıştır.
- Normal kameralarla malzeme yüzeyinin pürüzlülüğünü görüntü işleme ile gözleme.

#### Nokta Bulutu İşlemleri

Derinlik kamerası, nesnenin 3 boyutlu şeklini nokta bulutu (point cloud) olarak verir. İki kameradan gelen nokta bulutlarının birleştirilmesi gerekir. Bu işleme nokta bulutu kaydı (point cloud registration) denir. Matris dönüşümleriyle döndürme ve öteleme yapılarak iki bulut birleştirilir. Grup bunun için ICP (Iterative Closest Point) yöntemini kullanmayı düşünmektedir.

> **Ek bilgi (derste anlatılmadı):** ICP yinelemeli bir hizalama yöntemidir. Bir buluttaki her nokta için diğer buluttaki en yakın nokta eşleştirilir. Bu eşleşmeler üzerinden iki bulutu en iyi çakıştıran dönme ve öteleme hesaplanıp uygulanır. Bu adımlar hizalama hatası yeterince azalana kadar tekrarlanır. Yöntem iyi bir başlangıç hizalamasına ihtiyaç duyar.

Sonraki adımda hesaplama maliyetini azaltmak için ortamda gerekmeyen noktalar arka plan çıkarma (background subtraction) ile ayıklanır. Grubun kaynak aldığı çalışmada 3 boyutlu nokta bulutu segmentasyon yöntemleri beş çeşide ayrılır. Grup bunlardan bölge tabanlı (region-based) yöntemi kullanacak, noktaları K en yakın komşuya benzer biçimde gruplayarak arka plan verisinden ayıracaktır.

### 3.4 Hizmet Alımı

Proje iki firmadan destek alacaktır. Bir otomasyon firmasından G-code verisinin makineden alınması ve değiştirilmesi ile CNC'ye dair danışmanlık ve test hizmeti alınacaktır. Bir diğer firmadan ise CNC kiralanarak proje gerçek test ortamında denenecektir.

Bu sunumda iş paketi tablosu, risk ve bütçe ayrıntısı anlatılmaz. Grup, yaklaşım ve teknik ayrıntılara ağırlık verir.

## 4. 3. Sunum: Kolon Kanseri Görüntülerinde Çekirdek Sınıflandırma

### 4.1 Konu ve Motivasyon

Bu grubun önerisi (grup 5), derin öğrenilen özellikler topluluğu kullanarak kolon kanseri görüntülerinde çekirdeklerin sınıflandırılmasıdır. Histopatoloji, organ, doku ve hücrelerde oluşan değişikliklerin çeşitli yöntemlerle mikroskopta incelenmesidir. Kanser ve diğer hastalıkların doğru ve kesin teşhisi için kullanılır. Patolojik görüntüler dijital olarak kaydedilip klinisyenlere verilir. Bu görüntülerin sınıflandırılmasındaki gelişmeler, patoloji uzmanlarına ve klinisyenlere yardımcı olduğu için önemlidir.

Hücre çekirdeklerinin sınıflandırılması, hücrelerin homojen olmayan yapısı nedeniyle zor bir problemdir ve çekirdeklerin dokusuna dayanır.

### 4.2 Literatür ve Özgün Değer

Grup, literatürde yerel ikili örüntü (Local Binary Pattern), yönlü gradyan histogramı (Histogram of Oriented Gradients) ve Gabor yöntemlerinin kullanıldığını söyler. Grubun değerlendirmesine göre bu yöntemler maliyetlidir, tanı süresi uzundur ve elde edilen başarılar yeterli değildir. Projede bunların yerine derin öğrenme ve topluluk öğrenmesi (ensemble learning) analiz edilecektir.

> **Ders sonrası not:** Grup bu üç yöntemi "sınıflandırma algoritmaları" diye anar. Bunlar büyük olasılıkla sınıflandırıcı değil, öznitelik çıkarma yöntemleri olarak kastedilmiştir.

> **Ders sonrası not:** Grup, "derin öğrenme yöntemleri olarak yapay sinir ağları, destek vektör makineleri ve rastgele orman" kullanılacağını söyler. SVM ve rastgele orman derin öğrenme yöntemi değil, klasik makine öğrenmesi yöntemleridir. Projenin derin öğrenme kısmı, öznitelik çıkaran evrişimsel sinir ağıdır.

### 4.3 Yöntem

Önerilen akış şöyledir:

1. Evrişimsel sinir ağının (convolutional neural network) evrişim katmanlarıyla histopatolojik görüntülerin öznitelikleri çıkarılır.
2. Çıkarılan öznitelikler, öznitelik azaltma yöntemleriyle azaltılır.
3. Makine öğrenmesi algoritmalarıyla modelleme yapılır.
4. Daha iyi sonuç almak için öğrenicilerin kararları birleştirilir. Topluluk öğrenmesiyle ikinci bir öneri sunulur.
5. Sonuçlar, literatürdeki yaklaşımların sonuçlarıyla karşılaştırılır.

Değerlendirme büyük bir veri kümesi ve bağımsız bir test kümesi üzerinde yapılır. Grup hem sınıflandırma doğruluğu hem de F1 ölçüsü açısından yüksek performans hedefler.

<!-- BELİRSİZ: Altyazıda "etbir ölçüde" geçiyor; "F1 ölçüsü" olarak okundu. -->

Veri olarak kalın bağırsak kanserine ait 100 boyanmış histoloji görüntüsü kullanılacaktır. Veri kümesi en az 22.000 çekirdekle başlar, elde edilecek çekirdek sayısının daha fazla olması beklenir. Çekirdekler dört sınıfta etiketlenecektir: epitel, inflamatuar, fibroblast ve "çeşitli". İlk üç kategoriye girmeyen çekirdekler "çeşitli" sınıfına alınır. Örnekler, etiketlenmiş histoloji görüntüsünden kesilerek elde edilir.

> **Ders sonrası not:** Tarif edilen veri kümesi (100 boyanmış görüntü, aynı dört sınıf) büyük olasılıkla literatürdeki CRCHistoPhenotypes veri setidir. Sunumda adı geçmez.

### 4.4 İş Paketleri

Projede yedi iş paketi vardır. Grup her birinde görev alacak araştırmacı sayısını da verir.

| No | İçerik | Görev alanlar |
| --- | --- | --- |
| 1 | Çekirdeklerin etiketlenmesi için modül geliştirme | 2 lisans, 2 yüksek lisans, 1 doktora araştırmacısı |
| 2 | Etiketlenen çekirdeklerin ayrıştırılması için yazılım modülü | 2 yüksek lisans, 1 doktora araştırmacısı |
| 3 | Hücre çekirdeği veri kümesinin oluşturulması | 2 yüksek lisans, 1 doktora araştırmacısı |
| 4 | Evrişim katmanlarıyla öznitelik çıkarma | Altyazıda söylenmez |
| 5 | SVM, yapay sinir ağı ve evrişimsel sinir ağı ile sınıflandırma algoritmaları | 2 lisans, 2 yüksek lisans, 1 doktora araştırmacısı |
| 6 | Geliştirilen algoritmanın literatürle karşılaştırılması | Altyazıda söylenmez |
| 7 | Sonuçların raporlanması | Yürütücü |

### 4.5 Risk Yönetimi

Grup, her riski ilgili olduğu iş paketiyle eşleştirir:

- **Tüm proje:** Sağlık verilerinin mahremiyet açısından korunması gerekir. Diferansiyel mahremiyet (differential privacy) gibi çözümler düşünülmektedir.
- **1. iş paketi:** Çekirdekler etiketlenemeyebilir. Bu durumda hazır etiketli kanserli doku veri setleri kullanılacaktır.
- **4. ve 5. iş paketleri:** Model eğitimi ve testinde hesaplama kapasitesi aşılabilir. Bu durumda yüksek başarımlı hesaplama ortamı kullanılacaktır.

> **Ek bilgi (derste anlatılmadı):** Diferansiyel mahremiyet, bir veri analizinin çıktısının tek bir kişinin verisine çok bağlı olmamasını matematiksel olarak güvence altına alan bir çerçevedir. Genellikle sonuca veya eğitim sürecine ölçülü gürültü eklenerek sağlanır. Gürültü arttıkça mahremiyet güçlenir, ama modelin başarısı düşebilir.

### 4.6 Çıktılar ve Etki

Akademik çıktı olarak kongre sunumu ve dergi makalesi hedeflenir. Geliştirilecek yazılım modülleriyle kanserli dokuların öznitelikleri alınabilecek, sınıflandırılabilecek ve doğruluğu değerlendirilebilecektir. Toplum sağlığının korunması sosyal çıktı olarak gösterilir. Grubun öngördüğü etkiler sağlık alanında yapay zeka kullanımıyla tanı ve tedavinin kolaylaşması, yeni çalışmalara zemin hazırlanması ve hastanelerde tanı ve tedavi maliyetlerinin düşmesidir.

## 5. 4. Sunum: Güncel Saldırıların ve Sıfırıncı Gün Ataklarının Tespiti

### 5.1 Konu ve Motivasyon

Bu grubun önerisi (grup 7), yapay sinir ağlarıyla güncel saldırıların ve sıfırıncı gün (zero-day) ataklarının tespitidir. Proje ekibinde grup üyeleri ile siber güvenlik ve ağ alanında uzman bir danışman görev alacaktır. Motivasyon olarak iki grafik gösterilir: yıllara göre zararlı yazılım (malware) saldırılarındaki artış ve internet kullanımındaki artış. Grup, bu iki artışın birlikte insanlara maddi ve manevi zarar verdiğini söyler.

### 5.2 Saldırı Tespit Sistemleri

Atakları tespit etmek ve önlemek için kurulan sistemlere saldırı tespit sistemleri (intrusion detection system) denir. Bu sistemler zararlı yazılımları ve politika ihlallerini tespit etmeye ve engellemeye yarar. İki ana başlıkta incelenir:

- **Kötüye kullanım saldırı tespiti (KKST):** İmza kullanan, Snort ve Bro gibi kural tabanlı sistemlerdir. Geçmiş saldırıları tespit etmeye yöneliktir.
- **Anomali saldırı tespiti (AST):** Bir ortamdaki normal dışı davranışları tespit eder. Yanlış pozitif oranı yüksektir, yani atak olmayan paketleri atak olarak sınıflandırabilir.

Projede kullanılacak Snort, imza tabanlı bir sistemdir. 1998'de geliştirilmeye başlanmıştır, saldırı tespiti ve engelleme işlevlerine sahiptir, açık kaynak kodludur ve GPLv2 lisanslıdır. Grup slaytta bir imza örneği gösterir: Paketin hangi porttan hangi porta gittiği, mesaj bilgisi, `content` bilgisi ve akış gibi bölümler vardır. Burada özellikle `content` parametresine dikkat çekilir, çünkü bu parametre paketin yükünü (payload) denetler. Proje, bu parametrelerden yeni bir imza kümesi oluşturacaktır.

> **Ders sonrası not:** Altyazıda "buro / Bura" diye geçen sistem büyük olasılıkla Bro'dur. Bu sistemin bugünkü adı büyük olasılıkla Zeek'tir.

> **Ders sonrası not:** Sunumda Snort imzaları GPL lisanslı olarak anılır. Büyük olasılıkla bu yalnız topluluk kuralları için geçerlidir; kayıtlı ve abone kural setlerinin lisans koşulları ayrıdır.

### 5.3 Sıfırıncı Gün Atakları ve Araştırma Sorusu

Sıfırıncı gün atakları daha önce karşılaşılmamış ataklardır. Grup örnek olarak 2010'daki Stuxnet atağını verir. Bu atakların örüntüleri farklıdır ve tespitleri zordur. Grup, iki sistem türünün de bu konuda yetersiz kaldığını şöyle açıklar: KKST geçmiş saldırılara yönelik olduğu için bu atakları tespit edemez. AST ise yanlış pozitif oranı yüksek olduğu için kullanılamamaktadır.

> **Ders sonrası not:** Anomali tabanlı sistemlerin sıfırıncı gün ataklarında "kullanılamadığı" ifadesi fazla kesindir. Yeni atakları yakalama potansiyeli olan yaklaşım büyük olasılıkla anomali tabanlı tespittir; asıl sorunu yüksek yanlış pozitif oranıdır.

Araştırma sorusu şudur: Sıfırıncı gün ataklarını ve güncel atakları tespit edebilen bir sistem yapmak mümkün müdür? Grup yanıtı üç maddenin birleşiminde arar:

- Paket analizi yapmak
- İstatistiksel özellikler kullanmak
- KKST ile AST sistemlerini birleştirmek

Başarı kriteri bu saldırıları yüksek oranda tespit etmek ve yanlış pozitif oranını sağlamak olarak ifade edilir.

> **Ders sonrası not:** Bir başarı ölçütü "yanlış pozitif oranını sağlamak" biçiminde eksik kalır. Burada büyük olasılıkla bu oranın düşük tutulması kastedilmiştir. Sayısal bir hedef de verilmemiştir.

### 5.4 Literatürdeki Eksikler ve Özgün Değer

İkinci konuşmacı literatürdeki çalışmaları tek tek saymak yerine buralarda gördüğü eksikleri anlatır:

- **Güncel olmayan veri:** KDD Cup 99 ve NSL-KDD veri setleri çok kullanılmaktadır. İlki 1999, ikincisi 2009 yılına aittir. Grup, Kanada Siber Güvenlik Enstitüsü'nün 2017 ve 2018 veri setlerini kullanacaktır.
- **Dar kapsam:** Çalışmaların bir kısmı yalnız belirli saldırı türlerine yöneliktir, örneğin botnet ve kaba kuvvet (brute force). Grup tüm atak türlerini ve sıfırıncı gün ataklarını tespit edebilen bir model hedefler.
- **Yalnız istatistiksel öznitelik:** Son on yıldaki makine öğrenmesi ve derin öğrenme çalışmaları modelleri istatistiksel özniteliklerle eğitir. Grup, Snort ile paket yüklerini de analiz edecektir.

Grup, üçüncü maddeyi en önemli özgün değeri olarak gösterir. İstatistiksel özniteliklerin yanında paket içeriklerinin de değerlendirildiği bir model eğitilecektir. Literatürdeki çalışmalarda doğruluk genellikle %90'ın üzerindedir, kapsama göre %98'e varan sonuçlar da vardır. Modelin başarısı bu oranlarla karşılaştırılacaktır.

<!-- BELİRSİZ: Saldırı türleri arasında altyazıda bir de "Excess" geçiyor; hangi tür olduğu anlaşılamadı. -->

### 5.5 Yöntem

Yöntem adımları şöyledir:

1. Kanada Siber Güvenlik Enstitüsü'nün veri setleri elde edilir. Sunuma göre 2017 veri seti için izin gereklidir, 2018 veri seti ise herkese açıktır.
2. Ham paketler parçalanır ve Snort ile paket analizi yapılır.
3. Paket analizinden elde edilen vektörler öznitelik uzayıyla birleştirilir.
4. Derin öğrenme modelleri eğitilir: çok katmanlı algılayıcı (multilayer perceptron) ve otomatik kodlayıcı (autoencoder).

Grup bu iki modeli seçme gerekçesi olarak, saldırı tespiti literatüründe başarıyı oldukça artırdıklarını gösterir.

### 5.6 İş Paketleri ve Risk

Proje 10 ay sürecek ve beş iş paketinden oluşacaktır:

| No | İş paketi | İçerik |
| --- | --- | --- |
| 1 | Veri inceleme | Veri setindeki saldırı türlerinin analizi, kullanılacak türlerin ve eğitim-test oranlarının belirlenmesi |
| 2 | Öznitelik uzayının oluşturulması | Snort imzalarındaki `content` parametrelerinin birleştirilip yeni imza kümesinin oluşturulması |
| 3 | Veri parçalama | Ham paketlerin SplitCap ile paket ve akış bazında bölünmesi ve uygun formata çevrilmesi |
| 4 | Veri setinin oluşturulması | Paketlerin Snort'a verilmesi, her paket için dönen vektörün istatistiksel özniteliklerle birleştirilmesi, test verisinin ayrılması |
| 5 | Model eğitimi | MLP ve otomatik kodlayıcının eğitilmesi, ince ayar, gerçek hayat senaryosunda test ve Snort ile karşılaştırma |

Beşinci paketin sonunda deneysel analizler raporlanacak ve yazılacak makale için kaynak oluşturulacaktır. Snort'un iki rolü vardır: Hem paket analizi için projenin bir parçasıdır hem de bir KKST olarak karşılaştırma ölçütüdür.

Grup en büyük risk olarak Snort imzalarının GPL lisansının iptal edilmesini görür. B planı, farklı organizasyonların paylaştığı atak imzalarını kullanmaktır.

### 5.7 Çıktılar ve Etki

Grup, paket analizi yapan ve aynı zamanda istatistiksel öznitelik kullanan bir yöntemin literatürde daha önce yapılmadığını savunur. Bu nedenle yöntemi anlatan bir bilimsel makaleyi uluslararası kongrelerde ve SCI dergilerde yayımlamayı hedefler. Başarı tatmin edici olursa kamu kurumlarında kullanım, ticari ürünler ve ulusal güvenliğe etki öngörülür.

## 6. 5. Sunum: Düşme Tespiti Yöntemiyle Enkaz Tespiti

### 6.1 Konu ve Motivasyon

Bu grubun önerisi (grup 17), düşme tespiti yöntemiyle bir enkaz acil durum uygulaması geliştirmektir. Grup, deprem bölgesindeki ülkeler için iki temel problem tanımlar. Birincisi depremin önceden tespitidir, ancak bu dakikaları bulmaz, saniyeler öncesinden yapılabilir. İkincisi, depremden sonra yardım kurumlarının bölgeye hızlı ve güvenli biçimde yönlendirilmesidir. Proje ikinci probleme odaklanır.

Literatürde düşme tespiti çalışmaları genelde yaşlı insanların düşmeleri veya hareket sınıflandırması üzerinedir. Depremle ilgili çalışmalarda ise mobil uygulamalar üzerinden sensör kullanılır. Grup, düşme tespitini mobil sistemler üzerinden enkaz tespitine uygulayan bir çalışma bulunmadığını söyler.

### 6.2 Araştırma Soruları, Amaç ve Hedefler

İki araştırma problemi vardır: Düşme tespiti yöntemiyle enkaz tespit edilebilir mi? Enkaz tespit edildikten sonra kişi ve konum bilgileri kamu kurumlarına doğru biçimde iletilebilir mi?

Amaçlar, enkazın tespit edilmesi, kişinin konumunun doğru biçimde iletilmesi ve enkaz altında yaklaşık kaç kişi kaldığının tahmin edilmesidir. Hedefler de şunlardır:

- Mobil sistemlerin %90'ını kapsayan bir uygulama geliştirmek
- Düşme tespiti için yüksek doğruluklu bir makine öğrenmesi modeli geliştirmek
- Sunucu tabanlı bir iletişim yapısı kurmak

### 6.3 Yöntem

Proje üç temel yöntemden oluşur: düşme tespiti modeli, mobil uygulama ve grubun mobil enkaz belirleme algoritması (MEBA) diye adlandırdığı algoritma.

#### Düşme Tespiti Modeli

Makine öğrenmesi adımında MobiFall veri kümesi kullanılacaktır. Grup bu kümenin düşme tespitinde akademik olarak sık kullanıldığını söyler. Veri kümesi ivmeölçer ve jiroskop verisi içerir; dört düşme türü ve dokuz günlük yaşam aktivitesi bulunur. Grup düşme türlerine odaklanacak, ama verinin tamamını alacaktır. Literatürde en iyi sonuçları KNN ve SVM verdiği için ikisi de denenecek, en iyi sonuç veren kullanılacaktır.

> **Ders sonrası not:** Altyazıda modeller "KÖNEM ve SEM" diye geçer. Bunlar büyük olasılıkla KNN ve SVM'dir.

#### Mobil Uygulama Akışı

Uygulama akışı şöyledir:

1. Kişinin ivmeölçer ve jiroskop verileri sensörlerden alınır ve modele verilir.
2. Düşme yoksa uygulama çalışmaya devam eder.
3. Düşme tespit edilirse bekleme noktasına geçilir.
4. Bekleme süresi bitince sensör verisi yeniden alınır ve tekrar kontrol edilir.
5. Düşme durumu sürüyorsa acil durum mekanizması tetiklenir, kişi ve konum bilgisi sunucuya iletilir.
6. Düşme durumu bozulduysa sorun yok demektir.

Bekleme süresinin nedeni şudur: Deprem sırasında kişi hayat üçgeni oluşturmak için belli bir süre çömelerek bekleyebilir. Bu durum tek başına enkaz anlamına gelmez.

> **Ders sonrası not:** Sunumda geçen "hayat üçgeni" önerisi büyük olasılıkla tartışmalıdır. AFAD gibi kurumların önerdiği hareket büyük olasılıkla "çök, kapan, tutun"dur. Bu fark, bekleme süresi tasarımının mantığını değiştirmez.

#### Mobil Enkaz Belirleme Algoritması

Mobil uygulamadan gelen konum, diğer kullanıcıların konumlarıyla karşılaştırılır ve bir çember içindeki yakınlıklar bulunur. Tek konum da gelebilir, çok sayıda konum da. Acil durum mekanizması tetiklenmeden önce konumlar Kandilli Rasathanesi'nden gelen deprem merkez üssü verisiyle de karşılaştırılır. Yakınlık eşiği için grup 2 km ve 10 km gibi değerleri örnek olarak anar, kesin değeri jeofizik danışmanı belirleyecektir. Konumlar depremle yakınsa acil durum sistemi tetiklenir.

### 6.4 İş Planı ve Risk Yönetimi

İş planı 12 ay sürer ve altı kategoriye ayrılır. Görevler kişilerin yetkinliğine göre dağıtılmıştır:

- Makine öğrenmesi modelinin geliştirilmesi
- Sunucu uygulamasının hazırlanması ve MEBA'nın geliştirilmesi (jeofizik mühendisi danışmanla)
- Web servislerinin hazırlanması
- Android uygulamasının geliştirilmesi
- iOS uygulamasının geliştirilmesi
- Test ve tamamlama

Risk tablosu beş risk ve bunların B planlarını içerir:

| Risk | B planı |
| --- | --- |
| İnternet bağlantısının kesilmesi (en önemli risk) | Mesaj iletilene kadar yeniden deneme, olmazsa Bluetooth ile aktarım |
| Kullanıcının uygulama izinlerini vermemesi | Uygulamanın önemini farklı kanallarla anlatma, bilgilendirme mesajları |
| Zarar gören alanda kişi azlığı | Doğrudan Kandilli verisiyle kontrol |
| Sunucunun aşırı yüklenmesi | Yeni sunucu ekleme ve yük dengeleyici (load balancer) ile yoğunluk yönetimi |
| GPS cihazının bozuk veya hatalı olması | Çevredeki kişilerden Bluetooth ile bilgi alma |

### 6.5 Çıktılar ve Etki

Grubun öngördüğü çıktılar şunlardır:

- **Araştırmacı yetiştirme:** Bir yüksek lisans öğrencisine burs verilecek, makine öğrenmesi ve mobil uygulama deneyimi olan nitelikli bir eleman yetiştirilecektir.
- **Bilimsel çıktı:** Bir uluslararası dergi makalesi ve üç konferans bildirisi.
- **Ekonomik ve ticari çıktı:** MEBA'nın patentlenmesi.
- **Sosyal çıktı:** AKUT ve itfaiye gibi kurumlarla hızlı iletişim.

Öngörülen etkiler arasında uygulamanın bir güven ortamı oluşturarak insanların psikolojisini olumlu etkilemesi, düşme tespitiyle enkaz belirleme üzerine yeni bir çalışma alanı açılması, sağlık giderlerinin azalması ve ülke içinde hızlı haberleşmeyle ulusal güvenliğe katkı vardır.

### 6.6 Bütçe

Toplam bütçe 31.287,64 TL'dir. Kalemler şunlardır:

- Makine ve teçhizat: iki monitör ve bir taşınabilir disk
- Sarf: büro ve kırtasiye ürünleri, kablolar
- Hizmet alımı: sunucu kiralama, iOS ve Android geliştirici ortamları, GitHub Team ücreti
- Seyahat: 1000 TL
- Bursiyer: bir yüksek lisans öğrencisine bir yıllık 6600 TL
- Geçici işçi ücreti: jeofizik mühendisi danışman

## 7. 6. Sunum: Çevrim İçi ve Çevrim Dışı İmza Doğrulama

Bu sunum (grup 20) İngilizce yapılır. Altyazının büyük kısmı bozuk ya da döngüye girmiş durumdadır. Aşağıda yalnız anlaşılan kısımlar ve kısa notta aktarılan slayt tablosu yer alır.

### 7.1 Konu

Önerinin konusu, çevrim içi (online) ve çevrim dışı (offline) imza doğrulamanın birleştirildiği bir yaklaşımdır. Sunumun planı giriş, projenin amacı, yöntem, deney sonuçları, etkiler, çıktılar ve kaynaklar olarak verilir. Girişte el yazısı analizinin çoğunlukla bilimsel laboratuvarlardaki deneyimli uzmanlar ve polis teşkilatı gibi kurumların belge inceleme birimleri tarafından yapıldığı anlatılır.

İmza analizi iki kategoridedir:

- **Çevrim içi:** İmza atılırken kamera veya hassas tablet ile kaydedilir.
- **Çevrim dışı:** İmza taranmış görüntü olarak alınır.

<!-- BELİRSİZ: 00:55:10 civarındaki amaç anlatımı altyazıda döngüye girmiş; anlaşılmıyor. -->

### 7.2 Yöntem

Önerilen sistem üç ana bileşenden oluşur:

- Çevrim içi öznitelik çıkarma: kalem ucu izleme (pen tip tracking)
- Çevrim dışı öznitelik çıkarma: gradyan öznitelikleri
- İki yaklaşımın birleştirilmesi: destek vektör makineleri

Akış iki koldan ilerler. Web kamerasıyla çevrim içi kolda veri toplama, ön işleme, öznitelik çıkarma ve sınıflandırma yapılır. Tarayıcıyla çevrim dışı kolda da aynı adımlar uygulanır. Her kolun ayrı sınıflandırma sonucu vardır. Eşleştirme için çevrim içi yaklaşımda dinamik zaman bükme (Dynamic Time Warping), çevrim dışı yaklaşımda Öklid uzaklığı kullanılır. İki sonucun birleştirilmesi SVM ile yapılır.

> **Ek bilgi (derste anlatılmadı):** Dinamik zaman bükme, hızları farklı olabilen iki zaman serisini hizalayarak benzerliklerini ölçer. Aynı kişi imzasını bir seferinde daha hızlı, bir seferinde daha yavaş atabilir. Noktaları birebir karşılaştırmak yerine serilerin en iyi hizalandığı yol aranır. Bu nedenle imza gibi dinamik verilerde sık kullanılır.

#### Çevrim İçi Kol: Kalem Ucu İzleme

Video karelerine şu ön işleme adımları uygulanır:

- Gürültü süzme: video karelerindeki istenmeyen pikseller atılır.
- İkilileştirme (binarization): kalem bölgesi beyaz, diğer bölgeler siyah piksellerle gösterilir.
- Alan açma (area opening): kalem bölgesi dışında kalan küçük beyaz bölgeler silinir.

Öznitelik, her karedeki kalem ucunun konumudur. Kalem ucu, karedeki en alt beyaz piksel olarak belirlenir.

<!-- BELİRSİZ: Ön işlemenin 1. adımı altyazıda anlaşılmıyor; adımlar 2'den başlıyor. -->

#### Çevrim Dışı Kol: Gradyan Öznitelikleri

Gradyan yönü 12 yöne eşlenir ve her yön için gradyan büyüklüğünün ortalaması hesaplanır. Görüntü $4 \times 4$ bloğa bölünür ve her blokta yön sayıları çıkarılır. Slaytta ham gradyan özniteliklerinin ortalama ve sayı değerlerine bir örnek gösterilir.

### 7.3 Deney Sonuçları

Kısa notta aktarılan slayt tablosu şöyledir:

| Yaklaşım | Doğruluk | FAR | FRR | AER |
| --- | --- | --- | --- | --- |
| Çevrim içi | 63,46 | 45,38 | 27,69 | 36,54 |
| Çevrim dışı | 74,04 | 19,23 | 32,69 | 25,96 |
| Birleşik | 76,92 | 11,54 | 34,62 | 23,08 |

<!-- BELİRSİZ: Tablo değerleri altyazıda okunmuyor; kısa nottaki slayt aktarımından alındı. Veri kümesi bilgisi altyazıda bozuk ("13 yazıları", "30 genet ve 25") ve yazar ile imza sayıları doğrulanamadı. -->

> **Ek bilgi (derste anlatılmadı):** FAR (False Acceptance Rate), sahte bir imzanın yanlışlıkla kabul edilme oranıdır. FRR (False Rejection Rate), gerçek bir imzanın yanlışlıkla reddedilme oranıdır. Biri düşürüldüğünde diğeri genellikle yükselir. Bu yüzden iki oran birlikte raporlanır.

Tablodaki AER, FAR ile FRR'nin ortalamasıdır. Doğruluk da $100 - \text{AER}$ olarak tutar (ara adım eklendi):

$$\text{AER} = \frac{\text{FAR} + \text{FRR}}{2}$$

- Çevrim içi: $(45,38 + 27,69)/2 = 36,535 \approx 36,54$; doğruluk $100 - 36,54 = 63,46$
- Çevrim dışı: $(19,23 + 32,69)/2 = 25,96$; doğruluk $100 - 25,96 = 74,04$
- Birleşik: $(11,54 + 34,62)/2 = 23,08$; doğruluk $100 - 23,08 = 76,92$

Birleşik yaklaşım en yüksek doğruluğu ve en düşük FAR'ı verir, ancak FRR'si en yüksektir. Yani sistem sahte imzayı daha az kabul eder, buna karşılık gerçek imzayı daha sık reddeder. Slaytta grafiklerde çevrim içi kırmızı, çevrim dışı yeşil, birleşik yaklaşım mor renktedir. İkinci grafik yazar ile FRR arasındaki ilişkiyi gösterir.

Etkiler ve çıktılar kısmı altyazıda anlaşılmıyor.

## 8. 7. Sunum: Veri Ambarında Kişisel Veri Tespiti

Bu öneri (grup 28), yeni bir bakış açısıyla veri ambarında kişisel veri tespiti için uygulama geliştirmeyi amaçlar. Ekipten biri projeden ayrıldığı için sunum tek kişiyle yapılır.

### 8.1 Temel Kavramlar

Sunum, konuya uzak dinleyiciler için temel kavramları açıklayarak başlar:

- **Kaynak sistem:** Verinin ilk oluşturulduğu yerdir. Bir uygulamanın ön yüzünde yapılan işlemler, faturalama gibi süreçlerin çıktıları veya şirket içi bir birimin çalışma sonuçlarını paylaştığı ortamlar buna örnektir.
- **Veri ambarı (data warehouse):** Analiz ve raporlama gibi amaçlarla farklı kaynak sistemlerden gelen verinin toplandığı, saklandığı ve yönetildiği ortamdır.
- **ETL (Extract, Transform, Load):** Kaynak sistemlerdeki verinin çıkarılıp dönüştürülerek veri ambarına yüklenmesi sürecidir. ODI gibi araçlarla ya da PL/SQL paketleri yazılarak yönetilebilir.
- **Yükleme logları:** ETL sürecinin ayrıntılarının tutulduğu kayıtlardır. Hangi verinin nereden, ne zaman, kim tarafından, hangi dönüştürmeyle nereye yazıldığını gösterir.
- **Kişisel veri:** Bir verinin kime ait olduğunu belirlenebilir kılan veridir. Kimlik ve banka bilgisi buna örnektir.

Kişisel Verilerin Korunması Kanunu, kişisel veriye sahip kurumlara verinin saklanması, işlenmesi ve erişilmesi konusunda sorumluluk yükler. Bu sorumluluklar karşılanmazsa ciddi yaptırımlar vardır. Dolayısıyla şirketlerin önce kendi ortamlarında tuttukları kişisel verileri tespit etmesi gerekir.

Veri akışı şöyle özetlenebilir:

```text
Arayüzler, süreçler, birimler --> Kaynak sistemler --(ETL)--> Veri ambarı --> Analiz ve raporlama
```

### 8.2 Mevcut ve Önerilen Yaklaşım

Mevcut yaklaşımda genellikle bir uygulama kullanılır. Bu uygulama kaynak sistemlerdeki ve veri ambarındaki her veriyi yerinden bağımsız olarak değerlendirir ve kişisel veri olup olmadığına karar verir. Varlık ismi tanıma (Named Entity Recognition), kural tabanlı yöntemler veya makine öğrenmesi kullanılır.

Grup, veri ambarındaki tespiti kaynak sistemlerdeki tespitten farklı yönetmeyi önerir. Yazılacak uygulama yükleme loglarını analiz ederek kaynak-hedef eşleştirmesi çıkarır. Kaynak sistemlerdeki kişisel veri tespit çıktıları kullanılarak verinin izi bu eşleştirme üzerinden sürülür ve veri ambarında nereye yüklendiği bulunur. Böylece kesinlik ve duyarlılığın artması beklenir. Grubun deyişiyle yaklaşım, şirketlerin elindeki veriyi, yani yükleme loglarını kullanmaktan ibarettir.

> **Ders sonrası not:** Sunumda "precision ve recall, yani duyarlılık ve kesinlik" denir; sıra karışmıştır. Precision kesinlik, recall duyarlılık karşılığıdır.

### 8.3 Yöntem

Geliştirme üç aşamadan oluşur.

**Birinci aşama: veri simülasyonu ve etiketleme.** Uygulama için yükleme loglarına ihtiyaç vardır, ama hiçbir kurum bu logları paylaşmaz. Bu yüzden log üretilmesi gerekir:

1. Kamuya açık veriler toplanır.
2. Bu veriler, bir şirketteki farklı kaynak sistemlermiş gibi gruplanır.
3. Proje bilgisayarına kurulan açık kaynaklı MySQL'e yüklenir.
4. Bu verilerle uyumlu kişisel veriler üretilir ve onlar da MySQL'e yüklenir.
5. Açık kaynaklı Talend Open Studio ile farklı kombinasyonlarda ETL süreçleri tasarlanır ve veriler veri ambarıymış gibi yine MySQL'e yüklenir.
6. Bu yükleme süreci sonunda gerekli log kayıtları elde edilir.

Başarıyı sonunda ölçebilmek için kişisel verilerin kaynak sistemlerdeki yerleri ve ETL sonucunda yüklendiği yerler etiketlenir. Yani etiketler baştan bilindiği için, uygulamanın bulduğu yerler bunlarla karşılaştırılabilir.

**İkinci aşama: uygulama geliştirme.** Planlanan açık kaynaklı uygulama geliştirilir.

**Üçüncü aşama: dokümantasyon.** Uygulamanın amacını, hedefini ve başarısını anlatan bir doküman hazırlanır. Bu doküman kullanım rehberi, öngörülen problemlere çözümler ve başvurulacak kaynakları içerir.

### 8.4 Proje Yönetimi

| Aşama | Süre | Başarıya katkı |
| --- | --- | --- |
| Veri simülasyonu ve etiketleme | 1. ay | %30 |
| Açık kaynaklı uygulamanın geliştirilmesi | 2-5. aylar | %60 |
| Dokümantasyon | 6. ay | %10 |

### 8.5 Risk Yönetimi ve Hocanın Yorumu

Grup iki risk öngörür:

- **Bütçe desteğinin kesilmesi:** Proje özel sektöre anlatılarak destek aranacaktır.
- **Ekipten birinin ayrılması:** Yüksek lisans yapan ve uygulama geliştirme konusunda yetkin bir kişi, bütçelenen bursla projeye dahil edilecektir.

Sunumda ayrıca ekibin neden yetkin olduğunu göstermek için kısa özgeçmişler de vardır: veri ambarı modelleme ve ETL süreci tasarımı deneyimi ile uygulama geliştirme deneyimi.

Sunum bitince hoca, "senin risklerden biri aslında gerçekleşti" der. Sunan kişi, ekibe başka birini ekleyebileceğini, ama hocayla paylaşılan sürüme sadık kalmak için sunumu değiştirmediğini açıklar. Hoca bunu uygun bulur.

> **Hocanın vurgusu:** "Senin risklerden biri aslında gerçekleşti." Hocanın bu kısa yorumu, öneride yazılan bir riskin proje sürerken, hatta sunum günü bile gerçekleşebileceğini hatırlatır.

Bu örnekte ikinci riskin B planı gerçekten işe yarayacak kadar somuttur: Hangi yetkinlikte birinin, hangi bütçe kalemiyle alınacağı bellidir.

## 9. 8. Sunum: CNN ile Hava Tahmini

Bu sunum (grup 30) İngilizce yapılır. Altyazının büyük kısmı bozuk ya da döngüye girmiş durumdadır. Aşağıda yalnız anlaşılan kısımlar yer alır.

### 9.1 Konu

Önerinin başlığı, büyük veriyle makine öğrenmesi tekniklerinin uygulanmasıdır. Uygulama alanı hava tahminidir. Sunumda makine öğrenmesi yöntemlerinin atmosferdeki süreçleri anlamaya başarıyla uygulandığı problem kategorileri sayılır:

- **Sayısal hava tahmini (Numerical Weather Prediction) sistematik hatalarının düzeltilmesi:** Tahmin çıktıları gözlem verisi kullanılarak sonradan işlenir. Amaç yanlılıkları (bias) gidermek, çözünürlüğü artırmak veya yerel topoğrafik etkileri çözmektir.
- **Uç olayların tespiti (extreme detection):** Nadir olayların tahmin edilmesi veya tespit edilmesi üzerine bir sınıflandırma problemidir.

Sunumda doğrusal regresyon modellerinin hava tahmininde yalnızca yanlılık gidermekten daha geniş bir bağlamda kullanıldığı da söylenir.

<!-- BELİRSİZ: 01:22-01:26 arasındaki kısımlar altyazıda döngüye girmiş. Diğer kategoriler ve proje amacı anlaşılmıyor. -->

### 9.2 Yöntem

Çalışmada sayısal hava modelleriyle birlikte CNN modellerinin kullanılması önerilir. Bu cümlenin devamı altyazıda anlaşılmıyor. Girdi olarak atmosferin 1000, 700 ve 500 basınç seviyelerindeki Z parametresi kullanılır. Bu parametre, belirli bir basınç değerine ulaşılan atmosfer yüksekliğini gösterir. Sunuma göre bu seviyeler deniz seviyesinden tipik olarak 1000, 3000 ve 5500 metreye karşılık gelir.

<!-- BELİRSİZ: Altyazıda "Z at 1700 at 500" geçiyor; "1000, 700 ve 500" olarak okundu. -->

> **Ders sonrası not:** Bu yükseklikler büyük olasılıkla 700 hPa için yaklaşık 3000 m, 500 hPa için yaklaşık 5500 m olarak doğrudur. Fakat 1000 hPa yüzeyi büyük olasılıkla deniz seviyesine çok daha yakındır (yaklaşık 100 m). Sunumdaki 1000 m değeri bu seviye için uygun görünmüyor.

İki mimari karşılaştırılır:

| Özellik | 2B CNN | 3B CNN |
| --- | --- | --- |
| Evrişim katmanı | 2 | 2 (aynı yapı) |
| Çekirdek | $3 \times 3$ | $3 \times 3 \times 3$ |
| Maksimum havuzlama (max pooling) | $2 \times 2$ | $2 \times 2 \times 2$ |
| Çıkış | Tam bağlantılı katman ve softmax | Tam bağlantılı katman ve softmax |

Evrişimden sonra maksimum havuzlama uygulanır. Tam bağlantılı katman çıkışa bağlanır. Softmax katmanı çıkış katmanından hemen önce gelir ve çıkış katmanıyla aynı sayıda düğüme sahip olmalıdır.

<!-- BELİRSİZ: Çıkış sınıfları altyazıda "rain and drive" diye geçiyor; büyük olasılıkla yağışlı ve kuru (rain/dry). Doğrulanamadı. -->

İki model de TensorFlow ile gerçeklenecek, verinin %80'iyle 300 epoch boyunca eğitilecektir. Kalan %20, modellerin doğruluğunu test etmek için doğrulama verisi olarak kullanılacaktır. Sunumda TensorFlow, makine öğrenmesi için araçlar, kütüphaneler ve topluluk kaynaklarından oluşan uçtan uca açık kaynaklı bir platform olarak tanıtılır.

Sonuç kısmı altyazıda anlaşılmıyor.

## Dersin Toparlaması

Bu ders sekiz farklı alandan proje önerisini aynı iskelet üzerinde gösterdi: görme engelli asistanı, CNC çarpışma önleme, histopatolojide çekirdek sınıflandırma, sıfırıncı gün atağı tespiti, düşmeyle enkaz tespiti, imza doğrulama, veri ambarında kişisel veri tespiti ve hava tahmini. Hepsinde mevcut çözümün somut bir eksiği gösterilip yöntemin bunu nasıl kapatacağı anlatılmaya çalışıldı: ek donanım gerektirmemek, kaza olmadan önlem almak, güncel veri kullanmak, paket içeriğini de analize katmak veya elde zaten bulunan logları kullanmak gibi.

Hocanın derste yaptığı tek içerik yorumu risk yönetimi üzerineydi. 7. sunumda öngörülen bir risk sunum günü gerçekleşmiş, grup da B planını anlatmıştı. Hoca sunumların sonuna gelindiğini söyleyerek dersi kapattı.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
