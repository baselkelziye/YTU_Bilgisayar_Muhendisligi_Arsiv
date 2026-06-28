# Ders 6 Çalışma Özeti

## Genel Konular

- Kombinasyonel devre tasarımı
  - Çıkışlar yalnızca o andaki girişlere bağlıdır; bellek etkisi yoktur.
  - Fonksiyon çıkarma, sadeleştirme ve kapı düzeyinde gerçekleme birlikte ele alınır.
- Kodlayıcı ve kod çözücü yapıları
  - Decoder, ikili giriş bilgisini tekil çıkış hatlarına dönüştürür.
  - Encoder, aktif giriş bilgisini ikili koda dönüştürür.
- Multiplexer ve demultiplexer
  - Multiplexer seçme girişlerine göre çok sayıda girişten birini çıkışa aktarır.
  - Demultiplexer tek girişi seçme hatlarına göre çıkışlardan birine yönlendirir.
- Aritmetik devrelere giriş
  - Toplayıcı ve çıkarıcı devreler Boolean fonksiyonlarıyla kurulur.
  - Yarım toplayıcı, tam toplayıcı, yarım çıkarıcı ve tam çıkarıcı mantığı temel alınır.

## Hocanın Özellikle Vurguladığı Kısımlar

- Kombinasyonel devrelerde doğruluk tablosu tasarımın başlangıç noktasıdır.
  - Her çıkış için ayrı Boolean ifade çıkarılmalıdır.
- Decoder, encoder ve multiplexer hazır blok gibi düşünülse de iç yapıları kapı düzeyinde anlaşılmalıdır.
- Toplayıcı devrelerde toplam ve elde çıkışı ayrı fonksiyonlardır.
  - XOR toplam bitinde, AND/OR yapıları elde bitinde sık kullanılır.

## Kısa Tekrar Notları

- Kombinasyonel devre: bellek yok, çıkış girişe bağlı.
- Decoder: `n` girişten `2^n` çıkış üretir.
- Encoder: aktif çıkışı ikili koda çevirir.
- Multiplexer: seçme bitleriyle giriş seçer.
- Yarım toplayıcı: `S = A XOR B`, `C = A · B`.

## Detaylı Açıklamalar

- Kombinasyonel devre tasarımında önce problem giriş ve çıkış değişkenleriyle modellenir. Ardından doğruluk tablosu oluşturulur, her çıkış için Boolean ifade yazılır ve sadeleştirme yapılır.
- Decoder devreleri, özellikle minterm üretimi açısından önemlidir. Her çıkış belirli bir giriş kombinasyonuna karşılık gelir. Bu nedenle decoder çıkışları OR kapılarıyla birleştirilerek istenen fonksiyonlar oluşturulabilir.
- Multiplexer devreleri fonksiyon gerçekleştirme amacıyla da kullanılabilir. Seçme hatları değişkenlerin bir kısmını temsil ederken veri girişlerine sabit `0`, `1` veya diğer değişkenler bağlanabilir.
- Toplayıcı ve çıkarıcı devreler aritmetik işlemlerin lojik kapılarla kurulabileceğini gösterir. Toplam/fark bitleri çoğunlukla XOR mantığına, elde/borç bitleri ise AND-OR kombinasyonlarına dayanır.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
