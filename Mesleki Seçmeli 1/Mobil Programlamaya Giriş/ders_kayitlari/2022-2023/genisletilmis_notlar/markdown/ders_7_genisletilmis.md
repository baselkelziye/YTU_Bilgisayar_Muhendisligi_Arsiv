# Ders 7 Genişletilmiş Notu: Intent ile Sonuç Alma, Layout'lar ve ListView/RecyclerView

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Önceki Derslerden Bağlantı ve Dersin Planı
- 2. Yaygın (Common) Intent'ler
- 3. startActivityForResult ile Sonuç Alma
- 4. Intent Filter Örnekleri
- 5. Fotoğraf Çekme Intent'i ve Gelen Intent'i Karşılamak
- 6. Activity Result API
- 7. Layout'lar ve UI Bileşenleri
- 8. Adapter ile Liste Gösterme: ListView
- 9. RecyclerView ve ListView Karşılaştırması
- 10. RecyclerView'ı Kurmak: Aktivite ve Adapter
- 11. Android Studio Örneği: ListView ile Liste
- 12. Android Studio Örneği: Çok Tipli RecyclerView
- 13. Mezun Bilgi Sistemi: Duyuru Ekranı Tasarımı
- 14. Uygulama Bölümündeki Sorular
- Örnek Sorular
- Dersin Toparlaması

## 1. Önceki Derslerden Bağlantı ve Dersin Planı

Önceki haftalarda aktiviteler, bileşenler, aktivite yaşam döngüsü (Activity Lifecycle) ve aktiviteler arası iletişimi sağlayan intent konuşulmuştu: explicit ve implicit intent'in farkı, bir aktiviteden diğerine hangi amaçla geçildiği ve geri dönüş beklenip beklenmediği. Bu derste aynı konu, iki aktivite arasında bilgi geri döndüğünde neyle karşılaşıldığı ve bu bilginin nasıl alındığı üzerinden derinleştirilir. Ardından çok sayıda veriyi ekranda göstermeye yarayan ListView ve RecyclerView yapıları, aralarındaki farklar ve birbirlerine göre avantajları ele alınır.

Ders boyunca bir "mezun bilgi sistemi" uygulaması geliştirilmektedir. Bu uygulamada bir giriş (login) ekranı, bir kayıt (sign up) ekranı, mezunların bilgilerinin alındığı ve fotoğraf yükleyebildiği bir ekran bulunur. Bu dersle birlikte uygulamaya, mezunların sisteme girdiğinde bölümle ve mezunlarla ilgili haberleri bir liste halinde gördüğü bir duyuru ekranı eklenecektir. Böylece mezun, mezunların başarıları, öğrencilerin ve öğretim üyelerinin çalışmaları hakkında bilgi alabilecektir.

## 2. Yaygın (Common) Intent'ler

### 2.1 Seçim ekranı ve createChooser hatırlatması

Bir implicit intent gönderildiğinde sistem, o aksiyonu gerçekleştirebilecek aktiviteleri listeler. Varsayılan durumda kullanıcıya ilgili uygulamayı "yalnız bir kez" mi yoksa "her zaman" (always) mı kullanmak istediği sorulur. Kullanıcı "her zaman" seçerse bundan sonra karşısına seçenek çıkmaz. Uygulamadan her aksiyon yapıldığında alternatiflerin kullanıcının önüne gelmesi isteniyorsa `createChooser` ile bir seçici yaratılır.

### 2.2 Alarm kurma

Intent yapısıyla kendi aktivitenizden bir alarm kurabilir, alarmın saatini ayarlayabilirsiniz. Slayttaki kod şöyledir (ekrandan, 00:15:00):

```java
public void createAlarm(String message, int hour, int minutes) {
    Intent intent = new Intent(AlarmClock.ACTION_SET_ALARM)
            .putExtra(AlarmClock.EXTRA_MESSAGE, message)
            .putExtra(AlarmClock.EXTRA_HOUR, hour)
            .putExtra(AlarmClock.EXTRA_MINUTES, minutes);
    if (intent.resolveActivity(getPackageManager()) != null) {
        startActivity(intent);
    }
}
```

Metodun adı (`createAlarm`) özel değildir, istenen başka bir ad verilebilir. Değişmemesi gereken kısım, intent'in aksiyonunun `ACTION_SET_ALARM` olmasıdır. Alarmın saat kaçta çalacağı (örneğin 5.28) saat ve dakika olarak aktarılmalıdır; bunlar verilmezse alarm kurulamaz. Mesaj aktarılmazsa yalnız ekranda mesaj görünmez. Ardından `resolveActivity` ile bu isteği karşılayacak bir aktivite olup olmadığı kontrol edilir ve alarm o saat ve dakika için kurulur.

Bu intent'i çağırabilmek için uygulamanın `SET_ALARM` iznine sahip olması gerekir (ekrandan, 00:15:00):

```xml
<uses-permission android:name="com.android.alarm.permission.SET_ALARM" />
```

> **Hocanın vurgusu:** İzin alınmazsa yazılan alarm kodunun bir önemi kalmaz; uygulama hata verir ve çalışmaz. Bu izin mutlaka Android Manifest'e eklenmelidir.

Ters yönde, yani sizin uygulamanız alarm kurma isteğini karşılayabilecekse, aktivitenin intent filter'ına bu aksiyonu yapabildiği yazılır (ekrandan, 00:15:00):

```xml
<activity ...>
    <intent-filter>
        <action android:name="android.intent.action.SET_ALARM" />
        <category android:name="android.intent.category.DEFAULT" />
    </intent-filter>
</activity>
```

### 2.3 Zamanlayıcı (timer)

Zamanlayıcı da alarma benzer biçimde kurulur; aksiyonu `ACTION_SET_TIMER`'dır. Zamanlayıcı bitince gösterilecek mesaj, ne kadar süreceği ve kullanıcı ekrandan çıktığında zamanlayıcının devam edip etmeyeceği aktarılır. Bazı zamanlayıcıların yalnız uygulamada kalındığı sürece, bazılarının arka planda da devam etmesi istenebilir. İzin almak unutulmamalıdır. Sizin uygulamanız bu isteği karşılayacaksa intent filter'a `SET_TIMER` aksiyonu yazılır; böylece bu istek geldiğinde uygulama "ben de varım" diyebilir.

### 2.4 Kişi ekleme

Bir kişi bilgisini telefondaki kişiler arasına eklemek için `ACTION_INSERT` aksiyonu kullanılır. Her insert aksiyonu kişi eklemek anlamına gelmeyebilir; başka bir bilgiyi sisteme eklemek de olabilir. Bu yüzden `setType` ile işin kişilerle ilgili olduğu belirtilir. Slayttaki örnekte ad ve e-posta `putExtra` ile verilmiştir; istenirse telefon numarası da eklenip adres defterine kaydedilebilir.

### 2.5 Belirli tipte dosya açma

Bu intent'te belirli tipteki bir dosyanın açılması istenir ve bu kez sonuç geri beklenir (ekrandan, 00:20:00):

```java
static final int REQUEST_IMAGE_OPEN = 1;

public void selectImage() {
    Intent intent = new Intent(Intent.ACTION_OPEN_DOCUMENT);
    intent.setType("image/*");
    intent.addCategory(Intent.CATEGORY_OPENABLE);
    // Only the system receives the ACTION_OPEN_DOCUMENT, so no need to test.
    startActivityForResult(intent, REQUEST_IMAGE_OPEN);
}

@Override
protected void onActivityResult(int requestCode, int resultCode, Intent data) {
    if (requestCode == REQUEST_IMAGE_OPEN && resultCode == RESULT_OK) {
        Uri fullPhotoUri = data.getData();
        // Do work with full size photo saved at fullPhotoUri
        ...
    }
}
```

Yapıcıya `ACTION_OPEN_DOCUMENT` aksiyonu verilir. Tip olarak herhangi bir uzantıya sahip bir resim (`image/*`) istenir. Kategori olarak açılabilir bir dosya (`CATEGORY_OPENABLE`) belirtilir. Burada önemli olan, `startActivityForResult`'ın çağrılmasıdır: açılacak dosyanın bilgisi geri alınır ve `onActivityResult` metodunda işlenir.

