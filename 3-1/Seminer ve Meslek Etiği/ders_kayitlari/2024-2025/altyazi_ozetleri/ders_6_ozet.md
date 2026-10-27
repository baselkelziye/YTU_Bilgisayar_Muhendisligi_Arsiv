# Ders 6 Çalışma Özeti

## Genel Konular

- Bu ders teorik bölümün son dersidir. Konu bilişim hukuku ve Türkiye'deki bilişim yasalarıdır.
- Bilişim suçunun tanımı (1983 Paris uzmanlar komisyonu) ve suçların kategorileri.
- Türkiye'deki ilgili yasalar:
  - TCK 5237 (Türk Ceza Kanunu),
  - CMK 5271 (Ceza Muhakemesi Kanunu),
  - 5846 FSEK (Fikir ve Sanat Eserleri Kanunu),
  - 5070 Elektronik İmza Kanunu,
  - 5651 İnternet Kanunu,
  - 6698 KVKK (Kişisel Verilerin Korunması Kanunu),
  - 6563 Elektronik Ticaret Kanunu,
  - Avrupa Siber Suç Sözleşmesi (6533 sayılı onay kanunu).
- Bilişim suçlarının soruşturulmasının diğer suçlardan farkları.
- Adli bilişim (digital forensics):
  - tanım,
  - dört inceleme alanı (disk, bellek, ağ, mobil),
  - üç aşama (toplama, inceleme ve çözümleme, raporlama).
- Hangi sayısal verilerin adli kanıt sayılıp sayılmayacağı: bellek, disk, belge, fotoğraf, CD/DVD, taşınabilir bellek, bulut, e-posta.
- CMK md. 134'e göre kanıt toplama usulü: ayna imaj, hash özeti, kopyanın sanığa verilmesi.
- Yasaların ayrıntıları: TCK maddeleri, FSEK tanımları, 5070 tanımları, 5651'deki dört sağlayıcı rolü, KVKK, 6563.
- Ara sınav ve seminer sunumu duyuruları.

## Hocanın Özellikle Vurguladığı Kısımlar

- Bilişim suçunda suçlu ile suçun etkilendiği yer genellikle farklı kentlerde veya ülkelerdedir. Bu yüzden inceleme suç mahallinden (ör. bankanın merkezinden) değil, zarar gören kişi veya sistemden başlamalıdır. Uluslararası iş birliği gerekebilir.
- Soruşturma çok hızlı yapılmalıdır. Suçlu sürekli yer ve IP adresi değiştirir.
- Sayısal kanıt usulüne uygun toplanmazsa mahkemede delil niteliğini yitirir. Bundan gerçek suçlu kazançlı çıkar.
- Bellekten kanıt toplanacaksa bilgisayar kapatılmamalıdır. Bellek uçucudur (volatile) ve elektrik kesilince veri kaybolur.
- Hocaya göre Word belgeleri, Excel dosyaları, fotoğraflar (EXIF), CD/DVD tarihleri ve e-posta çıktıları tek başına adli kanıt sayılmaz. Bunların üst verileri (metadata) kolayca değiştirilebilir. Hoca, Ergenekon ve Balyoz davalarının bu tür kanıtlar yüzünden çöktüğünü söylüyor.
- Güvenilir kaynak, işletim sisteminin ve lisanslı uygulamaların olay kayıtları (event log) ile hizmet sağlayıcının trafik kayıtlarıdır.
- İmaj alındıktan sonra kişinin bilgisayarına aylarca el koymaya gerek kalmaz.
- Adli bilişim yalnızca suçluyu bulmaz, masumu da ortaya çıkarır. Adli tıp kadar gereklidir.
- Uzman raporu hüküm kurmaz. Yalnızca teknik bulguları hakimin anlayacağı dille ortaya koyar.
- Yasaları mevzuat.gov.tr'den açıp en azından göz gezdirin. Güncel hali ve değişiklik kayıtları orada bulunur.
- KVKK'da her şey "açık rıza"ya bağlanmış. Hocaya göre üye olurken açık rıza vermeden ilerleyemediğiniz için koruma pratikte zayıf kalıyor.

