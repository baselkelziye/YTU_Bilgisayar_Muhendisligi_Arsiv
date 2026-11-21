# Ders 9 Genişletilmiş Notu: Biyomedikal Veride Makine Öğrenmesi Süreci ve Histopatolojik Hücre Bölütleme Örneği

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Makine Öğrenmesi Sürecinin Genel Çerçevesi
- 2. Veri Elde Etme ve Ön İşleme
- 3. Eğitim, Doğrulama ve Test Verisi
- 4. Öznitelik Çıkarma
- 5. Boyut Azaltma ve Öznitelik Seçme
- 6. Model: Eğiticili, Eğiticisiz ve Derin Öğrenme
- 7. Son İşleme
- 8. Değerlendirme
- 9. Temel Sınıflandırıcılar: Bayes ve k-NN
- 10. Yapay Sinir Ağları
- 11. Derin Öğrenme
- 12. Verinin Karar Yüzeyine Etkisi ve Çapraz Doğrulama
- 13. SVM, Çekirdek Yöntemleri, Topluluk Öğrenme ve Kümeleme
- 14. Örnek Proje: Histopatolojik Görüntüde Hücre Bölütleme
- 15. MATLAB Uygulaması: Veri Yapısı ve SVM ile Sınıflandırma
- 16. Bir Araştırma Projesi Nasıl Geliştirilir?
- 17. Akademik Yazım: Overleaf, LaTeX ve BibTeX
- 18. Çalışılabilecek Veri Setleri ve Yöntem Alanları

## 1. Makine Öğrenmesi Sürecinin Genel Çerçevesi

Bu derste hoca, bir önceki derste başlanan öznitelik çıkarma (feature extraction) konusundan devam ederek biyomedikal verilerde makine öğrenmesi sürecini baştan sona tahtada çizdi (ekrandan, 00:25:00 ve 00:45:00). Ardından temel sınıflandırıcılar ve sinir ağları üzerinden geçti, son olarak bir histopatoloji veri setinde hücre bölütleme örneğini MATLAB'de gösterdi.

Tahtadaki akış şöyledir:

```text
Veri elde etme (Acquisition)
  -> Ham veri (Raw Data)
  -> Ön işleme (Preprocessing)
  -> Veri seti: Eğitim / Doğrulama / Test
  -> Öznitelik çıkarma ve seçme (Feature Extraction ve Selection)
  -> Model (1: Eğiticili, 2: Eğiticisiz)
  -> Son işleme (Post-processing)
  -> Değerlendirme (Evaluation)
```

## 2. Veri Elde Etme ve Ön İşleme

İlk adım verinin elde edilmesidir. Biyomedikal alanda bilgi çeşitli sensörlerden ve cihazlardan gelir: MR verisi, mikroskop görüntüsü ya da tek boyutlu işaret olarak EKG ve EEG gibi. Hangi teşhis amaçlanıyorsa o amaç için geliştirilmiş cihazlarla ham veri toplanır. Hoca bu verinin ham veri (raw data) olduğunu, doğrudan modele verilemeyeceğini vurguladı.

Ön işlemede (preprocessing) yapılan işlemler verinin türüne göre değişir:

- EKG işareti teşhiste kullanılacak küçük parçalara (bölüklere) ayrılır.
- Gürültü süzgeç uygulanarak giderilir.
- Görüntüdeki benekler ve çekimden kaynaklanan hatalar süzgeçlenir.
- Veriler belli bir aralığa getirilir, örneğin $[-1,1]$ (normalizasyon).
- Gerekirse histogram eşitleme (histogram equalization) yapılır.
- Aykırı değerler (anomaliler) giderilir.

## 3. Eğitim, Doğrulama ve Test Verisi

Ön işlemeden sonra elimizde bir veri seti vardır. Bu veri seti genelde eğitim (training), doğrulama (validation) ve test olmak üzere üçe ayrılır. Bazen yalnız eğitim ve test olarak ikiye ayrılır ve eğitimin küçük bir kısmı doğrulama için kullanılır. Test verisi her zaman verilmeyebilir; tek bir veri seti verildiyse onu parçalara ayırıp bir kısmını test, bir kısmını doğrulama için kullanırız.

Eğitilmiş modele yeni bir test verisi geldiğinde, bu veri tek bir vektör de olabilir, birçok örnekten oluşan bir matris de. Burada hocanın en çok vurguladığı kural şudur:

> **Hocanın vurgusu:** Eğitim verisine uygulanan ön işleme adımlarının aynısı test verisine de uygulanmalıdır. Girdiler aynı işlemlerden geçmezse model mantıklı bir sonuç üretemez.

Hocanın örneği: eğitim görüntülerine medyan süzgeç uyguladınız, sistemi gürültüsüz görüntülerle eğittiniz. Test görüntüsüne medyan süzgeç uygulamazsanız model daha gürültülü bir görüntüyle karşılaşır. Aykırı değer giderme, süzgeçleme ve normalizasyon için de aynısı geçerlidir. Çünkü modeldeki matematiksel katsayılar ve karar yüzeyleri eğitim verisinin özelliklerine göre oluşmuştur.

Tahtada iki boyutlu ($x$-$y$) bir düzlem çizildi. Normalizasyon yapılmış bir test örneği birinci sınıfın bölgesine düşüyor. Aynı örnek normalizasyon yapılmadan verilirse bambaşka bir yere düşüyor ve karar sınırı onu ikinci sınıfa atayabiliyor.

## 4. Öznitelik Çıkarma

Hoca öznitelik çıkarmanın iki türlü yorumlanabileceğini söyledi (ekrandan, 00:35:00).

### 4.1 Zaman (uzamsal) domeninde ölçümler

Birinci yaklaşımda veri üzerinde doğrudan ölçümler yapılır. EKG örneğinde P dalgasının uzunluğu, ST ve PT aralıklarının uzunlukları, QRS kompleksinin uzunluğu ve eğimleri bulunur, bunlar arka arkaya bir vektöre yazılır. Bu ölçümler elle ya da otomatik yapılabilir. Hoca bunun, verinin doğal hâliyle görünen fiziksel özelliklerinden çıkarıldığını söyledi.

Bu yaklaşım uzman bilgisini taklit eder. EKG'ye bakan bir doktor, geçmiş tecrübesiyle gördüğü değişikliklerden bir karara varır. Görüntülerde de uzman hücreleri gözüyle bölütler, MR verisindeki anomalilere bakar, bazı açılara ve yoğunluklara dikkat eder: hücreler bir yerde yoğunlaşmış mı, hücrelerin içinde bozulma var mı, mitotik hücre var mı gibi.

### 4.2 Dönüşüm tabanlı yöntemler

İkinci yaklaşımda veri PCA, ayrık Fourier dönüşümü (DFT), dalgacık (wavelet) ya da ICA gibi bir dönüşümle başka bir domene taşınır ve elde edilen katsayılar öznitelik olarak kullanılır. Örneğin dalgacık dönüşümünde işaretin farklı yaklaşıklıkları (boyu küçültülmüş versiyonları) ve yüksek frekans bileşenleri bulunur; boyu küçültülmüş versiyonun arkasına yüksek frekanslı katsayılar eklenerek vektör kurulur.

