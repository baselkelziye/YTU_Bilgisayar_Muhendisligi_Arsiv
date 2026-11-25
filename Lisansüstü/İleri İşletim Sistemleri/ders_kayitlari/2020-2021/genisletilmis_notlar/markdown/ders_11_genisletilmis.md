# Ders 11 Genişletilmiş Notu: Makale Tartışması: IO-Lite, LOCUS ve ITC Dağıtık Dosya Sistemi (AFS)

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dersin Biçimi
- 2. IO-Lite: Birleşik G/Ç Tamponlama ve Önbellekleme
- 3. IO-Lite'ta Dosya Sistemi ve Ağ
- 4. Değiştirilemez Tamponların Bedeli
- 5. LOCUS Dağıtık İşletim Sistemi
- 6. LOCUS'un Bedeli ve Sonuç Bölümü
- 7. ITC Dağıtık Dosya Sistemi: Amaç ve Sınıflandırma
- 8. Dosya Sistemi Hedefleri ve Konum Şeffaflığı
- 9. Vice ve Virtue
- 10. Tasarım İlkeleri ve Yerel Dosyalar
- 11. Koruyuculuk (Custodianship) ve Güvenlik
- 12. Örnek Sorular

## 1. Dersin Biçimi

Bu ders, dönem boyunca sürdürülen klasik işletim sistemi makaleleri tartışmasının bir haftasıydı. Öğrenciler o haftanın makalelerini önceden okumuştu. Hoca her makale için sorular sordu, öğrencilerin el kaldırarak cevap vermesini istedi, cevapları değerlendirdi ve gerektiğinde makaleden ilgili cümleleri sesli okuyarak doğru cevabı kendisi açıkladı. Tartışma Türkçe ve İngilizce karışık yürüdü. Hoca, cevaplarda soruya yönelik konuşulmasını istedi.

Derste üç makale tartışıldı:

- "IO-Lite: A Unified I/O Buffering and Caching System"
- LOCUS dağıtık işletim sistemi makalesi (1983)
- "The ITC Distributed File System: Principles and Design" (1985; AFS olarak da bilinir)

Kayıt Zoom konuşmacı görünümündeydi; görüntüde ekran paylaşımı yoktu, yalnız konuşan kişinin adı görünüyordu. Bu yüzden notun tamamı altyazıdan hazırlandı. Makalelerden sesli okunan cümleler İngilizce olarak korunmuştur. Altyazıda yankı nedeniyle anlaşılmayan bazı öğrenci cevapları nota alınmadı.

Hoca derste öğrencilerin daha aktif olmasını istediğini birkaç kez söyledi: burada doğru ya da yanlış yoktur, bu bir fikir alışverişidir; yanlış söylenen bir şey düzeltilir, belki hocanın gözünden kaçan bir şey de öğrenciler tarafından yakalanır.

## 2. IO-Lite: Birleşik G/Ç Tamponlama ve Önbellekleme

### 2.1 Neden "Lite"?

Hoca ilk soruyu IO-Lite'ın adından sordu: bu sistem neden "hafif" (light) olarak anılıyor, hafifliği nereden geliyor? Bir öğrenci, sistemin tampon (buffer) ve önbellek (cache) tekrarından kaçındığını, böylece birden fazla kopyalama yapmadığını ve kendini hafif tuttuğunu söyledi. Hoca bunun doğru olduğunu ama tampon yapısıyla ilgili çok daha net, anahtar bir nokta olduğunu belirtti. Cevap gelmeyince ipucunu kendisi verdi: makale değiştirilemez tampon (immutable buffer) der.

> **Hocanın vurgusu:** IO-Lite'ın hafifliğinin çok temel bir sebebi vardır ve bu sebep tamponların yapısıyla ilgilidir: tamponlar değiştirilemezdir.

### 2.2 Değiştirilemez tampon ne demek?

Bir öğrenci "immutable" sözcüğünün değiştirilemez anlamına geldiğini ve tamponun salt okunur (read-only) olduğunu söyledi. Hoca bunu şöyle tamamladı: tamponun içeriği bir kez belirlendikten, yani ilk veri o tampona yüklendikten sonra bir daha değiştirilmez. Bir öğrenci tamponun konumunun da (location) değişmediğini okuduğunu ekledi; hoca bunu kabul etti.

Ardından hoca, içeriğin değiştirilemiyor olmasının hangi zorlukları ortadan kaldırdığını sordu. Bir öğrencinin makaleden aktardığı cevap şuydu:

"Immutable buffers can solve problems like synchronization, protection, consistency, and fault isolation among OS subsystems and applications."

Hoca bu cevabı doğru kabul etti. Yani tampon salt okunur olunca onu paylaşan işletim sistemi alt sistemlerinin ve uygulamaların eşzamanlı değişikliklere karşı senkronize olması, birbirinden korunması, tutarlılık için uğraşması ve birinin hatasının diğerini bozmasından (hata yalıtımı) çekinmesi gerekmez.

> **Ek bilgi (derste anlatılmadı):** IO-Lite, büyük olasılıkla Pai, Druschel ve Zwaenepoel'in 1999-2000 yıllarında yayımlanan çalışmasıdır. Sistemde veriler değiştirilemez tamponlarda tutulur ve bu tamponlara işaret eden "buffer aggregate" adlı yapılar alt sistemler arasında değer olarak aktarılır; böylece aynı fiziksel veri kopyalanmadan dosya önbelleği, ağ alt sistemi ve uygulama tarafından paylaşılır.

### 2.3 Unix tamponlamasının temel sorunları

Hoca soruyu İngilizce de sordu: Unix ve türevleri gibi işletim sistemleri bazı tamponlama mekanizmaları sağlar, ama makale bu mekanizmaların bazı temel sorunları olduğunu söyler; bu sorunlar nelerdir? Bir öğrencinin cevabı makaledeki üç sorunu verdi:

- Gereksiz veri kopyalama (redundant data copying): aynı verinin alt sistemler arasında defalarca kopyalanması.
- Çoklu tamponlama (multiple buffering): aynı verinin birden çok kez, ayrı ayrı tamponlarda tutulması.
- Alt sistemler arası optimizasyon eksikliği (lack of cross-subsystem optimization): farklı alt sistemlerin birlikte optimize edilememesi.

Hoca cevabı "süper" diye onayladı.

### 2.4 Çoklu tamponlamaya somut örnek

Hoca çoklu tamponlamanın neyin sonucunda oluştuğunu sordu ve somut bir örnek istedi. İlk cevap bellek kullanımının artması gibi genel bir sonuçtu; hoca sorunun yanlış anlaşıldığını, istenenin somut bir örnek olduğunu belirtti. Bir başka öğrenci şu örneği verdi: bir web sunucusunda bütün kullanıcıların ortak kullandığı bir veri tabanı uygulaması ya da dosyalar olabilir. Sunucuya istek geldiğinde her kullanıcı için ayrı tampon oluşturmak yerine veri tek bir tamponda tutulursa aynı verinin tekrar tekrar tamponlanması önlenir. Hoca bunu doğru cevap olarak kabul etti.

### 2.5 Erişim denetimi ve tahsis

Sonraki soru şuydu: IO-Lite erişim denetimi (access control) ve tahsis (allocation) için işletim sisteminde mevcut olan hangi model üzerinden, daha doğrusu hangi çözünürlük üzerinden gidiyor? Hoca bir tamponun yetkilendirme açısından hangi seviyede bir şeye atanabildiğini sorduğunu açıkladı. Cevap gelmeyince kendisi verdi: süreç (process) seviyesinde. Makalenin 2.3 numaralı "Access Control and Allocation" bölümünden okudu:

"IO-Lite ensures access control and protection at the granularity of processes."

Hoca "granularity" sözcüğünü çözünürlük, yani işin hassasiyeti diye açıkladı. Erişim hakkı tek tek nesneler ya da kullanıcılar düzeyinde değil, süreçler düzeyinde tanımlanır.

## 3. IO-Lite'ta Dosya Sistemi ve Ağ

### 3.1 Soru: neden iki ayrı başlık?

Hoca, yazarların bir yanda "IO-Lite and the File System", diğer yanda "IO-Lite and the Network" başlıklarını açtığını hatırlattı ve neden böyle ayırma ihtiyacı duyduklarını sordu. Bir öğrenci, ağ tarafında ağ sürücülerinin güncellenmesi gerektiğini, çünkü paketlere müdahale edilmesi gerektiğini, dosya sisteminde ise böyle bir değişiklik olmadığını anladığını söyledi.

Hoca soruyu yeniden çerçeveledi: IO-Lite'ın en önemli özelliği ekstra kopya oluşturmamaktır. Gelen veri, onu kim kullanacaksa doğrudan orada kullanılsın diye tek bir tampon üzerinden ilerler. Bu durumda ağ ile dosya sistemi arasındaki fark nedir?

### 3.2 Hocanın açıklaması

Dosya sisteminde nereden okunacağı ya da nereye yazılacağı, yapılan çağrı sırasında zaten bellidir. Ağda ise bir paket geldiğinde o paketin hangi uygulamaya ait olduğunu paketin içinden çözmek gerekir; örneğin TCP/IP'de port numarasına bakılarak.

Normal bir ağ sürücüsü şöyle çalışır:

- Gelen paketi ağ arayüzünün donanım tamponundan alır.
- İşletim sisteminde, çekirdekteki bir tampona yerleştirir ve orada inceler.
- İnceledikten sonra paketi ilgili uygulamanın kullanımına aktarır; muhtemelen orada bir tamponlama daha yapılır.

Sonuçta aynı veri için donanım tamponu, çekirdekte yazılımsal inceleme tamponu ve uygulamanın tamponu olmak üzere birden çok kopya oluşur. Buna bir önceki sorudaki erişim denetimi de eklenir: o uygulamanın bu ağ haberleşmesi ve buradan gelip gidecek veriler için yetkili olup olmadığı denetlenmelidir.

Bu yüzden ağ sürücüleri, hem erişim denetimini yapacak hem de gelen verinin bir ara tampona alınmasını, yani kopyalanmasını engelleyecek biçimde güncellenmelidir. Mümkünse veri, ağ arayüzünün donanım tamponundan çekildiği gibi ilgili uygulamaya aktarılmalıdır.

Hoca makaleden ilgili yeri okudu: sürücüler, hedef bilgisini "from the headers of incoming packets using a packet filter, an operation known as early demultiplexing" belirlemelidir. Yani gelen paketin başlığına paket filtresiyle bakılarak hangi uygulamaya gideceği erkenden belirlenir. Hoca bunun donanım seviyesinde yapılarak işin hızlandırılması anlamına geldiğini belirtti.

> **Hocanın vurgusu:** Dosya sistemiyle ağ arasındaki temel fark, verinin hedefinin dosya sisteminde çağrı anında bilinmesi, ağda ise ancak paket incelenince öğrenilmesidir. Kopyasız çalışmak için hedefin erken belirlenmesi gerekir.

## 4. Değiştirilemez Tamponların Bedeli

### 4.1 Soru: hiç sakıncası yok mu?

Hoca, değiştirilemez tampon kullanmanın hiçbir sakıncası olup olmadığını sordu. Bir öğrenci şu cevabı verdi: tampon değiştirilemez olduğu için bir değişiklik gerektiğinde tamponun başka bir yere kopyalanması gerekir; bu kopyalama ek bir maliyettir. Bir başka öğrenci aynı noktayı tekrarladı: senkronizasyon ve koruma sorunları ortadan kalkar ama başlangıç verisi değiştirilemediği için bu bedel ödenir.

### 4.2 Makalenin 2.8 bölümü: üç durum

