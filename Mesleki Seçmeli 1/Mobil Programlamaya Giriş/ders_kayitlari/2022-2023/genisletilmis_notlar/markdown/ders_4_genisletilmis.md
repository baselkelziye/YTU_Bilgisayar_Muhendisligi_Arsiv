# Ders 4 Genişletilmiş Notu: Mobil Uygulama Trendleri, Android Mimarisi ve İlk Android Projesi

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Mobil Uygulama Geliştirme Trendleri
- 2. iOS ve Android ile Uygulama Geliştirmenin Karşılaştırılması
- 3. Instant App (Anlık Uygulama)
- 4. On-Demand (Talep Üzerine Hizmet) Uygulamaları
- 5. Mobil Uygulamanın Başarısını Ölçmek: Metrikler
- 6. Android Mimarisi
- 7. Android Runtime: JIT, AOT, NDK ve SDK
- 8. Activity ve Yaşam Döngüsü
- 9. Uygulama Mimarisi İlkeleri ve İyi Uygulamalar
- 10. İlk Uygulamayı Tasarlarken: Giriş Noktaları ve Farklı Cihazlar
- 11. Diller, APK ve Android App Bundle
- 12. En Az Ayrıcalık İlkesi
- 13. Temel Uygulama Bileşenleri
- 14. Intent
- 15. AndroidManifest.xml
- 16. Uygulama Kaynakları (App Resources)
- 17. Yapılandırma Değişiklikleri ve İzinler
- 18. Android Studio ile İlk Proje

## 1. Mobil Uygulama Geliştirme Trendleri

Ders, önceki haftada yarım kalan "mobil uygulama geliştirme trendleri" konusunun tamamlanmasıyla başladı. Hoca, dersin ikinci yarısında artık Android Studio ile tanışılacağını ve kodlamaya yavaş yavaş geçileceğini söyledi.

Önceki slayttaki başlıklara ek olarak Beacon teknolojisi, Instant App'ler, On-Demand uygulamalar ve bulut tabanlı geliştirme anıldı. Mobil uygulamaların bulutla ilişkisi giderek daha önemli hâle geliyor. Ekrandaki trend listesi şuydu (ekrandan, 00:10:00):

- Katlanabilir cihazlar için uygulama geliştirme (uygulamaların yeniden tasarlanması gerekiyor).
- Makine öğrenmesi ve yapay zekâ.
- Chatbotların yükselişi.
- Giyilebilir cihaz entegrasyonu (özellikle akıllı saatler).
- Nesnelerin interneti (IoT) ile çalışan uygulamalar.
- Artırılmış gerçeklik (AR) ve sanal gerçeklik (VR).
- Mobil cüzdanlar.
- Mobil uygulama güvenliğinin daha fazla önem kazanması.

Yapay zekâ tarafında hoca, öğrenmenin artık telefonlarda da yapılmaya başlandığını, bunun için bir merkezde toplu öğrenme yerine telefonlara dağıtılmış bir öğrenme yaklaşımının (federe öğrenme, Federated Learning) kullanıldığını belirtti.

Nesnelerin interneti tarafında şu anda ağırlık giyilebilir cihazlarda, ama evdeki akıllı cihazlar (çamaşır makinesi, bulaşık makinesi) ve en yaygın olarak akıllı televizyonlar için de uygulama geliştiriliyor. AR ve VR beklendiği kadar yaygınlaşmamış olsa da oyun, sanal geziler ve turlar, uzaktan eğitim, büyük bir parçanın ofiste nasıl duracağını görme ve büyük bir kampüste ya da binada yol bulma gibi alanlarda telefonlarla kullanılıyor.

Mobil cüzdanlar sayesinde saat ya da telefonla ödeme yapmak kolaylaştı; artık kredi kartı taşımadan ödeme yapılabiliyor. Bu ödemelerde güvenlik için eskisine göre daha çok adım uygulanıyor: SMS ile gelen kodlar ya da doğrudan uygulamadan gönderilen bildirimler kullanılıyor. <!-- BELİRSİZ: altyazıda "Huawei Authentication" geçiyor; büyük olasılıkla "two-factor authentication" (iki aşamalı doğrulama) kastedildi. -->

Mahremiyet ve güvenlik de önemli bir trend. İşletim sistemi düzeyinde mesajların ve sağlık bilgilerinin üçüncü kişilerce öğrenilmemesi için yeni çözümler üretiliyor. Uygulama düzeyinde ise bu, veriyi şifreleyerek paylaşma ya da buluta şifreli aktarma biçiminde karşımıza çıkıyor.

### 1.1 Uygulama kategorileri

Uygulama kategorileri arasında (finans, medikal, müzik, alışveriş, sağlık vb.) en büyük payı oyun sektörü alıyor: mobil cihazlarda en çok tercih edilen, satın alınan ve indirilen uygulamalar oyunlar. Oyunların arkasından eğlence uygulamaları geliyor. Fotoğraf ve video uygulamalarının payı da son dönemde artıyor.

Hoca, değişimin yönünü fotoğraf uygulamalarıyla anlattı. Eskiden fotoğrafı görür, kesip biçmek gibi birkaç işlem yapardınız. Bugün işletim sistemiyle gelen fotoğraf uygulamaları benzer fotoğrafları sunuyor, fotoğrafları çekildikleri coğrafi bölgeye göre gösteriyor, bir kelimeyle arama yapıp o nesnenin geçtiği fotoğrafları listeliyor. WhatsApp gibi birçok kaynaktan gelen binlerce fotoğraf arasında aynı olanları temizlemek ya da aranan bir fotoğrafı (bir manzara ya da vesikalık fotoğraf) bulmak için tarih çoğu zaman yetmiyor; makine öğrenmesi ve görüntü işleme bu ihtiyaca cevap veriyor. Hoca, bu tür bir fotoğraf uygulamasının ekibi tarafından bir bitirme projesi olarak geliştirilip mağazada yayımlandığını da örnek verdi. Ana fikir şu: Günlük hayatta sık kullanılan ama "keşke şu özellik de olsa" denen bir açığı fark ederseniz, bunun üzerine uygulama geliştirebilirsiniz.

## 2. iOS ve Android ile Uygulama Geliştirmenin Karşılaştırılması

Önceki derste iOS ve Android işletim sistemi düzeyinde karşılaştırılmıştı. Bu kez uygulama geliştirme açısından karşılaştırma yapıldı. Ekrandaki tablo şöyleydi (ekrandan, 00:20:00):

| iOS: avantajlar ve zorluklar | Android: avantajlar ve zorluklar |
|---|---|
| (+) iOS faster time to ship | (+) Flexibility and customization |
| (+) iOS cheaper timeline to bring to market | (+) Faster approval process |
| (+) iOS simpler coding languages | (+) Cheaper developer account fee |
| (+) Users with higher average spending power | (+) More robust developer resources |
| (−) Higher developer account fee | (+) Larger global market share |
| (−) Closed-source code | (−) More complicated to bring to market |
| (−) Higher publishing costs | (−) Increased fragmentation among devices, screens, resolutions |
| | (−) Increased chances of app release with bugs/vulnerabilities |

Hocanın anlatımıyla:

- **Kaynak kodu:** iOS kapalı kaynak, Android açık kaynak.
- **Geliştirici hesabı:** Android'de daha ucuz, iOS'ta daha pahalı.
- **Cihaz ve test:** Android'de herhangi bir bilgisayarda geliştirme yapıp emülatörde deneyebilirsiniz. iOS'ta simülatör yalnız fikir verir; mağazaya çıkacaksanız mutlaka gerçek cihazda test etmeniz gerekir. Ayrıca geliştirme için bir Apple cihazına ve Xcode'a ihtiyaç vardır.
- **Dil:** Hocaya göre Swift, Kotlin'e göre daha basit bir dil; bu yüzden iOS'ta kod geliştirmek sanıldığından kolay, ama daha maliyetli.
- **Yayın süreci:** iOS'ta düzenlemeler nedeniyle uygulamanın onaylanması birkaç haftayı bulabilir. Android'de çok sıkı bir denetim yok; bu yüzden Google Play'de zaman zaman zararlı (malware) ya da verimsiz çalışan uygulamalarla karşılaşılabiliyor. iOS'a konmamış, Android'de ücretsiz ama sorunlu çalışan uygulamalar da var.
- **Özelleştirme:** Android daha avantajlı.
- **Enerji:** iOS uygulamaları genelde enerji tüketimi açısından daha verimli. Android'de donanım ve yazılımı farklı üreticilerin geliştirmesi bu konuda sorun çıkarıyor.
- **Yaygınlık:** Android çok daha yaygın. iOS'un belirli bir fiyat politikası olduğu için her segmentte müşterisi yok.

### 2.1 Uygulama geliştirme stratejisi

Bu farklar doğrudan uygulama geliştirme stratejisini etkiler. Bir uygulama geliştirirken şu sorular sorulmalı: Hangi kullanıcı segmenti hedefleniyor? O kitlenin gerçekten ihtiyaç duyduğu uygulama ne? Fikriniz harika olabilir ama insanların buna ihtiyacı var mı? Bu segment uygulamayı satın alır mı, yoksa gelir reklamlardan mı elde edilmeli?

Sürüm uyumluluğu da bu stratejinin parçası. Bugün Android 12 ve 13 konuşuluyor, ama dünyadaki kullanım oranlarına bakıldığında Android 10 ve sonrasındaki cihaz sayısı sanıldığı kadar fazla değil; büyük bir segment 7, 8, 9 sürümlerinde, hatta daha eski cihazlar da var. Bu yüzden eski sürümlerle uyumlu uygulama geliştirmek önemli. Minimum SDK sürümünüz ve hedef (target) SDK sürümünüz bütün bu ihtimaller masaya konarak belirlenmeli. "Fikrim var, yazmaya başladım" demek yetmez; bunlar dikkate alınmazsa mağazaya bir uygulama koyarsınız ama ilgi görmeyebilir. Reklam ve uygulamanın nasıl yayılacağı da önemli; iOS ve Android için farklı stratejiler gerekir.

İkinci karşılaştırma slaytında bütçe, programlama dili, yayın paketi biçimi, geliştirici kaynakları, açık ya da kapalı kaynak olma, pazar payı ve müşteri tipi ana kalemler olarak verildi.

