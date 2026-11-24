# Ders 2 Genişletilmiş Notu: Proje İlerleme Sunumları: Tıbbi Görüntü Veri Setleri ve Yöntem Seçimi

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dersin biçimi ve genel çerçeve
- 2. Vision Transformer ile göğüs röntgeni sınıflandırması
- 3. Göğüs röntgeni veri setleri ve Graph Learning
- 4. BRACS veri seti ve manifold öğrenme
- 5. Servikal hücre segmentasyonu ve segmentasyon veri setleri
- 6. Kolorektal kanser histopatolojisi, CNN ve patching
- 7. Derin metrik öğrenme ve meme kanseri görüntüleri
- 8. Semantik segmentasyon için karşılaştırma yöntemleri
- 9. Lizard veri seti ve yarı denetimli öğrenme
- Örnek Sorular
- Dersin Toparlaması

## 1. Dersin biçimi ve genel çerçeve

Bu ders, dönem projelerinin ilerleme oturumu olarak geçti. Öğrenciler sırayla ekran paylaşarak seçtikleri tıbbi görüntü veri setini, okudukları makaleleri ve düşündükleri yöntemi anlattı; hoca her sunumdan sonra yöntem ve veri seti önerileri verdi. Notta sunumların teknik içeriği ve hocanın yönlendirmeleri konu sırasıyla aktarılmıştır.

Bütün projeler için ortak çerçeve şuydu: önce standart transfer öğrenmesi yöntemleriyle hızlıca bir temel sonuç alınır, ardından güncel bir derin öğrenme yöntemi uyarlanarak yöntemsel bir yenilik aranır ve iki sonuç karşılaştırılır.

> **Hocanın vurgusu:** Transfer öğrenmesi artık standart hâle geldi, birkaç satır kodla uygulanıyor. Bu yüzden asıl yöntem olamaz; karşılaştırma için bir basamak olarak kullanılır. Bizim için asıl önemli olan yöntemsel yeniliktir.

## 2. Vision Transformer ile göğüs röntgeni sınıflandırması

### 2.1 Sunumdaki ilk çalışma

İlk sunumda bir öğrenci, göğüs röntgeni (X-ray) görüntüleri üzerinde Kaggle'da bulduğu örnek kodlarla transfer öğrenmesi ve CNN denediğini, ayrıca Vision Transformer'ı (ViT) incelemeye başladığını anlattı. Etiketsiz bir veri setiyle çalışılamadığını, bu yüzden etiketli bir setle devam ettiğini belirtti. Hoca, X-ray tarafında çok sayıda veri seti bulunduğunu ve farklı setlerin de indirilmesini istedi.

Öğrencinin ViT'yi ilk anlayışı "görüntüyü parçalara bölüp sıralı biçimde veriyor" şeklindeydi. Hoca bunu doğruladı: Transformer'lar doğal dil işlemede (NLP) yaygın kullanılır, ViT bunun görüntüye uyarlanmış hâlidir.

### 2.2 ViT yalnız nesne bulma değildir

Öğrenci ViT'yi önce nesne bulmaya dayalı bir yöntem olarak algıladığını söyledi. Hoca, ViT tabanlı sınıflandırıcıların görüntüyü bütün olarak alıp "hastalıklı / hastalıksız" gibi sınıflara ayırmakta da kullanıldığını belirtti ve arama sonucunda çıkan "Enhanced Vision Transformer Architecture for Chest X-Ray Image Classification" başlıklı çalışmayı örnek gösterdi. Yani sadece nesne bulma değil, görüntü sınıflandırması için kullanılan ViT sürümleri de vardır.

### 2.3 ViT mimarisi (ekrandan, 00:05:00)

Ekranda gösterilen slayt ViT mimarisini adım adım veriyordu:

1. Görüntü sabit boyutlu yamalara (patch) bölünür.
2. Yamalar düzleştirilir (flatten).
3. Düzleştirilmiş yamalardan daha düşük boyutlu doğrusal gömmeler (linear embedding) üretilir.
4. Konum gömmeleri (positional embedding) eklenir.
5. Elde edilen dizi Transformer kodlayıcıya (encoder) girdi olarak verilir.
6. ViT modeli büyük bir veri setinde görüntü etiketleriyle tamamen denetimli olarak ön eğitilir.
7. Hedef (downstream) veri setinde görüntü sınıflandırması için ince ayar yapılır.

