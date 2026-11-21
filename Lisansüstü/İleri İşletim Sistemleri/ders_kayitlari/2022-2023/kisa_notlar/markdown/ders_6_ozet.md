# Ders 6 Çalışma Özeti

## Genel Konular

- Mach makalesi: bellek ve haberleşmenin ikiliği (duality)
  - Okunan ilk makale, Mach işletim sistemini anlatan "The Duality of Memory and Communication in the Implementation of a Multiprocessor Operating System" makalesidir (1987). Ders, önceki haftalarda olduğu gibi önceden okunan makalenin soru-cevapla tartışılması biçiminde geçti. Ekranda slayt ya da makale paylaşılmadı.
  - Konu çok işlemcili (multiprocessor) işletim sistemleridir. Bu sistemler iki gruba ayrılır:
    - Paylaşılan bellekli (shared memory) sistemler: birden fazla işlemci aynı belleğe erişir ve belleği aralarında paylaşır. Bunlar sıkı bağlı (tightly coupled) sistemlerdir. Belli bir işlemci sayısından sonra bellek kapasitesi, bant genişliği ve erişim hızı darboğaz olur.
    - Paylaşılmayan bellekli (non-shared memory) sistemler: her işlemcinin kendi belleği vardır, işlemciler başka bir haberleşme katmanı (örneğin TCP/IP ile ağ) üzerinden bağlanır. Bunlar gevşek bağlı (loosely coupled) sistemlerdir ve yüzler, binler, on binler mertebesinde ölçeklenebilir.
  - İkilik kavramı: paylaşılan bellekli sistemde çözümü olan bir problemin paylaşılmayan bellekli sistemde de bir karşılığı ("ikizi") vardır. Makale bu karşılıkları ve bunun için gereken tasarım değişikliklerini inceler.
  - Girişteki kilit cümle: Mach'ın bellek ile haberleşmeyi "dual" olarak ele almasının kazançları kullanıcı programlarına bellek yönetiminde artan esneklik, Mach olanaklarının hem sıkı hem gevşek bağlı çok işlemcili sistemlere daha iyi uyması ve daha yüksek performanstır.
  - "Treating as duals": bellek erişiminin semantiği ile haberleşme üzerinden erişimin semantiği eşitlenirse, yerel bellek ile uzak sistemdeki bellek dışarıdan aynı görünür. Zaman farkı kalır, ama ikisi birbirinin yerine geçebilir.
- Mach'ın beş temel soyutlaması
  - Task, thread, port, message ve memory object. Bir öğrenciye göre ilk dördü daha önceki bir sistemden alınmıştır; önceki haftanın link kavramı Mach'ta porta dönüşür.
  - Task, kaynak tahsisinin temel birimidir (basic unit of resource allocation); thread, hesaplamanın temel birimidir (basic unit of computation).
- Sanal bellekten bellek eşlemeli G/Ç'ye
  - Segmentli bellek dış parçalanmaya yol açar ve prosesin bütün olarak belleğe konmasını gerektirir. Sayfalı bellek eşit boyutlu sayfalarla bu sorunu giderir; sanal bellek de mantıksal adres soyutlamasını ve programın parça parça belleğe alınmasını getirir.
  - Mach sanal belleği ve bellek eşlemeli G/Ç'yi (memory mapped I/O) Accent'ten alır, uyarlar ve daha etkin hale getirir.
  - Paylaşılan kütüphane salt okunur olarak belleğe bir kez yüklenip isteyen proseslerin adres uzayına eşlenebilir.
  - Bellek eşlemeli dosyada proses, diskteki veriye bellekte çok büyük bir diziye erişiyormuş gibi erişir; diske okuma ve yazma ayrıntısıyla uğraşmaz.
- Memory object ve portlar
  - Dosyayı temsil eden memory object'e sistem çağrısıyla değil, bir port üzerinden istek gönderilerek erişilir. Sayfa bellekteyse cevap hemen gelir; yoksa sayfa hatası olur ve çekirdek sayfayı arka planda getirir. Hoca bunu "çekirdeğin sürekli doldurduğu bir tampon" gibi düşünmeyi önerdi.
  - Avantaj 1: port arkasındaki hedefin yerel mi ağda başka bir makinede mi olduğu fark etmez.
  - Avantaj 2: nesne kullanıcı uzayında oluşturulduğunda erişim sistem çağrısı (kesme, kullanıcı-çekirdek geçişi) yerine fonksiyon çağrısı gibi olur ve kat kat hızlanır.
  - Nesne paslanabilir; başka prosesler de çekirdeğe gitmeden aynı veriyi okuyabilir.
