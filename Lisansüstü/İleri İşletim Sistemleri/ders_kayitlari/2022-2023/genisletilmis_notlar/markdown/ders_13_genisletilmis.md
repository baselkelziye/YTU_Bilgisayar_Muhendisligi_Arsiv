# Ders 13 Genişletilmiş Notu: Disco: Hazır İşletim Sistemlerini Ölçeklenebilir Çok İşlemcilerde Çalıştırmak

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

Bu ders, önceki haftaların düzeniyle, öğrencilerin önceden okuduğu bir makalenin soru-cevapla tartışılmasıyla geçti. Kayıt kısadır; akademik tartışma yaklaşık yirmi iki dakika sürer. Bu haftanın makalesi, bir önceki derste kısaca giriş yapılan Disco makalesiydi. Bir öğrenci önce makaleyi sözlü özetledi, sonra hocanın sorularına cevap verebilmek için makaleyi kendi işaretlediği yerlerle birlikte ekranda paylaştı. Hoca soruları sordu, cevapları tamamladı ve önemli cümlelerin ne anlama geldiğini açtı. Aşağıdaki makale alıntıları ekranda paylaşılan makale sayfalarından alınmıştır.

> **Ek bilgi (derste anlatılmadı):** Ekranda paylaşılan makalenin sayfa başlığında "Disco: Running Commodity Operating Systems on Scalable Multiprocessors" adı ve E. Bugnion, S. Devine, K. Govil ve M. Rosenblum yazarları görünür (ekrandan, 00:20:00; 00:25:00). Bu, büyük olasılıkla makalenin 1997'de ACM Transactions on Computer Systems'ta yayımlanan genişletilmiş sürümüdür; ilk sürümü büyük olasılıkla aynı yıl SOSP'ta Bugnion, Devine ve Rosenblum adıyla yayımlanmıştır. Yazarlar büyük olasılıkla daha sonra VMware'in kurucuları arasında yer almıştır; ESX Server makalesiyle bağlantı buradan gelir.

## İçindekiler

- 1. Makalenin genel fikri: Disco nedir?
- 2. Sanal makinelerin karşılaştığı zorluklar
- 3. Ek yükler ve yetkili komutlar
- 4. Kaynak yönetimi: boşta döngü, meşgul bekleme ve gerçek hesap
- 5. Paylaşım ve haberleşme
- 6. NUMA ve CC-NUMA
- 7. Disco'nun çözümleri
- 8. Disco'nun gerçekleştirimi
- Örnek Sorular
- Dersin Toparlaması

## 1. Makalenin genel fikri: Disco nedir?

Hoca, makaleyi okuyan öğrenciden okuyabildiği kadarıyla Disco'yu anlatmasını istedi. Öğrencinin özeti şöyleydi. Makale "büyük ölçekli sistem" (large scale system) dediği yapılarla ilgilidir: çok işlemcili, paylaşımlı bellekli ya da tekdüze olmayan bellek erişimli (NUMA) sistemler. Bu tür sistemlerde, normalde kullanılan standart, hazır (commodity) işletim sistemlerinin çalışabilmesi için çok fazla kod değişikliği gerekir.

Disco bu tür sistemlerde araya giren bir katmandır; bir sanal makine izleyicisi (Virtual Machine Monitor, VMM) gibi çalışır. Hazır işletim sistemlerinin hepsini destekler ve işletim sistemini o makineye uyarlamak için gereken değişikliğe göre çok daha az kod içerir. Sisteme getirdiği yük azdır. Öğrencinin ifadesiyle makale, bu ara katmanı ve onun nasıl yapıldığını tek tek anlatır.

Öğrenci ilk turda Disco'nun öne çıkan üç özelliğini saydı:

- Önceki sistemlerin desteklemediği NUMA bellekleri destekler.
- Sanal makinelerin birbiriyle haberleşmesi için bir ağ kurar.
- Copy-on-write diskler kullanır: bellekteki bazı blokları bütün sanal makinelere paylaşımlı verir. Her seferinde belleğe yeni bir blok kopyalanmaz, bütün sanal makineler aynı bloğu kullanır ve bellek kullanımı azalır. Bir değişiklik olursa copy-on-write işaretleri sayesinde güncelleme yapılır.

Bu özellikler sonraki bölümlerde ayrıntılı ele alınacaktır.

## 2. Sanal makinelerin karşılaştığı zorluklar

