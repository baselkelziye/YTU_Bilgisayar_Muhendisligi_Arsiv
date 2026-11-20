# Ders 14 Genişletilmiş Notu: Konum Servisleri ve Geofence

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Mobil Uygulamalarda Konum Bilgisi
- 2. Konum Kaynakları ve Enerji Maliyeti
- 3. Ön Plan ve Arka Plan Konum Erişimi
- 4. Konum İzinleri
- 5. Google Play Services ve Son Bilinen Konum
- 6. Pil Tüketimini Belirleyen Parametreler
- 7. Konum Kullanım Senaryoları
- 8. Sürekli Konum Güncellemesi
- 9. Konum API'leri ve Arka Plan Erişimi
- 10. Geofence (Sanal Bölge)
- 11. Uygulama: MapActivity ile Konum ve Harita
- Örnek Sorular
- Dersin Toparlaması

## 1. Mobil Uygulamalarda Konum Bilgisi

Bu derste Android'de konum servisleri işlendi: uygulamaların konum bilgisini nasıl kullandığı, işletim sistemlerinin bu konuda zamanla neleri değiştirdiği ve konumun koda nasıl alındığı. Kullanılan slayt destesi "AndroidProgramming-Lesson8" adını taşıyor (ekrandan, 00:20:00).

Hoca harita uygulamalarını özellikle örnek dışında tuttu, çünkü harita uygulamalarında konum zaten en baştan beri merkezdedir. Bugün birçok talep üzerine çalışan (on-demand) uygulama farkını konum üzerinden yaratır. Taksi uygulaması, sürücünün görmediği bir müşteriyi konum eşleşmesi ve haritalama fonksiyonlarıyla onunla buluşturur. Daha basit bir örnek hava durumu (weather) uygulamasıdır: ülke ya da il değiştirdiğinizde, hiçbir seçim yapmadan bulunduğunuz bölgenin hava durumunu gösterir.

Bu iki uygulamanın konuma ihtiyaç duyduğu sıklık çok farklıdır. Haritalama uygulamaları çok sık konum ister. Hava durumu uygulamasında ise dakikalar ya da saniyeler içinde bölge değiştirmediğiniz için bu sıklığa gerek yoktur. Bu yüzden bir uygulama tasarlarken sistem analizinde iki soru cevaplanmalıdır: konum hangi sıklıkta ve hangi hassasiyette gerekiyor? Bu karar, derste görülecek seçenekler arasından seçim yapmayı belirler.

Kararın bu kadar önemli olmasının nedeni konum almanın maliyetidir. Bu maliyet parasal değil, pil tüketimidir. Yüksek hassasiyetle konum istendiğinde telefonun pili hızla tükenir. İşletim sistemleri bu yüzden "yalnız uygulama açıkken" ya da "yalnız bu sefer" gibi seçenekler sunar. Bu seçenekler, arka planda açık unutulan ve boş yere konum takip eden uygulamaların enerji tüketiminin önüne geçer.

## 2. Konum Kaynakları ve Enerji Maliyeti

Hoca, telefonun konum için hangi bileşenleri ve kaynakları kullanabileceğini sınıfa sordu.

### 2.1 GPS

İlk cevap GPS oldu. GPS, Global Positioning System'in kısaltmasıdır. Hoca bu adı, farklı ülkelerin uydu sistemlerini temsil eden genel bir ad gibi düşünebileceğimizi söyledi; Rusların sistemi GLONASS'tır, Çin'in de kendi sistemi vardır. GPS'te telefon ile uydular arasındaki sinyallerin süreleri kullanılır ve kişinin konumu üçgenleme (triangulation) mantığıyla belli bir hassasiyetle kestirilir. Normal şartlarda en yüksek hassasiyeti GPS verir.

> **Ek bilgi (derste anlatılmadı):** Çin'in uydu konumlama sistemi BeiDou, Avrupa Birliği'nin sistemi Galileo'dur. Telefonlar genellikle bu sistemlerin birkaçından gelen sinyalleri birlikte kullanır.

**Soru:** GPS'ten veri alındıktan sonra ivmeölçer gibi sensörlerle sonraki konum tahmin edilebilir mi, örneğin yer altındayken? **Cevap:** Hoca sorulan alternatifin ivmeölçer ya da jiroskop olmadığını, konumu doğrudan veren başka kaynakların arandığını söyledi.

### 2.2 Wi-Fi Erişim Noktaları ve Baz İstasyonları

Öğrencilerin verdiği diğer iki cevap Wi-Fi ağları (erişim noktaları, access point) ve bağlı olunan baz istasyonu oldu. Baz istasyonlarının ve Wi-Fi erişim noktalarının konumları bilindiği için bunlar özellikle belirli yerlerde çok yüksek doğrulukla konum verir. Bu yerler ağırlıklı olarak şehir merkezleridir, çünkü orada baz istasyonları da erişim noktaları da daha sık yerleşmiştir. Kırsala çıkıldığında birim alana düşen baz istasyonu ve erişim noktası sayısı azalır, hesaplamaların hata payı büyür.

Haritada konum genellikle bir nokta ve çevresinde bir daireyle gösterilir. Sistem aslında şunu söyler: "Merkezi hesapladım, ama sen bu dairenin herhangi bir yerinde olabilirsin." GPS bağlantısı hava şartlarından ve bulunulan fiziksel yerden etkilenir; bu yüzden zaman zaman sapmalar görülür. Hoca 10 metreler, 50 metreler mertebesinde doğruluktan, zaman zaman GPS ile 1-2 metreye kadar inen doğruluktan söz etti.

Bina içinde değilseniz GPS sinyaliyle sorun yaşama ihtimaliniz düşüktür. Bina içindeyseniz, birine adres tarif etmek için pencere kenarına yaklaşırsınız. Kapalı büyük binalar, özellikle bodrum katlar ve beton yığınlarının içi konum açısından ciddi sorun çıkarır. Hoca, yaşanan deprem felaketlerinde de araçları bir noktaya yönlendirirken konumla ilgili sorunlar ve hatalar yaşandığını hatırlattı.

### 2.3 Son Bilinen Konum

Bu üç yönteme ek olarak bir seçenek daha vardır: yeni bir konum hesaplatmadan, en son alınmış ve en güncel olan konumu istemek. Bu, son 1-2 saatte ya da 5 saatte başka bir uygulamanın almış olduğu konumun işletim sistemi tarafından sizin uygulamanıza aktarılması demektir. Birçok uygulama bunu yapar. Neredeyse hiç enerji harcamaz; enerjinin en az tüketildiği seçenektir.