- UMA, NUMA ve NORMA
  - UMA (Uniform Memory Access): gerçek paylaşılan bellekte iki prosesin belleğe erişim hızı aynıdır.
  - NUMA (Non-Uniform Memory Access): paylaşılmayan bellek yapısında bazı prosesler yerel belleğe nanosaniyeler mertebesinde, bazıları uzak belleğe mikrosaniye hatta milisaniye mertebesinde erişir.
  - NORMA: uzak bellek erişiminin hiç olmadığı, erişimin tamamen yerelle sınırlı olduğu yapılar.
  - Hocaya göre bu kavramlar bugün Windows, Linux ve Unix türevlerinde hâlâ kullanılır.
- Program, proses (task) ve thread
  - Bir program bir prosese karşılık gelir. Aynı programla birden fazla proses (her biri ayrı bir kopya) ilişkilendirilebilir, ama bir proses yalnız bir programla ilişkilendirilir. Çocuk proses de ayrı bir prosestir.
  - Bir program, birbiriyle ilintili ama eş zamanlı ve bağımsız çalışabilen parçalardan oluşabilir: kelime işlemcide yazarken arka planda çalışan yazım denetimi ya da telefonda otomatik düzeltme gibi. Bu parçalar thread veri yapısıyla izlenir.
- Kernel seviyesi ve kullanıcı seviyesi thread'ler
  - İşlemciyi tahsis etme yetkisi işletim sistemindedir. İşletim sistemi yalnız prosesleri tanırsa işlemciyi yalnız prosese verebilir. Prosesin içindeki parçaların eş zamanlı çalışabilmesi için thread'lerin çekirdek seviyesinde tanınması gerekir: kernel level thread.
  - Çekirdeğe giriş sistem çağrısı, yani kesme ile olur. Her kesme bir duraksama ve yavaşlamadır.
  - Thread'ler kullanıcı uzayına taşınırsa (user level thread) çekirdek thread'leri tanımaz; prosese verilen sürenin thread'ler arasında paylaştırılması ve işlemcinin thread'ler arasında aktarılması sorun olur.
- First-class user-level threads makalesi (Psyche)
  - Makale, kullanıcı seviyesi thread'lere "first class status" vermek için tasarlanmış bir dizi çekirdek mekanizmasını ve kuralını anlatır.
  - First class: kullanıcı seviyesi thread'ler, kernel seviyesi thread'lerin bütün yeteneklerine sahipmiş gibi davranır; programcı ikisi arasında fark gözetmeden aynı programlama yapısını kullanır, ama daha yüksek performans, daha düşük gecikme ve daha az ek kaynak elde edilir.
  - Psyche'de çekirdek ve kullanıcı arasında paylaşılan veri yapıları vardır (makalenin Şekil 1'i): çekirdek verisi, kullanıcı verisi, gerçek yazmaçların aynasını tutan sözde yazmaçlar (pseudo-registers), sanal işlemci, fiziksel işlemci, adres uzayı.
  - Kullanıcı uzayında bir sanal işlemci (virtual processor) oluşturulur. Donanımdaki olaylar ve kesmeler yukarıda yazılım kesmelerine dönüştürülür. Hoca bunu paravirtualization'ın başlangıcı gibi düşünmeyi önerdi.
  - Makalede sayılan yazılım kesmeleri: sanal işlemcinin başlatılması, thread'in çekirdekte bloke olması, thread'in çekirdekte blokajdan çıkması, başka bir sanal işlemciden sinyal, zamanlayıcının dolması, yakın önalım (imminent preemption) ve program hatası.

## Hocanın Özellikle Vurguladığı Kısımlar

