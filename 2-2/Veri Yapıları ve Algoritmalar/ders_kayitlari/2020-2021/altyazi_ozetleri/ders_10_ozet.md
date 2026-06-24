# Ders 10 Çalışma Özeti

## Genel Konular

- Greedy algoritmalar
  - Her adımda o an için en iyi görünen seçimi yapan algoritmik yaklaşım olarak tanıtılır.
  - Bazı problemlerde optimal, bazı problemlerde optimale yakın sonuç verebileceği açıklanır.
- Greedy örnekleri
  - Para üstü verme, Huffman kodlama, minimum spanning tree ve tek kaynaklı en kısa yol problemleri greedy yaklaşım bağlamında anılır.
  - Gezgin satıcı ve benzeri optimizasyon problemlerinde greedy yöntemlerin her zaman en iyi sonucu garanti etmeyebileceği belirtilir.
- Divide and conquer
  - Problemi alt problemlere bölme, alt problemleri çözme ve sonuçları birleştirme yaklaşımı anlatılır.
  - Brute force, greedy ve decrease and conquer yaklaşımlarından farkları tartışılır.
- Merge sort
  - Diziyi ikiye bölüp alt dizileri sıraladıktan sonra sıralı biçimde birleştirme mantığı açıklanır.

## Hocanın Özellikle Vurguladığı Kısımlar

- Greedy seçim geri alınmaz.
  - Bu nedenle her problemde optimal sonuç beklemek doğru değildir.
- Divide and conquer her zaman brute force'tan iyi olmak zorunda değildir.
  - Problem alt problemlere anlamlı biçimde ayrılabiliyorsa faydalıdır.
- Merge sort'ta asıl iş birleştirme aşamasındadır.
  - Bölme işlemi basittir; sıralı alt parçaların doğru biçimde merge edilmesi sonucu üretir.

## Kısa Tekrar Notları

- Greedy: her adımda yerel en iyi seçimi yapar.
- Divide and conquer: böl, çöz, birleştir.
- Merge sort kararlı ve öngörülebilir bir sıralama algoritmasıdır.
- Rekürsif bölme tek elemana kadar devam eder.

## Detaylı Açıklamalar (Daha Fazla Detay İsteyenler İçin)

Greedy algoritmalar, karar anında en avantajlı görünen seçimi yaparak ilerler. Para üstü verme gibi bazı para sistemlerinde bu yaklaşım optimal sonuç verebilir; fakat her problem için garanti yoktur. Divide and conquer yaklaşımı ise problemi daha küçük parçalara ayırır. Merge sort bu yaklaşımın klasik örneğidir: dizi sürekli ikiye bölünür, tek elemanlı parçalar sıralı kabul edilir ve ardından bu parçalar sıralı biçimde birleştirilir. Böylece büyük problem, daha kolay yönetilen alt problemlerin birleşimiyle çözülür.
