# Ders 19 Çalışma Özeti

## Genel Konular

- Ders 3 Ocak 2022 Pazartesi akşamı online yapıldı. Dönemin son dersidir. Dersi Dr. Furkan Çakmak yönetiyor; kayıt, oturum yönetiminin ona devredilmesiyle başlıyor.
- Ders tamamen öğrenci proje sunumlarına ayrıldı. Her konu birden çok gruba verilmişti. Anlatacak grup kurayla seçildi.
- Sunulan 8 konu (sunum sırasıyla):
  - GSM (Global System for Mobile Communications).
  - ADSL (Asymmetric Digital Subscriber Line).
  - ISDN (Integrated Services Digital Network).
  - Frame Relay.
  - ATM (Asynchronous Transfer Mode).
  - Kablo televizyon (CATV, Community Antenna Television).
  - X.25.
  - WiMAX (IEEE 802.16).
- Ders sonunda final sınavına dair sorular yanıtlandı.

## Hocanın Özellikle Vurguladığı Kısımlar

- Sunum ve rapor birlikte ikinci vize yerine geçiyor ve %30 ağırlıkta.
- Sunumda hazır bulunmayan grup üyeleri sıfır alıyor. Kurada adı geçen ama hiç üyesi bulunmayan gruplar hem sunumdan hem rapordan sıfır aldı.
- **Sunum süresi:**
  - Sunum en çok 15 dakika olmalı. İlk grup süreyi aştı.
  - Sonraki gruplar için 15 dakikayı aşan her dakika puan kesileceği söylendi.
- Kurada çıkmayan gruplar, önceden yükledikleri videolardan notlandırılacak.
- **Sunumlar finale dahil:** Anlatılan 8 konudan finalde soru gelecek. Eksik anlatılan kısımları hoca tamamlıyor. Bir sunum çok eksik olursa başka bir grup yeniden anlatabilir. Bu ders kaydı izlenerek çalışılabilir.
- **Final soruları:** Konuların özelliklerinden olacak. Hocanın örnekleri:
  - "ADSL'in özelliği nedir?"
  - "ATM'deki şu kavram nedir?"
  - "Bu özellik X.25'in hangi katmanındadır?"
- Final, vize gibi çoktan seçmeli olacak.
- **Sunum tavsiyesi:**
  - İş hayatında ve mülakatlarda sunum yapılacak.
  - Slaytlar görsel ağırlıklı olmalı, anlatılacak şeyi hatırlatan birkaç kelime içermeli.
  - Konuya hakim olunmalı, slayt okunmamalı.

## Kısa Tekrar Notları

- **GSM:** 2G sayısal hücresel standart (ETSI). FDMA ve TDMA birlikte kullanılır: 200 kHz'lik taşıyıcılar, her birinde 8 zaman dilimi. Ses devre anahtarlamalıdır. Veri için önce GPRS, sonra EDGE eklendi.
- **GSM bileşenleri:**
  - MS (Mobile Station): cihaz (ME, IMEI ile tanımlanır) ve SIM kart (IMSI içerir).
  - BSS (Base Station Subsystem): BTS ve BSC.
  - NSS (Network Switching Subsystem): MSC, HLR, VLR, AuC, EIR, GMSC.
  - OSS (Operation Support Subsystem).
- **GSM arayüzleri:** Um (MS–BTS), Abis (BTS–BSC), A (BSC–MSC).
- **ADSL:**
  - Mevcut bakır telefon hattında telefonla aynı anda veri iletir.
  - Asimetriktir: indirme hızı yükleme hızından yüksektir.
  - DMT (Discrete Multi-Tone) modülasyonu kullanır.
- **ISDN:**
  - Uçtan uca sayısal iletim sağlar.
  - B kanalları 64 kbps ve kullanıcı verisi taşır. D kanalı sinyalleşme taşır.
  - BRI = 2B + D (D: 16 kbps).
  - PRI = 23B + D (ABD, T1) ya da 30B + D (Avrupa ve Türkiye, E1). PRI'da D kanalı 64 kbps'tir.
- **Frame Relay:**
  - Paket (çerçeve) anahtarlamalı bir WAN teknolojisidir. Sanal devre kullanır, bağlantılar DLCI (Data Link Connection Identifier) ile tanımlanır.
  - Hata düzeltme yapmaz. Bozuk çerçeveyi atar, düzeltmeyi uç sistemler yapar.
  - Tıkanıklık bildirimi FECN ve BECN bitleriyle yapılır.