- Mach makalesinin özü
  - Aradaki soyutlamayı (port, memory object) koymak; paylaşılan bellekte çözülebilen her problemin paylaşılmayan bellekte bir ikizi olduğunu ortaya koymak; bunun kendiliğinden olmadığını, sistemsel ve kavramsal değişiklikler gerektirdiğini göstermek.
  - Nesne yönelimi programlama dillerinde çok konuşulur, ama bunu işletim sisteminde görebilmek önemlidir: yerel bir fonksiyon çağrısını ağ üzerinden bir çağrıya dönüştürebilmek.
- Kullanıcı uzayında oluşturulan nesnenin farkı
  - Kullanıcı ile çekirdek uzayı arasındaki geçiş (kesme) zaman kaybıdır. Nesne kullanıcı uzayındaysa erişim fonksiyon çağrısına dönüşür.
- Task ve thread tanımı
  - "Task is the basic unit of resource allocation. Thread is the basic unit of computation." Hoca bu tanımı çok güzel bulduğunu ve kritik ayrımın bu olduğunu söyledi. Computation yerine daha genel olarak "execution" denir, çünkü her komut bir hesaplama değildir (dallanma, atlama olabilir).
- Task proseslerden oluşmaz
  - Task, günümüz terminolojisinde prosesin kendisidir. Bir programı proseslere bölmekten söz edilmez; program içindeki eş zamanlı parçalar thread'dir.
- First class'ın anlamı
  - Kullanıcı hiç etkilenmemeli: kernel thread'i nasıl kullanıyorsa kullanıcı seviyesi thread'i de değişiklik olmadan aynı biçimde kullanabilmeli.
- Makale okuma yöntemi
  - Makaledeki her sistem çağrısı tablosunu ezberlemek gerekmez; önemli olan kavramları ve bugün kullanılan bir şeyin ilk nasıl ortaya atıldığını görmektir.

## Kısa Tekrar Notları

- Shared memory = sıkı bağlı, sınırlı ölçeklenir; non-shared memory = gevşek bağlı, binlerce düğüme ölçeklenir.
- Duality: bir taraftaki çözümün diğer tarafta karşılığı vardır; bellek erişimi ile haberleşme semantiği eşitlenir.
- Mach soyutlamaları: task, thread, port, message, memory object.
- Task = kaynak tahsisi birimi (bugünkü adıyla proses); thread = hesaplama (yürütme) birimi.
- Memory object'e port üzerinden erişilir; yerel ya da uzak fark etmez; kullanıcı uzayında ise erişim fonksiyon çağrısı kadar hızlıdır.
- Bellek eşlemeli dosya: diskteki veriye bellekteki büyük bir diziymiş gibi erişilir.
- UMA: eşit erişim süresi; NUMA: yerel/uzak erişim süresi farklı; NORMA: uzak erişim yok.
- Bir proses yalnız bir programla ilişkilidir; bir programın birden fazla proses kopyası olabilir.
- Kernel level thread: çekirdek tanır, ama her geçiş kesme ve yavaşlama demektir.
- User level thread: hızlı, ama çekirdek tanımaz; işlemci paylaştırma sorunu vardır.
- First-class user-level threads (Psyche): sanal işlemci, paylaşılan çekirdek-kullanıcı veri yapıları, donanım olaylarının yazılım kesmesine dönüştürülmesi.

## Detaylı Açıklamalar

Dersin ilk yarısı Mach makalesine ayrıldı. Hoca önce "duality" kelimesinin bu bağlamdaki anlamını sordu. Bir öğrencinin "bir şeyi güçlendirince başka bir şeyden kaybetmek" yorumunu düzelterek, kavramın çok işlemcili sistem sınıflandırmasından çıktığını açıkladı. Paylaşılan bellekli sistemlerde işlemciler ortak belleğe erişir; bu yapı belli bir işlemci sayısına kadar iyi çalışır, sonra bellekle ilgili darboğazlar başlar. Paylaşılmayan bellekli sistemlerde her işlemcinin kendi belleği vardır ve işlemciler bir haberleşme katmanıyla bağlanır; bu yapı çok daha rahat ölçeklenir. Mach, bellek ile haberleşmeyi birbirinin yerine geçebilen eşdeğer parçalar olarak ele alır: yerel belleğe erişmek ile uzaktaki bir makinenin belleğine haberleşme üzerinden erişmek dışarıdan aynı görünür.

