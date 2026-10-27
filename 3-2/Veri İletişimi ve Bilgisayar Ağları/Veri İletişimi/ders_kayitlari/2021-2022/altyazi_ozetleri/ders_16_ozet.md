# Ders 16 Çalışma Özeti

## Genel Konular

- Ders 13 Aralık 2021 Pazartesi akşamı online yapıldı. Slaytlarda "BLM3051 Data Communication, Week 11" yazıyor. Dersi Dr. Furkan Çakmak anlatıyor.
- Önceki hafta IEEE 802.3, 802.4 ve 802.5 anlatılmıştı. Bu hafta kablosuz LAN (Wireless LAN, WLAN) standardı IEEE 802.11 (Wi-Fi) işleniyor.
- Konular:
  - Kablosuz iletişimin özellikleri: radyo frekansı (RF) ve kızılötesi (infrared), hareketlilik (mobility), dolaşım (roaming), menzil, gürültü.
  - 802.11 ortam erişim denetimi (Media Access Control, MAC): CSMA/CA, DCF (Distributed Coordination Function) ve PCF (Point Coordination Function).
  - Çerçeveler arası boşluklar (DIFS, SIFS, EIFS), geri çekilme (backoff) ve çekişme penceresi (Contention Window, CW).
  - RTS/CTS ve ağ ayırma vektörü (Network Allocation Vector, NAV).
  - Gizli düğüm (hidden node) ve açıkta kalan düğüm (exposed node) sorunları.
  - Temel ve genişletilmiş hizmet alanları (BSS, ESS).
  - 2,4 GHz kanal yapısı ve örtüşmeyen kanallar (1, 6, 11). FHSS ve DSSS.
  - 802.11 sürümleri, Bluetooth (piconet, scatternet), ZigBee, HomeRF, HiperLAN.
  - Kablosuz teknolojilerin hız ve menzil karşılaştırması (2G, 3G, 4.5G, 5G, Wi-Fi, Bluetooth).
  - Kablosuz ağ tehditleri ve güvenlik: dinleme, izinsiz erişim, girişim (interference), karıştırma (jamming), WEP, WPA, WPA2.
  - 802.3, 802.4, 802.5, FDDI ve WLAN'ın avantaj ve dezavantaj karşılaştırması.
- Bağlantılı ve bağlantısız hizmetler ile anahtarlama (switching) gelecek haftaya kaldı.

## Hocanın Özellikle Vurguladığı Kısımlar

- 802.11, Ethernet'teki çarpışma algılama (Collision Detection, CD) yerine çarpışmadan kaçınma (Collision Avoidance, CA) kullanır.
  - Kablosuz antenler yarı çift yönlüdür (half duplex). Gönderirken aynı anda dinleyemez, bu yüzden çarpışmayı algılamak zordur.
- DCF'nin temel adımları:
  - İstasyon hattı dinler. Hat boşsa DIFS kadar bekler ve gönderir.
  - Hat meşgulse gönderimi erteler. Hat boşalınca DIFS bekler, sonra rastgele bir geri çekilme sayacıyla geri sayar.
  - Sayacı ilk sıfıra inen çekişmeyi (contention) kazanır ve gönderir.
  - Diğerleri sayaçlarını dondurur. Bir sonraki turda kaldıkları yerden devam ederler.
  - Alıcı, çerçeveyi aldıktan sonra SIFS kadar bekleyip ACK gönderir. SIFS, DIFS'ten kısadır. Böylece ACK önceliklidir.
  - Çarpışma olursa ilgili istasyonlar "cezalandırılır": CW iki katına çıkar, daha uzun beklerler.
