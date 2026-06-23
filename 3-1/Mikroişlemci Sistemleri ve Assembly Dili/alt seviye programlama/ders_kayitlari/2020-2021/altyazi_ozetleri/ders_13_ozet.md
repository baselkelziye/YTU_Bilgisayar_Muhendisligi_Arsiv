# Ders 13 Çalışma Özeti

## Genel Konular

- Donanımsal kesmeler ve kesme denetleyicisi (8259 PIC)
- Kesmelerin öncelik mekanizmaları, kesme birleştirme ve maskeleme işlemleri
- STI (Enable Interrupts) ve CLI (Disable Interrupts) komutları

## Hocanın Özellikle Vurguladığı Kısımlar

- Donanımsal kesmelerin asenkron yapısı ve işlemciye nasıl iletildiği.
- Kritik kod bloklarında CLI ile kesmelerin kapatılması ve STI ile tekrar açılması gerekliliği.
- Maskelenebilir (INTR) ve maskelenemez (NMI) kesme ayrımları.

## Kısa Tekrar Notları

- Donanımsal kesmeler çevre birimlerinden gelir.
- 8259 PIC öncelikleri yönetir.
- CLI kesmeleri kapatır, STI açar. NMI maskelenemeyen en yüksek öncelikli donanım kesmesidir.
