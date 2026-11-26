# Ders 3 Genişletilmiş Notu: Operatörler ve Öncelik, Kontrol Deyimleri ve Önişlemci Makroları

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. İfade türleri
- 2. Zincirleme karşılaştırma ve zincirleme atama
- 3. Operatör öncelik tablosu ve bit kaydırma
- 4. Koşul operatörü ve tablonun alt kısmı
- 5. Parantezler ve aritmetik atama operatörleri
- 6. Artırma ve azaltma operatörleri
- 7. Virgül operatörü
- 8. İlişkisel ve mantıksal operatörler
- 9. Bit işleme operatörleri
- 10. cast ve sizeof operatörleri
- 11. Kontrol deyimleri hatırlatması
- 12. Önişlemci komutları ve makrolar
- Örnek Sorular
- Dersin Toparlaması

## 1. İfade türleri

Ders, önceki haftanın operatörler ve öncelik konusunun kaldığı yerden devam eder. Derste kullanılan ortam Dev-C++ 4'tür; hoca örnekleri bu haftanın projesi içinde tek bir kaynak dosyada yazıp derleyerek çalıştırdı.

Slayttaki ifade türleri şunlardır (ekrandan, 00:15:00):

- **Sabit ifadeler:** `5`, `5 + 6 * 13 / 3.0`.
- **Tam sayı ifadeleri** (`int j, k`): `j`, `j / k * 3`, `k - 'a'`, `3 + (int) 5.0`.
- **Ondalıklı ifadeler** (`double x, y`): `x / y * 5`, `3 + (float) 4`.
- **İşaretçi ifadeleri** (`int * p`): `p`, `p + 1`, `"abc"`.

`k - 'a'` örneğinde `'a'` tek tırnak içinde yazılmış bir karakter sabitidir. Her karakter arka planda ASCII koduyla bir sayıya karşılık gelir; büyük `A`'nın kodu 65'tir. Bu yüzden `k - 'a'`, `k`'nin değerinden `'a'`nın kodunu çıkaran bir tam sayı ifadesidir.

> **Ders sonrası not:** Hoca küçük `a`'nın kodu için "95 gibi bir şey" dedi; ASCII'de `'a'` 97'dir.

`3 + (int) 5.0` ifadesinde `5.0` ondalıklı yazılmıştır, ama önündeki `(int)` onu tam sayıya çevirir ve toplama tam sayı olarak yapılır. Hoca bunu bir adım ileri götürdü: değer 5.5 bile olsa ve cast yazılmasa bile, sonuç bir tam sayı değişkene atanırken küsurat silinir ve 8 olarak atanır. İşaretçi ifadeleri ileride ayrıca görülecek.

## 2. Zincirleme karşılaştırma ve zincirleme atama

Slayttaki uyarıya göre `a = b = c` ya da `a < b < c` gibi ikili atama ve ikili karşılaştırmalar yazmak doğru değildir. Belki amaç `c`'nin değerini `b`'ye, `b`'ninkini de `a`'ya atamak ya da "`a`, `b`'den, `b` de `c`'den küçük mü" diye sormaktır; ama derleyici bunları beklenenden farklı değerlendirebilir. Doğrusu `b = c; a = b;` biçiminde ayrı komutlar ya da `a < b && b < c` biçiminde ikiye bölünmüş bir koşuldur.

### 2.1 Dev-C++ denemesi

Hoca bunu göstermek için şu kodu yazdı (ekrandan, 00:20:00):

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

`b = 9`, `c = 7` olduğu için `b < c` yanlıştır, ama program "Evet" yazdı. Hoca önce bunun şans eseri olduğunu söyledi.

**Soru:** (Bir öğrenci) Bu şans değil; `a < b` ifadesi 1 sonucunu veriyor ve 1 de 7'den küçük, öyle değil mi?
**Cevap:** Evet. Doğru 1, yanlış 0 ile gösterildiği için önce `a < b` hesaplanır ve 1 olur, ardından `1 < c` karşılaştırılır. Bu yüzden her zaman beklenen sonuç alınmaz.

Koşul `a < b && b < c` biçiminde yazılınca program "Hayir" verdi ve farklı değer kombinasyonlarında hep doğru sonuç üretti.

> **Hocanın vurgusu:** Karşılaştırmaları ve atamaları zincirleme yazmayın; `a < b && b < c` ve `b = c; a = b;` biçimini kullanın.

Kod not hazırlanırken `system("PAUSE")` satırı çıkarılarak `gcc -Wall` ile derlenip çalıştırıldı: zincirleme biçim "Evet", ikiye bölünmüş biçim "Hayir" verdi. gcc ayrıca `a < b < c` satırı için "comparisons like 'X<=Y<=Z' do not have their mathematical meaning" uyarısı verdi.

## 3. Operatör öncelik tablosu ve bit kaydırma

Öncelik tablosunda en yukarıdaki en yüksek, en aşağıdaki en düşük önceliktir. Çarpma, bölme ve mod alma toplama ile çıkarmadan önce gelir. Bir ifade soldan sağa okunurken önce çarpma ve bölme, sonra toplama ve çıkarma yapılır; aynı öncelikteki işlemlerde soldaki önce yapılır.

Hoca tablonun alt kısmını aşağıdan yukarı okudu: eşitlik operatörleri (`==` eşit mi, `!=` eşit değil mi), onun üstünde ilişkisel operatörler (`<`, `<=`, `>`, `>=`), onun da üstünde kaydırma (shift) operatörleri yer alır.

> **Hocanın vurgusu:** Sınavlar kâğıt üzerinde yapıldığında küçük-eşit ve büyük-eşit işaretlerini matematikteki gibi tek simgeyle yazmayın. Klavyede öyle bir karakter yoktur; `<=` ve `>=` biçiminde iki karakterle yazın.

### 3.1 Sola ve sağa kaydırma

`<<` sola, `>>` sağa kaydırmadır; okun ucu hangi yöne bakıyorsa sayının ikili gösterimi o yöne kaydırılır. Hoca bunu bir hesap tablosunda bit bit gösterdi (ekrandan, 00:25:00):

- `int a = 9` → `00001001`.
- `int b = 6` → `00000110`.
- `a & b` → `00000000`, yani 0.
- `a && b` → mantıksal: `a` doğru, `b` doğru, sonuç TRUE, yani 1.
- `a << 1` → `00010010` = 18.

Sola kaydırmada en soldaki bit "uçurumdan düşer", diğer bütün bitler bir basamak sola kayar ve sağdan 0 gelir. Sonuç $16 + 2 = 18$'dir. Dev-C++'ta `a = b << 1;` (`b = 9`) yazılınca da 18 çıktı.

Bir bit sola kaydırmak 2 ile çarpmak, iki bit sola kaydırmak 4 ile çarpmak demektir. Bir bit sağa kaydırmak 2'ye bölmek gibidir, ama tek sayılar tam bölünmez. Hoca bu işlemlerin belki daha hızlı olabileceğini, ama milisaniye kazanmaya çalışan kod yazılmadığı için normal çarpma ve bölmenin kullanılmasını önerdi.

Sağa kaydırmada en sağdaki bit düşer, diğerleri bir sağa kayar. `9 >> 1` için `00000100` = 4 çıkar; Dev-C++'ta da 4 çıktı.

