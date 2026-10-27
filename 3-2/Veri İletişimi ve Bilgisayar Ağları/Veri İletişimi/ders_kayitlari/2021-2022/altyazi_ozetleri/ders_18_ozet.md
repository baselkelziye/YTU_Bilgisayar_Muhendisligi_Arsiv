# Ders 18 Çalışma Özeti

## Genel Konular

- Ders 27 Aralık 2021 Pazartesi akşamı online yapıldı. Dersi Dr. Furkan Çakmak anlatıyor. Hoca "13. haftadayız" diyor; bu, hocanın ders anlattığı son hafta.
- Dersin başında proje ve sunumlarla ilgili sorular yanıtlandı.
- Konular:
  - OSI katmanlarına göre ağ cihazları: repeater ve hub, bridge ve switch, router, gateway.
  - Sanal LAN (Virtual LAN, VLAN) ve trunking.
  - TCP/IP modeli ve OSI ile karşılaştırması. TCP ve UDP.
  - IP adres sınıfları (A–E), alt ağ maskesi (subnet mask) ve alt ağ hesabı.
  - Yaygın port numaraları.
  - NAT (Network Address Translation), DHCP, DNS (Domain Name System), statik ve dinamik IP.
  - Ağ güvenliği:
    - Bütünlük, kullanılabilirlik ve gizlilik.
    - Şifreleme ve sayısal imza.
    - Erişim denetimi ve kimlik doğrulama.
    - Trafik dolgusu (traffic padding), yönlendirme denetimi ve noterlik (notarization).
- TCP/IP ve güvenlik konuları "genel kültür" düzeyinde anlatıldı. Ayrıntısı Ağ Teknolojileri ve Bilişim Sistemleri Güvenliği derslerinde görülecek.

## Hocanın Özellikle Vurguladığı Kısımlar

- Katmanlara göre cihazlar sınav için önemli:
  - **Repeater:** Fiziksel katmanda çalışır, zayıflayan sinyali güçlendirir.
  - **Bridge ve switch:** Veri bağı katmanında MAC adreslerine göre çalışır.
  - **Router:** Ağ katmanında çalışır, rota belirler.
  - **Gateway:** Farklı protokolleri ve ağları birbirine çevirir.
- Cihazlar yukarı katmanlara çıktıkça daha çok bellek ve işlem gücüne ihtiyaç duyar.
- **Hub ile switch farkı:** Hub gelen sinyali tüm portlara yayar (broadcast). Switch yalnızca hedef porta iletir, ağda gereksiz trafik oluşmaz.
- Repeater ve hub pasif bir konnektör değildir. Güç gerektiren aktif cihazlardır.
- **VLAN'ın avantajları:**
  - Daha yüksek başarım: broadcast yalnızca VLAN üyelerine gider.
  - Sanal çalışma grubu kurulabilir.
  - Kolay yönetim.
  - Fiziksel kablolamaya göre düşük maliyet.
  - Güvenlik.
- TCP/IP'nin internet katmanı bağlantısızdır (datagram). Güvenilirliği üst katmanlar, özellikle TCP sağlar.
- **Alt ağ hesabı sınavda sorulabilir.** Örnek soru tipleri:
  - "130 makine için en uygun maske nedir?"
  - "5 makine için en küçük maske nedir?"
- Router'lar trafik olmasa bile birbirleriyle küçük paketlerle rota bilgisi paylaşır. Ayrıca geçen paketlerin başlıklarından da tablolarını günceller. Paketin içeriğini değil, yalnızca başlığını okurlar.

## Kısa Tekrar Notları

- **IP adresi:** 32 bit, 4 bayt. Toplam $2^{32} = 4\,294\,967\,296$ adres.
- **Adres sınıfları:**

| Sınıf | İlk bitler | Varsayılan maske | Ağ başına konak |
| --- | --- | --- | --- |
| A | 0 | 255.0.0.0 (/8) | $2^{24}-2 = 16\,777\,214$ |
| B | 10 | 255.255.0.0 (/16) | $2^{16}-2 = 65\,534$ |
| C | 110 | 255.255.255.0 (/24) | $2^{8}-2 = 254$ |
| D | 1110 | – | Çok noktaya yayın (multicast) |
| E | 1111 | – | Ayrılmış (deneysel) |

