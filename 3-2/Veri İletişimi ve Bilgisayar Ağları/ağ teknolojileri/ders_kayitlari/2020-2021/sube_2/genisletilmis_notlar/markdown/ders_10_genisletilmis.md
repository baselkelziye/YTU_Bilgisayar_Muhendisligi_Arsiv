# Ders 10 Genişletilmiş Notu: Ağlar Arası Bağlantı (Internetworking)

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Neden Ağları Birleştiririz
- 2. Ağlar Nasıl Farklılaşır
- 3. Ağlar Nasıl Bağlanır
- 4. IP'nin Yeri ve IPv4/IPv6 Geçiş Sorunu
- 5. Tünelleme
- 6. Ağlar Arası Yönlendirme
- 7. Paket Parçalama
- 8. Path MTU Discovery
- 9. İnternette Ağ Katmanına Giriş ve Tasarım İlkeleri
- Örnek Sorular
- Dersin Toparlaması

## 1. Neden Ağları Birleştiririz

Bu derste ağ katmanının "internetworking" bölümü işlendi. Bölümün ilk slaytı internetworking'i şöyle tanımlar: birden çok farklı ağı tek bir büyük ağda birleştirmek (ekrandan, 00:05:00). Aynı slayt bölümün beş başlığını sıralar:

- How networks differ (ağlar nasıl farklılaşır)
- How networks can be connected (ağlar nasıl bağlanabilir)
- Tunneling (tünelleme)
- Internetwork routing (ağlar arası yönlendirme)
- Packet fragmentation (paket parçalama)

Hoca konuya neden ağları birleştirmek istediğimizle girdi. Bir ağın kendi içinde tutarlı olması ve cihazların birbiriyle haberleşmesi iyidir, ama şöyle bir ilke vardır: bir ağdaki cihaz sayısı arttıkça o ağın değeri de bununla orantılı olarak artar. İnternetten başka bir ağ deneyimi olmayan biri için bu çok sezgisel görünmeyebilir. Hoca bunu daha önce konuşulan overlay ağ kavramıyla bağladı: overlay ağda var olan bir ağın üstüne mantıksal düzeyde yeni bir ağ kurulur. Bunun bir örneği eşler arası (peer-to-peer) ağlardır; bir film ya da kitap arandığında, aranan dosya ne kadar çok kişide varsa o kadar hızlı indirilir. Yani orada bile beklenti şudur: ağ büyüdükçe faydası, dolayısıyla değeri artar.

Bu yüzden ağların diğer ağlarla birleşmesi gerekir ki daha çok yere ve kaynağa erişilebilsin. Bir apartmanın içindeki bilgisayarların bağlı olduğu bir ağla yapılabilecekler oldukça sınırlıdır; internete bağlanıldığı anda her şey başka bir düzeye çıkar. İnternette belli bir omurga (backbone) vardır, bu omurgaya ISP'ler ve diğer kurumlar bağlıdır. Bunların hepsi kendi içinde birbirinden farklı ağlardır ve bir şekilde bir araya getirilmeleri gerekir.

Hoca dersin planını şöyle çizdi: önce ağların birbirinden nasıl farklılaşabildiğine bakılır, sonra bu farkların nasıl giderileceği ya da farklara rağmen ağların nasıl birleştirileceği konuşulur. Bu birleştirmenin özel durumlarından biri, günümüzde pek çok sebeple kullanılan tünellemedir; VPN de tünellemenin bir türevidir. Bir diğer konu, kaynaktan çıkan paketin farklı ağlardan geçerek hedefe nasıl yönlendirileceğidir. Şimdiye kadar link state ve distance vector konuşulmuştu, ama bunlar hep tek bir ağın içinde çalışıyordu; paketin bulunduğu ağın dışına çıkması gerektiğinde işin nasıl yürüyeceği ayrı bir sorudur. Son olarak paket boyutu konusu vardır: her ağda fiziksel ve veri bağı katmanının kısıtları yüzünden en büyük iletim birimi (maximum transmission unit, MTU) farklı olabilir. Ethernet'te bu değer 1500 bayttır, Wi-Fi'de daha büyüktür. Bu yüzden bir Wi-Fi çerçevesi bir Ethernet ağına girdiğinde tek bir Ethernet çerçevesine sığmayabilir; bu durumda paketler parçalanır (fragmentation) ve bunun için iki temel yaklaşım vardır.

> **Ders sonrası not:** Hoca Wi-Fi çerçeve boyutunu önce "2230, 2250 ya da 2238" diye düşündüğünü, sonra "2200 küsur bayt" olduğunu söyledi ve kesin değeri hatırlayamadı. 802.11'in taşıyabildiği en büyük veri birimi (MSDU) büyük olasılıkla 2304 bayttır. Derste vurgulanan nokta değişmez: 802.11 çerçevesi Ethernet'in 1500 baytından büyüktür.

## 2. Ağlar Nasıl Farklılaşır

Slayt başlığı "farklar büyük olabilir ve internetworking'i zorlaştırır" der ve farklılaşma noktalarını bir tabloyla verir (ekrandan, 00:40:00):

| Öğe (Item) | Bazı olasılıklar (Some Possibilities) |
|---|---|
| Service offered | Connectionless versus connection oriented |
| Addressing | Different sizes, flat or hierarchical |
| Broadcasting | Present or absent (also multicast) |
| Packet size | Every network has its own maximum |
| Ordering | Ordered and unordered delivery |
| Quality of service | Present or absent; many different kinds |
| Reliability | Different levels of loss |
| Security | Privacy rules, encryption, etc. |
| Parameters | Different timeouts, flow specifications, etc. |
| Accounting | By connect time, packet, byte, or not at all |

