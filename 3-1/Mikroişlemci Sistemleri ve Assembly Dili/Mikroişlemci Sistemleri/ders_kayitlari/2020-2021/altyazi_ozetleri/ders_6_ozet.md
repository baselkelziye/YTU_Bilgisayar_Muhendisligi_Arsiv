# Ders 6 Çalışma Özeti

## Genel Konular

- **8255 Mod 1 Uygulaması ve Tekrarı**
  - Geçen haftanın mod 1 teorisi, bu hafta Proteus üzerinde örnek bir devre ile pekiştirildi.
  - Control word yapısı ve mod selection bölümü tekrar incelendi.
  - Port A input, Port B output olarak ayarlanarak iki port arasında handshaking örneği yapıldı.

- **Interrupt Ayarları ve Enable İşlemleri**
  - Handshaking'in çalışması için A ve B portlarının interrupt'larının ayrı ayrı enable edilmesi gerekir.
  - Interrupt enable işlemleri bit set reset (BSR) modülü üzerinden C portunun belirli pinleri set edilerek yapılır.
  - Port A input modunda iken C6 pininin, Port B output modunda iken C2 pininin set edilmesi gerekir.

- **Status Word Okuma ve Interrupt Kontrolü**
  - C portundan status word okunarak interrupt oluşup oluşmadığı kontrol edilir.
  - A portu için 08H ile AND işlemi yapılarak ilgili bitin durumu sorgulanır.
  - Interrupt oluştuğunda mikro işlemci porttan veri okur; oluşmadığında tekrar döngüye dönülür.

- **8251 USART Haberleşme Entegresine Giriş**
  - Seri haberleşme ihtiyacından ve paralel ile seri arasındaki temel farklardan bahsedildi.
  - Paralel iletişim kısa mesafelerde hızlı ama maliyetli, seri iletişim uzun mesafelerde yavaş ama ekonomiktir.
  - Günümüzde seri iletişim teknolojileri daha yaygın olarak kullanılmaktadır.

## Hocanın Özellikle Vurguladığı Kısımlar

- **Her Entegrenin Kendine Özgü Control Word'ü Olduğu**
  - 8255'te olduğu gibi 8251'de de entegrenin davranışını belirleyen bir kontrol sözcüğü vardır.
  - Bu sözcük, entegrenin hangi modda çalışacağını ve hangi pinlerin ne işlevde olacağını belirler.
  - Kodlamaya geçmeden önce bu kontrol sözcüğünün doğru şekilde hesaplanması gerekir.

- **Adresleme ve Chip Select Pininin Doğru Analizi**
  - Proteus örneğinde chip select pininin bağlanma biçimine göre entegrenin hangi adreste çalıştığı belirlenir.
  - Adres hesaplamasında A0-A9 address pinlerinin ve decoder devresinin doğru okunması gerekir.
  - Yanlış adresleme, entegrenin tetiklenmemesine veya yanlış portun seçilmesine yol açar.

- **Interrupt'un Read/Write Sinyalleri ile Resetlenmesi**
  - Interrupt oluştuğunda ve mikro işlemci okuma/yazma yaptığında interrupt otomatik olarak resetlenir.
  - Bu mekanizma sayesinde bir sonraki veri transferi için interrupt yeniden hazırlanmış olur.

- **K-Pad ve 7-Segment Display Kullanımı**
  - Örnekte port A'ya k-pad, port B'ye 7-segment display bağlandı.
  - K-pad'den basılan tuşun indisi okunarak ekranda ilgili sayının gösterilmesi sağlandı.
  - Burada amaç handshaking mantığını göstermekti; k-pad'in çalışma detayı örneğin dışında bırakıldı.

## Kısa Tekrar Notları

- Her entegre için önce adres belirlenmeli, ardından control word gönderilmelidir.
- Mod 1'de handshaking için interrupt'ların BSR modülüyle enable edilmesi şarttır.
- Status word C portundan okunarak interrupt durumu sorgulanır.
- Interrupt, read/write sinyalleri ile otomatik resetlenir.
- Adres hesaplamasında decoder devresi ve chip select pininin durumu dikkate alınmalıdır.

## Detaylı Açıklamalar (Daha Fazla Detay İsteyenler İçin)

Bu derste 8255'in mod 1'i üzerinde yoğunlaşıldı ve bu modun pratikte nasıl uygulanacağı Proteus simülasyon programı üzerinden gösterildi. Öncelikle entegrenin hangi adreste yerleşik olduğu belirlendi; chip select pininin decoder devresine bağlanma biçimi incelendi. Ardından BSR modülü kullanılarak A ve B portlarının interrupt'ları enable edildi. Port A input olarak ayarlandığında C6 pininin, port B output olarak ayarlandığında C2 pininin set edilmesi gerektiği vurgulandı.

Mod selection kısmında ise A portu mod 1 input, B portu mod 1 output olarak programlandı. Control word'un ilgili bitleri ayarlandıktan sonra port adreslerine veri yazıldı ve status word C portundan okunarak interrupt durumu kontrol edildi. A portundan veri geldiğinde interrupt oluştuğu ve bu durumun AND operatörü ile kontrol edildiği gösterildi. Interrupt oluştuğunda port A'dan veri okundu, bu veri geçici bir register'a atıldı ve ardından port B'nin hazır olup olmadığı status word üzerinden sorgulandı. Port B müsait olduğunda veri port B'ye yazılarak ekranda display edildi.

Dersin ikinci kısmında ise 8251 USART entegresine giriş yapıldı. Seri ve paralel iletişim arasındaki temel farklar anlatıldı. Paralel iletişimde veri aynı anda birden fazla hat üzerinde gönderilirken, seri iletişimde veri peş peşe tek bir hat üzerinde iletilir. Paralel iletişim kısa mesafelerde hızlıdır ancak maliyetlidir; seri iletişim ise uzun mesafelerde tercih edilir ancak daha yavaştır. Günümüzde seri iletişim teknolojileri daha yaygın olarak kullanılmaktadır.
