# Ders 2 Genişletilmiş Notu: Arka Plan İşleri ve WorkManager

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Ana Thread ve Arka Plan İşlerine Duyulan İhtiyaç
- 2. Arka Plan İşlemenin Zorlukları ve Android'in Önlemleri
- 3. App Standby Bucket'lar
- 4. Doğru Çözümü Seçmek İçin Sorulacak Sorular
- 5. Arka Plan İşinin Tanımı ve Türleri
- 6. Kategorilere Göre Önerilen Çözümler
- 7. WorkManager ve Foreground Servisler
- 8. Servisler
- 9. Karar Akışı
- 10. Cihazı Uyanık Tutmak
- 11. AlarmManager Ayrıntıları
- 12. Uygulama: WorkManager ile Dosya Yükleme Simülasyonu
- Örnek Sorular
- Dersin Toparlaması

## 1. Ana Thread ve Arka Plan İşlerine Duyulan İhtiyaç

Dersin konusu Android'de arka plan işleridir (background tasks). Hoca konuya, arka plan işlerinin Android'de yıllar içinde en çok dikkat çeken ve üzerine en çok önlem alınan konulardan biri olduğunu söyleyerek girer. İlk Android sürümlerinde her uygulama arka planda istediği işi rahatça yapabiliyordu; zamanla bunun özellikle pil tüketiminde yarattığı sorunlar Google'ın önlem almasını gerektirdi.

Neden arka plan işine ihtiyaç duyulduğunu anlamak için ana thread'e bakmak gerekir. Slayttaki ifadeye göre her Android uygulamasında, kullanıcı arayüzünü yönetmekten (view'ların ölçülmesi ve çizilmesi dahil), kullanıcı etkileşimlerini koordine etmekten ve yaşam döngüsü olaylarını almaktan sorumlu bir ana thread vardır (ekrandan, 00:10:00). Kullanıcıyla ön plandaki bütün etkileşim bu thread üzerinden yürür. Bulunulan aktivitede uzun sürecek bir işlem bu thread'de yapılırsa kullanıcıyla etkileşim kesilir, ekranda donmalar olur ve iş "Application Not Responding" (ANR) hatasına kadar gidebilir.

Slayta göre bitmap çözme, diske erişme ya da ağ isteği yapma gibi uzun süren hesaplama ve işlemler ayrı bir arka plan thread'inde yapılmalıdır. Genel kural olarak birkaç milisaniyeden uzun süren her iş bir arka plan thread'ine devredilmelidir. Hoca bu sınırı sözlü olarak 5-10 milisaniye diye verdi. Arka planda yapılması gereken tipik işler şunlardır:

- Ağ üzerinden dosya indirme ve yükleme.
- Diskteki büyük bir dosyanın belleğe taşınması.
- Bir multimedya dosyası üzerinde işlem yapılması.

Önemli olan, bu işlerin main thread ya da UI thread diye bilinen ana thread'den ayrı organize edilmesi ve böylece kullanıcıyla olan etkileşimde gecikme yaratılmamasıdır.

Hoca iki tür yapıdan söz eder: Java'nın sunduğu thread'ler ve Android'in sunduğu özel yapılar. Java tarafında thread yönetimi standart bir şekilde yapılırken Android'in yapıları mobil cihazların donanım ve enerji kısıtlarına uygun olarak tasarlanmıştır.

## 2. Arka Plan İşlemenin Zorlukları ve Android'in Önlemleri

Arka plan işlerinin organize edilmesi yalnız donma ve ANR'den kaçınmak için değil, sistemin performanslı ve kaynakların verimli kullanılması için de gereklidir. Slayttaki ilk zorluk şudur: arka plan işleri cihazın RAM ve pil gibi sınırlı kaynaklarını tüketir; doğru yönetilmezse kullanıcı deneyimi kötüleşir (ekrandan, 00:15:00). Kullanıcı ön planda bir iş yaparken arka planda sürekli kaynak kullanılması pilin çok hızlı tükenmesine yol açar.

Bunu yönetmek için Android 6.0 ile başlayan ve Android 12 döneminde de geliştirilmeye devam eden önlemler vardır. Slayttaki kronoloji şöyledir (ekrandan, 00:15:00):

- Android 6.0 (API 23): Doze modu ve App Standby geldi. Doze modu, ekran kapalıyken ve cihaz hareketsizken uygulama davranışını kısıtlar. App Standby, kullanılmayan uygulamaları ağ erişimlerini, işlerini (job) ve senkronizasyonlarını kısıtlayan özel bir duruma alır.
- Android 7.0 (API 24): örtük (implicit) broadcast'leri sınırladı ve Doze-on-the-Go'yu getirdi. Hoca bunu, telefon cepte taşınırken de kullanılmadığının sistem tarafından anlaşılıp arka plan işlerinin kısıtlanması ya da sıklıklarının düşürülmesi olarak açıkladı.
- Android 8.0 (API 26): arka planda konum alma ve önbelleğe alınmış wake lock'ların bırakılması gibi arka plan davranışlarını daha da sınırladı. Bu madde slaytta var, sözlü anlatılmadı.
- Android 9 (API 28): App Standby Bucket'ları getirdi. Uygulamaların kaynak istekleri kullanım örüntülerine göre dinamik olarak önceliklendirilir.

Hoca, Android 9 ile gelen yaklaşımın tamamen yeni bir bakış açısı olduğunu vurgular: uygulamaların kullanım sıklıkları sistem tarafından bir makine öğrenmesi modeliyle arka planda takip edilir ve uygulamalar buna göre önceliklendirilir.

## 3. App Standby Bucket'lar

Uygulamaların kullanım örüntüleri incelenerek uygulamalar beş farklı kovaya (bucket) ayrılır. Hoca bunu "4 artı 1" diye anlatır: kullanılan uygulamalar için Active, Working Set, Frequent ve Rare; ayrıca indirilmiş ama hiç kullanılmamış uygulamalar için Never kovası. Yüksek önceliğe sahip olmak için uygulamanın sık kullanılması ve aktif uygulamalar arasında olması gerekir; indirilip hiç kullanılmayan bir uygulama en düşük öncelikli kovaya yerleştirilir.

