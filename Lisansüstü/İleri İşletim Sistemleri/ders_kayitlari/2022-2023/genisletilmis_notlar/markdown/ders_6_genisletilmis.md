# Ders 6 Genişletilmiş Notu: Mach'ta Bellek ve Haberleşmenin İkiliği ve Birinci Sınıf Kullanıcı Seviyesi Thread'ler

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dersin Biçimi ve Okunan İki Makale
- 2. "Duality" Ne Demek?
- 3. Mach'ın Soyutlamaları: Task ve Thread
- 4. Segmentli Bellekten Sanal Belleğe ve Bellek Eşlemeli G/Ç'ye
- 5. Memory Object, Portlar ve Kullanıcı Uzayı
- 6. UMA, NUMA ve NORMA
- 7. Program, Proses ve Thread
- 8. Kernel Seviyesi ve Kullanıcı Seviyesi Thread'ler
- 9. First-Class User-Level Threads ve Psyche
- Örnek Sorular
- Dersin Toparlaması

## 1. Dersin Biçimi ve Okunan İki Makale

Bu ders de önceki haftalar gibi öğrencilerin önceden okuduğu iki makalenin soru-cevapla tartışılmasıyla geçti. Kayıt boyunca ekranda slayt ya da makale paylaşılmadı; aşağıdaki bütün bilgiler sözlü anlatımdan ve hocanın makalelerden sesli okuduğu cümlelerden alınmıştır. İlk makale, hocanın adını tam olarak okuduğu "The Duality of Memory and Communication in the Implementation of a Multiprocessor Operating System" makalesidir. Bir öğrenci makalenin 1987 tarihli olduğunu söyledi ve işletim sisteminin adının "Mach" ("mak") diye okunduğunu hocaya teyit ettirdi. İkinci makale "first-class user-level threads" konusunu, yani kullanıcı seviyesi thread'lere birinci sınıf statü verilmesini anlatır; makalede uygulamanın yapıldığı sistemin adı Psyche olarak geçer.

> **Ek bilgi (derste anlatılmadı):** İlk makale büyük olasılıkla M. Young, A. Tevanian, R. Rashid, D. Golub, J. Eppinger ve arkadaşlarının 1987'de SOSP'ta (ACM Symposium on Operating Systems Principles) yayımlanan makalesidir. İkinci makalenin adı derste tam söylenmedi; büyük olasılıkla B. D. Marsh, M. L. Scott, T. J. LeBlanc ve E. P. Markatos'un 1991'de SOSP'ta yayımlanan "First-Class User-Level Threads" makalesidir. Psyche, büyük olasılıkla Rochester Üniversitesi'nde geliştirilmiş bir çok işlemcili işletim sistemidir.

## 2. "Duality" Ne Demek?

Bir öğrenci Mach'ın özetinde (abstract) "memory object" kavramının önemli bir bileşen olarak öne çıktığını ve bunun dış bir dosya sistemiyle haberleşirken kullanıldığını söyleyerek söze başladı. Hoca araya girip önce makalenin adındaki "duality" kelimesinin bu bağlamda ne anlama geldiğini sordu. Kelime anlamı "ikilik"tir, ama burada özel bir anlamda kullanılır.

Bir öğrenci kelimeyi "bir yerden alıp bir yere vermek", yani belleği güçlendirince başka bir şeyden kaybetmek gibi bir ödünleşim olarak yorumladı ve makalenin çok işlemcili sistemlerde en iyi tasarımı aradığını düşündüğünü söyledi. Hoca bunun makaledeki anlam olmadığını belirterek kavramı sistem sınıflandırmasından başlayarak açıkladı.

### 2.1 Paylaşılan ve paylaşılmayan bellekli sistemler

Makalede söz konusu olan, birden fazla işlemcisi olan bir işletim sistemidir (multiprocessor operating system). Bu tür sistemler iki gruba ayrılabilir:

- **Paylaşılan bellekli (shared memory) sistemler:** Bir öğrencinin cevabıyla işlemciler ve bellek veri yollarıyla (bus) bağlıdır. Birden fazla işlemci aynı belleğe erişir ve bu belleği aralarında paylaşır. Hoca bunlara sıkı bağlı (tightly coupled) sistemler dendiğini hatırlattı.
- **Paylaşılmayan bellekli (non-shared memory) sistemler:** Her işlemcinin kendi belleği vardır. İşlemciler başka bir katman, başka bir haberleşme yöntemi üzerinden birbirine bağlanır. İki sistemi TCP/IP protokolüyle internet üzerinden birlikte kullandığımızda böyle bir yapı kurmuş oluruz. Bunlar gevşek bağlı (loosely coupled) sistemlerdir.

Paylaşılan bellekli sistemler belli bir yere kadar ölçeklenebilir. İşlemci sayısı arttıkça bellek kapasitesi, bellek bant genişliği ve erişim hızıyla ilgili sıkıntılar başlar. Gevşek bağlı sistemler ise çok daha rahat ölçeklenir; hocanın deyişiyle yüzler, binler, hatta on binler mertebesinde ölçeklenebilen yapılardan söz edilir.

