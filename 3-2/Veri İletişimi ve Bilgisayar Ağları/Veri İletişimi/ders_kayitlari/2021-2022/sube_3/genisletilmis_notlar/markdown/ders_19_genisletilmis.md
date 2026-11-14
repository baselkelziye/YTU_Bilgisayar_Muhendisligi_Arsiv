# Ders 19 Genişletilmiş Notu: Öğrenci Proje Sunumları: GSM, ADSL, ISDN, Frame Relay, ATM, CATV, X.25 ve WiMAX

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dersin Düzeni ve Sunulan Konular
- 2. GSM (Global System for Mobile Communications)
- 3. ADSL (Asymmetric Digital Subscriber Line)
- 4. ISDN (Integrated Services Digital Network)
- 5. Frame Relay
- 6. ATM (Asynchronous Transfer Mode)
- 7. Hocanın Sunum Tavsiyesi
- 8. Kablo Televizyon Sistemleri (CATV)
- 9. X.25
- 10. WiMAX (IEEE 802.16)
- 11. Final Sorularının Biçimi
- Örnek Sorular
- Dersin Toparlaması

## 1. Dersin Düzeni ve Sunulan Konular

Bu ders Veri İletişimi dersinin son dersidir ve tamamen öğrenci proje sunumlarına ayrılmıştır. Kayıt, dersin oturum yönetiminin (host) Furkan Çakmak'a devredilmesiyle başlıyor; dersi baştan sona o yönetiyor. Dönem boyunca sekiz konu belirlenmiş ve her konu birden çok gruba verilmişti. Derste her konu için önce konu, sonra o konuyu hazırlayan gruplar arasından anlatacak grup kurayla seçildi. Kurada çıkmayan grupların hazırlıkları, önceden yükledikleri materyallerden değerlendirilecek.

Sunumlar şu sırayla yapıldı:

- GSM
- ADSL
- ISDN
- Frame Relay (gönüllü bir grup anlattı)
- ATM (gönüllü bir öğrenci anlattı)
- Kablo televizyon (CATV, Community Antenna Television)
- X.25 (gönüllü bir grup anlattı)
- WiMAX

> **Hocanın vurgusu:** Arkadaşlarınızın anlattığı konulardan da finalde sorumlusunuz. Yalnız kendi konunuzdan değil, sekiz konunun hepsinden soru gelebilir. Bu dersin videosu kayıt altında, izleyerek çalışabilirsiniz.

Bir öğrenci, sunumlarda eksik kalan kısımlardan da sorumlu olup olmayacaklarını sordu. Hoca, bir sunum çok eksik kalırsa başka bir gruba konuyu yeniden anlattırabileceğini, küçük eksikleri ise sunum sırasında kendisinin tamamlayacağını söyledi; böylece ders kapsamında eksik bırakılmayacak. Hoca ayrıca her grubun sunum sonunda, hatırlatma beklemeden, dinleyenlere soru olup olmadığını sormasını istedi.

## 2. GSM (Global System for Mobile Communications)

### 2.1 Tanım ve genel özellikler

GSM, dünyada kabul görmüş bir mobil iletişim sistemidir. Avrupa Telekomünikasyon Standartları Enstitüsü (ETSI) tarafından, el cihazlarında kullanılan ikinci nesil (2G) sayısal hücresel ağları tanımlamak için geliştirilmiş bir standarttır. Standart, çift yönlü (full duplex) ses iletimi için optimize edilmiştir ve ilk hâliyle devre anahtarlamalıdır (circuit switched). Sonradan önce GPRS ile paket veri aktarımı, ardından EDGE ile daha yüksek hızlı veri iletimi eklenerek genişletilmiştir.

Grup, GSM'in 900, 1800 ve 1900 MHz bantlarında çalıştığını, 1800 MHz'e optimize edilmiş sürümüne DCS 1800 (Digital Cellular System) dendiğini anlattı. Hava arayüzünde (air interface) TDMA (Time Division Multiple Access) kullanılır: aynı frekans farklı zaman dilimlerinde farklı kullanıcılara verilir. Sonraki bir konuşmacı fiziksel katmanda FDMA ve TDMA'nın birlikte kullanıldığını belirtti. <!-- BELİRSİZ: 00:20:28 civarında TDMA'nın "tek bir frekansla UDP'ye ulaşmayı sağladığı" ve "star ve mesh yapıda olabildiği" söyleniyor; altyazı bozuk, anlam net değil. -->

Sunumda GSM'in "açık kaynaklı, kod erişimine izin veren" bir sistem olduğu söylendi.

> **Ders sonrası not:** GSM açık bir standarttır, açık kaynak değildir. ETSI standart belgelerini yayımlar ve her üretici bu belgelere göre ürün yapabilir; ancak operatörlerin ve üreticilerin kullandığı yazılımlar büyük olasılıkla açık kaynak değildir.

### 2.2 Tarihçe

- Eski analog sistemler (AMPS ve TACS) az sayıda kullanıcıyı destekleyebiliyordu. Uluslararası alanda kullanılabilecek yeni bir sisteme ihtiyaç duyuldu.
- 1983'te CEPT bir çalışma grubu kurdu. Yeni sistemden beklenenler: uluslararası dolaşım (roaming) desteği, yüksek konuşma kalitesi, el cihazı desteği ve düşük maliyet.
- 1987'de Avrupa'da GSM'in standart olmasına dair düzenlemeler yapıldı.
- 1989'da GSM projesinin sorumluluğu CEPT'ten ETSI'ye geçti.
- 1991'de GSM tabanlı hizmetler Finlandiya'da başladı.
- 1993'te ilk DCS 1800 ağı İngiltere'de çalışmaya başladı. Aynı yıl Avustralya'da Telstra, GSM ağı kuran ilk Avrupa dışı operatör oldu.
- 2000'de ilk ticari GPRS hizmetleri ve GPRS uyumlu cihazlar sunuldu. GPRS, telefondan internete bağlanmayı sağlayan paket veri teknolojisidir.
- 2002'de MMS (multimedya mesajları) hizmete girdi. Ardından EDGE hizmetleri başladı.
- 2005'te HSDPA hizmete girdi.

Sunumda ayrıca GSM'in "2011'de bütün dünyaya kabul ettirildiği" söylendi.

> **Ders sonrası not:** GSM büyük olasılıkla 2000'lerin ortasında zaten dünyanın en yaygın mobil standardıydı; "2011'de kabul ettirildi" ifadesi yanıltıcıdır. Sunumda geçen HSDPA da GSM'in değil, 3G (UMTS) ailesinin veri hızlandırma teknolojisidir.

### 2.3 GSM'in yapısı

GSM dört ana birimden oluşur: mobil istasyon, baz istasyonu alt sistemi, anahtarlama alt sistemi ve operasyon destek alt sistemi.

**Mobil istasyon (MS, Mobile Station)** iki parçadan oluşur:

- Mobil ekipman (ME): Cihazın kendisidir. Her cihaza üretimde değişmeyen bir uluslararası mobil ekipman kimliği (IMEI) atanır. Cihazın çalıntı olup olmadığı bu numaraya bakılarak anlaşılır.
- Abone kimlik modülü (SIM): Bildiğimiz SIM karttır. Kullanıcı kimliğine ait bilgileri, bu arada uluslararası mobil abone kimliğini (IMSI) taşır. PIN ile korunan bir akıllı karttır.

**Baz istasyonu alt sistemi (BSS, Base Station Subsystem)**, radyo alt sistemi diye de anılır. Mobil istasyon ile anahtarlama merkezi arasındaki radyo iletişimini sağlar ve yönetir. İki bölümü vardır:

- Baz alıcı-verici istasyonu (BTS, Base Transceiver Station): Alıcı ve verici antenleri içerir. Radyo sinyallerini kodlar, şifreler, çoğullar, modüle eder ve antenlere besler. Mobil cihazla Um (radyo hava) arayüzü üzerinden konuşur.
- Baz istasyonu denetleyicisi (BSC, Base Station Controller): Radyo kaynaklarını yönetir; bölgedeki cihazlara zaman dilimlerini ve frekansları atar. BTS ile Abis arayüzü üzerinden konuşur.

**Anahtarlama alt sistemi (NSS, Network Switching Subsystem)**, çekirdek ağ diye de anılır:

- Mobil anahtarlama merkezi (MSC): Ana unsurdur. Çağrı yönlendirme, çağrı kurma, kayıt, konum güncelleme ve devir (handover) yönetimi yapar; BSS'ler ile MSC'ler arasında çağrı aktarımını yürütür.
- Ev konum kaydı (HLR, Home Location Register): Abonelerin kalıcı kayıtlarını ve son konumlarını tutan veritabanıdır. Gelen çağrı bu sayede doğru baz istasyonlarına yönlendirilir.
- Ziyaretçi konum kaydı (VLR, Visitor Location Register): HLR'den seçilmiş bilgileri içeren ayrı bir veritabanıdır. Bölgeye yeni giren cihazların bilgilerini tutar. Böylece HLR'nin sorgu yükü azalır ve erişim hızlanır.
- Kimlik doğrulama merkezi (AuC): Korumalı bir veritabanıdır. SIM karttaki gizli anahtarların kopyalarını tutar; kimlik doğrulamayı yapar ve radyo kanalındaki şifrelemeyi korur.
- Ekipman kimlik kaydı (EIR): IMEI'ye bakarak cihazı beyaz, gri ya da kara listeye alır. Beyaz listedeki cihaza izin verilir, kara listedeki engellenir, gri listedeki gözetim altında tutulur.
- Ağ geçidi MSC (GMSC): Başka ağlara açılan geçittir.

<!-- BELİRSİZ: 00:26:56 civarında EIR anlatılırken "uluslararası mobil abone kimlik numarası" deniyor; bağlamdan kastedilen IMEI'dir. -->

