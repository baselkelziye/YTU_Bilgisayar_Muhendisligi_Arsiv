# Ders 11 Çalışma Özeti

## Genel Konular

- Alt programlara parametre aktarma yöntemleri
- Registerlar aracılığıyla, ortak bellek alanları (global değişkenler) üzerinden veya yığın (stack) yardımıyla parametre aktarımı
- Stack frame oluşturma, BP (Base Pointer) kullanımı

## Hocanın Özellikle Vurguladığı Kısımlar

- Stack üzerinden parametre aktarımının rekürsif ve çoklu yordam çağrılarındaki güvenliği.
- Yordam çağrısından sonra stack temizliğinin (Caller veya Callee tarafından) yapılması sorumluluğu.
- BP ile stack'teki lokal değişkenlere ve parametrelere erişim.

## Kısa Tekrar Notları

- Parametre aktarımında en esnek yöntem stack kullanımıdır.
- BP register'ı yığındaki parametrelere göreli erişim sağlar ([BP+4] vb.).
- Lokal değişkenler için stack'te yer açılır.