### 2.2 İkiliğin anlamı

Duality'nin anlatmak istediği şey şudur: paylaşılan bellekli bir sistemde çözümü olan bir problemin, paylaşılmayan bellekli bir yapılandırmada da mutlaka bir karşılığı vardır. Makalenin yazarları problemleri paylaşılan bellekli sistemlerden paylaşılmayan bellekli sistemlere taşıdıklarında denk düşen çözümü araştırırlar. Makalenin adındaki "memory and communication" ifadesi de buradan gelir: bir yanda paylaşılan ve paylaşılmayan bellek, öbür yanda buna bağlı olarak haberleşme.

Hoca makalenin girişindeki bir paragrafın son cümlesini okudu: Mach'ın bellek ile haberleşmeyi bu şekilde "dual" olarak ele almasıyla elde edilen avantajlar arasında kullanıcı programlarına bellek yönetiminde artan esneklik, Mach olanaklarının hem sıkı hem gevşek bağlı çok işlemcili sistemlerle daha iyi uyuşması ve daha yüksek performans vardır.

Cümlenin kritik kısmı "treating memory and communication as duals" ifadesidir. "Treat" burada bir şeyi ele almak, değerlendirmek anlamındadır. Bellek ve haberleşme, biri diğerinin yerine kullanılabilecek biçimde ele alınır. Bellek erişiminin semantiği ile haberleşme üzerinden erişimin semantiği eşitlenir, dışarıdan görünüşleri benzer hale getirilirse, zamansal farklar mutlaka kalır ama bunun dışında yerel belleğe erişmekle çok uzaktaki bir sistemin belleğine erişmek arasında fark kalmaz. O zaman ikisi birbirinin yerine geçebilir, eşdeğer parçalar olarak düşünülebilir.

**Soru:** Bir öğrenci, dosya sistemine kullanıcı uzayındaki bir yöneticinin bir port aracılığıyla eriştiğini, sayfa hatası olursa çekirdeğin tamponu doldurduğunu ve aynı uygulamanın ağ üzerinden başka bir yerde de yapılabildiğini söyleyerek hocanın kastettiği şeyin bu olup olmadığını sordu. **Cevap:** Hoca tam olarak bunu kastettiğini söyledi: bir yanda aynı çok işlemcili sistem, aynı sunucu yapısı üzerinde; öbür yanda ağ üzerinden farklı sunucular ve farklı sistemler üzerinde aynı yapı. Öğrenci de portun bu işteki rolünü vurguladı: çekirdekten doğrudan istemek yerine bir port üzerinden istenirse istenen yere erişilebilir. Hoca böylece makalenin özünü baştan söylemiş olduğunu belirtti.

## 3. Mach'ın Soyutlamaları: Task ve Thread

Öğrenci makalenin beş ilişkili soyutlama (five interrelated abstractions) tanımladığını anlattı: task, thread, port, message ve memory object. Öğrenciye göre task, thread, port ve message daha önceki bir sistemden alınmıştır. Önceki haftalarda okunan makalelerde task kavramı zaten görülmüştü; oradaki link kavramının Mach'ta porta dönüştüğü görülür. Hoca da "linkler porta dönüşüyor" diye bunu onayladı. Thread bir sonraki makalede ayrıca ele alınacaktı; memory object de makalenin ilerisinde anlatılır.

<!-- BELİRSİZ: Öğrencinin bu dört soyutlamanın alındığını söylediği sistemin adı altyazıda "Xen" diye geçiyor; doğru ad anlaşılamadı. -->

> **Ek bilgi (derste anlatılmadı):** Mach büyük olasılıkla Carnegie Mellon Üniversitesi'nde, aynı ekibin daha önce geliştirdiği Accent çekirdeğinin üzerine kurulmuştur. Port ve mesaj tabanlı haberleşme fikri büyük olasılıkla Accent'ten ve onun öncülü RIG sisteminden gelir.

### 3.1 Task ile thread arasındaki fark

Hoca, Mach'ın task ile thread arasındaki farkı çok güzel tarif ettiğini söyleyip bu farkı sordu. Bir öğrenci kendi bilgisinden "task birden fazla prosesin aynı anda işlenmesini sağlar, thread'de yalnız bir task çalışır" diye cevap verdi; hoca bunun makaleye dayanmayan bir yorum olduğunu belirtti. Başka bir öğrenci ise her thread'in kendi yazmaçları (register) ve kendi yığını (stack) olduğunu, ama hepsinin adres uzayının aynı, yani prosesinkiyle aynı olduğunu söyledi.

Hoca makaledeki tanımı okudu:

- "Task is the basic unit of resource allocation." Task, kaynak tahsisinin temel birimidir.
- "Thread is the basic unit of computation." Thread, hesaplamanın temel birimidir.

Bir programı çalışabilir hale getirmek için işletim sisteminin ona bellek ayırması, kod ve veri alanını belleğe getirmesi gerekir. Program çalışırken büyük olasılıkla dosyalara erişecek, ağı kullanacak, başka sistem kaynaklarından yararlanacaktır. Bütün bunların kaydının tutulması ve çalışma süresince programa tahsis edilmesi gerekir. Programı işletim sistemi açısından ifade eden, her türlü kaynağı kapsayan bu veri yapısı task'tır; sonradan buna proses denmiştir.

