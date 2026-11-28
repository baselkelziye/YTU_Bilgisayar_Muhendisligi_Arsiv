# Ders 2 Çalışma Özeti

## Genel Konular

- Arka plan işlerine neden ihtiyaç duyulur?
  - Her Android uygulamasında kullanıcı arayüzünü çizen, kullanıcı etkileşimlerini koordine eden ve yaşam döngüsü olaylarını alan tek bir ana thread (main/UI thread) vardır (ekrandan, 00:10:00).
  - Bitmap çözme, diske erişme, ağ isteği yapma gibi uzun süren işler ana thread üzerinde yapılırsa arayüz donar; durum "Application Not Responding" (ANR) hatasına kadar gidebilir.
  - Genel kural: birkaç milisaniyeden uzun süren her iş ayrı bir arka plan thread'ine devredilmelidir. Hoca bu sınırı kabaca 5-10 milisaniye olarak verdi.
  - Tipik arka plan işleri: ağ üzerinden dosya indirme ve yükleme, diskteki büyük bir dosyanın belleğe taşınması, multimedya dosyaları üzerinde işlem yapılması.
- Arka plan işlemenin zorlukları ve Android'in aldığı önlemler
  - Arka plan işleri RAM ve pil gibi sınırlı kaynakları tüketir; doğru yönetilmezse kullanıcı deneyimi kötüleşir (ekrandan, 00:15:00).
  - Android 6.0 (API 23): Doze modu ve App Standby. Doze, ekran kapalıyken ve cihaz hareketsizken uygulama davranışını kısıtlar; App Standby kullanılmayan uygulamaların ağ erişimini, işlerini (job) ve senkronizasyonlarını kısıtlar.
  - Android 7.0 (API 24): örtük (implicit) broadcast'ler sınırlandı ve "Doze-on-the-Go" geldi; cihaz cepte taşınırken de kısıtlama uygulanır.
  - Android 8.0 (API 26): arka planda konum alma gibi davranışlar daha da sınırlandı (yalnız slaytta).
  - Android 9 (API 28): App Standby Bucket'lar; uygulamaların kaynak istekleri kullanım örüntüsüne göre dinamik olarak önceliklendirilir. Hoca bu takibin sistem tarafında bir makine öğrenmesi modeliyle yapıldığını söyledi.
- App Standby Bucket'lar (4 + 1 kova)
  - Active: o anda kullanılan ya da yeni kapatılan uygulama; foreground servis kullanan, bildirimine tıklanan uygulamalar da buraya girer. Arka plan işleri kısıtlanmaz.
  - Working Set: sık kullanılan ama o anda aktif olmayan uygulama (örnek: her gün açılan bir sosyal medya uygulaması). Hafif kısıtlamalar uygulanır (ekrandan, 00:20:00).
  - Frequent: düzenli ama her gün olmayan kullanım (örnek: iki üç günde bir açılan spor takip uygulaması). Daha fazla kısıtlama vardır.
  - Rare: ayda bir ya da yılda birkaç kez kullanılan uygulamalar (örnek: seyahatte kullanılan otel uygulamaları). Katı kısıtlamalar vardır.
  - Never: indirilmiş ama hiç açılmamış uygulamalar; en kısıtlı kova.
  - Uygulamalar kullanım azaldıkça alt kovalara düşebilir. Kovayı sistem kendisi belirler.
- Doğru çözümü seçmek için sorulacak sorular (ekrandan, 00:25:00)
  - Başlama ve durma zamanı üzerinde kesin kontrol gerekiyor mu? (müzik uygulaması evet; log yükleme hayır)
  - İş gerekirse bölünebilir mi? (çok büyük bir dosya yüklemesi bölünürse baştan başlamak gerekebilir; küçük log dosyalarında sorun olmaz)
  - İş ertelenebilir mi, yoksa hemen mi yapılmalı? (butona basınca veri çekmek hemen; logları sunucuya yollamak ertelenebilir)
  - Ağ bağlantısı, şarja takılı olma gibi sistem koşullarına bağlı mı?
  - Navigasyon gibi hassas veri (konum) kullanan ve sık güncellenen bir iş mi? Bu durumda foreground servis önerilir.
  - Kesin bir saatte mi çalışmalı (alarm, takvim hatırlatması)? Bir iş bittikten sonra başka bir işin başlaması mı gerekiyor?
