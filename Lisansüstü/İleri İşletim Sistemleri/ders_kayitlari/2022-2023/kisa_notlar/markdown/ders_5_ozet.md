# Ders 5 Çalışma Özeti

## Genel Konular

- Dersin biçimi: iki makalenin soru-cevap ile tartışılması
  - Öğrencilerin önceden okuduğu iki makale tartışıldı: DEMOS işletim sisteminde görevler arası haberleşme (task communication) ve DEMOS/MP'de proses göçü (process migration).
  - Kayıtta ekranda slayt ya da makale paylaşılmadı. Bütün bilgiler sözlü anlatımdan ve hocanın makaleden sesli okuduğu cümlelerden alınmıştır.
- DEMOS: mesaj aktarımına dayalı görevler arası haberleşme
  - Makale "proses" yerine "task" (görev) terimini kullanır. Haberleşme mesaj aktarımı (message passing) temellidir.
  - Görevler arası haberleşme için kullanılan sistem çağrılarına topluca "messages" (mesajlar) adı verilir. Bunlar dosya açma, yazma, ekrana yazma gibi bilinen sistem çağrılarıdır; haberleşmeyi sağladıkları için bu adı alırlar.
  - Link (bağlantı): mesajların bir görevden diğerine gittiği tek yönlü yoldur. Tipik bir link kullanıcı tarafındaki görevde başlar, çekirdekte (kernel) biter.
- Görev haberleşmesinin sağlaması gereken üç işlev
  - Birincisi: görev oluşturulurken, görevin istemesine gerek kalmadan bazı standart linkler verilir (örneğin dosya sistemine ya da konsola erişim için). Bu, proseslere standart girdi, çıktı ve hata tanımlayıcılarının verilmesine benzer.
  - İkincisi: birbirinden habersiz (arbitrary and unrelated) iki görevin karşılıklı rızayla (mutual consent) haberleşebilmesi. Bunu aradaki switchboard (santral) görevi sağlar. Var olan linkler üzerinden mesajla birlikte yeni linkler aktarılabilir ("passing links along with messages over existing links").
  - Üçüncüsü: bir görevin başka bir görevi ya da görev grubunu sarabilmesi. Bu, hata ayıklama (debugging) ve izleme (monitoring) için kullanılır; bu işleve instrumentation ya da mediation denir.
- Cray-1'de bellek koruması ve mesaj tabanlı tasarım
  - Makaledeki sistemde (Cray-1) tek bir base ve limit yazmaç çifti vardır. Bu zayıf koruma, görevlerin birbirinin belleğine erişmeyip yalnız mesajla haberleştiği bir tasarıma uygundur.
  - Base/limit koruması görevlerin hem bütünlüğünü hem gizliliğini korur, ama katı uygulanırsa global (paylaşılan) değişken erişimini ortadan kaldırır. Bu yapı dağıtık işlemenin (distributed processing) de temelidir.
  - Mesajlaşmanın yetmediği durumlar için linkler üzerinden paylaşılan veri alanlarının adresleri aktarılabilir. Makaleye göre birden fazla görevin belleğine aynı anda donanım erişimi gereken tek parça çekirdektir; mesaj ve veri aktarımı link kavramında birleştirilir.
- Link türleri ve link yönetimi
  - Bir öğrencinin aktarımıyla dört link türü: request, reply, resource ve general. Reply linki yalnız bir kez kullanılır ve kullanıldıktan sonra çekirdek tarafından yok edilir.
  - Linkler tek yönlüdür. İki görev karşılıklı haberleşecekse iki link gerekir; iki ters yönlü link birlikte bir kanal oluşturur.
  - Dosya açma örneği üzerinden resource link: dosya sistemi açılan dosyayı temsil eden bir resource linki kendisine oluşturur ve reply linki üzerinden görev A'ya aktarır. Sonunda görev A'nın dosya sistemine iki linki olur (standart request linki ve resource link); dosya sisteminin görev A'ya linki kalmaz.
  - Link yönetimi: ölmüş ya da sonlanmış görevleri gösteren linklerin kullanılmasının engellenmesi, linklerin çoğaltılması ve koruma bayrakları. Ölü bir görevden cevap bekleyerek sonsuza kadar beklemeye karşı basit bir önlem olarak zaman aşımı (timeout) önerilir.
  - Bypass link: izleme yapan bir görev araya girdiğinde büyük veri aktarımları izleyici üzerinden geçmesin diye veri kısmı için ayrı bir bağlantı verilir.