Hoca öğrencinin anlattıklarının Disco'nun özellikleri ve diğer yapılardan farkları olduğunu, kendi sorusunun ise başka olduğunu belirtti. Sorduğu şey, sanal makine kullanmanın, çalıştırmanın ve bu ortamı oluşturmanın kendisinden gelen zorluklardı; makalede bunlar ayrıca yazılıdır.

Öğrenci makaleyi ekranda paylaştı ve "3.1 Challenges Facing Virtual Machines" bölümünü açtı. Bölümün girişinde sanal makine izleyicisi kullanmanın avantajlarının bazı dezavantajlarla birlikte geldiği söylenir. İyi bilinen sorunlar şunlardır (ekrandan, 00:15:00):

- Donanım kaynaklarının sanallaştırılmasından doğan ek yükler (overheads),
- Kaynak yönetimi (resource management),
- Paylaşım (sharing),
- Haberleşme (communication).

Makale bunları sırayla, italik alt başlıklarla anlatır: "Overheads", "Resource Management" ve "Communication and Sharing". Hoca, "Resource Management" başlığını öğrencinin işaretlemediğini, okurken hızlıca geçtiğini fark etti ve tartışmayı o bölüme de taşıdı.

## 3. Ek yükler ve yetkili komutlar

### 3.1 Makaledeki ifade

Makaleye göre geleneksel sanal makine izleyicilerindeki ek yük birçok kaynaktan gelir: ek istisna (exception) işleme, komut yürütme ve donanımı sanallaştırmak için gereken bellek. Öğrencinin işaretlediği cümleler şunlardır (ekrandan, 00:15:00):

> "Operations such as the execution of privileged instructions cannot be safely exported directly to the operating system and must be emulated in software by the monitor. Similarly, the access to I/O devices is virtualized, so requests must be intercepted and remapped by the monitor."

Yani yetkili komutların yürütülmesi gibi işlemler işletim sistemine güvenli biçimde doğrudan açılamaz, VMM tarafından yazılımda öykünülmelidir (emulate edilmelidir). G/Ç aygıtlarına erişim de sanallaştırılır; istekler VMM tarafından yakalanmalı ve yeniden eşlenmelidir.

Makalenin aynı bölümüne göre ek yük yalnız yürütme süresinde değildir. Birden çok bağımsız sanal makine çalıştırmanın ek bellek maliyeti de vardır: her işletim sisteminin ve uygulamanın kodu ve verisi her sanal makinenin belleğinde ayrı ayrı kopyalanır. Dosya sistemi tampon önbelleği gibi büyük bellek yapıları da kopyalanır ve bellek kullanımı ciddi biçimde artar. Benzer bir israf, farklı sanal makinelerin dosya sistemlerinin diskte kopyalanmasıyla da oluşur (ekrandan, 00:15:00).

### 3.2 Yetkili komut nedir, neden doğrudan verilemez?

Öğrenci, yetkili komutlarla belleğe doğrudan erişim komutlarının mı kastedildiğinden emin olmadığını söyledi. Hoca kavramı açtı.

"Privileged" yetkili demektir. Yetkili komutlar, işlemcinin çalışmasını doğrudan etkileyebilecek komutlardır. Örnekler:

- Kesmelerin açılması (enable) ve kapatılması (disable),
- İşlemcinin sıfırlanması (reset),
- Bir G/Ç portuna erişilmesi, o porttan okunması ya da porta yazılması.

Hoca G/Ç portu örneği üzerinden sorunu şöyle anlattı. G/Ç portlarına erişim komutları sanal makinelere doğrudan açılırsa, o sanal makinede çalışan işletim sistemi bu komutu kullanıp G/Ç portuna erişebilir. Böylece o portun üzerinden erişilen donanımın yapısını ve çalışma şeklini değiştirebilir. Bu değişiklik, aynı donanımı kullanan başka bir sanal makinenin çalışmasını etkiler. Bu yüzden erişimin kontrollü olması gerekir.

Öte yandan sanal makinedeki işletim sistemi bu komutu kullanmak zorundadır; başka çaresi yoktur, çünkü üzerinde bu komuta ihtiyaç duyan bir kod parçası yazılıdır. Çözüm, komutu sanal makineye doğrudan açmak değil, öykünme (emülasyon) yoluyla açmaktır. Arka tarafta VMM, hedef alınan donanımı sanallaştırarak onun paylaşımlı kullanılmasını sağlar.