Hoca bu dönüşümleri insan beyninin yapmasının mümkün olmadığını, burada farklı bir uzaya geçildiğini söyledi. Geçen haftaki PCA örneğini hatırlattı: veri mevcut eksenlerde bir çizgiyle ayrılamıyorsa yeni bir eksen takımı tanımlanır ve yeni eksenlere göre veri bir çizgiyle rahatça ayrılabilir hâle gelir.

## 5. Boyut Azaltma ve Öznitelik Seçme

### 5.1 Dönüşümle boyut azaltma

Dönüşüm yöntemlerinin bir özelliği de verinin miktarını ya da öznitelik sayısını azaltma imkânı vermesidir. PCA yeni eksenleri varyansa (özdeğere) göre sıralar. Hocanın örneği: 100 eksen olsun; ilk 10 eksenin özdeğeri büyük, kalan 90'ınki çok küçükse veriyi ayrıştırmak için ilk 10 eksen yeterlidir, kalan 90 eksen atılır (ekrandan, 00:35:00). DFT kullanıldıysa ve yüksek frekanslardaki bazı katsayılar sıfırsa bu katsayıların kullanılmaması mantıklıdır. Buna boyut azaltma (dimension reduction) denir.

Boyut azaltma iki nedenle önemlidir:

- **Hesap karmaşıklığı:** Algoritmalar bilgisayarda çalışır, yapılacak işlem sayısı azalır. Eğitim matrisi $N\times d$ ise ($N$ örnek, $d$ öznitelik) ve algoritmanın karmaşıklığı $d$'ye bağlıysa (tahtada $O(d^2)$ yazıldı), $d$'yi azaltmak hesap yükünü azaltır.
- **Daha iyi ayrışma:** Hocaya göre dönüşüm yönteminin asıl yararı boyut azaltma değil, verinin daha iyi ayrışabileceği farklı bir uzaya döndürülmesidir.

### 5.2 Öznitelik seçme

Öznitelik seçmede (feature selection) elimizde zaten $N\times d$ bir matris vardır, ama $d$ yüzlerce ya da binlerce olabilir: hazır çıkarılmış bir biyoinformatik verisi ya da birçok dönüşümden gelen katsayılar gibi. Bazı sütunlar birbiriyle çok ilişkiliyse birini kullanmak yeterlidir. Model için bazı öznitelikler seçilir, bazıları atılır.

Hocanın saydığı yaklaşımlar:

- **İleri arama (forward search):** Öznitelikler teker teker eklenir; hangi öznitelik eklenince başarım ya da ayrışma artıyor ona bakılır. Burada kombinasyonların denenmesi gerekir.
- **Geri arama (backward search):** Öznitelikler teker teker çıkarılır ve başarıma bakılır.
- **Bilgi ölçütleri:** Her özniteliğin taşıdığı enformasyon miktarı ya da entropisi, dağılımına bakılarak ölçülür.
- **Optimizasyon tabanlı arama:** Genetik algoritmalar ve güncel sürü (swarm) yöntemleriyle en uygun alt kümeler aranır.

## 6. Model: Eğiticili, Eğiticisiz ve Derin Öğrenme

Bu adımdan sonra elimizde $N\times d$ boyutlu bir eğitim matrisi vardır; öznitelikler azaltılmış ya da olduğu gibi bırakılmış olabilir. Etiketler (label) olabilir ya da olmayabilir; bu kullanılacak modelin tipini belirler. Modeller temelde eğiticili (supervised) ve eğiticisiz (unsupervised) olarak ikiye ayrılır. Bazıları pekiştirmeli öğrenmeyi (reinforcement learning) üçüncü bir sınıf sayar; burada olumlu ya da olumsuz geri bildirim verilir. Topluluk öğrenme (ensemble learning) ve yarı eğiticili öğrenme (semi-supervised learning) gibi eğiticisiz yöntemlerle karışan yaklaşımlar da vardır.

### 6.1 Eğiticili öğrenme ve yer gerçekliği

Eğiticili yöntemlerde eğitim matrisinin yanında etiket bilgisi vardır. Bu etikete yer gerçekliği (ground truth) de denir. Etiketleme iki seviyede olabilir:

- **Piksel seviyesinde:** Mikroskobik bir hücre görüntüsünün yanında hücrelerin bölütlendiği, 0 ve 1'lerden oluşan bir görüntü verilir. Sistem hangi piksellerin hücre olduğunu bu maskeyle öğrenir; yeni bir görüntüde hücrelerin yerini tespit eder.
- **Görüntü seviyesinde:** Örneğin 200×200'lük görüntülerin her birine tek bir etiket verilir: bu görüntü normal (0), bu 2 numaralı hastalık tipi, bu 3 numaralı hastalık tipi. Bir doktorun mikroskobik görüntüye bakıp "bu normal" demesi gibi.

Model oluşturmak, etiketler yardımıyla öznitelik uzayında benzer örneklerin toplandığı bölgeleri ayırmak, yani karar yüzeylerini bulmaktır. Yeni bir test örneği geldiğinde bu karar yüzeylerine göre etiketi belirlenir.

### 6.2 Eğiticisiz öğrenme

Eğiticisiz yöntemlerde yalnız veri seti vardır. Öznitelikler uzaya yerleştirildiğinde bazı öbekler görülür; karar yüzeyleri bu dağılıma göre oluşturulur ve "bu birinci küme, bu ikinci küme" denir. Eğiticili yöntemdeki gruplara sınıf (class), eğiticisiz yöntemdekilere küme (cluster) denir. Bir küme sonra bir hastalık tipiyle eşleştirilebilir.

### 6.3 Derin öğrenme

Hoca tahtaya ayrıca derin öğrenmeyi (deep learning) not etti. Derin öğrenmede de eğiticili ve eğiticisiz yöntemler vardır. Derin öğrenmenin söylediği şudur: "Öznitelik çıkarma kısmını bana bırak, ben kendi yapımın içinde çıkarır ve sınıflarım." Derin öğrenme, ucuzlayan ve hızlanan işlem gücüyle çeşitli mimarilerde gerçekleştirilebilen sinir ağı yapılarıdır; işlem yükü daha fazladır.

## 7. Son İşleme

Model oluşturulduktan sonra yeni test verisi sınıflardan ya da kümelerden birine atanır. Ama sonuç her zaman istenen gibi olmayabilir. Hocanın örneği: hücreleri belirlemeniz istendi, hücreleri az çok buldunuz ama hücrelerin içinde siyah noktalar (delikler) ve kopukluklar kaldı. İnsan gözü bunun hücre olduğunu kolayca görür. Modelin tam bulamadığı, eksik bulduğu ya da göze batan bu hataların düzeltildiği son adıma son işleme (post-processing) denir.

Son işlemede, görüntü işleme kısmında görülen morfolojik işlemler kullanılır:

- Kapama (closing) ve açma (opening) ile hücre içindeki delikler kapatılır.
- Arka planda yanlışlıkla hücre denmiş küçük parçalar aşındırma (erosion) ile silinir; çevreleri tamamen boş olduğu için yok olurlar.
- Ardından genişletme (dilation) ile kalan yapılar geri büyütülür.

## 8. Değerlendirme

Son adım sonuçların değerlendirilmesidir (evaluation). Bazen bize test verisi verilir ve modelin bu veride ne ürettiği sorulur; bazen test verisinin etiketleri de verilir ki hiç görülmemiş veride modelin sonucu karşılaştırılabilsin. Test verisinde etiket yoksa, etiketli eğitim verisinin bir kısmı performans ölçümü için ayrılmalıdır.

### 8.1 K katlı çapraz doğrulama

En basit yöntem k katlı çapraz doğrulamadır (k-fold cross-validation). Örneğin $k=5$ seçilirse veri seti 5 parçaya bölünür. 4 parçayla eğitilir, 1 parçayla test edilir. Sonra test edilen parça değiştirilir. Test parçası parçalar arasında gezer ve işlem toplam 5 kez yapılır. Böylece sistem farklı eğitim verileriyle eğitilip farklı test verileriyle test edilir ve ortalama performansı yakalanır (ekrandan, 00:50:00).

### 8.2 Ölçütler

- **Genel doğruluk (overall accuracy):** Doğru bilinen örneklerin bütün veriye oranı, yüzde olarak.
- **F-ölçütü (F-measure) ve kappa:** Etiket bilgisi varken kullanılan diğer ölçütler.
- **Kümeleme ölçütleri:** Etiket yoksa, bulunan kümelerde küme içi değişintinin olabildiğince az, kümeler arası değişintinin olabildiğince çok olması beklenir. Tahtada kırmızıyla yanlış bir kümeleme çizildi: küme içi değişinti yüksek, kümeler arası değişinti düşük. İnsan gözü doğru kümelemeyi öbeklenmeden anlar; bunu makineye anlatmak için küme içi dağılımı ve kümeler arası uzaklığı ölçen yöntemler kullanılır.
- **Bölütleme ölçütleri:** Bölütlemede de genel doğruluk hesaplanabilir. Ayrıca bulunan bölge ile doğru bölgenin ne kadar kesiştiğini ölçen kesişim/birleşim (intersection over union, IoU) ve Dice ölçütü kullanılır. Hangi ölçütün kullanılacağı uygulamaya ve veriye bağlıdır.

> **Ek bilgi (derste anlatılmadı):** İki ikili maske $A$ (bulunan) ve $B$ (yer gerçekliği) için $\mathrm{IoU}=\frac{|A\cap B|}{|A\cup B|}$ ve $\mathrm{Dice}=\frac{2|A\cap B|}{|A|+|B|}$ biçiminde tanımlanır. İkisi de 0 ile 1 arasındadır ve tam örtüşmede 1 olur.

## 9. Temel Sınıflandırıcılar: Bayes ve k-NN

Hoca bu kısmı Robi Polikar'ın "Pattern Recognition" başlıklı makalesi üzerinden anlattı (ekrandan, 00:55:00).

### 9.1 Bayes sınıflandırıcıları

Bayes sınıflandırıcıları sınıfların olasılıklarını kullanarak sınıflandırma yapar; naif Bayes gibi olasılık tabanlı yöntemlerdir. Slayttaki naif Bayes kuralında her sınıf için ayırt edici fonksiyon (discriminant function) hesaplanır ve bu fonksiyonu en büyük yapan sınıf seçilir (ekrandan, 00:55:00):

$$g_i(\mathbf{x})=P(\omega_i)\prod_{j=1}^{d}P(x^{(j)}\mid\omega_i)$$

### 9.2 k en yakın komşu (k-NN)

k-NN biraz farklı bir yaklaşımdır. Eğitim verileri uzaya yerleştirilir. Yeni bir örnek geldiğinde önce kendisine en yakın $k$ veri örneği bulunur, sonra bu örneklerin etiketlerinden hangisi çoğunluktaysa yeni örneğe o etiket atanır. Örneğin 5-NN kullanılıyorsa en yakın beş örneğe bakılır. Slayttaki şekilde dört sınıflı bir veri ve $k=11$ için komşuluk daireleri gösteriliyordu (ekrandan, 00:55:00).

> **Hocanın vurgusu:** Bu işlem yoğun bir işlemdir. Şekilde en yakın komşuları görmek kolaydır, ama bin örnekli bir veri setinde yeni bir örneğin en yakın komşusunu bulmak için bin uzaklık hesaplamak gerekir. Görsel olarak kolay yapılan şeylerin altında ciddi hesap zorlukları olabilir.

> **Ders sonrası not:** Hoca 00:54:47 civarında "bin tane ölçüm yapmanız gerek yok" dedi; bağlamdan kastedilenin "bin tane ölçüm yapmanız gerekir" olduğu anlaşılıyor (cümlenin devamı "bu da zorlu bir işlem").

## 10. Yapay Sinir Ağları

Aradan sonra hoca yapay sinir ağlarına geçti; büyük verilerde ve derin öğrenmede temel olduğu için bazı kavramların üzerinde durdu.

### 10.1 Biyolojik nöron ve nöron modeli

İnsan sinir hücresinde dendritlerden gelen uyarılar toplanır, akson üzerinden sinaptik uçlara iletilir ve dışarıya uyarı verilir (ekrandan, 01:10:00). Uyarılar şiddetine göre belli bir ağırlıkla çarpılıp toplanır, hücre içinde bir eşikten geçirilir; bu eşiklemeyi yapan fonksiyona aktivasyon fonksiyonu denir.

Yapay nöron modelinde (ekrandan, 01:15:00) girişler $x_1,\dots,x_d$ bağlantı ağırlıkları $w_1,\dots,w_d$ ile çarpılıp toplanır. $d$ boyutlu bir öznitelik vektörü için $d+1$ giriş vardır: sabit değeri 1 olan $x_0$ girişi ve ağırlığı $w_0$, düğümün yanlılığıdır (bias). Hoca yanlılığı, karar yüzeyinde bir kaydırma gerekiyorsa matematiksel olarak eklenen, girişe bağlı olmayan sabit olarak açıkladı. Ağırlıklı toplam $net$ diye anılır:

$$net=\sum_{i=0}^{d} w_i x_i,\qquad y=f(net)$$

### 10.2 Aktivasyon fonksiyonları

Slayttaki aktivasyon fonksiyonları (ekrandan, 01:15:00):

- **Eşik fonksiyonu:**

$$f(net)=\begin{cases}1, & net\ge 0\\ 0, & \text{aksi hâlde}\end{cases}\qquad\text{ya da}\qquad f(net)=\begin{cases}1, & net\ge 0\\ -1, & \text{aksi hâlde}\end{cases}$$

  Bu aktivasyonla çalışan düğüme perseptron denir.
- **Doğrusal (identity) fonksiyon:** $f(net)=net$; girişi olduğu gibi çıkışa aktarır.
- **Lojistik (sigmoid) fonksiyon:** Girişi bir miktar bastırır, sonra artar ve belli bir değerde doyuma ulaşır.
- **Hiperbolik tanjant:** Doğrusal olmayan karar yüzeylerinin oluşturulması için kullanılır.

