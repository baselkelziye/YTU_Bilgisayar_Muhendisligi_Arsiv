# Ders 11 Genişletilmiş Notu: Ağ Katmanı: NAT, IPv6, Genelleştirilmiş İletim, Ara Kutular ve Kontrol Düzlemine Giriş

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Veri Düzlemi Yol Haritası ve Önceki Dersin Hatırlatması
- 2. NAT: Ağ Adresi Dönüştürme
- 3. NAT Neden Tartışmalı?
- 4. IPv6
- 5. IPv4'ten IPv6'ya Geçiş: Tünelleme
- 6. IPv6'nın Yayılması
- 7. Genelleştirilmiş İletim: Eşle + Eylem
- 8. OpenFlow Örnekleri
- 9. Ara Kutular (Middleboxes)
- 10. İnternetin Kum Saati ve Mimari İlkeleri
- 11. Kontrol Düzlemine Giriş
- Örnek Sorular

## 1. Veri Düzlemi Yol Haritası ve Önceki Dersin Hatırlatması

Ders, ağ katmanı konusunun nasıl bölündüğünün hatırlatılmasıyla açıldı. Ağ katmanı iki parçada işlenir: veri düzlemi (data plane) ve kontrol düzlemi (control plane). Veri düzlemi temelde tek bir yönlendiricinin içinde olup bitenlerle ilgilenir. Önceki derste bu kapsamda iletim (forwarding) mekanizması, yani gelen bir datagramın giriş portundan ilgili çıkış portuna nasıl aktarıldığı anlatılmıştı. Üç anahtarlama türü de görülmüştü: yazılım (bellek) tabanlı, veri yolu (bus) ve anahtarlama dokusu (switching fabric).

Yol haritası slaytına göre bu derste "IP: the Internet Protocol" başlığı altında datagram biçimi ve adreslemenin ardından ağ adresi dönüştürme (NAT) ve IPv6 işlenecek; sonra "Generalized Forwarding, SDN" başlığı altında eşle + eylem (match + action) ve OpenFlow, en sonda da ara kutular (middleboxes) anlatılacaktır (ekrandan, 00:05:00). Hoca, geleneksel iletimin ağ katmanında (3. katman) çalıştığını, genelleştirilmiş iletimde ise başka katmanlardaki alanların da kullanılabildiğini önceden belirtti. Ara kutular arasında güvenlik duvarları ve yük dengeleyiciler sayıldı.

## 2. NAT: Ağ Adresi Dönüştürme

### 2.1 Motivasyon ve özel adres blokları

IPv4 adresleri 32 bittir ve adres alanı sınırlıdır. Hocanın sorusu şuydu: IPv4'ün kullanımını bugün nasıl genişletebiliriz? Cevap NAT'tır. NAT ile yerel ağdaki (LAN) bütün cihazlar, dış dünya söz konusu olduğunda tek bir IPv4 adresini paylaşır. Yerel ağdan çıkan bütün datagramlar aynı kaynak adresiyle (derste 138.76.29.7) ama farklı kaynak portlarıyla çıkar.

Bunu mümkün kılan, IPv4'te bazı adres bloklarının yalnız özel (private) kullanıma ayrılmış olmasıdır. Slayttaki bloklar şunlardır (ekrandan, 00:10:00):

- `10/8`: $2^{24}$ adres.
- `172.16/12`: $2^{20}$ adres.
- `192.168/16`: $2^{16}$ adres.

Bu bloklar yalnız yerel ağda kullanılır, internette (genel ağda) kullanılamaz. Yerel ağ içinde kaynağı ya da hedefi bu ağda olan datagramlar her zamanki gibi bu yerel adresleri taşır; dışarıya çıkarken tek bir dış IP kullanılır.

> **Ders sonrası not:** Hoca `172.16/12` bloğu için "$2^{12}$ cihaz" dedi; doğrusu önek uzunluğu 12 olduğundan $2^{32-12} = 2^{20} = 1\,048\,576$ adrestir (python ile kontrol edildi). `10/8` için $2^{24}$ ve `192.168/16` için $2^{16}$ doğrudur. Hoca `192.168/16` bloğunu "B sınıfı" diye andı; sınıflı adreslemede `192.168` adresleri C sınıfı aralığındadır.

### 2.2 NAT'ın avantajları

Slaytta dört avantaj sayılır (ekrandan, 00:10:00); hoca ilk üçünü temel avantajlar olarak anlattı:

- ISS'den tüm cihazlar için yalnız bir IP adresi gerekir. Hocanın örneği: evinizde ücretini ödeyip tek bir statik IP alır ve bütün yerel cihazlarınız için onu kullanırsınız.
- Yerel ağdaki konakların adresleri dış dünyaya bildirilmeden değiştirilebilir.
- ISS değiştirildiğinde yerel ağdaki cihazların adresleri değişmez.
- Güvenlik: yerel ağdaki cihazlar dış dünyadan doğrudan adreslenemez ve görünmez.

