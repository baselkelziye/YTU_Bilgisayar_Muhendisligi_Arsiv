# Alt Seviye Programlama Ders Kayıtları & Çalışma Özetleri

> **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.

### 📋 Genel Bilgiler
* **Ders:** Alt Seviye Programlama
* **Hoca:** Dr. Furkan Çakmak
* **Dönem:** Güz
* **Akademik Yıl:** 2020-2021

Bu dizin, ilgili ders kayıtlarının altyazı özetlerini, çalışma notlarını ve PDF kaynaklarını içermektedir.

## 📚 Ders Müfredatı ve Belge Dizini

Aşağıdaki tabloda her bir dersin konusu, kaynak markdown dosyası ve doğrudan indirilebilir PDF formatındaki derlenmiş halleri listelenmiştir.

| Ders No | Ders İçeriği / Konu Başlıkları | Kaynak Notlar (Markdown) | Çalışma Dosyası (PDF) |
| :---: | :--- | :---: | :---: |
| **Ders 1** | Assembly Diline Giriş ve 8086 Mimarisi | [Özet](altyazi_ozetleri/ders_1_ozet.md) | [PDF (İndir)](ders_1_ozet.pdf) |
| **Ders 2** | Fiziksel Adres Hesaplama ve Veri Tanımlama | [Özet](altyazi_ozetleri/ders_2_ozet.md) | [PDF (İndir)](ders_2_ozet.pdf) |
| **Ders 3** | Dallanma, Karşılaştırma ve Matematiksel İşlemler | [Özet](altyazi_ozetleri/ders_3_ozet.md) | [PDF (İndir)](ders_3_ozet.pdf) |
| **Ders 5** | Öteleme ve Döndürme Komutları | [Özet](altyazi_ozetleri/ders_5_ozet.md) | [PDF (İndir)](ders_5_ozet.pdf) |
| **Ders 6** | Adresleme Kipleri ve İşaretçiler | [Özet](altyazi_ozetleri/ders_6_ozet.md) | [PDF (İndir)](ders_6_ozet.pdf) |
| **Ders 7** | Bellek Segmentleri ve Yığın (Stack) Mantığı | [Özet](altyazi_ozetleri/ders_7_ozet.md) | [PDF (İndir)](ders_7_ozet.pdf) |
| **Ders 9** | Döngüler ve Yığın İşlemleri | [Özet](altyazi_ozetleri/ders_9_ozet.md) | [PDF (İndir)](ders_9_ozet.pdf) |
| **Ders 10** | Alt Programlar (Procedures) ve Makrolar | [Özet](altyazi_ozetleri/ders_10_ozet.md) | [PDF (İndir)](ders_10_ozet.pdf) |
| **Ders 11** | Parametre Aktarma Yöntemleri | [Özet](altyazi_ozetleri/ders_11_ozet.md) | [PDF (İndir)](ders_11_ozet.pdf) |
| **Ders 12** | Kesmeler (Interrupts) ve BIOS/DOS Servisleri | [Özet](altyazi_ozetleri/ders_12_ozet.md) | [PDF (İndir)](ders_12_ozet.pdf) |
| **Ders 13** | Donanımsal Kesmeler ve Kesme Denetleyicisi | [Özet](altyazi_ozetleri/ders_13_ozet.md) | [PDF (İndir)](ders_13_ozet.pdf) |
| **Ders 14** | Assembly ve Yüksek Seviyeli Diller - 1 (Inline Assembly) | [Özet](altyazi_ozetleri/ders_14_ozet.md) | [PDF (İndir)](ders_14_ozet.pdf) |
| **Ders 14.1** | Assembly ve Yüksek Seviyeli Diller - 2 (External Modules & Linking) | [Özet](altyazi_ozetleri/ders_14_1_ozet.md) | [PDF (İndir)](ders_14_1_ozet.pdf) |

> [!NOTE]
> Müfredat akışına göre *Ders 4* (29 Ekim Cumhuriyet Bayramı resmi tatili) ve *Ders 8* (vize haftası) tarihlerinde ders işlenmemiş veya kayıt alınmamıştır.

## 🎯 Derslerin Detaylı Özetleri ve Kazanımları

