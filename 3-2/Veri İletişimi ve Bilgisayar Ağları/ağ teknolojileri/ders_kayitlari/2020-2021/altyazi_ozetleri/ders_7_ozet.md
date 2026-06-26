# Ders 7 Çalışma Özeti

## Genel Konular

- IP ile İlgili Yardımcı Protokoller
  - IP tek başına yeterli değildir; yönetim, hata bildirimi, otomatik konfigürasyon gibi işler için yardımcı protokoller gerekir.
  - **ICMP (Internet Control Message Protocol)**: Network katmanının kontrol ve yönetimi için.
  - **ARP (Address Resolution Protocol)**: IP adresini MAC adresine çevirmek için.
  - **DHCP (Dynamic Host Configuration Protocol)**: IP adresi, subnet mask, gateway, DNS sunucusu gibi bilgileri otomatik dağıtmak için.

- ICMP Mesaj Türleri
  - **Echo / Echo Reply**: Ping komutunun temeli; karşı tarafın ayakta olup olmadığını kontrol eder.
  - **Destination Unreachable**: Hedef router tarafından "ulaşılamaz" bildirimi; ayrıca "Don't Fragment" biti set edilmiş ve parçalanması gereken bir paket için de kullanılır.
  - **Time Exceeded**: TTL 0 olunca veya parça zamanında gelmeyince gönderilir; traceroute komutu bu mantıkla çalışır.
  - **Redirect**: Router, host'a "daha iyi bir yol var" bilgisi gönderir; routing optimizasyonu sağlar.
  - **Parameter Problem**: Header'da beklenmeyen bir değer varsa.
  - **Source Quench**: Tıkanıklık bildirimi (artık kullanılmıyor; TCP bunu ECN ile yapar).
  - **Router Advertisement / Solicitation**: Host'un yerel router'ları keşfetmesi için (DHCP olmadan).

- ARP (Address Resolution Protocol)
  - IP paketi yerel ağda gönderilirken, hedef IP'nin MAC adresi bilinmelidir.
  - ARP broadcast yapar: "192.168.1.5 kim? MAC adresinizi söyleyin."
  - Tüm hostlar broadcast'ı alır; sadece hedef IP'ye sahip olan cevap verir.
  - Cevapta kaynak MAC adresi de yer aldığı için, diğer hostlar da bu bilgiyi kendi ARP tablolarına ekler (öğrenme yan etkisi).
  - ARP tablosunda entry'ler yaşam süresine (TTL) sahiptir; çünkü hostlar kapanıp açılabilir, ethernet kartı değişebilir.
  - **Proxy ARP**: Bazı durumlarda, bir host başka bir host'un MAC adresi için cevap verebilir (örn. mobil IP'de home agent).

- DHCP (Dynamic Host Configuration Protocol)
  - Bir host'un IP'ye dahil olması için gereken bilgiler: IP adresi, subnet mask, gateway, DNS sunucu adresi (en az 1, tercihen 2).
  - Bu bilgiler hardcoded olabilir (küçük, statik ağlarda), ama büyük, dinamik ağlarda DHCP gerekir.
  - DHCP 4 aşamalı süreç (kısaca): Discover → Offer → Request → Acknowledge.
  - DHCP server, IP havuzundan (pool) rastgele veya belirli bir MAC adresine rezerve edilmiş bir adres verebilir.
  - Lease time: verilen adresin geçerlilik süresi; süre dolmadan yenilenmelidir.
  - BootP, DHCP'nin öncülüdür; günümüzde yerini DHCP'ye bırakmıştır.

- MPLS (Multiprotocol Label Switching)
  - Datagram (connectionless) network'lerde, circuit-switched hızına yakın switching yapmak için geliştirilmiş.
  - Paketlerin başına 32-bit label eklenir; router'lar IP yerine label'a bakar (en hızlı lookup).
  - Label formatı: 20 bit label + 3 bit QoS + 8 bit TTL + 1 bit stack.
  - Tek hop için anlamsız; birden fazla hop'ta faydalı (toplu switching).
  - Datagram ağ üzerinde virtual circuit benzeri davranış sağlar.

- OSPF (Open Shortest Path First)
  - Standart interior routing protokolü; TCP/IP suitinde kabul görmüş.
  - Link state routing'in implementasyonu; dağıtık Dijkstra kullanır.
  - Hierarchical yapı: Otonom sistemler (AS), her AS alanlara bölünür (area 0 = backbone).
  - Backbone router'lar alanlar arası trafiği yönetir; internal router kendi alanı içinde kalır.

- BGP (Border Gateway Protocol)
  - Exterior routing protokolü; farklı otonom sistemler arası.
  - Teknik kriterlerden çok politik, ticari, kurumsal kurallara dayanır.
  - Örnek: Eğitim ağı üzerinden ticari trafik aktarılamaz; Apple siteleri arası trafik Google üzerinden geçemez.
  - Internet'in "yapıştırıcısı"dır; sınır kapısı gibi düşünülebilir.

