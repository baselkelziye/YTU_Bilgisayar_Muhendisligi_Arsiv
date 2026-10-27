# Veri İletişimi ve Bilgisayar Ağları Ders Kayıtları & Çalışma Özetleri

> **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.

### 📋 Genel Bilgiler
* **Ders:** Veri İletişimi ve Bilgisayar Ağları (BLM3051)
* **Hoca:** Dr. Ziya Cihan Tayşi (vize öncesi), Dr. Furkan Çakmak (vize sonrası)
* **Dönem:** Güz
* **Akademik Yıl:** 2021-2022
* **Şube:** BLM3051 - 3

Bu dizin, ilgili ders kayıtlarının altyazı özetlerini, çalışma notlarını ve PDF kaynaklarını içermektedir.

## 📚 Ders Müfredatı ve Belge Dizini

Aşağıdaki tabloda her bir dersin konusu, kaynak markdown dosyası ve doğrudan indirilebilir PDF formatındaki derlenmiş halleri listelenmiştir. Ders numaraları, kayıt arşivindeki ders kaydı sıra numaralarıdır (hafta numarası değildir).

| Ders No | Ders İçeriği / Konu Başlıkları | Kaynak Notlar (Markdown) | Çalışma Dosyası (PDF) |
| :---: | :--- | :---: | :---: |
| **Ders 1** | Veri İletişimine Giriş, Ağların Sınıflandırılması ve Topolojiler | [Özet](altyazi_ozetleri/ders_1_ozet.md) | [PDF (İndir)](ders_1_ozet.pdf) |
| **Ders 4** | OSI Referans Modeli, İşaretler, Kanal Kapasitesi ve Polar Kodlama | [Özet](altyazi_ozetleri/ders_4_ozet.md) | [PDF (İndir)](ders_4_ozet.pdf) |
| **Ders 7** | Bipolar Kodlama, PCM, Sayısal-Örneksel Modülasyon ve QAM | [Özet](altyazi_ozetleri/ders_7_ozet.md) | [PDF (İndir)](ders_7_ozet.pdf) |
| **Ders 10** | Seri ve Paralel İletim, Eş Zamanlılık ve Yönlendirilmiş İletim Ortamları | [Özet](altyazi_ozetleri/ders_10_ozet.md) | [PDF (İndir)](ders_10_ozet.pdf) |
| **Ders 11** | Kablosuz İletim Ortamı, Çoğullama ve Hata Algılama ile Düzeltme | [Özet](altyazi_ozetleri/ders_11_ozet.md) | [PDF (İndir)](ders_11_ozet.pdf) |
| **Ders 12** | Bağlantı Yönetimi, Akış Denetimi ve ARQ Yöntemleri | [Özet](altyazi_ozetleri/ders_12_ozet.md) | [PDF (İndir)](ders_12_ozet.pdf) |
| **Ders 14** | Senkron ve Asenkron Veri Bağlantı Protokolleri ve HDLC | [Özet](altyazi_ozetleri/ders_14_ozet.md) | [PDF (İndir)](ders_14_ozet.pdf) |
| **Ders 15** | IEEE 802 LAN Teknolojileri: Ethernet, Token Bus, Token Ring ve FDDI | [Özet](altyazi_ozetleri/ders_15_ozet.md) | [PDF (İndir)](ders_15_ozet.pdf) |
| **Ders 16** | IEEE 802.11 Kablosuz Yerel Ağlar, Bluetooth ve LAN Teknolojilerinin Karşılaştırması | [Özet](altyazi_ozetleri/ders_16_ozet.md) | [PDF (İndir)](ders_16_ozet.pdf) |
| **Ders 17** | Devre Anahtarlama, Paket Anahtarlama ve Sanal Devreler | [Özet](altyazi_ozetleri/ders_17_ozet.md) | [PDF (İndir)](ders_17_ozet.pdf) |
| **Ders 18** | Ağ Cihazları, VLAN, TCP/IP, Alt Ağ Hesabı ve Ağ Güvenliği | [Özet](altyazi_ozetleri/ders_18_ozet.md) | [PDF (İndir)](ders_18_ozet.pdf) |
| **Ders 19** | Öğrenci Proje Sunumları: GSM, ADSL, ISDN, Frame Relay, ATM, CATV, X.25 ve WiMAX | [Özet](altyazi_ozetleri/ders_19_ozet.md) | [PDF (İndir)](ders_19_ozet.pdf) |

