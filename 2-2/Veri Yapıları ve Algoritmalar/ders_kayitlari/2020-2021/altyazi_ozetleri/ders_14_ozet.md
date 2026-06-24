# Ders 14 Çalışma Özeti

## Genel Konular

- Prim algoritması
  - Minimum spanning tree problemini düğüm merkezli büyüterek çözen greedy algoritma olarak anlatılır.
  - Başlangıç düğümünden itibaren mevcut ağaca en düşük maliyetle bağlanabilecek düğüm seçilir.
- Priority queue kullanımı
  - Prim algoritmasında en küçük kenar maliyetine sahip adayı seçmek için min-priority queue/heap kullanılabileceği açıklanır.
- Dijkstra algoritması
  - Tek kaynaklı en kısa yol problemi için kullanılan greedy algoritma olarak tanıtılır.
  - Kaynaktan diğer düğümlere olan geçici uzaklıkların relax işlemiyle güncellendiği anlatılır.
- Negatif kenar ağırlıkları
  - Dijkstra'nın negatif ağırlıklı kenarlarda doğru çalışmayacağı, bu durumda Bellman-Ford gibi farklı algoritmaların gerektiği belirtilir.

## Hocanın Özellikle Vurguladığı Kısımlar

- Prim ve Kruskal aynı problemi farklı stratejiyle çözer.
  - Kruskal kenarları sıralarken, Prim mevcut ağacı en ucuz yeni bağlantıyla büyütür.
- Dijkstra'da seçilen düğümün uzaklığı kesinleşir.
  - Bu özellik, tüm kenar ağırlıkları negatif değilse geçerlidir.
- Relax işlemi shortest path algoritmalarının temelidir.
  - Daha kısa bir yol bulunursa düğümün uzaklık ve ebeveyn bilgisi güncellenir.

## Kısa Tekrar Notları

- Prim MST üretir.
- Prim'de en düşük maliyetli aday kenar seçilir.
- Dijkstra tek kaynaktan en kısa yolları bulur.
- Relax daha kısa yol bulunduğunda mesafeyi günceller.
- Dijkstra negatif ağırlıklarda güvenilir değildir.

## Detaylı Açıklamalar (Daha Fazla Detay İsteyenler İçin)

Son teorik derste minimum spanning tree ve shortest path algoritmaları tamamlanır. Prim algoritması bir başlangıç düğümünden yola çıkarak ağacı genişletir; her adımda mevcut ağaçtan dışarıya giden en düşük maliyetli güvenli kenarı seçer. Dijkstra algoritması ise bir kaynak düğümden diğer düğümlere en kısa yolları bulur. Başlangıçta kaynak uzaklığı sıfır, diğerleri sonsuz kabul edilir. Kenarlar incelendikçe relax işlemiyle daha kısa yollar keşfedilir. Negatif kenarlar varsa Dijkstra'nın greedy kesinleştirme mantığı bozulabilir.