**Soru:** (Bir öğrenci) Negatif sayılarda kaydırma operatörü nasıl çalışıyor?
**Cevap:** Hoca, en soldaki işaret biti 1 olduğu için sağa kaydırmada soldan 0 gelirse sayının pozitife dönmesini beklediğini söyledi ve denedi. `-9 >> 1` sonucu -5 çıktı; yani işaret korundu. Hoca bunun nedenini o an açıklamadı ve kaydırma işlemlerinin aritmetik için değil, mantıksal (bit) işlemler için kullanıldığını, onlarla matematik yapmaya çalışmanın her zaman doğru sonuç vermeyeceğini söyledi. Nedeni dersin ilerleyen kısmında (Bölüm 9.1) bulundu.

### 3.2 Belirli bir biti bulma denemesi

Hoca kaydırma ile bir sayının belirli bir bitinin 0 mı 1 mi olduğunu bulmayı denedi (ekrandan, 00:30:00). Kodun açıklama satırında "soldan 4. bit nedir?" yazıyor; anlatıma göre ilgilenilen bit 8 değerli bittir (en sağdaki bit 1. sayılırsa 4. bit). Fikir şuydu: sayı önce 3 bit sağa kaydırılırsa istenen bit en sağa gelir; sonra uygun bir maskeyle işleme sokulup tekrar kaydırılırsa yalnız o bit kalır. Ekranda görülen ara hali:

```c
//soldan 4. bit nedir?
int a = 3, b = 9, c = 7;
a = b >> 3;
a = a << 3;
printf("sonuc=%d ", (a|8)>>);
```

Bu satırlar yazılma aşamasındadır (son satır eksik). `b = 9` için sonuç 1 çıktı, ama `b = 6` için de 1 çıkınca hoca ara değerleri yazdırdı. Bir öğrenci maskeleme için `|` (VEYA) değil `&` (VE) kullanılması gerektiğini belirtti; hoca haklı olduğunu kabul etti: tek `&` bitsel VE, çift `&&` mantıksal VE'dir. Hoca konuyu tamamlamadan, "sağa ve sola kaydırarak böyle bir şey bulabilirsiniz" diyerek geçti.

<!-- BELİRSİZ: kodun derste ulaşılan son hali karelerde ve altyazıda net değil. -->

> **Ek bilgi (derste anlatılmadı):** Bu iş tek satırda `(b >> 3) & 1` ile yapılabilir: 3 bit sağa kaydırılan sayının yalnız en sağdaki biti 1 ile VE'lenerek alınır. Not hazırlanırken gcc ile denendi: `b = 9` için 1, `b = 6` için 0 verdi.

## 4. Koşul operatörü ve tablonun alt kısmı

Tablonun devamında, öncelik sırası azalarak, bitsel işlemler gelir: önce `&`, sonra `^`, sonra `|`. Ardından çift karakterli mantıksal operatörler (`&&`, `||`), sonra koşullu atama operatörü `?:`, sonra bütün atama operatörleri ve en altta virgül gelir.

### 4.1 `?:` operatörü

Hoca bu operatöre "bir türlü ısınamadığını" söyledi. `a = 3`, `b = 9` için "`a`, `b`'den büyükse `c = 1`, değilse `c = 0`" ifadesi iki biçimde yazılabilir:

```c
int a = 3, b = 9, c = 7;
a > b ? c = 1 : c = 0;
/*if( a > b ) c = 1;
else        c = 0; */
printf("sonuc=%d ", c);
```

Ekranda görülen ilk deneme derleme hatası verdi: "invalid lvalue in assignment" (ekrandan, 00:35:00). Hoca ifadeyi parantez içine alıp sona tek noktalı virgül koyması gerektiğini fark etti; ama denediği biçimi derleyici yine kabul etmedi. Sonunda bunun yalnız tanınması için gösterildiğini, kullanılması için olmadığını söyledi.

> **Ek bilgi (derste anlatılmadı):** C'de `?:` atamadan daha yüksek öncelikli olduğu için `a > b ? c = 1 : c = 0;` büyük olasılıkla `(a > b ? c = 1 : c) = 0;` gibi ayrıştırılır ve sol taraf atanabilir olmadığı için hata verir. Doğru ve kısa biçim `c = (a > b) ? 1 : 0;` olur; not hazırlanırken gcc ile derlendi ve `a = 3, b = 9` için 0 verdi.

### 4.2 Atama ve virgül

Bütün atama işlemleri sondan bir önceki önceliktedir, en sonda virgül vardır. `char ch, int a, b` gibi bir listedeki virgülün en sonda değerlendirilmesi de bu yüzden doğaldır.

## 5. Parantezler ve aritmetik atama operatörleri

### 5.1 Parantezlerle önceliği değiştirme

Varsayılan öncelik işinize gelmiyorsa parantez kullanılır. `2 - 3 * 4` ifadesinde önce $3 \cdot 4 = 12$ hesaplanır, sonra $2 - 12 = -10$ bulunur. Önce `2 - 3` yapılsın isteniyorsa `(2 - 3) * 4` yazılır.

İç içe parantezlerde en içteki parantezden başlanır; en içte aynı düzeyde birden fazla parantez varsa en soldaki önce hesaplanır. Hocanın slayttaki örneği için anlattığı adımlar şunlardır: önce $3 + 1 = 4$, sonra $8 - 4 = 4$; ardından dış parantezde önce bölme ($4 / 4 = 1$), sonra $1 - 5 = -4$; en sonda $1 + (-4) = -3$.

<!-- BELİRSİZ: bu iç içe parantez örneğinin slayttaki tam ifadesi karelerde yok; yalnız anlatılan ara adımlar aktarıldı. -->

Mod alma (`%`) tam sayılar içindir; ondalıklı sayılarla doğru sonuç vermez.

### 5.2 Aritmetik atama operatörleri

Slayttaki tablo (ekrandan, 00:40:00):

| Operatör | Simge | Biçim | İşlem |
|---|---|---|---|
| assign | `=` | `a = b` | `b`'nin değerini `a`'ya koy |
| add-assign | `+=` | `a += b` | `a+b`'nin değerini `a`'ya koy |
| subtract-assign | `-=` | `a -= b` | `a-b`'nin değerini `a`'ya koy |
| multiply-assign | `*=` | `a *= b` | `a*b`'nin değerini `a`'ya koy |
| divide-assign | `/=` | `a /= b` | `a/b`'nin değerini `a`'ya koy |
| remainder-assign | `%=` | `a %= b` | `a%b`'nin değerini `a`'ya koy |

Yani `a += b`, `a = a + b` demektir.

Hoca ardından bir sonraki slayttaki ifadeleri hesapladı. Anlatıma göre `m` ve `n` tam sayı, `x` ve `y` ondalıklıdır; değerler `m = 3`, `n = 4`, `x = 2.5`, `y = 1.0`'dır. Sağ taraftaki ifadenin sonuç tipi ile sol taraftaki değişkenin tipi birlikte düşünülmelidir.

- `m += n + x - y`: önce $n + x = 4 + 2.5 = 6.5$ (bir işlenen ondalıklı olduğu için sonuç ondalıklıdır), sonra $6.5 - 1.0 = 5.5$, sonra $m + 5.5 = 8.5$. Sonuç tam sayı değişkene yazıldığı için küsurat kaybolur ve `m` 8 olur.
- `m /= x * n + 1`: önce $x \cdot n = 2.5 \cdot 4 = 10$, sonra $10 + 1 = 11$, sonra $3 / 11 \approx 0.27$. Küsurat kaybolacağı için `m` 0 olur.
- Son ifade için hoca, en sağdan başlanarak önce `y`'nin `m` kadar azaltılacağını, sonra çıkan `y` değerinin `x`'e ekleneceğini anlattı; ama bu tür ifadelerden kaçınılmasını, birkaç komuta bölünmesini önerdi.

