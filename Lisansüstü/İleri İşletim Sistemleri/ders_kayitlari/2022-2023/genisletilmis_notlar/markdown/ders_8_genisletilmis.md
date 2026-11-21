# Ders 8 Genişletilmiş Notu: VMware ESX Server'da Bellek Kaynak Yönetimi

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

Bu derste ekran paylaşımı yapılmadı; anlatım tamamen sözlüydü. Öğrencilerin önceden okuduğu "Memory Resource Management in VMware ESX Server" makalesi soru-cevap biçiminde tartışıldı. Bir öğrenci makaleyi anlatmaya başladı, hoca sık sık araya girip sorular sordu ve cevapları adım adım doğru noktaya taşıdı. Makaleden yapılan alıntılar ve sayılar, hocanın makaleden sesli okuduğu kısımlardır.

> **Ek bilgi (derste anlatılmadı):** Derste adı söylenen makale büyük olasılıkla Carl A. Waldspurger'ın "Memory Resource Management in VMware ESX Server" çalışmasıdır (OSDI 2002). Makalenin başlıca bölümleri balonlama, içerik tabanlı sayfa paylaşımı, boşta bellek vergisi ve sıcak G/Ç sayfası yeniden eşlemesidir (hot I/O page remapping).

## İçindekiler

- 1. Makaleye giriş ve sanallaştırma kavramı
- 2. JVM tipi sanallaştırma ile ESX tipi sanallaştırma
- 3. Sanallaştırma türleri ve hosted mimari
- 4. Sanal, fiziksel ve makine adresi
- 5. Balonlama (ballooning)
- 6. Şeffaf sayfa paylaşımı
- 7. İçerik tabanlı sayfa paylaşımı ve copy-on-write
- 8. Güvenli özet ile hızlı özet
- 9. Sayfa paylaşımının başarımı
- 10. Boşta bellek vergisi
- Örnek Sorular

## 1. Makaleye giriş ve sanallaştırma kavramı

Sunumu yapan öğrenci makalenin özetinden başladı. Özette VMware ESX Server'ın donanımı çoğullayan (multiplex eden) ince bir yazılım katmanı olduğu söylenir. Makale ileride balonlama tekniğinden, boşta bellek vergisinden (idle tax), içerik tabanlı sayfa paylaşımından ve sıcak G/Ç sayfalarının yeniden eşlenmesinden (hot I/O page remapping) bahseder. Genel konu sanallaştırmadır. Öğrenci, makaleye girmeden önce sanallaştırmanın kendisini anlatmak gerektiğini düşündü.

## 2. JVM tipi sanallaştırma ile ESX tipi sanallaştırma

### 2.1 Öğrencinin örneği: Java Virtual Machine

Öğrencinin aklına gelen ilk sanallaştırma örneği Java Virtual Machine (JVM) oldu. ARM üzerinde çalışacak bir kod yazıyorsanız ARM komutlarına, Intel'de Intel komutlarına, PowerPC'de PowerPC komutlarına göre yazmanız gerekir. Aynı kodu üç mimaride çalıştırmak istiyorsanız üç ayrı komut kümesi için uğraşmanız gerekir. JVM araya girer ve "en sondaki komutları ben çıkarırım, sen karışma" der. Bu bir soyutlamadır: JVM, CPU kavramını sanallaştırır.

Hoca bu açıklamayı tamamladı. Java kodu aslında bir "Java CPU'su" üzerinde çalışır. Bu sanal işlemcinin move, add, increment, decrement, compare gibi genel komutları vardır. Bu komutların Intel'deki, PowerPC'deki ve ARM'daki karşılıkları farklıdır. JVM, sanal işlemcinin komutunu alttaki gerçek donanımın işlemcisinde denk düşen komuta dönüştürür. Böylece yazılmış kod farklı bir işlemci mimarisine taşındığında değişiklik gerekmez.

Hoca bunu C ile karşılaştırdı. C'de yazılmış bir kod "taşınabilir" diye anılır, ama taşınabilmesi için hedef donanım neyse ona göre yeniden derlenmesi gerekir: Intel için ayrı, ARM için ayrı, PowerPC için ayrı. Duruma göre kodda değişiklik bile gerekebilir. Java ise bunu arada ortadan kaldırır, çünkü tanımlanmış bir Java işlemcisi vardır; bu işlemci varmış gibi gösterilir ama alttaki gerçek işlemciden yararlanılır.

### 2.2 ESX Server'daki sanallaştırma bunun gibi mi?

Hoca öğrencilere şunu sordu: ESX Server'daki işlemci sanallaştırması da bu şekilde mi gerçekleşiyor? Öğrenci soruyu sürekli belleğe taşıyınca hoca, ESX'in hem CPU, hem bellek, hem de çevre birimi (G/Ç aygıtı) sanallaştırması yaptığını, ama sorunun yalnız CPU tarafıyla ilgili olduğunu hatırlattı.

Başka bir öğrenci, sanallaştırmayı birden fazla makinenin donanımı ortaklaşa kullanması olarak anladığını söyledi: hangi uygulamanın CPU'ya ihtiyacı varsa ona verilir, sonra geri alınır. Hoca bunun kavramsal olarak doğru olduğunu söyledi ve şöyle bağladı:

- ESX Server'daki sanallaştırma bir donanımın sanal kopyalarını oluşturmaktır. İşlemci mimarisinde bir değişiklik yapmaz.
- Alt tarafta Intel varsa, üzerinde çalıştıracağınız her işletim sistemi Intel mimarisi için yazılmış olmalıdır. ARM varsa ARM için, PowerPC varsa PowerPC için. ARM için yazılmış bir işletim sistemini Intel üzerinde bu yolla çalıştıramazsınız.
- Bu sanallaştırma, alttaki işlemci mimarisi ile üstte çalışacak işletim sistemlerinin hedef mimarisinin aynı olmasını gerektirir.