### 2.3 NAT'ın gerçekleştirilmesi

NAT için NAT yeteneğine sahip bir yönlendirici gerekir ve bu yönlendirici şeffaf (transparent) çalışır. Hoca üç gereksinimi sırayla anlattı:

- **Giden datagramlar:** NAT yönlendiricisi her giden datagramın (kaynak IP adresi, kaynak port) ikilisini (NAT IP adresi, yeni port) ile değiştirir. NAT IP adresi, ISS'nin verdiği dış adrestir. Uzaktaki istemciler ve sunucular cevap verirken bu (NAT IP adresi, yeni port) ikilisini hedef adres olarak kullanır.
- **Hatırlama:** NAT yönlendiricisi her (kaynak IP, kaynak port) → (NAT IP, yeni port) eşlemesini NAT dönüştürme tablosunda (NAT translation table) saklamak zorundadır.
- **Gelen datagramlar:** Cevap datagramının hedef alanındaki (NAT IP, yeni port), tablodaki karşılığı olan özgün (yerel IP, yerel port) ile değiştirilir.

### 2.4 NAT örneği

Slayttaki ağda yerel konaklar 10.0.0.1, 10.0.0.2 ve 10.0.0.3; NAT yönlendiricisinin LAN tarafı arayüzü 10.0.0.4, WAN tarafı arayüzü 138.76.29.7'dir (ekrandan, 00:15:00). Örnek dört adımda yürür:

1. 10.0.0.1 konağı, IP adresi 128.119.40.186 olan bir web sunucusuna istek gönderir. Datagram: S: 10.0.0.1, 3345; D: 128.119.40.186, 80.
2. NAT yönlendiricisi kaynağı 10.0.0.1, 3345'ten 138.76.29.7, 5001'e çevirir ve tabloyu günceller. Tabloya "WAN side addr: 138.76.29.7, 5001 / LAN side addr: 10.0.0.1, 3345" satırı eklenir. Giden datagram: S: 138.76.29.7, 5001; D: 128.119.40.186, 80 (ekrandan, 00:15:00).
3. Web sunucusu cevap verir: S: 128.119.40.186, 80; D: 138.76.29.7, 5001.
4. Datagram NAT yönlendiricisine gelince tablodan bakılır ve hedef 10.0.0.1, 3345'e çevrilir; cevap doğru konağa ulaşır.

Hoca, giderken hedef IP adresi ve hedef portun hiç değişmediğini, yalnız kaynağın değiştiğini özellikle gösterdi. Yöntemin basit olduğunu, yerel cihaz sayısını artırırken yine tek bir IP adresiyle çalışılabildiğini söyledi.

## 3. NAT Neden Tartışmalı?

Hoca NAT'ın tartışmalı (controversial) olduğunu dört nedenle açıkladı:

- **Katman ihlali:** Yönlendiriciler yalnız 3. katmana kadar işlem yapmalıdır. NAT ise portu değiştirir; port 4. katman (taşıma katmanı) bilgisidir. Yani NAT yalnız ağ katmanında çalışmaz, taşıma katmanı başlığını da değiştirir.
- **IPv6'yı geciktirmesi:** IPv6, IP adresi sıkıntısı yüzünden getirildi. NAT IPv4'ün kullanımını genişleterek IPv6'ya geçişi engelliyor.
- **Uçtan uca ilkesinin ihlali:** IP'de ağdaki her cihaz başka bir ağdaki her cihaza erişilebilir olmalıdır. NAT'ta yerel adres kullanan cihazlara doğrudan erişilemez.
- **NAT arkasındaki sunucu (NAT traversal):** Sunucu yerel bir IP adresi kullanıyorsa dışarıdaki istemci ona nasıl bağlanacak? Ayrıca NAT arkasında birden fazla web sunucusu varsa standart web portu 80'i yalnız biri kullanabilir.

Tüm bu tartışmalara rağmen NAT hâlâ yaygındır. Hoca özellikle 4G ve 5G hücresel ağları örnek verdi: hücresel ağda çok sayıda cihaz bulunduğu için ve bazı güvenlik nedenleriyle operatörler IPv4 ve NAT kullanmaya devam ediyor.

## 4. IPv6

### 4.1 Motivasyon

İlk motivasyon adres alanıdır: IPv4 32 bittir, adres alanı sınırlıdır ve tamamen dolmuştur. Milyarlarca cihaz ağa katıldığı için daha fazla adres gerekir.

