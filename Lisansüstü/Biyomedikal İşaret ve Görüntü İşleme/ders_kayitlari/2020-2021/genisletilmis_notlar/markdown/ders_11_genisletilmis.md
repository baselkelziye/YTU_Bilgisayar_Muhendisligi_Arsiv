# Ders 11 Genişletilmiş Notu: Proje İlerleme Sunumları: Tıbbi Görüntü Bölütleme ve Sınıflandırma Projelerine Yöntem Önerileri

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dersin Yapısı
- 2. Etiketsiz Veriyle Anlamsal Bölütleme: Kan Yayması Görüntüleri
- 3. Transfer Öğrenme ve Topluluk Öğrenme: Deri Lezyonu Sınıflandırma
- 4. Kolorektal Kanser Derecelendirme: Dengeli Veri ve Veri Artırma
- 5. Beyin Tümörü Bölütleme: BraTS ve Karşılaştırma Metrikleri
- 6. LGG Veri Seti ve Temel Model
- 7. Servikal Sitoloji: Herlev, Cervix93 ve Yama Tabanlı Sınıflandırma
- 8. Büyük Veri Setleriyle Çalışma: PanNuke ve Kaggle
- 9. Araştırmadan Yayına Çalışma Yöntemi
- Örnek Sorular

## 1. Dersin Yapısı

Bu derste yeni bir konu anlatılmadı. Öğrenciler dönem projelerinde geçen haftadan bu yana yaptıklarını ekran paylaşarak gösterdi; hoca her sunumdan sonra veri setinin kullanımı, yöntem seçimi, karşılaştırma ve değerlendirme üzerine öneriler verdi. Projelerin hepsi tıbbi görüntü analiziyle ilgilidir: kan yayması görüntülerinde hücre bölütleme ve sınıflandırma, deri lezyonu sınıflandırma, kolorektal kanser dokusunda derecelendirme, beyin MR görüntüsünde tümör bölütleme, servikal sitoloji görüntülerinde çekirdek bölütleme ve sınıflandırma, çekirdek (nucleus) veri setleriyle transfer öğrenme. Bu not, sunumlardaki akademik içeriği ve hocanın yöntem önerilerini sunum sırasıyla aktarır. Sunum yapanlar "bir öğrenci" diye anılır.

## 2. Etiketsiz Veriyle Anlamsal Bölütleme: Kan Yayması Görüntüleri

### 2.1 Problem

Bir öğrencinin projesi, kan yayması görüntülerindeki beyaz kan hücrelerini (ör. eozinofil, nötrofil, monosit) sınıflandırmaktır. Hoca amacı şöyle özetledi: görüntülerde dört sınıf hücre var; önce bölütleme ile hücreler ayrılacak, sonra bunların birbirinden ayrılıp ayrılamadığına bakılacak. Öğrenci de bu yüzden iki eğitim kümesine ihtiyaç olduğunu söyledi: biri bölütleme için, diğeri sınıflandırma için.

Geçen hafta öğrenci, görüntülere histogram tabanlı bir ön işlem uygulamış ve bölge tabanlı (region-based) bir bölütleme yapmıştı. Bu hafta derin öğrenmeyle anlamsal bölütlemeye (semantic segmentation) geçmek istiyordu. Ön işlem olarak RGB görüntüye medyan süzgeç de eklemişti.

### 2.2 Anlamsal bölütleme için eğitim kümesi

Slayta göre (ekrandan, 00:10:00) derin öğrenmeyle anlamsal bölütleme için bir **görüntü ve etiket eğitim kümesi** gerekir: her görüntünün yanında aynı boyutta, her pikselin sınıfını gösteren bir etiket görüntüsü bulunur. Slaytta 500 görüntü ve 500 etiketle ResNet18, ResNet50 gibi hazır ağlar kullanılarak eğitim yapılacağı gösterildi. Öğrencinin vurguladığı gibi bu yöntem etiket olmadan çalışmaz.

Öğrencinin seçtiği veri setinde hazır bir etiket ya da açıklama (annotation) dosyası yoktu. Elle tek tek etiketlemek çok yorucu olacağı için şu yolu izlemişti (ekrandan, 00:10:00):

- Görüntüye bölge tabanlı bölütleme uygulanır; ikili (siyah-beyaz) bir hücre maskesi elde edilir.
- Histogram üç kutuya ayrılır (ekrandaki MATLAB satırı: `hh1 =histogram(x4,3);% 3: three labels`). Kutular üç etikete karşılık gelir: beyaz kan hücresi, kırmızı kan hücresi ve arka plan.
- Sonuç üç renkli bir etiket görüntüsüdür (slaytta arka plan, kırmızı hücreler ve beyaz hücre farklı renkte). Histogramın karıştırdığı yerler elle düzeltilir.

Öğrenci bu yolla bir eğitim kümesi hazırladığını, ama bazı yerlerde fazla hatalı (ör. olmaması gereken yerde beyaz hücre) etiket çıktığını söyledi.