Hoca önce bu tablonun dışında kalan farkları ayırdı. Ağlardan söz edildiğinde hep OSI katmanları üzerinden konuşulur, dolayısıyla işin içinde fiziksel ve veri bağı katmanları da vardır. Alt tarafta kullanılan modülasyonlar ve çerçeve yapıları farklı olabilir, ama bunlar fiziksel ve veri bağı katmanının sorunlarıdır; ağ katmanı konuşulurken bunlara fazla girilmez.

### 2.1 Hizmet türü ve sıralama

Örnek olarak bir tarafta WiMAX (802.16), diğer tarafta Ethernet olsun ve 802.16 ağından Ethernet'teki bir cihaz adreslenmeye çalışılsın. Önce adresleyip adresleyemeyeceğiniz bir sorudur. Diyelim ki adreslediniz. Ethernet'te bir bağlantı yapısı yoktur, Ethernet bağlantısızdır (connectionless). WiMAX ise bağlantı yönelimlidir (connection-oriented). Bağlantı yönelimli bir yerden bağlantısız bir yapıya geçildiğinde, paketlerin sıralı gitmesi gibi bağlantıya bağlı yapıların, kısacası bağlantı durumunun tamamı ortadan kalkar.

### 2.2 Paket boyutu

Daha önce de anıldığı gibi her ağın paket boyutu farklıdır. 8000 baytlık bir paketiniz varsa, MTU'su 1500 olan bir yerden bunu nasıl geçireceğiniz bir sorundur.

### 2.3 Yayın (broadcast) yapısı

İletişimin unicast, broadcast ya da multicast düzeyinde nasıl gerçekleştiği de farklılaşabilir. Bir ağ doğası gereği broadcast ile çalışırken diğeri noktadan noktaya bağlantılarla çalışıyor olabilir. Özellikle broadcast çalışan bir ağdan noktadan noktaya bir ağa geçerken fark ortaya çıkar.

### 2.4 Hizmet kalitesi

QoS ölçütlerine sıkı biçimde uyan bir ağdasınız, ama gitmeye çalıştığınız ağ best effort çalışıyor. Hocanın benzetmesiyle bu ağ "olursa olur, olmazsa çay demleriz" mantığıyla çalışır: elinden geleni yapar, olmadığında da olmaz. Bu iki ağı birleştirdiğinizde pek çok potansiyel sorun vardır.

### 2.5 Güvenlik

Haberleşmenin ne kadar güvenli olduğu da ağdan ağa değişir. Burada bir avantaj vardır: ağ güvenliği sağlamasa bile, haberleşmeyi yaptığınız üst düzeyde veriyi kapsülleyebilirsiniz. Örneğin şifreleme (encryption) kullanarak paketlerin belli bir gizliliğe (confidentiality) sahip olmasını sağlayabilirsiniz.

### 2.6 Ücretlendirme ve diğer parametreler

Başka parametreler de işin içindedir; bunlardan biri ücretlendirmedir (accounting). Hoca şu örneği verdi: iki telefon operatörü var ve her ikisinin ağındasınız. Biri kullanımınızı süre cinsinden ölçüp hesaplıyor, diğeri gönderdiğiniz bayt ya da ses verisi üzerinden. Bu iki ağ arasında geçiş yapılacaksa kimin kime neyi nasıl faturalayacağı da toparlanmalıdır.

Sonuç olarak kâğıt üzerinde iki ağı birbirine bağlamak için pek çok engel vardır; bunlar en azından düşünülmesi ya da çözülmesi gereken potansiyel sorunlardır.

## 3. Ağlar Nasıl Bağlanır

### 3.1 İki yaklaşım

Bu sorunlara rağmen birbirinden farklı iki ağı nasıl bağlarız? İlk akla gelen çözüm iki ağ arasında geçişi sağlayacak bir cihaz yapmaktır. WiMAX'tan Ethernet'e geçilecekse ikisi arasına bir geçiş cihazı konur; bu cihaz bir taraftan gelen istekleri ya da bağlantıları öbür tarafa aktarırken yapılması gereken her şeyi yapar, bağlantı yönelimli ve bağlantısız yapı arasındaki farkı da denetler ve düzeltir.

İkinci yol, işi bir üst düzeye taşımaktır: "Bunu bu düzeyde çözmeyeyim, bu işi yapabilecek yeni bir katman oluşturarak bir üst düzeyde çözeyim." Hoca bunun, işi başka yere ötelemek gibi görünse de aslında 1970'lerde iki araştırmacının önerdiği bir yöntem olduğunu söyledi; öneren kişilerden birinin adını Kahn olarak andı, diğerini hatırlayamadı ve bu kişilerin önerilerinden yaklaşık 30 yıl sonra Turing Ödülü aldıklarını ekledi. Fikir şudur: sorunu o katmanda çözmek zorunda değilsiniz, bir üst katmanda, bir soyutlama katmanıyla çözebilirsiniz. Teknik olarak uygulanması gereken ve bugün uygulanan çözüm budur.

> **Ek bilgi (derste anlatılmadı):** Bu yaklaşım büyük olasılıkla Vinton Cerf ve Robert Kahn'ın 1974'te yayımladıkları ve TCP/IP'nin temelini oluşturan çalışmadır. İkisi büyük olasılıkla 2004 yılında Turing Ödülü'nü almıştır.

