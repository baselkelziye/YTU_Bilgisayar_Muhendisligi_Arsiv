# Ders 9 Genişletilmiş Notu: Android Sensörleri ve Sensör Framework'ü

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Ders Başındaki Sorular: Firebase ve Kütüphane Sürümleri
- 2. Sensörler Neden Önemli?
- 3. Ölçüm Aralığı ve Hassasiyet
- 4. Donanım ve Yazılım Tabanlı Sensörler
- 5. Android Sensör Framework'ünün Görevleri
- 6. Örnekleme Hızı ve Enerji
- 7. Android'deki Sensör Tipleri
- 8. Framework'ün Dört Yapı Taşı
- 9. Sensörleri Sorgulamak ve Seçmek
- 10. onSensorChanged, Register ve Unregister
- 11. Google Play Filtresi
- 12. Raporlama Modları
- 13. Calibrated ve Uncalibrated Veri
- 14. Sensör Değerleri ve Eksenler
- 15. Android 12 ile Gelen Örnekleme Kısıtı
- 16. Uygulama: Telefondaki Sensörleri Listelemek
- 17. Uygulama: Dönüş Vektörüyle Ekran Rengini Değiştirmek
- 18. Kotlin ile Yazılmış Bir Öğrenci Uygulamasının İncelenmesi
- Örnek Sorular
- Dersin Toparlaması

## 1. Ders Başındaki Sorular: Firebase ve Kütüphane Sürümleri

Derse geçmeden önce iki teknik soru konuşuldu.

**Soru:** Mobil uygulamada veri tabanı olarak Firebase'in diğer veri tabanlarına (ör. PostgreSQL) göre artısı nedir? **Cevap:** Hoca önce bu soruyu öğrencilerin Firebase ile çalışırken kendilerinin araştırmasını beklediğini söyledi. Sonra şöyle açıkladı: Firebase kolay kullanılan, ilk kez uygulama geliştirenlerin kolayca öğrenebildiği, uygulaması basit ve aynı zamanda performanslı bir yapıdır; Flutter ile geliştirmede de sık kullanılır. PostgreSQL ise özel olarak mobil uygulamalar için tasarlanmış bir veri tabanı değildir; birçok uygulamada kullanılan genel bir veri tabanı yönetim sistemidir. Firebase ağırlıklı olarak mobil uygulamalar gözetilerek ortaya çıkmıştır. Aradaki fark budur.

**Soru:** İnternetten bulunan kod parçalarında sürüm uyumuna nasıl dikkat edilir? **Cevap:** Hoca bu konuyu ayrıca göstereceğini söyledi ve kısaca şunu belirtti: bu tür sorunları gidermek için çoğu zaman `build.gradle` dosyası açılıp gerekli depoların (repository) eklenmesi gerekir. Herkes farklı API seviyeleri ve o seviyeye uygun farklı Gradle sürümleriyle kod geliştirdiği için kütüphanelerin sürümleri özellikle kontrol edilmelidir.

## 2. Sensörler Neden Önemli?

Hoca konuya insanın karar verme biçiminden girdi. İnsan hayattaki kararlarını çevreden topladığı bilgilerle verir. Bir nesneye bakarak biçimini anlar, sesleri duyarak hangi sesin hangi hayvandan ya da cihazdan geldiğini öğrenir, dokunarak bir eşyanın sert mi yumuşak mı, sivri uçlu mu olduğunu, kaç köşesi olduğunu tespit eder. Tat ve koku da önemli duyulardır, hayatın keyfi açısından çok değerlidir; ama hayat konforu ve kararlar açısından ilk etapta görme, duyma ve dokunma öne çıkar.

Aynı mantık bilgisayarlar için de geçerlidir. Yapay zekâdan söz edebilmek için bilgisayara sürekli dosyadan veri okutmak ya da kullanıcıya sürekli veri girdirmek yeterli değildir. Özellikle gerçek zamanlı (real-time) işler yapılıyorsa, ortamda çevresel zekâ (ambient intelligence) uygulamalarına ihtiyaç varsa ya da olan bitene anında karşılık verilmek isteniyorsa, kullanılan cihazın ya da robotun ortamı anlaması, gözlemesi, öğrenmesi ve gelişmelerden haberdar olması gerekir. Bunu mümkün kılan, elektronik cihazların ve eşyaların üzerine yerleştirilen sensörlerdir.

Sensörler çok çeşitli yapılara konabilir: bilgisayar, tablet, saat, akıllı telefon, giyilebilir cihazlar ve bugün IoT cihazları (çamaşır makinesi, bulaşık makinesi vb.). Sensörün görevi fiziksel değişimi elektriksel bir sinyale dönüştürmektir (analog-dijital dönüşüm). Bu dönüşümden sonra elektriksel sinyallerle, artık genellikle dijital olarak, veri üretirler. Bu yüzden veriyi üreten olmazsa olmaz yapılardır.

Her sensör dış ortamda farklı bir değişimi takip eder. İvmeölçer bağlı olduğu eşyaya uygulanan ivmeyi ölçer; jiroskop bir eşyanın belirli bir eksende ne hızla döndüğünü radyan/saniye cinsinden verir; sıcaklık sensörü ortamın sıcaklığını, nem sensörü nem oranını verir. Kamera basit bir sensör değildir ama sonuçta iki boyutlu görüntü (tek kare ya da video dizisi) üreten bir sensördür. Mikrofon da dışarıdaki sesleri toplayan bir sensördür.

Dolayısıyla her sensörün:

- bir veri toplama görevi,
- verileri toplama sıklığı,
- verinin birimi,
- verinin kapladığı alan,
- tükettiği enerji ya da güç

vardır. Telefondaki sensörler de günlük hayattaki bu gelişmeleri takip edebilmek için konumlandırılmıştır.

Bir telefona bakıldığında en sık karşılaşılan sensörler, saatler dahil hemen her cihazda bulunan ve hareket sensörü (motion sensor) olarak adlandırılan ivmeölçer, jiroskop ve manyetometredir. Hoca bunların saniyede 200 civarında veri toplayabildiğini söyledi. Bu sensörler telefonun konumunu belirlemede, oyunlarda, düşme tespitinde ve kişinin hareketini algılamada çok sık kullanılır. Akademik çalışmalar incelendiğinde en başarılı sonuçların üçünün birlikte kullanıldığı senaryolarda alındığı görülür.

Bunların dışında yakınlık (proximity) sensörü vardır: telefon ekranı bir nesneye belirli bir mesafeden yakın olunca ekran otomatik kapanır. Bazı telefonlarda sıcaklık sensörü vardır. Hoca, bütün telefonların derste konuşulan sensörlerin hepsine sahip olmadığını vurguladı; hareket sensörleri ise giyilebilir cihazlarda ve telefonlarda ağırlıklı olarak bulunur.

## 3. Ölçüm Aralığı ve Hassasiyet

Telefondaki sensörler telefonun boyutuna uygun olarak çok küçüktür. Bu nedenle bir elektronik cihazın içine konan daha büyük bir sensörle kıyaslandığında ölçüm hassasiyeti açısından bazı handikaplara sahip olabilirler. Ancak elektronik üretimindeki gelişmeler sayesinde bugün oldukça hassas ölçüm yapabiliyorlar. Hocaya göre "askeri uygulamalardaki düğümlerde kullanılan sensörler kadar etkin değil" yorumları yavaş yavaş geride kalıyor.

