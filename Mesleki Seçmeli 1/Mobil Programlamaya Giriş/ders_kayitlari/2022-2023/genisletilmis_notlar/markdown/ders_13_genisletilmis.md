# Ders 13 Genişletilmiş Notu: Bildirimler (Notifications), Pop-up Mesajlar ve Diyaloglar

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Kullanıcıyla Etkileşim ve Bildirimlerin Yeri
- 2. Bildirimlerin Gösterim Biçimleri
- 3. Bildirimin Anatomisi
- 4. Genişletilebilir Bildirimler ve Gruplama
- 5. Bildirim Kanalları, Öncelik ve Rahatsız Etmeyin Modu
- 6. Önemli Notlar ve Sürümlere Göre Değişiklikler
- 7. Bildirim Oluşturmak ve PendingIntent
- 8. Bildirime Aksiyon, Doğrudan Cevap ve İlerleme Çubuğu Eklemek
- 9. Görevler, Back Stack ve Bildirimden Aktivite Başlatmak
- 10. Uygulama Çubukları ve Swipe-to-Refresh
- 11. Pasif Etkileşim: Toast ve Snackbar
- 12. Diyaloglar
- 13. Uygulama: NotificationExample
- 14. Uygulama: DownloadManager ile Dosya İndirmek

## 1. Kullanıcıyla Etkileşim ve Bildirimlerin Yeri

Bir önceki derste arka plan görevleri (background tasks) işlenmişti. Bu derste kullanıcıyı uygulamadaki ya da telefondaki gelişmelerden haberdar etmenin yolları ele alınıyor. Bunların başında bildirimler (notification) geliyor; ardından pop-up mesajlar, Toast mesajları, Snackbar, uygulama çubukları ve diyaloglar gibi alternatifler konuşuluyor.

Hoca bildirimlerin bugün çok önemli olduğunu, çünkü bildirim sayısının çok arttığını söylüyor. Eskiden kullanıcıyı bilgilendirmek için SMS kullanılırdı; bugün SMS'in yanına bildirimler, özellikle push notification servisleri eklenmiş durumda. Bildirim, uygulamanın kendi mesajlarını kullanıcıya iletmesinin en önemli yoludur: başka kullanıcılardan gelen mesajlar, telefondan gelen olaylar ya da başka uygulamalardaki değişiklikler bildirimle iletilir.

> **Hocanın vurgusu:** Bildirim konusunun dönem projesinin içinde yer alması önemli. Kullanıcıyla etkileşim kurmayı sağlayan bu yöntemlerden mümkün olanlar projeye dahil edilmeli.

Slaytta bildirimin tanımı şöyle verilir (ekrandan, 00:15:00):

- Bildirim, Android'in uygulamanın kullanıcı arayüzünün dışında gösterdiği bir mesajdır. Kullanıcıya hatırlatma, başka kişilerden gelen iletişim ya da uygulamadan gelen başka zamanında bilgiler verir.
- Kullanıcı bildirime dokunarak uygulamayı açabilir ya da bildirim üzerinden doğrudan bir aksiyon alabilir.

## 2. Bildirimlerin Gösterim Biçimleri

### 2.1 Status bar, drawer ve heads-up

Hoca üç temel gösterim biçimi anlatıyor (ekrandan, 00:15:00):

- **Status bar ikonu:** Bir mesaj geldiğinde (SMS, e-posta) durum çubuğunun sol tarafında küçük bir ikon belirir. Yeni bir duruma geçildiğinde de ikon görünebilir. İleride görülecek foreground servisler de, örneğin müzik çalan bir medya uygulaması, burada ikon gösterir.
- **Notification drawer (bildirim çekmecesi):** İkon yetmiyorsa ve mesajın daha fazla ayrıntısı paylaşılmak isteniyorsa daha uzun metinler drawer'da gösterilir. Status bar'da yer almayan ve heads-up olmayan mesajlar da genelde drawer'a yerleşir.
- **Heads-up notification:** Dikkat çekmesi gereken, kullanıcı başka bir iş yaparken drawer'da kalıp geç fark edilebilecek mesajlar için kullanılır. Mesaj geldiğinde yukarıdan aşağıya bir pencere açılır ve ön plandaki uygulamanın önünde içerik görünür. Mesajın üzerinde butonlar varsa (slayttaki örnekte REPLY ve ARCHIVE) aksiyon buradan alınabilir. Aksiyon alınmayacaksa pencere yukarı kaydırılır ya da bir süre beklenir, mesaj kendini arka plana alır. Acil ve öncelikli mesajlar heads-up olarak kurgulanır.

### 2.2 Kilit ekranı ve görünürlük

Belirli bir sürümden itibaren işletim sistemleri, ekran kilitliyken normalde görünmeyen bildirimler için özel durumlar yaratmıştır. Kullanıcının izniyle kilidi açmadan bildirimin geldiği, hatta içeriği görülebilir. Bunun ayarı görünürlüktür (visibility):

- **Public:** bildirimin bütün içeriği kilit ekranında görünür.
- **Private:** yalnız mesajın temel bilgisi görünür, alttaki ayrıntı görünmez.
- **Secret:** mesajın hiçbir kısmı görünmez.

Hoca anlatırken önce seçenekleri karıştırdığını söyleyip düzeltti; yukarıdaki liste düzeltilmiş halidir. Hangi seçeneğin kullanılacağı biraz da kullanıcının mahremiyet kaygısına bağlıdır.

> **Hocanın vurgusu:** Geliştirici bu konuda yalnız varsayılan ayarları belirleyebilir. Kullanıcı ayarı değiştirdiğinde programın tekrar müdahale etme şansı yoktur. Kullanıcı her uygulamanın bildirim ayarını kendisi yapabilir.

### 2.3 Uygulama ikonu rozeti (notification dot)

iOS tarafı yeni mesaj geldiğinde uygulama ikonunun köşesine kaç mesaj olduğunu gösteren bir sayı (badge) koyuyordu. Android 8 ile Google da benzer bir yaklaşımı, "notification dot" adını verdiği renkli bir rozetle getirdi. Rozete tıklanarak doğrudan bildirimlere gidilebilir ya da ikona uzun basılarak bildirimler gösterilebilir. Böylece kullanıcı ana ekranda gezerken hangi uygulamaya yeni bildirim geldiğini anlayabilir.

Hoca burada kullanıcı deneyimi (UX) ve kullanıcı arayüzünün (UI) önemine dikkat çekiyor: kullanıcı karmaşık bildirimler arasında yolunu bulabilsin diye işletim sistemleri her sürümde özellikle insan-bilgisayar etkileşimi noktalarında yeni çözümler getiriyor. Eskiden bildirim ayarları bütün uygulamaları kapsardı; bugün Gmail, SMS ve WhatsApp için ayrı ayarlar yapılabiliyor.

### 2.4 Giyilebilir cihazlar

Kullanıcının eşlenmiş bir Wear OS cihazı (örneğin akıllı saat) varsa bütün bildirimler, genişletilebilir bildirimler ve aksiyon butonları dahil, otomatik olarak orada da görünür (ekrandan, 00:20:00). Bunun için özel kod yazmak gerekmez; Wear OS ile Android kendi aralarında halleder. Bu mekanizma yine ayarlarla yönetilebilir.

## 3. Bildirimin Anatomisi

Bir bildirimde görünen bilgiler bildirimin temel yapısını oluşturur. Hoca slayttaki numaralı parçaları tek tek anlatıyor:

- **Küçük ikon:** Geliştirici belirler, `setSmallIcon` ile verilir.
- **Uygulama adı:** Sistem tarafından sağlanır; bildirimin hangi uygulamaya ait olduğunu gösterir.
- **Zaman damgası:** Mesajın ne zaman, kaç dakika önce geldiğini gösterir. `setWhen` ile ayarlanır, `setShowWhen(false)` ile gizlenebilir.
- **Büyük ikon:** İsteğe bağlıdır, `setLargeIcon` ile verilir.
- **Başlık:** İsteğe bağlıdır.
- **Metin:** Bildirimin içeriği.

Bu metotlar notification builder üzerinden çağrılarak bildirimin nasıl görüneceği belirlenir.

Android 12 ile yeni bir güvenlik seviyesi geldi. Normalde telefon kilitliyken gelen bir bildirime tıklayınca uygulamaya gidilir ve güvenlik kontrolü yoktur. Bir bildirim aksiyonu yapıldığında kişiye şifre sorulması isteniyorsa `setAuthenticationRequired(true)` verilir; o zaman kilit ekranından işlem yapmak için mutlaka kimlik doğrulama istenir.

## 4. Genişletilebilir Bildirimler ve Gruplama

Bildirimlerin kısa olduğu varsayılır ama bu her zaman böyle değildir. Örneğin bir e-posta uygulaması e-postanın içeriğini de göstermek isteyebilir. Bunun için genişletilebilir (expandable) bildirimler vardır. Slayta göre varsayılan olarak bildirim metni tek satıra sığacak şekilde kırpılır; daha uzun bir bildirim için ek bir şablon uygulanarak genişletilebilir daha büyük bir metin alanı açılır (ekrandan, 00:25:00). Slayttaki örnekte bir Gmail bildirimi kapalıyken yalnız gönderen ve konuyu, açılınca e-postanın gövdesini ve REPLY, ARCHIVE butonlarını gösteriyor.

Aynı uygulamadan çok sayıda bildirim geldiğinde bunlar gruplanabilir. Örneğin Gmail'den 10 e-posta geldiyse her biri ayrı bildirim olarak ekranı kaplamak yerine tek bir Gmail bildirimi olarak konumlanır. Kullanıcı gruba dokunduğunda içindeki bildirimler tek tek görünür ve aralarında gezebilir. Böylece ekranda başka uygulamaların bildirimleri için de yer kalır.

> **Hocanın vurgusu:** Notification group özelliğinden faydalanmak kullanıcı memnuniyetini artıran bir yaklaşımdır.

## 5. Bildirim Kanalları, Öncelik ve Rahatsız Etmeyin Modu

### 5.1 Kanallar ve öncelik

Bildirimlere kanal (channel) özelliği verilerek öncelikleri farklılaştırılabilir. Böylece aynı uygulamadan gelen acil mesajlar ile çok önemli olmayan mesajlar farklı kurallarla kullanıcıya iletilir. Kullanıcının gördüğü öncelik seviyeleri şöyle davranır:

- **Urgent:** ses çıkarır ve heads-up olarak yukarıdan aşağı görünür.
- **High:** yalnız ses çıkarır.
- **Medium:** ses çıkarmaz.
- **Low:** ses çıkarmaz, status bar'da da görünmez.

Hoca bunun anlamını şöyle açıklıyor: bir uygulamadan gün içinde çok sayıda mesaj gelebilir. Öncelik bilgisi gözetilerek kurgulanan bildirimlerde kritik olanlar ses çıkarıp kullanıcıyı uyarırken, pazarlama mesajları gibi kritik olmayanlar yalnız drawer'da kalır, status bar'a bile çıkmaz. Kullanıcı bu ayarları uygulamanın bildirim ayarlarından değiştirebilir. Geliştirici programla varsayılanı belirler; kullanıcı değiştirdikten sonra programla müdahale edemez.

### 5.2 Rahatsız Etmeyin (Do Not Disturb) modu

Toplantıdayken ses, titreşim ya da alarm çalması istenmez. Bu yüzden Do Not Disturb modunun üç seviyesi vardır:

- **Total silence:** alarmlar dahil bütün ses ve titreşimler kalkar; kullanıcı hiçbir şekilde rahatsız edilmez.
- **Alarms only:** yalnız kurulan alarmlar ses ya da titreşim çıkarır.
- **Priority only:** hatırlatıcı (reminder), etkinlik (event), gelen arama, mesaj gibi kritik noktalarda kullanıcıyı bilgilendirecek kadar ses çıkar.

Bu ayar kişi özelinde de yapılabilir. Hoca bunların uygulama geliştirirken dikkat edilmesi gereken noktalar olduğunu söylüyor.

## 6. Önemli Notlar ve Sürümlere Göre Değişiklikler

### 6.1 Foreground servis bildirimleri

Slayttaki "Important Notes" bölümüne göre (ekrandan, 00:30:00) uygulama bir foreground servis çalıştırıyorsa, yani arka planda uzun süre çalışan ve kullanıcının fark ettiği bir servis (örneğin medya oynatıcı) varsa, bir bildirim zorunludur. Bu bildirim diğer bildirimler gibi kaydırılarak kapatılamaz; bildirimi kaldırmak için servis durdurulmalı ya da foreground durumundan çıkarılmalıdır. Hoca bunun amacını, kullanıcının arka planda çalışan bir servis olduğunu unutmaması olarak açıklıyor.

### 6.2 Gönderim sınırı (post limits)

Bildirimler çok sık geldiğinde her biri ses çıkarırsa kullanıcı rahatsız olur. Slayta göre (ekrandan, 00:30:00) Android 8.1 (API level 27) ile uygulamalar saniyede birden fazla bildirim sesi çıkaramaz. Uygulama bir saniye içinde birden çok bildirim gönderirse hepsi beklendiği gibi görünür, ama o saniyedeki yalnız ilk bildirim ses çıkarır. Ayrıca tek bir bildirim çok sık güncellenirse (örneğin bir saniyeden kısa sürede çok sayıda güncelleme) sistem bazı güncellemeleri düşürebilir.

> **Ders sonrası not:** Hoca bu sınırı önce "bir dakika" olarak hatırladığını söyledi, slaytta "bir saniye" yazdığını görünce kontrol etmek istediğini belirtti; özelliği de Android 8 ile gelmiş gibi anlattı. Slayttaki ifade Android 8.1 (API 27) ve saniyede en fazla bir sestir.

### 6.3 Sürümlere göre bildirim özellikleri

Hoca bildirim özelliklerinin sürümlere göre nasıl değiştiğini slaytlardan özetliyor:

- **Android 5.0:** kilit ekranı ve heads-up bildirimler tanıtıldı. Kilit ekranı için `setVisibility`, öncelik için `setPriority` metotları bu sürümde geldi.
- **Android 7:** bildirim şablonlarına resim ve avatar eklenebilmesi gibi görsel yenilikler, bildirimlere doğrudan cevap verebilme özelliği.
- **Android 8:** her bildirimin bir kanala ait olması ve kanalların yönetiminin kullanıcıya bırakılması; bildirim arka planına renk ekleme. <!-- BELİRSİZ: altyazıda "Notification'ların sunu uzatma özelliği" geçiyor; erteleme (snooze) ya da bildirim süresi (timeout) olabilir. -->
- **Android 13:** bildirimler için çalışma zamanı izni (runtime permission). Kullanıcı bu izni vermeden ilgili işlemler yapılamaz.