### 3.2 Alt katman cihazlarının hatırlatılması

Hoca, Veri İletişimi dersinde konuşulmuş olan cihazları hatırlattı. Repeater ve hub, bir hattaki (kablolu ya da kablosuz) bilgiyi başka bir hat üzerinden aynen tekrar eden yapılardır. Bridge ve switch ise bağlantı (link) katmanında çalışan cihazlardır; aralarında küçük farklar olan ağları bağlamak için kullanılırlar. Örneğin 10 Mbit, 100 Mbit, 1 Gbit Ethernet'ler ya da switched Ethernet arasında geçişi bu cihazlar sorunsuzca sağlar.

Burada konuşulan durumda ise hangi yöntem seçilirse seçilsin, ister doğrudan bir geçiş cihazı yerleştirilsin ister iş bir üst katmana taşınsın, iki ağın arasına mutlaka fiziksel bir cihaz konması gerekir. Bu cihaza burada router denir.

### 3.3 Ortak ağ katmanı üzerinden bağlantı: 802.11, MPLS, Ethernet örneği

Slayt başlığı "Internetworking based on a common network layer – IP" der (ekrandan, 00:45:00). Şekil üç farklı ağın birbirine bağlanmasını gösterir:

```text
Source --[ 802.11 ]-- Router --[ MPLS ]-- Router --[ Ethernet ]-- Destination
                       ^ "Packet mapped to a VC here"
                       |<----- Virtual circuit ----->|
```

Kaynağın (source) bulunduğu sol tarafta bir 802.11 ağı vardır. 802.11 ağının ucundaki router ile diğer router arasında MPLS yazar. Hoca MPLS'in ayrıntısına sonra girileceğini, ama MPLS'in (multiprotocol label switching) bağlantı yönelimli bir yapı olduğunu ve içinde sanal devreler (virtual circuit) bulunduğunu söyledi. Hedefin (destination) bulunduğu sağ tarafta ise Ethernet vardır.

Kaynaktan hedefe varana kadar pek çok sorun vardır ve bunlar bir önceki tabloda konuşulanlardır:

- 802.11 bağlantısızdır, MPLS bağlantı yönelimlidir; bu geçişin yapılması gerekir. Ethernet yine bağlantısızdır; tekrar bir geçiş gerekir.
- 802.11'de kullanılan paket boyutu Ethernet'tekinden büyüktür. Ethernet'in en büyük çerçevesinden daha büyük bilgi içeren bir çerçeve gelirse bölünmesi, parçalanması gerekir.

Yapılan şey, daha önce söylenen yaklaşımdır: sorunu bir üst katmanda çözmek. Slaytın alt kısmındaki protokol yığını şeması bunu gösterir (ekrandan, 00:45:00):

```text
Kaynak            Router 1                  Router 2                 Hedef
  IP              IP (yukarı alınır)        IP (yukarı alınır)       IP
802.11|IP   ->   802.11|IP  ->  MPLS|IP  ->  MPLS|IP  ->  Eth|IP  ->  Eth|IP
        Physical
```

Slayttaki etiketler: "Data from Transport layer" (taşıma katmanından gelen veri) ve "Common protocol (IP) carried all the way" (ortak protokol IP baştan sona taşınır). Akış şöyledir:

1. Taşıma katmanından gelen veri bir IP paketine konur ve IP paketi önce 802.11 tarafından kapsüllenir.
2. İlk router 802.11 çerçevesindeki IP paketini çıkarır ve MPLS'in içine koyar. Router'ın bu noktada üst katmandaki asıl IP paketini alıp MPLS yapısına uygun biçimde kapsüllemesi ve aktarması gerekir; slayta göre paket burada bir sanal devreye eşlenir.
3. Paket öbür uçtaki router'a geldiğinde Ethernet çerçevesine sığacak biçimde parçalanır ve öyle devam eder.
4. Hedefte Ethernet çerçevesinden IP paketi çıkarılıp yukarı verilir.

## 4. IP'nin Yeri ve IPv4/IPv6 Geçiş Sorunu

IP bugün ağ katmanında fiilen tek protokol gibi görünür, ama başlangıçta böyle değildi. IPX, AppleTalk, SNA gibi başka protokoller de vardı. IP zamanla bunların hepsini saf dışı bıraktı; bunun temel nedeni internetworking konusunda sağladığı esnekliktir. Bu açıdan internetworking oldukça önemli bir noktadır.

Bugün yaşanan en büyük sıkıntılardan biri, hâlâ IPv4 ağlarla devam ediliyor olması ve IPv4'te adresleme konusunda ciddi bir sıkıntı bulunmasıdır. Hoca, IPv4'ten önce sürüm 1, 2 ve 3'ün de bulunduğunu ama bunların yaygın kullanılmadığını, IPv5'in de pek kullanılmadığını, IPv6'ya geçişin ise yirmi küsur yıldır bir türlü tamamlanamadığını söyledi.

Geçişin zorluğunun temel nedenlerinden biri, ikisi de IP olmasına rağmen IPv4 ve IPv6 arasında yaşanan sorundur. Internetworking'in temel sorunlarından biri adreslemeydi: IPv4 adreslerinin boyutu ile IPv6 adreslerinin boyutu aynı değildir. Bu yüzden IPv4 bir ağdan çıkıp bir IPv6 ağına ulaşmak için adresleme yapma şansı yoktur; protokolde ayrılmış öyle bir alan yoktur.