- Arka plan işinin tanımı ve türleri (ekrandan, 00:30:00)
  - Bir uygulama, hiçbir aktivitesi kullanıcıya görünür değilse ve görünür bir aktiviteden başlatılmış bir foreground servis çalıştırmıyorsa arka planda sayılır; aksi halde ön plandadır.
  - Üç ana kategori: Immediate (hemen çalışıp kısa sürede bitmeli), Long Running (tamamlanması zaman alır; hoca 10 dakika ve üzerini örnek verdi), Deferrable (hemen çalışması gerekmez).
  - Her biri ayrıca Persistent (uygulama yeniden başlasa ya da cihaz yeniden açılsa da zamanlanmış kalır) ya da Impersistent (süreç bitince zamanlaması kalkar) olabilir.
- Kategorilere göre önerilen çözümler
  - Persistent immediate iş: WorkManager ile `OneTimeWorkRequest`, `setExpedited()` ile öne alınır (ekrandan, 00:35:00).
  - Impersistent immediate iş: Kotlin coroutine'leri; Java'da RxJava, Guava ya da Executor'lar; kısa ve tekrarlanmayan işlerde Java `Thread`/`Runnable`.
  - Long running iş: WorkManager'daki worker yapısı; bölünemeyen büyük indirmeler için worker ya da DownloadManager.
  - Deferrable iş: acelesi olmayan, belli aralıklarla tekrarlanan senkronizasyon gibi işler için `PeriodicWorkRequest`; sistem uygun anı kendisi seçer.
  - Alarmlar: AlarmManager yalnız kesin zamanlı alarmlar (çalar saat, takvim etkinliği) için kullanılmalıdır; cihazı Doze'dan uyandırdığı için pile olumsuz etkisi vardır (ekrandan, 00:40:00).
  - Foreground servis: medya oynatma, aktivite takibi, konum paylaşımı, sesli/görüntülü görüşme gibi kullanıcının farkında olduğu ve bildirim çekmecesinden kontrol edebildiği işler.
- Servisler
  - Servis, arka planda uzun süren işler yapan ve kullanıcı arayüzü olmayan bir uygulama bileşenidir. Başka bir bileşen servisi başlatabilir ya da servise bind olup onunla etkileşebilir, hatta süreçler arası iletişim (IPC) yapabilir (ekrandan, 00:45:00).
  - İki temel tür: foreground servis (küçük de olsa bir arayüz/bildirimle kontrol edilir) ve background servis (arayüzü yok).
  - Servis `startService()` ya da `startForegroundService()` ile başlatılır, iş bitince durdurulmalıdır; durdurulmazsa kaynak sıkıntısında sistem servisi kendisi öldürebilir.
  - Servis manifest'te `<application>` içinde tanımlanır.
  - Servis uzun süren işler içindir; thread ise çok kısa süreli ve tekrarlanmayan işler için önerilir.
- Karar akışı (ekrandan, 00:50:00)
  - Uzun süren HTTP indirmesi ise DownloadManager; değilse ve iş ertelenemiyorsa foreground servis; ertelenebilir ve sistem koşullarıyla tetikleniyorsa WorkManager; kesin bir saatte çalışması gerekiyorsa AlarmManager; hiçbiri değilse yine WorkManager.
- Cihazı uyanık tutmak
  - Ekranı açık tutmak: aktivitede `FLAG_KEEP_SCREEN_ON` bayrağı ya da layout XML'inde `android:keepScreenOn="true"` (ekrandan, 01:10:00).
  - CPU'yu açık tutmak: `WAKE_LOCK` izni ve `PowerManager` üzerinden bir wake lock.
  - WakefulBroadcastReceiver: `onReceive` içinde başlatılan servis çalışırken cihazın uykuya geçmesini engeller.
  - Wake lock yerine mümkünse alternatifler: indirme için DownloadManager, sunucuyla senkronizasyon için SyncAdapter, JobScheduler ve Firebase Cloud Messaging (FCM).
- AlarmManager ayrıntıları
  - Exact alarm tam zamanda çalışır; inexact alarm sistemin pil açısından uygun gördüğü bir anda biraz gecikmeyle çalışır.
  - Exact alarm için manifest'te `SCHEDULE_EXACT_ALARM` izni gerekir; iş bir `PendingIntent` ile tanımlanır (ekrandan, 01:15:00).
- Uygulama: WorkManager ile dosya yükleme simülasyonu
  - `Worker`'dan türeyen `UploadWorker` sınıfı, `doWork()` içinde bir döngüyle yüklemeyi simüle eder ve her %10'da log yazar (ekrandan, 01:35:00).
  - `MainActivity`'de bir butona basılınca `OneTimeWorkRequest` kuyruğa alınır ve işin durumu LiveData ile izlenir (ekrandan, 01:25:00).
  - Sonraki adım olarak telefon şarja takıldığında işi bir Broadcast Receiver'ın tetiklemesi istendi.