### 3.1 Active

O anda kullanılan ya da yeni kapatılan uygulamalar buradadır; bunlar genellikle bir launcher aktivitesi olan uygulamalardır. Bunlara ek olarak foreground servis kullanan uygulamalar, belli periyotlarla senkronizasyon yapması gereken uygulamalar ve kullanıcının bildirimine tıkladığı uygulamalar da Active kovaya yerleştirilir. Active kovadaki uygulamaların arka plan işleri hiç kısıtlanmaz.

Uygulamalar zamanla kovalar arasında yer değiştirir: aktif kovadan bir alt kovaya düşebilir, çok az kullanılırsa Rare kovaya kadar inebilir.

### 3.2 Working Set

Slayta göre bir uygulama sık çalışıyor ama o anda aktif değilse Working Set kovasındadır. Örneğin kullanıcının çoğu gün açtığı bir sosyal medya uygulaması büyük olasılıkla bu kovadadır. Uygulamalar dolaylı olarak kullanıldıklarında da bu kovaya yükseltilir. Working Set'teki uygulamalara iş çalıştırma ve alarm tetikleme konusunda hafif kısıtlamalar uygulanır (ekrandan, 00:20:00). Hoca örneği şöyle somutlaştırır: saatte bir ya da yarım saatte bir bakılan, ama o an ya da yakın gelecekte açılmamış bir uygulama Working Set'tedir; sistem bunları yumuşak kurallarla yönetir.

### 3.3 Frequent

Hocanın örneği bir spor takip uygulamasıdır. Bu uygulama günün her dakikası değil, spor yapılan günlerde, iki üç günde bir ya da gün aşırı açılır. Bu tür uygulamalar daha az sıklıkla kullanıldığı için arka plan işleri daha fazla kısıtlanır ve sürekli arka planda iş yapmaları engellenir.

Hoca bunun neden önemli olduğunu da açıklar: geliştirici uygulamaya yoğun arka plan işleri yüklemiş olsa bile, kullanıcı uygulamayı çok kullanmıyorsa sistem bu gereksiz işleri kova mantığıyla kontrol altına alır. Böylece yazılımcının gereksiz yere oluşturduğu arka plan işlerinin önüne geçilmiş olur.

### 3.4 Rare

Seyahatlerde kullanılan otel uygulamaları gibi ayda bir, birkaç ayda bir ya da yılda birkaç kez açılan uygulamalar bu kovadadır. Burada arka plan işleri için çok daha katı kurallar vardır; işler mümkün olduğunca kontrollü ve sistemin uygun olduğu zamanlarda çalışır. Never kovasından sonra en fazla kısıtlamanın olduğu kovadır.

### 3.5 Google'ın önerileri

> **Hocanın vurgusu:** Uygulamanın hangi kovada bulunacağını sistem belirler; geliştirici buna kesinlikle müdahale etmemelidir. Müdahale sistemde sorunlara yol açabilir.

İkinci önemli uyarı: bir uygulamanın Active kovada yer alabilmesi için mutlaka bir launcher aktivitesi olmalıdır. Launcher aktivitesi olmayan bir uygulamanın Active kovaya girme ihtimali yoktur. Aynı şekilde bildirimleri kullanıcıya bir eylem sunacak biçimde tasarlanmamış bir uygulama da bildirim yoluyla aktif kovaya giremez. Bu yüzden uygulamanın launcher aktivitesi ya da eylem üretebilen bildirimleri olacak şekilde tasarlanması gerekir.

> **Ek bilgi (derste anlatılmadı):** Android belgelerinde kovaların arasında ayrıca Android 12 ile eklenen "Restricted" adlı bir kova da büyük olasılıkla bulunmaktadır; derste anlatılan 4 + 1 yapısı Android 9'daki ilk tasarıma dayanır.

## 4. Doğru Çözümü Seçmek İçin Sorulacak Sorular

Hoca, bir arka plan işi için uygun yapıyı seçmeden önce sorulması gereken soruları sıralar. Slayttaki ilk üç soru şunlardır (ekrandan, 00:25:00):

- Uygulamanın başlama ve durma zamanı üzerinde kesin kontrole ihtiyacı var mı? Örneğin bir müzik uygulaması kullanıcı çalmayı başlattığında çalmaya başlamalı ve kullanıcı durdurana kadar devam etmelidir. Buna karşılık periyodik olarak log yükleyen bir uygulama, yüklemenin tam ne zaman olduğunu önemsemez.
- İş gerekirse bölünebilir mi? Çok büyük bir dosya yüklenirken yükleme kesilirse bütün iş kaybolabilir ve yüklemeye baştan başlamak gerekebilir; böyle bir işin mümkünse hiç kesilmemesi istenir. Küçük log dosyalarının periyodik yüklenmesinde ise bir yüklemenin kesilmesi sorun değildir.
- İş ertelenebilir mi, yoksa hemen mi yapılmalı? Kullanıcı bir butona bastığında ağdan veri çekilecekse iş hemen yapılmalıdır. Loglar sunucuya gönderilecekse iş, uygulamanın performansını ya da kullanıcı beklentisini etkilemeden ertelenebilir.

Hoca müzik uygulamasını, notification drawer gibi sürekli göz önünde olmayan bir alandan durdurulabilmesi, başlatılabilmesi ve sonlandırılabilmesi gereken bir iş örneği olarak verir; bu tür işler foreground servislerle yönetilir. Log gönderme örneğinde ise logların gün içinde değil, gece telefonun kullanılmadığı, belki bir Wi-Fi erişim noktasına bağlı olduğu ya da şarjda olduğu bir anda gönderilmesinin avantajını anlatır.

Sözlü olarak eklenen diğer sorular şunlardır:

- İş, internet bağlantısının olması ya da cihazın güce bağlı olması gibi sistem koşullarına bağlı mı? Öyleyse çözüm bu koşulları dikkate almalıdır.
- İş hassas veri kullanıyor ve anlık karar gerektiriyor mu? En iyi örnek navigasyon uygulamasıdır: konum bilgisi hassas bir bilgidir ve sık güncellenmesi gerekir. Bu yüzden navigasyon uygulaması foreground servis olarak başlatılmalı ve kullanıcı bunun üzerinde hakimiyet kurabilmelidir.
- İşin kesin bir zamanda başlaması gerekiyor mu? Örneğin saat 2'de başlaması isteniyorsa AlarmManager gibi yapılardan yararlanmak gerekir; takvim hatırlatmalarının tam saatinde çıkması da bunun örneğidir.
- Bir işin bitmesinden sonra başka bir işin başlaması gerekiyor mu? Bu durumda da buna uygun bir çözüm üretmek gerekir.

## 5. Arka Plan İşinin Tanımı ve Türleri

### 5.1 Arka plan tanımı

Slayttaki tanıma göre bir uygulama aşağıdaki iki koşul birlikte sağlandığında arka planda çalışıyor sayılır; aksi halde ön plandadır (ekrandan, 00:30:00):

- Uygulamanın hiçbir aktivitesi o anda kullanıcıya görünür değildir.
- Uygulama, kendi aktivitelerinden biri görünürken başlatılmış bir foreground servis çalıştırmıyordur.

Hoca bunu şöyle açar: arka plan işinin aktiviteleri kullanıcının gözü önünde olmamalı, kullanıcıyla görsel temas kurmamalıdır. Foreground servisler dışında uygulamanın hiçbir parçası görünür olmamalıdır. Yalnız notification drawer'da foreground servisler için, örneğin müzik uygulamasında Pause, Play, Stop gibi tuşlar bulunabilir.

Foreground servisler de aslında arka planda çalışır ve arka planda yapılan işler kategorisine girer, ama background servis ile foreground servis birbirinden farklıdır. Background servisler uzun süre çalışan, hiçbir arayüzü olmayan servislerdir. Foreground servislerde ise küçük de olsa bir arayüz üzerinden, özellikle multimedya işleri yönetilebilir.

### 5.2 Üç ana kategori

Slayta göre arka plan işi üç temel kategoriden birine girer (ekrandan, 00:30:00):

- **Immediate:** hemen çalışmalı ve kısa sürede tamamlanmalıdır.
- **Long Running:** tamamlanması zaman alabilir. Hoca bunun genelde 10 dakika ve üzeri işler için kullanıldığını söyler.
- **Deferrable:** hemen çalışması gerekmez.

### 5.3 Persistent ve impersistent

Bu üç kategorinin her birindeki iş ayrıca şu iki türden biri olabilir:

- **Persistent work:** uygulama yeniden başlatıldığında ve cihaz yeniden açıldığında da zamanlanmış olarak kalır.
- **Impersistent work:** süreç bittikten sonra artık zamanlanmış değildir; çalıştıktan sonra tekrar çalışmaz.

<!-- BELİRSİZ: 00:32:19 civarında hoca bir şekil üzerinden "coroutine'ler kısa süreli işler, Expedited Work tekrar edebilir işler" gibi bir ifade kullanıyor; altyazı bozuk ve şeklin karesi yok, bu kısım nota alınmadı. -->

## 6. Kategorilere Göre Önerilen Çözümler

### 6.1 Persistent işler ve WorkManager

Hoca, persistent (tekrar eden, kalıcı) işlerin mümkünse WorkManager ile yapılmasının istendiğini söyler. WorkManager, Google'ın Android platformunda sunduğu ve bu tür arka plan işlerini yürütmek için özel olarak tasarlanmış bir yapıdır. Kotlin coroutine'leri ve Java'nın thread mekanizmaları ise kısa süreli, hemen yapılması gereken ve tekrarı olmayan işler için kullanılabilir. Örneğin milisaniyeler ya da saniyeler sürecek ve tekrar etmeyecek bir iş için Java'nın `Thread` ya da `Runnable` mekanizması yeterlidir.

> **Ders sonrası not:** Hoca 00:34:12 civarında WorkManager'ın daha çok impersistent işler için, servis mekanizmasının ise tekrar eden işler için kullanılacağını söyledi. Bu, hocanın hemen önceki ifadesiyle ve slaytla çelişir: slayta göre persistent işler için WorkManager, impersistent kısa işler için coroutine, Executor ve benzeri yapılar önerilir.

### 6.2 Immediate work

Slayttaki tanıma göre immediate work, hemen çalışması gereken görevleri kapsar. Bunlar kullanıcı için önemli olan ya da daha sonraya ertelenemeyen görevlerdir; uygulama kapansa ya da cihaz yeniden başlasa bile hızlıca çalışmak üzere zamanlanmış kalmaları gerekebilir (ekrandan, 00:35:00).

Önerilen çözüm:

- Persistent immediate iş için WorkManager ile bir `OneTimeWorkRequest` kullanılır; WorkRequest `setExpedited()` ile öne alınır (expedite edilir).
- Impersistent immediate iş için Kotlin coroutine'leri kullanılır. Uygulama Java kullanıyorsa RxJava ya da Guava, ayrıca Executor'lar kullanılabilir.

Slayttaki örnekler:

- Bir uygulamanın bir veri kaynağından veri yüklemesi gerekir. Bu istek ana thread'de yapılırsa thread bloke olur ve arayüz takılır (UI jank); uygulama isteği bir coroutine içinde ana thread dışında yapar.
- Bir sohbet uygulamasında mesaj gönderilmesi gerekir. Uygulama bir `Worker` oluşturur ve görevi bir `WorkRequest` olarak kuyruğa alır; `WorkRequest`'i `setExpedited()` ile öne alır.

Hoca sözlü olarak, uygulama açıldığında resimlerin ve videoların anında indirilmesi gerekiyorsa bunun immediate bir iş olduğunu ekler.

