# Ders 26 Genişletilmiş Notu: Hafıza Birimleri ve 8086 Hafıza Arayüzü

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dersin kapsamı
- 2. ROM ve çeşitleri
- 3. ROM'un blok yapısı ve iç yapısı
- 4. RAM, SRAM ve DRAM
- 5. 8086'nın hafıza uzayı ve bankalar
- 6. Adres çözümleme
- 7. Örnek: hafıza arayüzü kapasiteleri
- 8. Örnek: 128 KB RAM ve 128 KB ROM yerleşimi
- 9. Örnek: FF800H-FFFFFH aralığına ROM bloğu
- Örnek Sorular
- Dersin Toparlaması

## 1. Dersin kapsamı

Dersin konusu hafıza arayüzleridir (memory interface). Konu başlıkları slaytta şöyle verilir (ekrandan, 00:10:00): hafıza birimleri (ROM: Masked ROM, PROM, EPROM, EEPROM, Flash Memory; RAM: SRAM, DRAM), adres çözümleme, 8086 ile hafıza birimleri arayüzü ve örnekler.

Dersin iki ana hedefi vardır. Birincisi, küçük hafıza bloklarını kullanarak daha büyük bloklar oluşturmaktır. Bu genişleme üç biçimde yapılabilir:

- Veri yolu yönünde genişleme: küçük bloklarla daha geniş veri yoluna sahip bir eleman kurmak.
- Kapasite yönünde genişleme: küçük bloklarla tek parça gibi davranan daha yüksek kapasiteli bir eleman kurmak.
- Her iki yönde birden genişleme.

İkinci hedef, oluşturulan hafıza bloğunu 8086'nın hafıza uzayında belirli bir adres aralığına yerleştirmektir.

> **Hocanın vurgusu:** Bu dersin konusundan ve bir önceki dersin kesme konusundan final sınavında kesin soru gelecek.

## 2. ROM ve çeşitleri

### 2.1 ROM nedir?

ROM (Read Only Memory), çalışma sırasında yalnız okunabilen bir hafıza birimidir. Kalıcıdır (non-volatile): enerjisi kesildiğinde verisi kaybolmaz.

Bir mikroişlemcili sistem açıldığında (boot) işi önce BIOS çipi ele alır, gerekli kontrolleri yapar ve sorun yoksa kontrolü işletim sistemine devreder. İşletim sistemine devretmek, işletim sisteminin ikincil hafızadan ana belleğe (RAM) yüklenmesi ve orada çalışması demektir. Sistemi ilk ayağa kaldıran BIOS çipi ROM yapısındadır. Bu yüzden 8086'nın reset vektörünün bulunduğu bölgeye bir ROM yerleştirilmelidir.

> **Ek bilgi (derste anlatılmadı):** 8086'da reset sonrası CS = FFFFH, IP = 0000H olur; ilk komut fiziksel FFFF0H adresinden alınır. Bu yüzden ROM genellikle hafıza uzayının en üst kısmına yerleştirilir; ders örneklerindeki ROM blokları da FFFFFH adresinde biter.

### 2.2 ROM çeşitleri

Slayttaki liste (ekrandan, 00:15:00) üretim teknolojisine göre yapılmış bir sınıflandırmadır:

- **Masked ROM:** imalat aşamasında programlanır. Kullanıcı ROM'u doğrudan programlanmış hâlde alır.
- **PROM (programmable read-only memory):** programlanabilir hâlde imal edilir. Kullanıcı bir kez programlar, sonra o şekilde kullanılır. Programlama, sigortaların (fuse) yakılması ya da korunmasıyla yapılır.
- **EPROM (erasable programmable read-only memory):** silinebilir ve tekrar programlanabilir. Çipin üzerinde bir pencere vardır; bu pencere çalışma sırasında bantla ya da bir yalıtım malzemesiyle kapatılır. Programı silmek için pencere açılır ve çip 15-20 dakika kadar ultraviyole ışıkta tutulur. Hoca bunu sigortanın yanık hâlinin giderilmesi ya da daha doğrusu bir kapı (gate) durumunun değiştirilmesi olarak anlattı.
- **EEPROM (electrically erasable programmable read-only memory):** programlama da silme de elektrikseldir. Normal fonksiyon uçlarının yanında programlama uçları vardır; bu uçlarda gerekli koşullar sağlanınca çip elektriksel olarak silinip yeniden programlanır.
- **Flash bellek:** USB belleklerde kullanılan yapıdır. Tek tek hücreleri silmek yerine bloklar hâlinde silme yapılır. Teknolojisi farklıdır ama ROM çeşidi olarak ele alınabilir.

## 3. ROM'un blok yapısı ve iç yapısı

### 3.1 Blok yapısı

Bir ROM'un $n$ adres ucu, $m$ veri ucu ve iki kontrol ucu vardır: $\overline{OE}$ (output enable) ve $\overline{CS}$ (chip select).

- $n$ adres ucu, ROM içinde $2^n$ hafıza gözü olduğunu gösterir.
- $m$ veri ucu, her gözün $m$ bit sakladığını gösterir.
- Kapasite: $2^n \times m$.

Bağlantılar şöyle olmalıdır:

- $\overline{OE}$ ucu mikroişlemcinin $\overline{RD}$ ucuna bağlanır. İşlemci okuma işareti verdiğinde, adres uçlarıyla seçilen gözdeki veri veri uçlarına çıkar.
- Veri uçları mikroişlemcinin veri uçlarına, adres uçları mikroişlemcinin adres uçlarına bağlanır.
- $\overline{CS}$ ucu (aktif 0) harici adres çözümleme devresinin çıkışına bağlanır.

G/Ç cihazları 1, 2 ya da 4 baytlık yer kaplıyordu; ROM ise kilobayt mertebesindedir, yani geniş bir adres aralığı kaplar. ROM'u yerleştirdiğimiz aralıktaki bir adresle komut yürütüldüğünde adres çözümleme devresi $\overline{CS}$ işaretini üretir. Hafıza birimlerine `IN`/`OUT` komutlarıyla değil, `MOV` komutuyla erişilir; çünkü bunlar G/Ç cihazı değil hafıza cihazıdır.

> **Ders sonrası not:** Hoca bir cümlede "eğer bu bir hafıza cihazı olmuş olsaydı işlemler `OUT` ve `IN` ile olacaktı" dedi; kastettiği G/Ç cihazıdır. `IN`/`OUT` G/Ç cihazları için, `MOV` hafıza için kullanılır.

### 3.2 İç yapı: dekoder ve transistör matrisi

ROM'un içinde bir dekoder ve bir transistör matrisi vardır (ekrandan, 00:20:00). Dekoder $n$ adres ucundan $2^n$ hafıza gözünü (satırı) oluşturur. Slayttaki 4x4 ROM'da A1, A0 adres girişleri bir dekodere girer; dekoderin 0-3 çıkışları dört satırı sürer. Her satırda dört transistör vardır, yani her göz 4 bit tutar. $2^2 = 4$ göz ve göz başına 4 bit olduğu için kapasite 4x4'tür.

