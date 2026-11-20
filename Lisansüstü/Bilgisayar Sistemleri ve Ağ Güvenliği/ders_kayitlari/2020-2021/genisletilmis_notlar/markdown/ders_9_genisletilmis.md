# Ders 9 Genişletilmiş Notu: Ağ Güvenliğine Giriş: TCP/IP, Ethernet, ARP, IP, TCP ve DNS

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Web Güvenliğinden Ağ Güvenliğine
- 2. internet, Internet ve Best-Effort İletim
- 3. Ağ Protokolü: Sözdizimi ve Anlam
- 4. Protokol Katmanları
- 5. IP: Dar Bel
- 6. Veri Birimleri ve Kapsülleme
- 7. Ethernet
- 8. ARP ve Man-in-the-Middle
- 9. IP Adresleri
- 10. IPv4 Header
- 11. Kaynak Adres Sorunu ve IP'nin Sınırları
- 12. BGP Olayı: Pakistan YouTube'u Ele Geçiriyor
- 13. Portlar ve UDP
- 14. TCP
- 15. TCP'ye Yönelik İki Saldırı Fikri
- 16. DNS
- Örnek Sorular
- Dersin Toparlaması

## 1. Web Güvenliğinden Ağ Güvenliğine

Önceki iki haftada web güvenliği işlenmişti: önce web'in temel yapıları ve güvenlik prensipleri, işletim sisteminde ve diğer yapılarda görülen güvenlik mekanizmalarıyla karşılaştırmalı olarak gözden geçirilmiş, sonra web'e yapılan saldırılar, türleri ve alınabilecek tedbirler incelenmişti. Web güvenliğiyle ilgili bir sunum daha kalmış olsa da hoca araya ağ (network) konusunu almayı tercih etti. Gerekçesi şuydu: web, uygulama katmanında yer alır ve altındaki taşıma (transport) ve ağ (network) katmanlarından soyutlanamaz. Bu ikisi iç içe ilerleyen konulardır.

Dersin planı, önceki konulardaki mantığın aynısıdır: önce ağın temel kavramları gözden geçirilir, ardından bu yapılara yönelik saldırılar ve tedbirler konuşulur. Bu derste temel yapı anlatıldı; saldırılar bir sonraki derse bırakıldı.

Ağ denince otomatik olarak TCP/IP protokolü kastedilir. Ağ mimarilerinin gelişimi sırasında pek çok farklı protokol geliştirilip kullanılmıştır, ama bugün hem uygulamaların hem de sistemlerin birbiriyle haberleşmesinde hocanın tahminine göre %90-95, belki daha fazlası TCP/IP üzerinden yürür. Bu yüzden dersin odağı TCP/IP'dir. Hoca konuların çoğunun öğrencilere tanıdık olduğunu varsaydığını, bu yüzden bazı yerlerden hızlı geçeceğini söyledi.

## 2. internet, Internet ve Best-Effort İletim

Küçük harfle yazılan "internet" ile büyük harfle yazılan "Internet" arasında önemli bir fark vardır. Küçük harfli internet, internetworking demektir: aynı ya da farklı protokol kullanan ağların birbirine bağlanması ve birlikte çalışmasıdır, yani "ağlar arası" anlamına gelir. Büyük harfle yazıldığında ise doğrudan TCP/IP kullanan küresel ağ kastedilir: bütün ağlar TCP/IP'den oluşur ve birbiriyle haberleşmek için de TCP/IP yığınındaki protokolleri kullanır.

Ekrandaki "The Internet" slaytında Internet şöyle tanımlanıyordu: bağlı hostlar arasında paketlerin best-effort iletimini sağlayan küresel ağ (ekrandan, 00:10:00). Ortak nokta IP'dir (Internet Protocol). IP, fiziksel katman ve veri bağlantı katmanının üzerinde yer alan ve bir paketin bir noktadan başka bir noktaya gitmesini sağlayan katmandır.

Best-effort, "elinden gelenin en iyisini yapmak" demektir. Bilgi hiçbir zaman tek parça halinde gönderilmez, parçalara bölünerek gönderilir. IP bu parçaları kaynaktan hedefe giderken farklı yollardan gönderebilir:

- Bütün parçalar aynı yoldan da gidebilir, her biri ayrı yoldan da.
- Aynı parçanın birden fazla kopyası oluşabilir; hepsi kaybolursa parça hiç ulaşmaz, bazıları ulaşıp bazıları kaybolabilir.
- Parçalar farklı zamanlarda varabilir; çıkış sırası ile varış sırası aynı olmayabilir.

Paket, gönderilecek alt parçanın belirli bir yapıya göre düzenlenmiş halidir. Slayttaki tanımla paket yapılandırılmış bir bayt dizisidir (ekrandan, 00:10:00):

- **Header:** ağın kullandığı metadata. Taşınan verinin ne anlama geldiğini ve nasıl değerlendirileceğini söyler.
- **Payload:** taşınacak kullanıcı verisi, yani uygulamaya ve dolayısıyla kullanıcıya ait kısım.

IP ağındaki her sisteme host denir, çünkü ağ uygulamalarına ev sahipliği yapar. Her hostun tekil bir IP adresi vardır. Slayttaki şekilde 141.212.120.7 adresli bir dizüstü bilgisayar, 8.8.8.8 adresli Google DNS sunucusuna erişiyordu (ekrandan, 00:10:00). Paket, çıktığı noktadan hedefe varana kadar pek çok router'dan geçer. Router'lar paketin header'ındaki hedef adrese bakar ve paketi hedef IP adresine doğru bir hop ilerletir. Bu yüzden bu yönteme paket anahtarlama (packet switching) da denir.

## 3. Ağ Protokolü: Sözdizimi ve Anlam

Her ağ protokolünde bir header bir de payload yapısı vardır. Hoca bunu günlük dille karşılaştırdı. Slayttaki ifadeyle hostların nasıl haberleşeceği yayımlanmış ağ protokolleriyle tanımlanır (ekrandan, 00:15:00):

- **Syntax (sözdizimi):** haberleşmenin nasıl yapılandırıldığı, örneğin mesajların biçimi ve sırası. Header içinde hangi alanın nerede bulunacağı.
- **Semantics (anlam):** haberleşmenin ne anlama geldiği; mesaj gönderildiğinde, alındığında ya da bir zamanlayıcı dolduğunda yapılacak işler ve hangi varsayımların yapılabileceği.

Günlük dilde cümlenin öznesi, yüklemi vardır, sıfatın gelme yeri bellidir, gizli özne kullanılabilir. Ağ protokolünde de aynı mantık geçerlidir: header'daki hangi parçanın ne iş için tanımlandığını hem alıcı hem verici birebir bilmelidir. Bu sözdizimidir. Alanlardaki değerler ise bir anlam ifade eder: bir bitlik bir alanın 0 olması ayrı, 1 olması ayrı anlam taşır; aynı bitin alıcı ya da verici tarafından 1 yapılması farklı anlamlara gelebilir. Bu da anlamsal kısımdır. Dolayısıyla alıcı ve verici hem alanların başlangıç, bitiş ve uzunluğunda hem de değerlerin yorumunda anlaşmalıdır. Aradaki router'lar da aynı şeyi bilmelidir.

Slayttaki örnek header 32 bit genişliğinde çizilmişti (ekrandan, 00:15:00):

```text
Bayt  0               1               2               3
     +-------------------------------+-------------------------------+
  0  |          Source Port          |       Destination Port        |
     +-------------------------------+-------------------------------+
  4  |            Length             |           Checksum            |
     +-------------------------------+-------------------------------+
       her alan 16 bit, toplam 8 bayt
```

Source port'un nerede başladığı ve nasıl değerlendirileceği hem sözdizimi hem anlam olarak tanımlıdır; aynı şey destination port, length ve checksum için de geçerlidir. 0. bitin ve 31. bitin nerede olduğunu hem alıcı hem verici bilir.

> **Ders sonrası not:** Hoca bu şekli "IP header'ından bir parça" diye tanıttı. Şekildeki alanlar (Source Port, Destination Port, Length, Checksum; toplam 8 bayt) UDP header'ının alanlarıdır. IPv4 header'ı aşağıda Bölüm 10'da ayrıca anlatıldı.