**Operasyon destek alt sistemi (OSS)**: GSM şebekesinin işletimi ve bakımıyla ilgilenir. Bir ya da birden çok operasyon bakım merkezini destekler; bu merkezler MS, BSC ve MSC'nin performansını izler.

### 2.4 Arayüzler

- Um (radyo hava arayüzü): MS ile BTS arası.
- Abis: BTS ile BSC arası.
- A: BSC ile MSC arası.
- B: MSC ile VLR arası; alandaki MS'lerin bilgilerine erişim.
- C: HLR ile GMSC arası; ağ dışından gelen bir aramanın tamamlanması için.
- D: VLR ile HLR arası bilgi geçişi.
- E: MSC'ler arası bilgi alışverişi.
- F: MSC ile EIR arası; IMEI doğrulaması burada yapılır.
- G: Farklı MSC'lere bağlı VLR'ler arası.
- H: Kısa mesaj iletiminde kullanılır.
- I: MSC ile MS arası. <!-- BELİRSİZ: 00:29:13'te "MSC ve M arasında" deniyor; MS kastedilmiş olabilir. -->

### 2.5 Hiyerarşik alanlar

GSM'de alanlar küçükten büyüğe şöyle sıralanır:

- Hücre (cell): Bir baz istasyonunun kapsadığı alandır. Her hücre evrensel hücre kimliği (Global Cell Identity) ile tanımlanır.
- Konum alanı (Location Area): Hücrelerin grubudur. Abone, çağrı geldiğinde bu alan içinde aranır. Bir konum alanına bir ya da birden çok BSC hizmet verebilir, ama MSC yalnızca bir tanedir. Her konum alanına bir konum alanı kimliği (LAI) atanır.
- MSC/VLR hizmet alanı: Bir MSC'nin kapsadığı ve VLR'sinde kayıtlı abonelere erişilebilen bölgedir.
- PLMN (Public Land Mobile Network) alanı: En büyük alandır; bir operatörün hizmet verdiği ağdır. Sunumda örnek olarak ABD'nin beş PLMN alanına bölündüğü bir şekil gösterildi.

### 2.6 Güvenlik

GSM kablosuz bir sistem olduğu için güvenli olacak şekilde tasarlanmaya çalışılmış, ama yine de saldırılara açıktır. Kimlik doğrulama meydan okuma-yanıt (challenge-response authentication) yöntemiyle yapılır: kullanıcıya önceden bir gizli bilgi verilir, ağ bir soru sorar ve kullanıcı doğru yanıtı üretirse hizmet devam eder.

GSM, akış şifreleri (stream cipher) de dahil olmak üzere birkaç şifreleme algoritması kullanır: A5/1, A5/2 ve A5/3. A5/1 ve A5/2 kırılmıştır ve yapıları araştırmacılar tarafından yayımlanmıştır; bu yüzden GSM bilinen düz metin (plaintext) saldırılarına karşı hassastır. Veri iletiminde kullanılan GPRS'in şifreleri GEA-1 ve GEA-2 de kırılmıştır; sunumda bunların 2011'de yayımlandığı söylendi. Paketlere erişmeyi sağlayan açık kaynak yazılımlar da yayımlandığı için GSM/GPRS saldırılara açık hâle gelmiştir.

### 2.7 Kısıtlar

- Elektronik karışma: GSM darbeli iletim (pulse transmission) kullanır ve bu, işitme cihazları gibi elektronik cihazlarda elektromanyetik parazit yapabilir. Havaalanlarında ve hastanelerde telefonların kapatılmasının ana nedeni budur.
- Bant genişliği gecikmesi: Birden çok kullanıcı aynı bant genişliğini paylaşır; kullanıcı sayısı arttıkça önemli gecikmeler olabilir.
- Sınırlı veri hızı: Daha yüksek hız için daha gelişmiş sistemleri destekleyen bir cihaza geçmek gerekir.
- Tekrarlayıcı (repeater) ihtiyacı: Kapsama alanını artırmak için tekrarlayıcılar gerekir. Tekrarlayıcı, evdeki Wi-Fi sinyal güçlendiricileri gibi bir yükselteç görevi görür.

### 2.8 GSM ile CDMA karşılaştırması

Grup GSM'i CDMA (Code Division Multiple Access) ile karşılaştırdı:

- Yaklaşım: GSM'de işlemler SIM kart üzerinden yürür; CDMA'da cihazın kendisi esastır.
- Teknoloji: GSM, FDMA ve TDMA kullanır; CDMA kod bölmeli çoklu erişim kullanır.
- Ağ: GSM'de her hücredeki kule o bölgedeki telefonlara hizmet verir; CDMA'da her cihaz için özel bir kod bulunur.
- İletim: Sunuma göre GSM'de ses ve veri aynı anda olabilir, CDMA'da olamaz.
- Dolaşım: GSM'de dünya çapında dolaşım vardır, CDMA'da daha sınırlıdır.
- Hız: Sunuma göre CDMA, GSM'den daha hızlıdır.

> **Ders sonrası not:** "CDMA'da ses ve veri aynı anda olmaz" ifadesi büyük olasılıkla yalnız CDMA2000 1x ve EV-DO gibi sistemler için geçerlidir. Klasik GSM/GPRS cihazlarının çoğunda da ses ve veri aynı anda kullanılamaz. Hız karşılaştırması da nesle göre değişir; 3G'de iki taraf da CDMA tabanlıdır (W-CDMA ve CDMA2000).

### 2.9 Protokol yapısı

GSM'de üç katmanlı bir yapı kullanılır; birimler arasındaki iletişim arayüzler üzerinden yürür.

- **Fiziksel katman:** FDMA ve TDMA kullanılır. MS ile BTS arasındaki Um arayüzünün temelini oluşturur. BTS, MS'den aldığı bilgiyi 64 kbps'lik sayısal biçime çevirir ve Abis arayüzüyle BSC'ye iletir.
- **Veri bağı katmanı:** Bağlantının kurulup güvenli biçimde sürdürülmesini ve hata tespitini sağlar. LAPD ve LAPDm kullanılır. LAPDm, LAPD'nin hava arayüzüne uyarlanmış ve CRC içermeyen sürümüdür.
- **Üçüncü katman:** Üç alt katmana bölünür:
  - Radyo kaynak yönetimi (RR, Radio Resource Management): MS ile ağ arasındaki temel bağlantıyı ve cihazların kullandığı radyo kaynaklarının yönetimini sağlar.
  - Hareketlilik yönetimi (MM, Mobility Management): Mobil istasyonun konumunu sürekli takip eder.
  - Bağlantı yönetimi (CM, Connection Management): En üst seviyededir; çağrı kontrolünü, SMS servisini ve ek servisleri yönetir.

BTS ile BSC arasında (Abis) RR yerine BTSM adlı ayrı bir katman bulunur. BSC ile MSC arasında (A arayüzü) ise RR'nin yerini BSSMAP alır; MM ve CM katmanları ise olduğu gibi kalır.

### 2.10 Adresleme ve numaralar

- IMEI: Her mobil cihazı uluslararası geçerlikte tanımlar. Çalıntı ya da çalışmayan cihazlar bununla ayırt edilir.
- IMSI (International Mobile Subscriber Identity): Her aboneyi tanımlar, SIM kartta bulunur.
- MSISDN (Mobile Subscriber ISDN Number): Bildiğimiz telefon numarasıdır, her SIM karta özeldir.
- MSRN (Mobile Station Roaming Number): Bölgedeki VLR'nin atadığı, konuma bağlı geçici bir numaradır. MSISDN ile aynı temel yapıdadır.
- LAI (Location Area Identity): Her konum alanını uluslararası standartta tanımlar.
- TMSI (Temporary Mobile Subscriber Identity): VLR'nin atadığı, yalnız o bölgede geçerli geçici kimliktir; HLR'ye aktarılmaz.
- LMSI (Local Mobile Subscriber Identity): VLR'nin atayabildiği, veritabanı erişimini hızlandırmak için ek bir arama anahtarı olarak kullanılan numaradır.
- Hücre kimliği (Cell Identifier): Konum alanı içindeki her hücreyi tanımlar. LAI ile birleşerek evrensel hücre kimliğini (Global Cell Identity) oluşturur.

### 2.11 Hocanın sorusu

**Soru (hoca):** Araştırmalarınızda SIM teknolojisiyle ilgili bir şey gördünüz mü? Şu an kullanılan SIM kartların yerine yeni bir teknoloji çıkıyor; bununla ilgili bilgi araştırdınız mı?

**Cevap (grup):** Grup, GSM'in temel yapısını ve ilk çıkışından bu yana nasıl bir yapıda olduğunu araştırdıklarını, en yeni teknolojilere (state of the art) bakmadıklarını söyledi.

## 3. ADSL (Asymmetric Digital Subscriber Line)

### 3.1 Tanım

ADSL, geleneksel telefon hattı üzerinden kurulan çevirmeli bağlantılara göre çok daha yüksek hız sunan bir iletişim teknolojisidir. Fiber optik kablo gerektiren yeni teknolojilere göre daha esnektir, çünkü onlarca yıldır sesli arama için kullanılan bakır hatlar üzerinde çalışır. Bir tür sayısal abone hattı (DSL) teknolojisidir; "asimetrik" adı, indirme ve yükleme hızlarının farklı olmasından gelir.

### 3.2 Tarihçe

