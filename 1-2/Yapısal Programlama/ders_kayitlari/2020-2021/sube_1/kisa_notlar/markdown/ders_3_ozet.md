# Ders 3 Çalışma Özeti

## Genel Konular

- C dilinde veri tiplerinin sınıflandırılması
  - C'de veri tipleri üç gruba ayrılır: tipi olmayan `void`, skaler tipler ve birleşik tipler (`struct`, `union`).
  - `void` değişken olmaz; geriye hesap sonucu döndürmeyen fonksiyonların tipi olarak ve ileride görülecek genel (generic) işaretçilerde kullanılır.
  - Skaler tipler: aritmetik tipler (tam sayı ve ondalıklı), işaretçiler ve `enum`.
  - C kuvvetli tiplemeli bir dildir: değişkenin tipi baştan yazılır. Bu, derleme anında hata yakalamayı kolaylaştırır; tipsiz (`var` benzeri) dillerin esnekliği ise disiplinsizlik ve zor yakalanan hatalar gibi bir bedelle gelir.
- Skaler tipler için 9 ayrılmış kelime (ekrandan, 00:10:00)
  - Temel tipler: `char`, `int`, `float`, `double`, `enum`.
  - Niteleyiciler (qualifier): `long`, `short`, `signed`, `unsigned`. Temel tipin önüne konunca kapasite ya da işaret yorumu değişir.
  - Aynı tipte birden fazla değişken tek bildirimde virgülle tanımlanabilir: `int j, k;`.
  - Slayttaki kural: bir bloktaki bütün bildirimler çalıştırılabilir komutlardan önce gelmelidir.
- Tam sayı tipleri, boyutlar ve format belirteçleri
  - ANSI standardı byte için en az 8 bit, `int` için en az 16 bit ister; "tam 4 byte" demez. Yaygın platformlarda `int` 4 byte'tır.
  - İşaretli sayılarda en soldaki bit işaret biti olur; bu yüzden aynı bit sayısıyla ulaşılabilen en büyük pozitif değer yarıya iner.
  - Format belirteçleri: `%d` (int), `%u` (unsigned int), `%hi` (short), `%li` (long), `%hu` (unsigned short), `%lu` (unsigned long), `%c` (char), `%f`, `%lf`, `%e` (bilimsel gösterim).
  - `short` için harf `h`, `long` için `l` kullanılır.
  - `char` 1 byte'tır ve içinde sayı saklanabilir: 65 sayısı `%c` ile yazdırılınca ASCII karşılığı olan `A` çıkar.
- Format belirteci denemesi (Dev-C++ 4 üzerinde, ekrandan, 00:25:00 ve 00:30:00)
  - `int sayi = 65` farklı belirteçlerle yazdırıldığında hepsi 65, `%c` ile `A` çıktı.
  - `sayi = -65` iken `%u` ile yazdırılınca işaret biti de sayının parçası sayıldığından 4,2 milyar civarında bir değer çıktı.
  - `sayi = 659999` iken `%hi` ve `%hu` 4639 verdi: sayı 16 bitlik `short` alana sığmadığı için üst bitler kesildi.
  - `float ondalikli = 7000000.555` değeri `%f` ile `7000000.500000` olarak göründü; `float` bu kadar büyük bir sayının küsuratını tutamıyor. `%.3f` noktadan sonra 3 basamak gösterir.
- Sekizlik ve on altılık tam sayı sabitleri (ekrandan, 00:35:00)
  - Sekizlik sabit `0` ile, on altılık sabit `0x` ile başlar: 8 = `010` = `0x8`, 15 = `017` = `0xF`, 255 = `0377` = `0xFF`.
  - Negatif sabitte eksi işareti öne yazılır: -87 = `-0127` = `-0x57`.
  - Son ekler: `u`/`U` unsigned, `l`/`L` long anlamına gelir.
