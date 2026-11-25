# Ders 2 Genişletilmiş Notu: Koruma Halkaları, Süper Sayfalar ve Communicating Sequential Processes Makale Tartışması

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dersin biçimi ve sonraki makalelere giriş
- 2. Donanımda koruma halkaları
- 3. Süper sayfalar için şeffaf işletim sistemi desteği
- 4. Communicating Sequential Processes
- 5. Örnek Sorular
- 6. Dersin Toparlaması

## 1. Dersin biçimi ve sonraki makalelere giriş

Bu ders bir makale tartışması olarak işlendi. Ekran paylaşılmadı; kayıtta yalnızca konuşan kişinin adı görünür, slayt ya da makale sayfası yoktur. Bu yüzden notun tamamı konuşmalardan kurulmuştur. Hoca her makale için önce özünü sordu, sonra öğrencilerin yorumlarını sorularla derinleştirdi ve yanlış ya da eksik cevapları düzeltti. Hoca bazen öğrencileri sınamak için yanıltıcı soru sorabileceğini de belirtti: sorunun kendisi doğru cevabın tersini ima edebilir.

Hoca derse geçmeden sonraki haftanın makalelerini de kısaca tanıttı:

- **Experience with Processes and Monitors in Mesa:** Mesa, akademik ortamda işletim sistemi denemeleri için geliştirilmiş bir sistemdir. Şimdiye kadar okunan makalelerde erişim kontrolü, monitör yapısı ve süreçler arası haberleşme görüldü; bu makalede süreç ve monitör kavramları daha derinlemesine incelenir.
- **DEMOS ve DEMOS/MP makaleleri:** Bir sürecin dağıtık bir yapıda bir sistemden başka bir sisteme nasıl taşınacağı (process migration) tartışılır. Amaç, sürecin kesintiye uğramasını en aza indirmek; arkasındaki temel hedefler yük dengeleme ve hataya dayanıklılıktır (fault tolerance). Hoca, burada tanımlanan kavramların bugün sanal makinelerin bir hypervisor'dan başka bir hypervisor'a aktarılmasında da kullanıldığını vurguladı. DEMOS'ta görevler arası haberleşme makalesi de aynı konunun etrafında döner; çünkü bu, başlangıçta üzerinde çok çalışılmış konulardan biridir.

## 2. Donanımda koruma halkaları

Tartışılan ilk makale "Hardware Architecture for Implementing Protection Rings" idi.

### 2.1 Makalenin özü

Bir öğrencinin özetine göre bilgisayarda hesaplamanın ve bilginin korunması önemlidir ve kullanıcılar ile bilgi arasında bir ayrım bulunmalıdır. Hocanın sorusu ve başka bir öğrencinin cevabıyla özet netleşti: koruma halkaları daha önceki sistemlerde yazılımda gerçekleştirilmişti; bu makale aynı mekanizmanın donanımda, özellikle Multics işletim sistemi için nasıl gerçekleştirileceğini anlatır. Öğrencilerden biri Multics'in zaman paylaşımlı bir ana bilgisayar (mainframe) işletim sistemi olduğunu ve sanal bellek kullandığını da belirtti.

> **Ek bilgi (derste anlatılmadı):** Makale büyük olasılıkla Schroeder ve Saltzer'in 1972 tarihli çalışmasıdır. Multics adı "Multiplexed Information and Computing Service" ifadesinden gelir.

### 2.2 Dört ölçüt

Yazarlar donanım gerçekleştirmesi için bazı temel ölçütler koymuştur. Öğrencilerin sıraladığı ve hocanın onayladığı ölçütler şunlardır:

- **İşlevsel yetenek (functional capability):** Veri erişim mekanizmaları alışılmış ya da alışılmamış her türlü koruma ihtiyacını doğal yoldan karşılamalıdır.
- **Ekonomi:** Mekanizma, gelişmiş ya da basit bütün özellikleri için düşük karmaşıklıkla çalışmalı, fazladan bellek ve işlem zamanı gerektirmemelidir.
- **Basitlik:** Mekanizma anlaşılabilir olmalı, güvenilirlik getirmeli ve sistemde açık yaratmamalıdır.
- **Programlama genelliği:** Mekanizma programlama açısından genel olmalıdır.

Bir öğrenci bu ölçütlerin zaten her sistem için gerekli olduğunu söyleyince hoca şöyle cevap verdi: Mesele ölçütlerin genel geçerliliği değildir. Böyle bir şey ilk kez donanımda gerçekleştiriliyor; makalenin tarihine bakıldığında ne kadar eski olduğu görülür. Gereksinimler (requirements) konmuş, tasarım bunlara göre yapılmıştır. Bugün bunlar alışılagelmiş şeylerdir ama olayın başlangıç noktası budur.

Hoca ekonomi ölçütünü açtırdı. Bir öğrenci bunu fazladan bellek ya da işlem zamanı gerektirmemek diye açıkladı; hoca da şöyle tamamladı: Bu yöntemin ağırlığını hissetmemeliyiz. Yöntem devreye girdiği için yavaşlamamalı ya da alışkanlıklarımızı çok değiştirmemeliyiz; mekanizma bize şeffaf (transparent) olmalıdır.

