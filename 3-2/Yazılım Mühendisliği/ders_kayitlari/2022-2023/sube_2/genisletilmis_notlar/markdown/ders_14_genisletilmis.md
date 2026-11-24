# Ders 14 Genişletilmiş Notu: Yazılım Kalitesi ve Yazılım Ölçütleri

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Ölçme, Ölçüt ve Ölçüm
- 2. Yorumlama Engeli ve Yazılımı Neden Ölçeriz
- 3. Doğrudan ve Dolaylı Ölçüm, LOC Tabanlı Ölçütler
- 4. Fonksiyon Noktası Yöntemi
- 5. LOC ve FP Ölçeklerinin Kıyaslanması
- 6. Kalite Ölçütü Sınıflandırmaları
- 7. Dış Kalite Ölçütleri
- 8. İç Kalite Ölçütleri
- 9. Ölçme İlkeleri
- 10. Nesneye Yönelik Ölçütler ve CK Ölçütleri
- 11. Diğer Ölçütler ve Ölçütlerin Sınırları
- 12. Kitaptan Eşik Değerleri ve Görselleştirme
- Örnek Sorular
- Dersin Toparlaması

## 1. Ölçme, Ölçüt ve Ölçüm

Ders, yazılım kalitesi ve yazılım ölçütleri bölümüyle başladı. Hoca, daha önce proje yönetimi konusunda ölçmenin gerekli olduğunu söylediklerini hatırlattı ve bu bölümde konuyu ölçme odaklı ele alacaklarını belirtti. Önce üç temel kavram oturtuldu (ekrandan, 00:10:00).

### 1.1 Ölçme (measuring)

Ölçme, somut veya soyut bir varlığın sahip olduğu bir özelliğini sayısal veya derecelendirilmiş bir veri olarak ifade etmektir. Slayttaki örnekler şunlardır:

- Bir kişinin boyunu santimetre cinsinden söylemek: somut bir varlığın uzunluk özelliği sayısal bir veri olarak ifade edilir.
- "Hava bugün 22 santigrat derecedir": ortamın sıcaklık özelliği sayısal olarak ifade edilir.
- "İlk ara sınav çok zordu": belli bir sınavın zorluk derecesi, çok kolay - kolay - orta - zor - çok zor biçiminde beş kademeli bir ölçekle (Likert ölçeği) derecelendirilir.

### 1.2 Ölçüt (metric)

İlk iki örnekte değerin sonunda bir birim (cm, santigrat derece) vardı. İşte burada ölçüt devreye girer: ölçüt, varlığın ölçülecek özelliğini ölçme biçimidir. Hoca, daha önce bağlaşım ve uyumu anlatırken de aynı kavramın (ör. doğrudan ilişki alınıp alınmaması gibi farklı kriterlerle) farklı biçimlerde ölçülebildiğini hatırlattı.

- Mesafe ölçütleri: A noktasından B noktasına gidilecek mesafe, araya bir dağ girdiğinde dağın etrafından dolanarak, bir tünelden geçerek ya da kuş uçuşu ölçülebilir. Hepsi mesafedir ama ölçüm biçimi farklıdır. Slaytta bu, "bir labirentteki Öklid ölçütü (Pisagor teoreminden) ve kuş uçuşu ölçütü" diye geçer.
- Sıcaklık ölçütleri: santigrat ve Fahrenhayt. Santigratta deniz seviyesinde suyun donma noktası ile kaynama noktası arası 0 ve 100 alınıp yüze bölünmüştür.

### 1.3 Ölçüm (measurement)

Ölçüm, belli bir ölçüte göre yapılan ölçme eyleminin sonucudur. Hoca, üç kavramın karıştırılmaması gerektiğini, kitaplarda bile zaman zaman karıştırıldığını söyledi. İngilizcede (measuring, metric, measurement) ayırt etmek daha zordur; slaytta "-ment" ve "-ing" eklerinin bilinçli olarak konduğu yazıyor. Türkçede ise ölçme (eylem), ölçüt (biçim), ölçüm (sonuç) diye isim-sıfat-eylem ayrımıyla düşünülürse daha kolaydır.

Neden ölçeriz sorusunun yanıtı slaytta şöyledir: gerçek dünya ile ilgili, işimize yarayacak, anlamlı sonuçlar elde etmek için.

## 2. Yorumlama Engeli ve Yazılımı Neden Ölçeriz

### 2.1 Yorumlama engeli (intelligence barrier)

Hoca, İngilizce "intelligence barrier" teriminin "zeka engeli" diye çevrilirse insanlara hakaret gibi duracağını, bu yüzden "yorumlama engeli" demeyi tercih ettiğini söyledi. Yorumlama engeli şudur (ekrandan, 00:15:00):

- Ölçmenin sonucu, aradığımız sonuçları elde etmek için doğrudan bir yol sunmayabilir,
- ya da yapacağımız yorumlama zor olabilir.

Slayttaki şema şu akışı gösterir:

```text
Soyut veya somut varlıklar --(ölçme)--> Veriler (sayısal veya derecelendirilmiş)
        |                                        |
 [Yorumlama engeli]                     (matematik, istatistik)
        |                                        |
        v                                        v
 Anlamlı sonuçlar  <------(yorumlama)------  Sayısal sonuçlar
```

Varlıklardan anlamlı sonuçlara doğrudan geçmek çoğu zaman mümkün değildir. Ölçme ile elde edilen veriler matematiksel ve istatistiksel yöntemlerle sayısal sonuçlara çevrilir, bu sonuçlar da yöntemlerin verdiği ipuçları doğrultusunda yorumlanarak anlamlı sonuçlara varılır.

Hoca basit bir örnekle yorumlamanın kolay olduğu durumu anlattı. Elinde bir kurşun kalem ve bir tahta kalemi var; tahta kalemi daha uzun ve daha kalın. Odayı havalandırmak için açtığı pencere sürekli kapanıyorsa destek olarak daha kalın kalemi kullanmak mantıklıdır. Tavandaki bir projeksiyon düğmesine boyu yetişmiyorsa daha uzun kalemi kullanır. Bu durumlarda ölçümden karara geçiş kolaydır. Yazılım gibi karmaşık işlerde ise yorumlama bu kadar kolay olmaz.

Yorumlama engelinin yüksekliğine örnek olarak Otostopçunun Galaksi Rehberi verildi: evrendeki en karmaşık süper bilgisayar uzun yıllarda yapılır, ona ilk soru olarak "Hayatın anlamı nedir?" diye sorulur, bilgisayar kısa bir süre düşünüp "42" yanıtını verir. "Peki 42 ne demek?" sorusunun yanıtı için ise yüzyıllar geçer.

### 2.2 Yazılım ölçümü neden zordur?

Yazılım ölçümünde yorumlama engeli yüksektir. Bunun bir nedeni yazılımın zihinsel yoğunluk gerektiren, zor problemleri çözmeye çalışan bir iş olmasıdır. İkinci bir zorluk da önerilen ölçütlerin nitel ya da öznel (sübjektif) kalmasıdır; bu durumda yorumlama daha da zorlaşır.

### 2.3 Yazılımı neden ölçeriz?

- Ne kadar iyi bir ürün ortaya çıkardığımızı anlamak için.
- Ne kadar iş yapacağımızı kestirmek, buradan da ne kadar zaman ve para harcayacağımızı tahmin etmek için.
- Proje yönetimi için: ölçülemeyen ilerleme yönetilemez.

## 3. Doğrudan ve Dolaylı Ölçüm, LOC Tabanlı Ölçütler

### 3.1 İki temel ölçüm biçimi

Slayta göre iki temel ölçüm biçimi vardır (ekrandan, 00:20:00):

- Doğrudan: gider, süre, komut satırı, hız, bellek genişliği, hata miktarı.
- Dolaylı: işlev, nitelik, karmaşıklık, etkinlik, güvenilirlik, dayanıklılık.

