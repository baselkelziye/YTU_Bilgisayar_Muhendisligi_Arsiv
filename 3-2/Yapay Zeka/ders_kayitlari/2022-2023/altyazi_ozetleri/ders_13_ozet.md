# Ders 13 Çalışma Özeti

## Genel Konular

- Pekiştirmeli öğrenmeye giriş
  - Bir ajanın ortamla etkileşerek ödül ve ceza geri bildirimleri üzerinden davranış öğrenmesi anlatılır.
- Ajan ve ortam ilişkisi
  - Ajanın bir durumda bulunduğu, bir eylem seçtiği, ortamdan yeni durum ve ödül aldığı döngü açıklanır.
- Durum, eylem ve ödül kavramları
  - Pekiştirmeli öğrenmede karar verme sürecinin state, action ve reward bileşenleriyle kurulduğu belirtilir.
- Politika
  - Hangi durumda hangi eylemin seçileceğini belirleyen yapı olarak politika tanıtılır.
- Değer kavramı
  - Bir durumda veya durum-eylem çiftinde gelecekte beklenen ödülün öneminden bahsedilir.
- Q-learning
  - Durum-eylem çiftleri için değer tutan Q tablosu üzerinden politikanın zamanla iyileştirilmesi anlatılır.

## Hocanın Özellikle Vurguladığı Kısımlar

- Pekiştirmeli öğrenme, denetimli öğrenmeden farklıdır.
  - Model doğrudan doğru cevap etiketleriyle değil, ortamdan aldığı ödül/ceza geri bildirimiyle öğrenir.
- Amaç anlık ödülü değil uzun vadeli toplam getiriyi iyi hale getirmektir.
  - Bir eylem o anda iyi görünmese bile gelecekte daha iyi sonuçlara götürebilir.
- Politika öğrenmenin merkezindedir.
  - Ajanın amacı, hangi durumda hangi hareketi yapacağını belirleyen politikayı iyileştirmektir.
- Keşif ve sömürü dengesi önemlidir.
  - Ajan hem bildiği iyi eylemleri kullanmalı hem de daha iyi seçenekler bulmak için yeni durumları denemelidir.
- Q tablosu durum-eylem değerlerini temsil eder.
  - Q-learning sürecinde bu değerler deneyimle güncellenerek daha iyi kararlar üretir.

## Kısa Tekrar Notları

- Pekiştirmeli öğrenmede ajan ortamla etkileşerek öğrenir.
- Temel bileşenler durum, eylem, ödül, politika ve değerdir.
- Politika, durumda seçilecek eylemi belirler.
- Q-learning, durum-eylem çiftleri için değer öğrenir.
- Öğrenmenin hedefi uzun vadeli toplam ödülü artıran davranışı bulmaktır.
