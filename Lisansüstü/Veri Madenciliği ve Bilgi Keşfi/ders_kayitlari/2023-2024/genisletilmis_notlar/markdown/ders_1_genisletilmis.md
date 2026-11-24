# Ders 1 Genişletilmiş Notu: Veri Madenciliğine Giriş ve Veri Madenciliği Stratejileri

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Veri Madenciliği Nedir?
- 2. Dersin Kapsamı ve Kullanılan Araçlar
- 3. Neden Veri Madenciliği?
- 4. Potansiyel Uygulama Alanları
- 5. Dolandırıcılık Tespiti ve Olağandışı Örüntüler
- 6. Veri Madenciliği Stratejileri
- 7. Eğiticili Öğrenme ve Karar Ağacı Örneği
- 8. Eğiticisiz Kümeleme
- 9. Sınıflandırma, Kestirim ve Öngörü
- 10. Market Sepeti Analizi
- 11. Üretim Kuralları: Doğruluk ve Kapsayıcılık
- Örnek Sorular
- Dersin Toparlaması

## 1. Veri Madenciliği Nedir?

Hoca dersi, veri madenciliğinin gerçek dünyaya dokunan, sonuçları yorumlanabilen ama matematiği de kullanan bir alan olduğunu söyleyerek açtı. Kullanılan matematik çok ağır değildir; zamanla unutulan matematik ve istatistik konuları için ders içinde "hadi şimdi hatırlayalım" diye kısa hatırlatma bölümleri yapılacaktır.

Dersin amacı ekrandaki tanıtım belgesinde şöyle yazıyordu: veri madenciliği, büyük miktardaki veriden bilgi keşfetmektir; başka bir anlamıyla, bilgisayar programları aracılığıyla gelecek hakkında öngörüde bulunma sürecidir (ekrandan, 00:10:00). Literatürde aynı işi anlatan pek çok ad vardır:

- knowledge mining from databases (veri tabanlarından bilgi madenciliği),
- knowledge extraction (bilgi çıkarımı),
- data/pattern analysis (veri/örüntü analizi),
- data archeology (veri arkeolojisi),
- ve en bilineni Knowledge Discovery from Databases (KDD).

Bu adların hepsinin yapmaya çalıştığı şey aynıdır: önce veriyi iyi analiz etmek, sonra veriden amaca uygun, hedefe yönelik bilgi çıkaran yöntem ve algoritmaları uygulamak.

Veri madenciliği yalnız bilgisayar mühendisliğinde değil, endüstri mühendisliği ve işletme gibi bölümlerde de okutulur; oralarda "business intelligence" ya da "karar destek sistemleri (decision support)" gibi farklı ders adları taşır. Hocaya göre temelde aynı algoritmalar öğrenilir. Bilgisayar mühendisliği öğrencileri bu yöntemleri daha çok bir araç olarak öğrenir; uygulama alanı (application) ihtiyaca göre değişir.

## 2. Dersin Kapsamı ve Kullanılan Araçlar

### 2.1 Konuların genel akışı

Hoca dersin akademik akışını şöyle özetledi (ekrandan, 00:15:00):

- **Veri ön işleme:** Ham veri yığınından amaca uygun parametrelerin seçilmesi, yani veri azaltma (data reduction), verinin ayrıklaştırılması (discretization) ve normalizasyon işlemleri. Bu temel kavramlar ilk haftaları kapsar.
- **Eğiticili (supervised) yöntemler:** Karar ağaçları ve karar kuralları (decision trees and decision rules), istatistiksel sınıflandırma yöntemleri ve Naive Bayes sınıflandırıcı.
- **Eğiticisiz (unsupervised) kümeleme:** Temel (baseline) algoritmalar olarak K-means ve hiyerarşik kümeleme; ayrıca öz düzenleyici haritalar (Self-Organizing Map). Hoca temel algoritmalar iyi öğrenilince yeni yöntemlerin çok daha kolay anlaşılacağını söyledi.
- **Birliktelik kuralları ve market sepeti analizi:** Apriori algoritması; işletmelerde ve pazarlamada kullanılan yöntemler.
- **Öneri sistemleri:** Kişiselleştirilmiş öneri sistemleri (personalized recommendation systems) ve işbirlikçi filtreler (collaborative filters).

Hoca, yöntemleri "bir filtre, alt tipi ne" diye ezberlemek yerine matematiğini göreceklerini vurguladı. Örneğin yalnız 10 örnekten oluşan basit bir veriyle karar ağacı çizdirmek istense, altta yatan matematik nedir, neyi ve nasıl hesaplıyoruz, ağaçta neyi görüyoruz; bunlar adım adım ele alınacaktır. Böyle öğrenilen bir yöntem sonra kodlanıp kullanılabilir hale gelir.

> **Hocanın vurgusu:** Bir yöntemin matematiğini bilirseniz hangi veri üzerinde hangi yöntemin kullanılabileceğine çok daha kolay önceden karar verebilirsiniz.

### 2.2 Araçlar: Python ve WEKA

