# Ders 8 Çalışma Özeti

## Genel Konular

- Android'de veri saklama seçenekleri (ekrandan, 00:20:00)
  - App-specific storage: yalnız uygulamanın kullanacağı dosyalar; internal storage içindeki ya da external storage içindeki uygulamaya ayrılmış dizinlerde tutulur. Başka uygulamaların erişmemesi gereken hassas bilgi internal storage'daki dizinlere yazılır.
  - Shared storage: başka uygulamalarla paylaşılacak medya, doküman ve diğer dosyalar (galeri, müzik, video, indirilen dosyalar).
  - Preferences: özel, ilkel (primitive) verilerin key-value çiftleri hâlinde saklanması.
  - Databases: yapısal (structured) verilerin Room persistence kütüphanesiyle özel bir veritabanında saklanması.
  - Ağ tarafında Firebase ya da kendi backend'inizdeki bir bulut veritabanı da veri saklama seçeneğidir.
- Hangi yöntemin seçileceği
  - Gereken alan büyükse ya da dosyalar çok paylaşılıyorsa external storage; uygulamaya özel kısımlar internal storage'a konur. Paylaşılan medya MediaStore API, diğer paylaşılan dosyalar Storage Access Framework ile ele alınır.
  - Veri uygulamaya özel ve hassassa internal storage, preferences ya da veritabanı seçilir: ilkel tipler için preferences, yapısal veri için veritabanı, dosya için internal storage.
  - SharedPreferences bilgisi bir XML dosyasında key-value çiftleri olarak, yarı yapısal (semi-structured) biçimde saklanır.
- Karşılaştırma tablosu (ekrandan, 00:25:00)
  - App-specific dosyalar: internal storage'da `getFilesDir()` / `getCacheDir()`, external storage'da `getExternalFilesDir()` / `getExternalCacheDir()`. Internal için izin gerekmez; external için Android 4.4 (API 19) ve üzerinde gerekmez. Diğer uygulamalar erişemez, uygulama kaldırılınca silinir.
  - Media (resim, ses, video): MediaStore API. Android 11 (API 30) ve üzerinde başka uygulamaların dosyalarına erişirken `READ_EXTERNAL_STORAGE`; Android 10'da (API 29) `READ_EXTERNAL_STORAGE` ya da `WRITE_EXTERNAL_STORAGE`; Android 9 (API 28) ve altında bütün dosyalar için izin gerekir. Diğer uygulamalar `READ_EXTERNAL_STORAGE` izniyle erişebilir; kaldırılınca silinmez.
  - Documents and other files (indirilen dosyalar dahil): Storage Access Framework, izin gerekmez, diğer uygulamalar sistem dosya seçicisiyle erişir, kaldırılınca silinmez.
  - App preferences: Jetpack Preferences kütüphanesi, key-value; Database: Room persistence kütüphanesi, yapısal veri. İkisinde de izin gerekmez, diğer uygulamalar erişemez, kaldırılınca silinir.
  - Android 11 ile gelen `MANAGE_EXTERNAL_STORAGE` izni bütün external alanda iş yapmayı sağlar; yalnız yedekleme, sıkıştırma gibi dosya yönetimi uygulamalarına uygundur, Android de diğer uygulamalara önermez.
- Device File Explorer (ekrandan, 00:30:00)
  - Android Studio'da View > Tool Windows > Device File Explorer ile açılır. Sanal ya da fiziksel cihazdaki dosyaların izinleri, tarihleri ve boyutları görülür.
  - `data/data/app_name/`: uygulamanın internal storage'daki veri dosyaları. `sdcard/`: external user storage'daki kullanıcı dosyaları (resimler vb.).
- Content Provider ve cache
  - Uygulamalar arası veri paylaşımı Content Provider ile yapılır (örneğin rehberdeki kişilere erişim).
  - Varsayılan olarak uygulama internal storage'a kurulur, dosyalarına diğer uygulamalar erişemez, kaldırılınca hepsi silinir.
  - Cache dizinine konan dosyaları Android yer azalınca temizleyebilir. Geçici dosyalar için cache dizini kullanmak daha akıllıcadır.
- Dosyalarla çalışırken iyi uygulamalar (ekrandan, 00:35:00)
  - Dosyaları tekrar tekrar açıp kapatmamak.
  - Tek tek dosya paylaşımı için FileProvider ya da Content Provider kullanmak.
  - Dosyaları Device File Explorer ile incelemek.
  - Dosya yolunu hardcoded yazmamak, çünkü konum cihazdan cihaza değişir.
  - Uygulamanın external storage'a kurulması isteniyorsa manifest'te `android:installLocation="preferExternal"` yazılır.
