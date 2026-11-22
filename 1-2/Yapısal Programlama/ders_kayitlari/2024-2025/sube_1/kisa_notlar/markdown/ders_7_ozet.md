# Ders 7 Çalışma Özeti

## Genel Konular

- Dinamik bellek ayırmanın neden kullanıldığı
  - Statik tanımlanan dizi (`int a[5];` gibi) için bellek, kullanılsa da kullanılmasa da program boyunca ayrılmış kalır.
  - Dinamik ayırmada yalnız gereken kadar yer alınır, iş bitince `free` ile geri verilir. Bellek sınırlı olduğu için bu daha verimli bir programdır.
  - Boyut bir değişkenle verildiğinde (`malloc(n * sizeof(int))`) dizinin boyutunu değiştirmek kolaylaşır.
- `<stdlib.h>` içindeki dört bellek fonksiyonu
  - `malloc`: istenen bayt kadar yer ayırır, içeriği sıfırlamaz.
  - `calloc(adet, boyut)`: iki parametre alır, yer ayırır ve bütün baytları sıfırlar.
  - `realloc(ptr, yeniBoyut)`: `malloc`/`calloc` ile alınmış bloğu büyütür ya da küçültür.
  - `free`: ayrılan bloğu serbest bırakır.
- Uygulama 1: üç zarın toplam-olasılık matrisi (ekrandan, 00:10:00)
  - Birinci sütunda üç zarın olası toplamları (3-18, tekrarsız), ikinci sütunda her toplamın olasılığı tutulur; matris dinamik ayrılır.
  - Olasılık elle yazılmaz (`mat[i][j] = 0.0046296` yasak), döngü ve aritmetikle hesaplanır.
  - Çözüm dört fonksiyona bölündü: `initialize_mat`, `calc_prob`, `print_probs`, `free_mat`.
- Uygulama 2: Collatz fonksiyonu ve `realloc` ile büyüyen "sepet" dizisi (ekrandan, 00:40:00)
  - $f(n) = 3n+1$ ($n$ tek), $f(n) = n/2$ ($n$ çift); $n$ değerine 1 elde edilene kadar uygulanır.
  - Dizi `calloc` ile 2 elemanlık açılır, dolunca `realloc` ile boyutu iki katına çıkarılır; sonunda dizi, eleman sayısı ve kapasite yazdırılır, dizi `free` edilir.
- Uygulama 3: fatura oluşturma (string + dinamik bellek)
  - Dört ürün (Soda 10, Meyve Suyu 15, Kola 20, Su 5 birim fiyat) için kullanıcıdan miktar alınır; her ürün için tutar satırı ve en sonda toplam tutar satırı oluşturulur.
  - `#define` ile sabitler, `char**` satır dizisi, satır başına `malloc`, `sprintf` ile biçimli string üretimi gösterildi.
- Laboratuvar 1 sorusunun çözümü: iki $2 \times N$ matriste ortak anahtarların değerlerini toplama
  - Her matrisin ilk satırı benzersiz sayılardır (anahtar), ikinci satır bu sayıların değerleridir.
  - İki matrisin ilk satırında ortak olan her sayı için ikinci satırdaki karşılıkları toplanır.
  - Matris elemanlarına yalnız işaretçi aritmetiğiyle erişilir: `*(*(matris1) + i)` = `matris1[0][i]`, `*(*(matris1 + 1) + i)` = `matris1[1][i]`.

## Hocanın Özellikle Vurguladığı Kısımlar

- İki boyutlu dinamik matris iki aşamada ayrılır, iki aşamada boşaltılır
  - Önce satır işaretçileri için `malloc(nrow * sizeof(float*))`, sonra her satır için `calloc(ncolumn, sizeof(float))`.
  - Boşaltırken önce her satır (`free(mat[i])`), en son işaretçi dizisinin kendisi (`free(mat)`) serbest bırakılır.
- Bellek ayrıldıktan sonra `NULL` kontrolü yapılmalı
  - `mat == NULL` ise "Bellek Ayrilamadi" yazılıp `exit(-1)` ile çıkılır.
- `calloc` ile ayırmanın faydası
  - Olasılık sütunu sıfırdan başladığı için `+=` ile birikimli toplama güvenle yapılabilir.
- Dizinin "dolu eleman sayısı" ile "kapasitesi" ayrı değişkenlerde tutulmalı
  - Dolu eleman sayısı kapasiteye eşit olduğunda `realloc` ile kapasite ikiye katlanır.
