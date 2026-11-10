# Ders 18 Genişletilmiş Notu: Ağ Cihazları, VLAN, TCP/IP, Alt Ağ Hesabı ve Ağ Güvenliği

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dersin Çerçevesi
- 2. OSI Katmanlarına Göre Ağ Cihazları
- 3. Sanal LAN (VLAN)
- 4. TCP/IP Modeli
- 5. IP Adresleri, Adres Sınıfları ve Port Numaraları
- 6. Alt Ağ (Subnet) Hesabı
- 7. NAT, DHCP, DNS, Statik ve Dinamik IP
- 8. Ağ Güvenliği
- Örnek Sorular
- Dersin Toparlaması

## 1. Dersin Çerçevesi

Hoca bu hafta için üç konu belirledi. Önce ağ içinde kullanılan elektronik donanımlar ve özellikleri anlatılacak. Ardından TCP/IP modeline çok kısa, OSI referans modeliyle karşılaştırma düzeyinde bir göz atılacak. Son olarak gönderilen verilerle ilgili güvenlik sorunlarına ve bunlara karşı kullanılan mekanizmalara değinilecek.

Hoca, TCP/IP'nin Ağ Teknolojileri dersinde, güvenlik konularının da Bilişim Sistemleri Güvenliği ve seçmeli Ağ Güvenliği derslerinde çok ayrıntılı işlendiğini söyledi. Bu yüzden bu derste TCP/IP ve güvenlik "genel kültür" seviyesinde anlatıldı. Ağ cihazları ise dersin ana konusunun devamı olarak daha ayrıntılı işlendi.

## 2. OSI Katmanlarına Göre Ağ Cihazları

OSI referans modeli 7 katmandan oluşur. Her katmanda farklı donanımlar çalışır. Hoca cihazları alttan yukarı doğru, fiziksel katmandan başlayarak anlattı. Yukarı katmanlara çıktıkça cihazın ihtiyaç duyduğu bellek ve işlem gücü de artar.

### 2.1 Repeater (Tekrarlayıcı)

Repeater fiziksel katmanda (physical layer) çalışır. Görevi, zayıflayan sinyali yeniden güçlendirerek daha uzak mesafeye ulaşmasını sağlamaktır. Sinyal kablolu da olabilir, kablosuz da.

Hoca burada daha önce görülen zayıflama (attenuation) kavramını hatırlattı. Sinyal, doğası gereği göndericiden uzaklaştıkça zayıflar. Bir noktadan sonra o kadar zayıflar ki hata oranı yükselir. Hatalı ulaşan her çerçeve (frame) için, ağ katmanında konuşursak her paket için, alıcıdan "hatalı geldi, tekrar gönder" yanıtı döner. Bu da arka planda ek iş ve kapasite kaybı demektir.

Wi-Fi ağı buna iyi bir örnektir. Sinyal gücünün birimi desibeldir (dB). Antenden uzaklaştıkça alınan sinyal azalır. Telefondaki çubuk göstergesi (örneğin 5 çubuk) antenin dibindeyken tam doluyken, uzaklaştıkça bazen tek çubuğa düşer. Böyle bir noktada veri iletişiminde kapasitenin düştüğünü hepimiz görürüz. Bunun sebeplerinden biri zayıflama ve onun sonucu olan yeniden gönderimlerdir.

Hocanın verdiği örnekte Wi-Fi'ın ulaşmadığı bir odaya hizmet vermek için, aşağı yukarı ortadaki bir noktaya kablosuz repeater konur. Repeater ağı aynı isimle ya da farklı bir isimle yeniden yayınlayabilir. Kablolu tarafta da benzer şekilde repeater'larla sinyal güçlendirilir.

Hoca önemli bir noktanın altını çizdi: Repeater pasif bir cihaz değildir, aktif bir cihazdır. Prize takılır, güç ister. Çünkü sinyali güçlendirip yeniden yollaması gerekir. Repeater'ı yalnızca bir konnektör gibi düşünmemek gerekir.

### 2.2 Hub

Repeater'lar artık çok kanallı çalışır. Kablolu bir hattı bir repeater'a bağlayıp repeater'ın uçlarından aynı sinyali dağıtan birden çok çıkış alınabilir. Bu yapıya hub denir. Hoca, repeater'ları "hub" adıyla da duymuş olabileceğimizi söyledi.

Hub'ın çalışma biçimi yayındır (broadcast). LAN'larda sinyal yayın olarak ilerler: Bir bus ya da ring topolojisinde gönderilen veri herkese teker teker ulaşır. Veri size geliyorsa alırsınız, gelmiyorsa umursamazsınız. Slayttaki örnekte hub'ın A portundan bir sinyal verilir. Asıl hedef C'dir, ama sinyal tüm portlara yayılır. Veri C'ye de ulaşır, fakat yol üzerindeki bütün portlarda gereksiz trafik oluşur.

### 2.3 Bridge (Köprü) ve Switch (Anahtar)

Bridge ve switch, repeater'a göre daha fazla hesaplama kapasitesine sahip donanımlardır. İçlerinde kendi bellekleri vardır. Veri bağı katmanında (data link layer) çalışırlar.

Veri bağı katmanı, mantıksal bağ denetimi (Logical Link Control, LLC) ve ortam erişim denetimi (Media Access Control, MAC) olarak ikiye ayrılıyordu. MAC alt katmanında her noktanın bir adresi vardır. Switch'in repeater'dan ayrıldığı nokta buradan doğar: Switch, MAC adreslerini bildiği makineleri birbirine eşleştirir (switch eder). Böylece hub'daki yoğun yayın akışının önüne geçilir.

Aynı örnekte A portundan C'ye bir sinyal yollandığında switch bu sinyali yalnızca C portuna iletir. Sinyal yalnızca C'den çıkar ve diğer portlarda trafiğe yol açmaz.

