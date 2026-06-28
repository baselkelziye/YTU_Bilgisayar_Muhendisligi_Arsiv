# Alt Seviye Programlama Ders Kayıtları & Çalışma Özetleri

> **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi daha verimli çalışabilirsiniz.

### Genel Bilgiler

* **Ders:** Alt Seviye Programlama
* **Hoca:** Dr. Furkan Çakmak
* **Dönem:** Güz
* **Akademik Yıl:** 2020-2021

Bu dizin, ilgili ders kayıtlarının altyazı özetlerini, çalışma notlarını ve PDF kaynaklarını içermektedir.

## Ders Müfredatı ve Belge Dizini

Aşağıdaki tabloda her bir dersin konusu, kaynak markdown dosyası ve doğrudan indirilebilir PDF formatındaki derlenmiş halleri listelenmiştir.

| Ders No | Ders İçeriği / Konu Başlıkları | Kaynak Notlar (Markdown) | Çalışma Dosyası (PDF) |
| :---: | :--- | :---: | :---: |
| **Ders 1** | Alt seviye programlama ve Assembly dillerine giriş | [Özet](altyazi_ozetleri/ders_1_ozet.md) | [PDF (İndir)](ders_1_ozet.pdf) |
| **Ders 2** | Fiziksel adres hesaplama mantığı | [Özet](altyazi_ozetleri/ders_2_ozet.md) | [PDF (İndir)](ders_2_ozet.pdf) |
| **Ders 3** | Dallanma ve Karşılaştırma komutları | [Özet](altyazi_ozetleri/ders_3_ozet.md) | [PDF (İndir)](ders_3_ozet.pdf) |
| **Ders 5** | Öteleme (Shift) ve döndürme (Rotate) komutları | [Özet](altyazi_ozetleri/ders_5_ozet.md) | [PDF (İndir)](ders_5_ozet.pdf) |
| **Ders 6** | 8086 Adresleme Kipleri (Addressing Modes) | [Özet](altyazi_ozetleri/ders_6_ozet.md) | [PDF (İndir)](ders_6_ozet.pdf) |
| **Ders 7** | Data Segment ve Stack Segment yapısı | [Özet](altyazi_ozetleri/ders_7_ozet.md) | [PDF (İndir)](ders_7_ozet.pdf) |
| **Ders 9** | Döngü yapıları ve LOOP komutu | [Özet](altyazi_ozetleri/ders_9_ozet.md) | [PDF (İndir)](ders_9_ozet.pdf) |
| **Ders 10** | Alt programlar (Procedures) ve modüler programlama | [Özet](altyazi_ozetleri/ders_10_ozet.md) | [PDF (İndir)](ders_10_ozet.pdf) |
| **Ders 11** | Alt programlara parametre aktarma yöntemleri | [Özet](altyazi_ozetleri/ders_11_ozet.md) | [PDF (İndir)](ders_11_ozet.pdf) |
| **Ders 12** | Kesmeler (Interrupts) ve Kesme Vektör Tablosu (IVT) | [Özet](altyazi_ozetleri/ders_12_ozet.md) | [PDF (İndir)](ders_12_ozet.pdf) |
| **Ders 13** | Donanımsal kesmelerin asenkron yapısı | [Özet](altyazi_ozetleri/ders_13_ozet.md) | [PDF (İndir)](ders_13_ozet.pdf) |
| **Ders 14** | Assembly dilinin yüksek seviyeli programlama dilleri (C/C++) ile birlikte kullanımı | [Özet](altyazi_ozetleri/ders_14_ozet.md) | [PDF (İndir)](ders_14_ozet.pdf) |
| **Ders 14 (Lab)** | Linux ortamında C programından assembly yordamı çağırma | [Özet](altyazi_ozetleri/ders_14_lab_ozet.md) | [PDF (İndir)](ders_14_lab_ozet.pdf) |
| **Ders 14 (1)** | Harici modüller (External Modules) ve Linking | [Özet](altyazi_ozetleri/ders_14_1_ozet.md) | [PDF (İndir)](ders_14_1_ozet.pdf) |

## Derslerin Detaylı Özetleri ve Kazanımları

### Ders 1: Alt seviye programlama ve Assembly dillerine giriş

