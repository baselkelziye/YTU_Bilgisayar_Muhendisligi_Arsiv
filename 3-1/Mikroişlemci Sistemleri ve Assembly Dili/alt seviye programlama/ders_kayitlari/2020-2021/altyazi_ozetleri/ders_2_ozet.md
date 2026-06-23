# Ders 2 Çalışma Özeti

## Genel Konular

- Fiziksel adres hesaplama mantığı
  - 8086'nın 20-bit adres hattına erişim için kullanılan Segment * 16 + Offset (Segment << 4 + Offset) formülü anlatılır.
- Veri tanımlama direktifleri
  - Bellekte veri saklamak için kullanılan DB (Define Byte - 8 bit) ve DW (Define Word - 16 bit) direktifleri tanıtılır.
- Değişken tanımlama kuralları ve bellek yerleşimi
  - Değişken isimlerinin sayıyla başlayamaması ve hex sayılarda harfle başlayan değerlerin başına sıfır (0) konulması kuralı (örn. 0Ah) açıklanır.

## Hocanın Özellikle Vurguladığı Kısımlar

- Fiziksel adrese erişim mekanizması ve segment sınırları
  - Her segmentin en fazla 64 KB veri/kod barındırabileceği ve bu sınırın aşılmaması gerektiği.
- Veri boyutu belirleme
  - Değişken bildirimlerinde veri boyutlarının (Byte ve Word) doğru belirlenmesinin bellek tasarrufu ve işlem doğruluğu için önemi.
- Hexadecimal gösterim kuralları
  - Harfle başlayan hex değerlerin derleyici tarafından değişken olarak algılanmaması için prefix ve suffix kurallarına dikkat edilmesi gerektiği.

## Kısa Tekrar Notları

- Fiziksel adres = (Segment * 10h) + Offset.
- Değişken tanımlarken byte için DB, word için DW kullanılır.
- Hexadecimal sayılarda harfle başlayanların önüne 0 konur (örn: 0FFh).

## Detaylı Açıklamalar (Daha Fazla Detay İsteyenler İçin)

8086 işlemcisi 20-bitlik adres hattına (1 MB adres uzayı) sahip olmasına rağmen registerları 16-bittir. Bu nedenle 1 MB'lık fiziksel belleğe erişebilmek için segmentasyon tekniği kullanılır. Fiziksel Adres = (Segment * 16) + Offset (veya Segment << 4 + Offset) formülüyle hesaplanır. Bellekte veri tanımlamak için DB (Define Byte - 8 bit) ve DW (Define Word - 16 bit) direktifleri kullanılır. Değişken tanımlamalarında isimlerin rakamla başlayamaması, büyük/küçük harf duyarlılığı (derleyiciye bağlı) ve hexadecimal değerlerde harfle başlayan sayıların başına sıfır (0) konulması zorunluluğu gibi kurallar mevcuttur. Örneğin, 0AH yazılmazsa derleyici bunu AH register'ı veya bir değişken adı olarak algılayıp hata verecektir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