Her sütunun üstünde bir pull-up direnç (R) vardır ve sütunlar D3, D2, D1, D0 veri uçlarına iner. Her transistörün kapı (gate) bağlantısında bir sigorta bulunur.

Hoca çalışma mantığını önce aktif 0 çıkışlı dekoderle anlatmaya başladı, sonra daha anlaşılır olduğu için aktif 1 seçimle anlattı:

- Bir satır seçildiğinde o satırdaki transistörlerin kapısına 1 gelir.
- Sigorta korunmuşsa transistör iletime geçer; pull-up direnç üzerinden gelen besleme gerilimi transistörden toprağa akar. Veri ucunda lojik 0 görülür.
- Sigorta yakılmışsa transistörün kaynak (source) ve savak (drain) uçları birbirinden kopmuş gibi davranır. Besleme pull-up direnç üzerinden doğrudan veri ucuna gider; lojik 1 görülür.
- Seçilmeyen satırlardaki transistörler iletimde değildir, veri hattını etkilemez.

Bu senaryo NMOS transistörler için geçerlidir. PMOS kullanılırsa durum tersine döner: sigorta korunursa 1, yakılırsa 0 okunur. ROM'u programlamak, hangi sigortaların yakılıp hangilerinin korunacağını belirlemektir.

### 3.3 4x4 ROM programlama örneği

Slaytta (ekrandan, 00:25:00) programlanacak değerler "Adr./Data" olarak verilmiştir:

| Adres (A1A0) | Veri (hex) | D3 D2 D1 D0 |
|---|---|---|
| 00 | A | 1 0 1 0 |
| 01 | 3 | 0 0 1 1 |
| 10 | 5 | 0 1 0 1 |
| 11 | 7 | 0 1 1 1 |

Her satırda 1 olması gereken bitlerin sigortası yakılır, 0 olması gerekenlerinki korunur. Örneğin 0 numaralı satıra 1010 yazmak için en yüksek anlamlı bitin (D3) sigortası yakılır, D2'ninki korunur, D1'inki yakılır, D0'ınki korunur.

Okuma örneği: adres uçlarına A1A0 = 10 verilirse 2 numaralı satır seçilir. D3 sütununda sigorta korunduğu için kaynak ile savak bağlıdır ve toprağa bağlantı yüzünden D3 = 0 okunur. D2'de sigorta yakıldığı için pull-up direnç üzerinden D2 = 1 okunur. D1 = 0, D0 = 1 olur. Sonuç: 0101 = 5, programlanan değerle aynıdır.

## 4. RAM, SRAM ve DRAM

### 4.1 RAM'in özellikleri

RAM geçici (volatile) bir hafıza birimidir. Okuma ve yazma hızı ROM'dan yüksektir, üretim maliyeti de daha yüksektir. Ana bellek (main memory) olarak kullanılır.

Adı Random Access Memory olduğu için rastgele erişim sağlar: adres verilerek istenen göze doğrudan erişilir, zaman karmaşıklığı açısından $O(1)$ gibi düşünülebilir. Bunun karşıtı sıralı erişimdir (sequential access): belirli bir adrese ulaşmak için baştan itibaren bütün adresleri dolaşmak gerekir. Yazılımda bağlı liste buna örnektir: bir değeri aramak için baştan (head) başlayıp bağlantılar boyunca gezmek gerekir. Donanımdaki karşılığı manyetik kasetlerdir: belirli bir adrese ulaşmak için kaseti sarmak gerekir.

RAM iki türe ayrılır:

- **Statik RAM (SRAM):** birim hafıza elemanları flip-flop mantığındadır. Enerji kesilmediği sürece değeri kararlı biçimde tutar.
- **Dinamik RAM (DRAM):** her hücre bir transistör ve bir kapasiteden oluşur. Kapasite yükünü kaçak akımlarla kaybedebildiği için değer belirli aralıklarla yeniden yazılmalıdır. Örneğin lojik 1 tutan bir hücrenin yükü azalıp henüz eşiğin altına düşmemişken (hâlâ 1 olarak okunurken) değer tekrar yazılır ve yük ilk seviyesine getirilir.

### 4.2 SRAM hücresi

Flip-flopların en temel hâli, birbirine geri besleme ile bağlı iki kapıdır. Sol tarafta lojik 1 oluşturulmuşsa ilk kapının çıkışı 0 olur, bu 0 ikinci kapıdan geçip yeniden 1 üretir. Kapıların beslemesi sürdükçe bir tarafta 1, diğer tarafta 0 kararlı biçimde kalır.

Slayttaki SRAM hücresi (ekrandan, 00:30:00) iki biçimde çizilmiştir: solda geri beslemeli iki evirici ve M5, M6 erişim transistörleri; sağda aynı yapının transistör düzeyi (M1-M6, $V_{DD}$ ve toprak). Hücrenin iç düğümleri Q ve $\overline{Q}$'dur. WL (word line) adres seçimini, BL ve $\overline{BL}$ (bit line) veriyi taşır.

- Her evirici bir PMOS ve bir NMOS transistörden oluşan bir CMOS çiftidir.
- Hücrenin kendisi 4 transistör, veriyi hücreye aktaran giriş/çıkış transistörleri 2 transistördür. Bir SRAM hücresi en az 6 transistörle kurulabilir.

> **Ders sonrası not:** Altyazıda geri beslemeli kapılar "NAT kapısı" olarak geçiyor; slayttaki çizimde bunlar evirici (NOT kapısı) olarak görünüyor ve hoca da anlatımın bir yerinde "not kapısı" diyor. Doğrusu iki eviricidir.

### 4.3 SRAM'e yazma

**Lojik 1 yazma:** önce hücre seçilir: WL üzerinden 1 gönderilir ve giriş/çıkış transistörleri iletime geçer (kaynak ile savak bağlanır). Sonra BL'ye yazılacak değer olan 1, $\overline{BL}$'ye tersi olan 0 verilir. 1 değeri bir eviricinin girişine ulaşır ve çıkışında 0 üretir; bu 0, diğer taraftan gelen 0 ile uyumludur, çakışma olmaz. 0 değeri diğer eviricinin girişine girer ve çıkışında 1 üretir. Böylece bir tarafta 1, diğer tarafta 0 birbirini besleyecek biçimde tutarlı hâle gelir. Besleme sürdükçe değer korunur.

**Lojik 0 yazma:** yine WL ile hücre seçilir (yani hücrenin adresi verilir). BL'den 0, $\overline{BL}$'den 1 girilir. 0, eviriciden geçip 1 olur ve diğer taraftaki girişle tutarlıdır; diğer tarafta 1 girip 0 çıkar. Kararlı yapı oluşur. WL kaldırıldığında hücrede 0 saklanmış olur; anlamlı taraf veri hattının bağlı olduğu Q tarafıdır.

### 4.4 SRAM'den okuma

