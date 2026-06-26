# Ders 14 Çalışma Özeti

## Genel Konular

- Ders genel değerlendirmesi ve final sınavı bilgilendirmesi
  - Hoca, son haftada olduklarını, derse katılan arkadaşlara teşekkür ettiğini, umarım bir şeyler katabilmiştir dediğini belirtmiştir.
  - Yaklaşık 20 kişinin anketi doldurduğu, 85 kişilik sınıftan 20 kişinin ankete katıldığı bilgisi verilmiştir.
  - Farklı görüşler olduğu, kodlama noktasında daha aktif kodlama isteyenler, birebir yazılmasını tercih edenler, daha fazla örnek görmek isteyenler olduğu paylaşılmıştır.
  - Konuların çok yoğun olduğu, ileri seviye dersin açılması gerektiğini talep edenler olduğu belirtilmiştir.
  - Ders dışı performans harcamanın fazla olduğu geri bildirimi alındığı, Java'da yazılan küçük bir metotla çok iş yapılabilse de event driven programlarının listener'ları nedeniyle çok kod yazılması gerektiği açıklanmıştır.

- Sınav formatı
  - Kod yazdırmanın sınav sırasında zor olduğu, öğrencilerin de çok tercih etmediği.
  - Final sınavının vize benzeri olacağı: boşluk doldurma, test veya klasik sınava yakın olmayacak (dersin ruhuna aykırı).
  - Sınavın %20-25'lik kısmının daha ayırt edici sorular olacağı belirtilmiştir.
  - Sınava hazırlanmak için en basit ve kolay adres developer.android.com olarak belirtilmiştir.
  - Slide'lar paylaşılacak, üzerinden geçilmesi önerilmiştir.

- Dönem ödevi değerlendirme hatırlatması
  - Dönem projesinin daha derin bir değerlendirme gerektirdiği, kontrolünün daha uzun süreceği.
  - Teslim edilen ödevlerde hiç ses kullanmadan gösteren arkadaşlar olduğu, projenin anlatılması gerektiği.
  - Drive'a yüklenen videoların bir kısmının açılmadığı, YouTube linki göndermenin daha risksiz olduğu.
  - İkinci ödev açıklandığında sıkıntı olanların paylaşılabileceği.

- Konum tabanlı servisler (Location-based services)
  - Lokasyon bilgisini kullanan uygulama sayısının yıllar içinde çok arttığı.
  - Ebeveynlerin çocuklarını takip etmesi, araçla seyahat, akıllı saat kullanımı gibi senaryolar.
  - Telefonun adres bilgisi sağlama kalitesinin önemi.

- Adres bilgisi temin yöntemleri
  - GPS (Global Positioning System): en yüksek doğruluk; GPS (Amerika), Glonass (Rusya), Beidou (Çin), Hindistan sistemi.
  - Baz istasyonları: telefonlar üzerinden konum bilgisi.
  - Wi-Fi access point'ler: her birinin sabit IP'si var, lokasyonları belli.
  - Diğer uygulamanın almış olduğu konum: düşük enerji modunda veya no power modunda, başka uygulamanın 5 saniye önce aldığı konum kullanılır.

- Üçgensel hesaplama (Triangulation)
  - Baz istasyonu ve access point duruma göre uzak noktalarda bulunabilir.
  - Lokasyon bilgisinin doğruluğu/hassasiyeti: nokta + çember; çemberin büyüklüğü hassasiyetin düşüklüğünü gösterir.
  - Yüksek hassasiyet için GPS veya yakın bölgede birden fazla baz istasyonu/access point gerekir.
  - Üçgensel yaklaşımla gelen sinyallerin kuvvetine bağlı hesaplama yapılır.

- Android lokasyon türleri
  - Foreground location: anlık veya geçici periyot için (navigasyon, anlık konum paylaşımı).
  - Background location: sürekli kişi takibi, geofencing API.
  - Android 10 ve 11 arasında farklılıklar var; biri require, diğeri recommend ediyor.
  - 8 ile başlayan, 9'da belirginleşen, 10 ve 11'de net ayrımlar.