### 6.3 Long running work

İş birden fazla kez ve 10 dakikadan uzun sürecekse long running work olarak adlandırılır; WorkManager'daki worker yapısıyla yönetilebilir. Büyük boyutlu bir dosya indirilecekse ve parçalara bölünmesi mümkün değilse, indirmenin bir worker aracılığıyla yapılması önerilir. Alternatif olarak DownloadManager de vardır. İndirilecek dosyanın hemen inmesi gerekmiyorsa parçalara ayrılarak sistemi daha az yoran ve uygun anlarda parça parça indiren bir çözüm tercih edilebilir.

### 6.4 Deferrable work

Hemen yapılması gerekmeyen bütün işler ertelenebilir işlerdir. Örneğin aciliyeti olmayan bir verinin arka planda belli periyotlarla senkronize edilmesi, WorkManager altındaki `PeriodicWorkRequest` ile yapılır. Böylece iş belirli bir dakika ve saniyede değil, sistemin müsait olduğu bir zaman diliminde yapılmak üzere sisteme devredilir; sistem de bunu kendine uygun bir zamanda yönetir.

### 6.5 Alarmlar

Hoca alarm yöneticisini sistemi en çok yoran ve sayısının artması verimli olmayan yapı olarak tanıtır. Slayta göre alarmlar arka plan işinin bir parçası olmayan özel bir kullanım durumudur; arka plan işleri yukarıdaki iki çözümle, coroutine'ler ve WorkManager ile yapılmalıdır. AlarmManager yalnız çalar saat ya da takvim etkinliği gibi kesin zamanlı alarmları zamanlamak için kullanılmalıdır. AlarmManager ile arka plan işi zamanlandığında cihaz Doze modundan uyandırılır; bu da pil ömrünü ve genel sistem sağlığını olumsuz etkiler ve bu etkiden uygulama sorumludur (ekrandan, 00:40:00).

Hoca, cihazı uyku konumundan gerektiğinde hem ekran hem CPU anlamında uyandırdığı için alarmların bataryaya olumsuz etkisi olduğunu ve mümkün olduğunca kaçınılması gerektiğini vurgular. Alarm iki şekilde kurulabilir: tam belirli bir zamanda çalışan exact alarm ya da "saat 2 civarında" çalışabilecek inexact alarm. Inexact alarm 5 saniye, 10 saniye ya da 1 dakika gecikmeyle devreye girebilir; kullanıcı açısından sakıncası yoksa bir takvim etkinliği tam 13.00'te değil birkaç dakika geçe bildirilebilir.

## 7. WorkManager ve Foreground Servisler

Foreground servisler özellikle medya uygulamalarının yönetilmesi, aktivitelerin takip edilmesi, konum bilgisinin paylaşılması ve sesli ya da görüntülü gelen görüşmelerin yönetilmesi için kullanılır. Hoca, Android'in WorkManager tarafındaki yapı sayesinde foreground servislerin verimliliğini artırdığını, uzun soluklu işler için foreground servisler kullanılmaya devam ederken daha kısa süreli işler için WorkManager'dan hizmet alınabileceğini söyler.

WorkManager son yıllarda birçok iş yükünü sahiplenmiştir ve Android'in önerdiği önemli bir kütüphanedir. Bağlantının olması, güç kaynağına bağlı olma gibi durumları takip eder ve gerekli koşullar oluştuğunda ertelenebilir işleri çalıştırır. Bu sayede önemli bir kaynak verimliliği sağlar.

> **Hocanın vurgusu:** Google, arka plan işlerinin mümkün olduğunca WorkManager başlığı altında yönetilmesini tavsiye ediyor.

Kullanıcının başlattığı bir işten söz ediliyorsa, örneğin müzik uygulaması, iş foreground servis olarak çalıştırılmalı ve kullanıcıya bu servis üzerinde yönetme ve kontrol etme hakkı verilmelidir. Bu erişim genelde bildirim çekmecesi (notification drawer) üzerinden olur: kullanıcı çekmeceyi indirerek arka plandaki müzik, ses ya da video konferans uygulamasına ulaşır.

AlarmManager için öneri yine aynıdır: mümkün olduğunca WorkManager kullanılmalı; WorkManager bir alternatif olamıyorsa, örneğin bir takvim uygulamasında kesin zamana (precise time) ihtiyaç varsa AlarmManager kullanılmalıdır.

## 8. Servisler

### 8.1 Servis nedir?

Arka planda kullanıcı arayüzü olmadan uzun süre çalışan operasyonlar servisler tarafından yönetilir; bu, dersin ilk haftalarında da söylenmişti. Slayttaki tanıma göre (ekrandan, 00:45:00):

- Servis, arka planda uzun süren işlemler yapabilen ve kullanıcı arayüzü sağlamayan bir uygulama bileşenidir.
- Başka bir uygulama bileşeni bir servisi başlatabilir ve servis, kullanıcı başka bir uygulamaya geçse bile arka planda çalışmaya devam eder. Ayrıca bir bileşen, servisle etkileşmek ve hatta süreçler arası iletişim (IPC) yapmak için servise bind olabilir.
- Örneğin bir servis ağ işlemlerini yürütebilir, müzik çalabilir, dosya G/Ç yapabilir ya da bir content provider ile etkileşebilir; bunların hepsini arka planda yapar.

Eskiden arka plandaki ağ işlemleri ve müzik dinleme ağırlıklı olarak servislerle yönetilirdi; artık kullanıcıyla etkileşim söz konusuysa foreground servisler tercih ediliyor. Arayüz olmadan arka planda devam etmesi gereken, özellikle 10 dakikadan uzun işlerin servislerle yönetilmesi istenir.

### 8.2 Servis türleri ve bind

Servisler foreground servis ve background servis olarak iki temel başlıkta toplanır. Bunlara ek olarak servislerin bind edilmesi kavramı vardır. Hoca slayttaki bounded/unbounded servis şemasını gösterir: bir tarafta servis örneğin bir broadcast receiver üzerinden tetiklenebilir, diğer tarafta bir uygulamaya bind edilebilir.