Okuma için yalnız WL'yi etkin yapmak yeterlidir, ama ayrıca bir karşılaştırıcı (sense) gerekir (ekrandan, 00:35:00). WL = 1 olunca BL hattına saklanan değer X, $\overline{BL}$ hattına X'in tersi ulaşır. Bu iki hat karşılaştırıcının + ve − girişlerine bağlıdır. Karşılaştırıcı, + girişindeki gerilim − girişindekinden yüksekse 1, değilse 0 üretir.

- Saklanan değer 0 ise + girişine 0, − girişine 1 gelir; çıkış 0 olur.
- Saklanan değer 1 ise + girişine 1, − girişine 0 gelir; çıkış 1 olur.

Elektriksel seviyelerde küçük kaymalar olsa bile karşılaştırıcı bunları düzeltip çıkışta net lojik seviyeyi verir.

### 4.5 SRAM blok yapısı ve iç yapısı

SRAM'in blok yapısı ROM'a benzer ama farkları vardır:

- $n$ adres ucu → $2^n$ hafıza hücresi; her hücre $m$ bit ise veri yolu genişliği $m$'dir.
- Hem okuma hem yazma yapılabildiği için iki kontrol ucu vardır: $\overline{WE}$ (write enable) ve $\overline{RE}$ (read enable).
- Belirli bir adres aralığına yerleştirmek için bir $\overline{CS}$ ucu vardır.
- Veri yolu çift yönlüdür.

Bağlantılar: adres uçları işlemcinin adres uçlarına, $\overline{WE}$ işlemcinin $\overline{WR}$ ucuna, $\overline{RE}$ işlemcinin $\overline{RD}$ ucuna, $\overline{CS}$ adres çözümleme devresinin çıkışına, veri uçları işlemcinin veri uçlarına bağlanır.

İç yapıda yine bir dekoder ve hafıza matrisi vardır; bunlara ek olarak okuma/yazma kontrolünü sağlayan bir giriş/çıkış tamponu bulunur. Okuma doğrudan matristen değil, arayüz sağlayan bu tampon üzerinden yapılır.

### 4.6 DRAM hücresi

DRAM'de her hafıza hücresi bir transistör ve bir kapasiteden oluşur. Hoca, kapasitenin de bir transistörün iki ucu birleştirilerek elde edilebileceğini, bu yüzden bir DRAM hücresinin iki transistörlük alan tuttuğunu söyledi. Buna göre aynı alanda SRAM'e göre çok daha fazla (hocanın ifadesiyle dört kat) veri saklanabilir.

DRAM'de 0 yazıldıktan sonra kaybolmaz. Yalnız lojik 1 kaybolabilir: 1, kapasitedeki yüke karşılık gelir ve kaçak akımlarla bu yük azaldıkça değer giderek 0'a yaklaşır. Hoca bir DRAM hücresini **sızdıran bir kovaya** benzetti.

Hücrede adres seçimi word line, veri bit line üzerinden yapılır:

- **1 yazma:** hücre WL ile seçilir, transistörün kaynak-savak bağlantısı kurulur. Bit hattından 1 gönderilince savağa bağlı kapasite şarj olur. Adres kaldırıldığında yük kapasitede kalır, 1 saklanmış olur.
- **0 yazma:** hücre seçilir, bit hattından 0 gönderilir. Kapasitede yük varsa 0'a bağlı hat üzerinden deşarj olur. Adres kaldırıldığında kapasite boş kalır, 0 saklanmış olur (ekrandan, 00:40:00: "DRAM – 0 Yazma Mantığı", Bit Line = 0, t1 transistörü, C1 kapasitesi, sonuçta X = 0).

### 4.7 DRAM tazeleme (refresh)

Kapasiteye yazılan 1 onu belirli bir gerilime kadar şarj eder. Kaçak akımlar yüzünden bu gerilim üstel olarak azalır ve bir süre sonra 1 ile 0'ı ayıran eşik geriliminin altına düşme riski doğar. Kapasitenin zaman sabiti dikkate alınarak belirli aralıklarla saklanan değer yeniden yazılır: yük eşiğin altına inmeden en yüksek seviyesine kadar doldurulur, sonra yine azalır, yine doldurulur. DRAM'in periyodik güncellenmesi bu mantıkla yapılır.

### 4.8 DRAM'de adresleme

SRAM'de verilen adres değeri doğrudan bir satırı seçer: $n$ adres ucuyla $2^n$ göz adreslenir. DRAM'de ise adres iki farklı zamanda alınır. İlk anda gönderilen $n$ bitlik adres bir mandala, ikinci anda gönderilen başka bir $n$ bitlik adres öteki mandala alınır. Biri satırı, diğeri sütunu seçer. Böylece $2^n$ satır x $2^n$ sütun = $2^{2n}$ göz adreslenir. Her kesişim noktasında (Z yönünde) $m$ bit varsa kapasite:

$$2^{2n} \times m$$

<!-- BELİRSİZ: 00:44:02-00:44:44 arasında hoca satır/sütun seçimi için birer adres ucu kullanılırsa kapasitenin $2^{n-2} \times 2 \times m$ gibi bir değere düşeceğini ve DRAM kontrolcüsü kullanılırsa yine $2^{2n}$ göze ulaşılacağını söylüyor; altyazıdan tam hesap çıkarılamadı. -->

DRAM de bir RAM olduğu için $\overline{WE}$ ($\overline{WR}$'ye) ve $\overline{RE}$ ($\overline{RD}$'ye) uçlarına sahiptir.

Slayttaki DRAM iç yapısında (ekrandan, 00:45:00) 12 bitlik RADR[11:0] adres girişi hem Row Addr Latch'e ($\overline{RAS}$ ile) hem Column Address Latch'e ($\overline{CAS}$ ile) gider. Satır mandalı row driver'lar üzerinden DRAM hücre matrisini sürer; sütun tarafında sense amplifier'lar vardır, okunan veri data-out buffer üzerinden DOUT'a çıkar. Yazılacak veri DIN girişinden data buffer'a gelir.

> **Ders sonrası not:** Hoca anlatımda bir yerde ilk gönderilen adresin sütun, ikincinin satır seçimi yaptığını söyledi. Slayttaki yapıda ve standart DRAM çalışmasında büyük olasılıkla önce satır adresi $\overline{RAS}$ ile, sonra sütun adresi $\overline{CAS}$ ile alınır. Kapasite hesabı sıradan etkilenmez.

## 5. 8086'nın hafıza uzayı ve bankalar

### 5.1 Temel sayılar

Slayttaki özet (ekrandan, 00:50:00):

- 8086: 20 adres ucu, 16 veri ucu.
- Hafıza birimleri: 8 veri ucuna sahip (aksi belirtilmedikçe temel bloklar 8 bitlik kabul edilir).
- 8086 çift adresten 16 bitlik, tek adresten 8 bitlik ve çift adresten 8 bitlik işlemleri bir okuma/yazma çevriminde yapmayı desteklemeli.

Bu üç işlemin örnekleri (ekrandan, 00:50:00):

```asm
MOV AX, [100H]   ; çift adresten 16 bit
MOV AL, [101H]   ; tek adresten 8 bit
MOV AL, [100H]   ; çift adresten 8 bit
```

