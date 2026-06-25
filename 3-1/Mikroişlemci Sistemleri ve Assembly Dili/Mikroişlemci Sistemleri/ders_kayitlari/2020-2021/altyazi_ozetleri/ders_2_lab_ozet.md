# Ders 2 Lab Çalışma Özeti

## Genel Konular

- **Dersin İşleyişi ve Değerlendirme Sistemi**
  - Lab soruları hafta içi paylaşılacak, 3-4 günlük süre verilecek
  - Cuma günleri asistan tarafından ekran paylaşımı ve canlı demo ile değerlendirme yapılacak
  - Değerlendirme puanları: 0, 25, 50, 75, 100 (kademeli)
  - Gruplar farklı asistanlar tarafından dönüşümlü olarak değerlendirilecek

- **Proteus ile Devre Simülasyonu**
  - Ders için kullanılacak simülasyon ortamı Proteus'tur
  - Yeni proje oluşturulurken "New Project" → isim verme → "Create a schematic from the selected template" adımları izlenir
  - Firmware projesi oluşturulurken aile olarak 8086, compiler olarak MacroASM (MASM) seçilmeli
  - PCB oluşturulmayacak (Do not create PCB seçeneği kullanılacak)

- **8086 İşlemci Pin Yapısı**
  - **AD0-AD15 (Bus):** Adres ve veri yollarının ortak kullanıldığı 16 bitlik multiplex hat
    - Hem adres hem de data olarak kullanılır (time-division multiplex)
    - Kalın mavi çizgi ile gösterilir çünkü çoklu bit taşır
  - **ALE (Address Latch Enable):** AD hatlarının adres bilgisi taşıdığını gösteren sinyal
    - ALE=1 olduğunda bus'larda adres verisi bulunur
    - ALE=0'dan 1'e geçerken adres bilgisi latch'lenir
  - **BHE (Bus High Enable):** 16 bitlik bus'ın üst 8 bitinin (MSB) aktif olup olmadığını kontrol eder
    - Şapka (overline) ile gösterildiği için aktif-low'tur (0=aktif)
  - **MN/MX (Minimum/Maximum Mode):** İşlemcinin çalışma modunu belirler
    - MN=1: Minimum mod (ek buffer'a gerek yok)
    - MN=0: Maximum mod
    - Ders boyunca minimum mod kullanılacak
  - **RESET:** İşlemciyi başlangıç durumuna döndürür (toprağa bağlanmış, aktif-high)
  - **READY:** İşlemcinin çalışabilir durumda olduğunu gösterir
  - **HOLD/HOLD ACK:** DMA işlemleri için elde tutma sinyalleri
  - **TEST, NMI, CLK:** Sırasıyla test, maskelenemeyen kesme ve saat sinyali pinleri

## Hocanın Özellikle Vurguladığı Kısımlar

- **Proteus'ta Bus Bağlantıları:**
  - Bus terminalleri bağlanırken terminal kullanılmalı
  - Aynı isimdeki terminal etiketleri arka planda birbirine bağlı olur
  - Karmaşık tasarımlarda bus'ları fiziksel olarak çekmek yerine etiketleme yöntemi tercih edilmeli

- **Pin Sembolizminin Önemi:**
  - Şapka (overline) olan pinler aktif-low'tur (0 olduğunda aktif)
  - Şapka olmayan pinler aktif-high'tır (1 olduğunda aktif)
  - Bu ayrım devre tasarımında hayati önem taşır

- **Program File Yolu:**
  - İşlemci özelliklerinden program dosyası yolu kontrol edilmeli
  - Bazen proje oluşturulurken bu yol hatalı olabilir, çalışan bir projeden güncellenebilir

## Kısa Tekrar Notları

- Lab değerlendirmeleri bireysel olarak yapılacaktır
- Proteus'ta firmware projesi oluştururken MASM compiler'ı seçilmeli
- 8086'da adres 20 bit, data 16 bit; ilk 16 adres biti ile data yolu ortak kullanılır
- ALE sinyali bus'larda adres bilgisi olduğunu gösterir
- BHE pin'i üst byte'ın (D8-D15) aktifliğini kontrol eder
- Minimum modda ek buffer/devre elemanı gerektirmez
- Bus bağlantılarda terminal ve etiketleme yöntemi kullanılır

## Detaylı Açıklamalar (Daha Fazla Detay İsteyenler İçin)

**8086 Multiplex Bus Yapısı:** 8086 işlemcisi pin sayısını azaltmak için adres ve veri yollarını aynı hatlar üzerinden zaman bölmeli (time-division multiplex) olarak kullanır. AD0-AD15 olarak adlandırılan bu 16 hat, bir cycle'da adres, sonraki cycle'da data bilgisi taşır. ALE sinyali bu geçişi kontrol eder; ALE high olduğunda bus'larda adres bilgisi, ALE low olduğunda data bilgisi bulunur. Bu durum, fiziksel entegre devrede ek 16 bacak eklemek yerine daha verimli bir çözüm sağlar.

**Pin Aktif Seviyeleri:** 8086 pin diyagramında şapka (overline) sembolü olan pinler aktif-low olarak adlandırılır. Örneğin BHE^ (Bus High Enable) pini 0 seviyesine çekildiğinde üst byte aktif olur. MN/MX pininde ise şapka MX tarafındadır, yani MN=1 (high) olduğunda minimum mod aktif olur. Bu ayrımı doğru yapmak, devre tasarımında hatalı bağlantıları önler.

**Minimum vs. Maximum Mod:** Minimum modda 8086, tüm gerekli sinyalleri kendi üretir ve ek外部 devre elemanı gerektirmez. Maximum modda ise 8288 bus controller gibi ek çiplere ihtiyaç duyulur. Ders boyunca minimum mod kullanılacağı için MN pini 1'e bağlanmıştır (toprağa çekilmemiştir, VCC'ye bağlıdır).

**Proteus'ta Etiketleme:** Büyük ölçekli devre tasarımlarında tüm hatları fiziksel olarak çekmek karmaşıklığa yol açar. Proteus'ta terminal ekleyip aynı ismi vererek farklı noktaları arka planda birbirine bağlamak mümkündür. Bu yöntem, okunabilirliği artırır ve tasarım sürecini hızlandırır.
