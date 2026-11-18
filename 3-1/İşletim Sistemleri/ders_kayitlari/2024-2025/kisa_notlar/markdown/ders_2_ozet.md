# Ders 2 Çalışma Özeti

## Genel Konular

- Önyükleme (bootstrap) programı
  - Kullanıcı programlarına bellekte yeri işletim sistemi ayırır; işletim sisteminin kendisini belleğe yükleyen ayrı bir mekanizma gerekir.
  - Elektrik verildiği anda ROM'da (BIOS/UEFI) duran bootstrap programı çalışır: donanımları (klavye, fare, USB, ekran, ses) başlatır, işletim sistemi çekirdeğini (kernel) ana belleğe yükler ve çalıştırmaya başlar.
  - Bu sabit yazılıma firmware denir. ROM, EPROM ve EEPROM (elektrikle silinip yeniden yazılabilen) aşamalarından geçilmiştir; EEPROM BIOS güncellemesine izin verir.
  - Dual boot: bootstrap birden fazla işletim sistemi görürse hangisiyle açılacağını sorar.
- Bilgisayar sistemi organizasyonu
  - Bir veya daha fazla CPU, ortak bir bus üzerinden paylaşılan tek bir ana bellek ve her biri kendi aygıt denetleyicisine (device controller) sahip aygıtlar.
  - CPU ve G/Ç aygıtları eş zamanlı (concurrent) çalışabilir; G/Ç sırasında CPU boş kalmamalıdır.
  - Her aygıt denetleyicisi belli bir aygıt türünden sorumludur ve yerel bir buffer'a sahiptir. İşletim sistemi denetleyiciyle aygıt sürücüsü (device driver) üzerinden konuşur.
  - Denetleyici işini bitirdiğini CPU'ya kesme (interrupt) ile bildirir (ekrandan, 00:21:30).
- Kesmeler ve zaman paylaşımı
  - Kesme vektörü (interrupt vector), gelen kesmeyi ilgili kesme servis rutinine (interrupt service routine, ISR) yönlendirir. ISR normal bir fonksiyondur ama kodla çağrılmaz, bir olay (tuşa basma, G/Ç) tetikler.
  - Kesmeye giderken de fonksiyon çağrısındaki gibi o anki durum yığına (stack) kaydedilir.
  - Yazılım kaynaklı kesmeler: trap ya da exception (sıfıra bölme, yetkisiz bellek erişimi, `printf`/`scanf` gibi G/Ç istekleri).
  - Zaman paylaşımı (time sharing): tek işlemcide programlar zaman aralıklarını örtüşmeden kullanır; geçişler kesmelerle olur. Frekans paylaşımı işlemciyi analog dünyaya döndüreceği için tercih edilmez.
  - Kesme gecikmesi (interrupt latency): kesmenin çözümlenip servis rutinine geçilmesi için geçen süre.
  - Kesme zaman çizelgesi (ekrandan, 00:35:30): G/Ç isteği gelir, aygıt aktarıma geçer, aktarım bitince CPU kısa bir süre G/Ç kesmesini işler, sonra kullanıcı sürecine döner.
  - `printf` donanıma doğrudan erişemez; `write` sistem çağrısını kullanır. Aygıt durum tablosu (device status table) hangi aygıtın boşta, hangisinin kime atanmış olduğunu tutar.
- Depolama yapısı ve hiyerarşisi
  - Ana bellek: rastgele erişimli (random access) ama uçucu ve kapasitesi sınırlı.
  - İkincil bellek (sabit disk, SSD): büyük kapasite, daha yavaş erişim.
  - Hiyerarşi; kapasite, hız ve uçuculuk açısından kurulur. Önbellek (cache) CPU register'ları ile RAM arasındaki hız farkını dengeler, sık kullanılan veriyi tutar.
  - Slayttaki tablo (ekrandan, 01:35:30): register'ları derleyici, önbelleği donanım, ana belleği ve diskleri işletim sistemi yönetir.
- Doğrudan bellek erişimi (DMA)
  - Hızlı G/Ç aygıtları için denetleyici, veri bloklarını CPU'ya uğramadan doğrudan ana belleğe aktarır; her bayt yerine her blok için bir kesme üretilir (ekrandan, 00:48:30).
- Çok işlemcili sistemler
  - Çok işlemcili (paralel, sıkı bağlı) sistemler: daha fazla verim (throughput), ölçeklenebilirlik, güvenilirlik.
  - Asimetrik çok işlemcilik: her işlemciye belirli bir görev atanır. Simetrik çok işlemcilik: her işlemci her işi yapabilir; her CPU'nun kendi register'ları ve önbelleği vardır.
  - Çok çekirdekli (multicore) yongalar: tek yonga üzerinde birden çok çekirdek; daha az bus ve bağlantı gerektirir.
  - Küme (cluster) sistemleri: ortak depolamayı paylaşan çok sayıda bilgisayar; depolama ve yüksek başarımlı hesaplama için.
