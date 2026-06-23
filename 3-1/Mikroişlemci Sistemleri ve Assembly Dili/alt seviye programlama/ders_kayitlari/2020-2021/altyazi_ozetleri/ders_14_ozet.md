# Ders 14 Çalışma Özeti

## Genel Konular

- Assembly dilinin yüksek seviyeli programlama dilleri (C/C++) ile birlikte kullanımı
- Inline Assembly (satır içi assembly) yazım kuralları
- Register ve değişken paylaşımları

## Hocanın Özellikle Vurguladığı Kısımlar

- Hız gerektiren kritik algoritmaların (görüntü işleme, kriptografi vb.) C kodu içinde inline assembly olarak yazılmasının sağladığı avantajlar.
- C derleyicisinin register optimizasyonları ile Assembly kodunun çakışmaması için dikkat edilmesi gerekenler.

## Kısa Tekrar Notları

- Yüksek seviyeli dillerle Assembly birlikte kullanılabilir.
- C içinde __asm veya asm anahtar kelimesiyle satır içi kod yazılır.
- Bu yöntem donanıma doğrudan ve hızlı erişim sağlar.
