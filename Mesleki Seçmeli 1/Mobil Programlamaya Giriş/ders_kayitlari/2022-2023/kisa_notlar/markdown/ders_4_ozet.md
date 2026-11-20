# Ders 4 Çalışma Özeti

## Genel Konular

- Mobil uygulama geliştirme trendleri (önceki haftanın devamı)
  - Slayttaki başlıklar: katlanabilir cihazlar için uygulama, makine öğrenmesi ve yapay zekâ, chatbotlar, giyilebilir cihaz entegrasyonu, nesnelerin interneti (IoT), artırılmış ve sanal gerçeklik (AR/VR), mobil cüzdanlar ve mobil güvenlik (ekrandan, 00:10:00).
  - Öğrenmenin merkezde değil telefonlarda dağıtık yapılması: federe öğrenme (Federated Learning).
  - Uygulama kategorileri içinde en büyük pay oyunlarındır; ardından eğlence, fotoğraf ve video uygulamaları gelir. Fotoğraf uygulamaları artık benzer fotoğrafları gruplama, konuma göre gösterme, nesne adıyla arama gibi yapay zekâ destekli özellikler sunar.
- iOS ve Android ile uygulama geliştirmenin karşılaştırılması
  - iOS: kapalı kaynak, daha pahalı geliştirici hesabı, Apple cihazı ve Xcode gerekir, Swift daha basit bir dildir, mağaza onayı birkaç hafta sürebilir, enerji verimliliği daha iyidir.
  - Android: açık kaynak, daha ucuz geliştirici hesabı, emülatörle geliştirme yapılabilir, onay süreci hızlıdır ama denetim gevşek olduğu için hatalı veya zararlı uygulamaya daha sık rastlanır; özelleştirme ve pazar payı açısından avantajlıdır; cihaz, ekran ve çözünürlük çeşitliliği (parçalanma) dezavantajdır (ekrandan, 00:20:00).
  - Hedef kitle, gelir modeli (ücretli, reklam, uygulama içi satın alma) ve desteklenecek en düşük Android sürümü (minimum ve hedef SDK) baştan düşünülmelidir. Dünyada Android 10 ve sonrasını kullanan cihaz oranı sanıldığı kadar yüksek değildir.
- Instant App (anlık uygulama) kavramı
  - Uygulamanın tamamı yerine kullanıcının ihtiyaç duyduğu modül indirilir ve kurulum yapılmadan, bir bağlantı (URL) üzerinden çalıştırılır.
  - Alışveriş, ödeme, podcast ve haber uygulamaları için uygundur. Slayta göre Android 8.0 (API 26) ve üstünde `targetSandboxVersion` değeri 2 olan uygulamada veri tam sürüme otomatik aktarılır (ekrandan, 00:25:00).
  - Sınırları: sandbox ortamında çalışır, yaklaşık 15 MB boyut sınırı vardır, sistem broadcast mesajlarını alamaz, izinleri ve depolama kullanımı kısıtlıdır, başka uygulamalarla resim paylaşamaz, arka plan servisi çalıştıramaz.
- On-Demand (talep üzerine hizmet) uygulamaları
  - Taksi çağırma, içerik izleme, yemek siparişi, temizlik ve bakım hizmeti gibi uygulamalar.
  - Çoğu zaman iki ayrı uygulama gerekir (örneğin taksici tarafı ve müşteri tarafı). Mobil uygulama artık yalnız ön yüz değildir; bulut ya da sunucu tarafında arka uç kodu da yazılır, bağlantı koparsa kullanıcı kaldığı yerden devam edebilmelidir.
- Mobil uygulama başarı metrikleri
  - Performans metrikleri: uygulama çökmeleri, API gecikmesi, uçtan uca uygulama gecikmesi, dönem başına uygulama yüklenmesi, ağ hataları (ekrandan, 00:35:00).
  - Kullanıcı metrikleri: günlük ve aylık aktif kullanıcı, cihaz, işletim sistemi ve bölge dağılımı.
  - Bağlılık (engagement) metrikleri: uygulamada geçirilen süre, tekrar kullanma sıklığı, 3. ve 7. gün tutma (retention), oturumlar, kaldırma (uninstall) oranı.
  - İş metrikleri: müşteri edinme maliyeti, işlem geliri, terk oranı, LTV (müşteri yaşam boyu değeri), mağaza yıldız puanı (ekrandan, 00:40:00).
  - Erişilebilirlik (reachability): push ve uygulama içi bildirimlere tıklama oranı ve bildirime izin verme (opt-in) oranı (ekrandan, 00:45:00).
