# Ders 2 Genişletilmiş Notu: Mobil İşletim Sistemleri ve Mobil Uygulama Geliştirme Teknikleri

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Android İşletim Sisteminin Mimarisi
- 2. Android'de Çalışma Ortamı, Paketleme ve Geliştirme Araçları
- 3. iOS Mimarisi ve Geliştirme Ortamı
- 4. Emülatör ve Simülatör
- 5. İki Platform Stratejisi ve KaiOS
- 6. Cross-Platform Geliştirme
- 7. Mobil Uygulama Geliştirmede Dört Teknik
- 8. Mobil İşletim Sistemi ile PC İşletim Sistemi Arasındaki Farklar
- 9. Mobil Uygulama Geliştirmede Kısıtlar: Veri Aktarımı ve Depolama
- Örnek Sorular
- Dersin Toparlaması

## 1. Android İşletim Sisteminin Mimarisi

Ders, bir önceki derste konuşulan pazar payı (market share) konusundan devam etti: hangi mobil işletim sistemlerinin yaşamaya devam ettiği, hangilerinin eklendiği ve ilk mobil işletim sisteminin ne olduğu daha önce değerlendirilmişti. Bu derste işletim sistemlerinin iç yapısına geçildi.

Mobil işletim sistemleri genelde bir framework yapısıyla, üst üste binen katmanlardan (layer) oluşur. Android'in katmanları slaytta şöyle gösterildi (ekrandan, 00:20:00):

| Katman | Bileşenler |
|---|---|
| Applications | Home, Contacts, Phone, Browser, ... |
| Application Framework | Activity Manager, Window Manager, Content Providers, View System, Package Manager, Telephony Manager, Resource Manager, Location Manager, Notification Manager |
| Libraries | Surface Manager, Media Framework, SQLite, OpenGL \| ES, FreeType, WebKit, SGL, SSL, libc |
| Android Runtime (Libraries ile yan yana) | Core Libraries, Dalvik Virtual Machine |
| Linux Kernel | Display Driver, Camera Driver, Flash Memory Driver, Binder (IPC) Driver, Keypad Driver, WiFi Driver, Audio Drivers, Power Management |

En alt katmanda Linux çekirdeği yer alır. Bir üst katmanda ihtiyaç duyulan kütüphaneler bulunur. Hoca, kütüphanelere doğrudan erişimin performanslı yazılım geliştirmek için çok önemli olduğunu belirtti.

Application Framework, telefonun özelliklerini kullanarak uygulama geliştirmeyi sağlayan katmandır. Activity Manager, Notification Manager, Location Manager, Telephony Manager gibi bileşenler burada yer alır; uygulama yazmak için gereken API'leri bu katman verir. En üst katmanda işletim sisteminin varsayılan olarak sunduğu, bir telefonun sahip olması gereken temel uygulamalar bulunur.

Uygulama geliştirirken asıl çalışılan katmanlar ikinci ve üçüncü katmanlardır: Application Framework API'leri sağlar, Libraries katmanı ise sistem seviyesine yakın, performanslı işler için kullanılır. Çekirdek düzeyinde de iş yapmak mümkündür, ama uygulama geliştiriciler orada çalışmayı pek tercih etmez; o düzey daha çok işletim sistemine yönelik performans işleri içindir.

## 2. Android'de Çalışma Ortamı, Paketleme ve Geliştirme Araçları

### 2.1 Java Virtual Machine'den Android Runtime'a

Android'in çalışma ortamı zaman içinde değişti. Önce Java Virtual Machine fikrinden yola çıkıldı. Sonra küçük ve kaynakları kısıtlı cihazlar için Dalvik Virtual Machine ortaya atıldı. Daha sonra Android Runtime (ART) hayata girdi.

### 2.2 Just-in-time ve Ahead-of-time Derleme

Eskiden Android'de bir uygulamanın kodu, uygulamayı çalıştırmaya başladığınız anda gerçekleşen bir yorumlama (interpret) işlemiyle çalışıyordu. Bu yöntemin yavaşlığı ve kaynak tüketimi Google'ın dikkatini çekti ve ahead-of-time (AOT) derleme mantığı getirildi.

AOT'de uygulamayı indirirken, çalıştırılacak kodun dönüşümü de o sırada yapılır. Böylece uygulamayı her açtığınızda dönüşümle vakit kaybetmezsiniz ve performans kazanırsınız. Bedeli de vardır: kurulum biraz uzar ve uygulama daha fazla yer kaplar, çünkü çalıştırılacak kod önceden dönüştürülmüş olarak saklanır.

Zamanla Android ikisini birleştiren bir yapıya döndü. Bugün hem just-in-time hem ahead-of-time derleme mantığı birlikte kullanılarak uygulamaların daha performanslı çalışması sağlanıyor.

> **Ek bilgi (derste anlatılmadı):** Büyük olasılıkla ART'nin bugünkü karma yaklaşımında uygulama önce kısmen yorumlanarak ya da JIT ile çalışır, sık kullanılan kod parçaları profillenir ve cihaz boştayken AOT ile derlenir. Bu, kurulum süresi ile çalışma performansı arasındaki ödünleşimi dengeler.

### 2.3 APK ve Android App Bundle

APK, Android'in kullandığı paket (package) biçimidir. Geliştirdiğiniz yazılımı bir zip dosyası gibi düşünebilirsiniz: her şey bu paketin içinde saklanır ve yayımlanır. Marketten bu APK indirilir ve açılarak kurulur.

Cihaz çeşitliliği çok fazla olduğu için APK'lar bütün cihazlarda çalışacak bilgileri içeriyordu. Bu yüzden boyutları büyük, kurulumları uzun süren paketlerdi.

Android App Bundle, APK paket biçiminin yeni sürümüdür. Bu biçimde market, uygulamayı indirecek telefonun özelliklerine bakar ve kurulumda yalnız o telefona gerekli olan parçaları aktarır. Böylece başka telefonlar için gereken kütüphaneleri boşu boşuna kendi telefonunuza almazsınız. Bu hem indirmeyi hem kurulumu hızlandırdı, hem de uygulamaların telefonda kapladığı yeri önemli ölçüde azalttı. App Bundle, cihaz çeşitliliğini yönetebilecek düzeyde tasarlanmış bir biçimdir.

