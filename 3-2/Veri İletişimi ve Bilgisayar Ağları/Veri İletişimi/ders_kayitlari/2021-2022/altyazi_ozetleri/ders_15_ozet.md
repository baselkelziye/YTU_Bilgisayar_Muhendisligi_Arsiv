# Ders 15 Çalışma Özeti

## Genel Konular

- Ders 6 Aralık 2021 Pazartesi günü online yapıldı. Dersi Dr. Furkan Çakmak anlattı. Kayıt yaklaşık 1 saat 32 dakika.
- Yerel ağ (LAN) teknolojileri ve IEEE 802 projesi:
  - veri bağlantı katmanının LLC (Logical Link Control) ve MAC (Media Access Control) alt katmanlarına ayrılması,
  - LLC hizmet türleri ve PDU yapısı.
- Ortam erişim yöntemleri:
  - ALOHA ve slotlu ALOHA (slotted ALOHA),
  - CSMA (Carrier Sense Multiple Access) türleri,
  - CSMA/CD (Collision Detection).
- IEEE 802.3 Ethernet: çerçeve yapısı, Fast Ethernet, Gigabit Ethernet ve sonrası, Metro Ethernet, PoE (Power over Ethernet).
- IEEE 802.4 Token Bus.
- IEEE 802.5 Token Ring: jeton (token), öncelik ve rezervasyon, halkadaki bit sayısı, izleme istasyonu (monitor station).
- FDDI (Fiber Distributed Data Interface): senkron ve asenkron çerçeveler, 4B/5B kodlama, DAS/SAS istasyonları.
- Kısaca kablosuz ve kişisel alan ağları: 802.11, Bluetooth, ZigBee, WiMAX.
- Proje ve ikinci vize duyurusu.

## Hocanın Özellikle Vurguladığı Kısımlar

- Noktadan noktaya iletişimde adres gerekmez. Çok noktalı iletişimde alıcının adresi söylenmelidir. Hoca vizede bununla ilgili bir soru sorduklarını hatırlatıyor.
- LAN protokolleri çok noktalı modda çalışır. Farklı ağ kartlarının ve protokollerin uyumlu konuşabilmesi için IEEE 802 projesi geliştirilmiştir.
- Paylaşılan ortamda en ciddi sorun çarpışmadır (collision). İki istasyonun verisi havada veya kabloda çakışınca hiçbir taraf için anlam taşımaz.
- Token kavramı çok önemlidir. Token da bir çerçevedir. Token'ı alan istasyon tek başına veri gönderdiği için çarpışma olmaz.
- Token Ring'deki öncelik ve rezervasyon mekanizmasını iyi öğrenin. Hoca bunun mülakatlarda ve iş hayatında "buna benzer bir şey yap" diye karşınıza çıkacağını söylüyor.
- Token Ring'de veriyi hattan alıcı değil, veriyi koyan istasyon çeker.
- FDDI'da öncelik istasyonlara değil çerçevelere verilir. Aynı istasyonun canlı görüntü ve sesi öncelikli (senkron), e-postası önceliksiz (asenkron) gönderilebilir.
- 4B/5B kodlamayı dikkatle dinlemenizi istiyor. Her 4 bit, art arda çok sayıda 0 içermeyen 5 bitlik bir kodla gönderilir. 16 bit veri için 20 bit gönderilir.
- PoE ile cihazlar elektriği de Ethernet kablosundan alır. Güvenlik kameraları ve bazı sensörler bu şekilde çalışır. Altyapının PoE'yi desteklemesi gerekir.

## Kısa Tekrar Notları

