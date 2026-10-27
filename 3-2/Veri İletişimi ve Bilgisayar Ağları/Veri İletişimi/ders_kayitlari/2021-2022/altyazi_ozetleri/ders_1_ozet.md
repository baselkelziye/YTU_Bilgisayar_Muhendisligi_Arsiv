# Ders 1 Çalışma Özeti

## Genel Konular

- Dersin tarihi 11 Ekim 2021 Pazartesi. Ders online yapıldı, saat 17:00'de başladı.
  - Hoca kendini Ziya Cihan Tayşi olarak tanıtıyor. İletişim için Yıldız e-posta adresini veriyor.
  - 00:21:42 ile 00:27:12 arasında ara var. Hocanın önceden haber verdiği zorunlu bir ara.
  - Ders yaklaşık 01:49'da bitiyor.
- Dersin işleyişi
  - Dersin üç grubu var. Bu kayıt 3. grup (online grup).
  - 3. grubu Furkan Hoca ile dönüşümlü verecekler. Büyük ihtimalle ilk yedi haftayı Ziya Cihan Tayşi, sonrasını Furkan Hoca anlatacak.
  - Üç grup senkron ilerleyecek, aynı konulardan sorumlu olacak ve sınavlara aynı anda girecek.
  - Değerlendirme: bir vize, bir final ve bir proje. İlk vize 8. haftada.
  - Proje grup çalışması. Dersin kapsamındaki alt seviye bir protokol veya teknoloji araştırılacak. Örnek alanlar: fiziksel katman, veri bağı katmanı (data link layer), ortama erişim denetimi (medium access control). Rapor ve sunum hazırlanacak, sunumlar son bir-iki haftada.
  - Slaytlar paylaşılmayacak. Hoca kayıtlardan takip edilmesini istiyor.
  - Kaynak: Tanenbaum, *Computer Networks*. Ağ Teknolojileri dersinde de ana kitap bu. 5. baskı yeterli.
- Veri iletişiminin temel kavramları
  - İletişim ve haberleşme farkı.
  - İletişimin tarihçesi.
  - Veri iletişiminin temel parçaları.
  - İyi bir iletişimin özellikleri: doğru teslim, doğruluk, zamanında teslim, jitter.
- Bilgisayar ağlarının faydaları ve değerlendirme ölçütleri
  - Başarım (performance), servis kalitesi (quality of service, QoS), güvenilirlik, güvenlik, ölçeklenebilirlik, uyumluluk.
- Ağ mimarisi yaklaşımları
  - Katmanlı yaklaşım (layered approach): OSI ve TCP/IP.
  - Çapraz katmanlı yaklaşım (cross-layer approach).
- Standartlar ve standart kurumları
  - De jure ve de facto standartlar.
  - Açık ve kapalı standartlar.
  - ISO, ITU, ETSI, IEEE, EIA/TIA, ANSI, TSE, IETF.
- Ağların sınıflandırılması
  - İletim tekniğine göre: noktadan noktaya (point-to-point) ve yayın (broadcast).
  - Kapsama alanına göre: PAN, LAN, CAN, MAN, RAN, WAN.
  - Hıza göre.
- Ağ topolojileri
  - Yol (bus), yıldız (star), ağaç (tree), halka (ring), örgü (mesh), melez (hybrid).
- İletim modları
  - Tek yönlü (simplex), yarı çift yönlü (half duplex), tam çift yönlü (full duplex).
- Adresleme modelleri
  - Unicast, broadcast, multicast, anycast.
- Veri akışı ve ölçüler
  - Simetrik ve asimetrik akış.
  - Bit hızı ve birimleri, verim (throughput), cevap süresi (response time), jitter.

## Hocanın Özellikle Vurguladığı Kısımlar

- **İletişim ve haberleşme farkı:** İletişim alt seviyede verinin bir yerden bir yere aktarılmasıdır. Haberleşme daha üst seviyede anlamlı bilginin aktarılması ve alınmasıdır. Ders notlarında bile bu iki kavram zaman zaman karışıyor.
- **Veri iletişiminin dört temel parçası:**
  - İletim ortamı (medium).
  - Mesaj.
  - Gönderici ve alıcı.
  - Protokol: ortamın nasıl kullanılacağını belirleyen kurallar.
