# Ders 1 Genişletilmiş Notu: Mobil Teknolojilere Giriş: Pervasive Computing ve Mobil Uygulama Geliştirme Yaklaşımları

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dersin Amacı, Kapsamı ve Kaynakları
- 2. Pervasive (Ubiquitous) Computing
- 3. Mobil Cihazlarda Kablosuz Haberleşme ve Kısıtlar
- 4. Kablosuz Sensör Ağlarından Nesnelerin İnternetine
- 5. Pervasive Computing'in Alt Alanları ve Evrimi
- 6. Gömülü Sistemler ve Mobil İşletim Sistemleri
- 7. Mobil Uygulamalar ve Geliştirme Yaklaşımları
- 8. Mobil Veriden Çıkarım ve İyi Bir Mobil Uygulamanın Ölçütleri

## 1. Dersin Amacı, Kapsamı ve Kaynakları

Dersin amacı, öğrencilere önce mobil teknolojiler hakkında genel bir bakış kazandırmak, ardından Android tarafında native (platformun kendi araçlarıyla) uygulama geliştirirken hangi yapı taşlarının kullanılacağını ve nelere dikkat edileceğini öğretmektir. Ders, Android programlamayı hiç bilmeyen birine bu alanda temel bilgi kazandıracak giriş düzeyinde tasarlanmıştır. Aralarında iOS, React Native, Flutter, Xamarin ya da HTML5, CSS ve JavaScript gibi web teknolojileriyle mobil uygulama geliştirmiş olanlar bulunsa da içerik temel seviyede kalır. Ders sonunda öğrencinin mobil teknolojiler hakkında fikir sahibi olması, alternatif geliştirme yöntemlerini tanıması ve belirli düzeyde bir Android uygulaması yazabilecek bilgiye ulaşması beklenir.

### 1.1 Konu akışı

Hocanın ekranda gösterdiği izlencede (syllabus) konular şu sırayla yer alır (ekrandan, 00:10:00):

- Mobil bilişime (mobile computing) ve mobil cihazlara genel bakış
- Mobil işletim sistemleri ve mobil uygulama programlama dilleri
- Uygulama geliştirme araçları ve ortamları, Android mimarisi
- Uygulama yaşam döngüsü (lifecycle), Activity, Intent ve layout'lar
- Kullanıcı arayüzü bileşenleri, widget'lar ve diğer uygulamalarla etkileşim
- Akıllı telefonlarda veri yönetimi
- Akıllı telefonlardaki sensörler ve sensör verisi toplama
- BroadcastReceiver
- Bildirimler (notifications)
- Arka plan görevleri (background tasks)
- Konum tabanlı servisler
- Haritalar
- Uygulama mağazaları ve kuralları

Hoca bu akışı şöyle anlattı: önce mobil teknolojiler, mobil cihazlar, bu cihazları yöneten işletim sistemlerinin normal işletim sistemlerinden farkı, kullanılan diller ve araçlar ele alınır. Sonra Android mimarisi ve temel yapı taşları gelir: bir uygulamanın yaşam döngüsünde hangi adımlar vardır, aktivite nedir, Intent ne işe yarar, hangi tür layout'lar oluşturulabilir, arayüzde hangi bileşenler kullanılır, iki uygulama ya da iki aktivite arasında bilgi nasıl taşınır. Ardından akıllı telefonda verinin nasıl saklanacağı ve yöntemlerin birbirine göre artı ve eksileri, telefondaki sensörler (hangi veriler, hangi sıklıkta, hangi amaçla toplanır), BroadcastReceiver, bildirimler, arka plan görevleri, konum tabanlı servisler, haritalar ve son olarak bir uygulamanın mağazaya yüklenirken geçtiği adımlar anlatılır.

### 1.2 Kaynaklar

- Ana kaynak: `developer.android.com`. Hoca, ilk birkaç hafta dışında ders içeriğini büyük ölçüde buradaki kaynaklardan derlediğini ve ayrıntıların bu sayfadan takip edilmesini önerdi (ekrandan, 00:10:00).
- Ders kitabı: Bill Phillips, Brian Hardy, "Android Programming: The Big Nerd Ranch Guide", 3. baskı (ekrandan, 00:10:00).
- Yardımcı kitap: Dawn Griffiths, David Griffiths, "Head First Android Development: A Brain-Friendly Guide", O'Reilly, 2014 (ekrandan, 00:10:00).

Hocaya göre Google'ın kendi sunduğu çevrim içi kaynaklar bu ders için fazlasıyla yeterlidir. Ders Türkçe anlatılır, ama terimler ve slaytlar İngilizcedir.

### 1.3 Programlama dili ve test ortamı

Android programlamada üç temel dil vardır: Java, Kotlin ve C++. Eskiden ağırlıklı olarak Java kullanılıyordu; zamanla Kotlin'in payı arttı. Derste Java kullanılır, ama isteyen öğrenci kendi kodunu Kotlin ile yazabilir. Kotlin daha sadeleştirilmiş, belli yüklerden arındırılmış bir dildir ve kütüphane açısından Java'dan bazı farkları vardır. Google, Java'nın hantal yapısını bertaraf etmek için Kotlin'e ciddi yatırım yapmış ve desteğini artırmaya devam etmektedir. Hocaya göre bu ayrım dersin temel mantığını etkilemez: native programlamanın temel yapı taşları öğrenilirken hangi dilin kullanıldığı, bazı özel durumlar dışında teknik olarak büyük fark yaratmaz.