#### Genel Konular

- Alt seviye programlama ve Assembly dillerine giriş
  - Yüksek seviyeli dillerin aksine donanım mimarisine doğrudan bağımlı olan programlama yapısı tanıtılır.
- 8086 mikroişlemci mimarisi ve yazmaçlar
  - Register (yazmaç) kavramı ve genel amaçlı yazmaçların (AX, BX, CX, DX) görevleri açıklanır.
- Segment yapısı ve hafıza organizasyonu
  - CS, DS, SS, ES segment yazmaçları ile bellek alanlarının bölümlenmesi anlatılır.
- Kod ve veri ayrımı
  - Alt seviye programlamanın en temel prensiplerinden biri olan kod ve verinin hafızada farklı bölgelerde tutulması ele alınır.

#### Hocanın Özellikle Vurguladığı Kısımlar

- Assembly dillerinin donanıma doğrudan erişim gücü
  - Doğrudan erişimin sağladığı hız ve esnekliğin yanında getirdiği sorumluluklar.
- Registerların kısıtlı kaynaklar olması
  - Belleğe kıyasla son derece sınırlı olan bu yazmaçların verimli şekilde yönetilmesi gerekliliği.
- Hafızaya doğrudan erişimlerin taşıdığı riskler
  - Hatalı adreslemelerin program veya sistem kararsızlığına yol açabileceği uyarısı.
### Ders 2: Fiziksel adres hesaplama mantığı

#### Genel Konular

- Fiziksel adres hesaplama mantığı
  - 8086'nın 20-bit adres hattına erişim için kullanılan Segment * 16 + Offset (Segment << 4 + Offset) formülü anlatılır.
- Veri tanımlama direktifleri
  - Bellekte veri saklamak için kullanılan DB (Define Byte - 8 bit) ve DW (Define Word - 16 bit) direktifleri tanıtılır.
- Değişken tanımlama kuralları ve bellek yerleşimi
  - Değişken isimlerinin sayıyla başlayamaması ve hex sayılarda harfle başlayan değerlerin başına sıfır (0) konulması kuralı (örn. 0Ah) açıklanır.

#### Hocanın Özellikle Vurguladığı Kısımlar

- Fiziksel adrese erişim mekanizması ve segment sınırları
  - Her segmentin en fazla 64 KB veri/kod barındırabileceği ve bu sınırın aşılmaması gerektiği.
- Veri boyutu belirleme
  - Değişken bildirimlerinde veri boyutlarının (Byte ve Word) doğru belirlenmesinin bellek tasarrufu ve işlem doğruluğu için önemi.
- Hexadecimal gösterim kuralları
  - Harfle başlayan hex değerlerin derleyici tarafından değişken olarak algılanmaması için prefix ve suffix kurallarına dikkat edilmesi gerektiği.
### Ders 3: Dallanma ve Karşılaştırma komutları

#### Genel Konular

- Dallanma ve Karşılaştırma komutları
  - Koşulsuz dallanma (JMP) ve koşullu dallanma (JE, JNE, JZ, JNZ, JG, JL vb.) komutları tanıtılır.
- Matematiksel ve mantıksal işlemler
  - ADD, SUB, MUL, DIV, AND, OR, XOR, NOT gibi temel ALU komutları ele alınır.
- Karşılaştırma (CMP) komutu ve Flags register'ının rolü
  - CMP komutunun çıkarma işlemi yapıp sonucu kaydetmeden sadece durum bayraklarını (ZF, SF, OF vb.) güncellemesi anlatılır.

#### Hocanın Özellikle Vurguladığı Kısımlar

- Koşullu dallanmaların Flags register'ı üzerindeki bit durumlarına bağlılığı
  - Akış kontrolünün tamamen durum bayraklarındaki bitlerin (0 veya 1) durumuna göre yönlendirildiği.
- Çarpma (MUL) ve bölme (DIV) işlemlerinde örtük register kullanımı
  - 8-bit veya 16-bit işlemlerine göre AX, DX:AX gibi registerların otomatik olarak seçilmesi ve oluşabilecek taşma durumları.
- Kod okunabilirliği ve akışı
  - Dallanma bloklarının karmaşıklığı önleyecek şekilde düzenli yapılandırılması gerektiği.
