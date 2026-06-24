# Ders 10 Çalışma Özeti

## Genel Konular

- IEEE 802.11 ve kablosuz ağlar
  - Wi-Fi standartları kablosuz ortamda veri iletimi için veri bağı ve fiziksel katman kuralları tanımlar.
  - Kablosuz ortam paylaşımlı ve daha belirsiz olduğu için Ethernet'teki bazı yaklaşımlar doğrudan uygulanamaz.
- Collision detection yerine collision avoidance
  - Kablolu Ethernet'te çakışma fiziksel hat üzerinden algılanabilir.
  - Kablosuz ortamda çakışmanın nerede ve nasıl gerçekleştiğini algılamak zor olduğu için CSMA/CA yaklaşımı kullanılır.
- CSMA/CA
  - İstasyon ortamı dinler, uygun bekleme aralıkları kullanır ve çakışma ihtimalini azaltmaya çalışır.
  - Amaç çakışmayı olduktan sonra algılamak değil, oluşma ihtimalini baştan düşürmektir.
- RTS/CTS mantığı
  - Request to Send ve Clear to Send mesajları, veri gönderimi öncesinde ortamın ayrılmasına yardım eder.
  - Özellikle hidden terminal probleminde çakışma ihtimalini azaltır.
- Hidden ve exposed terminal problemleri
  - Hidden terminalde iki istasyon birbirini duyamaz ama aynı alıcıya gönderim yaparak çakışmaya sebep olabilir.
  - Exposed terminalde bir istasyon ortamı meşgul sanıp aslında güvenli olabilecek bir gönderimi erteleyebilir.
- Bluetooth ve kısa mesafeli kablosuz iletişim
  - Bluetooth daha kısa mesafe ve farklı kullanım senaryoları için tasarlanmış bir kablosuz iletişim teknolojisidir.
  - Wi-Fi ile amaç, kapsama, hız ve ortam yönetimi bakımından farklılık gösterir.

## Hocanın Özellikle Vurguladığı Kısımlar

- Kablosuz ortam kablolu ortam gibi davranmaz.
  - Çakışmayı kabloda olduğu gibi doğrudan algılamak mümkün olmadığı için kaçınma temelli yöntemler gerekir.
- CSMA/CD ile CSMA/CA karıştırılmamalıdır.
  - CD çakışmayı algılamaya, CA çakışmadan kaçınmaya odaklanır.
- RTS/CTS her durumda zorunlu değil, belirli problemleri azaltan yardımcı mekanizmadır.
  - Ek kontrol mesajı maliyeti vardır; faydası senaryoya göre değerlendirilir.

## Kısa Tekrar Notları

- 802.11 Wi-Fi standart ailesidir.
- Kablosuzda CSMA/CA kullanılır.
- Hidden terminal birbirini duymayan göndericiler problemidir.
- RTS/CTS ortam ayırma ve çakışma azaltma için kullanılır.
- Bluetooth kısa mesafeli kablosuz iletişim teknolojisidir.

## Detaylı Açıklamalar

Bu derste IEEE 802.11 kablosuz ağlarının Ethernet'ten neden farklı ele alınması gerektiği anlatılmıştır. Kablolu Ethernet'te tüm istasyonlar aynı fiziksel hat üzerindeki çakışmayı algılayabilir. Kablosuzda ise sinyaller havada yayılır, alıcı ve göndericilerin kapsama alanları farklı olabilir. Bu yüzden collision detection yerine collision avoidance mantığı kullanılır.

CSMA/CA, istasyonların ortamı dinleyip uygun süreler bekledikten sonra gönderime başlamasına dayanır. Bu, çakışmayı tamamen ortadan kaldırmaz fakat olasılığını azaltır. RTS/CTS mekanizması, veri gönderimi öncesi kısa kontrol mesajlarıyla diğer istasyonlara ortamın kullanılacağını bildirir. Bu özellikle hidden terminal probleminde yararlıdır.

Bluetooth konusu, kablosuz iletişim ailesindeki farklı bir kullanım alanını göstermek için ele alınır. Wi-Fi daha yüksek veri hızı ve yerel ağ bağlantısı amacıyla kullanılırken Bluetooth kısa mesafe, düşük güç ve cihazlar arası bağlantı gibi senaryolarda öne çıkar.
