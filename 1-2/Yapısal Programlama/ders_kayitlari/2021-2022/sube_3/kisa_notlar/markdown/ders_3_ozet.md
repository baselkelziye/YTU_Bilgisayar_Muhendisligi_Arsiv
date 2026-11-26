# Ders 3 Çalışma Özeti

## Genel Konular

- İfade türleri (ekrandan, 00:15:00)
  - Sabit ifadeler: `5`, `5 + 6 * 13 / 3.0`.
  - Tam sayı ifadeleri (`int j, k`): `j`, `j / k * 3`, `k - 'a'`, `3 + (int) 5.0`.
  - Ondalıklı ifadeler (`double x, y`): `x / y * 5`, `3 + (float) 4`.
  - İşaretçi ifadeleri (`int *p`): `p`, `p + 1`, `"abc"`. Bunlar ileride işaretçiler konusunda görülecek.
  - Karakter sabiti tek tırnakla yazılır ve arka planda ASCII koduyla bir sayıdır; bu yüzden `k - 'a'` bir tam sayı ifadesidir.
  - `3 + (int) 5.0` ifadesinde cast yüzünden toplama tam sayı olarak yapılır. Tam sayı değişkene ondalıklı değer atanırken de küsurat atılır.
- Zincirleme karşılaştırma ve atama hatası (ekrandan, 00:20:00)
  - `a < b < c` matematikteki anlamıyla çalışmaz: önce `a < b` hesaplanır, sonuç 1 ya da 0 olur, sonra bu değer `c` ile karşılaştırılır.
  - `int a = 3, b = 9, c = 7;` için `b < c` yanlış olduğu halde `a < b < c` "Evet" verdi; çünkü `(3 < 9)` 1'dir ve `1 < 7` doğrudur.
  - Doğrusu `a < b && b < c` biçiminde ikiye bölmektir. Bu biçim "Hayir" verir.
  - Aynı şekilde `a = b = c` yerine `b = c; a = b;` yazılması önerildi.
- Operatör önceliği tablosu
  - Yukarıdan aşağı öncelik azalır. Çarpma, bölme ve mod toplama/çıkarmadan önce gelir. Aynı öncelikteki işlemler soldan sağa değerlendirilir.
  - Sırayla (alt kısımlar): kaydırma `<<`, `>>`; ilişkisel `<`, `<=`, `>`, `>=`; eşitlik `==`, `!=`; bitsel `&`, `^`, `|`; mantıksal `&&`, `||`; koşul operatörü `?:`; atama operatörleri; en altta virgül.
  - Öncelik parantezle değiştirilir. İç içe parantezlerde en içteki, aynı düzeyde birden çok parantez varsa en soldaki önce hesaplanır.
  - Örnek: `2 - 3 * 4` önce çarpmayı yapar ($2 - 12 = -10$); `(2 - 3) * 4` önce çıkarmayı yapar.
- Bit kaydırma operatörleri
  - `<<` sola, `>>` sağa bit kaydırır. Sola kaydırmada en soldaki bit düşer, sağdan 0 gelir.
  - `9` = `00001001`. `9 << 1` = `00010010` = 18, `9 >> 1` = `00000100` = 4 (ekrandan, 00:25:00).
  - Bir bit sola kaydırmak 2 ile çarpmak, bir bit sağa kaydırmak (çift sayılarda) 2'ye bölmek gibidir. Hoca yine de çarpma/bölme için normal operatörlerin kullanılmasını önerdi.
  - Negatif sayıyı sağa kaydırınca işaret korunur: `-9 >> 1` sonucu -5 çıktı. Slayttaki örnek: `-5 >> 2` = -2 (ekrandan, 01:25:00). Derleyici soldan, en soldaki bitin değeriyle besliyor.
  - Slayt tablosu (16 bit): `5 << 1` = 10, `255 >> 3` = 31, `8 << 10` = $2^{13}$, `1 << 15` = $-2^{15}$, `5 >> 2` = 1 (ekrandan, 01:25:00).
- Bitsel `&`, `|`, `^`, `~` (ekrandan, 01:30:00)
  - Tek `&` ve tek `|` bitsel, çift `&&` ve `||` mantıksal işlemdir.
  - `9430` = `0x24D6`, `5722` = `0x165A`.
  - `9430 & 5722` = `0x0452` = 1106; `9430 | 5722` = `0x36DE` = 14046.
  - XOR (`^`): iki bit aynıysa 0, farklıysa 1. `9430 ^ 5722` = 12940.
  - `~` bütün bitleri tersine çevirir: `~9430` = -9431.
  - `<<=`, `>>=`, `&=` gibi bileşik atamalar da vardır.