- **ATM:**
  - Veriyi 53 baytlık sabit hücrelere (cell) böler: 5 bayt başlık, 48 bayt yük.
  - Bağlantı yönelimlidir, VPI/VCI kullanır.
  - Katmanları: fiziksel katman, ATM katmanı, AAL (ATM Adaptation Layer).
- **CATV:**
  - Bölümleri: merkez (headend), ana hat (trunk), dağıtım şebekesi, ev içi dağıtım.
  - Kablo yapısı koaksiyel ya da karma fiber-koaksiyel (HFC) olabilir.
- **X.25:**
  - İlk paket anahtarlamalı WAN standartlarından biridir (CCITT, 1976).
  - Üç katmanı vardır: X.21 (fiziksel), LAPB (veri bağı), PLP (paket katmanı).
  - Cihazları: DTE, DCE ve PSE.
- **WiMAX:**
  - IEEE 802.16 tabanlı kablosuz şehir ağı (Metropolitan Area Network, MAN) teknolojisidir.
  - Sabit ve mobil erişimi destekler. Menzil onlarca kilometreye kadar çıkabilir.
  - Avrupa'daki karşılığı HiperMAN'dir (ETSI).

## Detaylı Açıklamalar

### GSM

- **Tarihçe:**
  - Eski analog sistemler (AMPS, TACS) az sayıda kullanıcıyı destekliyordu.
  - CEPT, 1982–83'te yeni bir standart için çalışma grubu kurdu.
  - Hedefler uluslararası dolaşım, yüksek ses kalitesi, el cihazı desteği ve düşük maliyetti.
  - Sorumluluk 1989'da ETSI'ye geçti. İlk ticari GSM ağı 1991'de Finlandiya'da açıldı.
  - DCS 1800 (1800 MHz) 1993'te İngiltere'de başladı. Aynı yıl Telstra (Avustralya), Avrupa dışındaki ilk GSM operatörü oldu.
  - Sonraki gelişmeler: 2000 civarında GPRS, ardından EDGE ve MMS.
- **Mobil istasyon:**
  - Cihazın değişmez kimliği IMEI'dir. Çalıntı cihazlar bu numarayla engellenir.
  - SIM kartta abone kimliği (IMSI) ve gizli anahtar bulunur.
- **BSS (Base Station Subsystem):**
  - BTS, radyo vericisi ve alıcısıdır.
  - BSC, BTS'lerin radyo kaynaklarını yönetir; frekans ve zaman dilimlerini atar.
- **NSS (Network Switching Subsystem):**
  - MSC, çağrı kurma, yönlendirme ve devir (handover) işlerini yapar.
  - HLR, abonelerin kalıcı kayıtlarını ve son konumlarını tutar.
  - VLR, bölgedeki ziyaretçi abonelerin geçici kopyasını tutar. Böylece HLR'nin yükü azalır.
  - AuC, kimlik doğrulama anahtarlarını tutar.
  - EIR, IMEI'ye göre beyaz, gri ve kara listeler tutar.
  - GMSC, diğer ağlara açılan geçittir.
- **Arayüzler:**
  - B: MSC–VLR.
  - C: HLR–MSC/GMSC.
  - D: VLR–HLR.
  - E: MSC–MSC.
  - F: MSC–EIR.
  - G: VLR–VLR.
  - H: kısa mesaj iletiminde kullanılır.
- **Hiyerarşik alanlar:**
  - Hücre (cell): bir BTS'nin kapsadığı alan. Global Cell Identity ile tanımlanır.
  - Konum alanı (Location Area): hücre grubu, LAI ile tanımlanır.
  - MSC/VLR hizmet alanı.
  - PLMN alanı: bir operatörün ağı.
- **Protokol yapısı:** Üç katmanlıdır.
  - Fiziksel katmanda FDMA ve TDMA kullanılır.
  - Veri bağı katmanında LAPDm kullanılır. LAPDm, LAPD'nin hava arayüzüne uyarlanmış ve CRC içermeyen sürümüdür.
  - 3. katman üç alt katmana ayrılır: RR (radyo kaynak yönetimi), MM (hareketlilik yönetimi), CM (bağlantı yönetimi: çağrı, SMS).