Daha önce 8 bitlik G/Ç birimleri ardışık çift ya da ardışık tek adreslere yerleştirilmiş ya da iki 8 bitlik birimle 16 bitlik bir G/Ç birimi kurulup ardışık çift ve tek adreslere yerleştirilmişti. Hafızada da benzer bir düzen gerekir.

### 5.2 Neden 512K x 16?

20 adres ucu $2^{20}$ göz adresler. Her göz 8 bit olduğuna göre kapasite $2^{20} \times 8$ bittir. $2^{20} = 2^{10} \cdot 2^{10}$, yani kilo x kilo = mega; toplam 1 MB.

Ama 8086'nın 16 veri ucu vardır ve hafızayı x16 olarak görmek ister. 1M x 8'lik bir hafıza doğrudan bağlansaydı 8 bitlik çıkışı ya D0-D7'ye ya D8-D15'e bağlanacaktı; işlemci hafızanın yarısına asla erişemeyecekti. Bu yüzden toplam kapasite ikiye bölünür: her biri 8 bit olan iki 512K'lık banka yan yana çalıştırılır. 8086'nın görmek istediği arayüz **512K x 16**'dır.

### 5.3 Çift ve tek bankalar

Sağdaki bankada yalnız çift adresler (even bank), soldaki bankada yalnız tek adresler (odd bank) bulunur. Aynı satırdaki iki göz yalnız A0 bitinde farklıdır.

