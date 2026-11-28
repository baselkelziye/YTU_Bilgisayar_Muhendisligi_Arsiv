# Ders 10 Çalışma Özeti

## Genel Konular

- Fiziksel tasarıma giriş: veri depolama ve indeks fikri
  - Derste ders kitabının (Database System Concepts, 7. baskı) 13. bölümü (Data Storage Structures) ve 14. bölümünün (Indexing) ilk slaytları işlendi (ekrandan, 00:10:00; 02:05:00). Konuların ileri kısmı veritabanı sistem gerçekleme dersine bırakıldı.
  - İlişkisel modeldeki tablolar arka planda dosyalarda saklanır. Bu dosyalar kullanıcının açıp okuyabileceği metin dosyaları değildir; veritabanı sisteminin kendi denetimindeki ikili (binary) dosyalardır ve hızlı erişim için belli bir düzende tutulur.
  - Çok büyük bir tablo parçalara bölünebilir (partitioning). Bölme satır esaslı (row-oriented) ya da sütun esaslı (column-oriented) olabilir.
  - İndeks benzetmesi: büyük bir kitapta bir kelime aranırken kitabın sonundaki küçük ve sıralı indekse bakılır, kelimenin yanında yazan sayfa numarasıyla doğrudan o sayfaya gidilir. Tablo da kitap gibidir; tablonun indeksi tabloya göre çok küçüktür, sıralıdır ve aranan değerin kaydının adresini verir.
- Disk sayfası (disk block, page)
  - Veri diskten her zaman disk sayfası birimiyle çekilir. 100 baytlık bir veri istense de içinde bulunduğu sayfanın tamamı gelir. İşletim sistemlerinde sayfa tipik olarak 4 KB'dir; PostgreSQL ve MS SQL'de varsayılan veritabanı sayfası 8 KB'dir.
  - Aynı içerik bulunduğu yere göre farklı adlar alır: diskte "disk block", ana bellekte "page", tampon havuzunda "buffer" ya da "frame".
  - Varsayım: kayıtlar bir disk bloğundan küçüktür (ekrandan, 00:10:00). 8-10 nitelikli bir tablonun kaydı tipik olarak 100-200 bayttır, yani 8 KB'lık bir sayfaya onlarca kayıt sığar.
  - CLOB/BLOB gibi büyük nesneler sayfayı aşabildiği için ayrı bir düzen gerektirir.
- Sabit uzunluklu kayıtlar (fixed-length records)
  - En kolay gerçekleme. i. kayıt $n \cdot (i-1)$ baytından başlar; $n$ kayıt boyudur (ekrandan, 00:25:00).
  - Bir sayfaya tam sayıda kayıt sığmayabilir. Ya kalan baytlar boş bırakılır ya da sonraki kaydın bir kısmı bu sayfaya, kalanı sonraki sayfaya yazılır (page spanning). Kayıt sayfadan büyükse page spanning kaçınılmazdır.
  - Silme seçenekleri (ekrandan, 00:35:00): (1) sonraki bütün kayıtları kaydırmak (shift), (2) son kaydı boşalan yere taşımak, (3) kayıtları taşımamak, boş yerleri dosya başlığındaki (header) bir işaretçiden başlayan bağlı liste (free list) ile izlemek.
  - Sabit uzunlukta güncelleme sorun çıkarmaz; yeni kayıt ilk boş yere konur, çünkü dosya sırasızdır.