## Kısa Tekrar Notları

- **Bilişim suçu (1983 Paris tanımı):** Bilgileri otomatik işleyen veya veri iletişimine yarayan bir sistemde yapılan her türlü kanunsuz, ahlak dışı veya yetkisiz davranış.
- **1983 sınıflandırmasının beş kategorisi:**
  - Verileri yasa dışı biçimde almak, bozmak, silmek veya yok etmek.
  - Sahtekarlık amacıyla bilgisayarı kullanmak.
  - Bir sistemin çalışmasını engellemek.
  - Ticari yarar için program sahibinin haklarını zarara uğratmak (ör. lisanssız yazılım).
  - Güvenlik önlemlerini aşarak izinsiz sisteme girmek.
- **Hocanın genel sınıflandırması:**
  - Bilgisayarla işlenen suçlar: internet bankacılığı soygunu, DDoS, zararlı yazılım (malware).
  - Bilgisayar veya bilgi sistemi üzerinde işlenen suçlar: veri tabanına sızma, saatli bomba.
  - İnternette yayın ve hizmetle işlenen suçlar: müstehcenlik, ulusal güvenliği tehdit eden yayın, yalan haber, çocuk istismarı, yasadışı bahis.
  - Kanıtı bilişim ortamında tutulan suçlar.
  - Bilgisayar ağlarında işlenen suçlar.
  - Fikri mülkiyet suçları: kaynak kod aşırma, lisanssız yazılım.
- **TCK'daki bilişime özgü maddeler:**
  - md. 243: bilişim sistemine girme.
  - md. 244: sistemi engelleme, bozma, verileri yok etme veya değiştirme.
  - md. 245: banka veya kredi kartlarının kötüye kullanılması.
  - md. 246: tüzel kişiler hakkında güvenlik tedbirleri.
- **CMK md. 134:** Bilgisayarlarda, bilgisayar programlarında ve kütüklerde arama, kopyalama ve el koyma.
- **Adli bilişim:** Bilişim ortamındaki bulguların teknik donanım ve yazılımla mahkemede kullanılabilecek hukuki kanıta dönüştürülmesi süreci.
- **Adli bilişimin dört alanı:** Disk, bellek, ağ, mobil.
- **Adli bilişimin üç aşaması:**
  - Kanıtı elde etmek ve saklamak.
  - İncelemek ve çözümlemek.
  - Raporlamak.
- **Kanıt:** Bir olayı maddi gerçeklere, hukuka ve akla uygun biçimde, değişmez şekilde anlatan her türlü iz.
- **Ayna imaj (bire bir tıpkı kopya):** Belleğin ve diskin bit düzeyinde kopyası. Sanık ve savcının gözü önünde alınır. Bütünlüğü için hash özeti çıkarılır. İmajın ve hash'in bir kopyası sanığa verilir.
- **5651'deki roller:**
  - **İçerik sağlayıcı:** İçeriği üreten kişi veya kurum (tweet atan kullanıcı, haber sitesi).
  - **Yer sağlayıcı:** İçeriğe yer veren platform (Ekşi Sözlük, Twitter, hosting firması).
  - **Erişim sağlayıcı:** İnternet servis sağlayıcıları (İSS).
  - **Toplu kullanım sağlayıcı:** Kafe veya otel gibi ortak internet sunan işletme.
- **KVKK'nın ilgili maddeleri:**
  - md. 7: silme, yok etme veya anonim hale getirme.
  - md. 8: yurt içinde aktarma.
  - md. 9: yurt dışına aktarma.
- **Özel nitelikli kişisel veri:** Irk, etnik köken, siyasi düşünce, inanç, din, mezhep, sağlık, biyometrik veri gibi veriler.

## Detaylı Açıklamalar