- Bellcore çalışanları, telefon santrali ile müşteri arasındaki bükümlü bakır çift üzerinde, temel bant analog ses sinyalinin üstündeki frekanslara geniş bant sayısal sinyal yerleştirerek ADSL'i geliştirdi ve 1988'de patentini aldı. O dönemki maliyetler yüzünden hemen yaygınlaşamadı.
- 1990'larda telefon şirketleri bakır hatlar üzerinden hizmet sunmak için DSL türlerini kullanmaya başladı; önce küçük işletmelere, sonra evlere ADSL tanıtıldı.
- 1995 civarında şirketler ADSL'i daha hızlı internet erişimi ihtiyacını karşılamanın gerekli bir yolu olarak görmeye başladı.
- ADSL standardı T1.413 ilk olarak 1995'te ANSI T1E1 komitesi tarafından yayımlandı. Daha sonra ITU-T tarafından G.992.1 ve G.992.2 olmak üzere iki sürüm standartlaştırıldı.
- 1998 civarında ANSI T1.413'ü izleyen hemen hemen tüm satıcılar DMT (Discrete Multi-Tone) modülasyonunu benimsedi.
- ADSL önce 1990'larda ABD'de, 2000'lerde ise genel olarak yaygınlaştı.

Grup DMT'yi, ADSL ve güç hattı gibi kablolu kanallarda alıcı-vericinin performansını iyileştirmek için çeşitli bit yükleme algoritmalarıyla birlikte kullanılan bir dikgen frekans bölmeli çoğullama (OFDM) çeşidi olarak tanımladı. Eski ADSL standartları yaklaşık 2 km'lik bükümlü bakır çift üzerinden yaklaşık 8 Mbps sağlayabiliyordu; yeni türevler bu değerleri iyileştirdi.

### 3.3 Çalışma mantığı

ADSL, telefon görüşmelerinin kullanmadığı frekans spektrumunu kullanır. Ayırıcı (splitter) denen bir filtre, ses ve veri frekans bantlarını birbirinden ayırır; böylece tek bir telefon hattı hem ADSL hem de telefon görüşmesi için aynı anda kullanılabilir. ADSL, bakır hattın yaklaşık 1 MHz'lik bant genişliğini yaklaşık 4 kHz'lik kanallara böler. En alttaki kanal telefon (POTS) görüşmeleri ve faks için, diğer kanallar paralel sayısal iletişim için kullanılır. ADSL asimetrik olduğundan indirme (downlink) için yükleme (uplink) yönünden çok daha fazla kanal ayrılır.

<!-- BELİRSİZ: 00:48:16–00:48:33 arasında kanal sayıları bozuk: "256 kanal", "downlink için 190", "uplink için 64 kanal" gibi değerler geçiyor ve birbirini tutmuyor. -->

> **Ders sonrası not:** Sunumdaki kanal sayıları karışık. Standart ADSL'de büyük olasılıkla 256 alt kanal vardır ve her biri 4,3125 kHz genişliğindedir; toplam $256 \times 4{,}3125 = 1104$ kHz eder (yaklaşık 1,1 MHz). Yükleme için yaklaşık 25–138 kHz arası (yaklaşık 25 kanal), indirme için yaklaşık 138 kHz–1,1 MHz arası (yaklaşık 224 kanal) kullanılır.

ADSL genellikle santrale yakın aboneler için uygundur. Sunuma göre ortalama 4 km'den kısa mesafeler için kurulur; kablo kalitesi izin verirse 8 km'yi aşabilir. ADSL hızını etkileyen etkenler: santrale uzaklık, kablonun özellikleri, AM radyo yayınlarından gelen parazitler ve modemin bulunduğu yerdeki yerel elektriksel parazitler.

### 3.4 Avantajlar, literatür ve kullanım

Avantajları:

- Mevcut telefon bağlantısını bozmadan tek bir bakır çift üzerinden kullanılır; ek hat gerekmez.
- Geleneksel ses bandı modemlerinden çok daha hızlıdır.

Grup literatürden birkaç çalışma aktardı:

- ADSL'de ses iletimindeki en büyük sorun, diğer uygulamalardan gelen veri trafiğidir. Bir çalışmada, simülasyonlarla, yukarı yön bit hızı artırılmasa bile ses trafiği performansının diğer veri trafiğine göre iyileştirilebildiği gösterilmiş.
- Dermatoloğa erişimin zor olduğu bölgelerde ADSL üzerinden uzaktan muayene hizmeti verilmesini inceleyen bir çalışma.
- 2021'de yapılmış bir çalışmada kablo arıza durumunu sınıflandırmak ve tahmin etmek için makine öğrenmesi kullanılmış. Karar ağaçları, k en yakın komşu, çok katmanlı algılayıcı, naive Bayes ve rastgele orman gibi algoritmalar WEKA yazılımıyla karşılaştırılmış.

Bugün fiber optik kablolar yaygınlaşsa da ADSL birçok evde hâlâ kullanılıyor. Sebepleri: bazı bölgelere fiber henüz ulaşmamış olması, bazı evlerde yüksek hıza ihtiyaç duyulmaması ve ADSL'in daha ucuz olması. En büyük dezavantajı, santrale uzaklığın kullanıcının hızını çok etkilemesidir. Türkiye'de ADSL hizmeti veren sağlayıcılara örnek olarak Türk Telekom, Superonline, TurkNet ve Millenicom verildi. Grup, VDSL ve fiber gibi teknolojiler yerini alsa da ADSL'in önümüzdeki yıllarda da kullanılmaya devam edeceğini öngördü.

## 4. ISDN (Integrated Services Digital Network)

### 4.1 Tanım ve tarihçe

ISDN'in Türkçe karşılığı "Tümleşik Hizmetler Sayısal Şebekesi"dir. Ses, veri ve görüntünün sayısal bir ortamda aynı ağ üzerinden iletilmesini sağlayan bir haberleşme ağı teknolojisidir. Analog hatlardan farklı olarak hem temiz bir sayısal ses kanalı hem de aynı anda veri iletimi sağlar.

ISDN konsepti, eski analog telefon sisteminin (POTS) bir uzantısı olarak ortaya çıktı. Dünyanın birçok yerinde kullanıldı, ama ADSL piyasaya çıkınca güçlü bir rekabetle karşılaştı ve çoğu ülkede yaygınlaşamadı. Sunuma göre ABD'de neredeyse hiç kullanılmadı. Japonya'da 1990'ların sonunda ADSL'in gelişiyle rağbeti azalsa da uzun süre popüler kaldı. Bugün ADSL, DSL ya da fiberin tercih edilmediği yerlerde kullanılıyor.

ISDN'de bilgi son kullanıcıya kadar sayısal olarak taşınır, en sonda telefon makinesinin algılayabileceği analog sinyale çevrilir. Bilginin sayısal taşınmasının iki avantajı vardır:

- Bilgi gürültüden daha az etkilenir, ses kalitesi yükselir.
- Bilgi son noktaya kadar sayısal geldiği için üzerinde görüntü, ses, veri gibi farklı uygulamalar çalıştırılabilir.

### 4.2 Kanallar

ISDN'de iki çeşit kanal vardır:

- **B kanalları (bearer):** Sistemin temelidir. Her biri 64 kbps taşır; sayısal ses, görüntü ve veri bu kanallarda iletilir. Sayıları 2, 23 ya da daha fazla olabilir, ama iletişimin denetimi için mutlaka D kanalına ihtiyaç duyarlar.
- **D kanalı (delta):** İletişimin denetimi için kullanılır. Hat açma-kapama ve sinyallerin alınıp gönderilmesi görevlerini üstlenir.

Sunumda "D kanalının büyüklüğünün B kanal sayısını belirlediği; B kanal sayısı arttıkça kontrol sinyali ihtiyacının arttığı" söylendi.

> **Ders sonrası not:** Kanal düzenini belirleyen arayüz tipidir (BRI ya da PRI). B kanal sayısı arttıkça sinyalleşme yükü arttığı için PRI'da D kanalı daha geniştir: BRI'da 16 kbps, PRI'da 64 kbps.

### 4.3 Cihazlar

ISDN cihazları dört başlıkta toplanır: terminal adaptörleri (TA), ağ sonlandırma cihazları (NT), hat sonlandırma ekipmanları (LT) ve santral sonlandırma ekipmanları (ET). Sunuma göre terminal adaptörü tarafı genelde 4 telli, ağ ve hat sonlandırma tarafı 2 tellidir.

### 4.4 Arayüzler: BRI ve PRI

- **BRI (Basic Rate Interface, temel oran arayüzü):** Ev kullanıcıları ve küçük işletmeler için tasarlanmıştır. İki B kanalı ve bir D kanalından oluşur (2B + D). B kanalları 64 kbps'de kullanıcı verisini taşır. D kanalı 16 kbps'de çalışır; kontrol ve sinyalleşme bilgisini taşır, belirli koşullarda kullanıcı verisi de taşıyabilir.
- **PRI (Primary Rate Interface, birincil oran arayüzü):** Büyük işletmeler için tasarlanmıştır. Kuzey Amerika ve Japonya'da 23B + D, Avrupa, Avustralya ve dünyanın diğer bölgelerinde 30B + D yapısındadır.

Bu değerlerle kullanıcıya açık toplam kapasiteler şöyle hesaplanır (ara adım eklendi):

$$\text{BRI: } 2 \times 64 + 16 = 144 \text{ kbps}$$

$$\text{PRI (T1): } 23 \times 64 + 64 = 1536 \text{ kbps}, \qquad \text{PRI (E1): } 30 \times 64 + 64 = 1984 \text{ kbps}$$

> **Ek bilgi (derste anlatılmadı):** PRI'nın taşındığı hatların toplam hızı çerçeveleme bitleri yüzünden bundan biraz büyüktür: T1'de 8 kbps çerçeveleme eklenince 1544 kbps, E1'de 64 kbps eşzamanlama kanalı eklenince 2048 kbps elde edilir. Türkiye'deki PRI hatları büyük olasılıkla E1 tabanlıdır.

### 4.5 Katmanlar

ISDN üç katmandan oluşur:

- **Birinci katman (fiziksel):** Çerçeve biçimi, çerçevenin terminalden ağa mı yoksa ağdan terminale mi gittiğine göre farklıdır. Sunuma göre çerçeveler 48 bit uzunluğundadır ve bunların 36 biti veriyi temsil eder. Birden fazla ISDN cihazı aynı devreye fiziksel olarak bağlanabilir.
- **İkinci katman:** D kanalı üzerindeki bağlantı erişim prosedürü LAPD'dir (Link Access Procedure on the D channel). LAPD, HDLC ve LAPB ile benzerlik gösterir. Kontrol ve sinyalleşme bilgisinin D kanalı boyunca doğru aktarılmasını sağlar. Sunuma göre LAPD adres alanı, ilk baytın genişletilmiş adres (EA) bitine göre 1 ya da 2 bayt olabilir.
- **Üçüncü katman:** Kullanıcıdan kullanıcıya devre anahtarlamalı ve paket anahtarlamalı bağlantıları destekler. Kurulum (setup), bağlan (connect), kullanıcı bilgisi, iptal, durum, bağlantıyı kes (disconnect) gibi çağrı kurma ve sonlandırma mesajları bu katmanda tanımlanır.

48 bit ve 36 bit değerleri BRI ile tutarlıdır (ara adım eklendi): BRI'nın S/T arayüzünde bir çerçeve 250 µs sürer, yani saniyede 4000 çerçeve gönderilir. Her çerçevede her B kanalından 2 × 8 bit ve D kanalından 4 bit bulunur:

$$2 \times (8+8) + 4 = 36 \text{ bit}, \qquad 36 \times 4000 = 144 \text{ kbps}, \qquad 48 \times 4000 = 192 \text{ kbps}$$

Kalan 12 bit çerçeveleme ve denge bitleridir; arayüzün toplam hızı 192 kbps'tir.

> **Ders sonrası not:** 250 µs çerçeve süresi ve 192 kbps toplam hız sunumda geçmedi; bu değerler büyük olasılıkla ITU-T I.430 tanımından gelir. LAPD'de adres alanı pratikte büyük olasılıkla hep 2 bayttır (SAPI ve TEI); EA biti adres alanının nerede bittiğini gösterir.

### 4.6 Avantajlar

- Paket anahtarlamalı veri ve telefon hizmeti için tamamen sayısal olanaklara erişim sağlar.
- Bant dışı (out-of-band) kanal sinyalleşmesi kullandığı için çağrı kurulumu çok daha hızlıdır.
- B kanallarıyla kanal başına 64 kbps sağlar; ses bandı modemlerinden çok daha hızlıdır.
- Görüntü, ses, metin ve veri aynı anda iletilebilir.
- Tamamen sayısal olduğu için hata olasılığı düşüktür.

### 4.7 Soru-cevap

**Soru:** ADSL çıkınca ISDN'in kullanımı azaldı, ama Japonya'da hâlâ popüler olduğunu söyledin. Bunun sebebi maliyet mi, hız mı, başka bir özelliği mi? Neden ADSL'e geçilmemiş?

**Cevap:** Sunan öğrenciye göre ADSL ABD'de 1990'ların başında kullanılmaya başlandı, diğer ülkelere yayılması 1990'ların sonu ile 2000'lerin başını buldu. Japonya'da ISDN için bir altyapı önceden kurulmuş olduğu için ADSL ile birlikte kullanılmaya devam edildi.

## 5. Frame Relay

Bu konuyu, ders başında gönüllü olan bir grup anlattı; sunumun son kısmı İngilizce yapıldı.

### 5.1 Tanım, avantajlar ve dezavantajlar

Frame Relay, büyük verileri paketler (çerçeveler) hâlinde geniş alan ağları (WAN) üzerinden yüksek hız ve verimlilikle ileten bir veri iletişim teknolojisidir. Sunuma göre kullanımının yaklaşık %90'ı yerel alan ağlarını (LAN) birbirine bağlamaktır. Veri paket anahtarlamalı iletildiği için bir hat birden çok kullanıcı ve ağ tarafından paylaşılabilir. Frame Relay veride hata düzeltme yapmaz; hatanın ele alınmasından verinin gideceği uç nokta sorumludur.

Avantajlar:

- Sunuma göre 45 Mbps'e kadar, fiberle 2,4 Gbps'e kadar hız sağlayabilir.
- Sunuma göre kiralık hat maliyetlerini yaklaşık %50 azaltır.
- Gecikmesi düşük, verimliliği yüksektir.
- 4096 bayta kadar çerçeveleri işleyebilir; yüksek hacimli veri iletimi için uygundur.

Dezavantajlar:

- Ses iletimine uygun değildir. Değişken boyutlu çerçeveleri işlediği için değişken gecikmelere yol açar; gerçek zamanlı sesli ve görüntülü konferans için uygun değildir.
- Şifreleme yoktur, güvenilirliği düşüktür. Eski bir teknolojidir; bugün yerine VPN kullanılır.

> **Ders sonrası not:** Frame Relay'in tipik erişim hızları büyük olasılıkla 56 kbps ile 45 Mbps (T3) arasındadır; "fiberle 2,4 Gbps" yaygın uygulamaları yansıtmaz. "%50 maliyet azaltma" oranı da altyazıdan doğrulanamaz, kaynağına göre değişir.

### 5.2 Mimari

Örnek şekilde beş cihaz Frame Relay ağı üzerinden birbirine bağlıdır. Her cihaz ağa bir erişim bağlantısı (access link) ile ulaşır.

- **DTE (Data Terminal Equipment):** Uçtaki cihazlardır; kullanıcı verisini paketleyip ağa çıkarır.
- **DCE (Data Circuit-terminating Equipment):** Erişim bağlantılarının bağlandığı, Frame Relay ağının içindeki anahtarlardır (switch). Ağ hizmetini sunar, gerektiğinde hattı kesebilir.
- **LMI (Local Management Interface):** Erişim bağlantıları üzerinde bulunan yönetim arayüzüdür. Sunuma göre gelen verinin geçerli bir adres içerip içermediğini sorgular.

Cihazlar Frame Relay üzerinden veri göndermek istediğinde verinin bu katmana uygun hâle getirilmesi, yani kapsüllenmesi (encapsulation) gerekir. Kapsüllenmemiş veri ağa kabul edilmez.

### 5.3 Çerçeve yapısı ve veri aktarımı

Frame Relay çerçevesi şu alanlardan oluşur: başta ve sonda bayrak (flag), adres, veri ve FCS (Frame Check Sequence).

- **Adres alanı:** İçindeki DLCI (Data Link Connection Identifier), verinin gideceği yolu belirtir. Bir yönlendiriciden (router) diğerine aktarım sırasında izlenecek sanal devre bu numarayla gösterilir. Sunuma göre DLCI'ler genellikle 10 bittir ve her bağlantı için tekildir. Adres alanında FECN ve BECN bitleri de bulunur.
- **FCS:** Gönderici veriyi matematiksel bir işlemden geçirip sonucu çerçeveye ekler; alıcı aynı işlemi yapar. Sonuçlar uyuşuyorsa veri doğru alınmıştır.

Bir yönlendirici birden çok yönlendiriciye veri aktarabilir, ama bunu aynı anda değil sırayla yapar; hangi hedefe gidileceği DLCI ile ayırt edilir. 10 bitlik DLCI ile $2^{10} = 1024$ farklı değer elde edilir (ara adım eklendi).

Sunumda FCS uyuşmazsa "verinin yeniden alınacağı, bunun geri bildirimle bildirileceği" ve FECN/BECN'nin "hata bildirimi" olduğu söylendi.

> **Ders sonrası not:** Frame Relay, FCS ile bozuk çıkan çerçeveyi atar; yeniden gönderimi Frame Relay değil, uç sistemlerdeki üst katmanlar yapar. Bu, sunumun başındaki "hata düzeltme yapmaz" ifadesiyle tutarlıdır. FECN (Forward Explicit Congestion Notification) ve BECN (Backward Explicit Congestion Notification) hata değil, tıkanıklık (congestion) bildirim bitleridir.

### 5.4 Sanal devreler

Sunumun son kısmı İngilizce anlatıldı. Sanal devre (virtual circuit), bağlantı yönelimli (connection-oriented) hizmet sunan bir ağ yapısıdır. Veri iletimi süresince iki düğüm arasında kaynak ayrılır. Güvenilir bir aktarım ortamıdır, ama uygulanması maliyetlidir. Sanal devreler çift yönlü iletim yolu sağlar ve DLCI ile tekil olarak tanımlanır. Birden çok sanal devre tek bir fiziksel devre üzerinde çoğullanabilir.

Kalıcı sanal devrelerde (PVC, Permanent Virtual Circuit) devre sürekli kurulu olduğu için DTE cihazları hazır olduklarında veri göndermeye başlayabilir. PVC üzerindeki iletişim, anahtarlamalı sanal devrelerde (SVC, Switched Virtual Circuit) gereken çağrı kurma ve sonlandırma aşamalarına ihtiyaç duymaz. <!-- BELİRSİZ: 01:14:48–01:15:44 arası altyazı boş ya da anlamsız; bu aralıkta anlatılan kısım aktarılamadı. -->

## 6. ATM (Asynchronous Transfer Mode)

Bu konuyu, aradan sonra gönüllü olan bir öğrenci tek başına anlattı.

### 6.1 Gelişimi

Teknoloji kurumlar ve insanlar arasında hemen her noktada kullanılır oldu; elde edilen verilerin boyutları da büyüdü. Örneğin fotoğraf makinelerinin çözünürlüğü arttıkça görüntü ve video dosyaları büyüdü. Bu verileri taşıyacak ortamlar eskiden zor sağlanıyordu. ITU-T, 1980'lerde iletimi kolay, hızlı ve az kayıplı hâle getirmek için önce ISDN standardını oluşturdu. Bu standarttan yeterli verim alınamayınca geniş bantlı ISDN (B-ISDN) standardını geliştirdi. ATM, bu standardın aktarım tekniğidir.

