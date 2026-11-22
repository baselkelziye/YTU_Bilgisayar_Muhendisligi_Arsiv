# Ders 2 Genişletilmiş Notu: Soru-Cevap Oturumu: Algoritma, Gömülü Sistemler, Ağ Temelleri ve C Dili

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

<!-- BELİRSİZ: Kayıtta slayt yoktur; bütün karelerde yalnız kapalı kamera simgesi görünür. Not tamamen altyazıdan yazılmıştır. -->

## İçindekiler

- 1. Oturumun Niteliği ve Algoritma Kurma Becerisi
- 2. Gömülü Sistemler
- 3. Yeniden Başlatma Neden İşe Yarar?
- 4. Bir Teknik Sorunu Doğru Sormak ve Ayırmak
- 5. Kablosuz Ağlarda Frekans
- 6. DSL Altyapısı, DSLAM ve Trunk Hatları
- 7. Programlama Dillerinin Nesilleri
- 8. C Programlama Dili ve Dersteki Yeri
- 9. Kripto Para ve Blockchain
- 10. Siber Güvenliğe Nereden Başlanır?
- 11. Önerilen Temel Kaynaklar ve İngilizce
- 12. Bilgisayar Mühendisliği Eğitiminin Amacı
- 13. Sanal Gerçeklik, Yapay Zekâ ve Beyin-Bilgisayar Arayüzleri
- Örnek Sorular

## 1. Oturumun Niteliği ve Algoritma Kurma Becerisi

Bu kayıt, dersin laboratuvar saatinde yapılan bir soru-cevap oturumudur. Laboratuvar uygulamaları henüz başlamadığı için hoca bu saati öğrencilerin bölüm, ders ve meslekle ilgili sorularını cevaplamaya ayırmıştır. Slayt kullanılmamış, sorular sohbet penceresinden ya da sesli olarak sorulmuştur. Bu yüzden notun bölümleri, öğrencilerin sorduğu soruların sırasını izler.

Hoca, öğrencilerin kendi başlarına neyi nasıl çalışabileceği sorusuna cevap verirken dersin akışını özetler. Önce bilgisayarın tarihsel gelişimi konuşulacak, ardından "algoritma nedir" sorusuyla başlanacak ve algoritmanın en temel ifade biçimlerinden biri olan akış diyagramı ele alınacaktır. Akış diyagramı öğrenildikten sonra öğrencinin kendi başına çalışabileceği malzeme oluşur.

Hocanın bu noktadaki temel mesajı şudur: Tarihçe önemlidir, veri yapıları önemlidir, ama bilgisayar mühendisliğindeki en önemli becerilerden biri algoritma kurabilmektir. Bu beceri pratikle kazanılır. Çalışma yöntemi şöyledir:

- Bir problem ortaya atılır.
- Problemin çözümü oluşturulur.
- Çözüm akış diyagramıyla ifade edilir.
- Bu süreç farklı problemlerle, farklı çözümlerle tekrar tekrar yapılır.

> **Hocanın vurgusu:** Algoritma kurma yeteneği bilgisayar mühendisliğinin en önemli becerilerinden biridir ve ancak çok sayıda problem üzerinde pratik yaparak kazanılır.

## 2. Gömülü Sistemler

Bir öğrenci, gömülü sistemlerle ilgilenmenin bir geleceği olup olmadığını sordu. Hoca önce bir terim düzeltmesi yaptı: "gömülü yazılım" değil "gömülü sistem" diye bakmak gerekir. Çünkü gömülü sistemlerle uğraşan biri yalnız yazılımla uğraşmaz, donanıma da girmek zorundadır.

### 2.1 Gömülü sistemi zorlaştıran nedir?

Gömülü sistemde bir bütün sistemden söz edilir: içinde hem donanım hem yazılım bileşenleri vardır. Hoca, bu yapıda donanım bileşeninden kaynaklanan bir hatanın yazılım hatası gibi, yazılımdaki bir hatanın da donanım hatası gibi görünebileceğini söyler. Geliştirici kolayca "bir bulmacanın içinde kaybolabilir". Bu nedenle PC üzerinde yazılım geliştirme, ağ, görüntü işleme ya da yapay zekâ ile uğraşmaya göre gömülü sistem geliştirmek daha zahmetlidir.

### 2.2 Hata ayıklamanın dünü ve bugünü

Hoca, on-on beş yıl öncesinde bir mikrodenetleyici programlanırken sistemin durumunu görmek için `printf` ile ekrana yazdırma imkânı bile olmadığını anlatır. Bunun yerine şu yollar kullanılırdı:

- Kart üzerindeki LED'leri yakıp söndürerek durumu göstermek.
- Seri port bağlantısı yapılmışsa seri port üzerinden PC'ye mesaj göndermek.

