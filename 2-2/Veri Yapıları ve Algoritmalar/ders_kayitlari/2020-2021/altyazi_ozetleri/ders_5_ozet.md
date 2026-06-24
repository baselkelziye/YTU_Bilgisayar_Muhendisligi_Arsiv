# Ders 5 Çalışma Özeti

## Genel Konular

- Yığın (stack)
  - Son giren ilk çıkar (LIFO) mantığıyla çalışan veri yapısı olarak tanıtılır.
  - `push`, `pop`, `peek/top`, boşluk ve doluluk kontrolleri ele alınır.
- Stack uygulamaları
  - Fonksiyon çağrıları, derleyici ayrıştırma işlemleri, parantez dengeleme, infix-postfix dönüşümü ve diziyi ters çevirme örnekleri verilir.
- Kuyruk (queue)
  - İlk giren ilk çıkar (FIFO) mantığıyla çalışan veri yapısı olarak açıklanır.
  - Kuyruğun baş ve son işaretçileriyle yönetildiği, ekleme ve çıkarma uçlarının farklı olduğu anlatılır.
- Dairesel kuyruk fikri
  - Dizi tabanlı kuyrukta boşalan alanları yeniden kullanmak için dairesel yapıdan yararlanılabileceği belirtilir.

## Hocanın Özellikle Vurguladığı Kısımlar

- Stack ve queue erişim sırasına göre ayrılır.
  - Stack LIFO, queue FIFO davranışı gösterir; bu fark uygulama seçimini belirler.
- Parantez kontrolü stack için klasik bir örnektir.
  - Açılan parantezler yığına konur, kapanan parantezler uygun açılışla eşleştirilir.
- Kuyrukta baş ve son işaretçilerinin güncellenmesi dikkat ister.
  - Yanlış güncelleme eleman kaybına veya yanlış çıkarma sırasına neden olabilir.

## Kısa Tekrar Notları

- Stack: son giren ilk çıkar.
- Queue: ilk giren ilk çıkar.
- `push/pop` stack işlemleridir.
- `enqueue/dequeue` queue işlemleridir.
- Dairesel kuyruk dizi alanını verimli kullanır.

## Detaylı Açıklamalar (Daha Fazla Detay İsteyenler İçin)

Bu derste doğrusal veri yapılarının özel erişim kurallarıyla nasıl farklılaştığı gösterilir. Stack, özellikle geri dönüş gerektiren işlemlerde doğal bir model sunar; fonksiyon çağrılarının çalışma zamanı yığını bunun tipik örneğidir. Parantez dengeleme probleminde her açılış parantezi yığına konur, kapanış parantezi geldiğinde en üstteki öğeyle eşleşme aranır. Queue ise sıraya alma mantığını temsil eder; işlemci kuyrukları, yazdırma kuyrukları ve genişlik öncelikli gezinti gibi örneklerde kullanılır. Dizi tabanlı kuyrukta alanı boşa harcamamak için baş ve son indisleri modüler aritmetik ile döndürülür.