Hoca makalenin 2.8 numaralı "Impact of Immutable I/O Buffers" bölümünü açtı ve okudu:

"Consider the impact of IO-Lite's immutable I/O buffers on program operation. If a program wishes to modify a data object stored in a buffer aggregate, it must store the new values in a newly allocated buffer. There are three cases to consider."

Üç durum şunlardır:

- Verinin her sözcüğü değişir ("every word in the data object is modified"). Verinin tamamı değiştiği için zaten yeni bir tampon kullanmak gerekir. Hoca bunun örneği olarak tamponun şifrelenmesini (encryption) ya da üzerinden bir sağlama toplamı (checksum) hesaplanıp verinin dönüştürülmesini verdi.
- Verinin yalnız bir alt kümesi değişir ("only a subset of the words in the object change values"). Değişmeyen kısım aynı tutulur, değişen kısımlar yeni tamponlara yazılıp bağlı liste ya da zincirleme (chaining) mantığıyla bir araya getirilir.
- Değişiklikler tek bir bölgede ya da verinin tamamında değil, verinin pek çok farklı yerine dağılmıştır. Hoca bunun günlük hayatta karşılaşılabilecek bir durum olduğunu söyledi.

Hoca bu üç durumun performansa ve çalışmaya etkisinin görülmesi ve çözülmesi gerektiğini, makalenin bunu incelediğini belirtti.

### 4.3 Performans değerlendirmesi

Hoca, makalenin devamında HTTP örneği üzerinden, istek miktarına göre ve geniş alan ağındaki (wide area) etkiye göre ayrıntılı ve güzel bir performans analizi bulunduğunu söyledi; derste bu analizin ayrıntısına girilmedi.

## 5. LOCUS Dağıtık İşletim Sistemi

### 5.1 LOCUS ne sağlar?

Hoca ikinci makaleye geçti: dosya sistemine giderken arada bir dağıtık işletim sistemi vardır. Bir öğrenci LOCUS'un, ağ üzerindeki birden çok işletim sisteminin topluca tek bir işletim sistemiymiş gibi çalışmasını sağladığını, aralarındaki bağlantıyı LOCUS'un kurduğunu söyledi.

### 5.2 Çoğaltma (replication)

LOCUS'un öne çıkan özelliği sorulunca bir öğrenci çoğaltmayı (replication) anlattı: dağıtık sistem küçük bir alana değil geniş bir ağa yayıldığı için makineler birbirinden uzaktır. Kopyaların tutulması hem erişilebilirlik açısından (biri bozulduğunda diğerinin hizmet vermesi) hem de performans açısından (en yakın kopyanın sunulabilmesi) avantaj sağlar.

Hoca bunun makalenin en çok yoğunlaştığı kısımlardan biri olduğunu onayladı ve iki isteği vurguladı:

- Çoğaltma esnek olmalıdır.
- Çoğaltma mümkünse hiç kullanıcı müdahalesi olmadan otomatik gerçekleşmelidir.

### 5.3 Çoğaltma birimi

Hoca çoğaltmanın hangi seviyede yapıldığını sordu: dosya sistemi bazında mı, dosya bazında mı, dizin bazında mı? Yani çoğaltma birimi (unit of replication) nedir? Bir öğrenci çoğaltmanın hem kullanıcı hem işletim sistemi açısından önemli olduğunun vurgulandığını, bir başkası çekirdek düzeyinde sistem çağrılarının da işin içinde olduğunu söyledi. Bir başka öğrenci otomatik çoğaltmanın dosya seviyesinde yapıldığını söyledi. Hoca cevabı şöyle verdi: çoğaltma temel olarak dosya seviyesindedir; tabii bunun için çekirdek tarafı da işin içindedir.

### 5.4 Çoğaltmada kritik ilke: işlemsel bütünlük

Hoca, çoğaltma yapılırken ön planda tutulan çok kritik bir şey olduğunu söyledi ve ne olduğunu sordu. Öğrencilerden gelen cevaplar şunlardı: her kopyanın güncel (up to date) olması gerekir; kopyalar arasında tutarlılık olmalıdır; kullanıcı seviyesinde şeffaflık. Hoca "tutarlılık ama hangi seviyede?" diye sordu ve cevabı verdi: işlem (transaction) seviyesinde, yani işlemsel bütünlük (transactional integrity).

### 5.5 İç içe işlemler (nested transactions)

Hoca makalenin iddialı olduğunu, iç içe işlemleri (nested transactions) de desteklediğini söyledi ve bundan ne anlaşıldığını sordu. Gelen cevaplar:

- Belirli bir sırayı izlemesi gereken işlemler (hoca bu cevabın doğaçlama olduğunu söyledi).
- İşlem denince akla tutarlılık gelir: işlemin bir kısmının gerçekleşip bir kısmının gerçekleşmemesi söz konusu olamaz.
- Birden fazla işlemi içeren bir işlem. Makale "a set of events together" ifadesini kullanır; birden fazla işlem sonucunda sistem tutarlı bir duruma getirilmelidir.

Hoca doğruya en yakın cevabın üçüncüsü olduğunu söyledi ve asıl noktayı açıkladı: sistem dağıtıktır, dosyanın birden fazla kopyası vardır ve bunlar otomatik çoğaltmayla tutarlı tutulmaya çalışılır. Ancak bunun üzerinde iç içe geçmiş operasyonlar biçiminde işlemler olabilir. İşlem sınırlarında (transaction boundary) çoğaltmayı yapmak ve tutarlılığı sürdürmek bir problemdir; makale bunu inceler.

**Soru:** Makalede commit konusu da var, değil mi? **Cevap:** Bir öğrenci, bilinen commit mekanizmasına benzer biçimde değişikliklerin biriktirilip gönderildiğini, commit edilmedikçe değişikliğin kopyalara da yansımadığını belirtti. Hoca bunun tutarlılığı sağlamak için olduğunu onayladı.

