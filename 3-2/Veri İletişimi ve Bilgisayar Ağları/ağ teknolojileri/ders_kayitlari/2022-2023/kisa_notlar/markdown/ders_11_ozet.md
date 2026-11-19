# Ders 11 Çalışma Özeti

## Genel Konular

- Ağ katmanının iki parçası ve dersin yeri
  - Ağ katmanı veri düzlemi (data plane) ve kontrol düzlemi (control plane) olarak ikiye ayrılır. Veri düzlemi tek bir yönlendiricinin içinde olanlarla (iletim, anahtarlama) ilgilenir.
  - Önceki derste iletim (forwarding) ve üç anahtarlama türü (yazılım/bellek tabanlı, veri yolu, anahtarlama dokusu) ile IP datagram biçimi ve adresleme işlenmişti. Bu derste NAT, IPv6, genelleştirilmiş iletim (SDN, OpenFlow) ve ara kutular (middlebox) anlatıldı, sonra kontrol düzlemine giriş yapıldı (ekrandan, 00:05:00).
- NAT (Network Address Translation, ağ adresi dönüştürme)
  - IPv4 adresleri 32 bittir ve tükenmiştir. NAT ile yerel ağdaki bütün cihazlar dış dünyaya karşı tek bir IPv4 adresini paylaşır.
  - Özel (private) adres blokları yalnız yerel ağda kullanılır, internette yönlendirilmez: `10/8`, `172.16/12`, `192.168/16` (ekrandan, 00:10:00).
  - Avantajları: ISS'den tek bir IP yeterlidir; yerel cihazların adresi dış dünyaya bildirmeden değiştirilebilir; ISS değiştirilince yerel adresler değişmez; yerel cihazlar dışarıdan doğrudan adreslenemez, bu da güvenlik sağlar (ekrandan, 00:10:00).
- NAT'ın çalışması
  - Giden datagramda NAT yönlendiricisi kaynak IP ve kaynak portu (NAT IP adresi, yeni port) ile değiştirir ve bu eşlemeyi NAT dönüştürme tablosuna yazar.
  - Gelen cevapta hedef alanındaki (NAT IP, yeni port) tablodan bakılarak özgün (yerel IP, yerel port) ile değiştirilir.
  - Derste örnek: 10.0.0.1:3345 adresli konak 128.119.40.186:80 web sunucusuna istek gönderir; NAT yönlendiricisi kaynağı 138.76.29.7:5001 yapar, tabloya "138.76.29.7, 5001 ↔ 10.0.0.1, 3345" satırını ekler (ekrandan, 00:15:00).
- NAT'ın tartışmalı yönleri
  - Yönlendirici yalnız 3. katmana kadar işlem yapmalıdır; NAT 4. katman başlığındaki portu da değiştirir.
  - Adres sıkıntısının asıl çözümü IPv6'dır; NAT IPv4'ün ömrünü uzatıp IPv6'ya geçişi geciktirir.
  - Uçtan uca ilkesini (end-to-end argument) bozar: yerel adresli cihazlara dışarıdan doğrudan erişilemez.
  - NAT arkasındaki bir sunucuya dışarıdan bağlanmak (NAT traversal) sorundur; arkada birden çok web sunucusu varsa standart 80 numaralı portu yalnız biri kullanabilir.
  - Buna rağmen NAT yaygındır; özellikle 4G/5G hücresel ağlarda operatörler IPv4 ve NAT kullanır.
- IPv6
  - Asıl motivasyon: 32 bitlik IPv4 adres alanının tükenmesi. IPv6 adresi 128 bittir.
  - Ek motivasyon: işleme ve iletim hızı. Başlık 40 bayt ve sabit uzunluktadır, isteğe bağlı alan ve başlık uzunluğu alanı yoktur.
  - Akış etiketi (flow label) ve öncelik (priority) alanlarıyla aynı akıştaki datagramlar tanımlanıp farklı işlem görebilir.
  - IPv4'te olup IPv6'da olmayanlar: sağlama toplamı (checksum) kaldırılmıştır, böylece yönlendiricide işlem hızlanır. <!-- BELİRSİZ: 00:23:07 civarında altyazı bozuk; parçalama (fragmentation) ve seçenekler (options) alanlarının kaldırıldığı anlatılmış olabilir, karede görülmedi. -->
- IPv4'ten IPv6'ya geçiş ve tünelleme
  - Bütün yönlendiriciler aynı anda yükseltilemez, "bayrak günü" (flag day) yoktur; IPv4 ve IPv6 bir arada yaşar (ekrandan, 00:25:00).
  - Çözüm tünellemedir: IPv6 datagramı, IPv4 datagramının yükü (payload) olarak taşınır. Hücresel ağlarda yaygındır.
  - Derste örnek: A ve F yalnız IPv6, B ve E hem IPv6 hem IPv4 (köprü), C ve D yalnız IPv4 yönlendiricidir. A'dan F'ye giden IPv6 datagramı (flow X, src A, dest F) B'de src B, dest E olan bir IPv4 datagramının içine konur; E'de içinden çıkarılıp F'ye iletilir (ekrandan, 00:30:00).