### Ders 5: Öteleme (Shift) ve döndürme (Rotate) komutları

#### Genel Konular

- Öteleme (Shift) ve döndürme (Rotate) komutları
  - SHL, SHR, SAR, SAL, ROL, ROR, RCL, RCR komutlarının çalışması incelenir.
- Mantıksal ve aritmetik öteleme farkları
  - Mantıksal ötelemede boşalan bitlere sıfır doldurulurken, aritmetik ötelemede işaret bitinin (MSB) korunması farkı ele alınır.
- Öteleme komutlarının hızlı çarpma ve bölme işlemlerinde kullanımı
  - 2'nin kuvvetleriyle çarpmada sola, bölmede sağa öteleme yapmanın hızı anlatılır.

#### Hocanın Özellikle Vurguladığı Kısımlar

- Aritmetik sağa ötelemede (SAR) işaret bitinin (MSB) korunması
  - İşaretli sayılarda bölme yapılırken sayısal değerin işaretinin korunması için bu komutun şart olduğu.
- Döndürme komutlarında elde (carry) bitinin rolü
  - ROL/ROR ile RCL/RCR arasındaki farkın carry bayrağının (CF) döngüye dahil edilmesiyle oluştuğu.
- Performans kritik uygulamalarda çarpma/bölme yerine öteleme kullanımı
  - Öteleme komutlarının işlemci saat çevrimi (T-states) açısından MUL/DIV komutlarına kıyasla katbekat daha hızlı çalışması.
### Ders 6: 8086 Adresleme Kipleri (Addressing Modes)

#### Genel Konular

- 8086 Adresleme Kipleri (Addressing Modes)
  - Immediate, Register, Direct, Register Indirect, Based, Indexed ve Based Indexed adresleme yöntemleri açıklanır.
- OFFSET direktifi ve işaretçiler (pointers)
  - Bir değişkenin başlangıç adresini (segment içindeki offsetini) alma ve bellek adreslerini işaretçilerle yönetme yolları ele alınır.
- Bellekteki verilere esnek erişim yöntemleri
  - Diziler veya yapılar gibi veri kümelerine indeks yazmaçları (SI, DI) kullanarak erişim anlatılır.

#### Hocanın Özellikle Vurguladığı Kısımlar

- Adresleme kiplerinin esnekliği
  - Diziler ve tablolara erişimde indexed veya based-indexed adreslemenin sunduğu büyük pratiklik.
- Pointer aritmetiği ve veri boyutu belirteçleri
  - Bellek adresindeki verinin boyutunu derleyiciye bildirmek için kullanılan BYTE PTR veya WORD PTR belirteçlerinin önemi.
- Performans farkları
  - Hangi adresleme kipinin hangi bellek erişim süresi (saat çevrimi) maliyetini getirdiği.
### Ders 7: Data Segment ve Stack Segment yapısı

#### Genel Konular

- Data Segment ve Stack Segment yapısı
  - Program şablonundaki bellek alanlarının işlevleri anlatılır.
- Stack (Yığın) mimarisi ve işlemleri
  - LIFO (Last In First Out) mantığı ile çalışan yığında PUSH ve POP komutlarının kullanımı açıklanır.
- Değişkenlerin hafızadaki yerleşimi
  - Başlangıç değeri verilmeyen değişkenler için '?' kullanımı ve bellek hizalaması (alignment) ele alınır.

#### Hocanın Özellikle Vurguladığı Kısımlar

- Stack segmentinin çalışma mantığı
  - Yığının yukarıdan aşağıya (düşük adreslere doğru) büyümesi ve SP (Stack Pointer) register'ının bu doğrultuda yönetimi.
- SP register'ının yönetimi
  - Her PUSH işleminde SP'nin 2 azalması, her POP işleminde ise 2 artması kuralı.
- Başlangıç değeri atanmamış değişkenlerin bellek yerleşimi
  - Program boyutunu küçültmek amacıyla veri alanında sadece yer ayırma prensibi.
### Ders 9: Döngü yapıları ve LOOP komutu

#### Genel Konular

- Döngü yapıları ve LOOP komutu
  - LOOP komutunun CX register'ını otomatik olarak bir azaltarak sıfır olana kadar dallanma yapması anlatılır.
