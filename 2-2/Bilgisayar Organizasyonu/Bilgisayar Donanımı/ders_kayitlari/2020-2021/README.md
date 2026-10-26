# Bilgisayar Donanımı Ders Kayıtları & Çalışma Özetleri

> **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.

### 📋 Genel Bilgiler
* **Ders:** Bilgisayar Donanımı (BLM2022)
* **Hoca:** Prof. Dr. Songül Varlı
* **Dönem:** Bahar
* **Akademik Yıl:** 2020-2021
* **Şube:** BLM2022 - 1

Bu dizin, ilgili ders kayıtlarının altyazı özetlerini, çalışma notlarını ve PDF kaynaklarını içermektedir.

## 📚 Ders Müfredatı ve Belge Dizini

Aşağıdaki tabloda her bir dersin konusu, kaynak markdown dosyası ve doğrudan indirilebilir PDF formatındaki derlenmiş halleri listelenmiştir. Ders numaraları, kayıt arşivindeki ders kaydı sıra numaralarıdır (hafta numarası değildir).

| Ders No | Ders İçeriği / Konu Başlıkları | Kaynak Notlar (Markdown) | Çalışma Dosyası (PDF) |
| :---: | :--- | :---: | :---: |
| **Ders 1** | Dersin Tanıtımı, Lojik Kapılar ve Boole Cebri Tekrarı, Multiplexer, Decoder ve Encoder | [Özet](altyazi_ozetleri/ders_1_ozet.md) | [PDF (İndir)](ders_1_ozet.pdf) |
| **Ders 2** | Toplayıcılar, İkiye Tümleyen Aritmetiği ve Taşma, Three-State Buffer, Flip-Flop'lar ve Ardışıl Devre Analizi | [Özet](altyazi_ozetleri/ders_2_ozet.md) | [PDF (İndir)](ders_2_ozet.pdf) |
| **Ders 3** | Dizi Tanıyıcı, Saklayıcılar ve Mikro İşlemler, Seri Toplayıcı, Asenkron ve Senkron Sayıcılar | [Özet](altyazi_ozetleri/ders_3_ozet.md) | [PDF (İndir)](ders_3_ozet.pdf) |
| **Ders 4** | JK ve T Flip-Flop ile Sayıcı Tasarımı, Kendi Kendini Düzeltme, ROM ve PLA | [Özet](altyazi_ozetleri/ders_4_ozet.md) | [PDF (İndir)](ders_4_ozet.pdf) |
| **Ders 5** | PAL, RAM Türleri, Bellek Organizasyonu, Çakışık Seçim ve Bellek Genişletme | [Özet](altyazi_ozetleri/ders_5_ozet.md) | [PDF (İndir)](ders_5_ozet.pdf) |
| **Ders 6** | Register Transferi ve Ortak Veri Yolu, Komut Kümesi Mimarisi, Adresleme Modları ve Koşullu Dallanma | [Özet](altyazi_ozetleri/ders_6_ozet.md) | [PDF (İndir)](ders_6_ozet.pdf) |
| **Ders 9** | İşlemci Tasarımına Giriş: Datapath, Aritmetik Devre Tasarımı, ALU, Kaydırıcı ve Kontrol Kelimesi | [Özet](altyazi_ozetleri/ders_9_ozet.md) | [PDF (İndir)](ders_9_ozet.pdf) |
| **Ders 10** | Tek Çevrimli Bilgisayar, Komut Çözücü, Pipeline ve Tehlikeleri, G/Ç Arayüzü ve Haberleşme | [Özet](altyazi_ozetleri/ders_10_ozet.md) | [PDF (İndir)](ders_10_ozet.pdf) |
| **Ders 11** | Seri İletişim, Veri Transfer Yöntemleri, Öncelikli Kesmeler, DMA ve Önbelleğe Giriş | [Özet](altyazi_ozetleri/ders_11_ozet.md) | [PDF (İndir)](ders_11_ozet.pdf) |
| **Ders 12** | Cache Bellek: Bellek Hiyerarşisi, Yerellik İlkesi, Direct Mapped Cache, Ortalama Erişim Süresi ve Yazma Politikaları | [Özet](altyazi_ozetleri/ders_12_ozet.md) | [PDF (İndir)](ders_12_ozet.pdf) |
| **Ders 13** | Sanal Bellek: Adres Dönüşümü, Sayfa Tablosu, TLB, Sayfa Yerine Koyma ve Final Bilgilendirmesi | [Özet](altyazi_ozetleri/ders_13_ozet.md) | [PDF (İndir)](ders_13_ozet.pdf) |