### Türkiye'de Bilişim Mevzuatı

- **TCK 5237:** Bilişim suçlarının cezalarını tanımlar.
- **CMK 5271 md. 134:** Adli bilişimde delil arama, kopyalama ve el koyma usulünü tanımlar.
- **5070 Elektronik İmza Kanunu:** E-imzanın nasıl kullanılacağını, nasıl denetleneceğini ve sahteciliğin cezalarını düzenler.
- **5651:** İnternet ortamındaki yayınları ve bu yayınlarla işlenen suçlarla mücadeleyi düzenler. Kısaca "İnternet Kanunu" denir.
- **6698 KVKK:** Kişisel veri tutan veya işleyen her sistem bu kanuna uygun hazırlanmalı ve işletilmelidir.
- **6563:** Elektronik ticareti düzenler.
- **Avrupa Siber Suç Sözleşmesi:**
  - Türkiye sözleşmeyi 2010'da imzaladı. 2014'te 6533 sayılı onay kanunu yayımlandı.
  - Sözleşmenin kapsamı:
    - sistem ve verilerin gizliliğine, bütünlüğüne ve kullanılabilirliğine karşı suçlar (yasa dışı erişim, veri ve sisteme müdahale, cihazların kötüye kullanımı),
    - bilgisayarla sahtecilik ve dolandırıcılık,
    - içerik suçları (özellikle çocuk istismarı),
    - telif suçları,
    - verilerin korunması ve trafik bilgisinin saklanması,
    - arama ve el koyma,
    - gerçek zamanlı trafik bilgisi toplama,
    - içeriğe müdahale.
  - Sözleşmenin 19. maddesi depolanmış verilerin aranmasını ve el konulmasını düzenler. Hoca, Meclis'in onayladığı Türkçe metnin bire bir çeviri yüzünden anlatım bozukluğu içerdiğini söylüyor ve maddeyi ders notlarından okumanızı istiyor.
- **Bilişim Yasası taslağı:**
  - Tüm bu dağınık kanunları tek bir bilişim kanununda toplamak hedefleniyordu.
  - Tartışmalar sürerken bir çocuk istismarı olayı yaşandı. Taslaktan alıntılarla 5651 aceleyle hazırlanıp Mayıs 2007'de yayımlandı. Bilişim Yasası taslak olarak kaldı.

### Bilişim Suçunun Soruşturulması

- Soruşturmayı savcılık yürütür. Delile ilk dokunan polis veya jandarma gibi kolluk kuvvetleridir.
- **Fark 1, yer:** Klasik suçta suçlu suç mahallindedir. Bilişim suçunda suçlu genellikle başka bir kentte veya ülkededir.
  - Hocanın örneği: İnternet bankacılığından para çalınınca bankanın Levent'teki merkezine gitmek anlamsızdır. Zarar gören kişinin sisteminden geriye doğru gidilmelidir.
- **Fark 2, hız:** Suçlu suçu işlediği süre boyunca belli bir IP adresinden bağlanır. Bu yüzden şikayet gelir gelmez kayıtlar hızla incelenmelidir.
- **Fark 3, kanıtın doğası:** Belgeler, tablolar, ses kayıtları, fotoğraflar ve videolar sayısal kanıttır. Bunları toplamak özel bilgi gerektirir. Bu iş siber suçlarla mücadele birimlerinde uzmanlarca yapılır.
- **Fark 4, değerlendirme:** Suçun izlerini ancak adli bilişim uzmanları değerlendirebilir.

### Adli Kanıt Olarak Sayısal Veriler

- **Bellek:**
  - Bellekteki bilgiler adli kanıt olabilir. Ancak bilgisayar çalışır durumda olmalıdır.
  - Hocanın örneği: Odaya girildiği anda kişinin bilgisayarı kapatması engellenmelidir.
  - Suçüstünde çalışan kötü amaçlı uygulama ve verileri bellektedir. Özel cihazlarla belleğin anlık görüntüsü alınabilir.