## 3. Instant App (Anlık Uygulama)

Instant App kavramını Google şu gözlemden yola çıkarak ortaya koydu: Kullanıcılar çok fazla uygulama indiriyor. Bir süre sonra cihazda yer kalmıyor, uygulamalar çok kaynak ve enerji tüketiyor, boyutları büyüyor. Cihaz kaynakları orantısız kullanılıyor ve denetim mekanizması çok katı olmadığı için memnuniyetsizlik doğuyor. Google'ın incelemesi, her uygulamanın içindeki modüllerin aynı oranda kullanılmadığını, kullanıcının uygulama kodunun çoğunu aslında hiç çalıştırmadığını gösterdi.

Buradan şu fikir çıktı: Kullanıcı uygulamanın tamamını mağazadan indirmek yerine yalnız kullanmak istediği modülü indirsin, bu modülü önbellekte (cache) kullansın, işi bitince uygulama hafızada yer kaplamasın. Google Play'de bazı uygulamaların yanında indirme seçeneğinin yanında, uygulamanın Instant App olduğunu gösteren geçici kullanım bağlantısı bulunur; bu bağlantıyla uygulamanın ihtiyaç duyulan kısmı indirilir. Yani uygulamanın en çok kullanılan, tercih edilen kısmı bir Instant App olarak tasarlanıp kullanıcıya sunulur.

Slayttaki maddeler (ekrandan, 00:25:00):

- Uygulama kurulmadan anında açılıp çalıştırılabilir.
- İlk ve en büyük sürtünme noktası olan kurulum ortadan kalkar.
- Uygulamayı bulmanın ve denemenin yeni bir yolu açıldığı için keşfedilebilirlik artar.
- Instant App bağlantıları kolayca paylaşılabilir.
- Ana uygulama hakkında ilk izlenimi oluşturur.
- Sunulan özellikler için kurulabilir uygulamayla aynı deneyimi, ama bir URL üzerinden verir.
- Çok küçük uygulamalar için olduğu kadar alışveriş, podcast ve haber gibi büyük uygulamalar için de uygundur, çünkü bağlantıya tıklanınca yalnız gereken modül indirilir.
- Android 8.0 (API level 26) ve üstünde çalışan bir cihazda uygulama `targetSandboxVersion` değerini 2 olarak belirtirse, veriler tam uygulama sürümüne otomatik aktarılır.

### 3.1 Instant App'in sınırları

Instant App'lerin belirli sınırları vardır:

- Genellikle bir sandbox ortamında çalışırlar.
- Yaklaşık 15 MB'lık bir boyut sınırı vardır.
- Sistemden broadcast mesajı, yani sistem düzeyinde bir değişiklik olduğuna dair bilgi alamazlar.
- Cihazın bazı özelliklerinden yararlanamazlar; özellikle izinler sınırlıdır.
- Depolamayı istenen boyutta dosyalar için kullanamazlar.
- Diğer uygulamalarla resim paylaşmak gibi işlemler yapamazlar.
- Arka plan servisi çalıştıramazlar.

Hoca, bu sınırların aslında Instant App'in neden var olduğunu gösterdiğini vurguladı: Bu işler yapıldığında kod büyür, kaynak tüketimi artar ve basit bir iş için bile bütün uygulama kodunu indirmek gerekir.

## 4. On-Demand (Talep Üzerine Hizmet) Uygulamaları

Son on yılda On-Demand uygulamaların sayısı çok arttı: taksi çağırmaktan içerik izlemeye, yemek siparişinden ev ve ofis temizliği, çocuk bakımı ya da arızalı bir cihaz için hizmet aramaya kadar. Bunlar talep temelli uygulamalardır ve hizmeti en hızlı getirecek organizasyona sahip olmaları beklenir. Slayttaki başlıklar: düşük maliyet, erişilebilirlik, kullanıcı tercihlerine uyum, çeşitli ödeme yöntemleri, en az çaba (ödeme ve adres bilgilerinin saklanması) ve çeşitlilik. Sağdaki akış şemasında işleyiş istek, eşleştirme, ödeme onayı, hizmet teslimi, onay ve ödemenin çekilmesi adımlarıyla gösteriliyordu (ekrandan, 00:30:00).

Burada uygulamayı yazmak kadar fikrin lojistik desteğini organize etmek de önemlidir. Taksi örneğinde müsait taksilerin bilgisinin kullanıcının telefonuna aktarılması gerekir. Bir yanda taksicilerin kullandığı kurumsal (business) bir uygulama, öbür yanda müşterilerin kullandığı bir uygulama vardır; yani bir fikri hayata geçirmek için iki ayrı uygulama yayımlamanız gerekebilir. Taksici tarafı konumunu bildirir, müşteri tarafı müsait taksileri arar. Müşteri bindikten sonra taksi kendini dolu olarak işaretlemeli, varışta ödemenin kartla mı nakitle mi yapılacağı da uygulama üzerinden bildirilmelidir.

İçerik izleme platformlarında da benzer sorumluluklar vardır. Yayın (streaming) sırasında bant genişliğinin denetlenmesi ve ayarlanması gerekir. Bazı uygulamalar ekranı yalnız yatayda gösterecek biçimde tasarlanır; bu tür kararları stratejik ekip verir, teknik ekip uygular. Kullanıcının nerede durduğu, hangi bölümleri izlediği, hangi içeriğe bakıp yarım bıraktığı saklanmalı; daha iyi öneri sunmak için kullanıcının alışkanlıkları izlenip kaydedilmelidir. Bu, basit bir mobil uygulamanın ötesinde, buna uygun veri toplayan bir yapı gerektirir.

Bu yüzden On-Demand uygulamalar yalnız ön yüzden (front-end) ibaret değildir. Uçta (edge) çalışan telefon tarafına ek olarak bulutta ya da sunucuda bütün süreci yönetecek arka uç (backend) kodu da yazılmalıdır. Bugün mobil uygulama geliştirmek aynı zamanda frontend ve backend tasarlamak demektir. Eskiden uygulamalar daha çok çevrimdışı çalışacak biçimde tasarlanırken bugün çoğu çevrimiçi çalışıyor; bağlantı koparsa kullanıcı veri kaybetmeden, bağlantı gelince kaldığı yerden devam edebilmelidir.

## 5. Mobil Uygulamanın Başarısını Ölçmek: Metrikler

Bir mobil uygulamanın başarılı olup olmadığını değerlendirmek ve başka bir uygulamayla kıyaslamak için bakılan metrikler dört grupta toplandı: performans metrikleri, kullanıcı metrikleri, bağlılık (engagement) metrikleri ve iş (business) metrikleri. Son ikisi daha özelleşmiştir ve uygulamanın yaşam döngüsüyle ilgilidir.

### 5.1 Performans metrikleri

Slayttaki performans metrikleri (ekrandan, 00:35:00):

- App Crashes (uygulama çökmeleri)
- API Latency (API gecikmesi)
- End-to-End Application Latency (uçtan uca uygulama gecikmesi)
- App Load per Period (dönem başına uygulama yükü)
- Network Errors (ağ hataları)

Bu metrikler ya kendi yazdığınız kodlarla ya da Google Play ve Apple mağazasının sunduğu araçlarla izlenebilir. Uygulamanın ne kadar çöktüğü, bir API'nin gecikmesi, eşler arası (peer-to-peer) haberleşmede gecikme olup olmadığı, ne kadar ağ hatası alındığı takip edilerek uygulamanın ne oranda hata aldığı ve müşteriye nasıl göründüğü (tutarlılığı) anlaşılır. Bu metrikler kullanıcı memnuniyetini doğrudan etkiler. Hoca iki örnek verdi: Uygulama büyük bir resim ya da videoyla açılıyorsa ve bu çok geç yükleniyorsa, kullanıcı bir süre sonra uygulamayı bırakır; çünkü bir an önce ilgili modüle ulaşmak ister ve güzel olsun diye konan görsel onun için anlam taşımaz. Kullanıcı iki üç kez girip her seferinde aynı modülde çökme yaşarsa uygulamayı kararsız bulup alternatif bir uygulamaya geçer.

### 5.2 Kullanıcı metrikleri

Günlük ve aylık aktif kullanıcı sayısının nasıl değiştiği, indirme oranlarının yükselip yükselmediği ya da bir yerde takılıp kalmadığı izlenir. Uygulamanın hangi cihazlarda, hangi işletim sistemlerinde, dünyanın neresinde kullanıldığını bilmek, sonraki adımda uygulamayı hangi modüllerle destekleyeceğinizi ve hangi segmente hitap ettiğinizi anlamayı kolaylaştırır. Bazen X segmentini hedeflersiniz ama Y segmenti daha çok ilgi gösterir; bu durumda uygulama o yöne yönlendirilebilir.

### 5.3 Bağlılık metrikleri

Kullanıcının uygulamayı indirdikten sonra hangi aralıklarla tekrar kullandığı, bir kez kurup bir daha dönüp dönmediği, uygulamada ne kadar zaman geçirdiği izlenir. Böylece uygulamanın gerçekten kullanılmak için mi yoksa bir bakıp çıkmak için mi indirildiği görülür. Hangi modülde ne kadar vakit geçirildiğine bakarak insanların uygulamayı neden tercih ettiği ve ne kadar bağlı oldukları incelenir.

### 5.4 İş metrikleri

Slayttaki iş metrikleri (ekrandan, 00:40:00):

- Acquisition Cost (kullanıcı edinme maliyeti)
- Transaction Revenue (işlem geliri)
- Abandonment Rate (terk oranı)
- LTV (kullanıcının yaşam boyu değeri)
- App Star Rating (mağaza yıldız puanı)

Uygulamanın ücretsiz bir sürümü olabilir, ya da uygulama içi satın alma (in-app purchase) ile belirli hizmetler ücretli sunulabilir. Bunların oranı, insanların ödeme yapıp yapmadığı ve toplam yatırımın ne kadar sürede geri döneceği izlenir.