- **IEEE 802 katmanları:** 802.1 ağlar arası işler ve yönetim, 802.2 LLC, 802.3/802.4/802.5 MAC ve fiziksel katman.
- **LLC hizmetleri:** Onaysız bağlantısız (unacknowledged connectionless), bağlantı yönelimli (connection mode), onaylı bağlantısız (acknowledged connectionless).
- **LLC PDU:** DSAP, SSAP, denetim alanı, bilgi alanı.
- **ALOHA:** İstasyon istediği an gönderir. En yüksek verim yaklaşık %18,4.
- **Slotlu ALOHA:** Gönderim yalnız slot başlarında yapılır. En yüksek verim yaklaşık %36,8.
- **CSMA:** Göndermeden önce hat dinlenir.
- **CSMA/CD:** Gönderirken çarpışma izlenir. Çarpışma olursa jam sinyali gönderilir ve ikili üstel geri çekilme (binary exponential backoff) ile beklenir.
- **Ethernet çerçevesi:** Önsöz (preamble) 7 bayt, SFD 1 bayt, hedef adres 6 bayt, kaynak adres 6 bayt, uzunluk/tip 2 bayt, veri 46–1500 bayt, CRC 4 bayt.
- **Ethernet sürümleri:** 802.3u Fast Ethernet (100 Mbps), 802.3z/802.3ab Gigabit Ethernet, sonra 10, 40, 100 Gbps.
- **Token Bus (802.4):** Fiziksel olarak bus veya ağaç, mantıksal olarak halka. 75 Ω koaksiyel. Veri en çok 8182 bayt. Öncelik sınıfları 0, 2, 4, 6.
- **Token Ring (802.5):** Halka topoloji. Token 3 bayt (SD, AC, ED). Diferansiyel Manchester kodlama. 4/16 Mbps. Bitler en anlamlı bitten (MSB) başlayarak gönderilir.
- **Halkadaki bit sayısı:** $B = \dfrac{L \cdot R}{v}$
- **İzleme istasyonu:** Kaybolan token'ı yeniler, sahipsiz (orphan) çerçeveleri temizler.
- **FDDI:** Fiber üzerinde token tabanlı. 100 Mbps. Çift halka. 4B/5B + NRZI kodlama.
- **DAS / SAS:** Çift bağlı (dual attachment) / tek bağlı (single attachment) istasyon.

## Detaylı Açıklamalar

### IEEE 802 ve Veri Bağlantı Katmanı

IEEE 802 projesi veri bağlantı katmanını iki alt katmana ayırır:

- **LLC (802.2):** Akış ve hata denetimi, üst katmanla arayüz.
- **MAC:** Ortama erişim. CSMA/CD (802.3), Token Bus (802.4), Token Ring (802.5) gibi yöntemler burada yer alır.

MAC yöntemi fiziksel katmanda uygun bir altyapı ister. Örneğin bir protokol 50 Ω'luk koaksiyel kablo istiyorsa o kablo kullanılmalıdır.

Ortam erişim yöntemleri üç sınıfta incelenir: sabit atamalı (fixed), çekişmeli (contention, ör. CSMA/CD) ve token/rezervasyon tabanlı (ör. Token Ring).

### ALOHA ve Slotlu ALOHA

Ada halkları birbirine mesajı tekneyle taşıyordu. Hawaii'de adalar arasında radyo frekansıyla kurulan ALOHA ağı bu iletişimi kablosuz yaptı.

**ALOHA:** Her istasyon gönderecek verisi olduğunda yayına başlar. Herkes yayını duyar; mesaj kendisine geldiyse alır. İki istasyon aynı anda gönderirse çarpışma olur. Hat en iyi durumda yaklaşık beşte bir oranında kullanılabilir.

**Slotlu ALOHA:** Zaman, bir çerçeve süresi uzunluğunda slotlara bölünür. İstasyonlar yalnız slot başında gönderime başlayabilir. Böylece çarpışma olasılığı azalır ve verim yaklaşık iki katına çıkar.

$$S_{ALOHA} = G e^{-2G} \Rightarrow S_{max} = \frac{1}{2e} \approx 0{,}184$$

$$S_{slotlu} = G e^{-G} \Rightarrow S_{max} = \frac{1}{e} \approx 0{,}368$$

### CSMA Türleri

Temel fikir: göndermeden önce hattı dinle, hat boşsa gönder.

- **1-ısrarcı (1-persistent):** Hat meşgulse sürekli dinle, boşalınca hemen gönder. Birden fazla istasyon bekliyorsa hat boşaldığı anda hepsi birden gönderir ve çarpışır.
- **Israrsız (non-persistent):** Hat meşgulse rastgele bir süre bekle, sonra yeniden dinle. Çarpışma azalır ama hat boşken de beklenebilir.
- **p-ısrarcı (p-persistent):** Slotlu kanallarda kullanılır. Hat boşsa $p$ olasılıkla gönder, $1-p$ olasılıkla bir slot bekleyip yeniden dene.

### CSMA/CD

Gönderici, iletim sırasında hattı izlemeye devam eder. Çarpışmayı algılarsa:

1. İletimi keser ve kısa bir jam sinyali gönderir. Böylece tüm istasyonlar çarpışmayı fark eder.
2. İkili üstel geri çekilme ile rastgele bir süre bekler. $n$. denemeden sonra $0$ ile $2^{\min(n,10)} - 1$ arasında rastgele bir $k$ seçilir ve $k$ slot süresi beklenir.
3. Hattı yeniden dinler ve tekrar dener. 16 başarısız denemeden sonra çerçeve bırakılır.

Hoca jam sinyalini, kalabalık bir sınıfta herkesi susturmak için bağıran birine benzetiyor.

### IEEE 802.3 Ethernet

**Çerçeve yapısı:**

| Alan | Boyut |
|---|---|
| Önsöz (preamble) | 7 bayt, her biri `10101010` |
| SFD (Start Frame Delimiter) | 1 bayt, `10101011` |
| Hedef adres | 6 bayt (MAC adresi) |
| Kaynak adres | 6 bayt (MAC adresi) |
| Uzunluk / tip | 2 bayt |
| Veri | 46–1500 bayt |
| CRC (FCS) | 4 bayt |

Önsöz alıcının saatini senkronize etmek içindir; "ben geliyorum" demektir.

**Sürümler:** IEEE yeni geliştirmelerde standart adının sonuna harf ekler. Harfler bitince iki harf kullanılır (ör. 802.3ab).

- 802.3u: Fast Ethernet, 100 Mbps, otomatik anlaşma (auto-negotiation).
- 802.3z ve 802.3ab: Gigabit Ethernet.
- Sonraki sürümler: 10 Gbps, 100 Gbps ve üstü.

**Metro Ethernet:** Ethernet teknolojisinin yerel ağın dışına, şehir ölçeğine taşınmasıdır.

**PoE (Power over Ethernet):** Ethernet kablosu üzerinden hem veri hem elektrik iletilir. Ayrı bir prize gerek kalmaz. Eski sabit telefonların da hattan gelen düşük gerilimle çalışması bunun ilkel bir örneğidir.

### IEEE 802.4 Token Bus

1980'lerin başında General Motors tarafından fabrika otomasyonu için önerildi. CSMA/CD'deki bekleme ve çarpışma sorunlarını önlemek amaçlandı.

- Fiziksel topoloji bus veya ağaç (kademeli bus) olabilir. İstasyonlar mantıksal bir halka oluşturur.
- Her istasyon kendinden önceki ve sonraki istasyonu tanır. Token bu sırayla dolaşır.
- Token'ı alan istasyon, verisi varsa gönderir. İşi bitince token'ı sıradakine verir.
- MAC kısmı karmaşıktır: 10 farklı zamanlayıcı ve 24 farklı durum vardır.
- Genellikle 75 Ω koaksiyel kablo kullanılır. Üç modülasyon seçeneği vardır: faz sürekli FSK, faz uyumlu FSK ve çok seviyeli ikili-ikili (duobinary) AM/PSK. Hız 10 Mbps'e kadar çıkar.
- Veri alanı en çok 8182 bayttır. Bu, Ethernet'in yaklaşık beş katıdır.
- Öncelik sınıfları 0, 2, 4, 6'dır. 6 en yüksek önceliktir. Canlı yayın gibi gecikmeye duyarlı trafik yüksek öncelik alır.
- Öncelikler dinamik olarak değiştirilebilir.

### IEEE 802.5 Token Ring

İstasyonlar bir halka üzerinde dizilir. Hat boşken bile 3 baytlık token sürekli dolaşır.

**İşleyiş:**

1. Göndermek isteyen istasyon token'ı yakalar ve onu bir veri çerçevesine dönüştürüp halkaya basar. Artık başka kimse gönderemez.
2. Her istasyonun ağ kartı (NIC) çerçevenin kendisine gelip gelmediğine bakar. Gelmediyse yanındakine iletir.
3. Hedef istasyon çerçevenin bir kopyasını alır, hata denetimini yapar ve sonucu çerçevenin denetim kısmına yazar. Çerçeveyi iletmeye devam eder.
4. Çerçeve halkayı dolaşıp göndericiye döner. Gönderici alındı bilgisini görür, çerçeveyi halkadan çeker ve yerine token koyar.

Bir istasyon token'ı yalnız belli bir süre tutabilir (token holding time). Süre bitince token'ı bırakmalıdır.

