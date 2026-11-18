# Ders 4 Genişletilmiş Notu: Prosesler: Proses Kavramı, Durumlar, PCB, Zamanlama, Proses Oluşturma ve Sonlandırma; Kabuk Programlama Uygulaması

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Proses Yönetimine Giriş
- 2. Proses Kavramı
- 3. Prosesin Bellekteki Yerleşimi
- 4. Proses Durum Modelleri
- 5. Proses Kontrol Bloğu (PCB)
- 6. Prosesler Arası Geçiş ve Thread'lere Kısa Bakış
- 7. Proses Zamanlama ve Kuyruklar
- 8. Scheduler Türleri
- 9. Bağlam Değişimi (Context Switch)
- 10. Proses Oluşturma
- 11. fork, exec ve wait Örnekleri
- 12. Proses Sonlandırma, Zombi ve Yetim Prosesler
- 13. Uygulama: Kabuk Komutları ve Kabuk Programlama
- Örnek Sorular
- Dersin Toparlaması

## 1. Proses Yönetimine Giriş

Hoca bu dersten itibaren yaklaşık yedi sekiz hafta boyunca işletim sisteminin en çok üzerinde durduğu konu olan proses yönetimine (process management) bakılacağını söyledi. Kullanılan slaytlar dersin ana kitabının (Silberschatz, Galvin ve Gagne, *Operating System Concepts*) slaytlarıdır. Hoca diğer iki kaynağın da takip edilmesini, bazı konuların orada daha iyi açıklanmış olabileceğini ve zaman zaman oradan alıntı yapacağını belirtti.

Önceki derslerde işletim sistemi bir kontrol ve koordinasyon sistemi olarak tanımlanmıştı. Kontrol ve koordine edilmesi gereken en önemli kaynaklardan biri işlemcidir. İşlemci proseslere yeri geldiğinde tahsis edilir (allocation), yeri geldiğinde geri alınır (deallocation). Bu bölümün başlıkları proses kavramı, proses zamanlama, prosesler üzerindeki işlemler ve prosesler arası haberleşmedir. Bu derste ilk üç başlık işlendi.

## 2. Proses Kavramı

İşletim sistemi çeşitli programları yürütebilir (execute). Sistem batch (toplu işlem) sistemiyse yürütülen işlere **job** denir; zaman paylaşımlı bir sistemde ise **user program** ya da **task** denir. Batch sistemlerin özelliği, başlatılan bir işin yarıda kesilememesidir. Günümüzde, özellikle kişisel bilgisayarlarda, etkileşim (interaktivite) önemli olduğu için zaman paylaşımlı sistemler kullanılır; etkileşimli olmak aynı anda birden fazla programın ya da prosesin çalışabilmesi demektir. Kitaplar job, proses ve program kavramlarını birbirinin yerine kullanabilir; aralarında kavramsal farklar olsa da derste "proses" kavramı kullanılacaktır.

C dilinde bir program yazdığımızı düşünelim. Program önce derlenir; derleme tek bir adım değildir: önce derleme (compile), sonra bağlama (link) yapılır ve sonunda çalıştırılabilir (executable) bir dosya oluşur. Bu dosya diskte duran **pasif bir varlıktır**. Üzerine çift tıklayarak ya da komut satırından çalıştırdığımızda program yürütülmeye başlar. Programın bu yürütülme hâline **proses** denir. Satır satır akan bu akışa yürütme akışı (execution flow) denir.

Program proses hâline geldiğinde işletim sistemi onu ve diğer proseslerle ilişkisini kontrol edebilmek için bazı bilgiler tutmalıdır; önceki derslerde muhasebe (accounting) ve güvenlik gibi rollerden söz edilmişti. Örneğin her prosesin bir kimliği (ID) olmalıdır; gerektiğinde proses bu kimlikle öldürülür (kill) ya da bellek uzayıyla ilgili kontroller yapılır.

Bir program birden fazla proses içerebilir. Word programını birden fazla kez çalıştırabiliriz; bu durumda birden fazla proses çalışır. Tek bir tıklamayla da birden fazla proses başlayabilir. Hoca görev yöneticisini açıp bir web tarayıcısını gösterdi: tek bir tarayıcı penceresi açık olduğu hâlde arka planda aynı adlı çok sayıda proses çalışıyordu. Bir tarayıcının bütün işini tek bir prosese yüklemek zordur; bu yüzden birden fazla proses çalışır, bunlar kendi aralarında haberleşir ve senkronize olur. Bu proseslerin altında da ileride görülecek thread'ler vardır.

Executable dosya belleğe yüklendiğinde program proses hâline gelir. Bu, fareyle tıklayarak, komut satırında `ls` gibi bir komutla ya da kendi yazdığımız bir programı çağırarak olabilir. Hoca derleyici örneğini verdi: `gcc` ile derleme yaptığımızda derleyicinin kendisi de derleme yapabilmek için bir proses hâline gelir.

## 3. Prosesin Bellekteki Yerleşimi

Bellekte işletim sisteminin bir yeri vardır; bir prosese de bir bellek bölgesi verilir ve bu bölgenin sınırları prosesle (PID ile) ilişkilendirilir. Bunun ayrıntısı bellek yönetimi konusunda görülecektir. Bu bölge kendi içinde bölümlere ayrılır. Slayttaki şemada (ekrandan, 00:20:00) adres 0'dan max'a doğru şu bölümler vardır:

```text
max  +-----------+
     |   stack   |   (aşağı doğru büyür)
     |     |     |
     |     v     |
     |           |
     |     ^     |
     |     |     |
     |   heap    |   (yukarı doğru büyür)
     +-----------+
     |   data    |
     +-----------+
     |   text    |
0    +-----------+
```

- **Text bölümü (kod segmenti):** Programın makine (assembly) kodu karşılığı burada tutulur.
- **Register'lar ve program sayacı:** Proses işlemciye girer, yürütülür, belli zamanlarda işlemciden çıkarılıp tekrar dönmek üzere bekletilir. Program bitmediği için program sayacı (program counter), program durum sözcüğü (PSW) ve carry, borrow, overflow, zero gibi bayrak (flag) register'ları ile diğer register değerlerinin yedeklenmesi gerekir. Bunlar prosesin anlık etkinliğiyle (current activity) ilgilidir.
- **Stack:** Yerel değişkenler (`int a, b, c` gibi), sabit uzunluklu diziler (hoca burada `static` anahtar sözcüğünü değil, 10 ya da 20 elemanlı sabit boyutlu dizileri kastettiğini belirtti), fonksiyon parametreleri ve dönüş adresleri stack'te tutulur. Program açılınca `main` etkinleşir; `main`'den bir fonksiyon çağrıldığında o anki satır bilgisi ve değişkenlerin değerleri stack'e atılır, fonksiyon çalışır; iç içe çağrılarda bu böyle devam eder.
- **Data bölümü:** Global ve statik değişkenler ile `main`'in parametreleri (`argc`, `argv` gibi komut satırı parametreleri) ve ortam değişkenleri (environment variables) burada tutulur. Hoca global değişkenlerin neden ayrı bir yerde tutulduğunu sordu ve bu konuya senkronizasyon konusunda ayrıntılı dönüleceğini söyledi.
- **Heap:** Çalışma zamanında dinamik olarak ayrılan bellek bölgeleri burada tutulur.

Bu bölümlerin birbirinden ayrı ve yalıtılmış tutulmasının nedeni, prosesin yönetimini kolaylaştırmak ve program işleyişinin birbirine karışmamasını sağlamaktır; stack'teki veriler kendi mantığıyla, heap'tekiler başka bir mantıkla saklanır.

Stack yüksek adresten (max) aşağı doğru, heap ise yukarı doğru dolar. Hoca bunu C'de denemeyi önerdi: `main` içinde önce `a`, sonra `b` tanımlanıp adresleri `%p` ile yazdırılırsa `a`'nın adresinin `b`'ninkinden büyük olduğu görülür. Benzer biçimde sabit bir dizinin elemanlarının adresleri azalarak değişir. `malloc` ile on elemanlı bir alan alınıp elemanlarına bakıldığında ise adresler artarak gider.

Özyinelemeli (recursive) bir fonksiyon kendini durmadan çağırırsa stack dolmaya başlar ve bir yerden sonra program durdurulur: **stack overflow** hatası alınır. Bu, stack bölgesinin heap bölgesine baskı yapması, onun sınırına girmesi demektir. İşletim sistemi bunu kontrol ettiği için heap bölgesine müdahaleye izin vermez ve programı sonlandırır.

> **Ders sonrası not:** Hoca stack ve heap'in büyüme yönünü "big endian, little endian" kavramlarıyla ilişkilendirdi ve bunun mikroişlemci mimarisine göre değiştiğini söyledi. Big endian ve little endian çok baytlı bir değerin baytlarının bellekte hangi sırayla dizildiğini anlatır; stack'in büyüme yönüyle ilgisi yoktur. Stack'in yönü büyük olasılıkla mimariye ve çağrı kurallarına bağlıdır (x86'da aşağı doğru büyür).