> [!NOTE]
> 2, 3, 5, 6, 8, 9 ve 13 numaralı kayıtlar arşivde yoktur; 22 Kasım 2021 haftası vize haftasıdır.

## 🎯 Derslerin Detaylı Özetleri ve Kazanımları

### 🔹 Ders 1: Veri İletişimine Giriş, Ağların Sınıflandırılması ve Topolojiler
* **Genel Konular:**
  - Dersin tarihi 11 Ekim 2021 Pazartesi. Ders online yapıldı, saat 17:00'de başladı.
    - Hoca kendini Ziya Cihan Tayşi olarak tanıtıyor. İletişim için Yıldız e-posta adresini veriyor.
  - Dersin işleyişi
    - Dersin üç grubu var. Bu kayıt 3. grup (online grup).
  - Veri iletişiminin temel kavramları
    - İletişim ve haberleşme farkı.
  - Bilgisayar ağlarının faydaları ve değerlendirme ölçütleri
    - Başarım (performance), servis kalitesi (quality of service, QoS), güvenilirlik, güvenlik, ölçeklenebilirlik, uyumluluk.
  - Ağ mimarisi yaklaşımları
    - Katmanlı yaklaşım (layered approach): OSI ve TCP/IP.
  - Standartlar ve standart kurumları
    - De jure ve de facto standartlar.
  - Ağların sınıflandırılması
    - İletim tekniğine göre: noktadan noktaya (point-to-point) ve yayın (broadcast).
* **Hocanın Vurgusu:**
  - **İletişim ve haberleşme farkı:** İletişim alt seviyede verinin bir yerden bir yere aktarılmasıdır.
    - Haberleşme daha üst seviyede anlamlı bilginin aktarılması ve alınmasıdır. Ders notlarında bile bu iki kavram zaman zaman karışıyor.
  - **Veri iletişiminin dört temel parçası:**
    - İletim ortamı (medium).
  - **İletişimin üç beklentisi:** Doğru adrese teslim (delivery), doğruluk (accuracy) ve zamanında teslim (timeliness).
    - Gerçek zamanlı ses ve görüntüde geciken verinin anlamı yoktur, atılır (discard).
  - **Jitter:** Arka arkaya gönderilen paketlerin gecikmelerindeki değişkenlik.
    - Hat kalitesinin bir ölçüsüdür.
  - **Katmanlı yapının kuralı:** Her katman kendi içinde kalır.
    - Altındaki katmandan servis alır, üstündeki katmana servis verir.

### 🔹 Ders 4: OSI Referans Modeli, İşaretler, Kanal Kapasitesi ve Polar Kodlama
* **Genel Konular:**
  - Dersin tarihi 18 Ekim 2021 Pazartesi. Ders online yapıldı.
    - Asıl anlatım yaklaşık 00:06'da başlıyor.
  - Referans modelleri
    - OSI (Open Systems Interconnection) ve TCP/IP.
  - OSI'nin 7 katmanı ve görevleri
    - Fiziksel, veri bağı, ağ, taşıma, oturum, sunu, uygulama.
  - TCP/IP modeli ve diğer ağ modelleri
    - SNA, DNA, IPX/SPX, AppleTalk.
  - İşaretler (signals)
    - Örneksel (analog) ve sayısal (digital) işaretler.
  - İletimi bozan etkenler
    - Zayıflama (attenuation), gecikme, gürültü (noise), çapraz girişim (crosstalk), bozulma (distortion).
  - Kanal kapasitesi
    - Nyquist ve Shannon-Hartley teoremleri.
* **Hocanın Vurgusu:**
  - **OSI bir protokol değil, bir başvuru (referans) modelidir:**
    - ISO tarafından hazırlanmış de jure bir standarttır.
  - **İki modelin ters yönde oluşması:**
    - OSI önce tasarlanıp sonra uygulanmak üzere hazırlandı. Süreç politikayla ve uzun tartışmalarla yavaşladı.
  - **Ezber cümlesi:** Ağla çalışan herkesin 7 katmanı ezbere bilmesi gerekir.
    - Aşağıdan yukarı: *Please Do Not Touch Steve's Pet Alligator*.
  - **Uçtan uca haberleşen bilgisayar değil, süreçtir (process):**
    - Ağ katmanındaki adres (ör. IP adresi) sadece cihazı adresler.
  - **Katman ilişkisi:** $n$. katman $(n-1)$. katmandan servis alır, $(n+1)$. katmana servis verir.

