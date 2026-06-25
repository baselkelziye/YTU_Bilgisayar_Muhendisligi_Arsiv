# Ders 7 Çalışma Özeti

## Genel Konular

- **8251 USART Entegresi ve Seri Haberleşme Kavramları**
  - USART açılımı: Universal Synchronous/Asynchronous Receiver/Transmitter.
  - Hem senkron hem de asenkron seri iletişim yapabilen bir donanım modülüdür.
  - Mikro işlemci ile seri haberleşme yapan cihazlar arasında arayüz sağlar.

- **Senkron ve Asenkron Haberleşme Farkları**
  - Senkron haberleşmede iki cihaz aynı anda iletime başlar ve sürekli veri akışı sağlanır.
  - Asenkron haberleşmede ise cihazlar senkronizasyon kurmadan, aralarda boşluklarla veri gönderebilir.
  - Çoğu uygulama ve örnek asenkron Haberleşme üzerinedir.

- **Seriler Haberleşmenin Temel Elemanları**
  - Start biti: Veri transferinin başladığını bildiren bit (genellikle 0).
  - Stop biti: Veri transferinin bittiğini bildiren bit (genellikle 1).
  - Parity biti: Hata kontrolü için eklenen opsiyonel bir bit.
  - Baud rate: Saniyede gönderilen bit sayısı; iletişim hızını belirler.
  - Bit rate: Baud rate ile aynı anlama gelir, bit transfer hızını ifade eder.

- **Yazılımsal Seri İletişim**
  - Mikro işlemci portlarından seri veri gönderip almanın yazılımsal bir yoludur.
  - Her bir bit tek tek okunur veya yazılır; bir sayaç ile toplam bit sayısı kontrol edilir.
  - Delay (gecikme) prosedürleri ile baud rate'e uygun zamanlama sağlanır.
  - Donanımsal çözümün aksine tüm iş yükü mikro işlemci üzerindedir.

## Hocanın Özellikle Vurguladığı Kısımlar

- **Temel Kavramların Sınavlarda Sorulabilirliği**
  - Asenkron/senkron farkı, baud rate, parity, start/stop bitleri gibi kavramlar sınavlarda test formatında sorulabilmektedir.
  - Bu kavramların sadece tanımını değil, pratikteki karşılığını da bilmek gerekir.

- **Mikro İşlemciden Seri Veri Çıkışı**
  - Mikro işlemci in/out komutuyla 8 bitlik veriyi aynı anda porttan gönderir.
  - Ancak seri cihazlara bu veri tek tek bit olarak iletilmelidir.
  - Bu dönüşüm yazılımsal olarak RCR (Rotate Right Through Carry) komutuyla gerçekleştirilir.
  - Her adımda bir bit dışarıya gönderilir ve keri (carry) bayrağı ile bir sonraki bit hazırlanır.

- **Bit Sayısının Hesaplanması**
  - Toplam gönderilecek bit sayısı = veri biti + start biti + stop biti (+ parity biti varsa).
  - Örneğin 8 bitlik veri için 1 start + 1 stop ile toplam 10 bit gönderilir.
  - sayaç bu toplam değere göre ayarlanır ve her adımda bir azaltılır.

- **Delay Prosedürünün Önemi**
  - Her bit gönderimi arasında baud rate'e uygun bir bekleme süresi eklenmelidir.
  - Delay süresi toplam transfer süresini belirler.
  - Yanlış delay ayarı iletişim hatalarına yol açar.

## Kısa Tekrar Notları

- USART hem senkron hem asenkron çalışabilen bir seri haberleşme entegresidir.
- Seri iletişimde veri start bitiyle başlar, veri bitleri peş peşe gönderilir, stop bitiyle biter.
- Parity biti hata kontrolü için opsiyonel olarak eklenebilir.
- Yazılımsal seri iletişimde RCR komutuyla bitler tek tek dışarıya aktarılır.
- Her bit transferi arasında baud rate'e uygun delay eklenmelidir.
- Donanımsal çözüm (8251) tüm bu işlemleri otomatik olarak yapar.

## Detaylı Açıklamalar (Daha Fazla Detay İsteyenler İçin)

8251 USART entegresi, mikro işlemcilerin seri haberleşme yapabilmesi için kullanılan temel donanım bloklarından biridir. Hem senkron hem de asenkron modda çalışabilir. Senkron modda iki cihaz aynı clock sinyaline senkron olarak veri transferi yapar; asenkron modda ise her iki taraf kendi zamanlamasını oluşturur ve start/stop bitleriyle veri paketlerini çerçeveler.

Serili iletişimde veri paketinin yapısı şöyledir: Önce start biti (0) gönderilir, ardından veri bitleri (genellikle 8 bit) sırayla iletilir, opsiyonel olarak parity biti eklenir ve son olarak stop biti (1) ile transfer tamamlanır. Toplam bit sayısı, baud rate ile çarpılarak transfer süresi hesaplanabilir.

Yazılımsal seri iletişimde mikro işlemci herself bir biti manuel olarak porttan dışarıya aktarır. Bu işlemde RCR (Rotate Right Through Carry) komutu kullanılır; bu komut sayesinde veri kaydırılır ve en anlamlı bit carry bayrağına geçer, ardından bu bit doğrudan çıkış portuna yazılır. Her adımda bir delay prosedürü çağrılarak baud rate'e uygun zamanlama sağlanır. Toplam bit sayısının kadar döngü tekrarlanır.

Donanımsal çözümde ise 8251 USART entegresi tüm bu işlemleri otomatik olarak yapar. Mikro işlemci sadece veriyi 8 bitlik bir register'a yazar, 8251 ise bunu seri olarak paketler ve karşı tarafa iletir. Benzer şekilde seri olarak gelen veriyi de 8 bitlik paralel bir veriye dönüştürerek mikro işlemciye sunar. Bu sayede mikro işlemcinin iş yükü azalır ve daha verimli bir iletişim sağlanır.