Kaynak ve hedef farklı yapılardaysa ve arada bambaşka ağlardan da geçilmesi gerekiyorsa, bu işi çözmeye çalışmak her geçiş noktasında ayrı bir ya da birden fazla sorunla uğraşmak demektir. IPv4 ile IPv6 örneğinde görüldüğü gibi, protokoller birbirine bu kadar yakın olsa, biri diğerinin sürümü olsa bile aralarında geçiş yapmak oldukça zordur.

## 5. Tünelleme

### 5.1 Tünellemenin gerektiği durum

Tünelleme şu ihtiyaçtan doğar: özel firmaların ya da kurumların farklı konumlarda, aynı mimariye sahip ağları vardır. Bunun en net örneklerinden biri ISP'lerdir; ya da bir firmanın farklı şehirlerdeki, aynı yapıdaki ağları düşünülebilir. Bu ağlar arasında bir bağlantı yapılması gerekir, ama aradaki geçişin ne olduğunu bilmezsiniz. Bir ağın bağlantısı genelde internete ya da doğrudan bir ISP'ye olur. Özel bir ağınız yoksa ve internet üzerinden bağlanıyorsanız, bu bağlantı bir ağ için DSL, bir başkası için kablo, bir başkası için uydu üzerinden olabilir ve bunlar birbirinden tamamen farklı yapılardır. Burada konuşulan durum, iç ağların benzer sistematiğe ve benzer özelliklere sahip olduğu durumdur.

### 5.2 Paris-Londra örneği

Slayt: "Connects two networks through a middle one; packets are encapsulates over the middle" (iki ağı ortadaki bir ağ üzerinden bağlar; paketler ortadaki ağ boyunca kapsüllenir) (ekrandan, 00:55:00). Şekil:

```text
Paris --[ IPv6 ]-- Router ====[ IPv4: Tunnel ]==== Router --[ IPv6 ]-- London

IPv6 packet  ->  [ IPv4 | IPv6 packet ]  ->  IPv6 packet
```

Örnekte Paris ve Londra'daki iki ofisin ikisi de IPv6 kullanır. IPv6 ile Paris'ten doğrudan Londra'ya gitme şansı yoktur, çünkü aradaki servis sağlayıcıların hiçbiri IPv6 çalıştırmaz. Bu durumda şu mantık kurulur: uç noktadan (Paris) doğrudan son noktayı (Londra) adreslemeye çalışılmaz. Onun yerine aradaki bütün geçişlerden yalıtılmayı sağlayan, bunlarla hiç uğraşmamayı sağlayan bir yapı oluşturulur; buna tünel denir.

Amaç, Paris'te çıkan IPv6 paketlerinin aradaki bir ya da birkaç ISP'nin farklı noktalardaki, farklı teknolojilerdeki ya da farklı ağ katmanlarına sahip cihazlarından geçerek son noktada Londra ofisinin router'ına gelmesi ve orada yeniden baştaki IPv6 paketi olarak kullanılabilmesidir. Yapılan şey IPv6 paketini bir IPv4 paketinin içine kapsüllemektir. Bu sırada IPv6 paketinin ne hedef adresi ne de başlığı değiştirilir. Paketin hedef adresinden, içteki router paketin Londra tarafına gittiğini anlar ve onu Londra router'ına giden bir IPv4 paketine koyar. Londra'daki router bu IPv4 paketini aldığında açar ve içindeki IPv6 paketini ortaya çıkarır. Bu, bir anlamda daha önce konuşulan overlay yapısına benzer.

IPv6'yı IPv4 üzerinden taşımak zorunlu değildir; ters yönde işler de yapılabilir.

### 5.3 VPN ve tünelleme

Tünelleme farklı bir biçimde de kullanılabilir. Hoca dersin başında da söylediği gibi, bazen kısıtları aşmak, normalde erişilemeyen yerlere erişmek için tünelleme kullanıldığını anlattı: kendinizi örneğin Londra'daki bir bilgisayara bağlarsınız ve onun üzerinden dışarı çıkarsınız. Bu kapsülleme yapılırken siz yine bir IPv4 paketi üretirsiniz, bu paket başka bir IPv4 paketinin içine kapsüllenip gönderilir. Bunun üstüne şifreleme de eklenirse iletişim iyice güvenli hale gelir. Bu yapıyı (VPN) günümüzde şirketler yaygın olarak kullanır.

Hoca tünellemeyi Manş Denizi altındaki tünele benzetti: bir taraftan çıkarılan paketler bütün yolu geçip öbür taraftan çıkar.

## 6. Ağlar Arası Yönlendirme

Hoca bu kısım için slaytlar arasında ayrı bir şekil olmadığını ama konunun konuşulması gerektiğini söyledi.

### 6.1 Sorun

Kaynakta oluşturulan paketin farklı ağların içinden geçerek hedefe varması beklenir. Bu yüzden paketin geçtiği her ağın içinde yönlendirilmesi gerekir. Ancak bu ağların her biri farklı bir yönlendirme algoritması kullanıyor olabilir: biri link state, diğeri distance vector kullanabilir. Bu durumda ağlar arasındaki geçişin nasıl sağlanacağı, hangi bağlantının ve hangi yolun izleneceğine nasıl karar verileceği bir soru işaretidir.

