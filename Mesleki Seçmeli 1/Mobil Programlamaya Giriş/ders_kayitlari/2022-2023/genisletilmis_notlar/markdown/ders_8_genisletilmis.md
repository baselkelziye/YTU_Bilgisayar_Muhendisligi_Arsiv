# Ders 8 Genişletilmiş Notu: Veri Saklama: Dosya Depolama, SharedPreferences, Parcelable ve Kamera Örnekleri

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Neden Kalıcı Veri Saklama?
- 2. Android'de Veri Saklama Seçenekleri
- 3. Hangi Yöntemi Seçmeli?
- 4. Karşılaştırma Tablosu ve İzinler
- 5. Device File Explorer, Content Provider ve Cache
- 6. Dosyalarla Çalışırken İyi Uygulamalar
- 7. Veritabanı ve Room
- 8. Internal ve External Storage Farkları
- 9. Okuma, Yazma ve Dizin İşlemleri
- 10. External Storage'ın Kontrolü ve İzinler
- 11. MediaStore, Storage Access Framework ve BlobStoreManager
- 12. SharedPreferences
- 13. Uygulamalar Arası Veri Gönderme
- 14. Serializable ve Parcelable
- 15. Android Studio: Kamera ile Fotoğraf Alma (ActivityResultLauncher)
- 16. Android Studio: Fotoğrafı Dosyaya Kaydetme
- 17. Android Studio: SharedPreferences Uygulaması
- Örnek Sorular
- Dersin Toparlaması

## 1. Neden Kalıcı Veri Saklama?

Önceki derslerde daha temel yapılar konuşulmuştu: aktivite, aktivitenin layout'u, bir aktiviteden diğerine geçiş, veri taşıma ve Bundle nesnesinde saklanan veriye hangi şartlarda yeniden ulaşılabileceği. Bu derste ise uygulamadan çıkıldığında ya da telefon kapatıldığında da korunması istenen verinin kalıcı olarak nasıl depolanacağı konuşulur. Hoca konunun geniş olduğunu ve bütün ayrıntılarıyla verilemese de dersin tamamını kaplayacağını söyledi.

## 2. Android'de Veri Saklama Seçenekleri

Slayttaki genel bakış dört kavramı sıralar (ekrandan, 00:20:00):

- **App-specific storage:** Yalnız uygulamanın kullanacağı dosyalar; internal storage içindeki ayrılmış dizinlerde ya da external storage içindeki ayrılmış dizinlerde tutulur. Diğer uygulamaların erişmemesi gereken hassas bilgi internal storage'daki dizinlere yazılır.
- **Shared storage:** Uygulamanın diğer uygulamalarla paylaşmak istediği dosyalar: medya, dokümanlar ve diğer dosyalar.
- **Preferences:** Özel, ilkel (primitive) verilerin key-value çiftleri olarak saklanması.
- **Databases:** Yapısal verilerin Room persistence kütüphanesiyle özel bir veritabanında saklanması.

Hoca bunları şöyle açıkladı. Android iki fiziksel yapıyla çalışır: internal storage ve external storage. External storage bazen ayrı bir SD kart değil, telefonun üzerinde ayrı bir bölüm (partition) olarak bulunur. Uygulamaya özel bilgiler ağırlıklı olarak internal storage'da saklanır, çünkü internal storage'da veri saklamanın güvenlik seviyesi çok daha yüksektir. External storage fiziksel olarak çıkarılabilen bir SD kartsa, üzerinde uygulamaya özel bilgi tutmak istenen bir durum değildir. Ancak yer kısıtı, uygulamanın büyük olması ya da uygulamanın herkesin erişebildiği video, fotoğraf, PDF gibi dosyalara ihtiyaç duyması durumunda bazı şartlarda external storage kullanılabilir.

Herkesin erişebildiği dosyalar shared storage kavramıyla saklanır: medya dosyaları, dokümanlar ve diğer dosyalar. Örneğin birçok galeri uygulamasına telefondaki fotoğraflara erişim izni verilir ve hepsi o ortak alandaki fotoğraflara erişir. Aynısı şarkılar, videolar ve indirilen dosyalar için de geçerlidir. Bu alanlar uygulamaya özel değildir ve bunlar için ayrı API'ler vardır.

Daha ilkel veri tipleri için, kullanıcı tercihleri gibi basit bilgiler key-value olarak SharedPreferences yapısı ve Preferences API ile saklanır. Yapısal bir veriden söz ediliyorsa ilişkisel veritabanı kavramı devreye girer: Room persistence kütüphanesi üzerinden SQLite ile bir veritabanı oluşturulup veriler oraya yerleştirilir. Bunlar telefon üzerinde saklanan yapılardır. Ağ tarafında ise Google'ın sunduğu Firebase ya da kendi backend'inizdeki bir bulut mimarisi veya veritabanı da veri saklamak için kullanılabilir.

## 3. Hangi Yöntemi Seçmeli?

Hoca, uygulama yazarken sorulması gereken bazı sorulara verilen cevaba göre yöntem seçildiğini anlattı.

- **Ne kadar alan gerekiyor?** Internal storage'ın bir limiti vardır. Uygulamanın büyük bir alana ihtiyacı varsa ya da ortak dosya kullanımı çoksa external storage'a yönlenilir. Uygulamaya özel kısımlar internal storage'a, geri kalanlar ise ileride görülecek MediaStore API ya da Storage Access Framework üzerinden yerleştirilir.
- **Veri uygulamaya özel mi (should the data be private to your app)?** Kritik bilgiler saklanıyorsa bunların tartışmasız internal storage'a ya da internal storage'daki dosya veya veritabanı alanına yazılması beklenir. Hassas veri (sensitive data) için internal storage, preferences ya da veritabanı seçilir: ilkel veri tipleri için preferences, yapısal veri için veritabanı, dosya kullanılacaksa internal storage.

SharedPreferences'taki bilgiler yarı yapısal (semi-structured) olarak da adlandırılır ve bir XML dosyası içinde key-value çiftleri hâlinde saklanır.

> **Hocanın vurgusu:** Kritik bilgiler saklanıyorsa bunların tartışmasız internal storage'a ya da oradaki dosya veya veritabanı alanına yazılması beklenir.

## 4. Karşılaştırma Tablosu ve İzinler

Slayttaki tablo (ekrandan, 00:25:00) içerik türlerini erişim yöntemi, gereken izin, diğer uygulamaların erişimi ve kaldırmada silinme bakımından karşılaştırır:

| İçerik | Tür | Erişim yöntemi | Gereken izin | Diğer uygulamalar erişir mi? | Kaldırınca silinir mi? |
|---|---|---|---|---|---|
| App-specific files | Yalnız uygulamanın kullandığı dosyalar | Internal: `getFilesDir()`, `getCacheDir()`; External: `getExternalFilesDir()`, `getExternalCacheDir()` | Internal için hiç gerekmez; external için Android 4.4 (API 19) ve üzerinde gerekmez | Hayır | Evet |
| Media | Paylaşılabilir medya (resim, ses, video) | MediaStore API | Android 11 (API 30)+: diğer uygulamaların dosyaları için `READ_EXTERNAL_STORAGE`; Android 10 (API 29): `READ_EXTERNAL_STORAGE` ya da `WRITE_EXTERNAL_STORAGE`; Android 9 (API 28) ve altı: bütün dosyalar için izin | Evet, diğer uygulamanın `READ_EXTERNAL_STORAGE` izni olmalı | Hayır |
| Documents and other files | İndirilen dosyalar dahil diğer paylaşılabilir içerik | Storage Access Framework | Yok | Evet, sistem dosya seçicisiyle | Hayır |
| App preferences | Key-value çiftleri | Jetpack Preferences kütüphanesi | Yok | Hayır | Evet |
| Database | Yapısal veri | Room persistence kütüphanesi | Yok | Hayır | Evet |

Hoca tabloyu satır satır anlattı. App-specific dosyalarda internal storage'da `getFilesDir()` ve `getCacheDir()`, external storage'da `getExternalFilesDir()` ve `getExternalCacheDir()` metotlarıyla dizine ulaşılır. Burada yaratılan dosya ve dizinlere başka uygulamalar erişemez. Uygulama kaldırıldığında buradaki bütün bilgiler telefondan silinir; Android bunu garanti eder, bu yüzden kaldırma sırasında ayrıca bir şey yapmaya gerek yoktur.

