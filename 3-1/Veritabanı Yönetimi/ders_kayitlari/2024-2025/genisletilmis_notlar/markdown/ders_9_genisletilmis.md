# Ders 9 Genişletilmiş Notu: NoSQL Veritabanları (CAP, Doküman ve Anahtar-Değer Depoları) ve İndekslemeye Giriş

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. NoSQL: Neden "Store"?
- 2. Not Only SQL ve Join Problemi
- 3. Dağıtık Veritabanı Kavramları
- 4. Yarı Yapısal Veri ve Esnek Şema
- 5. Yüksek Performans, Erişilebilirlik ve Çoğaltma
- 6. NoSQL Kategorileri ve Örnek Sistemler
- 7. Çoğaltma, Nihai Tutarlılık ve Sharding
- 8. CAP Teoremi
- 9. Doküman Depoları: MongoDB
- 10. Anahtar-Değer Depoları ve Tutarlı Karma
- 11. Sütun Tabanlı ve Çizge Depoları
- 12. İndekslemeye Giriş
- 13. Kümelenmiş ve İkincil İndeksler
- 14. İndeks Ne Zaman Kullanılır, Neden Her Yere Konmaz?
- Örnek Sorular

## 1. NoSQL: Neden "Store"?

Hoca bu derste NoSQL veritabanlarına devam edileceğini ve indekslemeye giriş yapılacağını söyledi. NoSQL veritabanı deyince ilk söylenmesi gereken, bunların büyük veri sistemleri için saklama ortamları olduğudur. Konu ilk olarak dağıtık veritabanı (distributed database) konusudur.

Hocanın dikkat çektiği ilk nokta, bu sistemlerin adlarında çoğu zaman "database" kelimesinin geçmemesidir: Key-value store, columnar store, document store.

**Soru:** Neden "database" yerine "store" deniyor? **Cevap:** Çünkü geleneksel veritabanının karmaşık kavramlarının biraz dışına çıkılıyor ya da bu kavramlar gevşetiliyor.

**Soru:** İlişkisel sistemleri zorlayan, büyük veriyi kaldıramamalarına yol açan nedir? **Cevap:** Hocanın açıklaması: Büyük veri terabayt, petabayt ve ötesidir; bir odaya, hatta bir binaya sığmaz. Dünyada hemen herkesin kullandığı servislerin verisi veri merkezlerinde, adeta bir "veri fabrikasında" toplanır. Bu veriyi PostgreSQL, Oracle ya da MS SQL Server gibi tek bir makinede ya da birkaç makinede çalışan bir sistemde tutmak akla sığmaz. Bu sistemler çok karmaşıktır: Eş zamanlılık, tutarlılık (consistency), kurtarma (recovery) gibi her şeyi mükemmel yapmaya çalışırlar. Hoca bunu işletim sistemlerine benzetti: Çok sayıda süreç, kaynakların ortak kullanımı ve kurtarma ile işletim sistemi de karmaşık bir sistemdir ve kullanıcı sayısı arttıkça karmaşıklık artar. Veritabanı sisteminin verdiği güvenceler (herkesin işinin görülmesi, gerçek zamanlılık, veri kaybı olmaması; yani hem yüksek performans hem veri bütünlüğü) bu ölçekte sağlanamaz.

Bu yüzden bu sistemler "database system" değil "data storage system"dir: Karmaşık SQL sistemlerinin gevşetilmiş hâlleridir. Başka türlü bu kadar veriyle başa çıkmak, onu düzenli saklamak ve sorgulamak mümkün değildir.

Hoca anlatımda yine aynı kitabın (Elmasri ve Navathe) NoSQL bölümünü kullandığını söyledi. Kitap güncellenen bir kitaptır; sunular 2016 tarihlidir. Teknoloji hızlı değişse de kategorizasyon yerine oturmuştur; güncel durumu merak edenler ayrıca araştırmalıdır.

## 2. Not Only SQL ve Join Problemi

NoSQL "Not only SQL" demektir: Bu sistemler saf SQL sistemleri değildir, ama SQL'den tamamen uzak da değildir. Hoca ilginç bir gidişata dikkat çekti: 2010'larda SQL'den kaçarak yola çıkan birçok sistem sonradan SQL'in basit biçimlerini benimsedi. Sebebi SQL'in çok çekici, bildirimsel (declarative) bir dil olmasıdır; hoca bunu az kodla çok iş yapılan Python'a benzetti. Ama iç içe sorgular, ilişkili (correlated) sorgular ve join'ler büyük veri üzerinde pek yapılmaz. Temel işlemler `get` ve `put`'tur: Bir anahtar üzerinden arama yapılır ve o anahtardaki değer, arkada indeksler kullanılarak hızla çekilir.

**Soru:** Büyük veri sistemlerinde hiç join yapılmıyor mu, bu kadar veri üzerinde join nasıl yapılır? **Cevap:** Veritabanı "ben yalnız `put` ve `get` yapabilirim, join'i ben yapmam" der; join gerekiyorsa uygulama yapar. Join'in yaptığı iş, farklı veri setlerinin eşleşen satırlarını yakalamaktır. Veri normalizasyon ve bütünlük sebepleriyle dağıtılmıştır; aranan verinin tek bir yerde olmaması çok normaldir. Uygulama bunu, veritabanı sistemlerinin içindeki karmaşık join algoritmalarıyla değil, veriyi parçalara ayırıp paralel algoritmalarla yapar. Hoca bunun büyük veri dersinde anlatıldığını söyledi.
<!-- BELİRSİZ: Altyazıda "Bunları map ediyor ... Prodius gibi paralel algoritmalarla" geçiyor (00:11:30-00:11:38); büyük olasılıkla MapReduce kastediliyor. -->

Hoca dağıtık veritabanının merkezî veritabanına göre çok daha karmaşık olduğunu, bu konuyu önceki yıllarda pek anlatmadığını söyledi. Amaç bir büyük veri platformunda veritabanı uygulaması geliştirmek değildir; o ayrı bir dersin konusudur. Amaç terminolojiyi ve motivasyonu bilmek, dört kategoride hangi meşhur sistemlerin bulunduğunu öğrenmektir.

## 3. Dağıtık Veritabanı Kavramları

Slayta göre NoSQL veritabanları çoğunlukla dağıtık veritabanları ya da dağıtık depolama sistemleridir.

**Soru:** "Dağıtık veritabanı" deyince terminolojik olarak ilk akla ne gelmeli? **Cevap:** Küme (cluster). Kümede birden çok makine vardır ve bunlar sıradan (commodity) makinelerdir.

Commodity, piyasada satılan sıradan makine demektir; süper bilgisayar değildir. Eskiden süper bilgisayarlar çok meşhurdu, ama hiçbir süper bilgisayar büyük veriyi tek başına kaldıramaz. Buradaki anahtar kelime yatay ölçeklemedir (horizontal scalability): Kümede 100 makine varsa ihtiyaca göre 10 makine daha eklenir, ihtiyaç kalmazsa 10 makine çıkarılır. Sistem bu mekanizma üzerine kurgulanmıştır; hiçbir makine süper bilgisayar değildir. Ölçeklenebilirlik (scalability) kelimesinin içinde bu vardır: Günümüzde veri patlamalı ve çok hızlı arttığı için kapasite ihtiyaca göre artırılır.