## 4. Proses Durum Modelleri

Hoca ilk derste anlatılan komut döngüsünü (instruction cycle) hatırlattı: Bir komut CPU'ya gelir, çözülür (decode), varsa işlenenleri (operand) bellekten getirilir, komut yürütülür ve sıradaki komuta geçilir. Ama bir proses işlemciye bir kez girip bitene kadar orada kalamaz; başka prosesler de çalıştığı için biri çıkarılır, diğeri alınır. Bu yüzden prosesin farklı durumlarda olabilmesi gerekir.

### 4.1 İki durumlu model

Proses ya bellektedir ya da CPU'dadır. Bellekteyse yürütülmüyordur, CPU'daysa yürütülüyordur. Buna iki durumlu proses modeli denir. Hoca bu modele ana kitabın slaytlarında doğrudan yer verilmediğini, diğer kitaplarda ayrıntılı anlatıldığını söyledi. Theory of Computation dersindeki durum makinelerine benzer biçimde P0 ve P1 diye iki durum düşünülebilir: biri waiting, diğeri running. Running durumdaki proses işlemcidedir, waiting durumdaki bellekte bekler.

### 4.2 Üç durumlu model

Zamanla gereksinimler değişti (araya önbellek gibi yapılar eklendi) ve proseslerin G/Ç (giriş/çıkış) yapması gerekti. G/Ç yapan bir proses ne running ne de waiting durumunda olmalıdır; bu yüzden üçüncü bir durum eklendi. Running ile waiting arasında iki yönlü geçiş olabilir: bellekte bekleyen prosese işletim sistemi "hadi sen biraz çalış" diyebilir. Running durumundayken bir G/Ç isteği olursa proses G/Ç durumuna geçer. G/Ç bitince ilk modellemede önce waiting durumuna, sonra running durumuna gidilmesi öngörüldü. Waiting durumundan G/Ç durumuna ise geçilemez: Program bellekte duruyor ve yürütülmüyorsa `printf` mi `scanf` mi yapacağı bilinemez; yürütülmeyen bir şeyin G/Ç isteği olamaz.

### 4.3 Beş durumlu model

Bilgisayar mimarileri değiştikçe durum olasılıkları da gelişti. Günümüzde temel alınan beş durumlu modeldir; ama Windows ve UNIX gibi gerçek sistemler bu modeli birebir kullanmaz, tasarımcılar yeni olasılıkları dikkate alarak ek durumlar tanımlamıştır. Hoca bunu deterministik olmayan sonlu otomatlara (NFA) benzetti: Her durumdan her duruma geçiş tanımlamak zorunda değiliz; işletim sistemi istatistik tuttuğu için bazı durumlar bu mantıkla zaman içinde eklenmiştir. NFA'nın C ile basit bir kodlamasını internette aramayı önerdi.

Beş durum şunlardır:

- **New:** Proses oluşturuluyor; belleğe ilk yüklendiği an.
- **Ready:** Proses CPU'ya atanmayı bekliyor.
- **Running:** Komutları yürütülüyor.
- **Waiting:** Proses bir olayın (G/Ç, kesme vb.) gerçekleşmesini bekliyor.
- **Terminated:** Prosesin yürütmesi bitti; işlemci ve belki bellek prosesten alınır.

Ready durumunun neden gerektiğini hoca şöyle açıkladı: İşlemci belleğe göre çok hızlıdır. Prosesleri tek tek bellekten getirip işlemciye koymayı düşünürsek, bellekten gelene kadar geçen sürenin belki binde biri kadar sürede işlemci bir başka prosesi zaten işleyebilir. Bu yüzden yürütülecek prosesler önceden bir kuyrukta hazır tutulur: "önce P1, sonra P2 girsin." Hoca bunu kırmızı ışıktan yeşile geçmiş, gaza basmak üzere bekleyen sürücüye benzetti.

Slayttaki durum diyagramı (ekrandan, 00:30:00) şöyledir:

```text
new --admitted--> ready --scheduler dispatch--> running --exit--> terminated
                  ready <------interrupt------- running
                  running --I/O or event wait--> waiting
                  waiting --I/O or event completion--> ready
```

Geçişler:

- New durumundaki proses belleğe gelmiş, kabul edilmiştir (admitted) ve ready durumuna geçer. Sıfırıncı satırdan başlatılacağı için çalışmaya hazır hâle getirilir; new durumundan yalnız ready durumuna geçiş vardır.
- Ready durumundaki proses scheduler tarafından CPU'ya gönderilir (scheduler dispatch).
- Running durumundaki proses bir kesmeyle ("sen çok durdun, artık çık") ready durumuna dönebilir.
- Program tamamlanırsa terminated durumuna geçer.
- Yürütme sırasında `printf`, `scanf`, dosyaya yazma ya da dosyadan okuma gibi bir G/Ç ya da bekleme ihtiyacı olursa waiting durumuna geçer.
- Bekleme bitince proses doğrudan running'e değil, ready kuyruğuna gider. Ready'de bir kuyruk veri yapısı kullanılır; birden fazla proses hazırsa hangisinin işlemciyi kullanacağına bu kuyruk üzerinden karar verilir. Şimdilik ilk gelen ilk hizmet alır mantığıyla tek kuyruk düşünülebilir; birden fazla kuyruk olabileceği scheduling konusunda görülecek.

**Soru:** (anlaşılamayan bir soru üzerine) Birden fazla kuyruk olabilir mi? **Cevap:** Şu an tek kuyruk gibi düşünülmeli; birden fazla kuyruk olabilir ve bu scheduling konusunda ele alınacak.

## 5. Proses Kontrol Bloğu (PCB)

Her prosesle ilgili bilgilerin saklandığı veri yapısına **proses kontrol bloğu** (process control block, PCB) denir. Hoca bir durum makinesini kodlarken durumları bir değişkende saklamamız gerektiği gibi, prosesin durumunun da bir yerde tutulması gerektiğini söyledi. PCB'de şunlar bulunur:

- **Proses durumu (process state):** New, ready, running gibi.
- **Proses numarası (PID):** Prosesi sonlandırmak ya da başka işlemler yapmak için.
- **Program sayacı:** Proses çalıştı, işlemciden çıktı ve belleğe yedeklendi; program sayacının hızlıca yerine konması gerektiği için ayrıca saklanır.
- **CPU register'ları:** Prosesin register'larının son durumu.
- **CPU zamanlama bilgisi:** Prosesin önceliği, hangi kuyrukta tutulacağı gibi bilgiler.
- **Bellek yönetimi bilgisi:** Proses hangi bellek bölgelerinde saklanıyor. Hoca şimdilik tek bir bölge çizildiğini, ama bellek yönetimi konusunda bir prosesin parçalara (sayfalara, page) bölündüğünü, bir kısmının bellekte bir kısmının diskte olabileceğini ve bu yüzden bu bölgelerin ayrı ayrı tutulması gerektiğini anlattı.
- **G/Ç durum bilgisi:** Prosese verilen dosya izinleri ve G/Ç tanımlayıcıları (file descriptor): hangisi açık, hangisi kullanılıyor, hangisi kapalı.
- **Muhasebe bilgisi (accounting information):** CPU'nun ne kadar kullanıldığı, başlangıçtan bu yana geçen süre, prosese verilebilecek zaman sınırları.

PCB nerede tutulmalıdır: işlemcide mi, ana bellekte mi, diskte mi? Bir şeye proses diyorsak ana bellekte, çalışabilir durumda olmalıdır. PCB de genellikle ana bellekte tutulur; program sayacı gibi bilgilere hızlı erişmek gerekir ve diske gidip gelmek çok zaman alır. Bellek yönetimi konusunda prosesin bazı kısımlarının sanal bellek (virtual memory) için diskte (HDD, SSD) saklanabileceği görülecek; ama çoğunlukla PCB'nin ana bellekte olduğunu bilmek yeterlidir.

Hoca multi-tasking, multi-processing, multi-threading ve multi-programming kavramlarını ve aralarındaki farkları okumamızı istedi.

## 6. Prosesler Arası Geçiş ve Thread'lere Kısa Bakış

### 6.1 Bir prosesten diğerine geçiş

İki proses düşünelim: P0 ve P1 (bu sayı 2 de 22 de olabilir, "çok" diye düşünülmelidir). Tek bir CPU çekirdeği varsa bir proses CPU'dan çıkacak, diğeri girecektir. Çok çekirdekli bir sistemde de her çekirdek için aynı şey geçerlidir.

Bir prosesin işlemciden çıkarılması prosesin kendisinden ya da dışarıdan kaynaklanabilir. Prosesin kendisinden kaynaklanan nedenler: sıfıra bölme (divide by zero) gibi bir istisna (exception) ya da bir G/Ç isteği; bu durumda proses bir kesmeyle işlemciden çıkarılır. Dışarıdan kaynaklanan neden: prosese ayrılan işlemci kullanım süresi dolmuştur ve işletim sistemi "sen çık, yerine başkasını alacağım" der. Genellikle bu bir kesmeyle olur.

