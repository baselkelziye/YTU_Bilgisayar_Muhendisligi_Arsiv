# Ders 10 Çalışma Özeti

## Genel Konular

- Dönemde işlenen konuların hatırlatması
  - Mobil terminoloji, mobil cihazlar, mobil işletim sistemleri ve masaüstü işletim sistemlerinden farkları, mobil uygulama geliştirme teknikleri ve dilleri, geliştirme araçları ve ortamları, Android mimarisi, uygulama ve aktivite yaşam döngüsü, intent'ler ve layout'lar, aktiviteler arası haberleşme, kullanıcı arayüzü bileşenleri, veri saklama yolları, sensörlerden veri toplama.
  - Bu dersin konusu Broadcast Receiver'lardır. Hocaya göre Broadcast Receiver'lar aslında arka plan işlerinin (background tasks) bir parçasıdır.
- Broadcast Receiver nedir?
  - Sistem düzeyinde ya da uygulama düzeyinde olan değişikliklerden diğer uygulamaların haberdar olmasını sağlayan temel yapı taşıdır. Hoca bunu PC ortamındaki kesmelere (interrupt) benzetir. <!-- BELİRSİZ: altyazıda "inter-app" ve "inter-up" geçiyor; bağlamdan "interrupt" olduğu düşünüldü. -->
  - Aktiviteler gibi uygulamaya bir giriş noktasıdır (entry point): bir sistem ya da uygulama değişikliğinden sonra uygulamada bir kodun çalışmasını sağlar.
  - Tasarım kalıbı publish-subscribe'dır: değişiklikler bir merkeze bildirilir, bu değişikliği izlemek isteyen (abone olan) uygulamalar haberdar edilir.
  - Ekrandaki şemada şarj cihazının takılması, Android sistemi ve gelen mesaj birer kaynak olarak Broadcast Receiver'a bağlanır (ekrandan, 00:30:00).
- Broadcast türleri
  - Sistem broadcast'leri: sistemsel değişiklikleri bildirir. Sayıları 200'ün üzerindedir. Örnekler: pil durumunun değişmesi ya da belli seviyenin altına düşmesi, cihazın yeniden başlaması, güç kaynağına takılma, uçak moduna geçme, ekranın açılıp kapanması, SMS ya da arama gelmesi.
  - Özel (custom) broadcast'ler: uygulamaya özel değişikliklerin diğer uygulamalara ya da uygulamanın kendi içine bildirildiği intent'lerdir.
  - Derste ilgilenilen üç kaynak: sistemden gelen, diğer uygulamalardan gelen ve `LocalBroadcastManager` ile uygulama içinden gelen broadcast'ler.
  - Kullanım örnekleri: telefon şarja takıldığında ya da şarj belli seviyenin üstündeyken güncelleme yapmak, kota dolmasın diye yalnız Wi-Fi'ye bağlanınca iş yapmak, telefonun az kullanıldığı gece saatlerinde iş yapmak.
- İki tür receiver (ekrandan, 00:30:00)
  - Manifest'te tanımlanan (manifest-declared, statik) receiver'lar: uygulama kapalıyken bile değişikliği izler. Uygulama yüklendiği andan itibaren, hiç açılmasa da izleme başlar; olay olduğunda sistem uygulamayı başlatır.
  - Context'e kaydedilen (context-registered, dinamik) receiver'lar: yalnız kaydedildiği context (aktivite ya da uygulama) yok edilmediği sürece izler.
- Manifest'te tanımlama (ekrandan, 00:35:00)
  - `<receiver>` etiketi içinde `<intent-filter>` ve izlenecek `<action>`'lar yazılır. Örnekte `BOOT_COMPLETED` ve `INPUT_METHOD_CHANGED` izlenir. Bir receiver birden fazla aksiyonu izleyebilir; hepsi için aynı işi ya da aksiyona göre farklı işler yapabilir.
  - API 26 ve üstünü hedefleyen uygulamalar, uygulamayı özel olarak hedeflemeyen (implicit) broadcast'lerin çoğu için manifest'te receiver tanımlayamaz.
  - Kendi receiver sınıfı `BroadcastReceiver`'dan türetilir ve `onReceive(Context, Intent)` metodu yazılır. Örnekte aksiyon ve URI bilgisi bir `StringBuilder` ile birleştirilip `Log.d` ile loglanır ve `Toast` ile gösterilir.