## 4. Yarı Yapısal Veri ve Esnek Şema

Dağıtık depolama sistemlerinde saklanan veri yapısal (structured) değildir; bu da motivasyonlardan biridir. Üniversite veritabanında her şey düzenlidir: Öğrenciler, dersler, şubeler, bölümler vardır; tanımı kolaydır, gerçek hayat güzelce "kesilip biçilmiştir" ve ihtiyaç da budur. Ama sosyal medya platformlarında, büyük şirketlerin servislerinde, web uygulamalarında bir linke tıklamak bile veri üretir. Bu veri düzenli değildir; ne kadar uğraşılsa da çoğu zaman düzenli hâle gelmez.

Hocanın örneği bir alışveriş sitesidir: Cep telefonları ve tabletler satılır, bunların altında da birçok kategori vardır. Android telefonun özellikleri farklı, iPhone'unki farklıdır; tabletler de öyledir. Bu kadar çeşitlilikte tek bir tablo ve nitelik listesi kurmak kolay değildir. Uygulamaya göre şema belirlemek mümkün olmayabilir; ya tamamen yapısal olmayan (unstructured) ya da yarı yapısal (semi-structured) bir yapı gerekir.

Klasik SQL sisteminde şema bellidir; gelen kayıt şemaya uygunsa eklenir. Şema olunca sorgu iyileştirme çok daha kolaydır, çünkü neyin nerede olduğu bilinir; her şey bir parça deterministiktir. Yarı yapısal veride ise ortam esnektir: Şema yoktur ya da yarı şema vardır, tamamen uç bir noktaya da gidilmez. Bu boşluk açılınca her boşluğu dolduran çok sayıda sistem ortaya çıkmıştır; hocaya göre yüzlerce, binlerce veritabanı vardır.

## 5. Yüksek Performans, Erişilebilirlik ve Çoğaltma

Böyle bir sistemden yine yüksek performans beklenir: Hızlı dönüş alınmalıdır. Hoca bunun ancak sistemin gevşetilmesiyle, karmaşıklığın azaltılmasıyla mümkün olduğunu söyledi.

**Soru:** Erişilebilir (available) olmak ne demektir? **Cevap:** Sistemin her zaman "up and running" olması. Hoca ikisini ayırdı: Sistem ayakta (up) olup arka planda dağılmış şeyleri toparlamakla meşgul olduğu için hizmet vermiyor olabilir. Erişilebilirlik, arka planda düzenlemeler yapılsa da sistemin her zaman hizmet vermesidir. Kullanılan sosyal medya platformlarında "şu anda hizmet veremiyoruz" gibi mesajlar çok nadirdir.

Ama alınan hizmet her zaman aynı kalitede olmayabilir: Veri tam doğru, tam tutarlı olmayabilir. Burada banka hesabındaki para gibi değerli bilgiler saklanmaz. Paylaşılan bir görüntüyü ya da videoyu hemen ya da bir saniye sonra görmek çok hassas bir şey değildir. Tam tutarlılıktan ödün verilerek erişilebilirlik sağlanır.

Erişilebilirliği, yani doğru ya da yanlış bir veriye her zaman erişebilmeyi sağlayan şey çoğaltmadır (replication). Veri kümedeki birçok düğüme dağıtılıp çoğaltılır; bir düğüm çökerse veri başka düğümden alınır. Bunun koordinasyonunu dağıtık veritabanı yapar. Ölçeklenebilirlik de kullanıcı sayısının yüzlerden milyonlara çıkabilmesidir. Bu özelliklerin farklı derecelerde sağlanması çok sayıda farklı sistem doğurmuştur: Biri bir noktada, öteki başka noktada daha iyidir.

Tipik uygulamalar: Sosyal medya verisi (metin, medya), web bağlantıları, kullanıcı profilleri (profile göre reklam ve teklif gelir), alışveriş siteleri (rağbet gören ürünlerin tahminine göre stok tedariki), tweet'ler, gönderiler ve ulaşım hareketleri (en çok gidilen yerler gibi). Hoca bu sistemlerin piyasaya ve ekonomiye çok dokunduğu, herkesi ilgilendirdiği için çok popüler olduğunu, ama esasında SQL sistemlerinin birçok modülünün gevşetilmesiyle yapıldığını vurguladı.

## 6. NoSQL Kategorileri ve Örnek Sistemler

NoSQL sistemleri dört kategoriye ayrılır:

- Doküman tabanlı (document-based) NoSQL
- Anahtar-değer depoları (key-value stores)
- Wide column ya da sütun tabanlı (column-based) depolar
- Çizge tabanlı (graph-based) depolar

Bunların karma (hibrit) biçimleri de vardır. Hoca derste doküman ve anahtar-değer depolarını ayrıntılı anlatacağını, diğer ikisine öğrencilerin bakmasını söyledi.

Tarihçede XML veritabanları vardır; 2005'ler civarında ilişkisel modelden ayrılmanın ilk denemeleri olarak çok vaatleri oldu. Nesne (object) veritabanları da öyledir; bugün bunların popülerliği kalmamıştır. XML ve JSON ise yarı yapısal verinin sorgulanmasında birlikte kullanılır. JSON (JavaScript Object Notation) web servislerinin haberleşmesinde de çok kullanılan bir yapıdır; yarı yapısal verinin saklanması ve sorgulanması için bir model, bir dil diye düşünülebilir.

Örnek sistemler:

- Google Bigtable: Google'ın kapalı (açık kaynak olmayan) sütun tabanlı NoSQL sistemi.
- Amazon DynamoDB: Amazon servislerinin kullandığı anahtar-değer deposu.
- HBase: Apache'nin açık kaynak sistemi.
- Voldemort: Dynamo tekniklerinin açık kaynak gerçeklemesi.
- Cassandra: Facebook'un kullandığı; biraz wide column, biraz anahtar-değer, karma bir sistem.
- MongoDB ve Couchbase: Doküman depoları.
- Neo4j ve GraphBase: Çizge veritabanları.
- OrientDB: Karma bir model. Hoca AsterixDB'yi de duyduğunu söyledi.

> **Ders sonrası not:** Hoca HBase'i bir yerde Dynamo'nun, bir yerde Bigtable'ın açık kaynak karşılığı gibi andı, Voldemort için de önce "Apache'nin", sonra "Apache'nin değil herhalde" dedi. Büyük olasılıkla doğrusu şudur: HBase, Bigtable modelinin açık kaynak karşılığıdır; Voldemort ise LinkedIn'in geliştirdiği, Dynamo'dan esinlenen açık kaynak bir anahtar-değer deposudur.

> **Hocanın vurgusu:** Bu ders alındıysa, örneğin "doküman deposuna bir örnek verin" denince bu isimler akla gelmelidir. İlişkisel modelde PostgreSQL ne kadar biliniyorsa, NoSQL'de de bu isimler bilinmelidir.

