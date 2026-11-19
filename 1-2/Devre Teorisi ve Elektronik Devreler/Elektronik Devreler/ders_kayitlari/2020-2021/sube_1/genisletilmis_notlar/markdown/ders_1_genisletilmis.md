# Ders 1 Genişletilmiş Notu: Derse Giriş, Analog ve Sayısal İşaretler, Örnekleme ve Sinüzoidal İşaret

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dersin Kapsamı ve Kaynakları
- 2. Elektronik Devrelerin Donanım Dersleri Arasındaki Yeri
- 3. Transistörün Tarihsel Önemi
- 4. Analog Dünya ve Sayısal Dünya
- 5. Ayrıklaştırma ve Örnekleme
- 6. Fourier Analizine Giriş
- 7. Sinüzoidal İşaret: Genlik, Frekans, Faz
- 8. DC Bileşen ve İşaretlerin Frekans Bandı
- Örnek Sorular

## 1. Dersin Kapsamı ve Kaynakları

Bu ders, bilgisayar mühendisliği öğrencilerine donanımın temel kavramlarını veren bir giriş dersidir. Hoca, dersin elektronik mühendisliğindeki derin analizlere girmeden temel kavramları vereceğini, dikkatle takip edildiğinde rahat anlaşılabilecek bir ders olduğunu söyledi. Devre Teorisi'nde öğrenilen analiz yöntemlerinin üzerine artık gerçek elemanlarla analog devrelerin kurulması ve çözülmesi gelecektir.

Dönem boyunca işlenecek konular şunlardır:

- Elektroniğin temel kavramları ve yarı iletken fiziği
- Diyot modelleri, doğrultucular, zener diyot ve diğer diyot uygulamaları <!-- BELİRSİZ: altyazıda "lojik diyotlar" geçiyor (00:12:20); kastedilen büyük olasılıkla özel amaçlı diyotlar ya da diyotlu lojik kapılar -->
- Bipolar jonksiyonlu transistörler (BJT) ve DC analizleri
- FET transistörler
- İşlemsel yükselteçler (op-amp)

Her konudan sonra bol soru çözülecek, ayrıca o ana kadarki konuları toplu çözen haftalar olacaktır.

Dersin ana kaynağı Boylestad ve Nashelsky'nin *Electronic Devices and Circuit Theory* kitabıdır. Slaytlar bu kitabın sunumlarından alınmıştır ve kitapta çok sayıda çözümlü örnek vardır. Kitabın Türkçe çevirisi de bulunmaktadır. Slaytlar görsel destek içindir; anlatım ağırlıklı olarak yazı tahtası üzerinde, devreler çizilerek yapılır.

Devreleri denemek için kurulum gerektirmeyen çevrim içi simülatörler kullanılabilir. Hoca derste CircuitLab'i açtı; örnek devrede 1 kHz'lik bir sinüs kaynağı, $10\,\Omega$'luk kaynak direnci, 1N5817 diyot, $10\,\mu F$ kondansatör ve $100\,\Omega$'luk yük direnci vardı (ekrandan, 00:20:00). Simülatörde lojik kapılar ve ölçüm noktaları da bulunuyor. Bir öğrencinin önerisiyle Proteus da elektronik devreler için uygun bir program olarak anıldı.

> **Ek bilgi (derste anlatılmadı):** CircuitLab'in açılış devresi bir yarım dalga doğrultucu ve filtre kondansatöründen oluşur: diyot yalnız pozitif yarım dalgaları geçirir, kondansatör çıkışı düzleştirir. Doğrultucular ilerleyen haftalarda diyot konusunda işlenecektir.

## 2. Elektronik Devrelerin Donanım Dersleri Arasındaki Yeri

Hoca, bilgisayar mühendisliğinde görülen donanım derslerini tahtada bir zincir olarak sıraladı (ekrandan, 00:25:00): Devre Teorisi, Yarı İletken Fiziği, Elektronik Devreler, Lojik Devreler, Bilgisayar Donanımı, Bilgisayar Mimarisi, Mikroişlemciler ve Gömülü Sistemler. Yarı İletken Fiziği, Elektronik Devreler'e bir giriş niteliğindedir.