- Hoca slayttaki üç istasyonlu DCF şemasını adım adım anlattı. Ayrıntısı "Detaylı Açıklamalar"da.
- RTS/CTS akışı ve NAV mantığı sınav için önemli. Gizli düğüm ile açıkta kalan düğüm arasındaki fark özellikle soruldu.
- 2,4 GHz bandında birbirini etkilemeyen kanallar 1, 6 ve 11'dir. Komşu kanallar büyük ölçüde örtüşür.
- Kullanılabilecek frekanslar fiziksel değil yasal bir sınırdır. Lisanssız bantlar devletlerce halka açılmıştır. Diğer bantlar askerî kullanıma ayrılmış ya da satılmıştır.
- Frekans arttıkça hız artar ama menzil kısalır. 5 GHz Wi-Fi hızlıdır ama 2,4 GHz'ten daha kısa mesafeye ulaşır.
- Wi-Fi menzili açık alanda yaklaşık 100 m, kapalı alanda genellikle 15–30 m.
- Şifrelemede WPA2 ve AES (Advanced Encryption Standard) seçilmeli.
- Karşılaştırma tablosu sınavda sorulabilir:
  - **Ethernet:** basit ve yaygın. Gerçek zamanlı iş için uygun değil, öncelik yok, en küçük çerçeve 64 bayt.
  - **Token Bus ve Token Ring:** kararlı, öncelik mekanizması var. Düşük yükte gecikmesi yüksek.
  - **FDDI:** çift halka, uzun mesafe, zamana duyarlı veri için iyi.
  - **WLAN:** hareketlilik sağlar. Menzili kısa, hızı kablolu ağlardan düşük.

## Kısa Tekrar Notları

- **CSMA/CA:** taşıyıcı dinlemeli çoklu erişim, çarpışmadan kaçınma ile.
- **DIFS (DCF Interframe Space):** gönderim öncesi standart bekleme süresi.
- **SIFS (Short Interframe Space):** ACK ve CTS gibi yanıtlardan önceki kısa bekleme. SIFS < DIFS.
- **EIFS (Extended Interframe Space):** hatalı veya çarpışmış bir çerçeve algılandıktan sonraki daha uzun bekleme.
- **Geri çekilme (backoff):** $[0, CW]$ aralığından rastgele seçilen sayıda zaman dilimi (slot) beklenir. Her çarpışmada CW yaklaşık iki katına çıkar: $31 \to 63 \to 127 \dots$
- **RTS (Request to Send):** "Sana şu kadar süre veri göndereceğim" isteği.
- **CTS (Clear to Send):** alıcının izni. Bu süre bilgisini duyan herkes NAV'ına yazar ve o süre boyunca göndermez.
- **Gizli düğüm:** A ile C birbirini duymaz, ikisi de B'ye gönderir. Çarpışma B'de olur.
- **Açıkta kalan düğüm:** C, B'nin CTS'ini duyduğu için susar. Oysa C'nin D'ye göndermesi A–B iletişimini bozmazdı. Boşuna beklenir.
- **BSS (Basic Service Set):** tek bir erişim noktasına bağlı istasyonlar.
- **ESS (Extended Service Set):** birden çok BSS'nin birleştirilmesiyle oluşan geniş ağ.
- **FHSS (Frequency Hopping Spread Spectrum):** gönderim kanaldan kanala atlayarak yapılır.
- **DSSS (Direct Sequence Spread Spectrum):** sinyal geniş bir banda yayılarak gönderilir.
- **Bluetooth:**
  - IEEE 802.15.1 standardıdır. Ericsson 1994'te geliştirdi. Bluetooth SIG yönetir.
  - 2,4 GHz bandında frekans atlamalı çalışır.
  - **Piconet:** en çok 8 aktif cihaz (1 ana + 7 bağımlı) ve 255'e kadar beklemedeki (park) cihaz.
  - **Scatternet:** birden çok piconet'in birleşimi.
- **ZigBee:** düşük güçlü, düşük veri hızlı IoT ve sensör ağları için.
- **WPA2:** AES tabanlı şifreleme. Kurumsal kimlik doğrulama için EAP (Extensible Authentication Protocol) kullanır.

## Detaylı Açıklamalar

### Kablosuz iletişimin temelleri

