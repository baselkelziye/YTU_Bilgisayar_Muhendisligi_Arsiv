# Veri Madenciliğine Giriş Ders Kayıtları & Çalışma Özetleri

> **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi daha verimli çalışabilirsiniz.

### Genel Bilgiler

* **Ders:** Veri Madenciliğine Giriş
* **Hoca:** Songül Varlı
* **Dönem:** Bahar
* **Akademik Yıl:** 2020-2021

Bu dizin, ilgili ders kayıtlarının altyazı özetlerini, çalışma notlarını ve PDF kaynaklarını içermektedir.

## Ders Müfredatı ve Belge Dizini

Aşağıdaki tabloda her bir dersin konusu, kaynak markdown dosyası ve doğrudan indirilebilir PDF formatındaki derlenmiş halleri listelenmiştir.

| Ders No | Ders İçeriği / Konu Başlıkları | Kaynak Notlar (Markdown) | Çalışma Dosyası (PDF) |
| :---: | :--- | :---: | :---: |
| **Ders 1** | Veri madenciliğine genel bakış | [Özet](altyazi_ozetleri/ders_1_ozet.md) | [PDF (İndir)](ders_1_ozet.pdf) |
| **Ders 2** | Veri ön işleme | [Özet](altyazi_ozetleri/ders_2_ozet.md) | [PDF (İndir)](ders_2_ozet.pdf) |
| **Ders 3** | Veri indirgeme | [Özet](altyazi_ozetleri/ders_3_ozet.md) | [PDF (İndir)](ders_3_ozet.pdf) |
| **Ders 4** | Temel bileşen analizi | [Özet](altyazi_ozetleri/ders_4_ozet.md) | [PDF (İndir)](ders_4_ozet.pdf) |
| **Ders 5** | Karar ağaçlarıyla sınıflama | [Özet](altyazi_ozetleri/ders_5_ozet.md) | [PDF (İndir)](ders_5_ozet.pdf) |
| **Ders 6** | Naive Bayes sınıflayıcı | [Özet](altyazi_ozetleri/ders_6_ozet.md) | [PDF (İndir)](ders_6_ozet.pdf) |
| **Ders 9** | Dengesiz sınıf problemi | [Özet](altyazi_ozetleri/ders_9_ozet.md) | [PDF (İndir)](ders_9_ozet.pdf) |
| **Ders 11** | Eğiticisiz öğrenme ve kümeleme | [Özet](altyazi_ozetleri/ders_11_ozet.md) | [PDF (İndir)](ders_11_ozet.pdf) |
| **Ders 12** | Hiyerarşik kümeleme | [Özet](altyazi_ozetleri/ders_12_ozet.md) | [PDF (İndir)](ders_12_ozet.pdf) |
| **Ders 13** | Birliktelik kuralları | [Özet](altyazi_ozetleri/ders_13_ozet.md) | [PDF (İndir)](ders_13_ozet.pdf) |
| **Ders 14** | Birliktelik kuralları devamı | [Özet](altyazi_ozetleri/ders_14_ozet.md) | [PDF (İndir)](ders_14_ozet.pdf) |

## Derslerin Detaylı Özetleri ve Kazanımları

### Ders 1: Veri madenciliğine genel bakış

#### Genel Konular

- Veri madenciliğine genel bakış
  - Veri madenciliği, büyük veri yığınları içinden anlamlı örüntü, ilişki ve karar destek bilgisi çıkarma süreci olarak ele alınır.
  - Amaç, ham veriyi doğrudan saklamak değil, veriden yorumlanabilir ve kullanılabilir bilgi üretmektir.
- Veri, bilgi ve örüntü ilişkisi
  - Veri tek başına çoğu zaman anlam taşımaz; anlamlı hale gelmesi için temizleme, düzenleme, dönüştürme ve modelleme süreçlerinden geçmesi gerekir.
  - Örüntüler, veri içinde tekrar eden ilişkiler veya davranış biçimleri olarak düşünülür.