> **Ek bilgi (derste anlatılmadı):** Switch, hangi MAC adresinin hangi portun arkasında olduğunu, gelen çerçevelerin kaynak adreslerine bakarak öğrenir ve bunu bir MAC adres tablosunda tutar. Hedef adresi tabloda henüz bulunmayan bir çerçeveyi ise büyük olasılıkla tüm portlara gönderir (flooding). Switch'ler arasında döngü oluşursa çerçeveler sonsuza kadar dolaşabilir. Bu yüzden döngüleri engelleyen yayılan ağaç protokolü (Spanning Tree Protocol, STP) kullanılır.

**Fakülte örneği.** Hoca switch'lerin nerede kullanıldığını fakülte binası üzerinden anlattı. Binaya fiber kabloyla internet gelir. Sunucu odasında sunucular ve switch'ler vardır. Gelen hat bir switch'e bağlanır. Hocanın tahminine göre bu switch'lerde 48-50 civarında port vardır, yani kabloyla 48-50 cihaz bağlanabilir. Oysa yalnızca bir laboratuvarda 20-30 makine vardır. Daha fazla cihaz için switch'ler birbirine, döngü oluşturmayacak şekilde ağaç yapısında bağlanır. Böylece gelen hat daha yüksek kapasiteli bir yapıya bölünür.

### 2.4 Router (Yönlendirici)

Router ağ katmanında (network layer) çalışır ve bu katmana ve altındaki katmanlara hizmet verir. Hoca, switch'in de benzer biçimde veri bağı ve fiziksel katmana hizmet verdiğini, repeater'ın ise yalnızca fiziksel katmanda çalıştığını belirtti. Hoca ayrıca çeşitli ayarlarla switch'in router olarak da kullanılabileceğini söyledi.

> **Ders sonrası not:** Hoca "switch'i router olarak da kullanabilirsiniz" dedi. Bu yalnızca katman 3 (L3) switch'ler için geçerlidir. Sıradan, katman 2 (L2) bir switch IP yönlendirmesi yapmaz.

Geçen hafta bağlantısız (connectionless) ve bağlantı yönelimli (connection-oriented) yöntemler anlatılmıştı. İki yöntemde de yönlendirme algoritmaları vardı. A noktasından B noktasına veri gönderilirken aradaki birçok düğüme uğranıyordu. O düğümler router'lardır.

Hocanın örneği: İstanbul'dan Konya'ya bir paket gönderiliyor. Paket önce Gebze, sonra Bursa, Eskişehir ve Ankara gibi yerlere uğrayarak Konya'ya varıyor. Bu şehirlerin her biri rotayı belirleyen bir router gibi düşünülebilir.

Router'ların dinamik ve statik gibi farklı türleri vardır. Hoca şunu vurguladı: Ağdaki cihazlar birbirine hiç veri göndermese bile router'lar kendi aralarında küçük paketlerle hangi rotanın o an ne kadar iyi olduğunu konuşur. Örneğin Eskişehir'deki router, Ankara'daki router'a bağlıdır. Ankara'daki router, "Trabzon, Rize tarafına şu yoldan veri gönderdim, şu hızla gitti" diye haber verir. Router'lar bu bilgileri bir arama tablosunda (look-up table), yani yönlendirme tablosunda (routing table) tutar. Komşunun söylediği rota kendi bildiği rotadan daha iyi değilse tablo güncellenmez. Daha iyiyse router kendi rotasını günceller.

Bağlantısız yöntemde her paket her router'a geldiğinde nereye gideceğine o router karar veriyordu. Bağlantı yönelimli yöntemde ise rota önceden belirlenmiş olur ve paketler o rota üzerinden gider.

Router'lar tablolarını yalnızca bu "boş zamandaki" konuşmalarla güncellemez. Üzerlerinden geçen paketlerin başlıklarına (header) da bakarlar: Paket nereden gönderilmiş, hangi router'lardan geçmiş, ne kadar sürede ulaşmış. Hoca burada önemli bir ayrım yaptı: Router paketin içeriğini, yani mesajın kendisini okumaz; yalnızca başlıktaki iletim bilgilerini okur. Bu bilgilerden daha iyi bir rota keşfederse yönlendirme tablosunu günceller. Router'lar, üzerinde çok farklı yönlendirme algoritmaları çalışan aktif yapılardır. Bu algoritmaların ayrıntısı Ağ Teknolojileri dersinde görülecek.

### 2.5 Gateway (Ağ Geçidi)

Bir ağda, özellikle internette, çok farklı tiplerde cihaz vardır. Hocanın örneğine göre hâlâ internete bağlı 50 yıllık makineler vardır, örneğin bir CNC makinesinin elektronik kısmı. Öte yandan yeni çıkmış bir bilgisayar da gelişmiş ağ kartıyla internete bağlanır. Bu cihazların ağ arayüzleri ve konuşabildikleri protokoller birbirinden farklıdır.

Farklılıklar birkaç düzeyde ortaya çıkar:

- **Topoloji:** Bir LAN bus topolojisinde, bir başkası token ring ile ring topolojisinde haberleşir.
- **Alt katman protokolü:** Biri Ethernet, biri 802.11 (Wi-Fi), biri Bluetooth üzerinden ağa bağlanır.
- **Çerçeve boyutu:** 802.3, 802.4 ve 802.5 gibi standartlarda çerçeve boyutları farklıdır. Hocanın örneğinde biri 4000 baytlık veri gönderirken diğeri 1000 baytlık veri almayı bekler.

Gateway, bütün bu farklı yapılar arasında iletişimi sağlayan, birini diğerine çeviren (translate eden) donanım birimidir. Repeater'da çok az işlem gücü gerekir. Router'da yönlendirme algoritmalarının çalışacağı işlem gücü ve tabloların tutulacağı bellek gerekir. Gateway ise örneğin bir protokolde gelen 4000 baytlık veriyi başka bir protokolde nasıl teslim edeceği gibi sorunları çözmek zorundadır. Bu yüzden işlem gücü en yüksek olan cihazdır.

