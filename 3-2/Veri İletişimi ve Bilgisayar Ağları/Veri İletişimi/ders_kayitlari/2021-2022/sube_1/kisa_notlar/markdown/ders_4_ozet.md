# Ders 4 Çalışma Özeti

## Genel Konular

- Neden bu kadar ayrıntılı teknik konu öğreniliyor
  - Hoca, ders başlamadan önceki bir soru üzerine, bilgisayar mühendisinin amacının hazır teknolojileri yalnızca kullanmak değil, onları tasarlayabilecek hâle gelmek olduğunu söyledi.
  - Bir tekniğin nasıl tasarlandığını, hangi kriterlere göre seçildiğini bilmek, yeri geldiğinde kendi çözümünü (ör. kendi zamanlama algoritmasını ya da protokolünü) üretebilmeyi sağlar. Uygulama geliştirirken bile alttaki yapıyı bilmek doğru tasarım seçimini kolaylaştırır.
- IEEE 802 projesi
  - Aynı dönemde birbirine rakip olan Ethernet, Token Bus ve Token Ring gibi farklı LAN teknolojilerinin birlikte çalışabilmesi için başlatılmış bir projedir.
  - Slayttaki katman yapısı (ekrandan, 00:40:00): en altta her teknolojinin kendi fiziksel katmanı (802.3 Physical, 802.4 Physical, 802.5 Physical), onun üstünde her birinin MAC katmanı (802.3 CSMA/CD, 802.4 Token Bus, 802.5 Token Ring), bunların üstünde ortak 802.2 LLC, onun üstünde 802.1 Internetworking ve diğer katmanlar. 802.1 ağ katmanına, 802.2 ile MAC birlikte veri bağı katmanına, 802.x Physical fiziksel katmana karşılık gelir.
  - Hoca, içerik slaytında "IEEE 802.11 Projesi, 802.11.1 ... 802.11.5" yazdığını, bunun yanlış olduğunu, doğrusunun 802 projesi ve 802.1 ... 802.5 olduğunu belirtti (ekrandan, 00:35:00).
- Fiziksel katman
  - Sinyalin iletim ortamından nasıl gönderileceğini belirler: örneksel (analog) işaret mi kullanılacak, kullanılacaksa faz, genlik ya da frekans üzerinden mi modülasyon yapılacak, yoksa sayısal kodlama mı kullanılacak.
  - Zaman eşzamanlaması (ör. preamble) ile verinin gönderilip alınması fiziksel katmanın işidir.
- MAC (Media Access Control) alt katmanı
  - Paylaşılan iletim ortamının nasıl kullanılacağıyla ilgilenir (ekrandan, 00:45:00): an uyumluluğunun sağlanması (synch), bir uçtan diğerine aktarım için fiziksel adresleme, hata kontrolünün gerçekleştirilmesi.
  - LAN'da bağlantı çok noktalı (multipoint) ve ortam paylaşımlı olduğu için ortama kimin ne zaman erişeceği belirlenmelidir. WAN'da bağlantı noktadan noktaya olduğundan bu sorun daha basittir.
  - Ortak saat yoksa eşzamanlama mesajlaşmayla, yani mantıksal seviyede yapılabilir.
- LLC (Logical Link Control) alt katmanı
  - Veri bağı katmanının LAN'da ikiye bölünmesinin iki nedeni vardır (ekrandan, 00:50:00): ikinci katman fonksiyonları arasında paylaşımlı erişimli ortamların (shared access medium) yönetimini sağlayacak yapının bulunmaması ve aynı LLC için birden fazla MAC seçeneği sunulabilmesi.
  - LLC hata kontrolü ve akış kontrolü gibi işleri yapar ve bir donanım soyutlaması sağlar: üstte aynı işi yapan fonksiyon ailesi tanımlanır, altta hangi MAC varsa ona uygun fonksiyon çağrılır.
  - Üç servis tipi vardır (ekrandan, 00:55:00): alındı bilgisi yollanmayan bağlantısız servis (akış ve hata kontrolü yapılmayan basit datagram hizmeti), bağlantılı servis (bağlantı veri alışverişinden önce kurulur, akış ve veri kontrolü yapılabilir), alındı bilgisi yollanan bağlantısız servis (ön bağlantı kurmadan alındı bilgisi yollanan datagram servisi).
  - LLC PDU'sunda dört temel alan vardır: hedef adres, kaynak adres, kontrol alanı ve bilgi (kullanıcı verisi) alanı. Kontrol alanı, HDLC'deki I, S, U çerçevelerini ayırt etmeye benzer bir iş görür.