Bir başka öğrenci makalede bu ölçütlerin hepsinin aynı anda karşılanmasının zor olduğunun belirtildiğini ekledi: basitlik ve programlama genelliğinde kazanç sağlanırken ekonomiden ister istemez ödün verilebilir. Hoca bu tespiti çok iyi buldu. Bir öğrenci de makalede basitliğe özellikle değinildiğini hatırlattı: mekanizmanın anlaşılabilir ve çok karmaşık olmaması gerekir, çünkü karmaşıklık güvenlik açığı doğurabilir.

### 2.3 Halkaların yapısı

Makalede sekiz halka önerilmiştir. Sıfırıncı halka en yüksek yetkiye, yedinci halka en düşük yetkiye sahiptir. Bir öğrencinin belirttiği gibi sekiz sayısı kesin değildir; makaleye göre başka sistemlerde daha fazla halka da olabilir.

Hoca bu yetkinin neyi belirlediğini sordu. Öğrencilerin cevapları şöyle toplandı:

- Halka mekanizması sistem kaynaklarına erişimi kısıtlamak ve güvenliği sağlamak için kullanılır. Süreçler birbirine ait verilere, kullanıcılar da sistem kaynaklarına doğrudan erişmemelidir.
- Bir kullanıcı sistem kaynaklarına erişmek istediğinde daha düşük numaralı, daha yetkili bir halkaya geçmesi gerekir. Bu geçiş halkalar arasında bir yetki aktarımıdır.
- Sistemde okuma, yazma ve yürütme işlemleri vardır. Hangi işlemin bunlardan hangisini yapabileceği halka sistemiyle belirlenir; bazı işlemler yalnızca okuyabilirken bazıları okuyup yazabilir.
- Daha yetkisiz halkadan daha yetkili halkadaki işleve geçiş kapılar (gate) aracılığıyla yapılır. Hoca bunu şöyle özetledi: Yüksek numaralı (yetkisiz) halkalar düşük numaralı (yetkili) halkaları çağırabilir, ama tersi doğrudan mümkün değildir; alttan neyin çağrılabileceği kapılarla belirlenmiştir.

Bir öğrenci halka mekanizmasının bir tür sarmalama (encapsulation) sağlayıp sağlamadığını, nesneye yönelik dillerdeki arayüzlere benzeyip benzemediğini sordu. Hoca bunu da söyleyebileceğimizi kabul etti: her halka üst katmanlara yalnızca açmayı seçtiği şeyi gösterir.

### 2.4 Halkalar çekirdeğin içinde nerede işe yarar?

Hoca şu soruyu sordu: Güvenlik ve koruma açısından bu mekanizma özellikle çekirdeğin (kernel) içinde nerede kullanılabilir, hangi senaryo için uygundur?

Bir öğrenci önce kullanıcıların belleğin her yerine erişmemesi gerektiğini söyledi. Hoca "çekirdeğin içinde" dediğini hatırlattı ve çekirdeğin temel özelliğini sordu. Öğrenci çekirdeğin kullanıcıların donanıma ve kaynaklara doğrudan erişmesini engellediğini ve kaynakları onlara paylaştırdığını söyledi. Hoca çekirdeğin kaynaklara canının istediği gibi erişip erişemeyeceğini sordu; öğrenci en yetkili halkada olduğu için işlemcinin ve donanımın verdiği izinler çerçevesinde erişebileceğini söyledi. Bir başka öğrenci de halkaları dosya sistemi sürücüleri gibi bileşenlerle ilişkilendirdi; hoca bunun cevabın ipucu olduğunu belirtti.

Hocanın cevabı şuydu: Aygıt sürücüleri (bir yazıcının, bir diskin ya da herhangi bir harici cihazın sürücüsü) çekirdeğin içinde olabilir. Ama sürücü farklı bir halkaya yerleştirilirse sürücüdeki bir programlama hatası, bir güvenlik zafiyeti ya da başka bir sorun çekirdeğin tamamını çökertemez, devre dışı bırakamaz.

Modern işletim sistemlerinde uzun yıllar boyunca uygulanan yapı ikili bir seviyedir. Makalede sekiz halkadan söz edilir, ama gerçekleştirme kolaylığı için bu sayı ikiye indirilmiştir: 0 çekirdek, 1 kullanıcı. Bu yüzden çekirdeğin içindeki her şey sıfırıncı halkadadır; hepsinin yetkisi ve yeteneği aynıdır. Birinde oluşan bir hata diğer yerleri de devre dışı bırakabilir.

> **Hocanın vurgusu:** Intel işlemcileri günümüzde de dört halkayı (0, 1, 2, 3) destekler, ama gerçekleştirmedeki zorluklar nedeniyle bugün yalnızca ikisi kullanılır. Bazı özel uygulamalarda, bazı gömülü ve güvenlik açısından kritik (safety critical) sistemlerde bu yapı uygulanır, ama genel kullanımda değildir.

**Soru:** Şu anki donanımlarda dört halka seviyesi var ama işletim sistemleri yalnızca ikisini mi kullanıyor?

