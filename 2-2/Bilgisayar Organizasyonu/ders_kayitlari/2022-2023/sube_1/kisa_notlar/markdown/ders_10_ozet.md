# Ders 10 Çalışma Özeti

## Genel Konular

- Dersin ilk bölümü ara sınav (vize) sorularının çözümüdür. İkinci bölümde önceki haftalardan kalan boru hattı (pipeline) konusu tamamlanır, ardından giriş/çıkış (input/output) arayüzüne geçilir. Slaytlar Mano ve Kime'nin "Logic and Computer Design Fundamentals" kitabının 9. bölümünden ve giriş/çıkış bölümündendir.
- Vize sorularında tekrar edilen konular
  - İşaretli çıkarmada bayraklar: $127 - (-1) = 128$ 8 bitte gösterilemez; taşma (overflow) bayrağı 1, sıfır bayrağı 0 olur, sonuç negatif görünür.
  - İkiye tümleyen: $(1111\,0000)_2 = -16$.
  - Adresleme modları: sabit değer atamak anlık (immediate) adresleme, işlenen olarak doğrudan yazmaç kullanmak yazmaç adreslemedir.
  - Bellek kapasitesi $= 2^{\text{adres biti}} \times$ veri genişliği: 12 bit adres ve 64 bit veri ile $2^{12} \cdot 8\ \text{B} = 32$ KB; 16 bit adres ve 32 bit veri ile $2^{16} \cdot 4\ \text{B} = 256$ KB (ekrandan, 00:10:00).
  - Aritmetik sağa öteleme işaret bitini korur, taşma üretmez; aritmetik sola ötelemede işaret biti değişirse taşma olur.
  - Program sayacı (PC) her komuttan sonra değişir: dallanmada hedefe, diğerlerinde bir sonraki komuta.
  - Komut formatı: 20 bitlik komut ve 32 yazmaçta üç yazmaç alanı $3 \times 5 = 15$ bit, opcode 5 bit, yani 32 farklı işlem; 24 bit ve 64 yazmaçta $3 \times 6 = 18$ bit, opcode 6 bit, 64 işlem.
  - Bellek genişletme: 128K×16'dan 128K×64 için 4 modül yan yana (veri yolu genişletme); 128K×16'dan 1M×32 için 16 modül ve 3'e 8 dekoder (ekrandan, 00:15:00).
  - PLA, PAL ve ROM: PAL'da AND katı programlanabilir, OR katı sabittir; ROM'da AND katı sabit (dekoder), OR katı programlanabilirdir.
  - Bayrak lojiği: tüm yazmaç bitlerini giren NOR kapısı sıfır bayrağını, XOR kapısı eşlik (parity) bitini üretir.
  - Asenkron (ripple) sayıcı, karşılaştırıcı, sayıcı tasarımında flip-flop sayısı ($\lceil \log_2 \text{durum sayısı} \rceil$), doğrusal geri beslemeli ötelemeli yazmaç (LFSR), çarpım için yazmaç genişliği, TEST ve NEG komutları, AND ile bit temizleme.
  - Öteleme-toplama (shift-and-add) çarpıcısında yazmaç ve toplayıcı genişliği ile saat darbesi sayısı (ekrandan, 00:40:00 ve 00:45:00).
- Tek çevrimli bilgisayarda saat frekansı sınırı
  - Her komut bir saat çevriminde bittiği için periyot, en uzun komutun geçtiği blokların gecikmeleri toplamından kısa olamaz (ekrandan, 01:10:00).
- Boru hattı (pipeline)
  - Komut yürütme aşamalara bölünür: komut getirme (IF), çözme (ID), işlenen getirme (OF), yürütme (EX), geri yazma (WB). Aşamalar arasına yazmaç konur; her saat çevriminde farklı komutların farklı aşamaları aynı anda yürür (ekrandan, 01:15:00).
  - Kesintisiz akış için üç koşul: ardışık komutlar aynı tekil donanım kaynağını aynı anda istememeli (yapısal tehlike), bir komutun girdisi önceki komutun çıktısı olmamalı (veri tehlikesi), koşullu dallanma olmamalı (kontrol tehlikesi) (ekrandan, 01:25:00).
  - Saat periyodu en yavaş aşamanın süresine göre seçilir; verim (throughput) artar.