- Koşullu döngüler
  - Zero Flag (ZF) durumuna da bakan LOOPE/LOOPZ ve LOOPNE/LOOPNZ komutları tanıtılır.
- Yığın işlemlerinin döngülerle birleşimi
  - İç içe döngülerde veya döngü içinde register durumlarını korumak için stack kullanımı gösterilir.

#### Hocanın Özellikle Vurguladığı Kısımlar

- LOOP komutunun CX register'ına bağımlılığı
  - Döngü sayacının otomatik olarak CX üzerinden yönetildiği ve CX'in manuel değiştirilmesinin döngü akışını etkileyeceği.
- Büyük döngülerde veya iç içe döngülerde register çakışmalarını önlemek
  - İç içe döngülerde dış döngünün CX değerini bozmamak için yığına (stack) PUSH edilip iç döngü çıkışında POP edilmesinin kritik önemi.
### Ders 10: Alt programlar (Procedures) ve modüler programlama

#### Genel Konular

- Alt programlar (Procedures) ve modüler programlama
  - PROC, CALL ve RET komutları ile alt program yapısı ve programın parçalara ayrılması ele alınır.
- Makro (MACRO) tanımı ve kullanımı
  - Makro tanımlama kuralları ve parametrik makro yapısı anlatılır.
- Alt program ve makro arasındaki temel farklar
  - Kod boyutu, çalışma süresi, stack kullanımı ve derleyici seviyesindeki açılımlar üzerinden karşılaştırma yapılır.

#### Hocanın Özellikle Vurguladığı Kısımlar

- Alt program çağrılarında geri dönüş adresinin stack'e kaydedilmesi
  - CALL komutunun sonraki talimat adresini stack'e atıp RET komutunun bu adresi stack'ten geri yüklemesi süreci.
- Makroların derleme aşamasında kod açılımı yapması
  - Makronun koda doğrudan kopyalanarak çalışma zamanında dallanma maliyeti getirmemesi, buna karşılık program boyutunu büyütmesi (Macro Expansion).
### Ders 11: Alt programlara parametre aktarma yöntemleri

#### Genel Konular

- Alt programlara parametre aktarma yöntemleri
  - Registerlar aracılığıyla, ortak bellek alanları (global değişkenler) veya yığın (stack) yardımıyla parametre geçişi anlatılır.
- Stack frame oluşturma
  - BP (Base Pointer) register'ı kullanılarak stack üzerinde her fonksiyon çağrısı için oluşturulan yerel çalışma alanı açıklanır.
- Yığındaki parametrelere erişim
  - Parametrelere göreli adresleme ile ([BP+4], [BP+6] vb.) erişim mantığı ele alınır.

#### Hocanın Özellikle Vurguladığı Kısımlar

- Stack üzerinden parametre aktarımının avantajları
  - Rekürsif (öz yinelemeli) ve çoklu yordam çağrılarında register çakışmasını önleyen en güvenli yöntem olması.
- Stack temizleme sorumluluğu
  - Yordam çağrısından sonra stack'in temizlenmesinin çağıran (caller - ADD SP, X) veya çağrılan (callee - RET X) tarafından yapılması kuralı.
- BP register'ının stack frame taban noktası rolü
  - MOV BP, SP ile frame sınırının belirlenmesi ve SP değişse bile parametrelere sabit mesafeyle erişim kolaylığı.
### Ders 12: Kesmeler (Interrupts) ve Kesme Vektör Tablosu (IVT)

#### Genel Konular

- Kesmeler (Interrupts) ve Kesme Vektör Tablosu (IVT)
  - Kesme kavramı, IVT'nin bellekteki konumu (ilk 1 KB) ve yapısı anlatılır.
- Yazılımsal kesmeler (INT komutu)
  - BIOS ve DOS servislerini çağıran INT 21h, INT 10h gibi sistem kesmeleri ele alınır.
- Kesmelerin çalışma mantığı
  - Kesme tetiklendiğinde Flags, CS ve IP registerlarının otomatik olarak stack'e atılması ve Kesme Servis Yordamına (ISR) dallanma süreci açıklanır.

#### Hocanın Özellikle Vurguladığı Kısımlar