- **Disk ve uygulamalar:**
  - Lisanslı ve üreticisi bilinen programların ürettiği kayıtlar güvenilirdir.
  - Üreticisi belirsiz bir programın kayıt dosyası güvenilir değildir.
  - Bu konu derste bir öğrenci sorusuyla açıldı. Hocanın örneği: lisanslı Microsoft Office'in log dosyasına güvenilir, "masa soft" gibi bilinmeyen bir programın log dosyasına güvenilmez.
- **Belgeler:** Word dosyasının yazarı, oluşturma, değiştirme ve yazdırma tarihleri dosyanın başlığında üst veri olarak tutulur. Bunlar kolayca değiştirilebilir. Bu yüzden belge tek başına adli kanıt değildir.
- **Fotoğraf ve video:** EXIF verileri (kamera modeli, zaman damgası, GPS, diyafram vb.) kolayca değiştirilebilir. Değiştirilebilir olması, bu verilerin kanıt değeri taşımadığını da gösterir.
- **CD ve DVD:**
  - Yazım tarihi, yazan bilgisayarın saatinden gelir. Saat istenildiği gibi değiştirilebilir.
  - Hocanın örneği: Nero'nun 2018'de çıkan bir sürümüyle 2016 tarihli bir CD yazılmış görünüyorsa bu, delilin yanıltmak için hazırlandığını gösterir. Hocanın ifadesiyle "anne baba doğmadan çocuk doğmuş" olur.
- **Taşınabilir diskler ve USB bellekler:** CD gibi kolay değiştirilebildikleri için içlerindeki dosyalar adli kanıt sayılmaz.
- **Bulut:**
  - Bir kişi yerelde hiç iz bırakmadan tüm işini bulutta yapabilir.
  - Hizmet sağlayıcı güvenilirse ve yetkisiz erişime izin vermiyorsa buluttaki veriler güvenilir kanıt sayılır.
  - "Kuzenimin şirketinin bulutu" gibi belirsiz bir hizmet güvenilir değildir.
  - Bulut kullanımı ağ kayıtlarından kolayca anlaşılır. Bu durumda buluttaki kayıtların da ayna kopyası alınmalıdır.
- **E-posta:**
  - Gönderen gerçek kimliğini ve IP adresini gizleyebilir. Başlık bilgileri sonradan düzenlenebilir. Bu yüzden e-posta çıktısı adli kanıt sayılmaz.
  - Gmail veya Outlook gibi güvenilir sağlayıcıların olay kayıtları, eylem tutanakları ve trafik bilgileri kanıt olarak kullanılabilir.
  - İki taraf da e-postayı ve içeriğini kabul ederse (ikrar), hakim onu kanıt olarak sayabilir.

### Kanıt Toplama Usulü (CMK md. 134)

- **Olay yerinde bulunması gerekenler:**
  - sanık ve varsa avukatı,
  - savcı,
  - kolluk,
  - varsa adli bilişim uzmanı.
- Bellekten kanıt toplanacaksa çalışan sistemler durdurulmamalıdır.
- **Toplama adımları:**
  - Belleğin ve disklerin ayna imajı, sanık ve savcının gözü önünde alınır.
  - İmajın hash özeti çıkarılır.
  - İmajın ve hash'in bir kopyası sanığa verilir.
  - İtiraz olursa hash yeniden hesaplanır. Aynı çıkıyorsa veri değişmemiştir.
  - Ortamdaki taşınabilir disk, USB, CD ve DVD'lerin de ayna imajı ve hash'i alınır.
- **Öğrenci sorusu:** "Bunları kanıt saymıyorduk, neden kopyalıyoruz?"
  - Hoca: Word dosyasının kendisine güvenilmez. Ama Windows olay kayıtları, Word'ün hangi saniyede açıldığını ve hangi dosyanın kaydedildiğini gösterir.
  - Olay kaydı ile diskteki dosyanın içeriği eşleştirilebilirse, dosyanın gerçekten o kullanıcı tarafından o bilgisayarda üretildiği söylenebilir.
