# Ders 10 Genişletilmiş Notu: Proje Önerileri Sunumları: Biyomedikal Veri Setleri, Bölütleme ve Sınıflandırma Yaklaşımları

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Proje dönemine giriş
- 2. Kolorektal kanser histolojisinde çekirdek tespiti ve sınıflandırması
- 3. Deri lezyonu sınıflandırması: ISIC veri setleri ve transfer öğrenme
- 4. Serviks sitolojisi: Herlev veri seti ve N/C oranı
- 5. Sıvı bazlı sitoloji ve serviks veri setleri
- 6. Kan hücresi bölütlemesi: bölge tabanlı elips uydurma
- 7. Beyin tümörü bölütlemesi ve yer gerçekliği kavramı
- 8. Düşük dereceli gliomda bölütleme ve şekil öznitelikleri
- 9. Diğer proje önerileri
- 10. Örnek Sorular

## 1. Proje dönemine giriş

Bu derste dönemin proje aşamasına geçildi. Her öğrenci seçtiği biyomedikal veri setini, ilgili yayınları ve aklındaki yöntemi 10-15 dakikalık kısa bir sunumla anlattı. Hoca her sunumun ardından veri setinin yapısını, verilen yer gerçekliği (ground truth) bilgisini ve uygun yöntemleri tartışarak bir yön çizdi.

Bütün sunumlarda tekrar eden yaklaşım şuydu: önce makalede ne yapıldığı anlaşılır ve tekrar edilir, sonra bunun üzerine güncel ya da başka bir alanda kullanılmış bir yöntem uyarlanarak yeni bir şey önerilir. Hoca ayrıca tek bir veri setine bağlı kalınmamasını, birkaç veri setiyle çalışılıp sonuçların ayrı ayrı verilmesini istedi.

> **Hocanın vurgusu:** Makaledeki yaklaşımı yapıp üstüne kendimiz yeni bir şeyler önermemiz lazım. Problemini tanıyan öğrenci, başka bir alanda kullanılmış bir yöntemi bu probleme getirmeyi kendisi de önerebilir.

## 2. Kolorektal kanser histolojisinde çekirdek tespiti ve sınıflandırması

### 2.1 Veri seti

İlk sunum, kolon kanseri (kolorektal adenokarsinom) histoloji görüntülerinden oluşan CRC çekirdek veri setiyle ilgiliydi. Ekranda açılan makaleye göre (ekrandan, 00:10:00):

- 100 adet H&E boyalı histoloji görüntüsü vardır; hepsi $500\times500$ pikseldir.
- Görüntüler 9 hastanın 10 tüm-slayt (whole-slide) görüntüsünden, örtüşmeyen alanlardan kesilmiştir. Piksel çözünürlüğü $0{,}55\,\mu m$/piksel, büyütme 20x'tir.
- Kesilen alanlar hem normal hem kötü huylu doku görünümünü temsil edecek biçimde seçilmiştir. Gerçek hayattaki aykırı durumları temsil etmek için artefakt, aşırı boyama (over-staining) ve başarısız otomatik odaklama içeren alanlar da vardır.
- Toplam 29.756 çekirdek merkezinden işaretlenmiştir. Bunların 22.444'ünün sınıf etiketi vardır, kalan 7.312'si etiketsizdir.
- Sınıflar ve sayıları: epitel 7.722, fibroblast 5.712, enflamatuvar 6.971, diğer (miscellaneous) 2.039. Enflamatuvar sınıfı lenfosit, plazma, nötrofil ve eozinofil çekirdeklerini; "diğer" sınıfı adiposit, endotel, mitotik figür ve nekrotik (ölü) hücre çekirdeklerini kapsar.

Sınıf sayılarının toplamı $7722+5712+6971+2039=22444$ eder ve etiketli çekirdek sayısıyla tutarlıdır; $29756-22444=7312$ de etiketsiz çekirdek sayısını verir (python ile doğrulandı).

### 2.2 Tespit mi, sınıflandırma mı?

Hoca, görüntüde hücrelerin nokta olarak işaretlendiğini ve hücre tiplerinin de verildiğini diğer öğrencilere açıkladı. Bu bilgiyle iki farklı problem kurulabilir:

- **Tespit (detection):** Hücrelerin konumu bilindiği için, merkezleri bulan bir sistem eğitilebilir. Makalede tespit başarımı kesinlik (precision), duyarlılık (recall) ve F1 skoruyla ölçülmüş; işaretli merkezin 6 piksel yarıçapındaki bölge yer gerçekliği kabul edilmiştir (ekrandan, 00:10:00). Makale, önerdiği uzamsal kısıtlı CNN (SC-CNN) türevlerini diğer yöntemlerle F1 skoru üzerinden karşılaştırmıştır.
- **Sınıflandırma (classification):** Yer gerçekliğindeki merkezlerin çevresinden yalnız o hücreyi kaplayan bir yama (patch) kesilir ve hücrenin tipi belirlenir. Makalede bu deney, merkezinde bir çekirdek bulunan $27\times27$ piksellik yamaların 4 sınıfa ayrılmasıyla yapılmış; başarım sınıf başına F1 ve çok sınıflı AUC ile ölçülmüştür (ekrandan, 00:15:00).

Öğrenci tespit için Mask R-CNN ve U-Net'e baktığını söyledi. Hoca ise öncelikle sınıflandırma kısmını önerdi: yer gerçekliğinden hücre konumları alınıp yamalar kesilir, dört sınıf güncel yöntemlerle ayrılır.

