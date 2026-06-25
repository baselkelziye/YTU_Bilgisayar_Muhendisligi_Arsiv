# Ders 14 Çalışma Özeti

## Genel Konular

- RAM Türleri
  - **SRAM (Static RAM):** Flip-flop tabanlı, yenileme gerektirmez, hızlı, pahalı, az yoğunluk
  - **DRAM (Dynamic RAM):** Kapasitör tabanlı, düzenli yenileme gerektirir, yavaş, ucuz, yüksek yoğunluk
  - SRAM: Cache belleklerde, DRAM: Ana belleklerde kullanılır
  - Yenileme (refresh) işlemi DRAM'ın en önemli özelliğidir
  - Kapasitörler zamanla deşarj olur, bu yüzden belirli aralıklarla yenilenmelidir

- DMA (Direct Memory Access)
  - İşlemci olmadan doğrudan bellek erişimi
  - Veri transferi için DMA denetleyicisi kullanılır
  - 8257/8237 DMA denetleyici çipleri
  - İşlemciyi yorgunluktan kurtarır (verimlilik artırır)
  - Blok veri transferlerinde tercih edilir

- Final Sınavı Konuları Özeti
  - **8255:** Parallel Port (A, B, C portları, Mode 0-2)
  - **8253:** Programmable Interval Timer (3 counter, Mod 0-5)
  - **8259:** Programmable Interrupt Controller (IRQ0-IRQ7, ICW/OCW)
  - **ADC0804:** A/D Dönüştürücü (8-bit, EOC handshake)
  - **DAC0808:** D/A Dönüştürücü (8-bit, analog çıkış)
  - Tüm bu çiplerin 8086 ile arayüzleme yöntemleri

- Sistem Entegrasyonu
  - Tüm çipler aynı veri bus'ına bağlı
  - Chip Select (CS) ile adresleme
  - Kontrol sinyalleri (RD, WR, IO/M)
  - Kesme ve DMA kullanımı
  - Gerçek zamanlı uygulama örnekleri

## Hocanın Özellikle Vurguladığı Kısımlar

- SRAM ve DRAM arasındaki temel farkın yenileme ihtiyacı olduğunu
- DMA'nın verimlilik açısından önemini
- Final sınavında tüm konuların entegre sorulacağını
- Her çipin arayüzleme yönteminin sınavda sorulacağını
- Zamanlama diyagramlarının önemini
- Pratik uygulama örneklerine odaklanılması gerektiğini

## Kısa Tekrar Notları

- SRAM: Flip-flop, hızlı, pahalı, yenileme yok
- DRAM: Kapasitör, yavaş, ucuz, yenileme var
- DMA: İşlemci olmadan bellek erişimi
- 8255: Parallel port (3 port, 3 mode)
- 8253: Timer (3 counter, 6 mod)
- 8259: Kesme denetleyicisi (8 IRQ, 4 ICW)
- ADC0804: A/D (8-bit, EOC handshake)
- DAC0808: D/A (8-bit, analog çıkış)
- Tüm çipler 8086 veri bus'ına bağlı

## Detaylı Açıklamalar (Daha Fazla Detay İsteyenler İçin)

SRAM (Static RAM) flip-flop devreleri kullanarak verileri saklar. Yenileme gerektirmediği için hızlıdır ancak pahalıdır. Bu yüzden önbellek (cache) belleklerde kullanılır. DRAM (Dynamic RAM) ise kapasitörler kullanır ve zamanla deşarj oldukları için düzenli yenileme işlemine ihtiyaç duyar. Ancak daha ucuz ve yoğun olduğu için ana belleklerde tercih edilir.

DMA (Direct Memory Access), büyük blok veri transferlerinde işlemciyi devreden çıkarır. DMA denetleyicisi doğrudan bellek ve cihaz arasında veri transferi yapar. Bu sayede işlemci diğer işlemlere odaklanabilir ve sistem verimliliği artar.

Final sınavı tüm konuları kapsar. 8255 Parallel Port, 8253 Timer, 8259 Kesme Denetleyicisi, ADC0804 A/D dönüştürücü ve DAC0808 D/A dönüştürücüsü arasındaki entegrasyon sınavın odak noktasıdır. Tüm bu çipler 8086'nın aynı veri bus'ına bağlıdır ve Chip Select (CS) ile adreslenir.

Zamanlama diyagramları, her çipin çalışma zamanını gösterir. WR ve RD sinyallerinin zamanlaması, EOC el sıkışma süreci, kesme tetikleme anları gibi detaylar sınavda sıkça sorulur. Pratik uygulama örnekleri ile bu kavramların pekiştirilmesi önerilir.