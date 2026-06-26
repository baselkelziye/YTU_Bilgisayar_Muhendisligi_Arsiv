# Ders 6 Çalışma Özeti

## Genel Konular

- Dünya İnternet Topolojisi
  - İnternet, omurga (backbone) ağlardan bölgesel, ulusal, kurumsal ağlara; oradan da ev/mobil ağlara kadar hiyerarşik bir yapıdır.
  - Backbone router'lar arası bağlantılar yüksek kapasiteli (kalın hat), alt seviyelerdeki bağlantılar daha düşük kapasitelidir.
  - Türkiye'nin ulusal ağı da benzer şekilde uluslararası bağlantılara sahiptir; ULAKBİM, TT, vb. kurumlar bu yapıda yer alır.
  - Ev ağlarındaki "ADSL router" aslında sınırlı özelliklere sahip bir uç cihazıdır; gerçek router işlevi görmez.

- IPv4 Protokol Başlığı (Header)
  - Toplam 20-60 byte (standart 20 byte + opsiyonel alanlar).
  - **Version (4 bit)**: 4 (IPv4). Tek sayılı versiyonlar (1, 3, 5) test için; çift sayılılar (2, 4, 6) sahada kullanılır.
  - **IHL (Internet Header Length, 4 bit)**: Header uzunluğunu 32-bit word cinsinden verir (min 5 = 20 byte, max 15 = 60 byte).
  - **Total Length (16 bit)**: Header + veri uzunluğu; max 65.535 byte.
  - **Identification, Flags, Fragment Offset**: Parçalama için kullanılır.
  - **TTL (Time To Live, 8 bit)**: Paketin kaç hop geçebileceğini belirtir; orijinalde saniye cinsinden tanımlanmış, pratikte hop sayısı olarak kullanılır. Her router'da 1 azalır, 0 olunca paket düşürülür.
  - **Protocol (8 bit)**: Üst katmandaki protokolü belirtir (TCP=6, UDP=17, ICMP=1).
  - **Header Checksum (16 bit)**: Sadece header hata kontrolü; veri değil. 1-bit hataları yakalar, çok-bit hataları kaçırabilir.
  - **Source Address, Destination Address (her biri 32 bit)**: IP adresleri.
  - **Options**: Değişken uzunluklu, deneysel amaçlı.

- Byte Order (Endianness) Sorunu
  - IP, SPARC işlemcisi ve SunOS üzerinde tasarlanmıştır; Big Endian (network byte order) kullanır.
  - Modern Intel işlemcileri Little Endian kullanır; dönüşüm gerekir (htonl, htons fonksiyonları).
  - IPv6 da Big Endian'dır; IPv4 ile uyumlu kalmak için.

- IP Adres Sınıfları (Classful Addressing)
  - 1980'lerde tasarlanmış, sınırlı sayıda network'ün düşünüldüğü bir yapı:
    - **A sınıfı**: 8 bit network + 24 bit host; 128 network, 16M host.
    - **B sınıfı**: 16 bit network + 16 bit host; 16K network, 65K host.
    - **C sınıfı**: 24 bit network + 8 bit host; 2M network, 256 host.
    - **D sınıfı**: Multicast (224.0.0.0 - 239.255.255.255).
    - **E sınıfı**: Gelecek kullanım için ayrılmış.
  - ABC sınıflama dünya genelinde yayılınca yetersiz kaldı; classless (CIDR) yapıya geçildi.

- Subnet Mask ve Prefix Notation
  - Classless yapıda, network ve host kısımları sınıf bazlı değil, prefix uzunluğu ile belirlenir: 192.168.0.0/24 (24 bit prefix = network, 8 bit = host).
  - Subnet mask: 1'lerden oluşan bit sayısı prefix uzunluğunu gösterir. Kesintisiz olmalıdır.
  - Alt ağlar (subnet) oluşturmak için daha büyük bir network bölünebilir (örneğin bir üniversitenin /16 prefix'i, bölümler için /24'lere bölünebilir).

## Hocanın Özellikle Vurguladığı Kısımlar

- Versiyon numaralarının stratejisi
  - IP'de tek numaralı versiyonlar (1, 3, 5) test/development için; çift numaralılar (4, 6) sahada kullanılır. Bu, geliştirme ve deployment'ı ayırır.

