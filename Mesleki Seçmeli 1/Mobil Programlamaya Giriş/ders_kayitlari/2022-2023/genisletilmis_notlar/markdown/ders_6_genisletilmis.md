# Ders 6 Genişletilmiş Notu: Activity Yaşam Döngüsü, UI Durumunun Saklanması ve Intent'ler

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Aktiviteler ve Uygulamaya Giriş Noktaları
- 2. Aktivitenin Manifest'te Tanımlanması ve Intent Filter
- 3. Activity Yaşam Döngüsü
- 4. Yaşam Döngüsü Metotları Tek Tek
- 5. Sistemin Aktiviteyi Bellekten Atması
- 6. UI Durumunu Saklama Seçenekleri
- 7. Bundle ile Durum Saklama: Sayaç Örneği
- 8. Layout XML Temelleri
- 9. Intent'ler: Explicit ve Implicit
- 10. Intent ile Veri Taşıma ve Aktivite Başlatma
- 11. Android Studio'da İlk Uygulama: Basit Login
- Örnek Sorular
- Dersin Toparlaması

## 1. Aktiviteler ve Uygulamaya Giriş Noktaları

Bu haftanın konusu aktiviteleri daha yakından tanımak ve aktivite yaşam döngüsüne (Activity Lifecycle) ayrıntılı bakmaktır. Geçen hafta bir aktivitenin bir ekranı temsil ettiği söylenmişti.

Her uygulamanın genellikle bir başlangıç aktivitesi vardır. Buna launcher activity denir. Kullanıcı uygulamanın simgesine dokunduğunda karşılaştığı ilk ekran budur. Çoğu projede adı `MainActivity` olur, ama bu ad zorunlu değildir. Önemli olan, uygulamaya her zaman bu aktiviteden girilmek zorunda olmamasıdır. Kullanıcı bir uygulamayı farklı kanallardan tetikleyebilir ve uygulamanın farklı aktivitelerini doğrudan kullanabilir. Bu yüzden hoca bu hikâyeyi "non-deterministik" olarak niteledi: olay güdümlü (event-driven) programlama, mobil uygulamayı masaüstü programlamadan ayıran şeydir.

Hocanın verdiği örnek: E-postalarınızı gördüğünüz bir uygulamayı kendiniz açtığınızda gelen kutusu ekranı gelir. Fakat başka bir uygulamada "paylaş" dediğinizde, bu bilgiyi paylaşabilecek yeteneğe sahip uygulamaların listesi çıkar (WhatsApp, Twitter vb.). Listeden e-posta uygulamasını seçtiğinizde o uygulamanın yalnız e-posta gönderme aktivitesine ulaşırsınız. Yani bir uygulamanın birden fazla giriş noktası vardır.

Bu nedenle aktiviteler, birbirleriyle uyumlu çalışan ama birbirine bağımlılığı en az seviyede olan küçük, bağımsız iş birimleri olarak görülebilir. Bir uygulamanın pek çok aktivitesi olsa da bunların yalnız birkaçı, hem uygulamanın içinden hem başka uygulamalardan, çok daha yoğun kullanılabilir. Bu, kullanıcının ihtiyacına göre değişir.

Son yıllarda ekranların büyümesiyle bir ekranın birden fazla aktivite tarafından kullanılması da mümkün hale geldi. Şimdiye kadar aktivite için "tek kullanıcı arayüzü" denmişti; ama ekran ikiye bölünerek birbirinden bağımsız iki aktivite aynı anda çalıştırılabilir (multi-window). Ayrıca bir aktivitenin alt işleri iki ya da üç fragment'a bölünerek yönetilebilir. Bunun gerekip gerekmediği uygulamaya ve uygulamanın çalışacağı cihazlara bağlıdır.

## 2. Aktivitenin Manifest'te Tanımlanması ve Intent Filter

Bir aktivite yaratıldığında, yani aslında yeni bir modül yaratıldığında, bu aktivite manifest dosyasında tanımlanmalıdır. Tanım `<application>` etiketinin içine yazılır. Slayttaki örnek (ekrandan, 00:10:00):

```xml
<manifest ... >
  <application ... >
    <activity android:name=".ExampleActivity" />
    ...
  </application ... >
  ...
</manifest >
```

Bu yazımda yalnız ad verilmiş ve etiket aynı satırda hem açılıp hem kapatılmıştır (`<activity ... />`). Birden fazla özellik ya da iç içe öğe tanımlanacaksa ayrı bir açma ve kapama etiketi kullanılır.

Android Studio'da yeni bir aktiviteyi sihirbazla ürettiğinizde sistem onu manifest'e kendiliğinden ekler. Fakat başka bir kaynaktan bir kod parçasını (örneğin A ve B aktivitelerini) projeye kopyaladığınızda bu aktiviteler manifest'e otomatik eklenmez. Onları manifest'e elle tanımlamanız ve gerekli ad değişikliklerini yapmanız gerekir.

Aktivite en basit haliyle yalnız adıyla tanımlanabilir. Aktiviteye ait bir simge (icon) kullanılıyorsa o da tanımlanır. Aktivitenin bir yeteneği varsa, örneğin e-posta gönderebiliyorsa, bu yetenek intent filter ile sisteme bildirilir. Slayttaki örnek (ekrandan, 00:10:00):

```xml
<activity android:name=".ExampleActivity" android:icon="@drawable/app_icon">
    <intent-filter>
        <action android:name="android.intent.action.SEND" />
        <category android:name="android.intent.category.DEFAULT" />
        <data android:mimeType="text/plain" />
    </intent-filter>
</activity>
```

Intent filter sisteme şunu söyler: "Ben şu aksiyonu, şu kategorideki uygulamalar için, şu veri tipi için yapabilirim." Slayttaki ifadeyle intent filter'lar Android platformunun çok güçlü bir özelliğidir; bir aktivitenin yalnız açık (explicit) bir istekle değil, örtük (implicit) bir istekle de başlatılabilmesini sağlar. Örneğin bir anlık mesajlaşma uygulaması yazdınız ve bu filtreyi tanımladınız: başka bir uygulamadan bir paylaşım talebi geldiğinde sizin uygulamanız da bu aksiyonu gerçekleştirebilecek uygulamalar listesine girer.

Uygulamanızda 20 aktivite olabilir; bunlardan bazıları belirli görevleri yerine getirebilmek için sisteme kaydolur (register) ve ilgili isteklere karşılık verebilecek listede kendine yer bulur.

## 3. Activity Yaşam Döngüsü

Slayttaki diyagramda (ekrandan, 00:15:00) yaşam döngüsü şöyle gösterilir:

```text
Activity launched
  -> onCreate()
  -> onStart()   <------------------------ onRestart()
  -> onResume()  <---------------+              ^
  -> Activity running            |              |
     (başka bir aktivite ön plana gelir)        |
  -> onPause()  -- kullanıcı aktiviteye döner --+
     (aktivite artık görünmez)                  |
  -> onStop()   -- kullanıcı aktiviteye gider --+
     (aktivite bitiyor ya da sistem yok ediyor)
  -> onDestroy()
  -> Activity shut down

onPause()/onStop() durumundayken daha öncelikli uygulamalar bellek isterse:
  -> App process killed -> kullanıcı aktiviteye gider -> onCreate()
```

Bir aktivite başlatıldığında (kullanıcı simgeye dokunduğunda, bir servis aktiviteyi çağırdığında ya da başka bir uygulama aktiviteyi başlattığında) önce `onCreate()` çalışır. Ardından `onStart()`, sonra `onResume()` gelir ve aktivite artık çalışır durumdadır; ön planda (foreground) kendine yer bulur.

Aktivite kullanıcı fark etmeden ön plandan çıkabilir. Bu durumda sırayla `onPause()`'a, ardından `onStop()`'a girer. `onPause()`'a girip arka planda kısmen de olsa görünür kalırsa `onResume()` üzerinden kaldığı yerden devam edebilir. Aktivite tamamen durup görüntüden çıkarsa `onStop()`'a geçer. `onStop()`'tan geri dönülecekse `onRestart()` üzerinden aktivite tekrar çalışır hale gelir.

`onStop()`'a gelmenin örnekleri: Back tuşuna basmak, Home tuşuna basmak (bu ikisinin farkı aşağıda) ya da o aktiviteden başka bir aktiviteye geçmek; örneğin fotoğraf çekmek için başka bir aktiviteyi çağırmak. O zaman tamamen görüntüden çıkan aktivite `onStop()` durumuna geçer ve bu geri çağırma (callback) sayesinde `onStop()` metodu çalışır.