### 🔹 Ders 7: Bipolar Kodlama, PCM, Sayısal-Örneksel Modülasyon ve QAM
* **Genel Konular:**
  - Dersin tarihi 25 Ekim 2021 Pazartesi. Ders online yapıldı.
    - Asıl anlatım yaklaşık 00:04:39'da başlıyor.
  - Önceki dersin tekrarı: Manchester ve diferansiyel Manchester.
  - Bipolar kodlama: AMI, B8ZS, HDB3.
  - Örneksel-sayısal kodlama
    - PAM (Pulse Amplitude Modulation).
  - Sayısal-örneksel kodlama
    - Taşıyıcı işaret.
  - Örneksel-örneksel kodlama: AM, FM, PM.
* **Hocanın Vurgusu:**
  - **Bipolar kodlamanın amacı DC bileşenden kurtulmaktır:** 1'ler sırayla pozitif ve negatif kodlanır.
    - Uzun vadede ortalama gerilim sıfır olur.
  - **AMI'nin kalan sorunu uzun 0 dizileridir:** İşarette değişim olmaz ve alıcı senkronu kaybeder.
    - B8ZS ve HDB3 bu dizileri bilerek "bozarak" çözer.
  - **Bilgisayar haberleşmesinde bir uç hep sayısaldır:** Bu yüzden sayısal-sayısal, örneksel-sayısal ve sayısal-örneksel kodlamalar önemlidir.
    - Örneksel-örneksel kısım hızlı geçildi.
  - **Örneksel işaretin temel özelliği sürekliliktir:** Hoca "analog" cevabını eksik buldu.
    - Gerçek zamanlı işletim sistemini "gerçek zamanlı işletim sistemi" diye tanımlamaya benzetti. Aradığı cevap süreklilikti (kesintisiz işaret).
  - **Örnekleme kuralları:** Örnekler eşit aralıklarla alınmalıdır.
    - Örnekleme hızı da işaretin karakterini yakalayacak kadar yüksek olmalıdır.

### 🔹 Ders 10: Seri ve Paralel İletim, Eş Zamanlılık ve Yönlendirilmiş İletim Ortamları
* **Genel Konular:**
  - Dersin tarihi 1 Kasım 2021 Pazartesi. Ders online yapıldı.
    - Asıl anlatım yaklaşık 00:10:24'te başlıyor. Öncesi katılım beklemesi.
  - Bu hafta grup diğer gruplardan önde olduğu için hoca hızlı gitmeyeceğini, yönlendirilmiş ortamlarla (guided media) duracağını söyledi.
  - Sayısal veri iletim teknikleri
    - Paralel iletim, paralel port (DB25, Centronics).
  - İletim ortamı (transmission medium)
    - Altyapı yatırımı olarak kablolama ve yedeklilik.
* **Hocanın Vurgusu:**
  - **Fiziksel katmanda henüz çerçeve (frame) veya paket yok:** Bir öğrenci verinin hatlara paket olarak mı bölündüğünü sordu.
    - Hoca burada sadece bitlerin ortam üzerinden nasıl aktarıldığından söz edildiğini söyledi. Çerçeveleme veri bağı katmanının işidir.
  - **Paralel iletim:**
    - Avantajı hızdır.
  - **Pin tablolarına takılmayın:** Konnektörlerin bacak bağlantıları genel kültür.
    - Önemli olan teori ve çalışma mantığı.
  - **Eş zamansız iletimin temel sorunu saatlerin bağımsız olmasıdır:**
    - Hoca bunu "yarın 17.34'te buluşalım" örneğiyle anlattı. Herkesin saati ayrı bir kaynağa bağlı olduğundan biri 17.30'da, biri 17.40'ta gelir.
  - **Eş zamanlı ve eş zamansız iletimin karşılaştırması:**
    - Eş zamanlı iletim: daha etkin kullanım, daha iyi hata denetimi, daha yüksek hız.