### 2.3 Hocanın önerileri

Hoca yöntemin mantıklı olduğunu, ama bölge tabanlı yöntemin ne kadar kaliteli sonuç vereceğinin soru işareti olduğunu söyledi ve iki yol önerdi.

**Birinci yol, etiketli başka bir veri setinden öğrenmek.** Hoca derste MoNuSeg veri setini açtırdı. Eğitim verisi zip dosyasında "Annotations" ve "Tissue Images" klasörleri vardır (ekrandan, 00:15:00); açıklamalar XML dosyası olarak verilmiştir. Bu veriyle önce hücreleri arka plandan ayıran bir ağ eğitilir, sonra öğrencinin kendi görüntülerinde hücre ve arka plan ayrımı bu ağa yaptırılır. Hoca bunu "farklı bir veri setinden öğrenip bir nevi transfer öğrenme yapmak" diye tanımladı. Bölütleme ağı olarak U-Net ve SegNet gibi yapıların eğitilmesini ya da hazır eğitilmiş modellerin aranmasını önerdi. MoNuSeg sayfasında başka derin öğrenme veri setlerine de bağlantı vardır; bunların bazılarında bütün hücreler işaretli değildir. Hoca bu durumda yalnız işaretli bölgeleri kesip kullanmanın mantıklı olabileceğini söyledi.

**İkinci yol, eğiticisiz (unsupervised) bölütleme.** Etiket ya da yer gerçekliği (ground truth) bilgisine hiç ihtiyaç duymadan görüntü kendi kategorilerine ayrılır. Hocanın saydığı yöntemler:

- K-means kümeleme,
- Gauss karışım modelleri (Gaussian mixture models),
- bulanık c-ortalamalar (fuzzy c-means), <!-- BELİRSİZ: altyazıda "Fazit Sikip" diye bozulmuş; bağlamdan fuzzy c-means olduğu düşünüldü. -->
- etikete ihtiyaç duymayan eğiticisiz derin öğrenme ağları.

Öğrenci sonuçları ileride bu yöntemlerle karşılaştırabileceğini söyledi.

> **Hocanın vurgusu:** Öncelikle hücrelerin iyice seçilmiş (bölütlenmiş) olması lazım, sınıflandırmaya ancak ondan sonra geçilebilir.

Öğrenci sınıflandırma aşamasında transfer öğrenme kullanmayı ve bunu başka bir yöntemle karşılaştırmayı planlıyordu.

## 3. Transfer Öğrenme ve Topluluk Öğrenme: Deri Lezyonu Sınıflandırma

### 3.1 ISIC veri setleri

Bir öğrenci ISIC deri lezyonu yarışma veri setleriyle çalışıyordu. Öğrencinin aktardığına göre yılların veri setleri farklıdır:

- 2018 setinde yaklaşık 10 bin görüntü vardır.
- 2019 setinde yaklaşık 25 bin görüntü vardır ve sınıf etiketleri mevcuttur.
- 2020 setinde yaklaşık 33 bin görüntü vardır, ama 7 sınıf ayrıntılı etiketlenmemiştir; çoğunlukla yalnız iyi huylu ve kötü huylu ayrımı vardır.

Bu nedenle projede 2019 setinin kullanılması kararlaştırılmıştı. Öğrenci güncel yayınlarda 2018 ve 2019 setlerinin hâlâ kullanıldığını da gözlemlemişti.

### 3.2 InceptionV3 ile transfer öğrenme

Öğrenci, veri setini tanımak ve transfer öğrenmeyi denemek için 2018 setinde InceptionV3 modeliyle transfer öğrenme yapmış, yaklaşık %85 doğrulama doğruluğu elde etmişti. Her sınıf için precision, recall, F1 skoru ve support değerlerini de hesaplamıştı. Ekrandaki "InceptionV3 -- Training and validation loss" grafiğinde (ekrandan, 00:25:00) 9 epok vardır: eğitim kaybı 1. epokta yaklaşık 3,0'dan 2. epokta yaklaşık 1,2'ye düşüyor ve 9. epokta 0,8 civarına iniyor; doğrulama kaybı yaklaşık 1,35'ten başlayıp 0,55-0,7 arasında dalgalanıyor.

### 3.3 Topluluk öğrenme önerisi

Hoca transfer öğrenmeden sonra topluluk (ensemble) öğrenmenin denenmesini istedi. Öğrenci yarışmalarda daha iyi sonuç için genellikle topluluk yöntemlerinin kullanıldığını gözlemlemişti. Hoca derste "deep learning ensemble" araması yaptı ve öne çıkan başlıkları okudu: derin öğrenme için yatay oylama topluluğu (horizontal voting ensemble), model ortalaması topluluğu (model averaging ensemble) gibi yöntemler. Sonra "Ensemble Methods for Deep Learning Neural Networks" başlıklı bir öğretici yazıyı açtırdı. Yazının sonunda yöntemler şu eksenlerde sınıflandırılmıştır:

- **Eğitim verisini çeşitlendirme (varying training data):** her model farklı bir veri alt kümesiyle eğitilir; örneğin bootstrap ile yeniden örnekleme.
- **Modeli çeşitlendirme (varying models):** farklı mimariler ya da aynı mimarinin farklı başlangıçlarla eğitilmiş kopyaları kullanılır.
- Bunların birleşimi.

Öğrenci de veride mi, modelde mi, yoksa ikisinin karışımında mı çeşitlendirme yapılacağı sorusunu daha önce sorduğunu hatırlattı.

> **Ek bilgi (derste anlatılmadı):** Bootstrap, eğitim kümesinden yerine koyarak rastgele örnekleme ile aynı büyüklükte yeni kümeler üretmektir; her modele farklı bir küme verilir ve kararlar birleştirilir (bagging). Yatay oylama, aynı eğitimin son birkaç epoğunda kaydedilen modellerin kararlarının birleştirilmesidir. Model ortalaması ise birden çok modelin tahmin olasılıklarının ortalamasını almaktır.

Hoca, bu öğreticideki yöntemlerle iyi bir giriş (introduction) yazılabileceğini, ardından ör. bootstrap tabanlı iki yöntemin karşılaştırmalı uygulanabileceğini söyledi. Yöntem bu alana ilk kez uyarlanacağı için çalışma bildiri düzeyinin üstüne çıkıp ulusal ya da uluslararası bir dergiye gönderilebilir. Ayrıca bizim alanda olmasa bile başka alanlarda yapılmış yeni "derin öğrenme + topluluk öğrenme" çalışmalarına da bakılmasını istedi.

## 4. Kolorektal Kanser Derecelendirme: Dengeli Veri ve Veri Artırma

### 4.1 Veri seti

Bir öğrenci kolorektal kanser (CRC) derecelendirme projesinde MATLAB'da transfer öğrenme ile önceden eğitilmiş ResNet-50 modelini kullanıyordu. Hoca önce makaleyi ve veri setini tanıtmasını istedi. Veri setinin README dosyasına göre (ekrandan, 00:35:00):

- Bu veri seti, aynı grubun önceki CRC veri setinin genişletilmiş hâlidir.
- Görüntüler 4548×7548 ve 5000×7300 piksel boyutunda, 20× büyütmede çıkarılmış, örtüşmeyen görüntülerdir.
- Her görüntü uzman patologlarca normal doku (Grade1), düşük dereceli tümör (Grade2) ya da yüksek dereceli tümör (Grade3) olarak etiketlenmiştir.
- Görüntüler H&E ile boyanmış 137 doku lamının sayısallaştırılmış tüm lam görüntülerinden (WSI) elde edilmiştir; tarama 0,275 µm/piksel (40×) çözünürlüktedir.
- Toplam 300 görüntü vardır: 120 normal, 120 düşük dereceli, 60 yüksek dereceli kanser görüntüsü.
- Bazı görüntülerde birden çok sınıfa ait bez (glandüler) yapılar bulunabilir; yönteme göre bunların tek sınıf içerecek şekilde ön işlenmesi gerekebilir. Sınıf bilgisi dosya adlarındadır.

Klasörde dosyalar "Grade1_Patient_..." gibi adlarla durur (ekrandan, 00:30:00). Öğrenci arşivi açtığında bazı dosyaların bozuk olduğunu ve 300'den az görüntü elde ettiğini söyledi. <!-- BELİRSİZ: bozuk dosyalar çıkarıldıktan sonraki sınıf dağılımı altyazıda karışık okunuyor (171, 53, 88 gibi sayılar geçiyor); kesin dağılım çıkarılamadı. -->

Hoca, bir makale belli sayıda veri kullandığını söylüyorsa bu verinin bozuk olmayan hâlinin de yayımlanmış olması gerektiğini belirtti.

### 4.2 Dengeli ve dengesiz veri seti

Öğrencinin sunumunda dengeli (balanced) ve dengesiz (imbalanced) veri seti ayrımı geçti: her sınıfta aynı sayıda görüntü varsa veri seti dengelidir ve doğruluk (accuracy) hesabı için daha uygundur. Öğrenci bu yüzden en az örnekli sınıfın sayısına göre seçim yaptığını söyledi.

Hoca sınıflar arasındaki farkın büyük olmadığını söyledi: bir sınıfta 10, ötekinde 100 görüntü olsaydı dengesiz sayılırdı; buradaki fark kabul edilebilir.

### 4.3 Veri artırma ve yamalar

Hoca veri artırmayı (data augmentation) önerdi: görüntüler dört yöne ve köşegen boyunca döndürülerek veri sayısı yaklaşık beş katına çıkarılabilir.