> **Ek bilgi (derste anlatılmadı):** Android'de C++ kodu genellikle Android NDK (Native Development Kit) ile yazılır ve çoğunlukla performans gerektiren ya da var olan C/C++ kütüphanelerini kullanan kısımlar için tercih edilir. Uygulamanın arayüz ve yaşam döngüsü kodu yine Java ya da Kotlin ile yazılır.

Yazılan uygulamalar bir emülatörde çalıştırılabilir, ama elde gerçek bir cihaz varsa onun üzerinde test etmek her zaman bir avantajdır.

## 2. Pervasive (Ubiquitous) Computing

### 2.1 Tanım

Pervasive computing, başka bir adıyla ubiquitous computing, uzun yıllardır literatürde kullanılan önemli bir kavramdır. Hoca, bu başlıkları içeren derslerin Türkiye'de lisans ve yüksek lisans düzeyinde az olduğunu, bu dersin programlama odaklı olmayan yüksek lisans versiyonunun ise akıllı cihazlar, uzaktan erişilebilir cihazlar (saat, telefon, IoT cihazları) ile neler geliştirilebileceğini, bu cihazların sorunlarını ve bu sorunlara yönelik çözümleri problem odaklı ele aldığını anlattı. Bu derste ise problemler hakkında fikir verildikten sonra telefonun, saatin, arabanın, akıllı televizyonun nasıl ve nasıl verimli programlanacağı konuşulur.

Slayttaki tanım şöyledir (ekrandan, 00:30:00):

> "Pervasive computing, also called ubiquitous computing, is the growing trend of embedding computational capability (generally in the form of microprocessors) into everyday objects to make them effectively communicate and perform useful tasks in a way that minimizes the end user's need to interact with computers as computers. Pervasive computing devices are network-connected and constantly available."

Türkçesiyle: pervasive computing, hesaplama yeteneğinin (genelde mikroişlemci biçiminde) günlük nesnelere gömülmesi eğilimidir. Böylece bu nesneler etkin biçimde haberleşir ve son kullanıcının bilgisayarla "bilgisayar olarak" etkileşme ihtiyacını en aza indirecek şekilde yararlı işler yapar. Bu cihazlar ağa bağlıdır ve sürekli erişilebilirdir.

Hoca, pervasive computing denince özellikle kablosuz bağlantıya sahip cihazların, ayrıca kabloyla bağlı olup uzaktan erişilebilen bütün cihazların üzerinde yapılabilecek işlemlerin kastedildiğini belirtti. Gömülü sistemlerin son 10 yılda hayatımızda çok yaygınlaşmasıyla birlikte iş sabit bir noktadan değil, herhangi bir cihazdan kaldığı yerden sürdürülebilir hale geldi.

### 2.2 Her yerden, her cihazdan erişim

Eskiden evdeki bilgisayarda yapılan bir iş, işe bir USB bellek ya da harici diskle taşınır ve orada kaldığı yerden sürdürülürdü. Bugün bulut bilişim (cloud computing) sayesinde veri tek bir noktada saklanır ve çok sayıda cihazdan ona erişilir.

Cihazlar da bu süreçte dönüştü. Eski tip el terminalleri (handheld) zamanla cep telefonu formuna geldi, ekranları büyüdü. Ardından bilgisayarla telefon arasına yerleşen tabletler, sonra giyilebilir teknolojilerle akıllı saatler ve akıllı bileklikler geldi. Bugün baret, eldiven ve giysiler üzerinde de giyilebilir teknoloji uygulamaları görülmektedir. Bilginin her an her yerden erişilebilir olması ihtiyacı sonucunda cihazlara milisaniyeler mertebesinde erişilebilir. Bu, zaman açısından büyük kazanç ve yer açısından bağımsızlık sağlar: her yerden çalışmak ve üretmek mümkün olur. Cihazlardaki sensörler sayesinde kişileri izlemek de mümkündür.

Hocanın vurguladığı bir gözlem, cepte taşınan telefonun belki 50'nin üzerinde, 100'e yakın cihazın yerini tutmasıdır: video kaydedici, kamera, not defteri, kitap, el feneri. Sağlık açısından telefon ve saat kan basıncını, kalp atış hızını izleyebilir, düşme tespiti yaparak ilgili kişileri ya da kurumları uyarabilir. Bu teknolojilere VR (Virtual Reality, sanal gerçeklik) ve AR (Augmented Reality, artırılmış gerçeklik) eşlik eder. Sonuçta tek bir cihaza onlarca cihaz sığdırılmış olur.

### 2.3 "Her yerde var olmak"

Pervasive computing denince ilk akla gelen şey her yerde bulunabilmektir. Slayttaki ifade şöyledir (ekrandan, 00:40:00):

> "Existing everywhere: Anywhere, Anytime, Any Device, Any Network, Any Data"

Yani her türlü veriye, her türlü cihaz üzerinden, her türlü ağ üzerinden, istenen anda erişebilmek. Hoca bunun gelinen son nokta olduğunu söyledi. Bugün bir kişinin birden fazla cihazı olduğu düşünülünce milyarlarca cihazın birbiriyle veri alışverişinde olduğu görülür; bu da konunun ne kadar ön plana çıktığını ve cihazların sürekli çevrim içi olma ihtiyacını gösterir.