| Cihaz | Katman | Temel iş |
| --- | --- | --- |
| Repeater / hub | Fiziksel | Sinyali güçlendirir; hub tüm portlara yayar |
| Bridge / switch | Veri bağı (MAC) | MAC adresine göre yalnızca hedef porta iletir |
| Router | Ağ | Yönlendirme tablosuyla rota belirler |
| Gateway | Üst katmanlar | Farklı protokol ve ağlar arasında çeviri yapar |

## 3. Sanal LAN (VLAN)

Hepimiz bir LAN'a bağlıyız ve o LAN üzerinden veri iletişimi kuruyoruz. Fiziksel bir LAN içinde veri göndermeye başladığımız anda yayın yaparız. Veri ilgili ilgisiz tüm cihazlara gider. İlgili cihaz veriyi aldıktan sonra o veri trafiği durur.

**Çok oyunculu oyun örneği.** Hoca bunu canlandırmak için çevrim içi, çok oyunculu bir oyun örneği verdi. 10 oyuncu var ve her biri farklı bir fiziksel LAN'da: biri İstanbul'da, biri Ankara'da, biri yurt dışında. Bir oyuncu arabasını bir yerden bir yere hareket ettirdiğinde bu hareketin diğer tüm oyunculara gönderilmesi gerekir. Bu da hareketin tüm oyuncuların LAN'larında yayınlanması demektir. Her LAN'da 100 cihaz varsa:

$$100 \times 10 = 1000$$

makineye bu verinin gitmesi gerekir.

Sanal LAN (Virtual LAN, VLAN) kurulduğunda bu 10 makine sanki yalnız kendilerinin bağlı olduğu fiziksel bir LAN'daymış gibi davranır. Paket gönderildiğinde yayın yalnızca VLAN içindeki bu 10 makineye yapılır. Hoca dikkat çekti: Gönderenin kendi fiziksel LAN'ına bile yayın yapılmaz. Oyun oynayan bazı öğrencilerin, böyle VLAN'lar kurmayı sağlayan programları kullanıyor olabileceğini de ekledi. VLAN'ın farklı sürümleri vardır, ama ayrıntılarına girilmedi.

VLAN'lar arasında da iletişim kurmak gerekecektir. Bunun için trunk'lar kullanılır. VLAN'ın bazı birimleri trunking yapar. VLAN'lar arasında iletişim kurmayı sağlayan bu yapıya trunking denir.

> **Ek bilgi (derste anlatılmadı):** Gerçek kurumsal ağlarda VLAN'lar genellikle switch'ler üzerinde tanımlanır. Trunk bağlantısı, birden çok VLAN'ın trafiğini tek bir hat üzerinden taşıyan switch portudur. Çerçeveler bu hatta IEEE 802.1Q etiketiyle hangi VLAN'a ait olduklarını belirterek taşınır. Farklı VLAN'lardaki cihazların birbirine ulaşması için ise büyük olasılıkla bir router ya da L3 switch gerekir.

### 3.1 VLAN'ın Avantajları

Hoca VLAN'ı neden tercih edeceğimizi şöyle sıraladı:

- **Daha yüksek başarım:** 1000 makineye yayın yapıp yalnız 10'unun veriyi almasını beklemek yerine yalnız 10 makineye yayın yapmak gecikmeleri azaltır.
- **Sanal çalışma grubu:** Birbirine sürekli veri gönderen bir grup oluşturulur. Oyun en basit örnektir. Daha karmaşık bir örnek görüntülü görüşmedir: Karşı tarafın görüntüsü gelip gider ve bu verilerin başka tarafa aktarılmaması gerekir. Veri şifreli bile olsa VLAN kullanılmazsa hem kendi fiziksel LAN'ınızda hem karşı tarafın fiziksel LAN'ında yayın yapmak zorunda kalırsınız.
- **Kolay yönetim:** Veriyi 1000 cihaz yerine 10 cihaza dağıtmak yönetimi kolaylaştırır.
- **Düşük maliyet:** Aynı işi yapan 10 bilgisayarı fiziksel olarak birbirine bağlamak yerine bunu sanal olarak yapmak maliyet avantajı sağlar.
- **Güvenlik:** VLAN üyeleri bellidir. Başka hiç kimseye yayın yapılmaz, yalnızca VLAN içinde yayın yapılır.

## 4. TCP/IP Modeli

TCP/IP modeli de OSI referans modeli gibi ağ katmanlarını içinde barındıran bir modeldir. OSI'de toplam 7 katman vardı. Teorik olarak TCP/IP'nin 3 ile 5 arasında katmandan oluştuğu söylenir. Pratikte bazı uygulamalar TCP/IP'yi 4 katman, bazıları 5 katman üzerinden gerçekleştirmiştir.

Slaytta OSI katmanlarına karşılık gelen TCP/IP katmanları gösterildi:

- **4 katmanlı modelde** en alttaki ağ (erişim) katmanı, OSI'deki fiziksel ve veri bağı katmanlarına birlikte karşılık gelir.
- **5 katmanlı modelde** ise veri bağı ve fiziksel katmanlara doğrudan karşılık gelen ayrı katmanlar vardır.
- OSI'deki ağ katmanının TCP/IP'deki karşılığına **internet katmanı** denir. Hocaya göre iki modelde de bu katman için ortak olarak "internet katmanı" ifadesi kullanılır.

<!-- BELİRSİZ: Slayttaki 4 ve 5 katmanlı model tablosunun katman adları altyazıda tam okunmuyor; yalnızca yukarıdaki eşleşmeler sözlü olarak anlatıldı. -->

