# Ders 3 Çalışma Özeti

## Genel Konular

- Basit Giriş-Çıkış Birimlerinin Mikro İşlemciye Bağlanması
  - Çıkış birimi örneği: 8 LED'in bağlanması ve yakılması
  - Giriş birimi örneği: 8 butonun bağlanması ve okunması
  - Chip select (çip seçimi) ve adresleme mantığı

- 74245 Transceiver Entegresi
  - Yön belirleme: Dir bacağı ile veri akış yönü kontrol edilir (A→B veya B→A)
  - Dir=1 → Porta yazma (çıkış), Dir=0 → Porttan okuma (giriş)
  - Enable bacağı (çip seçimi) ile entegre aktif/pasif hale getirilir
  - Doğruluk tablosu: Arayüzler PDF'inde bulunur

- Adresleme ve Chip Select Mantığı
  - Bir çevre birimine yazı yapabilmek için önce o birimi seçmek gerekir
  - Adres bacakları (A0-A19) kullanılarak belirli bir bellek/IO adresi aktif edilir
  - NAND kapıları ile chip select sinyali üretilir
  - Enable ucuna 0 gelmesi durumunda entegre aktif hale gelir (aktif düşük)
  - Write sinyalinin de 0 olması gerekir (yazma işlemi için)

- Çıkış Birimi Tasarım Örneği (LED Yakma)
  - 8 LED, F0000h adresindeki basit çıkış birimine yerleştirilmiş
  - Adres çözümlemesi: A0-A15'in belirli kombinasyonları chip select'i aktif eder
  - DX register'ına port adresi yazılır, AL register'ına veri konulur
  - OUT komutu ile porttan veri gönderilir
  - Veri: 55h (01010101) → on-off-on-off deseni

- Giriş Birimi Tasarım Örneği (Buton Okuma)
  - 8 buton, belirli bir IO adresinde konumlandırılmış
  - Butona basıldığında ilgili pin 0'a gider (pull-up direnç ile)
  - IN komutu ile porttan veri okunur
  - Okunan değer FFh değilse bir butona basılmış demektir
  - Sonsuz döngü ile sürekli okuma yapılabilir

- 8255 PPI (Programmable Peripheral Interface) Entegresi
  - 3 adet 8-bit port içerir (Port A, Port B, Port C)
  - Her port bağımsız olarak giriş veya çıkış olarak programlanabilir
  - Port C'nin spesifik özelliği: 4-bitlik iki gruba ayrılabilir (üst ve alt)
  - Control word ile entegrenin çalışma modu belirlenir
  - A0 ve A1 pinleri ile hangi portun seçileceği belirlenir (8255'in kendi pinleridir, mikro işlemcideki A0-A1 ile karıştırılmamalıdır)

## Hocanın Özellikle Vurguladığı Kısımlar

- Chip select tasarımı bir DONANIM meselesidir; yazılım ile değil kapı devreleri ile yapılır
- 8255'in kendi A0-A1 pinleri, mikro işlemcinin A0-A1 pinleriyle aynı şey değildir - kesinlikle karıştırılmamalıdır
- 16-bit veri yolunda 8-bit çevre birimi kullanırken BHE (Bus High Enable) pini kullanılmalıdır
- Adresleme yaparken IO/M sinyalinin de dikkate alınması gerekir
- Port C'nin 4-bit olarak ayrılabilir olması, bazı uygulamalarda büyük avantaj sağlar
- Arayüzler PDF'i sınavlarda yanınızda bulundurulabilir; ezber yapmaya gerek yoktur

## Kısa Tekrar Notları

- 74245: Dir=1 yazma, Dir=0 okuma; Enable=0 ile aktif
- Chip select: Adres bacaklarının belirli kombinasyonu ile üretilir (NAND kapıları ile)
- OUT komutu: AL/AX'teki veriyi DX'teki adrese yazar
- IN komutu: DX'teki adresten AL/AX'e veri okur
- 8255: 3 port (A, B, C) + Control Word; A0-A1 ile port seçimi
- 8255 port seçimi: 00=PortA, 01=PortB, 10=PortC, 11=Control Word
- BHE: 01→D8-D15 (üst byte), 10→D0-D7 (alt byte), 00→16-bit, 11→geçersiz

## Detaylı Açıklamalar (Daha Fazla Detay İsteyenler İçin)

Basit bir çıkış birimi (LED) tasarlamak için şu adımlar izlenir: Önce fiziksel olarak 8 LED, bir transceiver entegresine (74245) bağlanır. Entegrenin enable ucu, mikro işlemcinin adres bacaklarından üretilen bir chip select sinyali ile kontrol edilir. Chip select sinyali, istenen adres geldiğinde (örn. F0000h) 0 seviyesine inerek entegreyi aktif hale getirir. Dir bacağına 1 verilerek veri akışı mikro işlemciden çevre birimine yöneltilir. Yazma işlemi için WR sinyalinin de 0 olması gerekir.

Giriş biriminde ise durum tersinedir. Butonlar pull-up dirençlerle 5V'a bağlanmıştır. Basıldığında toprağa (0V'a) bağlanır. Mikro işlemci IN komutu ile portu okuduğunda, basılmamış butonlar için FFh (11111111), basılmış butonlar için ilgili bit 0 olarak okunur.

8255 PPI entegresi, birden fazla portu tek bir çip üzerinde sunarak sistemi basitleştirir. İçerisindeki Port A, Port B ve Port C tamamen 8-bit olarak programlanabilir. Ancak Port C'nin kendine özgü bir özelliği vardır: 4-bitlik iki gruba (upper ve lower) ayrılabilir. Bu, bazı uygulamalarda (kontrol sinyalleri ile birlikte veri taşırken) büyük avantaj sağlar.

8255'in programlanması için bir control word oluşturulur. Bu kelimenin her bir belirli biti, belirli bir ayarı kontrol eder. Örneğin 7. bit 1 ise mod seçimi yapılır, Port A'nın modu, Port B'nın modu ve Port C'nin upper/lower bölümlerinin modları bu kelime ile belirlenir. Control word, 8255'e yazıldığında entegre bu ayarlara göre yapılandırılır. Arayüzler PDF'inde bu bit dizilimleri ve akış diyagramları detaylı olarak verilmiştir.