- **Konak sayısı:** Konak kısmı $h$ bit ise kullanılabilir konak sayısı $2^h - 2$ olur. Tümü 0 olan adres ağ adresi, tümü 1 olan adres yayın adresidir.
- **Son baytta maske ve konak sayısı:**
  - 255.255.255.128 (/25): 126 konak.
  - 255.255.255.192 (/26): 62 konak.
  - 255.255.255.224 (/27): 30 konak.
  - 255.255.255.240 (/28): 14 konak.
  - 255.255.255.248 (/29): 6 konak.
- **Port numaraları:** 16 bitlik bir sayıdır, 0–65535 arası değer alır.

| Port | Protokol |
| --- | --- |
| 20, 21 | FTP |
| 23 | Telnet |
| 25 | SMTP (e-posta gönderme) |
| 80 | HTTP |
| 110 (TLS ile 995) | POP3 (e-posta alma) |

- **TCP:** Bağlantı yönelimli, güvenilir iletim.
- **UDP (User Datagram Protocol):** Bağlantısız. Teslimat ve sıra garantisi vermez.
- **NAT:** Yerel ağdaki pek çok cihaz, servis sağlayıcının verdiği tek bir genel IP üzerinden internete çıkar.
- **DHCP:** Yerel cihazlara otomatik IP dağıtır. Ev modemleri genellikle 192.168.x.x adreslerini verir.
- **DNS:** Alan adlarını IP adreslerine çevirir.
- **Statik IP:** Modem yeniden başlasa da IP değişmez.
- **Dinamik IP:** Her bağlantıda yeni bir IP atanabilir. Sağlayıcı sınırlı adresi daha çok kullanıcıya böyle paylaştırır.

## Detaylı Açıklamalar

### Repeater ve hub

- Sinyal mesafeyle zayıflar (attenuation). Zayıf sinyalde hata oranı artar, çerçeveler yeniden gönderilir. Telefonda çekim çubuklarının azalması ve hızın düşmesi bunun sonucudur.
- Sinyal gücü desibel (dB) ile ölçülür.
- Hoca, evinde Wi-Fi'ın ulaşmadığı odaya kablosuz repeater koyduğunu anlattı. Repeater aynı ya da farklı SSID ile ağı yeniden yayınlar.
- Çok portlu repeater'a hub denir. A portundan gelen sinyal tüm portlara yayılır. Yalnızca hedef C olsa bile tüm ağda trafik oluşur.

### Bridge ve switch

- İçlerinde bellek ve daha fazla işlem gücü vardır. Veri bağı katmanının MAC alt katmanında adreslere göre çalışırlar.
- A portundan gelen ve C'ye giden çerçeveyi yalnızca C portuna iletirler. Böylece broadcast yoğunluğu azalır.
- **Fakülte örneği:**
  - Binaya fiber hat gelir ve sunucu odasındaki bir switch'e bağlanır.
  - Switch'lerde 48–50 port vardır.
  - Daha çok cihaz için switch'ler birbirine döngü oluşturmayacak şekilde ağaç yapısında bağlanır.

### Router

- Ağ katmanında çalışır. Datagram ve sanal devre anlatımındaki "düğüm"ler router'dır.
- İstanbul'dan Konya'ya giden bir paket Gebze, Bursa, Eskişehir ve Ankara'dan geçebilir. Bu şehirlerin her biri bir router gibi düşünülebilir.
- Router'lar yönlendirme tablosu (routing table, look-up table) tutar. Komşudan daha iyi bir rota öğrenirlerse tablolarını günceller, daha kötüyse güncellemez.
- Bağlantısız modelde her paket için her router'da karar verilir. Bağlantı yönelimli modelde rota önceden belirlenir.

### Gateway

- İnternete 50 yıllık bir CNC makinesinden yeni bir bilgisayara kadar çok farklı cihaz bağlıdır.
- Bu cihazların topolojileri (bus, ring), protokolleri (Ethernet, Wi-Fi, Bluetooth) ve çerçeve boyutları farklıdır. Örneğin bir protokol 4000 baytlık çerçeve gönderirken öteki 1000 bayt bekleyebilir.
- Gateway bunlar arasında çeviri yapar. En çok işlem gücü isteyen cihazdır.

### VLAN