Bugün işlemcilerin hem kapasitesi hem yetenekleri değişmiştir. Örneğin JTAG arayüzü üzerinden mikrodenetleyiciye bağlanılıp yazılım yüklenebilir ve çalışması adım adım izlenebilir. Hocaya göre işler kolaylaşmış olsa da eskiden kalma bir çekince yüzünden pek az kişi donanım işine girmek istemekte, bu yüzden bu alanda yetişmiş insan sayısı sınırlı kalmaktadır.

### 2.3 Adanmış sistem ve genel amaçlı bilgisayar

Hoca, bir sonraki soruya geçerken gömülü sistemin temel özelliğini açıklar. Gömülü sistemlerin çoğu adanmış (dedicated) işler yapar. Örnekler:

- Bir savaş uçağının pilot destek sistemi, uçuş kontrol sistemi ya da silah kontrol mekanizması. Bunların her biri ayrı bir gömülü sistem olarak geliştirilir.
- Bir buzdolabının içindeki kontrol birimi.

Bu sistemler tek bir işi ya da birkaç işi hep aynı biçimde yapar. PC ise farklıdır: ona farklı yazılımlar ya da donanımlar bağlanarak farklı işler yaptırılabilir. Kamera bağlayıp internet üzerinden görüntülü konuşulabilir, aynı makine yalnız veri tabanı sunucusu olarak kullanılabilir, hatta daktilo yerine kullanılabilir. Yapılan özelleştirmelerle farklı amaçlara hizmet eden bu yapı adanmış değildir.

## 3. Yeniden Başlatma Neden İşe Yarar?

Yavaş internet sorusu sırasında hoca, "herkesin dalga geçtiği" yeniden başlatma (reset) konusuna değinir. Ona göre yeniden başlatmayla dalga geçilmesinin nedeni yöntemin kendisi değil, kötüye kullanılmasıdır.

Gömülü sistemler genellikle hiç kapatılmadan sürekli çalışır. Böyle bir sistem bir durum makinesi (state machine) gibi düşünülebilir: belli adımları vardır ve "şu yapıldı mı, bu yapıldı mı; bu yapıldıysa bu tarafa, şu yapıldıysa şu tarafa" biçiminde geçişler olur. Sistem olması gerektiği gibi çalışmadığında ve hangi durumda olduğu bilinmediğinde yapılması gereken, sistemi bilinen bir duruma getirmektir.

Bilinen durum, ilk açılış anıdır. Sistem güç döngüsünden geçirilirse (power cycle), yani kapatılıp yeniden başlatılırsa, açılışta her şey temiz ve bilinen bir noktaya gelir. Bundan sonra sistem izlenip ne olduğu anlaşılabilir. Yeniden başlatmanın önemi buradan gelir.

> **Hocanın vurgusu:** Yeniden başlatma, bilinmeyen bir durumdan bilinen bir başlangıç durumuna dönmenin yoludur. Ama durmadan yeniden başlatılması gereken bir sistem zaten düzgün bir sistem değildir.

## 4. Bir Teknik Sorunu Doğru Sormak ve Ayırmak

### 4.1 Soruyu doğru sormak

Bir öğrenci "internetim çok yavaş, ne yapabilirim?" diye sordu. Hoca bu soruyu herkese örnek olsun diye ayrıntılı ele aldı. Eğitim hayatı boyunca soru sormak gerekir; kendi kendine öğrenirken bile insan kendine soru sorar. Bu yüzden soruyu düzgün sormayı ve sorunu doğru ifade etmeyi öğrenmek eğitimin bir parçasıdır.

Hoca şu noktaları gösterdi:

- Soran, bağlantısının türünü bilir (telefondan hücresel ağ mı, evde ADSL mi, fiber mi), ama cevap veren bilmez. Bu bilgi baştan verilmelidir.
- Cihazın markası ve modeli açıkça yazılmalıdır; böylece cevap veren cihazı internette arayıp özelliklerine bakabilir.
- "ADSL'dir herhalde" gibi belirsiz ifadeler, soranın kendi sorununu ciddiye almadığı izlenimini verir ve yardım alma ihtimalini düşürür.

> **Hocanın vurgusu:** Sorunuzu açık, eksiksiz ve kesin ifadelerle sorun. Kendi bağlantısının ne olduğunu bilmeyen birine yardım etmek çok zordur.

### 4.2 Sorun ayırma adımları

Öğrencinin ADSL bağlantısı ve TP-Link marka bir modemi olduğu, modemi yeniden başlatınca bir süre düzelip sonra yine yavaşladığı anlaşıldı. Hoca modemin model koduyla internette arama yaptı ve şu adımları önerdi:

- **Yönetim arayüzü:** Modemin bir yönetim (admin) arayüzü vardır. Tarayıcı açılıp modemin yerel ağ adresine bağlanılır. Bu adres 192.168 ile başlayan bir adrestir (ör. 192.168.0.x ya da 192.168.2.1 gibi). Hoca bu adresi rahatça söyleyebildiğini, çünkü bunun herkesin kendi yerel ağında kullandığı bir adres olduğunu belirtti.
- **Firmware:** Aynı modelin birden fazla donanım sürümü (V1, V2, V3, V4) vardır. Sürüm modemin üzerinde "hardware revision" gibi bir etikette yazar. En yeni sürüm için güncelleme çıkmamış olabilir, eski sürümler için birden fazla firmware güncellemesi çıkmış olabilir; gerekiyorsa güncelleme yapılır.
- **Modemin konumu:** Modem evin bir ucundaysa ve kullanıcı birkaç oda ötede Wi-Fi ile bağlanıyorsa yüksek performans beklemek gerçekçi değildir.
- **Sinyal artırıcı:** Sinyal artırıcı kullanılıyorsa gerçekten ne kadar sinyal artırdığına ve modemle arasındaki bağlantının kalitesine bakılmalıdır. Artırıcı modeme yine Wi-Fi ile bağlıysa bu da bir sorun kaynağıdır; mümkünse kabloya çevrilmelidir. Böylece en azından bir aralık garanti altına alınır.
- **Sorunun yerini ayırmak:** Asıl soru, sorunun ev içindeki Wi-Fi bağlantısında mı yoksa dış internet bağlantısında mı olduğudur. Bunu doğrudan bilmek mümkün değildir. Modemin kendi üzerinden bir bağlantı testi yapılırsa ya da bilgisayar modeme Ethernet kablosuyla bağlanıp hız testi yapılırsa sorunun hangi tarafta olduğu daha net söylenebilir.

> **Ders sonrası not:** Hoca 192.168 ile başlayan adresler için "sanal IP adresi" dedi. Bu adreslerin yerleşik adı "özel (private) IP adresi"dir; yalnız yerel ağ içinde geçerlidir ve internette doğrudan yönlendirilmez.

## 5. Kablosuz Ağlarda Frekans

Hoca, yeni modemlerin çoğunun hem 2.4 GHz hem 5 GHz bantlarında çalışabildiğini hatırlatıp kablosuz iletişimde frekansın ne anlama geldiğini açıkladı.

Frekans ne kadar yüksekse taşınabilecek bilgi miktarı o kadar fazladır. Ancak yüksek frekanslı sinyaller duvarların içinden iyi geçmez; bir yerlere çarpar, seker, yansır. Bu yüzden modemin bulunduğu odada iyi çalışan bağlantı başka bir odada zayıflar.

Karşı örnek olarak düşük frekanslı radyo ve telsiz sinyalleri verilir: bu sinyaller çok uzak mesafelere, hatta başka ülkelere ulaşabilir. Menzilleri yüksektir, ama taşıyabildikleri veri miktarı düşüktür.

Buradan pratik sonuç çıkar: Modem iki bantlıysa ve kullanıcı duvarların arkasından 5 GHz ile bağlanıyorsa, 2.4 GHz'e geçmek bağlantıyı iyileştirebilir.

> **Ek bilgi (derste anlatılmadı):** Wi-Fi'de 2.4 GHz ve 5 GHz bantlarının farkı, sinyalin duvar ve engellerde uğradığı zayıflamanın frekansla artmasından gelir. Bu yüzden 5 GHz bandı yakın mesafede daha yüksek hız, 2.4 GHz bandı ise daha geniş kapsama sağlar.

## 6. DSL Altyapısı, DSLAM ve Trunk Hatları

### 6.1 Santral mesafesi ve DSLAM

Hoca, VDSL gibi yapılarda abonenin santrale olan mesafesinin önemli olduğunu söyledi. Birkaç kilometre (örnekte 5 km) mesafedeki abone belli hızların üstüne çıkamaz; birkaç yüz metre mesafedeki abone ise çok yüksek hızlara çıkabilir. Bunun yanında çekilen altyapının ve operatör tarafındaki ağ cihazının kalitesi de önemlidir.

ADSL'de abonenin evine kadar çekilmiş telefon kablosunun operatördeki ucu DSLAM denen cihaza bağlanır. Böylece abone, telefon hattının yanında veri hattına da abone olmuş olur. Hızı etkileyen unsurlar:

- Operatördeki DSLAM cihazının kalitesi ve yapısı.
- Aboneye kadar çekilmiş kablonun kalitesi.
- Bina içi kablolama.

> **Ders sonrası not:** Hoca DSLAM'i "Digital Line Subscriber ..." diye açtı. Doğru açılım Digital Subscriber Line Access Multiplexer'dır.

### 6.2 Trunk hattı ve paylaşılan kapasite