### 2.4 Diller, SDK ve NDK

Android'de native geliştirme için iki temel dil kullanılır: Kotlin ve Java. Bunun için SDK'nın (Software Development Kit) yüklenmesi gerekir. Alt seviye bir iş yapmak isteniyorsa Android NDK (Native Development Kit) kurulur. NDK ile C ve C++ dilleriyle kütüphane yazılır ve bu alt seviye kod parçaları Java içinden bir kütüphane gibi çağrılıp çalıştırılır. Bu sayede Java'nın hantal yapısı aşılır ve sistem seviyesindeki işler daha yakından kontrol edilebilir.

Hoca, son yıllarda Android'de Java'dan Kotlin'e doğru bir kayma olduğunu ve Kotlin ile uygulama geliştirenlerin sayısının çok arttığını belirtti.

## 3. iOS Mimarisi ve Geliştirme Ortamı

### 3.1 Katmanlar

iOS tarafında dört, hatta beş temel katman vardır. Slayttaki yapı alttan üste şöyledir (ekrandan, 00:25:00):

| Katman | Bileşenler |
|---|---|
| Cocoa Touch (Application) | AppKit |
| Media | AV Foundation, Core Animation, Core Audio, Core Image, Core Text, OpenAL, OpenGL, Quartz |
| Core Services | Address Book, Core Data, Core Foundation, Foundation, Quick Look, Social, Security, WebKit |
| Core OS | Accelerate, Directory Services, Disk Arbitration, OpenCL, System Configuration |
| Kernel and Device Drivers | BSD, File System, Mach, Networking |

En altta çekirdek ve aygıt sürücülerinin bulunduğu katman vardır. Üstünde işletim sisteminin çekirdek özelliklerinin yönetildiği bölüm yer alır; Android'den farklı olarak bu bölüm iki katman (Core OS ve Core Services) olarak tasarlanmıştır. En üstte Android'in uygulama katmanına denk gelen Cocoa Touch yapısı konumlanır.

<!-- BELİRSİZ: 00:25:24 civarında altyazı kopuk ("olarak tasarlanmamış yok böyle bir katman"); hocanın hangi katmanın Android'de karşılığı olmadığını söylediği net değil. Büyük olasılıkla Media katmanından söz ediliyor. -->

### 3.2 Cihaz Çeşitliliği ve Diller

iOS, Android'e göre çok daha az cihaza yönelik çalışır. Eskiden bir ya da iki cihaz vardı; son yıllarda 3-4 farklı kombinasyonla çeşitlilik arttı, bugün 4-5 cihazdan söz edilebilir.

iOS'ta Swift ve Objective-C dilleri kullanılır. Swift, öğrenildiğinde çok kolay yazılan, script diline yakın bir dildir. Objective-C daha karışık bir yapıya sahiptir. Sadeleştirmek için Swift yaklaşık 7-8 yıldır kullanılıyor ve dil tamamen oturmuş durumda.

### 3.3 iOS Geliştiricisinin Az Olmasının Nedeni

Hocaya göre iOS geliştiricisi bulmak kolay değildir. En önemli nedenlerden biri, uygulama geliştirmek için genelde bir Mac cihaza ihtiyaç duyulması ve Apple'ın test işlemlerini daha çok gerçek bir cihaz üzerinde yapmayı gerektirmesidir. Android'de ise emülatör vardır ve birçok test emülatörde yapılabilir.

## 4. Emülatör ve Simülatör

Hoca bu noktada emülatör ile simülatör arasındaki farkı sordu.

**Soru:** Emülatör ile simülatör arasındaki fark nedir?

**Cevap (bir öğrenci):** Simülatörde yalnız görsel şeyler test edilebiliyor. Emülatörde cihazla ilgili diğer şeyler de test edilebiliyor, uygulama yüklenebiliyor. Örneğin iOS simülatöründe market olmadığı için bir uygulama indirip denemek mümkün olmuyor; emülatörde market dahil her şey olabiliyor.

Hoca cevabı şöyle tamamladı: emülatör, bir donanım yapısının birebir taklit edilmesi, bütün özelliklerinin kopyalanmasıdır ve alt seviye programlama bilgisi gerektirir. Donanımı birebir taklit edecek bir yazılım geliştirmek kolay değildir; bu yüzden her cihazın emülatörünü yazmak mümkün değildir ya da çok ciddi kaynak gerektirir. Android, geliştirmeyi kolaylaştırmak için en başından beri bu yolu seçti: "cihazınız yoksa da katkıda bulunabilirsiniz, size emülatör sunuyoruz."

Simülatör ise davranışı, fikir sahibi olunabilecek kadar taklit etmeyi amaçlar. O cihazın davranışını modeller, ama birebir o davranışı yaratmaz; yalnız genel bir fikir verir.

Hocanın benzetmesi uçuşla ilgiliydi. Bir uçuş simülatörü size sağa sola dönüş gibi davranışları sunar, ama gerçek bir uçağın davranışlarını birebir yansıtamadığı için orada yaptığınız denemeler yalnız genel bir uçuş deneyimi ya da fikir sağlar. Buna karşılık pilotların eğitim aldığı, uçağın her düğmesini ve her fonksiyonunu deneyimlemeye izin veren çok pahalı uçuş emülatörleri vardır; bunlar dünyada çok az sayıda ve yüksek maliyetle üretilmiştir.

Sonuç olarak iOS'ta bir uygulama geliştirdiyseniz bunu yalnız simülatörle test etmek yeterli olmaz; gerçek cihaz gerekir. Bu da iOS geliştiricilerinin sayısının çok yükselmesini engeller, çünkü cihazlar ucuz değildir.

## 5. İki Platform Stratejisi ve KaiOS

### 5.1 iOS ve Android'in Farklı Yolları

