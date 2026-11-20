# Ders 15 Genişletilmiş Notu: Haritalar: Google Maps SDK, Marker'lar, Şekiller ve Kamera

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Haritalarla Çalışmaya Hazırlık: SDK'lar ve API Anahtarı
- 2. Haritayı Uygulamaya Eklemek
- 3. GoogleMap Sınıfı ve Harita Türleri
- 4. Bina İçi Haritalar ve Trafik Katmanı
- 5. Haritanın Başlangıç Durumu
- 6. Marker'lar
- 7. Harita Üzerinde Şekiller
- 8. Kamera: Tilt, Bearing ve Zoom
- 9. My Location Katmanı, POI Tıklamaları ve Lite Mode
- 10. Koordinat Sistemleri
- 11. Adres ve Koordinat Dönüşümü: Geocoder
- 12. Kod Örneği: Konumu Sürekli İzleyen Harita
- Örnek Sorular
- Dersin Toparlaması

## 1. Haritalarla Çalışmaya Hazırlık: SDK'lar ve API Anahtarı

Bir önceki derste konum servisleri konuşulmuş ve alınan konum bilgisi bir örnekte harita üzerinde gösterilmişti. Bu derste harita nesnelerinin kendisi ve yetenekleri ele alındı. Hoca iki API üzerinden ilerleneceğini söyledi: `GoogleMap` ve `MapFragment`.

### 1.1 Gereken SDK'lar

Haritalarla çalışan bir uygulama için Android SDK yetmez. Ek olarak Google Play Services SDK ve Maps SDK kurulmalıdır. Android Studio'da yeni ekran oluştururken Google Maps Activity seçilebilir. Sonra üretilen API anahtarı manifest dosyasında olması gereken yere eklenerek kurulum tamamlanır.

### 1.2 API anahtarı neden var?

Hoca anahtar almak için platformun kredi kartı bilgisi isteyebildiğini, ama belirli bir kullanım kredisi karşılığında ücret almadan anahtar ürettiğini söyleyip bunun anlamını sordu.

**Soru:** API anahtarının anlamı nedir? **Cevap (bir öğrenci):** Bir siteye girişte verilen token gibi bir doğrulama mekanizmasıdır. İstekler bizim üzerimizden yürür; ücretsiz kullanımda belirli sınırlar, ücretli kullanımda işlem maliyeti vardır.

Hoca cevabı şöyle genişletti: Herkes anahtarsız ve sınırsız harita sorgusu yapabilseydi platforma gelen istek sayısı yönetilemezdi. Anahtar bu yükü kontrol altında tutmak içindir.

Anahtar alma adımları slaytta şöyleydi (ekrandan, 00:35:00):

1. Google Cloud Platform Console'a gidilir.
2. Proje açılır listesinden API anahtarı eklenecek proje seçilir ya da oluşturulur.
3. Menüden APIs & Services > Credentials seçilir.
4. Credentials sayfasında Create credentials > API key tıklanır; açılan pencerede yeni anahtar görünür.
5. Close tıklanır. Anahtar Credentials sayfasında API keys altında listelenir. Üretimde kullanmadan önce anahtarın kısıtlanması hatırlatılır.

### 1.3 Debug ve release anahtarları, manifest ve Gradle

İki tür anahtar/sertifika vardır: debug ve release. Debug anahtarı çok kritik değildir, ama debug anahtarı release için kullanılamaz. Alınan anahtar, manifest dosyasında `application` etiketinin içine metadata olarak eklenir. Ayrıca Build Gradle'da çeşitli eklenti (plugin) ayarları yapılmalıdır; harita kütüphanelerine güvenli erişim bu eklentilerle sağlanır. Hoca bu eklemeler yapılmadan alınacak hataların büyük olasılıkla bunlarla ilgili olacağını söyledi.

### 1.4 Anahtar kısıtları ve sertifika

Anahtar ayarlarında iki başlık vardır:

- **Application Restriction:** anahtarın hangi kaynaktan gelen isteklerle kullanılabileceğini sınırlar. Bir anahtar üzerinden çok sayıda istek geldiğinde hizmet belirli bir noktadan sonra engellenir; bu kötü niyetli kullanıma karşı bir önlemdir.
- **API Restriction:** anahtarın hangi API ile kullanılacağını sınırlar. Her API'ye gelen istek sayısının bir sınırı vardır; sınır aşılınca kullanım mümkün olmaz.

Uygulama tarafında imza sertifikasının hashlenmiş bir değeri kullanılır. Bu da ek bir güvenlik seviyesi oluşturarak anahtarın açık kullanımını engeller. Slayt listesinde bu konunun "SHA-1 Fingerprint" başlıklı bir slaytı vardı (ekrandan, 00:35:00).
<!-- BELİRSİZ: Altyazıda 00:37:46'da "RAS diyoruz" geçiyor; bağlamdan büyük olasılıkla SHA-1 parmak izinden söz ediliyor. -->

Sertifika iki yoldan alınır. Birincisi, Android Studio'da geliştirilen uygulamanın imzalanmasıyla oluşan (debug) sertifikadır. İkincisi, uygulama markete çıkarken yapılan imzalama içindir ve release sertifikası gerekir. Her biri için ayrı sertifika üretilir, biri diğerinin yerine kullanılamaz.

## 2. Haritayı Uygulamaya Eklemek

### 2.1 XML layout ve Activity kodu

Slayttaki layout'ta bir fragment tanımlanır (ekrandan, 00:40:00):

```xml
<fragment xmlns:android="http://schemas.android.com/apk/res/android"
    xmlns:tools="http://schemas.android.com/tools"
    android:layout_width="match_parent"
    android:layout_height="match_parent"
    android:id="@+id/map"
    tools:context=".MapsActivity"
    android:name="com.google.android.gms.maps.SupportMapFragment" />
```

Fragment'a `map` kimliği verilir ve aktivitenin layout'una yerleştirilir. Böylece harita işlemlerinin bu fragment üzerinde gerçekleşeceği tanımlanmış olur. Activity tarafı şöyledir (ekrandan, 00:40:00):

```java
import android.os.Bundle;
import android.support.v4.app.FragmentActivity;
import com.google.android.gms.maps.CameraUpdateFactory;
import com.google.android.gms.maps.GoogleMap;
import com.google.android.gms.maps.OnMapReadyCallback;
import com.google.android.gms.maps.SupportMapFragment;
import com.google.android.gms.maps.model.LatLng;
import com.google.android.gms.maps.model.MarkerOptions;

public class MapsActivity extends FragmentActivity implements OnMapReadyCallback {

    private GoogleMap mMap;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_maps);
        SupportMapFragment mapFragment = (SupportMapFragment) getSupportFragmentManager()
                .findFragmentById(R.id.map);
        mapFragment.getMapAsync(this);
    }

    @Override
    public void onMapReady(GoogleMap googleMap) {
        mMap = googleMap;

        // Add a marker in Sydney, Australia, and move the camera.
        LatLng sydney = new LatLng(-34, 151);
        mMap.addMarker(new MarkerOptions().position(sydney).title("Marker in Sydney"));
        mMap.moveCamera(CameraUpdateFactory.newLatLng(sydney));
    }
}
```

