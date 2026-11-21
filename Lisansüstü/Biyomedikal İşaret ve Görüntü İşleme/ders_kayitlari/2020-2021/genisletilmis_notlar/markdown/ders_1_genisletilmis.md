# Ders 1 Genişletilmiş Notu: Derse Giriş, Biyomedikal İşaretler ve Örnekleme

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dersin kapsamı ve yaklaşımı
- 2. Biyomedikal mühendisliği ve işaret işlemenin yeri
- 3. Genel enstrümantasyon sistemi ve veri işleme akışı
- 4. Sensörlerle ölçülen biyomedikal büyüklükler
- 5. EKG işareti, gürültü ve filtreleme
- 6. İşaret işlemenin uygulama alanları, zaman ve frekans domeni
- 7. Bir, iki ve üç boyutlu işaretler
- 8. Sürekli işaretten ayrık işarete: örnekleme
- 9. DSP kısmının nasıl işleneceği
- Örnek Sorular

## 1. Dersin kapsamı ve yaklaşımı

Ders, sinyal işleme, görüntü işleme, makine öğrenmesi ve örüntü tanıma yöntemlerinin bir arada kullanıldığı disiplinlerarası bir derstir. Hoca bu yapıyı tahtada iki parçalı bir dönem olarak çizdi (ekrandan, 00:30:00). Dönemin ilk yarısında, yaklaşık 7-8 hafta boyunca, üç temel alan hızlandırılmış biçimde verilir:

- **Sayısal işaret işleme (DSP):** yaklaşık 4-5 hafta. Özellikle ayrık işaretler üzerinde konvolüsyon ve frekans domeni analizi gibi kavramlar netleştirilecektir.
- **Görüntü işleme (Image Processing):** 1-2 hafta. Slaytlar üzerinden, sık kullanılan temel fonksiyonlar tanıtılarak geçilir.
- **Makine öğrenmesi (ML):** yaklaşık 1 hafta. Temel kavramlar, öznitelik çıkarımı (feature extraction) nedir, standart makine öğrenmesi yöntemleri nasıl çalışır ve neyi amaçlar, buradan derin öğrenmeye geçişe kadar olan kısım.

Bu üç alanın verilmesinin nedeni, dönemin ikinci yarısında yapılacak projedir. Projede biyomedikal veri kümeleri, derste öğrenilen modüllerle ve öğrencinin dışarıdan edindiği bilgilerle işlenir; hedef, ulusal ya da uluslararası bir konferans bildirisi, daha da ilerletilirse bir dergi makalesidir. Tahtadaki çizimde proje kutusundan önce "Datasetler" notu ve sona doğru "yenilikçi" vurgusu yer alır (ekrandan, 00:30:00).

Uygulamalar MATLAB ya da Python ile yapılabilir. Hoca, bu ortamlara yabancı olanların başlangıç düzeyindeki ("Introduction to MATLAB", "Introduction to Python", "Introduction to Machine Learning") çevrim içi eğitimlerle eksiklerini kapatmasını önerdi. Hesaplama ortamı olarak Google Colab gibi bulut hizmetleri öneriliyor; MATLAB'ın da bulut hesaplama hizmeti olduğunu belirtti.

Veri kümesi olarak hocanın üzerinde yoğunlaştığı alan histopatolojidir, ancak MR görüntüleri, göz verileri ya da başka biyomedikal veriler de seçilebilir. Yurtdışı üniversitelerin siteleri ve Kaggle gibi yarışma siteleri veri kaynağı olarak önerildi.

### 1.1 Araştırma yöntemi

Hocanın tarif ettiği çalışma biçimi şöyledir: Güncel yayınlarda sık sık yeni bir yöntem önerilir ve kodu paylaşılır. Önce bu yöntem anlaşılır ve kendi veri kümemize uygulanır (implemente edilir). Ardından "biz bunun üzerine ne yenilik önerebiliriz?" sorusu sorulur. Ders, işaret işleme, görüntü işleme, makine öğrenmesi ve bir veri kümesini birleştiren disiplinlerarası bir çalışmayı bilimsel bir yayına dönüştürmenin yolunu öğretmeyi amaçlar.