## 3. Mobil Cihazlarda Kablosuz Haberleşme ve Kısıtlar

### 3.1 Çevrim içi olmanın önemi

Bu cihazlar çevrim dışıyken de önemli işler yapar, ama bugün diğer insanlarla etkileşimli ve kablosuz olarak haberleşilir. Bu yüzden mobil cihazların en önemli yeteneklerinden biri kablosuz haberleşmedir: hiçbir kabloya ihtiyaç duyulmaz ve cihaz üzerinde bu haberleşmeyi sağlayan çeşitli protokoller bulunur.

- GPS: kablosuz haberleşme yalnız bilgi taşımak değildir; konum bilgisinin alınmasını sağlayan haberleşme de bunlardandır. GPS en çok enerji tüketenlerden biridir.
- Hücresel ağlar: baz istasyonlarıyla iletişim. 2G ile başlayan süreç 3G, 4G, LTE ve 5G'ye ulaşmıştır; 6G için çalışmalar başlamıştır.
- Wi-Fi: erişim noktalarına (access point) bağlanılır; burada bir yıldız topoloji söz konusudur.
- Bluetooth ve NFC (Near Field Communication): telefonun diğer cihazlarla ve kişilerle haberleşmesinde önemli protokollerdir.

Bu protokollerin her birinin belirli enerji tüketimleri, belirli veri aktarım kapasiteleri ve bağlanabilecek cihaz sayısına göre belirli kapasiteleri vardır; bunlar ilerleyen derslerde ele alınacaktır. Hocaya göre bu cihazlar çevrim içi olduklarında çok daha yeteneklidir.

### 3.2 Pil kısıtı

Mobil cihazların kısıtları da vardır ve şu andaki en büyük problemlerden biri pil kısıtıdır. Yazılan uygulamanın çok fazla kaynak tüketmemesi, özellikle pil konusunda "cimri" olması istenir.

> **Hocanın vurgusu:** Uygulama geliştirirken şu sorular sorulmalıdır: Mevcut teknolojilerle enerji tasarrufu nasıl yapılır? Uygulama ne sıklıkla kullanılacak, enerji tüketimine hassas olmak gerekiyor mu? Cross-platform bir araç kullanıldığında kaynak tüketimi native'e göre değişiyor mu?

## 4. Kablosuz Sensör Ağlarından Nesnelerin İnternetine

### 4.1 Kablosuz sensör ağları (WSN)

Telefonların hikayesi aslında kablosuz sensör ağlarıyla (wireless sensor networks; Türkçede telsiz algılayıcı ağlar ya da kablosuz sensör ağlar) başlar. Bunlar daha çok özel bir donanım üzerine sensör yerleştirilerek belirli bir ortamdan bilgi almak amacıyla kurulan ağlardır. Askeri ve çevresel uygulamalarda kullanılır: bir ormana, bir okyanusa ya da bir hayvan sürüsü üzerine yerleştirilebilir. 1990'lardan beri, özellikle 2000'lerin başında birçok projede uygulama odaklı kullanılmıştır.

Temel amaç bulundukları ortamdan veri toplamaktır. Ağdaki düğümler birbirleri üzerinden haberleşerek veriyi merkeze aktarır. Örnekler:

- Orman yangınını önlemek için ortamdan sıcaklık bilgisi toplamak.
- Bir askeri operasyonda bir bölgeye izinsiz bir ekibin girip girmediğini anlamak.

WSN'lerin özellikleri:

- Temel prensip bölgeden bilgi toplamaktır; karşılıklı haberleşme vardır ama tasarım daha çok merkeze akan veri üzerinedir.
- Bant genişliği (bandwidth) dardır.
- Sahadaki cihazların özellikle enerji tüketimi açısından çok önemli kısıtları vardır, çünkü zorlu çevre koşulları nedeniyle düğümler oraya bir kez bırakılabilir. Uçakla atılabilir, başka yollarla gönderilebilir ya da elle yerleştirilebilir; amaç ulaşılması zor coğrafyalardan bilgi toplamaktır.

WSN doğrudan dersin konusu değildir, ama hikayenin başlangıç noktasıdır.

### 4.2 Sensörler: elektronik cihazın duyuları

Hoca şu benzetmeyi yaptı: insan için beş duyu (görme, duyma, dokunma, koku, tat) nasıl çok önemliyse, elektronik cihazlar için de ortamdan aldıkları bilgi karar verme noktasında doğrudan etkilidir. Telefondaki kamera, mikrofon, ivmeölçer, jiroskop ve hatta Wi-Fi ile baz istasyonundan gelen paketler de hesaba katılırsa bu cihazlar ortamdan sürekli veri toplar ve bu veriyle karar alır.

Örnek olarak yakınlık sensörü: telefon kulağa götürüldüğünde yakınlık sensörü çalışır ve ekranı kapatır. Bunun iki amacı vardır:

- Enerji tasarrufu.
- Yanlışlıkla bir tuşa basıp karşı tarafı rahatsız etmeyi ya da görüşmeyi sonlandırmayı önlemek.

### 4.3 Ambient Intelligence

Ortamdan bilgi alıp ortamın durumunu anlayan uygulamalara Ambient Intelligence (çevresel zeka) uygulamaları denir. Bu kavram hâlâ kullanılsa da eskidir; eskiden bunun için özel sınıflar, özel alanlar ve özel evler yaratılıyordu. Bugün çevresel zeka uygulamaları yavaş yavaş IoT uygulamaları olarak hayatımıza girmektedir.

