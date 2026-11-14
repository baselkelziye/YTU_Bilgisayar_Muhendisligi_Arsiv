# Ders 9 Çalışma Özeti

## Genel Konular

- NoSQL'in özü: Gevşetilmiş veritabanı
  - NoSQL veritabanları büyük veri sistemleri için saklama ortamlarıdır. Adlarında çoğu zaman "database" yerine "store" geçer (key-value store, document store, column store), çünkü geleneksel veritabanının karmaşık kavramları gevşetilmiştir.
  - İlişkisel sistemler (PostgreSQL, Oracle, MS SQL Server) tek ya da birkaç makinede çalışır ve eş zamanlılık, tutarlılık, kurtarma gibi her şeyi mükemmel yapmaya çalışır. Dünya ölçeğindeki veriyi (veri merkezleri, "veri fabrikaları") bu karmaşıklıkla taşımak mümkün değildir.
  - "Not only SQL": Birçok NoSQL sistemi sonradan SQL'in basit biçimlerini benimsedi, çünkü SQL çok çekici, bildirimsel (declarative) bir dildir. Ama iç içe ve ilişkili (correlated) sorgular, join'ler büyük veri üzerinde pek yapılmaz; temel işlemler `get` ve `put`'tur.
  - Join gerekiyorsa uygulama yapar; bunun için çoğunlukla paralel algoritmalar kullanılır.
