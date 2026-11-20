# Ders 12 Genişletilmiş Notu: Arka Plan İşleri (Background Tasks), WorkManager ve Servisler

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Ana Thread ve Arka Plan İşleri
- 2. Neden Arka Plan İşleme?
- 3. Arka Plan İşlemenin Zorlukları ve Android'in Kısıtları
- 4. App Standby Buckets
- 5. Doğru Çözümü Seçmek İçin Sorular
- 6. Arka Plan İşinin Tanımı ve Türleri
- 7. İş Türüne Göre Önerilen Çözümler
- 8. Alarmlar ve AlarmManager
- 9. Foreground Servisler ve WorkManager
- 10. Servisler
- 11. Cihazı Uyanık Tutmak: Ekran ve CPU
- Örnek Sorular
- Dersin Toparlaması

## 1. Ana Thread ve Arka Plan İşleri

Bu derste Android'de arka plan işlerinin (background tasks) nasıl yönetildiği ve bunun için hangi yapıların bulunduğu konuşuldu. Ders kuramsal anlatımla yürüdü; konuyla ilgili uygulama kısmı bu derste yapılmadı. Hoca bu konunun bir giriş dersinde ayrıntısıyla öğretilemeyeceğini, ama birçok uygulamanın ana thread'de yapılamayacak kadar uzun süren işler içerdiği için ne olup bittiğini bilmenin önemli olduğunu, ayrıntıların ayrıca çalışılması gerektiğini söyledi.

Başlangıç noktası şudur (ekrandan, 00:15:00):

- Her Android uygulamasının bir ana thread'i vardır. Bu thread arayüzü yönetir (view'ların ölçülmesi ve çizilmesi dahil), kullanıcı etkileşimlerini koordine eder ve yaşam döngüsü olaylarını alır.
- Bitmap decode etme, diske erişme ya da ağ isteği yapma gibi uzun süren hesaplama ve işlemler ayrı bir arka plan thread'inde yapılmalıdır.
- Genel olarak birkaç milisaniyeden uzun süren her şey bir arka plan thread'ine devredilmelidir.

Hoca, servisler dışındaki bütün uygulamalarda bir arayüz bulunduğunu, bu yüzden bir ana thread ile karşılaşıldığını ve bu thread'in belirli bir yaşam döngüsü içinde yaşadığını hatırlattı. Saniyeler mertebesine çıkan işler kullanıcı deneyimini bozmamak için başka mekanizmalarla yönetilmelidir. Java'dan bilinen Thread kütüphanesi ve Kotlin tarafındaki coroutine'ler, o anda yapılacak ve kullanıcının başlattığı arka plan işleri için temel araçlardır; ama derste bunların dışında başka yapılar da konuşuldu.

Arka plan thread'ine taşınması gereken işlere örnekler:

- bir resmin işlenmesi, decode ya da encode edilmesi,
- disk biriminden bilgi taşınması ya da oraya bilgi yazılması,
- buluta ya da bulut olmayan uzaktaki bir birime veri gönderilmesi veya oradan veri alınması.

Bunların hepsi farklı thread'lerce yürütülmesi gereken asenkron işlerdir. Kullanıcı bir butona basmak için ana thread'deki işin bitmesini beklememelidir. Arka planda yürüyen bütün işlere genel olarak **background processing** denir ve burada birden fazla thread olabilir. Çok çekirdekli işlemcilerde daha fazla thread'e ulaşılabilir; ama tek çekirdekli işlemcili bir telefonda da aynı ilkeler geçerlidir. Çünkü telefon tarafında işi thread'e ayırmanın asıl nedeni kullanıcının o anki etkileşimini kesintisiz sürdürebilmektir. Hoca, masaüstü uygulamalarında thread'lerin daha farklı amaçlarla ortaya çıktığını, telefonda ise işlerin kullanıcı deneyimini aksatmadan asenkron yürütülmesi için kullanıldığını vurguladı.

> **Hocanın vurgusu:** Belirli bir milisaniyenin üzerinde süren bir iş söz konusuysa mutlaka arka plan thread'i ile çözülmelidir.

## 2. Neden Arka Plan İşleme?

Slaytta üç gerekçe sayıldı (ekrandan, 00:20:00):

- G/Ç (I/O) olaylarının arayüzü bloklamasını ve ünlü "Application Not Responding" iletişim kutusunu önlemek. Donan bir uygulama kötü kullanıcı deneyimi demektir.
- HTTP çağrıları gibi bazı işlemlerin ana thread'de çalışmasına izin verilmez.
- Performansı artırmak.

Bir uygulama belli bir süre bloklanırsa "Application Not Responding" (ANR) metnini içeren bir iletişim kutusu açılır; kullanıcı onu kapatana kadar bir şey yapamaz ve uygulama sonlanabilir. Hoca, yanlış hatırlamıyorsa Android'de yaklaşık 5 saniyelik bir bloklamanın bu hatayı ürettiğini söyledi. Aynı iş ayrı bir thread'de yürüseydi bu hatayla karşılaşılmazdı. HTTP çağrıları, indirilen dosyalar gibi işler mutlaka ana thread'den ayrı yapılmalıdır ki karşı sayfadaki bilgiler ya da bir dosya indirilirken arayüz bloklanmasın.

Performans tarafında ise ön planda sürdürülmeyecek, hatta ekranın aktif olmasını gerektirmeyen arka plan işleri Android'de özellikle **servis** bileşeniyle yönetilir.

## 3. Arka Plan İşlemenin Zorlukları ve Android'in Kısıtları

Arka plan işleri cihazın RAM ve pil gibi sınırlı kaynaklarını tüketir; doğru yönetilmezse kullanıcı deneyimi kötüleşir (ekrandan, 00:25:00). Hoca, uygulamalar her şeyi keyfince arka plana atıp çalıştırsaydı telefonun şarjının çok kısa sürede tükeneceğini söyledi. Android'in eski sürümlerine (6, 7, 8) göre bugün 14 beta konuşulurken ve kararlı sürüm 13 iken, pil tüketiminin kötüleşmesi beklenirdi; oysa iyileşme konuşuluyor. Bunun temel nedeni, arka plan işlerinde iOS'a göre cömert davranan Android'in zamanla iOS'un çizgisinde ilerleyip arka plan işlerini kısıtlama ve yönetme konusunda daha gelişkin çözümler aramasıdır.

Slayttaki sürüm tarihçesi (ekrandan, 00:25:00):

