# Ders 2 Çalışma Özeti

## Genel Konular

- İletim ortamı kavramı
  - Medium, verinin göndericiden alıcıya ulaşıncaya kadar içinde taşındığı fiziksel ya da kablosuz ortamdır.
  - Ortamın zayıflama, gürültü, bant genişliği, maliyet ve kapsama gibi özellikleri iletim kalitesini belirler.
- Paralel ve seri iletim
  - Paralel iletimde birden fazla bit aynı anda farklı hatlardan gönderilir.
  - Seri iletimde bitler aynı veri hattı üzerinden zaman sırasıyla gönderilir.
  - Paralel iletim kısa mesafede hızlı olabilir; uzun mesafede kablo sayısı, senkronizasyon ve maliyet sorunları artar.
- Simplex, half-duplex ve full-duplex
  - Simplex tek yönlü iletişimdir.
  - Half-duplex iki yönlüdür ama aynı anda iki taraf konuşamaz.
  - Full-duplex iki yönlü ve eş zamanlı iletişime izin verir.
- Kablolu iletim ortamları
  - Bakır kablolar elektriksel sinyallerle çalışır ve dış elektromanyetik etkilerden etkilenebilir.
  - Bükümlü çift kablolar parazit etkisini azaltmak için çiftlerin birbirine sarılması mantığını kullanır.
  - Koaksiyel kablo daha iyi yalıtım sağlar.
  - Fiber optik kablo ışıkla veri taşır, yüksek hız ve düşük elektromanyetik etkilenme avantajı sunar.
- Kablosuz ortamlar
  - Radyo, mikrodalga ve kızılötesi gibi elektromanyetik dalgalarla veri taşınabilir.
  - Kablosuz iletimde ortam paylaşımı, parazit, kapsama ve güvenlik daha belirgin sorunlardır.

## Hocanın Özellikle Vurguladığı Kısımlar

- Medium seçimi sadece kablo seçimi değildir.
  - Veri hızı, mesafe, hata ihtimali, maliyet ve ortam koşulları birlikte değerlendirilmelidir.
- Paralel iletim her zaman daha iyi değildir.
  - Aynı anda çok bit göndermek avantajlı görünür; fakat çok hat kullanımı uzun mesafede karmaşıklık doğurur.
- Full-duplex için çoğu durumda ayrı alış ve veriş yolları düşünülmelidir.
  - Tek hat üzerinde eş zamanlı çift yönlü iletişim ek teknikler gerektirir.

## Kısa Tekrar Notları

- Medium, verinin taşındığı ortamdır.
- Paralel iletim çok hat, seri iletim tek hat mantığına dayanır.
- Simplex tek yön; half-duplex sırayla çift yön; full-duplex eş zamanlı çift yöndür.
- Fiber optik yüksek hız ve düşük parazit avantajı sağlar.
- Kablosuz iletimde ortam paylaşımı ve parazit kritik konulardır.

## Detaylı Açıklamalar

Bu derste veri iletim teknikleri fiziksel katman ağırlıklı olarak ele alınmıştır. Veri iletilirken sadece gönderilecek bit dizisi değil, bu bitlerin hangi ortamdan geçeceği de önemlidir. Ortamın yapısı sinyalin ne kadar bozulacağını, ne kadar güçlendirici gerekeceğini, kaç hat kullanılacağını ve hangi hızlara çıkılabileceğini belirler.

Paralel iletim, aynı anda birden fazla bit gönderebildiği için teorik olarak hızlıdır. Ancak her bit için ayrı hat gerektirmesi maliyeti ve senkronizasyon zorluğunu artırır. Seri iletimde veri bit bit gönderilir; bu yaklaşım daha az hat kullanır ve uzun mesafelerde daha pratiktir. Seri iletimde RS-232 gibi standartlar örnek olarak anılır.

İletişim yönü açısından simplex, half-duplex ve full-duplex ayrımı yapılır. Full-duplex yapı modern ağlarda önemlidir çünkü iki tarafın aynı anda veri alışverişi yapmasına izin verir. Bunun fiziksel olarak nasıl sağlandığı, kullanılan ortamın ve protokolün tasarımına bağlıdır.
