# Ders 8 Çalışma Özeti

## Genel Konular

- IEEE 802.4 Token Bus
  - Fiziksel olarak bus yapısına benzeyen, mantıksal olarak token dolaştıran bir erişim yöntemidir.
  - Veri göndermek isteyen istasyonun token'a sahip olması gerekir.
- Token mantığı
  - Token, gönderim hakkını temsil eder.
  - Token kimdeyse ortamı o kullanır; böylece rastgele çakışma ihtimali azaltılır.
- Priority ve erişim düzeni
  - Bazı token tabanlı yapılarda öncelik seviyeleri tanımlanabilir.
  - Öncelik, hangi istasyonun hangi durumda gönderim hakkı alacağını etkiler.
- IEEE 802.5 Token Ring
  - İstasyonlar mantıksal halka düzeninde düşünülür.
  - Token halka boyunca dolaşır; veri gönderecek istasyon token'ı yakalayıp frame'i gönderir.
- Halka yapısında kontrol
  - Veri frame'i halka üzerinde dolaşır ve hedefe ulaştığında işaretlenir.
  - Monitor istasyon gibi mekanizmalar token kaybı veya hatalı frame dolaşımı gibi problemleri yönetebilir.

## Hocanın Özellikle Vurguladığı Kısımlar

- Token yaklaşımı collision'ı azaltmak için geliştirilmiştir.
  - Ortamı herkesin rastgele kullanması yerine gönderim hakkı sırayla devredilir.
- Fiziksel topoloji ile mantıksal topoloji aynı olmak zorunda değildir.
  - Token bus fiziksel olarak bus görünürken mantıksal erişim token sırasına dayanabilir.
- Token kaybı veya bozulması ayrıca yönetilmelidir.
  - Token tabanlı sistemlerde tek gönderim hakkının kaybolması tüm iletişimi etkileyebilir.

## Kısa Tekrar Notları

- Token, gönderim iznidir.
- Token bus, bus ortamında mantıksal token sırası kurar.
- Token ring, halka mantığında token dolaştırır.
- Token kimdeyse veri gönderme hakkı ondadır.
- Öncelik ve monitor mekanizmaları erişim düzenini korur.

## Detaylı Açıklamalar

Bu derste Ethernet'in çakışma tabanlı ortam erişiminden farklı olarak token tabanlı yaklaşımlar incelenmiştir. Token bus ve token ring sistemlerinde temel fikir, veri gönderebilme yetkisinin özel bir kontrol bilgisinin dolaşımıyla sınırlandırılmasıdır. Böylece birden fazla istasyonun aynı anda ortama çıkması engellenir.

Token bus yapısında istasyonlar fiziksel olarak ortak bir hat üzerinde olabilir; fakat mantıksal olarak token'ın dolaştığı bir sıra vardır. Token'a sahip olan istasyon veri gönderebilir, işi bitince token'ı sıradaki istasyona devreder. Bu yapı çakışmayı azaltır ancak token yönetimi ek karmaşıklık getirir.

Token ring yapısında istasyonlar mantıksal halka oluşturur. Token halka üzerinde dolaşır ve gönderim yapmak isteyen istasyon token'ı kullanır. Frame hedefe ulaştıktan sonra halka üzerinde uygun işaretlemelerle dolaşım tamamlanır. Token kaybı, sürekli dolaşan hatalı frame veya öncelik yönetimi gibi konular sistemin güvenilir çalışması için ayrıca ele alınır.
