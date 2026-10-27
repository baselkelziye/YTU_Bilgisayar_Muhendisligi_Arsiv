# Ders 1 Çalışma Özeti

## Genel Konular

- Dersin tarihi 11 Ekim 2021 Pazartesi. Ders Zoom üzerinden yapıldı.
  - Bu şube çevrim içi teori şubesidir. Teori dersi Pazartesi 2 saat, uygulama saatleri Salı günüdür.
  - İlk hafta çevrim içi sistemde ders yapılamadı. Bu kayıt dersin ilk gerçek oturumudur.
  - Asıl ders anlatımı yaklaşık 00:22'de başlar. Öncesinde yüz yüze şube talepleri ve dersin işleyişi konuşulur.
  - 00:45 ile 00:50 arasında kısa bir ara var.
- Dersin işleyişi ve değerlendirme
  - İki vize ve bir final yapılacak. Proje verilip verilmeyeceği belli değil.
  - Laboratuvarda 4 veya 5 uygulama yapılacak. Uygulamalara not verilmeyecek, ama sınavlarda sorulacak.
  - Ana kaynak Silberschatz, Galvin ve Gagne'nin *Operating System Concepts* kitabının 9. baskısı ve slaytlarıdır.
- İşletim sistemi nedir?
  - Bilgisayar sisteminin dört bileşeni: donanım, işletim sistemi, uygulama programları, kullanıcılar.
  - Kullanıcı bakışı ve sistem bakışı. Sistem bakışında işletim sistemi bir kaynak yöneticisidir (resource allocator) ve kontrol programıdır (control program).
  - Çekirdek (kernel), sistem programları ve uygulama programları.
- Bilgisayar sisteminin başlatılması: önyükleme programı (bootstrap program), BIOS ve önyükleyici (bootloader).
- Bilgisayar sistemi organizasyonu
  - Aygıt denetleyicileri (device controller) ve yerel tamponlar (local buffer).
  - Kesme (interrupt) mekanizması, kesme vektörü, donanım ve yazılım kesmeleri (trap, exception).
  - Kesme oluşunca durumun saklanması ve geri yüklenmesi.
- Depolama yapısı ve hiyerarşisi: yazmaç (register), önbellek (cache), ana bellek, SSD, sabit disk, optik disk, manyetik bant.
  - Önbelleğe alma (caching) ve tutarlılık (consistency) sorunu.
- Doğrudan bellek erişimi (DMA).
- von Neumann ve Harvard mimarileri.
- Çok işlemcili sistemler: asimetrik ve simetrik çoklu işlem (SMP), çok çekirdekli tasarım, sıkı ve gevşek bağlı (tightly / loosely coupled) sistemler.
- Kümelenmiş sistemler (clustered systems): yüksek başarım (HPC), yüksek erişilebilirlik (high availability), asimetrik ve simetrik kümeleme.
- Çoklu programlama (multiprogramming) ve zaman paylaşımı (time sharing, multitasking) kavramlarına giriş.

## Hocanın Özellikle Vurguladığı Kısımlar

- Laboratuvar uygulamalarından da sorumlusunuz.
  - Derste konuşulan şey kuramdır, laboratuvarda yapılan şey gerçek hayattır.
  - Uygulamalarda yapılan veya yapılması gereken şeyler sınavlarda sorulacak.
- Sınavlar "çoktan çok seçmeli"dir.
  - Bir soruda bir, iki, üç veya dört şık birden doğru olabilir.
  - Yalnız doğru şıkları seçerseniz sorun yok. Doğrunun yanında yanlış bir şık seçerseniz yanlış sayılır. Yanlışlar doğruları götürür.
- İşletim sistemi temelde bir kaynak yönetim sistemidir.
  - Kaynakları, kaynak isteyen uygulamalar arasında etkin ve düzenli biçimde paylaştırır.
- İyi bir işletim sistemi sistemin çalışmasını en az ölçüde keser.
  - İşletim sisteminin çok çalışması, asıl işi yapan uygulamaların daha az CPU zamanı alması demektir.
- Donanıma her erişim işletim sisteminden geçmelidir.
  - Çekirdek donanımı sert bir kabuk gibi sarar. Hiçbir uygulama doğrudan donanıma erişmemelidir.