**Cevap:** Evet. Hocanın anlatımına göre 1960'larda başlayıp 1970'lerde devam eden çalışmalarla MIT'de hem tek hem çok işlemcili çalışabilecek bir işlemci mimarisi geliştirildi ve bu mimaride donanım seviyesinde halka koruması sekiz seviye olarak gerçekleştirildi. Multics, Unix'in atasıdır: orijinal Unix adı "Multi" yerine "Uni" konarak türetilmiştir (biri "multiplex", diğeri "uniplex" kısaltmasıdır). Intel işlemciyi zamanla sıradan bir ürün (commodity) haline getirdi, ama bunu birden yapmadı (4004, 8008, 8080, 8088, 8086...). O günün entegre devre üretim olanakları düşünüldüğünde sekiz seviye hem ekonomi hem karmaşıklık açısından fazla geldiği için dört seviye seçildi. Multics'teki sekiz seviyeli yaklaşım Unix'te kolaylık için iki seviyeye indirildi: çekirdek seviyesi ve kullanıcı seviyesi (kernel mode/user mode, kernel level/user level gibi farklı adlar aynı şeyi gösterir). Çekirdeği daha güvenli yapmak ve güvenlik zafiyetlerini azaltmak için Intel işlemcideki diğer halkaları da devreye sokan bazı farklı gerçekleştirmeler ve yamalar vardır. Diğer işlemcilerde de halka mekanizması bulunur; halka adı verilmese bile ek bellek koruma özellikleri vardır.

> **Ders sonrası not:** Hoca, Intel işlemcisinin Multics'in geliştirildiği MIT'deki donanımın kopyası olduğunu söyledi (kötü anlamda söylemediğini de ekledi). Büyük olasılıkla daha doğru ifade, x86'nın dört halkalı yapısının Multics'ten esinlendiğidir; Multics'in donanım halkaları Honeywell 6180 gibi ticari makinelerde gerçekleştirilmiştir.

## 3. Süper sayfalar için şeffaf işletim sistemi desteği

İkinci makale "Practical, Transparent Operating System Support for Superpages" idi.

> **Ek bilgi (derste anlatılmadı):** Makale büyük olasılıkla Navarro, Iyer, Druschel ve Cox'un 2002 tarihli çalışmasıdır ve FreeBSD üzerinde gerçekleştirilmiştir.

### 3.1 Motivasyon ve TLB

Bir öğrenci bilgisayar dünyasındaki en büyük zorluğun işi daha az zaman ve alanla verimli yapmak olduğunu söyleyerek başladı. Hoca soruyu daraltıp süper sayfaların neden gerektiğini sordu. Cevaplar: TLB ıskalarını (TLB miss) azaltmak; daha ayrıntılı olarak, bellek boyutları hızla artarken TLB'lerin bu belleği kapsayamayacak kadar küçük kalması.

Hoca TLB'nin ne işe yaradığını sordu. Bir öğrenci TLB'nin önbelleğe nasıl gidileceğini söylediğini öne sürdü; hoca bunun yanlış olduğunu belirtip makaleye yeniden bakmasını önerdi. Doğru cevap diğer öğrencilerden geldi: Sanal ve fiziksel adresler arasında bir dönüşüm tablosu (sayfa tablosu) vardır. Bu tablo büyüktür ve her erişimde ona gitmek maliyetlidir. TLB (Translation Lookaside Buffer), sayfa tablosunu önbelleğe alan küçük bir tablodur; böylece çoğu erişimde sayfa tablosuna gitmeden doğrudan belleğe gidilebilir.

### 3.2 Sayfa tablosu nasıl büyür?

Bir öğrenci adres dönüşüm tablosunun bellekle birlikte üstel büyüdüğünü söyledi. Hoca bunu düşünmesini istedi ve soruyu başka bir öğrenciye de yöneltti. Sonuç: Sayfa boyutu sabitken bellek büyüdükçe tablodaki girdi sayısı doğrusal (lineer) artar, üstel değil. Bir öğrencinin eklediği gibi tablo üstel büyüseydi bir noktadan sonra tablo belleğin kendisinden büyük olurdu.

Hoca asıl sorunu şöyle bağladı: Bellek çok büyür ama sayfa boyutu aynı kalırsa sayfa tablosundaki girdi sayısı çok artar. Bu durumda belleğin büyük bir kısmı sayfa dönüşüm tablosu için kullanılır; hatta tablonun tamamı belleğe sığmayabilir. Bitişiklik (contiguity) sorunu da buradadır, çünkü sayfa dönüşüm tablosu bellekte fiziksel olarak arka arkaya gelen adreslerde olmak zorundadır. Daha büyük sayfalar kullanılırsa tutulacak girdi sayısı azalır.

> **Ders sonrası not:** Sayfa tablosunun fiziksel olarak bitişik olma zorunluluğu tek seviyeli doğrusal bir tablo için geçerlidir. Büyük olasılıkla çok seviyeli sayfa tablolarında her seviye ayrı sayfalara dağılabilir; tablo yine de büyük yer kaplar.

### 3.3 Süper sayfa nedir?