Paylaşılabilir medya dosyaları (fotoğraf, video, ses) için MediaStore API kullanılır ve özellikle Android 10, 11 ve üzerinde çeşitli izinlerin alınması beklenir: Read External Storage ve Write External Storage. Android 11 ile birlikte Manage External Storage izni de gelmiştir. Bu izin bütün external alanda iş yapmayı sağlar ve gerçekten o alandaki dosyalarla ilgisi olan yedekleme, sıkıştırma gibi dosya yönetimine yatkın uygulamaların alması beklenir. Diğer uygulamalar bu izni istediğinde kullanıcılar genelde vermek istemez, Android de bunu tavsiye etmez. Paylaşılan alandaki dosyalar uygulama kaldırıldığında silinmez.

Medya dışında indirilen PDF ve benzeri dosyaların paylaşımı için Storage Access Framework kullanılır. Burada da uygulama kaldırılınca dosyalar silinmez; diğer uygulamalar sizin uygulamanızın yarattığı dosyalara erişebilir, ama burada üretilen dosyalar özel bir izne tabi değildir.

Key-value çiftleri ve ilkel veri tipleri için iki yapı vardır: SharedPreferences ve Android'in sunduğu yeni Jetpack Preferences kütüphanesi. İkisi de key-value saklayabilir. Veritabanında ise Room kütüphanesi üzerinden gerekli modeller kurgulanarak veri saklanır.

## 5. Device File Explorer, Content Provider ve Cache

### 5.1 Device File Explorer

Device File Explorer, telefonun dosya sisteminde yaratılan ya da bulunan dosyalara erişmeyi sağlayan Android Studio aracıdır. Bütün dosyaların izinleri, ne zaman yaratıldıkları, boyutları ve adları görülür. Slayta göre View > Tool Windows > Device File Explorer ile ya da araç penceresi çubuğundaki Device File Explorer düğmesiyle açılır (ekrandan, 00:30:00). Slaytta özellikle iki dizin önemli diye belirtilir:

- `data/data/app_name/`: uygulamanın internal storage'daki veri dosyaları.
- `sdcard/`: external user storage'daki kullanıcı dosyaları (resimler vb.).

Hoca, data klasörünün altında uygulamanın adına özel bir klasör yaratıldığını ve uygulamaya özel bütün dosyaların internal storage'da buraya yerleştirildiğini anlattı. External storage'daki bir bilgiye SD kartın altında yaratılan dosyalarla erişilir; bu SD kart gerçek olabilir ya da internal storage içinde sanal bir alan olarak karşınıza çıkabilir. Internal storage'da bir veri arandığında ilk bakılacak yer, data klasörünün altındaki uygulama adına denk gelen klasördür.

### 5.2 Content Provider

Bir uygulamanın diğer uygulamalarla veri paylaştığı senaryoda bu paylaşım genellikle Content Provider üzerinden yapılır. Daha önce söylendiği gibi telefondaki kişilerin bilgilerine erişmek için Content Provider kullanılır. Kendi uygulamanız da gerekli tanımları yaparak Content Provider üzerinden diğer uygulamalara veri sunabilir; başka bir uygulamanın paylaştığı veriye de yine Content Provider üzerinden erişilir.

### 5.3 Varsayılanlar ve cache

Varsayılan ayarlarda, değişiklik yapılmadıysa indirilen uygulama internal storage'a kurulur, dosyaları oraya yüklenir, diğer uygulamalar bunlara erişemez ve uygulama kaldırılınca her şey silinir.

Saklanacak bilgiler istenirse cache dosyalarına konabilir. Hoca farkı şöyle açıkladı: cache dizini kullanmadan yaratılan dosyalar uygulama silinene kadar kalır. Cache dizini yaratılıp veri oraya konursa, Android uygun görürse (yer kalmaması durumunda) cache'i belli periyotlarla temizleme hakkına sahiptir. Geçici olarak indirilen ve sürekli saklanması anlamlı olmayan dosyalar varsa bunları bir cache dizinine koymak daha akıllıcadır; böylece Android'in bunları belli aralıklarla temizlemesine izin verilmiş olur.

### 5.4 External storage'ın riski

External storage her zaman bir risk barındırır. Android 10 ve 11 ile önlemler alınmış ve çeşitli ayarlar getirilmiş olsa da, fiziksel olarak çıkarılabilir bir yapıdan söz ediliyorsa buradaki bilgiler hiçbir zaman tam anlamıyla güvenli sayılamaz. Çok kritik kişisel veri barındırmayan uygulamalar gönül rahatlığıyla buraya konabilir. Ama bankacılık gibi uygulamaların buraya kurulmasını istemek, yani kullanıcıyı buna zorlamak, kullanıcıyı uygulamayı indirmekten vazgeçirecek noktaya kadar götürebilir.

## 6. Dosyalarla Çalışırken İyi Uygulamalar

Slayttaki "Best Practices for Operating on Files" maddeleri (ekrandan, 00:35:00):