- Veri madenciliği problemlerinin ana türleri
  - Sınıflama, kümeleme, birliktelik kuralları ve tahminleme gibi temel problem başlıkları tanıtılır.
  - Sınıflama etiketli veriye, kümeleme ise etiketsiz veride benzerlik temelli gruplamaya dayanır.

#### Hocanın Özellikle Vurguladığı Kısımlar

- Veri madenciliğinin amacı
  - Asıl hedef veri toplamak değil, veriden karar vermeyi destekleyen bilgi çıkarmaktır.
- Problem türünü doğru belirleme
  - Kullanılacak yöntem, eldeki verinin etiketli olup olmamasına ve hedef çıktının türüne göre seçilmelidir.

#### Detaylı Açıklamalar

- Derste veri madenciliği, veri tabanlarında veya büyük veri kaynaklarında saklanan bilgilerin sistematik biçimde analiz edilmesi olarak konumlandırılır. Bu süreçte veri önce anlaşılır, sonra uygun biçime dönüştürülür ve ardından uygun algoritmalarla modellenir.
- Veri madenciliği yöntemleri, eldeki problemin yapısına göre ayrılır. Eğer geçmiş örneklerin sınıf etiketleri biliniyorsa sınıflama yapılabilir. Etiket yoksa örnekler benzerliklerine göre kümelenebilir. Birliktelik analizi ise özellikle hangi öğelerin birlikte görülme eğiliminde olduğunu bulmak için kullanılır.
- Bu giriş dersi, sonraki haftalarda işlenecek ön işleme, boyut indirgeme, sınıflama, kümeleme ve birliktelik kuralları konularının kavramsal temelini oluşturur.
### Ders 2: Veri ön işleme

#### Genel Konular

- Veri ön işleme
  - Veri madenciliğinde model başarısı, çoğu zaman kullanılan algoritmadan önce verinin kalitesine bağlıdır.
  - Eksik, hatalı, gürültülü veya ölçekleri farklı veriler modelin yanlış öğrenmesine neden olabilir.
- Veri temizleme ve dönüştürme
  - Eksik değerlerin ele alınması, aykırı değerlerin değerlendirilmesi ve tutarsız kayıtların düzeltilmesi temel ön işleme adımlarıdır.
  - Sayısal özelliklerin karşılaştırılabilir hale gelmesi için normalizasyon ve ölçekleme kullanılır.
- Aykırı değer kavramı
  - Aykırı değerler, genel dağılımdan belirgin biçimde sapan gözlemlerdir.
  - Her aykırı değer hata değildir; bazı problemlerde en kritik bilgi aykırı gözlemlerde bulunabilir.

#### Hocanın Özellikle Vurguladığı Kısımlar

- Ön işlemenin modelleme öncesi zorunlu oluşu
  - Kalitesiz veriyle kurulan model, algoritma güçlü olsa bile güvenilir sonuç üretmez.
- Aykırı değerlerin doğrudan silinmemesi
  - Aykırı gözlemin hata mı yoksa problem için anlamlı bir durum mu olduğu bağlama göre değerlendirilmelidir.

#### Detaylı Açıklamalar

- Derste veri ön işlemenin, ham veriyi algoritmaların kullanabileceği tutarlı bir forma dönüştürdüğü anlatılır. Gerçek veri kümeleri çoğunlukla eksik, hatalı veya farklı biçimlerde tutulmuş değerler içerir. Bu nedenle doğrudan algoritmaya verilen veri yanıltıcı sonuçlar doğurabilir.
- Normalizasyon, özellikle uzaklık temelli yöntemlerde önemlidir. Bir öz niteliğin değer aralığı diğerlerinden çok büyükse, uzaklık hesabını baskılayabilir. Bu durumda algoritma gerçekte daha önemli olan özellikleri görmezden gelebilir.
- Aykırı değerler hem hata kaynağı hem de bilgi kaynağı olabilir. Örneğin ölçüm hatası olan bir değer temizlenebilir; fakat dolandırıcılık, saldırı tespiti veya arıza analizi gibi problemlerde aykırı değerler asıl ilgilenilen sınıfı temsil edebilir.
### Ders 3: Veri indirgeme