Bu metotlar çalıştığında sizin tanımladığınız işlerin yapılması beklenir. Örneğin:

- O anda kullanılmayan kaynakların serbest bırakılması (release).
- Kayıt olunmuş (register) ama o anda dinlenmesi gerekmeyen sensörlerin kaydının silinmesi (unregister).
- Verinin kalıcı olarak saklanması gerekiyorsa ikincil belleğe ya da veritabanına yazılması.

### 3.1 Uzun işler ve ana thread

Bu metotlarda yapılan iş uzun sürecekse kullanıcı etkileşiminde sorun çıkabilir. Kullanıcı ekranda tıklamaya devam ederken uzun süren bir işi arka plan için tasarlanmış özel API'lerle çalıştırmazsanız kullanıcının ekranı donar. Hocanın örneği: 4-5 saniyelik bir işi, kullanıcının aksiyonlarını da takip ederken ana thread'de (main thread) yapmaya kalkarsanız sonuç kullanıcı memnuniyetsizliği olur. Bu yüzden uzun sürecek işler için farklı bir thread yapısı ya da arka planda çalışabilen yapılar kullanılması önerilir. Bu yapılar ileride background task'lar konusunda ayrıntılı görülecek.

### 3.2 onDestroy ve görev yığını

`onDestroy()` aktivite tamamlanacağı zaman çalışır. Bunun nedeni geliştiricinin kodda çağırdığı bir `finish` komutu, kullanıcının Back tuşuyla aktiviteden tamamen çıkması ya da sistemin kaynak ihtiyacından dolayı aktiviteyi sonlandırması olabilir.

Hoca burada bir sürüm farkından söz etti: Android 11 ve öncesinde `onDestroy()`'a geçen aktiviteye ait bilgiler bellekten tamamen kaldırılıyordu. Android 12 ve sonrasında ise süreç öldürülse de bellekte yer olduğu sürece bilgileri saklanıyor; böylece uygulamayı sıfırdan çalıştırmak (cold start) yerine son halinden yeniden başlatmak (warm start) mümkün oluyor ve hız kazanılıyor.

> **Ders sonrası not:** Soğuk başlatma (cold start) ile ılık ve sıcak başlatma (warm/hot start) ayrımı Android'de 12 sürümünden önce de vardı; sistem arka plandaki süreçleri bellek elverdiği sürece önbellekte tutar. Hocanın "11 ve öncesi / 12 ve sonrası" ayrımı büyük olasılıkla Android 12'de bu davranışla ilgili yapılan bir değişikliğe dayanıyor; ayrıntısı derste verilmedi.

Android görevleri bir yığın (stack) mantığıyla, "back stack" olarak saklar. Çalıştırdığınız her görev yığına itilir (push). Üstüne yeni görevler açtıkça eskileri altta kalır; Back yaptıkça yığının üstünden eski görevler yavaş yavaş önünüze gelir.

### 3.3 Yaşam döngüsünü bilmek neden önemli?

Slaytta, yaşam döngüsüne uygun yazılmayan bir uygulamada şu sorunların çıkabileceği sıralanır (ekrandan, 00:20:00):

- Kullanıcı uygulamanızı kullanırken telefon araması gelirse ya da başka bir uygulamaya geçerse uygulamanın çökmesi.
- Kullanıcı uygulamayı aktif kullanmıyorken değerli sistem kaynaklarının tüketilmesi.
- Kullanıcı uygulamadan çıkıp sonra döndüğünde ilerlemesinin kaybolması.
- Ekran yatay ve dikey yön arasında döndürüldüğünde çökme ya da kullanıcının ilerlemesinin kaybolması.

Hoca, durumlara uygun olarak kaynakları serbest bırakmayan uygulamaların daha fazla enerji ve kaynak tükettiğini, her uygulama bunu yönetmediğinde sistemin bir noktadan sonra yönetilemez hale geldiğini vurguladı.

### 3.4 LogCat ile yaşam döngüsünü izlemek

Her yaşam döngüsü durumu için "bu duruma ne zaman geçildi, bir sorun var mı, buradaki işler ne kadar sürüyor" sorularının cevabını görmek için log mekanizması kullanılabilir. Her duruma bir log mesajı koyarsanız aktivite her durum değiştirdiğinde bir mesaj üretir; böylece sistem çalıştığı sürece aktivitenin hangi durumlardan geçtiğini ve ne kadar zaman harcadığını görürsünüz. Android Studio'da bu mesajlar LogCat penceresinden izlenir.

LogCat aynı zamanda hatanın nereden kaynaklandığını da gösterir. Örneğin bir aktiviteyi çağırdığınızda uygulama çöküyorsa, nedeni aktivite adını yanlış yazmanız ya da aktiviteyi manifest'e tanımlamamanız olabilir. Hoca, LogCat'teki mesajları takip edip anlamaya çalışmanın çok şey kazandıracağını söyledi.

## 4. Yaşam Döngüsü Metotları Tek Tek

### 4.1 onCreate()

`onCreate()`'te sistem aktiviteyi ilk kez yaratır. Aktiviteyle ilgili bütün ilk değerler ve ilklendirmeler bu metotta yapılır. Layout'taki XML dosyasıyla ilişki burada kurulur, butonlarla ilişki burada kurulur. Kaynak dosyalarınız (resource) ile kaynak kodunuzdaki (source) değişkenlerin ilişkisi `R` sınıfı üzerinden `onCreate()`'te kurulur.

Hocaya göre bu ilişkilerin kullanıcıyla etkileşime geçirildiği, aktivitenin ön plana gelip görselleştiği adım `onStart()`'tır; bu yüzden yalnız `onCreate()` ile hareket etmek kullanıcı aksiyonlarını takip etmeye yetmez.

> **Ders sonrası not:** Hoca kullanıcıyla etkileşimin `onStart()` ile başladığını söyledi. Slayttaki tanıma göre (ekrandan, 00:25:00) aktivite kullanıcıyla `onResume()` sonrasındaki Resumed durumunda etkileşir; `onStart()` aktiviteyi yalnız görünür yapar.

### 4.2 onResume()

Slayttaki tanım (ekrandan, 00:25:00): Aktivite Resumed durumuna girdiğinde ön plana gelir ve sistem `onResume()` callback'ini çağırır. Bu, uygulamanın kullanıcıyla etkileşimde olduğu durumdur; uygulama, odağı ondan alan bir şey olana kadar bu durumda kalır. Aynı slayttaki örnek kodda `onResume()` içinde, sürüm `LOLLIPOP` ve üstüyse durum çubuğunun rengi ayarlanır.

`onResume()`, `onPause()` ya da `onStop()` üzerinden dönülen noktada çalışır; arka plana düşen bir aktivitenin yeniden ön plana alınırken yapılması gerekenler buraya yazılır. Hocanın örneği: Bir sensörü kaydettiniz, `onPause()`'a düşünce kaydını sildiniz ("uygulama açık değilken takip etmeyeceğim"). Bu sırada telefonla konuşuyorsunuz; konuşma bitince ya da bildirime baktıktan sonra sistem tamamen sizin aktivitenize döndü. `onPause()`'tan çalışır duruma geçerken `onResume()` çağrıldığında sensörü yeniden kaydetmezseniz, ilk `onPause()`'tan sonra sensörü bir daha hiç takip etmemiş olursunuz.

> **Hocanın vurgusu:** `onPause()`'ta yaptığınız işin tam tersini `onResume()`'da yapmanız beklenir. Bu anlamda `onResume()` ile `onPause()` birbirinin aynasıdır. Hoca aynı ilişkinin `onStop()` ile `onRestart()` arasında da olduğunu söyledi.

> **Ders sonrası not:** Android belgelerinde `onStop()`'un karşılığı genellikle `onStart()` olarak verilir; durmuş bir aktivite dönerken `onRestart()` ve ardından `onStart()` birlikte çalışır. `onStop()`'ta bırakılan bir kaynak büyük olasılıkla en güvenli biçimde `onStart()`'ta geri alınır.

### 4.3 onPause()

Slayttaki tanım (ekrandan, 00:30:00): `onPause()`, aktivitenin artık ön planda olmadığını gösterir. Nedenleri:

- Uygulamanın çalışmasını kesen bir olay (telefon araması gibi sistemsel kesmeler).
- Android 7.0 (API seviyesi 24) ve üstünde birden fazla uygulama multi-window modda çalışabilir. Herhangi bir anda yalnız bir pencerenin odağı olduğu için sistem diğer bütün uygulamaları duraklatır. Hocanın anlatımıyla: büyük ekranda bir uygulamayla etkileşimdeyseniz, ekranda görünmelerine rağmen diğer uygulamalar `onPause()` durumuna geçer.
- Yarı saydam yeni bir aktivite (örneğin bir diyalog) açılır. Aktivite kısmen görünür ama odakta değilse duraklatılmış kalır. Hoca, bir bilgilendirme ya da uyarı (alert) mesajı ekrana geldiğinde, kullanıcı "evet/hayır" gibi bir butona basıp mesaj kaybolana kadar aktivitenin `onPause()` durumunda olduğunu söyledi.

`onPause()` metodu sistem kaynaklarını, GPS gibi sensörlere ait bağlantıları ya da aktivite duraklatılmışken kullanıcının ihtiyaç duymadığı ve pil ömrünü etkileyebilecek her kaynağı serbest bırakmak için kullanılabilir. Hocanın örneği: telefon görüşmesi uzun sürebilir; uygulamanız aslında çalışmadığı halde bu süre boyunca kaynak tüketmesi anlamsızdır. Bir saat boyunca bir şeyin veri toplamaya devam etmesi anlamlı olmayabilir.

Derste bu noktada bir soru geldi (ayrıntısı Örnek Sorular bölümünde): `onPause()`'ta yalnız kaynak iadesi yapılmaz; o andaki bazı bilgiler de saklanabilir, örneğin SharedPreferences'a küçük bir bilgi yazılabilir. `onStop()`'ta da veritabanına yazılması gereken kalıcı bir bilgi varsa yazılabilir. Çünkü telefonla konuşurken kullanılmayan aktivite bir süre sonra `onStop()`'a geçer, konuşma uzarsa sistem kaynak tüketimine bağlı olarak onu yok edebilir. Durum geçişleri bu yüzden veriyi saklamak için bir fırsattır.

> **Hocanın vurgusu:** Büyük bir veriyi `onPause()` ya da `onStop()` aşamasında saklamak iyi bir fikir değildir, çünkü uzun süren bir saklama işi ana thread'e bağlı olarak devam etmemelidir. Büyük boyutlu buluta aktarımlar ya da veritabanına büyük veri yazma, ayrı bir thread ile, tercihen aktivite çalışırken yapılmalıdır. En kötü zamanlama `onDestroy()`'da bir şey kaydetmeye çalışmaktır: sistem aktiviteyi çok kısa sürede devre dışı bırakır ve verinin yazılacağının garantisi yoktur. Veri depolamak için `onPause()` ve `onStop()` daha uygun noktalardır.

### 4.4 onStop()

`onStop()`, aktivite artık görünmediğinde sistem tarafından çağrılan callback'tir. Örneğin Home tuşuna basmışsınızdır ve karşınıza uygulamalarınızın olduğu ekran gelmiştir.

### 4.5 Home ve Back tuşunun farkı

Home tuşuna bastığınızda aslında başka bir uygulamaya geçmek için gittiğinizi söylersiniz; hızlıca geri dönüp aynı uygulamadan devam edebilirsiniz. Aktivite `onStop()`'ta kalır.

Back tuşu ise "bu aktivitede işim bitti, başka aktiviteye geçiyorum" demektir. Bu yüzden Back tuşuna basınca sırayla `onPause()`, `onStop()` ve `onDestroy()` çalışır; hikâyenin sonu `onDestroy()`'dur.

> **Hocanın vurgusu:** Home tuşuna basmakla Back tuşuna basmak birbirinden farklıdır.

`onStop()` metoduyla kullanılmayan bir uygulama, en az enerji ve kaynak harcayacak biçimde konumlandırılır. Slaytta `onStop()` içinde CPU yoğun kapanış işlemlerinin (CPU-intensive shutdown operations) de yürütülebileceği söylenir. Hoca bunu şöyle açıkladı: `onDestroy()`'a geçmeden `onStop()` tarafında biraz daha uzun sürecek işler yapılabilir, çünkü burada `onDestroy()`'a göre daha fazla zaman vardır. Ama bunun da bir sınırı vardır, her şey burada halledilemeyebilir; yine dikkatli olmak gerekir.

### 4.6 onDestroy() ve yapılandırma değişikliği

`onDestroy()` iki şekilde gerçekleşir:

- Kullanıcı aksiyonu ya da geliştiricinin kodda belirlediği bir nedenle aktivitenin tamamlanması.
- Sistemde yapılan bir değişiklik. Buna yapılandırma değişikliği (configuration change) denir: cihazın döndürülmesi, multi-window moda geçilmesi, klavyeyle ilgili bir ayarın değiştirilmesi, dilin Türkçeden İngilizceye ya da İtalyancaya çevrilmesi gibi.

Android burada bir felsefe ortaya koyar: Cihazla ilgili bir şey değişiyorsa yeni bir aktivite oluşturmak gerekir. Çünkü dikey ve yatay ekran görüntüsünü aynı aktiviteyle sağlamak kullanıcı memnuniyetsizliğine yol açar. Telefonu döndürdüğünüzde, bu özelliği kilitlemediyseniz, sistem yeni duruma daha uyumlu olmak için mevcut aktiviteyi öldürüp yenisini yaratır. Hoca, iyi uygulamalarda yatay ve dikey ekran için ayrı ekran tasarımları yapıldığını göreceğinizi söyledi. Dil değişikliğinde de aynı nedenle aktivitenin yok edilip yenisinin çağrılması önemlidir. <!-- BELİRSİZ: 00:34:30'da altyazı "Keza M6.000'de olmadığı için de aynı şeyler geçerli" diyor; hangi durumdan söz edildiği anlaşılmıyor (büyük olasılıkla multi-window mod). -->

## 5. Sistemin Aktiviteyi Bellekten Atması

Android işletim sistemi gerektiğinde çalışan bütün uygulamaları sonlandırma hakkına sahiptir, ama bir hiyerarşi gözetir. Slayttaki tablo (ekrandan, 00:35:00):

| Öldürülme olasılığı | Süreç durumu | Son aktivite durumu |
|---|---|---|
| En düşük | Ön plan (odağı olan ya da odak almak üzere) | Resumed |
| Düşük | Görünür (odak yok) | Started/Paused |
| Daha yüksek | Arka plan (görünmez) | Stopped |
| En yüksek | Boş | Destroyed |

Hocanın anlatımıyla: en önde kullandığınız aktivite yok edilecek son hedeftir. Sonra belli oranda görünen ama odakta olmayan aktivite gelir. Arka plana alınmış, görünmeyen ama yakın zamanda kullanılmış aktivite bir sonraki önceliktir. Kaynakları boşaltmak için en yüksek önceliğe sahip olan ise zaten yok edilmiş (destroyed) olandır. Hoca yine Android 12 ve üzerinde, yer varsa yok edilmiş aktivitenin bellekte "hareketsiz ama canlı" bir halde tutulduğunu ve bir talep geldiğinde sıfırdan başlatmak yerine o noktadan başlatıldığını belirtti.

### 5.1 Kullanıcının durumunu korumak

Kullanıcı arayüzündeki o anki durumu (bir oyunda oynuyorsanız oyunun durumu, bir form dolduruyorsanız girilen bilgiler) aktivite yok olmadan önce mutlaka saklamak gerekir. Cihazı döndürdüğünüz anda kullanıcıya ait ya da ekrandaki bir bilgi kaybolursa, aktivite yeniden yüklendiğinde bu kullanıcıyı mutsuz eder. Android bu yüzden, aktivite kullanıcı ya da sistem tarafından sonlandırıldığında yeni aktivitenin kaldığı yerden devam edebilmesi için, kişiye ve ekrana ait bilgilerin belirli yöntemlerle saklanıp yeniden yüklenmesini önerir.

Sonlanma nedenleri iki gruba ayrılır:

- **Kullanıcının başlattığı (user-initiated):** Son kullanılanlar ekranından uygulamayı kapatmak (hoca bunu aktivitelerin "çöp kutusunu temizlemek" diye anlattı; kaldıkları sürece telefon belli oranda yavaşlar), ayarlar ekranından uygulamayı durdurmak, ya da geliştiricinin kodunda aktivitenin kendini sonlandırmasını sağlayan çağrının çalışması.
- **Sistemin başlattığı:** Sistemin çökmesi, kaynak nedeniyle aktivitenin sonlandırılması, sistemin kendi kendine yeniden başlaması. Kullanıcı tetiklese de sistem kuralı gereği oluşan ekranın döndürülmesi de bu gruba sayılabilir.

Bu iki grubun ayrılmasının nedeni, saklama yöntemlerinin her birine farklı davranmasıdır.

## 6. UI Durumunu Saklama Seçenekleri