- Giriş/çıkış (G/Ç) sistemi
  - İşlemci, RAM, ROM ve G/Ç birimleri veri, adres ve kontrol yollarını paylaşır; adres çözümleme devresi aynı anda yalnız bir birimi seçer (ekrandan, 01:35:00).
  - 8086'da bellek işlemleri MOV, G/Ç işlemleri IN/OUT komutlarıyla yapılır; $M/\overline{IO}$ ucu MOV'da 1, IN/OUT'ta 0 olur.
  - G/Ç cihazı ile işlemci arasında bir arayüz (interface) bulunur.
- Klavye tarama: mikro denetleyici 3 bitle 8 satırı dekoderden sürer, 4 bitle 16 sütunu çoklayıcıdan okur (ekrandan, 01:40:00).
- Veri aktarım yöntemleri: yoklama (polling), kesme (interrupt), doğrudan bellek erişimi (DMA) (ekrandan, 01:45:00).
- İkincil bellek, önbellek ve yerellik; CRT ve sıvı kristal ekranlar.
- Paralel arayüz: CS, RS1, RS0, RD, WR uçları; Port A, Port B, kontrol ve durum yazmaçları (ekrandan, 01:55:00).
- Strobe ile ve el sıkışma (handshaking) ile asenkron veri aktarımı (ekrandan, 02:05:00 ve 02:10:00).
- Seri haberleşme: paralelden seriye ve seriden paralele dönüşüm, asenkron çerçeve (start, veri, eşlik, stop bitleri), senkron haberleşme, NRZI ve Manchester kodlama, USB hub ağacı (ekrandan, 02:20:00 ve 02:25:00).
- Kesme yönetimi: vektör adresi, papatya zinciri (daisy chain), öncelik kodlayıcı ve maske yazmacı (ekrandan, 02:35:00).
- DMA kontrolcüsü: BR/BG ile yolların devri ve bellek ile G/Ç arasında doğrudan aktarım (ekrandan, 02:40:00).

## Hocanın Özellikle Vurguladığı Kısımlar

- Öteleme-toplama çarpıcısı "sınavın en can alıcı sorularından biri" olarak çözüldü.
  - 15 × 15 dört saat darbesinde biter. A yazmacı 7 bit, B 4 bit, toplayıcı 7 bit, P 7 bit yeterlidir; toplamın 8. biti toplayıcının elde çıkışında (Cout) tutulur. Ardışık toplama ile çarpımda ise 15 toplama ve 8 bitlik toplayıcı gerekirdi.
- Boru hattının çalışabilmesi için üç koşul özellikle yazdırıldı: tekil donanım kaynağına eş zamanlı ihtiyaç olmaması, ardışık komutlarda veri bağımlılığı olmaması, koşullu dallanma olmaması.
- Mikro işlemci ile G/Ç birimi arasındaki üç aktarım yöntemi (polling, interrupt, DMA) "özellikle vurgulayalım" diye ayrıca tekrar edildi.
- Yüksek empedans: seçilmeyen birim hattan kopmuş gibi davranır; adres çözümleme ve paralel arayüzde birden fazla birimin aynı yola çıkmamasını bu sağlar.
- Strobe ile aktarımda karşı tarafın veriyi alıp almadığı bilinemez; bu doğrulamayı el sıkışma sağlar.
- Klavye gibi yavaş cihazlarda polling işlemciyi boşuna meşgul eder; bu yüzden kesme tabanlı okuma kullanılır.

## Kısa Tekrar Notları

- Bellek kapasitesi: $2^{a} \times w$; 16 bit adres, 32 bit veri: 256 KB.
- $n$ bitlik iki sayının çarpımı $2n$ bit ister: $4$ bitte $15 \cdot 15 = 225$ (8 bit), $5$ bitte 10 bit.
- NOR(tüm bitler) = sıfır bayrağı; XOR(tüm bitler) = eşlik.
- PAL: programlanabilir AND, sabit OR. ROM: sabit AND (dekoder), programlanabilir OR.
- NEG ikiye tümleyen alır. Bir biti temizlemek için o biti 0, diğerleri 1 olan maskeyle AND yapılır (1. bit için FD).
- Tek çevrimli bilgisayarda en uzun yol saat periyodunu belirler; boru hattında en uzun aşama belirler.
- Beş aşama: IF, ID, OF, EX, WB. Aşamalar arası yazmaçlar zorunludur.
- Tehlikeler: yapısal, veri, kontrol (dallanma).
- Dallanma için seçenekler: boru hattını bekletmek, hep sıradaki komutu yüklemek, geçmişe ya da koda bakarak karar veren bir blok kullanmak.
- G/Ç aktarım yöntemleri: polling (işlemci sürekli durum yazmacını okur), interrupt (cihaz hazır olunca kesme), DMA (veri işlemciden geçmez).
- Paralel arayüz yazmaç seçimi: CS = 0 ise veri yolu yüksek empedans; RS1 RS0 = 00 Port A, 01 Port B, 10 kontrol, 11 durum.
- Asenkron seri çerçeve: boşta 1, start biti 0, önce en düşük anlamlı bit, isteğe bağlı eşlik, stop bitleri.
- Senkron haberleşmede saat hattı vardır, uzun bloklar gönderilebilir ve CRC gibi kontrol dizileri kullanılır.
- Papatya zincirinde öncelik bağlantı sırasıdır; öncelik kodlayıcıda hem öncelik hem maskeleme yapılır.
- DMA: işlemci başlangıç adresi, hedef adres ve sayıyı yükler, BR/BG ile yolları bırakır, iş bitince kesme gelir.