- Modern bir işletim sistemi kesmeyle sürülmelidir (interrupt driven).
  - Kesme olmadan uygulamalar arası geçiş yapılamaz. Bir uygulamanın sistemi ele geçirmesi de engellenemez.
- İşlemci kesmeyi komut döngüsünün (fetch, decode, execute) ortasında değil, iki komut arasında denetler.
- Önbelleğe almanın hangi seviyede yapıldığına göre kararı donanım, işletim sistemi veya uygulama verir.
- İşletim sisteminin ne yaptığı, sistemin ne için kurulduğuna bağlıdır.
  - Kişisel bilgisayarda kullanım kolaylığı (convenience) ve başarım önemlidir.
  - Paylaşımlı sistemlerde (sunucu, mainframe) kaynakların kullanıcılar arasında adil ve anlaşmalara göre dağıtılması önemlidir.
  - Mobil cihazlarda pil de bir kaynaktır, enerji yönetimi öne çıkar.

## Kısa Tekrar Notları

- Bilgisayar sistemi: donanım + işletim sistemi + uygulama programları + kullanıcılar.
  - Kullanıcı bir insan, başka bir bilgisayar veya bir yazılım olabilir.
- İşletim sistemi: kaynak yöneticisi ve kontrol programı.
  - Kontrol programı, programların çalışmasını denetler. Hataları ve bilgisayarın uygunsuz kullanımını (improper use) önler.
- Çekirdek (kernel): her zaman çalışan, donanımı saran temel parça.
- Sistem programları: derleyici, metin düzenleyici, assembler, servisler (daemon) gibi sistemin sürmesini ve geliştirme yapılmasını sağlayan programlar.
- Önyükleme sırası:
  1. Güç verilince ROM/EEPROM'daki önyükleme programı (PC'de BIOS) çalışır. Donanımı ilklendirir.
  2. Önyükleyici (bootloader) çekirdeği belleğe kopyalar ve çalıştırır.
- Kesme (interrupt):
  - Donanım kesmesi: aygıt denetleyicisi işi bitirince oluşturur.
  - Yazılım kesmesi (trap, exception): sistem çağrısı veya çalışma hatası (ör. sıfıra bölme) ile oluşur.
  - Kesme vektörü: kesme servis yordamlarının adreslerini tutan tablo.
  - Kesme işlenmeden önce program sayacı ve yazmaçlar saklanır, sonra geri yüklenir.
- Depolama hiyerarşisi (yukarıdan aşağı): yazmaç, önbellek, ana bellek, SSD, sabit disk, optik disk, manyetik bant.
  - Yukarı çıktıkça hız ve maliyet artar, kapasite azalır.
  - Ana bellek (RAM) rastgele erişimlidir ve uçucudur (volatile).
  - Disk ve SSD kalıcıdır (non-volatile). Bant sıralı erişimlidir (sequential access).
  - Her seviye, altındaki seviye için önbellek gibi davranabilir.
- DMA: Denetleyici, veriyi aygıt tamponu ile ana bellek arasında CPU'ya uğramadan blok blok aktarır. Blok bitince tek bir kesme üretir.
- SMP: Bütün işlemciler eşittir ve her işi yapabilir. Günümüz sistemleri SMP'dir.
- Asimetrik çoklu işlem: Bir işlemci diğerlerine iş dağıtır (patron-işçi ilişkisi).
- Sıkı bağlı (tightly coupled): bir kutu içinde birden fazla işlemci. Gevşek bağlı (loosely coupled): ayrı bilgisayarların bir araya getirilmesi, ör. küme.
- Küme amaçları: HPC (iş paralelleştirme) veya yüksek erişilebilirlik.
  - Asimetrik küme: bir düğüm sıcak beklemede (hot standby) bekler.
  - Simetrik küme: bütün düğümler iş yapar ve birbirini izler.
- Çoklu programlama: Bellekte birden fazla iş tutulur. Biri G/Ç beklerken CPU başka işi çalıştırır.
- Zaman paylaşımı: CPU işler arasında sık sık geçiş yapar. Kullanıcı bütün işlerin aynı anda çalıştığını sanır. Amaç tepki süresini düşürmektir.