Ekrandaki makalede (IEEE Transactions on Medical Imaging, 2020) normal, düşük ve yüksek dereceli dokular ızgara hâlinde küçük kutulara bölünmüştür; her kutu 20× büyütmede standart bir yama sınıflandırıcısının gördüğü 224×224 piksellik bağlamı gösterir. Yöntemin akış şemasında 1792×1792 girdi görüntüsü 224×224 yamalara bölünüyor, her yamadan öznitelik çıkarılıp bir öznitelik küpü oluşturuluyor, ardından dikkat bloğu ve bağlam blokları ile sınıflandırma yapılıyor (ekrandan, 00:40:00). Hoca öğrencinin de bu yolu izleyebileceğini söyledi: 300 görüntünün hepsinden küçük yamalar çıkarılacağı için görüntü sayısı az olsa da veri yeterli olur.

Öğrenci genişletilmiş CRC setini kullandığını söyleyince hoca, eski CRC veri setini de indirip genişletilmiş setle birleştirerek veri sayısını artırmasını önerdi.

## 5. Beyin Tümörü Bölütleme: BraTS ve Karşılaştırma Metrikleri

### 5.1 Verinin bölünmesi

Bir öğrenci BraTS 2020 veri setiyle beyin tümörü bölütleme yapıyordu. BraTS 2020'de bölütleme maskeleri yalnız eğitim setinde vardır, doğrulama setinde yoktur. Bu yüzden öğrenci doğrulama setini kullanmadan eğitim setindeki 369 örneği ayırdı. Slayta göre (ekrandan, 00:50:00) %66'sı eğitim (243), kalanı doğrulama (126) olarak ayrıldı.

$$369 \times 0{,}66 \approx 243{,}5 \;\Rightarrow\; 243 \text{ eğitim},\qquad 369 - 243 = 126 \text{ doğrulama}$$

> **Ders sonrası not:** Öğrenci sözlü olarak doğrulama için 125 örnek dedi; slayttaki ve hesaptaki değer 126'dır.

Genelleme için ayrıca TCIA'daki başka bir MR veri setinde (yine maskeli) test yapılması planlandı. Slaytta projenin amacı şöyle yazıyordu: katmanlara bölütleme uygulayarak 3 boyutlu bir tümör görüntüsü elde etmek, katmanlarda bulunan tümörün koordinatlarını sunmak, bu bilgileri metin olarak raporlamak; bölütleme ile yer gerçekliği arasındaki başarım IoU/Dice ile ölçülecekti. FCN'nin çıkış kısmında uzamsal bilgiyi koruması bu iş için yararlı görülmüştü.

### 5.2 Papers with Code

Hoca karşılaştırma için Papers with Code sitesini tanıttı. "Brain Tumor Segmentation" araması yapıldığında veri setlerine (ör. BraTS 2018) göre denenmiş yöntemler, makaleler, sonuçlar ve çoğu zaman kodlar bir arada listelenir. Hoca bunun hem bu öğrenciye hem aynı konuda çalışan öteki gruba yarayacağını, kodların karşılaştırma için kullanılabileceğini söyledi.

### 5.3 Renk haritası ve nicemleme

Öğrenci Python'da kesitlere doğrudan renk haritaları (colormap) uygulayınca tümörlü bölgelerin hızla ayırt edilebildiğini fark etmişti (ekranda `cmap="jet"` ile gösterilen kesitler, ekrandan, 00:50:00 ve 00:55:00). Hoca önce renk uzayının mı değiştirildiğini sordu; öğrenci yalnız renk haritasını değiştirdiğini söyledi.

Hoca bu etkiyi nicemleme (quantization) ile açıkladı: renk haritası renk geçişlerini tam yapamaz, değerleri bir üst ya da bir alt seviyeye atar; bu da görüntüye bölütleme yapılmış gibi bir görünüm verir. Öneri: ağa bir kez bu hâliyle, bir kez özgün hâliyle vermek ve hangisinin metriklere göre daha iyi bölütleme sonucu verdiğine bakmak.

### 5.4 Türev tabanlı kenar fikri ve metrikler

Öğrenci özgün bir yöntem olarak, iki bölge arasındaki geçişlerdeki değişimi türev alarak bulmayı, önce tümörün kenarını çizip sonra bölütleme yapmayı ve yerelleştirme ile başka koyu bölgeleri ayıklamayı düşünüyordu. Hoca bunu olumlu karşıladı ama önce BraTS kullanan, MR bölütleme üzerine çalışan son makalelere bakılmasını istedi.

> **Hocanın vurgusu:** Kullanılan metriklere bakın. Karşılaştırma için hangi metrikleri kullanıyorlar, Dice mı, başka bir bölütleme doğruluğu mu? Biz de aynı metrikleri kullanalım.

Öğrenci makalelerde genellikle IoU (Intersection over Union) ve Dice kullanıldığını, Dice'ın F1 skoruyla aynı olduğunu belirtti; hoca onayladı.

