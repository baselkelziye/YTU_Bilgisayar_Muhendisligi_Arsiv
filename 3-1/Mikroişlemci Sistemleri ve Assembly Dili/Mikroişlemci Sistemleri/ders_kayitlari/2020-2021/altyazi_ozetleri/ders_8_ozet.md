# Ders 8 Çalışma Özeti

## Genel Konular

- **8251 USART Entegresinin Donanımsal Yapısı**
  - 8251A modeli 28 bacaklı bir entegredir.
  - 8 bitlik paralel veri busı (D0-D7), VCC, Ground, clock, reset, chip select (CS), read/write ve modem kontrol pinleri bulunur.
  - TXD (Transmit Data) ve RXD (Receive Data) pinleri seri veri transferini sağlar.

- **Pin İşlevleri ve Bağlantıları**
  - CS (Chip Select): Aktif düşük seviyeli bir pindir; entegrenin aktif olmasını sağlar.
  - C/D (Command/Data): Mikro işlemcinin kontrol mü yoksa veri mi gönderdiğini belirler.
  - RD/WR: Okuma ve yazma sinyalleri; mikro işlemci tarafından beslenir.
  - TXRDY/TXRDY: Gönderi hazır ve alıcı hazır sinyalleri; handshaking için kullanılır.
  - CTS (Clear To Send): Modem tarafından gelen "gönderime hazır" sinyali; topraklanarak aktif edilir.

- **Seri Veri Transfer Mekanizması**
  - Mikro işlemci 8 bitlik veriyi paralel olarak 8251'e yazar.
  - 8251 bu veriyi seri olarak paketleyerek TXD pininden dışarıya iletir.
  - Karşı taraftan seri olarak gelen veri, 8251 tarafından 8 bitlik paralel veriye dönüştürülür ve RXD pininden okunur.

- **Hata Kontrolü ve Robustness**
  - Parity check ile hata tespiti yapılabilir.
  - Framing hatası (yanlış byte gönderimi) ve overrun hatası (okunamayan veri) gibi durumlar için mekanizmalar mevcuttur.
  - Bu özellikler sayesinde yazılımsal çözümlere göre daha robust bir iletişim sağlanır.

## Hocanın Özellikle Vurguladığı Kısımlar

- **8251'in 8255 ile Karşılaştırılması**
  - Her iki entegre de mikro işlemci ile çevre birimleri arasında arayüz sağlar.
  - 8255 paralel giriş-çıkış için, 8251 ise seri haberleşme için kullanılır.
  - Her ikisinde de adres çözümleme, chip select ve kontrol sinyalleri aynı mantıkla çalışır.

- **Seri Haberleşmede Buffer Kullanımı**
  - 8251 içinde hem gönderme hem alma tarafında bufferlar bulunur.
  - Bu bufferlar sayesinde mikro işlemci ile seri cihaz arasındaki hız farkı dengelenir.
  - Mikro işlemci veriyi buffer'a yazar, 8251 ise bunu uygun hızda seri olarak iletir.

- **Senkronizasyon ve Clock Pinleri**
  - Hem senkron hem asenkron çalışmada clock sinyali gereklidir.
  - Senkron modda her iki cihaz aynı clock'a senkronize olur.
  - Asenkron modda clock sinyali sadece baud rate'i belirler; cihazlar birbirinden bağımsız çalışır.

- **Modem Kontrol Pinleri ve Kullanım Dışılığı**
  - CTS, DSR, DTR gibi modem pinleri genellikle kullanılmaz.
  - Ancak CTS pininin topraklanması transmit devresini aktif etmek için gereklidir.
  - Bu pinlerin doğru bağlanması entegrenin düzgün çalışmasını sağlar.

## Kısa Tekrar Notları

- 8251 USART, seri haberleşme için kullanılan 28 bacaklı bir entegredir.
- Hem senkron hem asenkron modda çalışabilir.
- TXD ve RXD pinleri seri veri transferini sağlar.
- C/D pininin durumu kontrol ve veri ayrımını belirler.
- CTS pininin topraklanması transmit devresini aktif eder.
- Entegre, hata kontrolü ve robust iletişim için parity ve overrun kontrolü sunar.

## Detaylı Açıklamalar (Daha Fazla Detay İsteyenler İçin)

8251 USART entegresi, seri haberleşme ihtiyacını karşılamak için kullanılan temel donanım bloklarından biridir. 28 bacaklı DIP paketinde gelir ve hem sendik hem asenkron modda çalışabilir. Temel olarak mikro işlemcinin paralel verisini seri formata dönüştürerek dışarıya iletir ve seri olarak gelen veriyi paralel formata dönüştürerek mikro işlemciye sunar.

Entegrenin en önemli pinleri arasında TXD (Transmit Data) ve RXD (Receive Data) bulunur. TXD pininden seri veri gönderilirken, RXD pininden seri veri alınır. Bu pinler tek bitlik seri hatlardır. Mikro işlemci ise 8 bitlik paralel veri busı (D0-D7) üzerinden 8251 ile iletişim kurar.

CS (Chip Select) pini aktif düşük seviyelidir; bu pini toprakladığınızda entegre aktif hale gelir. C/D (Command/Data) pini ise mikro işlemcinin gönderdiği verinin bir kontrol komutu mu yoksa aktarılacak bir veri mi olduğunu belirler. RD ve WR pinleri ise okuma ve yazma sinyallerini kontrol eder.

Haberleşme sürecinde mikro işlemci veriyi 8251'in veri register'ına yazar. 8251 bu veriyi start biti, veri bitleri, opsiyonel parity biti ve stop bitiyle paketleyerek TXD pininden seri olarak iletir. Karşı taraftan seri olarak gelen veri ise tersi yönde işlenerek 8 bitlik paralel veriye dönüştürülür ve mikro işlemci tarafından okunur.

Entegre ayrıca hata kontrolü için parity check, framing hatası ve overrun hatası gibi özellikler sunar. Bu özellikler sayesinde hatalı veri transferleri tespit edilebilir ve gerekli önlemler alınabilir. Donanımsal olarak bu işlemleri yapması, yazılımsal çözümlere göre daha verimli ve robust bir iletişim sağlar.
