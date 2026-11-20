# Ders 7 Çalışma Özeti

## Genel Konular

- Yaygın (common) intent'ler
  - Implicit intent'le seçim ekranı tekrar hatırlatıldı: kullanıcı bir uygulamayı "her zaman" (always) seçerse liste bir daha gelmez. Her seferinde seçenek gösterilmesi isteniyorsa `createChooser` kullanılır.
  - Alarm kurma: `new Intent(AlarmClock.ACTION_SET_ALARM)` ile intent yaratılır, `putExtra` ile `AlarmClock.EXTRA_MESSAGE`, `EXTRA_HOUR`, `EXTRA_MINUTES` yüklenir, `resolveActivity(getPackageManager()) != null` kontrolünden sonra `startActivity` çağrılır. Manifest'e `com.android.alarm.permission.SET_ALARM` izni eklenmelidir (ekrandan, 00:15:00).
    - Mesaj verilmezse ekranda mesaj görünmez; saat ve dakika ise mutlaka verilmelidir.
    - Aynı işi karşılayan bir uygulama yazılıyorsa aktivitenin `<intent-filter>`'ına `android.intent.action.SET_ALARM` ve `android.intent.category.DEFAULT` eklenir.
  - Zamanlayıcı (timer): aksiyonu `ACTION_SET_TIMER`'dır. Mesaj, süre ve kullanıcı ekrandan çıkınca zamanlayıcının arka planda sürüp sürmeyeceği bilgisi aktarılır. İzin ve intent filter mantığı alarmla aynıdır.
  - Kişi ekleme: `ACTION_INSERT` her zaman kişi eklemek anlamına gelmediği için `setType` ile kişilerle ilgili olduğu belirtilir; ad, e-posta (istenirse telefon) `putExtra` ile verilir.
  - Belirli tipte dosya açma: `Intent.ACTION_OPEN_DOCUMENT`, `setType("image/*")`, `addCategory(Intent.CATEGORY_OPENABLE)` ve `startActivityForResult(intent, REQUEST_IMAGE_OPEN)` kullanılır; `REQUEST_IMAGE_OPEN = 1` tanımlıdır. Sonuç `onActivityResult` içinde `data.getData()` ile `Uri` olarak alınır (ekrandan, 00:20:00).
    - `setType` ile `image/*` yerine daha dar tipler (örneğin yalnız JPEG ya da PNG) istenebilir; uyumsuz tipte dosya gelince kullanıcıyı uyarmak geliştiricinin işidir.
  - Medya dosyası oynatma: `Intent.ACTION_VIEW` ve `setData(file)` ile sistem, dosyayı oynatabilecek uygulamaları sunar. Örnek intent filter yalnız `audio/*` ve `application/ogg` tiplerini kabul eder; video gibi başka tipte istek gelirse bu uygulama listelenmez (ekrandan, 00:25:00).
- `startActivityForResult` ile sonuç alma
  - Başka bir aktiviteyi çağırıp ondan bilgi beklendiğinde kullanılır: bir işin yapılıp yapılmadığı, bir kişi bilgisi, bir resim, bir indirme adresi ya da form bilgisi dönebilir.
  - Request code: bir aktivite birden çok tipte istek yapabildiği için her isteğe bir kod verilir (örneğin kişi seçme 1, resim seçme 2). Dönüşte hangi isteğin cevabı geldiği bu kodla anlaşılır.
  - Result code: işin yapılıp yapılamadığını söyler; `RESULT_OK` başarılı, `RESULT_CANCELED` başarısız demektir.
  - `onActivityResult(int requestCode, int resultCode, Intent data)` üç parametre alır; dönen intent bütün bilgiyi taşır.
  - Kişi seçme örneği: `requestCode == PICK_CONTACT_REQUEST` ve `resultCode == RESULT_OK` kontrolünden sonra `resultIntent.getData()` ile kişinin `Uri`'si alınır, `getContentResolver().query(...)` ile bir `Cursor` açılır ve `Phone.NUMBER` sütunundan telefon numarası okunur (ekrandan, 00:30:00).
  - İsteği karşılayacak aktivite yoksa `ActivityNotFoundException` fırlatılır; `try-catch` ile yakalanıp uygulamanın çökmesi önlenmelidir. Bu `startActivity` için de geçerlidir.