### 4.4 Telefon: WSN ile IoT arasındaki köprü

Hocaya göre WSN ile IoT (Internet of Things, nesnelerin interneti) arasındaki köprüyü telefonlar kurdu. Araştırmacılar WSN'lerin ortamdan veri toplamaya yardımcı olduğunu, ama onları hareketli hale getirmenin kolay olmadığını gördü: ya çok maliyetliydi ya da bulundukları coğrafya hareket ettirmeyi zorlaştırıyordu. Telefon, sahibiyle birlikte doğal yolla hareket eden bir sensör grubu oluşturdu. Böylece araştırmacılar, insanların zaten kullandığı eşyaları elektronik donanımlarla donatmanın çok daha fazla problemi çözeceği kanaatine vardı: yalnız tek bir iş için özel bir cihaz tasarlamak yerine var olan nesnelere bu yeteneği kazandırmak.

Bu fikirle IoT kavramı ortaya çıktı. Oturulan koltuk, kullanılan kalem gibi nesneler için bugün yaygın kullanımlar olmasa da akıllı sınıf, akıllı ev, toplantı odası gibi ortamlar sıcaklığı izleme, hareket yokken ışığı kapatma gibi yetenekler kazandı.

### 4.5 IP adresi ve IPv6

WSN'lerde düğümlere doğrudan erişilemiyordu; ormanın bir bölgesindeki düğümlere ancak bölge olarak erişilebiliyordu, çünkü düğümlerin IP adresi yoktu. Nesnelere bir IP adresi kazandırılırsa onlara doğrudan erişilebilir ve onlardan doğrudan bilgi istenebilir. IoT bu fikirle hayatımıza girdi.

Bugün kullanılan IP version 4 (IPv4) 32 bit üzerine kurgulandığı için, var olan pek çok cihazın fiziksel olarak kendi adresini alması mümkün değildir: IP blokları tükenmiştir ve 32 bitle adreslenemeyecek kadar çok elektronik cihaz vardır. Bu nedenle 128 bitlik ve güvenlik açısından daha güçlü bir yapıya sahip IP version 6 (IPv6) gündeme gelmiştir. Hocaya göre geçiş beklendiği kadar hızlı olmasa da altyapılar dönüştürüldüğünde ve cihaz sayısındaki hızlı artış düşünüldüğünde IPv6 kullanımı kaçınılmaz olacaktır.

> **Ek bilgi (derste anlatılmadı):** 32 bitlik adres alanı en fazla $2^{32} \approx 4{,}3 \times 10^{9}$ adres verir; 128 bitlik adres alanı ise $2^{128} \approx 3{,}4 \times 10^{38}$ adres verir. Dünyadaki bağlı cihaz sayısı milyarlar mertebesinde olduğundan IPv4 adresleri yetmez; pratikte bu açık büyük olasılıkla NAT gibi yöntemlerle kapatılmaktadır.

Böylece birbirleriyle konuşan, haberleşen cihazların, yani makineler arası iletişimin (machine to machine communication) önü açılır. Cihazlar API'ler üzerinden belirli mesajlaşma formatlarıyla birbirlerine veri taşır, birbirlerinden veri sorgular. Artık cihazlar yalnız insanların kontrolüyle değil, programcıların yazdığı programlar aracılığıyla da veri toplar ve bu veriden karar üretir.

## 5. Pervasive Computing'in Alt Alanları ve Evrimi

### 5.1 Açan bir çiçek gibi

Hoca, pervasive computing'i açıldığında birçok alt yaprağı ortaya çıkan bir çiçeğe benzetti:

- Cloud computing: veriyi yönetebilmek için.
- Internet of Things: çok sayıda cihaz birbiriyle haberleşir.
- Big data: bu cihazların ürettiği veri büyük veri olarak adlandırılır.
- Data science: bugün veri biliminden söz edilebiliyorsa bu, büyük veri ve cihazların donanım kapasitesinin artması sayesindedir.

Bu nedenle pervasive computing birçok yeni alt alanın oluşmasına öncülük etmiştir.

### 5.2 Distributed, mobile ve pervasive computing

Slaytta evrim üç adımla gösterildi (ekrandan, 01:00:00):

- Distributed Computing
- Mobile Computing
- Pervasive Computing

Başta işlemler tek bir bilgisayar üzerinde yapılıyordu. Zamanla belirli işleri birden fazla cihazda çalıştırarak daha hızlı sonuç alma mantığıyla dağıtık programlama ve süreçler arası iletişim (inter-process communication) geldi. Dağıtık programlamada cihazların birbirine kabloyla (wired) bağlı olması daha yaygındı. Kablosuz cihazların yaygınlaşmasıyla mobile computing yeni halini aldı: kablosuz cihazlar işlem yapıp sonuçları birbirleriyle paylaşmaya başladı.

Mobile computing üç ana başlık altında değerlendirilir:

- Mobile hardware: telefonun donanımı.
- Mobile software: telefonun yazılımı.
- Mobile communication: telefonun haberleşmesi.

Bu üç alanda da gelişmeler sürmektedir. Daha sonra yalnız telefonların değil, kişisel kullanımdaki diğer cihazların da çeşitliliği ve sayısı artınca pervasive computing kavramı konuşulmaya başlandı.