- **Adli bilişim araçları (forensic tools):**
  - Disk imajı alır ve diski bayt bayt inceler.
  - Lisanslı ve güvenilirlik belgeli olmalıdır. Lisanssız araçla toplanan delil, delil sayılmaz.
  - Araç, kopyayı aldığı diske ekleme yapmamalıdır.
  - Kopyayı alan kişi de tarafsız olmalıdır. İmaj almadan önce sisteme bir şey ekleyen kişi kötü niyetli davranmış olur.
- **Silinen veriler:** Bir dosya silinince işletim sistemi yalnızca dosya yerleşim tablosunda o alanı boş olarak işaretler. Üzerine yazılmadıysa ham veri sektörden okunarak geri getirilebilir.
- Çatışma durumu yoksa cihazlara el koymaya gerek kalmaz. Gerekirse cihazlar uygun önlemlerle adli bilişim merkezine götürülür.
- Nereden ve kim tarafından elde edildiği belirsiz disk, CD veya USB önce bu yönden araştırılmalıdır. Bunlar yanıltmak için hazırlanmış olabilir.

### İnceleme, Çözümleme ve Raporlama

- İnceleme, adli tıp laboratuvarına benzer özel bir laboratuvarda uzmanlarca yapılır.
- **Şifreleme:** Önce sanıktan parola istenir. Vermezse kaba kuvvet (brute force) saldırısıyla kırılmaya çalışılır.
  - Hocanın örneği: ABD'de federal birimler şifreli bir iPhone'u açması için Apple'a baskı yaptı. Apple kullanıcı gizliliği gerekçesiyle direndi.
- **Disk incelemesi:**
  - Davayla ilgisiz dosyalar ayıklanır, ilgili olabilecekler tek tek incelenir. İfade aramak için kelime tabanlı arama kullanılır.
  - Üzerine yazılmamış silinen veriler geri getirilebilir.
  - Disk birçok kez belirli örüntülerle (ör. 7 veya 35 geçiş) üzerine yazılarak kazındıysa veri geri getirilemez.
- **Ağ incelemesi:** Saldırı tespit sistemi (intrusion detection system) olan kuruluşlardan veya İSS'lerden kayıt alınır. Kim, kiminle, ne zaman, ne kadar süre ve ne tür iletişim kurdu, bunlar çıkarılır.
- **Mobil:**
  - Akıllı telefon, kendi işletim sistemi olan RISC mimarili küçük bir bilgisayardır. SIM kart, bellek ve depolama incelenir.
  - Operatörlerden HTS (Historical Traffic Search) kayıtları alınabilir: hangi baz istasyonu, ne zaman, kaç saniye. Bunun için mahkeme izni gerekir.
- **Rapor:**
  - Konu, yapılan incelemeler ve aşamalar açıkça yazılır.
  - Bulgular yeterli teknik ayrıntıyla verilir.
  - Sonuç kesin biçimde açıklanır. Hocanın örneği: "Şu dosya şu IP'den şu tarihte geldi, şu kullanıcı şu saatte çalıştırdı, şu dosyalar değişti."
  - Rapor hüküm kurmaz ve ceza önermez. "Kesindir", "tespit edilemez", "ispatlanamaz" gibi ifadelerle durumun fotoğrafını çeker.

### TCK'da Bilişimle İlgili Maddeler

- **Bilişim yoluyla da işlenebilen eski suçlar** (bu maddelere bilişimle ilgili eklemeler yapıldı):
  - intihara yönlendirme (84),
  - çocukların cinsel istismarı (103),
  - uyuşturucu kullanımını kolaylaştırma (190),
  - sağlık için tehlikeli madde temini (194),
  - müstehcenlik (226),
  - fuhuş (227),
  - kumar için yer ve imkan sağlama (228).