- Intent filter örnekleri
  - Bir aktivitenin içinde birden fazla `<intent-filter>` tanımlanabilir; her aktivite yapabildiği işleri ayrı ayrı bildirir (ekrandan, 00:35:00).
  - `MainActivity`: `action.MAIN` ve `category.LAUNCHER` ile yalnız uygulamanın giriş noktasıdır, başka uygulamalara hizmet vermez.
  - `ShareActivity`: bir filtreyle `text/plain` veriyle `SEND`, ikinci filtreyle `SEND` ve `SEND_MULTIPLE` aksiyonlarıyla resim ve video gönderebildiğini bildirir.
  - Birden fazla dosya gönderemeyen bir uygulama, `SEND_MULTIPLE` isteğinde seçenekler listesinde hiç görünmez.
  - Hedef uygulama Android 13 (API 33) ya da üstünü hedefliyorsa, intent ancak onun intent filter'ındaki aksiyon ve kategorilerle eşleşirse karşılanır; eşleşme yoksa `ActivityNotFoundException` fırlatılır (ekrandan, 00:35:00).
- Fotoğraf çekme intent'i
  - `MediaStore.ACTION_IMAGE_CAPTURE` ile intent yaratılır, `MediaStore.EXTRA_OUTPUT` ile kaydedilecek dosya yolu verilir ve `startActivityForResult(intent, REQUEST_IMAGE_CAPTURE)` çağrılır; `REQUEST_IMAGE_CAPTURE = 1` tanımlıdır (ekrandan, 00:40:00).
  - Dönüşte `data.getParcelableExtra("data")` ile küçük resim (thumbnail) `Bitmap` olarak alınır.
- Gelen intent'i karşılayan aktivite
  - Bir aktivite dışarıdan bilgi alıp iş yapıyorsa `onCreate` içinde `setContentView`'dan sonra `getIntent()` ile intent alınır, içindeki veri ve tipi kontrol edilir (resim mi, düz metin mi) ve ona göre iş yapılır.
  - İş başarıyla bitince `setResult(Activity.RESULT_OK)` ile çağıran tarafa bildirilir.
- Activity Result API
  - Android'in son yıllarda önerdiği yeni yapıdır: `ActivityResultLauncher` tanımlanır, `registerForActivityResult` ile kaydedilir, sonuç gelince yapılacak iş callback içinde yazılır, düğmeye basılınca `launch` çağrılır.
  - Fragment'larla ve `LifecycleObserver` yapısıyla uyumlu çalıştığı için yaygınlaşmıştır. Ders kapsamında yalnız tanıtıldı, ayrıntısına girilmedi.