- Lokasyon izin türleri
  - COARSE_LOCATION: kabaca bilgi (şehir düzeyi).
  - FINE_LOCATION: kesin bilgi (sokak düzeyi).
  - Manifestte ACCESS_FINE_LOCATION, ACCESS_COARSE_LOCATION tanımlanmalı.
  - Android 10+ için ACCESS_BACKGROUND_LOCATION manifestte ayrıca tanımlanmalı.
  - API 29+ sonrası foreground service tipi manifestte belirtilmeli.

- Foreground vs Background location kullanım senaryoları
  - Foreground: navigasyon, anlık konum paylaşımı (WhatsApp'ta konum gönderme), bir yerden bir yere giderken bilgi.
  - Background: sürekli çocuk takibi, IoT (evden çıkınca ışık kontrolü), geofencing (belirli bölgeye giriş/çıkış).

- Geofencing
  - Coğrafi fence: yarıçapı ve merkezi belirlenen bölge.
  - 100 metreden 1-5 kilometreye kadar değişen büyüklükler.
  - Bölgeye giriş/çıkış/içeride kalma takibi.
  - Reminder'lar bölge bazlı tetiklenebilir (zamansal değil, mekansal).

- Run-time lokasyon izinleri
  - Manifest yerine runtime sırasında izin alma (checkSelfPermission).
  - Allow once, Allow while using the app, Deny seçenekleri.
  - Önce foreground location talep edilir, gerçekten gerekirse background location talep edilir.
  - Sadece current location için background access talep edilmemelidir.

- Konum bilgisi sağlama yöntemleri
  - Eski: LocationManager (artık çok kullanılmıyor).
  - Yeni: Google Play Services üzerinden FusedLocationProviderClient sınıfı.
  - SDK içerisinden Google Play Services'ın geliştirme ortamına yüklenmesi gerekir.
  - onCreate'de fusedLocationProviderClient değişkeni, locationServices.getFusedLocationProviderClient çağrısı.
  - getLastLocation ile en son bilgi talep edilir.
  - onSuccess (bilgi varsa) ve onFailure listener'ları.

- Konum verisinin geçerliliği
  - GetLastLocation metoduyla alınan bilgi hatalı olabilir (eski bilgi olabilir).
  - Lokasyon bilgisinin ne kadar yeni olduğu (saat kontrolü) önemli.
  - Üretilen bilgilerin uyumluluğu (kısa sürede bambaşka yer gösteriliyorsa hata var).
  - Hız bilinen, üretilen veriler belli; ilişki kontrol edilip ön işlemden geçirilmeli.

- Konum verisi alınamama durumları
  - Sensörde donanımsal arıza.
  - Telefonun çekmemesi (airplane modda veya GPS kapalı).
  - Wi-Fi veya baz istasyonuna bağlantı olmaması.
  - Uydu bağlantısı için fiziksel/hava şartlarının uygun olmaması.
  - Yeni cihaz (ilk kez açıldığında lokasyon bilgisi yok).
  - Google Play Services yüklenmemiş/yeniden başlatılmış.
  - FusedLocationProviderClient oluşturulmamış veya eski provider'ın hafızada asılı kalması.

- Doğru adres üretme ve batarya optimizasyonu
  - Konum bilgisinde iki kriter: doğru adres üretme, batarya optimizasyonu.
  - Android 8'den itibaren background'lar için yeni kurallar.
  - Background location talebinde bulunulsa bile, gelen restrictionlardan dolayı saatte 1-2-3-4 taneye düşebilir.
  - Wi-Fi üzerinden veri alındığında, aynı Wi-Fi'ye bağlı kalındığı sürece ekstra enerji harcanmaz.
  - Geofence'de bölgeden çıkıp çıkmadığınız saniyede bir kontrol edilir; 10 saniye-2 dakika gecikme olabilir.
  - Aralık ne kadar açık olursa batarya performansı o kadar yüksek olur.

- Batarya tüketimini etkileyen üç parametre
  - Accuracy (doğruluk): setPriority üzerinden ayarlanır.
    - HIGH_ACCURACY: tüm seçenekler devrede, en yüksek hassasiyet, en fazla enerji tüketimi.
    - BALANCED_POWER_ACCURACY: GPS'ten çok Wi-Fi veya baz istasyonlarından, güç tüketimi dengelenmiş, en sık kullanılan.
    - LOW_POWER: minimum pil tüketimi, genelde baz istasyonu sinyalleri, doğruluk garantisi yok.
    - NO_POWER: mevcut başka uygulama lokasyon üretiyorsa onun verisine bağlı; üretmiyorsa bilgi gelmez.
  - Frequency (sıklık): saniye mertebesinde, setInterval ile belirlenir.
  - Latency (gecikme): bilginin ne gecikmeyle ulaşacağı.

- setInterval ve setFastestInterval
  - setInterval: talep sıklığı (örneğin 10 saniye).
  - setFastestInterval: eğer işleme süresi talep sıklığından kısa ise, en hızlı bilgi talep edilir.
  - Standart 10 saniye ama belli anlarda 5 saniye gerekirse, setFastestInterval 5 saniye yapılabilir.

## Hocanın Özellikle Vurguladığı Kısımlar

- Sınavda temel bilgilerin sorulacağı, çok ayrıntıya kaçılmayacağı
  - "Çok kıydaki öste kalmış bir bilgi sorma taraftarı değilim, temel bilgiden soracağım" ifadesi.
  - Developer.android.com'un en güncel ve güvenilir kaynak olduğu vurgusu.

- Dönem projesi tesliminde dikkat edilmesi gerekenler
  - Projeyi anlatmak için ses kullanılması gerektiği; sessiz anlatım kabul edilmediği.
  - YouTube linkinin drive'a göre daha risksiz olduğu; videonun açılmaması durumunda not kaybı olacağı.

- Background location talep etmeden önce foreground location talep edilmesi
  - "Sadece current location için, o anda bulunduğunuz lokasyonu görmek için background aksesi kesinlikle talep etmemelisiniz" ifadesiyle gereksiz background talebinin önlenmesi.
  - Android'in background location talep etmeyi çok istemediği, çünkü gereksiz enerji tüketimi ve sürekli kişi takibi anlamına geldiği.

- Konum verisinin doğruluğunun kontrol edilmesi
  - GetLastLocation metoduyla alınan bilginin hatalı olabileceği, lokasyon bilgisinin ne kadar yeni olduğunun kontrol edilmesi gerektiği.
  - Kısa sürede bambaşka bir yeri göstermesinin hata işareti olduğu, hız/veri ilişkisinin kontrol edilip ön işlemden geçirilmesi gerektiği.

- Doğru zamanda doğru doğruluk seviyesinin seçilmesi
  - "Daha iyisini her zaman isterim" yaklaşımının sıkıntısı: gereksiz yere hassas bilgi talep etmek daha çok enerji harcamayı gerektirir.
  - Hava durumu uygulaması için COARSE_LOCATION yeterli, navigasyon için FINE_LOCATION gerekir.

- Wi-Fi'nin şehir yaşamında akıllıca kullanımı
  - Baz istasyonu ve Wi-Fi access point kullanmak akıllıca çünkü daha az enerji tüketir.
  - Kırsal yaşamda bu yöntemler yetersiz kalabilir; GPS gerekebilir.

## Kısa Tekrar Notları

- Ders 1-13 tüm konular final sınavında sorulabilir.
- Lokasyon sağlama yöntemleri: GPS, baz istasyonu, Wi-Fi, başka uygulama.
- COARSE_LOCATION (şehir) vs FINE_LOCATION (sokak).
- Foreground location: anlık; background location: sürekli.
- Geofencing: bölge giriş/çıkış takibi, 100m-5km.
- Android 10+ background location ayrı izin.
- FusedLocationProviderClient: Google Play Services üzerinden.
- getLastLocation + onSuccess/onFailure listener.
- Konum verisi doğruluğu kontrol edilmeli (saat, uyumluluk).
- 4 doğruluk seviyesi: HIGH_ACCURACY, BALANCED_POWER_ACCURACY, LOW_POWER, NO_POWER.
- setInterval + setFastestInterval.

## Detaylı Açıklamalar

Dersin başlangıcında hoca, son haftada olduklarını, senenin tamamlanmak üzere olduğunu, derse katılan arkadaşlara teşekkür ettiğini belirtmiştir. Umduğu şeyleri katabilmiş olmayı dilemiştir. Anket göndermişti, yaklaşık 20 kişinin yorumu eline ulaşmıştı. 85 kişilik sınıftan 20 kişinin anketi doldurması orantılı bir katılım olarak değerlendirilmiştir. 20 kişi arasında farklı görüşler olduğu, birbirinden tamamen zıt görüşler de olduğu belirtilmiştir. Herkesin kendince eleştirdiği ve teşekkür ettiği bir nokta olduğu paylaşılmıştır. Özellikle kodlama noktasında daha aktif kodlama isteyenler, birebir yazılmasını tercih edenler, daha fazla örnek görmek isteyenler olduğu belirtilmiştir. Ancak konuların çok yoğun olduğu, dersin ileri seviyesinin açılması gerektiğini talep edenler olduğu söylenmiştir. Ders dışı faaliyetin biraz fazla olduğu, anlatılan konuların pratikte gerçeklenmesi için kod parçalarının incelenmesi gerektiği belirtilmiştir.

Sınav bilgilendirmesi yapılmıştır. Kod yazdırmanın sınav sırasında zor olduğu, öğrencilerin de çok tercih etmediği söylenmiştir. Kod bilgisini sorgulamak gerektiğini düşünen arkadaşlar olduğu, bu nedenle birkaç tane kod sorusu sorulabileceği belirtilmiştir. Final sınavının vize benzeri olacağı, boşluk doldurma, test veya klasik sınava yakın olmayacağı (dersin ruhuna aykırı) vurgulanmıştır. Sınavın %20-25'lik kısmının daha ayırt edici sorular olacağı, %75-80'inin temel bilgilerden oluşacağı söylenmiştir. Sınava hazırlanmak için en basit ve kolay adres developer.android.com olarak belirtilmiştir. Slide'ların paylaşılacağı, üzerinden geçilmesi önerilmiştir. "Çok kıydaki öste kalmış bir bilgi sorma taraftarı değilim, temel bilgiden soracağım" ifadesi kullanılmıştır.

Dönem ödevi değerlendirme hatırlatması yapılmıştır. Dönem projesinin daha derin bir değerlendirme gerektirdiği, kontrolünün daha uzun süreceği belirtilmiştir. Teslim edilen ödevlerde hiç ses kullanmadan gösteren arkadaşlar olduğu, projeyi anlatmak için ses kullanılması gerektiği vurgulanmıştır. Drive'a yüklenen videoların bir kısmının açılmadığı, video linkinin erişilemediği, "böyle bir dosya yoktur" hataları alındığı paylaşılmıştır. YouTube üzerinden linki göndermenin daha risksiz olduğu, dönem projesine bu detaylara düşülmemesi gerektiği, düzeltmek için yeterince vakit olmayabileceği söylenmiştir. İkinci ödev açıklandığında sıkıntı olanların paylaşılabileceği, hoca tarafından ne tür problem varsa öğrencilere aktarılacağı belirtilmiştir.

Dersin ana konusuna, yani konum tabanlı servislere geçildiğinde ilk olarak lokasyon bilgisinin önemi vurgulanmıştır. Lokasyon bilgisini kullanan uygulama sayısının yıllar içinde çok arttığı, telefon veya akıllı saat olmadan hiçbir yere gidilmediği, ebeveynlerin çocuklarını takip etmesi, araçla bir yerden bir yere giderken telefonsuz bir noktaya giden sayısının çok az olduğu belirtilmiştir. Adres bilgisini hangi yollardan temin edildiği sorulmuş, bir öğrenci sensörleri (Wi-Fi, Bluetooth, GPS) ve baz istasyonlarını saymıştır.

Adres bilgisi temin yöntemleri detaylı olarak açıklanmıştır. GPS (Global Positioning System) en yüksek doğrulukla bilgi sağlar. Bunun altında farklı uydu sistemleri vardır: GPS (Amerika), Glonass (Rusya), Beidou (Çin), Hindistan'ın sistemi; hepsine genel olarak GPS denir (uydu üzerinden lokasyon değerlendirilmesi). Baz istasyonları üzerinden de konum bilgisi elde edilebilir. Wi-Fi access point'ler üzerinden de konum bilinir çünkü her birinin sabit bir IP'si var, bu sabit IP'lerin lokasyonları bellidir; bu yöntemle yüksek çözünürlükte bilgi alınabilir. Bir başka yöntem: başka uygulamanın almış olduğu konum bilgisi. Sizin uygulamanız bir request yaptığında, eğer düşük enerji modunda veya no power modunda ise, 5 saniye önce başka bir uygulama bu bilgiyi almışsa onun kaynağından alınır; böylece ekstra enerji tüketilmemiş olur.

Üçgensel hesaplama (Triangulation) açıklanmıştır. Şehir yaşamında baz istasyonu ve Wi-Fi access point kullanmak akıllıcadır çünkü daha az enerji tüketir (mesafe: Wi-Fi daha yakın, baz istasyonu biraz daha uzak, uydu en uzak). Kırsal yaşamda baz istasyonu veya Wi-Fi access point duruma göre uzak noktalarda bulunabilir. Lokasyon bilgisinin doğruluğu/hassasiyeti nokta + çember şeklinde ifade edilir; çemberin büyüklüğü hassasiyetin düşüklüğünü gösterir. Yüksek hassasiyet için GPS veya yakın bölgede birden fazla baz istasyonu/access point gerekir. Üçgensel yaklaşımla gelen sinyallerin kuvvetine bağlı hesaplama yapılır.

Android lokasyon türleri açıklanmıştır. Eskiden ikiye ayrılmayan lokasyon bilgisi takibi, enerji tüketimi dolayısıyla ikiye ayrılmıştır. Foreground location anlık veya geçici periyot için bilgi sağlar (navigasyon, anlık konum paylaşımı). Background location sürekli kişi takibi ve geofencing API için gerekir. Android 10 ve 11 arasında farklılıklar vardır; birinde require, diğerinde recommend ediliyor. 8 ile başlayan, 9'da belirginleşen, 10 ve 11'de net ayrımlar. Android'den lokasyon izni isteniyorsa artırımlı yaklaşımla önce foreground, gerekirse background location talep edilmelidir. Doğrudan background location talebi Android'in çok istediği bir durum değil çünkü gereksiz enerji tüketimi ve sürekli kişi takibi anlamına gelir.

Lokasyon izin türleri detaylı olarak ele alınmıştır. COARSE_LOCATION kabaca bilgi (şehir düzeyi, kaba bir bilgi). FINE_LOCATION kesin bilgi (sokak düzeyi, mümkünse en iyi seçenek). Manifestte ACCESS_FINE_LOCATION, ACCESS_COARSE_LOCATION tanımlanmalıdır. Android 10+ için ACCESS_BACKGROUND_LOCATION manifestte ayrıca tanımlanmalıdır. Foreground service kullanılıyorsa foreground service tipi de manifestte belirtilmelidir (API 29+ sonrası zorunlu). Foreground location, uygulamanın bir foreground service çalıştırması durumunda da talep edilebilir.

Geofencing kavramı açıklanmıştır. Coğrafi fence, yarıçapı ve merkezi belirlenen bölgedir (100 metreden 1-5 kilometreye kadar değişen büyüklükler). Bölgeye giriş/çıkış/içeride kalma takibi yapılır. Reminder'lar bölge bazlı tetiklenebilir (zamansal değil, mekansal); örneğin eve geldiğinizde bir şey yapmanız gerektiğinde hatırlatma yapılabilir.

Run-time lokasyon izinleri açıklanmıştır. Manifest yerine runtime sırasında izin alma (checkSelfPermission) önerilir çünkü manifestteki izinler bir kez verildiğinde sürekli kullanılır. Allow once, Allow while using the app, Deny seçenekleri sunulur. Önce foreground location talep edilir, gerçekten gerekirse background location talep edilir. Sadece current location için background access talep edilmemelidir ("kesinlikle talep etmemelisiniz").

Konum bilgisi sağlama yöntemleri açıklanmıştır. Eski LocationManager artık çok kullanılmıyor. Yeni olarak Google Play Services üzerinden FusedLocationProviderClient sınıfı kullanılır. SDK içerisinden Google Play Services'ın geliştirme ortamına yüklenmesi gerekir. onCreate'de fusedLocationProviderClient değişkeni oluşturulur, locationServices.getFusedLocationProviderClient çağrılır. getLastLocation ile en son bilgi talep edilir (telefonunuzda kaydedilmiş başka bir uygulama tarafından da olabilir). onSuccess (bilgi varsa) ve onFailure listener'ları ile sonuç işlenir. Eğer onSuccess çalıştı ama location object null döndüyse, bunun sebepleri: sensör donanımsal arıza, telefon çekmemesi, airplane modda, GPS kapalı, Wi-Fi/baz istasyonu bağlantısı yok, uydu bağlantısı için fiziksel/hava şartları uygun değil, yeni cihaz, Google Play Services yüklenmemiş/yeniden başlatılmış, FusedLocationProviderClient oluşturulmamış.

Konum verisinin geçerliliği vurgulanmıştır. GetLastLocation metoduyla alınan bilgi hatalı olabilir (eski bilgi olabilir). Lokasyon bilgisinin ne kadar yeni olduğu (saat kontrolü) önemlidir. Üretilen bilgilerin uyumluluğu (kısa sürede bambaşka bir yer gösteriliyorsa hata var) kontrol edilmelidir. Hız bilinen, üretilen veriler bellidir; ilişki kontrol edilip ön işlemden geçirilmelidir. Hoca, "hocam bir anda üniversitenin giriş kapısındayken üniversitenin ortasında gösterdi" gibi örnekler vererek hatalı verinin gerçek hayatta nasıl sorun yarattığını açıklamıştır.

Batarya optimizasyonu detaylı olarak ele alınmıştır. Doğru adres üretme ve batarya optimizasyonu iki ana kriterdir. Android 8'den itibaren background'lar için yeni kurallar konulmuştur. Background location talebinde bulunulsa bile, gelen restrictionlardan dolayı saatte 1-2-3-4 taneye düşebilir; her zaman beklenen sıklıkta veri alınamayabilir. Wi-Fi üzerinden veri alındığında, aynı Wi-Fi'ye bağlı kalındığı sürece ekstra enerji harcanmaz; sistem otomatik optimizasyon yapar. Geofence'de bölgeden çıkıp çıkmadığınız saniyede bir kontrol edilir; 10 saniye-2 dakika gecikme olabilir. Aralık ne kadar açık olursa batarya performansı o kadar yüksek olur.

Batarya tüketimini etkileyen üç parametre açıklanmıştır. Accuracy (doğruluk): setPriority üzerinden ayarlanır, dört kademe. HIGH_ACCURACY tüm seçenekler devrede, en yüksek hassasiyet, en fazla enerji tüketimi. BALANCED_POWER_ACCURACY GPS'ten çok Wi-Fi veya baz istasyonlarından, güç tüketimi dengelenmiş, en sık kullanılan. LOW_POWER minimum pil tüketimi, genelde baz istasyonu sinyalleri, doğruluk garantisi yok, şehir düzeyi. NO_POWER mevcut başka uygulama lokasyon üretiyorsa onun verisine bağlı, üretmiyorsa bilgi gelmez, neredeyse hiç enerji tüketmez. Frequency (sıklık): saniye mertebesinde, setInterval ile belirlenir (5000, 10000, 2000, 1000 ms). En yüksek hassasiyetli frekans saniyede 1 defadır (navigasyon için). setInterval talep sıklığını belirler. setFastestInterval: eğer işleme süresi talep sıklığından kısa ise, en hızlı bilgi talep edilir; standart 10 saniye ama belli anlarda 5 saniye gerekirse, setFastestInterval 5 saniye yapılabilir. Latency (gecikme): bilginin ne gecikmeyle ulaşacağı.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
