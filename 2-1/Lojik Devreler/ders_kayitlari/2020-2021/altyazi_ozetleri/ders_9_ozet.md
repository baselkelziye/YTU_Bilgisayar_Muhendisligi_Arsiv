# Ders 9 Çalışma Özeti

## Genel Konular

- Sıralı devrelere giriş
  - Sıralı devrelerde çıkış yalnızca mevcut girişlere değil, devrenin önceki durumuna da bağlıdır.
  - Bu yapı bellek elemanlarını gerektirir.
- Latch ve flip-flop kavramları
  - Latch seviye duyarlı, flip-flop kenar duyarlı bellek elemanı olarak ele alınır.
  - SR, JK, D ve T türleri farklı giriş-durum ilişkileriyle çalışır.
- Senkron ve asenkron davranış
  - Senkron devrelerde durum değişimi saat işaretiyle kontrol edilir.
  - Asenkron girişler saatten bağımsız olarak çıkışı etkileyebilir.
- Register kavramı
  - Birden fazla flip-flop birlikte kullanılarak çok bitli veri saklanır.

## Hocanın Özellikle Vurguladığı Kısımlar

- Sıralı devrelerde zaman ve önceki durum kavramı temel farktır.
  - Kombinasyonel devrede bellek yokken, sıralı devrede durum bilgisi vardır.
- Flip-flop doğruluk/uyarma tabloları iyi öğrenilmelidir.
  - Her flip-flop türünün girişleri farklı anlam taşır.
- Saat işaretinin aktif kenarı veya seviyesi doğru yorumlanmalıdır.

## Kısa Tekrar Notları

- Kombinasyonel devre: yalnızca girişe bağlı.
- Sıralı devre: giriş + önceki duruma bağlı.
- Latch seviye duyarlı, flip-flop kenar duyarlıdır.
- D flip-flop giriş verisini saatle saklar.
- Register çok bitli saklama yapısıdır.

## Detaylı Açıklamalar

- Sıralı devreler, dijital sistemlerde bellek ve zamanlama ihtiyacını karşılar. Bir çıkışın değeri yalnızca o andaki girişlerden değil, saklanan durumdan da etkilenir. Bu nedenle durum değişkenleri devre analizinde önemli yer tutar.
- SR latch temel bellek yapılarından biridir. Set ve reset girişleri çıkışı belirler; bazı giriş kombinasyonları yasak veya belirsiz kabul edilir. JK flip-flop bu belirsizliği toggle davranışıyla giderir.
- D flip-flop, tek veri girişine sahip olduğu için register ve bellek tasarımlarında yaygın kullanılır. Saat kenarında girişteki veri çıkışa aktarılır ve bir sonraki etkin saate kadar saklanır.
- T flip-flop giriş aktif olduğunda durum değiştirir. Bu özellik sayaç tasarımlarında kullanışlıdır.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