> **Hocanın vurgusu:** Yetkili komutlarla birlikte G/Ç cihazlarının da sanallaştırılması doğal olarak gerekir. Bir G/Ç aygıtını tek bir sanal makineye atarsanız diğer sanal makinelerin ne yapacağı sorusu doğar.

Öğrenci bu noktada makalede G/Ç aygıtlarının kullanımına ilişkin ayrı bir kısım olduğunu da ekledi.

## 4. Kaynak yönetimi: boşta döngü, meşgul bekleme ve gerçek hesap

### 4.1 Makaledeki ifade

"Resource Management" alt başlığına göre sanal makine izleyicileri, iyi politika kararları vermek için gereken bilgiye sahip olmadıklarından sık sık kaynak yönetimi sorunları yaşar. Örneğin bir işletim sisteminin boşta döngüsünün (idle loop) ya da kilit için meşgul bekleme (busy-waiting) kodunun komut akışı, VMM seviyesinde önemli bir hesaptan ayırt edilemez (ekrandan, 00:15:00; 00:20:00). Makale devamında şöyle der (ekrandan, 00:20:00):

> "The result is that the monitor may schedule resources for useless computation while useful computation may be waiting. Similarly, the monitor does not know when a page is no longer being actively used by a virtual machine, so it cannot reallocate it to another virtual machine."

Yani VMM faydalı hesap beklerken kaynakları faydasız hesaba ayırabilir. Benzer şekilde bir sayfanın sanal makine tarafından artık etkin kullanılmadığını bilemediği için onu başka bir sanal makineye veremez. Genel olarak VMM, kaynak yönetimi kararlarını bir işletim sisteminin sahip olacağı üst düzey bilgi olmadan vermek zorundadır.

### 4.2 Cümlenin anlamı

Hoca, öğrencinin fare imlecini üzerinde gezdirdiği cümlenin neden önemli olduğunu sordu. Öğrenci şöyle açıkladı: VMM, boşta döngüde dönen bir sanal makineye CPU'yu boşuna harcamış olur. Bu tamamen boş bir işlemdir; o sırada CPU başka bir sanal makineye devredilebilirdi.

Hoca bunu tamamladı. İşletim sistemi sanal bir ortamda değil de doğrudan donanım üzerinde, yani "bare metal" denen yapıda çalışsaydı, bu boşta döngüye ihtiyacı olurdu. Çünkü o sırada çalıştırabileceği bir proses ya da thread yoktur, ama işlemcinin durması söz konusu olmadığına göre boş zaman geçirmesi gerekir. Sanal ortamda ise bu boş zamanın fark edilmesi ve o zaman dilimi için işlemcinin bu sanal makineye verilmesi yerine bilakis ondan alınıp başka bir sanal makineye tahsis edilmesi en doğrusudur.

İkinci durum kilitle ilgilidir: bir kaynağa erişmek için bir kilit vardır ve kilidin serbest kalıp kalmadığı meşgul beklemeyle sürekli kontrol edilir. Bu da anlamlı bir iş değildir.

Hoca üç durumu yan yana koydu:

- Bir sanal makine matris çarpımı yapıyor. Bu hesap yoğun (compute intensive), anlamlı bir iştir.
- Bir sanal makine bir kilidin boşa çıkıp çıkmadığını anlamak için sürekli kontrol ediyor (meşgul bekleme).
- Bir sanal makine boşta döngüde vakit geçiriyor.

Üçü de dışarıdan bakıldığında işlemciyi çok ciddi kullanır. Ama yalnızca birincisi anlamlıdır.

> **Hocanın vurgusu:** Bu farkı VMM seviyesinde fark edemediğiniz sürece kaynakları yanlış sanal makinelere yanlış zamanlarda tahsis edebilirsiniz. Anlamlı iş yapmak için CPU bekleyen sanal makinelere CPU verememiş olursunuz.

## 5. Paylaşım ve haberleşme

Sonraki alt başlık "Communication and Sharing"dir. Makaleye göre birden fazla bağımsız işletim sistemi çalıştırmak paylaşımı ve haberleşmeyi zorlaştırır. Örneğin VM/370 üzerindeki CMS'te, bir kullanıcının dosyalarını içeren sanal disk bir sanal makinede kullanılıyorsa başka bir sanal makine ona erişemezdi. Aynı kullanıcı iki sanal makine başlatamazdı ve farklı kullanıcılar dosyaları kolayca paylaşamazdı. Sanal makineler, yalnızca aynı donanımı paylaşan bir dizi bağımsız tek başına sistem gibi görünürdü (ekrandan, 00:20:00).

