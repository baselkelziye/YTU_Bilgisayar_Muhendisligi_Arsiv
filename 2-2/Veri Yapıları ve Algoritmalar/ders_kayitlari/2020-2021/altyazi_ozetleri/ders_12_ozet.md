# Ders 12 Çalışma Özeti

## Genel Konular

- Graf veri yapısı
  - Düğümler ve kenarlardan oluşan bağlantılı yapı olarak tanımlanır.
  - Karmaşıklık analizinde düğüm sayısı `V`, kenar sayısı `E` ile ifade edilir.
- Graf kullanım alanları
  - Haritalar, sosyal ağlar, web sayfaları, bilgisayar ağları, biyolojik ağlar ve öneri sistemleri gibi örnekler verilir.
- Graf türleri ve kavramları
  - Yönlü/yönsüz, ağırlıklı/ağırlıksız, çevrimli/çevrimsiz graf ayrımları yapılır.
  - Derece, yol, çevrim, connected component ve subgraph kavramları açıklanır.
- Graf gösterimleri
  - Komşuluk listesi ve komşuluk matrisi yaklaşımları anlatılır.
  - Seyrek graflarda komşuluk listesinin, yoğun graflarda matrisin avantajlı olabileceği belirtilir.
- Graf gezintileri
  - BFS ve DFS mantığına giriş yapılır; gezintilerin graf problemlerinin temeli olduğu gösterilir.

## Hocanın Özellikle Vurguladığı Kısımlar

- Aynı graf farklı şekillerde çizilebilir.
  - Düzlemdeki görünüm değil, düğüm ve kenar ilişkileri grafı belirler.
- Graf algoritmalarında `V` ve `E` temel büyüklüklerdir.
  - Karmaşıklık hesapları çoğunlukla bu iki parametre üzerinden yapılır.
- Gösterim seçimi performansı etkiler.
  - Komşuluk listesi ve matrisi farklı bellek ve erişim maliyetlerine sahiptir.

## Kısa Tekrar Notları

- Graf = düğümler + kenarlar.
- Directed graph kenar yönü taşır.
- Weighted graph kenar maliyeti taşır.
- Adjacency list seyrek graflarda kullanışlıdır.
- BFS kuyruk, DFS rekürsiyon/stack mantığıyla ilişkilidir.

## Detaylı Açıklamalar (Daha Fazla Detay İsteyenler İçin)

Graflar, nesneler arasındaki ilişkileri modellemek için kullanılan çok genel veri yapılarıdır. Bir şehir haritasında kavşaklar düğüm, yollar kenar; sosyal ağda kişiler düğüm, takip/arkadaşlık ilişkileri kenar olarak düşünülebilir. Grafın çizimde nasıl göründüğü önemli değildir; hangi düğümlerin hangi kenarlarla bağlı olduğu esastır. Komşuluk listesi her düğümün komşularını saklar ve seyrek graflarda bellek açısından avantajlıdır. Komşuluk matrisi ise iki düğüm arasında kenar olup olmadığını hızlı sorgulatır, fakat daha fazla bellek kullanır.