- Dosya okuma ve yazma
  - `File file = new File(context.getFilesDir(), filename);` ile uygulamanın kendi dizininde dosya tanımlanır (ekrandan, 00:45:00).
  - Yazma `openFileOutput` ve `FileOutputStream` ile, string `getBytes()` ile byte'a çevrilerek yapılır; okuma `FileInputStream` ve `BufferedReader` ile satır satır yapılır.
  - `File.createTempFile` ile ya da `getCacheDir()` altında cache dosyası yaratılır; `cacheFile.delete()` ya da `context.deleteFile(cacheFileName)` ile silinir; `fileList()` ile dizindeki dosyalar listelenir.
  - `getCacheDir()` için makul bir boyut sınırı (örneğin 1 MB) önerilir; `getDir(name, mode)` ile `getFilesDir()` içinde yeni dizin yaratılır (ekrandan, 00:45:00).
  - Birden fazla external storage volume olabilir; 0 indisli volume (büyük olasılıkla cihaz içindeki, sökülemeyen bölüm) önerilir.
  - Büyük bir dosyayla çalışmadan önce yeterli boş alan olup olmadığı kontrol edilmelidir; derste gösterilen kod 10 MB'lık alan olup olmadığını kontrol ediyordu. <!-- BELİRSİZ: 00:47 civarındaki StorageManager kodu karede yok, yalnız altyazıdan anlatıldı. -->
- External storage kontrolü (ekrandan, 01:05:00)
  - `isExternalStorageWritable()`: `Environment.getExternalStorageState()` sonucu `MEDIA_MOUNTED` ise true.
  - `isExternalStorageReadable()`: durum `MEDIA_MOUNTED` ya da `MEDIA_MOUNTED_READ_ONLY` ise true.
  - Ortak alan: `Environment.getExternalStoragePublicDirectory(Environment.DIRECTORY_PICTURES)`; uygulamaya özel alan: `context.getExternalFilesDir(Environment.DIRECTORY_PICTURES)`. İkisinde de `mkdirs()` başarısızsa "Directory not created" loglanır.
  - Silme: `myFile.delete()` ya da `myContext.deleteFile(fileName)`.
  - `getFreeSpace()` ve `getTotalSpace()` ile alan bilgisi alınır; `getExternalFilesDir()` ile yaratılan dosyalar uygulama kaldırılınca silinir.
  - Okuma yeterliyse yalnız `READ_EXTERNAL_STORAGE` istenmelidir; gereksiz izin kullanıcıyı şüphelendirir. İzin, gerektiğinde çalışma zamanında (runtime) istenebilir.
- Diğer API'ler
  - Medya için MediaStore API, PDF gibi dokümanlar için Storage Access Framework.
  - Android 11 ile gelen BlobStoreManager: uygulamalar arasında paylaşılabilen veri setleri (özellikle makine öğrenmesi ve federated learning için).
- SharedPreferences
  - `getSharedPreferences(dosyaAdı, mod)`: birden fazla preferences dosyası için, dosya adı parametresi gerekir. `getPreferences(mod)`: aktiviteye özel tek bir dosya için.
  - SharedPreferences ile saved instance state farkı (ekrandan, 01:10:00): SharedPreferences veriyi kullanıcı oturumları arasında, uygulama öldürülüp yeniden başlatılsa ya da cihaz yeniden açılsa bile korur (kullanıcı tercihleri, oyun skoru). Saved instance state yalnız aynı oturumdaki aktivite örnekleri arasında korur (seçili sekme, aktivitenin o anki durumu; tipik kullanım cihaz döndürülünce durumu yeniden kurmak).
  - Yazma: `SharedPreferences.Editor editor = sharedPref.edit();` → `editor.putInt(...)`, `putString`, `putBoolean` → `apply()` ya da `commit()` (ekrandan, 01:15:00).
  - Okuma: editör gerekmez; `sharedPref.getInt(key, defaultValue)`. Değer yoksa varsayılan değer döner (ekrandan, 01:15:00).
  - Diğer metotlar: `getFloat`, `getLong`, `getString`, `getAll`, `edit`, `putLong`.
  - Jetpack Preferences kütüphanesi aynı key-value hizmetini sunan daha yeni yapıdır.
