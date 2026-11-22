# Ders 4 Genişletilmiş Notu: Operatörler, İfadeler ve Akış Kontrolü

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. İfadeler
- 2. Operatör Önceliği ve Birleşme Yönü
- 3. Operatörlerin Operant Sayısına Göre Sınıflandırılması
- 4. Aritmetik ve Aritmetik Atama Operatörleri
- 5. Artırma ve Azaltma Operatörleri
- 6. Virgül Operatörü
- 7. İlişkisel ve Mantıksal Operatörler
- 8. Bit Düzeyi Operatörler
- 9. Cast, sizeof ve Koşul Operatörü
- 10. Bellekle İlgili Operatörler
- 11. Akış Kontrolü: if ve switch
- 12. Döngüler: while, do-while, for
- 13. Boş Deyim, break, continue ve goto
- 14. Kod Örnekleri: scanf, switch ile Hesap Makinesi, break ve continue

## 1. İfadeler

Dersin konusu temel operatörler, ifadeler (expression), operatör öncelikleri, aynı öncelikteki operatörlerin birbirine göre nasıl değerlendirileceği ve ardından akış kontrolüdür.

C'de bir değer üreten her yazım bir ifadedir. Slaytta dört tür ifade örneklendi (ekrandan, 00:15:00):

- **Sabit ifadeler:** `5`, `5 + 6 * 13 / 3.0`. Programın herhangi bir yerine tek başına `5` yazmak bile geçerli bir ifadedir.
- **Tamsayı ifadeleri (`int j, k`):** `j`, `j / k * 3`, `k - 'a'`, `3 + (int) 5.0`.
- **Kayan noktalı ifadeler (`double x, y`):** `x / y * 5`, `3 + (float) 4`.
- **İşaretçi ifadeleri (`int *p`):** `p`, `p + 1`, `"abc"`.

`k - 'a'` ifadesi önemlidir: burada gizli bir tip dönüşümü vardır. Tamsayıdan bir karakter çıkarılırken karakterin sayısal değeri kullanılır. `3 + (float) 4` ifadesinde önce 4 float'a çevrilir, sonra 3 eklenir ve sonuç 7.0 gibi bir kayan noktalı değer olur. İşaretçi ifadelerinde işaretçi aritmetiği yapılabilir; bu konu ilerleyen haftalarda görülecek.

## 2. Operatör Önceliği ve Birleşme Yönü

Her operatörün iki önemli özelliği vardır: **öncelik** (precedence) ve **birleşme yönü** (associativity, binding). Bu iki özellik operantların hangi sırayla işleneceğine karar verir.

Öncelik, matematikte olduğu gibi işler: önce yüksek öncelikli operatör işletilir. Bir atama ifadesinde çarpma nerede olursa olsun önce çarpma yapılır; bakılan şey ifadedeki en yüksek öncelikli operatördür. Bazı durumlarda operatörler aynı önceliğe sahiptir; örneğin `+` ile `-` ya da atama operatörleri. "Eşit şartlardayız, önce hangisini yapalım?" sorusunun cevabını birleşme yönü verir.

### 2.1 Öncelik tablosu

Slayttaki tablo, en yüksek öncelikten aşağıya doğru şöyledir (ekrandan, 00:20:00):

| Sınıf | Operatörler | Birleşme yönü |
|---|---|---|
| primary | `()` `[]` `->` `.` | Soldan sağa |
| unary | cast, `sizeof`, `&` (adres), `*` (dereferans), tekli `-` `+`, `~` `++` `--` `!` | Sağdan sola |
| multiplicative | `*` `/` `%` | Soldan sağa |
| additive | `+` `-` | Soldan sağa |
| shift | `<<` `>>` | Soldan sağa |
| relational | `<` `<=` `>` `>=` | Soldan sağa |
| equality | `==` `!=` | Soldan sağa |

Hoca tablonun devamını da gösterdi: bit düzeyi AND, OR gibi operatörler yine soldan sağa; en altta atama operatörleri ve koşul operatörü sağdan sola; en sonda da virgül operatörü soldan sağa birleşir.

En üstte normal parantez, dizi elemanına erişim ve yapı (struct) elemanına erişim operatörleri vardır. Örneğin parantez içinde `d[3] + 5` varsa önce dizinin elemanı getirilir. Bu operatörlerden birkaçı art arda gelirse soldan sağa işlenir.

Hoca derste cast operatörünün nasıl yazıldığını sordu; cevap `(int) a` biçimiydi, tip olarak `double`, `float`, `char` da yazılabilir. `sizeof` henüz kullanılmadı ama önümüzdeki haftalarda sık kullanılacak. Hoca bunun bir fonksiyon değil **operatör** olduğunu vurguladı: `sizeof a` ya da `sizeof(int)` yazılır ve içerisine verilen ifadenin boyutunu bayt cinsinden döndürür.

Tekli operatörler aynı satırda bir araya gelirse sağdan sola işlenir. Atama operatörü de sağdan sola birleşir. Örneğin:

```c
a = b = c = 6;
```

Burada önce `c`'ye 6 atanır, sonra `c`'nin değeri `b`'ye, en son `b`'nin değeri `a`'ya atanır. Buna karşılık `a = b + c - d` ifadesinde `+` ve `-` eşit öncelikli ve soldan sağa olduğundan önce `b + c`, sonra bundan `d` çıkarılır, üçüncü işlem olarak sonuç `a`'ya kopyalanır.

### 2.2 Virgül operatörü nerede kullanılır?

Hoca öğrencilere virgül operatörünün nerede kullanıldığını sordu. Verilen örnekler: fonksiyon parametrelerini ayırırken (`f(int a, int b)`) ve değişken tanımlarken (`int a, b, c;`). Virgülde önce solundaki, sonra sağındaki işlem yapılır.

### 2.3 Parantezler

Derleyicinin kendi içinde bir öncelik sırası vardır. Problem çözerken farklı bir sıraya ihtiyaç varsa, örneğin çıkarmanın önce yapılması gerekiyorsa, matematikte olduğu gibi parantez kullanılır. En içteki parantez önce hesaplanır; aynı seviyedeki parantezlerde soldaki önce yapılır. Hocanın gösterdiği örnekte önce `3 + 1 = 4`, sonra `8 - 4 = 4`, sonra bölme önceliğinden dolayı `4 / 4` hesaplandı ve sonuca adım adım ulaşıldı. <!-- BELİRSİZ: örnek ifadenin tamamı karelerde yok; altyazıda sonraki adımlar ("1-5, daha sonra 3") net değil (00:23:29) -->

## 3. Operatörlerin Operant Sayısına Göre Sınıflandırılması

Operatörler aldıkları operant sayısına göre üçe ayrılır. Hoca bunu Paint'te bir ağaç olarak çizdi (ekrandan, 00:25:00):

- **Unary (tekli):** tek operant alır. Öğrencilerden gelen örnekler: değil `!`, `++`, `--`; hocanın ekledikleri: `sizeof` ve cast operatörü. Bunların hepsi bir değer döndürür ve tek bir değişken alır.
- **Binary (ikili):** sağına ve soluna birer operant alır: `+`, `/` ve daha önemlisi `=`, `+=`, `-=`.
- **Ternary (üçlü):** C'de tek bir tane vardır, koşul operatörü `?:`.