### 5.3 Büyük veri, bellek ve işlem gücü

Büyük veri bugün çok değerlidir ve onu işlemek için işlem gücü (process power) ve işleme sırasında verinin tutulacağı belleğin büyüklüğü önem kazanır. Bugün telefonlar gigabaytlar mertebesinde belleğe sahiptir; hoca bunun yaklaşık 15 yıl önceki bilgisayarların disk kapasitesi civarında olduğunu, ama bu küçük donanıma sığdırılabildiğini söyledi. Büyük veri genellikle kapasitesi yüksek cihazlarda işlenir.

### 5.4 Makine öğrenmesi telefonda çalışır mı?

Makine öğrenmesi ve derin öğrenme gibi yapay zeka uygulamalarında güçlü donanım daha çok eğitim süreci için gerekir. Eğitim tamamlandığında modeli herhangi bir cep telefonunda çalıştırmakta sorun yoktur.

> **Hocanın vurgusu:** "Derin öğrenme cep telefonunda çalıştırılabilir mi?" sorusunun cevabı evettir. Bir yapay sinir ağının katman ve nöron sayısı ne kadar fazla olursa olsun yaptığı işlemler basit matematiksel işlemlerdir; hazır bir model telefona ya da saate yüklenip (deploy) kararları üzerinden çıktı üretilebilir. Eğitim ise ayrı bir iştir ve GPU gibi güçlü donanım gerektirebilir.

Hocanın son eğilim olarak andığı yaklaşım, öğrenme sürecini telefonlara dağıtmaktır. Bunu bir blockchain yapısına benzetti: eğitimin tamamlanması için tek bir merkez yerine çok sayıda mobil cihaz kullanılır. Bu, merkezi yapıdan dağıtık yapıya geçiş yaklaşımıdır ve araştırılması değerli bir konudur. Böylece makine öğrenmesi yalnız büyük ve güçlü adanmış cihazlarda değil, kapasitesi düşük cihazlarda da yapılabilir hale gelmektedir.

> **Ders sonrası not:** Hoca bu yaklaşımı "Federated Computing" diye andı; literatürdeki yaygın adı büyük olasılıkla "Federated Learning" (federe öğrenme) olmalıdır. Bu yaklaşımda veri cihazda kalır, cihazlar modeli yerelde eğitir ve yalnız model güncellemeleri birleştirilir.

### 5.5 Katmanlı yapı

Slaytta pervasive computing'in yapı taşları üç katman halinde gösterildi (ekrandan, 01:05:00):

| Katman | Bileşenler |
|---|---|
| Ubiquitous mobility | Sensors; Embedded computing; Low-cost, low-power connectivity |
| IoT | Smart material and design; IoT applications |
| Multi-device experience | Pervasive computing applications |

Hoca bu katmanları şöyle açıkladı. Sensörler pervasive computing'in olmazsa olmazıdır, çünkü cihazlar ortamdan bilgi almalıdır. Gömülü sistemler önemlidir, çünkü bu cihazların belirli kısıtları vardır. Pervasive computing genelde düşük güçlü bağlantı (low-power connectivity) ve düşük maliyetli (low cost) cihazlardan söz eder; bugünkü telefonların fiyatları düşükten çok yükseğe geniş bir aralığa yayılsa da temel mantalite bu cihazların belirli bir kaynak kısıtıyla kurgulanmasıdır. IoT cihazları bir sonraki katmanda yer alır ve en üstte pervasive computing uygulamaları gerçekleşir.

## 6. Gömülü Sistemler ve Mobil İşletim Sistemleri

### 6.1 Gömülü sistem nedir?

Kısıtlı cihazların bazılarında işletim sistemi vardır, bazılarında yoktur:

- IoT cihazlarında çoğunlukla işletim sistemi görülmez.
- Oyun konsollarında belirli bir framework vardır, ama tam anlamıyla bir işletim sisteminden söz edilmez.
- Telefonlar için artık bir işletim sisteminden söz edilir.

Çamaşır makinesi, bulaşık makinesi, bir evin otomasyon yazılımı gibi ağırlıklı olarak belirli işleri adanmış (dedicated) biçimde yapan cihazlara gömülü sistem denir. Telefon uzun süredir bu sınıftan çıkmıştır.

### 6.2 Telefonun evrimi ve işletim sistemi ihtiyacı

Telefonun ilk versiyonları yalnız sesli haberleşme ve mesajlaşma için kullanılıyordu. Zamanla internet, takvim uygulamaları, not tutma geldi ve bugün bir bilgisayarın neredeyse bütün yetenekleri küçük bir alana sığdırıldı. Yaklaşık 2000'li yıllardan beri telefon işletim sistemleri evrim geçirerek bugüne geldi.

Telefon bu yeteneklere sahip olduğu için bir işletim sistemine ihtiyaç duyar, ama donanım ve kaynak kısıtı nedeniyle bir masaüstü işletim sistemini taşıyamaz. Hoca, masaüstü işletim sistemi bir telefona yüklenirse şarjın dakikalar mertebesinde tükeneceğini söyledi. Nasıl masaüstü bilgisayar ile sunucunun yetenekleri farklıysa ve ayrı işletim sistemleri varsa, telefonlar ve hatta saatler için de farklı işletim sistemleri gerekir. Amaç, işletim sisteminin cihazın yetenekleri dahilinde kaynak kontrolü yapmasıdır; cihazda olmayan bir yeteneği izlemeye çalışmak boşuna enerji harcatır.