> **Hocanın vurgusu:** Bu alanda seyrek öğrenme (sparse learning) ve sözlük öğrenme (dictionary learning) boş kalmış durumda. Değişken yama boyutlarıyla bunlar uyarlanabilir. Metrik öğrenme (metric learning) de denenebilir.

> **Ek bilgi (derste anlatılmadı):** Sözlük öğrenmede her örnek, veriden öğrenilen bir "atom" kümesinin (sözlüğün) az sayıdaki elemanının doğrusal birleşimi olarak gösterilir; seyrek kodlama katsayıları öznitelik olarak kullanılabilir. Metrik öğrenme ise aynı sınıftaki örnekleri yakın, farklı sınıftakileri uzak tutan bir uzaklık ölçüsü öğrenmeyi amaçlar.

### 2.3 Hocanın çalışma grubunun önceki çalışmaları

Hoca aynı veri setinin daha önce kendi çalışma grubunda hücre tipi sınıflandırma problemi olarak ele alındığını söyledi ve yayınları gösterdi. Bunlardan biri yerel ikili örüntü (local binary patterns) ile hücre tipi sınıflandırmasıdır (ekrandan, 00:25:00). Bir sonraki sunumda açılan başka bir çalışmanın akışı şöyledir (ekrandan, 00:40:00):

```text
Görüntü yamaları
  -> Öznitelik çıkarma (evrişimsel sinir ağı, KSA)
  -> Öznitelik azaltma (temel bileşen analizi, TBA)
  -> DVM | Rastgele orman | Bagging | Stokastik boosting | YSA
  -> Karar birleştirme
```

Bu çalışmada evrişim katmanında $3\times3$ maskeler kullanılmış, çıkan öznitelikler TBA ile azaltılarak çeşitli sınıflandırıcılara verilmiş ve kararlar topluluk öğrenme mantığıyla birleştirilmiştir. Ekranda kısmen görünen sonuç tablosunda F1 / genel doğruluk değerleri DVM için 0,73 / 74,20, bagging için 0,66 / 68,34, rastgele ormanlar için 0,46 / 48,68, stokastik boosting için 0,68 / 69,73, karar ağacı için 0,54 / 55,34 olarak okunmaktadır (ekrandan, 00:40:00). <!-- BELİRSİZ: tablonun alt satırları (Adaboost ve birleştirme sonuçları) karede kesik. -->

## 3. Deri lezyonu sınıflandırması: ISIC veri setleri ve transfer öğrenme

### 3.1 Veri setleri

İkinci sunum dermoskopik deri lezyonu görüntüleriyle ilgiliydi. Öğrenci COVID-19 X-ışını veri setlerine de baktığını, ancak bu alanda çok çalışma yapıldığını ve çoğunun %98-99 doğruluk bildirdiğini söyleyerek ISIC yarışma veri setlerine yöneldi.

- ISIC yarışmaları 2016'da başlar; 2016 ve 2017 verileri azdır.
- **ISIC 2018 (HAM10000):** yaklaşık 10 bin görüntü, hepsi eğitim için; 7 sınıf.
- **ISIC 2019:** 7 sınıfa 2 sınıf daha eklenmiş (skuamöz hücreli karsinom ve "yukarıdakilerin hiçbiri"); eğitim verisi 25.331 görüntü, test için yaklaşık 8 bin görüntü vardır.
- **ISIC 2020:** 33.126 eğitim, yaklaşık 10 bin test görüntüsü. Meta veride görüntü adı, hasta kimliği, cinsiyet, yaklaşık yaş, lezyonun vücuttaki yeri, tanı ve iyi/kötü huylu bilgisi vardır. Hedef (target) değişkeni iyi huylu için 0, kötü huylu için 1'dir. Ancak 33 bin görüntünün yaklaşık 32 bininde tanı "bilinmiyor" olarak verilmiştir.

### 3.2 Literatür

Öğrencinin gösterdiği çalışmalar (ekrandan, 00:35:00):

- CNN tabanlı melanom sınıflandırması (2019, ISIC 2018).
- Deri lezyonlarının CNN ile sınıflandırılması (TENCON 2019).
- Farklı çözünürlüklerde EfficientNet modellerinin topluluğu ve meta veri (2020); aynı ağ farklı görüntü çözünürlükleriyle eğitilip topluluğu alınmış; ISIC 2018 ve 2019 karşılaştırılmış.
- VGGNet, ResNet, AlexNet, GoogLeNet gibi derin ağların topluluğu (2018); ISIC 2017'de yaklaşık %89,4 ile 4. olmuş.

Öğrenci ISIC 2018'in 2020'de bile hâlâ kullanıldığını, konunun güncelliğini koruduğunu belirtti.

### 3.3 Hocanın yönlendirmesi ve transfer öğrenme

Hoca, tanı bilgisi eksik olduğu için 2020 yerine ISIC 2019'dan başlanmasını önerdi. Önce standart yöntemler denenmeli: güncel transfer öğrenme modelleri (ResNet, DenseNet, Inception). Yarışma sayfalarındaki forumlarda insanların hangi yöntemlerle uğraştığına da bakılabilir. Sonra yeni yaklaşımlar, örneğin yeni yeni gelmeye başlayan NAS (sinir mimarisi arama) tabanlı ağlar denenebilir. Sonuçlar 2018 ve 2019 için ayrı ayrı verilebilir.

