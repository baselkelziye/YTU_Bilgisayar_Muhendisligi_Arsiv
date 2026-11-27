# Ders 10 Çalışma Özeti

## Genel Konular

- Ağlar arası bağlantı (internetworking) kavramı
  - Slayttaki tanım: internetworking, birden çok farklı ağı tek bir büyük ağda birleştirir (ekrandan, 00:05:00).
  - Bölümün başlıkları: ağlar nasıl farklılaşır, ağlar nasıl bağlanır, tünelleme, ağlar arası yönlendirme, paket parçalama (ekrandan, 00:05:00).
  - Bir ağa bağlı cihaz sayısı arttıkça ağın değeri de artar. Örnek: eşler arası (peer-to-peer) dosya paylaşımında aranan dosya ne kadar çok kişide varsa o kadar hızlı indirilir.
  - Bir apartman içindeki yerel ağla yapılabilecekler sınırlıdır; internete bağlanınca erişilebilen kaynaklar katlanır. İnternet, bir omurgaya (backbone) bağlı ISP'ler ve kurumlardan oluşur ve bunların hepsi birbirinden farklı ağlardır.
  - Daha önce konuşulan overlay ağ fikri hatırlatıldı: var olan bir ağın üzerinde mantıksal düzeyde yeni bir ağ kurmak.
- Ağlar nasıl farklılaşır (ekrandan, 00:40:00)
  - Slayt başlığı: farklar büyük olabilir ve internetworking'i zorlaştırır.
  - Slayttaki tablo:

    | Öğe | Bazı olasılıklar |
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

  - Modülasyon ve çerçeve yapısı farkları fiziksel ve veri bağı katmanlarının sorunudur; ağ katmanında bunlara girilmez.
  - Hizmet türü: WiMAX (802.16) bağlantı yönelimli, Ethernet bağlantısızdır. Bağlantı yönelimli bir ağdan bağlantısız bir ağa geçince sıralı teslim gibi bağlantıya bağlı özellikler ortadan kalkar.
  - Paket boyutu: her ağın bir en büyük iletim birimi (MTU) vardır; Ethernet'te 1500 bayttır, Wi-Fi'de daha büyüktür. 8000 baytlık bir paketin MTU'su 1500 olan bir ağdan nasıl geçirileceği bir sorundur.
  - Yayın: bir ağ doğası gereği broadcast ile, diğeri noktadan noktaya bağlantılarla çalışabilir.
  - Hizmet kalitesi: QoS ölçütlerine sıkı uyan bir ağ ile "elinden geleni yapan" (best effort) bir ağı birleştirmek sorun doğurur.
  - Güvenlik: alttaki ağ sağlamasa bile haberleşme üst düzeyde kapsüllenip şifrelenerek gizlilik (confidentiality) sağlanabilir.
  - Ücretlendirme (accounting): biri süreye, diğeri gönderilen bayta göre ücretlendiren iki operatör arasında kimin kime nasıl fatura keseceği çözülmelidir.
- Ağlar nasıl bağlanır (ekrandan, 00:45:00)
  - Yol 1: iki ağ arasında, iki tarafı da bilen ve gereken her dönüşümü (örneğin bağlantı yönelimli ile bağlantısız arasında) yapan bir geçiş cihazı kurmak.
  - Yol 2: sorunu bir üst katmanda, ortak bir soyutlama katmanıyla çözmek. Bu, 1970'lerde iki araştırmacının önerdiği ve bugün uygulanan çözümdür.
  - Repeater ve hub bir hattaki sinyali aynen tekrarlar; bridge ve switch bağlantı (link) katmanında çalışır ve küçük farkları olan ağları (10 Mbit, 100 Mbit, 1 Gbit Ethernet) bağlar.
  - Hangi yol seçilirse seçilsin iki ağ arasına fiziksel bir cihaz konur; burada bu cihaza router denir.
  - Slayt: "Internetworking based on a common network layer – IP". Şekilde kaynak 802.11 ağında, ortada MPLS ağı, hedef Ethernet ağındadır; iki router vardır. Paket ilk router'da bir sanal devreye (VC) eşlenir; ortak protokol (IP) baştan sona taşınır.
  - Protokol yığını: kaynakta IP paketi 802.11 çerçevesine konur; ilk router 802.11 çerçevesinden IP paketini çıkarıp MPLS içine koyar; ikinci router MPLS'ten çıkarıp Ethernet çerçevesine koyar; hedefte Ethernet çerçevesinden IP çıkar.
  - Sorunlar: 802.11 bağlantısız, MPLS bağlantı yönelimli, Ethernet yine bağlantısızdır; 802.11 çerçevesi Ethernet'ten büyük olduğundan Ethernet tarafında parçalama gerekebilir.
