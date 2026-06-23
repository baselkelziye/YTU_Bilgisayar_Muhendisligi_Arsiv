# Ders 7 Çalışma Özeti

## Genel Konular

- Data Segment ve Stack Segment yapısı
- Stack (Yığın) mimarisi ve yığın işlemleri (PUSH, POP)
- Değişkenlerin hafızadaki yerleşimi, başlangıç değeri verilmeyen değişkenler için '?' kullanımı
- Program şablonunun oluşturulması

## Hocanın Özellikle Vurguladığı Kısımlar

- Stack segmentinin çalışma mantığı (LIFO - Last In First Out).
- SP (Stack Pointer) register'ının yönetimi.
- Başlangıç değeri atanmamış değişkenlerin bellek hizalaması (alignment) ve program boyutuna etkisi.

## Kısa Tekrar Notları

- Stack Last-In-First-Out (LIFO) çalışır.
- PUSH veriyi yığına yazar, SP azalır. POP veriyi yığından alır, SP artar.
- Başlangıç değeri atanmayan değişkenler '?' ile tanımlanır.
