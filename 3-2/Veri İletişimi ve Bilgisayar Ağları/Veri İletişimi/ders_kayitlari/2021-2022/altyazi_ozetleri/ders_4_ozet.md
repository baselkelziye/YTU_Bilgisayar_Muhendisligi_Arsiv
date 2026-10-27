# Ders 4 Çalışma Özeti

## Genel Konular

- Dersin tarihi 18 Ekim 2021 Pazartesi. Ders online yapıldı.
  - Asıl anlatım yaklaşık 00:06'da başlıyor.
  - 01:09:35 ile 01:17:09 arasında ara var.
  - Ders yaklaşık 02:02'de bitiyor.
- Referans modelleri
  - OSI (Open Systems Interconnection) ve TCP/IP.
  - İki modelin ortaya çıkış biçimi ve farkları.
- OSI'nin 7 katmanı ve görevleri
  - Fiziksel, veri bağı, ağ, taşıma, oturum, sunu, uygulama.
  - Katmanlar arası arayüz ve servis ilişkisi.
  - Kapsülleme (encapsulation).
  - Her katmandaki veri biriminin adı.
- TCP/IP modeli ve diğer ağ modelleri
  - SNA, DNA, IPX/SPX, AppleTalk.
- İşaretler (signals)
  - Örneksel (analog) ve sayısal (digital) işaretler.
  - Periyodik ve periyodik olmayan (aperiodic) işaretler.
  - Fourier dönüşümü.
  - Genlik, frekans, faz, periyot.
  - Bit hızı ve bit aralığı.
- İletimi bozan etkenler
  - Zayıflama (attenuation), gecikme, gürültü (noise), çapraz girişim (crosstalk), bozulma (distortion).
- Kanal kapasitesi
  - Nyquist ve Shannon-Hartley teoremleri.
  - Sayısal örnek.
- İşaretlerin kodlanması
  - Dört dönüşüm türü.
  - Sayısal-sayısal kodlama: unipolar, polar (NRZ-L, NRZ-I, RZ, Manchester, diferansiyel Manchester). Bipolar kodlamaya sonraki derste geçilecek.

## Hocanın Özellikle Vurguladığı Kısımlar

- **OSI bir protokol değil, bir başvuru (referans) modelidir:**
  - ISO tarafından hazırlanmış de jure bir standarttır.
  - Hangi işin hangi katmanda yapılacağını söyler.
  - Ağ tasarımını kolaylaştırır.
- **İki modelin ters yönde oluşması:**
  - OSI önce tasarlanıp sonra uygulanmak üzere hazırlandı. Süreç politikayla ve uzun tartışmalarla yavaşladı.
  - TCP/IP zaten çalışan, de facto standart hâline gelmiş bir uygulamadan modele çevrildi.
  - "Çok formal olmak sizi geciktiriyor."
  - Yine de derslerde ve bilimsel anlatımlarda OSI modeli kullanılır.
- **Ezber cümlesi:** Ağla çalışan herkesin 7 katmanı ezbere bilmesi gerekir. Aşağıdan yukarı: *Please Do Not Touch Steve's Pet Alligator*.
  - Physical, Data Link, Network, Transport, Session, Presentation, Application.
- **Uçtan uca haberleşen bilgisayar değil, süreçtir (process):**
  - Ağ katmanındaki adres (ör. IP adresi) sadece cihazı adresler.
  - Cihaz üzerindeki uygulamayı adreslemek için bir katman daha yukarı çıkmak gerekir: taşıma katmanı.
- **Katman ilişkisi:** $n$. katman $(n-1)$. katmandan servis alır, $(n+1)$. katmana servis verir.
- **Kapsülleme:**
  - Her katman üstten gelen verinin önüne kendi başlığını (header) ekler.
  - Veri bağı katmanı ayrıca sona bir kuyruk (trailer) ekler. Kuyrukta hata denetimi için bir sağlama değeri (checksum) bulunur.
  - Alıcıda başlıklar katman katman soyulur. Matruşka bebekleri gibi.
