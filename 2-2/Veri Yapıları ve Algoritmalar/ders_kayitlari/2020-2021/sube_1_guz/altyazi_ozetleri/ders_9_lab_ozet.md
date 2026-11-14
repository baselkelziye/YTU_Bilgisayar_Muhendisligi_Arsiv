# Ders 9 Lab Çalışma Özeti

## Genel Konular

- Aralık ve karşılaştırma soruları
  - Verilen bir sayının hangi aralıklara düştüğünü belirleme gibi koşul tabanlı algoritma örnekleri tartışılır.
- String search hazırlığı
  - Brute force ve daha gelişmiş arama yöntemlerinin karşılaştırma sayısı üzerinden değerlendirilebileceği hatırlatılır.
- Algoritmik düşünmede sınır durumları
  - Aralıkların çakışması, boş aralıklar ve eşitlik sınırları gibi durumların dikkatle ele alınması gerektiği vurgulanır.

## Hocanın Özellikle Vurguladığı Kısımlar

- Koşullar net kurulmazsa aynı değer birden fazla aralığa girebilir veya hiçbir aralığa girmeyebilir.
- Karşılaştırma sayısı algoritmanın maliyetini anlamada önemli bir göstergedir.
- Test verileri sınır değerleri içermelidir.

## Kısa Tekrar Notları

- Aralık kontrolünde alt ve üst sınırlar açık tanımlanmalıdır.
- Çakışan koşullar hatalı sonuç doğurabilir.
- Karakter karşılaştırmaları substring aramada temel maliyettir.

## Detaylı Açıklamalar (Daha Fazla Detay İsteyenler İçin)

Bu uygulama kaydı, koşul kurma ve karşılaştırma sayma becerilerini destekler. Bir sayının aralıklara göre sınıflandırılması basit görünse de sınırların dahil olup olmadığı ve aralıkların çakışıp çakışmadığı algoritmanın doğruluğunu belirler. Aynı düşünce substring aramada da görülür: her karakter karşılaştırması maliyete katkı sağlar ve daha iyi algoritmalar gereksiz karşılaştırmaları azaltmaya çalışır.