#### Genel Konular

- Veri indirgeme
  - Veri indirgeme, veri kümesinin temsil gücünü koruyarak daha küçük veya daha yönetilebilir bir biçime dönüştürülmesidir.
  - Amaç işlem maliyetini azaltmak, gereksiz bilgiyi temizlemek ve modelin genelleme başarısını artırmaktır.
- Öz nitelik seçimi ve öz nitelik çıkarımı
  - Öz nitelik seçimi, mevcut değişkenler arasından en anlamlı olanları tutar.
  - Öz nitelik çıkarımı, mevcut değişkenlerden yeni ve daha temsil edici değişkenler üretir.
- Aykırı değer ve veri kalitesi ilişkisi
  - Aykırı değerlerin veri indirgeme ve modelleme üzerindeki etkisi tartışılır.
  - Aykırı değer analizi, veri setinin yapısını anlamanın parçası olarak değerlendirilir.

#### Hocanın Özellikle Vurguladığı Kısımlar

- Boyut azaltmanın sadece hız kazandırmaması
  - Gereksiz veya zayıf değişkenlerin çıkarılması modelin daha anlaşılır ve daha sağlam hale gelmesini sağlar.
- Öz niteliklerin etkisinin ayrı ayrı değerlendirilmesi
  - Her değişkenin modele katkısı aynı değildir; ilgisiz değişkenler gürültü oluşturabilir.

#### Detaylı Açıklamalar

- Derste veri indirgeme, veri madenciliği süreçlerinde hem performans hem de yorumlanabilirlik açısından önemli bir adım olarak ele alınır. Çok sayıda öz nitelik olduğunda algoritmalar daha yavaş çalışabilir, gereksiz değişkenler karar sınırlarını bozabilir ve modelin öğrenmesi zorlaşabilir.
- Öz nitelik seçimi ile öz nitelik çıkarımı arasındaki fark önemlidir. Seçim yöntemlerinde mevcut kolonlardan bazıları korunur; çıkarım yöntemlerinde ise veriyi daha iyi temsil eden yeni eksenler veya bileşenler elde edilir. Bu ayrım, PCA gibi yöntemlere geçiş için temel oluşturur.
- Aykırı değerler veri indirgeme sırasında dikkatli ele alınmalıdır. Nadir ama anlamlı davranışları temsil eden gözlemler yanlışlıkla çıkarılırsa model problem için kritik bilgiyi kaybedebilir.
### Ders 4: Temel bileşen analizi

#### Genel Konular

- Temel bileşen analizi
  - PCA, çok boyutlu veriyi daha az sayıda yeni eksene yansıtarak boyut azaltma yapan bir yöntemdir.
  - Yeni eksenler, verideki varyansı en iyi temsil edecek şekilde oluşturulan temel bileşenlerdir.
- Öz nitelik çıkarımı
  - PCA mevcut öz nitelikleri doğrudan seçmez; bunların doğrusal bileşimlerinden yeni bileşenler üretir.
  - Bu nedenle feature composition veya feature extraction yaklaşımıdır.
- Varyans ve bileşen seçimi
  - İlk temel bileşen en yüksek varyansı, sonraki bileşenler kalan varyansı açıklayacak şekilde sıralanır.
  - Kaç bileşen kullanılacağı, açıklanan toplam varyans oranına göre belirlenir.

#### Hocanın Özellikle Vurguladığı Kısımlar

- PCA'nın öz nitelik seçimi değil öz nitelik üretimi olduğu
  - Yöntem eski değişkenleri atıp bazılarını tutmaz; yeni koordinat sistemi üretir.
- Bileşen sayısına dikkat edilmesi
  - Çok az bileşen bilgi kaybına, çok fazla bileşen ise indirgeme amacının zayıflamasına yol açar.

#### Detaylı Açıklamalar

