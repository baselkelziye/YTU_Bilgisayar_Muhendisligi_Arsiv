# Ders 12 Çalışma Özeti

## Genel Konular

- 8259 Programlanabilir Kesme Denetleyicisi
  - 8 adet kesme hattı (IRQ0-IRQ7)
  - Öncelik tabanlı kesme yönetimi
  - Cascade modu ile 64'e kadar kesme genişletme
  - Tek (single) ve çoklu (cascade) çalışma modu
  - Yazılımsal polling seçeneği
  - ISR, IRR, IMR register'ları

- ICW (Initialization Command Words) Başlatma Dizisi
  - **ICW1:** Başlatma komutu, A7-A4 adresi, trigger modu
  - **ICW2:** Vektor adresi (kesme numaralama)
  - **ICW3:** Cascade modu yapılandırması (master/slave)
  - **ICW4:** 8086/8088 modu, EOI komutu türü

- OCW (Operation Command Words)
  - **OCW1:** IMR (Interrupt Mask Register) güncelleme
  - **OCW2:** EOI (End of Interrupt) komutu, öncelik sıralaması
  - **OCW3:** Okuma register seçimi, polling modu

- IRQ0-IRQ7 Öncelik Sıralaması
  - IRQ0: En yüksek öncelik (sistem saati)
  - IRQ1: Klavye
  - IRQ2: Cascade (master-slave bağlantısı)
  - IRQ3-IRQ7: Diğer cihazlar

## Hocanın Özellikle Vurguladığı Kısımlar

- ICW dizisinin sırasıyla yazılması gerektiğini (1→2→3→4)
- Her ICW'nin belirli port adreslerine yazıldığını
- IMR register'ının kesmeleri maskelerken kullanıldığını
- EOI komutunun kesme işlendikten sonra gönderilmesi gerektiğini
- Cascade modunun master-slave yapısını açıkladığını
- Polling modunun kesme hatası durumunda alternatif olarak kullanıldığını

## Kısa Tekrar Notları

- 8259 = 8 kesme hattı (IRQ0-IRQ7)
- ICW1→ICW2→ICW3→ICW4 sırasıyla yazılır
- IRQ0 en yüksek öncelik (sistem saati)
- IRQ2 cascade bağlantısı
- IMR: Kesmeleri maskeler
- ISR: Aktif kesmeyi gösterir
- IRR: Bekleyen kesmeleri tutar
- EOI: Kesme işlendikten sonra gönderilir
- Cascade: 8259-8259 bağlantısı ile 64 kesme

## Detaylı Açıklamalar (Daha Fazla Detay İsteyenler İçin)

8259 Programlanabilir Kesme Denetleyicisi, mikro işlemci sistemlerinde kesme yönetimini sağlayan kritik bir çiptir. 8 adet kesme hattına (IRQ0-IRQ7) sahiptir ve her birine öncelik atayabilir.

Başlatma işlemi ICW (Initialization Command Words) dizisi ile yapılır. ICW1 ile başlatma komutu verilir, ICW2 ile vektor adresi belirlenir, ICW3 ile cascade modu yapılandırılır, ICW4 ile ise 8086/8088 modu ve EOI komutu türü ayarlanır. Bu dizinin sırasıyla yazılması zorunludur.

IRQ0-IRQ7 arasında öncelik sıralaması vardır. IRQ0 en yüksek önceliklidir (sistem saati), IRQ1 klavye, IRQ2 cascade bağlantısı, IRQ3-IRQ7 ise diğer cihazlar için kullanılır.

IMR (Interrupt Mask Register) kesmeleri maskelerken, ISR (In-Service Register) aktif kesmeyi, IRR (Interrupt Request Register) ise bekleyen kesmeleri tutar. EOI (End of Interrupt) komutu ise kesme işlendikten sonra gönderilir ve kesme sürecini tamamlar.

Cascade modu, birden fazla 8259'i birbirine bağlayarak 64'e kadar kesme hattı genişletme sağlar. Master-slave yapısı ile IRQ2 üzerinden bağlantı yapılır.