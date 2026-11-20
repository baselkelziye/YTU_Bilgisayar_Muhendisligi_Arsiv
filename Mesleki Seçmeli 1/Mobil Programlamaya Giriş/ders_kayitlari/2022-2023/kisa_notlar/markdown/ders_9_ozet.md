# Ders 9 Çalışma Özeti

## Genel Konular

- Sensörlerin önemi
  - İnsan kararlarını görme, duyma, dokunma gibi duyularla çevreden topladığı bilgiyle verir. Bir cihazın ya da robotun gerçek zamanlı ve çevresel zekâ gerektiren işler yapabilmesi için de ortamı sensörlerle algılaması gerekir.
  - Sensörler fiziksel değişimi elektriksel sinyale çevirir (analog-dijital dönüşüm) ve veriyi üretir. Bilgisayar, tablet, saat, akıllı telefon, giyilebilir cihazlar ve IoT cihazları (çamaşır makinesi vb.) sensör taşır.
  - Her sensörün bir veri toplama görevi, toplama sıklığı, birimi, kapladığı alan ve tükettiği güç vardır. Kamera ve mikrofon da sensördür.
  - Telefonlarda en sık görülenler hareket (motion) sensörleridir: ivmeölçer, jiroskop, manyetometre. Konum tespiti, oyun, düşme tespiti ve hareket tanımada kullanılır; akademik çalışmalarda en başarılı sonuçlar üçü birlikte kullanıldığında alınır.
  - Ölçüm aralığı (range) ve hassasiyet önemlidir: ivmeölçerin bir üst sınırı vardır, üstündeki ivme algılanamaz. Hocaya göre birkaç yıl önce 2G-4G'nin üstü ölçülemezken bugün 8G-16G ölçülebiliyor. Aralık büyütülürse hassasiyet düşer, küçültülürse üst sınır iner.
- Donanım ve yazılım tabanlı sensörler
  - Donanım tabanlı (hardware-based): telefonda fiziksel bir bileşen ölçüm yapar.
  - Yazılım tabanlı (software-based): başka sensörlerin değerlerinden yeni bir değer üretir. Örnek: pedometre (adım sayar) fiziksel değil, yazılımsal bir sensördür.
- Android sensör framework'ünün işleri (ekrandan, 00:15:00)
  - Cihazda hangi sensörlerin bulunduğunu belirlemek; sensör yoksa uygulama hata verip kapanabilir.
  - Bir sensörün yeteneklerini öğrenmek: maksimum aralık, üretici, güç ihtiyacı, çözünürlük. Bir telefonda aynı tipten birden fazla sensör olabilir.
  - Ham sensör verisini (raw sensor data) almak ve en düşük örnekleme hızını belirlemek.
  - Sensör değişikliklerini izleyen event listener'ları kaydetmek (register) ve kaydını silmek (unregister).
- Örnekleme hızı (sampling rate)
  - Sensörün saniyede kaç örnek aldığıdır, aynı zamanda frekansıdır. İvmeölçer saniyede bir örnek alsaydı bugünkü uygulamaların çoğu yapılamazdı; GPS'ten ise saniyede 100 konum almaya ne gerek ne de enerji vardır. Sensöre göre bu sayı 200, 10, 5 ya da 1 olabilir.
  - Gereksiz veri toplamak enerji israfıdır. Android son sürümlerde sensörlerin arka planda kullanımını kısıtlar; uygulama kullanılırken ya da bir foreground servis üzerinden veri toplanması beklenir.