İnternet katmanında bağlantısız bir iletişim vardır. Hoca burada datagram yöntemini hatırlattı: Veri gönderilir, ama gönderen verinin ulaşıp ulaşmamasından kendini sorumlu tutmaz. Bu yüzden TCP/IP'nin internet katmanı zaman zaman güvensiz ve performanssız olarak değerlendirilir. Ancak bunun üzerindeki taşıma ve uygulama katmanlarının sağladığı avantajlarla bu güvensizlik ortadan kalkar. TCP/IP'yi bütün olarak düşündüğümüzde hepimiz gündelik hayatta kullanıyoruz ve performansından oldukça memnunuz.

Taşıma katmanında iki temel protokol anlatıldı:

- **TCP (Transmission Control Protocol):** Bağlantı yönelimli çalışır. Hoca bağlantı yönelimli yöntemi şöyle hatırlattı: A noktasından B noktasına, arada 30 düğüm olsa bile bir rota çizilir. Buna bağlantı denir. Her paket bu bağlantı üzerinden karşıya ulaştırılır.
- **UDP (User Datagram Protocol):** Bağlantısız bir protokoldür. Paket ağa gönderilir, kendi yolunu bulup karşı tarafa ulaşmaya çalışır. Ulaşıp ulaşmayacağı, ne zaman ve hangi sırada ulaşacağı ile doğrudan ilgilenilmez.

> **Ders sonrası not:** Hoca TCP'nin bağlantı yönelimli yapısını "arada 30 düğüm olsa bile bir rota çiziliyor" diye, sanal devre (virtual circuit) mantığıyla anlattı. TCP bağlantısı yalnızca iki uç arasında kurulan mantıksal bir bağlantıdır. Altındaki IP katmanı datagram olarak çalışmaya devam eder; TCP paketleri farklı rotalardan gidebilir. TCP güvenilirliği rotayı sabitleyerek değil, sıra numaraları, onaylar ve yeniden gönderimle sağlar.

## 5. IP Adresleri, Adres Sınıfları ve Port Numaraları

### 5.1 IP Adresi ve Adres Sınıfları

TCP/IP denince akla ilk gelen şeylerden biri IP adresleridir. Bir IP adresi 4 bayttan oluşur. Her bayt 8 bittir ve $2^8 = 256$ farklı değer alabilir. Bu yüzden teorik olarak

$$256^4 = 2^{32} = 4\,294\,967\,296$$

makineye IP adresi verilebilir (sayısal değer ara adım olarak eklendi). Ancak bazı IP adresleri ayrılmıştır (reserved). Veri iletişimi yapılırken uç birimlere, makinelere bu adresler verilemez.

IP adreslerinin toplam 5 sınıfı vardır. A sınıfı adreslerin hepsi 0 biti ile başlar. Bu yüzden IP adreslerinin yarısı A sınıfıdır. B, C, D ve E sınıflarında ilk bit 1'dir. Sınıf, sonraki bitlerin 0 ya da 1 olmasına göre belirlenir.

| Sınıf | İlk bitler | Varsayılan maske | Ağ başına kullanılabilir konak |
| --- | --- | --- | --- |
| A | 0 | 255.0.0.0 | $2^{24} - 2 = 16\,777\,214$ (yaklaşık 17 milyon) |
| B | 10 | 255.255.0.0 | $2^{16} - 2 = 65\,534$ (yaklaşık 65 bin) |
| C | 110 | 255.255.255.0 | $2^{8} - 2 = 254$ |
| D | 1110 | – | Çok noktaya yayın (multicast) |
| E | 1111 | – | Ayrılmış |

<!-- BELİRSİZ: D ve E sınıflarının ilk bitleri ve kullanım amacı altyazıda söylenmedi; slayttan aktarıldığı varsayılan standart değerler yazıldı. -->

Hoca C sınıfını örnek verdi: C sınıfı bir adres belli değerlerle başlar, geri kalan kısım istenildiği gibi ayarlanır ve 254 konak elde edilir. Aynı şekilde B sınıfında yaklaşık 65 bin, A sınıfında yaklaşık 17 milyon konak vardır.

**Maske neden 255?** C sınıfının maskesi 255.255.255.0'dır. Bir baytın tüm bitleri 1 olduğunda değeri 255'tir. Son bayt 0'dır; yani bu bayt konaklara ayrılmıştır. Son bayt 0'dan 255'e kadar 256 değer alabilir. Ancak tüm bitlerin 0 olduğu ve tüm bitlerin 1 olduğu iki durum ayrılmıştır. Böylece

$$2^8 - 2 = 256 - 2 = 254$$

konak, yani makine bağlanabilir.

> **Ek bilgi (derste anlatılmadı):** Tüm konak bitleri 0 olan adres ağın kendisini (ağ adresi), tüm konak bitleri 1 olan adres o ağdaki herkesi (yayın adresi, broadcast address) gösterir. Örneğin 192.168.1.0/24 ağında ağ adresi 192.168.1.0, yayın adresi 192.168.1.255'tir. Maskeler kısaca 1 olan bit sayısıyla da yazılır: 255.255.255.0 için /24, 255.255.255.192 için /26 (CIDR gösterimi). 10.x.x.x, 172.16-31.x.x ve 192.168.x.x blokları büyük olasılıkla internete doğrudan çıkmayan özel (private) adreslerdir.

### 5.2 Port Numaraları

Makinenin bir IP adresi vardır. Bu IP adresinde de birçok farklı haberleşme portu bulunur. Hoca yaygın portları şöyle sıraladı:

| Port | Protokol | Açıklama |
| --- | --- | --- |
| 20, 21 | FTP (File Transfer Protocol) | Dosya aktarımı |
| 23 | Telnet | Uzak terminal |
| 25 | SMTP | E-posta (mail) sunucusu |
| 80 | HTTP | Web |
| 110 (995) | POP | Posta geldi mi diye kontrol eden servis |