Üç temel yaklaşım vardır: ViewModel, saved instance state denen Bundle nesnesi ve kalıcı depolama (internal storage, external storage ya da ağdaki bir alan). Slayttaki karşılaştırma (ekrandan, 00:55:00):

| | ViewModel | Saved instance state | Persistent storage |
|---|---|---|---|
| Saklama yeri | bellekte | diske serileştirilmiş | diskte ya da ağda |
| Yapılandırma değişikliğine dayanır | Evet | Evet | Evet |
| Sistemin başlattığı süreç ölümüne dayanır | Hayır | Evet | Evet |
| Kullanıcının aktiviteyi tamamen kapatmasına / `onFinish()`'e dayanır | Hayır | Hayır | Evet |
| Veri sınırı | karmaşık nesneler olur, ama alan kullanılabilir bellekle sınırlı | yalnız ilkel tipler ve String gibi basit, küçük nesneler | yalnız disk alanı ya da ağdan getirme maliyeti/süresiyle sınırlı |
| Okuma/yazma süresi | hızlı (yalnız bellek erişimi) | yavaş (serileştirme/serileştirmeyi çözme ve disk erişimi) | yavaş (disk erişimi ya da ağ işlemi) |

**ViewModel:** Karmaşık bilgileri sınırlar dahilinde bir bellek bölgesinde saklayabilir. Ancak bunu yalnız yapılandırma değişikliği söz konusuysa yapar. Süreç sistem tarafından öldürüldüyse ya da kullanıcı tarafında `Activity.finish()` çağrılarak aktivite sonlandırıldıysa ViewModel işe yaramaz. ViewModel'in asıl sağladığı, yapılandırma değişikliğinde bilgilerin hızla saklanmasıdır.

**Saved instance state (Bundle):** Bundle nesnesiyle `onSaveInstanceState` metodu kullanılarak bilgi saklanır. ViewModel'den farkı, bilginin bellekte değil disk bölgesinde, serileştirilerek tutulmasıdır. Serileştirme gerektiği için saklanacak verilerin ilkel (primitive), basit veriler olması ön koşuldur; String bir nesne olsa da basit string bilgileri de saklanabilir. Güzelliği şudur: aktivite yalnız yapılandırma değişikliğinde değil, sistem tarafından herhangi bir nedenle durdurulup yok edildiğinde de, yeniden yaratıldığında `onCreate()` ile Bundle'daki bilgiler alınıp kaldığı yerden devam edilebilir. ViewModel'e göre bu artısı olduğu için uygulama geliştiriciler genelde Bundle ile saklamayı tercih eder.

Kod içinde `finish()` ile sonlandırma durumunda Bundle devreye girmez; bu bilinçli bir sonlandırma olduğu için herhangi bir saklama hamlesi gerçekleşmez.

**Kalıcı depolama:** Saklanacak verinin yapısı karmaşıksa ve her durumda korunması gerekiyorsa iyi bir çözümdür. Önemli olan, veriyi aktivite sonlanmadan önce yazmaktır. Bellek erişimi hızlıdır, ama disk ve ağ erişimi daha uzun sürer. Bu nedenle çok büyük verileri Bundle ile saklamak da mümkün değildir; serileştirme ve serileştirmeyi çözme adımları işi ayrıca yavaşlatır.

## 7. Bundle ile Durum Saklama: Sayaç Örneği

Slayttaki örnek uygulamada (ekrandan, 01:00:00) bir kullanıcı adı alanı, bir telefon numarası alanı, `0` yazan bir TextView ve "COUNT UP" butonu vardır. Kod şöyledir:

```java
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity {

    Button button;
    TextView textView;
    int counter;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        if (savedInstanceState != null) {
            String message = savedInstanceState.getString("message");
            Toast.makeText(this, message, Toast.LENGTH_LONG).show();

            counter = savedInstanceState.getInt("counter", 0);
        }

        button = findViewById(R.id.button);
        textView = findViewById(R.id.textView);
        textView.setText(String.valueOf(counter));

        button.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                counter = Integer.valueOf(textView.getText().toString()) + 1;
                textView.setText(String.valueOf(counter));
            }
        });
    }

    @Override
    public void onSaveInstanceState(Bundle outState) {
        super.onSaveInstanceState(outState);
        outState.putString("message", "This is a saved message");
        outState.putInt("counter", counter);
    }

    @Override
    protected void onRestoreInstanceState(Bundle savedInstanceState) {
        super.onRestoreInstanceState(savedInstanceState);
        Toast.makeText(getApplicationContext(), "onRestoreInstanceState",
                Toast.LENGTH_SHORT).show();
        counter = savedInstanceState.getInt("counter", 0);
    }
}
```

Slaytta `onRestoreInstanceState` sağ üst köşede ayrı bir parça olarak gösterilir; burada okunabilirlik için sınıfın içine yerleştirildi.

### 7.1 Kodun anlatımı

**İçe aktarmalar.** `View`, `Button`, `TextView`, `Toast` ve aktivite sınıfı gibi kütüphaneler import edilir. Bunlar genelde otomatik yapılır: kullandığınız bileşenin kütüphanesi yoksa bir uyarı çıkar ve Android Studio neyi import etmeniz gerektiğini önerir. `android.widget.*` de yazılabilirdi, ama hoca kodu şişirmemek için yalnız kullanılacak sınıfların import edildiğini söyledi.

**Alanlar.** Aktivitenin içinde önce XML tarafındaki arayüz bileşenlerini temsil edecek tanımlar yapılır: ekranda bir buton olduğu için bir `Button`, bir TextView olduğu için bir `TextView`. Ayrıca kodlama sırasında gereken yerel değişkenler, örneğin `counter`, tanımlanır.

**onCreate ve setContentView.** `onCreate` olmazsa olmaz bir tanımdır, çünkü XML dosyasındaki arayüz bileşenleriyle ilişki burada kurulur. Önce `onCreate` yeniden yazılır (override), sonra `setContentView(R.layout.activity_main)` ile layout klasöründe `activity_main` olarak tanımlanan dosya bu aktivitenin görselini temsil eden dosya olarak bağlanır. Hoca bunu, kaynak dosyaya uygun "kıyafetin" giydirilmesi diye anlattı.

`onCreate`'e bir Bundle nesnesi gelir. Adının `savedInstanceState` olması zorunlu değildir, yalnız alışılagelmiş kullanım budur.

**Null kontrolü.** Aktivitenin sıfırdan mı yaratıldığı yoksa bir yok edilme sonrasında mı çağrıldığı bilinmediği için Bundle'ın null olup olmadığı mutlaka kontrol edilir. Null ise aktivite büyük olasılıkla ilk kez yaratılmıştır ve bir şey yapılmaz. Null değilse içindeki bilgiler `getString`, `getFloat` gibi metotlarla aktivitenin içine çekilir. Bu örnekte iki bilgi alınır: bir mesaj (string) ve sayaç. Mesaj `Toast` sınıfıyla kullanıcıya gösterilir.

**findViewById.** `if` bloğundan sonra, Bundle olsa da olmasa da yapılması gereken kısım gelir: layout'taki arayüz bileşenlerinin kaynak kodda da temsil edilmesi. `R.id.button` layout tarafındaki bileşendir; koddaki `button` değişkeni ile ilişkisi `findViewById` ile kurulur. TextView için de aynısı yapılır. Böylece layout ile asıl işin yapıldığı iş mantığı (business logic) arasındaki köprü kurulmuş olur. Bundan sonra bu nesnelerin metotlarıyla arayüzde değişiklik yapılabilir.

**Sayacın geri yüklenmesi.** Kullanıcı "COUNT UP" butonuna basarak sayıyı 1, 2, ..., 8'e getirmiş olsun. Aktivite yeniden yaratıldığında 8'den devam edebilmesi için sayacın Bundle'a kaydedilmiş ve aktivite yüklenirken geri getirilmiş olması gerekir. `textView.setText(String.valueOf(counter))` bunu ekrana yazar. Bundle gelmemişse `counter` alanının varsayılan değeri 0 olur; `getInt("counter", 0)` çağrısındaki ikinci parametre de anahtar yoksa dönecek varsayılan değerdir.

**Tıklama dinleyicisi.** Butonun tıklanmasını takip etmek için `new View.OnClickListener()` ile anonim bir sınıf tanımlanır. Bunun başka yolları da vardır: XML dosyasına `onClick` özelliği koyarak koda bu bloğu yazmadan da aynı iş yapılabilir. Her tıklamada sayaç bir artırılır ve `textView.setText` ile ekran güncellenir. Ekrandaki kodda artırma, TextView'daki metnin sayıya çevrilip 1 eklenmesiyle yapılır (`Integer.valueOf(textView.getText().toString()) + 1`).