Hoca, iOS'un politikasını "herkes gelsin, katkıda bulunsun" değil, "bu konuda uzmanlaşmak, yatırım yapmak ve kendini buna adamak isteyenler gelsin" diye özetledi. İki işletim sistemi ve iki firma tamamen bağımsız iki yol seçmiştir. Kârlılıkta iOS önde, bilinirlik ve yaygınlıkta Android öndedir. Google Android'i başka yönlerden destekler: dünyadaki yaygınlığı ve kendi servislerinin kullanılabilirliği üzerine strateji kurar. iOS ise doğrudan bu platformdan para kazanmayı hedefler.

Bugün elde iki ana işletim sistemi vardır: Android ve iOS. Bunlara daha çok düşük konfigürasyonlu cihazlar için KaiOS eklenmiştir. Piyasada Bada, Samsung'un Tizen'i ya da Huawei'nin yeni işletim sistemleri gibi alternatifler olsa da, native geliştirme yapacaksanız temelde iki ortamı hedeflersiniz. Bu iki platform için kaynak ayırmanız, planlama yapmanız gerekir: ya paralel geliştirme için iki kişi alırsınız ya da birini bitirip diğerine geçerek sıralı (sequential) çalışırsınız ve ikinci platformun markete çıkması gecikir.

### 5.2 KaiOS Mimarisi

KaiOS'un katmanları slaytta şöyle gösterildi (ekrandan, 00:45:00):

| Katman | Bileşenler |
|---|---|
| KaiOS Front End | Core applications, Shared JS libraries (yanında: Integrated services) |
| Web API | |
| Gecko | OS Management, Web App Management, Connectivity, Device API |
| Gonk | Drivers, Kernel, OEM Libraries |

KaiOS'ta farklı bir mimari vardır, ama burada da JavaScript'in ve web API'lerinin tercih edildiği görülür. KaiOS temel uygulamaları sunar; bunlar daha çok sosyal medya uygulamalarıdır. Bunun dışında bağlantı (connectivity) gibi uygulamaların ihtiyaç duyacağı temel özellikler üzerine kuruludur. Donanım olarak belirli bir seviyede kalan telefonları yönetmek için yeterli bir yapıdır. Web teknolojileri kullanıldığı için uygulama geliştirmek de zor değildir; cross-platform mantığına benzer biçimde geliştirme yapılabilir. Hocanın bildiği kadarıyla cross-platform araçlar henüz KaiOS için uygulama üretmeyi desteklemiyordu, ama yakında bu özelliğin eklenebileceğini düşünüyordu.

## 6. Cross-Platform Geliştirme

### 6.1 Ortaya Çıkışı ve Diller

İki platform için ayrı geliştirmenin maliyetini ortadan kaldırmak için cross-platform development ortaya çıktı. Yaklaşık 8-10 yıllık bir geçmişi vardır, 2011'lerde başlar. 2010'ların ilk yarısında cross-platform araçlar oldukça yetersizdi: görselliği olmayan, yalnız temel işleri yapan basit uygulamalar üretebiliyorlardı. Bugün en bilinenleri Flutter ve React Native olmak üzere birçok araç vardır; iki platform için aynı anda kod üretmeyi sağlarlar.

**Soru:** Cross-platform araçların kullandığı diller nelerdir?

**Cevap (bir öğrenci):** React Native'de JavaScript, Flutter'da Dart kullanılır.

Hoca, Dart'ın da JavaScript'e benzer bir dil olduğunu ekledi. Script dillerinin çok eski bir geçmişi vardır (Visual Basic de bir script dilidir). JavaScript çok güçlü bir dil gibi görünmese de yazım kolaylığı ve script dili olması nedeniyle inanılmaz bir etkiye sahiptir ve bu etki mobil ortamda da görülür. Birçok cross-platform araç JavaScript, HTML5 ve CSS üçgeni üzerine kuruludur; web teknolojilerini kullanarak dönüşüm yapar ve kullanıcının bu dilleri bilmesiyle mobil uygulama geliştirmesini sağlar.

Alternatif olarak öğrenciler Xamarin, Cordova ve Delphi ile FireMonkey'i saydı. Hoca, Xamarin'de C# kullanıldığını ve bunun özellikle Windows teknolojilerinden gelen kişilerin mobil uygulama geliştirmesine yönelik bir strateji olduğunu belirtti. Bugün birçok alt kategoride uygulamaların cross-platform araçlarla geliştirildiği biliniyor.

### 6.2 Cross-Platform'un Dezavantajı

**Soru:** Cross-platform araçların hâlâ süren dezavantajı nedir?

**Cevap (bir öğrenci):** Genel olarak performans ve telefonun bütün özelliklerini kullanabilme. Örneğin ön yüzden native metotlara erişmenin ek bir maliyeti var; yalnız ön yüz kullanılırken bu maliyet olmuyor.

Hoca performans konusunu açtı. Yazılan kodu iOS'a ya da Android'e uygun biçimde çalıştırabilmek için bir dönüşüm gerekir. Bu dönüşümü bir derleyici gibi düşünebilirsiniz: kod yazarsınız, makine diline çevirirken arada bir derleyici vardır; Assembly kullanırken arada bir assembler vardır. Cross-platform'da bu dönüşümü yapan yapı bir API'dir. JavaScript, HTML5 gibi web teknolojilerini ya da C# gibi dilleri alır ve iOS ile Android tarafına çevirir.

Bu dönüştürücü zamanla çok iyi evrilse de, iOS SDK ya da Android SDK'nın sağladığı performanslı kaynak kullanımını ve pil tüketimini birebir veremez, çünkü arada bir katman vardır. Ne kadar katman eklenirse yapının performansı o kadar düşer. Hoca bunu dil katmanlarıyla örnekledi: makine diline en yakın Assembly ile (düzgün yazıldığını varsayarak) çok iyi performans alınır; C'ye, oradan Python'a, SQL'e ya da yapay zeka dillerine çıktıkça ara katmanlar artar ve özellikle sistem seviyesindeki işlerin performansı düşer. Bugün dönüşümü yapan katmanlar oldukça gelişmiş yazıldığı için cross-platform ile geliştirilen uygulamalarda 5 yıl öncesine göre önemli bir performans kaybı yaşanmaz.