> **Hocanın vurgusu:** JVM de ESX de sanallaştırmadır, ama iki farklı kategori sanallaştırmadır. Tek bir tip sanallaştırma yoktur; bunu unutmamak lazım.

ESX tipi sanallaştırmanın amacı, aynı bilgisayar sistemi üzerinde birden fazla işletim sisteminin birbirinden habersiz çalışmasıdır. Her biri donanımı tek başına sahiplenmiş, o donanım üzerinde yalnız kendisi çalışıyormuş gibi bir algıya sahip olmalıdır.

### 2.3 Bu ortamda bellek yönetimi

Bir işletim sistemi doğal olarak belleği yönetmekle yükümlüdür, ama belleği prosesler arasında yönetir: 1 GB, 2 GB ya da 10 GB'lık ortak bir bellek ihtiyaca göre proseslere paylaştırılır. Sanallaştırmada bir adım öteye geçilir. Hoca proseslerin her birini bir işletim sistemi gibi düşünmeyi önerdi, sonra "gibi"yi kaldırdı: bunlar gerçekten birer işletim sistemidir. O zaman yalnız bellek değil, CPU ve çevre birimleri (disk erişimi, ağ erişimi ve diğerleri) açısından da her biri yalıtılmalı, her biri donanıma yalnız kendisi sahipmiş gibi görmeli ve buna inanmalıdır. Makale 2002 tarihlidir ve o tarihe kadarki çalışmaların, deneyimlerin özetidir.

## 3. Sanallaştırma türleri ve hosted mimari

### 3.1 Üç sanallaştırma türü

Hoca üç sanallaştırma türü saydı: tam sanallaştırma (full virtualization), para-sanallaştırma (paravirtualization) ve işletim sistemi seviyesinde sanallaştırma (OS-level virtualization). Bunların Type 1, Type 2 gibi adlarla da geçtiğini söyledi.

> **Ders sonrası not:** Hoca Type 1 ve Type 2 için "birinde tam sanallaştırma, diğerinde OS seviyesi sanallaştırma var diye düşünebilirsiniz" dedi. Yaygın sınıflandırmada Type 1 ve Type 2, büyük olasılıkla hipervizörün yerine göre yapılır: Type 1 hipervizör doğrudan donanım üzerinde çalışır (ESX Server gibi), Type 2 hipervizör bir ana işletim sisteminin üzerinde çalışır (VMware Workstation gibi). OS seviyesi sanallaştırma (container) ise bu iki tipten ayrı bir kategori olarak anılır.

### 3.2 VMware Workstation ve ESX Server

Hoca makalenin girişinin ikinci sütunundan bir paragraf okudu. Makaleye göre ESX Server'ın tasarımı VMware Workstation'dan önemli ölçüde farklıdır. İkisi de VMware ürünüdür. Workstation hosted bir sanal makine mimarisi kullanır, yani bir işletim sisteminin üzerinde çalışır ve taşınabilir G/Ç aygıt desteği için var olan bir işletim sisteminden yararlanır.

Makaledeki örnek şudur: Linux üzerinde çalışan bir sanal makine monitörü (VMM, virtual machine monitor), bir sanal makinenin kendi sanal diskinden sektör okuma girişimini yakalar ve karşılık gelen veriyi almak için alttaki Linux'a bir `read` sistem çağrısı yapar. Yani üstteki sanal makine kendisine verilmiş diskten okumak isterse, bu istek alttaki Linux'un `read` sistem çağrısına dönüşür.

Buna karşılık ESX Server sistem donanımını doğrudan yönetir. Bu, önemli ölçüde daha yüksek G/Ç başarımı ve kaynak yönetimi üzerinde tam denetim sağlar. Yani ESX donanım seviyesine çok daha yakındır. Hoca ESX'i "amacı sanallaştırma için oluşturulmuş bir işletim sistemi" diye tanımladı.

Hoca makalenin kaynakçasında Disco'nun bulunduğuna dikkat çekti. Disco makalesi henüz okunmamıştı; hoca onu ileride Xen ile birlikte okutacağını söyledi.

## 4. Sanal, fiziksel ve makine adresi

### 4.1 Öğrencinin anlatımı

Öğrenci, sonrasını anlamak için sanal belleği bilmek gerektiğini söyledi ve süper sayfalar konusunda da değinilen sanal bellek kavramını özetledi. Segmentli bellekten sayfalı belleğe geçilince parçalanma sorunundan kurtulunur; prosesin belleği sayfa sayfa ayrılıp belleğin farklı yerlerine konabilir. Buradan sanal bellek kavramı doğar: arada bir soyutlama vardır, proses gerçek bellekten habersizdir. CPU sanal adresler üretir, bellek yönetim birimi (MMU) TLB'ye ve sayfa tablosuna giderek bunu gerçek adrese çevirir.

Makaledeki kavram bunu bir adım öteye götürür: proses belleğin aslını bilmiyorsa, işletim sistemi de bilmesin. İşletim sisteminin gittiğini zannettiği yere de bir soyutlama konur, gerisini ESX halleder. Böylece bir sanal sayfa numarasından fiziksel sayfa numarasına (PPN, physical page number), oradan da gerçek belleğin adresi olan makine sayfa numarasına (MPN, machine page number) geçilir. PPN'nin MPN'ye eşlenmesi gerekir.

### 4.2 Hocanın netleştirmesi

Hoca üç kavramı basitçe tanımlattı ve öğrencilerin cevaplarını düzelterek şu sonuca vardı:

- **Sanal adres:** Prosesin, yani CPU üzerinde çalışan programın ürettiği adres. Sanal bellekten dolayı vardır.
- **Fiziksel adres:** Prosesin çalıştığı işletim sisteminden çıkan adres. İşletim sistemi sanal adresi kendi sayfa tablosuyla fiziksel adrese çevirir. Bu kavramdan önce fiziksel adres RAM'in o gözü demekti.
- **Makine adresi:** İşletim sisteminden çıkan fiziksel adresin VMM (burada ESX) tarafından bir kez daha çevrilmesiyle VMM'den dışarı çıkan, gerçek bellek adresi.

**Soru:** Fiziksel adres nereden çıkıyor? **Cevap:** Bir öğrenci "MMU'dan" dedi, hoca kabul etmedi. Bir başkası "host'tan" dedi; hoca "host değil, işletim sistemi" diye düzeltti. Fiziksel adres, prosesin çalıştığı işletim sisteminden çıkar.

**Soru:** Sanallaştırma yokken işletim sisteminden çıkan fiziksel adres nereye gider? **Cevap:** RAM'e, yani RAM'in adres ve veri yollarına giden fiziksel sinyallere. Sanallaştırma varsa arada bir katman daha vardır: VMM. VMM adresi bir kez daha çevirir ve makine adresine dönüştürür.

### 4.3 İkinci çeviri neden gerekli?

Hoca neden ikinci bir dönüşüme ihtiyaç olduğunu sordu. Bir öğrenci her soyutlamanın bunu gerektirdiğini, işletim sisteminin fiziksel bir yer, RAM'in kendisini beklediğini, oysa RAM'in parçalanıp sayfa sayfa verildiğini anlattı. Hoca bunun ayrıntıda doğru olduğunu ama "nokta atışı" bir cevap istediğini söyledi ve cevabı kendisi kurdu.

Programcı açısından işi kolaylaştırmak için her programın, dolayısıyla her prosesin adresleri sıfırdan başlamalıdır. Bütün belleği kullanmak ayrı bir konudur; önemli olan adresin sıfırdan başlamasıdır. İşletim sistemi de sonuçta bir programdır ve onun da adreslerinin sıfırdan başlaması gerekir. Normalde gerçek işlemci üzerinde çalışacaktı; gerçek bir sistem kuran biri belleği 10.000 adresinden değil, sıfır adresinden başlatır. Üst sınırın tamamını kullanmak zorunda değildir, ama bir sıfırdan başlamalıdır.

Doğrudan donanım üzerinde çalışan bir işletim sistemi zaten sıfır adresiyle karşılaşır. Sanallaştırılmış bir işletim sistemine ise gerçek sıfır adresi verilemez, çünkü sistemde tek bir sıfır adresi vardır, iki tane yoktur. Bu yüzden her işletim sistemine adreslerinin sıfırdan başladığı imajı verilir ve ikinci bir çeviri gerekir.

> **Hocanın vurgusu:** Sanal adres prosesten sıfırdan başlıyormuş gibi çıkar ve fiziksel adrese çevrilir. Fiziksel adresler de sıfırdan başlıyormuşçasına çıkar, ama sanal ortamda oldukları için bir daha çevrilir ve gerçekten makine adresine dönüşür. Bu üç kavram önemlidir.

## 5. Balonlama (ballooning)

### 5.1 Sorun: bir konuktan bellek geri almak

Hoca balonlama kavramının ne olduğunu sordu. Öğrenci şöyle anlattı: bazı konukların (guest) bazı zamanlarda daha çok belleğe ihtiyacı olur, bazıları ise ayrılan belleği çok kullanmaz; bellek buna göre artırılıp azaltılmalıdır. Bir yöntem, VMM'nin sayfa tablolarını denetleyip işletim sisteminin en az kullandığı sayfaları kendisinin takas etmesidir. Ancak bu durumda makalede "double paging" sorunu olarak geçen bir sorun çıkar: konuk işletim sistemi ile VMM'nin sayfalama kararları çakışabilir. Ayrıca konuk işletim sisteminin kendisi hiçbir şekilde değiştirilmek istenmez. Bu seçenek bu yüzden elenir.

> **Ek bilgi (derste anlatılmadı):** Makalede büyük olasılıkla belirtildiği gibi VMM sayfa seçerken konuğun hangi sayfaları az kullandığını bilmez; ayrıca VMM bir sayfayı diske çıkardıktan sonra konuk aynı sayfayı kendisi de dışarı çıkarmak isterse sayfa önce diskten geri getirilip sonra yeniden yazılır. Double paging bu gereksiz çift G/Ç'ye verilen addır.

### 5.2 Çözüm: balon sürücüsü

Konuk işletim sistemine karışmadan bunu yapmak için bir çekirdek modülü ya da aygıt sürücüsü yazılır ve konuğa yüklenir. Bu, konuğu değiştirmek sayılmaz, çünkü çekirdek bu yapıyı zaten sunar. Sürücü konukta çalışır ve VMM bununla konuşabilir. Bir konuktan kaynak alınacağı ya da ona kaynak verileceği zaman VMM doğrudan bu sürücüyle konuşur.

Hoca makaleden okudu: sunucu bellek geri almak istediğinde sürücüye şişmesini (inflate) söyler; sürücü de sabitlenmiş fiziksel sayfalar (pinned physical pages) ayırarak şişer.

**Soru:** "Pinned" ne demek? **Cevap:** Bir öğrenci "sabitlenmiş, doğrudan bağlantısı olan" dedi. Hoca bunu bir panoya iğneyle tutturulan kâğıda benzetti. Pinned sayfalar yerinde sabitlenir, hiç değişmeyecekmiş gibi davranılır.

### 5.3 Balon nasıl çalışır?