Bir öğrenci commit operasyonlarındaki loglar üzerinden kopyalar arasında fark olup olmadığının izlendiğini hatırladığını, ama bunun bu makalede mi geçtiğinden emin olmadığını söyledi. Hoca, haftalık makalelerin konularının birbirine yakın olduğunu ve tek bir konudan gitmemek için araya farklı makaleler yerleştirdiğini belirtti.

<!-- BELİRSİZ: Log üzerinden kopyalar arası farkın izlenmesi bilgisinin LOCUS makalesine ait olup olmadığı derste netleşmedi. -->

## 6. LOCUS'un Bedeli ve Sonuç Bölümü

### 6.1 Kod büyüklüğü

Bir öğrenci makalede dikkatini çeken bir noktayı aktardı: bütün makalelerde performansı artırmak birinci öncelik olarak geçer, ama burada performans kazanımının bir bedeli olduğu açıkça söylenir; iyi bir tasarımla zorluklar aşılabilir ama çok büyük bir kod tabanı ortaya çıkar. Öğrenci bunu önce "Unix'ten sonra üçüncü en uzun kod tabanı", sonra "Unix'in üç katı" diye yorumladı. Hoca bu yorumu düzeltmek için sonuç bölümünü okudu:

"Nothing is free. In order to avoid performance degradation when resources are local, the cost has been converted into additional code and substantial care in implementation architecture. LOCUS is approximately a third bigger than Unix and certainly more complex."

Hoca "a third bigger" ifadesini şöyle açıkladı: Unix 1 ise LOCUS yaklaşık 1,33'tür; üç katı değil, üçte bir daha büyüktür ve daha karmaşıktır. Hoca bir işletim sisteminin bu kadar büyümesinin dikkat edilmesi gereken bir şey olduğunu ekledi.

> **Hocanın vurgusu:** "Nothing is free": yerel kaynaklarda performans kaybını önlemenin bedeli ek kod ve uygulamada büyük özendir.

Sonuç bölümünde ayrıca, sistem tasarımının doğası gereği dinamik yeniden yapılandırma (dynamic reconfiguration) yapıldığı ve bunun sisteme göre değiştiği belirtilir: "Rebuilding lock tables and synchronizing processes running in separate environments are problems of inherent difficulty." Yani kilit tablolarını yeniden kurmak ve ayrı ortamlarda çalışan süreçleri senkronize etmek doğası gereği zor problemlerdir.

### 6.2 Donanım çeşitliliği

Bir öğrenci, ağın farklı donanımlardan oluşmasının büyük bir sorun olduğunu, dizinlerin en basit adlandırma yapılarının bile farklı olmasının en büyük problemlerden biri olduğunu hatırlattı. Hoca, bir tarafta PDP donanımları olduğunu ve sistem devreye alınmadan önce PDP-11'lerin devre dışı bırakılarak donanım açısından daha tek tip (uniform) bir yapıya geçildiğini söyledi.

### 6.3 Projenin ölçeği

Hoca makalede geçen tarihleri okudu: çalışma 1979'da başlar ve 1983 başında ("early 1983") biter; yani yaklaşık 3,5-4 yıl. Harcanan emek 50 adam-yıldır ("50 man-years"). Hoca bunu şöyle açıkladı: bir kişi olsa 50 yıl, 50 kişi olsa 1 yıl çalışacak demektir. Makalenin beş yazarı vardır; işin dört yılda bittiği düşünülürse 10-15 kişilik bir ekip olması gerekir. Bu, o dönem için çok ciddi bir araştırmadır.

Hesap (ara adım eklendi): $50 / 4 = 12{,}5$ kişi, $50 / 3{,}5 \approx 14{,}3$ kişi; yani hocanın 10-15 kişilik ekip tahmini bu hesapla uyumludur.

### 6.4 Makalenin son cümlesi ve bugün

Hoca makalenin son cümlelerini okudu:

"However, use of LOCUS indicates the enormous value of a highly transparent distributed operating system. Since file activity often is the dominant part of the operating system [...], it seems clear that the LOCUS architecture constructed on a distributed file system base is rather attractive."

Hoca bir karşılaştırma yaptı: o dönem bu kadar uğraşılarak dosya sistemi dağıtık hale getirilmeye çalışılmış, bugün ise arka planda dosya sistemini çoğunlukla merkezi bir noktaya taşıyoruz.

> **Ders sonrası not:** Altyazıda bu sözcük "world" diye geçiyor ve Whisper bozması olabilir; makaledeki ifade büyük olasılıkla "load" ya da benzeridir. Cümlenin anlamı (dosya etkinliğinin işletim sistemi işinin baskın kısmı olduğu) değişmez.

## 7. ITC Dağıtık Dosya Sistemi: Amaç ve Sınıflandırma

### 7.1 Tarih ve bağlam

Üçüncü makale ITC dağıtık dosya sistemidir; AFS olarak da anılır. Hoca tarihlere dikkat çekti: LOCUS 1983, bu makale 1985 tarihlidir. Ders 2021'de yapıldığına göre bundan 36 yıl önce dağıtık dosya sistemleri, performansları, çoğaltma ve işlemsel loglama üzerine yoğun biçimde çalışılıyordu (hoca önce 26 dedi, bir öğrencinin uyarısıyla 36 olarak düzeltti: $2021 - 1985 = 36$).

### 7.2 Neden dağıtık dosya sistemi?

Bir öğrenci sistemin Carnegie Mellon Üniversitesi için tasarlandığını, üniversitede çok sayıda kullanıcı olduğunu, sistemin esnek olması ve kullanıcı hareketliliğini desteklemesi gerektiğini söyledi.

### 7.3 Üç kategori

Hoca, yazarların dağıtık sistemleri şeffaflık (transparency), karmaşıklık (complexity) ve iletişim (communication) gereksinimleri üzerinden, daha şeffaf ve daha karmaşık olandan daha az şeffaf ve daha az karmaşık olana doğru sıraladığını hatırlattı ve kaç kategori çıktığını sordu. Bir öğrenci üç kategori saydı:

- Dağıtık işletim sistemleri (distributed operating systems): işletim sisteminin kendisi dağıtıktır.
- Dağıtık dosya sistemleri (distributed file systems): LOCUS'ta olduğu gibi dosya sistemi dağıtıktır.
- Gevşek bağlı ağlar (loosely coupled networks): örnek olarak ARPANET, yani bugünkü internetin öncüsü verilir.

### 7.4 Gevşek bağlı ağ neden tercih edilmedi?

Bir öğrenci bunun güvenlik nedeniyle olabileceğini söyledi; hoca bunun üzerine "neden tercih etmiyorlar?" sorusunu açtı. Bir başka öğrenci, ARPANET'te kullanıcının bir işlem yapabilmesi için bütün adımları kendisinin yapması ve karşı hedefi bilmesi gerektiğini, uzak dosya sisteminin kullanıcının sisteminin bir parçası gibi davranmadığını söyledi.

Hoca bunu FTP örneğiyle açtı: eskiden bir dosyayı yerele almak için FTP (File Transfer Protocol) kullanılırdı. Burada şeffaflık yoktur; üzerinde çalışılacak dosyanın yerel kopyasını kullanıcının kendisi oluşturur ve kararları kendisi verir. Yapılan değişikliklerin diğer kopyalara nasıl yansıyacağı, kopyaların nasıl güncelleneceği hiç düşünülmez. Aynı dosyanın ağda binlerce, on binlerce birbirinden bağımsız kopyası olabilir. Çok sayıda kullanıcı ve bilgisayar bulunan bir üniversitede bu sorumluluğu kullanıcılara bırakmak tam bir kaosa yol açar; bu yüzden anlamlı değildir.

## 8. Dosya Sistemi Hedefleri ve Konum Şeffaflığı

### 8.1 Hedefler

Hoca dosya sistemi açısından hedeflerin ne olarak konduğunu sordu ve cevabın makalede doğrudan yazdığını söyledi. Öğrencilerin saydığı hedefler şunlardır: konum şeffaflığı (location transparency), kullanıcı hareketliliği (user mobility), erişilebilirlik, bütünlük ve heterojenlik.

> **Ek bilgi (derste anlatılmadı):** ITC makalesinde dosya sistemi hedefleri büyük olasılıkla konum şeffaflığı, kullanıcı hareketliliği, güvenlik, performans, ölçeklenebilirlik, erişilebilirlik, bütünlük ve heterojenlik başlıklarını içerir; derste bunların bir kısmı sayıldı.

### 8.2 Konum şeffaflığı

Hoca konum şeffaflığından ne anlaşıldığını tek cümleyle sordu. Gelen cevaplar:

- Paylaşılan bütün dosyalar tek bir ad alanına dahil olmalı, herkes o ad alanından erişebilmelidir.
- Dosyanın adından, dosyanın hangi bilgisayarda kayıtlı olduğu anlaşılmamalıdır; ad konum bilgisi içermemelidir.

Hoca şunu ekledi: aynı zamanda kullanıcı müdahil olmadan dosyanın konumunu sistemin bulabilmesi gerekir. Bugün internette bu anlamda bir konum şeffaflığı yoktur, çünkü URL'nin içinde konum bilgisi vardır. Makalenin hedefi ise kullanıcının yalnız dosyanın adını vermesi, arka tarafta sistemin dosya hangi bilgisayardaysa ona erişebilmesidir. Konumu çözen kullanıcı değil, dosya sistemidir.

**Soru:** DNS de bir tür şeffaflık sağlamıyor mu? Sonuçta arka planda adresi o biliyor. **Cevap:** Şeffaflık yalnız IP adresini almakla ilgili değildir. Bir kaynağı tek bir bilgisayara, tek bir konuma sabitlerseniz o hep oradadır; oysa ağda size daha yakın bir kopyası olabilir. Hoca örnek olarak büyük bir video sitesini verdi: DNS adı aynıdır, ama arka planda coğrafi konumlandırma yapılarak kullanıcı bulunduğu bölgeye en yakın sunucuya yönlendirilir. Bu, merkezi bir yapı üzerinden merkezi olmayan bir yapı kurmaktır. Hoca bunun 1985'te düşünülmüş olmasının dikkat çekici olduğunu vurguladı.

Bir öğrenci, şeffaflığın varlığını fark etmiyor olmamızın aslında onun çok iyi sağlandığını gösterdiğini söyledi: bir siteye bağlanırken arkadaki sunucunun hangi şehirde olduğunu bilmeyiz, istemci açısından bilmemek en iyisidir. Hoca makalede de konumun kullanıcı tarafından değil dosya sistemi tarafından çözüldüğünün yazdığını belirtti.

### 8.3 Heterojenlik

Heterojenlik sorulunca bir öğrenci, istasyonların dağıtık dosya sistemi aracılığıyla dosyalarını paylaşıma katabilmesini söyledi; bir başkası farklı yapılandırmalara ve farklı işlemcilere sahip bilgisayarların aynı sistemde çalışabilmesi gerektiğini ekledi. Hoca bunu farklı istasyonların aynı sisteme dahil olabilmesi diye özetledi.

## 9. Vice ve Virtue

### 9.1 Tanımlar

Hoca makalede geçen Vice ve Virtue kavramlarını sordu. Bir öğrenci Vice'ın sunucu, Virtue'nun istemci tarafı olduğunu söyledi. Bir başka öğrenci daha ayrıntılı anlattı: Vice dosyaların tutulduğu merkezi sisteme benzer bir yapıdır ve içinde hiçbir kullanıcı süreci çalıştırılmaz, bu yüzden daha güvenlidir. Virtue ise kullanıcı tarafındaki karşılığıdır; Vice'a bağlı Virtue'lar vardır ve aradaki arayüz sayesinde bu Virtue'lara bağlı istasyonlar dosyaları kendi parçalarıymış gibi görür.