- İşletim sistemi yapısı
  - Çoklu programlama: birden çok iş (job) bellekte bulunur, iş zamanlama (job scheduling) yapılır.
  - Çok görevlilik (multitasking, time sharing): CPU işler arasında o kadar hızlı geçer ki paralel çalışıyormuş gibi görünür; yanıt süresi bir saniyenin altında olmalıdır.
  - Bellek yetmezse takas (swap) ve sanal bellek (virtual memory) kullanılır.
  - Kesmeler donanım ya da yazılım kaynaklı olabilir.
- İkili mod (dual mode) işlem
  - Kullanıcı modu (mode bit = 1) ve çekirdek modu (mode bit = 0) (ekrandan, 01:23:00).
  - Kesmeleri kapatmak gibi ayrıcalıklı komutlar (privileged instructions) yalnız çekirdek modunda çalışır.
  - Kullanıcı süreci sistem çağrısı yapınca trap oluşur, mod biti 0 olur, sistem çağrısı çalışır, dönüşte mod biti 1 olur.
- İşletim sisteminin görevleri
  - Süreç yönetimi: süreç oluşturma, sonlandırma, askıya alma ve devam ettirme, senkronizasyon, süreçler arası iletişim, deadlock çözümü.
  - Bellek yönetimi: hangi bölgenin kime ayrıldığını ve hangilerinin boş olduğunu izleme, ayırma ve geri alma.
  - Depolama yönetimi: blok aktarımı, dosya sistemi (oluşturma, silme, izinler, yedekleme), yığın depolama (mass storage).
  - Önbellek tutarlılığı (cache coherence): çok işlemcide bir sürecin verisi farklı önbelleklerde tutarsız kalabilir; snoopy cache ile çözülür.
  - G/Ç alt sistemi: donanımın karmaşıklığını kullanıcıdan gizler.
  - Koruma (protection) ve güvenlik (security): süreçlerin birbirinin alanına girememesi; virüs, worm gibi saldırılara karşı korunma; kullanıcı kimlikleri ve yetki yönetimi.
- Çekirdek veri yapıları
  - Bağlı listeler (tek, çift, dairesel), ikili arama ağaçları (dengeli ağaçlarda en kötü $O(\log n)$, dengesizde $O(n)$), dengeli ağaçlar (AVL, red-black), hash (idealde $O(1)$), bitmap.
  - Linux'ta `<linux/list.h>`, `<linux/kfifo.h>`, `<linux/rbtree.h>` (ekrandan, 01:51:30).
- Hesaplama ortamları
  - Geleneksel bilgisayarlar, mobil sistemler (iOS, Android), gömülü sistemler, dağıtık sistemler, istemci-sunucu ve eşler arası (peer-to-peer) yapılar.
  - DHCP ile IP alınması; IP adresi ve port birleşerek soket (socket) oluşturur.
  - Sanallaştırma ve emülasyon: sanal makine yöneticisi (VMM) ile bir donanımda birden çok işletim sistemi.
  - Bulut bilişim, gerçek zamanlı sistemler (otonom araç), açık kaynak işletim sistemleri (Linux çekirdeği, BSD, macOS).

## Hocanın Özellikle Vurguladığı Kısımlar

- Bootstrap'in görevi
  - İşletim sistemi de bir programdır ve belleğe yüklenmesi gerekir; bu işi ROM'daki bootstrap programı yapar.
- Yerel buffer ve `scanf` örneği
  - `scanf("%d", &x);` ardından `scanf("%c", &y);` yapılırsa, ilk girişte basılan Enter karakteri buffer'da kalır ve ikinci `scanf` onu okur (ekrandan, 00:21:30). Çözüm: `" %c"` biçiminde boşluk koymak ya da giriş buffer'ını boşaltmak.
- Kesme, programlar arasında "mikrofonu" dolaştırır
  - CPU bir mikrofon gibidir: kimdeyse o konuşur; kesmelerle mikrofon birinden alınıp diğerine verilir.
- Kullanıcı kesmeleri kapatamamalıdır
  - Kullanıcı programı kesmeleri kapatabilseydi kendi G/Ç ihtiyacına bile yanıt verilemez, sistem tıkanırdı ("bindiği dalı kesmek").
- Veri yapıları ana bellektedir
  - Ağaç, bağlı liste, graf gibi veri yapıları ana bellekte tutulur; diskte tutulduklarını düşünmek yanılgıdır. Bellek tek boyutludur.
- Hiçbir kural kesin değildir
  - Kesmenin komut bitene kadar bekletilmesi kuralı gerçek zamanlı sistemlerde geçerli değildir; anında yanıt (immediate interrupt response) vardır.

## Kısa Tekrar Notları

- Bootstrap: ROM'da durur, donanımı başlatır, çekirdeği RAM'e yükler.
- Firmware: ROM → EPROM → EEPROM.
- Her aygıt denetleyicisinin yerel buffer'ı vardır; aygıt sürücüsü denetleyici ile çekirdek arasında arayüzdür.
- Kesme vektörü → kesme servis rutini; dönüş için durum yığına yazılır.
- Trap/exception: yazılım kaynaklı kesme (sıfıra bölme, yetkisiz erişim, sistem çağrısı).
- Zaman paylaşımı: programlar örtüşmeyen zaman dilimlerinde CPU kullanır.
- `printf` → `write` sistem çağrısı.
- DMA: blok başına bir kesme, CPU araya girmez.
- Asimetrik: işlemciye görev atanır. Simetrik: her işlemci her işi yapar.
- Mod biti: 1 kullanıcı, 0 çekirdek.
- Görevler: süreç, bellek, depolama, G/Ç, koruma ve güvenlik yönetimi.
- Önbellek tutarlılığı sorunu çok işlemcili sistemlerde ortaya çıkar.
- Hash ideal $O(1)$, dengeli ağaç $O(\log n)$.
- IP + port = soket.