### 🔹 Ders 11: Kablosuz İletim Ortamı, Çoğullama ve Hata Algılama ile Düzeltme
* **Genel Konular:**
  - Ders 8 Kasım 2021 Pazartesi günü online yapıldı. Hoca dönemin 6. haftası olduğunu söylüyor. Kayıt yaklaşık 1 saat 29 dakika.
  - Yönlendirilmemiş (kablosuz) iletim ortamının (unguided media) devamı:
    - radyo dalgaları (radio waves),
  - Çoğullama (multiplexing) ve çoğullamayı çözme (demultiplexing):
    - frekans bölmeli çoğullama (FDM, Frequency Division Multiplexing) ve OFDM,
  - Hata nedenleri ve hata türleri: tek bit hatası, çok bitli hata, hata patlaması (burst error).
  - Hata algılama (error detection) yöntemleri:
    - VRC (Vertical Redundancy Check, eşlik biti),
  - Hata düzeltme (error correction): gereken artıklık biti sayısı ve Hamming kodu.
  - Vize sınavının biçimi ve hoca değişikliği duyurusu.
* **Hocanın Vurgusu:**
  - Kablosuz ortamın temel kazancı hareketlilik (mobility) ve kablolama maliyetinin olmamasıdır.
    - Kırsal ve uç bölgelere servis vermek için çok tercih edilir.
  - Düşük frekanslı radyo dalgaları engellerin içinden geçebilir ve uzağa gider.
    - Bunun bedeli izolasyonun olmamasıdır. Komşuların Wi-Fi ağlarını görmeniz bundandır.
  - Frekans arttıkça kapsama alanı daralır, sinyal yönlü hale gelir ve engelden geçmek yerine sekmeye başlar.
    - 5 GHz'e geçmek bu yüzden komşu ağlarla çakışmayı azaltır.
  - Aynı kanalda yayın yapan çok sayıda erişim noktası birbiriyle çakışır.
    - Hoca bölümün B blokundaki ilk Wi-Fi kurulumunu örnek veriyor: kanallar ayarlanana kadar hiçbir şey düzgün çalışmamış.
  - Bluetooth da 2,4 GHz'te çalışır.
    - İlk sürümler frekans atlamayı (frequency hopping) düzgün yapamadığı için Wi-Fi ile çakışıyordu. Sonraki sürümler dolu kanalı atlayan uyarlamalı atlama kullanır.
* **Detaylı Açıklamalar:** Kablosuz iletim atmosferi kullanır. Günlük kullanımda daha çok yere yakın yayılan yer dalgaları (ground wave) önemlidir. Yüksek frekanslarda iyonosferdeki değişimler iletimi etkileyebilir.

### 🔹 Ders 12: Bağlantı Yönetimi, Akış Denetimi ve ARQ Yöntemleri
* **Genel Konular:**
  - Ders 15 Kasım 2021 Pazartesi günü online yapıldı. Hoca dönemin 7. haftası olduğunu söylüyor. Kayıt yaklaşık 1 saat 33 dakika.
  - Veri bağlantı katmanının (data link layer) görevleri: çerçeveleme (framing), akış denetimi (flow control), hata denetimi (error control), adresleme, bağlantı yönetimi.
  - Bağlantı yönetimi (line discipline):
    - noktadan noktaya hatlar için ENQ/ACK,
  - Akış denetimi:
    - dur ve bekle (stop-and-wait),
  - Hat kullanım oranı (link utilization) hesabı ve $a$ parametresi.
  - Hata denetimi ve otomatik yeniden gönderim isteği (ARQ, Automatic Repeat reQuest):
    - dur ve bekle ARQ,
  - Sırtlama (piggybacking).
* **Hocanın Vurgusu:**
  - Akış denetiminin amacı, alıcının alabileceğinden fazla veriye maruz kalmasını engellemektir.
  - Alıcının boğulmasının nedenleri:
    - İki uç farklı hızlarda çalışabilir.
  - Tampon (buffer) dolarsa çerçeveler düşürülür.
    - Her yeniden gönderim hat kapasitesini boşa harcar.
  - Tek atlamalık (single hop) mesafede akış denetimini veri bağlantı katmanı yapar.
    - Araya başka ağlar girdiğinde bu iş taşıma katmanına düşer. O zaman sorun alıcının kapasitesi değil, aradaki ağların yoğunluğudur.
  - Bir mesaja cevap gelmediğinde iki ihtimal vardır: mesaj hiç gitmemiştir ya da cevap yolda kaybolmuştur.
    - Gönderici bu ikisini ayırt edemez. Hoca bunu "lütfen unutmayın" diye vurguluyor.
