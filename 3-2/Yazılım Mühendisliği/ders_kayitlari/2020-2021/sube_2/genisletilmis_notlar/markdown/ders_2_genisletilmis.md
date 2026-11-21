# Ders 2 Genişletilmiş Notu: Yazılım Süreçlerinin Genel Adımları, CASE Araçları ve Süreç Modelleri

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Kalite Kontrolünde Rastgele Örnekleme (Random Sampling)
- 2. Yazılım Süreçlerinin Genel Adımları
- 3. Bilgisayar Destekli Yazılım Mühendisliği (CASE) ve Sürekli Tümleştirme (CI / DevOps)
- 4. Dördüncü Kuşak Diller ve Araçlar (4GL / 4GT)
- 5. Yazılım Geliştirme Süreçlerine Giriş ve Şelale Modeli
- 6. Ön Ürün (Prototip) Modeli
- 7. Hızlı Uygulama Geliştirme (RAD: Rapid Application Development)
- 8. Bileşen Tabanlı (Component-Based) Uygulama Geliştirme
- 9. Artımsal (Incremental) ve Yinelemeli (Iterative) Modellere Giriş
- Örnek Sorular
- Dersin Toparlaması

## 1. Kalite Kontrolünde Rastgele Örnekleme (Random Sampling)

Derste akademik konulara geçilmeden önce kalite kontrol süreçlerinde kullanılan **rastgele örnekleme (*random sampling*)** kavramının mantığı üzerinde durulmuştur. Bir üretim tesisinin çıkardığı ürünleri veya bir kurumun sunduğu hizmeti denetlerken, üretilen bütün ürünleri tek tek test etmek ya da hizmet alan bütün müşterilerle (hizmet alan = müşteri, hizmet veren = denetlenen kurum) tek tek görüşmek pratikte mümkün değildir.

Üstelik denetçinin hangi örnekleri inceleyeceği önceden biliniyorsa, denetlenen kurum yalnızca o örnekler üzerinde fazladan hazırlık yaparak kendisini gerçekte olduğundan daha iyi göstermeye çalışabilir. Bunun önüne geçmek için kalite denetiminde önceden bilinmeyen bir ölçütle **rastgele örnekler** seçilir ve bu örneklerin kalitesine bakılarak bütünün kalitesi hakkında çıkarım yapılır.

Bununla birlikte hoca, yazılım mühendisliğinde yazılım kalitesi ölçülürken rastgele örnekleme yönteminin kullanılmadığını özellikle belirtmiştir; çünkü yazılımda kaynak kod havuzunun tamamı elimizdedir ve otomatik ölçütlerle ya da sınama (*testing*) teknikleriyle doğrudan denetlenebilir.

## 2. Yazılım Süreçlerinin Genel Adımları

İlerleyen bölümlerde incelenecek olan yazılım geliştirme süreç modelleri (şelale, ön ürün, hızlı uygulama geliştirme, bileşen tabanlı, çevik süreçler vb.) iş akışını farklı şekillerde düzenlese de, tüm modellerde yürütülen temel mühendislik etkinlikleri beş genel adımda toplanır (ekrandan, 00:30:00):

1. **Çözümleme (*Analysis*)**
2. **Tasarım (*Design*)**
3. **Gerçekleme (*Implementation*)**
4. **Sınama (*Testing*)**
5. **Bakım (*Maintenance*)**

### 2.1 Çözümleme (Analysis)

Çözümleme kelimesinin sözlük tanımı, *"bir şeyi anlayabilmek için parçalarına ayırmak"*tır (ekrandan, 00:30:00). Buradaki anahtar kavram **anlayabilmektir**. Çözümleme aşamasında yapılan çalışmalar, gerçeklenecek sistemi anlamaya yönelik etkinliklerden ve üst düzey planlama eylemlerinden oluşur (ekrandan, 00:30:00):

- **Uygulama alanı (*problem domain*):** Ortaya çıkarılacak yazılım belirli bir problemi çözecektir. *"Bir sorunu anlamadan çözemezsiniz"* ilkesi gereği önce yazılımın çalışacağı iş ve problem alanı anlaşılır (ekrandan, 00:30:00).
- **Kullanıcı gereksinimleri:** Yazılımın hitap edeceği kullanıcı grubunun istek ve ihtiyaçları belirlenir (ekrandan, 00:30:00).
- **Program parçaları arasındaki üst düzey ilişkiler ve etkileşimler:** Nesneye yönelik programlama (NYP) yaklaşımı kullanıldığında bu parçalar **sınıflar (*classes*) ve nesnelerdir (*objects*)**; çözümleme aşamasında problem alanındaki temel varlıklar ve aralarındaki üst düzey ilişkiler keşfedilir (ekrandan, 00:30:00).
- **Üst düzey planlama ve kestirim (*estimation*):** Gereksinimler netleştikten sonra bu yazılım projesinin kaç kişiyle, ne kadar zamanda ve ne kadar bütçeyle tamamlanabileceğinin tahmini (*estimation*) yapılır. Kestirim zor bir sanattır; projeye atanacak insan kaynağının deneyimi ve ekip üyelerinin birbiriyle uyumu süreyi doğrudan etkiler. Çok acil bir proje değilse eldeki deneyimli ve deneyimsiz insan kaynağı projeler arasında en verimli olacak biçimde dağıtılır.

### 2.2 Tasarım (Design)

Çözümleme aşamasında **"neye"** ihtiyacımız olduğunu anladıktan sonra, tasarım aşamasında bu işi **"nasıl"** yapacağımızı planlarız. Tasarımın sözlük tanımı *"bir araştırma veya geliştirme sürecinin çeşitli dönemlerinde izlenecek yol ve işlemleri tasarlayan çerçeve"*dir; yazılım mühendisliği bağlamında ise çözümleme aşamasında anlaşılan problemi kodlamaya geçmeden önce **kâğıt üzerinde çözmeye çalışmaktır** (buradaki "kâğıt üzerinde" ifadesi mecazidir; pratikte elektronik teknik dokümantasyon araçları kullanılır).