- Derste PCA'nın amacı, yüksek boyutlu veri kümesini daha az boyutlu ama temsil gücü yüksek bir uzaya taşımak olarak açıklanır. Bu yöntem özellikle birbirleriyle ilişkili öz niteliklerin bulunduğu veri kümelerinde işe yarar.
- PCA'da veri yeni eksenlere projekte edilir. Bu eksenler birbirine diktir ve her biri verideki farklı bir varyans yönünü temsil eder. İlk bileşen en fazla varyansı taşıdığı için en bilgilendirici eksen kabul edilir.
- PCA sonucunda elde edilen bileşenler modelleme öncesinde kullanılabilir. Böylece gürültü azalabilir, işlem maliyeti düşebilir ve görselleştirme kolaylaşabilir. Ancak bileşenler orijinal değişkenler kadar doğrudan yorumlanabilir olmayabilir.
### Ders 5: Karar ağaçlarıyla sınıflama

#### Genel Konular

- Karar ağaçlarıyla sınıflama
  - Karar ağaçları, veri kümesini öz niteliklere göre dallandırarak sınıf etiketi tahmini yapan denetimli öğrenme yöntemleridir.
  - İç düğümler test koşullarını, dallar koşul sonuçlarını, yapraklar sınıf kararlarını temsil eder.
- Bölme ölçütleri
  - Ağaç oluşturulurken hangi öz niteliğin düğümde kullanılacağı bilgi kazancı, entropi veya benzeri saflık ölçütleriyle belirlenir.
  - Amaç, alt düğümlerde sınıfların mümkün olduğunca saf hale gelmesidir.
- Aşırı öğrenme
  - Ağaç çok fazla detaylandırılırsa eğitim verisini ezberleyebilir.
  - Bu durumda eğitim başarısı yüksek, yeni veride başarı düşük olur.

#### Hocanın Özellikle Vurguladığı Kısımlar

- Kök düğüm seçiminin önemi
  - İlk bölme tüm ağacın yapısını etkilediği için uygun ölçütle seçilmelidir.
- Overfitting riski
  - Karar ağacı gereğinden derinleşirse genelleme gücünü kaybedebilir.

#### Detaylı Açıklamalar

- Derste karar ağacı, anlaşılabilirliği yüksek bir sınıflama yöntemi olarak ele alınır. Model, veriyi adım adım parçalara ayırır ve her dalda daha homojen sınıf dağılımı elde etmeye çalışır.
- Entropi, bir düğümdeki belirsizliği ifade eder. Bilgi kazancı ise bir öz nitelikle bölme yapıldığında belirsizliğin ne kadar azaldığını gösterir. Yüksek bilgi kazancı sağlayan öz nitelik, düğüm seçimi için güçlü adaydır.
- Karar ağacı yorumlanabilir olduğu için avantajlıdır; ancak küçük değişikliklere duyarlı olabilir ve fazla büyüdüğünde eğitim verisine aşırı uyum sağlayabilir. Bu nedenle budama veya durma koşulları önem kazanır.
### Ders 6: Naive Bayes sınıflayıcı

#### Genel Konular

- Naive Bayes sınıflayıcı
  - Naive Bayes, Bayes teoremine dayalı olasılıksal bir sınıflama yöntemidir.
  - Öz niteliklerin sınıf koşulu altında birbirinden bağımsız olduğu varsayımıyla hesaplamayı basitleştirir.
- Posterior olasılık ve karar verme
  - Her sınıf için gözlenen öz nitelikler altında olasılık hesaplanır.
  - En yüksek posterior olasılığa sahip sınıf tahmin sonucu olarak seçilir.
- K-en yakın komşu yöntemine giriş
  - KNN, yeni örneği eğitim verisindeki en yakın komşuların sınıfına göre etiketleyen örnek tabanlı bir yöntemdir.
  - K değeri ve uzaklık ölçüsü yöntemin davranışını belirler.
- Dengesiz veri problemi
  - Sınıflar arasında büyük oran farkı varsa model başarısı yalnızca doğruluk oranıyla değerlendirilemez.