Derste kodlama ağırlıklı olarak Python ile yapılacaktır. Kendi kodumuzun ve kütüphanelerin yanında hazır programlar da kullanılabilir. Hoca ilk olarak WEKA'yı tanıttı: Yeni Zelanda'daki Waikato Üniversitesi'nde geliştirilmiş, Java ile yazılmış, açık kaynaklı bir veri madenciliği araç kutusudur. Üniversite ortamında geliştirildiği için her araştırmacı bir parça üretip eklemiştir. Kodlama bilmeyen ya da yeni başlayan biri için, veriler üzerinde hızlıca sonuç almakta çok yararlı bir araçtır.

### 2.3 Kaynak kitaplar

Hocanın önerdiği iki temel kitap ekranda görünüyordu (ekrandan, 00:15:00):

- Mehmed Kantardzic, *Data Mining: Concepts, Models, Methods and Algorithms*. Hoca derse ve sınavlara hazırlanırken en çok bu kitabı kullandığını söyledi.
- J. Han ve M. Kamber, *Data Mining* (Morgan Kaufmann). Hocaya göre özellikle işletme ve pazarlama tarafı için iyi bir kitaptır.

## 3. Neden Veri Madenciliği?

Ekrandaki "Why Data Mining?" slaytı şu noktaları içeriyordu (ekrandan, 00:30:00):

- Verinin patlayıcı büyümesi: terabaytlardan petabaytlara.
  - Veri toplama ve verinin erişilebilirliği: otomatik veri toplama araçları, veri tabanı sistemleri, web, bilgisayarlaşmış toplum.
  - Bol verinin başlıca kaynakları: iş dünyası (web, e-ticaret, işlemler, borsa), bilim (uzaktan algılama, biyoinformatik, bilimsel simülasyon), toplum ve herkes (haberler, dijital kameralar).
- "We are drowning in data, but starving for knowledge!"
- "İhtiyaç icadın anasıdır": veri madenciliği, büyük veri setlerinin otomatik analizidir.

<!-- BELİRSİZ: Altyazıda hocanın verinin "petabaytlardan ... byte'lara doğru" çıktığını söylediği yer bozuk; slaytta "terabytes to petabytes" yazıyor. -->

Hoca verinin büyüklüğünü sağlık alanından örneklerle somutlaştırdı. Ulusal sağlık kayıt sistemindeki verinin yaklaşık 5 petabayta yaklaştığını, üstelik bunun içinde radyolojik görüntülerin hiç olmadığını, yalnız klinik verilerin bulunduğunu söyledi. Radyoloji tarafında veri çok daha büyüktür; çünkü tomografi ve MR görüntüleri kesit kesit alınır ve katlanarak büyür. Genetik araştırmalarda kullanılan veriler de çok büyüktür.

Dijital patoloji de yeni bir veri kaynağıdır. Patolojide doku bir lam (cam) üzerine yerleştirilir ve uzman normalde mikroskop altında, örneğin 20 kat büyüterek inceler. Dijital patolojide bu camlar 20 kat büyütmeyle taranıp sayısallaştırılır. Hocanın aktardığına göre sıkıştırma uygulanmamış tek bir cam görüntüsü yaklaşık 40 GB'lık bir dosyadır.

Bu verinin yalnız izlemek (monitor etmek) ya da hasta bilgilerini dökmek dışında da kullanılması gerekir: veriyi dijital platformlara taşıyabiliyoruz, ama artık bir bilgiye dönüştürmemiz gerekiyor. Aynı durum e-ticaret siteleri, bankacılık ve bireysel emeklilik gibi sistemlerde tutulan veriler, borsa işlemleri, biyoinformatik ve genetik çalışmalar, tıbbi görüntüleme, hava tahmini için toplanan veriler ve sosyal medyada üretilen görüntü ve haberler için de geçerlidir. Slayttaki ifadeyle veride boğuluyoruz ama bilgi keşfi yapan çalışmalara açız. Bunu yapanlar vardır, ama yaygınlaşması gerekmektedir.

Hoca bu gelişmenin arkasında veri tabanı teknolojilerinin, özellikle ilişkisel veri tabanlarının olgunlaşmasının büyük payı olduğunu belirtti; dijital platformdaki veri için en sağlam altyapı bunlardır.

## 4. Potansiyel Uygulama Alanları

"Why Data Mining? Potential Applications" slaytı uygulama alanlarını şöyle sıralıyordu (ekrandan, 00:35:00):

- Veri analizi ve karar destek
  - Pazar analizi ve yönetimi: hedef pazarlama, müşteri ilişkileri yönetimi (CRM), market sepeti analizi, çapraz satış (cross selling), pazar segmentasyonu.
  - Risk analizi ve yönetimi: tahmin (forecasting), müşteriyi elde tutma, sigortacılıkta daha iyi risk değerlendirmesi (improved underwriting), kalite kontrol, rekabet analizi.
  - Dolandırıcılık tespiti ve olağandışı örüntülerin (aykırı değerlerin) tespiti.
- Diğer uygulamalar
  - Metin madenciliği (haber grupları, e-posta, belgeler) ve web madenciliği.
  - Akış verisi madenciliği (stream data mining).
  - Biyoinformatik ve biyolojik veri analizi.