> [!NOTE]
> 23 Nisan, 30 Nisan (vize haftası) ve 14 Mayıs 2021 haftalarına ait kayıt yoktur. Ders güncel müfredatta Bilgisayar Organizasyonu adını almıştır.

## 🎯 Derslerin Detaylı Özetleri ve Kazanımları

### 🔹 Ders 1: Dersin Tanıtımı, Lojik Kapılar ve Boole Cebri Tekrarı, Multiplexer, Decoder ve Encoder
* **Genel Konular:**
  - Dersin tarihi 12 Mart 2021 Cuma. Ders Zoom üzerinden yapıldı.
    - Asıl ders yaklaşık 00:06:24'te başlar. Kaydın başı bekleme kısmıdır.
  - Dersin tanıtımı ve işleyişi
    - Ders, Lojik Devreler dersinin devamı gibidir. İşlemci, bellek, çevre birimleri ve portlar işlenecek.
  - Haftalık plan (ders tanıtım formundan)
    - Kombinasyonel ve ardışıl devreler, saklayıcı ve sayıcılar, programlanabilir yapılar (PLD, PLA, PAL), RAM ve ROM.
  - Lojik kapılar ve Boole cebri tekrarı
    - AND, OR, NOT, NAND, NOR, XOR kapıları ve sembolleri.
  - Lojik fonksiyonların gösterimi
    - Doğruluk tablosu, lojik ifade, devre şeması ve HDL (Verilog, VHDL).
  - Sayı sistemleri
    - 0-18 arası sayıların ikilik ve onaltılık karşılıkları.
  - Kombinasyonel yapı taşları
    - Multiplexer (MUX), decoder, demultiplexer, encoder, priority encoder.
* **Hocanın Vurgusu:**
  - Değerlendirme: 1 ara sınav %30, 2 kısa sınav (2 x %15) %30, final %40.
    - Ödev yok. Kısa sınavlar 4. hafta (2 Nisan) ve 13. hafta (4 Haziran).
  - Devam zorunluluğu %70'tir.
    - Devamsız öğrencinin notu F0 olur.
  - Dönemin ilk yarısı kolay gelecek.
    - İkinci yarısı (CPU, giriş/çıkış, cache, sanal bellek) dersin asıl kısmıdır.
  - XOR kapısının genel tanımı: girişlerdeki 1'lerin sayısı tekse çıkış 1'dir.
    - Bu tanım 2'den fazla girişte de geçerlidir. XOR bu yüzden bir çift eşlik (even parity) üretecidir.
  - İşaretli sayılarda yalnızca ikiye tümleyeni düşünün.
    - Öğrenciler bu konuda çok hata yapıyor.
* **Detaylı Açıklamalar:** Ders Cuma günleri yapılan zorunlu bir derstir. Hoca dersin Lojik Devreler dersinin üzerine kurulduğunu söyledi. İlk haftalarda lojik konuları hızla tekrar edilecek. Lojik bilgisi eksik olanlar (özellikle bilimsel hazırlık öğrencileri) kitabın ilk 5-6 bölümünü erkenden çalışmalı.