- IP'nin yeri ve IPv4/IPv6 sorunu
  - Ağ katmanında eskiden IPX, AppleTalk, SNA gibi protokoller de vardı; IP, internetworking'e sağladığı esneklik sayesinde bunları saf dışı bıraktı.
  - IPv4'te adres sıkıntısı vardır; IPv6'ya geçiş yıllardır tamamlanamamaktadır.
  - IPv4 ve IPv6 adres boyutları farklıdır; IPv4 başlığında IPv6 adresini koyacak alan yoktur. Aynı protokolün iki sürümü arasında bile geçiş zordur.
- Tünelleme (ekrandan, 00:55:00)
  - Slayt: iki ağı ortadaki bir ağ üzerinden bağlar; paketler ortadaki ağ boyunca kapsüllenir.
  - Örnek: Paris ve Londra ofisleri IPv6 kullanır, aradaki servis sağlayıcılar yalnız IPv4 çalıştırır. Paris tarafındaki router IPv6 paketine dokunmadan onu bir IPv4 paketinin içine koyar; Londra router'ı IPv4 paketini açıp içindeki IPv6 paketini çıkarır.
  - Şekildeki akış: IPv6 packet → [IPv4 | IPv6 packet] (tünel) → IPv6 packet.
  - Ters yönde de kullanılabilir. Tünelleme overlay yapısına benzer.
  - VPN tünellemenin bir türevidir: IPv4 paketi başka bir IPv4 paketinin içine konup uzak bir noktadan dışarı çıkılır; üstüne şifreleme eklenince haberleşme güvenli olur. Şirketler bunu yaygın kullanır.
  - Benzetme: Manş Denizi altındaki tünel; bir uçtan giren araç yolun tamamını geçip öbür uçtan çıkar.
- Ağlar arası yönlendirme
  - Her ağ farklı bir yönlendirme algoritması (link state ya da distance vector) ve farklı bir ölçüt (maliyet, hız, bant genişliği, gecikme) kullanabilir.
  - Ağları farklı operatörler işletir; operatörler sekme sayısı, gecikme, bant genişliği gibi bilgileri birbirine göstermek istemeyebilir. Bu yüzden kaynaktan hedefe tek bir yönlendirme algoritması kullanılamaz.
  - Çözüm iki düzeyli yönlendirmedir: her ağın içinde intra-domain yönlendirme (interior gateway protocol), ağlar arasında inter-domain yönlendirme (exterior gateway protocol).
  - Her ağ kendi içinde istediği protokolü seçebilir; inter-domain protokol ortak olmalıdır. İnternette bu BGP'dir (Border Gateway Protocol).
  - İnternetteki her bir ağa autonomous system (AS) denir.
- Paket parçalama (ekrandan, 01:00:00)
  - Paket, kendi ağının çerçeve boyutundan daha küçük çerçeve boyutlu bir ağa gelirse parçalanmalıdır. Neden protokol ya da fiziksel kısıt olabilir.
  - Hoca IP paketlerinin 65515 bayta kadar büyüyebildiğini söyledi (bkz. ders sonrası not).
  - Saydam (transparent) parçalama: her ağın giriş geçidi (G1) paketi parçalar, çıkış geçidi (G2) yeniden birleştirir; paket bir sonraki ağa bütün olarak geçer.
  - Saydam olmayan (non-transparent) parçalama: parçalar yollarına parça olarak devam eder, başka ağlarda daha da bölünebilir; birleştirme yalnız hedefte yapılır.
  - Saydam yöntemin sakıncaları: çıkış geçidi parçaları tamponlamalı ve takip etmelidir, geçitlere ek yük biner; bütün parçalar aynı çıkış geçidinden geçmek zorundadır, bu da rota seçimini kısıtlar.
  - Saydam olmayan yöntemin artısı ara birleştirme noktalarından ve rota kısıtından kurtulmaktır. IP bunu kullanır: başlıkta "do not fragment" ve "more fragments" bitleri ile offset alanı vardır; parçalar uç noktada birleştirilir.
  - İki yöntemin ortak sakıncası: her parçaya ek başlık eklenir, gönderilen toplam veri artar, verim (utilization) düşer.
