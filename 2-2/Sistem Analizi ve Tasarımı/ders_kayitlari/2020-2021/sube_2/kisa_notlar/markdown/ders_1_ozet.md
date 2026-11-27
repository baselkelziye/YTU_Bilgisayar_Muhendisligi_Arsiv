# Ders 1 Çalışma Özeti

## Genel Konular

- Dersin konu akışı (ekrandaki ders planından, 00:15:00 ve 00:20:00)
  - Giriş ve sistem tanımı; sistem tipleri, bilgi sisteminin tarafları (paydaşlar), sistem geliştirme süreci (şelale/waterfall modeli).
  - Ön inceleme ve fizibilite (yapılabilirlik) çalışmaları, zaman fizibilitesi.
  - Sistem analizi: veri toplama, iş analizi, kullanım senaryoları (use case); veri modelleme ve fonksiyonel (işlevsel) çözümleme, veri akış diyagramları; nesneye yönelik çözümleme.
  - Sistem tasarımı: mimari tasarım (yapı diyagramları, ardışıl diyagramlar); girdi, çıktı, veri yapısı ve arabirim tasarımları.
  - Veritabanı tasarımına giriş, kodlama, test süreçleri, yeni sisteme geçiş, bakım ve destek süreçleri; örnek bir analiz-tasarım vaka çalışması.
- Bilgi neden önemli? (ekrandan, 00:40:00)
  - İnsan ve hammadde kaynakları önemlidir; günümüzde en önemli kaynak bilgidir. Bilginin doğru kullanımı rekabet gücünü artırır.
  - Bilginin üretimi, dağıtımı, işlenmesi, güvenliği ve depolanması ayrı ayrı ele alınması gereken başlıklardır.
  - Makineler ve sensörler (IoT) elle üretilen veriden çok daha fazlasını üretir; verinin organizasyonu ve kullanım maliyetleri artmıştır. Çözüm bilgi sistemleridir.
- Veri ve bilgi farkı
  - Anlamlandırılmamış ham değerler veridir; anlamlandırılmış veri bilgidir.
  - Hava istasyonu örneği: saatte binlerce sıcaklık/nem değerini yalnız grafik olarak göstermek az iş yapmaktır; eğilimlerden "yarın yağmur yağabilir" gibi amaca yönelik uyarı üretmek veriyi bilgiye dönüştürmektir.
- Bilgi sistemi ile bilgisayar programı farkı
  - Program tek bir problemi bir algoritmayla çözer (yüzlerce-binlerce satır).
  - Bilgi sistemi bütüncüldür: binlerce-milyonlarca satır kod, onlarca-yüzlerce algoritma, modüler ve genişletilebilir yapı, ortak ya da ayrı veri ve bir süreç yönetimi gerektirir.
- Sistemin tanımı (ekrandan, 00:50:00)
  - Belli bir amacı gerçekleştirmek için bir arada çalışan, birbiriyle ilişkili parçalardan oluşan, girdi ve çıktıları olan, sınırları belirlenmiş bütün yapı/oluşum/çözüm.
  - Şekildeki elemanlar: ortam, girdi, çıktı, bileşen, ilişki, sınır, arabirim.
- Sistemin temel özellikleri (ekrandan, 00:55:00)
  - Bileşenler, değişkenler, parametreler, ilişkiler, sınır, arabirim, kısıtlar, ölçüt, ortam ve geri besleme.
- Sistem ve ortam (ekrandan, 01:00:00)
  - Sistem ortama bağlıdır, aralarında doğrudan ya da dolaylı ilişki vardır; sistem ortamda değişiklik yapabilir.
  - İç içe yapı: şehir ⊃ cadde ⊃ bina ⊃ ısıtma, enerji, güvenlik, aydınlatma ve su sistemleri.
- Sistem örnekleri
  - Ev sinema sistemi (ekrandan, 01:05:00), restoran, fabrika bilgi sistemi (ekrandan, 01:20:00), üniversite öğrenci bilgi sistemi.
- Bilgi sistemi tanımı ve bileşenleri (ekrandan, 01:10:00 ve 01:15:00)
  - İşletmenin ihtiyaçlarını desteklemek için veri toplayan, işleyen, depolayan; insan, veri, süreçler ve bilgi teknolojilerinin etkileşimde bulunduğu yapı.
  - Beş bileşen ailesi: donanım, yazılım, insan, veri ve ağ kaynakları.
- Genel sistem teorisi (ekrandan, 01:25:00)
  - Yedi ilke: girdiyi çıktıya dönüştürme, disiplinler arasılık, elemanlar arası etkileşim, farklı elemanlardan oluşma, hiyerarşi, ortama göre düzenlenme, amaç yönelimlilik.

