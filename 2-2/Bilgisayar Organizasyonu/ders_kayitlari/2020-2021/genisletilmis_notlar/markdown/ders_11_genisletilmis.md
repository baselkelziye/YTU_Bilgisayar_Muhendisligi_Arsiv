# Ders 11 Genişletilmiş Notu: Pipeline, Giriş-Çıkış Arayüzleri, Seri Haberleşme, Kesme ve DMA, Önbelleğe Giriş ve Direct Mapped Cache

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Tek Çevrimli Bilgisayar Mimarisinin Tekrarı
- 2. Senkron ve Kombinasyonel Bloklar, Kritik Yol
- 3. Pipeline Mantığı
- 4. Mikro İşlemci, Mikro Denetleyici ve Giriş-Çıkış Birimleri
- 5. Arayüzler, Adres Çözümleme ve Yüksek Empedans
- 6. Programlanabilir Paralel Arayüz
- 7. Strobe ve Handshaking ile Veri Aktarımı
- 8. Seri Haberleşme
- 9. Veri Aktarım Yöntemleri: Polling, Kesme ve DMA
- 10. Önbelleğe Giriş: Yerellik ve Bellek Hiyerarşisi
- 11. Cache Eşleme Yöntemleri
- 12. Direct Mapped Cache
- 13. Örnek Sorular

## 1. Tek Çevrimli Bilgisayar Mimarisinin Tekrarı

Ders, merkezi işlem birimi tasarımında geçen hafta gelinen noktanın toparlanmasıyla başladı. Tasarım register file ile başlamıştı. Register file içindeki herhangi bir yazmacın değeri iki ayrı kanala (A ve B) çıkabilir; bunu sağlayan bir MUX yapısı vardır. Register file'ın D girişine ise function unit'ten ya da veri hafızasından gelen değer yazılabilir.

Function unit içinde aritmetik lojik birim (ALU) ve shifter bulunur. ALU, aritmetik birim ve lojik birim olarak ayrı ayrı tasarlanmıştı. Shifter, MUX'larla uygun bağlantılar kurularak oluşturulmuştu.

Sisteme veri hafızası da eklendi. Hafızayı kullanmak için bir adres ve bir veri ucu gerekir; bunlar register file'ın A ve B kanallarından üretilir. Hafıza eklenince bir kontrol ucu daha ortaya çıkar: MW (memory write). Bazen yazmaçtan hafızaya veri yazmak, bazen de hafızadan okuyup yazmaca aktarmak isteriz; ikinci durum için hafıza çıkışından gelen "data in" yolu kullanılır.

### 1.1 Kontrol kelimesi

Tüm bu kontrol uçları bir kontrol kelimesinde (control word) toplanır (ekrandan, 00:10:00):

- DA: register file'da sonucun yazılacağı yazmaç.
- AA: A kanalına çıkacak yazmaç.
- BA: B kanalına çıkacak yazmaç.
- MB: MUX B, B yolunda sabit değer mi yoksa register file değeri mi kullanılacak.
- FS: function unit'te (ALU ya da shifter) hangi işlemin yapılacağı.
- MD: MUX D, sonucun veri hafızasından mı function unit'ten mi geleceği.
- RW: sonuç register file'a yazılacak mı.
- MW: sonuç hafızaya yazılacak mı.
- PL, JB, BC: dallanma kontrolleri. PL, PC'nin farklı bir değerle yüklenip yüklenmeyeceğini; JB koşulsuz dallanmayı (jump); BC koşullu dallanmayı belirler.

### 1.2 Program sayacı ve dallanma

Ardışık akışta, yani dallanma yoksa, PC komut hafızasında bir sonraki komutu gösterecek şekilde uygun adımla artırılır. Uygun adım bir komutun hafızada kaç byte kapladığına bağlıdır. Örneğin 2 byte'lık komutlarda PC her komuttan sonra 2 artar.

Akış bir yerde kırılıyorsa iki durum vardır. Koşulsuz dallanmada PC'ye doğrudan yeni bir değer yazılır; şekilde A kanalından gelen değer PC'ye yüklenir. Koşullu dallanmada ise o anki PC değerine bir offset eklenir. Bu offset komutun içine gömülüdür; şekilde 6 bitlik bir değerdir ve işaret genişletilerek (sign extend) PC'ye eklenir. Offset ikiye tümleyen aritmetiğinde pozitif ya da negatif olabilir.

Branch control birimi PL, JB, BC kontrollerini ve function unit'in ürettiği V, C, N, Z bayraklarını girdi olarak alır. PC'nin artırılacağına, yeni değer yükleneceğine ya da offset ekleneceğine bu birim karar verir.

### 1.3 Komut ile kontrol kelimesi arasındaki fark

Kontrol kelimesi seyrek (sparse) bir gösterimdir. Komut ise kontrol kelimesinin sıkıştırılmış, daha üst seviyeli hâlidir. Örneğin function unit'te bir yazmacı sıfırlayan bir fonksiyon yoktur. Ama "yazmacı sıfırla" diye bir komut tanımlanabilir; bu komut arka planda A XOR A işlemini çalıştırır. Komuttan kontrol kelimesine geçmek için bir çözücüye (instruction decoder) ihtiyaç vardır.

Tek çevrimli bilgisayarda (single cycle computer) PC, komut hafızasında sıradaki komutu seçen bir adres seçicidir. Seçilen komut çözücüye girer, kontrol kelimesi üretilir ve komut bir çevrimde yürütülür. Komutta sabit (immediate) değer varsa bu değer MUX B üzerinden B yoluna ve function unit'e aktarılır.

## 2. Senkron ve Kombinasyonel Bloklar, Kritik Yol

Şekilde mavi işaretli bloklar (PC, register file, veri hafızası) senkron devrelerdir. İçlerinde yazmaçlar bulunur ve ortak bir saatin yükselen kenarında durum değiştirirler. Gri işaretli bloklar ise kombinasyonel devrelerdir.

Bir komut çözücüden geçtikten sonra kontrol uçları belirlenir ve kombinasyonel bloklarda değerler üretilir. Örneğin function unit içinde hem ALU hem shifter bir değer üretir, hangisinin seçileceği kontrol kelimesiyle belirlenir. Değerler register file'ın D girişine kadar hazırdır, ama başlangıçta büyük ihtimalle doğru değildir; çünkü A ve B hatları henüz oturmamıştır. Yollar oturup doğru değer D ucuna geldikten sonra saatin yükselen kenarıyla değer register file'a yazılır. Yani kombinasyonel bloklar değeri hazırlayıp senkron blokların girişine kadar getirir, senkron bloklar saat kenarını bekler.

> **Hocanın vurgusu:** ALU tasarımına dikkat edin. Hem verilen fonksiyon tablosundan tasarım yapma hem de verilmiş bir tasarımın hangi fonksiyonlara karşılık geldiğini bulma örnekleri çözüldü. Aritmetik birim tam toplayıcı ile kurulur; tablodan X, Y ve carry-in girişlerine bağlanacak fonksiyonlar bulunur. Function unit'in bir kontrol ucunun doğrudan carry-in'e bağlanması gibi bir kısıt varsa tasarım buna göre yapılır.

### 2.1 Kritik yol

Kritik yol, kullanılabilecek tüm komutlar içinde en uzun yolu kat etmesi gereken komutun yoludur. Örneğin hem register file'ı, hem MUX B'yi, hem function unit'i, hem de MUX D'yi kullanan bir komut. Bu en uzun süre $T$ ise senkron bloklar için ulaşılabilecek en yüksek saat frekansı:

$$f_{max} = \frac{1}{T}$$

Ekranda gösterilen şekilde bir komutun yolundaki blok gecikmeleri şöyle verilmiştir (ekrandan, 00:20:00): PC 0,2 ns, komut hafızası 4 ns, register file okuma 0,6 ns, MUX B 0,2 ns, function unit ya da veri hafızası 4 ns, MUX D 0,2 ns, register file yazma 0,6 ns. Bu değerlerin toplamı $0{,}2 + 4 + 0{,}6 + 0{,}2 + 4 + 0{,}2 + 0{,}6 = 9{,}8$ ns'dir (ara adım eklendi).

