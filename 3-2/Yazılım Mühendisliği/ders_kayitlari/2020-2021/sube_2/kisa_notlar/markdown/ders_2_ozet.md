# Ders 2 Çalışma Özeti

## Genel Konular

- Kalite Kontrolünde Rastgele Örnekleme (*Random Sampling*) Kavramı
  - Üretim veya hizmet süreçlerinde tüm çıktıları ya da tüm hizmet alanları tek tek denetlemek mümkün olmadığında, denetlenen kurumun önceden özel hazırlık yapmasını önlemek ve bütünün kalitesi hakkında yansız fikir edinmek için rastgele seçilen örneklerin incelenmesi (yazılım kod havuzunda ise rastgele örnekleme yerine doğrudan sınama yöntemlerinin kullanılması).
- Yazılım Süreçlerinin Genel Adımları
  - Tüm yazılım geliştirme süreç modellerinde ortak olarak yürütülen beş temel etkinlik: **Çözümleme (*Analysis*)**, **Tasarım (*Design*)**, **Gerçekleme (*Implementation*)**, **Sınama (*Testing*)** ve **Bakım (*Maintenance*)** (ekrandan, 00:30:00).
  - Çözümleme (*analysis*): gerçeklenecek sistemi anlamak için parçalarına ayırma; uygulama/problem alanını (*problem domain*), kullanıcı gereksinimlerini ve program parçaları (nesneye yönelik programlamada sınıflar ve nesneler) arasındaki üst düzey ilişkileri/etkileşimleri anlama ve üst düzey kaynak/süre/bütçe kestirimi (*estimation*) yapma (ekrandan, 00:30:00).
  - Tasarım (*design*): çözümleme aşamasında anlaşılan problemin "nasıl" çözüleceğini kâğıt üzerinde (elektronik teknik dokümantasyon, ayrıntılı UML sınıf/sıralama/durum/etkinlik şemaları ve kalıcılık için veritabanı şemaları ile) planlama.
  - Gerçekleme (*implementation*): tasarımın bir programlama diliyle kodlanması ve kodlama sırasında gereken alt düzey teknik kararların alınması.
  - Sınama (*testing*): yazılım sürecinde ilerledikçe hata giderme maliyetinin üstel olarak artması ve hataların büyük çoğunluğunun kökeninin isteklerin belirlenmesi ile tasarım aşamalarına dayanması nedeniyle sınamanın erkenden, sık sık ve kolay yapılması (ekrandan, 00:36:00).
  - Bakım (*maintenance*): yazılım faaliyete geçirildiği andan itibaren yapılan hata düzeltme (kodlama, tasarım ve gereksinim/analiz hataları), işlev ekleme/değiştirme, farklı ortama (programlama dili, işletim sistemi, donanım, iklim koşulları) taşıma ve yeniden mühendislik (*refactoring / software re-engineering*) çalışmaları (ekrandan, 00:40:00).
- Bilgisayar Destekli Yazılım Mühendisliği (CASE) ve Dördüncü Kuşak Teknikler (4GL / 4GT)
  - CASE (*Computer-Aided Software Engineering*) / IPSE (*Integrated Programming Support Environment*) kavramı: yazılım mühendisliği etkinliklerinin bir kısmını bilgisayar desteğiyle otomatikleştirme vizyonu.
  - CASE sisteminin üç temel öğesi: **İşlemler** (süreci düzenleyen yöntem bilimi), **Yöntemler** (standart tasarım teknikleri) ve **Bütünleşik otomatik yazılım geliştirme araçları** (ekrandan, 01:00:00).
  - CASE teknolojisi mimarisi: grafik görüntü iş istasyonu ile etkileşen **Üst CASE bölümü** (diyagram çizimi ve tanımlama araçları), **Orta CASE bölümü** (sistem analizi ve tasarımı gereçleri), **Alt CASE bölümü** (kod üretim gereçleri / kod çeviricisi) ve bunların ortak kullandığı **Ansiklopedik Arşiv** (fonksiyonlar, işlevler, veri modelleri, veri sözlüğü / *data dictionary*) (ekrandan, 01:06:00).
  - Günümüzde ağır sıklet (*heavyweight*) CASE araçlarının yerini **Sürekli Tümleştirme (*Continuous Integration* - CI)** ve **DevOps** (*Development Operations*) yaklaşımları ile Microsoft Team Foundation Server / Azure DevOps ve IBM Rational ürün ailesi gibi tümleşik ortamların alması.
  - Dördüncü kuşak diller ve araçlar (**4GL / 4GT** - *Fourth Generation Languages / Tools*): üst, orta ve alt CASE katmanlarını ansiklopedik arşiv olmadan tek parça ve hafif sıklet bir grafik arayüzde birleştiren; özellikle SAP gibi karmaşık ERP yazılımlarında iş akışlarını `BPEL` ve `BPMN` gibi notasyonlarla özelleştirmede kullanılan teknikler.