## 4. Protokol Katmanları

Ağlar bir protokol katmanları yığını kullanır. Slayttaki maddeler şunlardı (ekrandan, 00:20:00):

- Her katmanın farklı sorumlulukları vardır; katmanlar soyutlama sınırları tanımlar.
- Alt katmanlar üstteki katmanlara hizmet verir ve üst katmanların ne yaptığıyla ilgilenmez.
- Üst katmanlar alttaki katmanların hizmetlerini kullanır ve onların nasıl çalıştığını dert etmez.

Slayttaki yığın yukarıdan aşağıya Application, Transport, Network, Data Link ve Physical katmanlarından oluşuyordu. Network katmanı temel olarak IP'dir; Physical ve Data Link katmanlarının üzerine oturur, üstünde Transport ve Application vardır. Bu, TCP/IP'nin katmanlama yapısıdır. OSI referans modeline göre çizilseydi Transport ile Application arasında Session ve Presentation katmanları da olurdu. TCP/IP'de bu iki katmanın görevleri Application katmanının içine gömülmüştür. OSI yedi katmanlıdır, TCP/IP açısından ise beş katman vardır. Hoca bugün beş katmanlı modelin kabul gördüğünü söyledi; yedi katmanı uygulayan protokoller vardır ama TCP/IP kadar yaygın kullanılmadıkları için pratikte anlam ifade etmezler.

Katmanlamanın güvenlik açısından anlamı şudur: birbiriyle ilintili görevler gruplanır ve bu gruplar arasında görünmez sınırlar oluşur. Bu gruplar katmanlara denk düşer. Böylece "bu grup görevleri şu grup görevlerden izole ettik" denebilir ve bir katmanın başka bir katmana vereceği ve ondan alacağı hizmetler net olarak tanımlanır. Hoca burada daha önce konuşulan güvenlik prensiplerine dikkat çekti: separation of duties ya da compartmentalization (parçalara bölme, kutucuklara ayırma). En azından kavramsal tasarım açısından katman yapısı bu temel güvenlik prensipleriyle uyuşur.

Katmanların görevleri:

- **Physical (fiziksel):** gönderilecek bitlerin elektrik, optik ya da radyo sinyaline nasıl dönüştürüleceği ve geri nasıl kazanılacağı.
- **Data Link (veri bağlantı):** paketin birbirine doğrudan bağlı iki nokta arasında, yani bir hop'ta, gönderici ile alıcı arasında nasıl hareket edeceği. Arada paket bir atlama yapmış gibi düşünüldüğü için buna hop denir.
- **Network (ağ):** paketin birden fazla hop atlayarak çıkış noktasından varış noktasına gitmesi. Data Link'in bir hop için yaptığını Network katmanı $n$ hop için yapar.
- **Transport (taşıma):** Network katmanının hop hop taşıdığı paketleri kullanarak iki nokta arasında bir süreklilik oluşturur; uygulamaya sürekli var olan bir bağlantı imajı sunar.
- **Application (uygulama):** uygulamanın kendisi ve kendi protokolü: HTTP, FTP, SMTP, SSH, Telnet. İki uç hangi sözdizimi ve anlama göre haberleşeceklerse ona uygun protokolle konuşur.

## 5. IP: Dar Bel

"IP — The Narrow Waist" slaytında yığın bir kum saati gibi çizilmişti (ekrandan, 00:25:00):

```text
Application layer   DNS   SSH   FTP   SMTP   NNTP   HTTP
                      \     \____\_____|______/______/
Transport layer       UDP              TCP
                         \            /
Network layer                 IP
                        /     |      \
Link layer        Cellular  WiFi   Ethernet
                       \    /       /     \
Physical layer         Radio     Copper   Fiber
```

Slaytta her katmanın yanında cevapladığı soru yazıyordu: Application "uygulama veriyi nasıl yapılandırır?", Transport "doğru servise nasıl ulaşırım, güvenilir bir veri akışını (stream) nasıl elde ederim?", Network "paket son hedefine nasıl ulaşır?", Link "bir sonraki hop'a nasıl giderim?".

Her şeyin merkezinde IP, yani Network katmanı vardır. Altında GSM/LTE gibi hücresel ağlar (Cellular), WiFi ve Ethernet bulunur. Cellular ve WiFi radyo dalgalarıyla, Ethernet bakır ya da fiber ile haberleşir. Network katmanının üstünde Transport katmanı vardır; en çok kullanılan iki taşıma protokolü UDP (User Datagram Protocol) ve TCP'dir (Transmission Control Protocol). En üstteki SSH, FTP, SMTP, NNTP ve HTTP TCP kullanır. UDP kullanan ve bugün farkına varmadan en çok kullandığımız protokollerden biri DNS'tir (Domain Name System): adlardan adreslere dönüşüm yapar.

Transport katmanının iki görevi vardır. Birincisi doğru servise ulaşmayı sağlamaktır; bu, OSI'deki Session katmanının yapacağı işlerin bir parçasıdır, geri kalanı Application katmanındadır. İkincisi akıştır (stream): paketler kaynaktan hedefe hop hop atlayarak giderken Transport katmanı açısından iki uç arasında kesintisiz, bayt çözünürlüğünde bir akış varmış gibi davranılır. Bayt çözünürlüğü şu demektir: en uç durumda gönderen tek bir bayt gönderebilir, alan tek bir bayt alabilir; yüzlerce baytı ya da bir paketi bir seferde göndermek gerekmez.

## 6. Veri Birimleri ve Kapsülleme

Hoca "paket" kavramının yanıltıcı olabileceğini belirterek katmanlara göre veri birimlerinin adlarını verdi:

- Physical ve Data Link katmanında dışarıya gönderilen bitlerin oluşturduğu bütüne **frame** denir. Frame'in bitleri Data Link katmanı tarafından karşıya aktarılır.
- Network katmanından Data Link katmanına inen yapıya **paket** denir.
- Transport katmanından Network katmanına gelen yapıya **segment** denir.
- Application katmanından çıkan yapıya **mesaj (message)** denir.

İdeal durumda bunların boyları birbirine eşit olur, ama her zaman böyle değildir. Uygulamadan çıkan bir mesaj Transport katmanında birden fazla segmente, bir segment Network katmanında birden fazla pakete bölünebilir. Çok istisna yapılmayan nokta, Network katmanındaki paket boyu ile Data Link/Physical katmanındaki frame boyudur. Bunların eşit olması istenir ve bunun için çaba gösterilir; bir paketi birden fazla frame'e bölmek çok daha fazla sorun getirir.

Bu yapıda bir kapsülleme (encapsulation) yani iç içe geçme durumu vardır. Slayttaki tanım (ekrandan, 00:30:00):

- N1 protokolü, alt katmandaki N2 protokolünün hizmetlerini kullanabilir.
- N1'in P1 paketi, N2'nin P2 paketinin içine kapsüllenir.
- P2'nin payload'u P1'dir.
- P2'nin denetim bilgisi P1'inkinden türetilir.

Slayttaki şekilde P2 = [IP Header | Payload] ve payload'un içinde P1 = [TCP Header | HTTP Request] vardı. Transport katmanından bir TCP segmenti gelir; başında TCP header'ı, arkasında örneğin bir HTTP isteği vardır. Network katmanına gelince bu segment olduğu gibi taşınacak bir veriye dönüşür ve payload alanının tamamını oluşturur; önüne bir IP header'ı eklenir. Karşı tarafta Network katmanı IP header'ını inceleyerek payload'ta ne olduğunu anlar ve onu TCP'ye mi UDP'ye mi yönlendireceğine karar verir. TCP'ye çıkarsa TCP header'ına, UDP'ye çıkarsa UDP header'ına bakılarak devam edilir.

Hoca bunu Rus matruşka bebeklerine benzetti: bir bebeğin içinden kendisi gibi bir bebek, onun içinden yine bir bebek çıkar. Üst katmandan alt katmana inerken her seferinde öne bir header eklenir; alt katmandan üst katmana çıkarken header'lar birer birer çıkarılır.

## 7. Ethernet

### 7.1 Ethernet Frame'i

