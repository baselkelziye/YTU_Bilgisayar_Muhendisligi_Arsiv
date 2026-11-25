# Ders 4 Çalışma Özeti

## Genel Konular

- Hafıza hiyerarşisi
  - CPU içindeki yazmaçlar (register) en hızlı, kapasitesi en küçük ve birim maliyeti en yüksek hafıza birimleridir. Komutlara girdi sağlar ve işlem sonuçlarını tutar.
  - Ön bellek (cache) yazmaçlardan daha yavaş ama daha büyüktür. Bir kısmı CPU içinde, bir kısmı hemen dışındadır.
  - Bellek (ana bellek) günümüzde dinamik RAM mantığıyla kurulur.
  - İkincil hafıza birimleri (sabit disk, manyetik teyp, CD-ROM gibi) en büyük ve en yavaş seviyedir.
  - CPU'dan uzaklaştıkça hız düşer, erişim süresi artar, birim maliyet azalır. Hiyerarşi, CPU-yazmaç, ön bellek, bellek ve ikincil hafıza blokları olarak tahtada çizildi (ekrandan, 00:10:00).
- Yerellik (locality) ve ön belleğin çalışması
  - Uzamsal yerellik (spatial locality): `for` döngüsünde `x = array[i]` gibi ardışık erişimlerde bir verinin komşusuna yakında erişilme olasılığı yüksektir (ekrandan, 00:10:00).
  - Zamansal yerellik (temporal locality): döngüde `x = x + i` gibi aynı veriye farklı zamanlarda tekrar tekrar erişilir.
  - Bu yüzden bellekten tek bir veri değil, aranan adres ve çevresindeki blok ön belleğe taşınır. CPU önce ön belleğe bakar; veri yoksa bellekten yeni blok getirilir. Yer yoksa ya da yerleştirme kuralı gerektiriyorsa mevcut bloklardan biri çıkarılır.
  - Bellek ile ikincil hafıza arasında da benzer bir ilişki vardır: belleğe sığmayan programın sayfaları (page) gerektikçe belleğe getirilir, yer yoksa bir sayfa kaldırılır.
- Kalıcı (non-volatile) ve geçici (volatile) hafıza
  - ROM enerjisi kesilse de içeriğini korur; operasyon sırasında yalnız okunur. BIOS gibi açılış programları ROM tabanlıdır ve CPU'nun reset vektörünün gösterdiği adres alanında yer alır. Mikrodenetleyici programlamak aslında ROM'unu programlamaktır.
  - RAM enerji varken veriyi saklar, enerji kesilince kaybeder; operasyon sırasında hem okunur hem yazılır. Genel amaçlı bilgisayarda programlar RAM üzerinde çalışır.
- RAM ve ROM'un blok yapısı
  - RAM'in veri girişi ($n$ bit), adres ($m$ bit), write ve read uçları vardır; boyutu (kelime sayısı) $\times$ (kelime başına bit) olarak, yani $2^m \times n$ bit diye verilir (ekrandan, 00:25:00).
  - Örnek: 5 bitlik adres ve 8 bitlik veri, $32 \times 8$ bitlik RAM demektir. 32 göz için $\log_2 32 = 5$ adres ucu gerekir (ekrandan, 00:25:00).
  - İçeride $m$'den $2^m$'e bir dekoder bir satırı (Sel$_i$) seçer. Yazmada veri girişleri write ile kontrol edilen üç durumlu tamponlardan, okumada veri çıkışları read ile kontrol edilen üç durumlu tamponlardan geçer (ekrandan, 00:20:00).
  - Veri giriş ve çıkış uçları üç durumlu tamponlarla aynı fiziksel uçlarda birleştirilebilir.
  - ROM'da adres ($m$ bit), read ve veri çıkışı ($n$ bit) vardır. RAM ve ROM senkron (saatli) ya da asenkron (saatsiz) olabilir (ekrandan, 00:30:00). ROM'un içinde dekoder ve önceden programlanmış bir sigorta yapısı bulunur.
- ROM çeşitleri
  - Maskeli ROM: üretimde programlanır, değiştirilemez.
  - Bir kez programlanabilen ROM.
  - Elektriksel olarak programlanan, üzerindeki pencereden ultraviyole ışıkla silinen ROM'lar.
  - EEPROM: elektriksel olarak hem programlanır hem silinir. Programlama ayrı programlama uçları ve modu ile yapılır; operasyon modunda yazılamaz.
- SRAM ve DRAM
  - SRAM'in birim hücresi flip-flop'tur (latch); en az 6 transistör gerekir.
  - DRAM hücresi bir transistör ve bir kapasitörden oluşur. Kapasitörde yeterli yük lojik 1, yetersiz yük lojik 0 demektir (ekrandan, 01:50:00). Kaçak akımlar yüzünden yük azalır, bu yüzden periyodik tazeleme (refresh) gerekir. DRAM, SRAM'e göre çok daha yoğundur, büyük kapasite ve düşük maliyet sağlar.