Pazarlama tarafında müşteri segmentasyonu (customer segmentation) önemlidir: müşteriler gruplanır ve bir segmentteki müşteriye bir üst segmentin ürünleri satılmaya çalışılır. Hoca, telekomünikasyon şirketlerinin müşterinin paketinde neyi ne kadar kullandığına bakmadan onu sürekli bir üst pakete yönlendirmeye çalışmasını örnek verdi ve müşteri olarak bu tekniklere karşı dikkatli olmak gerektiğini söyledi. Risk yönetimi ve finansal planlama başlıklarını ise hızlı geçti.

## 5. Dolandırıcılık Tespiti ve Olağandışı Örüntüler

"Fraud Detection & Mining Unusual Patterns" slaytı (ekrandan, 00:40:00):

- Yaklaşımlar: kümeleme ve dolandırıcılık için model kurma, aykırı değer analizi.
- Uygulamalar: sağlık, perakende, kredi kartı hizmetleri, telekomünikasyon.
  - Oto sigortası: düzenlenmiş kaza halkaları (ring of collisions).
  - Kara para aklama: şüpheli parasal işlemler.
  - Sağlık sigortası: profesyonel hastalar, doktor ve sevk halkaları; gereksiz ya da birbiriyle ilişkili tarama testleri.
  - Telekomünikasyon: telefon görüşmesi dolandırıcılığı. Görüşme modeli; aranan yer, süre, günün ya da haftanın zamanı. Beklenen normdan sapan örüntüler analiz edilir.
  - Perakende: analistlere göre perakende kayıplarının %38'i dürüst olmayan çalışanlardan kaynaklanır.
  - Terörle mücadele.

Hoca, dolandırıcılık tespitinin özellikle bankacılık uygulamalarında en çok ihtiyaç duyulan konulardan biri olduğunu söyledi. Kredi kartı örneğinde her kart kullanıcısının bir harcama düzeni vardır: markete ortalama ne kadar harcadığı, harcamanın ay içine nasıl dağıldığı, elektronik ya da kuyumculuk gibi sektörlere aylık ne kadar harcadığı bilinir. Bir aylık harcamanın tamamı bir günde tek bir mağazada yapılırsa bu, olağandışı bir örüntü (unusual pattern) olarak görülür ve alarm üretilebilir. Ama bu şüpheli durum gerçekten kart sahibinin kendi davranışı da olabilir; yani her alarm dolandırıcılık değildir.

Sağlık sigortasında bir kişinin başka bir hastanın yerine geçip ilaç yazdırması gibi durumlar da hasta kayıtlarının geçmişine bakılarak yakalanabilir. Telekomünikasyondaki dolandırıcılık işlemleri de veri madenciliği yöntemleriyle izlenebilir.

Hoca ilginç bir çalışmayı aktardı: kredi kartı bilgileri çalınan ya da kopyalanan kartlarla yapılan işlemlerde şöyle bir örüntü yakalanmış. İlk işlem olarak bir akaryakıt istasyonunda benzin alınıyor; hemen ardından ikinci işlem olarak bir mağazada elektronik ya da pahalı bir ürün alınıyor ve kartın limiti kadar harcama yapılıp kart bir daha kullanılmıyor. Bunun nedeni öğrencilere soruldu (bkz. Örnek Sorular).

**Soru:** Dolandırıcı neden önce akaryakıt istasyonundan benzin alıyor? **Cevap:** Bir öğrenci kartın çalışıp çalışmadığını kontrol ediyor olabileceğini söyledi. Hoca bu cevabı onayladı: kart çalışmıyorsa ya da durum fark edilmişse akaryakıt istasyonu kolayca uzaklaşmaya elverişli bir yerdir; kart çalışıyorsa hemen ardından limit kadar alışveriş yapılıyor. Hoca, bugün çevrim içi alışverişte de benzer yöntemlerin olduğunu ve kart sahiplerinin dikkatli olması gerektiğini ekledi.

## 6. Veri Madenciliği Stratejileri

Hoca bu bölümü "en sevdiği slayt" diye tanıttı ve dönem boyunca her konunun bu ağaçta nereye oturduğunu tekrar tekrar hatırlatacağını söyledi. Veri madenciliği stratejileri altyazıya göre şöyle bir ağaçla gösterildi:

```text
Veri madenciliği stratejileri
├── Eğiticisiz kümeleme (Unsupervised Clustering)
├── Eğiticili öğrenme (Supervised Learning)
│   ├── Sınıflandırma (Classification)
│   ├── Kestirim (Estimation)
│   └── Öngörü (Prediction)
└── Market sepeti analizi (Market Basket Analysis)
```

<!-- BELİRSİZ: Strateji ağacının slaytı karelerde görünmüyor; yapı altyazıdaki anlatımdan kuruldu. -->

- **Eğiticisiz kümeleme:** Elimizde etiketsiz veri vardır ve bu veriyle kümeleme yapılır.
- **Eğiticili öğrenme:** Bir alan uzmanınca etiketlenmiş veri vardır; bununla sınıflandırma, kestirim ya da öngörü yapılır.
- **Market sepeti analizi:** Birliktelik kuralları ve ürün öneri sistemleri bu başlıktadır.

Hoca özellikle ilk iki başlığın, yani eğiticili ve eğiticisiz yöntemlerin ne olduğunun en başta kavram olarak iyi anlaşılması gerektiğini söyledi.

## 7. Eğiticili Öğrenme ve Karar Ağacı Örneği

### 7.1 İki temel adım