Hoca önce, bir uygulamaya bind edilen servisin o uygulama kapatıldığında kapandığını, böylece servisin açılıp kapanmasını ayrıca kodla kontrol etmek gerekmediğini söyler. Ardından bunu düzeltir: servis bind edilmeden başlatılırsa uygulama kapanınca servis de otomatik kapanır; bind edilirse önce servisin unbind edilmesi, sonra uygulamanın kapanması gerekir.

> **Ders sonrası not:** Hocanın bu düzeltmesi Android belgeleriyle büyük olasılıkla örtüşmez. `startService()` ile başlatılan (bind edilmemiş) bir servis, onu başlatan bileşen yok olsa bile `stopSelf()` ya da `stopService()` çağrılana kadar çalışmaya devam eder. Yalnız bind ile kullanılan bir servis ise ona bağlı bütün istemciler `unbindService()` ile ayrıldığında (ya da istemciler yok olduğunda) sistem tarafından yok edilir. Yani hocanın ilk ifadesi doğruya daha yakındır.

### 8.3 Servisi başlatmak, durdurmak ve tanımlamak

Ön plandaki servisler `startForegroundService()` ile başlatılır. `startService()` ile de, Intent içine hangi servisin arka planda çalışacağı yazılarak servis çağrılır. Servisi durdurmak, başlatmak kadar önemlidir: servis durdurulmazsa ve Android yeterli kaynak bulamazsa, sistem haber vermeden ilk temizlediği yapılardan biri olan servisi otomatik olarak öldürür.

Daha önce aktiviteler manifest'te `<application>` içinde tanımlandığı gibi, çalıştırılacak servis de manifest'te tanımlanır. Ardından ilgili servis sınıfı (hoca `IntentService` örneğini verir) extend edilerek arka planda yapılacak işler servisin içine kodlanır.

### 8.4 Servis mi, thread mi?

Servis uzun sürecek işlere hizmet eden bir yapıdır. Thread ise ağırlıklı olarak çok kısa süreli ve tekrar etmeyecek işler için önerilen bir yapıdır.

> **Ek bilgi (derste anlatılmadı):** `IntentService` sınıfı Android 11 (API 30) ile büyük olasılıkla kullanımdan kaldırılmış (deprecated) durumdadır; Google bunun yerine WorkManager ya da `JobIntentService` kullanılmasını önerir.

## 9. Karar Akışı

Hoca, şimdiye kadar anlatılan sorulara göre hangi yapının seçileceğini slayttaki akış şemasıyla özetler (ekrandan, 00:50:00):

```text
Long-running HTTP downloads?
  Yes -> DownloadManager
  No  -> Deferrable work?
    No  -> Foreground service
    Yes -> Triggered by system conditions?
      Yes -> WorkManager
      No  -> Run at precise time?
        Yes -> AlarmManager
        No  -> WorkManager
```

Sözlü anlatıma göre:

- Uzun soluklu bir HTTP indirmesi varsa DownloadManager önerilir.
- İş ertelenebilir değilse foreground servis önerilir.
- İş sistem tarafından tetiklenecekse, örneğin telefon güce ya da bir ağa bağlandığında ya da şarj belli bir seviyenin üzerine çıktığında, yani sistem koşullarının takibi gerekiyorsa WorkManager kullanılır.
- Ertelenebilir bir iş kesin bir zamanda çalışmak zorunda değilse yine WorkManager kullanılır.
- Kesin bir zamanda çalışması gereken bir iş varsa AlarmManager kullanılır, ama alarmların sayısını çok artırmamak önerilir.

## 10. Cihazı Uyanık Tutmak

Android cihaz belli bir süre sonra önce ekranını kapatır, sonra CPU'sunu uyku moduna alır; bu enerji yönetimi açısından çok değerlidir. Ama bazı senaryolarda cihazın uyanık kalması gerekir. Örneğin film izlerken ya da ekrana dokunmadan uzun süre video izlerken (hoca burada "Ambient TV Mode" gibi bir yapıdan söz eder) kesintisiz izleme için uygulamada uyanık tutma özelliklerinin oluşturulması gerekir.

Hoca, uyanık tutma yerine kullanılabilecek alternatifleri de sayar:

- Cihazı wake lock ile uyanık tutup dosya indirmek yerine indirmeyi DownloadManager'a yönlendirmek.
- Uzaktaki bir sunucuyla veri senkronizasyonunu SyncAdapter'lar üzerinden, wake lock kullanmadan sisteme devretmek.
- Arka plan işleri için JobScheduler'dan yararlanmak.
- Firebase Cloud Messaging (FCM) mekanizmasını kullanmak.

### 10.1 Ekranı açık tutmak

Ekranı sürekli açık tutmanın iki yolu vardır. Birincisi aktivitede pencereye `FLAG_KEEP_SCREEN_ON` bayrağını eklemektir; ikincisi aktivitenin layout XML'ine `android:keepScreenOn="true"` özelliğini koymaktır. Bu özellik devre dışı bırakılmadıkça ekran kapanmaz. Slayttaki kodlar (ekrandan, 01:10:00):

```java
public class MainActivity extends Activity {
  @Override
  protected void onCreate(Bundle savedInstanceState) {
    super.onCreate(savedInstanceState);
    setContentView(R.layout.activity_main);
    getWindow().addFlags(WindowManager.LayoutParams.FLAG_KEEP_SCREEN_ON);
  }
}
```

```xml
<RelativeLayout xmlns:android="http://schemas.android.com/apk/res/android"
    android:layout_width="match_parent"
    android:layout_height="match_parent"
    android:keepScreenOn="true">
    ...
</RelativeLayout>
```

