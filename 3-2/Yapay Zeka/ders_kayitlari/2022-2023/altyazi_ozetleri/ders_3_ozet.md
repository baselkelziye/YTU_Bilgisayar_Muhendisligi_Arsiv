# Ders 3 Çalışma Özeti

## Genel Konular

- Arama problemlerine giriş
  - Bir problemin başlangıç durumu, hedef durumu, durum uzayı, operatörleri ve geçişleriyle modellenebileceği anlatılır.
- Durum uzayı
  - Problemin olası tüm durumlarının bir grafik veya ağaç gibi düşünülebileceği; çözümün bu uzay içinde bir yol bulmak olduğu açıklanır.
- Kör arama yöntemleri
  - Arama sırasında probleme özel ek bilgi kullanılmadığında yöntemlerin kör arama olarak değerlendirildiği belirtilir.
- Genişlik öncelikli ve derinlik öncelikli arama
  - BFS ve DFS yaklaşımlarının arama sırası, bellek kullanımı, çözüm bulma davranışı ve derinlik ilişkisi üzerinden karşılaştırılması yapılır.
- Maliyet kavramı
  - Her çözüm yolunun aynı kalitede olmayabileceği; bazı problemlerde en az maliyetli yolun aranması gerektiği anlatılır.

## Hocanın Özellikle Vurguladığı Kısımlar

- Arama problemi kurmadan algoritma seçmek anlamlı değildir.
  - Önce durumların, operatörlerin, başlangıcın ve hedefin net tanımlanması gerekir.
- Durum uzayı büyüdükçe arama maliyeti hızla artar.
  - Bu yüzden arama algoritmalarında zaman ve bellek karmaşıklığı kritik hale gelir.
- BFS ve DFS farklı avantajlara sahiptir.
  - BFS sığ çözümlerde güvenilirken daha fazla bellek kullanabilir; DFS daha az bellekle ilerleyebilir ama uygun olmayan dallarda derine gidebilir.
- Çözümün bulunması ile en iyi çözümün bulunması aynı şey değildir.
  - Maliyetli problemlerde bulunan ilk çözüm her zaman en uygun çözüm olmayabilir.

## Kısa Tekrar Notları

- Arama problemi: başlangıç durumu, hedef durumu, durum uzayı ve operatörlerden oluşur.
- Kör arama, probleme özel sezgisel bilgi kullanmaz.
- BFS katman katman ilerler; DFS bir dalda derine iner.
- Maliyet varsa amaç yalnızca hedefe ulaşmak değil, iyi veya en düşük maliyetli yola ulaşmaktır.
- Durum uzayının büyüklüğü algoritmanın pratikte çalışabilirliğini belirler.

## Detaylı Açıklamalar (Daha Fazla Detay İsteyenler İçin)

Yapay zekada birçok problem bir arama problemi olarak modellenebilir. Bir arama problemi; başlangıç durumu (initial state), geçiş modeli ve operatörler (actions), hedef testi (goal test) ve yol maliyeti (path cost) bileşenlerinden oluşur. Tüm olası durumların oluşturduğu yapıya durum uzayı (state space) denir. Kör arama (uninformed/blind search) yöntemleri hedefe giden yol hakkında ek sezgisel bilgiye sahip olmayan, sadece durum uzayını sistematik olarak tarayan algoritmalardır. BFS (Breadth-First Search - Enlemesine Arama) durum uzayını seviye seviye arayarak en kısa yolu bulmayı garanti eder (optimaldir) ancak bellek gereksinimi üsteldir. DFS (Depth-First Search - Derinlemesine Arama) ise bir dal boyunca en derine kadar gider; bellek tüketimi düşüktür ancak sonsuz döngülere girebilir ve optimal yolu bulması garanti değildir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
