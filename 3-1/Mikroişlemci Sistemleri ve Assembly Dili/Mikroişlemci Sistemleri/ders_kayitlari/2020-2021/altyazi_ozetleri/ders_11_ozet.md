# Ders 11 Çalışma Özeti

## Genel Konular

- **Analog-Dijital Sinyal Dönüşümleri (ADC/DAC)**
  - Analog sinyallerin sürekli (continuous) ve zamanda değişken doğası; dijital sinyallerin ise ayrık (discrete) yapıda olması.
  - Fiziksel dünyadaki sıcaklık, basınç gibi değerlerin sensörler aracılığıyla analog elektriksel sinyallere dönüştürülmesi ve bu sinyallerin mikro işlemci tarafından işlenebilmesi için dijital formata (ADC) çevrilmesi gerekliliği.
  - İşlenmiş dijital sinyalin tekrar analog forma (DAC) dönüştürülerek hoparlör, motor gibi aktüatörlere iletilmesi.

- **DAC (Digital-to-Analog Converter) Devreleri**
  - R-2R merdiven direnç ağı yapısı: Binary girişlerin analog gerilime dönüştürülmesinde kullanılan temel devre topolojisi.
  - Op-amp (işlemsel yükselteç) tabanlı toplayıcı devre ile R-2R ağının birlikte kullanımı; MSB ve LSB bitlerin direnç değerleriyle orantılı katkısı.
  - DAC0808 entegresi: 8 bitlik dijital girişi analog çıkışa dönüştüren entegre yapısı, chip select, ILE, write ve xfer pinlerinin çalışma mantığı.
  - DAC'ta leçleme (latch) işlemi: Dijital verinin sabitlenerek analog çıkışın korunması; write sinyalinin düşen kenarıyla verinin register'a aktarılması.

- **ADC (Analog-to-Digital Converter) Devreleri**
  - Comparator (karşılaştırıcı) tabanlı ADC mantığı: Referans gerilimleri ile giriş sinyalinin karşılaştırılması ve priority encoder ile binary karşılığın elde edilmesi.
  - Counter tabanlı ADC yapısı: FF'den aşağıya doğru sayan bir counter ile DAC üzerinden üretilen analog sinyalin giriş sinyaliyle karşılaştırılması; eşleşme anında interrupt oluşması.
  - ADC entegresi: Clock, interrupt (INTR), chip select, read/write pinleri ve adresleme yapısı.

- **Assembly Kodu Örnekleri**
  - DAC örneği: 00H'dan FFH'a kadar artan değerlerin port'a gönderilmesiyle testere dişi (sawtooth) sinyali üretilmesi.
  - ADC örneği: İki aşamalı adresleme (önce chip select ile dönüşüm başlatma, sonra interrupt kontrolü ile dijital veriyi okuma).

- **Kesmelere (Interrupt) Giriş**
  - Yazılımsal kesmeler (INT 0, INT 3) ve donanımsal kesmeler (INTR, NMI) kavramları.
  - Kesme vektör tablosu: 1024 byte'lık alan, 256 farklı kesme, her kesme için 4 byte (CS + IP).
  - Kesme işleminin gerçekleştirilme adımları: Bayrak register'ının stack'e push edilmesi, IF ve TF'nin sıfırlanması, CS ve IP'nin stack'e yazılması, vektör tablosundan yeni adreslerin yüklenmesi.

## Hocanın Özellikle Vurguladığı Kısımlar

- **DAC ve ADC'de cycle farkı**: DAC tek cycle'da işlem yaparken, ADC iki cycle'da işlem gerçekleştirir (önce dönüşüm başlatılır, sonra interrupt ile sonuç okunur).
- **Testere dişi sinyali**: 00H'dan FFH'a kadar lineer artış ve sonra sıfırlanma ile oluşan sinyal formu; sinüs dalgası için farklı (lineer olmayan) değer dizileri gerektiği.
- **Kesme vektör tablosunda adres hesabı**: Her kesme tipinin adresi = tip no × 4 (örneğin tip 4 → 10H adresinden başlar).
- **IF bayrağının önemi**: IF=1 iken donanımsal INTR kesmeleri alınabilir; kesme routinesinde IF=0 yapılarak iç içe kesmeler engellenir.
- **NMI (Non-Maskable Interrupt)**: Maskeleyemeyen, en yüksek öncelikli donanımsal kesme; tip 2 olarak vektör tablosunda 08H adresinde yer alır.