- Android'deki sensör tipleri (ekrandan, 00:30:00)
  - `TYPE_ACCELEROMETER` (donanım, m/s², yer çekimi dahil, 3 eksen), `TYPE_AMBIENT_TEMPERATURE` (donanım, °C), `TYPE_GRAVITY` (yazılım ya da donanım, m/s²), `TYPE_GYROSCOPE` (donanım, rad/s, 3 eksen etrafında dönüş hızı), `TYPE_LIGHT` (donanım, lx), `TYPE_LINEAR_ACCELERATION` (yazılım ya da donanım, yer çekimi hariç ivme), `TYPE_MAGNETIC_FIELD` (donanım, μT, pusula), `TYPE_ORIENTATION` (yazılım, cihazın konumu), `TYPE_PRESSURE` (donanım, hPa ya da mbar), `TYPE_PROXIMITY` (donanım, cm, görüşmede ekranı kapatmak), `TYPE_RELATIVE_HUMIDITY` (donanım, %), `TYPE_ROTATION_VECTOR` (yazılım ya da donanım), `TYPE_TEMPERATURE` (cihaz sıcaklığı; API 14'te `TYPE_AMBIENT_TEMPERATURE` ile değiştirildi).
  - Basınç sensörü çoğu telefonda yoktur; olanlarda kat değişimi anlaşılabilir (ör. alışveriş merkezinde izlenen rota, kullanıcı onayıyla).
- Sensör framework'ünün dört yapı taşı
  - `SensorManager`: bütün sensörlere erişim, register/unregister işleri.
  - `Sensor`: bir sensörün yeteneklerini tutan sınıf.
  - `SensorEvent`: bir olay olduğunda olayın bilgisini (değerler, sensör, doğruluk, zaman) tutan nesne.
  - `SensorEventListener`: sürekli veri değişimini ya da durum değişimini izleyen arayüz.
- Sensörleri sorgulama
  - `getSystemService(Context.SENSOR_SERVICE)` ile `SensorManager` alınır. `getSensorList(Sensor.TYPE_ALL)` bütün sensörleri, `getSensorList(Sensor.TYPE_MAGNETIC_FIELD)` gibi bir çağrı o tipteki bütün sensörleri döndürür.
  - Aynı tipte birden fazla sensör olmasının nedenleri: biri bozulunca diğeriyle devam etmek, biri daha az enerji harcayıp daha az ayrıntı üretmek gibi. Kameralar da örnektir.
  - Yetenek metotları: `getMaximumRange()`, `getPower()` (yaklaşık güç tüketimi), `getResolution()`, `getVendor()`, `getVersion()`.
- Örnek kod: istenen sensörü seçmek (ekrandan, 00:35:00)
  - Yer çekimi sensörü varsa listesi alınır ve üreticisi `"Google LLC"`, sürümü `3` olan seçilir. Bulunamazsa ivmeölçere bakılır; o da yoksa "cihazınızda ivmeölçer yok, bu oyunu oynayamazsınız" türünden bir mesaj verilir.
- `onSensorChanged` ve `onAccuracyChanged`
  - `onSensorChanged(SensorEvent event)` sensör her veri ürettiğinde ya da durum değiştiğinde çağrılır; saniyede 100-200 veri geliyorsa saniyede 100-200 kez çalışır. İçinde uzun iş yapılmamalıdır, yoksa sonraki veriler kaçırılır.
  - `onAccuracyChanged(Sensor sensor, int accuracy)` sensörün doğruluğu değiştiğinde çağrılır; nadiren kullanılır, ama arayüz uygulanınca tanımlanmak zorundadır.
- Register ve unregister
  - Sensör `onResume`'da kaydedilir, `onPause`'da kaydı silinir. Silinmezse dinleme sürer, enerji ve kaynak boşa harcanır.
  - `registerListener` parametreleri: listener, sensör ve örnekleme sıklığı (ör. `SENSOR_DELAY_NORMAL`, en hızlısı `SENSOR_DELAY_FASTEST`). Android istenen sıklığı garanti etmez: saniyede 100 istenirken 95-98 gelebilir; hesaplar gelen veri sayısına göre yapılmalıdır.
- Google Play filtresi (ekrandan, 00:40:00)
  - Uygulama bir sensöre mutlaka ihtiyaç duyuyorsa manifest'e `<uses-feature android:name="android.hardware.sensor.accelerometer" android:required="true" />` yazılır. Sensörü olmayan telefonlarda uygulama markette görünmez.
  - `required="false"`: uygulama sensörle bütün yeteneklerini gösterir, sensör yoksa da kısıtlı çalışır.
- Raporlama modları (ekrandan, 00:45:00)
  - Continuous: verilen örnekleme hızında sürekli raporlama.
  - On-change: yalnız değer değişince raporlama (ör. step counter, proximity). Telefon dururken sürekli 0 göndermeye gerek yoktur; enerji tasarrufu sağlar.
  - One-shot: bir olay (gesture, anlamlı hareket) algılanınca bir kez tetiklenir (trigger sensörler). Yürümeye başlama, araçla hareket gibi aktivitelerin anlaşılmasında kullanılır; genelde ivmeölçer, manyetometre ve jiroskoptan beslenen yazılım sensörleridir.
  - Tablodaki örnekler: game rotation vector (ivmeölçer + jiroskop, manyetometre kullanmaz), geomagnetic rotation vector (ivmeölçer + manyetometre, jiroskop kullanmaz), significant motion (one-shot), step counter (on-change), step detector ve tilt detector (special), glance/pick up/wake up gesture (one-shot), orientation (deprecated).
- Calibrated ve uncalibrated veri
  - Calibrated veri, Android'in belli bir standarda göre düzelttiği ve filtrelediği veridir; çok profesyonel olmayan kullanıcılar için kolaydır.
  - Uncalibrated veri, sensörün hiç filtre uygulanmadan ölçtüğü değerlerdir; kalibrasyonu kendi yöntemiyle yapmak isteyenler için daha akıllıcadır. İkisi de kullanılır.
- Sensör değerlerinin eksenleri
  - İvmeölçer üç eksende değer üretir: `values[0]` x, `values[1]` y, `values[2]` z. Hangi sensörden kaç boyutlu veri geldiği bilinmelidir. Eskiden tek ya da iki eksenli ivmeölçerler de vardı; bugün üç eksen standarttır.
  - Sıcaklık, ışık, basınç gibi tek kanallı sensörlerin değeri `values[0]`'dadır. Proximity değeri `values[0]`'da cm cinsinden nesneye uzaklıktır (ekrandan, 01:05:00).
  - Trigger event listener ile significant motion gibi one-shot olaylar `onTrigger` içinde işlenir (ör. araca binildiği anlaşılınca araç Bluetooth'una bağlanmak).
- Konum sensörleri ve yönelim açıları (ekrandan, 01:05:00)
  - Azimuth: -z ekseni etrafında dönüş; cihazın üst kenarının manyetik kuzeyle açısı (kuzey 0°, doğu 90°, güney 180°, batı 270°).
  - Pitch: x ekseni etrafında dönüş, -180° ile 180° arası.
  - Roll: y ekseni etrafında dönüş, -90° ile 90° arası.
- Android 12 ile örnekleme kısıtı
  - Android 12'den itibaren sensör örnekleme hızına üst sınır gelmiştir; sensor direct channel kullanıldığında `RATE_NORMAL` düzeyinde, yaklaşık 50 Hz'lik bir sınır vardır. <!-- BELİRSİZ: registerListener için söylenen sınır altyazıda kopuk (01:07:15-01:07:40). --> Daha yüksek hız için manifest'te `HIGH_SAMPLING_RATE_SENSORS` izni tanımlanmalıdır.
- Uygulama 1: sensörleri listeleme (ekrandan, 01:10:00)
  - `ListSensors` aktivitesi `getSensorList(Sensor.TYPE_ALL)` ile sensörleri alır, adlarını `StringBuilder` ile bir `TextView`'a yazar, adı ve `getPower()` değerini `Log.v` ile Logcat'e basar.
  - Hocanın telefonunda ivmeölçer, manyetometre, jiroskop ve uncalibrated sürümleri, wakeup secondary sensörler, gravity, linear acceleration, rotation vector, step detector, step counter, significant motion, game rotation vector, geomagnetic rotation vector, orientation, pedometer, persistent motion detector gibi sensörler listelendi. Jiroskop ve yazılım sensörlerinin (gravity, linear acceleration) güç tüketimi ivmeölçer ve manyetometreden yüksektir.
  - Emülatörde sensörler gerçek veri toplamaz; değerleri elle değiştirmek gerekir.
- Uygulama 2: dönüş vektörüyle ekran rengi (ekrandan, 02:00:00)
  - Rotation vector değerleri `getRotationMatrixFromVector` ile dönüş matrisine çevrilir, `remapCoordinateSystem` ile yeniden eşlenir, `getOrientation` ile üç eksenin açısı alınır.
  - Telefon sağa yatırılınca ekran siyah, sola yatırılınca beyaz, dik tutulunca sarı olur. Hocanın anlatımında eşikler 45° ve -45°'dir; karedeki kodda dik konum `Math.abs(orientations[2]) < 10` ile sarı yapılır.
  - Bir listener'a birden fazla sensör kaydedilebilir; bu durumda `onSensorChanged` içinde `event.sensor.getType()` ile verinin hangi sensörden geldiği kontrol edilir.
- Kotlin ile yazılmış örnek bir öğrenci uygulamasının incelenmesi (ekrandan, 02:25:00 ve 02:30:00)
  - Kotlin kodu noktalı virgülsüzdür ve Java'dan kısadır, yapı benzerdir.
  - Kullanıcı bilgileri `SharedPreferences`'ta tutulmuştu; uygulama yeniden yüklenince bu bilgiler silindi.
  - `RecyclerView` için `LinearLayoutManager`, `setHasFixedSize(true)`, `ArrayList<News>` ve `MyAdapter` kullanıldı. Adapter'da `onCreateViewHolder` `list_item` layout'unu inflate eder, `getItemCount` liste boyunu döndürür, `onBindViewHolder` resim ve başlığı bağlar, `MyViewHolder` `ShapeableImageView` ve `TextView`'u bulur.

## Hocanın Özellikle Vurguladığı Kısımlar

- Sensörü kullanmadan önce cihazda olup olmadığını kontrol edin
  - Sensör yoksa uygulama hata verip kapanabilir. Kritik sensör için manifest'te `required="true"` yazmak, uygulamanın o telefonda markette hiç görünmemesini sağlar ve kullanıcı memnuniyetsizliğini önler.
- `onSensorChanged` içinde uzun iş yapmayın
  - Metot saniyede yüzlerce kez çağrılabilir; iş bir sonraki veri gelmeden bitmezse veri kaçırılır.
- `onPause`'da unregister edin
  - Edilmezse sensör dinlenmeye devam eder, enerji ve kaynak boşa gider.
- İstenen örnekleme hızına güvenmeyin
  - Android hızı garanti etmez; hesaplarınızı gerçekten gelen veri sayısına göre yapın.
- Örnekleme hızı sensöre ve işe göre seçilmeli
  - Sampling rate sensör denince akla gelmesi gereken ilk terimdir ve işin başarısını doğrudan etkiler.

## Kısa Tekrar Notları

- Donanım sensörü fiziksel bileşendir; yazılım sensörü (pedometre, linear acceleration, rotation vector) başka sensörlerden hesaplanır.
- Dört yapı taşı: `SensorManager`, `Sensor`, `SensorEvent`, `SensorEventListener`.
- `getSensorList(Sensor.TYPE_ALL)` bütün sensörleri, `getDefaultSensor(tip)` varsayılan sensörü verir; yoksa `null` döner.
- Yetenekler: `getMaximumRange`, `getPower`, `getResolution`, `getVendor`, `getVersion`.
- `onResume` → `registerListener(listener, sensör, sıklık)`; `onPause` → `unregisterListener`.
- Raporlama modları: continuous, on-change, one-shot (ve special).
- İvmeölçer `values[0..2]` = x, y, z; ışık, sıcaklık, basınç, proximity tek değer `values[0]`.
- Birimler: ivme m/s², jiroskop rad/s, ışık lx, manyetik alan μT, basınç hPa/mbar, proximity cm, nem %.
- Linear acceleration = yer çekimi çıkarılmış ivme.
- Uncalibrated veri filtresiz ham ölçümdür; kendi kalibrasyonunu yapmak isteyen kullanır.
- `<uses-feature ... android:required="true"/>` sensörü olmayan cihazda uygulamayı markette gizler.
- Android 12+ yüksek örnekleme için `HIGH_SAMPLING_RATE_SENSORS` izni gerekir.

## Detaylı Açıklamalar

- Sensör framework'ünde çalışma sırası şöyledir: önce `SensorManager` alınır, sonra istenen sensörün varlığı `getDefaultSensor` ya da `getSensorList` ile kontrol edilir. Sensör varsa aktivite `SensorEventListener` arayüzünü uygular, `onResume`'da `registerListener` çağrılır. Her yeni veri `onSensorChanged` metoduna bir `SensorEvent` olarak gelir; değerler `event.values` dizisindedir. Aktivite duraklarken (`onPause`) dinleyici kaydı silinir. Sıklık parametresi bir istektir, Android bunu garanti etmez.
- Seçili sensör örneği (ekrandan, 00:35:00) şöyledir:

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

- Sensör listeleme uygulamasının `onCreate` gövdesi (ekrandan, 01:15:00):

```java
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
```

  - Logcat'te gravity ve linear acceleration (wakeup secondary) için güç `2.824997`, rotation vector için `2.819992`, step detector ve pedometre gibi sensörler için `0.32499695` görünüyordu (ekrandan, 01:10:00 ve 01:15:00). `TextView` ekrana sığmayan sensörleri gösteremediği için listenin `RecyclerView` ile gösterilmesi önerildi.
- Dönüş vektörü uygulamasında `onResume` ve `onPause` (ekrandan, 02:00:00):

```java
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

  - `onSensorChanged` içinde önce sensör tipi kontrol edilir: jiroskopsa jiroskop dalı, değilse rotation vector dalı çalışır. Rotation vector dalında `getRotationMatrixFromVector` → `remapCoordinateSystem` → `getOrientation` zinciriyle açılar alınır; açı değeri log'a yazılır ve ekranın arka plan rengi `getWindow().getDecorView().setBackgroundColor(...)` ile değiştirilir. Karede görünen son dal `else if (Math.abs(orientations[2]) < 10)` koşulunda rengi `Color.YELLOW` yapar. <!-- BELİRSİZ: siyah/beyaz dallarının tam koşulları karede görünmüyor; hoca 45 ve -45 eşiklerinden söz etti. -->
- Yer çekimi sensörü üç kanallıdır; telefonun duruşuna göre yer çekimi ivmesi (yaklaşık 9,8 m/s²) tek bir eksende görünür, diğer eksenler 0'a yakındır.
  - Ders sonrası not: Hoca yatay duruşta y, dik duruşta x, "sinema modunda" z ekseninin yaklaşık 9,8 gösterdiğini söyledi. Android koordinat sisteminde büyük olasılıkla doğrusu şudur: telefon portre olarak dik tutulunca y, yatay (landscape) tutulunca x, masada düz yatarken z ekseni yaklaşık 9,8 gösterir.
- Calibrated/uncalibrated tablosunda hoca, calibrated verinin 3, uncalibrated verinin 5 kanaldan geldiğini söyledi.
  - Ders sonrası not: Android belgelerinde uncalibrated jiroskop ve manyetometre büyük olasılıkla 6 değer döndürür (3 eksen ham değer + 3 eksen sapma/bias tahmini).

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