### 10.3 Çok katmanlı perseptron

Nöronlar yan yana ve katman katman dizildiğinde giriş katmanı, gizli katman ve çıkış katmanından oluşan çok katmanlı perseptron (MLP) elde edilir. Eğitim matrisindeki her vektör ($x_0, x_1, x_2, \dots$) girişe verilir, ağırlıklarla çarpılır; etikete göre ağırlıklar belirlenir. Sonraki örnek başka bir sınıftansa ağırlıklar yeniden güncellenir. Hatanın geriye doğru yayılmasıyla ağ, iç içe geçmiş sınıfları ayırabilecek kadar karmaşık karar yüzeyleri oluşturur.

Bu yapıda birçok parametre vardır: ağırlıkların güncellenme tekniği, aktivasyon fonksiyonları, çıkışın nasıl değerlendirileceği. Gizli katman sayısı arttıkça hatanın geriye yayılması zorlaşır. Hataların küçük adımlarla mı büyük adımlarla mı düzeltileceğini öğrenme oranı belirler; momentum gibi ek parametreler yerel minimuma düşmemeye ve hata yüzeyinde daha iyi yakınsamaya yardım eder.

Çıkışta ikili kodlar kullanılabilir (örneğin $1\text{-}0\text{-}0$ bir sınıfı, $1\text{-}1\text{-}0$ başka bir sınıfı gösterir) ya da tek bir çıkış nöronunun değer aralıklarına sınıflar atanabilir. Sınıflandırmanın nasıl yapılacağı biraz da kurulan matematiksel yaklaşıma bağlıdır.

### 10.4 Radyal tabanlı fonksiyon (RBF) ağları

MLP dışındaki ağlardan biri Gauss dağılımı kullanan radyal tabanlı fonksiyon (RBF) ağlarıdır (ekrandan, 01:20:00). Gizli katmana alıcı alan (receptive field) katmanı denir; her alıcı alan belli bir merkez ve standart sapmayla veriyi ayrıştırmaya çalışır. Slayttaki formül:

$$y_j=\varphi(net_j=\lVert\mathbf{x}-\mathbf{u}_j\rVert)=e^{-\left(\frac{\lVert\mathbf{x}-\mathbf{u}_j\rVert}{\sigma}\right)^2}$$

Burada $\mathbf{u}_j$ Gauss çekirdeğinin merkezi, $\sigma$ yayılımıdır (standart sapma). RBF ağları hem eğiticili hem eğiticisiz yaklaşımlarla kullanılabilir. Hoca bu kısımlara derinlemesine girmedi.

## 11. Derin Öğrenme

Hoca derin öğrenmenin ayrı bir ders olarak verildiğini, burada yalnız temel fikri anlattığını söyledi. Derin öğrenme yapıları daha çok görüntüler üzerinde, yani iki boyutlu girişlerle kullanılır. Görüntünün içindeki küçük parçaları (yamaları) alıp işler. Normal sinir ağlarından farklı olarak ara katmanlarda konvolüsyon uygulayarak öznitelik çıkarır. Bu katmanlarda kimi köşegen yapıları, kimi belli nesne özelliklerini bulan çeşitli süzgeçler öğrenilir. Ara katmanlarda max pooling ve bazı ağırlıkların güncellenmesini engelleyen dropout gibi işlemler kullanılır. Ağırlıklar yine geriye yayılımla güncellenir.

Hem konvolüsyon işlemi hem de çok sayıda katman içerdiği için bu yaklaşımlara derin öğrenme denir. Kullanılan yapıya mimari (architecture) denir; AlexNet ve GoogLeNet farklı mimarilere örnektir.

## 12. Verinin Karar Yüzeyine Etkisi ve Çapraz Doğrulama

Performans değerlendirmesinde temel yöntem yine k katlı çapraz doğrulamadır: $k$ blok vardır, biri test için bırakılır, diğerleriyle eğitim yapılır ve test bloğu her seferinde kaydırılır (ekrandan, 01:25:00). Bütün modellerde sistemin parametreleri veriye uyumlu olarak güncellendiği için seçilen veri önemlidir.

Veri farklı sınıfları ve sınıf içindeki küçük farklılıkları ne kadar iyi temsil ederse o kadar iyidir. Tek tip bir veriye yoğunlaşılmışsa model basit bir karar yüzeyi çizer; farklı davranışlar ve yayılımlar temsil edilmişse daha karmaşık karar yüzeyleri seçilebilir.

Tahtadaki örnekte (ekrandan, 01:25:00) iki sınıf arasından geçen iki farklı karar yüzeyi çizildi. Belli bir eğitim örneği veri setinde yoksa karar yüzeyi farklı bir yerden geçer. Tam aradaki bir $x$ test noktası, ilk karar yüzeyiyle 1 numaralı sınıfa atanacakken, mavi çizilen yüzeyle 2 numaralı sınıfa atanır. Demek ki modelin bir veri bağımlılığı vardır; eğitim verisinin sınıfları gerçekten ayrıştıracak kalitede olması gerekir. K katlı çapraz doğrulama, verideki bazı noktaları çıkarıp bazılarını sokarak ve karar yüzeylerini bunların ortalaması olarak belirleyerek bu bağımlılığı azaltır.

Karar yüzeylerini iyileştirmenin başka yolları da vardır. Veriyi daha iyi temsil ettiği düşünülen örnekler seçilir, karar yüzeyini bozduğu düşünülen örnekler ayıklanır. Aktif öğrenme (active learning) veriyle bu şekilde oynayarak karar yüzeyini en iyilemeye çalışan yaklaşımlardan biridir.

Hoca, makine öğrenmesinin olasılıktan başlayıp götürülebilecek ayrı bir alan olduğunu; görüntü işleme ve derin öğrenmenin de ayrı dersler olarak görülebilecek konular olduğunu, burada genel bir yapıdan bahsedildiğini hatırlattı.

## 13. SVM, Çekirdek Yöntemleri, Topluluk Öğrenme ve Kümeleme

### 13.1 Destek vektör makineleri

Destek vektör makineleri (SVM) güncel ve çok kullanılan bir yöntemdir (ekrandan, 01:30:00). Karar yüzeyine en yakın örnekler (destek vektörleri) bulunur ve aradaki marj olabildiğince geniş olacak şekilde en iyi karar yüzeyi çizilir. Slayttaki başlık SVM'lerin "en büyük marj sınıflandırıcısı" (maximum margin classifier) olarak da anıldığını gösteriyordu.

### 13.2 Çekirdek yöntemleri

SVM'lerde karşılaştırmalar daha yüksek boyutlu bir uzaya geçilerek yapılır; veri yüksek boyutta daha iyi ayrışır. Bu yaklaşıma çekirdek (kernel) yöntemleri denir.