- IEEE 802.3 Ethernet'in tarihçesi ve gelişimi
  - Slayta göre (ekrandan, 01:00:00): 1972'de Robert Metcalfe ve Xerox PARC araştırmacıları Ethernet'i Xerox Alto için geliştirdi; deneysel çalışma 1973'te Alto Aloha Network diye adlandırıldı; 1979'da Metcalfe, Digital, Intel ve Xerox'u (DIX) ortak çalışmaya ikna etti; aynı yıl adı "Ethernet" yapılarak sistemin yalnız Alto'ya özgü olmadığı vurgulandı.
  - Kablolama kalın koaksiyelden (10Base-5) ince koaksiyele (10Base-2), sonra bükümlü çifte (10Base-T) ve fibere (10Base-F) geçti. Paylaşımlı yol yapısından hub'lara, sonra anahtarlamalı (switched) Ethernet'e geçildi. Hız ihtiyacı arttıkça yapı korunup hız artırıldı (Fast Ethernet), half-duplex'ten full-duplex'e geçildi.
  - MAC alt katmanındaki teknik, kullanım oranını artıracak biçimde gelişti (ekrandan, 01:05:00): orijinal MAC half-duplex tasarlandı, ortama bağlı olarak full-duplex de mümkün; yöntemler sırasıyla Aloha, Slotted Aloha, CSMA ve CSMA/CD.
- Aloha ve Slotted Aloha
  - Aloha, Hawaii Üniversitesi'nde adalardaki terminalleri ana karadaki bilgisayara telsizle bağlamak için geliştirildi. Verisi olan doğrudan gönderir, alıcı geri onay yollar. Onay zamanlayıcı süresinde gelmezse çarpışma olduğu kabul edilir, bir süre beklenip yeniden gönderilir. Trafiği düşük ağlar için uygundur. Kullanım oranı yaklaşık %18'dir.
  - Slotted Aloha'da kanal, her biri çerçeve iletim süresine eşit zaman dilimlerine (slot) bölünür (ekrandan, 01:10:00). Ortak bir zamanlama mekanizması gerekir, istasyon yalnız slot başında iletime geçebilir, slot boyu $T_{frame}$'e bir $\Delta T$ eklenerek belirlenir. Kullanım oranı yaklaşık %37'dir.
- CSMA (Carrier Sense Multiple Access)
  - Göndermeden önce hat dinlenir. Hat boşsa gönderilir, meşgulse beklenir (ekrandan, 01:20:00).
  - Yayılma gecikmesi (propagation delay) yüzünden uzaktaki istasyon iletimin başladığını hemen algılayamaz, bu yüzden birden fazla istasyon hattı boş görüp aynı anda gönderebilir. Çarpışma, alındı bilgisinin dönmemesiyle anlaşılır.
  - Hat meşgulken davranışa göre üç algoritma vardır:
    - Non-persistent: hat müsaitse gönder; meşgulse rastgele bir süre bekle ve yeniden dinle (ekrandan, 01:30:00). Rastgele bekleme çarpışmayı azaltır ama gereğinden uzun bekleme kapasite kaybına yol açar.
    - 1-persistent: hat meşgulse sürekli dinle, boşaldığı anda gönder. Bekleyen birden çok düğüm aynı anda atılacağı için çarpışma artar.
    - p-persistent: hat boşalınca $p$ olasılıkla gönder, $1-p$ olasılıkla ertele. $N$ istasyon bekliyorsa $N\cdot p$ değeri 1'i aşmayacak biçimde $p$ seçilmelidir.
  - Hocanın gösterdiği throughput grafiğinde sıralama: pure Aloha en düşük, sonra slotted Aloha, 1-persistent CSMA, 0.5-persistent CSMA, non-persistent CSMA ve en iyi 0.01-persistent CSMA. Hoca bunu "nezaket kazanıyor" diye özetledi.