Makale bu dezavantajların hâlâ var olduğunu, ama işletim sistemi teknolojisindeki yeni gelişmelerle VMM'ye eklenen bazı yeni hilelerin birleştirilmesiyle etkilerinin çok azaltılabildiğini söyler. Örneğin modern işletim sistemlerinin dağıtık ortamda birlikte çalışmayı yaygın biçimde desteklemesi, paylaşım ve haberleşme sorunlarını büyük ölçüde azaltır (ekrandan, 00:20:00).

Öğrenci bunu, ilk turda saydığı Disco özellikleriyle ilişkilendirdi: Disco'nun sağladığı özellikler sayesinde birden fazla sanal makinenin haberleşebilmesi ve dosya paylaşabilmesi sorunu da çözülür. Bu özellikler Bölüm 7'de anlatılmaktadır.

## 6. NUMA ve CC-NUMA

### 6.1 NUMA

Hoca NUMA mimarisinin ne demek olduğunu sordu. Öğrenci açılımın Non-Uniform Memory Access (tekdüze olmayan bellek erişimi) olduğunu, makalede de belirtildiğini söyledi. Ardından öğrenci farkı şöyle özetledi, hoca da onayladı:

- Normal (tekdüze) yapıda tek bir bellek vardır. Bütün CPU'lar belleğe eşit uzaklıktadır. Bu yüzden hepsinin erişim zamanı tekdüzedir (uniform), yani eşittir.
- NUMA'da ise tam tersi geçerlidir. Birden fazla bellek vardır ve CPU'ların farklı belleklere uzaklıkları farklıdır. Bu yüzden erişim süresi tekdüze değildir (non-uniform).

### 6.2 CC-NUMA

Hoca bir de CC-NUMA'nın ne demek olduğunu sordu. Öğrenci bilmediğini, terimi görüp bakamadığını söyledi; makalede "cache coherent" teriminin çok geçtiğini de belirtti. Hoca CC'yi önce "closely coupled" (birbiriyle doğrudan bağlantılı, "loosely coupled"ın karşıtı) diye açtı, sonra cache coherent'ın bunun başka bir ifadesi olduğunu söyledi. Tartışmanın sonunda hoca şu tanımı verdi: closely coupled ya da cache coherent dendiği zaman işlemcilerin önbellekleri arasında donanım seviyesinde bir bütünlük vardır. Donanım bazında bir haberleşme vardır; araya bir ağ katmanı girmez, haberleşme böyle bir katman olmadan gerçekleşir.

<!-- BELİRSİZ: 00:21:13-00:21:28 arasında hocanın "closely coupled'da böyle bir şey yok", "birinin cache'ine diğeri müdahale edemiyor" cümleleri geçiyor; bunlar büyük olasılıkla "loosely coupled" için söylendi, Whisper sözcüğü karıştırmış olabilir. -->

> **Ders sonrası not:** Hoca CC kısaltmasını "closely coupled" diye açtı. CC-NUMA'nın yerleşik açılımı "cache-coherent NUMA"dır (önbellek tutarlı NUMA): işlemcilerin önbellekleri donanım tarafından tutarlı tutulur. Hocanın verdiği asıl tanım, yani önbellekler arasında araya ağ katmanı girmeden donanım seviyesinde bütünlük olması, bu açılımla uyumludur.

## 7. Disco'nun çözümleri

### 7.1 FLASH makinesi ve MIPS R10000

Öğrenci makalenin "4. Disco: A Virtual Machine Monitor" bölümüne geçti (ekrandan, 00:20:00). Disco, FLASH adlı, MIPS tabanlı, önbellek tutarlı (cache-coherent) bir çok işlemcili makine için yazılmıştır. Hoca işlemcinin MIPS R10000 olduğunu söyledi.

Öğrenci makalede işlemcilerin yüksek başarımlı, ölçeklenebilir bir ara bağlantıyla (high performance scalable interconnect) bağlandığının yazdığını okudu. <!-- BELİRSİZ: Bu kısımda altyazı bozuk ("Disco Connect to with High Performance Scalive Internet Connect"); hocanın bu ifadeyle ilgili sorusu ve öğrencinin cevabı tam anlaşılmıyor. -->