Öğrenci, hocanın grubundaki CNN + PCA + topluluk çalışmasındaki (bkz. 2.3) yapıyı kendi veri setine uygulamayı önerdi. Hoca, oradaki DVM ve rastgele orman gibi klasik sınıflandırıcıların öncelikle denenebileceğini, sonra 4-5 farklı transfer öğrenme modelinin topluluğunun kurulabileceğini söyledi.

Hoca transfer öğrenmeyi kabaca şöyle anlattı: Daha önce büyük bir veri setiyle, genellikle ImageNet ile eğitilmiş ağlar vardır. ImageNet görüntüleri bizim biyomedikal görüntülerimizden farklıdır, ama bu eğitim sırasında filtre katsayıları epey güncellenmiş ve belli bir olgunluğa gelmiştir. Biz son katmanı ya da sondan belli bir derinliğe kadar olan katmanları kendi verimizle yeniden eğitir ve ağı kendi problemimize uyarlarız. Örneğin orijinal ağda 1000 sınıf varsa, çıkış katmanı yalnız bizim sınıf sayımıza göre yeniden ayarlanır.

## 4. Serviks sitolojisi: Herlev veri seti ve N/C oranı

### 4.1 Veri seti

Üçüncü sunum, rahim ağzı (serviks) kanseri taramasında kullanılan pap smear görüntüleriyle ilgiliydi. Sunumdaki bilgilere göre (ekrandan, 00:50:00): rahim ağzı kanseri dünyada kadınlarda meme kanserinden sonra en sık görülen kanserlerdendir (%11,6) ve yılda yaklaşık 437.000 yeni hasta görülür; pap smear ilk kez 1927'de gündeme gelmiş, 1940'lı yıllarda klinik kullanıma girmiştir; tarama ve erken tanı sayesinde mortalite son 5 yılda %70 düşmüştür. Veri seti tablosunda 917 örnek, 7 öznitelik ve sınıflandırma görevi görünmektedir.

Herlev veri setinde 917 tek hücre görüntüsü vardır; 3 sınıf normal, 4 sınıf anormal hücreleri içerir. Her görüntünün yanında hücrenin sitoplazma ve çekirdek olarak bölütlenmiş hâli de verilmiştir (ekrandan, 00:55:00).

### 4.2 Elle öznitelik çıkarma denemesi

Öğrenci birkaç görüntüde elle (handcrafted) bölütleme ve öznitelik çıkarmayı denediğini, ama sitoplazma ve çekirdeği ayrı ayrı bulmanın gürültülü görüntülerde verimli olmadığını gördüğünü söyledi; bu yüzden CNN tabanlı bölütlemeye yöneldi. Hoca, önce hücrenin bulunup sonra hücre sınırları içinde çekirdeğin aranabileceğini ekledi.

Hoca, bu veri setindeki bölütlenmiş görüntülerin model eğitimi için yer gerçekliği olduğunu açıkladı: hem hücreyi, hem sitoplazmayı, hem çekirdeğin yerini gösterir. U-Net, SegNet gibi bölütleme algoritmaları tam olarak bu tür veriyle çalışır.

### 4.3 N/C oranı ve sınıflar

Sınıflamada temel ölçüt çekirdek alanının sitoplazma alanına oranıdır (N/C oranı). Çekirdek büyüdükçe hücre kötü huylu kanser hücresine yaklaşır. Sunumdaki tablo (ekrandan, 00:55:00):

| Sınıf | 1 | 2 | 3 | 4 | 5 | 6 | 7 |
|---|---|---|---|---|---|---|---|
| N/C oranı | 0,01 | 0,03 | 0,35 | 0,27 | 0,38 | 0,49 | 0,60 |
| Nitel | çok küçük | küçük | orta | orta | büyük | çok büyük | çok büyük |

Öğrenci, sıralı gitmesi beklenen oranın 3. ve 4. sınıf arasında bozulduğunu (0,35 > 0,27) sordu. Hoca bunun bir yer değişikliği olabileceğini söyledi; ayrıntı için bu veri setiyle daha önce çalışmış bir öğrenciye danışılmasını istedi. Ayrıca bazı normal sınıflardaki biçimsiz görünen hücrelerin örnek alınırken parçalanmış hücreler olabileceğini belirtti.

### 4.4 Bölütleme problemi olarak kurulum

Hoca, bölütleme ağına verilecek maskeyi şöyle tarif etti: arka plan 0, sitoplazma 1 numaralı sınıf, çekirdek 2 numaralı sınıf. Böylece toplam üç sınıflı bir piksel sınıflandırması, yani bölütleme yapılır. Sınıflandırma algoritmaları da kullanılabilir ama o zaman öznitelik çıkarmak gerekir; bölütleme algoritmaları ise doğrudan bu maskelerle (arka plan, sitoplazma, çekirdek) eğitilir.

Eldeki 917 verinin bir kısmı test için ayrılmalıdır. Hoca K-katlı çapraz doğrulamayı hatırlattı: örneğin 100 örnek varsa 80'i eğitim, 20'si test için kullanılır ve beş parçanın her birinde test parçasının yeri değişir.

Hoca ayrıca grubunun daha önce çok katmanlı sitoloji küpleri üzerinde serviks kanseri erken teşhisi için çekirdek ve sitoplazma bölütlemesi çalıştığını, o veri setinin de indirilip kullanılmasını istedi.

## 5. Sıvı bazlı sitoloji ve serviks veri setleri

### 5.1 Bethesda sistemi ve sıvı bazlı sitoloji veri seti