> **Hocanın vurgusu:** Cross-platform araçları birbirleriyle karşılaştırmak önemlidir. A aracının ürettiği kod ile B aracının ürettiği kod boyut, enerji tüketimi ve kaynak kullanımı açısından farklıdır. Hangi aracı seçeceğinize bu ölçütlere bakarak karar vermelisiniz.

### 6.3 İyi Bir Cross-Platform Aracın Özellikleri

**Soru:** Bugün bir cross-platform araç geliştirecek olsanız, nelere dikkat ederdiniz?

**Cevap (bir öğrenci):** Flutter'ın mantığını doğru buluyorum: çok kişiye hitap ediyor, Android ve iOS tarafındaki geliştirmeleri destekliyor, ana ekran widget'ları bile geliştirilebiliyor, dili öğrenmesi kolay, dokümantasyonu iyi ve native'e olabildiğince yakın performans sağlamaya çalışıyor.

Hoca bunları doğru buldu ve toparlayarak şunları ekledi:

- O andaki mevcut işletim sistemlerinin hepsini desteklemeli. Bugün çeşitlilik azaldığı için iki işletim sistemi vardır.
- Arayüzde hem Android'in hem iOS'un arayüzüne yakın UI seçenekleri (butonlar, görseller vb.) sunmalı. Eskiden native uygulama ile cross-platform uygulama arasındaki görsel fark hissediliyordu; bugün bu fark neredeyse hiç hissedilmiyor.
- Güvenlik açığı vermemeli. Dönüştürücü açık verirse kullanıcı memnuniyetsizliği doğar.
- Her iki işletim sistemi için üretilen kod çalışırken güç tüketimi düşük olmalı.
- Mümkün olduğunca az ek kod eklemeli.
- Yerleşik (built-in, native) özelliklere mümkün olduğunca erişim sağlamalı. Eskiden cross-platform ürünlerde kamerayı ya da medya bileşenlerini kontrol etmek bile zordu; bugün native'in yapabildiği neredeyse her işlem yapılabiliyor.

## 7. Mobil Uygulama Geliştirmede Dört Teknik

### 7.1 Native ve Cross-Platform

**Soru:** Bugün bir mobil uygulama geliştirmek isteseniz kaç farklı yaklaşımla geliştirme şansınız var?

**Cevap (bir öğrenci):** Üç: doğrudan native, React Native ve Flutter. React Native yalnız ön yüz olarak kullanılıyor ve native metot kullanılmıyorsa Flutter'dan daha hızlı kalıyor, native'den de çok farkı olmuyor. React Native native uygulamaların içine de konabiliyor; bazı kısımlar React Native ile sağlanabiliyor. Native metotlar çok kullanılıyorsa Flutter performansta daha iyi. Seçim, native'in ne kadar kullanılacağına ve ekibin yapısına göre yapılmalı.

Hoca, native development'ı birinci teknik, Flutter, React Native ve diğer araçlarla yapılan cross-platform development'ı ikinci teknik olarak adlandırdı ve üçüncü, dördüncü tekniği sordu.

### 7.2 Hybrid App Development

**Soru:** Hybrid development'ı duydunuz mu? Cross-platform'dan farkı nedir?

**Cevap (bir öğrenci):** Cross-platform'da (Flutter, React Native) kod native'e çevriliyor. Cordova, Ionic gibi hybrid araçlarda ise üzerinde yalnız bir web sayfası var gibi.

Hoca açıkladı: hybrid uygulama, web teknolojileriyle geliştirilen ve telefonun üzerindeki WebKit üzerinden çalıştırılan uygulamadır. Cordova örneğiyle anlatırsak, web teknolojisiyle bir uygulama geliştirirsiniz; araç bu uygulamayı bir native konteyner (native container) içine koymanızı sağlar. Bu konteyner sayesinde uygulama marketten indirilebilir hale gelir. Kullanıcı onu normal bir native uygulama gibi marketten indirir. Çalıştırıldığında, telefonun işletim sisteminde web tarayıcısını yorumlayan WebKit, yazdığınız web teknolojisi kodunu yorumlayarak (interpret) uygulamanın çalışmasını sağlar. Yani temelde bir web uygulamasıdır, ama native bir konteynerin içinde durduğu için marketten indirilebilir.

Hybrid uygulamalar hâlâ vardır, ama yavaş yavaş cross-platform'a doğru kayılmaktadır. Cross-platform doğrudan native dönüşüm sağladığı ve bunu web teknolojileri için yapabilen platformlar da olduğu için, uygulama artık WebKit üzerinde çalışacak biçimde değil, birebir dönüştürülüp native kod tarafına entegre edilebilir biçimde üretilir. Hoca, hybrid app development'ın cross-platform'un bir başka türevi gibi de düşünülebileceğini söyledi.

### 7.3 Mobile Web Development

**Soru:** Telefonda bir iş yapabilmek için kullanılan dördüncü yaklaşım nedir?

**Cevap (bir öğrenci):** Doğrudan web sitesini kullanmak. Bazı siteler ana ekrana kaydedilince uygulama gibi duruyor.

Hoca bunu mobile web development diye adlandırdı. Responsive design ile bir web sitesi geliştirdiğinizde site telefon, tablet ve PC'den kullanılabilir. Avantajları: marketten indirmeye gerek yoktur, kurulum gerektirmez, çevrim içi olmak şartıyla her an her yerden erişilebilir, geliştirmesi kolaydır, bakım masrafı azdır ve tek geliştirmeyle PC dahil her yerden erişilir. Dezavantajı: cihazın yerleşik özelliklerini kullanmada başarılı değildir. HTML5'in gelmesiyle bu yöntem iyice yaygınlaştı, çünkü HTML5 bazı medya özelliklerinde telefonu kullanabilir. Bugün mobile web development, özellikle web sitelerinin tasarımında ve bilgi aktarımında responsive design olarak kullanılır; ama akıllı telefonun native özelliklerini kullanmada kısıtlıdır.

