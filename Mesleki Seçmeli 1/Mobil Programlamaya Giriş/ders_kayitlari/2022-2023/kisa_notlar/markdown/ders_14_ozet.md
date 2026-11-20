# Ders 14 Çalışma Özeti

## Genel Konular

- Mobil uygulamalarda konum bilgisinin önemi
  - Taksi çağırma gibi talep üzerine çalışan (on-demand) uygulamalar, sürücü ile müşteriyi konum eşleşmesi ve haritalama sayesinde buluşturur. Hava durumu uygulaması ise ülke ya da il değiştiğinde bölgenin hava durumunu kendiliğinden gösterir.
  - Uygulamaların konuma ihtiyaç duyduğu sıklık ve hassasiyet farklıdır. Navigasyon çok sık ve hassas konum ister. Hava durumu uygulaması için seyrek ve kaba konum yeterlidir.
  - Tasarım sırasında hangi sıklıkta ve hangi hassasiyette konum gerektiğine karar verilmelidir. Bunun nedeni konum almanın pil (enerji) maliyetidir.
- Konum kaynakları
  - GPS (Global Positioning System): uydulardan gelen sinyallerin süreleri üzerinden üçgenleme (triangulation) ile konum kestirilir. Normal şartlarda en yüksek hassasiyeti verir. Rusya'nın GLONASS'ı gibi başka ülkelerin uydu sistemleri de vardır.
  - Wi-Fi erişim noktaları ve baz istasyonları: konumları bilindiği için özellikle şehir merkezlerinde yüksek doğruluk verir. Kırsalda yoğunlukları azaldığı için hata payı büyür.
  - Başka bir uygulamanın daha önce aldığı son konumu kullanmak: neredeyse hiç enerji harcamaz.
  - Haritada gösterilen nokta ve çevresindeki daire, kişinin bu dairenin herhangi bir yerinde olabileceğini anlatır. Kapalı alanlarda, bodrum katlarda ve beton yapıların içinde GPS sinyali zayıflar.
  - Enerji sıralaması (hocanın anlatımıyla): en çok GPS, sonra baz istasyonu, sonra Wi-Fi erişim noktası harcar. Neden uzaklıktır; haberleşmede gereken güç kabaca mesafenin karesiyle orantılı artar.
- Ön plan ve arka plan konum erişimi (foreground / background location)
  - Ön plan: uygulamanın bir activity'si görünürken ya da uygulama bir foreground service çalıştırırken konum alınır. Örnekler: navigasyonda adım adım yol tarifi, mesajlaşma uygulamasında anlık konum paylaşmak.
  - Foreground service çalışırken sistem kalıcı bir bildirim gösterir.
  - Arka plan: uygulama kullanılmazken belirli aralıklarla konum alınır. Örnek: "yakındaki yerleri öner" özelliği.
- Konum izinleri
  - `ACCESS_COARSE_LOCATION`: yaklaşık (approximate) konum. `ACCESS_FINE_LOCATION`: hassas (precise) konum. `ACCESS_BACKGROUND_LOCATION`: arka plan konumu.
  - İzinler artık kurulumda değil, kullanım sırasında sorulur. Kullanıcı "While using the app", "Only this time" ya da "Deny" seçer (ekrandan, 00:25:00).
  - Hassas konum için hem FINE hem COARSE izni birlikte istenir; yaklaşık konum için COARSE yeterlidir.
  - Android 11'den itibaren ön plan ve arka plan konumu aynı anda istenirse sistem isteği reddeder. İzinler kademeli istenir.
  - Android 10 ve sonrasında arka planda sürekli konum alan uygulama için sistem kullanıcıya hatırlatma bildirimi gösterir.