Süre, projenin süresi ya da belli bir işlemin yürütülmesi için gereken süre olabilir; hız uygulamanın çalışma hızıdır; hata miktarı ortaya çıkan hata sayısıdır. Dolaylı ölçümlerde, ör. karmaşıklık doğrudan ölçülemeyebilir, çünkü birine az karmaşık gelen şey başkasına çok karmaşık gelebilir. Bu yüzden dolaylı ölçümler doğrudan ölçümlere çevrilmeye ya da onlar cinsinden ifade edilmeye çalışılır. Hepsindeki ortak amaç verimlilik, kalite, gider ve belgelemenin hesaplanmasıdır.

### 3.2 Doğrudan ölçülen niceliklerden tanımlanan ölçütler

Slayttaki tanımlar şunlardır (ekrandan, 00:20:00):

- LOC = Line of Code (kod satırı sayısı)
- KLOC = 1000 * LOC (K: Kilo)
- Verimlilik = KLOC / (kişi * ay)
- Kalite = Hata / KLOC
- Gider = Toplam gider / KLOC
- Belgeleme = Belge sayfası / KLOC

> **Ders sonrası not:** Slaytta "KLOC = 1000 * LOC" yazıyor ve hoca da "bin çarpı" diye okudu. Kastedilen, KLOC'un bin satırlık bir birim olmasıdır: 1 KLOC = 1000 LOC, yani satır sayısı KLOC'a çevrilirken bine bölünür (KLOC = LOC / 1000).

Programların hacmi çok büyüdüğü için satır sayısı artık KLOC cinsinden söylenir. Verimlilik, bir kişinin bir ayda ürettiği bin satır sayısıdır. Kalite ölçütü bin satırda yapılan hata sayısıdır. Gider, bin satır kod başına yapılan masraftır; en büyük gider kalemi genellikle çalışan masraflarıdır, ama lisans bedelleri, yazılımın çalıştığı sunuculardaki süre, bakım/sahiplik masrafı için amortisman ya da Amazon Web Services gibi bir bulut üzerinde çalışıyorsa bulut masrafları gibi bütün gider kalemleri eklenir. Belgeleme ölçütü bir masraf değil, belgeleme hacmidir ve belgelemeye ne kadar ağırlık verildiğinin göstergesidir.

## 4. Fonksiyon Noktası Yöntemi

Fonksiyon noktası (FP, Function Point) ölçümü bir dolaylı ölçüm örneğidir. Literatürde KLOC ölçümünün dezavantajlarına bir alternatif olarak önerilmiştir; kendi dezavantajları da vardır. Hesaplama için iki tablo ve ardındaki eşitlik kullanılır (ekrandan, 00:25:00).

### 4.1 Tablo 1: Fonksiyon noktası bileşenleri

| i | Nicelik | Basit | Orta | Karmaşık |
|---|---|---|---|---|
| 1 | Kullanıcının yazılıma giriş sayısı (user input) | 3 | 4 | 6 |
| 2 | Kullanıcının aldığı çıktı sayısı (output) | 4 | 5 | 7 |
| 3 | Kullanıcının sorgulama sayısı (query) | 3 | 4 | 6 |
| 4 | Kütük sayısı (record) | 7 | 10 | 15 |
| 5 | Dış arabirim sayısı | 5 | 7 | 10 |

Tablonun ayrıca "Sayısı (S)" ve "$FP_i$" sütunları vardır; $FP_i = S \times AF$ (AF: ağırlık faktörü) ve en altta $\sum FP_i$ hesaplanır.

Hoca bileşenleri şöyle açıkladı:

- Sorgulama (query) ile çıktı farklıdır; çıktı bir hesaplamanın sonucudur.
- Kütük sayısı, ör. bir veritabanı kullanılıyorsa tablo sayısı gibi düşünülebilir.
- Dış arabirimler, yazılımın birlikte çalışacağı, çıktı vereceği ya da girdi alacağı dış sistemlerdir.

Her niceliğin hepsinin basit, hepsinin orta ya da hepsinin karmaşık olması beklenmez. Bu yüzden sayı sütunu üçe bölünebilir: basit olanlar, orta olanlar ve karmaşık olanlar ayrı sayılır, her biri kendi ağırlık faktörüyle çarpılır ve satır içinde toplanır. Sonra bütün satırların değerleri toplanarak fonksiyon noktası bileşenlerinden gelen kısım ($\sum FP_i$) bulunur.

### 4.2 Tablo 2: Yazılım parametreleri

İkinci tabloda 14 yazılım parametresi vardır. Hoca bunlardan ilk üçünü saydı:

- Güvenli yedekleme ve geri yükleme gerekli mi?
- İletişim altyapısı gerekli mi?
- Dağıtılmış işleme fonksiyonları var mı? (dağıtılmış sistemler, eşler arası ağlar ya da günümüzde popüler mikroservis tabanlı uygulamalar gibi)

Her parametreye 0 (yok), 1 (kolay) ile 5 (en zor ya da en karmaşık) arasında bir değer verilir ve bunlar toplanarak ikinci bileşen ($\sum F_i$) elde edilir.

<!-- BELİRSİZ: Tablo 2 ve formül slaytlarının karesi yok; 14 parametrenin tamamı ekranda okunamadı. -->

### 4.3 FP formülü

İki toplam bulunduktan sonra formülde yerine konur. Altyazıda formül "FP eşittir toplam FP çarpı 0,65 ... sigma Fi" diye geçiyor; standart biçimi büyük olasılıkla şudur:

$$FP = \sum FP_i \times \left(0{,}65 + 0{,}01 \times \sum F_i\right)$$

<!-- BELİRSİZ: slayttaki formülün tam biçimi karede yok; 0,01 katsayısı altyazıda duyulmuyor. -->

Hoca, formüldeki sigma işaretlerinin yanıltmaması gerektiğini vurguladı: formülde yeniden bir toplama işlemi yapılmaz; $\sum FP_i$ Tablo 1'den, $\sum F_i$ Tablo 2'den hesaplanmış tek birer sayıdır. Aradaki boşluk da çarpma anlamındadır.

FP hesaplandıktan sonra verimlilik, kalite, gider ve belgeleme ölçütleri aynı biçimde tanımlanır; tek fark KLOC yerine FP kullanılmasıdır.

> **Ek bilgi (derste anlatılmadı):** Parantez içindeki çarpan, 14 parametrenin hepsi 0 olduğunda 0,65, hepsi 5 olduğunda $0{,}65 + 0{,}01 \times 70 = 1{,}35$ olur. Yani Tablo 2, Tablo 1'den gelen ham değeri büyük olasılıkla yaklaşık %35 aşağı ya da yukarı ayarlar.

## 5. LOC ve FP Ölçeklerinin Kıyaslanması

Slayttaki kıyaslama tablosu şöyledir (ekrandan, 00:30:00):

| LOC ölçeği | FP ölçeği |
|---|---|
| − Programlama diline bağımlı (kısmen) | + Programlama dilinden bağımsız |
| − İyi tasarlanmış ama kısa yazılımları yeterince değerlendirememekte | − Sübjektiftir |
| − İşlemsel olmayan dillerdeki yazılımlara kolayca uyarlanamaz | − Doğrudan fiziksel bir ölçüt değildir |
| | − Veri toplaması güçtür |

Hoca, iki sütunun birbirinin tam zıttı olmadığını, yalnız dil bağımlılığı satırının karşılıklı olduğunu söyledi.

### 5.1 LOC'un eleştirileri

LOC'un en önemli eleştirisi, aynı zamanda FP'nin ortaya çıkış nedeni, programlama diline bağımlı olmasıdır. Aynı işi bir dilde bir komutla, başka bir dilde sekiz komutla yapıyor olabilirsiniz. Farklı dillerde yazılmış projeleri karşılaştırmak "elmalarla armutları karşılaştırmak" olur. Projeler aynı dil ve geliştirme ortamındakilerle kendi aralarında değerlendirilirse bu sakınca en aza indirilebilir; tablodaki "kısmen" sözcüğü bu yüzdendir.

Ancak aynı dilde (ör. Java) bile aynı iş daha az ya da daha çok satırla yazılabilir ve satır saymak belirsizdir:

- Basit bir getter metodunda gövde açılış parantezi metot adıyla aynı satıra mı, alt satıra mı yazılıyor? Tek başına bir parantez bir komut sayılmalı mı?
- Noktalı virgüller mi sayılmalı? O zaman içinde iki noktalı virgül bulunan `for` döngüsü nasıl sayılacak?
- `for` döngüsünün başlangıç, devam ve artım ifadeleri vardır; başlangıç bir kez çalışır. Döngünün içindeki 10 komut 10 mu sayılmalı? Döngünün kaç kez döneceği ancak çalışma anında belli olur.

Farklı araçlar LOC'u farklı biçimde hesaplayabilir; farklı cetvellerle yapılan ölçümlerin sonuçları da farklı olur. Bu yüzden mümkün olduğunca hep aynı ölçek ve aynı cetvelle ölçülmelidir.

Ayrıca nesneye yönelimde böl-parçala-yönet mantığıyla çok iş yapan uzun bir metot alt metotlara bölünür. Bu LOC'u artırır ama ortaya çıkan kod çok daha kolay anlaşılır. Saha çalışmaları, LOC ölçeğinin iyi tasarlanmış ama kısa yazılımları yeterince doğru değerlendiremediğini göstermiştir. İşlemsel olmayan dillere de kolayca uyarlanamaz.

### 5.2 FP'nin eleştirileri

FP programlama dilinden bağımsızlık sağlamıştır, ama öznellik çok önemli bir etkendir. 0-5 arası değerleri kim, neye göre atıyor? Değerleri belirleyen kişi kendi deneyim ve bilgisine göre karar verir. Farklı kişiler farklı "cetveller" kullanırsa tahmin hassasiyeti ve doğruluğu düşer. Bu öznelliği azaltmak için Delphi yöntemi kullanılabilir.

FP doğrudan fiziksel bir ölçüt değildir ve verinin toplanması güçtür. Girdi, çıktı ve kütük sayılarının hassas belirlenebilmesi için yazılım gereksinimleri belgesinin tamamlanmış olması, hatta tasarımın belli bir noktaya gelmiş olması gerekir. Bu yüzden ilk başta yapılan ölçüm ve tahminler proje ilerledikçe tekrarlanmalı ve netleştirilmelidir.

## 6. Kalite Ölçütü Sınıflandırmaları

Nitel kalite ölçütleri de nicel ölçütler cinsinden ifade edilmeye çalışılır. Farklı kişi ve gruplar bu ölçütleri farklı biçimde gruplamış ve farklı adlarla anmıştır.

<!-- BELİRSİZ: bu bölümün slaytı (178) karelerde yok; içerik altyazıdan alındı. -->

### 6.1 ISO 9126

Kalite ölçütleri işlevsellik, güvenilirlik, kullanılabilirlik, verimlilik, bakım kolaylığı ve taşınabilirlik ana bölümlerine ayrılır. Her birinin alt bölümleri vardır; ör. işlevselliğin altında uygunluk, doğruluk, güvenlik; güvenilirliğin altında hata bağışıklığı gibi.

### 6.2 McCall ve ekibi

McCall ve ekibi kalite ölçütlerini üçe ayırmıştır:

- İşlevsel ölçütler: yazılım ürününün yaptığı işlerle ilgilidir; her kullanım senaryosunun gerçeklenmesi bir işlev olarak değerlendirilir. Ölçütler: doğruluk, güvenilirlik, bütünlük, kullanılabilirlik, verimlilik.
- Değiştirme ölçütleri: bakım kolaylığı, esneklik, sınanabilirlik.
- Taşınma ölçütleri: taşınabilirlik, yeniden kullanılabilirlik, birlikte çalışabilirlik.

### 6.3 İç ve dış kalite ölçütleri

Hocanın en sevdiği sınıflandırma, en basit ve akılda kalması en kolay olduğu için, kalite ölçütlerini iki gruba ayıran sınıflandırmadır: iç kalite ölçütleri ve dış kalite ölçütleri. <!-- BELİRSİZ: bu sınıflandırmanın yazarının adı altyazıda "MacDonald" diye geçiyor. -->

- İç kalite ölçütleri yazılımı geliştirenleri ilgilendirir.
- Dış kalite ölçütleri yazılımı kullananları ilgilendirir.

Bu ayrım noktası sayesinde akla gelen herhangi bir kalite niteliğinin iç mi dış mı olduğuna kolayca ve net olarak karar verilebilir; diğer sınıflandırmalardaki alt dallar da bu iki gruba rahatça yerleştirilebilir.

> **Hocanın vurgusu:** Bu ölçütlerin hepsini ezberlemek gerekmez, ama her kategoriden birkaç tanesi akılda olmalıdır.

## 7. Dış Kalite Ölçütleri

Slayttaki dış kalite ölçütleri şunlardır (ekrandan, 00:40:00):

- Doğruluk (Correctness): Yazılımın hatalar içermemesi, gereksinimlerde belirtildiği şekilde çalışması.
- Etkinlik (Efficiency): Bellek ve işlemci gibi sistem kaynaklarının en az oranda kullanımı.
- Güvenilirlik (Reliability): Sistemin her koşulda istenildiği gibi çalışması, hatalar arasındaki ortalama zaman aralığının (MTBF) yüksek olması.
- Güvenlik (Security): İzinsiz ve yetkisiz işlemler mümkün olmamalı.
- Bütünlük (Integrity): Veriler ve işlemler arasındaki tutarlılığın korunması.
- Uyarlanabilirlik (Adaptability): Sistemin değişik uygulamalar veya ortamlarda kullanılabilmesi için mümkün olduğunca az değişiklik gerektirmesi.
- Hassaslık (Accuracy): Sistemin kendisinden beklenen işi mümkün olduğunca iyi yapabilmesi.
- Sağlamlık (Robustness): Aykırı girişlere veya güç çalışma ortamlarına karşılık sistemin çalışmayı sürdürebilmesi.
- Kullanılabilirlik (Usability): Yazılım kolay kullanılabilir olmalıdır.
- Bu ölçütler örtüşebilir; bazı durumlarda birbirinden daha iyi veya daha zor ayrılabilir.

### 7.1 Doğruluk ve etkinlik

Doğruluk elbette en çok yazılımı kullananı ilgilendirir. Etkinlik, kaynakların verimli kullanımıdır. Bu, diğer iç ve dış kalite ölçütlerine de avantaj sağlar: yazılım ürününün toplam sahiplik ve idame bedelinin (total cost of ownership) düşük olmasını sağlar, kaynak israfını ve dolayısıyla enerji israfını önler.

### 7.2 Güvenilirlik ve MTBF

> **Hocanın vurgusu:** Güvenilirlik (reliability) ile güvenlik (security) Türkçe adlarının yakınlığı nedeniyle karıştırılmamalıdır. İngilizce adları karışmaz ama Türkçe adları karışır.

Güvenilirlik, sistemin her koşulda istenildiği gibi çalışması, hataların mümkün olduğunca seyrek gerçekleşmesidir. Bunun için tanımlanmış bir ölçüt, hatalar arasındaki ortalama zaman aralığıdır: MTBF (Mean Time Between Failures).

Hesaplama mantığı şöyledir: belli bir zaman diliminde (ör. sistemin müşteri tarafından kullanılmaya başlandığı andan bu yana ya da son 3-6 ay) kaç arıza olduğu ve arızalar arasındaki doğru çalışma süreleri (gün ya da saat olarak) bilinir. Bu sürelerin toplamı arıza aralığı sayısına bölünerek ortalama bulunur. MTBF ne kadar yüksekse sistem o kadar güvenilirdir.

### 7.3 Güvenlik

Hoca "hırsıza kilit dayanmaz" atasözünü hatırlattı: kırılamayacak güvenlik önlemi aslında yoktur. Önemli olan kırılmanın ne kadar zor olduğudur; kırma işlemi sınırlı kaynaklarla yapılamamalı ya da yapılsa bile iş işten geçmiş olmalıdır.