## Hocanın Özellikle Vurguladığı Kısımlar

- Sınırın belirlenmesi
  - Neyin sistemin içinde, neyin dışında olduğuna sistem tasarlanırken en başta karar verilmelidir. Hoca sınırı "belki de en önemli hususlardan biri" olarak niteledi.
- Bilgi sistemi yalnız yazılım değildir
  - Donanım, yazılım, insan, veri ve ağ kaynakları birlikte bilgi sistemini oluşturur; "sadece kod" diye düşünülmemelidir.
- Kısıtlar işlevsel olmayan gereksinimlerin temelidir
  - Dosya tipi ya da bellek sınırı gibi kısıtlar ileride işlevsel olmayan gereksinimleri oluşturacak ve tasarımı etkileyecektir.
- Geri besleme
  - Temel özellik listesinde her zaman yer almasa da hoca onu "artık olmazsa olmaz" saydı: çıktıların ölçülüp girdiler ya da sistem üzerinde iyileştirme yapılmasıdır.
- Gereksinim değişirse sistem değişir
  - Aynı işi yapan farklı sistem alternatifleri vardır (televizyon yerine projeksiyon ve perde gibi); hangisinin seçileceğini gereksinimler belirler.
- Her sistemin bir amacı olmalıdır
  - "Bir şey yaptım ama hiçbir şey yapmıyor" olamaz; amaçsız sistem tasarlanmaz.
- Büyük resim
  - Bu derste artık tek bir algoritma değil, problemin yapılabilirliğinden başlayıp gerçekleştirmeye kadar giden bütün süreç ve büyük resim modellenir; akış diyagramları ve algoritmalar bileşenlerin içindeki küçük parçalar olarak kalır.

## Kısa Tekrar Notları

- Veri: ham, anlamlandırılmamış; bilgi: işlenmiş, anlamlandırılmış veri.
- Sistem = amaç + ilişkili parçalar + girdi/çıktı + belirlenmiş sınır.
- Ortamdan alınan girdi, ortama verilen çıktıdır; sistemin ortamla ya da diğer sistemlerle bilgi/veri alışverişi yaptığı noktalar arabirimdir.
- Değişken: farklı değer alabilen özellik; parametre: sabit değer; ilişki: bileşenlerin değişken ve parametrelerle bağlantısı.
- Kısıt: değişken değerleri ve kaynak tahsisi sınırlamaları (ör. bellek üst sınırı).
- Ölçüt: hedefe ne kadar ulaşıldığını değerlendirmek için eşik/standart (ör. saniyede işlenen kayıt sayısı).
- Ortam: sistemin tümleyeni, sistem dışındaki her şey.
- Sistemler hiyerarşiktir: her sistemin alt ve üst sistemleri vardır; en küçük parçaya bileşen denir.
- Bilgi sistemi bileşenleri: donanım, yazılım, insan, veri, ağ kaynakları.
- Bazı insan kaynağı görevleri (ör. ağ trafiğini izleyip alarm üretme) yazılım ya da donanım bileşenleriyle yer değiştirebilir.
- Aynı veriyi kullanan bilgi sistemi farklı taraflara farklı çıktılar üretebilir.
- Entropi, sistemin ortamla ilişkisini belirler; bir ortam için yazılmış sistem başka ortamda dönüşüm ya da adaptör olmadan çalışmaz.

## Detaylı Açıklamalar

- **Sistem kelimesinin anlamı.** Hoca sözlük tanımından yola çıktı: sistem düzen, bir sonuç elde etmeye yarayan yöntemler düzeni, yol-yöntem, bir aracı oluşturan düzenek/tertibat (fren sistemi örneği) ve dizge anlamlarına gelir. Bunlardan çıkan ortak fikir: bir düzen içinde çalışan, çeşitli parçalardan oluşan, bir çıktı üreten ya da bir sorunu çözen, bir hizmet veren yapı. <!-- BELİRSİZ: Sözlük tanımının gösterildiği slaytın karesi yok; maddeler altyazıdan alındı. -->

- **Bilginin doğru kullanımı.** En önemli kaynak bilgidir; ama sahip olunan bilgi doğru kullanılmazsa fayda sağlamaz. Bilgiyi doğru kullanmak için şu başlıklar ele alınır: bilgi nasıl üretilecek (elle ya da makinelerle, IoT), nasıl dağıtılacak, nasıl işlenecek (sonuç ve hizmet üretecek şekilde), güvenliği nasıl sağlanacak (kişisel verilerde KVKK gibi yasal yaptırımlar), nerede ve nasıl depolanacak (yerelde, bulutta, kopyalı ya da kopyasız). Depolama ve işleme maliyetleri de veri büyüdükçe artar.