- Ondalıklı sayılar ve ilk değer atama
  - `float` tek, `double` çift hassasiyetlidir. Hassas mühendislik ve bilim hesaplarında `double` tercih edilir.
  - İlk değer atanmamış bir değişkenin değeri belirsizdir: bellekte o gözde ne kaldıysa odur. Sayaç ve toplam gibi değişkenlere mutlaka ilk değer verilir.
  - Tanımla birlikte değer atanabilir: `char ch = 'A';`.
- Tip karıştırma ve dönüşümler
  - Küçük kaptan büyük kaba (`int` → `long`, `int` → `float`) dönüşüm güvenlidir. Büyükten küçüğe dönüşümde veri kaybı olur.
  - Örtük dönüşüm (ekrandan, 00:50:00): `int j; float f;` için `j + f` ifadesinde `j` float'a çevrilir, `j + f + 2.5` ifadesinde ikisi de double'a çevrilir.
  - Hassasiyet kaybı: `j = 2.5;` atamasında `j` 2 olur; çok büyük bir ondalıklı sayı atanırsa taşma (overflow) olur.
  - Açık dönüşüm (cast) (ekrandan, 01:05:00): `int j=2, k=3; float f; f = k / j;` tam sayı bölmesi yapar; `f = (float) k / j;` ile sonuç 1.5 olur.
- `enum` ve `typedef`
  - `enum` adlandırılmış sabitler kümesidir; değişken yalnız o kümedeki değerleri alabilmelidir (giysi bedeni, renk gibi).
  - Slayttaki örnek (ekrandan, 01:10:00): `enum { red, blue, green, yellow } color;` ve `enum { bright, medium, dark } intensity;`. `color = yellow` geçerli, `color = bright` tip çatışması olarak gösterilmiştir.
  - Varsayılan değerler sıfırdan başlar ve birer artar; istenirse başka değer verilebilir.
  - `#define` ile sabit tanımlamak yerine `enum` kullanmak, farklı kümelerin değerlerinin karışmasını önler.
  - `typedef` bir tipe yeni ad verir: `typedef long int INT32;` sonrası `INT32 j;` yazılabilir. Gelenek olarak bu adlar büyük harfle yazılır (ekrandan, 01:15:00).
- İfadeler ve operatör önceliği
  - İfade türleri (ekrandan, 01:20:00): sabit (`5 + 6 * 13 / 3.0`), tam sayı (`j / k * 3`, `k - 'a'`, `3 + (int) 5.0`), ondalıklı (`x / y * 5`, `3 + (float) 4`), işaretçi (`p`, `p + 1`, `"abc"`).
  - Öncelik tablosu (ekrandan, 01:25:00): birincil `() [] -> .`; tekli `cast`, `sizeof`, `&`, `*`, `- +`, `~ ++ -- !` (sağdan sola); çarpımsal `* / %`; toplamsal `+ -`; kaydırma `<< >>`; ilişkisel `< <= > >=`; eşitlik `== !=`.
  - Parantez her şeyden önce gelir; iç içe parantezde en içteki önce hesaplanır: `1 + (((3 + 1) / (8 - 4)) - 5) = -3`.
  - `a < b < c` gibi bir zincir, `(a < b)` sonucunun (0 ya da 1) `c` ile karşılaştırılması demektir; doğrusu `a < b && b < c`.
- Atama, artırma ve azaltma operatörleri
  - `a += b`, `a -= b`, `a *= b`, `a /= b`, `a %= b` (ekrandan, 01:30:00).
  - `m += n + x - y` ifadesi `m = m + ((n + x) - y)` olarak değerlendirilir.
  - Ön ek (`++j`) önce artırır sonra değeri kullanır; son ek (`j++`) önce değeri kullanır sonra artırır (ekrandan, 01:35:00).
- Virgül operatörü (ekrandan, 01:40:00)
  - Tek ifade beklenen yerde birden fazla ifade yazmayı sağlar: `for (j = 0, k = 100; k - j > 0; j++, k--)`. Sonuç en sağdaki işlenenin değeridir.