Hoca, aboneye çekilen hattın aslında aboneye özel olduğunu, ama bu hattın bina içinde bir yerde sonlandığını ve oradan santrale gittiğini anlatır. Santral her aboneye tek tek bağlıdır. Ama santralin dünyanın geri kalanıyla konuşabilmesi için bir üst katmandaki başka bir santrale bağlanması gerekir. Bu bağlantı, trunk denen daha yüksek kapasiteli bir hat üzerinden yapılır.

Hocanın örneğinde binlerce abonesi olan bir santral düşünülür. Abonelerin hiçbiri internet kullanmıyorsa, kullanan tek abone kiralık hat (leased line) gibi neredeyse kendi bağlantısına tanımlanmış hızın tamamıyla her yere erişir. Abonelerin bir kısmı aynı anda kullanmaya başladığında ise durum değişir: üstteki trunk hattının kapasitesi bütün abonelerin toplam hızı kadar değil, bundan azdır. Bu yüzden aboneler kapasite için birbiriyle yarışmaya başlar.

Hoca bunu günlük bir gözlemle bağlar: uzaktan eğitim yayınlarının başladığı saatlerde ya da herkesin mesai saatinde video konferansa girdiği dönemlerde internetin yavaşlamasının bir kısmı bu paylaşımdan kaynaklanır. Hoca konuyu ileride laboratuvarda, ağlarla ilgili konuşurken çizimlerle daha ayrıntılı anlatabileceğini belirtti.

> **Ek bilgi (derste anlatılmadı):** Üst hattın kapasitesinin abonelere satılan toplam hızdan az tutulmasına "aşırı abonelik" (oversubscription) denir. Bu yaklaşım, bütün abonelerin aynı anda tam hızda kullanmayacağı varsayımına dayanır.

## 7. Programlama Dillerinin Nesilleri

Bir öğrenci yeni bir programlama dilinin nasıl oluşturulduğunu ve ilk programlama dilinin nasıl ortaya çıktığını sordu. Hoca bu konunun tarihçe dersinde ele alınacağını belirterek kısa bir çerçeve verdi.

Programlama dilleri nesil nesil değişmiştir. Süreç, geliştirilen donanım üzerinde bir şeyler yazabilmek ve donanımı farklı amaçlarla çalıştırabilmekle başlar. Bu ilk aşamadaki dil insan tarafından kolay okunabilir (human readable) değildir. Onu daha anlaşılır hale getirme çabasıyla ikinci, üçüncü, dördüncü ve beşinci nesil diller oluşturulmuştur. Birinci nesilden ikinciye geçişte amaç daha anlaşılır olmaktır; ikinciden üçüncüye geçişte ise bambaşka bir bakış açısı devreye girer. Ayrıntılar tarihçe kapsamında konuşulacaktır.

<!-- BELİRSİZ: Hoca birinci nesli "SM diliyle başlıyor" diye anlattı; altyazıdaki "SM" büyük olasılıkla "assembly" ya da "makine dili"dir. -->

> **Ders sonrası not:** Yaygın sınıflandırmada birinci nesil makine dili, ikinci nesil assembly dilidir. Altyazıda hocanın birinci nesli assembly ile mi makine diliyle mi eşleştirdiği net değildir; doğru eşleştirme büyük olasılıkla birinci nesil = makine dili biçimindedir.

## 8. C Programlama Dili ve Dersteki Yeri

### 8.1 Bu yıl ne kadar C öğrenilecek?

Bir öğrenci bu yıl yalnız C mi öğrenileceğini sordu. Hocanın cevabı: bu yıl C bile tam öğrenilmeyecek, yalnız C programlama diline giriş yapılacak. C yarım dönemde öğrenilebilecek bir dil değildir. Dersteki sıra şöyledir:

- Önce akış diyagramı çizmek öğrenilir: bir problem için oluşturulan çözüm akış diyagramıyla çizilir.
- Akış diyagramı düzgün çizilebildikten sonra C'nin temel öğelerine bakılır: veri tipleri ve nasıl tanımlandıkları, ifadelerin nasıl oluşturulduğu, kontrol yapıları.
- Akışta öğrenilenler C dili üzerinde uygulanır.
- Sonraki dönemde C üzerinde daha fazla pratik yapılır.
- Daha sonraki dönemlerde yapılar (structure), dosyalar, işaretçiler (pointer), dosya işaretçileri ve fonksiyon işaretçileri gibi ileri özellikler gelir.

### 8.2 C neden riskli bir dildir?

Hoca, C'nin karmaşık ve "biraz riskli" bir dil olduğunu söyler; bunun tasarım hatası anlamına gelmediğini de ekler. Pek çok programlama dili varsayılan ayarlarında yapılan hataları ve hata olabilecek yerleri (uyarıları) uzun listeler halinde programcının önüne döker: "iki satır kod yazarsanız yirmi satır laf dinlersiniz." C ise böyle çalışmaz. C derleyicisi olaya "bunu yazan programcıdır ve ne yaptığını biliyor, ben karışmayayım" diye bakar. Bu yüzden yazılmak istenen şeye uymayan hatalı ifadelerde bile derleyici hata vermez, hatta zaman zaman uyarı da vermez. Bu da C öğrenmeyi zorlaştırır.