## Detaylı Açıklamalar

### Dersin işleyişi ve değerlendirme

Teori dersi Pazartesi günleri 2 saattir. Salı günleri bütün şubelerin ortak uygulama saatleri vardır. Laboratuvar uygulamaları her hafta yapılmayacak. Kuramda belli bir yere gelindikten sonra, tahminen 4. hafta civarında başlayacak.

- **Laboratuvar:** 4 veya 5 uygulama planlanıyor. Konular:
  - kurulacak bir Linux ortamında kabuk (shell) komutları ve kabuk programlama,
  - süreçler arası iletişim (interprocess communication),
  - önyükleyici (bootloader),
  - mümkün olursa çekirdek modülü (kernel module) yazma.

  Uygulamalara not verilmeyecek. Dinleme, tekrar etme ve öğrenme amaçlıdır. Ama içerikleri sınavlarda sorulacak.
- **Sınavlar:** İki vize ve bir final yapılacak. Final %40, yıl içi %60. Yıl içi notu iki vize arasında %30 + %30 olarak bölünecek.
  - 1. vize normalde 8. haftadır. Üniversite vize haftasını henüz açıklamamıştı.
  - 2. vize için vize haftası yoktur. Hoca 2. vizeyi 12. veya 13. haftada yapmayı düşünüyor.
- **Kaynaklar:** Üç temel kitap var:
  - Silberschatz, Galvin, Gagne, *Operating System Concepts*
  - Tanenbaum, *Modern Operating Systems*
  - Stallings, *Operating Systems*

  Ders Silberschatz'ın 9. baskısının slaytları üzerinden gidecek. Bu slaytlar internette bulunabilir. Anlatım sırasında diğer iki kitaptan da bilgi eklenecek.
- **Devam:** Öğrenci sorusu üzerine hoca, devam konusunda üniversitenin duyurusunun geçerli olduğunu söyledi.

### İşletim sisteminin tanımı

Her şeyi kapsayan tek bir tanım yoktur. Mainframe'den mikrodenetleyiciye kadar her sistemin beklentisi farklıdır. Bu yüzden işletim sistemi biraz da amaçlarıyla tanımlanır.

- **Kullanıcı bakışı:** İşletim sistemi, kullanıcı uygulamalarını çalıştıran ve sistemi kolay kullanılır yapan bir ortamdır. Birden fazla kullanıcı veya uygulama varsa, bunların birbirini bozmadan sistemden en etkin biçimde yararlanmasını sağlar.
- **Sistem bakışı:** İşletim sistemi bir kaynak yöneticisidir. Elinde donanım (CPU, bellek, G/Ç aygıtları) vardır. Bu kaynakları, kaynak isteyen uygulamalar arasında paylaştırır.
- **Kontrol programı:** Kullanıcı uygulamalarının çalışmasını denetler. Hataları ve bilgisayarın uygunsuz kullanımını önler. Örnek: Bir uygulamanın yetkisi olmayan bir şeyi çalıştırması, başka bir uygulamayı bozması veya sistemi ele geçirmesi engellenir.

Ders kitabındaki bir tanıma göre işletim sistemi, "satıcının işletim sistemi diye gönderdiği her şeydir". Ama bu sınır zamanla kayar. Hoca örnek olarak Microsoft'un Internet Explorer'ı Windows'a gömmesini ve bu yüzden ABD'de açılan tekel davasını anlattı. Bugün ise tarayıcısı olmayan bir cep telefonu düşünülemiyor.

İşletim sistemi bakışı sistemin türüne göre değişir:

| Sistem | Öne çıkan beklenti |
| :--- | :--- |
| Kişisel bilgisayar | Kullanım kolaylığı, başarım. Kaynakların tam kullanımı (utilization) önemli değil. |
| Paylaşımlı sistem (sunucu, mainframe) | Kaynakların kullanıcılar arasında anlaşmalara ve seviyelere göre dağıtılması. |
| Mobil cihaz | Pil de bir kaynaktır. Ekranı kapatmak, düşük güç moduna geçmek gibi enerji yönetimi. |