- IVT'nin 00000h - 003FFh arasındaki sabit adresi
  - Her bir kesme için 4 byte'lık (2 byte Segment, 2 byte Offset) adres vektörü tuttuğu bilgisi.
- ISR sonundaki IRET komutunun rolü
  - Stack'e atılan Flags, CS ve IP değerlerini geri yükleyerek kesme öncesindeki ana program akışına güvenli dönüş sağladığı.
### Ders 13: Donanımsal kesmelerin asenkron yapısı

#### Genel Konular

- Donanımsal kesmelerin asenkron yapısı
  - Dış çevre birimlerinden (klavye, zamanlayıcı vb.) gelen kesme sinyalleri ele alınır.
- Kesme denetleyicisi (8259 PIC)
  - Çoklu donanımsal kesmeleri ve bunların öncelik sıralamasını yöneten donanım yongası anlatılır.
- STI ve CLI komutları ile kesme kontrolü
  - CLI ile kesmelerin maskelenmesi (kapatılması) ve STI ile tekrar açılması işlemleri gösterilir.

#### Hocanın Özellikle Vurguladığı Kısımlar

- Donanımsal kesmelerin program akışından bağımsız (asenkron) oluşu
  - Herhangi bir kod satırında aniden tetiklenebilme özelliği.
- Kritik kod bloklarında CLI ile kesmelerin kapatılması gerekliliği
  - Bölünmemesi gereken hassas işlemler (örn. kesme vektörü güncelleme) sırasında kesmelerin CLI ile kapatılıp sonrasında STI ile açılması.
- Maskelenebilir (INTR) ve maskelenemez (NMI) kesme ayrımı
  - Hayati donanım hatalarının NMI pini üzerinden maskelenemez şekilde işlemciye doğrudan iletildiği.
### Ders 14: Assembly dilinin yüksek seviyeli programlama dilleri (C/C++) ile birlikte kullanımı

#### Genel Konular

- Assembly dilinin yüksek seviyeli programlama dilleri (C/C++) ile birlikte kullanımı
  - Geliştirme kolaylığı ile donanım kontrolünün birleştirilmesi mantığı ele alınır.
- Inline Assembly (satır içi assembly) yazım kuralları
  - C kodu içinde `__asm` veya `asm` anahtar kelimeleriyle assembly blokları oluşturma gösterilir.
- Register ve değişken paylaşımları
  - C değişkenlerine assembly komutlarıyla doğrudan erişim ve veri transferi kuralları anlatılır.

#### Hocanın Özellikle Vurguladığı Kısımlar

- Inline assembly'nin sağladığı hız ve optimizasyon avantajları
  - Görüntü işleme, kriptografi veya sürücü tasarımı gibi kritik kısımların optimize edilmesi.
- Derleyici optimizasyonları ile çakışma riskleri
  - Derleyicinin register tahsis kararlarıyla inline assembly kodundaki register kullanımının çakışmaması için dikkat edilmesi gereken kurallar.
### Ders 14 (Lab): Linux ortamında C programından assembly yordamı çağırma

#### Genel Konular

- Linux ortamında C programından assembly yordamı çağırma
  - C tarafında normal bir `main` fonksiyonu yazılır ve dışarıda tanımlanacak assembly yordamı için prototip bildirilir.
  - Örnekte kullanıcıdan `n` değeri alınır, `1` değerinden `n` değerine kadar eleman içeren bir `int` dizisi oluşturulur ve bu dizi assembly tarafındaki toplama yordamına gönderilir.
  - C kodunda assembly yordamını çağırabilmek için yordamın dönüş tipi ve parametreleri doğru tanımlanmalıdır; örnek yapı `extern int topla(int *, int)` biçimindedir.
- NASM sözdizimiyle assembly dosyası yazma
  - Microsoft Assembler tarafında kullanılan `segment` yaklaşımına karşılık NASM tarafında `section` kullanılır.
  - Kod bölümü `section .text` ile tanımlanır.
  - Assembly yordamının C tarafından görülebilmesi için yordam adı `global` bildirimiyle dışa açılır.
  - C tarafında çağrılan fonksiyon adı ile assembly tarafındaki etiket adı birebir aynı olmalıdır.