**onSaveInstanceState.** Aktivite yok edilirken bilgilerin Bundle'a yazıldığı yer burasıdır. Hoca bu metodun aktivite duraklatılırken ya da durdurulurken çağrıldığını, adının da hep `onSaveInstanceState` olduğunu söyledi. Ekrandaki sayaç değeri ve (hocanın deyişiyle aslında çok gerekli olmayan) ek bir mesaj `outState`'e yazılır. Aktivite kullanıcı tarafından bilinçli olarak sonlandırılmadıysa, yeniden yaratıldığında bu Bundle sayesinde kaldığı yerden devam eder.

**onRestoreInstanceState.** Bu metot, `onCreate`'te Bundle'ın null olup olmadığını kontrol ettiğimiz kod parçasının yaptığı işin aynısını yapar. İki seçenek vardır: ya `onCreate`'te Bundle'ı kontrol edip bilgileri çekersiniz, ya da `if` kodunu hiç yazmayıp `onRestoreInstanceState`'i yazarsınız. Bundle'da bir şey varsa aktivite `onRestoreInstanceState`'i zaten çağırır.

> **Hocanın vurgusu:** `onRestoreInstanceState` ile `onCreate`'teki null kontrolü birbirinin alternatifidir; ikisini aynı anda yazmaya gerek yoktur, biri seçilir.

> **Ek bilgi (derste anlatılmadı):** `onRestoreInstanceState`, `onStart()`'tan sonra ve yalnız geri yüklenecek bir Bundle varsa çağrılır; bu yüzden içinde null kontrolüne gerek yoktur. `onSaveInstanceState` ise Android 9 (API 28) ve sonrasında `onStop()`'tan sonra, daha eski sürümlerde `onStop()`'tan önce çağrılır.

## 8. Layout XML Temelleri

Sayaç örneğinin layout dosyası slaytta şöyledir (ekrandan, 01:10:00):

```xml
    <EditText
        android:layout_width="match_parent"
        android:layout_height="wrap_content"
        android:hint="Phone number"
        android:inputType="phone" />

    <TextView
        android:id="@+id/textView"
        android:layout_width="wrap_content"
        android:layout_height="wrap_content"
        android:text="0"
        android:textSize="32sp" />

    <Button
        android:id="@+id/button"
        android:layout_width="wrap_content"
        android:layout_height="wrap_content"
        android:text="COUNT UP" />

</LinearLayout>
```

Hoca bu dosyada bir EditText, bir TextView ve bir buton olduğunu söyledi; her bileşene ait özellikler tanımlanabilir:

- `match_parent`: bileşenin genişliği içinde bulunduğu bileşene göre belirlenir.
- `wrap_content`: boyut bileşenin içeriğinin büyüklüğüne göre belirlenir.
- `hint`: alanın içine silik bir ipucu yazısı ("Phone number") koyar; bazen telefon numarası biçimi de yazılarak alanın nasıl doldurulacağı gösterilir.
- `inputType`: giriş türünü kısıtlar; örneğin telefon alanına harf yazılması engellenir. Bu kontrol Android tarafından otomatik yapılır.

**Kimlik tanımı.** Bir bileşene kimlik ilk kez tanımlanırken `@+id/ad` yazılır. Bu ad, kodda `R.id.ad` ile ilişkilendirme yaparken kullanılacak addır. Bir ekranda birden fazla TextView olabileceği için bileşenlere `textView` yerine `password`, `username` gibi ayırt edici adlar verilmelidir. Var olan bir kimliğe başvururken (referans verirken) yalnız `@id/ad` yazmak yeterlidir, `+` gerekmez.

> **Hocanın vurgusu:** Tanımlama için `@+id`, referans için `@id` yazılır; buna dikkat etmek gerekir.

Tıklandığında çağrılacak metodun adı da XML'de `onClick` özelliğiyle verilebilir; böylece koddaki dinleyici bloğu yerine bu kullanılabilir. Bileşenler bir layout içinde verilir: bu bir RelativeLayout ya da LinearLayout olabilir. Bunların kullanımı ileride çeşitli örneklerle görülecek.

## 9. Intent'ler: Explicit ve Implicit

Bir aktivitenin başka bir aktiviteyle, bir uygulamanın başka bir uygulamayla etkileşime girmesi çok doğaldır. Kendi uygulamanızda bir aktiviteden diğerine geçersiniz ya da bir uygulamadaki aktiviteden başka bir uygulamadaki aktiviteye atlarsınız. Diğer aktiviteyi çağırmak için genellikle Intent bileşeni kullanılır. Çağırma işi Intent üzerinden yapılır ve diğer aktiviteye aktarılacak bilgiler de Intent ile gönderilir. Karşı aktiviteden bilgi geri dönmesi isteniyorsa `startActivityForResult` metodu çağrılır.

Intent'lerin başka türleri de vardır (broadcast intent, sticky intent); bunlar ileride görülecek. Ama temelde intent'ler iki gruba ayrılır. Slayttaki şema (ekrandan, 01:15:00):

- **Implicit intent:** haritada coğrafi konum gösterme (MAP / GEO Location), arama yapma (Dial a Call), web sitesini WebView'da açma (Launch Website in WebView).
- **Explicit intent:** broadcast receiver başlatma, aktivite başlatma, arka plan servisi başlatma.

### 9.1 Explicit intent

Uygulama için bir sonraki adımın belli olduğu, işi kimin yapacağının bilindiği durumda sistem doğrudan geçilecek ekrana yönlendirilir. Buna explicit intent denir. Bir aktivitenin başlatılması, bir broadcast receiver'ın başlatılması, arka plan servisinin çalıştırılması bu gruptadır.

Hocanın örneği: Login butonuna bastınız. Girdiğiniz kullanıcı adı ve şifre doğruysa uygulama sizi bir sonraki ekrana yönlendirir. Yanlışsa ya bir açılır pencereyle (pop-up) mesaj alırsınız ya da başka bir ekrana, örneğin "şifre yanlış olduğu için" kayıt ekranına yönlendirilirsiniz. Burada hedef aktivite doğrudan bellidir.

### 9.2 Implicit intent

Her durumda bir aktiviteyi doğrudan çağırmak gerekmez; bazen bir iş yaptırmak istersiniz ve o işi yapabilecek aktiviteler çağrılır. Hocanın örnekleri:

- Bir web sayfasında bir telefon numarası gördünüz, üzerine uzun bastınız ve "ara" seçeneği çıktı. Seçeneğe dokunduğunuzda aramayı yapabilecek başka bir uygulamanın aktivitesi çağrılır.
- Bir adres bilgisinin haritada gösterilmesi gerekiyor. Google Maps, Apple Maps ya da Yandex gibi uygulamalar bu hizmeti vermek için bekler; onların ilgili aktivitesi çağrılır.

Toparlarsak: Yaptırmak istediğiniz bir iş var ve "bunu kim yapabilir, bana alternatifleri ver" diyorsanız implicit intent kullanırsınız. Yapmak istediğinizi intent'e ekleyip gönderirsiniz; sistem intent filter'lara bakar ve "veri paylaşmak istiyorsun, şu uygulamalarla paylaşabilirsin" ya da "e-posta göndermek istiyorsun, şu e-posta istemcileri var" diyerek seçenekleri önünüze getirir. Explicit intent'te kaynak kodda hedefin adı söylenir; implicit intent'te hedef belirtilmez, yapılmak istenen iş belirtilir ve intent'e o işle ilgili özellikler eklenir.

### 9.3 Örnek implicit intent'ler

Slaytta implicit intent örnekleri vardı; altyazıya göre anlatılanlar şunlardır:

- **Numara arama:** Aranacak numara bir URI (Uniform Resource Identifier) olarak `Uri.parse` metoduyla ön işlemden geçirilir. Sonra intent tanımlanır ve yapıcısına (constructor) hangi aksiyonun istendiği verilir; burada aksiyon "dial"dır. Aksiyon söylenmezse sistem ne yapmak istediğinizi anlamaz. Ayrıca işi yapacak aktiviteye hangi numarayı araması gerektiği mutlaka gönderilmelidir. İşi yapacak aktivite de kendi kodunu çalıştırmaya başladığında bu bilgiyi `getIntent` metoduyla alır.
- **Haritada konum gösterme:** Bir konum bilgisinin harita üzerinde görselleştirilmesi için `ACTION_VIEW` aksiyonu istenir.
- **Web adresi açma:** Adres `Uri.parse` ile hazırlanır ve yine `ACTION_VIEW` aksiyonuyla gönderilir. Bu kez aksiyonu Firefox, Safari ya da Chrome gibi bir tarayıcı karşılar.