> **Ek bilgi (derste anlatılmadı):** Tahmin maskesi $A$ ve yer gerçekliği maskesi $B$ için $\text{IoU} = \frac{|A\cap B|}{|A\cup B|}$ ve $\text{Dice} = \frac{2|A\cap B|}{|A|+|B|}$ olarak tanımlanır. İkili piksel sınıflandırmasında Dice, F1 skoruna eşittir. İkisi arasında $\text{Dice} = \frac{2\,\text{IoU}}{1+\text{IoU}}$ bağıntısı vardır.

Öğrenci ileri aşama olarak, bölütlemeden sonra "şu bölgede şu kadar milimetreküp tümör var" diyen bir rapor üretmeyi önerdi. Hoca bu raporun bölütlenen bölgenin piksel sayısından ve bir piksele düşen fiziksel alandan çıkarılabileceğini, ama önce bölütlemenin yapılması gerektiğini söyledi.

### 5.5 Bölütleme taramasından model seçimi

Hoca daha önce gösterdiği derin öğrenme ile görüntü bölütleme taramasını (survey) açtırdı. Öğrenci taramada tam evrişimli ağın (FCN) çok kullanıldığını, ResNet ve InceptionV3 ile de çalışmalar yapıldığını, kendi yöntemini büyük olasılıkla ResNet sonuçlarıyla karşılaştıracağını söyledi. Hocanın taramadan saydığı model aileleri:

- Mask R-CNN,
- DeepLab ailesi (DeepLabv3; öğrenciye göre bir de v3+ sürümü var),
- piramit yapıları (çok seviyeli piramit ağları),
- dikkat (attention) ağları,
- yinelemeli (recurrent) sinir ağı modelleri,
- üretici modeller ve çekişmeli eğitim (generative models, adversarial training).

Ekrandaki tarama sayfasında DeepLab ailesinin temeli olan genişletilmiş (dilated, "atrous") evrişim anlatılıyordu (ekrandan, 00:55:00): bir $x(i)$ işaretinin genişletilmiş evrişimi $y_i = \sum_{k=1}^{K} x[i + rk]\, w[k]$ biçimindedir; $r$ genişletme oranıdır ve çekirdek ağırlıkları arasındaki aralığı belirler. Sayfadaki örneğe göre genişletme oranı 2 olan 3×3 bir çekirdek, yalnız 9 parametre kullanarak 5×5 bir çekirdekle aynı alıcı alana (receptive field) sahip olur; böylece hesap maliyeti artmadan alıcı alan büyür.

Hoca bu modellerin iki öğrenci arasında paylaştırılmasını önerdi: biri DeepLab ailesine (piramit yapısı içeren), öteki dikkat tabanlı ve çekişmeli eğitim yöntemlerine yoğunlaşabilir. Hoca, başka bir çalışmada yapılan bir yöntemin (ör. GAN) buraya uyarlanmasının sorun olmadığını, önemli olanın iyi sonuç almak olduğunu söyledi. Hızlı ön denemelerle hangi modellere yoğunlaşılacağına karar verilmelidir. Karşılaştırma için tam bağlantılı (fully connected) katmanlı basit bir yapı da temel sınıflandırıcı (base classifier) olarak kullanılabilir.

### 5.6 Kesit mi, hacim mi?

Öğrenci aynı hastanın 95, 96 ve 97 numaralı kesitlerini gösterdi; aşağı doğru gidildikçe derinlik değiştiği için tümör kaybolur ya da beyin alanı daralır. Hoca şu soruyu sordu: makaleler karşılaştırmayı nasıl yapıyor, her kesiti ayrı bir görüntü gibi mi kabul ediyor, yalnız belli kesitleri mi alıyor, yoksa hasta bazında hacimsel (volumetric) bir değerlendirme mi yapıyor? Öğrenci bunu henüz incelemediğini, büyük olasılıkla en büyük tümör bölgesini içeren kesitlerin alındığını söyledi.

> **Hocanın vurgusu:** Oradaki yaklaşım çok önemli. Bu veri setinden yararlanan makalelerde neyin neyle karşılaştırıldığına ve verinin nasıl ele alındığına önce yoğunlaşmak lazım.

## 6. LGG Veri Seti ve Temel Model

Bir öğrencinin veri seti LGG beyin MR bölütleme veri setiydi: düşük dereceli glioma (lower-grade glioma) denen beyin tümörünün bölütlenmesi. Ekrandaki slayta göre (ekrandan, 00:45:00) veri setinde 110 hastanın MR görüntüsü klasör olarak sunulmuştur; her klasörde 40-70 arası MR-maske kesit çifti vardır, yani 3 boyutlu MR görüntüsü derinlik boyunca tek tek 2 boyutlu kesit-maske çiftlerine ayrılmıştır. Görüntüler The Cancer Imaging Archive (TCIA) kaynaklı FLAIR görüntüleridir. Maskeler yer gerçekliği olarak kullanılır.