### 🔹 Ders 1: Assembly Diline Giriş ve 8086 Mimarisi
* **Genel Konular:**
  - Alt seviye programlama ve Assembly dillerine giriş
    - Yüksek seviyeli dillerin aksine donanım mimarisine doğrudan bağımlı olan programlama yapısı tanıtılır.
  - 8086 mikroişlemci mimarisi ve yazmaçlar
    - Register (yazmaç) kavramı ve genel amaçlı yazmaçların (AX, BX, CX, DX) görevleri açıklanır.
  - Segment yapısı ve hafıza organizasyonu
    - CS, DS, SS, ES segment yazmaçları ile bellek alanlarının bölümlenmesi anlatılır.
  - Kod ve veri ayrımı
    - Alt seviye programlamanın en temel prensiplerinden biri olan kod ve verinin hafızada farklı bölgelerde tutulması ele alınır.
* **Hocanın Vurgusu:**
  - Assembly dillerinin donanıma doğrudan erişim gücü
    - Doğrudan erişimin sağladığı hız ve esnekliğin yanında getirdiği sorumluluklar.
  - Registerların kısıtlı kaynaklar olması
    - Belleğe kıyasla son derece sınırlı olan bu yazmaçların verimli şekilde yönetilmesi gerekliliği.
  - Hafızaya doğrudan erişimlerin taşıdığı riskler
    - Hatalı adreslemelerin program veya sistem kararsızlığına yol açabileceği uyarısı.
* **Detaylı Açıklamalar:** Assembly dilleri, yüksek seviyeli dillerin aksine donanım mimarisine doğrudan bağımlıdır. 8086 mikroişlemcisi, 16-bitlik bir mimariye sahiptir ve x86 mimarisinin temelini oluşturur. İşlemci içinde genel amaçlı yazmaçlar (AX, BX, CX, DX) bulunur. AX (Accumulator) aritmetik işlemler, BX (Base) adresleme işlemleri, CX (Counter) döngü sayaçları, DX (Data) ise giriş/çıkış ve büyük çarpma/bölme işlemleri için özelleşmiştir. Hafıza organizasyonunda segment-offset yapısı (Segmentation) kullanılır. CS (Code Segment) kod alanını, DS (Data Segment) veri alanını, SS (Stack Segment) yığın alanını ve ES (Extra Segment) ek veri alanlarını gösterir. Kod ve veri alanlarının birbirinden fiziksel veya mantıksal olarak ayrılması, güvenlik ve program bütünlüğü açısından kritik bir alt seviye programlama prensibidir.
* **NotebookLM Çalışma Notu:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM veya benzeri bir yapay zeka aracına yükleyerek ders üzerinde daha verimli çalışabilirsiniz.

### 🔹 Ders 2: Fiziksel Adres Hesaplama ve Veri Tanımlama
* **Genel Konular:**
  - Fiziksel adres hesaplama mantığı
    - 8086'nın 20-bit adres hattına erişim için kullanılan Segment * 16 + Offset (Segment << 4 + Offset) formülü anlatılır.
  - Veri tanımlama direktifleri
    - Bellekte veri saklamak için kullanılan DB (Define Byte - 8 bit) ve DW (Define Word - 16 bit) direktifleri tanıtılır.
  - Değişken tanımlama kuralları ve bellek yerleşimi
    - Değişken isimlerinin sayıyla başlayamaması ve hex sayılarda harfle başlayan değerlerin başına sıfır (0) konulması kuralı (örn. 0Ah) açıklanır.
* **Hocanın Vurgusu:**
  - Fiziksel adrese erişim mekanizması ve segment sınırları
    - Her segmentin en fazla 64 KB veri/kod barındırabileceği ve bu sınırın aşılmaması gerektiği.
  - Veri boyutu belirleme
    - Değişken bildirimlerinde veri boyutlarının (Byte ve Word) doğru belirlenmesinin bellek tasarrufu ve işlem doğruluğu için önemi.
  - Hexadecimal gösterim kuralları
    - Harfle başlayan hex değerlerin derleyici tarafından değişken olarak algılanmaması için prefix ve suffix kurallarına dikkat edilmesi gerektiği.
* **Detaylı Açıklamalar:** 8086 işlemcisi 20-bitlik adres hattına (1 MB adres uzayı) sahip olmasına rağmen registerları 16-bittir. Bu nedenle 1 MB'lık fiziksel belleğe erişebilmek için segmentasyon tekniği kullanılır. Fiziksel Adres = (Segment * 16) + Offset (veya Segment << 4 + Offset) formülüyle hesaplanır. Bellekte veri tanımlamak için DB (Define Byte - 8 bit) ve DW (Define Word - 16 bit) direktifleri kullanılır. Değişken tanımlamalarında isimlerin rakamla başlayamaması, büyük/küçük harf duyarlılığı (derleyiciye bağlı) ve hexadecimal değerlerde harfle başlayan sayıların başına sıfır (0) konulması zorunluluğu gibi kurallar mevcuttur. Örneğin, 0AH yazılmazsa derleyici bunu AH register'ı veya bir değişken adı olarak algılayıp hata verecektir.
* **NotebookLM Çalışma Notu:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM veya benzeri bir yapay zeka aracına yükleyerek ders üzerinde daha verimli çalışabilirsiniz.