Slayttaki nota göre, ekranın açık kalması artık istenmediği sürece (örneğin belli bir hareketsizlikten sonra ekranın kapanması isteniyorsa) `FLAG_KEEP_SCREEN_ON` bayrağını temizlemek gerekmez. Uygulama arka plana geçtiğinde ya da ön plana döndüğünde doğru şeylerin olmasını pencere yöneticisi sağlar. Bayrak açıkça temizlenip ekranın yeniden kapanmasına izin verilmek istenirse şu kullanılır:

```java
getWindow().clearFlags(WindowManager.LayoutParams.FLAG_KEEP_SCREEN_ON);
```

> **Ders sonrası not:** Hoca bayrak yöntemi için bir izin alınması gerektiğini söyledi. Büyük olasılıkla `FLAG_KEEP_SCREEN_ON` ve `android:keepScreenOn` herhangi bir izin gerektirmez; izin (`WAKE_LOCK`) aşağıdaki CPU'yu açık tutma yöntemi için gereklidir.

### 10.2 CPU'yu açık tutmak

Ekranın yanında CPU'nun da kapanıp açılması, boşta (idle) ya da uyku modunda olması enerji tüketimi açısından kritiktir. Arka planda devam eden bir iş varsa CPU'yu belli bir süre açık bırakmak gerekebilir. Bunun için iki adım gerekir: `WAKE_LOCK` izninin alınması ve `PowerManager` üzerinden bir wake lock tanımlanması. Bu wake lock aracılığıyla CPU'nun belli bir süre uyku moduna geçmesi engellenir.

<!-- BELİRSİZ: CPU'yu açık tutan slaytın (yaklaşık 01:10:36) karesi yok; PowerManager kodu nota alınmadı. -->

### 10.3 WakefulBroadcastReceiver

Önceki haftalarda görülen broadcast receiver'ların bir varyantı WakefulBroadcastReceiver'dır. Bu receiver, arka planda CPU'nun uykuya dalmasını engelleyecek şekilde bir servisin çalıştırılmasını sağlar. Slayttaki örnekte WakefulBroadcastReceiver'dan türetilmiş bir receiver vardır; `onReceive` metodunda başlatılan servis, cihazı ayakta tutarak arka planda çalışmaya devam eder.

> **Ek bilgi (derste anlatılmadı):** `WakefulBroadcastReceiver` sınıfı büyük olasılıkla Android 8.0 (API 26) ile kullanımdan kaldırılmıştır; yeni kodlarda bunun yerine JobScheduler ya da WorkManager önerilir.

## 11. AlarmManager Ayrıntıları

AlarmManager'ın kullanım durumlarında önemli olan, kesin bir zamanda (exact time) yapılacak bir iş olup olmamasıdır. AlarmManager arka planda çalışacak uzun soluklu bir operasyonu başlatmak için de kullanılabilir. Hocanın örneği bir hava durumu tahmini bilgisinin indirilmesidir: indirme için arka plandaki servisin belirli bir zamanda başlatılması gerektiğinden bu iş AlarmManager ile yönetilebilir.

AlarmManager broadcast receiver'lar üzerinden de kullanılabilir. Bir servisin başlatılması için bir koşul sağlandığında bir `PendingIntent` tanımlanarak AlarmManager kullanılır. Alarmlar uygulamanın dışında da tetiklenebilir: uygulama çalışmıyorken, hatta cihaz uyku moduna geçmiş olsa bile ilgili dakika geldiğinde alarm devreye girer. Bunun bir maliyeti vardır: sistem bunları sürekli takip etmek zorundadır ve tam anlamıyla bir uykudan söz edilemez. Bu da pilin harcanması demektir; ne kadar çok alarm olursa arka planda enerji ve kaynak tüketme ihtimali o kadar artar.

Exact alarm ile inexact alarm arasındaki fark şudur: exact alarmda işin tam istenen zamanda gerçekleşmesi garanti edilir; inexact alarmda iş tam o noktada gerçekleşmeyebilir, sistem pil tüketimi açısından en uygun anı seçer ve alarm belli bir gecikmeyle devreye girer.

Slayttaki örnekte önce exact alarm izni alınır, sonra bir AlarmManager ve iş için bir `PendingIntent` tanımlanır ve alarm takvimle senkronlanır (ekrandan, 01:15:00):

```xml
<manifest ...>
    <uses-permission android:name="android.permission.SCHEDULE_EXACT_ALARM"/>
    <application ...>
        ...
    </application>
</manifest>
```

```java
private AlarmManager alarmMgr;
private PendingIntent alarmIntent;
...
alarmMgr = (AlarmManager)context.getSystemService(Context.ALARM_SERVICE);
Intent intent = new Intent(context, AlarmReceiver.class);
alarmIntent = PendingIntent.getBroadcast(context, 0, intent, 0);

// Set the alarm to start at 8:30 a.m.
Calendar calendar = Calendar.getInstance();
calendar.setTimeInMillis(System.currentTimeMillis());
calendar.set(Calendar.HOUR_OF_DAY, 8);
calendar.set(Calendar.MINUTE, 30);

// setRepeating() lets you specify a precise custom interval--in this case,
// 20 minutes.
alarmMgr.setRepeating(AlarmManager.RTC_WAKEUP, calendar.getTimeInMillis(),
        1000 * 60 * 20, alarmIntent);
```

Kod adım adım şunu yapar:

- `getSystemService(Context.ALARM_SERVICE)` ile sistemin alarm servisi alınır.
- `AlarmReceiver` adlı broadcast receiver'ı hedefleyen bir Intent oluşturulur ve `PendingIntent.getBroadcast(...)` ile sarılır; alarm çaldığında bu broadcast gönderilir.
- Bir `Calendar` nesnesi şimdiki zamana ayarlanır, sonra saati 8, dakikası 30 yapılır.
- `setRepeating(...)` ile alarm, `RTC_WAKEUP` türünde (duvar saati zamanına göre ve cihazı uyandırarak) kurulur. Tekrar aralığı milisaniye cinsindendir: $1000 \cdot 60 \cdot 20 = 1\,200\,000$ ms, yani 20 dakika (python ile doğrulandı).