- Koşul operatörü `?:`
  - `c = (a > b) ? 1 : 0;` ile `if (a > b) c = 1; else c = 0;` aynıdır.
  - Hoca bu operatörün okunmasının zor olduğunu, `if-else` biçiminin tercih edilmesini söyledi.
- Aritmetik atama operatörleri (ekrandan, 00:40:00)
  - `a += b` → `a = a + b`; aynı şekilde `-=`, `*=`, `/=`, `%=`.
  - `m = 3, n = 4, x = 2.5, y = 1.0` için `m += n + x - y` → $3 + 5.5 = 8.5$, `m` tam sayı olduğu için 8 olur.
  - `m /= x * n + 1` → $3 / 11 \approx 0.27$, `m` tam sayı olduğu için 0 olur. <!-- BELİRSİZ: slayt karesi yok; ifadeler ve değerler hocanın anlatımından kuruldu, toplanan 1 slaytta `y` olabilir. -->
  - `%` (mod) tam sayılar içindir.
- Artırma ve azaltma operatörleri
  - Son ek (`j++`): önce değeri kullan, sonra artır. Ön ek (`++j`): önce artır, sonra kullan.
  - `int j=5, k=5; printf(..., j++, k--);` 5 ve 5 yazar, sonraki satırda 6 ve 4 görülür (ekrandan, 00:45:00).
  - Slayt örnekleri, `int j = 0, m = 1, n = -1;` için (ekrandan, 00:50:00):
    - `m++ - --j` → `(m++) - (--j)` → $1 - (-1) = 2$. Sonra `m` 2, `j` -1 olur.
    - `m += ++j * 2` → `m = (m + ((++j) * 2))` → $1 + 1 \cdot 2 = 3$.
    - `m++ * m++`: sonucu derleyiciye bağlıdır. Derste kullanılan derleyici $1 \cdot 1 = 1$ verdi.
  - `m+++--j` gibi boşluksuz yazım derleme hatası (invalid lvalue) verdi; `--` ile `-` arasında boşluk gerekir.
- Virgül operatörü
  - Tek ifade beklenen yere birden fazla ifade yazmaya izin verir. Tipik kullanım `for` döngüsünün ilk ve son kısmıdır.
- İlişkisel ve mantıksal operatörler (ekrandan, 01:20:00)
  - Doğru 1, yanlış 0 olarak değerlendirilir. Sıfır olmayan her değer (ör. 2.5) doğru sayılır. `!` tek operatörlüdür.
  - `int j=0, m=1, n=-1; float x=2.5, y=0.0;` için: `j > m` → 0; `m/n < x` → 1; `j <= m >= n` → `((j <= m) >= n)` → 1; `++j == m != y * 2` → `((++j) == m) != (y * 2)` → 1.
- `cast` ve `sizeof` (ekrandan, 01:35:00)
  - `3 / 2` tam sayı bölmesidir ve 1 verir; sonuç `float` değişkene atansa da küsurat önce kaybolur.
  - `(float) 3 / 2` ya da `3 / (float) 2` 1.5 verir. İşlenenlerden birini çevirmek yeter.
  - `(float)(b / 2)` yine 1 verir; çünkü bölme önce tam sayı olarak yapılır (ekrandan, 01:40:00).
  - `sizeof` bir veri tipinin ya da ifadenin bellekte kaç byte tuttuğunu verir: `sizeof(3+4)` int boyutunu verir. Derste `int` 4, `short` 2, `long` 4 byte çıktı.
- Kontrol deyimleri hatırlatması
  - `if-else`, iç içe `if` ve "sallanan else" (dangling else): `else` her zaman en yakın önceki `if`'e bağlanır (ekrandan, 01:45:00). Girinti derleyici için anlamsızdır; süslü parantez kullanılmalıdır.
  - `switch-case`: tek bir değişkenin ayrık değerlerine göre dallanır. `break` yoksa girilen `case`'ten sonrakiler de çalışır (fall-through). Aralık koşulu yalnız `if` ile yazılır.
  - `while` koşulu her yinelemenin başında, `do-while` sonunda denetler; `do-while` en az bir kez çalışır.
  - `for` üç kısmı noktalı virgülle ayrılır; herhangi biri boş bırakılabilir. Koşul boş bırakılırsa sonsuz döngü olur, koşula 0 yazılırsa döngüye hiç girilmez.
  - Null statement: `if (j == 1);` koşuldan sonra konan noktalı virgül boş komut çalıştırır (ekrandan, 02:15:00).
  - `break` yalnız içinde bulunduğu döngüden çıkar; dış döngülerden çıkmak için bayrak değişkeni kullanılır.