<!-- BELİRSİZ: Arama, harita ve web adresi örneklerinin slayttaki tam kodu karelerde görünmüyor (yaklaşık 01:15:30-01:17:30 arası); yukarıdaki anlatım altyazıdan kurulmuştur. -->
## 10. Intent ile Veri Taşıma ve Aktivite Başlatma

### 10.1 E-posta ve takvim örnekleri

Önceki örneklerde çok küçük bilgiler gönderildi; bazen daha fazlasını paylaşmak gerekir. Hocanın örneği: Ekranınızda bir e-posta seçeneği sundunuz; kullanıcı konuyu, alıcıyı vb. yazdı. Fakat uygulamanızın e-posta gönderme yeteneği yok, çünkü bunun için arka planda POP3, SMTP, IMAP bağlantılarının düzenlenmesi gerekir. Buna karşılık bir Gmail istemcisinin ya da çalıştığınız kurumun size sunduğu e-posta uygulamasının bu yeteneği vardır. Slayttaki kod (ekrandan, 01:20:00):

```java
// Sending an E-mail
Intent emailIntent = new Intent(Intent.ACTION_SEND);
// The intent does not have a URI, so declare the "text/plain" MIME type
emailIntent.setType(HTTP.PLAIN_TEXT_TYPE);
emailIntent.putExtra(Intent.EXTRA_EMAIL, new String[] {"jon@example.com"}); // recipients
emailIntent.putExtra(Intent.EXTRA_SUBJECT, "Email subject");
emailIntent.putExtra(Intent.EXTRA_TEXT, "Email message text");
emailIntent.putExtra(Intent.EXTRA_STREAM, Uri.parse("content://path/to/email/attachment"));
// You can also attach multiple items by passing an ArrayList of Uris
```

Burada `putExtra` metodu çağrılarak konu, metin ve kullanıcıdan alınan diğer bilgiler intent'e yüklenir. Slaytta değerler sabit yazılmıştır (hardcoded); gerçekte EditText'lerden gelen bilgiler alınıp intent'e konur ve kullanıcı hangi e-posta istemcisini seçtiyse bilgiler oraya aktarılır.

Aynı slaytta bir takvim uygulamasına kullanıcının etkinliğini kaydetme örneği de vardır (ekrandan, 01:20:00):

```java
// Creating and Adding a Calendar Event
Intent calendarIntent = new Intent(Intent.ACTION_INSERT, Events.CONTENT_URI);
Calendar beginTime = Calendar.getInstance();
beginTime.set(2012, 0, 19, 7, 30);
Calendar endTime = Calendar.getInstance();
endTime.set(2012, 0, 19, 10, 30);
calendarIntent.putExtra(CalendarContract.EXTRA_EVENT_BEGIN_TIME, beginTime.getTimeInMillis());
calendarIntent.putExtra(CalendarContract.EXTRA_EVENT_END_TIME, endTime.getTimeInMillis());
calendarIntent.putExtra(Events.TITLE, "Ninja class");
calendarIntent.putExtra(Events.EVENT_LOCATION, "Secret dojo");
```

`ACTION_INSERT` özelliğini gösteren herhangi bir takvim uygulamasına bu bilgiler gönderilerek belirli bir gün ve saatte, belirli başlık ve ayrıntıdaki etkinliğin kaydedilmesi istenebilir. Takvim uygulaması bu bilgileri kendi depolama alanına ekler.

> **Ek bilgi (derste anlatılmadı):** Java'nın `Calendar` sınıfında aylar 0'dan başlar; `set(2012, 0, 19, 7, 30)` 19 Ocak 2012 saat 07:30 demektir. Örnekteki etkinlik 07:30-10:30 arası, yani 3 saat sürer.

> **Hocanın vurgusu:** Bilgiler kendiliğinden taşınmaz. Karşı uygulama yalnız sizin götürdüğünüz kadarını alabilir ve işleyebilir. "Intent o anda sayfadaki her şeyi alır ve benim adıma gönderir" diye bir senaryo yoktur; gereken bilgileri tek tek intent'e yüklemeniz ve intent'in özelliklerini tanımlamanız gerekir.

### 10.2 İşi yapacak uygulama var mı?

Telefon etmek, e-posta göndermek, takvime kayıt eklemek gibi temel işler için genelde bu işi karşılayabilecek aktivitelere sahip uygulamalar bulunur. Ama yaptırmak istediğiniz işi yapabilecek bir aktivite hiçbir uygulamada yoksa ve bunu kontrol etmezseniz sisteminiz hata üretebilir. Bu yüzden intent'teki talebi karşılayabilecek bir aktivite olup olmadığı mutlaka kontrol edilmelidir. Hoca, bu kontrol kodunun zamanla güncellemeler aldığını da belirtti.

> **Hocanın vurgusu:** Kimse size bir şey dönmezse programınız listeyi gösteremediği için çökmesin; bu kontrolü yapmayı aklınızda tutun.

### 10.3 Intent'i başlatmak

Slayttaki açıklama (ekrandan, 01:25:00): Intent'i oluşturup ek bilgileri yükledikten sonra onu sisteme göndermek için `startActivity()` çağrılır. Sistem intent'i karşılayabilecek birden fazla aktivite bulursa kullanıcının hangi uygulamayı kullanacağını seçmesi için bir diyalog (bazen "disambiguation dialog" diye anılır) gösterir. Slayttaki kod:

```java
// Build the intent
Uri location = Uri.parse("geo:0,0?q=1600+Amphitheatre+Parkway,+Mountain+View,+California");
Intent mapIntent = new Intent(Intent.ACTION_VIEW, location);

// Verify it resolves
PackageManager packageManager = getPackageManager();
List<ResolveInfo> activities = packageManager.queryIntentActivities(mapIntent, 0);
boolean isIntentSafe = activities.size() > 0;

// Start an activity if it's safe
if (isIntentSafe) {
    startActivity(mapIntent);
}
```

Akış şöyledir: bir adres harita uygulamasında gösterilmek isteniyor. Adres `mapIntent`'e yüklenir. Sonra bu talebe karşılık gelebilecek bir ya da birden fazla uygulama olup olmadığı kontrol edilir. Karşı aktiviteden bir bilgi dönmeyecekse intent `startActivity` metoduna verilir; değer dönecekse `startActivityForResult` çağrılır.

Slaytın sağ alt köşesinde "Open with" başlıklı bir seçim ekranı vardır (Chrome, Firefox). Kullanıcı hangisiyle açmak istediğini seçer: yalnız bir kerelik seçebilir ya da "her zaman bununla aç" diyebilir. İkincisinde sistem ayarlarına kaydedilir ve intent bundan sonra hep o uygulamayla açılır.

Bazı geliştiriciler seçeneklerin her seferinde kullanıcıya gösterilmesini ister. Bunun için bir liste oluşturulup her seferinde kullanıcıya gösterilmesi sağlanabilir. Bir yanda sistemin sunduğu varsayılan seçim ekranı, öbür yanda her seferinde sizin istediğiniz biçimde soran özel bir seçici (chooser) ekranı vardır; bu tamamen geliştiricinin tercihidir.

> **Ek bilgi (derste anlatılmadı):** Her seferinde seçim ekranı göstermek için genellikle `Intent.createChooser(intent, "başlık")` ile sarılmış intent `startActivity`'ye verilir. Android 11 (API 30) ve sonrasında başka uygulamaları sorgulamak için manifest'e `<queries>` öğesi eklemek gerekir; bu yüzden `queryIntentActivities` kontrolünün yazımı sürümlere göre değişmiştir.

Başka bir aktiviteden sonuç alma senaryosu da slaytlarda vardı, ama bu derste ona geçilmedi.

## 11. Android Studio'da İlk Uygulama: Basit Login

Dersin son bölümünde Android Studio'da yazılmış basit bir login uygulaması birlikte incelendi. Hoca, bazı öğrencilerin ilk etapta zorlandığı için kolay bir örnekle başladığını söyledi.

### 11.1 Proje yapısı

Proje ağacında `manifests` altında `AndroidManifest.xml`, `java/com.example.myapplication` altında iki aktivite (`Login` ve `User`) ve `res/layout` altında bu aktivitelerin layout dosyaları (`activity_login.xml`, `activity_user.xml`) vardır (ekrandan, 01:40:00).

### 11.2 Login ekranının XML'i