Ekranda görünen sayfaya göre, FLASH makinesi için gerekli olsa da R10000 işlemcisinin seçimi Disco için talihsizdi, çünkü R10000 çekirdek sanal adres uzayının tam sanallaştırılmasını desteklemez. Makale, çekirdek kipindeki kodun Disco üzerinde çalışabilmesi için gereken işletim sistemi değişikliklerini ayrı bir bölümde (4.3.1) anlatır. MIPS işlemcisinin öykünmesinin yanında Disco, bazı işlemci işlevlerine verimli erişim için mimariyi genişletir: kesmeleri açıp kapatma ve yetkili yazmaçlara erişme gibi sık çekirdek işlemleri, özel adreslere yapılan load ve store komutlarıyla gerçekleştirilebilir. Bu arayüz, Disco'ya göre ayarlanmış işletim sistemlerinin tuzak öykünmesinden (trap emulation) doğan ek yükü azaltmasını sağlar (ekrandan, 00:25:00).

Bu sırada tuzak kavramı da konuşuldu. Öğrenci tuzağın (trap) CPU'da bir hata oluştuğunda devreye giren istisna mekanizması olduğunu hatırladı. Hoca bunu yazılım kesmesi (software interrupt) diye niteledi ve sıfıra bölmeyi örnek verdi. Öğrenci, bu tür durumlar oluştuğunda VMM'nin bazı komutları öykündüğünü, yani tuzak oluştuğu anda komutu kendisinin alıp yorumladığını ekledi.

> **Ders sonrası not:** Sıfıra bölme, büyük olasılıkla daha doğru bir terimle, işlemcinin komut yürütülürken ürettiği eşzamanlı bir istisnadır (exception/trap). "Yazılım kesmesi" terimi çoğu kaynakta programın bilerek çalıştırdığı kesme komutları (örneğin sistem çağrısı için kullanılan tuzak komutu) için kullanılır; ikisi de dış donanım kesmesinden farklı olarak komut akışından doğar.

### 7.2 Fiziksel bellek ve dinamik sayfa göçü ile kopyalama

Ekranda görünen "Physical Memory" paragrafına göre Disco, sıfır adresinden başlayan bitişik bir fiziksel adres uzayında duran bir ana bellek soyutlaması sağlar. Bu düzen, işletim sisteminin yaptığı varsayımlara uymak için seçilmiştir. Çoğu hazır işletim sistemi FLASH makinesinin tekdüze olmayan belleğini etkin biçimde yönetecek şekilde tasarlanmamıştır. Öğrencinin işaretlediği cümle şudur (ekrandan, 00:25:00):

> "Disco uses dynamic page migration and replication to export a nearly uniform memory access time memory architecture to the software."

Bu sayede NUMA'dan habersiz bir işletim sistemi, NUMA bellek yönetimi için gereken değişiklikler yapılmadan FLASH üzerinde iyi çalışır.

Hoca "dinamik sayfa göçü ve kopyalama" ifadesinin ne anlama geldiğini sordu. Öğrenci makalenin ilerisinde bundan bahsedildiğini, ama ayrıntısını anlamadığı için düzgün cevap veremeyeceğini söyledi; soru derste cevaplanmadan kaldı.

> **Ek bilgi (derste anlatılmadı):** Büyük olasılıkla makalenin ilgili bölümüne göre Disco, hangi işlemcinin hangi sayfaya sık eriştiğini izler. Tek bir işlemcinin (ya da düğümün) yoğun kullandığı bir sayfayı o işlemcinin yakınındaki belleğe taşır (göç, migration). Birden fazla düğümün çoğunlukla okuduğu bir sayfanın ise her düğümün yerel belleğinde bir kopyasını oluşturur (kopyalama, replication). Konuk işletim sisteminin gördüğü fiziksel adres değişmez, yalnız VMM'nin fiziksel adresten makine adresine eşlemesi değişir; böylece erişimlerin çoğu yerel belleğe düşer ve bellek, yazılıma neredeyse tekdüze görünür.

### 7.3 Sanal disklerin paylaşım ve kalıcılık modelleri

Hoca bir önceki konuya dönerek şunu sordu: VM/370 üzerindeki CMS'te sanal diskler paylaşılamıyordu ve bir kullanıcı yalnızca bir sanal makine oluşturabiliyordu. Disco'da ise öğrencinin işaretlediği bir cümleye göre sanal diskler farklı paylaşım ve kalıcılık modellerini destekleyecek biçimde yapılandırılabilir ("Virtual disks can be configured to support different sharing and persistency models"). Bundan ne anlaşılır?