- Önişlemci ve makrolar
  - `#` ile başlayan komutlar derlemeden önce, kaynak kodun bellekteki kopyası üzerinde işlenir. `.c` dosyası değişmez.
  - Önişlemcinin işleri: makro tanımlama, koşullu derleme, dosya ekleme (`#include`), satır denetimi.
  - Makro, tanımın kodda geçtiği her yere metin olarak yapıştırılmasıdır. Sonuna `;` konmaz, tanımda `=` kullanılmaz, uzun makro `\` ile alt satıra geçer. Makro adları gelenek olarak büyük harfle yazılır.
  - Sabit tanımı: `#define BUFF_LEN 512` değerin tek yerden değişmesini sağlar ve değişken gibi bellek harcamaz.
  - Fonksiyon benzeri makrolar (ekrandan, 02:30:00): `#define MUL_BY_TWO(a) ((a) + (a))`, `#define min(a, b) ( (a) < (b) ? (a) : (b))`.
  - `#undef` ile makro kaldırılıp yeniden tanımlanabilir (ekrandan, 02:50:00).
  - Hazır makrolar: `__LINE__`, `__FILE__`, `__TIME__`, `__DATE__`, `__STDC__`.

## Hocanın Özellikle Vurguladığı Kısımlar

- Zincirleme karşılaştırma ve zincirleme atama yazılmamalı
  - `a < b < c` bazen doğru, bazen yanlış sonuç verir. Bu yüzden `a < b && b < c` yazılmalıdır.
- Kâğıda yazarken `<=` ve `>=` iki karakterle yazılmalı
  - Matematikteki tek karakterli küçük-eşit simgesi klavyede yoktur; C'de `<=` ve `>=` kullanılır.
- Karmaşık artırma/azaltma ifadelerinden kaçınılmalı
  - `m++ * m++` gibi ifadelerin sonucu derleyiciye bağlıdır. Bu ifadeler yalnız nasıl değerlendirildiğini anlamak için incelendi.
- Kaydırma operatörleri matematik için değil bit işlemleri içindir
  - Negatif sayılarda beklenmedik sonuçlar çıkabilir.
- Cast'te bütün ifadeyi değil, işlenenlerden birini çevirmek gerekir
  - `(float)(b / 2)` işe yaramaz; `(float) b / 2` doğru kullanımdır.
- İç içe yapılarda süslü parantez şarttır
  - `else` en yakın `if`'e bağlanır; girinti bunu değiştirmez.
- `switch`'te `break` unutulmamalı
  - `break` olmazsa akış sonraki `case`'lere taşar.
- `continue` ve null statement önerilmez, `goto` kesinlikle kullanılmaz
  - `goto` program akışını izlenemez bir yumağa çevirir.
- Makroların tip denetimi yoktur ve yan etkileri olabilir
  - `MIN(x++, y)` makrosu `x++`'ı iki kez yazar; fonksiyon ise bir kez değerlendirir.

## Kısa Tekrar Notları

- `a < b < c` → `(a < b) < c`; doğrusu `a < b && b < c`.
- `9 << 1` = 18, `9 >> 1` = 4, `-9 >> 1` = -5.
- `&`, `|`, `^`, `~` bitsel; `&&`, `||`, `!` mantıksal.
- `9430 & 5722` = 1106, `9430 | 5722` = 14046, `9430 ^ 5722` = 12940, `~9430` = -9431.
- `?:`: `koşul ? değer1 : değer2`.
- `j++` önce kullan sonra artır; `++j` önce artır sonra kullan.
- `3 / 2` = 1; `(float) 3 / 2` = 1.5; `(float)(3 / 2)` = 1.
- `sizeof` byte sayısı verir.
- `else` en yakın `if`'e aittir.
- `switch`'te `break` yoksa sonraki `case`'ler de çalışır.
- `for(;;)` sonsuz döngüdür; `if (j == 1);` boş komuttur.
- Makro metin yapıştırmadır: `;` ve `=` yok, tip denetimi yok, yan etki riski var, fonksiyon çağrısı maliyeti yok, kodu büyütür.
- `#undef` makroyu kaldırır; `__LINE__`, `__FILE__`, `__DATE__`, `__TIME__`, `__STDC__` hazır makrolardır.

## Detaylı Açıklamalar

- Zincirleme karşılaştırma denemesi (ekrandan, 00:20:00)
  - Derste yazılan kod:

    ```c
    #include <stdio.h>

    int main(int argc, char *argv[])
    {
        int a = 3, b = 9, c = 7;
        if( a < b  < c )
            printf("Evet");
        else
            printf("Hayir");
        system("PAUSE");
        return 0;
    }
    ```

  - `b < c` yanlış olduğu halde çıktı "Evet" oldu. Bir öğrencinin belirttiği gibi bu şans değildir: `a < b` 1 verir ve `1 < 7` doğrudur. Koşul `a < b && b < c` yapılınca "Hayir" çıktı.
  - Not hazırlanırken kod `system("PAUSE")` satırı çıkarılarak `gcc -Wall` ile derlendi; gcc bu satır için "comparisons like X<=Y<=Z do not have their mathematical meaning" uyarısı verdi.