Yerel ağlarda, hatta bugün şehir içindeki metro ağlarında en çok kullanılan link katmanı protokollerinden biri Ethernet'tir. Ethernet 48 bitlik, yani 6 baytlık fiziksel adresler üzerine kuruludur. Bunlara MAC (Medium Access Control) adresi denir. Frame'de sırasıyla hedef MAC adresi, kaynak MAC adresi ve taşınan verinin türü (EtherType) bulunur. Eskiden tür alanı yoktu ve uzunluktan çıkarılıyordu; sonra Ethernet Type II kullanılmaya başlandı. EtherType değerleri onaltılık olarak:

- `0x0800`: IPv4 taşınıyor.
- `0x0806`: ARP (Address Resolution Protocol) taşınıyor.
- `0x86DD`: IPv6 taşınıyor.

Frame'in sonunda 4 baytlık bir CRC (Cyclic Redundancy Check) vardır. CRC, bit değişimlerinin (bit hatalarının) fark edilmesini ve hatalı frame'lerin kabul edilmemesini sağlar. Arada 46 ile 1500 bayt uzunluğunda payload bulunur. Kapsülleme mantığına göre bu payload bir IP paketi ya da bir ARP paketi olabilir.

Frame boylarının hesabı şöyledir (ara adımlar hocanın anlatımından):

- Header: 6 (hedef MAC) + 6 (kaynak MAC) + 2 (EtherType) = 14 bayt.
- Header + CRC: $14 + 4 = 18$ bayt.
- En kısa frame: $46 + 18 = 64$ bayt. Bundan kısa frame hatalı sayılır.
- En uzun frame: $1500 + 18 = 1518$ bayt.

### 7.2 Broadcast Ethernet'ten Switched Ethernet'e

Başlangıçta Ethernet broadcast mantığıyla çalışıyordu. "Thick Ethernet" denen kalın bir koaksiyel kablo vardı ve bütün hostlar bu kabloya bağlıydı. Bir hostun gönderdiğini hepsi aynı anda alıyordu. Her host yalnız MAC adresine bakıp "bana mı gelmiş?" diye kontrol ediyor; kendine gelmemişse frame'i ve içindeki paketi almaya gerek görmeyip atıyor, kendine gelmişse işliyordu.

Bu yapının iki önemli sorunu vardı. Birincisi, aynı anda birden fazla host konuşmak istediğinde bir gürültü oluşur. Hoca bunu herkesin bir arada olduğu bir ortamda herkesin aynı anda konuşmasına benzetti: bir yerden sonra kimse kimseyi anlamaz. İkincisi, mahremiyet yoktur: herkes herkesin konuştuğunu duyabilir.

Daha sonra broadcast Ethernet, switched Ethernet'e dönüştü. Araya bir anahtarlama cihazı (switch) konur ve her host switch'in farklı bir portuna bağlanır. Slayttaki maddeler (ekrandan, 00:35:00):

- Switch, kaynak MAC adreslerine bakarak her MAC adresinin hangi fiziksel portta bulunduğunu öğrenir.
- Switch, M adresinin P portunda olduğunu biliyorsa M'ye giden paketi yalnız P portundan gönderir.
- Switch, M'nin hangi portta olduğunu bilmiyorsa tüm portlara yayınlar (broadcast).

Böylece gürültü ortamı oluşmaz ve paket yalnız ilgili hosta aktarılır. O ana kadar hiç konuşmamış, MAC adresi bilinmeyen bir host varsa switch "şu MAC adresini arıyorum" diye yayın yapar; o adrese sahip host cevap verince switch onun hangi porta bağlı olduğunu öğrenir.

### 7.3 ifconfig Örneği

Slaytta bir Unix makinesinde çalıştırılmış `ifconfig` çıktısı vardı. Hocanın okuduğu bilgiler:

- Ethernet kartının işletim sistemindeki adı `ens160`.
- MTU (Maximum Transmission Unit) 1500: Ethernet payload'u en az 46, en çok 1500 bayt olabilir.
- Bir IPv4 adresi, ağ maskesi (netmask) ve yayın (broadcast) adresi.
- `fe80` ile başlayan bir IPv6 adresi.
- 48 bitlik Ethernet (MAC) adresi.
- 1000 frame'lik transmit queue length: bir frame gönderilirken başka frame gönderme istekleri gelirse 1000 taneye kadar kuyruğa alınabilir.
- Alınan ve gönderilen paket sayıları ve bayt karşılıkları (alınan yaklaşık 1,7 TB, gönderilen yaklaşık 6 TB); makinenin uzun süredir çalıştığı belliydi.
- Hatalı bulunduğu için işlenmeyen alınmış paket sayısı 73; yaklaşık 1,4 milyar pakette 73 hata.

<!-- BELİRSİZ: ifconfig çıktısının karesi yok. IPv4 adresi, MAC adresi ve trafik sayıları altyazıdan alındı; IPv4 adresi ve MAC adresi bu yüzden nota yazılmadı, trafik sayıları doğrulanamadı. -->

Hoca bu çıktıdan şu sonucu çıkardı: yerel ağdaki Ethernet oldukça güvenilir çalışır. Az önceki sayıda hatalı paketin büyük olasılıkla header checksum'ı tutmadığı için atıldığını da daha sonra IP header'ı anlatırken ekledi.

## 8. ARP ve Man-in-the-Middle

### 8.1 İki Problem

Bir host haberleşeceği hostun MAC adresini bilmiyorsa ne yapmalıdır? Switch örneğinde görüldüğü gibi bir yayın yapılmalıdır. Buradaki problem şudur: host katman 3'te IP ile çalışır, ama IP paketi katman 2'de MAC adresi kullanılarak gönderilecektir. Bu yüzden IP adresine karşılık gelen MAC adresinin öğrenilmesi gerekir.

Daha büyük resimde, Internet'in kendisinde ise ikinci bir problem vardır: bir router'ın kendisine gelen paketi bir sonraki aşamada nereye göndereceğine karar verebilmesi için hedef IP adresinin hangi yönde olduğunu bilmesi gerekir. Bu iki problemin çözülmesi gerekir. Yereldeki problem ARP ile çözülür.

### 8.2 ARP'nin Çalışması

ARP tamamen yerel ağda (local area) çalışır ve bir IP adresine karşılık gelen MAC adresini öğrenmeyi sağlar. Slayttaki tanım (ekrandan, 00:40:00):

- ARP, hostların IP adreslerini MAC adreslerine eşlemesini sağlayan bir ağ protokolüdür.
- IP adresi N'ye karşılık gelen MAC adresi M'ye ihtiyaç duyan host, yerel ağa "IP adresi N kimde?" diye soran bir ARP paketi yayınlar.
- IP adresi N olan host "IP N, MAC adresi M'dedir" diye cevap verir.

Soru bütün hostlara gider, ama tasarım gereği yalnız IP adresi N olan host cevap vermelidir.

Slayttaki ARP frame'inde önce az önce öğrenilen hedef ve kaynak MAC adresleri ile ARP tipini gösteren EtherType (`0x0806`) yer alıyordu. ARP bilgileri 28 baytlık bir kısımda taşınır; bu kısım bir ARP isteği (request) ya da cevabı (reply) olabilir. Ethernet frame'i 64 bayttan kısa olamayacağı için ARP bilgileri bir araya getirildiğinde eksik kalan kısım sıfır değerli dolgu (padding) ile doldurulur.

> **Ders sonrası not:** Hoca eksik kalan kısmın "10 bayt kadar" olduğunu söyledi. 28 baytlık ARP verisi ile 46 baytlık en küçük payload arasındaki fark $46 - 28 = 18$ bayttır; dolgu büyük olasılıkla 18 bayttır.

### 8.3 ARP'nin Güvenlik Sorunu

Sorun şuradadır. Ağ büyükse yayının bütün hostlara ulaşma süresi aynı olmaz; bazılarına hızlı, bazılarına yavaş ulaşır. Kötü niyetli bir host, özellikle ağın ortasına yakın konumlandırılmışsa, bu yayınlara "bu IP adresi bana ait" diye cevap verebilir.

Olay şöyle gelişir:

- ARP isteği yapılır.
- Kötü niyetli host "bu IP adresi bana aittir" diye cevap verir.
- Bir süre sonra o IP adresinin gerçek sahibi de cevap verir.
- İsteği gönderen taraf durumun farkında değildir. Gerçek hostun cevabı daha sonra geldiği için "ağdır bu, paket iki kez gelebilir; ben cevabı zaten almıştım" diyerek ikinci cevabı atar.
- Böylece araya giren kötü niyetli hostun cevabı gerçek kabul edilir. Gerçek hostun cevabını da kötü niyetli host görmüş olur, çünkü o da yayına cevap vermektedir.

Sonuçta A ile B arasında doğrudan gerçekleşmesi gereken haberleşme kötü niyetli hostun üzerinden geçer. Bu tipik bir man-in-the-middle saldırısıdır.

> **Hocanın vurgusu:** ARP'de bu açıdan hiçbir güvenlik yoktur. Bu, ARP'nin en sorunlu noktalarından biridir.

## 9. IP Adresleri

Yerel ağ düz (flat) bir yapıdadır ve orada adresleme ARP ile çözülür. Internet'te ise IP adresleri kullanılır. İki sürüm vardır (ekrandan, 00:45:00):

- **IPv4:** 32 bitlik host adresleri. A.B.C.D biçiminde 4 bayt olarak yazılır; A, ..., D ondalık yazılmış 8 bitlik tamsayılardır. Rahat okunması için ondalık yazıldığından buna noktalı ondalık biçim (dotted decimal, slaytta dotted quad) denir. Örnek: 192.168.1.1.
- **IPv6:** 128 bitlik host adresleri, yani IPv4'ün 4 katı. 16 bayt olarak AA:BB::XX:YY:ZZ biçiminde yazılır; AA, ..., ZZ onaltılık yazılmış 16 bitlik tamsayılardır, yani adres 2 baytlık gruplar halinde yazılır ve gruplar iki nokta üst üste ile ayrılır. `::` sıfır gruplarını ifade eder.

Ardışık sıfır grupları `::` ile kısaltılır. Slayttaki örnek:

$$
\texttt{2620:0:e00:b::53} = \texttt{2620:0:e00:b:0:0:0:53}
$$

Çözüm (hocanın anlatımına göre): kısaltılmış adreste `2620`, `0`, `e00`, `b`, `53` olmak üzere 5 grup görünür. IPv6 adresi 128 bit, yani 16 bitlik 8 gruptur. Eksik grup sayısı $8 - 5 = 3$'tür, bu yüzden `::` yerine 3 sıfır grubu gelir. `2620`'den sonraki tek sıfır grubu ise `0` olarak yazılmak zorundadır.

Bu sıkıştırma adreste yalnız bir yerde yapılabilir. Başta, ortada ve sonda birden çok kez yapılırsa toplam kaç grubun eksik olduğu bilinir, ama bunların kaçının başa, kaçının ortaya, kaçının sona ait olduğu bilinemez.

> **Ders sonrası not:** Hoca 00:46:52'de eksik sıfırları sayarken "toplamda 128 byte" dedi; IPv6 adresi 128 bit (16 bayt) uzunluğundadır.

> **Python ile doğrulandı:** `ipaddress.ip_address('2620:0:e00:b::53').exploded` sonucu `2620:0000:0e00:000b:0000:0000:0000:0053` olur; 3 sıfır grubu açılmıştır.

## 10. IPv4 Header

IPv4 header'ı, router'lara ve hostlara gelen pakete ne yapılması gerektiğini, pakete nasıl davranılacağını ve paketin ne anlama geldiğini anlatır. Slayttaki ikinci cümle önemlidir: bütün değerleri gönderen host doldurur (ekrandan, 00:50:00).

```text
Bayt  0               1               2               3
     +-------+-------+---------------+-------------------------------+
  0  |Version|  IHL  |Type of Service|         Total Length          |
     +-------+-------+---------------+-----+-------------------------+
  4  |        Identification         |Flags|     Fragment Offset     |
     |                               |x D M|                         |
     +---------------+---------------+-----+-------------------------+
  8  | Time To Live  |   Protocol    |        Header Checksum        |
     +---------------+---------------+-------------------------------+
 12  |                        Source Address                         |
     +---------------------------------------------------------------+
 16  |                      Destination Address                      |
     +---------------------------------------------------------------+
 20  |   IP Option (değişken uzunluklu, isteğe bağlı, yaygın değil)  |
     +---------------------------------------------------------------+
       ilk 20 bayt sabit; IHL (Internet Header Length) seçenekleri de kapsar
```

### 10.1 Version ve IHL

Version 4 bitlik bir alandır. IPv4 paketlerinde bu alanda 4, IPv6 paketlerinde 6 değeri bulunur.

IHL (IP Header Length) header'ın uzunluğudur ve ona da yalnız 4 bit ayrılmıştır. 4 bitle 0 ile 15 arası değerler ifade edilebilir, ama header'da bundan çok daha fazla bayt vardır. Bu yüzden IHL 32 bitlik (4 baytlık) kelimeler üzerinden hesaplanır:

- IHL = 5 ise $5 \times 4 = 20$ bayt.
- IHL = 8 ise $8 \times 4 = 32$ bayt.

### 10.2 Diğer Alanlar

Version ve IHL'nin yanında Type of Service ve Total Length alanları vardır.

Identification ve Fragment Offset parçalama içindir. Bir segment kendi içinde birden fazla parçaya bölünebilir. Her parçanın ayrı olduğunu ifade etmek için bir tanımlayıcı (ID) değeri gerekir; Identification bu işe yarar. Öte yandan daha uzun bir parça daha küçük parçalara bölündüyse bunlar aynı parçanın alt parçaları olduğundan Identification değerleri aynı olmalıdır; yalnız kaçıncı parça olduklarına göre farklılaşmalıdır. Bu da Fragment Offset ile ifade edilir.

> **Ders sonrası not:** Hoca Fragment Offset'in bayt cinsinden olduğunu söyledi. Doğrusu, Fragment Offset 8 baytlık birimlerle ifade edilir.

Time to Live (TTL) alanı best-effort iletim yüzünden önemlidir: paket kaybolabilir, çoğalabilir, farklı yollardan gelebilir. Hoca bunu teslim edilemeyen mektuba benzetti: aranan kişi orada oturmuyorsa ya da adres yanlışsa mektubun üzerine not düşülüp posta servisine iade edilir. IP'de de her paketin bir yaşam süresi vardır. Paket hop hop aktarılırken her hop'ta bu değer bir azaltılır. Sıfıra inerse paketin hedefe ulaştırılamadığı kabul edilir, paketle daha fazla uğraşılmaz ve paket atılır.

Protocol alanı payload'taki üst protokolü gösterir: UDP, TCP, gerçek zamanlı akış protokolleri ya da diğerleri olabilir.

Header Checksum yalnız header kısmının checksum'ıdır. IP best-effort taşıma yapar ve taşıdığı verinin doğruluğuyla ilgilenmez; yalnız onun hedefe düzgün aktarılmasıyla ilgilenir. Düzgün aktarım için düzgün olması gereken alanlar header'dadır; bu yüzden header için bir checksum değeri üretilir. Hoca, `ifconfig` örneğinde atılan paketlerin büyük olasılıkla checksum'ı tutmadığı için atıldığını söyledi.