- **Katmanlara göre veri birimi adları:** veri bağında çerçeve (frame), ağda paket (packet), taşımada segment.
- **Yönlendiriciler 3. katmanda kalır:** Ağ cihazlarını üst katmanlara çıkarmak çok daha maliyetli olur. 3. katmanda kalan gömülü (embedded) cihazlar daha verimlidir.
- **Bağlantılı ve bağlantısız servis:**
  - Bağlantılı (connection-oriented) servis telefon gibidir.
  - Bağlantısız (connectionless) servis posta veya telgraf gibidir. Buna datagram denir. Örnek: UDP (User Datagram Protocol).
  - İkisi arasında iyi-kötü sıralaması yok. Seçim uygulamaya göre yapılır.
- **Alt katman bağlantısız olsa da üstte bağlantılı servis verilebilir:** Örnek: IP paket anahtarlamalıdır ve bağlantısızdır. Üstündeki TCP bağlantılıdır. Ders sunumu da şu an böyle bir yapı üzerinden yapılıyor.
- **Shannon-Hartley örneği sınav tipi bir hesap.** Ayrıntısı aşağıda.
- **Manchester ve diferansiyel Manchester:** Bir öğrencinin isteği üzerine ders sonunda ikinci kez anlatıldı.

## Kısa Tekrar Notları

- OSI katmanları (Türkçe adlarıyla, aşağıdan yukarı):
  - Fiziksel, veri bağı, ağ, taşıma, oturum, sunu, uygulama.
- Katman grupları:
  - 1-3: ağ destek katmanları. Donanıma daha yakındır.
  - 4: taşıma. İki grup arasında geçiş noktasıdır.
  - 5-7: kullanıcı destek katmanları.
- Uçtan uca (end-to-end) çalışan katmanlar: taşıma, oturum, sunu, uygulama.
- Fiziksel katman:
  - Bitleri ortamda iletilebilecek işaretlere dönüştürür.
  - Ortam kablo, hava (radyo, kızılötesi) gibi farklı türlerde olabilir.
  - Kodlamanın genlikle mi, frekansla mı, fazla mı yapılacağı burada belirlenir.
  - Yönlü iletimde iletim yönünü ve gerekirse çıkış gücünü belirler.
- Veri bağı katmanının üç temel görevi:
  - Çerçeveleme (framing): verinin nerede başlayıp bittiğini belirtir. Hata sonrası yeniden senkron olmayı sağlar.
  - Hata denetimi (error control): bulma (detection) veya düzeltme (correction).
  - Akış denetimi (flow control): hızlı gönderici yavaş alıcıyı boğmasın. Alıcının geri bildirimi gerekir. Aksi hâlde alıcı tamponu taşar (buffer overflow) ve gelen veri atılır.
  - Ek görev: paylaşılan ortamda erişim denetimi (MAC).
  - Uygulamada iki alt katman vardır: LLC (Logical Link Control) ve MAC (Medium Access Control).
- Ağ katmanı:
  - Paketi kaynaktan hedefe farklı ağlar üzerinden iletir.
  - Mantıksal adresleme yapar. Örnek: IP adresi.
  - Yönlendirme (routing) yapar. Devre anahtarlamada rota başta bir kez belirlenir. Paket anahtarlamada her paket için karar verilir.
  - Mantıksal adresi fiziksel adrese dönüştürür, çünkü son atlama veri bağı katmanıyla yapılır.
- Taşıma katmanı:
  - Büyük veriyi segmentlere böler (segmentation). Alıcıda yeniden birleştirir (reassembly).
  - Segmentlere sıra numarası (sequence number) verir.
  - Sıralı ve hatasız iletim sağlar.
  - Hizmet erişim noktası (service access point, SAP) ile uygulamayı adresler. TCP/IP'de buna port denir. Porta erişim arayüzü soket (socket) olarak adlandırılır.
  - Akış denetimi yapar.
