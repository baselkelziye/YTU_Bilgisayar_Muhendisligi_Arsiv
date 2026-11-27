# Ders 12 Genişletilmiş Notu: IPv4 Başlığı, IP Adresleme, NAT ve IPv6

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. İnternette Ağ Katmanı
- 2. IPv4'ün Kökeni ve Version Alanı
- 3. IPv4 Başlığının Alanları
- 4. Bayt Sırası: Big Endian ve Little Endian
- 5. Parçalama Alanları: Identification, DF, MF, Fragment Offset
- 6. TTL, Protocol, Header Checksum ve Adresler
- 7. IPv4 Seçenekleri
- 8. Sınıflı Adresleme
- 9. Önekler ve Alt Ağ Maskesi
- 10. Alt Ağlara Bölme
- 11. Birleştirme ve En Uzun Önek Eşleşmesi
- 12. NAT ve PAT
- 13. IPv6
- Örnek Sorular
- Dersin Toparlaması

## 1. İnternette Ağ Katmanı

Bu derste iki şubenin öğretim üyeleri birlikte ders anlattı; ağ katmanı konusunun devamı olarak İnternetin ağ katmanına ve IP protokolüne geçildi. İlk slayt İnternetin genel yapısını gösteriyordu (ekrandan, 00:05:00). Slayttaki tanım şudur: İnternet, IP protokolüyle bir arada tutulan, birbirine bağlı çok sayıda ağın topluluğudur ("an interconnected collection of many networks that is held together by the IP protocol").

Şekildeki bileşenler şöyledir:

- Bir ABD omurgası (A U.S. backbone) ve bir Avrupa omurgası (A European backbone).
- Asya'ya giden kiralık hatlar (leased lines to Asia) ve Atlantik ötesi kiralık hatlar (leased transatlantic lines).
- ABD omurgasına bağlı bir bölgesel ağ (regional network) ve ona kabloyla (cable) bağlanan bir ev ağı (home network).
- Bir mobil ağ (mobile network) ve ona WiMAX ile bağlanan bir dizüstü bilgisayar.
- Avrupa omurgasına bağlı bir ulusal ağ (national network), ona bir IP yönlendiricisi üzerinden bağlanan şirket ağı (company network) ve şirket ağının içinde Ethernet.

Omurga içindeki bağlantılar daha kalın çizilmiştir. Bunun anlamı, trafiğin uç noktalardan toplanarak yukarıya, omurgaya doğru akması ve dünyanın bir noktasından diğerine omurga üzerinden taşınmasıdır. Önceki haftalarda konuşulduğu gibi, ister omurga, ister mobil ya da metro ağı olsun, bu ağlar birbirine bağlanır; şirket ağı da örnekte ulusal ağa bağlanmaktadır.

### 1.1 "ADSL router" aslında ne yapar?

Hoca evlerde "ADSL router" diye anılan cihazlar için yanlış bir kullanım olduğunu söyledi. Bu cihazlar aslında bir uç bağlantı noktasıdır ve bir yönlendiricinin sahip olduğu özelliklerin çok azını içerir. Evin içinde birden fazla dış bağlantı ve aralarında paslaşma yoktur; cihazın bir tarafı hat teknolojisine, diğer tarafı kablolu ya da kablosuz iç ağa bakar. Bu yüzden bu cihazlar statik yönlendirme yapar: gidilecek tek bir yer vardır, hesaplanacak bir yol yoktur.

Birden fazla dış bağlantı olsa bile, bunlar ayrı cihazlarsa aralarındaki karar mekanizması bu cihazlardan bağımsız üçüncü bir cihazla ya da elle yürütülür. Örneğin bir sağlayıcının bağlantısı koptuğunda başka bir sağlayıcıya ya da cep telefonu üzerinden bağlantıya geçmek elle yapılır. Şirket ağlarında ise farklı kampüsler ve bölgeler olabileceği için yapı daha geneldir.

## 2. IPv4'ün Kökeni ve Version Alanı

İnternet, ABD hükümetinin, özellikle savunma tarafının, bir felaket anında da çalışmaya devam edebilecek bir ağ ihtiyacından doğdu. ARPA adı Advanced Research Projects Agency'den gelir ve savunmayla ilişkilidir. Ağ önce birkaç üniversite arasında kuruldu, sonra ABD içinde yaygınlaştı, önce ticari kurumlara, en son bireysel kullanıma açıldı.

Bugün kullanımda olan IP sürümleri 4 ve 6'dır. IPv6'ya geçiş için defalarca tarih konuldu ve hep ertelendi; ne Türkiye'de ne dünyada geçiş tamamlanabildi. Büyük servis sağlayıcılar kendi iç ağlarında IPv6 kullansa da genel geçiş gerçekleşmedi.

IP sürümü başlıktaki Version alanında tutulur. Hoca şu soruyu sordu: IP'nin kaç sürümü olabilir? Version alanı 4 bit olduğu için 0-15 arasında değer alabilir, yani 16 farklı sürüm numarası vardır (ayrıntı Örnek Sorular bölümünde).

## 3. IPv4 Başlığının Alanları

Slayttaki başlık şeması şöyledir (ekrandan, 00:20:00). Slaytta "IPv4 başlığı bütün paketlerde taşınır ve protokolün ana parçaları için alanlar içerir" yazıyor. Her satır 32 bittir.

| Satır | Bit 0-3 | Bit 4-7 | Bit 8-15 | Bit 16-31 |
|---|---|---|---|---|
| 1 | Version | IHL | Differentiated Services | Total length |
| 2 | Identification (16 bit) | | | ayrılmış bit, DF, MF, Fragment offset (13 bit) |
| 3 | Time to live (8 bit) | | Protocol (8 bit) | Header checksum (16 bit) |
| 4 | Source address (32 bit) | | | |
| 5 | Destination address (32 bit) | | | |
| 6+ | Options (0 ya da daha fazla 32 bitlik kelime) | | | |

### 3.1 Sabit kısım ve IHL

Bu bölümü ikinci hoca araya girerek anlattı. Başlık 32 bitlik, yani 4 baytlık satırlardan oluşur ve 5 standart satır vardır; dolayısıyla 20 baytlık sabit bir başlık bulunur. Bunun altında Options denen değişken kısım vardır; bu kısım sıfır uzunlukta da olabilir, daha uzun da.

