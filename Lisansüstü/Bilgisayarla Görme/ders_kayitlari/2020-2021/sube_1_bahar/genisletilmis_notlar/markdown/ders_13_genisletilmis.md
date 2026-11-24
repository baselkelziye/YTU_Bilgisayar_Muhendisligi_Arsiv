# Ders 13 Genişletilmiş Notu: Proje Sunumları: DeepEMD ile Az Örnekli Sınıflandırma, Havadan Görüntülerle Trafik Modelleme ve Tek Görüntüden Derinlik Kestirimi

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dersin yapısı
- 2. Az örnekli sınıflandırma ve DeepEMD
- 3. Kuş bakışı görüntülerden dinamik trafik modelleme
- 4. Tek görüntüden derinlik kestirimi: Semantic Divide-and-Conquer Network
- Örnek Sorular
- Dersin Toparlaması

## 1. Dersin yapısı

Bu, dönemin son dersidir ve proje sunumlarının üçüncü haftasıdır. Üç öğrenci, bilgisayarla görme alanındaki birer güncel konferans makalesini anlattı. Hoca, proje sunumlarının insanların ne tür problemlerle uğraştığını, hangi veri setlerini kullandığını ve uygulama alanlarının çeşitliliğini görmek açısından çok faydalı olduğunu söyledi. Bir sunucu da, sözle ifade edildiğinde çok basit görünen fikirlerin koda ve matematiğe dökülünce birden karmaşıklaştığını fark ettiklerini ekledi.

## 2. Az örnekli sınıflandırma ve DeepEMD

İlk sunumun konusu "DeepEMD: Few-Shot Image Classification with Differentiable Earth Mover's Distance" makalesidir, yani sınıflandırmanın Earth Mover's Distance (EMD) adlı bir mesafe kavramıyla yapılmasıdır.

### 2.1 Az örnekli (few-shot) sınıflandırma nedir

Derin öğrenme yöntemlerinin düzgün çalışması için çok fazla veri gerekir; ama her görev için çok veri toplamak mümkün değildir ya da çok zahmetlidir. Few-shot sınıflandırma, az veriyle öğrenme problemidir ve insanın öğrenme biçiminden esinlenir. Bir çocuk konuşmayı öğrenmek için binlerce kelime duyar ve ancak bir iki yıl sonra konuşur; ama daha sonraki yaşlarda yeni bir kelimeyi iki üç kez duyarak öğrenir. Görmede de durum aynıdır: bebekken milyonlarca görüntü görülür, sonra yeni bir nesneyi birkaç kez görmek sınıflandırmak için yeterli olur. Burada eski bilginin yeni durum için kullanılması söz konusudur. Örneğin milyonlarca köpek, fil, maymun resmiyle eğitilmiş bir model, eğitim verisinde olmayan birkaç lemur ya da tavşan resmiyle bu yeni sınıfları da ayırt edebilir hale getirilir.

Görevler "N-way K-shot" diye adlandırılır. "Shot" her sınıf için eğitimde kullanılan örnek sayısını, "way" kaç sınıfın ayrılacağını gösterir. Örneğin "5-way 2-shot" denildiğinde beş sınıf olduğu ve her sınıf için iki eğitim örneği bulunduğu anlaşılır. Eğitim örneklerinin oluşturduğu kümeye **destek kümesi (support set)**, test örneklerine **sorgu kümesi (query set)** denir.

### 2.2 Dört temel yaklaşım

Sunumda few-shot sınıflandırma yöntemleri dört ana başlıkta toplandı (ekrandan, 00:15:00):

- **Matching Network:** Resimleri karşılaştırmayı ve iki resmin farkını hesaplamayı öğrenir. Resimler önce öznitelik vektörüne çevrilir, sonra kosinüs, Öklid ya da EMD gibi bir ölçüyle karşılaştırılır. Test resmi destek kümesindeki her resimle karşılaştırılır; en düşük farka sahip destek resminin sınıfı, test resminin sınıfıdır.
- **Prototypical Network:** Destek resimleri öznitelik vektörüne çevrilir ve her sınıfın vektörlerinin ortalaması alınır. Bu ortalama sınıfın bir "prototipi" olduğu için yönteme bu ad verilir. Test resmi hangi sınıfın prototipine en yakınsa o sınıfa atanır. Slayttaki şekilde üç sınıfın merkezleri $c_1, c_2, c_3$ ve test noktası $x$ gösteriliyor.
- **Relation Network:** Matching Network'e benzer. Destek resminin öznitelik vektörü ile test resmininki birleştirilir (concatenate) ve bir ilişki modülü (relation module) bu ikisinin ilişkisine bakarak sınıflandırır. Slaytta ilişki skoru $r_{i,j} = g_\phi(\mathcal{C}(f_\varphi(x_i), f_\varphi(x_j)))$, $i = 1, 2, \ldots, C$ olarak veriliyor ve $r_{i,j}$ sigmoid ile $(0,1)$ aralığına sınırlanıyor.
- **Model-Agnostic Meta-Learning (MAML):** Sunucu bu yöntemi tam anlayamadığını belirterek anlatmadı; yalnız modele birçok görevin birlikte öğretilmesiyle ilgili olduğunu söyledi.

> **Ek bilgi (derste anlatılmadı):** MAML, model parametreleri için öyle bir başlangıç noktası $\theta$ öğrenir ki, yeni bir görevde birkaç gradyan adımıyla iyi sonuç verilsin. Her görev için $\theta$'dan başlayıp birkaç adım uyarlanmış parametreler bulunur, sonra bu uyarlanmış parametrelerin görev kayıpları toplanarak $\theta$ güncellenir. Slayttaki şekildeki $\nabla\mathcal{L}_1, \nabla\mathcal{L}_2, \nabla\mathcal{L}_3$ okları farklı görevlerin gradyanlarını, $\theta_1^*, \theta_2^*, \theta_3^*$ ise her göreve uyarlanmış parametreleri gösterir.