> **Ders sonrası not:** Sunumda ISDN'in açılımı "Integrated Switched Digital Networks" diye verildi. Doğrusu "Integrated Services Digital Network"tür.

Genel resim şudur: ATM veriyi hücrelere böler, hücreleri sanal kanal ve sanal yollar üzerinden bir anahtara gönderir. Anahtar da hücreyi yine sanal kanal ve yollar üzerinden hedefe ulaştırır.

### 6.2 Hücre yapısı

ATM'de veri 53 baytlık sabit boyutlu hücrelere (cell) bölünür. Bunun yalnız 48 baytı yük (payload), yani kullanıcı verisidir; kalan 5 bayt başlıktır (header):

$$48 + 5 = 53 \text{ bayt}$$

Sunumda 53'ün nereden geldiği şöyle anlatıldı: Taraflardan biri 48, diğeri farklı bir değer istemiş, orta noktada uzlaşılmış. <!-- BELİRSİZ: 01:36:56–01:37:04'te "bu ATM uygulamasını Japonlar geliştiriyor, onlar 48 olsun, Avrupa 63 olsun diyor" gibi bozuk ifadeler var. -->

> **Ders sonrası not:** 48 baytlık yük büyük olasılıkla ABD ile Avrupa arasında bir uzlaşmadır: ABD 64 bayt, Avrupa ise ses gecikmesini azaltmak için 32 bayt istedi; CCITT (ITU-T) ikisinin ortalaması olan 48 baytı seçti. 5 baytlık başlık bunun üstüne eklendi.

Başlıkta şu alanlar tanımlıdır:

- Genel akış kontrolü (GFC, Generic Flow Control)
- Sanal yol belirleyici (VPI, Virtual Path Identifier)
- Sanal kanal belirleyici (VCI, Virtual Channel Identifier)
- Yük tipi (PT, Payload Type)
- Hücre kaybı önceliği (CLP, Cell Loss Priority)
- Başlık hata kontrolü (HEC, Header Error Control)

Başlık, kullanıcı-ağ arayüzünde (UNI) ve ağ-ağ arayüzünde (NNI) farklıdır. GFC yalnızca UNI'de bulunur. NNI'de bu 4 bitlik alan VPI'ye katılır. Sunumda UNI'de 4 bit GFC ve 12 bit VPI, NNI'de ise 16 bit VPI olduğu söylendi.

> **Ders sonrası not:** Sunumdaki VPI uzunlukları büyük olasılıkla yanlıştır. UNI başlığı GFC 4, VPI 8, VCI 16, PT 3, CLP 1, HEC 8 bittir. NNI başlığında GFC yoktur, VPI 12 bittir. İki durumda da toplam $4+8+16+3+1+8 = 12+16+3+1+8 = 40$ bit, yani 5 bayttır.

Alanların anlamı:

- **VCI ve VPI:** Hücrenin bir sonraki adımda hangi anahtara gideceğini gösterir. Sanal yol, birçok sanal kanalın bir araya gelmesiyle oluşur. İkisi birlikte bir rota bilgisi gibi düşünülebilir.
- **Yük tipi:** Hücrenin taşıdığı yükün cinsini belirtir: kontrol verisi, bakım verisi ya da kullanıcı verisi. Belli bir kodlaması vardır.
- **Hücre kaybı önceliği:** Hatta yoğunluk olduğunda hücrenin atılıp atılamayacağını gösterir. CLP = 1 ise hücre atılabilir, CLP = 0 ise atılmamalıdır.
- **Başlık hata kontrolü:** Hataları denetler.

> **Ek bilgi (derste anlatılmadı):** HEC alanı yalnız başlığın ilk 4 baytını korur, yükü korumaz. Bu alan, başlıktaki tek bitlik hataları düzeltmek ve çok bitlik hataları tespit etmek için kullanılan 8 bitlik bir CRC'dir. Yükteki hataların denetimi büyük olasılıkla üst katmanlara (AAL) bırakılmıştır.

### 6.3 Anahtarlama

ATM anahtarlamada VCI bir sonraki anahtarı gösterir; VPI ise sanal kanalların bir araya gelmesinden oluşan sanal yoldur. Sunumdaki örnekte port 1'den VPI/VCI değerleri 6 ve 4 olan bir hücre gelir. Anahtar, tablosuna bakarak hücreyi port 3'e yönlendirir. Yönlendirmeden önce başlıktaki etiketleri değiştirir: VPI/VCI alanlarına 2 ve 9 yazar ki bir sonraki anahtar da hücreyi yönlendirebilsin.

ATM'in paket anahtarlama mı devre anahtarlama mı olduğu sorusu da ele alındı. Veriyi hücrelere böldüğü için paket anahtarlamaya benzer. Ama sanal devreler kullandığı için devre anahtarlamanın özelliklerini de taşır. Yani ATM, ikisinin olumlu yanlarını birleştirerek daha verimli bir sonuç elde eder.

### 6.4 Bağlantılar ve arayüzler

İki uç arasında iletim kurulduğunda sanal kanallar ve sanal yollar oluşur. Bir sanal yolun içinde birden çok sanal kanal bulunur ve bunlar birlikte bir sanal devre bağlantısı oluşturur. Sanal kanalların yolunu VCI, sanal yolların yolunu VPI belirler.

ATM'de üç tip arayüz vardır:

- **UNI (User-Network Interface, kullanıcı-ağ arayüzü):** Bir ATM uç noktası ile anahtar arasındaki arayüzdür.
  - Özel UNI: Özel bir ATM ağı içindeki uç nokta ile anahtar arası.
  - Genel UNI: Özel ağdaki uç nokta ya da anahtar ile genel ağdaki bir anahtar arası.
- **NNI (Network-Node Interface, ağ-düğüm arayüzü):** İki anahtar arasındaki arayüzdür.
  - Özel NNI: Özel bir ATM ağı içindeki iki anahtar arası.
  - Genel NNI: Genel bir ağ içindeki iki anahtar arası.
- **B-ICI (Broadband Inter-Carrier Interface, geniş bant taşıyıcılar arası arayüz):** Farklı iki genel ATM ağındaki anahtarlar arası.

> **Ders sonrası not:** Sunumda genel NNI de "özel network içindeki iki anahtarın bağlanması" diye tanımlandı; bu bir dil sürçmesidir. Genel NNI, genel (public) bir ağ içindeki iki anahtarı bağlar.

### 6.5 Referans modeli

ATM referans modeli üç katmandan oluşur:

- **ATM uyum katmanı (AAL, ATM Adaptation Layer):** Kullanıcıdan gelen veriyi hücrelere böler; ters yönde gelen hücreleri birleştirir.
- **ATM katmanı:** Başlığı ekler ve denetler, VPI/VCI çevirisini yapar, genel akış kontrolünü sağlar.
- **Fiziksel katman:** Çerçeve üretimini ve iletim ortamına uyarlamayı yapar, hücre sınırlarını denetler ve fiziksel yapıyı kontrol eder.

### 6.6 Avantajlar, dezavantajlar ve kullanım alanları

Dezavantajlar:

- Yüksek maliyetli bir altyapı ister; bu yüzden kullanımı azdır.
- Sunuma göre bazı görüşlere göre standartları nispeten yeni olduğu için tam oturmamıştır ve gereken altyapı ve donanım tam belirlenememiştir.

Avantajlar:

- Var olan sistemlere kolayca uyarlanabilir; bu yüzden birçok sistemin omurgasında ATM'e rastlanır.
- Ortaya çıkış amacı olan yüksek hızlı iletimi, büyük veri boyutlarında da sağlar.
- Güvenilir bir iletim ortamı sunar ve bant genişliğini etkin kullanır.

Kullanım alanları: kampüs ağları, Frame Relay omurgaları, internet omurgaları ve yerleşim alanlarındaki geniş bant ağları. Özellikle trafik yoğunluğunun çok fazla olduğu yerlerde hızlı ve güvenilir veri akışı sağlaması ATM'e avantaj sağlar.

> **Ders sonrası not:** ATM 1990'ların teknolojisidir; "standartları nispeten yeni" ifadesi bugün için geçerli değildir. Omurgalarda büyük olasılıkla büyük ölçüde MPLS ve Ethernet ile yer değiştirmiştir.

## 7. Hocanın Sunum Tavsiyesi

İlk beş sunumdan sonra hoca genel bir değerlendirme yaptı. İşe girdiğinizde ve mülakatlara gittiğinizde sizden çeşitli durumlarda sunum yapmanız istenecek.

> **Hocanın vurgusu:** Slaytın içine bir paragraf yerleştirip çıkıp onu okumak kadar kendinize kötü bir şey yapamazsınız. Slayt görsel ağırlıklı olmalı ve size anlatacağınız şeyi hatırlatan birkaç kelime içermeli. Konuya zaten hâkim olmanız lazım.

Hoca, konuya hâkim olarak, slayt okumadan anlatılan ATM sunumunu bu açıdan iyi bir örnek olarak gösterdi.

## 8. Kablo Televizyon Sistemleri (CATV)

### 8.1 Tanım ve bölümler

Kablo televizyon sistemi, radyo yayını ya da uydu tarafından sağlanan programları koaksiyel ya da fiber optik kablo aracılığıyla evlere ulaştıran bir iletişim sistemidir. Yayın sinyallerini alabilen, sayısal ya da analog yayın yapan çok sayıda televizyon ve radyo kanalını yüksek kaliteli fiber ve koaksiyel kablo üzerinden ileten çok kanallı bir sistemdir. Görevi, farklı kaynaklardan gelen görüntü ve ses sinyallerini abonelerin alıcılarına dağıtmaktır.