Kullanıcı yorumları ve puanları bugün çok önemlidir; uygulamanın mağazada üst sıralarda yer almasını sağlar. Verilen isim bile önemlidir: Benzer adlı uygulamalar arasında puanınız düşükse çok geride kalabilirsiniz. Uygulama kategorisi de doğru seçilmelidir; yanlış kategori seçilirse o kategoride arayan kullanıcı uygulamanıza ulaşamayabilir. Puanlama ilk başta çok yavaş ilerler, dikkat çektikçe çığ gibi büyüyebilir; yüksek puan ve iyi yorum almak için ciddi stratejiler gerekir. Hoca, bazı geliştiricilerin yakınlarına puan verdirdiğini ya da farklı hesaplarla puanları yükseltmeye çalıştığını da belirtti.

### 5.5 Tek tek metrikler

Sonraki slaytlarda metrikler tek tek ele alındı:

- **İndirmeler:** İndirme sayısını ve bunun hangi kaynaktan (telefon, tablet ve bunların kendi içindeki çeşitlilik) geldiğini izlemek en önemli hedeflerden biridir.
- **Aktivasyon:** Kullanıcının uygulamayı indirdikten sonra onu ne kadar kullandığı.
- **Tutma (retention):** Özellikle 3. ve 7. güne bakılır. Uygulama ilk yüklendiği günden sonra 3. ve 7. gün tekrar açılıyor mu, ya da ilk 3 ve ilk 7 gün içinde kullanılıyor mu?
- **Oturumlar:** Uygulamaya gün içinde ne sıklıkla girildiği ve oturum süreleri, kullanıcının uygulamayla ne kadar bağ kurduğunu gösterir.
- **Kaldırmalar (uninstall):** Uygulamanın kaldırıldığını izleyebilirsiniz; kaldırmadan önce sizin tarafınıza bilgi gönderen bir modül konabilir. Böylece kullanıcıların uygulamadan ne kadar çabuk vazgeçtiği görülür.
- **Ödeme ve aksiyonlar:** Kullanıcıların ne oranda ödeme yaptığı ve hangi aksiyonları gerçekleştirdiği.
- **Erişilebilirlik (Reachability):** Gönderilen push bildirimlerine ve uygulama içi bildirimlere kullanıcıların ne kadar tıkladığı. Slaytta KPI olarak tıklama oranı (click-through rate) ve izin verme oranı (opt-in rate); izlenecek değer olarak push, uygulama içi bildirim ve e-posta bağlantılarına dokunan kullanıcı yüzdesi ile bildirim almayı ya da konum erişimini kabul eden kullanıcı yüzdesi yazıyordu (ekrandan, 00:45:00).

Hoca bu bölümü, ilk slayt grubunda mobil uygulama geliştirme tekniklerinin, mobil işletim sistemlerinin ve trendlerin konuşulduğunu, artık asıl odaklanılacak "habitat" olan Android'e geçileceğini söyleyerek kapattı.

## 6. Android Mimarisi

Dersin ikinci bölümünde Android programlamaya geçildi. Android mimarisi beş katmandan oluşur (ekrandan, 01:05:00). Aşağıdan yukarıya:

| Katman | İçerik (slayttaki kutular) |
|---|---|
| System Apps | Dialer, Email, Calendar, Camera, ... |
| Java API Framework | Content Providers, View System; Managers: Activity, Location, Package, Notification, Resource, Telephony, Window |
| Native C/C++ Libraries ve Android Runtime | Webkit, OpenMAX AL, Libc, Media Framework, OpenGL ES, ...; Android Runtime (ART), Core Libraries |
| Hardware Abstraction Layer (HAL) | Audio, Bluetooth, Camera, Sensors, ... |
| Linux Kernel | Drivers: Audio, Binder (IPC), Display, Keypad, Bluetooth, Camera, Shared Memory, USB, WIFI; Power Management |

- **Linux çekirdeği:** En alttaki katmandır; sürücüler burada yer alır, güç yönetimi (Power Management) de bu katmanda yapılır.
- **Donanım soyutlama katmanı (HAL):** Çeşitli donanımlara (ses, Bluetooth, kamera, sensörler) erişmek için gereken yazılımların konumlandığı katmandır.

> **Ders sonrası not:** Hoca HAL'ı "firmware'lerin, driver'ların bulunduğu katman" olarak tarif etti. Slayttaki diyagramda sürücüler (Drivers) Linux çekirdeği katmanında gösteriliyor; HAL ise üst katmanlara bu donanımlar için standart bir arayüz sunar.

- **Yerel C/C++ kütüphaneleri:** Media Framework, WebKit, Libc gibi kütüphaneler, özellikle native kod geliştirip daha verimli iş yapmak isteyen, düşük seviyede çalışan geliştiriciler için değerlidir.
- **Android Runtime:** Kütüphanelerle aynı seviyededir. Uygulama kodlarımız bu çalışma ortamında çalışır; çekirdek (core) kütüphaneler de bu katmandadır. Ayrıntısı bir sonraki bölümde.
- **Java API Framework:** Content Provider'dan Activity Manager'a, Location Manager'a kadar temel API'lerin bulunduğu katmandır. Geliştirirken en çok bu "üstten ikinci" katmandaki yapılar kullanılır. Her biri için bir yönetici (manager) sağlanır; ilgili sınıflardan türetme yapılarak kendi sınıflarınız üretilir.
- **Sistem uygulamaları:** En üstte, işletim sisteminin hazır sunduğu uygulamalar vardır. Mağazaya bağlanmak istemeyen bir kişinin bile temel işleri yapabilmesini sağlarlar. Örneğin standart bir kamera uygulaması gelir; daha kapsamlı bir kamera uygulaması isteyen mağazadan indirir. SMS uygulamaları için de aynısı geçerlidir. Hoca, işletim sistemlerinin bugün sağlık uygulamaları dahil yaklaşık 15-30 arasında sistem uygulaması sunduğunu söyledi.

## 7. Android Runtime: JIT, AOT, NDK ve SDK

Java Virtual Machine ile başlayan süreçte, Java'nın masaüstü cihazlar için sunduğu yapının daha küçük cihazlara uyarlanması hedeflendi. Bu amaçla uzun süre Dalvik Virtual Machine kullanıldı. Bugün ise Android Runtime (ART) yapısı kullanılıyor. ART'ı anlamak için iki derleme kavramı bilinmeli.

### 7.1 Just-in-time (JIT) derleme

JIT derlemede derleme, uygulama indirildiğinde değil, uygulama çalıştırıldığında yapılır. Uygulamayı indirdiniz ama kullanmadığınız sürece hiçbir derleme yapılmaz, bayt kodlar üretilmez. Dezavantajı şudur: Kod, uygulama ilk çalıştırıldığında ve her çalıştırıldığında üretildiği için büyük uygulamalar yavaş çalışır.

### 7.2 Ahead-of-time (AOT) derleme

Bu sorun yüzünden "önceden derleyelim" mantığı düşünüldü: Derleme aşaması önceden tamamlansın, uygulamaya tıklandığında hazır kod çalışsın. Bu hızlandırır, ama kaynak israfına yol açar: Hiç kullanmayacağınız bir uygulama için de bu dönüşüm yapılır. Ayrıca hem kaynak kod hem çalıştırılabilir kod saklandığı için aynı kodun iki katı boyut tutulmuş olur.

### 7.3 Android'in karma yaklaşımı

Android ikisinin artı ve eksilerini birleştirip karma bir yapıyla yoluna devam etti: Çok sık kullanılma potansiyeli olan ya da zaman içinde sık kullanıldığı gözlenen kısımlar AOT ile önceden derlenip hazır tutulur, az kullanılan kısımlar ise kullanılacakları zaman derlenir.

> **Ek bilgi (derste anlatılmadı):** Dalvik JIT derleme kullanıyordu. ART, Android 5.0 ile kurulum sırasında AOT derlemeye geçti; kurulumların uzaması üzerine büyük olasılıkla Android 7.0'dan itibaren kullanım profiline dayalı JIT + AOT karma derleme benimsendi. Derste anlatılan karma yaklaşım budur.

### 7.4 NDK ve SDK

NDK (Native Development Kit), yerel kütüphanelerin bulunduğu katmandaki kod parçalarını kullanmanızı sağlar. Düşük seviyeli ve performanslı iş yapmak isteyen geliştiricilerin en çok ihtiyaç duyduğu kütüphane bütünüdür. Genel bir geliştirme yapıyorsanız SDK'yı (Software Development Kit, Android SDK) indirmeniz gerekir.

## 8. Activity ve Yaşam Döngüsü

Hoca, Activity yaşam döngüsünü sonraki haftalarda daha ayrıntılı konuşacaklarını, ama mimariyi anlatırken buna ihtiyaç duyduğunu söyleyerek kısa bir giriş yaptı.

Android'de bir uygulama çalıştırıldığında uygulamanın en temel bileşenlerinden biri Activity'lerdir. Her ekran bir Activity demektir: Görülebilen ve üzerinde iş yapılabilen her ekranı bir Activity olarak düşünebilirsiniz. Hocanın benzetmesiyle uygulamayı bir süreç (process) olarak düşünürseniz, Activity'yi de bir iş parçacığı (thread) olarak düşünebilirsiniz. Hoca bunun "çok harika bir benzetme olmasa da" fikir verdiğini belirtti.

### 8.1 Yaşam döngüsü diyagramı

Activity'lerin her biri birbirinden bağımsız bir yaşam döngüsüne sahiptir. Slayttaki diyagram (ekrandan, 01:10:00):

```text
Activity launched
  -> onCreate() -> onStart() -> onResume() -> Activity running
Activity running
  -- başka bir Activity öne gelir --> onPause()
onPause()
  -- kullanıcı Activity'ye döner --> onResume()
  -- Activity artık görünmez --> onStop()
onStop()
  -- kullanıcı Activity'ye gider --> onRestart() -> onStart()
  -- Activity bitiyor ya da sistem yok ediyor --> onDestroy() -> Activity shut down
onPause() / onStop()
  -- daha yüksek öncelikli uygulamalar bellek ister --> App process killed
App process killed
  -- kullanıcı Activity'ye gider --> onCreate()
```

