# Ders 1 Çalışma Özeti

## Genel Konular

- Bilgisayar Mimarilerinin Tarihsel Gelişimi
  - Bilgisayar mimarileri üç ana çağda incelenir: Mekanik Çağ, Elektriksel Çağ ve Elektronik Çağ. Mekanik çağda Abaküs ve Pascal'ın çarklı hesap makinesi gibi cihazlar geliştirilmiştir. Elektriksel çağda delikli kartlar kullanılmış ve IBM'in temelleri atılmıştır. Elektronik çağda ise vakum tüpleri (Colossus - Enigma şifre çözümü), transistörler (1947) ve entegre devreler (1958-1960) sırasıyla ortaya çıkmıştır.
- Mikroişlemcinin Tanımı ve Gelişim Kriterleri
  - Bir mikroişlemcinin gelişmişlik düzeyi dört kritere bağlanır: kaç bitlik olduğu (register boyutu), adresleme kapasitesi (adres ucu sayısı ile 2^n formülü), register sayısı ve komut seti (instruction set) zenginliği. Ayrıca çalışma/işlem frekansı da önemli bir parametredir.
- Intel İşlemcilerin Evrimi (4004 → 8008 → 8080 → 8086)
  - 1971'de Intel 4004 (4 bit, 4096 adresleme, 45 komut, 50 kHz) ilk mikroişlemcidir. 8008 (8 bit, 16 KB adresleme), 8080 (8 bit, 64 KB, TTL tabanlı, 10x daha hızlı) ve 8085 (769 kHz) takip etmiştir. 1978'de çıkan 8086 ise 16 bitlik ilk işlemci olup, 1 MB adresleme, 2.5 milyon işlem/saniye, komut kuyruğu ve zengin komut seti (~20.000 varyasyon) sunmuştur.
- RISC ve CISC Mimarileri
  - RISC (Reduced Instruction Set Computer): Az komut seti, daha az hafıza kullanımı (memory efficient) ancak karmaşık işlemler için daha fazla kod satırı gerekir. CISC (Complex Instruction Set Computer): Zengin komut seti, tek satırda karmaşık işlemler yapılabilir ancak komutları indekslemek için daha fazla hafıza (code segment) gerekir. 8086 CISC mimarisindedir.
- 8086'nın İç Yapısı ve Register Mimarisi
  - 8086 dört genel amaçlı registera sahiptir: AX (akümülatör), BX (base register - dizi erişimi), CX (counting - döngü/sayma), DX (data register - port adresi saklama). Her biri 16 bit olup, 8 bitlik alt parçalara ayrılabilir (AH/AL, BH/BL, CH/CL, DH/DL). Ayrıca SP, BP, SI, DI, segment registerları (CS, DS, SS, ES) ve IP (Instruction Pointer) bulunur.
- Segment Mimarisi ve Fiziksel Adres Hesaplama
  - 8086'da bellek segmentlere bölünmüştür. Her segment 16 bitlik olduğundan 64 KB'lık alan gösterir. Fiziksel adres = Segment × 10H + Offset formülüyle hesaplanır. Örneğin DS=1230H ve SI=0042H ise fiziksel adres 12342H olur. Code segment için CS×10H+IP, stack için SS×10H+SP/BP kullanılır.
- Bayrak (Flag) Register'ı
  - Carry Flag (CF): İşaretsiz toplama/çıkarmada taşma durumunda 1 olur. Parity Flag (PF): Sonuçtaki 1'lerin adedi çift ise 1, tek ise 0 olur. Auxiliary Carry Flag (AF): Nibble (4 bit) seviyesinde elde bayrağı. Zero Flag (ZF): İşlem sonucu 0 ise 1 olur. Sign Flag (SF): Sonuç negatif ise 1 olur. Overflow Flag (OF): İşaretli işlemlerde taşma durumunda 1 olur. Trap Flag (TF) ve Interrupt Enable Flag (IF) interrupt kontrolünde kullanılır.
- Adresleme Modları
  - Register Addressing: MOV AX, BX gibi registerlar arası veri aktarımı. Immediate Addressing: MOV AX, 1234H gibi doğrudan değer atama. Direct Addressing: MOV BX, [1234H] gibi doğrudan bellek adresinden okuma. Register Indirect Addressing: BX, SI veya DI registerındaki değeri adres olarak kullanma. Base-Index Addressing: BX+SI veya BX+DI gibi bileşik adresleme.
- Veri Yolu ve Adres Yolu İlişkisi
  - 16 bitlik bir işlemcide registerlar 16 bit veriyi tek seferde saklayabilir. 16 adet veri ucu varsa tek cycle'da tüm register doldurulabilir. 8088'de 8 bit veri yolu olduğu için 16 bitlik registerı doldurmak 2 cycle sürer. Adres ucu sayısı ise 2^n formülüyle kaç bellek bloğunun adreslenebileceğini belirler.

## Hocanın Özellikle Vurguladığı Kısımlar