### 2.4 Enerji Sıralaması

Hoca enerji tüketimini en çoktan en aza GPS, baz istasyonu ve Wi-Fi erişim noktası olarak sıraladı. Bu sıralamanın sebebi uzaklıktır: bir sinyal A noktasından B noktasına ne kadar uzağa taşınıyorsa o kadar fazla güç ve enerji gerekir. Hocanın aktardığına göre haberleşme protokollerinde gereken güç genellikle mesafenin karesiyle doğru orantılıdır.


## 3. Ön Plan ve Arka Plan Konum Erişimi

Android, konum erişimini iki kategoride ele alır: ön plan konumu (foreground location) ve arka plan konumu (background location) (ekrandan, 00:20:00). Birincisi uygulamanın etkin olarak kullanıldığı senaryodur. İkincisi uygulama kullanılmazken arka planda belirli aralıklarla konuma ihtiyaç duyulan durumdur.

### 3.1 Ön Plan Konumu

Slayttaki tanıma göre bir özellik konumu yalnız bir kez ya da belirli bir süre boyunca paylaşıyor veya alıyorsa ön plan konum erişimi gerekir. Slayttaki iki örnek şunlardır (ekrandan, 00:20:00):

- Navigasyon uygulamasında adım adım yol tarifi (turn-by-turn directions).
- Mesajlaşma uygulamasında anlık konumu başka bir kullanıcıyla paylaşmak.

Hoca navigasyon örneğini açtı: kullanıcı haritayı açıp bir yerden bir yere giderken uygulama belirli sıklıkla konum ister. Gelen konuma göre rotada değişiklik gerekip gerekmediğine, kullanıcının "100 metre sonra sağa dön", "sağdan devam et", "sola geç" gibi komutlarla uyarılıp uyarılmayacağına karar verilir. Bir sonraki dönüş noktası (milestone) güncellenir. Konumu mesajla bir arkadaşa göndermek için de ön plan konum izni alınmış olmalıdır.

Sistem, uygulamayı şu iki durumda ön plan konumu kullanıyor sayar (ekrandan, 00:20:00):

- Uygulamaya ait bir activity görünürdür.
- Uygulama bir foreground service çalıştırıyordur. Foreground service çalışırken sistem kalıcı bir bildirim gösterir. Uygulama arka plana geçse de (Home tuşu, ekranın kapanması) erişim sürer.

Hoca, foreground service'in geçen hafta anlatıldığını ve bildirim çubuğunda ya da çekmecede bir simgeyle gösterildiğini hatırlattı. Servis tanımlamak için manifestte `service` etiketi kullanılır. Slayttaki nota göre Android 10 (API 29) ve sonrasında foreground service türü olarak `location` bildirilmelidir.

### 3.2 Arka Plan Konumu ve Örnek Bir Arayüz

Hoca bir örnek uygulama ekranından söz etti. Bulunulan konumu göstermeye ve göndermeye yarayan özellik ön plan konum erişimi ister. "Recommend nearby places" (yakındaki yerleri öner) özelliği ise arka plan konum erişimi ister ve kullanıcının açılan ekranda bunu etkinleştirmesi gerekir. Bunun nedeni, yakındaki benzinlikleri, hastaneleri ve kafeleri sürekli önerebilmek için konumun sürekli alınması gerektiğidir; bu tek seferlik bir ön plan isteğiyle yapılamaz.

<!-- BELİRSİZ: Hocanın 00:23:32'de söz ettiği "uçurtma şeklindeki ikon" ve "Figür 2" bu slaytta; ilgili kare okunmadı, ikonun ne olduğu net değil. -->

## 4. Konum İzinleri

### 4.1 COARSE ve FINE

İki temel izin vardır:

- `ACCESS_COARSE_LOCATION`: yaklaşık (approximate) konum. İşletim sisteminden daha yüksek hata payıyla, düşük çözünürlüklü bir konum istendiğini bildirir.
- `ACCESS_FINE_LOCATION`: hassas (precise) konum. Mümkünse çok az hatayla, noktasal bir konum istendiğini bildirir.

Eskiden izinler uygulama kurulurken verilirdi. Artık kullanım sırasında seçenekler çıkar. Kullanıcı konumunu yalnız bu sefer mi ("Only this time"), uygulama kullanıldığı sürece mi ("While using the app") paylaşacağını seçer ya da "Deny" ile reddeder.

Slayttaki iki ekran şöyledir (ekrandan, 00:25:00):

- Figür 2: uygulama yalnız `ACCESS_COARSE_LOCATION` istediğinde çıkan pencere. "Allow My App to access this device's approximate location?" sorusu sorulur.
- Figür 3: uygulama tek bir çalışma zamanı isteğinde hem `ACCESS_FINE_LOCATION` hem `ACCESS_COARSE_LOCATION` istediğinde çıkan pencere. "Precise" ve "Approximate" seçenekleri birlikte gösterilir.

Hoca tablo üzerinden şunu vurguladı: kullanıcı "While using the app" ile hassas konum verecekse uygulama hem FINE hem COARSE iznini istemiş olmalıdır. FINE izni COARSE'u kapsamaz; ikisi birlikte istenir. Yalnız yaklaşık konum için COARSE izni yeterlidir.

> **Ek bilgi (derste anlatılmadı):** Bu kural büyük olasılıkla Android 12 (API 31) ile geldi: bu sürümü hedefleyen uygulama yalnız FINE isterse sistem isteği yok sayar. Kullanıcı hassas konum yerine yaklaşık konumu seçebildiği için uygulama yalnız COARSE izniyle de çalışabilecek şekilde yazılmalıdır.

### 4.2 Kademeli İzin İsteme

Android 11'den itibaren ön plan ve arka plan konumu sistem düzeyinde aynı anda istenirse sistem isteği geri çevirir. Hocanın yorumu şudur: bu tür bir ihtiyaç varsa en çok gereken izinden başlanmalı, "her şeyi istiyorum" demek yerine "önce buna ihtiyacım var, olmadıysa şuna" diye kademeli istek yapılmalıdır.

### 4.3 Arka Plan İzni ve Hatırlatıcı

Arka planda konum almak için ayrıca `ACCESS_BACKGROUND_LOCATION` izni gerekir. Android 10 ve sonrasında, arka planda uzun süreli konum kullanan bir uygulama için işletim sistemi bildirim ekranına bir hatırlatma düşürür: "Şu uygulama cihaz konumuna sürekli erişmek istedi, değiştirmek için dokunun." Böylece kullanıcı farkında olmadan arka plan veri toplamasına izin verdiği bir uygulamayı fark edip durdurabilir.