- **İletişimin üç beklentisi:** Doğru adrese teslim (delivery), doğruluk (accuracy) ve zamanında teslim (timeliness). Gerçek zamanlı ses ve görüntüde geciken verinin anlamı yoktur, atılır (discard).
- **Jitter:** Arka arkaya gönderilen paketlerin gecikmelerindeki değişkenlik. Hat kalitesinin bir ölçüsüdür.
- **Katmanlı yapının kuralı:** Her katman kendi içinde kalır. Altındaki katmandan servis alır, üstündeki katmana servis verir.
- **Ağın değeri:** Bir ağın değeri ona bağlanabilen cihaz sayısıyla orantılıdır. Bu bağlantıyı sağlamak için birbiriyle uyumlu yapılar, yani standartlar gerekir.
- **Topoloji seçiminde belirleyici olan maliyettir:** LAN'da mesafeler kısa olduğu için farklı topolojiler kurulabilir. WAN'da kilometrelerce kablo gerektiği için daha çok noktadan noktaya bağlantı tercih edilir.
- **Hub ve switch farkı:** Hub, yol topolojisinin bir kutu içine konmuş hâlidir. Biri konuşurken herkes dinler. Switch ise aynı anda birden fazla ikilinin konuşmasına izin verir.
- **Birim yazımı:** Saniyedeki bit (bps) için küçük "b", saniyedeki bayt için büyük "B" kullanılır. Kilo küçük "k" ile yazılır. Mega, giga, tera gibi diğer önekler büyük harfle yazılır.
- **Verimi düşüren asıl neden protokol ek yüküdür (protocol overhead):** 100 Mbps'lik kart alsanız da faydalı veri (payload) hiçbir zaman 100 Mbps olmaz. Gönderilen veriye her katman kendi başlık bilgisini ekler.
- **Sınav formatı:** Henüz netleşmedi. Hoca sorunun nasıl sorulacağına takılmamayı, konuyu bilmeyi öneriyor.

## Kısa Tekrar Notları

- Telekomünikasyon (telecommunication): Yunanca "tele" (uzak) ile iletişim. Uzaktan yapılan iletişim.
- Haberleşmenin tarihçesi:
  - Tamtam, duman, bayrak ve kuşlarla haberleşme.
  - Telgraf, telefon, radyo, televizyon.
  - Bugün Metro Ethernet, fiber, ADSL.
- Bilgisayar ağının faydaları:
  - Kaynak paylaşımı: yazıcı, veri, yedekleme.
  - Yük dengeleme (load balancing) ve hata toleransı.
  - Pahalı merkezi sistemler (mainframe) yerine sıradan donanımla (commodity hardware) benzer güvenilirlik.
  - Etkin haberleşme.
- Değerlendirme ölçütleri:
  - Başarım.
  - Servis kalitesi (QoS).
  - Güvenilirlik (reliability, availability).
  - Güvenlik (security).
  - Ölçeklenebilirlik (scalability).
  - Uyumluluk.
- Devre anahtarlamalı ağ (circuit switching):
  - Önce uçtan uca fiziksel bir devre kurulur. Bir bağlantı kurulum süresi vardır.
  - Örnek: eski telefon santralleri.
- Paket anahtarlamalı ağ (packet switching):
  - Her paket ayrı yönlendirilir. Paketler farklı yollardan gidebilir.
  - Paketler farklı gecikmelere uğrayabilir veya kaybolabilir.
- De jure standart: resmi kurumlarca belirlenip onaylanır.
- De facto standart:
  - Uygulamadan ve deneyimden doğar. Açık veya kapalı olabilir.
  - Örnekler: QWERTY, VHS, PDF. PDF önce de facto idi, sonra de jure oldu.
- Kapsama alanına göre ağlar:
  - PAN: kişisel alan; telefon, bileklik, kulaklık.
  - LAN: ev, ofis.
  - CAN: yerleşke ağı, kabaca 3-5 km. Örnek: Davutpaşa yerleşkesi.
  - MAN: kentsel ağ. Örnekler: kablonet, Metro Ethernet. YTÜ'nün Yıldız, Maslak ve Davutpaşa kampüsleri Metro Ethernet ile bağlıydı.
  - RAN: bölgesel ağ, örneğin Marmara bölgesi.
  - WAN: ülke çapı.
  - Hoca bu sınırları keskin bulmuyor.