Bir öğrenci makaledeki beş soyutlamayı (task, thread, port, message, memory object) sıraladı ve kullanıcı uzayındaki bir yöneticinin port aracılığıyla dosya sistemine eriştiğini, sayfa hatasında çekirdeğin tamponu doldurduğunu, aynı yapının ağ üzerinden başka bir makinede de kurulabildiğini anlattı. Hoca bunun tam olarak makalenin özü olduğunu doğruladı. Ardından makalenin task ve thread tanımına geçti: task bir programı çalıştırmak için gereken her şeyin (kod ve veri alanı, dosyalar, ağ ve diğer kaynaklar) kaydını tutan yapıdır; thread ise bu yapının içinde akan, ilerleyen yürütmedir. Başlangıçta task ile thread ayrılmamıştı. Bir programın farklı parçaları aynı anda çalışabilecek biçimde kurulabilince iki kavramın ayrılması gerekti. Hoca, bu fikirlerin bir yerde yazılı olarak hazır bulunmadığını, 1960'lardan 1990'lara kadar deneme yanılma ile adım adım geliştiğini vurguladı.

Sanal bellek tartışmasında öğrenci segmentli bellekten sayfalı belleğe, oradan sanal belleğe geçişi özetledi ve Mach'ın bu kavramları Accent'ten aldığını söyledi. Hoca bellek eşlemeli dosyada prosesin diskteki veriye bellekte büyük bir diziye erişir gibi eriştiğini sorularla açtırdı. Sonra memory object'e port üzerinden erişimin iki avantajını konuşturdu: hedefin yeri önemsizleşir ve nesne kullanıcı uzayında oluşturulursa erişim kesme gerektiren bir sistem çağrısı yerine sıradan bir fonksiyon çağrısı olur. Hoca bu bölümü UMA, NUMA ve NORMA kavramlarıyla bağladı: paylaşılan bellekten paylaşılmayan belleğe geçildiğinde erişim süresi eşit olmaktan çıkar, yerel erişim nanosaniyeler, uzak erişim mikrosaniye ya da milisaniye mertebesine çıkabilir.

Dersin ikinci yarısında kullanıcı seviyesi thread'ler makalesi tartışıldı. Hoca önce program, proses ve thread arasındaki farkı netleştirdi. Bir öğrencinin "task altında prosesler olur" ve "program proseslere bölünür" ifadelerini düzeltti: task prosesin eski adıdır, bir program bir prosese karşılık gelir, program içindeki eş zamanlı parçalar thread'dir. Kelime işlemcide yazarken arka planda çalışan yazım denetimi ve telefondaki otomatik düzeltme bu parçalara örnektir. İşletim sistemi yalnız prosesleri tanırsa işlemciyi yalnız prosese verebilir; bu yüzden standart tasarımda thread'ler çekirdek seviyesinde tanınır. Ancak çekirdeğe her giriş bir kesmedir ve zaman kaybettirir. Thread'leri kullanıcı uzayına taşımak bu maliyeti kaldırır ama çekirdek artık thread'leri tanımaz.

Makale bu sorunu çekirdek ile kullanıcı arasında paylaşılan veri yapıları ve kullanıcı uzayında bir sanal işlemci soyutlamasıyla çözer. Fiziksel işlemcide gerçekleşen olaylar (çekirdekte bloke olma ve blokajdan çıkma, zamanlayıcı, önalım, program hatası gibi) üst tarafa yazılım kesmeleri olarak yansıtılır. Örneğin sıfıra bölme ya da erişilmemesi gereken belleğe erişme donanımda bir donanım kesmesi doğururdu; kullanıcı seviyesinde yalnız hatanın oluştuğu ve türü bildirilir. Böylece kullanıcı seviyesi thread'ler kernel thread'lerinin yeteneklerine sahip olur ve programcı ikisi arasında fark gözetmek zorunda kalmaz. Hocanın deyişiyle "first class"tan anlaşılan budur.

<!-- BELİRSİZ: Bir öğrenci task, thread, port ve message soyutlamalarının alındığı sistemin adını söyledi; altyazıda "Xen" diye geçiyor, doğru ad anlaşılamadı. -->

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