- Oturum katmanı:
  - Haberleşen cihazlar arasında eş zamanlama yapar.
  - Kontrol noktaları (checkpoint) koyar. Kopmada son sağlıklı noktadan devam edilir.
  - İş bitince veya hata hâlinde kaynakları düzgünce bırakır (graceful shutdown).
- Sunu katmanı:
  - Farklı sistemlerin veri gösterimini uyumlu hâle getirir. Örnekler: little endian ve big endian, farklı karakter kodlamaları.
  - Şifreleme (encryption) ve şifre çözme işlemlerinden sorumludur.
- Uygulama katmanı: kullanıcıya arayüz sunar. Örnekler: e-posta, dosya aktarımı, uzaktan oturum açma (remote login).
- TCP/IP katmanları:
  - Ağ erişim katmanı: Ethernet, 802.11.
  - İnternet katmanı: IP, ICMP. Modelin "dar boğazı"dır, tek seçenek IP'dir.
  - Taşıma katmanı: TCP, UDP, RTP.
  - Uygulama katmanı.
- İşaret türleri:
  - Sürekli (continuous), yani analog veya örneksel.
  - Ayrık (discrete), yani sayısal.
  - Her ikisi de periyodik veya periyodik olmayan olabilir.
- Periyot ve frekans: $T = \frac{1}{f}$.
  - Frekans birimi hertz (Hz).
  - Periyot birimleri: s, ms, μs, ns, ps.
- Faz kayması: 90° kayma, periyodun $\frac{1}{4}$'ü kadar kaymadır.
- Sayısal işaret:
  - Genlik, frekans ve faz yerine bit hızı ve bit aralığı ile ifade edilir.
  - Bit aralığı = bir bitin gönderilmesi için geçen süre.
- Nyquist (gürültüsüz kanal): $C = 2H\log_2 V$. $H$ bant genişliği, $V$ işaret seviyesi sayısıdır. İkili sistemde $V=2$ olduğundan $C=2H$.
- SNR: $SNR_{dB} = 10\log_{10}\frac{S}{N}$.
- Shannon-Hartley (gürültülü kanal): $C = H\log_2\left(1+\frac{S}{N}\right)$.
- Dört kodlama türü:
  - Sayısal-sayısal: bilgisayarla çevre birimi arası.
  - Örneksel-sayısal: sesin örneklenip bilgisayara aktarılması.
  - Sayısal-örneksel: telefon hattı üzerinden modemle veri.
  - Örneksel-örneksel: radyo yayını.
- Sayısal-sayısal kodlama grupları:
  - Unipolar.
  - Polar: NRZ, RZ, bifaz (biphase).
  - Bipolar: AMI, B8ZS, HDB3.

## Detaylı Açıklamalar

### Neden Standart Bir Model Gerekti

- İnternet öncesinde ağlar yaygınlaşırken farklı donanım ve işletim sistemi üreticilerinin birlikte çalışması gerekti.
- Bunun için esnek, açık, birlikte çalışabilen (interoperable) ve kolay anlatılabilen bir yapı arandı.
- Bugün OSI'yi birebir izleyen protokol pek yok. TCP/IP her yerde kullanılıyor.
- Hoca TCP/IP'yi mükemmel bulmuyor: "Protokol yığını (protocol stack) olarak oldukça sıkıntılı bir yapı."
- OSI'nin tasarım hedefleri, yani kolay anlatılabilirlik ve birlikte çalışabilirlik, büyük ölçüde tuttu.

### Ağ Katmanında Neden Farklı Adres Gerekir

- Bütün dünya tek bir ağda olsaydı ve herkese tek atlamada ulaşılsaydı, veri bağı katmanı yeterdi.
- Gerçekte ağlar heterojendir:
  - Kullanıcılar kablonet, ADSL, fiber, hatta dial-up kullanıyor.
  - Ağ sağlayıcısı aradaki geçişler için her yere 3. seviye cihaz koyuyor.