Hocanın sorusu üzerine sunucu, DeepEMD'nin Matching Network'e yakın olduğunu, resimlerin farkına baktığını; ama destek kümesinde birden fazla resim olduğunda bunların genel bir yapısını çıkardığı için biraz da prototip yaklaşımına yakın olduğunu söyledi.

### 2.3 Metrik tabanlı yöntemlerin yapısı

Metrik tabanlı yöntemlerde CNN modülü daha önce binlerce resim üzerinde eğitilip dondurulmuştur. Bu modülle resimlerin öznitelikleri çıkarılır ve öznitelik vektörü (gömme) olarak gösterilir. Sonra bu gömmeler bir fark hesaplama yöntemiyle karşılaştırılır; bu kosinüs, Öklid ya da başka bir ölçü olabilir. DeepEMD bu ölçü olarak Earth Mover's Distance'ı kullanır ve makalede bunun diğer yöntemlerden daha iyi sonuç verdiği gösterilmiştir.

Sezgisel olarak iki köpek resmini karşılaştırmak için resimler bloklara bölünebilir: bir blokta baş, birinde bacak, birinde kuyruk, birinde gövde olur. İki resmin bacağı bacakla, başı başla eşleştirilirse küresel bir fark ölçüsünden daha iyi bir karşılaştırma yapılır. Öznitelikler çıkarıldığında baş bir vektörde, bacak başka bir vektörde temsil edilir; EMD bu yerel vektörler arasındaki eşleştirmeyi uygun biçimde yapar.

### 2.4 Earth Mover's Distance

EMD iki dağılım arasındaki farkı ölçer: bir dağılımdan diğerine en az maliyetle geçmenin maliyetidir. Slayttaki çizimde kırmızı $g(x)$ ve mavi $f(x)$ eğrileri var; soru, bir eğriden diğerine en az hareketle nasıl geçileceğidir (ekrandan, 00:20:00).

Sunucunun benzetmesi şöyleydi: Edirne ile İstanbul arası mesafe sorulduğunda genelde iki şehir birer nokta sayılır ve koordinatlar çıkarılarak 200-300 km gibi bir cevap verilir. Oysa iki şehir de nokta değil, alana yayılmış birer dağılımdır. "İstanbul'daki bütün toprağı Edirne'ye en az maliyetle nasıl taşırım?" sorusunu cevaplamak için EMD kullanılır. Bu problem doğrusal programlama ile çözülür; makalede OpenCV'nin bir çözücüsü kullanılmış.

Slayttaki sayısal örnekte (ekrandan, 00:20:00) açık gri daireler gönderici, koyu gri daireler alıcı gibi düşünülür. Verilenler:

- Bir tarafta ağırlıklar $w_1 = 0.74$, $w_2 = 0.26$.
- Diğer tarafta ağırlıklar $u_1 = 0.23$, $u_2 = 0.51$; toplamı $0.74$, yani daha hafif dağılım budur.

En iyi olmayan akışta (non-optimal flow) $f_{21} = 0.23$ birim $d_{21} = 292.9$ uzaklığa, $f_{12} = 0.51$ birim $d_{12} = 252.3$ uzaklığa taşınır:

$$\text{İş}_1 = 0.23 \cdot 292.9 + 0.51 \cdot 252.3 = 67.37 + 128.67 \approx 196$$

En iyi akışta (optimal flow) $f_{22} = 0.26$ ($d_{22} = 198.2$), $f_{11} = 0.23$ ($d_{11} = 155.7$) ve $f_{12} = 0.25$ ($d_{12} = 252.3$) taşınır:

$$\text{İş}_2 = 0.26 \cdot 198.2 + 0.23 \cdot 155.7 + 0.25 \cdot 252.3 = 51.53 + 35.81 + 63.08 \approx 150.4$$

Toplam akış her iki durumda da hafif dağılımın ağırlığına, $0.74$'e eşittir. EMD en küçük işin toplam akışa bölümüdür:

$$\mathrm{EMD}(x, y) = \frac{150.4}{0.74} \approx 203.3$$

(Ara çarpımlar eklendi; sonuçlar python ile doğrulandı.)

Sunumda makaledeki EMD optimizasyon formülü de gösterildi ve bir maliyet ifadesinin en aza indirildiği anlatıldı. <!-- BELİRSİZ: makaledeki formül slaytı karelerde görülmedi -->

> **Ek bilgi (derste anlatılmadı):** EMD'nin genel biçimi şöyledir: $\min_{f_{ij} \ge 0} \sum_i \sum_j f_{ij} d_{ij}$; kısıtlar $\sum_j f_{ij} \le w_i$, $\sum_i f_{ij} \le u_j$ ve $\sum_i\sum_j f_{ij} = \min(\sum_i w_i, \sum_j u_j)$. Sonuç $\mathrm{EMD} = \sum f_{ij} d_{ij} / \sum f_{ij}$ olarak normalize edilir. DeepEMD'de $d_{ij}$, iki resmin yerel öznitelik vektörleri arasındaki maliyettir.

### 2.5 Çapraz referans mekanizması ve yapılandırılmış FC katmanı

**Çapraz referans (cross-reference) mekanizması** başarıyı artırmak için kullanılır. Resmin yerel öznitelik vektörü ortalama öznitelik vektörüyle karşılaştırılır. Yüksek varyanslı bir bölgeye az ağırlık verilir ve o bölgenin uzaklık hesabındaki etkisi azaltılır. Böylece yüksek varyanslı arka plan bölgeleri geri planda kalır; diğer resimlerde de bulunan köpeğin burnu, kuyruğu gibi ayırt edici bölgeler daha yüksek ağırlık alır. Sunumdaki ağırlık haritalarında etkili bölgeler açık, etkisiz bölgeler (örneğin arka plan) koyu görünüyor; kuş resminde de farkı belirleyen bölgeler renkle işaretlenmiş.

