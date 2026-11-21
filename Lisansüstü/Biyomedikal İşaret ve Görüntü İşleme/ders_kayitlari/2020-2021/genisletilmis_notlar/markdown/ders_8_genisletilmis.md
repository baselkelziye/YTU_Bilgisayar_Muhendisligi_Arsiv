# Ders 8 Genişletilmiş Notu: Makine Öğrenmesine Giriş: Örüntü Tanıma Sisteminin Bileşenleri, Öznitelik Çıkarımı, PCA ve LDA

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Derse Giriş ve Kaynak
- 2. Biyomedikal Veride Makine Öğrenmesinin Amacı
- 3. Biyomedikal Veri Tipleri
- 4. Veri Matrisi, Öznitelik Vektörü ve Etiket
- 5. Patoloji Görüntüsünde Örnek Bir Problem
- 6. Piksel Sınıflama, Eğiticili ve Eğiticisiz Öğrenme
- 7. İnsan Gözü ile Bilgisayar Arasındaki Fark ve Son İşleme, Ön İşleme
- 8. Eğitim, Test ve Başarının Ölçülmesi
- 9. Öznitelik Uzayı ve Karar Sınırları
- 10. Örüntü Tanıma Sisteminin Bileşenleri
- 11. Öznitelik Çıkarımı, Öznitelik Seçimi ve Boyut Azaltma
- 12. Temel Bileşen Analizi (PCA) ve Doğrusal Ayırtaç Analizi (LDA)
- Örnek Sorular

## 1. Derse Giriş ve Kaynak

Bu ders, dönemin ikinci yarısındaki proje çalışmalarına hazırlık olarak makine öğrenmesine genel bir giriş niteliğindeydi. Hoca, ders sayfasına iki kaynak yüklediğini söyledi: "Machine Learning: An Overview" başlıklı bir sunum (ekrandan, 00:15:00) ve Robi Polikar'ın "Pattern Recognition" başlıklı makalesi (ekrandan, 00:10:00). Polikar'ın makalesi örüntü tanımanın temel kavramlarını, bir örüntü tanıma sisteminin bileşenlerini ve öznitelik çıkarımı yöntemlerini derli toplu anlatır. Dersin ikinci yarısında hoca bu makaleyi ekranda açarak üzerinden anlattı. Hoca, sunumun karar ağaçlarından başlayarak diğer yöntemlere kadar temel kavramları geniş kapsamlı anlattığını belirtti. <!-- BELİRSİZ: 00:14:23'te altyazı "Misition Trilerden başlıyor" diyor; büyük olasılıkla "Decision Tree'lerden" kastediliyor. -->

Anlatımın büyük bölümü Microsoft Whiteboard üzerinde çizimlerle yapıldı.

## 2. Biyomedikal Veride Makine Öğrenmesinin Amacı

Hoca anlatıma bir EKG örneğiyle başladı. Kalp verisinde tekrar eden atımlar vardır; bu atımlar belirli segmentlere bölünerek bir veri seti oluşturulabilir. Derste daha önce kullanılan veri setinde 256 uzunluklu çerçevelere bölünmüş QRS kompleksleri vardı ve normal atımın yanında taşikardi gibi hastalık örnekleriyle birlikte 6 ya da 9 sınıf bulunuyordu.

Doktorlar bu sınıfları ayırırken görsel tecrübelerine dayanırlar. Bir atıma baktıklarında belirli yapılanmalara, atımın süresine, eğimine gibi ayırt edici özelliklere bakarak karar verirler. Makine öğrenmesinin sorduğu soru şudur: **bir doktorun tecrübeyle öğrendiği bu ayırt etme becerisi makineye öğretilebilir mi?**

Hoca, makine öğrenmesi (machine learning), örüntü tanıma (pattern recognition) ve veri madenciliğinin (data mining) birbirine çok yakın, ortak konulara sahip alanlar olduğunu söyledi. Bunların hepsinin üst çatısı veri mühendisliği ya da veri bilimidir (data science); veri bilimine ayrıca istatistik ve matematiksel modelleme gibi kavramlar da girer (ekrandan, 00:25:00).

Bu alandaki amaç, sayısallaştırılmış biyomedikal veriyi en iyi şekilde değerlendirerek doktora yardımcı bir sistem kurmaktır. Bu sistemler iki başlıkta anılır:

- Bilgisayar destekli teşhis (computer-aided diagnosis, CAD) sistemleri.
- Karar destek sistemleri (Decision Support System, DSS) (ekrandan, 00:30:00).

<!-- BELİRSİZ: 00:25:15'te altyazı "CAT sistemleri" diyor; bağlamdan büyük olasılıkla CAD (bilgisayar destekli teşhis) kastediliyor. -->

## 3. Biyomedikal Veri Tipleri

### 3.1 Bir boyutlu işaretler

EKG, EEG (beyin sinyalleri) gibi işaretler bir boyutludur. Bunlar dış dünyadan problarla alınıp sayısallaştırılır.

### 3.2 İki boyutlu görüntüler

Ultrason, MR, bilgisayarlı tomografi ve mikroskop gibi biyomedikal cihazlar çeşitli arabirimlerle sayısallaştırılır (ekrandan, 00:25:00). Sayısallaştırmayla birlikte bu görüntüleri bilgisayar ortamında analiz etme imkânı doğar. Kullanılan sensörün ya da modalitenin tipine göre, ultrasonda olduğu gibi gri seviyeli görüntüler alınabileceği gibi renkli görüntüler de alınabilir.

### 3.3 Üç boyutlu (hacimsel) veri

MR'da hasta kesit kesit (slice) taranır. Hoca bunu karaciğer üzerinden anlattı: birinci kesitte karaciğerin küçük bir kısmı görünür, alttaki kesitte daha geniş bir kısmı, sonra yine daralmaya başlar. Her kesit, organı bıçakla kesiyormuşsunuz gibi X-Y düzlemindeki görüntüsünü verir. Kesitler üst üste konduğunda X, Y, Z eksenlerinde görülebilen hacimsel (volümetrik) bir veri küpü oluşur (ekrandan, 00:30:00). Bu tür veriler üzerinde de çalışılabilir.

