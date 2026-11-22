# Ders 4 Çalışma Özeti

## Genel Konular

- İfadeler (expressions)
  - C'de sabit ifadeler (`5`, `5 + 6 * 13 / 3.0`), tamsayı ifadeleri (`j / k * 3`, `k - 'a'`, `3 + (int) 5.0`), kayan noktalı ifadeler (`x / y * 5`, `3 + (float) 4`) ve işaretçi ifadeleri (`p`, `p + 1`, `"abc"`) vardır (ekrandan, 00:15:00).
  - `k - 'a'` ifadesinde gizli bir tip dönüşümü vardır: karakterin sayısal (ASCII) değeri kullanılır.
  - `3 + (float) 4` önce 4'ü float'a çevirir, sonuç 7.0 olur.
- Operatör önceliği (precedence) ve birleşme yönü (associativity)
  - Bir ifadede önce en yüksek öncelikli operatör işletilir; atamanın neresinde olduğuna bakılmaz.
  - Öncelikleri eşit operatörler yan yana gelirse birleşme yönü (soldan sağa ya da sağdan sola) sırayı belirler.
  - Öncelik tablosu yukarıdan aşağıya (ekrandan, 00:20:00): primary `() [] -> .` (soldan sağa); unary: cast, `sizeof`, `&`, `*`, tekli `- +`, `~ ++ -- !` (sağdan sola); çarpımsal `* / %`; toplamsal `+ -`; kaydırma `<< >>`; ilişkisel `< <= > >=`; eşitlik `== !=` (bunların hepsi soldan sağa). Tablonun devamında bit düzeyi `& ^ |`, mantıksal `&& ||`, koşul operatörü `?:` ve atama operatörleri (sağdan sola), en altta virgül operatörü (soldan sağa) gelir.
  - `a = b = c = 6` sağdan sola işler: önce `c`, sonra `b`, sonra `a` 6 olur. `a = b + c - d` ifadesinde `+` ve `-` eşit öncelikli olduğundan soldan sağa işlenir.
  - Parantez öncelik sırasını değiştirmek için kullanılır; en içteki parantez önce, aynı seviyedeki parantezler soldan sağa hesaplanır.
- Operatörlerin operant sayısına göre sınıflandırılması
  - Unary (tekli): `!`, `++`, `--`, `sizeof`, cast.
  - Binary (ikili): `+`, `/`, `=`, `+=`, `-=` gibi iki operant alanlar.
  - Ternary (üçlü): tek örnek koşul operatörü `?:`.
- Aritmetik ve aritmetik atama operatörleri
  - `* / % + -` ikili aritmetik operatörlerdir. Kalan operatörü `%` yalnız tamsayılarla çalışır.
  - ANSI standardı `a == (a % b) + (a / b) * b` ilişkisini ister.
  - `b += a`, `b -= a`, `b %= a` gibi operatörler `b = b + a` vb. biçiminde açılarak çözülür.
- Artırma ve azaltma operatörleri
  - Prefix (`++a`): önce artırılır, sonra değer kullanılır. Postfix (`a++`): önce değer kullanılır, sonra artırılır.
  - `j++` ve `k--` ile yazdırma `5 5`, ardından `6 4` verir; `++j` ve `--k` ile iki satır da `6 4` verir (ekrandan, 00:40:00; derlenip denendi).
- Virgül operatörü
  - Tek ifade beklenen yerde birden fazla ifade yazmayı sağlar; sonuç en sağdaki operantın değeridir (ekrandan, 00:45:00).
  - Örnek: `for (j = 0, k = 100; k - j > 0; j++, k--)`.
- İlişkisel ve mantıksal operatörler
  - İlişkisel operatörler 0 (yanlış) ya da 1 (doğru) döndürür.
  - Mantıksal operatörler (`&&`, `||`, `!`) birden fazla önermeyi birleştirir. C'de 0 yanlış, sıfırdan farklı her değer (negatif dahil) doğrudur.
  - Kısa devre değerlendirme: `&&` zincirinde bir yanlış bulunursa, `||` zincirinde bir doğru bulunursa geri kalanlara bakılmaz.