- CSMA/CD
  - Çarpışmanın, onay gelmeyince değil, iletim sırasında fark edilmesi için ağ kartında donanımla gerçekleştirilen tekniktir. Kablolu ortamda mümkündür. Kablosuz ortamda kendi yayının sinyali çok güçlü olduğundan çarpışma algılanamaz, bu yüzden CSMA/CA kullanılır.
  - Akış (ekrandan, 01:35:00): bilgisayar iletime hazır, kanalı dinle; kanal kullanımdaysa yeniden dene; boşsa veriyi ilet ve kanalı dinlemeye devam et; çarpışma olmazsa iletim tamamlandı; çarpışma oluşursa durumu belirleyen jam sinyalini yolla, Exponential Binary Back-off algoritmasına göre bekle, yeniden dene.
- IEEE 802.3 çerçeve yapısı (ekrandan, 01:40:00)
  - Preamble (7 byte, `10101010`), SFD (1 byte, `10101011`), hedef adres (2-6 byte), kaynak adres (2-6 byte), uzunluk (2 byte), veri (46-1500 byte), CRC (4 byte).
  - İki adres alanı aynı uzunlukta olmalıdır. Veri 46 byte'tan kısaysa dolgu (padding) eklenir.
  - En kısa çerçeve 64 byte olmalıdır, çünkü daha kısa çerçevelerde çarpışma algılanamaz.
- IEEE 802.3 fiziksel katman tablosu (ekrandan, 01:45:00) ve diğer Ethernet standartları (ekrandan, 01:55:00)
- Anahtarlamalı (switched) Ethernet
  - Aynı hedefe farklı portlardan gelen çerçeveler anahtardaki bellekte tamponlanır; anahtar çerçeveleri MAC adresine bakarak iletir ve filtreler, MAC adres tablosu tutar, birden fazla düğümün aynı anda full-duplex haberleşmesine izin verir (ekrandan, 01:50:00).
  - Çarpışma alanı anahtar portu ile uçtaki bilgisayar arasına daralır, full-duplex bağlantıda CSMA/CD gerekmez.
  - Erişim, dağıtım ve omurga (core) anahtarlarından oluşan kademeli yapı; alt port kapasitesi ile uplink kapasitesinin oranı.
- Metro Ethernet ve Power over Ethernet (PoE)
- IEEE 802.4 Token Bus
  - Ethernet kötü durumda uzun beklemeye yol açabildiği için fabrika ortamındaki gerçek zamanlı uygulamalara uygun değildir (ekrandan, 02:05:00).
  - Fiziksel olarak yol ya da ağaç topolojisindeki bilgisayarlar mantıksal bir halka kurar; en büyük numaralı bilgisayar iletime geçer, sonra jetonu komşusuna verir. Jetonsuz istasyon iletemediği için çarpışma olmaz.
  - Çerçeve (ekrandan, 02:10:00): en az 1 byte preamble, SD, FC, adresler (2 ya da 6 byte, aynı ortamda eşit uzunlukta), veri, ED.
- Gerçek zamanlı sistem kavramı
  - Gerçek zamanlı sistem, işlerin bir zaman kısıtı içinde tamamlandığı sistemdir. Yumuşak (soft) gerçek zamanlı örnek MP3 çalar, katı (hard) gerçek zamanlı örnek trafik kazasına yol açabilecek bir fren sistemidir. Bunun için gecikmenin deterministik olması gerekir.
- IEEE 802.5 Token Ring
  - Halka topolojisinde veri olmasa bile 3 byte'lık jeton dolaşır (SD, AC, ED). Boş jetonu yakalayan istasyon yerine veri çerçevesini koyar, çerçeve halkayı dolaşıp gönderene döner, gönderen çerçevenin alındığını anlayınca jetonu geri koyar (ekrandan, 02:15:00).
  - Halkadaki bit sayısı formülü (ekrandan, 02:20:00).
  - Öncelik, rezervasyon, zaman sınırı ve monitör istasyon; hızlar 4 ve 16 Mbps, 802.5t ile 100 Mbps, 802.5v ile 1 Gbps; Differential Manchester kodlama; 6 byte NIC adresi; önce MSB gönderilir; veri, jeton ve abort olmak üzere üç çerçeve (ekrandan, 02:25:00).
- FDDI (Fiber Distributed Data Interface)
  - Fiber optikle 100 Mbps; bakır sürümü CDDI. Jeton ve öncelik mekanizması, senkron (S) ve asenkron (A) çerçeveler, üç zamanlayıcı: Sync Allocation, Target Token Rotation Time ve Absolute Maximum Time.
  - 4B/5B kodlama ve NRZ-I (ekrandan, 02:30:00).
  - PMD, çift halka, MIC; DAS, SAS, DAC, SAC, NAC cihazları (ekrandan, 02:40:00).