> **Hocanın vurgusu:** Dersin asıl çıktısı projedir; işaret işleme, görüntü işleme ve makine öğrenmesi kısımları bu projeye hazırlık olarak verilir.

## 2. Biyomedikal mühendisliği ve işaret işlemenin yeri

Hoca slaytlara Polikar'ın sayısal işaret işleme dersinin giriş sunumuyla ("ECE 09.351.01 Digital Signal Processing, Lecture 1: Introduction") başladı (ekrandan, 00:40:00).

Dersin amacı, dış dünyadan sensörler aracılığıyla elde edilen veriyi işlemektir. Dış dünya analogdur, yani süreklilik gösterir; bu veri çeşitli aletler yardımıyla alınır, analiz edilir ve anlamlandırılır. Temel yapı taşı sensör, sensörün kalitesi ve kullanım alanıdır. Aynı yöntemler insan vücudu yerine yeryüzü araştırmalarında kullanılırsa uzaktan algılama ve jeofizik uygulamaları ortaya çıkar.

Burada "bilgisayar" sözcüğü yalnız dizüstü, masaüstü ya da iş istasyonu anlamına gelmez; hesaplama yapan bir mikrodenetleyici ya da işlemcili herhangi bir sistem olabilir.

Bu alan aynı zamanda biyomedikal mühendisliği (Biomedical Engineering) adıyla özelleşmiş bir alandır. Biyomedikal mühendisliği yalnız hesaplama yapmaz; robotik, biyomalzeme gibi çok geniş bir çalışma alanı vardır. Slaytta sayılan alt alanlar:

- Biyoenstrümantasyon: biyolojik ortamda çalışan aletlerin yapılması.
- Biyomalzemeler: örneğin diz kapağına konan uzun ömürlü titanyum eklemler.
- Biyomekanik.
- Biyoişaretler ve biyogörüntüler: bu dersin doğrudan girdiği alanlar.
- Biyosistemler, biyotransport, hücre mühendisliği, klinik mühendisliği, doku mühendisliği, rehabilitasyon mühendisliği.
- Biyoistatistik: var olan verinin istatistiksel olarak anlamlandırılması; en çok kullanılan alanlardan biri.
- Tıbbi bilişim (Medical Informatics).

Bilgisayar mühendisliği açısından bakıldığında elde bir veri vardır ve bu verinin analiz edilip anlamlandırılması, sonuç çıkarılması gerekir. Sayısal yöntemler kullanıldığı için, tıp doktorlarının bilmediği ve onlara yardımcı olacak karar destek sistemleri kurulur.

## 3. Genel enstrümantasyon sistemi ve veri işleme akışı

"General Instrumentation Systems" başlıklı slaytta bir ölçüm sisteminin blok şeması verilir (ekrandan, 00:45:00):

- **Measurand (ölçülen büyüklük):** ölçülecek fiziksel büyüklük; şemada insan vücudu olarak çizilmiştir.
- **Sensor:** iki bloktan oluşur: birincil algılama elemanı (primary sensing element) ve değişken dönüştürme elemanı (variable conversion element). Hoca bu ikisini birlikte daire içine alıp "Transducer" (dönüştürücü) diye yazdı.
- **Signal processing (işaret işleme)**, ardından **output display (çıktı gösterimi)** ve algılanabilir çıktı (perceptible output).
- **Data storage (veri depolama)** ve **data transmission (veri iletimi)**.
- Kesikli çizgilerle bağlı isteğe bağlı bloklar: **calibration signal (kalibrasyon işareti)**, **control and feedback (kontrol ve geri besleme)**, **power source (güç kaynağı)** ve vücuda uygulanan **radyasyon, elektrik akımı ya da başka bir enerji**.

Slayttaki açıklama: sensör, ölçülen büyüklükten gelen enerjiyi ya da bilgiyi başka bir biçime (genellikle elektriksel) dönüştürür; bu işaret işlenir ve insanın bilgiyi algılayabileceği biçimde gösterilir. Kesikli çizgiyle gösterilen eleman ve bağlantılar bazı uygulamalarda isteğe bağlıdır.