> **Ek bilgi (derste anlatılmadı):** 9,8 ns'lik bir kritik yol için $f_{max} = 1/9{,}8\text{ ns} \approx 102$ MHz olur. Hoca bu şekli gösterdi ama derste sayıları tek tek okumadı.

## 3. Pipeline Mantığı

Sonraki slaytlar çok çevrimli (multicycle) bilgisayar mimarisine aittir. Hoca bu kısmın geneline girmedi, yalnız pipeline (boru hattı) mantığına değindi.

### 3.1 Komut yürütmenin adımları

Bir komutun yürütülmesi şu adımlara bölünebilir:

- Instruction fetch (IF): sıradaki komutun program hafızasından işlemciye getirilmesi.
- Instruction decode: komutun çözülüp kontrol kelimesine dönüştürülmesi.
- Operand fetch (OF): işlenenlerin yazmaçlardan ya da veri hafızasından alınması.
- Execution (EX): komutun yürütülmesi.
- Write back (WB): sonucun yazmaca ya da hafızaya yazılması.

Kabaca 5 adımdır; bazı mikro işlemcilerde 4, bazılarında 6 adım olabilir. Tek çevrimli mimaride bu adımların hepsi aynı çevrimde art arda gerçekleşir. Bu yüzden function unit sonuç hesaplarken komut hafızası ve çözücü boşta bekler.

Bir komutu alt adımlara bölmek çok çevrimli mimaride mümkündür, tek çevrimli mimaride olmaz. Her adımdan sonra bir yazmaç eklenirse verinin kaybolması önlenir ve pipeline kurulur. Bir çevrimde IF bloğu yeni komutu çekip bir yazmaçta saklarken çözücü bir önceki komutu çözüp kontrol kelimesini bir yazmaçta saklar; OF bloğu iki adım önceki komutun işlenenlerini çeker; EX bloğu daha önceki bir komutu yürütür; WB bloğu en eski komutun sonucunu yazar. Bir komut yine 5 çevrimde biter, ama tüm bloklar aynı anda çalıştığı için birim zamanda biten komut sayısı (throughput) artar.

Alt çevrimlerin hepsi aynı saatle senkronize edilir. Saat periyodu en uzun alt adıma göre seçilir. Avantaj, boşta bekleyen blok kalmamasıdır.

### 3.2 Dört aşamalı örnek

Örnekte komut yürütme 4 alt bloğa ayrılmıştır: IF, OF, EX, WB. Burada instruction decode, büyük ihtimalle IF bloğunun içine yedirilmiştir. Zaman çizelgesi şöyledir (ekrandan, 00:25:00):

```text
çevrim     1    2    3    4    5    6    7
1. komut   IF   OF   EX   WB
2. komut        IF   OF   EX   WB
3. komut             IF   OF   EX   WB
4. komut                  IF   OF   EX   WB
```

1. çevrimde yalnız birinci komutun IF'si çalışır; OF, EX ve WB boştadır, çünkü onlara henüz girdi gelmemiştir. 2. çevrimde birinci komutun OF'si yapılırken boşalan IF ikinci komutu çekebilir. 3. çevrimde birinci komut EX'e geçer, ikinci komut OF'ye, üçüncü komut IF'ye girer. Komut sayısı yeterince fazlaysa öyle bir an gelir ki tüm bloklar aynı anda farklı komutların farklı adımlarını yürütür.

### 3.3 Sayısal örnek: 20 komut

Verilen: 20 komutluk bir dizi, koşullu ya da koşulsuz dallanma yok. Aşamalardan en uzunu 5 ns, bu yüzden alt çevrim saati 5 ns seçilmiş. Diğer aşamalar 5 ns'den kısa olabilir. Aşamaların toplam süresi 17 ns, WB 4 ns sürüyor. <!-- BELİRSİZ: IF, OF ve EX aşamalarının tek tek süreleri karelerde görünmüyor; altyazıdan yalnız toplamın 17 ns, en uzun aşamanın 5 ns ve WB'nin 4 ns olduğu anlaşılıyor. -->

Klasik (seri) yöntem: her komut IF'den girip WB'den çıktıktan sonra sıradaki komut alınır. Bir komut 17 ns sürer (ekrandan, 00:30:00):

$$20 \times 17 = 340 \text{ ns}$$

Pipeline: 1. komut 1. çevrimde IF'ye girer, 2. komut 2. çevrimde, ..., 20. komut 20. çevrimde IF'ye girer. 20. komutun bitmesi için 3 aşama daha gerekir:

$$20 + 3 = 23 \text{ çevrim}, \qquad 23 \times 5 = 115 \text{ ns}$$

Buradaki 3, aşama sayısı eksi 1'dir; 20 ise komut sayısıdır. Aynı 20 komut 8 aşamalı bir pipeline'da yürütülseydi 20. komut 20. çevrimde IF'ye girer ve 7 adım daha gerekirdi:

$$20 + (8 - 1) = 27 \text{ çevrim}$$

Python ile kontrol edildi: $n + k - 1$ formülü 4 aşama için 23, 8 aşama için 27 verir; $23 \times 5 = 115$, $20 \times 17 = 340$.

### 3.4 Pipeline'ı bozan durumlar

Bu hesap dallanma olmadığı ve komutların sırayla akabildiği varsayımına dayanır. Hoca sınıfa, ikinci komutun pipeline'a hemen alınamayacağı durumları sordu.

**Soru:** Birinci komutu pipeline'a aldıktan sonra ikincisini alamamamızın sebebi ne olabilir? **Cevap (bir öğrenci):** Önceki komut, sonraki komutun işleyeceği veriyi değiştiriyorsa ikinci komut hemen işlenemez. Hoca bunu doğruladı: örneğin birinci komut R1 ile R2'yi toplayıp R3'e yazıyor, ikinci komut R3'ü işlenen olarak kullanıyorsa, ikinci komutun IF'si birinci komutun write back'i bittikten sonra başlamalıdır; yani 5. çevrime ötelenir.

İkinci örnek dallanmadır. Günümüz işlemcilerinde komutlar tek tek çekilmek yerine toplu olarak çekilip bir prefetch kuyruğunda tutulur. Örneğin sıradaki 10 komut çekilmiş, ama 5. komut "A > 5 ise 100'e atla" gibi bir koşullu dallanma. 100. adresteki komutlar henüz çekilmemiştir. Koşul doğruysa kuyruktaki komutlar çöp olur ve dallanılan adresten itibaren komutların yeniden çekilmesi gerekir. Bu da dolaylı olarak pipeline'ı etkiler.

## 4. Mikro İşlemci, Mikro Denetleyici ve Giriş-Çıkış Birimleri

Tek çevrimli mimari ve pipeline ile işlemci tasarımı bölümü tamamlandı; sırada giriş-çıkış birimleri ve haberleşme vardı.

Bu derste "mikro işlemci" ile kabaca datapath'e (gerekirse komut çözücüyle birlikte) karşılık gelen CPU kastedilir. CPU tek başına çalışamaz. Çalışabilmesi için uygun buffer ve tekrarlayıcı entegrelere, saat darbesi üreten bir devreye, hafıza bloklarına ve giriş-çıkış birimlerine ihtiyaç vardır. Mikro denetleyici ise mikro işlemciyi, çevre birimlerini, giriş-çıkış birimlerini, hafızayı, program hafızasını ve saat üretecini tek entegrede barındırır; enerji verilince çalışabilir. Mikro işlemciye doğrudan enerji vermek yetmez.

Standart giriş-çıkış birimleri klavye, ekran, sabit disk gibi yapılardır.

### 4.1 Klavye