- Fiziksel LAN'da gönderilen her çerçeve tüm cihazlara yayılır.
- **Çok oyunculu oyun örneği:**
  - 10 oyuncu farklı LAN'lardadır ve her LAN'da 100 cihaz vardır.
  - Bir oyuncunun hareketinin 1000 cihaza yayılması gerekir.
  - 10 oyuncu için kurulan bir VLAN'da yayın yalnızca bu 10 makineye gider.
- VLAN'lar arası iletişime trunking denir.
- Görüntülü görüşme gibi gizli trafikte de yayının yalnızca ilgili cihazlara gitmesi güvenlik sağlar.

### TCP/IP modeli

- OSI 7 katmanlıdır. TCP/IP teoride 3–5 katmanlı anlatılır. Uygulamada 4 ya da 5 katmanlı modeller kullanılır.
- 4 katmanlı modelde en alttaki ağ erişim katmanı OSI'nin fiziksel ve veri bağı katmanlarına karşılık gelir. 5 katmanlı modelde bu iki katman ayrı ayrı gösterilir.
- OSI'deki ağ katmanının TCP/IP'deki karşılığı internet katmanıdır.
- İnternet katmanı (IP) bağlantısız ve "en iyi çaba" (best effort) ile çalışır. TCP, bunun üzerine güvenilir ve bağlantı yönelimli iletim kurar. UDP ise bağlantısızdır.

### Alt ağ (subnet) hesabı

- **35 bilgisayarlı şirket örneği:**
  - C sınıfı adres ve 255.255.255.0 maskesiyle 254 adres ayrılır. 35 cihaz için bu israftır.
  - Son baytın ilk iki biti 1 yapılırsa (255.255.255.192), 6 konak biti kalır. $2^6 - 2 = 62$ konak yeterlidir.
- **Genel kural:** $N$ konak için $2^h - 2 \ge N$ koşulunu sağlayan en küçük $h$ seçilir. Maske, kalan bitlerin 1 yapılmasıyla bulunur.
- **Örnekler (Python ile doğrulandı):**
  - 10 konak: $h = 4$, 14 konak, maske 255.255.255.240.
  - 5 konak: $h = 3$, 6 konak, maske 255.255.255.248.
  - 130 konak: $h = 8$, 254 konak, maske 255.255.255.0. $h = 7$ yalnızca 126 konak verir, yetmez.

### NAT, DHCP, DNS, statik ve dinamik IP

- Evdeki televizyon, telefon ve bilgisayar modemden yerel IP alır. Bu adresleri modemin DHCP sunucusu dağıtır.
- Dışarı çıkarken hepsi servis sağlayıcının verdiği tek genel IP'yi kullanır. Hangi yanıtın hangi cihaza gideceğini NAT ayırt eder.
- **DNS:**
  - İnsanların IP adreslerini ezberlemesi mümkün değildir. DNS, akılda kalan isimleri IP'lere eşler.
  - Alan adları ücret karşılığında kayıt ettirilir.
  - Google'ın genel DNS sunucusu 8.8.8.8'dir.
- **Dinamik IP örneği:** Telefon eve gelip Wi-Fi'a bağlanınca mobil ağdaki IP serbest kalır ve başka bir cihaza verilir.

### Ağ güvenliği

- Güvenlik yalnızca gizlilik değildir:
  - **Bütünlük:** 30 baytlık paket eksiksiz ve değiştirilmeden ulaşmalıdır. Bir bayt bile eksik ya da değişmişse veri işe yaramaz.
  - **Kullanılabilirlik:** Veri, ihtiyaç anında erişilebilir olmalıdır.
  - **Gizlilik ve mahremiyet:** Verinin başkasınca okunmaması.
- **Güvenlik mekanizmaları:**
  - **Şifreleme:** DES, AES.
  - **Sayısal imza:** Gönderenin kimliğini kanıtlar.
  - **Erişim denetimi:** Genellikle kimlik doğrulamayla birlikte kullanılır. İkincil bir cihazın birincil gibi davranması bir erişim denetimi açığıdır.
  - **Kimlik doğrulama:** Kullanıcı adı ve şifre.
  - **Yönlendirme denetimi:** Sahte başlıklı paketlerle trafiğin kötü niyetli bir router'a çekilmesini önler.
  - **Noterlik:** Güvenilir bir üçüncü tarafın onayıyla erişim. Hoca, yetki düzeyine göre kapı açan kart sistemine benzetti.

### Duyurular ve değerlendirme