- Veri bağı adresi (ör. Ethernet adresi) farklı ağlarda geçerli değildir. Bu yüzden bir soyutlama gerekir.
- Ağ katmanı bu soyutlamayı mantıksal adreslemeyle sağlar.
- Hedef ağa varınca IP adresi fiziksel adrese çevrilir. Son atlama bu fiziksel adresle yapılır.

### Taşıma Katmanı ve Apartman Benzetmesi

- Ağ adresi apartmanın adresine benzer. Haberleşen apartmanlar değil, içindeki insanlardır.
- Daire numarası ve isim, cihaz üzerinde çalışan servisi gösteren taşıma adresine karşılık gelir.
- Örnek: Uygulama 10 MB'lık bir dosya göndermek ister. Taşıma katmanı bunu segmentlere böler, numaralandırır ve gönderir. Karşı tarafta sırayla birleştirilir.

### Akış Denetimi Neden İki Katmanda Var

- Hoca sordu: "Veri bağı katmanında akış denetimi var, taşıma katmanında neden yine var?"
- Veri bağı katmanında iki düğüm aynı ağdadır. Gönderici ortamın hızından hızlı gönderemez. Ama alıcı paketleri aynı hızda işleyemeyebilir. Bu yüzden yavaşlama ve bekleme gerekebilir.
- Uçlar arasına farklı ağlar girdiğinde ağın o anki durumu bilinmez.
  - Aradaki bir cihazda tıkanıklık (congestion) olabilir. Bu, diğer trafiğin oluşturduğu bir yoğunluktur.
  - Hoca bunu ara yollardan ana yola, sonra TEM'e çıkıp trafiğe takılmaya benzetiyor.
  - Taşıma katmanı bu durumu düzenler ve gönderimi yavaşlatır.
- Hoca bir öğrencinin cevabını hata denetimiyle karıştırdığı için düzeltti. Akış denetimi hatayla değil, hızla ilgilidir. Bağlantı kurulumundaki el sıkışmayla (handshake) da ilgisi yoktur.

### Fourier Yaklaşımı

- Basit bir sinüs dalgası doğrudan formülle ifade edilebilir. Karmaşık bir işaret ise doğrudan ifade edilemez.
- Fourier dönüşümü işareti çok sayıda periyodik bileşene ayırır. Her bileşenin etkisi bir katsayı ile ifade edilir.
- Ters Fourier dönüşümüyle işaret yeniden oluşturulur. Katsayı sayısı ne kadar fazlaysa sonuç aslına o kadar benzer.
- Sayısal bir kare dalga da farklı genlik, frekans ve fazdaki sinüslerin toplamı olarak gösterilebilir.

### İletimi Bozan Etkenler

- Kabloda gürültü, çapraz girişim ve zayıflama görülür.
- Kablosuz iletimde bunlara ek olarak yansımalar ve bozulmalar vardır.
- Çapraz girişim:
  - Terim telsiz ve radyoda kanalların karışmasından gelir.
  - FM bandında kanallar arasında koruma bantları (guard band) vardır. Ama işaret kayması (drift) olunca 100.6'yı dinlerken 100.8 duyulabilir.
  - Teknik anlamı, bir haberleşme kanalının başka bir kanalla karışmasıdır.
- Zayıflamaya çözüm olarak araya yükselteç (amplifier) konabilir. Ama analog işarette gürültü de yükseltilir. Önce gürültü temizlenmeli, sonra yükseltilmelidir. Bu da kolay değildir.
- Kullanılmayan bir kabloya osiloskop bağlanırsa bile hatta bir şeyler görülür. Ortamda çok fazla elektromanyetik işaret vardır.
- Farklı frekanstaki bileşenler ortamda farklı hızlarda yayılır. Bu yüzden Fourier bileşenleri karşıya farklı gecikmelerle ulaşır ve iletim kalitesi düşer.

### Çok Seviyeli İşaret ve Gürültü