#### Hocanın Özellikle Vurguladığı Kısımlar

- Naive Bayes'teki bağımsızlık varsayımı
  - Bu varsayım gerçek hayatta her zaman tam sağlanmasa da yöntemi pratik ve hızlı hale getirir.
- KNN'de K seçimi
  - Çok küçük K gürültüye duyarlı, çok büyük K ise sınıf sınırlarını fazla yumuşatan sonuçlar üretebilir.

#### Detaylı Açıklamalar

- Derste Naive Bayes sınıflayıcının temel mantığı, sınıf olasılıkları ile öz nitelik olasılıklarının birlikte kullanılması olarak açıklanır. Her sınıf için verinin o sınıfa ait olma olasılığı hesaplanır ve karşılaştırılır.
- Yöntemin naive olarak adlandırılmasının nedeni, öz nitelikler arasında koşullu bağımsızlık varsayımı yapmasıdır. Bu varsayım hesaplamayı kolaylaştırır ve özellikle metin sınıflama gibi yüksek boyutlu problemlerde pratik avantaj sağlar.
- KNN tarafında model açık biçimde parametre öğrenmez; eğitim örneklerini saklar ve yeni örnek geldiğinde yakınlık hesabı yapar. Bu nedenle ölçekleme, uzaklık metriği ve K değeri kritik hale gelir.
### Ders 9: Dengesiz sınıf problemi

#### Genel Konular

- Dengesiz sınıf problemi
  - Veri setinde bir sınıf çok fazla, diğer sınıf çok az örnek içerdiğinde accuracy yanıltıcı olabilir.
  - Kredi kartı sahteciliği, saldırı tespiti ve kusurlu ürün tespiti gibi problemlerde azınlık sınıfı genellikle daha önemlidir.
- Confusion matrix ve başarı ölçütleri
  - True positive, true negative, false positive ve false negative kavramları üzerinden sınıflayıcı performansı değerlendirilir.
  - Precision, recall, F-measure, specificity, false positive rate ve false negative rate ölçütleri anlatılır.
- ROC eğrisi
  - ROC eğrisi, true positive rate ile false positive rate arasındaki ilişkiyi grafiksel olarak gösterir.
  - Olasılık üreten sınıflayıcı çıktıları ve threshold değişimi kullanılarak çizilir.
- KNN için model seçimi
  - K değeri validation verisi üzerinden seçilebilir.
  - Eğitim, doğrulama ve test ayrımı model başarısını tarafsız değerlendirmek için kullanılır.

#### Hocanın Özellikle Vurguladığı Kısımlar

- Accuracy'nin dengesiz veride yetersizliği
  - Tüm örnekleri çoğunluk sınıfına atayan bir model yüksek accuracy üretebilir ama azınlık sınıfını tamamen kaçırabilir.
- Confusion matrix yönlerinin doğru okunması
  - Actual ve predicted sınıfların hangi eksende bulunduğu karıştırılırsa tüm ölçütler yanlış hesaplanır.
- ROC için olasılık çıktısı gerekliliği
  - Sadece sınıf etiketi veren modelden ROC çizmek yeterli değildir; eşik değişimi için skor veya olasılık gerekir.

#### Detaylı Açıklamalar

- Derste dengesiz veri probleminde accuracy'nin neden yanıltıcı olduğu örneklerle açıklanır. Eğer 1000 örneğin 990'ı negatif, 10'u pozitifse, tüm örneklere negatif diyen bir model yüzde 99 accuracy verir. Fakat pozitif sınıf asıl önemli sınıfsa model pratikte başarısızdır.
- Confusion matrix, sınıflayıcının hangi örnekleri doğru veya yanlış etiketlediğini gösterir. True positive gerçek pozitifin pozitif tahmin edilmesi, false negative gerçek pozitifin negatif tahmin edilmesi, false positive gerçek negatifin pozitif tahmin edilmesi, true negative ise gerçek negatifin negatif tahmin edilmesidir.
- Precision ve recall farklı başarı boyutlarını ölçer. Precision yanlış alarmı, recall ise kaçırılan pozitifleri anlamak için önemlidir. F-measure bu iki ölçütü tek sayıda birleştirerek model karşılaştırmayı kolaylaştırır.
- ROC eğrisi, farklı threshold değerlerinde modelin yakalama oranı ile yanlış alarm oranı arasındaki değişimi gösterir. İyi bir sınıflayıcı yüksek true positive rate ve düşük false positive rate üretmelidir.
### Ders 11: Eğiticisiz öğrenme ve kümeleme