- Hafıza tanımları (ekrandan, 00:50:00 ve 01:00:00)
  - Hafıza: depolama hücreleri ve bunlara bilgi aktaran devreler. Hafıza organizasyonu: verinin nasıl erişildiğine göre temel mimari yapı. RAM: erişim süresi seçilen hücreye bağlı olmayan hafıza. Adres: bir elemanı tanımlayan bit vektörü.
  - Bit, byte (8 bit), word (genelde 1, 2, 4, 8 byte), double word, quad word. Aksi belirtilmedikçe derste her hafıza gözü 1 byte kabul edilir.
- Harvard ve von Neumann mimarileri
  - Harvard: program ve veri hafızası ayrı veri, adres ve kontrol yolları kullanır; iki kontrolcü gerekir, güvenlik açısından avantajlıdır.
  - von Neumann: tüm hafıza ve G/Ç birimleri aynı yolları (bus) paylaşır.
  - Ön bellek yalnız veri için değil, komutlar için de vardır (program ön belleği).
- Ortak yol ve adres çözümleme
  - Ortak veri yolunda aynı anda iki cihaz veri çıkarırsa çakışma olur. Her cihaz tasarımda sabit bir adres aralığına yerleştirilir.
  - Adres çözümleme devresi adres ve kontrol yolundan gelen bilgiye göre yalnız ilgili cihazın chip select (CS) ucunu aktif eder. Seçilmeyen cihazların veri çıkışları yüksek empedanstadır.
  - CS = 0 iken işlem yoktur; CS = 1, R/$\overline{W}$ = 0 seçili kelimeye yazma; CS = 1, R/$\overline{W}$ = 1 seçili kelimeden okumadır (ekrandan, 01:20:00).
- Mikroişlemciye uygun hafıza arayüzü
  - 16 bitlik mimari (16 veri ucu, 20 adres ucu): $2^{20} = 1$M göz, 1 MB. Tek ya da çift adresten 8 bit, çift adresten 16 bit okuma tek çevrimde desteklenir (ekrandan, 01:05:00). Uygun arayüz $512\text{K} \times 16$: çift ve tek adresler için iki $512\text{K} \times 8$ blok; $A_0$ çift bloğu, ayrı bir seçim ucu (bus high enable) tek bloğu seçer.
  - 32 bitlik mimari (32 veri, 32 adres ucu): $2^{32}$ göz, 4 GB. Her göze tek tek, çift adreslerden 16 bit, 4'ün katı adreslerden 32 bit erişim (ekrandan, 01:10:00). Dört tane 8 bitlik blok ve her birinin kendi aktif 0 enable ucu ($E_0$–$E_3$) gerekir; arayüz $1\text{G} \times 32$ olur.
  - 8088 (8 veri, 20 adres ucu, 16 bitlik yazmaçlar): arayüz $1\text{M} \times 8$; 16 bitlik veri iki okumayla alınır.
- Hafızayı lojik fonksiyon (lookup table) olarak kullanmak: 10 adres ucu ve 16 bitlik çıkışı olan bir hafıza, 10 girişli 16 ayrı lojik fonksiyonu gerçekler. FPGA tasarımlarında bu kullanılır.
- Erişim süresi ve yazma süresi
  - Örnekte okuma (erişim) 65 ns, yazma 75 ns sürer; her biri 20 ns'lik dört saat darbesine (T1–T4) yayılır (ekrandan, 01:25:00).
  - Yazmada adres ve geçerli veri hatta stabil tutulur, memory enable verilir, R/W sıfıra çekilir. Okumada adres stabil tutulur, R/W bir kalır, geçerli veri T4'te örneklenir.
- Tek çevrim, çok çevrim ve boru hattı
  - Komutun alınması (fetch), çözülmesi (decode), operand getirme, yürütme ve geri yazma blokları vardır. Tek çevrimli tasarımda bir blok çalışırken diğerleri boşta bekler.
  - Boru hattında her blok aynı anda farklı bir komutun ilgili aşamasını işler. Dallanma komutları ve veri bağımlılıkları boru hattının verimini düşürür; dallanma tahmini ve bağımsız komutları öne alma bu kaybı azaltır.