Slayttaki şekilde yamalar "Linear Projection of Flattened Patches" katmanından geçer, "Patch + Position Embedding" ile numaralanır; dizinin başına ek, öğrenilebilir bir sınıf gömmesi (0 numaralı, `[class]` embedding) konur. Dizi "Transformer Encoder"a girer, sınıf kararı "MLP Head" üzerinden çıkar (örnekte Bird, Ball, Car gibi sınıflar). Sağdaki kodlayıcı bloğu aşağıdan yukarı şöyledir ve L kez tekrarlanır:

```text
Embedded Patches
  -> Norm -> Multi-Head Attention -> (+) artık bağlantı
  -> Norm -> MLP                  -> (+) artık bağlantı
  (blok L kez tekrarlanır)
```

### 2.4 Hocanın yönlendirmesi

Hoca, ViT ile göğüs röntgeni sınıflandırması üzerine yapılan çalışmaların literatürünün bir yere kaydedilmesini istedi; ileride bir bildiri yazılırsa giriş bölümünde konuyu bir bütün olarak anlatmak için 20-25 kadar kaynağa ihtiyaç olacak. Önce ViT kurulacak, ardından DenseNet, ResNet, Inception gibi transfer öğrenmesi yapılarıyla karşılaştırılıp sonuçların onlara yakın mı, onları geçiyor mu olduğuna bakılacak. COVID-19 X-ray görüntüleriyle karşılaştırma yapan yeni çalışmaların da incelenmesi önerildi.

## 3. Göğüs röntgeni veri setleri ve Graph Learning

### 3.1 RSNA COVID-19 X-ray verisi

İkinci sunumda bir öğrenci, RSNA'nın yarışma için paylaştığı göğüs röntgeni verisini anlattı. Görüntüler dört sınıfa etiketlenmiştir: negatif (zatürre yok), tipik COVID-19 görünümü, belirsiz (indeterminate) görünüm ve atipik görünüm. Ayrıca akciğerdeki bulgu bölgeleri sınırlayıcı kutularla (bounding box) işaretlenmiştir; hocanın sorusu üzerine öğrenci bu kutuların akciğerdeki hava/opasite bölgelerini gösterdiğini söyledi. Etiketleri radyologlar koymuştur. Veri yaklaşık 128 GB'tır ve DICOM biçiminde saklanır. Yarışmada hem anormalliklerin tespiti hem de yerinin belirlenmesi (lokalizasyon) istenmiştir.

Bu veriyle yapılan bir çalışmada normal, zatürre ve COVID-19 olmak üzere üç sınıflı sınıflandırma yapılmış, hastalıklı bölgeler ısı haritası (heatmap) benzeri bir yöntemle gösterilmeye çalışılmıştır. Hoca, lokasyon tespitinin başarısının büyük olasılıkla örtüşme miktarıyla ölçüldüğünü belirtti.

> **Ek bilgi (derste anlatılmadı):** Nesne tespitinde kutu örtüşmesi genellikle IoU (Intersection over Union, kesişim/birleşim) ile ölçülür. Altyazıda öğrencinin "muhtemelen..." diye başlayan cevabı net değildir; bu ölçütün adı derste açıkça geçmedi.

### 3.2 Diğer göğüs röntgeni veri setleri (ekrandan, 00:10:00)

Sunumda "Diğer Datasetler" slaytında şu setler listelendi:

- Pneumonia dataset: zatürre tespiti için farklı bir RSNA yarışma veri seti.
- VinBigData Chest X-ray Abnormalities Detection: 13 farklı sınıf için etiketli veri; akciğer başlangıç ve bitiş piksel koordinatları bulunur.
- Chest14 veri seti.
- PadChest: PA (arka-ön) ve L (yan) göğüs röntgeni görüntüleri birlikte bulunur.

Öğrenci, yarışmada birinci olan takımın akciğerin her lobunu YOLO ağıyla tespit edip sınırlayıcı kutu çizdiğini, böylece akciğer dışındaki bölgeleri elediğini anlattı. Hoca, şimdilik bu kadar derine girmeden standart bir sınıflandırıcıyla yöntemlere yoğunlaşılmasını, lokalizasyonun sonraki çalışmalara bırakılabileceğini söyledi.

### 3.3 Graph Learning (ekrandan, 00:15:00)