### 🔹 Ders 2: Toplayıcılar, İkiye Tümleyen Aritmetiği ve Taşma, Three-State Buffer, Flip-Flop'lar ve Ardışıl Devre Analizi
* **Genel Konular:**
  - Dersin tarihi 19 Mart 2021 Cuma. Ders Zoom üzerinden yapıldı.
    - Asıl ders yaklaşık 00:06:20'de başlar.
  - Toplayıcılar
    - Yarım toplayıcı (half adder) ve tam toplayıcı (full adder).
  - Çok bitli yapı taşları
    - 8 bitlik 4'ten 1'e MUX: 8 tane 1 bitlik 4'ten 1'e MUX.
  - Karşılaştırıcı (comparator)
    - XOR ve NOR ile eşitlik kontrolü.
  - İkiye tümleyen aritmetiği
    - İşaretsiz çıkarma ve elde/borç biti.
  - Üç durumlu tampon (three-state buffer)
    - Yüksek empedans (Hi-Z) çıkışı ve veri yolunda (bus) kullanımı.
  - Ardışıl devreler
    - Latch ve flip-flop farkı, D latch, D flip-flop.
* **Hocanın Vurgusu:**
  - Yarım toplayıcı elde girişi almadığı için çok bitli toplayıcı kurmaya yetmez.
    - Tam toplayıcı kullanılır.
  - Bundan sonraki tasarımlarda hazır bir tam toplayıcı olduğu varsayılacak.
  - İkiye tümleyeni alırken "tersini çevirip başına 1 eklemek" yanlıştır.
    - Doğrusu: bitleri ters çevir, sonra en düşük anlamlı bite 1 ekle.
  - Çıkarmada elde biti C = 1 ise borç biti B = 0'dır.
    - Bu, X'in Y'den büyük olduğunu gösterir.
  - İşaretli sayılarda V (overflow), Z (zero) ve N (negative) bitlerine bakılır.
    - İşaretsiz sayılarda overflow biti kullanılmaz, yalnızca C bitine bakılır.
* **Detaylı Açıklamalar:** Yarım toplayıcı iki bitlik girişi toplar ve toplam (sum) ile elde (carry out) üretir. Toplam çıkışı XOR ile gerçekleştirilir. Çünkü toplam, girişlerdeki 1'lerin sayısı tek olduğunda 1'dir.

### 🔹 Ders 3: Dizi Tanıyıcı, Saklayıcılar ve Mikro İşlemler, Seri Toplayıcı, Asenkron ve Senkron Sayıcılar
* **Genel Konular:**
  - Dersin tarihi 26 Mart 2021 Cuma. Ders Zoom üzerinden yapıldı.
    - Asıl ders yaklaşık 00:09:12'de başlar.
  - Geçen haftanın tekrarı
    - Mealy ve Moore modeli devreler, state diagram farkları.
  - Ardışıl devre tasarımı: dizi tanıyıcı (sequence recognizer)
    - 1101 dizisini tanıyan devrenin state diagram'ı ve durum kodlaması.
  - Saklayıcılar (registers)
    - Basit kaydırmalı saklayıcı (shift register).
  - Saklayıcı transfer işlemleri
    - Datapath ve control unit.
  - Seri toplayıcı (serial adder) örneği
  - Sayıcılar (counters)
    - Asenkron (ripple) sayıcı: D ve T flip-flop ile.
* **Hocanın Vurgusu:**
  - Mealy ve Moore modellerini ayırt edin.
    - Moore'da çıkış dairenin içine yazılır, okların üzerinde yalnızca giriş bulunur.
  - İşlemci içinde clock gating kullanılmaz.
    - Clock yoluna eklenen kapılar gecikme yaratır. Bütün saklayıcı ve sayıcılar clock'un aynı kenarında durum değiştirmelidir.
  - "Shift down/up" ifadeleri yerine shift left/right kullanın.
    - Slayttaki "Q0'dan Q3'e" kaydırma shift left'tir.
  - Fonksiyon tablosundan flip-flop giriş denklemini yazabilmelisiniz.
    - Çok fonksiyonlu saklayıcıda her flip-flop'un önüne bir MUX konur.
  - Ripple (asenkron) sayıcıları bilin, ama tasarımlarda senkron sayıcılar kullanılacak.
* **Detaylı Açıklamalar:** Devrenin bir X girişi ve bir Z çıkışı vardır. Başta doğrudan (asenkron) reset ile bütün flip-flop'lar sıfırlanır. Devre son dört giriş 1, 1, 0, 1 olduğunda Z = 1 üretir. Diziler örtüşebilir: bir dizinin son 1'i bir sonrakinin ilk 1'i olabilir.