Süper sayfa, normal sayfa boyutundan (taban sayfa, base page) büyük sayfadır. Hoca makalenin yazıldığı dönemde süper sayfanın ne kadarlık bir boyutu ifade ettiğini sordu ve makaledeki şu bilgiyi okudu:

| İşlemci | Taban sayfa | Süper sayfa boyutları |
|---|---|---|
| Alpha | 8 KB | 64 KB, 512 KB, 4 MB |
| i386 ailesi | 4 KB | 4 MB |
| Itanium | 4 KB'tan 256 MB'a kadar on farklı sayfa boyutu | |

Konuşma sırasında bir öğrencinin "4 kilobayt" dediği ses bağlantısında "gigabayt" gibi duyuldu; hoca makalede gigabayt boyutunda bir sayfa olmadığını belirterek düzeltti.

### 3.4 Süper sayfa kısıtları

Hoca makalede süper sayfalar için konan kısıtları sordu ve bunların makalede açıkça yazdığını vurguladı. Bir öğrencinin cevabı ve hocanın açıklamalarıyla kısıtlar şunlardır:

- **Desteklenen boyut:** Süper sayfanın boyutu işlemci (TLB) tarafından desteklenmelidir.
- **Bitişiklik:** Süper sayfadaki adresler hem sanal bellekte hem fiziksel bellekte bitişik (contiguous) olmalıdır.
- **Hizalama:** Süper sayfanın başlangıç adresi hem sanal hem fiziksel bellekte süper sayfa boyutunun tam katı olmalıdır. Hoca burada bir düzeltme yaptı: fiziksel adres ile sanal adres aynı olmak zorunda değildir, ikisinin de boyutun tam katı olması yeterlidir. Süper sayfa 64 KB ise başlangıç adresi 64 KB'ın, 256 MB ise 256 MB'ın tam katı olmalıdır.
- **Tek TLB girdisi:** TLB'de süper sayfa için tek bir girdi vardır; bu girdide tek bir referans biti, tek bir kirli (dirty) bit ve tek bir koruma özniteliği bulunur.

Hoca hizalama kısıtının neyi sağladığını açıkladı: Bu kısıt adreslemeyi kolaylaştırır ve donanım karmaşıklığını azaltır. Sanal adresten fiziksel adrese geçerken "şu kadar biti al, yerine şu kadar biti koy" denir; bu basit AND/OR maskeleme ya da kaydırma (shift) işlemleriyle yapılır.

> **Ek bilgi (derste anlatılmadı):** Boyutu $2^k$ bayt olan hizalı bir süper sayfada adresin alt $k$ biti sayfa içi uzaklıktır. Dönüşüm için üst bitler TLB'den gelen fiziksel çerçeve adresiyle değiştirilir, alt bitler olduğu gibi kalır; bu yüzden maske ve birleştirme yeterlidir.

Tek TLB girdisinin sonucu çözünürlüktür (granülarite). Süper sayfa kullanılmazken koruma bilgisi ve "kullanıldı mı" bilgisi 4 KB çözünürlükle tutulur. Süper sayfa kullanıldığında bu bilgiler süper sayfanın tamamı için tutulur: süper sayfa 64 KB ise çözünürlük 64 KB, 256 MB ise 256 MB olur. Ayrı 4 KB'lık girdiler yoktur, bölge tek parça halinde tutulur.

### 3.5 Promotion, demotion ve eviction

Bir öğrenci makaledeki ödünleşimlerden (trade-off) söz etmek istedi: ayırma (allocation) sürecinin düzenlenmesi, parçalanmanın denetlenmesi ve işletim sisteminin bunlardaki rolü. Hoca üç kavramı ayrı ayrı açıklatmak istedi ve önce sözcük anlamlarını verdi: promotion terfi ettirmek, demotion verilen terfiyi geri almak, eviction boşaltmaktır.

**Promotion.** Taban sayfaları bir araya getirip süper sayfa yapmaktır. Bu bir blok halinde ya da artımlı (incremental) yapılabilir. Makalede ayırmanın kısmi olarak yapılabileceği ve rezervasyonla desteklenebileceği de anlatılır. Hocanın açıklamasına göre artımlı promotion şöyle işler: Bir süper sayfa boyutuna ulaşıldıktan sonra arkasında bitişik taban sayfalardan oluşan alan dolmaya devam ederse, bölge desteklenen bir sonraki süper sayfa boyutuna yükseltilir. Hocanın örneğinde taban sayfalar birikmeye devam edip 128 olunca bölge artık 64'lük değil 128'lik bir süper sayfa olarak görülür.

<!-- BELİRSİZ: Hocanın 64 ve 128 örneğinde birimin taban sayfa sayısı mı yoksa KB mı olduğu altyazıdan net değil; bu yüzden birimsiz bırakıldı. -->

**Demotion.** Süper sayfanın yeniden daha küçük süper sayfalara ya da taban sayfalara bölünmesidir. Hoca neden bölmek isteyeceğimizi sordu. Bir öğrenci parçalanma (fragmentation) dedi, başka biri bellek parçalanması dedi; hoca hangi parçalanma olduğunu sordu ve cevabı verdi: iç parçalanma (internal fragmentation).