Örnek: Bir hesaptan başka bir hesaba para aktarılıyor (aynı banka içinde ya da bankalar arasında, fark etmez). Bu işlem birçok sistemin birlikte çalışmasını ve alt işlem adımlarından geçmeyi gerektirir; bu mantıkla yapılan işlemlere hareket (transaction) denir. İşlemin güvenliği tek kullanımlık parolalarla (one time password) sağlanıyor olsun. Bir saldırgan haberleşme paketlerinden yola çıkıp tek kullanımlık parolayı kırmaya çalışabilir. Ama bu işlem çok güçlü bir bilgisayar sisteminde bile 1-3 saat sürüyorsa, para transferi ise birkaç dakikada bitiyorsa, parolayı kırsa bile elde ettiği bilgi artık işine yaramaz.

### 7.4 Bütünlük

Bütünlük, veriler ve işlemler arasındaki tutarlılığın korunmasıdır. Aynı örnekte A hesabından B hesabına 1000 lira gidiyorsa, işlemin sonunda A hesabından 1000 lira eksilmiş, B hesabına 1000 lira yatmış olmalıdır:

- A'dan para düşmemiş ama B'ye yatmışsa banka zarardadır.
- A'dan para düşmüş ama B'ye yatmamışsa müşteri zarardadır.

Hareket mantığında alt adımlardan biri gerçekleşirken bir sorun olursa, sistem önceki alt adımlar hiç gerçekleşmemiş gibi en son sağlam ve doğru duruma geri döndürülebilmelidir. Döndürülemezse tutarsızlık oluşur.

### 7.5 Uyarlanabilirlik

Uyarlanabilirlik (adaptability), sistemin değişik uygulama veya ortamlarda kullanılabilmesi için mümkün olduğunca az değişiklik gerektirmesidir. Hoca burada taşınabilirlikten söz edilmediğini, taşınabilirliğin bir iç kalite ölçütü olduğunu, burada yapılabilecek uyarlama eylemlerinin kastedildiğini vurguladı.

### 7.6 Hassaslık

Slayttaki Türkçe tanım (sistemin beklenen işi mümkün olduğunca iyi yapabilmesi) belirsiz kalır. Hocaya göre hassaslığın asıl anlamı, yapılan hesaplamanın ve ortaya çıkan sonucun yeterli anlamlılık düzeyinde olmasıdır. Örnekler:

- Para birimlerinde bir lira yüz kuruş, bir dolar yüz senttir; insanlar için virgülden sonra iki basamak anlamlıdır. 35,99 gibi bir fiyat olur, 35,899 gibi bir fiyat olmaz. Ama döviz kuru hesaplamalarında (ör. 1 dolar = 20,98765 gibi) ve bankalar arası finansal işlemlerde virgülden sonra 8-10 basamağa kadar hassasiyetle işlem yapılır. Hacimli işlemlerde kaç basamağa kadar gidildiği, ortaya çıkan değerleri farklılaştırır.
- Bir çemberin çevresi ya da bir dairenin alanı hesaplanırken pi sayısının virgülden sonra kaç basamağı alınırsa sonuç o kadar hassas, yani gerçeğe o kadar yakın olur.

### 7.7 Sağlamlık

Sağlamlık, sistemin aykırı girişlere veya güç çalışma ortamlarına karşı çalışmayı sürdürebilmesidir. Bir noktada çalışma kesilebilir, ama sistemin hangi noktada çalışmayı bıraktığını bilmek önemlidir: aynı anda kaç kullanıcıyı ya da saniyede kaç işlemi destekleyebildiği gibi. Bu limitlerin üstüne çıkılıyorsa sistemin yeni donanım kaynaklarına genişletilmesi gerekebilir; bunun ne zaman gerekeceğini söyleyebilmek için sağlamlık ölçümleri yapılmalıdır.

### 7.8 Kullanılabilirlik

Kullanım kolaylığı, yazılımın hayatta tutulmasındaki en önemli etkenlerden biridir. Kullanılamayan yazılım önünde sonunda, çoğu zaman da erken terk edilmeye mahkumdur. İnsanların çoğu değişimden korkar ve değişmemeyi tercih eder; bu değişime karşı direnç psikolojik bir etkendir. Mevcut bir bilgi sisteminin yerine yenisi geliyorsa, yeni sistem daha yetenekli ve iç/dış nitelikleri daha iyi olsa bile kullanılabilir değilse kullanıcılar yeni sisteme geçişte ayak direyecek, bu da birçok soruna yol açacaktır.

Hoca son olarak, herhangi bir örneğin hangi kalite ölçütüne girdiği sorulduğunda birden fazla aday söylenebileceğini, çünkü bu ölçütlerin kimi durumlarda örtüştüğünü ve birbirinden ayrılmasının zor olabildiğini belirtti.

## 8. İç Kalite Ölçütleri

Slayttaki iç kalite ölçütleri şunlardır (ekrandan, 00:55:00):

- Yeniden kullanılabilirlik (Reusability): Sistemin parçalarının başka sistemlerde kullanılabilmesinin kolaylığı.
- Bakım kolaylığı (Maintainability): Yazılıma yeni yetenekler eklemenin, yazılımdaki hataları gidermenin veya yazılımın başarımını artırmanın mümkün olduğunca kolay olması.
- Esneklik (Flexibility): Yazılımın orijinal olarak tasarlandığı uygulama alanının dışında çalışabilmesi için gerekli olan değişikliklerin olduğunca az olması.
- Taşınabilirlik (Portability): Yazılımın farklı donanım ve işletim sistemleri gibi değişik çalışma ortamlarına kolaylıkla aktarılabilmesi.
- Okunabilirlik (Readability): Kodun kaynak kodunun incelenmesinin kolay olması.
- Anlaşılabilirlik (Understandability): Yazılımın sistem, bileşen ve kod düzeylerinde anlaşılabilirliğinin mümkün olduğunca kolay olması. Okunabilirlik sadece kod düzeyinde anlaşılabilirliği sağlar.
- Sınanabilirlik (Testability): Sistemin istenen gereksinimleri karşılayıp karşılamadığının sınanabilmesinin bileşen ve tüm sistem çapında mümkün olduğunca kolay olması.

### 8.1 Yeniden kullanılabilirlik, bakım kolaylığı ve esneklik

Yeniden kullanılabilirlik dönem boyunca çok konuşulduğu için kısa geçildi. Bakım kolaylığının önemi yazılım yaşam döngüsünden gelir: yazılım yaşam döngüsünde ilerledikçe değişiklik yapma maliyeti üstel olarak artar ve yazılım için harcanan toplam çabanın büyük kısmı bakım aşamasında gerçekleşir. Bu yüzden bakım kolaylığını iyileştiren her etkenin "başımızın üstünde yeri vardır".

> **Hocanın vurgusu:** Yeniden kullanılabilirlik ile esneklik karıştırılmamalıdır. Yeniden kullanılabilirlikte anahtar kelime "sistemin parçaları"dır. Esneklikte ise yazılımın tamamı başka bir uygulama alanına taşınır.

### 8.2 Taşınabilirlik

Günümüzde taşınabilirliğin, özellikle şirket düzeyinde, çok yararı vardır. Güncel programlama dilleri ve ortamları sanal makineler üzerine kurulmuştur: Java, .NET platformu, Python ve birçok dil böyledir; "bir yerde yaz, birçok sistemde çalıştır" yaklaşımı vardır. Bir yazılım ürününün mümkün olduğunca geniş bir kitleye hitap etmesi istenir; bunun için farklı donanım ve işletim sistemlerinde çalışabilmesi gerekir. Bu uyarlama ne kadar kolaysa ürün o kadar hızlı ve geniş bir kitleye ulaşır, kâr da o kadar artar.