> **Ders sonrası not:** Hoca Android 13 iznini, izin verilmeden bildirimden aktiviteye geçilemeyeceği şeklinde anlattı. Android belgelerine göre büyük olasılıkla doğrusu şudur: Android 13 ile gelen `POST_NOTIFICATIONS` çalışma zamanı izni verilmezse uygulama (bazı istisnalar dışında) bildirim gösteremez; yani izin, bildirimin gösterilmesinin önkoşuludur.

Hoca 7 sürümüyle ilgili bir cümleyi de anlatıyor ama altyazıda tam anlaşılmıyor. <!-- BELİRSİZ: 00:32:14 civarında "Android katılıyor / Android tarafından 7 ile birlikte tanıtılıyor" geçiyor; hangi özelliğin kastedildiği anlaşılmıyor (büyük olasılıkla gruplanmış bildirimler). -->

## 7. Bildirim Oluşturmak ve PendingIntent

### 7.1 Temel bildirim

Bildirim oluşturmak için gerekli bağımlılıkların projeye eklenmesi gerekiyor. <!-- BELİRSİZ: altyazıda "AppCompat aktivite özelliğini buraya mutlaka eklemeniz gerekiyor" geçiyor; slayttaki bağımlılık satırı karelerde görünmüyor. --> Temel bir bildirim `NotificationCompat.Builder` ile kurulur. Slayttaki ilk örnek (ekrandan, 00:35:00):

```java
NotificationCompat.Builder builder = new NotificationCompat.Builder(this, CHANNEL_ID)
        .setSmallIcon(R.drawable.notification_icon)
        .setContentTitle(textTitle)
        .setContentText(textContent)
        .setPriority(NotificationCompat.PRIORITY_DEFAULT);
```

> **Hocanın vurgusu:** Kanal kimliğini (`CHANNEL_ID`) vermek kritiktir. Android 8 ve üzerinde kanal kimliği zorunludur; verilmezse hata oluşur.

Daha farklı stiller için `setStyle` gibi metotlar çağrılır; böylece metin daha büyük ya da kalın gösterilebilir. Slayttaki ikinci örnek, tek satıra sığmayan bir metni `BigTextStyle` ile gösteriyor (ekrandan, 00:35:00):

```java
NotificationCompat.Builder builder = new NotificationCompat.Builder(this, CHANNEL_ID)
        .setSmallIcon(R.drawable.notification_icon)
        .setContentTitle("My notification")
        .setContentText("Much longer text that cannot fit one line...")
        .setStyle(new NotificationCompat.BigTextStyle()
                .bigText("Much longer text that cannot fit one line..."))
        .setPriority(NotificationCompat.PRIORITY_DEFAULT);
```

### 7.2 PendingIntent nedir?

Hoca burada öğrencilere PendingIntent'in ne işe yaradığını sordu, birkaç öğrenciden cevap aldı ve ardından şöyle açıkladı: Yaptırılmak istenen bir iş o anda değil, ileride, kullanıcının bir aksiyonuna bağlı olarak yapılacaksa görev bir PendingIntent'e atanır. Bu intent arka planda askıda (suspend) bekler; kullanıcı ilgili aksiyonu aldığında ya da sistemde bir değişiklik olduğunda devreye girer ve görevi yerine getirir. Alarm Manager'da da aynı yapı konuşulmuştu: alarm kurulur, zamanı gelince PendingIntent aracılığıyla yapılacak iş yapılır.

Bildirimde PendingIntent `setContentIntent` ile bildirime bağlanır. Böylece bildirime ya da bildirimdeki bir aksiyon butonuna tıklanınca istenen iş gerçekleşir. Slayttaki örnek (ekrandan, 00:35:00):

```java
// Create an explicit intent for an Activity in your app
Intent intent = new Intent(this, AlertDetails.class);
intent.setFlags(Intent.FLAG_ACTIVITY_NEW_TASK | Intent.FLAG_ACTIVITY_CLEAR_TASK);
PendingIntent pendingIntent = PendingIntent.getActivity(this, 0, intent, 0);

NotificationCompat.Builder builder = new NotificationCompat.Builder(this, CHANNEL_ID)
        .setSmallIcon(R.drawable.notification_icon)
        .setContentTitle("My notification")
        .setContentText("Hello World!")
        .setPriority(NotificationCompat.PRIORITY_DEFAULT)
        // Set the intent that will fire when the user taps the notification
        .setContentIntent(pendingIntent)
        .setAutoCancel(true);
```

Burada `AlertDetails` sınıfını çağıran açık (explicit) bir intent oluşturulmuş, intent PendingIntent ile sarılmış ve işin gelecekte, kullanıcının bildirime dokunmasıyla yapılması sağlanmıştır.

> **Ek bilgi (derste anlatılmadı):** Android 12 (API 31) ve sonrasında PendingIntent oluştururken `PendingIntent.FLAG_IMMUTABLE` ya da `FLAG_MUTABLE` bayraklarından birinin verilmesi büyük olasılıkla zorunludur. Slayttaki `getActivity(this, 0, intent, 0)` çağrısı yeni hedef sürümlerde hata verebilir; bu durumda son parametre `PendingIntent.FLAG_IMMUTABLE` yapılır.

**Soru:** WhatsApp'ta bildirimden cevap yazabiliyoruz; bu da bununla mı yapılıyor? **Cevap:** Evet, bu PendingIntent ile yapılabilen özelliklerden biridir. Ama yalnız onu kapsamaz; bildirim üzerinden başlatılan her aksiyon böyle kurulur. PendingIntent bildirimlere özel bir yapı değildir; Alarm Manager'da ya da ileriye dönük her türlü işte kullanılabilir.

### 7.3 Kanal yaratmak ve önem seviyesi

Kanal yaratan kod slaytta şöyledir (ekrandan, 00:40:00):

```java
private void createNotificationChannel() {
    // Create the NotificationChannel, but only on API 26+ because
    // the NotificationChannel class is new and not in the support library
    if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.O) {
        CharSequence name = getString(R.string.channel_name);
        String description = getString(R.string.channel_description);
        int importance = NotificationManager.IMPORTANCE_DEFAULT;
        NotificationChannel channel = new NotificationChannel(CHANNEL_ID, name, importance);
        channel.setDescription(description);
        // Register the channel with the system; you can't change the importance
        // or other notification behaviors after this
        NotificationManager notificationManager = getSystemService(NotificationManager.class);
        notificationManager.createNotificationChannel(channel);
    }
}
```

Önem seviyesi `NotificationChannel` yapıcısına kanal kimliği ve adla birlikte parametre olarak verilir. Böylece oluşturulan bildirimin hangi önceliğe sahip olduğu belirlenir. Bölüm 5.1'deki kullanıcı seviyeleriyle eşleşme şöyledir:

| Kullanıcının gördüğü seviye | Koddaki önem sabiti | Davranış |
|---|---|---|
| Urgent | `IMPORTANCE_HIGH` | ses + heads-up |
| High | `IMPORTANCE_DEFAULT` | ses |
| Medium | `IMPORTANCE_LOW` | ses yok |
| Low | `IMPORTANCE_MIN` | ses yok, status bar'da yok |
| Hiçbir yerde görünmesin | `IMPORTANCE_NONE` | gösterilmez |

Kanallar farklı şekillerde özelleştirilebilir: mesaj geldiğinde kullanıcının nasıl uyarılacağı `enableLights`, `setLightColor`, `setVibrationPattern` gibi metotlarla kanal üzerinden ayarlanır. Bu ayar yalnız kanal ilk yaratıldığında yapılır. Kullanıcı ayarı değiştirdiğinde kontrol ona geçer; değiştirmezse geliştiricinin varsayılan ayarları kullanılmaya devam eder.