Task'ın içinde programa ait komutlar da vardır. Bunlar çalıştırılmaya başlandığında bir akış oluşur, bir şeyler ilerler; thread bu akışı gösterir. Çok thread'li (multi-threaded) yapı da buradan çıkan bir kavramdır. Hoca "computation" kelimesinin günümüzde genelleştirilerek "execution" (yürütme) dendiğini, çünkü her komutun bir şeyi hesaplamak zorunda olmadığını, bir dallanma, bir atlama ya da bir XOR da olabileceğini söyledi.

> **Hocanın vurgusu:** Task ile thread arasındaki esas kritik ayrım budur: task kaynak tahsisinin, thread yürütmenin birimidir.

Başlangıçta böyle bir ayrım yapılmıyordu; task eşittir thread kabul ediliyordu. Ancak bir program farklı parçaları aynı anda çalışabilecek biçimde kurulabiliyorsa, bu iki kavramı birbirinden ayırmak gerekir.

**Soru:** Bir öğrenci, ilk dönemde bu ayrım yokken bir proses G/Ç yaptığında işletim sisteminin onu durdurduğunu, o zaman "program bir kısmı dururken diğer kısmı devam edebilsin" diye düşünülüp düşünülmediğini sordu. **Cevap:** Hoca bunun zamanla söylendiğini, ilk başta söylenmediğini belirtti. Bu fikirler bir yerde yazılı olarak hazır bulunmuyordu; deneyerek, yanılarak, düşünerek, tasarımları iyileştirerek ve bunları kayda geçirerek adım adım bugüne gelindi. Hocaya göre 1960'lardan 1990'lara kadar yaklaşık 30 yıl bu konular üzerinde çok çalışıldı ve 1987'deki bu makaleden bu yana temel fikirler pek değişmedi.

> **Ders sonrası not:** Hoca 1987'den o güne kadar geçen süreyi "35 sene" diye hesapladı; ders 2023'te yapıldığı için doğrusu yaklaşık 36 yıldır.

## 4. Segmentli Bellekten Sanal Belleğe ve Bellek Eşlemeli G/Ç'ye

Öğrenci makalenin, Mach'ın sanal belleği Accent'ten aldığını söylediği kısmına geçti ve bunun arka planını önceki derslerde konuşulan bellek modelleriyle özetledi:

- **Segmentli bellek:** Parçalanma (fragmentation) problemi ortaya çıkar. Ayrıca prosesin bir bütün olarak belleğe konması gerekir; büyük prosesler kendilerine yer bulamayabilir.
- **Sayfalı bellek:** Sayfaların boyutları aynıdır, sayfalar belleğe konup çıkarılabilir; bu parçalanmayı engeller.
- **Sanal bellek:** Program gerçek değil mantıksal adres üretir. Bu soyutlama programcıyı gerçek adreslerle uğraşmaktan kurtarır ve prosese fiziksel bellekten çok daha büyük bir alanı kullanıyormuş gibi düşündürür. Ayrıca kodun tamamının belleğe konması gerekmez; parçalar alınıp yürütme bu şekilde yapılır.

Hoca, sanal belleğin Mach'ın ortaya attığı bir şey olmadığını, zaten var olan bir kavram olduğunu, Mach'ın onu hem alıp hem uyarladığını hem de yeri geldiğinde daha etkin hale getirdiğini özetledi. Öğrenci de konuyu tam bu "daha etkin" noktasına bağladı.

### 4.1 Paylaşılan kütüphane ve bellek eşlemeli G/Ç

Öğrenci sanal belleğin bir avantajını da hatırlattı: paylaşılan bir kütüphane salt okunur (read-only) olarak belleğe yüklenir ve isteyen her prosesin adres uzayına eşlenir (map); böylece herkes onu kullanabilir. Bu, büyük boyutlu bellek nesnelerinin prosesler arasında aktarılmasını da kolaylaştırır.

Makale Accent'teki bellek eşlemeli G/Ç'den (memory mapped I/O) de söz eder. Dosyaları sürekli `read` sistem çağrısıyla okumak yerine dosya belleğe alınıp proseslerin adres uzayına eşlenirse iş kolaylaşır, çünkü diske gidip gelmek zaman alır.

**Soru (hocadan):** Bu durumda program ya da proses diskteki bir yapıya aslında neye erişiyormuş gibi erişir? **Cevap:** Veri diskin üzerindedir ama proses ona RAM'e, yani bellekteki çok büyük boyutlu bir diziye erişiyormuş gibi erişir. Arkada diske okuma ve yazma yapıldığını görmez, bu ayrıntılarla kesinlikle uğraşmaz.

## 5. Memory Object, Portlar ve Kullanıcı Uzayı