### 🔹 Ders 4: JK ve T Flip-Flop ile Sayıcı Tasarımı, Kendi Kendini Düzeltme, ROM ve PLA
* **Genel Konular:**
  - Dersin tarihi 2 Nisan 2021 Cuma. Ders Zoom üzerinden yapıldı. Dönemin 4. haftası.
    - Asıl ders yaklaşık 00:05'te başlar.
  - Sayıcı tasarımı örnekleri (geçen haftadan kalan)
    - JK flip-flop ile sayıcı: geçiş tablosu (excitation table) ile flip-flop girişlerini yazma.
  - Programlanabilir lojik cihazlar (Programmable Logic Devices)
    - Ortak yapı: bir AND dizisi ve bir OR dizisi. Hangi dizinin önünün programlanabilir olduğu türü belirler.
  - ROM ile kombinasyonel devre tasarımı ve ROM boyutu hesapları.
  - PLA ile iki çıkışlı fonksiyon gerçekleme ve ortak terim arama.
* **Hocanın Vurgusu:**
  - JK geçiş tablosunu ezberlemeyin, fonksiyon tablosundan siz çıkarın.
    - Sadece JK flip-flop'un fonksiyon tablosunu bilmeniz yeter.
  - Karnaugh haritasında küçük bir hata sonucu bozar.
    - Derste hocanın kendisi de sütun etiketini yanlış yazdı, öğrenciler düzeltti. Dikkatli olun.
  - Don't care'leri 0 ya da 1 almak devrenin kullanılmayan durumlardaki davranışını değiştirir.
    - Tasarımdan sonra kullanılmayan durumların nereye gittiğini mutlaka kontrol edin.
  - Kullanılmayan durumlar kendi aralarında döngü kurarsa devre kilitlenir.
    - Devre kendi kendini düzeltmiyorsa don't care seçimlerini değiştirip yeniden tasarlayın. Devre biraz büyüyebilir.
  - ROM bir arama tablosudur (lookup table).
    - İçinde aritmetik yapan bir devre yoktur. Doğruluk tablosunu ROM'a yazar, adrese göre okursunuz.

### 🔹 Ders 5: PAL, RAM Türleri, Bellek Organizasyonu, Çakışık Seçim ve Bellek Genişletme
* **Genel Konular:**
  - Dersin tarihi 9 Nisan 2021 Cuma. Ders Zoom üzerinden yapıldı. Dönemin 5. haftası.
    - Asıl ders yaklaşık 00:07'de başlar. İlk dakikalar selamlaşma ve aşı sohbetidir.
  - Geçen haftadan kalan programlanabilir lojik cihazlar
    - PLA'nın kısa tekrarı (bir öğrencinin isteğiyle).
  - Bellek temelleri (Memory Basics)
    - RAM türleri: statik RAM (SRAM) ve dinamik RAM (DRAM).
  - Daha büyük bellek oluşturma
    - Boyuna uzatma (daha çok satır, making larger memories).
* **Hocanın Vurgusu:**
  - Bellek genişletme konusu önemlidir. "Bu konularla ilgili mutlaka sınavda soru olacak."
  - Kitabın bölüm sonu sorularını çözün.
    - Hoca kitabın 4. baskısının PDF'ini ders duvarına koydu.
  - Kapasite sorularında verilen kelime genişliğine dikkat edin.
    - "2 MB" gibi bayt cinsinden verilen kapasiteyi, elinizdeki çipin kelime genişliğine (ör. 16 bit) göre yeniden yazın. Soru bu yüzden "biraz trikli".
  - 48K gibi 2'nin kuvveti olmayan sayılarda bir üst kuvveti alın.
    - 32 için 5 bit yeter. 32'yi aşan her sayı için (64'e kadar) 6 bit gerekir.
  - Statik RAM pahalıdır, bu yüzden yalnız küçük kapasiteli önbellekte (cache) kullanılır.