## Hocanın Özellikle Vurguladığı Kısımlar

- Uygulamanın standby kovasına geliştirici müdahale etmemelidir
  - Kovayı sistem belirler; müdahale sistemde sorunlara yol açabilir.
- Active kovaya girebilmek için launcher aktivitesi ya da eyleme dönüştürülebilir bildirim gerekir
  - Launcher aktivitesi olmayan ve bildirimleri kullanıcıya bir eylem sunmayan bir uygulamanın Active kovaya girme olasılığı yoktur.
- AlarmManager'ın sayısı az tutulmalıdır
  - Her alarm cihazı uyandırır ve tam bir uykuyu engeller; alarm sayısı arttıkça enerji ve kaynak tüketimi artar. Kesin saat gerekmiyorsa WorkManager tercih edilmelidir.
- Google, arka plan işlerinin mümkün olduğunca WorkManager altında yönetilmesini öneriyor
  - WorkManager bağlantı, şarj gibi koşulları izler ve koşullar oluşunca ertelenebilir işleri çalıştırır; bu da kaynak verimliliği sağlar.
- Kullanıcının başlatıp kontrol ettiği işler foreground servis olmalıdır
  - Müzik ve navigasyon uygulamaları bildirim çekmecesinden durdurulabilir, başlatılabilir olmalıdır.
- Arka plan görevleri konusu derin bir konudur
  - Derste genel kavramlar ve bakılması gereken başlıklar verildi; bu alanda çalışacak olanların ayrıntılara da bakması önerildi.

## Kısa Tekrar Notları

- Ana thread = UI thread; birkaç ms'den uzun işler arka plana.
- Uzun işi ana thread'de yapmak: donma, ANR.
- Doze (6.0), Doze-on-the-Go (7.0), arka plan sınırları (8.0), App Standby Bucket (9).
- Kovalar: Active, Working Set, Frequent, Rare, Never; aşağı indikçe kısıtlama artar.
- İş türleri: Immediate, Long Running, Deferrable; her biri Persistent ya da Impersistent.
- Persistent iş: WorkManager. Impersistent kısa iş: coroutine, Executor, Thread.
- Tekrarlanan ertelenebilir iş: `PeriodicWorkRequest`; tek seferlik: `OneTimeWorkRequest`.
- Kesin saat: AlarmManager (exact); esnek saat: inexact alarm ya da WorkManager.
- Uzun HTTP indirmesi: DownloadManager.
- Kullanıcının kontrol ettiği iş: foreground servis.
- Ekran açık: `FLAG_KEEP_SCREEN_ON` / `android:keepScreenOn`; CPU açık: `WAKE_LOCK` + `PowerManager`.
- Worker'da iş `doWork()` içinde yapılır ve `Result.success()` döner.

## Detaylı Açıklamalar

- Ana thread ve arka plan ihtiyacı
  - Android'de kullanıcıyla olan bütün etkileşim tek bir ana thread üzerinden yürür. Bu thread aynı zamanda view'ların ölçülmesi ve çizilmesi ile yaşam döngüsü olaylarından sorumludur. Bu thread'de uzun süren bir işlem başlatılırsa kullanıcı etkileşimi kesintiye uğrar, ekran donar ve sonunda sistem "Application Not Responding" diyaloğu gösterebilir. Bu yüzden belli bir süreden uzun sürecek işler Android'in sunduğu yapılarla ya da Java'nın thread mekanizmalarıyla ana thread dışına taşınmalıdır. Java'daki thread yönetimi standart bir yapı sunarken Android'in kendi yapıları mobil cihazın donanım ve enerji kısıtlarına göre tasarlanmıştır.
- Pil ve kaynak sorunu
  - İlk Android sürümlerinde uygulamalar arka planda istedikleri her işi yapabiliyordu. Bu durum pilin hızla tükenmesine yol açınca Google sürüm sürüm önlemler aldı. Doze modu ekran kapalı ve cihaz hareketsizken arka plan işlerini erteler; Doze-on-the-Go aynı mantığı cihaz taşınırken de uygular. Android 9 ile gelen App Standby Bucket'lar ise her uygulamanın ne sıklıkla kullanıldığını izler ve arka plan işlerine buna göre kota koyar. Sık kullanılan uygulamaların işleri neredeyse hiç kısıtlanmazken nadiren kullanılan uygulamaların işleri sistemin uygun olduğu anlara bırakılır. Bu, geliştiricinin gereksiz yere eklediği arka plan işlerinin de önüne geçer.