`onActivityResult`'ın üç parametresi vardır: `requestCode`, `resultCode` ve intent. Bir aktivitede yapılacak işlemler birden fazla olabileceği için her işleme bir kod verilir ve bu kod karşı tarafa gönderilir. Dönen kodun gönderilen request code ile aynı olup olmadığına bakılarak doğrulama yapılır. Result code ise karşıdaki aktivitenin işi yapıp yapamadığını söyler: `RESULT_OK` dönerse iş yapılmış, `RESULT_CANCELED` dönerse yapılamamıştır. Beklenen doküman bilgisi alınamamışsa durumu kullanıcıya bildiren ya da gerekli aksiyonu alan bir kod yazmak geliştiricinin sorumluluğudur. Sorun yoksa karşı taraftan aktarılan intent'ten `getData` ile resme ait bilgi alınır ve resimle ilgili işler yapılır. Galeriden resim almak ya da kameradan çekilen fotoğrafı alıp işleyip uygulama içinde kaydetmek çok sık yapılan işlerdendir.

Bu yeteneğe sahip bir uygulama yazılıyorsa, ekrandaki örnekte olduğu gibi bir `<provider>` tanımı, intent filter'ı ve izni (`android.permission.MANAGE_DOCUMENTS`) manifest'e yazılmalıdır (ekrandan, 00:20:00).

`setType`'ta yalnız "resim" demek yerine daha dar bir kısıtlama da yapılabilir: örneğin yalnız JPEG ya da PNG. Bazı web sitelerinde dokümanların belli bir standartta yüklenmesi için bu tür kısıtlar görülür; başka tipte bir doküman gelince kullanıcı "bu doküman tipi uyumsuz" diye uyarılır. Bunların koordinasyonu geliştiriciye aittir.

### 2.6 Medya dosyası oynatma

Bir müzik ya da video dosyasının dinlenmesi veya izlenmesi için küçük bir kod parçası yeterlidir (ekrandan, 00:25:00):

```java
public void playMedia(Uri file) {
    Intent intent = new Intent(Intent.ACTION_VIEW);
    intent.setData(file);
    if (intent.resolveActivity(getPackageManager()) != null) {
        startActivity(intent);
    }
}
```

`ACTION_VIEW` ile gösterme ya da dinleme amacında olduğunuzu söylersiniz, `setData` ile dosya bilgisini eklersiniz. Sistem bu medya dosyasını oynatabilecek uygulamaları seçenek olarak sunar, kullanıcı birini seçer.

Örnek intent filter'da ise uygulamanız bir medya oynatıcı gibi davranır ve kendisine gönderilen dosyaları oynatabileceğini bildirir (ekrandan, 00:25:00):

```xml
<activity ...>
    <intent-filter>
        <action android:name="android.intent.action.VIEW" />
        <data android:type="audio/*" />
        <data android:type="application/ogg" />
        <category android:name="android.intent.category.DEFAULT" />
    </intent-filter>
</activity>
```

Bu filtre yalnız ses dosyaları için bir vaattir: video dosyası ya da OGG dışındaki bir uygulama tipi desteklenmez. Uygulamanız yalnız bu koşula uyan bir istek geldiğinde çağrılır.

## 3. startActivityForResult ile Sonuç Alma

### 3.1 Ne zaman kullanılır?

Şimdiye kadar çoğunlukla `startActivity` kullanıldı. `startActivityForResult`, adından da anlaşıldığı gibi, başka bir aktiviteyi çağırıp ondan bir bilgi döndürmesini beklediğinizde kullanılır. Dönen bilgi bir işin yapılıp yapılmadığı, bir kişi bilgisi, bir resim, bir indirme adresi ya da bir forma ait bilgiler olabilir.

### 3.2 Request code ile isteği izlemek

Slayttaki örnekte `pickContact` adlı bir metot tanımlanmıştır. Bu metotta karşı taraftan, rehberden içerik talep edilir; `pickContactIntent.setType(...)` ile özellikle telefon numarası bulunan kişilerin bilgileri istenir. Intent gönderilirken isteğin kodu da verilir. Bunun nedeni, bir aktivitenin içinde koşula bağlı olarak birden fazla tipte istek yapılabilmesidir. Örneğin bir `PICK_CONTACT_REQUEST` (1) ve bir `PICK_IMAGE_REQUEST` (2) olabilir. Galeriden bir şey istendiyse dönüşte 2, kişi istendiyse 1 gelir; hangi isteğin cevabının geldiği bu kodlarla takip edilir.

> **Hocanın vurgusu:** Request code karşı tarafa mutlaka verilmelidir; işi talep edenin kim olduğu mutlaka bilinmelidir.

### 3.3 ActivityNotFoundException

Haritada bir adres gösterme örneğinde dikkat çekilen nokta hem `startActivity` hem de `startActivityForResult` için geçerlidir: isteği karşılayabilecek bir aktivite telefonda yoksa (düşük bir olasılık olsa da) `ActivityNotFoundException` oluşur. Bunun `catch` kısmına yapılacak işlem yazılmalı ve uygulamanın çökmesi (crash) önlenmelidir.

### 3.4 Sonucu almak: kişi seçme örneği

Özetle: istek yapılırken request code karşı tarafa gönderilir; karşı taraftan result code döner ve işin yapılıp yapılamadığını `RESULT_OK` ya da `RESULT_CANCELED` ile söyler; ayrıca `onActivityResult` metoduna bütün bilgiyi taşıyan intent'in kendisi döner. Slayttaki örnek şöyledir (ekrandan, 00:30:00):

```java
@Override
protected void onActivityResult(int requestCode, int resultCode, Intent resultIntent) {
    // Check which request it is that we're responding to
    if (requestCode == PICK_CONTACT_REQUEST) {
        // Make sure the request was successful
        if (resultCode == RESULT_OK) {
            // Get the URI that points to the selected contact
            Uri contactUri = resultIntent.getData();
            // We only need the NUMBER column, because there will be only one row in the result
            String[] projection = {Phone.NUMBER};

            // CAUTION: The query() method should be called from a separate thread to avoid
            // blocking your app's UI thread.
            Cursor cursor = getContentResolver()
                    .query(contactUri, projection, null, null, null);
            cursor.moveToFirst();

            // Retrieve the phone number from the NUMBER column
            int column = cursor.getColumnIndex(Phone.NUMBER);
            String number = cursor.getString(column);

            // Do something with the phone number...
        }
    }
}
```

Adım adım: önce request code kontrol edilir (doğru isteğin cevabı mı geldi?). Sonra result code `RESULT_OK` mi diye bakılır (istenen iş yapılabildi mi?). Ardından gelen intent'ten (`resultIntent`) `getData` ile bilgi bir değişkene alınır. Son olarak bir cursor ile gelen kişi bilgileri arasında gezilerek istenen telefon numarası birkaç adımda okunur. Dönen bilgi tek bir kayıt olabileceği gibi birden fazla kayıt da olabilir: karşı taraftan bir A kişisinin bilgisi istenmiş olabileceği gibi telefondaki B harfiyle başlayan bütün kişiler de istenmiş olabilir. Alttaki kod buna göre yazılır.

Benzer ikinci bir örnekte bir `CONTACT_REQUEST` değeri sıfır olarak tanımlanır. `onKeyDown` olayına bağlanan bir aksiyon gerçekleştiğinde `startActivityForResult` çağrılır, kişi bilgileriyle ilgilenildiği ve request code karşı tarafa bildirilir. Gelen veri işlendikten sonra, önceki koddan farklı olarak, bilgiyi ekranda göstermek için yeni bir aktivite `startActivity` ile başlatılır. <!-- BELİRSİZ: Bu ikinci örneğin slaytı kare olarak görülmedi; ayrıntılar yalnız altyazıdan alındı. -->

Hoca burada bu tür kodların anlatılarak hemen anlaşılmasının kolay olmadığını, önemli olanın genel kavramı anlayıp sonra deneyimlemek olduğunu söyledi. Sistematik kafada oturursa kod yazmak daha rahat olur.

## 4. Intent Filter Örnekleri

Bir aktivitenin bir aksiyonu gerçekleştirebileceği düşünülüyorsa, hangi veriyi işleyebildiği MIME tipleriyle bir intent filter içinde Android Manifest'te tanımlanır. Ekrandaki örnekte iki aktivite vardır: `MainActivity` ve `ShareActivity` (ekrandan, 00:35:00):

```xml
<activity android:name="MainActivity" android:exported="true">
    <!-- This activity is the main entry, should appear in app launcher -->
    <intent-filter>
        <action android:name="android.intent.action.MAIN" />
        <category android:name="android.intent.category.LAUNCHER" />
    </intent-filter>
</activity>

<activity android:name="ShareActivity" android:exported="false">
    <!-- This activity handles "SEND" actions with text data -->
    <intent-filter>
        <action android:name="android.intent.action.SEND"/>
        <category android:name="android.intent.category.DEFAULT"/>
        <data android:mimeType="text/plain"/>
    </intent-filter>
    <!-- This activity also handles "SEND" and "SEND_MULTIPLE" with media data -->
    <intent-filter>
        <action android:name="android.intent.action.SEND"/>
        <action android:name="android.intent.action.SEND_MULTIPLE"/>
        <category android:name="android.intent.category.DEFAULT"/>
        <data android:mimeType="application/vnd.google.panorama360+jpg"/>
        <data android:mimeType="image/*"/>
        <data android:mimeType="video/*"/>
    </intent-filter>
</activity>
```