- Bit düzeyi operatörler
  - `&`, `|`, `^` (XOR), `~` (tümleyen), `<<`, `>>` ve bunların atamalı biçimleri (`&=`, `<<=` vb.).
  - `5 & 6 = 4`, `5 ^ 6 = 3`; `~5` sıfır değil, sıfırdan farklı bir değerdir.
  - Sola kaydırma ikiyle çarpma, sağa kaydırma ikiye bölme gibidir; boşalan bitlere 0 gelir, taşan bit başa dönmez.
- Cast ve `sizeof`
  - Cast açık tip dönüşümüdür: `3 / 2` sonucu 1'dir; gerçek sonuç için operantlardan biri `(float)` ile çevrilir ya da `3.0` yazılır.
  - `sizeof` bir fonksiyon değil, operatördür; ifadenin ya da tipin boyutunu bayt cinsinden verir.
- Koşul operatörü `?:`
  - `a ? b : c`: `a` sıfırdan farklıysa sonuç `b`, değilse `c`. Örnek: `z = ((x < y) ? x : y);` iki sayıdan küçüğünü bulur (ekrandan, 01:20:00).
- Bellek operatörleri
  - `&` (adres), `*` (dereferans), `[]` (dizi elemanı), `.` (yapı üyesine değer yoluyla), `->` (yapı üyesine işaretçi yoluyla). Öncelikleri yüksektir.
- Akış kontrolü
  - `if`, `if-else`, iç içe `if`; `switch-case-default` ve `break`; `while`, `do-while`, `for`; boş deyim (null statement); `break`, `continue`, `goto`.
- Kod örnekleri (Dev-C++)
  - `scanf`'te `&` unutulursa programın çökmesi, değişkenlerin adreslerinin `%p` ile yazdırılması.
  - `switch` ile dört işlem hesap makinesi, `break` olmadan düşme (fall-through), `scanf(" %c", ...)` ile tampondaki Enter'ı atlama, `do-while` ile "devam etmek ister misiniz" menüsü.
  - `for` içinde `break` ve `continue` farkı.

## Hocanın Özellikle Vurguladığı Kısımlar

- Öncelik ve birleşme yönü
  - Derleyici kurallarını ezberlemek amaç değildir; önemli olan aynı öncelikli operatörlerin hangi yönde işlendiğini bilmek ve kafa karıştığında parantez kullanmaktır.
  - Öncelik tablosu ayrıntılıdır, gözden geçirilmesi faydalıdır.
- Aynı değişkeni bir ifadede birden çok kez artırmak
  - `m++` gibi işlemlerin aynı ifadede tekrarlandığı durumlarda sonuç derleyiciye göre değişebilir; kendi derleyicinizde deneyin, gerekirse parantezle açık yazın.
- Döngü seçimi
  - `while`: adım sayısı belli değildir, döngüye hiç girilmeyebilir, sonsuz döngü olabilir. Arama gibi ne zaman biteceği belli olmayan problemlerde kullanılır.
  - `do-while`: gövde en az bir kez çalışır (ör. şifre girişi, "tekrar oynamak ister misiniz" menüsü). Döngü sonunda noktalı virgül vardır.
  - `for`: başlangıcı, bitişi ve adım sayısı belli olan döngüdür. `for`'u `while` gibi yazmak önerilmez; iki döngü okuyucuya farklı mesaj verir.
- `break`, `continue`, `goto`
  - Bu derste `break` yalnız `switch` içinde kullanılır; döngülerde `break`, `continue` ve `goto` kullanılmaz. Gerekçe: algoritma analizini ve izlemeyi zorlaştırırlar; çıkış şartı döngünün şart kısmına yazılmalıdır.
  - Global değişken yerine parametre geçişi kullanılmalıdır.
- `scanf` ve adres operatörü
  - `scanf`'te değişken adresi (`&a`) verilmelidir. Dizilerde ve karakter dizilerinde taban adresi için `&` kullanılmaz.
  - Değişkenler tanımlandığında temizlenmez, içlerinde rastgele (çöp) değer bulunur.
  - `%c` okurken önceki girişten kalan Enter karakteri okunabilir; `" %c"` ile önündeki boşluk atlanır.
- Kaynak dosya `.c` uzantısıyla kaydedilmelidir.

## Kısa Tekrar Notları