Veri setinin kaynak makalesi (Computers in Biology and Medicine; ekrandan, 01:30:00) düşük dereceli gliomaların genomik alt tiplerini, derin öğrenmeyle otomatik çıkarılan şekil öznitelikleriyle ilişkilendirir. Özetinde 5 kurumdan 110 hastanın verisinin kullanıldığı ve otomatik tümör bölütlemede ortalama %82 Dice katsayısına ulaşıldığı, bunun insan başarımıyla karşılaştırılabilir olduğu yazıyordu. Makalede bölütleme için U-Net kullanılmıştı.

Öğrenci taramayı okuduktan sonra hangi bölütleme modelini seçeceğinde kararsızdı. Hoca şu yolu önerdi:

1. Önce makaledeki U-Net'i veri artırma uygulayarak bu veriye uyarlamak; böylece karşılaştırılabilecek temel (baseline) yapı kurulmuş olur.
2. Sonra başka yöntemlerle bu başarının geçilip geçilemediğini araştırmak.

> **Hocanın vurgusu:** Amacımız U-Net kullanmak değil, U-Net'i karşılaştırma amacıyla kullanmak. Önce U-Net'i dene, sonra diğer algoritmalara hızlı bir şekilde geç.

## 7. Servikal Sitoloji: Herlev, Cervix93 ve Yama Tabanlı Sınıflandırma

### 7.1 Veri setleri

Bir öğrenci Herlev ve Cervix93 veri setlerinde bölütleme ve sınıflandırma yapacaktı. Herlev veri setinde 917 görüntü vardır ve öğrenci bu veri üzerinde U-Net ile bölütlemeye başlamıştı.

Cervix93 veri setinde 93 yığın (stack) vardır. Öğrencinin aktardığına göre her yığında lamın farklı kesitlerinden (odak düzlemlerinden) taranmış 10-20 görüntü bulunur. Bunlar birleştirilerek her yığın için tek bir görüntü elde edilmiştir; dosya yapısında bu görüntüler "EDF" klasöründedir (ekrandan, 01:20:00) ve her PNG görüntünün yanında aynı adlı bir CSV dosyası vardır. CSV dosyalarında görüntüdeki çekirdeklerin merkez noktaları verilmiştir; gösterilen örnekte 28 çekirdek vardı. Sınıflandırma için ayrıca hangi görüntünün hangi sınıfa ait olduğu ve eğitim mi test mi kümesinde olduğu bir etiket dosyasında verilmiştir: 0 olanlar eğitim, 1 olanlar test için ayrılmıştır. Üç sınıf vardır. EDF görüntülerinin boyutu 1280×960'tır.

> **Ek bilgi (derste anlatılmadı):** EDF (extended depth of field, genişletilmiş alan derinliği), farklı odak düzlemlerinde çekilmiş mikroskop görüntülerinden her bölgenin en net olduğu düzlemin seçilerek birleştirilmesiyle elde edilen ve her yeri odakta görünen tek görüntüdür.

### 7.2 Hocanın yama tabanlı önerisi

Öğrenci, bölütleme için EDF görüntülerini mi yoksa taranmış tek tek kesitleri mi kullanması gerektiğinde kararsızdı. Hoca, tam boyutlu görüntülerle doğrudan eğitip test etmenin yorucu olacağını söyledi ve tahtada şu yöntemi çizdi (ekrandan, 01:35:00):

1. Bir EDF görüntüsünde çekirdek merkezleri bilinir. İstenirse önce bu merkezler görüntü üzerine işaretlenir.
2. Her çekirdek merkezinin çevresinden sabit boyutlu bir yama alınır: 512×512, 256×256 ya da 128×128.
3. Görüntünün sınıfı bilindiği için ondan alınan bütün yamalar o sınıfa atanır. Tahtadaki örnekte 1 numaralı sınıfa ait bir görüntüde 7 çekirdek vardır; her birinin çevresinden 512×512 yama alınınca bu görüntüden 1. sınıfa ait 7 yama elde edilir.
4. Aynı işlem 2. ve 3. sınıfın görüntüleri için tekrarlanır. Böylece her çekirdek merkezi için bir yama olmak üzere sınıflandırılabilecek bir yama veri seti oluşur.
5. Veri artırma uygulanır: yama döndürülerek özgün hâliyle birlikte dört şekil elde edilir, köşegen çevirmeler de eklenince veri sayısı daha da artar.
6. Önce herhangi bir ön eğitim kullanılmadan CNN ile eğitip sonuca bakılır; ardından transfer öğrenme ile ResNet, DenseNet, Inception gibi standart yapılar denenir.

### 7.3 İleri aşama: çok kesitli girdi