## 7. Çoğaltma, Nihai Tutarlılık ve Sharding

Slayttaki karakteristikler dağıtık sistemlerle ilgilidir.

**Soru:** Ölçeklenebilirlik nedir? **Cevap:** Artımlı olması: İhtiyaca göre makine, donanım ve yazılım eklenebilmesi.

Yüksek performanslı veri erişimi denince akla hemen indeksler gelmelidir; yüksek performans ancak indekslerle olabilir. İkinci araç yük dengelemedir (load balancing): 10 makinelik bir kümede yük makinelere dağıtılmalıdır. Yük tek makinede toplanırsa tek hata noktası (single point of failure) oluşur: Orada arıza olunca bütün sistem çöker. Hoca bu kavramların hep birbirini çağrıştırdığını, söylediklerinin sezgisel (intuitive) şeyler olduğunu vurguladı.

Çoğaltmanın sebebi hem erişilebilirlik hem yüksek performanstır: Veri yakındaki başka bir makinede de varsa sorgu oradan karşılanır; bir makine bozulursa başka makineden alınır. Çoğaltması olmayan bir NoSQL veritabanı yoktur.

**Soru:** Çoğaltmanın ortaya çıkardığı problem nedir? **Cevap:** Bir öğrenci doğru cevabı verdi; hoca, çoğaltmadan sonra akla gelmesi gerekenin yazmalar, yani güncellemeler olduğunu söyledi. Verinin tekrar etmesi yer kaplar, ama bu ikincil bir problemdir; disk gibi saklama ortamları ucuzdur. Asıl problem, sürekli gelen yeni verinin bütün kopyalara yazılmasıdır: 10 makinedeki kopyalar sihirli değnek gibi aynı anda güncellenemez. Bu, dağıtık veritabanlarının en karmaşık noktalarından biridir ve usta-usta (master-master), usta-köle (master-slave) gibi protokollerle çözülür.

Sonuç olarak PostgreSQL ya da Oracle gibi geleneksel sistemlerde bir sorguda yanlış bir şey görülmez. Onlarda da yalıtım (isolation) düzeyleriyle ACID kriterlerinin gevşetilmesi mümkündür, ama istenirse %100'e yakın doğru çalışırlar. NoSQL'de böyle bir vaat yoktur; vaat nihai tutarlılıktır (eventually consistent): Şu an tutarlı olmayabilir, ama bu günlerce sürmez. Saklanan veri tweet, sosyal medya ve web bağlantıları gibi yarı yapısal veri olduğu için bu gayet makuldür.

### 7.1 Sharding

Dikkat çeken bir başka kelime sharding'dir (sharding of files). Hoca kelimenin sözlük anlamını bilmediğini, bildiğinin yatay bölümleme (horizontal partitioning) olduğunu söyledi. Nasıl ölçekleme yatay ise bölümleme de yataydır. Dosya ya aralık (range) esaslı ya da hash esaslı parçalanır.

Google'ın Bigtable'ındaki gibi kocaman bir dosya tek bir yerde saklanmaz; başına bir şey gelirse bütün veri gider, bu hiç erişilebilir değildir. Dosya (1 TB, 1 PB, ne olursa) parçalara ayrılır, parçalar yüzlerce, binlerce makineye dağıtılır ve her parça çoğaltılır. Hoca en az 3 kopya tutulduğunu, HBase'de varsayılanın bildiği kadarıyla 3 olduğunu, erişilebilirlik beklentisine göre 10 da olabileceğini söyledi.

### 7.2 Veri modelleme tarafı

Fiziksel gerçeklemeyle ilgili kavramlar küme ve makinelerdir. Tasarım, yani veri modelleme tarafında ise şu kavramlar gelir:

- Daha az güçlü sorgu dili (less powerful query language).
- Şema zorunlu değildir: Şemasız ya da yarı şemalı.
- Sürümleme (versioning): Çoğaltma yüzünden birçok makineden gelen kopyalardan hangi sürümün alınacağı sorusu. Ya zaman damgası en yakın olan alınır ya da sürümler uygulamaya gönderilir ve uygulama ihtiyacına göre birini seçer. Doküman depolarında, Cassandra'da ve diğerlerinde sürümleme vardır; her birinin kendi protokolü bulunur.

## 8. CAP Teoremi

Slayta göre çoğaltılmış veriler arasında farklı tutarlılık düzeyleri vardır (ekrandan, 00:39:40). En güçlüsü serileştirilebilirliği (serializability) zorlamaktır, ama yüksek ek yük getirir ve okuma-yazma performansını düşürebilir. CAP teoremi tutarlılık (consistency), erişilebilirlik (availability) ve bölünme toleransı (partition tolerance) kavramlarını ele alır: Çoğaltma yapılan dağıtık bir sistemde üçü aynı anda garanti edilemez.

Hoca CAP'teki tutarlılığın SQL sistemlerindeki tutarlılıktan farklı olduğunu açıkladı. SQL sistemlerinde tutarlılık, bir işlemin (transaction) sonunda veritabanının tutarlı kalmasıdır. İşlem, birden çok SQL ifadesi ve güncelleme içerebilen bir programdır; işin içinde yazma vardır, yazma olmasa sistem bir arşive dönüşürdü. Örnek: Bir hesaptan başka bir hesaba 100 lira transfer edilirken iki güncelleme yapılır; biri azaltılır, diğeri artırılır. A ve B'nin toplamı aynı kalmalı, para bir yere uçmamalıdır. Bu, küçük dünyanın gerektirdiği bir kısıttır. NoSQL'de ise tutarlılıktan daha çok kopyaların birbiriyle tutarlılığı kastedilir. Slayttaki küçük nota göre ACID'deki tutarlılık, bir işlemin şemada tanımlı bütünlük kısıtlarını ihlal etmemesidir; ama kopyaların tutarlılığı da bir kısıt olarak tanımlanırsa iki kullanım birbirine bağlanır.

**Soru:** ACID'e karşılık hangi kelime akla gelmeli? **Cevap:** BASE, yani nihai tutarlılık (eventually consistent). Hoca bu dersteki beklentisinin bu olduğunu, her birinin ayrı bir kitap konusu olduğunu söyledi.

Bölünme toleransı: Kümede bir grup makine devre dışı kalırsa, kalanlar kendi aralarında anlaşabiliyorsa hizmet vermeye devam eder; birbirlerine muhtaç değildir, yalnız koordineli hareket ederler. Hoca bunun erişilebilirliğe yakın olduğunu, erişilebilirliğin daha genel, bölünme toleransının ise kümeye, dağıtık yapıya daha çok bakan bir kavram olduğunu söyledi.

Teorem, bu üçünden en fazla ikisinin aynı anda sağlanabileceğini söyler; üçünü birden hedeflemek boşunadır. Hocanın özeti:

- SQL sistemleri tutarlıdır, ama erişilebilir ve bölünme toleranslı değildir.
- NoSQL sistemleri tutarlı değildir, ama her zaman erişilebilir ve bölünme toleranslıdır.