- Google Play Services ve Fused Location Provider
  - Android, konum için Google Play Services'in sunduğu hizmetleri önerir. Project Structure > Dependencies bölümünden `play-services-location` (harita için `play-services-maps`) eklenir.
  - Adımlar: Google Play Services kurulumu, manifestte izinler, `FusedLocationProviderClient` oluşturma, son bilinen konumu alma (ekrandan, 00:30:00).
  - `getLastLocation()` sonucu `addOnSuccessListener` içinde işlenir; dönen `Location` nesnesi null olabilir, kontrol edilmelidir.
- Location nesnesinin null döndüğü durumlar (ekrandan, 00:35:00)
  - Cihaz ayarlarında konum kapalıysa (kapatmak önbelleği de siler).
  - Cihaz konumunu hiç kaydetmemişse (yeni cihaz ya da fabrika ayarlarına dönmüş cihaz).
  - Google Play Services yeniden başlamış ve konum isteyen aktif bir Fused Location Provider istemcisi yoksa.
  - Son bilinen konum saatler önce alınmış olabilir; ne zaman alındığı, doğruluğu ve kaynağı kontrol edilmelidir.
- Pil tüketimini belirleyen üç parametre: doğruluk (accuracy), sıklık (frequency), gecikme (latency)
  - `setPriority()` ile dört seçenek (ekrandan, 00:40:00): `PRIORITY_HIGH_ACCURACY`, `PRIORITY_BALANCED_POWER_ACCURACY`, `PRIORITY_LOW_POWER`, `PRIORITY_NO_POWER`.
  - `setInterval()`: uygulamanın konumu ne sıklıkla istediği. `setFastestInterval()`: başka uygulamalar için hesaplanan konumun bu uygulamaya en hızlı hangi aralıkla iletilebileceği (ekrandan, 01:00:00).
  - `setMaxWaitTime()`: gecikme (latency) ayarı.
- Kullanım senaryoları (ekrandan, 01:05:00)
  - Harita uygulaması: sık güncelleme, düşük gecikme, `PRIORITY_HIGH_ACCURACY` (gerekirse balanced). Uygulama kapanınca takip de bitirilmelidir.
  - Hava durumu: `getLastLocation()` yeterlidir.
  - Ev ya da iş yerinden ayrılmayı izlemek, mağaza yakınında bildirim: geofence.
  - Kullanıcının araç ya da bisiklet kullandığını anlamak: Activity Recognition API ile birlikte konum güncellemesi.
  - Pasif arka plan takibi: `PRIORITY_NO_POWER`, olmuyorsa balanced ya da low power; high accuracy kullanılmamalıdır.
- Sürekli konum güncellemesi
  - `LocationRequest` nesnesi oluşturulur, ayarları yapılır. `LocationSettingsRequest.Builder` ile `addLocationRequest` çağrılır, settings client üzerinden ayarlar kontrol edilir.
  - `requestLocationUpdates(locationRequest, locationCallback, looper)` ile güncelleme başlar, `removeLocationUpdates` ile biter. `onResume` içinde başlatılır, `onPause` içinde durdurulur (ekrandan, 01:10:00).
  - `onSaveInstanceState` ile güncelleme isteğinin durumu (boolean) saklanır; ekran döndürmede doğru devam edilir.
  - `setExpirationDuration` / `setExpirationTime` ile takibin süresi sınırlanır.
- Konum API'leri
  - Fused Location Provider API, Geofencing API ve en eski olan LocationManager API.
- Geofence (sanal bölge)
  - Enlem, boylam ve yarıçapla tanımlanan dairesel bölgedir. Olaylar: ENTER (giriş), EXIT (çıkış), DWELL (bölgede kalma) (ekrandan, 01:15:00).
  - Android 10 ve sonrasında `ACCESS_BACKGROUND_LOCATION` izni gerekir.
  - `LocationServices.getGeofencingClient()` ile istemci alınır. `Geofence.Builder` ile `setRequestId`, `setCircularRegion`, `setExpirationDuration`, `setTransitionTypes` ayarlanır (ekrandan, 01:20:00).
  - En az 100 metre yarıçap önerilir. Uygulama başına yaklaşık 100 geofence sınırı vardır.
  - `GeofencingRequest` builder ile listelenir. Olaylar `PendingIntent` ile bir Broadcast Receiver'a gider; receiver geçiş türünü kontrol edip bildirim gönderir.
  - Cihaz yeniden başlatma, uygulamanın kaldırılıp kurulması, uygulama verisinin ya da Google Play Services verisinin silinmesi durumlarında geofence'ler uygulama tarafından yeniden kaydedilmelidir.
  - Sorunlar (ekrandan, 01:25:00): geofence çok küçük, Wi-Fi kapalı, ağ bağlantısı yok, uyarılar gecikebilir (ortalama 2-3 dakika, uzun süre hareketsiz cihazda 6 dakikaya kadar).