**Yapılandırılmış tam bağlantılı katman (Structured Fully Connected Layer):** Destek kümesinde yalnız bir resim olsaydı iki resmi doğrudan EMD ile karşılaştırmak yeterdi. Ama destek kümesinde iki, üç ya da daha fazla resim olabilir. Bu durumda her sınıf için bir yapı (bir tür ortalama) öğrenen bir katman oluşturulur. Test resmi her sınıfın bu yapısıyla EMD üzerinden karşılaştırılır ve en düşük EMD'ye sahip sınıfa atanır. Sıradan yaklaşımda ise bu karşılaştırma doğrudan iç çarpımla (dot product) yapılır.

### 2.6 Sonuçlar

5-way k-shot deneyini gösteren grafikte (ekrandan, 00:25:00) yatay eksen shot sayısı (0-50), dikey eksen doğruluktur. Karşılaştırılan yöntemler Prototype Learning, Cosine classifier, EMD+NN, EMD+Fusion ve EMD+SFC'dir. EMD+SFC (kırmızı) her noktada en üsttedir; yaklaşık %73'ten başlayıp 50 shot'ta %90'ın biraz üstüne çıkar. EMD+Fusion (mavi) 10 shot'tan sonra diğerlerinin altında kalır ve yaklaşık %82'de doyar.

Ayrıntılı tablolarda (ekrandan, 00:30:00) omurga, yani öznitelik çıkaran ve eğitilmeyen kısım, çoğu yöntem için ResNet-12'dir. DeepEMD'nin sonuçları:

| Veri seti | 1-shot | 5-shot |
|---|---|---|
| miniImageNet | $65.91 \pm 0.82$ | $82.41 \pm 0.56$ |
| tieredImageNet | $71.16 \pm 0.87$ | $86.03 \pm 0.58$ |
| Fewshot-CIFAR100 | $46.47 \pm 0.78$ | $63.22 \pm 0.71$ |
| Caltech-UCSD Birds-200-2011 | $75.65 \pm 0.83$ | $88.69 \pm 0.50$ |

DeepEMD dört veri setinin hepsinde karşılaştırılan yöntemlerden (cosine classifier, TADAM, ProtoNet, MatchNet, MetaOptNet, CTM vb.) daha iyi sonuç vermiş. Sunucu, güncel few-shot karşılaştırma listelerinde DeepEMD'yi göremediğini, bunun omurganın yalnız ResNet-12 olmasıyla ilgili olabileceğini düşündüğünü söyledi.

Makalede EMD, yapılandırılmış sınıflandırıcı ve çapraz referans ayrı ayrı test edilmiş; her biri başarımı artırıyor, üçü birlikte en yüksek başarımı veriyor. Hoca, bu veri setlerinin few-shot için oluşturulmuş alt kümeler olduğunu ve az sayıda görüntüyle eğitilen bir mimarinin ilginç bir konu olduğunu belirtti.

## 3. Kuş bakışı görüntülerden dinamik trafik modelleme

İkinci sunumun konusu CVPR konferansından "Dynamic Traffic Modeling from Overhead Imagery" makalesidir: kuş bakışı (uydu ya da havadan) görüntülerden şehirdeki ana yol ve bağlantı yollarında trafik hızının, akış yönünün ve yoğunluğunun bulunması, bunun şehir planlamasında kontrol ve modelleme için kullanılması.

### 3.1 Benzer çalışmalar

Çalışma üç konuyu birden ele alır: görüntüden yol tespiti, yol üzerindeki akış yönünün (tek ya da çift yönlü yollarda ileri/geri) tespiti ve trafik hızının tespiti. Bu yüzden farklı alanlardaki çalışmalardan esinlenmiştir.

- **Şehir görüntülerinin bölütleme ile analizi (ekrandan, 00:35:00):** Bir CNN modeliyle görüntüdeki yol, havalimanı, yeşil alan, fabrika, spor sahası gibi alanlar tespit edilmiş. Barselona, Madrid, Roma, Berlin, Budapeşte ve Atina görüntüleri kullanılmış. Şehirlerarası doğruluk matrisinde bir şehirde eğitilip aynı şehirde test edildiğinde doğruluk yüksektir (köşegen: Atina 0.83, Barselona 0.76, Berlin 0.72, Budapeşte 0.72, Madrid 0.68, Roma 0.68). Başka bir şehirde test edildiğinde doğruluk belirgin düşer (örneğin Roma'da eğitilip Budapeşte'de test: 0.23). Bütün şehirlerle eğitildiğinde doğruluk yaklaşık %50'de (0.47-0.53) kalır.
- **Yol özelliklerinden hız kestirimi:** Yalnız yollar tespit edilmiş; trafik akışı yerine yolun düz ya da virajlı olması, genişliği, şehir içi ya da ana yol olması gibi özelliklerden o yolda yapılabilecek ortalama hız bulunmaya çalışılmış. CNN'in yanında klasik görüntü işleme (maskeleme) de kullanılmış. <!-- BELİRSİZ: sonuç değerleri (%80, %64) altyazıda net değil, karede görülmedi -->
- **Optik akış ile hız kestirimi:** Bir pikselin belli bir sürede ne kadar hareket ettiği bulunursa $x = v t$ gibi basit bir bağıntıyla hız çıkarılır. Burada kritik olan optik akış algoritmasının etkili uygulanması ve aynı pikselin sonraki karelerde doğru izlenmesidir; piksel yanlış eşleştirilirse hız da yanlış bulunur.
- **En yakın çalışma:** Görüntü ve yol özellikleri ayrı ayrı işlenip sonra birleştirilmiş; ayrı ayrı kullanıldıklarında farklı oranlar alınırken birlikte kullanıldığında yaklaşık %49 elde edilmiş. <!-- BELİRSİZ: %49 değerinin hangi ölçü olduğu altyazıda net değil -->