Hoca, yazılım tasarımının önemini diğer mühendislik dallarından iki benzetmeyle açıklamıştır:
- **İnşaat ve mimarlık benzetmesi:** Bir bina inşa edilmeden önce mimar iç ve dış kat planlarını çizer, ardından inşaat mühendisi statik ve dinamik hesaplamaları yapar. Hesaplamalarda bir sorun çıkarsa mimara geri dönülüp plan revize edilir ve inşaat ancak bu planlar kesinleştikten sonra başlar.
- **Elektronik mühendisliği benzetmesi:** Bir elektronik kart üretilmeden önce devre şeması çizilir, yazılım üzerinde simülasyonu yapılır ve doğrulandıktan sonra fabrikaya baskı devre üretimine gönderilir.

Yazılım mühendisliğinde de çözümlemede keşfedilen varlıklar ve ilişkiler sistem düzeyindeki gereksinimlerle birleştirilerek ayrıntılandırılır. Nesneye yönelik tasarımda **ayrıntılı UML sınıf şemaları**, **sıralama (*sequence*) şemaları**, iş akışının ayrıntıları için **durum (*state*) ve etkinlik (*activity*) şemaları**, ayrıca verilerin kalıcılığını (*persistence*) sağlamak üzere bir veritabanı katmanı kullanılacaksa **veritabanı şemaları** oluşturulur.

### 2.3 Gerçekleme (Implementation)

Gerçekleme, eldeki tasarımın bir programlama dili kullanılarak kodlanmasıdır. İngilizce literatürde de yalnızca *coding* (kodlama) denmeyip ***implementation* (gerçekleme)** teriminin tercih edilmesinin nedeni, tasarımdan tüm kodun yüzde yüz otomatik üretilememesi ve kodlama sırasında geliştiricinin alt düzeyde ek teknik kararlar alıp tasarımı hayata geçirmesidir.

### 2.4 Sınama (Testing)

Sınama aşamasında geliştirilen yazılımın gereksinimleri karşılayıp karşılamadığı ve hata barındırıp barındırmadığı denetlenir. Slaytta sınamanın neden kritik olduğu üç temel özellikle vurgulanmıştır (ekrandan, 00:36:00):

- **Yazılım sürecinde ilerledikçe, ortaya çıkabilecek hataların giderilme maliyeti üstel olarak artar** (ekrandan, 00:36:00).
- **Aksi gibi, hataların büyük çoğunluğunun kökenleri isteklerin belirlenmesi ve tasarım aşamalarındaki sorunlara dayanır** (unutulan, eksik kalan veya yanlış anlaşılan gereksinimler ile yanlış tasarım kararları) (ekrandan, 00:36:00).
- **Bu yüzden: Erkenden, sık sık ve kolay sınama yapın** (ekrandan, 00:36:00).

> **Hocanın vurgusu:** İlk derste programcı yanılgıları arasında sayılan *"yazılımı tamamlamadan kalitesini ölçemem"* yanılgısı, *"yazılımı tamamlamadan test edemem"* biçiminde genişletilebilir. Kökeni gereksinim ve tasarım aşamasına dayanan bir hatayı kodlama bittikten sonra yakalamak çok ağır bir maliyet doğurur; bu yüzden sınama teknikleri daha çözümleme ve gereksinim analizi aşamalarından itibaren uygulanmalıdır.

### 2.5 Bakım (Maintenance)

Yazılımın müşteriye teslim edilip faaliyete (canlı kullanıma) geçirildiği andan itibaren bakım aşaması başlar ve bu andan sonra yapılan her türlü değişiklik **bakım faaliyeti** olarak adlandırılır. Bakım etkinlikleri dört ana grupta incelenir:

1. **Yazılım hatalarının düzeltilmesi:** Bakım aşamasında karşılaşılan hataları düzeltmenin zorluğu ve maliyeti, hatanın doğduğu aşamaya göre büyük fark gösterir:
   - *Kodlama hatalarını* düzeltmek en kolay ve en az maliyetli olanıdır.
   - *Tasarım hatalarını* düzeltmek çok daha zordur.
   - *Gereksinim ve analiz hatalarını* bakım aşamasında düzeltmek ise (değişiklik maliyetinin zamanla üstel artması kuralı gereği) en zor ve en pahalı olanıdır.
2. **Sistemin işlevlerini değiştirmek, yeni işlev eklemek veya işlev çıkarmak.**
3. **Yazılımı başka bir ortama taşımak:** Farklı bir programlama diline, farklı bir işletim sistemine veya farklı bir donanıma geçiş yapmak bakım kapsamındadır. Hatta gömülü bir yazılımda donanımın çalışacağı **iklim koşullarının** değişmesi bile donanımın davranışını değiştireceği için denetim yazılımında bakım yapılmasını gerektirebilir.
4. **Yeniden mühendislik (*Refactoring / Software re-engineering*) veya tersine mühendislik (*Reverse engineering*):**
   - **Teknik bakış açısı:** Yazılımın dış işlevini, dışarıya verdiği hizmeti ve arayüzünü değiştirmeden **iç yapısını değiştirmek/iyileştirmektir** (ekrandan, 00:40:00).
   - **Olası eylemler:** Yazılımın belgelendirilmesi, tasarımın iyileştirilmesi/değiştirilmesi ve yazılımın farklı bir ortama taşınması (ekrandan, 00:40:00).

Zaman içinde yapılan küçük ve yerel yamalar (*local optimum*) biriktikçe yazılım esnekliğini yitirir ve "yamalı bohça" hâline gelir. Artık ufak bir hata düzeltmesi bile çok fazla zaman ve maliyet gerektirmeye başladığında, tasarımı derleyip toparlamak için *refactoring* (belki yeni bir minör sürüm projesi olarak) gündeme gelir. Ticari bir yazılım evinde bu karar alınırken mutlaka bir **fayda-zarar analizi** yapılır: *refactoring* için harcanacak kişi-ay maliyeti ile mevcut yamalı yapıda hata düzeltmeye devam etmenin maliyeti tartılır. Hoca burada *"mükemmel, iyinin katilidir"* sözünü hatırlatarak kodlamada hiçbir zaman mutlak mükemmele ulaşılamayacağını, önemli olanın mühendislik dengesini kurmak olduğunu vurgulamıştır.

## 3. Bilgisayar Destekli Yazılım Mühendisliği (CASE) ve Sürekli Tümleştirme (CI / DevOps)

### 3.1 CASE Kavramı ve Vizyonu