Bir diğer nokta yönlendirme ölçütüdür. Distance vector de olsa link state de olsa en kısa yol (shortest path) kullanılır, ama yolun "kısa" olması fiziksel olarak kısa olması demek değildir. Yönlendirme kararı bir ölçüte göre verilir: bu maliyet, hız, bant genişliği ya da gecikme olabilir. Dolayısıyla geçilen her ağda yönlendirme ölçütleri birbirinden farklı olabilir.

Ayrıca geçilen her ağ farklı bir operatör tarafından işletilir. Hoca bunu cep telefonundan internete çıkma örneğiyle anlattı: siz bir operatörü kullanıyorsunuz, bağlanacağınız kişi başka bir operatöre bağlı ve oraya gitmek için üçüncü bir operatörün ağından geçmeniz gerekebiliyor. Hoca örneği uydurduğunu, gerçekte bazı operatörlerin altyapısını başka bir operatörün sağladığını da ekledi. Böyle bir durumda operatörlerin birbirine söylemek ya da göstermek istemediği ölçütler ve bilgiler olabilir: sekme (hop) sayısı, gecikme, bant genişliği gibi. Bu ve benzeri kısıtlar yüzünden kaynaktan hedefe kadar işi tek bir yönlendirme algoritmasıyla yürütmek mümkün değildir.

### 6.2 İki düzeyli yönlendirme

Çözüm, yönlendirmeyi iki düzeye ayırmaktır. Hoca ilk anlatımda terimleri karıştırdığını fark edip düzeltti; doğru eşleme şudur:

- **Intra-domain yönlendirme = interior gateway protocol (IGP):** her ağın kendi içinde bir yönlendirme algoritması vardır. Her ağ kendi içinde istediği yönlendirmeyi kullanmakta serbesttir.
- **Inter-domain yönlendirme = exterior gateway protocol (EGP):** internet gibi birden çok ağı birbirine bağlayan bir yapıda, ağlar arasındaki geçişi sağlamak için kullanılır. Genel bütünlüğü sağlayabilmek için inter-domain protokolün ortak olması gerekir.

Bugün bildiğimiz internette inter-domain için BGP (Border Gateway Protocol) kullanılır; hoca bunun bir sonraki derste, internetteki ağ katmanı IP paketinden başlanarak adım adım konuşulurken ele alınacağını söyledi.

Hoca bir terimi de ekledi: internet, birden fazla ağın birbirine bağlanmasıdır ve bu ağların her birine **autonomous system** (otonom sistem) denir. Bu terim çeşitli yerlerde karşınıza çıkar.

## 7. Paket Parçalama

### 7.1 Neden parçalama gerekir

Paketler kaynaktan çıktıktan sonra, kendi ağlarındaki çerçeve boyutundan daha küçük bir çerçeve boyutuna sahip bir ağa gelebilir. Bu durumda tek bir çerçeveye sığamayacakları için parçalanmaları gerekir. Bunun nedeni kullanılan protokol ya da fiziksel katmandaki kısıtlar olabilir; buna müdahale edilemez, orada farklı bir ağ ve farklı bir paket boyutu vardır ve buna uygun davranılmalıdır. En basit örnek baştaki örnektir: Ethernet'in çerçeve boyutu 1500 bayt, 802.11'inki 2200 küsur bayttır. Bu yüzden bir 802.11 paketi Ethernet ağından geçerken parçalanabilir.

Hoca ayrıca IP başlığına bakılacağını ve IP paketlerinin 65515 bayta kadar büyüyebildiğini söyledi.

> **Ders sonrası not:** Hoca IP paketinin 65515 bayta kadar büyüyebildiğini söyledi. IPv4 başlığındaki Total Length alanı 16 bit olduğu için paketin toplam boyu en fazla $2^{16}-1 = 65535$ bayttır. 65515 değeri, 20 baytlık en küçük başlık çıkarıldığında kalan en büyük veri miktarıdır ($65535 - 20 = 65515$).

Bir paket, boyutu taşınmasına uygun olmayan bir ağa girdiğinde birkaç strateji uygulanabilir. Slayt: "Networks have different packet size limits for many reasons; large packets sent with fragmentation & reassembly" (ağların paket boyutu sınırları birçok nedenle farklıdır; büyük paketler parçalanıp yeniden birleştirilerek gönderilir) (ekrandan, 01:00:00).

### 7.2 Saydam (transparent) parçalama

Slaytın üst şekli (ekrandan, 01:00:00):

```text
Packet -> [ Network 1:  G1 --(parçalar)--> G2 ] -> Packet -> [ Network 2:  G3 --(parçalar)--> G4 ] -> Packet
          G1 fragments      G2 reassembles                  G3 fragments      G4 reassembles
Transparent – packets fragmented / reassembled in each network
```

Paket Network 1'e girdiğinde giriş geçidi G1 (gateway 1) tarafından parçalanır, çıkış geçidi G2 tarafından yeniden birleştirilir. Küçük parçalar ağdan çıkmadan tekrar birleştirilir ve tek paket olarak, asıl paket olarak bir sonraki ağa aktarılır. Parçalamanın gerektiği her ağda (şekilde Network 2'de G3 ve G4) bu yeniden yapılır.

### 7.3 Saydam olmayan (non-transparent) parçalama

Slaytın alt şekli (ekrandan, 01:00:00):