Eskiden böyle bir imkân yoktu. Bir kez izin verilince birçok uygulama arka planda sürekli konum isterdi ve pil hızla bittiğinde kullanıcı bu senaryoyu aklına bile getirmeyebilirdi. Hocaya göre bu hatırlatıcılar, işletim sistemlerinin pil tüketimini farkındalıkla azaltıp kullanıcı memnuniyetini artırmak için getirdiği çözümlerdir.

## 5. Google Play Services ve Son Bilinen Konum

### 5.1 Kütüphane Kurulumu

Android kendi konum API'lerini içerse de konum hizmetleri için Google Play Services'i kullanmayı öneriyor ve teşvik ediyor. Bu yüzden Google Play Services uygulamanın kütüphaneleri arasına eklenmelidir. Bu, Project Structure içinde uygulama modülüne `implementation` olarak bağımlılık eklenerek yapılır. Özellikle Fused Location Provider kullanılacaksa bu ayar şarttır.

Son bilinen konumu almanın adımları slaytta dört madde olarak verilir (ekrandan, 00:30:00):

- Google Play Services'i kurmak (Setup Google Play Services).
- Uygulama izinlerini belirtmek (Specify app permissions).
- Konum servisleri istemcisi oluşturmak (Create Location Services client).
- Son bilinen konumu almak (Get the Last Known Location).

### 5.2 Kod

Manifestte yaklaşık konum izni istenir (ekrandan, 00:30:00):

```xml
<manifest xmlns:android="http://schemas.android.com/apk/res/android"
    package="com.google.android.gms.location.sample.basiclocationsample" >

  <uses-permission android:name="android.permission.ACCESS_COARSE_LOCATION"/>
</manifest>
```

Activity içinde bir `FusedLocationProviderClient` alanı tanımlanır ve `onCreate` içinde `LocationServices.getFusedLocationProviderClient(this)` ile oluşturulur. Bu nesne Google Play Services'ten gelecek bilgiye köprü olur (ekrandan, 00:30:00):

```java
private FusedLocationProviderClient fusedLocationClient;

// ..

@Override
protected void onCreate(Bundle savedInstanceState) {
    // ...

    fusedLocationClient = LocationServices.getFusedLocationProviderClient(this);
}
```

Sonra `getLastLocation()` çağrılır ve sonuç bir `OnSuccessListener` içinde işlenir (ekrandan, 00:30:00):

```java
fusedLocationClient.getLastLocation()
        .addOnSuccessListener(this, new OnSuccessListener<Location>() {
            @Override
            public void onSuccess(Location location) {
                // Got last known location. In some rare situations this can be null.
                if (location != null) {
                    // Logic to handle location object
                }
            }
        });
```

`onSuccess` içinde konumla ne yapılacağı kodlanır: konumu birine göndermek, başka bir konuma rota çizdirmek gibi. `Location` nesnesinde genellikle enlem (latitude) ve boylam (longitude) bulunur. Bunlara ek olarak yükseklik (altitude) ve hız bilgisi de bu nesnede yer alır. Konum haritaya çizdirildiğinde kullanıcı simgeyi görüp nerede olduğunu anlar.

### 5.3 Konum ile Adres Farkı

Hoca konum ile adresi birbirinden ayırdı. Konum, enlem ve boylam bilgisiyle dünya haritası üzerinde fiziksel olarak bulunulan noktadır. Adres ise o konumla ilişkilendirilen ve insanların o yeri birbirine tarif etmek için kullandığı bilgidir. Bazen adresi konuma, bazen konumu adrese dönüştürmek gerekir; bu ayrı bir iştir.

### 5.4 Location Nesnesi Null Olabilir

Slayt, `Location` nesnesinin null dönebileceği durumları sayar (ekrandan, 00:35:00):

- Cihaz ayarlarında konum kapalıdır. Konumu kapatmak önbelleği de temizlediği için daha önce son konum alınmış olsa bile sonuç null olabilir.
- Cihaz konumunu hiç kaydetmemiştir. Yeni bir cihaz ya da fabrika ayarlarına döndürülmüş bir cihaz buna örnektir.
- Cihazdaki Google Play Services yeniden başlamıştır ve sonrasında konum isteyen aktif bir Fused Location Provider istemcisi yoktur. Bunu önlemek için yeni bir istemci oluşturup konum güncellemelerini kendiniz istersiniz.

Hoca, bu durumlara karşı kodun hazırlıklı olması gerektiğini, örneğin kullanıcıya hata mesajı gösterilmesini ya da yapılacak işlerin buna göre ayarlanmasını söyledi.

`getLastLocation()` bilinen son konumu verir; bu konum bir saat, on dakika ya da beş saat önce alınmış olabilir. Uçağa binmeden önce uçak moduna geçerken alınmış bir konum da olabilir. Bu yüzden konumun o anda işe yarayıp yaramayacağı değerlendirilmelidir. Slayta göre bunun için şunlar kontrol edilir (ekrandan, 00:35:00):

- Alınan konum, önceki konumdan anlamlı ölçüde daha yeni mi?
- Konumun bildirdiği doğruluk öncekinden daha iyi mi, daha kötü mü?
- Yeni konumu sağlayan kaynak (provider), önbellekteki konumun kaynağından daha güvenilir mi?

Sık konum kullanan uygulamalarda ise güncel konum, ileride görülecek `requestLocationUpdates` yöntemiyle sürekli istenebilir.

## 6. Pil Tüketimini Belirleyen Parametreler

Konum tabanlı servisler ciddi enerji tüketir ve bunu azaltmak için çeşitli pil optimizasyon teknikleri vardır. Örneğin arka planda toplanan konumların mümkün olduğunca az istenmesi için ayarlar vardır; hocanın aktardığına göre bu, saatte en fazla 3-5 kez konum alınması üzerine kuruludur. Hoca ayrıca cihaz bir Wi-Fi erişim noktasına bağlı kaldıkça konum güncellemesi yapılmaması yönünde bir tasarruf modundan ve dersin ikinci bölümünde ayrıntılandırılan geofence'lerden söz etti. Geofence'in büyüklüğü ve hangi olayın izlendiği, pilin ne kadar hızlı tükeneceğini belirler.

<!-- BELİRSİZ: Wi-Fi'ye bağlıyken konum güncellemesi yapılmayan "tasarruf modu" (00:36:57) altyazıda tek cümleyle geçiyor; ilgili slayt karesi okunmadı. -->

Pil tüketimini hızlandıran üç temel parametre vardır:

- **Doğruluk (accuracy):** ne kadar yüksek doğruluk istenirse o kadar fazla enerji tüketilir.
- **Sıklık (frequency):** konum ne kadar sık istenirse pil o hızda tükenir.
- **Gecikme (latency):** istenen konumun ne kadar gecikmeyle iletilebileceğine dair tolerans. Navigasyon uygulamasında gecikmeye tahammül yoktur. Güncelleme geç gelirse harita kullanıcıyı hâlâ gerideymiş gibi gösterir, kullanıcı dönüşü kaçırır ve yanlış rotaya girer. Bazı uygulamalarda ise gecikmenin önemi yoktur.

### 6.1 Doğruluk: setPriority

Doğruluk `setPriority()` ile dört değerden biri seçilerek ayarlanır (ekrandan, 00:40:00):

- `PRIORITY_HIGH_ACCURACY`: mümkün olan en doğru konumu verir. Gerektiği kadar çok girdi kullanır (GPS, Wi-Fi, hücresel ağ ve çeşitli sensörler) ve pili ciddi biçimde tüketebilir. Hoca, burada ağırlıklı olarak GPS kullanıldığını, ama yüksek doğruluk için Wi-Fi ve hücresel ağ bilgilerinin de katıldığı daha karmaşık bir hesaplama yapıldığını anlattı.
- `PRIORITY_BALANCED_POWER_ACCURACY`: gücü optimize ederek doğru konum verir. GPS'i çok nadiren kullanır; genellikle Wi-Fi ve hücresel bilgiyi birleştirir. Hocaya göre ödünleşimin (trade-off) en dengeli olduğu noktadır: ne doğruluktan çok vazgeçilir ne de yüksek enerji harcanır.
- `PRIORITY_LOW_POWER`: büyük ölçüde baz istasyonlarına dayanır, GPS ve Wi-Fi girdilerinden kaçınır. Şehir düzeyinde (city-level) kaba doğruluk verir, pil tüketimi çok azdır.
- `PRIORITY_NO_POWER`: konumu, başka uygulamaların zaten hesapladığı konumlardan pasif olarak alır. Hiçbir istek ya da hesaplama yapmaz. Kabaca bir konum yeterliyse ve kullanıcı çok yer değiştirmiyorsa tercih edilebilir.

Hoca LOW_POWER için olası bir itirazı cevapladı: "Wi-Fi daha az enerji tüketiyordu, neden baz istasyonu?" Cep telefonu, konuşulsun ya da konuşulmasın, gelen bir arama yönlendirilebilsin diye baz istasyonuyla sürekli haberleşir. Bu sinyal zaten geldiği için onu kullanmak ek enerji gerektirmez. Elde edilen şehir düzeyi doğruluk, örneğin hava durumu uygulaması için yeterlidir.

### 6.2 Sıklık: setInterval ve setFastestInterval

Sıklığı iki yöntem belirler (ekrandan, 01:00:00):

- `setInterval()`: konumun uygulama için hangi aralıkla hesaplanacağı, yani uygulamanın sistemden ne sıklıkla konum istediği.
- `setFastestInterval()`: başka uygulamalar için hesaplanan konumun bu uygulamaya hangi aralıkla iletileceği, yani uygulamanın gelen konumu en hızlı ne sıklıkla işleyebileceği.

Hocanın örneği: `setInterval` ile 10 saniyede bir konum isteniyor, `setFastestInterval` 5 saniye veriliyor. Başka bir uygulama sistemden daha sık konum istiyorsa, 5 saniyeye kadar olan sıklıktaki konumlar bu uygulamaya da aktarılır. 5 saniyeden daha sık gelen konumlar aktarılmaz, çünkü uygulama sisteme "en fazla 5 saniyede bir konum işleyebilirim" demiştir. Bu yüzden `setInterval` daha büyük, `setFastestInterval` daha küçük bir değer olmalıdır. Interval 10 saniye, fastest interval 20 saniye verilirse bunun bir anlamı olmaz ve hatalıdır. `setFastestInterval` kullanmak zorunlu değildir, ama `setInterval` ile istek sıklığı mutlaka belirtilmelidir.

### 6.3 Gecikme: setMaxWaitTime

Gecikme `setMaxWaitTime()` ile belirlenir. Gerçekten çok hızlı konum güncellemesi gerekmiyorsa gecikmesi çok az olan bir istekte bulunmak anlamlı değildir, çünkü daha fazla enerji tüketir.

> **Ek bilgi (derste anlatılmadı):** `setMaxWaitTime()` ile verilen süre, interval'dan büyükse sistem konumları toplu (batch) olarak, en geç bu süre dolunca iletebilir. Böylece cihaz daha seyrek uyanır ve pil tasarrufu sağlanır; karşılığında konumlar uygulamaya gecikmeli ulaşır.

## 7. Konum Kullanım Senaryoları

Hoca, farklı kullanım senaryolarında hangi seçeneğin mantıklı olduğunu tartıştı.

- **Harita (navigasyon) uygulaması:** konum çok sık ve düşük gecikmeyle istenmelidir. Mümkünse `PRIORITY_HIGH_ACCURACY` seçilir; enerji tüketimi konusunda hassasiyet varsa `PRIORITY_BALANCED_POWER_ACCURACY` seçilebilir. Uygulama sonlandığında konum takibi de mutlaka sonlandırılmalıdır.
- **Hava durumu uygulaması:** `getLastLocation()` ile bilinen en son konum istenmesi en uygun çözümdür.
- **Evden ya da iş yerinden ayrılmayı izlemek:** geofence kullanılmalıdır. Geofence belirli bölgeler tanımlar; bu bölgelere giriş, çıkış ve bölgede bulunma izlenir. Kullanıcının ev ve iş bölgesi bu açıdan önemlidir; bu olaylara göre örneğin bir mesaj gönderilebilir.
- **Kullanıcı etkinliğine göre güncelleme:** Activity Recognition API, kullanıcının araba mı sürdüğünü, bisiklete mi bindiğini, yürüdüğünü mü, sabit mi durduğunu anlamaya yardım eder. Kullanıcı hareket etmiyorsa konum isteği değiştirilebilir. Slayta göre güncellemeler yalnız hedef etkinlik (örneğin araç ya da bisiklet kullanımı) algılanınca istenir ve etkinlik bitince kaldırılır (ekrandan, 01:05:00).
- **Bir mağazaya yakınlık:** bir ürünü arıyorsanız, arka planda gidilen yerlerde ilgili mağaza olup olmadığı ve ürünün stokta olup olmadığı takip edilebilir. Bu geofence ile yapılır; slaytta `addGeofences(GeofencingRequest, PendingIntent)` yöntemi önerilir (ekrandan, 01:05:00). Geofence'e bağlanan pending intent ile bildirim üretilir.
- **Görünür bileşeni olmayan, uzun süreli arka plan takibi:** örneğin ailelerin küçük çocuklarını takip etmek için pasif olarak sürekli arka plan konumu alan uygulamalar. Slayta göre mümkünse pil tüketimi neredeyse hiç olmayan `PRIORITY_NO_POWER` kullanılmalı; bu mümkün değilse `PRIORITY_BALANCED_POWER_ACCURACY` ya da `PRIORITY_LOW_POWER` seçilmeli, `PRIORITY_HIGH_ACCURACY` ise sürekli arka plan işinde pili çok tükettiği için kullanılmamalıdır (ekrandan, 01:05:00). Hoca, böylece çocuğun birebir konumu değil ama okulda mı, arkadaşlarıyla mı olduğu gibi genel bir bilgi edinilebileceğini söyledi.