### 7.4 Kanal ayarlarını okumak

Aradan sonra hoca, kanal ayarları hakkında bilgi almak için `getNotificationChannel` ile kanalın alınabileceğini, `getVibrationPattern` ve `getSound` gibi metotlarla ayarların okunabileceğini anlatıyor. Kanal ayarları programla değiştirilemez ama kullanıcının yaptığı değişikliklerden bu yolla haberdar olunabilir.

## 8. Bildirime Aksiyon, Doğrudan Cevap ve İlerleme Çubuğu Eklemek

### 8.1 Aksiyon butonu

Eskiden bildirim tek yönlüydü: yalnız bilgi verir, bir değişiklikten haberdar ederdi. Bugün bildirim kullanıcının aksiyon almasını da sağlıyor. Bunun için yine PendingIntent kullanılır. Builder'a `addAction` metoduyla bir ikon, `strings.xml`'den alınan bir metin (örneğin snooze yazısı) ve butona tıklanınca çalışacak PendingIntent verilir. Slayttaki örnekte snooze aksiyonu, bir snooze intent'i üzerinden `MyBroadcastReceiver` sınıfına yönlendiriliyor. Hoca bunların bugün çok sık yazılan, kullanıcının bildirimle etkileşimini sağlayan kod parçaları olduğunu söylüyor.

### 8.2 Doğrudan cevap (direct reply)

Slaytta doğrudan cevap aksiyonu üç adımda kuruluyor (ekrandan, 01:00:00):

```java
// Key for the string that's delivered in the action's intent.
private static final String KEY_TEXT_REPLY = "key_text_reply";

String replyLabel = getResources().getString(R.string.reply_label);
RemoteInput remoteInput = new RemoteInput.Builder(KEY_TEXT_REPLY)
        .setLabel(replyLabel)
        .build();
```

```java
// Build a PendingIntent for the reply action to trigger.
PendingIntent replyPendingIntent =
        PendingIntent.getBroadcast(getApplicationContext(),
                conversation.getConversationId(),
                getMessageReplyIntent(conversation.getConversationId()),
                PendingIntent.FLAG_UPDATE_CURRENT);
```

```java
// Create the reply action and add the remote input.
NotificationCompat.Action action =
        new NotificationCompat.Action.Builder(R.drawable.ic_reply_icon,
                getString(R.string.label), replyPendingIntent)
                .addRemoteInput(remoteInput)
                .build();
```

Bu kod parçaları slaytta gösterildi; hoca ayrıntılı olarak satır satır anlatmadı.

### 8.3 İlerleme çubuklu bildirim

Örneğin bildirimdeki bir "Download" butonuyla dosya indirilmek isteniyor. İndirmenin ne kadar ilerlediği bildirimdeki bir progress bar ile gösterilebilir. Kullanıcı o aktiviteden çıkıp başka bir aktiviteye geçebileceği için, takip bir bildirim üzerinden yapılır: kullanıcı drawer'ı aşağı çekerek dosyanın ne oranda indiğini görür. Slayttaki örnekte builder'a "Picture Download" başlığı ve "Download in progress" metni verilir; ardından indirme ilerledikçe progress bar 0 ile 100 arasında uygun değere güncellenir.

### 8.4 Tam ekran bildirim

Gelen bir arama ya da WhatsApp görüntülü araması gibi durumlarda bilgi tüm ekrana yayılmak istenebilir. Ekran kilitliyse mesaj görülmeyebilir; kilitli değilse de kullanıcı önde başka bir iş yaparken önemli bir mesajı kaçırabilir. Bu tür acil mesajlarda `setFullScreenIntent` çağrılarak bildirimin kaçırılmaması sağlanır. Telefon görüşmeleri ilk geldiğinde heads-up gibi görünür; bir ayarla büyük ekrana taşınabilir.

## 9. Görevler, Back Stack ve Bildirimden Aktivite Başlatmak

### 9.1 Back stack

Android'de görevler (task) bir yığın (back stack) yapısında tutulur. Slayttaki şemada Activity 1, Activity 2'yi, o da Activity 3'ü başlatır; geri gidilince Activity 3 yok edilir ve Activity 2 yeniden ön plana gelir (ekrandan, 01:05:00). Slayttaki maddeler ve hocanın anlatımı:

- A aktivitesi B'yi başlattığında A durdurulur, ama sistem A'nın durumunu (kaydırma konumu, formlara girilen metin gibi) saklar. Kullanıcı B'deyken Back tuşuna basarsa A, durumu geri yüklenerek kaldığı yerden devam eder.
- Kullanıcı Home tuşuyla görevden ayrılırsa o anki aktivite durdurulur ve görev arka plana gider. Sistem görevdeki her aktivitenin durumunu saklar. Kullanıcı görevi başlatan ikona tekrar dokunursa görev ön plana gelir ve yığının tepesindeki aktivite devam eder (resume).
- Back tuşuna basılırsa o anki aktivite yığından çıkarılır ve yok edilir (destroy). Yığındaki bir önceki aktivite devam eder. Yok edilen aktivitenin durumu saklanmaz.
- Aktiviteler, başka görevlerden de olmak üzere, birden çok kez örneklenebilir.

> **Hocanın vurgusu:** Home tuşuna basmak ile Back tuşuna basmak arasında önemli bir fark vardır. Home aktiviteyi yalnız arka plana alır, aktivite ortadan kalkmaz. Back ise o anki aktiviteyi yığından alıp yok eder.

Birden çok örnek için hocanın örneği: Bir e-posta uygulamasında e-posta yazarken uygulama bırakılır; başka bir uygulamadan e-posta uygulamasına geçilip yazma aktivitesi yeniden çalıştırılırsa ikinci bir örnek yaratılır ve iki örnek ayrı yaşam döngüleriyle devam eder.

### 9.2 Bildirimden aktivite başlatmak

Bildirim uygulamaya bir giriş noktasıdır (entry point). Örneğin WhatsApp'tan gelen bir mesaj drawer'a düşer, ona tıklanınca doğrudan WhatsApp açılır. Bunun ötesinde bildirimdeki bir butona tıklanınca uygulamanın varsayılan ekranı yerine başka bir aktivitenin açılması da sağlanabilir.

Slaytta normal bir aktivitenin PendingIntent üzerinden başlatılmasını anlatan bir kod parçası var: bir intent yaratılır, `TaskStackBuilder` üzerinden bir yığın kurucu oluşturulur ve ilgili intent'ler sırayla eklenir. <!-- BELİRSİZ: bu slaydın kodu karelerde görünmüyor; ayrıntılar altyazıdan alınamadı. -->

> **Ek bilgi (derste anlatılmadı):** `TaskStackBuilder` kullanmanın amacı büyük olasılıkla şudur: kullanıcı bildirimden doğrudan uygulamanın iç sayfalarından birine girdiğinde Back tuşu ana ekrana değil, uygulamanın üst aktivitesine dönsün diye uygun bir yapay back stack kurulur.

## 10. Uygulama Çubukları ve Swipe-to-Refresh

### 10.1 App bar, ActionBar ve Toolbar