- **Android 6.0 (API 23):** Doze modu ve App Standby geldi. Doze, ekran kapalı ve cihaz hareketsizken uygulama davranışını kısıtlar. App Standby kullanılmayan uygulamaları ağ erişimlerinin, job'larının ve senkronizasyonlarının kısıtlandığı özel bir duruma koyar.
- **Android 7.0 (API 24):** örtük (implicit) broadcast'ler kısıtlandı ve Doze-on-the-Go geldi.
- **Android 8.0 (API 26):** arka plan davranışı daha da kısıtlandı; örneğin arka planda konum alma ve önbellekteki wakelock'ların bırakılması.
- **Android 9 (API 28):** App Standby Buckets geldi; uygulamaların kaynak istekleri kullanım örüntüsüne göre dinamik olarak önceliklendirilir.

<!-- BELİRSİZ: 00:23:09-00:23:36 arasında altyazı boş; Doze'un ilk anlatımının başı kayıtta yok. Sürüm bilgileri slayttan alındı. -->

### 3.1 Doze ve Doze-on-the-Go

Doze, cihazın kullanılmadığını işletim sistemi düzeyinde takip eder: telefonun hareketsiz olduğunu IMU sensörlerinden ya da jiroskoptan anlar, ekranın kapalı olduğunu da bilir. Bu durumda özellikle kullanılmayan uygulamaların arka plan işlerini kısıtlar. Android 7 ile gelen Doze-on-the-Go, telefon yalnız masada dururken değil, cepte ya da çantada hareket ederken de ekranı kapalıysa telefona acil erişim olmadığı varsayımıyla arka plan işlerini en aza indirir.

Hoca bunu mesajlaşma uygulamalarıyla somutlaştırdı: WhatsApp, Telegram gibi uygulamalarda telefonu kullanmadığınız anlarda mesaj kontrolü sayısı azalır. Örneğin saniyede bir yapılan kontrol 5 saniyede, 10 saniyede, yarım dakikada bire düşer. Böylece telefonun sürekli uyanmasına gerek kalmaz. Hoca, daha gelişkin çözümlerin sonraki slaytlarda geleceğini, bu yapının gelişiminin "nereden daha fazla kısarız" sorusuyla adım adım ilerlediğini söyledi.

### 3.2 Broadcast Receiver ve konum kısıtları

Broadcast receiver'lar da bir arka plan işidir. Daha önceki derslerde konuşulduğu gibi, uygulama içi bir mesajlaşma söz konusuysa LocalBroadcastManager kullanılmalıdır. Takip edilmesi gerekmeyen sistem seviyesindeki bir değişikliğe abone olmak her zaman telefona yük getirir; bunlar için ayrıca özel izinler vardır ve kullanıcı izin vermedikçe uygulamaya ne yazılırsa yazılsın broadcast receiver aktif edilmez. Her arka plan takibi hem kaynak hem pil tüketimi açısından sorun yaratabilir.

Android 8 ile özellikle arka plandaki konum değişikliği bilgisinin toplanmasına kısıtlar geldi. Eskiden düşük sürümlerde bir servis çalıştırarak arka planda sürekli konum takibi yapılabiliyor ve bunun hiçbir düzenlemesi yoktu. Artık bu tür takip ancak belirli kurallara uyularak yapılabilir. Android 9 ile de daha akıllı bir yapı olan App Standby Buckets ortaya çıktı.

## 4. App Standby Buckets

App Standby Buckets, Android 9 ile gelen bir pil yönetimi özelliğidir. Uygulamalar kullanım sıklıklarına göre kategorilere ayrılır, farklı kovalara (bucket) yerleştirilir ve istekleri bu önceliğe göre karşılanır. Hoca kovaların sayısını 5 olarak verdi. Yerleştirme sistem tarafından dinamik ve otomatik yapılır; bir uygulama kullanım sıklığına bağlı olarak zamanla bir kovadan diğerine geçebilir. Kullanıcının uygulamayı ne sıklıkla kullandığı takip edilerek yerleştirmeyi bir makine öğrenmesi yapısı gerçekleştirir. Bunlara ek olarak, indirilmiş ama hiç açılmamış uygulamalar için ayrı, özel bir kova vardır; hoca Android'de çok sık uygulama indirildiğini ve bazılarının hiç açılmadığını hatırlattı.

<!-- BELİRSİZ: Hoca kova sayısını 5 olarak verdi ama derste dört kova (Active, Working set, Frequent, Rare) ve hiç açılmamış uygulamalar için özel bir kova anlatıldı; beşinci kovanın adı altyazıda geçmiyor. -->

### 4.1 Active

Slayttaki tanım (ekrandan, 00:30:00): Kullanıcı uygulamayı o anda kullanıyorsa ya da çok yakın zamanda kullandıysa uygulama **active** kovasındadır. Örnekler:

- uygulama bir aktivite başlatmıştır (ör. launcher'dan yeni açılmış bir aktivite),
- uygulama bir foreground servis çalıştırmaktadır,
- uygulamanın, ön plandaki bir uygulamanın kullandığı bir content provider ile ilişkili bir sync adapter'ı vardır (karşı tarafla veri senkronizasyonu yapan uygulama),
- kullanıcı uygulamanın bir bildirimine tıklamıştır.

Uygulama active kovasındaysa sistem uygulamanın job'larına, alarmlarına ve FCM mesajlarına hiçbir kısıt koymaz.

### 4.2 Working set

Çok sık kullanılan ama şu anda aktif olmayan uygulamalar working set'tedir. Slayt örnek olarak sosyal medya uygulamasını veriyordu. Hoca sosyal medya denince akla farklı uygulamaların gelebileceğini söyledi: WhatsApp gibi anlık mesajlaşma uygulaması çok sık kullanılır; Twitter ise kimi insanlarca sürekli aktif kullanılırken, belirli bir sıklıkta kullanılıyorsa working set'e konur. Bu kovadaki uygulamaların istekleri daha az engellenir; görece ılımlı kısıtlar uygulanır ve arka plan işleri daha rahat yapılabilir. Android'in yaklaşımı şudur: bir fedakârlık gerekiyorsa bu, bu kovadaki uygulamalardan değil, daha az kullanılan uygulamalardan yapılmalıdır.

### 4.3 Frequent

Belirli periyotlarla ama her gün kullanılmayan uygulamalar **frequent** kovasındadır. Örnek: haftada iki üç gün kullanılan bir egzersiz ya da fitness uygulaması. Bu uygulamalar arka planda daha sert tedbirlere maruz kalır; çünkü az kullanılan bir uygulamanın zaten arka plan işine talip olmaması gerekir. Android'in mantığı şudur: kullanıcının çok kullanmadığı bir uygulamanın arka planda sürekli bir şey yapmasına izin verilirse hem kaynak ve pil tüketimi çok yükselir hem de uygulama belki kötü amaçla hareket ediyordur. Bu yüzden kısıt getirilir.

### 4.4 Rare

Seyrek kullanılan uygulamalar: seyahatte kullanılan bir otel uygulaması ya da TripAdvisor gibi bir gezi uygulaması; altı ayda, yılda ya da iki üç ayda bir kullanılan uygulamalar. Bunların arka plan işleri çok daha katı kurallarla yönetilir.

### 4.5 Google'ın tavsiyeleri

Slayttaki "Best Practices" maddeleri (ekrandan, 00:35:00):

- Uygulamanızı bir kovaya ya da diğerine sokmak için sistemi manipüle etmeye çalışmayın. Sistemin kovalama yöntemleri değişebilir ve her cihaz üreticisi kendi algoritmasını yazabilir. Bunun yerine uygulamanız hangi kovada olursa olsun düzgün davransın.
- Uygulamanın launcher aktivitesi yoksa hiçbir zaman active kovasına yükseltilmeyebilir; uygulamayı böyle bir aktivitesi olacak şekilde yeniden tasarlamak gerekebilir.
- Uygulamanın bildirimleri etkileşimli (actionable) değilse kullanıcı bildirimlerle etkileşerek uygulamayı active kovasına yükseltemez. Bu durumda bazı bildirimleri kullanıcının yanıt verebileceği şekilde yeniden tasarlamak gerekebilir (Material Design bildirim tasarım kalıpları).
- Benzer şekilde, uygulama yüksek öncelikli bir FCM mesajı aldığında bildirim göstermezse kullanıcıya etkileşim şansı vermez ve active kovasına yükselemez. Yüksek öncelikli FCM mesajlarının tek amacı kullanıcıya bildirim göndermektir. Bir FCM mesajı uygunsuz biçimde yüksek öncelikli işaretlenirse kotanın tükenmesi gibi olumsuz sonuçlar doğabilir; gerçekten acil mesajlar normal öncelikli işlenebilir.

Hoca bu maddeleri şöyle açıkladı: kovalar arasındaki geçişleri sistem kendisi takip eder. Kullanıcı, kullanım sıklığını artırarak bir değişiklik yapabilir; ama geliştiricinin "benim uygulamam daha üst kovada olsun" diye manipülasyona gitmemesi gerekir. Kullanıcıyla etkileşimde olan her uygulamanın zaten bir launcher aktivitesine ihtiyacı vardır. Ayrıca uygulamanın bildirimler üzerinden tetiklenmesi, uygulamanın active kovasında yer almasını sağlar. Bunlar yapılmazsa uygulama en fazla frequent ya da working set seviyesine kadar çıkabilir.

> **Hocanın vurgusu:** Kova yapısı Android'in kontrolündedir ve geliştiricinin yapabileceği çok şey yoktur; ama bu yapı bilinirse uygulamanın active konuma nasıl gelebileceğine dair ipuçları unutulmaz.

## 5. Doğru Çözümü Seçmek İçin Sorular

Kovaların bir tarafı sistemdir; öbür tarafı geliştiricinin hangi tür arka plan işine ihtiyaç duyduğudur. Hoca bir arka plan işini tasarlarken şu soruların cevaplanması gerektiğini anlattı:

- **Kullanıcı işe dahil mi?** Örneğin bir müzik uygulamasında kullanıcı müziği başlatır ve durdurur; bu kullanıcı müdahalesi gerektirir. Öte yandan başka bir uygulama arka planda belli saatlerde verileri buluta taşımak ya da buluttan dosya indirmek isteyebilir; bu günlük, haftalık ya da aylık olabilir. Hoca, ileride makine öğrenmesiyle yapılan işler çoğaldıkça telefonların modelleri belli periyotlarla uzak sunuculardan güncelleyeceğini örnek verdi.
- **İş bölünebilir mi?** Çok büyük bir dosya indiriliyorsa ve dosyanın parça parça inmesinde sakınca yoksa, kaldığı yerden devam edebiliyorsa iş parça parça yönetilebilir. Dosyanın tek seferde inmesi gerekiyorsa iş kesintisiz yapılmalıdır.
- **İş ertelenebilir mi?** İş kullanıcı butona bastığında hemen mi olmalı, yoksa "telefon Wi-Fi'ye ya da şarja bağlandığında yap, benim için fark etmez" denebilir mi?

Slaytta sorulmaya devam eden sorular (ekrandan, 00:40:00):

- **İş sistem koşullarına bağlı mı?** İşin yalnız cihaz güce bağlıyken ya da internet bağlantısı varken çalışması istenebilir. Slayt örneği: uygulamanın sakladığı veriyi periyodik olarak sıkıştırması gerekiyorsa, kullanıcıyı etkilememek için bu iş yalnız cihaz şarj olurken ve boştayken yapılmalıdır. Hoca ekledi: bir işi baz istasyonu üzerinden, hücresel ağdan yapmak istemeyebilirsiniz; uzun sürecek bir iş için telefonun belli bir şarj seviyesinin üstünde olmasını beklersiniz.
- **İş hassas kullanıcı verisi topluyor ya da kullanıyor mu?** Örneğin bir navigasyon uygulamasında yol tarifi vermek için, kullanıcının başlattığı navigasyonu sürdürmek üzere bir foreground servis kullanılabilir. Hoca bunun en çok konum işlerinde karşımıza çıktığını ve hangi hassasiyette konum bilgisine ihtiyaç duyulduğunun da önemli olduğunu söyledi.
- **İş kesin bir zamanda mı çalışmalı?** Bir takvim uygulaması kullanıcının bir etkinlik için belli bir saatte hatırlatıcı kurmasına izin verebilir; kullanıcı bildirimi doğru zamanda görmeyi bekler. Diğer durumlarda uygulama işin tam ne zaman çalıştığını umursamayabilir; "önce Job A, sonra Job B, sonra Job C çalışmalı" gibi genel gereksinimler olabilir ama belirli bir zaman gerekmez.

Hoca kesin zaman örneğini açtı: saat 12'de bir hatırlatma ya da takvime kurulmuş bir toplantı, belki bir yaşlının ilaç alma saati. Gerçekten 12'de hatırlatılması gerekiyorsa AlarmManager gibi yapılar vardır ve bunlar sistem tarafında oluşturulmalıdır. "O zaman her şeyi AlarmManager ile yapalım" denebilir; ama AlarmManager adanmış (dedicated) bir yapı olduğu için arka planda ne kadar çok alarm tanımlanırsa sistem o oranda CPU'yu ayakta tutmak ve her an o zaman dilimini kontrol etmek zorunda kalır. Bu da çok daha hızlı pil tüketimine yol açar.

Bu yüzden Android son birkaç sürümdür şunu yapar: işin net bir zamanı yoksa ve belli bir zaman aralığında gerçekleşmesi yetiyorsa, sistem bu işleri kendisi organize eder, birden fazla işi bir araya getirir ve kaynakları çok daha verimli kullanarak arka plan işlerini yönetir. Hoca bunu Android'in son dönemde sunduğu önemli yapılardan biri olarak niteledi. **Job Scheduler** üzerinden job'lar yaratılabilir; job çalıştığında ve durduğunda ne yapılacağı belirlenebilir. Job Scheduler aslında bir servis olarak çalışır ama sınıflar üzerinden bir arayüz de sunarak kendi job'larınızı planlamanızı sağlar. Bunun üstünde, farklı bir katmanda konumlanan **WorkManager** gibi yapılar geliştiricinin işini daha da kolaylaştırır.

## 6. Arka Plan İşinin Tanımı ve Türleri

### 6.1 Tanım

Slayttaki tanım (ekrandan, 00:45:00): Bir uygulama, şu iki koşulun ikisi de sağlandığında arka planda çalışıyor sayılır:

- Uygulamanın aktivitelerinden hiçbiri o anda kullanıcıya görünmüyordur.
- Uygulama, kendi aktivitelerinden biri kullanıcıya görünürken başlatılmış bir foreground servis çalıştırmıyordur.

Aksi hâlde uygulama ön planda (foreground) çalışıyordur.

Hoca ikinci koşulu bir müzik uygulamasıyla açıkladı: bildirim çubuğunda çalan bir müzik dinleme uygulaması ya da benzeri bir servis varsa, uygulama arka plan işi olarak adlandırılmaz. Foreground servisler de ana thread'den ayrılan işleri temsil eder; ama kullanıcı etkileşimine açık oldukları ve kullanıcının o hizmetten yararlandığı bilindiği için Android bu servislere dokunmaz. Hiçbir kullanıcı etkileşimi yoksa, Android'in ilk ortadan kaldırdığı yapılar arka plan servisleri olur.

### 6.2 Üç kategori ve kalıcılık

Arka plan işleri üç ana kategoriye ayrılır (ekrandan, 00:45:00):

- **Immediate:** hemen çalışması ve kısa sürede tamamlanması gerekir.
- **Long Running:** tamamlanması biraz zaman alabilir.
- **Deferrable:** hemen çalışması gerekmez, ertelenebilir.

Bu üç kategorideki işlerin her biri ayrıca şunlardan biri olabilir:

- **Persistent work:** uygulama yeniden başlasa ve cihaz yeniden açılsa da planlanmış kalır; tekrar tekrar çalışabilir.
- **Impersistent work:** süreç bittiğinde artık planlanmış değildir; yeniden çalışmasına ihtiyaç yoktur, oturum tamamlanınca yenilenmez.

Dersin ikinci bölümü bu sınıflandırmanın tekrarıyla açıldı: temelde üç grup vardır (hemen yapılması gerekenler, uzun sürmesi beklenenler, ertelenebilenler); persistent kalıcı ve tekrar eden işleri, impersistent tek seferlik işleri anlatır.

## 7. İş Türüne Göre Önerilen Çözümler

### 7.1 WorkManager ve genel tavsiye

Bu noktada karşımıza **WorkManager** çıkar. Hocanın anlatımıyla WorkManager, Android'in yeni sürümlerinde tanıttığı, daha önce söz edilen JobScheduler servisinin üzerine oturan ve geliştiricinin kolay kullanmasını sağlayan bir yapıdır. Android'in genel tavsiyesi:

- Tekrar eden (persistent) bütün işler WorkManager ile yönetilmelidir.
- Hemen gerçekleşecek ve tek seferlik işler için ya Kotlin coroutine'leri ya da Java kullanılıyorsa thread kütüphanelerinden ExecutorService ya da bilinen thread yapıları kullanılmalıdır; ileride RxJava kütüphanesi de görülecektir.
- Ertelenebilir ve uzun sürecek işler için mutlaka WorkManager kullanılmalıdır.
- Impersistent uzun işler ve ertelenebilir tek seferlik işler için de WorkManager ile hareket edilmesi ve bunun persistent olarak kurgulanması beklenir.

> **Ek bilgi (derste anlatılmadı):** WorkManager, Android Jetpack'in bir kütüphanesidir; büyük olasılıkla platformun belli bir sürümüyle değil, ayrı bir kütüphane olarak dağıtılır ve eski API seviyelerinde de çalışır. Altta cihazın sürümüne göre JobScheduler gibi sistem mekanizmalarını kullanır.

### 7.2 Immediate Work

Kullanıcının hemen olmasını istediği ve o işin sonunda yoluna devam edeceği bir yapı söz konusuysa bu **immediate work**'tür. Hoca örnek verdi: kullanıcının ilerlemesi için bir dokümanın indirilmesi gerekiyorsa ya da bir test içinde bir soruya cevap vermek için ilgili video veya görüntünün indirilmesi gerekiyorsa o iş hemen yapılmalıdır.

Slayttaki tanım ve öneriler (ekrandan, 01:05:00):

- Immediate work, hemen çalışması gereken işleri kapsar. Bunlar kullanıcı için önemlidir ya da başka türlü daha sonraya ertelenemez. Uygulama kapansa ya da cihaz yeniden başlasa bile hızlıca çalıştırılmak üzere planlanmış kalmaları gerekebilecek kadar önemli olabilirler.
- **Persistent immediate work** için WorkManager ile bir `OneTimeWorkRequest` kullanılmalıdır; WorkRequest `setExpedited()` ile hızlandırılır.
- **Impersistent immediate work** için Kotlin coroutine'leri kullanılmalıdır. Uygulama Java kullanıyorsa RxJava ya da Guava kullanılmalıdır; Executors da kullanılabilir.

<!-- BELİRSİZ: 01:04:58-01:05:13 arasında altyazı kopuk; hocanın immediate work için önerdiği ilk yapının adı duyulmuyor. Öneriler slayttan alındı. -->

**Executor Service.** Hoca, Executor Service denince aslında bir thread havuzunun (thread pool) kastedildiğini açıkladı. Executor'lar yardımıyla iş bu havuza atanır ve sistemin ilgili mekanizmayı kullanarak havuzdan thread çekmesi beklenir. Bu, kendi başınıza bir thread yaratıp çalıştırmaktan çok daha verimlidir. JobScheduler servisindeki mantığa benzer biçimde Android, thread'lerin bir havuzda toplanmasını ve yönetiminin sistemce yapılmasını önerir; bu da kaynakların daha verimli kullanılmasını sağlar.

> **Hocanın vurgusu:** Thread'leri kendiniz yaratmak yerine Executor Service'ten faydalanın.

Slayttaki iki örnek (ekrandan, 01:05:00):

- Bir uygulamanın bir veri kaynağından veri yüklemesi gerekiyor. Bu istek ana thread'de yapılırsa ana thread bloklanır ve arayüzde takılmaya (UI jank) yol açar. Bunun yerine istek ana thread'in dışında, bir coroutine içinde yapılır. Hoca bunun bir Worker üzerinden de yapılabileceğini söyledi.
- Bir sohbet uygulamasında bir mesaj gönderilmesi gerekiyor. Uygulama bir `Worker` oluşturur ve işi bir `WorkRequest` olarak kuyruğa alır; `WorkRequest`'i `setExpedited()` ile hızlandırır.

### 7.3 Long Running Work

Android uzun süren işi, 10 dakika ve üzerinde sürebilecek bir iş olarak tanımlar. Bu tür işler için mümkünse WorkManager, yani Worker'lardan faydalanılmasını tavsiye eder. Örnek: büyük bir veri dosyasının indirilmesi. Hoca, veri iletimi çok hızlansa da içeriklerin de çok büyüdüğünü, bağlı olunan ağa ve hatta bulunulan konuma göre bir dosya indirmenin bazen dakikaları aşabildiğini söyledi; bunu bir Worker üzerinden yönetmek uygun olur.

### 7.4 Deferrable Work

Deferrable work'te hemen yapılması gerekmeyen işler söz konusudur. Bu işler genelde planlanır (schedule edilir). Planlanan işler, uygulama kapansa ya da telefon yeniden başlasa da sistem tarafından kendi havuzunda tutulur ve zamanı geldiğinde çalışmaya devam eder. En güzel örneği, özellikle backend'i olan birçok uygulamanın belirli periyotlarla yaptığı senkronizasyondur.

"Saat 12'de olsun" gibi belli bir saat ya da dakikada çalışma zorunluluğu yoksa önerilen yaklaşım, bir **periodic work request** ile bir Worker kullanmaktır. Sisteme "bu işi şu sıklıkla istiyorum" (günlük, saatlik) denir ve tam dakikaya telefonun yoğunluğuna ve kaynak kullanımına göre sistemin karar vermesi sağlanır.

## 8. Alarmlar ve AlarmManager

Alarmlar bir arka plan işi gibi görünse de farklı bir kullanım alanına sahiptir. Slayttaki metin (ekrandan, 01:10:00):

- Alarmlar, arka plan işinin parçası olmayan özel bir kullanım durumudur. Arka plan işleri yukarıda anlatılan iki çözümle, coroutine'ler ve WorkManager ile yürütülmelidir.
- AlarmManager **yalnız** çalar saat ya da takvim etkinlikleri gibi kesin zamanlı alarmları planlamak için kullanılmalıdır. Arka plan işini planlamak için AlarmManager kullanıldığında cihaz Doze modundan uyanır; bu yüzden kullanımının pil ömrüne ve genel sistem sağlığına olumsuz etkisi olabilir. Bu etkilerden uygulamanız sorumlu olur.

Hoca, AlarmManager ile arka plan işi planlanırsa Google'ın kurmak istediği bütün yapının belli oranda sekteye uğradığını ve buna sizin uygulamanızın sebep olduğunu vurguladı. Kullanıcı bu konuda çok bilinçli olmayabilir; uygulamayı yüklerken her izni otomatik verir ve çok takılmaz. Sonra uygulamayı çok kullanmasa da bir süre sonra telefonunun şarjı çabuk biter ve kaynak sıkıntısı yaşar. Bu yüzden geliştiricinin tasarımda bu tavsiyelere dikkat etmesi beklenir.

Konunun sonunda hoca alarmları bir kez daha toparladı: AlarmManager tekrar edilebilir işler ve belirli bir zamanda çalışması gereken işler için kullanılır; ama sistem dengesi açısından WorkManager daha iyi bir seçenektir.

## 9. Foreground Servisler ve WorkManager

### 9.1 Foreground servis kullanım alanları

Foreground servisler çeşitli uygulamalarda kullanılır: bir medya dosyası ya da video oynatmak, müzik çalmak, kullanıcı aktivitelerini takip etmek, konum bilgisini takip ederek paylaşmak ya da streaming üzerinden görüntülü veya sesli görüşme yapmak.

Hocanın anlatımına göre Android 12 ile birlikte foreground servislere alternatif olarak WorkManager yapısı kullanılarak `setForeground` üzerinden bir yönetim önerilmektedir. Böylece WorkManager'ın yaşam döngüsü doğrultusunda daha verimli bir çözüm sunulur; foreground servis gerektiren işler de WorkManager üzerinden yönetilebilir.

Hoca WorkManager'ı bir kez daha hatırlattı: ertelenebilir işler için sunulan bu kütüphane, telefonun ağ ve güç durumunu gözeterek işi uygun zamanda yapabildiği için devreye girer. JobScheduler servisinin üzerinde oturduğu için telefonun kaynaklarının çok iyi yönetilmesini sağlar.

### 9.2 Foreground servislerin özellikleri

Slayttaki maddeler (ekrandan, 01:15:00):

- Kullanıcının başlattığı, hemen çalışması ve tamamlanana kadar yürümesi gereken işler için foreground servis kullanılır. Foreground servis kullanmak sisteme, uygulamanın önemli bir şey yaptığını ve öldürülmemesi gerektiğini söyler.
- Foreground servisler, bildirim alanındaki kaldırılamayan (non-dismissible) bir bildirimle kullanıcıya görünür.
- Foreground servisler, uygulamanın işin ne zaman durup başlayacağı üzerinde kesin kontrole ihtiyaç duyduğu durumlarda en uygun çözümdür.
- Örnek: müzik uygulaması.

Hoca, foreground servis çalıştığı süre boyunca bildirim çubuğunda kaldırılamayan, genelde ikonik bir gösterim olduğunu anlattı. Örneğin arka plan konum takibi yapılıyorsa bir GPS simgesi, müzik çalıyorsa ona ait bir simge görünür. Yeni sürümlerde bu bildirimlerin kaldırılabilmesine yönelik düzenlemeler yapıldığını, merak edenlerin ayrıntıları okuyabileceğini söyledi. Sonuçta foreground servis, kullanıcının istediği zaman başlattığı, arka planda sürdürdüğü, istediği zaman sonlandırdığı ve kullanıcıyla görsel bir bağ kurabilen simgeler sunan servistir.

## 10. Servisler

### 10.1 Servis nedir?

Servis yapısı Android'e girişte anlatılmıştı: bir uygulama bileşenidir; arka planda çalışır, kullanıcıyla doğrudan bağlantısı yoktur ve bir arayüz sunmaz. Özellikle arka plan takibi gerektiren, veri toplamaya ya da akan veriyi değerlendirmeye yönelik işler servis üzerinden yapılır. Hocanın örnekleri:

- ağdaki paketlerin ulaştıkça incelenmesi ve bir saldırı olup olmadığının anlaşılması,
- bir sağlık uygulaması için kullanıcının hareketlerinin arka planda incelenmesi.

Müzik çalma gibi işler artık foreground servis olarak karşımıza çıkıyor; ama uzun sürebilecek işler için Android hâlâ servis kullanmaya izin veriyor. Belli kısıtlar var ve servisler bu kurallara uygun yazılmalıdır.

### 10.2 Servis türleri

Servisler iki temel yapıya ayrılır: **foreground** ve **background**. Bir de **bound (bounded)** ve **unbound (unbounded)** servisler vardır.

- **Foreground servis:** kullanıcıyla etkileşim vardır.
- **Background servis:** kullanıcının yaptığı işlemlerle ilgili bir müdahale yoktur. Örnek: arka planda depolama alanını düzenleyen bir servis; kullanıcı aksiyonuna gerek yoktur, otomatik yapılabilir.
- **Bound servis:** bir uygulama tarafından başlatılmış ve o uygulamaya bağlı çalışan servistir; hocanın anlatımına göre uygulama sonlandığında servis de otomatik olarak sonlanır. Bir bound servis tek bir uygulamaya bağlı olmak zorunda değildir, birden fazla uygulamaya bağlı olabilir.
- **Unbound servis:** herhangi bir uygulamaya bağlılığı yoktur; durdurulmadığı sürece arka planda çalışmaya devam eder, ancak durdurulduğunda sonlanır.

Hoca unbound servisin Google'ın en istemediği şey olduğunu söyledi: bir servis başlatılıp kullanıcı tarafından ya da yazılan kodla durdurulamıyorsa sistemin kaynaklarını arka planda çok ciddi miktarda tüketebilir. Bu yüzden Android telefonlar böyle bir durumla karşılaştığında önce bu arka plan servislerini öldürmeyi tercih eder.

### 10.3 Servis mi, thread mi?

Hoca bunun eskiden çokça sorulan bir soru olduğunu söyledi. Eskiden servis üzerinde bu kadar denetim yoktu ve her şey serviste yapılabiliyordu. Bugün ise iş uzun sürmüyorsa ve gerçekten arka plan takibi gerektirmiyorsa servislerden genelde uzak durulur.

### 10.4 Servislerin yaşam döngüsü

Slayttaki "(Un)Bounded Services" şeması (ekrandan, 01:20:00) iki akışı yan yana gösterir:

```text
Unbounded service                    Bounded service
-----------------                    ---------------
Call to startService()               Call to bindService()
        |                                    |
    onCreate()                           onCreate()
        |                                    |
  onStartCommand()                       onBind()
        |                                    |
  Service running                 Clients are bound to service
        |                                    |
The service is stopped            All clients unbind by calling
by itself or a client                 unbindService()
        |                                    |
        |                              onUnbind()
        |                                    |
    onDestroy()                          onDestroy()
        |                                    |
  Service shut down                   Service shut down
```

`onCreate()` ile `onDestroy()` arasındaki kısım şemada "Active Lifetime" olarak işaretlidir. Hoca şemayı şöyle anlattı: bir tarafta servisin başlatılması, diğer tarafta başlatılan servisin ilgili uygulamayla eşleştirilmesi vardır. İkisi de `onCreate()` aşamasından geçer; sonra `onStartCommand()` ya da `onBind()` noktasında servis çalışmaya başlar. Unbounded serviste servisin ya kendisinin durması ya da istemci (client) tarafından durdurulması beklenir; istemcinin onu durduracak bir yapısı yoksa servis mutlaka sistem tarafından yok edilmelidir. Bound servis bağlı olduğu uygulama sonlandığında kendini sonlandırır.

> **Ders sonrası not:** Hoca bound servisin bağlı olduğu uygulama sonlanınca kendini sonlandırdığını söyledi (01:20:39). Slayttaki şemaya göre bound servis, bağlı **bütün** istemciler `unbindService()` ile bağlantıyı kopardığında `onUnbind()` ve `onDestroy()` adımlarıyla kapanır. Birden fazla istemci bağlıysa, tek birinin sonlanması büyük olasılıkla servisi kapatmaz.

### 10.5 Servisi başlatmak, durdurmak ve bildirmek

- Bir servis `startService()` ya da `startForegroundService()` metodu çağrılıp ilgili Intent verilerek çok hızlı biçimde başlatılabilir.
- Servis `stopService()` ile başka bir bileşen tarafından durdurulabilir ya da kendi kendine sonlanabilir.
- Aktivitelerde olduğu gibi servis de manifest dosyasında, `application` etiketinin içinde tanımlanmalıdır. Servisin bir arayüzü olmasa da manifestte yer alması gerekir; buna dikkat edilmelidir.

> **Ek bilgi (derste anlatılmadı):** Servisin kendi kendini durdurması için kullanılan metot büyük olasılıkla `stopSelf()`'tir; altyazıda bu iki metot da "StopService" diye duyuluyor. Manifestteki tanım `<service android:name=".BenimServisim" />` biçiminde, `<application>` etiketi içine yazılır.

### 10.6 Önerilen yapılar özeti

Hoca, arka plan işleri için önerilen yapıları şöyle topladı:

- Uzun sürecek HTTP indirmeleri için **DownloadManager** kullanılmalıdır.
- Ertelenebilir olmayan bir iş için foreground servislerinden faydalanılır.
- İş bir zaman aralığında sistem tarafından çalıştırılabiliyorsa, yani ertelenebiliyorsa **WorkManager** kullanılır.
- İş belirli, kesin bir zamanda çalışacaksa **AlarmManager**; değilse yine WorkManager kullanılır.

<!-- BELİRSİZ: 01:22:08-01:22:23 arasında altyazı kopuk; listedeki bir ara madde (büyük olasılıkla ertelenebilir iş için koşul) duyulmuyor ve bu aralığın karesi yok. -->

## 11. Cihazı Uyanık Tutmak: Ekran ve CPU

### 11.1 İki kademeli uyanıklık

Cihazın uyanık olması iki kademelidir: birincisi ekranın açık olması, ikincisi işlemcinin boşta (idle) ama uyku modunda olmaması. İşletim sistemi, cihaz kullanılmadığında mümkünse ekranı bir an önce kapatmak ve işlemciyi bir an önce uyku moduna almak ister; bu ciddi enerji tasarrufu sağlar. Kullanıcı kendi tercihiyle örneğin ekranın süresiz açık kalmasını seçtiyse işletim sisteminin yapabileceği bir şey yoktur, yalnız belli aralıklarla uyarı verebilir. İşlemci için de aynısı geçerlidir.

Slayttaki giriş metni (ekrandan, 01:25:00): Pili tüketmemek için boşta bırakılan bir Android cihaz hızla uykuya geçer. Ama bazen bir uygulamanın bir işi tamamlamak için ekranı ya da CPU'yu uyandırıp uyanık tutması gerekir. İzlenecek yol uygulamanın ihtiyacına bağlıdır; genel kural, sistem kaynaklarına etkiyi en aza indirmek için mümkün olan en hafif yaklaşımı kullanmaktır.

### 11.2 Wakelock ve alternatifleri

Burada önemli kavram **Wake Lock** mekanizmasıdır. Wakelock ile bir cihaz sürekli ayakta tutulabilir. Eskiden telefonlarda çok sık kullanılıyordu; ama wakelock devreye girdiğinde telefon sürekli ayakta tutulduğu ve pil çok çabuk tükendiği için Android bunun yerine alternatif çözümler ortaya koymaya başladı.

Slayttaki "Alternatives to using wake locks" maddeleri (ekrandan, 01:25:00); uygulamaya wakelock desteği eklemeden önce kullanım durumunun şunlardan birine uyup uymadığına bakılır:

- Uygulama uzun süren HTTP indirmeleri yapıyorsa `DownloadManager` kullanılabilir.
- Uygulama harici bir sunucudan veri senkronize ediyorsa bir sync adapter oluşturulabilir.
- Uygulama arka plan servislerine dayanıyorsa, bu servisleri belli aralıklarla tetiklemek için JobScheduler ya da Firebase Cloud Messaging kullanılabilir.
- Eşlik eden (companion) bir cihaz menzildeyken eşlik eden uygulamanın çalışır kalması gerekiyorsa Companion Device Manager kullanılabilir.

Hoca JobScheduler'ın derinlemesine incelenmesi gereken bir servis olduğunu ve burada istenen şeyin arka plan işlerini işletim sistemine devretmek olduğunu söyledi: sistem bu servis aracılığıyla kaynakları en iyi şekilde kullanarak hizmet verir; araya WorkManager gibi yapılar konur.

> **Ders sonrası not:** Hoca JobScheduler'ın "yanlış hatırlamıyorsam Android 11 ya da 12 ile" aktif olarak kullanılmaya başlandığını söyledi (01:26:52). JobScheduler API'si büyük olasılıkla Android 5.0 (API 21) ile gelmiştir.

### 11.3 Ekranı açık tutmak

Bu yapılar kullanılmıyorsa ya da işe yaramıyorsa, örneğin bir video oynatıcı ya da bir oyun yapıldıysa ve ekranın sürekli açık kalması isteniyorsa iki yol vardır: XML layout dosyasında "keep screen on" özniteliğini `true` yapmak ya da ilgili pencerenin bayrağını (flag) ayarlamak. İşlem tamamlandığında bu yine kapatılabilir.

Hoca bunun önemini şöyle açıkladı: işletim sistemi normalde kullanılmayan uygulamada ekranı karartır ya da parlaklığı azaltır; bu kullanıcı memnuniyetsizliğine yol açabilir. Video ve medya uygulamaları, Netflix ya da Disney Plus gibi içerik göstericiler, kullanıcı izlediği sürece ekranın açık kalmasını sağlar. Başka bir uygulamada aynı ayarlarla bir süre ekrana dokunulmazsa ekran yavaş yavaş kararır; ama bu uygulamalarda ekranı açık bırakan kod yazıldığı için, daha fazla enerji tüketse de ekran rahatsızlık vermeden açık kalır.

> **Ek bilgi (derste anlatılmadı):** Layout özniteliği büyük olasılıkla `android:keepScreenOn="true"`, pencere bayrağı ise `getWindow().addFlags(WindowManager.LayoutParams.FLAG_KEEP_SCREEN_ON)` biçimindedir; bayrak `clearFlags` ile kaldırılır. Bu yol wakelock gibi özel bir izin gerektirmez.

### 11.4 CPU'yu açık tutmak

Aynı şey CPU için de geçerlidir. Slayttaki metin ve kod (ekrandan, 01:30:00): Cihaz uykuya geçmeden önce bir işi tamamlamak için CPU'nun çalışır kalması gerekiyorsa `PowerManager` sistem servisinin **wake lock** özelliği kullanılabilir. Wakelock'lar, uygulamanın cihazın güç durumunu denetlemesini sağlar.

Manifestte izin:

```xml
<uses-permission android:name="android.permission.WAKE_LOCK" />
```

Wakelock alma:

```java
PowerManager powerManager = (PowerManager) getSystemService(POWER_SERVICE);
WakeLock wakeLock = powerManager.newWakeLock(PowerManager.PARTIAL_WAKE_LOCK,
        "MyApp::MyWakelockTag");
wakeLock.acquire();
```

Hoca wakelock'un ciddi bir enerji tüketimi anlamına geldiğini, bunun `PowerManager` üzerinden yapıldığını ve ihtiyaç bildirilerek izin istendiğini anlattı. Örnek kullanım: arka planda performans gerektiren bir resim işleme. Daha somut örnek bir **bebek takip uygulamasıdır**: uygulama gelen görüntüyü ya da sesi sürekli işleyip bebeğin ağlayıp ağlamadığını veya hareket edip etmediğini bildirir. Bunun için CPU'nun sürekli çalışması gerekir. Uygulama istemci-sunucu mimarisinde de olabilir: iki telefonda aynı uygulama çalışır, bebeğin odasındaki telefon işleri yapar ve sonucu size gönderir. Bu koşullarda o telefonun CPU'yu sürekli aktif kullanması gerekir; bu tür durumlarda wakelock mekanizmasından faydalanılır.

> **Ders sonrası not:** Hoca wakelock için kullanıcıdan izin alınması gerektiğini söyledi (01:29:23). `WAKE_LOCK` büyük olasılıkla "normal" koruma düzeyinde bir izindir: manifestte bildirilir ve kurulumda kullanıcıya ayrıca sorulmadan verilir; çalışma zamanında izin penceresi açılmaz.

> **Ek bilgi (derste anlatılmadı):** Alınan wakelock iş bitince `wakeLock.release()` ile bırakılmalıdır; bırakılmayan wakelock CPU'yu uyanık tutmaya devam eder ve pili tüketir. `acquire(timeout)` biçimiyle bir zaman aşımı da verilebilir.

### 11.5 Wakeful Broadcast Receiver

Son olarak Wakeful Broadcast Receiver'lardan söz edildi. Hoca bunun çok ayrıntısına girmek istemediği bir konu olduğunu, yalnız duyulması için slayta alındığını ve ayrıntıların okunarak öğrenilebileceğini söyledi.

<!-- BELİRSİZ: 01:30:45-01:31:13 arasında altyazı kopuk; 01:31:13'te Calendar ve PendingIntent ile bir şeyin (büyük olasılıkla bir alarmın) ayarlandığı bir kod parçasından söz ediliyor. Bu ana ait kare yok, kod okunamadı. -->

## Örnek Sorular

### Soru 1 (derste sözlü, 01:23:17 ve 01:32:45)

Bir uygulama içinde, uzak bir bağlantıya bağlanıp oradaki büyük bir dosyayı (megabaytlar değil, gigabaytlar mertebesinde) arka planda kendi cihazınıza indiren bir servis ya da arka plan süreci yazın. Uygun yapıları deneyerek çalıştırın.

> **Çözüm (derste verilmedi):** Derste çözüm verilmedi; bir sonraki derste konuşulacağı söylendi. Bu derste anlatılan ilkelere göre kurulabilecek yaklaşım şöyledir (kod ajan tarafından yazılmadı ve test edilmedi):
>
> - İş uzun sürer (Long Running) ve ana thread'de yapılamaz; HTTP çağrısı ana thread'de yapılırsa uygulama bloklanır.
> - Derste uzun süren HTTP indirmeleri için ilk önerilen yapı `DownloadManager`'dır (bkz. Bölüm 10.6 ve 11.2). Sistem indirmeyi kendisi yürütür; uygulama kapansa da indirme devam eder.
> - Alternatif olarak WorkManager ile bir `Worker` yazılabilir; uzun iş için `setForeground` ile kullanıcıya görünür bir bildirim gösterilerek iş foreground olarak yürütülür. Dosyanın parça parça inmesi ve kaldığı yerden devam edebilmesi (iş bölünebilir mi sorusu) bu tasarımda önemlidir.
> - Kullanıcının başlatıp durdurduğu, ilerlemesini bildirimden izlediği bir indirme ise foreground servis (`startForegroundService()`) de uygundur; servis manifestte `application` içinde tanımlanmalıdır.
> - İş Wi-Fi'ye ya da şarja bağlıyken yapılabiliyorsa (ertelenebilir iş), WorkManager'a bu koşullar verilerek sistemin uygun anı seçmesi sağlanır.

## Dersin Toparlaması

Bu derste Android'de arka plan işlerinin neden gerektiği ve nasıl yönetildiği konuşuldu. Ana thread arayüzden ve yaşam döngüsü olaylarından sorumludur; birkaç milisaniyeden uzun süren disk, ağ ya da resim işleme işleri ayrı thread'lere taşınmalıdır, yoksa arayüz bloklanır ve ANR penceresi açılır. Öte yandan arka plan işleri RAM ve pil tüketir; bu yüzden Android sürüm sürüm kısıtlar getirmiştir: Doze ve App Standby (6.0), Doze-on-the-Go ve örtük broadcast kısıtı (7.0), arka plan konum kısıtı (8.0) ve uygulamaları kullanım sıklığına göre Active, Working set, Frequent ve Rare kovalarına yerleştiren App Standby Buckets (9). Geliştirici kovaları manipüle etmemeli; launcher aktivitesi ve etkileşimli bildirimlerle uygulamanın active kovasına çıkabilmesini sağlamalıdır.

Doğru yapıyı seçmek için işin kullanıcıya bağlı olup olmadığı, bölünebilirliği, ertelenebilirliği, sistem koşullarına bağımlılığı, hassas veri kullanımı ve kesin zaman gerektirip gerektirmediği sorulur. Arka plan işleri Immediate, Long Running ve Deferrable olarak; her biri de Persistent ya da Impersistent olarak sınıflandırılır. Persistent, uzun ve ertelenebilir işler için JobScheduler'ın üstüne oturan WorkManager (`OneTimeWorkRequest`, `PeriodicWorkRequest`, `setExpedited()`, `setForeground`); tek seferlik hemen yapılacak işler için coroutine'ler ya da Executor'lar; yalnız kesin zamanlı işler için AlarmManager önerilir. Foreground servisler kaldırılamaz bildirimle kullanıcıya görünür; servisler bound ve unbound yaşam döngüleriyle çalışır ve manifestte tanımlanır. Son olarak ekranı ve CPU'yu uyanık tutma yolları (keep screen on, `PowerManager` wakelock) ve bunlardan önce düşünülmesi gereken alternatifler anlatıldı. Bir sonraki derste arka plan işlerinin kalan birkaç maddesi, büyük dosya indirme alıştırması ve bildirimler (notification) ile bunların arka plan işleriyle, AlarmManager ile ilişkisi ele alınacak; ardından konum bilgisinin toplanması ve harita üzerinde kullanılması işlenecek.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
