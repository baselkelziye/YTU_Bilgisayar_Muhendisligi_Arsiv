# Ders 12 Çalışma Özeti

## Genel Konular

- Arka plan işlerine (background tasks) neden ihtiyaç var? (ekrandan, 00:15:00)
  - Her Android uygulamasının bir ana thread'i (main/UI thread) vardır. Bu thread arayüzü çizmekten, kullanıcı etkileşimlerini koordine etmekten ve yaşam döngüsü olaylarını almaktan sorumludur. Servisler dışındaki bütün uygulamalarda bir arayüz, dolayısıyla bir ana thread bulunur.
  - Bitmap decode etme, diske erişme, ağ isteği yapma gibi uzun süren hesaplama ve işlemler ayrı bir arka plan thread'inde yapılmalıdır. Genel kural: birkaç milisaniyeden uzun süren her iş arka plan thread'ine devredilir.
  - Örnek işler: resim işleme (decode/encode), diskten bilgi taşıma ya da diske yazma, buluta veya uzaktaki bir birime veri gönderme ve oradan veri alma.
  - Java tarafında Thread kütüphanesi, Kotlin tarafında coroutine'ler kullanıcının başlattığı ve o anda yapılacak arka plan işleri için temel araçlardır.
- Arka plan işlemenin gerekçeleri (ekrandan, 00:20:00)
  - G/Ç (I/O) olaylarının arayüzü bloklamasını ve "Application Not Responding" (ANR) iletişim kutusunu önlemek. Donan uygulama kötü kullanıcı deneyimi demektir.
  - HTTP çağrıları gibi bazı işlemlerin ana thread'de çalışmasına izin verilmez.
  - Performansı artırmak.
  - Thread'e ayırmanın asıl amacı telefonda kullanıcı etkileşiminin kesintisiz sürmesidir; bu yüzden tek çekirdekli işlemcili telefonda da aynı ilkeler geçerlidir.