- Context'e kaydetme (ekrandan, 00:40:00)
  - Bir receiver nesnesi ve bir `IntentFilter` oluşturulur, `addAction` ile aksiyon eklenir, `registerReceiver(br, filter)` çağrılır. İş bitince `unregisterReceiver` ile kayıt silinir.
  - Kayıt ve silme karşılıklı yaşam döngüsü metotlarında yapılır: `onCreate` - `onDestroy`, `onStart` - `onStop`, `onResume` - `onPause`.
  - Activity context'inde kaydedilen receiver aktivite yok edilince izlemeyi bırakır; Application context'inde kaydedilen receiver uygulama çalıştığı sürece izler.
- `onReceive` ve ana thread
  - `onReceive` ana (UI) thread'de çalışır. İçindeki iş milisaniyeler, en çok bir saniyeye yakın sürede bitmelidir; yoksa ana thread bloklanır.
  - Uzun iş (dosya yükleme, bitmap işleme) için bir asenkron yapı (derste AsyncTask örneği) ya da servis kullanılır. Bağlantı arka plan işleri konusunda kurulacak.
- Broadcast gönderme (ekrandan, 00:45:00)
  - `sendOrderedBroadcast`: broadcast'i sırayla, her seferinde bir receiver'a gönderir. Receiver sonucu bir sonrakine aktarabilir ya da broadcast'i tamamen kesebilir. Sıra intent-filter'daki `android:priority` ile belirlenir.
  - `sendBroadcast`: bütün receiver'lara belirsiz sırada gönderir (normal broadcast). Daha verimlidir, ama receiver'lar birbirinin sonucunu okuyamaz, broadcast'i kesemez.
  - `LocalBroadcastManager.sendBroadcast`: yalnız aynı uygulamadaki receiver'lara gönderir. Süreçler arası iletişim gerekmediği için çok daha verimlidir ve güvenlik kaygısı yoktur.
  - Intent hazırlanır, `setAction` ile aksiyon, gerekirse `putExtra` ile veri eklenir, `sendBroadcast` ile gönderilir. Bu intent `startActivity` ile gönderilen intent'ten farklıdır.
- Receiver'dan servis başlatma
  - Örnekte `onReceive` içinde bir intent ile servis başlatılır; manifest'te cihazın yeniden başlamasını (`BOOT_COMPLETED`) izleyen receiver vardır. Bu aksiyon için `uses-permission` ile izin alınmıştır. İzin yoksa izleme olmaz ya da hata alınır.
- Gelen aramaları izleyen receiver (ekrandan, 00:50:00)
  - `MyPhoneReceiver`, `onReceive` içinde `intent.getExtras()` ile `TelephonyManager.EXTRA_STATE` değerini alır; durum `EXTRA_STATE_RINGING` ise `EXTRA_INCOMING_NUMBER` ile arayan numarayı loglar. Manifest'te `READ_PHONE_STATE` izni ve `android.intent.action.PHONE_STATE` aksiyonu vardır.
- İzinlerle broadcast'i kısıtlama (ekrandan, 01:05:00)
  - Gönderen taraf `sendBroadcast(intent, Manifest.permission.SEND_SMS)` ile alıcıda hangi iznin olması gerektiğini belirtir; alıcı bu izni almış olmalıdır.
  - Alan taraf `<receiver android:permission="...">` ya da `registerReceiver(receiver, filter, izin, null)` ile yalnız bu izne sahip gönderenlerden broadcast kabul eder.
- Alarm ve PendingIntent örneği
  - `AlarmManager` ile ileride olacak bir iş kurulur. Ne zaman olacağı bilinmeyen iş için intent `PendingIntent` olarak oluşturulur. Receiver'da "Don't panic, but your time is up" `Toast` mesajı gösterilir ve telefon titreştirilir (vibrator, 2 saniye). <!-- BELİRSİZ: slayt karesi yok; hoca tetikleyiciyi "butona 10 defa basılınca" diye anlatıyor, slayttaki örneğin ayrıntısı doğrulanamadı. -->
- Sticky broadcast intent'ler (ekrandan, 01:10:00)
  - Artık önerilmez; Android 5'e kadar aynı intent'in tekrar tekrar izlenmesini sağlıyordu, güvenlik açığına yol açtığı için kullanımı kaldırıldı.
  - Ekrandaki örnek: `ACTION_BATTERY_CHANGED` için `registerReceiver(null, filter)` çağrılır, dönen intent'ten `EXTRA_STATUS` ve `EXTRA_PLUGGED` okunarak şarj olup olmadığı ve USB/AC ile şarj edildiği bulunur.