<!-- BELİRSİZ: Hoca bu noktada C'nin "run to completion mantığıyla oluşturulmuş" bir dil olmadığını söyledi; altyazıdaki ifadenin tam olarak neyi kastettiği net değildir. -->

> **Hocanın vurgusu:** C bir yandan çok basit, bir yandan karmaşıktır. Derleyici hatalı ama geçerli kodda sessiz kalabildiği için dikkatli öğrenilmesi gerekir.

> **Ek bilgi (derste anlatılmadı):** C'de bir dizinin sınırları dışına yazmak ya da ilk değer verilmemiş bir değişkeni okumak gibi hatalar dil standardında "tanımsız davranış" (undefined behavior) sayılır. Derleyicinin bu tür hataları yakalaması zorunlu değildir; `gcc -Wall` gibi seçenekler bazı uyarıları açar.

### 8.3 C'nin güçlü yönleri

Hoca C'nin önemini şu noktalarla açıklar:

- Günümüzde kullanılan birçok işletim sisteminin çekirdeği C ile yazılmıştır. Web ya da mobil uygulamada doğrudan görülmese de günlük hayatta kullanılan hemen her şeyin içinde C vardır.
- Sanılanın aksine oldukça yaygın kullanılır. Kompakt yapısı sayesinde 8 bitlik mikrodenetleyicilerden mainframe'lere kadar her mimaride çalışabilir.
- Doğru kodlanır ve doğru kurgulanırsa oldukça taşınabilirdir (portable). Hoca, Windows, Solaris, HP-UX ve AIX üzerinde çalışan bir C programını başka bir sisteme taşırken neredeyse hiç değişiklik gerekmediğini örnek verir.
- C öğrenildikten sonra programlama mantığı oturduğu için diğer diller de rahatlıkla öğrenilebilir.

> **Ders sonrası not:** Hoca C'yi "fonksiyonel bir dil" diye andı. Programlama paradigmaları açısından C prosedürel (yapısal) bir dildir; fonksiyonel programlama Haskell gibi dillerin ayrı bir paradigmasıdır. Hoca büyük olasılıkla "fonksiyonlar üzerine kurulu prosedürel dil" anlamında kullandı.

### 8.4 Ders dışında başka bir dil öğrenmek

Bir öğrenci ders dışında kendi başına başka bir dil öğrenmenin mantıklı olup olmadığını sordu. Hoca şimdilik bunu önermedi. Gerekçesi şudur: Derste belirli bir mantıkla bir dil öğrenilecektir. Öğrenci aynı anda başka mantıkta bir dil, örneğin nesne yönelimli (object oriented) bir dil ya da C++ öğrenmeye kalkarsa, öğrendiği kaynaklarda doğru mantığa aykırı uygulamalar görebilir ve bu aşamada bunu ayırt edebilecek düzeyde değildir. Hoca, önce nesne yönelimli bir dil öğrenip sonra C'ye geçen öğrencilerin bildiklerini C'de aramaya çalışıp zorlandıklarını gözlemlediğini anlatır. Önerisi, böyle bir işe en erken ikinci dönemin ortasından sonra ya da birinci yılın sonunda başlamaktır.

## 9. Kripto Para ve Blockchain

Bir öğrenci blockchain teknolojisinin geleceğini ve kişisel bilgisayarda kripto para üretme imkânı olup olmadığını sordu.

Hoca tersten başladı: Kişisel bilgisayarda kripto para üretme imkânı artık fiilen ortadan kalkmıştır. Hocanın hatırladığına göre yaklaşık 2014'ten sonra Bitcoin ya da Ethereum gibi sistemlerde gereken hesaplamalar öyle bir noktaya geldi ki, kişisel bilgisayarın kısıtlı sürede yeni blokları hesaplayıp üretmesi performans olarak mümkün değildir. Hoca bunun işlemci saat hızıyla ilgili olmadığını vurgular: "Benimki 2 GHz, seninki 5 GHz, daha hızlıyım" mantığı burada işlemez. Bitcoin hesaplaması artık ASIC'ler üzerinde, yani donanım seviyesinde yapılmaktadır. PC'de ise hesaplama yazılım seviyesindedir; donanım seviyesindeki hesaplama çok daha hızlı olduğu için PC ile uğraşan kişi yalnız boşa elektrik harcamış olur.

Blockchain'in geleceği konusunda hoca, teknolojinin kripto paralarla birlikte yaygın olarak tanındığını, ama günlük hayattaki uygulamalarının henüz tam başlamadığını söyler. Bu yönde çalışmalar vardır ve teknoloji farklı bir boyuta gidebilir; hoca ise konuya biraz şüpheyle baktığını belirtir.