### 6.3 Android ve iOS

Bu nedenle telefonlarda işletim sistemleri sadeleştirilmiş biçimde yer alır:

- Android: Linux çekirdeği kullanılır, ama birçok ayrıntı özelliğinden arındırılarak telefona uyarlanır ve Android bunun üzerine kendi yapısını kurar.
- iOS: Apple, FreeBSD üzerinden gelen Unix türevi bir işletim sistemi yapısının üzerine iOS'u inşa eder.

> **Ek bilgi (derste anlatılmadı):** iOS, Apple'ın Darwin adlı açık kaynak çekirdek katmanı üzerine kuruludur. Darwin'in XNU çekirdeği Mach mikroçekirdeği ile FreeBSD'den alınmış bileşenleri birleştirir; hocanın "FreeBSD üzerinden Unix türevi" ifadesi bu ilişkiyi anlatır.

Akıllı telefon (smartphone) olarak adlandırılan cihazlar 2007-2008 yıllarında yaygınlaştı. O günden bu yana bazı işletim sistemleri ortaya çıktı, bazıları yok oldu. Bugün çok konuşulan 5-6 işletim sistemi vardır, ama yaygın olarak kullanılan 2-3 tanedir. Bayrağı hâlâ Android ve iOS taşımaktadır. Daha düşük profilli telefonlar için başka bir işletim sistemi daha vardır; ayrıntısı sonraki derse bırakıldı.

<!-- BELİRSİZ: Altyazıda "Kios" olarak geçen düşük profilli telefon işletim sistemi büyük olasılıkla KaiOS'tur; ekranda doğrulanamadı. -->

## 7. Mobil Uygulamalar ve Geliştirme Yaklaşımları

### 7.1 Mobil uygulama ve uygulama marketleri

Mobil cihazlar üzerinde çalışan uygulamalara mobil uygulama (mobile app) denir. Genellikle telefon uygulamaları kastedilse de tablet, akıllı saat ya da akıllı TV üzerinde çalışan uygulamalar da bu kapsamdadır. Hocaya göre artık her "habitatın" bir uygulama marketi vardır. Böylece daha küçük çaplı işler için uygulamaya özgü seçim yapılabilir ve daha özel hizmetler sunulabilir. Tarayıcı eklentileri (extension) de aynı mantıkla çalışır: tarayıcıya bir eklenti ekleyerek onu daha yetenekli hale getirirsiniz.

### 7.2 Dört geliştirme yaklaşımı

Bir mobil uygulama geliştirmek için şu yaklaşımlardan biri seçilebilir:

- Native app: platformun kendi SDK'ları üzerinden cihazın bütün yeteneklerini kullanabilen uygulama.
- Cross-platform app: tek kod yazıp birden fazla platform için uygulama üretmek. Hoca, bu yaklaşımın 10 yıl öncesine göre müthiş ilerlediğini ve "bir taşla iki kuş vurmayı" sağladığını söyledi.
- Progressive Web App (PWA).
- Hybrid app.

Hangisinin seçileceği hedeflere, eldeki imkânlara, uygulamanın kime ulaşacağına ve cihazın hangi özelliklerinin kullanılacağına bağlıdır. Uygulamayı geliştirecek ekip ve bütçe de bu seçimde önemlidir.

### 7.3 Karar akış şeması

Ekranda "Choose a Dev Approach for Your Mobile App" başlıklı bir karar şeması gösterildi (ekrandan, 01:10:00). Şemadaki sorular ve dallar şöyledir:

```text
S1: Mobil uygulamaya mümkün olan en ucuz şekilde mi ihtiyacınız var?
    EVET -> S2: Kamera ya da GPS gibi donanım özellikleri şart mı?
              HAYIR -> Hybrid app
              EVET  -> S3'e git
    HAYIR -> S3

S3: Pazara çıkış süresini kısaltıyorsa sınırlı performansı kabul eder misiniz?
    EVET -> S4: E-ticaret uygulaması mı geliştiriyorsunuz?
              EVET  -> Progressive web app
              HAYIR -> Cross-platform app
    HAYIR -> S5: Her platform için ayrı kod tabanında çalışan iki ekip kurmaya hazır mısınız?
              EVET  -> Native app
              HAYIR -> Hybrid, cross-platform ve PWA seçenekleri arasından seçim yapılır
```

Şemanın altındaki logolardan anlaşıldığı kadarıyla örnek araçlar şunlardır: hybrid için Ionic, Apache Cordova ve Visual Studio; cross-platform için React Native, Flutter ve Xamarin; PWA için Angular, React ve Polymer; native için Xcode ve Android Studio.

<!-- BELİRSİZ: Şemadaki araçlar yalnız logo olarak gösterildi; adlar logolardan ve 01:20:00'daki tablodan çıkarıldı. -->

### 7.4 Geliştirme araçları

Hoca, iOS ve Android'in kendi geliştirme araçlarını (development tools) ve yazılım geliştirme kitlerini (SDK) sunduğunu, bu araçlarla native uygulama geliştirilebildiğini anlattı. Son dönemde en çok kullanılan cross-platform araçların başında React Native ve Flutter gelir; ikisinin de kendine göre önemli artıları vardır ve hızlı uygulama geliştirmeyi sağlar. Hoca bu araçların karşılaştırmasının ayrıntısına bu derste girmedi.