- Topolojiler:
  - Bus: ilk Ethernet coax kablo üzerinde çalışıyordu. T adaptörler ve hattın iki ucunda sonlandırma dirençleri (terminator) vardı. Hat bir yerden koparsa ağ ikiye ayrılır ve arızanın yeri zor bulunur. Aynı anda tek kişi gönderebilir.
  - Star: ortada hub veya switch var. Bir kablo bozulursa sadece o uçtaki cihaz etkilenir. Bunun bedeli daha fazla kablodur.
  - Tree: hiyerarşik switch yapısı. Kampüs ağları genelde böyledir: çekirdek/omurga (core/backbone), dağıtım (distribution) ve erişim (access) katmanları.
  - Ring: söz, jetonu (token) tutandadır. Bugün az kullanılıyor.
  - Mesh: tam örgüde (full mesh) her düğüm diğer her düğüme doğrudan bağlıdır. Maliyetli olduğu için kısmi örgü (partial mesh) de kullanılır.
  - Hybrid: farklı topolojiler ağ geçidi (gateway) türü cihazlarla birbirine bağlanır.
- İletim modları:
  - Simplex: tek yön. Örnek: uydu alıcısı.
  - Half duplex: iki yön, ama aynı anda değil. Örnek: telsiz.
  - Full duplex: iki yön aynı anda. Örnek: Ethernet.
- Adresleme modelleri:
  - Unicast: tek alıcı.
  - Broadcast: herkes.
  - Multicast: önceden belirlenmiş bir alt grup. Örnek: IP üzerinden TV yayını.
  - Anycast: gruptaki herhangi bir alıcı.
- Cevap süresi = isteğin sunucuya iletilmesi + işlenmesi + cevabın geri iletilmesi.
- Hız ölçeği: 10 kbps'den 400 Gbps'e. 40 ve 100 Gbps bugün ticari olarak yaygın.

## Detaylı Açıklamalar

### İletişim, Protokol ve Günlük Hayattan Örnekler

- Hoca protokol kavramını sınıf ortamıyla anlatıyor:
  - Hoca konuşur, öğrenciler dinler.
  - Söz almak için el kaldırmak bant dışı (out-of-band) bir kontrol kanalıdır. Veri için ayrı, kontrol için ayrı hat kullanılır.
  - Hocanın durmasını bekleyip söze girmek, taşıyıcı dinlemeli çoklu erişime (carrier sense multiple access) benzer. Önce hattın boş olup olmadığına bakılır.
  - Annenizle, kardeşinizle veya dedenizle farklı konuşmanız da farklı protokoller izlemenizdir.
- Kulaktan kulağa oyunu, doğruluk (accuracy) olmadan iletişimin işe yaramadığını gösteriyor.
- Video izleme platformları (Netflix, YouTube vb.) önbelleğe alma (caching) yapar. Sen $T$ anını izlerken $T+1$, $T+2$, ... saniyeler arka planda indirilir. Bu yüzden ileriye dönük gecikme sorun olmaz. Canlı yayında ise geciken paket atılır.
- Gecikmenin iki ayrı boyutu var:
  - **Hat gecikmesi:** Ortamın karakteristiğinden gelir. Bakır mı fiber mi olduğuna, mesafeye ve uydu kullanılıp kullanılmadığına bağlıdır.
  - **Paket gecikmesi:** Paket anahtarlamalı ağlarda her paketin gecikmesi. Gecikmeler arasındaki değişkenlik de jitter olarak ölçülür.

### Yük Dengeleme Örneği

- OBS gibi bir servisi tek bilgisayarla verirseniz bütün istekler aynı yere gider. Bilgisayar fiziksel sınıra ulaşınca devre dışı kalır.
- Birkaç bilgisayarı yan yana koyup önlerine bir yük dengeleyici (load balancer) koyabilirsiniz. Diğer yol, isim sunucusu (name server) üzerinden istekleri farklı cihazlara yönlendirmektir. Böylece üç sunucu varsa her üç istekten biri bir sunucuya gider.
- Ek fayda: Bir sunucu bozulursa performans düşer, ama servis devam eder.

