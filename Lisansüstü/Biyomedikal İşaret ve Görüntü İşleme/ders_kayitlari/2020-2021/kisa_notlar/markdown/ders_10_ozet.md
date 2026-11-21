# Ders 10 Çalışma Özeti

## Genel Konular

- Proje dönemine giriş: öğrenci proje önerilerinin tartışılması
  - Bu derste öğrenciler seçtikleri biyomedikal veri setlerini ve yöntem fikirlerini kısa sunumlarla anlattı. Hoca her sunumda veri setinin yapısını, yer gerçekliği (ground truth) bilgisini ve uygun yöntemleri tartışarak yön çizdi.
  - Ortak tema: önce makaledeki yaklaşımı anlamak ve tekrar etmek, sonra güncel bir yöntemle üstüne yeni bir şey önermek; mümkünse tek değil birkaç veri setiyle çalışmak.
- Kolorektal kanser histoloji veri seti (CRC çekirdek veri seti) ile tespit ve sınıflandırma
  - Makaledeki veri (ekrandan, 00:10:00): 9 hastanın 10 tüm-slayt görüntüsünden kesilmiş, H&E boyalı, $500\times500$ piksellik 100 görüntü; 20x büyütme, piksel çözünürlüğü $0{,}55\,\mu m$. Toplam 29.756 çekirdek merkezi işaretli; bunların 22.444'ü sınıf etiketli, 7.312'si etiketsiz.
  - Sınıflar: epitel (7.722), fibroblast (5.712), enflamatuvar (6.971), diğer (2.039) (ekrandan, 00:10:00). Görüntüler artefakt, aşırı boyama ve başarısız otomatik odaklama gibi gerçekçi aykırı durumları da içerir.
  - Problem iki türlü kurulabilir: çekirdek merkezlerinin tespiti (detection) ya da yer gerçekliğindeki merkezlerin çevresinden yama (patch) kesip hücre tipini sınıflandırma. Makalede sınıflandırma $27\times27$ piksellik yamalarla yapılmıştır (ekrandan, 00:15:00).
  - Hocanın önerisi: tespit yerine sınıflandırmaya odaklanmak; değişken boyutlu yamalarla seyrek öğrenme (sparse learning), sözlük öğrenme (dictionary learning) ya da metrik öğrenme (metric learning) denemek.