Hoca açıklamayı tamamlamak için önce şunu sordu: işletim sistemi tek başına bir donanım üzerinde çalışsaydı ve kullanabileceği boş bellek kalmamışken yeni bir program başlatmak isteseydi ne yapardı? Cevap: bazı proseslerin kullanmadığı bellek parçalarını dışarı yazarak (page out) çalar, yani sayfa çalma (page stealing) yapar ve yeni prosese yer açar.

O halde sayfa çalmayı tetiklemenin yolu, işletim sistemine belleğin bittiği izlenimini vermektir. Balon sürücüsünün yaptığı şey çok basittir:

- **Şişme (inflate):** Sürücü gereksiz yere bellek isteğinde bulunur, isteğini artırdıkça artırır. İşletim sistemi elinde boş bellek kalmadığını görür ve proseslerin kullanmadığı sayfaları çalmaya, dışarı yazmaya başlar. Balonun tuttuğu sayfalar aslında VMM'ye devredilmiş olur; ESX böylece istediği belleğe sahip olur.
- **Söndürme (deflate):** ESX'in belleğe ihtiyacı yoksa, örneğin yeni bir sanal makine başlatılmıyorsa, konuk işletim sistemleri boşuna sıkıntı çekmesin diye balon küçültülür. Balonun küçülmesi, balonun temsil ettiği prosesin kendi rızasıyla sayfaları serbest bırakması demektir. İşletim sistemi belleğinin arttığını düşünür ve artık zorla sayfa çalmasına, sayfaları diske yazmasına gerek kalmaz.

Hoca bir sanal makinenin belleğe neden ihtiyaç duyabileceğini de örnekledi: VMware'in yeni bir sanal makine çalıştırması gerekir, ama o sırada boş belleği yoktur. O zaman çalışan diğer sanal makinelerden bellek toplaması gerekir; balonlama bunun yoludur.

Sayfa çalarak çalışmak işletim sisteminin başarımını düşürür. Hoca buna thrashing dedi: bellek azaldığı için bir sayfayı dışarı çıkarırsınız, bir sonraki aşamada o sayfaya ihtiyaç duyar, tekrar içeri alırsınız; ping pong gibi gidip gelir. Bu zaman açısından bir maliyettir.

> **Hocanın vurgusu:** Balonlamada işletim sistemi "kandırılır". İşletim sisteminin iç yapısına karışmadan, ona müdahale etmeden ya da onda değişiklik yapmadan, yalnız ihtiyaca göre dinamik olarak bellek isteyen veya elindeki belleği bırakan basit bir çekirdek seviyesi sürücüsüyle bellek yönetilir. Sürücünün tek görevi doğrudan VMM ile (bu örnekte VMware ile) haberleşmektir.

Bir öğrencinin "VMware ile ESX Server farkı ne?" sorusuna hoca, VMware'in ESX Server'ın üreticisi olduğunu, VMware denince host'u ya da VMM'yi kastettiklerini varsaymayı önerdi.

### 5.4 Makaleden ayrıntılar

Hoca makaleden şu kısımları okudu:

- Linux, FreeBSD ve Windows için yazılan balon sürücüleri, hedef balon boyutunu öğrenmek için sunucuyu saniyede bir yoklar. Sunucu dediği ESX Server'dır: her saniye, bir sonraki saniyede balon boyutunun ne olmasını istediğini söyler.
- Sürücüler konuk işletim sistemini zorlamamak için tahsis hızlarını uyarlamalı olarak sınırlar.
- Fiziksel sayfa ayırmak için standart çekirdek arayüzleri kullanılır: Linux'ta `get_free_page`, Windows'ta `MmAllocatePagesForMdl` ya da `MmProbeAndLockPages`.
- Çalışırken bellek eklemeyi destekleyen (hot-pluggable memory) gelecekteki konuk işletim sistemleri, ek bir kaba taneli (coarse-grained) balonlama biçimini mümkün kılabilir.

Hoca son maddeyi açıkladı. 2002'de Linux, FreeBSD ve Windows'un hiçbiri çalışırken bellek eklemeyi desteklemiyordu, çünkü sunucular kapatılmadan üzerine bellek eklenemiyordu; donanım ortamı olmadığı için işletim sisteminin çalışırken belleğinin artması söz konusu değildi. Sanallaştırma ortamı ve donanımdaki değişiklikler bir araya gelince, bugün sunucu mimarisindeki sistemlere çalışır durumdayken bellek takılabilmektedir. Bunu işletim sisteminin de algılaması gerekir. Balonlamaya benzer biçimde işletim sisteminin belleğinin yeniden boyutlandırılması mümkündür; makale bunu da söyler.

Bir öğrenci bunların pratikte bilmeden yaptıkları işler olduğunu söyleyince hoca, artık bunları bilerek yapmalarını ve arkasında ne olduğunu düşünmelerini istedi.

## 6. Şeffaf sayfa paylaşımı

### 6.1 "Şeffaf" ne demek?

Aradan sonra hoca şeffaf sayfa paylaşımının (transparent page sharing) ne olduğunu sordu. Bir öğrenci önce "transparent" kavramının işletim sistemlerinde tam olarak neyi ifade ettiğini sordu; bu kavram süper sayfalar makalesinde ve koruma halkaları konusunda da geçmişti. Hoca kelimenin Türkçesini sordu: şeffaf.

Öğrencilerden farklı cevaplar geldi: farklı sanal makineler arasında bir geçirgenlik; var olan şeyi değiştirmeye gerek kalmadan; paylaşılacak sayfaları en başta belirleyip paylaştırmak. Hoca şöyle açıkladı.

Farklı işletim sistemleri çalışıyor ve birbirlerini bilmiyorlar, farkında bile değiller. Sanallaştırmada oluşturulan yanılsama zaten budur: her işletim sistemi o donanımda tek başınaymış gibi çalışır. O zaman bir işletim sistemi kendisi isteyerek ve bilerek içeriği aynı olan sayfaları başka bir işletim sistemiyle paylaşamaz; bu olayın mantığına aykırıdır, çünkü öbür işletim sisteminin varlığını bilmez.

