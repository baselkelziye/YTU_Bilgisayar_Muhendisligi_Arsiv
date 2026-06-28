# Ders 12 Çalışma Özeti

## Genel Konular

- Sıralı devre tasarım adımları
  - Problem durumlarla modellenir.
  - Durum diyagramı, durum tablosu, flip-flop uyarma tablosu ve çıkış fonksiyonları oluşturulur.
- Sayaç ve durum makinesi tasarımı
  - Belirli bir diziyi üreten veya belirli girişlere göre durum değiştiren devreler analiz edilir.
  - Kullanılmayan durumlar ve reset davranışı tasarımın parçasıdır.
- Karnaugh haritası ile giriş fonksiyonlarını sadeleştirme
  - Flip-flop girişleri için çıkarılan Boolean fonksiyonlar harita ile sadeleştirilir.
- Aritmetik ve kontrol mantığı ilişkisi
  - Kombinasyonel bloklar, sıralı devrelerin giriş/çıkış mantığında kullanılabilir.

## Hocanın Özellikle Vurguladığı Kısımlar

- Sıralı devre tasarımında adımlar atlanmamalıdır.
  - Durum diyagramından doğrudan devreye geçmek hata riskini artırır.
- Uyarma tablosu seçilen flip-flop türüne bağlıdır.
  - Aynı durum geçişi D, JK veya T flip-flop için farklı giriş fonksiyonları gerektirebilir.
- Kullanılmayan durumlar önemsiz kabul edilse bile tasarımda bilinçli ele alınmalıdır.

## Kısa Tekrar Notları

- Durum diyagramı davranışı gösterir.
- Durum tablosu geçişleri sayısal biçime çevirir.
- Uyarma tablosu flip-flop girişlerini verir.
- Karnaugh haritası giriş fonksiyonlarını sadeleştirir.
- Reset ve kullanılmayan durumlar kontrol edilmelidir.

## Detaylı Açıklamalar

- Sıralı devre tasarımında ilk olarak devrenin kaç duruma ihtiyaç duyduğu belirlenir. Durum sayısı, gerekli flip-flop sayısını doğrudan etkiler. `n` flip-flop ile en fazla `2^n` durum kodlanabilir.
- Durum kodlaması yapıldıktan sonra mevcut durum, girişler ve sonraki durum ilişkisi tabloya dökülür. Çıkışlar Moore veya Mealy yaklaşımına göre yalnızca duruma ya da durumla birlikte girişlere bağlı olabilir.
- Flip-flop türü seçildiğinde her durum biti için gerekli giriş fonksiyonları çıkarılır. Bu fonksiyonlar Karnaugh haritasıyla sadeleştirilir ve kapı düzeyinde kurulur.
- Tasarım doğrulamasında yalnızca geçerli durumlar değil, kullanılmayan durumlara girildiğinde devrenin ne yaptığı da incelenmelidir. Bu yaklaşım daha güvenilir devreler tasarlamayı sağlar.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