- RAM hücresinden RAM entegresine
  - SRAM hücresi SR latch, select ucu, $B$ ve $\overline{B}$ girişleri ile modellenir. Yazmada S, R uçlarına 1, 0 gelir; okumada 0, 0 gelir ve değer korunur.
  - $2^n$ kelime $\times$ 1 bitlik RAM için $n$ adres hattını $2^n$ word select hattına çeviren bir dekoder (örnekte 4'ten 16'ya) ve birden çok entegrenin birleştirilmesine izin veren çıkıştaki üç durumlu tampon gerekir (ekrandan, 01:40:00).
  - Adres iki zamanda (önce satır, sonra sütun) gönderilirse $n$ adres ucuyla $2^n \times 2^n$ hücre seçilebilir. Adres yarı yarıya satır ve sütuna aynı anda verilirse kapasite yine $2^n$ olur.
- Kapasite ve veri yolu genişletme
  - $256\text{K} \times 8$, dört $64\text{K} \times 8$ RAM ile kurulur: 18 bitlik adresin düşük 16 biti dört entegreye ortak gider, en yüksek 2 biti (17, 16) bir 2'den 4'e dekoderle CS uçlarını seçer. Veri uçları ortaklanır (ekrandan, 01:45:00).
  - $64\text{K} \times 16$, iki $64\text{K} \times 8$ RAM ile kurulur: 16 adres ucu, R/W ve CS ikisine ortak gider; biri yüksek, biri düşük anlamlı 8 biti verir.
  - $256\text{K} \times 16$ için sekiz $64\text{K} \times 8$ entegre (4 satır, 2 sütun) gerekir.

## Hocanın Özellikle Vurguladığı Kısımlar

- Okuma ve yazma çevrimleri hep mikroişlemci açısından tanımlanır.
  - "Yazma" mikroişlemcinin hafızaya yazmasıdır. Geçerli veriyi hatta koyan mikroişlemcidir.
- Ortak yolda aynı anda yalnız bir cihaz konuşabilir.
  - Bunu adres çözümleme devresi ve CS ucu sağlar; seçilmeyen cihazlar yüksek empedansla hattan kopmuş gibi davranır. Hoca bunu "önemli bir nokta" diye belirtti.
- Hafıza arayüzü kurulurken mikroişlemcinin adres ucu sayısı, veri ucu sayısı ve bir saat çevriminde desteklediği okuma/yazma işlemleri birlikte dikkate alınmalıdır.
- Okuma ve yazma süreleri farklı olabilir; senkron tasarımda saat periyodu uzun olana (örnekte 75 ns) göre seçilir.
- Kapasite genişletmede entegreler aynı anda seçilmemeli (dekoder), veri yolu genişletmede ise aynı anda seçilmelidir (ortak CS).

## Kısa Tekrar Notları

- Hiyerarşi: yazmaç > ön bellek > bellek > ikincil hafıza. Hız ve birim maliyet aşağı doğru düşer, kapasite ve erişim süresi artar.
- Uzamsal yerellik: komşu veriye erişim. Zamansal yerellik: aynı veriye tekrar erişim.
- $m$ adres, $n$ veri ucu: $2^m \times n$ bit. $32 \times 8$ RAM: 5 adres ucu.
- ROM: kalıcı, yalnız okunur. RAM: geçici, okunur ve yazılır.
- SRAM: latch, en az 6 transistör. DRAM: 1 transistör + 1 kapasitör, tazeleme gerekir.
- Harvard: ayrı program ve veri yolları. von Neumann: ortak yol.
- CS = 0: işlem yok; R/$\overline{W}$ = 0: yazma; R/$\overline{W}$ = 1: okuma.
- 16 bit mimari, 20 adres: 1 MB, arayüz $512\text{K} \times 16$. 32 bit mimari: 4 GB, arayüz $1\text{G} \times 32$. 8088: $1\text{M} \times 8$.
- $256\text{K} \times 8 = 4 \times (64\text{K} \times 8)$ ve 2'den 4'e dekoder. $64\text{K} \times 16 = 2 \times (64\text{K} \times 8)$ ve ortak CS.
- Gerekli entegre sayısı = (kapasite oranı) $\times$ (veri genişliği oranı).

## Detaylı Açıklamalar