Slayttaki şemada (ekrandan, 00:40:00) P0 yürütülürken bir kesme ya da sistem çağrısı gelir. İşletim sistemi P0'ın durumunu (register'lar, program sayacı) PCB0'a kaydeder; PCB0 ana bellekte saklanır. Ardından PCB1'den P1'in durumunu yükler; register bilgileri ve program sayacı işlemciye alınır. Bu bir hazırlık aşamasıdır; bu sırada P0 boştadır (idle). Sonra P1 yürütülür. Bir süre sonra P1 için bir kesme ya da sistem çağrısı gelir; P1'in durumu PCB1'e kaydedilir, PCB0 yeniden yüklenir ve P0 yürütülmeye devam eder. Bu, N proses arasında tek bir işlemcinin paylaşılmasına genelleştirilebilir.

### 6.2 Thread'ler

Şu ana kadar her prosesin tek bir yürütme akışı olduğu varsayıldı: `main`'den başlayıp `return 0`'a kadar giden tek bir akış. Günümüz uygulamalarında bazı görevlerin (task) eş zamanlı çalışabilmesi gerekir; çünkü bilgisayarlarda çekirdek sayısı arttı ve işin bir kısmı paralelleştirilebilir. Örneğin bir fonksiyonun önce birinci veri, sonra ikinci veri için çalışması gerekmez; aynı fonksiyon bir kolda birinci veriyi işlerken diğer kollar ikinci, üçüncü ve dördüncü veriyi paralel işleyebilir. Bunu sağlayan yapılara **thread** denir ve günümüz uygulamaları çok thread'li (multi-thread) çalışır. Prosesler için PCB tutulduğu gibi thread'ler için de TCB (thread control block) tutulur. Amaç etkileşimi artırmak, programların daha hızlı yürütülmesini sağlamak ve işlemci kullanımını artırmaktır.

Çok sayıda proses üretmek de bir çözümdür (tarayıcı örneğindeki gibi), ama prosesler arası haberleşme ve senkronizasyon proses düzeyinde maliyetlidir ve zaman zaman baş edilmesi güçtür. Bu yüzden prosesleri çok thread'li çalıştırmak günümüzde daha uygun hâle geldi.

## 7. Proses Zamanlama ve Kuyruklar

### 7.1 Market kasası benzetmesi

Tek bir işlemci çekirdeğini birden fazla proses kullanacaksa işletim sistemi hangi sırayla kullandıracaktır? Bunun için kriterler ve zamanlama algoritmaları belirlenmelidir. Hoca bunu bir benzetmeyle açtı: Markette tek bir kasa ve n müşteri var; müşterileri hangi sırayla kasaya alırsınız ve kriteriniz ne olur?

**Soru:** Bir müşteri olarak en önemli kriter nedir? **Cevap (öğrencilerden):** İlk gelene öncelik vermek, yani adalet. Bir diğer öneri: eşyası az olanı öne almak. Hoca ikinci önerinin yığılmayı, yani **ortalama bekleme süresini** azalttığını açıkladı. İlk gelenin çok eşyası varsa ve arkadakilerin az eşyası varsa herkesin bekleme süresi artar; işi az olan önden alınırsa kişi başına ortalama bekleme süresi düşer.

Proses zamanlayıcı (process scheduler) işletim sisteminin bileşenlerinden (servislerinden) biridir. Yürütülebilecek prosesler arasından uygun olan birini seçer ve işlemciye atar. Birden fazla işlemci varsa işlemci sayısı kadar seçim yapılır. Seçim zamanlama kuyruklarındaki proseslerden yapılır.

### 7.2 Zamanlama kuyrukları

- **Job queue:** Sistemdeki bütün proseslerin bulunduğu kuyruk. Batch sistemlerde ilk gelen ilk hizmetini alır.
- **Ready queue:** Bütün prosesler sistemde tutulur ama hepsi işlemcide yürütülmeye hazır değildir (örneğin G/Ç yapan olabilir). Ready queue, bellekte bulunan ve yürütülmeye hazır olan proseslerden seçim yapmak için kullanılan kuyruktur.
- **Device queue'lar:** Aygıtların da kendi kuyrukları vardır. Örneğin bir yazıcıya birden fazla yazdırma işi gönderilmişse orada bir kuyruk tutulur; yazıcıdaki bellek az olduğu için orada öne alma, sona atma gibi bir planlama yapılamaz, ilk gelen ilk hizmet alır.

Prosesler bu kuyruklar arasında dolaşır: işlemciye girecekse ready queue'ya, bir aygıt kullanacaksa o aygıtın kuyruğuna girer. Buna genellikle waiting denir ama aygıt kuyruğunda durma olasılığı da vardır.

### 7.3 Linux'ta proseslerin temsili

Linux'ta bir proses C'deki `task_struct` yapısıyla temsil edilir. Slayttaki alanlar (ekrandan, 00:50:00):

```c
pid_t pid;                    /* process identifier */
long state;                   /* state of the process */
unsigned int time_slice;      /* scheduling information */
struct task_struct *parent;   /* this process's parent */
struct list_head children;    /* this process's children */
struct files_struct *files;   /* list of open files */
struct mm_struct *mm;         /* address space of this process */
```

`pid_t` aslında bir tamsayıdır. `time_slice` prosesin işlemcide ne kadar kalacağıdır (3 saniye, 2 saniye gibi). Prosesler başka proseslerin yardımıyla oluşturulduğu için her prosesin bir parent'ı vardır; işletim sistemi açılınca komut satırından ya da tıklayarak başka bir proses aracılığıyla proses oluştururuz. Açık dosyalar yalnız `.txt` gibi dosyalar değildir; örneğin bir ağ bağlantısı da file descriptor kullanır. Bu `task_struct` yapıları bağlı liste (linked list) hâlinde tutulur; slaytta şu anda yürütülen proses `current` işaretçisiyle gösterilir.

### 7.4 Kuyruk örneği

Slayttaki örnekte ready queue'nun başında PCB7, ardından PCB2 vardır. İşlemci kullanılacağında kuyruğun başı (head) yedinci prosesi gösterir; P7 işlemciyi alır ve head artık PCB2'yi gösterir. Kuyruğa yeni bir proses gelirse bağlı listenin sonuna eklenir; kuyruğun başı ve sonu ayrı tutulur. Manyetik teyp birimlerine atanmış proses yoksa onların kuyrukları boştur. Disk kuyruğunda PCB3, PCB14 ve PCB6 vardır; burada ilk gelen ilk hizmet alır kuyruğu olabilir. Terminal kuyruğunda (komut istemi gibi düşünülebilir) yalnız PCB5 vardır.

### 7.5 Kuyruk diyagramı

Ready kuyruğuna bir proses üç yoldan gelebilir: new durumundan, running durumundan bir kesmeyle ve waiting durumundan. Ready kuyruğundan gidilecek yer işlemcidir. İşlemciden şu yollarla çıkılabilir:

- Proses tamamen bitip sonlanır.
- Bir G/Ç isteği olur ve proses G/Ç kuyruğuna girer (örneğin yazıcı doğrudan atanmaz, kuyruğa girilir); iş bitince ready kuyruğuna dönülür.
- Zaman dilimi (time slice) dolar; proses doğrudan ready kuyruğuna döner.
- Proses bir çocuk proses oluşturur (fork a child) ve çocuğun yürütülmesi sırasında bir bekleme olabilir.
- Proses bir kesmenin gerçekleşmesini bekler. Hoca bunu gömülü sistemlerden örnekledi: Bir butona basılınca bir yerden bilgi okunur ya da sıcaklık aniden düşünce ısıtıcıyı çalıştıracak bir kod bir kesmeyle çalışır; bu, G/Ç için gelen kesmeden farklı bir kesmedir.

Bütün bu durumlar bitince gidilecek yer ready kuyruğudur.

> **Hocanın vurgusu:** Sınavda en çok yapılan hata şudur: Yürütmesi tamamlanmadan yarıda kesilen bir proses ya G/Ç nedeniyle waiting durumuna ya da kendisine ayrılan zaman dolduğu için doğrudan ready durumuna gider. Running'den waiting'e geçmiş bir proses waiting'den kesinlikle doğrudan running'e dönemez: önce waiting'den ready'ye, sonra ready'den running'e geçer.

## 8. Scheduler Türleri

### 8.1 Short-term scheduler

Kısa vadeli zamanlayıcı (short-term scheduler) aslında CPU scheduler'dır. Hazır prosesler arasından işlemciyi hangisinin kullanacağını belirler. Bir prosesi alıp işlemciye koyar, sonra çıkarıp başkasını koyar; bu yüzden milisaniyeler mertebesinde çalışmalı ve çok hızlı olmalıdır. Bazı sistemlerde tek scheduler budur; birçok bilgisayar sistemi işlemci kullanımı üzerine kurulu olduğu için çoğu sistemde yalnız bu görülür.