Hoca şemada ölçülen büyüklüğü, dönüştürücüyü ve veri depolamayı işaretledi. Bu dersin özel durumu, verilerin çoğunlukla zaten kaydedilmiş olarak gelmesidir; çalışma depolanmış veriden başlar.

> **Ek bilgi (derste anlatılmadı):** Dönüştürücü (transducer), bir enerji biçimini başka bir enerji biçimine çeviren düzenektir. Biyomedikal ölçümde genellikle sıcaklık, basınç ya da iyon akımı gibi bir fiziksel/kimyasal etki elektriksel gerilime çevrilir, çünkü elektriksel işaret kolayca yükseltilir, sayısallaştırılır ve işlenir.

### 3.1 Kaydedilmiş veriden sonuca

Hocanın tarif ettiği akış şöyledir: insan deneği ve sensör sistemleri ile kaydedilmiş veri alınır; ardından ön işleme (preprocessing), modelleme ve son işleme (post-processing) adımları gelir; en sonda amaca göre sınıflandırma (classification) ya da bölütleme yapılır.

Çalışmanın illa makine öğrenmesi tarafında olması gerekmez. Örnekler:

- Görüntü işlemede gürültü giderimi üzerine çalışıp daha iyi sınıflandırmaya katkı sağlayan bir yöntem önermek.
- MR verileri gibi çok büyük verilerin sıkıştırılması üzerine çalışmak.
- Histopatoloji verilerinde yeni öznitelik çıkarım yöntemleri geliştirmek.

Son örnekte bile çalışma ister istemez makine öğrenmesine kayar: yeni bir öznitelik çıkarım yönteminin gerçekten başarılı olup olmadığını göstermek için en azından bir sınıflandırma deneyi yapmak gerekir.

## 4. Sensörlerle ölçülen biyomedikal büyüklükler

Sensörlerle ölçülebilecek büyüklüklerin en basiti vücut sıcaklığı ve deri yüzeyi sıcaklığıdır. Kimyasal sensörlerle kan testleri yapılabilir. Elektriksel işaretler incelendiğinde, deri yüzeyindeki elektriksel potansiyel değişimleri ölçülür. Slaytta sayılan büyüklükler:

- Kan akışı, kan basıncı, kalp debisi (cardiac output).
- **EEG (elektroensefalografi):** beyin işaretleri. Bir öğrenci lisansta EEG beyin verisi üzerinde çalıştığını belirtti.
- **EMG (elektromiyografi):** kas hareketlerinin elektriksel seviyesi. Hoca, organ kaybı yaşayan hastalarda vücudun geri kalanından alınan elektriksel işaretle mekanik bir sistemin (protezin) çalıştırılması çalışmalarını örnek verdi.
- **EKG (elektrokardiyografi):** kalbin atımlarıyla oluşan işaretler.
- **ERG (elektroretinografi):** gözle ilgili işaretler.
- Kimyasal büyüklükler: pH, karbondioksit seviyesi, oksijen seviyesi (hastaların parmağına takılan sensörler ve kan testleri).
- Sıcaklık: en çok kullanılan ölçümlerden biri.

En çok duyulanlar EKG ve EEG'dir; EMG biraz daha az bilinir.

Bu ölçümlerin amacı, ölçülen değişkenin normal insanlarla hastalıklı insanlar arasındaki farkını ortaya koymaktır. Bunun için temel bazı belirteçlerin çıkarılması gerekir; böylece hasta olan ve olmayan bireyler arasındaki fark anlaşılabilir.

## 5. EKG işareti, gürültü ve filtreleme

### 5.1 EKG dalga biçimi

Hoca bir EKG örneği üzerinden konuyu açtı. Konu üzerinde uzmanlaşmış biri, EKG verisinin normal insanlardaki yapısını çıkarabilir. Slaytta gösterilen dalga biçimi (ekrandan, 00:50:00):

