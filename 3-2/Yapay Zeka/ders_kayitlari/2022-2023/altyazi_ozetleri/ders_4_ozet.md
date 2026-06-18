# Ders 4 Çalışma Özeti

## Genel Konular

- Kör aramanın tamamlanması
  - Önceki dersteki arama modelleri ve maliyetli arama fikri üzerinden konu toparlanır.
- Maliyet tabanlı arama
  - Yolların farklı maliyetlere sahip olduğu durumlarda aramanın toplam maliyeti dikkate alması gerektiği açıklanır.
- Sezgisel aramaya giriş
  - Arama sürecini yönlendirmek için hedefe yakınlık veya tahmini maliyet gibi probleme özel bilgilerin kullanılabileceği anlatılır.
- Sezgisel fonksiyon
  - Bir durumun hedefe ne kadar yakın olduğunu yaklaşık olarak değerlendiren fonksiyonun arama performansını belirlediği vurgulanır.
- A* algoritması
  - Geçmiş yol maliyeti ile hedefe kalan tahmini maliyeti birlikte kullanan bir yaklaşım olarak ele alınır.

## Hocanın Özellikle Vurguladığı Kısımlar

- Sezgisel bilgi aramayı hızlandırır ama doğru tasarlanmalıdır.
  - Kötü sezgisel fonksiyon algoritmayı yanlış yönlendirebilir veya beklenen kazancı sağlamayabilir.
- A* yalnızca sezgisel değere bakmaz.
  - Hem şu ana kadar oluşan maliyet hem de hedefe kalan tahmini maliyet birlikte değerlendirilir.
- Sezgisel fonksiyonun problemle uyumlu olması gerekir.
  - Harita, oyun, yol bulma gibi problemlerde hedefe yakınlığı temsil eden ölçütler doğru seçilmelidir.
- Arama algoritmalarında optimalite ve verimlilik ayrımı önemlidir.
  - Hızlı çalışan bir yöntem her zaman en iyi çözümü garanti etmeyebilir.

## Kısa Tekrar Notları

- Maliyetli aramada amaç en düşük maliyetli çözümü bulmaktır.
- Sezgisel arama, probleme özel tahmin bilgisi kullanır.
- Sezgisel fonksiyon hedefe kalan maliyeti yaklaşıklar.
- A* algoritması genellikle `f(n) = g(n) + h(n)` fikriyle açıklanır.
- İyi sezgisel, arama uzayını küçültür ve gereksiz dalları azaltır.