Port alanı 16 bit olduğunda $2^{16} = 65\,536$ farklı port olur. Hoca 8080 portunu, yerel makine (localhost) üzerinden veri haberleşmesi için kullanılabilecek ve başka derslerde fark edilmiş olabilecek portlardan biri olarak andı. Bir Exchange Server üzerinde SMTP ve POP sunucuları kurulacaksa bu port numaraları kullanılmalıdır. Bu listedekilerden çok daha fazla port vardır. Hoca POP için 995 numaralı portun da kullanıldığını hatırladığını, ama yanılıyor olabileceğini söyledi. Kurulum sırasında doğru portlara bakmak gerekir.

> **Ders sonrası not:** Hoca "8 bitlik port adresleme" ifadesini de kullandı. TCP ve UDP port alanı her zaman 16 bittir ve $2^{16} = 65\,536$ değer alır (0-65535). Altyazıda "80.80" diye geçen port 8080'dir. Standart POP3 portu 110'dur; 995, TLS ile şifrelenmiş POP3 (POP3S) portudur.

## 6. Alt Ağ (Subnet) Hesabı

### 6.1 Maskenin Anlamı

Maske 32 bitlik bir veridir. C sınıfının maskesi 255.255.255.0 ise bu, art arda $8 + 8 + 8 = 24$ tane 1 ve ardından 8 tane 0 demektir:

$$\underbrace{11111111.11111111.11111111}_{24 \text{ bit } 1}.\underbrace{00000000}_{8 \text{ bit } 0}$$

C sınıfı bir IP ve 255.255.255.0 maskesiyle toplam 254 makine barındırılır.

### 6.2 35 Bilgisayarlı Şirket Örneği

Bir şirketin 35 bilgisayarı var, yani 35 IP adresine ihtiyacı var. Maske 255.255.255.0 olursa 254 IP kullanma hakkı doğar, ama yalnızca 35'i kullanılır. Hocaya göre bu bir israftır. Dünyada IP ihtiyacı olan çok sayıda cihaz vardır; bu yüzden şirketlere ve kurumlara ayrılan IP adreslerini mümkün olduğunca az kullanmak, yani alt ağı iyi ayarlamak gerekir.

> **Ders sonrası not:** Hoca IPv4 adres sayısı için "32-34 milyon" dedi ve "sadece Türkiye'de 34 milyon cihaz vardır" diye ekledi. Doğrusu $2^{32} \approx 4{,}29$ milyar adrestir. Adres yetersizliği bu kadar adresle bile ortaya çıktığı için NAT, alt ağlama ve büyük olasılıkla 128 bitlik IPv6 ile çözülmeye çalışılır.

Çözüm adım adım şöyledir:

- **Verilen:** 35 konak, C sınıfı adres, son bayt konaklara ayrılmış.
- **İşlem:** Son baytın ilk iki biti de 1 yapılır. Son bayt $11000000_2 = 128 + 64 = 192$ olur (ara adım eklendi). Maske 255.255.255.192'dir.
- **Ara sonuç:** Konaklar için 6 bit kalır. $2^6 = 64$ farklı değer vardır.
- **Ayrılmış adresler:** Tüm bitlerin 0 ve tüm bitlerin 1 olduğu iki durum çıkarılır: $64 - 2 = 62$.
- **Sonuç:** 62 konak, 35 cihaz için yeterlidir. Maskenin son baytı 192 olmalıdır.

> **Ders sonrası not:** Hoca tüm-0 durumunu çıkardıktan sonra tüm-1 durumunu da çıkarınca "63 makine" dedi. İki ayrılmış durum da çıkarılınca doğrusu $2^6 - 2 = 62$ konaktır. Sonuç değişmez: 62 konak 35 cihaza yeter.

> **Hocanın vurgusu:** Bu tarz sorular zaman zaman sorulur; "biz de sorabiliriz" dedi. Örnek olarak "130 makine için alt ağ maskesi ne olmalı?" ve "5 makine için en küçük maske ne olmalı?" sorularını verdi (çözümleri Örnek Sorular bölümünde).

### 6.3 255.255.255.128 ve Genel Kural (Öğrenci Sorusu)

**Soru:** Alt ağ (subnet) tam olarak ne sağlıyordu? Bir daha söyler misiniz?

**Cevap:** Hoca alt ağın, IP adres sınıfına göre kaç makineye IP adresi verilebileceğini belirlediğini söyledi. Örnek olarak maske 255.255.255.128 alındı. Bu durumda son baytın yalnızca ilk biti 1, geri kalan 7 biti 0'dır. Hoca $2^7 = 128$ değerden 1 çıkararak 127 makineye IP verilebileceğini söyledi. Bir şirket ya da üniversite ağının 127'den fazla IP'ye ihtiyacı yoksa maske 255.255.255.128 olabilir. Bir bit daha 1 yapılırsa son bayt 192 olur ve 6 tane 0 boşta kalır.

> **Ders sonrası not:** 255.255.255.128 için hoca "127 makine" dedi. Tüm-0 ve tüm-1 adresleri çıkarılınca doğrusu $2^7 - 2 = 126$ konaktır. Ayrıca hoca bu maskeyle "128'den sonra 129, 130, 131 diye giden adreslerin" verilebileceğini söyledi. Maskenin son baytındaki 128, adres aralığının başlangıcı değildir; yalnızca kaç bitin konaklara kaldığını gösterir. Örneğin 192.168.1.0/25 ağı 192.168.1.1-126 konaklarını, 192.168.1.128/25 ağı ise 192.168.1.129-254 konaklarını içerir (python `ipaddress` ile doğrulandı).