Hoca akışı şöyle anlattı. Layout'taki fragment ile koddaki `SupportMapFragment` ilişkilendirilir; bu daha önce butonlar, TextView'lar ve EditText'ler için yapılan bağlamanın aynısıdır. Bir aktivitede birden fazla fragment olabilir. Örneğin dönem projesinde ekran ikiye bölünüp bir fragment'ta kullanıcıdan alınan bilgiler, diğerinde harita gösterilebilir. Genelde tüm ekran kullanılır, ama tablette ekranı iki parçaya bölmek ekranı daha verimli kullanır.

Aktivite `OnMapReadyCallback` arayüzünü uygular; harita üzerindeki işlemler bu sayede kontrol edilir. Arayüzün `onMapReady` metoduna bir `GoogleMap` nesnesi geçirilir. Son üç satırda önce marker'ın konacağı konum (`LatLng`) oluşturulur, sonra marker tanımlanıp konum `position` metoduna verilir, `title` ile isim verilir. Son olarak kamera o noktaya taşınır. Kameranın belirli bir zoom seviyesiyle doğru noktaya ortalanması önemlidir; aksi halde harita açıldığında ülke ölçeğinde görünebilir. Türkiye'ye odaklanılacaksa Türkiye ölçeğinde, belirli bir şehir ve zoom seçildiyse o şehre özgü görünür.

Kullanılan sınıflar (`CameraUpdateFactory`, `GoogleMap`, `OnMapReadyCallback`, `SupportMapFragment`, `LatLng`, `MarkerOptions`) ilgili Google paketlerinden tek tek import edilir. Hoca yıldızlı import kullanılmadığını, hangisine ihtiyaç varsa yalnız onun yazıldığını söyledi.

> **Ek bilgi (derste anlatılmadı):** Slayttaki `android.support.v4.app.FragmentActivity` eski Support Library paketidir. Güncel projelerde aynı sınıf AndroidX altında `androidx.fragment.app.FragmentActivity` olarak bulunur.

### 2.2 Statik ve dinamik ekleme

"Add a Map to an Android App" slaytında iki senaryo yan yana gösterildi (ekrandan, 00:45:00). Sol tarafta haritanın statik eklenmesi için layout vardır:

```xml
<?xml version="1.0" encoding="utf-8"?>
<fragment xmlns:android="http://schemas.android.com/apk/res/android"
    android:name="com.google.android.gms.maps.MapFragment"
    android:id="@+id/map"
    android:layout_width="match_parent"
    android:layout_height="match_parent"/>
```

Sağ tarafta fragment dinamik oluşturulup aktiviteye eklenir:

```java
mMapFragment = MapFragment.newInstance();
FragmentTransaction fragmentTransaction =
        getFragmentManager().beginTransaction();
fragmentTransaction.add(R.id.my_container, mMapFragment);
fragmentTransaction.commit();
```

Statik eklemede aşağıdaki kodla yalnız layout'taki fragment'la ilişki kurulur:

```java
public class MainActivity extends FragmentActivity
    implements OnMapReadyCallback {
    ...
}

MapFragment mapFragment = (MapFragment) getFragmentManager()
    .findFragmentById(R.id.map);
mapFragment.getMapAsync(this);

@Override
public void onMapReady(GoogleMap map) {
    map.addMarker(new MarkerOptions()
        .position(new LatLng(0, 0))
        .title("Marker"));
}
```

Hoca hangi durumda statik, hangi durumda dinamik eklemenin tercih edileceğini sordu (aşağıda Örnek Sorular). Varılan sonuç şudur: Aktivitenin odağı haritaysa ve o aktivitede tamamen harita üzerinde iş yapılacaksa fragment'ı statik tanımlamak daha akıllıcadır. Harita yalnız belirli koşullarda açılacaksa, ağırlıklı bir kullanım değilse ve her an açma ihtiyacı yoksa fragment'ı dinamik oluşturup haritayı onun üzerinde kullanmak daha akıllıcadır.

## 3. GoogleMap Sınıfı ve Harita Türleri

### 3.1 GoogleMap sınıfı

Map nesnesi Maps SDK üzerinden hizmet alınan bir nesnedir ve üzerinde çok farklı işler yapılabilir. Hoca zaman içindeki değişimi anlattı: Uygulamaların çoğu başta yalnız konumu gösterirken, zamanla POI (Point of Interest) denen benzinlik, okul, alışveriş merkezi gibi ikonlar eklendi. Bunlar pazarlama amacıyla ya da insanları yönlendirmek için kullanılır. İkonların hepsi tıklanabilir değildir. Bazıları yalnız bilgi amaçlı durur, bazıları tıklanınca ek bilgi verir, bazılarıyla bambaşka bir iş yapılabilir. Dersin geri kalanında harita yalnız konum bulmak için değil, çok daha etkin kullanılacak şekilde ele alındı.

Slayttaki tanım (ekrandan, 00:50:00): Harita nesnesiyle çalışırken temel sınıf `GoogleMap`'tir. `GoogleMap` uygulama içindeki harita nesnesini modeller. Arayüzde harita ya bir `MapFragment` ya da bir `MapView` nesnesiyle temsil edilir. `GoogleMap` şu işleri yapar:

- Google Maps servisine bağlanmak.
- Harita karolarını (tile) indirmek.
- Karoları cihaz ekranında göstermek.
- Pan ve zoom gibi çeşitli kontrolleri göstermek.
- Pan ve zoom hareketlerine haritayı kaydırarak ve yakınlaştırıp uzaklaştırarak yanıt vermek.

Karo yapısının önemi şudur: Uygulama ilk etapta tüm dünya haritasının ayrıntısını indirmez. Ayrıntıya ancak yakınlaşıldıkça girilir; ayrıca belirli bir bölgenin dışına zoom out ile çıkılmaması da sağlanabilir. İhtiyaç duyulmayan ayrıntıyı ya da dünyanın başka bir yerinin harita bilgisini kullanıcının telefonuna indirmek hem gereksiz veri hem de zaman kaybıdır. Bilgi alışverişinin yönetimi bu sınıfla yapılırken, haritanın ekranda gösterilmesi, zoom in/out ve navigasyon uygulamalarında görülen tepeden bakış açısının yatay bakışa dönmesi gibi hareketler (gesture) de aynı sınıf üzerinden yönetilir.

### 3.2 Harita türleri

`GoogleMap` üzerinde ilk yapılan tanımlardan biri haritanın türüdür. Bu önemlidir, çünkü haritanın yalnız yolları ve insanların aktif kullanacağı özellikleri mi göstereceği, uydu görüntüsü mü paylaşacağı, yoksa topografik bir veri mi sunacağı uygulamanın kullanıcıya hangi bilgiyi sağlamaya çalıştığına bağlıdır. Genelde normal modda çalışılır, ama bazı uygulamalar tercihe bağlı ya da kendi seçimleriyle farklı görünümler sunar.