- Örnek uygulama: MapActivity
  - Harita fragment'ı, `OnMapReadyCallback`, `FusedLocationProviderClient`, `LocationRequest` ve `LocationCallback` kullanan bir activity.
  - `getLastLocation()` ile alınan konum Toast ile yazdırılır ve haritada marker ile gösterilir (ekrandan, 01:50:00).
  - Google Maps için API anahtarı gerekir; anahtar `strings.xml` içine konur ve manifestte `meta-data` ile referans verilir (ekrandan, 01:55:00).
  - Kod `requestLocationUpdates` kullanacak şekilde değiştirilince konum 20 saniyede bir güncellenir; zoom seviyesi 5'ten 7'ye ve 12'ye çıkarılınca harita ülke, bölge ve ilçe ölçeğine iner.

## Hocanın Özellikle Vurguladığı Kısımlar

- Konum almanın maliyeti pildir
  - Hassasiyet, sıklık ve düşük gecikme arttıkça enerji tüketimi artar. Uygulamanın ihtiyacı analiz edilip en az maliyetli seçenek seçilmelidir.
- İzinler kademeli istenmelidir
  - Ön plan ve arka plan konumu birlikte istenirse Android 11 ve sonrası isteği reddeder. "Her şeyi istiyorum" yerine önce en gerekli izin istenir.
- `getLastLocation()` null dönebilir ve eski olabilir
  - Null kontrolü yapılmalı, konumun ne zaman alındığı değerlendirilmelidir.
- `setInterval` değeri `setFastestInterval` değerinden büyük olmalıdır
  - Örneğin interval 10 saniye, fastest interval 5 saniye anlamlıdır. Interval 10, fastest 20 saniye verilirse anlamsız ve hatalıdır.
- Arka plan konum erişimi yalnız gerçekten gerekiyorsa kullanılmalıdır
  - İzin alınmalı ve kullanıcı takibin sürdüğü konusunda bilgilendirilmelidir. Android 8 ve sonrasında arka planda saatte yalnız birkaç güncelleme gelir.
- Geofence yarıçapı 100 metrenin altında olmamalıdır
  - Küçük bölgeler sürekli giriş-çıkış takibine ve fazla enerji tüketimine yol açar. Cihaz yeniden başlatma gibi durumlarda geofence'ler yeniden kaydedilmelidir.

## Kısa Tekrar Notları

- Konum kaynakları: GPS (en hassas, en pahalı), baz istasyonu, Wi-Fi erişim noktası, son bilinen konum (neredeyse bedava).
- Ön plan konumu: görünür activity ya da foreground service. Arka plan konumu: `ACCESS_BACKGROUND_LOCATION`.
- COARSE = yaklaşık, FINE = hassas; hassas için ikisi birlikte istenir.
- Android 11+: ön plan ve arka plan izinleri ayrı ayrı istenir.
- Fused Location Provider için Google Play Services bağımlılığı gerekir.
- `getLastLocation()` → `addOnSuccessListener` → null kontrolü.
- `setPriority`: HIGH_ACCURACY, BALANCED_POWER_ACCURACY, LOW_POWER (şehir düzeyi, baz istasyonu), NO_POWER (pasif).
- `setInterval` > `setFastestInterval`; `setMaxWaitTime` gecikme içindir.
- `requestLocationUpdates` `onResume`'da, `removeLocationUpdates` `onPause`'da.
- Geofence: enlem + boylam + yarıçap; ENTER, EXIT, DWELL; en az 100 m; uygulama başına yaklaşık 100 geofence.
- Geofence olayları PendingIntent ve Broadcast Receiver ile işlenir; uyarılar birkaç dakika gecikebilir.
- Harita için API anahtarı `strings.xml` + manifest `meta-data`.