- C ile assembly arasında parametre aktarımı
  - C fonksiyon çağrısında parametreler stack üzerinden aktarılır.
  - Parametreler çağrı sırasında belirli bir sırayla stack üzerine yerleşir; assembly yordamı bu değerlere `EBP` tabanlı göreli adresleme ile erişir.
  - Yordam başında `EBP` değeri korunur ve `EBP`, mevcut `ESP` değerine eşitlenerek stack frame kurulur.
  - Yordam içinde kullanılacak registerlar çağıran kodun durumunu bozmamak için `push` ile saklanır ve işlem sonunda `pop` ile geri alınır.
- Assembly yordamında dizi toplama işlemi
  - Dizinin başlangıç adresi bir registerda, eleman sayısı başka bir registerda tutulur.
  - Döngü içinde her eleman okunur, toplam değere eklenir ve dizi adresi bir sonraki `int` elemana geçecek biçimde artırılır.
  - `int` elemanlar 32 bitlik olduğu için dizi üzerinde ilerlerken adres artışı 4 bayt üzerinden düşünülür.
  - Toplam sonucunun dönüş değeri olarak kullanılabilmesi için sonuç `EAX` registerında bırakılır.
- Fonksiyon dönüş değerinin register üzerinden aktarılması
  - C tarafında bir fonksiyon `int` gibi bir değer döndürdüğünde bu değer assembly düzeyinde `EAX` registerı üzerinden döndürülür.
  - Bu nedenle assembly yordamında toplamın `EAX` üzerinde hesaplanması veya işlem sonunda `EAX` içine alınması gerekir.
  - `ret` komutu çalıştığında çağıran C kodu, dönüş değerini `EAX` üzerinden alır ve ilgili değişkene aktarır.
- NASM ve GCC ile 32 bitlik derleme ve linkleme
  - Assembly dosyası NASM ile nesne dosyasına çevrilir.
  - 32 bitlik nesne dosyası üretmek için NASM tarafında uygun format seçilir.
  - C kodu GCC ile 32 bitlik olarak derlenir; bunun için `-m32` parametresi kullanılır.
  - C nesne kodu ile assembly nesne kodu birlikte linklenerek çalıştırılabilir dosya üretilir.
  - Üretilen dosyanın çalıştırılabilir olması dosya adından değil, sistemdeki çalıştırılabilirlik bilgisinden ve dosya izinlerinden anlaşılır.
- 64 bitlik registerlara geçiş hakkında temel notlar
  - 64 bitlik mimaride `EAX`, `EBX` gibi 32 bitlik register adlarının yanında `RAX`, `RBX` gibi 64 bitlik registerlar kullanılır.
  - 64 bitlik ortamda ayrıca `R8`, `R9`, `R10`, `R11`, `R12` gibi ek genel amaçlı registerlar da bulunur.
  - 64 bitlik kod yazarken yalnızca register adlarını değiştirmek yeterli olmayabilir; çağrı düzeni, parametre aktarımı ve derleme hedefi de dikkate alınmalıdır.
- Assembly kullanımının performans ve düşük seviye programlama açısından önemi
  - Assembly, yüksek performans gerektiren veya donanıma yakın çalışılması gereken durumlarda önem taşır.
  - Görüntü işleme, yapay zeka, gerçek zamanlı sistemler ve gömülü/düşük kaynaklı donanımlar gibi alanlarda belirli yordamların daha hızlı çalıştırılması gerekebilir.
  - Yüksek seviyeli dillerde yazılan programların çalıştırılmadan önce makine düzeyindeki komutlara dönüştüğü vurgulanır; bu nedenle assembly bilgisi bilgisayarın altta nasıl çalıştığını anlamak için temel bir araçtır.

#### Hocanın Özellikle Vurguladığı Kısımlar

- C tarafındaki `extern` bildirimi ile assembly tarafındaki `global` bildiriminin uyumu
  - C kodu dışarıda tanımlı bir yordamı çağıracağını `extern` ile bildirir.
  - Assembly kodu ise bu yordamı dışarıya görünür yapmak için `global` kullanır.
  - İki tarafta kullanılan yordam adı aynı olmazsa linker ilgili sembolü eşleştiremez.
