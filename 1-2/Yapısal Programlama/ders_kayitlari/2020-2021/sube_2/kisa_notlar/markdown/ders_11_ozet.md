# Ders 11 Çalışma Özeti

## Genel Konular

- Oturumun yapısı
  - Bu kayıt bir uygulama (lab) oturumudur. İki soru Dev-C++ ortamında adım adım kodlandı: (1) metni ASCII değerlerinden oluşan $M \times M$ bir "resim" matrisine gömen şifreleme ve bunu geri çözen program, (2) Eratosthenes Kalburu (Sieve of Eratosthenes) ile $n$'ye kadar olan asal sayıları bulan program.
  - Ortak tema dinamik bellek yönetimidir: `malloc`, `calloc`, `realloc`, `free`, `NULL` denetimi ve işaretçi-işaretçisi (`int **`) ile iki boyutlu dizi kurmak.
- Soru 1: Metni resme gömme (şifreleme) (ekrandan, 00:10:00)
  - Harflerin ASCII karşılıklarından $M \times M$ bir matris (resim) oluşturulur. Her hücre 0-255 arası bir piksel değeridir; değer 0 ise o pikselde harf yoktur.
  - Kelimenin ilk harfi `[0][0]`, ikincisi `[0][1]` hücresine yazılır; satır dolunca sonraki satıra geçilir. Kalan hücrelere 0 yazılır.
  - Örnek: `YILDIZTEKNIK` (12 harf) için $M = 4$ ve matris
    - `89 73 76 68 / 73 90 84 69 / 75 78 73 75 / 0 0 0 0` (ekrandan, 00:10:00).
  - Not: Stringin uzunluğu önceden bilinmiyor varsayılır; uzunluk kullanıcıdan alınır.
- Şifreleme programının adımları (ekrandan, 00:20:00, 00:25:00, 00:35:00, 00:40:00)
  - `textSize` okunur; `text = (char *)malloc(sizeof(char) * textSize);` ile metin dizisi açılır.
  - Satır sonu karakteri `scanf("%c", &junk);` ile atlanır, metin `scanf("%[^\n]", text);` ile Enter'a kadar okunur. Alternatif olarak `scanf("%s", text)` önerildi (boşluklu metinde yalnız ilk kelimeyi okur).
  - `m = ceil(sqrt(textSize));` ile kare matrisin kenarı bulunur (`math.h` gerekir). 12 için $\sqrt{12} \approx 3{,}46 \to 4$.
  - İç içe iki `for` döngüsü ve bir `k` sayacı: `k < textSize` ise `theImage[i][j] = (int)text[k];`, değilse `0`; her hücrede `k++`.
  - Matris `printf("%3d ", ...)` ile hizalı basılır, sonra bellek `free` ile bırakılır.
- Satır satır `realloc` ile büyütme ve ortaya çıkan hata
  - İlk çözümde matris 1x1 açılıp her satırda `theImage` ve her hücrede `theImage[i]` `realloc` ile birer birer büyütüldü. Bazı bilgisayarlarda kısa kelimelerde çalıştı, `YILDIZTEKNIK` ile çöktü.
  - Çözüm olarak $M$ bulunduktan sonra matris tek seferde açıldı: `calloc(m, sizeof(int *))` ve her satıra `calloc(m, sizeof(int))`.
  - Asıl nedeni için "Ders sonrası not" maddesine bakın.
- Soru 1b: Şifre çözme (decode) (ekrandan, 01:00:00, 01:10:00)
  - Kullanıcıdan $M$ alınır, matris tek seferde açılır, pikseller `(i, j) = ` istemiyle sırayla okunur.
  - İkinci döngüde her hücre için `text` bir karakter büyütülür (`realloc`), `text[textIndex] = (char)theImage[i][j];` yazılır, `textIndex++`.
  - Örnek matris girilince `YILDIZTEKNIK` geri elde edildi.
  - İyileştirme önerisi: Hücre 0 ise `text`'i büyütmeye gerek yoktur.
