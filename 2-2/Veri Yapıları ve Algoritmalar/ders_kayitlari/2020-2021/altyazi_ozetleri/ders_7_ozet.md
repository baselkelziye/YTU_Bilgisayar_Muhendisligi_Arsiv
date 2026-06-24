# Ders 7 Çalışma Özeti

## Genel Konular

- Heap veri yapısı
  - Heap'in complete binary tree üzerine kurulu özel bir ağaç yapısı olduğu anlatılır.
  - Max-heap ve min-heap ayrımı yapılır.
- Diziyle heap gösterimi
  - Ebeveyn ve çocuk indislerinin aritmetik ilişkilerle bulunabileceği gösterilir.
  - Son iç düğümden başlayarak heapify işlemiyle heap kurulabileceği açıklanır.
- Priority queue
  - Öncelik kuyruğunun heap ile verimli biçimde gerçekleştirilebileceği belirtilir.
  - En yüksek veya en düşük öncelikli elemanı hızlı çekme ihtiyacı örneklenir.
- Heap sort
  - Heap kurma ve kök elemanı sona taşıyıp yeniden heapify etme mantığı üzerinden sıralama yapılır.

## Hocanın Özellikle Vurguladığı Kısımlar

- Heap sıralı bir ağaç değildir.
  - Sadece ebeveyn-çocuk arasında öncelik kuralı vardır; tüm düğümler global olarak sıralı görünmek zorunda değildir.
- Complete binary tree özelliği dizi gösterimini mümkün kılar.
  - Boşluklar oluşmadığı için indis ilişkileriyle çocuk ve ebeveyn hesaplanabilir.
- Heapify işlemi temel operasyondur.
  - Heap kuralı bozulduğunda yapıyı yeniden düzenleyen ana işlem heapify'dır.

## Kısa Tekrar Notları

- Max-heap'te ebeveyn çocuklarından büyük/eşittir.
- Min-heap'te ebeveyn çocuklarından küçük/eşittir.
- Heap complete binary tree şeklindedir.
- Priority queue için heap kullanmak verimlidir.
- Heap sort karşılaştırmaya dayalı bir sıralama yöntemidir.

## Detaylı Açıklamalar (Daha Fazla Detay İsteyenler İçin)

Heap, ağaç yapısının öncelik ilişkisiyle özelleştirilmiş halidir. Max-heap'te en büyük değer kökte, min-heap'te en küçük değer kökte bulunur. Bu özellik, en öncelikli elemanı hızlıca almak için kullanılır. Heap'in complete binary tree olması, onu dizi içinde boşluk bırakmadan saklamayı sağlar. Heap sort algoritmasında önce dizi heap haline getirilir, ardından kökteki eleman sona taşınır ve kalan bölüm yeniden heapify edilir. Böylece sıralı sonuç elde edilir.