## Hocanın Özellikle Vurguladığı Kısımlar

- ICMP'nin network katmanı içinde taşınması
  - ICMP mesajları normal IP paketleri gibi taşınır; ancak hedefteki IP katmanı bunları tanır ve cevap verir. Üst veya alt katmana etkisi yoktur.

- ARP tablosunun yaşam süresi
  - TTL olmadan ARP tablosu hatalı kalır; hostlar kapanabilir, ethernet kartı değişebilir. Bu nedenle entry'ler periyodik olarak temizlenir.

- DHCP'nin vize haftası öncesi vurgusu
  - Hoca, vizede sorulabilecek DHCP bilgisi olarak; adres, maske, gateway, DNS sunucu kavramlarını netleştirir.

- MPLS'in "ne işe yaradığı"
  - Datagram network'te, normalde her router'da IP lookup yapılır (longest prefix matching). MPLS, paketleri birleştirip (aggregate) tek bir label ile yoluna devam ettirir; router'lar sadece label'a bakar. Bu, core router'larda büyük performans artışı sağlar.

- BGP'nin "yönetimsel" doğası
  - Teknik kriterler (hız, bant genişliği, gecikme) dışında politik, ticari, kurumsal kısıtlar vardır. BGP bu kuralların ifade edilebileceği bir protokoldür.

## Kısa Tekrar Notları

- ICMP: network katmanı kontrol protokolü
- ARP: IP → MAC çözümlemesi (broadcast)
- DHCP: dinamik IP konfigürasyonu; Discover/Offer/Request/Ack
- TTL (ARP tablosunda da var)
- MPLS: label switching; en hızlı routing kararı
- OSPF: link state, interior, area 0 backbone
- BGP: exterior, politik kurallar

## Detaylı Açıklamalar

Bu derste IP'nin etrafındaki yardımcı protokoller öğretilir. ICMP, IP'nin "hata bildirim" mekanizmasıdır. Bir paket hedefe ulaşamıyorsa, aradaki bir router ICMP Destination Unreachable mesajı gönderir. Benzer şekilde, TTL sıfırlanırsa Time Exceeded gönderilir. Ping, ICMP Echo/Echo Reply'in uygulama seviyesindeki kullanımıdır. Traceroute ise Time Exceeded'in yaratıcı bir kullanımıdır: artan TTL değerleriyle paket gönderilir, her router'da Time Exceeded alınır, böylece yol üzerindeki tüm router'lar keşfedilir.

ARP, network katmanı ile data link katmanı arasındaki "çeviri" protokolüdür. Network katmanı IP adresiyle ilgilenir, data link katmanı MAC adresiyle. Yerel ağda bir paket gönderebilmek için hedef IP'nin MAC adresini bilmek gerekir. ARP broadcast ile bunu sorgular. Önemli bir detay: ARP tablosu statik değildir; entry'lerin yaşam süresi vardır çünkü ağda her an değişiklikler olabilir. Örneğin, bir laptop'un ethernet kartı bozulup yenisi takılırsa, eski MAC adresi geçersiz olur.

DHCP, modern ağların vazgeçilmez bileşenidir. Bir üniversite kampüsünde 10.000 öğrenci var; her birinin IP'sini, subnet maskesini, gateway'ini, DNS'ini manuel olarak yapılandırmak imkansızdır. DHCP, bu bilgileri otomatik dağıtır. Süreç basittir: yeni bağlanan host "DHCP Discover" yayını yapar; DHCP server "Offer" ile cevap verir; host "Request" ile seçtiği teklifi kabul eder; server "Acknowledge" ile onaylar. Bu sürecin sonunda host tüm gerekli konfigürasyona sahip olur.

MPLS, modern internet omurgasında yaygın kullanılan bir teknolojidir. Temel fikir: datagram (connectionless) network'lerde bile, paketleri bir "virtual circuit" mantığıyla yönlendirmek. Bunun için her pakete kısa bir label eklenir; router'lar uzun IP prefix matching yerine sadece label'a bakar. Bu, yüksek hızlarda büyük performans artışı sağlar. MPLS aynı zamanda QoS (Quality of Service) için de temel sağlar; label içindeki 3-bit QoS alanı, paketin önceliğini belirtir.

OSPF ve BGP, internet'in iki routing seviyesini oluşturur. OSPF, bir organizasyonun kendi iç ağında kullanılır; alanlara (area) bölünmüş hiyerarşik bir yapıdadır, area 0 her zaman backbone'dur. BGP, farklı organizasyonların ağları arası routing için kullanılır; burada teknik kriterler yerine politik, ticari, kurumsal kurallar ön plana çıkar.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