Aynı öğrencinin ikinci konusu Graph Learning'di. Slayttaki tanımlar:

- Graflar, gerçek dünyadaki çeşitli varlıklar (entities) arasındaki ilişkilerin tanımlanmasıdır.
- Bir graf sıklıkla köşe (vertex) ve kenar (edge) olmak üzere iki kümeyle tanımlanır.
- Köşeler varlıkları, kenarlar bu varlıklar arasındaki ilişkiyi temsil eder.
- Graph Learning yöntemleri olgular arasındaki karmaşık ilişkileri yakalayabildiği için son zamanlarda popülerleşmiştir.
- Örnek: biyolojik çalışmalarda, tedavisi zor hastalıklar için proteinler arasındaki etkileşimler graf olarak çıkarılıp keşifler yapılabilir.
- Örnek: şehir trafiğinin farklı zamanlardaki yoğunlukları arasındaki ilişkilerden belirli zamanlardaki yoğunluk tahmin edilebilir.

Öğrenci ayrıca bir derlemede "heterogeneous academic network" başlığı altında verilen bir graf örneğini gösterdi. Hoca, Graph Learning'e giriş için "Machine Learning Tasks on Graphs" tarzı bir anlatımı önerdi: düğüm sınıflandırma (node classification), bağlantı tahmini (link prediction), topluluk tespiti (community detection) ve grafların sınıflandırma, kümeleme ve regresyon için nasıl kullanıldığı. Proje için aranacak şey "Graph Learning + classification" birleşimidir.

## 4. BRACS veri seti ve manifold öğrenme

### 4.1 BRACS (ekrandan, 00:20:00)

Bir öğrenci meme kanseri histopatoloji görüntülerinden oluşan, 2021'de yayımlanmış BRACS veri setini tanıttı. Slayttaki "Dataset Overview":

- 547 etiketli tam slayt görüntüsü (Whole Slide Image)
- 4539 etiketli ilgi bölgesi (Region of Interest)
- 189 hasta

Sınıf yapısı iki düzeylidir:

| Ana sınıf | Alt sınıflar |
|---|---|
| Benign Tumors (iyi huylu) | Normal, Pathological Benign, Usual Ductal Hyperplasia |
| Atypical Tumors (atipik) | Flat Epithelial Atypia, Atypical Ductal Hyperplasia |
| Malignant Tumors (kötü huylu) | Ductal Carcinoma In Situ, Invasive Carcinoma |

İndirilen veride alt sınıflar 0'dan 6'ya kadar numaralandırılmıştır, yani toplam 7 sınıf vardır. Böylece hem 3 sınıflı hem 7 sınıflı sınıflandırma yapılabilir; öğrenci 3 sınıfla başlamayı planladı, hoca da sonra genişletilebileceğini söyledi. Öğrencinin aktardığına göre eğitim kümesinde yaklaşık 3000 küsur, doğrulama kümesinde 500 küsur görüntü vardır, test kümesi de doğrulamaya yakındır.

### 4.2 Manifold öğrenme ile ne yapılabilir?

Öğrencinin yöntem konusu manifold öğrenmeydi ve çok sayıda yöntem olduğu için hangisinin uygun olduğunu sordu. Hoca, manifold öğrenme yöntemlerinin daha çok öznitelik çıkarma ve boyut indirgeme ile ilgili olduğunu söyledi: görüntüler (RGB, yani üç kanallı) Isomap, Laplacian Eigenmaps gibi yöntemlerle farklı uzaylara taşınır, elde edilen temsiller sınıflandırıcılara ya da transfer öğrenmesi yöntemlerine verilir ve başarımlar karşılaştırılır.

Öğrenci, konvolüsyonel otokodlayıcıyı (convolutional autoencoder) sinir ağlarıyla birleştirerek sınıflandırma yapan makaleler bulduğunu söyledi. Hoca, manifold yöntemlerinden birkaçının seçilip otokodlayıcılara ve sınıflandırıcıya verilmesini, sonuçların karşılaştırılmasını önerdi. Bu yol verim vermezse Deep Ensemble Learning'e geçilebilir.

Hoca ayrıca "Learning Texture Manifolds" başlıklı bir çalışmayı sohbete ekledi. Gerekçesi şuydu: farklı sınıflar büyük olasılıkla farklı yüzey dokuları (texture) oluşturur; doktorlar da bu sınıfları görsel olarak ayırt eder. Bu nedenle doku manifoldlarını öğrenen bir yaklaşım sınıflandırmaya uyarlanabilir.