### Servis Kalitesi ve Ağ Operatörü

- Kişisel ağlar ve şirket içi ağlar (intranet) dışında birçok ağda bir ağ operatörü vardır. Kurumlar bu operatörden servis alır.
- Alınan servisin özellikleri QoS metrikleriyle tanımlanır ve sözleşmeye bağlanır.
- Devre anahtarlamalı ağda bu metrikler bit hızı, gecikme (transmission delay) ve ortalama hata miktarı gibi değerlerdir.
- Paket anahtarlamalı ağda başka parametreler kullanılır. Çünkü paketler farklı yollardan gider ve farklı gecikmelere uğrar.
- Eski telefon şebekesinde 5 kademeli bir yapı vardı. Şehirlerarası bir aramada kademeler boyunca yukarı çıkılıp geri inilirdi. İki nokta arasında 12 kadar anahtarlama ile fiziksel bir devre oluşurdu.

### Katmanlı Mimari

- OSI referans modelinde 7 katman var:
  - Fiziksel katman.
  - Veri bağı katmanı. Ortama erişim denetimi (MAC) bunun bir alt katmanıdır, ayrı sayılmaz.
  - Ağ, taşıma, oturum, sunu ve uygulama katmanları.
- TCP/IP'de dört katman var.
- OSI düzgün tanımlanmış bir referans modelidir ve katman kurallarına uyar. TCP/IP'de iki katman arasında nereye ait olduğu belli olmayan, "2,5. katman" denebilecek protokoller var.
- Kablosuz algılayıcı ağlarında (sensor networks) katmanlı yapı sık sık delinir:
  - Uygulama, yönlendirme (routing) kararına karışabilir.
  - Yönlendirme katmanı MAC'e müdahale edebilir.
  - Buna çapraz katmanlı yaklaşım (cross-layer approach) denir.

### Standartlar

- Standart yokken yaşanan sorun: DVD-R ve DVD+R birbiriyle uyumlu değildi. Bir türü diğer yazıcıda yazamıyordunuz.
- Gömleklerde düğmelerin hangi tarafta olduğu bile bir standarttır.
- Kurumlar:
  - ISO: ülkelerin standart kurumlarının bir araya geldiği uluslararası kurum.
  - ITU: telekomünikasyon standartları.
  - IEEE: Wi-Fi gibi birçok teknolojinin katmanlarında IEEE standartları var.
  - ETSI: Avrupa Birliği ile doğrudan bağlantılı. Amaç standardı Avrupa'da yapmak ve dünyaya yaymak.
  - EIA/TIA ve ANSI: Amerika tarafı.
  - TSE: Hoca, bazı TSE standartlarının içinin ISO standardının çevrilmemiş kopyası olmasını eleştiriyor.
- Standart savaşlarının bir örneği ATM (Asynchronous Transfer Mode):
  - Hücre boyutu 53 bayttır. Uzlaşmayla ortaya çıkmış, ikinin kuvveti olmayan bir değer.
  - ATM, ADSL'de servis sağlayıcı tarafında hâlâ kullanılıyor (AAL5). Hız sınırlarını uygulamak için kullanılıyor.

### Yayın Mantığı ve Güvenlik

- Wi-Fi alt seviyede yayın (broadcast) mantığıyla çalışır.
  - Frame içinde, bir erişim noktasına (access point) bağlıysanız, üç adres vardır: sizin adresiniz, erişim noktasının adresi ve hedefin adresi.
  - Aynı ağdaki herkes frame'i duyar. "Bana değil" deyip geçer.
  - Bu yüzden gizli dinleme (eavesdropping) mümkündür. Paketler yakalanıp şifre çözülmeye veya trafik yönlendirilmeye çalışılabilir.
- Noktadan noktaya bağlantı örnekleri:
  - İki bilgisayarı çapraz (cross) Ethernet kablosuyla bağlamak.
  - Fiber, eski seri hatlar, USB.

### VLAN ve Trunk (Öğrenci Sorusu Üzerine)

