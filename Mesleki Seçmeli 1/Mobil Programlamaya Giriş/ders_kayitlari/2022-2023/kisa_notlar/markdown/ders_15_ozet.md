# Ders 15 Çalışma Özeti

## Genel Konular

- Haritalarla çalışmanın ön koşulları: SDK'lar ve API anahtarı
  - Android uygulamasında harita kullanmak için Android SDK'ya ek olarak Google Play Services SDK ve Maps SDK kurulmalıdır. Android Studio'da Google Maps Activity şablonu seçilebilir.
  - Haritaya erişim bir API anahtarı ister. Anahtar Google Cloud Platform Console'da proje seçilip "APIs & Services > Credentials > Create credentials > API key" adımlarıyla üretilir; üretimde kullanmadan önce anahtarın kısıtlanması önerilir (ekrandan, 00:35:00).
  - Anahtar, manifest dosyasında `application` etiketinin içine metadata olarak eklenir. Build Gradle tarafında ayrıca eklenti (plugin) ayarları gerekir; bunlar yapılmazsa alınan hatalar genelde bu eksiklerden kaynaklanır.
  - Anahtar sayesinde istekler sayılır ve sınırlandırılır. Anahtarsız ve sınırsız kullanım, platformun aşırı istek altında yönetilemez hale gelmesine yol açardı.
  - Kısıtlar iki başlıktadır: Application Restriction (anahtarın hangi uygulamadan kullanılabileceği) ve API Restriction (anahtarın hangi API'lerle kullanılabileceği). Uygulama tarafında imza sertifikasının hash değeri (SHA-1 parmak izi) kullanılarak ek bir güvenlik katmanı oluşur.
  - Debug ve release olmak üzere iki tür sertifika vardır. Biri diğerinin yerine kullanılamaz; markete çıkacak uygulama için release sertifikası gerekir.
- Haritayı uygulamaya ekleme: XML layout ve Activity kodu
  - Layout'ta `com.google.android.gms.maps.SupportMapFragment` sınıfından, `@+id/map` kimlikli bir fragment tanımlanır (ekrandan, 00:40:00).
  - Activity `OnMapReadyCallback` arayüzünü uygular. `onCreate` içinde `findFragmentById(R.id.map)` ile fragment bulunur ve `getMapAsync(this)` çağrılır. Harita hazır olunca `onMapReady(GoogleMap)` çağrılır; marker ekleme ve kamerayı taşıma burada yapılır.
  - Gerekli sınıflar tek tek import edilir (`CameraUpdateFactory`, `GoogleMap`, `OnMapReadyCallback`, `SupportMapFragment`, `LatLng`, `MarkerOptions`); yıldızlı import kullanılmaz.
- Statik ve dinamik harita fragment'ı
  - Statik: fragment layout'ta tanımlanır, kodda yalnız `findFragmentById` ile ilişkilendirilir.
  - Dinamik: `MapFragment.newInstance()` ile oluşturulur, `FragmentTransaction` ile `add` edilip `commit` edilir (ekrandan, 00:45:00).
- `GoogleMap` sınıfı ve harita türleri
  - Harita nesnesiyle çalışırken temel sınıf `GoogleMap`'tir. Arayüzde harita `MapFragment` ya da `MapView` ile temsil edilir (ekrandan, 00:50:00).
  - Görevleri: Google Maps servisine bağlanmak, harita karolarını (tile) indirmek, karoları ekranda göstermek, pan ve zoom kontrollerini göstermek, pan/zoom hareketlerine (gesture) yanıt vermek.
  - Karo yapısı sayesinde yalnız gereken bölge ve gereken ayrıntı indirilir; bu veri ve zaman tasarrufu sağlar.
  - Harita türleri: `none`, `normal`, `hybrid`, `satellite`, `terrain` (ekrandan, 01:10:00). Uydu görüntüsü daha çok veri indirir; topografik (terrain) harita yükseltileri renklendirir.
- Bina içi haritalar ve trafik katmanı
  - `setIndoorEnabled(false)` ile bina içi harita kapatılır; varsayılan olarak açıktır. Kat seçici `getUiSettings().setIndoorLevelPickerEnabled(false)` ile kapatılır. `OnIndoorStateChangeListener` ve `getFocusedBuilding()` ile odaklanan bina ve aktif kat izlenebilir (ekrandan, 00:55:00).
  - Trafik bilgisi Google'ın sunduğu bir katmandır; geliştirici renklendirmesine ya da içeriğine müdahale edemez.
- Haritanın başlangıç durumu (initial state)
  - Kameranın hedefi, zoom seviyesi, açısı ve kullanıcının hangi hareketleri yapabileceği baştan ayarlanmalıdır.
  - XML öznitelikleri: `mapType`, `cameraTargetLat`, `cameraTargetLng`, `cameraZoom`, `cameraBearing`, `cameraTilt`, `uiZoomControls`, `uiCompass`, `uiZoomGestures`, `uiScrollGestures`, `uiRotateGestures`, `uiTiltGestures`, `zOrderOnTop`, `useViewLifecycle`, `liteMode` (ekrandan, 01:10:00).
  - Programla ayarlama: `GoogleMapOptions` nesnesi oluşturulur; `MapFragment.newInstance(options)` ya da `new MapView(context, options)` ile kullanılır.
- Lite mode
  - Harita bir bitmap görüntüsü olarak sunulur, API'nin yalnız bir alt kümesi desteklenir; kaynak tüketimini azaltır. Varsayılanı `false`'tur.
  - Lite mode'da bina içi haritalar, trafik katmanı, ground overlay, tile overlay, gesture'lar ve Street View yoktur.
- Marker'lar
  - Marker'lar `onMapReady` içinde eklenir; harita üzerindeki ilgi noktalarını (POI) temsil eder.
  - Örnek: `OnMarkerClickListener` ve `OnMapReadyCallback` uygulayan bir Activity'de Perth, Sydney ve Brisbane için üç marker eklenir; her tıklamada tıklama sayısı Toast ile gösterilir (ekrandan, 01:15:00).
  - Sürüklenebilir (draggable) marker: kullanıcının bir noktaya not düşmesi için yararlıdır; standart POI'lerde genelde `false` kalır.
  - Özelleştirme: varsayılan marker rengini değiştirme (`HUE_AZURE`), saydamlık (`alpha(0.7f)`), `title`, `snippet` ve drawable'dan ikon (`fromResource`) (ekrandan, 01:20:00).
  - Marker'da izlenen üç temel kullanıcı aksiyonu: tıklama, sürükleme ve bilgi penceresine (info window) tıklama. Bilgi penceresi `showInfoWindow()` / `hideInfoWindow()` ile gösterilir ya da gizlenir; özel tasarımlı pencereler yapılabilir.
- Harita üzerinde şekiller
  - Polyline (bağlı doğru parçaları), Polygon (kapalı şekil), Circle (merkez ve yarıçap).
  - Polyline'a `StyleSpan` ile renkli parçalar ya da `StrokeStyle.gradientBuilder` ile renk geçişi verilebilir (ekrandan, 01:25:00).
  - Circle için merkez, yarıçap, çizgi kalınlığı ve rengi, dolgu ve tıklanabilirlik ayarlanır; tıklama `setOnCircleClickListener` ile izlenir.
  - A noktasından B noktasına rota, Google Maps tarafından alınan yol bilgisiyle çizdirilebilir.
- Kamera: tilt, bearing ve zoom
  - Tilt: dik eksenle yapılan açı; 0 iken harita tam tepeden görülür. Navigasyon uygulamaları yakın yeri büyük gösteren eğik bir perspektif (örneğin 45 derece) kullanır (ekrandan, 01:30:00).
  - Bearing: kuzeye göre yön açısı; varsayılanı 0 (kuzey yukarıda), kullanıcı hareketleriyle değişebilir.
  - Zoom seviyeleri: 1 dünya, 5 kıta, 10 şehir, 15 sokak, 20 bina. `setMinZoomPreference` ve `setMaxZoomPreference` ile sınır konur.
  - `CameraUpdate` ile kamera konumlanır. `moveCamera` ani geçiş yapar; `animateCamera` geçişi belirli bir sürede yumuşak yapar, ama render maliyeti vardır.
- My Location katmanı ve POI tıklamaları
  - `setMyLocationEnabled(true)` ile konum düğmesi ve mavi nokta gösterilir; `onMyLocationButtonClick` ve `onMyLocationClick` ile tıklamalar izlenir (ekrandan, 01:35:00).
  - Mavi noktanın çevresindeki daire büyüdükçe konumun kesinliği azalır.
  - `OnPoiClickListener` ile Google'ın haritadaki POI'lerine tıklanınca POI nesnesindeki bilgi uygulamada kullanılabilir.
- Koordinat sistemleri
  - Enlem/boylam (WGS84), dünya koordinatları, piksel koordinatları ve karo (tile) koordinatları (ekrandan, 01:40:00).
  - Dünya koordinatları Mercator izdüşümünün sol üst köşesinden ölçülür; x doğuya, y güneye artar. Harita boylamda -180..180, enlemde yaklaşık -85..85 aralığını kapsar.
  - $\text{pixelCoordinate} = \text{worldCoordinate} \times 2^{\text{zoomLevel}}$. Zoom 0'da dünya 256×256, zoom 1'de 512×512, zoom 2'de 1024×1024, zoom 3'te 2048×2048 pikseldir.
  - Chicago örneğinde zoom 3'te piksel koordinatı (525, 761), karo koordinatı (2, 2)'dir.
- Adres ve koordinat dönüşümü
  - Adresten enlem/boylam ya da enlem/boylamdan adres almak için Android'in `Geocoder` sınıfı kullanılır. Ücretli Geocoding API ayrı bir web servisidir.
- Kod örneği: konumu sürekli izleyip haritada gösteren uygulama
  - Activity `OnMapReadyCallback`, `GoogleApiClient.ConnectionCallbacks`, `OnConnectionFailedListener` ve `LocationListener` uygular.
  - `LocationRequest` ile `setInterval(1000)`, `setFastestInterval(1000)`, `setPriority(PRIORITY_BALANCED_POWER_ACCURACY)` ayarlanır; izin kontrolünden sonra `requestLocationUpdates` çağrılır (ekrandan, 01:55:00).
  - `onLocationChanged` içinde eski marker kaldırılır, yeni konumdan `LatLng` ve `MarkerOptions` oluşturulur, `Geocoder` ile adres alınıp marker başlığına yazılır, marker yeniden eklenir ve kamera zoom 11 ile konuma taşınır.

## Hocanın Özellikle Vurguladığı Kısımlar

- Haritalarla çalışırken SDK'ların kurulması ve API anahtarının manifeste eklenmesi şarttır
  - Bu eklemeler yapılmadan alınan hataların büyük kısmı bunlarla ilgilidir.
- Statik mi dinamik mi?
  - Aktivitenin odağı haritaysa (navigasyon gibi) fragment statik tanımlanmalıdır. Harita yalnız belirli koşullarda ve arada bir açılacaksa dinamik oluşturmak daha akıllıcadır.
- Başlangıç durumu kullanıcı deneyimi için önemlidir
  - Yanlış zoom ya da hedefle açılan haritada işaretli nokta görünmeyebilir ya da çok genel kalabilir. Kullanıcıya hangi hareketlerin açık olacağına geliştirici karar verir.
- Zoom seviyesi hem ayrıntıyı hem indirilen veri miktarını belirler
  - Karo yapısı sayesinde yalnız bakılan bölgenin ayrıntısı indirilir; gereksiz veri telefona indirilmez.
- Marker'larda bilgi varsayılan olarak gösterilmez
  - Ekran küçük olduğu için bilginin üzerine gelince ya da tıklayınca çıkması daha etkilidir; bu yüzden marker olayları izlenir.
- Lite mode kaynak tasarrufu sağlar
  - Kullanıcının ihtiyaç duymayacağı özellikler çıkarılır ve yük azalır.

## Kısa Tekrar Notları

- Gerekenler: Google Play Services SDK, Maps SDK, API anahtarı (manifestte `application` içinde metadata), Gradle eklenti ayarları.
- API anahtarı kısıtları: Application Restriction ve API Restriction. Debug ve release sertifikası ayrıdır.
- `SupportMapFragment` + `getMapAsync(this)` + `onMapReady(GoogleMap)`.
- Statik fragment: layout + `findFragmentById`. Dinamik: `MapFragment.newInstance()` + `FragmentTransaction.add(...).commit()`.
- `MapFragment` fragment olarak, `MapView` view olarak haritayı temsil eder; genelde fragment tercih edilir.
- Harita türleri: none, normal, hybrid, satellite, terrain.
- Bina içi: `setIndoorEnabled`, `setIndoorLevelPickerEnabled`. Trafik bir katmandır.
- Başlangıç ayarı: XML öznitelikleri ya da `GoogleMapOptions`.
- Marker: position, title, snippet, icon, alpha, draggable; olaylar: click, drag, info window click.
- Şekiller: Polyline, Polygon, Circle.
- Kamera: tilt (0 = tepeden), bearing (0 = kuzey), zoom (1 dünya, 5 kıta, 10 şehir, 15 sokak, 20 bina).
- `moveCamera` ani, `animateCamera` yumuşak geçiş.
- `pixelCoordinate = worldCoordinate × 2^zoom`; zoom 0'da 256×256.
- Adres ↔ koordinat: `Geocoder`.

## Detaylı Açıklamalar

- Haritayı uygulamaya eklemenin temel akışı şöyledir. Layout'ta `SupportMapFragment` tipinde bir fragment yer alır. Activity bu fragment'ı `getSupportFragmentManager().findFragmentById(R.id.map)` ile bulur ve `getMapAsync(this)` çağırır. Harita hazır olunca sistem `onMapReady` metodunu bir `GoogleMap` nesnesiyle çağırır. Slayttaki örnekte Sydney için `new LatLng(-34, 151)` noktasına "Marker in Sydney" başlıklı marker eklenir ve kamera `CameraUpdateFactory.newLatLng(sydney)` ile oraya taşınır (ekrandan, 00:40:00).
- Tablet gibi geniş ekranlarda ekran iki fragment'a bölünebilir: birinde kullanıcı bilgileri, diğerinde harita. Telefonlarda genelde tüm ekran haritaya verilir.
- `GoogleMap` sınıfı hem veri alışverişini (servise bağlanma, karo indirme) hem de görüntüleme ve hareketleri (zoom in/out, eğme, döndürme) yönetir. Uygulama ilk açıldığında tüm dünyanın ayrıntısı indirilmez; kullanıcı yakınlaştıkça yalnız o bölgenin ayrıntılı karoları gelir.
- Marker örneğinde Perth (-31.952854, 115.857342), Sydney (-33.87365, 151.20689) ve Brisbane (-27.47093, 153.0235) için `static final LatLng` sabitleri tanımlanır (ekrandan, 01:15:00). Hoca bu yapının ev arkadaşı arayan kişinin rumuzu ya da özel olmayan birkaç bilgisiyle de kullanılabileceğini söyledi.
- Customize Marker slaytında Melbourne (-37.813, 144.962) için üç kullanım gösterildi: `defaultMarker(HUE_AZURE)` ile renk değiştirme, `alpha(0.7f)` ile saydamlık, `title("Melbourne")`, `snippet("Population: 4,137,400")` ve `fromResource(R.drawable.arrow)` ile özel ikon (ekrandan, 01:20:00).
- Polyline örneğinde (47.6677146, -122.3470447) ile (47.6442757, -122.2814693) arasındaki çizgiye önce kırmızı ve yeşil `StyleSpan`'lar, sonra kırmızıdan sarıya gradyan verilir (ekrandan, 01:25:00). Trafik uygulamalarındaki renkli yollar ve uçuş rotası çizimleri bu mantıkla yapılır.
- Koordinat örneğinde Chicago için zoom 3'te dünya 2048×2048 piksellik bir alana yayılır; nokta 525. piksel sütunu ve 761. piksel satırına, (2, 2) karosuna düşer. Bu değerler python ile Mercator formülünden doğrulandı.
  - Ders sonrası not: hoca (525, 761) değerini "525. satır, 761. sütun" diye okudu. Dünya koordinatlarında x sütunu, y satırı gösterdiği için doğrusu 525. sütun, 761. satırdır.
  <!-- BELİRSİZ: Hoca enlemi "41.80" diye okudu; örneğin slaytı karede görünmedi. Google belgelerindeki örnek büyük olasılıkla 41.85, -87.65'tir; iki enlem de aynı piksel ve karo değerini verir. -->
- Konum izleme örneğinde `onLocationChanged` çağrıldığında `getBestProvider(new Criteria(), true)` ile sağlayıcı seçilir, `getLastKnownLocation` ile son konum alınır, `Geocoder` ile enlem/boylamdan adres bilgisi (eyalet, ülke vb.) çıkarılıp marker başlığına yazılır. Böylece marker'ın üzerinde sayılar yerine okunabilir bir adres görünür (ekrandan, 01:55:00).

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