## 5. Servikal hücre segmentasyonu ve segmentasyon veri setleri

### 5.1 GAN tabanlı segmentasyon

Bir öğrenci üç makale inceledi. Birincisinde servikal (rahim ağzı) hücre görüntülerinde, özellikle üst üste binen hücreleri ayırabilmek için GAN tabanlı bir segmentasyon yöntemi kullanılmıştı; yöntem "Generation" ve "Discrimination" olmak üzere iki ana bölümde anlatılıyordu. İkinci makalede GAN tabanlı yarı denetimli (semi-supervised) öğrenme vardı ve örnek kodlar ile veri setleri paylaşılmıştı. Üçüncüsü bir yöntem derlemesiydi; öğrenci yalnız GAN tabanlı yönteme odaklandı.

Öğrenci, birinci makaledeki servikal veri setine erişemediğini, verinin işlenmesinin de çok uzun sürdüğünü söyledi. Hoca, üst üste binen hücreleri ayırmanın ayrı ve zor bir problem olduğunu, projede hatalı da olsa yalnız segmentasyon yapmanın yeterli olduğunu belirtti.

### 5.2 Gösterilen veri seti (ekrandan, 00:30:00)

Sunumda gösterilen üçüncü veri seti slaytı:

- Başlık: "Stacked BCDU-Net with Semantic CMR Synthesis: Application to Myocardial Pathology Segmentation Challenge" (Zenodo bağlantısıyla).
- Açıklama: çok dizili kardiyak MR (CMR) görüntülerinde otomatik patoloji segmentasyonu için yeni bir yaklaşım; yöntem iki aşamalıdır ve güncel derin öğrenme tekniklerini kullanır; model 5 zaman noktasından alınmış 256x256 boyutlu CMR görüntüleriyle eğitilmiştir.

### 5.3 Hocanın önerdiği segmentasyon veri setleri

Hoca, segmentasyon çalışılacaksa Warwick'in paylaştığı veri setlerine ve PanNuke'a bakılmasını önerdi. PanNuke hem segmentasyon hem sınıflandırma için kullanılabilir. Bunun yanında 2019'da yayımlanmış bir kolorektal çekirdek segmentasyonu veri seti ve floresan hücre segmentasyonu veri setleri de vardır; hocaya göre PanNuke ve kolorektal set yeterli olacaktır.

> **Hocanın vurgusu:** Çalışmaları yaparken incelediğiniz kaynakları not edin. Google Scholar'dan aldığınız BibTeX kayıtlarını bir referans dosyasında toplayın; LaTeX'te yazarken işinize yarayacak.

## 6. Kolorektal kanser histopatolojisi, CNN ve patching

### 6.1 Konu ve literatür (ekrandan, 00:35:00)

Bir öğrenci kolorektal kanseri (kalın bağırsak ya da kolon ve rektum kanseri, CRC/KRK) konusunu sundu. Öğrencinin aktardığına göre kolorektal kanser en sık görülen kanser türleri arasında üçüncü sıradadır. Bu alandaki çalışmalarda bir kısmı görüntüler üzerinde CNN gibi görüntü işleme yöntemleri kullanırken, bir kısmı görüntülerden sayısal öznitelikler çıkarıp klasik yöntemler kullanmıştır. Yöntemler arasında en sık sınıflandırma, self-supervised öğrenme ve görüntü segmentasyonu görülür; Vision Transformer ve Graph Learning daha az kullanılmıştır.

Hoca, öğrencinin listelediği klasik makine öğrenmesi yöntemlerinin temel düzeyde kaldığını, karşılaştırma amacıyla kullanılabileceklerini ama derin öğrenmenin güncel algoritmalarına yönelmek gerektiğini söyledi.

### 6.2 Klasik sınıflandırıcı ile CNN arasındaki fark

Hocanın açıklaması şöyleydi: standart sınıflandırıcılarda (SVM, Naive Bayes gibi) önce bir öznitelik çıkarma adımı uygulanır, ardından öznitelikler sınıflandırıcıya verilir. Evrişimli sinir ağları gibi iki boyutlu girdi alan yapılarda ise görüntünün kendisi verilir; öznitelik çıkarma ağın içinde, konvolüsyon katmanlarında çeşitli filtrelerle yapılır ve ardından sınıflandırma gelir.