Login ekranında bir `RelativeLayout` kullanılmıştır (hoca bunun değişebileceğini söyledi). İçinde önce bir TextView ("Login" başlığı), ardından ikinci bir TextView ("Username" yazısı) vardır. Karedeki tanımlar (ekrandan, 01:40:00):

```xml
<TextView
    android:id="@+id/tv_login"
    android:layout_width="wrap_content"
    android:layout_height="wrap_content"
    android:layout_alignParentLeft="true"
    android:layout_alignParentStart="true"
    android:layout_alignParentTop="true"
    android:layout_marginLeft="11dp"
    android:layout_marginStart="11dp"
    android:layout_marginTop="13dp"
    android:text="Login"
    android:fontFamily="sans-serif-condensed"
    android:textSize="30sp"/>

<TextView
    android:id="@+id/tv_username"
    android:layout_width="wrap_content"
    android:layout_height="wrap_content"
    android:layout_alignLeft="@+id/tv_login"
    android:layout_alignStart="@+id/tv_login"
    android:layout_below="@+id/tv_login"
    android:layout_marginTop="80dp"
    android:fontFamily="monospace"
    android:text="Username"
    android:textSize="25sp" />

<EditText
    android:id="@+id/et_username"
    ...
```

Hocanın açıklamaları:

- İlk TextView'a `@+id/tv_login` ile kimlik verilmiştir; bileşenin bütün özellikleri tek tek burada tanımlanır.
- `dp`, yoğunluktan bağımsız piksele (density-independent pixel) karşılık gelir.
- TextView'da ne yazacağı (`text`), yazı tipi ailesi (`fontFamily`) ve yazı boyutu (`textSize`) belirlenmiştir.
- İkinci TextView konumlandırılırken hangi bileşenin pozisyonuna göre yerleşeceği (`layout_below`, `layout_alignLeft`) yazılmıştır.
- TextView'lar sabit bilgi gösterir. EditText ise adını "editable" (düzenlenebilir) kelimesinden alır; içine bilgi girilebilen yapıdır. Kullanıcı adı alanının altında yine bir "Password" TextView'u ve bir EditText, en altta da bir login butonu vardır.

Hoca bu ekrana başka butonlar da eklenebileceğini söyledi: yazılanları silen bir "Clear" butonu ya da başka bir sayfaya yönlendiren bir "Register" butonu gibi.

> **Ders sonrası not:** Hoca yazı boyutunun piksel olarak verildiğini söyledi; karede birim `sp`'dir (scale-independent pixel). `sp`, `dp` gibi yoğunluktan bağımsızdır ve ek olarak kullanıcının sistemdeki yazı boyutu ayarına göre ölçeklenir.

> **Ek bilgi (derste anlatılmadı):** Karedeki XML'de başvurular da `@+id/tv_login` biçiminde yazılmıştır. Bu da çalışır, çünkü kimlik zaten varsa `+` yeni bir kimlik yaratmaz; ama derste söylenen kurala göre referans için `@id/tv_login` yazmak yeterlidir.

### 11.3 Login.java

XML'in kod tarafındaki karşılığı `Login.java`'dır. Karedeki kod (ekrandan, 01:45:00 ve 01:50:00):

```java
import android.content.Intent;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

import androidx.appcompat.app.AppCompatActivity;

public class Login extends AppCompatActivity {
    EditText username, password;
    Button login;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_login);

        username = (EditText) findViewById(R.id.et_username);
        password = (EditText) findViewById(R.id.et_password);

        login = (Button) findViewById(R.id.btn_login);

        login.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                if (username.getText().toString().equals("admin")
                        && password.getText().toString().equals("admin")) {
                    Toast.makeText(Login.this, "Username and Password is correct",
                            Toast.LENGTH_SHORT).show();
                    Intent intent = new Intent(getApplicationContext(), User.class);
                    startActivity(intent);
                } else {
                    Toast.makeText(Login.this, "Username or Password is incorrect",
                            Toast.LENGTH_SHORT).show();
                }
            }
        });
    }
}
```

Karede uzun satırlar tek satırdı; burada okunabilirlik için bölündü. Karedeki import listesinin en üstünde bir satır daha (`android.annotation.SuppressLint`) yarı görünür durumdadır.

Adım adım:

1. **Alanlar.** İki EditText ve bir buton tanımlanır ki XML dosyasıyla ilişkilendirme yapılabilsin.
2. **setContentView.** `onCreate`'te ilk yazılması gereken bilgi, `setContentView(R.layout.activity_login)` ile layout'un bağlanmasıdır. Burada `.xml` uzantısı yazılmaz. Bu satırdan sonra sistem eşleşmenin `activity_login.xml` ile `Login` Java kodu arasında olacağını bilir.
3. **findViewById.** Ardından adlar eşleştirilir. Hoca, XML'deki adlarla koddaki değişken adlarının farklı olmasının faydalı olacağını söyledi: `username` ve `password` login aktivitesindeki değişkenlerdir, `et_username` ve `et_password` ise XML dosyasındaki bileşenlere başvurur. Hoca canlı olarak buton değişkeninin adını değiştirdi; adlar değişince Android Studio ilgili yerleri kırmızıya boyadı ve bunlar düzeltildi. Sonuçta `btn_login` XML'deki bileşenin adı, `login` de koddaki değişkenin adı oldu.
4. **Dinleyici.** `findViewById` ile ilişki kurulduktan sonra koddaki `login` adıyla devam edilir ve `login.setOnClickListener` çağrılarak takibi yapacak dinleyici etkinleştirilir. Anonim bir sınıf yaratılır, içinde `onClick(View v)` metodu yazılır ve yapılacak işe odaklanılır.
5. **Kontrol.** `username.getText().toString()` "git, şuradaki bilgiyi al, metne çevir" demektir; sonra `"admin"`'e eşit mi diye bakılır. Bu örnekte kullanıcı adı ve şifre ikisi de "admin" girilirse doğru dala, aksi halde `else` dalına gidilir.
6. **Toast.** Doğruysa `Toast.makeText` ile "Username and Password is correct" mesajı üretilir, `.show()` ile ekranda gösterilir. Parametreler mesajın ne kadar süre ve (hocanın anlatımıyla) hangi konumda görüneceğini belirler. Hoca varsayılanın ekranın alt kısmında kısa süreli, 3-5 saniye görünmek olduğunu söyledi.
7. **Explicit intent.** Ardından bir intent yaratılır. İlk parametre olarak genelde `getApplicationContext()` ile içinde bulunulan bağlam (context) alınır, ikinci parametre çağrılmak istenen sınıfın adıdır (`User.class`). Bu bir explicit intent kullanımıdır. `startActivity(intent)` ile intent verildiğinde sistem `User` aktivitesini çağırır ve onun XML'inde ne yazıyorsa ya da içinde ne yapılıyorsa onu yapar.
8. **Yanlış giriş.** Şifre yanlışsa ekrana "Username or Password is incorrect" yazdırılır.

> **Ders sonrası not:** `Toast.LENGTH_SHORT` yaklaşık 2 saniye, `Toast.LENGTH_LONG` yaklaşık 3,5 saniyedir; hocanın "3-5 saniye" dediği süre büyük olasılıkla kaba bir tahmindir. `makeText`'in parametreleri bağlam, metin ve süredir; konum `makeText` ile değil, ayrı bir `setGravity` çağrısıyla ayarlanır.

`User` aktivitesinin ekranında iki TextView vardır: birinde daha büyük harflerle "Welcome", ötekinde daha küçük harflerle "Administrator" yazar. `User.java`'da bunun dışında bir şey yoktur; yalnız XML'e gömülü mesajlar gösterilir.

### 11.4 Manifest

Manifest'te iki aktivite tanımlanır. Bunlardan biri mutlaka MAIN ve LAUNCHER olarak işaretlenmelidir ki uygulama ilk açıldığında hangi aktivitenin çalışacağı belli olsun. Diğer aktivite için böyle bir tanım gerekmez. Hoca manifest'te yeni yaratılan aktivitenin adını da düzeltti. Bu örnekte özel bir action içeren intent filter tanımlanmadı; bu ileriki haftalarda yapılacak. Böylece bir uygulama içinde iki aktivite tanımlanmış ve biri başlangıç aktivitesi olarak belirtilmiş oldu.

<!-- BELİRSİZ: Manifest dosyasının içeriği karelerde görünmüyor (yaklaşık 01:48:30); anlatım altyazıdan kurulmuştur. -->

### 11.5 Çalıştırma ve kendi uygulamanı yazma