- İki boyutlu dinamik dizinin yapısı (sözlü soru, 01:12:10)
  - `theImage[i] = calloc(...)` tek köşeli parantezle bir satırı (bir `int *`'ı) gösterir; `theImage[i][j]` ise o satırın içindeki elemana erişir. Dış dizinin her elemanı ayrı bir dizinin adresini tutar.
- Soru 2: Eratosthenes Kalburu (ekrandan, 01:25:00 - 01:45:00)
  - 2'den $n$'ye kadar sayılar listelenir. Elenmemiş en küçük sayı $a$ için $a^2 \le n$ olduğu sürece $a$'nın katları elenir; kalanlar asaldır. $n = 10$ için sonuç $2, 3, 5, 7$.
  - `setlocale(LC_ALL, "Turkish");` ve `locale.h` ile konsolda Türkçe karakter gösterilir.
  - `prime_states` bir `char` dizisidir (1 = asal, 0 = değil); C'deki en küçük tip 1 bayt olduğu için `char` seçildi.
  - `n--` yapılır ve dizi `n` elemanla açılır: 1 asal olmadığı için tutulmaz; indeks `i`, sayı `i + 2`'yi temsil eder.
  - `malloc` sonrası `NULL` denetimi: alan yoksa "Bellekte alan oluşturulamadı." yazılır ve `exit(0)` çağrılır.
  - Kalbur döngüsü: `for (i = 0; (i+2)*(i+2) <= n+1; i++)`, asalsa `for (j = (i+2)*(i+2); j <= n+1; j += i+2) prime_states[j-2] = 0;`
  - Asallar sayılır (`prime_count`), `primes` dizisi tam bu boyutta açılır ve `primes[j] = i + 2` ile doldurulur.
  - Çıktı 10 asalda bir alt satıra geçer, sayılar 5 genişlikte hizalanır, son sayıdan sonra virgül konmaz. 500 ile denendi.

## Hocanın Özellikle Vurguladığı Kısımlar

- Boyut biliniyorsa bellek tek seferde ayrılmalı
  - Matrisin boyutu $M$ hesaplandıktan sonra belli olduğu için hücre hücre `realloc` yerine tek seferde ayırmak hem daha temiz hem daha güvenlidir. Metnin uzunluğu baştan biliniyorsa (ya da `strlen` ile hesaplanırsa) hesap baştan yapılıp ayırma doğrudan yapılabilir.
- `realloc`'un öğretilme amacı
  - İlk çözümde `realloc` bilerek kullanıldı: dizinin boyutunun çalışma sırasında yeniden düzenlenebildiğini göstermek için. Pratikte boyut biliniyorsa bu gereksizdir.
- Bellek ayırma sonrası `NULL` denetimi
  - Bellekte yer yoksa `malloc` `NULL` döner; denetlenmeli ve programdan çıkılmalıdır.
- Kod okunabilirliği
  - Değişkenlerin düzenli tanımlanması, girinti (indentation) ve yazım kurallarına uyulması gerekir; kodun yalnız çalışması değil, okunabilir olması da beklenir.
- Döngü sınırları ve indeks kaydırma
  - Kalburda `i` indeksinin `i + 2` sayısını temsil etmesi "burası önemli" diye vurgulandı; bütün koşullar (`(i+2)*(i+2) <= n+1`, `j - 2`) bu kaydırmadan gelir.

## Kısa Tekrar Notları

- $M = \lceil \sqrt{\text{uzunluk}} \rceil$; `ceil` ve `sqrt` için `#include <math.h>`.
- `scanf("%c", &junk)` önceki `scanf`'ten kalan `'\n'`'yi yutar; `%[^\n]` satırı Enter'a kadar okur.
- İki boyutlu dinamik dizi: önce `int **` için satır işaretçileri, sonra her satır için `int` dizisi.
- `printf("%3d", x)` sayıyı 3 karakterlik alana sağa dayalı yazar; tablo hizalı görünür.
- `(int)text[k]` harfin ASCII kodunu, `(char)theImage[i][j]` ASCII kodundan harfi verir.
- `realloc(p, yeni_boyut)` eski içeriği korur; `p` ya `NULL` ya da daha önce ayrılmış bir blok olmalıdır.
- Eratosthenes: katları elemeye $a^2$'den başla, $a^2 > n$ olunca dur.
- Bayrak dizisi için `char` yeterlidir (1 bayt).
- Her `malloc`/`calloc` sonrası `NULL` denetimi, iş bitince `free`.

## Detaylı Açıklamalar

- Şifreleme programında matris için `int **theImage` kullanılır. Bu, "işaretçi dizisinin işaretçisi"dir: `theImage` bellekte $M$ tane `int *` tutan bir bloğu gösterir, bu işaretçilerin her biri de $M$ tane `int` tutan ayrı bir bloğu gösterir. Bu yüzden önce `theImage = (int **)calloc(m, sizeof(int *));`, ardından döngüyle `theImage[i] = (int *)calloc(m, sizeof(int));` yazılır. Erişim yine `theImage[i][j]` biçimindedir. Programın sonunda dersteki kod yalnız `free(theImage); free(text);` çağırdı (ekrandan, 00:35:00).
- `k` sayacı metindeki sıradaki harfin indeksidir ve iç döngünün her adımında artar. `k < textSize` olduğu sürece harfin ASCII kodu (`'Y'` = 89, `'I'` = 73, `'L'` = 76, `'D'` = 68 ...) hücreye yazılır, metin bitince 0 yazılır. 12 harf ve $4 \times 4 = 16$ hücre için son satır tamamen 0 olur. Bu değerler python ile doğrulandı.
- Şifre çözmede programın metnin uzunluğunu bilmediği varsayılır. Bu yüzden `text` bir karakterlik açılır ve her hücre için `realloc(text, sizeof(char) * (textIndex + 1))` ile büyütülür; ASCII değeri `(char)` ile karaktere çevrilip eklenir. Son hücrelerdeki 0 değerleri metne `'\0'` olarak girdiği için `printf("%s", text)` metni doğru bitirir. Hücre 0 ise büyütmeyi atlamak bir iyileştirmedir. Okuma ve dönüştürme iki ayrı döngüde yapıldı; tek döngüde birleştirilebilirdi ama okunabilirlik için ayrıldı.
- Eratosthenes Kalburu'nda `prime_states` dizisinin 0. elemanı 2'yi, 1. elemanı 3'ü temsil eder (sayı = indeks + 2). Kullanıcı 10 girdiğinde `n--` ile `n = 9` olur ve dizi 2..10 arasındaki 9 sayıyı tutar. Bu yüzden döngülerdeki üst sınır `n + 1` (asıl sayı 10) ve elenen sayının indeksi `j - 2`'dir. 2 için 4, 6, 8, 10; 3 için 9 elenir; $4^2 = 16 > 10$ olunca dış döngü biter. Asal sayısı bilindikten sonra `primes` tam bu boyutta ayrılır; bu, gereksiz yer ayırmamanın bir örneğidir.
- Ders sonrası not: Satır satır `realloc` çözümündeki çökmenin nedeni derste "aynı boyutta tekrar ayırmaya çalışmak" ve "bellekte uygun yer bulunup bulunmaması" diye açıklandı. Doğrusu büyük olasılıkla şudur: `theImage` `realloc` ile bir satır büyütüldüğünde yeni eklenen `theImage[i]` işaretçisi ilklendirilmemiş (çöp değerli) kalır; iç döngüde `realloc(theImage[i], ...)` bu çöp adresle çağrılır. `realloc`'a yalnız `NULL` ya da daha önce ayrılmış bir blok verilebilir; aksi tanımsız davranıştır. Bu yüzden program bazen çalıştı, bazen çöktü. Ajanın AddressSanitizer denemesinde çökme tam bu satırda görüldü. Satır büyütüldükten sonra `theImage[i] = NULL;` yazmak ya da derste yapıldığı gibi matrisi tek seferde ayırmak hatayı giderir.
- Ders sonrası not: Dersteki kodda `text` `textSize` bayt ayrıldı; `scanf("%[^\n]", text)` sona bir de `'\0'` yazdığı için 12 harflik metin 13 bayt ister. Doğrusu `malloc(sizeof(char) * (textSize + 1))` biçimindedir. Ayrıca matrisin satırları da `free` edilmelidir (önce her `theImage[i]`, sonra `theImage`).
- Not içindeki tam C programları (düzeltilmiş şifreleme, şifre çözme ve kalbur) ajan tarafından ekran görüntülerinden yeniden kurulup `gcc -Wall` ile derlendi ve dersteki girdilerle (12 / `YILDIZTEKNIK`, $M = 4$ matrisi, 10 ve 500) denendi; ekranda tam görünmeyen satırlar genişletilmiş notta işaretlidir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