### 8.2 Long-term scheduler

Ready kuyruğuna hangi proseslerin getirileceğine karar veren zamanlayıcıya uzun vadeli zamanlayıcı (long-term scheduler) denir. Bellekten bir prosesi alıp işlemciye getirmek zaman aldığı için hazır proseslerin bir yerde tutulması gerekir; ready kuyruğuna kimin geleceğini long-term scheduler belirler. Saniyeler ya da dakikalar mertebesinde, görece seyrek çağrılır.

Long-term scheduler çoklu programlama derecesini (degree of multiprogramming) kontrol eder, gerektiğinde düşürür. Hoca şu örneği verdi: Bilgisayarda 500 program olsun; bunların hepsini her zaman çalıştırmak gerekmez. Alt sınır 100 ise bu değer 100 ile 500 arasında gezebilir, belki hiçbir zaman 500'e ulaşmaz. Bunun avantajları ve dezavantajları arasında bir ödünleşim (trade-off) vardır; bellek yönetimi konusunda buraya dönülecek.

### 8.3 G/Ç bağımlı ve CPU bağımlı prosesler

- **G/Ç bağımlı (I/O-bound) proses:** İşlemciye girer, biraz çalışır ve hemen G/Ç yapması gerekir; hesaplamadan çok G/Ç yapar. Bu tür prosesler çoksa işlemci sık sık boşta kalır, G/Ç kuyrukları şişer.
- **CPU bağımlı (CPU-bound) proses:** Çok az G/Ç yapar, çok işlemci kullanır. Örneğin veri bellekte hazırdır ve üzerinde sıralama ya da karmaşıklığı yüksek bir algoritma çalıştırılır. Bu tür prosesler çoksa işlemcinin önündeki ready kuyruğu dolar, G/Ç kuyrukları boş kalır.

Dengeyi sağlamak için bir kısmı G/Ç bağımlı, bir kısmı CPU bağımlı proseslerden oluşan bir **proses karışımı** (process mix) seçilmelidir; bunu ilk yapacak olan long-term scheduler'dır. Ancak hangi prosesin ne kadar G/Ç yapacağı önceden bilinmez; işletim sistemi yalnız yürüttüğü komutu bilir. Bu yüzden şimdiye kadar çalışan proseslerin G/Ç ihtiyacıyla ilgili istatistikler tutularak geleceğe yönelik tahmin yapılır.

### 8.4 Medium-term scheduler

İstatistiğe dayalı seçim her zaman sağlıklı yürümez. Yanlış kararla G/Ç bağımlı ya da CPU bağımlı prosesler artırılmışsa çoklu programlama derecesi bozulur; bu da kilitlenmelere ve başka sorunlara yol açabilir. Bunu önlemek için orta vadeli zamanlayıcı (medium-term scheduler) eklenebilir. Amacı gerektiğinde çoklu programlama derecesini azaltmak, gerektiğinde artırmaktır.

İki işlem vardır:

- **Swap out:** Bellekte yürütülmeye hazır bekleyen bir prosesin (bir kısmı yürütülmüş, bir kısmı yürütülecek ama acil olmayan) bellekten çıkarılıp diske yazılmasıdır. Proses diske sonsuza kadar gitmez, ileride getirilmek üzere gider. Swap out çoklu programlama derecesini doğrudan azaltır.
- **Swap in:** Diske çıkarılmış prosesin yürütmeye devam etmesi için yeniden ana belleğe getirilmesidir. Önce dereceyi artırır, sonra dengeye getirir.

Hoca örnek verdi: Çoklu programlama derecesi 100 olsun; 120, 140, 150'ye çıkarsa swap out yapa yapa yeniden 100'e indirilir. Yeni prosesler swap in ile getirildiğinde 110-120'ye çıkar gibi olur, ama o sırada başka prosesler swap out edilerek 100 civarında tutulur. Medium-term scheduler, long-term scheduler'ın (ya da yanlış bir CPU zamanlama algoritması nedeniyle ortalama bekleme süresi artan short-term scheduler'ın) bozduğu dengeyi düzeltmeye çalışır.

### 8.5 Mobil sistemler

Mobil sistemlerde prosesler çalışabilir ya da askıya alınmış (suspended) durumda olabilir. İşlemci ve bellek kaynak olduğu gibi mobil sistemlerde pil de bir kaynaktır; prosesleri farklı durumlarda bekletmek bile güç harcar. Örneğin iOS sistemlerde prosesler ön plan (foreground) ve arka plan (background) olarak ayrılmıştır; Android'de de benzeri vardır. Arka plan prosesleri en az güç harcayacak biçimde düzenlenir; bellek ve CPU da yine verimli kullanılır.

## 9. Bağlam Değişimi (Context Switch)

İşletim sistemi bir prosesten başka bir prosese geçerken eski prosesin PCB'sini kaydeder ve yeni prosesin durumunu CPU'ya yükler. Buna **bağlam değişimi** (context switch) denir; "context" içerik demektir. Bunun için geçen süreye bağlam değişim süresi denir. Şemadaki boşta geçen (idle) süre bu sürenin bir parçasıdır ama tamamı değildir: kaydetmeye başlama, aradaki boş süre ve yeniden yükleme birlikte context switch süresini oluşturur.

Bu süre bir ek yüktür (overhead): Sistem bu sırada yararlı iş yapmaz. Ne kadar az olursa CPU o kadar az boş kalır; CPU az boş kalırsa çoklu programlama ve etkileşim o kadar iyi olur.

Bağlam değişim süresi şunlara bağlıdır:

- PCB'nin büyüklüğü ve işletim sisteminin kaydetme (save) ve yeniden yükleme (reload) rutinlerinin karmaşıklığı; bunlar kopyalama ve yedekleme süresini uzatırsa süre artar.
- Donanım desteği. PCB'ler genellikle ana bellekte tutulur (her prosese ayrılan bellek bölgesi gibi, işletim sistemi de PCB'leri bellekte saklar). Ama işlemcide bu işe ayrılmış özel amaçlı register setleri varsa PCB'ler register'larda tutulabilir. Register'lar işlemcinin içinde olduğu için belleğe gidip yedekleme gerekmez ve geçiş daha hızlı olur.

## 10. Proses Oluşturma

### 10.1 Proses ağacı

İşletim sistemi proses oluşturma ve sonlandırma gibi işlemler için mekanizma sağlamalıdır. Çift tıklayarak proses oluşturuyorsak, o çift tıklamayı sağlayan da başka bir prosestir. Bir proses ancak bir parent (ebeveyn) proses tarafından oluşturulabilir; parent proses child (çocuk) proses oluşturur, çocuk da başka prosesler oluşturabilir. Böylece bir ağaç yapısı oluşur: **proses ağacı**.

Her şeyi başlatan bir ilk proses olmalıdır. İşletim sistemi önyükleyici (bootloader) ile başlatıldığında bir `init` prosesi başlar, ardından diğer işletim sistemi prosesleri başlar. Bunlardan biri de çift tıklayarak ya da komut satırından program çalıştırmayı sağlayan prosestir; kullanıcı prosesleri onun yardımıyla çalıştırılır. Prosesler PID ile yönetilir; bir prosesin öldürülmesi, oluşturulması ya da kaynaklarının kontrolü PID üzerinden yapılır.

Linux'ta (ekrandan, 01:50:00) kökte PID'si 1 olan `init` vardır. Bilgisayar açıldığında en azından giriş (login) yapmak gerekir; giriş işlemini yapan bir proses vardır. Ayrıca `kthreadd` ve `sshd` gibi farklı servisleri sağlayan prosesler başlar. Girişten sonra bir komut satırı gelir; slayttaki ağaçta `bash` (pid 8416) ve onun altında `ps` (pid 9298) gibi prosesler görülür.

### 10.2 Kaynak paylaşımı ve yürütme seçenekleri

Kaynak paylaşımı açısından üç olasılık vardır:

- Parent ve çocuklar bütün kaynakları paylaşır.
- Çocuklar parent'ın kaynaklarının bir alt kümesini paylaşır.
- Parent ve çocuk hiçbir kaynak paylaşmaz.

İşletim sistemi bu olasılıklara göre farklı davranır. Yürütme açısından ise parent ve çocuk eş zamanlı (concurrent) çalışabilir ya da parent çocuk sonlanana kadar bekleyebilir.

### 10.3 Concurrent ve paralel yürütme

**Soru:** Concurrent ne demek? **Cevap (bir öğrenci):** Paralel. Hoca bu kavramın iyi bilinmesi gerektiğini söyleyerek açıkladı: Tek bir işlemci çekirdeği varsa belli bir zaman aralığında onu tek bir proses kullanır; gerçek anlamda paralellik mümkün değildir. Zaman paylaşımı esasıyla, nanosaniyeler ya da milisaniyeler mertebesinde proseslerden biri alınıp biri çıkarılır ve sanki paralel bir işleyiş varmış gibi görünür. Buna **sanal paralellik** denir; diğer adı **eş zamanlı yürütme** (concurrent execution) dır. İki, üç ya da dört işlemci çekirdeği (ya da birden fazla işlemci) varsa gerçek paralellik sağlanır.

