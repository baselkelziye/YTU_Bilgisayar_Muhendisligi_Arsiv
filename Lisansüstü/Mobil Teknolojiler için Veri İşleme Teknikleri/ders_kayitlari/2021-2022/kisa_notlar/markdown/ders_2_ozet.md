# Ders 2 Çalışma Özeti

## Genel Konular

- Android işletim sisteminin katmanlı mimarisi (ekrandan, 00:20:00)
  - En altta Linux çekirdeği (Linux Kernel) bulunur: Display, Camera, Flash Memory, Binder (IPC), Keypad, WiFi, Audio sürücüleri ve Power Management.
  - Üstünde iki blok yan yana durur: Libraries (Surface Manager, Media Framework, SQLite, OpenGL | ES, FreeType, WebKit, SGL, SSL, libc) ve Android Runtime (Core Libraries, Dalvik Virtual Machine).
  - Application Framework katmanı uygulama yazmak için gereken API'leri verir: Activity Manager, Window Manager, Content Providers, View System, Package Manager, Telephony Manager, Resource Manager, Location Manager, Notification Manager.
  - En üstte Applications katmanı vardır: Home, Contacts, Phone, Browser gibi telefonla gelen temel uygulamalar.
  - Uygulama geliştirici çoğunlukla Application Framework ve Libraries katmanlarıyla çalışır. Çekirdek düzeyindeki iş daha çok işletim sistemine yönelik performans işleri içindir.
- Android'de çalışma ortamının gelişimi
  - Java Virtual Machine fikrinden, kaynakları kısıtlı cihazlar için Dalvik Virtual Machine'e, oradan Android Runtime'a (ART) geçildi.
  - Eskiden kod uygulama açılırken yorumlanıyordu (just-in-time). Bu yavaş ve kaynak tüketen bir yoldu.
  - Ahead-of-time (AOT) derlemede kod uygulama indirilip kurulurken dönüştürülür. Uygulama her açılışta hızlı çalışır, ama kurulum uzar ve uygulama daha çok yer kaplar.
  - Bugün Android iki yöntemi birlikte kullanır.
- APK ve Android App Bundle
  - APK, Android'in paket biçimidir. Yazılım bir zip gibi paketlenir, marketten bu paket indirilip açılır.
  - APK bütün cihazlarda çalışacak bilgileri taşıdığı için büyüktür ve kurulumu uzundur.
  - App Bundle yeni paket biçimidir. Market, indirecek telefonun özelliklerine bakar ve yalnız o telefona gereken parçaları gönderir. İndirme ve kurulum hızlanır, uygulama daha az yer kaplar. Cihaz çeşitliliğini yönetmek için tasarlanmıştır.
- Android'de geliştirme dilleri ve araçlar
  - Yerel (native) geliştirme Kotlin ve Java ile yapılır. Bunun için SDK (Software Development Kit) gerekir.
  - Alt seviye iş için NDK (Native Development Kit) kurulur. C ve C++ ile kütüphane yazılır, Java içinden kütüphane gibi çağrılır. Böylece Java'nın hantallığı aşılır ve sistem düzeyine yaklaşılır.
- iOS mimarisi (ekrandan, 00:25:00)
  - Katmanlar alttan üste: Kernel and Device Drivers (BSD, File System, Mach, Networking), Core OS (Accelerate, Directory Services, Disk Arbitration, OpenCL, System Configuration), Core Services (Address Book, Core Data, Core Foundation, Foundation, Quick Look, Social, Security, WebKit), Media (AV Foundation, Core Animation, Core Audio, Core Image, Core Text, OpenAL, OpenGL, Quartz), Cocoa Touch (Application) katmanı (slaytta AppKit kutusu).
  - Android'den farkı, çekirdeğin üstündeki çekirdek hizmetlerin iki ayrı katman (Core OS ve Core Services) olarak tasarlanmasıdır. Cocoa Touch, Android'in uygulama katmanına denk gelir.
  - iOS daha az cihaz çeşidine yönelir. Diller Swift ve Objective-C'dir. Swift, script diline yakın, kolay yazılan bir dildir; Objective-C daha karışıktır.
  - iOS geliştirme için genelde Mac gerekir ve testler çoğunlukla gerçek cihazda yapılır. Bu yüzden iOS geliştiricisi bulmak zordur. Android'de emülatör vardır.
