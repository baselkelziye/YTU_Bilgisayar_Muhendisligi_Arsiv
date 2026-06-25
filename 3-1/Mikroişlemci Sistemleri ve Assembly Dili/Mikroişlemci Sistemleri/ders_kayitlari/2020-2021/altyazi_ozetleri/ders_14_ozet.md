# Ders 14 Çalışma Özeti

## Genel Konular

- **Hafıza Birimleri Temelleri (ROM ve RAM)**
  - ROM (Read Only Memory): Sadece okunabilen, enerji kesildiğinde verisi kaybolmayan (non-volatile) hafıza birimi. BIOS, ön yükleme programları gibi kalıcı bilgilerin saklanmasında kullanılır.
  - RAM (Random Access Memory): Hem okuma hem yazma yapılabilen, enerji kesildiğinde verisi silinen (volatile) hafıza birimi. Bilgisayarlarda ana bellek olarak kullanılır.

- **ROM Çeşitleri**
  - Mask ROM: Fabrikada donanımsal olarak programlanan, sonradan değiştirilemeyen ROM tipi.
  - PROM (OTP): Bir kez programlanabilen ROM; fusible link teknolojisi ile çalışır.
  - EPROM: Ultraviyole ışık ile silinip tekrar programlanabilen ROM (15-20 dakika UV ışık).
  - EEPROM (E²PROM): Elektriksel olarak silinip programlanabilen ROM.
  - Flash ROM: Güncel sistemlerde kullanılan, hızlı silme/yazma özelliğine sahip ROM türü (USB flash bellekler, anakart BIOS'ları).

- **ROM Yapısı ve Programlama**
  - Adresleme ve dekoder yapısı: N adres ucu ile 2^N satır adreslenir; M data yolu ile M bitlik veri okunur.
  - n×m notasyonu: Örneğin 4×4 ROM = 4 satır × 4 bit veri; 12×16 ROM = 2^12 satır × 16 bit veri.
  - Programlama mantığı: Kablo bağlantısı (kablo varsa 0, yoksa 1) ile her satırın verisinin belirlenmesi; her satıra "sel" (cell) denir.
  - CS (Chip Select) ve OE (Output Enable) pinleri: CS adres çözümleme için, OE okuma kontrolü için kullanılır.

- **SRAM (Statik RAM)**
  - Transistör tabanlı flip-flop hücre yapısı ile veri saklama; elektrik olduğu sürece veri korunur.
  - Çok hızlı erişim süresi; CPU önbellek (cache), stack gibi yüksek hızlı uygulamalarda kullanılır.
  - Yazma: Wordline aktif edilir, Bitline ve Bitline-bar'a zıt değerler verilerek hücre kilitlenir.
  - Okuma: Wordline aktif edilir, hücredeki değer Bitline'lardan okunur.
  - WE (Write Enable) ve RE (Read Enable) pinleri: RAM için ayrı ayrı adres çözünmesi gerekir.

- **DRAM (Dynamic RAM)**
  - Kapasitör + transistör hücre yapısı; kapasitörün şarj/deşarj durumu ile veri saklanır.
  - Dezavantajları: Yavaş erişim; kapasitörün zamanla deşarj olması nedeniyle periyodik refresh sinyali gerekliliği.
  - Avantajları: Ucuz, küçük alanda yüksek kapasite (GB seviyesinde ana bellek).
  - DDR RAM'lerdeki refresh hızı belirtimleri (örn. 5-5-16): FSB frekansında refresh sıklığını gösterir.
  - DRAM'de satır (row) ve sütun (column) adresleme: Aynı adres pinleri sırayla satır ve sütun seçimi için kullanılır (multiplexing).

- **8086'da Hafıza Organizasyonu**
  - 8086: 20 adres ucu (2^20 = 1 MB adres uzayı) ve 16 veri ucu.
  - Hafıza modülleri genellikle 8 bitlik olduğundan, 16 bit veri yolu için çift bank (even) ve tek bank (odd) yapısı kullanılır.
  - Çift bank: A0=0 olan adresler (0, 2, 4, ...); D0-D7 veri yoluna bağlı.
  - Tek bank: A0=1 olan adresler (1, 3, 5, ...); D8-D15 veri yoluna bağlı.
  - BHE (Bus High Enable): D8-D15 arası veri yolunun etkinliğini kontrol eder; BHE=0 iken yüksek anlamlı 8 bit aktif.

- **8086'da Tek Cycle İşlem Türleri**
  - Çift adresten 16 bit okuma: A0=0, BHE=0 → tek cycle'da hem çift hem tek banktan 16 bit veri.
  - Çift adresten 8 bit okuma: A0=0, BHE=1 → sadece D0-D7'den 8 bit veri.
  - Tek adresten 8 bit okuma: A0=1, BHE=0 → sadece D8-D15'ten 8 bit veri.
  - Tek adresten 16 bit okuma: Tek cycle'da yapılamaz; 2 cycle gerekir (önce tek banktan 8 bit, sonra çift banktan 8 bit).

- **Adres Çözümleme Yöntemleri**
  - Separate Bank Decoder: A0 ve BHE pinleri chip select'e girilerek bank seçimi yapılır; adres çözümlemede kullanılır.
  - Separate Bank Strop: A0 ve BHE pinleri chip select'e değil, read/write enable mantığına bağlanır; adres çözümlemesi sadece A12-A19 gibi üst adres pinleriyle yapılır.
  - Memory vs I/O adresleme: M/IO̅ pini ile hafıza (0) veya giriş/çıkış (1) uzayı seçimi.

## Hocanın Özellikle Vurguladığı Kısımlar

- **Tek adresten 16 bit işlem tek cycle'da yapılamaz**: A0=1 verilince çift bank devre dışı kalır; BHE=0 verilince A0=0 olması gerekir (çelişki). Bu nedenle 2 cycle gerekir.
- **Çift adresten 16 bit = çift + sonraki tek adres**: Örneğin adres 1000H'den 16 bit okuma → 1000H (çift) + 1001H (tek) birlikte okunur.
- **Tek adresten 16 bit = tek + sonraki çift adres**: Örneğin adres 1001H'den 16 bit okuma → 1001H (tek) + 1002H (çift) iki ayrı cycle'da okunur.
- **Dekoder bubble (baloncuğu)**: Çıkışta bubble varsa seçilen uçtan 0 çıkar; enable'da bubble varsa 0'da enable olur.
- **Adres çözümlemede dokunulmaması gereken pinler**: A0-A11 gibi alt adres pinleri doğrudan hafıza modülünün iç satır adreslemesi için bağlanır; adres çözümleme devresi A12-A19 gibi üst pinlerle yapılır.
- **ROM sorularında sadece OE (Output Enable) adres çözülür**: RAM'de hem WE hem RE için ayrı adres çözülmesi gerekir.

## Kısa Tekrar Notları

- ROM: Non-volatile, sadece okunabilir. RAM: Volatile, okuma+yazma.
- ROM çeşitleri: Mask ROM → PROM → EPROM → EEPROM → Flash ROM (kronolojik gelişim).
- n×m ROM: n=adreslenebilir satır sayısı (2^N), m=data yolu genişliği.
- SRAM: Flip-flop tabanlı, hızlı, düşük kapasite (MB), CPU cache'de kullanılır.
- DRAM: Kapasitör tabanlı, yavaş, yüksek kapasite (GB), refresh gerekir, ana bellekte kullanılır.
- 8086: 20 adres ucu (1 MB), 16 veri ucu.
- Even bank (çift): A0=0, D0-D7; Odd bank (tek): A0=1, D8-D15.
- BHE=0 → D8-D15 aktif; BHE=1 → D8-D15 pasif.
- Çift adresten 16 bit: A0=0, BHE=0 → 1 cycle.
- Tek adresten 16 bit: 2 cycle gerekir.
- Separate Bank Decoder: A0+BHE chip select'te kullanılır.
- Separate Bank Strop: A0+BHE read/write enable'da kullanılır.

## Detaylı Açıklamalar (Daha Fazla Detay İsteyenler İçin)

**8086 Hafıza Bank Yapısı:**
8086'nın 16 bitlik veri yolu olmasına rağmen, hafıza modülleri genellikle 8 bit genişliğinde üretilir. Bu nedenle fiziksel olarak tek bir hafıza bloğu kullanılırken, adresleme açısından ikiye ayrılır: çift (even) bank ve tek (odd) bank. Çift bank A0=0 olan adresleri (0, 2, 4, ...) içerir ve veri yolunun alt 8 bitine (D0-D7) bağlanır. Tek bank A0=1 olan adresleri (1, 3, 5, ...) içerir ve veri yolunun üst 8 bitine (D8-D15) bağlanır. Bu yapı sayesinde:
- Çift adresten 16 bit okuma (A0=0, BHE=0): Tek cycle'da AL=çift bank, AH=tek bank.
- Tek adresten 8 bit okuma (A0=1, BHE=0): Tek cycle'da sadece AH'ye tek bank verisi.
- Çift adresten 8 bit okuma (A0=0, BHE=1): Tek cycle'da sadece AL'ye çift bank verisi.

**DRAM'de Row/Column Multiplexing:**
DRAM'de adres pinleri hem satır hem sütun seçimi için kullanılır. Örneğin 3 adres pini ile 8 satır ve 8 sütun adreslenerek 64 hücreye erişim sağlanır. İlk olarak satır adresi latch'lenir (RAS - Row Address Strobe), ardından sütun adresi latch'lenir (CAS - Column Address Strobe). Bu multiplexing sayesinde daha az pin ile daha büyük kapasite adreslenebilir.

**Adres Çözümleme Örnek Yaklaşımı:**
Bir soruda belirli bir adres aralığına ROM/RAM yerleştirilecekse:
1. Adres aralığının binary karşılığı yazılır; hangi pinlerin sabit (1 veya 0) olduğu belirlenir.
2. Sabit olmayan alt adres pinleri (örn. A0-A10) doğrudan hafıza modülünün iç adreslemesine bağlanır.
3. Sabit olan üst adres pinleri (örn. A11-A19) ve M/IO̅, A0, BHE gibi kontrol pinleri adres çözümleme mantığına (NAND/NOR kapıları veya dekoder) girer.
4. ROM ise sadece OE (veya CS) adres çözülür; RAM ise hem WE hem RE için ayrı mantık kurulur.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