Klavyedeki tuşlar bir matris biçimindedir (ekrandan, 00:40:00). Klavyede bir mikro denetleyici bulunur. Bu mikro denetleyici bir dekodere 3 bitlik seçim değeri göndererek satırları sırayla aktif eder: 0, 1, ..., 7, sonra tekrar 0. Aynı anda yalnız bir satır lojik 1'dir. Bir tuşa basılınca o tuşun satırı ile sütunu kısa devre olur. Sütunlar bir MUX'a bağlıdır; mikro denetleyici MUX'un 4 bitlik seçim uçlarıyla sütunları sırayla MUX çıkışına aktarır ve çıkışta sıfırdan farklı bir değer var mı diye bakar.

Sıfırdan farklı bir değer görüldüğünde hangi satırın aktif olduğu ve hangi sütunun okunduğu bellidir. Mikro denetleyici bir look-up table ile bu satır-sütun çiftinin hangi ASCII karaktere karşılık geldiğini bulur. Satırlar sürülür (drive edilir, yani değer üretilir), sütunlar okunur. Tarama o kadar hızlıdır ki tuşa ne kadar kısa basılsa da basış algılanır.

Bu matris, kendi başına giriş-çıkış birimidir. Ama giriş-çıkış biriminin anlam kazanması için CPU'nun veri, adres ve kontrol yollarına bir arayüz (interface) üzerinden bağlanması gerekir. Giriş-çıkış birimi ile arayüz farklı şeylerdir: arayüz, birim ile mikro işlemcinin yolları arasındaki iletişimi sağlar.

### 4.2 Manyetik disk ve monitörler

Manyetik diskte veri halkalar hâlinde bloklar olarak tutulur. Halkalar (track) ve sektörler vardır. Manyetik okuma kafası içe ya da dışa doğru hareket ederek farklı sektördeki veri bloklarını okur.

CRT monitörde bir elektron tabancası bulunur. Yatay ve dikey elektromanyetik alanlarla gönderilen elektronun yönü değiştirilir ve ekran belirli bir sırayla taranır. Elektronların çarptığı her görüntü hücresi kırmızı, yeşil ve mavi olmak üzere üç alt pikselden oluşur. Yalnız kırmızı aktifse kırmızı görülür; üçünün birleşimiyle bütün renkler elde edilir. LCD ekranda bir arka plan aydınlatması vardır; likit kristallerin dizilimi ve polarizasyonuyla, kırmızı, yeşil ve mavi için ayrı bloklar kullanılarak piksel bazında renk oluşturulur.

## 5. Arayüzler, Adres Çözümleme ve Yüksek Empedans

CPU'nun bir veri yolu, bir adres yolu ve bir kontrol yolu vardır. Datapath şeklinde adres ve veri yolları ile MW gibi kontrol değerleri görülür. Daha fazla G/Ç birimi ve RAM, ROM gibi daha fazla hafıza bloğu kullanılırsa her biri için okuma ve yazma kontrol uçları eklenir ve kontrol uçlarının sayısı artar.

Ekrandaki şekilde CPU'ya veri, adres ve kontrol yolları üzerinden dört arayüz bağlıdır: klavye (giriş), CRT ekran (çıkış), yazıcı (çıkış) ve manyetik disk (giriş ve çıkış) (ekrandan, 00:50:00). Hoca, klavyedeki okun yönünün klavyeden CPU'ya doğru olması gerektiğini, fazla bir ok konduğunu belirtti.

- Klavye: tuşa basıldığı bilgisini ve tuş değerini arayüze bildirir. Arayüz değeri saklar ve CPU müsait olduğunda gönderir. CPU başka işler yürütürken arayüzleri sırayla kontrol edebilir (polling) ya da arayüz CPU'yu kesme ucu üzerinden tetikleyebilir. Kesmede CPU yürüttüğü komutu bitirir, isteğin önceliğine bakar ve uygunsa arayüzden okur. Klavye PS2 ya da USB ile bağlanır; anakart üzerindeki kontrol entegresi arayüze karşılık gelir.
- CRT ekran: CPU video hafızasını günceller; veri VGA portu üzerinden ekrana tek yönde gönderilir. VGA çıkışını süren entegre arayüzdür.
- Yazıcı: çift yönlü gösterilmiştir. Arayüz yazıcıya "müsait misin" diye sorar, müsaitse sıradaki karakteri gönderir. Bu kontrollü akış handshaking mantığıdır.
- Manyetik disk: arayüz üzerinden iki yönde veri aktarılır.

### 5.1 Adres çözümleme

Bir CPU'ya birden fazla arayüz ve hafıza bağlıdır, ama tek bir veri yolu vardır. Klavye ve manyetik disk aynı anda veri yoluna değer çıkarsa çakışma olur. Bunu önlemek için bir adres çözümleme devresi kullanılır. Her arayüzün önceden belirlenmiş bir adresi vardır; örneğin G/Ç uzayında klavye arayüzü 10H, CRT monitör 20H adresindedir. Yürütülen komut 10H adresiyle ilgiliyse adres çözümleme devresi yalnız klavye arayüzünün chip select (CS) ucuna 1, diğerlerinin CS ucuna 0 gönderir.

CS ucu 0 olan cihazın veri uçları yüksek empedans gösterir.

**Soru (hocadan sınıfa):** Empedans AC işaretler için akıma karşı gösterilen direncin ifadesidir. En yüksek direnç, sonsuz direnç fiziksel olarak ne zaman oluşur? **Cevap (bir öğrenci):** Açık devreyken. Hoca bunu doğruladı: CS ucuna 0 verildiğinde uçlarda görülen yüksek empedans, hatların devreden kopartılmış gibi davranmasıdır.

Böylece 10H örneğinde disk, yazıcı ve monitör arayüzlerinin veri yoluyla bağlantısı kopmuş gibi olur; hatta yalnız CPU ile klavye arayüzü kalır ve yalnız ikisi konuşur. Tek bir bus varsa CPU bir seferde tek bir cihazla konuşabilir. Bu yalnız G/Ç birimleri için değil, veri yoluna bağlı hafıza birimleri için de geçerlidir.

> **Hocanın vurgusu:** Yüksek empedansın anlamı budur: o anda veri yolunda CPU ve karşı tarafta tek bir cihaz kalır.

## 6. Programlanabilir Paralel Arayüz

Arayüzler farklı biçimlerde çalışabilir. Biri paralel veri aktarımı için kullanılan paralel giriş-çıkış arayüzüdür. Örneğin 7 bitlik bir kontrol değerini aynı anda çıkarmak gerekiyorsa, birlikte kontrol edilen paralel uçlar gerekir. Dış dünyaya doğrudan bağlantı sağlayan bu fiziksel uçlara port denir.

Paralel arayüzün iç yapısı (ekrandan, 01:00:00):

- CPU tarafında: çift yönlü veri yolu ve bus buffer'lar; chip select (CS); register select uçları RS1 ve RS0; I/O read (RD) ve I/O write (WR).
- İçeride: timing and control birimi ve bir iç bus.
- G/Ç tarafında: Port A yazmacı ve Port B yazmacı (G/Ç verisi), kontrol yazmacı (kontrol hatları), durum (status) yazmacı (durum hatları).

| CS | RS1 | RS0 | Seçilen yazmaç |
|----|-----|-----|----------------|
| 0 | x | x | Hiçbiri: veri yolu yüksek empedansta |
| 1 | 0 | 0 | Port A yazmacı |
| 1 | 0 | 1 | Port B yazmacı |
| 1 | 1 | 0 | Kontrol yazmacı |
| 1 | 1 | 1 | Durum yazmacı |

Veri yolu, CPU'dan arayüze ya da portlardan CPU'ya veri aktarırken kullanılan çift yönlü yoldur.