- Dağıtık sistem kavramları
  - Küme (cluster): Çok sayıda sıradan (commodity) makine. Yatay ölçekleme: İhtiyaca göre makine ekleyip çıkarmak; hiçbir süper bilgisayar büyük veriyi tek başına taşıyamaz.
  - Veri düzenli değildir: Sosyal medya, web tıklamaları, kullanıcı profilleri yarı yapısal ya da yapısal olmayan veri üretir. Bir alışveriş sitesindeki telefon ve tabletlerin nitelikleri modele göre çok değişir; tek bir şema kurmak zordur.
  - Yüksek performans: İndeksler ve yük dengeleme (load balancing) ile sağlanır. Yük tek makinede toplanırsa tek hata noktası (single point of failure) oluşur.
  - Erişilebilirlik (availability): Sistem her zaman "up and running" olmalı, her zaman hizmet vermelidir. Verilen cevap her zaman tam doğru olmayabilir; bundan ödün verilerek erişilebilirlik sağlanır.
  - Çoğaltma (replication): Erişilebilirliği ve performansı sağlar (yakındaki kopyadan okunur). Çoğaltması olmayan NoSQL sistemi yoktur.
  - Çoğaltmanın problemi yazmalar (update'ler): Kopyalar aynı anda güncellenemez. Çözüm protokolleri usta-usta ve usta-köle (master-master, master-slave) gibi modellerdir. Sonuç nihai tutarlılıktır (eventual consistency).
  - Sharding: Yatay bölümleme (horizontal partitioning); dosya aralık (range) ya da hash esaslı parçalanıp düğümlere dağıtılır ve her parça çoğaltılır (en az 3 kopya; HBase'de varsayılan 3).
  - Veri modelleme tarafı: Daha az güçlü sorgu dili, şema zorunlu değil (şemasız ya da yarı şemalı), sürümleme (versioning): Kopyalardan hangi sürümün alınacağı zaman damgasına göre seçilir ya da sürümler uygulamaya gönderilir.
- NoSQL kategorileri ve örnek sistemler
  - Doküman deposu (MongoDB, Couchbase), anahtar-değer deposu (Amazon DynamoDB, Voldemort, Oracle NoSQL, Redis), sütun tabanlı ya da wide column (Google Bigtable, HBase, Cassandra), çizge (Neo4j, GraphBase). Karma modeller de vardır (OrientDB; Cassandra hem anahtar-değer hem wide column).
  - XML ve nesne veritabanları 2005'ler civarında ilişkisel modelden ilk ayrılma denemeleriydi; bugün popüler değildir. JSON ve XML yarı yapısal verinin saklanmasında ve sorgulanmasında kullanılır.
- CAP teoremi (ekrandan, 00:39:40)
  - Çoğaltılmış veride farklı tutarlılık düzeyleri vardır; en güçlüsü serileştirilebilirliktir (serializability), ama okuma ve yazma performansını düşürür.
  - CAP: Tutarlılık (consistency), erişilebilirlik (availability), bölünme toleransı (partition tolerance). Çoğaltma yapılan dağıtık bir sistemde üçü aynı anda garanti edilemez, en fazla ikisi sağlanır.
  - İlişkisel sistemlerde tutarlılık, bir işlemin (transaction) veritabanını küçük dünyanın kısıtlarına uygun bırakmasıdır (para transferinde toplamın değişmemesi). NoSQL'de daha çok kopyaların birbiriyle tutarlılığı kastedilir.
  - Bölünme toleransı: Kümenin bir kısmı ağdan koparsa kalan düğümler hizmet vermeye devam edebilir.
  - Hocanın özetine göre ilişkisel sistemler tutarlılığı, NoSQL sistemleri erişilebilirlik ve bölünme toleransını seçer. NoSQL'de daha zayıf tutarlılık kabul edilir; ACID'in karşılığı BASE'tir (eventually consistent).
  - İkisinin arasını doldurmaya çalışan, dağıtık ama SQL'in doğruluk vaadini koruyan sistemler NewSQL adı altında toplanır.
- Doküman depoları: MongoDB
  - Koleksiyon (collection) kabaca tabloya, doküman (document) kabaca satıra karşılık gelir. Koleksiyondaki dokümanlar benzerdir ama aynı şemaya sahip olmak zorunda değildir.
  - Dokümanlar JSON ya da XML gibi kendini tanımlayan (self-describing) biçimlerde tutulur; JSON metni ayrıntılı (verbose) olduğu için sistemde ikili ve kompakt biçimi BSON kullanılır.
  - Koleksiyon oluşturulurken sınır (`capped`, boyut ve en fazla doküman sayısı) verilebilir. Her dokümanın bir kimliği (`_id`, ObjectId) vardır; tanımlanmazsa sistem üretir ve ObjectId genelde zaman damgası içerir.
  - Proje ve işçi verisi için üç tasarım: İşçileri projenin içine dizi olarak gömmek; proje içinde işçi kimliklerini dizi olarak tutup işçileri ayrı koleksiyonda saklamak; işçi dokümanlarında proje kimliğini tutmak (dizisiz). Gömülü tasarımlarda fazlalık vardır ve yapı 1NF bile değildir.
  - Tek doküman güncellemesi atomiktir; çok dokümanlı işlemlerde iki aşamalı onay (two-phase commit) protokolü kullanılır. Çoğaltma usta-köle yaklaşımıyla yapılır: Yazmalar önce birincil (master) kopyaya, sonra kademeli olarak diğer kopyalara yansıtılır.
  - Sharding: Dokümanlar ayrık parçalara (chunk) bölünür, farklı düğümlerde saklanarak yük dengelenir; anahtar üzerinde varsayılan bir indeks vardır. Aralık sorguları çoksa aralık esaslı, eşitlik erişimleri çoksa hash esaslı bölümleme seçilir.
- Anahtar-değer depoları
  - Tarihsel olarak ilk geliştirilenlerdir ve SQL sistemlerinden en uzak olanlardır. Anahtar bir değeri belirler; değer bir bayt dizisidir ve içinde ne olduğu sistemi ilgilendirmez (yorumu uygulamaya aittir).
  - DynamoDB'de her öğe nitelik-değer çiftlerinden oluşur; birincil anahtar tek ya da çok nitelikli olabilir. İşlemler `get`, `put`, `delete` ile sınırlıdır.
  - Tutarlı karma (consistent hashing) (ekrandan, 01:22:20): Hash değerlerinin aralığı bir halka gibi düşünülür; her düğüm halkada bir aralıktan sorumludur. Üç düğümlü örnekte range 1 A'ya, range 2 B'ye, range 3 C'ye gider; C'nin kapasitesi daha büyüktür. Yeni düğüm D eklenince range 4'teki öğeler B ve C'den D'ye taşınır. Kapasitesi büyük düğüm halkada birden çok noktaya yerleştirilebilir.
  - Redis bellek içi (in-memory) çalışır, veriyi ara sıra diske yazar.
- Sütun tabanlı ve çizge depoları
  - Sütun ailelerinin (column family) baştan belirlenmesi gerekir ve sonradan değiştirilemez; ailelerin içindeki nitelikler değişebilir. Bu yüzden ilişkisel modele en yakın NoSQL kategorisidir. HBase, Bigtable modeline dayanır ve Hadoop'un HDFS'i üzerine kuruludur.
  - Çizge veritabanları düğümler ve kenarlardan oluşur, sosyal medya bağlantıları için kullanılır. Neo4j'in sorgu dili Cypher'dır (ekrandan, 01:31:00): `MATCH`, `WITH`, `WHERE`, `RETURN`, `ORDER BY`, `LIMIT`, `CREATE`, `DELETE`, `SET`, `REMOVE`. Bildirimseldir, SQL kadar güçlü değildir ama özyinelemeli sorgularda başarılıdır.
- İndekslemeye giriş
  - İndeks dosyası, veri dosyasının yanındaki yardımcı bir dosyadır. Her indeks kaydı bir arama anahtarı (search key) ve o anahtarı içeren kayıtlara işaretçi (pointer) içerir. Arama anahtarı bir ya da birden çok nitelik olabilir.
  - İki temel düzenleme vardır: Sıralı (ordered) indeksler ve hash indeksleri. Ana dosyayı sıralı tutmak güncellemeleri çok yavaşlatır; küçük ve düzenli indeks dosyasını sıralı tutmak kolaydır.
  - Sıralı indekste ikili arama (binary search) ile logaritmik erişim olur. Hash indeksi eşitlik sorgusunda teoride $O(1)$'dir ama çarpışmalar (collision) yüzünden pratikte öyle değildir ve aralık sorgularına hizmet etmez. B+ ağacı hem eşitlik hem aralık sorgusuna logaritmik hizmet verir; yaygın olan sıralı indekstir.
  - İndeks değerlendirme ölçütleri: Desteklenen erişim türleri (eşitlik, aralık), erişim süresi, ekleme ve silme süresi, kapladığı yer.
  - Kümelenmiş (clustered, primary) indeks: Ana dosya da indeksin arama anahtarına göre sıralıdır; aralık sorgusunda ana dosyada bir kez konumlanmak yeterlidir. İkincil (secondary) indekste ana dosya bu niteliğe göre sıralı değildir; aralıktaki her kayıt ayrı bir disk erişimi (disk I/O) gerektirebilir. İkincil indeks daha çok eşitlik ve dar aralıklı sorgularda işe yarar.
  - Sorgu iyileştirici (optimizer), değer dağılımına göre indeksi kullanıp kullanmayacağına karar verir; geniş bir aralıkta tüm dosyayı taramak daha ucuz olabilir. `EXPLAIN` ile sorgu planı görülebilir.
  - Her niteliğe indeks konmaz: İndeks bir fazlalıktır; ana tablodaki her ekleme, silme ve güncellemede indeksin de güncellenmesi gerekir. Sistem birincil anahtar üzerinde varsayılan olarak (B+ ağacı) indeks oluşturur, çünkü birincil anahtar kısıtını denetlemek (lookup) ve join'leri hızlandırmak için gerekir.
  - İleride işlenecek yapılar: B+ ağacı, hash indeksleri ve NoSQL sistemlerinin temel depolama yapısı LSM ağacı (Log-Structured Merge tree).

## Hocanın Özellikle Vurguladığı Kısımlar

- "Store" kelimesinin anlamı
  - NoSQL sistemleri geleneksel veritabanının karmaşık modüllerini gevşetir; bu yüzden "database" yerine "store" denir.
- Terminolojiyi bilmek
  - Her kategoride örnek sistem adları bilinmelidir: Doküman deposu deyince MongoDB, anahtar-değer deyince DynamoDB, çizge deyince Neo4j gibi.
- Kavramlar birbirini çağrıştırır
  - Ölçeklenebilirlik, yüksek performans, yük dengeleme, çoğaltma ve erişilebilirlik birbirine bağlıdır; çoğaltmadan sonra akla yazmalar ve tutarlılık gelmelidir. Hocaya göre bunlar sezgisel (intuitive) çıkarımlardır.
- ACID'e karşı BASE, nihai tutarlılık
- Doğru sistemi uygulamaya göre seçmek
  - Veritabanı sıralama sitelerindeki sıra bağlayıcı değildir; önemli olan uygulamanın ihtiyacıdır.
- MongoDB tasarımları normalizasyonla ilişkilidir
  - Gömülü tasarımlar fazlalık içerir, 1NF bile değildir; SQL'den ayrılma noktası modellemededir.
- İndeksler sistem performansının temelidir
  - Doğru kullanılan indeks sistemi binlerce kat hızlandırabilir: $\log_2 1024 = 10$, yani 1024 adımlık doğrusal arama 10 adıma iner.
  - Hangi indeksin seçileceği (index tuning) deterministik değildir.

## Kısa Tekrar Notları

- NoSQL: Büyük veri için dağıtık depolama; "Not only SQL"; `get`/`put`.
- Join gerekiyorsa uygulama yapar (paralel işleme).
- Küme + commodity makineler + yatay ölçekleme.
- Erişilebilirlik ← çoğaltma; çoğaltma → yazma problemi → nihai tutarlılık.
- Sharding = yatay bölümleme (aralık ya da hash).
- CAP: Üçünden en fazla ikisi. SQL: C; NoSQL: A ve P.
- ACID ↔ BASE.
- MongoDB: Koleksiyon ≈ tablo, doküman ≈ satır; JSON/BSON; usta-köle çoğaltma.
- Anahtar-değer: Değer bayt dizisi; tutarlı karma (halka).
- Sütun aileleri sabit, içindeki nitelikler esnek.
- Neo4j + Cypher.
- İndeks kaydı: Arama anahtarı + işaretçi.
- Sıralı indeks: Eşitlik + aralık, logaritmik. Hash: Yalnız eşitlik, çarpışma.
- Kümelenmiş indeks: Ana dosya da sıralı. İkincil indeks: Aralıkta çok disk erişimi.
- Birincil anahtara varsayılan B+ ağacı indeksi: Kısıt denetimi ve join.

## Detaylı Açıklamalar

- Neden join uygulamaya bırakılır?
  - Join'in yaptığı iş, farklı veri setlerindeki eşleşen satırları yakalamaktır. Veri normalizasyon ve bütünlük sebepleriyle dağıtılmıştır, aranan veri tek bir yerde olmayabilir. Büyük veri depoları "ben yalnız `put` ve `get` yaparım" der; birleştirme gerekiyorsa uygulama bunu veriyi parçalara ayırıp paralel algoritmalarla yapar.
  <!-- BELİRSİZ: Altyazıda "map ediyor ... Prodius gibi paralel algoritmalar" geçiyor (00:11:30-00:11:38); büyük olasılıkla MapReduce kastediliyor. -->
- Erişilebilirlik ve tutarlılık
  - Sosyal medyada bir paylaşılan videoyu hemen ya da bir saniye sonra görmek önemli değildir; banka hesabındaki para gibi değerli bir bilgi saklanmaz. Bu yüzden her an tam tutarlılıktan ödün verilerek sistemin her zaman hizmet vermesi sağlanır. İlişkisel sistemlerde de yalıtım (isolation) düzeyleriyle ACID'in gevşetilmesi mümkündür, ama istenirse %100'e yakın doğru çalışırlar. NoSQL'de böyle bir vaat yoktur; vaat nihai tutarlılıktır: Şu an tutarsız olabilir ama bu günlerce sürmez.
- MongoDB'de proje–işçi tasarımı
  - Birinci tasarımda her proje dokümanı içinde bir `workers` dizisi, dizinin içinde de işçi bilgileri vardır. Bir işçi birden çok projede çalışıyorsa bilgileri her projede tekrar eder. İkinci tasarımda proje dokümanında yalnız işçi kimlikleri dizi olarak tutulur, işçi bilgileri ayrı bir koleksiyondadır; fazlalık azalır ama dizi yüzünden yapı hâlâ 1NF değildir. Üçüncü tasarımda işçi dokümanları proje kimliğini taşır ve hiç dizi yoktur. Hoca, `(Id, Project)` birlikte anahtar olup `Ename`'in bunun bir parçasına bağlı olduğu yapının 2NF'ye aykırı olduğunu, normalizasyonda bunun parçalanarak çözüldüğünü, burada ise aynı yerde tutulduğunu vurguladı. Tasarım seçimi tamamen kullanıcıya, uygulamadan beklenen işlemlere bırakılmıştır.
- Tutarlı karma
  - Problem, kümedeki makinelere veriyi ölçeklenebilir biçimde dağıtmaktır: Yeni bir makine eklendiğinde, kapasitesine göre diğer makinelerden ne kadar yük alacağı belirlenmelidir. Anahtarlar hash'lenir; hash değer aralığı bir halka olarak düşünülür ve her makine halkanın bir aralığına atanır. Bir anahtarın hash değeri hangi aralığa düşüyorsa öğe o makineye yazılır. Makineler dolunca yeni bir makine halkada uygun noktalara yerleştirilir; o aralıklar komşu makinelerden alınır ve yük saat yönünde dağıldığı için yük dengeleme hash fonksiyonuyla kontrol edilmiş olur.
- İndeks kullanım örnekleri (derste sözlü)
  - `instructor` tablosunda `salary` üzerinde ikincil bir indeks varsa `WHERE salary BETWEEN 60000 AND 80000` ve `WHERE salary = 80000` bu indeksi kullanabilir; `WHERE ID = 20000` kullanamaz. `SELECT name ... WHERE salary ...` sorgusunda `name` üzerindeki bir indeksin anlamı yoktur, çünkü arama `WHERE` kısmında yapılır, `SELECT` iş bittikten sonra uygulanır. `salary = 60000` sorgusu indeksi mutlaka kullanır (sıralı indekste logaritmik arama, sonra tek bir yere atlama). `salary` 60.000 ile 200.000 arasında ise ve maaşlar zaten büyük ölçüde bu aralıktaysa, iyileştirici büyük olasılıkla indeksi kullanmaz, çünkü ana tabloda çok sayıda rastgele erişim (random access) gerekir; tüm dosyayı taramak daha ucuzdur.
  <!-- BELİRSİZ: Bu bölümde ekran paylaşılmadığı için indeks şekillerindeki kayıtlar ve değerler (15.151, 60.000 gibi) karede doğrulanamadı; değerler altyazıdan alındı (01:50:00-01:57:45). -->

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