Hoca ikinci, sonraya bırakılacak bir fikir de verdi. EDF görüntüsü gri seviyeli ise tek katmanlı, renkli ise 3 katmanlı (RGB) bir görüntüdür; 512×512 yama da 512×512×3 olur. Oysa her yığın için EDF'i oluşturan kesitler de verilmiştir. Kesit sayısı yığından yığına 10-20 arasında değiştiği için en küçük ortak sayı (ör. 10) seçilir ve her yamanın o kadar kesiti üst üste konur. Böylece sınıflandırma için $M \times N \times 10$ boyutlu çok kanallı bir girdi elde edilir.

## 8. Büyük Veri Setleriyle Çalışma: PanNuke ve Kaggle

### 8.1 PanNuke veri seti

Son sunumu yapan öğrenci PanNuke veri setine transfer öğrenme uygulayacaktı. Öğrencinin aktardığına göre veri seti 481 görsel alandan (visual field) oluşturulmuştur, yaklaşık 200 bin etiketli çekirdek içerir, 5 çekirdek tipi ve 19 doku tipi vardır. Veri setinin oluşturulmasında aktif öğrenme (active learning) kullanılmıştır. Veri numpy dizileri hâlinde paylaşılmıştır; ekrandaki Colab defterinde `types.npy` dosyasındaki doku tiplerinin 'Breast', ..., 'Colon' gibi değerler içerdiği görülüyordu (ekrandan, 01:40:00). <!-- BELİRSİZ: altyazıda "görsel alan içeren 20.000 yüksek çözünürlüklü görüntüden" ifadesi geçiyor; bu sayının neye karşılık geldiği net değil. -->

Sorun, veri setinin her biri 11-12 GB civarında 3 parça (fold) hâlinde olmasıydı. Öğrenci Google Colab'e ve Google Drive'a yüklemede zorlandı. Büyük veri setleriyle çalışma üzerine bulduğu öneriler, verinin normalize edilip parçalar hâlinde HDF5 (H5) dosyası olarak saklanması ve verinin Kaggle'a koyulup oradan kullanılmasıydı.

> **Ek bilgi (derste anlatılmadı):** HDF5, büyük sayısal dizileri parçalar (chunk) hâlinde saklayan bir dosya biçimidir; veri belleğe bütünüyle yüklenmeden yalnız gereken dilimler diskten okunabilir. Bu nedenle bellekten büyük veri setlerinde eğitim sırasında parça parça veri okumak için uygundur.

### 8.2 Kaggle ortamı

Hoca Kaggle'ın da GPU imkânı sunduğunu, bir öğrencinin aktardığına göre Tesla P100 kullandırdığını ve Google Colab'den daha iyi olabileceğini söyledi; özellikle Python kullananların denemesini önerdi. Kaggle'da önce hesap açılır; veri setleri Kaggle'ın kendi depolama alanında tutulabilir, böylece veriyi her seferinde yükleme sorunu ortadan kalkar. Öğrenci hem Kaggle'a yüklenmiş veri setlerinin kullanılabildiğini hem de kullanıcının kendi verisini yükleyebildiğini gördüğünü söyledi.

## 9. Araştırmadan Yayına Çalışma Yöntemi

Ders boyunca hoca projelerin yayına dönüşmesi için bir çalışma yolu önerdi. Son sunumdan sonra bunu şöyle özetledi:

1. Makalede kullanılan yöntemi incelemek; kodları varsa kodlara bakmak ve yöntemi uygulamak.
2. Yenilik (novelty) için hangi değişiklikleri ve yeni model önerilerini yapabileceğini düşünmek, bunları denemek.
3. Makalenin kullandığı metrikleri kullanarak onun sonucunu geçmeye çalışmak.
4. Aynı veri setini kullanan yeni yayınlara ve taramalara bakmak: ne kullanmışlar, veri setini nasıl tanıtmışlar.
5. İyi referansları şimdiden kaydetmek; böylece çalışma daha rahat makaleye dönüştürülür.

Hoca, Papers with Code sitesindeki kıyaslama sonuçlarının (benchmark), kodların ve makale uygulamalarının herkesin kendi verisine benzer yöntemleri bulmasında yararlı olacağını yeniden hatırlattı. Çalışmanın konusuna ve yeniliğine göre ulusal ya da uluslararası dergi hedeflenebileceğini söyledi.

## Örnek Sorular

**Soru 1** (derste sözlü, 00:13:36): Elimizdeki görüntülerde piksel etiketi yoksa derin öğrenmeyle hücre bölütleme nasıl yapılabilir?

> **Cevap (derste verildi):** İki yol vardır. Birincisi, etiketli başka bir veri setiyle (ör. MoNuSeg) hücre ile arka planı ayıran bir ağ (U-Net, SegNet gibi) eğitip kendi görüntülerine uygulamaktır; bu bir tür transfer öğrenmedir. İkincisi, etiket gerektirmeyen eğiticisiz yöntemlerdir: K-means, Gauss karışım modelleri, fuzzy c-means ya da eğiticisiz derin öğrenme ağları.