- Path MTU discovery
  - Parçalamadan kaçınmanın yolu, parçalamaya hiç gerek bırakmamaktır: uçtan uca yol üzerinde parçalanmadan gönderilebilecek en büyük MTU bulunur.
  - Kaynak parçalanmaya izin vermeyen bir paket gönderir; paketi taşıyamayan router paketi düşürür ve kaynağa bir hata/uyarı mesajı döndürür; kaynak paket boyutunu ona göre küçültür.
  - Derste sözlü anlatılan örnek: kaynak 1400 baytla başlar, ilk router en fazla 1200 diyerek paketi düşürür; kaynak 1200 ile yeniden dener, ikinci router en fazla 900 der; kaynak 900 baytla gönderir.
  - Yalnız ilk keşifte biraz gecikme yaratır, sonrasında parçalamayı önler.
- İnternette ağ katmanı ve tasarım ilkeleri (ekrandan, 01:20:00)
  - Sonraki konuların listesi: IP Version 4, IP Addresses, IP Version 6, Internet Control Protocols, Label Switching and MPLS, OSPF (interior gateway routing protocol), BGP (exterior gateway routing protocol), Internet Multicasting, Mobile IP. Son ikisi slaytta soluk gösterilmiştir.
  - Hoca internetin tasarım ilkeleri için RFC 1958'i okumayı önerdi. Derste anılan ilkeler:
    - Çalıştığından emin ol: test edilip onaylanmamış bir şeyi kesinleştirme.
    - Basit tut: Occam'ın usturası; birden çok çözüm varsa basit olanı seç, var olan özelliklerin birleşimiyle yapılabilecek bir şeyi ayrıca ekleme.
    - Net seçim yap: aynı işi yapmanın birden çok yolu olması belaya davetiye çıkarmaktır.
    - Modülerlik: katmanlar arasındaki servis sınırları temiz olmalı, bir katman çıkarılıp yerine başkası konabilmelidir. TCP/IP'de bu tam sağlanmaz; ICMP'nin hangi katmanda olduğu tartışmalıdır.
    - Heterojenliği bekle: farklı donanımlar, iletim teknikleri ve uygulamalar olacaktır.
    - Ölçeklenebilirlik.
    - Gönderirken kurala sıkı uy, alırken toleranslı ol: gelen verinin kurala uygun olacağını varsaymak büyük hatadır.

## Hocanın Özellikle Vurguladığı Kısımlar

- Ağların farklılaştığı noktalar
  - Hizmet türü, adresleme, paket boyutu, yayın, QoS, güvenlik ve ücretlendirme farklarının her biri iki ağı birleştirirken çözülmesi gereken ayrı bir sorundur.
- Sorunu bir üst katmanda çözmek
  - Her geçiş noktasında ayrı dönüşüm yapmak yerine ortak bir ağ katmanı (IP) kullanılır; günümüzde uygulanan çözüm budur.
- İki düzeyli yönlendirme
  - Ağ içinde serbest seçilen interior gateway protokolü, ağlar arasında ortak exterior gateway protokolü (internette BGP). Hoca, interior ve exterior terimlerini karıştırdığını fark edip düzeltti; doğru eşleme intra-domain = interior, inter-domain = exterior'dır.
- IP parçalama alanları
  - "Do not fragment", "more fragments" bitleri ve offset alanı; hoca bunların derste ve sınavlarda zaman zaman sorulduğunu belirtti.
- Parçalamadan kaçınmak
  - En iyi çözüm parçalamanın hiç olmamasıdır; bunun yolu path MTU discovery'dir.