Hoca taşınabilirlik sorunlarına bir deneyimini örnek verdi: aynı IDE'yi, aynı derleyiciyi ve aynı işletim sistemini kullanan iki bilgisayarda aynı program birinde düzgün çalışırken diğerinde çöküyordu; uzun uğraşa rağmen ne kök neden ne de geçici bir çözüm (workaround) bulunabildi. Sorun belki işletim sistemine yüklenen servis ve yamaların farkına kadar inen bir kökene sahipti. Bu, piyasaya sürülecek bir yazılım olsaydı ciddi bir sorun olurdu.

### 8.3 Okunabilirlik ve anlaşılabilirlik

Okunabilirlik kaynak kodun incelenmesinin kolay olmasıdır. Anlaşılabilirlik ise yazılımın sistem, bileşen ve kod düzeylerinde ne yaptığının farkına varılabilmesinin mümkün olduğunca kolay olmasıdır. Hoca, bir şeyi tanımlarken tanımlanan sözcüğün kendisini kullanmanın ("anlaşılabilirlik, ... anlaşılabilirliğidir") bir tavuk-yumurta sorunu yarattığını, bu yüzden yakın kavramlarla açıklamanın daha iyi olduğunu söyledi.

Aradaki fark şudur: bir şeyi okuyabilirsiniz ama okuduğunuzu anlayamayabilirsiniz. Bu, bakmak ile görmek arasındaki fark gibidir: etrafa bakarsınız ama oradaki önemli bir ayrıntıyı göremeyebilirsiniz. Okunabilirlik kaynak kod düzeyinde tanımlanır; anlaşılabilirlik kaynak kod düzeyinde de geçerlidir ama bileşen ve sistem düzeyinde de ortaya çıkar ve yalnız kaynak koddan ibaret değildir.

Bu iki ölçüt bakım kolaylığına götürür, ama yalnız bakımı değil yazılımın bütün geliştirme sürecini de kolaylaştırır. Böl-parçala-yönet yaklaşımının burada da katkısı vardır: büyük bir şeyi anlamak yerine alt işlemlere ayrılmış parçaları anlamak daha kolaydır. Hoca bunu büyük bir lokmayı yemek yerine onu küçük lokmalara bölmenin daha hızlı olmasına benzetti.

### 8.4 Sınanabilirlik

Sınama zaten sistemin istenen gereksinimleri karşılayıp karşılamadığını denetlemektir; sınanabilirlik bunun bileşen ve tüm sistem çapında mümkün olduğunca kolay olmasıdır. Sınama zor bir iş olduğu için onu kolaylaştıran her şey değerlidir. Test güdümlü tasarımın temel savı da budur: rahatça sınanamayan bir şey büyük ihtimalle doğru tasarlanmamıştır.

## 9. Ölçme İlkeleri

### 9.1 Ölçme sürecinin adımları

Ölçme işinin düzgün yapılabilmesi için bir süreç olarak ele alınması gerekir. Süreç beş adımdan oluşur; adımlar sırayla yapılır, ama yazılım yaşam döngüsü boyunca ölçme sürekli tekrarlanır. Slayttaki adımlar şunlardır (ekrandan, 01:25:00):

- Tanımlama (Formulation): Ölçütler ölçülecek yazılıma uygun bir şekilde tanımlanır.
  - Kullanılan yaklaşım: yapısal programlama, NYP vb.
  - Yazılımın türü: gerçek zamanlı, gömülü, uygulama vb.
- Toplama (Collection): Tarif edilen ölçütlerin gerektirdiği verileri elde etme.
- Hesaplama (Analysis): Ölçütlerin hesaplanması = ölçümlerin elde edilmesi.
  - Matematiksel araçlar kullanılabilir.
  - Hesaplama mümkün olduğunca otomatik yapılmalıdır.
- Yorumlama (Interpretation): Elde edilen ölçüm değerlerinden yararlı anlamlar çıkartılması.
- Geri besleme/Kullanma (Feedback): Çıkartılan sonuçların yazılım ekibine bildirilmesi ve ekibin sonuçları kullanarak yazılımı iyileştirmesi.

### 9.2 Tanımlama adımının ayrıntıları

Tanımlamada genellikle kendi ölçütlerimizi önermek yerine literatürdeki hazır ölçütler kullanılır. Yeni bir ölçüt önermek, ancak literatürdeki ölçütler arasında ihtiyaca hitap eden bir ölçüt bulunamadığında anlamlıdır. Yazılım projesi çok çeşitli bakış açılarından ölçülmek istendiği için tek bir ölçüt yetmez; aynı noktaya yönelik ölçümlerde bile birden fazla ölçüt birlikte kullanılarak ihtiyaca ulaşılabilir. Bütün bunlara rağmen önemli bir şeyi yorumlamakta eksik kalınıyorsa yeni bir ölçüt önerilebilir.

Ölçüt, ölçülecek yazılıma uygun olmalıdır:

- Kullanılan yaklaşım: Yapısal programlama ile nesneye yönelik programlamada farklı ölçütler gerekebilir. Örneğin kalıtım ağacının derinliği (Depth of Inheritance Tree) ölçütü nesneye yönelimde anlamlıdır, yapısal programlamada kalıtım olmadığı için uyarlanamaz. Hoca, kalıtımın çok biçimlilik gibi önemli yeteneklere götüren ama diğer ilişkilere göre daha ağır bir ilişki olduğunu, yalnız gerekli yerlerde kullanılması ve kalıtım hiyerarşisinin çok derin olmaması gerektiğini hatırlattı.
- Yazılımın türü: Türe göre daha kritik görülen konular ölçülür. Bu noktada GQM (Goal-Question-Metric) yaklaşımı devreye girer: hedef nedir, bu hedefe ne düzeyde ulaşıldığını anlamak için hangi niteliklere bakmak gerekir (soru) ve bu nitelikleri ölçüp yorumlayan doğru ölçüt hangisidir (metrik). Örneğin gerçek zamanlı uygulamalarda yanıt süresi (response time), gömülü yazılımlarda ise az sistem kaynağı kullanımına yönelik ölçütler daha önemlidir.

### 9.3 Geri beslemenin önemi

Sadece ölçmek bir şey kazandırmaz; yorumlamak da tek başına bir şey kazandırmaz. Asıl kazanç, yorumların karşılığında alınması gereken eylemleri yürütmekten gelir. Örneğin büyüklük ölçütleri olarak LOC ve metot sayısı (number of methods) kullanılıyorsa:

- Uzun metotlardan oluşan sınıfların metotları daha kolay anlaşılan kısa metotlara dönüştürülür.
- Bir sınıfa çok fazla ya da birbiriyle uyumsuz sorumluluklar verilmişse, sorumluluklar kendi arasında uyumlu alt kümelere ayrılır ve çoğu zaman yeni sınıflar oluşturularak dağıtılır.

### 9.4 Bir ölçütün sahip olması arzu edilen özellikler

Slayttaki özellikler şunlardır (ekrandan, 01:20:00):

- Uygun matematiksel özelliklere sahip olmalı:
  - Anlamlı bir ölçekte olmalı. Ör. 0-1 arası sonuçlar üretmeli. Aksi halde bir değerlendirme aralığı verilmeli.
  - Doğru (veya ters) orantıya sahip olmalı. Sonucun yükselmesi, ölçülen özelliğin iyi bir sonuca doğru ilerlemesi (gerilemesi) anlamına gelmeli.
- Deneysel olarak doğrulanabilmeli:
  - Doğrulanmasının ardından kullanılmalı.

Bu matematiksel özellikler aslında yorumlama engelini düşüren özelliklerdir. Normalize bir ölçütte, ör. 0 en kötü, 1 en iyi, 0,5 ortalama olabilir; tersi de olabilir (0 en iyi, 1 en kötü). Normalize değilse anlamlı değerlendirme aralıkları verilmelidir. Hoca örnek olarak LCOM'u gösterdi: sonucu 10, 20, 100, hatta 200 çıkabilir; bunun ne anlama geldiği, yani hangi aralığın iyi, orta ya da kötü olduğu ölçüt önerildiğinde yoktu, çok sonra yapılan saha çalışmalarıyla belirlendi. <!-- BELİRSİZ: hoca burada bir uyum ölçütü için "0-20 iyi, 20-50 ortalama, 50 üstü mutlaka düzeltilmeli" gibi aralıklar söylüyor; bu, slayttaki LCOM aralıklarıyla (0 / 1-20 / >20) uyuşmuyor ve hangi ölçüte ait olduğu altyazıdan net değil. -->