- IPv6'nın yayılması
  - Google'a göre istemcilerin yaklaşık %30'u hizmetlere IPv6 ile erişir; NIST'e göre ABD devlet alan adlarının yaklaşık üçte biri IPv6 yeteneklidir. Yayılma çok yavaştır (25 yıldır sürüyor).
  - Bu sürede uygulamalar (web, sosyal medya, akış medyası, oyun, telekonferans) çok değişti; yeni ihtiyaçlar ağ katmanı değiştirilmeden taşıma ve uygulama katmanında yeni protokollerle karşılandı.
- Genelleştirilmiş iletim: eşle + eylem (match plus action)
  - Her yönlendiricide bir iletim tablosu (akış tablosu, flow table) vardır. Hedef tabanlı iletimde yalnız hedef IP adresine bakılır (en uzun önek eşleme).
  - Genelleştirilmiş iletimde bağlantı, ağ ve taşıma katmanındaki birçok başlık alanı eşlenebilir; birçok eylem mümkündür: düşür (drop), kopyala, değiştir, kaydet (log), ilet, denetleyiciye gönder (ekrandan, 00:35:00).
  - Kurallara öncelik ve sayaçlar (paket ve bayt sayısı) eklenebilir.
- OpenFlow örnekleri (ekrandan, 00:40:00)
  - Hedef tabanlı iletim: IP Dst 51.6.0.8 olan datagramlar çıkış portu 6'ya iletilir.
  - Güvenlik duvarı: TCP hedef portu 22 (SSH) olan bütün datagramlar düşürülür.
  - Güvenlik duvarı: IP Src 128.119.1.1 olan konaktan gelen bütün datagramlar düşürülür.
  - 2. katman hedef tabanlı iletim: belirli bir hedef MAC adresine giden çerçeveler belirli bir porta yönlendirilir.
- Eşle + eylem soyutlamasının birleştirici gücü
  - Yönlendirici: en uzun hedef IP önekini eşle, çıkış bağlantısına ilet.
  - Anahtar (switch): hedef MAC adresini eşle, ilet ya da taşır (flood).
  - Güvenlik duvarı: IP adresi ve TCP/UDP port numarasını eşle, izin ver ya da reddet.
  - NAT: IP adresi ve portu eşle, adresi ve portu yeniden yaz.
- Ara kutular (middleboxes)
  - RFC 3234 tanımı: kaynak ve hedef arasındaki veri yolunda, standart bir IP yönlendiricisinin işlevleri dışında işlev yapan her ara cihaz. <!-- BELİRSİZ: Hoca RFC numarasını "3331" gibi okudu; doğrusu büyük olasılıkla RFC 3234. -->
  - Örnekler: NAT (ev, hücresel, kurum), güvenlik duvarı ve IDS (kurum, servis sağlayıcı, ISS), yük dengeleyici (servis sağlayıcı, veri merkezi, mobil ağ), uygulamaya özel hizmetler (CDN), önbellekler ve vekil sunucular (ekrandan, 00:45:00).
  - Önceleri kapalı, tescilli donanımlardı; şimdi açık API'li "beyaz kutu" donanımlara, SDN'de mantıksal merkezi denetime ve NFV (ağ işlevlerinin sanallaştırılması) ile beyaz kutu üzerinde programlanabilir hizmetlere geçildi.
- İnternetin kum saati ve mimari ilkeleri
  - Kum saatinin üstünde çok sayıda uygulama protokolü (HTTP, SMTP, RTP, QUIC, DASH), taşımada TCP ve UDP, altta çok sayıda bağlantı ve fiziksel teknoloji vardır; ortada yalnız IP bulunur. İnternete bağlı her cihazda IP olmak zorundadır.
  - NAT, IPv6, OpenFlow/SDN ve ara kutularla kum saatinin ince "beli" biraz kalınlaştı.
  - RFC 1958: "amaç bağlanabilirlik, araç İnternet Protokolü, zekâ ise ağın içinde gizli değil uçtan ucadır" (ekrandan, 00:50:00). Üç temel taş: basit bağlanabilirlik, her cihazda IP, zekâ ve karmaşıklığın ağın kenarında olması.
  - Uçtan uca argümanı: güvenilir veri aktarımı, tıkanıklık denetimi gibi işlevler ağın içinde ya da kenarda gerçekleştirilebilir.
  - 20. yüzyıl telefon ağında (PSTN) zekâ ağdaydı, telefon cihazının "beyni" yoktu; internette zekâ kenardaydı, bugün ise ağdaki cihazlar da programlanabilir hâle geldi.