- Çift banka A0 ile seçilir (A0'ın diğer adı $\overline{BLE}$, bus low enable). A0 = 0 olunca seçilir. Veri uçları D0-D7'ye bağlanır.
- Tek banka $\overline{BHE}$ (bus high enable) ile seçilir. $\overline{BHE}$ = 0 olunca seçilir. Veri uçları D8-D15'e bağlanır.

Yalnız A0'ın 0 ya da 1 olması yetmez, çünkü üç durum vardır: yalnız çift bankadan 8 bit, yalnız tek bankadan 8 bit ve iki bankanın aynı satırından 16 bit. Üç durum için en az iki bit gerekir: A0 ve $\overline{BHE}$.

A0 banka seçimine ayrıldığında geriye A1-A19 olmak üzere 19 adres ucu kalır. $2^{19}$ = 512K satır seçilebilir; bu da kurulan arayüzün satır sayısıyla aynıdır. A1-A19 iki bankaya ortak gider. Çift bankadaki bütün gözlerin D0 uçları birleştirilip işlemcinin D0'ına, D1 uçları D1'ine, ..., D7 uçları D7'sine bağlanır. Tek bankanın veri uçları da aynı biçimde D8-D15'e bağlanır.

### 5.4 Çift adresten 8 bit: `MOV AL, [100H]`

Slayt (ekrandan, 00:55:00): "MOV AL, [100H], A0=0"; tek bankada $\overline{BHE}$ = 1, çift bankada A0 = 0.

- Adres çift olduğu için A0 = 0.
- Çift adresten 8 bitlik işlem olduğu için işlemci $\overline{BHE}$ = 1 üretir.
- İşlemci veriyi D0-D7 üzerinden bekler.

A0 = 0 olduğu için çift banka seçilir; 100H adresi de bu bankadadır. $\overline{BHE}$ = 1 olduğu için tek banka seçilmez, D8-D15'e veri çıkmaz. Veri D0-D7'ye çıkar ve işlemci tam da oradan bekler. İşlem doğru yapılır.

### 5.5 Tek adresten 8 bit: `MOV AL, [101H]`

Komutla segment ve ofsetten 20 bitlik adres oluşturulur. En düşük anlamlı bit A0 yalnız banka seçiminde kullanılır; 101H tek olduğu için A0 = 1'dir.

100H ve 101H'ın A1-A19 bitleri aynıdır; tek fark A0'dadır (ara adım eklendi):

```text
100H = 0001 0000 0000   A0 = 0
101H = 0001 0000 0001   A0 = 1
```

Bu yüzden `MOV AL, [101H]` çalıştırıldığında tek bankada 100H ile aynı satırdaki göz seçilir. İşlemci A0 = 1, $\overline{BHE}$ = 0 üretir. Çift banka seçilmez, tek banka seçilir ve değer D8-D15'e çıkar. İşlemci bu komutta veriyi zaten D8-D15'ten bekler; senaryo tutarlıdır.

### 5.6 Çift adresten 16 bit: `MOV AX, [100H]`

Slayt (ekrandan, 01:00:00): "MOV AX, [100H], A0=0, /BHE=0, Veri: D0-D15; 100H --> AL, 101H --> AH".

- Adres çift olduğu için A0 = 0.
- 16 bitlik komut olduğu için veri yolunun yüksek anlamlı kısmına da veri gelecek; işlemci $\overline{BHE}$ = 0 üretir.
- İşlemci veriyi D0-D15'in tamamından bekler.

`MOV AX, [100H]`, 100H'daki değeri AL'ye, 101H'daki değeri AH'ye koymak demektir. A0 = 0 ve $\overline{BHE}$ = 0 olduğu için iki banka da seçilir; A1-A19 iki bankaya aynı değeri götürdüğü için aynı satır etkin olur. 100H'daki değer D0-D7'ye, 101H'daki değer D8-D15'e çıkar.

Little endian düzeninde verinin düşük anlamlı kısmı düşük adreste saklanır. 16 bitlik verinin düşük anlamlı baytı veri yolunun düşük anlamlı kısmından, yüksek anlamlı baytı yüksek anlamlı kısmından gelir; AX doğru okunur.

### 5.7 Tek adresten 16 bit: desteklenmeyen durum

İşlemcinin tek okuma/yazma çevriminde desteklemediği durum, tek adresten 16 bitlik işlemdir. Örnek: `MOV AX, [5]`. Bu aslında `MOV AL, [5]` ve `MOV AH, [6]` demektir.

```text
5 = 0101
6 = 0110
```

A0 ayrıldıktan sonra kalan bitler (010 ve 011) aynı değildir; iki bayt aynı satıra düşmez. Aynı satırdan aynı anda seçim yapılıp veri yoluna çıkarılamaz.

İşlemci bu durumda tek adresten 16 bitlik işlemi iki 8 bitlik işleme böler:

1. Önce tek adresten 8 bitlik işlem: 5 adresi tek bankadan D8-D15'e çıkar. Bu sırada çift banka da seçilseydi aynı satırdaki 4 adresinin değeri gelirdi; bu istenmez.
2. Sonra çift adresten 8 bitlik işlem: 6 adresi çift bankadan D0-D7'ye çıkar.

> **Hocanın vurgusu:** 8086, uygun hafıza arayüzü kurulduysa tek adresten 8 bit, çift adresten 8 bit ve çift adresten 16 bit işlemleri bir okuma/yazma çevriminde yapar; tek adresten 16 bit işlemleri ise iki çevrime bölerek yapar.

## 6. Adres çözümleme

### 6.1 Neden gerekir?

Slayttaki maddeler (ekrandan, 01:05:00):

- Hafıza ve G/Ç çipleri ortak veri ve adres yollarını kullanır.
- Bir seferde yola veri çıkaran tek bir çip sağlamak için adres çözümleme kullanılır.
- Hafıza ve G/Ç çiplerini yalnız belirli adres aralıklarına yerleştirmek için adres çözümleme gereklidir.

Bir mikroişlemcili sistemde birçok hafıza ve G/Ç birimi aynı anda bağlıdır, ama işlemci her seferinde yalnız biriyle konuşabilir. Birden fazla cihaz aynı anda etkin olursa aynı tele birinin 0, diğerinin 1 çıkarması gibi çakışmalar oluşur. İşlemci `IN`, `OUT` ya da `MOV` yürüttüğünde adres uçlarının bir kısmı adres çözümleme devresine gider; yalnız adresi kendi aralığına düşen cihaz etkin olur. Diğer cihazlar veri uçlarında yüksek empedans gösterir, yani hattan kopmuş gibi davranır. Örneğin `MOV AX, [100H]` yürütülünce 100H hangi cihazın aralığındaysa yalnız o etkinleşir.

### 6.2 Adres uçlarının paylaşımı

- A0: çift ve tek bankaların seçimi.
- A1-Ai: hafıza elemanının kapasitesine göre doğrudan cihazın adres uçlarına.
- Ai+1-A19: adres çözümleme lojiğine.

Hatırlatma: M/$\overline{IO}$ ucu adres çözümlemede kullanılırsa **izole G/Ç** (isolated I/O) olur: 1 MB'lık hafıza uzayı ve 64 KB'lık G/Ç uzayı birbirinden ayrı kullanılır. Kullanılmazsa **memory-mapped I/O** olur: tek bir 1 MB'lık uzay vardır ve düşük anlamlı 64 KB'ı G/Ç'ye, geri kalanı hafızaya ayrılır.

> **Hocanın vurgusu:** Derste aksi belirtilmedikçe izole G/Ç kullanılır; yani M/$\overline{IO}$ adres çözümleme devresinde kullanılmalıdır. Hoca bunun vizede sık yapılan hatalardan biri olduğunu belirtti.

### 6.3 Separate Bank Decoder ve Separate Bank Strobe

Bu ayrım izole/memory-mapped ayrımından farklıdır. 512K x 16'lık arayüzdeki çift ve tek bankaların nasıl seçileceğiyle ilgilidir (ekrandan, 01:10:00).

**Separate Bank Decoder:** bankalar chip select uçlarıyla ayrı ayrı seçilir. Adres çözme lojiğine $\overline{BHE}$, A0 ve Ai+1-A19 girer; çıkışında $\overline{CS}_{\text{çift}}$ ve $\overline{CS}_{\text{tek}}$ üretilir. Tek bankanın ve çift bankanın $\overline{CS}$ uçları bu iki çıkışa bağlanır; A1-Ai iki bankaya ortaktır; $\overline{RD}$ iki bankanın $\overline{RE}$ uçlarına, $\overline{WR}$ iki bankanın $\overline{WE}$ uçlarına ortak bağlanır. Lojik, A0 ve $\overline{BHE}$'ye göre ya tek bankayı, ya çift bankayı, ya da ikisini aynı anda etkin yapar.

**Separate Bank Strobe:** iki banka tek bir adres bloğu gibi görülür. Adres çözme lojiğine yalnız Ai+1-A19 girer ve tek bir $\overline{CS}$ iki bankaya birden gider. Çift ve tek bankalar okuma/yazma işaretleri bölünerek ayrılır:

$$\overline{RD}_{\text{tek}} = \overline{RD} + \overline{BHE}, \quad \overline{RD}_{\text{çift}} = \overline{RD} + A0$$

$$\overline{WR}_{\text{tek}} = \overline{WR} + \overline{BHE}, \quad \overline{WR}_{\text{çift}} = \overline{WR} + A0$$

$\overline{WR}$ aktif 0'dır, A0'ın 0 olması da çift bankayı seçen aktif 0 durumudur. İkisi de 0 iken 0 üreten kapı OR kapısıdır. $\overline{RD}_{\text{tek}}$ ve $\overline{WR}_{\text{tek}}$ tek bankanın $\overline{RE}$, $\overline{WE}$ uçlarına; $\overline{RD}_{\text{çift}}$ ve $\overline{WR}_{\text{çift}}$ çift bankanınkilere bağlanır.

Çift adresten 16 bitlik yazmada işlemci A0 = 0 ve $\overline{BHE}$ = 0 üretir; $\overline{WR}_{\text{tek}}$ ve $\overline{WR}_{\text{çift}}$ ikisi de 0 olur ve iki banka hem $\overline{CS}$ hem de okuma/yazma uçlarıyla seçilmiş olur.

### 6.4 Dekoderler

Adres çözümleme çok girişli NAND kapısı, dekoder ya da programlanabilir lojik elemanlarla yapılabilir. Derste temel olarak 3x8 ya da 2x4 dekoder kullanılacak. İkisi de aktif 0 çıkışlıdır.

- **3x8 dekoder:** E1 = 1, $\overline{E2}$ = 0, $\overline{E3}$ = 0 verilirse etkin olur. C en anlamlı olmak üzere C B A girişlerine verilen ikili sayıya karşılık gelen çıkış 0, diğerleri 1 olur. Örneğin 000 → $\overline{Y0}$ = 0. Etkin değilse bütün çıkışlar 1'dir.
- **2x4 dekoder:** tek bir enable ucu vardır. Etkinse B en anlamlı olmak üzere B A değerine karşılık gelen çıkış 0, diğerleri 1 olur; enable ucuna 1 verilirse bütün çıkışlar 1 olur.

## 7. Örnek: hafıza arayüzü kapasiteleri

Aradan sonra hoca geçmiş yıllara ait bir vize kâğıdı üzerinden örnekler çözdü. İlk soru (ekrandan, 01:30:00): hafıza uzaylarının tamamı göz önünde bulundurulduğunda uygun hafıza arayüzü kapasitelerini bulun.

**a) 8088 (20 bit adres yolu, 8 bit veri yolu):** $2^{20}$ = 1M göz, her göz 8 bit. 8088 her gözü zaten 8 bit görmek ister. Arayüz: **1M x 8**.

**b) 8086 (20 bit adres yolu, 16 bit veri yolu):** $2^{20}$ = 1M göz, toplam 1 MB. 8086 veri yolunu 16 bit gördüğü için 1M x 8 konamaz; yarısı alınıp yan yana çalıştırılır. 1M satır ikiye bölünür: 512K satır, her satır 16 bit. Arayüz: **512K x 16**.

**c) 80486 (32 bit adres yolu, 32 bit veri yolu):** $2^{32} = 4 \cdot 2^{10} \cdot 2^{10} \cdot 2^{10}$ = 4G göz, her göz 8 bit, yani 4 GB. 80486 32 bitlik veri yolu görmek istediği için 4G x 8 uygun değildir. Her banka 8 bit genişliğinde olduğundan 4'e bölünür: 1G'lık 4 banka. Arayüz: **1G x 32**.