Sistem üç bölümde incelenir: merkez (headend), ana şebeke (trunk) ve ev içi dağıtım şebekesi. Genel akış şöyledir: Uydudan gelen sinyali çanak anten alır. Sinyal illerde kurulan merkezlere gider ve orada bir dizi işlemden geçtikten sonra dağıtım şebekesine verilir. Dağıtım şebekesinden yükselteçler ve frekans çeviricilerle ev içi dağıtıma ulaşır.

### 8.2 Merkez (headend)

Merkez, illerde kurulan ve sinyali abonelerin evlerine dağıtmak için kullanılan yerdir. İşlem zinciri şöyledir:

- Boyutları doğru seçilmiş parabolik anten, uydudan aldığı sinyali anten besleme ünitesine odaklar.
- Sinyal düşük gürültülü yükseltece (LNA) gider; bu yükselteç radyo frekansındaki sinyali güçlendirir.
- Ardından sinyal frekansını düşürmek için alt çeviriciye (down converter) gönderilir. Bunun nedeni, yüksek frekanslı sinyalin uzun mesafelere taşınamamasıdır; frekans, koaksiyel kabloda taşınabilecek seviyeye indirilir.
- Son olarak uydu alıcısı sinyali televizyona uygun görüntü ve ses sinyallerine dönüştürür.

### 8.3 Ana şebeke (trunk)

Ana şebekede merkezde birleştirilen televizyon sinyalleri ana hat üzerinden uzak mesafelere taşınır. Burada kayıp ile kazancın eşit olmasına dikkat edilir. Kablodaki kayıp frekansa bağlıdır: yüksek frekanslar daha çok zayıflar. Bu kaybı telafi etmek için her ana hat yükseltecinin girişine ters frekans tepkili bir eşitleyici (equalizer) devresi konur. Böylece yükseltecin aktif katlarına bütün frekanslarda eşit seviyede sinyal gider. Kablodaki kayıp sıcaklığa da bağlıdır; sunuma göre her santigrat derecede yaklaşık %0,2 değişir.

Frekans planı:

- Gidiş yolu (merkezden aboneye): 47–450 MHz bandı.
- Dönüş yolu (aboneden merkeze): Modern sistemlerde 5–20 MHz bandı. Ters yönde bilgi göndermek için kullanılır. Bu durumda ana hat ve dağıtım hattındaki yükseltici kutularında bir filtreyle birbirinden ayrılmış iki yükseltici bulunur.

Dönüş yolundan örneğin ödemeli TV (pay TV) verileri iletilir. Ödemeli TV, Avrupa ve Amerika'da yaygın olan, abonelerin izledikleri kadar ödediği bir hizmettir. Dönüş yolundan gelen verilerle bir bilgisayar abonenin hangi kanalı ne kadar izlediğini saptar ve ücretlendirme buna göre yapılır.

Ana hat kablosunun uzunluğunu belirleyen değişkenler:

- Her yükseltecin en yüksek çıkış seviyesi
- Gürültü değeri (noise figure)
- Genlik ve frekans tepkisi
- Her yükseltecin kazancı
- Ana hat kablosunun birim uzunluktaki zayıflaması

### 8.4 Ev içi dağıtım

En basit hâliyle ev içi dağıtım bir kablo ve bir televizyon prizinden oluşur. Birkaç prizin beslenmesi gerekiyorsa ev içinde de yükselteç gerekebilir. Bina içi dağıtımda sunuma göre en uygun yöntem yıldız bağlantıdır: binanın girişine gelen kablo bir bölücüyle (splitter) sonlandırılır ve daire ve kat sayısına uygun bölücülerle her daireye ayrı kablo çekilir. Bu yöntem, bir dairedeki sinyal kesintisinin diğer daireleri etkilememesini sağlar; ama her daireye ayrı kablo ve yükselteç kullanmak maliyeti artırır. İyi görüntü ve ses için prizdeki sinyal seviyesi 60–80 dBµV arasında olmalıdır.

### 8.5 Koaksiyel ve fiber

Buraya kadar anlatılan, iletişimin her aşamasında analog sinyallerin ve koaksiyel altyapının kullanıldığı klasik sistemdir. Avrupa ve Amerika'da kablo TV'nin can damarının koaksiyel kablo olması, onun en uygun kablo olduğu anlamına gelmez. Fiber optik kablo ana hat maliyetini azaltır ve zayıflamayı çok düşürdüğü için kaliteyi artırır. Ama fiber koaksiyelden pahalı olduğu ve mevcut altyapıyı değiştirmek ek maliyet getirdiği için çoğu yerde mevcut koaksiyel altyapı yeterli görülür.

### 8.6 Blok diyagram ve bileşenler

Blok diyagramda televizyon kanallarının yayınları ve uydu gibi kaynaklardan alınan sinyaller modüle edilip birleştirilir. Taşıma sırasında kayıplar oluştuğu için yükselteçler (amplifier) ve eşitleyiciler kullanılır. Sinyal dağıtım merkezine, oradan da ana hatlarla tüketiciye aktarılır.

Bileşenler:

- **Koaksiyel kablo:** En içte veriyi taşıyan bakır iletken, onun çevresinde plastik yalıtkan, en dışta koruyucu kılıf bulunur. Bu katmanların malzemesi ve yapısı kablonun kalitesini ve özelliklerini belirler.
- **Ana hat yükselteci (trunk amplifier):** Koaksiyel kabloda zayıflayan sinyali güçlendirir.
- **Hat uzatıcı yükselteç (line extender amplifier):** Benzer işlev gören bir yükselteç türüdür. <!-- BELİRSİZ: 01:57:02'de hat uzatıcının "daha büyük ölçekler için" kullanıldığı söyleniyor; genelde dağıtım hattının sonlarında kullanılır, ifade bozuk olabilir. -->
- **Bölücü (splitter):** Bir sinyali birden fazla yere yönlendirir.
- **Musluk (tap):** Örneğin binaya gelen sinyalin her dairedeki kullanıcıya ayrı ayrı alınabilmesini sağlar.
- **Düşüm kablosu (drop cable):** Son kullanıcının evine giren kablodur.
- **HFC (Hybrid Fiber-Coax):** Hem fiber hem koaksiyel kablo içerir. Uzak mesafelerde fiber, binalara girdikten sonra koaksiyel kullanılır. İnternet ve kablo TV bağlantısı aynı anda sağlanabilir.

### 8.7 CATV'de kullanılan teknolojiler

- **Kablo telefon:** Telefon görüşmesini iletmek için kablo bağlantısını kullanır. İnternet kullanmaz, bu yüzden internet telefonundan farklıdır; ama kablo internete benzer biçimde veri göndermek ve almak için kablo ağını kullanır. Veri sıkıştırma sayesinde geleneksel telefona göre bant genişliğini daha verimli kullanır ve daha yüksek ses kalitesi sağlayabilir; buna karşılık sabit hatlarda olmayan güvenlik sorunları vardır. Telefon, internet ve TV aynı ağdan sunulduğu için bu hizmetleri ayrı ayrı almaktan daha ucuz olabilir.
- **Analog ve sayısal video:** Analog video, resmin parlaklık ve renk bilgilerini hızla değişen bir analog sinyalle temsil eder. Video, çerçeve (frame) denen bağımsız resimlerin art arda aktarılmasıdır; her çerçeve satır satır çizilir. Sayısal video ise piksel gruplarıyla temsil edilen resimlerden oluşur.
- **IPTV (Internet Protocol Television):** Kablo ya da uydu sinyali yerine TCP/IP paketleriyle televizyon programı ve video içeriği sunan hizmettir. Canlı yayın ya da isteğe bağlı video sunabilir. Bir kurumun özel ağında da kullanılabilir, ama karmaşıklık, ağ gecikmesi ve ölçekleme sorunları yüzünden bu tür uygulamalar abone tabanlı modellerden çok daha az yaygındır.
- **HDTV:** Büyük ekranlar yaygınlaştıkça standart çözünürlük (SD) yetersiz kalmaya başladı. Mükemmel görüntü için HD sinyal veren kaynaklar gerekir; kablo TV bu kaynaklardan biridir. HD yayın izlemek için harici ya da dahili alıcılar gerekir.
- **Kablosuz kablo (wireless cable):** Kablo TV sinyallerini kablosuz iletişimle uzak noktalara ulaştırır. MMDS (Multichannel Multipoint Distribution Service, çok kanallı çok noktalı dağıtım hizmeti) ve LMDS (Local Multipoint Distribution Service, yerel çok noktalı dağıtım hizmeti) olarak ikiye ayrılır.
- **Etkileşimli televizyon (interactive TV):** İzleyicinin program bilgilerini seçmesine, değiştirmesine ya da girmesine izin verir. Örneğin izleyici bir futbol maçını hangi açıdan izleyeceğini seçebilir ya da yayıncıya bilgi gönderebilir. Dönüş kanalı telefon, mobil SMS, radyo, telefon hatları ya da kablo TV olabilir. Kablo TV'de entegre dönüş yolu olan platformlar, dönüş yolu (return path) olarak aynı kabloyu kullanır.

### 8.8 Kablo TV servisleri