- Makro (`#define`) kullanımı okunabilirliği ve bakımı kolaylaştırır
  - Ürün sayısı değişirse yalnız tek bir satır değişir.
- Laboratuvar sorusundaki kurallar sonucun doğruluğu kadar önemlidir
  - Soruda "matris elemanlarına yalnız işaretçi aritmetiğiyle erişilmeli" deniyordu; `matris[i][j]` yazmak kuralı çiğner.
- Döngü değişkeni (`i`) döngünün dışında tanımlanmalı
  - Kullanılan derleyici ortamında `for (int i = ...)` biçimi hata veriyor.

## Kısa Tekrar Notları

- `malloc` sıfırlamaz, `calloc` sıfırlar; ikisi de `<stdlib.h>` ister.
- `realloc` dönüşü aynı işaretçiye atanır: `A = (int*)realloc(A, yeniKapasite * sizeof(int));`
- `float**` matris: satır dizisi + her satır için ayrı blok; serbest bırakma tersten.
- Üç zar: $6^3 = 216$ eşit olası sonuç; her üçlü için ilgili toplamın olasılığına $1/216$ eklenir. $P(3) = 1/216 \approx 0.00463$, $P(4) = 3/216 \approx 0.01389$, $P(5) = 6/216 \approx 0.02778$, $P(10) = P(11) = 27/216 = 0.125$.
- Toplam $t$, matriste `t - 3` numaralı satıra yazılır; 3'ten 18'e 16 satır gerekir.
- Collatz, $n = 13$: 13 40 20 10 5 16 8 4 2 1 → 10 eleman, kapasite 2→4→8→16.
- `sprintf(hedef, "Toplam tutar:%d TL", toplam)` biçimli metni ekrana değil bir `char` dizisine yazar.
- `scanf("%d\n", ...)` biçimindeki `\n` fazladan girdi bekletir; `scanf("%d", ...)` kullanılmalı.
- İşaretçi aritmetiğiyle 2B erişim: `*(*(m + r) + c)` ≡ `m[r][c]`.

## Detaylı Açıklamalar

Bu oturum bir uygulama (laboratuvar) dersiydi ve tamamı dinamik bellek yönetimi üzerine kuruldu. Önce kısa bir hatırlatma yapıldı. Statik bir dizi için ayrılan bellek program boyunca kullanılsın kullanılmasın ayrılmış kalır. `malloc`, `calloc`, `realloc` ve `free` ile ise yalnız gereken kadar yer alınır ve iş bitince geri verilir. `calloc`, `malloc`'tan farklı olarak iki parametre alır (eleman sayısı ve eleman boyutu) ve ayırdığı alanı sıfırlar.

**Zar olasılık matrisi.** Üç zar birlikte atılıyor. Program, olası her toplamı birinci sütuna ve o toplamın olasılığını ikinci sütuna yazan bir matris oluşturmalı. Matris dinamik ayrılmalı, toplamlar tekrar etmemeli ve olasılıklar elle değil hesapla doldurulmalı (ekrandan, 00:10:00). Matris `initialize_mat` fonksiyonunda kuruldu. Satır işaretçileri `malloc` ile, her satır `calloc` ile ayrıldı ve her satırın 0. sütununa `i + 3` yazıldı (ekrandan, 00:25:00). `calc_prob` içinde üç iç içe `for` döngüsü her zar için 1'den 6'ya kadar döner. Her üçlüde `top = i + j + k` hesaplanır ve `mat[top-3][1] += (float) 1/(6*6*6);` ile o toplamın olasılığına bir sonucun payı eklenir (ekrandan, 00:30:00). `print_probs` satırları yazdırır. `free_mat` önce satırları, sonra matrisin kendisini serbest bırakır. `main` içinde `nrow = 16`, `ncolumn = 2` ile matris kuruldu, hesaplamadan önce ve sonra yazdırıldı, en sonda boşaltıldı (ekrandan, 00:35:00). İlk çıktıda olasılık sütunu `calloc` sayesinde sıfırdı. Hesaplamadan sonra ilk değer 0.0046 olarak geldi, bu da sorudaki tabloyla örtüşüyor.

- Ders sonrası not: anlatımda toplam sütunu için "15 satır" dendi. 3'ten 18'e kadar 16 farklı toplam olduğundan doğrusu 16 satırdır; kodda da `nrow = 16` kullanıldı (ekrandan, 00:35:00).