"Supervised Learning" slaytında iki madde vardır (ekrandan, 00:50:00):

- Build a learner model using data instances of known origin: sınıfı (kökeni) bilinen veri örneklerini kullanarak öğrenebilen bir model kur.
- Use the model to determine the outcome of new instances of unknown origin: bu modeli, sınıfı bilinmeyen yeni örneklerin sonucunu belirlemek için kullan.

Hoca bazı kavramları Türkçeye çevirince aynı anlamın tam aktarılamadığını, bu yüzden önce İngilizcesini verip sonra açıkladığını belirtti. Birinci adımda elimizde bir alan uzmanınca etiketlenmiş, yani bir sınıf etiketi (class label, çıktı) içeren veri vardır; bu veriyle veriden öğrenebilen bir model kurulur. İkinci adımda bu model, etiketi bilinmeyen yeni örneklerin hangi sınıfa ait olduğunu tahmin etmek için kullanılır.

### 7.2 Eğitim verisi: varsayımsal hastalık teşhisi

Kavramı somutlaştırmak için "Hypothetical Training Data for Disease Diagnosis" tablosu kullanıldı (ekrandan, 00:45:00). 10 hasta vardır (Patient ID 1-10), her satır bir örnektir (sample). Hastalara beş evet/hayır sorusu sorulmuştur: boğaz ağrısı (Sore Throat), ateş (Fever), şiş bezeler (Swollen Glands), burun tıkanıklığı (Congestion) ve baş ağrısı (Headache). Bu tıbbi veri setinde amaç hastaya teşhis koymaktır.

| Hasta | Sore Throat | Fever | Swollen Glands | Congestion | Headache | Diagnosis |
|---|---|---|---|---|---|---|
| 1 | Yes | Yes | Yes | Yes | Yes | Strep throat |
| 2 | No | No | No | Yes | Yes | Allergy |
| 3 | Yes | Yes | No | Yes | No | Cold |
| 4 | Yes | No | Yes | No | No | Strep throat |
| 5 | No | Yes | No | Yes | No | Cold |
| 6 | No | No | No | Yes | No | Allergy |
| 7 | No | No | Yes | No | No | Strep throat |
| 8 | Yes | No | No | Yes | Yes | Allergy |
| 9 | No | Yes | No | Yes | Yes | Cold |
| 10 | Yes | Yes | No | Yes | Yes | Cold |

Bu beş sorunun cevaplarına göre bir alan uzmanı, burada bir kulak burun boğaz doktoru, Diagnosis sütununu doldurmuştur: Strep throat (boğaz enfeksiyonu), Allergy (alerji) ve Cold (soğuk algınlığı). Yani üç farklı sınıf etiketi vardır.

Bu veri setinin adı eğitim veri setidir (training data set). Eğitim veri setinde mutlaka bir etiket bulunmalıdır; burada Diagnosis sütunu çıktı değişkenimiz (output variable) ve etiketlerimizdir. Veri yalnız hastalara sorularak toplansaydı sadece beş parametrenin cevaplarından oluşurdu; bir alan uzmanına gösterilip etiketlendiği için eğitim verisine dönüşmüştür.

Terminoloji açısından hoca, sütunlara Türkçede öz nitelik, İngilizcede feature dendiğini, istatistikçilerin ise bunlara değişken (variable) dediğini hatırlattı. Bu veride beş öz nitelik ve bir çıktı değişkeni (sınıf etiketi) vardır.

### 7.3 Öğrenilen model: karar ağacı

Bu veriden öğrenen bir algoritmayla şu karar ağacı elde edilmiştir. Ağaçta belirli öz niteliklerin aldığı değerlere bakılarak nihai karar, yani teşhis verilir:

```text
Swollen Glands?            (kök düğüm)
├── Yes -> Strep throat
└── No  -> Fever?
           ├── Yes -> Cold
           └── No  -> Allergy
```

En üst düğümde boğazdaki bezelerin şiş olup olmadığı sorulur. Bezeler şişse teşhis boğaz enfeksiyonudur. Değilse ateş olup olmadığına bakılır: ateş varsa soğuk algınlığı, yoksa alerji. Yapraklardaki sonuç düğümlerine uç (terminal) düğüm denir; bunlar karar ağaçları konusunda ayrıntılı anlatılacaktır.

Ağacın eğitim verisindeki 10 hastanın hepsini doğru sınıfladığı tablo üzerinden kontrol edilebilir (ajan tarafından python ile doğrulandı): şiş bezeli 1, 4, 7 numaralı hastalar Strep throat; bezeleri şiş olmayıp ateşi olan 3, 5, 9, 10 numaralılar Cold; ikisi de olmayan 2, 6, 8 numaralılar Allergy.

> **Ek bilgi (derste anlatılmadı):** Ağaçta boğaz ağrısı, tıkanıklık ve baş ağrısı öz niteliklerinin hiç kullanılmaması, karar ağacı algoritmalarının yalnız sınıfları ayırmaya en çok katkı yapan öz nitelikleri seçmesinden kaynaklanır. Bu seçimin hangi ölçüye (örneğin bilgi kazancı) göre yapıldığı karar ağaçları konusunda ele alınır.

### 7.4 Modeli yeni örneklere uygulamak