- Android mimarisi (beş katman, aşağıdan yukarı; ekrandan, 01:05:00)
  - Linux çekirdeği: sürücüler (ses, Binder IPC, ekran, klavye, Bluetooth, kamera, paylaşılan bellek, USB, Wi-Fi) ve güç yönetimi.
  - Donanım soyutlama katmanı (HAL): ses, Bluetooth, kamera, sensörler gibi donanımlara erişim.
  - Yerel C/C++ kütüphaneleri (WebKit, OpenMAX AL, Libc, Media Framework, OpenGL ES) ve aynı seviyede Android Runtime (ART) ile çekirdek kütüphaneler.
  - Java API Framework: Content Provider'lar, View sistemi ve yöneticiler (Activity, Location, Package, Notification, Resource, Telephony, Window).
  - Sistem uygulamaları: telefon, e-posta, takvim, kamera vb.
- Derleme yaklaşımları: JIT, AOT ve Android'in karma yapısı
  - JIT (just-in-time): kod uygulama çalıştırılırken derlenir; büyük uygulamalar yavaş çalışır.
  - AOT (ahead-of-time): kod önceden derlenir; hızlıdır ama hiç kullanılmayan kod için de derleme yapılır ve hem kaynak hem çalıştırılabilir kod saklandığı için yer iki katına çıkar.
  - Android ikisini birleştirir: sık kullanılan kısımlar önceden derlenir, az kullanılan kısımlar kullanılacağı zaman derlenir.
  - NDK (Native Development Kit) yerel kütüphane katmanına erişim sağlar; düşük seviyeli ve performans odaklı iş içindir. Genel geliştirmede Android SDK kullanılır.
- Activity ve yaşam döngüsü (ekrandan, 01:10:00)
  - Her ekran bir Activity'dir. Uygulama bir süreç gibi düşünülürse Activity bir iş parçacığına benzetilebilir (hocaya göre tam bir benzetme değil).
  - Akış: `onCreate()` → `onStart()` → `onResume()` → çalışıyor → `onPause()` → `onStop()` → `onDestroy()`; durdurulmuş Activity'ye dönülürse `onRestart()` → `onStart()`.
  - Activity kısmen görünür ama etkileşime kapalıysa `onPause()`, hiç görünmüyorsa `onStop()` durumundadır.
