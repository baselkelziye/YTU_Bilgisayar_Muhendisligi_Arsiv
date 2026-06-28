# Ders 8 Çalışma Özeti

## Genel Konular

- Kombinasyonel devre bloklarının devamı
  - Decoder, encoder ve seçici devreler farklı tasarım problemlerinde yeniden kullanılır.
  - Hazır blokların giriş-çıkış ilişkisi doğruluk tablolarıyla açıklanır.
- Aritmetik devreler
  - Yarım ve tam toplayıcı yapıları çok bitli toplama devrelerinin temelini oluşturur.
  - Çıkarıcı devrelerde fark ve borç çıkışları ayrı Boolean fonksiyonlarıdır.
- Paralel toplama mantığı
  - Çok bitli toplamada her basamak bir önceki basamağın elde çıkışını kullanır.
  - Elde yayılımı gecikme ve tasarım karmaşıklığı açısından önemlidir.
- Fonksiyonların bloklarla gerçekleştirilmesi
  - Decoder veya multiplexer kullanarak Boolean fonksiyonları kurulabilir.

## Hocanın Özellikle Vurguladığı Kısımlar

- Aritmetik devrelerde her çıkış bağımsız analiz edilmelidir.
  - Toplam/fark ile elde/borç aynı fonksiyon değildir.
- Çok bitli devreler tek bitlik yapıların düzenli bağlanmasıyla oluşur.
- Hazır blok kullanımı, kapı düzeyindeki mantığın anlaşılmasını gereksiz kılmaz.

## Kısa Tekrar Notları

- Yarım toplayıcı iki giriş toplar, elde üretir.
- Tam toplayıcı iki bit ve giriş eldesini toplar.
- Yarım çıkarıcı fark ve borç üretir.
- Çok bitli toplamada elde bir sonraki basamağa aktarılır.
- Decoder/multiplexer fonksiyon gerçekleştirmede kullanılabilir.

## Detaylı Açıklamalar

- Toplayıcı devrelerin temelinde XOR ve AND işlemleri bulunur. İki bitin toplam biti XOR ile, elde biti AND ile ifade edilir. Giriş eldesi eklendiğinde tam toplayıcı yapısı ortaya çıkar.
- Tam toplayıcılar kademeli bağlanarak çok bitli paralel toplayıcı oluşturulur. Her basamak kendi toplam bitini üretirken elde çıkışını bir sonraki basamağa aktarır.
- Çıkarıcı devrelerde fark biti, girişlerin farklılığına bağlıdır; borç biti ise çıkarılan değerin mevcut bitten büyük olduğu durumları temsil eder. Bu nedenle borç fonksiyonu ayrı analiz edilmelidir.
- Decoder ve multiplexer gibi bloklar, yalnızca belirli bir iş yapan elemanlar değil, genel Boolean fonksiyonları gerçekleştirmek için de kullanılabilen yapı taşlarıdır.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