## Hocanın Özellikle Vurguladığı Kısımlar

- Yaygın tercih her zaman en doğru seçim değildir
  - Bugün veri bağı katmanında alındı bilgisi yollanmayan bağlantısız servis tercih edilir, çünkü bağlantılı servis her cihazın her akış için durum tutması, ek bellek ve işlemci demektir; servis sağlayıcılar bu maliyeti üstlenmek istemez ve güvenilirlik üst katmana bırakılır. Savunma sanayi ya da denizaltı gibi uygulamalarda bağlantılı ya da onaylı servis tercih edilebilir.
- Ethernet'te 64 byte alt sınırı ile Token Bus'ta büyük veri alanı aynı sorundan gelir
  - Ethernet'te çarpışma algılamanın çalışması için çerçevenin belli bir uzunlukta olması gerekir. Token Bus'ta çarpışma olmadığından veri çöpe gitme riski yoktur, bu yüzden çok daha büyük veri alanı (8182 byte) kullanılabilir.
- 100 metre sınırı
  - Standart 100 m diyorsa kablolama planını 90 m'ye göre yapmak gerekir.
- CSMA/CD kablosuz ortamda çalışmaz
  - Verici antenin kendi sinyali çok güçlü olduğu için çarpışma duyulamaz, bu yüzden kablosuzda CSMA/CA kullanılır.
- 4B/5B'deki fazla bit boşa değildir
  - 16 veri sembolü 32 kod içine yerleştirilir. Fazladan kodlar hat kontrol sembolleri (idle, başlangıç, bitiş vb.) için kullanılır. Kodlar iyi dağıtılırsa tek bitlik hata kullanılmayan bir koda düşer ve hata da yakalanır.
- Öncelikli yapılarda açlık (starvation) riski
  - Token Ring'deki öncelik mekanizması düşük öncelikli istasyonların uzun süre bekletilmesine yol açabilir. Bu yüzden rezervasyon ve zaman sınırı mekanizmaları vardır.
- Standartların ayrıntısı ezberlenmek zorunda değil
  - Hoca 100Base-TX, T2, T4 gibi standartların her ayrıntısının bilinmesini beklemediğini, kulak aşinalığı için anlattığını söyledi.

## Kısa Tekrar Notları

- IEEE 802: farklı LAN teknolojilerini ortak LLC (802.2) üzerinden birleştirir. Veri bağı = LLC + MAC.
- MAC: ortama erişim, eşzamanlama, fiziksel adresleme. LLC: hata ve akış kontrolü, donanım soyutlaması.
- LLC servisleri: onaysız bağlantısız, bağlantılı, onaylı bağlantısız.
- Aloha yaklaşık %18, Slotted Aloha yaklaşık %37 kullanım oranı.
- CSMA türleri: non-persistent (rastgele bekle), 1-persistent (sürekli dinle, hemen gönder), p-persistent ($p$ olasılıkla gönder).
- CSMA/CD: iletirken dinle, çarpışmada jam sinyali, exponential binary back-off.
- Ethernet çerçevesi: 7 + 1 + 6 + 6 + 2 + (46-1500) + 4 byte; en az 64 byte (preamble ve SFD hariç).
- Switched Ethernet: tamponlama, MAC tablosu, full-duplex, CSMA/CD gereksiz.
- Token Bus: fiziksel yol, mantıksal halka, en büyük ID başlar; çarpışma yok, veri alanı büyük.
- Token Ring: 3 byte jeton (SD, AC, ED), 4/16 Mbps, Differential Manchester, monitör istasyon.
- Halkadaki bit sayısı: $b = L / (SP \cdot 1/R)$. 1 Mbps, 200 m/µs, 1 km için 5 bit.
- FDDI: 100 Mbps fiber, çift halka, 4B/5B + NRZ-I, TTRT ve TRT'nin iki katı olan mutlak üst süre.

## Detaylı Açıklamalar

- **802 projesi ve katmanlar.** OSI modelinde farklı teknolojileri birleştiren katman ağ katmanıdır; IP her şeyi bir arada tutar. 802 projesi bu birleşmeyi veri bağı seviyesinde de sağlamak için veri bağı katmanını ikiye böler. Fiziksel katman ve MAC teknolojiye özgüdür, LLC ortaktır; böylece üstte internetworking (802.1) kurulabilir (ekrandan, 00:40:00).