- Wi-Fi, lisanssız RF bantlarında (2,4 GHz ve 5 GHz) yayın yapar. Evdeki modem bir SSID yayınlar, ona bağlanan cihazlar bir LAN oluşturur. İnternet olmasa da bu cihazlar birbirleriyle veri paylaşabilir.
- Kızılötesi bağlantıda verici ve alıcı birbirini doğrudan görmelidir (eski TV kumandası örneği). RF'de görüş hattı gerekmez, sinyal duvarı geçebilir. Ama malzemeye ve dalga boyuna göre zayıflar.
- **Hareketlilik ve dolaşım:**
  - Kampüs Wi-Fi'ında öğrenci bir binadan yemekhaneye yürürken aynı ağda kalır. Cihaz her yerde en yakın erişim noktasına bağlanır. Buna dolaşım (roaming) denir.
  - Yurt dışında telefonda "R" görünmesi de aynı fikir: başka bir operatörün ağı üzerinden hizmet alınır.
- **Sinyal zayıflaması:** Serbest uzayda alınan güç mesafenin karesiyle ters orantılıdır. Mesafe iki katına çıkınca güç dörtte birine düşer.
- **Gürültü:** Kablolu ağlarda termal gürültü vardı. Kablosuzda asıl gürültü kaynağı aynı ya da komşu kanalda yayın yapan diğer ağlardır. Fuar gibi kalabalık ortamlarda yeniden gönderimler artar ve hız düşer.

### DCF ve çekişme

- Slayttaki şemada üç istasyon var. İlk turda CW = 31, yani geri çekilme sayısı 0–31 arasından seçiliyor.
  1. Station 3'e ilk çerçeve geliyor. Hat boş olduğu için DIFS bekleyip hemen gönderiyor (BO = 0).
  2. Bu sırada Station 1 ve 2'ye de gönderilecek çerçeve geliyor. Hat meşgul olduğu için bekliyorlar.
  3. Hat boşalınca herkes DIFS bekliyor. Sonra seçilen değerlerden geri sayılıyor: Station 1 için 10, Station 2 için 19, Station 3'ün yeni çerçevesi için 25.
  4. Station 1 sıfıra ilk ulaşıp gönderiyor. Station 2'nin sayacı 9'da, Station 3'ün sayacı 15'te donuyor.
  5. Sonraki turda Station 1 yeni çerçevesi için 9 seçiyor. Station 2 de 9'dan devam ediyor. İkisi aynı anda sıfıra ulaşıyor ve çarpışma oluyor.
  6. Çarpışan istasyonların CW değeri 63'e çıkıyor ve yeni sayılar seçiyorlar: Station 1 için 52, Station 2 için 43.
  7. Station 3 kaldığı yerden (6) sayarak sıfıra ulaşıyor ve gönderiyor. Diğer ikisi 46 ve 37'de donuyor.
- **CW ve öncelik:**
  - CW, rastgele bekleme süresinin üst sınırıdır.
  - Hocanın anlatımında öncelikli istasyonlar daha küçük bir aralıktan seçim yapar. Bu fikir 802.11e'deki trafik sınıflarına karşılık gelir.
  - Çarpışan istasyonun penceresi büyür, ortalama bekleme süresi uzar.
- Hoca DCF'nin yanında PCF'yi de andı. PCF'de erişim noktası istasyonları sırayla yoklar (polling).

### RTS/CTS ve gizli/açıkta kalan düğüm

- A, B'ye RTS gönderir. RTS'te ne kadar süre gönderileceği de yazar.
- B uygunsa CTS ile yanıt verir. CTS'teki süre bilgisini kapsama alanındaki herkes duyar ve NAV'ına yazar. Bu süre bitene kadar hattı dinlemeden susarlar.
- **Gizli düğüm örneği:**
  - Diziliş A – B – C. A yalnızca B'yi duyar, C de yalnızca B'yi duyar.
  - A'nın B'ye gönderdiğini C bilemez. C de B'ye göndermeye kalkarsa çarpışma B'de olur.
  - CTS'in B tarafından yayınlanması bu sorunu azaltır. C, A'yı duymasa da B'nin CTS'ini duyar.