Hocanın anlatımıyla akış şöyledir: Activity'ye girildiğinde (launch edildiğinde) `onCreate`, `onStart`, `onResume` adımlarından geçerek çalışmaya başlar ve ekranda bir şey yaptığınız sürece çalışır. Arkadan bir kesinti (bir telefon araması, bir bildirim) geldiğinde Activity `onPause` durumuna geçer. Ekran tamamen ortadan kalktığında `onStop` durumuna geçer. Activity artık işe yaramayacaksa, siz uygulamayı temizlediğinizde, uygulama çöktüğünde ya da yer kalmadığı için sistem temizlediğinde `onDestroy` ile yaşam döngüsü sona erer. Ama `onStop` durumuna gidip başka bir şey yapıp geri döndüyseniz Activity kaldığı yerden `onRestart` ile tekrar çalışmaya başlar.

Hoca telefon araması örneğini verdi: Eskiden gelen arama tam ekran görünürdü, şimdi bildirim gibi yukarıdan düşüyor. Activity'niz görünür durumda ama etkileşim olmadan arka plana gittiğinde `onPause` durumundadır. Aramaya cevap verdikten ya da reddettikten sonra bildirim ekrandan gidince Activity kaldığı yerden çalışmaya devam eder.

### 8.2 Uygulama ve Activity ilişkisi

Bir Activity hayatta kalıp diğer bütün Activity'ler öldüğünde, uygulama teknik olarak o Activity üzerinden hizmet vermeye devam eder. Uygulamanın bir Activity'sinin kullanılabilmesi için bütün Activity'lerin yaşıyor olması gerekmez. Bu sırada arka planda Activity'ye bağlı bir servis de çalışıyor olabilir.

Android programlamada ilk bilinmesi gereken şey, kullanıcıyla etkileşime giren her ekranın belirli bir işi yapmak için konumlandırılmış bir Activity olduğudur. Örneğin bir e-posta uygulamasında mail yazılan ekran X Activity'si, bütün maillerin listelendiği ekran Y Activity'sidir. Uygulama içinde gezinerek ilgili Activity'nin çağrılması sağlanır. Bir Activity'ye yalnız uygulama içinden mi erişilir? Hayır; başka bir Activity üzerinden ya da başka yollarla da erişilebilir. Activity uygulamaya açılan bir giriş kapısıdır.

### 8.3 Pause ve Stop farkı (soru-cevap)

**Soru:** Pause ile Stop arasındaki fark nedir?

**Cevap:** Stop durumunda Activity ekranı tamamen görünmez olur; ekranda Activity'ye dair hiçbir şey görmezsiniz. Pause durumuna ise bir bildirim ekranı, bir diyalog kutusu ya da bir açılır pencere öne çıkıp Activity'yi arka planda ama görünür bırakınca geçilir. Kısaca: Activity'ye ait görüntü arka planda da olsa ekrandaysa `onPause`, hiç görüntü yoksa `onStop`.

**Soru:** Bildirim çubuğunu yukarıdan aşağı indirdiğimizde Activity pause mu olur?

**Cevap:** Evet. Bildirim çubuğu öne geldiği için Activity'ye erişilemez ve etkileşime giremez; Activity kendini otomatik olarak `onPause` durumuna alır.

Hoca, bu durum geçişleri kullanıcının kendi aksiyonları sonucunda gerçekleştiği için, `onStop` durumuna girildiğinde o andaki verilerin uygun yapılarda saklanması gerektiğini vurguladı. Böylece geri dönüldüğünde kaldığınız yerden devam edebilirsiniz. Verinin bu şekilde korunması ve yönetilmesi çok önemlidir.

## 9. Uygulama Mimarisi İlkeleri ve İyi Uygulamalar

Android'de uygulama geliştirirken dikkat edilmesi gereken temel mimari ilkeler vardır. Üç katmandan söz edilir: UI katmanı (UI Layer), isteğe bağlı Domain katmanı ve Data katmanı. En az iki katmanlı bir yapı kurmanız gerekir; yani arayüz tarafıyla arkada verinin saklandığı taraf birbirinden ayrılmalıdır. Bunun için Model-View-Controller, MVVM gibi farklı yapılar vardır. Amaç şudur: Birincisi veriye doğrudan erişim engellenmeli; ikincisi UI katmanında yapılan bir değişiklik veriyle ilgili sorun çıkarmamalı, veri tarafında yapılan bir değişiklik de UI'da başka değişiklikler gerektirmemelidir.

### 9.1 UI katmanı

UI katmanında iki temel alt blok vardır:

- **UI elemanları:** Bilgiyi gösteren elemanlar, yani View'lar; checkbox'lar, butonlar gibi yapılar.
- **State holder'lar:** O anda bulunduğunuz ekrandaki UI elemanlarının sahip olduğu bilgileri saklayan yapılar. Bir çerçeveye (frame) ya da kaba (container) yerleştirilmiş UI elemanlarını, bir seçim kutusundaki, metin alanındaki ya da TextView'daki bilgiyi saklamaktan sorumludurlar.

### 9.2 Data katmanı

Data katmanında iki tür veri tutan yapı olabilir: repository'ler ve veri kaynakları (data source). Veri kaynakları daha çok dosya, veritabanı, SharedPreferences gibi yapılardır. Hoca repository'yi uzaktan bağlanıp kodların saklanabildiği GitHub benzeri yapılar olarak örnekledi.

> **Ek bilgi (derste anlatılmadı):** Android'in önerdiği mimaride "repository", genellikle uygulamanın verisine (yerel veritabanı, ağ servisi gibi kaynaklara) tek bir giriş noktası sağlayan bir sınıftır; UI katmanı veriye bu sınıf üzerinden ulaşır.

### 9.3 Veriye soyutlama üzerinden erişim

Data katmanında bir soyutlama yapın ve bu yapıya yalnız belirli metotlar üzerinden erişin. Böylece veri, doğrudan erişilerek değiştirilemez. Hoca bunu Java'daki public-private yapısına benzetti: Private bir alana ancak getter ve setter'larla erişebilirsiniz, ama alan public olduğunda nesnenin elemanına doğrudan başvurup değiştirebilirsiniz. Android mimarisi bu soyutlama katmanıyla verinin arka planda yönetilmesini öneriyor.

Slayttaki genel iyi uygulamalar (ekrandan, 01:20:00):

- Do not store data in app components (veriyi uygulama bileşenlerinde saklamayın).
- Reduce dependencies on Android classes.
- Create well-defined boundaries of responsibility between various modules in your app.
- Expose as little as possible from each module.
- Focus on the unique core of your app so it stands out from other apps.
- Consider how to make each part of your app testable in isolation.
- Types are responsible for their concurrency policy.
- Persist as much relevant and fresh data as possible.

Hoca modüler yapının olabildiğince küçük tutulmasını ve bir Activity'de gerekenden fazla iş yapılmamasını vurguladı. Aynı Activity'de mailleri listeleyip yeni mail de yazdırabilirsiniz, ama bunları ayrı ekranlarda tasarlamak işi her zaman kolaylaştırır ve test edilebilirliği artırır. Uygulamanın her parçasının bağımsız test edilebilmesi önemli bir mimari ilkedir. Verinin korunması ve kaybolmaması da önemlidir: Telefonun yapılandırması değiştiğinde, örneğin ekran dikeyden yataya döndürüldüğünde, Activity `onDestroy` ile ölür ve doldurduğunuz forma, o ekrana ait bütün bilgiler kaybolur. Android buna karşı alınabilecek önlemleri sunar ve kodu buna uygun geliştirmeyi önerir.

### 9.4 Mimariye neden önem veriyoruz?

Hoca, bir slaydın yanlış yere kaydığını fark edip mimarinin yararlarını anlatan slayda geri döndü:

- Uygulamanın ölçeklenebilirliğini mümkün kılar.
- Testi hızlandırır, hata ayıklamayı kolaylaştırır.
- Uygulamanın yönetilebilirliğini ve bakım yapılabilirliğini iyileştirir, kalitesini artırır.
- Bunlar kullanıcı deneyimine yansır: Mimarisi sağlam bir uygulamada kullanıcı bir Activity'de çok beklemez ya da kaybolup ne yapacağını bilemez duruma düşmez; veri akışı hızlanır.

## 10. İlk Uygulamayı Tasarlarken: Giriş Noktaları ve Farklı Cihazlar

Slayttaki başlıklar (ekrandan, 01:25:00):

- Apps provide multiple entry points
  - Components: Activity, BroadcastReceivers, Services, ...
  - App Icon, Different Activity, Notification, Different App
- Apps adapt to different devices
  - Different layouts for different screen sizes
  - Specific hardware

Bir uygulamaya giriş yapmak için genellikle Activity'ler kullanılır, ama servisler ve Broadcast Receiver'lar da giriş imkânı tanır. Bir uygulama açıldığında başlayan bir "launcher" Activity'si vardır. Uygulamada birden fazla Activity varsa ilk açılışta hangisinin çalışacağını bilmesi için bunun tipini launcher olarak belirlemelisiniz; bu tanım Android Manifest'te yapılır. Uygulamanın ikonu ve adı da mutlaka tanımlanmalıdır.

Tek tip bir ekranı düşünmek akıllıca değildir; çok farklı ekran boyutlarına sahip cihazlar vardır. Cihaz döndürüldüğünde dikey ve yatay kullanım için tasarlanan layout'un farklı olması gerekir ve layout'lar ekran boyutuyla uyumlu hâle getirilmelidir. Bazı uygulamalar tek bir eksende çalışmayı tercih eder; bir ayarla telefon döndürüldüğünde Activity'nin yeni bir layout'a geçmesi engellenebilir. Örneğin bunu engellemiş bir video uygulaması, telefonu dikeye çevirseniz de yatay görüntüsünde kalır; geliştirici ekran yönünü (orientation) kilitlemiştir. Ama çoğu uygulama döndürülebilir olduğu için ekran boyutlarına göre tasarım önem kazanır.

Eskiden yalnız ekran boyutu ya da piksel sayısı üzerinden gidiliyordu. Sonra belirli oranlar gelmeye başladı ve oransal tasarıma geçildi. Bu, mobil web teknolojisindeki duyarlı (responsive) tasarımın, yani bir sayfanın tablette genişleyip telefonda küçülmesinin kolaylığını Android'e de getirdi. Bunun için DPI (density per inch) değerleri verilerek uygulamanın görselliği farklı cihazlar için daha yönetilebilir ve düzgün hâle getirilir.