### 🔹 Ders 3: Dallanma, Karşılaştırma ve Matematiksel İşlemler
* **Genel Konular:**
  - Dallanma ve Karşılaştırma komutları
    - Koşulsuz dallanma (JMP) ve koşullu dallanma (JE, JNE, JZ, JNZ, JG, JL vb.) komutları tanıtılır.
  - Matematiksel ve mantıksal işlemler
    - ADD, SUB, MUL, DIV, AND, OR, XOR, NOT gibi temel ALU komutları ele alınır.
  - Karşılaştırma (CMP) komutu ve Flags register'ının rolü
    - CMP komutunun çıkarma işlemi yapıp sonucu kaydetmeden sadece durum bayraklarını (ZF, SF, OF vb.) güncellemesi anlatılır.
* **Hocanın Vurgusu:**
  - Koşullu dallanmaların Flags register'ı üzerindeki bit durumlarına bağlılığı
    - Akış kontrolünün tamamen durum bayraklarındaki bitlerin (0 veya 1) durumuna göre yönlendirildiği.
  - Çarpma (MUL) ve bölme (DIV) işlemlerinde örtük register kullanımı
    - 8-bit veya 16-bit işlemlerine göre AX, DX:AX gibi registerların otomatik olarak seçilmesi ve oluşabilecek taşma durumları.
  - Kod okunabilirliği ve akışı
    - Dallanma bloklarının karmaşıklığı önleyecek şekilde düzenli yapılandırılması gerektiği.
* **Detaylı Açıklamalar:** Assembly'de akış kontrolü dallanma (Branching) komutları ile sağlanır. Koşulsuz dallanma için JMP komutu kullanılırler, koşullu dallanmalar (JE, JNE, JZ, JNZ, JG, JL, JGE, JLE) Flags register'ındaki durum bitlerini (Zero Flag - ZF, Sign Flag - SF, Overflow Flag - OF vb.) kontrol eder. Karşılaştırma işlemi CMP Hedef, Kaynak komutuyla yapılır. Bu komut, hedef değerden kaynak değeri çıkararak Flags register'ını günceller ancak sonucu kaydetmez. Matematiksel işlemlerden ADD ve SUB toplama ve çıkarma yaparken, MUL (işaretsiz çarpma) ve DIV (işaretsiz bölme) komutları örtük register kullanımı gerektirir. Örneğin, 8-bitlik çarpmada çarpan AL ile çarpılır, sonuç AX'e yazılır; 16-bitlik çarpmada AX ile çarpılır, sonuç DX:AX yazmaç ikilisinde tutulur. Bölme işleminde ise tam tersi bir bölünen yerleşimi mevcuttur ve sıfıra bölme hatası (Divide Overflow) donanımsal bir kesme tetikler.
* **NotebookLM Çalışma Notu:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM veya benzeri bir yapay zeka aracına yükleyerek ders üzerinde daha verimli çalışabilirsiniz.

### 🔹 Ders 5: Öteleme ve Döndürme Komutları
* **Genel Konular:**
  - Öteleme (Shift) ve döndürme (Rotate) komutları
    - SHL, SHR, SAR, SAL, ROL, ROR, RCL, RCR komutlarının çalışması incelenir.
  - Mantıksal ve aritmetik öteleme farkları
    - Mantıksal ötelemede boşalan bitlere sıfır doldurulurken, aritmetik ötelemede işaret bitinin (MSB) korunması farkı ele alınır.
  - Öteleme komutlarının hızlı çarpma ve bölme işlemlerinde kullanımı
    - 2'nin kuvvetleriyle çarpmada sola, bölmede sağa öteleme yapmanın hızı anlatılır.
* **Hocanın Vurgusu:**
  - Aritmetik sağa ötelemede (SAR) işaret bitinin (MSB) korunması
    - İşaretli sayılarda bölme yapılırken sayısal değerin işaretinin korunması için bu komutun şart olduğu.
  - Döndürme komutlarında elde (carry) bitinin rolü
    - ROL/ROR ile RCL/RCR arasındaki farkın carry bayrağının (CF) döngüye dahil edilmesiyle oluştuğu.
  - Performans kritik uygulamalarda çarpma/bölme yerine öteleme kullanımı
    - Öteleme komutlarının işlemci saat çevrimi (T-states) açısından MUL/DIV komutlarına kıyasla katbekat daha hızlı çalışması.
