# Ders 10 Çalışma Özeti

## Genel Konular

- Alt programlar (Procedures) ve modüler programlama
- PROC, CALL ve RET komutları
- Makro (MACRO) tanımı, makro ile yordam (procedure) arasındaki farklar
- Vize sınav sorularının çözümü ve analizi

## Hocanın Özellikle Vurguladığı Kısımlar

- Alt program çağrılarında geri dönüş adresinin stack'e kaydedilmesi ve RET ile geri alınması süreci.
- Makroların derleme aşamasında kod açılımı yapması, yordamların ise çalışma zamanında çağrılması (bellek vs hız optimizasyonu).

## Kısa Tekrar Notları

- Yordamlar PROC ile başlar, RET ile biter.
- CALL yordamı çağırır ve dönüş adresini stack'e atar.
- Makrolar koda doğrudan kopyalanır, yordam çağrısı gibi dallanma yapmaz.