Doğrulanabilirlik şudur: bir ölçüt verilerin nasıl toplanıp nasıl yorumlanacağını söyler, ama bu yorumun gerçekten doğru bilgi verip vermediği ayrıca saha testleriyle doğrulanmalıdır. Doğrulanmamış bir ölçüt kullanılıyorsa onu doğrulayan biz oluruz; bu sonuçların yayınlarda paylaşılması iyi bir katkı olur.

## 10. Nesneye Yönelik Ölçütler ve CK Ölçütleri

### 10.1 Nesneye yönelik ölçütlerin özellikleri

Slayttaki maddeler şunlardır (ekrandan, 01:30:00):

- Kaliteli bir yazılıma götüren tasarım ilkelerine yöneliktirler.
- NYP'de çözümleme ve tasarım arasında kopukluk olmadığı için, aynı ölçütler çözümleme ve kodlama aşamalarında da kullanılabilir.
- Böylece yazılım ekibi, "kaliteli bir ürüne giden yolda" iz üstünde olup olmadıklarını anlayabilir.
- Proje yöneticisi de, başka ölçütlerle birlikte, kestirimlerde bulunabilir.

Bu ölçütlerin bazıları, özellikle bağlaşımla ilgili olanlar, analiz aşamasının sonundan itibaren kullanılabilir: metotlar henüz yokken bile nesneleri ve ilişkilerini gösteren sınıf şeması vardır ve buradan bağlaşım hesaplanabilir. Süreç ilerledikçe analiz tasarıma taşınıp değişiklikler yapıldıkça ölçüm değerleri de değişir. Bu yüzden yazılım projesi, doğru yolda olup olmadığını anlamak için ölçüm sonuçlarıyla sürekli izlenmelidir.

### 10.2 CK ölçütleri (Chidamber ve Kemerer)

En yaygın kullanılan iç kalite ölçütleri CK ölçütleridir; en eski oldukları için üzerlerinde en fazla geçerleme çalışması yapılmıştır. Ad, iki araştırmacının (Chidamber ve Kemerer) soyadlarının baş harflerinden gelir. Slayttaki liste şöyledir (ekrandan, 01:30:00):

- WMC: Sınıftaki ağırlıklı metot sayısı (Weighted Methods per Class).
- DIT: Kalıtım ağacının derinliği (Depth of Inheritance Tree).
- NOC: Alt sınıf sayısı (Number of Children).
- RFC: Sınıfın yanıt kümesinin eleman sayısı (Response For a Class).
  - Good (RFC = [0,50]), regular (RFC = [51,100]), bad (RFC > 100).
- CBO: Sınıflar arası bağlaşım (Coupling Between Objects).
- LCOM: Uyum eksikliği (Lack of COhesion in Methods).
  - Good (LCOM = 0), regular (LCOM = [1-20]), bad (LCOM > 20).

DIT için hoca, kalıtım derinliğinin pek büyümemesi gerektiğini daha önce konuştuklarını hatırlattı. <!-- BELİRSİZ: DIT için söylenen üst sınır altyazıda "beş ... yediyi geçmesin" biçiminde bozuk geçiyor. --> RFC, sınıfın bütün metotlarının çağrılmasıyla oluşabilecek yanıtların kümesindeki eleman sayısıyla ilgilidir; hoca ayrıntısına girmedi, merak edenlerin inceleyebileceğini söyledi.

LCOM uyum eksikliğini ölçer. Uyumun (cohesion) yüksek olması istenir; LCOM ise uyumun eksikliğini gösterdiği için LCOM'un düşük olması tercih edilir. LCOM sonucu ne kadar düşükse o kadar iyidir. Hoca, slayttaki aralığın ölçütün ilk çıktığında verilen aralık olduğunu, isteyenlerin daha ince kategoriler de kullanabileceğini söyledi. <!-- BELİRSİZ: hocanın önerdiği alternatif kategori sınırları altyazıda bozuk. -->

> **Hocanın vurgusu:** Bir ölçümün sıfır çıkması her zaman şüphe uyandırmalıdır. Sıfır, ölçütün hesaplanamadığı anlamına da gelebilir ya da ölçümü yapan araçtaki bir hatadan kaynaklanabilir. Bu durumda başka bir araçla ikinci bir görüş almak yararlıdır. Araçtan şüpheleniliyorsa küçük sınıflar üzerinde elle hesaplama yaparak sağlama yapılabilir; araca güvenilmeye başlandıktan sonra buna gerek kalmaz, çünkü bu işlerin mümkün olduğunca otomatik yapılması gerekir.

LCOM'un çeşitli tanım belirsizlikleri nedeniyle alternatif LCOM ölçütleri de önerilmiştir: bir kısmını Chidamber ve Kemerer kendi eksiklerini fark ederek yeni sürümler olarak, bir kısmını başka araştırmacılar önermiştir. Literatürde farklı uyum ölçütleri de vardır.

### 10.3 WMC ayrıntısı

Slayttaki tanım şöyledir (ekrandan, 01:35:00): C1 sınıfının $M_1 \ldots M_n$ metotlarının karmaşıklıkları $c_1 \ldots c_n$ ise

$$WMC = \sum_{i=1}^{n} c_i$$

Slayttaki eleştiriler:

- Metot karmaşıklığı neye göre belirlenecek?
- Belirlemedeki öznellik güçlü yön mü, zayıf yön mü?

Karmaşıklık katsayıları kişilere belirletilirse, birine az karmaşık gelen başkasına çok karmaşık gelebilir. Maliyet tahmininde konuşulan Delphi yöntemi burada da kullanılabilir, ama kişilerin görüşlerini ayrı ayrı toplamak masraflı bir iştir; oysa bu işin olabildiğince otomatik olması gerekir. Bu öznelliği bazıları güçlü yön, bazıları zayıf yön olarak yorumlar. Hoca, öznelliğin zayıf yön olduğu görüşündedir ve öznelliği mümkün olduğunca nesnelleştirmekten yanadır. Bunun için çevrimsel karmaşıklık (cyclomatic complexity) adlı bir hesaplama yöntemi vardır. Bu, metodun içindeki döngüler, koşullar ve kaç farklı dal olduğu üzerinden kaynak kod üzerinde somut hesaplamalarla yapılan beyaz kutu (white box) bir ölçüttür. Karmaşıklık kişilere belirletilmeyip çevrimsel karmaşıklıkla verilirse öznellik sorunu kalmaz.

> **Ek bilgi (derste anlatılmadı):** Çevrimsel karmaşıklık McCabe tarafından önerilmiştir. Metodun kontrol akış grafında $E$ kenar, $N$ düğüm ve $P$ bağlı bileşen sayısı ise $V(G) = E - N + 2P$ olur; tek bir metot için bu, karar noktası sayısı + 1'e eşittir.

Slayttaki "Ölçütün rehberliği" maddeleri şunlardır:

- Bir sınıfın karmaşıklığını belirler.
- Çok sayıda metodu olan sınıf:
  - Çok fazla sorumluluk yüklenmiştir, dağıtılması uygun olabilir.
  - Yüksek uyumun olup olmadığına tekrar bakılmalıdır.
  - Uygulamaya özeldir, yeniden kullanılabilirliği düşüktür.

Çok sayıda metodu olan sınıfların WMC'sinin yüksek çıkma eğilimi daha fazladır. Karmaşıklığın azaltılmak istenmesinin nedeni bakım aşamasında işi kolaylaştırmaktır. WMC yüksekse LCOM'a ya da başka bir uyum ölçütüne de bakmak gerekir; o sınıfa çok fazla sorumluluk yüklenmiş olabilir. Yüksek WMC'li sınıflar gözden geçirilir; gerekirse refactoring yapılarak metotlar ayrıştırılır (extract method), aynı sınıf içinde kalınır ya da farklı sınıflar oluşturularak fazla sorumluluk dağıtılır.