> **Ders sonrası not:** Hoca ASIC'i "Application Specific Integrated Software" diye açtı. Doğru açılım Application Specific Integrated Circuit'tir, yani belirli bir iş için üretilmiş tümleşik devre. Hocanın anlattığı "donanım seviyesinde hesaplama" fikri de bununla uyumludur.

## 10. Siber Güvenliğe Nereden Başlanır?

Bir öğrenci siber güvenliğe yönelmek isteyenlere ne önerildiğini ve nereden başlamak gerektiğini sordu.

Hoca önce siber güvenliğin tek bir konu olmadığını vurguladı. Siber güvenlik, siber sistemlerin her yönünü kapsar: ağ, sistem (işletim sistemi) ve verinin güvenliği. Bu üç boyutun üçüne de hâkim olmak gerekir:

- **İşletim sistemi:** İşletim sisteminin çalışmasını, yapısını ve pratiğini bilmeden onun güvenliğinden söz edilemez.
- **Veri:** Veri tabanının nasıl çalıştığı, nasıl yapılandırıldığı, yapılandırılmış (structured) ve yapılandırılmamış (unstructured) veri tabanlarının ne olduğu ve hangi bileşenlerden oluştuğu bilinmeden veri güvenliği konuşulamaz.
- **Ağ:** Bugün ağ denince IP protokolünden söz edilir. TCP/IP yığınının nasıl çalıştığı ve ağ programlama yalnız soket düzeyinde değil daha ileri düzeyde bilinmelidir. Bundan sonra güvenlik duvarı (firewall) ve saldırı tespit sistemleri (IDS) gibi ağ güvenliği konularına geçilebilir.

Bu alanlar birbirinden bağımsız değildir: örneğin güvenlik duvarı çoğu zaman işletim sistemi üzerinden yapılandırılır. Bu yüzden önce temellere yönelmek gerekir. Doğrudan bir siber güvenlik kitabı alıp okumak tek başına yeterli olmaz; önce işletim sistemi ve ağ gibi temel bilgiler düzgün kaynaklardan okunmalıdır.

> **Hocanın vurgusu:** Siber güvenlik = ağ + işletim sistemi + veri güvenliği. Temelleri bilmeden güvenlik öğrenilemez; önce temel kaynaklar okunmalıdır.

## 11. Önerilen Temel Kaynaklar ve İngilizce

Hoca, temel bilgiler için kaynakların neredeyse tamamının yabancı kaynak olduğunu söyler. Önerdiği kaynaklar:

| Alan | Önerilen kaynak |
|---|---|
| İşletim sistemleri | Silberschatz, *Operating System Concepts* (hoca 8. ya da 9. baskıyı andı) |
| İşletim sistemleri | Tanenbaum'un işletim sistemleri kitabı |
| İşletim sistemleri | Stallings'in işletim sistemleri kitabı |
| Ağ programlama | W. R. Stevens'ın ağ programlama kitabı (iki cilt) |
| Bilgisayar ağları | Tanenbaum, *Computer Networks* (hoca 5. baskıyı andı) |
| Bilgisayar ağları | Stallings, *Data and Computer Communications* |

Hoca işletim sistemleri için bu üç kitabın üçünün de iyi olduğunu, birinden başlanabileceğini söyler. Stallings'in iletişim kitabının iyi ama yorucu olduğunu belirtir.

> **Ders sonrası not:** Hoca Stevens'ın kitabını "Linux Network Programming" diye andı. Kitabın adı büyük olasılıkla *UNIX Network Programming*'dir (iki cilt). Hoca Stevens'ın ölümünden sonra kitabın oğlu tarafından sürdürüldüğünü söyledi; sonraki baskıların ortak yazarları büyük olasılıkla Bill Fenner ve Andrew M. Rudoff'tur.

Kaynakların hepsinin İngilizce olması hocayı bir başka vurguya götürür: Kullanılan teknolojinin dili İngilizcedir. Bu yüzden İngilizceyi "anlıyorum ama konuşamıyorum" düzeyinde değil, anlayan, konuşan ve iyi yazan bir düzeye getirmek gerekir. Hoca, İngilizce düzeyini ölçmek için okuma, yazma ve dinlemenin birlikte sınandığı TOEFL gibi ciddi bir sınavın ya da İngilizceyi gerçek bir iletişimde kullanabilmenin ölçüt olması gerektiğini söyler.

> **Hocanın vurgusu:** Siber güvenlik, sistem yönetimi ya da başka hangi alan seçilirse seçilsin, ilk adım İngilizceyi toparlamak olmalıdır.

## 12. Bilgisayar Mühendisliği Eğitiminin Amacı