Hoca genel kuralı şöyle kurdu: Makine sayısı $2^6$ ile $2^7$ arasındaysa son bayt 128, $2^6$'dan azsa 192 olur. 10 makine varsa: $2^4 = 16$ bunu sağlar, $2^3 = 8$ sağlamaz. Bu yüzden yalnızca son 4 biti 0, ilk 4 biti 1 olan bayt seçilir. Bu baytın onluk karşılığı alt ağ maskesinin son baytı olarak kullanılır:

$$11110000_2 = 128 + 64 + 32 + 16 = 240 \quad \text{(ara adım eklendi)}$$

10 makine için maske 255.255.255.240'tır ve $2^4 - 2 = 14$ konak verir.

Ayrılmış iki adres hesaba katılınca genel kural şudur: $N$ konak için $2^h - 2 \ge N$ koşulunu sağlayan en küçük $h$ seçilir. Maske, kalan $32 - h$ bitin 1 yapılmasıyla bulunur.

> **Ders sonrası not:** Hocanın "$2^6$ ile $2^7$ arası" sınırı yaklaşık bir kuraldır. Ayrılmış adresler hesaba katılınca 255.255.255.192 en çok 62, 255.255.255.128 en çok 126 konak taşır. Yani 63-126 konak için 128, 62 ve altı için 192 seçilir.

Son baytta maske ve konak sayıları (python `ipaddress` ile doğrulandı):

| Maske | CIDR | Konak bitleri $h$ | Kullanılabilir konak $2^h - 2$ |
| --- | --- | --- | --- |
| 255.255.255.0 | /24 | 8 | 254 |
| 255.255.255.128 | /25 | 7 | 126 |
| 255.255.255.192 | /26 | 6 | 62 |
| 255.255.255.224 | /27 | 5 | 30 |
| 255.255.255.240 | /28 | 4 | 14 |
| 255.255.255.248 | /29 | 3 | 6 |

Hoca, bu ayrıntıların, sınıfların farklı özelliklerinin ve portların Ağ Teknolojileri dersinde çok ayrıntılı görüleceğini, burada yalnızca kabaca, genel kültür seviyesinde anlatıldığını söyledi.

## 7. NAT, DHCP, DNS, Statik ve Dinamik IP

### 7.1 NAT ve DHCP

IPv4 adres sayısı sınırlıdır, oysa dünyada IP'ye ihtiyacı olan milyarlarca cihaz vardır. Bunların birlikte nasıl çalıştığını Ağ Adresi Çevirisi (Network Address Translation, NAT) açıklar. Hoca, modemlerde NAT ayarlarının yapıldığını hatırlattı.

Hocanın ev örneğinde televizyon, telefonlar, bilgisayar ve saat gibi cihazların hepsi modeme bağlıdır. Modem her cihaza yerel (lokal) bir IP verir. Ayar değiştirilmediyse bu adres varsayılan olarak 192.168 ile başlar. Yerel IP'yi dağıtan, modemdeki DHCP sunucusudur.

Ancak modeme bağlı tüm cihazlar ağa çıkarken tek bir IP kullanır: servis sağlayıcının modeme verdiği IP. Yani yerelde her cihazın kendi yerel IP'si, dışarıda ise hepsinin ortak tek bir IP'si vardır. Dışarıdan gelen bir yanıtın modeme bağlı cihazlardan hangisine ait olduğunu ayırt eden yapı NAT'tır.

> **Ek bilgi (derste anlatılmadı):** Ev modemlerindeki NAT büyük olasılıkla port tabanlı çalışır (NAPT ya da PAT). Modem, dışarı çıkan her bağlantı için yerel IP ve port ikilisini dış IP üzerindeki farklı bir port numarasıyla eşleştirip bir tabloda tutar. Yanıt geldiğinde bu tabloya bakarak paketi doğru yerel cihaza iletir.

### 7.2 DNS (Domain Name System)

Makinelerin olduğu gibi hizmet alınan internet sitelerinin de birer IP adresi vardır. Arama motorlarının, video sitelerinin ve sosyal ağların her birinin bir IP'si vardır. Hoca, DNS sunucusunu elle ayarlamak isteyenlerin, büyük bir arama motoru şirketinin DNS sunucusunun 8 rakamlarıyla başlayan akılda kalıcı bir adres olduğunu bilebileceğini söyledi.

Hoca DNS'in amacını uydurma bir örnekle anlattı: Bir video platformundan bir şey izlemek istiyoruz ve platformun IP'si dört sayıdan oluşan rastgele bir adres olsun. Bir insanın bunu aklında tutması çok mümkün değildir. Alışveriş yapılacak sitenin başka, gazete okunacak sitenin başka, üniversite sitesinin başka bir IP'si vardır. Hepsini akılda tutmak imkânsızdır. Bu yüzden alan adı sistemi (Domain Name System, DNS) oluşturulmuştur. IP'lere insanların daha kolay anlayıp hatırlayabileceği isimler verilir. Bu isim kullanılarak ilgili IP'de barındırılan (host edilen) hizmete ulaşılır.

Alan adları, belli IP'lerle eşleştirilmiş isimler olarak alan adı kayıt kuruluşlarından ücret karşılığında alınır. Bunu sıradan kullanıcı değil, hizmet sunacak olan taraf yapar. Böylece insanlar bu ismi girerek barındırılan sisteme ulaşabilir.

### 7.3 Statik ve Dinamik IP

Modemlerde statik ve dinamik IP olmak üzere iki durum vardır.

- **Statik IP:** Servis sağlayıcı modeme sabit bir IP verir. Modem kapatılıp açılsa, bir yıl geçse bile IP aynı kalır. Avantajı, IP numarası bilindiği için bu IP üzerinden hızlıca bağlantı kurulabilmesidir. Hoca, bazı öğrencilerin bazı servis sağlayıcıların statik IP'yi ücretsiz de verdiğini söylediğini aktardı.
- **Dinamik IP:** Ek ücret ödenmeyen standart durumlarda verilir. Modem her başlatıldığında, sıfırlandığında, elektrik gidip geldiğinde ya da başka durumlarda servis sağlayıcı yeni bir IP adresi verir.

