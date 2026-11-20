# Ders 13 Çalışma Özeti

## Genel Konular

- Bildirimlerin (notification) genel yapısı ve gösterim biçimleri
  - Bildirim, Android'in uygulamanın arayüzü dışında gösterdiği bir mesajdır. Kullanıcıya hatırlatma, başka kişilerden gelen iletişim ya da uygulamadan zamanında bilgi verir. Kullanıcı bildirime dokunarak uygulamayı açabilir ya da doğrudan bildirim üzerinden bir aksiyon alabilir (ekrandan, 00:15:00).
  - Status bar ikonu: yeni mesaj ya da yeni durum oluştuğunda durum çubuğunun solunda bir ikon belirir. Medya oynatıcı gibi foreground servisler de burada ikon gösterir.
  - Notification drawer: daha uzun metinler ve ayrıntılar çekmecede gösterilir.
  - Heads-up notification: acil mesajlar yukarıdan aşağı açılan küçük bir pencerede, ön plandaki uygulamanın önünde görünür. Üzerindeki butonlarla aksiyon alınabilir; yukarı kaydırılınca ya da bir süre sonra arka plana çekilir.
  - Kilit ekranı: görünürlük ayarına göre bildirimin tamamı (public), yalnız temel bilgisi (private) ya da hiçbir kısmı (secret) gösterilmez. Geliştirici yalnız varsayılan ayarı belirler; kullanıcı değiştirdikten sonra programla müdahale edilemez.
  - Uygulama ikonu rozeti (notification dot): Android 8 ile gelen, uygulama ikonunun köşesinde renkli bir nokta. Uzun basınca bildirimler görülebilir.
  - Wear OS: eşlenmiş saat varsa bildirimler, genişletilebilir bildirimler ve aksiyon butonları dahil, ek kod yazmadan saatte de görünür (ekrandan, 00:20:00).
- Bildirimin anatomisi
  - Küçük ikon (`setSmallIcon`), sistemin verdiği uygulama adı, zaman bilgisi (`setWhen`, `setShowWhen(false)` ile gizlenebilir), isteğe bağlı büyük ikon (`setLargeIcon`), başlık ve metin.
  - Android 12 ile kilitli ekrandayken bir bildirim aksiyonu için kimlik doğrulama istenebilir: `setAuthenticationRequired(true)`.
- Genişletilebilir bildirimler ve bildirim grupları
  - Varsayılan olarak bildirim metni tek satıra kırpılır. Uzun içerik (örneğin e-posta gövdesi) için ek şablon (`BigTextStyle` gibi) kullanılır.
  - Aynı uygulamadan gelen çok sayıda bildirim (örneğin 10 Gmail iletisi) tek bir grup altında toplanır, kullanıcı grubu açıp tek tek gezebilir (ekrandan, 00:25:00).