#### Genel Konular

- Eğiticisiz öğrenme ve kümeleme
  - Kümeleme, sınıf etiketi olmayan verileri benzerliklerine göre gruplama işlemidir.
  - Etiketleme maliyetli olduğu için kümeleme büyük ve etiketsiz veri kümelerinde önemlidir.
- Uzaklık ve benzerlik ölçütleri
  - Öklid, Manhattan, Minkowski, Mahalanobis, kosinüs benzerliği ve Hamming gibi ölçütler ele alınır.
  - Nümerik ve ikili öz nitelikler için farklı metrikler uygun olabilir.
- Binary özelliklerde benzerlik
  - Simple Matching Coefficient, sıfır-sıfır ve bir-bir eşleşmelerini birlikte dikkate alır.
  - Jaccard benzerliği özellikle bir-bir eşleşmelerini önemser ve sıfır-sıfır eşleşmesini hesaba katmaz.
- K-means kümeleme
  - K-means, n örneği önceden seçilen K adet kümeye ayırır.
  - Amaç, örneklerin kendi küme merkezlerine olan uzaklıklarının kareleri toplamını minimize etmektir.

#### Hocanın Özellikle Vurguladığı Kısımlar

- K-means'in temel yöntem oluşu
  - K-means anlaşılırsa fuzzy c-means, self organizing map ve benzeri yöntemleri anlamak kolaylaşır.
- Başlangıç küme merkezlerinin etkisi
  - İlk centroid seçimi sonucu etkileyebilir; yöntem iteratif olarak merkezleri günceller.
- Jaccard formülünde sıfır-sıfır eşleşmesinin dışarıda bırakılması
  - Asimetrik binary değişkenlerde iki örneğin aynı anda sıfır olması benzerlik anlamına gelmeyebilir.

#### Detaylı Açıklamalar

- Derste kümeleme, veri madenciliğinin eğiticisiz öğrenme kolu olarak anlatılır. Kullanım örnekleri arasında e-postaları gruplama, müşteri segmentasyonu ve görüntüde bölge belirleme bulunur. Bu problemlerde sınıf etiketi olmadan doğal gruplar aranır.
- K-means'te önce K değeri belirlenir. Ardından K adet başlangıç merkezi seçilir. Her örnek en yakın merkezin kümesine atanır. Kümeler oluştuktan sonra her kümenin yeni merkezi hesaplanır. Örneklerin küme üyelikleri değişmeyene veya belirlenen durma koşulu sağlanana kadar işlem tekrarlanır.
- Mesafe ölçüsü seçimi kritik önemdedir. Nümerik verilerde Öklid veya Manhattan mesafesi kullanılabilirken, ölçek ve korelasyon etkilerini dikkate almak için Mahalanobis mesafesi tercih edilebilir. Metin veya vektör yönelimi önemli olduğunda kosinüs benzerliği anlamlıdır.
- Binary özelliklerde tüm eşleşmeler aynı öneme sahip olmayabilir. Simple matching tüm eşleşmeleri dikkate alırken, Jaccard yalnızca bir-bir eşleşmelerine odaklanır. Bu nedenle değişkenlerin anlamına göre doğru benzerlik ölçütü seçilmelidir.
### Ders 12: Hiyerarşik kümeleme

#### Genel Konular

- Hiyerarşik kümeleme
  - Hiyerarşik kümeleme, örnekleri ağaç benzeri bir yapı içinde birleştirerek veya bölerek gruplar.
  - Sonuç dendrogram ile görselleştirilebilir.