- DEMOS/MP: proses göçü
  - Proses göçü, çalışan bir prosesin durdurulup başka bir işlemciye aktarılması ve orada kaldığı yerden devam etmesidir.
  - Amaçları: işlemciler arasında yük dengeleme, prosesi eriştiği kaynağa yaklaştırarak haberleşme maliyetini azaltma, işlemci hatası tespit edildiğinde ya da öngörüldüğünde hata toleransı.
  - Makale göçü sekiz adımda tanımlar: prosesi yürütmeden çıkarma (in migration olarak işaretleme), hedef çekirdeğe sorma, hedefte proses durumu için yer ayırma, durumun aktarılması, programın (kod, veri, yığın) aktarılması, bekleyen mesajların iletilmesi, kaynak işlemcideki durumun temizlenmesi (geride bir iletme adresi bırakılarak) ve prosesin yeniden başlatılması.
  - "In migration" ayrı bir durumdur: proses run queue'dan çıkarılır ama kayıtlı durumu (running, ready, suspended) değiştirilmez; böylece hedefte birebir aynı durumdan devam eder.
  - Mesaj iletme (message forwarding) kritiktir: eski konuma gelen mesajlar yeni konuma yönlendirilmezse prosesle haberleşen diğer prosesler havada kalır.
- Gevşek bağlı (loosely coupled) ve sıkı bağlı (tightly coupled) sistemler
  - DEMOS tek işlemcili bir yapıda çalışır; DEMOS/MP (multiprocessor) birden fazla işlemcinin gevşek bağlı olduğu bir yapıdır.
  - Sıkı bağlı: işlemciler belleğe doğrudan adres, veri ve kontrol yolu üzerinden erişir. Gevşek bağlı: bellek fiziksel olarak paylaşılmaz, işlemciler TCP/IP gibi üst seviye protokollerle ağ üzerinden haberleşir.

## Hocanın Özellikle Vurguladığı Kısımlar

- Switchboard görevi eski telefon santrali gibidir
  - Santral memuru arayanın isteğini karşı tarafa iletir, karşı taraf kabul ederse iki hattı bir kabloyla bağlar ve aradan çekilir. Karşılıklı rıza mekanizması budur.
  - Resource link de aynı mantıkla çalışır: erişim bir kez verildikten sonra her okuma ve yazmanın dosya sistemi üzerinden geçmesi gibi gereksiz bir "bürokrasi" ortadan kalkar.
- Link yönetimi merkezi olarak çekirdektedir
  - Reply linkini dosya sistemi değil çekirdek oluşturur. Dosya sistemi kodu yalnız dosya işlemleriyle uğraşır; link oluşturma ve yok etme kullanıcı alanındaki görevlerden çıkarılıp merkezileştirilir.
- Zaman aşımı sonsuz beklemeyi önler ama işin doğru yapıldığını garanti etmez
  - Amaç işi yapmak değil, sonsuz bekleme durumundan çıkabilmektir.
- Proses göçü akademik bir çalışmadan günlük hayata geçmiştir
  - Hoca bunu en sevdiği makalelerden biri olarak andı. Sanallaştırma ortamlarındaki (VMware, Hyper-V) göç işlemlerinin bu makaledeki mantığa dayandığını söyledi.
  - Makalenin sonucu: proses göçü, haberleşme tabanlı dağıtık bir işletim sisteminde makul bir olanaktır ve DEMOS/MP'de gerçeklenip test edilmesi bir kişi-aydan kısa sürmüştür.
  - Göç, yeni bir proses başlatmanın adımlarına çok benzer. Fark, statik verinin diskten değil diğer sistemdeki son halinden alınması ve linklerin düzgün yönlendirilmesidir.
- Elektrik kesilen bir işlemcideki proses bu makaledeki yöntemle göç ettirilemez
  - Bunun için proses durumunun belirli aralıklarla (checkpointing) erişilebilir bir yere yazılması gerekir. Bu, durumun replikasyonu anlamına gelir.

## Kısa Tekrar Notları

- DEMOS'ta görev = proses; haberleşme mesaj aktarımıyla; ilgili sistem çağrılarının toplu adı "messages".
- Link: tek yönlü mesaj yolu; tipik olarak görevde başlar, çekirdekte biter. İki ters link = kanal.
- Üç işlev: standart linkler, switchboard ile karşılıklı rızalı haberleşme, başka görevi sarma (debugging/monitoring, instrumentation).
- Cray-1: tek base/limit çifti. Adres base + limit dışına çıkarsa donanım kesme üretir.
- Base/limit ile katı koruma global değişkenleri kaldırır; paylaşım gerekirse veri alanı adresleri linklerle aktarılır.
- Birden fazla görevin belleğine erişmesi gereken tek parça çekirdektir.
- Link türleri: request, reply (tek kullanımlık), resource, general.
- Resource link: kaynağa (açık dosya gibi) aracı olmadan doğrudan erişim sağlar.
- Ölü görev bekleme sorunu: timeout. Bypass link: büyük veri izleyiciyi atlar.
- Proses göçünün amaçları: yük dengeleme, kaynağa yakınlık, hata toleransı.
- Göçün sekiz adımı; "in migration" ayrı bir durumdur; mesajlar iletilir, geride iletme adresi kalır.
- Gevşek bağlı: bellek paylaşılmaz, ağ üzerinden haberleşme. Sıkı bağlı: ortak bellek yolları.
- Göçe alternatif: aynı prosesin hazır replikaları ve isteklerin onlara yönlendirilmesi; bunun için uygulama stateless olmalı ya da durum ortak bir yerde (örneğin Redis, memcached) tutulmalıdır.