- Dikey eksen milivolt (mV), yaklaşık -0,5 ile 1,0 mV arası; yatay eksen saniye, 0 ile 0,8 s arası.
- **P tepesi:** başta küçük bir tümsek (yaklaşık 0,1 mV).
- **QRS kompleksi:** Q'da küçük bir iniş, R'de yaklaşık 1,0 mV'luk sivri tepe (yaklaşık 0,2 s civarı), S'de yaklaşık -0,4 mV'a iniş.
- **S-T segmenti:** QRS'ten sonra düz kalan bölüm.
- **T tepesi:** yaklaşık 0,2 mV'luk geniş tümsek; işaret yaklaşık 0,6 s'de taban çizgisine döner.
- **P-Q aralığı:** P'nin başından Q'ya kadar; **Q-T aralığı:** Q'dan T'nin sonuna kadar (yaklaşık 0,18 s ile 0,6 s arası).
- Renk anahtarı: mavi çubuk kulakçık kasılması (atrial contraction) P dalgası bölgesinde, sarı çubuk karıncık kasılması (ventricular contraction) QRS'ten T'ye uzanan bölgede.

Bu işaret, kalbin kan pompalaması sırasında vücut yüzeyinde oluşan elektriksel değişimlerin, hastanın vücut yüzeyine yapıştırılan elektrotlarla (problarla) alınmasıyla elde edilir.

Hoca slayttaki EKG ölçüm örneğinde giriş işaretinin milivolt seviyesinde olduğunu ve bir DC ofset geriliminin bulunduğunu okudu; bu değerlerin tecrübeyle çıkarıldığını söyledi. <!-- BELİRSİZ: Altyazıda giriş işareti "5 milivolt" olarak geçiyor; DC ofset değeri söylenmedi. İlgili slayt mevcut karelerde yok, değer doğrulanamadı. -->

> **Ders sonrası not:** Hoca derste "atrial karıncık, ventriküler kulakçık galiba" diyerek terimleri karıştırdığını kendisi de belirtti. Doğrusu: atrium **kulakçık**, ventrikül **karıncıktır**. Slayttaki renk anahtarı da buna uygundur: P dalgası kulakçık kasılmasına, QRS-T bölgesi karıncık kasılmasına karşılık gelir.

### 5.2 Sinyal kavramı ve gürültü

Dersin en önemli kavramı işarettir (sinyal). Bir, iki ya da üç boyutlu çalışılsın, temelde çalışılan şey işaretlerdir ve her işaret bir bilgi taşır; amaç bu yararlı bilgiyi çıkarmaktır.

Sensör kullanıldığında, tek boyutlu bir işaret de olsa iki boyutlu bir görüntü de olsa, içinde gürültü bulunur. Gürültü elektronik ortamdan ya da doğrudan temas olmamasından kaynaklanabilir. Slayttaki ham EKG örneğinde, vücuda takılan elektrotlar nedeniyle oluşan gürültü ana işaretin üzerine binmiş durumdadır. Gürültünün karakteristiğine göre filtreleme yapıldığında işlenebilecek temiz işaret elde edilir.

Bundan sonraki adım, işareti segmentlere bölüp sağlıklı bir kalp verisiyle karşılaştırmak ve hastalık belirtisinin nerelerde ve ne sıklıkta görüldüğünü analiz etmektir. Bu süreçte bilgisayar mühendisliği açısından kullanılan araçlar sırasıyla işaret işleme yöntemleri, (tek boyutlu işaretin) işlenmesi ve en sonda makine öğrenmesidir. Hoca bunun günümüzde hızla gelişen bir araştırma alanı olduğunu vurguladı.

## 6. İşaret işlemenin uygulama alanları, zaman ve frekans domeni

### 6.1 Uygulama alanları

Slaytta, bilginin işlenmesi ve çıkarılması açısından işaret işlemenin kullanıldığı alanlar sıralanmıştır:

- Bilginin aktarılması (haberleşme), işaret güvenliği, işaretlerin çoğullanması, veri sıkıştırma.
- Gürültü giderimi, konuşmacı tanıma, ses işleme (audio processing).
- İşaretlerin zenginleştirilmesi (enhancement): daha rahat işlenebilmeleri için.
- Eşitleme (equalization): farklı sistemlerle alınmış işaretlerin ortak bir veri tabanında işlenebilmesi için.
- Görüntü işleme, gürültü giderimi (denoising), veri zenginleştirme.
- İşaretin içine bilgi gömme ve bu bilgiyi geri elde etme.
- Veri analizi ve öznitelik çıkarımı: verinin içindeki gizli yapıyı ortaya çıkarmak.
- Frekans ve spektral analiz.

