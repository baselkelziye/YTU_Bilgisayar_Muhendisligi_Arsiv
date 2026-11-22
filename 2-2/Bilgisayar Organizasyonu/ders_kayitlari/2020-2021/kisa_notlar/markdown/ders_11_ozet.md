# Ders 11 Çalışma Özeti

## Genel Konular

- Tek çevrimli bilgisayar (single cycle computer) mimarisinin tekrarı
  - Register file iki çıkış kanalına (A ve B) sahiptir; D girişine function unit ya da veri hafızasından gelen değer yazılır.
  - Function unit, aritmetik birim, lojik birim ve shifter'dan oluşur. Veri hafızası A kanalını adres, B kanalını veri olarak kullanır; hafızaya yazmak için MW (memory write) kontrol ucu eklenir.
  - Kontrol kelimesi (control word) alanları: DA, AA, BA, MB, FS, MD, RW, MW, PL, JB, BC (ekrandan, 00:10:00).
  - Komut (instruction), kontrol kelimesinin sıkıştırılmış, daha üst seviyeli hâlidir. Komuttan kontrol kelimesine geçişi komut çözücü (instruction decoder) yapar. Örneğin function unit'te "yazmacı sıfırla" fonksiyonu yoktur, ama "sıfırla" komutu arka planda A XOR A çalıştırabilir.
  - PC, komut hafızasında sıradaki komutu seçer. Ardışık akışta PC komut boyu kadar artar (2 byte'lık komutta 2'şer). Koşulsuz dallanmada A kanalındaki değer PC'ye doğrudan yüklenir; koşullu dallanmada komuta gömülü 6 bitlik offset işaret genişletilip (sign extend) PC'ye eklenir. Offset ikiye tümleyen sayıdır, negatif olabilir.
  - Branch control birimi PL, JB, BC kontrollerini ve function unit'in V, C, N, Z bayraklarını girdi olarak alır.
  - Mavi bloklar (PC, register file, veri hafızası) saatin yükselen kenarında durum değiştiren senkron devrelerdir. Gri bloklar kombinasyoneldir; değerleri hazırlayıp senkron blokların girişine kadar taşır ve saat kenarını bekler.
  - Kritik yol: olası tüm komutlar içinde en uzun süren yoldur (ör. register file, MUX B, function unit, MUX D'nin hepsini kullanan komut). Bu süre $T$ ise en yüksek saat frekansı $f_{max} = 1/T$ olur.
- Pipeline (boru hattı) mantığı
  - Bir komutun yürütülmesi alt adımlara bölünür: instruction fetch (IF), instruction decode, operand fetch (OF), execution (EX), write back (WB). Bazı işlemcilerde 4, bazılarında 6 adım olabilir.
  - Tek çevrimli mimaride bu adımlar tek saat çevriminde art arda yapılır; bir blok çalışırken diğerleri boşta bekler. Alt adımlara bölme çok çevrimli (multicycle) mimaride mümkündür.
  - Her adımdan sonra bir yazmaç eklenirse her blok aynı anda farklı bir komutun farklı adımını yürütür. Bir komut yine birkaç çevrimde biter, ama birim zamanda biten komut sayısı (throughput) artar.
  - Alt çevrim süresi en uzun alt adıma göre belirlenir.
- Pipeline örneği (ekrandan, 00:25:00 ve 00:30:00)
  - 4 aşama: IF, OF, EX, WB. En uzun aşama 5 ns, aşamaların toplamı 17 ns. 20 komut var, dallanma yok.
  - Pipeline: $20 + (4-1) = 23$ çevrim, $23 \times 5 = 115$ ns.
  - Klasik (seri) yöntem: bir komut 17 ns, $20 \times 17 = 340$ ns.
  - 8 aşamalı pipeline olsaydı: $20 + 7 = 27$ çevrim.
- Pipeline'ı bozan durumlar
  - Veri bağımlılığı: birinci komut R1 + R2'yi R3'e yazıyor, ikinci komut R3'ü kullanıyorsa ikinci komut birincinin write back'i bitene kadar bekletilir.
  - Dallanma: komutlar önceden prefetch kuyruğuna çekilir. Koşullu dallanma uzak bir adrese giderse kuyruktaki komutlar boşa gider ve yeni adresten tekrar çekilmesi gerekir.
- Mikro işlemci ve mikro denetleyici
  - Mikro işlemci (datapath'e karşılık gelen CPU) tek başına çalışamaz. Buffer'lara, saat üretecine, hafızaya ve giriş-çıkış birimlerine ihtiyaç duyar.
  - Mikro denetleyici, işlemciyi, hafızayı, program hafızasını, çevre birimlerini ve saat üretecini tek entegrede toplar; enerji verilince çalışabilir.
- Giriş-çıkış birimleri
  - Klavye: tuşlar satır-sütun matrisidir. Mikro denetleyici bir dekoder üzerinden satırları sırayla aktif eder (satırları sürer); MUX ile sütunları sırayla okur. Sıfırdan farklı değer görülünce satır ve sütun bilinir; bir look-up table ile ASCII karşılığı bulunur. Şekilde dekodere 3, MUX'a 4 seçim hattı gider (ekrandan, 00:40:00).
  - Manyetik disk: veri halkalar (track) ve sektörler hâlinde tutulur; okuma kafası sektörler arasında hareket eder.
  - CRT monitör: elektron tabancasından çıkan elektron, yatay ve dikey elektromanyetik alanlarla yönlendirilip ekranı tarar. Her görüntü hücresi kırmızı, yeşil ve mavi alt piksellerden oluşur. LCD'de arka aydınlatma ve likit kristallerin polarizasyonu kullanılır.
  - Giriş-çıkış birimi ile arayüz (interface) farklı şeylerdir. Arayüz, birim ile CPU'nun veri, adres ve kontrol yolları arasındaki iletişimi sağlar.
- Arayüzler ve adres çözümleme
  - Tek bir veri yolunda aynı anda yalnız bir cihaz konuşabilir. Adres çözümleme devresi, komutun adresine göre (ör. klavye 10H, CRT 20H) yalnız ilgili arayüzün chip select ucunu 1 yapar, diğerlerini 0 yapar.
  - Chip select 0 olan cihazın veri uçları yüksek empedans gösterir; cihaz sanki hattan kopmuş (açık devre) gibi davranır.
  - Paralel arayüz (ekrandan, 01:00:00): çift yönlü veri yolu, bus buffer'lar, CS, RS1, RS0, RD, WR girişleri; Port A, Port B, kontrol ve durum (status) yazmaçları. CS = 0 iken veri yolu yüksek empedanstadır; RS1 RS0 = 00, 01, 10, 11 sırasıyla Port A, Port B, kontrol ve durum yazmacını seçer.
  - G/Ç arayüzleri adres uzayında 1-4 byte gibi küçük alan kaplar (az adres ucu), hafıza birimleri 1K, 2K gibi büyük alan kaplar.
  - 16 bitlik adres yolunda arayüzün düşük anlamlı 2 biti yazmaç seçer; kalan 14 bit adres çözümleme devresine gider.
  - Kontrol yazmacına yazılan değerle portların yönü ayarlanır. Port A ve Port B'ye 16 LED bağlıyken iki porta da 55H yazılırsa LED'ler biri yanık biri sönük olur ($55H = 01010101_2$).
  - Durum yazmacının bir biti "veri hazır" bayrağı olarak kullanılabilir. RD ve WR uçları tek bir $R/\overline{W}$ ucunda birleştirilebilir (1: oku, 0: yaz).
- Paralel veri aktarımında zamanlama
  - Strobe (tek kontrol uçlu) aktarım: hedef başlatırsa kaynak verisinin hazır olup olmadığı bilinmez; kaynak başlatırsa hedefin veriyi aldığı garanti değildir.
  - Handshaking (el sıkışma): request ve reply uçlarıyla iki taraf birbirini onaylar. Hedef başlatırsa request gönderir, kaynak veriyi koyup reply verir. Kaynak başlatırsa request ile birlikte veriyi koyar, hedef reply ile kabul eder.
- Seri haberleşme
  - Asenkron: iki terminal TX, RX ve ortak ground ile bağlıdır, ortak saat yoktur. Bit hızı, veri biti sayısı, start/stop bitleri önceden anlaşılır. Hat boşta lojik 1'dir. Start biti (0), en düşük anlamlı bitten başlayarak veri bitleri, sonra lojik 1 seviyesinde stop bitleri gönderilir. Gönderen sağa ötelemeli, alan ötelemeli yazmaç kullanır. Saat farkı kaymaya yol açtığı için küçük çerçeveler (5-8 bit) kullanılır.
  - Senkron: ortak saat hattı da vardır. Büyük paketler, senkronizasyon byte'ları ve CRC gibi hata kontrol bitleri kullanılır.
  - Klavye ile arayüzü arasında senkron seri haberleşme olabilir. USB'de cihazlar hub'lar üzerinden ağaç yapısında bağlanır. Manchester kodlamada bitler seviye yerine geçişlerle ifade edilir.
- Veri aktarım yöntemleri
  - Polling: CPU durum yazmacını okur, bayrak bitini maskeler, bayrak 1 olana kadar tekrar eder, sonra veri yazmacını okur. Kolay ama CPU'yu meşgul eder.
  - Kesme tabanlı: cihaz kesme isteği gönderir; CPU yürüttüğü komutu bitirip acknowledge verir; cihaz vektör adresini gönderir, CPU ilgili kesme alt programına dallanır.
  - Daisy chain: kesme istekleri OR ile CPU'ya bağlanır, acknowledge cihazlar arasında PI/PO uçları üzerinden zincirle geçer. CPU'ya yakın cihazın önceliği yüksektir.
  - Öncelik kodlayıcı (priority encoder) ile kesme: en öncelikli kaynak en yüksek anlamlı girişe bağlanır; çıkış sıfırlarla tamamlanıp vektör adresi (VAD) olur. Maske yazmacı ile kesmeler tek tek kapatılabilir (ekrandan, 01:40:00).
  - DMA: CPU, DMA kontrolcüsünü G/Ç adresi, hafıza başlangıç adresi ve byte sayısı ile programlar (ör. G/Ç 100, hafıza 200, 20 byte). Kontrolcü bus request gönderir, CPU bus grant verip adres, veri ve kontrol uçlarını yüksek empedansa çeker. Veri CPU'ya uğramadan G/Ç ile hafıza arasında taşınır; bitince kesme ile CPU uyandırılır.
- Önbellek (cache) temelleri
  - Yerellik: spatial locality (erişilen verinin komşularına yakında erişilmesi, ör. dizi elemanları) ve temporal locality (aynı veriye bir süre sonra yeniden erişilmesi, ör. döngüde güncellenen değişken).
  - Bellek hiyerarşisi: yazmaçlar, L1, L2, L3 cache, ana hafıza, disk. İşlemciye yaklaştıkça hız ve bit başına maliyet artar, kapasite azalır. Diskten ana hafızaya blok taşıma sanal bellek konusudur.
  - Aranan veri L1'de yoksa L2'ye, orada da yoksa ana hafızaya bakılır; veri ve çevresi alt seviyelere taşınır.
  - Üç eşleme yöntemi: direct mapped, fully associative, set associative. Fully associative'de blok her yere konabilir, tüm bloklara bakılır; değiştirmede FIFO ya da LRU kullanılır. Set associative ikisinin arasıdır: satır belli, satırdaki bloklardan hangisinin değişeceği kurala bağlıdır.
- Direct mapped cache
  - 16 byte hafıza, 4 satırlık (4 byte) cache, satır genişliği 1 byte: indeks = adresin düşük anlamlı 2 biti, tag = yüksek anlamlı 2 bit. 0, 4, 8, C adresleri 0. satıra düşer (ekrandan, 02:45:00).
  - Her satırda veri, tag ve valid biti tutulur. Valid biti başlangıçta 0'dır; rastgele içerikle tag'in tesadüfen tutması bu sayede yanlış "bulundu" sonucu vermez.
  - Erişim: indeksle satıra git, valid bitine bak, tag'leri karşılaştır; tutarsa hit, tutmazsa hafızadan oku, satırı, tag'i ve valid bitini güncelle.
  - Örnek: 8 byte kapasite, 2 byte blok, 16 byte hafıza: 4 satır, indeks 2 bit, byte offset 1 bit, tag $4-2-1 = 1$ bit (ekrandan, 02:50:00).
  - Genel adres bölmesi: tag, indeks, word offset, byte offset.

## Hocanın Özellikle Vurguladığı Kısımlar

- ALU tasarımı
  - Hem verilen fonksiyon tablosundan tasarım hem verilen tasarımdan fonksiyon bulma soruları çözülmüştü. Aritmetik birim tam toplayıcı ile kurulur; X, Y ve carry-in girişlerine bağlanacak fonksiyonlar bulunur.
- Kritik yol ve saat frekansı
  - En uzun süren komutun yolu saat periyodunu belirler, $f = 1/T$.
- Pipeline çevrim sayısı
  - $n$ komut, $k$ aşama için toplam çevrim $n + k - 1$'dir. Toplam süre bu sayı çarpı alt çevrim süresidir.
- Yüksek empedansın anlamı
  - Chip select 0 olan cihazın veri hattı açık devre gibi olur; böylece veri yolunda yalnız CPU ve seçilen cihaz kalır.
- Giriş-çıkış birimi ile arayüzün farkı
  - Arayüz, birim ile CPU yolları arasındaki köprüdür.
- Yerellik türleri
  - Spatial ve temporal locality tanım olarak birbirinden ayrılabilmelidir.
- Asenkron haberleşme
  - Asenkron seri haberleşme tarafının net bilinmesi gerekir; senkron tarafa daha az ağırlık verildi.
- Direct mapped cache'te valid ve tag alanlarının neden gerektiği
  - Satır adresten belli olsa da orada başka bir adresin verisi ya da rastgele içerik olabilir.

## Kısa Tekrar Notları

- Komut, kontrol kelimesinin sıkıştırılmış hâlidir; çözücü komutu kontrol kelimesine çevirir.
- Senkron bloklar saat kenarında güncellenir, kombinasyonel bloklar değerleri hazırlar.
- $f_{max} = 1/T_{kritik}$.
- Pipeline: IF, ID, OF, EX, WB; adımlar arasına yazmaç eklenir, throughput artar.
- 20 komut, 4 aşama, 5 ns: 23 çevrim, 115 ns. Seri: 340 ns. 8 aşama: 27 çevrim.
- Veri bağımlılığı ve dallanma pipeline akışını bozar.
- Mikro denetleyici kendi başına çalışır; mikro işlemcinin çevre birimlerine ihtiyacı vardır.
- Klavye: satırlar sürülür, sütunlar okunur.
- Adres çözümleme: tek cihazın CS'si 1, diğerleri 0 (yüksek empedans).
- Paralel arayüz: RS1 RS0 = 00 Port A, 01 Port B, 10 kontrol, 11 durum yazmacı.
- Strobe: tek kontrol ucu, onay yok. Handshaking: request ve reply.
- Asenkron seri: start biti 0, LSB önce, stop bitleri 1; ortak saat yok.
- Senkron seri: ortak saat, büyük paket, CRC.
- Polling, kesme, DMA: üç veri aktarım yöntemi.
- Daisy chain'de öncelik bağlantı sırasıdır; öncelik kodlayıcıda en yüksek anlamlı giriş en önceliklidir.
- DMA'da CPU bus grant verir ve hatlarını yüksek empedansa çeker.
- Spatial ve temporal locality.
- Hiyerarşi: işlemciye yaklaştıkça hız ve maliyet artar, kapasite azalır.
- Direct mapped: indeks = $\log_2(\text{satır sayısı})$ bit, byte offset = $\log_2(\text{blok byte})$ bit, tag = kalan bitler; ayrıca valid biti.
- Direct mapped'de aynı satıra düşen iki adrese sırayla erişmek satırı sürekli bozar; fully ve set associative bunu azaltır.

## Detaylı Açıklamalar

- Tek çevrimli bilgisayarda zamanlama
  - Komut hafızadan çıkıp çözücüden geçince kontrol uçları belirlenir. A ve B kanallarından gelen değerler MUX B, function unit ve MUX D'den geçip register file'ın D girişine kadar ulaşır. Bu sırada değerler henüz doğru olmayabilir; yollar oturduktan sonra gelen yükselen saat kenarında sonuç yazmaca yazılır. Bu yüzden saat periyodu, en uzun yolun (kritik yol) süresinden kısa olamaz. Ekranda gösterilen şekilde blok gecikmeleri PC 0,2 ns, komut hafızası 4 ns, register file okuma 0,6 ns, MUX B 0,2 ns, function unit ya da veri hafızası 4 ns, MUX D 0,2 ns, register file yazma 0,6 ns olarak verilmiştir (ekrandan, 00:20:00); bunların toplamı 9,8 ns'dir (ara adım eklendi).
- Pipeline'ın çevrim sayısı
  - Birinci komut 1. çevrimde IF'ye girer, her çevrimde bir sonraki komut IF'ye girer; 20. komut 20. çevrimde IF'ye girer. Bu komutun bitmesi için 3 aşama daha gerekir, toplam 23 çevrim olur. 8 aşamalı bir pipeline'da aynı mantıkla $20 + 7 = 27$ çevrim gerekir. Pipeline'da tüm alt bloklar aynı anda farklı komutlar için çalıştığı için boşta bekleyen blok kalmaz. <!-- BELİRSİZ: Örnekteki IF, OF, EX aşamalarının tek tek süreleri karelerde görünmüyor; altyazıdan yalnız en uzun aşamanın 5 ns, WB'nin 4 ns ve toplamın 17 ns olduğu anlaşılıyor. -->
- Paralel arayüzün kullanımı
  - CPU önce kontrol yazmacına (RS1 RS0 = 10) bir değer yazarak portların yönünü belirler. Hocanın örneğinde kontrol yazmacının 0. biti Port A'nın, 1. biti Port B'nin yönünü belirler. Sonra adres uçlarına 00 verip veri yazınca değer Port A uçlarında görünür. Klavye örneğinde tuşa basılınca durum yazmacının 0. biti 1 olur; CPU polling ile durum yazmacını (11) okur, bit 1 olunca veri portunu okur.
- Strobe ve handshaking zamanlaması
  - Hedefin başlattığı strobe aktarımında strobe'un yükselen kenarıyla kaynak veriyi yola koyar, strobe düşünce kaldırır. Kaynağın başlattığında kaynak önce veriyi yola koyar, sonra strobe gönderir. Handshaking'de hedef request gönderir, kaynak veriyi koyup reply'ı 1 yapar; hedef veriyi örnekler ve request'i düşürür, kaynak reply'ı düşürür ve veriyi kaldırır (ekrandan, 01:15:00).
- Tuşa basmanın algılanması
  - Bir soru üzerine anlatıldı: tuş yükselen kenarda (basıldığı an), düşen kenarda (bırakıldığı an) ya da seviyeyle (basılı olduğu sürece) algılanabilir. Kenar algılama uzun basışta bile tek basış üretir. Seviye kontrolünde basış sayısı kontrol frekansına bağlıdır; frekans yüksekse kısa bir basış birkaç karakter olarak algılanabilir. Bunu klavyedeki mikro denetleyici çözer, arayüze ise dönüştürülmüş strobe işareti gider.
- Asenkron seri çerçeve
  - Ekrandaki çerçevede hat boşta 1'dir; start biti (0) ardından karakter bitleri 1, 1, 0, 0, 0, 1, 0, 1 sırasıyla gönderilir ve hat stop bitleri için 1'e döner (ekrandan, 01:25:00). Alıcı her bit süresinde hattı örnekler. İki tarafın saatleri arasındaki küçük bir fark uzun bir veri akışında örnekleme anını bir sonraki bite kaydırabilir; bu yüzden asenkron haberleşme küçük çerçevelerle yapılır.
- DMA akışı
  - CPU, DMA kontrolcüsünü bir çevre birimi gibi programlar. Kontrolcü bus request gönderir; CPU yürüttüğü komutu bitirip bus grant verir ve AB, DB, RD, WR uçlarını yüksek empedansa çeker (ekrandan, 01:45:00). Kontrolcü adres yoluna adresi koyar, G/Ç cihazını ve hafızayı aktif eder, G/Ç ile handshaking yaparak byte'ları taşır. 20 byte bitince bir kesme ile CPU'yu yeniden devreye alır.
- Direct mapped cache adım adım
  - Boş cache'te tüm valid bitleri 0'dır. 0 adresi (0000) okununca indeks 00'a bakılır, valid 0 olduğu için miss olur; veri (X) yazılır, tag 00 ve valid 1 yapılır. 1 adresi (0001) okununca satır 01'de rastgele bir değer ve tesadüfen 00 tag'i olsa bile valid 0 olduğu için miss olur; Y yazılır, tag 00, valid 1 yapılır. 9 adresi (1001) okununca yine satır 01'e gidilir; valid 1, ama tag 10 ile 00 tutmaz; miss olur, satır 9 adresinin içeriğiyle güncellenir, tag 10 yapılır (ekrandan, 02:40:00).
  - Blok 2 byte olduğunda adresin en düşük biti blok içindeki byte'ı seçer (byte offset), sonraki 2 bit indeks, en yüksek bit tag olur. Daha geniş bloklarda bir satırda birden fazla word bulunur; adres tag, indeks, word offset ve byte offset olarak bölünür.
  - Bir öğrencinin sorusu üzerine: program sürekli 0 ve 8 adreslerine erişirse ikisi de 0. satıra düştüğü için satır sürekli bozulur, diğer 3 satır kullanılmaz. Fully associative ve set associative eşleme bu sorunu azaltmak için önerilmiştir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
