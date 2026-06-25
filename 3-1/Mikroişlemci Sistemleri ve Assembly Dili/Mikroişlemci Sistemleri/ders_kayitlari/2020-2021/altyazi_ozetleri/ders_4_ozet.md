# Ders 4 Çalışma Özeti

## Genel Konular

- Arayüzler PDF'inin Tanıtımı ve Kullanımı
  - Sınavlarda yanınızda bulundurulabilecek 4 sayfalık referans belgesi
  - Tüm entegrelerin control word bit dizilimleri ve akış diyagramları içerir
  - Her entegrenin programlama modları bu PDF'te tanımlıdır

- 8255 PPI'nin Detaylı Adresleme Tasarımı
  - 8255'te 4 farklı mod: Port A okuma/yazma (00), Port B okuma/yazma (01), Port C okuma/yazma (10), Control Word (11)
  - Mikro işlemciden A1 ve A2 pinlerinin 8255'in A0 ve A1 pinlerine bağlanması önerilir
  - A2-A1 kombinasyonları: 00→PortA, 01→PortB, 10→PortC, 11→Control Word

- Çift Adresli 8255 Yerleşimi (16-bit Veri Yolu Uyumlu)
  - 8255'in 8-bit veri yolu, 8086'nın 16-bit veri yoluyla uyumlu hale getirilir
  - Çift adresler (even addresses): A0=0 olan adresler (F8h, FAh, FCh, FEh)
  - Tek adresler (odd addresses): A0=1 olan adresler (F9h, FBh, FDh, FFh)
  - BHE ile üst byte (D8-D15), A0 ile alt byte (D0-D7) kontrol edilir
  - Böylece tek bir 8255 ile 16-bit veri yolu üzerinde tam verimlilik sağlanır

- Chip Select Devre Tasarımı
  - 3-to-8 dekoder kullanımı: A3, A4, A5 pinlerinin kombinasyonunu çözer
  - Dekoderin enable uçları ile belirli adres aralıkları aktif edilir
  - Dekoder kullanımı, kapı devrelerine (NAND, NOR) göre daha basit ve güvenilirdir
  - Kapı devreleriyle de yapılabilir ancak daha fazla hata riski taşır

- Mod Seçimi ve Kontrol
  - 8255'in mod 0 (basit giriş-çıkış), mod 1 (handshake'li), mod 2 (bidirectional) modları vardır
  - Control word'un 7. biti 1 ise mod seçimine geçilir
  - Her portun modu bağımsız olarak belirlenebilir

- IO/M ve Chip Select Etkileşimi
  - IO/M sinyali, işlemin bellek mi yoksa çevre birimi ile mi olduğunu belirtir
  - Chip select devresinde IO/M sinyalinin de dikkate alınması gerekir
  - Böylece aynı adres hem bellek hem de IO için kullanılabilir (izole I/O)

## Hocanın Özellikle Vurguladığı Kısımlar

- Çift adres yerleşimi: 16-bit veri yolu ile çalışırken 8-bit çevre birimlerinin verimli kullanılması için bu yöntem şarttır
- Dekoder kullanımı kapı devrelerine göre her zaman tercih edilmelidir; kapı devrelerinde beklenmeyen durumlar yaşanabilir
- Adresleme tasarımında sadece A0-A1 değil, IO/M ve chip select sinyallerinin de birlikte değerlendirilmesi gerekir
- 8255'in A0-A1 pinleri ile mikro işlemcinin A0-A1 pinleri arasındaki fark her zaman vurgulanmalıdır
- Control word oluşturma işlemi, 8255'in tüm davranışını belirler; bu yüzden Arayüzler PDF'inden doğru bit değerlerine ulaşılmalıdır

## Kısa Tekrar Notları

- 8255 port seçimi: A2→8255-A1, A1→8255-A0 (mikro işlemci pinleri 8255 pinlerine kaydırılır)
- Çift adres yerleşimi: F8h (PortA), FAh (PortB), FCh (PortC), FEh (Control)
- BHE/A0 kombinasyonu: 16-bit veri yolunu 8-bit olarak iki parçaya böler
- Chip select: Dekoder ile adres çözümlemesi, NAND kapısı ile de yapılabilir
- Control word: 7. bit=1 → mod seçimi; ilgili bitler Port A/B/C modlarını belirler
- IO/M sinyali: 1→bellek, 0→input-output; chip select devresinde kullanılmalıdır

## Detaylı Açıklamalar (Daha Fazla Detay İsteyenler İçin)

8255 PPI entegresinin adresleme tasarımı, pratikte en çok karşılaşılan konulardan biridir. Bir 8255'i sisteme yerleştirirken, her bir portun (A, B, C ve Control Word) ayrı bir adres alması gerekir. Eğer 8255 tek adresli (8-bit) olarak yerleşecekse, sadece A0 pini ile port seçimi yapılabilir. Ancak biz 16-bit veri yolu kullandığımız için, 8255'i çift adresli (even/odd) olarak yerleştirmeliyiz.

Çift adresli yerleşimde, 8255'in kendi A0-A1 pinleri, mikro işlemciden gelen A1-A2 pinlerine bağlanır. Bu sayede: A2-A1=00→PortA, A2-A1=01→PortB, A2-A1=10→PortC, A2-A1=11→Control Word seçilir. Başlangıç adresi F8h verildiğinde, PortA=F8h, PortB=FAh, PortC=FCh, Control=FEh adreslerine yerleşmiş olur.

Chip select devresi, belirli bir adres geldiğinde 8255'i aktif hale getirmek için tasarlanır. En mantıklı yöntem 3-to-8 dekoder kullanmaktır. Dekoder, 3 girişli (A3, A4, A5 gibi) ve 8 çıkışlı bir devredir. Girişlerdeki bit kombinasyonuna göre sadece bir çıkış 0 seviyesine iner. Bu çıkış 8255'in chip select ucuna bağlanarak entegre o adreste aktif hale getirilir. Dekoder yerine NAND kapıları ile de aynı iş yapılabilir ancak kapı sayısı artar ve hata riski yükselir.

BHE ve A0 pinleri, 16-bit veri yolunun nasıl kullanılacağını belirler. BHE=0 olduğunda D8-D15 (üst byte) aktif olur, A0=0 olduğunda D0-D7 (alt byte) aktif olur. Bu iki sinyalin kombinasyonu ile 16-bit, 8-bit upper veya 8-bit lower veri transferi yapılabilir. Bu sayede tek bir 8255 ile 16-bit veri yolu üzerinde tam verimlilikle çalışılabilir.