### 🔹 Ders 6: Register Transferi ve Ortak Veri Yolu, Komut Kümesi Mimarisi, Adresleme Modları ve Koşullu Dallanma
* **Genel Konular:**
  - Dersin tarihi 16 Nisan 2021 Cuma. Ders Zoom üzerinden yapıldı. Dönemin 6. haftası.
    - Asıl ders yaklaşık 00:07'de başlar.
  - Takvim duyurusu
    - 23 Nisan resmî tatil olduğu için gelecek hafta ders yok.
  - Register transferi ve ortak veri yolu (bus)
    - Dersin hedefi: veri yolu birimi (datapath unit) ve kontrol birimi (control unit) ile bir CPU tasarlamak.
  - Komut kümesi mimarisi (Instruction Set Architecture, ISA)
    - RISC ve CISC.
* **Hocanın Vurgusu:**
  - Üç durumlu veri yolu konusu önemli. "Bunu anlamanızı özellikle istiyorum."
    - Bundan sonraki CPU tasarımında bu yapı kullanılacak.
  - Üç durumlu veri yolunda aynı anda yalnız bir tamponun enable olmasını garanti edin.
    - İki register aynı anda veri yoluna farklı değer koyarsa devre yanar.
  - Bu ders 8086 assembly dersi değildir.
    - Amaç tek bir işlemciyi değil, genel mimari kavramları öğrenmektir. Böylece yeni bir işlemciye kolay geçersiniz.
  - Aritmetik kaydırmada taşma yalnız sola kaydırmada olur.
    - Sağa kaydırmada taşma olmaz, yalnız işaret biti korunur.
  - Negatif sayıyı yazarken yalnız en anlamlı biti 1 yapmayın.
    - Önce pozitif değeri yazın, sonra ikiye tümleyenini alın. Hocanın en çok gördüğü hatalardan biri.
* **Detaylı Açıklamalar:** 1. Instruction Fetch (IF): Komut bellekten komut register'ına (IR) getirilir. 2. Instruction Decode (ID): Opcode ve adresleme modu çözülür. 3. Operand Fetch (OF): Operand (gerekirse bellekten) getirilir. 4. Execute (EX): İşlem yürütülür. 5. Write Back (WB): Sonuç register'a ya da belleğe yazılır. 6. PC sonraki komutu gösterecek biçimde güncellenir, çevrim başa döner.