### Sistem programları ve uygulama programları

İşletim sisteminin sürmesi ve kullanıcı uygulamalarına servis verebilmesi için başka programlar da gerekir. Bunların hepsini çekirdeğe gömmek etkin değildir. Bu yüzden ayrı birer program olarak yazılırlar. Örnek: metin düzenleyici, derleyici, assembler, hata ayıklayıcı, servisler (daemon). Bunlara sistem programı denir. Kullanıcının iş üretmek için çalıştırdığı programlar ise uygulama programıdır.

### Önyükleme (bootstrap)

Bilgisayarın güç düğmesine basıldığında bir dizi adım çalışır.

1. **Önyükleme programı (bootstrap program):** Üretici tarafından ROM veya EEPROM'a yazılmıştır. Güç verildiği anda çalışır. İşlemciyi, belleği ve aygıt denetleyicilerini ilklendirir. PC'de bu işi BIOS yapar.
2. **Önyükleyici (bootloader):** Çekirdeği ikincil bellekten ana belleğe kopyalar ve çalıştırmaya başlatır.

Yani önyükleme birkaç kademeli bir iştir.

### Aygıt denetleyicileri ve kesmeler

Yaklaşık 30 yıl önce aygıtların ayrı denetleyicileri yoktu. Diskten okuma, klavyeden okuma gibi işlerin hepsini CPU yapıyordu. Bugün her aygıtın veya her veri yolunun bir denetleyicisi vardır. Denetleyicinin bir yerel tamponu (local buffer) vardır.

- CPU, denetleyiciye neyi, nereden, ne kadar okuyacağını söyler.
- Denetleyici veriyi aygıttan alıp kendi tamponuna koyar.
- İş bitince denetleyici CPU'ya bir **kesme** gönderir.
- Bu süre içinde CPU boş beklemez, başka bir süreci çalıştırabilir.

**Kesme**, işlemcinin sıradan akışını değiştiren mekanizmadır. İşlemci normalde bellekte sırayla komut çalıştırır (0, 4, 8, 12, ... adresleri). Kesme gelince başka bir bellek bölgesine atlar ve kesmeye karşılık gelen kodu çalıştırır.

- **Kesme vektörü:** Kesme servis yordamlarının adreslerini tutan tablodur. Hangi aygıt kesme oluşturduysa tablodaki karşılığına gidilir.
- **Donanım kesmesi:** Bir aygıt denetleyicisinden gelir. İşlemcinin bir giriş ucuna fiziksel bir sinyal gönderilir.
- **Yazılım kesmesi (trap, exception):**
  - Bir uygulama işletim sisteminden servis istediğinde oluşur, ör. G/Ç yapmak için sistem çağrısı.
  - Bir çalışma hatasında oluşur, ör. sıfıra bölme (division by zero).

İşlemci kesmeyi bir komutun ortasında değil, komut döngüsünün adımları (getir, çöz, yürüt; fetch, decode, execute) bittikten sonra denetler. Yani bir komut bölünmeden tamamlanır, sonra kesmeye geçilir.

Kesme oluştuğunda:

1. Çalışan sürecin kaldığı yer (program sayacı) ve yazmaç değerleri saklanır.
2. Kesme vektörü üzerinden ilgili servis yordamına gidilir. Kesme birden fazla aygıta bakan bir denetleyiciden geldiyse hangi aygıtın kesme ürettiği denetlenir.
3. Okuma, yazma gibi gerekli iş yapılır.
4. Saklanan bilgiler geri yüklenir. Kesilen program kaldığı yerden sürer.

Slayttaki zaman çizelgesinde bir çıktı (output) işlemi gösterilir. Kullanıcı süreci çalışırken G/Ç aygıtı aktarıma başlar. Aktarım bitince aygıt boşa (idle) geçer ve bir kesme üretir. Kullanıcı süreci kısa süre durdurulur, CPU kesmeyi işler, sonra kullanıcı sürecine döner.