İkinci adımda model, sınıfı bilinmeyen yeni örneklere uygulanır. Elimizdeki 10 hastaya 11, 12 ve 13 numaralı hastalar eklenir; onlara da aynı sorular sorulmuştur. Fakat bu kez sonuçlar uzmana değil modele sorulur:

- 11 numaralı hastanın bezeleri şiştir: Strep throat.
- 12 numaralı hastanın bezeleri şiş değil, ateşi var: Cold.
- 13 numaralı hastanın bezeleri şiş değil, ateşi de yok: Allergy.

<!-- BELİRSİZ: 11-13 numaralı hastaların tam öz nitelik tablosu karelerde görünmüyor; sonuçlar altyazıdaki anlatımdan alındı. -->

Sınıflandırma ya da eğiticili öğrenme başlığında yapılan iş bu şekilde özetlenebilir: etiketli veriden model kur, modeli etiketsiz yeni örneğe uygula.

## 8. Eğiticisiz Kümeleme

Eğiticisiz kümeleme, önceden tanımlı bir sınıf olmadan veriden model kuran bir veri madenciliği yöntemidir ("a data mining method that builds models from data without predefined classes"). Aynı örnekten gidilirse: 10 hastaya 5 soru sorulmuş, ama toplanan veri bir uzmana gösterilmemiş, dolayısıyla sınıf etiketi yoktur.

Hoca bunun pratikteki önemini vurguladı: bir uzmanın veriyi işaretlemesi çok zaman alır. Geçmişte konmuş teşhisler üzerinden geriye dönük çalışılıyorsa etiketli veri bulunabilir, ama veriyi etiketletmek hem maliyetli hem zaman alıcıdır. Bu yüzden çoğu zaman etiketsiz veriyle çalışmak zorunda kalınır.

Elimizde istatistikteki adıyla gözlemler (observation) vardır, ama tanımlanmış bir çıktı değişkeni yoktur. Bu durumda yapılabilecek iş kümelemedir (clustering). Hoca Türkçede "kümeleme" dediğini, bazı kaynakların "öbekleme" ya da "topaklama" dediğini, terminolojinin henüz oturmadığını belirtti. Kümelemede örnekler (burada hasta ya da müşteri) birbirlerine olan benzerliklerine göre, benzerlik ölçüleri (similarity) kullanılarak gruplanır: en benzer olanlar aynı gruba, az benzeyenler ayrı gruplara yerleştirilir. Örneğin bir bankanın ya da e-ticaret sitesinin müşterileri alışveriş davranışlarına göre 3 ya da 5 segmente ayrılabilir.

### 8.1 Acme yatırımcı veri seti

Örnek olarak Acme Investors Incorporated veri seti gösterildi (ekrandan, 00:55:00):

| Customer ID | Account Type | Margin Account | Transaction Method | Trades/Month | Sex | Age | Favorite Recreation | Annual Income |
|---|---|---|---|---|---|---|---|---|
| 1005 | Joint | No | Online | 12.5 | F | 30-39 | Tennis | 40-59K |
| 1013 | Custodial | No | Broker | 0.5 | F | 50-59 | Skiing | 80-99K |
| 1245 | Joint | No | Online | 3.6 | M | 20-29 | Golf | 20-39K |
| 2110 | Individual | Yes | Broker | 22.3 | M | 30-39 | Fishing | 40-59K |
| 1001 | Individual | Yes | Online | 5.0 | M | 40-49 | Golf | 60-79K |

Bu veri setinde yatırım hesabı açan müşterilerin hesap türü ve işlem yöntemi (transaction method) gibi bilgiler vardır. İşlem yöntemi, müşterinin telefonla bir yatırım uzmanı (broker) üzerinden mi yoksa çevrim içi uygulamalar üzerinden kendisi mi işlem yaptığını gösterir. Yatırımcılar davranışlarına, cinsiyetlerine, yaş aralıklarına ve yıllık gelirlerine bakılarak gruplanabilir: örneğin üç gruba ayırıp hangi müşterilerin birbirine benzediğini, hangilerinin yatırımlarının daha büyük olduğunu incelemek ve bir gruptaki müşteriyi diğerine çekmek için alternatif öneriler sunmak.

### 8.2 Etiketsiz veride eğiticili yöntem

Bu veri setinde daha çok eğiticisiz kümeleme yapılır, ama eğiticili öğrenme de çalıştırılabilir: var olan sütunlardan biri çıktı değişkeni seçilir, diğerleri girdi değişkeni kabul edilir ve bir sınıflandırma yöntemi çalıştırılır. Slayttaki soru buna örnektir: "Can I develop a general profile of an online investor?" Yani yatırımlarını çevrim içi yapan bir müşterinin genel profili nedir? Burada işlem yöntemi sütunu çıktı değişkeni olarak seçilir.

Hoca, "veri setinde etiket yok" dediği halde sınıflandırmadan söz etmesini şöyle açıkladı: normalde etiket bir uzman tarafından konur; ama sütunlardan biri çıktı kabul edilip diğerleri girdi sayılırsa eğiticili bir yöntem de çalıştırılabilir.

Eğiticisiz yöntemlerle aykırı değer tespiti (outlier detection) de yapılabilir. Aykırı değerler, dolandırıcılık tespitinde sözü edilen olağandışı örüntüleri (unusual pattern) bulmakta işe yarar.