İncelenen örnek makalede görüntülerin renk ve yoğunluk değerlerinden, gri seviyeye çevrilerek öznitelikler çıkarılmış ve SVM gibi sınıflandırıcılar kullanılmıştı. Veri setinde 8 doku tipi ve her birinde 625 görüntü vardır.

> **Ek bilgi (derste anlatılmadı):** 8 sınıf × 625 görüntü toplam 5000 görüntü eder; öğrencinin "5 bine büyüttükleri" ifadesi büyük olasılıkla veri artırma değil, bu toplam sayıdır. Bu sayılar büyük olasılıkla Kather ve arkadaşlarının kolorektal doku veri setine aittir; set adı derste geçmedi.

### 6.3 Alt görüntü boyutu ve patching yöntemi (ekrandan, 00:40:00)

Hoca, alt görüntülerin kaça kaç olduğunun önemli olduğunu vurguladı. Derin öğrenme ağları genellikle 224x224 boyutlu girdi alır. Görüntü bundan büyükse iki seçenek vardır: görüntüyü yeniden boyutlandırmak (resize) ya da içinden 224x224'lük parçalar seçmek. İkincisine patching yöntemi denir.

Hoca beyaz tahtada büyük bir kare çizip sol üst köşesine 224 kenarlı bir parça yerleştirdi; sağ tarafta 224x224'lük bir parçanın ağa girdi olarak verildiğini gösterdi. Anlatılan işlem şöyledir:

- Büyük görüntünün sol üst köşesinden 224x224'lük bir parça kesilir.
- Pencere belli bir örtüşmeyle sağa kaydırılarak yeni parçalar kesilir. Bir piksel kaydırmanın anlamı yoktur; örneğin 224'lük pencere 112 piksel kaydırılır.
- Satır bitince pencere aşağı kaydırılır ve aynı işlem tekrarlanır.
- Sonuçta giriş boyutu sağlanır ve eğitim verisi çoğalır.

Hoca örnek olarak 512 boyutlu bir görüntüden söz etti.

> **Ders sonrası not:** Altyazıda aşağı kaydırma miktarı "124" olarak geçiyor; yatayda 112 denildiği için büyük olasılıkla burada da 112 kastedilmiştir (Whisper ya da dil sürçmesi).

> **Ek bilgi (derste anlatılmadı):** W kenarlı bir görüntüde P boyutlu pencere S adımıyla kaydırılırsa bir eksendeki parça sayısı $\lfloor (W-P)/S \rfloor + 1$ olur. Derste geçen 512, 224 ve 112 değerleriyle bu, eksen başına 3 (başlangıçlar 0, 112, 224), toplam $3 \times 3 = 9$ parça eder; derste bu hesap yapılmadı.

Öğrenci, incelediği makalenin bunun tersini yaptığını, yani küçük doku görüntülerini birleştirerek büyük bir görüntü oluşturduğunu gösterdi; hoca bunun nedenini anlamadığını söyledi.

### 6.4 Önerilen yöntem yolu

Hocanın tavsiyesi: önce transfer öğrenmesiyle hızlıca sonuç alınır, çünkü hızlı uyarlanıp eğitilebilir. Ardından güncel bir yönteme geçilir. Seçenekler: self-supervised öğrenme, weakly supervised (zayıf denetimli) sınıflandırma, few-shot learning, Bayesian deep learning, graf tabanlı yöntemler, Vision Transformer. Hoca Papers with Code'da "self-supervised" araması yapıp çıkan başlıkları gösterdi: few-shot görüntü sınıflandırması için self-supervised öğrenme, tıbbi görüntü sınıflandırması, self-ensembling yöntemi, weakly supervised görüntü sınıflandırması.

**Soru:** SVM gibi yöntemlere girmeyelim mi? **Cevap:** Girme; orada ayrıca öznitelik çıkarma yöntemleri çalışıp sonuçlarını sınıflandırıcıya vermen gerekir.

**Soru:** CNN ile self-supervised ve weakly supervised farklı şeyler mi? **Cevap:** Bunlar iç içe geçebilir. CNN sınıflandırıcı olarak kullanılır. Transfer öğrenmesi yöntemleri aslında CNN'in farklı katman mimarileriyle kurulmuş, geliştirenlerin ad verdiği hâlleridir: AlexNet ile başlayan, VGG, DenseNet, ResNet, Inception gibi. Self-supervised ve weakly supervised ise öğrenme biçimini tanımlar.