- Sürümlere göre değişiklikler
  - Android 7: `ACTION_NEW_PICTURE` ve `ACTION_NEW_VIDEO` sistem broadcast'leri artık gönderilmez.
  - Android 8: manifest'te tanımlanan receiver'lara yeni kısıtlar; bazı sistem broadcast'leri yalnız context'e kayıtla izlenebilir.
  - `NETWORK_STATE_CHANGED_ACTION` artık kullanıcının konumunu belirleyebilecek bilgi taşımaz; bunun için izne tabi `getConnectionInfo` kullanılır.
  - Uygulama, hedef kitlesindeki API seviyelerine göre kodda önlem almalıdır.
- Öneriler
  - Uygulama içinde kalan mesajlar için mutlaka `LocalBroadcastManager` kullanılır.
  - Uzun süren arka plan işleri `JobScheduler`'a bırakılır; receiver yalnız değişikliği fark edip işi devreye sokar.
- Kod örnekleri (Android Studio, gerçek cihaz)
  - Uçak modu: `AirplaneModeChangeReceiver`, `Settings.Global` içindeki uçak modu değerine bakıp "Airplane Mode is on/off" `Toast`'u gösterir. Aktivite receiver'ı `onStart`'ta `IntentFilter` ile kaydeder, `onStop`'ta siler.
  - Statik/dinamik: `BRStaticDynamicReceiver` gelen aksiyona göre `ACTION1` ya da `ACTION2` mesajı gösterir (ekrandan, 01:20:00). `ACTION1` manifest'te (global) tanımlıdır ve `setPackage` + `sendBroadcast` ile gönderilir; `ACTION2` `LocalBroadcastManager` ile `onResume`'da kaydedilir, `onPause`'da silinir ve `LocalBroadcastManager...sendBroadcast` ile gönderilir (ekrandan, 01:25:00 ve 01:30:00).
  - Güç durumu: `PowerStatusActivity` ve aynı dosyadaki `MyReceiver`, `POWER_CONNECTED`, `POWER_DISCONNECTED`, `BATTERY_LOW`, `BATTERY_OKAY` aksiyonlarını izler; pil yüzdesini `level * 100 / (float) scale` ile hesaplar (ekrandan, 01:35:00).
- Uygulama alıştırması
  - Önceki haftanın ışık ve doğrusal ivme sensörü uygulamasına ekleme: telefon şarja takılınca sensör dinleme kaydı silinir, şarjdan çekilince yeniden kaydedilir.

## Hocanın Özellikle Vurguladığı Kısımlar

- Register edilen receiver mutlaka unregister edilmeli
  - Yoksa kaynaklar serbest kalmaz, manifest tanımından farkı kalmaz ve daha çok kaynak tüketilir.
- `onReceive` uzun iş yapmamalı
  - Ana thread bloklanmasın diye iş milisaniyeler içinde bitmeli; uzun işler asenkron yapıya ya da servise devredilmeli.
- Manifest kayıtlarındaki kısıtlar
  - Herkes her şeyi manifest'ten izleyebilseydi telefonun kaynakları hızla tükenirdi; Android bu yüzden sürümler içinde kısıt getirdi. Hangi broadcast'lerin manifest'te izlenebildiği listesini ezberlemek gerekmez, ama haberdar olmak gerekir.
- Uygulama içi iletişimde `LocalBroadcastManager`
  - İşletim sistemi düzeyine çıkmadan çalıştığı için çok daha verimli ve güvenlidir.
- Global ile lokal karıştırılmamalı
  - Manifest'te (global) tanımlı bir aksiyon `LocalBroadcastManager` ile gönderilirse sistem bunu görmez ve `onReceive` çalışmaz. Hoca burayı kritik nokta olarak işaretledi.
- İzinler
  - Sistem düzeyindeki birçok olay (cihazın açılması, telefon durumu) izin olmadan izlenemez; aksi hâlde uygulamalar kullanıcının haberi olmadan her şeyi izleyebilirdi.
- `sendOrderedBroadcast` sık kullanılmaz, ama gerektiğinde "hayat kurtarır".

## Kısa Tekrar Notları