Ek motivasyon hızdır, yani işleme ve iletim hızı. IPv6 başlığı 40 bayt ve sabit uzunluktadır. İsteğe bağlı (optional) başlık alanları yoktur, uzunluk sabit olduğu için başlık uzunluğu alanına da gerek yoktur. Sabit uzunluklu bir başlığın işlenmesi optimize edilebilir. Bir diğer ek motivasyon, farklı akışlara ağ katmanında farklı muamele yapılabilmesidir: iletim eyleminde akışa göre farklı işlemler tanımlanabilir. Bu motivasyon slaytının karesi boştur (ekrandan, 00:20:00); maddeler altyazıdan alınmıştır.

### 4.2 IPv6 datagram biçimi

IPv6'da adres alanı 128 bittir. Hoca başlığın öne çıkan alanlarını şöyle anlattı:

- **Akış etiketi (flow label):** Aynı akışa ait datagramları tanımlar. Bu etiketle iletimde öncelik verilebilir, paket düşürülebilir; yönlendirici güvenlik duvarı ya da yük dengeleyici gibi davranabilir.
- **Öncelik (priority):** Akıştaki datagramlar arasındaki önceliği belirler.
- **Yük uzunluğu (payload length), sonraki başlık (next header), atlama sınırı (hop limit):** Hoca bunların IPv4'teki karşılıklarına benzediğini söyledi.

IPv4'e göre eksik olan alanlar da anlatıldı. Sağlama toplamı (checksum) yoktur; yönlendiricide her atlamada kontrol gerekmediği için işlem hızlanır. <!-- BELİRSİZ: 00:23:07–00:23:33 arasında altyazı tekrar eden bozuk bir satırdan oluşuyor; hocanın burada parçalama (fragmentation/reassembly) ve seçenekler (options) alanlarının da IPv6'da bulunmadığını anlattığı düşünülüyor, ancak altyazıda ve karelerde doğrulanamadı. -->

> **Ek bilgi (derste anlatılmadı):** IPv4'teki sağlama toplamı TTL her atlamada azaldığı için her yönlendiricide yeniden hesaplanmak zorundadır; IPv6'da bu yükün kaldırılmasının nedeni budur. Hocanın IPv4'te de var dediği alanların IPv4'teki adları farklıdır: "sonraki başlık" IPv4'teki üst katman protokol alanına, "atlama sınırı" ise TTL alanına karşılık gelir.

## 5. IPv4'ten IPv6'ya Geçiş: Tünelleme

### 5.1 Neden bir arada yaşıyorlar?

IPv4'ten IPv6'ya geçişin on yıldan uzun süre önce yapılması düşünülmüştü. Ama bütün yönlendiriciler aynı anda yükseltilemez (ekrandan, 00:25:00). Bir "bayrak günü" (flag day), yani bütün IPv4 cihazlarının kapatılıp IPv6 cihazlarının açıldığı belirli bir gün olmadı. Bu yüzden bugün bazı ağlar IPv4, bazıları IPv6 ile çalışır; saf bir IPv6 ağı yoktur. Soru şudur: ağ, karışık IPv4 ve IPv6 yönlendiricileriyle nasıl çalışacak?

### 5.2 Tünelleme

Çözüm tünellemedir (tunneling). IPv6 datagramı, IPv4 datagramının içinde yük (payload) olarak taşınır. Dış IPv4 datagramının kendi başlık alanları (sürüm numarası, kaynak ve hedef IPv4 adresleri vb.) vardır; yükünün içinde de IPv6 başlığı ve IPv6 yükü bulunur. Hoca, 4G/5G ağlarda NAT ile IPv4 kullanıldığını hatırlatıp tünellemenin hücresel ağlarda yaygın kullanıldığını söyledi.

### 5.3 Tünelleme örneği

Slaytta mantıksal ve fiziksel görünüm birlikte verilir (ekrandan, 00:30:00):

- **Mantıksal görünüm:** A (IPv6) – B (IPv6/v4) – IPv6 yönlendiricilerini bağlayan IPv4 tüneli – E (IPv6/v4) – F (IPv6).
- **Fiziksel görünüm:** A (IPv6) – B (IPv6/v4) – C (IPv4) – D (IPv4) – E (IPv6/v4) – F (IPv6).

A ve F saf IPv6 yönlendiricileridir. B ve E hem IPv6 hem IPv4 bilen köprü yönlendiricilerdir; bir yanları IPv4 ağına, öbür yanları IPv6 ağına bağlıdır. C ve D IPv4 ağını oluşturan yönlendiricilerdir. Paketin yolculuğu şöyledir:

1. A'dan B'ye (A-to-B: IPv6): saf IPv6 datagramı; flow: X, src: A, dest: F, data.
2. B'de kapsülleme yapılır. B'den C'ye, C'den D'ye ve D'den E'ye giden datagramın dış (IPv4) başlığı src: B, dest: E'dir; içinde değişmemiş IPv6 datagramı (Flow: X, Src: A, Dest: F, data) vardır.
3. E, IPv4 başlığını atar ve özgün IPv6 datagramını (src: A, dest: F, data) F'ye iletir.

> **Hocanın vurgusu:** IPv6 datagramının kaynak ve hedefi baştan sona A ve F olarak kalır; IPv4 ağı içinde dış başlıktaki kaynak ve hedef, sürüm 4 ile sürüm 6 arasındaki köprü yönlendiricilerdir (B ve E).

> **Ders sonrası not:** Slaytta C→D ve D→E aşamalarının etiketleri de "B-to-C: IPv6 inside IPv4" olarak yazılmıştır (ekrandan, 00:30:00); bu büyük olasılıkla slayttaki bir kopyalama hatasıdır, doğrusu sırasıyla C-to-D ve D-to-E olmalıdır.

## 6. IPv6'nın Yayılması

Hocanın aktardığı verilere göre Google'a göre istemcilerin yaklaşık %30'u hizmetlere IPv6 ile erişiyor; yani hâlâ üçte bir civarında. NIST raporuna göre ABD devlet alan adlarının üçte biri IPv6 yetenekli, üçte ikisi hâlâ IPv4 ağında. Hoca yayılma grafiğini gösterip sürecin çok yavaş ilerlediğini, gidilecek çok uzun bir yol olduğunu söyledi.

> **Ders sonrası not:** Hoca "kalan %60 hâlâ IPv4'te" dedi; %30 IPv6 ise kalan pay yaklaşık %70'tir.

Geliştirme ve kullanıma geçiş 25 yıldır sürüyor. Hoca son 25 yılda uygulamaların ne kadar değiştiğini düşünmeyi istedi; öğrencilerin çoğu 25 yaşın altında olduğu için dünya çapında ağı (WWW), sosyal medyayı, akış medyasını, oyunları, telekonferansı ve video akışını zaten tanıyor. IPv4 bu uygulamalara hizmet verecek biçimde tasarlanmamıştı. Bunun nasıl çözüldüğünün cevabı basittir: taşıma katmanında anlatıldığı gibi güvenilirlik gibi özellikler orada gerçekleştirilebilir. Ayrıca uygulama katmanında yeni protokoller geliştirilerek IPv4 üzerinde güvenilirlik, yük dengeleme gibi özellikler sağlanabilir.

## 7. Genelleştirilmiş İletim: Eşle + Eylem

### 7.1 Hedef tabanlı iletimin hatırlatması

Slaytın "Review" kısmına göre her yönlendiricide bir iletim tablosu (forwarding table, diğer adıyla akış tablosu, flow table) vardır (ekrandan, 00:35:00). "Eşle + eylem" soyutlamasında gelen paketteki bitler eşlenir ve bir eylem yapılır. Slayttaki çizimde gelen paketin başlığındaki değer `0111`'dir ve yönlendirici tabloya bakarak paketi 2 numaralı çıkış bağlantısına yönlendirir (ekrandan, 00:35:00).

- **Hedef tabanlı iletim (destination-based forwarding):** Yalnız hedef IP adresine göre iletilir. Yönlendirici başlıktaki değeri iletim tablosundaki değerlerle karşılaştırır (en uzun önek eşleme) ve paketi ilgili çıkışa aktarır.
- **Genelleştirilmiş iletim (generalized forwarding):** Birçok başlık alanı eylemi belirleyebilir ve birçok eylem mümkündür: düşür (drop), kopyala (copy), değiştir (modify), kaydet (log).

### 7.2 Akış tablosu

Akış tablosunda akış (flow) başlık değerleriyle tanımlanır. Bu değerler yalnız ağ katmanından değil, bağlantı katmanı, ağ katmanı ve taşıma katmanı alanlarından gelir. Genelleştirilmiş iletimde basit paket işleme kuralları tanımlanır:

- **Eşleme (match):** Paket başlığındaki farklı katmanlara ait alanlardaki desen değerleri eşlenir.
- **Eylemler (actions):** Paketi düşürmek, iletmek, değiştirmek, kopyalamak ya da kaydetmek.
- **Öncelik (priority):** Birden fazla kural eşleşirse hangisinin uygulanacağı.
- **Sayaçlar (counters):** Bayt sayısı ve paket sayısı tutulabilir.

