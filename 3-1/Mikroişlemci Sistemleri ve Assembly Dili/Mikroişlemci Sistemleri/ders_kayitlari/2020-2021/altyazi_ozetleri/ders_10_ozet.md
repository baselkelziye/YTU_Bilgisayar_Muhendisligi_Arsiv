# Ders 10 Çalışma Özeti

## Genel Konular

- 8253 Mod 4 ve Mod 5 Detayları
  - **Mod 4:** Software Triggered Strobe - Yazılım tetiklemeli strobe sinyali
  - **Mod 5:** Hardware Triggered Strobe - Donanım tetiklemeli strobe sinyali
  - Gate pini Mod 5'te aktif, Mod 4'te pasif
  - Her iki modda da sayma bittiğinde OUT pini aktif olur

- CLK/OUT Sinyal Dalgaları
  - CLK giriş sinyalinin frekansı
  - OUT çıkış sinyalinin frekansı (CLK / divisor)
  - Mod 3'te simetrik kare dalga
  - Diğer modlarda asimetrik çıkış

- Frekans Bölücü Örnekleri
  - Örnek 1: 2 MHz → 500 Hz (divisor = 4000)
  - Örnek 2: 1.193182 MHz → 1 kHz (divisor = 1193)
  - Örnek 3: 10 MHz → 100 Hz (divisor = 100000)
  - BCD modunda 4 haneli değerler (0-9999)
  - Binary modunda 16-bit değerler (0-65535)

- Üç Counter'ın Programlanması
  - Counter 0: Sistem saatini bölmek için
  - Counter 1: Periyodik kesme üretmek için
  - Counter 2: Ses frekansı oluşturmak için
  - Her counter için ayrı kontrol kelimesi yazılması
  - Sıralı programlama: Önce kontrol kelimesi, sonra divisor değeri

## Hocanın Özellikle Vurguladığı Kısımlar

- Mod 4 ve Mod 5 arasındaki temel farkın Gate pini olduğunu
- CLK/OUT sinyal dalgalarının sınavda çizim olarak sorulabileceğini
- Frekans bölücü hesaplamalarında BCD ve Binary mod farkının önemli olduğunu
- Üç counter'ın birlikte kullanımının gerçek hayat uygulamalarında sık rastlandığını
- Divisor değerinin 0 yazılmasının 65536 (Binary) veya 10000 (BCD) anlamına geldiğini

## Kısa Tekrar Notları

- Mod 4: Yazılım tetiklemeli strobe (Gate pasif)
- Mod 5: Donanım tetiklemeli strobe (Gate aktif)
- CLK/OUT oranı = divisor değeri
- Mod 3: Simetrik kare dalga, diğerleri asimetrik
- Divisor 0 → 65536 (Binary) veya 10000 (BCD)
- Üç counter bağımsız çalışır
- Programlama sırası: Kontrol kelimesi → Divisor (LSB → MSB)

## Detaylı Açıklamalar (Daha Fazla Detay İsteyenler İçin)

Mod 4 (Software Triggered Strobe) ve Mod 5 (Hardware Triggered Strobe) birbirine benzer modlardır, ancak tetikleme kaynağında farklılık gösterir. Mod 4'te sayma işlemi yazılım tarafından başlatılırken, Mod 5'te Gate pini tarafından donanım tetiklemesi yapılır.

CLK/OUT sinyal dalgaları, 8253'ün çıkış davranışını gösterir. Mod 3'te çıkış sinyali giriş sinyalinin divisor katı kadar bölünür ve simetrik bir kare dalga oluşur. Diğer modlarda ise çıkış sinyali asimetrik olabilir.

Frekans bölücü uygulamalarında divisor değeri kritiktir. Örneğin 2 MHz'lik bir giriş sinyalini 500 Hz'e bölmek için divisor = 2.000.000 / 500 = 4000 olarak ayarlanır. BCD modunda bu değer 4 hanede (0-9999), Binary modunda ise 16-bit'te (0-65535) ifade edilir.

Üç counter'ın birlikte kullanımı gerçek hayat uygulamalarında sık görülür. Örneğin bir bilgisayar sisteminde Counter 0 sistem saatini böler, Counter 1 periyodik kesme üretir, Counter 2 ise ses frekansı oluşturur. Her counter için ayrı kontrol kelimesi yazılır ve divisor değeri LSB'den MSB'ye doğru sırayla yerleştirilir.