Servis sağlayıcıların elindeki IP adresleri sınırlıdır. Hocanın örneği: Cep telefonu eve gelince mobil veriden çıkıp Wi-Fi'a bağlanır. Mobil ağda baz istasyonu aracılığıyla atanmış bir IP vardı. Telefon artık onu kullanmadığı için bu IP serbest kalır ve hemen başka bir cihaza atanır. Telefon Wi-Fi'ın kapsama alanından çıkıp ya da Wi-Fi'ı kapatıp yeniden mobil şebekeye bağlandığında ona yeniden bir IP verilir. Statik değilse bu farklı bir IP'dir. Buna dinamik IP denir.

Statik IP'nin avantajı kullanıcı içindir. Dinamik IP'nin avantajı ise servis sağlayıcı içindir: Elindeki sınırlı sayıdaki IP adresini, adres sayısından daha fazla kullanıcıya bu şekilde paylaştırır.

## 8. Ağ Güvenliği

### 8.1 Güvenlik Yalnızca Gizlilik Değildir

Ağ güvenliği denince akla ilk gelen şey, gönderilen verinin başkası tarafından dinlenmesi ya da okunmasıdır. Örneğin bir görüntülü görüşme ya da mesajlaşma uygulamasında yapılan konuşmanın başkası tarafından okunması. Hoca, veri güvenliğinin yalnızca bu olmadığını vurguladı ve üç ölçüt anlattı.

**Bütünlük.** Veri bir bütün olarak, başı sonu belli şekilde karşı tarafa ulaşmalıdır. Örneğin bir paket 30 bayttır ve bu 30 baytın başarıyla karşıya ulaşması gerekir. Saldırgan veriyi okuyamıyor ya da anlayamıyor olabilir, ama verinin ulaşmasını engellemeye çalışabilir. Bir bayt, hatta bir bit bile eksik giderse karşı tarafta veri anlaşılamaz hale gelebilir. Hocanın örneğinde bir müdahale sonucu ortadaki baytlardan biri yok olur ve paket 28 bayt olarak gider.

<!-- BELİRSİZ: Hoca "30 bayttan biri yok olunca 28 bayt" dedi; tek bayt eksilirse 29 bayt olması beklenir. Hoca iki baytın kaybını mı kastetti, altyazıdan anlaşılmıyor. -->

**Kullanılabilirlik.** Hocanın örneğinde paket yine 30 bayt olarak gider, ama biri bir baytı bozup yerine başka bir bayt eklemiştir. Boyut değişmez, fakat alıcı sağlama toplamıyla (checksum) kontrol ettiğinde her seferinde hata çıkar ve veri kullanılamaz. Bu da bir veri güvenliği sorunudur.

**Gizlilik ve mahremiyet.** Verinin mahremiyetinin (privacy) ve gizliliğinin bozulması en ciddi sorunlardan biridir. Bu durumda yalnızca iletişimin engellenmesi değil, kurulan iletişimin dinlenmesi de söz konusudur.

### 8.2 Güvenlik Mekanizmaları

Hoca bu sorunlardan kurtulmak için kullanılan mekanizmaları sıraladı.

**Şifreleme.** Mesajlar DES (Data Encryption Standard) ya da AES (Advanced Encryption Standard) ile şifrelenebilir. Hoca, böyle şifrelenmiş mesajları günümüzdeki süper bilgisayarların bile kaba kuvvetle (brute force) makul bir sürede çözmesinin pek imkânı olmadığını söyledi.

> **Ders sonrası not:** Bu ifade AES için geçerlidir, DES için geçerli değildir. DES'in anahtarı 56 bittir. 1998'de EFF'nin "Deep Crack" makinesi bir DES anahtarını büyük olasılıkla 56 saat civarında kaba kuvvetle buldu. DES bugün güvensiz kabul edilir.

**Sayısal imza.** Gönderilen veri başkaları tarafından dinleniyor olabilir. Karşı taraftan veri geliyor ya da biz veri gönderiyor olabiliriz. Verinin gerçekten bizden geldiğini kanıtlayan imzaların bulunması güvenlik açısından bir avantajdır.

**Erişim denetimi (access control).** Erişim izni olan ve olmayan çeşitli noktalar vardır. Erişim denetimi genellikle kimlik doğrulamayla birlikte kullanılır. Hocanın örneği: Bir ağın içindeyiz ve trunk ile başka bir ağdan hizmet alıyoruz. O ağda birincil (primary) ve ikincil (secondary) cihazlar vardır, bazı cihazlar da hibrittir ve bunlar birbiriyle farklı biçimlerde iletişim kurar. İkincil bir cihazın çıkıp birincil gibi davranarak iş yapması ağ güvenliğini tehlikeye atar. Bu bir erişim denetimi sorunudur.

**Kimlik doğrulama (authentication).** En sık kullandığımız mekanizmalardan biridir. Ağa bağlanırken bir kullanıcı adı ve şifreyle bağlanarak güvenlik sağlanmaya çalışılır.

**Trafik dolgusu (traffic padding).** Hoca bunu şöyle anlattı: Boş bir ağa trafik basılır ve bu trafiğin ne tarafa aktığı analiz edilir. Kendi bilgisayarımızda da olabilir: Ağı hiç kullanmıyoruz, ama ağı gözlemlediğimizde yüksek oranda bir yere veri gittiğini ya da geldiğini görüyoruz. Örneğin bir Truva atı (Trojan) bilgisayardan veri alıp götürüyor olabilir. Ya da bilgisayara bir iş göndermiştir, örneğin kripto para madenciliği hesabı, ve bilgisayar sonucu geri gönderiyordur. Trafiğin nasıl yönlendirildiğini ve kimin aktif olarak veri aldığını kontrol etmek için çeşitli trafik dolgusu teknikleri vardır. Hoca bu tekniklerin ayrıntısını kendisinin de kabaca bildiğini söyledi.