- **Özel hayata karşı suçlar:**
  - haberleşmenin gizliliğini ihlal (132),
  - özel hayatın gizliliğini ihlal (134),
  - kişisel verilerin kaydedilmesi (135),
  - verileri hukuka aykırı verme veya ele geçirme (136),
  - verileri yok etmeme (138).
- **Malvarlığına karşı suçlar:**
  - bilişim sistemleri kullanılarak nitelikli hırsızlık (141-142),
  - nitelikli dolandırıcılık (157-158).
  - Cezalar, temel cezanın belli oranlarda artırılması şeklinde verilir.
- **Yalnızca bilişime özgü yeni suçlar:** 243, 244, 245.

### FSEK 5846

- Kanun 1951'de kabul edildi. 2001'deki değişiklikle bilgisayar programları açıkça fikir ve sanat eseri sayıldı.
- **Bilgisayar programı tanımı:** Bir bilgisayar sisteminin özel bir işlem veya görev yapmasını sağlayacak şekilde düzene konmuş bilgisayar emir dizgesi ve bu dizgenin oluşumunu sağlayacak hazırlık çalışmaları. Yani yalnızca kod değil, analiz ve tasarım çalışmaları da korunur.
- **Arayüz (interface):** Donanım ve yazılım unsurları arasında karşılıklı etkileşim ve bağlantı kuran program bölümleri.
- **Ara işlerlik (interoperability):** Program bölümlerinin birlikte çalışması ve aralarında aktarılan bilgiyi karşılıklı kullanabilmesi. Hoca bunu bugünkü birbiriyle haberleşen servislere benzetiyor.
- Bilgisayar programları ilim ve edebiyat eseri sayılır.
- **Eser sayılmayanlar:** Bir programın herhangi bir öğesine, arayüzü de dahil, temel oluşturan düşünce ve ilkeler eser sayılmaz.
  - Hocanın örneği: Klavyeden okuyup bir değişkene atama yapan yapı her programda olan bir niteliktir ve eser sayılmaz.

### 5070 Elektronik İmza Kanunu

- Diğer kanunlar gibi amaç, kapsam ve tanımlarla başlar.
- **Elektronik veri:** Elektronik, optik veya benzeri yollarla üretilen, taşınan ve saklanan kayıtlar.
- **Elektronik imza:** Başka bir elektronik veriye eklenen veya onunla mantıksal bağlantısı bulunan ve kimlik doğrulama amacıyla kullanılan elektronik veri.
- Diğer tanımlar: imza sahibi, imza oluşturma ve doğrulama verisi ile aracı, zaman damgası, elektronik sertifika.
- Kanun daha sonra sorumlulukları ve kötüye kullanımın yaptırımlarını sıralar.

### 5651 İnternet Kanunu

- Amacı:
  - içerik, yer, erişim ve toplu kullanım sağlayıcılarının yükümlülüklerini düzenlemek,
  - belirli suçlarla yer ve erişim sağlayıcılar üzerinden mücadele usulünü belirlemek.
- **İçerik sağlayıcı:**
  - Her türlü içerikten sorumludur.
  - Bağlantı verdiği başkasına ait içerikten sorumlu değildir. Ancak sunuş biçiminden o içeriği benimsediği anlaşılıyorsa sorumlu olur.
  - Haber sitesinde yalan bir haber çıkarsa internet editörü ve yazı işleri müdürü sorumlu tutulur.
- **Yer sağlayıcı:**
  - İçeriği kontrol etmekle yükümlü değildir.
  - Hukuka aykırı içerikten haberdar edilince içeriği yayından kaldırmak zorundadır.
  - Trafik bilgisini 1 yıldan az, 2 yıldan fazla olmamak üzere saklamak ve bu bilginin doğruluğunu, bütünlüğünü ve gizliliğini sağlamakla yükümlüdür.