- Alırken toleranslı olmak
  - Gelen isteklerdeki parametreleri hiç denetlemeyen bir REST API ağ geçidinin en küçük beklenmedik girdide çöktüğü bir örnek anlatıldı. Kural: her zaman düzgün gönder, ama her zaman düzgün geleceğini bekleme; sebep bir hata, sürüm farkı ya da kötü niyet olabilir.

## Kısa Tekrar Notları

- Internetworking: farklı ağları tek büyük ağda birleştirmek; ağın değeri bağlı cihaz sayısıyla artar.
- Fark tablosu: service offered, addressing, broadcasting, packet size, ordering, QoS, reliability, security, parameters, accounting.
- WiMAX bağlantı yönelimli, Ethernet ve 802.11 bağlantısız, MPLS bağlantı yönelimlidir (sanal devreler).
- Ethernet MTU'su 1500 bayttır; 802.11 çerçevesi daha büyüktür, Ethernet'e geçerken parçalanabilir.
- Repeater/hub: sinyali tekrarlar. Bridge/switch: link katmanı. Router: ağlar arası cihaz.
- Ortak ağ katmanı IP: her router alt katman çerçevesinden IP paketini çıkarıp sonraki ağın çerçevesine koyar.
- IPv4 ve IPv6 adres boyutları farklıdır; doğrudan adresleme yapılamaz.
- Tünelleme: IPv6 paketi IPv4 paketine kapsüllenir, tünelin öbür ucunda çıkarılır. VPN = tünelleme + (genelde) şifreleme.
- Yönlendirme: intra-domain (IGP) her ağın kendi seçimi; inter-domain (EGP) ortak, internette BGP. Her ağ bir autonomous system'dır.
- Saydam parçalama: her ağda parçala-birleştir; geçitlere yük, tek çıkış kısıtı.
- Saydam olmayan parçalama: birleştirme hedefte; IP bunu kullanır (DF, MF, offset).
- Her parça ek başlık getirir, verim düşer.
- Path MTU discovery: DF'li paket, düşüren router'dan hata mesajı, boyut küçültülür (1400 → 1200 → 900 örneği).
- RFC 1958 tasarım ilkeleri: çalışsın, basit olsun, net seçim, modülerlik, heterojenlik, ölçeklenebilirlik, gönderirken sıkı alırken toleranslı.

## Detaylı Açıklamalar

