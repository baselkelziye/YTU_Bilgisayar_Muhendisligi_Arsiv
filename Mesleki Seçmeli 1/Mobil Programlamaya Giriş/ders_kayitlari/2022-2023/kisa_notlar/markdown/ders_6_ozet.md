# Ders 6 Çalışma Özeti

## Genel Konular

- Aktivitenin uygulamadaki yeri
  - Aktivite bir ekranı temsil eder ve mobil uygulamanın temel yapı taşıdır. Aktiviteler birbirine en az bağımlılıkla çalışan küçük, bağımsız iş birimleri gibi düşünülebilir.
  - Uygulamanın genelde bir başlangıç (launcher) aktivitesi vardır, ama kullanıcı uygulamaya başka giriş noktalarından da girebilir. Örneğin başka bir uygulamadan "paylaş" denince bir e-posta uygulamasının yalnız gönderme aktivitesi açılabilir. Bu yüzden akış deterministik değildir, olay güdümlüdür (event-driven).
  - Büyük ekranlarda ekran bölünerek birden fazla aktivite aynı anda çalışabilir (multi-window). Bir aktivitenin alt işleri fragment'lara bölünebilir.
- Aktivitenin manifest dosyasında tanımlanması
  - Her aktivite `AndroidManifest.xml` içinde `<application>` etiketinin altında `<activity android:name=".ExampleActivity" />` biçiminde tanımlanır (ekrandan, 00:10:00).
  - Android Studio'nun ürettiği aktiviteler otomatik eklenir; dışarıdan projeye kopyalanan aktiviteler elle eklenmelidir.
  - Aktivitenin bir yeteneği varsa (örneğin metin paylaşma) `<intent-filter>` ile sisteme bildirilir. Ekrandaki örnek: `action` = `android.intent.action.SEND`, `category` = `android.intent.category.DEFAULT`, `data mimeType` = `text/plain` (ekrandan, 00:10:00). Böylece aktivite, ilgili isteği karşılayabilecek uygulamalar listesine girer.