### 6.2 libc örneği

İki işletim sistemi bir arada çalışıyor ve ikisi de aynı sürümdeki libc paylaşılan nesnesini (shared object) yüklemiş olsun. libc salt okunurdur, yeniden girilebilir (re-entrant) bir koddur. İşletim sistemleri birbirinden habersiz olduğu için bunu paylaşamaz. Araya VMM girer. VMM bir üst seviyeden baktığı için bazı sayfaların içerikleri aynıysa bunu görür. Önce içeriklerin değişmediğini varsayalım; Windows'ta bunun karşılığı DLL'dir (Dynamic Link Library).

Bu durumda kütüphaneyi bir A işletim sistemi için, bir B işletim sistemi için olmak üzere iki kez belleğe yüklemenin anlamı yoktur. Bir kopya yüklenir, iki tarafa da aynı yerden servis edilir. A da B de bunun farkında değildir; bilgiler iki işletim sistemi arasında onlara sorulmadan, söylenmeden, şeffaf biçimde paylaştırılır. Onların çalışmasında bir değişiklik, bozulma olmaz, ama sistem genelinde bellekten kazanç sağlanır.

Hoca uç bir örnek verdi: aynı donanım ve aynı VMM üzerinde aynı işletim sisteminin aynı sürümünden 100 kopya çalıştırılsın. libc'yi 100 kez yüklemek yerine bir kez yüklenir. Bu kütüphane, o işletim sistemlerinde çalışacak bütün proseslerin mutlaka ihtiyaç duyduğu kütüphanedir; onsuz proseslerin çalışma zamanı sağlanamaz. Şeffaf sayfa paylaşımının arkasındaki fikir budur.

## 7. İçerik tabanlı sayfa paylaşımı ve copy-on-write

### 7.1 Neden içerik tabanlı?

Öğrenci içerik tabanlı sayfa paylaşımını (content-based page sharing) anlattı. Şeffaf paylaşımda VMM'nin bir konuğun ortak sayfaya ne zaman yazdığını bilmesi gerekir, çünkü yazmadan sonra sayfa iki konuk için artık aynı olmaz ve konukların bundan haberi yoktur. Makaleye göre VMM, konuğun sistem çağrılarını izlemek ya da konuk koduna kanca atmak (makalede bcopy kancalama gibi bir yöntem olarak geçer) istemez. Bunun yerine konuğa hiç karışmaz: bütün sayfalar zaten VMM'nin elindedir, hangilerinin birbirinin aynısı olduğunu kendisi bulur ve aynı olanları paylaştırır.

Aynı olan iki sayfayı bulmak için her sayfayı her sayfayla karşılaştırmanın karmaşıklığı $O(n^2)$'dir. Her sayfanın özeti (hash) hesaplanıp bir özet tablosu kullanılırsa maliyet azalır.

Bir öğrenci "içeriğin önemi yok, yalnız aynı olması önemli" deyince, hocayla birlikte bu düzeltildi: içerik önemlidir, içerik aynıysa tek kopya tutulur. Özet hesaplanırken sayfa okunur; asıl nokta, işletim sistemine karışmaya gerek olmamasıdır.

### 7.2 Özetle karşılaştırma neden daha hızlı?

**Soru:** Özet alıp kontrol etmek neden daha hızlı? **Cevap:** Bir öğrenci, özetin sayfanın bir özetini verdiğini ve anahtar olarak kullanılınca özet tablosunda tek bir arama yapıldığını söyledi. Hoca daha teknik bir cevap bekledi ve şöyle açıkladı.

Özet kullanılmasaydı bir sayfa alınıp bütün sayfalarla tek tek karşılaştırılırdı. Bir sayfa $n$ sayfa ile karşılaştırılır ve her karşılaştırmada sayfadaki her kelime (mimariye göre 32 ya da 64 bit) ayrı ayrı karşılaştırılır. Hoca 4096 karşılaştırma, yani 4096 kez `if`'e girmek dedi; bu ciddi bir başarım kaybıdır. Özet hesabında ise sayfa bir dizi gibi düşünülür; XOR, toplama, OR gibi işlemlerden oluşan bir döngüyle baştan sona karşılaştırma yapmadan ilerlenir ve sonunda sayfanın tamamı için tek bir karşılaştırma yapılır. Özet hesaplamak için kullanılan işlemler aşırı karmaşık olmayan mantık işlemleri olduğu için çok daha fazla zaman kazanılır.

> **Ders sonrası not:** Hoca bir sayfa için "4096 karşılaştırma" dedi. 4 KB'lık bir sayfa 4096 bayttır; kelime kelime karşılaştırmada 32 bitlik kelimelerle 1024, 64 bitlik kelimelerle 512 karşılaştırma eder (python ile kontrol edildi). 4096 sayısı büyük olasılıkla bayt bayt karşılaştırmaya karşılık gelir.

### 7.3 Paylaşılan sayfaya yazılırsa: copy-on-write

Hoca bir senaryo kurdu: kod güzelce yazıldı, aynı sayfalar bulundu, tek kopyaya indirildi ve paylaşıldı. Ama bu sayfa salt okunur değilmiş, yazılabilir bir sayfaymış ve işletim sistemlerinden biri bu sayfaya yazmaya karar verdi. Ne olacak? Diğerleri sayfayı yeni haliyle mi kullanacak?

Öğrenciler diğerlerinin bunu kabul etmemesi gerektiğini, yoksa yanlış çalışacaklarını söyledi. Bir öğrenci, özet değişince o program için sayfanın ayrılacağını, ama o zaman paylaşmanın anlamının kalmadığını düşündü.