Öğrenci Mach'ın bu işi bir adım daha ileri götürdüğünü, aradaki çekirdeği "kaldırdığını" söyledi. Hoca bunun ne anlama geldiğini sordu. Öğrencinin açıklamasına göre memory object'e bir sistem çağrısıyla erişilmez; bir porta istek gönderilir. Orada ilgili sayfa varsa cevap hemen gelir; yoksa sayfa bulunamaz (page miss) ve çekirdek arka planda gidip sayfayı getirir. Sanki elinizde bir tampon vardır, çekirdek onu sürekli doldurur, siz de oradan çekersiniz. Hoca portları, istekleri bekleyen ve istek geldikçe cevap veren arayüzler olarak tanımladı.

### 5.1 Port üzerinden erişimin avantajları

Hoca bu yapının avantajını sordu ve öğrenciyle birlikte iki avantaj ortaya çıktı:

- **Yer saydamlığı:** İstek bir porta gönderildiği için portun arkasındaki hedefin ağda başka bir yerde olmasının bir önemi yoktur.
- **Sistem çağrısından kurtulmak:** Normalde program kullanıcı uzayında (user space), işletim sistemi çekirdek uzayındadır (kernel space). Sistem çağrısında araya bir kesme girer ve bu geçiş zaman kaybıdır. Arka plandaki dosyayı temsil eden bellek eşlemeli nesne, çalışan programla aynı kullanıcı uzayında oluşturulursa, port üzerinden erişim bir fonksiyon çağrısı gibi olur. Arada ne kesme ne başka bir şey vardır; erişim diğerine göre kat kat hızlanır.

Öğrenci buna bir avantaj daha ekledi: çekirdekten o kadar soyutlama konmuştur ki nesne başka proseslere paslanabilir ve onlar da çekirdeğe bağlanmadan aynı veriyi okuyabilir. Hoca bunu onayladı.

### 5.2 Makalenin özü

Hoca bu bölümün sonunda makaleden çıkarılması gerekeni özetledi. Bazı şeyler adres uzayından ve doğrudan çekirdek üzerinden erişilebilir olmaktan çıkarılıp kullanıcı adres uzayına taşındığında ve erişim biçimi portlar üzerinden taşınabilir (portable) hale getirildiğinde, yerel sistemde bir fonksiyon çağrısı yapmak ile uzaktaki bir sisteme ağ üzerinden erişmek aynı soyutlamanın altında toplanır.

> **Hocanın vurgusu:** 20 sayfalık makalenin özü birkaç cümledir: aradaki soyutlamayı koymak; paylaşılan bellekte çözülebilen her problemin paylaşılmayan bellekte bir karşılığı, bir "ikizi" olduğunu ortaya koymak; ama bunun kendiliğinden olmayacağını, bazı sistemsel ve tasarımsal değişiklikler ve kavramsal farklılaşmalar gerektirdiğini göstermek. Nesne yönelimi programlama dillerinde çok konuşulur, ama bunu işletim sisteminde görebilmek, yerel bir erişimi ya da fonksiyon çağrısını ağ üzerinden bir çağrıya dönüştürebilmek önemlidir.

Hoca ayrıca makaledeki sistem çağrısı tablolarına ve örnek kodlara bakmanın, bugün kullanılan bir şeyin ilk nasıl ortaya atıldığını görmek açısından değerli olduğunu, ama oradaki her sistem çağrısını bilmenin anlamı olmadığını söyledi.

## 6. UMA, NUMA ve NORMA

Hoca makaleyle bağlantılı olarak Uniform Memory Access, Non-Uniform Memory Access ve "NORMA" kavramlarını sordu; cevap gelmeyince kendisi açıkladı:

- **UMA (Uniform Memory Access):** Belleğe yerelde erişiliyorsa, herhangi iki prosesin belleğe erişim hızları aynıdır, çok değişmez. Bu, bellek gerçek anlamda paylaşılan bellekse ve özel bir yapısı yoksa geçerlidir.
- **NUMA (Non-Uniform Memory Access):** Yapı paylaşılmayan belleğe taşındığında bazı prosesler kendi yerelindeki belleğe, bazıları ise yerelinde olmayan uzak belleğe erişir. Biri nanosaniyeler mertebesinde, öbürü mikrosaniye, yeri geldiğinde milisaniye mertebesindedir. Bu farkın etkisi vardır.
- **NORMA:** Uzak erişimin hiç olmadığı, erişimin tamamen yerelle kısıtlandığı yapıları ifade eder. Hoca adın İngilizcede bir kadın adı gibi kulağa geldiğini de belirtti.

Hocaya göre bu kavramlar bugün Microsoft Windows'ta, Linux'ta, Unix ve türevlerinde hâlâ kullanılmaktadır; makaleden elde edilecek kazanım budur.

> **Ek bilgi (derste anlatılmadı):** NORMA, "NO Remote Memory Access" ifadesinin kısaltmasıdır. Mach makalesinde bu üç sınıf, büyük olasılıkla Mach'ın hedeflediği çok işlemcili donanım türlerini (UMA paylaşılan bellekli makineler, NUMA makineler ve ağla bağlı NORMA makineler) ayırmak için kullanılır.

