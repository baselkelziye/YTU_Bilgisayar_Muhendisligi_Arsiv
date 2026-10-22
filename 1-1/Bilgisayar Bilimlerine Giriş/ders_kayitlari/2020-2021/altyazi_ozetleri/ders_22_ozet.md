# Ders 22 Çalışma Özeti

## Genel Konular

- Ödevle ilgili notlar
  - Sözlük uygulamasında küçük/büyük harf karışık verilirse genelde bütün girdi küçük ya da büyük harfe çevrilir ve sözlük tek biçimde saklanır. Bu ödevde zorunlu değildir.
  - Gerçek bir sözlük uygulamasında aynı kelime iki kez bulunmaz. Kelime eklenmeden önce var olup olmadığı kontrol edilir, varsa kullanıcıya mesaj verilir.
  - `string.h` (`strlen`, `strcmp`) kullanılmadan kelime uzunluğu, null karakteri görülene kadar ilerleyerek bulunur.
- Bilgisayar mimarisi (computer architecture)
  - Bilgisayarın işini yapmasını sağlayan bütün birimler mimarinin parçasıdır: CPU (Central Processing Unit), ana bellek (main memory), anakart (motherboard) vb. Anakart, bütün parçaların birbiriyle konuşmasını sağlar.
  - Mobil cihazlardaki ve gömülü sistemlerdeki küçük, özel tasarımlı işlemcilere mikroişlemci (microprocessor) denir.
  - CPU'nun birimleri: kontrol birimi (control unit), aritmetik mantık birimi (arithmetic logic unit, ALU) ve register birimi.
  - Bellek hiyerarşisi: register → cache (seviyeleri vardır) → ana bellek → ikincil bellek (secondary memory). Sona doğru kapasite artar, birim maliyet azalır. Register, birim başına en pahalı ve en hızlı bellektir.
  - Genel amaçlı register'larda işlenecek veri, özel amaçlı register'larda programın akışıyla ve komutlarla ilgili bilgiler saklanır.
- Makine dili ve komut seti
  - Makine dili 0 ve 1 kombinasyonlarından oluşur. Her CPU'nun bir komut seti (instruction set) vardır. Toplama, çıkarma, veri taşıma, kaydırma, koşula göre programın hangi noktadan devam edeceği gibi bütün işler burada tanımlıdır.
  - Komut seti mimarisinde iki temel yaklaşım vardır:
    - RISC (Reduced Instruction Set Computer): az sayıda, basit ve genel komut. Karmaşık işler basit komutların birleşimiyle yapılır. Enerji verimlidir. ARM işlemciler bu yaklaşımı kullanır ve cep telefonu gibi enerji kısıtlı cihazlarda tercih edilir.
    - CISC (Complex Instruction Set Computer): karmaşık işler için ayrı komutlar tanımlanır, bu yüzden komut sayısı fazladır. Karmaşık işlerde daha performanslıdır ama daha çok enerji tüketir. Intel'in PC işlemcileri bu yaklaşımı kullanır.
  - Bir işlemcinin RISC yaklaşımıyla tasarlanmış olması karmaşık işleri yapamayacağı anlamına gelmez. Örneğin ARM mimarili dizüstü bilgisayarlar çıkmıştır. Kesin karar için işlemcinin komut setine bakmak gerekir.