İnsanın gözü ve kulağı ancak yaklaşık bir saniye ve üzeri gecikmeleri algılar; milisaniye ve nanosaniye düzeyindeki gecikmeler hissedilmez. Bu yüzden hızlı bağlam değişimleri sayesinde paralellik varmış gibi görürüz. Hoca kendi bilgisayarını örnek verdi: Bir yandan slayt, bir yandan Zoom çalışıyor, ses karşıya gidiyor; arka planda pek çok proses var ve hepsi sırayla işlemciye girip çıkıyor. Bir Gantt diyagramı çizilse önce biri, sonra diğeri girer ve hiç örtüşme olmaz. Bunun için iyi bir planlama gerekir: P1'den P100'e kadar prosesler varsa P1 çok geride kalır ve yeniden sıra gelmesi uzun sürer. İşletim sistemi eş zamanlı yürütmeyi scheduler yaklaşımları ve diğer servislerle sağlamalıdır.

Parent'ın çocuk sonlanana kadar beklemesinin bir nedeni de şudur: Her prosesin veri yapısında parent prosesin bilgisi vardır. Parent çocuktan önce ölürse oraya ne yazılacaktır? Bu durum zombi ve yetim proses kavramlarıyla ilgilidir (Bölüm 12).

### 10.4 Adres uzayı: kopyalama ve yeni program

Proses oluşturulduğunda parent'ın adres uzayının birebir kopyası bellekte başka bir yere alınır. Burada doğal bir soru akla gelir: Benim parent prosesim, programları çalıştırmayı sağlayan ve benim programımla ilgisi olmayan bir prosestir; onun kopyası alınırsa benim programımın kodu oraya nasıl yerleşir? Cevap şudur: Önce birebir kopya (duplicate) oluşur, sonra ek bir adımla sizin programınızın kodu bu bellek uzayına yüklenir. Buna program farklılaştırma (differentiation) da denir.

UNIX sistemleri bu iki aşamayı iki ayrı sistem çağrısıyla sağlar:

- **`fork()`:** "Fork" çatal demektir. Yürütme akışının bir yerinde `fork` çağrılarak çocuk proses oluşturulur. Çocuk parent'la aynıdır ama yeni bir prosestir: yeni bir PID alınır ve bellekte yer ayrılır.
- **`exec()`:** `fork`'tan sonra çocuğun bellek uzayının içeriğini yeni programla değiştirmek (replace) için kullanılır.

Windows'ta bu işi `CreateProcess()` yapar.

Görsel olarak: Bir başlangıç prosesi çalışır, `fork` çağrılınca birebir kopyası (child) oluşur; çocuğun içinde `exec` çağrılınca çocuğun içeriği değişir. Parent `wait` ile çocuk sonlanana kadar bekler, sonra kendi işine devam eder. Bu bekleme sağlanmadan parent sonlanırsa yetim ya da zombi proses olasılıkları ortaya çıkar.

## 11. fork, exec ve wait Örnekleri

### 11.1 fork'un dönüş değeri

`fork` bir tamsayı döndürür ve üç olasılık vardır. Kullanmak için `<unistd.h>` ve `<sys/types.h>` başlık dosyaları eklenir.

- **Negatif değer:** `fork` sistem tarafından reddedilmiş, proses oluşturulamamıştır. Çoklu programlama derecesi çok yüksek olabilir ya da bellek gibi bir kaynakla ilgili sorun olabilir. Hoca bu kodların 30-40 yıl öncesinin mantığıyla yazıldığını, o zamanlar bu durumun çok daha yaygın olduğunu, bugün olumsuz yanıt olasılığının çok daha az ama yine de var olduğunu söyledi.
- **Sıfır:** Çocuk prosesin içindesiniz. Çocuğun yapacaklarını buraya yazarsınız; örneğin `exec` ile `/bin/ls` yüklenir. Siz de masaüstündeki kendi C programınızı yükleyebilirsiniz.
- **Pozitif değer:** Parent prosesin içindesiniz ve değer çocuğun PID'sidir. Parent burada `wait(NULL)` ile çocuk tamamlanana kadar bekleyebilir. Çocuk `return 0` ile bitince parent beklemeden kurtulur, "Child Complete" yazar ve kendi `return 0`'ıyla biter.

Slayttaki örnek (ekrandan, 01:36:00):

```c
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>

int main()
{
pid_t pid;
    /* fork a child process */
    pid = fork();
    if (pid < 0) { /* error occurred */
        fprintf(stderr, "Fork Failed");
        return 1;
    }
    else if (pid == 0) { /* child process */
        execlp("/bin/ls","ls",NULL);
    }
    else { /* parent process */
        /* parent will wait for the child to complete */
        wait(NULL);
        printf("Child Complete");
    }
    return 0;
}
```

Bu kod derste derlenmedi. Ajan kodu scratchpad'de `#include <sys/wait.h>` ekleyerek `gcc -Wall` ile derleyip çalıştırdı: önce dizinin `ls` çıktısı, ardından `Child Complete` yazıldı.

> **Ek bilgi (derste anlatılmadı):** `wait()` fonksiyonunun bildirimi `<sys/wait.h>` başlık dosyasındadır. Slayttaki kodda bu başlık olmadığı için `gcc -Wall` "implicit declaration of function 'wait'" uyarısı verir; kodu derlerken bu başlığın eklenmesi gerekir.

Hoca aynı PID değişkeninin iki yerde tutulduğunu vurguladı: `fork`'a kadar yalnız parent vardır; `fork`'tan sonra birbirinin aynı iki kod çalışır. Başarılı bir `fork`'ta örneğin 100 dönerse parent'taki değişken çocuğun PID'sini (100), çocuktaki değişken ise 0'ı tutar. Kod bir noktadan sonra iki kola ayrılır; PID'ye bakarak hangi kolun parent, hangisinin çocuk olduğu ve kimin hangi işi yapacağı ifade edilir.

### 11.2 Windows CreateProcess

Slayttaki Windows örneğinde (ekrandan, 01:38:20) `STARTUPINFO si` ve `PROCESS_INFORMATION pi` yapıları `ZeroMemory` ile sıfırlanır, sonra `CreateProcess(NULL, "C:\\WINDOWS\\system32\\mspaint.exe", NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi)` ile çocuk proses olarak Paint programı çalıştırılır. Ekstra parametreler proses ve thread tanıtıcılarının (handle) devralınmaması, oluşturma bayrağı olmaması ve parent'ın ortam bloğu ile dizininin kullanılması içindir. `CreateProcess` başarısız olursa (sıfır dönerse) "Create Process Failed" yazılır. Parent `WaitForSingleObject(pi.hProcess, INFINITE)` ile çocuk bitene kadar bekler, "Child Complete" yazar ve `CloseHandle` ile tanıtıcıları kapatır.

### 11.3 Fork bombası

Hoca bir soru sordu: `void f()` fonksiyonu içinde `fork()` çağrılıp ardından yine `f()` çağrılsın ve `main`'den `f` çağrılsın. Ne olur? Özyinelemeli bir yapı vardır: Önce bir proses vardır, `fork` ile iki olur; ikisi de `f`'yi yeniden çağırıp kendi `fork`'unu yapar, dört olur; sonra sekiz olur. Her aşamada ikiyle çarpılarak üstel biçimde artar. Buna **fork bombası** (fork bomb) denir.

Çok fazla proses oluşunca bellek dolar ve çoklu programlama derecesi aşırı artar; işletim sisteminin bunu bir yerde engellemesi gerekir. Hoca eski kampüste öğrencilerin terminal istemcileri (thin client) üzerinden kendi hesaplarıyla bağlandığı bir sunucuyu anlattı: Biri böyle bir kod çalıştırdığında diğer kullanıcılar bilgisayarın yavaşladığını ve hatta sistemden atıldığını görürdü. Bellek dolunca sistem alarm durumuna geçer, diğer kullanıcılar atılır; ama çağrı sonsuz olduğu için bu da yetmez ve bilgisayar yeniden başlatılana kadar kilitli kalabilirdi. Böyle bir durumda `fork` negatif değer döndürebilir; işletim sistemi yeni prosese izin vermeyebilir.

### 11.4 Basit fork örneği

Hoca bu örneklerin bir sonraki uygulama dersinde ayrıca yapılacağını söyleyerek en basit örneği anlattı: Programın başında "before fork" mesajı bir kez yazılır. `fork`'tan sonra program iki parçaya ayrılır ve birebir kopya alındığı için sonraki `printf` iki kez çalışır; "message after fork" iki kez görülür. Burada `wait` yoktur; çocuk ya da parent'tan hangisinin önce sonlanacağı bilinemez, çünkü işletim sistemi hangisini önce işlemciye koyacağına kendisi karar verir. Önce işlemciye giren önce işini bitirir; bu durumda çocuğun yetim ya da zombi olma olasılığı vardır.