- Topografik harita, yükseltileri renklendirme yoluyla düz ve yüksek yerleri birbirinden ayıran coğrafi bir haritadır.
- Uydu görüntüsünde yol ve ayrıntı bilgisi yoktur; ama yerleşim yerleri ya da bir deprem sonrasında yıkılan binalar daha net görülebilir.

Slaytta farklı türlere örnek görüntüler vardı: ortada bir uydu görüntüsü, sağ ve solda (sağdaki daha ayrıntılı) bir bölgedeki yol alternatiflerini gösteren haritalar. Uydu görüntüsüne geçildiğinde daha çok ayrıntı akar ve telefona daha fazla veri indirilir. XML öznitelikleri slaytına göre geçerli tür değerleri `none`, `normal`, `hybrid`, `satellite` ve `terrain`'dir (ekrandan, 01:10:00).

## 4. Bina İçi Haritalar ve Trafik Katmanı

### 4.1 Indoor maps

Harita deyince hep dış mekan konuşulur, ama Google yıllardır büyük binaların iç yapısına dair bilgileri de paylaşmaktadır. Örneğin bir alışveriş merkezinde hangi markaların ve restoranların olduğu görülebilir. Slayttaki maddeler (ekrandan, 00:55:00):

- Bina içi haritalar `GoogleMap.setIndoorEnabled(false)` ile kapatılır. Varsayılan olarak açıktır. Bina içi harita aynı anda yalnız bir haritada gösterilir; varsayılan olarak bu, uygulamaya eklenen ilk haritadır. Başka bir haritada göstermek için ilk haritada kapatılıp ikinci haritada `setIndoorEnabled(true)` çağrılır.
- Varsayılan kat seçiciyi (floor picker) kapatmak için `GoogleMap.getUiSettings().setIndoorLevelPickerEnabled(false)` çağrılır.
- `GoogleMap` üzerindeki `OnIndoorStateChangeListener` arayüzü, yeni bir bina odağa geldiğinde ya da binada yeni bir kat etkinleştiğinde çağrılacak bir dinleyici kurmayı sağlar.
- `GoogleMap.getFocusedBuilding()` o an odaktaki binayı verir. Aktif kat `IndoorBuilding.getActiveLevelIndex()` ile bulunur; ayrıntılar `IndoorBuilding` ve `IndoorLevel` nesnelerindedir.

Hoca bunun da ek bilgi demek olduğunu, o bölgedeki bilginin daha ayrıntılı indirilmesine yol açtığını vurguladı. Bu ayrıntı istenmiyorsa (birçok uygulamada kullanılmaz) `setIndoorEnabled(false)` ile doğrudan kapatılabilir.

### 4.2 Trafik katmanı

Trafiğin son durumu bilgisi alınıp kullanıcılarla paylaşılabilir. Bu Google'ın servis olarak sunduğu bir hizmettir ve haritaya yalnız bir katman (layer) olarak aktarılır. Geliştiricinin bu katmanın renklendirmesine ya da verisine müdahale etme şansı yoktur.

## 5. Haritanın Başlangıç Durumu

### 5.1 Neden önemli?

Harita ilk açıldığında nereyi, hangi zoom seviyesinde ve hangi açıyla göstereceği çok önemlidir. Bazen bir nokta işaretlenir ama harita öyle açılır ki o nokta görünen alanda yoktur. Ya da çözünürlük o kadar düşüktür ki nokta çok genel görünür ve işe yaramaz. Bu yüzden kameranın konumu, odak noktası, bakış açısı ve zoom seviyesi baştan ayarlanmalıdır.

Hoca ayrıca kullanıcıya bunları değiştirme hakkının verilip verilmediğinin ya da ne kadar sınırlandığının da önemli olduğunu söyledi. Buna geliştirici karar verir. Belirli bir zoom seviyesinin üstüne ya da altına izin verilmiyorsa kullanıcı onu göremez; harita yalnız belirli bir konumu göstermek için açıldıysa kullanıcı fazla bir şey yapamaz. Hareketleri (gesture) kullanıcıya açmak ya da kapamak tamamen geliştiricinin kontrolündedir.

### 5.2 XML öznitelikleriyle

Başlangıç durumu iki yolla ayarlanır. Birincisi XML öznitelikleridir; harita türü bile böyle ayarlanabilir. Slayttaki öznitelikler (ekrandan, 01:10:00):

- `mapType`: gösterilecek harita türü; geçerli değerler `none`, `normal`, `hybrid`, `satellite`, `terrain`.
- `cameraTargetLat`, `cameraTargetLng`, `cameraZoom`, `cameraBearing`, `cameraTilt`: başlangıç kamera konumu.
- `uiZoomControls`, `uiCompass`: zoom kontrollerinin ve pusulanın haritada görünüp görünmeyeceği.
- `uiZoomGestures`, `uiScrollGestures`, `uiRotateGestures`, `uiTiltGestures`: hangi hareketlerin açık olacağı.
- `zOrderOnTop`: harita yüzeyinin penceresinin üstüne yerleştirilip yerleştirilmeyeceği; bu, haritanın üstünde görünebilecek diğer view'ların (zoom kontrolleri, konum düğmesi) hepsini örter.
- `useViewLifecycle`: yalnız `MapFragment` için geçerlidir; haritanın yaşam döngüsünün fragment'ın view'ına mı yoksa fragment'ın kendisine mi bağlanacağını belirler.
- `liteMode`: `true` değeri haritayı lite mode'a alır. Lite mode harita, tam API'nin işlevlerinin bir alt kümesini destekleyen bir bitmap görüntüsüdür. Varsayılan değer `false`'tur.

Hoca lite mode'da birçok API özelliğinin kapatıldığını ve bunun kaynak tüketimine önemli katkı sağlayacağını söyledi.

### 5.3 Kodla (GoogleMapOptions)