> **Ders sonrası not:** Hoca soruyu okurken 8088 için "20 adet veri ucu" dedi; soruda 20 bit adres yolu, 8 bit veri yolu yazıyor. Ayrıca 80486 hesabında bir yerde "8086" dedi, kastettiği 80486'dır.

## 8. Örnek: 128 KB RAM ve 128 KB ROM yerleşimi

Soru (ekrandan, 01:30:00): 8086 sisteminin bellek uzayına 00000H adresinden itibaren 128 KB'lık alana 32K x 8 SRAM'lerden oluşan bir RAM bloğu ve bitiş adresi FFFFFH olan 128 KB'lık alana 64K x 8 EPROM'lardan oluşan bir ROM bloğu yerleştirilecek.

### 8.1 Kaç çip gerekir? (c şıkkı)

$$\frac{128\text{K} \times 8}{32\text{K} \times 8} = 4 \text{ SRAM}, \qquad \frac{128\text{K} \times 8}{64\text{K} \times 8} = 2 \text{ EPROM}$$

Bayt "x8" demek olduğu için 8'ler ve K'lar sadeleşir, 128/32 = 4 ve 128/64 = 2 kalır.

### 8.2 Hizalı adres

Hoca çözüme geçmeden bir püf noktası açıkladı. Bir hafıza bloğunun (RAM ya da ROM) başlangıç adresi toplam uzayın ikiye bölünmüş parçalarının sınırına denk geliyorsa ve büyüklüğü bu parçalardan biri kadarsa adres hizalıdır:

- 1 MB'lık uzayda 512 KB'lık blok 00000H'dan ya da tam ortadan, 80000H'dan başlıyorsa hizalıdır.
- 1 MB / 4 = 256 KB'lık blok 00000H, 40000H, 80000H ya da C0000H'dan başlıyorsa hizalıdır.

Hizalı durumlarda adres uçları doğrudan bağlanabilir. Hizalı değilse blok ilk hizalı sınıra kadar ayrılıp iki parça hâlinde değerlendirilir.

> **Ders sonrası not:** Altyazıda orta noktanın adresi "800000" ve "4.000000" gibi fazladan sıfırlarla geçiyor; 20 bitlik uzayda doğrusu 80000H ve 40000H'dır.

### 8.3 Başlangıç ve bitiş adresleri (a şıkkı)

128K = $2^7 \cdot 2^{10} = 2^{17}$, yani 17 adres ucu değişir. Her onaltılık basamak 4 bittir: dört basamak 16 bit eder, bir bit de en yüksek anlamlı basamaktan değişir.

- RAM: 00000H'dan başlar, 17 bit 1 yapılınca bitiş **1FFFFH** olur.
- ROM: FFFFFH'ta biter, 17 bit 0 yapılınca başlangıç **E0000H** olur (en yüksek basamakta yalnız bir bit değişir, F → E).

Yöntem: kapasitenin kaç adres ucunun değişmesine karşılık geldiğini bulup o kadar biti değiştirmek.

### 8.4 Adres ucu sayıları (b şıkkı)

- SRAM 32K x 8: 32K = $2^5 \cdot 2^{10} = 2^{15}$ göz → 15 adres ucu.
- EPROM 64K x 8: 64K = $2^6 \cdot 2^{10} = 2^{16}$ göz → 16 adres ucu.

### 8.5 Adres çözümleme ve bağlantılar (d şıkkı)

Soru, RAM ve ROM bloklarının yerleşimini sağlayan adres çözümleme devresinin **tek bir dekoderle** kurulmasını ve tüm bağlantıların çizilmesini istiyor. Uçlar: SRAM'de D7-D0, adres yolu, $\overline{CS}$, $\overline{OE}$, $\overline{WE}$; EPROM'da D7-D0, adres yolu, $\overline{CS}$, $\overline{OE}$ (ekrandan, 01:35:00).

Tek dekoder kullanılacağı için Separate Bank Strobe mantığı seçilir: çift ve tek bloklar için tek bir $\overline{CS}$ üretilir, ayrım $\overline{RD}$/$\overline{WR}$ ile A0 ve $\overline{BHE}$ birleştirilerek yapılır (ekrandan, 01:40:00).

**Yerleşim.** Dört SRAM'den ikisi yan yana (aynı satırları gösterecek biçimde) çalışır, kalan ikisi de yan yana. RAM bloğu ortadan ikiye bölünür:

- RAM low: 00000H-0FFFFH
- RAM high: 10000H-1FFFFH
- ROM: E0000H-FFFFFH (iki EPROM, biri çift biri tek adresler için)

**Adres bitleri tablosu** (ekrandan, 01:40:00):

```text
Adres     A19-A16   A15 ............ A1   A0
00000H    0000      0000 0000 0000 000    0
0FFFFH    0000      1111 1111 1111 111    1     RAM low
10000H    0001      0000 0000 0000 000    0
1FFFFH    0001      1111 1111 1111 111    1     RAM high
E0000H    111 0     0000 0000 0000 000    0
FFFFFH    111 1     1111 1111 1111 111    1     ROM
```

- RAM low ve RAM high: her birinde 16 bit değişir; A0 tek/çift seçimine ayrılır, kalan A1-A15 (15 uç) SRAM'lerin adres uçlarına gider. Adres çözümlemeye A16-A19 (4 uç) kalır.
- ROM: 64K x 16'lık bir bloktur, 64K satır = $2^{16}$ → 16 uç. A1-A16 EPROM'ların adres uçlarına gider. Adres çözümlemeye A17-A19 (3 uç) kalır; bunlar ROM için 111'dir.

**Sorunun hileli kısmı.** Üç blok birlikte değerlendirildiğinde A16, A17, A18 ve A19'un hepsi bloklar arasında 0 ya da 1 olabiliyor; yani dört seçim ucu gerekir. Ama 3x8 dekoderin üç seçim girişi vardır. Çözüm: bu bloklarda A19 ve A18 her zaman aynı değeri alır (RAM'de 00, ROM'da 11). A19 ve A18 XOR'lanıp aktif 0 enable ucuna verilir: iki bit aynıysa XOR çıkışı 0 olur ve dekoder etkinleşir, farklıysa hiçbir çıkış seçilmez. Sonra A18 seçim girişine verilir; A18'in değeri belirlenince A19'un da aynı değeri aldığı garanti edilir. Böylece sanal bir dördüncü seçim ucu elde edilir.

**Dekoder bağlantıları** (ekrandan, 01:45:00):

| Dekoder ucu | Bağlantı |
|---|---|
| C | A18 |
| B | A17 |
| A | A16 |
| G1 | M/$\overline{IO}$ (izole G/Ç, hafıza işleminde 1) |
| $\overline{G2A}$ | lojik 0 (toprak) |
| $\overline{G2B}$ | A19 XOR A18 |
| $\overline{Y0}$ | $\overline{CS}_{RAMlow}$ (A18A17A16 = 000) |
| $\overline{Y1}$ | $\overline{CS}_{RAMhigh}$ (001) |
| $\overline{Y6}$, $\overline{Y7}$ | AND kapısı → $\overline{CS}_{ROM}$ (110 ve 111) |