Her sensörün bir ölçüm aralığı (range) vardır. Örneğin ivmeölçerin ölçebildiği bir ivme üst sınırı vardır. Telefona bu sınırın üstünde bir ivme uygulandığında telefon yalnız üst sınır kadarını algılar; üstündeki değeri donanımsal ya da yazılımsal kısıtlar yüzünden gösteremez. Tasarlanan uygulamada bu limitleri bilmek gerekir. Hoca, birkaç yıl önce sensörlerin 4G'nin üzerini ölçmesinin pek mümkün olmadığını, bugün 8G ve 16G'ye ulaşıldığını, daha eskiden ise yalnız 2G civarının ölçülebildiğini anlattı. Bu, telefona uygulanan büyük kuvvetlerin anlaşılamamasına ve bunlara dayanan uygulamaların sağlıklı çalışmamasına neden oluyordu.

Ölçümün hassasiyeti de önemlidir. Telefonu döndürerek bir topu delikten geçirdiğiniz ya da bir yolda ilerlediğiniz bir oyun düşünün; bu hareketlerin doğru algılanması için genel aralığın yanında hassasiyet bakımından da bir alan gerekir. Bu alanın nasıl kullanıldığı önemlidir: aralık büyütüldüğünde hassasiyet düşer, küçültüldüğünde üst sınır aşağı iner.

> **Ek bilgi (derste anlatılmadı):** İvmeölçerlerde "G" yer çekimi ivmesinin katıdır; 1G yaklaşık 9,81 m/s²'dir. ±2G, ±4G, ±8G, ±16G gibi aralıklar sensörün seçilebilir tam ölçek değerleridir. Sabit sayıda bitle temsil edilen bir ölçümde tam ölçek büyüdükçe her bitin karşılık geldiği ivme büyür, yani çözünürlük düşer.

## 4. Donanım ve Yazılım Tabanlı Sensörler

Android'de iki tip sensörden söz edilir:

- **Donanım tabanlı (hardware-based):** Telefonda fiziksel olarak bir bileşen bulunur ve ölçümü bu bileşen yapar.
- **Yazılım tabanlı (software-based):** Fiziksel bir bileşen yoktur; donanım sensörlerinin ürettiği değerleri kullanarak başka bir değer üretir. Örneğin pedometre kaç adım attığınızı ölçer, ama fiziksel bir sensör değildir; diğer sensörlerin verilerini kullanarak bu işi yapar.

## 5. Android Sensör Framework'ünün Görevleri

Android'de sensörlerle iş yaparken sensör framework'ünden yararlanılır. Slayttaki maddeler (ekrandan, 00:15:00) şunlardır:

- Android sensör framework'ü birçok sensör tipine erişim sağlar; bunların bir kısmı donanım, bir kısmı yazılım tabanlıdır.
- Cihazda hangi sensörlerin bulunduğunu belirlemek.
- Tek bir sensörün yeteneklerini belirlemek: maksimum aralık, üretici, güç ihtiyacı ve çözünürlük.
- Ham sensör verisini almak ve verinin alınacağı en düşük hızı tanımlamak.
- Sensör değişikliklerini izleyen olay dinleyicilerini (event listener) kaydetmek ve kaydını silmek.

Hoca bu maddeleri tek tek açtı. Önce cihazda hangi sensörlerin olduğu tespit edilmelidir: bir sensörle çalışmak isteniyorsa önce var olup olmadığı kontrol edilir, çünkü yoksa uygulama hata üretip kapanabilir. Sensörlerin belirli yetenekleri vardır: ölçebildikleri aralık, tükettikleri güç ve çözünürlükleri. Bir telefonda aynı tipten birden fazla sensör de bulunabilir; bu yüzden üreticileri de sorgulanabilir. Bazen sensörün üreticisi (vendor) önemlidir; belirli bir işi yapıp yapamayacağınızı oradan anlayabilirsiniz.

Sensörlerden gelen veriye genellikle ham veri (raw sensor data) denir.

## 6. Örnekleme Hızı ve Enerji

Hoca örnekleme hızını (sampling rate) sensör denince akla gelmesi gereken ilk terim olarak tanımladı. Bir sensörün ortamdan ne sıklıkla örnek aldığı, yapılan işin başarısını doğrudan etkiler. İvmeölçer saniyede yalnız bir veri alsaydı bugün ivmeölçerle yapılan işlerin çoğu ya hiç yapılamaz ya da çok başarısız yapılırdı. Öte yandan GPS'ten saniyede 100 konum bilgisi alınmaz: hem buna ihtiyaç yoktur hem de enerji tüketimi açısından büyük sorun yaratır. Bu yüzden her sensörün saniyede alabileceği örnek sayısının bir sınırı vardır: kiminde 200, kiminde 10, kiminde 5, kiminde saniyede bir. Hangi sensörle çalışılıyorsa örnekleme hızı buna göre belirlenmelidir. Saniyede alınan örnek sayısı aynı zamanda sensörün frekansını gösterir.

Sensörlerin ihtiyaç yokken veri toplaması gereksiz enerji tüketimi demektir; saniyede çok veri toplayan sensörlerde bu daha da önemlidir. Hoca, son dönemde gelen kısıtlamalarla Android'in bu sensörlerin arka planda kullanılmasını istemediğini, mümkünse uygulama kullanılırken ya da bir foreground servise bağlanarak veri toplanmasını beklediğini, arka plan servislerinin bunu kısıtladığını söyledi. Yine de kontrol geliştiricidedir: sensör olay dinleyicileri register ve unregister edilerek hangi sensörden veri toplanacağı belirlenir. Dinleyici kaydedildiği andan itibaren sensör veri ölçtükçe veri döndürür ve bu veriyle işlem yapılır.

## 7. Android'deki Sensör Tipleri

Android telefonda bulunabilecek sensörlerin tablosu (ekrandan, 00:30:00) şöyledir. Hoca bütün sensörlerin her telefonda bulunmadığını yeniden hatırlattı.

| Sensör | Tip | Ölçtüğü | Yaygın kullanım |
|---|---|---|---|
| `TYPE_ACCELEROMETER` | Donanım | 3 eksende cihaza uygulanan ivme, yer çekimi dahil (m/s²) | Hareket algılama (sallama, eğme) |
| `TYPE_AMBIENT_TEMPERATURE` | Donanım | Ortam sıcaklığı (°C) | Hava sıcaklığını izleme |
| `TYPE_GRAVITY` | Yazılım ya da donanım | 3 eksende yer çekimi kuvveti (m/s²) | Hareket algılama |
| `TYPE_GYROSCOPE` | Donanım | 3 eksen etrafında dönüş hızı (rad/s) | Dönüş algılama |
| `TYPE_LIGHT` | Donanım | Ortam ışık seviyesi (lx) | Ekran parlaklığını ayarlama |
| `TYPE_LINEAR_ACCELERATION` | Yazılım ya da donanım | 3 eksende ivme, yer çekimi hariç (m/s²) | Tek eksende ivmeyi izleme |
| `TYPE_MAGNETIC_FIELD` | Donanım | 3 eksende jeomanyetik alan (μT) | Pusula |
| `TYPE_ORIENTATION` | Yazılım | 3 eksen etrafındaki dönüş dereceleri | Cihaz konumunu belirleme |
| `TYPE_PRESSURE` | Donanım | Hava basıncı (hPa ya da mbar) | Basınç değişimini izleme |
| `TYPE_PROXIMITY` | Donanım | Ekrana nesne yakınlığı (cm) | Görüşmede telefonun kulağa tutulduğunu anlama |
| `TYPE_RELATIVE_HUMIDITY` | Donanım | Bağıl nem (%) | Çiy noktası, mutlak ve bağıl nem |
| `TYPE_ROTATION_VECTOR` | Yazılım ya da donanım | Dönüş vektörünün üç bileşeni | Hareket ve dönüş algılama |
| `TYPE_TEMPERATURE` | Donanım | Cihaz sıcaklığı (°C); API 14'te `TYPE_AMBIENT_TEMPERATURE` ile değiştirildi | Sıcaklık izleme |