<!-- BELİRSİZ: Altyazıda "sistem girişimini" olarak geçen madde büyük olasılıkla "system identification" (sistem tanılama) ya da "interference" (girişim); slayt karede yok. -->

Hoca son iki maddenin (veri analizi/öznitelik çıkarımı ve frekans/spektral analiz) şu anki çalışma alanlarına daha yakın olduğunu belirtti.

### 6.2 Zaman domeni ve frekans domeni

Şimdiye kadar çizilen işaretler zaman domenindedir: bağımsız değişken zamandır ($t$) ve değerler her anda işaretten ölçülen genliklerdir. İleriki derslerde frekans domenine geçilecektir. Frekans domeninde değişken artık frekanstır; işaretin içinde barındırdığı frekanslardaki anomaliler bu domende tespit edilmeye çalışılabilir. Frekans analizi, zaman domenindeki gösterime bir alternatif sunar.

## 7. Bir, iki ve üç boyutlu işaretler

Hoca tahtaya bir dünya çizerek dış dünyadaki verilerin genellikle sürekli olduğunu anlattı; dış dünya burada insan vücudu olarak düşünülür (ekrandan, 01:05:00). Örneğin vücut sıcaklığı zaman içinde sürekli değişir ya da bir EKG işareti ölçülür.

- **Bir boyutlu (1D) işaret:** tek bir değişkene göre ölçülen işarettir. Tahtada $x(t)$ olarak, zamana göre değişen bir eğri biçiminde çizildi (ekrandan, 01:00:00).
- **İki boyutlu (2D) işaret:** henüz sayısallaştırılmamış bir fotoğraf ya da bir organın çekilmiş görüntüsü. Burada da süreklilik vardır. Fotoğrafta süreklilik, piksel kavramının olmaması demektir: eski tip fotoğraf makinelerinde kimyasal film şeritleri kullanılırdı; bugünkü telefon ve sayısal kameralardaki gibi piksel yoktu, ışık kaynağının şiddetine göre resim levhaya ya da şeride basılırdı. 1B işarette değişken zamandı; 2B işarette değişkenler $x$ ve $y$'dir, yani uzamsaldır. Uzamsal değişkenin İngilizcesi "spatial"dır (ekrandan, 01:00:00).
- **Üç boyutlu (3D) işaret:** yatan bir hastadan kesitler alınıp kesitlerin görüntüleri art arda konduğunda veri miktarı artar; en, boy ve yükseklikle üç boyutlu veriye geçilir. Tahtada yatan bir hasta ve bir kesit düzlemi olarak çizildi (ekrandan, 01:00:00).

Derste önce bir boyutlu verilerden başlanacak; anlatılanların hepsi diğer boyutlara genelleştirilebilir.

## 8. Sürekli işaretten ayrık işarete: örnekleme

### 8.1 İşlemeyi yapan sistem

Amaç işareti bir hesaplama biriminde işlemektir. Hoca burada bilerek "bilgisayar" yerine daha genel bir ifade kullandı: bu, bir mikrodenetleyicili ya da mikroişlemcili sistem olabilir (tahtada "Computer", "μC", "μP" yazıldı; ekrandan, 01:05:00). Örneğin bir kutunun içine bir sistem yapılmıştır; bir taraftan sensör bilgisi gelir, içindeki mikrodenetleyici bu bilgiyi işleyip dışarıya bir çıktı (örneğin video biçiminde) aktarır. Önemli olan, içinde bilgiyi işleyip anlamlandırabilecek bir kısmın bulunmasıdır.

Sorun şudur: dış dünyadaki sürekli veri doğrudan bilgisayarda incelenebilir mi?

### 8.2 Sürekli işaretin sonsuz bilgisi