Bir aktivitede birden fazla intent filter tanımlamakta hiçbir sakınca yoktur; aktivite birden fazla iş yapıyorsa her biri tanımlanmalıdır. Uygulamada örneğin 10 aktivite varsa, belli işleri üstlenecek olanların her biri kendi `<activity>` etiketi içinde intent filter'larla tanımlanır.

`MainActivity`'nin görevi launcher olmaktır; başka bir işe talip olmadığı için kimseye hizmet vermez, yalnız uygulama başlatılırken çağrılabilecek aktivite olduğu bildirilir. `ShareActivity` ise iki farklı iş vaat eder: biri düz metin (`text/plain`, HTML değil) gönderebilmek, diğeri `SEND` ve `SEND_MULTIPLE` ile bir ya da birden fazla görüntü veya video göndermektir. Bazı uygulamalar aynı anda tek dosya gönderebilir, bazıları birden fazla. Örneğin bir e-posta uygulaması birden fazla dosya gönderebiliyorsa intent'e birden fazla dosya konabilir. Hoca önce bu yeteneği olmayan bir uygulamaya çok dosya gönderilirse hata alınacağını söyledi, sonra daha doğru ifadeyle düzeltti: bu yeteneği olmayan uygulama, filtreleme sonrasında listede hiç görünmez.

Slaytın altındaki notta şu belirtilir: diğer uygulama Android 13 (API level 33) ya da üstünü hedefliyorsa, sizin intent'iniz ancak o uygulamanın `<intent-filter>`'ındaki aksiyon ve kategorilerle eşleşirse karşılanır. Sistem eşleşme bulamazsa `ActivityNotFoundException` fırlatır ve gönderen uygulama bu istisnayı ele almalıdır (ekrandan, 00:35:00). Yani bir iş yaptırmak istenip o işi yapabilecek hiçbir aktivite yoksa bu istisna oluşur.

Bir başka filtre örneğinde `ShareActivity` bir intent filter ile SMS gönderme, diğeriyle görüntü ve basit metin gönderme yeteneğine sahip olduğunu manifest'te bildirir.

## 5. Fotoğraf Çekme Intent'i ve Gelen Intent'i Karşılamak

### 5.1 Fotoğraf ya da video çekme

Bu yaygın intent, `startActivityForResult` konuşulduktan sonra görülsün diye bilerek sona bırakılmıştır. Karşı taraftan bir görüntü ya da video talep edilir (ekrandan, 00:40:00):

```java
static final int REQUEST_IMAGE_CAPTURE = 1;
static final Uri locationForPhotos;

public void capturePhoto(String targetFilename) {
    Intent intent = new Intent(MediaStore.ACTION_IMAGE_CAPTURE);
    intent.putExtra(MediaStore.EXTRA_OUTPUT,
            Uri.withAppendedPath(locationForPhotos, targetFilename));
    if (intent.resolveActivity(getPackageManager()) != null) {
        startActivityForResult(intent, REQUEST_IMAGE_CAPTURE);
    }
}

@Override
protected void onActivityResult(int requestCode, int resultCode, Intent data) {
    if (requestCode == REQUEST_IMAGE_CAPTURE && resultCode == RESULT_OK) {
        Bitmap thumbnail = data.getParcelableExtra("data");
        // Do other work with full size photo saved in locationForPhotos
        ...
    }
}
```

Önce intent'in yapıcısına `MediaStore.ACTION_IMAGE_CAPTURE` verilir. Fotoğrafın nereye kaydedileceği metoda `targetFilename` ile iletilir ve `putExtra` ile intent'e yüklenir. Intent, `startActivityForResult` ile ve request code (burada 1) ile gönderilir. Dönüşte işlem başarılıysa aktarılan resim bilgisi `data.getParcelableExtra("data")` ile `Bitmap` tipinde küçük resim (thumbnail) olarak alınır.

Aynı slaytın ikinci kod parçasında, bu isteği karşılayabilecek uygulama yoksa ne olacağı gösterilir (ekrandan, 00:40:00):

```java
static final int REQUEST_IMAGE_CAPTURE = 1;

private void dispatchTakePictureIntent() {
    Intent takePictureIntent = new Intent(MediaStore.ACTION_IMAGE_CAPTURE);
    try {
        startActivityForResult(takePictureIntent, REQUEST_IMAGE_CAPTURE);
    } catch (ActivityNotFoundException e) {
        // display error state to the user
    }
}
```

### 5.2 Kendi aktivitende gelen intent'i işlemek

Aktiviteniz dışarıdan bir bilgi alıp iş yapacaksa, `onCreate` içinde `setContentView`'dan sonra, aktivite çalışmaya başladığında `getIntent()` ile aktarılmış bilgi alınır. İçindeki veri bir `Uri` değişkenine atanır. Ardından taahhüt edilen tipler (resim, düz metin vb.) arasından hangisinin geldiği kontrol edilir, çünkü aktivite birden fazla iş vaat etmiş olabilir. Resim geldiyse resimle, metin geldiyse metinle ilgili iş yapılır. Aynı kontroller, isteği `startActivityForResult` ile gönderip dönüşü `onActivityResult`'ta işleyen tarafta da gerekir.

İş başarıyla tamamlanırsa `setResult(Activity.RESULT_OK)` çağrılır. Böylece çağıran tarafa bilgi döndürüldüğünde işin sorunsuz yapıldığı da aktarılmış olur.

## 6. Activity Result API

Şu ana kadar anlatılan yapı (`startActivityForResult` ve `onActivityResult`) basit olduğu için hâlâ kullanılmaktadır ve kaldırılmış değildir. Ancak Android son birkaç yıldır, dönen değerle ilgili iş yapılacaksa yeni bir API'yi önermektedir. Bu yapıda bir `ActivityResultLauncher` tanımlanır, kayıt (register) işlemi yapılır ve bir sonuç döndüğünde ne yapılacağı bir callback içinde kodlanır. Örneğin bir düğmeye bağlandıysa, tıklandığında launcher'ın `launch` metodu ilgili parametreyle çağrılır.

İkinci örnekte bu yapı ayrı bir sınıf olarak konumlandırılmıştır: bir result launcher ve bir `ActivityResultRegistry` vardır, yapılacak iş yine sonuç callback'inde yazılır. Fragment yapısında bir `LifecycleObserver` üzerinden süreç yürütülür. Fragment'lar, bir aktivitenin içindeki birbirinden bağımsız yürütülmesi beklenen parçalar için kullanılır ve Activity Result API fragment'larla uyumlu çalıştığı için daha çok tercih edilmeye başlanmıştır. <!-- BELİRSİZ: Activity Result API slaytlarının kodu karelerde görülmedi; sınıf ve metot adları altyazıdan (Whisper bozmalarıyla) kurulmuştur. -->

Ders kapsamında bu yapı yalnız tanıtıldı, üzerinde durulmadı. Daha profesyonel kod yazmak isteyenlere bu yapıya yakından bakmaları önerildi.

> **Ek bilgi (derste anlatılmadı):** Yeni API'de kayıt `registerForActivityResult(contract, callback)` ile yapılır; `contract` olarak örneğin `ActivityResultContracts.StartActivityForResult()` ya da `ActivityResultContracts.TakePicturePreview()` gibi hazır sözleşmeler kullanılır. Kaydın, aktivite ya da fragment oluşturulurken (örneğin alan tanımında ya da `onCreate` içinde) yapılması gerekir. Bu yapı request code ihtiyacını ortadan kaldırır, çünkü her launcher kendi callback'ine bağlıdır.

## 7. Layout'lar ve UI Bileşenleri

Derste layout'lara ve UI bileşenlerine çok fazla girilmeyecek olsa da kabaca bakıldı. ViewGroup'lar, View'ların yerleştiği, kendileri görünmeyen yapılardır. LinearLayout, RelativeLayout ve GridView bunlardandır; UI bileşenlerinin ekranda konumlanmasını kolaylaştırırlar. Ekrandaki şekilde bir ViewGroup'un altında bir ViewGroup ve iki View, alt ViewGroup'un altında da üç View vardır (ekrandan, 01:00:00).