- Emülatör ve simülatör farkı
  - Emülatör donanımı birebir taklit eder; bütün özellikleri kopyalar. Yazması zordur, alt seviye bilgi ve ciddi kaynak ister.
  - Simülatör davranışı yaklaşık modeller; genel bir fikir verir ama gerçek cihaz davranışını birebir üretmez.
- KaiOS (ekrandan, 00:45:00)
  - Düşük donanımlı telefonlar için bir işletim sistemidir. Katmanlar: KaiOS Front End (Core applications, Shared JS libraries) ve Integrated services; Web API; Gecko (OS Management, Web App Management, Connectivity, Device API); Gonk (Drivers, Kernel, OEM Libraries).
  - JavaScript ve web API'leri kullanılır. Temel uygulamalar çoğunlukla sosyal medya ve bağlantı (connectivity) üzerinedir.
- Mobil uygulama geliştirmede dört teknik
  - Native development: her platform için kendi diliyle ayrı geliştirme. En iyi performans, ama iki platform için iki ekip ya da sıralı geliştirme gerekir.
  - Cross-platform development: tek kodla iki platforma kod üretilir. Flutter (Dart) ve React Native (JavaScript) en bilinenlerdir; Xamarin (C#) da vardır. Kod native'e dönüştürülür.
  - Hybrid app development: web teknolojileriyle yazılan uygulama native bir konteynere konur; marketten indirilir, telefondaki WebKit üzerinde yorumlanarak çalışır (Cordova, Ionic).
  - Mobile web development: responsive tasarımlı web sitesi. Kurulum gerekmez, bakım ucuzdur, ama cihazın yerleşik özelliklerine erişimi kısıtlıdır.
- Cross-platform araçların zayıf yanı ve iyi bir aracın özellikleri
  - Araya giren dönüşüm katmanı performansı ve pil kullanımını düşürür. Katman sayısı arttıkça performans azalır. Bugün bu kayıp beş yıl öncesine göre küçüktür.
  - İyi bir araç: güncel işletim sistemlerini desteklemeli, her iki platformun arayüzüne yakın UI bileşenleri sunmalı, güvenlik açığı vermemeli, düşük güç tüketen kod üretmeli, az ek kod eklemeli, yerleşik (native) özelliklere erişim sağlamalı.
- Mobil işletim sistemi ile PC işletim sistemi farkları (ekrandan, 01:00:00)
  - Güç: işlemci ve ekran varsayılan olarak kapanır; açık tutmak isteyen süreç wake-lock almalıdır. Android Doze, telefon kullanılmazken arka plan servislerinin daha seyrek uyanmasını sağlar. Karanlık mod, otomatik parlaklık (ortam ışığı sensörü), yakınlık sensörüyle ekranı kapatma ve baz istasyonundan Wi-Fi'ye otomatik geçiş de güç yönetimine katkı verir.
  - Arayüz: temel giriş dokunmatik ekrandır (çoklu dokunma, derin dokunma); klavye ve ses destekler.
  - Bellek: sınırlı bellek, etkinliklerin yaşam döngüsü, kullanılmayan uygulamaları öldüren "Low memory killer".
  - İletişim işlemcisi: GPRS/EDGE/3G/LTE ayrı bir işlemcide çalışır.
  - Taşınabilirlik: mobil işletim sistemleri çoğunlukla ARM üzerinde çalışır; Android emülatörü ARM ya da x86 seçeneği verir.
- Mobil uygulama geliştirmede kısıtlar (ekrandan, 01:10:00)
  - Sınırlı pil; az kaynak (CPU, bellek, depolama, pil); menzil ve bant genişliği; güvenlik standartları; olası tehlikeler.
  - Veri aktarım zamanlaması, yarıda kalan aktarımın sürdürülmesi, bağlantı türü seçimi ve depolama stratejisi bu kısıtlardan doğar.

## Hocanın Özellikle Vurguladığı Kısımlar

- Veri toplayan uygulamada verinin cihazdan merkeze ne zaman gönderileceği
  - Acil değilse: telefon kullanılmıyorken (örneğin gece), Wi-Fi erişim noktasına bağlıyken (mobil veri harcanmasın), şarja bağlıyken, ve arka planda çalışmaya izin verilmeyen uygulamalarda uygulama açıldığında.
  - Anlık gönderim gerekiyorsa dakikalık, beş dakikalık ya da saatlik periyot seçilir.
- Yarıda kalan aktarım baştan başlatılmamalı
  - Bağlantı koparsa veri yerelde tutulmalı ve kalınan yerden devam edilmeli. 10 MB'lık gönderimin 8 MB'ı gittiyse kalan 2 MB gönderilmeli; baştan göndermek kullanıcının veri planını boşa harcar.
- LTE ile 2G/3G arasında güç ve enerji ayrımı
  - LTE anlık olarak daha çok güç çeker. Ama hızlı olduğu için büyük veriyi kısa sürede gönderir ve toplam enerji açısından daha verimli olabilir. Veri seyrek ve küçükse günün çoğunda düşük güçlü bağlantıda kalmak enerjiyi azaltır.
- Cross-platform araçlar birbirinden farklıdır
  - Ürettikleri kodun boyutu, enerji tüketimi ve kaynak kullanımı farklıdır. Araç seçerken bu ölçütlere bakılmalıdır.
- Geliştirilecek uygulamanın ihtiyacı tekniği belirler
  - Basit bilgi sunan bir kurumsal site için native uygulama yerine responsive web yeterli olabilir.

## Kısa Tekrar Notları

- Android katmanları: Linux Kernel, Libraries + Android Runtime, Application Framework, Applications.
- iOS katmanları: Kernel and Device Drivers, Core OS, Core Services, Media, Cocoa Touch.
- KaiOS katmanları: Front End, Web API, Gecko, Gonk.
- JIT: açılışta dönüştürme. AOT: kurulumda dönüştürme. ART ikisini birlikte kullanır.
- App Bundle, cihaza özel parçaları gönderir; APK her şeyi taşır.
- Android: Kotlin, Java, SDK, NDK (C/C++). iOS: Swift, Objective-C, Mac ve gerçek cihaz.
- Emülatör donanımı birebir taklit eder; simülatör yaklaşık modeller.
- Dört teknik: native, cross-platform, hybrid, mobile web.
- React Native: JavaScript. Flutter: Dart. Xamarin: C#. Hybrid: Cordova, Ionic.
- Güç: wake-lock, Doze, karanlık mod, otomatik parlaklık, Wi-Fi'ye geçiş.
- Veri aktarımı: boşta, Wi-Fi'de, şarjda; kopan aktarım kaldığı yerden sürer.
- Android'de harici depolama paylaşım ve büyük veri için; güvenlik isteyen veri dahili depolamada.

## Detaylı Açıklamalar

Mobil işletim sistemleri katmanlı bir yapıyla tasarlanır. Android'de Linux çekirdeği donanım sürücülerini ve güç yönetimini taşır. Üstündeki kütüphaneler (SQLite, WebKit, OpenGL ES, SSL, libc gibi) performanslı yazılım için doğrudan erişim sağlar. Android Runtime, Java Virtual Machine fikrinden doğan Dalvik'in yerini alan çalışma ortamıdır. Uygulama geliştiricinin asıl çalıştığı yer Application Framework'tür; konum, bildirim, telefon, etkinlik yöneticileri gibi API'ler buradan gelir. Ders, Android'in derleme stratejisindeki değişimi de anlattı: önce açılış anında yorumlama vardı, sonra kurulum anında derleme (AOT) geldi, bugün ikisi birlikte kullanılıyor. Paketleme tarafında APK'dan App Bundle'a geçiş, cihaz çeşitliliğinin yarattığı boyut sorununu çözer.

iOS beş katmanla anlatıldı. Çekirdek ve sürücülerin üstünde Core OS ve Core Services ayrı katmanlardır; Media katmanı grafik, ses ve animasyon çerçevelerini taşır; en üstte Cocoa Touch vardır. Apple'ın stratejisi, az cihaz, Mac zorunluluğu ve gerçek cihazda test üzerinden kurulu daha kapalı bir ekosistemdir. Hoca bunu "herkes gelsin" yerine "uzmanlaşmak ve yatırım yapmak isteyen gelsin" yaklaşımı diye özetledi. Kârlılıkta iOS, yaygınlıkta Android öndedir; Google Android'i kendi servislerinin yaygınlığı için destekler. Bu bağlamda emülatör ile simülatör ayrımı yapıldı: emülatör donanımı birebir taklit eder ve yazması pahalıdır; simülatör davranışı yaklaşık modeller. Hoca, uçuş simülatörü ile pilot eğitiminde kullanılan, uçağın her düğmesini taklit eden pahalı emülatörleri karşılaştırarak bu farkı açıkladı.

İki platform için ayrı native geliştirme maliyetli olduğu için cross-platform araçlar ortaya çıktı. 2010'ların başında basit işler yapabilen bu araçlar bugün native'e çok yakın sonuç veriyor. Çoğu web teknolojilerine (JavaScript, HTML5, CSS) dayanır. Aradaki dönüştürücü katman bir derleyici gibi düşünülebilir; her ek katman performansı düşürür, ama bu katmanlar artık çok gelişmiş olduğu için kayıp küçüktür. Hybrid uygulama ise native'e dönüştürülmez: web uygulaması native bir konteynere konur ve telefonun WebKit'i tarafından yorumlanır. Mobile web development, responsive tasarımla tek geliştirmede telefon, tablet ve PC'ye hizmet verir; kurulum gerektirmez ama yerleşik özelliklere erişimi zayıftır. Derste öğrencilerin verdiği örneklerle bazı büyük uygulamaların Flutter ya da React Native ile yazıldığı, bazılarının sonra native'e döndüğü konuşuldu. Bir öğrenci Kotlin Multiplatform Mobile'ı anlattı: arayüz her platformda native yazılır, arka plandaki veri ve iş mantığı Kotlin'de yazılıp iOS'ta kütüphane olarak kullanılır. Google'ın Fuchsia adlı yeni işletim sistemi girişiminden de söz edildi.

Mobil işletim sistemini PC'den ayıran başlıca konu güç yönetimidir. Wake-lock mekanizması, Doze, karanlık mod, ortam ışığına göre parlaklık, görüşmede yakınlık sensörüyle ekranı kapatma ve uygun ağa otomatik geçiş bu yönetimin parçalarıdır. Arayüzde dokunmatik ekran, çoklu ve derin dokunma ile ses girişi öne çıkar. Hoca, dokunma noktalarının ve video izleme davranışının (nerede durulduğu, reklamın ne zaman geçildiği) kullanıcı modeli çıkarmak için kullanılabileceğini, sesle yazdırmanın ise hız ve ekranın açık kalma süresi açısından enerji ödünleşimi taşıdığını belirtti. Son bölümde uygulama geliştirme kısıtları ele alındı: veri aktarım zamanı, kopan aktarımın sürdürülmesi, LTE ile 2G/3G arasında güç ve toplam enerji ödünleşimi, ve depolama. Android'de harici flash bellek kullanılabilir; paylaşılan ya da büyük veri için uygundur, ama çıkarılabilir ve dışarıdan erişilebilir olduğu için güvenlik isteyen veri dahili depolamada tutulmalıdır. Android'in public ve private dizin kavramları, uygulama kaldırıldığında verinin kalıp kalmayacağını belirler.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
