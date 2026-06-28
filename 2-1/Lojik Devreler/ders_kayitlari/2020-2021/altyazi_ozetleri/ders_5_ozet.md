# Ders 5 Çalışma Özeti

## Genel Konular

- NAND ve NOR ile temel kapıların gerçekleştirilmesi
  - NAND veya NOR kapısının girişleri birleştirilerek NOT kapısı elde edilebilir.
  - AND ve OR kapıları, NAND/NOR ve De Morgan dönüşümleriyle kurulabilir.
- Aynı tür kapılarla devre tasarımı
  - NAND ve NOR kapıları fiziksel gerçekleme ve çip kullanımı açısından avantajlıdır.
  - Aynı tür kapılarla tasarım, bağlantı karmaşıklığını ve çip sayısını azaltabilir.
- Çarpımlar toplamı biçimi
  - Fonksiyon, AND terimlerinin OR ile toplanması şeklinde ifade edilir.
  - Bu biçim NAND-NAND gerçeklemeye doğal olarak uygundur.
- Karnaugh haritası ile indirgeme
  - Fonksiyon önce Karnaugh haritasıyla sadeleştirilir, sonra seçilen kapı türüyle gerçekleştirilir.

## Hocanın Özellikle Vurguladığı Kısımlar

- Önce indirgeme, sonra devre gerçekleme yapılmalıdır.
  - Sadeleştirilmemiş ifadeyi doğrudan kurmak gereksiz kapı kullanımına yol açar.
- NAND/NOR dönüşümlerinde De Morgan kuralları merkezi rol oynar.
  - Çarpımlar toplamı NAND yapısına, toplamlar çarpımı NOR yapısına uygun biçimde dönüştürülebilir.
- Kapı sayısı kadar çip içindeki kapı yerleşimi de önemlidir.
  - Tek bir entegre içindeki kapıların verimli kullanılması devre maliyetini azaltır.

## Kısa Tekrar Notları

- NAND ile NOT: `A NAND A = A'`.
- NOR ile NOT: `A NOR A = A'`.
- Çarpımlar toplamı: ürün terimleri OR ile toplanır.
- NAND-NAND gerçekleme için önce ürün terimlerinin tümleyenleri, sonra bunların NAND birleşimi kullanılır.
- Karnaugh haritası büyük komşu gruplar üzerinden sadeleştirme sağlar.

## Detaylı Açıklamalar

- NAND ve NOR kapıları evrensel kapılardır; yani temel lojik işlemler yalnızca bu kapılarla kurulabilir. NOT işlemi, kapının iki girişine aynı değişken verilerek elde edilir. Bu yöntem hem NAND hem NOR için geçerlidir.
- AND kapısı NAND çıkışının tekrar tümleyenlenmesiyle elde edilir. OR kapısı ise De Morgan dönüşümüyle girişlerin tümleyenlerinin NAND'lanması veya NOR çıkışının tümleyenlenmesi gibi yaklaşımlarla kurulabilir.
- Çarpımlar toplamı biçimindeki bir fonksiyon NAND ile gerçekleştirilirken önce her çarpım teriminin NAND çıkışı alınır. Son katmanda bu ara sonuçlar tekrar NAND'lanarak OR etkisi De Morgan üzerinden sağlanır. Böylece AND-OR devresi yerine NAND-NAND yapısı elde edilir.
- Karnaugh haritası örneklerinde `1` olan hücreler en büyük gruplar halinde seçilir. Her grup, değişmeyen değişkenlerden oluşan bir sade terim üretir. Bu terimler sonradan seçilen kapı teknolojisine uygun biçimde dönüştürülür.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