## 8. Sürekli Konum Güncellemesi

### 8.1 Başlatma, Durdurma ve Süre

Konum bilgisinde değişiklik izlemek için iki yol vardır. Sürekli konum güncellemesi `requestLocationUpdates` ile istenir; iş bitince `removeLocationUpdates` ile istek sonlandırılır. Takibin ne kadar süreceği, özellikle arka plan işlerinde, `setExpirationDuration` ve `setExpirationTime` ile belirlenir. Bu ayarlar bir `LocationRequest` nesnesi oluşturulduktan sonra o nesnenin yöntemleriyle yapılır.

### 8.2 Konum Ayarlarının Kontrolü

`getLastLocation()`'dan farklı olarak güncel konum almak için bazı ayarlar gerekir. Önce bir `LocationSettingsRequest.Builder` nesnesi oluşturulur ve `addLocationRequest` ile `LocationRequest` için tanımlanan ayarlar ona verilir. Sonra `LocationServices` üzerinden bir istemci (settings client) oluşturulur. Bu istemci üzerinden konum ayarlarının durumu alınır; sonuç `addOnSuccessListener` ve `addOnFailureListener` içinde işlenir.

Slayttaki örnekte bir yöntem içinde `LocationRequest` nesnesi oluşturulur ve `setInterval` ile `setFastestInterval` milisaniye cinsinden verilir. Hocanın anlatımına göre interval 10 saniye, fastest interval 5 saniyedir: "10 saniyede bir konum istiyorum; sen başka bir uygulama için daha sık konum alıyorsan bana da gönder, ama en fazla 5 saniyede bir işleyebilirim."

<!-- BELİRSİZ: 01:08:17'deki LocationRequest kod slaytının karesi okunmadı; 10 000 ve 5 000 ms değerleri hocanın anlatımından alındı. -->

### 8.3 requestLocationUpdates ve LocationCallback

`requestLocationUpdates`, `FusedLocationProviderClient`'ın bir yöntemidir ve konumun bir kez değil belirli sıklıkla istendiğini bildirir. `LocationRequest` ve `LocationCallback` nesnelerini alır. Callback, gönderilen `Location` nesnelerindeki bilgileri toplar.

Slayttaki callback tanımı (ekrandan, 01:10:00):

```java
private LocationCallback locationCallback;

// ...

@Override
protected void onCreate(Bundle savedInstanceState) {
    // ...

    locationCallback = new LocationCallback() {
        @Override
        public void onLocationResult(LocationResult locationResult) {
            if (locationResult == null) {
                return;
            }
            for (Location location : locationResult.getLocations()) {
                // Update UI with location data
                // ...
            }
        };
    };
}
```

Güncellemeler `onResume` içinde başlatılır (ekrandan, 01:10:00):

```java
@Override
protected void onResume() {
    super.onResume();
    if (requestingLocationUpdates) {
        startLocationUpdates();
    }
}

private void startLocationUpdates() {
    fusedLocationClient.requestLocationUpdates(locationRequest,
            locationCallback,
            null /* Looper */);
}
```

`onPause` içinde ise "artık konum almak istemiyorum" anlamında `removeLocationUpdates` çağrılır.

### 8.4 Durumun Saklanması

Hoca, dönemin başında görülen `Bundle` nesnesini ve `onSaveInstanceState` yöntemini hatırlattı. Konum güncelleme ayarlarının kaybolmaması için bu yöntemde son `requestingLocationUpdates` durumu bir boolean değer olarak saklanır. Activity geri döndüğünde bu durum okunur ve uygulama kaldığı yerden doğru biçimde devam eder. Ekran döndürme bu duruma örnektir.

## 9. Konum API'leri ve Arka Plan Erişimi

### 9.1 Üç API

Konuma erişmek için birkaç API vardır:

- Fused Location Provider API: ders boyunca anlatılan API.
- Geofencing API: biraz sonra anlatılan API.
- LocationManager API: en eski olanı.

> **Ders sonrası not:** Hoca 01:12:40'ta LocationManager API için de, Fused Location Provider API için de Google Play Services'e ihtiyaç duyulduğunu söyledi (altyazı burada bozuk olabilir). Doğrusu büyük olasılıkla şudur: LocationManager Android çatısının (`android.location`) parçasıdır ve Google Play Services gerektirmez; Fused Location Provider ve Geofencing API ise Google Play Services'in konum kütüphanesiyle gelir.

Bu yapılar, konum değiştiğinde ya da belirli bir yere gelindiğinde devreye girerek arka planda konum takibi ve konuma bağlı iş yapmak için kullanılır.

### 9.2 Arka Plan Konumunda Dikkat Edilecekler

Hoca arka plan konum erişimi için en önemli hususları şöyle sıraladı:

- Arka plan konum erişimi yalnız uygulama için gerçekten kritikse kullanılmalı, değilse devre dışı bırakılmalıdır.
- Android 10 ve sonrasında `ACCESS_BACKGROUND_LOCATION` izni mutlaka alınmalıdır.
- Kullanıcı, arka plan takibinin sürdüğü konusunda bilgilendirilmelidir.
- Android 8 ve sonrasında arka planda saatte yalnız birkaç (3-4) güncelleme gelir. Uygulama, her dakika güncelleme almadığını bilerek tasarlanmalıdır.

## 10. Geofence (Sanal Bölge)

### 10.1 Tanım

Hoca sınıfa geofence'i daha önce duyan olup olmadığını sordu; kimse duymamıştı. Geofence'ler, kullanıcının belirli bir yerde olup olmadığını ya da o yere girip çıkıp çıkmadığını izlemek için oluşturulan sanal bölgelerdir. Bu bölgelere giriş-çıkışlar ve orada geçirilen süreler yorumlanarak kullanıcının hayatındaki bazı işler kolaylaştırılır.