Hoca, TensorFlow'un transfer öğrenmesi öğreticilerinde (Türkçe çevirisi de olan) çok sayıda örnek bulunduğunu gösterdi.

## 7. Derin metrik öğrenme ve meme kanseri görüntüleri

Bir öğrenci meme kanseri görüntüleri üzerine çalıştı. Öğrencinin aktardığına göre en sık görülen tür invaziv duktal karsinomdur (Invasive Ductal Carcinoma). Kaggle'da bulduğu bir veri setinde görüntüler 0-1 olarak, yani kanserli ve kansersiz diye ikili etiketlenmiştir.

Öğrencinin yöntem konusu derin metrik öğrenmeydi (deep metric learning). Anlattığı temel fikir şudur: bir mesafe metriği üzerinde hesap yapılarak benzer örnekler birbirine yaklaştırılır, farklı örnekler uzaklaştırılır. PyTorch'ta bu yöntemler için pytorch-metric-learning kütüphanesine baktığını gösterdi (ekrandan, 00:50:00); kütüphane, derin metrik öğrenmeyi uygulamalarda modüler ve esnek biçimde kullanmayı sağlayan, PyTorch ile yazılmış bir araçtır. Öğrenci ayrıca kayıp fonksiyonları ve metrik öğrenme ile yarı denetimli öğrenme arasındaki ilişkiye baktığını anlattı.

Hoca, sınıflandırma için PanNuke veri setinin de kullanılabileceğini söyledi. İkinci aşamada önerilen yöntem, basit CNN tabanlı standart transfer öğrenmesi yöntemleriyle karşılaştırılacak; bunlar bir basamak olarak kullanılacak ve önerilen yöntemin başarımı artırıp artırmadığı incelenecek.

## 8. Semantik segmentasyon için karşılaştırma yöntemleri

Bir öğrenci, kan yayması görüntülerinden segmentlere ayrılmış beyaz kan hücrelerini ve immünohistokimya görüntülerinden lenfosit segmentasyonunu içeren veri setlerini tanıttı. Bu setler etkileşimli segmentasyon üzerine bir makalede yer alıyordu. Hoca öğrencinin semantik segmentasyon üzerine çalışmasını istedi; öğrenci GAN tabanlı yöntemleri ve DeepLab v3'ü incelemişti.

Hocanın beklediği karşılaştırma ailesi:

- SegNet ve onun geliştirilmiş bir sürümü olan U-Net.
- U-Net türevleri: TransUNet, Swin-UNet, UNet++.
- Panoptik segmentasyon: karşılaştırma amacıyla kullanılabilir.

Hocaya göre bu liste segmentasyon çalışan bütün öğrenciler için geçerlidir.

**Soru:** Makalede panoptik değil "panoramik segmentasyon" geçiyordu; ikisi aynı şey mi? **Cevap:** Değil.

> **Ek bilgi (derste anlatılmadı):** Panoptik segmentasyon, semantik segmentasyon (her pikselin sınıfı) ile örnek segmentasyonunu (instance segmentation, aynı sınıftaki ayrı nesnelerin ayrılması) birleştirir. "Panoramik" ifadesi ise büyük olasılıkla geniş görüş açılı (panoramik) görüntüler üzerinde yapılan segmentasyonu anlatır.

## 9. Lizard veri seti ve yarı denetimli öğrenme

### 9.1 Histopatoloji veri setleri (ekrandan, 01:05:00)

Hoca, sınıflandırma çalışacak öğrencilere BACH, PanNuke ve Lizard veri setlerini önerdi. Lizard hem sınıflandırma hem segmentasyon için kullanılır; bir öğrencinin cevabına göre veri tamamen etiketlidir ve 6 sınıf içerir. Lizard'ı inceleyen öğrencinin sunumunda kaynak veri setleri şöyle listelenmişti: GlaS, CRAG, ConSeP, PanNuke, TCGA, DigestPath. Öğrencinin aktardığına göre etiketler otomatik ve yarı otomatik yöntemlerle üretilmiştir.

### 9.2 Yarı denetimli öğrenme deney düzeni