WMC'ye bir eleştiri de nispeten uygulamaya özel olmasıdır: bir projede WMC ile ilgili çıkarılan sonuçlar başka projelerde aynı anlama gelmeyebilir. Basit bir iş uygulamasında ya da basit bir bilgi sisteminde sınıfların WMC'si yüksek çıkıyorsa bu büyük ihtimalle bir tasarım eksikliğidir. Ama bazı problem alanlarında karmaşık metotlar kodlamak zorunda kalınabilir; orada ne kadar uğraşılırsa uğraşılsın WMC düşürülemez ve yüksek çıkması doğaldır.

Uygun değer aralıkları için kesin bir iyi/kötü sınırı verilemez; aynı proje içinde göreceli karar verilir. Bütün sınıfların WMC'lerine bakılır; çevik bir süreçte bir sonraki koşuda (sprint), şelale sürecinde ise refactoring için ayrılan işlerde WMC'si en yüksek olan sınıflara müdahale edilir. Yani "ne kadar düşükse o kadar iyi" denir ve büyük olanlar küçültülmeye çalışılır.

## 11. Diğer Ölçütler ve Ölçütlerin Sınırları

### 11.1 Diğer kalite özelliklerine yönelik ölçütler

Slayttaki liste şöyledir (ekrandan, 01:40:00):

- Bazı bağlaşım ölçütleri: COMIAS, CBMC.
- Sınanabilirlik ölçütleri: Halstead ölçütleri (tartışmalı), Binder'in seçtiği ölçütler.
- Bakım kolaylığı ölçütleri: IEEE Std. 982.1-1998'de yazılım olgunluk ölçütü.

Hocaya göre sonuçta literatür taranmalıdır: yazılım mühendisliği kitapları, akademik veri tabanları, yazılım ölçütleriyle ilgili kitaplar ve IEEE, ISO gibi kuruluşların standartları incelenip GQM doğrultusunda hangi ölçütlerin kullanılacağına karar verilir.

### 11.2 Ne yapılabilir?

Slayttaki maddeler şunlardır (ekrandan, 01:40:00):

- Ölçütlerin büyük çoğunluğu mükemmel değildir.
- Yine de bu zayıf noktalar genellikle çok özel durumlarda ortaya çıkar.
- Bu nedenle ölçütler kullanılmalı, ancak tabulaştırılmamalı, sadece (çok da hassas olmayan) bir rehber olarak kullanılmalı.
- Belli bir kalite ölçütüne yönelik olarak, şimdiye dek önerilen ölçütlerden bazıları seçilip, sezgisel olarak bir araya getirildikten sonra piyasada sınanarak iyileştirilebilir.
  - Sezgisel yetenek nasıl bulunacak?
  - Özel sektör gerekli çabaya nasıl ikna edilecek?

Hoca, proje yönetimi konusunda bahsedilen bir makaleyi ve ölçütlerin amaç değil araç olarak kullanılması gerektiğini hatırlattı. "Mükemmel, iyinin düşmanıdır" sözüne göre, ölçütlerin zayıf noktaları olsa da bu noktalarla çok sık karşılaşılmaz ve ölçütler genel bir rehber olarak kullanıldığı için kusurlu bir ölçüt bile hiç kullanmamaktan iyidir.

> **Hocanın vurgusu:** Ölçütler amaç değil araçtır; genel amaçlı bir rehber olarak kullanılmalıdır.

### 11.3 Geçerleme çalışmalarının önündeki engeller

Yazılım ölçütleriyle ilgili çalışmalar istenen yaygınlıkta değildir. Bunun iki nedeni vardır:

- Akademik taraf: ölçüt önermek cazip gelir ama geçerleme çalışmalarını yapmak zordur.
- Sektör tarafı: geçerleme çalışmaları gerçek yazılım projeleri üzerinde yapılmalıdır, ama yazılım şirketleri kaynak kodlarını bu tür çalışmalara açmaktan çekinir.

Hoca bir çözüm senaryosu anlattı: araştırmacı şirkete gider; şirket ona ağ bağlantısı olmayan, USB girişleri kapalı bir bilgisayar verir ve önceden gönderilen ölçüm araçlarını yükler. Araştırmacı ölçümleri yapar, sonuçları bir metin ya da Excel dosyası olarak teknisyenin gözü önünde kopyalayıp ayrılır. Bu yapılabilir, ama altta yatan başka bir sorun vardır: şirketin yazılımlarının kalite değerlerinin kötü çıkması o şirket için büyük bir sorun olur. Yayında firma adı verilmeyip "bir yazılım evinde" denebilir, ama ölçütlerin yorumlanması problem alanıyla ilişkili olduğu için alanın da belirtilmesi gerekir; o alanda ülkede çok az yazılım üreticisi varsa firma tahmin edilebilir.

Alternatif olarak açık kaynak yazılım projeleri üzerinde ölçüm yapılabilir. Ama açık kaynak yazılımların dinamikleri ticari yazılımlardan farklıdır; ticari yazılımlar üzerinde de yapılabilse daha iyi olurdu. Slayttaki "özel sektör gerekli çabaya nasıl ikna edilecek?" sorusu bu açmazı anlatır.

## 12. Kitaptan Eşik Değerleri ve Görselleştirme

Ders içeriği bittikten sonra hoca yazılım ölçütleri konusunda ek olarak "Object-Oriented Metrics in Practice: Using Software Metrics to Characterize, Evaluate, and Improve the Design of Object-Oriented Systems" (Michele Lanza, Radu Marinescu) kitabını gösterdi (ekrandan, 01:50:00). Kitap, yazılım ölçütlerinin ne olduğunu, ne olmadığını, nasıl kullanılıp yorumlanacağını anlatır ve kendi ölçüt takımını da önerir. Hoca bu kitabı yazılım ölçütleriyle ilgilenenlere önerdi.

### 12.1 Eşik değerleri

Yorumlama için sayısal sınırlar gerekir: çevrimsel karmaşıklık ne zaman iyi, ne zaman orta, ne zaman kötüdür? Metot başına satır sayısı (LOC/Method) ne olmalıdır, yani "uzun metot" ne kadar uzundur? Bir sınıfta kaç metot (NOM, number of methods) olmalıdır? Böl-parçala-yönet mantığıyla metot sayısının biraz yüksek olması beklenir, ama aşırı bölünme de olabilir; bunun için sayısal ölçüler gerekir.

Kitabın yazarları 45 Java ve 37 C++ projesini, küçük, orta ve büyük ölçekli projeleri de kapsayacak biçimde incelemiş ve istatistiksel eşik değerleri çıkarmıştır. Hoca önce temel ölçütlerin tablosunu anlattı: Java'da metot başına satır sayısı için ortalama 10'dur; 7 düşük sayılır, 10'un üzeri yüksek sayılmaya başlar ve çok yüksek değer 19,5'tir. Yani ortalamadan daha fazla satırı olan metotları bölmeye çalışmak mantıklıdır. C++'ta ortalama yine 10'dur ama yüksek ve çok yüksek değerler farklıdır. Kod satırı başına çevrimsel karmaşıklık (CYCLO/LOC) Java'da ortalama 0,20'dir; C++'ın daha zor bir dil olduğu düşünülürse C++'ta bu değerlerin Java'dan yüksek çıkması mantıklıdır. <!-- BELİRSİZ: bu ilk tablonun (Table 2.1) karesi yok; Java LOC/Method "yüksek" değeri altyazıda net değil. -->

Ekrandaki ikinci tabloda (Table 2.2) WMC şu biçimde tanımlanır: bir sınıfın bütün metotlarının çevrimsel karmaşıklıklarının toplamı. Bu, üç ölçüt cinsinden şöyle yazılır (ekrandan, 01:50:00):

$$WMC = \frac{CYCLO}{LOC} \cdot \frac{LOC}{Method} \cdot \frac{NOM}{Class}$$