- Önce öncelik, eşit öncelikte birleşme yönü; unary, koşul ve atama operatörleri sağdan sola, diğerleri soldan sağa.
- `m += n + x - y` → `m = m + ((n + x) - y)`; `m = 3, n = 4, x = 2.5, y = 1.0` için 8.5, int'e atanınca 8.
- `m /= x * n + y` → `m = m / ((x * n) + y)` = 3 / 11.0, int'e atanınca 0.
- `x += y -= m`: önce `y = 1.0 - 3 = -2.0`, sonra `x = 2.5 + (-2.0) = 0.5`.
- `%` yalnız tamsayı operantlarla kullanılır.
- Postfix: önce değer, sonra artırma; prefix: önce artırma, sonra değer.
- 0 yanlış, sıfırdan farklı her değer doğru; ilişkisel ve mantıksal operatörler 0/1 döndürür.
- `5 & 6 = 4`, `5 ^ 6 = 3`, `5 << 1 = 10`, `255 >> 1 = 127`, `255 >> 3 = 31`, `8 << 10 = 8192`.
- `0x24D6 & 0x165A = 0x0452`, `0x24D6 | 0x165A = 0x36DE`.
- `z = (x < y) ? x : y;` iki sayının küçüğü.
- `switch`'te her `case` sonunda `break` yoksa alttaki `case`'ler de çalışır.
- `for (i = 0; i < 5; i++) a = a + i;` → döngü sonunda `a = 10`, `i = 5`.
- `for`/`if` başlığının sonuna konan `;` gövdeyi boş deyim yapar.

## Detaylı Açıklamalar

- **Aritmetik atama örneği (ekrandan, 00:30:00).** Slaytta `int m = 3, n = 4; float x = 2.5, y = 1.0;` verilip dört ifade soruldu. Hoca önce ifadeleri yalnız `=` ile açtı (ekrandan, 00:35:00): `m = (m + ((n + x) - y))`. `n + x` int ile float toplamı olduğundan 6.5 olur, `m` eklenince 9.5, `y` çıkarılınca 8.5; sonuç int `m`'ye atandığından 8 saklanır. İkincisi `m = (m / ((x * n) + y))`: `x * n = 10.0`, `y` eklenince 11.0, 3 / 11.0 ≈ 0.27, int'e atanınca 0. Bir öğrencinin sorusu üzerine hoca, `%d` ile yazdırılınca 0 görüleceğini doğruladı. `x += y -= m` ifadesinde iki atama operatörü aynı öncelikte olduğundan sağdan sola işlenir: önce `y -= m`, sonra sonuç `x`'e eklenir.
  - Ders sonrası not: Hoca `n %= y + m` ifadesini `n % (y + m)` diye açıp geçti. Ancak `y` float olduğu için `y + m` da float'tır ve `%` float operant kabul etmez; bu satır C'de derlenmez (gcc: `invalid operands to binary %`, ajan tarafından denendi).
- **Artırma/azaltma (ekrandan, 00:40:00).** `j = 5, k = 5` iken `printf("j: %d\t k : %d\n", j++, k--);` önce eski değerleri (5, 5) yazar, sonra değişkenler 6 ve 4 olur. Prefix sürümde (`++j, --k`) değişkenler yazdırılmadan önce değişir, iki satırda da 6 ve 4 görülür. Hoca, postfix'te değerin önce getirilip sonra artırıldığını, yani iki iç içe işlem olduğunu, prefix'te ise doğrudan `a = a + 1` yapıldığını söyledi.
- **Mantıksal operatör örneği (ekrandan, 00:55:00).** `int j = 0, m = 1, n = -1; float x = 2.5, y = 0.0;` için: `j && m` → 0; `(j < m) && (n < m)` → 1; `((x * 5) && 5) || (m / n)` → 1 (12.5 ve 5 sıfırdan farklı olduğu için doğru); `((!x) || !n) || (m + n)` → 0 (`!2.5 = 0`, `!(-1) = 0`, `m + n = 0`). Sonuçlar ajan tarafından gcc ile doğrulandı.
  - Ders sonrası not: Slayttaki ipucu "All non-zero values are interpreted as FALSE" yazıyor. Doğrusu TRUE'dur; hoca da sözlü olarak sıfırdan farklı değerlerin doğru sayıldığını söyledi.