## 11. Diller, APK ve Android App Bundle

Android'de uygulama geliştirmek için Kotlin, Java ve C++ kullanılır; Kotlin'in her geçen gün daha yaygınlaştığı rahatlıkla söylenebilir. C++ çok yoğun kullanılmaz; hoca bunun daha çok NDK ile kullanıldığını hatırlattı.

Birden fazla Activity, belki servis ya da Broadcast Receiver yazdınız; bunların hepsi kaynak kodunuzu oluşturur. Bir de layout gibi kaynak dosyalarınız (resource files) vardır; bunlar genellikle XML biçiminde saklanır. Hepsi birlikte paketlendiğinde bir APK paketi elde edilir ve Android bu paketi çalıştırarak derlenmiş sürümü kullanmanızı sağlar. Slayttaki tanımlar (ekrandan, 01:30:00):

- Code and resource files are compiled into APK.
- APK (Android Package), `.apk` uzantılı bir arşiv dosyasıdır; uygulamanın çalışma anında gereken içeriğini taşır ve Android cihazlar uygulamayı bu dosyayla kurar.
- Android App Bundle, `.aab` uzantılı bir arşiv dosyasıdır; uygulama projesinin içeriğini, çalışma anında gerekmeyen bazı ek meta verilerle birlikte içerir.

Android App Bundle (AAB), APK'nın bir alternatifi değildir. Bütün farklı cihazlar için olası kaynak kodların ve kaynak dosyalarının yüklendiği bir arşivdir. Mağazadan uygulama indirilirken Google Play, kullanıcının cihazına özgü donanım ve yazılıma göre ilgili kodların inmesini sağlar. Örneğin cihazınızda uygulamanın kullandığı bir sensör yoksa, o sensörle ilgili kısımlar telefonunuza indirilmez. Google Play donanım ve yazılım yeteneklerini, uygulamanın hangi parçalarının bunlarla uyumlu çalışabileceğini denetler; kullanılamayacak parçaları yüklemez. Böylece hocanın örneğiyle 100 MB'lık bir paket 80 ya da 70 MB'a inerek yalnız sizin cihazınıza uygun yapılandırmayla gelir. Ekran boyutu ve çözünürlük de analiz edilir; başka cihazlar için konmuş resimler otomatik elenir.

Bu şu demektir: Siz kodu her cihazda çalışacak şekilde planlarsınız ve bir App Bundle oluşturursunuz. App Bundle mağazadan indirilirken bu ayıklama yapılır ve uygun kod ve kaynak dosyaları indirilir. AAB yokken yalnız APK oluşturuluyordu ve her şey her cihaza yükleniyordu.

> **Ders sonrası not:** Hoca AAB'nin "yaklaşık 6-7 sene önce" hayatımıza girdiğini söyledi. AAB büyük olasılıkla 2018'de tanıtıldı; ders tarihinde (2023) yaklaşık 5 yıllıktı.

## 12. En Az Ayrıcalık İlkesi

Slayttaki metin (ekrandan, 01:35:00) üç maddeden oluşuyordu: Her uygulama varsayılan olarak yalnız işini yapmak için gereken bileşenlere erişir; iki uygulama aynı Linux kullanıcı kimliğini paylaşacak biçimde düzenlenebilir ve bu durumda birbirinin dosyalarına erişebilir, kaynak tasarrufu için aynı Linux sürecinde ve aynı VM'de çalışabilir, ama aynı sertifikayla imzalanmış olmalıdır; bir uygulama konum, kamera, Bluetooth gibi cihaz verilerine erişmek için izin isteyebilir ve kullanıcı bu izinleri açıkça vermelidir.

Hocanın anlatımıyla: Her süreç ayrı bir kullanıcı olacak biçimde kendi sanal makinesinde çalışır; hiçbir süreç istenmedikçe başka bir sürecin alanına giremez. Android bunu her uygulama için ayrı bir sanal makine üreterek sağlar. İki farklı uygulamanın kodları tamamen ayrı bölgelerde çalışır, en düşük düzeyde temas hâlinde olacak şekilde konumlanır; buna en az ayrıcalık ilkesi (principle of least privilege) denir.

Bunun tersi de mümkündür. Her uygulamanın farklı bir kullanıcı kimliği (user ID) vardır; ama iki uygulama birbiriyle veri paylaşacaksa aynı kullanıcı kimliğine sahip olacak biçimde düzenlenip aynı VM içinde çalıştırılabilir. Bu hem veri aktarımını hızlandırır hem de kaynak tasarrufu sağlar: Boşuna yeni bir sanal makine açılmaz, yeni bir süreç tablosu oluşturulmaz. Bunun için birbiriyle paylaşım yapacak iki ya da üç uygulamanın aynı sertifikayla imzalanması gerekir.

Uygulama yalnız başka uygulamalarla değil, çalıştığı cihazın GPS'i, kamerası, Bluetooth'u gibi kaynaklarla da etkileşmek isteyebilir. Uygulama yalnız kendi hakları dahilinde iş yapabildiği için kameraya erişmek onun kendi hakkı değildir; bu izin ya kurulum sırasında (install time) ya da çalışma sırasında (runtime) mutlaka alınmalıdır.

## 13. Temel Uygulama Bileşenleri

Android programlamada dört temel uygulama bileşeni vardır: Activity'ler, servisler, Broadcast Receiver'lar ve Content Provider'lar. Her uygulamada hepsi kullanılmak zorunda değildir, ama uygulama bu bloklarla inşa edilir. Bir uygulamada olmazsa olmaz bir diğer dosya Android Manifest'tir: Kuralların tanımlandığı, izinlerin verildiği ya da alındığı bu dosyanın adı her Android uygulaması için `AndroidManifest.xml`'dir. Kaynak koda ek olarak uygulama kaynakları (View'lar, layout'lar, çeşitli XML dosyaları) da vardır.

Hoca Android programlamayı ikiye ayırdı:

- **İş mantığı (business logic):** Verinin yönetildiği ve işlendiği kısımdır. Temel bileşenlerle (Activity, Service vb.) Java ya da Kotlin ile yazılır.
- **Kullanıcı arayüzü:** Verinin görselleştirilip ekrana yansıtıldığı kısımdır. Layout'lar ve kaynak dosyaları XML sözdizimiyle düzenlenir.

### 13.1 Activity

Activity, kullanıcının uygulamanın herhangi bir modülüyle etkileşime girdiği noktalardan biridir ve tek bir ekran üzerinden bir kullanıcı arayüzü sunar. E-posta uygulaması örneğinde giriş ekranı bir Activity, giriş yaptıktan sonra gelen maillerin listelendiği ekran başka bir Activity, bir mailin ayrıntısına girilen ekran başka bir Activity, yeni mail yazılan ekran başka bir Activity'dir. Her biri kullanıcının bir iş yaptığı ve telefonla aksiyon alabildiği bir ekranı temsil eder.

### 13.2 Service

Servis, uzun süreli çalışacak işler için sunulmuş bir bileşendir ve kullanıcı arayüzü gerektirmez. Örneğin bir müzik uygulamasının arka planda çalışabilmesi için genelde servis kullanılır. Bugün arka plan görevleri için başka özel yapılar da var; servisler daha uzun süreli, arka planda kesintisiz çalışma gereken işlemler için kullanılıyor. Slayttaki tanım (ekrandan, 01:40:00): Servis, uzun süren işlemleri yapmak ya da uzak süreçler için iş yapmak üzere arka planda çalışan bir bileşendir; kullanıcı arayüzü sunmaz; sistem, kullanıcı için daha acil işlere RAM gerekirse servisi sonlandırabilir (ve daha sonra yeniden başlatabilir).

Servislerin kaynak tüketimi vardır. Android bir kaynağa ihtiyaç duyduğunda, kullanıcı etkileşimi olmadığı için ilk feda edeceği bileşenlerden biri servislerdir. RAM'de yeterli alan kalmazsa sistem inisiyatif kullanıp servisleri sonlandırabilir ve arka plan işiniz kesintiye uğrayabilir. Bu yüzden Android servislerin sürekliliğini hiçbir zaman garanti etmez.

### 13.3 Broadcast Receiver

Broadcast Receiver'lar sistem ve diğer uygulamalar hakkında bilgi almanın ve bilgi paylaşmanın en güzel yoludur. Telefon şarjda mı, batarya kritik seviyeye mi geldi, şarj doldu mu, bir Wi-Fi ağına bağlı mı, hücresel bağlantı var mı gibi sistem düzeyinde bir değişiklik olduğunda bu bilgi diğer bütün uygulamalara duyurulur. Bu yayınla-abone ol (publish-subscribe) mantığıdır: Sistem bilgiyi yayınlar, buna abone olan uygulama da yayınlandığı anda öğrenir. Her uygulama sistemdeki her değişikliği takip etmek istemez; uygulamanızda neyi takip etmek istediğinizi belirterek gelişmeleri izler ve buna göre önlem alırsınız.

Bazen tersi gerekir: Uygulamanızın sistemde çalışan diğer uygulamaları bilgilendirmesi gerekebilir. O zaman uygulama bir broadcast mesajı yayınlayarak diğer uygulamaları bilgilendirir. Hoca, Broadcast Receiver'ların masaüstündeki kesmelere (interrupt) ve onların takibine karşılık geldiğini söyledi; sistem düzeyindeki bütün mesajların takip edilmesini mümkün kılarlar.

### 13.4 Content Provider

Content Provider'lar uygulamalar düzeyinde veri paylaşımı yapmayı mümkün kılan yapılardır. Başka bir uygulamanın verisinin okunması ve erişilmesi için kullanılır; ilgili izinler alınmak koşuluyla veri paylaşımı yapılabilir. Dört temel yapıdan biridir ama diğerleri gibi bir giriş noktası (entry point) değildir; daha çok veri paylaşımı için kullanılır.

## 14. Intent