Hocanın tablo üzerindeki açıklamaları:

- Işık sensörü telefonun ekran parlaklığı ve karanlık moda geçişi için çok önemlidir.
- Linear acceleration sensörü normal ivmeölçerden farklı olarak yer çekimi ivmesinin dışarıda bırakıldığı hâlidir: telefona uygulanan, yer çekiminden bağımsız ivmeyi verir. Donanımsal olabilir ya da yazılımsal olarak hesaplanabilir.
- Manyetik alan ölçümü özellikle pusula için kullanılır.
- Orientation sensörü telefonun konumuyla ilgili bilgiye ihtiyaç duyulduğunda telefonun pozisyonunu yazılımsal olarak söyler. Hoca üç temel pozisyondan söz etti: dik tutma, karşınızda tutma ve yatay çevirip "sinema ekranı" biçiminde bakma.
- Basınç sensörü çoğu telefonda yoktur; olanlarda Pascal ya da bar türünden birimlerle ifade edilir (slaytta hPa ya da mbar). Bu sensörle kişinin hangi katta olduğunu, kat değişimini anlayan uygulamalar yapılabilir. Örneğin kullanıcı onay verirse alışveriş merkezinde izlediği rota takip edilebilir. Bu tür uygulamalar insanların günlük aktivitelerini anlayıp başlarına gelebilecek olaylara karşı önlem almaya ya da davranışlarına göre reklam yapmaya katkı sağlar.
- Yakınlık sensörü telefonun pozisyonunun anlaşılmasında ve görüşme sırasında ekranın kapanmasında kullanılır.
- Rotation vector telefonun açısal olarak hangi konumda olduğunu, hangi dereceyle tutulduğunu hesaplar; genelde yazılım sensörü olarak karşımıza çıkar.
- Son olarak iç sıcaklığı ölçen bir sensör vardır; işlemcinin ya da telefonun kullanım yoğunluğuna bağlı ısınmasını izleyip önlem alınmasını sağlar.

## 8. Framework'ün Dört Yapı Taşı

Sensör framework'ü denince dört temel yapıdan söz edilir:

- **`SensorManager`:** Bütün sensörlere erişmekten ve onlarla ilgili register/unregister işlemlerinden sorumlu yapıdır.
- **`Sensor`:** Her sensör için oluşturulabilen ve o sensörün yeteneklerini saklayan sınıftır.
- **`SensorEvent`:** Bir olay gerçekleştiğinde o olaya ait bilgilerin saklandığı nesnedir.
- **`SensorEventListener`:** Sensördeki değişiklikleri izler. Değişiklik sürekli bir verinin takibi (continuous) olabileceği gibi bir durum (status) değişimi de olabilir.

Hoca bu dört yapıyı Android'in sunduğu temel yapı taşları olarak tanıttı ve hep bunların kullanılacağını söyledi.

## 9. Sensörleri Sorgulamak ve Seçmek

Önce bir `SensorManager` nesnesi tanımlanır. Hangi servisin istendiği kontekst üzerinden söylenir: `getSystemService(Context.SENSOR_SERVICE)` ile sensör servisi alınır. Hoca, konum tabanlı işlerde de benzer biçimde konum servislerine bağlanıldığını hatırlattı.

`SensorManager`'ın `getSensorList` metoduna `Sensor.TYPE_ALL`, `TYPE_TEMPERATURE`, `TYPE_ACCELEROMETER` gibi tipler verilerek o tipten hangi sensörlerin cihazda bulunduğu sorgulanır. `TYPE_ALL` verilirse bütün liste gelir; `TYPE_MAGNETIC_FIELD` verilirse o tipteki bütün sensörler gelir.

Her tipten yalnız bir tane olmayabilir. Bazı telefonlar aynı tipte birden fazla sensör koyar. Hocanın saydığı nedenler: biri bozulursa diğeriyle devam etmek, birinin daha az enerji tüketip daha az ayrıntılı bilgi üretmesi. Kameralar da iyi bir örnektir: telefonlarda artık birden fazla kamera vardır; hem derinlik algılamak için hem de ön ve arka kamerayı istenen zaman kullanmak için.

Bir sensörün yetenekleri metotlarla öğrenilir:

- `getMaximumRange()`: sensörün ölçebildiği en yüksek değer.
- `getPower()`: yaklaşık güç tüketimi. Hoca güç ile enerjinin farklı şeyler olduğunu hatırlattı: enerji zamana bağlıdır, güçten zaman üzerinden enerjiye geçilir.
- `getVendor()`: üretici.
- `getVersion()`: sensörün sürümü; speklerle ilgili bilgi.
- `getResolution()`: çözünürlük.

> **Ek bilgi (derste anlatılmadı):** Android belgelerinde `getPower()` değeri miliamper (mA) cinsinden verilir. Güç birimi değil akım birimi olduğu için karşılaştırma aynı cihazdaki sensörler arasında anlamlıdır.

Slayttaki örnek kod (ekrandan, 00:35:00) bu parçaları birleştirir:

```java
private SensorManager sensorManager;
private Sensor mSensor;

...

sensorManager = (SensorManager) getSystemService(Context.SENSOR_SERVICE);
mSensor = null;

if (sensorManager.getDefaultSensor(Sensor.TYPE_GRAVITY) != null){
    List<Sensor> gravSensors = sensorManager.getSensorList(Sensor.TYPE_GRAVITY);
    for(int i=0; i<gravSensors.size(); i++) {
        if ((gravSensors.get(i).getVendor().contains("Google LLC")) &&
           (gravSensors.get(i).getVersion() == 3)){
            // Use the version 3 gravity sensor.
            mSensor = gravSensors.get(i);
        }
    }
}
if (mSensor == null){
    // Use the accelerometer.
    if (sensorManager.getDefaultSensor(Sensor.TYPE_ACCELEROMETER) != null){
        mSensor = sensorManager.getDefaultSensor(Sensor.TYPE_ACCELEROMETER);
    } else{
        // Sorry, there are no accelerometers on your device.
        // You can't play this game.
    }
}
```

İlk `if`'te yer çekimi sensörünün olup olmadığı kontrol edilir. Varsa o tipteki sensörlerin listesi istenir ve içlerinde üreticisi Google olan, sürümü 3 olan bir yer çekimi sensörü aranır; bulunursa o kullanılır. İkinci blokta, yer çekimi sensörü seçilememişse ivmeölçere bakılır. O da yoksa, telefonda bu sensör olmadığı için belirli yeteneklerin kullanılamayacağını söyleyen bir mesaj döndürülebilir.

## 10. onSensorChanged, Register ve Unregister

Hoca iki metodu en kritik metotlar olarak tanıttı.

### 10.1 onSensorChanged