Slayttaki örnekte bir LinearLayout içine bir TextView ve bir Button yerleştirilmiştir (ekrandan, 01:00:00):

```xml
<?xml version="1.0" encoding="utf-8"?>
<LinearLayout xmlns:android="http://schemas.android.com/apk/res/android"
              android:layout_width="match_parent"
              android:layout_height="match_parent"
              android:orientation="vertical" >
    <TextView android:id="@+id/text"
              android:layout_width="wrap_content"
              android:layout_height="wrap_content"
              android:text="Hello, I am a TextView" />
    <Button android:id="@+id/button"
            android:layout_width="wrap_content"
            android:layout_height="wrap_content"
            android:text="Hello, I am a Button" />
</LinearLayout>
```

`orientation` dikey (`vertical`) verildiği için bileşenler dikeyde hizalanır. RelativeLayout'ta bileşen, kendini konumlandırmak için seçtiği başka bir bileşene göre yerleşir. LinearLayout'ta ise alan dikey ve yatay eksende parçalara bölünerek konumlandırma yapılır. WebView bir web içeriğini göstermek için kullanılır.

Bir kimlik tanımlanırken `@+id/ad` yazılır; var olan bir kimliğe başvurulurken `@+id` yerine yalnız `@id/ad` kullanılır. Bir widget'ın onlarca niteliği olabilir; en temel olanları `id`, `layout_width`, `layout_height` ve `text`'tir. Diğerleri kurcalanarak öğrenilebilir.

Uygulamalarda gerçekten gereken bileşeni kullanmak akıllıcadır: ScrollView, RadioButton, RadioGroup gibi. Hep aynı ve kolay bileşenleri kullanmak yerine, örneğin tarih alınırken bir metin alanı yerine takvime uygun, seçilebilir bir aralık sunan bir bileşen kullanmak daha doğrudur. Bileşenlere yarım saat kadar göz gezdirmek kabaca hepsini tanımaya yeter, ayrıntılarına ihtiyaç duydukça bakılır.

`findViewById`, layout tarafındaki bileşeni kaynak koddaki değişkenle ilişkilendiren metottur ve bundan sonra daha sık kullanılacaktır.

## 8. Adapter ile Liste Gösterme: ListView

Layout'lar yalnız tek tek UI bileşenleri için değildir. Tekrar eden ya da sayısı çok olan verileri bir bütün halinde göstermek için de yapılar vardır: en basiti ListView'dur, ayrıca GridView ve RecyclerView vardır. Amaç, bir veritabanından ya da dosyadan liste halinde gelen bilgileri ekranda göstermektir: X tane duyuru, Y tane resim, Z tane video ya da bir anketin seçenekleri.

Ekranda ListView tek sütunlu kayan bir liste, GridView ise satır ve sütunlardan oluşan kayan bir ızgara olarak gösterilir (ekrandan, 01:05:00). ListView için bir `ArrayAdapter` oluşturup bağlamanın kodu şöyledir (ekrandan, 01:05:00):

```java
ArrayAdapter<String> adapter = new ArrayAdapter<String>(this,
        android.R.layout.simple_list_item_1, myStringArray);

ListView listView = (ListView) findViewById(R.id.listview);
listView.setAdapter(adapter);
```

Yapıcının argümanları: uygulamanın `Context`'i, dizideki her string için bir `TextView` içeren layout ve string dizisinin kendisi.

Temel mantık şudur: bir bilgi bütünü ekranda gösterilecekse veri kaynağı (data source) ile ekrandaki alan arasındaki ilişki bir adapter aracılığıyla kurulmalıdır. Bu yüzden adapter tanımı kritiktir. ListView'da bu adapter hazır sunulabilir; örneğin yalnız şehirler ya da ülkeler listelenecekse 3-4 satır kod yeter.

Ancak içerikler genelde bu kadar tek düze değildir: bir resim, o resmin tarihi ve açıklaması ya da bir kişinin görseli, telefon numarası, adı soyadı gibi daha özelleşmiş elemanlar gerekir. O zaman bir "dekorasyon" ihtiyacı doğar; eleman sayısı büyüdükçe basit yapı yetersiz kalır ve performans sorunları ortaya çıkar. Bu yüzden ListView yerini RecyclerView'a bırakmaya başlar.

Bir başka örnek `SimpleCursorAdapter`'dır. Mantık aynıdır: bir adapter tanımlanır ve kişi bilgilerini göstermek için ListView'a `setAdapter` ile bağlanır. Adapter'a bilgiler bir string dizisi ve bir integer dizisinden gelir. Ayrıca ListView'da `setOnItemClickListener` ile listedeki bir elemana tıklanınca ne yapılacağı yazılır; kullanıcı listede gezinirken bir elemana tıkladığında `onItemClick` kısmındaki kod çalışır.

## 9. RecyclerView ve ListView Karşılaştırması

Slayttaki iki ekran örneği RecyclerView ile oluşturulmuştur: birinde daha basit bir eleman yapısı (bir gelen kutusu listesi), diğerinde CardView kullanılmıştır (ekrandan, 01:10:00). Her eleman için hazırlanan XML layout, her yeni bilgi geldiğinde aynı biçimde şişirilerek (inflate) ekrana yerleştirilir ve liste böyle oluşur.

### 9.1 Neden RecyclerView öne geçti?

ListView'da 100 ya da 1000 eleman varsa her biri için ayrı bir eleman nesnesi oluşturmanız ve bellekte yer ayırmanız gerekir; yeniden kullanılabilirlik yoktur. Liste ilk oluşturulurken eleman sayısı büyükse performans sorunları başlar ve kaydırırken (scroll) elemanların kesintisiz akmasında problemler yaşanır. Eskiden bu sorunlar daha büyüktü, bazı iyileştirmeler yapıldı; basit veriler hâlâ böyle kurgulanabilir. Ama veri büyüdükçe, cihazın kaynaklarına bağlı olarak sorunlar büyüyebilir.

RecyclerView ise daha önce yaratılmış ama artık ekranda görünmeyen elemanların yeniden kullanılmasına olanak tanır. Böylece bin eleman yaratmak yerine, ekranda yirmi eleman görünüyorsa sonra gelebilecek birkaç tanesi hazır tutulur, henüz kaydırılmayanlar oluşturulmaz. Kaydırdıkça eski elemanların alanları yeniden kullanılır. Bu, çok elemanlı bir yapıda kaynak optimizasyonu açısından büyük avantaj sağlar.

### 9.2 Diğer farklar

- ViewHolder deseninin kullanımı RecyclerView'da zorunlu, ListView'da isteğe bağlıdır. ViewHolder, performans sorunlarını en aza indiren ve yeniden kullanımı mümkün kılan yapıdır.
- ListView yalnız dikey liste yapar; RecyclerView birden fazla layout manager'a sahiptir ve elemanları yatay ya da istenen başka bir düzende yerleştirebilir.
- ListView'da `OnItemClickListener` vardır; RecyclerView'da `OnItemTouchListener` vardır.
- Item decoration RecyclerView'da daha esnek ve çeşitlidir.
- Item animator ListView'da hiç yoktur; RecyclerView'da elemanların eklenmesi ve kaldırılması animasyonla gösterilebilir.

Slayttaki artı ve eksiler şöyledir (ekrandan, 01:15:00):

| | Artılar | Eksiler |
|---|---|---|
| ListView | Kolay uygulanır; `OnItemClickListener` | Büyük listelerde kötü performans; ViewHolder desenini kullanmak karmaşık (ama kullanılabilir); yalnız dikey liste |
| RecyclerView | Eleman ekleme, güncelleme ve silmede animasyon; item decoration (kenarlık, ayırıcı); liste ya da ızgara olarak kullanılabilir; DiffUtil ile birlikte kullanılabilir; özellikle `setHasFixedSize` ile daha hızlı; zorunlu ViewHolder deseni | Daha fazla kod, bazen gereksiz zorluk; `OnItemClickListener` eklemenin kolay yolu yok |

ListView basit bir mantığa sahip olduğu için, basit bir veri grubu gösterilecek yerlerde hâlâ tercih edilir; hiç kullanılmıyor denemez. ViewHolder desenini ListView'da kullanmak daha karmaşık olduğundan çoğu kişi kullanmaz, bu da performansı düşürür. RecyclerView'da animasyon ve dekorasyon ListView'un çok ötesindedir ve performans çok daha yüksektir. Hocaya göre yeni eleman eklenmeyecekse, yani dinamik bir eleman grubu yoksa `setHasFixedSize(true)` verilerek performans kazancı daha da artar; kaynak sürekli değişiyor ve boyut sık güncelleniyorsa bu `true` yapılamaz. RecyclerView'u geliştirmek daha zahmetlidir, daha fazla kod gerekir ve tıklama işi `OnItemTouchListener` ile daha karmaşık bir yapıyla yapılır.