Hoca, çalar saat ve hatırlatma uygulamalarında ya da takvime eklenen etkinliklerde bu tür alarmların günlük hayatta sürekli kullanıldığını hatırlatır.

> **Hocanın vurgusu:** Arka plan görevleri bu dersin birebir ana konusu değil; derste bu alanda çalışmak isteyenlere fikir vermek, bakılması gereken başlıkları ve genel kavramları göstermek amaçlandı. Bu alanda çalışacak olanların konuları ayrıntılı öğrenmesi faydalı olur.

## 12. Uygulama: WorkManager ile Dosya Yükleme Simülasyonu

### 12.1 Uygulamanın amacı

Dersin uygulama kısmında arka planda bir dosya yüklemesi simüle edilir. Gerçek bir yükleme yerine bir `for` döngüsü kullanılır; döngünün belli adımlarında "dosyanın %10'u, %20'si yüklendi" gibi mesajlar log alanına yazılır. İş, bir butona basılınca tetiklenir. Hoca kodu önce Android Studio'da gösterip açıklar, sonra öğrencilerden aynısını yazmalarını ister.

Proje yapısı karede şöyle görünür (ekrandan, 01:20:00):

```text
app
├── manifests
├── java
│   └── ce.yildiz.edu.tr.myapplication
│       ├── MainActivity
│       └── UploadWorker
└── res
Gradle Scripts
```

### 12.2 UploadWorker

`UploadWorker`, `Worker` sınıfından türeyen özel bir sınıftır. Varsayılan parametrelerle (Context ve WorkerParameters) oluşturulur. `doWork()` metodu önce konsola sunucuya yükleme yapıldığını yazar. Ardından bir döngü başlatır; döngü 500 milyona kadar birer birer artarak ilerler. Sayaç 50 milyonun katı olduğunda (mod alındığında sonuç sıfırsa) yüzde değeri 10 artırılır ve "uploading... %10", "%20", "%30" gibi mesajlar loga yazılır. Bu, dosyanın ne kadarının yüklendiğini her yükleme noktasında göstererek yüklemeyi simüle eder. Son ekrandaki hali (ekrandan, 01:35:00; paket ve ilk import satırları 01:20:00 karesinden):

```java
package ce.yildiz.edu.tr.myapplication;

import android.content.Context;
import android.util.Log;

import androidx.annotation.NonNull;
import androidx.work.Worker;
import androidx.work.WorkerParameters;

public class UploadWorker extends Worker {

    private static final String TAG = UploadWorker.class.getName();

    public UploadWorker(@NonNull Context context, @NonNull WorkerParameters workerParams) {
        super(context, workerParams);
    }

    @NonNull
    @Override
    public Result doWork() {
        Log.d(TAG, "Uploading files to the server...");

        int count = 0;

        for(int i = 1; i <= 500000000; i++){
            if (i % 50000000 == 0) {
                count += 10;
                Log.d(TAG, "uploading... " + count + "%");
            }
        }

        return Result.success();
    }
}
```

01:20:00 karesinde dosyanın başında iki ayrı `package` satırı görünüyordu (biri `ce.yildiz.edu.tr.myapplication`, diğeri başka bir örnek projeden kalma bir paket adı). Bir Java dosyasında yalnız bir `package` bildirimi olabilir; burada proje ağacındaki paket adı kullanıldı (ara adım eklendi). Aynı karede `doWork()` üzerinde Android Studio'nun şablon yorumu da vardı. Bu yoruma göre `doWork()` bir arka plan thread'inde çağrılır, iş senkron yapılıp bir `Result` döndürülmelidir; metot döndüğünde Worker işini bitirmiş sayılır ve yok edilir. İşin kendi seçilen bir thread'de asenkron yapılması gerekiyorsa `ListenableWorker` kullanılır. Bir Worker'a işini bitirip `Result` döndürmesi için en fazla on dakika verilir; bu süre dolunca Worker'a durması bildirilir.

Döngünün çıktısı (python ile ölçeklenmiş bir döngüyle doğrulandı): $500\,000\,000 / 50\,000\,000 = 10$ kez log yazılır ve sayaç sırasıyla 10, 20, ..., 100 değerlerini alır. Son mesaj "uploading... 100%" olur. Bir öğrenci de kendi çalıştırmasında %10'dan %100'e kadar mesajları gördüğünü doğruladı.

### 12.3 MainActivity

`MainActivity`'de bir buton vardır. Butonun dışında bir `OneTimeWorkRequest` tanımlanır; butonun `onClick` bölümünde bu istek `WorkManager` ile kuyruğa alınır (enqueue). Ayrıca işin durumunu almak için `WorkManager.getInstance(...)` üzerinden `getWorkInfoByIdLiveData(...)` çağrılır ve `observe` ile her değişiklikte worker'ın durumu log ekranına yazdırılır. Ekrandaki kod (ekrandan, 01:25:00; dosyanın ilk 14 satırı, yani paket ve import satırları karede görünmüyor):

```java
public class MainActivity extends AppCompatActivity {

    private static final String TAG = MainActivity.class.getName();

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        final Button button = findViewById(R.id.button);
        final OneTimeWorkRequest workRequest = new OneTimeWorkRequest.Builder(UploadWorker.class).build();

        button.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                WorkManager.getInstance(v.getContext()).enqueue(workRequest);
            }
        });

        // Get the work status
        WorkManager.getInstance(getApplicationContext()).getWorkInfoByIdLiveData(workRequest.getId())
                .observe(this, new Observer<WorkInfo>() {
                    @Override
                    public void onChanged(WorkInfo workInfo) {
                        Log.d(TAG, "Worker status: " + workInfo.getState().name());
                    }
                });
    }
}
```

Kodun akışı:

- `OneTimeWorkRequest.Builder(UploadWorker.class).build()` ile `UploadWorker`'ı bir kez çalıştıracak istek oluşturulur.
- Butona basılınca `WorkManager.getInstance(...).enqueue(workRequest)` isteği kuyruğa alır; WorkManager işi arka planda çalıştırır.
- `getWorkInfoByIdLiveData(workRequest.getId())` bir LiveData döndürür; `observe(this, ...)` ile aktivite yaşam döngüsüne bağlı bir gözlemci eklenir. İşin durumu her değiştiğinde `onChanged` çağrılır ve durumun adı loga yazılır.

> **Ek bilgi (derste anlatılmadı):** WorkManager'ı kullanmak için uygulamanın `build.gradle` dosyasına `androidx.work:work-runtime` bağımlılığının eklenmesi gerekir. `WorkInfo.State` büyük olasılıkla ENQUEUED, RUNNING, SUCCEEDED, FAILED, BLOCKED ve CANCELLED değerlerini alır; bu örnekte loglarda tipik olarak ENQUEUED, RUNNING ve SUCCEEDED görülür.

### 12.4 Soru-cevap ve sonraki adım

**Soru:** Bir öğrenci `WorkManager.getInstance` çağrısının Android Studio'da tanınmadığını, API 30 kullandığını söyledi. **Cevap:** Hoca normalde `getInstance`'ın çalışması gerektiğini, sürüm farkından olduğunu sanmadığını, büyük olasılıkla worker henüz oluşturulmadığı için böyle bir sorun yaşandığını tahmin etti. Öğrenci daha sonra sorunun kendi hatasından kaynaklandığını ve çözüldüğünü bildirdi.

Uygulamanın sonraki adımı olarak hoca şunu ister: uygulamada bir Broadcast Receiver tanımlanacak ve telefon şarja takıldığında bu receiver, aynı worker'ı tetikleyerek %10, %20, %30 ... yükleme işlemini başlatacaktır. Önce butonla başlanması, ardından şarj tetiklemesine geçilmesi önerildi.

## Örnek Sorular

### Soru 1

(derste sözlü, 01:44:56)

Derste worker ile bir yükleme simülasyonu yapıldı. Bu worker yapısını kullanabileceğimiz başka bir uygulama örneği verin.

> **Derste verilen cevap:** Hoca örnek olarak virüs taramasını sordu: arka planda dosyaları tek tek kontrol edip tarayan bir uygulama worker ile yapılabilir. Ayrıca arka planda resim ya da video işleme örneğini verdi: ikincil bellekteki fotoğrafları işlemek uzun sürer ve bu iş arka planda bir worker ile yapılabilir.

### Soru 2

(derste sözlü, 01:21:35 ve 01:42:58)

Uygulamaya bir Broadcast Receiver ekleyin: telefon şarja takıldığında receiver, `UploadWorker`'ı WorkManager ile çalıştırsın ve yükleme simülasyonu başlasın.

> **Çözüm (derste verilmedi):** Aşağıdaki çözüm ajan tarafından yazılmıştır; derleyici ve cihaz üzerinde test edilmemiştir. Android 8.0 (API 26) ve sonrasında `ACTION_POWER_CONNECTED` gibi örtük broadcast'ler büyük olasılıkla manifest'te tanımlanan receiver'lara iletilmez; bu yüzden receiver aktivitede çalışma anında kaydedilir.

```java
// MainActivity içinde (ek alan ve yaşam döngüsü metotları)
private final BroadcastReceiver chargingReceiver = new BroadcastReceiver() {
    @Override
    public void onReceive(Context context, Intent intent) {
        if (Intent.ACTION_POWER_CONNECTED.equals(intent.getAction())) {
            OneTimeWorkRequest request =
                    new OneTimeWorkRequest.Builder(UploadWorker.class).build();
            WorkManager.getInstance(context).enqueue(request);
        }
    }
};

@Override
protected void onStart() {
    super.onStart();
    registerReceiver(chargingReceiver, new IntentFilter(Intent.ACTION_POWER_CONNECTED));
}

@Override
protected void onStop() {
    super.onStop();
    unregisterReceiver(chargingReceiver);
}
```

> Uygulama kapalıyken de şarj koşuluna bağlı çalışma isteniyorsa receiver yerine WorkManager'ın kendi koşul mekanizması büyük olasılıkla daha uygundur: `new OneTimeWorkRequest.Builder(UploadWorker.class).setConstraints(new Constraints.Builder().setRequiresCharging(true).build()).build()` biçiminde oluşturulan istek, cihaz şarja takılı olduğunda çalıştırılır. Bu, derste anlatılan "sistem koşullarıyla tetiklenen iş için WorkManager" kuralıyla da uyumludur.

## Dersin Toparlaması

Bu derste Android'de uzun süren işlerin neden ana thread dışına taşınması gerektiği, arka plan işlerinin pil ve bellek üzerindeki etkisi ve Android'in Doze modundan App Standby Bucket'lara kadar uzanan önlemleri işlendi. Arka plan işleri immediate, long running ve deferrable olarak sınıflandırıldı; her birinin persistent ya da impersistent olabileceği görüldü. Her durum için önerilen yapılar (WorkManager ile `OneTimeWorkRequest` ve `PeriodicWorkRequest`, coroutine'ler ve Executor'lar, DownloadManager, foreground servisler, AlarmManager) ve bunlar arasında seçim yapan karar akışı anlatıldı. Ardından servisler, cihazı uyanık tutma yöntemleri ve AlarmManager örneği ele alındı.

Uygulama kısmında `Worker`'dan türeyen bir `UploadWorker` ile dosya yükleme simüle edildi; iş bir butonla `OneTimeWorkRequest` olarak kuyruğa alındı ve durumu LiveData ile izlendi. Bir sonraki adım olarak işin telefon şarja takıldığında bir Broadcast Receiver tarafından tetiklenmesi istendi. Hoca sonraki derste konum tabanlı işlerin anlatılacağını, vakit kalırsa bir uygulamanın Google Play Store'a yüklenmesinde izlenecek adımlara da değinileceğini söyledi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