Hangi veri tipi seçilirse seçilsin, sonuçta bundan bir veri seti oluşturulur ve sorulan soru bu veri setinin nasıl değerlendirileceğidir.

## 4. Veri Matrisi, Öznitelik Vektörü ve Etiket

### 4.1 Ham veriyle veri seti oluşturma

Hoca, hiçbir öznitelik çıkarımı yapmadan, yalnız ön işlemeyle elde edilen ham veriyle çalışmanın mümkün olduğunu söyledi. Tahtada üç ayrı EKG atımı çizdi; her biri 1'den 256'ya kadar giden 256 örnekliktir (ekrandan, 00:30:00). Bu atımlar bir dizi (array) olarak saklanırsa saklanan şey genlik değerleridir: örneğin ilk değer 0, sonra 0.1, 0.2, atımın tepesinde 0.9 gibi büyük bir değer.

Bu parçalar alt alta konduğunda N örneklik bir veri seti oluşur. İçinde hem hastalıklı hem hastalıksız örnekler bulunabilir. Ayrıca yardımcı bir vektörde her örneğin tipi saklanır: örneğin 1, 1, 3, 2 gibi hastalık çeşitleri. Bunlar etiketlerdir (label).

### 4.2 Satırlar örnek, sütunlar öznitelik

Bu şekilde bir boyutlu işaretten iki boyutlu bir matris elde edilir. Makine öğrenmesinde genel kural şudur:

- Satırlara **örnek** (sample) denir.
- Sütunlara **öznitelik** (feature, özellik, properties) denir. Ham EKG örneğinde bir sütun, belirli bir andaki genlik değeridir; örneğin hastalıklı atımlarda bazı sütunlarda yükselme görülür.
- Tek bir örneğe ait satır, o örneği oluşturan özniteliklerin yan yana dizildiği **öznitelik vektörüdür** (feature vector).

Matris $N\times d$ boyutundadır: $N$ örnek sayısı, $d$ öznitelik sayısıdır. Bunun yanında $N\times 1$ boyutunda bir etiket vektörü bulunur; her satırı ilgili örneğin hangi tipte olduğunu söyler.

### 4.3 Gösterim

Dersin ikinci yarısında hoca gösterimi tahtaya yazdı (ekrandan, 01:20:00). Bilimsel yazılarda matrisler büyük harfle yazılır ve boyutları şu şekilde belirtilir:

$$X \in \mathbb{R}^{N\times d}$$

Matrisi oluşturan her bir öznitelik vektörü küçük harfle gösterilir:

$$x \in \mathbb{R}^{d}$$

Etiket vektörü ise

$$y \in \mathbb{R}^{N}$$

biçimindedir, çünkü toplam $N$ örnek vardır ve her birinin bir etiketi bulunur.

Hoca, eğitim verisi oluşturulurken çeşitli yapılar (structure) kullanılabileceğini söyledi. En basiti, `train.X` ve `train.y` gibi bir yapı içinde veriyi ve etiketleri birlikte tutmaktır (ekrandan, 01:20:00).

## 5. Patoloji Görüntüsünde Örnek Bir Problem

### 5.1 Problem tanımı uygulamaya bağlıdır

EKG örneğindeki problem bir sınıflandırma problemiydi: sistem hastalıklı ve hastalıksız örneklerle eğitilir, yeni gelen bir atımın hangi hastalık tipine ait olduğu bulunur. Hoca bu kez farklı bir probleme geçti ve problemin tanımının, doktorun neye ihtiyaç duyduğuna ya da teşhise hangi aşamanın yardımcı olacağına göre değiştiğini vurguladı.

### 5.2 Dokudan görüntüye

Mikroskopla bir kanser hastalığı araştırıldığını düşünelim. İlk problem, kanserin varlığını ve slayt üzerindeki dağılımını bulmak olabilir. Bu aşamaya gelene kadar şunlar olur:

- Hastadan bir doku alınır ve lamelin altına yerleştirilir.
- Doku, arka planı ve hücreleri (hücre çekirdeğindeki DNA'yı) farklı renge boyayan boyalarla boyanır.

Hoca ekranda örnek patoloji görüntüleri gösterdi (ekrandan, 00:50:00). Görüntülerde iki tip boya vardı: biri mavi ağırlıklı, diğeri kırmızı ağırlıklı. Hücre merkezlerindeki farklı yapılar yüzünden hücreler farklı renk almış, aradaki epitel dokular başka renklere girmiş, yağ doku ya da boşluk gibi bölgeler ise renk almamıştı.

Doktor burada mitoz, farklı hücre yapılanmaları ya da dağılımları, hücrelerin morfolojik özelliklerindeki değişiklikler, yoğunlaşma (proliferasyon) ve anormal yapılar arar. İnsan gözüyle bakıldığında problemin ilk adımı hücreleri arka plandan ayırmaktır; ardından hücrelerin yapısı ve dağılımı hakkında fikir edinilir. Hoca boyamanın kendisinin de bir ön işleme adımı olduğunu belirtti: boyama sayesinde hücreler daha rahat ayrılır.

### 5.3 Tam slayt, patch ve ilgi bölgesi

Boyanan doku yüksek çözünürlüklü bir tarayıcıya girer ve tüm slayt yüksek çözünürlükte taranır. Ortaya çok büyük bir görüntü çıkar; tahtadaki örnekte 10.000 x 10.000 piksel (ekrandan, 01:05:00). Buna tam slayt görüntüsü (whole slide image) denir.

Bütün görüntüyü alıp eğitmek mümkün değildir. Bu yüzden bir uzman önce bakılacak bölgeleri belirler ve "şu bölgeyle çalışalım" diyerek parçalar (patch) seçer. Bu bölgelere ilgi bölgesi (Region of Interest, RoI) de denir. Veri seti bu noktadan sonra oluşur. Uzman her patch'e bir etiket verir; tahtadaki örnekte normal (N, 0), normal ile hastalıklı arası (N-H, 1) ve hastalıklı (H, 2) olmak üzere ara sınıflar da tanımlanmıştı (ekrandan, 00:40:00).

Bu patch'ler örneğin bir derin öğrenme modeline verilerek doğrudan sınıflanabilir.

### 5.4 Problem bölütlemeye dönüşebilir

Hoca, aynı görüntüde farklı bir görev verildiğinde problemin değiştiğini gösterdi: "önce hücreleri tespit et" denirse bu artık bir sınıflandırma problemi değil, bir bölütleme (segmentation) problemidir. Patch'ler aslında üç katmanlı (R, G, B) renkli görüntülerdir (ekrandan, 00:35:00).

Hücreyi arka plandan ayırmak göründüğü kadar kolay değildir. Hoca ekrandaki görüntüde gösterdi: bazı hücreler belirgin, ama bazı hücrelerin bir kısmının rengi arka plandaki renkle aynı; bazı hücreler soluk çıkmış; bazı hücrelerin bir bölümü daha parlak ve arka plana benziyor. Yani her hücre aynı netlikte görünmez ve soru işaretleri oluşur.

## 6. Piksel Sınıflama, Eğiticili ve Eğiticisiz Öğrenme

### 6.1 Pikselden eğitim matrisi

Bölütleme için bir yaklaşım, her pikseli bir örnek olarak düşünmektir. En temelde bir pikselin üç özniteliği vardır: R, G ve B değerleri. Hoca tahtada şu tabloyu kurdu (ekrandan, 00:45:00):

| Seçilen piksel | Öznitelikler | Etiket |
|---|---|---|
| Hücre içinden 1. piksel | R, G, B | 1 (hücre) |
| Hücre içinden 2. piksel | R, G, B | 1 (hücre) |
| Arka plandan 1. piksel | R, G, B | 0 (hücre değil) |
| Arka plandan 2. piksel | R, G, B | 0 (hücre değil) |

Böylece EKG örneğindeki mantıkla aynı şekilde bir eğitim matrisi ve etiket vektörü elde edilir. Hoca, bu yapıların uygulamaya bağlı olarak kurulduğunu vurguladı.

### 6.2 Eğiticili ve eğiticisiz algoritmalar

Bu tür verilerle iki tür algoritma çalışabilir:

- Etiketleri kullanmadan, hücresel yapının hücresel olmayan yapıdan farklı olduğunu kendisi bulan algoritmalar. Bunlara **eğiticisiz** (unsupervised) algoritmalar denir.
- Etiket bilgisini kullanan algoritmalar. Bunlara **eğiticili** (supervised) algoritmalar denir.

Bunlar için "güdümlü" ve "güdümsüz" öğrenme terimleri de kullanılır; güdümlü, bir eğitimin yapıldığını, güdümsüz ise eğitim yapılmadığını anlatır.

## 7. İnsan Gözü ile Bilgisayar Arasındaki Fark ve Son İşleme, Ön İşleme

### 7.1 Bölütleme sonrasında kalan sorunlar

Algoritma hücreleri bulsa bile sonuç kusurlu olabilir: hücrelerin içinde boşluklar kalabilir (hücrenin bir kısmı arka plan olarak işaretlenmiştir), şekil tam bulunamayabilir ya da sınırlar iyi çıkmayabilir.

### 7.2 Son işleme (post-processing)

Bu sorunları düzeltmek için ikinci bir algoritma grubu çalıştırılır: hücre içindeki boşlukları giderip tam bir hücre haline getirme, kenarları düzeltme gibi. Bunlara son işleme (post-processing) yöntemleri denir (ekrandan, 01:20:00).

### 7.3 İnsan beyni neye bakıyor?

Hoca, bu dersin amacının makinenin insan gözüne ve beynine yakın kararlar verebilmesini sağlamak olduğunu söyledi. Bir çocuğa bile "şu hücreleri işaretle" dense, hücrelerin sınırını hiç zorlanmadan çizer; üst üste binen hücreleri ayırır, bulanıklığa rağmen sınırı doğru çizer. Ama bunu bilgisayara anlatmak ayrı bir iştir, çünkü bilgisayara kurallı komutlar dizisiyle anlatmak gerekir.

Hoca burada öğrencilere bir soru sordu (bkz. Örnek Sorular): hücreyi çevrelerken yalnız rengine mi bakıyoruz? Bir öğrenci renk ya da parlaklık değişim oranına, köşe bulur gibi bakıldığını söyledi. Hoca şöyle açıkladı: hücrenin bir bölgesi açık renkli olup arka planla aynı renkte görünse bile biz onu hücrenin içine alarak çevreleriz. Çünkü yalnız piksel rengine değil, **çevre piksellerin dağılımına** da bakarız: yuvarlak bir yapı var, içinde ona aykırı bir renklenme var, ama biz bunu da dikkate alarak kontürü kafamızda belirleriz. Yani beynimiz farklı öznitelikler de üretir.

Hoca bunu bir örnekle somutlaştırdı: hücre içi morlardan, arka plan pembeden oluşsun. Hücrenin ortasında tek bir piksel pembe çıksa, onu hücre dışı mı sayacağız? Görüntü sonuçta bir tarayıcının sensöründen geçer ve sensör yüzde yüz doğruluk vermez. Etrafındaki bütün pikseller mor olduğuna göre, insan gözü bunun bir yanlışlık olduğunu anlar ve pikseli hücre içi sayar.

Bu yüzden öznitelik vektörü yalnız merkez pikselin RGB değerleriyle sınırlı kalmayabilir; çevre piksellerin değerleri de eklenerek büyütülebilir. Bu tür uzamsal öznitelik çıkarma algoritmaları, pikselin etrafındaki piksellerin dağılımını ve yerleşimini dikkate alır.

### 7.4 Ön işleme (preprocessing)

Hoca, öznitelik çıkarmadan önce işi kolaylaştıracak işlemlerin de yapılabileceğini söyledi: gürültü giderilebilir, filtreler uygulanarak geçişler yumuşatılabilir. Amaç, işleme aşamasında daha kaliteli sonuçlar almaktır. Bunlara ön işleme (preprocessing) yöntemleri denir (ekrandan, 00:55:00).

### 7.5 Basit bir kararın arkasındaki karmaşıklık

Hoca, basit görünen bir kararın arkasında aslında pek çok adım olduğunu vurguladı: patch'lerin oluşturulması, özniteliklerin ve çevre piksel ilişkilerinin kurulması, modelleme, bölütleme ve son işleme. Doktorun bir EKG'ye bakıp verdiği karar da aslında birçok tecrübenin ürünüdür. Algoritmalar tecrübeyle birleştirildiğinde buna **model eğitimi** denir; bir anlamda tecrübe, modeller aracılığıyla bilgisayara öğretilir.

Doktordan doktora kararlar değişebilir, çünkü her biri beynini farklı verilerle eğitmiştir. Biri bir görüntüye "ara durum değil, normal" derken, daha önce gördüklerine benzediği için bir başkası "kesinlikle kanserli" diyebilir.

Büyük görüntülerde doktorun zamanı çok değerlidir. Doktorun dikkatini anormal bölgelere çeken yardımcı bir sistem büyük zaman kazandırır. Hoca, böyle bir sistemle bir saatte bir hasta yerine 12 hastaya bakılabileceğini ve bunun yüzde 1200 kazanç anlamına geldiğini söyledi.

> **Ders sonrası not:** Hoca 1 yerine 12 hastaya bakılmasını "yüzde 1200 kazanç" olarak ifade etti. Bu, verimin 12 katına çıkması demektir; artış oranı olarak ifade edilirse $(12-1)/1 = $ yüzde 1100 artıştır.

## 8. Eğitim, Test ve Başarının Ölçülmesi

Aradan sonra hoca, öğrencilere özetini çıkarmalarını istediği Polikar makalesinin bu akışların teorik altyapısını iyi özetlediğini söyledi ve gösterimi yeniden ele aldı (bkz. 4.3).

Eğitim verisi (`train.X`, `train.y`) modele verilir ve model eğitilir. Ardından test verisi (`test.X`) modele verilir ve modelin tahminleri, yani $\hat{y}$ (y-predicted) elde edilir. Test verisinin gerçek etiketleri $y$ elimizdeyse, tahminler bunlarla karşılaştırılarak modelin yüzde kaç başarılı olduğu hesaplanır (ekrandan, 01:20:00).

## 9. Öznitelik Uzayı ve Karar Sınırları

### 9.1 Öznitelik vektörü uzayda bir noktadır

Hoca, piksel örneğine dönerek $d=3$ (R, G, B) alındığında üç eksenli bir uzay oluştuğunu gösterdi (ekrandan, 01:20:00). Bir vektörün R, G ve B değerleri bu eksenler üzerinde işaretlendiğinde vektör uzayda tek bir noktaya karşılık gelir.

Eksenlerin birbirine dik çizilmesinin nedeni, özniteliklerin birbirinden bağımsız varsayılmasıdır: bir pikselin R değeri G değerine, G değeri B değerine bağlı değildir. Öznitelik sayısı 4, 5 ya da $d$ olduğunda bunu çizmek mümkün değildir, ama mantık aynıdır: her öznitelik vektörü $d$ boyutlu uzayda bir nokta oluşturur ve merkezden belirli bir uzaklıktadır.

Hoca terimleri de netleştirdi: İngilizcede "feature", Türkçede "özellik" ya da "öznitelik" terimleri kullanılır.

### 9.2 Sınıflar uzayda kümelenir

Polikar'ın makalesindeki Şekil 2 üzerinden anlatım devam etti (ekrandan, 01:25:00). İki öznitelik (Sensör 1 ve Sensör 2 ölçümleri) ve dört sınıf vardır. Hoca sınıfları normal (N) ve üç hastalık tipi (H1, H2, H3) olarak adlandırdı. Öznitelikler sınıfları gerçekten ayırıyorsa, farklı sınıfların örnekleri uzayın farklı bölgelerinde yoğunlaşır. Etiket bilgisiyle (kare, üçgen, yuvarlak, yıldız) çizildiğinde aralarında belirli sınırlar oluştuğu görülür. Bu sınırlara **karar sınırı** (decision boundary) denir.

Etiketi bilinmeyen yeni bir test örneği geldiğinde, karar sınırları matematiksel olarak kurulabildiyse örneğin konumuna bakılır: hangi sınıfın sınırları içine düşüyorsa (örneğin H1) kararı o sınıf olarak verilir.

### 9.3 Hatalar sınırlarda oluşur

Sorun, test örneğinin tam karar sınırına ya da ona çok yakın bir yere düştüğünde ortaya çıkar. Hata oranları bu sınırlara yakın yerlerde başlar. Hoca bu yüzden başarının iki şeye bağlı olduğunu söyledi:

1. Toplanan örneklerin kalitesi ya da gerçekten ayrıştırılabilir olması: eğitim verisi dağılımı iyi temsil etmelidir.
2. Modelin karar sınırlarını iyi çizmesi.

### 9.4 Karar yüzeyleri ve hiperdüzlemler

Üç boyutlu uzayda sınıflar bu kez karar çizgileriyle değil, **karar yüzeyleriyle** (bir plaka gibi) ayrılır. Genel kural şudur:

- 2 boyutlu uzayda ayırıcılar sınırlardır (eğriler).
- 3 boyutlu uzayda ayırıcılar 2 boyutlu yüzeylerdir.
- 4 boyutlu uzayda 3 boyutlu, 5 boyutlu uzayda 4 boyutlu ayırıcılar gerekir.

Boyut arttıkça bu ayırıcılara genel olarak **hiperdüzlem** (hyperplane), yani çok boyutlu ayırıcı yüzey denir. Matematiksel modeller bu yüzeyleri bulur.

### 9.5 İç içe geçen sınıflar

Polikar'ın Şekil 3'ü gerçek verinin genellikle bu kadar düzgün ayrışmadığını gösterir (ekrandan, 01:30:00). Karar yüzeyi bir sınıfı en iyi kapsayacak şekilde en iyi biçimde çizilse bile, diğer sınıftan bazı örneklerin yüzeyin içine geçmesi kaçınılmazdır; bazı ödünler vermek gerekir. Bunun nedeni sensörlerden kaynaklanan hatalar ya da gerçekten birbirine çok benzeyen öznitelik dağılımlarıdır. Hoca bunu doktorlara benzetti: tecrübe ne kadar önemli olsa da bazen kesin cevap verilemez, ara sınıflar ve kararsız kalınan durumlar oluşur. Aynı durum modellerde de görülür. Bu yüzden modeli eğittiğimiz verinin, ayırmaya çalıştığımız sınıfları gerçekten ayırıp ayıramadığı önemlidir.

## 10. Örüntü Tanıma Sisteminin Bileşenleri

Hoca, Polikar'ın Şekil 4'ündeki akışı adım adım anlattı (ekrandan, 01:35:00 ve 01:40:00):

```text
Gerçek dünyadan bir sınıflandırma / karar verme problemi
  -> Veri toplama (Data Acquisition)
  -> Ön işleme (Preprocessing)
  -> Öznitelik çıkarımı (Feature Extraction)
  -> Öznitelik seçimi (Feature Selection)
  -> Model seçimi ve eğitim (Model Selection & Training)
  -> Değerlendirme (Evaluation)
  -> Çözüm
```

### 10.1 Gerçek dünya problemi ve veri toplama

Önce karar verilecek gerçek dünya problemi, yani analog sistem belirlenir. EKG örneğinde kalpte atım sırasında elektriksel potansiyeller oluşur; bunlar vücuda konulan problarla sürekli (analog) dünyadan sayısala çevrilir. Bu dönüşümü en iyi şekilde yapacak sistem, veri toplama (data acquisition) aşamasıdır. Burada sorulması gereken sorular şunlardır:

- Potansiyellerin değerleri nedir, hangi değer aralığında ölçülmelidir, anomaliler var mı?
- Probun tipi ne olmalı, prob ile vücut arasına iletkenliği artıracak bir madde sürülmeli mi?
- Ne kadar veri toplanmalı?
- Uygun örnekleme oranı, uygun genlik aralığında nicemleme (kuantalama) ve bit derinliği ne olmalı, hangi sensörler kullanılmalı?

### 10.2 Ön işleme

Toplanan uzun kayıt üzerinde ön işlemler yapılır (ekrandan, 01:40:00: "noise removal, filtering, normalization, outlier removal"):

- **Uygun segmentlere bölme.**
- **Gürültü giderme ve filtreleme.** Kalp atımı verisi hiçbir zaman saf gelmez; aletin gürültüsü üzerine biner. Örneğin 50 Hz'lik şebeke frekansı filtrelerle giderilmelidir. Kayıtta filtreden kaynaklanan salınımlar ya da taban kayması olabilir; belirli frekansların ve sensörden kaynaklanan istenmeyen bileşenlerin yok edilmesi gerekir. Aynı işlemler test verisine de uygulanabilir olmalıdır.
- **Normalizasyon.** Örneğin veri $[-1, 1]$ aralığında çalışılacaksa en büyük genlik $+1$'e, en küçük genlik $-1$'e çekilir.
- **Aykırı değer (outlier) temizliği.** Kayıtta aşırı yükselen ya da aşağı inen atımlar olabilir; normalde rastlanmaması gereken bu örnekler önce elenir ve veri iyice temizlenir.

### 10.3 Öznitelik çıkarımı

Hoca öğrencilerden kendilerini bir uzmanın yerine koymalarını istedi: uzman bir problemi gözle çözerken neye bakıyor? Örneğin bir atımın derinliğine, bir dalganın genişliğine ya da bir sürenin uzunluğuna bakıyor olabilir. Bunlar zaman uzayındaki özelliklerdir.

Bilgisayar mühendisinin ek bir avantajı vardır: **insan gözü frekans uzayına geçemez.** Bir doktorun frekans analizi yapabilmesi için işareti başka bir uzaya dönüştüren bir araca ihtiyacı vardır. Biz ise matematiksel olarak Fourier dönüşümü, dalgacık (wavelet) dönüşümü ya da PCA gibi yöntemlerle farklı uzaylarda öznitelikler elde edebiliriz.

> **Hocanın vurgusu:** Öznitelik çıkarımı denince iki şeye odaklanın: (1) uzamsal/zaman uzayında çıkarılan ölçümsel değerler (belirli zaman aralıkları, eğimler, oranlar); (2) matematiksel dönüşüm yöntemleriyle çıkarılan öznitelikler (örneğin EKG'de hangi frekansların ne kadar baskın olduğu, başka bir hastalık türünde görülmeyen frekansların ortaya çıkıp çıkmadığı).

### 10.4 Öznitelik seçimi

Bazen öznitelik boyutu çok büyük olabilir ve azaltılması gerekir. Hoca nedenini Öklid uzaklığıyla açıkladı (ekrandan, 01:40:00): iki örnek $x$ ve $y$ arasındaki uzaklık

$$\text{uzaklık}(x, y)=\sqrt{\sum_{i=1}^{d}(x_i-y_i)^2}$$

ile hesaplanır. $d$ ne kadar büyükse o kadar çıkarma ve kare alma işlemi yapılır; yani $d$'nin büyüklüğü bu basit uzaklık hesabının bile yükünü artırır. Makine öğrenmesi yöntemleri Öklid uzaklığından çok daha karmaşık işlemler kullanır. Hem öznitelik sayısının hem de örnek sayısının büyüklüğü makinenin performansını etkiler ve kaynaklar sınırlıdır.

Bu nedenle $d$ boyutlu uzay yerine, $d$'den çok daha küçük $d'$ boyutlu bir uzay veriyi ayırmaya yetiyorsa öznitelik seçimi denen boyut azaltma algoritmaları kullanılır (tahtada $d' \ll d$; ekrandan, 01:45:00). Hoca bunun özellikle DNA ve biyoenformatik verilerinde çok önemli olduğunu söyledi.

### 10.5 Model seçimi ve eğitim

Her zaman eğiticili algoritmalar kullanılmaz; bölütleme gibi işler için eğiticisiz yöntemler de kullanılır. Ara yöntemler de vardır:

- **Yarı eğiticili öğrenme (semi-supervised learning):** kısmen etiketli, kısmen etiketsiz verilerle çalışır.
- **Topluluk öğrenmesi (ensemble learning):** birden fazla modelle eğitip kararlarını birleştirir.

### 10.6 Değerlendirme

Değerlendirmede modelin ne kadar doğruluğa ulaştığı, yeniden eğitilmesi gerekip gerekmediği ve veri miktarının artırılması gerekip gerekmediği sorulur. Bazen veri miktarı yeterli olsa bile çıkarılan özniteliklerin istenen ayrışmayı ya da sistem başarısını sağlamadığı görülür.

> **Hocanın vurgusu:** Burada en önemli kavram verinin temsil gücüdür (temsiliyet). Veri, sınıflandırma ya da bölütleme için gerçekten temsil kabiliyetine sahip mi?

## 11. Öznitelik Çıkarımı, Öznitelik Seçimi ve Boyut Azaltma

### 11.1 Ön işlemenin ayrıntıları

Hoca ön işlemeyi biraz daha açtı. Gürültü giderme ve filtreleme için daha önce sinyal ve görüntü işlemede görülen yöntemler kullanılabilir. Örneğin gürültülü bir hücre görüntüsünde hücre içi ile hücre dışı bölgeler birbirine benziyorsa, **medyan filtre** kenarlardaki keskinliği kaybettirmeden hücre içindeki pikselleri yumuşatır. Bu, gürültüyü azalttığı için bölütlemeye yararlıdır.

Normalizasyon iki şekilde yapılabilir (ekrandan, 01:40:00):

- **Z-normalizasyonu (Z-dönüşümü):** veri ortalamasından arındırılıp standart sapmaya bölünür; sıfır ortalamalı ve birim varyanslı hale gelir:

$$x_i' = \frac{x_i-\mu_i}{\sigma_i}$$

  Burada $x_i$ özgün verinin $i$. özniteliği, $\mu_i$ ortalaması, $\sigma_i$ standart sapmasıdır.

- **Belirli bir aralığa getirme:** örneğin $[-1, 1]$ aralığına. Polikar'ın makalesinde bunun için verilen formül şudur:

$$\mathbf{x} = \frac{\mathbf{x}}{\sqrt{\sum_{i=1}^{d}(x_i)^2}}$$

Aykırı değerleri atmak için örneğin **Mahalanobis uzaklığı** kullanılabilir. Hoca bunun ayrıntısına girmedi; sınıfların kovaryansı dışında kalan noktaların silinmesiyle karar yüzeylerinin daha rahat ve daha düz çıkarılabildiğini, karar sınırı ne kadar basit olursa hesap yükünün o kadar azalacağını söyledi. Polikar'ın makalesinde düşük boyutlu ($d \le 3$) verinin çizilerek aykırı değerlerin gözle görülebileceği, $d > 3$ için Mahalanobis uzaklığının özellikle Gauss dağılımlı verilerde kullanılabileceği yazar (ekrandan, 01:40:00).

> **Ek bilgi (derste anlatılmadı):** Mahalanobis uzaklığı $D(x)=\sqrt{(x-\mu)^T\Sigma^{-1}(x-\mu)}$ biçimindedir; burada $\mu$ ortalama vektörü, $\Sigma$ kovaryans matrisidir. Öklid uzaklığından farkı, özniteliklerin ölçeklerini ve aralarındaki korelasyonu kovaryans matrisiyle hesaba katmasıdır.

### 11.2 Geleneksel makine öğrenmesi ve derin öğrenme

Hoca öznitelik çıkarımının geleneksel (konvansiyonel) makine öğrenmesinde çok önemli olduğunu söyledi. Geleneksel akış şöyledir (ekrandan, 01:50:00):

```text
Geleneksel ML:  Ön işleme -> Öznitelik çıkarımı -> Model
Derin öğrenme:  Ön işleme -> Derin öğrenme (öznitelik çıkarımı + model)
```

> **Hocanın vurgusu:** Geleneksel yöntemlerde modelin başarısı öznitelik çıkarımına çok bağlıdır; çıkarılan özniteliklerin modelin sınırları çizebilmesindeki önemi çok büyüktür.

Derin öğrenmede ise öznitelik çıkarımı ile model birleşmiştir. Derin öğrenme, öznitelikleri kendi iç mekanizmalarında evrişimsel (konvolüsyonel) ya da başka yapılarla çıkarıp kendisi modeller. Eskiden hangi öznitelik çıkarma yönteminin nasıl kullanılacağı ve nelere dikkat edileceği üzerinde çokça çalışmak gerekiyordu; evrişimsel sinir ağları gibi yeni yaklaşımlarda öznitelik çıkarımı bir ölçüde kapalı kutunun içine itilmiştir.

### 11.3 Öznitelik çıkarımı nedir, ne değildir?

Hoca öznitelik çıkarımının sık karıştırıldığını söyledi ve bir kalp atımı (256 örneklik) üzerinden üç yaklaşım gösterdi (ekrandan, 01:50:00):

1. **Ham veri:** atımın 256 genlik değeri doğrudan sınıflandırmada kullanılır; öznitelik çıkarımı yoktur.
2. **Ölçümler:** atım üzerinde bazı uzunluklar ölçülür (örneğin ST dalgasının uzunluğu) ve bunlar ayrı ayrı kaydedilerek bir öznitelik vektörü oluşturulur. Buna öznitelik çıkarımı denir.
3. **Dönüşümler:** atıma FFT uygulanır ve frekans içerikleri elde edilir. Spektrum simetrik olduğu için toplam 256 değerin yarısı, yani 128 öznitelik yeterlidir. PCA ya da LDA gibi yöntemlerle dönüşüm yapılıp daha az sayıda katsayı da elde edilebilir. Bunlar da öznitelik çıkarımıdır.

> **Ders sonrası not:** Gerçel değerli 256 örneklik bir işaretin DFT'si eşlenik simetriktir; birbirinden bağımsız frekans noktaları $k=0,\dots,128$ arasındaki 129 noktadır (python ile kontrol edildi). Hocanın "yarısı, 128 tane" demesi bu bilginin yuvarlak ifadesidir.

Farklı uzaylara geçmek için dalgacık, FFT, kısa zamanlı Fourier dönüşümü (STFT), ICA, PCA gibi çeşitli yöntemler vardır. Bunlarla boyut sayısı korunabileceği gibi, daha az elemanla da ayırt edicilik sağlanabilir.

### 11.4 Öznitelik çıkarımı ve boyut azaltma

> **Hocanın vurgusu:** Makine öğrenmesinde öznitelik çıkarımı genellikle boyut azaltma (dimension reduction) ile karıştırılır.

Dönüşüm yöntemlerinde bazı frekansları almayıp yalnız belirli frekanslara odaklanabilirsiniz; bu durumda öznitelik vektörü küçülür. Öznitelik vektörünün küçülmesi hesap yükünü ciddi biçimde rahatlatır, bu yüzden boyut azaltma makine öğrenmesinde önemli bir kavramdır. Ama boyut azaltma iki yolla yapılabilir:

- **Öznitelik çıkarımıyla:** yöntemin yapısı izin veriyorsa dönüşüm sonucunda daha az katsayı tutulur.
- **Öznitelik seçimiyle:** amaç zaten karar yüzeylerini daha iyi çıkarabilecek, daha az sayıda ve daha ayırt edici öznitelikleri seçmektir.

Polikar'ın makalesi de dönüşüm tabanlı boyut azaltma yöntemlerinin bazı kaynaklarda öznitelik seçiminin özel bir durumu olarak (filtre tabanlı öznitelik seçimi) ele alındığını belirtir (ekrandan, 02:05:00).

### 11.5 Boyut laneti

Makine öğrenmesinde önemli bir kavram **boyut lanetidir** (curse of dimensionality) (ekrandan, 01:55:00). Hoca "curse" kelimesinin Türkçeye "lanet" olarak çevrilebileceğini söyledi. Algoritmanın zaman ve bellek gereksinimleri boyut büyüdükçe artar; eklenen her öznitelik yükü karesel, kübik ya da polinomsal olarak artırabilir. Polikar'ın makalesinde altı çizilen cümleye göre, küçük ama bilgilendirici bir öznitelik kümesi sınıflandırma algoritmasının karmaşıklığını, çalışması için gereken zaman ve bellek gereksinimlerini ve aşırı öğrenme (overfitting) olasılığını belirgin biçimde azaltır.

### 11.6 Ockham'ın usturası

Hoca, boyut azaltmanın yararları anlatılırken sık anılan felsefi bir ilkeden söz etti: **Ockham'ın usturası** (Ockham's Razor). Makaledeki ifadesi şudur: "entities are not to be multiplied without necessity", yani gerek yoksa varlıklar çoğaltılmamalıdır (ekrandan, 01:55:00). Hoca bunu "mümkün olan en az şeyle sonuca ulaşmaya çalışın, işinizi gereksiz yere zorlaştırmayın" diye açıkladı ve doğanın en düşük potansiyelli yoldan gitmesine benzetti.

## 12. Temel Bileşen Analizi (PCA) ve Doğrusal Ayırtaç Analizi (LDA)

Öznitelik çıkarımında dönüşüm amacıyla kullanılan temel yöntemler PCA ve LDA'dır. Polikar'ın makalesinde bunlar en yaygın doğrusal dönüşümler olarak verilir (ekrandan, 01:55:00).

### 12.1 PCA: etiketsiz yöntem

Temel Bileşen Analizi (Principal Component Analysis, PCA) makine öğrenmesinin en temel öznitelik çıkarma yöntemlerinden biridir.

> **Hocanın vurgusu:** PCA etiketsizdir, sınıf bilgisi kullanmaz. LDA ise etiketlidir; sınıfları bilerek çalışır.

Hoca iki öznitelikli (Feature 1, Feature 2) bir dağılım üzerinden anlattı. Veride aslında iki farklı sınıf olsun, ama sınıf bilgisi bilinmesin. Özgün eksenlerden biri üzerinde bir eşik konursa, iki sınıfın izdüşümleri birbirinin üzerine geçer ve ayrım yapılamaz. Bunun yerine PCA şunu sorar: verinin en çok değiştiği, yani en geniş dağıldığı eksen hangisidir? İlk eksen bu yönde seçilir; ikinci eksen ikinci en çok değişimin olduğu yöndedir; bu şekilde öznitelik sayısı kadar eksen, varyansın büyüklüğüne göre sıralanır.

Bunun için:

1. Verinin kovaryans matrisi hesaplanır.
2. Kovaryans matrisinin özdeğerleri (eigenvalue) ve özvektörleri (eigenvector) bulunur.
3. Özvektörler yeni koordinat sisteminin eksenlerini verir; özdeğerler bu eksenlerdeki değişim miktarını gösterir. En büyük özdeğere ait eksen en büyük değişimin olduğu yön, yani birinci temel bileşendir (PC1); ikinci büyük özdeğere ait eksen PC2'dir.

Polikar'ın Şekil 5'ünde temel eksenlerin verinin kovaryans matrisinin özvektörleri boyunca uzandığı gösterilir (ekrandan, 01:55:00). Makalede PCA'nın Karhunen-Loève dönüşümü olarak da bilindiği, 2 boyutlu verinin birinci temel eksene izdüşürülmesiyle özgün veriyi en iyi temsil eden 1 boyutlu verinin elde edildiği yazar. Hoca PCA'nın matematiksel ayrıntısına girmeyeceğini, ama temel mantığın en çok değişim gösteren yönü bulmak olduğunu söyledi. Amaç, bu yönde basit bir eşikle çok daha az kayıpla ayrım yapabilmektir.

### 12.2 LDA: etiketli yöntem

Doğrusal Ayırtaç Analizi (Linear Discriminant Analysis, LDA) de bir izdüşüm yapar, yani yeni bir karar yüzeyi bulur, ama bunu sınıf bilgisini kullanarak yapar. Hoca burada öğrencilere bir soru sordu (bkz. Örnek Sorular) ve cevabını kendisi verdi: iyi bir karar yüzeyi çizmek için sınıfların olabildiğince kompakt olması, bir yerde toplanması istenir. Sınıflar dağınık olursa karar yüzeyi oluşturmak zorlaşır. İdeal bir ayrıştırma için:

- **Sınıf içi dağılım** (within-class) en küçük olmalıdır: aynı sınıfın örnekleri birbirine benzer özellikler göstermelidir.
- **Sınıflar arası uzaklık** (between-class) en büyük olmalıdır.

Böylece olabildiğince basit bir ayırıcı yüzey elde edilir. LDA önce sınıf içi dağılımları, sonra sınıflar arası dağılımı hesaplar; ardından sınıflar arası dağılımın sınıf içi dağılıma oranını en büyük yapan amaç fonksiyonunu (objective function) kullanır. Bu oranın en yüksek olduğu izdüşüm yönü bulunduğunda ayırıcı yüzey bulunmuş olur.

Polikar'ın Şekil 6'sında bu fark görsel olarak gösterilir (ekrandan, 02:00:00): kötü seçilmiş bir izdüşüm yönünde (soldaki şekil) üçgen ve yuvarlak sınıflarının izdüşümleri yatay eksende üst üste biner; LDA'nın seçtiği yönde (sağdaki şekil) ise iki sınıfın izdüşümleri birbirinden ayrışır.

Hoca LDA'nın matematiksel temelinin makalede anlatıldığını ve öğrencilerin bunun üzerinde çalışmasını istedi.

> **Ek bilgi (derste anlatılmadı):** İki sınıflı durumda Fisher ölçütü genellikle $J(w)=\dfrac{w^T S_B w}{w^T S_W w}$ biçiminde yazılır; $S_B$ sınıflar arası, $S_W$ sınıf içi dağılım matrisidir. Bu oranı en büyük yapan $w$ yönü, genelleştirilmiş özdeğer probleminin çözümüdür.

### 12.3 Diğer öznitelik çıkarma yöntemleri

PCA ve LDA dışında ICA (bağımsız bileşen analizi), dalgacık tabanlı ve FFT tabanlı yöntemler, son zamanlarda geliştirilen eğricikler (curvelet) gibi 1, 2 ve 3 boyutlu yapılar da vardır. Polikar'ın makalesinde PCA ve LDA'nın her uygulama için en iyi seçenek olmadığı; ayırt edici bilginin spektral uzayda bulunduğu durumlarda Fourier tabanlı, EKG ve EEG gibi durağan olmayan işaretlerde ise dalgacık tabanlı zaman-frekans gösterimlerinin daha uygun olabileceği yazar (ekrandan, 02:05:00).

## Örnek Sorular

**Soru 1** (derste sözlü, 00:32:12): $N\times d$ boyutlu veri matrisinde $N$ ve $d$ neyi gösterir?

> **Çözüm (derste verildi):** $N$ örnek (sample) sayısıdır, $d$ öznitelik (feature) sayısıdır. Etiketler $N\times 1$ boyutlu ayrı bir vektörde tutulur.

**Soru 2** (derste sözlü, 00:48:56): Bir hücreyi görüntüde çevrelerken (bölütlerken) yalnız pikselin rengine (RGB değerine) mi bakıyoruz? Beynimiz başka neyi kullanıyor?

> **Çözüm (derste verildi):** Bir öğrenci renk ya da parlaklık değişim oranına (köşe bulur gibi) bakıldığını söyledi. Hoca, bunun yanında çevre piksellerin dağılımına, yapının şekline ve bağlama da bakıldığını açıkladı: rengi arka planla aynı olan bir bölge bile çevresindeki yapı yüzünden hücre içi sayılır; ortasında tek bir pembe piksel bulunan mor bir hücrede o piksel sensör hatası kabul edilir. Bu yüzden öznitelik vektörüne çevre piksellerin değerleri de eklenebilir.

**Soru 3** (derste sözlü, 01:25:38): Karar sınırları kurulmuş bir sistemde hata en çok nerede oluşur?

> **Çözüm (derste verildi):** Test örneği karar sınırına çok yakın ya da tam sınırın üzerine düştüğünde. Bu yüzden başarı hem eğitim verisinin dağılımı iyi temsil etmesine hem de modelin sınırları iyi çizmesine bağlıdır.

**Soru 4** (derste sözlü, 02:02:07): İki sınıf arasında bir karar yüzeyi çizmek istiyorsunuz. Bu yüzeyi çizmeyi en çok ne kolaylaştırır?

> **Çözüm (derste verildi):** Sınıfların kompakt olması, yani sınıf içi dağılımın en küçük, sınıflar arası uzaklığın en büyük olması. LDA tam olarak sınıflar arası dağılımın sınıf içi dağılıma oranını en büyük yapan izdüşüm yönünü arar.

## Dersin Toparlaması

Bu derste biyomedikal veride makine öğrenmesinin amacı, doktorun tecrübeyle edindiği ayırt etme becerisini bilgisayara öğretmek olarak tanımlandı. Bir, iki ve üç boyutlu biyomedikal veriden satırları örnek, sütunları öznitelik olan $X \in \mathbb{R}^{N\times d}$ matrisinin ve $y$ etiket vektörünün nasıl kurulduğu EKG ve patoloji görüntüsü örnekleriyle gösterildi. Patoloji akışında boyama, tam slayt taraması, patch ve ilgi bölgesi seçimi, sınıflandırma ile bölütleme arasındaki fark, eğiticili ve eğiticisiz öğrenme ile ön ve son işleme adımları anlatıldı. Öznitelik uzayında sınıfların kümelenmesi, karar sınırları, yüzeyleri ve hiperdüzlemler, hataların sınırlar yakınında oluşması ve iç içe geçen sınıflar ele alındı.

Polikar'ın makalesi üzerinden bir örüntü tanıma sisteminin bileşenleri (veri toplama, ön işleme, öznitelik çıkarımı, öznitelik seçimi, model seçimi ve eğitim, değerlendirme) incelendi. Öznitelik çıkarımının boyut azaltmayla karıştırılmaması gerektiği, boyut laneti ve Ockham'ın usturası vurgulandı; etiketsiz PCA ile etiketli LDA'nın temel mantığı karşılaştırıldı. Hoca bir sonraki derste öznitelik seçiminden devam edeceğini ve ardından proje örnekleriyle ilerleyeceğini söyledi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