- Agglomerative ve divisive yaklaşımlar
  - Agglomerative yöntem bottom-up çalışır; her örnek başlangıçta tek başına kümedir ve benzer kümeler adım adım birleştirilir.
  - Divisive yöntem top-down çalışır; tüm örnekler tek kümede başlar ve giderek alt kümelere ayrılır.
- Linkage yöntemleri
  - Single linkage, kümeler arasındaki en yakın iki noktanın mesafesini kullanır.
  - Complete linkage, en uzak iki noktanın mesafesini kullanır.
  - Average linkage, kümeler arası tüm nokta çiftlerinin ortalama uzaklığına dayanır.
- Küme uzaklığı ölçüleri
  - Minimum, maximum, mean ve average distance gibi farklı küme uzaklığı tanımları anlatılır.

#### Hocanın Özellikle Vurguladığı Kısımlar

- Agglomerative yaklaşımın daha sezgisel olması
  - Tekil örneklerden başlayıp benzerleri birleştirmek, divisive bölmeye göre daha kolay kurgulanır.
- Dendrogramın sadece çizim değil karar aracı olması
  - Hangi seviyede kesileceği, kaç küme elde edileceğini belirler.
- Küme-küme uzaklığı ile örnek-örnek uzaklığının farklılığı
  - Hiyerarşik yöntemde artık tek örneklerin değil, birden çok örnek içeren kümelerin arası ölçülür.

#### Detaylı Açıklamalar

- Derste hiyerarşik kümeleme, K-means gibi doğrudan sabit sayıda küme üretmek yerine, verinin farklı ayrıntı seviyelerindeki gruplanmasını gösteren bir yöntem olarak anlatılır. Bu yapı, küme ilişkilerini görsel ve yorumlanabilir hale getirir.
- Agglomerative yöntemde başlangıçta her örnek atomik bir kümedir. En benzer iki küme birleştirilir ve bu işlem tekrarlandıkça daha büyük kümeler oluşur. Tüm örnekler tek kümede toplanana kadar süreç sürdürülebilir; ancak pratikte belirli sayıda küme kalınca veya mesafe eşiği aşılınca durulur.
- Divisive yöntem ters yönde çalışır. Başlangıçta tüm veri tek kümedir ve sonra alt gruplara ayrılır. Bu yaklaşım teorik olarak anlamlı olsa da hangi ayrımın yapılacağını belirlemek daha zor olduğu için agglomerative yaklaşım daha uygulanabilir görülür.
- Linkage seçimi sonuç üzerinde doğrudan etkilidir. Single linkage zincirleme etki yaratabilir; complete linkage daha sıkı kümeler üretme eğilimindedir; average linkage iki uç yaklaşım arasında denge sağlar.
### Ders 13: Birliktelik kuralları

#### Genel Konular

- Birliktelik kuralları
  - Birliktelik analizi, veri içinde öğelerin birlikte görülme eğilimlerini bulmayı amaçlar.
  - Market sepeti analizi bu yaklaşımın klasik örneğidir.
- Market sepeti analizi
  - Müşterilerin aynı alışverişte aldığı ürünler incelenerek ürünler arası ilişkiler çıkarılır.
  - E-ticaret önerileri, kampanya tasarımı ve raf yerleşimi gibi alanlarda kullanılabilir.
- Kural yapısı
  - Birliktelik kuralı genellikle X -> Y biçimindedir.
  - Bu ifade X öğeleri görüldüğünde Y öğesinin de görülme eğilimini temsil eder.
- Destek ve güven
  - Support, ilgili öğe kümesinin veri tabanında ne kadar sık geçtiğini gösterir.
  - Confidence, X gerçekleştiğinde Y'nin gerçekleşme olasılığına karşılık gelir.

#### Hocanın Özellikle Vurguladığı Kısımlar

- Birliktelik ile nedenselliğin karıştırılmaması
  - X ve Y birlikte görülüyor diye X'in Y'ye neden olduğu söylenemez.