Hocanın sezgisel örneği: iki öznitelik ve iki sınıf (kırmızılar ve maviler) olsun; sınıflar birbirinin içine geçmiş görünsün. Veriye $x$-$y$ düzleminde yukarıdan bakıldığında, yani noktaların düzleme izdüşümüne bakıldığında, sınıflar gerçekten iç içe görünür. Oysa üçüncü bir boyut eklendiğinde kırmızılar ile maviler farklı yüksekliklerde kalır ve aralarından geçen bir yüzeyle ayrılabilir. Daha yüksek boyutlu bir uzaya geçerek ayrıştırma fikri çekirdekleştirme (kernelization) kavramını doğurur. Hoca, çekirdek tabanlı yöntemlerin derin öğrenmeden önce en aktif çalışma alanlarından biri olduğunu, derin öğrenmenin bu alandaki çalışmaları yavaşlattığını, ama SVM'in hâlâ temel sınıflandırıcılardan biri olarak kullanıldığını söyledi.

> **Ek bilgi (derste anlatılmadı):** Çekirdek hilesinde (kernel trick) veri yüksek boyuta açıkça taşınmaz; yalnız iki örnek arasındaki iç çarpım bir çekirdek fonksiyonuyla hesaplanır. Derste kullanılan libsvm aracında `-g` parametresi Gauss (RBF) çekirdeğinin genişlik parametresi $\gamma$'dır, `-c` ise yanlış sınıflandırma cezasıdır.

### 13.3 Topluluk öğrenme

Topluluk öğrenmede (ensemble learning) birçok sınıflandırıcının verdiği kararlar birleştirilir. Hocanın benzetmesi: bir vakayı değerlendiren doktorlar kurulu. Biri "kanser" der, biri "arada bir değer" der, biri "kanser değil" der. Her doktor farklı tecrübesiyle farklı bir sınıflandırıcıdır; en doğru karar bu kararları değerlendiren bir üst yapıyla verilir.

### 13.4 Kümeleme yöntemleri

Eğiticisiz yöntemlere kümeleme (clustering) yöntemleri denir; etiket bilgisi kullanmazlar. Hocanın saydıkları: k-means, bulanık c-means (fuzzy c-means), yoğunluk tabanlı (density-based) yöntemler ve optimizasyon tabanlı kümeleme yöntemleri.

k-means'te veri uzayına rastgele merkezler atanır. Her merkez kendisine en yakın örnekleri toplar; bu merkezlere sentroid (centroid) denir. Merkezler kümelerinin ortasına çekilir ve kendine en yakın noktalarla bir karar yüzeyi oluşturur. En kritik nokta başlangıç merkezlerinin seçimidir. Yoğunluk tabanlı yöntemler noktaların en yoğun olduğu bölgeleri kümelere almaya çalışır. Kullanılan optimizasyon algoritmasına göre farklı biçimli kümeler oluşabilir. Hoca, hangi yöntem kullanılırsa kullanılsın işe algoritmanın yapısını anlamakla başlamak gerektiğini söyledi.

## 14. Örnek Proje: Histopatolojik Görüntüde Hücre Bölütleme

Hoca, öğrencilerin kafasında projelerin nasıl yürüyeceği canlansın diye kendi yaptığı bir çalışmayı örnek olarak anlattı: histopatolojik bir veri setinde hücrelerin arka plandan ayrılması.

### 14.1 Veri setini keşfetmek

İlk iş veri setini indirip incelemektir (dataset exploration). Bu veri setinde görüntünün her tarafı işaretlenmemişti; yalnız belli bir bölgesinin (sağ üst kısım) yer gerçekliği vardı. Buradan istenen işin bölütleme (segmentation) olduğu anlaşılıyordu. Hoca örnek görüntüyü Paint'te açarak gösterdi (ekrandan, 01:40:00 ve 01:45:00).

Veri seti 58 görüntüden oluşan bir meme kanseri (breast cancer) veri setiydi; hocanın ifadesiyle ilk çalışılan basit setlerden biri.

### 14.2 Problemin zorluğu

İnsan gözü hücreleri çok rahat bulur, hatta üst üste binmiş hücreleri bile ayırabilir. Ama yalnız RGB değerlerine göre bölütleme yapılırsa:

- Aynı renkteki bitişik hücreler tek bir parça gibi çıkar.
- Asıl sorun, bazı hücrelerin (epitel doku gibi) iç kısmının arka planla aynı renkte olmasıdır. Bu hücreler bulunsa bile delikli bir yapıda çıkar; oysa istenen hücrenin dolu bir bölge olarak gösterilmesidir.
- Arka planda da beyaz, pembe ve kırmızı bölgeler, yağ, epitel doku ve kırmızı kan hücreleri vardır.

### 14.3 Ön işleme: bölgeyi kesmek

Görüntü ile yer gerçekliğinin koordinatları aynıdır. Önce yer gerçekliği olan bölge hem görüntüden hem yer gerçekliğinden kesildi ve alt görüntüler oluşturuldu. Böylece nerenin hücre, nerenin dış kısım olduğu bilinen iki sınıflı bir problem elde edildi.

### 14.4 Birinci yol: eğiticisiz kümeleme

İlk yaklaşımda her pikselin RGB değerleri alt alta konarak bir matris oluşturuldu ve kümeleme uygulandı. Eğiticisiz yöntemlerin çoğu (k-means, fuzzy c-means) küme sayısını kullanıcıdan ister; bazıları otomatik bulur. Hoca tecrübesine ve deneme yanılmaya dayanarak beyazlar, pembeler, koyu renkler ve daha koyu renkler için $k=4$ seçti.

Etiket kullanılmadığından sonuç çok sağlıklı olmayabilir: hücre içindeki bir rengin RGB değeri arka plandaki bir renkle aynı olduğu için hücrelerde delikler kalır. Bu delikler son işleme yöntemleriyle giderilmelidir.

### 14.5 İkinci yol: eğiticili piksel sınıflandırma

İkinci yaklaşımda yer gerçekliği kullanıldı. Hücre olduğu bilinen piksellerin RGB değerleri alınıp etiketlerine 1, hücre olmayan yapılardan (arka plan) alınan piksellerin etiketlerine 0 yazıldı. Böylece bir eğitim seti oluşturuldu ve SVM ya da Random Forest gibi bir yöntemle model eğitildi.

Model görüntünün her pikseline teker teker uygulanır: ilk piksel için 0 (arka plan), ikinci piksel için 0, ... hücre dediği piksellere 1. Ancak sonuçta hücre bölgelerinin arasında arka plan denmiş pikseller de oluşur; tam bir leke (blob) ya da hücre elde edilemez. Test görüntüsünün de yer gerçekliği varsa önce sonuçla karşılaştırılıp başarım yüzdesi hesaplanmalıdır.

### 14.6 Uzamsal öznitelikler

Literatür araştırması, yalnız RGB değerlerini kullanmanın mantıklı sonuç üretmeyeceğini gösterdi; çünkü bu durumda uzamsal bilgi kullanılmıyordu. Bir pikselin hücre olup olmadığına yalnız kendi rengine bakarak değil, çevresindeki piksellerin oluşturduğu desene bakarak karar verilmelidir. Hücre içindeki bir piksel ile arka plandaki bir piksel aynı renkte olabilir; çevresine bakıldığında fark ortaya çıkar.