Sonuç olarak basit, büyük olmayan veriler ve hızlı uygulama için ListView iyi bir seçenektir; karmaşık ve daha güzel görseller için performans etkisi de düşünüldüğünde RecyclerView daha avantajlıdır.

> **Ders sonrası not:** Hoca `setHasFixedSize(true)`'yu "yeni eleman eklenmeyecekse" kullanılacak bir ayar olarak anlattı. Android belgelerine göre bu ayar büyük olasılıkla daha dar bir anlam taşır: adapter içeriğindeki değişikliklerin RecyclerView'un kendi genişlik ve yüksekliğini değiştirmeyeceğini bildirir. Yani eleman eklenip silinse bile RecyclerView'un ekrandaki boyutu sabitse (örneğin `match_parent`) `true` verilebilir.

## 10. RecyclerView'ı Kurmak: Aktivite ve Adapter

### 10.1 Aktivite tarafı

Önce kaynak (resource) tarafında, aktivitenin XML layout dosyasına bir RecyclerView yerleştirilmelidir. Kaynak kod tarafında şu adımlar izlenir:

- RecyclerView ve adapter değişkenleri tanımlanır.
- RecyclerView, layout'taki RecyclerView ile `findViewById` ile eşleştirilir; buton ya da ImageView'da olduğu gibi, RecyclerView de bir UI bileşenidir.
- İstenirse `setHasFixedSize(true)` verilir; bu tamamen içeriğe bağlıdır, değişken içerikte doğru değildir.
- Bir layout manager tanımlanır; elemanların RecyclerView içinde nasıl konumlanacağını bu belirler.
- Yazılan adapter sınıfından (örnekte `MyAdapter`) bir nesne yaratılır ve veri kaynağı (`myDataset`) yapıcıya verilir.
- `recyclerView.setAdapter(...)` ile adapter bağlanır.

Bu kadar kısa bir ilişkilendirmeyle RecyclerView aktiviteye yerleştirilmiş olur; asıl iş adapter'dadır.

### 10.2 Adapter tarafı

`MyAdapter` sizin yazmanız gereken bir sınıftır; bu adapter yazılmadan RecyclerView kullanılamaz. Slayttaki kod şöyledir (ekrandan, 01:20:00):

```java
public class MyAdapter extends RecyclerView.Adapter<MyAdapter.MyViewHolder> {
    private String[] mDataset;

    // Provide a reference to the views for each data item
    // Complex data items may need more than one view per item, and
    // you provide access to all the views for a data item in a view holder
    public static class MyViewHolder extends RecyclerView.ViewHolder {
        // each data item is just a string in this case
        public TextView textView;
        public MyViewHolder(TextView v) {
            super(v);
            textView = v;
        }
    }

    // Provide a suitable constructor (depends on the kind of dataset)
    public MyAdapter(String[] myDataset) {
        mDataset = myDataset;
    }

    // Create new views (invoked by the layout manager)
    @Override
    public MyAdapter.MyViewHolder onCreateViewHolder(ViewGroup parent, int viewType) {
        // create a new view
        TextView v = (TextView) LayoutInflater.from(parent.getContext())
                .inflate(R.layout.my_text_view, parent, false);
        ...
        MyViewHolder vh = new MyViewHolder(v);
        return vh;
    }

    // Replace the contents of a view (invoked by the layout manager)
    @Override
    public void onBindViewHolder(MyViewHolder holder, int position) {
        // - get element from your dataset at this position
        // - replace the contents of the view with that element
        holder.textView.setText(mDataset[position]);
    }

    // Return the size of your dataset (invoked by the layout manager)
    @Override
    public int getItemCount() {
        return mDataset.length;
    }
}
```

Adapter `RecyclerView.Adapter`'dan türetilir ve bir ViewHolder verilir. ViewHolder için önce ekranda, yani her elemanda neyin görüneceği planlanır. Burada yalnız bir TextView vardır; örneğin yalnız şehirlerin listesi gösterilecekse TextView'da şehir adı yer alır. Adapter'a veri kaynağının bilgisi mutlaka aktarılmalıdır; burada bir string dizisi gelir. Bu, ListView tadında basit bir RecyclerView'dur; çok daha karmaşıkları yazılacaktır.

Yapıcılar oluşturulduktan sonra üç metot yazılır:

- `onCreateViewHolder`: her eleman için `LayoutInflater` kullanarak bir ViewHolder oluşturur, yani her elemanın görsel olarak bellekteki yerine yerleşmesini sağlar. Veri burada henüz basılmaz; yalnız eleman hangi biçimde olacaksa (bir yerde resim, yanında isim gibi) o eleman örneğinden yeni eleman geldikçe şişirilmesi sağlanır.
- `onBindViewHolder`: oluşturulan ViewHolder'ların içine veri kaynağındaki bilgi yazılır. O anda kaçıncı elemandaysak veri kaynağındaki o konumdaki veri alınıp holder'a basılır. Hocanın örneğiyle: veri kaynağı alfabetik bir şehir listesiyse birinci elemana Adana, ikinciye Adıyaman, üçüncüye Afyon gelir.
- `getItemCount`: adı değişmeyen bu metot veri kaynağının uzunluğunu döndürür ve mutlaka yazılmalıdır.

Bu metotlar her eleman için çalışır: önce bir layout oluşturulur, sonra `onBindViewHolder` ile içine veri basılır.

### 10.3 İkinci adapter örneği: CustomAdapter

Ekrandaki ikinci adapter da `RecyclerView.Adapter`'dan türetilmiş özel bir adapter'dır (ekrandan, 01:25:00):

```java
public class CustomAdapter extends RecyclerView.Adapter<CustomAdapter.ViewHolder> {

    private String[] localDataSet;

    /**
     * Provide a reference to the type of views that you are using
     * (custom ViewHolder).
     */
    public static class ViewHolder extends RecyclerView.ViewHolder {
        private final TextView textView;

        public ViewHolder(View view) {
            super(view);
            // Define click listener for the ViewHolder's View

            textView = (TextView) view.findViewById(R.id.textView);
        }

        public TextView getTextView() {
            return textView;
        }
    }

    /**
     * Initialize the dataset of the Adapter.
     *
     * @param dataSet String[] containing the data to populate views to be used
     * by RecyclerView.
     */
    public CustomAdapter(String[] dataSet) {
        localDataSet = dataSet;
    }

    // Create new views (invoked by the layout manager)
    @Override
    public ViewHolder onCreateViewHolder(ViewGroup viewGroup, int viewType) {
        // Create a new view, which defines the UI of the list item
        View view = LayoutInflater.from(viewGroup.getContext())
                .inflate(R.layout.text_row_item, viewGroup, false);

        return new ViewHolder(view);
    }

    // Replace the contents of a view (invoked by the layout manager)
    @Override
    public void onBindViewHolder(ViewHolder viewHolder, final int position) {

        // Get element from your dataset at this position and replace the
        // contents of the view with that element
        viewHolder.getTextView().setText(localDataSet[position]);
    }

    // Return the size of your dataset (invoked by the layout manager)
    @Override
    public int getItemCount() {
        return localDataSet.length;
    }
}
```

Yine bir string dizisi (`localDataSet`) ve tek bir TextView vardır. TextView, ViewHolder içinde layout'taki TextView ile ilişkilendirilir; ayrıca onu dışarıya veren bir `getTextView` metodu yazılmıştır. Yapıcıya veri kümesi verilir. `onCreateViewHolder`'daki kritik nokta, `inflate`'e verilen ilk parametredir: `R.layout.text_row_item`. Bu, elemanın ekranda nasıl görüneceğini belirleyen XML dosyasının adıdır. RecyclerView'daki elemanların aynı tipte gösterilmesi için en az bir eleman XML dosyası tanımlanmalıdır. Eleman üzerine kaç bilgi yüklenecekse (resim, ad soyad, telefon numarası, tarih gibi) bu XML'de düzenlenir; bilgi ise `onBindViewHolder` üzerinden yüklenir.

### 10.4 CardView

Kart tabanlı (card based) layout, görselin daha iyi konumlandırıldığı, yeni nesil uygulamaların daha çok tercih ettiği bir eleman biçimidir. Bu yapı ana aktivitenin layout'u içine yerleştirilir; içine konacak başka bir şey varsa o da eklenir.

## 11. Android Studio Örneği: ListView ile Liste