Hoca uygulamayı fiziksel telefonunda çalıştırıp ekranını paylaştı: "admin", "admin" yazıp Login'e bastığında ikinci aktiviteye, "Welcome Administrator" yazan ekrana yönlendirildi. Hoca bu arayüzün çok sevimli olmadığını, önemli olanın işlevselliği görmek olduğunu, daha iyi ekran tasarımlarının uzun vadede işe yarayacağını söyledi.

Kendi projenizi oluşturmak için New Project denir, hangi cihaz için uygulama geliştirildiği seçilir, sonra Basic Activity ya da Empty Activity seçilerek ekranlar adım adım izlenir. Yeni sınıflar ve ekranlar proje ağacında New menüsünden eklenir.

Hoca login ekranının geliştirilmesi için şu fikirleri verdi:

- Login yerine bir yanda "Sign in", öbür yanda "Sign up" butonu konabilir. Sign in bilgileri alıp kontrol eder; Sign up kayıt sayfasını çağırır.
- Şifreyi görünür yapan küçük bir arayüz bileşeni eklenebilir.
- Bir kişi şifreyi 3 kez yanlış girerse login butonu devre dışı bırakılabilir.
- Tek bir sabit "admin" kontrolü yerine bir `User` sınıfı oluşturulup kayıt ekranından yeni kullanıcı nesneleri yaratılabilir ve girişte bu nesnelere göre kontrol yapılabilir. İlk etapta veritabanına ya da dosyaya yazmak zorunlu değildir; veri modeli oluşturup bilgileri uygulama çalıştığı sürece saklamak yeterlidir.
- Giriş doğruysa açılacak sayfada kullanıcının resmi, adı soyadı ve kayıt sırasında verdiği diğer bilgiler gösterilebilir.
- Galeriden fotoğraf seçmek için uygulama doğrudan galeri uygulamasını çağırabilir ve seçilen resimler uygulamaya geri döndürülebilir; bu resimler Firebase gibi bir alana yüklenebilir.

Hoca örnek projeyi doğrudan paylaşmayı tercih etmediğini, benzer örneklerin "login and register sample code" gibi aramalarla GitHub'da bulunabileceğini söyledi. Başkasının kodunu kendi ortamınıza aktarırken hatalarla karşılaşmanın da öğretici olduğunu ekledi: her kod farklı zamanda, farklı API'ler ve farklı Gradle derleme sürümleriyle geliştirildiği için JDK uyumsuzlukları gibi sorunlar çıkar ve bunları aşmanın teknik yolları vardır. Günün sonunda bütün kodları sıfırdan yazmayacağınız için bu deneyim faydalıdır.

## Örnek Sorular

**Soru 1** (derste sözlü, 00:28:02): `onPause()` metodunda yalnız kaynak iadesi mi yapılır?

> **Cevap (derste verildi):** Hayır. `onPause()`'a geçerken o andaki bazı bilgiler de saklanabilir, örneğin SharedPreferences'a küçük bir bilgi yazılabilir. `onStop()`'ta da kalıcı olması gereken bir bilgi veritabanına yazılabilir, çünkü arka plana düşen aktivite önce `onStop()`'a geçer ve kaynak ihtiyacına göre sistem tarafından yok edilebilir. Ancak büyük veriler bu metotlarda ana thread'de yazılmamalıdır; en kötü yer `onDestroy()`'dur.

**Soru 2** (derste sözlü, 01:06:21): Ekran döndürülünce aktivite yok edilip yeniden yaratılıyorsa, YouTube gibi uygulamalarda döndürünce video nasıl kaldığı yerden devam ediyor? Yeni bir aktivite mi oluşturuluyor, yoksa bilgiler kaydedilip ekran baştan mı kuruluyor?

> **Cevap (derste verildi):** Android cihazlarda yapılandırma değişikliğinde aynı kurallar YouTube gibi uygulamalar için de geçerlidir: aktivite yok edilir ve yeniden yaratılır. Bu uygulamalar kaldığınız yerden devam etmenizi sağlamakla yükümlüdür; çok bilgi saklanıyormuş gibi görünse de bazı sadeleştirmelerle gereken durumu kısa sürede saklayıp geri yüklerler.

**Soru 3** (derste sözlü, 01:17:47): Bir uygulamada bir web linkine tıklayınca cihazdaki tarayıcılar (Chrome ya da varsayılan tarayıcı) arasından seçim yapmamızı isteyen "şununla aç" ekranı explicit intent midir?

> **Cevap (derste verildi):** Hayır, bu implicit intent'tir. Sisteme "bir web tarayıcı açmaya ihtiyacım var, bunu benim için kim açabilir?" denir. Implicit intent "bir iş yapmak istiyorum, işim şu, bu işi benim adıma kim yapabilir?" demektir. Explicit intent ise tam tersidir: "bu işi şu aktivitenin yapmasını istiyorum."

**Soru 4** (ekrandan, 01:45:00): Derste canlı incelenen alıştırma: iki EditText (kullanıcı adı, şifre) ve bir butondan oluşan bir login ekranı yazın. Kullanıcı adı ve şifre "admin" ise doğru mesajı gösterip ikinci bir aktiviteye ("Welcome Administrator") geçilsin, değilse hata mesajı gösterilsin.

> **Çözüm (derste verildi):** Bölüm 11.3'teki `Login.java` kodu: `setContentView(R.layout.activity_login)`, `findViewById` ile `et_username`, `et_password`, `btn_login` bağlanır; `setOnClickListener` içinde `getText().toString().equals("admin")` kontrol edilir; doğruysa `Toast.makeText(...).show()` ve `startActivity(new Intent(getApplicationContext(), User.class))`, değilse "Username or Password is incorrect" Toast'u. Manifest'te `Login` MAIN/LAUNCHER olarak, `User` yalnız adıyla tanımlanır.

**Soru 5** (derste sözlü, 02:03:03): Login ekranına bir sign up butonu koyarsak, butona tıklayınca açılacak ekran için de yine `onCreate`'i olan ayrı bir aktivite oluşturmamız gerekir mi?

> **Cevap (derste verildi):** Evet. Örnekteki `User.java` nasıl ayrı bir aktiviteyse, kayıt ekranı da ayrı bir aktivite olarak oluşturulur ve kodu oraya yazılır. Login butonunda olduğu gibi sign up butonunda da `startActivity` ile intent bu yeni aktiviteye yönlendirilir.

**Soru 6** (derste sözlü, 02:11:20): Cihazımı USB ile bağladım ama Android Studio cihazı görmüyor; Android Studio'yu yeniden mi başlatmam gerekir?

> **Cevap (derste verildi):** USB hata ayıklama (USB debugging) modunu açmak gerekir. Telefonda "Telefon hakkında" bölümünde yapı (build) numarasına 7 kez dokunarak önce Geliştirici seçenekleri etkinleştirilir; sonra bu seçeneklerden hata ayıklama modu açılır ve telefon tanınır.

**Soru 7** (derste sözlü, 02:27:25): Uygulamalarda dil olarak Kotlin kullanılabilir mi?

> **Cevap (derste verildi):** Evet, Kotlin kullanılabilir, bir sakıncası yoktur.

## Dersin Toparlaması

Bu derste önce aktivitenin bir uygulamadaki yeri ve manifest'te nasıl tanımlandığı, intent filter ile bir aktivitenin yeteneklerinin sisteme nasıl bildirildiği görüldü. Ardından Activity yaşam döngüsü (`onCreate`, `onStart`, `onResume`, `onPause`, `onStop`, `onRestart`, `onDestroy`) ayrıntılı incelendi: her metotta hangi işlerin yapılacağı, `onPause`/`onResume` ayna ilişkisi, Home ile Back tuşunun farkı, yapılandırma değişikliğinde aktivitenin yeniden yaratılması ve sistemin bellek gerektiğinde hangi aktiviteyi önce attığı konuşuldu. Kullanıcının durumunu korumak için ViewModel, Bundle (saved instance state) ve kalıcı depolama karşılaştırıldı; `onSaveInstanceState` ve `onRestoreInstanceState` bir sayaç örneğiyle gösterildi.

İkinci kısımda Intent'ler ele alındı: hedefi belli olan explicit intent ile yalnız işi tanımlayan implicit intent'in farkı, `putExtra` ile veri taşıma (e-posta, takvim), işi karşılayacak uygulama olup olmadığının kontrolü ve seçim ekranı. Son olarak Android Studio'da XML layout ile Java kodunun `setContentView` ve `findViewById` ile nasıl bağlandığı, explicit intent ve `startActivity` ile ikinci bir aktiviteye nasıl geçildiği basit bir login uygulaması üzerinden gösterildi. Login ekranının bir kayıt (sign up) ekranı ve kullanıcı veri modeliyle genişletilmesi, sonraki adımlar için önerildi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
