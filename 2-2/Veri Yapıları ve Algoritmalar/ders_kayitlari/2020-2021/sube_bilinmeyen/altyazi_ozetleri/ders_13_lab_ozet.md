# Ders 13 Lab Çalışma Özeti

## Genel Konular

- Counting sort
  - Sınırlı değer aralığında elemanların frekanslarını sayarak sıralama yapma yaklaşımı anlatılır.
  - Karşılaştırmaya dayalı olmayan bir sıralama yöntemi olduğu vurgulanır.
- Radix sort ve string sort
  - Basamak veya karakter konumlarına göre sıralama fikri açıklanır.
  - LSD string sort'un sabit uzunluklu anahtarlarda kullanılabileceği belirtilir.
- Sıralama algoritmalarını karşılaştırma
  - Zaman karmaşıklığı, bellek kullanımı, kararlılık, yerinde çalışma ve veri türüne uygunluk gibi ölçütler üzerinden seçim yapılması gerektiği anlatılır.
- Space-time tradeoff
  - Daha fazla yardımcı bellek kullanarak daha hızlı sıralama elde edilebileceği örneklenir.

## Hocanın Özellikle Vurguladığı Kısımlar

- Counting sort değer aralığı küçükse etkilidir.
  - Aralık çok büyürse sayaç dizisinin bellek maliyeti artar.
- Her sıralama algoritması her veri için en iyi değildir.
  - Veri boyutu, değer aralığı, anahtar türü ve kararlılık ihtiyacı seçimde belirleyicidir.
- Karşılaştırmaya dayalı olmayan yöntemler özel koşullarda çok hızlı olabilir.

## Kısa Tekrar Notları

- Counting sort frekans sayar.
- Radix sort basamak/karakter bazlı ilerler.
- LSD string sort sabit uzunluklu stringlerde kullanılır.
- Algoritma seçimi veri özelliklerine bağlıdır.

## Detaylı Açıklamalar (Daha Fazla Detay İsteyenler İçin)

Bu uygulama dersi, sıralama algoritmalarını karşılaştırmalı düşünmeyi sağlar. Counting sort, elemanların hangi değerlerden kaç tane olduğunu sayar ve sonuç dizisini bu sayımlara göre kurar. Değer aralığı küçük olduğunda doğrusal zamana yaklaşabilir; ancak büyük aralıkta bellek maliyeti artar. Radix sort ve string sort, sayıları veya karakter dizilerini basamak/konum konum işleyerek sıralar. Bu yöntemler karşılaştırma tabanlı olmadıkları için uygun veri tiplerinde çok verimli olabilir.