## 7. Program, Proses ve Thread

İkinci makaleye geçerken hoca "first class user level thread" ifadesinin ne demek olduğunu sordu ve "first class"ın günlük hayattaki birinci sınıf uçak bileti ya da birinci sınıf oturma yeri gibi bir anlamda kullanıldığını söyledi. Bir öğrenci önce thread'lerin daha önce nasıl uygulandığına bakmak gerektiğini, ilk uygulamalarda thread'lerin çekirdek tarafındaki proseslere bağlandığını, bunun için sistem çağrısı gerektiğini ve thread'lerin başlatılmasını yavaşlattığını söyledi. Hoca daha açık bir anlatım istedi. Bunun üzerine kavramsal bir karışıklık ortaya çıktı ve hoca önce program, proses ve thread ilişkisini düzeltti.

### 7.1 Kavram düzeltmeleri

Tartışmada bir öğrencinin ifadeleri sırayla şöyle düzeltildi:

- "Task, altında proseslerin olduğu şeydir." Hoca: Hayır. Task, günümüz açısından prosesin kendisidir; task'ın modernize edilmiş adı prosestir. Eskiden programın büyüklüğüne ve bellekte kapladığı yere göre başka adlar da verilmişti, ama modern işletim sistemleri terminolojisinde buna proses denir.
- "Programlar birden çok prosesten oluşur." Hoca: Hayır. Bir program bir prosesten oluşur.
- "Çocuk prosesleri de olabilir." Hoca: O çocuk prosestir. Her çocuk proses bir programla ilişkilendirilir. Birden fazla proses aynı programla ilişkilendirilmiş olabilir ama her biri farklı bir kopyadır. Buna karşılık bir proses yalnız bir programla ilişkilendirilebilir.
- "Program birden çok işlemcide verimli çalışsın diye proseslere bölünür." Hoca: Hayır, proseslere bölmüyoruz; burada kavramsal bir sorun var.

### 7.2 Thread'in yeri: kelime işlemci örneği

Hoca, programı çalışır hale getirmek için belleğe (tamamını ya da bir parçasını) almak gerektiğini, program ilerlerken dosyalara, başka proseslere, ağa erişebileceğini, bunların her birinin işletim sisteminin yönettiği bir kaynak olduğunu ve kaydının tutulması gerektiğini hatırlattı. Bunların hepsine bir bütün olarak verilen ad task, bugünkü adıyla prosestir.

Ancak bir program kendi içinde birbiriyle ilintili ama eş zamanlı ve bağımsız çalışabilen parçalardan da oluşabilir. Bu parçaların birbiriyle ilintili olması gerekir, çünkü aynı programın parçasıdırlar; iki farklı amaca yönelik şeyi aynı programın altına koymak mantıksız olur. Hocanın örneği bir kelime işlemcidir: kullanıcı sağ tuşa basıp "düzelt" dediğinde yapılan düzeltme sıralı (sequential) bir akıştır, kullanıcının tetiklediği bir iştir. Oysa kullanıcı tuşlara basıp kelime yazarken programın içinde arka planda bir parça daha çalışır ve yazım hatalarını kendiliğinden düzeltir. Telefondaki mesajlaşma uygulamalarında ve SMS yazarken çalışan otomatik düzeltme ya da metni hizalayan mekanizma da aynı şeydir.

Demek ki bir programın içinde farklı parçalar aynı anda aktif olabilir ve bu parçaların da ifade edilip izlenmesi gerekir. Bu izleme thread yapısıyla yapılır. Task da bir veri yapısıdır, thread de bir veri yapısıdır. Bir programın içinde birbiriyle ilintili, aynı programın parçası olan ve eş zamanlı çalışabilen thread'ler olabilir.

## 8. Kernel Seviyesi ve Kullanıcı Seviyesi Thread'ler

Hoca konuyu bir dizi soruyla ilerletti.

**Soru:** İşlemciyi kullanma ve kullandırma yetkisi kimdedir? **Cevap:** İşletim sistemindedir. İşletim sisteminin haberi olmadan işlemci hiçbir program akışı için kullanılamaz.

İşletim sistemi yalnız proseslerden haberdarsa işlemciyi yalnız prosese tahsis edebilir. Ama prosesin içinde alt parçalar aktif olacaktır; belki o anda eş zamanlı çalışması gereken üç alt parça vardır.

**Soru:** Bu parçaların aktif olabilmesi için hangi seviyede tanınmaları gerekir? **Cevap:** Çekirdek (kernel) seviyesinde. Standart thread tasarımı bunun üzerine kurulur: task ya da proses kaynak tahsisinin tutulduğu büyük yapıdır, içindeki aktif çalışabilen parçalar da thread'lerdir. İşletim sistemi programı çalıştırmak için prosesi, alt parçaların eş zamanlı çalışabilmesi için de thread'leri tanımak zorundadır.

**Soru:** İşletim sistemine girmek, onun dikkatini çekmek neyle gerçekleşir? **Cevap:** Sistem çağrılarıyla, yani kesmeyle (interrupt).