- Belirli bir biti bulma denemesi (ekrandan, 00:30:00)
  - Amaç, bir sayının 8 değerli bitinin (sağdan 4. bit) 1 mi 0 mı olduğunu bulmaktı. Hoca önce `a = b >> 3; a = a << 3;` gibi kaydırmalar ve `|` ile denedi. `b = 6` için yanlış sonuç çıkınca bir öğrencinin uyarısıyla `|` yerine `&` kullanılması gerektiği anlaşıldı.
  - <!-- BELİRSİZ: kodun derste ulaşılan son hali karelerde görünmüyor; hoca konuyu tamamlamadan geçti. -->
  - Not hazırlanırken denenen kısa yol (derste yazılmadı, ajan tarafından gcc ile test edildi): `(b >> 3) & 1`. `b = 9` için 1, `b = 6` için 0 verir.
- Artırma/azaltma denemeleri (ekrandan, 00:45:00 ve 00:55:00)
  - `printf("j: %d\t k : %d\n", j++, k--);` satırı 5 ve 5 yazdı; sonraki `printf` 6 ve 4 yazdı. Ön ek biçiminde ise ilk satırda da 6 ve 4 göründü.
  - `s = m++- --j;` ile `j = 0, m = 1` için `s = 2`, `m = 2`, `j = -1` çıktı. Hoca önce 0 beklemişti; `1 - (-1)` olduğu için doğru sonuç 2'dir.
  - `m++ * m++` denemesinde sonuç 1, `m` ise 3 çıktı. Hoca farklı derleyicilerin farklı sonuç verebileceğini söyledi.
- cast denemesi (ekrandan, 01:40:00)
  - `float a; int b = 3;` için `a = b / 2;` → 1.000000, `a = (float) b / 2;` → 1.500000, `a = b / (float) 2;` → 1.500000, `a = (float)(b / 2);` → 1.000000. Sonuçlar not hazırlanırken gcc ile doğrulandı.
- `if-else if` ile `switch` karşılaştırması (ekrandan, 01:55:00)
  - Kullanıcıdan `scanf("%d", &a)` ile okunan değer için `if (a == 0) ... else if (a == 1) ... else if (a == 2) ... else ...` zinciri ile aynı işi yapan `switch (a) { case 0: ... break; case 1: ... break; case 2: ... break; default: ... }` yazıldı; ikisi aynı çıktıyı verdi.
  - `break`'ler silinince 0 girildiğinde `case 0`'dan başlayıp `default` dahil hepsi çalıştı.
- Makro ve fonksiyon farkı (ekrandan, 02:35:00 ve 02:45:00)
  - `#define MIN(a, b) ( (a) < (b) ? (a) : (b))` makrosu `MIN(5, 7)` için 5, `MIN(15, 7)` için 7 verdi.
  - Makroya iki dizgi (string) verilince derleme hatası çıkmadı, anlamsız bir sayı yazıldı: karşılaştırılan şey dizgilerin bellekteki adresleriydi. Aynı çağrı `int min(int a, int b)` fonksiyonuyla yapılınca derleyici tip uyuşmazlığı uyarısı verdi.
  - Yan etki: `MIN(x++, y)` önişlemciden sonra `((x++) < (y) ? (x++) : (y))` olur (ekrandan, 02:40:00). `x = 6, y = 7, i = 6, j = 7` için `a = MIN(x++, y)` 7, `b = min(i++, j)` 6 verdi. Bir öğrencinin önerdiği bu değerlerle fark görüldü. Kod not hazırlanırken gcc ile derlenip çalıştırıldı ve aynı sonuç alındı.
- Makroların artı ve eksileri
  - Artı: fonksiyon çağrısı maliyeti yoktur, tipten bağımsız çalışır.
  - Eksi: tip denetimi yoktur, yan etki olabilir, kod her kullanımda yapıştırıldığı için çalıştırılabilir dosya büyür, hata ayıklaması daha zordur.
- Hazır makro denemesi
  - Bir fonksiyon içinde `__DATE__` ve `__TIME__` ile programın derlendiği tarih ve saat, `__LINE__` ve `__FILE__` ile kaynak dosyadaki satır ve dosya yazdırıldı. `__TIME__` çalışma zamanını değil derleme zamanını verir. `__LINE__` makronun yazıldığı satırı verir, fonksiyonun çağrıldığı satırı değil.
  - <!-- BELİRSİZ: bu denemenin kodu karelerde görünmüyor. -->

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