- Kontrol düzlemine giriş (5. bölüm)
  - Amaç: kontrol düzleminin ilkeleri; geleneksel yönlendirme algoritmaları, SDN denetleyicileri, ağ yönetimi ve yapılandırması; internetteki karşılıkları: OSPF, BGP, OpenFlow, ODL, ONOS denetleyicileri, ICMP, SNMP, YANG, NETCONF.
  - İletim (forwarding) bir paketi yönlendiricinin giriş portundan uygun çıkış portuna taşımaktır (veri düzlemi). Yönlendirme (routing) paketin kaynaktan hedefe izleyeceği yolu belirlemektir; küresel bir problemdir (kontrol düzlemi).
  - İki yaklaşım: yönlendirici başına denetim (her yönlendiricide yönlendirme algoritması çalışır, yönlendiriciler mesajlaşarak yerel iletim tablolarını oluşturur) ve mantıksal merkezi denetim (uzak denetleyici tabloları hesaplar, SDN).
  - Yönlendirme protokolünün amacı: gönderen konaktan alıcı konağa yönlendiriciler ağı üzerinden "iyi" yollar bulmak. Yol (path), paketin geçtiği yönlendirici dizisidir. "İyi": en az maliyetli, en hızlı ya da en az tıkanık (ekrandan, 01:00:00). Yönlendirme ağ alanının ilk 10 zorluğundan biridir.

## Hocanın Özellikle Vurguladığı Kısımlar

- NAT'ın dört temel işi
  - Giden datagramda kaynak (IP, port) değiştirilir; eşleme tabloya yazılır; gelen datagramda hedef (NAT IP, yeni port) tablodan özgün değere çevrilir. Hedef IP ve hedef port giderken hiç değişmez.
- NAT neden tartışmalı?
  - Port 4. katman bilgisidir; NAT ağ katmanında kalmaz, taşıma katmanı başlığını da değiştirir. Uçtan uca ilkesini bozar ve IPv6'ya geçişi geciktirir.
- Tünellemede adresler
  - IPv6 datagramının içindeki kaynak/hedef (A→F) hiç değişmez; IPv4 ağı içinde dış başlığın kaynak/hedefi köprü yönlendiricilerdir (B→E).
- Eşle + eylem tek bir soyutlamayla yönlendirici, anahtar, güvenlik duvarı ve NAT'ı birleştirir
  - OpenFlow cihazı akış tablosundaki kurala göre bu cihazlardan herhangi biri gibi davranabilir.
- İnternetin beli IP'dir
  - Her cihazda HTTP ya da TCP olmak zorunda değildir ama IP mutlaka vardır.

## Kısa Tekrar Notları

- Özel IPv4 blokları: `10/8` ($2^{24}$ adres), `172.16/12` ($2^{20}$ adres), `192.168/16` ($2^{16}$ adres).
- NAT: tek dış IP, çok yerel cihaz; NAT dönüştürme tablosu (WAN adresi, port) ↔ (LAN adresi, port).
- NAT sorunları: 4. katmana dokunur, uçtan uca ilkesini bozar, NAT arkasındaki sunucuya erişim zordur, IPv6'yı geciktirir.
- IPv6: 128 bit adres, 40 bayt sabit başlık, akış etiketi ve öncelik, sağlama toplamı yok.
- Geçiş: bayrak günü yok, tünelleme ile IPv6 datagramı IPv4 yükü olarak taşınır.
- Genelleştirilmiş iletim: çok katmanlı başlık alanları eşlenir; eylemler: ilet, düşür, değiştir, kopyala, kaydet, denetleyiciye gönder; sayaçlar ve öncelik.
- OpenFlow örnekleri: hedef IP → port, TCP d-port 22 → drop, kaynak IP → drop, hedef MAC → port.
- Ara kutular: NAT, güvenlik duvarı, IDS, yük dengeleyici, CDN, önbellek, vekil; beyaz kutu, SDN, NFV.
- RFC 1958: amaç bağlanabilirlik, araç IP, zekâ uçtan uca.
- İletim yerel (veri düzlemi), yönlendirme küresel (kontrol düzlemi); yönlendirici başına denetim ve merkezi (SDN) denetim.
- Yönlendirmede "iyi yol": en az maliyet, en hızlı, en az tıkanık.

## Detaylı Açıklamalar