`onSensorChanged` sensör tarafında üretilen her veriyi ya da her durum değişimini takip eden metottur. Gelen `SensorEvent` içindeki bilgiler burada alınır ve yapılacak işler genellikle burada yapılır. Metot sensör her veri ürettiğinde çağrıldığı için saniyede 100 ya da 200 veri alınıyorsa saniyede 100 ya da 200 kez çalışır.

Bunun sonucu şudur: metodun içinde uzun süren işler yapılırsa sensörün sağladığı sıklıkta veri işlenemez. İçerideki iş, bir sonraki veri gelene kadar bitebilecek düzeyde olmalıdır. Daha uzun kod bloklamaya, bazı değerlerin yakalanamamasına ve kullanılamamasına yol açar.

> **Hocanın vurgusu:** `onSensorChanged` içinde uzun süren işlerden mümkün olduğunca kaçınmak gerekir.

### 10.2 onResume ve onPause

Uygulama sensörü kullanacaksa, uygulama aktif olduğunda (`onResume`) sensör dinleyicisi kaydedilmelidir. Uygulama duraklatıldığında (`onPause`), arka planda dinleme yapılmıyorsa dinleyici mutlaka kaydından çıkarılmalıdır. Çıkarılmazsa dinleme devam eder; bu sırada enerji kaybı ve kaynak israfı sürer.

`registerListener` metoduna üç bilgi gönderilir: dinleyici (genellikle aktivitenin kendisi, `this`), dinlenecek sensör ve verinin ne sıklıkla toplanacağı. Çok sık veri isteniyorsa `SENSOR_DELAY_FASTEST` seçilir; bu, sensörün kapasitesine göre saniyede örnekleyebileceği kadar veri istendiği anlamına gelir.

Android bu sıklığı garanti etmez. Saniyede 100 veri planlanırken 97, 98 ya da 95 veri gelebilir. Bu nedenle işler her zaman istenen miktarda verinin geleceği varsayımıyla değil, gerçekten ne kadar veri geldiği hesaplanarak yapılmalıdır.

## 11. Google Play Filtresi

Bir sensör telefonda yoksa ve uygulama o sensöre mutlaka ihtiyaç duyuyorsa, manifest'te `uses-feature` ile tanımlanmalı ve `required` değeri `true` yazılmalıdır (ekrandan, 00:40:00):

```xml
<uses-feature android:name="android.hardware.sensor.accelerometer"
              android:required="true" />
```

Bunun etkisi şudur: bir telefon uygulamayı indirmek istediğinde manifest taranır; sensör o telefonda yoksa uygulama o telefonun markete girişinde gösterilmez. Böylece uygulama için kritik bir sensörü olmayan telefonda uygulama hiç görünmez ve kullanıcı memnuniyetinin kötü etkilenmesi önlenir.

`required` değerine `false` da yazılabilir. Bu şu anlama gelir: uygulama bütün yeteneklerini sergileyebilmek için ivmeölçere ihtiyaç duyar, ama sensör yoksa da çalışabilir; yalnız her yeteneğini tam performansla gösteremez.

## 12. Raporlama Modları

Android sensör verisini toplarken üç format kullanır:

- **Continuous (sürekli):** Belirli bir örnekleme hızı düşünülerek sensörlerden sürekli değer istenir. Verilen hıza bağlı olarak sensör o sıklıkta veri üretip aktarır.
- **On-change (değişimde):** Sensör yalnız yeni bir değer ölçtüğünde veri üretir. Step counter ya da proximity gibi sensörleri düşünün: yürümediğiniz, oturduğunuz, telefonun sabit kaldığı durumda telefonun sürekli 0-0-0 raporlamasına gerek yoktur. Bir adım attığınızda, ikinci adımı attığınızda, yani değişiklik olduğunda raporlama yapılır. Bu enerji tasarrufu sağlar.
- **One-shot (tek atımlık):** Bir olayın tespit edilmesi durumudur. Bunlar trigger sensörler olarak karşımıza çıkar: belirli bir gesture gerçekleştiği anda onu algılar. Bir aktivite gerçekleştirdiğinizde "yürüme moduna geçtiniz" ya da "araçla hareket ediyorsunuz" gibi bilgi verir. Kişinin günlük aktivitelerinin anlaşılması ve raporlanmasında kullanılır.

Hoca, eskiden işletim sistemlerinin bu tür işleri yapmadığını ve bunlar için kütüphane bulunmadığını anlattı. İnsanların aktivitelerinin anlaşılması günlük hayatta değer kazanınca bu sensörler eklendi; örneğin araca bindiğinizin anlaşılması isteniyorsa bu sensörler çağrılır. Genelde yazılım tabanlıdırlar ve arka planda, üçüncü parti uygulamaların yaptığı gibi, ivmeölçer, manyetometre ve jiroskoptan yararlanırlar.

Slayttaki tablo (ekrandan, 00:45:00 ve 01:00:00) yazılım tabanlı sensörlerin kategorisini, beslendiği fiziksel sensörleri ve raporlama modunu verir:

| Sensör | Kategori | Beslendiği fiziksel sensörler | Raporlama modu |
|---|---|---|---|
| Game rotation vector | Attitude | İvmeölçer, jiroskop; manyetometre KULLANMAZ | Continuous |
| Geomagnetic rotation vector | Attitude | İvmeölçer, manyetometre; jiroskop KULLANMAZ | Continuous |
| Glance gesture | Interaction | Tanımsız | One-shot |
| Gravity | Attitude | İvmeölçer, jiroskop | Continuous |
| Gyroscope uncalibrated | Uncalibrated | Jiroskop | Continuous |
| Linear acceleration | Activity | İvmeölçer, jiroskop (varsa) ya da manyetometre (jiroskop yoksa) | Continuous |
| Magnetic field uncalibrated | Uncalibrated | Manyetometre | Continuous |
| Orientation (deprecated) | Attitude | İvmeölçer, manyetometre, jiroskop (varsa) | Continuous |
| Pick up gesture | Interaction | Tanımsız | One-shot |
| Rotation vector | Attitude | İvmeölçer, manyetometre, jiroskop | Continuous |
| Significant motion | Activity | İvmeölçer (ya da çok düşük güçlü başka bir sensör) | One-shot |
| Step counter | Activity | İvmeölçer | On-change |
| Step detector | Activity | İvmeölçer | Special |
| Tilt detector | Activity | İvmeölçer | Special |
| Wake up gesture | Interaction | Tanımsız | One-shot |

## 13. Calibrated ve Uncalibrated Veri

Tablodaki bazı sensörler "calibrated", bazıları "uncalibrated" olarak geçer. Hoca bunun ne anlama gelebileceğini sınıfa sordu ve aradan sonra konuya döndü.

**Soru (hocanın sınıfa sorusu):** Bir sensörün kalibre ve kalibre edilmemiş olması arasında ne fark olabilir? **Cevap (bir öğrenci):** Kalibre veri doğrudan kalibre edilmiş olarak geliyor olabilir; kalibre edilmemiş veride ise kendimiz özel ayarlarla farklı bir kalibrasyon yapabiliyor olabiliriz. **Hocanın açıklaması:** Bu doğrudur. Android, kendi telefonunuzda sensörleri listelediğinizde bazı sensörlerin iki ya da üç sürümünü sunar; biri kalibre edilmiş veri, biri kalibre edilmemiş veri verir. Kalibre edilmiş veri belirli bir standarda göre düzeltilip filtrelenmiş olarak sunulur. Ancak her kalibrasyon istenen sonucu üretmeyebilir. Bu konuda hassas olanlar için sensörün hiçbir filtre uygulanmadan ölçtüğü değerler alınır ve kullanıcıya sunulur; kullanıcı bunları kendi yöntemiyle kalibre eder.