Her kesme bir duraksama ve yavaşlamadır. Aynı programın içinde ortak bir amaç için çalışan iki farklı eş zamanlı parçayı çalıştırabilmek için her seferinde çekirdeğe girilip çıkılması gerekir; bu bir zaman kaybıdır. Yine de ilk düşünülen standart çözüm budur: **kernel level thread'ler**.

Daha sonra şu düşünülür: Mach'ta bazı şeyler kullanıcı uzayına taşınmıştı; thread'ler de kullanıcı uzayına taşınamaz mı, nasıl taşınabilir ve taşındığında ne sorun çıkar? Sorun şudur: işletim sistemi thread'i tanımayacak, yalnız prosesi tanıyacak ve zamanı prosese verecektir. Prosese verilen zamanın içindeki iki, üç ya da dört thread arasında paylaştırılması gerekir. Ama işlemcinin kontrolünü yapan yer işletim sisteminin kendisidir; işletim sisteminin haberi olmadan işlemciyi bir thread'den alıp diğerine vermek bir problemdir. Hocaya göre bunun çözümü vardır, ama kernel thread'lerden farklı bir biçimde; bu çözümle **user level thread** kavramı ortaya çıkar.

## 9. First-Class User-Level Threads ve Psyche

### 9.1 "First class status" ne demek?

Hoca makalenin özetinin ikinci paragrafını okudu: yazarlar, kullanıcı seviyesi thread'lere birinci sınıf statü vermek için tasarlanmış bir dizi çekirdek mekanizmasını ve kuralını (conventions) anlatırlar ("We describe a set of kernel mechanisms ... designed to accord first class status to user level threads"). "Accord" burada bir şeye bir statüyü vermek, "artık sen busun" diyebilmek anlamındadır.

First class statü şunu ifade eder: thread'ler çekirdekteyken işler nasıl gerçekleşiyorsa, kullanıcı seviyesinde de benzer biçimde gerçekleşmelidir. Performans açısından daha yüksek, ama esneklik ve kullanılabilirlik açısından kullanıcıyı zorlamayan, alışık olduğu sıradan biçimde kullanmasını sağlayan mekanizmalar ve kurallar ortaya konur ve bunların kavram kanıtı (proof of concept) uygulaması yapılır. Böylece kullanıcı seviyesi thread'ler, çekirdeğin tanıdığı thread'lerin her türlü ayrıcalığına sahipmiş gibi olur. Programcı da "kernel level thread kullanacağıma, daha yüksek performans, daha düşük gecikme ve daha az ek kaynak kullanımı için user level thread kullanırım" diyebilir.

Kullanıcı seviyesi thread'lerin kernel thread'lerle karşılaştırıldığında bilinen standart sorunları vardır; first class statü için bunların önüne geçilmesi gerekir. Makale bunun için neler yapıldığını anlatır.

### 9.2 Paylaşılan çekirdek ve kullanıcı veri yapıları

Hoca makalenin Şekil 1'ini ("Shared kernel and user data structures in Psyche") sözlü olarak tarif etti. Şekilde bir yanda çekirdek verisi (kernel data), öbür yanda kullanıcı verisi (user data) vardır. Sözde yazmaçlar (pseudo-registers) asıl yazmaçlara denk düşen ama onların bilgisinin aynalanmış halini tutan yapılardır. Altta sanal işlemci (virtual processor), fiziksel işlemci (physical processor) ve adres uzayı (address space) bulunur.

<!-- BELİRSİZ: Şekil ekranda gösterilmedi; kutuların yerleşimi ve aralarındaki oklar sözlü anlatımdan çıkarılamadı. -->

Çekirdek doğrudan işlemciyle muhatap olur; işlemci de donanımın merkezindeki parçadır. İşlemciye kesmeler gelir: diske, ağa ya da yazıcıya yapılan G/Ç tamamlandı, bir hata oluştu, zaman aşımı oldu, dış bir kesme geldi gibi. Psyche bunları sanal işlemci mantığıyla yukarıya taşır, yani kullanıcı uzayında bir sanal işlemci oluşturur. Hoca bunun paravirtualization'ın başlangıcı, temeli gibi düşünülebileceğini söyledi: her komutu kullanıcı seviyesinde taklit etmek yerine, alttaki fiziksel işlemcide gerçekleşen olaylar üst tarafa yansıtılır. Prosesin içindeki parçalar bu sanal işlemciyi muhatap alır.

> **Ek bilgi (derste anlatılmadı):** Paravirtualization, konuk işletim sisteminin sanallaştırıldığını bilerek donanımı birebir taklit eden bir katman yerine hipervizörün sunduğu özel arayüzü (hiper çağrılar) kullandığı sanallaştırma yaklaşımıdır. Tam taklide göre daha az ek yük getirir.

### 9.3 Yazılım kesmeleri

Donanımda gerçekleşen olaylar ve kesmeler üst tarafta yazılım kesmelerine (software interrupts) dönüştürülür. Hoca makaledeki listeyi ("The following is a partial list of software interrupts in Psyche") okuyup her birini açıkladı:

- **Virtual processor initialization (sanal işlemcinin başlatılması):** Fiziksel işlemciye reset sinyali uygulanınca işlemci sıfırlanır ve belirli bir adresteki ilk komutu çalıştırır. Sanal işlemcinin de böyle bir başlatma sırası olmalı, bir yerden bir şey başlatmalıdır.
- **Thread blocked in the kernel (thread'in çekirdekte bloke olması):** Çekirdekte bir thread bloke oluyorsa bunun yukarıya yazılım kesmesiyle (trap) aktarılması gerekir, ama normal bir fiziksel kesmenin yavaşlığı ve gecikmesiyle değil.
- **Thread unblocked in kernel (thread'in çekirdekte blokajdan çıkması):** Çekirdekte blokajı kalkan thread yukarıda da devam edebilmelidir.
- **Signal from another virtual processor (başka bir sanal işlemciden sinyal):** Sanal işlemci bir thread'in çalışmasını sağlar; bir thread başka bir thread'le konuşacaksa bu gerekir. Hocanın örneğinde klavyede boşluk tuşuna basılınca bir kelime tamamlanmış olur ve öbür parçanın otomatik düzeltmeyi yapması gerekir.
- **Timer expiry (zamanlayıcının dolması):** Belirli bir sürenin geçtiğinden emin olmak için; örneğin bir işin belirli aralıklarla yapılması ya da araya girmemesi için.
- **Imminent preemption (yakın önalım):** İşlemciyi o thread'den hemen çekip başkasına tahsis etmek gerekebilir, çünkü daha yüksek öncelikli bir iş gelmiştir ya da çok özel bir durum oluşmuştur.
- **Program fault (program hatası):** Örneğin girdi yüzünden sıfıra bölmeye kalkmak (division by zero) ya da erişilmemesi gereken bir belleğe erişmek. Donanımda işlemci bunu yapsaydı bir donanım kesmesi oluşurdu. Yukarıda, yazılım seviyesinde bunu bu kadar ayrıntılı yapmaya gerek yoktur; yalnız hatanın oluştuğu ve türü bildirilir, devam edilir.

### 9.4 Makalenin özü

Hocanın özetine göre makalenin özünde şu yatar: fiziksel işlemciyi doğrudan muhatap alan ve onun etrafında kurulan kernel level thread'lerin sahip olduğu özellikleri kullanıcı uzayında uygulanan user level thread'lere taşımak. Kullanıcı seviyesi thread'ler kernel thread'leri gibi benzer kıvraklıkta, benzer yetenekte ve benzer kullanım kolaylığında olmalıdır. Kullanıcı bundan hiç etkilenmemeli; "bu kullanıcı seviyesi thread miydi, şunu mu çağıracaktım?" diye düşünmeden, kernel thread'i nasıl kullanıyorsa ve onun programlanması için hangi yapıyı öngörüyorsa aynısını değişiklik olmadan kullanıcı seviyesi thread'lere de uygulayabilmelidir. "First class"tan anlaşılan budur. Hoca bu makalenin Mach makalesine göre çok daha kısa olduğunu da belirtti.

## Örnek Sorular

Bu derste ekranda soru gösterilmedi; aşağıdaki sorular hocanın derste sözlü sorduğu sorulardır.

**Soru 1** (derste sözlü, 00:09:37): Mach makalesinin adındaki "duality" bu bağlamda ne anlama gelir?

> **Cevap (derste verildi):** Çok işlemcili sistemler paylaşılan bellekli (sıkı bağlı) ve paylaşılmayan bellekli (gevşek bağlı) olarak ikiye ayrılır. Duality, paylaşılan bellekli sistemde çözümü olan bir problemin paylaşılmayan bellekli sistemde de bir karşılığı olması demektir. Mach bellek erişimi ile haberleşme üzerinden erişimin semantiğini eşitleyerek ikisini birbirinin yerine geçebilen eşdeğer parçalar olarak ele alır.

**Soru 2** (derste sözlü, 00:20:10): Mach makalesine göre task ile thread arasındaki fark nedir?

> **Cevap (derste verildi):** Task kaynak tahsisinin temel birimidir (bellek, kod ve veri alanı, dosyalar, ağ gibi kaynakların kaydı); bugünkü adıyla prosestir. Thread hesaplamanın, daha genel adıyla yürütmenin temel birimidir; task içindeki akışı gösterir. Aynı task'taki thread'lerin kendi yazmaçları ve yığınları vardır, adres uzayları ortaktır.

**Soru 3** (derste sözlü, 00:29:50): Bellek eşlemeli bir dosyada proses, diskteki veriye neye erişiyormuş gibi erişir? Arkadaki disk işlemlerini görür mü?

> **Cevap (derste verildi):** Bellekteki çok büyük boyutlu bir diziye erişiyormuş gibi erişir. Diske okuma ve yazma yapıldığını görmez, bu ayrıntılarla uğraşmaz.

**Soru 4** (derste sözlü, 00:31:35 ve 00:32:22): Memory object'e sistem çağrısı yerine port üzerinden erişmenin avantajları nelerdir? Nesnenin kullanıcı uzayında oluşturulması neyi değiştirir?

> **Cevap (derste verildi):** Port arkasındaki hedefin yerel ya da ağda başka bir makinede olması fark etmez. Nesne çalışan programla aynı kullanıcı uzayında oluşturulursa kullanıcı-çekirdek geçişi ve kesme ortadan kalkar; erişim bir fonksiyon çağrısı gibi olur ve kat kat hızlanır. Nesne paslanabilir ve başka prosesler çekirdeğe gitmeden aynı veriyi okuyabilir.

**Soru 5** (derste sözlü, 00:34:42): Uniform Memory Access, Non-Uniform Memory Access ve NORMA ne demektir?

> **Cevap (derste verildi):** UMA'da (gerçek paylaşılan bellekte) iki prosesin belleğe erişim hızı aynıdır. NUMA'da bazı prosesler yerel belleğe nanosaniyeler, bazıları uzak belleğe mikrosaniye ya da milisaniye mertebesinde erişir. NORMA, uzak bellek erişiminin hiç olmadığı, erişimin tamamen yerelle sınırlı olduğu yapıları ifade eder.

**Soru 6** (derste sözlü, 00:57:20 ve 00:58:04): İşlemciyi kullandırma yetkisi kimdedir ve bir prosesin içindeki parçaların eş zamanlı çalışabilmesi için bu parçaların hangi seviyede tanınması gerekir?

> **Cevap (derste verildi):** Yetki işletim sistemindedir; onun haberi olmadan işlemci hiçbir akış için kullanılamaz. İşletim sistemi yalnız prosesi tanırsa işlemciyi yalnız prosese verebilir; parçaların eş zamanlı çalışabilmesi için thread'lerin çekirdek seviyesinde tanınması gerekir (kernel level thread).

**Soru 7** (derste sözlü, 00:58:53): İşletim sistemine girmek neyle gerçekleşir ve bunun kernel level thread'ler açısından bedeli nedir?

> **Cevap (derste verildi):** Sistem çağrısıyla, yani kesmeyle. Her kesme bir duraksama ve yavaşlamadır; aynı programın eş zamanlı parçalarını çalıştırmak için her seferinde çekirdeğe girip çıkmak zaman kaybıdır.

**Soru 8** (derste sözlü, 00:59:54): Thread'ler kullanıcı uzayına taşındığında ortaya çıkan sorun nedir?

> **Cevap (derste verildi):** İşletim sistemi thread'leri tanımaz, yalnız prosesi tanır ve zamanı prosese verir. Bu zamanın proses içindeki thread'ler arasında paylaştırılması gerekir, ama işlemcinin kontrolü işletim sistemindedir; onun haberi olmadan işlemciyi bir thread'den diğerine aktarmak problemdir.

**Soru 9** (derste sözlü, 00:49:38 ve 01:01:27): "First class user level thread" ne demektir?

> **Cevap (derste verildi):** Çekirdek mekanizmaları ve kurallar yoluyla kullanıcı seviyesi thread'lerin kernel thread'lerinin bütün yeteneklerine sahipmiş gibi davranmasıdır. Programcı kernel thread'i nasıl kullanıyorsa kullanıcı seviyesi thread'i de değişiklik olmadan öyle kullanır; buna karşılık daha yüksek performans, daha düşük gecikme ve daha az ek kaynak elde edilir. Psyche'de bu, kullanıcı uzayındaki sanal işlemci, paylaşılan çekirdek-kullanıcı veri yapıları ve donanım olaylarının yazılım kesmelerine dönüştürülmesiyle sağlanır.

## Dersin Toparlaması

Ders, çok işlemcili işletim sistemlerini iki makale üzerinden ele aldı. Mach makalesi, paylaşılan bellekli ve paylaşılmayan bellekli sistemler arasındaki ikiliği, bellek erişimi ile haberleşmenin semantiğini eşitleyen soyutlamalarla (task, thread, port, message, memory object) kurar. Bellek eşlemeli nesnelere port üzerinden erişim, hedefin yerini önemsizleştirir; nesne kullanıcı uzayında oluşturulduğunda erişim bir sistem çağrısı yerine fonksiyon çağrısı hızına iner. UMA, NUMA ve NORMA kavramları bu ikiliğin bellek erişim süresine yansımasını adlandırır.

İkinci makale aynı "kullanıcı uzayına taşıma" fikrini thread'lere uygular. Task kaynak tahsisinin, thread yürütmenin birimidir; kernel thread'ler çekirdekçe tanınır ama her geçiş kesme maliyeti taşır, kullanıcı seviyesi thread'ler hızlıdır ama çekirdekçe tanınmaz. Psyche, sanal işlemci ve yazılım kesmeleriyle kullanıcı seviyesi thread'lere kernel thread'lerinin yeteneklerini kazandırarak onları "birinci sınıf" yapar. Hoca, öğrencilerin bu iki makaleye bu bakış açısıyla bir kez daha, daha ayrıntılı bakmasını istedi; sonraki derste makalelerin can alıcı noktaları üzerine sorular soracağını söyledi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