## 4. Aritmetik ve Aritmetik Atama Operatörleri

İkili aritmetik operatörler çarpma, bölme, kalan (mod), toplama ve çıkarmadır. Diğer matematiksel operatörler kayan noktalı sayılarla da çalışır, ama kalan operatörü `%` yalnız tamsayılarla çalışır; `4.0` gibi bir değerle kullanılamaz. Kalanın işareti negatif ya da pozitif olabilir, uygulamaya göre değişebilir. ANSI standardı şu ilişkinin sağlanmasını ister:

$$a = (a \bmod b) + (a / b) \cdot b$$

Yani `%` tam bölmeyle ilgili bir işlemdir.

> **Ek bilgi (derste anlatılmadı):** C99 standardından itibaren tamsayı bölmesi sıfıra doğru keser; bu yüzden kalanın işareti bölünenin işaretiyle aynıdır (örneğin `-7 % 3 == -1`). "Uygulamaya bağlı" durum büyük olasılıkla eski C89 standardı için geçerlidir.

Aritmetik atama operatörleri de ikilidir: `b += a` `b`'yi `a` kadar artırır, `b -= a` azaltır, `b %= a` ise `b = b % a` anlamına gelir.

### 4.1 Örnek: aritmetik atama ifadeleri

Slaytta şu tanımlar ve dört ifade verildi; hoca öğrencilerden sonuçları yazmalarını istedi (ekrandan, 00:30:00):

```c
int m = 3, n = 4;
float x = 2.5, y = 1.0;

m += n + x - y
m /= x * n + y
n %= y + m
x += y -= m
```

Hocanın önerdiği yol: önce ifadenin yalnız `=` kullanılarak yazılmış açık hâlini bulmak; gerisi kolayca gelir. Paint'teki açılımlar (ekrandan, 00:35:00):

**Birinci ifade:** `m = (m + ((n + x) - y))`. `+` ve `-` eşit öncelikli olduğundan önce `n + x` yapılır.