- **Numaralar:** IMEI, IMSI, MSISDN (telefon numarası), MSRN (dolaşım numarası), TMSI (VLR'nin verdiği geçici kimlik), LMSI.
- **Güvenlik:**
  - Kimlik doğrulama meydan okuma-yanıt (challenge-response) yöntemiyle yapılır.
  - A5/1 ve A5/2 şifreleri kırılmıştır. GPRS şifreleri GEA-1 ve GEA-2 de zayıftır.
- **Kısıtları:**
  - Darbeli iletim, işitme cihazları gibi elektronik cihazlarda parazit yapabilir.
  - Kullanıcı arttıkça gecikme artar. Veri hızı sınırlıdır.
  - Kapsama için tekrarlayıcı (repeater) gerekir.
- **GSM ile CDMA karşılaştırması:** CDMA'da kullanıcılar aynı bandı farklı kodlarla paylaşır. GSM'de SIM kart esastır.

### ADSL

- Bellcore 1988'de, telefon sesinin üstündeki frekanslarda bakır çift üzerinden sayısal veri taşıma fikrinin patentini aldı.
- **Standartlar:** ANSI T1.413 (1995). ITU-T G.992.1 (G.dmt) ve G.992.2 (G.lite), 1999.
- **Çalışma mantığı:**
  - Bakır hattın yaklaşık 1,1 MHz'lik bandı yaklaşık 4,3 kHz genişliğinde 256 alt kanala bölünür.
  - En alt bant (0–4 kHz) telefon (POTS) içindir.
  - Bir ayırıcı (splitter/filtre) ses ile veriyi ayırır.
  - Yükleme için az sayıda, indirme için çok sayıda alt kanal kullanılır. Bu yüzden ADSL asimetriktir.
- Hız, santrale uzaklığa, kablo kalitesine ve parazitlere bağlıdır. Genellikle birkaç kilometreye kadar kurulur.
- **Avantajları:**
  - Ek hat gerekmez, telefon ve internet aynı anda kullanılır.
  - Ses bandı modemlerinden çok daha hızlıdır.
  - Ucuzdur ve fiber olmayan yerlerde hâlâ kullanılır.
- Türkiye'de ADSL hizmeti veren sağlayıcılar anıldı: Türk Telekom, Superonline, TurkNet ve diğerleri.

### ISDN

- Ses, veri ve görüntüyü aynı sayısal ağ üzerinden taşır. Bilgi kullanıcıya kadar sayısal gelir. Bu yüzden gürültüden daha az etkilenir.
- **Kanallar:** B kanalları 64 kbps'dir ve kullanıcı verisini taşır. D kanalı hat açma-kapama ve sinyalleşme işlerini yapar.
- **Arayüzler:**
  - BRI (Basic Rate Interface): ev ve küçük işletmeler içindir, 2B + D.
  - PRI (Primary Rate Interface): büyük işletmeler içindir.
- **Cihazlar:** Terminal adaptörleri (TA), ağ sonlandırıcılar (NT1, NT2), hat ve santral sonlandırıcılar (LT, ET).
- Katmanlar: fiziksel katman, D kanalı üzerinde LAPD (veri bağı) ve 3. katman sinyalleşmesi (Q.931).
- ADSL yaygınlaşınca ISDN çoğu ülkede geriledi. Japonya'da altyapı olduğu için uzun süre kullanıldı.

### Frame Relay

- Bu sunumu gönüllü bir grup yaptı. Bir bölümü İngilizce anlatıldı.
- Genellikle LAN'ları WAN üzerinden birbirine bağlamak için kullanılır.
- **Yapısı:**
  - Uç cihazlar (DTE) erişim bağlantılarıyla (access link) Frame Relay ağına bağlanır.
  - LMI (Local Management Interface), bağlantıların durumunu yönetir.
- **Çerçeve yapısı:** Bayrak (flag), adres alanı (DLCI ile FECN/BECN bitleri), veri ve FCS (Frame Check Sequence).
- **Avantajları:**
  - Kiralık hatlara göre ucuzdur.
  - Gecikmesi düşüktür.
  - Değişken boyutlu çerçeveleri (4096 bayta kadar) işleyebilir.
- **Dezavantajları:**
  - Değişken gecikme yüzünden ses iletimine uygun değildir.
  - Şifreleme yoktur. Bugün yerini çoğunlukla VPN ve MPLS aldı.
- Sunumun son kısmında sanal devrelerin (virtual circuit) bağlantı yönelimli olduğu ve kaynak ayırdığı anlatıldı.

### ATM

- ISDN'in geniş bant sürümü (B-ISDN) için geliştirilen aktarım tekniğidir.
- **Hücre yapısı:** Veri 53 baytlık sabit hücrelere bölünür. Sabit boyut, donanımda hızlı anahtarlamayı ve düşük gecikme değişkenliğini sağlar.
- **Anahtarlama:** Hücreler VPI/VCI değerlerine göre porttan porta aktarılır.
- **Arayüzler:**
  - UNI (User-Network Interface): kullanıcı ile ağ arası.
  - NNI (Network-Node Interface): anahtarlar arası. Özel ve genel türleri vardır.
  - B-ICI (Broadband Inter-Carrier Interface): iki genel ağ arası.
- **Referans modeli:**
  - AAL, kullanıcı verisini hücrelere böler ve birleştirir.
  - ATM katmanı başlık ekler ve akış denetimi yapar.
  - Fiziksel katman hücreleri iletim ortamına uyarlar.
- **Avantajları ve dezavantajları:**
  - Avantajı yüksek hız ve hizmet kalitesi (QoS) desteğidir.
  - Dezavantajı altyapının pahalı olmasıdır.
- **Kullanım alanları:** Kampüs ve internet omurgaları, DSL erişim ağları.

### Kablo televizyon (CATV)

- Uydu ya da karasal yayınları koaksiyel veya fiber kablo ile evlere taşıyan sistemdir.
- **Merkez (headend):**
  - Parabolik anten uydu sinyalini alır.
  - Düşük gürültülü yükselteç (LNA) sinyali güçlendirir.
  - Alt çevirici frekansı düşürür.
  - Uydu alıcısı sinyali TV sinyaline dönüştürür.
- **Ana hat (trunk):**
  - Kablodaki kayıp frekansla artar. Yükselteçlerin girişine eşitleyici (equalizer) konur ki tüm frekanslar eşit seviyede kalsın.
  - Gidiş yolu yaklaşık 47–450 MHz'tir. Dönüş yolu 5–20 MHz'tir; örneğin ödemeli TV verisi bu yoldan döner.
- **Bileşenler:**
  - Trunk ve hat uzatıcı yükselteçler (line extender).
  - Bölücüler (splitter) ve musluklar (tap).
  - Koaksiyel kablo: iç bakır iletken, yalıtkan ve dış kılıf.
  - HFC (Hybrid Fiber-Coax): ana hatta fiber, son kısımda koaksiyel kullanır.
- Ev içi dağıtımda iyi görüntü için prizde 60–80 dBµV seviyesi gerekir.
- Kablo modem ile internet ve kablolu telefon hizmeti de verilebilir.

### X.25

- ITU-T'nin (eski adıyla CCITT) protokol dizisidir. İlk paket anahtarlamalı protokollerdendir. Hata denetimi güçlüdür.
- Eskiden ATM'lerde (bankamatik) ve kredi kartı sistemlerinde yaygındı. Havacılıkta bazı kısımlarda hâlâ kullanılıyor.
- **Ağ cihazları:**
  - DTE: uç cihaz (PC, router, yazıcı).
  - DCE: modem ve benzeri cihazlar.
  - PSE (Packet Switching Exchange): ağın omurgasındaki anahtarlar.
- **Katmanlar:** OSI'nin ilk üç katmanına karşılık gelir.
  - Fiziksel katman: X.21.
  - Veri bağı katmanı: LAPB.
  - Paket katmanı (PLP): sanal devreleri kurar ve sonlandırır.
- Hata denetimi hem veri bağı hem paket katmanında yapılır.

### WiMAX

- Sabit ve mobil erişimi destekleyen geniş bant kablosuz MAN teknolojisidir. Noktadan noktaya ve noktadan çok noktaya bağlantı sağlar.
- **Hız ve menzil:** Teorik menzil yaklaşık 50 km'dir. İdeal koşulda hız yaklaşık 75 Mbps'tir, uzaklaştıkça düşer.
- WiMAX Forum'un ağ modeli üç parçadan oluşur:
  - MS: mobil istasyon.
  - ASN (Access Service Network): baz istasyonları ve ağ geçitleri.
  - CSN (Connectivity Service Network): IP bağlantısı ve temel IP işlevleri.
- **Sürümler:**
  - 802.16 (2001): 10–66 GHz, görüş hattı (LOS) gerekir.
  - 802.16a: 2–11 GHz, görüş hattı gerekmez (NLOS).
  - 802.16d (802.16-2004): sabit erişim.
  - 802.16e (2005): mobil erişim, "Mobile WiMAX".
  - WiMAX 2 (802.16m, 2011): IMT-Advanced (4G) hedefleri. Sabit kullanıcıya 1 Gbps, hareketli kullanıcıya 100 Mbps.
- **Wi-Fi ile karşılaştırma:**
  - Wi-Fi LAN içindir, lisanssız bantta çalışır ve QoS garantisi yoktur.
  - WiMAX MAN içindir, lisanslı ve lisanssız bantları kullanabilir ve QoS sağlar.
- **Diğer karşılaştırmalar:**
  - HiperMAN, WiMAX'in Avrupa karşılığıdır ve teknik olarak çok benzerdir.
  - UMTS (3G), CDMA tabanlıdır.
- Türkiye'de güvenlik kameralarının (MOBESE) görüntü aktarımında kullanıldığı örneği verildi. Kırsal alana internet götürmek için de uygundur.

### Ders sonrası notlar

- **GSM açık standarttır, açık kaynak değil.** Sunumda "açık kaynaklı, kod erişimine izin veren bir sistem" denildi. GSM, ETSI'nin yayımladığı açık bir standarttır. Operatörlerin kullandığı yazılımlar açık kaynak değildir.
- **GSM'in yayılışı:** Sunumda "2011'de bütün dünyaya kabul ettirildi" denildi. GSM 2000'lerin ortasında zaten dünyanın en yaygın mobil standardıydı. Sunumda geçen HSDPA (2005) ise GSM değil, 3G (UMTS) teknolojisidir.
- **ADSL kanalları:**
  - Sunumda "4 kHz'lik kanallar, indirme için 190 küsur, yükleme için 64 kanal" gibi karışık sayılar geçti.
  - Doğrusu: 256 alt kanal vardır ve her biri 4,3125 kHz genişliğindedir.
  - Yükleme için yaklaşık 25 kanal (yaklaşık 25–138 kHz) kullanılır.
  - İndirme için yaklaşık 224 kanal (yaklaşık 138 kHz–1,1 MHz) kullanılır.
  - İlk ADSL'de indirme hızı yaklaşık 8 Mbps, yükleme hızı yaklaşık 1 Mbps'tir.
- **ISDN açılımı:** "Integrated Services Digital Network" (Tümleşik Hizmetler Sayısal Şebekesi). ATM sunumunda "Integrated Switched Digital Networks" denildi; bu yanlış.
- **ISDN D kanalı:** Sunumda "D kanalının büyüklüğü B kanal sayısını belirler" denildi. Doğrusu: Arayüz tipi kanal düzenini belirler. BRI'da D kanalı 16 kbps, PRI'da 64 kbps'tir.
- **Frame Relay hızı:** Tipik erişim hızları 56 kbps ile 45 Mbps (T3) arasındadır. Sunumdaki "fiberle 2,4 Gbps" iddiası yaygın Frame Relay uygulamalarını yansıtmaz.
- **FECN ve BECN:** Bu bitler hata bildirimi değil, tıkanıklık (congestion) bildirimidir. Hatalı çerçeveler FCS ile tespit edilip atılır.
- **ATM hücre boyutu:** Sunumda "53 baytı Japonlar belirledi" denildi. 48 baytlık yük bir uzlaşmadır: ABD 64, Avrupa 32 bayt istiyordu. ITU-T (CCITT) bu iki değerin ortalamasını aldı.
- **ATM bugün:** Sunumda "standartları nispeten yeni" denildi. ATM 1990'ların teknolojisidir. Bugün omurgalarda büyük ölçüde MPLS ve Ethernet ile değiştirilmiştir.
- **WiMAX tarihleri:** 802.16a 2003'te, 802.16-2004 (d) 2004'te, 802.16e 2005'in sonunda yayımlandı. Sunumda 802.16a için "2000 başı" denildi.
- **UMTS bant genişliği:** UMTS (W-CDMA) kanalları 5 MHz genişliğindedir. Sunumda "5 milyar" diye geçiyor; bu bir telaffuz hatası.
- **GSM ile CDMA:**
  - "CDMA'da ses ve veri aynı anda olmaz" ifadesi CDMA2000 1x ve EV-DO için geçerlidir.
  - Klasik GSM/GPRS cihazlarının çoğunda da (sınıf B) ses ve veri aynı anda kullanılamaz.
  - Hız karşılaştırması nesle göre değişir. 3G'de iki taraf da CDMA tabanlıdır (W-CDMA ve CDMA2000).

**Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
