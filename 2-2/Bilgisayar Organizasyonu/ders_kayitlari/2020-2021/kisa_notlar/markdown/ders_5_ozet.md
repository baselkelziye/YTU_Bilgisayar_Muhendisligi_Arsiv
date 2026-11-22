# Ders 5 Çalışma Özeti

## Genel Konular

- Kısa sınav sorularının çözümü (1): T flip-flop ve 4x1 MUX ile 4 bitlik paralel yüklemeli yazmaç
  - Fonksiyon tablosu (ekrandan, 00:15:00): $M_2M_1=00$ için $\bar{q}$ (1'e tümleyen), $01$ için $q$ (aktarma, işlem yok), $10$ için $D_4D_3D_2D_1$ (paralel yükleme), $11$ için $q+1$ (arttırma, $15+1=0$ kabul edilebilir). Not: $q=(q_4q_3q_2q_1)_2$.
  - Her bit dilimi (bit slice) bir MUX ve bir T flip-flop'tan oluşur. MUX çıkışı T girişine bağlanır, seçim uçları bütün dilimlerde ortaktır ve dışarıda $M_2M_1$'e gider.
  - T flip-flop'ta $T=0$ durumu korur, $T=1$ durumu tersler (toggle). Tasarım bu tanım bağıntısına göre yapılır; D flip-flop gibi düşünmek tamamen farklı bir devre verir.
  - Tümleme için MUX'un ilgili girişine 1, aktarma için 0 bağlanır.
  - Paralel yükleme için $q \to Q=D$ geçişinden ters tanım tablosu yazılır: durum değişiyorsa $T=1$, değişmiyorsa $T=0$. Sonuç $T_i = D_i \oplus q_i$ olur.
  - Arttırma, aritmetik olarak 1 eklemektir; $q$ ile 1'in OR'lanması değildir. Bir arttırmada bütün bitler değişebileceği için (örneğin 1111) tasarım tek dilimde yapılamaz, bütün $q$'lar birlikte ele alınır.
  - 16 satırlık durum tablosu ve Karnaugh haritalarından: $T_1=1$, $T_2=q_1$, $T_3=q_2q_1$, $T_4=q_3q_2q_1$ (ekrandan, 00:25:00).
  - Logisim benzetiminde 0110 yüklendi, 00 ile 1001'e tümlendi, 01 ile değer korundu, 11 ile her saat darbesinde bir arttı ve 1111'den sonra 0000'a döndü.
- Kısa sınav sorularının çözümü (2): 1 bitlik karşılaştırıcılarla 2 bitlik karşılaştırıcı
  - 1 bitlik karşılaştırıcının çıkışları: $(>) = A\bar{B}$, $(<) = \bar{A}B$, $(=) = \overline{A \oplus B}$ (XNOR) (ekrandan, 00:35:00).
  - Önce 2 bitlik karşılaştırıcının 16 satırlık doğruluk tablosundan çıkış fonksiyonları bulunur, sonra bu fonksiyonlar 1 bitlik karşılaştırıcı çıkışları cinsinden yeniden yazılır.
  - $A>B = (A_1>B_1) + \overline{(A_1<B_1)}\,(A_0>B_0)$. İkinci terim "birinci girişin kendisi, ikincinin değili" biçiminde olduğu için bir 1 bitlik karşılaştırıcının $>$ çıkışıyla üretilir; girişlerine $(A_0>B_0)$ ve $(A_1<B_1)$ verilir. Sonuçtaki OR kapısı soruda hazırdı.
  - $A<B$ simetriktir: $(A_1<B_1) + \overline{(A_1>B_1)}\,(A_0<B_0)$.
  - $A=B = (A_1 \odot B_1)(A_0 \odot B_0)$: iki karşılaştırıcının $=$ çıkışları AND'lenir.
  - Verilen 1 bitlik karşılaştırıcı işaretsiz (unsigned) karşılaştırma yapar; ikiye tümleyen karşılaştırıcı işaretli sayıları karşılaştırır, bu soruda istenen o değildi.
- Hafıza hiyerarşisi
  - BIOS ROM (sistem açılışında donanım kontrolü ve işletim sistemine devretme), ikincil bellek (disk), ana bellek (RAM), önbellek (cache) ve yazmaçlar (register).
  - İşlemciye yaklaştıkça erişim hızı ve maliyet artar, kapasite düşer. Yazmaçlar en hızlı ve en az sayıdadır.
  - Önbellek, verinin komşuluğuna ve aynı değişkene tekrar tekrar erişilmesine dayanır. Önbellekte değişen verinin ana bellekle tutarlılığını sağlamak ayrı bir çalışma konusudur.
- SRAM ve DRAM'e giriş
  - SRAM latch/flip-flop mantığıyla saklar; bir hücre için 4 ya da 6 transistör gerekir.
  - DRAM bir transistör ve bir kapasite ile saklar; daha yoğundur ama yük kaçak akımlarla azaldığı için periyodik yenileme (refresh) ister.
- Hafıza tanımları (ekrandan, 01:00:00 ve 01:15:00)
  - Hafıza, adres, RAM (erişim süresi seçilen gözden bağımsız), bit, byte (8 bit), word (işlemcinin bir seferde okuyup yazabildiği genişlik, genelde 1, 2, 4, 8 byte), veri, işlem (okuma/yazma).
  - $k$ adres biti $2^k$ göz adresler. 20 adres ucu $2^{20}$ = 1M göz demektir.
  - 8086: 20 adres ucu, 16 veri ucu, word 2 byte. 64 bit bilgisayarlarda word 8 byte'tır.
- Mimari türleri
  - Von Neumann: program ve veri belleği aynı adres ve veri yollarını kullanır (8086 ve devamı).
  - Harvard: program ve veri belleğinin ayrı, kendine adanmış yolları vardır; veri belleği program belleğini bozamaz (ARM ailesi, mikrodenetleyiciler).
  - CISC: karmaşık komutlar (çarpma, bölme, vektör işlemleri), komut uzunluğu ve süresi komuttan komuta değişir (8086).
  - RISC: indirgenmiş komut kümesi, komut uzunlukları ve çevrim süreleri eşit (ARM, PIC).
- Hafıza organizasyonu ve kontrol uçları
  - $2^k \times n$ hafıza: $k$ adres ucu, $n$ veri ucu, okuma/yazma ve chip select (CS) uçları.
  - Örnekler: $2^3\times 8$ (8 word, 8 bit), $2^{10}\times 16$ (1024 word, 16 bit) (ekrandan, 01:20:00).
  - CS ve $R/\bar{W}$ tablosu (ekrandan, 01:25:00): CS=0 ise işlem yok; CS=1, $R/\bar{W}=0$ yazma; CS=1, $R/\bar{W}=1$ okuma.
  - Adres çözümleme devresi adres aralığına göre hangi hafıza biriminin CS'sinin aktif olacağını belirler. Seçilmeyen birimlerin veri uçları yüksek empedansa geçer, yani hattan kopmuş gibi davranır.
  - Tek veri yolu olduğu için okuma ve yazma aynı anda olamaz; bu yüzden ikisi tek $R/\bar{W}$ ucunda birleştirilebilir.
- Okuma ve yazma çevrimleri (ekrandan, 01:30:00)
  - 50 MHz saat: periyot $1/(50\cdot 10^6)$ s = 20 ns. Okuma (erişim) süresi 65 ns, yazma süresi 75 ns ise her ikisi de 4 saat çevriminde (80 ns) tamamlanır.
  - T1-T4 dört zamanlı çevrim (8086'da vardır): adres yola çıkar ve çevrim boyunca geçerli kalır, CS aktif olur, $R/\bar{W}$ üretilir. Yavaş bellek için T3'te bekleme yapılabilir.
  - Yazmada veri, yazma işaretinden önce veri yoluna konur. Okumada veri 65 ns sonra yola çıkar ve T4'ün düşen kenarında örneklenir.
- Kalıcı ve geçici hafıza
  - Geçici (volatile): enerji kesilince veri kaybolur (RAM). Kalıcı (non-volatile): enerji kesilse de veri kalır (ROM, sigortaların yakılmasıyla programlanır).
- SRAM hücresi ve bit dilimi (ekrandan, 01:40:00, 01:45:00)
  - Hücre: SR latch, Select girişi, çift raylı (dual rail) veri girişleri $B$, $\bar{B}$ ve çıkışları $C$, $\bar{C}$. Select=0 iken S=R=0 olur, latch durumunu korur.
  - Latch seviye tetiklemeli, flip-flop kenar tetiklemelidir.
  - Bit dilimi: $2^n$ hücre, her biri bir word select ile seçilir; yazma mantığı ($R/\bar{W}$, bit select, data in) ve okuma mantığı (bir latch ile data out).
- $2^n \times 1$ RAM entegresi ve genişletme (ekrandan, 01:50:00, 01:55:00)
  - $n$ adres ucu bir $n \to 2^n$ dekoderle word select hatlarına çözülür. Çıkıştaki üç durumlu tampon CS ile yönetilir.
  - Satır-sütun (coincident) seçimi: 16x1 RAM 4x4 hücre dizisi olarak kurulur; iki adres biti satır dekoderine, iki adres biti sütun dekoderine gider. Aynı adres uçları iki farklı zamanda satır ve sütun için kullanılırsa daha az uçla çalışılır (DRAM'de olduğu gibi). 20 uçla iki kez adres verilirse $2^{40}$ göz seçilebilir.
  - 8x2 düzenleme: sütunlar ikişer ikişer seçilerek her adreste 2 bit okunur.
- SRAM dizileri: veri yolu ve kapasite genişletme (ekrandan, 02:00:00)
  - Word sayısını arttırmak adres uzunluğunu, word genişliğini arttırmak veri uçlarını arttırır.
  - Adres, veri ve $R/\bar{W}$ hatları paralel bağlanır; yüksek anlamlı adres bitleri dekoderle çözülüp CS'leri sürer.
- Örnek 1: 64K x 8 SRAM'lerle 256K x 8 RAM (ekrandan, 02:20:00 - 02:35:00)
  - $64K = 2^{16}$: 16 adres ucu; $256K = 2^{18}$: 18 adres ucu. $256K\times 8 / 64K\times 8$: veri yolu genişletme yok, kapasite yönünde 4 SRAM.
  - 2x4 dekoderin girişlerine $A_{17}A_{16}$, çıkışlarına SRAM CS'leri, enable ucuna RAM bloğunun CS'si bağlanır. $A_0$-$A_{15}$, $D_0$-$D_7$ ve $R/\bar{W}$ ortaklanır.
  - Dekodere $A_1A_0$ bağlansaydı ardışık adresler dört SRAM'e sırayla dağılırdı (0, 4, 8, ... aynı SRAM'de).
  - 3FFFFH adresine 00H yazılırsa dördüncü SRAM seçilir ve onun FFFFH gözüne 00H yazılır.
- Örnek 2: 64K x 8 SRAM'lerle 64K x 16 RAM (ekrandan, 02:40:00)
  - 2 SRAM, veri yolu genişletme yönünde. CS'ler, $R/\bar{W}$'ler ve $A_0$-$A_{15}$ ortak; biri $D_8$-$D_{15}$ (yüksek anlamlı byte), diğeri $D_0$-$D_7$ (düşük anlamlı byte).
- Örnek 3: 64K x 8 SRAM'lerle 256K x 16 RAM (ekrandan, 02:45:00)
  - 4 satır (kapasite) x 2 sütun (veri yolu) = 8 SRAM. Bir satırdaki iki SRAM'in CS'si ortaktır ve 2x4 dekoderden ($A_{17}A_{16}$) gelir.
- DRAM hücresi
  - Bir transistör ve kapasite; veri kapasitede yük olarak saklanır. Bit dilimleri SRAM'dekine benzer biçimde word select ile kurulur; satır-sütun seçimiyle yoğun yerleşim sağlanır.
- Verilog örneklerine kısa bakış
  - 2x1 MUX davranışsal (behavioral) modül olarak `always` bloğu ve `if` ile tanımlandı; ayrıca giriş değerlerini sırayla uygulayan bir test bench dosyası gerekir. Icarus Verilog önerildi.
  - VHDL dosyaları IEEE kütüphanesini yükleyen tanımlarla başlar; Verilog `module` tanımlarıyla ilerler. PLD için yazılmış kod VHDL değildir.

## Hocanın Özellikle Vurguladığı Kısımlar

- T flip-flop ile tasarımda T flip-flop'un tanım bağıntısı kullanılmalı
  - Çok sayıda çözümde T flip-flop D flip-flop gibi kullanılmıştı. Ters tanım tablosu (durum değişiyorsa 1, değişmiyorsa 0) ile tasarım yapılmalıdır.
- Arttırma (increment) aritmetik toplamadır
  - $q+1$, 4 bitlik sayıya 1 eklemektir; OR işlemi olarak yorumlamak tamamen yanlıştır.
- "Sadece" verilen blokla tasarım
  - Kesikli çizgili bölgede yalnız 1 bitlik karşılaştırıcılar kullanılabiliyordu. Yol: hedef fonksiyonları bul, sonra onları bloğun çıkış fonksiyonları cinsinden yaz.
- Dekoder girişine yüksek anlamlı adres bitleri bağlanmalı
  - SRAM içindeki ardışık gözlerin RAM bloğunda da ardışık adres olması için dekodere $A_{17}A_{16}$ bağlanır. $A_1A_0$ bağlanırsa adresler bloklar arasında serpiştirilir.
- Seçilmeyen birimler yüksek empedanstadır
  - Bu sayede adres ve veri uçları ortaklanabilir; aynı anda yalnız bir birim veri yoluna değer çıkarır.
- RAM bloğunun CS'si dekoderin enable ucudur
  - Enable=0 iken hiçbir SRAM seçilmez, bütün veri uçları yüksek empedans olur.

## Kısa Tekrar Notları

- T flip-flop: $T=0$ koru, $T=1$ tersle. Paralel yükleme: $T=D\oplus q$. Arttırma: $T_1=1$, $T_i=q_{i-1}\cdots q_1$.
- 1 bitlik karşılaştırıcı: $>$ $=A\bar{B}$, $<$ $=\bar{A}B$, $=$ XNOR.
- 2 bitlik: $A>B=(A_1>B_1)+\overline{(A_1<B_1)}(A_0>B_0)$, $A=B=(A_1\odot B_1)(A_0\odot B_0)$.
- Hiyerarşi: yazmaç > önbellek > ana bellek > disk (hız azalır, kapasite artar).
- SRAM: latch, 4-6 transistör, yenileme yok. DRAM: 1 transistör + kapasite, yoğun, yenileme gerekir.
- $2^k\times n$: $k$ adres, $n$ veri ucu. $2^{10}$=K, $2^{20}$=M, $2^{30}$=G.
- CS=0: işlem yok, uçlar yüksek empedans. $R/\bar{W}=1$ okuma, $0$ yazma.
- 50 MHz → 20 ns; 65 ns okuma ve 75 ns yazma → 4 çevrim.
- Von Neumann: ortak yol. Harvard: ayrı program ve veri yolu. CISC: değişken uzunluk/süre. RISC: sabit uzunluk/süre.
- Gereken çip sayısı = hedef kapasite / çip kapasitesi; satır sayısı kapasite genişletmesi, sütun sayısı veri yolu genişletmesi.
- Kapasite genişletme: dekoder + yüksek anlamlı adres bitleri → CS'ler. Veri yolu genişletme: CS'ler ortak, veri uçları yan yana.

## Detaylı Açıklamalar

- Yazmaç sorusunun çözüm mantığı
  - Bir bit dilimine bakıldığında MUX'un dört girişi dört işleme karşılık gelir (ekrandan, 00:20:00): $I_1$ (seçim 00) girişine 1 bağlanır, çünkü tümleme için T flip-flop'un her darbede terslemesi gerekir. $I_2$ (seçim 01) girişine 0 bağlanır, çünkü aktarmada durum korunur. $I_3$ (seçim 10) girişine $D_i\oplus q_i$ bağlanır: $q=0, D=0$ ise değişim yok (0), $q=0, D=1$ ise değişim (1), $q=1, D=0$ ise değişim (1), $q=1, D=1$ ise değişim yok (0); bu XOR'dur. $I_4$ (seçim 11) girişine arttırma fonksiyonu bağlanır: birinci dilimde 1, ikincide $q_1$, üçüncüde $q_1q_2$, dördüncüde $q_1q_2q_3$.
  - Arttırma tablosunda $T_1$ her satırda 1'dir, $T_2$ iki satırda bir, $T_3$ dört satırda bir, $T_4$ sekiz satırda bir 1 olur. $T_4$'ün yalnız iki 1'i vardır (0111 ve 1111 satırları) ve Karnaugh haritası $q_3q_2q_1$ verir. Bu fonksiyonlar python ile 4 işlem ve bütün $q$, $D$ değerleri için kaba kuvvetle doğrulandı.
  - Hocanın değerlendirmesine göre Karnaugh haritaları çizilmeden fonksiyonlar doğrudan tablodan yazılmışsa da yeterlidir; asıl beklenen ara fonksiyonların bulunmasıdır.
- Karşılaştırıcı sorusunun çözüm mantığı
  - Karnaugh haritasından $A>B = A_1\bar{B}_1 + A_0\bar{B}_1\bar{B}_0 + A_1A_0\bar{B}_0$ bulunur (hocanın ekranda gösterdiği ifade incelenen karelerde yok; bu biçim python ile doğrulandı); bu, $A_1\bar{B}_1 + (A_1+\bar{B}_1)A_0\bar{B}_0$ biçimine getirilebilir ve $A_1+\bar{B}_1 = \overline{\bar{A}_1B_1}$ olduğu için 1 bitlik karşılaştırıcı çıkışlarıyla yazılır. İki ifade ve $A<B$, $A=B$ ifadeleri python ile 16 satırın hepsinde doğrulandı.
  - Devrede ilk katta $A_1$-$B_1$ ve $A_0$-$B_0$ karşılaştırılır; ikinci katta biri $>$, biri $<$ için iki karşılaştırıcı daha kullanılır; çıkışta iki OR ve bir AND kapısı vardır (ekrandan, 00:40:00).
- Adres çözümleme örneği
  - Hocanın örneğinde ROM1 0-1000, ROM2 1000-2000, RAM 2000-3000 aralığına yerleştirilmiştir. İşlemci 100 adresinden okumak istediğinde adres çözümleme devresi yalnız ROM1'in CS'sini aktif eder; ROM2 ve RAM'in uçları yüksek empedans olur ve işlemci yalnız ROM1'i görür. Slaytta CS aktif 1 gösterilmiştir, pratikte çoğunlukla aktif 0 kullanılır.
- SRAM bit diliminde yazma ve okuma
  - Yazmada $R/\bar{W}=0$, bit select = 1 olur; AND kapıları geçirgen hale gelir ve data in, kendisi ve değili olarak seçili hücrenin S ve R uçlarına ulaşır. $S\bar{R}$ = 10 ise 1, 01 ise 0 yazılır. Okumada S=R=0 olur, hücre durumunu korur ve seçili hücrenin $C$, $\bar{C}$ çıkışları okuma mantığındaki latch'e, oradan data out'a gider.
- Satır-sütun seçiminin kazancı
  - Tek dekoderli yapıda 16x1 RAM için 4 adres ucu gerekir. Satır-sütun seçiminde aynı 2 adres ucu önce satır, sonra sütun için kullanılırsa 2 uç yeter, ama iki adres erişim zamanı gerekir. Slayttaki örnekte 1001 adresinin ilk iki biti 10 satırını, son iki biti 01 sütununu seçer (ekrandan, 01:55:00).
- Genişletme örneklerinin ortak yöntemi
  - Önce çipin ve hedef bloğun uç sayıları çıkarılır. Sonra hedef kapasite çip kapasitesine bölünür: word sayısı oranı satır (kapasite genişletme), bit genişliği oranı sütun (veri yolu genişletme) sayısını verir. Kapasite genişletmede yüksek anlamlı adres bitleri dekoderle CS'lere gider, kalan adres bitleri ve veri uçları ortaklanır. Veri yolu genişletmede aynı satırdaki çiplerin CS ve adresleri ortaktır, veri uçları yan yana dizilerek geniş word oluşturulur.

<!-- BELİRSİZ: 01:17:58 civarında "her birisi 16 bit veriden oluşan 2 üzeri 20 adet hafıza gözü" örneğinin hangi mimariye ait olduğu altyazıdan anlaşılmıyor. -->
<!-- BELİRSİZ: Verilog 2x1 MUX ve test bench kodu (02:51-02:53) karelerde yok; kodun kendisi nota alınmadı. -->

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