- **Program ve bilgi sistemi.** Önceki derslerde bir problem için algoritma geliştirip veri yapılarıyla birleştirerek küçük problemleri çözen programlar yazıldı. Bilgi sisteminde fark önce boyuttadır; ama yalnız boyut değil, çözülen problemin çok yönlülüğü de farklıdır. Birden çok algoritmanın bir arada doğru çalışması, modüler ve yeni modül eklenebilir bir yapı, verinin ortak ya da ayrı kullanımı tasarlanmalıdır. Bu da bir süreç yönetimi gerektirir.

- **Sistemin şekli.** Slayttaki şekilde (ekrandan, 00:50:00) kapalı bir eğri sistemin sınırıdır; eğrinin dışı ortamdır. Ortamdan sisteme bir ok girer (girdi), sistemden ortama bir ok çıkar (çıktı). İçeride birkaç küçük şekil bileşenleri, bunlar arasındaki çift yönlü ok ilişkiyi, sistemin ortamla temas ettiği nokta arabirimi gösterir. Arabirim her sistemde olmak zorunda değildir, ama bilgi sistemlerinde neredeyse olmazsa olmazdır.

- **Temel özellikler** (ekrandan, 00:55:00):

  | Özellik | Slayttaki tanım |
  |---|---|
  | Bileşenler | Sistemi oluşturan parçalar |
  | Değişkenler | Değişik değer alan özellikler |
  | Parametreler | Sabit değerler |
  | İlişkiler | İlk üç madde arasındaki bağlantılar |
  | Sınır | Sistem için ortam ayracı |
  | Arabirim | Ortam veya alt sistemlerle karşılaşma noktası |
  | Kısıtlar | Değişken değerleri ve kaynak tahsis sınırlamaları |
  | Ölçüt | Hedef-amaçların değerlendirme standardı |
  | Ortam | Sistem dışındaki her şey |
  | Geri besleme | Çıktı kontrolü ve ölçme-değerlendirme ile girdiler ve sistem üzerinde iyileştirme yapma aracı |

  Kısıt örnekleri: "yalnız belirli dosya tipleri girdi olarak kabul edilir", "sistem 1024 MB'den fazla bellek kullanmaz". Ölçüt örneği: bir ders kayıt sisteminin saniyede 100 kayıt mı yoksa 1 milyon kayıt mı işleyeceği; sistemin beklentiyi karşılayıp karşılamadığına bu eşiklerle karar verilir.

- **Sistem ve ortam, hiyerarşi.** Slayttaki iç içe kutular (ekrandan, 01:00:00): en dışta ŞEHİR, içinde CADDE, içinde BİNA; binanın içinde ISITMA SİSTEMİ, ENERJİ SİSTEMİ, GÜVENLİK SİSTEMİ, AYDINLATMA SİSTEMİ ve SU SİSTEMİ. Isıtma sistemi ortamdan (başka bir sistemin arabiriminden) doğalgaz alır, ısı üretir ve böylece ortamını, yani binayı değiştirir. Güvenlik sisteminde duman dedektörü dumanı girdi olarak alır, çıktı olarak alarm verir. Aydınlatma, enerji sisteminin alt sistemi olarak da düşünülebilir. Hoca bu yapıyı fakülte, kampüs, şehir, ülke, kıta, dünya, güneş sistemi diye yukarı doğru genişletti: her ortam kapsadığı sistemler için bir ortamdır.

- **Ev sinema sistemi** (ekrandan, 01:05:00). Bileşenler: televizyon/monitör, amfi, DVD/Blu-ray oynatıcı, hoparlörler, koltuklar; sınır odanın duvarlarıdır. Odada ayrıca bir aydınlatma sistemi (spot lambalar) vardır. Koltuk sistem olarak modellenemeyecek kadar küçük bir parça, yani bileşendir. Oynatıcı ise ev sineması için bir bileşen olsa da kendi içinde tam bir sistemdir: elektrik ve disk girdisini alır, kodlamayı çözer, görüntü sinyali üretir ve bunu bir arabirimle (ör. HDMI) görüntü sistemine aktarır. Hoparlör elektrik sinyalini ses sinyaline dönüştürür. İzleyen kişi de bu sistemin bir tarafıdır ve aynı anda kendi içindeki sistemler çalışır. Televizyon yerine projeksiyon ve perde konursa aynı işi yapan bir sistem alternatifi elde edilir; hangisinin seçileceğini gereksinim (ör. "65 inç olacak" ya da "görüntü olabildiğince büyük olacak") belirler.