**CASE (*Computer-Aided Software Engineering* — Bilgisayar Destekli Yazılım Mühendisliği)**, yazılım mühendisliği etkinliklerinin bir kısmını bilgisayar yardımıyla otomatik olarak gerçekleştirmeyi amaçlayan sistem ve araçlardır. Avrupa kökenli literatürde aynı kavram **IPSE (*Integrated Programming Support Environment* — Tümleşik Programlama Destek Ortamı)** olarak da adlandırılır; her iki terimde de anahtar kelimeler *aided* (destekli) ve *support* (destek) sözcükleridir.

Neden etkinliklerin tamamı değil de yalnızca **bir kısmı** otomatikleştirilebilir? Eğer CASE araçları ilk ortaya çıktıklarındaki vizyonu %100 gerçekleştirebilseydi, son kullanıcılar arada bir yazılım mühendisi olmadan kendi uygulamalarını doğrudan üretebilir, bilgisayar mühendislerine yalnızca yeni CASE araçları veya işletim sistemleri yazmak için ihtiyaç duyulurdu. Ancak tıpkı 1950'lerden beri konuşulan yapay zekânın belirli görevlerde insandan başarılı olsa da insanın yaptığı her şeyi yapabilen genel bir zekâya dönüşememesi gibi, yazılım mühendisliğinde çözülen problemler de çok karmaşık ve çetrefilli olduğundan tamamen otomatikleştirilemez. Hoca, gerçek hayatta CASE araçlarının otomatik kod üretimi katkısının %80–100 değil, yaklaşık **%25** düzeyinde kaldığını, ancak bu oranın bile ciddi bir maliyet tasarrufu sağladığını belirtmiştir.

### 3.2 CASE Sisteminin Öğeleri ve Mimarisi

Bir CASE sistemi üç temel öğeden oluşur (tercihen tek bir tümleşik paket olarak, ya da birbiriyle uyumlu çalışan ayrı yazılımlar hâlinde) (ekrandan, 01:00:00):

