# Ders 9 Çalışma Özeti

## Genel Konular

- 8253 Programlanabilir Aralık Zamanlayıcısı
  - 3 bağımsız 16-bit counter
  - Her counter için 6 farklı Mod (0-5)
  - Kontrol kelime register'ı ile yapılandırma
  - BCD (0-9999) ve Binary (0-65535) sayma modları
  - Gate pini sayesinde counting kontrolü
  - OUT pini ile dışarıya sinyal çıkışı
  - Read-back komutu ile sayaç değeri okuma

- 8253 Modları
  - **Mod 0:** Interrupt on Terminal Count - Sayma bittiğinde kesme sinyali
  - **Mod 1:** Programmable One-Shot - Tek atış modu
  - **Mod 2:** Rate Generator - Periyodik sinyal üretimi
  - **Mod 3:** Square Wave Generator - Kare dalga üretimi (en sık kullanılan)
  - **Mod 4:** Software Triggered Strobe
  - **Mod 5:** Hardware Triggered Strobe

- Frekans Bölücü Uygulamaları
  - Giriş frekansının belirli bir oranda bölünmesi
  - Örnek: 1 MHz giriş → 1 kHz çıkış için divisor = 1000
  - Kontrol kelimesi ile bölücü değerinin ayarlanması

## Hocanın Özellikle Vurguladığı Kısımlar

- Mod 3'ün (kare dalga) en çok tercih edilen mod olduğunu
- Kontrol kelimesinin bileşenlerini: SC (seçim), RW (okuma/yazma), MCD (mod), BCD (tür)
- Gate pininin sadece Mod 1 ve Mod 5'te aktif olduğunu, diğer modlarda Gate'in etkisiz olduğunu
- Read-back komutunun 8253'ün önemli bir özelliği olduğunu ve sınavda sorulabileceğini
- Frekans bölücü hesaplamalarında BCD modunda 4 haneli, Binary modunda 16-bit değerlerin kullanıldığını

## Kısa Tekrar Notları

- 8253 = 3 bağımsız 16-bit counter
- Kontrol kelimesi: SC(2bit) + RW(2bit) + MCD(3bit) + BCD(1bit)
- Mod 3 = kare dalga (en yaygın)
- Gate pini: Mod 1 ve 5'te saymayı başlatır/durdurur
- OUT pini: Sayma bittiğinde veya Mod 3'te kare dalga çıkışı
- Read-back: Counter değerini programdan okumaya olanak tanır
- BCD modu: 0-9999 arası, Binary modu: 0-65535 arası

## Detaylı Açıklamalar (Daha Fazla Detay İsteyenler İçin)

8253 programlanabilir aralık zamanlayıcısı, mikro işlemci sistemlerinde zamanlama ve sayma işlemleri için kullanılan kritik bir çiptir. Üç bağımsız 16-bit counter'a sahiptir ve her biri ayrı ayrı yapılandırılabilir.

Kontrol kelimesi register'ı, her counter'ın nasıl çalışacağını belirler. SC (Select Counter) alanı hangi counter'ın seçileceğini, RW (Read/Write) alanı okuma/yazma modunu, MCD (Mode) alanı çalışma modunu, BCD alanı ise sayma türünü (BCD veya Binary) belirler.

Mod 3 (Square Wave Generator) özellikle saat sinyali üretimi ve frekans bölücü uygulamalarında en çok tercih edilen moddur. Bu modda counter, çıkışta simetrik bir kare dalga üretir. Örneğin 1 MHz'lik bir giriş saat sinyalini 1 kHz'e bölmek için divisor değeri 1000 olarak ayarlanır.

Gate pini, Mod 1 ve Mod 5'te sayma işlemini başlatır veya durdurur. Diğer modlarda Gate pini sayma sürecini etkilemez. OUT pini ise sayma bittiğinde veya Mod 3'te kare dalga çıktısı sağlar.

Read-back komutu, 8253'ün gelişmiş bir özelliğidir ve sayaç değerinin program tarafından okunmasını sağlar. Bu özellik, zamanlama uygulamalarında kritik öneme sahiptir.