# Ders 9 Çalışma Özeti

## Genel Konular

- Döngü yapıları ve LOOP komutu
- Koşullu döngüler (LOOPE, LOOPNE)
- Yığın işlemlerinin döngülerle birleşimi
- Vize sınavı değerlendirmesi ve geri bildirimler

## Hocanın Özellikle Vurguladığı Kısımlar

- LOOP komutunun CX register'ını otomatik olarak bir azaltması ve sıfır olup olmadığını kontrol etmesi.
- Büyük döngülerde veya iç içe döngülerde register çakışmalarını önlemek için stack kullanımı.

## Kısa Tekrar Notları

- LOOP döngüsü CX register'ına bağlı çalışır.
- Her adımda CX azalır ve sıfır değilse hedef adrese dallanır.
- İç içe döngülerde dış döngünün CX değeri stack'te saklanır.