- **Restoran örneği.** Bileşenler: depo, mutfak, büro, müşteri hizmetleri, yemek salonu. Girdiler: malzemeler (sebze, meyve, et), para, aletler. Çıktı: yiyecekler. Taraflar: yöneticiler, aşçılar, garsonlar, müşteri hizmetleri çalışanları; dışarıda tedarikçiler ve müşteriler. <!-- BELİRSİZ: Restoran slaytının karesi yok; liste altyazıdan alındı. -->

- **Bilgi sistemi ve bileşenleri** (ekrandan, 01:10:00 ve 01:15:00). Bilgi sistemleri genellikle işletme odaklıdır ama her zaman öyle olmak zorunda değildir. Beş bileşen ailesi:
  - Donanım kaynakları: sunucu, bilgisayar, monitör, klavye, yazıcı, tablet, barkod okuyucu vb.
  - Yazılım kaynakları: veri düzenleme, işleme, analiz programları ve bunlara ait süreçler ve yordamlar; yalnız bizim yazdığımız kod değil, hazır kütüphane, uygulama, servis, hatta hazır bir sistem de olabilir.
  - İnsan kaynakları: bilgi sisteminin sahibi, tasarlayanlar, kuranlar, kullananlar, işletenler, bakım yapanlar.
  - Veri kaynakları: sistemin kullandığı ve ürettiği verileri tutan veritabanı ve bilgi tabanı (NoSQL, büyük veri ortamları, bulut).
  - Ağ kaynakları: işletme içi ve dışı birimlerin bilgi sistemine bağlanma yapıları.

- **Fabrika bilgi sistemi örneği** (ekrandan, 01:20:00). Alt sistemler ve aralarındaki akışlar:

  ```text
  Sipariş alt sistemleri --(Sipariş, Sipariş Karşılama)--> Ürün stok alt sistemi
  Ürün stok alt sistemi  --(Siparişleri Yerine Koyma)----> Ürün planlama alt sistemi
  Ürün planlama alt sistemi --(Program)--> Üretim alt sistemi
  Üretim alt sistemi --(Bulunabilirlik)--> Ürün planlama alt sistemi
  Ürün planlama alt sistemi --(Talep)--> Ürün ve hammadde stok alt sistemi
  Ürün ve hammadde stok alt sistemi --(Bulunabilirlik)--> Ürün planlama alt sistemi
  ```

  Her alt sistem kendi içinde bir bilgi sistemi olabilir; birlikte, birer bileşen gibi çalışarak fabrika yönetim sistemini oluştururlar.

- **Üniversite öğrenci bilgi sistemi örneği.** Bu tür bir sistemde giriş/kimlik doğrulama alt sistemi kullanıcıyı tanır, yetkilendirir ve kullanabileceği modülleri gösterir; doğrulama için dış bir servisi arabirimle kullanabilir. Ders seçimi ve not girişi ayrı alt sistemlerdir: öğrenci ders seçer ama not giremez, öğretim üyesi not girer ama ders seçemez. Not girişi için dersin, bölümün ders tanımlama modülünden tanımlanmış olması ve öğrencilerin ders kayıt bilgisinin alınması gerekir; ardından not hesaplama süreçleri çalışır. Öğrenciye yalnız kendi notları gösterilir: aynı veriden farklı taraflara farklı çıktılar üretilir.

- **Genel sistem teorisi** (ekrandan, 01:25:00):
  - Sistem girdiyi çıktıya dönüştürür (bilgi sisteminde veri → bilgi).
  - Sistemler disiplinler arasıdır (bir daldaki ürün başka dalda kullanılabilir).
  - Sistem elemanları arasında etkileşim vardır (bir parçadaki etki diğer parçaları da etkiler).
  - Sistemler farklı elemanlardan oluşur (taşımacılık → demiryolu, denizyolu, havayolu; gereksinime göre biri ya da hibrit bir karışım seçilir: ucuzluk için deniz yolu, hız için hava yolu).
  - Sistemler hiyerarşiktir (her sistemin altında ve üstünde sistemler vardır).
  - Sistem ortama göre düzenlenmelidir (entropi ortamla ilişkiyi belirler; bir işletim sistemi için yazılmış bir sistem diğerinde dosya sistemi, ağ ve G/Ç farkları yüzünden dönüşüm ya da adaptör olmadan çalışmaz; tek sunucuda çalışan monolitik bir uygulama ile bulutta ya da konteyner mimarisinde çalışacak bir sistemin tasarımı farklıdır).
  - Sistem amaç yönelimlidir (her sistemin belli bir amacı vardır).

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