## 9. Sınıflandırma, Kestirim ve Öngörü

Eğiticili öğrenmenin altındaki üç başlık, hangi koşulların geçerli olduğuna göre ayrılır.

### 9.1 Sınıflandırma (Classification)

"Data Mining Strategies: Classification" slaytı (ekrandan, 01:00:00):

- Learning is supervised: öğrenme eğiticilidir.
- The dependent variable is categorical: bağımlı değişken kategoriktir.
- Well-defined classes: sınıflar iyi tanımlıdır.
- Current rather than future behavior: gelecekteki değil mevcut davranış.

Hoca burada yeni bir kavram olarak bağımlı değişkeni (dependent variable) tanıttı. Daha önce girdi ve çıktı değişkeninden söz edilmişti; teşhis örneğinde doktorun koyduğu teşhis bağımlı değişkendir. Yani çıktı değişkeni için burada bağımlı değişken denmektedir. Bağımlı değişken kategorikse, yani sayısal değil de soğuk algınlığı, alerji, boğaz enfeksiyonu gibi değerler alıyorsa yapılan iş sınıflandırmadır.

İyi tanımlı sınıflar, çıktı değişkenindeki sınıfların (burada üç sınıf) baştan tanımlanmış olması ve veri setinde her biri için yeterli sayıda örnek bulunması demektir. "Mevcut davranış" maddesi ise sınıflandırmanın geleceğe dönük bir tahmin olmadığını anlatır: hastaya şikayetleri sorulur ve o anki durumuna göre hangi hastalığın var olduğu tahmin edilir.

### 9.2 Kestirim (Estimation)

Kestirimi sınıflandırmadan ayıran şey bağımlı değişkenin sayısal olmasıdır. Hocanın örneği: bir aracın motor hacmini, dizel mi benzinli mi olduğunu, otomatik mi olduğunu ve başka pek çok parametresini biliyoruz; aracın o anki hızını da biliyoruz. Bu verilerle aracın o hızda giderken anlık ne kadar yakıt tükettiği tahmin edilebilir. Burada da geleceğe dönük bir şey yapılmaz; o anki hıza ve aracın teknik özelliklerine göre yakıt tüketimi kestirilir.

### 9.3 Öngörü (Prediction)

"Data Mining Strategies: Prediction" slaytı (ekrandan, 01:05:00):

- The emphasis is on predicting future rather than current outcomes: vurgu mevcut değil gelecekteki sonuçları tahmin etmektedir.
- The output attribute may be categorical or numeric: çıktı özniteliği kategorik ya da sayısal olabilir.

Geleceğe dönük bir tahmin yapılıyorsa işlemin adı öngörüdür. Hocanın örneği hava tahminidir: "Yarın en düşük sıcaklık 19 derece, en yüksek 24 derece olacak" geleceğe dönük ve sayısal bir öngörüdür. "Yarın hava yağmurlu, güneşli ya da sisli olacak" ise geleceğe dönük ama kategorik bir öngörüdür.

> **Hocanın vurgusu:** Türkçede "estimation" ve "prediction" ikisi de "tahmin" ya da "kestirim" diye çevrildiği için aradaki fark kaybolur. Ayırt edici nokta, tahminin mevcut durum için mi yoksa gelecek için mi yapıldığıdır.

Özetle eğiticili öğrenmenin altında üç kavram tanımlandı:

| Strateji | Bağımlı değişken | Zaman |
|---|---|---|
| Sınıflandırma | Kategorik | Mevcut durum |
| Kestirim | Sayısal | Mevcut durum |
| Öngörü | Kategorik ya da sayısal | Gelecek |

## 10. Market Sepeti Analizi

Üçüncü strateji market sepeti analizidir. Burada birliktelik kurallarına bakılır: mağazalarda satılan perakende ürünlerden hangilerinin birlikte daha çok satın alındığı bulunur ve aralarındaki ilişkiye bakarak satışları artırmaya yönelik stratejiler geliştirilir.

Hocanın aktardığı, artık şehir efsanesine dönmüş klasik örnek: Amerika'da yapılan bir araştırmada orta yaşlı evli erkeklerin cuma akşamları iş çıkışı hafta sonu için market alışverişi yaptıkları ve en çok birlikte aldıkları iki ürünün bira ve bebek bezi olduğu bulunmuş. Bu bilgi pazarlama açısından bir stratejiye dönüşebilir:

- Bu iki ürün broşürlerde bir araya getirilip birlikte indirime sokulabilir ve satışları artırılabilir.
- Ya da reyonlar düzenlenirken iki ürün birbirinden olabildiğince uzağa konur; birini alan öbürünü de alacağı için marketi daha çok gezer ve daha çok alışveriş yapar.

Bu iş için geliştirilmiş algoritmalardan Apriori ve FP-Growth derste ele alınacaktır.

## 11. Üretim Kuralları: Doğruluk ve Kapsayıcılık

### 11.1 Kredi kartı promosyonu veri seti

Son örnek "The Credit Card Promotion Database" tablosudur (ekrandan, 01:10:00). Öğrencilere veri setinde kaç örnek olduğu soruldu; cevap 15'tir.