- Hangi yapı ne zaman?
  - Hoca karar sürecini slayttaki akışla özetledi:

    ```text
    Uzun süren HTTP indirmesi mi?
      Evet -> DownloadManager
      Hayır -> İş ertelenebilir mi?
        Hayır -> Foreground service
        Evet  -> Sistem koşullarıyla mı tetikleniyor?
          Evet  -> WorkManager
          Hayır -> Kesin bir zamanda mı çalışmalı?
            Evet  -> AlarmManager
            Hayır -> WorkManager
    ```

  - Kaynak: (ekrandan, 00:50:00).
  - Ertelenebilir bir iş, örneğin uygulama loglarının sunucuya gönderilmesi, gündüz yerine telefonun kullanılmadığı, Wi-Fi'ye bağlı ya da şarjda olduğu bir anda yapılabilir. Bu hem kullanıcıyı rahatsız etmez hem de pil tasarrufu sağlar.
- Servisler ve bind
  - Servis arayüzü olmayan, uzun süreli işler yapan bir bileşendir. Doğrudan başlatılabilir ya da bir bileşene bind edilebilir. Eskiden ağ işlemleri ve müzik çalma ağırlıklı olarak servislerle yapılırdı; artık kullanıcı etkileşimi varsa foreground servisler tercih ediliyor.
  - > **Ders sonrası not:** Hoca 00:47:06 civarında, servis bind edilmeden başlatılırsa uygulama kapanınca servisin de kendiliğinden kapandığını, bind edilirse önce unbind gerektiğini söyleyerek önceki ifadesini "düzeltti". Android belgelerine göre durum büyük olasılıkla tersidir: `startService()` ile başlatılan servis, onu başlatan bileşen yok olsa da `stopSelf()`/`stopService()` çağrılana kadar çalışmaya devam eder; yalnız bind ile kullanılan servis ise ona bağlı bütün istemciler unbind olduğunda sistem tarafından yok edilir. Hocanın ilk ifadesi (bind edilen servis uygulamayla birlikte kapanır) bu açıdan doğruya daha yakındır.
- Ekranı ve CPU'yu açık tutmak
  - Film izleme ya da uzun video oynatma gibi senaryolarda kullanıcı ekrana dokunmasa da ekranın kapanmaması gerekir. Bunun için aktivitenin penceresine `FLAG_KEEP_SCREEN_ON` bayrağı eklenir ya da layout'un kök elemanına `android:keepScreenOn="true"` yazılır (ekrandan, 01:10:00):

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

  - Slayttaki nota göre bayrak, ekranın açık kalması artık istenmiyorsa `getWindow().clearFlags(WindowManager.LayoutParams.FLAG_KEEP_SCREEN_ON)` ile kaldırılır; uygulama arka plana geçince ya da öne gelince pencere yöneticisi gerekli işlemleri kendisi yapar.
  - > **Ders sonrası not:** Hoca bayrak yöntemi için bir izin gerektiğini söyledi; büyük olasılıkla `FLAG_KEEP_SCREEN_ON` ve `keepScreenOn` özel bir izin gerektirmez. İzin (`WAKE_LOCK`) CPU'yu açık tutan wake lock yöntemi için gerekir.
- AlarmManager örneği
  - Slayttaki örnekte önce manifest'e exact alarm izni eklenir, sonra saat 8:30'da başlayan ve 20 dakikada bir tekrarlanan bir alarm kurulur (ekrandan, 01:15:00):

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

  - Aralık milisaniye cinsindendir: $1000 \cdot 60 \cdot 20 = 1\,200\,000$ ms, yani 20 dakika (python ile doğrulandı).
- WorkManager uygulaması
  - Derste bir dosya yüklemesi simüle edildi. `UploadWorker`, `Worker` sınıfından türer; `doWork()` önce "Uploading files to the server..." logunu yazar, sonra 1'den 500.000.000'a kadar sayan bir döngüde sayaç 50.000.000'ın katı olduğunda yüzdeyi 10 artırıp log yazar ve en sonda `Result.success()` döner (ekrandan, 01:35:00). Döngü toplam 10 kez log yazar: %10, %20, ..., %100 (python ile doğrulandı).
  - `MainActivity`'de butona basılınca `WorkManager.getInstance(...).enqueue(workRequest)` çağrılır; `getWorkInfoByIdLiveData(...)` ile işin durumu gözlenir ve her değişiklikte durum adı loga yazılır (ekrandan, 01:25:00). Tam kodlar genişletilmiş nottadır.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