## Detaylı Açıklamalar

- **Konum kaynakları ve enerji.** Bir telefon konumu birkaç kaynaktan bulabilir. GPS, uydulardan gelen sinyallerin ulaşma sürelerinden üçgenleme ile konumu hesaplar ve normal şartlarda en hassas sonucu verir. Açık havada birkaç metreye kadar inen doğruluk mümkündür, ama bina içinde, bodrum katta ya da yoğun betonarme yapıların arasında sinyal zayıflar. Wi-Fi erişim noktaları ve baz istasyonlarının konumları bilindiği için bunlar da konum verir; şehir merkezlerinde yoğun oldukları için doğrulukları yüksektir, kırsalda düşer. Ayrıca işletim sistemi başka bir uygulamanın daha önce aldığı son konumu uygulamaya verebilir; bu neredeyse hiç enerji harcamaz. Hoca enerji sıralamasını GPS, baz istasyonu, Wi-Fi olarak verdi ve bunu sinyalin taşındığı mesafeyle açıkladı: haberleşmede gereken güç kabaca mesafenin karesiyle artar.

- **İzinler ve kullanıcı seçenekleri.** Manifestte `ACCESS_COARSE_LOCATION` yaklaşık konumu, `ACCESS_FINE_LOCATION` hassas konumu ister. Eskiden izinler kurulumda verilirdi; artık kullanım sırasında bir pencere çıkar. Yalnız COARSE istendiğinde pencerede yaklaşık konum sorulur; FINE ve COARSE birlikte istendiğinde kullanıcı "Precise" ile "Approximate" arasında seçim yapabilir (ekrandan, 00:25:00). Her iki durumda da "While using the app", "Only this time" ve "Deny" seçenekleri vardır. "Yakındaki yerleri öner" gibi sürekli güncellenen bir özellik ise arka plan konum izni ister. Android 11'den itibaren ön plan ve arka plan izinleri aynı istekte sorulursa sistem isteği kabul etmez; önce en gerekli izin istenir.

- **Son bilinen konum.** `LocationServices.getFusedLocationProviderClient(this)` ile istemci alınır, `getLastLocation()` çağrılır ve sonuç `OnSuccessListener<Location>` içinde işlenir (ekrandan, 00:30:00). Dönen `Location` nesnesinde enlem (latitude), boylam (longitude), yükseklik (altitude) ve hız bilgisi bulunabilir. Konum (dünya üzerindeki enlem-boylam noktası) ile adres (insanların o konumu tarif etmek için kullandığı bilgi) farklı şeylerdir; birinden diğerine dönüşüm ayrı bir iştir. Konum kapalıysa, cihaz hiç konum kaydetmemişse ya da Google Play Services yeniden başladıktan sonra aktif bir istemci yoksa nesne null olur. Son konum saatler önce, örneğin uçak moduna geçmeden önce alınmış da olabilir; bu yüzden yeni olup olmadığı, doğruluğu ve kaynağı kontrol edilmelidir (ekrandan, 00:35:00).

