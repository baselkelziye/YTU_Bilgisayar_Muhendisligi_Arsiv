# Ders 14 Çalışma Özeti

## Genel Konular

- Assembly dilinin yüksek seviyeli programlama dilleri (C/C++) ile birlikte kullanımı
  - Geliştirme kolaylığı ile donanım kontrolünün birleştirilmesi mantığı ele alınır.
- Inline Assembly (satır içi assembly) yazım kuralları
  - C kodu içinde `__asm` veya `asm` anahtar kelimeleriyle assembly blokları oluşturma gösterilir.
- Register ve değişken paylaşımları
  - C değişkenlerine assembly komutlarıyla doğrudan erişim ve veri transferi kuralları anlatılır.

## Hocanın Özellikle Vurguladığı Kısımlar

- Inline assembly'nin sağladığı hız ve optimizasyon avantajları
  - Görüntü işleme, kriptografi veya sürücü tasarımı gibi kritik kısımların optimize edilmesi.
- Derleyici optimizasyonları ile çakışma riskleri
  - Derleyicinin register tahsis kararlarıyla inline assembly kodundaki register kullanımının çakışmaması için dikkat edilmesi gereken kurallar.

## Kısa Tekrar Notları

- Yüksek seviyeli dillerle Assembly birlikte kullanılabilir.
- C içinde __asm veya asm anahtar kelimesiyle satır içi kod yazılır.
- Bu yöntem donanıma doğrudan ve hızlı erişim sağlar.

## Detaylı Açıklamalar (Daha Fazla Detay İsteyenler İçin)

Yüksek seviyeli diller (C/C++ gibi) geliştirme kolaylığı sağlarken, Assembly dili maksimum donanım kontrolü ve hız sunar. Bu iki dünyayı birleştirmek için Inline Assembly (satır içi assembly) kullanılır. C/C++ kodu içinde __asm veya asm anahtar kelimeleriyle assembly blokları açılır. Bu sayede C değişkenlerine doğrudan assembly komutlarıyla erişilebilir, registerlar manipüle edilebilir. Inline assembly, özellikle görüntü işleme filtreleri, kriptografik algoritmalar veya donanım sürücüsü yazımı gibi performans kritik kısımları optimize etmek için tercih edilir. Ancak derleyicinin register tahsis (register allocation) optimizasyonları ile çakışmamak için kullanılan registerların bildirilmesi önemlidir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