Slayta göre NoSQL dağıtık depolarında daha zayıf bir tutarlılık düzeyi çoğu zaman kabul edilebilir; erişilebilirlik ve bölünme toleransını garanti etmek daha önemlidir ve nihai tutarlılık sıkça benimsenir.

> **Ek bilgi (derste anlatılmadı):** CAP teoreminin daha kesin okunuşu şudur: Ağda bir bölünme olduğunda sistem tutarlılık ile erişilebilirlikten birini seçmek zorundadır; bölünme yokken ikisi birlikte sağlanabilir. Bu yüzden "SQL sistemleri erişilebilir değildir" ifadesi, bölünme anındaki davranış için bir sadeleştirmedir.

**Soru:** SQL'in karmaşıklığını ve doğruluk vaadini koruyup dağıtık çalışan sistemler yok mu? **Cevap:** Var. SQL sistemlerinin hedefi tam doğruluk ve karmaşık sorgulardır; NoSQL'inki büyük veridir. İkisinin arasında hem hızlı hem dağıtık çalışmaya zorlanan bir çalışma grubu vardır: NewSQL. Hoca bunların derste işlenmediğini, en az 3-5 tane NewSQL sistemi bildiğini, merak edenlerin bakabileceğini söyledi.

## 9. Doküman Depoları: MongoDB

Doküman tabanlı depoların meşhur örneği MongoDB'dir. Hoca, veritabanı sıralama sitelerinde MongoDB ve Cassandra'nın ilk 10'da yer aldığını, ilk sırada Oracle'ın bulunduğunu, ama bu sıralamaların bağlayıcı olmadığını söyledi: Bazı ölçütlere ve kıyaslama testlerine (benchmark) göre yapılırlar; önemli olan, veritabanının uygulamaya göre seçilmesidir. Aksi hâlde herkes ilk sıradakini kullanırdı.

### 9.1 Koleksiyon ve doküman

Doküman depolarında koleksiyon (collection) kabaca ilişkisel modeldeki tabloya, doküman (document) ise tablodaki satıra karşılık gelir. Hoca bunun %100 doğru olmadığını, ama bilinen bir şeyle eşleştirmenin kavramı canlandırdığını söyledi. Tabloda aynı şemaya sahip satırlar bir araya gelir; koleksiyonda ise birbirine benzeyen dokümanlar bir araya gelir. Birinin üç, ötekinin beş niteliği olabilir.

Dokümanlar genelde JSON ya da XML gibi yarı yapısal biçimlerde saklanır. Bu biçimler kendini tanımlar (self-describing); JSON dokümanı açılıp okunabilen bir metindir, yani ayrıntılıdır (verbose) ve fazla yer kaplar. Gerçek sistemlerde kompakt ikili biçimi BSON kullanılır. Hoca, PostgreSQL'de de dizinlerdeki dosyaların açılıp okunamayacağını, hepsinin ikili biçimde olduğunu hatırlattı: Metin ASCII'ye göre kodlanır ve çok yer kaplar; ikili biçim bayt dizisidir, çok daha az yer kaplar ve hızlı işlenir.

### 9.2 Koleksiyon oluşturma ve şema

Kitaptaki örnekte `COMPANY` veritabanından bir `project` koleksiyonu oluşturulur. Koleksiyona `capped` seçeneğiyle sınır konabilir: Belli bir yer kaplasın ve en fazla 500 doküman içersin; bu, bir tablonun en fazla 500 satır içermesine benzetilebilir. Ama tek tek dokümanların şeması kısıtlanmaz: Hepsi anlam bakımından proje dokümanıdır, ama bir projenin özellikleri ötekinden farklı olabilir. Her dokümanın bir kimliği vardır. Hoca, bir web servisi üzerinden (çoğu zaman ücretli ya da belli bir süre ücretsiz) bir küme ayrılıp koleksiyon oluşturulabileceğini ve doldurulabileceğini, bunun ayrı bir laboratuvar çalışması olabileceğini söyledi.

Dokümandaki veri alanlarının yapısı, dokümanlara nasıl erişileceğine göre seçilir. Bir birincil anahtar tanımlanabilir; tanımlanmazsa sistem `_id` alanında bir ObjectId'yi otomatik oluşturur. ObjectId genelde zaman damgası içerir; sürümlemeyle de ilgilidir.

### 9.3 Proje ve işçi için üç tasarım

Hoca, kitapta MongoDB dokümantasyonundan alınan üç tasarımı anlattı. Amaç hangi projede hangi işçilerin çalıştığını saklamaktır.
<!-- BELİRSİZ: Bu bölümde ekran paylaşılmadı (kareler 00:54:00-00:58:00 yalnız ad etiketi gösteriyor); JSON dokümanlarının alan adları ve değerleri karede doğrulanamadı, anlatım altyazıdan kuruldu. -->

**Birinci tasarım:** Her proje dokümanının içinde bir `workers` dizisi (array) vardır ve dizinin elemanları işçi bilgileridir. JSON'da böyle iç içe (nested) bir dizi tanımlanabilir. Proje koleksiyonu bu dokümanlardan oluşur; sınır 500 dense de 500 milyon da olabilir.

**İkinci tasarım:** Proje dokümanının içinde işçi kimlikleri bir dizi olarak tutulur (`worker1`, `worker2` gibi), işçilerin bilgileri ayrı bir `worker` koleksiyonundaki dokümanlardadır.

**Üçüncü tasarım:** Proje koleksiyonu ve işçi koleksiyonu vardır; işçi dokümanlarında proje kimliği geçer. Bu kez dizi yoktur.

**Soru:** Bu tasarımlar size neyi hatırlatıyor? **Cevap:** Normalizasyonu ve fazlalığı (redundancy). Birinci tasarımda bir işçinin bilgileri, çalıştığı her projede tekrar eder. İkinci tasarım fazlalığı azaltır ama yapı hâlâ 1NF değildir; dizi yüzünden iç içedir. Hoca birinci tasarımın 1NF olmadığı gibi 2NF ve 3NF de olmadığını söyledi: `(Id, Project)` birlikte anahtar olup `Ename` bu anahtarın bir parçasına fonksiyonel bağlıysa bu 2NF'ye aykırıdır. Normalizasyonda bu parçalanarak çözülürdü, burada aynı yerde tutulur. Bir işçinin adı, adresi, yaşı varsa çalıştığı her projede yeniden geçer. Üçüncü tasarımda ise dizi yoktur, iç içe yapı yoktur.

Tasarım tamamen kullanıcıya, uygulamadan beklenen işlemlere bırakılmıştır. Hoca bu örneğin SQL'den modelleme noktasında ayrılışı göstermesi bakımından iyi bir motivasyon olduğunu söyledi.

### 9.4 İşlemler, çoğaltma ve sharding

Fiziksel tarafta tek doküman üzerindeki güncelleme doğrudur (atomiktir). Birden çok doküman üzerindeki işlemlerde (multi-document transactions) iki aşamalı onay (two-phase commit) protokolü kullanılır. Hoca bu algoritmanın oldukça karmaşık olduğunu, ACID'deki onayın zaten zor olduğunu, iki aşamalı onayın bunu dağıtık olarak sağlamaya çalıştığını söyledi.