Bir geofence'in bir merkezi ve bu merkezin çevresinde bir yarıçapı vardır. Tanımda üç bilgi kullanılır: enlem (latitude), boylam (longitude) ve yarıçap (radius). Böylece dairesel bir alan oluşur ve bu alan ilgi duyulan, izlenen bölge olarak işaretlenir. Slayttaki tanıma göre geofencing, kullanıcının güncel konumunun farkındalığını ilgi çekici yerlere yakınlığının farkındalığıyla birleştirir (ekrandan, 01:15:00).

Bölgede üç olay izlenir (ekrandan, 01:15:00):

- ENTER: bölgeye giriş.
- EXIT: bölgeden çıkış.
- DWELL: bölgede bulunma, kalma.

Geofence izlemek için `ACCESS_BACKGROUND_LOCATION` izni gerekir; Android 10 ve sonrasında bu zorunludur.

### 10.2 Geofence Oluşturma

Fused Location Provider'daki istemci gibi burada da bir `GeofencingClient` tanımlanır ve `LocationServices.getGeofencingClient()` ile oluşturulur. Ardından belirlenen bölgeler bir listeye eklenir (ekrandan, 01:20:00):

```java
geofenceList.add(new Geofence.Builder()
    // Set the request ID of the geofence. This is a string to identify this
    // geofence.
    .setRequestId(entry.getKey())

    .setCircularRegion(
            entry.getValue().latitude,
            entry.getValue().longitude,
            Constants.GEOFENCE_RADIUS_IN_METERS
    )
    .setExpirationDuration(Constants.GEOFENCE_EXPIRATION_IN_MILLISECONDS)
    .setTransitionTypes(Geofence.GEOFENCE_TRANSITION_ENTER |
            Geofence.GEOFENCE_TRANSITION_EXIT)
    .build());
```

- `setCircularRegion` enlem, boylam ve yarıçapı alır. Örnekte yarıçap `Constants` sınıfındaki hazır bir sabitten gelir.
- `setExpirationDuration` geofence'in ne kadar süre hizmet edeceğini belirler.
- `setTransitionTypes` neyin izleneceğini belirler: bölgede kalma, bölgeye giriş anı ya da bölgeden çıkış anı.

> **Hocanın vurgusu:** Yüksek enerji tüketilmesi istenmiyorsa geofence yarıçapı en az 100 metre olmalıdır. 10 ya da 50 metrelik bölgeler sürekli giriş, çıkış ve kalma takibine yol açar ve çok enerji tüketir. Bölgenin bir kilometre olması gerekmez, ama konumun hatalı hesaplanmasından doğan sahte giriş-çıkışları izlememek için 100 metrenin altına inilmemelidir.

Bir uygulamada tanımlanabilecek geofence sayısının sınırı, kullanıcı başına 100 mertebesindedir. Bir kişi için onlarca geofence tanımlamak normalde beklenen bir şey değildir, ama bu sınırın varlığı ve her geofence'in ek takip ve enerji gerektirdiği bilinmelidir. Bu yüzden kurallara uygun sanal bölgeler tanımlanmalıdır.

### 10.3 GeofencingRequest ve PendingIntent

`LocationRequest`'te olduğu gibi `GeofencingRequest` de bir builder ile oluşturulur. Biraz önce tanımlanan geofence listesi bu builder'a eklenir ve sistem bu sanal bölgeleri izlemeye başlar.

Olaylar gerçekleştiğinde ne yapılacağını belirtmek için bir `PendingIntent` oluşturulur. Bu, işlerin bir Broadcast Receiver üzerinden düzenlenmesi demektir: bölgeye giriş, çıkış ya da kalma tetiklendiğinde yapılacak iş tanımlanmış olur. Geofence ekleme işleminin sonucu da `Location` nesnelerinde olduğu gibi `addOnSuccessListener` ve `addOnFailureListener` ile izlenir.

Geofence Broadcast Receiver'da geçiş türü (geofence transition) geofencing olayından alınır, izlenen olay olup olmadığı kontrol edilir ve gerekiyorsa bildirim gönderilir (slayttaki örnekte `sendNotification`). `removeGeofences` yöntemiyle geofence'lerin izlenmesi durdurulur ya da listeden çıkarılır.

### 10.4 Geofence'lerin Yeniden Kaydedilmesi

Geofence'ler kaydedildikten sonra bazı durumlarda yeniden kaydedilmeleri gerekir. Hoca bunları sorumluluğa göre ikiye ayırdı:

- **Sistemin kendiliğinden hallettiği durumlar:** Google Play Services'in güncellenmesi, durdurulup yeniden başlaması ya da konum sürecinin çökmesi. Sistem bu durumlarda geofence'leri otomatik olarak yeniden kaydeder.
- **Uygulamanın halletmesi gereken durumlar:** cihazın yeniden başlatılması, uygulamanın kaldırılıp yeniden kurulması, uygulama verisinin silinmesi, Google Play Services verisinin silinmesi. Bu durumlarda sistem geofence'leri kurtarmaz; kod bunları yeniden kaydetmelidir.

### 10.5 Giriş Olayındaki Sorunlar

Slayt, geofence giriş olayıyla ilgili sorunları ve nedenlerini sayar (ekrandan, 01:25:00):

- **Geofence içinde doğru konum yok ya da geofence çok küçük.** Çoğu cihazda geofence servisi tetikleme için yalnız ağ konumunu kullanır, çünkü ağ konumu çok daha az güç harcar, daha hızlı sonuç verir ve en önemlisi kapalı alanlarda da çalışır.
- **Cihazda Wi-Fi kapalı.** Wi-Fi açıkken konum doğruluğu belirgin biçimde artar. Wi-Fi kapalıysa yarıçapa, cihaz modeline ya da Android sürümüne bağlı olarak uygulama hiç geofence uyarısı almayabilir. Android 4.3 (API 18) ile gelen "Wi-Fi scan only mode", Wi-Fi kapalıyken de iyi ağ konumu almayı sağlar. Wi-Fi ve tarama modu ikisi de kapalıysa kullanıcıyı uyarmak ve bir kısayol sunmak iyi bir uygulamadır; ayarlar `SettingsClient` ile kontrol edilir.
- **Geofence içinde güvenilir ağ bağlantısı yok.** Geofence servisi ağ konum sağlayıcısına, o da veri bağlantısına dayandığı için uyarılar üretilmeyebilir.
- **Uyarılar gecikebilir.** Servis konumu sürekli sorgulamaz. Gecikme genellikle 2 dakikadan azdır, cihaz hareket hâlindeyse daha da azdır. Arka plan konum sınırları etkinse ortalama 2-3 dakikadır. Cihaz uzun süre hareketsiz kaldıysa 6 dakikaya kadar çıkabilir.