### 3.2 Çalışmanın amacı

Slayttaki amaçlar (ekrandan, 00:40:00):

- Gün içinde trafik yoğunluğunu ve dolayısıyla hareket hızını tahmin eden bir model oluşturmak.
- Trafiğin gün içindeki farklı zamanlarda da modellenebilmesi.
- Yolların farklı bölgelerinde de işlevsel olabilmesi.
- Az ya da gürültülü bilginin olduğu bölgelerde de etkili çalışabilmesi.

Standart modellerde trafik yoğunluğunun zamana bağlı bir fonksiyonu bulunur; ama bu modeller az ya da gürültülü verili noktalarda yüksek hata verir ve şehrin tamamına genelleştirmede zayıf kalır.

### 3.3 Veri seti

Çalışmada New York şehrine ait veri kullanılmış. Ana kaynak Uber'dir; Uber bu veriyi kendi araçlarının optimizasyonu için kullanırken bir kısmını akademik araştırma için açık kaynak yapmış. Veride araçların GPS noktaları, hız, yön ve tarih-saat bilgisi var. GPS noktalarını yollarla eşleştirmek için açık bir harita kaynağı olan OpenStreetMap kullanılmış. Sunucuya göre sonuçta yaklaşık 292 milyon kayıtlı, 22 GB'lık bir veri kümesi oluşturulmuş (altyazıdan).

### 3.4 Mimari ve kayıp fonksiyonları

CNN tabanlı bir yapay sinir ağı kullanılmış; sunucuya göre temel CNN yapısı çok değişmediği için asıl farklar kayıp fonksiyonlarında. Ağ üç görevi birlikte öğrenir:

- **Yol tespiti:** Her pikselin yola ait olup olmadığı ikili sınıflandırma ile bulunur; sigmoid aktivasyon kullanılır. Görüntülerin bazılarındaki örtüşmeler (overlap) analiz edilip kayba katılmış.
- **Seyahat yönünün tespiti:** Ders içinde görülen HOG özniteliklerine benzer biçimde, her piksel için $K$ adet yön açısının olasılığı softmax ile çıkarılır. Olasılığı en yüksek açı, o pikseldeki akış yönü kabul edilir. Tahmin edilen ve gerçek olasılık dağılımı karşılaştırılarak kayba eklenir.
- **Trafik hızının tespiti:** Görüntülere ek olarak Uber'in konum ve zaman bilgileri girdi olarak verilir; softplus aktivasyon tercih edilmiş. Çift yönlü yollarda her yön için ayrı hız belirlenmesi gerekir, çünkü bir yön açıkken diğeri yavaş akabilir. Tek piksel yerine yol bölümleri hesaba katılarak bölgesel bir ortalama hız hesaplanır.

### 3.5 Sonuçlar

Tespit edilen hızlar ısı haritasıyla gösterilmiş; kavşak noktalarında trafiğin yoğunlaştığı görülüyor. Aynı bölgenin sabah ve öğlen görüntüleri karşılaştırıldığında sabah saatlerinin işe gidiş-geliş nedeniyle daha yoğun olduğu yorumlanmış.

Hız tahmini tablosunda (ekrandan, 00:45:00) yol ve yön görevlerinin kullanılıp kullanılmamasına göre sonuçlar:

| Yol | Yön | RMSE | MAE | $R^2$ |
|---|---|---|---|---|
| yok | yok | 10.87 | 8.35 | 0.442 |
| yok | var | 10.78 | 8.21 | 0.452 |
| var | yok | 10.73 | 8.19 | 0.456 |
| var | var | 10.66 | 8.10 | 0.464 |

Girdi karşılaştırma tablosunda yalnız görüntü, yalnız konum, zaman ve görüntü + konum + zaman birleşimleri denenmiş; zaman eklenince hızda biraz düşüş olsa da toplamda en iyi sonuç üçünün birlikte kullanıldığı durumda alınmış. <!-- BELİRSİZ: bu tablonun değerleri karelerde görülmedi -->

Yön sonuçlarında bir kavşak noktasında dört yönde de akış olabileceği için dört yöne de olasılık verilmiş; en yüksek olasılığın çıktığı yön, trafiğin o yönde daha hızlı ve yoğun aktığı şeklinde yorumlanmış.

Genelleştirme için günün 00.00-23.59 saatleri boyunca trafiğin yoğunlaştığı ve rahatladığı anlar çıkarılmış. Manhattan ve Brooklyn için ayrı haritalarda, sabah saatlerinde trafiğin şehrin geneline yayıldığı, öğlen ise yalnız merkezde kaldığı gösterilmiş.

Hoca, bu tür çalışmaların Türkiye'de, örneğin İstanbul için de yapılmasını çok istediğini, trafik izleme verilerinin araştırma amaçlı paylaşıldığını ve bunun bir imkân olduğunu söyledi.

## 4. Tek görüntüden derinlik kestirimi: Semantic Divide-and-Conquer Network

Üçüncü sunumun konusu "Semantic Divide-and-Conquer Network for Monocular Depth Estimation" makalesidir: tek bir görüntüden derinlik kestirimi. Sunucu, mobil robotların kendi konumunu bilmesi ve dünyayla etkileşime girmesinin önemli olduğunu, uzaklık sensörü gibi klasik sensörlerin bunun için yeterli olmadığını, GPU'lar geliştikçe robot üzerinde CNN gibi ağır işlemlerin yapılabildiğini ve bu yüzden kameradan derinlik kestiriminin önemli bir konu olduğunu anlattı.

### 4.1 Problemin zorluğu

Tek görüntüden derinlik algılamak teknik olarak kötü tanımlanmış (ill-posed) bir problemdir. Bir nesnenin görüntüdeki büyüklüğü bağlama göre çok değişir. İnsan birçok başka bilgiyi bildiği için nesneleri rahatça derinliğe yerleştirir; perspektif bilgisi varsa görüntüde aynı boyutta görünen iki kişinin gerçekte farklı uzaklıklarda olduğu anlaşılır. Biyolojik canlılarda ve standart robotik uygulamalarda iki kameradan gelen stereo görüntülerle derinlik, iki görüntünün farkından bulunabilir. Tek resimde ise derinlik bağlama çok bağlı olduğu için problem zordur.