**Halkadaki bit sayısı:** $L$ metre uzunluğunda, $R$ bit/s hızındaki bir halkada sinyal $v$ m/s hızla ilerliyorsa bir bitin hatta kapladığı uzunluk $v / R$ metredir. Halkada aynı anda bulunan bit sayısı:

$$B = \frac{L}{v/R} = \frac{L \cdot R}{v}$$

**Öncelik ve rezervasyon:** Token'ın AC (Access Control) baytı öncelik ve rezervasyon bitlerini taşır. Derste öncelik seviyeleri 0, 2, 4, 6 olarak anlatıldı.

- Göndermek isteyen istasyon, token'daki rezervasyon değerine bakar.
- Kendi önceliği yazılı değerden yüksekse eski değeri silip kendi önceliğini yazar.
- Kendi önceliği düşükse bir şey yapmaz ve bekler.
- Halka dolaşıldıktan sonra token en yüksek önceliği isteyen istasyona verilir.
- Aynı öncelikte birden çok istek varsa önce rezervasyonu yapan hak kazanır.
- Yüksek öncelikli istasyonların hattı tamamen tekelleştirmemesi için öncelikler zaman zaman dinamik olarak değiştirilebilir.

**İzleme istasyonu (monitor station):** Akışı izler ve anormallik olunca müdahale eder. Yedek bir izleme istasyonu da bulunur. İki temel görevi vardır:

- **Token yok:** Token'ı alan istasyon onu geri bırakmadan hattan koparsa halkada token kalmaz. Token'ın bir tur dönmesi için gereken süre (ör. istasyon başına 3 ms ise 30 istasyonda 90 ms) güvenlik payıyla (ör. iki katı) aşılırsa izleme istasyonu yeni token üretir.
- **Sahipsiz çerçeve (orphan frame):** Hedef istasyon veya gönderici hattan koparsa çerçeve sahipsiz kalır ve sürekli döner. İzleme istasyonu bunu fark edip halkadan temizler ve yeni token koyar.

**Diğer özellikler:**

- Diferansiyel Manchester kodlama kullanılır.
- İlk sürümlerde hız 4 ve 16 Mbps'tir.
- 802.3 ve 802.4 baytları en az anlamlı bitten (LSB), 802.5 en anlamlı bitten (MSB) başlayarak gönderir.
- Veri alanı yaklaşık 4500 bayta kadar çıkabilir.
- İletimi iptal etmek için yalnız SD ve ED'den oluşan 2 baytlık bir iptal (abort) dizisi vardır.

### FDDI

Fiber optik kablo üzerinde çalışan, token tabanlı bir ANSI standardıdır. İlk sürüm 100 Mbps hıza ulaşır. İşleyişi Token Ring'e çok benzer.

**Senkron ve asenkron çerçeveler:**

- **S-frame (senkron):** Zamana duyarlı, öncelikli veri (ör. canlı ses ve görüntü).
- **A-frame (asenkron):** Önceliksiz veri (ör. e-posta, dosya yükleme).

Her istasyon için token'ın beklenen dönüş süresi (TTRT) ve gerçek dönüş süresi (TRT) tutulur. İstasyon token'ı alınca önce senkron çerçevelerini gönderir. Kalan süre varsa asenkron çerçevelere geçer. Ayrılan sürenin tamamını kullanmak zorunda değildir.

**4B/5B kodlama:** FDDI, NRZI kodlamayı kullanır. NRZI'de art arda gelen 0'lar senkronizasyonu bozar. Bu yüzden her 4 bitlik veri 5 bitlik bir koda dönüştürülür. 5 bitlik kodlar, ardışık 0 sayısını sınırlayacak şekilde seçilmiştir.

$2^4 = 16$ veri değeri $2^5 = 32$ olası koddan seçilir. Kalan kodların bir kısmı denetim sembolleri için kullanılır. Bedeli %25 ek yüktür: 16 bit veri için 20 bit gönderilir.

| Veri | Kod | Veri | Kod |
|---|---|---|---|
| 0000 | 11110 | 1000 | 10010 |
| 0001 | 01001 | 1001 | 10011 |
| 0010 | 10100 | 1010 | 10110 |
| 0011 | 10101 | 1011 | 10111 |
| 0100 | 01010 | 1100 | 11010 |
| 0101 | 01011 | 1101 | 11011 |
| 0110 | 01110 | 1110 | 11100 |
| 0111 | 01111 | 1111 | 11101 |