| # | Income Range | Magazine Promotion | Watch Promotion | Life Insurance Promotion | Credit Card Insurance | Sex | Age |
|---|---|---|---|---|---|---|---|
| 1 | 40-50K | Yes | No | No | No | Male | 45 |
| 2 | 30-40K | Yes | Yes | Yes | No | Female | 40 |
| 3 | 40-50K | No | No | No | No | Male | 42 |
| 4 | 30-40K | Yes | Yes | Yes | Yes | Male | 43 |
| 5 | 50-60K | Yes | No | Yes | No | Female | 38 |
| 6 | 20-30K | No | No | No | No | Female | 55 |
| 7 | 30-40K | Yes | No | Yes | Yes | Male | 35 |
| 8 | 20-30K | No | Yes | No | No | Male | 27 |
| 9 | 30-40K | Yes | No | No | No | Male | 43 |
| 10 | 30-40K | Yes | Yes | Yes | No | Female | 41 |
| 11 | 40-50K | No | Yes | Yes | No | Female | 43 |
| 12 | 20-30K | No | Yes | Yes | No | Male | 29 |
| 13 | 50-60K | Yes | Yes | Yes | No | Female | 39 |
| 14 | 40-50K | No | Yes | No | No | Male | 55 |
| 15 | 20-30K | No | No | Yes | Yes | Female | 19 |

(Satır numaraları okumayı kolaylaştırmak için eklendi; slaytta yoktur.)

Kart sahiplerinin gelir aralığı, cinsiyeti ve yaşı vardır. Onlara üç promosyon sunulmuştur: dergi, saat ve hayat sigortası promosyonu; promosyonu kabul edenler "Yes", etmeyenler "No" ile gösterilmiştir. Ayrıca kartın çalınması durumunda koruma sağlayan kredi kartı sigortası sütunu vardır.

### 11.2 Üretim kuralları ve iki ölçüt

Yılların bankacısı ya da bir mağaza müdürü, satışlara zamanla aşina olur ve "müşteri şu yaş aralığındaysa şuna bakar, kadınsa buna, erkekse şuna" gibi kuralları kafadan söyleyebilir hale gelir. Bu tür kurallar "IF ... THEN ..." biçiminde üretim kuralı (production rule) olarak yazılır ve iki ölçütle değerlendirilir:

- **Kural doğruluğu (rule accuracy):** Kuralın IF kısmına uyan örneklerden kaçında THEN kısmının gerçekten doğru olduğu.
- **Kural kapsayıcılığı (rule coverage):** THEN kısmındaki sınıfa ait bütün örneklerden kaçının kural tarafından doğru yakalandığı.

$$\text{doğruluk} = \frac{\text{IF ve THEN kısmına uyan örnek sayısı}}{\text{IF kısmına uyan örnek sayısı}}, \qquad \text{kapsayıcılık} = \frac{\text{IF ve THEN kısmına uyan örnek sayısı}}{\text{THEN sınıfındaki örnek sayısı}}$$

(Formül yazımı eklendi; tanımlar derste sayılarla anlatıldı.)

### 11.3 Birinci kural (derste hoca çözdü)

Kural: IF cinsiyet = kadın ve yaş 19 ile 43 arasında THEN hayat sigortası promosyonu = evet.

1. Veri setindeki kadın sayısı: 7 (bir öğrenci cevapladı).
2. Bu 7 kadının yaşları: 40, 38, 55, 41, 43, 39, 19. Sınırlar dahil olduğu için 43 ve 19 da koşula girer; yalnız 55 yaşındaki kadın kapsam dışıdır. IF kısmına uyan örnek: 6.
3. Bu 6 kadının hayat sigortası promosyonu değeri tek tek kontrol edilir: altısı da "Yes" demiştir.
4. Doğruluk: $6/6 = \%100$.
5. Veri setinde hayat sigortası promosyonuna "Yes" diyen kişi sayısı: 9 (bir öğrenci cevapladı).
6. Kapsayıcılık: $6/9 \approx \%66{,}7$.

Yani kural yazdığı her şeyde doğrudur, ama evet diyen 9 kişinin yalnız 6'sını yakalayabilmektedir.

**Soru:** Kapsayıcılığın %66 çıkması kuralın kullanılabilir olup olmadığı hakkında ne söyler? **Cevap:** Hayat sigortası promosyonu sütununda evet diyen 9 kişi vardır ve kural bunların 6'sını bulabilmiştir; 3 kişiyi bulamamıştır. Bu 3 kişiyi kapsayacak başka kurallar yazmak gerekir. Bir grup tek bir kuralla değil, bir dizi kuralla doğru tahmin edilir.

### 11.4 İkinci kural (öğrencilere bırakıldı, birlikte çözüldü)

Kural (ekrandan, 01:20:00): IF cinsiyet = erkek ve gelir aralığı = 40-50K THEN hayat sigortası promosyonu = hayır.

1. Veri setindeki erkek kart kullanıcısı sayısı: 8 (bir öğrenci cevapladı).
2. Bunlardan gelir aralığı 40-50K olanlar: 1, 3 ve 14 numaralı satırlar (45, 42 ve 55 yaş). IF kısmına uyan örnek: 3.
3. Üçü de hayat sigortası promosyonuna "No" demiştir.
4. Doğruluk: $3/3 = \%100$.
5. Hayat sigortası promosyonuna "No" diyen toplam kişi sayısı: 6 (1, 3, 6, 8, 9 ve 14 numaralı satırlar).
6. Kapsayıcılık: $3/6 = \%50$.