* **Detaylı Açıklamalar:** Öteleme (Shift) ve döndürme (Rotate) komutları, bit seviyesinde veri işleme, maskeleme ve hızlı matematiksel işlemler için kullanılır. SHL (Shift Left) ve SHR (Shift Right) mantıksal öteleme yaparken dışarıdan sıfır biti besler. SAL (Shift Arithmetic Left) mantıksal sola ötelemeyle aynı çalışırken, SAR (Shift Arithmetic Right) en anlamlı biti (işaret bitini - MSB) koruyarak sağa öteleme yapar. Bu durum, işaretli sayıları 2'ye bölmek için kritiktir. Döndürme komutlarında ROL (Rotate Left) ve ROR (Rotate Right) bitleri dairesel olarak kaydırır. RCL (Rotate through Carry Left) ve RCR (Rotate through Carry Right) komutları ise Carry Flag (CF) bitini de döngüye dahil eder. Öteleme komutları, çarpma (MUL) ve bölme (DIV) komutlarına kıyasla çok daha az saat çevrimi (T-states) harcadığı için 2'nin kuvvetleriyle yapılan işlemlerde optimizasyon amaçlı tercih edilir.
* **NotebookLM Çalışma Notu:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM veya benzeri bir yapay zeka aracına yükleyerek ders üzerinde daha verimli çalışabilirsiniz.

### 🔹 Ders 6: Adresleme Kipleri ve İşaretçiler
* **Genel Konular:**
  - 8086 Adresleme Kipleri (Addressing Modes)
    - Immediate, Register, Direct, Register Indirect, Based, Indexed ve Based Indexed adresleme yöntemleri açıklanır.
  - OFFSET direktifi ve işaretçiler (pointers)
    - Bir değişkenin başlangıç adresini (segment içindeki offsetini) alma ve bellek adreslerini işaretçilerle yönetme yolları ele alınır.
  - Bellekteki verilere esnek erişim yöntemleri
    - Diziler veya yapılar gibi veri kümelerine indeks yazmaçları (SI, DI) kullanarak erişim anlatılır.
* **Hocanın Vurgusu:**
  - Adresleme kiplerinin esnekliği
    - Diziler ve tablolara erişimde indexed veya based-indexed adreslemenin sunduğu büyük pratiklik.
  - Pointer aritmetiği ve veri boyutu belirteçleri
    - Bellek adresindeki verinin boyutunu derleyiciye bildirmek için kullanılan BYTE PTR veya WORD PTR belirteçlerinin önemi.
  - Performans farkları
    - Hangi adresleme kipinin hangi bellek erişim süresi (saat çevrimi) maliyetini getirdiği.
* **Detaylı Açıklamalar:** Adresleme kipleri, işlemcinin bellekteki operandlara nasıl erişeceğini belirler. En temel kipler immediate (doğrudan sabit değer), register (yazmaçtaki değer) ve direct (doğrudan adres) adreslemedir. Daha karmaşık veri yapıları için dolaylı adresleme yöntemleri kullanılır: register indirect (BX, BP, SI, DI registerları ile adresleme), based (BX veya BP ile bir taban adrese göre adresleme), indexed (SI veya DI ile dizin adresleme) ve based-indexed (taban ve dizin yazmaçlarının toplamıyla adresleme). Offset direktifi, bir değişkenin tanımlandığı veri segmentindeki başlangıç adresini (offset değerini) almak için kullanılır. İşaretçiler (pointers) tanımlanırken verinin boyutu BYTE PTR veya WORD PTR belirteçleriyle derleyiciye bildirilmelidir. Bu belirteçler, bellek adresindeki verinin kaç byte olarak okunacağını veya yazılacağını netleştirir.
* **NotebookLM Çalışma Notu:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM veya benzeri bir yapay zeka aracına yükleyerek ders üzerinde daha verimli çalışabilirsiniz.

### 🔹 Ders 7: Bellek Segmentleri ve Yığın (Stack) Mantığı
* **Genel Konular:**
  - Data Segment ve Stack Segment yapısı
    - Program şablonundaki bellek alanlarının işlevleri anlatılır.
  - Stack (Yığın) mimarisi ve işlemleri
    - LIFO (Last In First Out) mantığı ile çalışan yığında PUSH ve POP komutlarının kullanımı açıklanır.
  - Değişkenlerin hafızadaki yerleşimi
    - Başlangıç değeri verilmeyen değişkenler için '?' kullanımı ve bellek hizalaması (alignment) ele alınır.