- NASM sözdiziminde `section` kullanımının Microsoft Assembler'daki `segment` mantığına karşılık gelmesi
  - Farklı assembler araçları aynı temel kavramları farklı sözdizimleriyle ifade edebilir.
  - Bu nedenle assembly kodu yazarken kullanılan assemblerın sözdizimi bilinmelidir.
- Stack frame ve `EBP` tabanlı adresleme
  - Parametrelere güvenli ve düzenli biçimde erişmek için yordam başında stack frame kurulması gerekir.
  - `EBP` sabit referans noktası olarak kullanıldığında parametrelerin ve saklanan registerların stack üzerindeki konumu daha kolay takip edilir.
  - 32 bitlik ortamda değerlerin stack üzerindeki yerleşimi 4 baytlık aralıklarla düşünülmelidir.
- Kullanılan registerların korunması
  - Yordam içinde `ECX`, `EDI` gibi registerlar kullanılacaksa çağıran kodun beklediği değerlerin bozulmaması için bu registerlar saklanmalıdır.
  - `push` ve `pop` sırasının doğru yönetilmesi stack bütünlüğü açısından kritiktir.
- Dönüş değerinin `EAX` üzerinden verilmesi
  - `int` dönüşlü bir yordamın sonucu `EAX` registerında bulunmalıdır.
  - Toplama işlemi sonunda değerin `EAX` üzerinde kalması, C tarafındaki dönüş değerinin doğru alınmasını sağlar.
- 32 bitlik ve 64 bitlik hedeflerin karıştırılmaması
  - 32 bitlik registerlar ve 32 bitlik stack düzeniyle yazılan assembly kodu, buna uygun formatta derlenmeli ve C kodu da aynı hedef mimariye göre derlenmelidir.
  - NASM ve GCC tarafındaki hedef mimari uyumlu olmazsa register boyutları, çağrı düzeni veya linkleme aşamasında sorunlar ortaya çıkabilir.
- Assembly öğrenmenin temel amacı
  - Assembly yalnızca belirli örnekleri yazmak için değil, yüksek seviyeli programların makine düzeyinde nasıl temsil edildiğini anlamak için de önemlidir.
  - Performans kritik bölümlerde veya düşük kaynaklı donanımlarda assembly bilgisinin pratik değeri vardır.

#### Detaylı Açıklamalar

- Bu derste Linux ortamında bir C programının NASM ile yazılmış bir assembly yordamını çağırması ele alınır. Örnek senaryoda C programı kullanıcıdan bir `n` değeri alır, bu değere kadar artan sayılardan oluşan bir `int` dizisi üretir ve diziyi toplaması için assembly yordamına gönderir. C tarafında assembly yordamı normal bir fonksiyon gibi çağrılır; ancak derleyiciye bu fonksiyonun başka bir dosyada tanımlı olduğunu bildirmek için `extern` prototipi gerekir.

- C ile assembly dosyalarının birlikte çalışabilmesi için sembol adlarının doğru eşleşmesi gerekir. C kodunda çağrılan fonksiyon `topla` ise NASM dosyasında da `topla:` etiketi bulunmalı ve bu etiket `global topla` ile dışa açılmalıdır. Bu bildirim yapılmazsa linker, C kodundaki fonksiyon çağrısını assembly dosyasındaki yordamla ilişkilendiremez.

- NASM sözdiziminde program bölümleri `section` ile tanımlanır. Microsoft Assembler tarafında kullanılan `segment` yaklaşımıyla aynı temel fikri taşır; ancak yazım biçimi farklıdır. Kodların yer aldığı bölüm `section .text` olarak belirtilir. Bu bölüm içinde yordam etiketi tanımlanır ve yordamın komutları bu etiketin altında yazılır.

- Assembly yordamı çağrıldığında parametreler stack üzerinde bulunur. Yordam başında mevcut `EBP` değeri saklanır ve `EBP`, `ESP` değerine eşitlenerek stack frame oluşturulur. Böylece parametrelere ve saklanan değerlere sabit ofsetlerle erişilebilir. 32 bitlik ortamda her adres veya `int` değer 4 bayt kabul edildiği için stack üzerindeki ilerleme 4 baytlık aralıklarla düşünülür.