## Detaylı Açıklamalar

- **Vize sorularından seçmeler.** Bayrak sorusunda $127 - (-1) = 128$ sonucu 8 bitlik ikiye tümleyen aralığının dışındadır; pozitiften negatife taşma olduğu için sonuç negatif görünür, sıfır bayrağı 0, taşma bayrağı 1'dir. Diğer şıkta sonuç aralık içinde kaldığı için taşma yoktur. <!-- BELİRSİZ: Bu sorunun ilk şıkkındaki sayılar altyazıda bozuk, ekranda görülmedi. --> Aritmetik öteleme sorusunda sağa öteleme sonucu $(1101\,1010)_2 = -38$ bulunur; sayı negatif kalır, taşma yoktur. Aynı sayı sola ötelenince işaret biti 0'a döner ve taşma oluşur. <!-- BELİRSİZ: Ötelenen sayının kendisi ekranda görülmedi. --> Komut formatı sorusunda yazmaç sayısı alan genişliğini, kalan bitler opcode genişliğini belirler. 1M×32 bloğu için $\frac{1\text{M} \cdot 32}{128\text{K} \cdot 16} = 16$ modül gerekir; ikişer modül yan yana konarak 32 bitlik veri yolu kurulur, böylece 8 satır blok oluşur ve 8 bloğu seçmek için 3'e 8 dekoder kullanılır (ekrandan, 00:15:00).
- **Ripple sayıcı ve LFSR soruları.** Her flip-flop'un $\overline{Q}$'su kendi $D$'sine bağlıdır (her kenarda toggle) ve FF0 dışındakilerin saati bir öncekinin $Q$ çıkışından gelir. Başlangıç $(Q_0, Q_1, Q_2, Q_3) = (0, 0, 1, 1)$ iken 3 saat sonra $(1, 0, 0, 1)$ olur (ekrandan, 00:30:00). LFSR'de $Q_A^+ = q_B \oplus q_D$, $Q_B^+ = q_A$, $Q_C^+ = q_B$, $Q_D^+ = q_C$'dir; $(0, 1, 0, 1)$ durumundan $(0, 0, 1, 0)$'a geçilir (ekrandan, 00:35:00). İki sonuç python ile doğrulandı.
- **Öteleme-toplama çarpıcısı.** B'nin en düşük anlamlı biti A'nın her bitiyle AND'lenir, sonuç P ile toplanır. Her saat darbesinde toplam P'ye yazılır, A bir sola, B bir sağa ötelenir. 15 × 15 için ara değerler: P = 0, 15, 45, 105, 225; A = 15, 30, 60, 120, 240; B = 15, 7, 3, 1, 0 (ekrandan, 00:45:00; python ile doğrulandı). Son adımdaki 240 bir daha kullanılmadığı için A'da korunması gereken en büyük değer 120'dir ve 7 bite sığar.
- **Tek çevrimli bilgisayarın frekans sınırı.** Slayttaki gecikmeler PC 0,2 ns, komut belleği 4 ns, yazmaç dosyası okuma 0,6 ns, MUX B 0,2 ns, fonksiyon birimi ya da veri belleği 4 ns, MUX D 0,2 ns, yazmaç dosyası yazma 0,6 ns'dir (ekrandan, 01:10:00). Toplam 9,8 ns, yani en fazla yaklaşık 102 MHz eder (ara adım eklendi, python ile hesaplandı). Bir komut yürürken bu blokların çoğu boşta bekler; boru hattı bu boşluğu değerlendirir.
- **Boru hattı tablosu.** K1 birinci çevrimde IF'te, ikinci çevrimde ID'de iken IF'e K2 alınır. Beşinci çevrimde beş aşamanın hepsi doludur ve her çevrimde bir komut tamamlanır (ekrandan, 01:15:00). Veri tehlikesi örneğinde ADD R1, R2, R3'ün sonucu R1'e yazılmadan SUB R2, R3, R1 işlenen getirirse R1'in eski değeri okunur (ekrandan, 01:25:00). Dallanmada önceden alınan komutlar çöpe gidebilir. Hoca x86 programlarında koşullu dallanmaların yaklaşık %75'inin "false" sonuç verdiğini, bu yüzden sıradaki komutları yüklemenin rastgele seçimden (%50) iyi olduğunu söyler. <!-- BELİRSİZ: Bu oran hocanın verdiği istatistiktir, kaynağı belirtilmedi. --> Çok çevrimli yapıda ara yazmaçlar, birleşik bellek, komut yazmacı ve durum makinesine benzeyen bir kontrol birimi gerekir.
- **G/Ç mimarisi ve klavye.** Bellek birimleri işlemciyle doğrudan uyumludur. G/Ç cihazları ise farklı elektriksel seviye, protokol ve hızdadır; arayüz bu farkları giderir ve kesme desteği sağlar. Klavyede mikro denetleyici satırları sırayla sürer, her satırda 16 sütunu çoklayıcıdan tek tek okur. Basılı tuş ilgili satır ve sütunu kısa devre eder; örneğin 2 numaralı satır sürülürken 11 numaralı sütunda 1 okunursa basılan tuş bulunur. Tarama, insanın tuşa basma süresi içinde yüzlerce kez tekrarlanır; tuş kodu PS/2, USB ya da Bluetooth üzerinden HID olarak gönderilir.
- **Paralel arayüz.** CS = 0 iken veri yolu yüksek empedanstadır. CS = 1 iken RS1 RS0 = 00 Port A, 01 Port B, 10 kontrol, 11 durum yazmacını seçer (ekrandan, 01:55:00). Port A yazmacı fiziksel uçlara bağlıdır: çıkış yönündeyken yazılan değer uçlarda görünür, giriş yönündeyken uçlardaki seviye yazmaca aktarılır.
- **Strobe ve el sıkışma.** Hedef başlatmalı aktarımda hedef strobe'u yükseltir, kaynak veriyi yola koyar, hedef strobe'un düşen kenarında veriyi örnekler. Kaynak başlatmalı aktarımda kaynak önce veriyi koyar, sonra strobe gönderir. İkisinde de karşı tarafın işi yapıp yapmadığı bilinmez. El sıkışmada request ve reply işaretleri vardır: hedef başlatmalıda hedef request'i yükseltir, kaynak veriyi koyup reply'ı yükseltir, hedef veriyi okuyup request'i düşürür, kaynak veriyi kaldırıp reply'ı düşürür. Her iki taraf verinin konduğunu ve okunduğunu bilir (ekrandan, 02:10:00).
- **Seri haberleşme.** Gönderici paralel veriyi sağa öteleyerek en düşük anlamlı bitten başlayarak yollar, alıcı aynı şekilde sağa öteleyerek toplar. Senkron haberleşmede TX, RX, saat ve toprak (4 tel), asenkron haberleşmede TX, RX ve toprak vardır. Asenkron haberleşmede iç saatler arasındaki küçük fark uzun dizilerde bit kaymasına yol açacağı için veri 5, 6, 7 ya da 8 bitlik paketlerle, start ve stop bitleriyle çerçevelenir; baud hızı, bit sayısı, eşlik ve stop biti sayısı önceden anlaşılır (ekrandan, 02:20:00). Senkron paket yapısında senkronizasyon dizisi, adres bilgisi, veri, CRC ve paket sonu (EOP) bulunur.
- **Kesme ve DMA.** Polling'de işlemci durum yazmacındaki bayrağı maskeleyip okur, 1 olunca veri yazmacını okur (ekrandan, 02:30:00). Kesmede tek INTR ucu birden fazla kaynakla paylaşılır; işlemci onay (acknowledge) gönderir ve kaynaktan vektör adresi alır. Papatya zincirinde onay, en yüksek öncelikli cihazdan başlayıp kesmeyi isteyen cihaza kadar geçer. Öncelik kodlayıcıda kesme yazmacı ve maske yazmacı AND'lenir; çıkış $A_1 A_0$ diğer bitleri 0 olan 8 bitlik vektör adresini (VAD) oluşturur (ekrandan, 02:35:00). DMA kontrolcüsü programlandıktan sonra BR ile yolları ister, işlemci BG ile bırakır; kontrolcü her aktarımdan sonra adresleri artırıp sayacı günceller ve bitince kesme üretir (ekrandan, 02:40:00).

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