Bunun için pikselin çevresine çeşitli boyutlarda pencereler konur: 3×3, 5×5, 7×7, 9×9 (ekrandan, 02:10:00). Bu pencerelerden çıkarılan özniteliklere uzamsal öznitelik denir. Tahtadaki notta ve anlatımda geçen öznitelikler:

- Gri seviye eş oluşum matrisi (Gray Level Co-occurrence Matrix, GLCM)
- SIFT ve SURF
- HOG <!-- BELİRSİZ: altyazıda "Fog" geçiyor (01:51:28); bağlamdan HOG olduğu düşünüldü, karede yazılı değil. -->
- İstatistiksel değerler: basıklık (kurtosis), çarpıklık (skewness), varyans

Önce yalnız GLCM öznitelikleri 3×3 pencereyle denendi, sonra pencere boyutu 5×5, 7×7, 9×9'a çıkarıldı. Hoca bunun bir araştırma projesi olduğunu, ilk sorulacak sorunun "Yalnız RGB değerleri versem hücre ile arka planı ne kadar ayırabilirim?" olduğunu, sonra adım adım öznitelik eklenerek her birinin sonucunun ayrı ayrı denendiğini anlattı. 58 görüntünün yaklaşık 30'u eğitim, kalanı test için kullanıldı.

> **Ders sonrası not:** Hoca eğitim/test ayrımını bir yerde "28 tanesini veya 30 tanesini train için" (02:10:52), başka bir yerde "38 tanesini tren, 28 tanesini test" (02:16:46) dedi; ikinci ifadedeki sayılar toplamda 58'i aşıyor. Anlatımın bütününden büyük olasılıkla 30 görüntü eğitim, 28 görüntü test için kullanılmıştır ($30+28=58$).

## 15. MATLAB Uygulaması: Veri Yapısı ve SVM ile Sınıflandırma

### 15.1 Veri yapısı

Hoca bütün bilgiyi derli toplu tutmak için MATLAB'de bir hücre dizisi (cell array) yapısı kurmuştu. `traintestMat` adlı değişken 1×58'lik bir hücre dizisidir; her eleman bir görüntüye ait bir yapıdır (struct). Birinci elemanın alanları (ekrandan, 02:15:00):

| Alan | Değer |
|---|---|
| `IorgCrop` | 205×227×3 uint8 (kesilmiş orijinal görüntü) |
| `ILabCrop` | 205×227×3 uint8 |
| `GtCrop` | 205×227 uint8 (kesilmiş yer gerçekliği) |
| `xData` | 46535×3 double |
| `xLabel` | 46535×1 double |
| `minX` | 138 |
| `maxX` | 342 |
| `minY` | 156 |
| `maxY` | 382 |
| `FileName` | görüntünün dosya adı |

Kesme sınırları kesilen bölgenin boyutunu verir: $342-138+1=205$ ve $382-156+1=227$. Bölgedeki piksel sayısı $205\times 227=46535$'tir; bu da `xData` ve `xLabel`'in satır sayısıyla aynıdır. Yani kesilen bölgenin her pikseli bir örnektir; `xData`'nın 3 sütunu pikselin üç renk kanalıdır (ara adım eklendi, python ile doğrulandı).

<!-- BELİRSİZ: `ILabCrop` alanı derste açıklanmadı; adından görüntünün Lab renk uzayındaki karşılığı olduğu düşünülüyor. -->

Komut penceresinde kesilmiş görüntü ve yer gerçekliği şu komutlarla gösterildi (ekrandan, 02:15:00):

```matlab
load('traintestMatV2.mat')
imagesc(traintestMat{1}.IorgCrop)
figure
imagesc(traintestMat{1}.GtCrop)
colormap(gray)
```

`imagesc` yer gerçekliğini kendi renk haritasıyla (sıfırlar lacivert, birler sarı) gösterdiği için `colormap(gray)` ile siyah-beyaza çevrildi. Hoca bu kesme ve biçme işlerinin aslında sürecin ön işleme adımı olduğunu, kendi veri setini oluşturmak için gerekli hazırlık olduğunu belirtti. Ayrıca yer gerçekliklerinin her zaman tam düzgün işaretlenmeyebileceğini, ama herkesin kullandığı yer gerçekliği kabul edilerek çalışmanın onun üzerine kurulduğunu söyledi.

### 15.2 Eğitim verisi

Eğitim için ayrı bir yapı kullanıldı. `traindata` iki alanlı bir yapıdır (ekrandan, 02:20:00): `X` 5000×6 ve `y` 5000×1. Yani 30 görüntüden toplam 5000 örnek alınmış ve her örnek için 6 uzunluklu bir öznitelik vektörü çıkarılmıştır; hoca bunun büyük olasılıkla GLCM öznitelikleri olduğunu söyledi. Örnekler, yer gerçekliğinde 1 olduğu bilinen bir pikselin çevresine pencere konarak (hücre deseni) ve 0 olan bölgelerden pencereler alınarak (hücre dışı desen) oluşturulmuştu.

### 15.3 SVM eğitimi ve testi

SVM için libsvm aracı kullanıldı. Aracın kullanımına göre önce eğitim etiketleri, sonra eğitim verisi, sonra parametreler verilir (ekrandan, 02:20:00):

```matlab
load('traindata5000samples.mat')
modelSVM = svmtrain(traindata.y, traindata.X, '-c 1 -g 0.01');
```

İlk denemede `svmtrain` "Y must be a vector or a character array." hatası verdi (ekrandan, 02:20:00). Hoca, aracın tanınması için SVM klasörüne girmek gerektiğini söyledi ve komutu yeniden çalıştırdı. Hoca, kendi projelerinde Python ya da MATLAB'de kütüphaneyi içe aktarıp (import) düzenli bir çalışma yapısı kurulması gerektiğini, burada yalnız basit bir gösterim yapıldığını söyledi.

Test için 2000 örnekli ve etiketli bir veri kullanıldı (`testdata`). Test etiketleri verildiği için araç doğruluğu yüzde olarak verebildi; etiketler verilmeseydi yalnız tahminler elde edilirdi. `svmpredict` ile tahmin edilen etiketler `YhatSVM` (2000×1) değişkenine yazıldı.

Sonuçlar (ekrandan, 02:25:00):

- `accuracy = [91.4000; 0.0860; 0.6872]`
- Hata oranı `cerror` fonksiyonuyla hesaplandı: 0,0860.
- `1-cerror(YhatSVM, testdata.y)` = 0,9140.

`cerror` fonksiyonunun açıklamasına göre hata, tahmin ile gerçek etiketin farklı olduğu örneklerin oranıdır: `error = find(ypred~=ytrue)/length(ytrue)`. Fonksiyon önce tahmin, sonra gerçek etiket ister; hoca ilk denemede argümanların yerini ters verip düzeltti.

Adım adım çözüm:

- Verilen: 2000 test örneği, doğruluk %91,40.
- Doğru sınıflanan örnek sayısı: $0{,}914\times 2000=1828$.
- Yanlış sınıflanan: $2000-1828=172$; hata oranı $172/2000=0{,}086$.
- Sonuç: $1-0{,}086=0{,}914$, yani %91,40 (python ile doğrulandı).

> **Ek bilgi (derste anlatılmadı):** libsvm'in `svmpredict` fonksiyonu üç değer döndürür: doğruluk (yüzde), ortalama kare hata (MSE) ve kare korelasyon katsayısı. Ekrandaki `[91.4000; 0.0860; 0.6872]` vektörü bu sırayla okunur; etiketler 0/1 olduğundan MSE burada hata oranına eşittir.

Hoca, başka performans fonksiyonlarının da bulunup kullanılabileceğini söyleyerek bu basit uygulamayı bitirdi.

## 16. Bir Araştırma Projesi Nasıl Geliştirilir?

Hoca örnek proje üzerinden, bir araştırma projesinin adımlarını tahtaya yazdı (ekrandan, 01:55:00 ve 02:35:00):

- **1) Veri seti iyice anlaşılacak.** Veri seti okunacak, yapısı ve etiketleri anlaşılacak, o veri setini kullanan çalışmalara bakılacak.
- **2) Problem tanımı oturtulacak.** Problem sınıflandırma mı, bölütleme mi, tespit (detection) mi? Örnek projede amaç hücreleri arka plandan ayırmak, yani yer gerçekliğine olabildiğince benzeyen bir 0-1 görüntüsü elde etmekti.
- **3) Sağlam bir literatür araştırması yapılacak.** Kaynaklar: Google, Google Scholar, ResearchGate, GitHub. Bu sitelerde aynı ya da benzer veri setiyle çalışan araştırmacıların çözümleri bulunabilir.

Literatür okunurken bir belge açılıp kim hangi çalışmada hangi veri setini, hangi yöntemi kullanmış, düzenli olarak not edilmelidir. Hoca bu notların daha sonra bildirinin giriş (introduction) bölümüne dönüşeceğini söyledi. Önemli olan "Ben bunu nasıl yaparım?" sorusundan başlamak, sonra üzerine ekleyerek sağlam yöntemler kurmaktır.

## 17. Akademik Yazım: Overleaf, LaTeX ve BibTeX

Hoca bildirilerin Overleaf üzerinde LaTeX ile yazılacağını anlattı ve kendi bir bildiri projesini örnek olarak gösterdi (ekrandan, 02:30:00).

- LaTeX bir dizgi dilidir; konferanslar genelde şablonunu (template) verir. Çıktı, konferansa hazır biçimlendirilmiş bir PDF'tir. Başlıkların, yazar adlarının, özetin (abstract), giriş bölümünün ve formüllerin biçimi şablon tarafından ayarlanır; "burası büyük, burası küçük" diye elle uğraşılmaz.
- Örnekteki belge IEEE konferans biçimindeydi (`IEEEtran` sınıfı). Başlık kısmında önce Türkçe, sonra İngilizce başlık yazılmıştı; yazar bilgileri yazar bloğuna yazılır, şablon bunları kendisi düzenler.
- Kaynaklar ayrı bir `references.bib` dosyasında BibTeX biçiminde tutulur. Ekrandaki dosyada `@inproceedings` (bildiri) ve `@article` (dergi makalesi) türünde kayıtlar vardı; her kaydın `title`, `author`, `booktitle` ya da `journal`, `pages`, `year` gibi alanları vardır.
- Metinde kaynak, kaydın ilk satırındaki anahtar kelimeyle `\cite{...}` komutu kullanılarak anılır (ekrandaki örnek anahtar: `huang1998empirical`). Belgenin sonunda bibliyografya dosyası gösterilir; LaTeX kaynakları konferansın ya da derginin biçimine göre (italik yazım, sayfa numaraları) kendisi düzenler.
- BibTeX kaydını elle yazmak gerekmez: yayının adı Google Scholar'da aranır, "alıntı yap" bölümünden BibTeX biçimi kopyalanır ve `.bib` dosyasına yapıştırılır.

Hoca Overleaf kullanımını anlatan YouTube videolarına da bakılabileceğini söyledi.

## 18. Çalışılabilecek Veri Setleri ve Yöntem Alanları

Dersin son kısmında hoca proje için güncel veri setlerini ve yöntem alanlarını tanıttı. Bu liste, biyomedikal görüntü analizinde hangi problemlerin ve yöntemlerin çalışıldığına dair bir kaynak listesi olarak da okunabilir.

### 18.1 Veri setleri

- **TIA Lab veri setleri:** Çekirdek (nuclei) veri seti; hocanın ifadesiyle 280 bin yamadan oluşan bağırsak (kolorektal) kanseri veri seti (CRC); açık PanNuke veri seti (kanser histolojisi, çekirdek örnek bölütleme ve sınıflandırma, bölütleme ve sınıflandırma ayrı ayrı çalışılabilir); kanser derecelendirme (cancer grading) veri seti; CRC doku fenotipleme (tissue phenotyping).
- **Derin öğrenme veri setleri listesi:** Çekirdek bölütleme, epitel bölütleme, tübül bölütleme, lenfoma alt tip sınıflandırma, invaziv duktal karsinom, mitoz tespiti.
- **Kaggle Histopathologic Cancer Detection** (ekrandan, 02:40:00): Lenf düğümü kesitlerinin histopatolojik taramalarında metastatik dokuyu tespit etme yarışması. Ekrandaki açıklamaya göre bir yamaya pozitif etiket verilmesi, yamanın merkezindeki 32×32 piksellik bölgede en az bir tümör pikseli bulunduğu anlamına gelir; dış bölgedeki tümör dokusu etiketi etkilemez.
- **ISIC deri lezyonu (skin lesion) veri seti:** Melanom tespiti yarışması; veri setinin ve değerlendirmenin nasıl yapılacağı sitesinde anlatılır.
- **BreakHis** (meme kanseri histopatolojisi), **serviks** veri setleri (Herlev ve başka serviks veri setlerinin toplandığı bir derleme), floresan hücre bölütleme veri seti.

<!-- BELİRSİZ: Altyazıda "Extended Corel-Cancel Grading" ve "Corel-CNCF concept" olarak geçen veri seti adları (02:38:33-02:38:43) karede görünmüyor; büyük olasılıkla genişletilmiş kolorektal kanser derecelendirme veri setleri kastediliyor. -->

### 18.2 Yöntem alanları

Hoca tahtaya şu yöntem alanlarını yazdı (ekrandan, 02:45:00):

- Topluluk öğrenme (ensemble learning), transfer öğrenme, aktif öğrenme
- Manifold öğrenme, seyrek (sparse) öğrenme, sözlük tabanlı (dictionary based) öğrenme
- İşbirlikçi (collaborative) öğrenme
- Uzamsal bilgi çıkarma
- Optimizasyon tabanlı bölütleme
- Derin öğrenmeyle sınıflandırma, derin öğrenmeyle bölütleme
- Çizge (graph) tabanlı yöntemler, Graph CNN ve CNN varyantları