- Destek eşiğinin önemi
  - Çok düşük destekli kurallar rastlantısal olabilir; çok yüksek eşik ise ilginç kuralları kaçırabilir.

#### Detaylı Açıklamalar

- Derste birliktelik kuralları, denetimli sınıflama veya kümeleme dışında üçüncü temel veri madenciliği başlığı olarak ele alınır. Burada amaç sınıf tahmin etmek değil, veri içinde sık birlikte ortaya çıkan öğe kümelerini bulmaktır.
- Market sepeti analizinde her alışveriş bir işlem olarak düşünülür. İşlemlerde hangi ürünlerin birlikte yer aldığı incelenir. Örneğin bir ürün grubunu alan kullanıcıların başka bir ürünü de alma eğilimi varsa, bu ilişki öneri veya kampanya tasarımında kullanılabilir.
- Support ve confidence, kuralların anlamlılığını değerlendirmek için temel ölçütlerdir. Support kuralın veri genelinde ne kadar yaygın olduğunu, confidence ise öncül gerçekleştiğinde sonucun ne kadar güvenilir biçimde görüldüğünü açıklar.
### Ders 14: Birliktelik kuralları devamı

#### Genel Konular

- Birliktelik kuralları devamı
  - Market sepeti analizinde sık öğe kümelerinin bulunması ve bu kümelerden kurallar üretilmesi üzerinde durulur.
  - Kural değerlendirmede support ve confidence yanında ek ölçütler kullanılabilir.
- Apriori mantığı
  - Sık olmayan bir öğe kümesinin üst kümeleri de sık olamaz ilkesine dayanır.
  - Bu ilke aday öğe kümesi sayısını azaltarak arama sürecini verimli hale getirir.
- Lift ve kural ilginçliği
  - Lift, X ve Y'nin birlikte görülmesinin bağımsız beklenene göre ne kadar güçlü olduğunu gösterir.
  - Yüksek confidence tek başına yeterli olmayabilir; yaygın sonuç öğeleri yanıltıcı kural üretir.
- Kuralların yorumlanması
  - Kurallar iş bilgisiyle birlikte değerlendirilmelidir.
  - Çok sayıda kural üretilebilir; bu nedenle eşik değerleri ve ilginçlik ölçütleri önemlidir.

#### Hocanın Özellikle Vurguladığı Kısımlar

- Confidence'ın tek başına yeterli olmaması
  - Sonuç öğesi zaten çok sık görülüyorsa yüksek confidence gerçek ilişki gücünü abartabilir.
- Apriori ilkesinin arama alanını azaltması
  - Tüm kombinasyonları denemek pahalıdır; sık olmayan kümelerin üst kümelerini elemek işlem maliyetini düşürür.

#### Detaylı Açıklamalar

- Derste birliktelik kuralları daha algoritmik açıdan ele alınır. Büyük işlem veri tabanlarında tüm olası öğe kombinasyonlarını saymak çok maliyetli olduğu için Apriori benzeri yöntemler aday sayısını azaltır.
- Apriori yaklaşımı, önce tek öğeli sık kümeleri bulur; sonra bunlardan iki öğeli, üç öğeli ve daha büyük aday kümeler üretir. Bir adayın alt kümelerinden biri sık değilse o adayın kendisinin de sık olamayacağı kabul edilir ve aramadan çıkarılır.
- Confidence kuralın koşullu güvenilirliğini gösterse de tek başına yanıltıcıdır. Çok yaygın bir ürün sonuç tarafında yer alıyorsa birçok öncül için yüksek confidence verebilir. Lift gibi ölçütler, ilişkinin rastlantısal veya doğal yaygınlıktan kaynaklanıp kaynaklanmadığını ayırt etmeye yardım eder.
- Birliktelik kurallarının çıktısı çoğu zaman çok sayıda kuraldır. Bu nedenle minimum support, minimum confidence ve lift gibi eşikler belirlenerek hem istatistiksel hem de pratik açıdan anlamlı kurallar seçilir.

> **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi daha verimli çalışabilirsiniz.