Version alanından sonra IHL (Internet Header Length) gelir. IHL de 4 bittir, en çok 15 olabilir. Ancak bu 15 bayt değil, 32 bitlik kelime (word) cinsinden başlık boyutudur. Bu yüzden başlık en çok

$$15 \times 4 = 60 \text{ bayt}$$

olabilir. 20 bayt sabit kısımdır, kalan 40 bayt seçenekler için ayrılmıştır.

### 3.2 Differentiated Services

Differentiated Services alanı aslında hizmet kalitesi (Quality of Service) konusunda konuşulmuştu. En başta Type of Service adıyla tanımlanmıştı. Hizmet kalitesi uygulayabilmek için kullanılır: ilk 6 bit paketin servis sınıfını tanımlar (daha önce konuşulan expedited forwarding ve assured forwarding sınıfları), son 2 bit ise ek bir kontrol mekanizması içindir.

> **Ek bilgi (derste anlatılmadı):** Bugün ilk 6 bit DSCP (Differentiated Services Code Point), son 2 bit ECN (Explicit Congestion Notification) olarak tanımlıdır. ECN, tıkanıklığın paketi düşürmeden bildirilmesini sağlar.

### 3.3 Total length

Total length 16 bittir ve bayt cinsindendir. Bu, bir IP paketinin başlıkla birlikte en çok 65535 bayt olabileceği anlamına gelir. Alan, 20 baytlık sabit başlığı, en çok 40 bayta kadar çıkabilen seçenek alanını ve taşınan veriyi, yani hepsinin toplam uzunluğunu verir. Buna göre:

- Seçenek yoksa en çok taşınabilecek veri: $65535 - 20 = 65515$ bayt.
- Başlık 60 bayt ise en çok taşınabilecek veri: $65535 - 60 = 65475$ bayt.

> **Ders sonrası not:** Altyazıda bu hesap karışık aktarılmış ("minimum da 65535-60 olabilir"). Doğrusu, taşınabilecek en büyük veri miktarının başlık uzunluğuna göre 65475 ile 65515 bayt arasında değiştiğidir (python ile kontrol edildi).

## 4. Bayt Sırası: Big Endian ve Little Endian

Total length'i anlatırken hoca önemli bir noktaya değindi. IP protokolü 32 bitlik SPARC işlemcisi üzerinde ve SunOS üzerinde geliştirildi; ilk gerçekleme orada yapıldı. SPARC big endian bir işlemcidir. Bunun anlamı şudur: bir değer belleğe yerleştirildiğinde, karşıdan bakınca en anlamlı kısım solda, en az anlamlı kısım sağdadır. Yani kağıda yazılan görüntüyle bellekteki saklanma görüntüsü birebir aynıdır. Bu yüzden TCP/IP'de her şey big endian üzerine kuruludur.

Ancak bazı işlemciler little endian çalışır; bazıları da açılıştaki yapılandırmaya göre ikisi arasında geçiş yapabilir. SPARC'tan sonraki dönemde en çok geliştirilen, üzerine yatırım yapılan ve bugün dünyada en yaygın olan Intel işlemciler little endian'dır. Bir işlemci ailesinde en anlamlı bayt en düşük adreste, diğerinde en yüksek adreste olduğu ve protokolde bit düzeyinde işlem yapıldığı için karışıklık olmasın diye iki tanım ortaya atılmıştır:

- **Network byte order:** tasarımdan, ilk özgün yapıdan dolayı her zaman big endian'dır.
- **Host byte order:** TCP/IP gerçeklemesinin çalıştığı işlemciye göre little ya da big endian'dır.

İşlemci little endian ise paket alanlarının hepsini big endian'dan little endian'a dönüştürmesi gerekir. Bu zaman alıcı bir iştir: bitleri kaydırmak, baytların yerini değiştirmek gerekir. Daha hızlı olsun, fonksiyon çağrısıyla uğraşılmasın diye bu dönüşümler makro olarak gerçeklenmiştir.

> **Hocanın vurgusu:** Bu konu özellikle üzerine basa basa söylendi. İşin komik tarafı, IP big endian bir işlemcide tasarlandığı için network byte order big endian'dır, ama bugün etrafımızda kullandığımız işlemcilerin neredeyse hepsi her pakette network byte order ile host byte order arasında dönüşüm yapmak zorundadır. Bu değişmeyen bir durumdur; IPv6 da big endian üzerine kuruludur.

> **Ek bilgi (derste anlatılmadı):** C'de bu dönüşümler `htons`, `htonl`, `ntohs`, `ntohl` adlarıyla bilinir (host-to-network short/long ve tersi). Big endian bir makinede bunlar hiçbir şey yapmaz.

## 5. Parçalama Alanları: Identification, DF, MF, Fragment Offset

### 5.1 Identification

Bu alan daha önce konuşulan bir konunun hayata geçmesi için vardır. İnternette farklı ağlar birleştirilir; dolayısıyla fiziksel ya da veri bağı katmanı düzeyinde farklı özelliklere sahip ağlardan geçilir. Örneğin her ağın çerçeve boyutu farklı olabilir. Hoca şunu sordu: çerçeve boyutları farklıysa ne yapacaksınız? Üst düzeydeki bir paketi alt düzeyde bir çerçeveye yerleştirmek için daha küçük bir alan varsa parçalama (fragmentation) olur. O zaman parçaların aynı özgün pakete ait olup olmadığını kontrol edip tanımlayabilmek gerekir. Identification alanı bunun içindir. Bir paket art arda parçalanabilir; alan buna da izin verir.

### 5.2 Ayrılmış bit, DF ve MF

Identification'dan sonra bir boşluk, yani ayrılmış (reserved) bir bit görülür. Asıl önemli olanlar ondan sonra gelen DF ve MF bitleridir.