- İki seviye (0 ve 1) yeterlidir. 4 veya 8 seviye kullanırsanız her sembolde 2 veya 3 bit taşıyabilirsiniz.
- Bedeli:
  - Seviyeler arası geçiş zaman alır.
  - Seviyeler birbirine yaklaşır ve gürültüde ayırt edilmesi zorlaşır.
- İki seviyede hata payı geniştir. Örneğin 5 V'luk sistemde 0,5 V hâlâ 0 sayılır, 2,7 V ve üstü 1 sayılır.
- 0-5 V arasında her volt için ayrı seviye (6 seviye) koyarsanız, gürültüde 4'ü 5'ten ayırmak zorlaşır.

### Shannon-Hartley Örnek Hesap

- Soru: 3-4 kHz arasındaki bir kanalda SNR 24 dB. En yüksek hız ve gereken ayrık seviye sayısı nedir?
- Bant genişliği: $H = 4000-3000 = 1000$ Hz.
- $\frac{S}{N} = 10^{24/10} = 10^{2{,}4} \approx 251$.
- $C = 1000\log_2(1+251) \approx 7978 \approx 8000$ bps.
- Nyquist'ten seviye sayısı: $8000 = 2\cdot 1000\cdot\log_2 V$. Buradan $\log_2 V = 4$ ve $V = 16$.

### Unipolar Kodlama

- 0 için hat boş bırakılır (0 V), 1 için pozitif gerilim kullanılır.
- İki temel sorunu var:
  - **DC bileşen:** Ortalama gerilim hep pozitiftir. Frekansı sıfır olan DC bileşen uzun hatta iyi gitmez, zayıflar.
  - **Senkronizasyon:** Uzun 0 veya 1 dizilerinde bitin nerede başlayıp bittiği kaybolur. Ayrı bir saat hattı eklense de saat işareti de uzun hatta kayar (drift).

### Polar Kodlama

- İki polarite kullanılır: pozitif ve negatif.
- **NRZ-L (Non-Return to Zero Level):**
  - 1 pozitif, 0 negatif seviyedir.
  - Arka arkaya aynı bitler gelirse seviye değişmez. Senkronizasyon kaybolabilir.
- **NRZ-I (Non-Return to Zero Inverted):**
  - Her 1'de polarite değişir. 0'da değişiklik olmaz.
  - Uzun 0 dizilerinde yine sinyal değişmez.
- **RZ (Return to Zero):**
  - Üç seviye kullanılır: $+$, $0$, $-$.
  - 1 pozitiften başlar, bitin ortasında 0'a döner. 0 negatiften başlar, ortada 0'a döner.
  - Her bitte geçiş olduğu için senkronizasyon sağlanır.
  - Ama çok sayıda 0 gelirse ortalama negatif olur. Yine bir DC bileşen oluşur.

### Bifaz (Biphase) Kodlama

- Hocaya göre kullanılan sayısal-sayısal kodlamaların en iyilerindendir. Amaç DC bileşeni tamamen kaldırmak ve her bitte geçiş sağlamaktır.
- **Manchester:**
  - 1: bitin ortasında negatiften pozitife geçiş.
  - 0: bitin ortasında pozitiften negatife geçiş.
  - Önceki bit ne olursa olsun 1 hep aynı biçimde kodlanır. Arka arkaya iki 1 gelirse arada işaret önce negatife iner.
- **Diferansiyel Manchester:**
  - Bitin ortasında her zaman geçiş vardır.
  - Bitin başında geçiş varsa (süreklilik bozuluyorsa) 0 kodlanır.
  - Bitin başında geçiş yoksa (süreklilik korunuyorsa) 1 kodlanır.
  - Bu derste ilk bitin Manchester alışkanlığıyla negatiften pozitife başladığı varsayılıyor.
