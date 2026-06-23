# Ders 13 Çalışma Özeti

## Genel Konular

- Donanımsal kesmelerin asenkron yapısı
  - Dış çevre birimlerinden (klavye, zamanlayıcı vb.) gelen kesme sinyalleri ele alınır.
- Kesme denetleyicisi (8259 PIC)
  - Çoklu donanımsal kesmeleri ve bunların öncelik sıralamasını yöneten donanım yongası anlatılır.
- STI ve CLI komutları ile kesme kontrolü
  - CLI ile kesmelerin maskelenmesi (kapatılması) ve STI ile tekrar açılması işlemleri gösterilir.

## Hocanın Özellikle Vurguladığı Kısımlar

- Donanımsal kesmelerin program akışından bağımsız (asenkron) oluşu
  - Herhangi bir kod satırında aniden tetiklenebilme özelliği.
- Kritik kod bloklarında CLI ile kesmelerin kapatılması gerekliliği
  - Bölünmemesi gereken hassas işlemler (örn. kesme vektörü güncelleme) sırasında kesmelerin CLI ile kapatılıp sonrasında STI ile açılması.
- Maskelenebilir (INTR) ve maskelenemez (NMI) kesme ayrımı
  - Hayati donanım hatalarının NMI pini üzerinden maskelenemez şekilde işlemciye doğrudan iletildiği.

## Kısa Tekrar Notları

- Donanımsal kesmeler çevre birimlerinden gelir.
- 8259 PIC öncelikleri yönetir.
- CLI kesmeleri kapatır, STI açar. NMI maskelenemeyen en yüksek öncelikli donanım kesmesidir.

## Detaylı Açıklamalar (Daha Fazla Detay İsteyenler İçin)

Donanımsal kesmeler, klavye, zamanlayıcı veya disk gibi dış donanım birimlerinden gelen asenkron sinyallerdir. Bu kesmeler işlemcinin INTR (Interrupt Request) veya NMI (Non-Maskable Interrupt) pinleri üzerinden iletilir. Çoklu donanım kesmelerini ve önceliklerini yönetmek için 8259A PIC (Programmable Interrupt Controller - Programlanabilir Kesme Denetleyicisi) yongası kullanılır. CLI (Clear Interrupt Flag) komutuyla maskelenebilir kesmeler (INTR) devre dışı bırakılırken, STI (Set Interrupt Flag) komutuyla tekrar etkinleştirilir. NMI ise hayati donanım hataları için kullanılır ve maskelenemez (CLI'dan etkilenmez).

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