Application bar telefonun üst kısmına yerleştirilen, uygulamanın adı ve ikonunu taşıyan bir çubuktur; bu eski bir kullanımdır. Ardından ActionBar geldi: yine ekranın üst kısmında, uygulama bilgisi taşıyan ama bazen aksiyon da yaptırabilen bir çubuk. Bugün bunların yerini Toolbar aldı. Toolbar bir ViewGroup'tur ve aktivitenin herhangi bir bölgesine konabilir. Üzerine gezinmeyi kolaylaştıran ikonlar konarak ekranlar arası geçiş kolaylaştırılır. Hoca Toolbar'ın bugün çok sık kullanılan bir yapı taşı olduğunu ve XML tarafında tanımlanması gerektiğini söylüyor. Slaytlarda öğelerin nasıl seçildiğini gösteren kod parçaları da bulunuyor.

### 10.2 Swipe-to-Refresh

Hocanın örneği bir e-posta uygulaması: e-postalar bir ListView, GridView ya da RecyclerView'da gösteriliyor. Yeni e-posta gelip gelmediğini görmek için ekrana girip çıkmak istenmez; bir hareketle sistemin kontrol etmesi beklenir. Kullanıcı listeyi dikeyde aşağı çeker; bu hareket sunucuya bir istek gönderir ve yeni gelen bilgiler listeye öğe olarak eklenir.

Slayta göre (ekrandan, 01:10:00) swipe-to-refresh deseni tamamen `SwipeRefreshLayout` bileşeni içinde gerçekleşir. Bileşen dikey kaydırmayı algılar, kendine özgü bir ilerleme göstergesi gösterir ve uygulamadaki geri çağırma metotlarını tetikler. Bileşen layout dosyasında bir ListView ya da GridView'un ebeveyni olarak eklenir:

```xml
<android.support.v4.widget.SwipeRefreshLayout
    xmlns:android="http://schemas.android.com/apk/res/android"
    android:id="@+id/swiperefresh"
    android:layout_width="match_parent"
    android:layout_height="match_parent">

    <ListView
        android:id="@android:id/list"
        android:layout_width="match_parent"
        android:layout_height="match_parent" />

</android.support.v4.widget.SwipeRefreshLayout>
```

Liste görünümünün bu layout'un içine yerleştirilmiş olması gerekir. Action bar'a bir yenileme butonu eklemek de XML tarafında yapılır.

Yenileme isteği `setOnRefreshListener` ile takip edilir; `onRefresh` metodunda gerekli arka plan sorguları tetiklenir. Hoca bunun özellikle içeriği sık değişen bir RecyclerView için önemli bir kullanım olduğunu söylüyor. Action bar'daki yenileme butonu gibi bir öğe seçildiğinde çalışacak kod `onOptionsItemSelected` içine yazılır.

> **Ek bilgi (derste anlatılmadı):** Slayttaki `android.support.v4.widget.SwipeRefreshLayout` eski destek kütüphanesine aittir. AndroidX kullanan projelerde büyük olasılıkla `androidx.swiperefreshlayout.widget.SwipeRefreshLayout` sınıfı kullanılır.

## 11. Pasif Etkileşim: Toast ve Snackbar

### 11.1 Dinamik ve pasif etkileşim

Hoca kullanıcıyla etkileşim yöntemlerini ikiye ayırıyor. Swipe-to-refresh, kullanıcının hareketini (gesture) takip eden dinamik bir etkileşimdi. Pasif etkileşim ise kullanıcıyı bilgilendirmek için yapılan, kullanıcının üzerinde aksiyon alamadığı yapıdır.

### 11.2 Toast

En basit pasif mesaj Toast'tır. Metin oluşturulur ve `show()` metoduyla ekranda gösterilir. Süre (duration) ve `setGravity` ile konum ayarlanabilir; varsayılan konum ekranın altıdır. Biçim ve konum değiştirilebilir. Özel bir Toast görünümü için layout inflater kullanılır: içinde bir resim ve bir TextView bulunan bir XML dosyası inflate edilir, metin bilgileri XML'deki ilgili yerlerle ilişkilendirilir, Toast oluşturulur ve ilgili metotlarla konumu, süresi ve kullanacağı layout belirtildikten sonra `show()` ile gösterilir. Varsayılan kullanım çoğu iş için uygundur; daha profesyonel uygulamalar özel Toast görünümünü kendileri tasarlar.

### 11.3 Snackbar

Slayta göre (ekrandan, 01:15:00) bir uygulama, örneğin e-posta gönderdikten ya da dosya sildikten sonra kullanıcıya cevap beklemeden kısa bir onay göstermek isteyebilir. Mesaj kullanıcının görebileceği kadar belirgin, ama uygulamayla çalışmasını engellemeyecek kadar sade olmalıdır. Android bunun için Snackbar bileşenini sunar. Snackbar gösterilirken aktivite görünür ve etkileşimli kalır; kısa bir süre sonra Snackbar kendiliğinden kaybolur.

Hocanın anlatımıyla Snackbar Toast'ın bir alternatifidir, ama Toast'ta olmayan bir aksiyonu da içerebilir. Genellikle telefonun alt kısmında görünür. En sık örnek: e-posta listesinden bir e-posta silinince "1 item removed" mesajının yanında bir UNDO çıkar; buna basınca silinen e-posta gelen kutusuna geri döner. Aynısı bir resim uygulamasında silinen resmi geri almak için yapılabilir. "Resimleri silmek istediğinizden emin misiniz?" sorusu da Snackbar üzerinde onay/iptal seçenekleriyle sorulabilir.

Snackbar bir view ile ilişkilendirilir ve Toast'taki gibi `make` metoduyla mesaj yüklenip konumlandırılır. Snackbar'a aksiyon eklemek için slaytta küçük bir kod parçası var: aksiyon metnine tıklanınca yapılacak iş `MyUndoListener` sınıfının içine yazılır ve aksiyon Snackbar'a eklenir. <!-- BELİRSİZ: Snackbar kod slaytları karelerde görünmüyor; hoca ayrıca slayttaki bir görselde çalınan bir medyanın Snackbar üzerinde kontrol edilebildiğini söylüyor, bu görsel karelerde yok. -->

> **Hocanın vurgusu:** Snackbar dönem projesinde yapılan aksiyonlara eşlik edebilecek güzel bir özellik; kullanılması öneriliyor.

## 12. Diyaloglar

### 12.1 Diyalog nedir?

Slayta göre (ekrandan, 01:20:00) diyalog, kullanıcıdan bir karar vermesini ya da ek bilgi girmesini isteyen küçük bir penceredir. Ekranı doldurmaz ve genellikle kullanıcının devam etmeden önce bir aksiyon alması gereken modal olaylarda kullanılır. Hoca diyalog açıldığında arkadaki aktivitenin duraklatıldığını (pause) ve diyaloğun kullanıcıyı yaptığı işle ilgili uyardığını ya da "emin misiniz?" diye sorduğunu söylüyor. Slayttaki örnekler "Text message limit" (saklanacak mesaj sayısını seçtiren bir sayı seçici) ve "Erase USB storage?" (tüm fotoğraf ve medyanın kaybolacağını söyleyen, Cancel ve Erase butonlu) diyaloglarıdır.

Slayttaki diyalog türleri:

- **AlertDialog:** başlık, en fazla üç buton, seçilebilir öğelerden oluşan bir liste ya da özel bir layout gösterebilen diyalog.
- **DatePickerDialog / TimePickerDialog:** tarih ya da saat seçtiren, hazır arayüzlü diyalog.

Hoca uçak bileti alırken tarih seçme örneğini veriyor: eskiden tarih ve saat seçiciler ayrı bir diyalog olarak gelirdi; bugün çoğunlukla aktivitenin içine bir bileşen olarak gömülüyor. Diyaloglar daha çok "emin misiniz, son kararınız mı?" diye yapılan işin onayını son kez almak isteyen uygulamalarda kullanılıyor, çünkü dikkat çekecek bir aksiyon ancak böyle sağlanabiliyor.