- Arka plan işlemenin zorlukları ve Android sürümleriyle gelen kısıtlar (ekrandan, 00:25:00)
  - Arka plan işleri RAM ve pil gibi sınırlı kaynakları tüketir. Her uygulama her şeyi arka planda çalıştırsaydı şarj çok çabuk biterdi.
  - Android 6.0 (API 23): Doze modu ve App Standby. Doze, ekran kapalı ve cihaz hareketsizken uygulama davranışını kısıtlar; App Standby kullanılmayan uygulamaların ağ erişimini, job'larını ve senkronizasyonlarını kısıtlar.
  - Android 7.0 (API 24): örtük (implicit) broadcast'ler kısıtlandı, Doze-on-the-Go geldi (cihaz cepte ya da çantada hareket ederken de, ekran kapalıysa kısıtlama).
  - Android 8.0 (API 26): arka plan davranışı daha da kısıtlandı (arka planda konum alma, önbelleğe alınmış wakelock'ları bırakma).
  - Android 9 (API 28): App Standby Buckets; uygulamaların kaynak istekleri kullanım örüntüsüne göre dinamik olarak önceliklendirilir.
- App Standby Buckets (ekrandan, 00:30:00)
  - Sistem uygulamaları kullanım sıklığına göre kovalara (bucket) dinamik ve otomatik olarak yerleştirir; uygulama zamanla kovalar arasında geçebilir. Yerleştirmeyi bir makine öğrenmesi yapısı yapar.
  - Active: uygulama o anda kullanılıyor ya da çok yakın zamanda kullanılmış (bir aktivite başlatmış, foreground servis çalıştırıyor, ön plandaki bir uygulamanın content provider'ına bağlı sync adapter'ı var, kullanıcı uygulamanın bildirimine tıklamış). Bu kovada job, alarm ve FCM mesajlarına hiçbir kısıt uygulanmaz.
  - Working set: sık kullanılan ama şu an aktif olmayan uygulamalar (ör. sosyal medya); görece ılımlı kısıtlar.
  - Frequent: düzenli ama her gün kullanılmayan uygulamalar (ör. haftada 2-3 gün açılan egzersiz uygulaması); daha sert kısıtlar.
  - Rare: seyrek kullanılan uygulamalar (ör. yalnız seyahatte açılan otel ya da gezi uygulaması); çok daha katı kurallar.
  - Hiç açılmamış, yalnız indirilmiş uygulamalar için ayrıca özel bir kova vardır.
- Kovalarla ilgili iyi uygulamalar (ekrandan, 00:35:00)
  - Uygulamayı belli bir kovaya sokmak için sistemi manipüle etmeye çalışmayın; uygulama hangi kovada olursa olsun düzgün davranmalıdır.
  - Launcher aktivitesi olmayan uygulama hiçbir zaman active kovasına yükselemeyebilir.
  - Bildirimleri etkileşimli (actionable) olmayan uygulama, kullanıcı bildirime dokunarak uygulamayı active kovasına taşıyamaz.
  - Yüksek öncelikli FCM mesajı alınınca bildirim gösterilmezse kullanıcıya etkileşim şansı verilmez; yüksek öncelik yalnız bildirim göstermek içindir.
- Doğru çözümü seçmek için sorulacak sorular (ekrandan, 00:40:00)
  - Kullanıcı işe dahil mi (ör. müzik başlatıp durdurma)? İş bölünebilir mi, kaldığı yerden devam edebilir mi? İş ertelenebilir mi, yoksa hemen mi yapılmalı?
  - İş sistem koşullarına bağlı mı (şarja bağlı olma, internet bağlantısı, Wi-Fi, pil seviyesi)?
  - Hassas kullanıcı verisi toplanıyor ya da kullanılıyor mu (ör. navigasyonda konum)?
  - İş kesin (exact) bir zamanda mı çalışmalı (takvim hatırlatıcısı, ilaç hatırlatma)? Bu durumda AlarmManager gerekir; ama çok sayıda alarm CPU'yu ayakta tutar ve pili hızlı tüketir.
- Arka plan işinin tanımı ve türleri (ekrandan, 00:45:00)
  - Bir uygulama arka planda sayılır: hiçbir aktivitesi kullanıcıya görünmüyorsa ve kullanıcıya görünürken başlatılmış bir foreground servisi çalışmıyorsa. Aksi hâlde ön plandadır.
  - Üç ana kategori: Immediate (hemen çalışıp kısa sürede bitmeli), Long Running (tamamlanması zaman alabilir), Deferrable (hemen çalışması gerekmez).
  - Her kategori Persistent (uygulama yeniden başlasa ve cihaz yeniden açılsa da planlı kalır) ya da Impersistent (süreç bitince planlanmış olmaktan çıkar) olabilir.
- Önerilen çözümler (ekrandan, 01:05:00)
  - Persistent işler için WorkManager. WorkManager, JobScheduler servisinin üzerine oturan ve geliştiricinin işini kolaylaştıran yapıdır.
  - Persistent immediate iş: WorkManager + `OneTimeWorkRequest`, `setExpedited()` ile hızlandırılır.
  - Impersistent immediate iş: Kotlin coroutine'leri; Java'da RxJava, Guava ya da Executors (ExecutorService).
  - Örnek: veri kaynağından veri çekme ana thread'i bloklar, coroutine içinde yapılmalı. Sohbet uygulamasında mesaj gönderme: bir `Worker` oluşturulur, `WorkRequest` olarak kuyruğa alınır ve `setExpedited()` ile hızlandırılır.
  - Long running iş (10 dakika ve üzeri olabilir, ör. büyük dosya indirme): WorkManager/Worker.
  - Deferrable iş (ör. backend ile periyodik senkronizasyon): `PeriodicWorkRequest` ile bir Worker; sıklık verilir, kesin dakikayı sistem kaynak durumuna göre seçer. Planlanmış işler uygulama kapansa ya da telefon yeniden başlasa da korunur.
- Alarmlar (ekrandan, 01:10:00)
  - Alarmlar arka plan işinin parçası olmayan özel bir kullanım durumudur. Arka plan işleri coroutine'ler ve WorkManager ile yapılmalıdır.
  - AlarmManager yalnız kesin zamanlı alarmlar için (çalar saat, takvim etkinliği) kullanılmalıdır. Arka plan işini AlarmManager ile planlamak cihazı Doze modundan uyandırır, pil ömrüne ve sistem sağlığına olumsuz etki eder; sorumluluk uygulamanındır.
- Foreground servisler ve WorkManager ile değiştirilmeleri (ekrandan, 01:15:00)
  - Kullanıcının başlattığı, hemen çalışması ve tamamlanması gereken iş için foreground servis kullanılır; sisteme "önemli bir iş yapıyorum, öldürme" der.
  - Bildirim alanında kaldırılamayan bir bildirimle kullanıcıya görünür (ör. konum takibinde GPS simgesi, müzik uygulaması). İşin ne zaman başlayıp duracağı üzerinde kesin kontrol gerektiğinde en uygun çözümdür. Tipik örnek: müzik uygulaması.
  - Android 12 ile foreground servislere alternatif olarak WorkManager'ın `setForeground` kullanımı önerilmektedir.
- Servisler (ekrandan, 01:20:00)
  - Servis, arayüzü olmayan ve arka planda çalışan bir uygulama bileşenidir (ör. ağ paketlerini saldırı için izleme, sağlık uygulamasında hareket verisi toplama).
  - Foreground / background ayrımı: background serviste kullanıcı müdahalesi yoktur (ör. depolamayı arka planda düzenleyen servis).
  - Unbounded (started) servis: `startService()` → `onCreate()` → `onStartCommand()` → çalışıyor; kendisi ya da bir istemci durdurur → `onDestroy()`.
  - Bounded servis: `bindService()` → `onCreate()` → `onBind()` → istemciler servise bağlı; bütün istemciler `unbindService()` çağırınca `onUnbind()` → `onDestroy()`.
  - Servis `startService()` ya da `startForegroundService()` ile bir Intent verilerek başlatılır; `stopService()` ile başka bir bileşen, kendisi ise kendi kendine durdurabilir. Servis de aktiviteler gibi manifestte `application` etiketinin içinde tanımlanmalıdır.
  - Durdurulamayan servisler kaynakları tüketir; sistem sıkışınca önce arka plan servislerini öldürür. Bugün uzun sürmeyen ve sürekli takip gerektirmeyen işlerde servisten uzak durulur.
- Cihazı uyanık tutmak (ekrandan, 01:25:00)
  - Uyanıklığın iki kademesi vardır: ekranın açık olması ve CPU'nun uykuya geçmemesi. İşletim sistemi ikisini de mümkün olduğunca erken kapatmak ister.
  - Wakelock'tan önce alternatiflere bakılır: uzun HTTP indirmeleri için `DownloadManager`, harici sunucuyla senkronizasyon için sync adapter, belli aralıklarla tetiklenecek arka plan servisleri için JobScheduler ya da Firebase Cloud Messaging, yakındaki eşlik eden cihaz için Companion Device Manager.
  - Ekranı açık tutmak (video oynatıcı, oyun, Netflix gibi içerik uygulamaları): XML layout'ta "keep screen on" özniteliğini true yapmak ya da pencerenin bayrağını ayarlamak; iş bitince kapatılabilir.
  - CPU'yu açık tutmak (ekrandan, 01:30:00): `PowerManager` sistem servisinin wakelock özelliği; manifestte `android.permission.WAKE_LOCK` izni gerekir. Örnek: bebek takip uygulamasında görüntü/sesin sürekli işlenmesi.

## Hocanın Özellikle Vurguladığı Kısımlar

- Birkaç milisaniyeden uzun süren iş ana thread'de yapılmaz
  - Aksi hâlde arayüz bloklanır; uzun bloklamada (hocanın hatırladığına göre yaklaşık 5 saniye) ANR penceresi çıkar.
- Android, iOS'un çizgisine yaklaşarak arka plan işlerini sürüm sürüm kısıtlıyor
  - Sürümler ilerledikçe pil tüketimi kötüleşmesi beklenirken, bu kısıtlar sayesinde iyileşiyor.
- Hangi işin hangi yapıyla yapılacağı
  - Tekrar eden, ertelenebilir ve uzun süren işler için WorkManager; hemen yapılacak tek seferlik işler için coroutine / Executor; kesin zaman için yalnız AlarmManager.
  - Thread'i kendiniz yaratmak yerine ExecutorService'in thread havuzunu kullanmak daha verimlidir.
- AlarmManager'ı arka plan işi için kullanmayın
  - Cihazı Doze'dan uyandırır; kullanıcı bilinçli olmasa da şarjı çabuk biter.
- Bucket'lara karşı tasarım
  - Active kovasına çıkmak için launcher aktivitesi ve etkileşimli bildirimler gerekir; yoksa uygulama en fazla working set ya da frequent seviyesinde kalır.
- Servis mi thread mi?
  - Eskiden her şey serviste yapılabiliyordu; bugün iş uzun sürmüyorsa ve arka plan takibi gerektirmiyorsa servisten uzak durulur.

## Kısa Tekrar Notları

- Ana thread = UI thread; arayüz, etkileşim ve yaşam döngüsü olayları.
- Disk, ağ, bitmap gibi uzun işler arka plan thread'ine; HTTP çağrısı ana thread'de yapılamaz.
- Kısıt tarihçesi: 6.0 Doze + App Standby, 7.0 Doze-on-the-Go + implicit broadcast kısıtı, 8.0 arka plan konum kısıtı, 9 App Standby Buckets.
- Kovalar: Active (kısıt yok) > Working set > Frequent > Rare; hiç açılmamış uygulamalara ayrı kova.
- Arka plan işi kategorileri: Immediate, Long Running, Deferrable; her biri Persistent ya da Impersistent.
- WorkManager, JobScheduler'ın üstünde; `OneTimeWorkRequest`, `PeriodicWorkRequest`, `setExpedited()`, `setForeground`.
- Impersistent immediate: coroutine, RxJava, Guava, Executors.
- AlarmManager yalnız çalar saat / takvim gibi kesin zamanlı işler için.
- Foreground servis: kaldırılamaz bildirim, kullanıcı başlatır ve durdurur.
- Unbounded servis: `startService` → `onCreate` → `onStartCommand` → `onDestroy`. Bounded servis: `bindService` → `onCreate` → `onBind` → `onUnbind` → `onDestroy`.
- Servis manifestte `application` içinde tanımlanır.
- Wakelock yerine önce `DownloadManager`, sync adapter, JobScheduler / FCM, Companion Device Manager düşünülür.
- CPU için `PowerManager.PARTIAL_WAKE_LOCK` + `WAKE_LOCK` izni; ekran için "keep screen on".

## Detaylı Açıklamalar

- Ana thread ve arka plan işleri
  - Android'de arayüzü yöneten tek bir ana thread vardır ve bu thread aktivitenin yaşam döngüsüyle birlikte yaşar. Kullanıcının bir butona basabilmesi için ana thread'in uzun bir işin bitmesini beklememesi gerekir. Bu yüzden ağ, disk ve resim işleme gibi asenkron işler ayrı thread'lere ya da Android'in sunduğu yapılara taşınır. Masaüstünde thread'ler farklı amaçlarla ortaya çıkmıştır; telefonda asıl amaç kullanıcı deneyimini kesintisiz tutmaktır.
  - Uygulama belli bir süre bloklanırsa "Application Not Responding" penceresi açılır ve kullanıcı onu kapatana kadar bir şey yapamaz. Arka plan işlemenin amacı I/O ve ağ olaylarını arayüzden ayırarak bu hatayı önlemektir.
- Neden kısıtlama?
  - Arka plan işlerinin sayısı arttıkça RAM ve özellikle pil tüketimi artar. Doze, cihazın kullanılmadığını (ekran kapalı, IMU/jiroskop ile hareketsizlik) işletim sistemi düzeyinde anlayarak kullanılmayan uygulamaların arka plan işlerini kısıtlar. Hocanın benzetmesiyle, WhatsApp ya da Telegram gibi bir uygulamanın mesaj kontrolü telefon kullanılmazken saniyede birden 5 saniyeye, 10 saniyeye, yarım dakikaya düşer; böylece telefonun sürekli uyanması gerekmez.
  - Broadcast receiver'lar da bir arka plan işidir: uygulama içi mesajlaşmada LocalBroadcastManager tercih edilir, sistem seviyesindeki değişikliklere abone olmak her zaman telefona yük getirir.
  - Eskiden bir servisle arka planda sürekli konum takibi yapılabiliyordu; Android 8 ile buna kurallar geldi.
- App Standby Buckets
  - Android 9 ile gelen pil yönetimi özelliğidir. Uygulamalar kullanım sıklığına göre kovalara yerleştirilir ve kaynak istekleri buna göre karşılanır. Bir fedakârlık gerekiyorsa bu, sık kullanılan uygulamalardan değil az kullanılanlardan yapılır; az kullanılan uygulamanın sürekli arka plan işi yapması hem kaynak tüketir hem de kötü amaçlı bir davranışın işareti olabilir.
- İş türüne göre seçim
  - Persistent ve Impersistent ayrımı, işin uygulama ya da cihaz yeniden başladığında yeniden çalışıp çalışmayacağıdır. Android tekrar eden ve ertelenebilir işlerin WorkManager ile, tek seferlik ve hemen yapılacak işlerin coroutine ya da Executor ile yönetilmesini önerir.
  - ExecutorService bir thread havuzu sunar; iş havuza atanır, thread'i sistem havuzdan çeker. Bu, her iş için kendi thread'ini yaratmaktan daha verimlidir; JobScheduler'daki gibi kaynakların sistemce yönetilmesi fikrine dayanır.
  - Ertelenebilir işlerde, örneğin backend ile senkronizasyonda, "tam saat 12'de" gibi bir zorunluluk yoksa `PeriodicWorkRequest` ile sıklık (günlük, saatlik) bildirilir; sistem birden fazla işi bir araya getirip uygun anda çalıştırır.
- Servisler
  - Servis arayüzü olmayan bir uygulama bileşenidir ama yine de manifestte tanımlanmalıdır. Bounded servis ona bağlanan istemcilere bağlı yaşar; unbounded servis durdurulana kadar çalışır. Durdurulamayan bir servis sistem kaynaklarını ciddi ölçüde tüketir; Android böyle durumlarda önce arka plan servislerini öldürür.
- Cihazı uyanık tutmak
  - Wakelock telefonu sürekli ayakta tutar ve pili hızla tüketir; Android bunun için alternatifler sunmuştur. Video ve oyun gibi uygulamalarda ekranın açık kalması için layout özniteliği ya da pencere bayrağı kullanılır. CPU'nun açık kalması gereken durumlarda (ör. bebeğin odasındaki telefonun görüntü/sesi sürekli işlemesi) `PowerManager` üzerinden wakelock alınır:

```java
// (ekrandan, 01:30:00)
// Manifest: <uses-permission android:name="android.permission.WAKE_LOCK" />
PowerManager powerManager = (PowerManager) getSystemService(POWER_SERVICE);
WakeLock wakeLock = powerManager.newWakeLock(PowerManager.PARTIAL_WAKE_LOCK,
        "MyApp::MyWakelockTag");
wakeLock.acquire();
```

  - Wakeful Broadcast Receiver'lar da anıldı; ayrıntıya girilmedi.
  - <!-- BELİRSİZ: 01:31:13 civarında Calendar ve PendingIntent ile bir şeyin (büyük olasılıkla bir alarmın) ayarlandığı bir kod parçasından söz ediliyor; kare yok, kod okunamadı. -->

- Ders sonrası notlar
  - Hoca JobScheduler'ın "yanlış hatırlamıyorsam Android 11 ya da 12 ile" aktif kullanılmaya başladığını söyledi (01:26:52); JobScheduler API'si büyük olasılıkla Android 5.0 (API 21) ile gelmiştir.
  - Hoca wakelock için kullanıcıdan izin alınması gerektiğini söyledi (01:29:23); `WAKE_LOCK` büyük olasılıkla normal bir izindir, manifestte bildirilir ve kurulumda kullanıcıya sorulmadan verilir.
  - Hoca bound servisin bağlı olduğu uygulama sonlanınca kendini sonlandırdığını söyledi (01:20:39); slayttaki akışa göre (ekrandan, 01:20:00) bound servis, bütün istemciler `unbindService()` ile bağlantıyı kopardığında yok edilir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
