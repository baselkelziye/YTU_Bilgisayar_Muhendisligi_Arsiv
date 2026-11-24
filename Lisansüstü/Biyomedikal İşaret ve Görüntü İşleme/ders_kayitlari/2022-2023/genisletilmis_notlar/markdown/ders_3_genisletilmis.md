# Ders 3 Genişletilmiş Notu: Proje İlerleme Görüşmeleri: Transfer Öğrenme, Derin Ensemble ve GAN Tabanlı Segmentasyon

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dersin biçimi
- 2. Meme kanseri görüntülerinde derin ensemble öğrenme
- 3. Histopatolojide çekirdek segmentasyonu ve GAN tabanlı segmentasyon
- 4. Yarı gözetimli öğrenme için veri hazırlığı
- 5. Servikal sitoloji görüntülerinde sınıflandırma
- 6. Üç sınıflı görüntü sınıflandırmada transfer öğrenme ve ensemble
- 7. Örnek Sorular

## 1. Dersin biçimi

Bu ders kaydı bir konu anlatımı değil, proje ilerleme görüşmesidir. Öğrenciler sırayla ekranlarını paylaşıp bir hafta içinde ne okuduklarını, hangi veri setlerini ve kodları bulduklarını anlattı. Hoca da her projede bir sonraki adımı belirledi. Bütün projeler tıbbi görüntülerde sınıflandırma ya da segmentasyon üzerineydi.

Görüşmelerin hepsinde aynı yöntem çizgisi tekrar etti:

- Önce literatürde güncel çalışmaları ve kodları (özellikle "Papers with Code" sayfalarını) bulmak.
- Sonra standart transfer öğrenme modelleriyle bir karşılaştırma tabanı kurmak.
- Ardından daha yeni bir yaklaşımla (derin ensemble, GAN tabanlı yapılar, değiştirilmiş mimariler) bu tabanı geçmeye çalışmak ve ortaya yeni bir şey koymak.

> **Hocanın vurgusu:** Bir makale temel alınabilir, ama çalışma hızlanmalı ve sonunda bir yenilik ortaya konmalıdır.

## 2. Meme kanseri görüntülerinde derin ensemble öğrenme

### 2.1 Manifold öğrenmeden derin ensemble'a

Bir öğrenci meme kanseri görüntüleri üzerine çalışıyordu. <!-- BELİRSİZ: Altyazıda veri seti adı "Breaks Dataset" diye geçiyor; konuşmada ultrason görüntüleri gösteriliyor. Veri setinin adı karede doğrulanamadı. --> Bir önceki görüşmede manifold öğrenme üzerinden ilerlenmesi konuşulmuştu. Öğrenci, incelediği makalelerde ve kodlarda manifold öğrenmeyi kendi problemine uyarlamanın bir yolunu bulamadığını anlattı. Bu yüzden hocanın daha önce önerdiği derin ensemble öğrenmeye (deep ensemble learning) yöneldi. Bu konuda yakın tarihli bir derleme makalesi okudu ve meme kanseri veri setlerine uyarlanmış birkaç ensemble derin öğrenme modeline baktı.

İncelenen örneklerden biri ultrason görüntüleri, bir diğeri histopatolojik görüntüler üzerineydi. Histopatoloji çalışmasında CNN modelleri ensemble biçiminde birleştirilmişti. Makaledeki şekilde bazı modeller "Fully Trained" (sıfırdan eğitilmiş) olarak işaretlenmişti.

### 2.2 Hocanın önerisi: transfer öğrenme ve EWT/VMD

Hoca, makaledeki CNN modellerinin yerine önce transfer öğrenme modellerinin denenmesini istedi. Sayılan modeller şunlardır:

- DenseNet
- ResNet
- Inception
- Xception
- NASNet
- EfficientNet