Veri setleri sınıflandırma ya da bölütleme için kullanılabilir; tahtada sınıflandırma sütununa BreakHis, CRC doku fenotipleme ve deri lezyonu yazıldı. Hoca literatürde 2016 ve sonrasının taranmasını önerdi.

### 18.3 Derin öğrenmeyle bölütleme derlemesi

Hoca bölütleme çalışacaklara yol gösterici bir derleme makalesi açtı (arXiv 2001.05566, ekrandan, 02:55:00). Hocanın aktardığına göre makale konvolüsyonel yöntemlerden başlayıp GAN'lar ve otokodlayıcılar gibi derin öğrenme yapılarına, piramit yapılarına, kodlayıcı-kod çözücü (encoder-decoder) tabanlı modellere, çok ölçekli ve piramit tabanlı yöntemlere, dikkat (attention) tabanlı modellere ve üretici modellerle çekişmeli (adversarial) eğitime kadar güncel yöntemleri derli toplu anlatıyordu. Hoca her alt başlığın ayrı bir çalışma konusu olabileceğini söyledi; örneğin yalnız dikkat tabanlı bölütleme modelleri çalışılabilir.

Ekrandaki zaman çizelgesi 2014-2020 arasındaki iki boyutlu bölütleme algoritmalarını gösteriyordu; örnekler: FCN (VGG16), CNN+CRF, U-Net, SegNet, DeepLab ve DeepLab V3, Mask-RCNN, PSPNet (Pyramid Scene Parsing Network), Feature Pyramid Network, Panoptic FPN, HRNet. Makalede veri setleri de anlatılıyordu (ör. PASCAL VOC, MS-COCO).

> **Ek bilgi (derste anlatılmadı):** arXiv 2001.05566, büyük olasılıkla Minaee ve arkadaşlarının "Image Segmentation Using Deep Learning: A Survey" başlıklı derlemesidir. Zaman çizelgesinde turuncu bloklar anlamsal (semantic), yeşil bloklar örnek (instance), sarı bloklar panoptik bölütleme algoritmalarını gösterir.

## Örnek Sorular

**Soru 1** (derste sözlü, 00:23:23-00:25:28): Eğitim verisine medyan süzgeç ve normalizasyon uygulanmış bir modelde, test verisine bu işlemler uygulanmazsa ne olur?

> **Çözüm:** Model katsayıları ve karar yüzeyleri ön işlenmiş eğitim verisinin özelliklerine göre oluşmuştur. Ön işleme uygulanmamış test örneği daha gürültülü olur ya da öznitelik uzayında farklı bir aralıkta kalır; karar sınırının öbür tarafına düşüp yanlış sınıfa atanabilir. Bu yüzden eğitimdeki bütün ön işleme adımları teste de aynen uygulanmalıdır.

**Soru 2** (derste sözlü, 00:31:38-00:32:03): PCA ile elde edilen 100 eksenin ilk 10'unun özdeğeri büyük, kalan 90'ınınki çok küçükse ne yapılır ve bunun yararı nedir?

> **Çözüm:** Veriyi ayrıştırmak için ilk 10 eksen yeterlidir, kalan 90 eksen atılır (boyut azaltma). Öznitelik sayısı $d$ azaldığı için, karmaşıklığı $d$'ye bağlı algoritmaların (tahtadaki örnekte $O(d^2)$) hesap yükü azalır.

**Soru 3** (derste sözlü, 01:24:07-01:24:47): Eğitim setinde belli bir örnek bulunmadığında karar yüzeyi farklı yerden geçiyorsa, aradaki bir test noktasının sınıfı ne olur? Bu ne gösterir?

> **Çözüm:** Tahtadaki örnekte $x$ noktası birinci karar yüzeyiyle 1 numaralı sınıfa, ikinci (mavi) karar yüzeyiyle 2 numaralı sınıfa atanır. Bu, modelin eğitim verisine bağımlı olduğunu gösterir; eğitim verisi sınıfları iyi temsil etmelidir. K katlı çapraz doğrulama bu bağımlılığı azaltır.

**Soru 4** (ekrandan, 02:15:00): `traintestMat{1}` yapısında `minX=138`, `maxX=342`, `minY=156`, `maxY=382` ve `xData` 46535×3'tür. Bu sayılar nasıl tutarlıdır?

> **Çözüm (derste verilmedi):** Kesilen bölgenin bir kenarı $342-138+1=205$, diğer kenarı $382-156+1=227$ pikseldir; bu `IorgCrop`'un 205×227×3 boyutuyla uyuşur. Toplam piksel sayısı $205\times 227=46535$'tir. Her piksel bir satır, üç renk kanalı üç sütun olduğundan `xData` 46535×3 olur (python ile doğrulandı).

**Soru 5** (ekrandan, 02:25:00): 2000 örnekli test setinde SVM modelinin doğruluğu %91,40 ise kaç örnek doğru sınıflanmıştır ve `cerror` fonksiyonu hangi değeri verir?

> **Çözüm:** Doğru sınıflanan örnek sayısı $0{,}914\times 2000=1828$, yanlış sınıflanan $172$'dir. `cerror` yanlış oranını verir: $172/2000=0{,}0860$. Ekranda `1-cerror(YhatSVM,testdata.y)` = 0,9140 bulunmuştur.

## Dersin Toparlaması

Bu derste biyomedikal bir makine öğrenmesi probleminin bütün adımları sırayla ele alındı: ham verinin elde edilmesi, ön işleme ve bu işlemlerin test verisine de aynen uygulanması, verinin eğitim/doğrulama/test diye bölünmesi, zaman domeni ölçümleri ya da dönüşüm tabanlı yöntemlerle öznitelik çıkarma, boyut azaltma ve öznitelik seçme, eğiticili ya da eğiticisiz model kurma, morfolojik son işleme ve k katlı çapraz doğrulama, doğruluk, F-ölçütü, kappa, IoU ve Dice gibi ölçütlerle değerlendirme. Ardından naif Bayes, k-NN, sinir ağları (perseptron, MLP, RBF), derin öğrenme, SVM ve çekirdek yöntemleri, topluluk öğrenme ve kümeleme yöntemleri tanıtıldı.

Dersin ikinci yarısında bu kavramlar somut bir örnekle bağlandı: 58 görüntülük bir meme kanseri histopatoloji veri setinde hücre bölütleme. Yalnız RGB'ye dayalı k-means ve piksel sınıflandırmanın neden delikli sonuç verdiği, pikselin çevresinden alınan GLCM, SIFT, SURF ve istatistiksel özniteliklerin neden gerektiği gösterildi; MATLAB'de libsvm ile eğitilen model 2000 test örneğinde %91,40 doğruluğa ulaştı. Son olarak bir araştırma projesinin adımları (veri setini anlama, problem tanımı, literatür taraması), Overleaf'te LaTeX ve BibTeX ile bildiri yazımı ve çalışılabilecek güncel histopatoloji veri setleri ile yöntem alanları anlatıldı. Sonraki derslerde bu yöntemler seçilen veri setlerine uygulanacak.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