Hoca, bilgi sunan bir kurumsal web sitesi örneği verdi: site web teknolojileriyle responsive olarak yazıldığında telefondan, tabletten ve PC'den görsel bir sorun olmadan bakılabilir ve bütün işlevlere erişilebilir. Bunun için native uygulama yazmak mümkündü, ama gerekli olup olmadığı tartışılır. Bu tür basit işler için mobile web development'ı seçmek akıllıcadır. Teknik seçimi, geliştirilecek uygulamanın ihtiyaçlarına göre yapılır.

Böylece dört teknik tamamlandı: mobile web development, native development, cross-platform development ve hybrid app development.

### 7.4 Örnek Uygulamalar ve Yeni Gelişmeler

Flutter ve React Native ile geliştirilen uygulamalar sorulduğunda öğrenciler bazı örnekler verdi: Google'ın bazı uygulamalarının Flutter ile yazıldığı, Airbnb ve Facebook'un React Native kullandıktan sonra native'e döndüğü, bazı kamu kurumu uygulamalarının Flutter ile yazıldığı söylendi. Hoca, bu tercihin özellikle uygulamanın yayına alınma (deployment) süresini kısaltmak için yapıldığını ve Google'ın Flutter'a önemli bir yatırımı olduğunu belirtti; Google'ın amacı kendi tarafına bağlılık sağlayıp iOS tarafında da bir şeyler üretilmesini sağlamaktır.

Bir öğrenci Kotlin Multiplatform Mobile'ı anlattı. Bu yaklaşımda arayüz her platformda normal native arayüz olarak kodlanır, bu yüzden Android ve iOS için iki geliştirici gerekir. Ama arka taraftaki veri kısımları ve arayüz olmayan bütün kod Kotlin ile yazılır, bir framework olarak çıkarılır ve iOS'ta kütüphane olarak kullanılır. Öğrenciye göre bu çözüm cross-platform araçlardan daha native gibi çalışıyor ve iki-üç yıllık yeni bir çözüm.

Hoca ayrıca Google'ın Fuchsia adlı yeni bir işletim sistemi geliştirme niyetinden söz etti. Bir öğrenci Fuchsia'nın Flutter ile uyumlu olduğunu ekledi. Hocaya göre Fuchsia, Android'in bazı noktalarda yavaş kalması ve çok kaynak tüketmesi nedeniyle 2016'dan beri geliştirilen, ama henüz yaygınlaşmamış bir işletim sistemidir.

> **Hocanın vurgusu:** Bu alanda her gün yeni gelişmeler oluyor; hepsini takip etmek kolay değil. Kodlamayı sistem seviyesinden koparıp aynı zamanda performanslı kod üretmek için yeni diller ve platformlar çıkıyor. Ama temel dört yaklaşım değişmiyor; yalnız giderek cross-platform'a doğru kayılıyor.

## 8. Mobil İşletim Sistemi ile PC İşletim Sistemi Arasındaki Farklar

Bu bölümün slaytı şu maddeleri içeriyordu (ekrandan, 01:00:00):

- 1. Power: Android'de işlemci ve ekran varsayılan olarak kapanır. Bir süreç işlemciyi ya da ekranı açık tutmak istiyorsa bunları "wake-lock" ile özel olarak kilitlemelidir.
- 2. Interface: Temel giriş yöntemi dokunmatik ekrandır; tuş takımı, ses vb. ile desteklenir. Geleneksel pencere yöntemi ağırdır, bu yüzden katmanlar (layers) ve görünümler (views) kullanılır.
- 3. Memory: Android daha az bellek kullanmak üzere optimize edilmiştir; her uygulama en az RAM'e yüklenecek biçimde yapılandırılır. Linux çekirdeğinde "Out of memory" desteği zaten vardır, Android bunun üstüne kullanılmayan uygulamaları sonlandıran "Low memory killer"ı ekler. Framework'teki bütün kütüphaneler optimize edilmiştir; örneğin C kütüphanesi olarak glibc yerine bionic kullanılır.
- 4. Communication processor: Android, iletişim işlemcisi üzerinde çalışan ayrı, tescilli bir işletim sistemiyle haberleşir; masaüstü sistemlerde gerekmeyen GPRS/EDGE/3G/LTE desteklenir.
- 5. Portability: x86 masaüstü için yapılmıştır; mobil işletim sistemleri çoğunlukla gömülü sistemler için yapılmış ARM üzerinde çalışır. Çoğu işletim sistemi bütün donanım mimarilerine taşınmış olsa da bu mimarilerde optimize değildir.
- Kullanılabilir API'lerle sınırlılık.
- Mobil işletim sistemi masaüstünden çok daha kısıtlıdır.

### 8.1 Güç Yönetimi

Mobil işletim sisteminin PC'den en önemli farkı güç yönetimine ihtiyaç duymasıdır. Wake-lock mekanizmaları bu konuya hassasiyet gösterir ve arka plan işleri buna göre yönetilir. iOS baştan beri bu konuya hassastı; Android zaman içinde birçok yenilik getirdi.

**Soru:** Android Doze hakkında bilgisi olan var mı?

**Cevap (bir öğrenci):** Telefonu kullanmadığınız zamanlarda arka plan servislerinin daha seyrek uyanarak sorgulama yapmasını sağlar. Android 6-7 sürümlerinden sonra hayatımıza girdi ve her sürümde yeni bir yapılanmayla geliyor.

<!-- BELİRSİZ: 00:58:35 civarında altyazı kopuk; telefon hareketteyken (araçla seyahat, yürüyüş) Doze davranışının nasıl değiştiği tam anlaşılmıyor. -->

Hoca diğer güç önlemlerini sıraladı:

- Karanlık mod: bütün işletim sistemleri (mobil, PC, tablet, dizüstü) artık karanlık modu kullanıyor; özellikle telefonlarda ciddi güç kazancı sağlar.
- Ağ geçişi: eskiden elle değiştirmek gerekirdi; bugün işletim sistemi uygun ağı otomatik algılar ve baz istasyonundan Wi-Fi erişim noktasına geçer. Bu güç yönetimi için önemlidir.
- Ekran kontrolü: ekran iki biçimde kontrol edilir. Yakınlık (proximity) sensörü, telefonla konuşurken ekranı kapatır. Ortam ışığı sensörü, ışık azaldığında ekran parlaklığını düşürür, gün ışığında ekranın görünür olması için artırır. Bugün monitörlerde de bu özellik var, ama bir PC işletim sistemi için enerji açısından kritik değildir; mobil işletim sistemi ise bunları yönetmek zorundadır.