Hoca, uyarıların geç üretilebileceğinin tasarımda hesaba katılması gerektiğini, kullanıcının bölgeden çıktığı anda bir mesajın ya da bilgilendirmenin gelmeyebileceğini vurguladı. Ağ bağlantısının kontrol edilmesi ve geofence takibinin gerçekten yapılıp yapılmadığının denetlenmesi gerekir.

## 11. Uygulama: MapActivity ile Konum ve Harita

### 11.1 Uygulamanın Çalışması

Dersin son bölümünde hoca küçük bir uygulama gösterdi. Uygulama açıldığında giriş ekranından sonra haritaya yönlenir ve konum bilgisini gösterir. Hoca ilk denemede, telefonda daha önce konum alan bir uygulama olmadığı için `getLastLocation()`'ın Türkiye'nin başka bir noktasını gösterdiğini anlattı; telefon o güne kadar bir baz istasyonuna bağlanmamış, telefona SIM kart takılmamıştı. Kodu güncel konumu alacak şekilde değiştirip çalıştırdıktan sonra son bilinen konum da üniversitenin konumu oldu. Haritayı yakınlaştırma (zoom) ayrıntıları bir sonraki derse bırakıldı.

### 11.2 Bağımlılıklar

Kodun başında Google Play Services üzerinden içe aktarılması gereken kütüphaneler vardır: `LocationServices`, `FusedLocationProviderClient`, Google Map sınıfları. Android Studio'da Project Structure açıldığında SDK konumu ve Gradle sürümü gibi bilgiler görülür. Dependencies bölümünde artı işaretiyle iki `implementation` eklenir: Play Services Location ve Play Services Maps.

### 11.3 Activity'nin Yapısı

`MapActivity` (adı başka da olabilir) bir fragment üzerinden `OnMapReadyCallback` arayüzünü uygulayacak biçimde yazılmıştır. Konumla ilgili alanlar şunlardır: bir `Location currentLocation`, bir `FusedLocationProviderClient`, bir `LocationRequest` ve bir `LocationCallback`.

`onCreate` içinde standart `setContentView` yapılır, `LocationServices` üzerinden provider client oluşturulur ve özel tanımlanmış `fetchLocation()` fonksiyonu çağrılır. Bu fonksiyon önce manifestteki COARSE ve FINE izinlerinin verilip verilmediğini kontrol eder; verilmemişse hata üretmemek için geri döner. İzin sonucu `onRequestPermissionsResult` içinde ele alınır: istek kodu eşleşiyor ve `grantResults[0] == PackageManager.PERMISSION_GRANTED` ise `fetchLocation()` yeniden çağrılır (ekrandan, 01:50:00).

### 11.4 Son Bilinen Konumla Harita

İlk sürümde istemcinin `getLastLocation()` yöntemiyle uygulamadaki bilinen en son konum alınır (ekrandan, 01:50:00):

```java
Task<Location> task = fusedLocationProviderClient.getLastLocation();
task.addOnSuccessListener(new OnSuccessListener<Location>() {
    @Override
    public void onSuccess(Location location) {
        if (location != null) {
            currentLocation = location;
            Toast.makeText(getApplicationContext(), currentLocation.getLatitude() + "" + currentLocation.getLongitude(), Toast.LENGTH_SHORT).show();
            SupportMapFragment supportMapFragment = (SupportMapFragment) getSupportFragmentManager().findFragmentById(R.id.myMap);
            assert supportMapFragment != null;
            supportMapFragment.getMapAsync(MapActivity.this);
        }
    }
});
```

`Location` null değilse `currentLocation` alanına atanır (hocaya göre bu atama zorunlu değil). Enlem ve boylam Toast ile ekrana yazdırılır, sonra harita fragment'ı için `getMapAsync` çağrılır. Uygulama çalışınca Toast'ta enlem ve boylamın arada ayraç olmadan yan yana yazıldığı görülür (ekrandan, 02:00:00), çünkü iki sayı arasına boş bir dize (`""`) eklenmiştir.

Harita hazır olunca `onMapReady` çalışır (ekrandan, 01:50:00):

```java
@Override
public void onMapReady(GoogleMap googleMap) {
    LatLng latLng = new LatLng(currentLocation.getLatitude(), currentLocation.getLongitude());
    MarkerOptions markerOptions = new MarkerOptions().position(latLng).title("I am here!");
    googleMap.animateCamera(CameraUpdateFactory.newLatLng(latLng));
    googleMap.animateCamera(CameraUpdateFactory.newLatLngZoom(latLng, 5));
    googleMap.addMarker(markerOptions);
}
```

Enlem ve boylamdan bir `LatLng` nesnesi oluşturulur ve `MarkerOptions` nesnesinin `position` yöntemine verilir. Sonra kameranın nereye konumlanacağına ve hangi zoom seviyesinde olacağına karar verilir: haritaya en tepeden mi bakılacak, yoksa yakına mı inilecek. Zoom 5 olduğu için ilk açılışta Türkiye'yi içine alan bir görünüm oluşur. `addMarker` ile işaret (marker) haritaya konur.

Harita için layout'ta yalnız bir map fragment tanımlanır; ekranın tamamı haritadan oluşur.

### 11.5 Harita API Anahtarı

Haritada iş yapmak için bir harita anahtarı (API key) gerekir. Google Maps konsoluna Google hesabıyla girilir, anahtarın hangi amaçla kullanılacağı belirtilir ve haritayla ilgili bir API anahtarı üretilir. Bu anahtar genellikle `strings.xml` içine konur ve manifestte referans verilir (ekrandan, 01:55:00):

```xml
<meta-data android:name="com.google.android.geo.API_KEY" android:value="@string/map_key"/>
```

**Soru:** API anahtarı manifestte mi, `strings.xml`'de mi tanımlanmalı? **Cevap:** İki yerde de tanımlanabilir; doğrudan manifeste yazmak da mümkündür. Ancak anahtarı koda gömmemek (hard-coded yazmamak) ve parametrik yapmak için `strings.xml`'e yazıp manifestten referans vermek önerilir ve yaygındır. Manifestteki bu satır, uygulamanın Google Play Services'in harita hizmetine hangi API anahtarıyla kaydolduğunu bildirir; değer `strings.xml`'den okunur.