Bu modeller birlikte (karma olarak) denenecek ve sonuçlarına bakılacak. Hoca ayrıca makalede geçen EWT ve VMD adımlarını sordu ve açılımlarını verdi: EWT, Empirical Wavelet Transform; VMD, Variational Mode Decomposition. Öğrencinin bu makaleyi kendine temel alması, aynı yapıyı kendi verisine uyarlaması ve özellikle EWT ile VMD'yi de yönteme koyması istendi. Önerilen sıra: önce transfer öğrenme modelleriyle başlangıç, sonra EWT/VMD uyarlaması.

> **Ek bilgi (derste anlatılmadı):** EWT, işaretin Fourier spektrumunu uyarlanabilir biçimde bantlara bölüp her banda bir dalgacık süzgeci kurarak işareti kiplerine (mode) ayırır. VMD ise işareti, her biri bir merkez frekans çevresinde dar bantlı olan sınırlı sayıda kipe, bir optimizasyon problemi çözerek ayırır. İkisi de iki boyutlu biçimleriyle görüntülere de uygulanabilir. Böylece derin modele ham görüntünün yanında farklı frekans bileşenleri de verilebilir.

## 3. Histopatolojide çekirdek segmentasyonu ve GAN tabanlı segmentasyon

### 3.1 Veri seti arayışı: maske şartı

İkinci proje histopatoloji görüntülerinde GAN tabanlı segmentasyon üzerineydi. Öğrenci önce akciğer ve kolon kanseri histopatoloji görüntülerinden oluşan bir sete baktı. Bu sette yalnız görüntüler vardı, maskeler yoktu. Segmentasyon modeli piksel düzeyinde maske ile eğitildiği için bu set bırakıldı.

Maskeli setler olarak şunlar konuşuldu:

- PanNuke: görüntüler ve maskeler NumPy (`.npy`) dosyaları olarak geliyor.
- MoNuSeg: hocanın önerdiği çekirdek segmentasyonu seti.
- TNBC çekirdek segmentasyon seti: öğrencinin incelediği bir makalenin bağlantısından bulduğu set.

Hoca, bez (gland) segmentasyonunun farklı bir konu olduğunu söyleyerek onu listeden çıkarttı.

### 3.2 İncelenen kodlar

Öğrencinin slaytlarında incelenen kodlar şöyle listelenmişti (ekrandan, 00:10:00):

- SGAN (Paper with code): bir akciğer veri seti üzerinde çalışan, var olan görüntülerden GAN ile yeni görüntü üreten bir kod. Öğrenci kodu çalıştırdı, ama bunun bir segmentasyon kodu değil yalnız GAN kodu olduğunu gördü. Bu kodla bir GAN'ın nasıl çalıştığını anlamaya çalıştı.
- Nu-GAN (Paper with code): "Unsupervised Learning for Cell-level Visual Representation in Histopathology Images with GAN" çalışmasının Python uygulaması. Bağımlılıkları PyTorch ve HistomicsTK. HistomicsTK paketi hata verdiği için kurulamadı; Anaconda üzerinden kurulum önerisi de sonuç vermedi.
- TSFD-Net: "Tissue specific feature distillation network for nuclei segmentation and classification". PanNuke setini kullanır, sınıflandırma ve segmentasyon yapar, ama GAN değildir.
- HoVer-Net (`hover_net-master`, Paper with code): çekirdek segmentasyonu kodu.
- U-Net.

### 3.3 Hocanın önerisi: önce U-Net ailesi, sonra GAN

Hoca kurulum sorununa takılmamayı, önce U-Net sürümlerinin denenmesini önerdi. Bir kod segmentasyon yapıyorsa o da denenebilir, ama ilk iş standart segmentasyondur. Haftaya kadar GAN kullanmadan standart bir segmentasyon sonucu alınacak, sonra GAN'lara geçilecek. Denenecek standart modeller:

- U-Net
- U-Net++
- U-Net 3+
- Swin-Unet
- TransUNet