Bileşenler arasında, özellikle Activity'ler arasında bilgi taşımak gerekir. Bu işlem Intent ile yapılır. Activity, servis ve Broadcast Receiver olmak üzere üç bileşeni etkinleştiren asenkron mesaj tipine Intent denir. A Activity'sinden B Activity'sine geçerken ya geçişin kendisi için ya da iş yaparken belirli bir bilgiyi taşımak, mesajlaşmak için Intent kullanılır. Intent yalnız uygulama içi geçiş için değil, başka bir uygulamadan bir Activity'yi çağırmak için de kullanılabilir.

İki tür Intent vardır:

- **Explicit (açık) Intent:** Hoca bu türü adıyla andı. <!-- BELİRSİZ: 01:57:03-01:57:16 arasında altyazı boş; explicit Intent'in derste nasıl tanımlandığı okunamıyor (genel tanım: çağrılacak bileşenin sınıf adının açıkça verildiği Intent). -->
- **Implicit (örtük) Intent:** Yalnız yapılmak istenen iş bildirilir; sistem bu işi yapabilen Activity'leri listeler. Örneğin e-posta göndereceksiniz: Yalnız e-posta gönderme isteğinizi bildirirsiniz, sistem e-posta gönderebilen bütün uygulamaları listeler. Fotoğraf çekeceksiniz: Sistem, içinde bu özelliğe sahip Activity barındıran bütün uygulamaları gösterir.

## 15. AndroidManifest.xml

Manifest dosyası olmazsa olmaz dosyalardandır. Bu XML dosyasında uygulamanıza ait bütün bileşenler tanımlanır: uygulamanın adı ve ikonu, tanımlanan Activity'ler, servis, Intent, Broadcast Receiver olup olmadığı, telefonun donanımsal ya da yazılımsal bir kısıtı olup olmadığı, uygulamanın hangi yeteneklere sahip olduğu ve hangi özelliklere sahip telefonlarda çalışabileceği. Bu bir yapılandırma dosyasıdır; doğru düzenlenmezse uygulama çalışmayabilir.

Slayttaki örnekler (ekrandan, 02:00:00):

```xml
<?xml version="1.0" encoding="utf-8"?>
<manifest ... >
    <application android:icon="@drawable/app_icon.png" ... >
        <activity android:name="com.example.project.ExampleActivity"
                  android:label="@string/example_label" ... >
        </activity>
        ...
    </application>
</manifest>
```

Bu ilk örnekte uygulamaya ait bir Activity tanımlanmıştır: Paket adı `com.example.project`, Activity'nin adı `ExampleActivity`'dir. Activity'nin etiketi (label) `@string/example_label` ile string kaynağından alınır.

```xml
<manifest ... >
    ...
    <application ... >
        <activity android:name="com.example.project.ComposeEmailActivity">
            <intent-filter>
                <action android:name="android.intent.action.SEND" />
                <data android:type="*/*" />
                <category android:name="android.intent.category.DEFAULT" />
            </intent-filter>
        </activity>
    </application>
</manifest>
```

İkinci örnekte Activity'nin bir intent filter'ı vardır. `action` etiketindeki `SEND` ile sisteme şu bildirilir: "Uygulamamın içinde ComposeEmailActivity adlı bir Activity var ve bu Activity e-posta gönderebilir. Gönder isteği üreten başka bir uygulama varsa bu Activity'den yararlanabilir." Böylece Activity'lerinizin neler yapabildiğini manifestte bildirerek diğer uygulamaların bundan haberdar olmasını sağlarsınız.

```xml
<manifest ... >
    <uses-feature android:name="android.hardware.camera.any"
                  android:required="true" />
    <uses-sdk android:minSdkVersion="7" android:targetSdkVersion="19" />
    ...
</manifest>
```

Üçüncü örnekte `uses-feature` ile uygulamanın bir kameraya ihtiyaç duyduğu bildirilir; `required="true"` olduğu için kamerası olmayan bir telefon Play Store'a girdiğinde bu uygulama önüne getirilmez. Hoca, bugün kamerasız telefonun pek olmadığını, bunun yalnız bir örnek olduğunu belirtti. Değer `false` olsaydı "bu özelliğe ihtiyaç duyuyorum ama zorunlu değil" denmiş, yani bazı özelliklerin bu eksiklikte çalışmayacağı bildirilmiş olurdu. `uses-sdk` ile hedeflenen SDK belirtilir: Minimum SDK sürümü 7 olarak belirlendiği için Google Play, SDK sürümü 7'den düşük telefonları filtreler ve bu kullanıcılar uygulamayı göremez, indiremez.

## 16. Uygulama Kaynakları (App Resources)

App Resources, ek dosyaların ve statik içeriğin saklandığı dosyalardır: resimler, layout'lar, arayüzdeki butonların adları, farklı dillerdeki metinler, animasyonlar gibi doğrudan arayüzü etkileyen kaynaklar. Slayttaki proje yapısı (ekrandan, 02:05:00):

```text
MyProject/
    src/
        MyActivity.java
    res/
        drawable/
            graphic.png
        layout/
            main.xml
            info.xml
        mipmap/
            icon.png
        values/
            strings.xml
```

`src` klasörü altında kaynak kod, `res` (resource) klasörü altında resimler, bazen ses dosyaları, Activity'lerin kullandığı ekranlar, ikonlar ve ekrandaki widget'ların adlarının, sabitlerinin saklandığı yapılar bulunur. Slayttaki kaynak örnekleri:

```xml
<?xml version="1.0" encoding="utf-8"?>
<resources>
    <string name="hello">Hello</string>
    <string name="hi">@string/hello</string>
</resources>
```

```xml
<?xml version="1.0" encoding="utf-8"?>
<resources>
    <color name="red">#f00</color>
    <color name="highlight">@color/red</color>
</resources>
```

```xml
<?xml version="1.0" encoding="utf-8"?>
<EditText xmlns:android="http://schemas.android.com/apk/res/android"
    android:layout_width="fill_parent"
    android:layout_height="fill_parent"
    android:textColor="@color/opaque_red"
    android:text="@string/hello" />
```

```xml
<?xml version="1.0" encoding="utf-8"?>
<EditText xmlns:android="http://schemas.android.com/apk/res/android"
    android:layout_width="fill_parent"
    android:layout_height="fill_parent"
    android:textColor="@android:color/secondary_text_dark"
    android:text="@string/hello" />
```

```xml
<Button
    android:layout_width="fill_parent"
    android:layout_height="wrap_content"
    android:text="@string/submit" />
```

```xml
<ImageView
    android:layout_height="wrap_content"
    android:layout_width="wrap_content"
    android:src="@drawable/myimage" />
```

Hoca `strings.xml`'deki adlandırmayı C'deki `#define` ile karşılaştırdı: C'de `#define N 100` yazınca derleyici `N` gördüğü her yere 100 yazar; burada da bir ad tanımlarsanız o adın değeri sistematik biçimde bu dosyada saklanır. Renkler için `colors.xml` vardır; renk kodlarını anlaşılır adlarla tanımlayıp kodda bu adları kullanırsınız. Bir EditText'in rengi `@color/...` ile `colors.xml`'den, metni `@string/hello` ile `strings.xml`'deki `hello` değişkeninden alınır. Butonun üzerinde ne yazacağı da `@string/submit` ile belirlenir; hoca Türkçe bir uygulamada bunun karşılığının "Gönder" olması gerektiğini söyledi.

Metni `android:text` içine çift tırnakla doğrudan "Gönder" diye de yazabilirsiniz, ama o zaman dil değiştiğinde ya da aynı metni tekrar kullanmak istediğinizde sabit kod (hard code) yazmış olursunuz. Bu yüzden parametrik tanımlamak daha akıllıcadır. ImageView'da hangi resmin yer alacağı da resmi `drawable` altına yerleştirip `@drawable/...` ile belirtilir.

## 17. Yapılandırma Değişiklikleri ve İzinler

### 17.1 Yapılandırma değişiklikleri

Cihazın herhangi bir yapılandırması değiştiğinde Activity ölür ve arayüzdeki bilgiler kaybolur. Ekran yönünün değişmesi, çoklu pencere moduna geçilmesi gibi çeşitli yapılandırma değişiklikleri vardır. Bu bilgileri kaybetmemek için `onSaveInstanceState` metodu ile bilgiler saklanır, Activity yeniden başlatıldığında geri yüklenir.

### 17.2 İzin alma yolları

İzinler kritiktir; alınmazsa sistem düzeyindeki bilgilere erişilemez. Eskiden izinler yalnız uygulama kurulurken bir kez soruluyordu. Artık iznin türüne bağlı olarak bazı izinler kurulum sırasında, manifestte yazdığınız biçimde alınır; çok kritik bir bilgiye erişilecekse izin çalışma anında (runtime) istenir. Kişisel bilgi içermeyen, genel bir izin talep ediyorsanız bunu manifeste yazabilirsiniz. Çalışma anında kullanıcıya bir kez mi yoksa her erişim için mi izin verdiği de sorulabilir.

İzinler normal izinler ve tehlikeli (dangerous) izinler olarak ikiye ayrılır. Cihazın çalışmasını riske atmayan izinler normal izin olarak alınır. Kullanıcı mahremiyetini tehlikeye atabilecek ya da cihazın çalışmasını engelleyebilecek izinler tehlikeli izin olarak adlandırılır. Çalışma anı istekleri Android 6 ve sonrasında geldi: Bir işlem sırasında örneğin bir dosyaya erişeceğiniz zaman bir açılır pencere çıkar ve izin verip vermediğiniz sorulur; bazen bu iznin süresiz verilip verilmediği de sorulur. Sonuç olarak izinleri ya manifestte bildirerek alacaksınız ya da kodunuzda çalışma anında alacak kodu yazacaksınız.

Kurulum anı istekleri hoca tarafından eski bir Android sürümüyle ilişkilendirildi. <!-- BELİRSİZ: altyazıda "5.11 ile karşınıza çıkan requestler" geçiyor; büyük olasılıkla Android 5.1.1 ve öncesi kastedildi. --> Donanım özellikleriyle ilgili istekler için `uses-feature` kullanılır.

### 17.3 Normal izinler