Hoca, içerik tabanlı sayfa paylaşımının depolamada da kullanıldığını ve buna tekilleştirme (deduplication) dendiğini söyledi. Verinin tek kopyası yazılır; bir taraf, örneğin bir işletim sistemi, veriyi değiştirdiği anda verinin kopyası oluşturulur. Kopya değiştiği zaman, yani yazma işlemi yapıldığı zaman oluşturulur. Terim de buradan gelir: copy-on-write, yani yazma varsa kopyasını al. Çok klasik bir yöntemdir.

Hocanın örneği: yüz işletim sistemi çalışıyor, bunlardan 3'ü sayfayı değiştirdi. 97'si tek kopyayla çalışmaya devam eder, 3'ünün kendisi için özelleşmiş kopyası olur. Yüzü de değişiklik yapıyorsa o sayfalar zaten içerik tabanlı paylaşım mantığıyla paylaşılamaz.

## 8. Güvenli özet ile hızlı özet

Hoca makalenin Figure 4 civarındaki bir cümleyi okudu: taranan her sayfa için hızlı, yüksek kaliteli bir özet fonksiyonuyla 64 bitlik bir özet değeri üretilir. Bu bir güvenli özet (secure hash) değildir.

**Soru:** Güvenli özet ile burada kullanılan özet arasındaki fark ne? **Cevap:** Bir öğrenci güvenli özet algoritması olarak SHA ve SHA-256'yı hatırlattı. Başka bir öğrenci, 64 bitlik özetin daha hızlı olduğunu ama çakışma olasılığının 256 bitlik özete göre daha yüksek olduğunu söyledi. Hoca şöyle tamamladı: güvenli özette çakışma için "az" diye bir şey olamaz; teorik olarak çakışma beklenmez. Tek bir bit bile değişse çıkacak özetin değişmesi beklenir. Güvenli özet böyle olmalıdır ve bu yüzden karmaşıklığı daha yüksektir.

Hoca farkı canlandırmak için başka bir dersinden aklında kalan yaklaşık değerler verdi. SHA-256 günümüzün modern işlemcilerinde saniyede yaklaşık 2000 milyon özet (MH/s birimiyle) hesaplanabilir; bu sayfa boyutunda değil, 256 bitlik bir girdi içindir. Buna karşılık bcrypt gibi bir fonksiyonla saniyede yalnız yaklaşık 45 bin özet hesaplanır. Sayfa paylaşımında gereken özet bu tür güvenlik özelliklerine sahip olmak zorunda değildir: çakışmaya izin verir ama çok düşük oranda izin verir ve hızlıdır. Bu yüzden algoritma çok daha etkin olur.

> **Ek bilgi (derste anlatılmadı):** Bu tür saniyedeki özet sayıları büyük olasılıkla GPU üzerinde ölçülen parola kırma kıyaslamalarından gelir ve donanıma göre çok değişir. bcrypt kasıtlı olarak yavaş tasarlanmış bir parola özetleme fonksiyonudur; bu nedenle kendi amacı için yavaşlığı bir özelliktir.

Bir öğrenci, makalede çakışmanın da ele alındığını belirtti: özetler aynı çıkınca sayfalar ayrıca tam olarak karşılaştırılır. Hoca bunu onayladı. Yani tam karşılaştırma yalnız özetler eşleştiğinde yapılır.

## 9. Sayfa paylaşımının başarımı

### 9.1 Eşzamanlı sanal makine sayısı ile kazanç

Hoca makalenin sayfa paylaşımı başarımını gösteren şeklini (Figure 4) sözlü olarak anlattı. Şekilde eşzamanlı sanal makine sayısı ile paylaşılan bellek miktarı ve yüzdesi vardır. Çalışan sanal makine sayısı arttıkça kazanılan bellek miktarı yaklaşık doğrusal biçimde artar; eğim değişse de artış doğrusal kalır. Hocanın okuduğuna göre kazanç 50 MB civarından başlayıp 400 MB'a kadar çıkar; 10 sanal makinede neredeyse 400 MB'lık bir bellek kazancı sağlanır. <!-- BELİRSİZ: Şekil ekranda gösterilmedi; değerler hocanın sözlü okumasından alındı. -->

Yüzde olarak bakıldığında, hoca sanal makine belleğinin yaklaşık %67'sinin bu yolla tekilleştirilebildiğini söyledi. Bu durumda bir sanal makine için belleğin %100'ünü ayırmak yerine yaklaşık %33'ü, yani üçte biri yeterli olur. Bu da aynı bellekte bir yerine 3 sanal makine çalıştırmak demektir ($1/(1-0{,}67) \approx 3$, python ile kontrol edildi).

> **Hocanın vurgusu:** Yalnız basit bir algoritmik yaklaşımla eldeki donanım kaynağı çok daha etkin kullanılmış olur.

### 9.2 Gerçek kurulumlardan paylaşım ölçümleri

Hoca makalenin Figure 5'ini okudu: ESX Server'ın gerçek kurulumlarından paylaşım ölçümleri. Üç senaryo vardır:

- **A:** Büyük bir şirkette kullanıcılara hizmet veren Windows NT sanal makineleri. Veritabanı (Oracle, SQL Server), web sunucusu (IIS, WebSphere) ve Java ya da Visual Basic uygulamaları çalıştırır. 10 sanal makine için toplam bellek 2 GB'tır. Paylaşım yaklaşık %43'tür.
- **B:** Kâr amacı gütmeyen bir kuruluşun geniş kullanıcı topluluğuna hizmet veren 9 Linux sanal makinesi. Web (Apache), posta (Majordomo, Postfix, POP/IMAP, MailArmor) ve diğer sunucuları çalıştırır. Toplam bellek 1846 MB'tır. Paylaşım yaklaşık %29'dur.
- **C:** VMware çalışanlarına web vekil sunucusu (Squid), posta (Postfix, RAV) ve uzaktan erişim (SSH) hizmeti veren 5 Linux sanal makinesi. Toplam bellek 1658 MB'tır. Paylaşım yaklaşık %10'dur.