**Collatz dizisi ve `realloc`.** Ekrandaki "Yapısal Programlama 2. Lab" başlıklı soruda $f(n)$, $n$ tekse $3n+1$, çiftse $n/2$ olarak tanımlı (ekrandan, 00:40:00). Kullanıcıdan pozitif bir $n$ okunur (`do-while` ile pozitif girilene kadar tekrar sorulur). `calloc(2, sizeof(int))` ile 2 elemanlık bir "sepet" dizisi açılır. $n$ değerine 1 elde edilene kadar $f$ uygulanır ve her sonuç diziye eklenir. Dolu eleman sayısı (`i`) kapasiteye (`current_length`) eşit olunca kapasite ikiye katlanır ve `A = (int*)realloc(A, current_length*sizeof(int));` ile dizi büyütülür (ekrandan, 00:55:00). 17 girdisiyle yapılan denemede dizi 17 52 26 13 40 20 10 5 16 8 4 2 1 oldu: 13 eleman, kapasite 16 (ekrandan, 01:00:00).

**Fatura oluşturma.** Ürün sayısı `#define NUM_PRODUCTS 4`, satır uzunluğu `#define MAX_STRING_LENGTH 100` olarak tanımlandı (ekrandan, 01:20:00). `generateInvoice`, ürün sayısının bir fazlası kadar `char*` için yer ayırır. Fazladan satır toplam tutar içindir. Her ürün için `amount = quantities[i]*unitPrices[i]` hesaplanır, toplama eklenir, satır için `malloc(MAX_STRING_LENGTH*sizeof(char))` yapılır ve `sprintf` ile metin oluşturulur (ekrandan, 01:25:00). `printInvoice` satırları yazdırır, `freeInvoice` önce satırları, sonra satır dizisini serbest bırakır (ekrandan, 01:30:00). Miktarlar 4, 3, 1, 5 girilince toplam tutar 130 TL çıktı ($4 \cdot 10 + 3 \cdot 15 + 1 \cdot 20 + 5 \cdot 5 = 130$) (ekrandan, 01:40:00).

- Ders sonrası not: derste yazılan kodda `sprintf` yalnız toplam tutar metnini yazıyordu ve `return invoiceLines;` döngünün içinde kalmıştı (ekrandan, 01:25:00). Ürün satırları hiç doldurulmadığı için çıktıda toplam satırının önünde anlamsız karakterler göründü. Program da 3221226356 dönüş değeriyle bitti (ekrandan, 01:40:00). Bu değer Windows'ta `0xC0000374`, yani büyük olasılıkla yığın (heap) bozulması hatasıdır: ilklenmemiş işaretçiler `free` edilmişti. Doğrusu her ürün satırına kendi metnini, son satıra toplamı yazmak ve `return`'ü döngüden sonra koymaktır. Genişletilmiş notta düzeltilmiş ve test edilmiş bir sürüm var.

**Laboratuvar 1 çözümü.** İki matrisin her biri iki satırlıdır. Sütun sayıları ($N$, $M$) kullanıcıdan alınır. İlk satırlar benzersiz sayılardır; aynı sayı girilirse uyarı verilir ve yeniden giriş istenir. İkinci satır, ilk satırdaki sayıların değerleridir. Amaç, iki matrisin ilk satırında ortak olan sayıları bulup değerlerini toplamaktır. Sorudaki örnekte birinci matris $\begin{bmatrix}1 & 5\\ 7 & 2\end{bmatrix}$, ikinci matrisin ilk satırı 2, 3, 5'tir. Ortak sayı 5'tir, değerleri 2 ve 1 olduğundan sonuç 3'tür. Çözümde benzersizlik bir `bayrak` değişkeniyle denetlenir. Yeni sayı önceki sayılarla karşılaştırılır, eşitse `bayrak = 1` olur, uyarı yazılır ve `i--` ile aynı hücreye dönülür (ekrandan, 01:45:00). Ortak sayılar iki iç içe döngüyle bulunur ve `printf("%d -> %d + %d = %d\n", ...)` ile yazdırılır (ekrandan, 01:50:00). Derste yapılan denemede birinci matris ilk satır 1 2 3, değerler 4 2 1; ikinci matris ilk satır 1 5, değerler 6 4 girildi. Sonuç `1 -> 4 + 6 = 10` oldu.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
