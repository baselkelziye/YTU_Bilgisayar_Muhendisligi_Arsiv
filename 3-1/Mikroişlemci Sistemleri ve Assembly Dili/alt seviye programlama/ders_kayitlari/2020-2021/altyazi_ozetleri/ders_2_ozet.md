# Ders 2 Çalışma Özeti

## Genel Konular

- Fiziksel adres hesaplama formülü (Segment * 16 + Offset)
- Veri tanımlama direktifleri (DB - Define Byte, DW - Define Word)
- Değişken tanımlama kuralları ve bellek yerleşimi
- Değişken isimlerinin sayıyla başlayamaması ve hex sayılarda harfle başlayan değerlerin başına sıfır (0) konulması kuralı (örn. 0Ah)

## Hocanın Özellikle Vurguladığı Kısımlar

- Fiziksel adrese erişim mekanizması ve segment sınırları (64 KB).
- Değişken bildirimlerinde veri boyutlarının (Byte ve Word) doğru belirlenmesinin önemi.
- Hexadecimal gösterimlerde harfle başlayan değerlerin derleyici tarafından değişken olarak algılanmaması için prefix ve suffix kurallarına dikkat edilmelidir.

## Kısa Tekrar Notları

- Fiziksel adres = (Segment * 10h) + Offset.
- Değişken tanımlarken byte için DB, word için DW kullanılır.
- Hexadecimal sayılarda harfle başlayanların önüne 0 konur (örn: 0FFh).