Slayttaki sonuç da "Rule Accuracy: 100 %, Rule Coverage: 50 %" şeklindedir. Hesaplar ajan tarafından tablo üzerinden python ile doğrulandı.

> **Ders sonrası not:** Altyazıda bu kural çözülürken bazı satırlar için "30-40 bin" geçiyor ve doğruluk için "3 bölü 8" deniyor. Kuralın IF kısmı 40-50K gelirli erkekleri seçer; tabloda bu koşulu sağlayan üç satırın üçünün de geliri 40-50K'dır. Doğruluğun paydası tüm erkeklerin sayısı (8) değil, IF kısmına uyan örneklerin sayısıdır (3). Sonuç (%100 doğruluk, %50 kapsayıcılık) değişmez.

> **Ek bilgi (derste anlatılmadı):** Doğruluk ile kapsayıcılık arasında genelde bir denge vardır: koşulları sıkılaştırılan bir kural daha az örneğe uyar ve doğruluğu artabilirken kapsayıcılığı düşer. Bu yüzden kural tabanlı sınıflandırıcılar, sınıfın tamamını kapsamak için birden fazla kuraldan oluşan kural kümeleri üretir.

## Örnek Sorular

**Soru 1** (derste sözlü, 00:39:43): Çalıntı kredi kartlarıyla yapılan işlemlerde ilk işlemin akaryakıt istasyonunda küçük bir alım, ikincisinin hemen ardından limit kadar elektronik ürün alımı olduğu gözlenmiştir. Dolandırıcı neden önce akaryakıt istasyonuna gidiyor olabilir?

> **Çözüm (derste verildi):** Kartın çalışıp çalışmadığını (ödeme yapılabildiğini) kontrol etmek için. Kart çalışmıyorsa ya da durum fark edilmişse akaryakıt istasyonundan kolayca uzaklaşılabilir; kart çalışıyorsa hemen ardından limit kadar alışveriş yapılır.

**Soru 2** (ekrandan, 00:45:00; derste sözlü, 00:50:47): Hastalık teşhisi eğitim verisinden kurulan karar ağacı kökte Swollen Glands, ikinci düzeyde Fever özniteliğini test etmektedir. Yeni gelen hastalardan bezleri şiş olan, bezleri şiş olmayıp ateşi olan ve ikisi de olmayan hastalar hangi sınıfa atanır?

> **Çözüm (derste verildi):** Bezleri şiş olan hasta Strep throat; bezleri şiş olmayıp ateşi olan Cold; ikisi de olmayan Allergy.

**Soru 3** (ekrandan, 01:10:00): Kredi kartı promosyonu veri setinde kaç örnek vardır?

> **Çözüm (derste verildi):** 15.

**Soru 4** (derste sözlü, 01:11:28; tablo ekrandan, 01:10:00): IF cinsiyet = kadın ve yaş 19-43 THEN hayat sigortası promosyonu = evet kuralının doğruluğunu ve kapsayıcılığını bulun.

> **Çözüm (derste verildi):** IF kısmına 6 kadın uyar ve altısı da evet demiştir: doğruluk %100. Evet diyen toplam 9 kişiden 6'sı kapsanır: kapsayıcılık yaklaşık %66,7.

**Soru 5** (ekrandan, 01:20:00): IF cinsiyet = erkek ve gelir aralığı = 40-50K THEN hayat sigortası promosyonu = hayır kuralının doğruluğunu ve kapsayıcılığını bulun.

> **Çözüm (derste verildi):** IF kısmına 3 erkek uyar ve üçü de hayır demiştir: doğruluk %100. Hayır diyen toplam 6 kişiden 3'ü kapsanır: kapsayıcılık %50.

## Dersin Toparlaması

Bu ilk derste veri madenciliği, büyük miktardaki veriden anlamlı bilgi keşfetme süreci olarak tanımlandı; KDD gibi eş anlamlı adları, verinin sağlık, ticaret, bilim ve sosyal medyadaki patlayıcı büyümesi ve pazarlama, risk yönetimi, dolandırıcılık tespiti gibi uygulama alanları ele alındı. Dersin omurgası veri madenciliği stratejileri ağacıdır: eğiticisiz kümeleme, eğiticili öğrenme (sınıflandırma, kestirim, öngörü) ve market sepeti analizi. Eğiticili öğrenme hastalık teşhisi verisi ve ondan kurulan karar ağacıyla, eğiticisiz kümeleme yatırımcı veri setiyle örneklendi; sınıflandırma, kestirim ve öngörü bağımlı değişkenin türüne ve tahminin mevcut durum mu gelecek mi olduğuna göre ayrıldı.

Son olarak kredi kartı promosyonu veri seti üzerinde üretim kuralları yazıldı ve her kural doğruluk ile kapsayıcılık ölçütleriyle değerlendirildi. Sonraki derslerde veri ön işleme (veri azaltma, ayrıklaştırma, normalizasyon) ile başlanacak, ardından karar ağaçlarının matematiği, Bayes sınıflandırma, kümeleme algoritmaları, Apriori ve öneri sistemleri gelecektir.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