Bir öğrenci, bilgisayarda işlemek için verinin dijitale, sonuçta bilgisayarın görebileceği ikili (binary) biçime çevrilmesi gerektiğini söyledi. Hoca, ikili biçime geçmeden önceki süreci açmak için tahtaya $x(t)$ işaretini çizdi (ekrandan, 01:05:00). Bu bir fonksiyondur; ölçülen büyüklük vücut sıcaklığı, nem, kandaki bir maddenin konsantrasyonu gibi herhangi bir şey olabilir.

Bilgisayarda veriyi alıp işlemek için RAM, ROM gibi bellekler vardır. Tahtada işaretin 3. ve 4. saniyeleri işaretlendi ve şu soruldu: bu iki saniye arasında kaç farklı genlik değeri belleğe yüklenebilir? Bir öğrenci önce şekle bakarak 3 dedi, sonra "kaç parçaya bölersek o kadar" diye düzeltti. Hocanın vardığı sonuç: bunun bir sonu yoktur. Sürekli (continuous) işaretler en küçük aralıkta bile sonsuz sayıda bilgi içerir.

Demek ki yapılması gereken ilk şey **örneklemedir**. Örneklemenin sıklığı, işaretin kaliteli biçimde örneklenmesini belirler. Örnekler seyrek alınırsa aradaki değişimler kaçırılır.

### 8.3 Sık ve seyrek örneklemenin ödünleşimi

Hoca tahtada aynı işaretin bir bölümünü sık, bir bölümünü seyrek örnekledi (ekrandan, 01:10:00). Sık örneklenen kısımda örnek noktaları işaretin dalgalanmalarını izlerken, seyrek örneklenen kısımda (yeşil daire içinde) örnekler arasındaki değişimler kaybolmaktadır.

- **Sık örnekleme:** Avantajı, işaret üzerindeki en küçük değişimin bile yakalanmasıdır. Dezavantajı, bellekte çok fazla yer ayırmak gerekmesidir; hoca bunu hesaplama ve depolama maliyeti olarak özetledi.
- **Seyrek örnekleme:** Sık örneklemenin avantajı dezavantaja döner. Daha az bellek kaplar, ama alınan işaretin doğruluğu azalır.

> **Ek bilgi (derste anlatılmadı):** Örnekleme sıklığının alt sınırını Nyquist-Shannon örnekleme teoremi verir: işaretteki en yüksek frekans bileşeni $f_{max}$ ise, işaretin örneklerinden tam olarak geri elde edilebilmesi için örnekleme frekansının $f_s > 2 f_{max}$ olması gerekir. Daha seyrek örneklemede örtüşme (aliasing) oluşur. Bu konu büyük olasılıkla dersin DSP kısmında ele alınacaktır.

### 8.4 $x(t)$'den $x[n]$'ye

Analog işaret sürekli bir işarettir: zamanın her anında tanımlıdır ve $x(t)$ ile gösterilir. Bilgisayarın içinde ise alınan her örnekle birlikte zaman değişkeni yerini indislere bırakır: birinci örnek, ikinci örnek, üçüncü örnek... yani $n = 1, 2, 3, 4, \dots$ İşaret artık $x[n]$ biçimindedir. İki gösterim arasındaki farklar:

- Parantez köşeli paranteze dönüştü: bu, sürekliden (continuous) ayrığa (discrete) geçildiğini gösterir.
- $t$, $n$'ye dönüştü: sürekli değişken yerini indis değerlerine bıraktı.

$$x(t) \;\longrightarrow\; x[n]$$

Bu kavramların ayrıntısı bir sonraki derste işlenecektir.

## 9. DSP kısmının nasıl işleneceği

**Soru:** Lisansta alınan sayısal işaret işleme dersi neredeyse bir matematik dersi gibiydi. Bu derste matematiksel kısım nasıl ele alınacak; klasik algoritmalar mı kullanılacak, yoksa analogdan dijitale çevirme gibi işlemlerin uygulaması kendimiz mi yazılacak?