Öğrencinin cevabı ve hocanın tamamlamasıyla iki model ortaya çıktı:

- Bazı diskler, sanal makine kapandığında içeriği hiçbir şekilde diske kaydedilmeyecek biçimde oluşturulabilir. Hoca buna "ephemeral" (geçici) dendiğini söyledi: disk yaşadığı sürece vardır, kullanılmadığında kaybolur.
- Bazı diskler de diğer sanal makinelerle paylaşılabilir; öğrenci bunun salt okunur (read-only) kipte yapıldığını makalede gördüğünü söyledi, hoca onayladı.

### 7.4 Copy-on-write diskler

Öğrencinin dersin başında saydığı copy-on-write disk özelliği, makalenin 4.2.5 bölümünde anlatılır. Ekranda görünen ve öğrencinin işaretlediği kısım şudur (ekrandan, 00:30:00):

> "Disco intercepts every disk request that DMAs data into memory. When a virtual machine requests to read a disk block that is already in main memory, Disco can process the request without going to disk."

Aynı paragrafa göre işleyiş şöyledir:

- Disk isteği makinenin sayfa boyutunun katıysa Disco, DMA isteğini sayfayı sanal makinenin fiziksel belleğine eşleyerek karşılar.
- DMA işleminin anlamını korumak için sayfa, DMA'nın hedef adres sayfasına salt okunur eşlenir.
- Paylaşılan bir sayfayı değiştirme girişimi, VMM'nin kendi içinde işlediği bir copy-on-write hatasıyla sonuçlanır.

Bu mekanizmayla paylaşılan bir diske erişen birden çok sanal makine, sonunda makine belleğini de paylaşır. Copy-on-write anlamı sayesinde sanal makine paylaşımdan habersizdir; tek fark, disk isteklerinin neredeyse anında bitmesidir. Ölçeklenebilirlik için birden çok sanal makinenin çalıştığı bir ortamda hepsi çekirdeği ve uygulama programlarını içeren aynı kök diski paylaşabilir. Diskteki kod ve diğer salt okunur veri, ona ilk erişen sanal makine tarafından belleğe DMA ile getirilir; sonraki istekler veri aktarmadan yalnızca sayfayı eşler. Böylece sistem birden fazla bağımsız işletim sistemi çalıştırsa da tek bir paylaşımlı bellekli çok işlemcili işletim sisteminden beklenen bellek paylaşımı elde edilir (ekrandan, 00:30:00). Sanal makinelerin yalıtımını korumak için disk yazmaları, yazmayı yapan sanal makineye özel tutulur.

Öğrencinin dersin başındaki özetiyle bağlarsak: her seferinde belleğe yeni bir blok kopyalanmaz, bütün sanal makineler aynı bloğu kullanır ve bellek kullanımı azalır; değişiklik olduğunda kopya çıkarılır.

### 7.5 Sanal alt ağ

Öğrenci makalenin haberleşme kısmına geçti: Disco kendi içinde bir sanal alt ağ (virtual subnet) oluşturur. Hoca bu sanal alt ağın ne işe yaradığını sordu.

Öğrencinin cevabı şuydu: sanal makineler bu alt ağ üzerinden birbirleriyle haberleşir. Makalede özellikle belirtilen bir nokta, en büyük aktarım biriminin (Maximum Transfer Unit, MTU) burada aynı sınırla bağlı olmamasıdır. Normalde Ethernet'te MTU aşağı yukarı 1500 bayttır; hoca bunu onayladı. Sanal ağda ise bu sınır yoktur. Makalenin ifadesiyle bu özel ağlar büyük aktarım boyutlarını parçalanma (fragmentation) olmadan taşıyabilir; paketler istenen boyutta tek seferde gönderilebilir.

## 8. Disco'nun gerçekleştirimi

Öğrenci son olarak makalenin "Implementation of Disco" kısmına geldi. Disco çok iş parçacıklı (multi-threaded) bir paylaşımlı bellek programı olarak gerçekleştirilmiştir. NUMA bellek yerleşimine, önbelleğe uygun (cache-aware) veri yapılarına ve işlemciler arası haberleşme örüntülerine özel dikkat gösterilmiştir. <!-- BELİRSİZ: Altyazıda "Cache Average Structures, Intercultural Communication Patterns" geçiyor; büyük olasılıkla "cache-aware data structures" ve "interprocessor communication patterns" kastediliyor. -->