### 11.6 Sürekli Güncellemeyle Harita

Hoca daha sonra `getLastLocation()` bölümünü yorum satırına alıp üstteki bölümü açtı. Bu sürümde son bilinen konum alınmaz; sürekli güncelleme istenir ve güncel konum haritada gösterilir.

- `LocationRequest` nesnesi oluşturulur, önceliği yüksek doğruluk olarak verilir.
- `setInterval` ile 20 saniyede bir güncelleme istenir.
- `LocationCallback` tanımlanır: sonuç null ise hiçbir şey yapmadan dönülür; değilse `locationResult.getLocations()` üzerinden `Location` nesnesi alınır, enlem ve boylam değişkenlere atanır ve konum haritada gösterilir.
- Son olarak `requestLocationUpdates` çağrılır (ekrandan, 01:50:00, yorum satırındaki bölüm):

```java
fusedLocationProviderClient.requestLocationUpdates(locationRequest,
        locationCallback,
        Looper.getMainLooper());
```

Bu çağrı sisteme şunu söyler: "`LocationRequest` nesnesine tanımladığım ayarlara uygun olarak konumu tekrar tekrar istiyorum; gelen konumları bu callback üzerinden alacağım." Hoca bazı yöntemlerin kullanımdan kalktığı (deprecated) için Android Studio'da üstlerinin çizili göründüğünü, ama kullanımda sorun olmadığını belirtti.

Uygulama yeniden çalıştırıldığında hoca haritayı elle yakınlaştırdı; yaklaşık 20 saniye sonra callback'ten gelen bilgiyle harita yeniden zoom 5'e, yani ülke ölçeğine döndü. Hoca zoom seviyesini 7'ye çıkarınca harita diğer ülkeleri dışarıda bırakıp bölge ölçeğine, 12'ye çıkarınca şehrin de altına inip ilçe ölçeğine geldi. Her 20 saniyelik güncellemede harita yeniden bu konuma odaklanır.

### 11.7 Dönem Projesiyle Bağlantı

Hoca dönem projesindeki harita maddesini hatırlattı: harita üzerinde arama ve seçim yapma, kullanıcının güncel konumunu periyodik olarak tutma (ekrandan, 02:05:00). Konuyla ilgili önerdiği alıştırma şudur: bir ekranda bir buton oluşturulur; butona basılınca mevcut konum alınır ve kaydedilir. Hoca konumun adrese dönüştürülmesini göstermedi; bunun kolayca bulunabileceğini söyledi. Bir sonraki adımda bu konuma yakın evlerin ya da ev arkadaşı adaylarının gösterilmesi beklenir.

> **Ek bilgi (derste anlatılmadı):** Android'de konumdan adrese ve adresten konuma dönüşüm `android.location.Geocoder` sınıfıyla yapılır: `getFromLocation(lat, lng, maxResults)` adres listesi, `getFromLocationName(adres, maxResults)` konum listesi döndürür. Bu işlem ağ gerektirebilir, bu yüzden ana thread dışında çalıştırılmalıdır.

## Örnek Sorular

**Soru 1** (derste sözlü, 00:10:25): Bir uygulama konum bilgisine ihtiyaç duyduğunda telefon hangi bileşenleri ve kaynakları kullanabilir? Enerji tüketimi açısından nasıl sıralanırlar?

> **Cevap (derste verildi):** GPS (uydu sinyalleriyle üçgenleme; normal şartlarda en hassas), baz istasyonları ve Wi-Fi erişim noktaları (konumları bilindiği için şehir merkezlerinde doğru, kırsalda hata payı yüksek) ve başka bir uygulamanın daha önce aldığı son bilinen konum. Hocanın sıralamasına göre en çok enerjiyi GPS, sonra baz istasyonu, sonra Wi-Fi harcar; son bilinen konum neredeyse hiç enerji harcamaz. Sebep, sinyalin taşındığı mesafedir.

**Soru 2** (derste sözlü, 01:01:30): Aşağıdaki uygulamalar için hangi konum yöntemi ya da ayarı uygundur? (a) navigasyon/harita uygulaması, (b) hava durumu uygulaması, (c) kullanıcının evden ya da iş yerinden ayrılıp ayrılmadığını izlemek, (d) görünür bileşeni olmadan, pasif olarak sürekli konum takibi yapan bir uygulama.

> **Cevap (derste verildi):** (a) Sık güncelleme ve düşük gecikme: `requestLocationUpdates` ile `PRIORITY_HIGH_ACCURACY`, enerji önemliyse `PRIORITY_BALANCED_POWER_ACCURACY`; uygulama kapanınca takip sonlandırılır. (b) `getLastLocation()` ile bilinen son konum. (c) Ev ve iş yeri için geofence; giriş ve çıkış olayları izlenir. (d) Mümkünse `PRIORITY_NO_POWER`; olmuyorsa `PRIORITY_BALANCED_POWER_ACCURACY` ya da `PRIORITY_LOW_POWER`; `PRIORITY_HIGH_ACCURACY` kullanılmaz (ekrandan, 01:05:00).

## Dersin Toparlaması

Bu derste konum bilgisinin mobil uygulamalardaki yeri ve maliyeti ele alındı. Konum GPS, baz istasyonları, Wi-Fi erişim noktaları ya da başka uygulamaların aldığı son konumdan gelebilir. Her kaynağın doğruluğu ve pil maliyeti farklıdır. Android konum erişimini ön plan ve arka plan diye ayırır. COARSE, FINE ve BACKGROUND izinleri kullanım sırasında ve kademeli olarak istenir. Fused Location Provider ile `getLastLocation()` hızlı ve ucuz bir son konum verir, ama sonuç null ya da eski olabilir. Sürekli konum için `LocationRequest` (öncelik, interval, fastest interval, max wait time), `LocationCallback` ve `requestLocationUpdates`/`removeLocationUpdates` kullanılır. Geofence'ler enlem, boylam ve yarıçapla tanımlanan bölgelere giriş, çıkış ve kalma olaylarını PendingIntent ve Broadcast Receiver üzerinden bildirir. En az 100 metrelik yarıçap, yeniden kaydetme gereken durumlar ve uyarı gecikmeleri tasarımda hesaba katılmalıdır.

Uygulama bölümünde `MapActivity` ile önce son bilinen konum, sonra 20 saniyede bir güncellenen konum haritada marker ile gösterildi; harita için API anahtarının `strings.xml` ve manifest üzerinden tanımlandığı görüldü. Hoca bir sonraki derste haritalar konusunun, zoom ve kamera ayarlarının ayrıntılı işleneceğini söyledi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