Hoca telefon ekranını paylaşarak önceki hafta yazılan giriş ekranından devam etti: kullanıcı adı ve şifre olarak "admin", "admin" girilip giriş düğmesine basılınca başka bir aktivite çağrılıyordu. Bu kez çağrılan aktivite `ListOfPL` (List of Programming Languages) idi. Ekranda, bir anket gibi, çeşitli platform ve programlama dillerinin listesi gelir; bir elemana tıklanınca altta bir Toast mesajıyla tıklanan elemanın adı görünür.

Aktivitenin XML dosyasında yalnız bir ListView tanımlıdır; RecyclerView kullanılmamıştır. Hoca, layout'taki bileşen ile kaynak koddaki değişkenin farkı belli olsun diye koddaki değişkenin adını `listView_sc` olarak değiştirdi: layout tarafındaki `listView` UI bileşenini, `listView_sc` ise kaynak kod içinde o bileşeni temsil eder. Kodun son hali şöyledir (ekrandan, 01:35:00):

```java
public class ListOfPL extends AppCompatActivity {
    ListView listView_sc;
    TextView textView;
    String[] listItem;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_listofpl);

        listView_sc=(ListView)findViewById(R.id.listView);

        listItem = getResources().getStringArray(R.array.array_technology);

        final ArrayAdapter<String> adapter = new ArrayAdapter<String>(this,
                android.R.layout.simple_list_item_1, android.R.id.text1, listItem);
        listView_sc.setAdapter(adapter);

        listView_sc.setOnItemClickListener(new AdapterView.OnItemClickListener() {
            @Override
            public void onItemClick(AdapterView<?> adapterView, View view, int position, long l) {
                // TODO Auto-generated method stub
                String value=adapter.getItem(position);
                Toast.makeText(getApplicationContext(),value,Toast.LENGTH_SHORT).show();
            }
        });
    }
}
```

`ArrayAdapter` satırı 01:35:00 karesinde ekranın sağından taşmaktadır; satırın devamı (`android.R.id.text1, listItem`) 01:30:00 karesinden alınmıştır (ekrandan, 01:30:00).

Hoca öğrencilere `getResources().getStringArray(R.array.array_technology)` satırının ne yaptığını sordu (bu soru "Örnek Sorular" bölümündedir). Projede bir `res` (resources) klasörü vardır; altında `drawable`, `layout` ve `values` klasörleri bulunur, `values` altında da `strings.xml` vardır. Bu satır, `strings.xml`'de tanımlı `array_technology` adlı string dizisindeki bilgileri alıp `listItem` adlı String dizisine atar. Yani veri kaynağı tamamen `strings.xml` içindeki string dizisidir. İleride bu kaynak bir dosya, kullanıcının girdiği bilgi, ağ ya da veritabanı olabilir.

Ardından bir `ArrayAdapter` tanımlanır; kaynakla ekrandaki bilgiyi bağlamak için gereklidir. Hangi layout tipinde görüneceği yazılır: `simple_list_item_1`, bizim tanımlamadığımız, eleman için özel bir XML oluşturmadığımız, sistemde hazır bulunan bir biçimdir. Kullanımı bu yüzden çok kolaydır; yaptığı tek şey elemanları telefon ekranında görülen biçimde yazmaktır. Kaynağın ne olduğu da adapter'a verilir. Sonra adapter (adı `myAdapter` da olabilirdi) ListView'a `setAdapter` ile verilir.

`setOnItemClickListener` ile tıklama etkin hale getirilir. `onItemClick` içinde `adapter.getItem(position)` ile tıklanan elemanın değeri alınır ve `value` değişkenindeki bu değer `Toast` mesajıyla ekrana yazdırılır.

> **Ders sonrası not:** Hoca konuşurken bu çağrıyı "Adapter.GetItemPosition" diye okudu; ekrandaki kodda çağrı `adapter.getItem(position)`'dır (ekrandan, 01:35:00).

## 12. Android Studio Örneği: Çok Tipli RecyclerView

### 12.1 Uygulamanın görünümü

Bu kez giriş ekranından, RecyclerView'un bulunduğu başka bir aktivite (`ListModel`) çağrıldı. Ekranda dört eleman vardır: birincisinde yalnız bir metin ("Hello. This is the Text-only View Type..."), ikincisinde bir metin ve bir resim, üçüncüsünde bir metin ve bir ses düğmesi (basılınca ses çalar), dördüncüsünde yine bir metin ve bir resim. Hoca bu örneği, farklı tipteki elemanların aynı aktivitede aynı anda gösterilebileceğini göstermek için seçti.

### 12.2 Aktivite: veri kaynağını kurmak

`ListModel` aktivitesinin kodu şöyledir (ekrandan, 01:50:00):

```java
public class ListModel extends AppCompatActivity {
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_listmodel);
        Toolbar toolbar = (Toolbar) findViewById(R.id.toolbar);
        //setSupportActionBar(toolbar);

        ArrayList<Model> list= new ArrayList<>();
        list.add(new Model(Model.TEXT_TYPE, "Hello. This is the Text-only View Type. Nice to meet you", 0));
        list.add(new Model(Model.IMAGE_TYPE, "Hi. I display a cool image too besides the omnipresent TextView.", R.drawable.wtc));
        list.add(new Model(Model.AUDIO_TYPE, "Hey. Pressing the FAB button will playback an audio file on loop.", R.raw.sound));
        list.add(new Model(Model.IMAGE_TYPE, "Hi again. Another cool image here. Which one is better?", R.drawable.snow));

        MultiViewTypeAdapter adapter = new MultiViewTypeAdapter(list, this);
        LinearLayoutManager linearLayoutManager = new LinearLayoutManager(this, RecyclerView.VERTICAL, false);

        RecyclerView mRecyclerView = (RecyclerView) findViewById(R.id.recyclerView);
        mRecyclerView.setLayoutManager(linearLayoutManager);
        mRecyclerView.setItemAnimator(new DefaultItemAnimator());
        mRecyclerView.setAdapter(adapter);
    }
}
```

Önce aktivitenin layout'u bağlanır ve bir toolbar tanımlanır. Sonra tipi `Model` olan bir `ArrayList` oluşturulur ve elemanlar tek tek eklenir. Birinci elemana tip olarak `TEXT_TYPE` ve metin verilir. İkincisi `IMAGE_TYPE`'tır; metinden sonra `drawable` altına konmuş `wtc` adlı resim verilir. Üçüncüsü `AUDIO_TYPE`'tır; `res` altındaki `raw` klasörüne konmuş `sound` adlı ses dosyası verilir (biraz önce çalan ses budur). Dördüncüsü yine `IMAGE_TYPE`'tır ve `drawable` altındaki `snow` resmi verilir. Böylece veri kaynağı, hem koda gömülü (hard-coded) metinlerden hem de `drawable` ve `raw` altındaki kaynak dosyalardan kurulur.

Veri kaynağı hazır olunca `MultiViewTypeAdapter` adlı adapter'dan bir nesne yaratılır ve listeyi alır. `LinearLayoutManager` ile dikey bir doğrusal düzen yaratılır. Layout içine yerleştirilmiş RecyclerView `findViewById` ile bulunur. `setLayoutManager` ile RecyclerView'un bu doğrusal düzeni kullanacağı söylenir. `setItemAnimator`'a varsayılan animatör (`DefaultItemAnimator`) verilir; özel bir aksiyon istenmediği için bu satır yazılmasa da olur. En önemlisi, `setAdapter` ile adapter RecyclerView'a verilir ve veri kaynağı ile ekran arasındaki ilişki kurulur. Arkada adapter ve model tanımlıysa aktivite artık çalışır.

### 12.3 Model sınıfı

Model çok basit bir veri modelidir: `TEXT_TYPE` 0, `IMAGE_TYPE` 1, `AUDIO_TYPE` 2 olarak sabit (hard-coded) tanımlanmıştır ve bir yapıcı vardır. Gelen bilgileri alır ve saklar; modelin yaptığı bundan ibarettir.

### 12.4 Adapter: alanlar ve ViewHolder'lar

`MultiViewTypeAdapter` sınıfının başı şöyledir (ekrandan, 02:10:00):

```java
public class MultiViewTypeAdapter extends RecyclerView.Adapter<RecyclerView.ViewHolder> {

    private ArrayList<Model> dataSet;
    Context mContext;
    int total_types;
    MediaPlayer mPlayer;
    private boolean fabStateVolume = false;
    ...
```

Burada sonradan kullanılacak bir `ArrayList` ve sesi çalmak için bir `MediaPlayer` (`mPlayer`) vardır. Asıl önemli kısım ViewHolder'lardır. Bütün elemanlar aynı tipte olsaydı tek bir ViewHolder tanımlanacaktı; ama elemanlar farklı tipte olduğu için kaç tip varsa o kadar ViewHolder tanımlanır:

- `TextTypeViewHolder`: adı hocanın verdiği bir addır, hazır bir ad değildir (`MyViewHolder` da denebilirdi). `RecyclerView.ViewHolder`'dan türer; içinde metin için bir UI bileşeni (`txtType`) ve bir CardView vardır, ikisi de layout'taki karşılıklarıyla ilişkilendirilir. Listenin en üstündeki eleman için kullanılır.
- `ImageTypeViewHolder`: bir TextView ve bir ImageView içerir.
- `AudioTypeViewHolder`: bir TextView ve `fab` adlı bir FloatingActionButton içerir.

Hoca burada kısa bir karışıklığı düzeltti: her ViewHolder'ın kullandığı `itemView`, o tipe ait eleman XML'inden gelir. `ImageTypeViewHolder` `image_type.xml`'i, `AudioTypeViewHolder` `audio_type.xml`'i kullanır. Örneğin `audio_type.xml`'de `@+id/fab` ile tanımlanan bileşene ViewHolder'da `R.id.fab` ile başvurulur. Bu yüzden ViewHolder'lar için mutlaka bir XML tanımlanmalıdır. ListView'da bu biçim hazır veriliyordu; burada ViewHolder'lar ilgili eleman layout'larıyla ilişkilendirilmelidir.

Projede ayrıca `mylist.xml` adlı, yalnız bir TextView içeren bir eleman layout'u da bulunmaktadır (ekrandan, 01:55:00):

```xml
<?xml version="1.0" encoding="utf-8"?>

<TextView xmlns:android="http://schemas.android.com/apk/res/android"
    android:id="@+id/textView"
    android:layout_width="wrap_content"
    android:layout_height="wrap_content"
    android:text="Medium Text"
    android:textStyle="bold"
    android:textAppearance="?android:attr/textAppearanceMedium"
    android:layout_marginLeft="10dp"
    android:layout_marginTop="5dp"
    android:padding="2dp"
    android:textColor="#4d4d4d"
    />
```

### 12.5 onCreateViewHolder ve getItemViewType

ViewHolder'lar tasarlandıktan sonra adapter'ın yapıcısı gelir; veriler buraya aktarılır. Sonra ViewHolder'ların yaratılmasına geçilir. `onCreateViewHolder`'da gelen `viewType`'a bakılır: model `TEXT_TYPE` ise `LayoutInflater` metin tipinin XML'ini, `IMAGE_TYPE` ise resim tipinin XML'ini, `AUDIO_TYPE` ise ses tipinin XML'ini şişirir ve ilgili ViewHolder döndürülür. Metin tipinin XML'inde yalnız bir TextView vardır.

Demek ki `onCreateViewHolder`'da istenirse birden fazla tipte eleman şişirilebilir. Bütün elemanlar aynı tipte olsaydı `switch` ve `case`'lere hiç gerek olmayacaktı: yalnız şişirilecek layout XML'i seçilecek ve her eleman yaratıldığında o şişirilecekti.

`getItemViewType`'ta ise o konumdaki elemanın tipi alınır ve ona karşılık gelen sabit döndürülür (ekrandan, 02:00:00):

```java
        case 0:
            return Model.TEXT_TYPE;
        case 1:
            return Model.IMAGE_TYPE;
        case 2:
            return Model.AUDIO_TYPE;
        default:
            return -1;
```

`switch` ifadesinin başı karede görünmemektedir. <!-- BELİRSİZ: getItemViewType'ın switch satırı kare dışında kaldı; altyazıya göre konumdaki modelin type alanı üzerinden seçim yapılıyor. -->

### 12.6 onBindViewHolder

`onBindViewHolder`'da veri kaynağından o konumdaki model nesnesi alınır; nesne varsa tipine göre ilgili alanlar doldurulur (ekrandan, 02:00:00):

```java
@Override
public void onBindViewHolder(final RecyclerView.ViewHolder holder, final int listPosition) {

    Model object = dataSet.get(listPosition);
    if (object != null) {
        switch (object.type) {
            case Model.TEXT_TYPE:
                ((TextTypeViewHolder) holder).txtType.setText(object.text);

                break;
            case Model.IMAGE_TYPE:
                ((ImageTypeViewHolder) holder).txtType.setText(object.text);
                ((ImageTypeViewHolder) holder).image.setImageResource(object.data);
                break;
            case Model.AUDIO_TYPE:

                ((AudioTypeViewHolder) holder).txtType.setText(object.text);


                ((AudioTypeViewHolder) holder).fab.setOnClickListener(new View.OnClickListener() {
                    @Override
                    public void onClick(View view) {
                        ...
```

İlk eleman yalnız metin içerdiği için `txtType` değişkenine `setText` ile metin yazılır ve iş biter. Resim tipinde iki UI bileşeni vardır: `setImageResource` ile resim konur, `setText` ile mesaj yazılır; yani bind sırasında holder'a iki bilgi aktarılır. Ses tipinde iş biraz daha karmaşıktır: metin yazıldıktan sonra, FloatingActionButton'a tıklandığında müzik çalabilmesi için `setOnClickListener` çağrılır. `onClick` içinde ses çalıyorsa durdurulur, çalmıyorsa (`else` kolunda) başlatılır; düğmedeki görselin değişmesi de burada eklenir. <!-- BELİRSİZ: onClick gövdesinin ayrıntısı (fabStateVolume kontrolü, MediaPlayer çağrıları, simge değişimi) karede görünmüyor; yalnız altyazıdan özetlendi. -->

Unutulmaması gereken son yer `getItemCount`'tur: eleman sayısını döndüren bu metot mutlaka yazılmalıdır.

### 12.7 Tek tipli adapter için özet

Hoca adapter'ı tekrar özetledi. Adapter oluştururken bir ViewHolder nesnesine ihtiyaç vardır; aynı tipte elemanlar kullanılacaksa tek bir ViewHolder (örneğin `MyViewHolder`) yeterlidir, bu örnekteki gibi birden fazlasına gerek yoktur. ViewHolder'dan sonra adapter'ın yapıcısı yazılır. `onCreateViewHolder`'da elemanın XML tasarımı kullanılarak şişirme yapılır; tek tipte bu da tek bir satırdır, burada olduğu gibi üç değil. `onBindViewHolder`'da şişirilen ViewHolder'ların içi, veri kümesindeki bilgilerle doldurulur: her biri ViewHolder'ın ilgili gözüne `setText`, `setImageResource` gibi metotlarla yerleştirilir. Son olarak veri kaynağının boyutunu döndüren `getItemCount` gerekir.

> **Hocanın vurgusu:** En önemli kısım adapter'dır. Uygulamanızdaki elemanlar için adapter bir kez oluşturulunca iş çok kolaylaşır; oradan başlamak akıllıcadır.

Hoca `MultiViewTypeAdapter` ve `ListModel` dosyalarını öğrencilerle paylaştı. Bu kodlar daha karmaşık bir örnektir; amaç kodu anlamak ve kendi basit yapınıza dönüştürmektir.

## 13. Mezun Bilgi Sistemi: Duyuru Ekranı Tasarımı

Hoca tablette "YTU CE Mezun Uygulaması" başlıklı bir çizimle uygulamanın ekranlarını anlattı (ekrandan, 02:05:00):

- Sign In ekranı: tasarıma bağlı olarak kullanıcı adı ve şifre alanları ile giriş düğmesi ve kayda yönlendiren bir Sign Up düğmesi.
- Sign Up ekranı: kullanıcı adı, şifre, ad, soyad, resim, giriş yılı ve mezuniyet yılı.
- Girişten sonra açılan duyuru ekranı: her elemanın solunda bir resim (image), yanında duyuru başlığı ve tarih bulunan, alt alta tekrar eden bir liste.

Kullanıcı kayıt olup kullanıcı adı ve şifre belirledikten sonra giriş yapınca ilk olarak duyuru sayfası açılır. Burada 5-10 kadar duyuru olur ve kullanıcı duyurular arasında kaydırabilir. Bu liste doğal olarak bir RecyclerView olacaktır. Bunun için bir model de oluşturulmalıdır; modelin alanları resim (image), duyuru başlığı (announcement head) ve tarih (date) olarak çizildi. Bir duyuruya tıklanınca (`OnItemTouchListener` üzerinden) duyurunun ayrıntısını gösteren başka bir sayfaya geçilir. İlk aşamada veriler, örnekteki `ArrayList` gibi koda gömülü olarak girilebilir; daha sonra veritabanı ya da dosya üzerinden düzenlenecektir.

