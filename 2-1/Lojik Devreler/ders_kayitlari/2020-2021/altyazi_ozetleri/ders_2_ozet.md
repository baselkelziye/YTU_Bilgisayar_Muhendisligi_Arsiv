# Ders 2 Çalışma Özeti

## Genel Konular

- Lojik devrelerin temeli
  - Lojik devreler ikili işaretler ve ikili kodlanmış veriler üzerinde çalışır.
  - Değişkenler yalnızca `0` ve `1` değerlerini alır; bu değerler devrelerde düşük/yüksek gerilim, açık/kapalı anahtar veya yok/var durumlarıyla yorumlanabilir.
- Boolean cebri
  - Boolean cebri klasik cebire benzeyen, fakat iki değerli değişkenler ve kendine özgü aksiyomlarla çalışan matematiksel yapıdır.
  - Lojik kapıların davranışı Boolean cebriyle ifade edilir.
- Temel lojik kapılar
  - AND kapısı yalnızca bütün girişler `1` olduğunda `1` üretir.
  - OR kapısı girişlerden en az biri `1` olduğunda `1` üretir.
  - NOT kapısı tek girişin tümleyenini üretir; `0` değerini `1`, `1` değerini `0` yapar.
- Türetilmiş kapılar
  - NAND, AND işleminin tümleyenidir.
  - NOR, OR işleminin tümleyenidir.
  - XOR girişler farklı olduğunda `1`, aynı olduğunda `0` üretir.
  - XNOR girişler aynı olduğunda `1`, farklı olduğunda `0` üretir.
- Kümeler cebri ile ilişki
  - AND işlemi kümelerde kesişime, OR işlemi birleşime, NOT işlemi tümlemeye karşılık gelir.
  - Evrensel küme `1`, boş küme `0` ile temsil edilebilir.

## Hocanın Özellikle Vurguladığı Kısımlar

- Doğruluk tablosu kapı davranışını belirleyen temel araçtır.
  - Girişlerin aldığı her kombinasyon için çıkış açıkça yazılmalıdır.
- AND ve OR kapılarının anahtarlı devre karşılıkları iyi anlaşılmalıdır.
  - AND için anahtarlar seri, OR için anahtarlar paralel düşünülür.
- Zaman diyagramlarında çıkış, girişlerin değişim noktalarına göre parça parça belirlenir.
  - AND çıkışı yalnızca iki girişin aynı anda `1` olduğu aralıklarda `1` olur.
  - OR çıkışı iki girişin de `0` olduğu aralık dışında `1` olur.
- XOR ve XNOR kavramları karıştırılmamalıdır.
  - XOR farklılık, XNOR eşdeğerlik kontrolü gibi düşünülebilir.

## Kısa Tekrar Notları

- `A · B`: AND, yalnızca `11` için `1`.
- `A + B`: OR, yalnızca `00` için `0`.
- `A'`: NOT, değeri tersler.
- NAND = `(A · B)'`, NOR = `(A + B)'`.
- XOR farklı girişlerde `1`, XNOR aynı girişlerde `1` üretir.
- Kesişim AND'e, birleşim OR'a, tümleme NOT'a karşılık gelir.

## Detaylı Açıklamalar

- Boolean cebrinde her değişken bir bitlik bilgiyi temsil eder. Bu nedenle iki girişli bir kapıda dört olası giriş durumu vardır: `00`, `01`, `10`, `11`. Kapıların doğruluk tabloları bu dört durum üzerinden kurulur.
- AND kapısı seri anahtar devresiyle modellenebilir. İki anahtarın da kapalı olması durumunda devreden akım geçer ve çıkış `1` olur. Bu model, AND işleminin “bütün koşullar sağlanmalı” mantığını açıklar.
- OR kapısı paralel anahtar devresiyle modellenebilir. Anahtarlardan herhangi biri kapalı olduğunda akım için yol oluşur ve çıkış `1` olur. Bu model, OR işleminin “en az bir koşul yeterli” mantığını gösterir.
- NOT kapısı girişin tersini üretir. Lojik yorumda bu, bir durumun yokluğunu varlığa veya varlığını yokluğa çevirmek anlamına gelir.
- Türetilmiş kapılar temel kapılardan elde edilir. NAND ve NOR özellikle önemlidir; çünkü birçok devre yalnızca bu kapılar kullanılarak kurulabilir. XOR ve XNOR ise eşitlik/farklılık ilişkilerini ifade ettiği için karşılaştırma ve aritmetik devrelerde sık kullanılır.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