Bir öğrenci, belirli alt alanlarda (ör. yapay zekâ, siber güvenlik) açılan yeni mühendislik bölümleri hakkında hocanın görüşünü sordu. Hoca, farklı konuların dönem dönem popüler olduğunu söyler: görüntü işleme bir dönem çok popülerdi ve hâlâ popülerdir; yapay zekâ bugün daha da popüler hale gelmiştir; siber güvenlik dünyada uzun zamandır popüler olup ülkede yeni yükselmektedir.

Hoca bu tür bölümlere sıcak bakmadığını söyler ve bölümün amacını şöyle tanımlar: Burada yapay zekâ mühendisi, yazılım mühendisi, sistem tasarımcısı ya da gömülü sistem mühendisi yetiştirilmez. Burada bilgisayar mühendisi yetiştirilir, yani bir bilgisayar mühendisinin sahip olması gereken bütün temel bilgiye ve sistematiğe sahip insanlar. Sonrasında hangi alanda uzmanlaşılacağı kişiye kalmıştır.

## 13. Sanal Gerçeklik, Yapay Zekâ ve Beyin-Bilgisayar Arayüzleri

### 13.1 Sanal gerçeklik

Bir öğrenci sanal gerçeklik teknolojisinin geleceğini sordu. Hoca bu alanda yol alınmış olsa da yapılabilecek çok şey olduğunu, salgın döneminin de bu alanda yapılabilecekleri yeniden düşünmek için bir fırsat yarattığını söyler. Sanal gerçeklik denince çoğu insanın aklına gözlük takıp sanal bir ortamda gezinmek gelir. Hocaya göre bir sonraki adım etkileşimli sanal gerçekliktir: dokunma ve koku hissi gibi, duyu organlarına geri bildirim verebilen teknolojiler. Bunların bir kısmı vardır ama henüz yaygın değildir, çoğu prototip aşamasındadır. Gelişme bu yönde ilerleyecek, sonra görsellikle birleşecektir.

### 13.2 GPT-3 ve doğal dil işleme

Bir öğrenci GPT-3 gibi insan benzeri metin üreten yapay zekâ modellerinin mesleği tehdit edip etmediğini sordu. Hoca, insan benzeri metin üretmenin bilgisayar mühendisinin işinin yalnız bir parçası olduğunu söyler. Ayrıca GPT-3'ün İngilizcede başarılı metin ürettiğini, ama Türkçede sonuçların çok farklı olduğunu belirtir. Her dilin farklı özellikleri vardır; bir dil için kurulan model başka bir dilde hiçbir işe yaramayabilir. Doğal dil işleme alanında alınmış güzel bir yol olsa da daha yapılacak çok iş vardır. Özellikle sosyal medyadaki özensiz yazılmış metinler doğal dil işlemeyi daha da zorlaştırır.

Hoca, bir öğrencinin sanayi devrimi benzetmesine bir karşı örnekle cevap verir: Seri üretim mobilya yaygınlaşınca kalitesiz çalışan küçük üreticiler zor duruma düştü, ama gerçekten yetenekli ve kaliteli el işçiliği yapanlar daha niş pazarlarda daha çok kazanmaya başladı. Ona göre yapay zekâ da asıl olarak kalitesiz işin elenmesine yol açacaktır; kendini iyi yetiştiren bir bilgisayar mühendisinin korkacak bir şeyi yoktur.

> **Ders sonrası not:** Altyazıda GPT'nin açılımı bozuk geçmektedir. Doğru açılım Generative Pre-trained Transformer'dır; GPT-3 bu modelin üçüncü sürümüdür.

### 13.3 Beyin-bilgisayar arayüzleri

Bir öğrencinin sorusu üzerine (sorunun metni altyazıda yoktur) hoca, bunun mümkün olduğunu ve biyomühendislik ile biyoloji tarafında deneyler ve yayınlar bulunduğunu söyler. Örnek olarak, yıllar önce canlı sinir hücreleriyle küçük tekerlekli bir aracın hareketini yöneten bir çalışmayı ve sinirlerinin bir kısmını bir arayüz üzerinden başka bir kişinin sinirlerine bağlayıp bazı hisleri aktarabilen bir araştırmacıyı anar. Hocaya göre dışarıdan birçok his simüle edilebilir; bu yalnız yapay sinir ağlarının değil, malzeme biliminin ve elektroniğin gelişmesine de bağlıdır.

<!-- BELİRSİZ: 01:30:35 civarındaki öğrenci sorusunun metni altyazıda geçmiyor; cevaptan beyin-bilgisayar arayüzü ya da his simülasyonu ile ilgili olduğu anlaşılıyor. -->

## Örnek Sorular

Bu oturumda ekranda soru gösterilmedi. Aşağıdaki sorular derste öğrencilerin sözlü ya da yazılı olarak sorduğu sorulardır; cevaplar hocanın verdiği cevaplardır.