C, paylaşım açısından en düşük verimli senaryodur. Hocanın yorumuna göre web vekil sunucusu çok farklı yerlere erişir ve uzaktan erişimde farklı işler, farklı prosesler çalıştırılır. Yine de normal kullanıma göre belli bir miktar bellek kazanılır.

Hoca C senaryosunun açıklamasını da okudu: sayfa paylaşımı sanal makine belleğinin yaklaşık %7'sini geri kazanmış ve 120 MB tasarruf sağlamıştır; bunun 25 MB'ı sıfır sayfalarından (zero pages) kaynaklanır. Sıfır sayfası, tahsis edilmiş ama içi boş, hiç yazılmamış sayfadır. Python ile kontrol: $120/1658 \approx \%7{,}2$, okunan %7 ile tutarlıdır.

## 10. Boşta bellek vergisi

### 10.1 Kavram

Son olarak boşta bellek vergisi (idle memory tax) konuşuldu; yani boştaki belleğin geri alınması. Bir öğrenci bunu bugünkü bulut kiralama örnekleriyle ilişkilendirdi: bir şirketten daha fazla para verip daha fazla bellek ayırtabilirsiniz, ama ayırttığınız belleğin her yerine erişmiyorsanız, yani ayırdığınız belleğin çoğu boştaysa daha yüksek vergi ödersiniz. Hoca bunun "para değil, vergi" olduğunu vurguladı: mekanizma vergi mantığı üzerine kuruludur. Boşta bellek ne kadar yüksekse vergi o kadar yüksektir.

Hoca bu tür fonksiyonlara genelde ceza fonksiyonu (penalty function) dendiğini söyledi. Bellek tahsisi ve geri alınması bu ceza fonksiyonuna göre yapılır.

### 10.2 Makaleden

Hoca makaleden okudu: boşta bellek vergi oranı ayarlanabilir bir parametredir ve öntanımlı değeri %75'tir. Hoca bunun o zamanki ESX Server için geçerli olduğunu, bugünküne ayrıca bakmak gerektiğini ekledi. Bu oran, sistemdeki boşta belleğin çoğunun geri alınmasını sağlarken çalışma kümesinin hızlı büyümesine karşı bir tampon bırakır ve balonlama ile takas gibi geri alma işlemlerinin gecikmesini gizler.

Hoca bağlantıyı kurdu: başlangıçta bellek balonlama ile geri alınıyordu, balonun şişmesi ve sönmesiyle. Ancak balonlamanın gecikmesi daha yüksektir. Boşta bellek vergisiyle bu çok daha hızlı gerçekleşebilir.

> **Ek bilgi (derste anlatılmadı):** Makalede vergi mekanizması büyük olasılıkla pay tabanlı (proportional share) bellek tahsisine eklenir: bir sanal makinenin bellek payı, boşta tuttuğu sayfalar daha pahalı sayılarak hesaplanır ve bellek baskısı olduğunda bellek önce boşta belleği çok olan sanal makinelerden alınır. Boşta bellek oranı, sayfaların rastgele örneklenerek erişilip erişilmediğinin izlenmesiyle tahmin edilir.

## Örnek Sorular

Bu derste ekranda soru gösterilmedi; aşağıdaki sorular derste sözlü olarak soruldu.

**Soru 1** (derste sözlü, 00:17:34): ESX Server'daki işlemci sanallaştırması Java Virtual Machine'deki gibi sanal bir işlemci mimarisi oluşturarak mı gerçekleşir?

> **Cevap (derste verildi):** Hayır. ESX donanımın sanal kopyalarını oluşturur, işlemci mimarisini değiştirmez. Alttaki donanım hangi mimarideyse üstte çalışan işletim sistemleri de o mimari için yazılmış olmalıdır. JVM ise kendi genel komutlarını alttaki işlemcinin komutlarına çeviren sanal bir işlemci tanımlar. İkisi farklı kategori sanallaştırmalardır.

**Soru 2** (derste sözlü, 00:24:38): Hosted bir mimaride (Linux üzerinde VMM) sanal makine kendisine verilmiş diskten okumak isterse bu istek alt tarafta neye dönüşür?

> **Cevap (derste verildi):** VMM isteği yakalar ve alttaki Linux'a bir `read` sistem çağrısı olarak iletir. ESX Server ise donanımı doğrudan yönettiği için böyle bir ara işletim sistemi yoktur.

**Soru 3** (derste sözlü, 00:28:57): Sanal adres, fiziksel adres ve makine adresi nedir; her biri nereden çıkar?

> **Cevap (derste verildi):** Sanal adres prosesten çıkar. Fiziksel adres, prosesin çalıştığı konuk işletim sisteminden çıkar. Makine adresi, VMM'nin fiziksel adresi bir kez daha çevirmesiyle VMM'den çıkan gerçek bellek adresidir. Sanallaştırma yoksa fiziksel adres doğrudan RAM'e gider.

**Soru 4** (derste sözlü, 00:31:31): Sanallaştırmada neden ikinci bir adres çevirisine ihtiyaç vardır?

> **Cevap (derste verildi):** İşletim sistemi de bir programdır ve adreslerinin sıfırdan başlamasını bekler. Sistemde gerçek sıfır adresi tek olduğu için her konuğa ayrı ayrı verilemez. Her konuğa sıfırdan başlayan bir fiziksel adres uzayı yanılsaması verilir ve VMM bu adresleri makine adreslerine çevirir.