## Detaylı Açıklamalar

- **Bootstrap ve firmware.** Bilgisayar açıldığında RAM boştur; bir programın çalışması için RAM'de yeri olmalıdır. Bu yüzden ilk çalışan programın RAM dışında, kalıcı bir yerde (ROM, BIOS) durması gerekir. Bootstrap ("ayakkabı bağcığı") adı, ayakkabını bağlayıp dışarı çıkmaya hazırlanma benzetmesinden gelir. Açılıştaki siyah ekranda BIOS ya da UEFI yazıları görülür, sonra işletim sistemine geçilir; aradaki süreç bootstrap'in işidir. Firmware "sıkı yazılım" demektir: Bir kez yazılıp donanımda saklı kalması amaçlanır. Hocanın anlatımına göre ilk ROM'lar hiç değiştirilemezdi, sonra elektrikle silinebilen EEPROM'lar sayesinde BIOS güncellemesi mümkün oldu.
- **`scanf` ve buffer.** Ekrandaki örnekte (ekrandan, 00:21:30) birinci satır `scanf("%d",&x)`, ikinci satır `scanf("%c",&y)`'dir. Kullanıcı `123` yazıp Enter'a bastığında `123` tamsayıya çevrilip belleğe yazılır, Enter karakteri ise buffer'da bekler. İkinci `scanf` yeni giriş beklemeden bu Enter'ı alır; `y` yazdırıldığında Enter'ın ASCII karşılığı görülür. Bu, yerel buffer'da verinin beklediğini gösteren bir örnektir.
- **Interrupt timeline.** Slayttaki çizimde (ekrandan, 00:35:30) üstte CPU'nun "user process executing" ve "I/O interrupt processing" durumları, altta G/Ç aygıtının "idle" ve "transferring" durumları vardır. G/Ç isteği (I/O request) gelince aygıt aktarıma geçer; aktarım bitince (transfer done) CPU kısa bir süre kesmeyi işler, sonra kullanıcı sürecine döner. Bu kısa süreler, kesmenin çözümlenmesi ve servis rutininin başlatılması için geçen gecikmeyi gösterir.
- **Depolama tablosu.** Slayttaki tablo (ekrandan, 01:35:30):

  ```text
  Seviye          1                2                 3              4                5
  Ad              registers        cache             main memory    solid state disk magnetic disk
  Tipik boyut     < 1 KB           < 16 MB           < 64 GB        < 1 TB           < 10 TB
  Erişim (ns)     0.25 - 0.5       0.5 - 25          80 - 250       25,000 - 50,000  5,000,000
  Bant (MB/s)     20,000-100,000   5,000 - 10,000    1,000 - 5,000  500              20 - 150
  Yöneten         compiler         hardware          operating sys. operating sys.   operating sys.
  Yedeklendiği    cache            main memory       disk           disk             disk or tape
  ```

  Register derleyici, önbellek donanım tarafından yönetilir. Yedekleme yukarıdan aşağıya yapılır: register önbelleğe, önbellek ana belleğe, ana bellek diske, disk teybe.
- **Diskteki verinin register'a yolculuğu.** Bir görüntü işleme programında görüntü önce diskten ana belleğe, oradan (gerekirse önbellekte tutularak) register'lara gelir ve `MOV`, `ADD`, `SUB` gibi komutlarla işlenir. Çok görevli sistemde araya kesme girip süreç çıkarılabilir; veri önbellekte ya da ana bellekte bekler. Çok işlemcili sistemde süreç geri geldiğinde başka bir CPU'ya düşerse iki önbellek arasında tutarsızlık doğabilir. Hoca bunu iki bölüm sekreteri benzetmesiyle anlattı: Bir sekretere derdinizi anlatıp gidersiniz, döndüğünüzde diğer sekreter vardır ve her şeyi baştan anlatmanız gerekir. Snoopy cache mekanizmasında CPU kendi önbelleğinde bulamadığı veriyi yandaki önbellekten alır.
- **İkili mod.** Slayttaki şemada (ekrandan, 01:23:00) kullanıcı süreci çalışırken (mode bit = 1) bir sistem çağrısı yapar; trap ile mod biti 0 olur, çekirdek sistem çağrısını çalıştırır, dönüşte mod biti yeniden 1 olur. C'de bir pointer'a 0 atayıp gösterdiği yere yazmaya çalışmak ya da bir döngüyle belleği sıfırlamaya girişmek, bir noktadan sonra programın kapatılmasıyla sonuçlanır; çünkü sürece ait olmayan bir bellek bölgesine erişilmektedir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