Slayttaki uyarı kutusu ProgressDialog ile ilgilidir: Android'de ilerleme çubuğu gösteren `ProgressDialog` sınıfı kullanımdan kaldırılmıştır (deprecated), çünkü ilerleme gösterilirken kullanıcının uygulamayla etkileşimini engeller. Yükleme ya da belirsiz ilerleme gösterilecekse layout içinde bir `ProgressBar` kullanılmalıdır. Hoca bunun kullanıcı memnuniyetsizliği yarattığı için tercih edilmediğini vurguluyor.

### 12.2 AlertDialog oluşturmak

Hoca bir AlertDialog ile ışık (parlaklık) ayarı yapılabildiğini, yani AlertDialog'un belirli ayarların yapılmasını sağlayan işlerde de karşımıza çıktığını söylüyor. Notification builder'da olduğu gibi burada da bir `AlertDialog.Builder` vardır. Builder üzerinden ilgili metotlarla mesaj ve başlık belirlenir; ardından diyaloğun oluşması için `create()` metodu mutlaka çağrılmalıdır. Böylece diyalog ekranda konumlanabilir.

Diyaloğa butonlar eklenebilir. Genelde iki karşılık vardır: positive ve negative, çoğunlukla OK ve Cancel; ama yazılar değişebilir. Ayrıca onay ya da ret anlamı taşımayan neutral bir buton da kullanılabilir; örneğin hiçbir aksiyon yapılmayacaksa "Remind me later" denir ve diyalog kendiliğinden kapanır.

### 12.3 Liste ve özel layout

Diyaloğa liste de eklenebilir. Liste `setItems` metoduyla oluşturulur ve hangi öğenin tıklandığı `onClick` ile takip edilir. Slayttaki örnekte liste öğeleri (renkler) XML'den alınıyor ve bir öğeye tıklanınca yapılacak iş `onClick` içine yazılıyor. Çoklu seçim listesinde ("Pick your toppings": Onion, Lettuce, Tomato) birden fazla öğe işaretlenip OK ile onaylanabilir (ekrandan, 01:25:00). Özel bir layout ile kullanıcı adı ve parola alanları olan bir giriş (sign-in) diyaloğu da kurulabilir.

Hoca bu tür giriş ve seçim diyaloglarının bugün çok sık görülmediğini söylüyor: listeler dahil seçimler ağırlıklı olarak aktivitelerin içine konuyor, çünkü mümkün olduğunca her etkileşimin aktivitenin içinde olması isteniyor. AlertDialog'lar yalnız özel durumlarda, kullanıcının yaptığı şeyin farkında olması gerektiğinde ya da gerçekten özel bir liste seçimi olduğunda öneriliyor.

## 13. Uygulama: NotificationExample

### 13.1 Uygulamanın çalışması

Son bölümde hoca kendi telefonunda çalışan bir örnek uygulama gösteriyor. Uygulama açılınca bir giriş (login) ekranından `NotificationExample` aktivitesine geçiliyor. Ekranda beş buton var ve her biri farklı bir bildirim üretiyor:

- **Simple:** başlık ve metinden oluşan basit bir bildirim.
- **Big Text Style:** uzun metni öne çıkaran bildirim.
- **Big Picture Style:** bildirimin içine resmin büyük bir halini yerleştiren bildirim.
- **Inbox Style:** gelen bir e-posta gibi, başlığın altına satır satır içerik eklenmiş genişletilmiş bildirim.
- **Action:** üzerinde iki buton görevi gören aksiyon (Dismiss ve Delete) bulunan bildirim; bunlara basınca bildirim kalkıyor.

### 13.2 Aktivitenin yapısı

`NotificationExample` aktivitesi `View.OnClickListener` arayüzünü uyguluyor. Hoca bunun buton takibinin başka bir yolu olduğunu söylüyor: önceki örneklerde `OnClickListener` kodun içinde anonim sınıf olarak yaratılıyordu, burada ise aktivite arayüzü kendisi uyguluyor. `onCreate`'ten önce butonlar ve bir notification manager tanımlanıyor. `onCreate` içinde `setContentView`'dan sonra `createNotificationChannel` çağrılarak kanal oluşturuluyor, butonlar bağlanıyor ve aksiyonları `setOnClickListener` ile belirleniyor. Ardından `NotificationManagerCompat` hazırlanıyor. `onClick` içinde her buton ayrı bir metodu çağırıyor (`createSimpleNotification`, `createBigTextNotification` vb.).

### 13.3 Basit bildirim metodu

Hocanın anlatımına göre basit bildirim metodu şu adımları izliyor:

- `cancelAll()` ile daha önce gösterilmiş bildirimler temizleniyor.
- `drawable` altındaki resim decode edilerek bitmap'e dönüştürülüyor.
- Tıklanınca belirli bir web adresini gösteren bir `ACTION_VIEW` intent'i kuruluyor; bildirime dokunulunca bu adres bir tarayıcıda açılıyor. <!-- BELİRSİZ: altyazıda adres "Yıldız ..." diye bozuk geçiyor; kodun bu kısmı karelerde görünmüyor. -->
- Builder kanal kimliği verilerek oluşturuluyor; küçük ikon, başlık, metin ve varsayılan öncelik veriliyor.
- `setContentIntent` ile tıklanınca yapılacak iş PendingIntent olarak veriliyor, `setAutoCancel(true)` ile bildirimin dokunulunca kalkması sağlanıyor ve `build()` çağrılıyor.
- `notify` ile bildirim gösteriliyor.

### 13.4 BigTextStyle ve BigPictureStyle

Big text metodu ekrandan şöyle okunuyor (ekrandan, 01:45:00):

```java
private void createBigTextNotification(String title, String text, int notificationId) {

    //removes all previously shown notifications.
    mNotificationManagerCompat.cancelAll();

    Bitmap bitmap = BitmapFactory.decodeResource(getResources(), R.drawable.nature_img);

    NotificationCompat.BigTextStyle style = new NotificationCompat.BigTextStyle().bigText(text + " used for generating large-format notifications that ...")
            //set different title in expanded mode.
            .setBigContentTitle(null)
            //needed if an app sends notification from multiple sources(accounts).
            .setSummaryText("BigTextStyle");

    Notification notification = new NotificationCompat.Builder(this, CHANNEL_ID)
            .setSmallIcon(R.mipmap.ic_launcher_round)
            .setContentTitle(title)
            .setContentText(text + " used for generating large-format notifications that include a lot of text.")
            //set Big text template
            .setStyle(style)
            //Set the large icon in the notification.
            .setLargeIcon(bitmap)
            .build();

    mNotificationManagerCompat.notify(notificationId, notification);
}
```

<!-- BELİRSİZ: bigText(...) içindeki metnin sonu ekranın sağ kenarında kesildiği için "..." ile gösterildi. -->

Burada stil önce ayrı bir `BigTextStyle` nesnesi olarak kuruluyor: genişletilmiş moddaki başlık `setBigContentTitle(null)` ile boş bırakılıyor, özet metni `setSummaryText("BigTextStyle")` ile veriliyor. Builder'da `setStyle(style)` ile bildirimin bu stile göre oluşturulması sağlanıyor; `setLargeIcon(bitmap)` ile resim bildirimin yanına büyük ikon olarak konuyor. `build()` ile bildirim oluşturuluyor, `notify` ile drawer'a düşüyor.

Big picture metodunda ise metnin değil resmin öne çıktığı bir stil kullanılıyor. Ekranda görünen başlangıç kısmı (ekrandan, 01:45:00):