Sonraki aşamada GAN ile birleşen segmentasyon yapılarına bakılacak ve U-Net sürümleri ile GAN tabanlı segmentasyon karşılaştırılacak. Hoca bunun için "GAN based segmentation" araması yaptı ve 2022 tarihli "Generative Adversarial Networks in Medical Image Segmentation" derlemesini gösterdi. Bu derlemede karşılaştırma yapılabilecek çok sayıda güncel yöntem bulunduğunu söyledi. Hoca ayrıca daha önce gönderdiği, çekişmeli (adversarial) ağ kullanan bir segmentasyon makalesini hatırlattı. <!-- BELİRSİZ: Makale adı altyazıda "Segmentation using adversarial neer net" diye bozuk geçiyor; tam adı karede görünmüyor. -->

> **Ek bilgi (derste anlatılmadı):** GAN tabanlı segmentasyonda genellikle üretici (generator) ağ bir segmentasyon maskesi üretir, ayırt edici (discriminator) ağ ise bu maskenin gerçek (uzman çizimi) mi yoksa üretilmiş mi olduğunu ayırt etmeye çalışır. Bu çekişme, üretilen maskelerin şekil olarak gerçek maskelere benzemesini sağlar. U-Net ailesi bu yapılarda sıkça üretici olarak kullanılır.

## 4. Yarı gözetimli öğrenme için veri hazırlığı

Bir öğrenci yarı gözetimli (semi-supervised) öğrenme üzerine, özellikle self-training ile çalışıyordu. Veri setini indirmiş, etiketlerle verileri okuyup eşleştiren ve ön işlemeyi yapan kodu yazmaya başlamıştı. Hoca, makaleleri incelerken yeni bir yaklaşım kurgulanabilmesine dikkat edilmesini istedi.

> **Ek bilgi (derste anlatılmadı):** Self-training'de model önce etiketli verilerle eğitilir, sonra etiketsiz verilere tahmin verir. Güveni yüksek tahminler sözde etiket (pseudo-label) olarak eğitim setine eklenir ve model yeniden eğitilir. Bu döngü birkaç kez tekrar edilir.

## 5. Servikal sitoloji görüntülerinde sınıflandırma

### 5.1 Veri setleri

Bir öğrenci servikal kanser görüntülerinin sınıflandırması üzerine çalışıyordu. İncelediği makalelerde genellikle SIPaKMeD setinin kullanıldığını, bu setin Kaggle'da da bulunduğunu anlattı. Hoca da IEEE üzerinden bir başka servikal görüntü setini önerip indirilmesini istedi. Öğrenci, Pap smear setinin SIPaKMeD'den alınmış kırpılmış görüntülerden oluştuğunu söyledi. <!-- BELİRSİZ: Altyazıda "Pub Smaer zaten spek meet ondan alınmış ... Kırtılmış görüntüler" geçiyor; setler arasındaki ilişki karede doğrulanamadı. --> Sınıf sayısı soruldu: SIPaKMeD 5 sınıflıdır.

### 5.2 Literatürdeki yöntemler

Öğrencinin incelediği çalışmalarda önce ön işleme yapılmış, sonra öznitelikler birleştirilmiş ve makine öğrenmesi algoritmaları kullanılmıştı. Bu alandaki çalışmalarda makine öğrenmesi ve CNN genellikle birlikte kullanılıyor, son sınıflandırıcı olarak çoğunlukla SVM seçiliyor. Bir çalışmada AlexNet ve SVM kullanılmıştı. Öğrencinin dikkatini çeken son çalışmada iki CNN'den öznitelik çıkarılmış, bu öznitelikler birleştirilip SVM ile sınıflandırılmıştı. <!-- BELİRSİZ: Altyazıda "iki tane CNN A var. Şaf'ı kullanıyor. Bir de kendileri bir CNN ... buluşturmuşlar ... 44 tane özellik" geçiyor; model adları ve öznitelik sayısı doğrulanamadı. --> Hoca ayrıca adı "Selgan" diye geçen GAN tabanlı bir sınıflandırma çalışmasını gösterdi. <!-- BELİRSİZ: "Selgan" büyük olasılıkla hücre görüntüleri için bir GAN yöntemidir; adı karede doğrulanamadı. -->