Kullanıcı programı G/Ç yapmak istediğinde bir **sistem çağrısı** yapar. Parametreler (nereden, ne kadar okunacağı gibi) çağrıyla verilir. Sistem çağrısı bir kesme oluşturur, kontrol işletim sistemine geçer. İşletim sistemi G/Ç denetleyicisini programlar. G/Ç bitene kadar bekleyen süreç çalışamaz. Bu sırada CPU başka bir uygulamayı çalıştırabilir.

### Depolama yapısı

- **Yazmaç (register):** İşlemcinin doğrudan eriştiği en hızlı bellektir.
- **Önbellek (cache):** İşlemcinin içindedir. L1, L2, L3 gibi birden fazla seviyesi olabilir.
- **Ana bellek (main memory, primary storage):** Rastgele erişimlidir (random access). Yani istenen adrese, baştan sırayla okumadan doğrudan erişilir. Bu yüzden RAM (random access memory) denir. Uçucudur (volatile): Elektrik gidince içerik kaybolur.
  - Hazırda bekletmede (hibernate) bellek içeriği diske kaydedilir, açılışta geri yüklenir.
  - Büyük sunucularda bellek için pil desteği (battery backup) olabilir. Elektrik kesilince sistem güvenli bir duruma geçer. Bu, belleği kalıcı yapmaz. Bellek yine uçucudur.
- **İkincil bellek (secondary storage):** Sabit disk ve SSD kalıcıdır (non-volatile). SSD, sabit diskten çok daha hızlıdır.
- **Manyetik bant:** Yedekleme için kullanılır. Sıralı erişimlidir (sequential access). Kapasitesi terabaytlarla ölçülür.

Hiyerarşide yukarı çıktıkça hız ve maliyet artar, boyut azalır. Bu yüzden üst seviyedeki az kaynağın etkin kullanılması gerekir.

**Önbelleğe alma (caching):** Hiyerarşideki her seviye, bir alttaki daha yavaş seviye için önbellek gibi davranabilir. Sık erişilen veri bir üst seviyeye taşınır.

Öğrenci sorusu: Önbelleğe almaya kim karar verir?

- Ana bellek ile CPU önbelleği arasındaki taşıma donanımın denetimindedir. Donanım bellek erişimlerini izler.
- Hangi süreçlerin belleğe alınacağı (çoklu programlama) işletim sisteminin işidir.
- Disk havuzu ile bant havuzu arasındaki taşıma ise uygulama yazılımıyla yapılabilir. Örnek: Disk havuzu %75 dolunca veri banda aktarılır.

Önbelleğe almanın bir sorunu **tutarlılıktır (consistency)**. Önbellekteki veri değiştirilir ama bellekteki kopya güncellenmezse, başka bir işlemcideki süreç eski veriyi okur. Bu yüzden değişikliğin belleğe yansıması ve o sırada başkalarının erişmemesi gerekir. Kilitler (lock) burada devreye girer.

### Doğrudan bellek erişimi (DMA)

Denetleyici G/Ç'yi yönetse bile, tampondaki veriyi belleğe kopyalayan yine CPU'dur. Bu da etkin değildir. **DMA (Direct Memory Access)** denetleyicisi programlanır: "Bu aygıtın tamponundan belleğin şu adresine kopyala" denir. Kopyalamayı CPU yerine DMA denetleyicisi yapar. Böylece CPU daha da serbest kalır.

### von Neumann ve Harvard mimarileri

Slayttaki "How a Modern Computer Works" şeması bir von Neumann mimarisidir. CPU ile bellek arasında hem komut yürütme döngüsü hem veri aktarımı aynı yoldan geçer. Hoca bunu "tek bir bus üzerinden hem veri hem adres aktarmak" diye anlattı. Harvard mimarisini de "veri ve adres için ayrı bus" diye tanımladı. Bu iki tanımın doğru biçimi aşağıdaki "Ders sonrası notlar" kısmındadır.

Günümüz sunucuları ve kişisel bilgisayarlar büyük çoğunlukla von Neumann mimarisi üzerine kuruludur. Harvard mimarisi daha çok mikrodenetleyicilerde kullanılır.

### Çok işlemcili sistemler

Çok işlemcili sistem, içinde birden fazla genel amaçlı işlemci olan sistemdir. Tek işlemcili bir sistemde de belli bir işe ayrılmış özel işlemciler olabilir. Bu sistem yine tek işlemcili sayılır.