Dördüncü sunum da serviks üzerineydi. Öğrenci dünya çapında kullanılan Bethesda sınıflama sistemini hatırlattı ve en önemli şeyin erken aşamadaki, düşük dereceli (LSIL) lezyonu yakalamak olduğunu söyledi. Herlev'deki hafif displazi düşük dereceli, şiddetli displazi yüksek dereceli olarak gruplanabilir. Normal hücrelerde çekirdek küçük bir noktadır; anormal hücrelerde çekirdek neredeyse sitoplazma kadar büyür.

Kullanmak istediği yeni veri seti sıvı bazlı sitoloji (liquid based cytology) pap smear görüntüleridir (ekrandan, 01:15:00):

- 4 kategoriye ait 963 pap smear görüntüsü.
- Kategoriler: yüksek dereceli skuamöz intraepitelyal lezyon (HSIL), düşük dereceli skuamöz intraepitelyal lezyon (LSIL), intraepitelyal malignite için negatif, skuamöz hücreli karsinom.

Yüksek dereceli görüntülerde büyük çekirdekler, düşük dereceli görüntülerde ortada küçük çekirdekler görülür.

### 5.2 Boya kalıntıları ve üst üste binen hücreler

**Soru:** Görüntülerdeki boya kalıntıları göz ardı mı edilmeli, ne yapılmalı? **Cevap:** Gölge benzeri bozulmalar histogram eşitleme ile azaltılabilir. Boya kalıntısı gibi yapılar şöyle ayıklanabilir: hücre merkezleri tespit edildikten sonra bunların az çok oval bir şekli olduğu bilinir; ovallikten uzak, en-boy oranı çok farklı olan koyu, çekirdek benzeri yapılar çıkarılır.

Öğrenci daha önce yuvarlaklık için $4\pi A/P^2$ biçiminde bir ölçü hesapladığını söyledi ($A$ alan, $P$ çevre). Hoca bunun kullanılabileceğini, hücre merkezleri bulunduktan sonra bağlantılı bileşen analizinin (connected component analysis) en-boy oranı gibi ölçüler de verdiğini ekledi.

> **Ek bilgi (derste anlatılmadı):** $4\pi A/P^2$ ölçüsü tam bir çember için 1'dir ($A=\pi r^2$, $P=2\pi r$ yerine konunca $4\pi\cdot\pi r^2/(4\pi^2 r^2)=1$); şekil uzadıkça ya da sınırı girintili çıkıntılı hâle geldikçe 1'den küçülür. Bu yüzden yuvarlak hücreleri uzun ya da düzensiz artefaktlardan ayırmakta kullanılır.

**Soru:** Bir yerde iki çekirdek görünüyor; bu iki hücre mi? **Cevap:** Üst üste oturmuş ya da yan yana iki hücre olabilir. Kesit alınıp lamelin içine konduğunda üst üste binmiş iki hücre de böyle bir görüntü oluşturabilir. Öğrenci, bir hücrede iki çekirdek olmasının doğrudan anormal sınıflandırma sebebi olduğunu belirtti.

Öğrenci önce hücreleri bölütlemesi gerektiğini, sonrasında çekirdek merkezleri ve konturlar üzerinden her şeyin hesaplanabileceğini söyledi. Hoca, derin öğrenme tabanlı bölütleme yöntemlerinden örneğin piramit yapılı yöntemlerin işe yarayabileceğini belirtti.

> **Hocanın vurgusu:** Ne kadar iyi bölütlersen yalnız üzerinde çalışacağın hücrelere o kadar yoğunlaşabilirsin. Önemli olan burada iyi ayırabilmek.

### 5.3 Serviks sitolojisinde açık veri setleri

Ders sırasında serviks hücreleri için hesaplamalı yöntemleri inceleyen bir derleme makalesi açıldı ve veri setleri tablosu incelendi (ekrandan, 01:25:00):

| Veri seti | Yıl | Tür | Görüntü sayısı | Amaç | Açıklama |
|---|---|---|---|---|---|
| Herlev | 2005 | Görüntü | 917 | Bölütleme, sınıflandırma | Bölütleme yer gerçekliği olan tek hücre görüntüleri; 7 sınıf |
| ISBI14 | 2014 | Görüntü | 16 EDF + 945 sentetik | Bölütleme | Farklı örtüşme derecelerinde hücreler; çekirdek ve sitoplazma bölütlemesi |
| ISBI15 | 2015 | Görüntü | 17 EDF (her biri 20 görüş alanı) | Bölütleme | Farklı örtüşme dereceleri ve görüş alanları; çekirdek ve sitoplazma bölütlemesi |
| CERVIX93 | 2018 | Görüntü | 93 EDF (her biri 20 görüş alanı) | Bölütleme, sınıflandırma | ISBI15'e benzer; 7 sınıf; bölütleme yalnız çekirdek noktaları için |
| Risk-Factors | 2017 | Metin | - | Sınıflandırma | Hasta bilgisi ve tıbbi geçmiş |

Hoca ISBI 2015 yarışmasının adının "Second Overlapping Cervical Cytology Image Segmentation Challenge" olduğunu ve daha önce grubunun bu veriyle çalıştığını, ancak eğitim ve test verisinin az olduğunu söyledi. ISBI14 ile ISBI15'in büyük olasılıkla birleştirilebileceğini, CERVIX93'ün ayrıca kullanılabileceğini belirtti.