- Deri lezyonu sınıflandırması (ISIC yarışma veri setleri)
  - 2018: yaklaşık 10 bin eğitim görüntüsü, 7 sınıf. 2019: 2 sınıf daha eklenmiş (9 tanı), 25.331 eğitim görüntüsü. 2020: 33.126 eğitim, yaklaşık 10 bin test görüntüsü; iyi huylu (0) / kötü huylu (1) hedefi eklenmiş, ama tanı bilgisi görüntülerin çoğunda "bilinmiyor".
  - Literatürde CNN ve topluluk (ensemble) modelleri kullanılmış: farklı çözünürlüklerde EfficientNet topluluğu, VGG, ResNet, AlexNet, GoogLeNet topluluğu (ISIC 2017'de yaklaşık %89,4 ile 4.lük) (ekrandan, 00:35:00).
  - Hocanın önerisi: ISIC 2019'dan başlamak; önce transfer öğrenme (ResNet, DenseNet, Inception) gibi standart yöntemler, sonra NAS tabanlı ağlar gibi yeni yaklaşımlar; sonuçları 2018 ve 2019 için ayrı vermek.
- CNN öznitelikleri + PCA + topluluk öğrenme (hocanın çalışma grubunun önceki bir çalışması)
  - Akış (ekrandan, 00:40:00): evrişimsel sinir ağı ile öznitelik çıkarma → temel bileşen analizi (TBA/PCA) ile öznitelik azaltma → DVM, rastgele orman, bagging, stokastik boosting, YSA → karar birleştirme.
- Rahim ağzı (serviks) sitolojisi: Herlev pap smear veri seti
  - 917 görüntü, 7 sınıf (3 normal, 4 anormal) (ekrandan, 00:50:00). Her görüntüde hücre, sitoplazma ve çekirdek bölütlenmiş yer gerçekliği vardır.
  - Sınıflamada çekirdek/sitoplazma (N/C) oranı önemlidir: çekirdek büyüdükçe hücre kötü huyluya yaklaşır. Tablodaki N/C değerleri (ekrandan, 00:55:00): 0,01; 0,03; 0,35; 0,27; 0,38; 0,49; 0,60.
  - Bölütleme üç sınıflı bir problem olarak kurulabilir: arka plan 0, sitoplazma 1, çekirdek 2. U-Net, SegNet gibi ağlar bu yer gerçekliği maskeleriyle eğitilir.
- Sıvı bazlı sitoloji (liquid based cytology) pap smear veri seti
  - 4 kategoride 963 görüntü: yüksek dereceli skuamöz intraepitelyal lezyon (HSIL), düşük dereceli (LSIL), intraepitelyal malignite için negatif, skuamöz hücreli karsinom (ekrandan, 01:15:00). Yalnız sınıf etiketi vardır, bölütleme maskesi yoktur.
  - Boya kalıntıları: histogram eşitleme ile gölgeler azaltılabilir; çekirdek benzeri ama oval olmayan, en-boy oranı çok farklı koyu yapılar bağlantılı bileşen analiziyle ayıklanabilir. Yuvarlaklık ölçüsü $4\pi A/P^2$ de kullanılabilir.
- Serviks sitolojisinde açık veri setleri (ekrandan, 01:25:00)
  - Herlev (2005, 917 tek hücre görüntüsü, bölütleme + sınıflandırma), ISBI14 (16 EDF + 945 sentetik, bölütleme), ISBI15 (17 EDF, her biri 20 görüş alanı, bölütleme), CERVIX93 (2018, 93 EDF, bölütleme + sınıflandırma), Risk-Factors (2017, metin, sınıflandırma).
  - Hocanın önerisi: güncel derin öğrenme tabanlı bölütleme yöntemlerini (çok ölçekli piramit ağlar, DeepLab, yinelemeli ağ tabanlı ve dikkat (attention) tabanlı modeller) uyarlamak; standart taban çizgisi olarak U-Net.
- Kan hücreleri ve eozinofil: bölge tabanlı elips uydurma (region-based ellipse fitting)
  - Yöntem (ekrandan, 01:35:00): alan kısıtı ile hücre boyutuna uymayan nesneleri ayıklama, yuvarlaklık kısıtı ($4\pi A/P^2$) ile yuvarlak/eliptik olmayan nesneleri eleme, üst üste binen hücreleri bölge bölme (region splitting) ile ayırma.
  - MATLAB'de bir arayüzle bölütleme ve `regionprops` ile alan ve ağırlık merkezi çıkarımı gösterildi (ekrandan, 01:45:00). Görüntü kenarlarındaki siyah (döndürme kaynaklı) bölgeler bölütlemeyi bozdu.
  - Hocanın önerisi: yalnız eozinofil bulmak yerine dört akyuvar tipini (eozinofil, lenfosit, monosit, nötrofil) sınıflandırmak; watershed ve derin öğrenme tabanlı bölütleme ile karşılaştırma yapmak; siyah kenarları arka plan rengiyle doldurmak.
- Beyin tümörü bölütleme (BraTS yarışması)
  - 369 eğitim ve 125 doğrulama verisi; doğrulama verisinin yer gerçekliği verilmemiş. Taramalar T1, T1Gd, T2, T2-FLAIR; `.nii` uzantılı (ekrandan, 01:55:00).
  - Değerlendirme ölçütleri: piksel doğruluğu, kesişim/birleşim (IoU) ve Dice katsayısı $2|A\cap B|/(|A|+|B|)$.
  - Hoca, yarışmalarda doğrulama verisinin çoğu zaman etiketsiz verildiğini, sonuçların gönderilip yarışma düzenleyicisince değerlendirildiğini anlattı. Etiketli eğitim verisi olmadan model eğitilemez ve değerlendirilemez.
- Düşük dereceli gliom: MR bölütleme ve şekil öznitelikleri
  - Makalede 110 hasta, radyolog tarafından elle çizilip heyetçe düzeltilen yer gerçekliği; U-Net (PyTorch) ile bölütleme, ortalama Dice yaklaşık %82 (ekrandan, 02:15:00).
  - Üç şekil özniteliği (ekrandan, 02:10:00): açısal standart sapma (ASD), sınırlayıcı elipsoit hacim oranı (BEVR), kenar dalgalanması (MF). Bunlar genomik alt tiplerle ilişkilendiriliyor.
- Diğer öneriler
  - Genişletilmiş kolorektal kanser derecelendirme veri seti: 300 görüntü (120 normal, 120 düşük dereceli, 60 yüksek dereceli). Hocanın önerisi: çizge (graph) tabanlı sinir ağları ve aşırı öğrenme makineleri (extreme learning machine).
  - Omuz implantı X-ışını üretici sınıflandırması: hoca problemi dar buldu, daha genel bir göğüs X-ışını sınıflandırma veri seti önerdi.
  - TIA Lab veri setleri (PanNuke vb.) üzerinde transfer öğrenme ile sınıflandırma.

## Hocanın Özellikle Vurguladığı Kısımlar

- Yer gerçekliği (ground truth) olmadan eğitim ve değerlendirme yapılamaz
  - Bölütlemede bulunması gereken bölgelerin (hücre, çekirdek, tümör) çizildiği maske gerekir. Algoritma buna göre eğitilir, çıktısı buna göre ölçülür. Veri seti seçerken ilk bakılacak şey budur.
- Makaledeki yöntemi tekrar et, sonra üstüne kendi önerini koy
  - Önce standart yöntemler (transfer öğrenme, U-Net) taban çizgisi olarak denenir, sonra güncel ya da başka alanda kullanılmış bir yöntem bu probleme uyarlanır.
- Transfer öğrenme
  - Büyük bir veri setinde (genellikle ImageNet) eğitilmiş ağın filtre katsayıları olgunlaşmıştır. Son katman ya da sondan belli bir derinliğe kadar olan katmanlar yeniden eğitilir ve çıkış, problemin sınıf sayısına uyarlanır (ör. 1000 sınıf yerine kendi sınıf sayın).
- Bölütleme kalitesi sonraki her adımı belirler
  - Hücreler ne kadar iyi bölütlenirse çekirdek merkezi, kontur, N/C oranı gibi ölçümler o kadar kolay ve doğru hesaplanır.
- Tek veri setine bağlı kalmamak
  - Birden fazla veri setiyle çalışmak ve sonuçları ayrı ayrı vermek önerildi; yarışma forumlarında başkalarının denediği yöntemlere bakmak da yararlıdır.

## Kısa Tekrar Notları

- Tespit (detection) = nesnenin yerini bulmak; sınıflandırma = yerini bildiğin nesnenin tipini bulmak. Konumlar biliniyorsa yama kesip sınıflandırma problemi kurulabilir.
- CRC çekirdek veri seti: 100 görüntü, 29.756 çekirdek, 22.444 etiketli, 4 sınıf.
- ISIC 2018: ~10 bin görüntü, 7 sınıf; 2019: 25.331 görüntü, 9 sınıf; 2020: 33.126 eğitim, tanıların çoğu bilinmiyor.
- Herlev: 917 görüntü, 7 sınıf, N/C oranı ana ölçüt; bölütleme 3 sınıflı (arka plan, sitoplazma, çekirdek).
- Yuvarlaklık: $4\pi A/P^2$; alan ve en-boy oranıyla birlikte artefakt ayıklamada kullanılır.
- Bölge tabanlı elips uydurma: alan kısıtı + yuvarlaklık kısıtı + bölge bölme.
- Dice $=2|A\cap B|/(|A|+|B|)$; IoU $=|A\cap B|/|A\cup B|$.
- Yarışmalarda doğrulama verisi çoğu zaman etiketsizdir; kendi test kümeni etiketli eğitim verisinden ayır.
- Transfer öğrenme: önceden eğitilmiş ağ + son katmanların yeniden eğitimi + sınıf sayısına uyarlama.

## Detaylı Açıklamalar

- Bu ders, dönemin proje aşamasının başlangıcıdır. Öğrenciler önceki haftalarda seçtikleri konuların veri setlerini ve kısa literatür taramalarını sundu; hoca her sunumu teknik açıdan yönlendirdi. Ortak sorular hep aynıydı: veri setinde ne var, yer gerçekliği hangi düzeyde verilmiş (nokta, maske, yalnız sınıf etiketi), problem tespit mi, bölütleme mi, sınıflandırma mı?
- Kolorektal kanser histolojisi örneğinde çekirdeklerin merkezleri nokta olarak işaretlenmiştir. Bu bilgiyle iki çalışma yapılabilir: merkezleri bulan bir tespit sistemi ya da işaretli merkezin çevresinden hücreyi kaplayan bir yama kesip hücre tipini (epitel, fibroblast, enflamatuvar, diğer) sınıflandıran bir sistem. Makalede tespit başarımı, işaretli merkezin 6 piksel yarıçapındaki bölge yer gerçekliği kabul edilerek kesinlik, duyarlılık ve F1 ile ölçülmüş; sınıflandırma $27\times27$ yamalarla yapılmıştır (ekrandan, 00:10:00 ve 00:15:00). Hoca bu alanda seyrek öğrenme, sözlük öğrenme ve metrik öğrenmenin az kullanıldığını, değişken yama boyutlarıyla bunların uyarlanabileceğini söyledi.
- Hocanın çalışma grubunun aynı veri setiyle yaptığı bir çalışmada CNN'in evrişim katmanından alınan öznitelikler PCA ile azaltılmış, birden çok sınıflandırıcının (DVM, rastgele orman, bagging, stokastik boosting, YSA) kararları birleştirilmiştir (ekrandan, 00:40:00). Hoca, bu yapıdaki klasik sınıflandırıcıların yerine birkaç farklı transfer öğrenme modelinin topluluğunun da kurulabileceğini belirtti.
- Herlev veri setinde her hücrenin sitoplazma ve çekirdek maskesi verildiği için hem sınıflandırma hem bölütleme çalışılabilir. Bölütleme ağına (U-Net, SegNet) her piksel için 0 (arka plan), 1 (sitoplazma), 2 (çekirdek) etiketli maske verilir. Eğitimde K-katlı çapraz doğrulama kullanılabilir: örneğin 100 örneğin 80'i eğitim, 20'si test için ayrılır ve test parçası her katta değişir. Sınıflandırmada N/C oranı ana ölçüttür; tabloya göre oran sınıflar boyunca genelde artar, ama 3. sınıf (0,35) ile 4. sınıf (0,27) arasında sıra bozulmaktadır (ekrandan, 00:55:00).
- Sıvı bazlı sitoloji görüntülerinde boya kalıntıları ve üst üste binmiş hücreler zorluk çıkarır. Hoca gölgelerin histogram eşitleme ile azaltılabileceğini, çekirdek merkezleri bulunduktan sonra bağlantılı bileşen analizinin verdiği en-boy oranı gibi ölçülerle oval olmayan koyu yapıların atılabileceğini söyledi. İki çekirdekli görünen yapılar, lamel üzerinde üst üste binmiş iki hücre de olabilir.
- Kan hücresi bölütlemesinde gösterilen bölge tabanlı elips uydurma yöntemi önce benzer alana sahip kan hücrelerini alan eşiğiyle ayırır, sonra $4\pi A/P^2$ yuvarlaklık ölçüsüyle yuvarlak olmayan gürültü ve artefaktları eler, son olarak birden çok hücre içeren bölgeleri böler (ekrandan, 01:35:00). MATLAB'deki `regionprops` her nesnenin alanını ve ağırlık merkezini verir (ekrandan, 01:45:00). Hoca alternatif olarak watershed tabanlı yöntemleri ve derin öğrenme tabanlı bölütlemeyi önerdi; problemi dört akyuvar tipinin sınıflandırılmasına genişletmeyi istedi.
- BraTS örneğinde tartışma yer gerçekliği kavramı üzerine yoğunlaştı. Doğrulama verisinin maskesi yoksa bu veriyle başarım ölçülemez; ya etiketli eğitim verisinin bir kısmı test için ayrılır ya da test etiketleri verilmiş başka bir yılın verisi kullanılır. Bölütleme başarımı Dice ve IoU ile ölçülür (ekrandan, 01:55:00). Düşük dereceli gliom makalesinde U-Net ile ortalama Dice yaklaşık %82'dir; düşük, orta ve yüksek uyum örneklerinin Dice değerleri %50, %82 ve %95 olarak verilmiştir (ekrandan, 02:15:00).

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