Hoca basit bir kural tablosu örneği anlattı. Kaynak "her şey" (joker, wildcard), hedef `3.4.*.*` olan paketler, yani hedefin ilk 16 biti sabit ve kalan 16 biti serbest olanlar, 2 numaralı porta iletilir. Belirli bir iç konak grubundan herhangi bir hedefe giden bütün paketler düşürülür. Belirli bir kaynaktan herhangi bir hedefe gidenler denetleyiciye (controller) gönderilir. Böylece eylem olanakları çoğalır. <!-- BELİRSİZ: Bu slaytın karesi yok; kaynak ve hedef değerleri yalnız altyazıdan alındı, iç konak grubunun adres deseni anlaşılmıyor. -->

### 7.3 OpenFlow'da eşlenen alanlar ve eylemler

Eşlemede kullanılabilen başlık alanları katmanlara göre şöyledir:

- **Bağlantı katmanı:** Ethernet, kablosuz, sanal LAN (VLAN) alanları; kaynak ve hedef MAC adresi.
- **Ağ katmanı:** kaynak IP, hedef IP, IP protokol alanı.
- **Taşıma katmanı:** TCP/UDP kaynak ve hedef portu.

OpenFlow örnek tablosundaki sütunlar şunlardır (ekrandan, 00:40:00): Switch Port, MAC src, MAC dst, Eth type, VLAN ID, VLAN Pri, IP Src, IP Dst, IP Prot, IP ToS, TCP s-port, TCP d-port, Action.

Eylem olarak paket iletilebilir, düşürülebilir, ilgili katmandaki başlık alanları değiştirilebilir ya da paket kapsüllenip denetleyiciye iletilebilir. Hoca OpenFlow'un bu şekilde çalıştığını, kurallara sayaç da eklenebildiğini söyledi.

## 8. OpenFlow Örnekleri

### 8.1 Tablo örnekleri

Slayttaki örnekler şunlardır (ekrandan, 00:40:00). `*` her değeri eşleyen joker karakterdir.

| Örnek | Eşlenen alan (diğerleri `*`) | Eylem | Anlamı |
|---|---|---|---|
| Hedef tabanlı iletim | IP Dst = 51.6.0.8 | port6 | 51.6.0.8 adresine giden IP datagramları çıkış portu 6'ya iletilir. |
| Güvenlik duvarı | TCP d-port = 22 | drop | TCP port 22'ye (SSH) giden bütün datagramlar engellenir. |
| Güvenlik duvarı | IP Src = 128.119.1.1 | drop | 128.119.1.1 konağının gönderdiği bütün datagramlar engellenir. |

İlk örnek, diğer ağ katmanı cihazlarındaki hedef tabanlı iletime benzer: her kaynak IP'den belirli bir hedef adrese gidenler port 6'ya gönderilir. Diğer iki örnek OpenFlow'un güvenlik duvarı gibi çalışabildiğini gösterir.

> **Ders sonrası not:** Hoca son örnekteki adresi "128.119.11" diye okudu; karede 128.119.1.1'dir (ekrandan, 00:40:00).

Hoca bir örnek daha anlattı: OpenFlow 2. katmanda hedef tabanlı iletim de yapabilir. Belirli bir hedef MAC adresine (komşu cihazın onaltılık MAC adresi) giden çerçeveler belirli bir porta yönlendirilir. <!-- BELİRSİZ: Bu örneğin MAC adresi ve port değeri karede görülmedi. -->

### 8.2 Eşle + eylem soyutlamasının birleştirici gücü

Hoca, eşle + eylem soyutlamasının farklı türdeki cihazları tek bir modelde birleştirdiğini vurguladı. OpenFlow cihazı şunlar gibi çalışabilir:

- **Yönlendirici:** eşleme en uzun hedef IP önekidir; eylem çıkış bağlantısına iletmektir. Yani geleneksel yönlendirici gibi davranır.
- **Anahtar (switch, 2. katman):** eşleme hedef MAC adresidir; eylem iletmek ya da taşırmaktır (flood).
- **Güvenlik duvarı:** eşleme IP adresleri ve TCP/UDP port numaralarıdır; eylem izin vermek ya da reddetmektir (permit/deny).
- **NAT:** eşleme IP adresi ve porttur; eylem adresi ve portu yeniden yazmaktır.

### 8.3 OpenFlow ağ örneği

Son örnekte bir OpenFlow denetleyicisi, üç anahtar (s1, s2, s3) ve altı konak (h1'den h6'ya) bulunur; konakların IP adresleri slaytta verilmiştir. Amaç, h5 ve h6'dan h3 ve h4'e giden trafiği önce s1 üzerinden, sonra s2 üzerinden geçirmektir. Böylece trafik belirli bağlantılara yönlendirilebilir. Hocanın anlattığı kurallar şöyledir:

- Bir anahtarda kaynak ve hedef bloğuna göre eşlenen paketler çıkış portu 3'e iletilir.
- Giriş portu 1'den gelen, kaynak adresi `10.3.*.*` (10.3/16) ve hedef adresi `10.2.*.*` (10.2/16) olan her paket port 4'e iletilir.
- Giriş portu 2'den gelen ve hedefi 10.2.0.3 olan paketler port 3'e, yani h3'e giden bağlantıya iletilir; diğer konağa gidenler port 4'e iletilir.

Hoca her eylemin bu şekilde ayrıntılı tanımlanabildiğini belirtti. <!-- BELİRSİZ: Bu slaytın karesi yok; konak adresleri, ikinci hedef adresi ve kuralların hangi anahtara (s1, s2, s3) ait olduğu altyazıdan tam çıkmıyor. -->

## 9. Ara Kutular (Middleboxes)

### 9.1 Tanım

Hoca ara kutuyu bir RFC belgesine göre tanımladı: ara kutu, kaynak ve hedef arasındaki veri yolunda, bir IP yönlendiricisinin normal ve standart işlevleri dışında işlev gören her ara cihazdır. Yani standart yönlendirici dışındaki ağ cihazları kastedilir.

> **Ders sonrası not:** Hoca RFC numarasını "3331" gibi okudu (altyazıya göre); ara kutuları tanımlayan belge büyük olasılıkla RFC 3234'tür (Middleboxes: Taxonomy and Issues).

### 9.2 Ara kutular her yerde

Slayttaki örnekler (ekrandan, 00:45:00):

- **NAT:** ev, hücresel ağ, kurum. Hoca evde ve hücresel ağda kullandığımız NAT yönlendiricisinin bir ara kutu olduğunu söyledi.
- **Güvenlik duvarları, IDS:** kurumlar, servis sağlayıcılar, ISS'ler. Hoca IPS cihazlarını da andı.
- **Yük dengeleyiciler:** kurumlar, servis sağlayıcılar, veri merkezleri, mobil ağlar.
- **Uygulamaya özel hizmetler:** CDN (içerik dağıtım ağı). Hoca YouTube, Netflix, Disney+, BluTV gibi akış hizmetlerini örnek verdi.
- **Önbellekler ve vekil sunucular (proxy):** servis sağlayıcılar, mobil ağlar, CDN'ler.

### 9.3 Kapalı donanımdan beyaz kutuya

Başlangıçta ara kutular tescilli (proprietary), kapalı donanım çözümleriydi. Bugün açık API'ler sunan "beyaz kutu" (white box) donanımlara geçiliyor. Bu donanımlar eşle + eylem üzerinden yerel eylemlerle programlanabilir; yenilik ve farklılaşma yazılıma taşınır. SDN'de denetim ve yapılandırma yönetimi mantıksal olarak merkezîdir ve genel ya da özel bulutta çalışabilir. Ayrıca NFV (Network Functions Virtualization, ağ işlevlerinin sanallaştırılması) ile ağ, hesaplama ve depolama hizmetleri beyaz kutular üzerinde programlanabilir hâle gelir. Hoca bu alanın artık geniş ölçüde açık olduğunu söyledi.

## 10. İnternetin Kum Saati ve Mimari İlkeleri

### 10.1 Kum saati

Hoca o ana kadar öğrenilenleri kum saati modeliyle toparladı:

- **Uygulama katmanı:** HTTP, SMTP, RTP, QUIC, DASH gibi çok sayıda protokol.
- **Taşıma katmanı:** yalnız TCP ve UDP. TCP güvenilir hizmet, UDP güvenilmez ama hızlı hizmet verir.
- **Ağ katmanı:** yalnız IP.
- **Bağlantı katmanı:** Ethernet, PPP, PDCP, Wi-Fi, Bluetooth, ZigBee gibi çok sayıda teknoloji.
- **Fiziksel katman:** bakır, fiber, radyo gibi ortamlar.

> **Hocanın vurgusu:** Ağa bağlı her cihazda IP protokolü gerçekleştirilmiş olmak zorundadır. Her cihazda HTTP, TCP ya da SMTP bulunmayabilir ama IP mutlaka vardır.

IP'nin üstünde ve altında çok sayıda protokol bulunur. Kum saatinin beli eskiden çok inceydi; bugün IPv6, NAT, OpenFlow ve SDN gibi eklemelerle biraz kalınlaştı, "göbek bağladı".

### 10.2 RFC 1958 ve uçtan uca ilkesi

Hoca internetin mimari ilkelerini RFC 1958'e göre aktardı. Slayttaki alıntıya göre internet topluluğunun birçok üyesi bir mimari olmadığını, yalnız ilk 25 yıl boyunca yazıya geçirilmemiş bir gelenek olduğunu savunur. Ama çok genel anlamda topluluk şuna inanır: "amaç bağlanabilirliktir, araç İnternet Protokolüdür ve zekâ ağın içinde gizli olmak yerine uçtan ucadır" (ekrandan, 00:50:00).