## Kısa Tekrar Notları

- Analog sinyal: Zamanda ve genlikte sürekli; dijital sinyal: Zamanda ve genlikte ayrık.
- ADC: Analog→Dijital; DAC: Dijital→Analog dönüşüm sağlar.
- R-2R merdiven ağı: DAC'ta kullanılan, sadece R ve 2R değerinde dirençlerle binary-to-analog dönüşüm yapan devre.
- DAC0808: Chip select (CS), ILE, WR1, WR2, XFER pinleriyle kontrol edilen 8 bit DAC entegresi.
- ADC'de interrupt (D7/INTR pini): Dönüşüm tamamlandığında 1 olur; okuma işlemi bu sinyal ile başlar.
- Kesme vektör tablosu: 0000H-03FFH arası, 256 kesme, her biri 4 byte (2 byte offset + 2 byte segment).
- Tip 0: Sıfıra bölme; Tip 1: Single step (debug); Tip 2: NMI; Tip 3: Breakpoint; Tip 4: Overflow.
- Kesme routinesinde: Flags push → IF=0, TF=0 → CS push → IP push → Vektör tablosundan yeni CS/IP → IRET ile dönüş.
- STI: IF=1 yapar (kesmeleri açar); CLI: IF=0 yapar (kesmeleri kapatır).

## Detaylı Açıklamalar (Daha Fazla Detay İsteyenler İçin)

**DAC Çalışma Prensibi (R-2R Ağı):**
R-2R merdiven direnç ağı, binary girişlerin her bir bitini analog gerilime dönüştüren bir yapıdır. MSB'den LSB'ye doğru her bit, bir öncekinin yarısı kadar etkiye sahiptir. Bu yapı, op-amp'ın tersleyen girişine bağlanır ve feedback direnci ile birlikte bir toplayıcı devre oluşturur. Formül: Vout = -(V1/R × Rf + V2/2R × Rf + V3/4R × Rf + ...). Örneğin 3 bitlik bir yapıda 1,1,1 gönderildiğinde maksimum çıkış (Vout = Vin) elde edilirken, 1,0,0 gönderildiğinde Vout = Vin × 4/7 olur.

**DAC0808 Entegresi Çalışma Akışı:**
1. CS=0 yapılır (entegre seçilir), ILE=1 olmalıdır.
2. WR1=0'a düşer → dijital veri input latch'e yazılır.
3. WR1=1'e çekilir → veri leçlenir.
4. WR2=0'a düşer → latch'teki veri DAC register'a aktarılır (XFER=0 olmalı).
5. R-2R ağı analog çıkış üretir.

**ADC Counter Tabanlı Çalışma Prensibi:**
ADC, FF'den başlayarak aşağıya doğru sayan bir counter ile dahili DAC üzerinden analog sinyal üretir. Bu sinyal girişteki analog gerilimle comparator'da karşılaştırılır. Counter'ın ürettiği sinyal giriş geriliminin altına düştüğünde comparator çıkışı 1 olur ve interrupt oluşur. Bu andaki counter değeri, giriş geriliminin dijital karşılığıdır.

**Kesme Vektör Tablosu Detayları:**
8086'da belleğin en başında (00000H-003FFH) bulunan 1024 byte'lık alandır. Her kesme tipi 4 byte yer kaplar: ilk 2 byte offset (IP), sonraki 2 byte segment (CS) bilgisidir. Tip numarası × 4 ile efektif adres hesaplanır. Örneğin tip 40 için: 40H × 4 = 100H adresine subroutine'in CS:IP değeri yazılır. Rezerve kesmeler (tip 0-31) sistem tarafından kullanılır; tip 32-255 arası kullanıcı tanımlı kesmeler için ayrılır.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
