# Ders 5 Çalışma Özeti

## Genel Konular

- İnternetworking ve Farklı Ağların Birleştirilmesi
  - Farklı teknolojilere sahip ağların (Ethernet, 802.11 WiFi, MPLS, hücresel) birlikte çalışabilmesi için üst seviyede bir protokol gerekir; bu, IP (Internet Protocol) katmanıdır.
  - Ağ geçişlerinde karşılaşılan temel sorunlar:
    - Paket boyutu farklılıkları (Ethernet ~1500 byte, 802.11 daha küçük)
    - Adresleme format farklılıkları
    - Connection-oriented (MPLS) vs connectionless (Ethernet) yapılar
  - IP router, üst katmandan gelen veriyi paket olarak alır, hedef ağa uygun formata dönüştürür ve iletir.

- IP'nin Ortaya Çıkışı ve Standartlaşma
  - İnternet 1960'ların sonu-1980'lerin başında Amerika'da DARPA projesi olarak 5 üniversitenin işbirliğiyle geliştirildi.
  - Amaç: nükleer saldırı gibi felaket senaryolarında bile çalışmaya devam edebilen bir bilgisayar ağı.
  - ARPANET → ticari kurumlar → bireysel kullanıcılar → dünya genelinde yayılma.
  - Farklı protokoller (IPX, AppleTalk, SNA) denenmiş olsa da IP standart olmuştur.

- Paket Fragmentasyonu (Parçalama)
  - Bir paket, hedef ağın izin verdiği maksimum boyuttan (MTU) büyükse parçalanmalıdır.
  - İki strateji:
    - Transparent fragmentasyon: Her ağ geçişinde parçalanır, hedefe yakın router'da tekrar birleştirilir.
    - Non-transparent fragmentasyon: Parçalar yol boyunca küçülebilir, sadece hedef host'ta birleştirilir.
  - Avantajlar/dezavantajlar: Transparent'ta her router parçalanmış paketleri saklamak zorunda; non-transparent'ta parçalar yol boyunca bağımsız hareket eder, kayıp riski daha yüksek.
  - IP paket teorik olarak 65.535 byte'a kadar büyüyebilir; pratikte her ağın MTU sınırı vardır.

- Tunnelling (Tünelleme) ve Overlay Ağlar
  - Farklı ağlar arasında geçiş yapmak için, bir protokolün paketi başka bir protokolün payload'ı içine yerleştirilebilir.
  - Örnek: IPv6 paketi IPv4 ağı üzerinden taşınırken IPv4 paketine encapsulate edilir.
  - Paris-Londra ofisleri arasında IPv6 kullanmak için, ortadaki IPv4 ağında tünel açılır.
  - Tünelleme + şifreleme = VPN (Virtual Private Network) yapısı.

- Routing'in İki Seviyesi
  - **Intradomain routing (Interior Gateway Protocol)**: Bir organizasyonun (şirket, üniversite) kendi iç ağında kullanılan routing; herkes istediği protokolü kullanmakta serbest.
  - **Interdomain routing (Exterior Gateway Protocol)**: Farklı organizasyonlar arası routing; internet ölçeğinde ortak protokol gerekir (BGP).

## Hocanın Özellikle Vurguladığı Kısımlar

- Farklı network'lerin birleştirilmesinin zorlukları
  - Her network'ün kendine özgü yapısı, MTU'su, adresleme formatı vardır. Bunları birleştirmek için katmanlı yaklaşım (overlay) gerekir; IP bu rolü üstlenir.
  - Aynı network içinde bile routing farklı olabilir; Distance Vector, Link State, Path Vector gibi farklı algoritmalar kullanılabilir.

- Hoca, "unutmayın" vurgusu
  - Karmaşık konularda öğrencilerin kafasının karışmaması için, "bu ve şu aslında benzer şeyler, farklı terminolojiler" gibi hatırlatmalar yapar.

- IP'nin başarısının sırrı
  - IP, "her şeyi IP üzerinden yap" stratejisinin başarısıdır. 20+ yıldır IPv4 hâlâ kullanılmaktadır; IPv6'ya geçiş hâlâ tamamlanmamıştır.

## Kısa Tekrar Notları

- İnternetworking: farklı ağları birleştirme
- IP: ağlar arası ortak dil
- Fragmentasyon: transparent vs non-transparent
- Overlay/tünelleme: bir protokolü başka protokol içine sarmalama
- VPN: tünelleme + şifreleme
- Interior vs Exterior routing
- MTU: her ağın maksimum paket boyutu

## Detaylı Açıklamalar

Bu ders internetworking kavramını tanıtır. Temel fikir: dünya üzerinde farklı teknolojilere sahip birçok ağ vardır (Ethernet kablolu ağlar, WiFi ağları, hücresel ağlar, uydu ağları, MPLS ağları). Bunların hepsi farklı özelliklere sahiptir. Bu ağların birbirleriyle iletişim kurabilmesi için ortak bir dil gerekir; bu dil IP'dir.

Hoca, gerçek bir senaryoyla açıklar: Paris ve Londra'daki iki ofis IPv6 kullanmak istiyor. Ancak aradaki ISP ağı sadece IPv4 destekliyor. Çözüm: Paris'te IPv6 paketi IPv4 paketi içine sarılır (encapsulation), hedefe ulaşana kadar IPv4 ağı üzerinden taşınır, Londra'da tekrar IPv6 paketi açılır. Bu, tünelleme (tunnelling) yöntemidir. Şifreleme de eklenirse VPN (Virtual Private Network) elde edilir.

Fragmentasyon konusu önemlidir. Her ağın MTU (Maximum Transmission Unit) değeri farklıdır. Ethernet tipik olarak 1500 byte'lık frame kullanır; bazı ağlar daha küçük MTU'ya sahiptir. Eğer büyük bir paket daha küçük MTU'lu bir ağa gelirse, parçalanması gerekir. IP iki stratejiyi destekler: transparent (her router'da parçalanır, hedefe yakın router'da birleştirilir) ve non-transparent (parçalar yol boyunca küçültülebilir, sadece hedefte birleştirilir). Non-transparent'ta her parça bağımsız hareket ettiğinden bir parça kaybolursa tüm paket kaybedilmiş sayılır; bu yüzden güvenilir olmayan ağlarda risklidir.

Routing'in iki seviyede yapılması, internet'in ölçeklenebilirliği için kritiktir. Bir kurumun kendi iç ağında (intradomain) herhangi bir routing protokolü kullanılabilir (RIP, OSPF, IS-IS). Ancak farklı kurumların ağları arasında (interdomain) ortak bir protokol gerekir; bu BGP'dir (Border Gateway Protocol). Hoca, "her network'ün kendi routing fikri olabilir, ama genel internet için ortak bir protokol şart" der.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