- **Ön bellek neden işe yarar?** Bellekten veri getirmek uzun sürer. Programlar komşu adreslere (dizi gezme) ve aynı değişkene (döngü sayacı, toplam) tekrar tekrar eriştiği için, aranan adres ve çevresi birlikte ön belleğe taşınır. Sonraki erişimler ön bellekte bulunursa ortalama erişim süresi kısalır. Bulunamazsa bellekten yeni blok getirilir ve ön bellekte bir yere yerleştirilir; boş yer olsa bile yerleştirme kuralına göre mevcut bir blok çıkarılabilir. Aynı ilişki bellek ile ikincil hafıza arasında sayfalar için kurulur.
- **Hız ve erişim süresi farkı:** Bir öğrenci sorusu üzerine hoca, hızı tek bir hafıza elemanının girdiye cevap verme süresi olarak, erişim süresini ise hiyerarşide arama, adres çözümleme gibi dış etkenleri de içeren süre olarak ayırdı. İleride ön bellekte bulma ve bulamama olasılıkları kullanılarak ortalama erişim süresi hesaplanacak.
- **RAM'de yazma ve okuma:** Yazmak için adres uçlarına hedef gözün adresi verilir, dekoder o satırı seçer, veri girişine yazılacak değer konur ve write işareti verilir; değer seçili satırdaki flip-flop'lara yazılır. Okumada aynı adres verilir; tüm satırların çıkışları ortak hatta bağlıdır ama yalnız seçili satır aktiftir, diğerleri yüksek empedans gösterir. Read işareti verilince değer üç durumlu tampondan veri çıkışına geçer. 8086'da read ve write iki ayrı aktif 0 uçtur ve aynı anda aktif olmaz; bazı mimarilerde tek bir R/$\overline{W}$ ucu vardır.
- **16 bitlik mimaride arayüz:** Hafıza $1\text{M} \times 8$ bağlanırsa 16 bitlik veri bir çevrimde okunamaz. $1\text{M} \times 16$ bağlanırsa 8 bitlik erişimde her satırın yarısı boşa gider. Doğru çözüm, toplam 1 MB'yi iki $512\text{K} \times 8$ bloğa bölmektir: çift adresler bir blokta, tek adresler diğerinde. $A_0$ adres çözümlemeye girmez; $A_0 = 0$ çift bloğu seçer, aktif 0 bir "bus high enable" ucu tek bloğu seçer. Çift adresten 16 bitte ikisi birden, tek adresten 8 bitte yalnız tek blok, çift adresten 8 bitte yalnız çift blok seçilir.
- **32 bitlik mimaride arayüz:** 4 GB dört tane 8 bit genişliğinde bloğa bölünür. Her bloğun kendi aktif 0 enable ucu vardır. Çift adresten 8 bitlik erişimde verilen adrese göre $E_0$ ya da $E_2$, 32 bitlik erişimde $E_0$–$E_3$'ün hepsi aktif olur ve dört bloğun aynı satırı birlikte okunur.
- **Okuma ve yazma çevrimi:** Slayttaki örnekte bir hafıza çevrimi her biri 20 ns olan T1–T4 darbelerinden oluşur. Yazma çevriminde mikroişlemci adresi koyar, adres çözümleme CS (memory enable) üretir, mikroişlemci veriyi hazırlar ve R/W'yi sıfıra çeker; adres ve veri yeterince uzun süre hatta stabil tutulur, çünkü karşı taraftan bir onay (handshaking) yoktur. Okuma çevriminde adres stabil tutulur, R/W bir kalır ve hafızanın çıkardığı geçerli veri T4'te örneklenir.
- **Boru hattı ve bağımlılıklar:** Tek çevrimli tasarımda bir komut fetch, decode, operand fetch, execute ve write back bloklarından sırayla geçer, diğer bloklar boşta bekler. Boru hattında birinci komut çözülürken ikinci komut getirilir ve bu böyle sürer; komutlar komut hafızasından bir kuyruğa toplu alınır. Dallanma komutunun ardından gelen komutlar dallanma gerçekleşirse çöpe gider; bu yüzden ya boru hattı durdurulur ya da dallanma tahmin edilir. Örneğin $A \leftarrow A + B$'nin ardından $A \leftarrow A/2$ gelirse ikinci komut birincinin sonucunu beklemek zorundadır; bu sırada bağımsız komutlar öne alınabilir.
- **Kapasite genişletme:** $256\text{K} \times 8$ için $256\text{K}/64\text{K} = 4$ entegre gerekir. 18 bitlik adresin düşük 16 biti her entegreye ortak gider; en yüksek 2 bit 2'den 4'e dekodere girer ve aynı anda yalnız bir entegrenin CS'sini aktif eder. Entegreler sırasıyla 0–65.535, 65.536–131.071, 131.072–196.607 ve 196.608–262.143 adreslerini tutar (ekrandan, 01:45:00). Tüm entegrelerin aynı numaralı veri uçları ortaklanır; aynı anda yalnız biri aktif olduğu için çakışma olmaz.
- **Veri yolu genişletme:** $64\text{K} \times 16$ için kapasite aynı, veri genişliği iki katı olduğundan iki entegre yan yana konur. 16 adres ucu ikisine ortak gider; biri verinin yüksek anlamlı 8 bitini, diğeri düşük anlamlı 8 bitini taşır. Aynı satır iki entegrede birlikte okunup yazılacağı için R/W ve CS işaretleri ortaktır.

<!-- BELİRSİZ: SRAM hücresindeki kapıların yerleşimi (01:36–01:39) altyazıdan anlatıldı; ilgili slaydın karesi yok, kapı bağlantıları kareden doğrulanamadı. -->

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