Hocaya göre Lojik Devreler'in bu dersten sonra alınması daha mantıklı olurdu, çünkü lojik kapıların içinde bu derste öğrenilecek transistörler vardır.

Donanımdan yazılıma geçiş işletim sistemleri üzerinden olur. İşletim sistemleri bazen donanımla, mikroişlemciler konusuyla kesişir. Onun üzerine bilgisayarın donanım özelliklerini bilmeyi gerektiren düşük seviyeli diller (Assembly, C) gelir. En üstte ise Python gibi yüksek seviyeli diller bulunur.

### 2.1 Basit bir transistörlü devre

Bu bilginin pratikte nerede işe yarayacağını göstermek için hoca basit bir devre çizdi (ekrandan, 00:25:00). Girişe bir direnç üzerinden +5 V uygulanır; girişin altına bir kare dalga çizilmiştir. Direnç transistörün tabanına bağlanır. Transistörün kolektörü bir dirençle $V_{CC}$ beslemesine bağlıdır ve çıkış $V_{out}$ buradan alınır; emetör toprağa gider. Girişe +5 V verildiğinde çıkışta 0 mı 1 mi oluşacağı sorusu, dijital bilginin elektrik sinyalleriyle nasıl taşındığını gösterir. Bu bit dizileri hafızada 8 ya da 16 bitlik gözlerde saklanır. Devrenin çalışması ilerleyen haftalarda ayrıntılı anlatılacaktır.

Hoca, bilgisayar mühendisi ile programcı arasındaki farkı da bu bağlamda açıkladı: Bilgisayar mühendisi bir programcının yapabildiğini yapabilir, ama sistemi bir üst seviyeden, daha geniş kapsamlı görür. Elektronik, lojik ve sistem bilgisi özellikle savunma sanayi, biyomedikal ve sağlık alanındaki işlerde büyük avantaj sağlar.

## 3. Transistörün Tarihsel Önemi

Hoca, bilgisayar mühendisliğinin doğuşunu 1950'li yıllara bağladı ve bu doğuşu hızlandıran buluşun transistör olduğunu söyledi (ekrandan, 00:30:00). Transistörler iki amaçla kullanılır:

- **Gerilim yükseltici** olarak,
- 1 ve 0 mantığıyla çalışan **ikili (binary) elektrik devrelerinin** çok daha ucuza yapılması ve farklı iklim şartlarında çalışabilmesi için.

### 3.1 Tüplü yapılar

Bu tarihten önce de benzer işi gören yapılar vardı: cam gövdeli, altında çok sayıda bacağı olan tüpler. Tüplü radyolar ve eski televizyonlar açıldığında önce ısınmaları, kararlı çalışma sıcaklığına gelmeleri beklenirdi. Bu yapıların sakıncaları şunlardı:

- Sıcak ve soğuk havadan çok etkilenirler.
- Cam oldukları için fiziksel etkilere dayanıksızdırlar ve kararlı çalışmazlar.
- Aşırı ısındıklarında özelliklerini kaybedebilirler.
- Yan yana çok sayıda kullanıldıklarında çevreye büyük ısı verirler.

> **Ders sonrası not:** Hoca tüplü yapıyı "tüplü analog transistör" diye andı. Doğrusu bu elemanlar vakum tüpü (elektron tüpü) olarak adlandırılır; transistör değildir ama yükseltme ve anahtarlama işini görürler. Transistör büyük olasılıkla 1947'de Bell Laboratuvarları'nda icat edilmiştir.

Silisyum ve germanyum gibi yarı iletkenlerle yapılan transistörler bu sorunları çözdü ve devreleri çok ucuzlattı. Elde taşınabilir transistörlü radyolar büyük bir devrim oldu. Eskiden sehpaların üzerinde duran büyük radyoların işini bugün telefonun içindeki küçük bir çip görür.

> **Ders sonrası not:** Hoca ilk taşınabilir transistörlü radyoyu "zannedersem Sony" yaptı dedi. İlk ticari transistörlü radyo büyük olasılıkla 1954'te ABD'de çıkan Regency TR-1'dir; Sony'nin ilk transistörlü radyosu büyük olasılıkla 1955 tarihlidir.