Sıvı bazlı sitoloji veri setinde yalnız sınıf etiketi verildiği, bölütleme maskesi olmadığı anlaşıldı. Bu durumda bölütleme yapılmadan tüm görüntüden sınıflandırma yapılması gerekir. Risk-Factors veri seti ise yalnız metin tabanlı hasta bilgisi içerir, görüntü içermez.

### 5.4 İş bölümü önerisi

Hoca iki serviks projesini şöyle ayırdı:

- Biri Herlev ve CERVIX93 üzerinde bölütleme artı sınıflandırma yapar. Bölütlemede U-Net gibi standart bir yöntem ya da birkaç kaliteli bölütleme yöntemi kullanılır, ardından sınıflandırmaya geçilir.
- Diğeri daha derin, güncel bölütleme yapılarını uyarlar: çok ölçekli piramit ağ tabanlı modeller, DeepLab tipi yapılar, yinelemeli (recurrent) ağ tabanlı yöntemler ve dikkat (attention) tabanlı modeller. Bunlar için "Image Segmentation Using Deep Learning: A Survey" derlemesi kaynak gösterildi.

## 6. Kan hücresi bölütlemesi: bölge tabanlı elips uydurma

### 6.1 Veri seti ve literatür

Beşinci sunum eozinofil hücreleriyle ilgiliydi. Öğrenci eozinofilin ne olduğunu ve eozinofil sayısının yüksek ya da düşük olmasının hangi teşhislerle ilişkili olduğunu (ör. yüksekken adrenal yetmezlik, astım) anlattı; geçmişte kullanılan testleri (ELISA gibi enzim tabanlı testler, 2014'te invazif olmayan optik görüntüleme vb.) özetledi. Kaggle'daki veri setinde yaklaşık 3000 eozinofil görüntüsü vardır; her görüntüden bölütleme ile hem eozinofil hem diğer kan hücreleri çıkarılarak eğitim kümesi oluşturulması planlanıyordu.

### 6.2 Bölge tabanlı elips uydurma yöntemi

Öğrencinin uyguladığı yöntem "Cell Segmentation via Region-Based Ellipse Fitting" makalesine dayanıyordu (ekrandan, 01:35:00). Yöntem hücre görüntülerini otomatik ve eğiticisiz biçimde bölütler ve birbirine değen hücreleri böler. Öğrencinin anlattığı adımlar:

- **Alan kısıtı (area constraint):** Kan hücreleri birbirine benzer alana sahiptir ve gürültüden ya da diğer yapılardan bu yönüyle ayrılır. Nesnenin alanı bir eşiği geçiyorsa hücre kabul edilir.
- **Yuvarlaklık kısıtı (roundness constraint):** Kan hücreleri çember ya da elips biçiminde görünür. Bozuk hücreler, trombositler ya da arka planda kalan parlaklık farkları yuvarlak olmadığı için elenir. Eşik formülü $4\pi A/P^2$'dir. Örneğin aynı parlaklıkta çıkan ama yuvarlak olmayan bir bölge sayılmaz.
- **Bölge bölme (region splitting):** Üst üste binen hücreler için alan ve yuvarlaklık parametreleri kullanılarak bir nesnenin içinde iki ya da üç hücre olup olmadığı belirlenir ve nesne bölünür.

Hoca, MATLAB'de watershed tabanlı yöntemlerin de bulunduğunu hatırlattı.

### 6.3 MATLAB uygulaması

Öğrenci MATLAB App Designer ile hazırladığı bir arayüzü gösterdi (ekrandan, 01:40:00): görüntü yükleme, görüntüyü ters çevirme (invert), bölütleme ve ikili (BW) gösterim düğmeleri ile bölütlenmiş görüntü ve öznitelik tablosu. Örnek bir floresan hücre görüntüsünde bölütleme sonrası her nesnenin alanı ve ağırlık merkezi tabloya döküldü (ekrandan, 01:45:00); örneğin 1. nesne için alan 511, merkez $(15{,}89;\,8{,}74)$, 2. nesne için alan 1399, merkez $(13{,}11;\,154{,}79)$. Bu değerler MATLAB'in bölge özellikleri (`regionprops`) fonksiyonuyla elde edilir; alan, koordinatlar ve başka özellikler çıkarılabilir. Öğrenci, en büyük alanlı hücreyi eozinofil saymak gibi basit bir kuralın çok kaba kalacağını belirtti.

Hoca, yöntemin hazır kodunun makaleden alındığını, arayüzün ise öğrenci tarafından yazıldığını teyit etti. Eozinofil görüntülerinde ise görüntülerin döndürülmesinden kaynaklanan siyah kenar bölgeleri vardı; bunlarla denendiğinde bölütleme bozuldu.

> **Hocanın vurgusu:** Kenarlardaki o siyahlıklar bütün bölütlemeyi bozar. Arka plan rengiyle doldurulabilir.

### 6.4 Hocanın yönlendirmesi

Hoca, problemin yalnız eozinofil bulmaktan çıkarılıp dört akyuvar tipinin (eozinofil, lenfosit, monosit, nötrofil) sınıflandırılmasına dönüştürülmesini önerdi; eozinofilin içinde granül benzeri yapılar görülür, lenfositte görülmez. Bu sınıflandırma derin öğrenme ve transfer öğrenme ile yapılabilir. Bölütleme tarafında elips uydurma yöntemi alınabilir, ama derin öğrenme tabanlı bölütleme yöntemleriyle (örneğin U-Net benzeri bir yapıyla) karşılaştırılmalıdır. Hoca, CNN'in kendisinin bir sınıflandırma aracı olduğunu, bölütlemede kullanılacaksa sınıflandırma tabanlı bir bölütleme kurgusu gerektiğini de hatırlattı. Yer gerçekliğinin olup olmadığına bakılmasını istedi.

## 7. Beyin tümörü bölütlemesi ve yer gerçekliği kavramı

### 7.1 BraTS veri seti

Altıncı sunum beyin tümörü bölütlemesiyle ilgiliydi. Sunumdaki bilgiler (ekrandan, 01:55:00):

- Veri setinde 369 eğitim ve 125 doğrulama (validation) verisi vardır; test verisinin oluşturulması gerekir.
- Doğrulama verisi için yer gerçekliği verilmemiştir.
- Veri çok kipli (multimodal) MR taramalarıdır; T1, T1Gd, T2 ve T2-FLAIR taramaları ayrı ayrı `.nii` dosyalarında verilmiştir.
- Anlamsal (semantic) bölütleme için temel ölçütler: piksel doğruluğu (doğru sınıflandırılan piksel oranı), kesişim/birleşim (Intersection over Union, IoU) ve Dice katsayısı.

Dice katsayısı, $A$ tahmin edilen bölge ve $B$ yer gerçekliği olmak üzere:

$$\text{Dice}=\frac{2\,|A\cap B|}{|A|+|B|},\qquad \text{IoU}=\frac{|A\cap B|}{|A\cup B|}$$

Öğrenci ayrıca beyinde ayrılması gereken dokuları (gri madde, beyaz madde, beyin omurilik sıvısı), MR kaynaklı gürültünün giderilmesini ve BraTS yarışmasının dört görevini anlattı: bölütleme, ardından hastanın hayatta kalma süresinin tahmini gibi görevler. Bölütleme öncesinde göz ve kemik gibi yapılar görüntüden çıkarılır (kafatası soyma). Sunumda evrişimsel sinir ağının katmanları da özetlendi (ekrandan, 02:00:00): evrişim katmanı öznitelikleri saptar, doğrusal olmayan katman sisteme doğrusal olmayanlığı katar, havuzlama (downsampling) katmanı ağırlık sayısını azaltıp aşırı uyumu kontrol eder, düzleştirme (flattening) katmanı veriyi klasik sinir ağına hazırlar, tam bağlantılı katman sınıflandırmayı yapar.

### 7.2 Yarışmalarda doğrulama verisi

**Soru:** Doğrulama verisinin yer gerçekliği yoksa bölütleme kalitesi nasıl değerlendirilecek? **Cevap:** Yarışmalarda bazen şöyle yapılır: önce eğitim verisi verilir; deneme için yer gerçekliği olmayan bir doğrulama verisi verilir; katılımcılar sonuçlarını gönderir ve düzenleyiciler en başarılı olanı seçer. Ayrıca bir test verisi verilmeyebilir. Bu durumda yalnız etiketli eğitim verisiyle çalışılır: bunun bir kısmı test için ayrılır ya da bir yılın verisiyle eğitilip test etiketleri verilmiş başka bir yılın verisiyle test edilir. Ekranda BraTS 2015 için yer gerçekliği içeren eğitim verisinin ve ayrı test verisinin bulunduğu, BraTS 2017-2018 için de test verisinden söz edildiği görüldü. Hoca, beyin tümörü bölütleme yayınlarında kaç verinin eğitim, kaçının test için kullanıldığının yazdığını, bunların okunmasını istedi. Makalede "segmentation benchmark" denmesinden de yer gerçekliğinin büyük olasılıkla mevcut olduğu çıkarılabilir.

### 7.3 Yer gerçekliği kavramı

Hoca, öğrencinin gösterdiği bir şeklin yer gerçekliği olmadığını, yalnız bir bölgeye dikkat çektiğini belirtti ve kavramı yeniden açıkladı: Bir model eğitilecekse modelin ne bulacağı bilinmelidir. Burada tümör bulunacaksa eğitim verisinde tümörün yeri ya da yapısı gösterilmelidir. Önceki derste açılan histopatoloji görüntüsünde hücrelerin yanında bir yer gerçekliği resmi vardı ve bulunması gereken bölütler, hücreler orada çizilmişti. Algoritma buna göre eğitilir ve bölütleme yaptırılır.

> **Hocanın vurgusu:** Yer gerçekliği olmadan eğitim yapamazsın. Bulacağımız, tespit edeceğimiz şey neyse veri setinin bize onu vermesi lazım.

Bölütleme yöntemi olarak hoca, gönderdiği derlemedeki yöntemlerin değerlendirilmesini önerdi: U-Net'ler, dikkat tabanlı yöntemler, piramit yapıları; özellikle DeepLab ailesinin (DeepLabv3+ vb.) iyi sonuç verdiği söylenmektedir. Veri seti bulunamazsa konunun değiştirilebileceğini, illa Kaggle'a bağlı kalınması gerekmediğini, MR üzerine çok sayıda veri seti olduğunu söyledi.

## 8. Düşük dereceli gliomda bölütleme ve şekil öznitelikleri

Yedinci sunum, beynin destek dokusu olan glia hücrelerinden gelişen düşük dereceli gliomların MR görüntülerinde tespiti ve tümörün boyut ve şekil özelliklerinin genomik özelliklerle ilişkilendirilerek alt tiplerinin belirlenmesiyle ilgiliydi.

Makaleye göre yer gerçekliği şöyle oluşturulmuştur: bir radyolog bir yazılımla kanserli bölgeleri elle çizmiş, ardından doktorlardan oluşan bir heyet yanlışları düzeltmiş ve nihai yer gerçekliği elde edilmiştir. Elle bölütleme, otomatik bölütleme modelini eğitmek için yer gerçekliği olarak kullanılmıştır (ekrandan, 02:10:00). 110 hastanın görüntüleri kullanılmış; hasta başına ortalama 35 görüntü vardır ve yer gerçekliğiyle birlikte toplam 7858 görüntü elde edilmiştir. Bölütleme PyTorch'ta gerçeklenen U-Net ile yapılmış, kodlar GitHub'da paylaşılmıştır.

Bölütlenmiş tümörden üç şekil özniteliği çıkarılmıştır (ekrandan, 02:10:00):

- **Açısal standart sapma (Angular Standard Deviation, ASD):** Bir kesitte, kütlenin ağırlık merkezinden sınıra olan radyal uzaklıkların on eşit açılı dilimdeki standart sapmalarının ortalamasıdır. Tümör kenarındaki değişkenliği ve çembersel olmamayı ölçer; düşük değer çembere benzer şekli gösterir.
- **Sınırlayıcı elipsoit hacim oranı (Bounding Ellipsoid Volume Ratio, BEVR):** Bölütlenmiş FLAIR anormalliğinin hacminin onu sınırlayan en küçük elipsoidin hacmine oranıdır; düzensizliği üç boyutta yakalar. Tümör elipsoide iyi oturuyorsa (yüksek BEVR) düzenli sayılır.
- **Kenar dalgalanması (Margin Fluctuation, MF):** Ağırlık merkezinden sınır piksellerine uzaklıklar bulunur, bunlara tümör çevresinin %10'u uzunluğunda bir ortalama süzgeci uygulanır; süzme öncesi ve sonrası değerlerin farkının standart sapması alınır. Sınırdaki yüksek frekanslı değişimleri, yani pürüzlülüğü ölçer.

Sonuçlarda U-Net'in bulduğu tümör sınırı kırmızı, yer gerçekliği mavi çizilerek karşılaştırılmıştır. Örnek düşük, orta ve yüksek uyumlu bölütlemelerin Dice değerleri %50, %82 ve %95'tir; ortalama Dice katsayısı %82'dir (ekrandan, 02:15:00).

Hoca, buradaki U-Net yerine derlemedeki güncel bölütleme yöntemlerinin uygulanıp aynı yol üzerinden karşılaştırma yapılabileceğini önerdi.

> **Ek bilgi (derste anlatılmadı):** Ortalama süzgeci bir dizideki hızlı değişimleri bastırdığı için, süzme öncesi ve sonrası arasındaki fark yaklaşık olarak dizinin yüksek frekanslı bileşenidir. MF bu farkın standart sapması olduğundan, derste görülen alçak geçiren süzgeç mantığının şekil analizine bir uygulamasıdır.

## 9. Diğer proje önerileri

### 9.1 Kolorektal kanser derecelendirmesi

Bir sunum genişletilmiş kolorektal kanser (Extended CRC) derecelendirme veri setini tanıttı: 20x büyütmede çıkarılmış, örtüşmeyen büyük histoloji görüntüleri; 300 görüntüden 120'si normal, 120'si düşük dereceli, 60'ı yüksek dereceli kanser ($120+120+60=300$). <!-- BELİRSİZ: görüntü boyutu altyazıda bozuk ("4548 x 7548" benzeri bir değer söyleniyor), karede görünmüyor. --> Sunumda CNN'in çok sınıflı başarılı bir sınıflandırıcı olduğu özetlendi (ekrandan, 02:20:00). Hoca, makaledeki sınıflandırıcı tablosunu da sordu. Önerisi: çizge (graph) tabanlı derin öğrenme yöntemleri, özellikle günümüzde çok bilinen çizge sinir ağları ve aşırı öğrenme makineleri (extreme learning machines).

> **Ek bilgi (derste anlatılmadı):** Histolojide çizge tabanlı yaklaşımlarda genellikle her çekirdek bir düğüm, yakın çekirdekler arasındaki komşuluk bir kenar olarak alınır; böylece dokunun hücre düzeni (mimarisi) doğrudan modellenebilir. Aşırı öğrenme makinesi ise gizli katman ağırlıkları rastgele sabitlenen ve yalnız çıkış ağırlıkları kapalı biçimde (en küçük kareler) hesaplanan tek gizli katmanlı bir ağdır.

### 9.2 Omuz implantı X-ışını görüntüleri

Bir sunum, omuz implantlarının X-ışını görüntülerinden üreticinin sınıflandırılmasıyla ilgiliydi (ekrandan, 02:25:00). Total omuz artroplastisi (TSA), hasar görmüş omuz başının protezle değiştirildiği bir ameliyattır. Yıllar sonra protezin bakımı ya da değişimi gerektiğinde modeli ve üreticisi bilinmeyebilir; ameliyat öncesi doğru tanımlama, doğru ekipman ve yöntemin seçimi için gereklidir. Makalede 4 üretici ve 16 farklı modele ait görüntülerde, ImageNet gibi alan dışı veriyle önceden eğitilmiş derin CNN'lerin 10-katlı çapraz doğrulamada yaklaşık %80 doğrulukla üreticiyi bulduğu, diğer sınıflandırıcıların %56 ya da daha az doğrulukta kaldığı bildirilmiştir.

Hoca problemi dar buldu ve daha genel bir göğüs X-ışını sınıflandırma veri seti önerdi; zayıf denetimli (weakly supervised) sınıflandırma üzerine bir göğüs X-ışını veritabanı makalesi gösterildi. <!-- BELİRSİZ: veri setinin adı altyazıda bozuk ("A Shang Tsung 1 database on weekly supervised classification"); büyük olasılıkla ChestX-ray8 / NIH göğüs X-ışını veritabanı. -->

### 9.3 TIA Lab veri setleri

Konusu henüz belirlenmemiş iki öğrenciye hoca TIA Lab'ın veri setleri sayfasından seçim yaptırdı. Biri hiperspektral görüntülerde iyi sonuç aldığı transfer öğrenmeyle devam etmek istedi; hoca PanNuke veri seti üzerinde önce transfer öğrenme yöntemlerinin denenmesini, sonra güncel yeni yöntemlere bakılmasını önerdi. Diğerine, Eylül 2019 tarihli ve hem bölütleme hem sınıflandırma görevi içeren bir veri seti verildi; ikisinden biri seçilerek ilerlenecek. <!-- BELİRSİZ: altyazıda "konsept data set" geçiyor; büyük olasılıkla CoNSeP veri seti. -->

## 10. Örnek Sorular

Bu derste ekranda soru ya da alıştırma gösterilmedi; aşağıdaki sorular sunumlar sırasında sözlü sorulan sorulardır.

**Soru 1** (derste sözlü, 00:56:49): Herlev veri setinde N/C oranı sınıflar boyunca artması beklenirken 3. sınıfın değeri (0,35) 4. sınıfınkinden (0,27) büyük çıkıyor (ekrandan, 00:55:00). Bunun anlamı nedir?

> **Cevap (derste verilen):** Hoca bunun sınıfların yerinin değişmiş olabileceğini söyledi; ölçüt çekirdek/hücre oranıdır ve çekirdek büyüdükçe hücre kötü huyluya yaklaşır. Kesin açıklama için veri setiyle daha önce çalışmış birine danışılmasını istedi.

**Soru 2** (derste sözlü, 01:15:33): Sıvı bazlı sitoloji görüntülerindeki boya kalıntıları nasıl ele alınmalı?

> **Cevap (derste verilen):** Gölgeler histogram eşitleme ile azaltılabilir. Hücre merkezleri bulunduktan sonra bağlantılı bileşen analiziyle her nesnenin en-boy oranı gibi ölçüleri hesaplanır; oval olmayan, en-boy oranı çok farklı koyu yapılar çıkarılır. Yuvarlaklık ölçüsü $4\pi A/P^2$ de bu amaçla kullanılabilir.

**Soru 3** (derste sözlü, 01:16:57): Görüntüde iki çekirdekli bir yapı görülüyor. Bu iki hücre mi?

> **Cevap (derste verilen):** Üst üste ya da yan yana oturmuş iki hücre olabilir; kesit lamele konduğunda üst üste binen hücreler böyle görünebilir.

**Soru 4** (derste sözlü, 01:51:39): BraTS'ta doğrulama verisinin yer gerçekliği yoksa bölütleme kalitesi nasıl değerlendirilir?

> **Cevap (derste verilen):** Yarışmalarda doğrulama verisi çoğu zaman etiketsiz verilir; katılımcıların gönderdiği sonuçları düzenleyiciler değerlendirir. Kendi değerlendirmen için etiketli eğitim verisinin bir kısmı test için ayrılır ya da test etiketi verilmiş başka bir yılın verisi kullanılır.

**Soru 5** (derste sözlü, 02:02:24): Bir bölütleme modeli eğitilecek. Eğitim verisinde ne bulunmalıdır?

> **Cevap (derste verilen):** Modelin bulması istenen şeyin (burada tümörün yeri ve yapısı) çizildiği yer gerçekliği maskesi bulunmalıdır. Model buna göre eğitilir ve çıktısı buna göre ölçülür. Yer gerçekliği olmadan eğitim yapılamaz.

## Dersin Toparlaması

Bu ders, öğrencilerin proje önerilerini sunduğu ve hocanın her birini teknik açıdan yönlendirdiği bir proje toplantısıydı. Sunumlar histopatoloji (kolorektal kanser çekirdekleri ve derecelendirme), sitoloji (Herlev, sıvı bazlı sitoloji, ISBI ve CERVIX93), dermoskopi (ISIC), kan hücreleri ve MR (BraTS, düşük dereceli gliom) gibi farklı biyomedikal görüntü türlerini kapsadı. Tartışmaların ortak noktası problemi doğru kurmaktı: tespit mi, bölütleme mi, sınıflandırma mı yapılacağı ve bunun için veri setinin hangi düzeyde yer gerçekliği sunduğu.

Yöntem tarafında hoca her öğrenciye önce standart bir taban çizgisi (transfer öğrenme ile ResNet, DenseNet, Inception; bölütlemede U-Net) kurmasını, ardından güncel yöntemleri (seyrek ve sözlük öğrenme, metrik öğrenme, DeepLab ve piramit yapıları, dikkat tabanlı modeller, çizge sinir ağları, aşırı öğrenme makineleri, topluluk modelleri) uyarlamasını önerdi. Önceki derslerde görülen PCA, öznitelik çıkarma, sınıflandırıcılar, yer gerçekliği ve bölütleme kavramları bu derste gerçek veri setleri üzerinde uygulamaya döküldü. Sonraki haftalarda veri setlerinin indirilip ön denemelere başlanması bekleniyor.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