* **Detaylı Açıklamalar:** Hat yapısı ikiye ayrılır:

### 🔹 Ders 14: Senkron ve Asenkron Veri Bağlantı Protokolleri ve HDLC
* **Genel Konular:**
  - Ders 29 Kasım 2021 Pazartesi günü online yapıldı. Kayıt yaklaşık 2 saat.
  - Bu dersten itibaren dersi Dr. Furkan Çakmak anlatıyor. Vize haftasına kadar grubu Dr. Ziya Cihan Tayşi yürütmüştü.
  - Kısa tekrar: OSI modeli, fiziksel katman ve veri bağlantı katmanı. Bu ve sonraki haftalarda hâlâ veri bağlantı katmanında kalınacak.
  - Veri bağlantı denetim protokolleri (data link control protocols):
    - asenkron protokoller,
  - Bayt yönelimli protokoller:
    - ASCII denetim karakterleri (SYN, STX, ETX, ETB, ITB, SOH, DLE, ENQ, ACK0/ACK1, NAK, EOT, NULL vb.),
  - Bit yönelimli protokoller ve HDLC (High-Level Data Link Control):
    - istasyon tipleri, yapılandırmalar ve üç çalışma modu (NRM, ARM, ABM),
  - Vize sonuçlarına dair kısa değerlendirme.
* **Hocanın Vurgusu:**
  - Senkron protokoller bugün de kullanılıyor.
    - Hoca, şu an derste ses ve görüntünün de büyük olasılıkla senkron ve bit yönelimli bir protokolle geldiğini söylüyor.
  - Asenkron iletimde her bayta başlangıç ve bitiş bitleri eklenir.
    - Bu ek yük yüksektir ve çerçeveler arasında boşluklar oluşur. Bu yüzden asenkron iletim senkron iletime göre yavaştır.
  - Senkron iletimde başlangıç ve bitiş birer bit ile değil, özel bayraklarla (flag) belirtilir.
    - 1000–1500 baytlık bir çerçeve için yalnız birkaç denetim baytı eklenir. Ek yük çok daha düşüktür.
  - Cihazların saatleri zamanla kayar.
    - Fiziksel katmanda ortak saat işareti (common clock signal), mantıksal seviyede de bayraklar senkronizasyonu sağlar.
  - **Veri saydamlığı** önemli bir kavramdır ve farklı derslerde karşınıza çıkacaktır.
    - Gri tonlu bir resim gibi ikili verinin içinde bir bayt tesadüfen bir denetim karakteriyle (ör. ETX) aynı olabilir. Bu durum DLE kaçış karakteriyle çözülür.
* **Detaylı Açıklamalar:** Asenkron hatta veri belli periyotlarla gelmez. Gönderici istediği zaman gönderir ve alıcı baytın başını ve sonunu başlangıç/bitiş bitlerinden anlar. Hatta farklı uzunlukta boşluklar oluşur ve hat kullanım oranı düşer.

### 🔹 Ders 15: IEEE 802 LAN Teknolojileri: Ethernet, Token Bus, Token Ring ve FDDI
* **Genel Konular:**
  - Ders 6 Aralık 2021 Pazartesi günü online yapıldı. Dersi Dr. Furkan Çakmak anlattı. Kayıt yaklaşık 1 saat 32 dakika.
  - Yerel ağ (LAN) teknolojileri ve IEEE 802 projesi:
    - veri bağlantı katmanının LLC (Logical Link Control) ve MAC (Media Access Control) alt katmanlarına ayrılması,
  - Ortam erişim yöntemleri:
    - ALOHA ve slotlu ALOHA (slotted ALOHA),
  - IEEE 802.3 Ethernet: çerçeve yapısı, Fast Ethernet, Gigabit Ethernet ve sonrası, Metro Ethernet, PoE (Power over Ethernet).
  - IEEE 802.4 Token Bus.
  - IEEE 802.5 Token Ring: jeton (token), öncelik ve rezervasyon, halkadaki bit sayısı, izleme istasyonu (monitor station).
  - FDDI (Fiber Distributed Data Interface): senkron ve asenkron çerçeveler, 4B/5B kodlama, DAS/SAS istasyonları.