Çoğaltma MongoDB'de usta-köle (master-slave) yaklaşımıyla yapılır: Bütün yazmalar önce birincil (master) kopyaya yapılır, sonra kademeli (gradual) olarak köle (slave) kopyalara yansıtılır. Yansıtmanın kendisi de protokollere bağlıdır; uygulamanın doğruluk beklentisine göre ayarlanır ve beklenen tutarlılık derecesi yapılandırılabilir.

MongoDB'de sharding yine yatay bölümlemedir: Dokümanlar ayrık parçalara (disjoint partitions, chunk) bölünür; ihtiyaca göre yeni düğümler eklenebilir. Parçalar farklı düğümlerde saklanarak yük dengelenir. Kocaman bir koleksiyon tek makinede değil, dağıtılmış olarak durur; indeks gibi yük dengeleme de yüksek performansa hizmet eder. Her dokümanın kimliği üzerinde varsayılan bir indeks vardır; bu indeksle dokümana hızlı erişilir.

Bölümleme ya aralık esaslı ya da hash esaslıdır. Uygulamadaki sorgular aralık sorgularıysa aralık esaslı, eşitlik tarzında erişimler söz konusuysa hash esaslı bölümleme seçilmelidir. Hoca bunun genel bir ilke olduğunu söyledi: Aramada da bölümlemede de iki esas vardır, aralık ve hash. Aralık esaslı dağıtımda örneğin 0 ile 100.000 arasındaki değerler bir makineye, 100.000 ile 200.000 arası başka makineye gider; hash esaslıda değerin hash'i hangi makineyi gösteriyorsa oraya gider. MongoDB'de iki bölümleme de vardır; Dynamo ya da Voldemort ise yalnız hash esaslı dağıtır.

## 10. Anahtar-Değer Depoları ve Tutarlı Karma

Anahtar-değer depoları tarihsel olarak ilk geliştirilenlerdir ve daha da şemasızdır, yani SQL sistemlerinden daha uzaktır. Hem yapısal hem yapısal olmayan hem yarı yapısal veriyi saklayabilir. Anahtarın belirlediği değer bir bayt dizisi olarak saklanır; içinde ne olduğu önemli değildir, hiçbir şema yoktur. Bu, veri öğesine çok hızlı erişmeyi sağlar. Slayta göre değer bir karakter dizisi ya da bayt dizisi olabilir ve yapısını uygulama yorumlar.

Örnekler: Amazon'un DynamoDB'si (kapalı, açık kaynak değil; hiçbir sorgu dili yok) ve Oracle'ın anahtar-değer deposu. DynamoDB'de her öğe nitelik-değer çiftleriyle saklanır; nitelik tek ya da çok değerli olabilir; birincil anahtar tek nitelik ya da birden çok nitelik olabilir. Sistem milyarlarca anahtar-değer çiftini kümedeki makinelere dağıtır. Açık kaynak alternatifi Voldemort, Dynamo'nun tekniklerini gerçekler. İşlemler SQL'in en basit biçimleridir: `get`, `put`, `delete`. Join yoktur; yapılacaksa uygulama, çoğu zaman paralel işlemeyle yapar.

### 10.1 Tutarlı karma (consistent hashing)

Hocanın asıl anlatmak istediği, Voldemort'un anahtar-değer çiftlerini dağıtmakta kullandığı tutarlı karma yöntemiydi (ekrandan, 01:22:20). Dağıtım hash esaslıdır. Problem şudur: Kümedeki makinelere veri nasıl dağıtılacak ve bu ölçeklenebilir olacak; yani ihtiyaca göre yeni makine eklenecek ve yeni makine, kapasitesine göre diğer makinelerden yük alacak. Hocaya göre büyük resmi bir çember üzerinde modellemek dikkat çekici bir fikirdir.

Hash fonksiyonunun ürettiği değer aralığı (sıfırdan büyük bir sayıya kadar) bir halka olarak düşünülür. Kitaptaki şekilde üç makine vardır: A, B ve C. Bir anahtar hash'lenir; hash değeri range 1'e düşüyorsa öğe A'ya, range 2'ye düşüyorsa B'ye, range 3'e düşüyorsa C'ye yazılır. Şekil açıklamasına göre C'nin kapasitesi daha büyüktür. Hoca önce şekildeki harfleri kopyalar (replika) olarak yorumladı, sonra düzeltip üç makine olduğunu söyledi.

Makineler dolunca yeni veri için yeni makine eklenmelidir. Yeni makine D halkaya eklendiğinde, şekil açıklamasına göre range 4'teki öğeler B'den (range 2 küçülür) ve C'den (range 3 küçülür) D'ye taşınır. Böylece yük dengeleme, ihtiyaca göre, hash fonksiyonuyla kontrol edilmiş olur. Yük halkada saat yönünde dağılır. Slayttaki nota göre yeni bir düğüm, kapasitesine göre halkada bir ya da birden çok noktaya eklenebilir; kapasitesi büyükse birçok noktaya yerleştirilir. Yerleştirmek, o aralığa düşen anahtarların o makineye gitmesi demektir. Hoca algoritmanın ayrıntılarının örneklerle pekiştirilmesi gerektiğini, derste yalnız ana hatlarının verildiğini söyledi.
<!-- BELİRSİZ: Hoca D'nin hangi düğümlerin yükünü aldığını anlatırken önce "A ve C", sonra "A" diyor (01:26:02-01:26:30); şekil açıklamasına göre öğeler B ve C'den taşınıyor. -->

Diğer anahtar-değer depoları: Oracle'ın NoSQL veritabanı; Redis (bellek içi, in-memory; yüksek performansla çalışır, arada veriyi diske yazarak kalıcılık sağlar); Apache Cassandra (hem anahtar-değer hem sütun tabanlı).

## 11. Sütun Tabanlı ve Çizge Depoları

Hoca bu iki kategoriyi kısaca geçti ve ayrıntısına öğrencilerin bakmasını istedi.

Sütun tabanlı (column store) depolarda önce sütun aileleri (column family), yani nitelik kümeleri belirlenir ve bunlar sonradan değiştirilemez. Ailelerin içindeki nitelikler ise değiştirilebilir. Bu yüzden bu kategori ilişkisel sistemlere en yakın olanıdır; anahtar-değer depoları en uzak olanıdır. Kabaca belirlenen sütun aileleri katı ve düzenlidir, içleri esnektir. Örnek Bigtable'dır; açık kaynak karşılığı HBase aynı modele dayanır ve Hadoop'un HDFS'i üzerine kuruludur.

Çizge veritabanları düğümler (node) ve kenarlardan (edge) oluşan bir koleksiyondur; daha çok sosyal medya bağlantıları için kullanılır. Popüler örnek Neo4j'dir; kendi sorgu dili Cypher oldukça popüler olmuştur. Slayttaki temel Cypher yan tümceleri (ekrandan, 01:31:00):