Hoca burada daha önce kendisinin de baktığı bir kısma dikkat çekti: wait-free (beklemesiz) senkronizasyon ya da kilitsiz (lock-free) veri yapıları. <!-- BELİRSİZ: Altyazıda "Waze Pre-Segmentation veya Freelock Data Structural" geçiyor; büyük olasılıkla "wait-free synchronization" ve "lock-free data structures" kastediliyor. --> Hoca bunun çok eski, temel bir makale olduğunu, Disco'nun benzer bir yapıyı kullanarak kendi NUMA'ya uygun veri yapılarını oluşturduğunu söyledi. Makalede klasik veri yapılarını kullanmadıkları, çünkü bunların bu ortamda çöktüğü yazar. Öğrenci bunu, önbelleği düzgün kullanan bir yapı oluşturmak olarak özetledi.

> **Hocanın vurgusu:** Sanallaştırma için oluşturulan bu yapı yaklaşık 13.000 satır koddan oluşur. Makalenin sonuç kısmında belirtilen noktalardan biri de budur.

Öğrenci, makalenin sonucunda birden fazla konuk işletim sistemini destekleyebilmenin de önemli bir kazanç olarak geçtiğini söyledi; hoca onayladı ve bu katmanın optimize edilebilmesinin ya da üzerinde ayar yapılabilmesinin de önemli olduğunu ekledi.

Tartışmanın sonunda hoca, makalenin bazı kısımlarının hızlı okunup atlandığını belirtti ve makalenin daha özlü, dikkatli okunması gerektiğini söyledi: "Sürat felakettir."

> **Ek bilgi (derste anlatılmadı):** Disco'nun tasarım fikri büyük olasılıkla 1960-70'lerdeki IBM VM/370 gibi sanal makine izleyicilerinin, ölçeklenebilir paylaşımlı bellekli çok işlemcilerde yeni işletim sistemi yazmanın zorluğuna karşı yeniden kullanılmasıdır. Büyük olasılıkla bu çalışma, önceki derslerde tartışılan VMware ESX Server gibi ticari sanallaştırma ürünlerinin doğrudan öncülüdür; ESX'teki şeffaf sayfa paylaşımı fikri Disco'nun copy-on-write disk ve bellek paylaşımı yaklaşımıyla akrabadır.

## Örnek Sorular

**Soru 1** (derste sözlü, 00:09:04): Makaleye göre sanal makinelerin çalıştırılması ve yönetilmesiyle ilgili üstesinden gelinmesi gereken zorluklar nelerdir?