- **Erişim sağlayıcı:**
  - Hukuka aykırı içerik bildirilince erişimi engeller.
  - Hocanın ifadesine göre kayıtları geriye dönük 6 ay saklama gibi yükümlülükleri vardır.
  - Engelleme kararları tek tek her sağlayıcıya değil, Erişim Sağlayıcıları Birliği'ne gönderilir. Birlik kararı tüm erişim sağlayıcılara iletir.
- **Toplu kullanım sağlayıcı:**
  - Mahalli mülki amirden izin belgesi almalıdır. İzin belgesi olmadan internet paylaşımı yapamaz.
  - Ticari amaç olsun olmasın, erişim kayıtlarını tutmak ve verilen tedbirleri uygulamakla yükümlüdür.
- **Erişim engeli:**
  - md. 8: Belirli TCK suçları ve Atatürk aleyhine işlenen suçlarla ilgili içeriğe erişim engellenir.
  - md. 8/A: Gecikmesinde sakınca bulunan hallerde içeriği çıkarma veya erişimi engelleme.
  - md. 9 ve 9/A: Kişilik haklarının ve özel hayatın korunması için içeriği çıkarma veya erişimi engelleme.
  - Engel yalnızca yurt içini bağlar. Yurt dışından VPN ile erişim sürebilir.
- **Wikipedia örneği:** Birkaç makale yüzünden sitenin tamamı uzun süre kapatıldı. Oysa yalnızca o makalelerin engellenmesi yeterliydi.

### KVKK 6698

- 2016'da Avrupa Birliği uyum yasaları çerçevesinde yürürlüğe girdi.
- Amacı özel hayatın gizliliğini önde tutarak kişisel verilerin işlenmesini ve veri işleyenlerin yükümlülüklerini düzenlemektir.
- Düzenlediği konular:
  - açık rıza,
  - anonimleştirme,
  - kişisel veri tanımı,
  - işleme şartları,
  - özel nitelikli veriler,
  - silme ve yok etme hakkı (md. 7),
  - yurt içine aktarım (md. 8),
  - yurt dışına aktarım (md. 9).
- Kişi verdiği açık rızayı daha sonra geri alıp verilerinin silinmesini veya anonim hale getirilmesini isteyebilir.
- Hocanın eleştirisi: Aktarım "açık rıza olmadan yapılamaz" deniyor. Ama üye olurken açık rıza vermeden ilerlenemiyor ve bu rıza aynı anda üçüncü taraflara ve yurt dışına aktarımı da kapsıyor. Hocaya göre rıza kademeli olmalıydı, örneğin "grup şirketlerine aktarabilirsin ama yurt dışına aktaramazsın" denebilmeliydi.

### 6563 Elektronik Ticaret Kanunu

- Şu kavramları düzenler:
  - elektronik ticaret,
  - ticari iletişim,
  - ticari elektronik ileti (SMS ve e-posta izinleri),
  - hizmet sağlayıcı,
  - aracı hizmet sağlayıcı (pazar yerleri),
  - Bakanlık.
- E-ticaret dolandırıcılıklarının artması bu düzenlemeyi gerekli kıldı.

### Duyurular

- İlk hafta ders sınıfta yapıldı. Sonraki 6 hafta online işlendi. Bu ders teorik bölümün son dersidir.
- **Ara sınav (8. hafta):**
  - Çoktan seçmelidir ve ilk 7 haftanın konularını kapsar.
  - Cevaplar ZipGrade formuna işaretlenecek. Kağıdın geri kalanındaki karalamalar notlandırılmaz.
  - Gerekçe yaklaşık 180 öğrenci olmasıdır. Final de aynı biçimde olacak.