### 3.2 İkinci Dünya Savaşı'nın etkisi

Hoca 1939-1944 tarihlerini sorarak İkinci Dünya Savaşı'na dikkat çekti. Bu savaş elektronik devreler, haberleşme, istihbarat, işaret işleme, görüntü işleme ve uydu teknolojilerinin birlikte hızla gelişmesine yol açtı. Farklı iklim şartlarında çalışabilen taşınabilir cihazlara, telsiz haberleşmesine ve kriptografik cihazlara ihtiyaç vardı. Askeri lojistik açısından koca bir sandık taşımak yerine elde taşınan küçük bir cihazla haberleşmek çok daha mantıklıydı. Dağlara ve sıcak yerlere kurulan uydu haberleşme sistemlerinde de yan yana çok sayıda ısınan cam tüp kullanmak sorun oluşturuyordu.

> **Ders sonrası not:** İkinci Dünya Savaşı 1939-1945 yılları arasındadır; hoca 1939-1944 dedi.

## 4. Analog Dünya ve Sayısal Dünya

Mesleğimiz açısından temel bir şema vardır: dış dünya ve bu dünyadan gelen bilginin işlendiği bilgisayar (ekrandan, 00:35:00). Burada bilgisayar denince telefon, dizüstü bilgisayar, tablet gibi işlem yapabilen her cihaz kastedilir. Hoca, "bilgisayar" adının yanıltıcı olduğunu, aslında yapılan işin hesaplama (compute) olduğunu vurguladı.

Dış dünya **analog**, yani süreklidir; bilgisayar ise **sayısal**, yani ayrıktır (ekrandan, 00:40:00).

### 4.1 Sürekli bilgi

Sınıfta konuşan bir hocanın ses sinyali zamanda süreklidir: zamanın her anında tanımlıdır ve küçük parçalara ayrılamaz. Bu sinyal zamana bağlı bir fonksiyon olarak $x(t)$ diye yazılır. Gözümüzle bir ağaca baktığımızda da onu piksel piksel görmeyiz; gözde piksel kavramı yoktur, görüntü uzayın her noktasında doludur. Piksel, sayısal sistemlere ait bir kavramdır. Analog fotoğraf makinelerinde de durum aynıdır: film, kimyasal solüsyonlu bir kâğıda basılır ve resim bilgisi kâğıdın her noktasında tanımlıdır.

### 4.2 Ayrık bilgi ve hafıza

Sayısal sistemde bir mikrodenetleyici ya da mikroişlemci bilgileri RAM ve ROM'dan alıp işler. RAM bitlerden oluşur ve iki boyutu vardır:

- **Genişlik:** Bir gözün kaç bit olduğu (8, 16, 64 bit). Hoca bunu bir dairenin oda sayısına benzetti. Bugün standart sistemler 64 bitliktir.
- **Boy:** Kaç göz olduğu (512 MB, 1 GB, 8 GB). Bu da binadaki daire sayısına benzer. Örneğin 1024 daire 1 kilo olarak adlandırılır.

Dış dünyanın bilgisini saklamak için onun ayrık olması gerekir. Bu yüzden zaman değişkeni $t$'nin yerine bir indis $n$ gelir: $x(t)$ yerine $x[n]$ (ekrandan, 00:40:00). Bilgi hafızada 1 ve 0 olarak saklanır, ama oraya gelmeden önce bazı işlemlerden geçer.

## 5. Ayrıklaştırma ve Örnekleme

### 5.1 Soru 1: Nasıl ayrıklaştıracağım?

İlk soru, sürekli işaretin nasıl ayrık hale getirileceğidir. Hoca iki ölçüt koydu (ekrandan, 00:45:00):

- En az bilgi kaybı
- Orijinal bilgiye sadakat

Bir boyutlu bir işaret (örneğin ses) bir dizide (array), iki boyutlu bir işaret (örneğin görüntü) bir matriste saklanabilir. Anlatım kolaylığı için ses işareti üzerinden gidildi.

Ayrıklaştırmanın ilk adımı **örnek almaktır**. İşaretten belli aralıklarla değer alınır. Bu aralığa $T_s$ denir; $T_s$ **örnekleme periyodudur**. Alınan örnekler sırayla RAM'e yazılır; tahtada her örnekten RAM'deki bir göze giden oklar çizildi (ekrandan, 00:45:00).