Buna göre üç temel taş vardır:

- Basit bağlanabilirlik.
- Her cihazda bulunan protokol, yani IP.
- Zekâ ve karmaşıklığın ağın kenarında (network edge) olması.

Uçtan uca argümanına göre güvenilir veri aktarımı ve tıkanıklık denetimi gibi bazı ağ işlevleri ağın içinde ya da kenarda gerçekleştirilebilir. Ağ katmanı ağdaki her cihazda çalışmak zorunda olduğu için arada çok sayıda cihaz vardır; soru, zekânın nerede olacağıdır.

### 10.3 Zekâ nerede?

Hoca 20. yüzyılın telefon ağını (PSTN) örnek verdi. Orada bütün zekâ ağdaydı; analog, standart telefonun içinde bir "beyin" yoktu. Çevir sesi bile santralden gönderiliyordu. İnternetin başında ise ağ yalnız bağlantı sağlıyordu, bütün yetenekler uçlardaydı. Bugün ise OpenFlow ve benzeri yaklaşımlarla ağdaki her cihaz bir şeyler yapabilen bir "beyne" sahiptir. <!-- BELİRSİZ: 00:53:01–00:53:52 arasında altyazı bozuk; OpenFlow ile ilgili karşılaştırmanın ayrıntısı anlaşılmıyor. -->

Hoca bu noktada veri düzleminin bittiğini söyledi.

## 11. Kontrol Düzlemine Giriş

### 11.1 Bölümün hedefleri

Beşinci bölüm kontrol düzlemidir. Veri düzleminde yalnız tek bir yönlendiricinin içine bakılmıştı. Kontrol düzleminde amaç, arkasındaki ilkeleri anlamaktır:

- Geleneksel yönlendirme algoritmaları.
- SDN denetleyicileri (controllers).
- Ağ yönetimi ve ağ yapılandırması.

İnternetteki karşılıkları da işlenecektir: OSPF, BGP (Border Gateway Protocol), OpenFlow, ODL ve ONOS denetleyicileri, ICMP, SNMP, YANG ve NETCONF.

### 11.2 İletim ve yönlendirme

Veri düzleminde iletim (forwarding), paketi yönlendiricinin bir giriş portundan uygun çıkış portuna taşımaktı. Kontrol düzleminin konusu olan yönlendirme (routing) ise paketin kaynaktan hedefe izleyeceği yolu belirlemektir. Bu küresel bir problemdir; ağı tasarlarken küresel düşünmek gerekir.

Kontrol düzleminde iki yaklaşım vardır:

- **Yönlendirici başına denetim (per-router control):** Geleneksel yaklaşımdır. Yönlendirme algoritması her yönlendiricide ayrı ayrı çalışır. Her yönlendiricinin yerel bir iletim tablosu vardır; bu tablo, o yönlendiricide çalışan yönlendirme algoritmasıyla oluşturulur ve güncellenir. Yönlendiriciler birbirleriyle mesajlaşır.
- **Mantıksal merkezi denetim (logically centralized control):** Daha yeni yaklaşımdır ve yazılım tanımlı ağların (SDN) konusudur. Uzak bir denetleyici yerel iletim tablolarını hesaplar. <!-- BELİRSİZ: 00:58:35–00:59:20 arasında altyazı bozuk; merkezi denetimin ayrıntıları ve yönlendirme algoritması sınıflandırmasının ilk kısmı anlaşılmıyor. Yalnız "link state" ve "distance vector" adları duyuluyor. -->

Yönlendirme algoritmalarından bağlantı durumu (link state) ve uzaklık vektörü (distance vector) adları geçti; ayrıntıları sonraki derse kaldı.

### 11.3 Yönlendirme protokollerinin amacı

Slayta göre yönlendirme protokolünün amacı, gönderen konaktan alıcı konağa, yönlendiricilerden oluşan bir ağ üzerinden "iyi" yollar (eşdeğer olarak rotalar) belirlemektir (ekrandan, 01:00:00).

- **Yol (path):** Paketlerin verilen ilk kaynak konaktan son hedef konağa kadar geçtiği yönlendiriciler dizisi.
- **"İyi":** En az "maliyetli", en "hızlı" ya da en "az tıkanık" yol. Önce neyin iyi olduğuna karar vermek gerekir.

Hoca yönlendirmenin ağ alanındaki ilk 10 zorluktan biri olduğunu söyledi ve dersi burada bıraktı.

## Örnek Sorular