- Ders, ağ katmanının "internetworking" bölümünü işledi. Hoca önce neden ağları birleştirmek istediğimizi anlattı: bir ağdaki cihaz sayısı arttıkça ağın değeri de artar. Eşler arası dosya paylaşımında aranan dosyanın daha çok kişide olması indirmeyi hızlandırır; bir apartmanın kendi ağına karşılık internete bağlanmak bambaşka bir kaynak dünyası açar. Ancak internet, bir omurgaya bağlı ve birbirinden farklı ISP ve kurum ağlarından oluşur; bu farklı ağları bir araya getirmek gerekir. Bunun için önce ağların nasıl farklılaştığına, sonra bu farklara rağmen nasıl birleştirileceklerine bakılır.
- Fark tablosunda (ekrandan, 00:40:00) en çok üzerinde durulanlar şunlardı: bağlantı yönelimli WiMAX ile bağlantısız Ethernet arasında geçişte sıralı teslim gibi bağlantı durumuna bağlı özellikler kaybolur; 8000 baytlık bir paketi MTU'su 1500 olan bir ağdan geçirmek parçalama gerektirir; broadcast çalışan bir ağdan noktadan noktaya bir ağa geçiş sorun olabilir; QoS garantili bir ağdan best effort bir ağa geçince garantiler kaybolur; güvenlik eksikliği üst düzeyde kapsülleme ve şifrelemeyle telafi edilebilir; süreye göre ücretlendiren bir operatörle bayta göre ücretlendiren bir operatör arasında faturalama uzlaştırılmalıdır.
- Birleştirme için iki yol konuşuldu. Birincisi iki ağ arasında her şeyi çeviren özel bir geçiş cihazıdır. İkincisi işi bir üst soyutlama katmanına taşımaktır; bugün kullanılan ve ortak ağ katmanı olarak IP'yi kullanan çözüm budur. Slayttaki örnekte (ekrandan, 00:45:00) kaynak 802.11, ortası MPLS, hedef Ethernet'tir. IP paketi önce 802.11 çerçevesine konur; ilk router 802.11 çerçevesini açıp IP paketini MPLS'e uygun biçimde kapsüller (paket burada bir sanal devreye eşlenir); ikinci router paketi MPLS'ten çıkarıp Ethernet çerçevesine sığacak biçimde, gerekirse parçalayarak, iletir. Bu ortak yapı sayesinde IP; IPX, AppleTalk, SNA gibi rakiplerini saf dışı bıraktı. Yine de IPv4 ile IPv6 arasında bile geçiş zordur, çünkü adres boyutları farklıdır ve IPv4 başlığında IPv6 adresi için yer yoktur.
- Tünelleme (ekrandan, 00:55:00), kaynak ve hedef aynı türde ama arası farklı bir ağ olduğunda kullanılır. Paris ve Londra'daki iki IPv6 ofisi arasında yalnız IPv4 çalışan servis sağlayıcılar varsa, Paris router'ı IPv6 paketinin başlığına ve adresine dokunmadan onu bir IPv4 paketinin içine koyar ve Londra router'ına gönderir; Londra router'ı dış IPv4 paketini açıp IPv6 paketini çıkarır. Bu, overlay yapısına benzer. Aynı mantık VPN'de de vardır: kullanıcının IPv4 paketi başka bir IPv4 paketine kapsüllenir ve uzak bir noktadan dışarı çıkılır; şifreleme eklenince haberleşme güvenli hale gelir.
- Ağlar arası yönlendirmede her ağ farklı algoritma ve ölçüt kullanabilir, ayrıca farklı operatörler iç ölçütlerini birbirine açmak istemez. Bu yüzden yönlendirme iki düzeye ayrılır: her ağın kendi içindeki interior gateway protokolü ve ağlar arasında ortak exterior gateway protokolü. İnternette ortak protokol BGP'dir; internetteki her ağa autonomous system denir.
- Paket parçalamada (ekrandan, 01:00:00) saydam yöntemde her ağın giriş geçidi parçalar, çıkış geçidi birleştirir. Bu, çıkış geçidinin parçaları tamponlayıp izlemesini gerektirir, geçitlere yük bindirir ve bütün parçaları aynı çıkıştan geçmeye zorlar. Saydam olmayan yöntemde parçalar hedefe kadar parça olarak gider ve hedefte birleştirilir; IP bu yöntemi DF ve MF bitleri ile offset alanıyla uygular. Her iki yöntemde de her parça ek başlık taşıdığı için verim düşer. Bu yüzden en iyisi parçalanmayı önlemektir: path MTU discovery ile kaynak, parçalanmaya izin vermeyen paketler gönderir; paketi taşıyamayan router paketi düşürüp kaynağa hata mesajı döndürür ve kaynak boyutu küçültür (1400 → 1200 → 900 örneği). İlk keşif biraz gecikme getirir ama sonra parçalama olmaz.
- Son kısımda internetin ağ katmanına giriş yapıldı (ekrandan, 01:20:00) ve tasarım ilkeleri için RFC 1958 önerildi. Hoca özellikle "basit tut" (Occam'ın usturası), "aynı iş için tek yol" ve "gönderirken sıkı, alırken toleranslı ol" ilkelerini açtı. Son ilke için, gelen istek parametrelerini hiç denetlemeyen ve bu yüzden en küçük hatalı girdide çöken bir ağ geçidi örneğini verdi.
- Ders sonrası not: Hoca IP paketinin 65515 bayta kadar büyüyebildiğini söyledi. IPv4'te Total Length alanı 16 bittir, bu yüzden paketin toplam boyu en fazla 65535 bayttır; 65515, 20 baytlık başlık çıkarıldığında kalan en büyük veri miktarıdır.
- Ders sonrası not: Hoca 802.11 çerçeve boyutunu "2200 küsur bayt" olarak verdi ve kesin sayıyı hatırlayamadı. 802.11'in taşıyabildiği en büyük veri birimi büyük olasılıkla 2304 bayttır.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