Genelde çok profesyonel olmayan son kullanıcılar kalibre edilmiş değerlerle çalışmayı uygun bulur; bu kolay bir yöntemdir, çünkü birisi sizin adınıza veriyi belirli bir standarda göre kalibre etmiştir. Bu standardı beğenmeyen ve kendi uygulaması için farklı standartlar gözeterek kalibrasyon yapmak isteyenler için kalibre edilmemiş veriyi kullanmak daha akıllıcadır. Bugün iki tür veri de kullanılmaktadır ve ikisi de işe yarar.

## 14. Sensör Değerleri ve Eksenler

### 14.1 Hareket sensörleri

İlk hareket sensörü, yer çekimi ivmesini de değer olarak içinde barındıran ivmeölçerdir. Hareket sensörleri dahil bazı sensörler birden fazla eksende veri üretir. Yaşadığımız dünyada fiziksel nesnelere üç boyutta ivme uygulandığı için ivmeölçer üç değer üretir: `values` dizisinin ilk gözünde x ekseni, ikinci gözünde y ekseni, üçüncü gözünde z ekseni değeri bulunur. Bu değerler tek tek ya da hep birlikte kullanılarak işler yapılır. Bu yüzden `SensorEvent` nesnesinden veri geldiğinde kaç eksenden (kaç boyuttan) veri geldiğini bilmek gerekir.

Hoca, akıllı telefonların hayatımıza ilk girdiği dönemde tek ya da iki eksende veri üreten ivmeölçerler de bulunduğunu, bugün ise üç eksenin standart hâline geldiğini söyledi.

Aynı slaytta bir trigger event listener örneği vardı: önceki tabloda geçen significant motion gibi one-shot sensörler için. Kişinin aktivitesinde anlamlı bir değişim tespit edildiğinde trigger event listener bunu yakalar ve olaya göre yapılması gereken aksiyon `onTrigger` metodu içinde gerçekleştirilir. Hocanın örneği: arabaya bindiğiniz ve arabayla hareket ettiğiniz anlaşıldığında, gelen aramalar için telefonun arabanın Bluetooth'una bağlanmasını sağlamak.

<!-- BELİRSİZ: ivmeölçer ve trigger event listener kod parçalarının yer aldığı slayt karelerde yok; kod metni alınamadı. -->

### 14.2 Konum sensörleri

Konum (position) sensörleri bir cihazın dünya referans çerçevesindeki fiziksel konumunu belirlemek için kullanılır (ekrandan, 01:05:00). `TYPE_PROXIMITY` sensörü `SensorEvent.values[0]` içinde nesneye uzaklığı cm cinsinden verir. Hoca, konum sensörlerinin belirli bir eksenle olan açıyı da paylaşabildiğini (orientation sensörü olarak) söyledi. Slayttaki üç açı:

- **Azimuth (-z ekseni etrafında dönüş):** Cihazın o anki pusula yönüyle manyetik kuzey arasındaki açıdır. Cihazın üst kenarı manyetik kuzeye bakıyorsa 0°, güneye bakıyorsa 180°, doğuya bakıyorsa 90°, batıya bakıyorsa 270°'dir.
- **Pitch (x ekseni etrafında dönüş):** Cihaz ekranına paralel düzlem ile yere paralel düzlem arasındaki açıdır. Cihaz yere paralel, alt kenarı size yakın tutulurken üst kenarı yere doğru eğilirse pitch pozitif olur; ters yöne eğilirse negatif olur. Aralığı -180° ile 180°'dir.
- **Roll (y ekseni etrafında dönüş):** Cihaz ekranına dik düzlem ile yere dik düzlem arasındaki açıdır. Cihaz yere paralel, alt kenarı size yakın tutulurken sol kenarı yere doğru eğilirse roll pozitif olur; sağ kenarı yere doğru eğilirse negatif olur. Aralığı -90° ile 90°'dir.

### 14.3 Ortam sensörleri ve kanal sayıları

Ortam sıcaklığı, ışık ve basınç gibi sensörler tek kanaldan veri toplar; değerleri `SensorEvent.values` dizisinin ilk gözündedir.

Sonraki tabloda hem kalibre edilmiş hem de kalibre edilmemiş sensör verileri vardı. Hoca kalibre edilmiş verilerin 3 kanaldan, kalibre edilmemiş verilerin 5 kanaldan geldiğini söyledi.

> **Ders sonrası not:** Hoca kalibre edilmemiş verinin 5 kanaldan geldiğini söyledi. Android belgelerinde kalibre edilmemiş jiroskop ve manyetometre büyük olasılıkla 6 değer döndürür: üç eksende ham ölçüm ve üç eksende tahmini sapma (bias). <!-- BELİRSİZ: ilgili tablo karelerde görünmüyor. -->

Yer çekimi sensörü de 3 kanaldan beslenir. Hoca, telefonun duruşuna göre bir eksenin yaklaşık 9,8 m/s² (altyazıda "980", "981" diye geçiyor) gösterdiğini, diğer eksenlerin 0 gösterdiğini anlattı: yatay bir pozisyonda y ekseninin, dik pozisyonda x ekseninin, "sinema modunda" dönük dururken z ekseninin bu değeri gösterdiğini söyledi.

> **Ders sonrası not:** Hocanın eksen eşleştirmesi Android'in koordinat sistemiyle uyuşmuyor. Büyük olasılıkla doğrusu şudur: telefon portre konumda dik tutulduğunda y ekseni, yatay (landscape, "sinema modu") tutulduğunda x ekseni, masaya düz yatırıldığında z ekseni yaklaşık 9,81 m/s² gösterir. <!-- BELİRSİZ: altyazıda "yatay" ve "dikey" kelimelerinin hangi duruşu kastettiği net değil. -->

Tablonun devamında diğer sensörlerin kaç kanaldan veri ürettiği gösterildi. Bunlardan game rotation vector, oyunlardaki aksiyonların takibi için yazılımsal olarak veri üreten sensörlerden biridir.

## 15. Android 12 ile Gelen Örnekleme Kısıtı

Android 12 ile birlikte sensörlerin örnekleme hızlarına kısıtlamalar uygulanmaya başlandı: belirli bir değerin altı örneklenebilirken üstü örneklenemiyor. Hoca, sensor direct channel kullanıldığında da `RATE_NORMAL` üzerinden 50 Hz'lik bir kısıtlama olduğunu söyledi. Daha yüksek örnekleme istenirse manifest'te High Sampling Rate Sensors izni tanımlanmalıdır; ancak bu sayede daha fazla veri çekilebilir.

<!-- BELİRSİZ: 01:07:15 ile 01:07:40 arasında altyazı kopuk; registerListener için söylenen üst sınır değeri anlaşılmıyor. -->

> **Ek bilgi (derste anlatılmadı):** Android belgelerine göre Android 12'yi (API 31) hedefleyen uygulamalarda `registerListener` ile alınan veri büyük olasılıkla 200 Hz ile sınırlanır. Bu sınırı aşmak için manifest'e `<uses-permission android:name="android.permission.HIGH_SAMPLING_RATE_SENSORS"/>` eklenir.

## 16. Uygulama: Telefondaki Sensörleri Listelemek