- **LLC ve akış kontrolü.** Hoca akış kontrolünün neden gerektiğini şöyle açıkladı: iki taraf aynı hızda (ör. 100 Mbps) bağlı olsa bile alıcının işlemcisi ya da belleği gelen çerçeveleri işlemeye yetmeyebilir. Gönderen tarafta veri bağı katmanı ağ kartında donanımla hat hızında çalışırken alıcıda yazılımla yavaş çalışıyorsa akış sorunu doğar. Bunu çözmek LLC'nin işidir.

- **Slotted Aloha neden daha iyi.** Zaman slotlara bölündüğünde, slot ortasında verisi hazır olan istasyon bir sonraki slot başını bekler. Bir iletim başladıktan sonra o slotta araya girebilecek istasyon kalmaz; çarpışma yalnız aynı slot başında hazır olanlar arasında olur. Hoca bunu, konuşan birinin sözünü kesmek yerine durakladığı anı beklemeye benzetti. Gerçek bir örnek olarak araçlar arası haberleşmede GPS sinyaliyle saniye başında eşzamanlama yapıldığını anlattı.

> Ders sonrası not: Aloha için %18 ve Slotted Aloha için %37 değerleri $1/(2e) \approx 0{,}184$ ve $1/e \approx 0{,}368$ teorik üst sınırlarıdır (python ile kontrol edildi).

- **Ethernet çerçeve boyları.** Adresler 6 byte alınırsa en uzun çerçeve preamble ve SFD dahil $7+1+6+6+2+1500+4 = 1526$ byte'tır; hoca da önce 1524 deyip 1526 diye düzeltti. En kısa çerçeve preamble ve SFD hariç $6+6+2+46+4 = 64$ byte'tır; 46 byte'lık veri alt sınırı buradan gelir (python ile kontrol edildi).

- **IEEE 802.3 fiziksel katman tablosu** (ekrandan, 01:45:00):

| | 10Base-5 | 10Base-2 | 10Base-T | 10Broad-36 | 10Base-F |
|---|---|---|---|---|---|
| Takma isim | Thick | Thin | | | |
| Standart | IEEE 802.3 | IEEE 802.3a | IEEE 802.3i | IEEE 802.3b | IEEE 802.3j |
| İletim ortamı | Coax (50 Ω) | Coax (50 Ω) | UTP (2 çift kablo) | Coax (75 Ω) | FO (850 nm) LED |
| Band genişliği | 10 Mbps Half-Duplex | 10 Mbps Half-Duplex | 10 Mbps Full-Duplex | 10 Mbps | 10 Mbps Full-Duplex |
| Segment uzunluğu | 500 m | 185 m | 100 m | 1.8 km | MMF 2 km, SMF 5 km |
| Kapsama alanı | 2.5 km | 0.925 km | 0.5 km | 3.6 km | |
| İstasyon sayısı (max) | 100 | 30 | | | 33 |
| Sinyalleşme | Baseband Manchester | Baseband Manchester | Baseband Manchester | Broadband DPSK | Manchester |

> Ders sonrası not: Hoca 10Broad-36 için "1.6 km" dedi; slayttaki segment uzunluğu 1.8 km'dir.

- **Diğer Ethernet standartları** (ekrandan, 01:55:00): 802.3a/802.3i/802.3j Ethernet (10 Mbps); 802.3u/802.3y Fast Ethernet (100 Mbps); 802.3z/802.3ab Gigabit Ethernet (1 Gbps); 802.3ae/802.3ak/802.3an/802.3aq 10 GigE (10 Gbps); 802.3ba 40/100G Ethernet; P802.3bs 200/400 Gbps Ethernet; 802.11 a/b/g/n/ac kablosuz (11-600 Mbps); Metro Ethernet. Slaytta "801.11" yazıyordu, hoca bunun yanlış olduğunu söyledi. Yeni standartlar eski yatırımı çöpe atmamak için 802.3 MAC ile uyumlu kalmayı, ağ mimarisini değiştirmemeyi ve mevcut kablolamayı kullanabilmeyi ilke edinir.