Yüksek WMC eşiğini bulmak için üç terimin "yüksek" istatistiksel değerleri seçilip çarpılır. Benzer biçimde LOC/Class ve AMW (Average Method Weight, yani CYCLO/Method) için de eşikler hesaplanır. 45 Java ve 37 C++ sistemi için türetilen eşikler şunlardır (ekrandan, 01:50:00):

| Metrik | Java Low | Java Average | Java High | Java Very High | C++ Low | C++ Average | C++ High | C++ Very High |
|---|---|---|---|---|---|---|---|---|
| WMC | 5 | 14 | 31 | 47 | 4 | 23 | 72 | 108 |
| AMW | 1.1 | 2.0 | 3.1 | 4.7 | 1.0 | 2.5 | 4.8 | 7.0 |
| LOC/Class | 28 | 70 | 130 | 195 | 20 | 90 | 240 | 360 |
| NOM/Class | 4 | 7 | 10 | 15 | 4 | 9 | 15 | 23 |

Hoca, bir yazılım evinin kendi şimdiye kadar yazdığı kodlar üzerinde benzer istatistikleri çıkarabileceğini söyledi. Kitaptaki tablolar farklı alanlardaki projelerden çıkarıldığı için, belirli bir uygulama alanında çalışan bir ekip kendi geçmiş çalışmalarına dayanarak karar vermede kullanacağı eşikleri kendisi belirleyebilir ve bu daha anlamlı olur.

### 12.2 Polimetrik görünümlerle görselleştirme

Projedeki her sınıf bir dikdörtgenle gösterilebilir; dikdörtgenin genişliği, yüksekliği ve rengi ayrı birer ölçütü temsil eder. Hocanın örneğinde genişlik metot sayısını, yükseklik satır sayısını gösteriyordu: A dikdörtgeni ile karşılaştırıldığında C gibi uzun ve dar bir dikdörtgen, az sayıda ama çok satırlı, yani uzun metotlardan oluşan bir sınıf anlamına gelir ve istenmez; bu sınıfı kareye ya da yatık bir dikdörtgene yaklaştırmak gerekir. <!-- BELİRSİZ: A ve C dikdörtgenlerinin gösterildiği sayfanın karesi yok; genişlik/yükseklik eşleşmesi altyazıda bozuk geçiyor. -->

Ekrandaki kitap sayfasında gösterilen "System Complexity" görünümünde ise (ekrandan, 01:55:00) genişlik = öznitelik sayısı (number of attributes), yükseklik = metot sayısı (number of methods), renk = kod satırı sayısı (number of lines of code) olarak kullanılır. Sınıflar arasındaki kenarlar kalıtım ilişkilerini gösterir. Kitapta ayrıca bir kenarın kalınlığının ve renginin, iki sınıf arasındaki metot çağrısı sayısı gibi ilişki ağırlığını göstermek için kullanılabileceği yazar.

Bir araçla bütün projedeki sınıflar böyle çizildiğinde, refactoring yapılacaksa hangi sınıflardan başlanacağı bir bakışta anlaşılır. Hocanın şekil üzerindeki yorumu şöyleydi:

- Uzun metotlardan oluşan, karmaşık (koyu renkli) sınıflar ilk refactoring adaylarıdır. Rengin çevrimsel karmaşıklığı göstermesi de seçilebilir.
- Hiçbir kalıtım hiyerarşisine girmeyen ve anlaşılması zor olan bir sınıf görselde hemen göze batar; ilk adımda o ele alınır.
- Daha küçük, çubuğa benzeyen sınıflar daha az önemlidir. Amaç her şeyi mükemmelleştirmek değil, harcanan çabayı en iyi noktaya getirmektir.

Aynı karar, sınıfların LOC ve metot sayısı dökümünü sıralayarak da verilebilir. Her yinelemede sınırlı sayıda sınıf değiştirilebiliyorsa (ör. 5 sınıf), bu yöntemle kabaca da olsa en iyiye yakın bir seçim yapılabilir.

## Örnek Sorular

### Soru 1

(ekrandan, 01:35:00) WMC ölçütünde metot karmaşıklığı neye göre belirlenecek? Belirlemedeki öznellik güçlü yön mü, zayıf yön mü?

> **Çözüm (derste sözlü):** Karmaşıklık kişilere belirletilirse öznel olur; Delphi yöntemiyle yaklaştırmak mümkündür ama masraflıdır. Bu öznellik kimine göre güçlü, kimine göre zayıf yöndür; hoca zayıf yön olduğunu düşünür. Öznelliği gidermek için metot karmaşıklığı olarak kaynak koddan somut biçimde hesaplanan çevrimsel karmaşıklık (cyclomatic complexity) kullanılabilir.

### Soru 2

(ekrandan, 01:40:00) Belli bir kalite ölçütüne yönelik ölçütler seçilip sezgisel olarak bir araya getirildikten sonra piyasada sınanarak iyileştirilecekse, özel sektör gerekli çabaya nasıl ikna edilecek?

> **Çözüm (derste sözlü):** Şirketler kaynak kodlarını açmaktan ve kalite değerlerinin kötü çıkmasından çekinir. Ölçümler şirketin kontrolündeki ağa bağlı olmayan bir bilgisayarda yapılıp yalnız sonuçlar alınabilir, firma adı yayında gizlenebilir; ama alanda az üretici varsa firma yine tahmin edilebilir. Bir alternatif açık kaynak projeler üzerinde çalışmaktır, ancak onların dinamikleri ticari yazılımlardan farklıdır. Hoca bunu sektörle ilgili temel bir açmaz olarak niteledi.

### Soru 3

(derste sözlü, 00:51:08) Herhangi bir örnek durum verildiğinde bu hangi kalite ölçütüne girer?

> **Çözüm (derste sözlü):** Hoca, böyle bir soruda çoğu zaman birden fazla aday söylenebileceğini belirtti; çünkü kalite ölçütleri kimi durumlarda örtüşür ve birbirinden ayrılmaları zor olabilir. Bu yüzden ölçütlerin tanımları ve aralarındaki farklar (ör. güvenilirlik/güvenlik, yeniden kullanılabilirlik/esneklik, uyarlanabilirlik/taşınabilirlik, okunabilirlik/anlaşılabilirlik) iyi bilinmelidir.

## Dersin Toparlaması

Bu derste yazılım kalitesinin nasıl ölçüleceği ele alındı. Önce ölçme, ölçüt ve ölçüm kavramları ayrıldı ve ölçme verilerinden anlamlı sonuçlara geçişteki zorluk, yani yorumlama engeli tanıtıldı. Ardından doğrudan ve dolaylı ölçüm biçimleri, LOC tabanlı verimlilik, kalite, gider ve belgeleme ölçütleri ile dolaylı bir ölçüm olan fonksiyon noktası yöntemi anlatıldı; LOC ile FP'nin güçlü ve zayıf yönleri kıyaslandı. Kalite ölçütlerinin ISO 9126, McCall ve iç/dış ayrımına göre sınıflandırılması verildi; dış kalite ölçütleri (doğruluk, etkinlik, güvenilirlik, güvenlik, bütünlük, uyarlanabilirlik, hassaslık, sağlamlık, kullanılabilirlik) ve iç kalite ölçütleri (yeniden kullanılabilirlik, bakım kolaylığı, esneklik, taşınabilirlik, okunabilirlik, anlaşılabilirlik, sınanabilirlik) örneklerle açıklandı.

İkinci bölümde ölçme beş adımlı bir süreç olarak ele alındı, iyi bir ölçütün özellikleri sayıldı ve nesneye yönelik CK ölçütleri, özellikle WMC ayrıntılı incelendi. Ölçütlerin mükemmel olmadığı ama amaç değil araç olarak, bir rehber biçiminde kullanılması gerektiği vurgulandı. Ders, "Object-Oriented Metrics in Practice" kitabından eşik değerleri ve polimetrik görünümlerle refactoring adaylarının nasıl seçileceğini gösteren örneklerle kapandı. Bu ders, dönemin ders içeriğinin son konusuydu.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