### 11.5 getpid ile kendini tanıma

Prosesin kimliğine göre iş yapmak için `getpid()` (kendi PID'si) ve `getppid()` (parent'ın PID'si) sistem çağrıları kullanılır. Slayttaki `fork2.c` (ekrandan, 01:45:30):

```c
#include <stdio.h>
#include <unistd.h>

int main ( void )  {

    int forkResult;

    printf("process id : %i\n",getpid());
    forkResult = fork();
    printf("process id : %i - result : %d\n",
           getpid(), forkResult);

    return 0;
}
```

Slayttaki notlar: parent için `fork` çocuğun PID'sini, çocuk için 0 döndürür. Ekrandaki çıktı:

```text
process id : 2682
process id : 2682 - result : 2683
process id : 2683 - result : 0
```

Adım adım: İlk `printf` yalnız parent'ta çalışır ve 2682 yazar. `fork`'tan sonra parent'ta `getpid()` yine 2682'dir; `forkResult` sıfırdan büyüktür ve çocuğun PID'sidir (2683). Çocukta `getpid()` 2683'tür ve `forkResult` 0'dır. Hoca `forkResult`'ın parent'ta ne olacağının önceden bilinemeyeceğini, bu örnekte 2683 çıktığını söyledi. Burada `if` ile dönüş değerine bakılmaz, `printf` doğrudan yazılmıştır.

Ajan kodu scratchpad'de `gcc -Wall` ile uyarısız derleyip çalıştırdı; PID'ler farklı olsa da aynı yapıda üç satır elde edildi.

> **Ek bilgi (derste anlatılmadı):** Çıktı terminale değil bir dosyaya ya da boruya (pipe) yönlendirilirse `stdout` satır satır değil blok blok tamponlanır. Bu durumda ilk `printf`'in metni `fork` anında henüz tampondadır ve çocuğa da kopyalanır; ilk satır iki kez görünür. Ajanın denemesinde çıktı yönlendirildiğinde bu durum gözlendi. Terminalde çalıştırıldığında ilk satır bir kez görünür.

### 11.6 Kaynak koduyla farklılaştırma

Slayttaki `fork3.c` (ekrandan, 01:47:40); hoca slayta `fork`'un dönebileceği "0, −, +" değerlerini yazdı:

```c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main ( void )  {

    printf("(%i) Parent does something...\n", getpid());

    if(fork())  {  // Parent
        printf("(%i) Parent do completely different stuff\n",getpid());
    } else {       // Child
        printf("(%i) Child can do some stuff\n",getpid());
    }

    exit(0);
}
```

Ekrandaki çıktı:

```text
(2767) Parent does something...
(2767) Parent do completely different stuff
(2768) Child can do some stuff
```

`if (fork())` ifadesi `fork` sıfırdan farklı bir değer döndürdüğünde doğrudur; bu örnekte pozitif değer parent'ın kolunu gösterir, sıfır ise çocuğun kolunu. Parent kendi PID'sini (2767), çocuk kendi PID'sini (2768) yazar.

**Soru:** Son iki satırın yeri değişebilir miydi? **Cevap:** Evet. Hangi prosesin işlemciye önce gireceği bilinemez.

**Soru:** Çocuk doğup belleğe yüklenene kadar önce parent'ın çalışması mantıklı olmaz mı? **Cevap:** Mantıklıdır, ama sistemde yalnız bu parent ve çocuk yoktur. Parent'a sıra gelmeden on prosese sıra gelebilir; o on prosesten sonra önce çocuğa, sonra parent'a sıra gelebilir. Bu sıra değişebilir.

### 11.7 exec

`exec`, `fork` ile kopyalanmış bellek bölgesinin içeriğini değiştirip kendi programınızı oraya yüklemek için kullanılır. Örnekteki `/bin/ls` olmak zorunda değildir; bir C ya da Java programınızın çalıştırılabilir dosyasının yolu verilebilir. Bu dosyanın içeriği bellek uzayına kopyalanır ve çocuk proses artık kendi yoluna devam eder.

## 12. Proses Sonlandırma, Zombi ve Yetim Prosesler

### 12.1 exit ve wait

Proses oluşturmak için `fork`, içeriğini değiştirmek için `exec` vardır. Sonlandırmak için **`exit`** sistem çağrısı kullanılır. Komut satırındaki karşılığı `kill` komutudur: `kill PID` ile bir proses öldürülür.

Çocuk `exit` ile parent'ın `wait` çağrısına bir durum (status) verisi gönderir. C'de programın sonuna yazdığımız `return 0` bu 0 değerini komut satırına gönderir; `exit(0)` da aynı sonucu verir: biri sistem çağrısı, diğeri dönüş değeridir. `exit`'e 0 yerine 3, 5, 10 gibi bir değer verilip bu değer parent'ta `wait` ile alınarak çocuğun işini sağlıklı yapıp yapmadığı öğrenilebilir. Proses `exit` ile sonlandığında işletim sistemi kaynaklarını geri alır (deallocate); örneğin `malloc` ile verilen bellek alınır.

`wait` çağrısında bir durum değişkeninin adresi verilir (`wait(&status)`); `scanf`'teki gibi `&` kullanılır, çünkü bu değişkenin içine çocuğun `exit` ile gönderdiği değer yazılacaktır.

### 12.2 abort ve cascading termination

Parent, çocuğun yürütmesini `abort` ile sonlandırabilir. Nedenleri:

- Çocuk kendisine ayrılan kaynakları aşmıştır.
- Çocuğa verilen görev artık gerekli değildir.
- Parent sonlanıyordur ve işletim sistemi çocuğun parent'sız devam etmesine izin vermiyordur.

Bazı işletim sistemleri parent sonlandığında çocuğun yaşamasına izin vermez. Bir proses sonlanırsa onun bütün çocukları ve onların çocukları da sonlandırılır; ağaçtaki bütün alt prosesler ancak parent'larıyla birlikte sonlanır. Buna **cascading termination** denir.

Parent'ın çocuklarının sonlanmasını beklemesi `wait` sistem çağrısıyla sağlanır. Bu yazılmazsa çocuk önce ölebilir, parent önce ölebilir ve bazı şeyler karışabilir.

### 12.3 Zombi ve yetim

Hoca bu iki kavramı şöyle anlattı: `wait` kullanılmadıysa ve çocuk yaşarken parent yaşamıyorsa bu bir zombi prosestir. Parent ölmüş, çocuk yaşıyorsa, çocuk işletim sistemindeki başka bir proses tarafından evlat edinilir; buna **yetim (orphan) proses** denir. Her prosesin parent PID'si saklandığı için parent öldüğünde bu alan boş kalamaz ve var olmayan bir proses yazılamaz; bu yüzden çocuğun başka bir prosese evlat verilmesi ve parent PID'sinin değiştirilmesi gerekir. Hoca yetimi zombinin özel bir hâli olarak andı.

> **Ders sonrası not:** Standart tanımlar hocanın anlatımından farklıdır. **Zombi proses**, sonlanmış (`exit` yapmış) ama parent'ı henüz `wait` çağırmadığı için proses tablosundaki kaydı (PID ve çıkış durumu) silinmemiş çocuktur. **Yetim proses** ise parent'ı sonlandığı hâlde çalışmaya devam eden çocuktur; `init` (ya da bir alt toplayıcı, subreaper) tarafından evlat edinilir ve yeni parent'ı onun için `wait` çağırır. Yetim, zombinin özel hâli değildir; iki ayrı durumdur.

Slayttaki "Zombie example: non-terminating child" örneği (ekrandan, 01:57:30); slayttaki kodda parent kolundaki `exit(0);` satırının üstü çizilmiştir:

```c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main ( void ) {

    if(fork())  {  // Parent
        printf("Running parent, pid : %i\n",getpid());
    } else  {    // Child
        printf("Terminating child, pid : %i\n", getpid());
        while(1);
    }

    exit (0);
}
```

Ekrandaki terminalde `ps -ef | grep Zombie` çıktısında `./Zombie2` prosesi PID 3467 ve parent PID 1 ile görünür. Hoca kodu şöyle açıkladı: Parent işini bitirip `exit(0)` yapar; bu değer parent'ın parent'ına gider. Çocuk ise `while(1)` ile hiçbir şey yapmadan sonsuza kadar bekler. `ps` ile hangi prosesin bu durumda olduğu PID'siyle görülebilir; bir süre sonra kod yeniden çalıştırılıp `ps` yapılırsa o PID'li prosesin görünmediği görülür.

**Soru:** (anlaşılamayan bir soru) `if (fork())` içinde hangi kol çalışır? **Cevap:** Hoca önce karıştırıp düzeltti: `fork` sıfırdan büyük bir değer verirse `if` doğrudur ve parent kolu çalışır; sıfırsa çocuğun kolu çalışır.

> **Ders sonrası not:** Bu örnekte parent biter ve çocuk çalışmaya devam eder; `ps` çıktısında çocuğun parent PID'sinin 1 olması onun `init` tarafından evlat edinildiğini gösterir. Bu çocuk büyük olasılıkla zombi değil yetim prosestir. Ajanın denemesinde de (scratchpad'de derlenip çalıştırıldı, sonra çocuk öldürüldü) çocuğun parent PID'si bir alt toplayıcı prosese değişti ve durumu `R` (çalışıyor) idi.