Gerekçe şudur: Süper sayfalar normal sayfalara göre çok büyüktür. Normal sayfalamada en kötü durumda $n$ sayfa tam kullanılmış, $(n+1)$'inci sayfanın yalnızca 1 baytı kullanılmıştır; sistem açısından yine $n+1$ sayfa ayrılmıştır ve son sayfanın neredeyse tamamı boşa gider. Bu son sayfa bir süper sayfa ise boşa giden alan çok büyür:

$$256\ \text{MB} - 1\ \text{bayt} = 268\,435\,455\ \text{bayt} \approx 256\ \text{MB}$$

Bu durumda süper sayfanın daha küçük bir süper sayfaya ya da taban sayfalara demote edilmesi, iç parçalanmadan doğan kullanılamaz alanın kullanılabilir hale getirilmesi gerekir. Hocanın örneği: 256 MB'lık bir süper sayfanın 128 MB'tan 1 bayt eksiği doluysa öbür 128 MB'ın orada boş durmasına gerek yoktur. Sayfa iki tane 128 MB'lık süper sayfaya bölünebilir ya da taban sayfalara ayrılabilir. Sistem bunu zaman içinde dinamik olarak yönetmelidir.

**Eviction.** Bir öğrenci eviction'ı bellek baskı altındayken süper sayfaların taban sayfalara dönüştürülmesi olarak tanımladı; hoca burada taban sayfalara dönüştürmekten söz edilip edilmediğini sordu. Doğru cevap: eviction, bellekte yer kalmadığında sayfaların ikincil belleğe (secondary storage) taşınması ve gerektiğinde geri getirilmesidir. Hocaya göre eviction standart bir yöntemdir; normal sayfalarla yapılan eviction'dan farkı yoktur. Bir öğrencinin makalenin demotion'ı az açıkladığı yönündeki gözlemine de bu çerçevede değinildi.

Bir öğrencinin eklediği ve hocanın onayladığı bir nokta: Bu yönetim donanıma mümkün olduğunca yakın yapılmalıdır, çünkü bu işlemler saniyede binlerce kez gerçekleşir. Yönetim proaktif de olmalıdır; bellek dolduktan sonra yer açmaya başlamak her şey için çok geç olabilir.

### 3.6 TLB neden küçük?

**Soru:** Makalede TLB'nin 128 girdi olduğu yazıyor. TLB donanım maliyeti çok yüksek olduğu için mi küçük tutuluyor, neden artırılmıyor?

**Cevap:** TLB yazmaç yapısından bile pahalıya gelen bir yapıdır. TLB'de kaç girdi varsa hepsi kendisine gelen değeri tek saat çevriminde kontrol eder ve var ya da yok sonucunu döndürür. Bu çok özel bir önbellek mimarisidir: sıralı erişime hiç tolerans yoktur, bütün elemanlara eşzamanlı erişilir, hepsi karşılaştırmayı aynı anda yapar ve eşleşen girdinin sonucu dışarı verilir. Bunun işlemcinin çalışma frekansında gerçekleşmesi gerekir. Bu yüzden TLB'yi çok büyütmek kolay değildir. Günümüzdeki TLB boyutları 64 girdiden çok daha artmıştır, ama on binlerce girdi düşünülmemelidir.

### 3.7 Population map

Hoca makalede tanımlanan population map'in ne olduğunu sordu. Bir öğrencinin cevabı: population map, her bellek nesnesinde ayrılmış taban sayfaları izler. Hoca bunları neden izlediğimizi sordu. Cevaplar ve hocanın tamamlamasıyla kullanım amaçları:

- **Promotion ve demotion kararları:** Sayfalar ayrıldıkça promotion, boşaldıkça demotion kararı alınabilir.
- **Rezerve çerçeveyi bulma:** Sayfa hatası oluştuğunda işletim sistemi bu harita yardımıyla sayfanın sanal adresine denk gelen rezerve edilmiş çerçeveyi sağlar. Böylece zaten yer ayrılmış bir sayfa için yeniden alan ayırmaya çalışmaz; bir adrese eşleme yapıldıysa aynı adrese yeniden eşleme yapılmaz.
- **Çakışmayı önleme:** Sayfalar üzerinden süreçler bir şeyleri ortak kullanabilir, yani paylaşım (sharing) açılabilir. Ama paylaşım açılmadığı sürece eşlemeler üst üste binmemelidir (overlap olmamalıdır); harita bunun takibini sağlar.
- Bir öğrencinin eklediği gibi harita, sayfaların genişletilmesi ve rezervasyon kararlarının belirlenmesine de yardım eder.

### 3.8 Deneyler neden Alpha üzerinde yapıldı?

Hoca makalede deneylerin Alpha işlemcisi üzerinde yapılmasının nedenini açıkladı. Alpha, 8 KB taban sayfanın yanında üç farklı süper sayfa boyutu (64 KB, 512 KB, 4 MB) destekler. i386 ise yalnızca 4 KB ya da 4 MB destekler; ikili bir seçenek olduğu için çözünürlük düşüktür. Itanium 4 KB'tan 256 MB'a kadar çok sayıda boyut destekler, ama makalenin yazıldığı dönemde kullanımı yaygın değildi; hiçbir zaman yeterince popüler olmadı ve artık üretilmiyor. Alpha daha yaygın bir mimari olduğu ve farklı senaryoları denemeye elverdiği için deneyler onun üzerinde yapıldı.

