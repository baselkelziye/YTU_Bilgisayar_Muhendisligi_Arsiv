# Ders 13 Çalışma Özeti

## Genel Konular

- Disco makalesinin genel fikri
  - Derste "Disco: Running Commodity Operating Systems on Scalable Multiprocessors" makalesi (E. Bugnion, S. Devine, K. Govil, M. Rosenblum) soru-cevapla tartışıldı. Bir öğrenci makaleyi kendi işaretlediği yerler üzerinden ekranda paylaştı (ekrandan, 00:20:00; 00:25:00).
  - Büyük ölçekli sistemlerde (çok işlemcili, paylaşımlı bellekli, NUMA mimarili makineler) hazır (commodity) işletim sistemlerini çalıştırmak normalde çok fazla kod değişikliği ister.
  - Disco, işletim sistemi ile donanım arasına giren bir sanal makine izleyicisidir (Virtual Machine Monitor, VMM). Hazır işletim sistemlerini değiştirmeden çalıştırmayı hedefler ve kod miktarı küçüktür.
- Sanal makinelerin karşılaştığı zorluklar (makalenin 3.1 bölümü)
  - Makale dört sorun sayar: donanım kaynaklarının sanallaştırılmasından doğan ek yükler (overheads), kaynak yönetimi, paylaşım ve haberleşme (ekrandan, 00:15:00).
  - Ek yükler: ek istisna (exception) işleme, komut yürütme ve sanallaştırma için gereken bellek. Yetkili komutlar (privileged instructions) işletim sistemine doğrudan verilemez, VMM tarafından yazılımda öykünülür (emulate edilir). G/Ç aygıtlarına erişim de sanallaştırılır; istekler VMM tarafından yakalanır ve yeniden eşlenir.
  - Bellek maliyeti: her sanal makinede işletim sisteminin ve uygulamaların kodu ile verisi, dosya sistemi tampon önbelleği gibi büyük yapılar ayrı ayrı kopyalanır; aynı israf diskteki dosya sistemleri için de olur.
  - Kaynak yönetimi: VMM'nin iyi politika kararı vermek için yeterli bilgisi yoktur. Boşta döngü (idle loop), kilit için meşgul bekleme (busy waiting) ve gerçek bir hesap VMM seviyesinde birbirinden ayırt edilemez. Benzer şekilde VMM bir sayfanın artık kullanılmadığını bilemez (ekrandan, 00:20:00).
  - Paylaşım ve haberleşme: birden fazla bağımsız işletim sistemi arasında paylaşım ve haberleşme zordur. VM/370 üzerindeki CMS'te bir kullanıcının dosyalarını içeren sanal disk bir sanal makinede kullanılırken başka bir sanal makine ona erişemezdi; aynı kullanıcı iki sanal makine başlatamaz, farklı kullanıcılar kolayca dosya paylaşamazdı (ekrandan, 00:20:00).
- NUMA ve CC-NUMA
  - UMA'da tek bellek vardır ve bütün işlemciler belleğe eşit uzaklıktadır; erişim süresi tekdüzedir (uniform).
  - NUMA'da (Non-Uniform Memory Access) birden çok bellek vardır ve her işlemcinin her belleğe uzaklığı farklıdır; erişim süresi tekdüze değildir.
  - CC-NUMA'da işlemci önbellekleri arasında donanım seviyesinde tutarlılık vardır; araya bir ağ katmanı girmez.
  - Ders sonrası not: Hoca CC kısaltmasını önce "closely coupled" diye açtı, sonra cache coherent ile aynı şeyin başka ifadesi dedi. CC-NUMA'nın yerleşik açılımı "cache-coherent NUMA"dır (önbellek tutarlı NUMA).