Parçalama konuşulurken olası senaryolar tartışılmış ve sonunda en güzelinin parçalamanın hiç olmaması olduğu söylenmişti. Bunu sağlamanın iki yolu vardı: ya her yerde birebir aynı teknoloji kullanılacak (bu mümkün değil), ya da çıkış noktasından varış noktasına kadar parçalama istenmediği belirtilerek paket gönderilecek. Paket bir ağdan diğerine geçerken geçtiği ağda parçalanmadan gönderilemiyorsa göndericiye bir hata mesajı döner ve gönderici kendini buna göre ayarlar. DF (Don't Fragment) biti bu mekanizmayı çalıştırmak için vardır.

MF (More Fragments) ise "daha fazla parça var" demektir. Bir paket ikiye bölünmek zorunda değildir; beşe, ona, yirmiye, yirmi beşe bölünebilir. Parçaların hepsi aynı Identification değerine sahiptir. Sonuncusu hariç hepsinde MF biti 1 yapılır, yani arkadan başka parçaların geldiği söylenir. Son parçada MF 0'dır; böylece alıcı son parçayı aldığını anlar.

### 5.3 Fragment offset

Parçaların nereye yerleşeceği, özgün paketin hangi kısmı olduğu Fragment offset ile belirlenir. 16 bitlik alandan 3 bit (More Fragments, Don't Fragment ve ayrılmış bit) çıkarılınca 13 bit kalır. Bu alanla parçanın hangi konumdan itibaren yerleştirilmesi gerektiği söylenir.

> **Ders sonrası not:** Derste Fragment offset'in bayt cinsinden olduğu söylendi; doğrusu 8 baytlık birimler cinsindendir. 13 bitlik alan bu sayede $2^{13} \times 8 = 65536$ bayta kadar her konumu gösterebilir; bu yüzden son parça dışındaki parçaların veri uzunluğu 8'in katı olmalıdır.

## 6. TTL, Protocol, Header Checksum ve Adresler

### 6.1 Time to live

TTL 8 bitlik bir alandır ve bir paketin datagram ağında ne kadar süre dolaşabileceğini ifade eder. Özgün RFC'de bu alan saniye cinsinden tanımlanmıştır; en çok 255 saniye. Ancak daha sonra bunun pek anlamlı olmadığı görüldü: saniye cinsinden değeri tutmak çok fazla işlem gerektirir ve host'lar ile yönlendiriciler arasında milimetrik, yüzde yüz bir saat eşzamanlaması sağlanamaz. Bu yüzden alan atlama (hop) sayısına dönüştürüldü.

Buna göre bir IP paketi en çok 255 atlama gidebilir. Paket her yönlendiriciden bir sonrakine aktarılırken TTL bir azaltılır; sıfıra geldiğinde ilgili yönlendirici paketi artık iletmez, atar.

> **Ders sonrası not:** Derste değerin 255 ile başladığı söylendi. Başlangıç değerini gönderici belirler; büyük olasılıkla işletim sistemine göre 64, 128 ya da 255 gibi değerler kullanılır. 255 yalnızca alanın üst sınırıdır.

### 6.2 Protocol

Hemen yanındaki 8 bitlik alan Protocol alanıdır. IP bir taşıyıcıdır; ağ katmanında yer alır ve üstündeki hangi protokolün bilgisini taşıdığını bu alanla belirtir. 8 bit olduğu için IP kapsamında 256 farklı protokol taşınabilir. Sıfır değerinin de anlamı olabilir, yasaklı bir değer değildir. IP'nin kendisinin de bir protokol değeri vardır, çünkü IP de bir başka IP paketinin içinde taşınabilir.

### 6.3 Header checksum

Yanındaki 16 bitlik alan Header checksum'dır.

> **Hocanın vurgusu:** Bu alan çok önemlidir. IP, yönlendirmeyi sağlayabilmek için yalnızca ve yalnızca yönlendirmeyle ilgili olan, kendisine ait başlık kısmının doğruluğunu garanti etmek üzere bir sağlama toplamı kullanır.

Hoca hesabı şöyle anlattı: sıfırla başlanır, 16 bitlik değerler sırayla işleme sokulur, en son elde edilen değer bir kez daha işleme sokulur. Alıcı tarafta aynı değer benzer işleme sokulduğunda sonuç 0 çıkıyorsa hata olmamıştır.

> **Ders sonrası not:** Derste bu işlem XOR olarak anlatıldı. IPv4 başlık sağlama toplamı XOR değildir; başlıktaki 16 bitlik kelimelerin birler tümleyeni (one's complement) aritmetiğiyle toplanıp sonucun tümleyeninin alınmasıdır. Alıcı checksum alanı dahil aynı toplamı hesapladığında sonuç tümüyle 1 olur, tümleyeni 0 çıkar.

Başlıkta en ufak bir değişiklik olduğunda checksum yeniden hesaplanmalıdır. Hangi alan değişebilir? En basitinden TTL: her atlamada azaltıldığı için checksum da her yönlendiricide yeniden hesaplanır. Altyazının bu kısmı (00:36:24-00:37:20) bozuk aktarıldığı için hocanın burada eklediği ayrıntı tam anlaşılamıyor; söylenen, bu basitliğin paketlerin atlama atlama iletilme hızını ciddi ölçüde artırdığıdır. <!-- BELİRSİZ: 00:36:40-00:37:20 arası altyazı kopuk; özel ağ içinde IP düzeyinde yapılan bir uygulamadan söz ediliyor -->

### 6.4 Kaynak ve hedef adresleri

Sonra 32 bitlik iki alan gelir: Source address ve Destination address. Daha önce verilen mektup örneğindeki gibi, mektubun üzerinde gönderen ve alıcı mutlaka bulunur; her IP paketinin başlığında da bu ikisi mutlaka bulunur. Bu 20 baytlık kısım her IP paketinde vardır.

Seçenek sayısı IHL alanındaki değerden anlaşılır: IHL 5 ise seçenek yoktur, 6 ise bir kelime, 7 ise iki kelime seçenek vardır. IHL en çok 15 olabildiği için en fazla $15 - 5 = 10$ kelimelik seçenek bulunabilir.

## 7. IPv4 Seçenekleri

Bu bölümü yine ikinci hoca anlattı. Options kısmı teknik olarak 32 bitlik kelimelere yayılmıştır. Bir seçenek tek bayttan ibaret olsa bile otomatik olarak 4 bayta tamamlanır. Seçenek alanı ilk tasarımda protokole ek bir özellik kazandırabilmek, değişik denemeler yapabilmek ya da yeni bir sürüm oluşturulurken çok değişiklik gerekmeden işleri çözebilmek için konmuştur. Hocanın hatırladığı kadarıyla beş seçenek vardır:

- **Security:** Paketin önemli, gizlilik düzeyi yüksek bir paket olduğu ve örneğin her yerden geçmemesi gerektiği söylenir. Hoca bunun güvenlik açısından hiç makul olmadığını belirtti: hassas bilgiyi işaretleyip hedef tahtasına koymuş olursunuz.
- **Loose source routing:** Paketin geçmesi istenen yönlendiricilerin adresleri verilir; paket bunlardan geçer. Ama "gevşek" olduğu için paketin arada başka yönlendiricilerden de geçmesine izin verilir.
- **Strict source routing:** Başlangıçtan sona kadar geçilecek bütün yönlendiriciler tek tek belirtilir; paketin gidebileceği başka yer kalmaz.
- **Record route:** Paketin geçtiği bütün düğümlerin, yönlendiricilerin kaydedilmesi için kullanılır.
- **Timestamp:** Yönlendiriciler hem kendi adreslerini hem de bir zaman damgası bilgisini pakete ekler.

### 7.1 Neden bugün pek kullanılmıyor?

Seçenekler ortaya atıldığında İnternetin düğüm sayısı oldukça sınırlıydı. Başlık en çok 60 bayttır, 20 baytı sabittir, kalan 40 bayta 4 baytlık adreslerden en çok 10 tane sığar; seçeneğin kendi başlık bilgisi de konacağı için yaklaşık 9 adres, yani 9 atlama kaydedilebilir. Bugün bir üniversiteye ulaşana kadar bile geçilen yönlendirici sayısı bundan fazladır. Bu yüzden Record route ve Timestamp seçeneklerinin kullanımı şu anda makul değildir.

Diğer hoca buna şunu ekledi: günümüzde gerçek anlamda kullanılan, bir noktayla başka bir nokta arasındaki ping süresinin, yani paketin bir ağ katmanından diğerine ne sürede gittiğinin ölçülmesidir; ping ve traceroute gibi araçlarda bu tür bilgiden yararlanılır. Diğer seçenekler havada kalmıştır.

> **Ders sonrası not:** Ping süresi ölçümü büyük olasılıkla normalde ICMP echo mesajlarıyla, traceroute ise büyük olasılıkla TTL alanını adım adım artırarak yapılır; IP seçeneği gerektirmez; dolayısıyla bu araçların seçeneklere dayandığı söylenemez. Bazı ping gerçeklemelerinde Record route seçeneği isteğe bağlı olarak açılabilir (örneğin Linux'ta `ping -R`).

## 8. Sınıflı Adresleme

IP adresleri 32 bittir ve kullanımları için bazı düzenlemeler yapılmıştır. Hocalar anlatım sırasını değiştirmeye karar verdi: tarihsel olarak önce sınıflı (classful) adreslemeyi anlatmak, sonra öneklere dönmek daha mantıklıdır, çünkü ilk kullanım sınıflı idi, sonra öneklere dönüştü.

Slayt şöyledir (ekrandan, 00:50:00): eski adresler sabit boyutlu bloklar (A, B, C) halinde geliyordu; boyut adresin bir parçası olarak taşınıyordu ama esneklik yoktu. Bu yönteme sınıflı (classless'ın karşıtı) adresleme denir.

| Sınıf | İlk bitler | Yapı | Host adres aralığı |
|---|---|---|---|
| A | 0 | Network, Host | 1.0.0.0 - 127.255.255.255 |
| B | 10 | Network, Host | 128.0.0.0 - 191.255.255.255 |
| C | 110 | Network, Host | 192.0.0.0 - 223.255.255.255 |
| D | 1110 | Multicast address | 224.0.0.0 - 239.255.255.255 |
| E | 1111 | Reserved for future use | 240.0.0.0 - 255.255.255.255 |

### 8.1 A, B ve C sınıfları

Tasarımda 32 bitlik adres, ağ kısmı ve o ağın içindeki host kısmı olarak ikiye ayrılmıştır. A sınıfı için ilk bitin 0 olması gerekir; ağ kısmında geriye 7 bit kalır. $2^7 = 128$ olduğuna göre en çok 128 A sınıfı ağ olabilir. Bunun mantığı şudur: tasarımcılar adreslerin bütün dünyaya yayılacağını tam düşünmemiş, ABD için düşünmüşlerdi. Bir ülkede 128 tane büyük kurum ve her birinde çok sayıda host olacağı düşünülmüştü.

> **Ders sonrası not:** Derste A sınıfı bir ağda "1 milyon host" olduğu söylendi. 24 bitlik host kısmı $2^{24} = 16\,777\,216$ adres verir, yani yaklaşık 16,7 milyon.

B sınıfı 10 ile başlar. Burada host sayısı ile ağ sayısı dengelenmiş gibidir: her ağda $2^{16} = 65536$ adres, toplam $2^{14} = 16384$ ağ vardır.

C sınıfında ağ kısmı neredeyse 24 bittir, ama C sınıfı olduğunun anlaşılması için ilk 3 bitin 110 olması gerekir. Örüntü açıktır: 0, 10, 110. Böylece ağ için 21 bit kalır; $2^{21} = 2\,097\,152$ ağ olabilir ve her birinde $2^8 = 256$ adres vardır. Küçük kurumlar 256 bilgisayarlık C sınıfı, çok büyük kurumlar A sınıfı alacaktı. <!-- BELİRSİZ: altyazıda C sınıfı ağ sayısı "251" diye bozuk; değer bit sayısından hesaplandı -->

### 8.2 D ve E sınıfları

D sınıfı 1110 ile başlar ve çok noktaya yayın (multicast) adresleri içindir. Hoca bunun için günlük bir örnek verdi: bugün evlerde kullanılan yazıcılar bile kablosuzdur. macOS ya da Linux'ta "yeni yazıcı ekle" denildiğinde yazıcının markası, modeli karşınıza çıkar. Bunun nedeni, belirli bir çok noktaya yayın adres bölgesinin bulunması ve yazıcıların o bölgeden gelen bir sorguya cevap vermek zorunda olmasıdır. Böylece yazıcının ağda gerçekte hangi adresi aldığı bilinmeden, bu adres üzerinden sorulduğunda cevap verdiği için gerçek adresi öğrenilir.

E sınıfı 1111 ile başlar ve gelecekte kullanılmak üzere ayrılmıştır.

### 8.3 Sınıflı yapının sonu

IP'nin yalnız ABD'de değil Avrupa'da, Asya'da, Avustralya'da, bütün dünyada kabul görmesinden sonra bu A, B, C kullanımı pek anlamlı olmaktan çıktı. Örneğin bir kurum "çok farklı yerlerde kampüslerim var" diyerek B sınıfı istiyordu. Başlangıç böyleydi, ama sonra sınıfsız (classless) kullanıma geçildi. Hem sınıflı olarak dağıtılmış eski adreslerle hem yeni mantıkla dağıtılan adreslerle uyumlu çalışabilen bir önek mantığı kullanılmaktadır.

## 9. Önekler ve Alt Ağ Maskesi

Slayt şöyledir (ekrandan, 00:45:00):

- Adresler önek (prefix) denen bloklar halinde dağıtılır.
- Önek, adresin ağ kısmı tarafından belirlenir.
- Önek $2^L$ adres içerir ve $2^L$ sınırına hizalanır.
- Adres/uzunluk biçiminde yazılır, örneğin 18.0.31.0/24.

Şemada 32 bitin ilk L biti "Prefix length = L bits" (Network), kalan $32 - L$ bit Host olarak gösterilir. Altında alt ağ maskesi (subnet mask) yazılıdır: 24 tane 1 ve ardından 8 tane 0.

> **Ders sonrası not:** Slayttaki "Has $2^L$ addresses aligned on $2^L$ boundary" ifadesi hatalıdır: L önek uzunluğu ise blokta $2^{32-L}$ adres vardır ve blok $2^{32-L}$ sınırına hizalanır. Örneğin /24 bloğunda $2^8 = 256$ adres vardır.

Ağ kısmını (önek kısmını) host kısmından ayırt edebilmek için maskeleme yapılır: önek kısmındaki bitlerin tamamı kesintisiz 1 ile ifade edilir. Soldan başlayıp host kısmına kadar gelen bölümde, bu örnekte 24 tane 1 vardır ve aralarına 0 giremez, kesintiye uğrayamaz. Bunun nedeni bir sonraki adımda VE (AND) işleminde kullanılacak olmasıdır: bir adresi ağ ve host kısmına ayırmak için adres maskeyle VE işlemine sokulur ve ağ kısmı elde edilir. Host kısmındaki bitler maskede tamamen 0'dır.

18.0.31.0/24 gösteriminde 24, ağ (önek) kısmının en soldan sağa doğru arka arkaya kesintisiz 24 bitten oluştuğunu belirtir. Bu önekin maskesi 255.255.255.0'dır (python ile kontrol edildi).

## 10. Alt Ağlara Bölme

Önek yapısı kullanılarak alt ağlar (subnet) oluşturulur. Derste kullanılan slaytta bir üniversitenin Electrical Engineering, Computer Science ve Art bölümleri vardı; hoca "bizdeki yapıya çok benziyor" dedi. <!-- BELİRSİZ: alt ağ slaytı karelerde yok; slayttaki adres değerleri doğrulanamadı, yalnız önek uzunlukları altyazıdan alındı -->

Kuruma gelen adresin maskesinde soldan ilk 16 bit kesintisiz 1'dir, yani kuruma /16 önek verilmiştir. Kuruma bir adres bu önekle geliyorsa, kurum geriye kalan 16 host bitini kendi içinde ihtiyacına göre parçalayabilir. Bunu yaptığı anda host kısmını alt ağlara ayırmış olur. Yukarıdaki üst ağ kısmına dokunamaz, ama host kısmını kendi içinde bir kez daha alt ağ ve host diye bölebilir. Böylece en tepede ağ ve host ayrımı vardır; host kısmı bir kez daha alt ağ ve host olarak iki parçaya ayrılır.

Bu durumda alt ağın önek uzunluğu, kuruma gelen ana ağın önek uzunluğundan büyük olmak zorundadır; küçük olamaz, çünkü ilk 16 bit kurumun kontrolünde değildir. Örnekte Electrical Engineering'e /18, Computer Science'a /17, sanat bölümüne /19 önek verilmiştir. Önek uzunluğu, ana bloğun ne kadar parçalandığını gösterir: /19'un host kısmı daha küçük, /17'ninki daha büyüktür, /18 ikisinin arasındadır.

## 11. Birleştirme ve En Uzun Önek Eşleşmesi

### 11.1 Birleştirme (aggregation)

Slayt şöyledir (ekrandan, 01:00:00): birleştirme, birden fazla IP önekini tek bir büyük önekte birleştirerek yönlendirme tablosunun boyutunu küçültür.

```text
New York  <---- 192.24.0.0/19 (1 birleşik önek) ----  London (3 önek)
                                                        |-- 192.24.0.0/21  --> Cambridge
                                                        |-- 192.24.16.0/20 --> Oxford
                                                        |-- 192.24.8.0/22  --> Edinburgh
```

Slayttaki notlar: ISS tek bir önek duyurur (ISP advertises a single prefix); ISS'nin müşterilerinin önekleri farklıdır (ISP customers have different prefixes).

Bu, önek mantığının yönlendirmeye uyarlanmasıdır. Aynı bölgeye giden ve sonra alt ağlara ayrılan 3, 4, 5, 7, 10 tane farklı adresi yönlendirme tablosuna tek tek eklemeye gerek yoktur; hangi önekle ifade ediliyorsa ona göre yönlendirmek yeterlidir. Hoca yönlendirme konusunun başındaki benzetmeyi hatırlattı: başka bir şehre gidecekseniz, daha yolun başında o şehrin falan mahallesindeki falan sokağı sormaya başlamazsınız; önce şehrin yönünü öğrenirsiniz.

Örnekte Cambridge, Oxford ve Edinburgh, Londra'nın altındaki alt ağlardır. New York'tan çıkarken yalnızca Londra'ya doğru gidileceğini bilmek, yani ana öneki kullanarak yönlendirme yapmak işi kolaylaştırır: hem yönlendirme tablosunun bellek ihtiyacını hem de arama hızını en aza indirir. Paket Londra'daki yönlendiriciye geldiğinde bu yönlendirici /21 ile Cambridge'e, /20 ile Oxford'a, /22 ile Edinburgh'a yönlendirir. Ters yönde de bu ağlardan gelenler yukarıya doğru birleştirilerek çıkar; iki yönde de hızlanma sağlanır.

Adres aralıklarının kontrolü (python ile kontrol edildi):

| Önek | İlk adres | Son adres | Adres sayısı |
|---|---|---|---|
| 192.24.0.0/19 (birleşik) | 192.24.0.0 | 192.24.31.255 | 8192 |
| 192.24.0.0/21 (Cambridge) | 192.24.0.0 | 192.24.7.255 | 2048 |
| 192.24.8.0/22 (Edinburgh) | 192.24.8.0 | 192.24.11.255 | 1024 |
| 192.24.16.0/20 (Oxford) | 192.24.16.0 | 192.24.31.255 | 4096 |

Üç blok da birleşik /19 bloğunun içindedir.

### 11.2 En uzun önek eşleşmesi (longest matching prefix)

Bir sonraki slayt en uzun önek eşleşmesiydi. Bir adres birden fazla girdiye uyduğunda, en uzun önekle eşleşen girdiye göre gönderilmelidir. Londra'daki yönlendiricide /19'un içinde /21, /20 ve /22 vardır. Paketi /19'a göre yönlendirmemek gerekir, çünkü bakıldığında örneğin /20'de eşleşen bir girdi vardır; demek ki paket Oxford'a gidecektir. /21 ile eşleşiyorsa Cambridge'e, /22 ile eşleşiyorsa Edinburgh'a gönderilir. <!-- BELİRSİZ: en uzun önek eşleşmesi slaytı karelerde yok; slayttaki tablo/adres değerleri doğrulanamadı -->

Bu, yönlendiricideki karşılaştırma kodunu biraz karmaşıklaştırır, ama işi rahatlatır. En uzun önek, yani en küçük adres bölgesi kime aitse ona göre yönlendirme yapılır. Bu sayede adres bloklarını sorunsuzca parçalara bölüp, böldüklerimizi de düzgünce birleştirebiliriz.

> **Hocanın vurgusu:** En uzun önek eşleşmesi olayını unutmayın, bu önemli bir şey. IPv4'te adresleri hiyerarşik olarak birleştirmede ve bölmede bundan yararlanılır.

## 12. NAT ve PAT

### 12.1 Adres alanının yetersizliği

IPv4'ün en önemli sorunu, sınıflı ya da sınıfsız olsun, bütün dünyada kabul görmesinden sonra 32 bitlik adres alanının bağlanma ihtiyacındaki bütün host'ları bağlayamayacak durumda olmasıdır. $2^{32}$ yaklaşık 4 milyar eder, ama dünyada şu anda nereden bakılırsa bakılsın 4 milyardan fazla bağlanma ihtiyacı vardır. Aradaki yönlendiriciler, ayrılmış bloklar vb. düşülünce 32 bitin hepsini verimli kullanmak da mümkün değildir. IPv6'ya da yeterince hızlı geçilemedi.

### 12.2 Network Address Translation (klasik NAT)

Hoca NAT kavramında enteresan bir durum olduğunu söyledi: bugün uygulanan aslında port adres dönüşümüdür, ama otomatik olarak buna NAT denir. Klasik NAT'ta bir iç ağ (intranet) ve bir İnternet vardır. İnternet çıkışını sağlayan yönlendiricinin İnternete bakan bacağında, örneğin dünyanın her yerinden erişilebilen, yönlendirilebilen 5 gerçek adres bloğu olduğunu düşünelim. Her biri C sınıfı olsun.

İçeriden gelen bir istek dış dünyaya gönderilirken bu havuzdaki adreslerden birine eşlenir. Böylece içeride, dünyanın başka bir yerinde kullanılan bir IP adresi gönlünüzce tekrar kullanılabilir; adresler yeniden kullanılmış olur. Bu tür iç adresler kampüsün, iç ağın içine hapsedilmiştir; o halleriyle dışarı çıkmalarına izin verilmez. Dışarı çıkacakları zaman dış bacaktaki o anda boşta olan bir adres üzerinden çıkarılırlar.

Bu durumda havuzdaki adres sayısı kadar kişi aynı anda içeriden dışarı çıkabilir. Bu güzel bir rakamdır, ama bunu yaparken dış dünyada bir blok adres orada bağlı kalır; tek bir adresle iş çözülmez.

> **Ders sonrası not:** Derste 5 C sınıfı blok için "1250 adres" denildi. 5 × 256 = 1280 adres, kullanılabilir host sayısı olarak 5 × 254 = 1270 adres eder (python ile kontrol edildi).

### 12.3 Port Address Translation (PAT)

Bu yapıyı daha akıllı hale getirmek ve dışarıda bağlanan adres bölgesini en aza indirmek için port adres dönüşümüne geçilmiştir. Dışarı çıkarken yalnız ağ katmanıyla çıkılmaz; üstteki taşıma katmanında bir protokol kullanılır. Aynı ağ adresinde hangi taşıma katmanı uygulamasının dışarı çıkmak istediğini ya da içeri gelen verinin hangisine ait olduğunu belirleyebilmek için bir sayısal değer kullanılır. Bu değerlere port denir. İşletim sistemindeki süreç kimliğine (process ID) benzer: aynı host üzerinde aynı ağ katmanını kullanan uygulamaları birbirinden ayırt etmek için benzersiz bir numara verilir. Port 16 bittir; dolayısıyla bir ağ adresi kendi üzerindeki taşıma katmanında $2^{16}$ farklı uygulamayı destekleyebilir.

İçeride neredeyse istenen bir IP adresi kullanılır (bu adreslerin özellikleri aşağıda). Paket dışarı çıkarılırken dış bacaktaki IP adresiyle birlikte bu çıkış için bir port ayrılır. Uygulama dışarı mutlaka bir taşıma katmanı protokolüyle (TCP, UDP, RTP vb.) çıkar. Tek başına ağ katmanı düzeyinde bir noktadan diğerine bağlantı kurmak bambaşka bir şeydir; o zaman bir sanal özel ağ (VPN) kurulmuş olur. Uygulama trafiği söz konusu olduğuna göre taşıma katmanı işin içindedir: içeride bir port, dışarıda bir port vardır.

Slayttaki örnek (ekrandan, 01:05:00):

```text
[İç ağ: dizüstüler, PC, yazıcı] -- müşteri yönlendiricisi ve LAN
      |
      v  Packet before translation:  IP = 10.0.0.1,     port = 5544
  [NAT box/firewall]   (müşteri tesisinin sınırı)
      |
      v  Packet after translation:   IP = 198.60.42.12, port = 3344
  [ISP router] --> (to Internet)
```

NAT desteğine sahip yönlendirici bu eşlemeyi kendinde saklar: "içeriden 10.0.0.1:5544'ü dışarıda 198.60.42.12:3344'e eşledim" diye bir tabloya yazar ve paketi dış dünyaya bu şekilde gönderir. Dış dünyadan gelen cevap doğal olarak 198.60.42.12:3344'e gelir; yönlendirici bunu içeride tekrar 10.0.0.1:5544'e geri dönüştürür.

Slayttaki başlık ve maddeler: NAT kutusu bir dış IP adresini birçok iç IP adresine eşler; bağlantıları ayırt etmek için TCP/UDP portunu kullanır; katmanlamayı çiğner, evlerde vb. çok yaygındır.

Hoca bu mantığın çok olağanüstü bir buluş olmadığını, telefon santrallerinin çalışma biçiminden hiç farklı olmadığını söyledi. Dışarıya tek bağlantısı olan ama içeride örneğin 16 dahili hattı destekleyen bir santralde içeride 1, 3, 5 gibi numaralarınız vardır; yalnız onu çevirerek birbirinizle konuşursunuz. Aynı hattan örneğin 9'u çevirip dış hat alarak dışarı çıkabilir, dışarıdan arayan biri de dahili numarayı tuşlayarak içeri ulaşabilir. PAT bunun IP protokolüne uyarlanmış halidir. Bugün dış dünyaya çıkarken bütün dönüşümler bu mantıkla yapıldığı ve eski NAT mantığı artık kullanılmadığı için endüstri buna kısaca NAT (Network Address Translation) adını verir.

> **Hocanın vurgusu:** Slayttaki ikinci madde önemlidir: NAT katman yapısını hiçe sayan bir yapıdır. Normalde katmanları birbirinden bağımsız tutmak gerekir; burada taşıma katmanına özgü bir bilgi ağ katmanının işini görmek için kullanılır. Bu çok yanlıştır, ama çok yaygın kullanılan bir yaklaşımdır.

### 12.4 Özel adres blokları

Eski sınıflardan belirli adres bölgeleri blok halinde iç kullanıma ayrılmıştır. Bu bloklar RFC biçiminde duyurulduğu için üreticiler bu adresleri kesinlikle İnternette yönlendirmez, yönlendirme tablolarında barındırmaz. Böylece bu adresler yalnız iç ağlarda (intranet) kullanılır. İnternette ülkeler arasında yönlendirme yapan bir yönlendiricinin 10 ile başlayan, 172.16 ile başlayan ya da 192.168 ile başlayan bir adresi yönlendirmesi mümkün değildir; bu kısıt doğuştan konmuştur. Kampüs içinde, iç ağda ise bu adresler istenildiği gibi kullanılabilir. <!-- BELİRSİZ: özel adres slaytı karelerde yok; altyazıda bu kısım halüsinasyonlu (01:14:29) -->

> **Ek bilgi (derste anlatılmadı):** RFC 1918'deki özel adres blokları büyük olasılıkla şunlardır: 10.0.0.0/8, 172.16.0.0/12 ve 192.168.0.0/16.

## 13. IPv6

### 13.1 Hedefler

IPv6 çalışmalarının 1990'lardaki temel sebebi, dersin başından beri konuşulan adres bölgesinin yetersizliğidir. Diğer hedefler:

- 4 milyardan çok daha fazla host'u destekleyebilmek.
- Yönlendirme tablolarının boyutunu azaltmak.
- IPv4'te bir türlü protokolün doğal bir parçası haline gelemeyen güvenliği IPv6'nın doğal bir parçası yapmak.
- Hizmet türü desteğini düzenlemek: dersin başında anlatıldığı gibi, IPv4'teki Type of Service alanı o kadar çok değişmiştir ki (önce bu kadar bit böyle, sonra şu kadar bit şöyle) kafa karıştırıcı olmuştur.
- Mobil ağlarda adres değişmeden dolaşım (roaming) yapılabilmesi; bugünkü uygulamada adres çok sık değişir, IPv6 buna doğrudan destek sağlar.
- IPv4 ile bir arada yaşayabilmek.

Slaytta, 2011 itibarıyla yaygınlaştırmanın yavaş ve sancılı olduğu yazıyordu. Adresler bitmişti ama adres sıkıntısına NAT ve PAT ile başka bir çözüm bulunduğu için kimse bu riskin altına girmek istemedi. Hocalar geçişin birkaç kez, örneğin 1 Ocak 2003 gibi tarihler konarak planlandığını ve ertelendiğini anlattı. NAT ile işler çözülebildiği sürece, ki NAT birçok güvenlik açığı ve başka sorunlar da yaratır, bu durum yarım yamalak devam edecek gibi görünüyor.

### 13.2 IPv6 başlığı

Slayt şöyledir (ekrandan, 01:20:00): IPv6 başlığının adresleri çok daha uzundur (32'ye karşı 128 bit) ve başlık daha basittir (uzantı başlıkları kullanıldığı için). Her satır 32 bittir.

| Satır | Alanlar |
|---|---|
| 1 | Version, Diff. Serv., Flow label |
| 2 | Payload length, Next header, Hop limit |
| 3-6 | Source address (16 bayt) |
| 7-10 | Destination address (16 bayt) |

Başlık gerçekten çok basittir. Version alanının hemen yanında Differentiated Services, onun yanında Flow label vardır. Yine 32 bitlik satırlara oturtulmuş, yine big endian üzerine kurulmuştur. Differentiated Services konusu daha önce işlenmişti. Flow label ile akışlar birbirinden ayırt edilir. Bu bilginin bütün yönlendiricilerde tanımlı olması gerekir; o zaman paket bir yönlendiriciye geldiğinde, flow label'a ve differentiated services sınıfına göre ne yapacağını bilir. Sorun şudur: bunu bir kampüste, bir metropolde, bir ülkede ya da bir kıtada değil, dünyanın tamamında yapmak gerekir.

Hoca ayrıca IPv4'teki başlık sağlama toplamına değindi: teknolojinin geldiği noktada metropol ve geniş alan ağlarında paket kaybı ve bozulma ihtimali oldukça düşüktür. <!-- BELİRSİZ: 01:20:51-01:21:41 arası altyazı yok; IPv6'da checksum'ın kaldırılmasıyla ilgili açıklama tam duyulmuyor -->

> **Ek bilgi (derste anlatılmadı):** IPv6 başlığında Header checksum alanı yoktur; hata denetimi büyük olasılıkla alt katmanlara (çerçeve CRC'si) ve üst katmanlara (TCP/UDP sağlama toplamı) bırakılmıştır. Bu sayede yönlendiricilerin her atlamada checksum yeniden hesaplaması gerekmez.

### 13.3 Uzantı başlıkları

Slayt şöyledir (ekrandan, 01:25:00): IPv6 uzantı başlıkları diğer işlevleri üstlenir.

| Uzantı başlığı | Açıklama |
|---|---|
| Hop-by-hop options | Yönlendiriciler için çeşitli bilgiler |
| Destination options | Hedef için ek bilgi |
| Routing | Ziyaret edilecek yönlendiricilerin gevşek listesi |
| Fragmentation | Datagram parçalarının yönetimi |
| Authentication | Göndericinin kimliğinin doğrulanması |
| Encrypted security payload | Şifrelenmiş içerik hakkında bilgi |

Hop-by-hop seçenekleri bir sonraki yönlendiricilere bilgi vermek içindir. Destination seçenekleri hedefle ilgilidir. Routing, IPv4'te anlatılan loose source routing'e karşılık gelir: "giderken bu yönlendiricilerden geçmeye dikkat et; bunlardan geçersen yeterli, ama başka yönlendiricilerden de geçebilirsin." Fragmentation parçalamayla ilgilidir.

### 13.4 Jumbo paketler

IPv6'nın en önemli özelliklerinden biri jumbo paket (jumbogram, hoca "jumbo frame" de dedi) denen çok büyük IP paketlerine izin vermesidir. Bu özellikle veri merkezlerinde önemlidir. IPv4'te paket boyu 65535 bayt ile, Identification alanı da 16 bit ile sınırlıdır. Bugün veri merkezlerinde standart hale gelmiş 40 Gbit/s ya da 100 Gbit/s hızları bu boyuttaki paketlerle doyurmak mümkün olmaz: o kadar hızlı paket üretilemez, paket boyu yetmez. IPv6 bu sorunu IPv4'teki 65535 baytlık sınırın çok üstündeki paket boyutlarıyla çözmeye çalışır.

### 13.5 Kimlik doğrulama ve şifreleme

IPv6 kimlik doğrulamayla ilgili özellikler içerir. En önemli özelliklerinden biri de, şifrelenmiş içerik başlığıyla taşınan verinin düz metin olarak gitmemesidir. Bu özellikler RFC'lerde tanımlanmış ve bazı uç noktalar dışında birçok işletim sistemince gerçeklenmiştir; ama geçiş hâlâ tamamlanmamıştır.

Hocalar IPv6 tasarımında katılımcı bir yaklaşım olduğunu, birçok kurumun fikir beyan ettiğini ve bazı konularda bölünmeler yaşandığını söyledi; Hop limit gibi alanların neden öyle seçildiğine dair tartışmalar ders kitabında yer alır. Bunlar zorunlu değildir, merak edenler okuyabilir.

## Örnek Sorular

**Soru 1** (derste sözlü, 00:19:58): IP'nin kaç farklı sürümü olabilir?

> **Çözüm:** IPv4 başlığındaki Version alanı 4 bittir. 4 bit 0-15 arasında değer alabileceği için $2^4 = 16$ farklı sürüm numarası tanımlanabilir. Bugün kullanımda olanlar 4 ve 6'dır.

**Soru 2** (derste sözlü, 00:29:15): Paketin geçtiği ağların çerçeve boyutları birbirinden farklıysa ne yapılır?

> **Çözüm:** Paket daha küçük çerçeveye sığmıyorsa parçalanır. Parçalar aynı Identification değerini taşır, sonuncusu dışındakilerde MF = 1'dir, her parçanın yeri Fragment offset ile belirtilir. Parçalama istenmiyorsa DF biti 1 yapılır; paket geçemezse göndericiye hata mesajı döner.

**Soru 3** (derste sözlü, 00:36:24): Başlıkta bir değişiklik olunca checksum yeniden hesaplanmalıdır. Hangi alan her atlamada değişir?

> **Çözüm:** TTL. Her yönlendirici TTL'i bir azalttığı için başlık checksum'ı her atlamada yeniden hesaplanır.

## Dersin Toparlaması

Bu derste İnternetin ağ katmanı ve onu bir arada tutan IP protokolü ele alındı. IPv4 başlığı alan alan incelendi: 20 baytlık sabit kısım ve en çok 40 baytlık seçenekler, IHL'nin kelime cinsinden olması, Total length'in 65535 baytlık sınırı, parçalamayı yöneten Identification, DF, MF ve Fragment offset alanları, atlama sayısına dönüşmüş TTL, Protocol, yalnız başlığı koruyan checksum ve 32 bitlik adresler. Network byte order'ın big endian oluşu ve bunun bugünkü little endian işlemcilere getirdiği dönüşüm yükü özellikle vurgulandı. Beş IPv4 seçeneği ve bugün neden pek kullanılmadıkları anlatıldı.

Adresleme tarafında önce tarihsel sınıflı adresleme (A-E sınıfları), sonra önekler ve alt ağ maskesi, alt ağlara bölme, birleştirme ve en uzun önek eşleşmesi işlendi. Adres sıkıntısına çözüm olarak NAT ve onun bugünkü biçimi olan PAT, katmanlamayı çiğneyen ama çok yaygın bir yöntem olarak anlatıldı. Son olarak IPv6'nın hedefleri, sade başlığı, uzantı başlıkları ve jumbo paketleri tanıtıldı. Bir sonraki derste İnternet kontrol protokolleri ve label switching/MPLS konularına geçilecektir.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