```text
Packet -> [ Network 1:  G1 --(parçalar)--> G2 ] -> parçalar -> [ Network 2:  G3 --> G4 ] -> parçalar ... hedef birleştirir
          G1 fragments
Non-transparent – fragments are reassembled at destination
```

Bu yöntemde paket parçalandıktan sonra hayatına parçalar halinde devam eder. Paket birinci ağa gelir, G1 boyut yetmediği için paketi parçalara ayırmak zorunda kalır. Parçalar bu ağdan çıkarken birleştirilmez, aynı parçalar halinde yoluna devam eder. Bu parçalar başka bir ağa geldiğinde tekrar parçalanıp daha da küçülebilir. Birleştirme yalnız hedefe varıldığında yapılır. Yani üstteki yöntemde her ağın giriş ve çıkışında yapılan parçalama ve birleştirme, alttaki yöntemde yalnız hedefte yapılır.

### 7.4 İki yöntemin karşılaştırılması

İki yöntemin de artıları ve eksileri vardır.

Saydam yöntemde G1 parçalamayı yaptığında G2'nin paketi yeniden oluşturması gerekir. Bu, G2'nin parçaları sürekli takip etmesi demektir: G1 paketi örneğin şekildeki gibi yedi parçaya bölüp ağa saldıysa, gelen parçaların tamponlanması, diğer parçaların takip edilmesi ve onlar için hazırlık yapılması gerekir. Ağa giren bütün paketlerde böyle bir parçalama olursa geçitlere ek yük biner.

Bunun yanında gözden kaçan bir sorun daha vardır. Genelde, belki de evdeki ya da günlük hayatta kullanılan ağların küçük olmasından dolayı, bir ağın bir giriş ve bir çıkış geçidi varmış gibi düşünülür. Ama böyle olmak zorunda değildir. Saydam parçalama yapıldığı andan itibaren bütün parçaların, bütün küçük paketlerin aynı rotadan gitme zorunluluğu da konmuş olur: G1'in parçaladıkları G2'de birleştirilecekse, asıl paket G1'den G2'ye geçmek zorundadır ve ağın başka bir çıkışından geçip başka bir yere gidemez. Bu, rota seçimini epey kısıtlar.

Saydam olmayan yöntemin en önemli artısı, aradaki birleştirme noktalarından ve bu rota kısıtından kurtulmaktır. IP de bu yöntemi kullanır: IP paketlerinde "do not fragment" ve "more fragments" bitleri ile bir offset alanı vardır. Bir paket bölüneceği zaman bu alanlar uygun şekilde doldurulup gönderilir ve parçalar uç noktada birleştirilir.

> **Hocanın vurgusu:** IP başlığındaki "do not fragment" ve "more fragments" bitleri ile offset alanı, hocanın belirttiğine göre derste ve sınavlarda zaman zaman sorulan bir konudur.

Ancak her iki yöntemin de ortak bir sakıncası vardır: saydam da olsa saydam olmasa da her parçalamada her parçaya ek bir başlık alanı eklenir. Göndermek istenen bilgi için gerçekte gönderilmesi gereken toplam veri artar, dolayısıyla verim (utilization) düşer.

## 8. Path MTU Discovery

Hoca, hizmet kalitesi konusundaki mantığı hatırlattı: parçalamadan kaçınmanın çözümü, QoS'teki gibi düşünülürse, parçalanmaya hiç izin vermemektir. QoS'te "parayı bastırıp en son teknolojiye çıkarız, her şeyi artırırız" deniyordu; burada daha makul bir yaklaşım izlenir.

Kaynaktan hedefe giden ve farklı ağlardan geçen bir yol vardır ve her ağın MTU'su farklı olabilir. Amaç şudur: bu yol üzerinde parçalanmaya uğramadan gönderilebilecek en büyük MTU nedir? Yani bir yol keşfi (path discovery) yapılır. Belirlenen MTU, uçtan uca kat edilecek yolun tamamında parçalanma olmadan paket göndermeyi sağlayacak değerdir.

Çalışma biçimi şöyledir:

1. Kaynak, parçalanmasına izin verilmeyecek şekilde bir paket oluşturur.
2. Paket, geçtiği router'lardan birinde o boyut kabul edilmiyorsa düşürülür (drop).
3. Router kaynağa bir hata ya da uyarı mesajı döndürür.
4. Kaynak paket boyutunu buna göre ayarlar ve yeniden gönderir.

Derste anlatılan örnek (derste sözlü, 01:15:22): kaynak 1400 baytlık paketle başlar. İlk router 1200'ün üstüne çıkamayacağını söyleyip paketi düşürür ve kaynağı uyarır. Kaynak 1200 baytlık yeni bir paket oluşturur. Bu sefer ikinci router 900'den büyüğünü iletemeyeceğini söyler. Kaynak paket boyutunu 900'e indirir ve öyle gönderir.

<!-- BELİRSİZ: path MTU discovery slaytı (yaklaşık 01:15:20) kareler arasında yok; 1400, 1200 ve 900 değerleri yalnız altyazıdan alındı. -->

Bu yapı yalnız ilk keşif sırasında biraz gecikme yaratır, ama toplamda parçalanmadan kaçınmayı sağlar.

> **Ek bilgi (derste anlatılmadı):** IPv4'te bu mekanizma büyük olasılıkla başlıktaki DF ("don't fragment") biti ile çalışır; paketi taşıyamayan router kaynağa büyük olasılıkla bir ICMP "fragmentation needed" (Destination Unreachable) mesajı döndürür ve bu mesajda kendi bağlantısının MTU değerini bildirir.

