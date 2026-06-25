# Ders 5 Çalışma Özeti

## Genel Konular

- **8255 Input-Output Entegresi Mod 1 ve Mod 2 İncelemesi**
  - Geçen haftanın mod 0 (basic input output) konusunun üzerinden geçilerek temel bilgiler tazelendi.
  - Bu hafta odak noktası olarak mod 1 ve mod 2 ile bit set reset (BSR) modu belirlendi.

- **Mod 1: Handshaking Mekanizması**
  - Mod 1'de portlar arası iletişimde doğrudan in/out komutları yerine tetikleme sinyalleri kullanılır.
  - Veri gönderimi ve alımı için bir el sıkışma (handshake) süreci yürütülür.
  - Bu sayede iki cihaz veya iki port arasında senkron bir iletişim sağlanır.
  - Sadece A ve B portları mod 1 için programlanabilir; C portu ise kontrol sinyallerini taşır.

- **Mod 2: Bidirectional Data Bus**
  - Sadece A portu için geçerlidir; A portu hem okuma hem yazma için aynı anda kullanılabilir.
  - B portunda bidirectional kullanım mümkün değildir; B ya mod 0 ya da mod 1'de çalışır.
  - A portu kendi içinde handshaking yaparak tek bir hat üzerinde çift yönlü veri transferi sağlar.

- **Bit Set Reset (BSR) Modu**
  - Sadece C portunun belirli pinlerini programlı olarak 1 veya 0 yapmak için kullanılır.
  - Handshaking sinyallerini manuel olarak set etmek veya resetlemek amacıyla tercih edilir.
  - Control word'un en anlamlı biti (MSB) 0 olduğunda BSR moduna girilir.
  - Binary formatla hangi pinin değiştirileceği belirlenir (örneğin 0000 0101 ile PC2 pini 1 yapılır).

## Hocanın Özellikle Vurguladığı Kısımlar

- **Control Word Yapısı ve Mod Seçimi**
  - D6 ve D5 pinleri mod seçimini belirler: mod 0 için 00, mod 1 için 01, mod 2 için 1x.
  - D4 ve D1 pinleri A ve B portlarının input/output durumunu moddan bağımsız olarak belirler.
  - D3 pini sadece mod 1'de C portunun upper kısmının (4-5-6-7 pinleri) giriş/çıkış durumunu belirler.

- **Port C Pin Kullanımının Önemi**
  - Mod 1 ve mod 2'de C portunun belirli pinleri handshake sinyalleri için ayrılmıştır.
  - Port A input modunda iken C portunun 6 ve 7 numaralı pinleri genel amaçlı kullanılabilir.
  - Port A output modunda iken C portunun 4 ve 5 numaralı pinleri genel amaçlı kullanılabilir.
  - Yanlış pin kullanımı handshake sinyalleriyle çakışarak hatalara yol açar.

- **Stroop, IBF ve OBF Sinyalleri**
  - Stroop: Veri gönderen tarafın "veri yolda" sinyali.
  - IBF (Input Buffer Full): Alan tarafın "müsaitim, veriyi alabilirim" sinyali.
  - OBF (Output Buffer Full): Gönderen tarafın "veri hazır, yola koydum" sinyali.
  - Bu sinyallerin kombinasyonu ile interrupt oluşur ve mikro işlemciye bilgi verilir.

- **Interrupt Oluşum Koşulları**
  - İlgili portun interrupt'ı enable edilmiş olmalıdır.
  - Stroop ve IBF/OBF sinyalleri arasındaki iletişim doğru kurulmuş olmalıdır.
  - Interrupt oluştuktan sonra read/write sinyalleri ile otomatik olarak resetlenir.

## Kısa Tekrar Notları

- Mod 0'da doğrudan in/out ile hızlı ama senkronizesiz iletişim sağlanır.
- Mod 1'de handshaking ile veri kaybı önlenir; C portu kontrol sinyallerini taşır.
- Mod 2'de sadece A portu bidirectional olarak kullanılabilir.
- BSR modu sadece C portu içindir ve kontrol sinyallerini manuel ayarlamak için kullanılır.
- Control word gönderildikten sonra port adreslerine veri yazılmaya başlanır.
- Her entegrenin kendine ait bir control word yapısı vardır.

## Detaylı Açıklamalar (Daha Fazla Detay İsteyenler İçin)

8255 entegresi, mikro işlemci ile çevre birimleri arasında arayüz sağlayan çok amaçlı bir entegredir. Mod 0'da basit bir giriş-çıkış yapısı sunarken, mod 1'de iki port arasında senkron bir iletişim protokolü kurar. Bu iletişimde bir port veriyi gönderirken diğer port hazırlık durumunu bildiren sinyaller üretir. Örneğin, port A'dan veri okunacaksa, karşı taraf stroop sinyaliyle "veri gönderdim" der, 8255 ise IBF sinyaliyle "müsaitim" yanıtını verir. Bu sinyallerin her ikisi de aktif olduğunda interrupt oluşur ve mikro işlemci okuma işlemini tetikler.

Mod 2 ise sadece A portu için geçerli olan bidirectional bir moddur. Bu modda A portu hem veri alabilir hem de gönderebilir, ancak bu işlem handshaking mekanizmasıyla kontrol edilir. B portunda bu tür bir çift yönlülük mümkün değildir; B portu ya mod 0'da basit giriş-çıkış olarak ya da mod 1'de tek yönlü handshaking ile kullanılır.

C portu hem mod 1 hem mod 2'de hayati bir rol oynar. Bu portun belirli pinleri handshake sinyallerini taşırken, kalan pinler genel amaçlı giriş-çıkış olarak kullanılabilir. Ancak hangi pinlerin ne amaçla kullanılabileceği, A ve B portlarının input mu output mu olduğuna göre değişir. Bu nedenle doğru pin ataması için diagramların dikkatle incelenmesi gerekir.

Bit set reset modu ise C portunun belirli pinlerini programlı olarak kontrol etmek için kullanılır. Bu mod sayesinde handshake sinyalleri manuel olarak tetiklenebilir veya resetlenebilir. Control word'un en anlamlı bitinin 0 olmasıyla bu moda girilir ve binary formatta hedef pin belirlenerek ilgili pin 1 veya 0 yapılır. Bu işlem genellikle programın başında interrupt'ları enable etmek için kullanılır.