* **Hocanın Vurgusu:**
  - Stack segmentinin çalışma mantığı
    - Yığının yukarıdan aşağıya (düşük adreslere doğru) büyümesi ve SP (Stack Pointer) register'ının bu doğrultuda yönetimi.
  - SP register'ının yönetimi
    - Her PUSH işleminde SP'nin 2 azalması, her POP işleminde ise 2 artması kuralı.
  - Başlangıç değeri atanmamış değişkenlerin bellek yerleşimi
    - Program boyutunu küçültmek amacıyla veri alanında sadece yer ayırma prensibi.
* **Detaylı Açıklamalar:** Hafıza segmentleri, kod ve verinin mantıksal olarak ayrılmasını sağlar. Program şablonunda .CODE, .DATA ve .STACK direktifleri ile bu bölümler tanımlanır. Başlangıç değeri atanmayan değişkenler için ? sembolü kullanılarak sadece yer ayrılması sağlanır. Yığın (Stack) belleği, LIFO (Last In First Out - Son Giren İlk Çıkar) prensibiyle çalışan geçici bir depolama alanıdır. Stack işlemleri PUSH ve POP komutları ile yürütülür. PUSH komutu SP'yi (Stack Pointer) 2 azaltarak veriyi yığına yazar; POP komutu ise yığından veriyi okuyup SP'yi 2 artırır. Yığın, fonksiyon çağrılarında geri dönüş adreslerini saklamak, register durumlarını korumak ve lokal değişkenler oluşturmak için donanım tarafından otomatik olarak da kullanılır.
* **NotebookLM Çalışma Notu:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM veya benzeri bir yapay zeka aracına yükleyerek ders üzerinde daha verimli çalışabilirsiniz.

### 🔹 Ders 9: Döngüler ve Yığın İşlemleri
* **Genel Konular:**
  - Döngü yapıları ve LOOP komutu
    - LOOP komutunun CX register'ını otomatik olarak bir azaltarak sıfır olana kadar dallanma yapması anlatılır.
  - Koşullu döngüler
    - Zero Flag (ZF) durumuna da bakan LOOPE/LOOPZ ve LOOPNE/LOOPNZ komutları tanıtılır.
  - Yığın işlemlerinin döngülerle birleşimi
    - İç içe döngülerde veya döngü içinde register durumlarını korumak için stack kullanımı gösterilir.
* **Hocanın Vurgusu:**
  - LOOP komutunun CX register'ına bağımlılığı
    - Döngü sayacının otomatik olarak CX üzerinden yönetildiği ve CX'in manuel değiştirilmesinin döngü akışını etkileyeceği.
  - Büyük döngülerde veya iç içe döngülerde register çakışmalarını önlemek
    - İç içe döngülerde dış döngünün CX değerini bozmamak için yığına (stack) PUSH edilip iç döngü çıkışında POP edilmesinin kritik önemi.