## 4. Communicating Sequential Processes

Üçüncü makale Hoare'un "Communicating Sequential Processes" (CSP) makalesiydi.

### 4.1 Makalenin özü

Öğrenci yorumları önce programlama dillerinin genelde ardışık (sequential) programlamayı desteklediği, makalenin ise aynı anda birden fazla süreci ele aldığı noktasından başladı. Bir öğrenci monitörlerden söz edince hoca şu anda monitörleri değil CSP makalesini tartıştıklarını hatırlattı ve makalenin özünü sordu. Bir başka öğrenci makalenin eşzamanlı sistemler için bir yöntem ya da kavram ortaya koyduğunu söyledi. Hoca makaleden önce eşzamanlı ya da çok işlemcili sistemler olmadığından emin olup olmadığını sordu ve yazarın makalenin başında önceki önerileri saydığını hatırlattı: Fortran'da alt programlar, Algol 60'ta prosedürler, PL/I'da girişler (entries), Unix'te eş yordamlar (coroutines), Simula 67'de sınıflar, Concurrent Pascal'da süreçler ve monitörler, CLU'da kümeler (clusters).

Bir öğrenci makalenin ardışık süreçler arasındaki iletişimi sağlamak için temel giriş ve çıkış işlemlerini temel adım olarak alan bir mekanizma önerdiğini, bu yöntemin Dijkstra'nın korumalı komutlarıyla (guarded commands) birlikte çok yönlü hale geldiğini söyledi.

Hoca daha kritik bir noktaya dikkat çekti. Makaleye göre çok işlemcili sistemler yaygınlaşacak ve tek işlemcili sistemlerden daha güçlü hale gelecektir. Hoca makaleden şu cümleleri okudu: böyle bir makine, tek işlemcili görünen bir makineden "more powerful, capacious, reliable and economical" (daha güçlü, kapasiteli, güvenilir ve ekonomik) olabilir; "In order to use such a machine effectively on a single task, the component processors must be able to communicate and synchronize with each other." Yani böyle bir makineyi tek bir işte etkin kullanmak için bileşen işlemcilerin birbiriyle haberleşebilmesi ve eşzamanlanabilmesi gerekir.

Hoare'un kurmaya çalıştığı şey, altyapı birden fazla işlemciden oluşsa bile kullanıcı seviyesinden bakıldığında tek bir işlemci, tek bir sistem kullanılıyormuş gibi bütünleşik bir yapının görülmesidir; amaç işi programcı açısından kolaylaştırmaktır. Bugüne kadar birçok yöntem ortaya atılmıştır, ama herkes olaya farklı bir taraftan bakar. Hoare ise konuyu programlama tekniği açısından ele alır; arka tarafta neler yapılması ve nelere dikkat edilmesi gerektiğini ortaya koyar.

> **Hocanın vurgusu:** Makalenin kritikliği buradadır. Bu makalede ortaya konan fikirler hâlâ kullanılıyor; sonradan geliştirilen yapılar bunların üzerine kuruludur.

### 4.2 Dijkstra'nın korumalı komutları ve nondeterminizm

Hoca Hoare'un özellikle kimin çalışmasından yararlandığını sordu. Cevap: Dijkstra'nın korumalı komutlar (guarded commands) çalışması; Hoare bu altyapının üzerine eklemeler yapar. Hoca bu yapıyla temelde neyin sağlanmaya çalışıldığını ve buradaki tek temel kelimeyi sordu. "Input/output", "guarded command" gibi cevapları kabul etmedi; aranan kelime sonunda bulundu: **nondeterminizm** (nondeterminism).

Hocanın açıklaması: Dijkstra'nın kontrol yapıları kullanılmadan süreçler kendi haline bırakılırsa nondeterministik bir çalışma oluşur. İşletim sistemlerinde bunu tarif eden terim yarış durumudur (race condition): elde edilecek sonucun ne olacağı bilinmez. Hocanın benzetmesi: Yarışta hile yoksa yarışı kimin kazanacağı belli değildir; aynı yarışı aynı yarışçılarla üç kez koşturursanız üçü de farklı biçimde sonlanabilir. Biz ise çalıştırdığımız işlerden belirli sonuçlar istiyoruz: iş tek işlemcide ya da $n$ işlemcide çalışsın, parçaları farklı işlemcilerde ya da aynı işlemcide olsun, sonuç aynı olmalıdır. Yani bir determinizm istiyoruz. Hocaya göre Hoare'un Dijkstra'nın korumalı komutlarından ve onlarla kurulan yapılardan yararlanmak istemesinin sebebi bu nondeterministik durumu ortadan kaldırmaktır.

> **Ders sonrası not:** Hoca, korumalı komutların nondeterminizmi ortadan kaldırmak için kullanıldığını söyledi. Büyük olasılıkla CSP'de korumalı komutlar nondeterminizmi tamamen kaldırmaz; onu programda açıkça ifade eden ve denetleyen araçtır. Birden fazla korumanın doğru olduğu bir seçim komutunda hangi dalın çalışacağı belirlenmemiştir; programcının amacı, hangi dal seçilirse seçilsin doğru sonuca ulaşan bir program yazmaktır.