**Cevap:** Ders aslında matematik ağırlıklıdır, ama hoca temel kavramları olabildiğince basit matematikle anlatacağını söyledi. Konvolüsyon ve frekans analizinde çeşitli formülasyonlar vardır; ancak amaç işin özünü anlamak olduğu için kavramların ne anlama geldiği ayrıntılı açıklanacaktır. Normalde bir dönemlik olan sayısal işaret işleme dersi, mantığına ve anlamına odaklanan 4-5 haftalık hızlandırılmış bir kurs olarak verilecek ve yalnız temel kavramlar anlatılacaktır. Öğrencilerin temel işlemleri yapabilecek düzeyde olması beklenir.
## Örnek Sorular

**Soru 1** (derste sözlü, 00:59:29): Bir boyutlu ve iki boyutlu işaretten sonra, üç boyutlu bir işaret deyince ne anlarsınız?

> **Cevap (derste verildi):** Yatan bir hastadan kesitler alınıp kesit görüntüleri art arda konduğunda en, boy ve yükseklikten oluşan hacimsel bir veri elde edilir; bu üç boyutlu bir işarettir.

**Soru 2** (derste sözlü, 01:01:28): Dış dünyadan gelen sürekli veriyi doğrudan bilgisayar ortamına aktarabilir miyim?

> **Cevap (derste verildi):** Hayır. Veri önce dijitale, sonuçta bilgisayarın görebileceği ikili biçime çevrilmelidir. Bunun ilk adımı örneklemedir, çünkü sürekli işaret sınırsız sayıda değer içerir.

**Soru 3** (derste sözlü, 01:04:42; tahtada çizim, ekrandan, 01:05:00): $x(t)$ analog işaretinin 3. ve 4. saniyeleri arasındaki bölümü bilgisayarın RAM'ine konacak. Bu aralıkta kaç farklı genlik değeri alınıp belleğe yazılabilir?

> **Cevap (derste verildi):** Sınırı yoktur. Sürekli işaret zamanın her anında tanımlıdır ve en küçük aralıkta bile sonsuz sayıda değer içerir. Kaç değer alınacağını örnekleme sıklığı belirler.

**Soru 4** (derste sözlü, 01:06:43): Örneklemeyi sık aralıklarla yapmanın avantajı ve dezavantajı nedir?

> **Cevap (derste verildi):** Avantajı, işaretteki en küçük değişimin bile yakalanmasıdır. Dezavantajı, bellekte çok yer kaplaması, yani hesaplama ve depolama maliyetinin artmasıdır.

**Soru 5** (derste sözlü, 01:08:24 ve 01:09:47): Örnekleri seyrek (gevşek) aralıklarla almanın avantajı ve dezavantajı nedir?

> **Cevap (derste verildi):** Sık örneklemenin tersidir: daha az bellek kaplar, ama aradaki değişimler kaçırıldığı için alınan işaretin doğruluğu azalır.

## Dersin Toparlaması

Bu ilk derste dersin disiplinlerarası yapısı tanıtıldı: sayısal işaret işleme, görüntü işleme ve makine öğrenmesinin temel kavramları kısa sürede verilecek, ardından bir biyomedikal veri kümesi üzerinde, güncel bir yöntemi uygulayıp geliştirmeye dayanan bir araştırma projesi yapılacaktır. Biyomedikal mühendisliğinin alt alanları, genel enstrümantasyon sisteminin blokları (ölçülen büyüklük, sensör/dönüştürücü, işaret işleme, depolama), sensörlerle ölçülen büyüklükler (EEG, EMG, EKG, ERG, kimyasal büyüklükler, sıcaklık) ve EKG dalga biçimi üzerinden gürültü ve filtreleme ihtiyacı ele alındı.

Dersin son kısmında bir, iki ve üç boyutlu işaret kavramları ile sürekli işaretin bilgisayarda işlenebilmesi için örneklenmesi gerektiği anlatıldı; örnekleme sıklığının doğruluk ile maliyet arasındaki ödünleşimi tartışıldı ve $x(t)$ sürekli işaretinden $x[n]$ ayrık işaretine geçiş tanıtıldı. Bir sonraki derste ayrık işaretler ve bu geçişin ayrıntıları üzerinde durulacaktır.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