ROM için A16 hem 0 hem 1 olabilir (A18 = A17 = 1). 110 olunca $\overline{Y6}$, 111 olunca $\overline{Y7}$ aktif 0 olur. Bunlardan herhangi biri 0 iken 0 üreten kapı AND kapısıdır; $\overline{Y6}$ ve $\overline{Y7}$ AND'lenerek ROM'un $\overline{CS}$'si üretilir.

**Bellek bağlantıları:**

- SRAM'lerin içte A0-A14 olarak adlandırılan 15 adres ucuna işlemcinin A1-A15 uçları bağlanır.
- Tek adres blokları bir sütunda, çift adres blokları başka bir sütundadır. Low ve high alt bloklar aynı anda seçilemez, bu yüzden karşılıklı veri uçları birleştirilir: tek bloktan gelen 8 veri ucu D8-D15'e, çift bloktan gelenler D0-D7'ye bağlanır.
- EPROM'lara A1-A16 bağlanır.
- OR kapılarıyla $\overline{RD}_{\text{çift}} = \overline{RD} + A0$, $\overline{RD}_{\text{tek}} = \overline{RD} + \overline{BHE}$, $\overline{WR}_{\text{çift}} = \overline{WR} + A0$, $\overline{WR}_{\text{tek}} = \overline{WR} + \overline{BHE}$ üretilir (ekrandan, 01:45:00).
- Tek bloktaki SRAM'lerin $\overline{WE}$ ucuna $\overline{WR}_{\text{tek}}$, $\overline{OE}$ ucuna $\overline{RD}_{\text{tek}}$; çift bloktakilerin $\overline{WE}$ ucuna $\overline{WR}_{\text{çift}}$, $\overline{OE}$ ucuna $\overline{RD}_{\text{çift}}$ bağlanır.
- ROM'da yalnız okuma vardır; EPROM'ların $\overline{OE}$ uçlarına $\overline{RD}_{\text{tek}}$ ve $\overline{RD}_{\text{çift}}$ bağlanır.

## 9. Örnek: FF800H-FFFFFH aralığına ROM bloğu

İkinci örnekte bankalar için ayrı ayrı $\overline{CS}$ üretilir, yani Separate Bank Decoder mantığı kullanılır. Hoca örneğe başlarken "separate strobe" dedi, ama iki ayrı $\overline{CS}$ üretilen bu çözümü sonunda doğru adıyla Separate Bank Decoder olarak andı.

**Soru:** FF800H-FFFFFH aralığında iki adet EPROM kullanarak bir ROM bloğu oluşturun. İzole G/Ç kullanılacak, ROM'un kelime boyutu bayt kabul edilecek. Adres çözme devresi nasıl olmalı?

**Çözüm** (ekrandan, 01:50:00): aralık tek ve çift olmak üzere iki 1 KB'lık bloğa ayrılır: çift adresler FF800H-FFFFEH, tek adresler FF801H-FFFFFH.

```text
Çift: FFFFEH = 1111 1111 1 | 111 1111 111 | 0
      FF800H = 1111 1111 1 | 000 0000 000 | 0
Tek:  FFFFFH = 1111 1111 1 | 111 1111 111 | 1
      FF801H = 1111 1111 1 | 000 0000 000 | 1
               A19 ... A11 | A10 ...   A1 | A0
```

A0 banka seçimine ayrıldıktan sonra değişen bitler A1-A10, yani 10 adres ucudur. Her EPROM $2^{10} \times 8$ = 1 KB'tır. A11-A19 aralığın tamamında 1'dir; adres çözümlemeye bunlar gider.

**Separate Bank Decoder devresi:** iki çok girişli NAND kapısı kullanılır.

- Tek banka: A11-A19 = 1, M/$\overline{IO}$ = 1 ve $\overline{BHE}$ = 0 iken aktif 0 $\overline{CS}_{\text{tek}}$ üretilir.
- Çift banka: A11-A19 = 1, M/$\overline{IO}$ = 1 ve A0 = 0 iken aktif 0 $\overline{CS}_{\text{çift}}$ üretilir.
- Belirlenen değerlerden farklı bir değer varsa (örneğin A11 = 0) çıkış 1 olur ve cihaz seçilmez, çünkü A11 = 0 durumu aralığın dışındadır.

**Soru:** İki bloğu aynı anda seçebilir miyim, örneğin FFFF0H adresinden 16 bitlik bir işlem yapabilir miyim? **Cevap:** Evet. Aralıktaki çift bir adresten 16 bitlik işlemde A11-A19 = 1, `MOV` komutu olduğu için M/$\overline{IO}$ = 1, 16 bitlik işlem olduğu için $\overline{BHE}$ = 0 ve adres çift olduğu için A0 = 0 olur. İki bloğun aynı satırındaki değerler veri yolunun yüksek ve düşük anlamlı kısımlarına aynı anda çıkar; 16 bitlik işlem bir seferde yapılır.

**Separate Bank Strobe'a dönüştürme** (ekrandan, 01:55:00): adres çözümleme devresinin tek bir $\overline{CS}$ çıkışı olur: A19-A11 ve M/$\overline{IO}$ girişli bir NAND kapısı, hepsi 1 iken 0 üretir ve iki EPROM'un $\overline{CS}$ uçlarına birden gider. EPROM'ların A0-A9 uçlarına işlemcinin A1-A10 uçları bağlanır. Tek bankanın (D0-D7 çıkışı işlemcinin D8-D15'ine) $\overline{OE}$ ucu $\overline{RD} + \overline{BHE}$ ile, çift bankanın (D0-D7 çıkışı işlemcinin D0-D7'sine) $\overline{OE}$ ucu $\overline{RD} + A0$ ile sürülür. Çift adresten 16 bitlik işlemde ikisi aynı anda seçilir.

> **Hocanın vurgusu:** Bu yapıyla ilgili finalde kesin soru gelecek. Önceki haftanın kesme konusundan (farklı G/Ç cihazları, NMI ve INTR uçlarından kesmeler) da kesin soru gelecek.

Hoca, derste bakılamayan bir örneği daha kendi kontrolleri için paylaşacağını söyledi.

## Örnek Sorular

**Soru 1** (ekrandan, 01:30:00): Aşağıda özellikleri verilen mikroişlemcilerde, hafıza uzaylarının tamamı göz önünde bulundurulduğunda uygun hafıza arayüzü kapasitelerini (cevaba ilişkin hesabı da yazarak) belirtin.

- a) 8088 (20 bit adres yolu, 8 bit veri yolu) → ___ x ___
- b) 8086 (20 bit adres yolu, 16 bit veri yolu) → ___ x ___
- c) 80486 (32 bit adres yolu, 32 bit veri yolu) → ___ x ___

> **Çözüm (derste verildi):** a) $2^{20}$ = 1M göz, 8 bit → 1M x 8. b) 1 MB'lık uzay 16 bit genişliğinde görülmeli: 1M / 2 = 512K → 512K x 16. c) $2^{32}$ = 4G göz, 32 bit için 4 bankaya bölünür → 1G x 32.