1. **İşlemler:** Yazılımın geliştirme sürecini düzenlemekte kullanılan yöntem bilimi (seçilen süreç modelinin desteklenmesi veya betiklerle/*script* uyarlanması) (ekrandan, 01:00:00).
2. **Yöntemler:** Projenin ve yazılım türünün gerektirdiği standart tasarım teknikleri ve yöntemleri (ekrandan, 01:00:00).
3. **Bütünleşik otomatik yazılım geliştirme araçları:** Oluşturulan modellerden mümkün olduğunca otomatik kod ve belge üreten araçlar (ekrandan, 01:00:00).

Slayttaki mimari şemada **CASE Teknolojisi**; kullanıcıların grafik görüntü arayüzü (ekran ve fare) üzerinden etkileştiği üç katmanlı bir yapı ve bunların bağlandığı merkezi bir **Ansiklopedik Arşiv** olarak gösterilmiştir (ekrandan, 01:06:00):

```text
                       +-----------------------+
                  +--->|    Üst CASE bölümü    |---> [ Diyagram Çizimi ve  ]---+
                  |    +-----------------------+     [ Tanımlama Araçları  ]   |
                  |                                                            |
+---------------+ |    +-----------------------+                               |   +---------------------+
|               | |    |   Orta CASE bölümü    |                               |   | Ansiklopedik Arşiv  |
| Grafik Görüntü|<+--->+-----------------------+---> [   Tasarım Analizi   ]---+-->| - Fonksiyonlar      |
| (İş İstasyonu)| |                                                            |   | - İşlevler          |
+---------------+ |    +-----------------------+                               |   | - Veri modelleri    |
                  |    |    Alt CASE bölümü    |                               |   | - Veri sözlüğü      |
                  +--->+-----------------------+---> [    Kod Çeviricisi   ]---+   +---------------------+
```

- **Üst CASE bölümü (*Upper CASE*):** Bilgisayara dayalı diyagram çizim araçları şeklinde grafik arayüz üzerinden kullanılan, iş mantığını betimleyen gereçlerdir (UML *use case* şemaları, akış şemalarının çok daha zengin hâli olan UML etkinlik şemaları, sınıf şemaları ve metot iç mantığını gösteren *sequence* diyagramları burada çizilir) (ekrandan, 01:06:00).
- **Orta CASE bölümü (*Middle CASE*):** Sistem analizi ve tasarımı gereçleridir; yapılan tasarımı çeşitli ölçütlere göre inceleyerek olası uyumsuzlukları ve sorun noktalarını kullanıcıya bildirir (ekrandan, 01:06:00).
- **Alt CASE bölümü (*Lower CASE*):** Kod üretim gereçleridir (*kod çeviricisi*); üst ve orta bölümlerde çizilen sınıf ve sıralama şemalarından mümkün olduğunca çok kaynak kodu otomatik üretmeye çalışır (ekrandan, 01:06:00).
- **Otomatik Ölçüm, Belgelendirme ve Hata Ayıklama:** Orta ve alt bölümlerde otomatik ölçüm, belgelendirme (kod dışındaki her türlü şema ve belgeyi ifade eden **yapıt / *artifact*** üretimi ve özel diyagramların standart UML şemalarına dönüştürülmesi) ile hata ayıklama (*debugging*) gereçleri de yer alır (ekrandan, 01:06:00).
- **Ansiklopedik Arşiv ve Veri Sözlüğü (*Data Dictionary*):** Üst, orta ve alt CASE araçlarının her basamakta ürettiği ara sonuçlar (**fonksiyonlar, işlevler, veri modelleri ve veri sözlüğü**) merkezi bir ansiklopedik arşivde saklanır (ekrandan, 01:06:00). Bu arşiv hem mevcut projenin ileri adımlarında hem de gelecekteki benzer projelerde yeniden kullanım (*reuse*) sağlar. Arşivdeki **veri sözlüğü (*data dictionary*)**, sistemde izlenecek niteliklerin ve verilerin türlerini, kısıtlarını ve anlamlarını tanımlar: örneğin *T.C. Kimlik Numarası* niteliğinin 11 haneli sayısal bir içerik olduğu veya *Adres* bilgisinin kendi içinde *Şehir*, *Semt*, *Cadde* gibi alt bileşenlere ayrıldığı veri sözlüğünde kayıtlıdır. Ayrıca *Subversion* veya *SourceForge* gibi kaynak kod sürüm yönetim sistemlerinin de CASE ortamıyla tümleşik çalışması tercih edilir.

### 3.3 Güncel Eğilim: Sürekli Tümleştirme (Continuous Integration - CI) ve DevOps

Klasik CASE araçları bir dönem büyük firmalarda yoğun ilgi görmüş olsa da, günümüzün hız ve esneklik beklentileri karşısında ağır sıklet (*heavyweight*) ve hantal kalmaktadır. Bu nedenle günümüzde CASE araçlarının yerini aynı temel felsefeyi daha çevik biçimde uygulayan **Sürekli Tümleştirme (*Continuous Integration* - CI)** ve **DevOps (*Development Operations*)** yaklaşımları almıştır.

- **Sürekli Tümleştirme (CI):** Yazılım geliştirmede kullanılan destek araçlarının birbiriyle sürekli bütünleşik çalışması, bir aracın çıktısının diğerinin girdisini otomatik beslemesi, dokümantasyon ile kodun çift yönlü otomatik güncellenmesi (dokümantasyondan kod, koddan dokümantasyon üretilmesi), sınıf şemalarından ve koddan otomatik test senaryolarının (*test cases*) üretilip koşturulması ve başarısız olan testlerin neden/nerede başarısız olduğunun raporlanmasıdır.
- **DevOps (*Development Operations*):** Yazılım ekibindeki bir kişinin yalnızca tek bir dar göreve kapanması yerine; gereksinim belirlemeden analize, tasarımdan kodlama ve sınamaya, oradan da yazılımın müşteri ortamına kurulmasına (**konuşlandırma / *deployment***: hangi alt bileşenlerin ayakta olması gerektiği, veritabanı sunucusunun nasıl kurulup hangi kullanıcı yetkilerinin tanımlanacağı vb.) kadar tüm yaşam döngüsü adımlarını anlayacak şekilde kendisini geliştirmesi ve odaklandığı alanda uzmanlaşması yaklaşımıdır.

**Soru:** Gerçek dünyada kullanılan Sürekli Tümleştirme (CI) ve tümleşik geliştirme ortamlarına örnek verebilir misiniz?

**Cevap:** Hoca gerçek dünyadan iki büyük ekosistem örneği vermiştir:
1. **Microsoft ekosistemi:** Geçmişte *Microsoft Team System* / **Team Foundation Server (TFS)** adıyla bilinen, bulut ve DevOps dönüşümüyle birlikte güncel adı **Azure DevOps Server** olan tümleşik ortam.
2. **Java ve kurumsal ekosistem:** **IBM Rational** ürün ailesi (geçmişteki *Rational Rose* ve sonrasında Eclipse tabanlı tümleşik Rational araçları).

*(Not: Bir öğrencinin sohbet ekranından sorduğu kod inceleme ve CI entegrasyon aracı **Gerrit** hakkında ise hoca o an aracı duymadığını, inceleyip sonraki derste bilgi vereceğini belirtmiştir.)*

## 4. Dördüncü Kuşak Diller ve Araçlar (4GL / 4GT)

Programlama dilleri tarihsel gelişimine göre kuşaklara (*generations*) ayrılır:
- **1. Kuşak (1GL):** Alt düzey makine dili.
- **2. Kuşak (2GL):** *Assembly* dili.
- **3. Kuşak (3GL):** Yapısal programlama ve nesneye yönelik programlama dilleri (C, Java, C# vb.).
- **4. Kuşak (4GL / 4GT — *Fourth Generation Languages / Tools*):** Bir yazılımın grafik arayüzler üzerinden görsel olarak kodlanabilmesini sağlayan diller (`4GL`) ve araçlar (`4GT`).

Dördüncü kuşak teknikler, CASE teknolojisinin daha küçük ve hafif sıklet (*lightweight*) bir alt kümesi gibi düşünülebilir: CASE mimarisindeki üst, orta ve alt CASE katmanlarını arada ansiklopedik arşiv veya ayrı bir veri sözlüğü katmanı olmaksızın, ayrılmaz tek bir bütün hâlinde sunarlar. Dördüncü kuşak diller üçüncü kuşak dilleri ortadan kaldırmamış, ancak **SAP** gibi çok karmaşık **ERP (*Enterprise Resource Planning* — Kurumsal Kaynak Planlama)** ve lojistik yazılımlarının özelleştirilmesinde kendine kalıcı bir kullanım alanı bulmuştur.

Hoca bu kullanım alanını **sandalye üreten bir fabrika** örneğiyle açıklamıştır: Fabrikanın farklı parçaları temin ettiği çok sayıda tedarikçisi, farklı sandalye modellerini birleştiren farklı montaj tezgâhları ve farklı uzmanlıklara sahip işçileri vardır; süreç parça tedarikinden siparişlerin paketlenip sevk edilmesine, irsaliye kesilmesine ve verilerin mali bilgi sistemine (muhasebeye) aktarılmasına kadar uzanır. Firma bu süreci yönetmek için **SAP** ERP paketini satın alır; ancak SAP içinde ön tanımlı gelen standart iş akışlarından hiçbiri firmanın kendine özgü üretim yapısına birebir uymaz.

Bu durumda özel bir BT ekibi olmayan veya küçük bir ekibe sahip olan firmada, bir **konu alanı uzmanı** ya da **üst düzey yönetici** SAP'nin sunduğu **4GT** grafik arayüzünü açar. Doğrudan 3. kuşak kod yazmak yerine, hazır iş akışı bileşenlerini tıpkı akış şeması çizer gibi ekranda koşullarla birbirine bağlayarak kendi iş akışını tanımlar ve bileşenlerin iç özelliklerini tıklayarak yapılandırır; araç bu görsel akışı arka planda otomatik olarak sistemin anlayacağı koda çevirir. Bu amaçla sektörde iki temel iş akışı standardı/notasyonu yaygın kullanılır:
- **`BPEL`**
- **`BPMN`**

> **Ders sonrası not:** Hoca derste bu iki standardın açılımını sözlü olarak `BPEL` için *"Business Process Engineering Language"* ve `BPMN` için *"Business Process Markup Language"* şeklinde söylemiştir (01:25:06). Literatürde bu standartların gerçek açılımları büyük olasılıkla **BPEL (*Business Process Execution Language*)** ve **BPMN (*Business Process Model and Notation*)** şeklindedir.

> **Hocanın vurgusu:** 4GL ve 4GT araçlarının amacı programlama bilmeyen konu uzmanlarının veya yöneticilerin grafik arayüzle iş akışlarını biçimlendirmesini sağlamaktır; ancak bunu yapabilmek için bile kişinin arka planda mutlaka **algoritmik düşünme yeteneğine** sahip olması şarttır. Algoritmik düşünme altyapısı yoksa en mükemmel 4GT aracı bile işe yaramaz.

## 5. Yazılım Geliştirme Süreçlerine Giriş ve Şelale Modeli

### 5.1 Süreç ve Süreç Modeli Kavramı

Yazılım geliştirme yaşam döngüsü bir **süreçtir** (ekrandan, 01:30:00):

- **Süreç (*Process*):** Önceden belirlenmiş adımlardan oluşan iş akışıdır (ekrandan, 01:30:00).
- **Süreç modelleri:** Yazılım geliştirme sürecinin yapısını ve adımlarını belirleyen modellerdir; önceden ve iyi planlanmış bir süreç, zamanında (ve planlanan bütçe/işlev kapsamında) ve "kaliteli" bir "ürün" elde edilmesini sağlar (ekrandan, 01:30:00).

Çeşitli süreç modellerinin kendine özgü avantaj ve dezavantajları vardır; bu nedenle **hem gerçeklenecek projeye hem de yazılım evinin/müşterinin kurum kültürüne ve çalışanlarına uygun modelin seçilmesi** gerekir (ekrandan, 01:30:00). Süreç bir zincirdir ve zincirin her halkası dikkatle örülmelidir; tek bir halkadaki zayıflık tüm zincirin oradan kopmasına yol açar. Ayrıca bir süreç modeli doğrudan kullanılmasa bile, içerdiği iyi fikirler ve pratikler kullanılan ana sürece dahil edilebilir.

### 5.2 Şelale Modeli (Ardışıl Model — Sequential / Waterfall Model)

1950'lerin sonu ve 1960'ların başındaki Yazılım Krizi'nin ardından literatürde önerilen **en eski** ve en uzun süredir kullanılan süreç modeli **Şelale Modeli (*Waterfall Model*)** veya diğer adıyla **Ardışıl Modeldir (*Sequential Model*)** (ekrandan, 01:35:00).

- **Adımlar:**
  $$\text{Çözümleme} \rightarrow \text{Tasarım} \rightarrow \text{Kodlama} \rightarrow \text{Sınama} \rightarrow \text{Bakım}$$
- **Çalışma kuralı:** Bir adım tamamen tamamlanmadan bir sonraki adıma geçilmez (önce tüm çözümleme biter, sonra yalnızca tasarım yapılır ve biter, sonra yalnızca kodlama yapılır ve biter, ardından yalnızca sınama yapılır ve sonunda kullanıma alınıp bakım aşamasına geçilir) (ekrandan, 01:35:00).
- **Hata durumunda geri dönüş:** Bir aşamada önemli bir eksiklik veya hata fark edilirse (örneğin kodlama sırasında kolay çözülemeyecek, tasarımdan kaynaklanan bir sorun çıkarsa), o aşamadaki tüm etkinlikler durdurulur ve komple **bir önceki adıma** (gerekirse oradan da bir önceki adıma) geri dönülür (ekrandan, 01:35:00).

**Artıları (ekrandan, 01:35:00):**
- En eski modeldir ve yaygın kullanımdadır; bu sayede hem kurumsal hem bireysel deneyim birikimi çok yüksektir.
- Adımları çok iyi tanımlanmıştır; hangi adımda ne yapılacağı ve ne üretileceği nettir.
- Önceden birçok kez başarıya ulaştırılmış projelere benzer **rutin projelerin** yürütülmesi için çok uygundur.

**Eksileri (ekrandan, 01:35:00):**
- Son ürünün elde edilmesi uzun süreceğinden müşteri sabırlı olmalıdır. Analiz ve tasarım şemaları çizilirken ortada çalışan bir program olmadığı için müşteri *"kaç aydır uğraşıyorsunuz, hâlâ çalışan bir şey yok mu?"* diyerek sabırsızlanabilir ve erken aşamada sınamaya/geri bildirime katılamaz.
- Adımlar geride bırakıldıkça, ilerleyen aşamalarda karşılaşılan hataların düzeltilmesi **üstel olarak zorlaşır** (tasarımdan çözümlemeye veya kodlamadan tasarıma geri dönmek projeyi ağır biçimde yavaşlatır).
- Birçok müşteri gereksinimlerini en başta eksiksiz ve kesin olarak belirtmekte zorlanır; kodlama bittikten sonra müşterinin başta söylemeyi unuttuğu zorunlu bir gereksinim ortaya çıkarsa süre ve bütçe büyük oranda şaşar. Yüksek teknik risklere karşı bağışıklığı yoktur.

**Sonuç ve Uygun Olduğu Durumlar (ekrandan, 01:35:00):**
Hiç model kullanmamaktan iyidir. Özellikle önceden benzerleri başarıyla yapılmış **rutin projelerde**, gerek yazılım evinin gerekse müşterinin **bürokratik kurum kültürüne** sahip olduğu (hangi fazın hangi tarihlerde biteceğinin, çıktılarının, hak ediş ve faturalandırma takvimlerinin baştan kesin belirlendiği) ortamlarda ve çok karmaşık olmasa da çalışan/işlev sayısı bakımından **büyük ölçekli** problemlerde adım adım dikkatli ilerlemek için uygundur.

## 6. Ön Ürün (Prototip) Modeli

**Ön ürün modeli (*Prototyping Model*)**, şelale modelinin gereksinimleri erken yakalayamama ve müşteriye geç ürün gösterme sorununu aşmak üzere önerilmiştir (ekrandan, 01:42:00).

```text
   +---------------------------------------------------------------+
   |                                                               |
   v                                                               |
[ Müşteriyi dinle ] ---> [ Ön ürün oluştur ] ---> [ Müşteri ön ürünü dener ]
```

- **Adımlar:** Müşteri dinlenir $\rightarrow$ Elde edilen bilgiye dayanarak hızlıca çalışan bir **ön ürün (*prototip*)** oluşturulur $\rightarrow$ Müşteri ön ürünü dener $\rightarrow$ Deneme sırasındaki olumlu/olumsuz geri bildirimlerle tekrar en baştaki *"Müşteriyi dinle"* adımına dönülür ve ön ürün değiştirilerek döngü sürdürülür (ekrandan, 01:42:00).
- **Artıları (ekrandan, 01:42:00):**
  - Kullanıcı gereksinimlerinin en net elde edildiği yöntemdir; müşteri önüne çalışan bir ekran geldiğinde *"burası böyle olmamış, şurası şöyle olmalıydı"* diyerek unutulan gereksinimleri hemen fark eder.
  - Kullanıcının ürünü erkenden değerlendirmeye başlayabilmesini sağlar; böylece değişiklik ihtiyaçları yaşam döngüsünün başında, maliyet henüz düşükken yakalanır.
- **Eksileri (ekrandan, 01:42:00):**
  - **Ön ürün mükemmel değildir:** Adı üstünde nihai ürün değil ön üründür; tek bir işlevde iyi görünse bile diğer işlevlerle birlikte çalışması yetersiz olabilir. Döngü bazen kırılamaz ve süreç literatürde küçümseyici bir ifadeyle ***Build and Fix* (Yap ve Düzenle / Yamala)** modeli denilen sonu gelmez bir deneme-yanılma sarmalına dönüşür.
  - **Eksik ürünün zaman ve maliyet kısıtlamaları nedeniyle olgunlaşmadan canlı kullanıma alınması riski:** Örneğin 1 yılda bitmesi planlanan proje 1-2 ay uzadığında, elinde yarım yamalak da olsa çalışan bir prototip gören müşteri *"benim işim acil, bu hâliyle şubelerimde/sahada kullanmaya başlıyorum"* diyerek olgunlaşmamış prototipi canlıya (bakım aşamasına) alabilir. Oysa canlıya alınmış eksik bir yazılımda düzeltme yapmak ve güncellemeleri sahaya yaymak çok zordur; yazılım hızla yamalı bohçaya döner.

> **Hocanın vurgusu:** Prototip oluşturmayı başlı başına bir yazılım geliştirme süreç modeli olarak **kullanmamalı**; şelale gibi daha olgun bir modelin **analiz (çözümleme) aşamasında** gereksinimleri netleştirmek için bir araç/teknik olarak ele almalı ve gereksinimler belirlendikten sonra **prototip ürünü tamamen silip atmalıdır** (ekrandan, 01:42:00).

Hoca burada çok pratik bir mühendislik tavsiyesi vermiştir: Prototipi yazdıktan sonra *"buna o kadar emek verdik, silmeyelim, üzerinden devam edip son ürüne çevirelim"* nefsine yenik düşmemek için, prototipi asıl projede kullanacağınız dilden **farklı bir dil ve ortamda** geliştirin. Örneğin asıl kurumsal projeyi yüksek eşzamanlı kullanıcı başarımı için Java veya C# ile geliştirecekseniz, analiz aşamasındaki prototipi sürükle-bırak form tasarımıyla 1 saatte ekran çıkarabildiğiniz *Visual Basic* gibi bir ortamda yazın; böylece prototipi canlı ürüne dönüştürme ihtimalini baştan kesmiş olursunuz.

## 7. Hızlı Uygulama Geliştirme (RAD: Rapid Application Development)

**Hızlı Uygulama Geliştirme (*RAD: Rapid Application Development*)**, görsel bir ekranda sürükle-bırak bileşenlerle kod yazmak anlamına gelmez; **kısa geliştirme çevrimleri üzerinde duran artımsal bir süreç modelidir** (ekrandan, 01:50:00).

Temel fikri, çözülecek ana problemi birbirinden mümkün olduğunca bağımsız alt problemlere bölmek ve bu alt problemleri farklı alt takımlara atayarak **eşzamanlı (paralel)** biçimde, seri üretim mantığıyla kodlamaktır. Örneğin 6 kişilik bir yazılım ekibi varsa ve problem birbirinden bağımsız 3 alt parçaya bölünebiliyorsa, ikişer kişilik 3 takım aynı anda kendi parçasını geliştirir ve sonunda parçalar küçük bir tümleştirme (*integration*) çabasıyla birleştirilir.

**Ön Koşullar (ekrandan, 01:50:00):**
1. Uygulamanın yaklaşık/ortalama **3 aylık** (projeye göre 2–5 aylık) birbirinden bağımsız bölümlere ayrılabilmesi.
2. Yeterli sayıda bölümün eşzamanlı ilerlemesinin sağlanabilmesi.
3. Yazılımın hazır **bileşenlerden** kurulabilmesi (eldeki geçmiş kod kütüphaneleri veya üçüncü parti ücretli/açık kaynak bileşenler kullanılarak hazır kısımların doğrudan alınması).

**Artıları (ekrandan, 01:50:00):**
- Bu sürece uygun yazılım projelerinde paralel çalışma ve hazır bileşen kullanımı sayesinde verimliliği ve geliştirme hızını büyük ölçüde artırır.

**Eksileri (ekrandan, 01:50:00):**
- Büyük ölçekli çalışmalarda yeterli sayıda bölümü eşzamanlı ilerletebilecek sayıda çalışan bulunamayabilir.
- Her problem birbirinden bağımsız parçalara bölünmeye uygun değildir; bir parçanın girdisi diğerinin çıktısına sıkıca bağımlıysa istenen paralelliğe ulaşılamaz ve parçalar arası eşgüdüm/tümleştirme maliyeti hız kazancını yok eder ("attığınız taş ürküttüğünüz kurbağaya değmez").
- Çalışanların bu yüksek hıza uyum sağlaması zordur.
- **Yüksek teknik risklere uygun değildir:** Projenin tamamlanması tüm alt parçaların başarılı olmasına bağlıdır; parçalardan birisi teknik bir imkânsızlık nedeniyle çözülemezse diğer tamamlanan parçalar tek başına ürünleştirilemeyeceği için tüm proje batar.

**Sonuç (ekrandan, 01:50:00):**
Günümüzde başlı başına bir süreç modeli olarak yaygın kullanılmaz; ancak **prototip geliştirmede** kullanılması veya ana fikirlerinin diğer süreçlere uygulanması (örneğin tasarım aşamasında aralarındaki **bağlaşımı / *coupling*** düşük olan modüller fark edildiğinde bunların paralel alt ekiplere atanması) son derece yararlıdır.

## 8. Bileşen Tabanlı (Component-Based) Uygulama Geliştirme

**Bileşen Tabanlı Uygulama Geliştirme (*Component-Based Software Engineering* - CBSE)**, uygulamanın tamamının hazır yazılım bileşenlerinden oluşturulmasını (elde hazır bileşen bulunmayan kısımlar içinse yeni bileşen yazılıp kataloglanmasını) öngören süreç modelidir (ekrandan, 02:00:00).

### 8.1 Sürecin Dört Aşaması

Diğer süreç modellerinden farklı olarak dört özel aşama tanımlar (ekrandan, 02:00:00):

1. **Konu alanı mühendisliği (*Domain Engineering*):** Çözülecek problem alanının, alt problem bileşenlerinin ve gereken hesaplama/özelliklerin anlaşılması aşamasıdır (geleneksel adımlardaki gereksinim ve çözümleme aşamasına karşılık gelir) (ekrandan, 02:00:00).
2. **Aday bileşenlerin sınıflandırılması ve seçilmesi (*Qualification*):** Problem anlaşıldıktan sonra bu ihtiyaçları karşılayacak aday bileşenlerin kurum içi bileşen kataloğundan veya üçüncü parti (ücretli ya da açık kaynak) bileşen kataloglarından bulunması, sınıflandırılması ve seçilmesidir (ekrandan, 02:00:00).
   - Elde $n$ adet gereksinim ve aday bileşenler varken, bazı bileşenler birden fazla gereksinimi kısmen veya tamamen karşılayabilir ve aralarında örtüşmeler olabilir.
   - Sınıflandırma yapılırken yalnızca üçüncü parti bileşenin başlangıçtaki satın alma/lisans ücretine (*upfront licensing fee*) bakılmaz; daha kritik olan ölçüt **bileşenin kendi yazılımımıza uyarlanması için gerekecek çaba ve işgücü maliyetidir**. Uzun vadeli toplam maliyet önemseniyorsa **en az uyarlama ihtiyacı gösterecek bileşen** seçilir.
3. **Seçilen bileşenlerin kendi yazılımımıza uyarlanması (*Adaptation*):** Seçilen bileşenlerin projenin özel gereksinimlerine göre değiştirilmesi ve uyarlanmasıdır (ekrandan, 02:00:00).
4. **Bileşenlerin bir araya getirilmesi (*Composition*):** Uyarlanan bileşenlerin tümleştirilerek bütüncül ürünün ortaya çıkarılmasıdır (3. ve 4. aşamalar kabaca gerçekleme/*implementation* adımına karşılık gelir; sonrasında ise standart bakım aşamasına geçilir) (ekrandan, 02:00:00).

### 8.2 Bileşen Kataloglama ve Standart Altyapılar (Soru-Cevap)

**Soru:** Bileşen kataloğu oluşturmak için kullanılan standart bir sistem var mı?

**Cevap:** Yaygın tek bir zorunlu sistem yoktur ancak şu yapılar ve araçlar kullanılabilir:
- **Sözleşme (*Contract*) yapısı:** İlerleyen haftalarda nesneye yönelik çözümleme/tasarım konularında görülecek olan *contract* (sözleşme) yapısı; bir metodun ana amacını, parametrelerini, dönüş tipini (*return type*) ve metot içinde kurulan nesne ilişkilerini/kayıtları metinsel olarak tanımlar ve bileşen kataloglaması için sağlam bir zemin oluşturur.
- **Etmen tabanlı (*Agent-based*) yazılım standartları:** Akademik dünyada rağbet gören etmen (*agent*) tabanlı geliştirmede etmen yeteneklerini belgeleyen standartlar.
- **Metot imzaları ve `Javadoc`:** Java'da metotların ve parametrelerin ne işe yaradığını özel yorum bloklarıyla (`/** ... */`) yazıp otomatik dokümantasyon üreten **`Javadoc`** aracı üzerinden bileşen kataloğu oluşturulabilir.

Ayrıca bileşenlerin kendi iç hizmetlerini diğer bileşenlere standart bir arayüzle açabilmesi için geçmişte Microsoft'un **`DLL`** mimarisine açık kaynaklı bir alternatif olarak **`CORBA` (*Common Object Request Broker Architecture*)** standardı yoğun biçimde kullanılmıştır; ancak bileşen tabanlı geliştirmenin her probleme aynı verimlilikle uygulanamaması nedeniyle günümüzde eski yaygınlığı kalmamıştır.

### 8.3 Artıları, Eksileri ve Yeniden Kullanım (Reuse) Oranları

- **Artıları:** Bileşenler şeklinde üretim yapıldığı için **yeniden kullanımın (*reusability*) özendirilmesini** sağlar ve geliştirme giderlerini azaltması beklenir (ekrandan, 02:00:00). Ancak hoca, literatürdeki araştırmalara göre yeniden kullanım odaklı geliştirmenin sağladığı gerçek maliyet kazancının **%20–30** bandında (bazen %10–15 düzeyinde) kaldığını, bunun da beklenen devrimsel tasarrufu her zaman vermediğini belirtmiştir.
- **Eksileri (ekrandan, 02:00:00):**
  - Uygun hazır bileşenlerin bulunması gerekir; ancak her zaman uygun bileşen bulunamaz ve sıfırdan yazılan bileşen başka projelerde tekrar kullanılmazsa harcanan emek sadece o projeye yük olur.
  - Bileşenlerin uyarlanması (*adaptation*) gerekir ve işin içine girildiğinde bu uyarlama başlangıçta göründüğü kadar kolay olmayabilir.
- **Sonuç:** Başlı başına bir süreç olarak çok sık kullanılmasa da, özellikle hızlı uygulama geliştirme (RAD) başta olmak üzere ana fikirleri çeşitli süreçlere uygulanabilir (ekrandan, 02:00:00).

## 9. Artımsal (Incremental) ve Yinelemeli (Iterative) Modellere Giriş

Dersin son bölümünde, günümüzdeki çevik (*agile*) süreçlerin de temelini oluşturan **artımsal (*incremental*) ve yinelemeli (*iterative*)** süreç modellerinin ortak çalışma mantığına giriş yapılmıştır.

Bu modellerde yazılım yaşam döngüsü tek bir doğrusal şelale gibi akmaz; bunun yerine birbirini izleyen çevrimler hâlinde ilerler:
1. Önce bir miktar **analiz (çözümleme)** yapılır (ilk çevrimdeki analiz biraz daha kapsamlı olabilir).
2. Bu analizden bir **tasarım** çıkarılır.
3. Tasarımdan **kod** üretilir ve **sınanır**.
4. Ardından tekrar **analiz** aşamasına dönülerek yeni bir çevrim başlatılır; tüm işlevler yeterli olgunluğa ulaştığında ürün teslim edilip **bakım** aşamasına geçilir.

Hoca bu çevrimlerde yapılan iki temel eylemin kavramsal farkını şöyle açıklamıştır:
- **Artım (*Increment*):** Gerçekleştirilen çevrimde yazılıma **yeni bir işlev / özellik ekleniyorsa** buna artım (*increment*) denir.
- **Yineleme (*Iteration*):** Yazılıma yeni bir işlev eklemeden, önceki çevrimde yapılan bir hatayı/eksikliği gidermek veya mevcut tasarımı ve kod yapısını iyileştirmek (*refactoring* yapmak, hatta henüz canlıya çıkılmadığı için metot imzalarını ve arayüzleri daha esnek hâle getirmek) amacıyla çevrim tekrarlanıyorsa buna yineleme (*iteration*) denir.

> **Hocanın vurgusu:** Artımsal ve yinelemeli modellerin püf noktası, **ön ürün (prototip) modeli ile ardışıl (şelale) modelin güçlü yönlerini kendinde toplamak ve her ikisinin zayıf yönlerini geride bırakmaktır**. Bu çevrimlerde hangi gereksinimin hangi sırayla ele alınacağının (gereksinimlerin önem sırasına göre önceliklendirilmesinin) çok iyi planlanması gerekir.

## Örnek Sorular

### Soru 1 (derste sözlü, 01:11:24)

**Soru:** Klasik CASE araçlarının yerini alan Sürekli Tümleştirme (*Continuous Integration* - CI) ve DevOps yaklaşımının temel mantığı nedir ve gerçek dünyada hangi tümleşik araçlar kullanılmaktadır?

**Çözüm (derste verildi):**
Klasik CASE araçları günümüzün hız ve esneklik gereksinimleri karşısında ağır sıklet (*heavyweight*) ve hantal kaldığından, aynı "yazılım mühendisliği etkinliklerini bilgisayar desteğiyle kolaylaştırma" fikri bugün **Sürekli Tümleştirme (CI)** ve **DevOps** çatısı altında yürütülmektedir. Bu yaklaşımda geliştirme araçları birbirine kesintisiz veri aktarır; dokümantasyondan kod ve koddan dokümantasyon çift yönlü otomatik üretilir; sınıf şemalarından ve koddan otomatik test senaryoları (*test cases*) çıkarılıp koşturulur ve hatalar anında raporlanır. DevOps yaklaşımında ise ekip üyeleri gereksinim analizinden kodlamaya, sınamadan müşteri ortamına kurulum (*deployment*) ve veritabanı yetkilendirmelerine kadar tüm süreci bütüncül olarak kavrar. Gerçek dünyadaki başlıca tümleşik örnekleri Microsoft ekosisteminde **Team Foundation Server (TFS) / Azure DevOps Server** ve Java/kurumsal ekosistemde **IBM Rational** ürün ailesidir.

### Soru 2 (derste sözlü, 01:57:59)

**Soru:** Bileşen tabanlı uygulama geliştirmede (*Component-Based Software Engineering*) kurum içi veya dışı bileşen kataloğu oluşturmak için kullanılan bir yapı veya standart var mıdır?

**Çözüm (derste verildi):**
Sektörde tek bir zorunlu katalog sistemi olmamakla birlikte şu yöntem ve araçlar bileşen kataloglamada kullanılır:
1. **Sözleşme (*Contract*) yapısı:** Her bir bileşen metodunun ne işe yaradığını, parametrelerini, dönüş tipini (*return type*) ve oluşturduğu nesne ilişkilerini/kayıtları metinsel olarak tanımlayan yapı.
2. **Etmen tabanlı (*Agent-based*) yazılım standartları:** Akademik çalışmalarda etmenlerin yeteneklerini belgelemek için kullanılan standartlar.
3. **Metot imzası listeleri ve `Javadoc`:** Java'da metot ve parametre açıklamalarının `/** ... */` biçimindeki özel yorum bloklarıyla yazılıp **`Javadoc`** aracıyla otomatik dokümantasyona dönüştürülmesi.

Bileşenlerin birbirine standart biçimde hizmet açması içinse geçmişte Microsoft'un `DLL` yapısına açık kaynak alternatif olarak **`CORBA` (*Common Object Request Broker Architecture*)** standardı kullanılmıştır.

## Dersin Toparlaması

Bu derste ilk olarak yazılım geliştirme yaşam döngüsünün tüm süreç modellerinde ortak olan beş genel adımı (**Çözümleme, Tasarım, Gerçekleme, Sınama ve Bakım**) incelenmiş; bir sorunu anlamadan çözemeyeceğimiz, hata giderme maliyetinin üstel artışı nedeniyle sınamanın daha ilk adımlardan itibaren erkenden ve sık sık yapılması gerektiği ve bakım aşamasında kodun dış davranışını değiştirmeden iç yapısını iyileştiren yeniden mühendislik (*refactoring*) kararlarının fayda-zarar analiziyle alındığı ortaya konmuştur. Ardından bu adımları otomatikleştirmeyi amaçlayan **CASE (*Computer-Aided Software Engineering*)** sistemlerinin üç öğesi ve mimarisi (Üst, Orta, Alt CASE ile Ansiklopedik Arşiv ve Veri Sözlüğü), günümüzdeki **Sürekli Tümleştirme (CI) / DevOps** karşılıkları ve ERP sistemlerinin (ör. SAP) iş akışı özelleştirmelerinde (`BPEL`, `BPMN`) kullanılan **dördüncü kuşak teknikler (4GL / 4GT)** ele alınmıştır.

Dersin ikinci yarısında yazılım geliştirme süreç modellerine geçilerek **Şelale (Ardışıl) Modeli**, **Ön Ürün (Prototip) Modeli**, **Hızlı Uygulama Geliştirme (RAD)** ve **Bileşen Tabanlı Uygulama Geliştirme** modellerinin adımları, ön koşulları, artıları, eksileri ve hangi projelerde nasıl kullanılmaları gerektiği karşılaştırılmıştır. Son olarak şelale ile prototip modellerinin güçlü yönlerini birleştiren **artımsal (*incremental*) ve yinelemeli (*iterative*)** modellerin çalışma ilkesine giriş yapılmış olup, bir sonraki derste bu noktadan devam edilerek artımsal/yinelemeli süreç modelleri ve çevik (*agile*) süreçler ayrıntılı olarak işlenecektir.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