- Verilen: `m = 3`, `n = 4`, `x = 2.5`, `y = 1.0`.
- `n + x = 4 + 2.5 = 6.5` (int ile float toplanınca otomatik olarak float'a dönüşür).
- `m + 6.5 = 9.5`, `9.5 - y = 8.5`.
- Sonuç int `m`'ye atandığı için `m = 8`.

**İkinci ifade:** `m = (m / ((x * n) + y))`. Çarpma daha öncelikli.

- `x * n = 2.5 \cdot 4 = 10.0`, `+ y` → `11.0`.
- `m / 11.0 = 3 / 11.0 ≈ 0.27`.
- `m` int olduğu için `m = 0`.

**Soru:** İkinci ifadede sonuç integer istendiği için mi cevap sıfır oluyor? **Cevap:** Evet; 3 bölü 11, `m` int tanımlandığı için `%d` ile yazdırılırsa 0 görülür.

**Üçüncü ifade:** `n = n % (y + m)` biçiminde açılır.

> **Ders sonrası not:** Derste bu satırın sonucu hesaplanmadı. `y` float olduğu için `y + m` de float'tır; `%` operatörü float operant kabul etmediğinden bu satır C'de derlenmez (gcc `invalid operands to binary %` hatası verir; ajan tarafından denendi).

**Dördüncü ifade:** `x += y -= m`. İki atama operatörü aynı öncelikte olduğu için sağdan sola çalışır; yani önce `x += y` değil, önce `y -= m` yapılır. Hoca bunu `a = b = c` ifadesine benzetti: orada da önce `c`, `b`'ye atanır.

- `y = y - m = 1.0 - 3 = -2.0`.
- `x = x + y = 2.5 + (-2.0) = 0.5`.

Birinci, ikinci ve dördüncü ifadelerin sonuçları (8, 0 ve `x = 0.5`, `y = -2.0`) ajan tarafından gcc ile doğrulandı.

## 5. Artırma ve Azaltma Operatörleri

`++` ve `--` operanttan önce ya da sonra kullanılabilir. Hoca bu konuda öğrencilerin çok hata yaptığını söyledi.

- **Postfix (`a++`):** operatör operanttan sonra gelir. Önce `a`'nın değeri elde edilir, sonra artırılır.
- **Prefix (`++a`):** operatör operanttan önce gelir. Önce `a` artırılır, sonra değeri elde edilir.

Klasik bir `for` döngüsünde ikisi aynı sonucu verir ama hesaplama biraz farklıdır. `a = 5` iken `a++` hesaplanırsa önce `a`'nın değeri (5) getirilir, sonra 5 artırılarak 6 bulunur ve 6 değişkende kalır; yani aslında iç içe iki işlem vardır. `++a`'da ise doğrudan `a = a + 1` yapılır, tek işlem gibidir. Hoca, `for` döngüsünde `++i` kullanımının daha hızlı olduğunun söylenmesinin bir sebebinin bu olduğunu belirtti.

> **Ek bilgi (derste anlatılmadı):** Basit tamsayı sayaçlarında günümüz derleyicileri `i++` ile `++i` için büyük olasılıkla aynı makine kodunu üretir; fark ancak dönüş değeri kullanıldığında ya da C++'taki karmaşık nesnelerde ortaya çıkar.

### 5.1 Örnek: postfix ve prefix

Slayttaki iki program (ekrandan, 00:40:00):

```c
main () {
    int j=5, k=5;
    printf("j: %d\t k : %d\n", j++, k--);
    printf("j: %d\t k : %d\n", j, k);
    return 0;
}
```

```c
main () {
    int j=5, k=5;
    printf("j: %d\t k : %d\n", ++j, --k);
    printf("j: %d\t k : %d\n", j, k);
    return 0;
}
```

Postfix programında önce `j`'nin değeri getirilip yazılır, sonra `j` bir artırılır; aynı şekilde `k` yazılıp bir azaltılır. İlk satırda `5 5`, ikinci satırda güncellenmiş değerler `6 4` görülür. Prefix programında `%d`'ye giden değer, içinde gizli bir atama olan ifadenin (`j = j + 1`) sonucudur; önce `j` 6, `k` 4 yapılır ve ekrana basılır. İkinci satır da yine `6 4`'tür. (Çıktılar ajan tarafından derlenip denendi.)

### 5.2 Karışık artırma/azaltma ifadeleri

`m++ - --j` gibi ifadeler kafa karıştırabilir. Bunlar öncelik tablosuna göre parantezlenmelidir: tekli operatörler tabloda neredeyse en üsttedir, sonra `+` ve `-` gelir; dolayısıyla önce `m++` ve `--j` yapılır, onlar parantez içinde düşünülür, sonra çıkarma yapılır. `m = m++ + ++c * 2` gibi bir ifadede de önce `++c` yapılır, sonra çarpma, sonra toplama, en son atama gerçekleşir. <!-- BELİRSİZ: slayttaki ifadelerin tam yazımı karelerde yok (00:40:32-00:42:07) -->

Hoca aynı değişkenin bir ifadede iki kez artırıldığı bir örnekte (`m` başlangıçta 1) şu soruyu sordu: ilk `m++` 2'yi verdikten sonra ikinci artırma 2 üzerinden mi devam eder, 1 üzerinden mi? 2 üzerinden devam etmesi daha çok beklenir (sonuç 2 ve 3, çarpım 6), ama bazı derleyicilerde yığın (stack) kullanımı yüzünden 2 kere 2, yani 4 de görülebilir. Bu yüzden kendi derleyicinizde denemek gerekir. <!-- BELİRSİZ: ifadenin tam yazımı karelerde yok (00:42:25-00:43:49) -->

> **Ders sonrası not:** Hoca bu durumu "uygulamaya bağlı" (implementation dependent) diye anlattı. C standardına göre aynı değişkenin bir sıralama noktası olmadan iki kez değiştirildiği ifadeler (örneğin `m++ * m++`) tanımsız davranıştır (undefined behavior); sonucun hiçbir garantisi yoktur ve böyle ifadeler yazılmamalıdır.

> **Hocanın vurgusu:** Amaç derleyicinin kurallarını ezberletmek değildir. Önemli olan aynı öncelikli operatörler geldiğinde soldan sağa mı sağdan sola mı yapılacağını ve hangisinin öncelikli olduğunu bilmek; kafa karıştığında da parantezle düzeltmektir.

## 6. Virgül Operatörü

Virgül operatörü, tek bir ifadenin beklendiği yerde iki ya da daha fazla ayrı ifadenin değerlendirilmesini sağlar; sonuç en sağdaki operantın değeridir (ekrandan, 00:45:00). Örnek:

```c
for (j = 0, k = 100; k - j > 0; j++, k--)
```

`for`'un ilk bölümünde (ilklendirme) tek bir değişkeni ilklendirmek zorunlu değildir; virgülle birden fazla ilklendirme yapılabilir. Şart kısmında birden fazla şart verilebilir (bunlar `&&` gibi operatörlerle birleşir). Son kısımda da virgülle birden fazla değişkene, yani şarta müdahale eden birden fazla işleme yer verilebilir.

## 7. İlişkisel ve Mantıksal Operatörler

### 7.1 İlişkisel operatörler

İlişkisel operatörler sonunda doğru ya da yanlış döndürür. Diğer operatörlerin sonucu genellikle tamsayı ya da kayan noktalı sayıdır; ilişkisel operatörlerin sonucu ise 0 ya da 1'dir.

Slayttaki örneklerde yine öncelik tablosu kullanıldı: bölme ilişkisel operatörden önce geldiği için önce bölme parantez içine alınır; `++` olan örnekte önce artırma yapılıp sonra `m` ile karşılaştırma yapılır. Hoca iki ilişkisel operatörün art arda geldiği bir ifadeyi "aynı öncelikli oldukları için sağdan sola" değerlendirdi: `j = 0`, `m = 1` iken önce `j <= m` sınandı ve 1 geldi, ardından bu 1'in `n = -1` ile büyük-eşit karşılaştırması yapıldı ve sonuç 0 denildi. <!-- BELİRSİZ: slayttaki ifade karelerde yok, altyazıdan tam çıkmıyor (00:45:38-00:47:22) -->

> **Ders sonrası not:** Öncelik tablosuna göre (ekrandan, 00:20:00) ilişkisel operatörler soldan sağa birleşir, sağdan sola değil. Ayrıca hocanın ara adımındaki `1 >= -1` karşılaştırması doğrudur, yani sonuç 1'dir, 0 değildir.

### 7.2 Mantıksal operatörler

Mantıksal operatörler birden fazla ifadeyi, önermeyi birleştirir; mantık derslerindeki birleşik önermelerin programlamadaki karşılığıdır. Slayttaki örnek (ekrandan, 00:50:00 ve 00:55:00):

```c
int j=0, m=1, n=-1;
float x=2.5, y=0.0;
```

| İfade | Parantezli hâli | Sonuç |
|---|---|---|
| `j && m` | `(j) && (m)` | 0 |
| `j < m && n < m` | `(j < m) && (n < m)` | 1 |
| x \* 5 && 5 \|\| m / n | ((x \* 5) && 5) \|\| (m / n) | 1 |
| !x \|\| !n \|\| m + n | ((!x) \|\| !n) \|\| (m + n) | 0 |

Adım adım:

- `j < m && n < m`: önce `j < m` (0 < 1, doğru), sonra `n < m` (-1 < 1, doğru), sonra ikisi AND ile birleşir: doğru ve doğru → 1.
- `x * 5 && 5 || m / n`: önce çarpma, `2.5 \cdot 5 = 12.5`. Sıfırdan farklı olduğu için AND açısından 1 demektir; 5 de 1 demektir. 1 AND 1 → 1. `m / n = 1 / (-1) = -1`, o da sıfırdan farklıdır. Doğru OR doğru → 1.
- `!x || !n || m + n`: değil operatörünün önceliği daha yüksektir. `!2.5 = 0`, `!(-1) = 0`; 0 OR 0 = 0 olduğu için son terime bakmak gerekir; `m + n = 1 + (-1) = 0`. Sonuç 0.

C'de 0 her zaman yanlış demektir; 1, 5, 0.3 gibi sıfırdan farklı her değer doğru kabul edilir.

> **Ders sonrası not:** Slayttaki ipucu "All non-zero values are interpreted as FALSE, including negative values" yazıyor. Doğrusu TRUE'dur: negatif değerler dahil sıfırdan farklı her değer doğru sayılır. Hoca da sözlü olarak bu şekilde anlattı. Tablodaki dört sonuç ajan tarafından gcc ile doğrulandı.

### 7.3 Kısa devre değerlendirme

**Soru:** Kısa devre özelliği hangisinde var? **Cevap:** Hoca soruyu önce anlamadığını söyledi, sonra şöyle açıkladı: `if (a < b && 0 > 1 && ...)` gibi AND'lerle bağlanmış bir şart değerlendirilirken ifadeler sırayla ele alınır. Bunlardan biri yanlış çıkarsa diğerlerine bakılmaz, çünkü AND'in tanımı gereği hepsinin doğru olması gerekir. Benzer şekilde OR zincirinde bir terim doğru çıkarsa (yukarıdaki son örnekte olduğu gibi) gerisine bakmaya gerek kalmaz.

Hoca kendi deneyiminden bir örnek verdi: büyük-eşit yazması gereken yere yalnız küçük yazmış, program çalışmamış. Hata ayıklayınca o şartın sürekli yanlış olduğu ve bu yüzden diğer şartlara hiç bakılmadığı görülmüş.

Bir öğrencinin `y - y` ile ilgili sorusuna hoca şöyle cevap verdi: `y - y` ve `x - x` sıfırdır; işlem önceliğine göre 0 ile 0'ın AND'i 0 olur, 1 olmaz. Sonucun 1 olması ile ifadenin `if` içinde kullanılması farklı şeylerdir; değil (`!`) koyulacaksa en temizi parantezlerle açıkça yazmaktır. <!-- BELİRSİZ: sorunun tam metni altyazıdan çıkmıyor (00:52:28-00:53:01) -->

> **Hocanın vurgusu:** Olimpiyat sorularında ya da sınav tarzı sorularda ifadeler birbirine karıştırılıp "sonucu nedir" diye sorulabilir. Ama bir derleyicinin bütün kurallarını ezberlemek zorunda değiliz; genel bilinen kuralları uygulamak ve parantez kullanmak yeterlidir.

## 8. Bit Düzeyi Operatörler

Bit düzeyi operatörler, bit seviyesinde temel mantık işlemlerinin yapılmasını sağlar. Mikroişlemci dersinde ve Assembly'de de karşılaşılır; gömülü sistemlerde ve çeşitli algoritmalarda kullanılır.

### 8.1 AND, OR, XOR, tümleyen

`5 & 6` işlemi için iki sayı 8 bitlik ikilik olarak yazılır:

```text
  5 = 0000 0101
  6 = 0000 0110
  ------------- AND
      0000 0100 = 4
```

AND'de iki bit de 1 ise sonuç 1, en az biri 0 ise sonuç 0'dır. XOR (C'de şapka operatörü `^`) genelde pek bilinmez: bitler aynıysa 0, farklıysa 1 verir.

```text
  5 = 101
  6 = 110
  ------- XOR
      011 = 3
```

Tümleyen operatörü `~` bütün bitleri ters çevirir. Hoca bunu mantıksal değil operatörüyle karşılaştırdı: `a = 5` iken `b = !a` doğrudan `b`'yi 0 yapar. Ama `b = ~a` dersek `00000101`'in bitleri çevrilerek `11111010` elde edilir; sonuç 0 değil, sıfırdan farklı bir değerdir. (Ajanın denemesinde 32 bitlik int için `~5 = -6`.)

### 8.2 Kaydırma

Sola kaydırma ikiyle çarpma, sağa kaydırma ikiye bölme gibidir. Bütün bitler birer basamak kaydırılır; kayan bit başa dönmez, boşalan yere 0 ile besleme yapılır.

- `5 << 1`: `0101` → `1010` = 10. Bir daha kaydırılırsa 20, bir daha 40 olur. Yeteri kadar kaydırılırsa 1'ler dökülür ve sonunda sıfır elde edilir.
- 16 bit üzerinde `255 >> 1`: sekiz tane 1'den biri düşer, yedi tane 1 kalır → 127. `255 >> 3`: beş tane 1 kalır → 31.
- `8 << 10`: sonuç $2^{13} = 8192$.
- 16 bitlik işaretli tamsayıda `1 << 15`, en soldaki işaret bitine gelir ve $-2^{15}$ değerini verir.

Hoca negatif bir sayının (-5) iki kez sağa kaydırılmasında başa iki sıfır geldiğini ve sonucun $2^{13}$ civarında büyük bir pozitif sayı olduğunu söyledi. <!-- BELİRSİZ: slayttaki ifade ve sonuç karelerde yok; altyazıdaki "2 üzeri 13 - 1" değeri doğrulanamadı (00:59:38) -->

> **Ek bilgi (derste anlatılmadı):** Negatif bir işaretli sayının sağa kaydırılması C'de uygulamaya bağlıdır. gcc gibi derleyiciler aritmetik kaydırma yapar ve işaret bitini korur (ajanın denemesinde 16 bitlik `short` için `-5 >> 2 = -2`). Başa sıfır gelen mantıksal kaydırma ise `unsigned` türde olur (16 bitte `0xFFFB >> 2 = 16382`).

### 8.3 Onaltılık gösterim ve tablo örneği

Bir sayının onaltılık (hexadecimal) değeri ikilik olarak yazılırken her onaltılık basamak dört bite karşılık gelir: `0x24D6` için 2, 4, D, 6 basamakları sırayla `0010`, `0100`, `1101`, `0110` olur. Slayttaki tablo (ekrandan, 01:00:00):

| İfade | Onaltılık | İkilik |
|---|---|---|
| 9430 | `0x24D6` | `00100100 11010110` |
| 5722 | `0x165A` | `00010110 01011010` |
| 9430 & 5722 | `0x0452` | `00000100 01010010` |
| 9430 \| 5722 | `0x36DE` | `00110110 11011110` |

AND'de yalnız iki sayıda da 1 olan bitler, OR'da en az birinde 1 olan bitler 1 kalır. Değerler ajan tarafından gcc ile doğrulandı. Slaytta XOR ve NOT örnekleri de vardı.

### 8.4 Bit düzeyi atama operatörleri

`&=`, `|=`, `^=`, `<<=`, `>>=` gibi operatörlerde önce ilgili bit işlemi yapılır, sonra atama yapılır: önce sağa ya da sola kaydırılır, sonra sonuç değişkene atanır. Bunlar atama operatörüyle aynı öncelik durumundadır.

## 9. Cast, sizeof ve Koşul Operatörü

### 9.1 Cast

Cast operatörü bir tipten diğerine açık (explicit) dönüşüm yapar; genellikle float'tan integer'a ve integer'dan float'a dönüştürürken kullanılır. Slayttaki ilk örnekte `3 / 2` iki tamsayının bölümüdür (3.0 değil), sonuç 1'dir. Gerçek değer (1.5) isteniyorsa 3'ü ya da 2'yi floating point'e dönüştürmek, ya da 3'ü `3.0` olarak yazmak yeterlidir.

### 9.2 sizeof

Slayttaki örnekte `sizeof(3 + 5)` için önce `3 + 5` hesaplanır, sonucun integer olduğu bulunur ve integer türünün boyutu döndürülür. Aynı şey `short` ile de yapılır. Bu operatör ilerleyen haftalarda çok kullanılacak.

### 9.3 Koşul operatörü

Koşul operatörü C'deki tek üçlü operatördür ve sık kullanılan bir `if-else` biçiminin kısa yazımıdır (ekrandan, 01:20:00):

| Operatör | Sembol | Biçim | İşlem |
|---|---|---|---|
| conditional | `?:` | `a ? b : c` | `a` sıfırdan farklıysa sonuç `b`, değilse `c` |

Sonuç bir değişkende saklanmak istenirse `x = a ? b : c` yazılır. Örnek:

```c
if (x < y)
    z = x;
else
    z = y;
```

yerine

```c
z = ((x < y) ? x : y);
```

`x`, `y`'den küçükse `z`'ye `x`, değilse `y` atanır. Böylece iki sayıdan küçüğünü bulma gibi işlemler uzun uzun `if` yazmadan tanımlanabilir.

## 10. Bellekle İlgili Operatörler

- **`&` (ampersant, adres operatörü):** bellekteki bir elemanın adresini verir; işaretçilerde çok kullanılacak.
- **`*` (dereferans):** bir adresteki değeri getirir.
- **`[]`:** dizinin bir elemanına erişir.
- **`.` (nokta):** bir yapının (structure) üyesine doğrudan, değer yoluyla erişir.
- **`->` (ok):** bir yapının üyesine işaretçi yoluyla erişir.

Bu operatörlerin önceliği şimdiye kadar görülen operatörlerden yüksektir, çünkü önce oradaki değer elde edilir, sonra o değer üzerinde toplama, çıkarma yapılır. Örneğin önce dizinin beşinci elemanına gidilir, sonra o eleman üzerinde işlem yapılır. Köşeli parantezin içine `x[a + 3]` ya da `x[i++]` gibi bir aritmetik ifade de yazılabilir; bu durumda önce parantezin içi hesaplanır.

## 11. Akış Kontrolü: if ve switch

### 11.1 if

`if` deyimi bir şarta göre programın akışını kontrol eder. Parantez içindeki ifade bir şart ifadesidir; birden fazla önerme de yazılabilir.

```c
if (expression)
    statement1;
statement2;
```

Şart doğruysa `statement1` çalışır; yanlışsa doğrudan `statement2`'ye geçilir. `statement2` şart doğru da olsa yanlış da olsa çalışır. Şart doğruysa bir şey, yanlışsa başka bir şey yapılacaksa ya da doğru durumda birden fazla işlem yapılacaksa küme parantezleri ve `else` kullanılır: şart doğruysa `statement1`, yanlışsa `statement2` çalışır; ardından gelen `statement3` her iki durumda da çalışır.

İç içe `if`'te bir `if`'ten hemen sonra başka bir `if` gelir: "bu şart doğruysa ikinci bir şartı sına" anlamındadır. İçerideki `if`'in de `else`'i olabilir; önce içteki `if`'in `else`'i yazılır, sonra dıştaki `if`'e ait `else if` ya da `else` eklenir. Parantezlerle dikkatli kullanmak gerekir; alıştıktan sonra zor değildir.

### 11.2 switch

`switch`, çok durumlu `if`'leri kısaltmak, daha kompakt yazmak için kullanılır. Küme parantezi açılır, farklı `case`'ler yazılır: 1 ise, 2 ise, ... ya da `default` ise yapılacaklar. Slayttaki akış diyagramı ve kurallar (ekrandan, 01:25:00):

- `switch` ifadesi değerlendirilir. Case etiketlerinden biriyle eşleşirse akış eşleşen etiketin ardındaki deyimle devam eder.
- Hiçbir case etiketi eşleşmezse akış, varsa `default` etiketinden devam eder.
- İki case etiketi aynı değere sahip olamaz.
- `default`'un son etiket olması gerekmez, ama sona koymak iyi stildir. `default` hiç konmasa da olur.

Bir case bittikten sonra programın alttaki case'lere girmemesi için `break` kullanılır; `break` ile `switch`'ten çıkılır ve program `switch`'in altından devam eder. Hoca, `switch`'i uzun uzun anlattığını ama sınavda `switch` kodu sormadığını, ihtiyaç olduğunda zaten kullanılan bir yapı olduğunu söyledi.

## 12. Döngüler: while, do-while, for

### 12.1 while

`while`, arama işlemi gibi tekrarlı işler için kullanılır; arama ve sıralama algoritmaları genelde ilk örneklerdir. Slayttaki tanım (ekrandan, 01:30:00): önce ifade değerlendirilir; sıfırdan farklıysa deyim çalışır. Deyim çalıştıktan sonra kontrol `while`'ın başına döner ve işlem tekrarlanır. İfade sıfır olana kadar bu böyle sürer.

Hoca akışı çizerek iki özelliği vurguladı:

- Program `while`'a geldiğinde şart yanlışsa döngüye hiç girmeden devam eder. Yani `while`'da döngüye **hiç girmeme** olasılığı vardır.
- **Soru:** Döngüye girdik, nasıl çıkarız? **Cevap:** Ancak şart bozulduğunda. Şartın ne zaman bozulacağı belli değildir: bir iterasyonda da bozulabilir, sonsuza kadar da gidebilir. Şarttaki ifade hiç bozulmazsa sonsuz döngüye girilir.

Bu yüzden `while`, ne zaman biteceği, kaç adım süreceği belli olmayan algoritmalar için kullanılır. Hoca "arama" kavramını genişletti: yalnız bir sayı dizisinde bir sayının yerini bulmak değil, bir denklemin optimum değerlerini (yerel ya da global maksimum) bulmak, bir şeyin en küçüğünü ya da en büyüğünü bulmak da aramadır. Problem, arama uzayının sonuna gelmeden çıkmaya imkân veriyorsa (örneğin bir elemanın varlığını, ilk karşılaşmayı (first occurrence) bulmak) `while` kullanılır. Bir dizinin en küçük elemanını bulmak ise farklıdır, çünkü baştan sona bütün elemanlara bakmak gerekir.

Hoca, `for`'u okuyan birinin döngünün başlangıç ve bitişini bildiği için onu `while`'dan farklı analiz ettiğini söyledi. Arama probleminde `for`'u `while` gibi yazmak önerilmez: "for'u while gibi yazacaksan while döngüsünü niye yazmış insanlar?" İki döngü okuyucuya farklı mesaj verir.

### 12.2 do-while

`while`'da döngüye hiç girmeme olasılığı vardır. Döngü gövdesinin **en az bir kez** çalışması isteniyorsa `do-while` kullanılır:

```c
do {
    statement;
} while (expression);
```

`while (...)` satırının sonunda noktalı virgül vardır; hoca bunu C'de döngüden sonra noktalı virgül gelen tek istisna olarak niteledi. Burada şart sonradan sınandığı için gövdenin en az bir kez çalışacağı söylenmiş olur.

Hocanın örneği: bir e-posta hesabına girerken en az bir kez şifre girmeniz gerekir. Doğru girerseniz devam edersiniz, yanlış girerseniz tekrar istenir; en fazla beş deneme hakkı verilip sonra sistem kilitlenebilir. Bu, basit anlamda bir `do-while` mekanizmasıdır. Hoca, bazı soruların öğrencinin `while`, `for` ya da `do-while`'dan uygun olanı seçip seçemediğini ölçmek için sorulduğunu da söyledi.

### 12.3 for

`for` döngüsü **başlangıç noktası, bitiş noktası ve adım sayısı belli olan** döngüdür. Slayttaki akış (ekrandan, 01:40:00):

- Önce `expression1` (ilklendirme) değerlendirilir. Burada birden fazla ilklendirme olabilir; bu kısım boş da bırakılabilir (örneğin `i = 0;` döngüden önce yazılıp `for (; i < 10; ...)` denebilir).
- Sonra `expression2` değerlendirilir; bu şart kısmıdır, `while`'daki şartın aynısıdır. Yanlışsa kontrol `for`'dan çıkar; doğruysa deyim çalışır. Birden fazla şart `&&`, `||` ile eklenebilir.
- Deyim çalıştıktan sonra `expression3` değerlendirilir; bu kısım şarta müdahale eder. Yazılması zorunlu değildir, döngünün içinde bir yerde de yazılabilir.
- Sonra döngü `expression2`'yi yeniden sınamaya döner.

### 12.4 Örnek: for döngüsünün izlenmesi

Hoca şu kodu yazıp `a` ve `i`'nin değerlerini adım adım izledi (ekrandan, 01:45:00):

```c
a = 0;
for (i = 0; i < 5; i++) {
    a = a + i;
}
printf("%d %d", a, i);
```

| Adım | `i` | `i < 5`? | `a = a + i` |
|---|---|---|---|
| 1 | 0 | doğru | 0 |
| 2 | 1 | doğru | 1 |
| 3 | 2 | doğru | 3 |
| 4 | 3 | doğru | 6 |
| 5 | 4 | doğru | 10 |
| - | 5 | yanlış | döngüye girilmez, `a = 10` |

Sırayla: önce ilklendirme (`i = 0`), sonra şart sınanır; doğru olduğu için gövdeye girilir ve `a` `i` kadar artırılır. Gövde bitince `i++` yapılır ve yeniden şarta dönülür. `i` 4'ten 5'e çıktığında `5 < 5` yanlıştır, döngüye girilmez. Ekrana `10 5` yazılır (ajan tarafından derlenip denendi). `i` döngüden önce tanımlandığı için döngü bittikten sonra da yaşamaya devam eder; bu yüzden son artırmada elde edilen 5 değeri kalır, oysa 5 gövdede hiç kullanılmamıştır. Hoca bu tür analizin ayrık matematikte algoritma analizi kısmında da anlatılacağını söyledi.

> **Ders sonrası not:** Hoca döngünün başlangıç 0, bitiş 5 olduğu için "n + 1 defa" gerçekleşeceğini söyledi. Bu örnekte şart 6 kez sınanır, gövde ise 5 kez ($i = 0, 1, 2, 3, 4$) çalışır.

> **Ders sonrası not:** Hoca C'de `for (int i = 0; ...)` yazımının kesinlikle yasak olduğunu, bunun C++'ta bulunduğunu söyledi. Bu kural C89/C90 için geçerlidir; C99 ve sonraki standartlar döngü başlığında değişken tanımına izin verir. Derste kullanılan derleyici büyük olasılıkla eski standart modunda çalıştığı için hata veriyordu.

## 13. Boş Deyim, break, continue ve goto

### 13.1 Boş deyim (null statement)

`for` ya da `if` başlığının sonuna noktalı virgül konursa ne olur? Slayttaki açıklamaya göre `for` döngüsünün gövdesi atlanabilir; başlığın ardından konan noktalı virgül, şart doğru olduğu sürece boş bir deyimin (null statement) işletilmesine yol açar ve altta yazılan gövde döngünün parçası olmaz. Hoca bunun işletim sistemleri dersinde semafor ve bekleme konularında karşılarına çıkacağını söyledi: "bir şart doğru olduğu sürece bekle" gibi.

### 13.2 break, continue, goto

Slayttaki tanımlar (ekrandan, 01:50:00):

- **`break`:** `switch`'te case'lerden çıkmak için kullanılır. Bir döngüde kullanılırsa kontrol döngüden sonraki deyime atlar. Örnek: `for (i = 0; i < 100; i++)` içinde `i == 10` olunca `break` yapılırsa döngü biter, bir sonraki satırdan devam edilir.
- **`continue`:** döngünün başına normalden erken dönmeyi sağlar; döngünün o adımının geri kalanı atlanır, artırma kısmı yapılır ve döngü sonraki adımdan devam eder.
- **`goto`:** daha ilkel dillerde gereklidir. Hoca Pascal'da çok kullanıldığını, Assembly'de de karşılaşılabileceğini söyledi. Program akışı normalde hep aşağı doğru gider; `goto` ile şart yanlışsa yukarı dönülerek gizli bir döngü (bir tür gizli `do-while`) kurulabilir. `do-while` yapısı olduğu için `goto`'ya gerek yoktur; örneğin program bittikten sonra "kapatmak istiyor musunuz?" diye sorup başa dönmek `do-while` ile yapılır. Bazı gömülü sistemlerde hâlâ kullanılabilir.

Slaytta `continue` ve `goto` için "Please do NOT use it in any of your C programs" yazıyor.

> **Hocanın vurgusu:** Bu derste `break` yalnız `switch` içinde kullanılır; döngülerde `break`, `continue` ve `goto` kullanılmaz. Gerekçe: algoritma analizi ve izleme (trace) sırasında bu deyimler kullanışlı değildir. Program yazarken kolaylık, belki anlaşılırlık sağlarlar ama analizi zorlaştırırlar. `break` için zaten bir `if` şartı yazılacaktır; o şart döngünün şart kısmına eklenirse bunlara gerek kalmaz.

> **Ders sonrası not:** Hoca `switch` anlatırken "diğer döngülerde break veya continue kullanılmıyor" dedi. Bu bir dil kısıtı değil, dersin kodlama kuralıdır: C dili `break` ve `continue`'yu bütün döngülerde kabul eder; hoca da dersin sonunda bunların `for` ve `while` içinde çalıştığını gösterdi.

## 14. Kod Örnekleri: scanf, switch ile Hesap Makinesi, break ve continue

Dersin son bölümünde hoca Dev-C++ üzerinde kod yazdı. Önce öğrencilere `switch`'i önceki derslerde görüp görmediklerini sordu; görmedikleri için `switch`, `while`, `break` ve `continue` ile ilgili örnekler yapıldı. Hedef: toplama, çıkarma, çarpma ve bölme yapan bir hesap makinesi menüsü.

### 14.1 Tanımlar ve scanf'te adres operatörü

İlk sürümde `printf("İki sayı giriniz");` satırından sonra `int a, b;` yazıldı (ekrandan, 01:55:00). Hoca tanımlamaların fonksiyonun en başında yapılması gerektiğini, unutulursa bir üst satıra çıkıp yazmanın zor olmadığını söyledi.

Ardından `scanf("%d %d", &a, b)` yazılıp `b`'nin önündeki `&` bilerek unutuldu. Bu sık yapılan bir hatadır; başka dillerden gelen alışkanlıktan ya da az kod yazmaktan kaynaklanabilir. Program 6 ve 5 girildiğinde çöktü (ekrandan, 02:00:00). Açıklama:

- Girilen 6'nın `a` değişkeninin bellekteki yerine yazılması gerekir. C'de derleyici çok iş yapmaz, birçok sorumluluk programcıdadır; `a`'nın adresini kendiniz vermeniz gerekir. Başka dillerde girişte değişkenin adresine referans mekanizmasıyla ulaşılır, C'de böyle bir şey yoktur.
- C değişken tanımlandığında o bellek hücresini varsayılan olarak temizlemez; içinde o anda ne varsa (çöp değer) o kalır. Yazdırınca `a`'da 1, `b`'de 0 görüldü; çok büyük sayılarla da karşılaşılabilir.
- `&` olmadan `b`'nin içindeki değer (0) adres gibi kullanılır ve `scanf` belleğin 0 numaralı hücresine yazmaya çalışır. İşletim sistemi olan bir bilgisayarda aynı anda birçok program çalışır; işletim sistemi "başka bir sürecin adres alanına erişmeye çalışıyorsun" diye buna izin vermez. Hoca bunu başkasının evine girmeye çalışmaya benzetti.

Sonra değerler ve adresler `printf("a:%d &a:%p b:%d &b:%p\n", a, &a, b, &b);` ile yazdırıldı (ekrandan, 02:05:00). Adresler için `%d` değil, işaretçi biçimi `%p` kullanılır. Çıktıda `b`'nin adresi `a`'nınkinden 4 bayt küçüktü (sonraki bir çalıştırmada ekranda `&a:000000000023FE3C`, `&b:000000000023FE38` görünüyor; ekrandan, 02:15:00): `b` bellekte `a`'dan önce gelir ve `b`'nin adresine 4 bayt (bir int) eklenince `a`'nın adresine ulaşılır, yani değişkenler bellekte ardışıktır. `&` düzeltilince 5 ve 7 değerleri aynı adreslere yerleşti.

**Soru:** Adres operatörünü her değişken için kullanacak mıyız? **Cevap:** Hayır. Dizilerde dizinin taban adresi için ve karakter dizilerinde (string) kullanılmaz; dizinin belirli bir elemanı için kullanılır. Bu, diziler konusunda görülecek.

> **Hocanın vurgusu:** Bu dersin temeli bellek yönetimini öğretmektir; değişkenin değeri ile adresi arasındaki farkı görmek bu yüzden önemlidir. Menülü bir program yazarken menüyü güzel tasarlamak programın anlaşılırlığını artırır.

### 14.2 switch ile işlem seçimi ve tampondaki Enter

Operatör `char op;` olarak tanımlandı ve `scanf("%c", &op);` ile okundu. Ardından `switch (op)` ile her operatör için sonuç yazıldı (ekrandan, 02:10:00). Hata durumları için `default` eklendi.

Program çalıştırılıp `4 6` girilince operatör sorulmadan doğrudan "Hatalı giris" yazıldı. Sebep: iki sayı girildikten sonra Enter'a basılması giriş akışına (input stream) bir karakter daha ekler. Sıradaki `scanf("%c", ...)` bir karakter okumak istediği için bu Enter karakterini alır; o da hiçbir case ile eşleşmediği için akış `default`'a düşer ve program `return 0` ile biter. Çözümler:

- Giriş akışını temizleyen fonksiyonlar (ilerleyen haftalarda görülecek).
- Biçim dizesine boşluk koymak: `scanf(" %c", &op);`. Baştaki boşluk Enter'ı (boşluk karakterlerini) yutar, ardından `%c` yeni karakteri okur.

Düzeltmeden sonra `5` ve `8` girilip `*` seçildiğinde "Sonuc:40" yazdı.

Ajan aynı hatayı şu küçük programla doğruladı (`4 6`, Enter, `+` girdisiyle çıktı `Hatalı giris`):

```c
#include<stdio.h>
int main(){
    int a, b; char op;
    scanf("%d %d",&a,&b);
    scanf("%c",&op);
    switch(op){
        case '+': printf("Sonuc:%d\n",a+b); break;
        default: printf("Hatalı giris\n");
    }
    return 0;
}
```

### 14.3 break olmadan switch (fall-through)

Hoca bütün `break`'leri yorum satırı yaptı. `+` girildiğinde sırayla toplama, çıkarma, çarpma ve bölme sonuçlarının hepsi ve `default`'taki mesaj yazıldı. Çünkü `+` case'i sağlandıktan sonra akış alttaki bütün case'lerden geçer. `*` girildiğinde ise çarpma sonucu ile ondan sonraki case'ler ve `default` çalıştı: akış nerede eşleştiyse oradan devam eder. Bu yüzden her case'in sonunda `break` gerekir; bu derste `break`'in kullanımına yalnız burada izin verilir.

### 14.4 do-while ile "devam etmek ister misiniz?"

Hoca, program bittikten sonra kullanıcıya devam edip etmeyeceğinin sorulmasını istedi. `char devam;` eklendi ve `scanf("%c", &devam)` ile `E` ya da `H` okundu. Burada da önceki girişten kalan Enter yüzünden program cevap beklemeden bitti; çözüm yine `scanf(" %c", &devam)` oldu.

Hangi döngünün uygun olduğu soruldu. Program en az bir kez çalışacağı için `while` sağlıklı değildir; `do-while` daha güzel bir çözümdür. Menü `do { ... } while (devam == 'E');` içine alındı ve sonuna "Exit" mesajı eklendi. Hoca `scanf("%d %c %d", &a, &op, &b)` ile `4 + 7` gibi tek satırlık bir giriş biçimine geçti (ekrandan, 02:15:00, 02:30:00). Programın son hâli karelerden derlenerek şöyledir:

```c
#include<stdio.h>
int main(){
    int a, b;
    char op, devam;
    do{
        printf("İki sayı giriniz");
        printf("Operator giriniz<+,-,*,/>");
        printf("orn 4 + 5\n");
        scanf("%d %c %d", &a, &op, &b);
        switch(op){
            case '+':
                printf("Sonuc:%d", a+b);
                break;
            case '-':
                printf("Sonuc:%d", a-b);
                break;
            case '*':
                printf("Sonuc:%d", a*b);
                break;
            case '/':
                printf("Sonuc:%d", a/b);
                break;
            default:
                printf("Hatalı giris");
        }
        printf("\nProgram bitti, devam etmek ister misiniz?\n <E-H>\n");
        scanf(" %c", &devam);
    }while(devam == 'E');
    printf("Exit\n");
    return 0;
}
```

Ekrandaki sürümde döngünün başında `a`, `b` ve adresleri de yazdırılıyordu; ilk turda `a` ve `b` ilk değer almadığı için bu satır çöp değer gösterir, burada çıkarıldı. Kod ajan tarafından `gcc -Wall` ile uyarısız derlendi; `4 + 7`, `E`, `5 * 8`, `H` girdileriyle sırayla "Sonuc:11", "Sonuc:40" ve "Exit" yazdı.

Hoca ikinci turda `%d` ile başlayan okumada sorun yaşanmadığını, çünkü tamsayı okurken boşluk ve Enter karakterlerinin atlandığını, sorunun yalnız karakter okumada çıktığını belirtti. Ödev ya da projede böyle bir menüyle "tekrar oynamak / baştan başlamak ister misiniz?" diye sormanın, pencerenin kapatma düğmesinin yaptığı işi komut satırında kodla yapmak olduğunu söyledi. Şaka olarak, dışarıya bir `do-while` daha koyup "Emin misiniz?" diye sormanın da mümkün olduğunu ekledi.

### 14.5 for içinde break ve continue

Son örnekte hoca `break` ile `continue` farkını gösterdi (ekrandan, 02:25:00). Aşağıdaki kod, karedeki koda hocanın sonradan yaptığı düzenleme (continue sürümünde 3'ün yazılmaması için `if`'in `printf`'ten önceye alınması) eklenerek yazıldı:

```c
#include<stdio.h>
int main(){
    int i;
    printf("break\n");
    for(i=0;i<5;i++){
        printf("%d - ",i);
        if(i==3)
            break;
    }
    printf("\ncont\n");
    i=0;
    for(;i<5;i++){
        if(i==3)
            continue;
        printf("%d - ",i);
    }
    printf("\n");
    return 0;
}
```

Çıktı (ajan tarafından derlenip denendi):

```text
break
0 - 1 - 2 - 3 - 
cont
0 - 1 - 2 - 4 - 
```

`break` sürümünde 0, 1, 2 ve 3 yazılır, 3'ten sonra döngüden çıkılır. `continue` sürümünde 3 atlanır, 4 yazılır, 5'e gelinince şart bozulur. Hoca üçüncü bir sürümde `break`/`continue` şartını döngünün kendisine taşıyarak aynı işi bu deyimler olmadan yaptı; o sürümde döngüde 0, 1, 2, 3, 4 yazıldı ve döngüden sonra 5 yazdırıldı. <!-- BELİRSİZ: üçüncü sürümün kodu karelerde yok (02:26:27-02:27:24) -->

Hoca, `break` ve `continue`'nun yalnız `for` ve `switch`'te değil, `while` gibi diğer döngülerde de kullanılabildiğini ayrıca gösterdi; `while (i < 5)` örneğinde çıktı 0, 1, 2 oldu. <!-- BELİRSİZ: while örneğinin kodu karelerde yok (02:28:18-02:29:14) -->

> **Hocanın vurgusu:** `break`/`continue` konusunda sınavda doğrudan kod sorulmayabilir ama ekran çıktısı sorulabilir. Kaynak dosya `.c` uzantısıyla kaydedilmelidir.

Ardından hoca global değişken konusuna değindi: ilerleyen haftalarda fonksiyonlarda yerel ve global değişkenler görülecek, ama değişkenler global tanımlamak yerine parametre geçişiyle aktarılmalıdır. İç içe `if` ve iç içe döngüler için ise yapılacak şey küme parantezlerini uygun biçimde açıp kapatmaktır; bunların kaç adım çalıştığına dair analiz ayrık matematik ve benzeri derslerde anlatılmaktadır.

## Örnek Sorular

### Soru 1 (ekrandan, 00:30:00)

`int m = 3, n = 4; float x = 2.5, y = 1.0;` için aşağıdaki ifadelerin sonucu nedir? (Her ifade başlangıç değerleriyle ayrı ayrı değerlendirilsin.)

```c
m += n + x - y
m /= x * n + y
n %= y + m
x += y -= m
```

> **Çözüm:** Derste verildi (bölüm 4.1). `m = (m + ((n + x) - y))` → 8.5, int'e atanınca `m = 8`. `m = (m / ((x * n) + y))` → 3 / 11.0 ≈ 0.27, `m = 0`. `x += y -= m` sağdan sola: `y = -2.0`, `x = 0.5`. `n %= y + m` ise `%` float operant kabul etmediği için derlenmez (bu kısım derste verilmedi; gcc ile denendi).

### Soru 2 (ekrandan, 00:40:00)

Aşağıdaki iki programın çıktısı nedir?

```c
int j=5, k=5;
printf("j: %d\t k : %d\n", j++, k--);
printf("j: %d\t k : %d\n", j, k);
```

```c
int j=5, k=5;
printf("j: %d\t k : %d\n", ++j, --k);
printf("j: %d\t k : %d\n", j, k);
```

> **Çözüm:** Derste verildi. Postfix: `j: 5  k : 5`, sonra `j: 6  k : 4`. Prefix: iki satır da `j: 6  k : 4`.

### Soru 3 (ekrandan, 00:50:00)

`int j=0, m=1, n=-1; float x=2.5, y=0.0;` için ifadeleri öncelik tablosuna göre parantezleyip değerlerini bulun: `j && m`, `j < m && n < m`, `x * 5 && 5 || m / n`, `!x || !n || m + n`.

> **Çözüm:** Derste verildi (bölüm 7.2). `(j) && (m)` = 0; `(j < m) && (n < m)` = 1; `((x * 5) && 5) || (m / n)` = 1; `((!x) || !n) || (m + n)` = 0.

### Soru 4 (ekrandan, 01:00:00)

9430 ve 5722 sayılarının onaltılık ve ikilik gösterimlerini yazıp `9430 & 5722` ve `9430 | 5722` sonuçlarını bulun.

> **Çözüm:** Derste verildi. 9430 = `0x24D6` = `00100100 11010110`, 5722 = `0x165A` = `00010110 01011010`. AND = `0x0452` = `00000100 01010010`; OR = `0x36DE` = `00110110 11011110`.

### Soru 5 (derste sözlü, 00:55:20)

`5 & 6` ve `5 ^ 6` işlemlerinin sonucu nedir?

> **Çözüm:** Derste verildi. `101 & 110 = 100` = 4; `101 ^ 110 = 011` = 3.

### Soru 6 (ekrandan, 01:45:00)

Aşağıdaki kodun çıktısı nedir?

```c
a = 0;
for (i = 0; i < 5; i++) {
    a = a + i;
}
printf("%d %d", a, i);
```

> **Çözüm:** Derste verildi (bölüm 12.4). `a` sırayla 0, 1, 3, 6, 10 olur; `i` 5 olunca döngü biter. Çıktı `10 5`.

### Soru 7 (derste sözlü, 02:15:37)

"Devam etmek ister misiniz?" diye soran bir menüde hangi döngü en uygundur?

> **Çözüm:** Derste verildi. Program en az bir kez çalışacağı için `do-while`.

### Soru 8 (ekrandan, 02:25:00)

Bölüm 14.5'teki programın `break` ve `continue` kısımlarının ekran çıktısı nedir?

> **Çözüm:** Derste verildi. `break`: `0 - 1 - 2 - 3 -`; `continue` (`if` yazdırmadan önce): `0 - 1 - 2 - 4 -`.

## Dersin Toparlaması

Bu derste C'deki ifade türleri, operatörlerin öncelik ve birleşme yönü kuralları ve operatör aileleri (aritmetik, aritmetik atama, artırma/azaltma, virgül, ilişkisel, mantıksal, bit düzeyi, cast, `sizeof`, koşul ve bellek operatörleri) slayt örnekleri üzerinden işlendi. Temel ilke şuydu: önce öncelik, eşit öncelikte birleşme yönü; şüphede parantez. Karmaşık ifadeleri çözmenin yolu, onları yalnız `=` kullanarak açık hâle getirmek ve tip dönüşümlerini (int'e atanan float sonucun kesilmesi gibi) izlemektir.

İkinci bölümde akış kontrolü yapıları (`if`, `switch`, `while`, `do-while`, `for`, boş deyim, `break`, `continue`, `goto`) ve hangi döngünün hangi probleme uygun olduğu tartışıldı. Kod örneklerinde `scanf`'e adres verilmemesinin çökmeye yol açması, değişkenlerin çöp değerlerle başlaması, tampondaki Enter karakterinin `%c` okumasını bozması ve `" %c"` ile çözümü, `break`'siz `switch`'in davranışı ve `do-while` ile tekrarlanan bir menü gösterildi. Hoca, işaretçi aritmetiği, diziler, yapılar, fonksiyonlar ve kapsam (scope) kurallarının ilerleyen haftalarda ele alınacağını belirtti.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