## Detaylı Açıklamalar

- DEMOS'ta link kavramı ve çekirdeğin rolü
  - DEMOS'ta görevler birbirinin belleğine erişmez; haberleşme yalnız linkler üzerinden giden mesajlarla yapılır. Bir görev konsola yazmak ya da dosya açmak istediğinde bunu çekirdeğe giden bir link üzerinden mesajla ister. Konsol gibi herkesin kullandığı bir kaynağa kimin ne zaman yazacağı kullanıcı alanında yönetilemez; bu yüzden tipik linkler kullanıcı görevinden çekirdeğe doğrudur.
  - Görev oluşturulduğunda dosya sistemine ve switchboard'a giden standart linkler hazır verilir. Bir görev başka bir görevle konuşmak istediğinde switchboard'a kendi standart linki üzerinden sorar; switchboard da karşı görevin kendi standart linki üzerinden onun hazır ve istekli olup olmadığını öğrenir. İki taraf da kabul ederse istenen haberleşme için yeni linkler oluşturulur. Böylece standart linkler kontrol bilgisi ve yeni bağlantı kurmak için kullanılmış olur.
- Bellek koruması ve dağıtık işlemeye bağlantı
  - Base/limit korumasında görevden çıkan adres, o görev için belirlenmiş base + limit değeriyle karşılaştırılır. Adres izin verilen alanın dışındaysa bir kesme oluşur ve erişim donanım seviyesinde engellenir. Bu, yanlışlıkla başka bir programın kod segmentine yazılmasını önleyerek bütünlüğü, başkasının verisinin okunmasını önleyerek gizliliği korur.
  - Her görevin yalnız kendine ayrılmış belleği varsa global değişken kalmaz; bilgi yalnız mesajla paylaşılır. Her bilgisayarın erişebildiği ortak bir veri alanı varsayılamayacağı için bu, dağıtık işlemenin de temelidir. Yine de paylaşım gerektiğinde, programlama dillerinde argümanın değer yerine adresle (referansla) aktarılmasına benzer biçimde, linkler üzerinden veri alanlarının adresleri aktarılabilir.
  - Ortak veri alanına erişen iki görevin senkronizasyonu (kritik bölge) gerekebileceği bir öğrenci tarafından söylendi. Hoca makalenin bu konudaki cevabını okudu: birden fazla görevin belleğine aynı anda donanım erişimi gereken tek parça çekirdektir ve iki haberleşme türü link kavramında birleştirilir.
- Dosya açma örneği (makaleden okunan akış)
  - Görev A, dosya sistemine giden standart request linki üzerinden dosya adını ve gerekli parametreleri içeren bir mesajla "call" işlemi yapar.
  - Çekirdek standart reply kanalını belirten bir reply linki oluşturur; mesajı ve reply linkini dosya sistemine gönderir.
  - Dosya sistemi mesajı yorumlar, X dosyasını açar ve kendisine bir resource link oluşturur. Bu linkin kod alanında, dosya sisteminin açık dosya tablosunda X'in girdisine ait iç indis bulunur.
  - Dosya sistemi, görev A'nın gönderdiği reply linki üzerinden "reply" yapar ve X'i temsil eden resource linki bu yolla görev A'ya aktarır. Reply linki kullanıldıktan sonra çekirdek tarafından yok edilir.
  - Sonuçta görev A'nın dosya sistemine iki linki vardır: standart request linki ve X'i temsil eden resource link. Dosya sisteminin görev A'ya hiç linki yoktur.
- Link yönetimi ve deadlock tartışması
  - Ölmüş bir göreve istek gönderip cevap beklemek tek başına döngüsel bekleme (circular wait) değildir; sonsuz beklemedir. Bekleyen göreve başka bir görev, ona da bir başkası bağlıysa ve zincir ilk kaynağa geri dönüyorsa döngüsel bekleme oluşur. Makalenin önerdiği basit ve etkili çözüm zaman aşımıdır.
- Proses göçünde durum ve mesaj iletme
  - Proses run queue'dan çıkarılınca instruction çalıştırmaz, dolayısıyla durumunu kendisi değiştiremez. Durumu değiştirebilecek tek şey ona gelen mesaj ve olaylardır; bunları da çekirdek üstlenir ve yeni konuma iletir.
  - Prosesi "suspended" durumuna almak, örneğin çalışmakta olan bir prosesi hedefte askıda başlatmak demek olurdu. Bu yüzden zamanlayıcının prosesi run queue'ya koymaması için ayrı bir "in migration" durumu tanımlanır. Hedefte kod yüklenip veri aktarıldıktan sonra proses bu durumdan çıkar ve kaldığı durumdan devam eder.
  - Makalenin yazıldığı dönemde proses durumu dosya sistemi tablosu, semafor tablosu, bellek ayırma tablosu gibi birçok tabloya dağılmıştı; bu da taşımayı zorlaştıran bir etkendi.
  - Bir öğrencinin aktarımına göre, makale yazıldığında verimli bir taşıma kararı mekanizması hâlâ araştırma konusuydu.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