```java
private void createBigPictureNotification(String title, String text, int notificationId) {

    //removes all previously shown notifications.
    mNotificationManagerCompat.cancelAll();

    Bitmap bitmap = BitmapFactory.decodeResource(getResources(), R.drawable.nature_img);

    NotificationCompat.BigPictureStyle style = new NotificationCompat.BigPictureStyle()
            //set big picture
            .bigPicture(bitmap)
            //set the content text in expanded form.
            ...
```

Hocanın anlatımına göre bu stilde gösterilecek resim verilir, istenirse metin bilgisi eklenir; başlık ve ikon ayrıca set edilmez. Builder oluşturulur ve `setStyle` ile bu stil parametre olarak verilir; böylece resim ekranın önemli bir kısmını kaplayacak şekilde gösterilir.

### 13.5 InboxStyle

Inbox stilinde önce satırlar oluşturuluyor, stil `NotificationCompat.InboxStyle` olarak tanımlanıyor ve satırlar bu stile ekleniyor. Özet metnine "Inbox Style" yazılıyor, içerik kısmına parametre verilmiyor. Yine `setStyle` ile stil bildirime veriliyor ve `notify` ile gösteriliyor.

### 13.6 Aksiyonlu bildirim

Son metot stil yerine butonların eklendiği kısmı gösteriyor (ekrandan, 01:50:00):

```java
private void createActionNotification(String title, String text, int notificationId) {

    //removes all previously shown notifications.
    mNotificationManagerCompat.cancelAll();

    Intent intent = new Intent(getApplicationContext(), Receiver.class);
    intent.setAction("ACTION_CANCEL");

    //passing notificationId to receiver class through intent
    intent.putExtra("id", notificationId);

    PendingIntent pendingIntent = PendingIntent.getBroadcast(getApplicationContext(), 0, intent, PendingIntent.FLAG_UPDATE_CURRENT);

    //action fire on click of notification Dismiss action button.
    NotificationCompat.Action actionDismiss =
            new NotificationCompat.Action.Builder(0,
                    "Dismiss", pendingIntent)
                    .build();

    //action fire on click of notification Delete action button.
    NotificationCompat.Action actionDelete =
            new NotificationCompat.Action.Builder(0,
                    "Delete", pendingIntent)
                    .build();

    Notification notification = new NotificationCompat.Builder(this, CHANNEL_ID)
            .setSmallIcon(R.mipmap.ic_launcher_round)
            .setContentTitle(title)
            .setContentText(text)
            .setStyle(new NotificationCompat.BigTextStyle().bigText("This is an example of BigTextStyle notification with action."))
            //Add actions Dismiss and Delete to this notification.
            .addAction(actionDismiss)
            .addAction(actionDelete)
            .build();

    mNotificationManagerCompat.notify(notificationId, notification);
}
```

Hocanın açıklamaları:

- Önce `Receiver` sınıfını hedefleyen bir intent yaratılıyor; bu sınıf aksiyonu takip edecek. `setAction("ACTION_CANCEL")` ile aksiyon, `putExtra("id", notificationId)` ile bildirim kimliği intent'e konuyor.
- Intent `PendingIntent.getBroadcast` ile sarılıyor.
- "Dismiss" ve "Delete" için iki ayrı `NotificationCompat.Action.Builder` kuruluyor; ikisine de aynı PendingIntent verildiği için iki buton aynı işi yapıyor. Hoca normalde farklı aksiyonlar atanması gerektiğini, örneğin butonların bir sayfaya yönlendirebileceğini söylüyor.
- Önceki örnekten farklı olarak `BigTextStyle` ayrı bir değişkende yaratılmadan doğrudan `setStyle` içinde oluşturuluyor.

> **Hocanın vurgusu:** Unutulmaması gereken en önemli nokta, yaratılan aksiyonların `addAction` ile bildirime mutlaka eklenmesidir. Eklendikleri andan itibaren bildirimdeki iki buton tıklandığında ilgili PendingIntent görevini yerine getirir.

`createNotificationChannel` metodu daha önce slaytta görülenle aynı, varsayılan bir kod parçasıdır. Öğrencinin isteğiyle gösterilen `Receiver` sınıfında da özel bir kod yok, yalnız bildirim ortadan kaldırılıyor.

**Soru:** Bildirimler eklenirken birbirlerini ezme (override) sorunu yaşanabilir mi? **Cevap:** Örnekteki beş bildirimin her biri ayrı bir butonun tıklanmasıyla tetiklenen ayrı bir metotta oluşturuluyor; bu yüzden birbirleriyle çakışmıyorlar. Bildirimler bir aksiyonun sonucunda gösterilir ve hangisinin yaratılacağı burada ayrı metotlarla kurgulandı. Metot ayırmak zorunlu değildir, bildirimler koşula bağlı olarak da yaratılabilir; ama metot kullanmak işi takip edilebilir hale getirir.

> **Ek bilgi (derste anlatılmadı):** `notify(id, notification)` çağrısında aynı kimlik (id) yeniden kullanılırsa yeni bildirim büyük olasılıkla eskisinin yerine geçer (günceller); farklı kimlikler ise ayrı bildirimler üretir. Örnekteki metotlar ayrıca her seferinde `cancelAll()` çağırdığı için yeni bildirim gelmeden eskiler temizleniyor.

## 14. Uygulama: DownloadManager ile Dosya İndirmek

### 14.1 Uygulamanın çalışması

Hoca geçen hafta bahsettiği indirme işlemi için küçük bir örnek gösteriyor. Ekranda Download, View All ve Delete butonları var:

- **Download:** verilen bir adresteki (resim, PDF vb.) uzak dosyayı indiriyor; dosya çok küçük olduğu için ilerleme çubuğunun dolması görülemiyor, bildirimde "Download Complete" görünüyor. Örnekte bölüm web sitesindeki bir haberin resmi indiriliyor; ad değiştirilmediği için bütün resimler aynı adla kaydediliyor.
- **View All:** indirilen resimleri sistemin varsayılan arayüzünde gösteren bir intent başlatıyor.
- **Delete:** en son indirilen dosyayı siliyor.

Gösterim sırasında Delete eski dosyaları silmedi; hoca kodu açarak nedenini buldu (bkz. 14.3).

### 14.2 Kod

Ekrandan okunan kısım (ekrandan, 02:00:00):

```java
public class DownloadActivity extends AppCompatActivity {

    private DownloadManager downloadManager;
    private String fileName=null;
    private long downLoadId;

    /**
     * Initialize download manager
     */
    private void initializeDownloadManager() {
        downloadManager= (DownloadManager) getSystemService(DOWNLOAD_SERVICE);
        fileName="Voyager";
    }

    /**
     * Set the title and desc of this download, to be displayed in notifications.
     */
    private void downloadFile(){

        DownloadManager.Request request=new DownloadManager.Request(Uri.parse("https://ce.yildiz.edu.tr:8080/news-images/..."));
        request.setTitle("Voyager")
                .setDescription("File is downloading...")
                .setDestinationInExternalFilesDir(this,Environment.DIRECTORY_DOWNLOADS,fileName)
                .setNotificationVisibility(DownloadManager.Request.VISIBILITY_VISIBLE_NOTIFY_COMPLETED);
        //Enqueue the download.The download will start automatically once the download manager is ready
        // to execute it and connectivity is available.
        downLoadId=downloadManager.enqueue(request);
    }

    /**
     * Cancel downloads and remove them from the download manager.
     * If there is a downloaded file, partial or complete, it is deleted.
     */
    private void deleteDownloadedFile() { downloadManager.remove(downLoadId); }
    private void openOurDownload(){
        try {
            downloadManager.openDownloadedFile(downLoadId);
            ...
```