```text
MATCH <pattern>                     desene uyan düğüm ve ilişkileri bul
WITH <specifications>               toplamalar ve diğer sorgu değişkenleri
WHERE <condition>                   getirilecek veriye koşul
RETURN <data>                       döndürülecek veri
ORDER BY <data>                     sıralama
LIMIT <max number>                  döndürülen öğe sayısını sınırla
CREATE <node, labels, properties>   düğüm oluştur
CREATE <relationship, type, props>  ilişki oluştur
DELETE <nodes or relationships>     sil
SET <property values and labels>    özellik ve etiket ata
REMOVE <property values and labels> özellik ve etiket kaldır
```

Hoca Cypher'ın oldukça bildirimsel olduğunu, SQL kadar güçlü olmasa da özyinelemeli sorgularda başarılı olduğunu duyduğunu söyledi.

Böylece doküman ve anahtar-değer depoları daha ayrıntılı, sütun ve çizge depoları kısaca incelendi. Birçok sistem bu modelleri karma olarak kullanır.

## 12. İndekslemeye Giriş

Hoca kalan sürede indekslemeye bir giriş yaptı. İndeks, sistemin temel modüllerinden biridir ve son kullanıcıya performans olarak yansır. İndekslerin içinde veri yapıları vardır; bunlar ve disk performansı sistem gerçekleme dersinde daha ayrıntılı görülür, ama hocaya göre o ders alınmasa da indekslemenin ana hatları bilinmelidir. Sonraki derslerde B+ ağacı ve hash esaslı indeksler, ardından LSM ağacı (Log-Structured Merge tree) işlenecek. Hocanın ifadesiyle LSM, bütün NoSQL veritabanlarının ana depolama yapısıdır ve B+ ağacına bir alternatiftir; büyük veriyi tek bir ağaçta indekslemek yerine birden çok ağaca dağıtıp koordine eden bir "ağaç ailesi" yaklaşımıdır.

<!-- BELİRSİZ: Bölüm 12-14'te ekran paylaşılmadı (01:39:30-01:58:30 arası kareler yalnız hocanın kamerasını gösteriyor); indeks şekillerindeki kayıtlar ve sayılar karede doğrulanamadı, altyazıdan alındı. Hoca dersin sonunda ekran paylaşımını unuttuğunu fark etti. -->

### 12.1 İndeks dosyası

İndeks dosyası, ana dosyanın, yani veri dosyasının yanında bulunan yardımcı bir dosyadır. Bu dosyadaki düzenleme sayesinde büyük dosyada aranan noktalara hızla erişilir. Aranan noktalar arama anahtarıyla (search key) ifade edilir: Hangi nitelik üzerinden arama yapılıyorsa o arama anahtarıdır. Arama anahtarı bir ya da birden çok nitelik olabilir.

İndeksin şeması düzenli ve küçüktür: Her indeks kaydı bir arama anahtarı ve o anahtarı içeren veri tablosundaki kayıtlara işaretçiler (pointer) içerir. İki temel düzenleme vardır:

- **Sıralı indeksler (ordered indexes):** İndeks kayıtları arama anahtarına göre sıralıdır.
- **Hash indeksleri:** İndeks kayıtları bir hash fonksiyonuna göre dağıtılır.

Veri tablosunun şeması kısıtlı değildir; şemasız da olabilir, ilişkisel tablodaki gibi katı da olabilir. Ana dosyayı sıralı tutmak çok zordur: Bir kez sıralansa bile sürekli eklemeler, silmeler ve güncellemeler sırayı bozar ve sıralı tutmak güncellemeleri çok yavaşlatır. Bu yüzden ana dosyaya dokunulmaz, küçük ve düzenli indeks dosyası düzenlenir.

**Soru:** İndeksin sıralı olması aramada nasıl bir avantaj sağlar? **Cevap:** İkili arama (binary search). Logaritmik olduğu için çok hızlıdır.

### 12.2 Sıralı indeks mi, hash indeksi mi?

Algoritmik karmaşıklık açısından hash indeksi $O(1)$, sıralı indeks $O(\log n)$'dir; bu yüzden hash indeksinin daha iyi olduğu düşünülebilir. Ama yaygın olarak kullanılan sıralı indekslerdir. En önemli sebep, sıralı indekslerin aralık sorgularına hizmet etmesidir. Hash indeksi bir aralıktaki kayıtları yan yana yerleştirmez, dağıtır. Dağılmış kayıtlara erişmek ayrı bir maliyettir, çünkü her biri ayrı bir disk erişimi (disk I/O) demektir. Aralıktaki kayıtlar aynı yerde bulunsa ek disk erişimi olmazdı. Burada diskin çalışma prensibini bilmek gerekir: Veritabanı dosyaları disktedir ve disk bir darboğazdır (bottleneck); veri yapıları disk erişimini en aza indirecek biçimde çalışmalıdır. Disk esaslı veri yapıları denince indeksler akla gelir.

B+ ağacı gibi sıralama esaslı yapılar hem eşitlik hem aralık sorgularına logaritmik olarak hizmet verir. Hash esaslılar yalnız eşitlik sorgularına $O(1)$'de hizmet verir.

**Soru:** Eşitlik sorgusunda bile hash indeksi pratikte neden $O(1)$ değildir? **Cevap:** Büyük O gösterimi yöntemin bir özetidir ve aldatıcı olabilir; bir de pratik gerçekleme ve veri dağılımı vardır. Hash yönteminde her değer bir hash fonksiyonuyla bir disk sayfasına gönderilir ve arama anahtarına göre doğrudan bulunur. Ama aynı noktaya hash edilen başka kayıtlar olabilir; çok sayıda çarpışma (collision) çıkar. Çarpışmaları verimli çözmek kolay değildir. İndeks dosyasının veri miktarına göre uyarlanarak kademeli büyümesi ve küçülmesi gerekir; bunun için doğrusal karma (linear hashing) gibi uyarlanabilir, kendini düzenleyen yöntemler kullanılır. Sıralı indekste ise böyle bir çarpışma ya da dengesizlik problemi yoktur; logaritmik olmasına rağmen daha verimlidir.

### 12.3 İndeksin değerlendirilmesi

Slayttaki ölçütler:

- Desteklenen erişim türleri (eşitlik sorgusu, aralık sorgusu).
- Erişim süresi.
- Ekleme süresi: Ana dosyaya bir kayıt eklenince indekse de eklenmelidir.
- Silme süresi: Ana dosyadan kayıt silinince indeksten de silinmelidir.
- Kapladığı ek yer.

Bu veri yapısının ihtiyaca göre şekillendirilmesi birçok yapı doğurmuştur: Başta B+ ağacı, farklı veri türleri için R ağacı, erişim yöntemine göre hash ve onun kendini düzenleyen varyantları (doğrusal karma gibi).

## 13. Kümelenmiş ve İkincil İndeksler

Sıralı indekslerde terminolojide şu kavramlar geçer: Kümelenmiş indeks (clustered index), birincil indeks (primary index; ikisi aynı anlamda kullanılır), ikincil indeks (secondary index) ve indeksli sıralı dosya (index-sequential file).