- Broadcast Receiver: publish-subscribe; sistem ya da uygulama değişikliğinde kod çalıştıran giriş noktası.
- İki broadcast türü: sistem ve özel (custom). Üç kaynak: sistem, diğer uygulamalar, uygulama içi (`LocalBroadcastManager`).
- Statik (manifest): uygulama kapalıyken de izler; API 26+ ile implicit broadcast'lerin çoğu için kullanılamaz.
- Dinamik (context): `IntentFilter` + `registerReceiver`; `unregisterReceiver` şart. Eşler: `onCreate`/`onDestroy`, `onStart`/`onStop`, `onResume`/`onPause`.
- Activity context: aktivite yaşadıkça; Application context: uygulama çalıştıkça.
- Gönderme: `sendOrderedBroadcast` (sıralı, `android:priority`, kesilebilir), `sendBroadcast` (sırasız), `LocalBroadcastManager.sendBroadcast` (uygulama içi, en verimli).
- İzinli gönderme: `sendBroadcast(intent, izin)`; izinli alma: `android:permission` ya da `registerReceiver(..., izin, null)`.
- Sticky broadcast artık önerilmez; `ACTION_BATTERY_CHANGED` için `registerReceiver(null, filter)` pil durumunu döndürür.
- Android 7: yeni foto/video broadcast'i yok; Android 8: manifest kısıtları.
- Pil yüzdesi: `level * 100 / (float) scale`.
- Uzun iş: asenkron yapı, servis ya da `JobScheduler`.

## Detaylı Açıklamalar

- Broadcast Receiver'ın rolü
  - Bir uygulama ancak kendisini ilgilendiren bir olay olduğunda çalışmak isteyebilir: telefon şarja takıldığında güncelleme indirmek, Wi-Fi'ye geçince büyük dosya göndermek, gece saatinde yedek almak gibi. Bunun için uygulama, olayın aksiyon adını içeren bir intent filter ile kendini bir receiver olarak tanıtır. Olay olduğunda sistem bir broadcast intent yayımlar ve abone olan receiver'ların `onReceive` metodu çağrılır.
- Statik ve dinamik kaydın farkı
  - Manifest kaydı uygulama yüklendiği anda etkindir ve uygulama çalışmıyorken bile sistemin uygulamayı başlatmasına yol açar. Bu güçlü ama pahalıdır; bu yüzden Android 8 (API 26) ile, uygulamayı doğrudan hedeflemeyen broadcast'lerin çoğu için manifest kaydı kapatıldı. Dinamik kayıt ise yalnız ihtiyaç olduğu sürece yapılır ve karşılık gelen yaşam döngüsü metodunda silinir; böylece izleme kullanıcı uygulamayı kullanırken sınırlı kalır.
- Gelen arama örneği ve hocanın anlattığı uygulama
  - Telefon durumu broadcast'i ile çalan telefonun durumu ve arayan numara alınabilir. Hoca, operatörlerin kapalı telefonu arayan numaraları yalnız numara olarak SMS'le bildirdiği dönemde, gelen SMS'i yakalayıp numarayı rehberde arayan ve SMS'e kişinin adını yazan küçük bir uygulama geliştirdiklerini anlattı. Arama istatistiği tutmak ya da bir numarayı sessize almak gibi işler de bu yolla yapılır; ama bunların hepsi ilgili izinlere bağlıdır.
- Statik/dinamik kod örneğinin dersi
  - `ACTION1` manifest'te global tanımlıdır; bu yüzden düz `sendBroadcast` ile gönderilir. API 26'dan sonra intent'e `setPackage` ile paket adı verilerek açık (explicit) hâle getirilir; başka uygulamaların izlemesi istenirse paket set edilmez. Aynı aksiyon `LocalBroadcastManager` ile gönderilseydi mesaj sistem düzeyine çıkmayacak, manifest'teki receiver onu göremeyecek ve `onReceive` çalışmayacaktı. `ACTION2` ise `LocalBroadcastManager` ile kaydedildiği için yine onunla gönderilir.
- Güç durumu örneği
  - Aktivite pil durumu değişikliklerini izleyen bir intent filter kurar ve `registerReceiver`'ın döndürdüğü değerle şarj durumunu ve yüzdesini ekrandaki `TextView`'da gösterir ("Status is Charging", cihazda %90). Receiver her aksiyon için uygun mesajı ve yüzdeyi yazar.
  - Ders sonrası not: Hoca `BATTERY_LOW` eşiğini "genellikle %20", `BATTERY_OKAY` eşiğini %80 diye söyledi. Ekrandaki kod yorumunda ise düşük seviye 15, "okay" 30 olarak yazılıdır (ekrandan, 01:35:00). Eşik cihaz yapılandırmasına bağlıdır; büyük olasılıkla Android'in varsayılan düşük pil eşiği %15 civarındadır.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