Örnek: alıcı `11011` görürse gönderilen verinin `1101` olduğunu anlar.

**İstasyon tipleri:**

- **DAS (Dual Attachment Station):** İki ağ arayüzü ile iki halkaya bağlanır. Halkalar ters yönde döner. Performans ve güvenilirlik yüksektir ama her istasyona iki kart ve iki hat gerektiği için pahalıdır.
- **SAS (Single Attachment Station):** Tek arayüzü vardır. Çift halkaya bir yoğunlaştırıcı (concentrator) üzerinden bağlanır.
- **DAC / SAC:** Çift ve tek bağlı yoğunlaştırıcılar. SAS'ları halkaya bağlar.

### Kablosuz ve Kişisel Alan Ağları

- **802.11:** Kablosuz yerel ağ (Wi-Fi). Gelecek hafta ayrıntılı anlatılacak.
- **802.15:** Kişisel alan ağları (PAN). Bluetooth (akıllı saat, kulaklık, araç bağlantısı) ve ZigBee.
- **WiMAX (802.16):** Baz istasyonu gibi kilometrelerce yarıçapa geniş bant kablosuz erişim sağlamak için tasarlandı. Hoca 2007–2010 yıllarında büyük beklenti yarattığını, ama mobil ağların (4.5G, 5G) yaygınlaşmasıyla gündemden düştüğünü anlatıyor.

### Duyurular

- Proje grupları dört kişilik. Grup bildirmeyenler rastgele gruplanacak. Konular hocalar tarafından atanıp ders günü akşamı veya ertesi gün ilan edilecek.
- İkinci vize yapılmayacak. Projeden alınan not ikinci vize notu yerine geçecek.
- Slaytlar hocanın AVESİS sayfasında ve dersin Google Classroom'unda paylaşılıyor. Ödevler ve proje Classroom'dan toplanacak; sınıfa katılmanız isteniyor.
- Gelecek hafta 802.11 kablosuz yerel ağlar anlatılacak.

### Ders sonrası notlar

