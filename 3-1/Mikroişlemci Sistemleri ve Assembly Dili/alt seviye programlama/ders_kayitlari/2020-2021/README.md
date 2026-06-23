# Alt Seviye Programlama Ders Kayıtları & Çalışma Özetleri

Bu klasör, 2020-2021 eğitim öğretim yılı Güz dönemindeki Alt Seviye Programlama ders kayıtlarının haftalık özetlerini ve PDF çalışma dosyalarını içerir.

* **Dersi Veren Akademisyen:** Dr. Furkan Çakmak
* **Dönem:** 2020-2021 Güz Dönemi

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
* **Genel Konular:** alt seviye programlama ve assembly dillerine giriş, 8086 mikroişlemci mimarisi, register (yazmaç) kavramı ve genel amaçlı yazmaçlar (ax, bx, cx, dx), segment yapısı ve hafıza organizasyonu (cs, ds, ss, es), kod ve veri ayrımı, alt seviye programlamanın temel kavramları
* **Hocanın Vurgusu:** Assembly dillerinin donanıma doğrudan erişim sağlaması nedeniyle hızı ve esnekliği. Registerların kısıtlı kaynaklar olması ve verimli kullanılması gerekliliği. Hafızaya doğrudan erişimlerin getirdiği riskler ve kurallar.

### 🔹 Ders 2: Fiziksel Adres Hesaplama ve Veri Tanımlama
* **Genel Konular:** fiziksel adres hesaplama formülü (segment * 16 + offset), veri tanımlama direktifleri (db - define byte, dw - define word), değişken tanımlama kuralları ve bellek yerleşimi, değişken isimlerinin sayıyla başlayamaması ve hex sayılarda harfle başlayan değerlerin başına sıfır (0) konulması kuralı (örn. 0ah)
* **Hocanın Vurgusu:** Fiziksel adrese erişim mekanizması ve segment sınırları (64 KB). Değişken bildirimlerinde veri boyutlarının (Byte ve Word) doğru belirlenmesinin önemi. Hexadecimal gösterimlerde harfle başlayan değerlerin derleyici tarafından değişken olarak algılanmaması için prefix ve suffix kurallarına dikkat edilmelidir.

### 🔹 Ders 3: Dallanma, Karşılaştırma ve Matematiksel İşlemler
* **Genel Konular:** dallanma ve karşılaştırma komutları: koşulsuz dallanma (jmp) ve koşullu dallanma (je, jne, jz, jnz, jg, jl vb.), matematiksel ve mantıksal işlemler (add, sub, mul, div, and, or, xor, not), karşılaştırma (cmp) komutu ve flags register'ının rolü
* **Hocanın Vurgusu:** Koşullu dallanmaların Flags register'ı üzerindeki bit durumlarına göre çalıştığı. Çarpma (MUL) ve bölme (DIV) işlemlerinde örtük (implicit) register kullanımı ve taşma durumları. Kod okunabilirliği ve akışı için dallanma bloklarının düzenli yapılandırılması.

### 🔹 Ders 5: Öteleme ve Döndürme Komutları
* **Genel Konular:** öteleme (shift) ve döndürme (rotate) komutları (shl, shr, sar, sal, rol, ror, rcl, rcr), mantıksal ve aritmetik öteleme farkları, öteleme komutlarının hızlı çarpma ve bölme işlemlerinde kullanımı
* **Hocanın Vurgusu:** Aritmetik ötelemede (SAR) işaret bitinin (MSB) korunması, mantıksal ötelemede ise sıfır doldurulması. Döndürme komutlarında elde (carry) bitinin rolü. Performans kritik uygulamalarda çarpma/bölme yerine öteleme komutlarının kullanılması.

### 🔹 Ders 6: Adresleme Kipleri ve İşaretçiler
* **Genel Konular:** 8086 adresleme kipleri (addressing modes): immediate, register, direct, register indirect, based, indexed ve based indexed adresleme, offset direktifi ve işaretçiler (pointers), bellekteki verilere esnek erişim yöntemleri
* **Hocanın Vurgusu:** Adresleme kiplerinin esnekliği ve veri yapılarına (diziler vb.) erişimde indexed adreslemenin avantajları. Pointer aritmetiği ve segment-offset ilişkileri. Hangi adresleme kipinin hangi durumlarda daha performanslı olduğu.

### 🔹 Ders 7: Bellek Segmentleri ve Yığın (Stack) Mantığı
* **Genel Konular:** data segment ve stack segment yapısı, stack (yığın) mimarisi ve yığın işlemleri (push, pop), değişkenlerin hafızadaki yerleşimi, başlangıç değeri verilmeyen değişkenler için '?' kullanımı, program şablonunun oluşturulması
* **Hocanın Vurgusu:** Stack segmentinin çalışma mantığı (LIFO - Last In First Out). SP (Stack Pointer) register'ının yönetimi. Başlangıç değeri atanmamış değişkenlerin bellek hizalaması (alignment) ve program boyutuna etkisi.