* **Detaylı Açıklamalar:** Assembly'de döngüler LOOP komutu ile kurulur. LOOP Hedef komutu çalıştırıldığında, CX register'ının değeri otomatik olarak 1 azaltılır. Eğer CX sıfır değilse, belirtilen hedef etikete kısa dallanma (short jump -128 ile +127 byte sınırlarında) yapılır. Koşullu döngüler olan LOOPE/LOOPZ (Zero Flag 1 ve CX sıfır değilse döngüye devam et) ve LOOPNE/LOOPNZ (Zero Flag 0 ve CX sıfır değilse döngüye devam et) daha karmaşık arama ve karşılaştırma döngülerinde kullanılır. Döngülerin içinde register çakışmalarını (özellikle CX'in iç içe döngülerde bozulmasını) engellemek için dış döngünün sayacı stack'e push edilir, iç döngü bittiğinde pop edilerek geri yüklenir.
* **NotebookLM Çalışma Notu:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM veya benzeri bir yapay zeka aracına yükleyerek ders üzerinde daha verimli çalışabilirsiniz.

### 🔹 Ders 10: Alt Programlar (Procedures) ve Makrolar
* **Genel Konular:**
  - Alt programlar (Procedures) ve modüler programlama
    - PROC, CALL ve RET komutları ile alt program yapısı ve programın parçalara ayrılması ele alınır.
  - Makro (MACRO) tanımı ve kullanımı
    - Makro tanımlama kuralları ve parametrik makro yapısı anlatılır.
  - Alt program ve makro arasındaki temel farklar
    - Kod boyutu, çalışma süresi, stack kullanımı ve derleyici seviyesindeki açılımlar üzerinden karşılaştırma yapılır.
* **Hocanın Vurgusu:**
  - Alt program çağrılarında geri dönüş adresinin stack'e kaydedilmesi
    - CALL komutunun sonraki talimat adresini stack'e atıp RET komutunun bu adresi stack'ten geri yüklemesi süreci.
  - Makroların derleme aşamasında kod açılımı yapması
    - Makronun koda doğrudan kopyalanarak çalışma zamanında dallanma maliyeti getirmemesi, buna karşılık program boyutunu büyütmesi (Macro Expansion).
* **Detaylı Açıklamalar:** Alt programlar (Procedures) ve makrolar, kodun modülerliğini ve tekrar kullanılabilirliğini sağlar. Yordamlar PROC direktifi ile tanımlanır, CALL komutuyla çağrılır ve RET komutuyla sonlandırılır. CALL komutu, bir sonraki talimatın adresini (IP veya CS:IP) stack'e kaydeder ve yordamın başlangıç adresine dallanır; RET ise bu adresi stack'ten çekip IP'ye geri yazar. Makrolar ise MACRO direktifi ile tanımlanır. Derleyici, makro çağrılarını gördüğü her yerde makro içeriğini doğrudan kodun içine yapıştırır (Macro Expansion). Makrolar çalışma zamanında (runtime) alt program çağırma maliyeti (stack ve dallanma süresi) getirmez ancak kod boyutunu büyütür. Yordamlar ise bellek tasarrufu sağlar fakat stack yönetimi ve dallanma maliyeti barındırır.
* **NotebookLM Çalışma Notu:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM veya benzeri bir yapay zeka aracına yükleyerek ders üzerinde daha verimli çalışabilirsiniz.

### 🔹 Ders 11: Parametre Aktarma Yöntemleri
* **Genel Konular:**
  - Alt programlara parametre aktarma yöntemleri
    - Registerlar aracılığıyla, ortak bellek alanları (global değişkenler) veya yığın (stack) yardımıyla parametre geçişi anlatılır.
  - Stack frame oluşturma
    - BP (Base Pointer) register'ı kullanılarak stack üzerinde her fonksiyon çağrısı için oluşturulan yerel çalışma alanı açıklanır.
  - Yığındaki parametrelere erişim
    - Parametrelere göreli adresleme ile ([BP+4], [BP+6] vb.) erişim mantığı ele alınır.
* **Hocanın Vurgusu:**
  - Stack üzerinden parametre aktarımının avantajları
    - Rekürsif (öz yinelemeli) ve çoklu yordam çağrılarında register çakışmasını önleyen en güvenli yöntem olması.
  - Stack temizleme sorumluluğu
    - Yordam çağrısından sonra stack'in temizlenmesinin çağıran (caller - ADD SP, X) veya çağrılan (callee - RET X) tarafından yapılması kuralı.
  - BP register'ının stack frame taban noktası rolü
    - MOV BP, SP ile frame sınırının belirlenmesi ve SP değişse bile parametrelere sabit mesafeyle erişim kolaylığı.
* **Detaylı Açıklamalar:** Alt programlara parametre aktarımı üç temel yöntemle yapılır: registerlar üzerinden (hızlı ama sınırlı sayıda), ortak bellek alanları (global değişkenler) üzerinden (modülerliği azaltır) ve stack (yığın) üzerinden (güvenli ve sınırsız). Stack üzerinden parametre aktarımında, çağıran program parametreleri sırayla stack'e push eder ve ardından CALL komutunu çalıştırır. Yordam içinde, parametrelere ve lokal değişkenlere erişmek için BP (Base Pointer) register'ı kullanılır. BP değeri stack frame'in taban noktası olarak belirlenir (MOV BP, SP ile). Yordam sonlandığında stack'in temizlenmesi gerekir. Bu temizlik, çağıran program tarafından (ADD SP, X ile) veya yordamın kendisi tarafından (RET X komutuyla) gerçekleştirilir.
* **NotebookLM Çalışma Notu:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM veya benzeri bir yapay zeka aracına yükleyerek ders üzerinde daha verimli çalışabilirsiniz.

### 🔹 Ders 12: Kesmeler (Interrupts) ve BIOS/DOS Servisleri
* **Genel Konular:**
  - Kesmeler (Interrupts) ve Kesme Vektör Tablosu (IVT)
    - Kesme kavramı, IVT'nin bellekteki konumu (ilk 1 KB) ve yapısı anlatılır.
  - Yazılımsal kesmeler (INT komutu)
    - BIOS ve DOS servislerini çağıran INT 21h, INT 10h gibi sistem kesmeleri ele alınır.
  - Kesmelerin çalışma mantığı
    - Kesme tetiklendiğinde Flags, CS ve IP registerlarının otomatik olarak stack'e atılması ve Kesme Servis Yordamına (ISR) dallanma süreci açıklanır.
* **Hocanın Vurgusu:**
  - IVT'nin 00000h - 003FFh arasındaki sabit adresi
    - Her bir kesme için 4 byte'lık (2 byte Segment, 2 byte Offset) adres vektörü tuttuğu bilgisi.
  - ISR sonundaki IRET komutunun rolü
    - Stack'e atılan Flags, CS ve IP değerlerini geri yükleyerek kesme öncesindeki ana program akışına güvenli dönüş sağladığı.
* **Detaylı Açıklamalar:** Kesmeler (Interrupts), işlemcinin normal akışını keserek öncelikli bir görevi (Kesme Servis Yordamı - ISR) yürütmesini sağlayan mekanizmalardır. 8086 mimarisinde belleğin ilk 1 KB'lık kısmı (00000h - 003FFh) Kesme Vektör Tablosu (Interrupt Vector Table - IVT) olarak ayrılmıştır. IVT, 256 adet kesmenin her biri için 4 byte'lık CS:IP adres bilgisini tutar. Yazılımsal kesmeler INT N komutuyla tetiklenir. Örneğin INT 21h, DOS işletim sistemi servislerini (ekrana karakter yazma, klavyeden okuma, dosya işlemleri) çağırmak için kullanılır. Kesme tetiklendiğinde işlemci sırasıyla Flags register'ını, CS ve IP değerlerini stack'e push eder, kesme koduna karşılık gelen adresi IVT'den okuyarak oraya dallanır. ISR sonundaki IRET komutu stack'teki değerleri geri yükleyerek ana programa dönüş sağlar.
* **NotebookLM Çalışma Notu:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM veya benzeri bir yapay zeka aracına yükleyerek ders üzerinde daha verimli çalışabilirsiniz.

### 🔹 Ders 13: Donanımsal Kesmeler ve Kesme Denetleyicisi
* **Genel Konular:**
  - Donanımsal kesmelerin asenkron yapısı
    - Dış çevre birimlerinden (klavye, zamanlayıcı vb.) gelen kesme sinyalleri ele alınır.
  - Kesme denetleyicisi (8259 PIC)
    - Çoklu donanımsal kesmeleri ve bunların öncelik sıralamasını yöneten donanım yongası anlatılır.
  - STI ve CLI komutları ile kesme kontrolü
    - CLI ile kesmelerin maskelenmesi (kapatılması) ve STI ile tekrar açılması işlemleri gösterilir.
* **Hocanın Vurgusu:**
  - Donanımsal kesmelerin program akışından bağımsız (asenkron) oluşu
    - Herhangi bir kod satırında aniden tetiklenebilme özelliği.
  - Kritik kod bloklarında CLI ile kesmelerin kapatılması gerekliliği
    - Bölünmemesi gereken hassas işlemler (örn. kesme vektörü güncelleme) sırasında kesmelerin CLI ile kapatılıp sonrasında STI ile açılması.
  - Maskelenebilir (INTR) ve maskelenemez (NMI) kesme ayrımı
    - Hayati donanım hatalarının NMI pini üzerinden maskelenemez şekilde işlemciye doğrudan iletildiği.
* **Detaylı Açıklamalar:** Donanımsal kesmeler, klavye, zamanlayıcı veya disk gibi dış donanım birimlerinden gelen asenkron sinyallerdir. Bu kesmeler işlemcinin INTR (Interrupt Request) veya NMI (Non-Maskable Interrupt) pinleri üzerinden iletilir. Çoklu donanım kesmelerini ve önceliklerini yönetmek için 8259A PIC (Programmable Interrupt Controller - Programlanabilir Kesme Denetleyicisi) yongası kullanılır. CLI (Clear Interrupt Flag) komutuyla maskelenebilir kesmeler (INTR) devre dışı bırakılırken, STI (Set Interrupt Flag) komutuyla tekrar etkinleştirilir. NMI ise hayati donanım hataları için kullanılır ve maskelenemez (CLI'dan etkilenmez).
* **NotebookLM Çalışma Notu:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM veya benzeri bir yapay zeka aracına yükleyerek ders üzerinde daha verimli çalışabilirsiniz.

### 🔹 Ders 14: Assembly ve Yüksek Seviyeli Diller - 1 (Inline Assembly)
* **Genel Konular:**
  - Assembly dilinin yüksek seviyeli programlama dilleri (C/C++) ile birlikte kullanımı
    - Geliştirme kolaylığı ile donanım kontrolünün birleştirilmesi mantığı ele alınır.
  - Inline Assembly (satır içi assembly) yazım kuralları
    - C kodu içinde `__asm` veya `asm` anahtar kelimeleriyle assembly blokları oluşturma gösterilir.
  - Register ve değişken paylaşımları
    - C değişkenlerine assembly komutlarıyla doğrudan erişim ve veri transferi kuralları anlatılır.
* **Hocanın Vurgusu:**
  - Inline assembly'nin sağladığı hız ve optimizasyon avantajları
    - Görüntü işleme, kriptografi veya sürücü tasarımı gibi kritik kısımların optimize edilmesi.
  - Derleyici optimizasyonları ile çakışma riskleri
    - Derleyicinin register tahsis kararlarıyla inline assembly kodundaki register kullanımının çakışmaması için dikkat edilmesi gereken kurallar.
* **Detaylı Açıklamalar:** Yüksek seviyeli diller (C/C++ gibi) geliştirme kolaylığı sağlarken, Assembly dili maksimum donanım kontrolü ve hız sunar. Bu iki dünyayı birleştirmek için Inline Assembly (satır içi assembly) kullanılır. C/C++ kodu içinde __asm veya asm anahtar kelimeleriyle assembly blokları açılır. Bu sayede C değişkenlerine doğrudan assembly komutlarıyla erişilebilir, registerlar manipüle edilebilir. Inline assembly, özellikle görüntü işleme filtreleri, kriptografik algoritmalar veya donanım sürücüsü yazımı gibi performans kritik kısımları optimize etmek için tercih edilir. Ancak derleyicinin register tahsis (register allocation) optimizasyonları ile çakışmamak için kullanılan registerların bildirilmesi önemlidir.
* **NotebookLM Çalışma Notu:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM veya benzeri bir yapay zeka aracına yükleyerek ders üzerinde daha verimli çalışabilirsiniz.

### 🔹 Ders 14.1: Assembly ve Yüksek Seviyeli Diller - 2 (External Modules & Linking)
* **Genel Konular:**
  - Harici modüller (External Modules) ve Linking
    - Ayrı `.asm` dosyalarında yazılan assembly kodlarının derlenip C/C++ projelerine bağlanması (linking) süreci anlatılır.
  - Assembly fonksiyonlarının C tarafından çağrılması
    - C tarafında `extern` anahtar kelimesiyle fonksiyon bildirimi ve linker aşaması ele alınır.
  - Çağırma konvansiyonları (Calling Conventions)
    - Cdecl, Stdcall ve Fastcall kuralları, parametrelerin stack'e yerleştirilme sırası ve stack temizliği karşılaştırılır.
* **Hocanın Vurgusu:**
  - Çağırma kurallarının (Calling Conventions) hayati önemi
    - Çağıran ve çağrılan taraflar arasında stack temizliği ve parametre sırası uyumsuzluğunun program çökmesine yol açacağı.
  - Harici fonksiyon isimlerindeki alt çizgi (_) kuralı
    - Derleyicinin fonksiyon adlarının başına otomatik alt çizgi eklemesi nedeniyle assembly tarafında isimlerin bu kurala uygun tanımlanması ve `PUBLIC` yapılması zorunluluğu.
* **Detaylı Açıklamalar:** Harici modül kullanımı, assembly kodunun ayrı bir .asm dosyasında yazılıp derlenerek C/C++ projesine bağlanması (linking) yöntemidir. Bu yöntemde çağırma kuralları (Calling Conventions: Cdecl, Stdcall, Fastcall) hayati önem taşır. Cdecl kuralında parametreler sağdan sola stack'e push edilir ve stack temizliği çağıran (caller) fonksiyon tarafından yapılır; Stdcall'da ise stack temizliği çağrılan (callee) fonksiyon tarafından RET X ile yapılır. C derleyicisinin harici fonksiyon isimlerinin başına alt çizgi (_) ekleme alışkanlığı nedeniyle assembly tarafındaki fonksiyon adları bu kurala uygun tanımlanmalı ve PUBLIC direktifiyle dışa aktarılmalıdır. C tarafında ise bu fonksiyonlar extern anahtar kelimesiyle bildirilir.
* **NotebookLM Çalışma Notu:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM veya benzeri bir yapay zeka aracına yükleyerek ders üzerinde daha verimli çalışabilirsiniz.