- Yazılım Geliştirme Süreç Modelleri
  - Süreç (*process*) kavramı ve projeye/kurum kültürüne uygun süreç modeli seçiminin maliyet, süre, işlev ve kalite hedeflerine etkisi (ekrandan, 01:30:00).
  - **Şelale Modeli (*Waterfall / Sequential Model*):** çözümleme $\rightarrow$ tasarım $\rightarrow$ kodlama $\rightarrow$ sınama $\rightarrow$ bakım adımlarının ardışıl yürütülmesi; artıları, eksileri ve rutin/bürokratik projelere uygunluğu (ekrandan, 01:35:00).
  - **Ön Ürün / Prototip Modeli (*Prototyping Model*):** müşteriyi dinle $\rightarrow$ ön ürün oluştur $\rightarrow$ müşteri ön ürünü dener döngüsü; gereksinimleri netleştirmedeki başarısı, *build-and-fix* tuzakları ve eksik ürünün canlıya alınması riski nedeniyle yalnız analiz aşamasında kullanılıp prototipin silinmesi kuralı (ekrandan, 01:42:00).
  - **Hızlı Uygulama Geliştirme (*RAD: Rapid Application Development*):** kısa geliştirme çevrimleri ve uygulamanın yaklaşık 3 aylık bağımsız alt bölümlere ayrılıp paralel takımlarca bileşenlerle geliştirilmesi; ön koşulları, avantajları ve yüksek teknik risklere/bağlaşımlı problemlere uygun olmaması (ekrandan, 01:50:00).
  - **Bileşen Tabanlı Uygulama Geliştirme (*Component-Based Software Engineering*):** konu alanı mühendisliği (*Domain Engineering*), aday bileşenlerin sınıflandırılması ve seçilmesi (*Qualification*), uyarlama (*Adaptation*) ve bir araya getirme (*Composition*) aşamaları; yeniden kullanım (*reusability*) kazanımları (%20-30), bileşen kataloglama (`Javadoc`, sözleşmeler/*contracts*, `CORBA`, `DLL`) ve uyarlama zorlukları (ekrandan, 02:00:00).
  - **Artımsal ve Yinelemeli Modeller (*Incremental and Iterative Models*):** şelale modeli ile prototip modelinin güçlü yönlerini birleştirerek her çevrimde yeni bir işlev ekleme (artım / *increment*) veya mevcut yapıyı iyileştirme (yineleme / *iteration*) yaklaşımına giriş.

## Hocanın Özellikle Vurguladığı Kısımlar

- Çözümlemenin Temel Kuralı: "Bir Sorunu Anlamadan Çözemezsiniz"
  - Çözümleme (*analysis*) aşamasının anahtar kelimesi **anlamaktır**: uygulama alanını, kullanıcı gereksinimlerini ve sistem parçaları arasındaki üst düzey ilişkileri tam anlamadan doğru bir tasarım ve kodlama yapılamaz (ekrandan, 00:30:00).
- Erkenden, Sık Sık ve Kolay Sınama Yapma Zorunluluğu
  - Yazılım sürecinde ilerledikçe hata giderme maliyeti üstel olarak artarken, hataların büyük çoğunluğunun kökeni tam da sürecin en başındaki isteklerin belirlenmesi ve tasarım aşamalarına dayanır (ekrandan, 00:36:00).
  - Bu nedenle *"yazılım tamamlanmadan test edilemez"* düşüncesi yanlıştır; daha gereksinim ve analiz aşamalarından başlayarak erkenden, sık sık ve araç destekli sınama yapılmalıdır; bakım aşamasında kodlama hatasını düzeltmek en kolay, tasarım hatasını düzeltmek zor, gereksinim/analiz hatasını düzeltmek ise en zor ve en maliyetli iştir.
- Bakımda Yeniden Mühendislik (*Refactoring / Software Re-engineering*) Kararı
  - Zamanla yerel yamalarla "yamalı bohçaya" dönen bir yazılımda ufak bir değişiklik bile çok pahalı hâle geldiğinde, yazılımın dış işlevini ve arayüzünü değiştirmeden iç yapısını iyileştirmek (*refactoring*) gerekir; ancak ticari bir yazılım evinde bu karar mutlaka **fayda-zarar (maliyet) analizi** yapılarak verilmelidir (ekrandan, 00:40:00).
- Ön Ürün (Prototip) Modelinde Prototipin Silinip Atılması Kuralı
  - Prototip oluşturma başlı başına bir süreç modeli olarak kullanıldığında süreç "yap-düzenle" (*build and fix*) kısır döngüsüne girer ve zaman/bütçe baskısıyla olgunlaşmamış ön ürün canlı kullanıma alınarak ağır bakım sorunları doğurur (ekrandan, 01:42:00).
  - Bu yüzden prototipleme yalnızca daha olgun bir modelin **analiz aşamasında** gereksinimleri netleştirmek için bir araç olarak kullanılmalı ve gereksinimler elde edildikten sonra **prototip ürün tamamen silinip atılmalıdır** (hatta nefse yenik düşmemek için prototip Visual Basic gibi hızlı ama asıl projede kullanılmayacak farklı bir dil/ortamda geliştirilebilir) (ekrandan, 01:42:00).
- Bileşen Seçiminde (*Qualification*) Lisans Ücretinden Çok Uyarlama Maliyetinin Önemi
  - Bileşen tabanlı geliştirmede üçüncü parti bir bileşen seçilirken yalnızca başlangıçtaki satın alma/lisans ücretine (*upfront licensing fee*) bakılmamalıdır; bileşeni kendi sistemimize uyarlamak (*adaptation*) için harcanacak zaman ve işgücü maliyeti çoğu zaman ilk lisans ücretinden çok daha yüksek olduğundan, **en az uyarlama gerektiren bileşeni** seçmek toplam maliyeti düşürür (ekrandan, 02:00:00).

## Kısa Tekrar Notları

- **Yazılım süreçlerinin 5 genel adımı:** Çözümleme (*Analysis*) $\rightarrow$ Tasarım (*Design*) $\rightarrow$ Gerçekleme (*Implementation*) $\rightarrow$ Sınama (*Testing*) $\rightarrow$ Bakım (*Maintenance*) (ekrandan, 00:30:00).
- **Çözümleme vs. Tasarım:** Çözümleme **"ne"** yapılacağını (problem alanını ve gereksinimleri) anlamaktır; tasarım ise bunun **"nasıl"** yapılacağını (mimari, UML ve veritabanı şemalarıyla) kâğıt/ekran üzerinde planlamaktır.
- **Bakımda hata düzeltme zorluğu (kolaydan zora):** Kodlama hataları $<$ Tasarım hataları $<$ Gereksinim ve analiz hataları.
- **Yeniden mühendislik (*Refactoring / Software re-engineering*):** Yazılımın dış işlevini ve arayüzünü değiştirmeden iç yapısını iyileştirmek, yazılımı belgelendirmek veya farklı bir ortama taşımak (ekrandan, 00:40:00).
- **CASE (*Computer-Aided Software Engineering*) / IPSE:** Yazılım mühendisliği adımlarını otomatik araçlarla destekleyen sistem. Üç öğesi: **İşlemler**, **Yöntemler**, **Bütünleşik otomatik yazılım geliştirme araçları** (ekrandan, 01:00:00).
- **CASE mimarisi bölümleri:** **Üst CASE** (iş mantığını betimleyen diyagram çizim araçları), **Orta CASE** (sistem analizi ve tasarımı gereçleri), **Alt CASE** (kod üretim/çevirici gereçleri) ve ortak **Ansiklopedik Arşiv** (fonksiyonlar, işlevler, veri modelleri, veri sözlüğü) (ekrandan, 01:06:00).
- **Veri sözlüğü (*data dictionary*):** Sistemde izlenen veri ve niteliklerin türlerini, uzunluklarını, alt bileşenlerini ve anlamlarını tanımlayan yapı (ör. T.C. kimlik numarasının 11 haneli sayısal içerik olması, adresin şehir/semt/cadde alt alanlarına ayrılması) (ekrandan, 01:06:00).
- **Sürekli Tümleştirme (*Continuous Integration* - CI) ve DevOps:** Hantal CASE araçlarının yerine geçen, geliştirme araçlarının birbirini sürekli beslediği, dokümantasyon-kod-otomatik test üretiminin tümleşik yürüdüğü güncel yaklaşım (ör. Microsoft Team Foundation Server $\rightarrow$ Azure DevOps, IBM Rational ailesi).
- **Programlama dili kuşakları:** 1. kuşak = Makine dili, 2. kuşak = Assembly, 3. kuşak = Yapısal ve nesneye yönelik yüksek seviyeli diller, 4. kuşak (**4GL / 4GT**) = Grafik arayüz üzerinden iş akışı (`BPEL`, `BPMN`) ve ERP (ör. SAP) özelleştirmesi sağlayan diller/araçlar.
- **Şelale (*Waterfall*) modeli:** Ardışıl ilerler; bir adım bitmeden diğerine geçilmez, hata çıkarsa önceki adıma dönülür. En eski ve iyi tanımlanmış modeldir; rutin, büyük ölçekli ve bürokratik projeler için uygundur ancak yüksek teknik risklere ve belirsiz gereksinimlere dayanıksızdır (ekrandan, 01:35:00).
- **Ön ürün (*Prototyping*) modeli:** Müşteriyi dinle $\rightarrow$ Ön ürün oluştur $\rightarrow$ Müşteri dener döngüsü. Gereksinimleri erken yakalar ancak *build-and-fix* döngüsüne ve eksik ürünün canlıya alınmasına yol açabilir; yalnız analiz aşamasında kullanılmalı ve prototip atılmalıdır (ekrandan, 01:42:00).
- **Hızlı Uygulama Geliştirme (*RAD*):** Uygulamayı ~3 aylık bağımsız parçalara bölüp paralel takımlarla ve hazır bileşenlerle geliştirme. Düşük bağlaşımlı (*low coupling*) alt sistemler ve yeterli insan kaynağı gerektirir; yüksek teknik risklere uygun değildir (ekrandan, 01:50:00).
- **Bileşen Tabanlı Geliştirme (*CBSE*) aşamaları:** 1) Konu alanı mühendisliği (*Domain Engineering*), 2) Aday bileşenlerin sınıflandırılması ve seçilmesi (*Qualification*), 3) Uyarlama (*Adaptation*), 4) Bir araya getirme (*Composition*). Yeniden kullanımı (*reuse*) özendirir (~%20-30 maliyet kazancı) (ekrandan, 02:00:00).
- **Artımsal (*Incremental*) vs. Yinelemeli (*Iterative*):** Çevrimde yazılıma yeni bir özellik/işlev ekleniyorsa **artım (*increment*)**, yeni işlev eklemeden mevcut tasarım/kod iyileştiriliyorsa **yineleme (*iteration*)** yapılır.

## Detaylı Açıklamalar

### 1. Kalite Kontrolünde Rastgele Örnekleme (*Random Sampling*)

Bir üretim bandının veya hizmet sürecinin kalitesi denetlenirken, üretilen tüm ürünleri ya da hizmet alan tüm müşterileri tek tek incelemek çoğu zaman imkânsızdır. Ayrıca denetlenecek koşullar çok önceden bildirilirse, denetlenen kurum yalnızca o noktalar için yapay hazırlık yaparak kendini olduğundan daha iyi göstermeye çalışabilir. Bunu önlemek ve bütünün kalitesi hakkında doğru bir gösterge elde etmek için kalite kontrolünde **rastgele örnekleme (*random sampling*)** yöntemi kullanılır. Bununla birlikte hoca, yazılım mühendisliğinde kaynak kod havuzu elimizde olduğu için yazılım kalitesini ölçerken rastgele örnekleme yapmaya gerek olmadığını, doğrudan kod metrikleri ve sınama yöntemlerinin kullanıldığını belirtmiştir.

### 2. Yazılım Süreçlerinin Genel Adımları

Farklı yazılım geliştirme süreç modelleri bulunsa da hepsinin temelinde beş genel adım yer alır (ekrandan, 00:30:00):

1. **Çözümleme (*Analysis*):** Sözlük anlamıyla *"bir şeyi anlayabilmek için parçalarına ayırmak"* demektir (ekrandan, 00:30:00). Gerçeklenecek sistemi **anlamaya** yönelik çalışmalardan ve **üst düzey planlama eylemlerinden** oluşur:
   - **Uygulama alanı (*problem domain*):** Çözülecek problemin ait olduğu iş/uygulama alanının anlaşılması ("Bir sorunu anlamadan çözemezsiniz") (ekrandan, 00:30:00).
   - **Kullanıcı gereksinimleri:** Yazılımı kullanacak kitlenin istek ve ihtiyaçlarının belirlenmesi (ekrandan, 00:30:00).
   - **Program parçaları arasındaki üst düzey ilişkiler ve etkileşimler:** Nesneye yönelik programlama (NYP) yaklaşımında sistemdeki ana **sınıfların ve nesnelerin** keşfedilmesi (ekrandan, 00:30:00).
   - **Üst düzey planlama ve kestirim (*estimation*):** Netleşen gereksinimlerin kaç kişilik birelikle, hangi deneyim düzeyindeki insan kaynağıyla, ne kadar sürede ve ne kadar bütçeyle tamamlanabileceğinin tahmin edilmesi.
2. **Tasarım (*Design*):** Çözümleme aşamasında "neye" ihtiyaç olduğu anlaşıldıktan sonra, tasarım aşamasında bunun **"nasıl"** yapılacağı kâğıt üzerinde (elektronik teknik dokümantasyonla) planlanır. Tıpkı inşaatta mimarın kat planlarını çizip inşaat mühendisinin statik-dinamik hesapları yapması veya elektronikte devre şemasının çizilip simüle edildikten sonra baskı devreye gönderilmesi gibi, yazılımda da kodlamaya geçmeden önce ayrıntılı UML sınıf şemaları, sıralama (*sequence*) şemaları, iş akışı için durum/etkinlik şemaları ve kalıcılık (*persistence*) katmanı için veritabanı şemaları oluşturulur.
3. **Gerçekleme (*Implementation*):** Oluşturulan tasarımın bir programlama diliyle kodlanmasıdır. Tasarımdan tüm kod yüzde yüz otomatik üretilemediği ve kodlama sırasında ek alt düzey kararlar alındığı için yalnızca "kodlama" yerine daha kapsamlı olan "gerçekleme" terimi kullanılır.
4. **Sınama (*Testing*):** Yazılım sürecinde ilerledikçe ortaya çıkabilecek hataların giderilme maliyeti **üstel olarak artar** (ekrandan, 00:36:00). Üstelik hataların büyük çoğunluğunun kökeni, sürecin en başındaki isteklerin belirlenmesi ve tasarım aşamalarındaki eksikliklere veya yanlış kararlara dayanır (ekrandan, 00:36:00). Bu nedenle sınama kodlama bitene kadar bekletilmemeli; daha gereksinim ve çözümleme aşamalarından itibaren **erkenden, sık sık ve kolay** (araç destekli) sınama yapılmalıdır (ekrandan, 00:36:00).
5. **Bakım (*Maintenance*):** Yazılımın canlı kullanıma alındığı andan itibaren yürütülen tüm değişiklik faaliyetleridir:
   - **Hata düzeltme:** Kodlama hatalarını düzeltmek en kolay ve en ucuz olanıdır; tasarım hatalarını düzeltmek daha zordur; gereksinim ve analiz hatalarını bakım aşamasında düzeltmek ise en zor ve en pahalı olanıdır.
   - **İşlev ekleme/değiştirme ve ortam taşıma:** Yeni işlevlerin eklenmesi veya yazılımın farklı bir programlama diline, işletim sistemine, donanıma ya da gömülü sistemlerde farklı iklim/çevre koşullarına taşınması.
   - **Yeniden mühendislik (*Refactoring / Software re-engineering*):** Teknik bakış açısıyla **yazılımın dış işlevini ve arayüzünü değiştirmeden iç yapısını değiştirmek/iyileştirmektir** (ekrandan, 00:40:00). Zamanla yapılan yerel yamalar yüzünden "yamalı bohçaya" dönen yazılımın belgelendirilmesi, tasarımının iyileştirilmesi/değiştirilmesi veya farklı bir ortama taşınması eylemlerini kapsar (ekrandan, 00:40:00). Ticari bir yazılım evinde *refactoring* kararı alınırken, bu işlemin kaç kişiyle ne kadar süreceği ile mevcut yapıda hata düzeltmenin getirdiği ek maliyet karşılaştırılarak bir fayda-zarar analizi yapılır.

### 3. CASE Sistemleri, Sürekli Tümleştirme (CI / DevOps) ve 4. Kuşak Teknikler (4GL / 4GT)

**CASE (*Computer-Aided Software Engineering* — Bilgisayar Destekli Yazılım Mühendisliği)** veya Avrupa literatüründeki adıyla **IPSE (*Integrated Programming Support Environment*)**, yazılım geliştirme sürecindeki adımların bir kısmını bilgisayar desteğiyle otomatikleştiren sistemlerdir. Çözülen problemlerin karmaşıklığı nedeniyle hiçbir CASE aracı yazılım mühendisini tamamen devre dışı bırakıp sürecin %100'ünü otomatikleştiremez (hoca günlük pratikte kod üretimi katkısının ~%25 dolayında kalabildiğini belirtmiştir); ancak şema çizimi, tasarım analizi, kod iskeleti üretimi ve belgelendirmede önemli kolaylık sağlar.

Bir CASE sistemi üç temel öğeden oluşur (ekrandan, 01:00:00):
1. **İşlemler:** Yazılımın geliştirme sürecini düzenlemekte kullanılan yöntem bilimi (seçilen süreç modelinin desteklenmesi) (ekrandan, 01:00:00).
2. **Yöntemler:** Projenin gerektirdiği standart tasarım teknikleri ve yöntemleri (ekrandan, 01:00:00).
3. **Bütünleşik otomatik yazılım geliştirme araçları:** Diyagram çizimi, tasarım analizi ve otomatik kod üretimi yapan araçlar (ekrandan, 01:00:00).

Slayttaki mimari diyagrama göre **CASE Teknolojisi** üç katmana ve merkezi bir arşive ayrılır (ekrandan, 01:06:00):
- **Üst CASE bölümü (*Upper CASE*):** Grafik görüntü arayüzü üzerinden kullanılan, bilgisayara dayalı **diyagram çizimi ve tanımlama araçları** ile iş mantığını betimleyen gereçlerdir (ör. UML *use case*, etkinlik, sınıf ve sıralama şemaları) (ekrandan, 01:06:00).
- **Orta CASE bölümü (*Middle CASE*):** **Tasarım analizi**, sistem analizi ve tasarımı gereçleridir (tasarımdaki tutarsızlıkları ve olası sorun noktalarını denetler) (ekrandan, 01:06:00).
- **Alt CASE bölümü (*Lower CASE*):** **Kod çeviricisi** ve kod üretim gereçleridir (ör. çizilen sınıf ve *sequence* diyagramlarından kod üretir). Ayrıca orta ve alt bölümlerde otomatik ölçüm, belgelendirme (*artifact* üretimi) ve hata ayıklama gereçleri yer alır (ekrandan, 01:06:00).
- **Ansiklopedik Arşiv:** Üst, orta ve alt CASE bölümlerinin çift yönlü eriştiği merkezi depodur; içerisinde **fonksiyonlar, işlevler, veri modelleri ve veri sözlüğü (*data dictionary*)** saklanır (ekrandan, 01:06:00). Veri sözlüğü, sistemdeki niteliklerin yapısını ve anlamını tanımlar (ör. T.C. kimlik numarasının 11 haneli sayısal veri olması, adresin şehir/semt/cadde alt bileşenlerinden oluşması). Bu arşiv sayesinde ara sonuçlar hem mevcut projede hem de gelecekteki benzer projelerde yeniden kullanılabilir. Kaynak kod sürüm yönetimi için kullanılan *Subversion* veya *SourceForge* gibi sistemler de CASE ortamıyla tümleşik çalışabilir.

**Güncel Eğilim — Sürekli Tümleştirme (*Continuous Integration* - CI) ve DevOps:** Klasik CASE sistemleri günümüzün çevik ve esnek beklentileri karşısında ağır sıklet (*heavyweight*) ve hantal kaldığından, sektörde odak noktası **Sürekli Tümleştirme (CI)** ve **DevOps (*Development Operations*)** araçlarına kaymıştır. CI/DevOps yaklaşımında araçlar birbirini kesintisiz besler, dokümantasyon ile kod çift yönlü güncellenir, sınıf şemalarından ve koddan otomatik test senaryoları (*test cases*) üretilip koşturulur ve geliştiriciler gereksinimden sınamaya, veritabanı kurulumundan müşteri ortamına konuşlandırmaya (*deployment*) kadar tüm süreci bütüncül olarak kavrar. Gerçek dünya örnekleri olarak Microsoft ekosisteminde **Team Foundation Server (TFS)** (güncel adıyla **Azure DevOps Server**) ve Java/kurumsal ekosistemde **IBM Rational** ürün ailesi (*Rational Rose* vb.) öne çıkmaktadır.

**Dördüncü Kuşak Diller ve Araçlar (*4GL / 4GT — Fourth Generation Languages / Tools*):** Makine dili (1. kuşak), *assembly* (2. kuşak) ve yapısal/nesneye yönelik programlama dillerinin (3. kuşak) ardından, yazılımın grafik arayüzler üzerinden kodlanabilmesini sağlayan diller ve araçlar **4. kuşak (4GL / 4GT)** olarak adlandırılmıştır. CASE teknolojisinin üst, orta ve alt bölümlerini arada ansiklopedik arşiv veya veri sözlüğü olmadan tek parça ve daha hafif sıklet biçimde birleştiren bir alt küme gibidir. 3. kuşak dilleri ortadan kaldırmamış, özellikle **SAP** gibi karmaşık **ERP (*Enterprise Resource Planning*)** ve lojistik yazılımlarının kurumlara özelleştirilmesinde uzmanlaşmıştır. Örneğin farklı tedarikçilerden parça alıp farklı tezgâhlarda sandalye üreten bir firmanın kendine özgü sipariş, üretim, irsaliye ve muhasebe iş akışları SAP'nin standart akışlarına uymadığında; konu uzmanları veya yöneticiler doğrudan kod yazmak yerine **`BPEL`** ve **`BPMN`** gibi iş akışı notasyonlarıyla grafik ekranda hazır bileşenleri birbirine bağlayarak kendi iş akışlarını oluştururlar. Bununla birlikte hoca, en gelişmiş 4GT aracını kullanmak için bile kullanıcının temel **algoritmik düşünme** yeteneğine sahip olmasının şart olduğunu vurgulamıştır.

> **Ders sonrası not:** Hoca konuşmasında iş akışı standartlarının açılımını sözlü olarak `BPEL` için *"Business Process Engineering Language"* ve `BPMN` için *"Business Process Markup Language"* şeklinde ifade etmiştir (01:25:06); standartların literatürdeki tam açılımları büyük olasılıkla **BPEL (*Business Process Execution Language*)** ve **BPMN (*Business Process Model and Notation*)** şeklindedir.

### 4. Yazılım Geliştirme Süreç Modelleri

Yazılım geliştirme bir **süreç** (*önceden belirlenmiş adımlardan oluşan iş akışı*) olarak ele alınmalıdır (ekrandan, 01:30:00). Süreç modelleri bu sürecin yapısını ve adımlarını belirler; projeye ve kurum kültürüne uygun, iyi planlanmış bir süreç modeli seçmek bütçe, zaman, işlev ve kalite hedeflerine ulaşma şansını artırır (ekrandan, 01:30:00).

#### 4.1 Şelale Modeli (Ardışıl Model — Sequential / Waterfall Model)

- **Adımlar:** `Çözümleme -> Tasarım -> Kodlama -> Sınama -> Bakım` (ekrandan, 01:35:00).
- **İşleyişi:** Bir adım tamamen bitirilmeden bir sonraki adıma geçilmez (yalnızca çözümleme yapılır, bitince yalnızca tasarım yapılır, bitince yalnızca kodlama yapılır vb.). Bir aşamada önemli bir eksiklik veya hata fark edilirse o aşamadaki tüm çalışmalar durdurulur ve bir önceki adıma geri dönülür (ekrandan, 01:35:00).
- **Artıları:** En eski ve yaygın kullanımda olan modeldir; adımları çok iyi tanımlanmıştır ve kurumsal/bireysel deneyim birikimi yüksektir (ekrandan, 01:35:00).
- **Eksileri:** Son ürünün elde edilmesi uzun sürdüğü için müşteri sabırlı olmalıdır (müşteri uzun süre çalışan bir program göremediğinde huzursuzlanabilir ve erken geri bildirim veremez); adımlar geride bırakıldıkça ilerleyen aşamalarda karşılaşılan hataların düzeltilmesi üstel olarak zorlaşır; ayrıca birçok müşteri gereksinimlerini en başta eksiksiz ve kesin olarak belirtmekte zorlanır (ekrandan, 01:35:00).
- **Sonuç:** Hiçbir süreç modeli kullanmamaktan iyidir; yüksek teknik risk içermeyen, önceden birçok kez başarıya ulaştırılmış projelere benzer **rutin projelerin**, bürokratik kurum kültürlerinin ve büyük ölçekli projelerin yürütülmesi için uygundur (ekrandan, 01:35:00).

#### 4.2 Ön Ürün Modeli (Prototip Modeli — Prototyping Model)

- **Adımlar:** `Müşteriyi dinle -> Ön ürün oluştur -> Müşteri ön ürünü dener -> (Tekrar "Müşteriyi dinle" adımına dönülür)` (ekrandan, 01:42:00).
- **Artıları:** Müşteri çalışan bir ön ürünü (*prototip*) doğrudan deneyerek gördüğü için unutulan veya başta ifade edilemeyen **kullanıcı gereksinimleri çok daha iyi elde edilir** ve kullanıcı ürünü erkenden değerlendirmeye başlayabilir (ekrandan, 01:42:00).
- **Eksileri:** Ön ürün mükemmel değildir; sürekli *"yap-düzenle"* (literatürde küçümseyici ifadeyle ***build and fix***) kısır döngüsüne girme tehlikesi vardır. En büyük risk ise **eksik ürünün zaman ve maliyet kısıtlamaları nedeniyle henüz olgunlaşmadan müşteri tarafından canlı kullanıma (sahaya/şubelere) alınmasıdır**; bu durumda yazılım kısa sürede yamalı bohçaya döner ve bakım maliyeti patlar (ekrandan, 01:42:00).
- **Sonuç:** Prototip oluşturmayı başlı başına bir süreç modeli olarak **kullanmamalı**; şelale veya başka olgun bir modelin **analiz aşamasında** gereksinimleri netleştirmek için bir araç olarak kullanmalı ve gereksinimler belirlendikten sonra **prototip ürünü tamamen silip atmalıdır** (ekrandan, 01:42:00). Hatta prototipi son ürüne dönüştürme cazibesine kapılmamak için prototipi asıl proje dilinden (ör. Java) farklı, sürükle-bırak arayüz geliştirmesi hızlı bir ortamda (ör. Visual Basic) hazırlamak etkili bir önlemdir.

#### 4.3 Hızlı Uygulama Geliştirme (RAD: Rapid Application Development)

- **Tanım ve Ön Koşullar:** Yalnızca görsel ekranda sürükle-bırak kod yazmak demek değildir; **kısa geliştirme çevrimleri üzerinde duran artımsal bir modeldir** (ekrandan, 01:50:00). Üç temel ön koşulu vardır:
  1. Uygulamanın yaklaşık/ortalama **3 aylık** birbirinden bağımsız bölümlere ayrılabilmesi,
  2. Yeterli sayıda bölümün farklı alt ekiplerce **eşzamanlı (paralel)** ilerlemesinin sağlanabilmesi (ör. 6 kişilik ekibin 2'şer kişilik 3 takıma ayrılıp 3 parçayı paralel kodlaması),
  3. Yazılımın hazır **bileşenlerden** kurulabilmesi (ekrandan, 01:50:00).
- **Artıları:** Bu sürece uygun (düşük bağlaşımlı / *low coupling* parçalara bölünebilen) projelerde seri üretim mantığıyla verimliliği ve hızı önemli ölçüde artırır (ekrandan, 01:50:00).
- **Eksileri:** Büyük ölçekli çalışmalarda yeterli sayıda bölümü eşzamanlı ilerletebilecek sayıda çalışan bulunamayabilir; her problem birbirinden bağımsız parçalara bölünemez (parçalar arası bağımlılık yüksekse eşgüdüm ve tümleştirme çabası hızı düşürür); çalışanların bu yüksek hıza uyum sağlaması zordur; ayrıca parçalardan birinin teknik bir engel yüzünden tamamlanamaması tüm projeyi batıracağı için **yüksek teknik risklere uygun değildir** (ekrandan, 01:50:00).
- **Sonuç:** Prototip geliştirmede kullanılması veya ana fikirlerinin (tasarımda bağlaşımı düşük çıkan modüllerin paralel takımlara atanması gibi) diğer süreçlere uygulanması yerinde olur (ekrandan, 01:50:00).

#### 4.4 Bileşen Tabanlı (Component-Based) Uygulama Geliştirme

- **Tanım ve Aşamaları:** Uygulamanın hazır yazılım bileşenlerinden oluşturulmasını (elde hazır yoksa yeni bileşen yazılıp kataloglanmasını) öngörür (ekrandan, 02:00:00). Dört aşaması vardır:
  1. **Konu alanı mühendisliği (*Domain Engineering*):** Problem alanının ve alt problem gereksinimlerinin anlaşılması (kabaca gereksinim ve çözümleme aşaması) (ekrandan, 02:00:00).
  2. **Aday bileşenlerin sınıflandırılması ve seçilmesi (*Qualification*):** Kurumun kendi geçmiş projelerinden oluşturduğu bileşen kataloğundan veya üçüncü parti ücretli/açık kaynak kataloglardan aday bileşenlerin belirlenmesi, maliyet ve uyarlama yükü açısından değerlendirilip seçilmesi (ekrandan, 02:00:00).
  3. **Seçilen bileşenlerin kendi yazılımımıza uyarlanması (*Adaptation*):** Seçilen bileşenlerin projeye uyacak biçimde değiştirilmesi/uyarlanması (ekrandan, 02:00:00).
  4. **Bileşenlerin bir araya getirilmesi (*Composition*):** Uyarlanan bileşenlerin tümleştirilerek nihai ürünün oluşturulması (son iki adım kabaca gerçekleme/kodlama aşamasına karşılık gelir) (ekrandan, 02:00:00).
- **Bileşen Kataloglama ve Altyapı Standartları:** Bir öğrencinin *"Bileşen kataloğu oluşturmak için kullanılan bir sistem var mı?"* sorusu üzerine hoca; ilerleyen haftalarda görülecek **sözleşme (*contract*)** yapısının (metodun amacı, parametreleri, dönüş tipi ve kurduğu ilişkilerin metinsel tanımı), etmen tabanlı (*agent-based*) sistemlerdeki yetenek tanımlama standartlarının, metot imzası listelerinin ve Java'daki **`Javadoc`** (`/** ... */`) belgeleme aracının kataloglamada kullanılabileceğini belirtmiştir. Bileşenlerin birbirine standart biçimde hizmet açması için geçmişte Microsoft'un **`DLL`** yaklaşımına açık kaynak alternatif olarak **`CORBA` (*Common Object Request Broker Architecture*)** standardı yoğun kullanılmış, ancak süreç modelinin her probleme uymaması nedeniyle eski yaygınlığını yitirmiştir.
- **Artıları ve Eksileri:** En önemli artısı **yeniden kullanımın (*reusability*) özendirilmesidir**; ancak literatürdeki araştırmalar yeniden kullanımın sağladığı maliyet kazancının ortalama **%20–30** bandında kaldığını göstermektedir (ekrandan, 02:00:00). Eksileri ise her zaman uygun hazır bileşen bulunamaması (sıfırdan yazılan bileşenin başka projede kullanılmaması durumunda maliyet avantajının kaybolması) ve bileşenleri uyarlamanın (*adaptation*) başlangıçta göründüğü kadar kolay olmamasıdır (ekrandan, 02:00:00).
- **Sonuç:** Özellikle hızlı uygulama geliştirme (RAD) başta olmak üzere ana fikirleri çeşitli süreçlere uygulanabilir (ekrandan, 02:00:00).

#### 4.5 Artımsal ve Yinelemeli Modeller (Incremental and Iterative Models)

Dersin sonunda çevik (*agile*) süreçlerin de temelini oluşturan **artımsal (*incremental*) ve yinelemeli (*iterative*)** modellere giriş yapılmıştır. Bu modellerde süreç tek bir doğrusal akış yerine birbirini izleyen çevrimler hâlinde yürütülür: bir miktar analiz $\rightarrow$ tasarım $\rightarrow$ kodlama $\rightarrow$ sınama yapılır ve tekrar analize dönülür.
- Bir çevrimde yazılıma **yeni bir işlev/özellik ekleniyorsa** buna **artım (*increment*)** denir.
- Yeni bir işlev eklemeden mevcut tasarım veya kod **iyileştiriliyor / yeniden düzenleniyorsa (*refactoring*)** buna **yineleme (*iteration*)** denir.

Bu yaklaşımın temel hedefi, şelale modelinin disiplinli yapısıyla ön ürün modelinin erken geri bildirim gücünü birleştirmek ve ikisinin zayıf yönlerini geride bırakmaktır.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