**Soru:** Güç yönetimiyle ilgili mobil işletim sisteminin varsayılan olarak yönettiği başka süreçler nelerdir?

**Cevap (bir öğrenci):** Arka plan servisleri ve ekranın güç tüketimi (karanlık mod) konuşuldu. Hoca buna ekran parlaklığı ve yakınlık sensörüyle yapılan kontrolü ekledi.

### 8.2 Arayüz: Dokunmatik Ekran ve Ses

PC'de fiziksel klavye ve fare kullanılırken mobilde dokunmatik ekranın çoklu dokunma (multi-touch) özelliği kullanılır. Hoca, Google'ın bir patent davası nedeniyle bir dönem Android'de çoklu dokunmayı destekleyemediğini anlattı: telefonların donanımı buna uygundu ama yazılım desteklemiyordu; dava sonuçlanınca bir güncellemeyle özellik eklendi. Bugün çoklu dokunmanın yanına derin dokunma da geldi: dokunmanın gücü, derinliği ve süresi de hesaba katılabiliyor. İşletim sistemi bu dokunuşları takip ederek hizmet sunar.

**Soru:** Bir uygulama geliştirici olarak kullanıcının telefonun hangi noktalarına dokunduğunu takip edebilir miyiz?

**Cevap (bir öğrenci):** Dolaylı yoldan. Doğrudan piksel düzeyinde değil, ekrana koyduğumuz bileşenlere dokunulduğunda bunu yorumlayarak.

Hoca, bunun kullanıcının uygulamadaki davranış örüntüsünü (pattern) izlemek için kullanılabileceğini ve bundan ciddi çıkarımlar yapılabileceğini söyledi. Örneğin video izlenirken videonun neresinde durulduğu, ne kadar süre izlendiği, ne kadar ara verildiği takip edilir.

**Soru:** Video izleme davranışını takip edenler neyin peşindedir?

**Cevap (bir öğrenci):** Daha doğru içerik ve kişiselleştirilmiş reklam.

Hoca bunu doğruladı: içeriği kişiye doğru vermek, içeriğin uzunluğundan reklamın uzunluğuna kadar; reklamda kalınıp kalınmadığını, ne kadar sonra geçildiğini, ilginç bir reklamın izlenmeye devam edilip edilmediğini takip etmek isterler. Telefonda da uygulamanın hangi menülerinin kullanıldığı ve nerelere sıklıkla bakıldığı incelenerek çalışmalar yapılabilir.

İnsan-bilgisayar etkileşimi açısından dokunmatik ekrana ek olarak ses de vardır. Birçok kişi metni sesle yazdırır.

**Soru:** Klavyeyle yazmak mı, metni söyleyerek ifade etmek mi daha hızlıdır?

**Cevap (bir öğrenci):** Söylemek daha hızlıdır, ama tanıma hataları yüzünden bazen 3-4 kez söylemek gerekebiliyor.

Hoca buradaki ödünleşimi vurguladı: ses, telefona daha hızlı bilgi aktarmayı sağlayan yeni bir insan-bilgisayar etkileşimi tekniğidir. Enerji açısından da metni yazarken harcanan süre ve ekranın açık kaldığı süre düşünüldüğünde, sesle yazdırma daha verimli hale geliyor gibi görünmektedir.

### 8.3 Bellek, İletişim ve Taşınabilirlik

Mobil işletim sistemlerinin belleği görece kısıtlıdır. Her etkinliğin (activity) bir yaşam döngüsü vardır; hangisinin arka planda kalacağına, hangisinin temizleneceğine karar vermek için özel bir yapı gerekir ve mobil işletim sistemleri bunu arka planda yönetir.

İletişimde, bulunulan noktaya bağlı olarak hangi iletişim tekniğinin seçileceği önemlidir ve işletim sistemi bunu otomatik takip eder.

Taşınabilirlik açısından mobil işletim sistemleri Intel mimarilerinde de çalışabilir. Android emülatörü test sırasında ARM işlemcili mi yoksa x86 mimarili bir yapı mı kullanmak istediğinizi sorar. Her mimarinin desteklenmesi önemlidir, ama bugün bu işletim sistemleri ağırlıklı olarak ARM için çalışır.

Mobil işletim sistemi tasarım ölçütlerinin bir kısmı daha önce konuşulmuştu: güvenlik çok önemlidir; kaynak yönetiminde özellikle güç ve iletişim yönetimine dikkat edilmelidir.

## 9. Mobil Uygulama Geliştirmede Kısıtlar: Veri Aktarımı ve Depolama

Slayttaki kısıtlar şunlardı (ekrandan, 01:10:00):

- Limited Battery (sınırlı pil)
- Less Resources (az kaynak): CPU, Memory, Storage, Battery
- Range x Bandwidth (menzil ve bant genişliği)
- Security Standards (güvenlik standartları)
- Potential Hazards (olası tehlikeler)

### 9.1 Verinin Merkeze Aktarım Zamanı

Mobil uygulama geliştirirken kaynaklar kısıtlıdır ve her zaman çevrim içi olunamaz. Bu yüzden saklama, depolama ve aktarım zamanına karar vermek gerekir. Basit uygulamalarda sorun yoktur, ama veri toplayan bir uygulamada verinin cihazdan merkeze aktarılma zamanı önemlidir. Belirleyici olan, verinin merkeze ne kadar acil aktarılması gerektiğidir.

Aciliyet yoksa tercih edilecek koşullar derste öğrencilerle birlikte dört madde olarak toplandı:

- 1. Telefon kullanılmıyorken: temel olarak gece yarısı.
- 2. Mümkünse Wi-Fi erişim noktasına bağlıyken: mobil veri kısıtlı olduğu için baz istasyonu üzerinden göndermemek.
- 3. Telefon şarja (bir güç kaynağına) bağlıyken: veri boyutuna bağlı olarak aktarım enerji tükettiği için. Bir öğrenci, işletim sistemi güncellemesinin en az yüzde 50 şarj ya da şarja bağlı olmayı istemesini benzer bir örnek olarak verdi.
- 4. Arka planda çalışmasına izin verilmeyen uygulamalarda: uygulama her açıldığında veriyi arka planda göndermek.

Bazen bu lüks yoktur ve veri anlık gönderilmek istenir. Bu durumda dakikalık, beş dakikalık ya da saatlik periyotlar seçilebilir.

### 9.2 Yarıda Kalan Aktarım

Aktarım sırasında bağlantı sorunu çıkarsa veri belirli bir yerde depolanmalı ve bağlantı tekrar sağlandığında aktarım kaldığı yerden devam etmelidir. Hoca, bunun temel görünse de uygulamalarda sık ihmal edildiğini, hatanın hangi noktada oluştuğu kaydedilmediği için bütün verinin yeniden yüklendiğini söyledi.

Hocanın sayısal örneği:

- Verilen: gönderilecek toplam veri 10 MB; bağlantı koptuğunda 8 MB gönderilmiş.
- Doğru davranış: kalan $10 - 8 = 2$ MB gönderilir.
- Yanlış davranış: aktarım baştan başlatılır ve yeniden 10 MB gönderilir; daha önce giden 8 MB kullanıcının veri planından boşa harcanmış olur.

> **Hocanın vurgusu:** Bağlantı sorunlarında ve verinin ne sıklıkla aktarılacağına karar verirken bu noktalara dikkat edilmeli; kopan aktarımı baştan göndermek anlamlı bir iş değildir.

### 9.3 Bağlantı Türleri Arasında Geçiş

**Soru:** 2G, 3G ve LTE arasında geçiş yapmak düşünülebilir mi? Örneğin gün içinde LTE yerine bir süre 3G ya da 2G'ye bağlı kalmak?

**Cevap (bir öğrenci):** İşletim sistemi yazıyor olsaydım düşünürdüm; gerek olmayan anlarda LTE kullanmak güç tüketimini etkiler.

Hoca buradan devam etti. Güç (power) açısından bakıldığında, sinyal başına LTE'nin çektiği güç 2G ve 3G'den fazladır. Ama enerji açısından değerlendirildiğinde gönderilecek verinin boyutu önemlidir: LTE daha hızlı gönderdiği için büyük bir veri aktarılıyorsa toplam enerji tasarrufu LTE ile daha yüksek olur. Veri gönderimi çok sık değilse ve boyutu büyük değilse, günün büyük bölümünde diğer bağlantılarla bağlı kalmak enerji tüketimini olumlu etkiler. Bu yüzden işletim sisteminin bağlantılar arasında geçişi yönetebilmesi önemli bir özellik olarak düşünülebilir.

> **Ek bilgi (derste anlatılmadı):** Güç anlık harcama hızıdır (watt), enerji ise gücün süreyle çarpımıdır (joule = watt × saniye). Bu yüzden anlık gücü yüksek ama aktarımı kısa süren bir bağlantı, toplamda daha az enerji harcayabilir.

### 9.4 Veri Depolama: iOS ve Android

**Soru:** Veri depolama açısından iOS ile Android arasındaki temel fark nedir?

**Cevap (bir öğrenci):** iOS'ta uygulamalar için Apple'ın ayırdığı bir iCloud alanı her zaman vardır ve geliştiriciler bunu doğrudan kullanabilir; Android'de bu cihazdan cihaza değişir.

Hoca cihaz donanımı açısından düşünmeyi istedi ve şunu ekledi: Android'de (eskiden daha yaygındı) cihaza bağlı olarak harici bir flash bellek kullanılabilir, depolama genişletilebilir. iOS ise depolamayı tek bir yapıda sunar ve büyütmeye ya da müdahale etmeye izin vermez. Bu, iki platformda uygulama geliştirirken farklı stratejiler gerektirir.

**Soru:** Android'de hangi tür uygulamada dahili depolama yerine eklenen harici flash belleği tercih edersiniz?

**Cevap (bir öğrenci):** Fotoğraf gibi şeyler dışarıya konabilir; ayarlar gibi küçük, temel şeyleri dahili belleğe koyardım.

Hoca bunu tamamladı: güvenlik kaygısı varsa dahili depolama kullanılır. Ortak kullanım, özellikle uygulamalar arası paylaşım söz konusuysa harici depolama kullanılabilir. Harici belleğin en büyük sorunu fiziksel olarak çıkarılabilir olmasıdır; bu bütün işleyişi bozabilir. Ayrıca dışarıdan erişilebilir ve değiştirilebilir (manipüle edilebilir) olması bir güvenlik sorunudur. Buna karşılık büyük boyutlu verileri saklamak için katkı sağlar.

Depolama alanları yeterince büyüdüğü için genişletme artık çok kritik değildir. Ama Android bu imkanı hâlâ sunduğu için dosya yönetiminde Android'in public directory ve private directory kavramlarını bilmek gerekir. Harici bellekte tanımladığınız dizin türüne bağlı olarak, uygulama kaldırıldığında verinin saklanmaya devam etmesi ya da silinmesi gibi seçenekler vardır. Bunları bilinçli yönetmek, mobil cihazlarda veri yönetimi açısından kritiktir.

> **Ek bilgi (derste anlatılmadı):** Büyük olasılıkla burada kastedilen, Android'de uygulamaya özel dizinlerin (uygulama kaldırılınca silinen) ile paylaşılan ortak dizinlerin (uygulama kaldırılsa da kalan) ayrımıdır. Yeni Android sürümlerinde harici depolamaya erişim "scoped storage" ile daha da kısıtlanmıştır.

## Örnek Sorular

Aşağıdaki sorular derste sözlü olarak soruldu.

**1.** (derste sözlü, 00:17:50) Just-in-time ve ahead-of-time derleme nedir? Android bu ikisini nasıl kullanır?