- Mikroişlemcinin "kaç bitlik" olduğunun register boyutuyla ilişkili olduğu ve bu kavramın doğru anlaşılması gerektiği vurgulanmıştır.
- Adres ucu sayısının doğrudan adresleme kapasitesini belirlediği (2^20 = 1 MB for 8086) ve bu ilişkinin iyi kavranması gerektiği vurgulanmıştır.
- SMD (Sistem Programlama) bilgisinin bu ders için kritik önemi: 8086 Assembly dilinde programlama yapılacağı için SMD altyapısının sağlam olması gerektiği özellikle belirtilmiştir.
- Labların ders notunun %30'unu oluşturduğu ve ciddi programlama becerisi gerektirdiği vurgulanmıştır.
- 32 bit Windows'ta 4 GB RAM sınırının neden 32 bit adreslemeyle (2^32 = 4 GB) ilgili olduğu pratik örnek olarak verilmiştir.

## Kısa Tekrar Notları

- 8086: 16 bit register, 20 adres ucu, 16 veri ucu, 1 MB adresleme kapasitesi
- Mikroişlemci gelişim kriterleri: bit sayısı, adresleme kapasitesi, register sayısı, komut seti zenginliği, işlem frekansı
- 8086 CISC mimarisindedir; x86 ailesinin temelini oluşturur
- Segment registerları 16 bit olup 64 KB'lık alan gösterir; fiziksel adres = Segment × 10H + Offset
- Genel amaçlı registerlar: AX, BX, CX, DX (her biri 8+8 bit alt bölümlenebilir)
- Bayraklar: CF, PF, AF, ZF, SF, OF, TF, IF, DF
- Adresleme modları: Register, Immediate, Direct, Register Indirect, Base-Index
- Veri yolu (data bus) = tek cycle'da taşınan bit sayısı; Adres yolu (address bus) = adreslenebilen bellek bloğu sayısı

## Detaylı Açıklamalar (Daha Fazla Detay İsteyenler İçin)

**Mikroişlemci Tarihi ve Çağlar:**
Bilgisayar mimarilerinin gelişimi üç ana çağda incelenir. Mekanik Çağ'da (1800'lere kadar) Abaküs, Pascal'ın çarklı hesap makinesi gibi tamamen mekanik cihazlar kullanılmıştır. Bu cihazlarda toplama işlemi çarkların katmanlı yapısıyla gerçekleştirilmiştir. Elektriksel Çağ'da (1800-1940'lar) delikli kartlar kullanılarak programlama yapılmış, Herman Hollerith'in makineleri ve ardından IBM (International Business Machines) ortaya çıkmıştır. Z3 makinesi (1941, 5 Hz) modern bilgisayarın atası sayılır. Elektronik Çağ üç evrede gelişmiştir: Vakum tüpleri (Colossus, ENIAC - 17.000 tüp, 30 ton, 100 kHz, kısa ömür), transistörler (1947, daha küçük, daha güvenilir) ve entegre devreler (1958-1960, çoklu transistör tek chip üzerinde).

**8086 Register Mimarisi:**
8086'da dört ana genel amaçlı register bulunur. AX (Accumulator) aritmetik ve lojik işlemlerde birincil registerdır; AH ve AL olarak 8 bitlik alt parçalara ayrılabilir. BX (Base Register) özellikle dizi veri erişimlerinde base adres olarak kullanılır. CX (Counter Register) döngü işlemlerinde sayma registerı olarak, shift/rotate işlemlerinde kaydırma sayısı için kullanılır. DX (Data Register) dışarıdan gelen verilerin saklanmasında ve port adreslerinin tutulmasında kullanılır. Bunların dışında SP (Stack Pointer), BP (Base Pointer), SI (Source Index), DI (Destination Index) özel amaçlı registerlardır. Segment registerları (CS, DS, SS, ES) belleğin segment yapısını yönetir.

**Segment Mimarisi ve Adresleme:**
8086'da bellek segmentlere bölünmüştür çünkü 16 bitlik registerlarla 20 bitlik fiziksel adres üretmek gerekir. Her segment registerı 16 bitlik bir değer tutar ve bu değer 16 ile çarpılarak (10H ile çarpma = bir basamak sola kaydırma) 20 bitlik fiziksel adresin üst 16 biti elde edilir. Buna offset değeri eklenerek 20 bitlik tam fiziksel adres bulunur. Örneğin DS = 1230H ve BX = 2000H ise fiziksel adres = 1230H × 10H + 2000H = 14300H olur. Bu sayede 1 MB'lık adres alanı 16 bitlik registerlarla erişilebilir hale gelir.

**Bayrak Register'ı ve Kullanım Alanları:**
Flag register'ı işlem sonuçlarının durumunu saklar ve koşullu dallanma (jump) işlemlerinde kritik rol oynar. Carry Flag taşma durumunu, Zero Flag sonucun sıfır olup olmadığını, Sign Flag sonucun işaretini gösterir. Örneğin bir port okumasında sıcaklık belirli bir değerin altına düştüğünde Sign Flag tetiklenerek klimanın çalıştırılması gibi bir kontrol gerçekleştirilebilir. Parity Flag veri iletişiminde bozulma tespitinde kullanılabilir.

**Veri Yolu vs. Adres Yolu:**
Bir mikroişlemcide veri yolu (data bus) ve adres yolu (address bus) farklı kavramlardır. Veri yolu, CPU'nun registerlarına tek cycle'da kaç bitlik verinin aktarılabileceğini belirler. Adres yolu ise kaç farklı bellek bloğunun adreslenebileceğini belirler (2^n). 8086'da 16 veri ucu ve 20 adres ucu vardır. 8088'de ise 8 veri ucu ve 20 adres ucu bulunur; 16 bitlik registerı doldurmak için 2 cycle gerekir, bu da performans kaybı yaratır.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