### 🔹 Ders 9: Döngüler ve Yığın İşlemleri
* **Genel Konular:** döngü yapıları ve loop komutu, koşullu döngüler (loope, loopne), yığın işlemlerinin döngülerle birleşimi, vize sınavı değerlendirmesi ve geri bildirimler
* **Hocanın Vurgusu:** LOOP komutunun CX register'ını otomatik olarak bir azaltması ve sıfır olup olmadığını kontrol etmesi. Büyük döngülerde veya iç içe döngülerde register çakışmalarını önlemek için stack kullanımı.

### 🔹 Ders 10: Alt Programlar (Procedures) ve Makrolar
* **Genel Konular:** alt programlar (procedures) ve modüler programlama, proc, call ve ret komutları, makro (macro) tanımı, makro ile yordam (procedure) arasındaki farklar, vize sınav sorularının çözümü ve analizi
* **Hocanın Vurgusu:** Alt program çağrılarında geri dönüş adresinin stack'e kaydedilmesi ve RET ile geri alınması süreci. Makroların derleme aşamasında kod açılımı yapması, yordamların ise çalışma zamanında çağrılması (bellek vs hız optimizasyonu).

### 🔹 Ders 11: Parametre Aktarma Yöntemleri
* **Genel Konular:** alt programlara parametre aktarma yöntemleri, registerlar aracılığıyla, ortak bellek alanları (global değişkenler) üzerinden veya yığın (stack) yardımıyla parametre aktarımı, stack frame oluşturma, bp (base pointer) kullanımı
* **Hocanın Vurgusu:** Stack üzerinden parametre aktarımının rekürsif ve çoklu yordam çağrılarındaki güvenliği. Yordam çağrısından sonra stack temizliğinin (Caller veya Callee tarafından) yapılması sorumluluğu. BP ile stack'teki lokal değişkenlere ve parametrelere erişim.

### 🔹 Ders 12: Kesmeler (Interrupts) ve BIOS/DOS Servisleri
* **Genel Konular:** kesmeler (interrupts) ve kesme vektör tablosu (interrupt vector table - ivt), yazılımsal kesmeler (int komutu) ve bios/dos servisleri (örn. int 21h fonksiyonları), kesmelerin çalışma mantığı ve kesme servis yordamları (isr)
* **Hocanın Vurgusu:** IVT'nin bellekteki ilk 1 KB'lık alanda (00000h - 003FFh) yer alması ve her kesme için 4 byte'lık CS:IP adres bilgisi tutması. Kesme tetiklendiğinde Flags, CS ve IP registerlarının otomatik olarak stack'e atılması.

### 🔹 Ders 13: Donanımsal Kesmeler ve Kesme Denetleyicisi
* **Genel Konular:** donanımsal kesmeler ve kesme denetleyicisi (8259 pic), kesmelerin öncelik mekanizmaları, kesme birleştirme ve maskeleme işlemleri, sti (enable interrupts) ve cli (disable interrupts) komutları
* **Hocanın Vurgusu:** Donanımsal kesmelerin asenkron yapısı ve işlemciye nasıl iletildiği. Kritik kod bloklarında CLI ile kesmelerin kapatılması ve STI ile tekrar açılması gerekliliği. Maskelenebilir (INTR) ve maskelenemez (NMI) kesme ayrımları.

### 🔹 Ders 14: Assembly ve Yüksek Seviyeli Diller - 1 (Inline Assembly)
* **Genel Konular:** assembly dilinin yüksek seviyeli programlama dilleri (c/c++) ile birlikte kullanımı, inline assembly (satır içi assembly) yazım kuralları, register ve değişken paylaşımları
* **Hocanın Vurgusu:** Hız gerektiren kritik algoritmaların (görüntü işleme, kriptografi vb.) C kodu içinde inline assembly olarak yazılmasının sağladığı avantajlar. C derleyicisinin register optimizasyonları ile Assembly kodunun çakışmaması için dikkat edilmesi gerekenler.

### 🔹 Ders 14.1: Assembly ve Yüksek Seviyeli Diller - 2 (External Modules & Linking)
* **Genel Konular:** assembly yordamlarının harici modüller (external modules) olarak derlenip c/c++ projelerine bağlanması (linking), arama, sıralama gibi algoritmaların assembly kütüphanesi olarak yazılması ve test edilmesi, dönem sonu özeti ve değerlendirmesi
* **Hocanın Vurgusu:** Harici modül kullanımında çağırma konvansiyonları (Calling Conventions: Cdecl, Stdcall) ve stack yapısının uyumluluğu. Harici fonksiyon adlarının başındaki alt çizgi (_) kuralı ve linker hatalarının çözümü.