**Soru 5** (derste sözlü, 00:34:57 ve 00:39:00): Balonlama tekniği nedir, işletim sistemini nasıl "kandırır"?

> **Cevap (derste verildi):** Konuğa yüklenen bir balon sürücüsü VMM ile haberleşir. Şiştiğinde gereksiz yere sabitlenmiş sayfalar isteyerek konuğa belleğin bittiği izlenimini verir; konuk kendi algoritmasıyla kullanılmayan sayfaları dışarı yazar ve balonun tuttuğu sayfalar VMM'ye geçer. Söndüğünde sayfalar serbest kalır ve konuk sayfa çalmayı bırakır. Konuk işletim sisteminin iç yapısına dokunulmaz.

**Soru 6** (derste sözlü, 00:37:30): "Pinned physical pages" ifadesindeki "pinned" ne demektir?

> **Cevap (derste verildi):** Sabitlenmiş demektir; panoya iğneyle tutturulmuş bir kâğıt gibi yerinden oynatılmayan, diske çıkarılmayan sayfalar.

**Soru 7** (derste sözlü, 01:05:36): Şeffaf sayfa paylaşımında "şeffaf" ne anlama gelir ve paylaşımı neden konuk işletim sistemleri kendileri yapamaz?

> **Cevap (derste verildi):** Konukların haberi olmadan, onlara sorulmadan ve çalışmaları değişmeden yapılan paylaşım demektir. Konuklar birbirinin varlığından habersiz olduğu için aynı içerikli sayfaları bilerek paylaşamazlar; bunu bir üst seviyeden bakan VMM yapar. Örnek: aynı sürümdeki libc'nin tek kopyasının birçok konuğa servis edilmesi.

**Soru 8** (derste sözlü, 01:12:51): İçerik tabanlı sayfa paylaşımında sayfaları özet alarak karşılaştırmak neden daha hızlıdır?

> **Cevap (derste verildi):** Özet yoksa bir sayfa bütün sayfalarla kelime kelime karşılaştırılır; her kelime için ayrı bir karşılaştırma gerekir ve tüm çiftler için maliyet $O(n^2)$ olur. Özet ise XOR, toplama, OR gibi basit işlemlerden oluşan bir döngüyle hesaplanır, sonunda tek bir karşılaştırma yapılır ve özet tablosunda tek bir aramayla eş adaylar bulunur. Eşleşme olursa çakışmaya karşı sayfalar tam olarak karşılaştırılır.

**Soru 9** (derste sözlü, 01:15:22): Tek kopyaya indirilip paylaşılan yazılabilir bir sayfaya konuklardan biri yazarsa ne olur?

> **Cevap (derste verildi):** Diğer konuklar değişikliği görmemelidir. Yazma anında yazan konuk için sayfanın kopyası çıkarılır (copy-on-write). Örneğin yüz konuktan üçü yazarsa doksan yedisi tek kopyayı paylaşmaya devam eder, üçü kendi kopyasını alır.

**Soru 10** (derste sözlü, 01:19:51): SHA-256 gibi bir güvenli özet ile makalede kullanılan "hızlı, yüksek kaliteli" 64 bitlik özet arasındaki fark nedir?

> **Cevap (derste verildi):** Güvenli özette teorik olarak çakışma beklenmez ve tek bir bit değişse bile özet değişmelidir; bu yüzden karmaşıklığı yüksektir. Sayfa paylaşımındaki özet düşük oranda çakışmaya izin verir ama çok hızlıdır; eşleşmeler zaten tam karşılaştırmayla doğrulandığı için bu yeterlidir.

**Soru 11** (derste sözlü, 01:29:44): Boşta bellek vergisi (idle memory tax) nedir?

> **Cevap (derste verildi):** Bir sanal makinenin ayırıp kullanmadığı bellek için daha yüksek "vergi" ödemesini sağlayan, ceza fonksiyonuna dayanan bir tahsis mekanizmasıdır. ESX Server'da oran ayarlanabilir ve öntanımlı olarak %75'tir. Boşta belleğin çoğunu geri alırken çalışma kümesi büyümesine karşı tampon bırakır ve balonlamaya göre daha düşük gecikmeyle çalışır.

## Dersin Toparlaması

Bu derste VMware ESX Server'ın bellek kaynak yönetimini anlatan makale tartışıldı. Önce sanallaştırmanın tek bir türü olmadığı gösterildi: JVM sanal bir işlemci mimarisi tanımlarken, ESX donanımın sanal kopyalarını oluşturur ve konukların alttaki mimariyle aynı mimari için yazılmasını gerektirir. ESX, hosted mimarideki VMware Workstation'dan farklı olarak donanımı doğrudan yönetir. Bellek sanallaştırmasının temeli olarak sanal, fiziksel ve makine adresi kavramları ve ikinci adres çevirisinin nedeni, yani her konuğa sıfırdan başlayan bir adres uzayı verme gereği üzerinde duruldu.

Ardından ESX'in bellek geri alma ve paylaşma teknikleri incelendi. Balonlama, konuk işletim sistemini değiştirmeden onun kendi sayfalama algoritmasını tetikler. Şeffaf ve içerik tabanlı sayfa paylaşımı, birbirinden habersiz konukların aynı içerikli sayfalarını hızlı bir 64 bitlik özet ve copy-on-write ile tek kopyaya indirir; gerçek kurulumlarda bu yolla belleğin önemli bir kısmı kazanılır. Boşta bellek vergisi ise kullanılmayan belleği bir ceza fonksiyonuyla geri alır. Hoca makalenin kalan kısımlarını aynı yaklaşımla okumayı önerdi ve sanallaştırma konusunu sürdürmek için sonraki okumalar olarak Xen ve Disco makalelerini andı.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