> **Hocanın vurgusu:** Bu arayüzün yalnız iki adres ucu vardır. Hafıza birimlerinde (1K, 2K'lık) 10-12 adres ucu bulunur. G/Ç birimleri CPU'nun adres uzayında 1-4 byte gibi küçük alanlar, hafıza birimleri 1K, 2K gibi büyük alanlar kaplar.

### 6.1 Portların yönünü ayarlama ve LED örneği

Cihazı kullanmadan önce kontrol yazmacı üzerinden Port A ve Port B'nin giriş mi çıkış mı olacağı belirlenir. CPU'nun veri yolundan gönderdiği değer arayüzün veri uçlarından alınıp kontrol yazmacına aktarılır. Her arayüzün kendi veri sayfası (data sheet) vardır ve kontrol yazmacının her bitinin bir görevi tanımlıdır.

Hocanın varsayımsal örneğinde kontrol yazmacının 0. biti Port A'nın, 1. biti Port B'nin yönünü belirler. İki port da çıkış olarak ayarlanır ve portlara toplam 16 LED bağlanır (her porta 8). Sonra adres uçlarına 00 verilip veri gönderilince değer Port A uçlarında görünür. LED'lerin biri yanık biri sönük olsun isteniyorsa Port A'ya ve Port B'ye 55H yazmak yeter:

$$55H = 0101\,0101_2$$

> **Ders sonrası not:** Hoca önce 0. bit için "0 yazınca giriş, 1 yazınca çıkış", 1. bit için "1 yazınca giriş, 0 yazınca çıkış" dedi, ardından iki portu çıkış yapmak için iki bite de 0 yazılması gerektiğini söyledi. Bu üç ifade birbiriyle tutarlı değildir. Örnek varsayımsaldır; gerçek bir cihazda bitlerin anlamı o cihazın veri sayfasından alınır.

### 6.2 Durum yazmacı ve polling

Klavye örneğinde tuşa basılma durumu bir kontrol ucu üzerinden durum yazmacına aktarılabilir. Senaryoda durum yazmacının 0. biti klavyenin "veri hazır" bitine bağlıdır: 0 ise veri hazır değil, 1 ise hazır. Tuşa basıldığı anda bu bit otomatik olarak 1 olur.

CPU, arayüzün adresine bir giriş-çıkış komutu yürütür ve adres uçlarına 11 vererek durum yazmacını veri yoluna çıkarır. Okuduğu değerin 0. bitine bakar. Bit 0 ise tekrar okur; bit 1 olana kadar bu döngü sürer. Bit 1 olunca klavyenin bağlı olduğu porttan basılan tuş değerini okur.

Bu arayüz genel programlanabilir bir arayüzdür; hem giriş hem çıkış birimleri için kullanılır. CPU'nun arayüze yazması (ör. kontrol yazmacı) ve arayüzden okuması (ör. durum ve port yazmaçları) gerekir; bu yüzden okuma ve yazma için iki kontrol ucu bulunur. Bazı arayüzlerde bu iki uç tek bir $R/\overline{W}$ ucunda birleşir: uç 1 ise okuma, 0 ise yazma komutu anlamına gelir.

### 6.3 Arayüzün adres uzayındaki yeri

Arayüzün yalnız 2 adres ucu olması, CPU adres uzayındaki adresinin 2 bit olduğu anlamına gelmez. CPU'nun adres yolu kaç bitse arayüzün adresi de o genişliktedir. Örneğin 16 bitlik bir adres yolunda CPU'dan çıkan adresin düşük anlamlı 2 biti arayüzün hangi yazmacının seçileceğini belirler. Kalan 14 yüksek anlamlı bit doğrudan adres çözümleme devresine girer. Bu 14 bit, cihaza ayrılan değere eşitse cihaz aktif olur; son 2 bit hangi değeri alırsa alsın cihaz seçilir ve bu 2 bit içerideki yazmacı belirler.

## 7. Strobe ve Handshaking ile Veri Aktarımı

Cihazlar arasındaki paralel veri aktarımında, aktarımı hangi tarafın başlattığına göre farklı yöntemler vardır.

### 7.1 Strobe ile aktarım

Hedefin başlattığı aktarım (ekrandan, 01:10:00): veri kaynakta (source unit) üretilir ve hedefe (destination unit) aktarılacaktır. İki birim arasında tek yönlü bir veri yolu ve strobe denen bir kontrol işareti vardır. Hedef, strobe işaretini göndererek aktarımı başlatır. Strobe'un yükselen kenarıyla kaynak verisini veri yoluna çıkarır; hedef veriyi aldıktan sonra strobe düşer ve kaynak veriyi hattan kaldırır. Sorun şudur: hedef, kaynağın verisinin hazır olup olmadığını kontrol etmez. Kaynakta önceki adımdan kalmış eski bir veri ya da rastgele bir değer varsa hedef bunu okumak zorunda kalır.

Kaynağın başlattığı aktarım: klavye örneğinde tuşa basma hareketi strobe olarak, tuş değeri ise veri yoluna konan değer olarak düşünülebilir. Kaynak önce veriyi veri yoluna koyar, sonra strobe gönderir, işlem bitince veriyi kaldırır. Hedef müsaitse strobe'un yükselen kenarından belirli bir süre sonra veri hatlarını örnekleyip veriyi içeri kopyalar. Sorun şudur: hedef o sırada başka bir işle meşgul olabilir; verinin alındığı garanti değildir.

Bu iki yöntem tek kontrol uçlu haberleşmedir.

### 7.2 Handshaking ile aktarım

Handshaking (el sıkışma) yönteminde her iki tarafın da bir kontrol ucu vardır: request ve reply.

Hedefin başlattığı aktarım (ekrandan, 01:15:00): hedef "verin hazırsa gönder" anlamında request gönderir. Kaynak müsaitse önce veriyi veri yoluna koyar, sonra reply'ı 1 yaparak "veriyi koydum, alabilirsin" der. Hedef reply'ı aldıktan sonra belirli bir aralıkta veri uçlarını örnekler ve request'i düşürür. Request düşünce kaynak reply'ı sonlandırır ve veriyi hattan kaldırır.

Kaynağın başlattığı aktarım: klavyede tuşa basıldı; kaynak request gönderir ve veriyi yola koyar. Hedef müsaitse reply gönderir ve hemen veri yolunu örnekler. Kaynak, hedefin veriyi örneklediğini varsayarak request'i kaldırır; ardından hedef de reply'ı kaldırır ve döngü tekrarlanabilir hâle gelir.

Hoca, bu örneklerden hangisinin klavyeye, hangisinin monitöre uygun olduğunu düşünerek örneklerin genişletilebileceğini söyledi.

### 7.3 Tuş basışının algılanması

**Soru:** Klavyede strobe gönderilince tuşa basıldığını anlıyoruz. Tuşu basılı tutunca karakter tekrar tekrar yazılıyor. Parmak kaldırılınca ayrı bir strobe mu gönderiliyor? **Cevap:** Anlatılan örnekte tetikleme yükselen kenarladır. Tuş okuması üç biçimde yapılabilir. Yükselen kenarda: basıldığı an algılanır. Düşen kenarda: basarken bir şey olmaz, parmak çekilince algılanır. Bu ikisi anlık ve tekildir; tuşa uzun basılsa bile tek basış algılanır. Üçüncüsü seviye kontrolüdür: program bir döngüde ucun 1 olup olmadığına bakar; döngü başa dönüp tuş hâlâ 1 ise ikinci basış sayılır. Böylece basış sayısı kontrol frekansına bağlı olur. Kontrol frekansı yavaşlatılırsa iki karakter arasındaki süre uzar; örneğin bir güvenlik tuş takımında uzun basma bu şekilde algılanabilir. İyi yapılmazsa kullanıcı tek bastığını sanırken algoritma ucu 3-4 kez kontrol edip aynı karakteri 3 kez yazabilir; bu ergonomik değildir.

Basılı olduğu anı, basılı kaldığı süreyi ya da bırakıldığı anı ayırt eden ve kaç kez basıldığını tutan, klavyedeki mikro denetleyicidir. Mikro denetleyicinin arayüzle ayrı bir bağlantısı vardır; tuş basışı doğrudan değil, bir dönüşümden geçtikten sonra strobe işareti olarak arayüze gönderilir.

## 8. Seri Haberleşme

Paralel arayüzler bir anda 8 uçtan veri çıkaran ya da okuyan arayüzlerdir. Bunun dışında seri haberleşme arayüzleri vardır.

### 8.1 Asenkron seri haberleşme

İki seri haberleşme modülü düşünelim; biri birinci, diğeri ikinci mikro işlemciye bağlıdır. Modüller arasında iki veri hattı vardır: biri gönderme (transmit), diğeri alma (receive) için. Teorik olarak üçüncü bir bağlantı da ortak ground (ortak referans) ucudur.

İki taraf önceden şunlarda anlaşmıştır: bit hızı, veri biti sayısı, başlama ve bitiş bitlerinin türü ve sayısı. Örneğin "115200 hızında, 8 veri biti, 2 stop biti".

> **Ders sonrası not:** Altyazıda hız "112.500" olarak geçiyor; yaygın standart hız büyük olasılıkla kastedilen 115200 baud'dur.

Gönderim adımları:

- Hat boştayken lojik 1'dedir.
- Gönderen hattı bir bit süresi boyunca 0'a çeker: start biti.
- Veri bitleri en düşük anlamlı bitten (D0) başlayarak tek tel üzerinden tek tek gönderilir. Gönderen, paralel olarak tuttuğu veriyi serileştirmek için sağa ötelemeli bir yazmaç gibi davranır; sağa öteleme ucundan çıkan bit hatta verilir.
- Alıcı, gelen her biti yazmacın en yüksek anlamlı ucuna koyup önceki bitleri bir kaydırır. 8 bit sonunda LSB'den itibaren gönderilen 8 bitlik veri yazmaçta doğru sırada oluşur.
- Son bitten sonra hat, stop bitleri için boşta seviyesinde (lojik 1) anlaşılan süre kadar tutulur; örneğin 2 stop biti için iki bit süresi.

> **Ders sonrası not:** Hoca alıcının "sola ötelemeli" bir yazmaç kullandığını söyledi, ama anlattığı işlem (yeni biti en yüksek anlamlı uca koyup önceki bitleri sağa kaydırmak) sağa ötelemedir. LSB önce gönderildiğinde alıcı tarafta seri girişi MSB ucunda olan sağa ötelemeli bir yazmaç kullanılır.

Ekrandaki çerçevede start bitinden sonra karakter bitleri 1, 1, 0, 0, 0, 1, 0, 1 sırasıyla gelir ve hat stop bitleri için 1'e döner (ekrandan, 01:25:00).

Buna asenkron denmesinin sebebi iki terminalin ortak bir saate sahip olmamasıdır. Her taraf farklı kristal ve farklı saat frekansı kullanabilir. Frekanslar arasında küçük bir fark olsa bile, örneğin 700. bitten itibaren alıcının örnekleme anı bir sonraki bite kayabilir ve veri çöp olur. Bu yüzden asenkron haberleşme küçük çerçevelerle (5, 6, 7 ya da 8 bit) yapılır; veri bir start biti ve bir ya da iki stop bitiyle çerçevelenir.

### 8.2 Senkron seri haberleşme

Senkron haberleşmede bağlantılar ortak ground, veri alma, veri gönderme ve ek olarak ortak bir saat ucudur. Ortak saat sayesinde daha büyük veri paketleri gönderilebilir, ama paketlerin çerçevesi daha kalabalıktır. Örneğin büyük bir veri bloğunun başına ve sonuna 2-3 senkronizasyon byte'ı konabilir. Ayrıca uzak bir terminale gönderilen lojik 1 elektriksel bir girişimle bozulup lojik 0 olarak algılanabileceği için bir kontrol bit dizisi eklenir; alıcı örneğin CRC kontrolüyle hata olup olmadığını ve hangi bit civarında olduğunu tespit edebilir.

> **Hocanın vurgusu:** Asenkron haberleşme tarafını net bilmek yeterlidir; senkron tarafın üzerinde fazla durulmadı.

Ekrandaki bir başka şekilde bir mikro denetleyici, bir arayüz ve bir klavye vardır. Klavye ile arayüz arasındaki haberleşme ortak saatli bir senkron seri haberleşmedir.

### 8.3 USB ve Manchester kodlama

Günümüzde yaygın bir başka G/Ç yapısı USB'dir. Cihazlar hub'lar üzerinden ağaç yapısında bağlanır: bilgisayardaki root hub'a monitör ve yazıcı, monitörün hub'ına klavye ve başka bir hub, klavyenin hub'ına fare ve joystick bağlanabilir (ekrandan, 01:30:00). Hoca bir kontrolcünün hub'larla genişletilerek 128 cihaza kadar yönetebildiğini söyledi.

> **Ders sonrası not:** USB'de bir host kontrolcüsü büyük olasılıkla en fazla 127 cihaz adresleyebilir (7 bitlik adresin 0 değeri ayrılmıştır); altyazıda 128 geçiyor.

Seri aktarımda bitleri yalnız seviyeyle (1 için lojik 1) göndermek, özellikle uzak mesafede girişim yüzünden sorun çıkarabilir. Bunun yerine seviye geçişleri kullanılabilir: bitler 0'dan 1'e ya da 1'den 0'a geçiş olarak tanımlanır. Bu Manchester kodlama olarak adlandırılır.

## 9. Veri Aktarım Yöntemleri: Polling, Kesme ve DMA

G/Ç birimleri ile hafıza arasında üç farklı veri aktarım yöntemi vardır.

### 9.1 Polling

G/Ç cihazı ile arayüz arasında iki yönlü handshaking vardır. Cihazda veri üretilince otomatik olarak arayüzün veri yazmacına aktarılır ve durum yazmacındaki ilgili bayrak set edilir. Arayüz ile CPU arasında ise böyle adanmış bir handshaking pek mümkün değildir, çünkü CPU çok sayıda arayüzle muhataptır.

CPU polling ile şöyle okur: durum yazmacını okur (tek bir bit okuyamaz, 8 ya da 16 bitlik yazmacın tamamını okur); okuduğu değeri maskeleyip yalnız ilgili bayrağa bakar. Bayrak 0 ise tekrar okur. Bayrak, cihazda veri üretilip arayüze aktarımı tamamlanınca 1 olur. Bayrak 1 olunca CPU veri yazmacını okur. İşlem tek byte ile bitmiyorsa ikinci, üçüncü byte için başa dönülür; aktarım tamamlanınca program sonlanır.

Polling'in uygulaması kolaydır, ama CPU'yu yorar ve aktif beklemeye sebep olur. Örneğin klavyeden yazılan bir yazının kelime işlemciye aktarılması gerekirken CPU'nun ekranı sürmek, kelime işlemciyi çalıştırmak, fareyi kontrol etmek gibi başka işleri de vardır. Adanmış bir durum yoksa polling anlamlı değildir; bu durumlarda kesme tabanlı aktarım kullanılır.

### 9.2 Kesme tabanlı aktarım

CPU'da bir kesme istek ucu ve bir kesme acknowledge ucu vardır; çevre birimi ile two-way handshaking yapılır. Çevre birimi kesme isteği gönderir. CPU o sırada bir komutun ortasındaysa onu bitirir ve acknowledge gönderir. Ardından çevre birimi, PC'ye yüklenecek bir vektör numarası ya da adres değeri gönderir. Bu adres, o kesmeye ait alt programın adresidir; o cihazın kesme alt programı önceden bu adrese yerleştirilmiştir ve CPU oraya dallanır.

### 9.3 Daisy chain

Birden fazla cihaz kesme ile çalışacaksa cihazlar daisy chain biçiminde bağlanabilir. Cihazların kesme istekleri bir OR kapısıyla birleştirilip CPU'nun kesme istek ucuna bağlanır. CPU'nun veri yolu tüm cihazlara bağlıdır.

Örneğin 1 numaralı cihaz kesme isteği üretirse OR kapısından geçen isteği CPU algılar, ama hangi cihazdan geldiğini bilmez. Komutunu bitirip acknowledge gönderir. Acknowledge önce zincirdeki ilk cihazın PI (priority input) ucuna gelir. Bu cihaz kesme istememişse acknowledge'ı PO (priority output) ucundan sonrakine iletir. Sıradaki cihaz isteği üreten cihaz olduğu için vektör adresini veri yoluna çıkarır; CPU bu cihazın kesme alt programına dallanır.

Aynı anda 0 ve 1 numaralı cihazlardan istek gelirse acknowledge önce 0 numaralı cihaza ulaştığı için önce onun isteği karşılanır. Yani daisy chain'de öncelik bağlantı sırasıyla belirlenir.

### 9.4 Öncelik kodlayıcı ile kesme

Diğer yaklaşım bir öncelik kodlayıcı (priority encoder) kullanmaktır (ekrandan, 01:40:00). Şekilde 4 bitlik bir kesme yazmacı (interrupt register) ve 4 bitlik bir maske yazmacı (mask register) vardır. Her kesme biti ilgili maske bitiyle AND'lenip kodlayıcının D3-D0 girişlerine gider. En yüksek öncelikli cihaz kodlayıcının en yüksek anlamlı girişine bağlanır (3 en yüksek, 0 en düşük öncelik). Kodlayıcı, en yüksek anlamlı uçtan başlayarak 1 gördüğü ilk girişin numarasını A1 A0 çıkışında ikili olarak üretir. Bu çıkış sıfırlarla tamamlanarak vektör adresi (VAD) olarak kullanılır ve CPU'dan gelen interrupt acknowledge ile veri yoluna verilir. Kodlayıcının V çıkışı CPU'ya kesme isteği olarak gider.

Bir kesme kaynağı 0 ile maskelenirse o kaynaktan istek gelse bile kodlayıcıya ulaşmaz. Böylece bazı kesmeler açık, bazıları kapalı tutulabilir.

### 9.5 Doğrudan hafıza erişimi (DMA)

Polling ve kesme yöntemlerinde, örneğin klavyeden basılan tuşlar hafızanın bir bölgesine aktarılacaksa veri önce cihazdan CPU'ya, sonra CPU'dan hafızaya olmak üzere iki kez taşınır. DMA (Direct Memory Access) yönteminde bir DMA kontrolcüsü kullanılır.

CPU, DMA kontrolcüsünü bir çevre birimiyle konuşuyormuş gibi RD, WR, adres ve veri uçları üzerinden programlar: verinin okunacağı G/Ç cihazının adresi, yazılacağı hafıza başlangıç adresi ve aktarılacak byte sayısı. Sonra CPU kendini bekleme konumuna alır ve DMA kontrolcüsü aktif olur.

CPU tarafında DMA için iki kontrol ucu vardır: bus request (BR) ve bus granted (BG). BG = 1 olduğunda CPU'nun adres yolu (AB), veri yolu (DB), RD ve WR uçları yüksek empedansa (devre dışı) geçer (ekrandan, 01:45:00).

Genel yapı ve örnek akış:

- Sistemde CPU, DMA kontrolcüsü, adres çözümleyici, hafıza ve G/Ç cihazı vardır. Amaç, klavyeden basılan tuşların kelime işlemcisinin kullanabilmesi için hafızada peş peşe saklanmasıdır.
- CPU kontrolcüyü programlar: başlangıç G/Ç adresi 100, başlangıç hafıza adresi 200, toplam 20 byte.
- Kontrolcü bus request gönderir.
- CPU yarıda bir komutu varsa bitirir ve bus granted ile yol kontrolünü kontrolcüye bırakır; adres, veri ve kontrol uçları yüksek empedansa geçer.
- Kontrolcü adres ve veri yollarına değer çıkarır, G/Ç cihazını ve hafızayı (yazma yönünde) aktif eder. G/Ç cihazıyla two-way handshaking yaparak verinin hazır olup olmadığını kontrol eder ve veriyi hafızaya yazdırır. Bunu kalan $N-1$ veri için tekrarlar.
- 20 byte bitince CPU hold konumunda olduğu için kontrolcü bir kesme isteğiyle CPU'yu uyandırır ve CPU sonraki işlere devam eder.

DMA'da veri CPU'ya uğramadan G/Ç birimi ile hafıza arasında, iki yönde de aktarılabilir.

## 10. Önbelleğe Giriş: Yerellik ve Bellek Hiyerarşisi

Aradan sonra önbellek (cache) konusuna geçildi: cache nedir, hafıza hiyerarşisinde nerede durur, performansı neden ve nasıl artırır, program yazarken cache'i dikkate almak ne kazandırır.

### 10.1 Yerellik

Yerellik (locality), programlarda aynı değişkenin ya da bir değişkenin civarındaki değerlerin sıklıkla kullanılmasına dayanır. İki türü vardır:

- Spatial locality (uzamsal yerellik): $t$ anında bir veriye erişiliyorsa $t+1$ anında onun komşusu olan bir veriye erişme ihtimali yüksektir. Örneğin bir döngüde dizinin 0. elemanına erişildiyse sonraki döngüde 1. elemana erişilir. Dizi ve matris işlemleri buna örnektir.
- Temporal locality (zamansal yerellik): bir hafıza bölgesine erişildiyse bir süre sonra aynı bölgeye yeniden erişme ihtimali yüksektir. Örneğin recursive bir fonksiyon, sürekli güncellenen bir döngü değişkeni ya da her döngüde daha hassas hesaplanan bir sayı (ör. $\pi$).

> **Hocanın vurgusu:** Bu iki kavramı tanım olarak birbirinden ayırabilmek önemlidir. Cache yapısının ortaya çıkmasının sebebi yerelliktir.

### 10.2 Bellek hiyerarşisi

Programlar ana hafızada (memory) çalışır. Ama tüm programlar hafızaya sığmayabilir ya da aynı anda birden fazla program çalışıyordur. Bu yüzden ikinci bir hafıza birimi olan disk vardır. Diskteki büyük program blokları görece küçük bloklar hâlinde hafızaya taşınır; diskteki bir bloğun hafızada hangi bloka karşılık geleceğinin belirlenmesi sanal bellek (virtual memory) konusudur ve dönemin son haftasında işlenecektir.

CPU ile hafıza arasında ara hafıza blokları olmasaydı, bir dizide sıradaki gözlere ya da aynı göze tekrar tekrar erişilen durumlarda CPU her seferinde hafızaya gidip değeri okuyacak, işlemi yapıp geri yazacaktı. Ana hafıza diskten küçük ama diğer bütün seviyelerden büyüktür; hızı ise CPU içindeki yazmaçlardan ve cache'lerden düşüktür. Cache'ler yazmaçlardan büyük, ama görece küçük ve hızlıdır. Farklı seviyeler vardır: CPU'nun içinde ve hemen önünde L1, L2, günümüzde L3.

Cache'in amacı, işlenecek veriyi doğrudan hafızadan almak yerine aradaki daha hızlı seviyelerden almaktır. Sorun, bu seviyelerin kapasitesinin düşük olması ve aranan her verinin orada bulunamamasıdır. Süreç şöyledir: veri L1'de var mı? Yok. L2'de var mı? Yok. O zaman hafızadan okunur, L2'ye, oradan küçük bir blok L1'e aktarılır. Spatial ve temporal yerellik sayesinde sonraki aranan verinin L1'de olma ihtimali artık yüksektir. Veri L1'de yok ama L2'de varsa, veri ve çevresindeki blok L1'e aktarılır.

Hiyerarşi işlemciden uzaklaştıkça şöyle sıralanır: yazmaçlar, L1, L2, L3 cache, ana hafıza, ikinci hafıza birimleri (disk) (ekrandan, 02:20:00). İşlemciye yaklaştıkça erişim hızı ve birim kapasite başına üretim maliyeti artar, kapasite azalır. Her şeyin cache'te tutulamamasının sebebi maliyettir; performans ve maliyet arasında bir denge (trade-off) kurulur.

Moore yasasına göre zamanla işlemcilerin işlem gücü katlanarak artarken hafıza aynı oranda gelişemez; işlemci ile hafıza arasındaki fark açılır ve performansı artıran iyileştirmelere ihtiyaç doğar.

### 10.3 Cache tasarımının soruları

- Aranan verinin cache'te olup olmadığı nasıl anlaşılır, arama nasıl yapılır?
- Erişim ne kadar hızlıdır, ortalama arama ve bulma süresi nedir?
- Hafızadan getirilen bir blok cache'in neresine konur?

Veri cache'te yoksa hafızaya gidilir; hafızada da olmayabilir, çünkü henüz diskten yüklenmemiş olabilir (son haftanın konusu). Hafızada bulunan veri ve çevresi cache'e konur.

## 11. Cache Eşleme Yöntemleri

Üç temel cache yapısı vardır (ekrandan, 02:30:00): fully associative cache, direct mapped cache ve set associative cache. Bu yapılar (mapping), ana hafızadaki bir bloğun cache'e nasıl aktarılacağını ve cache'ten hangi verinin kaldırılıp yerine yenisinin konacağını belirler.

- Direct mapped: hafızadaki her blok için cache'te hangi satıra gideceği önceden tanımlıdır. Örneğin X adresi her zaman 5 numaralı göze düşer. Yeni veri nereye yerleşecek, hangi veri kalkacak, baştan bellidir.
- Fully associative: doğrudan bir adres eşlemesi yoktur. Hafızadan getirilen veri için bir kural uygulanır: cache'e ilk konan veri kaldırılabilir (FIFO) ya da en uzun süredir kullanılmayan veri kaldırılabilir (least recently used, LRU). Blokların birbirine göre önceliği yoktur; hepsinin kaldırılma ihtimali eşittir.
- Set associative: ikisinin arasındadır. Hafızadaki bir bloğun cache'in hangi satırına gideceği bellidir, ama satır birbirinin yerine geçebilen birden fazla bloktan oluşur. Satırdaki hangi bloğun kalkacağı FIFO ya da LRU gibi kurallarla belirlenir.

> **Ders sonrası not:** Hoca "associative" özelliğini toplama işlemindeki "değişim özelliği" ile ilişkilendirdi. Matematikte associativity birleşme özelliğidir; değişme özelliği commutativity'dir. Cache bağlamında anlatılmak istenen, blokların birbirinin yerine geçebilmesidir.

Arama açısından: direct mapped'de verilen adres için bakılacak satır bellidir, ama o satıra bakmak gerekir, çünkü aynı satıra düşen başka bir adresin içeriği orada olabilir. Fully associative'de verinin nerede olduğu belli değildir, tüm bloklara tek tek bakılır. Set associative'de bakılacak satır bellidir, yalnız o satırdaki bloklara bakılır.

## 12. Direct Mapped Cache

Direct mapped cache'te her hafıza adresi için tek bir cache bloğu tanımlıdır. Adres belliyse cache'te karşılık geleceği satır bellidir ve satırda tek blok vardır. Cache boşsa veri doğrudan yerleşir; doluysa kaldırılacak veri de adresten bellidir. Veri aranırken adres, hafızadan cache'e eşlemeyi sağlayan aynı fonksiyondan geçirilir ve bakılacak satır bulunur.

Hoca başta bu eşlemenin birebir ve örten bir fonksiyon olduğunu söyledi, sonra düzeltti: farklı hafıza blokları aynı cache satırına düşebildiği için birebir ve örten değildir, deterministik bir fonksiyondur.

Hafızadan bir seferde bir satır genişliği (blok) kadar veri getirilip cache'e konur. Cache satırlardan oluşur; toplam kapasite satır sayısı çarpı blok genişliğidir.

### 12.1 Basit örnek: 16 byte hafıza, 4 byte cache

16 adreslik bir hafıza ve her satırı 1 byte olan 4 satırlık bir direct mapped cache (ekrandan, 02:35:00). Adres 0, 0. satıra; 1, 1. satıra; 2, 2. satıra; 3, 3. satıra; 4 tekrar 0. satıra düşer ve böyle devam eder:

| Cache satırı | Hafıza adresleri |
|---|---|
| 0 | 0, 4, 8, C |
| 1 | 1, 5, 9, D |
| 2 | 2, 6, A, E |
| 3 | 3, 7, B, F |

> **Ders sonrası not:** Altyazıda 2. satır için "2, 6, 10 ve 15" geçiyor; doğrusu 2, 6, 10 (A) ve 14 (E)'dir. 15 (F) 3. satıra düşer.

**Soru (hocadan sınıfa):** Hafıza adresi ile cache satır (indeks) adresi arasındaki ilişki nedir? **Cevap (bir öğrenci):** Adresin en düşük anlamlı 2 bitine bakmak yeterli. Hoca doğruladı: hafıza adresi 4 bit, cache indeksi 2 bittir ve indeks adresin düşük anlamlı 2 bitidir.

**Soru (hocadan sınıfa):** Cache'in bir satırında neler saklanmalı? **Cevap:** Önce verinin kendisi. Bir öğrenci, adresin hangisi olduğunu anlamak için indekste kullanılmayan yüksek anlamlı bitlerin de saklanması gerektiğini söyledi; hoca doğruladı. Örneğin bir adresle ilgili işlem yapılınca indeksi 00 olduğu için 0. satıra bakılır. Oradaki değerin gerçekten bu adrese ait olup olmadığını anlamak için hafızadan tekrar okuyup karşılaştırmak anlamsız olur. Bunun yerine adresin indeks dışındaki yüksek anlamlı bitleri cache'te ayrılan bir alana yazılır: tag alanı. Tag genişliği $4 - 2 = 2$ bittir (ekrandan, 02:40:00).

> **Ders sonrası not:** Hoca "4 adresiyle, yani 1000 adresiyle" dedi; 4'ün ikilik karşılığı 0100'dür, 1000 ise 8'dir. İkisinin de indeksi 00 olduğu için örneğin sonucu değişmez: ikisi de 0. satıra düşer (tag'leri sırasıyla 01 ve 10).