### 🔹 Ders 9: İşlemci Tasarımına Giriş: Datapath, Aritmetik Devre Tasarımı, ALU, Kaydırıcı ve Kontrol Kelimesi
* **Genel Konular:**
  - Dersin tarihi 7 Mayıs 2021 Cuma. Ders Zoom üzerinden yapıldı.
    - Asıl anlatım yaklaşık 00:12'de başlar. Öncesi selamlaşma ve vize sonrası sohbettir.
  - İşlemci tasarımına giriş
    - CPU iki temel bloktan oluşur: veri yolu birimi (datapath unit) ve kontrol birimi (control unit).
  - Örnek datapath (4 register'lı)
    - Register kümesi (register file), kaynak seçen MUX'lar, MUX B, fonksiyon birimi (ALU + shifter), MUX F, MUX D ve hedef seçen decoder.
  - Aritmetik devre tasarımı
    - $n$-bit paralel toplayıcı (parallel adder) ve önüne konan B giriş lojiği (B input logic) ile 8 aritmetik işlem.
  - Alıştırmalar (kitabın bölüm sonu soruları)
    - Hem A hem B giriş lojiği gereken aritmetik devre tasarımı.
  - Lojik devre, ALU ve kaydırıcı (shifter)
    - AND, OR, XOR, NOT işlemlerini yapan lojik blok.
  - Genel datapath ve kontrol kelimesi (control word)
    - 8 register'lı datapath için 16 bitlik kontrol kelimesi.
* **Hocanın Vurgusu:**
  - Dersi derste öğrenin.
    - Sadece ders notlarıyla çalışmak çok vakit kaybettirir.
  - İşlemci tasarımı, pipeline, önbellek ve sanal bellek mesleğin temel konularıdır.
    - Mano'nun kitabı bu kavramları belli bir işlemciye bağlı kalmadan anlatır.
  - Aritmetik devrede en dikkat edilecek nokta $A-1$ işlemidir.
    - $Y$ girişine "hepsi 1" (all ones) verilir. Bu, ikiye tümleyende $-1$ demektir.
  - $C_{in}$ işlem seçme ucu gibi davranır.
    - 2 seçme ucu + $C_{in}$ ile 8 farklı aritmetik işlem tanımlanır.
  - B giriş lojiğinde kullanılan $C_{in}$, en düşük anlamlı bite dışarıdan gelen elde girişidir.
    - Tam toplayıcılar arasındaki ara elde bitleriyle karıştırmayın.

### 🔹 Ders 10: Tek Çevrimli Bilgisayar, Komut Çözücü, Pipeline ve Tehlikeleri, G/Ç Arayüzü ve Haberleşme
* **Genel Konular:**
  - Dersin tarihi 21 Mayıs 2021 Cuma. Ders Zoom üzerinden yapıldı.
    - Bayram tatilinden sonraki ilk derstir. Hoca "11. haftadayız" diyor.
  - Datapath tekrarı
    - Register file, fonksiyon birimi (ALU + shifter), MUX B, MUX D, 16 bitlik kontrol kelimesi.
  - Tek çevrimli bilgisayar (single-cycle computer)
    - Komut belleği (instruction memory), veri belleği (data memory), program sayacı (PC).
  - Boru hattı (pipeline) işleme
    - 3 aşamalı pipeline datapath (OF, EX, WB) ile hızlanma.
  - Giriş/Çıkış ve iletişim (Input/Output and Communications)
    - Çevre birimleri (peripherals): klavye, sabit disk, LCD ekran.
* **Hocanın Vurgusu:**
  - Datapath'in nasıl çalıştığını "gözünüz kapalı" bilmelisiniz.
    - Bu kısmı bilirseniz dersin yaklaşık %30'unu biliyorsunuz demektir.
  - Fonksiyon birimindeki hiçbir blokta senkron eleman (flip-flop) yoktur.
    - Hepsi kombinasyonel devredir. Amaç bir clock periyodunda bir mikro işlem yapan tek çevrimli bilgisayardır.
  - Kontrol kelimesi soruları klasik sınavlarda sık ve kolay sorulardır.
    - Tablolar sınavda önünüzde olur. Ezberlemeye gerek yok.
  - Zero fill ile sign extend farklı işlemlerdir.
    - Zero fill: yüksek bitler 0 ile doldurulur (immediate operand).
  - CPU = kontrol birimi + datapath. "Yıllar sonra aklınızda kalacak temel konu budur."

### 🔹 Ders 11: Seri İletişim, Veri Transfer Yöntemleri, Öncelikli Kesmeler, DMA ve Önbelleğe Giriş
* **Genel Konular:**
  - Dersin tarihi 28 Mayıs 2021 Cuma. Ders Zoom üzerinden yapıldı.
    - Asıl anlatım yaklaşık 00:04'te başlar.
  - Pipeline hakkında kısa cevap
    - Veri bağımlılığı derleyici (compiler) düzeyinde yazılımla ya da donanımla çözülebilir. Ayrıntısı Bilgisayar Mimarisi dersinde.
  - G/Ç tekrarı
    - Çevre birimleri, G/Ç arayüzü, isolated I/O ve memory-mapped I/O, chip select, strobing ve handshaking.
  - Seri iletişim
    - Asenkron ve senkron seri haberleşme. Start, stop ve parity bitleri. UART/USART.
  - Veri transfer yöntemleri (modes of transfer)
    - Program kontrollü transfer (programmed I/O, yoklama/polling).
  - Öncelikli kesme donanımı
    - Daisy chain (seri) öncelik ve paralel öncelik donanımı.
  - DMA denetleyicisi (DMA controller)
* **Hocanın Vurgusu:**
  - Bu konular mesleğin "arka yüzüdür".
    - Bilgisayarın portlarla ve cihazlarla nasıl haberleştiğini teknik olarak öğreniyorsunuz.
  - Program kontrollü transfer işlemciyi bloke eder.
    - Bilgisayarda kullanılmaz. Tek işi olan küçük, özel (dedicated) bir donanımda kullanılabilir.
  - Bilgisayarda tercih edilen yöntem kesme ile transferdir.
    - Büyük veri blokları için DMA kullanılır.
  - Daisy chain'de acknowledge işaretini ilk alan birim en yüksek önceliğe sahiptir.
  - DMA'da CPU devre dışı bırakılır.
    - Bus request ve bus grant işaretleri bu yüzden çok önemlidir.

### 🔹 Ders 12: Cache Bellek: Bellek Hiyerarşisi, Yerellik İlkesi, Direct Mapped Cache, Ortalama Erişim Süresi ve Yazma Politikaları
* **Genel Konular:**
  - Dersin tarihi 4 Haziran 2021 Cuma. Ders Zoom üzerinden yapıldı.
    - Asıl ders yaklaşık 00:07'de başlar. Kaydın başı bekleme kısmıdır.
  - Önceki konulara dair öğrenci soruları
    - Interface sorusu (soru 3): adres hattı numarasındaki bir hata düzeltildi.
  - Cache memory (önbellek)
    - Bellek hiyerarşisi (memory hierarchy): register, L1 cache, L2 cache, ana bellek (DRAM), disk.
* **Hocanın Vurgusu:**
  - Dersin son dört haftası en önemli konuları içerir.
    - Giriş/çıkış ve iletişim, cache memory ve virtual memory finalde ağırlıklı sorulacak.
  - Cache konusunda ezber gerekmez.
    - Matematiği dikkatli takip ederseniz her soruyu çözebilirsiniz.
  - Word, veri yolu genişliği kadardır.
    - 32 bit veri yolunda 1 word = 4 byte. 64 bit veri yolunda 1 word = 8 byte.
  - Cache kapasitesi yalnız veri (data) kapasitesidir.
    - Tag, valid ve dirty bitleri kapasite hesabına katılmaz.
  - Cache'te adresin tamamı değil, yalnız tag alanı saklanır.
    - Index ve offset alanları satırın yerinden ve satır içindeki konumdan zaten bellidir.

### 🔹 Ders 13: Sanal Bellek: Adres Dönüşümü, Sayfa Tablosu, TLB, Sayfa Yerine Koyma ve Final Bilgilendirmesi
* **Genel Konular:**
  - Dersin tarihi 11 Haziran 2021 Cuma. Dönemin son dersidir. Ders Zoom üzerinden yapıldı.
    - Asıl ders yaklaşık 00:07'de başlar. Kaydın başı bekleme kısmıdır.
  - Cache tekrarı
    - Cache zorunlu değildir, sistemi hızlandırır.
  - Sanal bellek (virtual memory)
    - Sanal adresten fiziksel adrese dönüşüm (address translation).
  - Örnekler
    - 48 bit sanal adres, 4 KB sayfa: sayfa tablosu büyüklüğü.
  - Final ve kapanış bilgileri.
* **Hocanın Vurgusu:**
  - Son haftaların konuları (cache ve virtual memory) mesleğiniz için çok önemli.
    - Bu konu İşletim Sistemleri dersiyle bağlantılıdır. Donanım tarafını bilmek orada işinizi kolaylaştırır.
  - Zamansal yerellik ve uzamsal yerellik kavramlarını yıllar sonra bile hatırlamalısınız.
    - Yüksek lisans mülakatlarında sıkça sorulur.
  - Her bellek seviyesi, bir üst (daha büyük) seviyenin bir alt kümesini tutar.
    - Cache ana belleğin, ana bellek de diskin bir parçasını tutar.
  - Sanal bellekte birim **sayfa**dır, cache'te **blok**tur.
    - Cache'teki miss'in karşılığı sanal bellekte **page fault**'tur.
  - Sanal bellekte yerleştirme her zaman fully associative'dir (sayfa tablosu üzerinden).
    - Yazma politikası yalnız write-back'tir. Sayfa çok büyük olduğu için her yazmada diske gidilmez.

**Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
