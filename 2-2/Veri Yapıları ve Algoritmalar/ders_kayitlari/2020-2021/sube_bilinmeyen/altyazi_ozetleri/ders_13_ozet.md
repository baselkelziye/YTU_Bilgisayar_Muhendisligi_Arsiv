# Ders 13 Çalışma Özeti

## Genel Konular

- Topological sort
  - Yönlü çevrimsiz graflarda düğümlerin bağımlılık ilişkilerini bozmayacak doğrusal sıraya konması olarak anlatılır.
  - DFS bitiş zamanlarına göre sıralama fikri kullanılır.
- Connected component fikri
  - Grafın birbirine erişebilen alt parçalar halinde incelenebileceği hatırlatılır.
- Minimum spanning tree
  - Ağırlıklı, bağlı ve yönsüz bir grafta tüm düğümleri en düşük toplam maliyetle bağlayan ağaç problemi tanımlanır.
  - Spanning tree'nin çevrim içermemesi ve `V - 1` kenar taşıması gerektiği açıklanır.
- Kruskal algoritması
  - Kenarları ağırlığa göre küçükten büyüğe sıralayıp çevrim oluşturmayan kenarları seçme yaklaşımı anlatılır.
  - Güvenli kenar seçimi greedy mantıkla ilişkilendirilir.

## Hocanın Özellikle Vurguladığı Kısımlar

- Topological sort yalnızca DAG yapılarında anlamlıdır.
  - Çevrim varsa bağımlılıkları bozmayan doğrusal sıra kurulamaz.
- MST'de amaç tüm düğümleri bağlamak ama çevrim oluşturmamaktır.
  - Fazladan çevrim maliyeti artırır ve ağaç özelliğini bozar.
- Kruskal greedy bir algoritmadır.
  - Her adımda en düşük maliyetli güvenli kenar seçilir.

## Kısa Tekrar Notları

- Topological sort bağımlılık sıralamasıdır.
- MST tüm düğümleri minimum maliyetle bağlar.
- Spanning tree `V - 1` kenar içerir.
- Kruskal kenarları küçükten büyüğe gezer.
- Çevrim oluşturan kenar seçilmez.

## Detaylı Açıklamalar (Daha Fazla Detay İsteyenler İçin)

Topological sort, bir işi yapmadan önce yapılması gereken ön koşullar olduğunda kullanılan graf sıralamasıdır. DFS gezintisinde düğümlerin bitiş zamanları, bağımlılıkların doğru sıraya konmasına yardımcı olur. Dersin ana konusu olan minimum spanning tree probleminde ise bütün düğümler bağlı kalmalı, toplam kenar maliyeti en düşük olmalı ve çevrim oluşmamalıdır. Kruskal algoritması bu problemi greedy biçimde çözer: kenarlar ağırlıklarına göre sıralanır ve her kenar, mevcut seçilmiş kenarlarla çevrim oluşturmadığı sürece çözüme eklenir.