- **Proje:**
  - Dönem başında grubunu kurmayanlar hoca tarafından atandı.
  - Ulaşılamayan ya da katkı vermeyen üyeler projeye yazılmamalı. Kalan kişiler, tek kişi kalsalar bile projeyi yapmak zorunda.
- **Sunum:**
  - Önümüzdeki hafta, normal ders saatinde (17:00–20:00) öğrenci sunumları yapılacak.
  - Aynı konu birden çok gruba verildi. Ders sırasında kurayla anlatacak grup seçilecek. Diğer gruplar hazırladıkları videolardan değerlendirilecek.
  - Sunum 15 dakikayı geçmemeli. Rapor yaklaşık 4 sayfa olmalı ve teknik ayrıntıları içermeli.
  - Sunum, konunun neyin devamı olduğunu, hangi sorunu çözdüğünü, özelliklerini ve nasıl çalıştığını anlatmalı. Mümkünse grafiklerle desteklenmeli.
  - Sunum tarihi ile raporun son teslim tarihi farklı. Doküman dikkatlice okunmalı.
- **Not ağırlıkları:** Proje (sunum ve rapor) ikinci vize yerine geçiyor ve %30 ağırlıkta. Final %40.
- Teslim etmeyen sıfır alır. Vize ortalamaları düşüktü, proje iyi hazırlanmalı.
- Sunumlarda anlatılan konulardan (X.25, ATM, ISDN vb.) finalde soru gelecek.
- **Final:**
  - Muhtemelen test olacak ve vizedeki gibi yüz yüze yapılacak.
  - Online grup öğrencileri de sınava okulda girecek.
  - Hoca, finallerin online yapılacağına dair bir bilgi olmadığını söyledi.

### Ders sonrası notlar

- **Toplam adres sayısı:** Hoca IPv4 adres sayısı için "32–34 milyon" dedi. Doğrusu $2^{32} \approx 4{,}29$ milyar adres. Adres yetersizliği bu yüzden NAT, alt ağlama ve IPv6 (128 bit) ile çözülür.
- **Konak sayıları:**
  - 255.255.255.192 için hoca 63 konak dedi. Doğrusu $2^6 - 2 = 62$.
  - 255.255.255.128 için hoca 127 konak dedi. Doğrusu $2^7 - 2 = 126$.
  - Hoca 255.255.255.0 için 254 konağı doğru hesapladı. Aynı "tümü 0 ve tümü 1 ayrılmıştır" kuralı küçük alt ağlarda da geçerlidir.
- **Port alanı:** Hoca "8 bitlik port adresleme" ifadesini kullandı. TCP ve UDP port alanı her zaman 16 bittir, $2^{16} = 65\,536$ değer alır. Hocanın "80.80" dediği port 8080'dir.
- **POP3:** Normal POP3 portu 110'dur. 995, TLS ile şifrelenmiş POP3 (POP3S) portudur.
- **DES:** Hoca DES ve AES'in süper bilgisayarlarla bile kırılamayacağını söyledi. Bu yalnızca AES için geçerli. DES'in anahtarı 56 bittir. 1998'de EFF'nin "Deep Crack" makinesi DES anahtarını yaklaşık 56 saatte kaba kuvvetle buldu. DES artık güvensiz kabul edilir.
- **Trafik dolgusu (traffic padding):** Hoca bunu ağdaki trafiği izleyip şüpheli akışları bulmak olarak anlattı. ITU-T X.800'deki tanımı farklıdır: Hatta sahte (anlamsız) veri gönderilerek gerçek trafiğin miktarı ve zamanlaması gizlenir. Amaç trafik analizini (traffic analysis) zorlaştırmaktır. Hocanın anlattığı izleme işi trafik analizi veya saldırı tespiti (intrusion detection) kapsamındadır.
- **Switch ve router:** Hoca "switch'i router olarak da kullanabilirsiniz" dedi. Bu yalnızca katman 3 (L3) switch'ler için geçerlidir. Sıradan (L2) bir switch IP yönlendirmesi yapmaz.
- **A sınıfı:** A sınıfı adres alanı toplam IPv4 alanının yarısıdır. Ancak yalnızca 126 kullanılabilir A sınıfı ağ vardır. 0 ve 127 ayrılmıştır; 127.x.x.x geri döngü (loopback) içindir.

**Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