Slayta göre Android 9 (API level 28) itibarıyla şu izinler `PROTECTION_NORMAL` olarak sınıflandırılır (ekrandan, 02:10:00): `ACCESS_LOCATION_EXTRA_COMMANDS`, `ACCESS_NETWORK_STATE`, `ACCESS_NOTIFICATION_POLICY`, `ACCESS_WIFI_STATE`, `BLUETOOTH`, `BLUETOOTH_ADMIN`, `BROADCAST_STICKY`, `CHANGE_NETWORK_STATE`, `CHANGE_WIFI_MULTICAST_STATE`, `CHANGE_WIFI_STATE`, `DISABLE_KEYGUARD`, `EXPAND_STATUS_BAR`, `FOREGROUND_SERVICE`, `GET_PACKAGE_SIZE`, `INSTALL_SHORTCUT`, `INTERNET`, `KILL_BACKGROUND_PROCESSES`, `MANAGE_OWN_CALLS`, `MODIFY_AUDIO_SETTINGS`, `NFC`, `READ_SYNC_SETTINGS`, `READ_SYNC_STATS`, `RECEIVE_BOOT_COMPLETED`, `REORDER_TASKS`, `REQUEST_COMPANION_RUN_IN_BACKGROUND`, `REQUEST_COMPANION_USE_DATA_IN_BACKGROUND`, `REQUEST_DELETE_PACKAGES`, `REQUEST_IGNORE_BATTERY_OPTIMIZATIONS`, `SET_ALARM`, `SET_WALLPAPER`, `SET_WALLPAPER_HINTS`, `TRANSMIT_IR`, `USE_FINGERPRINT`, `VIBRATE`, `WAKE_LOCK`, `WRITE_SYNC_SETTINGS`.

Hoca örnek olarak duvar kâğıdı ayarlama, Wi-Fi durumunun değişip değişmediğini öğrenme ve ön plan servisi (foreground service) çalıştırma haklarını verdi; bunlar kişisel sayılmadığı için normal düzeydedir.

### 17.4 İmza (signature) izinleri

İmza izinleri kurulum sırasında alınan izinlerdir. Bu izinleri talep edebilmek için uygulamanızın, izni tanımlayan uygulamayla aynı sertifikayla imzalanmış olması gerekir.

### 17.5 Tehlikeli izinler

Tehlikeli izinlerde kişisel bilgiler öne çıkar: takvimi okuma ve yazma, arama kayıtlarını okuma ve yazma, kamerayı kullanma, kişi bilgilerine erişme, mikrofondan kayıt yapma, telefonla arama başlatma, sensörlere erişim, SMS'ler ve depolama. Konum bilgisi de mahremiyet açısından çok kritik olduğu için bunların arasındadır. Hoca, gerçekten ihtiyaç duyulmayan izinleri istemenin kullanıcıyı rahatsız edebileceğini, uygulamanın indirilmemesine ya da kurulmamasına yol açabileceğini vurguladı.

> **Ders sonrası not:** Hoca tehlikeli izinlerin "hem install time sırasında mutlaka sorulması" gerektiğini söyledi. Android 6 ve sonrasında tehlikeli izinler manifestte bildirilir, ama kullanıcıya kurulumda değil çalışma anında sorulur.

İzin istemenin iki yolu vardır: Biri manifest üzerinden, diğeri bulunulan Activity'nin bağlamı (context) üzerinden `checkSelfPermission` ve `requestPermissions` metotlarıyla.

> **Ek bilgi (derste anlatılmadı):** Çalışma anı izin akışında önce `checkSelfPermission` ile izin zaten verilmiş mi diye bakılır; verilmemişse `requestPermissions` ile sistem izin penceresi açılır ve kullanıcının cevabı `onRequestPermissionsResult` geri çağırmasıyla Activity'ye bildirilir.

## 18. Android Studio ile İlk Proje

### 18.1 Proje oluşturma ve Gradle

Android projesi oluşturmak için Android Studio gerekir. Android Studio ücretsiz bir tümleşik geliştirme ortamıdır (IDE); ilgili SDK'lar yüklenerek uygulama geliştirilir. Java ile geliştirme yapılıyorsa Java Development Kit ve Java Runtime Environment da yüklenmelidir. Yeni bir proje için "Create New Project" denir, uygulama adı ve alan adı verilir, Activity tiplerinden biri seçilir. Mutlaka bir layout dosyası ve bir manifest dosyası olmalıdır.

Gradle, dosyaların derlenmesi ve paketlenmesi (build) için kullanılan yapıdır. Gradle'ın çeşitli sürümleri vardır; internetten alınan kod parçalarıyla çalışırken sürüm uyumsuzlukları çıkabilir. Bu yüzden Gradle sürümünü ve SDK'ları çalıştırılacak projenin dosyalarıyla uyumlu hâle getirmek gerekir.

### 18.2 Uygulamayı çalıştırma