### 4.2 İlgili çalışmalar

- **Olasılıksal yöntemler (CNN öncesi, yaklaşık 2010-2014; ekrandan, 00:55:00):** Markov Random Fields ile semantik etiketlerden derinlik (Liu, Gould ve Koller, 2010) ve Conditional Random Fields ile ayrık-sürekli derinlik kestirimi (Liu, Salzmann ve He, 2014). İlk yaklaşım pikselden değil, görüntünün "ev", "yer", "gökyüzü" gibi semantik olarak etiketlenmiş bölgelerinden derinlik çıkarır.
- **CNN tabanlı yöntemler (2014 sonrası):** Örneğin "Deeper Depth Prediction with Fully Convolutional Residual Networks" (2016). Bu çalışmada arada havuzlama katmanı olmadan yalnız evrişimlerle kestirim yapılır.
- **Gözetimsiz (aslında yarı gözetimli) yöntemler:** Hem görüntü hem derinlik içeren veri seti bulmak zordur. Stereo kameradan gelen iki görüntü arasındaki farkı öğrenen bir CNN eğitilir ve bu farktan derinlik bulunur.
- **Sentetik veri:** Bilgisayarla üretilmiş, derinliği bilinen üç boyutlu sahnelerle eğitim yapılır. Sorun, sentetik dünya ile gerçek dünya arasındaki tutarsızlıktır; bu yüzden GAN (Generative Adversarial Network) ile sentetik veride öğrenilen bilgi gerçek dünyaya aktarılmaya çalışılmış.

### 4.3 Nesne tanımada görevler (hatırlatma)

Sunucu, derste anlatılan nesne tanıma görevlerini kısaca hatırlattı:

- **Nesne tespiti:** Resimdeki nesneleri bulup sınırlayan kutularını belirlemek.
- **Örnek bölütleme (instance segmentation):** Her nesne örneğinin pikselleriyle ayrı ayrı belirlenmesi ve sınırlayıcı kutular.
- **Anlamsal bölütleme (semantic segmentation):** Farklı örnekler aynı semantik kategorinin parçası olarak gösterilir; örneğin resimdeki bütün kediler tek bir kategori olarak işaretlenir.
- **Panoptik bölütleme:** Örnek ve anlamsal bölütlemenin birlikte kullanılması. Bu çalışma da panoptik bölütlemeden yararlanır.

### 4.4 Modelin fikri ve dört bileşeni

Adı "böl ve yönet"ten gelir: görüntü hem örneklere hem semantik kategorilere göre bölütlenir ve her parça için derinlik ayrı hesaplanır. Varsayım şudur: farklı kategorilerin ve farklı nesnelerin derinliği çok farklı değişebilir, ama aynı türden nesnelerin derinlik değişimi birbirine yakındır. Örneğin gökyüzünün derinlik değişimi bir insanınkiyle aynı olmaz.

Model dört parçadan oluşur (ekrandan, 01:00:00):