- Dosyaları tekrar tekrar açıp kapatmayın (Don't open and close files repeatedly).
- Tek tek dosyaları paylaşın (Share individual files): FileProvider ve Content Provider.
- Device File Explorer.
- Uyarı: dosyaların kaydedilebileceği tam konum cihazdan cihaza değişebilir; bu yüzden hardcoded dosya yolu kullanmayın.

Hoca bunları açıkladı. Dosyalar mümkünse bir kez açılmalı, iş yapılmalı, kapatılmalı; sürekli aç-kapa yapmamak kaynaklar açısından önemlidir. Dosyaların başka uygulamalarla paylaşılmasında iki temel yaklaşım vardır: FileProvider ve Content Provider. Sanal ya da fiziksel cihazdaki dosyalara erişim Device File Explorer üzerinden yapılır. Dosya yollarının hardcoded olmaması önerilir, çünkü her üretici firmanın cihazı farklı bir yapıya sahip olabilir: external storage internal kısımda olabilir, SD kart olabilir ya da olmayabilir.

Uygulamanın doğrudan external storage'a kurulması isteniyorsa manifest'te `installLocation` özelliği `preferExternal` olarak belirlenir (ekrandan, 00:35:00):

```xml
<manifest ...
  android:installLocation="preferExternal">
  ...
</manifest>
```

Slayttaki nota göre uygulama çalışma zamanında depolamayla ilgili bir izin isterse, scoped storage etkin olsa bile kullanıcıya gösterilen diyalog uygulamanın external storage'a geniş erişim istediğini belirtir.

> **Ders sonrası not:** Hoca `preferExternal` ile kurulum aşamasında kullanıcıya sorulduğunu ve kullanıcı kabul ederse uygulamanın oraya kurulduğunu söyledi. Android belgelerine göre büyük olasılıkla kurulumda kullanıcıya ayrıca sorulmaz; `preferExternal` yalnız bir tercihtir, sistem external storage uygunsa oraya kurar, değilse ya da doluysa internal storage'a kurar. Kullanıcı uygulamayı daha sonra ayarlardan taşıyabilir.

Hoca ayrıca slaytta Android 10 ve üzerinde internal storage'daki bilgilere yalnız diğer uygulamaların erişememesinin değil, bu dosyaların şifrelenmesinin de belirtildiğini söyledi. Yani Android 10 ve üzerinde güvenlik bir kademe daha artırılmıştır; Android bu anlamda iOS tarafındaki gelişen güvenlik seviyesine ayak uydurmaya çalışır. Ortak kullanım söz konusuysa kalıcı ve paylaşılabilir dosyalar için external storage önerilir.

## 7. Veritabanı ve Room

Slayttaki "Databases" bölümü (ekrandan, 00:40:00) önce seçenekleri yeniden sıralar: internal file storage (cihaz dosya sisteminde uygulamaya özel dosyalar), external file storage (paylaşılan external dosya sisteminde, genellikle fotoğraf gibi paylaşılan kullanıcı dosyaları), shared preferences (özel ilkel verileri key-value çiftleri olarak saklama) ve databases (yapısal veriyi özel bir veritabanında saklama). Ardından dört madde gelir:

- Android SQLite veritabanlarını tam olarak destekler.
- Yaratılan her veritabanına yalnız sizin uygulamanız erişebilir.
- SQLite API'lerini doğrudan kullanmak yerine veritabanlarını Room persistence kütüphanesiyle yaratmak ve kullanmak önerilir.
- Room kütüphanesi, SQLite'ın bütün gücünü kullanırken akıcı veritabanı erişimi sağlayan bir nesne eşleme (object-mapping) soyutlama katmanı sunar.

Hoca, Room'un uzun yıllardır SQLite API'sinin karmaşıklığını basitleştirerek verilerin yapısal olarak depolanmasını sağladığını ve bu nesne eşleme katmanının işi oldukça kolaylaştırdığını söyledi.

SharedPreferences tarafında ise bilgiler bir XML dosyasında key-value olarak yazılır. Java'da nesne olarak geçen String dışında ilkel veri tipleri bu yapıda ikililer hâlinde saklanır ve dosya erişimine göre çok daha hızlı okunur. Bu yüzden uygulamaya özgü çok basit bilgilerin bu yapıda tutulması önerilir. Uygulamaya genel tek bir dosya yerine aktivite bazında, o aktiviteye ait bilgileri saklayan SharedPreferences dosyaları da yaratılabilir.

## 8. Internal ve External Storage Farkları

Hoca farkları listeledi:

- Internal storage her zaman erişilebilirdir. External storage, özellikle SD kart gibi fiziksel bir yapıdaysa, erişilemez olma potansiyeli her zaman taşır.
- Internal storage'daki dosyalara yalnız uygulamanız erişir. External storage'daki bilgilerin çoğunluğu herkes tarafından erişilebilir kabul edilir.
- Uygulama kaldırıldığında internal storage'daki bütün dosyalar silinir. External storage'da ise yalnız `getExternalFilesDir()` ile yaratılan dizindeki dosyalar silinir, diğerleri silinmez. Bu yüzden external tarafta da `getExternalFilesDir()` ile kademeli de olsa bir güvenlik seviyesi sağlanmış olur.
- Nereye kurulacağı manifest'teki install location ile belirtilir. APK boyutu büyükse internal storage yerine external storage kullanılabilir.

## 9. Okuma, Yazma ve Dizin İşlemleri

### 9.1 Uygulamaya özel dosya yaratma ve yazma

Uygulama içinde app-specific bir dosya yaratmak için bir `File` nesnesi kullanılır. `context` bulunulan uygulamanın bağlamıdır; `context.getFilesDir()` ile alınan dizine dosya adı verilerek dosyanın uygulamanın `data/data` klasörünün altında yaratılması sağlanır. Dizin işlemleri slaytında bu kod şöyle yer alır (ekrandan, 00:45:00):

```java
File directory = context.getFilesDir();
File file = new File(directory, filename);
```

Bunun için bir dosya adı belirlenir. İçine yazılacak içerik bir string, byte bilgisi ya da nesne olabilir; bunun için Java'nın sunduğu stream API'leri vardır. Derste gösterilen örnekte `openFileOutput` ile açılan bir `FileOutputStream`'e "hello world" ifadesi byte'a dönüştürülerek yazılıyordu. Bu, Java'daki yapının küçük değişikliklerle Android'e uyarlanmış hâlidir.

<!-- BELİRSİZ: 00:38 civarındaki openFileOutput / FileOutputStream kodunun tam metni karede yok; yalnız altyazıdan anlatıldı. -->

### 9.2 Dosyadan okuma

Okuma-yazma slaytında iki durum vardır: biri dosyaya yazma, diğeri `FileInputStream` ile dosyadan okuma. Okumada, Java'dan bilinen input stream'ler üzerinden adı verilen dosyaya ulaşılır, dosya açılır ve içindeki bilgiler `BufferedReader` ile satır satır okunur. Hoca bunun alışılmış bir okuma-yazma yapısı olduğunu ve Android'de de aynen karşınıza çıktığını söyledi.

### 9.3 Geçici ve cache dosyaları

Geçici dosya ve cache dosyası üretmenin farklı yolları vardır. `File.createTempFile` kullanılabilir ya da bir `File` nesnesiyle cache dosyasının adı verilip `getCacheDir()` dizininde dosya yaratılabilir. Cache dosyası `cacheFile.delete()` ile ya da `context.deleteFile(cacheFileName)` ile silinir. Bulunulan dizindeki dosyaların listesi `context.fileList()` ile alınır.

### 9.4 Dizin işlemleri

Slayttaki "Directory Operations" (ekrandan, 00:45:00):

- `getFilesDir()`: uygulamanın internal dizinini temsil eden bir `File` döndürür; uygulamayla benzersiz biçimde ilişkili dizindir.
- `getCacheDir()`: uygulamanın geçici cache dosyaları için internal dizini döndürür. Her dosya artık gerekmediğinde silinmeli ve kullanılan bellek için makul bir boyut sınırı (örneğin 1 MB) uygulanmalıdır. Bu dizin geçici dosyalar içindir ve düzenli temizlenmelidir; disk alanı azalınca sistem buradaki dosyaları silebilir, bu yüzden okumadan önce cache dosyalarının varlığı kontrol edilmelidir.
- `getDir(name, mode)`: uygulamanın dosya sistemi dizini içinde yeni bir dizin yaratır (ya da var olanı açar); bu dizin `getFilesDir()`'in verdiği dizinin içinde görünür.
- Bu dizinlerden birinde yeni dosya yaratmak için `File()` yapıcısına bu metotlardan birinin verdiği `File` nesnesi geçirilir.

Hoca `getCacheDir()` ile çalışırken genelde 1 MB civarında bir dosya boyutundan söz edildiğini vurguladı.

### 9.5 Birden çok external storage volume

Bir kod parçası birden fazla external storage volume olabileceğini vurgular: internal storage'dan sonra internal kısımda yer alan bir external storage ve ayrıca fiziksel bir SD kart olabilir. Hoca, 0 indisli external storage volume üzerinde çalışmanın önerildiğini söyledi, çünkü bu bölgenin telefonun içinde bir konumda yer alma olasılığı yüksektir. Telefonun içinde, fiziksel olarak sökülemeyecek bir parçada konumlanmak daha avantajlıdır. Cache dosyası yalnız internal alanda değil, external alanda da yaratılabilir.

### 9.6 Boş alan kontrolü

Hoca bir kod parçasının ne yaptığını sordu (bkz. Örnek Sorular, Soru 1). Kod 10 MB'lık bir alan olup olmadığını kontrol ediyor ve böyle bir alan yoksa yapılması gereken işlemler için alan açmaya çalışıyordu. Bu kontrol şu yüzden önemlidir: indirilen ya da üzerinde çalışılacak dosyanın boyutu büyük olabilir; Storage Manager üzerinden bakıldığında internal storage'da, belki son indirilen uygulamayla, çok az alan kalmış olabilir. Yalnız dosya açmak ve silmek değil, mevcut durumu kontrol etmek de beklenir; aksi hâlde hata oluşabilir. Hoca bunu, intent gönderirken işi yapacak bir uygulamanın var olup olmadığına bakılmasına benzetti: orada da işten bağımsız olarak ek bir kontrol kodu konuyordu, burada da bir bellek kontrolü yapılması tavsiye edilir.

<!-- BELİRSİZ: 00:47 civarında gösterilen boş alan kontrol kodu karelerde yok; kodun tam metni ve kullanılan StorageManager metotları doğrulanamadı. -->

## 10. External Storage'ın Kontrolü ve İzinler

### 10.1 İzinler

External storage'a yazmak için ilgili izinlerin alınması gerekir. Genellikle okuma ve yazma izinlerinin ikisinin de alınması tavsiye edilir, ama her zaman external storage'a yazma gerekmeyebilir; yalnız oradaki ortak dosyalara erişim söz konusuysa Read External Storage izni yeterlidir. Yalnız okuma gerekirken yazma izni de istemek kullanıcıyı rahatsız edebilir ve şüphelendirebilir. Hoca, "nasıl olsa lazım olur" diye ihtiyaç dışında izin istenmemesini, gerçekten kullanılacaksa, hatta manifeste yazmak yerine ihtiyaç anında çalışma zamanında (runtime) istenmesini daha mantıklı buldu.

> **Hocanın vurgusu:** Mümkün olduğunca ihtiyaç duyulan izinlerin ötesinde izin istenmemelidir; gereksiz izin, kullanıcıyı şüphelendirir.

### 10.2 External storage var mı, okunabilir mi, yazılabilir mi?

External storage'ın var olup olmadığı da kontrol edilmelidir. Slayttaki kod (ekrandan, 01:05:00):

```java
/* Checks if external storage is available for read and write */
public boolean isExternalStorageWritable() {
    String state = Environment.getExternalStorageState();
    if (Environment.MEDIA_MOUNTED.equals(state)) {
        return true;
    }
    return false;
}

/* Checks if external storage is available to at least read */
public boolean isExternalStorageReadable() {
    String state = Environment.getExternalStorageState();
    if (Environment.MEDIA_MOUNTED.equals(state) ||
        Environment.MEDIA_MOUNTED_READ_ONLY.equals(state)) {
        return true;
    }
    return false;
}
```

`Environment.getExternalStorageState()` ile durum alınır; gerçekten bir external storage olup olmadığı, okuma ve yazma modunda olup olmadığı kontrol edilir. Aynı slaytta dosya silme için iki yol yer alır: `myFile.delete();` ve `myContext.deleteFile(fileName);`.

### 10.3 Ortak alan ile uygulamaya özel alan

Aynı slaytın alt kısmındaki iki fonksiyonun temel farkı, birinin ortak bir alana, diğerinin uygulamaya özel bir alana erişmesidir (ekrandan, 01:05:00):

```java
public File getPublicAlbumStorageDir(String albumName) {
    // Get the directory for the user's public pictures directory.
    File file = new File(Environment.getExternalStoragePublicDirectory(
            Environment.DIRECTORY_PICTURES), albumName);
    if (!file.mkdirs()) {
        Log.e(LOG_TAG, "Directory not created");
    }
    return file;
}

public File getPrivateAlbumStorageDir(Context context, String albumName) {
    // Get the directory for the app's private pictures directory.
    File file = new File(context.getExternalFilesDir(
            Environment.DIRECTORY_PICTURES), albumName);
    if (!file.mkdirs()) {
        Log.e(LOG_TAG, "Directory not created");
    }
    return file;
}
```

`getExternalStoragePublicDirectory` ile ortak alana ulaşılır ve albüm ya da galeri işlemleri burada yürütülür. `getExternalFilesDir` ile uygulamanın özel resimleri saklanır. External storage içinde bu iki ayrıma dikkat edilerek, ihtiyaca göre uygulamaya özel bir alan yaratılır ya da ortak alan kullanılır.

Hoca ayrıca `getFreeSpace()` ve `getTotalSpace()` metotlarıyla alan bilgisi alınabileceğini ve external storage'da `getExternalFilesDir()` ile yaratılan dosyaların uygulama kaldırıldığında mutlaka silineceğini hatırlattı.

## 11. MediaStore, Storage Access Framework ve BlobStoreManager

Video ya da fotoğraflara erişmek için MediaStore API'ye bakılabilir. PDF ve benzeri dosyalar için kullanılacak yapılar Storage Access Framework üzerinden sunulur.

Bir de veri setleri vardır. Android 11'den itibaren BlobStoreManager, uygulamanızın ya da başka uygulamaların kullanabileceği veri setlerini kullanıma açar. Hoca bunun özellikle makine öğrenmesi açısından değerli olduğunu söyledi: telefonlara federated learning kavramı geldikten sonra telefonlar bazı öğrenme yetenekleri gösterebiliyor. Dağıtık yapıda ya da cihazın kendi üzerinde, çok büyük veri kullanmadan bu veri setleri telefona yerleştirilebiliyor. Bu da Android 11 ile BlobStoreManager'ı hayatımıza sokuyor.

## 12. SharedPreferences

### 12.1 İki metot

SharedPreferences API'de iki metot vardır:

- `getSharedPreferences(...)`: birden fazla SharedPreferences dosyası yaratılacaksa kullanılır. Hangi dosyanın yaratıldığını belirtmek için bir parametre daha (dosya adı) gönderilir.
- `getPreferences(...)`: aktiviteye özel tek bir preferences dosyası yaratılacaksa kullanılır; tek dosya olduğu için dosya adı gönderilmez.

### 12.2 SharedPreferences ile saved instance state farkı

Slayttaki karşılaştırma (ekrandan, 01:10:00):

| SharedPreferences | Saved instance state |
|---|---|
| Veriyi kullanıcı oturumları arasında, uygulama öldürülüp yeniden başlatılsa ya da cihaz yeniden başlatılsa bile korur | Durum verisini aynı kullanıcı oturumundaki aktivite örnekleri arasında korur |
| Oturumlar arasında hatırlanması gereken veri: kullanıcının tercih ettiği ayarlar, oyun skoru | Oturumlar arasında hatırlanmaması gereken veri: o an seçili sekme, aktivitenin o anki durumu |
| Yaygın kullanım: kullanıcı tercihlerini saklamak | Yaygın kullanım: cihaz döndürüldükten sonra durumu yeniden kurmak |

Hoca, saved instance state'te Bundle nesnesinin verileri yalnız kullanıcı oturumu açık olduğu sürece saklamayı taahhüt ettiğini hatırlattı. Uygulama kill edildiğinde, yeniden başladığında ya da cihaz reboot olduğunda bilgilerin kaldığı yerden devam edebilmesi için SharedPreferences kullanılması önerilir; saved instance state bu durumda bilgileri kaybeder. Gerçekten kalıcı olması istenen ve oturuma bağlı olmayan bilgiler için SharedPreferences "biçilmiş kaftandır". Kullanıcı tercihleri, kullanıcı bilgileri ve oyun durumu gibi bilgilerin SharedPreferences'ta saklandığı örnekler sıktır. Saved instance state ise ağırlıklı olarak aktivitenin o anki (current) durumunu tutmaya yöneliktir.

SharedPreferences'ı ayıran en önemli fark, kalıcı basit bilgileri saklamak için bir XML dosya formatı sunması ve key-value mantığı çok basit olduğu için bilgilere çok hızlı erişim sağlamasıdır. Nesne yazılmış bir dosyaya erişmek daha uzun sürer: dosyanın açılması, okunması, input reader ve stream yapıları verinin getirilmesini uzatır. Çok güçlü cihazlarda bu fark edilmeyebilir, ama özellikle eski tip cihazlarda en büyük fark performans olarak karşınıza çıkar.

### 12.3 Yazma

Slayttaki kod (ekrandan, 01:15:00):

```java
Context context = getActivity();
SharedPreferences sharedPref = context.getSharedPreferences(
        getString(R.string.preference_file_key), Context.MODE_PRIVATE);
```

Önce bağlam (context) bilgisi alınır, `SharedPreferences` tipinde bir nesne tanımlanır. `getSharedPreferences`'ın ilk parametresi kullanılacak dosya adıdır; burada `strings.xml`'den alınan bir ad vardır, ama bu ad kullanıcıdan da alınabilir. Dosya private modda açılır. Alttaki satırda ise `getPreferences` ile tek bir dosya açıldığı için dosya adı gönderilmez:

```java
SharedPreferences sharedPref = getActivity().getPreferences(Context.MODE_PRIVATE);
```

SharedPreferences nesnesi yaratıldıktan sonra ona bağlı bir editör yaratılır ve bilgiler editör aracılığıyla yazılır:

```java
SharedPreferences sharedPref = getActivity().getPreferences(Context.MODE_PRIVATE);
SharedPreferences.Editor editor = sharedPref.edit();
editor.putInt(getString(R.string.saved_high_score_key), newHighScore);
editor.commit();
```

Slaytta `commit()`'in yanında alternatif olarak `apply()` da yazılıdır. Editöre key-value mantığıyla hangi bilgilerin yükleneceği belirtilir: `putInt`, `putString`, `putBoolean` gibi metotlarla birden fazla değer yüklenebilir. Hoca önemli bir noktayı vurguladı: editörle yazılan bilgiler bellek alanında durur; ikincil belleğe (secondary storage) yazılmaları için `commit()` ya da `apply()` çağrılması gerekir.

### 12.4 apply() ile commit() farkı

Hoca bu farkı öğrencilere sordu (bkz. Örnek Sorular, Soru 2). Biri senkron, diğeri asenkron yazar. `apply()` dendiğinde asenkron bir yazma söz konusudur: bilgi editörle bellek alanına yazılır, ama dosyaya ne zaman yazılacağı (30 milisaniye sonra mı, 1 saniye sonra mı) belirsizdir ve o anda sistemin uygunluğuna bağlıdır. Çok geç bir süreden söz edilmez; ancak fazla bilgi yazılıyorsa kullanıcının arayüzle ilişkisini bölmemek için bu işi asenkron yaptırmak genellikle daha akıllıcadır. Sisteme "bunları belleğe yaz, uygun bir zamanda ikincil belleğe yazarsın" denmiş olur. `commit()`'te ise senkron, atomik ve kesintisiz bir yazma vardır: belleğe yazıldıktan hemen sonra ikincil belleğe de yazılması gerekir.

> **Ek bilgi (derste anlatılmadı):** `commit()` yazmanın başarılı olup olmadığını `boolean` olarak döndürür ve çağrıldığı thread'i yazma bitene kadar bekletir; bu yüzden ana thread'de büyük yazmalar için önerilmez. `apply()` ise değişikliği hemen bellekteki kopyaya uygular, diske yazmayı arka planda yapar ve bir sonuç döndürmez.

### 12.5 Okuma ve varsayılan değer

Slayttaki okuma kodu (ekrandan, 01:15:00):

```java
SharedPreferences sharedPref = getActivity().getPreferences(Context.MODE_PRIVATE);
int defaultValue = getResources().getInteger(R.integer.saved_high_score_default_key);
int highScore = sharedPref.getInt(getString(R.string.saved_high_score_key), defaultValue);
```

Okurken yine bir SharedPreferences nesnesi yaratılır, ama bu sefer editör yaratılmaz. Bilginin hangi key ile alınacağı söylenir. Varsayılan değer (default value) kısmı, bir değer okunamazsa hangi değerin kullanılacağını belirtir. Hoca önce bu kısmı yanlış anlattığını belirtip düzeltti: değer gelmezse (hiç yazılmamışsa) varsayılan değer kullanılır; burada varsayılan değer bir integer kaynağından XML üzerinden çekilir, örneğin sıfır.

Hocanın oyun örneği: oyuncunun yüksek skoru aktivite sonlandığında 80 ise, geri döndüğünde `getInt` ile key-value üzerinden 80 çekilir ve oyuncu 80'den devam eder. Oyuncu oyuna ilk kez girdiyse SharedPreferences'tan bir değer gelmez ve otomatik olarak varsayılan değer kullanılır; oyuncu hanesinde varsayılan değere ne atandıysa onu görür.

> **Hocanın vurgusu:** SharedPreferences'taki veriler aktivite her çalıştığında okunmalıdır. İlk açılışta orada veri olmayabileceği için, verinin olmaması durumunda kullanılacak varsayılan değerleri sizin belirlemeniz gerekir. Buna dikkat edilirse hata ile karşılaşılmaz.

### 12.6 Diğer metotlar ve Preferences kütüphanesi

SharedPreferences'ta kullanılabilecek metotlar arasında `getInt`, `getFloat`, `getLong`, `getString`, bütün değerleri çeken `getAll`, `edit`, ve editörün `putInt`, `putString`, `putLong` gibi metotları vardır.

Preferences kütüphanesi biraz farklıdır: Jetpack ile gelen yeni bir yapıdır ve preferences'ın aynısını hizmet olarak sunar. Hoca, `onActivityResult` örneğinde olduğu gibi Android'in zamanla yeni yapılar sunduğunu, bunların eski yapıların yerini yavaş yavaş aldığını hatırlattı. Bazı API'ler deprecated olur; bir süre kullanılmasına izin verilir ama belli bir versiyondan sonra izin verilmez. Önümüzdeki yıllarda Preferences API'nin daha sık kullanılacağının görüldüğünü, buna da bakılmasında fayda olduğunu söyledi.

> **Ek bilgi (derste anlatılmadı):** Jetpack Preference kütüphanesi daha çok ayarlar ekranı arayüzü kurmak içindir ve değerleri yine SharedPreferences'ta tutar. Google'ın SharedPreferences'ın yerine önerdiği daha yeni Jetpack bileşeni DataStore'dur; key-value için Preferences DataStore, tipli nesneler için Proto DataStore sunar ve asenkron çalışır.

## 13. Uygulamalar Arası Veri Gönderme

Hoca veri paylaşımı ile ilgili olduğu için daha önce konuşulan bir konuyu buraya da koydu. Veri kalıcı olarak saklanır ama paylaşımı da önemlidir: bir veriye ihtiyaç duyulduğunda o veri ağdan (örneğin bir JSON nesnesiyle), bir dosyadan, bir SharedPreferences dosyasından ya da bir veritabanından alınabilmeli veya oraya saklanabilmelidir. Uygulamalar arası veri akışının da sağlanması gerekir.

Slaytlarda text içeriğinin gönderilmesine yönelik iki örnek vardır. Yalnız metin değil, binary içerik de gönderilebilir; örnekte bir resim dosyasının URI'si (`uriToImage`) intent'e konur. İkinci ve üçüncü seçeneklerde `Intent.createChooser` ile işletim sistemine şu söylenir: "Bu bilgiyi gönderdim, bunu açmak ya da göndermek istiyorum; bu formatı açabilecek ya da gönderebilecek bir uygulama var mı? Seçeneklerini getir."

Birden fazla içerik paylaşılacaksa bunlar URI listesi olarak bir `ArrayList`'e eklenir ve karşı tarafa gönderilir (ekrandan, 01:20:00):

```java
ArrayList<Uri> imageUris = new ArrayList<Uri>();
imageUris.add(imageUri1); // Add your image URIs here
imageUris.add(imageUri2);

Intent shareIntent = new Intent();
shareIntent.setAction(Intent.ACTION_SEND_MULTIPLE);
shareIntent.putParcelableArrayListExtra(Intent.EXTRA_STREAM, imageUris);
shareIntent.setType("image/*");
startActivity(Intent.createChooser(shareIntent, "Share images to.."));
```

Diğer uygulamalardan veri alırken ise, önceki haftalarda aktivitelerde görüldüğü gibi `getIntent()` ile ilgili action'ın ve tipin ne olduğu alınır, yapılacak işlemler tipe göre ayrıştırılır ve iş tamamlanır. Bu konsept daha önce görüldüğü için ayrıntısına girilmedi.

<!-- BELİRSİZ: Tek metin ve tek resim gönderme örneklerinin (01:19 civarı) kodu karede yok; yalnız altyazıdan anlatıldı. -->

## 14. Serializable ve Parcelable

### 14.1 Neden?

Hoca öğrencilere, aynı ya da farklı tipte birden fazla veriyi birlikte saklayıp karşı uygulamaya ya da aktiviteye verimli biçimde göndermenin yolunu sordu (bkz. Örnek Sorular, Soru 3). Cevap iki yapıdır: Serializable arayüzü ve Parcelable.

### 14.2 Karşılaştırma

- **Serializable:** Java'nın sunduğu standart bir arayüzdür. Verilerin bir nesne mantığında saklanmasını ve birlikte hareket etmesini sağlar. Daha yavaş çalışır ve daha fazla garbage üretir, ama basit bir yapıdır.
- **Parcelable:** Android SDK'nın parçasıdır, Android işletim sistemi tarafından sunulur. Daha karmaşıktır ve özel kod gerektirir, ama daha az garbage üretir ve genel olarak daha hızlı çalışır. Performans artışı sağladığı için verilerin bir bütün hâlinde taşınmasında işletim sistemi tarafından önerilir.

### 14.3 Parcelable uygulaması

Parcelable örneğinde `Details` adlı bir sınıf, `name`, `age` ve `phone` bilgileri, bunların yapıcısı ve getter'ları ile kurulur; sınıf `Parcelable` arayüzünü uygular (ekrandan, 01:25:00):

```java
import android.os.Parcel;
import android.os.Parcelable;

public class Details implements Parcelable {

    private String name;
    private String age;
    private String phone;

    public Details(String name, String age, String phone) {
        this.name = name;
        this.age = age;
        this.phone = phone;
    }

    protected Details(Parcel in) {
        name = in.readString();
        age = in.readString();
        phone = in.readString();
    }

    public static final Creator<Details> CREATOR = new Creator<Details>() {
        @Override
        public Details createFromParcel(Parcel in) {
            return new Details(in);
        }

        @Override
        public Details[] newArray(int size) {
            return new Details[size];
        }
    };

    public String getName() { return name; }
    public String getAge() { return age; }
    public String getPhone() { return phone; }

    @Override
    public int describeContents() {
        return 0;
    }

    @Override
    public void writeToParcel(Parcel dest, int flags) {
        dest.writeString(name);
        dest.writeString(age);
        dest.writeString(phone);
    }
}
```

(Getter'lar karede alt alta ayrı satırlarda yazılıdır; burada kısaltılarak tek satırda verildi.)

Hoca adımları şöyle anlattı. Önce normal yapıcı yazılır, sonra her bir parcel bilgisini alan, `Parcel` parametreli bir yapıcı yazılır. Bir `CREATOR`'a ihtiyaç vardır; bu, her parcel için bir nesne üretmeyi sağlar. Hoca bunu geçen hafta RecyclerView'da öğelerin yaratılmasına, view holder'lara ve inflate işlemine benzetti. `Details` sınıfına ait bir dizi `newArray` metoduyla oluşturulur ve parcel sayısı burada alınır. Ek olarak `writeToParcel` metodunun içine `Details`'teki bütün özellikleri parcel'e yazan kod konur. Böylece Parcelable arayüzü uygulanmış olur ve `Details` sınıfından üretilen nesneler parcel'ler hâlinde yazılabilir.

Avantajı şudur: N tane bilgi karşı tarafa aktarılacaksa ve N binler mertebesini geçtiyse, performans Serializable'a göre çok ciddi oranda artar. Daha küçük veriler için yapılan araştırmalar çok büyük fark olmadığını söyler. Cihazların hızlanmış olmasının bunda önemli payı vardır: düşük konfigürasyonlu cihazda Parcelable daha avantajlıdır; yüksek konfigürasyonlu cihazlarda fark ancak büyük boyutta verinin toplu yazılması, okunması ya da aktarılmasında görülür.

### 14.4 Parcelable gönderme ve alma

Gönderirken intent'in `putExtra` kısmına `new Details(...)` ile yaratılan parcel yüklenir ve karşı tarafa aktarılır. Hoca bunun çok zor olmayan, yalnız görece biraz daha karmaşık bir yapı olduğunu söyledi. Karşı tarafta ise daha önceki bir kod örneğinde görüldüğü gibi `getParcelableExtra` ile (o örnekte `Student` nesnesine ait) bilgiler intent üzerinden alınır, değişkenlere atanır ve başka aktiviteden parcel ile gelen bilgi bu aktivitedeki ilgili yerlere yerleştirilir.

### 14.5 Serializable örneği

Serializable örneğinde yine bir kişiye ait bir sınıf vardır; `java.io` üzerinden import edilmiş `Serializable` arayüzünü uygular ve getter, setter'ları vardır. `CREATOR` gibi özel bir yapı tanımlanmaz. Önce `new Person(...)` ile kişi yaratılır, adı, adresi ve numarası verilir (örnekte hardcoded, ama kullanıcıdan form ile alınmış gibi düşünülebilir). Sonra nesne stream'ler kullanılarak yazılır ve okunur. Hoca bu yapının diğer mekanizmaya göre çok daha basit olduğunu, çünkü ek bir şey uygulamaya gerek kalmadığını söyledi. Serializable da Android'de uygulamalar arasında intent'lerle veri aktarımında ve dosyaya yazmada kullanılabilir.

<!-- BELİRSİZ: Serializable Person örneğinin kodu karede yok; hoca "object input stream" dedi, yazma için ObjectOutputStream, okuma için ObjectInputStream kullanıldığı büyük olasılıktır. -->

## 15. Android Studio: Kamera ile Fotoğraf Alma (ActivityResultLauncher)

### 15.1 Uygulamanın davranışı

Hoca önce uygulamayı çalıştırdı: giriş yapıldıktan sonra kamera butonuna tıklanınca kamera uygulamasının aktivitesi çağrılır, fotoğraf çekilir ve OK'e basılınca fotoğraf bir ImageView'da gösterilir. Bunun ders boyunca geliştirilen mezun uygulamasındaki kayıt formuyla ilişkisini de kurdu: kullanıcının kendi resmini koyması için önce resmi çekmesi, bunun için de bir fotoğraf uygulamasına bağlanması gerekir. İki kod gösterildi: ilki fotoğrafı yalnız aktivitedeki arayüz bileşenine yerleştirir, ikincisi ayrıca dosyaya kaydeder.

### 15.2 Camera.java

`Camera` adlı aktivitenin `onCreate` metodunda `setContentView(R.layout.activity_camera)` ile layout bağlanır. Layout'ta bir TextView, bir ImageView ve bir buton vardır. Ardından bu bileşenler koddaki değişkenlerle ilişkilendirilir. Kod (ekrandan, 01:35:00 ve 01:40:00):

```java
public static final int CAMERA_REQUEST_CODE = 102;
ImageView selectedImage;
Button cameraBtn;

ActivityResultLauncher activityResultLauncher;

@Override
protected void onCreate(Bundle savedInstanceState) {
    super.onCreate(savedInstanceState);
    setContentView(R.layout.activity_camera);

    selectedImage = findViewById(R.id.displayImageView);
    cameraBtn = findViewById(R.id.cameraBtn);
    // Open Camera

    activityResultLauncher = registerForActivityResult(
            new ActivityResultContracts.StartActivityForResult(),
            new ActivityResultCallback<ActivityResult>() {
        @Override
        public void onActivityResult(ActivityResult result) {
            if (result.getResultCode() == RESULT_OK && result.getData() != null) {
                Bundle bundle = result.getData().getExtras();
                Bitmap bitmap = (Bitmap) bundle.get("data");
                selectedImage.setImageBitmap(bitmap);
            }
        }
    });

    cameraBtn.setOnClickListener(new View.OnClickListener() {
        @Override
        public void onClick(View v) {
            askCameraPermissions();

            Intent intent = new Intent(MediaStore.ACTION_IMAGE_CAPTURE);
            if (intent.resolveActivity(getPackageManager()) != null) {
                activityResultLauncher.launch(intent);
            } else {
                Toast.makeText(Camera.this, "There is no app that support this action",
                        Toast.LENGTH_SHORT).show();
            }
        }
    });
}
```

(Karede görünen `@SuppressLint` açıklamaları atlandı; kodun geri kalanı karelerden aktarıldı. `askCameraPermissions()` ve `onRequestPermissionsResult` gövdeleri karede görünmedi.)

### 15.3 Kodun anlatımı

Hoca daha önce, aktiviteden sonuç bekleniyorsa `startActivityForResult` çağrılıp `onActivityResult` metodunun yazıldığını, bunun eski yöntem olduğunu ve yeni yöntemin `ActivityResultLauncher` olduğunu söylemişti; bu derste bunun örneği gösterildi.

- `ActivityResultLauncher` tipinde bir değişken tanımlanır; adı farklı olabilir ama tipi budur.
- `registerForActivityResult` ile, `ActivityResultContracts.StartActivityForResult()` sözleşmesi ve bir `ActivityResultCallback` parametresi verilerek kayıt yapılır.
- Callback anonim bir sınıftır ve bir `onActivityResult` metodu vardır. Önceki örnekte sonuç ve request kodu ayrı ayrı kontrol ediliyordu; burada doğrudan `result.getResultCode()` ve `result.getData()` ile sonucun OK olup olmadığına ve veri gelip gelmediğine bakılır.
- Karşı aktivitenin döndürdüğü bilgi (burada resim) Bundle içinden alınır, `Bitmap`'e dönüştürülür ve `selectedImage.setImageBitmap(bitmap)` ile ImageView'a yerleştirilir.

Butona tıklanınca `setOnClickListener` içindeki `onClick` çalışır. Önce `askCameraPermissions()` çağrılır: manifest üzerinden izin kontrol edilir, onay yoksa çalışma zamanında dinamik izin istenir ve cevap `onRequestPermissionsResult`'tan alınır. Sorun yoksa intent oluşturulur, `resolveActivity` ile `getPackageManager()`'dan bu işi yapabilecek bir aktivite olup olmadığı sorulur. Varsa `startActivityForResult` yerine `activityResultLauncher.launch(intent)` çağrılır; `startActivityForResult`'a intent gönderiliyordu, burada intent `launch` metoduna verilir. Uygun aktivite yoksa `else` koluna gidilir ve "There is no app that support this action" mesajı gösterilir. Fotoğraf çekilip geri dönüldüğünde callback'in `onActivityResult` metodu çalışır, gelen kod ve veri kontrol edilir, Bitmap ImageView'a yazılır.

### 15.4 Arada sorulan soru

**Soru:** Kodun üzerinden bir kez geçildi ama 67-69. satırlarda intent alındıktan sonra neden tekrar launch edildiği karıştı; akış bir daha anlatılabilir mi?

**Cevap:** Amaç fotoğrafı çekip görüntüyü ekrana yansıtmaktır. Butonlu bir aktiviteden başka bir aktiviteye gidilir, orada iş yaptırılır, içerik alınıp geri dönülür. Bu daha önce `startActivityForResult` ile yapılıyordu; burada onun yerine launcher ve `launch` metodu kullanılır. Orada da burada da bir intent gönderilir. Intent "bir image capture etmek istiyoruz" der. Göndermeden önce bu intent'e karşılık gelecek, işi yapabilecek bir aktiviteye sahip uygulama var mı diye sorulur; sonuç null değilse launch edilir, yoksa "bunu yapabilecek bir aktivite yok" denir. Bu birinci kısım butona, yani `setOnClickListener` içindeki `onClick`'e bağlıdır; butona tıklanınca önce izin kontrolleri yapılır, sorun yoksa sonraki adıma geçilir. İkinci kısım, fotoğrafı alan uygulama fotoğrafı geri ilettiğinde ne yapılacağıdır. Bunun için bir launcher tanımlanır (adı başka olabilir) ve register edilir; sözleşme üzerinden `StartActivityForResult` anonim sınıfla başlatılır. Anonim `ActivityResultCallback` sınıfının `onActivityResult` metodunun içi doldurulur (iskeleti hazır gelir). Daha önce kullanılan result code burada `result.getResultCode()` ile alınır; OK ise ve `getData()` null değilse, yani karşı taraftan image alınabildiyse (bazen hata olur ve image gelmeyebilir), extras içinden Bundle, Bundle içinden veri alınır ve Bitmap olarak `setImageBitmap` ile ImageView'a yerleştirilir.

## 16. Android Studio: Fotoğrafı Dosyaya Kaydetme

### 16.1 Uygulamanın davranışı

İkinci örnekte (`CameraSave`) uygulama aynı görünür: fotoğraf çekilip OK'e basılınca ekranda gösterilir. Farkı, resmin yalnız aktiviteye getirilmeyip aynı zamanda bir klasöre kaydedilmesidir. Hoca Android Studio'da Device Manager / Device File Explorer üzerinden cihazın dosyalarını açtı: `sdcard` altındaki `Pictures` klasöründe kaydedilen resimler görünüyordu ve en son kaydedilen resim açılınca çekilen fotoğraf görüldü. Böylece cihaz seçilerek o cihazdaki klasörlere ve dosyalara erişilebildiği gösterildi.

### 16.2 createImageFile()

Kod (ekrandan, 02:00:00):

```java
private File createImageFile() throws IOException {
    // Create an image file name
    String timeStamp = new SimpleDateFormat("yyyyMMdd_HHmmss").format(new Date());
    String imageFileName = "JPEG_" + timeStamp + "_";
//  File storageDir = getExternalFilesDir(Environment.DIRECTORY_PICTURES);
    File storageDir = Environment.getExternalStoragePublicDirectory(Environment.DIRECTORY_PICTURES);
    File image = File.createTempFile(
            imageFileName,  /* prefix */
            ".jpg",         /* suffix */
            storageDir      /* directory */
    );

    // Save a file: path for use with ACTION_VIEW intents
    currentPhotoPath = image.getAbsolutePath();
    return image;
}
```

Dosya oluşturulamazsa metot `IOException` fırlatır. Hoca dosya adının uzun olduğunu ve şöyle kurulduğunu anlattı: `SimpleDateFormat` ile o anki yıl, ay, gün ve saat bilgisi alınır, bir zaman damgası (timestamp) oluşturulur; başına "JPEG_" eklenir ve oluşturulmak istenen dosyanın adı `imageFileName` string'inde yaratılır. Benzersiz (unique) bir ad için tarih ve saat bilgisinden yararlanılır. Sonra, derste örnek kodlarda görülen `getExternalStoragePublicDirectory(Environment.DIRECTORY_PICTURES)` ile dosyanın konumlanacağı dizin söylenir. Ardından `File` sınıfının, geçici dosya üretmek için kullanılan `createTempFile` metoduna dosya adı, dosya türü (`.jpg`) ve dizin verilir. `image.getAbsolutePath()` ile dosyanın yeri `currentPhotoPath` değişkenine alınır ve `image` döndürülür. Yorum satırına alınmış alternatif satır, aynı işi uygulamaya özel dizinde (`getExternalFilesDir`) yapar.

> **Ek bilgi (derste anlatılmadı):** `File.createTempFile(prefix, suffix, directory)` dosya adını tam olarak `prefix + suffix` yapmaz; benzersizliği garanti etmek için araya rastgele bir sayı ekler. Bu yüzden oluşan dosyanın adı "JPEG_<zaman damgası>_<rastgele sayı>.jpg" biçimindedir. Ad geçici dosya metoduyla üretilse de dosya kendiliğinden silinmez.

### 16.3 dispatchTakePictureIntent()

Kodun görünen kısmı (ekrandan, 02:00:00):

```java
private void dispatchTakePictureIntent() {
    Intent takePictureIntent = new Intent(MediaStore.ACTION_IMAGE_CAPTURE);
    // Ensure that there's a camera activity to handle the intent
    if (takePictureIntent.resolveActivity(getPackageManager()) != null) {
        // Create the File where the photo should go
        File photoFile = null;
        try {
            photoFile = createImageFile();
        } catch (IOException ex) {

        }
        // Continue only if the File was successfully created
        if (photoFile != null) {
            Uri photoURI = FileProvider.getUriForFile(this,
                    "com.example.android.fileprovider", photoFile);
            ...
```

<!-- BELİRSİZ: Kodun 133. satırdan sonrası (putExtra ve startActivityForResult satırları) karede görünmüyor; aşağıdaki anlatım altyazıdandır. -->

Butona tıklanınca yine `setOnClickListener` → `onClick` → bu kez `verifyPermissions()` çağrılır ve izinlerin alınıp alınmadığı kontrol edilir. İzin verildiyse `dispatchTakePictureIntent()` çağrılır; verilmediyse "Camera Permission is Required to Use camera." mesajı gösterilir (ekrandan, 02:05:00). Bu metotta bir intent yaratılır ve yine resim çekip almak (capture) istendiği söylenir. `resolveActivity` ile null olup olmadığına, yani işi yapabilecek bir aktivite olup olmadığına bakılır. Sonra `createImageFile()` çağrılarak `photoFile` yaratılır. Dosya yaratıldıysa (null değilse) `FileProvider.getUriForFile` ile dosyanın URI'si `photoURI`'de saklanır ve `takePictureIntent.putExtra` ile gönderilecek intent'in ekstrasına bu URI eklenir. Burada eski usul `startActivityForResult` kullanılmıştır; editörde üstü çizili görünür, çünkü deprecated'dır, ama hâlâ kullanılabilir.

### 16.4 onActivityResult

Kod (ekrandan, 02:05:00):

```java
@Override
protected void onActivityResult(int requestCode, int resultCode, @Nullable Intent data) {
    super.onActivityResult(requestCode, resultCode, data);
    if (requestCode == CAMERA_REQUEST_CODE) {
        if (resultCode == Activity.RESULT_OK) {
            File f = new File(currentPhotoPath);
            selectedImage.setImageURI(Uri.fromFile(f));
            Log.d("tag", "ABsolute Url of Image is " + Uri.fromFile(f));

//          Intent mediaScanIntent = new Intent(Intent.ACTION_MEDIA_SCANNER_SCAN_FILE);
//          Uri contentUri = Uri.fromFile(f);
//          mediaScanIntent.setData(contentUri);
//          this.sendBroadcast(mediaScanIntent);
        }
    }
}
```

Intent `startActivityForResult` ile gönderildiği için dönüşte bu `onActivityResult` çalışır. Karşıya "fotoğraf çekmek istiyoruz, fotoğrafı çeken bir uygulama göster; o uygulama fotoğrafı çeksin ve bu dosyaya aktarsın" denmiştir. Eskisi gibi request kodu yukarıda tanımlanan kodla karşılaştırılır, sonra result kodu kontrol edilir. `currentPhotoPath`'teki mutlak yoldan bir `File` oluşturulur, `setImageURI` ile ImageView'da gösterilir ve `Log.d` ile dosyanın konumu `Uri.fromFile` bilgisiyle Logcat'e yazılır. Hoca Logcat'te bu satırı ilk denemede göremedi, bir fotoğraf daha çekerek gösterdi.

### 16.5 İki örneğin farkı

**Soru:** Bu örnekte kaydedilen resmi mi görüyoruz? Önceki örnekte kaydetmeden çekilen fotoğraf doğrudan ekrana yansıyordu; burada önce kaydetme yapılıyor, sonra mı ekrana yansıyor?

**Cevap:** Evet, aynen öyle. Önceki örnekte de veri JPEG'ti, ama Bitmap formatını da göstermek için bir düzenleme yapılmıştı: veri doğrudan intent'in içinden alınıp Bitmap olarak ImageView'a basılıyordu, kayıt yoktu. Burada ise istenen fotoğraf dosyaya kaydedildi, dosya açıldı ve içindeki veri `setImageURI` ile ekrana basıldı. Hoca öğrencinin farkı kendisinin fark etmesini olumlu buldu. Bu örnekte ayrıca eski `startActivityForResult` yöntemi kullanıldı ve gönderilen resim tarih ve saat bilgisiyle `sdcard/Pictures` altındaki bölgeye kaydedildi.

## 17. Android Studio: SharedPreferences Uygulaması

### 17.1 Uygulamanın davranışı

Hoca `SharedPrefActivity` adlı aktiviteyi başlatıp gösterdi. Ekranda daha önce girilmiş bilgiler (bir ad ve yaş) görünüyordu. Bunlar silinip yeni bir ad ve yaş girildi, sonra aktiviteden çıkıldı ve aktivite yok edildi (destroy). Aktiviteye yeniden girildiğinde SharedPreferences'tan en son girilen bilgiler geri geldi. Hoca bu şekilde hem girilen bilgilerin kaydedilebildiğini hem de daha önce girilenlerin ekrana geri geldiğini gösterdi; bunun illa böyle tasarlanmak zorunda olmadığını, bir örnek uygulama olduğunu ekledi.

### 17.2 Kod

Layout'ta (`activity_sharedpref.xml`) bir TextView ve iki EditText vardır. Kod (ekrandan, 02:25:00 ve 02:20:00):

```java
@Override
protected void onCreate(Bundle savedInstanceState) {
    super.onCreate(savedInstanceState);
    setContentView(R.layout.activity_sharedpref);
    name = findViewById(R.id.edit1);
    age = findViewById(R.id.edit2);
}

// Fetch the stored data in onResume() Because this is what will be called when the app opens again
@Override
protected void onResume() {
    super.onResume();
    // Fetching the stored data from the SharedPreference
    SharedPreferences sh = getSharedPreferences("MySharedPref", MODE_PRIVATE);
    String s1 = sh.getString("name", "");
    int a = sh.getInt("age", 0);

    // Setting the fetched data in the EditTexts
    name.setText(s1);
    age.setText(String.valueOf(a));
}

// Store the data in the SharedPreference in the onPause() method
// When the user closes the application onPause() will be called and data will be stored
@Override
protected void onPause() {
    super.onPause();
    // Creating a shared pref object with a file name "MySharedPref" in private mode
    SharedPreferences sharedPreferences = getSharedPreferences("MySharedPref", MODE_PRIVATE);
    SharedPreferences.Editor myEdit = sharedPreferences.edit();

    // write all the data entered by the user in SharedPreference and apply
    myEdit.putString("name", name.getText().toString());
    myEdit.putInt("age", Integer.parseInt(age.getText().toString()));
    myEdit.apply();
}
```

### 17.3 Kodun anlatımı

`onCreate`'te tasarım yüklenir ve iki EditText değişkenlerle ilişkilendirilir. Okuma kodu `onResume()`'dadır: hoca, aktivite her hâlükârda `onResume`'dan geçeceği için bu örnekte kodun `onCreate`'e konmadığını, genellikle `onCreate`'e konduğunu ama farklı olduğu için bu örneği tercih ettiğini söyledi. `getSharedPreferences("MySharedPref", MODE_PRIVATE)` ile nesne oluşturulur; `getString("name", "")` ve `getInt("age", 0)` ile değerler alınır. Bunlar hiç girilmediyse, ilk açılışta yaş sıfır, ad boş gelir. Sonra `name.setText(s1)` ve `age.setText(String.valueOf(a))` ile alanlar doldurulur.

Yazma kodu `onPause()`'tadır. `getSharedPreferences` ile `MySharedPref` dosyasına erişilir (nesnesi yaratılır). Bilgi yazılacağı için `edit()` metoduyla editör oluşturulur. EditText'lerde o an yazılı olan bilgi alınır; `putString` ile `name`'e, `putInt` ile `age`'e konur ve `apply()` denir. `apply()` asenkron bir aktarım olduğundan bilgi uygun bir zamanda SharedPreferences dosyasına yazılır.

> **Ek bilgi (derste anlatılmadı):** Bu örnekte yaş alanı boş bırakılırsa `Integer.parseInt("")` bir `NumberFormatException` fırlatır ve uygulama `onPause()`'ta çöker. Gerçek bir uygulamada alanın boş olup olmadığı ya da sayı olup olmadığı yazmadan önce kontrol edilmelidir.

## Örnek Sorular

**Soru 1** (derste sözlü, 00:47:04): Slayttaki (boş alanla ilgili) kod parçası ne yapıyor? Kodun üzerinde ipuçları var.

> **Cevap (derste verildi):** Bir öğrenci boş belleğe baktığını ve gerekli alan bulunmazsa başka bir yere yönlendirdiğini tahmin etti. Hoca bunu doğruladı: kod 10 MB'lık bir alan olup olmadığını kontrol ediyor; yoksa gereken işlemler için alan açmaya çalışıyor. İndirilecek ya da işlenecek dosya büyük olabileceği ve internal storage'da çok az yer kalmış olabileceği için, hata oluşmaması adına bu kontrol yapılmalıdır. <!-- BELİRSİZ: Kodun kendisi karede yok. -->

**Soru 2** (derste sözlü, 01:12:32): SharedPreferences editöründe `apply()` demekle `commit()` demek arasında ne fark vardır?

> **Cevap (derste verildi):** Bir öğrencinin cevabı doğruydu: biri senkron, diğeri asenkron yazar. `apply()` asenkrondur; bilgi belleğe yazılır, dosyaya ne zaman yazılacağı sistemin uygunluğuna bağlıdır ve arayüzü bloklamaz. `commit()` senkrondur; bellekten hemen sonra ikincil belleğe kesintisiz (atomik) yazılır.

**Soru 3** (derste sözlü, 01:20:22): Aynı ya da farklı tipte birden fazla veriyi birlikte saklayıp karşı uygulamaya ya da aktiviteye verimli biçimde göndermeyi mümkün kılan, kolaylaştıran yapılar nelerdir?

> **Cevap (derste verildi):** Serializable arayüzü ve Parcelable. Serializable Java'nın standart arayüzüdür; basit ama daha yavaştır ve daha çok garbage üretir. Parcelable Android SDK'nın parçasıdır; özel kod gerektirir ama daha hızlıdır ve daha az garbage üretir. Özellikle binlerce nesnenin aktarımında Parcelable belirgin biçimde daha hızlıdır.

**Soru 4** (derste sözlü, 01:51:04): Kamera örneğinde intent oluşturulduktan sonra neden ayrıca `launch` ediliyor; akış nasıl işliyor?

> **Cevap (derste verildi):** Bkz. Bölüm 15.4. Intent yalnız "image capture" işini tanımlar; `resolveActivity` ile bu işi yapacak bir aktivite olduğu doğrulandıktan sonra `activityResultLauncher.launch(intent)` ile gönderilir (eski `startActivityForResult`'ın yerine). Sonuç, launcher kaydedilirken verilen callback'in `onActivityResult` metoduna gelir.

**Soru 5** (derste sözlü, 02:06:02): Kaydetmeli örnekte ekrana yansıyan, kaydedilen dosya mıdır; önceki örnekten farkı nedir?

> **Cevap (derste verildi):** Bkz. Bölüm 16.5. Evet; önceki örnekte veri intent'ten Bitmap olarak alınıp kaydedilmeden gösteriliyordu, bu örnekte fotoğraf dosyaya kaydedilip dosyadan açılıyor ve `setImageURI` ile gösteriliyor.

## Dersin Toparlaması

Bu derste Android'de verinin kalıcı olarak nasıl saklanacağı ele alındı. Dört temel seçenek (app-specific storage, shared storage, preferences, database) ve bunlar arasında seçim yapmayı belirleyen sorular (gereken alan, verinin uygulamaya özel ve hassas olup olmadığı) konuşuldu. Internal storage'ın her zaman erişilebilir, uygulamaya özel ve Android 10'dan itibaren şifreli olduğu; external storage'ın ise paylaşım ve büyük dosyalar için uygun ama güvenlik açısından riskli olduğu vurgulandı. `getFilesDir`, `getCacheDir`, `getExternalFilesDir`, `getExternalStoragePublicDirectory` gibi dizin metotları, dosya okuma-yazma, cache dosyaları, external storage durum kontrolü, izinlerin gerektiği kadar istenmesi, MediaStore, Storage Access Framework ve BlobStoreManager tanıtıldı.

İkinci bölümde SharedPreferences ayrıntılı işlendi: `getSharedPreferences` ile `getPreferences` farkı, saved instance state ile karşılaştırma, editörle yazma, `apply()`/`commit()` farkı ve okurken varsayılan değer kullanımı. Ardından uygulamalar arası veri gönderme ve Serializable ile Parcelable karşılaştırıldı, Parcelable'ın nasıl uygulandığı gösterildi. Android Studio'da üç örnek incelendi: yeni `ActivityResultLauncher` yöntemiyle kameradan fotoğraf alıp gösterme, eski `startActivityForResult` yöntemiyle fotoğrafı `Pictures` dizinine kaydedip dosyadan gösterme ve kullanıcının girdiği ad ile yaşı `onPause`'ta kaydedip `onResume`'da geri getiren SharedPreferences uygulaması. Hoca, ileriki derslerde Firebase'den de söz edileceğini belirtti.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