- **ALOHA'nın kurucusu:** Hoca ALOHA ağının 1973'te Bob Metcalfe öncülüğünde kurulduğunu söylüyor. ALOHAnet'i Hawaii Üniversitesi'nde Norman Abramson ve ekibi geliştirdi ve 1971'de çalışmaya başladı. Bob Metcalfe ise 1973'te Xerox PARC'ta ALOHA'dan esinlenerek Ethernet'i geliştirdi.
- **Slotlu ALOHA:** Hoca slotlu ALOHA'yı her istasyona saniye içinde sabit bir slot verilen bir düzen gibi anlatıyor; verimin saat kayması yüzünden %37'de kaldığını söylüyor. Her istasyona sabit slot vermek TDMA'dır. Slotlu ALOHA'da herhangi bir istasyon herhangi bir slotun başında gönderebilir. Aynı slotu seçen istasyonlar yine çarpışır. Verim artışının nedeni, savunmasız sürenin (vulnerable time) iki çerçeve süresinden bire inmesidir. %36,8 sınırı da saat kaymasından değil, bu olasılık hesabından gelir.
- **CSMA türleri:** Hoca "ısrarsız CSMA"yı "meşgulse sürekli dinle, boşalınca hemen gönder" diye anlatıyor. Bu tanım 1-ısrarcı CSMA'ya aittir. Israrsız CSMA'da hat meşgulse rastgele bir süre beklenir. Hocanın p-ısrarcı tanımı ("boşsa rastgele bekle") da tam doğru değildir. p-ısrarcı CSMA'da hat boşken $p$ olasılıkla hemen gönderilir.
- **Çarpışma algılama:** Hoca çarpışmayı ayrı bir anten algılıyormuş gibi ve istasyonun göndermeden önce kısa bir jam sinyali yolluyormuş gibi anlatıyor. Kablolu Ethernet'te gönderici aynı alıcı-verici (transceiver) ile hattaki sinyal seviyesini izleyerek çarpışmayı algılar. Jam sinyali yalnız çarpışma algılandıktan sonra gönderilir. Amacı hattı "temizlemek" değil, tüm istasyonların çarpışmayı fark etmesini sağlamaktır. Kablosuz ağlarda çarpışma algılanamadığı için CSMA/CA kullanılır.
- **Ethernet adresleri:** Hoca adres alanını "ne kadar bilgisayar varsa" diye anlatıyor. Hedef ve kaynak adresleri sabit 6 baytlık MAC adresleridir.
- **Otomatik anlaşma:** Auto-negotiation, iki ucun ortak hız ve çift yönlülük (duplex) modunda anlaşmasıdır; ACK alışverişi veya zaman ayarı değildir.
- **Gigabit kablo:** Hoca Gigabit Ethernet için CAT5'ten CAT8'e kablolar kullanıldığını söylüyor. 1000BASE-T için en az Cat5e önerilir. Cat6A, Cat8 gibi kablolar daha yüksek hızlar içindir.
- **Metro Ethernet:** Hoca Metro Ethernet'in hayata geçirilmemiş bir kavram olduğunu söylüyor; bir şirket kampüsü veya intranet örneği veriyor. Metro Ethernet, servis sağlayıcıların şehir ölçeğinde (MAN) sunduğu, bugün yaygın olarak kullanılan bir hizmettir. Bir şirketin kendi kampüs ağı bunun örneği değildir.
- **PoE gerilimi:** PoE, sinyallerin Fourier ile ayrıştırılmasıyla değil, kablodaki çiftler üzerinden doğru akım (DC) verilerek çalışır. Nominal gerilim yaklaşık 48 V'tur. 802.3af cihaz başına yaklaşık 15,4 W, 802.3at 30 W, 802.3bt 90 W'a kadar güç verir.
- **ZigBee:** Hoca ZigBee'nin Bluetooth'un özelleşmiş bir sürümü olduğunu söylüyor. ZigBee, IEEE 802.15.4 tabanlıdır. Bluetooth ise başlangıçta 802.15.1 olarak standartlaştırılmıştı. İkisi ayrı teknolojilerdir.
- **WiMAX:** WiMAX, IEEE 802.16 standardıdır; Wi-Fi değildir. Birçok ülkede uygulandı ama yerini LTE'ye bıraktı.
- **Token Bus'ta sıralama:** Hoca istasyonların fiziksel olarak sağındaki ve solundaki istasyonu tanıdığını söylüyor. Token Bus'ta sıra fiziksel konuma göre değil, adrese göre kurulan mantıksal halkaya göredir. Token adres sırasında bir sonraki istasyona geçer.
- **Token Ring öncelik seviyeleri:** 0, 2, 4, 6 öncelik sınıfları Token Bus'a aittir. Token Ring'de AC baytında 3 bitlik öncelik ve 3 bitlik rezervasyon alanı vardır; seviyeler 0–7'dir.
- **"Token resizing":** Hoca token'ın veri çerçevesine dönüştürülmesine "token resizing" diyor. Standartta bu işlem, AC baytındaki T (token) bitinin değiştirilmesiyle token'ın yakalanmasıdır (token capture).
- **FDDI halkaları:** Hoca iki halkadan birinin senkronizasyon, diğerinin veri için kullanıldığını söylüyor. Normal çalışmada veri birincil halkada akar. İkincil halka yedektir; bir kopukluk olunca halka ikincil üzerinden kapatılır.
- **FDDI senkron trafik:** Hoca senkron çerçevelerin kalan süreye sığmazsa token için yeniden "savaşa girildiğini" söylüyor. FDDI'da her istasyonun senkron trafik için önceden ayrılmış bir süresi vardır ve bu süre garanti edilir. Yalnız asenkron trafik, TTRT ile TRT arasındaki farka bağlıdır.
- **4B/5B kuralı ve örneği:** Hoca ikiden fazla ardışık 0'ın sorun olduğunu söylüyor. 4B/5B kodları en fazla bir baştaki ve iki sondaki 0 içerir. Bu yüzden kod akışında en fazla üç ardışık 0 oluşur; bu Python ile doğrulandı. Hocanın örneğindeki `0100` için kod `0101` değil, `01010`'dur.
- **DAC ve SAC:** Hoca C harfinin "converter" olabileceğini söylüyor. C, yoğunlaştırıcı (concentrator) anlamına gelir.
- **FDDI standardı:** Hoca FDDI'ı "ANSI–ITU standardı" diye anıyor. FDDI, ANSI X3T9.5 komitesinde geliştirildi ve sonradan ISO 9314 olarak standartlaştı.

**Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