- Değişken uzunluklu kayıtlar (variable-length records)
  - Bir dosyada birden fazla kayıt türü olduğunda ya da varchar gibi değişken uzunluklu alanlar olduğunda ortaya çıkar (ekrandan, 00:45:00).
  - Değişken alanlar kaydın başında sabit boyutlu (offset, uzunluk) çiftleriyle temsil edilir, asıl veri sabit uzunluklu alanlardan sonra gelir; null değerler null bitmap ile gösterilir.
  - Başka bir yol, nitelik değerlerinde geçmesine izin verilmeyen bir ayırıcı karakter (delimiter, örneğin # ya da *) kullanmaktır.
  - Slotted page yapısı (ekrandan, 00:50:00): blok başlığında kayıt sayısı, boş alanın sonu ve her kaydın konumu ile boyu tutulur. Kayıtlar sayfa içinde kaydırılabilir; bu yüzden dışarıdaki işaretçiler kayda değil başlıktaki girişe işaret etmelidir.
  - PostgreSQL büyük nesneler için TOAST adlı bir düzen kullanır: büyük değer ayrı bir alanda tutulur, kayıtta ona bir işaretçi kalır.
- Dosya organizasyonları (ekrandan, 00:55:00)
  - Heap: kayıt boş yer olan her yere konur, sıra yoktur.
  - Sequential: kayıtlar arama anahtarına (search key) göre sıralı tutulur. "Sorted file" ve "ordered file" da denir.
  - Multitable clustering: birden fazla tablonun kayıtları aynı dosyada tutulur.
  - B+ ağacı: ekleme ve silmelerde de sıralılık korunur.
  - Hashing: arama anahtarı üzerinde hesaplanan hash fonksiyonu kaydın hangi bloğa konacağını belirler.
- Heap dosyası ve boş alan haritası (ekrandan, 01:05:00)
  - Kayıtlar yerleştikten sonra genelde yer değiştirmez; önemli olan boş yeri hızlı bulmaktır.
  - Free-space map: blok başına bir giriş tutan dizi. Örnekte her giriş 3 bittir; değer/8 bloğun boş kısmını verir. İkinci düzey harita, birinci düzeyin dörder girişinin en büyüğünü tutar.
  - PostgreSQL'de boş alanlar VACUUM komutuyla belli aralıklarla toplanır; yoğun bir işlemden sonra elle de çalıştırılabilir.
- Sequential dosya
  - Kayıtlar arama anahtarına göre sıralıdır. Silmede işaretçi zincirleri kullanılır. Eklemede boş yer varsa oraya, yoksa taşma (overflow) bloğuna yazılır ve işaretçi zinciri güncellenir; kaydırma yapılmaz.
  - Böylece sıra mantıksal olarak korunur ama fiziksel olarak bozulur; dosya zaman zaman yeniden düzenlenmelidir. Hoca bunun PostgreSQL'de VACUUM ile yapılabileceğini söyledi.
  - Ders sonrası not: VACUUM boş alanı geri kazanır ama kayıtları sıralamaz; tabloyu bir indekse göre fiziksel olarak yeniden sıralayan komut büyük olasılıkla CLUSTER'dır.
- Multitable clustering dosya organizasyonu (ekrandan, 01:10:00)
  - department ve instructor kayıtları aynı dosyada, her bölüm kaydının hemen ardından o bölümün hocaları gelecek şekilde tutulur.
  - Bu iki tabloyu birleştiren (join) sorgular ve tek bölüm ile hocalarını isteyen sorgular için iyidir; yalnız department tablosunu tarayan sorgular için kötüdür. Kayıtlar değişken uzunluklu olur.
- Partitioning (ekrandan, 01:40:00)
  - Bir tablonun kayıtları ayrı saklanan daha küçük tablolara bölünür. Örnek: transaction tablosu yıllara göre transaction_2018, transaction_2019 vb.
  - Sorguda year = 2019 gibi bir seçim varsa yalnız bir bölüme bakılır. Boş alan yönetimi gibi işlemlerin maliyeti azalır. Bölümler farklı aygıtlarda saklanabilir: güncel yıl SSD'de, eski yıllar manyetik diskte.
- Veri sözlüğü (data dictionary, katalog)
  - Veri hakkında veri (metadata): tablo ve nitelik adları, türleri, görünüm tanımları, bütünlük kısıtları, kullanıcı bilgileri, istatistikler (nitelik değer dağılımları, histogramlar) ve her tablonun hangi dosya organizasyonunda, nerede saklandığı.
  - Katalog da ilişkisel tablolarla temsil edilir (ekrandan, 01:45:00): Relation_metadata, Attribute_metadata, Index_metadata, View_metadata, User_metadata.
  - Sorgu işlenirken önce kataloğa bakılır; örneğin yanlış yazılmış bir tablo adı optimizer devreye girmeden katalogda yakalanır.
- Depolama erişimi ve tampon (buffer) (ekrandan, 01:50:00)
  - Bloklar hem yer ayırma hem veri aktarım birimidir. 8193 baytlık bir tablo iki sayfa kaplar.
  - Amaç disk ile bellek arasındaki blok aktarım sayısını en aza indirmektir. Buffer, disk bloklarının kopyalarının tutulduğu bellek alanıdır; buffer manager bu alanı yönetir.
  - Tampon dolunca kurban sayfa seçilir. Yaygın algoritma LRU'dur; LRU-K, CLOCK ve veritabanına özgü algoritmalar da kullanılır. Katalog sayfaları çok sık erişildiği için tamponda öncelikli tutulur.
  - Kopya tutmak tutarlılık sorununu doğurur: bellekte güncellenmiş ama diske yazılmamış veri elektrik kesilince kaybolabilir; bunu kurtarma (recovery) modülü çözer.
- İndekslemeye giriş: temel kavramlar (ekrandan, 02:05:00)
  - Search key: bir dosyada kayıt aramak için kullanılan nitelik ya da nitelik kümesi. İndeks dosyası (search-key, pointer) biçiminde index entry'lerden oluşur ve genelde ana dosyadan çok küçüktür.
  - İki temel tür: ordered index (anahtarlar sıralı tutulur) ve hash index (anahtarlar hash fonksiyonuyla kovalara (bucket) dağıtılır).
  - Bir sorguda indeksin işe yaraması için indeksin WHERE koşulundaki nitelik üzerinde olması gerekir; SELECT listesinde erişilen nitelik değil, aramanın yapıldığı nitelik önemlidir.
- Sıralı indeksler (ekrandan, 02:10:00)
  - Clustering (primary) index: sıralı dosyada, arama anahtarı dosyanın sıralama düzenini belirleyen indeks. Arama anahtarı genelde ama zorunlu olarak değil birincil anahtardır. Bir dosyada en fazla bir tane olabilir.
  - Secondary (nonclustering) index: arama anahtarı dosyanın sırasından farklı bir düzen belirleyen indeks.
  - Index-sequential file: arama anahtarına göre sıralı ve bu anahtar üzerinde clustering index olan dosya.
- Dense ve sparse indeks
  - Dense index: dosyadaki her arama anahtarı değeri için bir indeks kaydı vardır (ekrandan, 02:15:00).
  - Sparse index: yalnız bazı değerler için kayıt vardır; yalnız dosya arama anahtarına göre sıralıysa uygulanabilir. Tipik olarak her blok için bloğun ilk değeri tutulur. Daha az yer kaplar ve bakımı ucuzdur ama kayıt bulmada genelde daha yavaştır, çünkü her aramada veri bloğuna gitmek gerekir.
  - Secondary index örneği: instructor tablosunun salary alanı üzerinde; her indeks kaydı, o değere sahip bütün kayıtların işaretçilerini tutan bir kovaya işaret eder. Secondary indeksler dense olmak zorundadır (ekrandan, 02:30:00).
- İndeksin maliyeti (ekrandan, 02:35:00)
  - İndeksler aramayı hızlandırır ama değişikliklere ek yük getirir: ekleme ve silmede tablodaki her indeks, güncellemede güncellenen nitelik üzerindeki her indeks güncellenmelidir.
  - Clustering index ile aralık taraması verimlidir. Secondary index ile her kayıt erişimi yeni bir blok çekebilir (manyetik diskte blok başına yaklaşık 5-10 ms); aralık büyüdükçe avantaj kaybolur.

## Hocanın Özellikle Vurguladığı Kısımlar

- İndeks = hızlı erişim
  - Kitap indeksi benzetmesi indeksin özüdür: küçük, sıralı bir yapıda aranır, bulunan adresle ana dosyadaki kayda doğrudan gidilir.
- B+ ağacı sıralama esaslı, hashing sıralamasız
  - B+ ağacı denince ilk akla gelmesi gereken sıralılıktır; bu yüzden aralık sorgularında (örneğin ortalaması 2 ile 2.3 arasındaki öğrenciler) başarılıdır. Hashing aralık sorgularında kullanılamayacak kadar verimsizdir, eşitlik sorgularında (ID = 100) avantajlıdır.
  - B+ ağacı veritabanı sistemlerinin merkezinde olan, onsuz veritabanı kullanılamayacak bir yapıdır ve hashing'e göre çok daha yaygındır.
- Hiçbir dosya organizasyonu her zaman en iyi değildir
  - WHERE koşulu olmayan bir sorguda tablo taraması yapılır, indeks gerekmez; ORDER BY varsa sequential dosya, yoksa heap dosya daha iyidir. Hangi yapının seçileceğine sorgu optimizasyonu (optimizer, planner) karar verir.
- Search key WHERE koşulundadır
  - SELECT name FROM instructor WHERE salary > 10000 sorgusunda arama salary üzerindedir; işe yarayacak indeks salary indeksidir, name indeksi değildir.
- İndeks küçük tablolarda fayda sağlamaz
  - Birkaç yüz kayıtlık tabloda indeks bir şey değiştirmez; ihtiyaç tablo onlarca MB'a, binlerce kayda ulaşınca ortaya çıkar.
- İndeksin dezavantajı
  - İndeks veri tekrarıdır; indekslenmiş nitelik güncellenince indeks de güncellenmelidir. Bu, güncelleme performansını ve sistemin karmaşıklığını etkiler.
- Kavram düzeyi yeterli
  - Konular çok kapsamlıdır; ayrıntıya girilmedi ama indeksin ne olduğu ve amacı bilinmelidir.

## Kısa Tekrar Notları

- Tablo = dosya = disk sayfaları = kayıtlar = nitelikler.
- Disk ile bellek arası aktarım birimi sayfadır (veritabanında varsayılan çoğunlukla 8 KB).
- Sabit uzunluklu kayıt: i. kayıt $n(i-1)$ baytında başlar. Silme: kaydır, son kaydı taşı ya da free list.
- Değişken uzunluklu kayıt: (offset, uzunluk) çiftleri + null bitmap ya da ayırıcı karakter; sayfa düzeyinde slotted page.
- Dosya türleri: heap, sequential, multitable clustering, B+ ağacı, hashing.
- Heap: free-space map; sequential: overflow bloğu ve işaretçi zinciri, zaman zaman yeniden düzenleme.
- Partitioning: satır ya da sütun esaslı bölme; sorgular tek bölüme yönelir.
- Katalog: metadata da ilişkisel tablolarda tutulur, ilk bakılan yerdir.
- Buffer: disk bloklarının bellekteki kopyaları; kurban seçimi LRU vb.
- Clustering (primary) index: dosya da aynı anahtara göre sıralı, tek tane olabilir. Secondary index: dosya o anahtara göre sıralı değil, dense olmalı.
- Dense: her değer için giriş. Sparse: blok başına bir giriş, yalnız sıralı dosyada.
- İndeks okumayı hızlandırır, yazmayı yavaşlatır.

## Detaylı Açıklamalar

- **Disk sayfası neden önemli?** Bir sorgu yalnızca bir öğrencinin adını istese de sistem o kaydın bulunduğu 8 KB'lık sayfanın tamamını okur. Bu yüzden fiziksel tasarımın amacı okunan sayfa sayısını azaltmaktır. Bir kaydın adresi iki parçadan oluşur: hangi blokta olduğu ve blok içindeki konumu (offset). Hoca bunu instructor tablosundaki 33456 numaralı kaydın bölümünü bulma örneğiyle anlattı: indeks "ikinci blokta, şu konumda" der, sistem o bloğu okuyup o konuma gider. İndeksin bu adresi nasıl bulduğu derste "kapalı kutu" olarak bırakıldı ve sonraki konulara ertelendi.
- **Page spanning örneği.** Hoca gerçekçi olmayan küçük değerlerle anlattı: sayfa 300 bayt, kayıt 80 bayt olsun. Bir sayfaya 3 kayıt (240 bayt) sığar, 60 bayt boş kalır. Boş kalmasın denirse dördüncü kaydın 60 baytı bu sayfaya, kalan 20 baytı sonraki sayfaya yazılır. Böylece yer kaybı olmaz ama bir kayıt iki sayfaya dağılmış olur.
- **Sabit uzunluklu kayıtta adres hesabı.** Slayttaki instructor tablosu (ID, name, dept_name, salary) 12 kayıttan oluşur (record 0 - record 11) (ekrandan, 00:25:00). Kayıt boyu $n$ ise i. kayda $n \cdot (i-1)$ ofsetiyle doğrudan gidilir. <!-- BELİRSİZ: Hoca kayıt boyunu nitelik boyutlarından 28 bayt olarak hesapladı, ama hangi niteliğe kaç bayt verdiği altyazıda net değil. -->
  > **Ders sonrası not:** Hoca 5. kayda "28×5" ofsetiyle gidileceğini söyledi. Kayıtlar slayttaki gibi 0'dan numaralanırsa "record 5" gerçekten $28 \cdot 5 = 140$. bayttan başlar. Slayttaki $n \cdot (i-1)$ formülü ise kayıtları 1'den numaralar; bu numaralamayla 5. kayıt $28 \cdot 4 = 112$. bayttan başlar.
- **Free list.** Sabit uzunluklu dosyada silinen kayıtlar yerinde bırakılır. Dosya başlığındaki işaretçi ilk boş kayda (örnekte record 1), o kayıt bir sonrakine (record 4), o da sonrakine (record 6) işaret eder (ekrandan, 00:35:00). Yeni kayıt dosyanın sonuna değil bu boşluklara yazılır. Amaç dosyayı yekpare tutmaktır; boşluklar arttıkça kayıtlar diskin farklı sayfalarına dağılır ve arama yavaşlar.
- **Değişken uzunluklu kayıt örneği.** Slayttaki kayıtta ilk üç giriş (21, 5), (26, 10), (36, 10) çiftleridir; sonra 12. baytta sabit uzunluklu salary (65000), 20. baytta 1 baytlık null bitmap (0000), ardından değişken alanların verisi gelir: 21. baytta 10101, 26. baytta Srinivasan, 36. baytta Comp. Sci. (ekrandan, 00:45:00). Her çiftte ilk sayı ofset, ikincisi uzunluktur; hoca bunları iki short integer (2'şer bayt) olarak açıkladı. Başka bir kayıtta bu sayılar değişir.
- **varchar ve sabit uzunluklu gerçekleme.** varchar(100) alana kısa değer girilince fiziksel olarak yalnız girilen kadar yazılması yer kazandırır ama dosya yönetimini karmaşıklaştırır. Hoca, varchar küçükse sistemlerin onu içeride sabit uzunluklu gerçekleyebileceğini tahmin ettiğini söyledi; bu son kullanıcıyı etkilemez ama performansı etkileyebilir.
- **Boş alan haritası örneği** (ekrandan, 01:05:00). Birinci düzey harita: 4 2 1 4 7 3 6 5 1 2 0 1 1 0 5 6. Her değer 3 bittir, değer/8 o bloğun boş kısmıdır (7 → bloğun 7/8'i boş). İkinci düzey harita dörder girişin en büyüğünü tutar: max(4,2,1,4)=4, max(7,3,6,5)=7, max(1,2,0,1)=2, max(1,0,5,6)=6, yani 4 7 2 6. Harita diske belli aralıklarla yazılır; bazı girişlerin eski (yanlış) olması kabul edilir, sonradan fark edilip düzeltilir.
- **Multitable clustering örneği** (ekrandan, 01:10:00). Ortak dosyada sıra şöyledir: Comp. Sci. bölüm kaydı (Taylor, 100000), ardından o bölümün hocaları 10101 Srinivasan, 45565 Katz, 83821 Brandt; sonra Physics bölüm kaydı (Watson, 70000) ve hocası 33456 Gold. "Comp. Sci. bölümündeki hocalar" gibi sorgular tek bir bölgeden okunur.
- **Katalog tabloları** (ekrandan, 01:45:00):
  - Relation_metadata(relation_name, number_of_attributes, storage_organization, location)
  - Attribute_metadata(relation_name, attribute_name, domain_type, position, length)
  - Index_metadata(index_name, relation_name, index_type, index_attributes)
  - View_metadata(view_name, definition)
  - User_metadata(user_name, encrypted_password, group)
  - Hoca, katalogda nitelik değer dağılımları ve histogramlar gibi istatistiklerin de tutulduğunu, bunların sorgu planlayıcısının kullandığı kritik bilgiler olduğunu ekledi.
- **Disk ve bellek farkı.** Hoca disk erişiminin ana bellek erişiminden yaklaşık 100.000 kat yavaş olduğunu, bunun birkaç saniyelik işi bir günde yapmak gibi olduğunu söyledi. Tampon havuzu bu yüzden vazgeçilmezdir ama veri kopyası tutulduğu için tutarlılık ve kurtarma sorunları getirir.
- **Clustering index ve sıralılığın faydası.** Sıralı bir indekste ikili arama (binary search) yapılabilir: her adımda arama kümesinin yarısı elenir, $\log_2 N$ adımda sonuca varılır. Milyonlarca kayıtta bu, disk erişim sayısını çok azaltır. Dense index örneğinde instructor tablosu ID'ye göre sıralıdır ve her ID için bir indeks girişi vardır (ekrandan, 02:15:00); indeks ile dosya aynı anahtara göre sıralı olduğu için işaretçiler birbirine paraleldir. Bu yüzden bu bir clustering index, dosya da index-sequential dosyadır.
- **Sparse index ile arama.** Sparse index'te her blok için bloğun ilk değeri tutulur. Aranan değer indekste yoksa ondan küçük en büyük giriş bulunur ve o bloğa gidilip blok içinde aranır. Hoca 15151 aramasını örnek verdi: indekste 15151 yoktur, ama 10101 ile 32343 arasında olduğu için 10101 girişinin bloğuna gidilir. <!-- BELİRSİZ: Sparse index slaydı karelerde tam görünmüyor; değerler hocanın anlatımından ve önceki dense index slaydından alındı. --> Kaydın var olup olmadığı dense indekste indeksin kendisinden anlaşılır; sparse indekste ise mutlaka veri bloğuna gitmek gerekir.
- **Secondary index örneği** (ekrandan, 02:30:00). instructor dosyası ID'ye göre sıralıdır, indeks ise salary üzerindedir: 40000, 60000, 62000, 65000, 72000, 75000, 80000, 87000, 90000, 92000, 95000. İşaretçiler dosyada dağınık yerlere gider, birbirini keser. 80000 maaşı iki hocada (Singh ve Kim) bulunduğu için her indeks girişi, o değere sahip bütün kayıtların işaretçilerini tutan bir kovaya işaret eder.
- **Aralık sorgusunda clustering ve secondary index.** Clustering index aralığın başlangıcını hızla bulur, sonra kayıtlar fiziksel olarak bitişik olduğu için sıralı erişimle (sequential access) okunur. Secondary index'te her kayıt farklı bir bloğa düşebilir; rastgele erişim (random access) sıralı erişimden pahalıdır ve aralık büyüdükçe secondary indeksin avantajı kaybolur. Hiç filtre yoksa en iyisi indeks kullanmadan tabloyu baştan sona taramaktır.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