* **Hocanın Vurgusu:**
  - Noktadan noktaya iletişimde adres gerekmez.
    - Çok noktalı iletişimde alıcının adresi söylenmelidir. Hoca vizede bununla ilgili bir soru sorduklarını hatırlatıyor.
  - LAN protokolleri çok noktalı modda çalışır.
    - Farklı ağ kartlarının ve protokollerin uyumlu konuşabilmesi için IEEE 802 projesi geliştirilmiştir.
  - Paylaşılan ortamda en ciddi sorun çarpışmadır (collision).
    - İki istasyonun verisi havada veya kabloda çakışınca hiçbir taraf için anlam taşımaz.
  - Token kavramı çok önemlidir.
    - Token da bir çerçevedir. Token'ı alan istasyon tek başına veri gönderdiği için çarpışma olmaz.
  - Token Ring'deki öncelik ve rezervasyon mekanizmasını iyi öğrenin.
    - Hoca bunun mülakatlarda ve iş hayatında "buna benzer bir şey yap" diye karşınıza çıkacağını söylüyor.
* **Detaylı Açıklamalar:** IEEE 802 projesi veri bağlantı katmanını iki alt katmana ayırır:

### 🔹 Ders 16: IEEE 802.11 Kablosuz Yerel Ağlar, Bluetooth ve LAN Teknolojilerinin Karşılaştırması
* **Genel Konular:**
  - Ders 13 Aralık 2021 Pazartesi akşamı online yapıldı. Slaytlarda "BLM3051 Data Communication, Week 11" yazıyor. Dersi Dr. Furkan Çakmak anlatıyor.
  - Önceki hafta IEEE 802.3, 802.4 ve 802.5 anlatılmıştı. Bu hafta kablosuz LAN (Wireless LAN, WLAN) standardı IEEE 802.11 (Wi-Fi) işleniyor.
  - Konular:
    - Kablosuz iletişimin özellikleri: radyo frekansı (RF) ve kızılötesi (infrared), hareketlilik (mobility), dolaşım (roaming), menzil, gürültü.
  - Bağlantılı ve bağlantısız hizmetler ile anahtarlama (switching) gelecek haftaya kaldı.
* **Hocanın Vurgusu:**
  - 802.11, Ethernet'teki çarpışma algılama (Collision Detection, CD) yerine çarpışmadan kaçınma (Collision Avoidance, CA) kullanır.
    - Kablosuz antenler yarı çift yönlüdür (half duplex). Gönderirken aynı anda dinleyemez, bu yüzden çarpışmayı algılamak zordur.
  - DCF'nin temel adımları:
    - İstasyon hattı dinler. Hat boşsa DIFS kadar bekler ve gönderir.
  - Hoca slayttaki üç istasyonlu DCF şemasını adım adım anlattı.
    - Ayrıntısı "Detaylı Açıklamalar"da.
  - RTS/CTS akışı ve NAV mantığı sınav için önemli.
    - Gizli düğüm ile açıkta kalan düğüm arasındaki fark özellikle soruldu.
  - 2,4 GHz bandında birbirini etkilemeyen kanallar 1, 6 ve 11'dir.
    - Komşu kanallar büyük ölçüde örtüşür.

### 🔹 Ders 17: Devre Anahtarlama, Paket Anahtarlama ve Sanal Devreler
* **Genel Konular:**
  - Ders 20 Aralık 2021 Pazartesi akşamı online yapıldı. Slaytlarda "Week 12" yazıyor. Dersi Dr. Furkan Çakmak anlatıyor.
  - Kayıt, oturumu açan hocanın toplantı yönetimini (host) Furkan Çakmak'a devretmesiyle başlıyor. Ders yaklaşık bir saat sonra başlıyor. Sabah grubu da bu derse katılabiliyor.
  - Proje ödevi önceki hafta verildi. Bu yüzden konu sırası değişti: TCP/IP ve ağ cihazları bir hafta öne alındı.
  - Ders, veri bağı katmanından ağ katmanına geçişin girişi niteliğinde.
  - Konular:
    - Bilgisayar ağlarının sınıflandırması: yayınlı (broadcast) ve anahtarlamalı (switched) ağlar.