### 4.3 Haberleşmede kritik olan: girdi

Hoca makalede yedi madde bulunduğunu hatırlattı ve maddelerin üzerinden geçti: üçüncü madde hem girdi hem çıktıdan, dördüncü, beşinci, altıncı ve yedinci maddeler ise girdiden (input) söz eder. Öyleyse bu haberleşmede özellikle ele alınması gereken şey nedir?

Bir öğrencinin cevabı: Makalede genel olarak bir işlemin çıktısının başka bir işlemin girdisi olduğuna değinilmiş ve bütün kavram bunun üzerine kurulmuştur. Hoca şöyle tamamladı: Aslında çıktı göndermek büyük bir sorun değildir; sorun o çıktıyı alıp işlemektir. Öğrenci de zamanlamanın zor olduğunu ekledi: bir sürecin çıktı vermesini beklemek bir iştir; ikinci süreç bunu girdi olarak kabul edeceği için onu bekletmek gerekebilir ve bunu yönetmek ayrı bir sorundur.

> **Ek bilgi (derste anlatılmadı):** Makaledeki yedi madde büyük olasılıkla şunlardır: korumalı komutların ardışık kontrol yapısı olarak kullanılması, paralel komut, basit girdi ve çıktı komutları, girdi ve çıktının süreç adları eşleştiğinde birlikte gerçekleşmesi (beklemeli, tamponsuz haberleşme), girdi komutlarının korumalarda yer alabilmesi, tekrarlama komutunun bütün kaynak süreçler sonlandığında bitmesi ve basit desen eşleme.

### 4.4 Makaledeki yapılar ve örnekler

Hoca Hoare'un önerdiği yapıları sordu. Öğrenci yorumlarından ve hocanın açıklamalarından şunlar çıktı:

- Girdi ve çıktı komutları: bir süreç başka bir sürece değer gönderir, diğer süreç bu değeri alır.
- Hoca makaledeki bir dönüşüm örneğini açıkladı: süreç girdiyi başka bir şeye dönüştürür; ardışık iki yıldız (`**`) görürse bunların yerine bir yukarı ok (↑) koyar.
- Bir öğrenciye göre makalede üç temel yapı vardır: tekrarlama yapısı (örneğin `while` döngüsü), seçim yapısı (koşullu) ve ardışık birleştirme. Geleneksel sayısal bilgisayar tek bir ardışık programın belirlenimli yürütülmesi için tasarlanmıştır; bileşen işlemcilerin haberleşip eşzamanlanması bu yüzden yeni bir sorundur.
- Bir başka öğrencinin belirttiği gibi yazar, işletim sistemleri dersinden bilinen sınırlı tampon (bounded buffer), tamsayı semaforu ve yemek yiyen filozoflar problemleri için sözde kod çözümleri de paylaşmıştır. Yemek yiyen filozoflar için düşünme, çatal alma ve yeme kısımları yazılmıştır. Makalenin tartışma bölümünde bu ilkel yapılarla çözümlerin giderek zorlaşacağı da belirtilir.

<!-- BELİRSİZ: Öğrencilerin bu bölümdeki bazı İngilizce açıklamaları altyazıda büyük ölçüde bozuk; yalnız anlaşılabilen kısımlar alındı. -->

Ders sırasında CSP makalesinin yaklaşık yarısı tartışıldı. Monitörlerin gerçekleştirilmesi ve farklı senaryoları üzerine olan, yine Hoare'a ait dördüncü makale tartışılmadı.

## 5. Örnek Sorular

Bu derste ekranda soru gösterilmedi. Aşağıdaki sorular hocanın derste sözlü sorduğu sorulardır.

**Soru 1** (derste sözlü, 00:17:19): Koruma halkalarının donanımda gerçekleştirilmesi için yazarların koyduğu temel ölçütler nelerdir?

> **Cevap (derste verildi):** İşlevsel yetenek, ekonomi, basitlik ve programlama genelliği. Bunların hepsi aynı anda tam karşılanamaz; örneğin yetenek ve genellik artırılırken ekonomiden ödün verilebilir.

**Soru 2** (derste sözlü, 00:26:18): Halkalarda 0 en yetkili, 7 en yetkisiz. Bu yetki neyi belirler, neden vardır?

> **Cevap (derste verildi):** Sistem kaynaklarına ve belleğe erişimi, okuma/yazma/yürütme yetkilerini belirler. Süreçlerin birbirinin verisine ve kullanıcıların kaynaklara doğrudan erişmesini engeller. Daha yetkili halkaya geçiş kapılar üzerinden yapılır.

**Soru 3** (derste sözlü, 00:31:23): Halka mekanizması güvenlik ve koruma için çekirdeğin içinde özellikle nerede kullanılabilir?

> **Cevap (derste verildi):** Aygıt sürücüleri çekirdekten farklı bir halkaya konabilir. Böylece sürücüdeki bir hata ya da güvenlik açığı çekirdeğin tamamını çökertemez.