## 9. İnternette Ağ Katmanına Giriş ve Tasarım İlkeleri

### 9.1 Sonraki konular

Ardından internetin ağ katmanına geçildi ve hoca kısa bir giriş yaptı. Slayttaki konu listesi (ekrandan, 01:20:00):

- IP Version 4
- IP Addresses
- IP Version 6
- Internet Control Protocols
- Label Switching and MPLS
- OSPF — An Interior Gateway Routing Protocol
- BGP — The Exterior Gateway Routing Protocol
- Internet Multicasting (slaytta soluk)
- Mobile IP (slaytta soluk)

Hoca, IPv4 ile başlanacağını; IP adreslerinin, IPv6'nın, IP ile ilgili ek kontrol protokollerinin, label switching'in ve internetworking kısmında anılan, her ağın kendi içinde kullandığı interior gateway ve ağlar arasında kullanılan exterior gateway yönlendirme protokollerinin konuşulacağını söyledi.

### 9.2 RFC 1958 ve tasarım ilkeleri

Hoca, her şeyden önce internetin tasarım ve gerçeklenme stratejisinin konuşulması gerektiğini söyledi ve bunun için RFC 1958'i okumayı tavsiye etti. Bu belgede bir protokol ortaya atılırken sahip olması gereken özellikler, yani tasarım ölçütleri anlatılır. Derste anılan ilkeler:

- **Çalıştığından emin ol:** tam çalışmayan, test edilip onaylanmamış şeyleri kesinleştirme.
- **Basit tut:** hoca bunu Occam'ın usturası (Occam's Razor) ilkesiyle bağladı ve ilkenin 14-15. yüzyıldan kaldığını söyledi. İlkeye göre elinizde birden fazla yöntem ya da açıklama varsa basit olanı doğrudur ya da geçerlidir. Protokol tasarlarken de "onu da birleştireyim, şunu da ekleyeyim" diye uğraşmak yerine, var olan özelliklerin birkaçının birleştirilmesiyle elde edilebilecek bir özelliği ayrıca yapmanın anlamı yoktur.
- **Net seçim yap:** yapılan işin temiz olması; aynı işi yapmak için birden fazla yöntemin bulunması, hocanın deyişiyle belaya davetiye çıkarmaktır.
- **Modülerlik:** katmanlar olmalı ve katmanların birbirine verdiği ve birbirinden aldığı servisler çok net tanımlanmalıdır; böylece bir katman çıkarılıp yerine başka bir katman konabilir. Hoca, TCP/IP'nin yeterince ya da gereğinden fazla modüler olup olmadığının tartışmalı olduğunu söyledi; örneğin ICMP'nin hangi katmanda olduğuna zaman zaman cevap verilemez. Yani bugün kullanılan sistemlerde de bu ilkeler yüzde yüz geçerli değildir.
- **Heterojenliği bekle:** herkesin her yerde tek tip olmasını bekleyemezsiniz; farklı donanımlar, farklı iletim teknikleri ve farklı uygulamalar olacaktır ve tasarım bunlara cevap verebilmelidir.
- **Ölçeklenebilir ol.**
- **Gönderirken sıkı, alırken toleranslı ol:** her zaman kurala uygun göndermelisiniz, ama alırken çok farklı şeylerle karşılaşabilirsiniz. Alınan bilginin kurala uygun olacağını düşünmek büyük hatadır.

Son ilke için hoca bir akıllı ev uygulaması örneği anlattı. Sistemde REST API üzerinden istekleri alan bir ağ geçidi vardı; geçit istekleri işleyip üstteki merkezi veritabanına yerleştiriyordu. Sistem sürekli çöküyordu ve nedeni bulunamıyordu. İnceleme sonunda, geçidi yazan kişinin gelen isteklerdeki parametrelerin her durumda doğru olacağını varsaydığı ve hiçbirini denetlemediği ortaya çıktı; en küçük yanlış ya da beklenmedik parametre sistemin çökmesine yol açıyordu. Kural şudur: bir ağ oluşturuyorsanız her zaman düzgün gönderin, ama size her zaman düzgün geleceğini beklemeyin. Neden bir hata, bir sürüm farkı ya da kötü niyet olabilir.

Hoca bunların temel on tasarım ölçütü olduğunu ve RFC 1958'de ayrıntılarının görülebileceğini söyledi; fikir vermesi için okunmasını önerdi.

> **Ek bilgi (derste anlatılmadı):** RFC 1958 büyük olasılıkla 1996 tarihli "Architectural Principles of the Internet" belgesidir. Ders kitabında (Tanenbaum ve Wetherall) bu belgeden ve başka kaynaklardan derlenen on ilke büyük olasılıkla şöyle sıralanır: çalıştığından emin ol; basit tut; net seçim yap; modülerlikten yararlan; heterojenliği bekle; statik seçenek ve parametrelerden kaçın; iyi bir tasarım ara, mükemmel olması gerekmez; gönderirken sıkı, alırken toleranslı ol; ölçeklenebilirliği düşün; performansı ve maliyeti göz önüne al.

## Örnek Sorular

**Soru 1** (derste sözlü, 00:31:59): Ağlar birbirinden ne şekilde farklılaşabilir? Bir ağı diğerinden hangi özellikler farklı kılar?