* **Hocanın Vurgusu:**
  - Devre anahtarlamada üç aşama vardır: bağlantı kurma, veri iletimi, bağlantıyı sonlandırma.
    - Hoca bunu sabit hatlı telefonla anlattı:
  - Devre kurulduktan sonra hat boş bile olsa ücret ödenir.
    - Paket anahtarlamada ücret gönderilen veri miktarına göredir.
  - Ses trafiği düzenli bir akıştır.
    - Veri trafiği patlamalıdır (bursty). Paket anahtarlama patlamalı veri için tasarlanmıştır.
  - Devre anahtarlamada hat koparsa onarılana kadar iletişim kesilir.
    - Datagramda paketler başka yoldan gidebilir.
  - **Datagram ile sanal devre farkı sınavlarda her yıl soruluyor:**
    - Datagramda her pakette alıcı ve gönderici adresi bulunur.

### 🔹 Ders 18: Ağ Cihazları, VLAN, TCP/IP, Alt Ağ Hesabı ve Ağ Güvenliği
* **Genel Konular:**
  - Ders 27 Aralık 2021 Pazartesi akşamı online yapıldı. Dersi Dr. Furkan Çakmak anlatıyor. Hoca "13. haftadayız" diyor; bu, hocanın ders anlattığı son hafta.
  - Dersin başında proje ve sunumlarla ilgili sorular yanıtlandı.
  - Konular:
    - OSI katmanlarına göre ağ cihazları: repeater ve hub, bridge ve switch, router, gateway.
  - TCP/IP ve güvenlik konuları "genel kültür" düzeyinde anlatıldı. Ayrıntısı Ağ Teknolojileri ve Bilişim Sistemleri Güvenliği derslerinde görülecek.
* **Hocanın Vurgusu:**
  - Katmanlara göre cihazlar sınav için önemli:
    - **Repeater:** Fiziksel katmanda çalışır, zayıflayan sinyali güçlendirir.
  - Cihazlar yukarı katmanlara çıktıkça daha çok bellek ve işlem gücüne ihtiyaç duyar.
  - **Hub ile switch farkı:** Hub gelen sinyali tüm portlara yayar (broadcast).
    - Switch yalnızca hedef porta iletir, ağda gereksiz trafik oluşmaz.
  - Repeater ve hub pasif bir konnektör değildir.
    - Güç gerektiren aktif cihazlardır.
  - **VLAN'ın avantajları:**
    - Daha yüksek başarım: broadcast yalnızca VLAN üyelerine gider.

### 🔹 Ders 19: Öğrenci Proje Sunumları: GSM, ADSL, ISDN, Frame Relay, ATM, CATV, X.25 ve WiMAX
* **Genel Konular:**
  - Ders 3 Ocak 2022 Pazartesi akşamı online yapıldı. Dönemin son dersidir. Dersi Dr. Furkan Çakmak yönetiyor; kayıt, oturum yönetiminin ona devredilmesiyle başlıyor.
  - Ders tamamen öğrenci proje sunumlarına ayrıldı. Her konu birden çok gruba verilmişti. Anlatacak grup kurayla seçildi.
  - Sunulan 8 konu (sunum sırasıyla):
    - GSM (Global System for Mobile Communications).
  - Ders sonunda final sınavına dair sorular yanıtlandı.
* **Hocanın Vurgusu:**
  - Sunum ve rapor birlikte ikinci vize yerine geçiyor ve %30 ağırlıkta.
  - Sunumda hazır bulunmayan grup üyeleri sıfır alıyor.
    - Kurada adı geçen ama hiç üyesi bulunmayan gruplar hem sunumdan hem rapordan sıfır aldı.
  - **Sunum süresi:**
    - Sunum en çok 15 dakika olmalı. İlk grup süreyi aştı.
  - Kurada çıkmayan gruplar, önceden yükledikleri videolardan notlandırılacak.
  - **Sunumlar finale dahil:** Anlatılan 8 konudan finalde soru gelecek.
    - Eksik anlatılan kısımları hoca tamamlıyor. Bir sunum çok eksik olursa başka bir grup yeniden anlatabilir. Bu ders kaydı izlenerek çalışılabilir.

**Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