- Disco'nun çözümleri
  - Disco, FLASH adlı, MIPS R10000 tabanlı, önbellek tutarlı (cache-coherent) bir çok işlemcili makine için yazılmıştır.
  - Sık kullanılan çekirdek işlemleri (kesmeleri açıp kapatma, yetkili yazmaçlara erişim) özel adreslere yapılan load/store komutlarıyla yapılabilir; bu, tuzak öykünmesinin (trap emulation) yükünü azaltır (ekrandan, 00:25:00).
  - Fiziksel bellek: Disco, sıfır adresinden başlayan bitişik bir fiziksel adres uzayı soyutlaması sunar. Dinamik sayfa göçü ve kopyalama (dynamic page migration and replication) ile yazılıma neredeyse tekdüze erişim süreli bir bellek gösterir; böylece NUMA'dan habersiz bir işletim sistemi FLASH'ta iyi çalışır (ekrandan, 00:25:00).
  - Sanal diskler farklı paylaşım ve kalıcılık modelleriyle yapılandırılabilir: sanal makine kapanınca içeriği kaybolan geçici (ephemeral) diskler ve diğer makinelerle salt okunur paylaşılan diskler.
  - Copy-on-write diskler: Disco, belleğe DMA yapan her disk isteğini yakalar. İstenen blok zaten bellekteyse diske gitmeden isteği karşılar; sayfayı sanal makineye salt okunur eşler. Paylaşılan sayfa değiştirilmek istenirse VMM'nin işlediği bir copy-on-write hatası oluşur (ekrandan, 00:30:00).
  - Sanal alt ağ (virtual subnet): sanal makineler kendi aralarında bu sanal ağ üzerinden haberleşir. Ethernet'teki yaklaşık 1500 baytlık MTU sınırı burada yoktur; büyük paketler parçalanmadan (fragmentation olmadan) gönderilir.
  - Gerçekleştirim: Disco çok iş parçacıklı paylaşımlı bellek programı olarak yazılmıştır; NUMA'ya, önbelleğe uygun veri yapılarına ve işlemciler arası haberleşme örüntülerine özel dikkat gösterir. Kilitsiz veri yapıları kullanılır. Bütün sanallaştırma katmanı yaklaşık 13.000 satır koddur.

## Hocanın Özellikle Vurguladığı Kısımlar

- Yetkili komutlar neden doğrudan verilemez?
  - Yetkili komutlar işlemcinin çalışmasını doğrudan etkileyebilen komutlardır: kesmeleri açma/kapama, işlemciyi sıfırlama, bir G/Ç portuna erişip okuma/yazma.
  - G/Ç portu komutları sanal makineye doğrudan açılırsa, o sanal makinedeki işletim sistemi portun arkasındaki donanımın yapısını ve çalışma şeklini değiştirebilir. Bu değişiklik aynı donanımı kullanan diğer sanal makineleri etkiler.
  - Konuk işletim sistemi bu komutları kullanmak zorundadır, çünkü kodu buna göre yazılmıştır. Çözüm öykünmedir: VMM komutu yakalar, hedef donanımı sanallaştırır ve paylaşımlı kullanılmasını sağlar. Dolayısıyla yetkili komutlarla birlikte G/Ç aygıtları da sanallaştırılır.
- Boşta döngü, meşgul bekleme ve gerçek hesap ayırt edilemez
  - Gerçek donanımda (bare metal) işletim sisteminin çalıştıracak prosesi ya da thread'i yokken boşta döngüye ihtiyacı vardır, çünkü işlemci duramaz.
  - Sanal ortamda bu boş zamanın fark edilip işlemcinin o sanal makineden alınması ve başka bir sanal makineye verilmesi en doğrusudur.
  - Matris çarpımı (anlamlı, hesap yoğun iş), kilidin boşalıp boşalmadığını sürekli kontrol etme (meşgul bekleme) ve boşta döngü üçü de işlemciyi yoğun kullanır. VMM bunları ayırt edemezse kaynakları yanlış sanal makinelere yanlış zamanda verir; anlamlı iş için CPU bekleyen sanal makine CPU alamaz.
- Makaleyi özlü ve dikkatli okumak
  - Hoca, makalenin bazı kısımlarının hızlı okunup atlandığını belirtti ve makalenin daha özlü, dikkatli okunması gerektiğini söyledi ("Sürat felakettir").

## Kısa Tekrar Notları

- Disco: hazır işletim sistemlerini ölçeklenebilir çok işlemcilerde (NUMA) değiştirmeden çalıştıran küçük bir VMM.
- Sanal makine sorunları: ek yük, kaynak yönetimi, paylaşım, haberleşme.
- Yetkili komut ve G/Ç erişimi doğrudan verilmez; VMM öykünür ve sanallaştırır.
- VMM boşta döngü, meşgul bekleme ve gerçek hesabı ayırt edemez; kullanılmayan sayfayı da bilemez.
- UMA: tek bellek, eşit erişim süresi. NUMA: çok bellek, farklı erişim süreleri. CC-NUMA: önbellekler arası donanım tutarlılığı.
- FLASH: MIPS R10000 tabanlı önbellek tutarlı çok işlemcili makine.
- Dinamik sayfa göçü ve kopyalama: NUMA belleği yazılıma neredeyse tekdüze gösterir.
- Copy-on-write disk: bellekteki blok diske gitmeden ve kopyalanmadan salt okunur paylaşılır; yazmada kopya çıkar.
- Sanal diskler: geçici (ephemeral) ya da paylaşımlı (salt okunur) modeller.
- Sanal alt ağ: Ethernet'in 1500 baytlık MTU sınırı yok, parçalanmadan büyük aktarım.
- Disco yaklaşık 13.000 satır koddur.