Teorik kısımdan sonra hoca Android Studio'da `ListSensors` adlı aktiviteyi açtı ve kendi telefonunda çalıştırdı. Kod (ekrandan, 01:10:00 ve 01:15:00):

```java
private SensorManager mgr;
private TextView txtList;

@Override
protected void onCreate(Bundle savedInstanceState) {
    super.onCreate(savedInstanceState);
    setContentView(R.layout.activity_listsensors);

    mgr = (SensorManager)getSystemService(Context.SENSOR_SERVICE);
    txtList = (TextView)findViewById(R.id.sensorslist);
    List<Sensor> sensorList = mgr.getSensorList(Sensor.TYPE_ALL);

    StringBuilder strBuilder = new StringBuilder();
    for(Sensor s: sensorList){
        strBuilder.append(s.getName()+"\n");
        Log.v("Sensor",s.getName());
        Log.v("Sensor", String.valueOf(s.getPower()));
    }
    txtList.setVisibility(View.VISIBLE);
    txtList.setText(strBuilder);
}
```

Kod şunu yapar: önce sensör servisi üzerinden `SensorManager` tanımlanır. Sonra ana ekranda listenin yazdırılacağı `TextView` bulunur. `getSensorList(Sensor.TYPE_ALL)` ile telefondaki bütün sensörler alınır. Her sensörün adı hem `StringBuilder`'a eklenir hem de `Log.v` ile Logcat'e basılır; `getPower()` ile sensörün ne kadar güç tükettiği de altına basılır.

Logcat çıktısında hocanın telefonundaki sensörler görüldü: bir ivmeölçer ve kalibre edilmemiş sürümü, bir manyetometre ve kalibre edilmemiş sürümü, bir jiroskop. Hoca jiroskobun güç tüketiminin ivmeölçer ve manyetometreye göre oldukça yüksek olduğuna dikkat çekti. Ayrıca "Wakeup Secondary" diye geçen ikincil sensörler vardı: bir sensörden iki tane bulunabiliyor. Bunların ardından gravity, linear acceleration, step detector, step counter, significant motion detector, game rotation vector, geomagnetic rotation vector, orientation (yazılımsal), pedometre ve persistent motion detector gibi sensörler listelendi.

Karedeki Logcat değerleri (ekrandan, 01:10:00 ve 01:15:00): "Gravity -Wakeup Secondary" ve "Linear Acceleration -Wakeup Secondary" için güç `2.824997`, "Rotation Vector -Wakeup Secondary" için `2.819992`, "Step Detector -Wakeup Secondary", "Android Motion Detector", "Pedometer", "Motion Accel" ve "Persistent Motion Detector" için `0.32499695`. Hoca gravity ve linear acceleration gibi sensörlerin güç tüketiminin yüksek olmasını bunların büyük olasılıkla yazılım sensörü olmasına bağladı.

Telefon ekranında ise `TextView` yer kalmadığı için sensörlerin yalnız bir kısmını gösterebildi. Bu yüzden çok sayıda sensörü Logcat'te görmek daha anlamlıdır. Listeyi aşağı kaydırarak göstermek için daha önce yapılan `RecyclerView` yapısı kullanılabilir.

Ardından hoca sınıfa bir alıştırma verdi (bkz. Örnek Sorular). Bu sensör uygulaması için mezun uygulamasıyla karışmaması adına ayrı bir mini proje açılmasını önerdi.

**Soru:** Emülatörle çalışırken benzer bir çıktı alınamıyor, doğru mu? **Cevap:** Emülatörde sensörler açılıp hareketleri taklit edilebilir. Örneğin ışık sensörü seçilip tanımlanır, eklenir; ama değerlerini kendiniz elle değiştirmeniz ve uygulamanın buna göre tepki vermesi gerekir. Emülatör telefonlar gerçek hayattaki gibi veri toplamaz. Liste almada da sensörler tanımlanmazsa varsayılan durumda alınamaz.

## 17. Uygulama: Dönüş Vektörüyle Ekran Rengini Değiştirmek

Aradan sonra hoca yeni bir örnek gösterdi. Uygulamanın giriş ekranında kullanıcı adı ve parola girilip oturum açıldıktan sonra açılan ekranda telefonun duruşuna göre arka plan rengi değişiyordu: telefon dik tutulunca ekran sarı, sağa yatırılınca siyah, sola yatırılınca beyaz oluyordu.

### 17.1 Kodun yapısı

`onCreate` içinde `SensorManager` tanımlanır. İki sensör kullanılır: rotation vector sensörü ve jiroskop. Hoca jiroskopla ilgili işlemenin şimdilik devre dışı (çalışmayan) bırakıldığını söyledi.

Rotation vector'dan gelen değerler `getRotationMatrixFromVector` metoduna verilir. Hoca bu metodun arka planda bir hesap yaptığını, bu hesabı ezbere bilmeye gerek olmadığını söyledi. Elde edilen dönüş matrisi `remapCoordinateSystem` ile yeniden eşlenir; böylece telefonun yönelimiyle ilgili bilgi alınır. Açı bilgilerini almak için `getOrientation` çağrılır; ona yeniden eşlenmiş dönüş matrisi ve sonuçları alacak `orientations` dizisi verilir. Üç eksendeki açı bu diziye yazılır.

Bu üç değerden biri alınır, log'a yazdırılır ve değerin açısal karşılığına göre ekran rengi değiştirilir. Hocanın anlatımına göre değer 45 dereceden büyükse ekran siyah, -45 dereceden küçükse beyaz, dik konuma yakınsa sarı olur. Bu işlem her yeni değer için tekrarlanır.

Karede görülen kod parçası (ekrandan, 02:00:00):

```java
        } else if (Math.abs(orientations[2]) < 10) {

            getWindow().getDecorView().setBackgroundColor(Color.YELLOW);

        }
    }
}

@Override
public void onAccuracyChanged(Sensor sensor, int i) {
}

protected void onResume() {
    super.onResume();
    sensorManager.registerListener(this, gyroscopeSensor, SensorManager.SENSOR_DELAY_NORMAL);
    sensorManager.registerListener(this, rotationVectorSensor, SensorManager.SENSOR_DELAY_NORMAL);
}

@Override
protected void onPause() {
    super.onPause();
    sensorManager.unregisterListener(this);
}
```

Karede dik konum koşulu `Math.abs(orientations[2]) < 10` olarak görünüyor; yani kullanılan açı `orientations[2]`'dir ve mutlak değeri 10 dereceden küçükse ekran sarı yapılır. <!-- BELİRSİZ: siyah ve beyaz dallarının koşulları ile getRotationMatrixFromVector, remapCoordinateSystem, getOrientation çağrılarının tam parametreleri karede görünmüyor. Hoca 45 ve -45 eşiklerini söyledi. --> Hoca alınan açıyı bir yerde "ikinci eksen", bir yerde "üçüncü eksen", bir yerde de "dikeydeki y ekseni" olarak andı; `getOrientation` dizisinde `[2]` indisi y ekseni etrafındaki dönüştür (roll). Bu da telefonu sağa sola yatırma hareketiyle uyumludur.

> **Ek bilgi (derste anlatılmadı):** `SensorManager.getOrientation` açıları radyan cinsinden döndürür. Dereceyle karşılaştırma yapmak için değerler önce `Math.toDegrees` ile dereceye çevrilir. Dizinin gözleri sırasıyla azimuth, pitch ve roll'dur.