> **Ders sonrası not:** Trafik dolgusunun ITU-T X.800'deki tanımı hocanın anlattığından farklıdır. Hatta sahte, anlamsız veri gönderilerek gerçek trafiğin miktarı ve zamanlaması gizlenir; amaç trafik analizini (traffic analysis) zorlaştırmaktır. Hocanın anlattığı izleme işi trafik analizi ya da saldırı tespiti (intrusion detection) kapsamındadır.

**Yönlendirme denetimi (routing control).** Router'lar üzerlerinden geçen paketlerin başlıklarına bakıp daha performanslı bir rota görürse sonraki paketleri oradan gönderir. Saldırganlar bunu kötüye kullanabilir. Sahte başlıklı paketler hazırlanır ve bu paketler belli bir router'ın üzerinden çok performanslı geçmiş gibi gösterilir. Diğer router'lar o router'ın daha iyi olduğuna inandırılır ve bütün trafik onun üzerinden akmaya başlar. O router güvensizdir ve veriler oradan dışarı sızdırılabilir. Bu tür durumları engellemeye çalışan yönlendirme denetimi yöntemleri vardır.

**Noterlik (notarization).** Bir yetkili tarafından yalnızca izin verilenlerin bir router'a ya da ağa girişine izin verilmesidir. Bir ağdaki bir makineye veri göndermek için o ağa girme yetkisine (clearance) sahip olmak gerekir. Hoca bunu şirketlerdeki kartlı geçiş sistemine benzetti: Bazı odaları kartla açarsınız, ama daha üst rütbeli kişilerin odalarına kart okuttuğunuzda kapı açılmaz, çünkü güvenlik seviyeniz yetmez.

## Örnek Sorular

**Soru 1** (derste sözlü, 00:39:51). 35 bilgisayarı olan bir şirket için C sınıfı bir adreste alt ağ maskesi ne olmalıdır?

**Çözüm (derste verildi):** $2^h - 2 \ge 35$ koşulunu sağlayan en küçük $h$ değeri 6'dır, çünkü $2^5 - 2 = 30 < 35$ ve $2^6 - 2 = 62 \ge 35$. Son baytın ilk 2 biti 1 olur: $11000000_2 = 192$. Maske 255.255.255.192'dir, 62 konak taşır.

**Soru 2** (derste sözlü, 00:41:34). 130 makineye ihtiyaç olan bir durumda alt ağ maskesi ne olmalıdır?

> **Çözüm (derste verilmedi):** $2^7 - 2 = 126 < 130$ olduğu için 7 konak biti yetmez. $2^8 - 2 = 254 \ge 130$ olduğundan $h = 8$ seçilir. Maske 255.255.255.0'dır (/24), 254 konak taşır (python `ipaddress` ile doğrulandı).

**Soru 3** (derste sözlü, 00:41:34). 5 makineye ihtiyaç olduğunda, en küçük alt ağ düşünülürse maske ne olmalıdır?

> **Çözüm (derste verilmedi):** $2^2 - 2 = 2 < 5$, $2^3 - 2 = 6 \ge 5$ olduğu için $h = 3$ seçilir. Son baytın ilk 5 biti 1 olur: $11111000_2 = 248$. Maske 255.255.255.248'dir (/29), 6 konak taşır (python `ipaddress` ile doğrulandı).

**Soru 4** (derste sözlü, 00:49:04). 10 makine için alt ağ maskesinin son baytı ne olmalıdır?

**Çözüm (derste verildi):** Hoca $2^4 = 16$ değerinin yettiğini, $2^3 = 8$ değerinin yetmediğini söyledi. Son 4 bit 0, ilk 4 bit 1 olur: $11110000_2 = 240$. Maske 255.255.255.240'tır. Ayrılmış iki adres çıkarılınca $2^4 - 2 = 14 \ge 10$ konak kalır; $2^3 - 2 = 6$ ise yetmez.

## Dersin Toparlaması

Bu derste önce OSI katmanlarına göre ağ cihazları görüldü. Repeater ve hub fiziksel katmanda sinyali güçlendirip tüm portlara yayar. Bridge ve switch veri bağı katmanında MAC adreslerine göre yalnızca hedef porta iletir. Router ağ katmanında yönlendirme tablolarıyla rota belirler. Gateway ise farklı protokol ve ağlar arasında çeviri yapar. Katman yükseldikçe cihazın bellek ve işlem gücü ihtiyacı artar. Ardından VLAN'ın yayını yalnızca ilgili makinelere sınırlayarak başarım, yönetim, maliyet ve güvenlik avantajı sağladığı anlatıldı.

TCP/IP kısmında modelin OSI ile ilişkisi, bağlantısız internet katmanı, TCP ve UDP farkı, IP adres sınıfları, yaygın portlar ve alt ağ hesabı genel kültür düzeyinde işlendi. Alt ağ hesabında $N$ konak için $2^h - 2 \ge N$ koşulunu sağlayan en küçük $h$ seçilir. NAT, DHCP, DNS ve statik/dinamik IP kavramları ev ağı örnekleriyle açıklandı. Son olarak ağ güvenliğinin bütünlük, kullanılabilirlik ve gizlilik boyutları ile şifreleme, sayısal imza, erişim denetimi, kimlik doğrulama, trafik dolgusu, yönlendirme denetimi ve noterlik mekanizmaları kısaca anlatıldı. Hoca bu konuların ayrıntısının Ağ Teknolojileri ve güvenlik derslerinde görüleceğini söyledi. Bir sonraki hafta öğrenci grupları X.25, ATM ve ISDN gibi konuları sunacak.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