<!-- BELİRSİZ: bu slaydın karesi yok; ifadeler ve değerler hocanın anlatımından kuruldu. İkinci ifadede eklenen 1 slaytta `y` olabilir. -->

İlk iki sonuç not hazırlanırken gcc ile doğrulandı (8 ve 0).

## 6. Artırma ve azaltma operatörleri

`++` ve `--`, `+= 1` ve `-= 1`'in kısaltmasıdır. Değişkenin sağına ya da soluna yazılmaları fark eder:

- **Son ek (postfix), `x = a++`:** önce `a`'nın değeri `x`'e atanır, sonra `a` bir artırılır. `a--` de aynı şekilde çalışır.
- **Ön ek (prefix), `x = ++a`:** önce `a` artırılır, sonra çıkan değer `x`'e atanır. `--b` de aynıdır.

### 6.1 `printf` içinde son ek ve ön ek

Hoca `printf` içindeki `j++` ifadesinin bir şey değiştirmeyeceğini düşündüğünü söyleyip denedi (ekrandan, 00:45:00):

```c
int j=5, k=5;
printf("j: %d\t k : %d\n", j++, k--);
printf("j: %d\t k : %d\n", j, k);
```

İlk satır `j: 5  k : 5` yazdı, ikinci satır `j: 6  k : 4` yazdı. Yani `printf` içinde bile önce değer kullanıldı, sonra artırıldı ya da azaltıldı. İlk satır `++j`, `--k` yapılınca bu kez önce işlem yapıldı, sonra değer kullanıldı ve iki satırda da 6 ve 4 göründü. Sonuçlar not hazırlanırken gcc ile doğrulandı.

### 6.2 Slayttaki karmaşık ifadeler

Slayt (ekrandan, 00:50:00), `int j = 0, m = 1, n = -1;` için:

| İfade | Parantezli hali | Sonuç |
|---|---|---|
| `m++ - --j` | `(m++) - (--j)` | 2 |
| `m += ++j * 2` | `m = ( m + ((++j) * 2 )` | 3 |
| `m++ * m++` | | derleyiciye bağlı |

Hoca bu tür ifadelerin normalde yazılmamasını, ama nasıl değerlendirildiklerinin anlaşılması gerektiğini söyledi. Her ifadeyi ayrı ayrı, ilk değerlerle denedi.

**`m++ - --j`:** Ön ek `--j` önce işlem yapar: `j` 0'dan -1'e düşer. `m++` son ek olduğu için önce `m`'nin değeri (1) kullanılır, sonra `m` 2 olur. Sonuç $1 - (-1) = 2$'dir. Hoca ilk denemede sonucun 0 olmasını bekledi, ama ekranda 2 çıktı; ardından "eksi eksi bir artı olur" diyerek hatasını düzeltti (ekrandan, 00:55:00):

```c
int j = 0, m = 1, n = -1, s;
s = m++- --j;   // (m++) - (--j)   1--1  s=2 m=2 j=-1
printf("j:%d m:%d n:%d s:%d ", j,m,n,s);
```

Not hazırlanırken gcc ile `j:-1 m:2 n:-1 s:2` sonucu alındı.

Hoca ardından boşlukların önemini denedi. Boşluklar normalde yalnız insanlar içindir ve derleyici için anlam taşımaz. Ama ifade tamamen bitişik yazılınca derleme hatası (invalid lvalue) çıktı. Yalnız `--` ile önündeki `-` arasına bir boşluk konunca hata kalktı; yani derleyicinin üç eksiyi birbirine karıştırmaması için o boşluk gerekiyordu.