## Detaylı Açıklamalar

- Disco'nun konumu
  - Büyük ölçekli paylaşımlı bellekli ve NUMA mimarili makineler için hazır işletim sistemlerini uyarlamak çok fazla kod değişikliği ister. Disco bu değişikliği işletim sistemi yerine aradaki ince VMM katmanında yapar. Böylece birden fazla konuk işletim sistemi aynı makinede çalışabilir; bu katmanın ayrıca optimize edilip ayarlanabilmesi de önemli bir kazançtır.
- Ek yükler ve yetkili komutlar
  - Klasik VMM'lerde ek yük, ek istisna işleme, komut yürütme ve sanallaştırma için gereken bellekten gelir. Yetkili komutlar ve G/Ç erişimi konuk işletim sistemi tarafından kullanılmak zorundadır, ama doğrudan donanıma ulaşırsa diğer sanal makineleri bozabilir. Bu yüzden VMM bu komutları yakalar ve öykünür; G/Ç isteklerini yakalayıp gerçek aygıtlara yeniden eşler. Bir G/Ç aygıtı bir sanal makineye tamamen atanırsa diğer sanal makinelerin onu nasıl kullanacağı sorusu doğar; bu da aygıtların sanallaştırılmasını gerektirir.
  - Disco, MIPS işlemcisinin öykünmesinin yanında mimariyi genişletir: kesmeleri açıp kapatma ve yetkili yazmaçlara erişim gibi sık çekirdek işlemleri özel adreslere load/store ile yapılır. Disco'ya göre ayarlanmış işletim sistemleri böylece tuzak öykünmesinin yükünü azaltır (ekrandan, 00:25:00).
- Kaynak yönetimi
  - VMM, işletim sisteminin sahip olduğu üst düzey bilgiye sahip değildir. Komut akışına bakarak boşta döngüyü, kilit için meşgul beklemeyi ve gerçek hesabı ayırt edemez. Sonuç, makalenin ifadesiyle, faydalı hesap beklerken VMM'nin kaynakları faydasız hesaba ayırabilmesidir (ekrandan, 00:20:00). Aynı şekilde bir sayfanın artık etkin kullanılmadığını bilemediği için onu başka bir sanal makineye veremez.
- Paylaşım ve haberleşme
  - VM/370 üzerindeki CMS örneğinde sanal makineler aynı donanımı paylaşan bağımsız sistemler gibiydi: bir sanal disk aynı anda iki sanal makinede kullanılamazdı. Disco bunu yapılandırılabilir sanal disklerle (geçici ya da salt okunur paylaşılan) ve sanal alt ağ ile çözer. Sanal alt ağda MTU sınırı Ethernet'teki gibi değildir; büyük veriler parçalanmadan tek seferde aktarılabilir.
- NUMA ve bellek
  - NUMA'da işlemcilerin farklı belleklere uzaklığı farklıdır. Çoğu hazır işletim sistemi FLASH'ın NUMA belleğini etkin yönetemez. Disco dinamik sayfa göçü ve kopyalamayla yazılıma neredeyse tekdüze bellek erişim süresi gösterir; NUMA'dan habersiz işletim sistemi değişiklik gerekmeden iyi çalışır (ekrandan, 00:25:00).
  - <!-- BELİRSİZ: Derste "dynamic page migration and replication" sorusu cevaplanmadı; öğrenci ayrıntıyı anlamadığını söyledi. -->
- Copy-on-write diskler
  - Disco belleğe DMA yapan her disk isteğini yakalar. Okunmak istenen disk bloğu zaten ana bellekteyse istek diske gitmeden karşılanır. İstek makinenin sayfa boyutunun katıysa Disco sayfayı sanal makinenin fiziksel belleğine eşler; DMA anlamını korumak için sayfayı salt okunur eşler. Paylaşılan sayfaya yazma girişimi VMM'nin işlediği bir copy-on-write hatası doğurur (ekrandan, 00:30:00). Böylece aynı kök diski kullanan sanal makineler çekirdek ve uygulama kodunu bellekte tek kopya olarak paylaşır ve bellek kullanımı azalır.
- Gerçekleştirim
  - Disco çok iş parçacıklı paylaşımlı bellek programı olarak yazılmıştır. NUMA'ya, önbelleği iyi kullanan veri yapılarına ve işlemciler arası haberleşme örüntülerine dikkat edilir; klasik kilitli veri yapıları yerine kilitsiz yapılar kullanılır. Bütün katman yaklaşık 13.000 satırdır.
  - <!-- BELİRSİZ: Altyazıda "Waze Pre-Segmentation veya Freelock Data Structure" geçiyor; büyük olasılıkla "wait-free synchronization" ve "lock-free data structures" kastediliyor. -->

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