Burada bir sakınca vardır: İki örnek arasındaki değişimler önemliyse ve $T_s$ büyükse bu değişimler kaybolur. Tahtadaki çizimde tepe ve çukur noktalarının seyrek örneklerin arasına düştüğü, yani kaçırıldığı görülür. Bu durumda orijinal bilgiye sadakat sağlanamaz. Bu kayıp her işarette önemli olabilir: işaret bir ses olabileceği gibi biyomedikal bir işaret ya da uydu üzerinden iletilen gizli bir askeri veri de olabilir.

### 5.2 Soru 2: $T_s$'nin genişliği ne olmalı?

Bu sorunun ardından gelen ikinci soru, örnekleme periyodunun ne kadar seçileceğidir. Çok sık örnek alınırsa aradaki değişimler kaçırılmaz, ama $T_s$ çok küçülür. Burada bir ödünleşim (trade-off) vardır.

**Soru:** $T_s$'nin çok geniş alınmasının ve çok sık alınmasının, RAM'de bilgi sakladığımızı düşünerek, avantajı ve dezavantajı nedir?
**Cevap (bir öğrenci):** Seyrek alırsak RAM'de daha az yer kaplar; kısıtlı bir alanımız varsa çok örnek alamayız. Yer sıkıntımız yoksa daha sık alıp orijinale daha yakın bir sonuç çıkarabiliriz. Hoca cevabı doğru buldu.

Hoca buna şunu ekledi: Sık örneklemenin bir alt sınırı yoktur. Örnekler arasına yeni örnekler eklenebilir, bu sonsuza kadar sürer; limitte $T_s$ neredeyse sıfıra, $\varepsilon$ genişliğine indirilebilir ve orijinal işarete kadar gidilir. Ama hafıza kaynağı kısıtlıdır. Bu yüzden amaç, $T_s$'yi aradaki değişimleri kaçırmayacak şekilde **olabildiğince geniş** seçmektir. Bunun bir ölçüsü olmalıdır ve bu ölçüyü Fourier analizi verir.

> **Ek bilgi (derste anlatılmadı):** Bu ölçü örnekleme teoremi (Nyquist-Shannon) olarak bilinir: bir işaretin içerdiği en yüksek frekans $f_{max}$ ise, örnekleme frekansı $f_s = 1/T_s$ en az $2 f_{max}$ olmalıdır. Hocanın bir sonraki derste Fourier analiziyle bu noktaya geleceği büyük olasılıktır.

## 6. Fourier Analizine Giriş

Fourier analizi işaretlerin frekansıyla ilgilenir. 1800'lerde yaşamış matematikçi Fourier bunu işaretler için değil, keyfi (arbitrary) bir matematiksel fonksiyonun bileşenlerine ayrılıp ayrılamayacağını sorarak düşünmüştür.

Fourier'in sonucu basitçe şöyledir: Herhangi bir işaret, ideal olarak sonsuz sayıda sinüzoidal işaretin toplamından oluşur. Hoca tahtada karmaşık bir işaretin, düz bir çizgi (sabit bileşen) ile giderek artan frekanslı sinüzoidallerin toplamına eşit olduğunu çizdi (ekrandan, 00:50:00). Toplamın aralarına noktalar konmasının nedeni frekansın sürekli bir kavram olmasıdır; aradaki bütün frekanslar da toplamda yer alabilir. Fourier serilerinin ayrıntısı bir sonraki derse bırakıldı.

## 7. Sinüzoidal İşaret: Genlik, Frekans, Faz

Fourier analizine geçmeden önce sinüzoidal işaret açıklandı. Sinüzoidal işaret sinüs ya da kosinüs ile ifade edilir (ekrandan, 00:50:00). Sinüs ve kosinüs aslında aynı fonksiyondur; biri diğerinin 90° kaydırılmış halidir.

### 7.1 Genlik