- Mimari ilkeler ve iyi uygulamalar
  - Katmanlar: UI katmanı (UI elemanları ve state holder'lar), isteğe bağlı Domain katmanı ve Data katmanı (repository'ler ve veri kaynakları: dosya, veritabanı, SharedPreferences).
  - UI ve veri birbirinden ayrılmalı, veriye yalnız belirli metotlar üzerinden erişilmelidir (Java'daki private alan ve getter/setter mantığı).
  - Slayttaki genel iyi uygulamalar: veriyi uygulama bileşenlerinde saklama, Android sınıflarına bağımlılığı azalt, modüllerin sorumluluk sınırlarını net çiz, modülden olabildiğince az şey dışa aç, uygulamanın her parçasını ayrı test edilebilir yap, güncel ve ilgili veriyi olabildiğince kalıcı sakla (ekrandan, 01:20:00).
  - Yararları: ölçeklenebilirlik, hızlı test ve hata ayıklama, bakım kolaylığı, daha iyi kullanıcı deneyimi.
- İlk uygulamayı kurmak
  - Uygulamanın birden fazla giriş noktası olabilir (Activity, Service, BroadcastReceiver). İlk açılacak Activity manifestte launcher olarak işaretlenir.
  - Farklı ekran boyutları ve yönleri (dikey, yatay) için farklı layout tasarlanır. Ekran yönü kilitlenebilir. Boyutlar DPI (density per inch) ile yönetilir.
- APK ve Android App Bundle (AAB)
  - Kaynak kod ve XML kaynak dosyaları APK paketine derlenir; Android cihaz uygulamayı bu paketten kurar (ekrandan, 01:30:00).
  - AAB bütün cihaz yapılandırmaları için kod ve kaynakları içeren bir arşivdir. Google Play, indirme sırasında cihazın donanım ve yazılımına uygun parçaları seçip gönderir; paket küçülür.
- En az ayrıcalık ilkesi (Principle of Least Privilege; ekrandan, 01:35:00)
  - Her uygulama ayrı bir Linux kullanıcı kimliğiyle, ayrı süreç ve sanal makinede çalışır; yalnız kendi bileşenlerine erişir.
  - Aynı sertifikayla imzalanmış uygulamalar aynı kullanıcı kimliğini paylaşıp aynı süreç ve VM içinde çalışabilir.
  - Konum, kamera, Bluetooth gibi cihaz kaynakları için kullanıcı açıkça izin vermelidir.
- Dört temel uygulama bileşeni
  - Activity: kullanıcı arayüzü olan tek ekran (e-posta uygulamasında giriş, liste, ayrıntı, yeni mail ekranları ayrı Activity'lerdir).
  - Service: arayüzü olmayan, arka planda uzun süren işler (müzik çalma). RAM gerektiğinde sistem servisi sonlandırabilir; sürekliliği garanti edilmez (ekrandan, 01:40:00).
  - Broadcast Receiver: sistemdeki ve diğer uygulamalardaki değişiklikleri (şarj, batarya, Wi-Fi, hücresel bağlantı) yayınla-abone ol mantığıyla izleme ve yayınlama.
  - Content Provider: uygulamalar arası veri paylaşımı; giriş noktası değildir.
- Intent
  - Activity, Service ve Broadcast Receiver'ları etkinleştiren asenkron mesajdır; bileşenler arası geçiş ve veri taşıma için kullanılır.
  - İki tür vardır: explicit (açık) ve implicit (örtük). Implicit intent yalnız isteği bildirir, sistem bu işi yapabilen uygulamaları listeler (e-posta gönderme, fotoğraf çekme). <!-- BELİRSİZ: explicit intent'in derste verilen tanımı altyazıda eksik (01:57:03-01:57:16). -->
- AndroidManifest.xml (ekrandan, 02:00:00)
  - Uygulamanın adı, ikonu, Activity'leri, servisleri, alıcıları, intent filter'ları, donanım gereksinimleri ve izinleri burada tanımlanır.
  - `ACTION_SEND` içeren intent filter, Activity'nin başka uygulamalardan gelen "gönder" isteklerine cevap verebileceğini bildirir.
  - `<uses-feature android:name="android.hardware.camera.any" android:required="true" />` kamerası olmayan cihazlarda uygulamanın mağazada görünmemesini sağlar.
  - `<uses-sdk android:minSdkVersion="7" android:targetSdkVersion="19" />` ile SDK 7'den eski cihazlar uygulamayı göremez.
- Uygulama kaynakları (App Resources; ekrandan, 02:05:00)
  - `res/` altında `drawable/`, `layout/`, `mipmap/`, `values/` (strings.xml, colors.xml) bulunur.
  - Metinler `@string/...`, renkler `@color/...`, resimler `@drawable/...` ile çağrılır. Hoca bunu C'deki `#define` benzetmesiyle anlattı. Sabit metin gömmek yerine kaynak kullanmak çoklu dil desteği ve yeniden kullanım sağlar.
- Yapılandırma değişiklikleri
  - Ekran döndürme, çoklu pencere gibi değişikliklerde Activity yeniden oluşturulur ve ekrandaki veri kaybolur. Veri `onSaveInstanceState` ile saklanıp yeniden oluşturmada geri yüklenir.
- İzinler
  - Normal izinler (cihazı ve mahremiyeti riske atmayan; Android 9 itibarıyla `PROTECTION_NORMAL` listesi: `INTERNET`, `ACCESS_WIFI_STATE`, `SET_WALLPAPER`, `FOREGROUND_SERVICE`, `VIBRATE` vb.; ekrandan, 02:10:00), imza (signature) izinleri ve tehlikeli (dangerous) izinler.
  - Tehlikeli izinler: takvim, arama kayıtları, kamera, kişiler, mikrofon, telefon araması, sensörler, SMS, depolama, konum.
  - Android 6'dan beri tehlikeli izinler çalışma anında istenir: `checkSelfPermission` ve `requestPermissions`.
- Android Studio ve ilk proje
  - Android Studio ücretsiz IDE'dir. SDK Manager ile API seviyelerine göre SDK indirilir, Device Manager ile sanal cihaz (emülatör) oluşturulur. Gradle derleme ve paketleme aracıdır; sürüm uyumuna dikkat edilir.
  - Gerçek cihazda çalıştırmak için ayarlardaki derleme numarasına 7 kez dokunularak Geliştirici Seçenekleri açılır ve USB hata ayıklama etkinleştirilir.
  - Hello World projesi: `activity_hello_world.xml` içinde `RelativeLayout` ve ortalanmış bir `TextView` (ekrandan, 02:25:00); `HelloWorldActivity` sınıfında `onCreate` içinde `setContentView(R.layout.activity_hello_world)` (ekrandan, 02:30:00).

## Hocanın Özellikle Vurguladığı Kısımlar

- Uygulama fikri kadar hedef kitle ve sürüm analizi önemlidir
  - Harika bir fikir, ihtiyaç yoksa ya da hedeflenen segment uygulamayı satın almıyorsa başarısız olur. Minimum ve hedef SDK sürümü bu analizle seçilir.
- Gerçek cihaz testi
  - Mağazaya çıkacak bir uygulama mutlaka gerçek cihazda test edilmelidir.
- Pause ve Stop farkı
  - Activity'ye ait görüntü arka planda da olsa ekrandaysa `onPause()`, hiç görüntü yoksa `onStop()`. Bildirim çubuğu indirildiğinde Activity `onPause()` olur.
- Yapılandırma değişikliğinde veri kaybı
  - Ekran döndürülünce Activity ölür ve form verileri kaybolur; bu veriyi korumak geliştiricinin sorumluluğudur.
- Geliştirici Seçenekleri güvenlik riskidir
  - Açıkken herhangi bir kod telefona doğrudan yüklenip çalıştırılabilir; işi bitince kapatılması önerilir.
- Gereksiz izin istenmemeli
  - Gereksiz tehlikeli izin istemek kullanıcıyı rahatsız eder, uygulamanın kurulmamasına yol açabilir.
- Metinleri kaynak dosyalardan çağırın
  - `android:text` içine sabit metin yazmak yerine `@string/...` kullanmak dil değişiminde ve yeniden kullanımda kolaylık sağlar.
- `setContentView`
  - Activity'yi layout ile "giydirdiğiniz" yerdir; arayüz ile kod arasındaki ilk bağlantıdır.

## Kısa Tekrar Notları

- Instant App: modül modül, kurulumsuz çalışma; yaklaşık 15 MB sınır; arka plan servisi ve broadcast yok.
- On-Demand uygulamalar ön yüz ve arka ucu birlikte gerektirir.
- Metrik grupları: performans, kullanıcı, bağlılık, iş; tutma için 3. ve 7. güne bakılır.
- Android katmanları: Linux çekirdeği → HAL → yerel kütüphaneler + ART → Java API Framework → sistem uygulamaları.
- JIT çalışma anında, AOT önceden derler; Android ikisini karma kullanır.
- NDK yerel kod, SDK genel geliştirme içindir.
- Yaşam döngüsü: onCreate, onStart, onResume, onPause, onStop, onRestart, onDestroy.
- Dört bileşen: Activity, Service, Broadcast Receiver, Content Provider (giriş noktası değil).
- Intent: explicit ve implicit olmak üzere iki tür; implicit yalnız isteği bildirir.
- Manifest: bileşenler, intent filter, `uses-feature`, `uses-sdk`, izinler.
- APK kurulum paketi; AAB cihaza göre parçalanan yayın paketi.
- En az ayrıcalık: her uygulama ayrı kullanıcı kimliği ve VM; paylaşım için aynı sertifika.
- İzinler: normal, signature, dangerous; dangerous izinler çalışma anında istenir.
- Döndürmede veri kaybını önlemek için `onSaveInstanceState`.
- Developer Options: derleme numarasına 7 kez dokun.

## Detaylı Açıklamalar

- **Instant App neden ortaya çıktı?** Google, kullanıcıların çok sayıda uygulama indirdiğini, bunların cihazda yer ve enerji tükettiğini ve uygulamaların modüllerinin büyük kısmının hiç çalıştırılmadığını gözlemledi. Bu yüzden kullanıcının yalnız ihtiyaç duyduğu modülü indirip önbellekte çalıştırması, iş bitince yer kaplamaması fikri geliştirildi. Mağazada bazı uygulamaların yanında "hemen dene" türünden bir bağlantı bulunur. Sınırları (sandbox, yaklaşık 15 MB, arka plan servisi ve broadcast yok, kısıtlı izin ve depolama) bu küçük ve hafif kalma amacının sonucudur.
- **JIT ve AOT dengesi.** JIT derlemede uygulama indirildiğinde değil, çalıştırıldığında derleme yapılır; her çalıştırmada derleme olduğu için büyük uygulamalar yavaşlar. AOT derlemede kod önceden derlenir; uygulama hızlı açılır ama hiç kullanılmayacak kod için de derleme yapılır ve kaynak kodla birlikte çalıştırılabilir kod da saklandığı için yer iki katına çıkar. Android, sık kullanılan kısımları önceden derleyip az kullanılanları gerektiğinde derleyen karma bir yol seçti.

> **Ek bilgi (derste anlatılmadı):** Dalvik sanal makinesi JIT kullanıyordu. ART, Android 5.0 ile AOT derlemeye geçti; büyük olasılıkla Android 7.0'dan itibaren profil güdümlü karma (JIT + AOT) derleme kullanılmaktadır.

- **Activity yaşam döngüsü.** Activity başlatıldığında `onCreate()`, `onStart()`, `onResume()` sırasıyla çağrılır ve Activity çalışır. Telefon araması ya da bildirim gibi bir şey öne gelirse `onPause()` çağrılır; Activity tamamen görünmez olursa `onStop()` çağrılır. Kullanıcı geri dönerse `onRestart()` ve `onStart()` ile kaldığı yerden devam eder. Kullanıcı Activity'yi kapatırsa ya da sistem bellek için temizlerse `onDestroy()` ile yaşam döngüsü biter. Slayttaki diyagrama göre daha yüksek öncelikli uygulamalar bellek isterse `onPause()` ya da `onStop()` durumundaki uygulamanın süreci öldürülebilir; kullanıcı tekrar gelirse `onCreate()` ile baştan başlar (ekrandan, 01:10:00). Bir uygulamanın yaşaması için bütün Activity'lerinin yaşaması gerekmez; ekrandaki Activity üzerinden hizmet devam eder.
- **Android App Bundle.** APK döneminde her şey her cihaza yükleniyordu. AAB ile geliştirici bütün cihazlar için tek paket hazırlar; Google Play indirme sırasında cihazın donanım ve yazılım özelliklerine (sensör, ekran boyutu, çözünürlük) bakıp kullanılmayacak kod ve kaynakları eler. Hocanın örneğiyle 100 MB'lık bir paket cihaza 70-80 MB olarak inebilir.

> **Ders sonrası not:** Hoca AAB'nin "yaklaşık 6-7 sene önce" geldiğini söyledi; AAB büyük olasılıkla 2018'de tanıtıldı, yani ders tarihinde yaklaşık 5 yıllıktı.

- **AndroidManifest örnekleri** (ekrandan, 02:00:00):

```xml
<?xml version="1.0" encoding="utf-8"?>
<manifest ... >
    <application android:icon="@drawable/app_icon.png" ... >
        <activity android:name="com.example.project.ExampleActivity"
                  android:label="@string/example_label" ... >
        </activity>
        ...
    </application>
</manifest>
```

```xml
<manifest ... >
    ...
    <application ... >
        <activity android:name="com.example.project.ComposeEmailActivity">
            <intent-filter>
                <action android:name="android.intent.action.SEND" />
                <data android:type="*/*" />
                <category android:name="android.intent.category.DEFAULT" />
            </intent-filter>
        </activity>
    </application>
</manifest>
```

```xml
<manifest ... >
    <uses-feature android:name="android.hardware.camera.any"
                  android:required="true" />
    <uses-sdk android:minSdkVersion="7" android:targetSdkVersion="19" />
    ...
</manifest>
```

- `required="true"` kamerasız cihazda uygulamanın mağazada gösterilmemesini sağlar; `false` olsaydı "kamerayı kullanırım ama zorunlu değil" anlamına gelirdi.
- **İzinlerin ayrıntısı.** Eskiden bütün izinler kurulumda bir kez alınırdı. Android 6 ile çalışma anı izinleri geldi: kritik bir kaynağa erişilirken açılır pencere ile izin sorulur, kullanıcı bir kezlik ya da kalıcı izin verebilir. Kodda `checkSelfPermission` ile iznin olup olmadığına bakılır, yoksa `requestPermissions` ile istenir. İmza (signature) izinleri kurulumda verilir ama izni tanımlayan uygulamayla aynı sertifikayla imzalanmış olmak gerekir.

> **Ders sonrası not:** Hoca tehlikeli izinlerin "hem install time sırasında" sorulması gerektiğini söyledi. Android 6 ve sonrasında tehlikeli izinler manifestte bildirilir ama kullanıcıya kurulumda değil, çalışma anında sorulur.

- **Hello World projesi** (ekrandan, 02:25:00 ve 02:30:00): Proje yapısında `manifests/AndroidManifest.xml`, `java/` altında `HelloWorldActivity`, `res/` altında `drawable`, `layout`, `menu`, `values` klasörleri görülür. Layout dosyası:

```xml
<RelativeLayout xmlns:android="http://schemas.android.com/apk/res/android"
    xmlns:tools="http://schemas.android.com/tools"
    android:layout_width="match_parent"
    android:layout_height="match_parent"
    tools:context=".HelloWorldActivity" >

    <TextView
        android:layout_width="wrap_content"
        android:layout_height="wrap_content"
        android:layout_centerHorizontal="true"
        android:layout_centerVertical="true"
        android:text="Hello world!"
        android:textSize="25sp" />

</RelativeLayout>
```

  - Editör `android:text` değerini katlanmış olarak "Hello world!" gösteriyordu; hoca tıklayınca altında `@string/hello_world` referansı olduğunu gösterdi. `values/strings.xml` içindeki değer "Merhaba Dünya" yapılınca ekrandaki metin de değişti.
  - Activity sınıfı:

```java
package codepath.demos.helloworlddemo;

import android.os.Bundle;
import android.app.Activity;
import android.view.Menu;

public class HelloWorldActivity extends Activity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_hello_world);
    }

    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        // Inflate the menu; this adds items to the action bar if it is present.
        getMenuInflater().inflate(R.menu.activity_hello_world, menu);
        return true;
    }
}
```

  - `savedInstanceState`, Activity kapanırken saklanan bilginin geri verildiği `Bundle` nesnesidir. `onCreateOptionsMenu` bu örnek için gerekli değildir. Layout ile koddaki bileşenler arasındaki bağlantı `R` sınıfı üzerinden kurulur.
  - Paket adı genellikle ters alan adı biçimindedir (yildiz.edu.tr için `tr.edu.yildiz`).

> **Ders sonrası not:** Hoca `import android.*` gibi yıldızlı içe aktarmanın bütün sınıfları uygulamaya ekleyip boyutu büyüttüğünü söyledi. Java'da `import` yalnız derleme zamanında adların çözülmesini sağlar; yıldızlı import paket boyutunu değiştirmez. Kullanılmayan kodun pakete girmemesi büyük olasılıkla R8/ProGuard küçültmesiyle sağlanır. Belirli sınıfları açıkça içe aktarmak yine de okunabilirlik açısından önerilir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