**Soru 1** (ekrandan, 00:15:00): Bir yerel ağda 10.0.0.1 konağı, kaynak portu 3345 olan bir istekle 128.119.40.186 adresli web sunucusunun 80 numaralı portuna bağlanıyor. NAT yönlendiricisinin WAN adresi 138.76.29.7'dir ve bu bağlantı için 5001 numaralı portu seçiyor. Giden ve gelen datagramların adresleri ile NAT dönüştürme tablosundaki satır ne olur?

> **Çözüm (derste anlatıldığı gibi):**
>
> - Konaktan çıkan: S: 10.0.0.1, 3345; D: 128.119.40.186, 80.
> - NAT'tan sonra: S: 138.76.29.7, 5001; D: 128.119.40.186, 80.
> - Tablo satırı: WAN side addr 138.76.29.7, 5001 ↔ LAN side addr 10.0.0.1, 3345.
> - Sunucunun cevabı: S: 128.119.40.186, 80; D: 138.76.29.7, 5001.
> - NAT'tan sonra konağa giden: S: 128.119.40.186, 80; D: 10.0.0.1, 3345.

**Soru 2** (ekrandan, 00:10:00): NAT'ta kullanılan özel IPv4 blokları `10/8`, `172.16/12` ve `192.168/16`'dır. Her blokta kaç adres vardır?

> **Çözüm (derste verilmedi, python ile doğrulandı):** Önek uzunluğu $p$ olan blokta $2^{32-p}$ adres vardır.
>
> - `10/8`: $2^{24} = 16\,777\,216$ adres (10.0.0.0 – 10.255.255.255).
> - `172.16/12`: $2^{20} = 1\,048\,576$ adres (172.16.0.0 – 172.31.255.255).
> - `192.168/16`: $2^{16} = 65\,536$ adres (192.168.0.0 – 192.168.255.255).

**Soru 3** (ekrandan, 00:30:00): A ve F saf IPv6, B ve E IPv6/v4, C ve D yalnız IPv4 yönlendiricisidir. A'dan F'ye gönderilen (flow X) bir IPv6 datagramı C ile D arasındaki bağlantıda nasıl görünür?

> **Çözüm (derste anlatıldığı gibi):** Dış IPv4 başlığı src: B, dest: E'dir. Bunun yükünde değişmemiş IPv6 datagramı bulunur: Flow: X, Src: A, Dest: F, data. E dış başlığı atar ve IPv6 datagramını F'ye iletir.

**Soru 4** (ekrandan, 00:40:00): OpenFlow akış tablosunda (Switch Port, MAC src, MAC dst, Eth type, VLAN ID, VLAN Pri, IP Src, IP Dst, IP Prot, IP ToS, TCP s-port, TCP d-port, Action) şu işler için kurallar nasıl yazılır? (a) 51.6.0.8'e giden IP datagramlarını çıkış portu 6'ya iletmek, (b) SSH trafiğini engellemek, (c) 128.119.1.1 konağının gönderdiği her şeyi engellemek.

> **Çözüm (derste anlatıldığı gibi):** Belirtilmeyen bütün alanlar `*` olur.
>
> - (a) IP Dst = 51.6.0.8 → Action: port6.
> - (b) TCP d-port = 22 → Action: drop.
> - (c) IP Src = 128.119.1.1 → Action: drop.

## Dersin Toparlaması

Bu derste ağ katmanının veri düzlemi tamamlandı. IPv4 adres sıkıntısına iki cevap görüldü: kısa vadede özel adres blokları ve port dönüştürmesiyle tek dış IP'yi paylaştıran NAT, uzun vadede 128 bit adresli ve 40 baytlık sabit başlıklı IPv6. NAT'ın 4. katmana dokunması, uçtan uca ilkesini bozması ve IPv6'yı geciktirmesi tartışıldı; IPv6'ya geçişin bayrak günü olmadan, tünellemeyle ve çok yavaş ilerlediği anlatıldı. Ardından hedef tabanlı iletim genelleştirildi: OpenFlow'un eşle + eylem soyutlaması bağlantı, ağ ve taşıma katmanı alanlarını eşleyerek tek bir cihazın yönlendirici, anahtar, güvenlik duvarı ya da NAT gibi davranmasını sağlıyor. Ara kutular, beyaz kutular, SDN ve NFV ile internetin kum saatinin ince IP belinin kalınlaştığı ve zekânın yalnız uçlarda kalmadığı vurgulandı.

Dersin sonunda kontrol düzlemine geçildi. İletimin yerel, yönlendirmenin küresel bir problem olduğu; yönlendirici başına denetim ile mantıksal merkezi (SDN) denetimin iki temel yaklaşım olduğu ve yönlendirme protokolünün "iyi" (en az maliyetli, en hızlı, en az tıkanık) yolu bulmayı amaçladığı anlatıldı. Bağlantı durumu ve uzaklık vektörü algoritmalarıyla bölümün devamı sonraki derse kaldı.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