### 9.2 Güvenilirlik sınırı

Hoca makalenin Şekil 2.1'ine yönlendirdi: ortada içinde Vice yazan bir bulut çizilmiştir ve üstte "Vice is the boundary of trustworthiness" denir. Hoca bunu şöyle açıkladı: uç kullanıcı dağıtık ağa kendi iş istasyonuyla katılır ve ağın sunduğu kaynaklardan yararlanır. Bu iş istasyonu üzerindeki bütün denetim kullanıcıdadır; iyi niyetli de olabilir kötü niyetli de. Ancak herkes bir bütün olarak çalışacağına göre, güvenlik ve karşılıklı güven ilişkisi kurulması için ortada bir omurgaya (backbone), bir ana yapıya ihtiyaç vardır. Bu yapı Vice'tır.

Hoca Vice adının açılımını sordu. Bir öğrenci açılımı "Vast Integrated Computing Environment" olarak verdi; makalede de "It is rumored that Vice stands for Vast Integrated Computing Environment" yazar. Hoca sözcüğün günlük anlamına da dikkat çekti: polislerde "vice" birimi Türkiye'deki ahlak masasına denk düşer. Güvenilirlik sınırı için güzel bir kısaltma seçilmiştir; uç noktalara güvenemezsin.

> **Ders sonrası not:** Hoca "vice" sözcüğünün "ahlak" anlamına geldiğini söyledi; İngilizcede "vice" daha çok ahlaki kusur, kötü alışkanlık anlamındadır ve "virtue" (erdem) sözcüğünün karşıtıdır. "Vice squad" ise ahlak masasına karşılık gelir. Vice ve Virtue adları büyük olasılıkla bu karşıtlıktan seçilmiştir.

### 9.3 Eşler arası mı?

**Soru:** Bu yapı eşler arası (peer-to-peer) bir yaklaşım olarak görülebilir mi? Herkes ortak bir ortamda çalışıyor ve hepsi o ortama katkıda bulunuyor. **Cevap:** Yapı dağıtıktır; dahil olan herkesin her kaynağı bu yapının bir parçası olabilir. Yalnız eşler arası düzeyde düşünmek çok kısıtlayıcı olur. Bir'e N gibi de değil, çoktan çoğa (M'ye N) demek daha doğrudur; bu, özel durum olarak bire biri ve bire N'yi de içerir.

### 9.4 Topoloji

Hoca makaledeki şekli anlattı: iş istasyonları kümeler oluşturur ve her kümenin bir küme sunucusu (cluster server) vardır. Küme sunucuları bir araya geldiğinde Vice yapısı oluşur. Hoca bunu bir fakülte örneğiyle somutlaştırdı: fakültede bilgisayar, elektronik, elektrik, kontrol ve otomasyon bölümleri vardır; her birinin kendi iş istasyonları ve küme sunucusu vardır. Bir yandan yerelleşmiş görünürler; öte yandan o dönem için bir omurga Ethernet vardır (internetten söz edilmiyor) ve kümeler köprülerle (bridge) bu omurgaya bağlıdır. Küme sunucuları bir araya gelince daha büyük Vice yapısı oluşur ve kendilerine bağlı iş istasyonlarıyla diğer kümeler arasındaki güvenlik sınırını, güvenilirlik sınırını (boundary of trustworthiness) oluştururlar.

Bir öğrencinin cevabına göre makale başlangıçta 5000 kişisel iş istasyonundan söz eder. Hoca, 1985'te bir üniversite ortamında 5000 iş istasyonunun çok ciddi bir rakam olduğuna dikkat çekti. Makalede aradaki trafiğin açık metin (clear text) olarak değil şifrelenerek gönderilmesinden ve iş istasyonlarının yerel diskleri yerine uzak disk üzerinden çalışmasının mümkün olup olmadığından da söz edilir.

## 10. Tasarım İlkeleri ve Yerel Dosyalar

### 10.1 Tasarım ilkeleri

Hoca, dosyalara konumdan bağımsız erişileceğine göre nasıl bir adlandırma ve tasarım yapısı getirildiğini sordu. Bir öğrenci makaledeki tasarım ilkelerini aktardı:

- İşi iş istasyonunda yap: bir işlemi iş istasyonunda yapmakla merkezi bir kaynakta yapmak arasında seçim varsa ilki tercih edilir.
- Mümkünse yerelleştir: uzak bir kaynak yerine mümkünse daha yakın olan kullanılır.
- Sınıfa özgü dosya özelliklerinden yararlan: örneğin salt okunur bir dosya kopyalanabilir, üzerine yazılmaz.
- Mümkünse önbelleğe al: Virtue dosyaları ve bunlarla ilgili durum bilgisini önbelleğe alabilir.
- Sık ve büyük değişiklikten kaçın: güncellemeyi parça parça sürekli değil, toplu yap.

<!-- BELİRSİZ: Son ilkenin makaledeki tam ifadesi altyazıdan çıkmıyor; öğrenci "büyük değişiklik yapmaktan kaçının" diye aktardı. Makalede büyük olasılıkla "sık ve sistem çapında hızlı değişiklikten kaçın" anlamında bir ifade vardır. -->

### 10.2 Yerelde kalabilecek dosyalar

Hoca adlandırma ve konum konusunda makalede bir sınıflandırma olduğunu söyledi. Bir öğrenci makalede numaralı bir liste görüp bunu önceliklendirme sandı; hoca bunun bir önceliklendirme olmadığını, yerelde tutulması anlamlı olan dosya türlerinin listesi olduğunu açıkladı:

- Sistem dosyaları: iş istasyonunun açılması ve Vice'a bağlanmadan önce çalışması için gereken dosyaların yerelde olması mantıklıdır. (Bunlara bir disk sunucusu üzerinden de erişilebilir; o ayrı bir konudur.)
- Geçici dosyalar: örneğin derleyici derleme sırasında ara nesne dosyaları oluşturur, sonra siler. Bunları herkesin paylaştığı bir ad alanına koymanın anlamı yoktur, kimsenin onlara ihtiyacı olmaz.
- Özel dosyalar: kullanıcı bazı dosyaları, güvenlik mekanizmasından bağımsız olarak hiç paylaşıma açmak istemeyebilir; bunlar tamamen yerelde kalır. Bu dosyalar kullanıcı hareketliliğini ortadan kaldırır: X iş istasyonundaki özel dosyalarım başka yere taşınmazsa gidip Y iş istasyonunda çalışamam.
- İş istasyonunda kullanılan programlar: derleyici, editör gibi çok sık kullanılan ama az güncellenen programların paylaşılan ad alanına konmasına gerek yoktur, yerelde olabilirler.

### 10.3 Şekil 3.1 ve 3.2

Hoca makalenin Şekil 3.1'inde bu ayrımın bir Venn diyagramıyla gösterildiğini söyledi. Şekil 3.2'de ise Vice'ın aslında bir bağlama noktası (mount point) olduğu görülür; sonuçta Vice da bir dosya sistemidir ve Unix'te her dosya sistemi bir noktaya bağlanır. Bu noktanın altında mimariye göre ayrım yapılmıştır: Sun mimarisi ve VAX mimarisi için ayrı ikili dosya dizinleri vardır (hocanın aktardığı biçimiyle Vice altında unix/sun/bin ve unix/vax/bin). Her iki mimari de Unix çalıştırır ama ikili dosyaları farklıdır; böylece aynı programın farklı mimarilere göre kopyaları bulunabilir.

<!-- BELİRSİZ: Şekil 3.2'deki dizin yolunun tam yazımı ekranda gösterilmedi; yalnız hocanın sesli okumasından aktarıldı. -->

## 11. Koruyuculuk (Custodianship) ve Güvenlik

### 11.1 Koruyuculuk

Hoca makaledeki "custodianship" kavramını sordu ve sözcüğün anlamını verdi: custodian, bir şeye göz kulak olan, vasi gibi ondan sorumlu olan demektir. Cevap gelmeyince kendisi açıkladı: bir dosyanın koruyucusu, o dosyanın nerede saklandığından, nasıl çoğaltıldığından ve erişimin nasıl koordine edildiğinden sorumlu sunucudur. Makaleden okudu:

"If a server receives a request for a file for which it is not the custodian, it will respond with the identity of the appropriate custodian."

Hoca bunu dizin yapısıyla ilişkilendirdi: dizin, alt dizin, alt dizin diye ilerleyen bir ağaçta her alt dizin bir daldır. O alt dizinin altındaki bütün dosyaların koruyucusu aynıysa her dosya için ayrı koruyucu bilgisi tutmaya gerek yoktur; bilginin yalnız alt dizin için verilmesi yeter.

### 11.2 Güvenlik ihlali sınıflandırması

Hoca, dağıtık bir yapıdan söz ediliyorsa güvenlikten de söz etmek gerektiğini, LOCUS konuşulurken de erişim denetim listelerinden (access control list) bahsedildiğini hatırlattı ve makalenin güvenlik ihlallerini nasıl sınıflandırdığını sordu. Cevap gelmeyince makaleden okudu:

"Voydock and Kent classify breaches of security in a network as the unauthorized release of information, modification of information or denial of resource usage."

Yani ağdaki güvenlik ihlalleri üç sınıftır:

- Bilginin yetkisiz açığa çıkması (unauthorized release of information)
- Bilginin yetkisiz değiştirilmesi (modification of information)
- Kaynak kullanımının engellenmesi (denial of resource usage)

> **Hocanın vurgusu:** Bugünkü hizmet reddi (denial of service) kavramının 1985'teki adı "denial of resource usage"dır. Kavramlar o dönemde şekillenmeye başlamıştır ve sınıflandırma bugün de çok farklı değildir.

## 12. Örnek Sorular

Aşağıdaki sorular derste hoca tarafından sözlü olarak soruldu. Ekranda soru gösterilmedi.

**Soru 1** (derste sözlü, 00:02:53): IO-Lite neden "light" olarak anılır? Hafifliği nereden gelir?

> **Cevap (derste verildi):** Tampon yapısından: IO-Lite değiştirilemez (immutable) tamponlar kullanır. Veri tek bir tamponda, kopyalanmadan, onu kullanacak yere verilir; böylece tampon ve önbellek tekrarı ve çoklu kopyalama önlenir.

**Soru 2** (derste sözlü, 00:05:05): İçeriğin değiştirilemiyor olması hangi problemlerle uğraşmayı ortadan kaldırır?

> **Cevap (derste verildi):** İşletim sistemi alt sistemleri ve uygulamalar arasındaki senkronizasyon, koruma, tutarlılık ve hata yalıtımı sorunlarını.

**Soru 3** (derste sözlü, 00:07:19): Makaleye göre Unix ve türevlerindeki tamponlama mekanizmalarının temel sorunları nelerdir?

> **Cevap (derste verildi):** Gereksiz veri kopyalama, çoklu tamponlama ve alt sistemler arası optimizasyon eksikliği.

**Soru 4** (derste sözlü, 00:09:38): IO-Lite erişim denetimi ve tahsis için hangi çözünürlüğü kullanır?

> **Cevap (derste verildi):** Süreç çözünürlüğünü: "IO-Lite ensures access control and protection at the granularity of processes."

**Soru 5** (derste sözlü, 00:12:11): Yazarlar neden "IO-Lite and the File System" ve "IO-Lite and the Network" diye iki ayrı başlık açmıştır?

> **Cevap (derste verildi):** Dosya sisteminde okunacak ya da yazılacak yer çağrı sırasında bellidir; ağda ise paketin hangi uygulamaya ait olduğu paket başlığına bakılarak çözülmelidir. Normal sürücüler donanım, çekirdek ve uygulama tamponlarında birden çok kopya oluşturur. Kopyasız çalışmak için sürücüler, erişim denetimini yapacak ve hedefi paket filtresiyle erkenden belirleyecek (early demultiplexing) biçimde güncellenmelidir.