**Kümelenmiş indeks:** İndeks sıralıdır ve ana dosya da aynı niteliğe göre sıralıdır. Aralık sorgusunda aralığa erişmek için ana dosyaya bir kez gitmek yeterlidir. Hocanın örneğinde `ID` üzerinde bir indeks vardır ve dosya `ID`'ye göre sıralıdır. 15.000 ile 30.000 arasındaki kimliklere erişmek için indekste ikili aramayla aralığın başı bulunur, ana dosyada oraya geçilir; dosya da sıralı olduğu için aralıktaki kayıtlar art arda okunur. "Clustered" adı, aralıktaki kayıtların ana dosyada da kümelenmiş olmasından gelir.
<!-- BELİRSİZ: Hocanın kümelenmiş indeks örneğinde söylediği aralık önce "15.000 ile 20.000", sonra "15.000 ile 30.000" diye geçiyor ve bulunan ilk kayıt "15.151" (01:50:54); şekil ekranda görünmüyor. -->

**İkincil indeks:** Ana dosya indeksin niteliğine göre sıralı değildir. Hocanın örneğinde `salary` üzerinde sıralı bir indeks vardır. 60.000 ile 80.000 arasındaki kişilere erişmek için ana dosyada farklı noktalara gidilmelidir: 60.000'lik kayda gidilir, sonra 62.000, 65.000 gibi kayıtlar için ayrı ayrı yerlere gidilir. Her biri ayrı bir disk erişimidir. Bu yüzden birincil (kümelenmiş) indeks daha kıymetlidir. İkincil indeksin de kıymeti vardır, ama daha çok eşitlik sorgularında ya da aralığın dar olduğu sorgularda işe yarar. Bu yüzden indeks ayarlaması (index tuning), yani hangi indeksin seçileceği, sistem içinde hassas ve karmaşık, deterministik olmayan bir iştir.

## 14. İndeks Ne Zaman Kullanılır, Neden Her Yere Konmaz?

**Soru:** `salary` üzerindeki ikincil indeksi kullanabilecek bir SQL ifadesi söyleyin. **Cevap:** `instructor` tablosunda `WHERE salary BETWEEN 60000 AND 80000` ya da eşitlik sorgusu `WHERE salary = 80000`. Ama `WHERE ID = 20000` bu indeksi kullanamaz.

```sql
SELECT name
FROM instructor
WHERE salary BETWEEN 60000 AND 80000;
```

**Soru:** Bu sorguda `salary` üzerinde indeks yok ama `name` üzerinde indeks var. `name` indeksinin bir anlamı var mı? **Cevap:** Hiçbir anlamı yok. Arama `WHERE` kısmında yapılır. SQL ifadesi önce `FROM` ile tabloyu okur, sonra `WHERE` ile yüklemleri uygular, en son `SELECT` ile istenen niteliğe (`name`) erişir. İş bittikten sonra `name`'e erişildiği için onun üzerindeki indeks kullanılmaz.

**Soru:** `WHERE salary = 60000` ve `WHERE salary BETWEEN 60000 AND 200000` sorguları `salary` indeksini kullanır mı? **Cevap:** Eşitlik sorgusu mutlaka kullanır. Milyonlarca kayıt içinde 60.000'i ana dosyada bulmak sırayla bakmayı gerektirir; indeks sıralı olduğu için ikili aramayla (daha ötesinde B+ ağacıyla) logaritmik olarak bulunur, sonra ana dosyada tek bir yere atlanır. Geniş aralık sorgusunda ise indeks kullanılmayabilir: 60.000-70.000 ya da 60.000-80.000 için kullanılabilir, ama 60.000-200.000 için büyük olasılıkla kullanılmaz. Bu aralıkta çok sayıda kişi vardır ve ana tabloda bir oraya bir buraya gidilir; buna rastgele erişim (random access) denir. Bu kararı sorgu iyileştirici (optimizer) verir: Değer aralığına ve dağılımına bakar. Maaşlar zaten 50.000 ile 200.000 arasında dağılıyorsa ve sorgu bunun hemen hepsini istiyorsa, indeksten gitmek yerine bütün dosya taranır.

Hoca bunun denenmesini önerdi: SQL ifadesinin başına `EXPLAIN` yazılınca sorgunun nasıl çalıştığı görülür. `salary` üzerinde indeks tanımlanmışsa, aralık genişletildiğinde indeksin kullanılmadığı, daraltıldığında kullanıldığı görülebilir.

Slaytta SQL'de indeks oluşturma ve silme komutları geçti; hoca bir tablo üzerinde adında "PK" geçen bir indeksin `CREATE INDEX` ile tanımlandığını ve sonra düşürüldüğünü (`DROP INDEX`) gösterdi. Hangi tabloda, hangi nitelikte en çok sorgu yapılıyorsa o tablolarda indeks oluşturulmalıdır.
<!-- BELİRSİZ: Altyazıda tablo adı "TX tablosu" ve indeks adı "TX PK" diye geçiyor (01:58:23-01:58:50); ekran paylaşılmadığı için komutun tam metni doğrulanamadı. Kitaptaki benzer örnekte büyük olasılıkla `takes` tablosu kullanılıyor. -->

### 14.1 Neden her niteliğe indeks konmaz?

İndeksler doğru kullanılınca sistemi binlerce kat hızlandırabilir. Hoca bunu bir sayıyla gösterdi: $\log_2 1024 = 10$. 1024 adımlık doğrusal bir iş, logaritmik aramayla 10 adıma iner.

**Soru:** Madem indeksler bu kadar faydalı, bütün tabloların bütün niteliklerine indeks oluşturalım mı? **Cevap:** Hayır. Burada bir fazlalık (redundancy) vardır: Arama anahtarı hem ana tabloda hem indekste bulunur. Ana tabloya yeni kayıt eklenince indekse de eklenmeli, kayıt silinince indeksten de silinmeli, arama anahtarı güncellenince indeks de güncellenmelidir. Yer kaplaması o kadar önemli değildir; asıl önemli olan tutarlılık, yani indeksin güncel tutulmasının getirdiği ek yüktür. Hoca bunu çoğaltmadaki problemle aynı türden gördü.

**Soru:** Sistem birincil anahtar üzerinde neden kendiliğinden indeks oluşturur? **Cevap:** Hoca, birincil anahtarların da değişebileceğini, eklenip silinebileceğini, yani bunun bir yükü olduğunu kabul etti. Ama indeksler yalnız arama için değil, kısıtların sağlanması için de kullanılır. Milyonlarca kayıtlık bir tabloya yeni bir kayıt eklenirken, birincil anahtar kısıtı gereği o anahtarın zaten var olup olmadığına bakılmalıdır. İndeks olmasa kayıtlara teker teker bakmak gerekir. Varsayılan B+ ağacı (ya da hash) indeksi bu kontrolü, yani bir arama (lookup) sorgusunu çok hızlı yapar: Anahtar yoksa kayıt eklenir, varsa reddedilir. Ayrıca join'ler çoğu zaman yabancı anahtar ile birincil anahtar üzerinden yapıldığı için indeks join'leri de hızlandırır.