### 5.3 Hocanın önerdiği yol

Hoca adımları şöyle sıraladı:

- Görüntüleri temizlemek ve her sınıfta kaç örnek olduğunu çıkarmak.
- Görüntü boyutlarına bakmak. Transfer öğrenme modelleri tipik olarak $224 \times 224$ giriş kabul eder. Görüntü küçükse yeniden boyutlandırılır (resize). Büyükse içinden yamalar (patch) kesilir.
- Önce DenseNet, ResNet, Inception, Xception, EfficientNet, NASNet gibi standart transfer öğrenme modelleriyle sonuç almak.
- Sonra GAN tabanlı yapıyı ve öğrencinin bulduğu çalışmanın yapısını değiştirerek yeni bir yapı kurmak.

### 5.4 Yama çıkarmada dikkat edilecek nokta

Hoca yama çıkarmanın inceliğini şöyle açıkladı: veri setinde normal ve anormal sınıflar vardır. Her iki sınıftan da hücre bulunmayan yerlerden, yani arka plandan ya da hücre dışı bölgeden yama kesilirse bu yamalar aynı şeyi gösterir. Hastalık hücrelerin dağılımından ve morfolojik yapısından anlaşılır. Bu yüzden kesilen yamaların hücre içermesi gerekir.

> **Hocanın vurgusu:** Standart transfer öğrenme karşılaştırması önemlidir. Yeni yapının başarısı ancak eldeki standart sonuçlarla karşılaştırılarak değerlendirilebilir.

## 6. Üç sınıflı görüntü sınıflandırmada transfer öğrenme ve ensemble

### 6.1 Önce transfer öğrenme, sonra derin ensemble

Son görüşmede bir öğrenci üç sınıflı bir görüntü sınıflandırma problemi için uyarlayabileceği CNN örneklerini Kaggle'da aradığını anlattı. Hoca sırayı netleştirdi: önce transfer öğrenme yapılacak, sonra bu modeller derin ensemble ile birleştirilecek. Kodun illa TensorFlow ile yazılmasına gerek yoktur. Türkçe olanlar da dahil, transfer öğrenme ile görüntü sınıflandırmayı adım adım anlatan çok sayıda kaynak ve video vardır. "Transfer learning for image classification" araması bile birçok uyarlama örneği getirir. Hoca ayrıca PyTorch ile ensemble model kurulan bir görüntü sınıflandırma örneği gösterdi.

### 6.2 Ekrandaki örnek: CNN modeli ve ensemble

Öğrencinin ekranda gösterdiği Kaggle defterinde meme kanseri tespiti için bir CNN modeli kuruluyordu. Görünen kısım şöyledir (ekrandan, 00:20:00):

```python
#start bulding CNN Model
cnn_model = Sequential()
cnn_model.add(layers.Conv2D(64,(3,3),padding ='Same',activation = 'relu',input_shape=(50,50,3)))
cnn_model.add(layers.MaxPooling2D(2,2))
cnn_model.add(BatchNormalization())
cnn_model.add(layers.Conv2D(128,(3,3) ,padding ='same',activation='relu'))
cnn_model.add(layers.MaxPooling2D(2,2))
cnn_model.add(BatchNormalization())
cnn_model.add(layers.Conv2D(128,(3,3),padding ='same',activation='relu'))
cnn_model.add(layers.MaxPooling2D(2,2))
cnn_model.add(BatchNormalization())
cnn_model.add(layers.Conv2D(256,(3,3) ,padding ='same',activation='relu'))
cnn_model.add(layers.MaxPooling2D(2,2))
cnn_model.add(BatchNormalization())
cnn_model.add(layers.Conv2D(256,(3,3) ,padding ='same',activation='relu'))
cnn_model.add(layers.MaxPooling2D(2,2))
# ... (defterin devamı ekranda görünmüyor)
```