- Layout'lar ve UI bileşenleri
  - ViewGroup'lar görünmeyen kapsayıcılardır, View'lar (widget'lar) bunların içine yerleşir (ekrandan, 01:00:00).
  - LinearLayout bileşenleri dikey ya da yatay eksende sıralar (`android:orientation="vertical"`); RelativeLayout bileşeni başka bir bileşene göre konumlandırır; WebView web içeriği gösterir.
  - Kimlik ilk tanımlanırken `@+id/ad`, başvururken `@id/ad` yazılır. En temel nitelikler `id`, `layout_width`, `layout_height`, `text`'tir.
  - İşe uygun bileşen seçilmelidir: örneğin tarih almak için serbest metin yerine takvim tipi bir bileşen kullanmak daha doğrudur.
  - `findViewById` layout'taki bileşeni kaynak koddaki değişkenle ilişkilendirir.
- Adapter ile liste gösterme: ListView
  - Çok sayıda tekrar eden veriyi (duyurular, resimler, anket seçenekleri) göstermek için ListView, GridView ve RecyclerView kullanılır. Veri kaynağı ile ekrandaki görünüm arasındaki bağı adapter kurar.
  - Basit örnek: `new ArrayAdapter<String>(this, android.R.layout.simple_list_item_1, myStringArray)` ve `listView.setAdapter(adapter)` (ekrandan, 01:05:00). Yapıcının argümanları: context, her eleman için bir `TextView` içeren layout, dizi.
  - `SimpleCursorAdapter` ile kişi bilgileri de ListView'a bağlanabilir; tıklama `setOnItemClickListener` ile yakalanır.
- RecyclerView ve ListView karşılaştırması (ekrandan, 01:15:00)
  - ListView her eleman için ayrı nesne ve bellek ayırır, yeniden kullanım yoktur; liste büyüdükçe kaydırmada performans düşer.
  - RecyclerView ekrandan çıkan elemanların görünümlerini yeniden kullanır; ekranda 20 eleman görünüyorsa 1000 eleman için nesne yaratılmaz.
  - ViewHolder deseni RecyclerView'da zorunlu, ListView'da isteğe bağlıdır (ve ListView'da kullanımı zahmetlidir).
  - ListView yalnız dikey liste yapar; RecyclerView layout manager'larla yatay, dikey ya da ızgara düzen kurabilir.
  - RecyclerView'da item decoration daha esnektir ve eleman ekleme/silme animasyonları (item animator) vardır; ListView'da animatör yoktur.
  - ListView'da `OnItemClickListener` vardır ve kolaydır; RecyclerView'da tıklama `OnItemTouchListener` gibi yollarla, daha fazla kodla yapılır.
  - Sonuç: küçük ve basit veri ile hızlı uygulama için ListView, karmaşık ve görsel olarak zengin listeler için RecyclerView tercih edilir.
- RecyclerView'ı kurma adımları
  - Layout XML'ine bir RecyclerView konur, kodda `findViewById` ile bağlanır, istenirse `setHasFixedSize(true)` verilir, bir layout manager atanır, adapter nesnesi veri kümesiyle yaratılıp `setAdapter` ile bağlanır.
  - Adapter `RecyclerView.Adapter<...ViewHolder>`'dan türetilir ve üç metot yazılır (ekrandan, 01:20:00):
    - `onCreateViewHolder`: `LayoutInflater.from(parent.getContext()).inflate(R.layout..., parent, false)` ile eleman layout'u şişirilir (inflate) ve bir ViewHolder döndürülür; veri henüz konmaz.
    - `onBindViewHolder(holder, position)`: veri kümesindeki o konumdaki eleman ViewHolder'ın bileşenlerine yazılır, örneğin `holder.textView.setText(mDataset[position])`.
    - `getItemCount()`: veri kümesinin boyutunu döndürür (`mDataset.length`).
  - Her eleman tipi için en az bir eleman layout XML'i (ör. `R.layout.text_row_item`) yazılmalıdır; ListView'daki gibi hazır bir format yoktur (ekrandan, 01:25:00).
  - CardView, görselin daha iyi yerleştirildiği, yeni nesil uygulamaların tercih ettiği bir eleman biçimidir.
- Android Studio örneği 1: ListView ile programlama dilleri listesi (ekrandan, 01:35:00)
  - `listItem = getResources().getStringArray(R.array.array_technology)` satırı `res/values/strings.xml` içindeki `array_technology` adlı string dizisini okur; veri kaynağı budur.
  - `ArrayAdapter` hazır `android.R.layout.simple_list_item_1` biçimiyle kurulur ve `setAdapter` ile ListView'a bağlanır.
  - `onItemClick` içinde `adapter.getItem(position)` ile tıklanan eleman alınır ve `Toast` ile gösterilir.
- Android Studio örneği 2: çok tipli RecyclerView (ekrandan, 01:50:00)
  - `Model` sınıfında `TEXT_TYPE = 0`, `IMAGE_TYPE = 1`, `AUDIO_TYPE = 2` sabitleri ve bir yapıcı vardır.
  - Aktivitede `ArrayList<Model>` doldurulur: bir metin elemanı, `R.drawable.wtc` resimli bir eleman, `R.raw.sound` sesli bir eleman ve `R.drawable.snow` resimli bir eleman.
  - `MultiViewTypeAdapter` her tip için ayrı ViewHolder (`TextTypeViewHolder`, `ImageTypeViewHolder`, `AudioTypeViewHolder`) ve ayrı eleman XML'i kullanır. `onCreateViewHolder` gelen `viewType`'a göre `switch` ile doğru layout'u şişirir; `getItemViewType` konumdaki modelin tipini döndürür.
  - `onBindViewHolder` tipe göre `setText`, `setImageResource` çağırır; ses elemanında FloatingActionButton'a `setOnClickListener` bağlanır ve tıklamayla `MediaPlayer` başlatılır ya da durdurulur (ekrandan, 02:00:00).
  - Bütün elemanlar aynı tipteyse tek ViewHolder ve tek layout yeter, `switch`'e gerek kalmaz.
- Ders boyunca geliştirilen örnek uygulama: mezun bilgi sistemi (ekrandan, 02:05:00)
  - Sign In ekranı (kullanıcı adı, şifre, giriş ve kayıt düğmeleri), Sign Up ekranı (kullanıcı adı, şifre, ad, soyad, resim, giriş yılı, mezuniyet yılı) ve girişten sonra duyuru listesi.
  - Duyuru listesi bir RecyclerView'dır; her elemanda bir resim, duyuru başlığı ve tarih bulunur. Elemana tıklanınca duyurunun ayrıntı sayfası açılır. Veri önce `ArrayList` ile koda gömülür, sonra veritabanı ya da dosyadan alınır.

## Hocanın Özellikle Vurguladığı Kısımlar

- İzinler manifest'e mutlaka eklenmelidir
  - Örneğin alarm için `SET_ALARM` izni alınmazsa alarm kuran kod hata verir ve çalışmaz.
- Request code karşı tarafa mutlaka verilmelidir
  - Aynı aktivite birden çok istek yapabildiği için dönen cevabın hangi isteğe ait olduğu ancak bu kodla anlaşılır; ardından result code ile işin başarısı kontrol edilir.
- `ActivityNotFoundException` yakalanmalıdır
  - Düşük olasılık da olsa isteği karşılayacak uygulama olmayabilir; `catch` içinde kullanıcıya bilgi verilip uygulamanın çökmesi önlenmelidir.
- Adapter en önemli parçadır
  - Uygulamadaki elemanlar için adapter bir kez doğru yazılınca gerisi kolaylaşır; işe adapter'dan başlamak akıllıcadır.
- Kod yazarak öğrenmek
  - Kodu yalnız izlemek bir noktaya kadar götürür; uygulama yazarken sürüm uyumsuzluğu gibi gerçek sorunlarla karşılaşılır ve deneyim böyle kazanılır.
- Gradle sürüm uyumsuzluğu
  - İnternetten bulunan bir projeyi doğrudan açıp sürüm sorunlarıyla uğraşmak yerine yeni ve temiz bir proje açıp dosyaları parça parça aktarmak önerildi.

## Kısa Tekrar Notları

- `createChooser`: kullanıcıya her seferinde uygulama seçimi sunar.
- Alarm: `AlarmClock.ACTION_SET_ALARM` + `EXTRA_HOUR`, `EXTRA_MINUTES` (zorunlu), `EXTRA_MESSAGE` (isteğe bağlı) + `SET_ALARM` izni.
- Dosya açma: `ACTION_OPEN_DOCUMENT`, `setType("image/*")`, `CATEGORY_OPENABLE`, `startActivityForResult`.
- Medya oynatma: `ACTION_VIEW` + `setData(uri)`.
- Fotoğraf: `MediaStore.ACTION_IMAGE_CAPTURE`, sonuçta `getParcelableExtra("data")` ile `Bitmap`.
- `onActivityResult(requestCode, resultCode, data)`: önce request code, sonra `RESULT_OK`/`RESULT_CANCELED`, sonra `data.getData()`.
- Karşılayan aktivite: `getIntent()` ile veriyi alır, işi yapar, `setResult(Activity.RESULT_OK)` döndürür.
- Activity Result API: `ActivityResultLauncher` + `registerForActivityResult` + `launch`.
- `@+id/ad` yeni kimlik, `@id/ad` başvuru.
- ListView: kolay, `OnItemClickListener`, yalnız dikey, büyük listede yavaş.
- RecyclerView: görünüm yeniden kullanımı, zorunlu ViewHolder, layout manager, animasyon, daha çok kod.
- Adapter'ın üç metodu: `onCreateViewHolder` (inflate), `onBindViewHolder` (veri yaz), `getItemCount` (boyut).
- Çok tipli liste: her tipe bir ViewHolder ve bir XML, `getItemViewType` ile tip seçimi.

## Detaylı Açıklamalar

- Sonuç bekleyen aktivite çağrısının akışı
  - Çağıran aktivite bir intent hazırlar, bir request code seçer ve `startActivityForResult(intent, kod)` çağırır. Karşı aktivite işi yapar, sonucu bir intent'e koyar ve `setResult` ile result code'u belirler. Çağıran tarafta `onActivityResult` tetiklenir: request code hangi isteğin döndüğünü, result code işin başarılı olup olmadığını, intent ise taşınan veriyi verir. Kişi seçme örneğinde dönen `Uri` ile kişiler veritabanına sorgu yapılır ve cursor üzerinde gezilerek telefon numarası okunur. Birden fazla kayıt da dönebilir (örneğin belli bir harfle başlayan bütün kişiler); kod buna göre yazılır.
- Intent filter'ın iki yönü
  - Bir uygulama başka uygulamalardan iş isteyebilir (alarm kurdurma, fotoğraf çektirme) ya da kendisi bir işi üstlenebilir. İkinci durumda yapabildiği işi manifest'te `<intent-filter>` ile aksiyon, kategori ve MIME tipiyle bildirir. Bildirilen tipe uymayan istekte uygulama aday listesinde görünmez. Bu yüzden filtre ne kadar dar yazılırsa uygulama o kadar az istekte listelenir.
- Neden RecyclerView?
  - ListView'da 1000 elemanlık bir liste için 1000 görünüm nesnesi yaratılır. RecyclerView yalnız ekranda görünen kadar (ve biraz fazlası kadar) görünüm yaratır; kaydırıldıkça ekrandan çıkan görünümlerin yerine yeni veri yazılır. `onCreateViewHolder` yalnız yeni görünüm gerekince, `onBindViewHolder` ise her yeni konumda çalışır. Bu ayrım, kaynak kullanımında büyük kazanç sağlar.
- Çok tipli liste tasarımı
  - Aynı listede metin, resim ve ses elemanı göstermek için modelde bir tip alanı tutulur. `getItemViewType` her konum için bu tipi döndürür, `onCreateViewHolder` tipe göre doğru XML'i şişirir ve doğru ViewHolder'ı yaratır, `onBindViewHolder` ise holder'ı ilgili tipe dönüştürüp alanlarını doldurur. Mezun uygulamasındaki duyuru listesi tek tipli olduğu için tek ViewHolder ve tek XML yeterlidir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