Hoca, PostgreSQL'de (pgAdmin arayüzünde) üniversite ya da şirket veritabanının kataloglarına bakılmasını önerdi: Birincil anahtarlar üzerinde varsayılan olarak B+ ağacı indeksleri görülecektir.

## Örnek Sorular

**1.** (derste sözlü, 00:02:17) NoSQL sistemlerinin adlarında neden çoğu zaman "database" yerine "store" geçer?

Cevap (derste verildi): Bu sistemler geleneksel veritabanının karmaşık kavramlarını (eş zamanlılık, tam tutarlılık, kurtarma, karmaşık sorgular) gevşetir ya da dışarıda bırakır. Büyük veriyi saklayıp basit işlemlerle (`get`, `put`) erişmeye odaklanan veri depolama sistemleridir.

**2.** (derste sözlü, 00:09:45) Büyük veri sistemlerinde join gerektiğinde ne yapılır?

Cevap (derste verildi): Veritabanı join'i üstlenmez; join uygulama tarafından, çoğu zaman veriyi parçalara ayırıp paralel algoritmalarla yapılır.

**3.** (derste sözlü, 00:32:14) Çoğaltmanın (replication) ortaya çıkardığı temel problem nedir, NoSQL sistemleri bunu nasıl karşılar?

Cevap (derste verildi): Yazmalar, yani güncellemeler: Kopyalar aynı anda güncellenemez, bu yüzden okumalar her an doğru olmayabilir. Usta-köle ya da usta-usta protokolleri kullanılır ve tam tutarlılık yerine nihai tutarlılık (eventual consistency) kabul edilir. Yer kaybı ikincil bir problemdir.

**4.** (derste sözlü, 00:42:11; ekrandan, 00:39:40) CAP teoremi ne söyler? İlişkisel sistemlerin ACID'ine karşılık NoSQL'de hangi kavram kullanılır?

Cevap (derste verildi): Çoğaltma yapılan dağıtık bir sistemde tutarlılık, erişilebilirlik ve bölünme toleransının üçü aynı anda garanti edilemez, en fazla ikisi sağlanır. Hocanın özetine göre SQL sistemleri tutarlılığı, NoSQL sistemleri erişilebilirlik ve bölünme toleransını seçer. ACID'in karşılığı BASE'tir (eventually consistent).

**5.** (derste sözlü, 00:57:31) MongoDB'de işçileri proje dokümanının içine dizi olarak gömmek normalizasyon açısından neyi hatırlatır?

Cevap (derste verildi): Fazlalığı: Bir işçi birden çok projede çalışıyorsa bilgileri her projede tekrar eder. Dizi yüzünden yapı iç içedir, 1NF bile değildir; `(Id, Project)` anahtarına karşı `Ename`'in yalnız `Id`'ye bağlı olması 2NF'ye de aykırıdır. Proje dokümanında yalnız işçi kimliklerini tutmak fazlalığı azaltır ama yine 1NF değildir.

**6.** (ekrandan, 01:22:20) Tutarlı karmada A, B, C düğümlü bir halkaya D düğümü eklenince ne olur?

Cevap (derste verildi; slayttaki şekil açıklamasıyla): Hash değerleri range 1'deki öğeler A'da, range 2'dekiler B'de, range 3'tekiler C'dedir. D eklenince range 4'teki öğeler B'den ve C'den D'ye taşınır; range 2 ve range 3 küçülür. Kapasitesi büyük bir düğüm halkada birden çok noktaya yerleştirilebilir.

**7.** (derste sözlü, 01:45:34) Hash indeksi eşitlik sorgusunda teoride $O(1)$ olduğu hâlde neden sıralı indeksler daha yaygındır?

Cevap (derste verildi): Hash indeksi aralık sorgularına hizmet etmez, aralıktaki kayıtları dağıtır ve her biri ayrı disk erişimi gerektirir. Eşitlik sorgusunda bile çarpışmalar yüzünden pratikte $O(1)$ değildir ve indeksin veri miktarına göre uyarlanması gerekir. Sıralı indeks (B+ ağacı) eşitlik ve aralık sorgularına logaritmik olarak, çarpışma problemi olmadan hizmet verir.

**8.** (derste sözlü, 01:53:03-01:56:37) `instructor` tablosunda `salary` üzerinde ikincil bir indeks var. Şu sorgulardan hangileri indeksi kullanır: (a) `WHERE salary BETWEEN 60000 AND 80000`, (b) `WHERE salary = 80000`, (c) `WHERE ID = 20000`, (d) `WHERE salary BETWEEN 60000 AND 200000` (maaşlar 50.000-200.000 arasında dağılıyor). `SELECT name ... WHERE salary ...` sorgusunda `name` üzerindeki bir indeks işe yarar mı?

Cevap (derste verildi): (a) ve (b) kullanabilir; (c) kullanamaz. (d) için iyileştirici büyük olasılıkla indeksi kullanmaz, çünkü aralık değerlerin hemen hepsini kapsar ve çok sayıda rastgele erişim gerekir; dosyayı taramak daha ucuzdur. `name` üzerindeki indeks işe yaramaz, çünkü arama `WHERE` kısmında yapılır.

**9.** (derste sözlü, 02:00:31-02:02:15) Neden her niteliğe indeks konmaz, ama birincil anahtara sistem kendiliğinden indeks koyar?

Cevap (derste verildi): İndeks bir fazlalıktır; her ekleme, silme ve güncellemede indeksin de güncellenmesi gerekir ve bu tutarlılık yükü getirir. Birincil anahtar indeksi ise birincil anahtar kısıtının denetlenmesi (yeni kaydın anahtarı zaten var mı diye arama) ve yabancı anahtar–birincil anahtar join'lerinin hızlandırılması için gereklidir.

## Dersin Toparlaması

Bu derste NoSQL veritabanlarının neden "store" diye anıldığı, yani geleneksel veritabanının karmaşık modüllerinin büyük veri uğruna nasıl gevşetildiği ele alındı. Dağıtık sistem kavramları (küme, sıradan makineler, yatay ölçekleme, yük dengeleme, çoğaltma, sharding, sürümleme) birbirine bağlanarak anlatıldı; çoğaltmanın yazma problemi ve bunun sonucu olan nihai tutarlılık, CAP teoremi ve ACID karşısında BASE tartışıldı. Dört NoSQL kategorisi örnek sistemleriyle tanıtıldı; MongoDB'de koleksiyon ve doküman kavramları, proje–işçi tasarımlarının normalizasyonla ilişkisi, iki aşamalı onay ve usta-köle çoğaltma; anahtar-değer depolarında tutarlı karma ile yük dengeleme ayrıntılı işlendi. Sütun tabanlı depolarda sütun ailelerinin sabitliği ve Neo4j'in Cypher dili kısaca geçildi.

Son kısımda indekslemeye giriş yapıldı: İndeks dosyasının yapısı, sıralı ve hash indekslerinin karşılaştırılması, kümelenmiş ve ikincil indeksler, sorgu iyileştiricinin indeks kullanma kararı ve indekslerin bakım yükü. Sonraki derslerde B+ ağacı, hash indeksleri ve NoSQL sistemlerinin depolama yapısı LSM ağacı işlenecek.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