- **İlişkisel operatörlerde zincirleme karşılaştırma.** Hoca iki ilişkisel operatörün art arda geldiği bir ifadeyi sağdan sola değerlendirdi ve sonucu 0 buldu. <!-- BELİRSİZ: slayttaki ifade karelerde yok; altyazıdan tam çıkmıyor (00:46:13) -->
  - Ders sonrası not: Öncelik tablosuna göre (ekrandan, 00:20:00) ilişkisel operatörler soldan sağa birleşir. Ayrıca hocanın ara sonucundaki `1 >= -1` karşılaştırması doğrudur, yani 1 verir, 0 vermez.
- **Bit işlemleri (ekrandan, 01:00:00).** 9430 = `0x24D6` = `00100100 11010110`, 5722 = `0x165A` = `00010110 01011010`. AND sonucu `0x0452` = `00000100 01010010`, OR sonucu `0x36DE` = `00110110 11011110`. Onaltılık her basamak dört bite karşılık gelir. XOR'da bitler aynıysa 0, farklıysa 1 olur. `255 >> 1 = 127` (yedi tane 1), `255 >> 3 = 31` (beş tane 1); `8 << 10 = 2^13`.
- **Koşul operatörü (ekrandan, 01:20:00).** `if (x < y) z = x; else z = y;` yerine `z = ((x < y) ? x : y);` yazılır.
- **`switch` (ekrandan, 01:25:00).** İfade case etiketlerinden biriyle eşleşirse akış o etiketten devam eder; hiçbiri eşleşmezse varsa `default`'a gider. İki case aynı değeri taşıyamaz. `default`'un sonda olması zorunlu değildir ama iyi stildir.
- **`for` döngüsünün izlenmesi (ekrandan, 01:45:00).** `a = 0; for (i = 0; i < 5; i++) a = a + i; printf("%d %d", a, i);` için adımlar: `i = 0` → `a = 0`; `i = 1` → `a = 1`; `i = 2` → `a = 3`; `i = 3` → `a = 6`; `i = 4` → `a = 10`; `i = 5` olunca şart yanlış olur. Çıktı `10 5`'tir; `i`, döngü bittikten sonra da 5 değeriyle yaşamaya devam eder. `for`'un başlangıç kısmı boş bırakılıp `i = 0;` önceden yazılabilir.
  - Ders sonrası not: Hoca döngünün "n + 1 defa" gerçekleşeceğini söyledi. Bu örnekte şart 6 kez sınanır, gövde ise 5 kez çalışır.
  - Ders sonrası not: Hoca C'de `for (int i = 0; ...)` yazımının yasak olduğunu söyledi. Bu, C89/C90 için geçerlidir; C99 ve sonrasında izin verilir. Derste kullanılan derleyicinin büyük olasılıkla eski standart modunda çalıştığı için hata verdiği düşünülebilir.
- **`scanf` ve adres operatörü (ekrandan, 02:00:00).** `scanf("%d %d", &a, b)` yazılınca `b`'nin içindeki çöp değer (örnekte 0) adres sanılır, program o adrese yazmaya çalışır ve işletim sistemi başka bir sürecin adres alanına erişime izin vermediği için program çöker. Adresler `%p` ile yazdırıldığında `b`'nin bellekte `a`'dan 4 bayt önce yer aldığı görüldü.
- **Hesap makinesi (ekrandan, 02:10:00, 02:30:00).** `scanf("%d %d", &a, &b)` sonrası `scanf("%c", &op)` Enter karakterini okuduğu için doğrudan "Hatalı giris" yazıldı; `scanf(" %c", &op)` ile çözüldü. `break` yorum satırı yapılınca `+` girişinde altındaki bütün case'ler ve `default` de çalıştı. Son sürümde menü `do { ... } while (devam == 'E');` içine alındı ve `scanf("%d %c %d", &a, &op, &b)` ile `4 + 7` gibi tek satırda giriş yapıldı. Tam kod genişletilmiş notta verilmiştir (ajan tarafından `gcc -Wall` ile derlenip `4 + 7`, `5 * 8` girdileriyle denendi).
- **`break` ve `continue` (ekrandan, 02:25:00).** `for (i = 0; i < 5; i++) { printf("%d - ", i); if (i == 3) break; }` çıktısı `0 - 1 - 2 - 3 -`. `if (i == 3) continue;` yazdırmadan önce konursa çıktı `0 - 1 - 2 - 4 -` olur: 3 atlanır, döngü devam eder.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