Öğrenci, etiketli verilerden öznitelik çıkarıp denetimli algoritmalara vermeyi ya da derin öğrenmeyi düşündüğünü sordu. Hoca, yarı denetimli derin öğrenme yöntemleri uyarlanacağını hatırlattı ve deney düzenini şöyle anlattı:

- Veri tamamen etiketli olsa da yarı denetimli yöntemlerde verinin bir kısmının etiketi kullanılmaz.
- Eğitim ve test ayrımı hazır değilse K-katlı çapraz doğrulama (K-fold cross validation) kullanılır: 5 katın 4'üyle eğitilir, 1'iyle test edilir; test katı sırayla değiştirilir.
- Sonuç olarak katların ortalaması verilir; kod buna göre yazılmalıdır.
- Hangi yarı denetimli yöntemlerin kullanılacağı iyi bir literatür taramasıyla seçilmelidir; Papers with Code'da "semi-supervised" araması bunun için iyi bir başlangıçtır.

**Soru:** Öznitelik çıkarmayı kendim mi yapayım? **Cevap:** Derin yöntemlerde öznitelik çıkarma ayrıca pek kullanılmaz; ağ bunu kendisi yapar. Ayrı öznitelik çıkarma ancak klasik (conventional) yöntemlerle karşılaştırma yapılacaksa gerekir.

## Örnek Sorular

1. (derste sözlü, 00:38:27) Büyük bir histopatoloji görüntüsü (örneğin 512 boyutlu) 224x224 giriş bekleyen bir derin ağa nasıl verilir?

   > **Cevap (derste verildi):** Ya yeniden boyutlandırılır ya da patching uygulanır: 224x224'lük pencere örtüşmeli olarak (örneğin 112 adımla) yatayda ve dikeyde kaydırılarak parçalar kesilir. Bu hem giriş boyutunu sağlar hem veriyi artırır.

2. (derste sözlü, 00:44:33) CNN ile self-supervised ve weakly supervised öğrenme farklı şeyler mi?

   > **Cevap (derste verildi):** İç içe geçebilirler. CNN sınıflandırıcı mimarisidir; transfer öğrenmesi mimarileri (AlexNet, VGG, DenseNet, ResNet, Inception) CNN'in adlandırılmış farklı katman düzenleridir. Self-supervised ve weakly supervised ise eğitimin hangi etiket bilgisiyle yapılacağını tanımlar.

3. (derste sözlü, 00:52:47) Panoptik segmentasyon ile panoramik segmentasyon aynı şey midir?

   > **Cevap (derste verildi):** Hayır, değildir.

4. (derste sözlü, 01:01:49) Lizard veri setinde sınıflandırma yapılabilir mi?

   > **Cevap (derste verildi):** Evet; veri tamamen etiketlidir ve 6 sınıf vardır, hem sınıflandırma hem segmentasyon için kullanılır.

5. (derste sözlü, 01:08:02) Derin yöntemle çalışırken öznitelik çıkarmayı ayrıca yapmak gerekir mi?

   > **Cevap (derste verildi):** Hayır; derin yöntemlerde öznitelik çıkarma ağın içinde yapılır. Ayrı öznitelik çıkarma yalnız klasik yöntemlerle karşılaştırma için gerekir.

## Dersin Toparlaması

Bu oturumda tıbbi görüntü analizinde proje kurmanın genel kalıbı farklı veri setleri üzerinden tekrar tekrar işlendi: uygun ve etiketli bir veri seti seçmek (RSNA, VinBigData, Chest14, PadChest göğüs röntgenleri; BRACS meme histopatolojisi; PanNuke, Lizard, BACH, kolorektal ve servikal setler), standart transfer öğrenmesiyle bir temel sonuç almak ve ardından güncel bir yöntemle (Vision Transformer, Graph Learning, manifold öğrenme ve otokodlayıcılar, derin metrik öğrenme, self-supervised, weakly supervised, yarı denetimli öğrenme, Bayesian ya da ensemble yaklaşımlar) yöntemsel yenilik aramak.

Teknik açıdan öne çıkan noktalar ViT'nin yama tabanlı mimarisi, klasik sınıflandırıcılarla CNN arasındaki öznitelik çıkarma farkı, büyük görüntülerde patching yöntemi, segmentasyonda SegNet / U-Net ailesiyle karşılaştırma ve yarı denetimli deneylerde K-katlı çapraz doğrulamadır.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