**`m += ++j * 2`:** Önce `++j` yapılır ve `j` 1 olur; çarpmanın önceliği daha yüksek olduğu için $1 \cdot 2 = 2$ bulunur; `m` (1) bu kadar artırılır ve 3 olur. Ekranda `j` 1, `m` 3 çıktı. (Bu denemede sonuç değişkeni `s`'ye atama yapılmadığı için `s` ilk değer verilmemiş bir çöp değer gösterdi.)

**`m++ * m++`:** Hoca bunun derleyiciye bağlı olduğunu söyledi: `m`'nin karesi, `m` ile `m+1`'in çarpımı ya da başka bir sonuç çıkabilir. Denemede sonuç 1 çıktı, `m` ise 3 oldu; yani derleyici önce iki kez `m`'nin ilk değerini (1) kullandı, sonra iki kez artırdı.

> **Ek bilgi (derste anlatılmadı):** C standardında aynı değişkeni bir ifade içinde iki kez değiştirmek (`m++ * m++`) büyük olasılıkla "tanımsız davranış" (undefined behavior) sayılır; yani yalnız derleyiciye bağlı değil, hiçbir sonucu garanti değildir. Bu yüzden böyle ifadeler gerçek kodda hiç yazılmamalıdır.

## 7. Virgül operatörü

Virgül, bir ifadenin beklendiği yere birden fazla ifade yazılmasına izin verir. En tipik yeri `for` döngüsüdür. `for` üç bileşenden oluşur: yinelemelere başlamadan önce bir kez yapılan ilk değer atama, yinelemenin devam koşulu ve her yinelemenin sonunda otomatik yürütülen komut. İlk ve son kısma virgülle birden fazla komut yazılabilir.

## 8. İlişkisel ve mantıksal operatörler

### 8.1 İlişkisel operatörler

`a > b` gibi bir ifade doğru ya da yanlıştır; arka planda doğru 1, yanlış 0 ile gösterildiği için ifade sayısal olarak da kullanılabilir. Slayt (ekrandan, 01:20:00):

```c
int  j=0, m=1, n=-1;
float x=2.5, y=0.0;
```

| İfade | Parantezli hali | Sonuç |
|---|---|---|
| `j > m` | `j > m` | 0 |
| `m/n < x` | `(m / n) < x` | 1 |
| `j <= m >= n` | `( (j <= m) >= n)` | 1 |
| `++j == m != y * 2` | `((++j) == m) != (y * 2)` | 1 |

Adımlar:

- `j > m`: 0, 1'den büyük değildir; sonuç 0 (yanlış).
- `m/n < x`: $1 / (-1) = -1$, bu da 2.5'ten küçüktür; sonuç 1.
- `j <= m >= n`: önce `j <= m` → $0 \le 1$ doğru → 1; sonra $1 \ge -1$ doğru → 1. Hoca bu tür ifadelerden kaçınılmasını söyledi.
- `++j == m != y * 2`: önce aritmetik işlemler yapılır: $y \cdot 2 = 0$, `++j` ile `j` 1 olur. Sonra `1 == m` → $1 = 1$ doğru → 1; sonra $1 \ne 0$ doğru → 1.

> **Ders sonrası not:** Hoca önce ilişkisel operatörlerin "sağdan sola" (right to left) değerlendirildiğini söyledi; ardından slayttaki parantezlemeye bakarak soldan sağa değerlendirildiğini fark etti. Doğrusu soldan sağadır: ilişkisel ve eşitlik operatörleri soldan sağa birleşir, slayttaki parantezler de bunu gösterir.

### 8.2 Mantıksal operatörler

Mantıksal VE ve VEYA çift karakterle (`&&`, `||`), DEĞİL ise tek ünlemle (`!`) yazılır. Sıfır olmayan her değer doğru kabul edilir: `int a = 2` ya da `float x = 2.5` doğru/yanlış bağlamında kullanılırsa doğru sayılır.

Hocanın anlattığı örnekler (`j = 0`, `m = 1`, `n = -1`, `x = 2.5`):

- `j && m` → 0 ve 1 → 0.
- `j < m && n < m` → $0 < 1$ doğru (1), $-1 < 1$ doğru (1) → 1. Hoca `j < m > n` gibi yazmak yerine böyle ikiye ayırmanın en doğrusu olduğunu tekrarladı.
- `x * 5` içeren ifade: önce aritmetik yapılır, $2.5 \cdot 5$ sıfır olmayan bir değerdir ve 1 kabul edilir. VEYA'da bir tarafın 1 olması sonucu 1 yapar.
- `!x` → `x` doğru olduğu için tersi yanlıştır → 0. Diğer olumsuzlamalar da yanlış çıktı; hepsi VEYA ile bağlanınca sonuç 0 (yanlış) oldu.

Hoca slayttaki sonuçların sırasıyla 1, 0, 1, 1, 0 olarak doğru çıktığını söyledi.

<!-- BELİRSİZ: mantıksal operatörler slaydının karesi yok; ifadelerin tam yazımı altyazıdan çıkarılamadı, yalnız anlatılan değerlendirmeler aktarıldı. -->

## 9. Bit işleme operatörleri

Tabloda daha önce geçmeyen operatör şapka işaretidir (`^`): XOR (exclusive or, dışlayan VEYA). Tilde (`~`) ise bitsel tümleyendir; her biti tersine çevirir.

> **Ders sonrası not:** Hoca XOR'u ilk anlattığında "aynıysa 1, farklıysa 0" dedi; birkaç dakika sonra kendisi düzeltti: XOR'da iki bit aynıysa sonuç 0, farklıysa 1'dir ($0 \oplus 0 = 0$, $1 \oplus 1 = 0$, $0 \oplus 1 = 1$, $1 \oplus 0 = 1$).

### 9.1 Kaydırma tablosu ve negatif sayılar

Slayt (ekrandan, 01:25:00), 16 bitlik gösterimle:

| İfade | Sol işlenenin ikili hali | Sonucun ikili hali | Sonuç |
|---|---|---|---|
| `5 << 1` | `00000000 00000101` | `00000000 00001010` | 10 |
| `255 >> 3` | `00000000 11111111` | `00000000 00011111` | 31 |
| `8 << 10` | `00000000 00001000` | `00100000 00000000` | $2^{13}$ |
| `1 << 15` | `00000000 00000001` | `10000000 00000000` | $-2^{15}$ |
| `5 >> 2` | `00000000 00000101` | `00000000 00000001` | 1 |
| `-5 >> 2` | `11111111 11111011` | `11111111 11111110` | -2 |

- `5 << 1`: 5 = $4 + 1$; bir bit sola kayınca $8 + 2 = 10$.
- `255 >> 3`: sekiz tane 1'in sağdan üçü düşer, beş tane 1 kalır; $2^5 - 1 = 31$.
- `-5 >> 2`: bu satır hocanın derste karşılaştığı durumu açıkladı. Sağa kaydırmada soldan 0 değil, en soldaki bitin değeri (negatif sayıda 1) besleniyor. Hoca, kendi öğrencilik yıllarında gördüğü tanımın soldan 0 beslemek olduğunu, bu yüzden öyle anlattığını, ama C derleyicisinin böyle çalışmadığını söyledi. Dersin başında `-9 >> 1` sonucunun -5 çıkmasının nedeni de budur.

> **Ek bilgi (derste anlatılmadı):** İşaretli negatif bir sayının sağa kaydırılması C standardında büyük olasılıkla "gerçeklemeye bağlı" (implementation-defined) bırakılmıştır; yaygın derleyiciler işaret bitini kopyalayan aritmetik kaydırma yapar. Ayrıca slayttaki $-2^{15}$ sonucu 16 bitlik `int` içindir; 32 bitlik `int` kullanan bugünkü derleyicilerde `1 << 15` 32768 verir.

### 9.2 Bitsel VE, VEYA, XOR ve tümleyen

On altılık karşılıklar bilimsel hesap makinesiyle bulunabilir. Slayt (ekrandan, 01:30:00):

| İfade | On altılık | İkili |
|---|---|---|
| `9430` | `0x24D6` | `00100100 11010110` |
| `5722` | `0x165A` | `00010110 01011010` |
| `9430 & 5722` (=1106) | `0x0452` | `00000100 01010010` |
| `9430 \| 5722` (=14046) | `0x36DE` | `00110110 11011110` |

Bitsel VE'de bütün bitler tek tek VE işlemine girer: iki bit de 1 ise 1, değilse 0. Hoca sonuçları Dev-C++'ta da yazdırdı: VE 1106, VEYA 14046 verdi. Ardından aynı iki sayı için XOR'u yazdırdı ve 12940 buldu. `9430`'un bitsel tümleyeni bütün bitlerin tersidir ve negatif bir sayı olarak değerlendirilir; ekranda eksi işaretli bir sayı çıktı.

Not hazırlanırken python ile doğrulandı: `9430 & 5722` = 1106 (`0x452`), `9430 | 5722` = 14046 (`0x36DE`), `9430 ^ 5722` = 12940 (`0x328C`), `~9430` = -9431.

`<<=`, `>>=`, `&=` gibi bileşik atama operatörleri de vardır ve aritmetik atama operatörleriyle aynı mantıkla çalışır.

## 10. cast ve sizeof operatörleri

Slayt (ekrandan, 01:35:00):

- Cast operatörü bir değeri farklı bir tipe çevirmeye yarar. Kullanım amaçlarından biri, bölme sonucunun kesilmemesi için tam sayıyı ondalıklı sayıya yükseltmektir: `3 / 2` ve `(float) 3 / 2`.
- `sizeof` iki tür işlenen alır: bir ifade ya da bir veri tipi. İfade fonksiyon tipinde, `void` ya da bit alanı (bit field) olamaz.
- `sizeof`, işlenenin bellekte kapladığı byte sayısını döndürür: `sizeof (3+4)` int'in boyutunu döndürür; `sizeof(short)`.

`sizeof`, bir veri tipinin o platformda kaç byte ile gösterildiğini öğrenmeye yarar. İleride `struct` ve `union` ile kendi kayıt tiplerimiz oluşturulduğunda, bunları diske yazarken, okurken ya da dinamik bellek ayırırken ne kadar yer gerektiğini bulmak için de kullanılacak.

### 10.1 cast denemesi

`3` ve `2` tam sayı olduğu için `3 / 2`, 1.5 yerine küsuratı atılmış 1 verir. Küsuratın saklanması için işlenenlerden en az biri ondalıklı olmalıdır. Sabitlerde `3.0` yazılabilir; ama değişkenlerde sona `.0` eklenemez, bu yüzden başa parantez içinde tip yazılarak cast yapılır. Hoca tip dönüşümlerinin her dilde biraz farklı olduğunu ve veri kaybına yol açabildiği için nasıl davrandıklarının bilinmesinin önemli olduğunu söyledi.

```c
float a;
int b = 3;
a = (float) (b /2 );
printf("a:%f ",a);
```

Denemeler (ekrandan, 01:40:00):

- `a = 3 / 2;` → `a` `float` olduğu halde 1.000000 çıktı. Bölme iki tam sayıyla yapıldığı için 1.5 önce 1'e çevrilir, sonra atanır.
- `a = (float) 3 / 2;` → 1.500000.
- `a = b / 2;` → 1.000000; `a = (float) b / 2;` → 1.500000.
- `a = b / (float) 2;` → yine 1.500000. Bölme operatörü işlenenlerinden birini ondalıklı görürse işlemi ondalıklı yapar; ikisini birden çevirmek de sorun çıkarmaz.
- `a = (float) (b / 2);` → 1.000000. Parantez içindeki bölme yine iki tam sayıyla yapılır ve 1 çıkar; ancak ondan sonra 1, 1.0'a çevrilir.

> **Hocanın vurgusu:** Bütün işlemi değil, işlenenlerden birini cast etmek yeterlidir ve doğru kullanım budur.

Sonuçlar not hazırlanırken gcc ile doğrulandı.

### 10.2 sizeof denemesi

`a = sizeof(int);` 4 verdi; tam sayılar bu platformda 4 byte'tır. `sizeof(short)` 2 verdi. `sizeof(long)` ise 8 değil yine 4 çıktı; hoca bu konuyu bir önceki hafta da söylediklerini hatırlattı.

### 10.3 Koşul operatörü ve bellek operatörleri

Koşul operatörünün doğru kullanımı için biraz daha parantez gerekir: `z = ((x > y) ? x : y);` ifadesinde `x`, `y`'den büyükse `z`'ye `x`, değilse `y` atanır. Hoca slaytın sağındaki eşdeğer `if-else` biçiminin kullanılmasını istedi.

> **Ders sonrası not:** Hoca bu örneği anlatırken bir yerde "`x`, `y`'den küçükse `z`'ye `x` atanır" dedi; ifadeye göre `x` küçükse `z`'ye `y` atanır.

Bellek operatörleri diziler ve işaretçiler konusunda görüleceği için geçildi.

## 11. Kontrol deyimleri hatırlatması

### 11.1 `if-else` ve iç içe `if`

`if` koşulu doğruysa bir komut, değilse `else`'teki komut yürütülür. Genelde birden fazla komut gerektiği için süslü parantezle blok kullanılır. İkinci örnekte en sondaki komut her durumda yürütülür, çünkü iki dal birleşip akış oradan devam eder; bu, akış diyagramlarından bilinen bir şeydir.

`if-else` zincirinin yanında `if` içinde `if` de yazılabilir; `if`, `for`, `while` her türlü iç içe ve ikiden fazla düzeyde birleştirilebilir. Böyle durumlarda hangi bloğun hangi koşula ait olduğu mutlaka süslü parantezle gösterilmelidir.

Slayt (ekrandan, 01:45:00):

- Bir `else`'in hemen ardından `if` geliyorsa ikisi genelde aynı satıra yazılır; buna `else if` denir.
- İç içe `if`'ler, her `else`'i doğru `if` ile eşleme sorununu doğurur. Buna "sallanan else" (dangling else) sorunu denir.
- Bir `else` her zaman en yakın önceki `if`'e bağlanır.

```c
if(a<b)
   if(a<c)
         return a;
   else
         return c;
else if (b<c)
         return b;
else
   return c;
```

Bu kodda ilk `else`, `a < c`'nin `else`'idir, `a < b`'nin değil. Girinti en sola dayansa bile değişmez; girinti ve boşluk yalnız insanlar içindir, derleyici için anlam taşımaz (önceki bölümdeki üç eksi örneği gibi istisnalar dışında). Hoca slayt üzerinde süslü parantezleri çizerek gösterdi: hangi `else`'in hangi `if`'e bağlanması isteniyorsa ona göre blok açılıp kapanmalıdır.

### 11.2 `switch-case`

Tek bir değişkenin farklı değerlerine göre yürütülen bir `if-else if` zinciri `switch` ile yazılabilir. Hoca ikisini aynı programda yazdı (ekrandan, 01:55:00):

```c
int a;
printf("a degerini girin: "); scanf("%d",&a);
if( a == 0 )
    printf("SIFIR");
else if (a==1)
    printf("BIR");
else if (a==2)
    printf("IKI");
else
    printf("baskasini bilemiyorum");

switch(a) {
    case 0:
        printf("SIFIR");
        break;
    case 1:
        printf("BIR");
        break;
    /* ... */
}
```

<!-- BELİRSİZ: switch'in case 2 ve default kısmı karede görünmüyor; anlatıma göre case 2 "IKI" yazıp break ile biter, default "baskasini bilemiyorum" yazar. -->

`scanf`'te değişkenin adresi (`&a`) verilir. Her `case`'ten sonra başka bir şey yapılmaması için `break` yazılır. `case`'lerin hiçbiri tutmazsa `default` çalışır; en sondaki `break` iyi bir alışkanlıktır ama zorunlu değildir. `break`'in girintisi zevke ya da ekibin alışkanlığına kalmıştır.

Programa 1 girilince iki yapı da "BIR", 9 girilince "baskasini bilemiyorum" yazdı. `break`'ler silinip 0 girilince `if` zinciri yalnız "SIFIR" yazdı, `switch` ise `case 0`'dan başlayıp `default` dahil hepsini çalıştırdı.

`switch`'in mantığı şudur: değişkenin değerine göre girilen `case`'ten itibaren `break` görülene kadar sonraki `case`'ler de çalışır. Bu genelde uygulama mantığını bozar, bu yüzden `break` unutulmamalıdır. Ama art arda gelen birden fazla durumun çalışması isteniyorsa bu, `switch`'in bir esnekliği olarak `break`'siz kullanılabilir.

Hangisi tercih edilmeli? Fark etmez. Ancak `a < 0 && a > -5` gibi bir aralık yalnız `if` koşulunda yazılabilir; `switch`'e yalnız tek tek ayrık değerler yazılabilir.

### 11.3 Döngüler

- **`while (ifade)`:** ifade doğru olduğu sürece gövdeyi tekrarlar. Koşul her yinelemenin başında, ilk yinelemeden önce de denetlenir. Döngünün içinde koşulu bir noktada yanlış yapacak bir işlem olmalıdır; yoksa sonsuz döngü olur.
- **`do { ... } while (ifade);`:** noktalı virgül en sonda gelir. Gövde başta koşulsuz yürütüldüğü için en az bir yineleme garantidir; her yinelemenin sonunda koşul doğruysa devam edilir.
- **`for (ilk; koşul; son)`:** ilk ifade yinelemeler başlarken bir kez yapılır, ikinci ifade doğru olduğu sürece döngü sürer, üçüncü ifade her yinelemenin ardından otomatik yürütülür (genelde artırma ya da azaltma).

### 11.4 `for`'da boş ifadeler ve null statement

`for`'daki üç ifadeden biri gerekmiyorsa boş bırakılabilir. Örneğin sayaca daha önce değer atanmışsa ilk değer atama boş bırakılır; bu durumda o kısım boş komut (null statement) olur. Slayt (ekrandan, 02:15:00):

- `for` döngüsündeki ifadelerden biri atlanabilir, döngünün gövdesi de atlanabilir: `for(c = getchar(); isspace(c); c = getchar());`
- **Dikkat:** test koşulundan sonra noktalı virgül konursa, `if` ifadesi doğru olduğunda derleyici boş bir komut yürütür:

```c
if ( j == 1);
       j = 0;
```

Burada `j == 1` olduğunda hiçbir şey yapılmaz; `j = 0;` ise koşuldan bağımsız her durumda çalışır.

Hoca, ortadaki koşul ifadesi boş bırakılırsa döngünün hiç girilmeyeceğini mi yoksa sürekli mi çalışacağını merak edip denedi: `for (a = 0; ; a++)` içinde `a` yazdırılınca değerler durmadan arttı; boş koşul doğru kabul edildi ve sonsuz döngü oluştu (Ctrl-C ile çıkılır). Koşula `0` yazılınca döngüye hiç girilmedi. İlk ve koşul kısmı boş bırakılınca da sayaç sonsuza kadar yazdırıldı. Hoca bunların anlamlı kodlar olmadığını, ne olacağını anlamak için denendiğini söyledi.

### 11.5 İç içe döngüler, `break`, `continue`, `goto`

Döngüler iç içe yazılabilir; dizi işlemlerinde en az iki `for`'un iç içe kullanıldığı hatırlatıldı. İç döngü bütün yinelemeleriyle tamamlanınca dış döngünün tek bir yinelemesi bitmiş olur; dış döngünün sonraki yinelemesinde iç döngü yine baştan sona çalışır.

`break` yalnız içinde yazıldığı döngüden çıkar, en dış döngüden çıkmaz. Hepsinden birden çıkmak gerekirse fonksiyondan `return` ile çıkılabilir; ama fonksiyonun sonunda yapılacak iş varsa bir bayrak değişkeni kullanılır: bayrak başta 0'dır, iç döngüde koşul oluşunca 1 yapılır, dış döngü de bayrağı denetleyip gerekirse çıkar.

> **Hocanın vurgusu:** `continue` ve null statement tercih edilmiyor, lütfen kullanmayın. `goto` ise kesinlikle yasak: bir satıra etiket verip her yerden oraya atlamak, programın denetim akışını ucu belli olmayan, iç içe geçmiş bir yumağa çevirir.

## 12. Önişlemci komutları ve makrolar

### 12.1 Önişlemci nedir

Önişlemci (preprocessor) komutları, derleyiciye derlemeye başlamadan önce çeşitli komutlar vermeye yarar ve `#` ile başlar. Önce bu ön işlemler yapılır, sonra kaynak kodun işlenmiş hali derlenir. Derleyici `.c` dosyasını değiştirmez: dosyayı belleğe alır, önişlemci komutlarını bellekteki kopya üzerinde uygular ve o kopyayı derler. Bu çalışma biçimini bilmek önemlidir.

Önişlemciyle yapılabilecekler:

- Makro hazırlama.
- Koşullu derleme (conditional compilation): örneğin test sırasında ara değerleri yazdırmak için eklenen komutlar yalnız hata ayıklama içindir, son kullanıcının görmesi gerekmez. Bunlar işaretlenip "debug modunda derle" denince derlenir, müşteriye verilecek çalıştırılabilir dosya ise debug modu olmadan derlenir.
- Dosya ekleme (`#include`), daha önce kullanıldı.
- Satır denetimi (line control): derleyiciye belirli bir satırla ilgili bilgi verme.

### 12.2 Makro tanımlama ve sabitler

Makrolarla da bilgisayara hesap yaptırılabilir; aynı iş `main` içinde ya da ayrı fonksiyonlarla da yapılabilir. Farkları, artıları ve eksileri işlenecek. Ama şu hiç unutulmamalı: makro, derleyici için "yazdığım ifadeyi kodda geçtiği her yere yapıştır" demektir.

`#define`'dan sonra makroya bir ad verilir; isteğe bağlı olarak parametre de verilebilir (iki sayının toplamı gibi). Fonksiyonlarda parametrelerin tipi bilinir ve işlem ona göre yapılır; makrolar ise tipten bağımsız çalışır.

- `#define` satırının sonuna kesinlikle noktalı virgül konmaz.
- Makro alt satıra taşacaksa satır sonuna ters bölü (`\`) konup devam edilir.
- Makro adları gelenek olarak büyük harfle yazılır; böylece kodda neyin makro, neyin fonksiyon olduğu kolay ayırt edilir.

En basit ve yaygın kullanım sabit tanımlamaktır. Örneğin veriyi 512 byte'lık bir tampon bellekle okuyup yazıyorsanız ve kodun her yerine 512 yazdıysanız, değer değişince bütün 512'leri tek tek bulup değiştirmeniz gerekir. Bu angarya bir iştir; arada atlama yapılabilir, başka anlamdaki 512'ler de yanlışlıkla değişebilir. Bunun yerine en başa `#define BUFF_LEN 512` yazılır ve tampon amaçlı her yerde `BUFF_LEN` kullanılır. Derleyici bellekteki kopyada gördüğü her `BUFF_LEN` yerine 512 yazar; değer değişince yalnız tanım satırı değişir. Bu sabit dizi boyutu olarak da kullanılabilir.

Aynı değer değişken olarak tanımlansaydı boşuna 4 byte (`short` ise 2 byte) harcanırdı; makro kopyala-yapıştır olduğu için bellek harcamaz.

### 12.3 Fonksiyon benzeri makrolar

Slayt (ekrandan, 02:30:00):

- Dikkat: makronun sonunda `;` ya da makro tanımında `=` kullanmayın (derleme hatalarına yol açar).
- Makro argümanları için tip denetimi yoktur.
- Alıştırma: `min` makrosu örneğini üç sayı için genişletmeyi deneyin.

```c
/* Example 1 */
#define MUL_BY_TWO(a)  ((a) + (a))

j = MUL_BY_TWO(5);
f = MUL_BY_TWO(2.5);

/* Example 2 */
#define min(a, b) ( (a) < (b) ? (a) : (b))
```

Bir sayıyı 2 ile çarpmak onu kendisiyle toplamaktır; `MUL_BY_TWO(5)` 5'in iki katını `j`'ye atar. Hoca `?:` operatörünü sevmese de, minimum bulmak için onu bir kez makro olarak tanımlayıp kodda istediği gibi kullanmanın pratik olduğunu söyledi: makronun "imzası" `min(a, b)`, yapacağı iş ise "`a`, `b`'den küçükse `a`, değilse `b`"dir.

### 12.4 Tip denetimi olmaması

Makroya `'A'` ve `'B'` gibi iki karakter verilirse derleme hatası çıkmaz; karakterler ASCII kodlarıyla temsil edildiği için alfabede önce gelen küçük sayılır ve bu işe bile yarayabilir. Ama tip denetimi olmaması bazen olumsuz sonuç doğurur: örneğin bölme yapan bir makroda tam sayı mı ondalıklı mı bölüneceğini makro bilemez, gerekirse her şeyi makronun içinde cast etmek gerekir.

Hoca önce makronun normal kullanımını gösterdi:

```c
#define MIN(a, b) ( (a) < (b) ? (a) : (b))

int x = 5, y = 7;
printf("%d ", MIN(x, y));
```

Makro parametrelerinin adı (`a`, `b`) ile çağrıdaki değişkenlerin adının (`x`, `y`) aynı olması gerekmez. Çıktı 5 oldu; `x = 15` yapılınca 7 oldu.

Sonra makroya iki dizgi (string) verildi (ekrandan, 02:35:00). Hocanın verdiği iki örnek ad yerine burada genel adlar kullanılmıştır:

```c
printf("%d ", MIN("Ali", "Veli") );
```

Derleme hatası çıkmadı, ama ekranda anlamsız bir sayı (4198928) yazıldı. Hoca nedenini şöyle açıkladı: çift tırnak içindeki dizgi sabiti bellekte değiştirilemeyen bir alanda tutulur ve ifadede o alanın adresi kullanılır. Makro iki dizginin adresini karşılaştırıp küçük olanı döndürdü. Bu, kod mantığı açısından yanlıştır; derleyicinin uyarması gerekirdi.

Aynı iş fonksiyonla yapıldı:

```c
int min( int a, int b ) {
    if( a < b ) return a;
    else        return b;
}
```

Fonksiyona dizgiler verilince derleyici dizgileri işaretçi olarak ele alıp "cast etmeden işaretçiden tam sayıya dönüşüm" uyarısı verdi. Hata değil uyarı olsa da yanlış bir şey yapıldığı anlaşıldı. Fonksiyona tam sayılar verilince doğru çalıştı ve 7 yazdı.

### 12.5 Makronun yan etkisi

Slayt (ekrandan, 02:40:00):

```c
#define MIN(a,b)  ((a) < (b) ? (a) : (b))

a = MIN(b++, c);

a =  ((b++) < (c) ? (b++) : (c));
```

Makro `MIN(b++, c)` gibi çağrılırsa önişlemci bunu en alttaki satıra çevirir: makro tanımında `a` görülen her yere kelimesi kelimesine `b++` yazılır. Fonksiyon olsaydı `b` bir kez kullanılıp bir kez artırılırdı; makroda ise `b++` karşılaştırmada bir kez, sonuç olarak bir kez daha değerlendirilir. Böylece makro fonksiyon gibi davranmaz ve bu önemli bir yan etkidir.

> **Ders sonrası not:** Hoca eşitlik durumunda makronun ilk parametreyi döndürdüğünü söyledi. `(a) < (b)` eşitlikte yanlış olduğu için makro ikinci parametreyi (`b`) döndürür.

Hoca bunu göstermek için önce `x = 7, y = 7` ve `i = 7, j = 7` ile denedi; makro ve fonksiyon aynı sonucu verdi.

**Soru:** (Bir öğrenci) `x++` yerine `++x` deneyebilir miyiz?
**Cevap:** Denendi; yine aynı sonuç çıktı.

**Soru:** (Bir öğrenci) Değerler yanlış seçilmiş olabilir; `x = 6, y = 7` ve `i = 6, j = 7` ile dener misiniz?
**Cevap:** Hoca öyle denedi ve fark ortaya çıktı (ekrandan, 02:45:00):

```c
int min( int a, int b ) {
    if( a < b ) return a;
    else        return b;
}
int main(int argc, char *argv[])
{
    int x=6,y=7;
    int i=6,j=7;
    int a,b;
    a = MIN(x++,y);
    b = min(i++,j);
    printf("Makro:%d\n", a );
    printf("Fonks:%d\n", b );

    system("PAUSE");
    return 0;
}
```

Adım adım:

- Makro: `((x++) < (y) ? (x++) : (y))`. Karşılaştırmada `x`'in değeri 6 kullanılır, $6 < 7$ doğrudur ve `x` 7 olur. Sonuç olarak yine `x++` değerlendirilir: değeri 7'dir ve `x` 8 olur. `a = 7`.
- Fonksiyon: `min(i++, j)` çağrısında `i`'nin değeri 6 fonksiyona gider, sonra `i` 7 olur. Fonksiyon $6 < 7$ olduğu için 6 döndürür. `b = 6`.

Kod not hazırlanırken (`#include <stdio.h>` ve `MIN` tanımıyla, `system("PAUSE")` çıkarılarak) gcc ile derlenip çalıştırıldı: `Makro:7`, `Fonks:6`; ayrıca `x` 8, `i` 7 oldu. İlk denemedeki 7-7 değerlerinde fark görülmemesinin nedeni şudur (ara adım eklendi): $7 < 7$ yanlış olduğu için makro `x++`'ı ikinci kez değerlendirmez ve `y` döndürür.

### 12.6 Makroların artı ve eksileri

- **Hız:** Makrolar fonksiyon çağrısı ek yükünden kurtulur. Bir fonksiyon başka bir fonksiyonu çağırdığında denetim akışı çağrılan fonksiyona geçer; çağıranın durumu (değişkenler, değerleri) bellekte bir yığın yapısına atılır, üstüne yeni fonksiyonun değişkenleri ve komut işaretçisi gelir. Ondan da başka bir fonksiyon çağrılırsa o da yığının üstüne eklenir. Bu bağlam değişimi (context switching) arka planda yapılır. Makroda kopyala-yapıştır olduğu için bu maliyet yoktur.
- **Tipten bağımsızlık:** Sabit veri tipi olmaması aynı işlemi farklı tipler için tek seferde kodlamaya yarar. Ama bu tiplerin bazıları işe yarar, bazıları beklenmedik sonuçlar doğurur.
- **Yan etkiler:** Bölüm 12.5'teki gibi.
- **Kod büyüklüğü:** Fonksiyonun makine dili karşılığı çalıştırılabilir dosyaya bir kez yazılır ve çağrıldığı her yerden oraya atlanır. Makro ise kullanıldığı her yere yeniden yapıştırılır ve çalıştırılabilir dosyayı büyütür. Sınırlı depolama alanına sahip cihazlar için kod yazılırken bu bir dezavantajdır.
- **Tip denetimi yok:** Bölüm 12.4'teki gibi.
- **Hata ayıklama:** Arada önişlemcinin yapıştırma katmanı olduğu için makrolu kodu anlamak ve hata ayıklamak bir adım daha zordur.

Bu artı ve eksiler bilinerek, işe yaradığı yerde kullanılacak, riskli olduğu yerde kullanılmayacak.

> **Ders sonrası not:** Hoca çağıran fonksiyonun durumunun "heap bellekte bir yığın yapısına" atıldığını söyledi. Fonksiyon çağrılarındaki yerel değişkenler ve dönüş bilgisi büyük olasılıkla çağrı yığınında (stack) tutulur; heap, dinamik bellek ayırma için kullanılan ayrı bir bölgedir.

### 12.7 Makroyu kaldırma: `#undef`

Slayt (ekrandan, 02:50:00):

- Tanımlanan makro adı kaynak dosyanın sonuna kadar anlamını korur ya da `#undef` ile açıkça kaldırılana kadar.
- `#undef`'in en tipik kullanımı, bir tanımı kaldırıp yeniden tanımlayabilmektir.

```c
#define FALSE 1
/* code requiring FALSE = 1*/
#undef FALSE
#define FALSE 0
/* code requiring FALSE = 0*/
```

Normalde yanlış 0 ile gösterilir; ama belki eski bir kod kitaplığı `FALSE`'un 1 olmasını gerektiriyordur. O kod yazıldıktan sonra `#undef FALSE` ile tanım kaldırılır, `#define FALSE 0` ile yeniden tanımlanır. Bu örnek önişlemci komutlarının yalnız kaynak kodun başında değil, ortasında da yazılabileceğini gösterir.

### 12.8 Hazır makrolar

C ile birlikte gelen bazı makrolar iki alt çizgiyle başlayıp iki alt çizgiyle biter:

- `__LINE__`: kaynak kodun o anda kaçıncı satırında olunduğu.
- `__FILE__`: kodun hangi kaynak dosyada olduğu.
- `__TIME__`: programın çalıştığı değil, derlendiği saat.
- `__DATE__`: derlendiği tarih.
- `__STDC__`: derleyici ANSI standardına uyuyorsa belirli bir değer (1) verir.

Hoca bunları bir fonksiyon içinde "bu program şu tarihte, şu saatte derlenmiştir" ve "bu mesaj şu dosyanın şu satırındadır" mesajlarını yazdırmak için kullandı. Programı derleyip bir dakika sonra çalıştırdığında, çalışma saati değil derleme saati yazıldı. `__LINE__` da fonksiyonun çağrıldığı satırı değil, makronun yazıldığı satırı (mesaj alt satıra taştığı için bir sonraki satırı) gösterdi.

<!-- BELİRSİZ: hazır makro denemesinin kodu karelerde görünmüyor. -->

Koşullu derleme bir sonraki derse kaldı. Ders sonunda ekranda geçen slayt (ekrandan, 02:55:00), birbirinin eşdeğeri olan yazımları gösterir:

| Biçim 1 | Biçim 2 |
|---|---|
| `#if defined TEST` | `#if defined (TEST)` |
| `#if defined macro_name` | `#ifdef macro_name` |
| `#if !defined macro_name` | `#ifndef macro_name` |

## Örnek Sorular

**Soru 1** (ekrandan, 00:20:00): `int a = 3, b = 9, c = 7;` için `if (a < b < c) printf("Evet"); else printf("Hayir");` ne yazar? Neden?

> **Çözüm (derste verildi):** "Evet" yazar. `a < b` 1 verir ve `1 < 7` doğrudur. `b < c` yanlış olduğu halde koşul doğru çıkar. Doğru yazım `a < b && b < c`'dir ve "Hayir" verir.

**Soru 2** (ekrandan, 00:45:00): `int j=5, k=5;` için aşağıdaki iki satır ne yazar?

```c
printf("j: %d\t k : %d\n", j++, k--);
printf("j: %d\t k : %d\n", j, k);
```

> **Çözüm (derste verildi):** İlk satır `j: 5  k : 5`, ikinci satır `j: 6  k : 4` yazar. Son ekte önce değer kullanılır, sonra değiştirilir.

**Soru 3** (ekrandan, 00:50:00): `int j = 0, m = 1, n = -1;` için `m++ - --j`, `m += ++j * 2` ve `m++ * m++` ifadelerinin sonuçları nedir? (Her ifade ilk değerlerle ayrı hesaplanır.)

> **Çözüm (derste verildi):** `(m++) - (--j)` = $1 - (-1) = 2$; sonra `m` 2, `j` -1. `m = m + ((++j) * 2)` = $1 + 2 = 3$. `m++ * m++` derleyiciye bağlıdır; derste 1 çıktı ve `m` 3 oldu.

**Soru 4** (ekrandan, 01:20:00): `int j=0, m=1, n=-1; float x=2.5, y=0.0;` için `j > m`, `m/n < x`, `j <= m >= n`, `++j == m != y * 2` ifadelerinin değerleri nedir?

> **Çözüm (derste verildi):** Sırasıyla 0, 1, 1, 1. Parantezli halleri: `j > m`, `(m / n) < x`, `((j <= m) >= n)`, `((++j) == m) != (y * 2)`.

**Soru 5** (ekrandan, 01:25:00): 16 bitlik gösterimle `5 << 1`, `255 >> 3`, `8 << 10`, `1 << 15`, `5 >> 2`, `-5 >> 2` sonuçları nedir?

> **Çözüm (derste verildi):** 10, 31, $2^{13}$, $-2^{15}$, 1, -2. Negatif sayı sağa kaydırılırken soldan işaret biti beslenir.

**Soru 6** (ekrandan, 01:30:00): `9430 & 5722` ve `9430 | 5722` sonuçlarını on altılık ve onluk olarak bulun.

> **Çözüm (derste verildi):** `9430` = `0x24D6`, `5722` = `0x165A`. VE: `0x0452` = 1106. VEYA: `0x36DE` = 14046. Derste aynı sayılar için XOR 12940 bulundu.

**Soru 7** (ekrandan, 01:40:00): `float a; int b = 3;` için `a = b / 2;`, `a = (float) b / 2;`, `a = b / (float) 2;` ve `a = (float) (b / 2);` atamalarından sonra `a` kaç olur?

> **Çözüm (derste verildi):** 1.0, 1.5, 1.5, 1.0. Son ifadede bölme parantez içinde tam sayı olarak yapılır, cast sonradan uygulanır.

**Soru 8** (ekrandan, 01:45:00): Aşağıdaki kodda her `else` hangi `if`'e bağlıdır?

```c
if(a<b)
   if(a<c)
         return a;
   else
         return c;
else if (b<c)
         return b;
else
   return c;
```

> **Çözüm (derste verildi):** İlk `else` en yakın `if` olan `a < c`'ye bağlıdır. `else if (b<c)` ise ilk `if (a<b)`'nin `else`'idir; son `else` de `b < c`'ye bağlıdır. Girinti bu eşleşmeyi değiştirmez; farklı bir eşleşme isteniyorsa süslü parantez kullanılmalıdır.

**Soru 9** (ekrandan, 02:15:00): `if ( j == 1); j = 0;` kodu ne yapar?

> **Çözüm (derste verildi):** Koşuldan sonraki noktalı virgül boş komuttur. `j == 1` ise hiçbir şey yapılmaz; `j = 0;` ise koşuldan bağımsız her durumda çalışır.

**Soru 10** (ekrandan, 02:30:00): `min` makrosu örneğini üç sayı için genişletin.

> **Çözüm (derste verilmedi):** İki sayılık makro iç içe kullanılabilir:
>
> ```c
> #define MIN(a, b)     ( (a) < (b) ? (a) : (b) )
> #define MIN3(a, b, c) MIN(MIN(a, b), c)
> ```
>
> Not hazırlanırken gcc ile denendi: `MIN3(5, 2, 9)` 2, `MIN3(4, 8, 3)` 3 verdi. Bu makroya da `x++` gibi yan etkili argümanlar verilmemelidir; argümanlar birden çok kez değerlendirilebilir.

**Soru 11** (ekrandan, 02:40:00 ve 02:45:00): `#define MIN(a,b) ((a) < (b) ? (a) : (b))` ve `int min(int a, int b)` fonksiyonu için `x = 6, y = 7, i = 6, j = 7` iken `a = MIN(x++, y);` ve `b = min(i++, j);` sonuçları nedir?

> **Çözüm (derste verildi):** Makro `((x++) < (y) ? (x++) : (y))` olur: karşılaştırmada 6 kullanılır, sonuç olarak tekrar `x++` değerlendirilir ve `a = 7`, `x = 8` olur. Fonksiyon `b = 6` döndürür, `i = 7` olur.

## Dersin Toparlaması

Bu derste C operatörlerinin öncelik tablosu baştan sona tamamlandı. Zincirleme karşılaştırmanın neden yanlış sonuç verebildiği, bit kaydırma ve bitsel VE/VEYA/XOR/tümleyen işlemleri, negatif sayıların sağa kaydırılmasında işaret bitinin korunması, koşul operatörü, aritmetik atama, son ek ve ön ek artırma/azaltma, virgül, ilişkisel ve mantıksal operatörler ile cast ve `sizeof` örnekler üzerinden Dev-C++'ta denendi. Ana ders, karmaşık ve derleyiciye bağlı ifadelerden kaçınmak ve tip dönüşümlerinin veri kaybına nasıl yol açtığını bilmektir.

Ardından `if-else`, sallanan else sorunu, `switch-case` ve `break`, `while`, `do-while`, `for` ve boş ifadeler, iç içe döngüler ve `break` hatırlatıldı. Son kısımda önişlemciye geçildi: makronun kopyala-yapıştır mantığı, sabit tanımlama, fonksiyon benzeri makrolar, tip denetimi olmaması, yan etkiler, makro ile fonksiyonun artı ve eksileri, `#undef` ve hazır makrolar görüldü. Koşullu derleme bir sonraki derse kaldı.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