Hoca ayrıca `atexit()` fonksiyonunu anlattı. `atexit` program tamamlanırken yapılması gereken işleri yapmayı sağlar: açık dosyaların kapatılması, veritabanı bağlantısının kesilmesi, bellek bölgesinin geri verilmesi gibi. `atexit`'e bir fonksiyon işaretçisi verilir; `exit` çağrıldığında önce bu fonksiyondaki işlemler yapılır, sonra çıkış devam eder. `exit` ise parent'a bir durum değeri gönderir ve parent bunu `wait` ile almalıdır; ikisi farklı şeylerdir.

### 12.4 wait örneği

Slayttaki `wait1.c` (ekrandan, 02:00:30):

```c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define numOfChilds 5
int main ( void )  {

    int i;
    int child_status;
    pid_t pid[numOfChilds];
    pid_t wpid;

    for (i = 0; i < numOfChilds; i++)  {
        if ((pid[i] = fork()) == 0)  {
            exit(100+i);            // create & exit child
        }
    }

    for (i = 0; i < numOfChilds; i++) {
        wpid = wait(&child_status);     // wait for child
        if (WIFEXITED(child_status)) {  // check exit status
            printf("Child %d terminated with exit status %d\n",
                   wpid, WEXITSTATUS(child_status));
        } else {
            printf("Child %d terminate abnormally\n", wpid);
        }
    }
    exit(0);
}
```

Ekrandaki çıktı:

```text
Child 3630 terminated with exit status 100
Child 3631 terminated with exit status 101
Child 3633 terminated with exit status 103
Child 3634 terminated with exit status 104
Child 3632 terminated with exit status 102
```

Beş çocuk oluşturulur ve her biri hemen `exit(100+i)` ile sonlanır. Parent beş kez `wait` çağırır; hangi çocuk önce sonlanırsa `wait` onun PID'sini döndürür ve durum değeri `WEXITSTATUS` ile okunur. Çıktıda 102 en sona kalmıştır; çünkü CPU'nun proseslere verilmesi ve geri alınması mekanizması nedeniyle sonlanma sırası karışık olabilir. Ajan kodu scratchpad'de `gcc -Wall` ile uyarısız derleyip çalıştırdı; bu denemede de sıra 100, 101, 103, 102, 104 olarak karışık çıktı.

### 12.5 Bir proses içinden çoklu proses

Çoklu prosesler yalnız işletim sisteminden gelmez; bir proses kendi içinden başka prosesler oluşturabilir. Örneğin Chrome tarayıcısı açıldığında her sekme için olmasa da içinde ek prosesler vardır: arayüz, diskle ve ağla ilgili işler, HTML yorumlayıcısı (renderer) için ayrı prosesler. Bu prosesler de kendi içlerinde thread'ler doğurur; böylece bir ağaç oluşur ve her biri kendi göreviyle eş zamanlı ve senkronize çalışır.

## 13. Uygulama: Kabuk Komutları ve Kabuk Programlama

Dersin son bölümünde bir araştırma görevlisi uygulama dersi kapsamında Linux kabuk (shell) komutlarını ve kabuk programlamayı gösterdi.

### 13.1 Temel dosya ve klasör komutları

- `mkdir`: klasör oluşturur (make directory).
- `cd`: klasöre gider (change directory).
- `ls`: bulunulan klasördeki dosyaları listeler; `ls -l` uzun liste, `ls -a` gizli dosyaları da gösterir.
- `rmdir`: boş klasörü siler; içi dolu klasör bununla silinemez.
- `touch`: dosya oluşturur; `rm`: dosya siler.
- `cat`: dosyanın içeriğini terminale yazdırır; `nano`: dosyanın içeriğini terminalden düzenler.
- `cp`: dosya kopyalar; `mv`: taşır; `bzip2` gibi araçlarla dosya sıkıştırılır.

Görevli bir `deneme` klasörü oluşturup içine girdi, `touch` ile bir metin dosyası oluşturdu, `nano` ile içine "deneme yazısı" yazdı ve `cat` ile yazdırdı.

### 13.2 Kullanıcı ve grup işlemleri

Kullanıcı oluşturmak gibi işlemler yetki gerektirdiği için `sudo` ile yapılır: `sudo useradd -m kullanici_adi` kullanıcı ekler, `sudo userdel -r kullanici_adi` kullanıcıyı (dosyalarıyla) siler. `sudo groupadd testgrup` grup oluşturur, `groupdel` grubu siler, `sudo usermod -a -G testgrup testuser` kullanıcıyı gruba ekler. Gruplamanın amacı izinleri kolaylaştırmaktır: her kullanıcıya tek tek izin vermek yerine gruptaki örneğin 100 kullanıcıya birden, "yalnız okusun, yazamasın" gibi tek bir izin atanabilir.

### 13.3 Dosya izinleri ve chmod

`chmod 777` gibi üç basamaklı sayının her basamağı bir kullanıcı türünü belirtir: birincisi dosyanın sahibi, ikincisi dosyanın grubu, üçüncüsü bunların dışındaki diğer kullanıcılar (others). Her basamak read, write ve execute izinlerinin ikilik karşılığıdır: 7 = 111, yani üç iznin hepsi.

`ls -l` çıktısında satırın ilk karakteri dosya tipini gösterir: `l` sembolik bağlantı (kısayol gibi), `d` klasör. Ardından sahip, grup ve diğerleri için üçer karakterlik `rwx` grupları gelir. Örnekteki metin dosyasında sahip ve grup `rw-`, diğerleri `r--` iznine sahipti.

- `chmod 444 deneme.txt`: herkese yalnız okuma izni verir (her basamak 100). Bundan sonra `nano` ile açılan dosya için "deneme.txt is unwritable" uyarısı çıktı ve kaydetme "Permission denied" ile reddedildi.
- `chmod 666 deneme.txt`: herkese okuma ve yazma izni verir; dosyaya yeniden yazılabildi.
- `chmod 333 deneme.txt`: okuma izni kalmaz; `nano` dosyayı boş gibi açtı, çünkü içeriği okuyamadı, ve kaydetme yine reddedildi.
- `222` her basamakta 010'dur, yani yalnız yazma; okuma ve çalıştırma yoktur; sahip, grup ve diğerlerinin hepsi için geçerlidir.
- `chmod 754 dosya`: sahip bütün izinlere (7 = rwx), grup okuma ve çalıştırmaya (5 = r-x), diğerleri yalnız okumaya (4 = r--) sahiptir. Aynısı `chmod u=rwx,g=rx,o=r dosya` ile de yapılır.
- `chmod -R 754 klasor`: klasörün ve içindeki bütün dosya ve klasörlerin izinlerini tek komutla ayarlar. `a` (all) harfi sahip, grup ve diğerlerinin hepsini birden belirtir (örneğin `chmod -R a=r klasor`).

**Soru:** Uygulama notlarının önceki sayfalarında write için 3 yazılmamış mıydı; 2 olması gerekmez mi? **Cevap:** Evet, notlarda read 4, write 3, execute 1 yazılmıştı; doğrusu write için 2'dir ve not düzeltilecek. 3 ise hem yazma hem çalıştırma izni verir.

Bir betik çalıştırma izni (execute) olmadan `./deneme.sh` ile çalıştırılamadı; izin değiştirildikten sonra çalıştı.

### 13.4 Betik temelleri