- Örnekte dizi adresi ve eleman sayısı stack üzerinden alınır. Dizi adresi bir registerda, eleman sayısı ise döngü sayacı olarak kullanılabilecek bir registerda tutulur. Toplama işlemi sırasında `EAX` başlangıçta sıfırlanır, her döngü adımında dizinin o anki elemanı `EAX` üzerine eklenir ve dizi adresi bir sonraki elemana geçecek biçimde artırılır. Elemanlar `int` türünde olduğu için adres artışı 4 bayttır.

- Fonksiyon dönüş değeri konusu özellikle önemlidir. C tarafında `int` döndüren bir fonksiyonun sonucu assembly düzeyinde `EAX` registerı üzerinden iletilir. Bu nedenle assembly yordamı tamamlandığında toplam değerinin `EAX` üzerinde bulunması gerekir. `ret` komutu çağıran koda geri döndüğünde C tarafındaki değişken bu registerdan gelen değeri alır.

- Yordam içinde kullanılan registerlar çağıran kodun beklediği değerleri bozabileceği için saklanmalıdır. Ders örneğinde döngü ve dizi adresi için kullanılan registerlar yordam başında stack üzerine atılır, yordam sonunda ters sırayla geri alınır. Bu disiplin, özellikle C ve assembly kodlarının birlikte çalıştığı durumlarda programın kararlı davranması için gereklidir.

- Derleme sürecinde assembly dosyası önce NASM ile nesne dosyasına çevrilir. C dosyası GCC ile derlenirken hedefin 32 bitlik olması için `-m32` parametresi kullanılır. Sonrasında C kodu ile assemblyden üretilen nesne dosyası birlikte linklenir ve çalıştırılabilir dosya oluşturulur. Bu aşamada C kodunun hedef mimarisi ile assembly kodunun hedef formatı uyumlu olmalıdır.

- 64 bitlik sistemlerde register adları ve olanakları genişler. `EAX` gibi 32 bitlik registerların yanında `RAX` gibi 64 bitlik karşılıklar ve `R8`, `R9`, `R10` gibi ek registerlar bulunur. Ancak 64 bitlik kod yazarken yalnızca register adlarını büyütmek yeterli görülmemelidir; çağrı kuralları, parametrelerin hangi register veya stack alanları üzerinden aktarılacağı ve derleme hedefi de birlikte değerlendirilmelidir.

- Dersin genel vurgusu, assembly dilinin hem bilgisayarın alt seviyede nasıl çalıştığını anlamak hem de gerektiğinde performans kritik bölümleri optimize etmek için önemli olduğudur. Yüksek seviyeli dillerle yazılan programlar sonuçta makine komutlarına dönüştürülür. Bu dönüşümü anlamak; gömülü sistemler, gerçek zamanlı uygulamalar, yapay zeka, görüntü işleme veya düşük kaynaklı donanımlar gibi alanlarda daha bilinçli programlama yapılmasını sağlar.
### Ders 14 (1): Harici modüller (External Modules) ve Linking

#### Genel Konular

- Harici modüller (External Modules) ve Linking
  - Ayrı `.asm` dosyalarında yazılan assembly kodlarının derlenip C/C++ projelerine bağlanması (linking) süreci anlatılır.
- Assembly fonksiyonlarının C tarafından çağrılması
  - C tarafında `extern` anahtar kelimesiyle fonksiyon bildirimi ve linker aşaması ele alınır.
- Çağırma konvansiyonları (Calling Conventions)
  - Cdecl, Stdcall ve Fastcall kuralları, parametrelerin stack'e yerleştirilme sırası ve stack temizliği karşılaştırılır.

#### Hocanın Özellikle Vurguladığı Kısımlar

- Çağırma kurallarının (Calling Conventions) hayati önemi
  - Çağıran ve çağrılan taraflar arasında stack temizliği ve parametre sırası uyumsuzluğunun program çökmesine yol açacağı.
- Harici fonksiyon isimlerindeki alt çizgi (_) kuralı
  - Derleyicinin fonksiyon adlarının başına otomatik alt çizgi eklemesi nedeniyle assembly tarafında isimlerin bu kurala uygun tanımlanması ve `PUBLIC` yapılması zorunluluğu.

> **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi daha verimli çalışabilirsiniz.