<!-- BELİRSİZ: 01:17:25 civarında araçların ve onlarla geliştirilmiş uygulamaların gösterildiği slaytın karesi yok; slayttaki araç ve uygulama adları okunamadı. -->

### 7.5 Native, hybrid ve cross-platform karşılaştırması

Ders sonunda ekranda üç yaklaşımı karşılaştıran bir tablo gösterildi (ekrandan, 01:20:00). Hoca ayrıntılı artı ve eksi karşılaştırmasının sonraki derste yapılacağını söyledi. Tablonun okunabilen kısmı:

| Özellik | Native | Hybrid | Cross-platform |
|---|---|---|---|
| Araçlar | Xcode, AppCode, Android Studio | Ionic, Apache Cordova, Visual Studio | React Native, Xamarin, Flutter |
| Görüntüleme motoru | Native | Tarayıcı (browser) | Native |
| Kütüphaneler | Açık kaynak kütüphane ve platformlara pek bağımlı değil | Farklı kütüphane ve framework'lere çok bağımlı | Farklı kütüphane ve framework'lere çok bağımlı |
| Hata ayıklama | Native hata ayıklama araçları | Native ve web geliştirme hata ayıklama araçları | Framework'e bağlı |
| Kod tabanı | Her platform için ayrı kod tabanı | Tek kod tabanı, platforma özgü yetenek olasılığıyla | Tek kod tabanı, platforma özgü yetenek olasılığıyla |

Tablodaki artılar (pros):

- Native: cihaz ve işletim sistemi özelliklerine tam erişim; güçlü performans; işletim sistemiyle birlikte güncellenen native arayüz; verimli çalışma; yüksek kaliteli işlevsellik ve kullanıcı deneyimi; bütün native API'lere ve platforma özgü işlevlere erişim.
- Hybrid: düşük geliştirme maliyeti; farklı işletim sistemi desteği; kodun yeniden kullanımı; maliyet etkin geliştirme; geniş özelleştirme olanakları.
- Cross-platform: farklı işletim sistemi desteği; arayüz performansının neredeyse native kadar hızlı olması; kodun yeniden kullanımı; maliyet etkin geliştirme (ama yeni bir dil ya da yaklaşım öğrenmek gerekir).

Tablodaki eksiler (cons):

- Native: çoklu platform desteği yok; farklı işletim sistemleri desteklenecekse geliştirme maliyeti yüksek.
- Hybrid: daha yavaş performans; işletim sistemi özelliklerine sınırlı erişim.
- Cross-platform: daha yavaş performans; işletim sistemi özelliklerine sınırlı erişim.

<!-- BELİRSİZ: Tablonun "Cons" satırı karenin altında kesiliyor; görünmeyen başka eksiler olabilir. -->

### 7.6 Uygulama kategorileri ve mesajlaşmanın evrimi

Mobil uygulamaların sosyal medya, mesajlaşma, oyun, sağlık ve konum tabanlı uygulamalar gibi çok sayıda alt başlığı vardır. Uygulamanın hedef kitlesi, yapmak istediği iş ve telefonun hangi özelliklerini kullanacağı geliştirme stratejisini doğrudan etkiler.

Hoca, yeni ihtiyaç ve uygulama fikri bulmanın kolay olmadığını belirterek mesajlaşmanın evrimini örnek verdi. Önce SMS (Short Message Service) hayatımıza girdi. Ardından kişiler ya da gruplarla etkileşimli yazışmayı sağlayan anlık mesajlaşma (instant messaging) uygulamaları geldi. İnsanların bilgi paylaşımını daha herkese açık hale getirmek istemesiyle de sosyal medya uygulamaları doğdu. Resim ve video paylaşımı için Instagram, Facebook, TikTok, Discord, YouTube gibi uygulamalar üzerinden bugün çok farklı sektörler oluşmaktadır.

## 8. Mobil Veriden Çıkarım ve İyi Bir Mobil Uygulamanın Ölçütleri

### 8.1 Toplanan veriden çıkarım

Mobil cihazların ve uygulamaların ürettiği veri bugün büyük veri olarak analiz edilir ve birçok çıkarım yapılır. Hocanın örnekleri:

- Sosyal medya analizi: uç bir örnek olarak paylaşımlardan kişilerin ruh sağlığı risklerinin araştırılması; paylaşılan haberlerin döviz ya da borsanın yönünü etkileyip etkilemeyeceğinin analizi.
- Trafik: bir bölgedeki sensör verileri ya da oradan geçen kişilerin telefonlarından alınan hız bilgisiyle yol durumu öğrenilir ve bir noktadan diğerine kaç dakikada gidileceği söylenebilir. Ertesi gün bir yere kaç dakikada gidileceği de belirli bir güven aralığıyla tahmin (prediction) edilebilir.
- Hava durumu: eskiden 3-4 gün ilerisi tahmin edilebilirken bugün 10-15 gün, hatta mevsimsel tahminler yapılabilmektedir. Bunu sağlayan geçmiş verinin işlenmesidir. Tahminlerin hata payı mutlaka vardır, ama doğrulukları her geçen gün artar ve bu da planlama yapmayı sağlar.
- Kestirimci bakım (predictive maintenance): telefonlardan ve IoT cihazlarından toplanan büyük veriyi işleyerek bir fabrikadaki cihazların ne zaman bozulacağını tahmin etmek ve önceden önlem almak.