- Bildirim kanalları (channel) ve önem seviyeleri
  - Android 8 (API 26) ve üstünde her bildirim bir kanala aittir; kanal kimliği verilmezse hata oluşur.
  - Kullanıcı tarafındaki seviye ile kod tarafındaki sabit eşleşir: Urgent → `IMPORTANCE_HIGH` (ses + heads-up), High → `IMPORTANCE_DEFAULT` (ses), Medium → `IMPORTANCE_LOW` (ses yok), Low → `IMPORTANCE_MIN` (ses yok, status bar'da da görünmez), hiç gösterilmesin → `IMPORTANCE_NONE`.
  - Kanal `enableLights`, `setLightColor`, `setVibrationPattern` gibi metotlarla özelleştirilir. Ayar yalnız kanal ilk yaratılırken yapılabilir; sonra kontrol kullanıcıya geçer. Kullanıcının değişiklikleri `getNotificationChannel`, `getVibrationPattern`, `getSound` ile okunabilir.
- Rahatsız Etmeyin (Do Not Disturb) modu
  - Total silence: alarmlar dahil her ses ve titreşim kapanır.
  - Alarms only: yalnız alarmlar çalar.
  - Priority only: hatırlatıcı, etkinlik, arama, mesaj gibi öncelikli olaylar ses çıkarır; kişi bazında da ayarlanabilir.
- Önemli notlar
  - Foreground servis (örneğin medya oynatıcı) çalışırken bildirimi zorunludur ve kaydırarak kapatılamaz; servis durdurulmadan kalkmaz.
  - Gönderim sınırı: Android 8.1 (API 27) ile bir uygulama saniyede en fazla bir kez bildirim sesi çıkarabilir (ekrandan, 00:30:00).
- Sürümlere göre bildirim özellikleri
  - Android 5.0: kilit ekranı ve heads-up bildirimler, `setVisibility`, `setPriority`.
  - Android 7: şablonlarda resim ve avatar, bildirimden doğrudan cevap verme.
  - Android 8: kanallar, kanalların kullanıcıya bırakılması, arka plan rengi. <!-- BELİRSİZ: altyazıda "sunu uzatma özelliği" geçiyor; erteleme (snooze) ya da süre aşımı (timeout) olabilir. -->
  - Android 13: bildirimler için çalışma zamanı izni (runtime permission).
- Bildirim oluşturma ve PendingIntent
  - `NotificationCompat.Builder(this, CHANNEL_ID)` ile `setSmallIcon`, `setContentTitle`, `setContentText`, `setPriority` çağrılır; farklı görünüm için `setStyle` kullanılır (ekrandan, 00:35:00).
  - PendingIntent, hemen değil ileride, bir kullanıcı aksiyonu ya da sistem olayıyla yapılacak işi taşıyan intent'tir. `setContentIntent` ile bildirime bağlanır; Alarm Manager'da da kullanılır.
  - `addAction` ile bildirime buton eklenir; buton bir PendingIntent ile örneğin bir BroadcastReceiver'ı tetikler (snooze örneği). `RemoteInput` ile doğrudan cevap aksiyonu kurulur (ekrandan, 01:00:00).
  - İlerleme çubuklu bildirim: indirme sürerken bildirimdeki progress bar 0-100 arasında güncellenir.
  - `setFullScreenIntent`: gelen arama gibi acil bildirimlerin tüm ekranı kaplamasını sağlar.
- Görevler ve back stack
  - A aktivitesi B'yi başlatınca A durur ama durumu korunur. Back tuşu B'yi yığından çıkarıp yok eder ve A kaldığı yerden devam eder. Home tuşu ise görevi arka plana alır, aktivite yok edilmez (ekrandan, 01:05:00).
  - Bir aktivitenin birden çok örneği olabilir. Bildirim bir giriş noktasıdır; `TaskStackBuilder` ile uygun bir back stack kurularak aktivite başlatılır.
- Uygulama çubukları ve Swipe-to-Refresh
  - App bar → ActionBar → Toolbar. Toolbar bir ViewGroup'tur, aktivitenin istenen yerine konabilir.
  - `SwipeRefreshLayout`, ListView/GridView/RecyclerView'un ebeveyni olarak XML'de tanımlanır; dikey çekme hareketini algılar ve `setOnRefreshListener` içindeki `onRefresh` ile yenileme yapılır (ekrandan, 01:10:00). Action bar'daki yenileme butonu `onOptionsItemSelected` içinde karşılanır.
- Pasif etkileşim: Toast ve Snackbar
  - Toast: kullanıcının aksiyon alamadığı bilgilendirme mesajı. Süre ve `setGravity` ile konum ayarlanır; varsayılan konum alttır. Layout inflater ile özel Toast görünümü yapılabilir.
  - Snackbar: ekranın altında görünen, kendiliğinden kaybolan, bir aksiyon (örneğin UNDO) içerebilen mesaj. Aktivite görünür ve etkileşimli kalır (ekrandan, 01:15:00). `Snackbar.make` ile oluşturulur, `setAction` ve bir dinleyici sınıfla aksiyon eklenir.
- Diyaloglar
  - Ekranı tamamen kaplamayan, kullanıcıdan karar ya da ek bilgi isteyen küçük pencere (ekrandan, 01:20:00).
  - `AlertDialog` başlık, en çok üç buton (positive, negative, neutral), seçilebilir liste ya da özel layout gösterebilir. `DatePickerDialog` ve `TimePickerDialog` tarih/saat seçtirir; bugün bu seçiciler çoğunlukla aktivitenin içine gömülür.
  - `ProgressDialog` kullanıcıyı uygulamayla etkileşimden alıkoyduğu için kullanımdan kalkmıştır; yerine layout içinde `ProgressBar` önerilir.
  - `AlertDialog.Builder` ile mesaj ve başlık verilir, `create()` ile diyalog oluşturulur. `setItems` ile liste, çoklu seçim listesi ve özel giriş (sign-in) layout'u eklenebilir (ekrandan, 01:25:00).
- Uygulama: NotificationExample ve DownloadActivity
  - Beş butonlu örnek: basit bildirim, BigTextStyle, BigPictureStyle, InboxStyle ve iki aksiyon butonlu (Dismiss, Delete) bildirim.
  - DownloadManager örneği: `DownloadManager.Request` ile URL, başlık, açıklama ve hedef klasör verilir; `enqueue` kuyruğa ekler ve indirme kimliğini döndürür. Silme yalnız bu kimlikle yapılabilir.

## Hocanın Özellikle Vurguladığı Kısımlar

- Bildirimler dönem projesinde yer almalı
  - Hoca bildirim konusunun proje içinde kullanılmasının önemli olduğunu söyledi; Snackbar'ı da proje içinde aksiyonlara eşlik etmesi için önerdi.
- Kanal kimliği zorunludur
  - Android 8 ve üstünde kanal kimliği verilmezse hata oluşur. Kanal ayarları yalnız ilk yaratılışta belirlenir, sonrası kullanıcının kontrolündedir.
- PendingIntent bildirimlere özgü değildir
  - Alarm Manager'da ve ileride bir aksiyona bağlı her türlü işte kullanılır.
- Kullanıcı deneyimi
  - İşletim sistemleri her sürümde en çok bildirimler gibi insan-bilgisayar etkileşimi noktalarında değişiklik yapıyor; rozet, gruplama, kanallar bu amaçla geldi.
- Back ve Home tuşu farkı
  - Back aktiviteyi yığından çıkarıp yok eder; Home yalnız arka plana alır.
- Diyalogları yerinde kullanmak
  - Diyaloglar daha çok "emin misiniz?" türü onaylar içindir; seçimler artık mümkün olduğunca aktivitenin içine konuyor.

## Kısa Tekrar Notları

- Bildirim gösterim yerleri: status bar ikonu, drawer, heads-up, kilit ekranı, rozet, Wear OS.
- Kilit ekranı görünürlüğü: public (tamamı), private (temel bilgi), secret (hiçbir şey).
- Önem eşlemesi: Urgent=HIGH, High=DEFAULT, Medium=LOW, Low=MIN, gösterme=NONE.
- DND seviyeleri: Total silence, Alarms only, Priority only.
- Android 8.1+: saniyede en fazla bir bildirim sesi.
- `NotificationCompat.Builder(context, CHANNEL_ID)` + `setSmallIcon` + `setContentTitle` + `setContentText` + `setPriority` + `notify`.
- PendingIntent = ileride, kullanıcı aksiyonuyla çalışacak intent; `setContentIntent`, `addAction`.
- Stiller: `BigTextStyle`, `BigPictureStyle`, `InboxStyle`.
- Back stack: Back yığından çıkarır ve yok eder, Home arka plana alır.
- Toolbar bir ViewGroup'tur; `SwipeRefreshLayout` liste görünümünün ebeveynidir.
- Toast pasif, Snackbar aksiyonlu (UNDO); AlertDialog en çok üç buton.
- ProgressDialog kullanımdan kalktı, yerine ProgressBar.
- DownloadManager: `Request` → `enqueue` → indirme kimliği → `remove(id)`.

## Detaylı Açıklamalar

- **Bildirimin rolü.** Eskiden uygulamalar kullanıcıyı SMS ile bilgilendirirken bugün push bildirimleri yaygınlaştı. Bildirim, diğer kullanıcılardan, telefondan ya da başka uygulamalardan gelen değişiklikleri kullanıcıya ileten temel birimdir. Eskiden bildirim tek yönlü bir bilgilendirmeydi; bugün bildirim üzerinden cevap yazmak, ertelemek, silmek gibi aksiyonlar da alınabiliyor.

- **Gösterim biçimleri.** Status bar'daki ikon yeni bir mesaj ya da durumu haber verir. Daha fazla ayrıntı drawer'da gösterilir. Kullanıcı başka bir iş yaparken kaçırmaması gereken mesajlar heads-up olarak kurgulanır: üstten açılan pencerede içerik ve aksiyon butonları görünür, kullanıcı yukarı kaydırarak ya da bekleyerek işine dönebilir. Gelen arama gibi daha da acil durumlarda `setFullScreenIntent` ile bildirim tüm ekrana taşınabilir.

- **Kilit ekranı ve görünürlük.** Kilit ekranında bildirimin ne kadarının görüneceği public/private/secret seçenekleriyle belirlenir. Hoca önce karıştırdığını söyleyip düzeltti: secret'ta mesajın hiçbir kısmı görünmez, private'ta yalnız temel bilgi görünür, public'te içerik tamamen görünür. Geliştirici bunu varsayılan olarak ayarlar; kullanıcı değiştirirse kontrol kullanıcıya geçer.

- **Anatomi.** Bildirimin küçük ikonu `setSmallIcon` ile verilir. Uygulama adı sistemden gelir. Zaman bilgisi `setWhen` ile ayarlanır, `setShowWhen(false)` ile gizlenir. `setLargeIcon`, başlık ve metin isteğe bağlı alanlardır. Android 12 ile kilitli ekrandaki bir bildirim aksiyonu için `setAuthenticationRequired(true)` verilirse cihaz kilidinin açılması istenir.

- **Kanallar ve önem.** Android 8'den itibaren her bildirim bir kanala atanır ve kanal kimliği zorunludur. Kanal `createNotificationChannel` metodunda, `Build.VERSION.SDK_INT >= Build.VERSION_CODES.O` koşuluyla, ad, açıklama ve `NotificationManager.IMPORTANCE_DEFAULT` gibi bir önem seviyesiyle yaratılır ve `NotificationManager.createNotificationChannel` ile sisteme kaydedilir (ekrandan, 00:40:00). Önem seviyesi bildirimin ses çıkarıp çıkarmayacağını, heads-up olup olmayacağını ve status bar'da görünüp görünmeyeceğini belirler. Böylece bir uygulamanın kritik mesajları ses çıkarırken pazarlama gibi kritik olmayan mesajları yalnız drawer'da kalabilir.

- **Foreground servis ve gönderim sınırı.** Foreground servis bildirimi kullanıcı arka planda çalışan bir servis olduğunu unutmasın diye kaydırılarak kapatılamaz; servis durdurulmalıdır. Sık bildirim gelmesine karşı slaytta Android 8.1 (API 27) ile bir uygulamanın saniyede birden fazla bildirim sesi çıkaramadığı yazıyor (ekrandan, 00:30:00).
  - Ders sonrası not: Hoca derste önce bu sınırı "bir dakika" olarak hatırladığını söyledi, sonra slayttaki "bir saniye" ifadesini kontrol etmek istedi; özelliği Android 8 ile gelmiş gibi anlattı. Slayta göre doğrusu Android 8.1 (API 27) ve saniyede en fazla bir sestir. Slayt ayrıca tek bir bildirimin çok sık güncellenmesi durumunda sistemin bazı güncellemeleri düşürebileceğini belirtir.

- **PendingIntent.** Yapılacak iş hemen değil, kullanıcı bildirime ya da bir butona dokunduğunda yapılacaksa iş bir PendingIntent'e atanır. PendingIntent arka planda bekler, aksiyon gelince ilgili görevi çalıştırır. Slayt örneğinde `AlertDetails` aktivitesini açan açık (explicit) bir intent, `FLAG_ACTIVITY_NEW_TASK | FLAG_ACTIVITY_CLEAR_TASK` bayraklarıyla kurulur, `PendingIntent.getActivity(this, 0, intent, 0)` ile sarılır ve `setContentIntent(pendingIntent)` ile bildirime bağlanır; `setAutoCancel(true)` dokunulunca bildirimin kalkmasını sağlar (ekrandan, 00:35:00).

- **Aksiyonlar, doğrudan cevap ve ilerleme.** `addAction(ikon, metin, pendingIntent)` ile bildirime buton eklenir; snooze örneğinde buton bir BroadcastReceiver'a yönlendirilir. Doğrudan cevap için `RemoteInput.Builder(KEY_TEXT_REPLY).setLabel(...)` ile giriş alanı kurulur, `PendingIntent.getBroadcast(...)` ile cevap aksiyonunun PendingIntent'i hazırlanır ve `NotificationCompat.Action.Builder(...).addRemoteInput(remoteInput)` ile aksiyona eklenir (ekrandan, 01:00:00). Dosya indirme gibi uzun işlerde kullanıcı başka aktiviteye geçse bile drawer'daki ilerleme çubuğundan durumu takip edebilir.

- **Back stack.** Aktiviteler yığında tutulur. B, A'nın üstüne gelince A durdurulur ama kaydırma konumu ve formlara girilen metin gibi durumu korunur. Back tuşu B'yi yığından çıkarır ve yok eder; yok edilen aktivitenin durumu tutulmaz. Home tuşu görevin tamamını arka plana alır, kullanıcı geri döndüğünde yığının tepesindeki aktivite kaldığı yerden devam eder (ekrandan, 01:05:00). Bir aktivite başka görevlerden de çağrılarak birden fazla örnek olarak yaratılabilir. Bildirim de uygulamaya bir giriş noktasıdır ve `TaskStackBuilder` ile aktivite uygun bir yığınla açılabilir.

- **Toolbar ve Swipe-to-Refresh.** Eski app bar ve ActionBar'ın yerini bugün Toolbar almıştır; Toolbar bir ViewGroup olduğundan aktivitenin herhangi bir yerine konabilir ve ekranlar arası gezinmeyi kolaylaştıran ikonlar taşır. `SwipeRefreshLayout` XML'de liste görünümünü sarar; kullanıcı listeyi aşağı çekince sunucuya istek gönderilir ve yeni öğeler listeye eklenir (ekrandan, 01:10:00).

- **Toast, Snackbar, Dialog.** Toast pasif bir mesajdır; `show()` ile gösterilir, layout inflater ile görsel ve metin içeren özel bir görünüm verilebilir. Snackbar ekranın altında belirir, kendiliğinden kaybolur ve bir e-postayı silince çıkan "1 item removed / UNDO" gibi bir aksiyon taşıyabilir. Diyalog ise kullanıcının devam etmeden önce karar vermesini isteyen küçük penceredir ("USB depolamayı silmek istiyor musunuz?" gibi). AlertDialog'a positive, negative ve "Remind me later" gibi neutral butonlar, `setItems` ile liste ve çoklu seçim eklenebilir. ProgressDialog kullanıcıyı engellediği için kullanımdan kalkmıştır (ekrandan, 01:20:00).

- **Derste gösterilen uygulama.** `NotificationExample` aktivitesi `View.OnClickListener`'ı arayüz olarak uygular (önceki örneklerde anonim sınıf kullanılıyordu). Her buton ayrı bir metot çağırır: önce `cancelAll()` ile eski bildirimler temizlenir, bitmap `BitmapFactory.decodeResource` ile okunur, uygun stil (`BigTextStyle`, `BigPictureStyle`, `InboxStyle`) kurulur, `setStyle` ile builder'a verilir ve `notify(notificationId, notification)` ile gösterilir (ekrandan, 01:45:00). Aksiyonlu örnekte `Receiver` sınıfına giden bir intent, `"ACTION_CANCEL"` aksiyonu ve `putExtra("id", notificationId)` ile kurulur, `PendingIntent.getBroadcast` ile sarılır ve "Dismiss" ile "Delete" aksiyonlarına verilir (ekrandan, 01:50:00). `DownloadActivity`'de `getSystemService(DOWNLOAD_SERVICE)` ile alınan DownloadManager'a, başlığı, açıklaması ve hedef klasörü ayarlanmış bir `Request` `enqueue` edilir; dönen `downloadId` ile dosya açılır ya da silinir (ekrandan, 02:00:00).

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