Avantajları:

- **Daha fazla iş:** Birim zamanda daha fazla işlem yapılır.
- **Ölçek ekonomisi:** İki bilgisayar yerine bir bilgisayara iki işlemci koymak daha ucuzdur. G/Ç aygıtları paylaşılır.
- **Güvenilirlik:** Bir işlemci bozulursa diğerleri sistemi çalıştırmaya devam eder. Servis biraz yavaşlar ama kesilmez.

Türleri:

- **Asimetrik çoklu işlem:** İşlemcilerden biri diğerlerine ne zaman, neyin çalışacağını söyler ve onları yönetir. Hoca, CPU'nun yanında GPU'nun derin öğrenme gibi özel bir iş için kullanılmasını da asimetriye örnek verdi.
- **Simetrik çoklu işlem (SMP):** Bütün işlemciler aynı seviyededir ve her işi yapabilir. Günümüz sistemlerinin hepsi SMP'dir. Her işlemcinin kendi yazmaçları ve önbelleği vardır. Hepsi ortak ana belleğe erişir. Aynı anda erişmek isteyen işlemcilerin sıraya konması gerekir.

Bir kutu içinde birden fazla işlemci olan yapıya **sıkı bağlı (tightly coupled)** sistem denir. Ayrı bilgisayarların birleştirildiği yapıya **gevşek bağlı (loosely coupled)** sistem denir, ör. kümeler.

**Çok çekirdekli tasarım (multi-core):** Birden fazla işlemci paketi koymak yerine, bir paketin içine birden fazla çekirdek konur. Masaüstü ve dizüstü bilgisayarlarda bu kullanılır. Sunucularda ise çok çekirdekli birden fazla işlemci birlikte kullanılır. Aynı alanda daha çok işlem gücü elde edilir. Bedeli ısınma ve güç tüketimidir, ama maliyet çok düşer.

Hoca sanal çekirdeklere de değindi. İşlemcinin spekinde 4 çekirdek yazar, işletim sistemi 8 çekirdek görür. Bu bire bir iki kat başarım vermez, ama kullanım oranını (utilization) iyileştirir.

### Kümelenmiş sistemler

Bağımsız sistemler (düğümler, node) birbirine bağlanarak bir küme (cluster) kurulur. Kümenin adı amacına göre değişir.

- **Yüksek başarımlı hesaplama (HPC):** Amaç bir işi parçalara bölüp paralel çalıştırmaktır. Her iş paralelleştirilemez. Seri kalması gereken kısmın büyüklüğü, sistemin ne kadar etkin olacağını belirler.
- **Yüksek erişilebilirlik (high availability):** Amaç düğümler bozulsa da servisin sürmesidir. 40 düğümlü bir kümede 20 düğüm gitse de küme çalışmaya devam eder.
  - **Asimetrik kümeleme:** Bazı düğümler sıcak beklemede (hot standby) yedek oyuncu gibi bekler. Bir sorun olunca devreye girer.
  - **Simetrik kümeleme:** Bütün düğümler aynı anda iş yapar.
- Günümüzde küme düğümleri genelde merkezi bir depolama ağına (storage area network) bağlanır. İstek miktarına göre servis kopyaları dinamik olarak artırılıp azaltılır.

### Çoklu programlama ve zaman paylaşımı

İlk bilgisayarlarda programlar delikli kartlara yazılırdı. Bir operatör programları sıraya dizip tek tek çalıştırırdı. Sonra operatörün yerini işletim sistemi aldı.

- **Çoklu programlama (multiprogramming):** Tek bir kullanıcı CPU'yu ve G/Ç aygıtlarını sürekli meşgul edemez. Bu yüzden bellekte birden fazla iş tutulur. Bir iş G/Ç beklerken CPU başka bir işi çalıştırır. Amaç CPU, bellek ve G/Ç kullanımını verimli yapmaktır.
- **Zaman paylaşımı (time sharing, multitasking):** Etkileşimli sistemlerde kullanıcı, işinin ilerlediğini görmek ister. Klavyeye basınca harf ekranda hemen çıkmalıdır. Tarayıcıda gezinirken arkada müzik çalmaya devam etmelidir. Bunun için CPU işler arasında çok sık geçiş yapar. Geçişler insanın algılayabileceği süreden çok kısa olduğu için bütün işler aynı anda çalışıyormuş gibi görünür.

