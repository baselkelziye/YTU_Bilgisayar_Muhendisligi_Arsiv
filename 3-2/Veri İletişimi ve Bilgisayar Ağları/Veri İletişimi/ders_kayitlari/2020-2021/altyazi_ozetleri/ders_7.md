# Ders 7 Çalışma Özeti

## Genel Konular

- HDLC çalışma mekanizması
  - HDLC'de iletişim bağlantı kurma, veri aktarımı ve bağlantı sonlandırma aşamalarıyla ilerler.
  - U-frame türleri bağlantı yönetimi için kullanılır.
- Bağlantı kurma ve sonlandırma
  - SABM gibi komutlar bağlantının başlatılmasında kullanılır.
  - UA gibi cevaplar isteğin kabul edildiğini gösterir.
  - DISC bağlantının sonlandırılması için kullanılır.
- S-frame ve I-frame kullanımı
  - I-frame veri taşırken sıra numarası ve kontrol bilgileriyle güvenilirliği destekler.
  - S-frame, alındı bildirme ve yeniden iletim isteme gibi kontrol işlevlerini üstlenir.
- IEEE 802 ailesine giriş
  - Yerel ağlarda veri bağı katmanının alt bileşenleri ve standartları ele alınır.
  - Ethernet, ortam paylaşımı ve çakışma yönetimi açısından incelenir.
- CSMA/CD ve collision
  - Ethernet'te istasyonlar hattı dinler, boşsa gönderime başlar.
  - İki istasyon aynı anda gönderirse collision oluşur.
  - Collision detection, çakışmayı fark edip iletimi durdurma ve sonra tekrar deneme mantığıdır.
- Binary exponential backoff
  - Çakışma sonrası istasyonlar rastgele bekleme süresi seçer.
  - Çakışma sayısı arttıkça bekleme aralığı büyür.

## Hocanın Özellikle Vurguladığı Kısımlar

- HDLC'de bağlantı her zaman kendiliğinden var kabul edilmez.
  - Bazı yapılarda taraflardan biri bağlantıyı açıkça başlatmalıdır.
- Frame numaraları ve onaylar protokolün düzenini sağlar.
  - Hangi verinin alındığı ve hangisinin yeniden gönderileceği bu bilgilerle takip edilir.
- Ethernet'teki çakışma problemi ortam paylaşımından doğar.
  - Aynı fiziksel ortamı kullanan istasyonların eş zamanlı gönderimi kontrol edilmelidir.

## Kısa Tekrar Notları

- HDLC üç aşamalı düşünülebilir: bağlantı kur, veri aktar, bağlantıyı kapat.
- U-frame bağlantı yönetiminde önemlidir.
- Ethernet paylaşımlı ortamda çalışır.
- CSMA/CD hattı dinleme ve çakışmayı algılama mantığıdır.
- Backoff, çakışmadan sonra tekrar denemeyi rastgeleleştirir.

## Detaylı Açıklamalar

Bu derste önce HDLC'nin sadece frame formatı değil, aynı zamanda bir çalışma düzeni olduğu vurgulanmıştır. Bağlantının kurulması için taraflardan biri kontrol frame'i gönderir, karşı taraf uygun cevap verirse veri aktarımı başlar. Veri aktarımında I-frame'ler kullanılır; kontrol ve onay süreçlerinde S-frame'ler devreye girer. Bağlantı sonlandırma yine yönetim frame'leriyle yapılır.

Dersin ikinci kısmında IEEE 802 ve Ethernet mantığına geçilmiştir. Ethernet paylaşımlı bir ortamda birçok istasyonun aynı iletim ortamını kullanması problemine çözüm getirir. CSMA/CD yaklaşımında istasyon önce ortamı dinler, boş görürse gönderir. Buna rağmen iki istasyon aynı anda başlayabilir ve collision oluşabilir. Çakışma algılandığında iletim durdurulur, istasyonlar rastgele bekleme sürelerinden sonra tekrar dener.

Binary exponential backoff, çakışmalar arttıkça bekleme aralığını büyüterek ağın sürekli aynı çakışmaya düşmesini engellemeye çalışır. Bu mekanizma özellikle klasik paylaşımlı Ethernet yapılarında ortam erişim kontrolünün önemli parçasıdır.