### 17.2 Bir dinleyiciye birden fazla sensör

`onResume`'da iki sensör aynı dinleyiciye (`this`) kaydedilir: önce `SensorManager`'dan bu sensörlerin var olup olmadığı kontrol edilir, varsa kaydedilir; `onPause`'da dinleyici kaydından çıkarılır.

Bir dinleyiciye birden fazla sensör kaydedilebilir. Bu durumda `onSensorChanged` herhangi bir sensörden olay geldiğinde çağrılır; jiroskoptan da, rotation vector'dan da, belki takip edilen üç dört sensörden de. Bu yüzden önce olayın hangi sensörden geldiği kontrol edilir: `event.sensor.getType()` ile bakıldığında jiroskopsa `if` dalında jiroskop verisi işlenir; değilse `else` dalına gidilir ve verinin diğer sensörden geldiği anlaşılır. `else` dalında dönüş matrisi hesabıyla telefonun açısı alınır ve -45 ile 45 değerleriyle karşılaştırılarak ekran rengi değiştirilir. Yalnız tek bir sensör takip ediliyorsa bu kontrole gerek yoktur.

### 17.3 onAccuracyChanged

Aktivite `SensorEventListener` arayüzünü uygular. Bu arayüz uygulandığında `onSensorChanged` ile birlikte `onAccuracyChanged` metodu da tanımlanmak zorundadır. `onAccuracyChanged`, telefonun herhangi bir sensöründen gelen verinin doğruluğunda (accuracy) bir değişiklik raporlandığında ne yapılacağının yazıldığı metottur. Sensörün doğruluğunun değişmesi çok öngörülen bir durum olmadığı için bu metot çok sık kullanılmaz; ağırlıklı olarak `onSensorChanged` kullanılır.

## 18. Kotlin ile Yazılmış Bir Öğrenci Uygulamasının İncelenmesi

Dersin son bölümünde hoca bir öğrencinin gönderdiği uygulamayı çalıştırıp inceledi. Uygulama Kotlin ile yazılmıştı.

### 18.1 Arayüz ve davranış üzerine gözlemler

- ConstraintLayout kullanıldığı ve sürüm uyumsuzluğu olduğu için bazı düğmeler kaymış, hatta çalışmıyordu; hoca birkaç müdahale yapmak zorunda kaldı. Kayıt ekranında "kaydet" ve "geri dön" düğmeleri üst üste binmişti.
- Hatalı giriş bilgisinde uygulama "giriş bilgileri hatalı" mesajı verdi; beklenen davranış buydu.
- Hoca parola alanında parolanın görünmemesinin iyi olacağını söyledi. Alanlarda "kullanıcı adı" ve "parola" ipucu (hint) yazısının bulunmasını ise olumlu buldu. Ekran tasarımı sade ve uygundu, ikonlar vardı.
- Kayıt ekranına ad soyad, giriş tarihi ve mezuniyet tarihi alanları konmuştu. Hiçbir şey yazmadan "kaydet"e basıldığında da "kayıt başarılı" mesajı çıkıyordu. Hoca bunun olmaması gerektiğini, boş girişin kontrol edilmesine dikkat edilmesi gerektiğini söyledi.
- Uygulama sıfırdan yeniden yüklenince daha önce kaydedilen kullanıcıyla giriş yapılamadı. Hoca bunun nedenini açıkladı: bilgiler `SharedPreferences`'ta saklanmıştı ve uygulama yeniden yüklendiğinde `SharedPreferences`'taki bilgiler de kaybolur.
- Girişten sonra açılan haberler ekranında duyurular ve onlara uygun resimler statik olarak konmuştu.

### 18.2 Kotlin kodu

Hoca Kotlin kodunun Java'ya benzer bir yapıda olduğunu, ama noktalı virgüllerden arındırılmış ve daha kısa ifadelerle yazılabildiğini söyledi.

`MainActivity`: `super.onCreate` ile kaydedilmiş durum alınır, ardından `setContentView` çağrılır. `SharedPreferences`'tan kullanıcı adı ve parola alınıp `String`'e çevrilir ve girilen bilgilerle karşılaştırılır. Kontrol başarılıysa kullanıcı haberler ekranına yönlendirilir, değilse "giriş bilgileri hatalı" mesajı gösterilir. Hiçbir bilgi girilmemişse "bilgileri girmediniz" hatası verilir. Bütün bunlar "giriş yap" düğmesinin `setOnClickListener` bloğunda olur. "Kayıt ol" düğmesi kullanıcıyı kayıt ekranına yönlendirir.

`KayitOl`: "kaydet"e basıldığında `EditText`'lerdeki bilgiler alınıp `toString` ile metne çevrilir, oluşturulan `SharedPreferences`'ın editörüne eklenerek kaydedilir ve ekrandaki alanlar temizlenir.

`Haberler`: `RecyclerView`'un bağlanacağı ekrandır (ekrandan, 02:25:00). Resimler `drawable` klasörüne eklenmiş, resim kimlikleri ve duyuru başlıkları dizilere konmuştur. Kodun sonu şöyledir:

```kotlin
myRecyclerView = findViewById(R.id.recyclerView)
myRecyclerView.layoutManager = LinearLayoutManager(this)
myRecyclerView.setHasFixedSize(true)
myArrayList = arrayListOf<News>()
getUserData()
}

private fun getUserData(){
    for (i in imageID.indices){
        val news = News(imageID[i],heading[i])
        myArrayList.add(news)
    }
    myRecyclerView.adapter = MyAdapter(myArrayList)
}
```

`RecyclerView` bulunur, `LinearLayoutManager` atanır, `setHasFixedSize(true)` seçilir, bir `ArrayList` tanımlanır ve `getUserData` çağrılır. Bu metot her resim ve başlık için bir `News` nesnesi oluşturup listeye ekler; en sonda liste `MyAdapter`'a verilerek `RecyclerView`'a bağlanır.

`MyAdapter` (ekrandan, 02:30:00):

```kotlin
package com.example.mezunapp

import ...

class MyAdapter(private val newsList: ArrayList<News>):
    RecyclerView.Adapter<MyAdapter.MyViewHolder>() {

    override fun onCreateViewHolder(parent: ViewGroup, viewType: Int): MyViewHolder {
        val itemView = LayoutInflater.from(parent.context).inflate(R.layout.list_item,parent,false)
        return MyViewHolder(itemView)
    }

    override fun getItemCount(): Int {
        return newsList.size
    }

    override fun onBindViewHolder(holder: MyViewHolder, position: Int) {
        val currentItem = newsList[position]
        holder.titleImage.setImageResource(currentItem.titleImage)
        holder.tvHeading.text = currentItem.heading
    }

    class MyViewHolder(itemView:View):RecyclerView.ViewHolder(itemView){
        val titleImage : ShapeableImageView = itemView.findViewById(R.id.titleImage)
        val tvHeading : TextView = itemView.findViewById(R.id.tvHeading)
    }
}
```

- `onCreateViewHolder`: `LayoutInflater` ile `list_item` layout'unu inflate eder. `list_item` her öğe için tasarlanmış üç bileşenden oluşur: bir resim (`ShapeableImageView`), bir yazı ve altında boş bir `View`. Hoca `ShapeableImageView`'un resmin odak noktasını gösterdiğini söyledi.
- `getItemCount`: öğe sayısını döndürür.
- `onBindViewHolder`: öğenin konumuna göre ilgili `ViewHolder`'ın içini resimle ve metinle doldurur; her öğeye uygun duyuruyu ve resmi eşleştirir.
- `MyViewHolder`: `list_item` XML dosyasındaki bileşenlerle değişkenler arasındaki ilişkiyi kurar.