- İlişkisel ve mantıksal operatörler
  - İlişkisel ifadenin sonucu doğruysa 1, yanlışsa 0'dır.
  - Mantıksal işlemlerde 0 (ve 0.0) yanlış, sıfır olmayan her değer (negatifler dahil) doğru sayılır. Derste slayttaki bu cümlenin yanlış yazıldığı fark edildi ve `0 || -1` ifadesinin 1 verdiği çalıştırılarak gösterildi.
- Bit operatörleri
  - `&&` mantıksal VE, `&` bit düzeyinde VE'dir. Derste 9 (`1001`) ile 6 (`0110`) için `9 & 6 = 0`, `9 && 6 = 1` gösterildi.
  - `|`, `^` (XOR), `~` (NOT), `<<`, `>>` diğer bit operatörleridir; hepsinin `<<=`, `&=` gibi kısaltmaları vardır.
  - Kaydırma örnekleri (ekrandan, 01:55:00): `5 << 1 = 10`, `255 >> 3 = 31`, 16 bitte `8 << 10 = 2^13`, `1 << 15 = -2^15`.
  - Sola kaydırma 2'nin kuvvetiyle çarpmadır. Sağa kaydırma bölmeye benzer ama özellikle negatif ve tek sayılarda tam bölme değildir.
- `cast` ve `sizeof` (ekrandan, 02:10:00)
  - `cast`, `3 / 2` gibi bir bölmenin kesilmemesi için kullanılabilir: `(float) 3 / 2`.
  - `sizeof` bir ifade ya da tip alır ve byte cinsinden boyutu döndürür. Slayta göre `sizeof(3+5)` int boyutunu döndürür; işlenen fonksiyon tipi, `void` ya da bit alanı olamaz.
- Koşul operatörü ve bellek operatörleri
  - `z = ((x < y) ? x : y);` ifadesi `if (x < y) z = x; else z = y;` ile aynıdır; C'deki tek üçlü operatördür (ekrandan, 02:15:00).
  - `&a` değişkenin adresini, işaretçi `p` için `*p` gösterilen adresteki değeri verir. Ayrıntısı işaretçiler konusunda görülecek.
- Kontrol deyimleri
  - `if`, `else if`, `else` zinciri; süslü parantez yoksa `if` yalnız bir sonraki tek komutu bağlar.
  - Asılı else (dangling else) problemi (ekrandan, 02:20:00): `else` her zaman en yakın, eşleşmemiş önceki `if`'e aittir. Girinti derleyici için anlam taşımaz.
  - `switch-case`: etiketler tam sayı ya da karakter olmalı, iki etiket aynı değeri taşıyamaz; `break` konmazsa sonraki case'ler de çalışır (ekrandan, 02:25:00).
  - `while` döngüsüne hiç girilmeyebilir; `do-while` gövdesi en az bir kez çalışır.
  - Boş komut (`;`) bir koşulda hiçbir şey yapılmayacağını gösterir ama yanlış yerde sonsuz döngüye yol açabilir.
  - İç içe döngülerde iç döngü daha sık döner; `break` yalnız içinde bulunduğu tek döngüden çıkar.

## Hocanın Özellikle Vurguladığı Kısımlar

- C alt düzey bir dildir; çalışılan platformun ayrıntılarını bilmek gerekir.
  - Tip boyutları, bölmenin sonucu, `char`'ın işaretli olup olmadığı gibi konular standarttan ve derleyiciden derleyiciye değişebilir. Bu yüzden şüpheci olmak ve kodu deneyerek sınamak gerekir.
- Yanlış format belirteci yanlış sonuç verir.
  - Negatif bir sayıyı `%u` ile basmak ya da büyük bir sayıyı `%hi` ile basmak anlamsız değerler üretir.
- Karmaşık ve öncelik kurallarına dayanan ifadeler yazılmamalı.
  - `a = b = c`, `x += y -= m`, `m++ - --c` gibi ifadeler hem okunmaz hem de bazıları derleyiciye bağlı (implementation dependent) sonuç verir. Bunlar birkaç ayrı komuta bölünmeli ya da parantezle açıkça yazılmalı.
- Mantıksal ve sayısal ifadeler karıştırılmamalı.
  - İlişkisel sonucu sayı gibi kullanmak mümkün olsa da tavsiye edilmez.