- NAT örneği adım adım (ekrandan, 00:15:00)
  - Yerel ağ 10.0.0.0/24 bloğundadır: konaklar 10.0.0.1, 10.0.0.2, 10.0.0.3; NAT yönlendiricisinin LAN arayüzü 10.0.0.4, WAN arayüzü 138.76.29.7'dir.
  - 1. adım: 10.0.0.1 konağı, kaynak 10.0.0.1:3345, hedef 128.119.40.186:80 olan bir datagram gönderir.
  - 2. adım: NAT yönlendiricisi kaynağı 138.76.29.7:5001 yapar ve tabloya "WAN: 138.76.29.7, 5001 / LAN: 10.0.0.1, 3345" satırını ekler. Hedef değişmez.
  - 3. adım: Web sunucusu cevabı kaynak 128.119.40.186:80, hedef 138.76.29.7:5001 olarak gönderir.
  - 4. adım: NAT yönlendiricisi tabloya bakar ve hedefi 10.0.0.1:3345 yapar; cevap doğru konağa ulaşır.
  - Böylece yerel ağdaki cihaz sayısı artırılabilir ama dışarıya karşı yine tek bir IP kullanılır.
- Tünelleme örneği (ekrandan, 00:30:00)
  - Mantıksal görünümde A–B–E–F vardır ve B ile E arasında IPv6 yönlendiricilerini bağlayan bir IPv4 tüneli bulunur. Fiziksel görünümde B ile E arasında yalnız IPv4 bilen C ve D yönlendiricileri vardır.
  - A→B: saf IPv6 datagramı (flow X, src A, dest F, data).
  - B→C, C→D, D→E: dış IPv4 başlığı src B, dest E; yükte değişmemiş IPv6 datagramı (flow X, src A, dest F, data).
  - E→F: E dış başlığı atar, özgün IPv6 datagramını F'ye iletir.
- Hedef tabanlı ve genelleştirilmiş iletim farkı
  - Hedef tabanlı iletimde yönlendirici yalnız hedef IP adresine bakar ve iletim tablosunda en uzun önek eşlemesiyle çıkış portunu seçer.
  - OpenFlow akış tablosunda eşlenebilen alanlar (ekrandan, 00:40:00): Switch Port, MAC src, MAC dst, Eth type, VLAN ID, VLAN Pri, IP Src, IP Dst, IP Prot, IP ToS, TCP s-port, TCP d-port. `*` joker karakteri "her değer" demektir.
  - Derste anlatılan bir kural örneği: kaynak her şey, hedef `3.4.*.*` (son 16 bit serbest) olan paketler bir porta iletilir; belirli bir iç konak grubundan gelen her paket düşürülür; belirli bir kaynaktan gelenler denetleyiciye gönderilir. <!-- BELİRSİZ: Bu slaytın karesi yok; değerler altyazıdan alındı. -->
- OpenFlow ağ örneği
  - Bir OpenFlow denetleyicisi, üç anahtar (s1, s2, s3) ve altı konak (h1–h6) vardır. Amaç h5 ve h6'dan h3 ve h4'e giden trafiği s1 üzerinden, sonra s2 üzerinden geçirmektir.
  - Altyazıya göre kurallar: bir anahtarda IP Src `10.3.*.*`, IP Dst `10.2.*.*` → port 3'e ilet; s1'de giriş portu 1, IP Src `10.3.*.*`, IP Dst `10.2.*.*` → port 4'e ilet; s2'de giriş portu 2, IP Dst 10.2.0.3 → port 3 (h3), diğer hedef → port 4. <!-- BELİRSİZ: Bu slaytın karesi yok; konak adresleri ve hangi kuralın hangi anahtarda olduğu altyazıdan tam çıkmıyor. -->
- Zekâ nerede?
  - Telefon ağında santral her şeyi yapıyordu; çevir sesi bile santralden gelir. İnternetin ilk tasarımında ağ yalnız bağlantı sağlıyordu, zekâ uç cihazlardaydı. Bugün SDN, OpenFlow ve ara kutularla ağdaki cihazlar da programlanabilir ve "beyin" sahibidir.
- Ders sonrası notlar
  - Hoca `172.16/12` bloğu için "$2^{12}$" dedi; doğrusu bu blokta $2^{32-12} = 2^{20}$ adres vardır. `10/8` için $2^{24}$ ve `192.168/16` için $2^{16}$ doğrudur (python ile kontrol edildi).
  - Hoca `10/8` bloğunu "A sınıfı" ve `192.168/16` bloğunu "B sınıfı" diye andı; `192.168` adresleri sınıflı adreslemede C sınıfı aralığındadır.
  - Hoca IPv6 yayılmasında "%30 IPv6, kalan %60 IPv4" dedi; kalan pay yaklaşık %70'tir.
  - Hoca güvenlik duvarı örneğindeki adresi "128.119.11" diye okudu; karede 128.119.1.1'dir (ekrandan, 00:40:00).

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