Yapı, art arda gelen evrişim (3×3 çekirdek, `same` dolgu, ReLU), 2×2 en büyük havuzlama ve toplu normalleştirme bloklarından oluşur; filtre sayısı katmanlar ilerledikçe 64'ten 256'ya çıkar. Defterin içindekiler listesinde veri hazırlama, ön işleme, veri dengeleme, CNN modeli ve "Ensemble Model" bölümleri görünüyor. Hoca ensemble'ın nasıl yapıldığını sordu; örnekte üç modelin birleştirildiği görüldü.

> **Hocanın vurgusu:** Kodu uyarlamadan önce derin ensemble hakkında bir altyapı oluşturulmalı. Bunun için "Ensemble Deep Learning: A Review" gibi derleme makaleleri ve V7 Labs'ın ensemble öğrenme yazısı gibi anlatımlar okunmalı.

> **Ek bilgi (derste anlatılmadı):** Derin ensemble'da birkaç farklı model aynı görevi ayrı ayrı öğrenir, sonra tahminleri birleştirilir. En basit birleştirme yolları olasılık çıktılarının ortalamasını almak (soft voting) ya da sınıf tahminlerinde çoğunluk oyu (hard voting) kullanmaktır. Modellerin farklı hatalar yapması birleşik tahmini tek tek modellerden daha kararlı yapar.

## 7. Örnek Sorular

**Soru 1** (derste sözlü, 00:02:58): İncelenen meme kanseri makalesinde geçen EWT ve VMD nedir, yönteme nasıl katılabilir?

> **Cevap:** EWT, Empirical Wavelet Transform; VMD, Variational Mode Decomposition'dır. Hoca, makale temel alınarak aynı yapının kendi verisine uyarlanmasını, transfer öğrenme modelleriyle kurulan ensemble'a EWT ve VMD ayrıştırmalarının da eklenmesini önerdi.

**Soru 2** (derste sözlü, 00:15:49): Servikal sitoloji görüntülerini güncel yöntemlerle sınıflandırmak için hangi yöntemler kullanılabilir?

> **Cevap:** Önce görüntüler temizlenir ve sınıf dağılımı çıkarılır. Görüntüler $224 \times 224$ girişe göre yeniden boyutlandırılır ya da büyükse hücre içeren bölgelerden yama kesilir. İlk olarak DenseNet, ResNet, Inception, Xception, EfficientNet, NASNet gibi transfer öğrenme modelleriyle bir karşılaştırma tabanı kurulur. Ardından GAN tabanlı yöntemler ve literatürdeki yapının değiştirilmiş bir biçimi denenir.

**Soru 3** (derste sözlü, 00:22:04): Ekrandaki örnekte ensemble nasıl yapılıyor?

> **Cevap:** Örnekte üç model birleştiriliyor. Hoca, bu kodu uyarlamadan önce derin ensemble öğrenme hakkında derleme makaleleriyle bir altyapı oluşturulmasını istedi.

## Dersin Toparlaması

Bu derste tıbbi görüntü işleme projelerinin ilerlemesi görüşüldü. Meme kanseri, histopatolojik çekirdek segmentasyonu, yarı gözetimli öğrenme ve servikal sitoloji projelerinde ortak yöntem çizgisi belirlendi: önce maskeli ya da etiketli uygun veri setini seçmek, sonra standart transfer öğrenme modelleri (sınıflandırmada) ya da U-Net ailesi (segmentasyonda) ile bir karşılaştırma tabanı kurmak, en sonunda derin ensemble, EWT/VMD gibi ayrıştırma yöntemleri ya da GAN tabanlı yapılarla yeni bir yöntem önermek.

Görüntü hazırlığında iki pratik kural öne çıktı: transfer öğrenme modelleri tipik olarak $224 \times 224$ giriş bekler, ve büyük görüntülerden yama kesilirken yamaların hücre içermesi gerekir, çünkü hastalık bilgisi hücrelerin dağılımında ve morfolojisindedir.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