Ders sonunda bir öğrencinin sensör alıştırmasıyla ilgili sorusuna hoca şöyle cevap verdi: kurduğu mantık uygun olabilir, ama sonucu yalnız log'da değil ekranda da göstermek gerekir; bir `TextView` üzerinden göstermek, hatta renklendirmek ya da ikonla göstermek daha iyi olur.

## Örnek Sorular

**Soru 1** (derste sözlü, 00:44:54): Bir sensörün calibrated ve uncalibrated olması arasında ne fark vardır?

Cevap (derste verildi): Calibrated veri, Android'in belirli bir standarda göre düzeltip filtrelediği veridir; kullanımı kolaydır. Uncalibrated veri, sensörün hiç filtre uygulanmadan ölçtüğü ham değerlerdir; standart kalibrasyonu beğenmeyen ve kendi yöntemiyle kalibrasyon yapmak isteyenler bunu kullanır. Android bazı sensörlerin iki sürümünü de sunar.

**Soru 2** (derste sözlü, 01:14:30; kod ekrandan, 01:15:00): Sensör framework'ünü kullanarak kendi telefonunuzdaki sensörleri listeleyin. Her sensörün gücünü, üreticisini (vendor), çözünürlüğünü ve maksimum aralığını Logcat'te gösterin. Ardından listeyi `RecyclerView` ile, her öğede sensörün resmi, adı, gücü, çözünürlüğü ve maksimum aralığı olacak biçimde gösterin. Bir sonraki adım olarak bir öğeye tıklanınca yeni bir ekran açılsın ve o sensörün ölçtüğü değerler gösterilsin.

Derste verilen ipucu: Başlangıç kodu Bölüm 16'daki `ListSensors` aktivitesidir. Hoca güç dışında `getResolution()` ve `getMaximumRange()` ile de sensör özelliklerinin gösterilebileceğini hatırlattı (01:40:10).

> **Çözüm (derste verilmedi):** Döngü içinde her `Sensor s` için `s.getName()`, `s.getVendor()`, `s.getPower()`, `s.getResolution()` ve `s.getMaximumRange()` değerleri `Log.v` ile yazdırılır. `RecyclerView` için bu beş bilgiyi tutan bir model sınıfı, her öğe için bir `list_item` layout'u ve Bölüm 18.2'deki `MyAdapter` yapısına benzer bir adapter yazılır: `onCreateViewHolder` layout'u inflate eder, `getItemCount` liste boyunu döndürür, `onBindViewHolder` sensörün bilgilerini `TextView`'lara yazar. Sensör listesi `onCreate` içinde `getSensorList(Sensor.TYPE_ALL)` ile alınıp model listesine dönüştürülür ve adapter'a verilir. Bu çözüm Android kodu olduğu için derlenip çalıştırılmadı.

**Soru 3** (derste sözlü, 02:01:06 ve 02:02:29): Linear acceleration sensörü (yer çekiminin çıkarıldığı ivme) ve ışık sensörü verilerini birlikte takip eden bir uygulama yazın. İvmenin büyüklüğünü $\sqrt{x^2 + y^2 + z^2}$ ile hesaplayın; bu değer sıfır civarındaysa telefon hareketsizdir. Ekrana telefonun durumunu yazdırın:

- Hareket yok, ışık yok: telefon cepte ya da çantada.
- Hareket var, ışık var: telefon elde, kullanılıyor.
- Hareket yok, ışık var: telefon masanın üstünde duruyor.
- Hareket var, ışık yok: telefon çantada ve kişi telefonla hareket ediyor (dördüncü seçenek).

Hoca veri sürekli okunduğu için belirli bir gecikme konulabileceğini ya da okuma sıklığının düşürülebileceğini, anlık değişimler için çok sık veri okumanın gerekmeyebileceğini ve buna öğrencinin karar vereceğini söyledi. Başlangıç kodu olarak Bölüm 17'deki dönüş vektörü örneği verildi.

> **Çözüm (derste verilmedi):** İki sensör (`TYPE_LINEAR_ACCELERATION` ve `TYPE_LIGHT`) `onResume`'da aynı dinleyiciye kaydedilir, `onPause`'da kayıttan çıkarılır. `onSensorChanged` içinde `event.sensor.getType()` ile kaynak ayrılır: linear acceleration'dan gelirse büyüklük $\sqrt{v_0^2+v_1^2+v_2^2}$ hesaplanıp bir eşikle karşılaştırılarak "hareket var/yok" bilgisi güncellenir; ışıktan gelirse `values[0]` (lx) bir eşikle karşılaştırılarak "ışık var/yok" bilgisi güncellenir. Ardından iki bilgi yukarıdaki dört satırlık tabloya göre birleştirilip sonuç bir `TextView`'a yazılır. Eşik değerleri derste verilmedi; geliştirici telefonunda ölçerek seçer. Dört durumlu karar mantığı python ile dört giriş birleşimi üzerinde denendi ve her birleşim beklenen mesajı verdi. Android kodu derlenmedi.

**Soru 4** (derste sözlü, 00:08:47): Mobil uygulamada Firebase'in PostgreSQL gibi bir veri tabanına göre farkı nedir?

Cevap (derste verildi): Firebase mobil uygulamalar gözetilerek ortaya çıkmış, kolay öğrenilen, uygulaması basit ve performanslı bir yapıdır. PostgreSQL ise mobil uygulamalar için özel tasarlanmamış, genel amaçlı bir veri tabanı yönetim sistemidir.

## Dersin Toparlaması

Bu derste Android'de sensörlerle çalışmanın temeli kuruldu. Sensörlerin fiziksel değişimi elektriksel sinyale çevirerek cihaza çevresini algılama yeteneği verdiği, her sensörün bir ölçüm aralığı, hassasiyeti, birimi, örnekleme hızı ve güç tüketimi olduğu anlatıldı. Donanım ve yazılım tabanlı sensörler ayrıldı; Android'deki sensör tipleri ve birimleri tanıtıldı. Sensör framework'ünün dört yapı taşı (`SensorManager`, `Sensor`, `SensorEvent`, `SensorEventListener`) üzerinden sensörü sorgulama, yeteneklerini öğrenme, dinleyici kaydetme ve kayıttan çıkarma akışı görüldü. `onSensorChanged` içinde uzun iş yapılmaması, `onPause`'da unregister edilmesi ve istenen örnekleme hızının garanti olmadığı vurgulandı. Raporlama modları (continuous, on-change, one-shot), calibrated/uncalibrated veri, eksenler, yönelim açıları, Google Play filtresi ve Android 12 örnekleme kısıtı ele alındı.

Uygulama kısmında telefondaki sensörler Logcat'e listelendi, dönüş vektörüyle telefonun eğimine göre ekran rengi değiştirildi ve bir dinleyiciye birden fazla sensör bağlandığında kaynağın `getType()` ile ayrıldığı gösterildi. Son olarak Kotlin ile yazılmış bir uygulama üzerinden `SharedPreferences`'ın yeniden yüklemede silinmesi, boş giriş kontrolü ve `RecyclerView` adapter yapısı incelendi. Hoca bir sonraki derste broadcast konusunun işleneceğini söyledi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