> **Cevap (derste verildi):** Slayttaki tabloya göre (ekrandan, 00:40:00): sunulan hizmet (bağlantısız ya da bağlantı yönelimli), adresleme (farklı boyutlar, düz ya da hiyerarşik), yayın (var ya da yok, multicast dahil), paket boyutu (her ağın kendi en büyüğü), sıralama (sıralı ya da sırasız teslim), hizmet kalitesi (var ya da yok, pek çok türü), güvenilirlik (farklı kayıp düzeyleri), güvenlik (gizlilik kuralları, şifreleme), parametreler (farklı zaman aşımları, akış tanımları) ve ücretlendirme (bağlantı süresi, paket, bayt ya da hiç). Modülasyon ve çerçeve yapısı farkları da vardır, ama bunlar fiziksel ve veri bağı katmanının sorunlarıdır.

**Soru 2** (derste sözlü, 00:37:49): 8000 baytlık bir paketi MTU'su 1500 bayt olan bir ağdan nasıl geçirirsiniz?

> **Cevap (derste verildi):** Paket tek bir çerçeveye sığmadığı için parçalanmalıdır (fragmentation); parçalama saydam (her ağda parçala-birleştir) ya da saydam olmayan (birleştirme hedefte) biçimde yapılabilir. Parçalamadan tamamen kaçınmak için path MTU discovery kullanılır.

> **Çözüm (derste verilmedi):** Sayısal döküm için şu varsayımlar yapılmıştır: 8000 bayt, 20 baytlık başlık dahil bir IPv4 datagramının toplam boyudur ve parçalar da 20 baytlık başlık taşır. Veri $8000 - 20 = 7980$ bayttır. Bir parçaya en fazla $1500 - 20 = 1480$ bayt veri sığar; bu değer 8'in katıdır ($1480/8 = 185$), offset 8 baytlık birimlerle tutulduğu için uygundur. $\lceil 7980/1480 \rceil = 6$ parça çıkar: beş parça 1480 bayt veri (toplam 1500 bayt), son parça $7980 - 5 \cdot 1480 = 580$ bayt veri (toplam 600 bayt) taşır. Offset değerleri sırasıyla 0, 185, 370, 555, 740, 925'tir; ilk beş parçada "more fragments" biti 1, sonuncusunda 0'dır. (Python ile doğrulandı.)

**Soru 3** (derste sözlü, 00:50:05): IPv4 ve IPv6 ikisi de IP olduğu halde, bu iki ağ arasında geçişte nasıl bir sıkıntı yaşanır?

> **Cevap (derste verildi):** Adres boyutları farklıdır. IPv4 bir ağdan çıkan paket, IPv6 bir hedefi adresleyemez; IPv4 başlığında IPv6 adresini koyacak bir alan yoktur. Aynı ağ türündeki iki uç arada farklı bir ağla ayrılıyorsa çözüm tünellemedir: örneğin IPv6 paketi IPv4 paketine kapsüllenerek aradaki IPv4 ağından geçirilir.

**Soru 4** (derste sözlü, 01:15:22): Path MTU discovery ile kaynak 1400 baytlık paketle başlıyor; yol üzerindeki ilk router en fazla 1200, ikinci router en fazla 900 baytlık paket iletebiliyor. Süreç nasıl işler ve kaynak sonunda hangi boyutu kullanır?

> **Cevap (derste verildi):** Kaynak parçalanmaya izin verilmeyen 1400 baytlık paket gönderir; ilk router paketi düşürür ve kaynağa 1200 sınırını bildirir. Kaynak 1200 baytlık paket gönderir; bu kez ikinci router paketi düşürür ve 900 sınırını bildirir. Kaynak 900 baytlık paketlerle gönderir. Yalnız ilk keşifte gecikme olur, sonra parçalama gerekmez.

## Dersin Toparlaması

Bu derste farklı ağların tek bir büyük ağda birleştirilmesi işlendi. Ağların hizmet türü, adresleme, yayın, paket boyutu, sıralama, hizmet kalitesi, güvenilirlik, güvenlik, parametreler ve ücretlendirme bakımından farklılaşabildiği ve bu farkların her birinin birleştirmeyi zorlaştırdığı görüldü. Bu farklar ya her geçişte çeviri yapan bir cihazla ya da bir üst katmanda ortak bir soyutlamayla aşılabilir; bugün kullanılan çözüm ortak ağ katmanı IP'dir ve router'lar her ağın çerçevesinden IP paketini çıkarıp bir sonrakinin çerçevesine koyar. Aynı türdeki iki ağı farklı bir ağ ayırıyorsa tünelleme kullanılır (IPv6 paketinin IPv4 içinde taşınması; VPN). Ağlar arası yönlendirme iki düzeylidir: her ağın kendi interior gateway protokolü ve ağlar arasında ortak exterior gateway protokolü (internette BGP); internetteki her ağ bir autonomous system'dır. Paket parçalama saydam ya da saydam olmayan biçimde yapılabilir; IP saydam olmayan yöntemi kullanır, ama en iyisi path MTU discovery ile parçalamadan hiç kaçınmaktır.

Dersin sonunda internetin ağ katmanına giriş yapıldı ve RFC 1958'deki tasarım ilkeleri (çalışsın, basit olsun, net seçim, modülerlik, heterojenlik, ölçeklenebilirlik, gönderirken sıkı alırken toleranslı olmak) konuşuldu. Bir sonraki derste IPv4 ile başlanarak internetteki ağ katmanı IP paketinden itibaren adım adım ele alınacak; BGP de bu kapsamda konuşulacak.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