Saf bir $\sin$ fonksiyonu $-1$ ile $+1$ arasında salınır. Başına bir çarpan konursa, örneğin $3\sin$, işaret $-3$ ile $+3$ arasında salınır. Genel olarak $A\sin$ işareti $-A$ ile $+A$ arasında gider. Bu özellik **genliktir**.

**Soru:** Tahtada çizilen, sıfırdan geçerek yükselen işaret sinüs müdür, kosinüs müdür?
**Cevap:** Sinüstür. Kosinüs sıfır anında tepe değerinden başlar.

### 7.2 Periyot ve frekans

Dalganın başlayıp kendini tamamladığı ve tekrar etmeye başladığı süreye **periyot** denir ve $T$ ile gösterilir. Periyot ile frekans ters orantılıdır:

$$T = \frac{1}{f}$$

$T$ büyüdükçe frekans düşer; dalga daralıp daha sık tekrar ettikçe, yani $T$ küçüldükçe frekans artar. Sinüsün içi $2\pi f t$ biçiminde yazılır; $2\pi f$ yerine açısal frekans $\omega$ da kullanılır, böylece ifade $\omega t$ olur (ekrandan, 00:55:00).

### 7.3 Faz

İşaret sağa ya da sola da kayabilir. Bu kayma parametresi $\varphi$ ile gösterilir ve bir açıdır. Kaymanın büyüklüğü periyodun kaçta kaçı kadar gidildiğine göre ölçülür: tam periyot $2\pi$ ya da 360°'dir, çeyrek periyot $\pi/2$ ya da 90°'dir.

Böylece genel sinüzoidal işaret şöyle yazılır (ekrandan, 00:55:00):

$$x(t) = A\sin(2\pi f t + \varphi), \qquad \omega = 2\pi f$$

Tahtada $\varphi = \pi/2$ için bu ifadenin kosinüse dönüştüğü yazıldı:

$$A\sin\left(2\pi f t + \frac{\pi}{2}\right) = A\cos(2\pi f t)$$

> **Ders sonrası not:** Hoca 00:53:45 civarında 90° ileri kaymanın sinüsü "eksi kosinüse" dönüştürdüğünü söyledi, hemen ardından tahtaya $A\cos(2\pi f t)$ yazdı. Doğrusu $\sin(\theta + \pi/2) = \cos\theta$'dır; $-\cos\theta$ ise $\sin(\theta - \pi/2)$'ye, yani 90° geri kaymaya karşılık gelir. Bu eşitlikler python ile kontrol edildi.

Sonuç olarak her sinüzoidal fonksiyon üç temel özellikle tanımlanır (ekrandan, 00:55:00):

- **Genlik** $A$
- **Frekans** $f$ (ya da periyot $T = 1/f$)
- **Faz** $\varphi$

## 8. DC Bileşen ve İşaretlerin Frekans Bandı

### 8.1 AC ve DC

**Soru:** Şehir şebekesinden aldığımız işaret sürekli midir, süreksiz midir? DC midir, AC midir?
**Cevap (bir öğrenci):** Sürekli ve AC.

DC denince sinüzoidal olmayan, frekansı sıfır olan işaret anlaşılmalıdır. Frekans, işaretin salınım yapması demektir. $f = 1$ Hz olsa işaret bir saniyede bir salınım yapar; yani $T = 1/f$'den $T = 1$ s olur ve işaret başlangıcını ve bitişini bir saniyede tamamlar.

**Soru:** $T = 0{,}5$ s olsaydı frekans ne olurdu?
**Cevap:** $f = 1/T = 1/0{,}5 = 2$ Hz. İşaret aynı bir saniyede iki kez salınır; frekans iki katına çıkar.

Hiç salınımın olmadığı, frekansın sıfır olduğu bileşene **DC bileşen** denir. Fourier'e göre bir işaretin bileşenleri frekans sıfırdan (DC) başlar ve sonsuza kadar gider.

### 8.2 Bant sınırı

Gerçekte her işarette bütün frekanslar bulunmaz ve frekanslar sonsuza kadar gitmez. Her işaretin bir üst frekans sınırı vardır; sıfırdan bu sınıra kadar olan aralık işaretin bandı olarak kabul edilir. Örneğin insan konuşması temel kabulle 0-4 kHz arasındadır; daha tiz sesler 5 kHz'e çıkabilir. Bu bantta bütün frekanslar eşit miktarda bulunmaz: düşük frekanslar daha baskın, yüksek frekanslar daha zayıftır. Sesin karakterini belirleyen, ses telinin özelliğinden gelen bu bileşenlerdir.