**Soru 1** (derste sözlü, 00:18:48): Ev internet bağlantım çok yavaş, ne yapabilirim?

> **Cevap:** Önce bağlantı türü (hücresel, ADSL, fiber) ve modemin markası/modeli açıkça belirtilmelidir. Sonra modemin yönetim arayüzüne 192.168 ile başlayan yerel adresten girilip donanım sürümüne göre firmware güncellemesi kontrol edilir; modemin konumu, kullanılan Wi-Fi bandı (duvar arkasında 2.4 GHz daha iyi geçer) ve sinyal artırıcının modeme nasıl bağlandığı incelenir. Son olarak modemin kendi testi ya da Ethernet kablosuyla bağlı bir bilgisayardan hız testi yapılarak sorunun ev içi Wi-Fi'de mi dış bağlantıda mı olduğu ayrılır.

**Soru 2** (derste sözlü, 00:44:11): Yeni bir programlama dili nasıl oluşturulur, ilk programlama dili nasıl ortaya çıktı?

> **Cevap:** Ayrıntısı tarihçe dersinde anlatılacaktır. Diller nesil nesil gelişmiştir: önce donanım üzerinde doğrudan çalışan, insan için okunması zor alt seviye dil; ardından dili insan için daha anlaşılır kılmak amacıyla ikinci, üçüncü, dördüncü ve beşinci nesil diller.

**Soru 3** (derste sözlü, 00:45:44): Bu yıl yalnız C mi öğrenilecek? C neden "riskli" bir dil olarak anılır?

> **Cevap:** Bu yıl C'ye giriş yapılacak: önce akış diyagramı, sonra C'nin veri tipleri, ifadeleri ve kontrol yapıları. C risklidir çünkü derleyici programcının ne yaptığını bildiğini varsayar; hatalı ama geçerli ifadelerde çoğu zaman hata, bazen uyarı bile vermez.

**Soru 4** (derste sözlü, 00:52:57): Kişisel bilgisayarda kripto para üretmek bugün mümkün müdür?

> **Cevap:** Pratikte hayır. Hesaplamalar donanım seviyesinde, ASIC'lerle yapılmaktadır. Kişisel bilgisayarda yazılımla yapılan hesaplama bu hıza yetişemez; yalnız boşa elektrik harcanır. Bu, işlemcinin saat hızıyla ilgili değildir.

**Soru 5** (derste sözlü, 00:55:56): Siber güvenliğe nereden başlanmalıdır?

> **Cevap:** Siber güvenlik ağ, işletim sistemi ve veri güvenliğini kapsar. Önce işletim sisteminin, veri tabanlarının ve TCP/IP'nin nasıl çalıştığı temel kaynaklardan öğrenilmeli, sonra güvenlik duvarı ve saldırı tespit sistemleri gibi güvenlik konularına geçilmelidir.

**Soru 6** (derste sözlü, 01:22:11): Sanal gerçeklik teknolojisinin geleceğini nerede görüyorsunuz?

> **Cevap:** Bir sonraki adım, yalnız görsel gezinme değil, dokunma ve koku gibi duyulara geri bildirim veren etkileşimli sanal gerçekliktir. Bunların bir kısmı prototip aşamasındadır; gelişme bu yönde ilerleyip görsellikle birleşecektir.

## Dersin Toparlaması

Bu oturum slaytsız bir soru-cevap saati olmasına rağmen birçok temel kavrama değindi. Algoritma kurma becerisinin bilgisayar mühendisliğinin merkezinde olduğu ve bu becerinin akış diyagramlarıyla, çok sayıda problem üzerinde pratik yaparak kazanılacağı vurgulandı. Gömülü sistemlerin adanmış yapısı ve donanım-yazılım iç içeliği, yeniden başlatmanın sistemi bilinen bir başlangıç durumuna döndürmesi, kablosuz iletişimde frekans ile menzil ve veri miktarı arasındaki ödünleşim, DSL altyapısında santral mesafesi ve paylaşılan trunk kapasitesi gibi konular öğrencilerin sorularına verilen cevaplarla açıklandı.

Programlama tarafında dillerin nesiller halinde geliştiği ve C'nin bu derste nasıl ele alınacağı anlatıldı: önce akış diyagramı, sonra C'nin veri tipleri, ifadeleri ve kontrol yapıları. C'nin işletim sistemi çekirdeklerinin dili olması, taşınabilirliği ve derleyicinin hatalarda sessiz kalabilmesinden doğan riski öne çıkarıldı. Siber güvenlik ve diğer alanlar için önce işletim sistemi, ağ ve veri tabanı temellerinin İngilizce temel kaynaklardan öğrenilmesi önerildi. Hoca, sonraki teorik derste tarihsel gelişime ve ardından algoritma ile akış diyagramlarına geçileceğini belirtti.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