- Uygulamalar arası veri gönderme
  - Text ya da binary içerik (resim URI'si) intent'e yüklenir; `Intent.createChooser` ile sistemden bu içeriği açabilecek uygulamaları listelemesi istenir.
  - Birden çok içerik: `ACTION_SEND_MULTIPLE`, `putParcelableArrayListExtra(Intent.EXTRA_STREAM, imageUris)`, `setType("image/*")` (ekrandan, 01:20:00).
  - Veri alan taraf `getIntent()` ile action ve tipi okuyup işi ona göre ayırır.
- Serializable ve Parcelable
  - Serializable: Java'nın standart arayüzü; basit, ek kod gerektirmez; daha yavaş, daha çok garbage üretir.
  - Parcelable: Android SDK'nın parçası; daha karmaşık, özel kod ister; daha hızlıdır, daha az garbage üretir. Binlerce nesne aktarılırken fark büyür, az veride fark küçüktür.
  - Parcelable örneği `Details` sınıfı (name, age, phone): `Parcel` alan yapıcı, `CREATOR` (`createFromParcel`, `newArray`), `describeContents()` ve `writeToParcel()` yazılır (ekrandan, 01:25:00). Gönderme `putExtra`, alma `getParcelableExtra` ile.
- Kamera uygulamaları (Android Studio)
  - `Camera.java`: `ActivityResultLauncher` ve `registerForActivityResult(new ActivityResultContracts.StartActivityForResult(), ...)` ile kamera açılır; dönen `Bundle` içindeki `"data"` `Bitmap`'e çevrilip `setImageBitmap` ile ImageView'da gösterilir (ekrandan, 01:35:00). Fotoğraf kaydedilmez.
  - `CameraSave.java`: `createImageFile()` ile zaman damgalı dosya adı üretilir, `getExternalStoragePublicDirectory(DIRECTORY_PICTURES)` altında `File.createTempFile` ile dosya yaratılır, `FileProvider.getUriForFile` ile URI alınıp intent'e eklenir; dönüşte dosya açılıp `setImageURI` ile gösterilir (ekrandan, 02:00:00). Fotoğraf `sdcard/Pictures` altına kaydedilir.
- SharedPreferences uygulaması (`SharedPrefActivity`)
  - `onResume()` içinde `"MySharedPref"` dosyasından `name` (varsayılan `""`) ve `age` (varsayılan `0`) okunup EditText'lere yazılır; `onPause()` içinde editörle `putString`, `putInt` ve `apply()` ile kaydedilir (ekrandan, 02:25:00).

## Hocanın Özellikle Vurguladığı Kısımlar

- Hassas veri internal storage'da tutulmalı
  - Kritik bilgi tartışmasız internal storage'a (dosya ya da veritabanı) yazılır. External storage fiziksel olarak çıkarılabilir olabileceği için hiçbir zaman tam güvenli sayılmaz.
  - Bankacılık gibi uygulamaları external storage'a kurmayı istemek kullanıcıyı uygulamayı indirmekten vazgeçirebilir.
- Android 10 ve üzerinde güvenlik arttı
  - Internal storage'daki uygulama dosyalarına diğer uygulamalar erişemez; ayrıca bu dosyalar şifrelenir. Android bu konuda iOS'un güvenlik seviyesine ayak uydurmaya çalışıyor.
- Dosya yolları hardcoded yazılmamalı
  - Her üreticinin cihazında internal/external yapı ve SD kart durumu farklıdır.
- İzinleri gerektiği kadar isteyin
  - Yalnız okuma gerekiyorsa yalnız okuma izni istenmeli; "nasılsa lazım olur" diye izin istenmemeli.
- Boş alan kontrolü
  - Büyük bir dosya indirilmeden ya da işlenmeden önce yeterli alan olup olmadığı kontrol edilmelidir; aksi hâlde hata oluşabilir.
- `apply()` ile `commit()` farkı
  - Editörle yazılan bilgi önce bellektedir; ikincil belleğe yazılması için `apply()` ya da `commit()` çağrılmalıdır.
  - `apply()` asenkron yazar: bellekten dosyaya ne zaman yazılacağı sistemin uygunluğuna bağlıdır; arayüzü bloklamadığı için genelde daha akıllıcadır. `commit()` senkron, kesintisiz (atomik) bir yazmadır.
- SharedPreferences okurken varsayılan değer
  - Aktivite ilk açıldığında dosyada değer olmayabilir; bu yüzden her okuma için varsayılan değer belirlenmelidir (örneğin oyuncu ilk kez girdiğinde skor 0).
- SharedPreferences kalıcıdır, Bundle değildir
  - Gerçekten kalıcı olması gereken, oturuma bağlı olmayan basit bilgiler için SharedPreferences "biçilmiş kaftandır"; saved instance state bu bilgileri kaybeder.

## Kısa Tekrar Notları

- Dört temel seçenek: app-specific storage, shared storage, preferences, database.
- Hassas veri: internal storage, preferences ya da Room ile veritabanı.
- `getFilesDir()`, `getCacheDir()` internal; `getExternalFilesDir()`, `getExternalCacheDir()` external app-specific dizinlerdir; uygulama kaldırılınca silinir.
- MediaStore API medya için, Storage Access Framework diğer dokümanlar için; bunlar uygulama kaldırılınca silinmez.
- Cache dizinindeki dosyaları sistem yer azalınca silebilir.
- Device File Explorer: `data/data/app_name/` internal, `sdcard/` external.
- Paylaşım: FileProvider ve Content Provider.
- `installLocation="preferExternal"` uygulamanın external storage'a kurulmasını ister.
- External storage durumu `Environment.getExternalStorageState()` ile `MEDIA_MOUNTED` / `MEDIA_MOUNTED_READ_ONLY` karşılaştırılarak kontrol edilir.
- `getSharedPreferences(ad, mod)` çok dosya, `getPreferences(mod)` aktiviteye özel tek dosya.
- Yazma: `edit()` → `putX` → `apply()` (asenkron) ya da `commit()` (senkron).
- Okuma: `getX(key, defaultValue)`.
- SharedPreferences oturumlar arası kalıcı, saved instance state yalnız aynı oturumda.
- Parcelable Android'e özgü ve hızlı, Serializable Java standardı ve basit.
- Yeni yöntem: `registerForActivityResult` + `ActivityResultLauncher.launch(intent)`; eski yöntem: `startActivityForResult` + `onActivityResult` (deprecated ama çalışıyor).

## Detaylı Açıklamalar

- **Internal ve external storage.** Android iki fiziksel yapı kullanır: internal storage ve external storage. External storage gerçek bir SD kart olabileceği gibi internal storage içinde ayrı bir bölüm (partition) ya da sanal alan da olabilir. Internal storage her zaman erişilebilirdir ve yalnız uygulama kendi dosyalarına erişir; uygulama kaldırılınca hepsi silinir. External storage (özellikle çıkarılabilir bir kartsa) her zaman erişilebilir olmayabilir, çoğu dosyası herkese açık kabul edilir ve kaldırmada yalnız `getExternalFilesDir()` ile yaratılmış dizindeki dosyalar silinir. APK boyutu büyükse uygulama external storage'a kurulabilir.

- **Cache dosyaları.** Normal dizine yazılan dosyalar uygulama silinene kadar kalır. Cache dizinine yazılan dosyaları ise Android yer kalmadığında temizleyebilir. Geçici olarak indirilen ve sürekli saklanması anlamlı olmayan dosyalar cache dizinine konursa sistemin bunları belli aralıklarla temizlemesine izin verilmiş olur. Cache dosyası external alanda da yaratılabilir.

- **Uygulamaya özel dosyaya yazma ve okuma.** Bir dosya `context.getFilesDir()` ile alınan dizinde `new File(directory, filename)` diye tanımlanır (ekrandan, 00:45:00). Yazma için `openFileOutput` ile bir `FileOutputStream` açılır ve string `getBytes()` ile byte'a çevrilerek yazılır; derste "hello world" yazan örnek gösterildi. Okuma için `FileInputStream` ile dosya açılıp `BufferedReader` ile satır satır okunur. Bu yapı Java'dan bilinen stream yapısının Android'e uyarlanmış hâlidir.

- **Ortak ve özel albüm dizini.** Slayttaki iki fonksiyonun tek farkı dizin kaynağıdır (ekrandan, 01:05:00). `getPublicAlbumStorageDir` kullanıcının herkese açık resim dizinini `Environment.getExternalStoragePublicDirectory(Environment.DIRECTORY_PICTURES)` ile; `getPrivateAlbumStorageDir` uygulamanın özel resim dizinini `context.getExternalFilesDir(Environment.DIRECTORY_PICTURES)` ile alır. Galeri gibi ortak işlemler birincisiyle, uygulamaya özel resimler ikincisiyle yapılır.

- **SharedPreferences okuma ve yazma kodu** (ekrandan, 01:15:00):

  ```java
  Context context = getActivity();
  SharedPreferences sharedPref = context.getSharedPreferences(
          getString(R.string.preference_file_key), Context.MODE_PRIVATE);

  SharedPreferences sharedPref = getActivity().getPreferences(Context.MODE_PRIVATE);
  SharedPreferences.Editor editor = sharedPref.edit();
  editor.putInt(getString(R.string.saved_high_score_key), newHighScore);
  editor.commit();   // ya da apply()

  int defaultValue = getResources().getInteger(R.integer.saved_high_score_default_key);
  int highScore = sharedPref.getInt(getString(R.string.saved_high_score_key), defaultValue);
  ```

  Hoca oyun örneğiyle anlattı: oyuncunun yüksek skoru 80 iken aktivite kapanırsa, geri döndüğünde `getInt` ile 80 okunur ve oyuncu 80'den devam eder. İlk kez giren oyuncu için dosyada değer yoktur ve varsayılan değer kullanılır.

- **SharedPreferences ile dosya erişimi.** SharedPreferences basit bir XML key-value dosyası olduğundan erişimi hızlıdır. Nesne yazılmış bir dosyayı okumak (açma, input reader ve stream yapıları) daha uzun sürer. Güçlü cihazlarda fark hissedilmeyebilir, eski cihazlarda performans farkı belirgindir.

- **Parcelable örneği** (ekrandan, 01:25:00): `Details implements Parcelable` sınıfında `name`, `age`, `phone` alanları, `Details(Parcel in)` yapıcısında `in.readString()` ile okunur. `CREATOR`'daki `createFromParcel` `new Details(in)`, `newArray(int size)` `new Details[size]` döndürür. `describeContents()` 0 döndürür, `writeToParcel` içinde `dest.writeString(name)`, `dest.writeString(age)`, `dest.writeString(phone)` yazılır. Okuma sırası yazma sırasıyla aynıdır.

- **Kamera ve ActivityResultLauncher** (ekrandan, 01:40:00): Butona basılınca önce `askCameraPermissions()` çalışır; izin manifest'te yoksa çalışma zamanında istenir. Sonra `new Intent(MediaStore.ACTION_IMAGE_CAPTURE)` oluşturulur, `intent.resolveActivity(getPackageManager()) != null` ise `activityResultLauncher.launch(intent)` çağrılır, değilse "There is no app that support this action" Toast'u gösterilir. Dönüşte callback'in `onActivityResult(ActivityResult result)` metodunda `result.getResultCode() == RESULT_OK && result.getData() != null` kontrol edilir; `result.getData().getExtras()` ile alınan Bundle'dan `(Bitmap) bundle.get("data")` alınır ve `selectedImage.setImageBitmap(bitmap)` ile gösterilir.

- **Kamera ile dosyaya kaydetme** (ekrandan, 02:00:00 ve 02:05:00): `createImageFile()` dosya adını `new SimpleDateFormat("yyyyMMdd_HHmmss").format(new Date())` ile üretilen zaman damgasından kurar (`"JPEG_" + timeStamp + "_"`), dizini `Environment.getExternalStoragePublicDirectory(Environment.DIRECTORY_PICTURES)` olarak alır ve `File.createTempFile(imageFileName, ".jpg", storageDir)` ile dosyayı yaratır; `currentPhotoPath = image.getAbsolutePath()` saklanır. `dispatchTakePictureIntent()` dosyayı yaratır, `FileProvider.getUriForFile(this, "com.example.android.fileprovider", photoFile)` ile URI'yi alıp intent'e ekler ve `startActivityForResult` ile gönderir. `onActivityResult` içinde `requestCode == CAMERA_REQUEST_CODE` ve `resultCode == Activity.RESULT_OK` ise `new File(currentPhotoPath)` açılır, `selectedImage.setImageURI(Uri.fromFile(f))` ile gösterilir ve dosyanın yeri `Log.d` ile Logcat'e yazılır. Önceki örnekten farkı: orada veri intent'ten Bitmap olarak alınıp yalnız gösteriliyordu; burada dosya kaydedilip açılıyor ve oradan gösteriliyor.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