- **Doğruluk, sıklık, gecikme.** `PRIORITY_HIGH_ACCURACY` GPS, Wi-Fi, hücresel ağ ve sensörleri birlikte kullanır, pili hızlı tüketir. `PRIORITY_BALANCED_POWER_ACCURACY` GPS'i nadiren kullanır, Wi-Fi ve hücresel bilgiyle çalışır; hocaya göre en dengeli seçenektir. `PRIORITY_LOW_POWER` baz istasyonlarına dayanır ve şehir düzeyinde doğruluk verir. Telefon gelen aramalar için zaten baz istasyonuyla sürekli haberleştiğinden bu bilgi ek enerji harcamadan elde edilir; hava durumu uygulaması için yeterlidir. `PRIORITY_NO_POWER` yalnız başka uygulamaların hesapladığı konumları pasif olarak alır (ekrandan, 00:40:00). `setInterval(10 sn)` ve `setFastestInterval(5 sn)` örneğinde uygulama 10 saniyede bir konum ister; başka bir uygulama daha sık konum alıyorsa bu konumlar uygulamaya en fazla 5 saniyede bir iletilir, daha sık gelenler iletilmez.

- **Sürekli güncelleme.** `LocationCallback` içinde `onLocationResult` null kontrolü yapar ve `locationResult.getLocations()` üzerinden gelen konumları işler. `onResume` içinde `requestingLocationUpdates` doğruysa `startLocationUpdates()` çağrılır; bu da `fusedLocationClient.requestLocationUpdates(locationRequest, locationCallback, null)` çalıştırır (ekrandan, 01:10:00). `onPause` içinde `removeLocationUpdates` ile güncellemeler durdurulur. Güncelleme isteğinin durumu `onSaveInstanceState` ile saklanır.

- **Geofence.** Geofence, enlem, boylam ve yarıçapla tanımlanan dairesel bir sanal bölgedir. Sisteme bölgeye giriş (ENTER), bölgeden çıkış (EXIT) ve bölgede kalma (DWELL) olayları izletilir (ekrandan, 01:15:00). Kodda `geofenceList.add(new Geofence.Builder()...build())` ile istek kimliği, dairesel bölge, geçerlilik süresi ve geçiş türleri (`GEOFENCE_TRANSITION_ENTER | GEOFENCE_TRANSITION_EXIT`) verilir (ekrandan, 01:20:00). Olay olduğunda bir `PendingIntent` ile Broadcast Receiver çalışır; receiver geçiş türünü kontrol edip bildirim gönderir. Google Play Services güncellenince ya da konum süreci çökünce sistem geofence'leri kendisi yeniden kaydeder. Cihaz yeniden başlatılırsa, uygulama kaldırılıp kurulursa, uygulama ya da Google Play Services verisi silinirse uygulama bunları kendisi yeniden kaydetmelidir. Geofence servisi çoğu cihazda ağ konumunu kullandığı için Wi-Fi kapalıysa ya da veri bağlantısı yoksa uyarılar gelmeyebilir; uyarılar ortalama 2-3 dakika, uzun süre hareketsiz kalmış cihazda 6 dakikaya kadar gecikebilir (ekrandan, 01:25:00).

- **MapActivity örneği.** Hoca bir harita activity'si çalıştırdı. `onCreate` içinde istemci oluşturulur ve `fetchLocation()` çağrılır; bu fonksiyon önce izinleri kontrol eder. `getLastLocation()` ile gelen konum `currentLocation` alanına atanır, Toast ile yazdırılır ve `SupportMapFragment.getMapAsync(this)` çağrılır. `onMapReady` içinde `LatLng` oluşturulur, `MarkerOptions().position(latLng).title("I am here!")` hazırlanır, `CameraUpdateFactory.newLatLngZoom(latLng, 5)` ile kamera konumlanır ve `addMarker` ile işaret konur (ekrandan, 01:50:00). Haritanın çalışması için Google Maps konsolundan alınan API anahtarı `strings.xml` içine yazılır ve manifestte `<meta-data android:name="com.google.android.geo.API_KEY" android:value="@string/map_key"/>` ile referans verilir (ekrandan, 01:55:00). Kod `requestLocationUpdates` ile 20 saniyede bir güncelleme alacak şekilde değiştirildiğinde harita her güncellemede konuma döner; zoom seviyesi 5 ülke, 7 bölge, 12 ilçe ölçeğini gösterir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