Çoklu programlamada iş, süreç ve görev (job, process, task) kitapta birbirinin yerine kullanılır. Bellekte işletim sistemi ve çalıştırılacak işler bulunur. İşler bitip bellekten çıktıkça arada boşluklar oluşur. Yeni gelen iş bu boşluklara sığmayabilir. Bu sorun bellek yönetimi konusunda işlenecek.

### Ders sonrası notlar

- **Harvard ve von Neumann tanımı:** Derste von Neumann "tek bus üzerinden hem veri hem adres aktarmak", Harvard "veri ve adres için ayrı baslar" diye anlatıldı. Doğru ayrım komut ile veri arasındadır, adres ile veri arasında değildir.
  - von Neumann mimarisinde komutlar ve veri aynı bellekte durur ve aynı yoldan taşınır. Slayttaki şemada da bellek kutusunda "instructions and data" yazar.
  - Harvard mimarisinde komut belleği ile veri belleği ve bunlara giden yollar ayrıdır. Bu yüzden komut getirme ile veri okuma aynı anda yapılabilir.
- **Sanal çekirdek (hyper-threading, SMT):** Derste işlemcinin çekirdek zamanını "time sharing ile ikiye çıkardığı" söylendi. Eşzamanlı çoklu iş parçacığında (simultaneous multithreading) bir fiziksel çekirdek, iki donanım iş parçacığının durumunu (yazmaç setlerini) ayrı tutar. Çekirdeğin yürütme birimleri iki iş parçacığı arasında aynı anda paylaşılır. Bir iş parçacığı bellek beklerken diğeri boşta kalan birimleri kullanır. Kazanç bu yüzden iki kat değildir.
- **Asimetrik çoklu işlem ve GPU:** Ders kitabındaki asimetrik çoklu işlem, genel amaçlı işlemciler arasındaki patron-işçi ilişkisidir. CPU yanında GPU kullanmak ise farklı tür işlemcilerin birlikte kullanıldığı heterojen hesaplamadır. GPU genel amaçlı bir CPU değildir. Hocanın örneği bir benzetme olarak düşünülmelidir.
- **SMP'de bellek erişim sırası:** Derste aynı anda belleğe erişmek isteyen işlemcilerde "numarası düşük olanın en önce" geldiği söylendi. Bu genel bir kural değildir. Erişim sırası veri yolu hakemliği (bus arbitration) veya bellek denetleyicisi tarafından belirlenir. Kullanılan yöntem mimariye göre değişir, ör. round-robin.
- **Sabit diskte veri saklama:** Derste "metalde ferit çubukların şartlandırılması" diye anlatıldı. Sabit diskte veri, plakaların yüzeyindeki manyetik malzemenin küçük bölgelerinin mıknatıslanma yönüyle saklanır. Bu yüzden elektrik olmadan da kalıcıdır.
- **Microsoft davası:** ABD'deki Internet Explorer davası (United States v. Microsoft) 2001'de bir uzlaşmayla bitti. Bu davada büyük bir para cezası yoktur. Microsoft'a verilen büyük para cezaları Avrupa Birliği'nden gelmiştir. Örnek: 2004'te Windows Media Player'ın Windows'a gömülmesi yüzünden verilen yaklaşık 497 milyon avroluk ceza.
- **Önyükleyicinin yeri:** Önyükleyici işletim sistemiyle gelen bir programdır. Ama GRUB gibi önyükleyiciler çekirdekten ayrı programlardır ve birden fazla işletim sistemini başlatabilir.
- **Kitap adları:** Altyazıdaki "Şilber Şats", "Shivershots" Silberschatz demektir. Stallings'in kitabının tam adı *Operating Systems: Internals and Design Principles*.
- **Altyazı hataları:** "Donalım" donanım, "Trinter" printer, "Havuk" Harvard, "InterRap/interrap" interrupt, "XRStM" bilgisayar sistemi demektir.

**Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