- IPv4'ün hâlâ kullanımda olması
  - 1990'larda IPv6 ortaya atıldı, ama 30 yıl geçmesine rağmen hâlâ IPv4 kullanılıyor. Geçiş planları (2001, 2005, 2008, 2011) hep ertelendi.
  - IPv6'nın tamamen IPv4'ün yerini alması gerekiyordu ama bu gerçekleşmedi.

- IP'nin Big Endian oluşunun nedeni
  - IP, SPARC işlemcisi üzerinde geliştirildi; SPARC Big Endian'dır. Bu yüzden network byte order = Big Endian. Günümüzde çoğu işlemci Little Endian olduğu için dönüşüm hâlâ yapılıyor.

- Classful'ın yetersizliği
  - Hoca, kendi üniversitesinin (YTÜ) 1993'te C sınıfı adres aldığını, ABD merkezli düşünülen ABC sınıflamasının dünya genelinde yayılınca yetersiz kaldığını vurgular.

## Kısa Tekrar Notları

- Backbone: yüksek kapasiteli omurga ağlar
- IPv4 header: 20 byte minimum, 32 bit toplam uzunluk
- TTL: hop sayısı; 0 olunca paket düşürülür
- Protocol field: TCP=6, UDP=17, ICMP=1
- Byte order: Big Endian (network) vs Little Endian (host)
- IP sınıfları: A(0), B(10), C(110), D(1110 multicast), E(1111 reserved)
- Classless CIDR: prefix uzunluğu ile adresleme
- Subnet mask: kesintisiz 1'ler

## Detaylı Açıklamalar

Ders, internetin fiziksel topolojisinden başlayıp IP protokol detaylarına iner. Hoca önce büyük resmi çizer: dünya üzerinde birçok backbone ağı var (ABD, Avrupa, Asya); bunlar arasında kiralık hatlarla veya denizaltı kablolarıyla bağlantı kurulmuş. Bu omurga ağlardan bölgesel ağlara, oradan da son kullanıcıya (ev/kurum) ulaşılır. Her seviyede bağlantı kapasitesi düşer.

IPv4 header'ı, IP'nin en temel yapı taşıdır. Her alan önemli bir amaca hizmet eder. Version alanı protokolün uyumluluğunu sağlar; IHL header'ın nerede bittiğini gösterir; Total Length tüm paketin boyutunu verir; TTL paketin sonsuza kadar dolaşmasını engeller (yönlendirme döngüsü durumunda); Protocol üst katmanın hangi protokol olduğunu söyler (bu sayede IP aynı datagram içinde farklı protokolleri taşıyabilir); Header Checksum header'ın bozulmadığını garanti eder (sadece header, veri için değil); Source/Destination adresleri routing için kullanılır.

Byte order konusu, öğrencilerin sıklıkla karıştırdığı bir noktadır. IP, 1980'lerde SPARC işlemcisi üzerinde geliştirildi. SPARC Big Endian kullanır (en anlamlı byte en düşük adreste). Bu yüzden network üzerinden gönderilen tüm sayılar Big Endian formatındadır. Günümüzde ise çoğu bilgisayar Intel/AMD işlemcisi kullanır ve bunlar Little Endian'dır. Bu yüzden programlama sırasında dönüşüm fonksiyonları (htonl, htons, ntohl, ntohs) kullanılır. IPv6 da IPv4 ile uyumlu kalmak için Big Endian'dır.

Adres sınıfları (classful), internet'in ilk tasarımından kalan bir mirastır. ABD merkezli düşünülmüş, sınırlı sayıda büyük network varsayılmıştır. Ancak internet tüm dünyaya yayılınca, sınıfların esnek olmaması (her kurum için tam A, B veya C sınıfı ayrılamaması) sınıflama sistemini yetersiz kıldı. Çözüm: CIDR (Classless Inter-Domain Routing) — artık prefix uzunluğu (örn. /24) ile adres blokları tanımlanır; sınıf kavramı yoktur. Ancak eski sınıflar hâlâ tanınır (geriye uyumluluk için).

Subnet'leme, büyük bir network bloğunu daha küçük parçalara bölme işlemidir. Örneğin, bir üniversitenin /16 prefix'i (örn. 144.122.0.0/16) varsa, fakültelere /24 prefix'leri (örn. 144.122.1.0/24, 144.122.2.0/24) atanabilir. Bu, routing'i de kolaylaştırır: dış dünya sadece /16'yı bilir, iç yapıyı üniversitenin router'ları yönetir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