- **Anahtar uplink oranı.** Hoca 24 portlu, her portu 1 Gbps olan bir erişim anahtarını örnek verdi: alt kapasite toplam 24 Gbps'tır. Uplink yuvasına 100 Gbps'lık modül takılırsa darboğaz olmaz; 10 Gbps'lık modül takılırsa bütün portlar tam kapasitede çalıştığında tıkanıklık kaçınılmazdır.

> Ders sonrası not: Altyazıda bu oran bozuk aktarılmış ("1 bölü 2"). Hesaplanırsa $24 \times 1 / 10 = 2{,}4$, yani alt kapasite uplink'in 2,4 katıdır (2,4:1).

- **PoE.** Ethernet kablosundaki dört bükümlü çift üzerinden cihaza elektrik de taşınır; bunun için power injector ya da PoE destekli kurumsal anahtar kullanılır. 48 portun hepsine aynı anda güç vermek çok yüksek güç gerektireceğinden aynı anda kullanılabilecek PoE port sayısı genelde sınırlanır.

- **Token Bus ayrıntıları.** Hoca, her istasyonun yaklaşık 10 farklı zamanlayıcı tutması gerektiğini ve 24 kadar durum olduğunu (yanlış hatırlamıyorsa) söyleyerek yapının karmaşık ve ek yükünün büyük olduğunu, bugün çok sınırlı kullanıldığını anlattı. Orijinal hız 1.5 ve 10 Mbps, sonraki sürümlerde 100 Mbps. Veri alanı 8182 byte'a kadar çıkabilir; bu Ethernet'in 1500 byte'ının beş katından fazladır.

- **Token Ring'de halkadaki bit sayısı** (ekrandan, 02:20:00):

$$\text{bir bit çıkarma süresi} = \frac{1}{R\ (\text{Mbps})} \quad (\mu s/\text{bit})$$

$$\text{bit uzunluğu} = SP\ (m/\mu s) \times \text{bir bit çıkarma süresi}\ (\mu s/\text{bit})$$

$$b = \frac{L}{\text{bit uzunluğu}}$$

  - Burada $SP$ halka üzerindeki sinyalin yayılma hızıdır, $L$ halkanın metre cinsinden uzunluğudur. Örnek: $R = 1$ Mbps, $SP = 200$ m/µs, $L = 1$ km için bit uzunluğu $200 \times 1 = 200$ m, $b = 1000/200 = 5$ bit (python ile kontrol edildi).

- **FDDI zamanlayıcıları.** Sync Allocation (SA), halka kurulurken her istasyon için ayrı belirlenir ve istasyonun S (senkron, zamana duyarlı) çerçeve yollamak için kullanabileceği süredir. Target Token Rotation Time (TTRT), jetonun halkayı dolaşması için beklenen ortalama süredir ve bütün istasyonlar için aynıdır. Absolute Maximum Time bunun iki katıdır; jeton bu süre sonunda hâlâ gelmemişse bir terslik var demektir.

- **4B/5B kod tablosu** (ekrandan, 02:30:00). 4 bitlik veriler 5 bitlik değerlerle değiştirilir ve elde edilen değer NRZ-I ile kodlanır. Slayttaki kontrol sembolleri:

| 5 bit | Açıklama |
|---|---|
| 00000 | Q (Quit) |
| 11111 | I (Idle) |
| 00100 | H (Halt) |
| 11000 | J (başlangıç belirleyicisi) |
| 10001 | K (başlangıç belirleyicisi) |
| 01101 | T (bitiş belirleyicisi) |
| 11001 | S (Set) |
| 00111 | R (Reset) |

- **FDDI çerçeveleri ve cihazlar.** Jeton çerçevesi SD, AC, ED'den oluşur; veri çerçevesinde SD, FC, 6'şar byte adresler, veri (en fazla 4500 byte), ED ve Frame Status bulunur. PMD katmanı iletimin ışıkla mı elektrikle mi yapılacağını belirler. Çoğu zaman iki halka vardır: iletim birincil halkadan yapılır, ikincil halka hata durumunda halkayı tamamlamak için kullanılır. İstasyonlar MIC (Media Interface Coupler/Controller) ile bağlanır (ekrandan, 02:40:00). Cihaz türleri: iki MIC'li dual attached station (pahalı), tek MIC'li single attached station, iki halkayı bağlayıp tek arabirimli cihazları toplayan dual attachment concentrator, single attached concentrator ve null attached concentrator.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