- **Açıkta kalan düğüm örneği:**
  - Diziliş A – B – C – D. A, B'ye; C de D'ye göndermek istiyor.
  - C, B'nin CTS'ini duyduğu için susar. Oysa C'nin D'ye göndermesi B'de çarpışma yaratmazdı. Kapasite boşa harcanır.

### Kanal kullanımı

- 2,4 GHz bandında kanal merkezleri 5 MHz arayla dizilir. Kanal 1 2,412 GHz'tedir, kanal 13 2,472 GHz'tedir.
- Her kanal yaklaşık 22 MHz genişliğindedir. Bu yüzden komşu kanallar örtüşür. Örtüşmeyen üçlü 1, 6 ve 11'dir.
- **FHSS:** Bir kanalda sorun olursa sonraki gönderim başka bir kanaldan yapılır. Kanallar örtüştüğü için örtüşmeyen kanalları kullanmak daha verimlidir.
- **DSSS:** Sinyal tek bir geniş banda yayılarak gönderilir. Alıcı dar bantlı gürültüye karşı daha dayanıklıdır.
- 802.11n hem 2,4 hem 5 GHz'te çalışır. 5 GHz'te örtüşmeyen kanal sayısı çok daha fazladır.

### Diğer kablosuz teknolojiler ve menzil

- **Hücresel nesiller:**
  - 2G çok uzak mesafeye ulaşır ama yalnızca ses ve SMS taşıyabilir.
  - 3G, 4G ve 5G'de hız artar, hücre küçülür, baz istasyonu sayısı artar.
  - Hoca, 6G'de cihazların da baz istasyonu gibi davranabileceğini öngörüyor. Bu bir tahmin, standartlaşmış bilgi değil.
- **Bluetooth:**
  - Menzili Wi-Fi'dan da kısadır.
  - Saat, kulaklık, araç ve akıllı ev cihazlarıyla yaygınlaştı.
  - 4.0 ile gelen Bluetooth Low Energy (BLE), enerji tüketimini çok azalttı.
- **ZigBee örneği:** Bir serada sıcaklık ve nem ölçen yüzlerce ucuz sensör, saatte bir küçük veri gönderir. Yüksek hız gerekmez.
- **HomeRF ve HiperLAN:** Standartlaştırıldılar ama Wi-Fi'ın gelişmesiyle kullanımdan düştüler.
- **WMAN:** Kampüs ortasındaki dev bir antenden kilometrelerce yayın fikri prototip düzeyinde kaldı.

### Kablosuz güvenlik

- Kablolu hattı dinlemek için kabloya fiziksel müdahale gerekir. Kablosuzda yayın zaten herkese açıktır. Bu yüzden şifreleme şarttır.
- **Kimlik bilgisi çalma örneği (evil twin):**
  - Saldırgan, komşunun ağıyla aynı SSID'de sahte bir erişim noktası açar.
  - Kurban cihaz sahte ağa bağlanmaya çalışır. Kullanıcı açılan pencereye şifresini girer.
  - Saldırgan bu şifreyle gerçek ağa girer.
  - Bu yüzden kimlik doğrulamanın güçlü kurulması gerekir (WPA2/WPA3, EAP).
- **Girişim (interference):** Aynı kanalda çok güçlü bir verici, diğer ağların iletişimini bastırır.
- **Karıştırma (jamming):** Bilinçli olarak gönderilen bir sinyal iletişimi keser.
- **Fiziksel tehditler:** Erişim noktasının yerinden oynatılması gibi.
- **WEP ve WPA:** WEP'in şifrelemesi zayıftır ve kırılmıştır. WPA2'de AES kullanılır.

### LAN teknolojilerinin karşılaştırması

- **Ethernet (802.3):**
  - Manchester kodlama kullanır, en düşük anlamlı bit (LSB) önce gönderilir.
  - Düşük yükte gecikme neredeyse sıfırdır.
  - Yük arttıkça çarpışma olasılığı artar ve hat verimi düşer.
  - Öncelik mekanizması yoktur.