**Soru 4** (derste sözlü, 00:58:38): Süper sayfaların arkasındaki motivasyon nedir? TLB ne işe yarar?

> **Cevap (derste verildi):** Bellek boyutları hızla büyürken TLB küçük kaldığı için TLB ıskaları artar. TLB, sanal-fiziksel adres dönüşümü yapan sayfa tablosunun önbelleğidir.

**Soru 5** (derste sözlü, 01:01:53): Sayfa tablosu bellek boyutuyla üstel mi büyür?

> **Cevap (derste verildi):** Hayır. Sayfa boyutu sabitken girdi sayısı bellekle doğrusal büyür. Üstel büyüseydi tablo bir noktadan sonra belleğin kendisinden büyük olurdu.

**Soru 6** (derste sözlü, 01:06:14): Makaleye göre süper sayfalar hangi kısıtları sağlamalıdır? Hizalama kısıtı neyi sağlar?

> **Cevap (derste verildi):** Boyut TLB tarafından desteklenmeli; sayfa sanal ve fiziksel bellekte bitişik olmalı; başlangıç adresi her iki bellekte de boyutun tam katı olmalı; TLB'de tek girdi olduğundan tek referans biti, tek kirli bit ve tek koruma özniteliği vardır. Hizalama sayesinde adres dönüşümü basit maskeleme ve kaydırma ile yapılır.

**Soru 7** (derste sözlü, 01:11:42 ve 01:15:06): Promotion, demotion ve eviction ne demektir? Süper sayfayı neden bölmek isteriz?

> **Cevap (derste verildi):** Promotion taban sayfaları süper sayfada birleştirmek, demotion süper sayfayı küçük parçalara bölmek, eviction sayfaları ikincil belleğe taşımaktır. Süper sayfa iç parçalanma nedeniyle bölünür: en kötü durumda 256 MB'lık bir süper sayfanın 1 baytı kullanılır ve 256 MB − 1 bayt boşa gider.

**Soru 8** (derste sözlü, 01:20:01): TLB neden 128 girdi gibi küçük tutuluyor?

> **Cevap (derste verildi):** Bütün girdiler gelen adresi işlemci frekansında, tek saat çevriminde ve eşzamanlı olarak karşılaştırır. Bu yapı yazmaçtan bile pahalıdır; bu yüzden TLB çok büyütülemez.

**Soru 9** (derste sözlü, 01:22:35): Population map nedir, ayrılmış taban sayfaları neden izleriz?

> **Cevap (derste verildi):** Her bellek nesnesinde ayrılmış taban sayfaları izler. Promotion ve demotion kararları için, sayfa hatasında rezerve çerçeveyi bulup aynı yer için yeniden ayırma yapmamak için ve paylaşım açılmadıkça eşlemelerin çakışmasını önlemek için kullanılır.

**Soru 10** (derste sözlü, 01:43:46): Hoare, Dijkstra'nın korumalı komutlarıyla temelde neyi ele almaya çalışır?

> **Cevap (derste verildi):** Nondeterminizmi. Kendi haline bırakılan süreçler yarış durumuna yol açar; sonuçların tek ya da çok işlemcide aynı olması istenir.

**Soru 11** (derste sözlü, 01:48:28): Makaledeki yedi maddeden çoğu girdiden söz ediyorsa bu haberleşmede özellikle ele alınması gereken şey nedir?

> **Cevap (derste verildi):** Girdi, yani bir sürecin çıktısını alıp işlemek. Çıktı göndermek büyük sorun değildir; girdiyi alacak sürecin bekletilmesi ve zamanlamanın yönetilmesi zordur.

## Dersin Toparlaması

Bu derste işletim sistemlerinin üç temel konusu tarihî makaleler üzerinden tartışıldı. Koruma halkaları makalesi, erişim denetiminin donanımda nasıl gerçekleştirilebileceğini ve bunun için konan dört ölçütü gösterdi; bu sekiz seviyeli yapının Unix'te ve günümüz sistemlerinde neden iki seviyeye indiği, aygıt sürücülerini ayrı bir halkada çalıştırmanın çekirdeğe sağlayacağı yalıtım üzerinden konuşuldu. Süper sayfalar makalesi, büyüyen bellek ile küçük kalan TLB arasındaki uyumsuzluğu, süper sayfaların kısıtlarını ve promotion, demotion, eviction ile population map aracılığıyla bunların dinamik olarak nasıl yönetildiğini ele aldı.

CSP makalesinde ise çok işlemcili sistemlerde süreçlerin haberleşmesi ve eşzamanlanması, Dijkstra'nın korumalı komutları, nondeterminizm ve yarış durumu ile girdi komutlarının önemi tartışıldı. Hocanın vurguladığı ortak fikir, 1960-70'lerde ortaya konan bu kavramların bugün de kullanıldığı ve yeni görünen birçok yapının aslında bu eski fikirlerin üzerine kurulduğudur. Sonraki makaleler monitörlerin gerçekleştirilmesi (Hoare ve Mesa) ile DEMOS'ta görevler arası haberleşme ve süreç göçü üzerinedir.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