- **Televizyon programcılığı:** Medya içeriğinin planlanıp kaynaktan izleyiciye aktarılmasıdır; çeşitli ödeme planlarıyla hizmet alınır.
- **İzleme başına ödeme (pay-per-view):** Müşteri, izlemek istediği her bir içerik için ayrı ödeme yapar.
- **Reklam:** Ağ reklamcılığı, isteğe bağlı reklamcılık, geliştirilmiş reklamcılık ve etkileşimli reklamcılık gibi türleri vardır. En gelişmişi izleyiciye göre oluşturulan, daha etkileşimli reklamlardır.
- **Veri servisleri:** Başta internet erişimi olmak üzere veri aktarma olanakları ve veri hattı kiralama. Paketler hıza, ücrete ve kotaya göre değişir.
- **Telefon servisleri:** Kablo bağlantısı üzerinden telefon araması yapmayı sağlar. Bunun için standart telefon sinyallerini kablo sistemine aktaran bir kablo telefon adaptörü gerekir.
- **T-ticaret (T-commerce):** Ürün tanıtımı, sipariş alma ve ödeme işlemlerinin televizyon üzerinden yapılmasıdır. Bugün çok yaygın değildir.

## 9. X.25

Bu konuyu da gönüllü bir grup anlattı.

### 9.1 Tarihçe ve kullanım

X.25, ITU-T (eski adıyla CCITT) tarafından hazırlanmış bir protokol dizisidir. Geliştirilmesine 1970'lerde başlandı, ilk standardı 1976'da yayımlandı. Önemli özellikleri:

- Paket anahtarlamalı protokollerin ilklerindendir.
- Genel olarak geniş alan ağlarında (WAN) kullanılmıştır.
- WAN protokolleri için bir standarda bağlanan ilk protokollerdendir.
- Hata denetimine imkân verdiği için verinin güvenli ve başarılı iletimi konusunda önemli bir yere sahiptir.

ITU-T yaklaşık dört yıllık dönemlerle toplanıp X.25'in güncel sürümlerini yayımladı; amaç, protokolün güncel ağlarla uyumunu sağlamaktı. X.25, derste gördüğümüz OSI referans modelinden yaklaşık 8 yıl önce çıkmıştır; bu da ne kadar eski bir protokol olduğunu gösterir.

Daha çok havacılık, ödeme sektörü, askeri alan ve telekomünikasyonda kullanılmıştır. Eskiden bankamatiklerde (ATM) ve kredi kartı ödemelerinde sık kullanılıyordu; bugün havacılığın bazı kısımları dışında kullanımı pek kalmamıştır. Sunumda Fransa'nın X.25'i son kullanan ülkelerden biri olduğu, 2012'de kullanıma son verildiğinde yaklaşık 800 bin terminalin hâlâ X.25 ile çalıştığı söylendi.

> **Ders sonrası not:** Sunumda hem "2015'te son verildi" hem "2012'de son verildi" dendi; Fransa'daki X.25 ağı (Transpac) büyük olasılıkla 2012'de kapatıldı. OSI modeli büyük olasılıkla 1984'te standartlaştı; $1984 - 1976 = 8$ yıl, sunumdaki "yaklaşık 8 yıl" ile tutarlıdır.

### 9.2 Ağ yapısı ve cihazlar

- **DTE (Data Terminal Equipment):** Uç noktadaki cihazlardır: terminal, PC, yazıcı, yönlendirici.
- **DCE (Data Circuit-terminating Equipment):** DTE ile PSE arasındaki arayüz cihazlarıdır. Servis sağlayıcıdan hizmet almak için kullanılan modemler ve paket anahtarlama cihazlarıdır.
- **PSE (Packet Switching Exchange):** X.25 ağının iskeletini (omurgasını) oluşturan anahtarlardır. Verinin bir DTE'den diğerine ağ üzerinden aktarılmasından sorumludur.
- **PAD (Packet Assembler/Disassembler):** Çok kullanılmasa da DTE paket modunda çalışmıyorsa gerekir. Gelen veriyi tamponlar, paketlere böler ve DTE'nin cevaplarını birleştirerek iki tarafın anlayacağı biçime çevirir.

### 9.3 Katmanlar

X.25'in katmanları OSI modelinin ilk üç katmanına karşılık gelir:

| OSI katmanı | X.25 katmanı | Protokol |
|---|---|---|
| Fiziksel | Fiziksel katman | X.21 |
| Veri bağı | Veri bağı katmanı | LAPB |
| Ağ | Paket katmanı | PLP (Packet Layer Protocol) |

**Fiziksel katman (X.21):** DTE ile DCE arasındaki fiziksel bağlantıyı ve elektriksel sinyal akışını tanımlar. X.21 15 pinli bir konnektör kullanır ve RS-232 referans alınarak geliştirilmiştir. Sunuma göre X.21'de hız 2 Mbps'e kadar çıkabilir.

**Veri bağı katmanı (LAPB, Link Access Procedure Balanced):** HDLC'den türetilmiş, bit yönelimli (bit-oriented) bir protokoldür. Çerçevelerin sıralı, doğru ve hatasız iletilmesini sağlar. Çerçeve yapısı şöyledir:

- Bayrak (flag): Çerçevenin başına ve sonuna eklenir.
- Adres: Alıcının adresini içerir.
- Kontrol: Akış kontrolü ve hata kontrolüne ait bilgileri tutar.
- Veri: İletilen veriyi tutar.
- FCS (Frame Check Sequence): İletimde hata olup olmadığını anlamak için kullanılır.

**Paket katmanı (PLP):** Son kullanıcılar arasında mantıksal bağlantılar üzerinden veri aktarımını sağlar. Bağlantı kurma ve sonlandırmadan, yani DTE'ler arasında sanal devre kurmaktan sorumludur. PLP'nin beş modu vardır:

- Çağrı kurma (call setup): SVC kurmak için kullanılır.
- Veri aktarımı (data transfer): SVC ve PVC'lerde veri aktarımı için kullanılır.
- Boşta (idle): SVC kurulduktan sonra veri gönderilmeden önceki bekleme durumudur.
- Çağrı temizleme (call clearing): SVC'de DTE'ler arasındaki bağlantıyı sonlandırır.
- Yeniden başlatma (restarting): DTE ile DCE arasındaki eşzamanlamayı sağlar.

### 9.4 Sanal devreler

- **PVC (Permanent Virtual Circuit, kalıcı sanal devre):** Sık ve tutarlı veri aktarımları için kalıcı olarak kurulmuş bağlantılardır. Ağ yönetimi tarafından kalıcı olarak tahsis edilir. Çağrı kurmaya gerek kalmadan veri her zaman gönderilebilir. Bağlantının sorumluluğu servis sağlayıcıdadır.
- **SVC (Switched Virtual Circuit, anahtarlamalı sanal devre):** Düzensiz veri aktarımları için kullanılan geçici bağlantılardır. Ağdaki her DTE'ye eşsiz bir adres verilir. Telefonla aramaya çok benzer ve üç aşamadan oluşur: bağlantı kurma, veri aktarma, bağlantıyı sonlandırma. Bağlantıda sorun olursa devre sonlandırılıp yeniden kurulur.

### 9.5 Hata denetimi

Hata denetimi iki katmanda yapılır:

- Paket katmanı: Bilgi akışını yeniden eşzamanlamaktan sorumludur; kurtarılamayacak durumda çağrıları temizler.
- Veri bağı katmanı: Hata durumunda verinin yeniden gönderilmesinden sorumludur.

X.25 geliştirilirken çok yüksek hata oranları olacağı varsayıldığı için hata işleme (error handling) ve hata kurtarmaya (error recovery) odaklanılmıştır. Bu yüzden benzerlerine göre yavaştır. Özetle X.25 çok eski bir protokoldür, bugün havacılık ve askeri alan gibi geçmişten kalan kullanımlar dışında yaygın değildir ve sonraki paket anahtarlamalı protokoller için referans olmuştur.

> **Ek bilgi (derste anlatılmadı):** X.25 ile Frame Relay karşılaştırması bu dersteki iki sunumu birbirine bağlar. X.25 hatalı hatlar için tasarlandığından her düğümde hata denetimi ve yeniden gönderim yapar. Frame Relay ise daha temiz sayısal hatları varsayarak bu işleri uç sistemlere bırakır ve bu sayede daha hızlıdır.

## 10. WiMAX (IEEE 802.16)

### 10.1 Tanım

WiMAX, sabit ve mobil erişimi destekleyen, şehir alan ağları (MAN, Metropolitan Area Network) için kullanılan geniş bant kablosuz erişim teknolojisidir. Görüş hattı olan (LOS, line of sight) ya da olmayan (NLOS) ortamlarda noktadan noktaya, noktadan çok noktaya ve çok noktadan çok noktaya bağlantıları destekler. Sunuma göre uygun koşullarda en çok yaklaşık 75 Mbps hızla veri, ses ve görüntüyü hizmet kalitesi ve güvenlik gereklerini sağlayarak taşıyabilir. WiMAX, daha geniş bir alanda çalışan bir Wi-Fi gibi düşünülebilir; sunuma göre yaklaşık 50 km'ye kadar erişim sağlar. Uzaklaştıkça hız düşer ve 1 Mbps'e kadar inebilir.

### 10.2 Ağ modeli

WiMAX Forum'un ağ çalışma grubu, ekipmanlar arasında birlikte çalışabilirliği artırmak için bir ağ modeli tanımlamıştır:

- **MS (Mobile Station):** Son kullanıcıların ağa bağlanmasını sağlayan kısım.
- **ASN (Access Service Network):** Radyo erişim ağını oluşturan bir ya da daha fazla baz istasyonu ile ASN ağ geçitlerini içerir.
- **CSN (Connectivity Service Network):** IP bağlantılarını ve tüm temel IP işlevlerini yürütür.

### 10.3 Sürümler