> **Ders sonrası not:** Hoca header checksum'ı "aslında bir XOR işlemi" diye anlattı. Doğrusu, header'ın 16 bitlik kelimelerinin birler tümleyeni (one's complement) toplamının birler tümleyenidir.

Source Address ve Destination Address 32'şer bittir: paketin kimden gönderildiği ve kime gönderildiği. Çok kullanılmasa da IP paketleriyle standartta tanımlı isteğe bağlı bilgiler (options) de verilebilir. Bunlar varsa 20. bayt ofsetinden başlar.

### 10.3 Header Uzunluğu Sonuçları

- Geçerli bir IP header'ı en az 20 bayttır, daha kısa olamaz.
- En uzun geçerli IP header'ı $15 \times 4 = 60$ bayttır.
- En kısa header'lı bir IPv4 paketinin ilk baytı (ofset 0x0) onaltılık `45` olur: üst 4 bit Version = 4, alt 4 bit IHL = 5 (çünkü $5 \times 4 = 20$).

## 11. Kaynak Adres Sorunu ve IP'nin Sınırları

### 11.1 Router Yalnız Hedef Adrese Bakar

"Destination Address" slaytında şu yazıyordu: hedef adresi gönderen belirler; router'lar paketi bu adrese iletmeye çalışır (ekrandan, 00:55:00). Bir paketin hedefe gönderilmesinde her zaman hedef adres kullanılır, kaynak adres kullanılmaz. Source routing diye bir mekanizma vardır, ama o da kaynak adresi kullanmaz; yalnız gönderenin, paket yola çıkarken hangi router'lara uğranacağını belirtmesini sağlar.

> **Hocanın vurgusu:** İstisnasız olarak bir IP paketinin hedefe gönderilmesinde kullanılan adres her zaman hedef adrestir. Router'lar kaynak adresle ilgilenmez. Bu çok önemli bir noktadır.

Kaynak adresi gönderen kendisi yazar. Router "bu paket bana geldi, ama bu paketi gönderen gerçekten kaynak adresteki host muydu?" diye sorgulamaz. O halde bir ağ uygulamasıyla kaynak adres alanına istenen herhangi bir adres yazılabilir ve paket herhangi bir hedefe gönderilmek üzere router'a verilebilir. Kritik nokta şudur: paket hedefe ulaştığında hedefin üreteceği cevap gönderene değil, kaynak adres alanına ne yazıldıysa o adrese gider. Hoca "burada açıklar oluşmaya başladı" diyerek konuyu bağladı.

### 11.2 libnet ile Paket Üretme

libnet adlı bir kütüphanenin Unix, Linux ve Windows sürümleri vardır. Bu kütüphane C ve C++'tan, hatta Python gibi diğer dillerden kullanılabilir ve bununla bir IP paketi oluşturulabilir. Paketi oluştururken kaynak ve hedef adrese istenen değer yazılabilir.

Daha önce öğrenilen saldırılar sonucunda bir bilgisayarın kontrolü ele geçirilmiş ve üzerinde bu türden kötü niyetli bir kod parçası çalışıyorsa, bu kod bilgisayarı bir hizmet engelleme (denial of service) saldırısında kullanabilir ya da kendi gerçek kimliğini gizleyip paketleri o bilgisayardan çıkıyormuş gibi göstererek onun hattını kullanabilir. Yani IP'nin temelinde güvenlik açısından çok ciddi bir zafiyet vardır.

<!-- BELİRSİZ: 00:58:04-00:58:14 arası altyazı kesik; hocanın ikinci kullanım biçimini tamamlayan cümle tam anlaşılmıyor. -->

### 11.3 IP Ne Yapar, Ne Yapmaz

IP'nin yaptıkları:

- Yönlendirme (routing).
- Parçalama ve birleştirme (fragmentation ve reassembly).
- TTL üzerinden hata bildirimi: "bu paketi hedefine gönderemiyorum".

Bunun dışında hiçbir şey yoktur: sıralama yoktur, yeniden gönderme yoktur, header dışında hata denetimi yoktur. Paket (datagram) tabanlı olduğu için "aldım/verdim" biçiminde bir onay mekanizması yoktur. Bağlantı diye bir şey yoktur, güvenlik diye bir şey yoktur; yalnız paketler vardır.

## 12. BGP Olayı: Pakistan YouTube'u Ele Geçiriyor

Hoca IP'nin güvenliksizliğinin gerçek hayattaki bir sonucunu anlattı. Slayttaki bilgiler (ekrandan, 01:00:00):

- 24 Şubat 2008'de Pakistan Telecom (AS 17557), YouTube'a (AS 36561) atanmış ağın küçük bir kısmını duyurmaya (advertise) başladı.
- PCCW (3491), Pakistan Telecom'un (17557) 208.65.153.0/24 için yaptığı duyuruyu doğrulamadı.
- YouTube erişilemez (offline) oldu.

Pakistan Telecom, Türkiye'deki Türk Telekom gibi bir servis sağlayıcıdır. Amacı ülke içinde YouTube'a erişimi kısıtlamaktı ve bunun için YouTube'un otonom sistem numarasına ait adresleri farklı bir yere yönlendiren bir duyuruyu Border Gateway Protocol (BGP) üzerinden gönderdi. PCCW uluslararası bir servis sağlayıcıdır; hoca onu Amerika'daki Sprint gibi büyük omurga sağlayıcılarına benzetti. PCCW, Pakistan Telecom'dan gelen bu duyuruları bir onay mekanizmasından geçirmedi; "nasıl olsa Pakistan da ağın bir parçası, onlar da BGP ile sisteme bağlı" mantığıyla kabul etti. Sonuçta dünyanın her yerinde YouTube'a erişmek isteyenler Pakistan'ın belirttiği kör bir noktaya gitti ve YouTube bir anda erişilemez oldu.

> **Ders sonrası not:** Hoca Pakistan'ın YouTube'un bütün adres aralığını içeren bir duyuru gönderdiğini söyledi. Slaytta duyurulanın YouTube ağının küçük bir kısmı (208.65.153.0/24) olduğu yazıyor. Büyük olasılıkla bu daha özel (more specific) önek, router'larda YouTube'un kendi duyurusundan öncelikli seçildiği için trafik dünya çapında Pakistan'a yöneldi.

Hoca bu olayı IP'nin "ne sıralama, ne yeniden gönderme, ne ciddi hata denetimi, ne güvenlik" özellikleriyle ilişkilendirdi: Pakistan bunu kendi ülkesi için yapmak istemiş, ama bir yapılandırma hatası bütün dünyayı etkilemişti. Bunun ardından ülkeler arası Internet geçişini sağlayan BGP'deki bu tür güvenlik zafiyetlerinin giderilmesi için çalışmalar başladı.

> **Hocanın vurgusu:** TCP/IP bugün en çok kullandığımız ağ protokolüdür, ama aynı zamanda güvenlik açısından her anlamda, yani hem network katmanı hem transport katmanı hem de üzerindeki uygulama katmanı protokolleri açısından zaafları en yüksek olan protokol yapısıdır.

## 13. Portlar ve UDP

### 13.1 Portlar

Aradan sonra hoca Transport katmanının iki temel görevini hatırlattı: host üzerinde hangi uygulamayla haberleşileceğini belirlemek ve iki uç arasında kesintisiz bir akış sağlamak. Hangi uygulamayla haberleşileceği port bilgisiyle sağlanır. Hem UDP'de hem TCP'de ek bir bilgi olarak port değeri vardır. "Ports" slaytındaki maddeler (ekrandan, 01:15:00):

- Host üzerindeki her uygulama bir port numarasıyla tanımlanır.
- TCP bağlantısı X hostundaki A portu ile Y hostundaki B portu arasında kurulur.
- Portlar 1-65535 arasındadır (16 bit).
- Bazı hedef port numaraları uzlaşmayla belirli uygulamalar için kullanılır.

Böylece bir uygulama port bilgisini kullanarak karşı tarafta hangi uygulamayla haberleşeceğini belirtir. Slaytta en çok kullanılan portlar olarak 80, 443, 25, 67, 22 ve 23 verilmişti.

> **Ek bilgi (derste anlatılmadı):** Bu portlar sırasıyla yaygın olarak HTTP (80), HTTPS (443), SMTP (25), DHCP sunucusu (67, UDP), SSH (22) ve Telnet (23) için kullanılır.

### 13.2 UDP

UDP'nin temel kısıtı, tıpkı Network katmanında olduğu gibi, arka arkaya gelen paketleri birbiriyle ilişkilendirmemesidir. Her paket bağımsız kabul edilir ve alınıp verilecek bilgi tek bir paketin içine sığmak zorundadır. Bu, istek-cevap (request-reply) biçiminde çalışan uygulamalar için ciddi performans sağlayan bir yaklaşımdır. Ancak kayıp olduğunda kaybın nerede ve ne kadar olduğu bilinemez. UDP bir yandan hız getirirken öbür yandan Network katmanının güvenilmez yapısını da beraberinde getirir.

UDP kullanılıp güvenilir bir iletişim isteniyorsa uygulama seviyesinde tedbir almak gerekir. Bu tedbiri her uygulama için ayrı ayrı almak çok verimli olmayabilir ve asıl uygulamaya yoğunlaşmayı engelleyebilir. Bu sorunu çözmek için UDP'nin alternatifi olarak geliştirilmiş protokol TCP'dir.

## 14. TCP

### 14.1 Paketlerden Akışa

"From Packets to Streams" slaytında şunlar yazıyordu (ekrandan, 01:20:00): çoğu uygulama, farklı hostlardaki uygulamalar arasında güvenilir ve sıralı teslim edilen bir bayt akışı ister. TCP şunları sağlar:

- Açık kurulum ve sonlandırması olan bağlantı yönelimli bir protokol.
- Güvenilir, sıralı bayt akışı.
- Tıkanıklık denetimi (congestion control).

Bunları IP paketleri atılsa, sırası değişse ve çoğaltılsa bile sağlar.

TCP bağlantı mantığına kuruludur: haberleşecek iki uygulama önce bir bağlantı kurar, tıpkı bir telefon bağlantısı gibi; haberleşme bitince bağlantı sonlandırılır. Alınıp verilen veri sıralıdır: gönderenden hangi sırayla çıktıysa alıcıya o sırayla gelir. Eksik gelmez, fazla gelmez; tekrarlı gelse bile teke indirgenir. Hatlarda tıkanma olursa yavaşlama, tıkanma kalkınca hızlanma olabilir; tıkanıklık denetimi bunu yönetir. IP'de görülen sorunlara (paket kaybı, sıranın bozulması, kopyalar) rağmen TCP verinin güvenilir ve sıralı biçimde kaynaktan hedefe ulaşmasını sağlar. Bunun için sıra numarası (sequence number) kullanması gerekir.

TCP haberleşmesi çift yönlüdür: A'dan B'ye ve B'den A'ya aynı anda veri gidebilir. Bu, iki tek yönlü haberleşmeden yararlanılarak oluşturulur. 32 bitlik bir sıra numarası kullanılır. Her pakette sıra numarası bulunduğu için karşı taraf onay mekanizmasını çalıştırabilir: "5 numaralı paketi aldım, 7 numaralıyı aldım, 10 numaralıyı aldım" diyebilir.

### 14.2 TCP Header

TCP header'ı da IPv4 header'ı gibi 20 bayta oturtulmuştur. Hocanın saydığı alanlar:

- Source Port ve Destination Port.
- 32 bitlik Sequence Number.
- 32 bitlik Acknowledgment Number.
- 4 bitlik Offset alanı: hocaya göre ek TCP seçenekleri (options) varsa bunların nereden itibaren başladığını gösterir.
- Bir takım TCP bayrakları (flags).
- Window: hocaya göre tıkanıklığın yönetimi ve uçtan uca akış denetimi (flow control) ile ilgilidir.
- Checksum: IP'deki checksum ile aynı mantığa oturur.
- Urgent Pointer: aynı segmentte birbiriyle ilintili ama farklı veriler gidiyorsa ve bunların içinde önce işlenmesi gereken bir kısım varsa, o kısmın hangi ofsette başladığını gösterir.

<!-- BELİRSİZ: TCP header slaytının karesi yok; alan listesi altyazıdan alındı. -->

> **Ek bilgi (derste anlatılmadı):** Offset (Data Offset) alanı TCP header'ının uzunluğunu 32 bitlik kelime cinsinden verir; yani verinin (payload) nereden başladığını gösterir. Seçenek yoksa değeri 5'tir (20 bayt). Window alanı alıcının o an kabul edebileceği bayt miktarını bildirir ve doğrudan akış denetimi içindir; tıkanıklık denetimi ise gönderenin tuttuğu ayrı bir pencereyle yapılır.

### 14.3 Sıra Numarası ve ACK

Slaytta sıra numaraları bir bayt şeridi üzerinde gösterildi. Kural şudur: alıcı her zaman bir sonra beklediği baytın sıra numarasıyla onay verir (ekrandan, 01:25:00).

Hocanın anlattığı akış adım adım şöyledir:

- **Adım 1:** Gönderen 3 baytlık bir segment gönderir. Sıra numarası bir sonraki pozisyonu gösterir: 400'e kadar alınmış, bu segment 401, 402 ve 403. baytları taşır.
- **Adım 2:** Alıcı 403'e kadar aldığı için 404'ü beklemektedir; ACK olarak 404 gönderir.
- **Adım 3:** Gönderen arka arkaya iki segment gönderir: biri 404'ten başlayan 4 bayt (404-407), öbürü 408'den başlayan 3 bayt (408-410).
- **Adım 4:** Alıcı her ikisi için ayrı ACK göndermek yerine ACK sayısını azaltmak için tek bir ACK gönderebilir: $404 + 4 = 408$, $408 + 3 = 411$; ACK 411 gönderilir.

Bir paket ağda kaybolursa ne olur? Slayttaki soru buydu: "What if the first packet is dropped in network?" (ekrandan, 01:25:00):

- 404'ten başlayan segment kaybolur, 408'den başlayan 3 baytlık segment ulaşır.
- Alıcı 408-410'u almıştır, ama 404'ten başlayan 4 bayt eksiktir. Bu yüzden ACK 404 gönderir: "orası eksik". Slaytta bu cevap `ACK: 404, LEN: 0` olarak gösteriliyordu.
- Gönderen 404'ten 4 bayt gönderdiğini bilir ve kaybolan segmenti yeniden gönderir.
- Artık alıcı 410'a kadar bütün baytlara sahiptir ve ACK 411 gönderir.

> **Hocanın vurgusu:** Alıcının gönderdiği ACK, bir sonra beklediği bayttır. Bunu hiçbir zaman unutmuyoruz.

### 14.4 Bağlantının Kurulması: Üçlü El Sıkışma

Haberleşmeden, yani veri alışverişinden önce bağlantı kurulur, sonra sonlandırılır. Bağlantının kurulması üç mesajla gerçekleşir; bu yüzden buna üçlü el sıkışma (3-way handshake) denir. Bağlantıyı her zaman client başlatır.

- **1. mesaj (SYN):** Client, server'a bir senkronizasyon isteği ve kendi sıra numarasını gönderir.
- **2. mesaj (SYN/ACK):** Server isteği olumlu karşılarsa ACK alanına kendisine gelen sıra numarasının bir fazlasını, sıra alanına kendi sıra numarasını yazar.
- **3. mesaj (ACK):** Client, server'ın cevabını aldığını onaylamak için ACK alanına server'dan gelen sıra numarasının bir fazlasını yazar.

Hocanın slayttan okuduğu değerlere göre üçüncü mesajda client ACK 201 ve sıra numarası olarak 101 kullanır, yani kendisinden beklenen sıra numarasını. Buradan client'ın başlangıç sıra numarasının 100, server'ınkinin 200 olduğu anlaşılır (ara adım eklendi). Böylece client ve server birbiriyle senkronize olur.

```text
Client                                   Server
  |  SYN      SEQ=100                      |
  |--------------------------------------->|
  |  SYN/ACK  SEQ=200  ACK=101             |
  |<---------------------------------------|
  |  ACK      SEQ=101  ACK=201             |
  |--------------------------------------->|
```

<!-- BELİRSİZ: El sıkışma slaytının karesi yok; 100 ve 200 başlangıç değerleri, hocanın okuduğu 201 ve 101 değerlerinden çıkarıldı. -->

### 14.5 Bağlantının Sonlandırılması

Bağlantının sona erdirilmesi "kibar" bir şekilde gerçekleşir. Taraflardan biri (server da olabilir, client da) bitirme (FIN) isteğinde bulunur. Diğer taraf onay (ACK) gönderir ve aynı zamanda kendisi de FIN isteğinde bulunur. Bu sefer öbür taraf ACK gönderir.

Dört mesaj olmasının ve her iki tarafın da sonlandırma isteği göndermesinin nedeni, bağlantının iki tek yönlü akıştan oluşmasıdır: biri A'dan B'ye, biri B'den A'ya gider. FIN'lerden biri A'dan B'ye giden akışı, diğeri B'den A'ya giden akışı sonlandırır.

Bir de şu unutulmamalıdır: ağ bir paketi anında iletemez, belirli gecikmelerle iletir ve ağ büyüdükçe gecikmeler artabilir. Bu yüzden sonlandırma isteğinden sonra bir zamanlayıcı devreye girmeli ve ağda hâlâ yolda olan paketlerin gelmesine bağlantı kapanmadan önce fırsat tanınmalıdır.

### 14.6 Bağlantının Sıfırlanması (Reset)

Slayttaki maddeler (ekrandan, 01:30:00):

- TCP, sahte/başıboş (spurious) TCP paketleri olasılığını ele alacak şekilde tasarlanmıştır (örneğin önceki bağlantılardan kalan paketler).
- Oturumun o anki durumuna göre geçersiz olan paketler bir reset üretir: bağlantı varsa yıkılır ve cevap olarak RST bayraklı bir paket gönderilir.
- RST bayraklı bir TCP paketi alan host bağlantıyı yıkar.

Hoca son maddeyi şöyle tamamladı: RST biti set edilmiş bir TCP header'ı hosta gelirse ve sıra numarası da uygunsa host bu bağlantıyı sonlandırır.

## 15. TCP'ye Yönelik İki Saldırı Fikri

Hoca, bağlantı kurma ve sıfırlama bilgileri üzerine hemen iki zafiyet kurulabileceğini söyledi. Ayrıntılar sonraki derse bırakıldı.

### 15.1 Başka Bir Hostun Yerine Bağlantı Kurmak

Soru şudur: başka bir hostun yerine geçip onun adına bağlantı oluşturabilir miyiz? IP adresinin istenen biçimde yazılabildiği öğrenilmişti. Buna göre client'ın IP adresini kaynak adres olarak kullanıp server'a bir SYN isteği göndermek mümkündür.

Sorun şudur: server bu isteğin cevabını gerçek client'a gönderecektir. Saldırganın ise bu cevaptaki sıra numarasına ihtiyacı vardır, çünkü üçüncü mesajı gönderirken ACK değerini ona göre üretecektir.

- Sıra numaraları gerçekten düzgün (uniform) dağılımlıysa, yani rastgelelik açısından iyiyse, bu numarayı tahmin etme olasılığı $1/2^{32}$'dir; bu neredeyse imkânsızdır.
- Kullanılan sıra numaraları düzgün dağılımlı değil de öngörülebilir yapıdaysa, belirli koşullar sağlandığında numarayı tahmin etme şansı doğar.

Tahmin tutarsa saldırgan üçüncü mesajı doğru ACK değeriyle server'a gönderir. Böylece client'ın IP adresini sahte olarak kullanarak server ile başarılı bir bağlantı kurmuş olur.

### 15.2 TCP Reset Saldırısı

Mevcut bir bağlantıya reset saldırısı yapmak için gerekenler:

- Header'da RST biti set edilmiş bir paket.
- Port numaraları. Port numaraları 16 bittir ve istemci tarafında işletim sistemi bunları rastgele seçer. Ancak bilinen servislerde (80, 443, 25, 22) port numaraları zaten bilinir.
- Doğru bir sıra numarası.

Sıra numarası uzayı $2^{32}$'dir. Ama ağdaki gecikmeler, ağın büyüklüğü ve bir seferde gönderilebilen veri miktarını belirleyen pencere boyu (window size) yüzünden pencere içine düşen herhangi bir sıra numarası geçerli kabul edilir. Hoca bu kabul edilebilir aralığı yaklaşık 32K ile 64K arası olarak verdi. Bu durumda uzay pencere boyunda alt parçalara bölünmüş gibi düşünülebilir: $2^{32}$ içinde tek bir değeri aramak yerine $2^{16}$'lık bir parçayı aramak gerekir, yani deneme sayısı yaklaşık

$$
\frac{2^{32}}{2^{16}} = 2^{16} = 65536
$$

olur ve başarı ihtimali artar.

## 16. DNS

### 16.1 Hiyerarşik İsim Uzayı

Internet'in çalışmasının temelindeki protokollerden biri de DNS'tir (Domain Name Service). Slayttaki ifadeyle uygulama katmanı protokolleri ve insanlar hostlara genellikle adlarıyla (örneğin google.com) başvurur; IP adreslerini akılda tutmaya uğraşmayız (ekrandan, 01:35:00).

DNS, yetkisi devredilebilen (delegatable), hiyerarşik bir isim uzayıdır. Sorumluluk ve yetki aşağıya devredilebilir. Slayttaki ağaç:

```text
                         root
     /      /       |        \       \       \
   org    net      edu       com     uk      ca
            /     /   |    \     \
         wisc   ucb stanford  cmu   mit
                     /    \
                   cs      ee
                   |
                  www
```

Bir kök noktası vardır, altında alt alan adları (domain) vardır. Örnekte root, edu, stanford ve cs birer alan adıdır; www bir yaprak olduğu için hosttur. Root bir takım yetkileri edu'ya, edu Stanford'a, Stanford da CS'e devretmiştir.

<!-- BELİRSİZ: 01:36:19-01:36:37 arası altyazıda Whisper bozulması var; bu aralıkta anlatılan kısım okunamadı. -->

### 16.2 Kayıtlar ve Sorgu Araçları

Her DNS sunucusu, yetkili olduğu alan için bir takım kayıtlara sahiptir ve bu kayıtlar aracılığıyla cevap verir. `dig` ya da `nslookup`, bir isim sunucusuna sorgu gönderip onun ne bildiğini, bir soruya cevap verip veremediğini ve nasıl cevap verdiğini görmek için kullanılır. Slayttaki örnekte bob.ucsd.edu adının adresi ve bu alan için ns0, ns1 ve ns2.ucsd.edu adlı üç yetkili (authoritative) isim sunucusu görülüyordu.

<!-- BELİRSİZ: bob.ucsd.edu için okunan IP adresi altyazıda bozuk (beş parçalı) yazılmış; karesi yok. -->

### 16.3 Kök Sunucular ve Önbellekleme

En tepede kök isim sunucuları (root name servers) vardır. Dünya çapında 13 tanedir ve A'dan M'ye harflerle adlandırılmıştır. Büyük çoğunluğu Amerika'dadır; bunun dışında Japonya'da ve İngiltere'de olanlar vardır. Sorgular bu noktaya kadar çıkar ve oradan aşağı iner.

Bütün DNS sorgularının cevapları önbelleğe (cache) alınır; böylece DNS sistemine gelecek yük azalır. Olumsuz cevaplar da önbelleğe alınır, böylece olmayan adresler için gereksiz sorgu oluşmaz. Önbelleğe konan her verinin bir yaşam süresi (TTL) vardır; süre dolunca veri önbellekten çıkarılır.

Hocanın örneği: olumsuz cevapların önbellekte tutulma süresi 86400 olarak verildiyse bu değer saniye cinsindendir ve $86400 / 3600 = 24$ saat, yani bir gündür. O isim sunucusu yeniden başlatılmazsa bir gün boyunca aynı sorgu gelirse aynı olumsuz cevap döndürülür. Olumlu cevaplar için de aynı şey geçerlidir.

### 16.4 DNS Neden UDP Kullanır

DNS sorguları standart olarak UDP üzerinden yapılır, çünkü iş soru-cevaptır: soruyu içeren bir paket gider, cevabı içeren bir paket gelir. Aynı iş TCP ile yapılsaydı:

- Bağlantı kurulumu: 3 mesaj.
- Soru ve cevap: 2 mesaj, toplam 5.
- Bağlantının sonlandırılması: 4 mesaj, toplam 9.

UDP'de gönderilen bütün mesajlar işe yararken TCP'de 9 mesajdan yalnız 2'si asıl iştir: $2/9 \approx 0{,}22$. Hoca bunu "neredeyse beşte bir, %20 civarı verim" diye yuvarladı. DNS'i TCP üzerinden çalıştırmak mümkündür, ama çok mantıklı değildir.

### 16.5 DNS Paketi

Slayttaki bilgiler (ekrandan, 01:40:00):

- DNS istekleri UDP üzerinden gönderilir.
- Dört bölüm vardır: questions (sorular), answers (cevaplar), authority (yetki bilgisi: cevabı veren sunucu bu cevabı vermeye yetkili mi, yoksa yalnız öğrendiğini mi söylüyor) ve additional records (yardımcı ek kayıtlar).
- Query ID: 16 bitlik rastgele bir değerdir ve cevabı sorguya bağlar.

12 baytlık DNS header'ı şöyle çizilmişti:

```text
Bayt  0               1               2               3
     +-------------------------------+--+------+-------------+-----+
  0  |        Identification         |QR|Opcode|  DNS Flags  |RCode|
     |                               |  |      |AA TC RD RA Z|     |
     |                               |  |      |AD CD        |     |
     +-------------------------------+--+------+-------------+-----+
  4  |        Total Questions        |         Total Answers       |
     +-------------------------------+-----------------------------+
  8  | Total Authority Resource Rec. | Total Additional Resource R.|
     +-------------------------------+-----------------------------+
```

Aynı anda çok sayıda DNS sorgusu yapılabileceği ve bunlar UDP üzerinden gittiği için sorguları takip edebilmek ve gelen cevapları doğru sorguyla eşleştirebilmek için bir kimlik alanı gerekir. Bu Query ID'dir (Identification alanı) ve 16 bittir.

### 16.6 Örnek dig Çıktısı

Slaytta bir `dig` çıktısı incelendi. Soru 192.26.92.30 adresli sunucuya, DNS'in 53 numaralı portuna soruluyordu. Sorguda "recursion desired" (RD) isteniyordu: "sende cevap yoksa cevabı bulabilecek bir sonraki isim sunucusuna sor". Bu standart bir sorguydu (query) ve bir www adresinin IP adresi soruluyordu.

Gelen cevap şunu söylüyordu:

- Bu bir cevaptır (response), ama yetkili (authoritative) değildir; sunucu bunu yalnız öğrendiklerinden söylemektedir.
- Sunucunun recursion yapma yeteneği yoktur, bu yüzden recursion yapmamıştır.
- Elindeki bilgiyle iki yetkili kayıt döndürür: sorulan alanın isim sunucuları linux ve cs alt adlarına sahip iki sunucudur.
- "Sana iyilik olsun" diye bu iki sunucunun IP adreslerini ek kayıt (additional records) olarak gönderir; böylece soran tarafın ekstra sorgu yapmasına gerek kalmaz.

<!-- BELİRSİZ: Sorgulanan alan adı altyazıda "unix.viz.net" diye geçiyor; büyük olasılıkla unixwiz.net (isim sunucuları linux.unixwiz.net ve cs.unixwiz.net). dig çıktısının karesi yok. -->

Cevap yetkili olsaydı AA (Authoritative Answer) biti 1 olurdu. Bu, bilginin "kulaktan dolma" olmadığını; sorgulanan DNS sunucusunun gerçekten bu sorunun cevabını vermekle yetkilendirilmiş bir sunucu olduğunu, cevabı zaman içinde yaptığı sorgularla önbelleğe alarak öğrenmediğini gösterir.

> **Ek bilgi (derste anlatılmadı):** 192.26.92.30 adresi büyük olasılıkla .net ve .com alanlarının yetkili sunucularından c.gtld-servers.net'e aittir. Böyle bir üst düzey alan sunucusu genellikle son cevabı değil, alt alanın isim sunucularını gösteren bir yönlendirme (referral) döndürür; slayttaki yetkisiz cevap ve ek kayıtlar bu duruma uyar.

## Örnek Sorular

**Soru 1** (derste sözlü, 00:32:30): Ethernet Type II frame'inin en kısa ve en uzun boyu nedir, bu değerler nasıl elde edilir?

> **Çözüm:** Header 14 bayt (6 + 6 + 2), CRC 4 bayt, toplam 18 bayt ek yük. Payload 46-1500 bayt olduğundan en kısa frame $46 + 18 = 64$, en uzun frame $1500 + 18 = 1518$ bayttır.

**Soru 2** (derste sözlü, 00:46:52): `2620:0:e00:b::53` adresinde `::` kaç sıfır grubunun yerini tutar? (ekrandan, 00:45:00)

> **Çözüm:** IPv6 adresi 16 bitlik 8 gruptur. Kısaltılmış adreste 5 grup görünür; $8 - 5 = 3$ sıfır grubu eksiktir: `2620:0:e00:b:0:0:0:53`. Python `ipaddress` modülüyle doğrulandı.

**Soru 3** (derste sözlü, 00:48:23): IHL alanında 5 ve 8 değerleri varsa header kaç bayttır? En kısa ve en uzun IPv4 header'ı kaç bayttır?

> **Çözüm:** IHL 4 baytlık kelime sayısıdır: $5 \times 4 = 20$ bayt, $8 \times 4 = 32$ bayt. IHL en az 5 (20 bayt), en çok 15 olabilir: $15 \times 4 = 60$ bayt.

**Soru 4** (derste sözlü, 00:53:53): En kısa header'lı bir IPv4 paketinin ilk baytı ne olur, neden?

> **Çözüm:** İlk baytın üst 4 biti Version = 4, alt 4 biti IHL = 5'tir (20 bayt). Onaltılık olarak `0x45` olur.

**Soru 5** (derste sözlü, 01:24:19): Gönderen 404'ten başlayan 4 baytlık ve 408'den başlayan 3 baytlık iki segment gönderiyor. Alıcı tek ACK gönderirse değeri ne olur? İlk segment kaybolursa alıcı ne gönderir? (ekrandan, 01:25:00)

> **Çözüm:** $404 + 4 = 408$, $408 + 3 = 411$; tek ACK 411 olur. İlk segment kaybolursa alıcı 408-410'u almış olsa da bir sonra beklediği bayt 404 olduğundan ACK 404 gönderir. Gönderen 404 segmentini yeniden yollar ve ardından ACK 411 gelir.

**Soru 6** (derste sözlü, 01:31:18 ve 01:34:25): Sıra numarası düzgün dağılımlıysa sahte bağlantı için doğru numarayı tahmin etme olasılığı nedir? Reset saldırısında pencere boyu yaklaşık $2^{16}$ ise kaç deneme gerekir?

> **Çözüm:** Tam tahmin olasılığı $1/2^{32}$'dir. Reset saldırısında pencere içine düşen her değer geçerli sayıldığından $2^{32} / 2^{16} = 2^{16} = 65536$ deneme yeterlidir.

**Soru 7** (derste sözlü, 01:39:19): DNS sorgusu TCP ile yapılsaydı kaç mesaj gerekirdi ve verim ne olurdu?

> **Çözüm:** 3 (üçlü el sıkışma) + 2 (soru ve cevap) + 4 (sonlandırma) = 9 mesaj. Yararlı mesaj oranı $2/9 \approx 0{,}22$, yani yaklaşık %22 (hoca yaklaşık %20 dedi). UDP'de bu oran %100'dür.

## Dersin Toparlaması

Bu derste ağ güvenliğine giriş olarak TCP/IP yığını alttan üste gözden geçirildi. Fiziksel ve veri bağlantı katmanında Ethernet frame yapısı, broadcast Ethernet'ten switched Ethernet'e geçiş ve IP adresini MAC adresine çeviren ARP anlatıldı; ARP'de ilk gelen cevabın kabul edilmesinin man-in-the-middle saldırısına yol açtığı gösterildi. Ağ katmanında IPv4 ve IPv6 adresleri ile IPv4 header'ının alanları incelendi. En önemli tespit, router'ların yalnız hedef adrese bakması ve kaynak adresin gönderen tarafından istendiği gibi yazılabilmesiydi. IP'nin sıralama, yeniden gönderme, onay, bağlantı ve güvenlik sağlamadığı vurgulandı; Pakistan Telecom'un 2008'deki BGP duyurusu, doğrulama eksikliğinin bütün dünyayı nasıl etkileyebileceğine örnek verildi.

Taşıma katmanında portlar, UDP'nin bağımsız paket yaklaşımı ve TCP'nin bağlantı yönelimli, sıralı ve güvenilir akışı anlatıldı: sıra numarası ve ACK hesabı, üçlü el sıkışma, dört mesajlı sonlandırma ve RST ile sıfırlama. Bunların üzerine sıra numarası tahminiyle sahte bağlantı kurma ve pencere boyunun kolaylaştırdığı reset saldırısı fikirleri ortaya kondu. Son olarak DNS'in hiyerarşik ve devredilebilir yapısı, kök sunucular, önbellekleme ve TTL, UDP kullanımının gerekçesi ve DNS paketinin yapısı incelendi. Hoca sonraki derste bu protokollere yönelik saldırıların ve tedbirlerin ayrıntılı olarak incelenmesinin planlandığını belirtti.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