### 12.2 Valid biti ve adım adım erişim

Başlangıçta cache boştur ve satırlarda rastgele (don't care) değerler vardır.

- 1. erişim, adres 0 (0000): indeks 00. Veri cache'te yok; hafızadaki X değeri 0. satıra yazılır, tag alanına 00 yazılır.
- 2. erişim, adres 1 (0001): indeks 01. Bu satırda rastgele bir değer (Z) ve tesadüfen 00 tag'i bulunuyor olabilir. Tag tutuyor gibi görünse de veri geçersizdir.

Bu yüzden her satırda üçüncü bir alan gerekir: valid biti. Cache başlatıldığında tüm valid bitleri 0'dır. 2. erişimde tag tutsa da valid 0 olduğu için veri yok denir; hafızadan 1 adresinin içeriği (Y) getirilip satıra yazılır, tag 00 ve valid 1 yapılır. Satırın yapısı: valid biti, tag, veri.

- 3. erişim, adres 9 (1001): indeks 01, tag 10. 1. satıra bakılır; valid 1, ama satırdaki tag 00 ile 10 tutmaz. 9 adresinin içeriği satırda yoktur. Hafızadan 9 adresinin içeriği (T) getirilir, satırdaki Y'nin üzerine yazılır, tag 10 yapılır, valid 1 kalır.

Burada "referans etmek", o adresten okuma yapmak demektir.

Genel erişim algoritması:

- Satır sayısını ifade etmek için gereken bit sayısı bulunur: 4 satır için $\log_2 4 = 2$. Adresin düşük anlamlı 2 biti indekstir.
- İndeksle satıra gidilir, valid bitine bakılır.
- Valid ise adresin tag'i ile satırdaki tag karşılaştırılır. Tutuyorsa aranan veri cache'tedir (hit); veri hızlıca cache'ten okunur.
- Valid değilse ya da tag tutmuyorsa veri cache'te yoktur (miss); hafızadan okunur, satıra yazılır, tag ve valid güncellenir.

### 12.3 Bir satırda birden fazla byte

Bir satırda saklanan veri (blok boyutu) 1 byte'tan büyük olabilir. Her satır 2 byte ise 0 ve 1 adresleri aynı satıra, 2 ve 3 adresleri bir sonrakine, 4 ve 5 bir sonrakine, 6 ve 7 bir sonrakine düşer.

> **Ders sonrası not:** Altyazıda satır numaraları "0 ve 1 birinci satır, 2 ve 3 ikinci satır, 4 ve 5 ikinci satır, 6 ve 7 üçüncü satır" diye geçiyor. 0'dan numaralandırıldığında doğrusu: 0-1 adresleri 0. satır, 2-3 adresleri 1. satır, 4-5 adresleri 2. satır, 6-7 adresleri 3. satırdır; 8-9 yeniden 0. satıra düşer.

Hoca bunu ekranda yazdığı bir soruyla genişletti (bkz. Örnek Sorular, 1. soru): toplam kapasitesi 8 byte, blok genişliği 2 byte olan direct mapped cache, 16 byte'lık hafıza ile kullanılıyor; tag alanı kaç bittir?

Önemli olan satır sayısıdır: $8 / 2 = 4$ satır, indeks $\log_2 4 = 2$ bit. Blok 2 byte olduğu için hafızadan cache'e 2'şer byte'lık bloklar aktarılır. Hangi byte'ın kullanılacağı adresin en düşük anlamlı bitinde saklıdır: bu bit 0 ise bloğun düşük anlamlı byte'ı, 1 ise yüksek anlamlı byte'ı seçilir. $\log_2 2 = 1$ bit byte offset olarak kullanılır. Sonraki 2 bit indeks, kalan en yüksek anlamlı 1 bit tag olur. Satırda ayrıca 1 bitlik valid biti bulunur.

Bir öğrenci byte'ı seçen bitin en düşük bit değil de bir sonraki bit olabileceğini sordu. Hoca, blok 2 byte olduğu için bloğun hangi byte'ının seçileceğinin adresin en düşük anlamlı bitinde saklı olduğunu açıkladı.

Mikro işlemcilerde veri yolu genişlikleri byte değil word mertebesinde tanımlanır; örneğin 8086'da bir word 16 bit (2 byte)'tır. Bir satıra birden fazla word konabiliyorsa hafıza adresi şu alanlara bölünür:

```text
| tag | indeks | word offset | byte offset |
```

### 12.4 Direct mapped cache'in zayıf yanı

**Soru:** Bir program sürekli 0 ve 8 adreslerine erişip ikisinde de değişiklik yapıyorsa, cache'in diğer satırları boşken veri sürekli hafızadan mı çekilir? **Cevap:** Eşleme direct mapped ise sorun tam olarak budur. 0 ve 8 aynı satıra (0. satır) düştüğü için 0, 8, 0, 8 diye erişildiğinde satır sürekli bozulur ve her seferinde hafızadan okunur; cache'in kalan 3 satırı hiç kullanılmaz. Fully associative ve set associative eşleme bu sorunu gidermek için önerilmiştir; orada birebir eşleme ya yoktur ya da gevşetilmiştir ve aynı yere düşme ihtimali azalır.

**Soru:** Cache'teki veri güncellenince hafıza hemen mi güncellenir, yoksa satır değiştirileceği zaman mı? **Cevap:** Buna ilişkin iki yöntem vardır: write back ve write through. Şimdiye kadar anlatılanlar hafızadan okumayla ilgilidir. Yalnız cache güncellenirse hafıza geride kalır; hem cache hem hafıza güncellenirse performans düşer. İkisi arasında denge kuran yöntemler sonraki derste işlenecektir.

## 13. Örnek Sorular

### Soru 1 (ekrandan, 02:50:00)

Toplam kapasitesi 8 byte olan, blok genişliği 2 byte olan direct mapped cache yapısı için 16 byte'lık hafıza kullanılıyor. Buna göre cache tag alanının genişliği nedir?

**Çözüm (derste verildi):**

- Satır sayısı: $8 / 2 = 4$.
- İndeks: $\log_2 4 = 2$ bit.
- Byte offset: $\log_2 2 = 1$ bit.
- Hafıza adresi: 16 byte için 4 bit.
- Tag: $4 - 2 - 1 = 1$ bit. Satırda ayrıca 1 bit valid biti bulunur.

Örneğin 0001 adresinde en düşük bit (1) bloğun yüksek anlamlı byte'ını, ortadaki 00 indeksi (0. satır), en yüksek bit (0) tag'i verir. Python ile 16 adresin tamamı için bölme kontrol edildi.

### Soru 2 (ekrandan, 00:25:00 ve 00:30:00)

Komut yürütme IF, OF, EX, WB olmak üzere 4 aşamaya bölünmüştür. En uzun aşama 5 ns, aşamaların toplamı 17 ns'dir. Dallanma içermeyen 20 komut pipeline ile ve klasik (seri) yöntemle kaç ns'de yürütülür? Komutlar 8 aşamaya bölünseydi kaç çevrim gerekirdi?

**Çözüm (derste verildi):**

- Pipeline: $20 + 3 = 23$ çevrim, $23 \times 5 = 115$ ns.
- Seri: $20 \times 17 = 340$ ns.
- 8 aşama: $20 + 7 = 27$ çevrim.

### Soru 3 (derste sözlü, 00:32:31)

Bir komutu pipeline'a aldıktan sonra ikinci komutu pipeline'a sokamamamız için bir sebep ne olabilir?

**Cevap (derste verildi):** Veri bağımlılığı: ikinci komut, birinci komutun sonucunu (ör. R3) işlenen olarak kullanıyorsa birinci komutun write back'i bitene kadar beklemelidir. Bir diğer durum, prefetch kuyruğuna çekilmiş komutların koşullu dallanmayla boşa gitmesidir.

### Soru 4 (derste sözlü, 02:33:44)

16 adreslik hafızanın 4 satırlık direct mapped cache'e 0, 4, 8, C adresleri 0. satıra, 1, 5, 9, D adresleri 1. satıra düşecek biçimde eşlendiği yapıda hafıza adresi ile cache indeksi arasındaki ilişki nedir? Cache'te neler saklanmalıdır?

**Cevap (derste verildi):** İndeks, adresin düşük anlamlı 2 bitidir. Satırda veri, adresin yüksek anlamlı 2 biti (tag) ve valid biti saklanır.

## Dersin Toparlaması

Bu derste tek çevrimli bilgisayar mimarisi tamamlandı: komut ile kontrol kelimesi arasındaki ilişki, senkron ve kombinasyonel blokların zamanlaması ve saat frekansını belirleyen kritik yol tekrar edildi. Ardından komut yürütmeyi IF, OF, EX, WB gibi aşamalara bölen pipeline mantığı, $n + k - 1$ çevrim hesabıyla ve veri bağımlılığı ile dallanmanın akışı nasıl bozduğuyla birlikte anlatıldı. Giriş-çıkış bölümünde klavye tarama mantığı, arayüz kavramı, adres çözümleme ve yüksek empedans, programlanabilir paralel arayüzün yazmaçları, strobe ve handshaking zamanlaması, asenkron ve senkron seri haberleşme ile polling, kesme (daisy chain ve öncelik kodlayıcı) ve DMA veri aktarım yöntemleri işlendi.

Son bölümde yerellik ilkesi ve bellek hiyerarşisi üzerinden cache'in neden gerektiği açıklandı; üç eşleme yöntemi tanıtıldı ve direct mapped cache'te indeks, tag, valid biti ve byte offset alanlarının nasıl belirlendiği örneklerle gösterildi. Bir sonraki derste fully associative ve set associative cache'lerin okuma yönünde incelenmesi, ardından write back ve write through gibi yazma yöntemleri ele alınacak.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
