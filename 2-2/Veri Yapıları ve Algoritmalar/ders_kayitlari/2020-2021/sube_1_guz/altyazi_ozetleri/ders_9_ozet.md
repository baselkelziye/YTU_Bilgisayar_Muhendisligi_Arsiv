# Ders 9 Çalışma Özeti

## Genel Konular

- Substring arama problemi
  - Büyük bir metin içinde daha kısa bir örüntünün bulunması problemi tanımlanır.
  - Metin uzunluğu `N`, örüntü uzunluğu `M` olarak ele alınır.
- Brute force substring search
  - Örüntünün metin üzerinde birer karakter kaydırılarak karşılaştırıldığı temel yöntem anlatılır.
  - Basit olmasına rağmen büyük metinlerde maliyetli olabileceği gösterilir.
- Boyer-Moore ve Horspool yaklaşımı
  - Karşılaştırmayı sağdan başlatma ve uyuşmazlık durumunda birden fazla karakter kaydırma fikri açıklanır.
  - Ön işlem tablosu kullanarak bazı konumların güvenle atlanabileceği belirtilir.
- Space-time tradeoff
  - Ek tablo veya ön işlem kullanarak çalışma zamanının azaltılabileceği, bunun bellek maliyeti doğurabileceği vurgulanır.

## Hocanın Özellikle Vurguladığı Kısımlar

- Substring arama yalnızca metin arama değildir.
  - DNA dizileri, disk imajları, intihal kontrolü ve log analizi gibi birçok alanda kullanılır.
- Brute force anlaşılırdır ama her zaman verimli değildir.
  - Özellikle çok büyük metinlerde gereksiz karşılaştırma sayısı artar.
- Boyer-Moore ailesinin gücü atlama stratejisidir.
  - Uyuşmazlık bilgisi kullanılarak örüntü bazı konumlarda hiç denenmeden ilerletilebilir.

## Kısa Tekrar Notları

- Text: arama yapılan büyük metin.
- Pattern: aranan örüntü.
- Brute force her konumu tek tek dener.
- Boyer-Moore/Horspool ön işlem tablosuyla kaydırma yapar.
- Daha fazla bellek kullanımı daha az karşılaştırma sağlayabilir.

## Detaylı Açıklamalar (Daha Fazla Detay İsteyenler İçin)

Substring arama, bir karakter dizisi içinde belirli bir örüntünün hangi konumda geçtiğini bulma problemidir. Brute force yöntemi, örüntüyü metnin her olası konumuna yerleştirip karakter karakter karşılaştırır. Bu yöntem kodlaması kolay olduğu için küçük verilerde yeterli olabilir; fakat büyük metinlerde maliyeti artar. Boyer-Moore ve Horspool yaklaşımlarında uyuşmazlık oluştuğunda örüntünün ne kadar kaydırılabileceği önceden hesaplanan tablolardan yararlanılarak belirlenir. Böylece bazı karakterler hiç karşılaştırılmadan geçilebilir.