- `echo deneme yazısı` ekrana yazdırır. `cat 1.sh` ile bakılan betikte `echo "hello world"` vardı ve `./1.sh` ile çalıştırıldı.
- Sistem değişkenleri (örneğin `$USER` o anki kullanıcı adı, `$PWD` bulunulan klasör, `$PATH`) ve kullanıcı değişkenleri vardır. Bir betik `$USER` ile kullanıcıyı selamladı, `date` komutunun çıktısını yazdırdı; `who` oturum açmış kullanıcıları verir ve `who | wc -l` ile oturum sayısı bulunur (`wc -l` bir dosyadaki satır sayısını verir); `cal` takvim gösterir.
- Değişken tanımlama: `degisken0=` boş değişken, `degisken1=10` sayı, `degisken2=deneme` metin atar. Değeri almak için `$` kullanılır: `echo $degisken1`. Bir komutun sonucu da değişkene atanabilir (örneğin `pwd`'nin sonucu).
- `echo -e` ile kaçış dizileri kullanılabilir; bir öğrenci `\b`'nin imleci bir karakter sola götürdüğünü, ardından boşluk yazılırsa o karakterin silindiğinin görülebileceğini belirtti.
- Aritmetik `expr` ile yapılır; çarpmada `*` kabukta joker karakter (örneğin `a*` "a ile başlayan" demektir) olduğu için `\*` diye kaçırılır.
- Veri girişi: `echo "Lütfen adınızı giriniz"` sonra `read kullanici_adi` ile girdi alınır ve `echo "Merhaba $kullanici_adi"` ile yazdırılır.
- Joker karakter: `ls *` bütün dosyaları, `ls *.sh` yalnız `.sh` ile bitenleri listeler.
- `mkdir klasor; cd klasor; touch deneme`: noktalı virgül komutları ayırır; olmazsa `cd` de bir klasör adı sanılır.
- Yönlendirme: `echo "dosyaya yaz beni" > dosya` dosyanın içeriğini silip baştan yazar; `>>` sona ekler (append).

### 13.5 Boru (pipe) ve metin işleme

Boru (`|`) bir komutun çıktısını bir sonraki komuta girdi olarak verir ve bir işlem hattı (pipeline) oluşturur.

- `ps aux` görev yöneticisi gibi çalışan prosesleri kullanıcı ve PID bilgileriyle listeler. `egrep` bir dosyada bir ifadenin geçtiği satırları getirir. `ps aux | egrep root` yalnız "root" geçen satırları getirdi.
- `tr` (translate) karakter dönüştürür: `echo "col1 col2 col3" | tr a-z A-Z` küçük harfleri büyük harfe çevirir; `cat dosya.txt | tr ';' ','` noktalı virgülleri virgüle çevirir.
- `awk` sütun karşılaştırması için kullanılır: `-F` ile sütun ayırıcı (örneğin `;`) belirtilir ve örneğin ikinci sütunu 3'ten büyük olan satırlar getirilir. Örnekte bir dosyaya `>` ve `>>` ile "isim;not;sayı" biçiminde üç satır yazılmıştı.
- `bc` hesap makinesi gibi kullanılır: `3+4`, ya da `x=5`, `y=6`, `x+y` ile 11 elde edilir.

### 13.6 Koşul, döngü, metin ve fonksiyon

- Betik parametreleri: `$0` betik dosyasının adı, `$1`, `$2`, ..., `$n` parametreler, `$#` parametre sayısıdır. Örnekte `$# -gt 3` (greater than) ise "$# adet parametre girdiniz", değilse "yeterli değildir" yazdırıldı; bir başka örnekte `cat $1` başarılı olursa "$1 isimli dosya mevcut" yazdırıldı.
- `for` döngüsü üç biçimde yazılabilir: `for i in 1 2 3 4 5`, `for i in {1..5}` ve `for ((i=1; i<=5; i++))`; üçü de 1'den 5'e kadar yazdırır. `{1..10..2}` birden ona ikişer artarak gider. `for f in $(ls)` ile klasördeki dosya adları dolaşılabilir.
- `while` döngüsü: `i=10` ile başlayıp `i` 0'dan büyük olduğu sürece (`-gt 0`) değeri yazdırır ve `expr` ile bir azaltır. `until` ise koşul doğru olana kadar döner; örnekte sayaç 6'dan başlayıp 3'ten küçük olana kadar azaltılarak yazdırıldı.
- Metin uzunluğu `${#str}` ile bulunur ("Welcome to Javatpoint" örneği). `${str:0:10}` ile dilimleme (slicing) yapılır.
- Metin ayırma: `read -p` ile istem yazdırılarak girdi alınır, `IFS=','` ile ayırıcı virgül yapılır ve `read -a strarr` ile parçalar bir diziye yazılır; örnekte isim, şehir ve yaş üç parçaya ayrılıp dizinin 0, 1 ve 2. elemanları olarak yazdırıldı.
- Fonksiyon: `function_arguments() { echo $1 $2 $3 $4 $5; }` biçiminde tanımlanır; çağrılırken verilen beş parametre `$1`...`$5` ile alınır.

### 13.7 Python'dan kabuk komutu çalıştırma

Python'daki `subprocess` modülüyle kabuk komutları çalıştırılabilir: `subprocess.Popen(["echo", "..."], shell=True)` ya da `subprocess.run(..., capture_output=True)` ile çıktı bir değişkene alınıp `result.stdout` ile yazdırılabilir. Görevli bir `deneme.py` dosyası yazıp `python3 deneme.py` ile çalıştırdı ve `echo` komutunun çıktısını gördü. Dersin sonundaki kopyalama ve dosya sistemi örnekleri ses kalitesi nedeniyle anlaşılamadı.

<!-- BELİRSİZ: 03:08–03:14 arası uygulama kısmı (dosya kopyalama ve dosya sistemi örnekleri) altyazıda anlamsız; nota alınmadı. -->

## Örnek Sorular

**Soru 1** (derste sözlü, 00:45:00): Markette tek bir kasa ve n müşteri varsa müşteriler hangi kritere göre sıralanmalıdır?

> **Çözüm:** İlk gelene öncelik vermek adaleti sağlar. Eşyası az olanı öne almak ise ortalama bekleme süresini azaltır: işi kısa olan önden çıkınca kişi başına düşen bekleme süresi ortalamada düşer.

**Soru 2** (derste sözlü, 00:53:30): Yürütmesi yarıda kesilen bir proses hangi duruma geçebilir?

> **Çözüm:** G/Ç ya da bir olay nedeniyle waiting durumuna veya zaman dilimi dolduğu için doğrudan ready durumuna. Waiting'e geçmiş bir proses doğrudan running'e dönemez; önce ready kuyruğuna girer.

**Soru 3** (derste sözlü, 01:40:40): `void f()` içinde `fork()` çağrılıp ardından `f()` yeniden çağrılırsa ve `main` `f`'yi çağırırsa ne olur?

> **Çözüm:** Proses sayısı her adımda ikiye katlanır (1, 2, 4, 8, ...): fork bombası. İşletim sistemi sınırlamazsa bellek dolar ve sistem kilitlenir; sınır aşıldığında `fork` negatif değer döndürür.

**Soru 4** (ekrandan, 01:45:30): `fork2.c` çalıştırıldığında parent'ın PID'si 2682 ise çıktı ne olur?

> **Çözüm:** Önce yalnız parent `process id : 2682` yazar. `fork`'tan sonra parent `process id : 2682 - result : <çocuğun PID'si>` (ekranda 2683), çocuk `process id : 2683 - result : 0` yazar. Son iki satırın sırası değişebilir.

**Soru 5** (ekrandan, 01:47:40): `fork3.c` çıktısındaki son iki satırın yeri değişebilir mi?

> **Çözüm:** Evet. Parent ile çocuktan hangisinin işlemciye önce gireceği bilinemez; araya başka prosesler de girer.

**Soru 6** (derste sözlü, 01:54:30): Parent'ı ölmüş bir prosesin parent PID alanına ne yazılır?

> **Çözüm:** Var olmayan bir proses yazılamaz. Çocuk başka bir proses (`init` ya da bir alt toplayıcı) tarafından evlat edinilir ve parent PID'si onunla değiştirilir; bu çocuğa yetim (orphan) proses denir.

**Soru 7** (ekrandan, 02:32:00): `chmod 222` hangi izinleri verir? `chmod 754` ne anlama gelir?

> **Çözüm:** 222'de her basamak 010'dur: sahip, grup ve diğerleri yalnız yazabilir, okuyamaz ve çalıştıramaz. 754'te sahip rwx (111), grup r-x (101), diğerleri r-- (100) iznine sahiptir.

## Dersin Toparlaması

Bu derste proses kavramı, programdan farkı ve prosesin bellekteki text, data, heap ve stack bölümleri anlatıldı. İki, üç ve beş durumlu proses modelleri ele alındı; beş durumlu modelde geçişlerin kurallarına, özellikle waiting'den doğrudan running'e dönülemeyeceğine dikkat çekildi. Her proses için tutulan PCB'nin içeriği, prosesler arası geçiş ve bunun ek yükü olan bağlam değişimi açıklandı. Zamanlama kuyrukları, short-term, long-term ve medium-term scheduler'lar, G/Ç bağımlı ve CPU bağımlı prosesler ile proses karışımı incelendi. Son olarak proses ağacı, `fork`, `exec`, `wait`, `exit` sistem çağrıları, Windows'taki `CreateProcess`, fork bombası, cascading termination, zombi ve yetim prosesler slayttaki C örnekleriyle gösterildi. Uygulama bölümünde Linux kabuk komutları, dosya izinleri ve kabuk betikleri tanıtıldı.

Hoca CPU zamanlama konusuna ve bu bölümün kalanına (prosesler arası haberleşme) sonraki derslerde devam edileceğini, `fork` örneklerinin bir sonraki uygulama dersinde ayrıca yapılacağını söyledi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