Kayıt ekranında kamerayı açıp bir aktiviteyle görüntü almak ve bu görüntüyü kayıtla birlikte sisteme resim olarak yüklemek de beklenen işlerdendir. Hoca, elemanların bu çizimdeki gibi konumlanmasının zorunlu olmadığını; LinearLayout yerine GridView ya da CardView da kullanılabileceğini söyledi.

## 14. Uygulama Bölümündeki Sorular

**Soru:** Kayıt (sign up) ekranında kullanıcı adı ve şifre girildikten sonra, giriş (sign in) ekranında bu bilgilerle girilebilmesi için bilgilerin bir yere kaydedilmesi mi gerekiyor? **Cevap:** Evet. Kayıtta girilen bilgiler saklanır, girişte bu bilgilerle giriş kabul edilir ve ardından mezun uygulaması (ilk olarak duyurular) açılır.

**Soru:** Gradle sürümleriyle ilgili hatalar nasıl aşılabilir? **Cevap:** Gradle sürüm uyumsuzluğunu çözmek için belli Gradle sürümlerinin bilgisayara indirilmesi gerekebilir; ama kodu yazan kişinin kullandığı kütüphanelerle sizin yapılandırmanız uyumlu olmayabilir. Tavsiye, bulunan kodu kendi yeni açtığınız temiz bir projeye dosya dosya, parça parça almaktır. Sürüm uyumsuzluklarını gidermeye harcanan çaba bazen çok daha uzun sürer.

**Soru:** Bir uygulamada giriş yapıldıktan sonra görünen yükleme ekranı, kodun çalışma süresine göre kendiliğinden mi oluşur, yoksa geliştirici mi koyar? **Cevap:** Ekranda "loading" gibi bir görüntü ya da bir ilerleme çubuğu (progress bar) varsa onu geliştirici koyar, işletim sistemi koymaz. Uzun sürecek işlerde (örneğin 100 dosya indiriliyorsa) bir progress bar konması ve kullanıcının ilerlemeyi görmesi istenir. Ama geçişlerin kısa tutulması önerilir; uzun süren açılışa sahip mobil uygulamalar tasarlamaktan kaçınılır.

**Soru:** Ekranın üstünde görünen "MyApplication" sayfanın adı mı, uygulamanın adı mı? **Cevap:** Uygulamanın adıdır ve `strings.xml`'de yer alır. Bu tür bilgiler genelde `strings.xml` gibi kaynak dosyalarında tutulur. Uygulamanın ana ekranda görünen ikonu da geliştirici tarafından belirlenebilir. İkondan ada ve menüye kadar ekran tasarımı önemlidir: altta sekmeler (tab), sağ üstte bir menü ya da altta artı simgeli bir floating action button ile açılan seçenekler kullanılabilir.

**Soru:** Kullanıcı bilgileri yerel bir veritabanında mı, yoksa Firebase'de mi saklanmalı? **Cevap:** İlk aşamada bilgiler, uygulama kapanınca kaybolacak biçimde veri modelinde (`ArrayList` ile, `list.add` mantığıyla) tutulabilir; uygulama tekrar açılınca yine koddan yüklenir. Ancak bu çok anlamlı değildir. Kalıcı (persistent) saklama birkaç hafta sonra işlenecek olsa da isteyenler şimdiden yerel veritabanı ya da Firebase'e bakmaya başlayabilir; böylece aynı emek iki kez harcanmaz. İkisi de kabul edilebilir.

Hoca ayrıca `Toast` gibi çağrılarda context olarak `this` yerine genellikle `getApplicationContext()`'i tercih ettiğini söyledi. Gerekçesi, `this` ifadesinin bulunulan yere (aktivite mi, iç sınıf mı) göre farklı bir context'i göstermesi ve bunun birçok noktada sorun yaratabilmesidir.

> **Ders sonrası not:** `getApplicationContext()` Toast gibi işler için uygundur. Ancak diyalog göstermek, layout şişirmek ya da tema gerektiren işler için büyük olasılıkla aktivitenin kendi context'i (`MainActivity.this` gibi) gerekir; uygulama context'iyle bu işler hata verebilir veya temayı yansıtmayabilir. Anonim iç sınıf içinde `this`, aktiviteyi değil o iç sınıfı gösterir; bu durumda `AktiviteAdi.this` yazılır.

## Örnek Sorular

**Soru 1** (derste sözlü, 01:31:15; kod ekrandan, 01:35:00): `ListOfPL` aktivitesindeki şu satır ne yapar?

```java
listItem = getResources().getStringArray(R.array.array_technology);
```

> **Cevap (derste verildi):** Bir öğrenci, "resources içinde oluşturulmuş string dizisini listItem'a atıyor" diye cevap verdi. Hoca açıkladı: `getResources()` projenin `res` klasörüne erişir; `getStringArray(R.array.array_technology)` ise `res/values/strings.xml` içinde tanımlı `array_technology` adlı string dizisini okur ve sonucu `listItem` adlı `String[]` değişkenine atar. Böylece listenin veri kaynağı `strings.xml`'deki dizi olur; bu dizi daha sonra `ArrayAdapter` ile ListView'a bağlanır.

**Soru 2** (derste sözlü, 01:10:01): RecyclerView neden ListView'un önüne geçmiştir?

> **Cevap (derste verildi):** ListView her eleman için ayrı nesne yaratıp bellekte yer ayırır ve yeniden kullanım yapmaz; büyük listelerde kaydırma performansı düşer. RecyclerView ekrandan çıkan elemanların görünümlerini yeniden kullanır (ekranda 20 eleman görünüyorsa 1000 eleman için nesne yaratmaz), ViewHolder desenini zorunlu tutar, farklı layout manager'larla yatay/dikey/ızgara düzen kurabilir, daha esnek item decoration ve item animator sunar.

**Soru 3** (derste sözlü, 01:23:01; kod ekrandan, 01:20:00): Bir RecyclerView adapter'ında yazılması zorunlu üç metot hangileridir ve her biri ne yapar?

> **Cevap (derste verildi):** `onCreateViewHolder` eleman layout XML'ini `LayoutInflater` ile şişirip bir ViewHolder döndürür (veri henüz konmaz). `onBindViewHolder(holder, position)` veri kümesindeki o konumdaki veriyi ViewHolder'ın bileşenlerine yazar (örneğin `holder.textView.setText(mDataset[position])`). `getItemCount()` veri kümesinin boyutunu döndürür (`mDataset.length`).

**Soru 4** (derste sözlü, 02:21:28): Giriş yapıldıktan sonra uygulama açılırken görünen yükleme ekranını kim koyar?

> **Cevap (derste verildi):** Geliştirici koyar; işletim sistemi kendiliğinden bir yükleme ekranı eklemez. Uzun işlerde ilerlemeyi gösteren bir progress bar önerilir, ama mobil uygulamada uzun açılış sürelerinden kaçınılmalıdır.

## Dersin Toparlaması

Bu derste intent konusu, sonuç bekleyen çağrılarla tamamlandı. Alarm, zamanlayıcı, kişi ekleme, dosya açma, medya oynatma ve fotoğraf çekme gibi yaygın intent'ler üzerinden hem başka uygulamadan iş isteme hem de manifest'te intent filter ile bir işi üstlenme yönü görüldü. `startActivityForResult` ile request code'un isteği, result code'un işin başarısını, dönen intent'in ise veriyi taşıdığı; karşılayan aktivitenin `getIntent()` ile veriyi alıp `setResult(Activity.RESULT_OK)` ile cevap verdiği anlatıldı. Eşleşen aktivite yoksa `ActivityNotFoundException`'ın yakalanması gerektiği ve yeni Activity Result API'nin varlığı da not edildi.

Dersin ikinci yarısında layout'lar kısaca tanıtıldı ve çok sayıda veriyi göstermek için adapter mantığı işlendi. ListView'un kolay ama büyük listelerde yavaş olduğu, RecyclerView'un ise görünümleri yeniden kullanarak, zorunlu ViewHolder deseni ve layout manager'larla daha esnek ve hızlı olduğu gösterildi. Android Studio'da hem hazır `simple_list_item_1` biçimiyle bir ListView örneği hem de metin, resim ve ses elemanlarını aynı listede gösteren çok tipli bir RecyclerView örneği incelendi. Bu bilgiler mezun bilgi sistemindeki duyuru ekranına (resim, başlık ve tarih içeren elemanlar, tıklanınca ayrıntı sayfası) uygulanacaktır; kameradan resim alma ve kayıt ekranına ekleme de sonraki adımdır.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