**Soru 2** (derste sözlü, 00:38:33): Bir veri setinde sınıflar 120, 120 ve 60 görüntüden oluşuyor. Bu veri seti dengesiz sayılır mı, veri sayısı nasıl artırılabilir?

> **Cevap (derste verildi):** Hocaya göre fark büyük değildir; 10'a 100 gibi bir fark olsaydı dengesiz sayılırdı. Görüntüler dört yöne ve köşegen boyunca döndürülerek veri yaklaşık beş katına çıkarılabilir; ayrıca büyük görüntülerden küçük yamalar çıkarmak ve aynı grubun eski veri setini eklemek örnek sayısını artırır.

**Soru 3** (derste sözlü, 00:55:33): MR kesitlerine farklı bir renk haritası uygulanınca tümör bölgesi neden bölütlenmiş gibi görünür?

> **Cevap (derste verildi):** Renk haritası renk geçişlerini sürekli yapamaz, değerleri bir üst ya da bir alt seviyeye atar (nicemleme). Bu basamaklı görünüm bölütleme gibi algılanır. Yararlı olup olmadığı, ağa bu hâliyle ve özgün hâliyle verilip metriklerle karşılaştırılarak anlaşılır.

**Soru 4** (derste sözlü, 00:56:26): Bir MR veri setinde her hastanın çok sayıda kesiti varsa makalelerdeki yöntemler nasıl karşılaştırılmalıdır?

> **Cevap (derste verildi):** Önce makalelerin veriyi nasıl ele aldığına bakılmalıdır: her kesit ayrı bir görüntü mü sayılıyor, yalnız belli kesitler (ör. tümörün en büyük olduğu) mi alınıyor, yoksa hasta bazında hacimsel bir değerlendirme mi yapılıyor. Karşılaştırma aynı veri kullanımı ve aynı metriklerle (Dice, IoU) yapılmalıdır.

**Soru 5** (ekrandan, 01:35:00): Üç sınıflı bir sitoloji veri setinde 1280×960 boyutlu görüntüler ve her görüntüdeki çekirdek merkezleri verilmiştir. Sınıflandırma için eğitim verisi nasıl oluşturulur? Tahtadaki örnekte 1. sınıftan bir görüntüde 7 çekirdek varsa bu görüntüden kaç yama elde edilir?

> **Cevap (derste verildi):** Her çekirdek merkezinin çevresinden 512×512 (ya da 256×256, 128×128) yama alınır ve yama, görüntünün sınıfını etiket olarak alır. Örnekteki görüntüden 1. sınıfa ait 7 adet 512×512 yama çıkar. Aynı işlem 2. ve 3. sınıf için yapılır, döndürme ile veri artırılır; önce ön eğitimsiz CNN, sonra transfer öğrenme (ResNet, DenseNet, Inception) denenir.

**Soru 6** (derste sözlü, 01:36:26): Her görüntü 10-20 arası odak kesitinden oluşan bir yığından elde edilmişse, sınıflandırma girdisi tek EDF görüntüsü yerine nasıl zenginleştirilebilir?

> **Cevap (derste verildi):** Yığınlardaki en küçük ortak kesit sayısı (ör. 10) seçilir ve aynı yamanın bu kesitleri üst üste konarak $M\times N\times 10$ boyutlu çok kanallı bir girdi oluşturulur.

## Dersin Toparlaması

Bu ders, dönem projelerinin ilerleme sunumlarıyla geçti ve tıbbi görüntü analizinde sık karşılaşılan pratik sorunlara yöntem önerileri getirdi. Etiket olmadığında ya başka bir etiketli veri setinden öğrenip aktarmak ya da eğiticisiz bölütleme yöntemlerini kullanmak gerekir. Az veriyle çalışırken veri artırma, büyük görüntülerden yama çıkarma ve benzer veri setlerini birleştirme örnek sayısını artırır; çekirdek merkezleri biliniyorsa merkez çevresinden alınan yamalar doğrudan bir sınıflandırma veri seti oluşturur. Sınıflandırmada transfer öğrenmenin ardından topluluk öğrenme (veriyi, modeli ya da ikisini çeşitlendirme) denenebilir.

Bölütleme projelerinde temel ilke, makaledeki yöntemi (ör. U-Net) temel model olarak çalıştırıp aynı veri kullanımı ve aynı metriklerle (Dice, IoU) onu geçmeye çalışmaktır. Aday modeller derin öğrenme bölütleme taramasından (FCN, Mask R-CNN, DeepLab ailesi, piramit ve dikkat yapıları, çekişmeli eğitim) seçilir; Papers with Code gibi kaynaklar sonuçları ve kodları bir arada sunar. Büyük veri setleri için HDF5 biçimi ve Kaggle gibi GPU ortamları pratik çözümlerdir.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