1. **Omurga ağı (Backbone Network):** Feature Pyramid Network; resmin özniteliklerini çıkaran CNN yapısı.
2. **Bölütleme modülü:** Anlamsal bölütleme (kategori düzeyi) ve örnek bölütleme (örnek düzeyi).
3. **Derinlik kestirimi:** Her kategori (Category #1 ... #C) ve her örnek (Instance #1 ... #N) için derinlik; her biri $[0,1]$ aralığına normalize edilmiş olarak kestirilir.
4. **Derinlik birleştirme (aggregation):** Kategori ve örnek derinlik haritaları birleştirilerek son derinlik haritası elde edilir.

### 4.5 Omurga: ResNet-50 ve Feature Pyramid Network

Öznitelik çıkaran CNN olarak 50 katmanlı bir residual network kullanılmış; bunun üzerine Feature Pyramid Network (FPN) kurulmuş. Normal bir CNN'de evrişimler ilerledikçe resim küçülür: anlamca zengin ama çözünürlüğü düşük bir temsil oluşur. FPN her katmanın çıkışını birleştirir: daha derin ve küçük katman büyütülüp bir alttaki katmanla aynı boyuta getirilir, alttaki katman $1\times1$ evrişimden geçirilip bununla toplanır, ardından bir evrişim daha uygulanıp bir alt seviyeye aktarılır. Bütün seviyelerin çıkışları kestirim için öznitelik olarak kullanılır. Bunların yükseklik ve genişliği resme göre değişir, derinliği (kanal sayısı) 256 seçilmiş. FPN doğrudan sonucu üretmez; üzerine kurulacak ek ağlar için öznitelik sağlar.

### 4.6 Kategori ve örnek bazında derinlik

Kategori kolunda **yerel dal (local branch)** FPN'den gelen öznitelikleri alıp her semantik kategori için $[0,1]$ aralığında bir derinlik ("kanonik derinlik") kestirir. Aynı öznitelikler **küresel ortalama havuzlama (GAP)** ile özetlenip tam bağlantılı katmanlardan geçirilir ve bir dönüşüm hesaplanır. Bu dönüşüm, kategori için bulunan $[0,1]$ derinliğini resmin bütünündeki gerçek derinlik ölçeğine çevirir. Dönüşüm standart bir afin işlemdir: $w_c$ katsayısıyla ölçeklenip kategoriye özgü $b_c$ kaymasıyla ötelenir.

Örnek kolunda da benzer işlem her örnek için yapılır (ekrandan, 01:05:00). Mask R-CNN ile her örnek için $[0,1]$ aralığında derinlik haritası çıkarılır (araba 1, araba 2, insan 1, insan 2 gibi). İkinci dal (decoding branch), Mask R-CNN'deki RoIAlign yapısıyla öznitelik alıp tam bağlantılı katmanlarla dönüşüm katsayılarını bulur. Slaytta örnek öznitelik haritası $\tilde{F}^i$, boyutu $H \times W \times Z$ olarak gösteriliyor. Sunucuya göre dönüşüm $g(C(\cdot))$ biçimindedir: $C$ birebir ($1\times1$) bir evrişimdir ve çıkışı resimle aynı boyutta, 32 kanallı bir öznitelik verir; $g$ ise yine $w \cdot D + b$ biçiminde bir afin dönüşümdür. Böylece giriş görüntüsüyle aynı boyutta örnek bazlı derinlik haritaları elde edilir. Makalede yerel dallardaki CNN'lerin ayrıntılarının ek belgelerde olduğu söylenmiş; ama ek belgeler ve kod paylaşılmadığı için katman sayısı gibi ayrıntılar bilinmiyor.

### 4.7 Derinlik birleştirme

Elde iki tür harita vardır: kategorilere göre (örneğin bütün arabalar için) ve örneklere göre (tek tek arabalar için) $[0,1]$ derinlikler. Birleştirme şöyle anlatıldı: her kategoriye ait örneğin haritası, örneğin resimde nerede olduğunu gösteren maske matrisi $S$ ile çarpılır (çünkü örnek haritası bütün resmi kapsar, maske o örneğe ait kısmı seçer) ve örneğin o kategoriye ait olma olasılığı $p$ ile ağırlıklanır. Bu, kategorinin derinlik haritası $D$ ile toplanır. Farklı kategorilerin derinlik ölçekleri farklı olduğu için bir normalizasyon matrisi $M$ hesaplanır ve her kategorinin toplamı buna bölünür. Son olarak kategoriler, ait olma olasılıklarıyla birleştirilerek son derinlik haritası bulunur. <!-- BELİRSİZ: birleştirme formüllerinin tam biçimi karelerde görülmedi -->

### 4.8 Kayıp fonksiyonu

Sistem uçtan uca tek seferde eğitilir; üç kayıp birleştirilir (ekrandan, 01:10:00):

$$L = \alpha_I L_I + \alpha_S L_S + \alpha_D L_D$$

$L_I$ örnek bölütleme, $L_S$ anlamsal bölütleme, $L_D$ derinlik kaybıdır.

Örnek kaybı iki parçalıdır:

$$L_I(p, u, t^u, v) = L_{class}(p, u) + \lambda [u \ge 1] L_{loc}$$

Sınıf kaybı logaritmik kayıptır:

$$L_{class}(p, u) = -\log(p_u) = -[u \log(p) + (1 - u)\log(1 - p)]$$

Konum kaybı sınırlayıcı kutunun regresyonudur; kutunun merkezinin $x$ ve $y$ piksel indisi ile yüksekliği ve genişliği olmak üzere dört parametre tahmin edilir:

$$L_{loc}(t^u, v) = \sum_{i \in \{x, y, w, h\}} \mathrm{smooth}_{L_1}(t_i^u - v_i)$$

$$\mathrm{smooth}_{L_1}(x) = \begin{cases} 0.5x^2 & |x| < 1 \\ |x| - 0.5 & \text{diğer} \end{cases}$$

Anlamsal kayıp her piksel için kategori sayısına göre hesaplanır. Örneğin 21 sınıf varsa çıkışın yüksekliği ve genişliği giriş görüntüsüyle aynı, derinliği 21'dir; her pikselde en büyük değeri veren kanal o pikselin sınıfıdır. Burada da logaritmik kayıp kullanılır. Derinlik kaybı doğrudan tahmin ile gerçek değer arasındaki farka bakar. Sunucu, $\alpha_I, \alpha_S, \alpha_D$ katsayılarının eşit (her biri yaklaşık 0.33) seçilebileceğini, makalenin bunların seçimini ek belgelere bıraktığını söyledi.

> **Ek bilgi (derste anlatılmadı):** smooth L1 kaybı, küçük hatalarda L2 gibi karesel (türevi sıfıra yaklaşan, kararlı), büyük hatalarda L1 gibi doğrusal davranır; bu yüzden aykırı kutulara karşı L2'den daha dayanıklıdır. Örneğin $x = 0.5$ için $0.125$, $x = 2$ için $1.5$ verir. $[u \ge 1]$ göstergesi, arka plan sınıfı ($u = 0$) için konum kaybının hesaplanmadığını belirtir.

### 4.9 Değerlendirme ve veri setleri

Sonuçlar üç ölçütle karşılaştırılmış. RMSE (Root Mean Squared Error), tahmin ile gerçek değer farkının karesinin örnek sayısına bölünüp karekökünün alınmasıdır. Bir ölçütte tahminlerin ortalaması ($\bar{\theta}$) da çıkarılıyor. Squared relative error ise mutlak fark yerine farkın karesine bakar. <!-- BELİRSİZ: ölçüt formülleri karede görülmedi; ortalamanın çıkarıldığı ölçütün tam adı net değil -->

- **Cityscapes:** 50 farklı şehirden sokak görüntüleri, toplam 25 000 resim. Bunların 5000'i piksel düzeyinde ayrıntılı (her pikselin sınıfı, derinlik ve örnekler) notlanmış, 20 000'i kabaca notlanmış. Bu çalışma en iyi sonucu almış; benzer biçimde semantik kategorilerden yararlanan ama örnekleri kullanmayan önceki bir çalışmadan daha iyidir. Bu, örnek bilgisinin derinliğe ek katkı sağladığını gösteriyor. Görsel karşılaştırmada üstte gerçek resimler, altında gerçek derinlik haritaları ve en altta tahminler var.
- **Depth in the Wild (ekrandan, 01:15:00):** 495 000 görüntü; piksel piksel derinlik yok, yalnız görüntüdeki iki noktadan hangisinin görece daha yakın olduğu notlanmış (göreli notlandırma). Noktalar rastgele seçilseydi alttaki noktayı daha yakın saymak zaten yaklaşık %90 doğru olurdu; ufka paralel simetrik iki nokta seçildiğinde de merkeze yakın olan daha yakın olur. Bu yüzden noktalar sınırsız (unconstrained), simetrik (symmetric) ve ayırt etmesi zor (hard-to-tell) çiftler olarak seçilmiş. Göreli notlar örnek ve kategori bilgisi içermediği için semantik bölütleme için COCO (Common Objects in Context) kullanılmış. Ölçüt WHDR (Weighted Human Disagreement Rate) olup hata yaklaşık %11'dir.
- **NYU Depth:** İç mekan veri seti; yaklaşık 1500 resimde derinlik, kategoriler ve örnekler ayrı ayrı notlanmış; yemek odası, yatak odası, çalışma odası gibi 26 farklı mekan türü var. Derinlik bilgisi derinlik algılayıcılı kameradan geliyor.

**Ablation çalışması:** Modelin parçaları tek tek çıkarılarak her parçanın sonuca etkisi ölçülmüş. Dört model denenmiş: A yalnız derinlik verisiyle (kategori ve örnek yok), B kategorilerle, C kategori ve örneklerle, D tam yöntem. Ne kadar çok modül eklenirse sonuç o kadar iyileşmiş; bu, eklenen parçaların gerçekten katkı sağladığını gösteriyor. <!-- BELİRSİZ: C ve D modellerinin farkı altyazıda net değil -->

> **Ek bilgi (derste anlatılmadı):** NYU Depth v2 veri setinde etiketli görüntü sayısı büyük olasılıkla 1449'dur ve derinlik Kinect benzeri bir RGB-D algılayıcıdan gelir; sunucunun "stereo kamera" ve "1500" ifadeleri bu bakımdan yaklaşık değerlerdir. Cityscapes'te de değerlendirmede genelde 19 sınıf kullanılır; "21 sınıf" örneği büyük olasılıkla PASCAL VOC'un 21 sınıfından gelen genel bir örnektir.

### 4.10 Sunucunun kendi denemesi

Sunucu makalenin yöntemini birebir değil, sadeleştirilmiş bir biçimde denedi (ekrandan, 01:20:00). NYU Depth verisi ve ImageNet üzerinde önceden eğitilmiş, doğrudan çağrılabilen ResNet50 kullanıldı. FPN'e benzer bir kod çözücü kuruldu:

```text
Girdi 640x480
ResNet50: Convolution Block 1 -> 2 -> 3 -> 4 -> 5
Block 2 çıkışı -> Upsample -> Conv --+
Block 3 çıkışı ----------------------+-> (+) -> Upsample -> Conv --+
Block 4 çıkışı ----------------------------------------------------+-> (+) -> Upsample -> Conv --+
Block 5 çıkışı ----------------------------------------------------------------------------------+-> (+) -> Conv Transposed
```

Slaytta el yazısıyla $640\times480$, $320\times240$ ve $160\times120$ boyutları işaretlenmiş. Sunucu, çizimi ters hazırladığını da belirtti: aslında daha derin bloktan gelen öznitelik doğrusal interpolasyonla büyütülüp $1\times1$ evrişimle bir önceki blokla aynı filtre sayısına getiriliyor ve toplanıyor; bu tekrar tekrar daha derin katmanlarla yapılıyor ve sonunda çıkış $640\times480$ olacak şekilde eğitiliyor. ResNet50'nin 5. blok çıkışı $20\times15$'tir ($640/32 = 20$, $480/32 = 15$).

> **Ders sonrası not:** Keras'taki ResNet50'de çıkış adımı (stride) bloklara göre 2, 4, 8, 16, 32'dir; $640\times480$ girişte blok çıkışları büyük olasılıkla sırasıyla $320\times240$, $160\times120$, $80\times60$, $40\times30$ ve $20\times15$'tir. Slayttaki $320\times240$ ve $160\times120$ etiketleri bu yüzden büyük olasılıkla blok 2 ve 3'ün çıkışlarını değil, onlara giren boyutları gösteriyor.

Son blok çıkışından tam çözünürlüğe ulaşmak için bir iki kez daha büyütme gerekiyordu; bunun için Keras'taki **transpoze evrişim (convolution transpose)** kullanıldı. Slayttaki şekilde (Dumoulin ve Visin, "A Guide to Convolution Arithmetic for Deep Learning") $2\times2$'lik bir giriş dolgu (padding) ile genişletilip üzerinde $3\times3$'lük çekirdek gezdirilerek $4\times4$'lük bir çıkış elde ediliyor. Adım 1 için çıkış boyutu $(2 - 1)\cdot 1 + 3 = 4$'tür (ara adım eklendi, python ile doğrulandı).

Eğitim ayrıntıları: ResNet50'nin yaklaşık 23 milyon parametresi var, eklenen yapı yaklaşık 3 milyon parametreli. Veri dört resimlik yığınlarla (batch), her yığında bir güncelleme olacak şekilde, 20 epok eğitildi; eğitim yaklaşık 80 dakika sürdü. Model doğrudan derinlik bulacak şekilde eğitildi ve MSE, MAE ve RMSE ile değerlendirildi. Eğitim kaybı düşmeye devam ederken doğrulama kaybı 5. ya da 6. epoktan sonra pek değişmediği için orada durulabileceği görüldü.

Sonuç görsellerinde (ekrandan, 01:25:00) solda gerçek resim, ortada gerçek derinlik, sağda tahmin var. Üst satır FPN yapısı olmadan ilk denenen modeldir: transpoze evrişim düşük çözünürlükten yükseğe çıkarken başarısız olmuş; resim $640\times480$ olmasına rağmen tahmin yaklaşık $20\times15$ piksellik bloklu bir çözünürlükte kalmış. Katmanlarla oynanınca alt satırdaki daha yumuşak sonuç alınmış, ama gerçek derinlikten hâlâ uzak. Makaledeki model yaklaşık 50 milyon parametrelidir; bu kadar büyük bir modeli eğitmek güçlü bir GPU ve uzun süre ister.

Hoca, uygulama yapılmasının ayrıca güzel olduğunu belirtti ve şunu vurguladı:

> **Hocanın vurgusu:** Tek kamerayla derinlik bulmak gerçekten zor bir problemdir. Bu tür çalışmalarda genelde stereo kamera kullanılır; stereo görmenin de kendine göre zorlukları vardır. Tek kamerayla derinlik bulma ayrı bir araştırma alanıdır.

## Örnek Sorular

**Soru 1** (derste sözlü, 00:15:50): Bu makale few-shot sınıflandırmanın dört yaklaşımından hangisini kullanıyor?

> **Cevap (derste verildi):** Matching Network'e yakındır, çünkü resimlerin farkına (EMD ile) bakar. Ama destek kümesinde birden çok resim olduğunda bunların ortak bir yapısını çıkardığı için prototip yaklaşımına da yakındır.

**Soru 2** (derste sözlü, 00:26:51; ekrandan, 00:25:00): 5-way k-shot grafiğinde en üstteki kırmızı eğri EMD+SFC iken, mavi EMD+Fusion eğrisi neden diğerlerinin altında kalıyor?

> **Cevap (derste verildi, kısmen):** Sunucu, grafiği makaleden değil projenin GitHub sayfasından aldığını, bunun DeepEMD'nin ikinci sürümüne ait olabileceğini söyledi; kesin bir açıklama verilmedi. Makalede EMD, yapılandırılmış sınıflandırıcı ve çapraz referans ayrı ayrı denenmiş, üçü birlikte en yüksek sonucu vermiştir.

**Soru 3** (derste sözlü, 00:28:37; ekrandan, 00:30:00): miniImageNet'te 1-shot başarı yaklaşık %66 iken CIFAR-100 tablosunda yaklaşık %46. Bu fark, CIFAR-100'de 100 sınıf ayrıldığı için mi?

> **Cevap (derste verildi):** Hoca ve sunucu bunun sınıf sayısından kaynaklanabileceğini düşündü; sunucu few-shot görevlerinde genelde 5 sınıf (5-way) kullanıldığını belirtti.

> **Ders sonrası not:** Tablonun başlığı "Fewshot-CIFAR100" (FC100) ve grafik başlığı "5-way k-shot" olduğundan bu sonuçlar da büyük olasılıkla 5-way'dir. Düşük başarı büyük olasılıkla 100 sınıfın ayrılmasından değil, FC100'ün $32\times32$ gibi düşük çözünürlüklü görüntülerden oluşması ve eğitim/test sınıflarının farklı üst sınıflardan seçilmesiyle daha zor bir veri seti olmasından kaynaklanır.

**Soru 4** (derste sözlü, 00:30:09): "Birds" veri setinde 200 sınıf mı var?

> **Cevap (derste verildi):** Sunucu daha az sınıf olduğunu düşündü, çünkü 1-shot başarısı %75 civarında yüksek çıkmıştı.

> **Ders sonrası not:** Tablodaki ad "Caltech-UCSD Birds-200-2011"dir (ekrandan, 00:30:00); veri setinde 200 kuş türü vardır. Few-shot değerlendirmede bu türler eğitim/doğrulama/test olarak bölünür ve her görevde büyük olasılıkla yine 5 sınıf (5-way) ayrılır; yüksek başarı bu yüzden 200 sınıfla çelişmez.

**Soru 5** (derste sözlü, 00:46:22; ekrandan, 00:45:00): Hız tahmininde en alttaki RMSE 10.66 değeri ne anlama geliyor; yüzde mi, km/sa mi? Örneğin araç saatte 100 km gidiyorsa %10 hata mı demek?

> **Cevap (derste verildi):** Hoca, RMSE ortalama karesel hatanın karekökü olduğu için yüzde olmadığını, tahmin edilen büyüklükle aynı birimde olduğunu, yani ortalama akış hızında yaklaşık 10 km/sa sapma anlamına geldiğini söyledi. Sunucu da hızın km/sa olarak tahmin edildiğini belirtti. Bu, şehir içi trafik için yüksek bir hatadır.

> **Ders sonrası not:** Makalede hızların birimi büyük olasılıkla km/sa'dir; sunucu bundan emin olmadığını belirtti.

## Dersin Toparlaması

Bu son derste üç proje sunumu, dönem boyunca görülen konuların güncel araştırmalarda nasıl kullanıldığını gösterdi. DeepEMD, önceden eğitilmiş bir CNN'in yerel özniteliklerini Earth Mover's Distance ile eşleştirerek birkaç örnekle yeni sınıfları tanıyor; çapraz referans ağırlıkları arka planın etkisini azaltıyor. Trafik modelleme çalışması, kuş bakışı görüntüyü konum ve zaman bilgisiyle birleştirerek yol, akış yönü ve hızı birlikte öğrenen çok görevli bir CNN kuruyor. SDC-Depth ise anlamsal ve örnek bölütlemeyi derinlik kestirimiyle birleştiriyor: her kategori ve örnek için normalize derinlik bulup bunları ölçek-kayma dönüşümleriyle tek bir derinlik haritasında topluyor.

Sunumlarda tekrar eden fikirler derste görülen konulardır: öznitelik çıkaran CNN omurgaları ve transfer öğrenme, softmax/sigmoid çıkışlar ve logaritmik kayıp, bölütleme ve nesne tespiti, HOG benzeri yön histogramları, optik akış ve stereo görme. Hocanın son vurgusu, tek kamerayla derinlik bulmanın stereo görmeye göre çok daha zor olduğudur.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