**Soru 6** (derste sözlü, 00:19:53): Değiştirilemez tampon kullanmanın hiç sakıncası yok mu?

> **Cevap (derste verildi):** Var: bir veriyi değiştirmek isteyen program yeni değeri yeni ayrılmış bir tampona yazmak zorundadır; bu ek kopyalama maliyeti getirir. Makale üç durumu inceler: verinin tamamı değişir, bir alt kümesi değişir, değişiklikler pek çok yere dağılmıştır.

**Soru 7** (derste sözlü, 00:36:12): LOCUS çoğaltmayı hangi birimde yapar ve çoğaltmada ön planda tutulan kritik ilke nedir?

> **Cevap (derste verildi):** Çoğaltma temel olarak dosya seviyesindedir (çekirdek desteğiyle). Ön planda tutulan ilke işlemsel bütünlüktür (transactional integrity).

**Soru 8** (derste sözlü, 00:41:05): LOCUS'ta iç içe işlemler (nested transactions) ile ne kastedilir?

> **Cevap (derste verildi):** Birden fazla işlemi içeren, iç içe geçmiş operasyonlar. Dosyanın birden çok kopyası otomatik olarak tutarlı tutulurken işlem sınırlarında çoğaltmayı yapıp tutarlılığı korumak makalenin incelediği problemdir.

**Soru 9** (derste sözlü, 01:16:12): ITC makalesi dağıtık sistemleri şeffaflık, karmaşıklık ve iletişim açısından sıraladığında kaç kategori çıkar? Gevşek bağlı ağlara örnek nedir ve bu yaklaşım neden tercih edilmemiştir?

> **Cevap (derste verildi):** Üç kategori: dağıtık işletim sistemleri, dağıtık dosya sistemleri, gevşek bağlı ağlar. Gevşek bağlı ağ örneği ARPANET'tir. Orada şeffaflık yoktur; kullanıcı dosyanın yerel kopyasını kendisi oluşturur ve kopyalar birbirinden bağımsızdır. Çok kullanıcılı bir üniversitede bu sorumluluğu kullanıcılara bırakmak kaos yaratır.

**Soru 10** (derste sözlü, 01:20:01): Konum şeffaflığından ne anlıyoruz?

> **Cevap (derste verildi):** Dosyanın adı konum bilgisi içermez; kullanıcı yalnız adı verir ve dosyanın hangi makinede olduğunu kullanıcı değil dosya sistemi çözer. Bugünkü URL'ler konum bilgisi içerdiği için bu anlamda konum şeffaflığı sağlamaz.

**Soru 11** (derste sözlü, 01:24:31): Makaledeki Vice ve Virtue nedir? Vice neden "boundary of trustworthiness" olarak anılır?

> **Cevap (derste verildi):** Vice, küme sunucularının birleşmesiyle oluşan ve içinde kullanıcı süreci çalıştırılmayan sunucu tarafıdır; Virtue iş istasyonu tarafıdır. İş istasyonları üzerindeki denetim kullanıcıda olduğu için onlara güvenilmez; ortak güven ilişkisi Vice üzerinden kurulur.

**Soru 12** (derste sözlü, 01:39:39): "Custodianship" teriminden ne anlıyoruz?

> **Cevap (derste verildi):** Bir dosyanın nerede saklandığından, nasıl çoğaltıldığından ve erişimin nasıl koordine edildiğinden sorumlu sunucu o dosyanın koruyucusudur. Koruyucusu olmadığı bir dosya için istek alan sunucu uygun koruyucunun kimliğini döndürür; aynı koruyucuya sahip bir alt ağaç için bilgi yalnız alt dizin düzeyinde tutulur.

**Soru 13** (derste sözlü, 01:43:36): Makale ağdaki güvenlik ihlallerini nasıl sınıflandırır?

> **Cevap (derste verildi):** Voydock ve Kent'e dayanarak üç sınıf: bilginin yetkisiz açığa çıkması, bilginin yetkisiz değiştirilmesi ve kaynak kullanımının engellenmesi (bugünkü hizmet reddinin karşılığı).

## Dersin Toparlaması

Bu derste üç makale üzerinden G/Ç ve dağıtık dosya sistemleri tartışıldı. IO-Lite, değiştirilemez tamponlarla verinin alt sistemler arasında kopyalanmadan paylaşılmasını sağlar; bu, senkronizasyon ve koruma sorunlarını ortadan kaldırırken değişiklik gerektiğinde yeni tampon ayırma bedelini getirir. Ağ tarafında kopyasız çalışmak, paketin hedefinin erken belirlenmesini gerektirir. LOCUS, ağdaki makineleri tek bir şeffaf işletim sistemi gibi gösterir; otomatik, dosya düzeyinde ve işlemsel bütünlüğü koruyan çoğaltma sunar, ama bunun bedeli Unix'ten yaklaşık üçte bir büyük ve daha karmaşık bir sistemdir. ITC dağıtık dosya sistemi ise binlerce iş istasyonlu bir üniversite ortamı için konum şeffaflığı ve kullanıcı hareketliliğini hedefler; güvenilirlik sınırı olarak Vice'ı, iş istasyonu tarafı olarak Virtue'yu tanımlar, yerel ve paylaşılan dosyaları ayırır ve koruyuculuk kavramıyla dosyaların sorumluluğunu sunuculara dağıtır.

Hoca, bu makalelerdeki fikirlerin (en yakın kopyaya yönlendirme, hizmet reddi gibi) bugünkü sistemlerde hâlâ karşılık bulduğunu vurguladı. Haftanın dördüncü makalesi olan Windows NT dosya sistemi izleri (NT file traces) makalesi derste tartışılmadı.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