- Temel işlemler (elementary operations)
  - AND, OR, XOR, NOT gibi mantık işlemleri, store (register'daki veriyi belleğe yazma), shift, rotate ve jump.
  - Komutun bir kısmı işlem kodudur (operation code, opcode), kalanı işlenecek veridir (operand). Örneğin `0011` işlem kodu "store" anlamına gelebilir. AND iki operand, NOT tek operand ister.
  - Shift (kaydırma): `0111` sola kaydırılınca `1110`, sağa kaydırılınca `0011` olur. Sola kaydırma sayıyı 2 ile çarpmak, sağa kaydırma 2'ye bölmek demektir.
  - Rotate (döndürme): taşan bit diğer uçtan geri girer. `0111` sağa döndürülünce `1011`, sola döndürülünce `1110` olur.
- Makine döngüsü (machine cycle) (ekrandan, 00:33:00)
  - Fetch: bir sonraki komutu bellekten getirir ve program sayacını (program counter) artırır.
  - Decode: komut register'ındaki (instruction register) bit örüntüsünü çözümler, ne yapılacağına karar verir.
  - Execute: komutun gerektirdiği işlemi gerçekleştirir.
- İşlemci hızı ve karşılaştırma
  - Bilgisayarda sürekli darbe (pulse) üreten bir saat (osilatör, oscillator) vardır. Saniyedeki darbe sayısı işlemci hızını verir. Örneğin 1 GHz işlemci saniyede yaklaşık bir milyar darbe üretir.
  - 2 GHz bir işlemci 1 GHz bir işlemciden her zaman hızlıdır denemez. Bir komutun kaç saat döngüsünde (clock cycle) çalıştığı işlemciden işlemciye değişir. Örneğin toplama bir işlemcide 3, diğerinde 5 döngü sürebilir. Aynı ailede bile mimariler (8086, 80386, 80486...) ve çekirdek sayıları farklıdır.
  - Karşılaştırma için benchmark testleri kullanılır: iki makineye aynı işler yaptırılır ve süreleri ölçülür. Bir işte iyi olan işlemci başka bir işte daha kötü olabilir. Bellek ve GPU kullanımı gibi etkenler sonucu değiştirir.
  - Donanımın kendi içinde uyumlu olması önemlidir. Örneğin Apple donanımı ve yazılımı birlikte tasarladığı için performanslı ürünler çıkarabilir.
- Cihazlarla haberleşme
  - Bilgisayarla diğer cihazlar (CD sürücü, modem, monitör, disk) arasındaki haberleşme bir ara birim üzerinden yapılır: denetleyici (controller). Birimler bus yapısı üzerinden konuşur.
  - Ana bellek denetleyici kullanmaz. CPU ana belleğe doğrudan adresle eriştiği için iletişim çok daha hızlıdır. Denetleyiciler bir dönüşüm yaptığı ve sürücü (driver) gerektirdiği için bir maliyet getirir. Doğrudan bellek erişimi (DMA, Direct Memory Access) önemli bir performans sağlar.
  - Paralel haberleşme (parallel communication): bilgi aynı anda farklı hatlar üzerinden aktarılır. Örneğin 8 hat varsa aynı anda 8 bit gönderilir. Örnek: yazıcılar (eski paralel port).
  - Seri haberleşme (serial communication): bilgi aynı hat üzerinden arka arkaya gönderilir. Örnek: SATA diskler, USB. Paralel cihazlar daha maliyetli ve karmaşık olduğu için son yıllarda çoğu cihaz seri haberleşme kullanır.
- Haberleşme hızı ve bant genişliği (ekrandan, 01:30:00)
  - Haberleşme hızı saniyedeki bit sayısıyla ifade edilir: bps, Kbps, Mbps, Gbps.
  - Bit ile byte'ı karıştırmayın: 8 Kbps = 1 KB/s (kilobyte per second). Byte cinsinden hız için bit cinsinden değer 8'e bölünür.
  - Bant genişliği (bandwidth): bir hattın taşıyabileceği en fazla veri miktarı. Fiziksel hattın kapasitesi ile kullanılan cihazın sağlayabildiği hız ayrı bant genişlikleridir.
  - Kablolu (wired) ve kablosuz (wireless) haberleşme vardır. Kablolu: yerel ağ (LAN), metropol ağ (MAN), geniş ağ (WAN), ayrıca bilgisayara bağlanan bir disk.
- Portlar
  - Fiziksel portlar: USB, M.2, HDMI, VGA, DVI vb. Örneğin harici disk bilgisayarla USB portu üzerinden seri haberleşir.
  - Sanal portlar 0 ile 65535 arasında numaralandırılır. Örnekler: FTP (File Transfer Protocol), SSH (güvenli bağlantı), SMTP (Simple Mail Transfer Protocol), POP3 ve IMAP (e-posta), HTTP (80), HTTPS (443, güvenli web bağlantısı).
  - Portlar bilgisayarın giriş-çıkış kapılarıdır. Açık portlar saldırıya açıktır. Port tarama ile açık port bulunup kaba kuvvet (brute force) saldırısı yapılabilir. Gereksiz portlar kapatılabilir.
- Protokoller
  - Protokol, iki cihazın veya birimin birbiriyle haberleşirken uyduğu kurallardır.
  - Örnekler: IP, TCP, UDP (ağ haberleşmesi), Bluetooth, NFC, Wi-Fi, HTTP, FTP, SMTP, SSH, IMAP.
  - Wi-Fi "kablosuz internet" demek değildir. İnternet, bilgisayarların birbirine bağlandığı geniş bir ağdır. Modeme kabloyla bağlanınca Ethernet, kablosuz bağlanınca Wi-Fi protokolü kullanılır. Wi-Fi'nin altında IEEE 802 ile başlayan a, b, g, n gibi alt protokoller vardır. Hücresel ağlarda (GSM, cellular network) da 2G, 3G, 4G, 4.5G, 5G gibi protokoller vardır. Yeni nesiller haberleşmeyi hızlandırır ve hata oranını düşürür.
  - Kablosuz haberleşmede bilgi farklı frekanslardaki radyo dalgalarıyla taşınır (radyonun AM, FM bantları gibi).
  - Kablosuz haberleşme örnekleri: Bluetooth, GSM, Wi-Fi, NFC, kızılötesi (infrared). Kızılötesi kısa mesafede çalışır ve önünde engel olmaması gerekir. Bu yüzden kumandanın önüne bir şey gelince çalışmaz. Pasif kızılötesi sensörler koridor ışıklarında hareket algılamak için kullanılır. Araçlardaki park sensörleri ise ultrasonik ses dalgalarıyla çalışır.
- İşletim sistemi (operating system)
  - İşletim sistemi, bilgisayarın kaynaklarını verimli bir şekilde kullanmasını sağlayan yazılımdır.
  - Örnekler: Windows, macOS, Linux, Unix (PC); Android, iOS (mobil); bunların birden fazla kullanıcının aynı anda çalışabildiği sunucu sürümleri.
  - Toplu işleme (batch processing): işler tek seferde, kullanıcıyla etkileşim olmadan arka arkaya yapılır. İşler bir iş kuyruğunda (job queue) FIFO (First In, First Out) mantığıyla bekler. Tarihte kalmış bir yaklaşımdır. Bugün bankalarda gece belirli saatlerde çalışan zamanlanmış işler (cron job) bu mantığı hatırlatır, ama bu cihazlar aynı anda tek bir iş yapmaz.
  - Etkileşimli işleme (interactive processing): program çalışırken kullanıcı onunla etkileşir. Örneğin Word'de yazıp silmek, müziği durdurup yeniden başlatmak.
  - Gerçek zamanlı işleme (real-time processing, ekrandan, 02:10:00): bilgisayar görevleri belirli bir süre sınırı (deadline) içinde yapmak zorundadır. Örneğin radyodan müzik dinlerken ses saniyeler sonra değil, anında gelmelidir.
  - Zaman paylaşımı (time-sharing): birden fazla kullanıcı aynı bilgisayara bağlanıp CPU'yu paylaşır. Bunu gerçekleştirmenin bir yolu çoklu programlamadır (multiprogramming): zaman aralıklara bölünür ve her iş bir seferde yalnızca bir aralıkta çalışır. Ek işlemci ya da çekirdek yoksa bir anda yalnızca bir iş yapılır. İşler sırayla işlemciyi kullandığı için aynı anda çalışıyormuş gibi görünür.
  - Çoklu görev (multitasking): çoklu programlama tekniğinin tek kullanıcılı ortama aktarılmış hâli. Bugünkü bilgisayarlar böyle çalışır ve bunu işletim sistemi sağlar.
- Gömülü sistemler (embedded systems)
  - Belirli görevlere adanmış cihazlar: tıbbi cihazlar, araç elektroniği, ev aletleri, eski tip cep telefonları. Örnekler: çamaşır makinesi, ekmek kızartma makinesinin kızarmayı algılayan sistemi.
  - Bilgisayar birçok görevi yönetmek için tasarlanır, gömülü sistem ise belirli bir görev için. Akıllı telefonlar artık bilgisayara dönüştüğü için bu kategoride sayılmamalıdır.
  - Gömülü sistemlerin her biri için bir işletim sistemi gerekmez. Bazılarında vardır (ör. araçlar için Android). Yapılacak görevler belli olduğu için işletim sisteminin karmaşık yapısına çoğu zaman ihtiyaç yoktur.
  - BIOS (Basic Input Output System) gömülü sistem örneği değildir. BIOS, bilgisayarın donanımını temel seviyede yapılandırmak için kullanılan bir yazılımdır.
- İşletim sistemi mimarisi (ekrandan, 02:25:40)
  - Yazılım sınıflandırması: yazılım (software) uygulama (application) ve sistem (system) yazılımı olarak ikiye ayrılır. Sistem yazılımı da yardımcı yazılımlar (utility) ve işletim sistemi olarak ikiye ayrılır. İşletim sistemi kullanıcı arayüzü (user interface) ve çekirdekten (kernel) oluşur.
  - Uygulama yazılımları: Word, müzik ve video oynatıcılar gibi.
  - Yardımcı yazılımlar (utility): sistemi yönetmeye yardımcı yazılımlar. Örnekler: diski bölümlere ayırma (partition), disk temizleme, Windows'ta otomatik güncellemeleri yöneten yazılım, görev yöneticisi. İşletim sistemine ait olanlar ve üçüncü taraf (third party) olanlar vardır.
  - Çekirdek (kernel): işletim sisteminin temel görevlerini kullanıcı müdahalesi olmadan yürüten kısmıdır. Bu görevler: süreç yönetimi (process management), bellek yönetimi (memory management), dosya yönetimi (file management), giriş-çıkış yönetimi (I/O management), ağ yönetimi (network management). Çekirdeğe ancak yetkili kişiler belirli müdahaleler yapabilir.
  - Kullanıcı arayüzü: kullanıcı, çekirdeğe kullanıcı arayüzü üzerinden komut gönderir.
    - Komut satırı (shell, kabuk): komutlar klavyeyle yazılır. Eski bir yöntemdir ama hâlâ hızlıdır. Uzaktaki bir bilgisayara grafik arayüz kurmadan bağlanıp iş yaptırmak için sık kullanılır.
    - Grafik kullanıcı arayüzü (GUI): pencere yöneticisi (window manager) ile pencereler, düğmeler ve menüler üzerinden çalışılır. Komutların grafik arayüze aktarılmış hâli gibi düşünülebilir.
    - Grafik arayüzde yapılan her şey komut satırından da yapılabilir.

## Hocanın Özellikle Vurguladığı Kısımlar

- Hazır fonksiyonların (`strlen`, `strcmp`) kullanılmamasının sebebi, işin nasıl yapıldığını öğrenmenizdir. Bu fonksiyonları ileriki yıllarda zaten çok kullanacaksınız.
- RISC ve CISC'in biri diğerinden kesin olarak üstün değildir. RISC enerji verimliliği, CISC karmaşık işlerde performans için öne çıkar. Seçim yapılacak işe bağlıdır.
- İşlemcileri yalnızca GHz değerine bakarak karşılaştırmayın. Bu yalnızca genel bir fikir verir. Benchmark sonuçları da yaptırılan işe göre değişir.
- Bit ve byte'ı karıştırmayın: Kbps kilobit, KB/s kilobyte demektir.
- Wi-Fi bir protokoldür, "kablosuz internet" değildir.
- Bir şeyi bildiğiniz hâlde anlatmakta zorlanıyorsanız, ifade etme becerinizi geliştirmeniz gerekir. Kavramları kendi cümlelerinizle tanımlayabilmelisiniz.
- Derse katılıyorsanız bilgisayarın başında olun ve size söz verildiğinde cevap verin. Bilmiyorsanız "bilmiyorum" demek de bir cevaptır.

## Kısa Tekrar Notları

- CPU birimleri: control unit, ALU, register.
- Bellek hiyerarşisi: register → cache → main memory → secondary memory.
- RISC: basit komutlar, enerji verimli, ARM. CISC: karmaşık komutlar, performans, Intel.
- Komut = opcode + operand.
- Shift `0111`: sola `1110`, sağa `0011`. Rotate `0111`: sağa `1011`, sola `1110`.
- Makine döngüsü: fetch → decode → execute.
- GHz tek başına hız ölçüsü değildir. Benchmark kullanılır.
- Denetleyici (controller) cihazlarla haberleşmeyi sağlar. Ana belleğe doğrudan erişilir (DMA).
- Paralel: aynı anda çok hat. Seri: tek hat, arka arkaya.
- 8 Kbps = 1 KB/s. Bant genişliği = hattın en fazla veri taşıma kapasitesi.
- Sanal portlar 0-65535. HTTP 80, HTTPS 443.
- Protokol = haberleşme kuralları.
- Batch → interactive → real-time. Time-sharing, multiprogramming, multitasking.
- Gömülü sistem = belirli bir göreve adanmış cihaz.
- Software → application / system → utility / operating system → user interface / kernel.
- Kernel görevleri: process, memory, file, I/O, network management.

## Detaylı Açıklamalar

Dersin ilk bölümünde 3. ödevle ilgili kısa sorular cevaplanır. Ardından bilgisayar mimarisine geçilir: CPU'nun birimleri, bellek hiyerarşisi, makine dili, RISC ve CISC yaklaşımları, temel işlemler, makine döngüsü ve işlemci hızının nasıl karşılaştırılacağı konuşulur. Aradan sonra cihazlarla haberleşme, paralel ve seri haberleşme, haberleşme hızı, bant genişliği, portlar ve protokoller anlatılır. Son bölümde işletim sistemlerine geçilir: işleme türleri, zaman paylaşımı, çoklu görev, gömülü sistemler ve işletim sistemi mimarisi. İşletim sistemlerinin kalan kısmı ve ağ konusu sonraki haftalara bırakılmıştır.

### Paralel ve seri haberleşme farkı

Bir öğrenci, paralel haberleşmede gönderilen işlerin yazıcıda sıraya konmasıyla paralelliği karıştırdı. Hoca ikisini ayırdı. İşlerin yazıcı kuyruğunda sıraya girmesi ayrı bir konudur. Paralel haberleşme, tek bir işe ait verinin aktarılma biçimidir. Örneğin bir satırın verisi gönderilirken paralel haberleşmede aynı anda 8 hat üzerinden 8 bit gönderilir. Seri haberleşmede bu bitler aynı hat üzerinden sırayla gönderilir.

### Batch ve interactive processing farkı

Bir öğrenci, C ile yazılan ve girdiyi alıp sonucu veren programların toplu işleme sayılıp sayılmayacağını sordu. Hoca, toplu işlemenin tarihte kalmış bir yaklaşım olduğunu vurguladı. Toplu işlemede CPU aynı anda başka hiçbir şey çalıştırmaz ve kullanıcıyla etkileşmez: girdiyi alır, programı çalıştırır, çıktıyı üretir. Bugün bir C programı çalışırken arka planda başka programlar da çalışır. Program çoğu zaman her girdiden sonra yeni girdi isteyerek kullanıcıyla etkileşir. Bu yüzden bugünkü programlar toplu işleme örneği değildir.

### Zaman paylaşımı ve çoklu görev nasıl çalışır?

Tek bir işlemci çekirdeği bir anda yalnızca bir iş yapabilir. Çoklu programlamada zaman küçük aralıklara bölünür. Her süreç sırası gelince bir aralık boyunca işlemciyi kullanır, sonra işlemciyi bir sonrakine bırakır. Bu geçişler çok hızlı olduğu için kullanıcı Word'e yazarken, internette gezinirken ve müzik dinlerken bunların aynı anda çalıştığını düşünür. Aynı mantık birden fazla kullanıcıya uygulandığında zaman paylaşımı, tek bir kullanıcının birden fazla işine uygulandığında çoklu görev adını alır.

### Ders sonrası kontrol notları

- Derste 1 kHz, 1 MHz ve 1 GHz için $2^{10}$, $2^{20}$ ve $2^{30}$ değerleri söylendi. Frekans birimlerinde önekler ondalıktır: 1 kHz = $10^3$, 1 MHz = $10^6$, 1 GHz = $10^9$ Hz. İkili katlar ($2^{10}$ = 1024) bellek boyutu (KiB, MiB, GiB) için kullanılır. $2^{30}$, $10^9$'a yakın olduğu için derste söylenen "saniyede yaklaşık bir milyar darbe" sonucu değişmez.
- FTP portu derste önce 23 olarak söylendi, bir öğrenci 21 olduğunu belirtti. Doğrusu 21'dir (veri için 20). SSH 22, Telnet 23'tür.
- Kaba kuvvet saldırısı (brute force attack), şifre gibi bir bilgiyi çok sayıda deneme yaparak bulmaya çalışmaktır. Derste bundan hemen sonra anlatılan "bir porta çok sayıda istek gönderip sistemi cevap veremez hâle getirmek" ise hizmet engelleme (Denial of Service, DoS) saldırısıdır.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