> **Ek bilgi (derste anlatılmadı):** Klasik telefon hatlarında konuşma yaklaşık 300-3400 Hz aralığına sınırlanır ve 8 kHz ile örneklenir; bu, 4 kHz'lik bant sınırının iki katıdır.

## Örnek Sorular

**Soru 1** (derste sözlü, 00:28:43): 1950'li yıllarda neyin bulunuşu bilgisayar mühendisliğinin doğuşuna ya da hızlanmasına neden oldu?

> **Cevap (derste verildi):** Transistörün. Transistör hem gerilim yükseltici hem de ucuz ve kararlı ikili (binary) devrelerin yapı taşı olarak kullanılır.

**Soru 2** (derste sözlü, 00:31:04): 1939-1944 tarihleri neyi hatırlatır ve elektronik açısından önemi nedir?

> **Cevap (derste verildi):** İkinci Dünya Savaşı'nı. Taşınabilir, farklı iklim şartlarında çalışan haberleşme, istihbarat ve kriptografi cihazlarına duyulan ihtiyaç elektronik, işaret işleme ve uydu teknolojilerinin hızla gelişmesine yol açtı. (Savaşın bitişi 1945'tir.)

**Soru 3** (derste sözlü, 00:44:58): Örnekleme periyodu $T_s$'nin çok geniş ve çok dar seçilmesinin, RAM'de saklama açısından avantaj ve dezavantajları nelerdir?

> **Cevap (derste verildi):** Geniş $T_s$ az örnek ve az hafıza demektir ama aradaki değişimler kaybolur. Dar $T_s$ orijinale yakın bir sonuç verir ama çok hafıza kaplar. $T_s$, değişimleri kaçırmayacak en geniş değer olarak seçilmelidir; ölçüsünü Fourier analizi verir.

**Soru 4** (derste sözlü, 00:50:28): Sıfırdan geçerek yükselen sinüzoidal işaret sinüs müdür, kosinüs müdür?

> **Cevap (derste verildi):** Sinüs.

**Soru 5** (derste sözlü, 00:51:30): Periyot ile frekans arasında nasıl bir ilişki vardır?

> **Cevap (derste verildi):** Ters orantı: $T = 1/f$.

**Soru 6** (derste sözlü, 00:54:38): Şehir şebekesinden elde edilen işaret sürekli midir, süreksiz midir; AC midir, DC midir?

> **Cevap (derste verildi):** Süreklidir ve AC'dir, yani sinüzoidal bir işarettir.

**Soru 7** (derste sözlü, 00:55:43): Periyot $T = 0{,}5$ s olsaydı frekans ne olurdu?

> **Cevap (derste verildi):** $f = 1/0{,}5 = 2$ Hz. $T = 1$ s için $f = 1$ Hz olduğuna göre frekans iki katına çıkmıştır.

## Dersin Toparlaması

Bu ilk derste Elektronik Devreler'in kapsamı, kaynağı ve donanım dersleri arasındaki yeri tanıtıldı. Transistörün, tüplü yapıların sakıncalarını gidererek ucuz ve kararlı ikili devreleri mümkün kıldığı ve böylece bilgisayar mühendisliğinin doğuşunu hızlandırdığı anlatıldı. Ardından analog (sürekli) dış dünya ile sayısal (ayrık) bilgisayar arasındaki fark ve bu farkı kapatan ilk adım olan örnekleme ele alındı: örnekleme periyodu $T_s$ küçüldükçe sadakat artar ama hafıza maliyeti de artar.

$T_s$'nin doğru seçimi için işaretin frekans içeriğini bilmek gerekir. Bu yüzden Fourier analizine giriş yapıldı ve sinüzoidal işaretin üç parametresi (genlik, frekans, faz), $T = 1/f$ ilişkisi, DC bileşen ve işaretlerin bant sınırı açıklandı. Bir sonraki derste Fourier serileriyle devam edilecektir.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