- **802.16 (2001):** Şehir alan ağında geniş bant kablosuz veri sağlamak için çıktı. 10–66 GHz arasında çalışır ve görüş hattı gerektirir.
- **802.16a:** Frekans aralığı 2–11 GHz'e çekildi. En önemli farkı görüş hattı gerektirmemesidir. Bu, araya ne girerse girsin (bina, ağaç) sorun olmayacağı anlamına gelmez, ama önceki sürüme göre büyük bir ilerlemedir.
- **802.16d (802.16-2004):** 802.16a'nın yerini aldı. Bakır kablonun olmadığı ya da döşemenin ekonomik olmadığı köyler gibi yerlerde geniş bant hizmeti vermek ve DSL'e rakip olmak için geliştirildi. Taşınabilirlik yoktu.
- **802.16e (2005 sonu):** Tam hareketliliği (mobility) hedefleyen sürümdür; "Mobile WiMAX" ya da WiMAX 1.0 diye anılır. Sunuma göre hızı öncekilerden düşük olsa da hareketlilik desteği ve 6 GHz altındaki frekansları kapsaması sayesinde yaygın kullanıldı. 802.16e desteğiyle dizüstü bilgisayarlar piyasaya çıkmaya başladı ve WiMAX'in popülerliği arttı.
- **WiMAX 1.5:** Sunuma göre 802.16-2009 standardını kullanır, 125 Mbps'e kadar hız sağlayabilir ve frekans bölmeli çift yönlü iletim (FDD) kullanır.
- **WiMAX 2.0 (802.16m, Mart 2011):** IMT-Advanced gereksinimlerini karşılamak için çıktı. IMT-Advanced, ITU'nun 4G gereksinimlerini ortaya koyan girişimidir: sabit kullanıcıya 1 Gbps, hareketli kullanıcıya 100 Mbps.

<!-- BELİRSİZ: 02:27:18'de 802.16a için "2000 yılının başında" deniyor; 02:29:00'da 802.16e hızı için "15 değeriyle" gibi bozuk bir ifade geçiyor. -->

> **Ders sonrası not:** Sürüm tarihleri büyük olasılıkla şöyledir: 802.16a 2003'te, 802.16-2004 (d) 2004'te, 802.16e 2005 sonunda yayımlandı. Sunumdaki "802.16a 2000 başı" ifadesi doğru değildir. WiMAX 1.5 için verilen 125 Mbps değeri de altyazıdan doğrulanamaz.

### 10.4 Karşılaştırmalar

**Wi-Fi ile:**

| Özellik | Wi-Fi | WiMAX |
|---|---|---|
| Standart | IEEE 802.11 (a, b, ..., ax) | IEEE 802.16 (a, d, e, ...) |
| Ağ tipi | LAN (ev, ofis) | MAN (geniş alan) |
| QoS garantisi | Yok | Var |
| Frekans | 2,4 ve 5 GHz | 2–11 GHz |
| Lisans | Lisanssız bant | Lisanslı ve lisanssız bant |
| Kanal genişliği | Sunuma göre 20–25 MHz | 1,25–20 MHz |

Wi-Fi lisanssız bantta çalıştığı için 2,4 GHz'i kullanan Bluetooth kulaklık gibi cihazlarla çakışıp birbirinin iletişimini bozabilir. Sunuma göre WiMAX lisanslı ve lisanssız iki ayrı aralıkta çalışabildiği için bu sorun onda olmaz. Sunuma göre WiMAX, Wi-Fi'ye göre daha yüksek güvenlik, daha iyi hareketlilik ve daha düşük maliyet sunar.

**HiperMAN ile:** HiperMAN (High Performance Radio Metropolitan Area Network), ETSI'nin geliştirdiği, WiMAX'in Avrupa'daki alternatif standardıdır. 2–11 GHz aralığında kablosuz MAN bağlantısı hedefler. Katman yapısı ve hizmet planlaması bakımından WiMAX'e çok benzer; hem TDD (Time Division Duplex) hem FDD (Frequency Division Duplex) destekler, güçlü güvenlik ve hızlı uyarlama özellikleri sunar.

**UMTS ile:** Wi-Fi ve HiperMAN IP tabanlı teknolojilerdir; UMTS ise GSM ailesinden gelen 3G teknolojisidir. UMTS, WiMAX ve HiperMAN'in kullandığı frekans ve zaman bölmeli tekniklerden farklı olarak kod bölmeli çoklu erişim (CDMA) kullanır; kullanıcılar aynı geniş banttan haberleşir.

> **Ders sonrası not:** Sunumda UMTS kanal genişliği "5 milyar" diye geçiyor; bu bir telaffuz hatasıdır. UMTS (W-CDMA) kanalları 5 MHz genişliğindedir.

### 10.5 Türkiye'de kullanım

Grup, WiMAX'in Türkiye'deki kullanımına dair 2009–2010'dan sonrası için ayrıntılı bilgi bulamadığını söyledi. Örnek olarak İstanbul'da MOBESE güvenlik kameralarının görüntülerinin aktarımında kullanıldığı verildi. Genel kullanım mantığı, örneğin bir köye internet götürmektir: amaç yüksek hızdan çok, uzak mesafelere ve çok sayıda kullanıcıya hizmet vermektir.

> **Ek bilgi (derste anlatılmadı):** WiMAX, 4G yarışını büyük olasılıkla LTE'ye kaptırdı. Mobil operatörlerin çoğu mevcut GSM/UMTS altyapılarıyla uyumlu olan LTE'yi seçince WiMAX daha çok sabit kablosuz erişim ve kırsal bağlantı gibi niş alanlarda kaldı.

## 11. Final Sorularının Biçimi

Ders sonunda bir öğrenci, finalde bu konuların dönem boyunca görülen konularla karışık mı, yoksa ayrı mı sorulacağını sordu. Hoca, soruların bu konuların özelliklerine dair ayrı sorular olacağını söyledi ve örnek verdi: "ADSL'in özelliği nedir?", "ATM'de anlatılan şu kavram nedir?", "X.25 anlatılırken bahsedilen bu özellik X.25'in hangi katmanındadır?".

## Örnek Sorular

**Soru 1** (derste sözlü, 00:39:58): Şu an kullanılan SIM kartların yerini alan yeni bir teknoloji çıkıyor. Bu teknoloji nedir?

> **Çözüm (derste verilmedi):** Grup bu soruya cevap vermedi. Hocanın kastettiği büyük olasılıkla eSIM'dir (embedded SIM). eSIM'de abone bilgileri, takılıp çıkarılan bir kart yerine cihaza gömülü bir yongada tutulur ve operatör profili uzaktan yüklenir. Kart değiştirmeden operatör değiştirmek mümkündür.

**Soru 2** (derste sözlü, 01:05:08): ADSL çıkınca ISDN'in kullanımı azaldı. Japonya'da ISDN'in uzun süre popüler kalmasının sebebi nedir?

**Cevap (derste verildi):** ADSL'in ABD dışındaki ülkelere yayılması 1990'ların sonunu ve 2000'lerin başını buldu. Japonya'da ISDN için bir altyapı önceden kurulmuştu; bu yüzden ADSL geldikten sonra da ISDN kullanılmaya devam etti.

**Soru 3** (derste sözlü, 02:36:52, hocanın final için verdiği örnek soru tipi): ADSL'in özelliği nedir?

**Cevap (derste anlatılanlardan):** ADSL mevcut bakır telefon hattı üzerinde, telefon görüşmesiyle aynı anda sayısal veri iletir; ses ile veriyi bir ayırıcı (splitter) ayırır. Asimetriktir: indirme yönüne yükleme yönünden çok daha fazla alt kanal ayrılır, bu yüzden indirme hızı daha yüksektir. DMT modülasyonu kullanır. Hızı santrale uzaklığa bağlıdır.

**Soru 4** (derste sözlü, 02:37:07, hocanın final için verdiği örnek soru tipi): X.25'te anlatılan bir özellik X.25'in hangi katmanındadır? Örneğin sanal devrelerin kurulup sonlandırılması, çerçevelerin hatasız iletimi ve DTE–DCE arası elektriksel bağlantı hangi katmanlarda yapılır?

> **Çözüm (derste verilmedi, derste anlatılanlardan derlendi):** Sanal devrelerin (SVC/PVC) kurulması, sonlandırılması ve çağrı temizleme paket katmanında (PLP) yapılır. Çerçevelerin sıralı ve hatasız iletimi, bayrak/adres/kontrol/FCS içeren çerçeve yapısı ve hata durumunda yeniden gönderim veri bağı katmanındadır (LAPB). DTE ile DCE arasındaki elektriksel sinyal akışı fiziksel katmandadır (X.21). Hata denetimi hem veri bağı hem paket katmanında yapılır.

## Dersin Toparlaması

Bu son derste dönemin sekiz proje konusu öğrenci grupları tarafından anlatıldı. Sunumların ortak noktası, derste görülen katmanlı mimari, çoğullama, anahtarlama ve hata denetimi kavramlarının gerçek sistemlerde nasıl kullanıldığını göstermeleriydi. GSM'de FDMA ile TDMA'nın birlikte kullanıldığı hücresel yapı, ADSL'de bakır hattın frekans bölmeli kullanımı ve DMT, ISDN'de 64 kbps'lik B kanalları ile sinyalleşme taşıyan D kanalı görüldü. Paket anahtarlamalı WAN teknolojileri tarihî sırayla birbirine bağlandı: hatalı hatlar için her düğümde hata denetimi yapan X.25, hata düzeltmeyi uç sistemlere bırakan Frame Relay ve 53 baytlık sabit hücrelerle donanımda hızlı anahtarlama yapan ATM. CATV sunumunda koaksiyel ve HFC dağıtım şebekesi, WiMAX sunumunda ise kablosuz MAN erişimi ve 4G hedefleri anlatıldı.

Hoca, sunumlardaki konuların hepsinden, konuların özelliklerine ve katman yapılarına dair sorular sorulabileceğini hatırlattı. Bu not, sunumlarda geçen ve altyazıdan doğrulanamayan sayısal değerleri ve düzeltilmesi gereken ifadeleri "Ders sonrası not" bloklarıyla işaretler; finale hazırlanırken bu düzeltmeler dikkate alınmalıdır.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