**Soru 2** (ekrandan, 01:30:00 ve 01:35:00): 8086 mikroişlemci sisteminin bellek uzayına 00000H adresinden itibaren 128 KB'lık alana 32K x 8 kapasiteli SRAM'lerden oluşan RAM bloğu ve bitiş adresi FFFFFH olan 128 KB'lık alana 64K x 8 kapasiteli EPROM'lardan oluşan ROM bloğu yerleştirilmek isteniyor.

- a) RAM ve ROM bloklarının başlangıç ve bitiş adreslerini belirtin.
- b) Kullanılan SRAM ve EPROM'ların adres ucu sayılarını belirtin.
- c) İstenen RAM ve ROM bloklarını oluşturmak için kaçar adet SRAM ve EPROM kullanılması gerektiğini bulun.
- d) RAM ve ROM bloklarının bellek uzayında yerleşimini sağlayan adres çözümleme devresini tek bir dekoder kullanarak gerçekleyin ve yapılan tüm bağlantıları çizin. (Not: SRAM uçları D7-D0, adres yolu, $\overline{CS}$, $\overline{OE}$, $\overline{WE}$; EPROM uçları D7-D0, adres yolu, $\overline{CS}$, $\overline{OE}$.)

<!-- BELİRSİZ: d şıkkının metni karede görünmüyor; altyazıdaki okumadan aktarıldı. -->

> **Çözüm (derste verildi):** a) RAM 00000H-1FFFFH, ROM E0000H-FFFFFH (128K = $2^{17}$, 17 bit değişir). b) SRAM 15, EPROM 16 adres ucu. c) 4 SRAM, 2 EPROM. d) Separate Bank Strobe; RAM low 00000H-0FFFFH ve RAM high 10000H-1FFFFH; 74138 tipi dekoderde C = A18, B = A17, A = A16, G1 = M/$\overline{IO}$, $\overline{G2A}$ = 0, $\overline{G2B}$ = A19 ⊕ A18; $\overline{Y0}$ → RAM low, $\overline{Y1}$ → RAM high, $\overline{Y6}$ AND $\overline{Y7}$ → ROM; SRAM'lere A1-A15, EPROM'lara A1-A16; $\overline{RD}$/$\overline{WR}$ A0 ve $\overline{BHE}$ ile OR'lanarak çift/tek işaretleri üretilir. Ayrıntılar 8. bölümde.

**Soru 3** (ekrandan, 01:35:00; derste çözülmedi, kâğıt ekranda kaydırılırken göründü): "00" ile "99" arasında değer gösterebilen arttırma ve sıfırlama tuşları olan bir elektronik sayaç yapılması istenmektedir. 2 adet ortak katotlu 7 parçalı gösterge, 2 adet buton kullanarak istenen sayacı 8086 ve 8255 kullanarak aşağıdaki şartlara göre gerçekleyin.

- a) 8255'in B9H adresinden itibaren ardışık tek adreslere yerleşmesini sağlayacak adres çözümleme devresini 3x8 dekoder kullanarak gerçekleyin (8086 için izole adres uzayları kullanıldığını varsayın).
- b) 2 adet 7 parçalı gösterge için segment değerlerinin 8255'te PORTB ile gönderilebilmesi, gösterge seçiminin PORTC0 (birler basamağı) ve PORTC1 (onlar basamağı) ile yapılması, butonların PORTA0 (arttırma) ve PORTA1'e (sıfırlama) bağlanması istenmektedir. 8086'da adres (A19-A0), veri (D15-D0) ve kontrol ($\overline{RD}$, $\overline{WR}$, M/$\overline{IO}$, $\overline{BHE}$, ...) uçlarının uygun şekilde ayrıştırılmış olduğunu da varsayarak 8255'in 8086 uçlarına, butonlara ve 7 parçalı göstergelere olan bağlantılarını çizerek gösterin (butonlar basıldığında lojik 0, bırakıldığında lojik 1 verecek şekilde çizilmeli ve tuşa basıldığında/bırakıldığında kısa devre oluşmamalı).
- c) b şıkkında yaptığınız bağlantıya göre 8255'in PORTA, PORTB, PORTC ve KOMUT yazmaç adreslerini yazın.

<!-- BELİRSİZ: Sorunun d şıkkı karede kesik görünüyor ("b şıkkında istenenleri gerçekleyecek KOMUT yazmaç değerini bulun..."); devamı okunamadı. -->

> **Çözüm (derste verilmedi):** a) B9H = 1011 1001. A0 = 1 olduğu için 8255 tek bankadadır (veri uçları D8-D15'e bağlanır) ve $\overline{BHE}$ = 0 ile seçilir; 8255'in A0, A1 uçlarına işlemcinin A1, A2 uçları bağlanır. Adres çözümlemeye A3-A7 (= 10111), M/$\overline{IO}$ = 0 ve $\overline{BHE}$ = 0 girer; 16 bitlik G/Ç adresi kullanılırsa A8-A15 = 0 da girer. Olası bir 3x8 bağlantısı: C = A5, B = A4, A = A3 → $\overline{Y7}$ = $\overline{CS}$; G1 = A7; $\overline{G2A}$ = A6 + M/$\overline{IO}$; $\overline{G2B}$ = $\overline{BHE}$ (A8-A15 da kullanılacaksa onlar da bu uca OR'lanır). c) Ardışık tek adresler: PORTA B9H, PORTB BBH, PORTC BDH, KOMUT BFH.

## Dersin Toparlaması

Bu derste önce hafıza birimleri tanıtıldı. ROM kalıcı ve yalnız okunabilen bir hafızadır; iç yapısında bir dekoder ve sigortalı bir transistör matrisi bulunur, programlama sigortaların yakılıp korunmasıyla yapılır. RAM geçicidir; SRAM hücresi en az 6 transistörlü bir flip-flop, DRAM hücresi bir transistör ve bir kapasitedir. DRAM tazelenmeli ve adresini satır/sütun olarak iki parçada alır, bu yüzden kapasitesi $2^{2n} \times m$ olur.

Ardından 8086'nın 1 MB'lık uzayının 512K x 16'lık bir arayüzle, A0 ile seçilen çift ve $\overline{BHE}$ ile seçilen tek bankalar biçiminde kurulduğu gösterildi; tek adresten 16 bitlik işlemin iki çevrime bölündüğü açıklandı. Adres çözümlemede Separate Bank Decoder (iki $\overline{CS}$) ve Separate Bank Strobe (tek $\overline{CS}$, bölünmüş $\overline{RD}$/$\overline{WR}$) yöntemleri karşılaştırıldı. Son olarak eski bir vize sorusu üzerinden 128 KB RAM ve 128 KB ROM'un tek 3x8 dekoderle yerleştirilmesi (A19 ⊕ A18 hilesiyle) ve FF800H-FFFFFH aralığındaki bir ROM bloğu her iki yöntemle çözüldü. Bu ders dönemin son dersiydi; hoca bu konunun ve kesme konusunun finalde kesin sorulacağını vurguladı.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