Slaytta zoom seviyesinden açılara kadar her şeyin layout'taki map fragment içinde ayarlandığı bir örnek gösterildi. Aynısı kodla dinamik olarak da yapılabilir. Hoca kural olarak şunu verdi: Ayarlar hiç değişmeyecekse fragment'a (layout'a) koymakta sakınca yoktur. Kullanıcı bunlarda değişiklik yapacaksa ya da seçimlere bağlı olarak kameranın bölgesi, zoom'u ya da açısı değişecekse, bu iş daha çok Java ya da Kotlin ile yapılır.

Kodla ayarlamada `GoogleMapOptions` nesnesi kullanılır. Slayttaki örnekte harita türü belirlenir, pusula ve döndürme gibi özellikler `false` verilerek kapatılır; haritayı döndürmek de bir aksiyon olduğu için kapatılabilir. Bu seçenekler `MapFragment` oluştururken `newInstance` metoduna geçirilir. `MapView` kullanılıyorsa bağlam (context) ve `GoogleMapOptions` kurucuya (constructor) verilir.
<!-- BELİRSİZ: "Configuring Programmatically" slaytının kodu karede görünmedi; seçeneklerin tam listesi ve değerleri alınamadı. -->

Burada hoca `MapView` ile `MapFragment` arasındaki farkı sordu (aşağıda Örnek Sorular). Kendi cevabı şuydu: `MapView` aktiviteyle ilişkilendirilir, `MapFragment` ise aktivitenin altındaki fragment'larla. İkisi de kullanılabilir; ihtiyaca göre seçilir, genelde fragment tercih edilir.

> **Ek bilgi (derste anlatılmadı):** `MapView` bir view'dır ve herhangi bir layout'a konabilir; ama kullanıldığı aktivite ya da fragment, kendi yaşam döngüsü metotlarını (`onCreate`, `onStart`, `onResume`, `onPause`, `onStop`, `onDestroy` vb.) `MapView`'un aynı adlı metotlarına elle iletmelidir. `MapFragment` bu iletimi kendisi yaptığı için genelde daha kolay bir seçenektir.

## 6. Marker'lar

### 6.1 Marker'ları eklemek ve tıklamaları izlemek

Marker'lar `onMapReady` metodunda eklenir ve tanımlanır. Haritada görülen POI'ler bunlardır; bir okulun konumu da bir kişinin konumu da olabilir. Harita üzerindeki ilişkiler bu marker'lar üzerinden kurulur. Hoca bu bölümdeki kodların parçalar halinde konuşulduğunu, tüm kod indirildiğinde bütünlüğün daha iyi görüleceğini söyledi.

"Associate data with a marker" slaytındaki örnek (ekrandan, 01:15:00):

```java
/**
 * A demo class that stores and retrieves data objects with each marker.
 */
public class MarkerDemoActivity extends FragmentActivity implements
        OnMarkerClickListener,
        OnMapReadyCallback {

    private static final LatLng PERTH = new LatLng(-31.952854, 115.857342);
    private static final LatLng SYDNEY = new LatLng(-33.87365, 151.20689);
    private static final LatLng BRISBANE = new LatLng(-27.47093, 153.0235);

    private Marker mPerth;
    private Marker mSydney;
    private Marker mBrisbane;

    private GoogleMap mMap;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.marker_demo);

        SupportMapFragment mapFragment =
                (SupportMapFragment) getSupportFragmentManager().findFragmentById(R.id.map);
        mapFragment.getMapAsync(this);
    }
```

Üç farklı konumun koordinatları sabit olarak oluşturulur ve bir `MapFragment` üzerinden haritaya yerleştirilir. Sınıf iki arayüz uygular: `OnMarkerClickListener` ve `OnMapReadyCallback`. Biri harita oluştuğunda, diğeri marker'lara tıklandığında devreye girer. `onMapReady` içinde marker'lar eklenir, konumları değişkenlerden verilir ve şehirlerin adları gösterilir. Marker'lara `setOnMarkerClickListener` ile dinleyici atanır. `onMarkerClick` metodunda bir tıklama sayacı tutulur ve her tıklamadan sonra marker'ın kaçıncı kez tıklandığı bir Toast mesajıyla gösterilir. Hoca burada çok farklı şeyler yapılabileceğini, genel kavramın `onMarkerClick` ve `OnMarkerClickListener` ile etkileşimin izlenmesi olduğunu söyledi.
<!-- BELİRSİZ: Slaytın devamındaki onMapReady ve onMarkerClick kodu karede görünmedi; açıklama altyazıdan yazıldı. -->

Hoca bunu dönem projesine bağladı: Marker'ın üzerine gelindiğinde ev arkadaşı arayan kişinin adı ya da rumuzu, belki birkaç ek özelliği gösterilebilir; ev aramayla ilgili özel olmayan önemli bir bilgi de oraya konabilir.

### 6.2 Sürüklenebilir marker'lar

Bazı marker'lar sürüklenebilir (draggable), yani sürükle-bırak mantığıyla taşınabilir. Bir yer işaretlenecekse marker'ın tıklanan noktaya eklenmesi, sonra sürüklenmesi sağlanabilir. Ama POI'lerin normalde sürüklenemeyen noktalar olması gerekir ki bilgi karmaşası olmasın. Bu yüzden standart bilgiler için draggable özelliği genelde `false`'tur. Bir noktaya not düşmek isteniyorsa sürüklenebilir olması yararlıdır. Hoca TripAdvisor benzeri bir örnek verdi: Gezilen yere bir marker sürüklenip not düşülür, marker kişinin özel alanında saklanır. Böylece sonradan geriye dönüp hangi noktaların işaretlendiğine ya da o şehre tekrar gidildiğinde nerelere gidilmek istendiğine bakılabilir.

### 6.3 Marker'ı özelleştirmek

Marker'ın türü, ikonun rengi değiştirilebilir, varsayılan marker kullanılabilir ya da özel ikon konabilir. "Customize Marker" slaytında üç örnek vardı (ekrandan, 01:20:00):

```java
final LatLng melbourneLocation = new LatLng(-37.813, 144.962);
Marker melbourne = map.addMarker(
    new MarkerOptions()
        .position(melbourneLocation)
        .icon(BitmapDescriptorFactory.defaultMarker(BitmapDescriptorFactory.HUE_AZURE)));
```

```java
final LatLng melbourneLocation = new LatLng(-37.813, 144.962);
Marker melbourne = map.addMarker(new MarkerOptions()
    .position(melbourneLocation)
    .alpha(0.7f));
```

```java
final LatLng melbourneLocation = new LatLng(-37.813, 144.962);
Marker melbourne = map.addMarker(
    new MarkerOptions()
        .position(melbourneLocation)
        .title("Melbourne")
        .snippet("Population: 4,137,400")
        .icon(BitmapDescriptorFactory.fromResource(R.drawable.arrow)));
```

İlk parçada varsayılan marker kullanılmış ama rengi değiştirilmiştir. İkincisinde marker'ın alfa (saydamlık) özelliği ayarlanmıştır. Üçüncüsünde varsayılan marker yerine drawable'dan seçilen bir ikon kullanılmıştır. Ayrıca üzerine gelindiğinde ya da tıklandığında bilgi çıkması sağlanabilir.

### 6.4 Marker olayları ve bilgi pencereleri

Özelleştirmeye, sürüklemeye ve tıklamaya ek olarak, açılan bilgi penceresine (info window) tıklama da izlenebilir. Bu üç temel kullanıcı aksiyonunu izlemek harita üzerinde çok daha etkin bir kullanım sağlar. Marker'lar genelde küçük noktalardır ve varsayılan olarak üzerlerinde çok yazı görünmesi istenmez. Ekran zaten küçüktür; her marker'ın varsayılan olarak bilgi gösterdiği düşünülürse bu akıllıca olmaz. Bu yüzden bilginin üzerine gelince ya da tıklayınca çıkması daha etkilidir ve bu iş marker olaylarıyla takip edilir.

"Custom Info Windows" slaytında üç pencere örneği vardı: marker'a tıklanınca açılan varsayılan bilgi penceresi, resim konmuş bir pencere ve çerçeve çizilmiş bir pencere. Bilgi pencerelerinin gösterilip gizlenmesi `showInfoWindow()` ve `hideInfoWindow()` ile sağlanır. Bir tarafta üzerine gidildiğinde çıkan varsayılan snippet penceresi, diğer tarafta doğrudan orada konumlanmış bir pencere görülür. Hoca bunların uygulamaya özel tasarımlar olduğunu ve dönem projesinde uygun olanın seçilebileceğini söyledi.

## 7. Harita Üzerinde Şekiller

### 7.1 Polyline, Polygon ve Circle

Haritalar üzerinde çizim de yapılabilir. Google Maps API ile ilgili şekiller üretilip haritaya yerleştirilir. Üç tür şekil vardır:

- **Polyline:** birbirine bağlı doğru parçalarından oluşan şekil ya da uzun bir eğri parçası. `PolylineOptions` ile oluşturulur.
- **Polygon:** bu şekillerin kapalı versiyonu; kare, dörtgen ya da üçgen olabilir.
- **Circle:** çember.

### 7.2 Polyline özelleştirme

Polyline'lar özelleştirilerek birçok trafik uygulamasında görülen renkli ve belirli tipteki yol parçaları haritaya oturtulabilir. Slayttaki haritada trafiğin yavaş aktığı yer kırmızıyla gösteriliyordu. Polyline'ın üzerine gelince bilgi çıkması da sağlanabilir. Renkler değiştirilebilir ve gradyanla bir renkten diğerine geçiş gösterilebilir. Slayttaki iki örnek (ekrandan, 01:25:00):

```java
Polyline line = map.addPolyline(new PolylineOptions()
        .add(new LatLng(47.6677146,-122.3470447), new LatLng(47.6442757,-122.2814693))
        .addSpan(new StyleSpan(Color.RED))
        .addSpan(new StyleSpan(Color.GREEN)));
```

```java
Polyline line = map.addPolyline(new PolylineOptions()
        .add(new LatLng(47.6677146,-122.3470447), new LatLng(47.6442757,-122.2814693))
        .addSpan(new StyleSpan(StrokeStyle.gradientBuilder(Color.RED, Color.YELLOW).build())));
```

Birincisinde çizginin parçaları kırmızı ve yeşil renk alır; ikincisinde çizgi kırmızıdan sarıya geçen bir gradyanla çizilir. Hoca haritalarda görülen "cafcaflı" şekillerin böyle oluştuğunu söyledi.

### 7.3 Circle

`CircleOptions` ile çemberin merkezi, yarıçapı, çizgisinin kalınlığı ve rengi, içinin doldurulup doldurulmayacağı ve tıklanabilir olup olmayacağı ayarlanır. Tıklanma durumunda ne olacağı `setOnCircleClickListener` ile belirlenir. Hoca dönem projesinde çember üzerinden ilerlenebileceğini söyledi.

### 7.4 Rotalar

Slaytta Avustralya'da bir uçağın uçuşunu gösteren bir çizgi örneği vardı. Çizgilerin kalınlığı ve rengi istenildiği gibi belirlenebilir; Flightradar uygulamasındaki uçuş rotaları ya da uçakta yolculara çizilen rota aynı mantıkla yapılır. Çizgi elle çizilebileceği gibi, yollar konusunda Google Maps SDK'dan bilgi de alınabilir. Bir noktadan diğerine gitmek için rotalama gerekir ve geliştiricide o noktaların bilgisi olmayabilir; Google Maps üzerinden A noktasından B noktasına gidilecek yol kolayca çizdirilip haritada gösterilebilir.

## 8. Kamera: Tilt, Bearing ve Zoom

"Camera and View" slaytındaki çizimde harita düzlemi, kamera, hedef nokta (`target LatLng`), görünen alan (viewport), tilt açısı, nadir noktası (0° tilt) ve pusula yönleri (kuzey 0°, doğu 90°, güney 180°, batı 270° bearing) gösteriliyordu (ekrandan, 01:30:00).

### 8.1 Tilt (viewing angle)

Tilt, kameranın dikeyle yaptığı açıdır. Haritalarda başlangıçta genelde 0'dır; bu, en tepeden aşağıya dik bakılması demektir. Birçok uygulama tilt'i sıfırla başlatır. Navigasyon uygulamalarında ise A noktasından B noktasına gidilirken yolu daha rahat takip etmek için bir eğim verilir. Slayttaki örnekte 0 dereceden 45 dereceye geçilir; kameraya yakın kısımlar daha büyük görünecek şekilde ileriye doğru bir perspektif oluşur. Bu gösterim özellikle navigasyon uygulamalarında tercih edilir.

### 8.2 Bearing

Referans alınan kuzey yönü bearing açısıdır. Harita başlangıçta genelde kuzey yukarıda olacak şekilde konumlanır; dünya dikdörtgen bir harita olarak aşağıdan yukarıya düşünülür. Bearing ağırlıklı olarak 0 olsa da, özellikle kullanıcının döndürme hareketleriyle sağa ya da sola dönerek değişebilir.

### 8.3 Zoom

Hoca zoom'un önceki konulardan daha kritik olduğunu söyledi, çünkü zoom seviyesi hem telefona ne kadar bilgi indirileceğini hem de kullanıcıya ne ayrıntıda bilgi gösterileceğini belirler. Seviyeler şöyledir:

| Zoom seviyesi | Gösterilen ayrıntı |
|---|---|
| 1 | Dünya |
| 5 | Kıta |
| 10 | Şehir |
| 15 | Sokak |
| 20 | Bina |

Sınırlar `GoogleMap` üzerinde `setMinZoomPreference` ve `setMaxZoomPreference` ile konur. Geliştiricinin bunu yapma hakkı vardır; ama kullanıcı daha yukarı ya da aşağı inmek istiyorsa bundan memnun olmayabilir, bu yüzden kullanıcının ihtiyaçları göz önünde tutulmalıdır.

### 8.4 CameraUpdate: moveCamera ve animateCamera

Ayarlar önemlidir, ama işi yapan sınıf `CameraUpdate`'tir. Onun üzerinden zoom in ve zoom out metotları çağrılarak kamera konumlanır ve seviyesi belirlenir. `moveCamera` ile `animateCamera` arasında bir fark vardır:

- `moveCamera`: kamera bir noktadan alınıp ani bir şekilde başka bir noktaya götürülür; yumuşak geçiş yoktur.
- `animateCamera`: geçiş belirli bir sürede gerçekleşir. Daha yumuşak ve şık bir görüntü verir, ama görsel bir render yapıldığı için bir maliyeti vardır.

## 9. My Location Katmanı, POI Tıklamaları ve Lite Mode

### 9.1 My Location katmanı

Kullanıcının kendi konumunu sürekli görmesi gereken bir uygulamada `setMyLocationEnabled` ile haritaya varsayılan bir konum düğmesi konur; tıklandığında konum güncellenir ve haritada gösterilir. Tıklanınca ek bir şey yapılması isteniyorsa Toast mesajı gibi bir işlem eklenebilir. Slayttaki kod (ekrandan, 01:35:00):

```java
public void onMapReady(GoogleMap map) {
  mMap = map;
  // TODO: Before enabling the My Location layer, you must request
  // location permission from the user. This sample does not include
  // a request for location permission.
  mMap.setMyLocationEnabled(true);
  mMap.setOnMyLocationButtonClickListener(this);
  mMap.setOnMyLocationClickListener(this);
}

@Override
public void onMyLocationClick(@NonNull Location location) {
  Toast.makeText(this, "Current location:\n" + location, Toast.LENGTH_LONG).show();
}

@Override
public boolean onMyLocationButtonClick() {
  Toast.makeText(this, "MyLocation button clicked", Toast.LENGTH_SHORT).show();
  // Return false so that we don't consume the event and the default behavior still occurs
  // (the camera animates to the user's current position).
  return false;
}
```

Koddaki yoruma göre My Location katmanı açılmadan önce kullanıcıdan konum izni istenmelidir; örnek bu isteği içermez. `onMyLocationButtonClick` `false` döndürdüğü için olay tüketilmez ve varsayılan davranış (kameranın kullanıcının konumuna animasyonla gitmesi) yine gerçekleşir.

Hoca önceki derste söylediğini hatırlattı: Haritadaki mavi noktanın çevresindeki daire ne kadar büyükse konumun kesinliği o kadar düşüktür; kişi dairenin herhangi bir yerinde olabilir. Daire ne kadar küçükse tahmin o kadar doğrudur.

### 9.2 POI tıklamaları

`GoogleMap` üzerinden `OnPoiClickListener` uygulanır. POI'lere tıklanınca aksiyon alınması isteniyorsa POI nesnesindeki bilgiler kullanılarak kullanıcı bilgilendirilir. Böylece `GoogleMap` nesnesiyle gelen ek bilgiler uygulama içinde de kullanılabilir; bölgedeki yerler için ayrıca bir çalışma yapmaya ya da Google Maps uygulamasına geçmeye gerek kalmaz.

### 9.3 Lite mode kısıtları

Slaytta lite mode'da neyin kullanılıp neyin kullanılamadığı listelenmişti. Harita stili ve marker'larla ilgili çeşitli kısıtlar vardır; konum, zoom, animasyon ve harita olayları gibi aksiyonlarda da kullanım kısıtları bulunur. Lite mode'da hiç kullanılamayanlar şunlardır: bina içi haritalar, trafik katmanı, ground overlay (haritanın üzerine başka bir bitmap giydirme yeteneği), tile overlay, hareketler (gesture) ve Street View. Hoca lite mode'un amacını şöyle özetledi: Kullanıcının ihtiyaç duymayacağı ek özellikler çıkarılır ve yük azalır.

## 10. Koordinat Sistemleri

Slayta göre Maps SDK for Android şu koordinat sistemlerini kullanır (ekrandan, 01:40:00):

- Dünyadaki bir noktayı tekil olarak gösteren enlem ve boylam değerleri (Google, World Geodetic System WGS84 standardını kullanır).
- Harita üzerindeki bir noktayı tekil olarak gösteren dünya koordinatları (world coordinates).
- Belirli bir zoom seviyesinde haritadaki belirli bir pikseli gösteren piksel koordinatları.
- Belirli bir zoom seviyesinde haritadaki belirli bir karoyu gösteren karo (tile) koordinatları.

### 10.1 Dünya koordinatları

Dünya koordinatları Mercator izdüşümünün başlangıç noktasından, yani haritanın 180 derece boylam ve yaklaşık 85 derece enlemdeki kuzeybatı köşesinden ölçülür. x doğuya (sağa), y güneye (aşağıya) doğru artar. Temel Mercator karosu 256×256 piksel olduğu için kullanılabilir dünya koordinat uzayı x için 0-256, y için 0-256'dır (ekrandan, 01:40:00).

Hoca bunu şöyle anlattı: Ekrandaki matrisin sol üst köşesinden sağa doğru bir x ekseni, aşağı doğru bir y ekseni çekilir; boylamda -180 ile 180, enlemde -85 ile 85 arasında konumlandırma yapılır. Normalde enlem -90 ile +90 arasında, yani 180 derecelik bir aralıktadır. Ama kutup bölgelerindeki hassasiyet nedeniyle 3 boyutlu dünya 2 boyuta indirgendiğinde -85 ile 85 aralığı sunulur. Alınan enlem ve boylam bu x-y eksenine dönüştürülerek haritada gösterilir.

### 10.2 Piksel koordinatları

Piksel koordinatı, belirli bir zoom seviyesindeki koordinatı tutar. Slayttaki formül (ekrandan, 01:40:00):

$$\text{pixelCoordinate} = \text{worldCoordinate} \times 2^{\text{zoomLevel}}$$

Zoom seviyesi 0 seçildiğinde $2^0 = 1$ elde edilir ve tüm dünya 256×256'lık bir alana yerleşir. Buradaki pikseller density-independent piksel olarak geçer ve telefonun piksel yoğunluğuna göre bölme yapılır. Bir seviye yukarı çıkınca alan 512×512, bir seviye daha çıkınca 1024×1024 olur. Böylece yakınlaşılan seviyedeki ayrıntılı bilgiye erişilir.

| Zoom | Çarpan $2^z$ | Dünyanın piksel boyutu |
|---|---|---|
| 0 | 1 | 256 × 256 |
| 1 | 2 | 512 × 512 |
| 2 | 4 | 1024 × 1024 |
| 3 | 8 | 2048 × 2048 |

### 10.3 Karo koordinatları

Dünya haritası çeşitli bölgelere (karolara) ayrılır ve Google Maps'in uygulamalara sağladığı ayrıntılı harita bilgisi bu karolarla aktarılır. Slayttaki 4×4 ızgarada karolar (0,0)'dan (3,3)'e kadar numaralanmıştı (ekrandan, 01:40:00). (0,0) karosuna bakılıyorsa geri kalan karolar indirilmez; böylece gereksiz bilginin indirilmesi engellenir. Google yakınlaştıkça o bölgenin ayrıntısını getirir; tüm dünya istenmediyse ve belirli bir konumdan başlandıysa yalnız oranın bilgisi aktarılır.

### 10.4 Chicago örneği

Hoca slayttaki örneği okudu: ABD'de Chicago, Illinois için bir nokta, zoom seviyesi 3 (oldukça ayrıntısız bir seviye). Dünya koordinatı noktanın x ve y eksenindeki konumunu verir. Piksel koordinatı, noktanın hangi satır ve sütunda olduğunu verir. Zoom 0'da 256×256, 1'de 512×512, 2'de 1024×1024, 3'te 2048×2048 piksel vardır. Piksel koordinatı (525, 761), karo koordinatı (2, 2)'dir.

Hesap adım adım (ara adımlar eklendi; python ile doğrulandı):

1. Verilen: enlem $\varphi \approx 41{,}85$, boylam $\lambda = -87{,}65$, zoom 3.
2. Dünya koordinatı x: $x = 256 \cdot (0{,}5 + \lambda/360) = 256 \cdot (0{,}5 - 0{,}24347) \approx 65{,}67$.
3. Dünya koordinatı y: $y = 256 \cdot \left(0{,}5 - \dfrac{\ln\frac{1+\sin\varphi}{1-\sin\varphi}}{4\pi}\right) \approx 95{,}17$.
4. Piksel koordinatı: $2^3 = 8$ ile çarpılır: $(65{,}67 \cdot 8,\ 95{,}17 \cdot 8) \approx (525{,}4,\ 761{,}4)$, tam kısım $(525, 761)$.
5. Karo koordinatı: piksel koordinatı 256'ya bölünür: $(525/256,\ 761/256) \approx (2{,}05,\ 2{,}97)$, tam kısım $(2, 2)$.

> **Ders sonrası not:** Hoca (525, 761) değerini "525. satır, 761. sütun" diye okudu. x ekseni doğuya (sütun), y ekseni güneye (satır) doğru arttığı için doğrusu 525. piksel sütunu ve 761. piksel satırıdır.

<!-- BELİRSİZ: Hoca enlemi "41.80, 87.65" diye okudu; örnek slaytı karede görünmedi. Google belgelerindeki Chicago örneği büyük olasılıkla 41.85, -87.65'tir (boylam batıda olduğu için eksi işaretlidir). 41.80 ile de aynı piksel ve karo değerleri çıkar. -->

Hoca bu ayrıntılı bilgilerin haritalarda kullanılması gerekebileceği için farkındalık yaratmak adına paylaşıldığını söyledi.

## 11. Adres ve Koordinat Dönüşümü: Geocoder

Kod örneğine geçmeden hoca unuttuğu bir konuyu sordu: Bir adres verip enlem ve boylam almak ya da tersine enlem ve boylam verip adres almak için hangi yapı kullanılır? Bir öğrenci "Geocoding API" cevabını verdi. Hoca önce bunu onayladı, sonra kontrol edip düzeltti: Geocoding API ücretli bir versiyondur; ihtiyaç duyulan dönüşümü Android tarafında sağlayan yapı `Geocoder`'dır. Dönüşüm her iki yönde yapılabilir. Benzer adlı başka API'ler de vardır.

> **Ek bilgi (derste anlatılmadı):** Adresten koordinata dönüşüme ileri geocoding, koordinattan adrese dönüşüme ters (reverse) geocoding denir. `Geocoder` sınıfında bunlar `getFromLocationName` ve `getFromLocation` metotlarıyla yapılır; sonuç `Address` nesnelerinden oluşan bir listedir.

## 12. Kod Örneği: Konumu Sürekli İzleyen Harita

Hoca Android Studio'da bir önceki dersteki örneğin bir adım ileri versiyonunu gösterdi. Bu örnek konum bilgisini sürekli alır ve haritadaki konumu sürekli günceller. Kişinin konumunu sürekli izlemek dönem projesinde yer almıyordu, ama böyle bir uygulamada neler olduğunu görmek için gösterildi. Hoca başka bir bilgisayarda olduğu için projeyi çalıştırmadı, kod üzerinden ilerledi; kodun diğer bilgisayarda çalıştığını söyledi.

### 12.1 Yapı

- Gereken sınıflar import edilir. Çoğu Android Studio'nun eksik oldukça otomatik eklediği varsayılan kütüphanelerdir; `LocationManager` ve `Geocoder` gibi ek ihtiyaç duyulanlar da vardır.
- Activity `OnMapReadyCallback`, `GoogleApiClient.ConnectionCallbacks`, `OnConnectionFailedListener` ve `LocationListener` arayüzlerini uygular.
- `Marker`, `LocationRequest`, `GoogleApiClient` gibi alanlar tanımlanır.
- `onCreate` içinde önceki derste tanımlanan fragment'ın aynısı `findFragmentById` ile bulunur ve `getMapAsync` çağrılır.

### 12.2 onMapReady

`GoogleMap` nesnesi gelince harita türü belirlenir. `UiSettings` üzerinden zoom kontrolleri ve zoom hareketleri açılır: birinde artı/eksi düğmeleriyle, diğerinde iki parmakla yakınlaştırılır. Sonra gerekli izinlerin alınıp alınmadığı kontrol edilir. `GoogleApiClient` oluşturulur ve `setMyLocationEnabled(true)` ile konum düğmesi açılır; tıklanınca konum gösterilir. `GoogleApiClient`'a bağlantı geri çağrıları ve bağlantı hatası dinleyicisi verilir, bağlantı kurulur.

### 12.3 Bağlantı kurulunca: konum isteği

Bağlantı sağlanınca bir `LocationRequest` nesnesi oluşturulur. Önceki derste görülen `setInterval` ve `setFastestInterval` ayarlanır, istenen doğruluk `setPriority` ile belirlenir. İzin kontrolünden sonra konum güncellemeleri istenir (ekrandan, 01:55:00):

```java
mLocationRequest.setInterval(1000);
mLocationRequest.setFastestInterval(1000);
mLocationRequest.setPriority(LocationRequest.PRIORITY_BALANCED_POWER_ACCURACY);

if (ContextCompat.checkSelfPermission(this,
        Manifest.permission.ACCESS_FINE_LOCATION)
        == PackageManager.PERMISSION_GRANTED) {
    LocationServices.FusedLocationApi.requestLocationUpdates(mGoogleApiClient,
            mLocationRequest, this);
}
```

### 12.4 onLocationChanged

Konum değiştiğinde `onLocationChanged` çağrılır ve haritayla ilgili işler burada başlar (ekrandan, 01:55:00):

```java
@Override
public void onLocationChanged(Location location) {
    mLastLocation = location;

    if (mCurrLocationMarker != null) {
        mCurrLocationMarker.remove();
    }
    //Showing Current Location Marker on Map
    LatLng latLng = new LatLng(location.getLatitude(), location.getLongitude());
    MarkerOptions markerOptions = new MarkerOptions();
    markerOptions.position(latLng);

    LocationManager locationManager = (LocationManager) getSystemService(Context.LOCATION_SERVICE);
    String provider = locationManager.getBestProvider(new Criteria(), true);
    if (ActivityCompat.checkSelfPermission(this,
            Manifest.permission.ACCESS_FINE_LOCATION) != PackageManager.PERMISSION_GRANTED &&
            ActivityCompat.checkSelfPermission(this, Manifest.permission.ACCESS_COARSE_LOCATION)
                    != PackageManager.PERMISSION_GRANTED) {
        return;
    }
    Location locations = locationManager.getLastKnownLocation(provider);
    List<String> providerList = locationManager.getAllProviders();
    if (null != locations && null != providerList && providerList.size() > 0) {
        double longitude = locations.getLongitude();
        double latitude = locations.getLatitude();
        Geocoder geocoder = new Geocoder(getApplicationContext(),
        // ... (devamı karede görünmüyor)
```

<!-- BELİRSİZ: onLocationChanged metodunun Geocoder satırından sonraki kısmı karede görünmedi; aşağıdaki akış altyazıdan yazıldı. -->

Hocanın anlattığı akış:

1. Null olmayan bir konum geldiyse mevcut marker kaldırılır, çünkü yeniden konumlandırılacaktır.
2. `Location` nesnesinden enlem ve boylam alınıp bir `LatLng` oluşturulur. `MarkerOptions` nesnesi yaratılır ve konum verilir. Hoca önceki örneklerde bu işin tek nesne üzerinde art arda nokta ile metot çağırarak yapıldığını, burada adım adım yapıldığını belirtti.
3. `LocationManager` ile konum servisine bağlanılır, izinler yine kontrol edilir.
4. En son bilinen konum alınır; konum sağlayan bütün sağlayıcıların listesi alındıktan sonra enlem ve boylam kaydedilir.
5. Enlem ve boylamdan `Geocoder` ile adres bilgisi alınır. Marker'ın üzerinde enlem/boylam gösterilseydi yalnız sayılar görülürdü; `Geocoder` ile eyalet (state), ülke (country) gibi bilgiler alınır ve `MarkerOptions`'ın başlığına (title) eklenir. Marker'ın üzerine gelince bu bilgiler telefonda görülür.
6. Marker ikonunun rengi değiştirilir.
7. Kaldırılan marker `addMarker` ile tanımlanan `MarkerOptions`'a göre yeniden eklenir.
8. Kamera konuma göre konumlandırılır ve zoom seviyesi 11 verilir; böylece bulunulan konuma orta düzeyde yakınlaşılır.
9. `GoogleApiClient` varsa konum güncellemeleri kaldırılır (remove location updates); böylece konum sorgusu boşu boşuna devam etmez.
10. İzin sonuçları için varsayılan kontroller yapılır ve izin verilmediyse ekranda bilgi gösterilir.

Hoca bu kodu çalıştırınca telefonda kişinin konumunun görüneceğini ve hareket ettikçe haritada güncelleneceğini söyledi.

> **Ek bilgi (derste anlatılmadı):** Örnekteki `GoogleApiClient` ve `LocationServices.FusedLocationApi` artık kullanımdan kaldırılmıştır (deprecated). Güncel Google Play Services sürümlerinde aynı iş `LocationServices.getFusedLocationProviderClient(context)` ile alınan `FusedLocationProviderClient` ve onun `requestLocationUpdates` metoduyla yapılır.

## Örnek Sorular

**Soru 1** (derste sözlü, 00:33:59): Harita API anahtarı almak için platform kredi kartı bilgisi isteyebiliyor ama ücret almadan, belirli bir kredi karşılığında anahtar üretiyor. Bu API anahtarının anlamı nedir?

> **Cevap (derste verildi):** Anahtar, bir siteye girişte verilen token gibi bir doğrulama mekanizmasıdır; istekler anahtar sahibinin üzerinden yürür. Ücretsiz kullanımda sınırlar, ücretli kullanımda işlem maliyeti vardır. Anahtar ve istek sınırı olmasaydı herkesin sınırsız harita sorgusu platformu yönetilemez hale getirirdi. Anahtar kullanımı Application Restriction ve API Restriction ile ayrıca sınırlandırılır.

**Soru 2** (derste sözlü, 00:44:49): Harita fragment'ı statik ya da dinamik eklenebilir. Hangi durumda statik, hangi durumda dinamik tercih edilir?

> **Cevap (derste verildi):** Harita ekranın sabit ve önemli bir parçasıysa (iş harita ya da navigasyonsa) statik tanımlamak daha mantıklıdır. Harita yalnız belirli koşullarda ya da arada bir açılacaksa, ağırlıklı bir kullanım değilse fragment'ı dinamik oluşturmak daha akıllıcadır.

**Soru 3** (derste sözlü, 01:12:37): `MapView` ile `MapFragment` arasındaki fark nedir?

> **Cevap (derste verildi):** `MapView` aktiviteyle ilişkilendirilir; `MapFragment` ise aktivitenin altındaki fragment'larla ilişkilendirilir ve aktivitenin fragment sayısına göre ondan bağımsız olabilir. İkisi de kullanılabilir; ihtiyaca göre seçilir, genelde fragment tercih edilir.

**Soru 4** (derste sözlü, 01:47:53): Bir adres verip enlem ve boylam almak ya da enlem ve boylam verip adres almak için hangi yapı kullanılır?

> **Cevap (derste verildi):** Android'in `Geocoder` sınıfı. Dönüşümü her iki yönde yapar. Hoca önce "Geocoding API" cevabını onayladı, sonra bunun ücretli bir servis olduğunu görüp `Geocoder` diye düzeltti.

**Soru 5** (ekrandan, 01:40:00 ve derste sözlü, 01:42:12): Chicago'daki bir nokta (enlem yaklaşık 41,85, boylam -87,65) için zoom 3'te piksel ve karo koordinatları nedir? $\text{pixelCoordinate} = \text{worldCoordinate} \times 2^{\text{zoomLevel}}$ ve karo boyutu 256 pikseldir.

> **Cevap (derste sonuç verildi, ara adımlar python ile doğrulandı):** Dünya koordinatı yaklaşık (65,67; 95,17). $2^3 = 8$ ile çarpılınca piksel koordinatı (525, 761) olur. 256'ya bölüp tam kısmı alınca karo koordinatı (2, 2) çıkar. Zoom 3'te dünya 2048×2048 pikseldir.

## Dersin Toparlaması

Bu derste Android uygulamalarında Google Maps kullanımının temelleri işlendi. Önce gereken SDK'lar, API anahtarının alınması, kısıtlanması ve manifeste eklenmesi, debug ve release sertifikaları anlatıldı. Sonra haritanın `SupportMapFragment` ve `OnMapReadyCallback` ile uygulamaya eklenmesi, fragment'ın statik ya da dinamik oluşturulması, `GoogleMap` sınıfının karo indirme ve hareket yönetimi gibi görevleri, harita türleri, bina içi haritalar ve trafik katmanı ele alındı. Haritanın başlangıç durumunun XML öznitelikleri ya da `GoogleMapOptions` ile ayarlanması ve lite mode'un kaynak tasarrufu da konuşuldu.

İkinci bölümde marker'lar (ekleme, tıklama, sürükleme, özelleştirme ve bilgi pencereleri), Polyline, Polygon ve Circle şekilleri, kameranın tilt, bearing ve zoom kavramları, `moveCamera` ile `animateCamera` farkı, My Location katmanı, POI tıklamaları ve Maps SDK'nın koordinat sistemleri işlendi. Adres ile koordinat arasındaki dönüşüm için `Geocoder` tanıtıldı. Ders, önceki dersin konum servisleri örneğini haritayla birleştirip konumu sürekli izleyerek marker'ı ve kamerayı güncelleyen bir kod örneğiyle kapandı.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