- **Seminer sunumları:**
  - Sunumların son yükleme tarihi 25 Kasım.
  - Sunum planı bu hafta rastgele çekilişle, her haftaya eşit sayıda öğrenci düşecek şekilde açıklanacak.
  - Sunumlar D010 ve D110 sınıflarında iki grup halinde yapılacak.
  - Geçen yılki gibi yüklenen sunumlar önceden hazır bir bilgisayara konacak. Yedek olarak kendi bilgisayarınızı getirebilirsiniz.
  - Ders notlarındaki sunum ve hitabet önerilerine bakın, süreye uyun.
  - Konunuzun mesleki etik boyutuna mümkün olduğunca değinin.
  - Sunumdan sonra rapor için ayrı bir ödev açılacak.

### Ders sonrası notlar

- **1983 tanımı:** Bu tanım Türkçe kaynaklarda genellikle "Avrupa Ekonomik Topluluğu uzmanlar komisyonu" adıyla anılır. Uluslararası kaynaklarda ise OECD'nin 1983 Paris toplantısına dayandırılır.
- **TCK md. 245/A:** 2014'te TCK'ya md. 245/A (yasak cihaz veya programlar) eklendi. Bu madde, suç işlemek için cihaz, program, şifre veya güvenlik kodu üretmeyi, satmayı ve bulundurmayı cezalandırır. Hoca bilişime özgü yeni suçlar olarak üç madde sayıyor, bu maddeyi anmıyor.
- **"Belge kanıt değildir" ifadesi:** Bu ifade genel bir uyarıdır. Mahkemeler sayısal belgeleri tümüyle reddetmez. Hocanın da sonradan açıkladığı gibi, bir belge olay kayıtları ve imaj ile ilişkilendirilip bütünlüğü gösterilirse delil değeri kazanabilir.
- **Apple-FBI davası:** Hocanın andığı olay 2016'daki San Bernardino davasıdır. FBI telefonu sonunda Apple'ın yardımı olmadan, bir üçüncü tarafın aracıyla açtı.
- **Disk silme yöntemleri:** 35 geçişli yöntem Peter Gutmann'ın önerdiği yöntemdir; askeri bir standart değildir. Askeri standart olarak anılan ABD DoD 5220.22-M 3 veya 7 geçiş öngörür. Günümüz disklerinde tek geçiş bile genellikle yeterli kabul edilir.
- **SSD'ler:** Hocanın "bunların hepsi SSD ve flash için de bire bir geçerli" ifadesi tam doğru değil.
  - SSD'lerde TRIM komutu silinen blokları kısa sürede temizler. Bu yüzden silinen veriyi geri getirmek genellikle HDD'den daha zordur.
  - Aşınma dengeleme (wear leveling) nedeniyle üzerine yazma da güvenli silme sağlamaz. SSD'de ATA Secure Erase veya kriptografik silme kullanılır.
- **5651 süreleri:** Erişim sağlayıcı trafik bilgisini 6 aydan az, 2 yıldan fazla olmamak üzere saklar.
- **Bilişim Yasası taslağı:** Hoca taslağın "2010'larda" yoğunlaştığını söylüyor ama aynı derste 5651'in Mayıs 2007'de bu taslaktan alıntıyla çıktığını anlatıyor. Kronolojik olarak taslak çalışmaları 2007 öncesine aittir.
- **Wikipedia:** Erişim engeli Nisan 2017'de başladı. Anayasa Mahkemesi'nin hak ihlali kararıyla Aralık 2019'da kaldırıldı.
- **KVKK ve açık rıza:** KVKK md. 5, açık rıza dışında da işleme şartları sayar: sözleşmenin ifası, hukuki yükümlülük, meşru menfaat gibi. KVK Kurulu, hizmetin açık rıza şartına bağlanmasını hukuka aykırı bulmaktadır.
- **KVKK md. 9 değişikliği:** Yurt dışına aktarımı düzenleyen md. 9, 2024'te 7499 sayılı kanunla değiştirildi. Artık yeterlilik kararı ve uygun güvenceler gibi açık rıza dışı aktarım yolları da var. Hocanın "her şey açık rızaya bağlı" eleştirisi bu değişiklikten önceki metne daha çok uyuyor.

**Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