- Activity yaşam döngüsü (lifecycle)
  - Sıra: `onCreate()` → `onStart()` → `onResume()` → Activity running → `onPause()` → `onStop()` → `onDestroy()`. `onStop()`'tan geri dönülürse `onRestart()` → `onStart()`; `onPause()`'tan dönülürse `onResume()` çağrılır. Bellek gerekince sistem duraklatılmış ya da durmuş uygulamanın sürecini öldürebilir (ekrandan, 00:15:00).
  - `onCreate()`: aktivite ilk kez yaratılır. İlklendirmeler, `setContentView` ile layout bağlantısı ve `findViewById` ile bileşen bağlantıları burada yapılır.
  - `onStart()`: aktivite görünür hale gelir.
  - `onResume()`: aktivite ön plana gelir, kullanıcıyla etkileşim bu durumda olur (ekrandan, 00:25:00). `onPause()`'ta bırakılan kaynaklar (örneğin sensör kaydı) burada yeniden alınır.
  - `onPause()`: aktivite artık ön planda değildir. Nedenleri: sistem kesmesi (telefon araması), multi-window modda odağın başka uygulamada olması, yarı saydam bir diyalog açılması. GPS gibi pil tüketen kaynaklar bırakılır; küçük bilgiler (örneğin SharedPreferences'a) yazılabilir (ekrandan, 00:30:00).
  - `onStop()`: aktivite görünmez olur (Home tuşu, başka aktiviteye geçiş). Kaynaklar bırakılır, kalıcı veriler (veritabanı vb.) yazılabilir. `onPause()`'a göre biraz daha uzun süren kapanış işleri yapılabilir.
  - `onDestroy()`: geliştiricinin `finish()` çağırması, Back tuşu ya da sistem kararıyla aktivite sonlanır. Yapılandırma değişikliği (cihazın döndürülmesi, multi-window'a geçiş, klavye ve dil ayarı değişikliği) de aktivitenin yok edilip yeniden yaratılmasına yol açar.
- Sistemin aktiviteyi bellekten atma önceliği (ekrandan, 00:35:00)
  - En düşük olasılık: ön plandaki (Resumed) süreç. Düşük: görünür ama odakta olmayan (Started/Paused). Daha yüksek: arka plandaki görünmez (Stopped). En yüksek: boş süreç (Destroyed).
- UI durumunu saklama seçenekleri (ekrandan, 00:55:00)
  - ViewModel: bellekte tutulur, hızlıdır, karmaşık nesneleri saklayabilir; yalnız yapılandırma değişikliğinde korunur, sistemin süreci öldürmesinde ve `finish()`'te korunmaz.
  - Saved instance state (Bundle): diske serileştirilir, yavaştır, yalnız ilkel tipler ve String gibi küçük nesneler içindir; yapılandırma değişikliğinde ve sistemin süreci öldürmesinde korunur, kullanıcının aktiviteyi tamamen kapatmasında (`finish()`) korunmaz.
  - Kalıcı depolama (persistent storage): disk ya da ağdadır, en yavaştır, sınırı disk alanı ya da ağ maliyetidir; üç durumda da korunur.
- `onSaveInstanceState` ve `onRestoreInstanceState` örneği (sayaç uygulaması)
  - `onSaveInstanceState(Bundle outState)` içinde `outState.putString("message", ...)` ve `outState.putInt("counter", counter)` ile değerler yazılır (ekrandan, 01:00:00).
  - Geri yükleme iki yolla yapılır: `onCreate` içinde `if (savedInstanceState != null)` kontrolüyle `getString`/`getInt` kullanmak ya da `onRestoreInstanceState` metodunu yazmak. İkisi birbirinin alternatifidir, ikisini birden yazmaya gerek yoktur.
- Layout XML temelleri
  - `match_parent` genişliği kapsayan bileşene göre, `wrap_content` içeriğe göre ayarlar. `hint` silik ipucu yazısı, `inputType="phone"` giriş türü kısıtıdır (ekrandan, 01:10:00).
  - Bir bileşene kimlik ilk tanımlanırken `@+id/ad`, var olan kimliğe başvururken `@id/ad` yazılır.
  - Tıklama işi kod içinde `setOnClickListener` ile ya da XML'de `android:onClick` özelliğiyle bağlanabilir.
- Intent ve türleri
  - Başka bir aktiviteyi çağırmak ve ona veri aktarmak için Intent kullanılır. Sonuç geri dönecekse `startActivityForResult` kullanılır.
  - Explicit intent: hedef sınıf bellidir (aktivite başlatma, broadcast receiver, arka plan servisi). Örnek: login doğruysa kullanıcı ekranına geçmek.
  - Implicit intent: yalnız yapılacak iş (action) ve veri söylenir; sistem intent filter'lara bakarak bu işi yapabilecek uygulamaları listeler. Örnekler: numara arama (`ACTION_DIAL`), haritada konum ve web adresi gösterme (`ACTION_VIEW`), e-posta gönderme (`ACTION_SEND`), takvime etkinlik ekleme (`ACTION_INSERT`).
  - `putExtra` ile gerekli bütün bilgiler intent'e tek tek yüklenir; intent ekrandaki bilgileri kendiliğinden taşımaz.
  - Intent'i karşılayacak aktivite olup olmadığı `queryIntentActivities` ile kontrol edilmeden `startActivity` çağrılmamalıdır (ekrandan, 01:25:00). Birden çok aday varsa sistem seçim (disambiguation) ekranı gösterir; istenirse her seferinde soran özel bir seçici (chooser) kullanılabilir.
- Android Studio'da ilk uygulama: basit login
  - İki aktivite (`Login`, `User`) ve iki layout (`activity_login.xml`, `activity_user.xml`) vardır. Login ekranı `RelativeLayout` içinde TextView'lar, iki EditText ve bir butondan oluşur (ekrandan, 01:40:00).
  - `Login.java` içinde `setContentView(R.layout.activity_login)`, `findViewById` ile `et_username`, `et_password`, `btn_login` bağlanır. Kullanıcı adı ve şifre `"admin"` ise Toast gösterilir ve explicit intent ile `User` aktivitesi başlatılır; değilse hata Toast'u gösterilir (ekrandan, 01:45:00).
  - Manifest'te bir aktivite MAIN ve LAUNCHER olarak işaretlenir; ikinci aktivite için yalnız ad tanımı yeterlidir.

## Hocanın Özellikle Vurguladığı Kısımlar

- Yaşam döngüsünü doğru kullanmanın önemi
  - Yanlış kullanılırsa telefon geldiğinde ya da başka uygulamaya geçildiğinde uygulama çöker, kullanılmayan kaynaklar boşa tüketilir, kullanıcının ilerlemesi kaybolur, ekran döndürülünce veri kaybolur (ekrandan, 00:20:00).
- Ayna metotlar
  - `onPause()`'ta yapılanın tersi `onResume()`'da yapılmalıdır. Örneğin `onPause()`'ta bırakılan sensör `onResume()`'da yeniden kaydedilmezse uygulama bir daha sensörü dinlemez.
- Back ve Home tuşunun farkı
  - Home tuşu: aktivite `onStop()`'ta kalır, kullanıcı hızlıca geri dönebilir. Back tuşu: "bu aktiviteyle işim bitti" demektir; `onPause()` → `onStop()` → `onDestroy()` çalışır.
- Veri saklamanın zamanlaması
  - Büyük veriler `onPause()`/`onStop()` içinde ana thread'de yazılmamalıdır; ayrı thread ile, tercihen aktivite çalışırken yazılmalıdır. En kötü yer `onDestroy()`'dur, çünkü yazma bitmeden aktivite yok olabilir.
- Uzun işler ana thread'de yapılmaz
  - 4-5 saniyelik bir iş ana thread'de yapılırsa ekran donar ve kullanıcı memnuniyetsiz olur.
- LogCat kullanımı
  - Her yaşam döngüsü metoduna log mesajı koyarak hangi duruma ne zaman geçildiği ve ne kadar sürdüğü izlenebilir. Çökme nedenleri (aktivite adının yanlış yazılması, aktivitenin manifest'e eklenmemesi gibi) LogCat'te görülür.
- Implicit intent'te kontrol
  - Talebi karşılayacak bir uygulama yoksa ve kontrol yapılmadıysa uygulama hata verir.
- Implicit ve explicit ayrımı
  - Linke tıklayınca "şununla aç" listesinin çıkması implicit intent'tir: "Bu işi benim adıma kim yapabilir?" Explicit intent: "Bu işi şu aktivite yapsın."

## Kısa Tekrar Notları

- Aktivite = bir ekran; her aktivite manifest'te tanımlanmalı.
- Intent filter = aktivitenin yapabildiği action, category ve veri tipini sisteme bildirmek.
- Yaşam döngüsü: onCreate → onStart → onResume → (running) → onPause → onStop → onDestroy; dönüşler onResume ve onRestart üzerinden.
- onCreate: ilklendirme, `setContentView`, `findViewById`.
- onPause: odak kaybı; pil tüketen kaynakları bırak. onResume'da geri al.
- onStop: görünmez; kalıcı veriyi yaz. onDestroy'da veri yazmaya güvenme.
- Ekran döndürme, dil ve klavye değişikliği = yapılandırma değişikliği = aktivite yeniden yaratılır.
- Atılma önceliği: Resumed < Started/Paused < Stopped < Destroyed (boş süreç).
- ViewModel: bellek, hızlı, yalnız yapılandırma değişikliği. Bundle: disk, ilkel tipler, sistemin öldürmesine de dayanır. Kalıcı depolama: her durumda kalır.
- `onSaveInstanceState` ile yaz; `onCreate`'de null kontrolü ya da `onRestoreInstanceState` ile oku.
- `@+id` tanımlar, `@id` başvurur.
- Explicit intent hedef sınıfı söyler; implicit intent yapılacak işi söyler.
- `putExtra` ile veri yükle; `queryIntentActivities` ile kontrol et; `startActivity` ile başlat.
- Fiziksel cihazla test: Ayarlar > Telefon hakkında > Yapı (build) numarasına 7 kez dokun → Geliştirici seçenekleri → USB hata ayıklama.

## Detaylı Açıklamalar

- **Aktivite ve giriş noktaları.** Masaüstü programlamadan farklı olarak mobil uygulamada kullanıcı uygulamaya tek bir kapıdan girmez. Bir uygulamanın e-postaları listeleyen ekranı launcher aktivitesidir, ama başka bir uygulama "paylaş" dediğinde aynı uygulamanın yalnız gönderme aktivitesi açılabilir. Bu nedenle aktiviteler birbirine gevşek bağlı, kendi işini yapan küçük modüller gibi tasarlanır. Bir aktivitenin başka uygulamalara hizmet edebilmesi için manifest'te intent filter tanımlanır; bu tanım "şu action'ı, şu kategoride, şu veri tipi için yapabilirim" demektir.

- **Yaşam döngüsü ve geri çağırma (callback) metotları.** Aktivite durum değiştirdiğinde sistem ilgili callback'i çağırır, geliştirici de bu metotlara o duruma uygun işleri yazar. `onCreate()` ilklendirme yeridir: layout XML dosyası `setContentView` ile bağlanır, XML'deki bileşenler `R` sınıfı üzerinden `findViewById` ile koddaki değişkenlere bağlanır. Hocaya göre görünür hale gelme `onStart()` ile olur. Telefon araması, bildirim, diyalog ya da multi-window'da odak kaybı `onPause()`'a yol açar; aktivite tamamen görünmez olunca `onStop()` çalışır. Android 7.0 (API 24) ve üstünde multi-window modda odakta olmayan bütün uygulamalar duraklatılır (ekrandan, 00:30:00).

  > **Ders sonrası not:** Hoca kullanıcıyla etkileşimin `onStart()` ile başladığını söyledi. Slayttaki tanıma göre (ekrandan, 00:25:00) aktivite kullanıcıyla `onResume()` sonrasındaki Resumed durumunda etkileşir; `onStart()` aktiviteyi yalnız görünür yapar.

- **Ayna çiftleri.** `onPause()` ile `onResume()` birbirinin tersidir: biri kaynağı bırakır, öteki geri alır. Hoca aynı ilişkinin `onStop()` ile `onRestart()` arasında da olduğunu söyledi.

  > **Ders sonrası not:** Android belgelerinde `onStop()`'un karşılığı genellikle `onStart()` olarak verilir; durmuş bir aktivite dönerken `onRestart()` ve ardından `onStart()` birlikte çalışır. `onStop()`'ta bırakılan bir kaynak büyük olasılıkla en güvenli biçimde `onStart()`'ta geri alınır.

- **onDestroy ve sürüm farkı.** Hoca, Android 11 ve öncesinde yok edilen aktivitenin bilgilerinin bellekten tamamen silindiğini, Android 12 ve sonrasında ise bellekte yer varsa sürecin bilgilerinin tutulup uygulamanın soğuk başlatma (cold start) yerine ılık başlatma (warm start) ile daha hızlı açıldığını anlattı. Android görevleri bir yığın (stack) mantığıyla tutar: açılan her görev yığına eklenir, Back ile üsttekiler çıktıkça eskiler öne gelir.

  > **Ders sonrası not:** Soğuk ve ılık başlatma ayrımı Android'de 12 sürümünden önce de vardı; sistem arka plandaki süreçleri bellek elverdiği sürece önbellekte tutar. Hocanın verdiği "11 ve öncesi / 12 ve sonrası" ayrımı büyük olasılıkla Android 12'nin bu davranışla ilgili bir değişikliğine dayanıyor; ayrıntısı derste verilmedi.

- **Saklama seçeneklerinin karşılaştırılması.** ViewModel bellekte durduğu için hızlıdır ve karmaşık nesneleri tutabilir, fakat yalnız yapılandırma değişikliğine dayanır. Bundle (saved instance state) diske serileştirildiği için yavaştır ve ilkel tipler ile String gibi küçük veriler içindir, ama sistemin süreci öldürmesinden sonra da geri yüklenebilir; bu yüzden geliştiriciler çoğunlukla Bundle'ı tercih eder. Kod içinde `finish()` ile bilinçli sonlandırmada Bundle devreye girmez. Büyük ya da kalıcı veri internal/external storage ya da ağ üzerinde saklanır.

- **Sayaç örneği (ekrandan, 01:00:00).** `MainActivity` (`AppCompatActivity`'den türetilmiş) içinde `Button button`, `TextView textView`, `int counter` alanları vardır. `onCreate` içinde Bundle null değilse mesaj Toast ile gösterilir ve `counter = savedInstanceState.getInt("counter", 0)` ile sayaç geri alınır (anahtar yoksa varsayılan 0). Buton tıklandığında TextView'daki sayı bir artırılıp yeniden yazılır. `onSaveInstanceState` içinde mesaj ve sayaç Bundle'a yazılır. Böylece kullanıcı sayacı örneğin 8'e getirdikten sonra ekranı döndürürse sayaç 8'den devam eder.

- **Intent ile e-posta ve takvim.** Uygulamanın kendi e-posta gönderme altyapısı (POP3, IMAP vb.) olmasa da `ACTION_SEND` intent'i ile alıcı, konu, metin ve ek dosya bir e-posta istemcisine aktarılabilir. `ACTION_INSERT` ile takvim uygulamasına başlangıç-bitiş zamanı, başlık ve konumu olan bir etkinlik gönderilebilir (ekrandan, 01:20:00). Karşı uygulama yalnız intent'e yüklenen bilgiyi alır.

- **Login uygulaması.** Kod, XML'deki `et_username`, `et_password` ve `btn_login` kimliklerini koddaki `username`, `password` ve `login` değişkenlerine bağlar. Butona anonim bir `View.OnClickListener` sınıfı verilir; `onClick` içinde `getText().toString().equals("admin")` ile kontrol yapılır. Doğruysa `new Intent(getApplicationContext(), User.class)` ile `User` aktivitesi başlatılır. Hoca bu örneğin ileride bir `User` sınıfı ve kayıt (sign-up) ekranıyla birden fazla kullanıcıyı destekleyecek şekilde genişletilmesini önerdi.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