- **Token Bus (802.4):**
  - Yüksek yükte kararlı çalışır ve öncelik mekanizması vardır.
  - Düşük yükte jeton bekleme gecikmesi oluşur.
  - Protokolü karmaşıktır ve fiber altyapıya uygun değildir.
- **Token Ring (802.5):**
  - 8 seviyeli öncelik ve rezervasyon vardır.
  - Differential Manchester kodlama kullanır, en yüksek anlamlı bit (MSB) önce gönderilir.
  - Kısa ve uzun çerçevelerle çalışabilir.
  - Öksüz çerçeve (orphan frame) ve kayıp jeton için bir izleyici istasyon (monitor) gerekir. Bu ek yük getirir.
- **FDDI:**
  - Çift halka yapısı sayesinde bir halka koparsa diğeri kullanılır.
  - DAS (çift bağlantılı) ve SAS (tek bağlantılı) istasyonlar vardır.
  - Fiber sayesinde uzun mesafelere ulaşır.
- **WLAN:**
  - En büyük avantajı hareketliliktir.
  - Menzili sınırlıdır; 802.11n'de dış ortamda yaklaşık 250 m'dir.
  - Hızı kablolu ağlardan düşüktür.

### Ders sonrası notlar

- **CW aralığı:**
  - Hoca "W = 4 ise $2^4 = 16$, 0 ile 16 arasında" dedi. Doğrusu: CW = $2^W - 1$, seçim $[0, CW]$ aralığından yapılır. W = 4 için aralık 0–15'tir.
  - Slayttaki CW = 31 ve 63 değerleri bununla uyumlu.
  - 802.11 DSSS'te CWmin = 31 ve CWmax = 1023'tür.
- **DCF şeması:** Çarpışmadan sonra Station 1 ve 2 sırasıyla 46 ve 37'den devam ediyor ($52-6$ ve $43-6$). Hoca "37 ve 45" dedi.
- **Sinyal zayıflaması:** Hoca "1 metre uzaklaşınca 4 kat, 2 metre uzaklaşınca 16 kat zayıflar" dedi. Ters kare yasası mesafenin oranıyla çalışır, metre başına değil. Mesafe 2 katına çıkınca güç 1/4'e, 4 katına çıkınca 1/16'ya düşer.
- **Bluetooth:**
  - Klasik Bluetooth 2,4 GHz'te 1 MHz'lik 79 kanal kullanır, BLE 40 kanal kullanır. Hoca "90 küsur kanal" dedi.
  - İlk sürümün hızı 1 Mbps civarındadır (pratikte yaklaşık 721 kbps), 24 Mbps değil. 24 Mbps, Bluetooth 3.0 + HS'te 802.11 bağlantısı üzerinden ulaşılan hızdır.
  - Ders tarihinde en güncel sürüm 5.3'tü (2021). 6.0 sürümü 2024'te yayımlandı.
- **ZigBee:** Hoca "Bluetooth'un bir versiyonu" dedi. ZigBee, Bluetooth'tan bağımsızdır ve IEEE 802.15.4 üzerine kuruludur. Bu düşük güçlü, düşük hızlı bir kişisel alan ağı standardıdır.
- **WPA seçenekleri:** Modemlerde sunulan seçim "DES mi AES mi" değil, "TKIP mi AES (CCMP) mi"dir. TKIP, WEP'in yerine geçici çözüm olarak geldi. Artık güvensiz kabul edilir ve 802.11-2012'de kullanımdan kaldırıldı. Bugün WPA3 de mevcuttur.
- **Kanal sayısı:** 2,4 GHz'te Avrupa ve Türkiye'de 13 kanal kullanılabilir. 14. kanal yalnızca Japonya'da, 802.11b için vardır.
- **WMAN:** Hocanın "hayata geçmedi" dediği uzak mesafeli kablosuz şehir ağı fikri, IEEE 802.16 (WiMAX) olarak standartlaştı ve bir dönem bazı ülkelerde kullanıldı. Ayrıntısı ders 19'daki öğrenci sunumunda var.

**Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