Makalenin 3.1 bölümüne göre dört sorun vardır: donanım kaynaklarının sanallaştırılmasından doğan ek yükler (ek istisna işleme, komut yürütme, sanallaştırma için gereken bellek ve her sanal makinede kopyalanan kod, veri ve tampon önbellek), kaynak yönetimi (VMM'nin iyi karar için yeterli bilgisinin olmaması), paylaşım ve haberleşme (bağımsız işletim sistemleri arasında dosya paylaşmanın ve haberleşmenin zorluğu) (ekrandan, 00:15:00).

**Soru 2** (derste sözlü, 00:13:17): Yetkili komutların (privileged instructions) sanal makinedeki işletim sistemine doğrudan verilememesi ne demektir, neden böyledir?

Yetkili komutlar işlemcinin çalışmasını doğrudan etkileyen komutlardır: kesmeleri açma/kapama, işlemciyi sıfırlama, G/Ç portuna erişme. G/Ç portu komutu doğrudan açılırsa bir sanal makinedeki işletim sistemi portun arkasındaki donanımın yapısını değiştirip aynı donanımı kullanan diğer sanal makineleri etkileyebilir. Konuk işletim sistemi bu komutları kullanmak zorunda olduğu için VMM bunları yakalar ve öykünür, donanımı sanallaştırarak paylaşımlı kullanılmasını sağlar.

**Soru 3** (derste sözlü, 00:16:38): Makalede, bir işletim sisteminin boşta döngüsünün ya da kilit için meşgul bekleme kodunun VMM seviyesinde önemli bir hesaptan ayırt edilemeyeceğini söyleyen cümle neden önemlidir?

Matris çarpımı gibi anlamlı bir hesap, kilit için meşgul bekleme ve boşta döngü dışarıdan bakıldığında işlemciyi aynı ölçüde yoğun kullanır. VMM bunları ayırt edemezse CPU'yu boşta dönen ya da kilit bekleyen bir sanal makineye verip anlamlı iş için CPU bekleyen sanal makineyi bekletir. Doğrusu, boş zamanın fark edilip işlemcinin o sanal makineden alınması ve başka birine verilmesidir.

**Soru 4** (derste sözlü, 00:20:33): NUMA ne demektir? CC-NUMA ne demektir?

NUMA, Non-Uniform Memory Access'tir: birden fazla bellek vardır ve işlemcilerin farklı belleklere uzaklığı, dolayısıyla erişim süresi farklıdır. Tekdüze yapıda tek bellek vardır ve bütün işlemcilerin erişim süresi eşittir. CC-NUMA'da işlemcilerin önbellekleri arasında, araya ağ katmanı girmeden donanım seviyesinde tutarlılık vardır (yerleşik açılım: cache-coherent NUMA).

**Soru 5** (derste sözlü, 00:25:02): "Disco uses dynamic page migration and replication to export a nearly uniform memory access time memory architecture to the software" cümlesindeki dinamik sayfa göçü ve kopyalama ne demektir?

> **Çözüm (derste verilmedi):** Büyük olasılıkla makaleye göre Disco, sayfalara erişim sıklığını izleyerek tek bir düğümün yoğun kullandığı sayfayı o düğümün yerel belleğine taşır (göç) ve birden çok düğümün okuduğu sayfanın düğümlerde yerel kopyalarını oluşturur (kopyalama). Konuk işletim sisteminin gördüğü fiziksel adres değişmez, yalnız VMM'nin makine adresi eşlemesi değişir. Böylece erişimler çoğunlukla yerel belleğe düşer ve NUMA bellek, NUMA'dan habersiz işletim sistemine neredeyse tekdüze görünür.

**Soru 6** (derste sözlü, 00:25:18): VM/370 üzerindeki CMS'te sanal diskler paylaşılamıyordu. Disco'da sanal disklerin farklı paylaşım ve kalıcılık modelleriyle yapılandırılabilmesinden ne anlıyoruz?

Bazı diskler geçici (ephemeral) olabilir: sanal makine kapanınca içerik kaydedilmez, disk yalnız yaşadığı sürece vardır. Bazı diskler de diğer sanal makinelerle salt okunur kipte paylaşılabilir.

**Soru 7** (derste sözlü, 00:26:32): Disco'nun oluşturduğu sanal alt ağ ne işe yarar?

Sanal makinelerin kendi aralarında haberleşmesini sağlar. Ethernet'teki yaklaşık 1500 baytlık MTU sınırına bağlı değildir; büyük veriler parçalanmadan tek seferde aktarılabilir.

## Dersin Toparlaması

Bu derste Disco makalesi üzerinden, sanal makine izleyicilerinin hazır işletim sistemlerini ölçeklenebilir, NUMA mimarili çok işlemcili makinelerde çalıştırmak için nasıl kullanılabileceği tartışıldı. Önce sanal makinelerin genel zorlukları görüldü: yetkili komutların ve G/Ç erişiminin öykünülmesinden doğan ek yük, her sanal makinede kopyalanan bellek, VMM'nin boşta döngü ile meşgul beklemeyi gerçek hesaptan ayırt edememesi ve bağımsız sistemler arasında paylaşım ile haberleşmenin zorluğu. Ardından NUMA ve CC-NUMA kavramları açıldı.

Disco bu sorunlara FLASH (MIPS R10000) makinesinde şu çözümleri getirir: sık çekirdek işlemleri için özel adreslere load/store arayüzü, dinamik sayfa göçü ve kopyalamayla neredeyse tekdüze görünen bellek, farklı paylaşım ve kalıcılık modelleri olan sanal diskler, bellekteki blokları salt okunur paylaştıran copy-on-write diskler, MTU sınırı olmayan sanal alt ağ ve NUMA'ya uygun, kilitsiz veri yapılarıyla yazılmış yaklaşık 13.000 satırlık küçük bir izleyici. Makale, önceki derslerde tartışılan ESX Server ve Xen makalelerinin ardından sanallaştırma konusunun bir parçası olarak ele alındı.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