> **Cevap (derste verildi):** JIT'te kod uygulama çalışırken dönüştürülür/yorumlanır; yavaş ve kaynak tüketicidir. AOT'de kod uygulama indirilip kurulurken dönüştürülür; açılış hızlanır, ama kurulum uzar ve uygulama daha çok yer kaplar. Android bugün ikisini birlikte kullanır.

**2.** (derste sözlü, 00:19:43) APK ile Android App Bundle arasındaki fark nedir?

> **Cevap (derste verildi):** APK bütün cihazlar için gerekli her şeyi taşıyan, büyük ve kurulumu uzun bir pakettir. App Bundle'da market, telefonun özelliklerine bakıp yalnız o cihaza gereken parçaları gönderir; indirme ve kurulum hızlanır, kaplanan yer azalır.

**3.** (derste sözlü, 00:27:26) Emülatör ile simülatör arasındaki fark nedir?

> **Cevap (derste verildi):** Emülatör donanımı bütün özellikleriyle birebir taklit eder; yazması zordur ve pahalıdır. Simülatör davranışı yaklaşık olarak modeller ve yalnız genel bir fikir verir.

**4.** (derste sözlü, 00:38:17) Cross-platform araçların hâlâ süren dezavantajı nedir?

> **Cevap (derste verildi):** Kodu iOS ve Android'e çeviren ara katman nedeniyle native SDK'ların performansına, kaynak ve pil verimliliğine birebir ulaşılamaz. Katman sayısı arttıkça performans düşer; bugün bu kayıp eskisine göre küçüktür.

**5.** (derste sözlü, 00:41:31) Bir cross-platform araç geliştirecek olsanız nelere dikkat edersiniz?

> **Cevap (derste verildi):** Güncel işletim sistemlerini desteklemek, iki platformun arayüzüne yakın UI bileşenleri sunmak, güvenlik açığı vermemek, düşük güç tüketen kod üretmek, az ek kod eklemek, yerleşik özelliklere erişim sağlamak.

**6.** (derste sözlü, 00:45:40) Bir mobil uygulama kaç farklı teknikle geliştirilebilir?

> **Cevap (derste verildi):** Dört: native development, cross-platform development, hybrid app development ve mobile web development.

**7.** (derste sözlü, 00:47:26) Hybrid app development'ın cross-platform'dan farkı nedir?

> **Cevap (derste verildi):** Cross-platform'da kod native'e dönüştürülür. Hybrid'de web uygulaması native bir konteynere konur ve telefonun WebKit'i tarafından yorumlanarak çalışır.

**8.** (derste sözlü, 01:02:20) Bir uygulama geliştirici, kullanıcının telefonun hangi noktalarına dokunduğunu takip edebilir mi? Bu bilgi ne için kullanılabilir?

> **Cevap (derste verildi):** Doğrudan piksel düzeyinde değil, dolaylı olarak, ekrandaki bileşenlere dokunuşlar üzerinden. Bu bilgi kullanıcı davranış örüntüsünü çıkarmak, içeriği ve reklamı kişiselleştirmek için kullanılabilir.

**9.** (derste sözlü, 01:08:47) Veri toplayan bir uygulamada aciliyet yoksa veri merkeze hangi koşullarda gönderilmelidir?

> **Cevap (derste verildi):** Telefon kullanılmıyorken (gece), Wi-Fi'ye bağlıyken, şarja bağlıyken; arka planda çalışmasına izin verilmeyen uygulamalarda ise uygulama açıldığında.

**10.** (derste sözlü, 01:11:54) 2G, 3G ve LTE arasında geçiş yapmak enerji açısından anlamlı mıdır?

> **Cevap (derste verildi):** LTE anlık olarak daha çok güç çeker, ama büyük veriyi kısa sürede gönderdiği için toplam enerjide daha verimli olabilir. Veri seyrek ve küçükse günün çoğunda düşük güçlü bağlantıda kalmak enerji tasarrufu sağlar; bu yüzden işletim sisteminin geçişi yönetebilmesi faydalıdır.

**11.** (derste sözlü, 01:15:20) Android'de dahili depolama yerine harici flash belleği hangi durumda tercih edersiniz?

> **Cevap (derste verildi):** Paylaşılan ya da büyük boyutlu veri (örneğin fotoğraf) için harici bellek; güvenlik gerektiren ve küçük temel veriler (örneğin ayarlar) için dahili bellek. Harici bellek çıkarılabilir ve dışarıdan erişilebilir olduğu için risklidir.

## Dersin Toparlaması

Bu derste önce üç mobil işletim sisteminin katmanlı mimarisi incelendi: Android'de Linux çekirdeğinin üstünde kütüphaneler ve Android Runtime, onun üstünde uygulama çatısı ve uygulamalar; iOS'ta çekirdek ve sürücüler, Core OS, Core Services, Media ve Cocoa Touch; KaiOS'ta Gonk, Gecko, Web API ve ön yüz. Android'in çalışma ortamının Dalvik'ten ART'ye, derleme stratejisinin JIT'ten AOT'ye ve karma yapıya, paketlemenin APK'dan App Bundle'a evrimi anlatıldı. iOS ile Android'in geliştirici ekosistemi ve emülatör-simülatör ayrımı üzerinden iki platformun farklı stratejileri karşılaştırıldı.

Ardından mobil uygulama geliştirmede dört teknik (native, cross-platform, hybrid, mobile web) ele alındı; cross-platform araçların ara katman nedeniyle yaşadığı performans kaybı ve iyi bir aracın taşıması gereken özellikler konuşuldu. Son bölümde mobil işletim sisteminin PC'den farkları (güç, arayüz, bellek, iletişim işlemcisi, taşınabilirlik) ve mobil uygulama geliştirmenin kısıtları işlendi: veri aktarım zamanlaması, kopan aktarımın sürdürülmesi, bağlantı türleri arasında güç ve enerji ödünleşimi ve depolama stratejisi. Hoca, bir sonraki derste bu konunun bitirilip yeni bir konuya geçileceğini söyledi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