- Ağaç topolojisinde en üstteki cihaz hub olmaz. Yüksek kapasiteli bir omurga anahtarı (backbone switch) olmalıdır.
- Kampüste trafik erişim anahtarlarından yukarı doğru çıkar. Sonra ya sunuculara ya internete gider.
- Bölümlerin trafiği birbirinden yalıtılır:
  - Her port belli bir sanal ağa (VLAN) atanır.
  - Örneğin Bilgisayar Mühendisliği'nin 3. katındaki bir prize bağlanan cihaz o bölümün VLAN'ındadır. Trafiği Elektrik Mühendisliği'nin trafiğine karışmaz.
- Trunk bağlantı, cihaz üzerinde tanımlı bütün VLAN'ların trafiğini taşıyabilen bağlantıdır. Telefon santrallerindeki trunk hatlara benzer.
- Hoca bu konunun ileride VLAN anlatılırken daha iyi oturacağını söylüyor.

### Verim Sorusu

- Hoca sordu: "100 Mbps diye satılan kartla gerçekten 100 Mbps aktarabilir misiniz?"
- Öğrenciler kablo malzemesi, kablo uzunluğu ve donanım sınırları gibi cevaplar verdi.
- Hoca kablo türlerine de değindi:
  - Ethernet kablosunun 20'den fazla farklı adlandırması var.
  - Çiftlerin ayrı ayrı veya topluca kılıflı (shield) olup olmaması değişiyor.
  - Endüstriyel ve elektromanyetik gürültülü ortamlarda kablo malzemesi önemli hâle gelir.
  - Gigabit cihazda CAT4 veya CAT5 kablo sorun çıkarabilir.
- Aradığı cevap ise protokol ek yüküydü. 100 kilobit faydalı veri için hatta 100 kilobitten fazlası gider.

### Hız Tabloları

- Slaytta düşükten yükseğe hız ve mesafe tabloları var. Hız arttıkça desteklenen mesafe de değişiyor.
- Hoca bunları genel kültür olarak geçti, üzerinde durmadı.

### Ders sonrası notlar

- **Anycast:** Altyazıda "Nyquist" diye geçen adresleme modeli anycast'tir. Araçlar arası iletişimdeki (inter-vehicle communication) coğrafi türü geocast olarak da bilinir. Bunun Nyquist teoremiyle ilgisi yoktur.
- **ATM hücre boyutu:** Hoca, Avrupa'nın 48 bayt, ABD'nin 64 bayt istediğini söyledi. Bilinen tarih farklı:
  - Avrupa 32 bayt, ABD 64 bayt faydalı yük istedi.
  - Uzlaşma 48 bayt faydalı yük oldu. 48, ikinin kuvveti değildir.
  - Buna 5 baytlık başlık eklenince hücre 53 bayt oldu.
- **PDF'in standartlaşması:** PDF, 2008'de ISO 32000-1 olarak uluslararası standart oldu. Arşiv sürümü PDF/A ise 2005'te standartlaştı. Hoca "2000'lerin başı" dedi.
- **Fast Ethernet ve tel çiftleri:** Hoca, Fast Ethernet'te 8 telin dördünün bir yönde, dördünün diğer yönde kullanıldığını söyledi. Doğrusu:
  - 100BASE-TX dört çiftin yalnızca ikisini kullanır: bir çift gönderme, bir çift alma.
  - Dört çiftin hepsini kullanan Gigabit Ethernet'tir (1000BASE-T). Orada her çift aynı anda iki yönde çalışır.
- **Önekler:** Veri iletişiminde 1 kbps = 1000 bps'dir, 1024 değil. İkinin kuvvetleri (KiB, MiB) bellek ve dosya boyutunda kullanılır.
- **Altyazı hataları:**
  - "Tanenbaum"un kitabı *Computer Networks*'tür.
  - "Kaltof servisi" quality of service, "BSH video" VHS, "Bear" (twisted bear) twisted pair'dir.
  - "Etsy" ETSI'dir.
  - "Dejur" de jure, "Doğu Paşa" Davutpaşa'dır.
  - "Million access control" medium access control, "Bass" bus topolojisidir.

**Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