- Süslü parantez kullanılmalı.
  - Asılı else ve `for`/`if` içindeki komutların hangi koşula bağlı olduğu karmaşası süslü parantezle ortadan kalkar.
- `goto` ve `continue` kullanılmamalı.
  - Hocaya göre bunlar spagetti koda yol açar ve yapısal akışı izlemeyi zorlaştırır. `break` ise `switch` ve döngülerde kullanılır.
- İlk değer atanmamış değişkene güvenilmez.
  - Sayaç ve birikimli toplam gibi değişkenlere mutlaka ilk değer verilmelidir.

## Kısa Tekrar Notları

- Skaler tip ayrılmış kelimeleri: `char int float double enum` + `long short signed unsigned`.
- `int` en az 16 bit; yaygın platformlarda 4 byte. `%d %u %hi %hu %li %lu %c %f %lf %e`.
- 65 → `%c` ile `A`. `-65` → `%u` ile 4294967231 (32 bit int'te).
- Sekizlik `0...`, on altılık `0x...`; `u` unsigned, `l` long son eki.
- Küçük kaptan büyüğe dönüşüm güvenli, büyükten küçüğe veri kaybı.
- `int / int` tam sayı bölmesidir; `(float) k / j` ondalıklı bölme yapar.
- `enum` farklı kümelerin değerlerinin karışmasını önler; `typedef long int INT32;`.
- Öncelik: `() [] -> .` > tekli > `* / %` > `+ -` > `<< >>` > ilişkisel > eşitlik > bit ops > `&&` > `||` > `?:` > atama > virgül.
- `j++` önce kullan sonra artır; `++j` önce artır sonra kullan.
- İlişkisel sonuç 1/0; mantıkta sıfır olmayan her değer doğru.
- `&` bit VE, `&&` mantıksal VE: `9 & 6 = 0`, `9 && 6 = 1`.
- `5 << 1 = 10`, `255 >> 3 = 31`.
- `else` en yakın eşleşmemiş `if`'e aittir.
- `switch` içinde `break` yoksa alttaki case'ler de çalışır.
- `do-while` en az bir kez çalışır; `break` yalnız bir düzey döngüden çıkar.

## Detaylı Açıklamalar

- **Veri tipleri ve platform bağımlılığı.** C'de her değişkenin tipi baştan yazılır. Skaler tipler beş temel tipten (`char`, `int`, `float`, `double`, `enum`) ve onların önüne konabilen dört niteleyiciden (`long`, `short`, `signed`, `unsigned`) oluşur. ANSI standardı byte'ın en az 8 bit, `int`'in en az 16 bit olmasını ister. Hoca önce `int`'i 2 byte olarak andı, sonra slayttaki tabloya bakarak yaygın platformlarda 4 byte olduğunu düzeltti. 4 byte'lık işaretsiz bir tam sayı $0$ ile $2^{32}-1$ arasında, işaretli bir tam sayı $-2^{31}$ ile $2^{31}-1$ arasında değer alır, çünkü işaretli gösterimde bir bit işarete ayrılır.

  > **Ders sonrası not:** Altyazıda 1 byte'lık aralıklar bozuk geçiyor ("258 eksi bir", "7 byte"). Doğrusu: 1 byte = 8 bittir; işaretsiz aralık $0$ ile $255$ arasıdır. İşaretli aralık iki tümleyen gösteriminde $-128$ ile $127$ arasıdır ve işaret biti ayrıldıktan sonra kalan 7 bittir.

- **Format belirteci denemesi.** Hoca Dev-C++ 4'te aşağıdaki programı yazıp çalıştırdı (ekrandan, 00:25:00). Ekranda dosya 23 satırdı. Burada görünen satırlar, hocanın sonradan düzelttiği `%lu` satırı ve onun denediği `%.3f` satırı verilmiştir. Kapanış satırı eklendi. Program `gcc -Wall` ile derlendi ve çalıştırıldı. Derleyici `%li` ve `%lu` satırları için "int verilmiş, long bekleniyor" uyarısı verir. Bu uyarı, hocanın vurguladığı "uygun olmayan format belirteci" konusunun ta kendisidir.

  ```c
  #include <stdio.h>
  #include <stdlib.h>

  int main(int argc, char *argv[]){
      int sayi = 65;
      float ondalikli = 7000000.555;
      printf("     int \t%d\n",sayi);
      printf(" uns.int \t%u\n",sayi);
      printf(" srt.int \t%hi\n",sayi);
      printf(" lng.int \t%li\n",sayi);
      printf("usrt.int \t%hu\n",sayi);
      printf("ulng.int \t%lu\n",sayi);
      printf("     char\t%c\n",sayi);
      printf("\n");
      printf("     dbl \t%f\n",ondalikli);
      printf("     dbl \t%.3f\n",ondalikli);
      printf(" lng.dbl \t%lf\n",ondalikli);
      printf("     exp \t%e\n",ondalikli);
      return 0;
  }
  ```

  `sayi = 65` için ilk altı satır 65, `char` satırı `A` basar. Hoca ekranda `%ul` yazdığında çıktının sonuna bir `l` harfi eklendiğini gördü. Bunun nedeni, `%u`'nun belirteç olarak okunması ve `l`'nin düz metin olarak basılmasıdır; doğrusu `%lu`'dur. `sayi = 659999` yapıldığında `%hi` ve `%hu` 4639 bastı (ekrandan, 00:30:00): $659999 - 10 \cdot 65536 = 4639$, yani yalnız alttaki 16 bit kaldı. `float` yaklaşık 7 anlamlı basamak tuttuğu için `7000000.555` değeri `7000000.500000` olarak saklandı.

  > **Ders sonrası not:** Hoca `short` alana sığmama durumunu "buffer overflow" diye andı. Buradaki olay tam sayı taşması ya da kesilmedir; tampon taşması (buffer overflow) bir dizinin sınırının dışına yazmak anlamına gelir.

- **İşaretsiz aritmetik.** Hoca `unsigned int i = 10;` tanımlayıp `i - 15` sonucunu yazdırdı. `%d` ile -5 göründü, `%u` ile 4294967291 göründü. Sonuç hem kullanılan format belirtecine hem de atandığı değişkenin tipine göre farklı yorumlanır. Aynı şekilde `-65` değeri `%u` ile 4294967231 olarak basılır, çünkü işaret biti de sayının bir basamağı gibi okunur.

- **Örtük ve açık dönüşüm.** Karışık tipli bir ifadede sonuç "en geniş kap" tipinde hesaplanır: `int + float` float, `int + float + double` double olur. Ondalıklı bir değer `int` değişkene atanırsa küsurat atılır (`j = 2.5` → 2). Tam sayı kısmı da `int`'e sığmayacak kadar büyükse taşma olur. Taşınabilir ve niyeti açık kod için açık dönüşüm (cast) yazılır: `f = (float) k / j;`. Hoca, cast'in yalnız `k`'yi mi yoksa bölmeyi mi etkilediği konusunda emin olunamıyorsa parantez eklenmesini önerdi. Öncelik tablosuna göre cast tekli bir operatördür ve bölmeden önce uygulanır; yani `(float) k / j` önce `k`'yi float yapar, sonra bölme ondalıklı yapılır (gcc ile denendi: `k / j` → 1.000000, `(float) k / j` → 1.500000).

  > **Ders sonrası not:** Hoca 00:42:58 civarında "bölme işleminin sonucu her zaman ondalıklı olarak yorumlanır" dedi. 01:19:38'de de `j / k * 3` için "sonuç ondalıklı çıkar" dedi. C'de iki tam sayının bölümü tam sayıdır ve küsurat atılır (`3 / 2 == 1`). Slaytta da `j / k * 3` "Integral expressions" başlığı altındadır.

- **`enum` ile tip güvenliği.** `#define RED 1` ve `#define BRIGHT 1` gibi sabitler tanımlanırsa `color` değişkenine yanlışlıkla `BRIGHT` atanabilir ve mantık hatası olur. `enum` ile her kümeye ayrı değerler verilir. Slaytta `color = bright;`, `intensity = blue;` ve `color = 1;` atamaları "Type conflict" olarak, `color = green + blue;` ise "Misleading usage" olarak gösterildi.

  > **Ders sonrası not:** C'de `enum` sabitleri `int` gibi davranır. `gcc -Wall` ile denendiğinde `color = bright;` ve `intensity = blue;` hatasız ve uyarısız derlendi. Slayttaki "Type conflict" uyarısı büyük olasılıkla C++ derleyicileri ya da ek denetim araçları için geçerlidir; C'de bu güvenlik programcının dikkatine kalır.

- **Bit operatörleri ve kaydırma.** `&` iki sayının aynı basamaktaki bitlerini tek tek VE'ler; `&&` ise iki değeri doğru/yanlış olarak değerlendirir. Hoca Excel'de 9'u `1001` olarak yazdı (ekrandan, 01:50:00). Önce 5 (`0101`) ile denedi, `9 & 5 = 1` çıktı. Sonra ikinci sayıyı 6 (`0110`) yaptı: `9 & 6 = 0` ama `9 && 6 = 1`. Sola kaydırmada sağdan 0 gelir; `5 << 1` için `101` → `1010` = 10. `255 >> 3` için sağdaki üç bit düşer: `11111111` → `00011111` = 31.

  > **Ders sonrası not:** Hoca 01:57:15'te "5'i 1 bit sağa ötelediğinizde 2 ile çarpmış olursunuz" dedi. Doğrusu sola kaydırmadır; sağa kaydırma bölmeye karşılık gelir. Hocanın kendisi de cümlenin devamında sola kaydırmayı çarpma, sağa kaydırmayı bölme olarak anlattı.

  > **Ders sonrası not:** Slayttaki `-5 >> 2` satırlarında yazım hatası olduğunu hoca da söyledi (ekrandan, 01:55:00). 16 bitte $-5$ = `11111111 11111011` olur. gcc'de işaretli sayının sağa kaydırılması işaret bitini çoğaltır ve sonuç $-2$ olur. Aynı bit dizisi işaretsiz kaydırılırsa `00111111 11111110` = 16382 = $2^{14}-2$ çıkar. Slayttaki "$2^{13}-1$" değeri bu bit dizisiyle uyuşmuyor. İşaretli negatif sayıyı sağa kaydırmanın sonucu C standardında derleyiciye bırakılmıştır.

- **`sizeof`.** `sizeof` byte cinsinden boyut döndürür. Slayta göre `sizeof(3+5)` int boyutunu verir.

  > **Ders sonrası not:** Hoca `sizeof(3+5)` için "8 sayısını tutabilecek en küçük kap short'tur, o da 1 byte'tır" biçiminde bir açıklama yaptı. Doğrusu slayttaki gibidir: `3+5` bir `int` ifadesidir ve `sizeof(3+5) == sizeof(int)`. Bu değer gcc/x86-64'te 4'tür. `short` da genellikle 2 byte'tır, 1 byte değil (gcc ile denendi).

- **Asılı else.** Slayttaki örnekte (ekrandan, 02:20:00):

  ```c
  if (a < b)
      if (a < c)
          return a;
      else
          return c;
  else if (b < c)
      return b;
  else
      return c;
  ```

  İlk `else` en yakın `if (a < c)`'ye aittir. `else if (b < c)` ise dıştaki `if (a < b)`'nin `else`'idir. Kod üç sayının en küçüğünü döndürür. Girinti yalnız okuyan içindir; anlamı süslü parantezler belirler.

- **`break` iç içe döngüde.** `break` yalnız içinde bulunduğu döngüden çıkar; dış döngü devam eder.

  > **Ders sonrası not:** Hoca iç döngüye `if (k == 3) break;` koyunca "k=3 atlanır, 4-10 işlenir" dedi. Bu `continue`'nun davranışıdır. `break` ile iç döngü k=3'te tamamen biter, yani her `j` için yalnız k=1 ve k=2 işlenir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