### 8.2 Değerli olan artık fikir ve veri

> **Hocanın vurgusu:** Mobil teknolojiler denince yalnız mobil programlama yapmak ve ekran tasarlamak artık çok kritik değildir; bunlar bugün çok rahat yapılmaktadır. 10 yıl önce web sayfası geliştirmek, PHP ile sayfa yazmak, mobil uygulama (özellikle iOS'ta native uygulama) geliştirmek çok değerliydi ve bu konuda yetenekli kişi bulmak zordu. Bugün kaynaklar, kütüphaneler ve SDK'lar çok gelişmiştir; cross-platform araçlar aynı anda birden fazla platform için kolayca uygulama geliştirmeyi sağlar. Artık değerli olan, mobil uygulama fikri üretmek, uygulamada toplanan veriyi kullanarak çıkarım yapmak ve insan odaklı, insan hayatını kolaylaştıran uygulamalar geliştirmektir.

### 8.3 İyi bir mobil uygulama

Fikir bulmak kolay değildir; fikrin kabul görmesi için de iyi bir mobil uygulama geliştirmek gerekir. Hocaya göre iyi bir mobil uygulama:

- Çok enerji ve çok kaynak tüketmez.
- Kullanıcı deneyimi (UX, User Experience) iyidir.
- Arayüzü (UI) güzel, kolay, sade ve anlaşılırdır.
- İşlevleri karışık değildir; çok yeteneği olsa bile bunları iyi organize eder.

Mobil uygulama geliştirirken arayüz tasarımı, ekranların birbirleriyle ilişkisi, verinin korunması, saklanması ve merkeze aktarılması önemlidir. Aktarım yapılırken telefonun şarj durumu gözetilmelidir. Örneğin yedeğin ne zaman alınacağına telefonun durumuna (şarj aletine bağlı olup olmadığına) göre karar verilmeli, bir kurulum yapılacaksa şarjın belirli bir seviyede olması beklenmelidir. Hocaya göre bu tür farklar bir uygulamanın tercih edilmesini sağlar.

### 8.4 Dersin hedefleri

Hoca, giriş dersi olarak bu konuların önemini bir kez daha özetledi. Mobil teknolojileri ve bu teknolojilerin kullanıldığı cihazları tanımak gerekir: mobile computing denince hangi cihazlar akla gelmeli, giyilebilir teknolojiler nelerdir, AR ve VR ne zaman ve nerede işe yarar. İleride otonom araçların hayatımızdaki yeri ve onlar için oluşacak uygulama havuzları da konuşulacaktır. Telefon, akıllı saat ve akıllı bilekliğin hangi uygulamalar için kullanılacağı, IoT cihazlarının problemleri, bu cihazlarda çalışan yazılımlar, uygulamalar ve işletim sistemleri, Android ile iOS'u birbirinden ayıran farklar ve geliştirme tekniklerinin artı ve eksileri ele alınacaktır. Ardından native geliştirmede Android mimarisinin sunduklarına odaklanılacaktır.

> **Hocanın vurgusu:** Dersin amaçlarından biri mobil teknolojilere ait terminolojiyi aktarmaktır. IoT, kablosuz sensör ağları ve mobil işletim sistemleriyle ilgili kavramların anahtar kelimeleriyle birlikte bilinmesi beklenir.

## Dersin Toparlaması

Bu giriş dersinde mobil programlamanın arka planı çizildi. Pervasive (ubiquitous) computing, hesaplamanın günlük nesnelere gömülmesi ve cihazların ağa bağlı, sürekli erişilebilir olmasıdır; "Anywhere, Anytime, Any Device, Any Network, Any Data" sloganıyla özetlenir. Hikaye, veriyi merkeze akıtan, dar bantlı ve enerji kısıtlı kablosuz sensör ağlarıyla başlar; telefonların hareketli sensör grubu olarak devreye girmesi ve nesnelere IP adresi verilmesiyle IoT'ye ulaşır. Pervasive computing'den cloud computing, büyük veri ve veri bilimi gibi alanlar doğmuştur. Evrim distributed, mobile ve pervasive computing sırasıyla ilerler; mobile computing donanım, yazılım ve haberleşme olmak üzere üç başlıkta incelenir. Telefonlar, kaynak kısıtları nedeniyle sadeleştirilmiş işletim sistemleri (Linux tabanlı Android, BSD tabanlı Unix türevi üzerine iOS) kullanır.

Uygulama geliştirme tarafında native, cross-platform, PWA ve hybrid yaklaşımları tanıtıldı; seçimin maliyet, donanım erişimi, performans, pazara çıkış süresi ve ekip yapısına göre yapıldığı bir karar şeması ve üç yaklaşımın karşılaştırma tablosu gösterildi. Hoca, bugün değerli olanın fikir üretmek ve veriden çıkarım yapmak olduğunu, iyi bir uygulamanın ise az enerji tüketen, kullanıcı deneyimi yüksek ve telefonun durumunu gözeten bir uygulama olduğunu vurguladı. Bir sonraki derste mobil işletim sistemleri, geliştirme tekniklerinin artı ve eksileri ele alınacak, ardından Android mimarisine geçilecektir.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