- Hocanın tekrar anlatımı, slayttaki örneğe göre:
  - İlk 1: negatiften pozitife çıkar.
  - Ardından 0 gelir. Süreklilik bozulur, yani pozitifte bitmiş işaret bit başında negatife iner ve sonra pozitife çıkar.
  - Ardından 1 gelir. İşaret kaldığı yerden devam eder, pozitiften negatife iner.
  - Bir 1 daha gelir. Yine kaldığı yerden, negatiften pozitife çıkar.

### Ders sonrası notlar

- **TCP/IP'nin uygulama katmanı:** Hoca, OSI'nin uygulama ve oturum katmanlarının TCP/IP'de uygulama katmanında birleştiğini söyledi. Doğrusu, OSI'nin üç üst katmanı (oturum, sunu, uygulama) TCP/IP'nin tek uygulama katmanına karşılık gelir.
- **Taşıma katmanında akış denetimi ve tıkanıklık denetimi:** Hocanın anlattığı ara ağlardaki yoğunluk aslında tıkanıklık denetiminin (congestion control) konusudur. TCP'de iki mekanizma ayrıdır:
  - Akış denetimi, alıcının tamponunu korumak için uçtan uca yapılır (alıcı penceresi).
  - Tıkanıklık denetimi, aradaki ağı korumak için yapılır.
  - Veri bağı katmanındaki akış denetimi ise sadece komşu iki düğüm arasında, atlamadan atlamaya (hop-by-hop) çalışır.
- **Çoğullama hangi katmanda:** Hoca çoğullamayı (multiplexing) ağ katmanının görevleri arasında saydı. Klasik anlatımda birden fazla uygulama bağlantısının tek ağ bağlantısı üzerinden taşınması taşıma katmanının görevidir. TCP/IP'de bu iş port numaralarıyla yapılır.
- **Veri bağı katmanının kuyruğu:** Kuyruktaki hata denetim alanına FCS (Frame Check Sequence) denir. Ethernet'te bu alan bir CRC değeridir. Basit bir toplam (checksum) değildir.
- **Sunu katmanı:** Şifrelemenin yanında sıkıştırma (compression) da bu katmanın görevlerindendir.
- **Shannon-Hartley'nin kökeni:** Hoca formülün "ölçümler yapılarak bulunduğunu" söyledi. Formül deneysel değil, kuramsaldır. Claude Shannon 1948'de bilgi kuramı (information theory) çalışmasında türetti. Ralph Hartley'nin 1928'deki çalışması bunun öncülüdür.
- **Nyquist kapasitesi ile örnekleme teoremi farkı:** İkisi aynı kişiyle anılır, ama farklı şeyler söyler.
  - Kapasite formülü, $H$ bant genişliğindeki gürültüsüz bir kanalda saniyede en fazla $2H$ sembol gönderilebileceğini söyler.
  - Örnekleme teoremi ise analog işaretin en yüksek frekansının en az iki katı hızda örneklenmesi gerektiğini söyler.
  - Hoca ikisini bir arada anlattı. Örnekleme teoremi 7. derste ayrıca işleniyor.
- **Frekansa bağlı gecikme:** Hocanın "yayılma gecikmesi" (propagation delay) dediği etkinin yaygın adı gecikme bozulmasıdır (delay distortion). Farklı frekanstaki bileşenlerin farklı hızda yayılmasından doğar.
- **Manchester yön kuralı:** Bu derste kullanılan kural, yani 1 = negatiften pozitife, IEEE 802.3 (Ethernet) kuralıdır. Bazı kitaplarda (G. E. Thomas kuralı) tersi kullanılır. Sınavda slayttaki kurala uyun.
- **Altyazı hataları:**
  - "Maclier" MAC layer, "Facult switching" packet switching'dir.
  - 00:52-00:54 arasında "socket switching" ve "shortcut switching" geçen yerler bağlama göre circuit switching (devre anahtarlama) olmalıdır.
  - "Soundlink rate" sampling rate (örnekleme hızı), "V-Face" biphase'tir.
  - "Otoneyeşim" attenuation (zayıflama) demektir.

**Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