Slayttaki "Run Your App" başlığında iki seçenek vardı (ekrandan, 02:15:00): gerçek cihazda çalıştırma (Geliştirici Seçenekleri'nde USB hata ayıklamayı etkinleştir) ve emülatörde çalıştırma (yeni bir sanal cihaz oluştur).

Gerçek bir telefona Android Studio'dan uygulama yükleyebilmek için Geliştirici Seçenekleri (Developer Options) etkinleştirilmelidir. Bunun için telefonun "Hakkında" bölümündeki derleme numarasına (build number) 7 kez dokunulur. Hoca bu sayede USB hata ayıklamanın da açıldığını söyledi.

> **Ders sonrası not:** Slayttaki ifadeye göre USB hata ayıklama, Geliştirici Seçenekleri açıldıktan sonra bu menünün içinden ayrıca etkinleştirilir.

Geliştirici Seçenekleri daha sonra kapatılabilir. Hoca bunun önemli olduğunu belirtti: Geliştirici Seçenekleri herhangi bir uygulamanın telefona doğrudan yüklenip çalıştırılabilmesi demektir; açık olduğunda tehditlere de açıksınız. İndirip çalıştırdığınız, içeriğini bilmediğiniz bir kod parçası telefonunuza zarar verebilir.

İlk etapta basit bir arayüz tasarlanacak. Bunun için layout'lar, metin kutuları, butonlar gibi UI bileşenleri kullanılacak. Layout'lar bileşenlerin nasıl yerleşeceğini belirleyen yapılardır (LinearLayout, GridView gibi); konumlandırma XML dosyasında yapılır. Kodu yazmak ile layout ayrı işlerdir ve bunların birbiriyle ilişkilendirilmesi gerekir.

### 18.3 Android Studio arayüzü

Hoca Android Studio'yu açıp menüleri gösterdi:

- **New:** Yeni proje başlatılır; projeye Java sınıfı, Kotlin dosyası, kaynak dosyası ve çeşitli bileşenler eklenebilir. Fragment'lar, bir Activity içinde ekranın parçalara bölünerek kullanılmasını sağlar; hoca bunun şimdilik öncelik olmadığını söyledi. Asset eklenebilir; "Import Project" ile indirilmiş bir Android projesi içe aktarılabilir.
- **Sync Project with Gradle Files:** Gradle dosyalarıyla ilgili sorun olup olmadığı buradan öğrenilir.
- **Tools → SDK Manager:** Hangi SDK'ların yüklü olduğu, hangilerinin kısmen yüklü ya da yüklü olmadığı görülür. Sürümlerin adları ve API seviyeleri listelenir; çalışılacak sürüme uygun SDK dosyaları yerele indirilir. Android SDK konumu da buradan değiştirilebilir. <!-- BELİRSİZ: hocanın bilgisayarında yüklü SDK sürümleri altyazıda "8.18 ve 7.11" diye bozuk geçiyor; kare okunmadı. -->
- **Tools → Device Manager** (ekrandan, 02:20:00): "Create Virtual Device" ile telefon, tablet, saat için sanal cihaz oluşturulur; boyut, çözünürlük ve yoğunluk özelleştirilebilir. Geliştirilen uygulamanın o cihazda nasıl davrandığı emülatörde görülür. Bağlı gerçek cihazlar da burada listelenir; hocanın bağladığı cihazda Android 8.0 vardı. Uygulamalar hem sanal hem fiziksel cihaza yüklenebilir.

### 18.4 Hello World projesinin yapısı

Proje yapısında `manifests` klasörü altında `AndroidManifest.xml`, `java` klasörü altında `codepath.demos.helloworlddemo` paketinde `HelloWorldActivity`, `res` altında `drawable`, `layout`, `menu`, `values` klasörleri vardı. Manifestte launcher Activity şöyle tanımlanmıştı (ekrandan, 02:20:00):

```xml
<intent-filter>
    <action android:name="android.intent.action.MAIN" />
    <category android:name="android.intent.category.LAUNCHER" />
</intent-filter>
```

`res/layout/activity_hello_world.xml` dosyası (ekrandan, 02:25:00):

```xml
<RelativeLayout xmlns:android="http://schemas.android.com/apk/res/android"
    xmlns:tools="http://schemas.android.com/tools"
    android:layout_width="match_parent"
    android:layout_height="match_parent"
    tools:context=".HelloWorldActivity" >

    <TextView
        android:layout_width="wrap_content"
        android:layout_height="wrap_content"
        android:layout_centerHorizontal="true"
        android:layout_centerVertical="true"
        android:text="Hello world!"
        android:textSize="25sp" />

</RelativeLayout>
```

Ekranda "Hello World" yazısı görmek için bir TextView tanımlamak yeterlidir. `wrap_content`, widget'ın boyutunun içeriği kadar olacağını söyler; istenirse belirli bir boyut da verilebilir. `layout_centerHorizontal` ve `layout_centerVertical` değerleri `true` yapılarak metin ortaya konumlandırılır. `textSize` metnin boyutudur.

Editör `android:text` değerini "Hello world!" olarak gösteriyordu; hoca üzerine tıklayınca aslında `@string/hello_world` yazıldığını, bunun `values` altındaki `strings.xml` dosyasında `hello_world` adlı değişkene başvurduğunu gösterdi. Bu değer "Merhaba Dünya" yapılınca ekranda da "Merhaba Dünya" görüldü; çünkü TextView `@` işaretiyle o değişkene başvurur ve hangi XML dosyasına başvurduğunu söyler.

Layout yalnız kod olarak, "Split" ile kod ve tasarım yan yana ya da "Design" ile görsel olarak düzenlenebilir. Design görünümündeki palette butonlar, ImageView, RecyclerView; metin altında düz metin ve parola alanları; butonlar altında RadioGroup, normal buton, ImageButton; widget'lar altında ProgressBar, SeekBar, RatingBar; layout'lar altında LinearLayout (yatay ve dikey), FrameLayout, TableLayout gibi kaplar (container) bulunur. Kaplar UI bileşenlerini barındırmak için kullanılır. Bir bileşen seçilince özellikleri yan panelde ayarlanabilir. Bazıları bu aracı, bazıları XML kodu yazmayı tercih eder; ikisi de kullanılabilir.

### 18.5 HelloWorldActivity sınıfı

`HelloWorldActivity.java` dosyası (ekrandan, 02:30:00):

```java
package codepath.demos.helloworlddemo;

import android.os.Bundle;
import android.app.Activity;
import android.view.Menu;

public class HelloWorldActivity extends Activity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_hello_world);
    }

    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        // Inflate the menu; this adds items to the action bar if it is present.
        getMenuInflater().inflate(R.menu.activity_hello_world, menu);
        return true;
    }
}
```

- **Paket adı:** Genellikle web adresinin tersi biçiminde verilir; örneğin yildiz.edu.tr için `tr.edu.yildiz`.
- **import:** Activity'nin ya da menünün ihtiyaç duyduğu sınıflar içe aktarılır. Hoca yıldızlı (`*`) içe aktarmanın paketteki her şeyi getireceğini, boyutu büyüteceğini, bu yüzden yalnız ihtiyaç duyulanların içe aktarılması gerektiğini söyledi (bu iddia için bölüm sonundaki "Ders sonrası not"a bakın).
- **extends Activity:** Sınıf Activity'den türetilir; kendi Activity'nizin adını verirsiniz. Adın "Activity" ile bitmesi zorunlu değil ama genelde böyle adlandırılır.
- **onCreate:** Activity'nin mutlaka override etmesi gereken metottur. Parametresi `Bundle savedInstanceState`, Activity kapanırken saklanmış bir bilgi varsa onun buraya geri verilmesini sağlayan nesnedir. Ayrıntısı sonraki derste.
- **setContentView:** Bu Activity'nin hangi layout ile eşleştirildiğini söyler. Hocanın benzetmesiyle Activity "ben `activity_hello_world` layout'unu kendime kıyafet olarak kullanacağım" der; ilk Activity'yi giydirdiğiniz yer burasıdır. Activity, `activity_hello_world.xml` dosyasındaki UI bileşenlerini alır ve kullanıcının önüne onlarla çıkar. Arayüz ile kod arasındaki ilişkinin ilk adımı budur.
- **onCreateOptionsMenu:** Bu örnek için kritik değildir; silinebilir, varsayılan olarak gelir.

Bundan sonra yapılacak iş, layout tarafındaki bileşenlerle Java tarafındaki bileşenler arasında `R` dosyası üzerinden ilişki kurmak, butondan alınan bilgiyi Java tarafına alıp işlemek ve ekrana tekrar yazdırmaktır; bu sonraki derste yapılacak.

> **Ek bilgi (derste anlatılmadı):** `R` sınıfı derleme sırasında otomatik üretilir; `res` altındaki her kaynak için bir tamsayı kimlik içerir. `R.layout.activity_hello_world` layout dosyasına, `R.string.hello_world` ise `strings.xml`'deki metne karşılık gelir.

### 18.6 Soru-cevaplar

**Soru:** Bu derste konuşulan başlıklar iOS için de geçerli mi?

**Cevap:** Hayır. Dersin ikinci bölümündeki slaytlar tamamen Android'e özeldi. iOS'ta da bileşenler, paket biçimi (Android'deki APK'nın karşılığı olarak IPA), katmanlı bir işletim sistemi ve layout yapısı var, ama bunlar tamamen farklı ve bağımsız.

**Soru:** Yıldızlı import bütün sınıfları alıp boyutu büyütüyorsa, uygulama APK'ya çevrilirken bunu optimize etmiyor mu?

**Cevap (hoca):** Hayır, etmiyor. İçe aktarılan kütüphane bilgisi o Activity'ye aittir ve cihaz tipine göre bir karar verilmez; kaynak dosyada yer alır. Bunu APK ya da App Bundle çözmez. App Bundle ağırlıklı olarak cihazın sürümüne göre davranır; örneğin cihaz Android 8.0 ise Android 9.0'ın dosyalarını yüklemez.

> **Ders sonrası not:** Java'da `import` yalnız derleme zamanında sınıf adlarının çözülmesini sağlar; yıldızlı import, derlenmiş koda kullanılmayan sınıfları eklemez ve uygulama boyutunu büyütmez. Android sınıfları (`android.*`) zaten cihazdaki platformda bulunur, APK'ya girmez. Uygulamaya eklenen üçüncü taraf kütüphanelerdeki kullanılmayan kod ise büyük olasılıkla R8/ProGuard küçültmesiyle ayıklanır. App Bundle'daki bölme de büyük olasılıkla daha çok işlemci mimarisi (ABI), ekran yoğunluğu ve dil üzerinden yapılır. Belirli sınıfları açıkça içe aktarmak yine de okunabilirlik için önerilir.

## Örnek Sorular

**Soru 1** (derste sözlü, 01:14:23): Bir Activity'nin `onPause` ve `onStop` durumları arasındaki fark nedir?

- Çözüm (derste verildi): Activity'ye ait görüntü, arka planda kalsa bile ekranda görünüyorsa (öne bir bildirim, diyalog kutusu ya da açılır pencere gelmişse) Activity `onPause` durumundadır. Activity ekranı tamamen görünmez olduysa `onStop` durumundadır.

**Soru 2** (derste sözlü, 01:15:03): Ekranın üstünden bildirim çubuğu aşağı indirildiğinde çalışan Activity hangi duruma geçer?

- Çözüm (derste verildi): `onPause`. Bildirim çubuğu öne geldiği için Activity'yle etkileşim kurulamaz ama Activity hâlâ arka planda görünür.

**Soru 3** (derste sözlü, 02:17:32): Android mimarisi, uygulama bileşenleri ve APK gibi başlıklar iOS için de geçerli mi?

- Çözüm (derste verildi): Hayır. Bu başlıklar Android'e özeldir. iOS'ta da benzer kavramlar (paket olarak IPA, katmanlı işletim sistemi, layout yapısı) vardır ama tamamen farklı ve bağımsızdır.

**Soru 4** (derste sözlü, 02:31:23): Yıldızlı import kullanıldığında uygulama APK'ya çevrilirken kullanılmayan sınıflar ayıklanmaz mı?

- Hocanın cevabı: Ayıklanmaz; APK ya da App Bundle bunu çözmez.

> **Ders sonrası not:** Yukarıdaki 18.6 bölümündeki nota bakın: Java'da yıldızlı import derlenmiş kodun boyutunu değiştirmez; kullanılmayan kodun ayıklanması büyük olasılıkla R8/ProGuard ile yapılır.

**Soru 5** (derste sözlü, 02:32:27, alıştırma): Hazır bir Hello World projesini içe aktarıp emülatörde ya da gerçek cihazda çalıştırın. Ardından `drawable` altındaki ikonu, `strings.xml` altındaki uygulama adını ve ekranda gösterilen metin değişkeninin değerini değiştirip uygulamayı yeniden derleyin ve değişikliklerin ekranda göründüğünü doğrulayın.

> **Çözüm (derste verilmedi):** Android Studio'da projeyi "Import Project" ile açın ve "Sync Project with Gradle Files" ile Gradle uyumunu denetleyin. Device Manager'dan bir sanal cihaz oluşturun ya da Geliştirici Seçenekleri ve USB hata ayıklaması açık bir telefon bağlayın, sonra uygulamayı çalıştırın. Uygulama adı genellikle `res/values/strings.xml` içindeki bir string'dedir ve manifestte `android:label` ile kullanılır. Ekrandaki metin için TextView'ın `android:text` özelliğinin başvurduğu `@string/...` değeri değiştirilir. İkon, manifestteki `android:icon` özelliğinin gösterdiği `drawable` ya da `mipmap` kaynağı değiştirilerek güncellenir. Uygulama yeniden çalıştırılınca yeni ad, ikon ve metin görülmelidir.

## Dersin Toparlaması

Dersin ilk bölümünde mobil uygulama geliştirme trendleri tamamlandı: katlanabilir cihazlar, yapay zekâ ve federe öğrenme, giyilebilir cihazlar, IoT, AR/VR, mobil cüzdanlar ve güvenlik. iOS ile Android uygulama geliştirme maliyet, yayın süreci, dil, pazar payı ve parçalanma açısından karşılaştırıldı; hedef kitle ve sürüm analizi yapmadan uygulama geliştirmenin riskleri vurgulandı. Ardından yalnız gereken modülü kurulumsuz çalıştıran Instant App kavramı ve sınırları, ön yüz ile arka ucu birlikte gerektiren On-Demand uygulamalar, son olarak da performans, kullanıcı, bağlılık ve iş metrikleri ele alındı.

İkinci bölümde Android'e geçildi: beş katmanlı mimari, JIT ve AOT'yi birleştiren Android Runtime, NDK ve SDK ayrımı, Activity yaşam döngüsü, UI ve veri katmanını ayıran mimari ilkeler, APK ve App Bundle, en az ayrıcalık ilkesi, dört temel bileşen (Activity, Service, Broadcast Receiver, Content Provider), Intent türleri, AndroidManifest.xml, uygulama kaynakları, yapılandırma değişiklikleri ve izin türleri anlatıldı. Ders, Android Studio'da bir Hello World projesinin layout ve Activity dosyalarının incelenmesiyle bitti. Sonraki derste layout ile Java kodu arasındaki bağlantının `R` sınıfı üzerinden kurulması, Activity'ler arası geçiş ve Intent ile bilgi taşıma ele alınacak; iki ekranlı küçük uygulamalar (örneğin bir hesap makinesi) yazılmaya başlanacak.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