<!-- BELİRSİZ: URL'nin devamı ekranın sağ kenarında kesildiği için "..." ile kısaltıldı. -->

Hocanın açıklamaları:

- `onCreate` içinde XML ile ilişkilendirme yapıldıktan sonra `initializeDownloadManager` çağrılıyor. DownloadManager `getSystemService(DOWNLOAD_SERVICE)` ile, yani sistemin indirme servisi üzerinden ilklendiriliyor. Dosya adı statik olarak "Voyager" verilmiş; bu ad kullanıcıdan da alınabilir.
- `DownloadManager.Request` ile bir istek oluşturuluyor. İstek, `Uri.parse` ile çözümlenen bir adrese (bölümün web sitesindeki bir haberin resmi) yapılıyor. Başlık, indirme sırasında görünecek "File is downloading..." açıklaması ve hedef (Downloads klasörü) belirtiliyor.
- `downloadManager.enqueue(request)` isteği kuyruğa gönderiyor. O sırada başka indirmeler varsa istek sıraya giriyor; dönen kimlik, DownloadManager listesindeki kimliktir ve takip bu kimlikle yapılıyor. Sıradaki işler bitince DownloadManager isteği gerçekleştiriyor.
- Açma işlemi için hoca, indirilenler klasörünü göstermek üzere `ACTION_VIEW_DOWNLOADS` aksiyonlu örtük (implicit) bir intent oluşturulduğunu anlatıyor; işletim sistemi kendi varsayılan arayüzünde dosyaları gösteriyor, resme dokununca büyük hali açılıyor.

### 14.3 Neden eski dosyalar silinmedi?

Silme metodu `downloadManager.remove(downLoadId)` yalnız en son `enqueue` ile alınan kimliğe ait dosyayı kaldırıyor. Program çalışırken hangi dosya indirildiyse kimliği elde olduğu için yalnız o silinebiliyor. Daha önceki çalıştırmalarda oluşturulmuş dosyaların kimlikleri tutulmadığı (program telefona sıfırdan yüklendiği) için silinemedi. Hoca nedenin bu olduğunu, tek bir indirme kimliği üzerinden takip yapıldığını söylüyor.

## Örnek Sorular

**Soru 1** (derste sözlü, 00:35:21): PendingIntent ne görevi görür?

> **Çözüm (derste verildi):** PendingIntent, bir işin o anda değil ileride, kullanıcının bir aksiyonuna ya da sistemdeki bir değişikliğe bağlı olarak yapılması için kullanılan intent'tir. Arka planda askıda bekler; kullanıcı bildirime ya da bildirimdeki bir butona dokunduğunda, alarm zamanı geldiğinde vb. devreye girip görevi çalıştırır. Bildirime `setContentIntent` ya da `addAction` ile bağlanır; Alarm Manager'da da kullanılır.

**Soru 2** (derste sözlü, 00:38:45): WhatsApp'ta bildirimden cevap yazabilme özelliği PendingIntent ile mi yapılır?

> **Çözüm (derste verildi):** Evet, PendingIntent ile yapılabilen özelliklerden biridir; ama PendingIntent yalnız bunu değil, bildirim üzerinden başlatılan her aksiyonu kapsar. Doğrudan cevap için slaytta `RemoteInput` ile bir giriş alanı kurulur, `PendingIntent.getBroadcast` ile cevap PendingIntent'i hazırlanır ve `NotificationCompat.Action.Builder(...).addRemoteInput(remoteInput)` ile aksiyona eklenir (ekrandan, 01:00:00).

**Soru 3** (derste sözlü, 01:52:24): Birden fazla bildirim eklenirken bildirimler birbirini ezebilir (override) mi?

> **Çözüm (derste verildi):** Örnekteki her bildirim ayrı bir butonla tetiklenen ayrı bir metotta oluşturulduğu için birbirleriyle çakışmıyor. Bildirimler koşula bağlı olarak tek bir yerde de yaratılabilir; ama ayrı metot kullanmak kodu takip edilebilir kılar.

**Soru 4** (derste sözlü, 02:04:10): Uygulama görevi.

- (a) Daha önce yapılan uygulamada telefonun bir durumu değiştiğinde (pil durumu değişmesi, şarja takılma, Wi-Fi'ye bağlanma gibi; durum serbestçe seçilebilir) bu değişikliği tespit edip notification drawer üzerinden bir bildirimle kullanıcıya bildirin.
- (b) Uzaktaki bir adresten bir JSON dosyasını DownloadManager ile indirin ve içindeki bilgileri ekranda gösterin.

> **Çözüm (derste verilmedi):** Derste yalnız görev tanımı verildi. Dersteki parçalara dayanan bir yol şöyle olabilir; bu Android kodu ajan tarafından derlenip denenmedi, yalnız izlenecek adımlardır.
> (a) Önceki derslerdeki BroadcastReceiver ile ilgili sistem yayınını (örneğin şarj ya da bağlantı değişimi) dinleyin. `onReceive` içinde, Bölüm 7.3'teki gibi önceden yaratılmış bir kanalın kimliğiyle `NotificationCompat.Builder` kurun, `setSmallIcon`, `setContentTitle`, `setContentText` ile durumu yazın ve `NotificationManagerCompat.notify(id, notification)` ile gösterin. Android 13 ve üzerinde bildirim izninin verilmiş olması gerekir.
> (b) Bölüm 14.2'deki gibi `DownloadManager.Request` ile JSON adresini kuyruğa ekleyin ve dönen kimliği saklayın. İndirme bitince (örneğin indirme tamamlandı yayınını dinleyerek) `openDownloadedFile(id)` ya da dosya yolu ile dosyayı okuyun, metni bir JSON ayrıştırıcıyla (`JSONObject`/`JSONArray`) çözümleyin ve alanları bir TextView ya da listede gösterin.

## Dersin Toparlaması

Bu derste Android'de kullanıcıyı bilgilendirmenin ve onunla etkileşim kurmanın yolları işlendi. Bildirimlerin status bar, drawer, heads-up, kilit ekranı, rozet ve giyilebilir cihazlardaki gösterim biçimleri; küçük ikon, başlık, metin ve zaman gibi anatomik parçaları; genişletilebilir bildirimler ve gruplama ele alındı. Android 8 ile gelen kanallar ve önem seviyeleri (Urgent=HIGH, High=DEFAULT, Medium=LOW, Low=MIN), Rahatsız Etmeyin modunun üç seviyesi, foreground servis bildirimleri ve ses sınırı konuşuldu. Bildirim `NotificationCompat.Builder` ile kuruldu; PendingIntent ile bildirime dokunma, aksiyon butonları, doğrudan cevap ve ilerleme çubuğu bağlandı.

Ardından back stack'te Back ve Home tuşlarının farkı, bildirimden aktivite başlatmak, Toolbar ve Swipe-to-Refresh, pasif mesajlar olarak Toast ve aksiyon taşıyabilen Snackbar, son olarak AlertDialog, tarih/saat seçici diyaloglar ve kullanımdan kalkan ProgressDialog görüldü. Uygulama kısmında beş farklı bildirim türü üreten bir örnek ve DownloadManager ile dosya indirme örneği incelendi. Bir sonraki derste konum yöneticisi (Location Manager) ve konum bilgileriyle devam edileceği söylendi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
