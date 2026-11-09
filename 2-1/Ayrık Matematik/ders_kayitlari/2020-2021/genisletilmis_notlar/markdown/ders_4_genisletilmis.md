# Ders 4 Genişletilmiş Notu: Kümeler ve Küme İşlemleri, Kartezyen Çarpım, Diziler, Dizgiler ve Sayı Sistemleri

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Bölüme Giriş: Matematiğin Dili
- 2. Küme Kavramı ve Gösterimi
- 3. Sonlu, Sonsuz, Boş ve Evrensel Kümeler
- 4. Eleman Sayısı (Kardinalite)
- 5. Alt Küme, Eşitlik ve Öz Alt Küme
- 6. Kuvvet Kümesi ve Bonus Sorusu
- 7. Küme İşlemleri ve Venn Şemaları
- 8. Küme İşlemlerinin Özellikleri
- 9. Kartezyen Çarpım
- 10. Genelleştirilmiş Birleşim, Kesişim ve İçerme-Dışarma
- 11. Küme İşlemlerini Bit Dizisiyle Programlamak
- 12. Diziler (Sequences)
- 13. Toplam ve Çarpım Gösterimi
- 14. Dizgiler ve Düzenli İfadeler
- 15. Sayı Sistemleri
- Örnek Sorular
- Dersin Toparlaması

## 1. Bölüme Giriş: Matematiğin Dili

Ders Zoom üzerinden yapıldı. Kaydın ilk dakikaları selamlaşma ve sohbetle geçer; asıl anlatım yaklaşık 00:08:00'de başlar. Hoca bu hafta kitabın 4. bölümüne geçildiğini söyledi. Bölüm uzun olduğu için iki haftaya yayılabilir. Ardından algoritmalar konusu gelecek, daha sonra da kromatik polinomlar ya da ağaçlar, çizgeler (graphs) ve otomatlar.

Hoca bölüme başlarken bu konuların "matematiğin dili" olduğunu söyledi. Bölümde kümeler, fonksiyonlar, fonksiyonların bazı özellikleri, Hasse diyagramları ve Warshall algoritması gibi kavramlar var. Bunların birçoğu liseden tanıdık gelebilir. Ama hoca bu derste her zaman şunu soracağını söyledi: Bu kavramları kodlamaya kalkarsak nasıl kodlarız? Dersin amacı, algoritmik düşünmeyi bir adım ileri taşımaktır.

<!-- BELİRSİZ: 00:08:37'de altyazıda "Marshall algoritması" geçiyor; kitabın bu bölümündeki büyük olasılıkla Warshall algoritmasıdır. -->

## 2. Küme Kavramı ve Gösterimi

Küme (set), ayrık nesnelerden oluşan topluluktur. Kümenin içindeki nesnelere eleman (element) denir. Önemli olan, bir kümenin nasıl gösterildiğidir.

İlkokuldan beri öğretilen gösterim liste gösterimidir. Elemanlar süslü parantez içinde yazılır:

$$A = \{1, 3, 5, 7\}$$

Kümenin adı her zaman büyük harfle yazılır. Elemanlar küçük harf olabilir.

Hoca, matematik kitaplarında ya da akademik yayınlarda kümelerin bu "ilkokul vari" biçimde gösterilmediğini söyledi. Örneklerde liste gösterimi kullanılır. Ama bir kitap ya da bilimsel metin yazılıyorsa tanım gösterimi (set-builder notation) tercih edilir:

$$A = \{x \mid x = 2k + 1,\ 0 \le k \le 3\}$$

Bu ifade şöyle okunur: $A$ kümesi öyle $x$'lerden oluşur ki $k$, 0 ile 3 kapalı aralığındadır ve $x = 2k + 1$'dir. Hoca $\le$ işaretinin "küçük eşittir" diye değil, "kapalı aralık" olarak okunduğunu belirtti. Elemanları bulmak için $k$'ye sırayla değer verilir:

- $k = 0$ için $x = 1$
- $k = 1$ için $x = 3$
- $k = 2$ için $x = 5$
- $k = 3$ için $x = 7$

Sonuç, liste gösterimiyle aynıdır: $\{1, 3, 5, 7\}$.

**Soru:** $k$'nin tam sayı olduğunu kümenin içinde belirtmek gerekmiyor mu? **Cevap:** Hoca bunun doğru olduğunu söyledi ve slayta $k \in \mathbb{Z}$ şartının eklenmesi gerektiğini belirtti. Aralık zaten sınırlandırıldığı için "tam sayılar kümesinin elemanıdır" demek yeterlidir:

$$A = \{x \mid x = 2k + 1,\ k \in \mathbb{Z},\ 0 \le k \le 3\}$$

Bu şart yazılmazsa $k$ gerçel (real) bir sayı da olabilir. 0 ile 3 arasında sonsuz sayıda gerçel sayı vardır. O zaman küme sonsuz elemanlı olur. Hoca bu noktayı yakalayan öğrenciye teşekkür etti.

## 3. Sonlu, Sonsuz, Boş ve Evrensel Kümeler

### 3.1 Sonlu ve sonsuz kümeler

Kümeler sonlu (finite) ve sonsuz (infinite) diye ikiye ayrılır.

Sonlu küme örneği:

$$B = \{x \mid x \in \mathbb{Z},\ 1 \le x \le 4\}$$

Bu küme $\{1, 2, 3, 4\}$'tür ve sonludur.

Sonsuz küme örnekleri:

- $\mathbb{Z}$: bütün tam sayılar, eksi sonsuzdan artı sonsuza kadar.
- $S = \{x \mid x \in \mathbb{R},\ 0 \le x \le 4\}$: verilen aralıktaki bütün gerçel sayılar.

<!-- BELİRSİZ: 00:13:18'de altyazıda aralık "bir ve dört" diye geçiyor, hemen ardından "sıfır ve dört dahil değildir" deniyor. Kısa nottaki gibi [0, 4] alındı. -->

### 3.2 Kapalı ve açık aralık

Kapalı aralık köşeli parantezle gösterilir: $[0, 4]$ uçları içerir. Normal parantez kullanılırsa $(0, 4)$, 0 ve 4 dahil değildir. Bir uç açık, diğeri kapalı da olabilir: $(0, 4]$ "sıfır açık, dört kapalı" diye okunur; 0 dahil değildir, 4 dahildir.

### 3.3 Boş küme

Boş küme (null set ya da void set) $\emptyset$ ya da $\{\}$ ile gösterilir. Hoca C dilindeki `void` ile benzetme yaptı: C'de bir fonksiyonun `void` olması, parametre döndürmediği anlamına geliyordu. Burada da `void` kümenin boş olduğunu gösterir.

### 3.4 Evrensel küme

Evrensel küme (universal set) $U$, hangi sayılarla çalışılıyorsa o sayıların hepsini içeren kümedir. Örneğin bütün doğal sayılar, bütün gerçel sayılar ya da:

$$U = \{x \mid x \in \mathbb{N},\ 1 \le x \le 10\}$$

### 3.5 $\emptyset$ ile $\{\emptyset\}$ farkı

$$\emptyset \neq \{\emptyset\}$$

Sol taraf yalnızca boş kümeyi gösterir; hiç elemanı yoktur. Sağ taraf ise bir kümedir ve tek elemanı boş kümedir. Yani bir kümenin elemanlarından biri boş küme olabilir. Hoca bu ikisinin eşit olmadığını rahatlıkla söyleyebilmemiz gerektiğini vurguladı.

## 4. Eleman Sayısı (Kardinalite)

Bir kümenin eleman sayısına kardinalite (cardinality) denir. Hoca bu terimi Türkçeye tam çeviremediğini, anlamının "kümenin eleman sayısı" olduğunu söyledi. Farklı kaynaklarda farklı gösterimler vardır:

- $s(A)$: kümenin başına küçük bir $s$ yazılır. Lisede bu gösterim kullanılır.
- $|A|$: iki dik çizgi (pipe) arasında $A$.

$|A| = 5$ yazılmışsa bu, $A$'nın eleman sayısının 5 olduğu anlamına gelir.

> **Hocanın vurgusu:** $|A|$ küme için mutlak değer değildir. Hoca, bir vizede bir öğrencinin bu gösterimi mutlak değer olarak algıladığını iddia ettiğini anlattı. Soruyu okuyan biri $A$'nın bir küme olduğunu zaten görür. Mutlak değer olsaydı $A$'nın $-5$ ya da $+5$ olması gerekirdi; bu bir küme için anlamsızdır.

### 4.1 Sonlu kümelerde eleman sayısı

- $A = \{a, b, c\}$ ise $|A| = 3$.
- $B = \{x \mid x \in \mathbb{N},\ 1 \le x \le 9\}$ ise $|B| = 9$. Sınırlandırma ("$1 \le x \le 9$" kısmı) olmasaydı eleman sayısı söylenemezdi; küme sonsuz olurdu.

### 4.2 Sonsuz kümelerde eleman sayısı

Sonsuz kümelerin eleman sayısını söylemek zordur. Hoca iki durumu ayırdı:

- Doğal sayılar sayılabilir (countable): 1, 2, 3, 4, 5 diye tek tek sayabiliriz.
- Gerçel sayılar sayılamaz (uncountable): 1 ile 2 arasında bile sonsuz sayıda gerçel sayı vardır. 1'den 2'ye bile "tek tek" geçemeyiz.

### 4.3 Derste sorulan eleman sayıları

Hoca öğrencilerden derse sesli katılım beklediğini söyleyerek şu kümelerin eleman sayılarını sordu:

| Küme | Eleman sayısı | Açıklama |
| :-- | :-: | :-- |
| $\{a, b, c\}$ | 3 | Doğrudan sayılır. |
| $\{3, 3, 3, 3, 3\}$ | 1 | Aynı eleman bir kümede bir kez sayılır. |
| $\emptyset$ | 0 | Hiç elemanı yoktur. |
| $\{\emptyset, 2, \{1, 2\}\}$ | 3 | Elemanlar virgülle ayrılır: $\emptyset$, $2$, $\{1, 2\}$. |

Son örnekte hoca "çok dikkatli olun" dedi. Elemanlar virgüllerle ayrılır. Birinci eleman boş küme, ikinci eleman 2, üçüncü eleman $\{1, 2\}$ kümesidir. İç kümenin elemanları ayrıca sayılmaz. Eleman sayısı 3'tür.

Hoca son olarak sonsuz bir küme gösterdi ve böyle bir kümenin eleman sayısı için "sonsuzdur, bir şey söyleyemeyiz" dedi.

<!-- BELİRSİZ: 00:20:09'da eleman sayısı sonsuz denen kümenin tanımı altyazıda geçmiyor. -->

## 5. Alt Küme, Eşitlik ve Öz Alt Küme

### 5.1 Alt küme

$X$ kümesinin bütün elemanları $Y$ kümesinde de varsa $X$'e $Y$'nin alt kümesi (subset) denir. Burada büyük küme $Y$'dir. Gösterimi:

$$X \subseteq Y$$

Hoca bu işaretin okunuşunu şöyle anlattı: Kapsama işaretinin içi (açık ucu) hangi tarafa bakıyorsa o taraf büyük kümedir. "$Y$, $X$'i kapsıyor" diye okunur; yani $X$'in elemanları $Y$'nin içinde de vardır. İşaretin altında çizgi varsa "kapsar eşittir" diye okunur: $X$, $Y$'nin alt kümesidir ve iki küme aynı elemanlara sahip de olabilir.

Bu tanımın matematiksel gösterimi:

$$X \subseteq Y \iff \forall x\ (x \in X \Rightarrow x \in Y)$$

Hoca matematiksel gösterimlerin bazen korkutucu göründüğünü, ama aslında sözlü tanımın aynısı olduğunu söyledi: "Bütün $x$'ler için, $x$ $A$'nın elemanı ise $B$'nin de elemanıdır." Venn şemasında $U$ evrensel kümesinin içinde $B$, onun içinde de $A$ çizilir.

Kapsar eşittir işaretinin neden kullanıldığını hoca şöyle açıkladı: Başta $B$'de yalnız $A$'nın elemanları olabilir. Ama bu, $A$'nın $B$'nin alt kümesi olma özelliğini değiştirmez. Daha sonra $B$'ye başka elemanlar da eklenebilir.

Boş küme her kümenin alt kümesidir.

Diğer temel gösterimler:

- $x \in S$: $x$, $S$ kümesinin elemanıdır.
- $x \notin S$: $x$, $S$ kümesinin elemanı değildir.

### 5.2 Kümelerin eşitliği

İki kümenin eşitliği, alt küme kavramıyla şöyle tanımlanır:

$$X = Y \iff X \subseteq Y \text{ ve } Y \subseteq X$$

Hoca bunu bir önceki dersteki AND ile bağladı: AND'in doğru olması için iki girişin de doğru olması gerekir. $Y$, $X$'i kapsıyor ve $X$ de $Y$'yi kapsıyorsa iki küme eşittir.

> **Ders sonrası not:** Hoca eşitliği anlatırken bir yerde "eleman sayıları eşit demektir" dedi. Doğrusu: iki küme aynı elemanlara sahipse eşittir. Eleman sayılarının eşit olması yetmez; $\{1, 2\}$ ile $\{3, 4\}$ eşit değildir.

**Soru:** Eşitlik tanımında neden iki yön birden yazılıyor? $X \subseteq Y$ eşitliği de kapsıyorsa biri yeterli değil mi? **Cevap:** Hoca önce kapsar eşittir işaretini "veya" gibi düşünmek gerektiğini söyledi: "$Y$, $X$'i kapsıyor veya $X$ ile $Y$ eşit." Kümelerin elemanları bilinmeden bunun hangisi olduğu bilinemez. Örnekle açıkladı: $Y$'nin $X$'i kapsadığı biliniyorsa, dışarıdan $X$'e 1 geldiğinde $Y$'de de 1 vardır; $X$'e 2 geldiğinde $Y$'de de 2 vardır. Ama $Y$'ye 3 geldiğinde $X$'te 3 olmak zorunda değildir. İki küme eşit olsaydı $X$'te de 3 olurdu.

Asıl nokta şudur: Hoca alt küme kavramını anlatıyordu. "$X = Y$" denseydi iki küme zaten eşit olurdu. Ama eşitlik tanımı alt küme kavramıyla yapılacaksa iki yön yazılmalı ve AND ile bağlanmalıdır. Arada AND yerine OR olsaydı bu, kümeler arasındaki eşitliğin tanımı olmazdı. Yalnız "$X \subseteq Y$" yazmak eksik bir tanımdır, çünkü $Y$'de $X$'te olmayan elemanlar da olabilir.

### 5.3 Öz alt küme

$X$ kümesi $Y$'nin alt kümesiyken $Y$ kümesi $X$'in alt kümesi değilse, yani eşitlik yoksa, $X$'e $Y$'nin öz alt kümesi (proper subset) denir:

$$X \subset Y \iff X \subseteq Y \text{ ve } X \neq Y$$

Bu durumda $Y$, $X$'i kapsar ama $X$, $Y$'yi kapsamaz. Yani $Y$'de $X$'te olmayan en az bir eleman vardır.

> **Ders sonrası not:** Hoca öz alt kümeyi anlatırken bir an "X kapsar Y ise X, Y'nin öz alt kümesidir" dedi; yönler karıştı. Doğrusu yukarıdaki tanımdır: $X \subset Y$ ise büyük küme $Y$'dir.

## 6. Kuvvet Kümesi ve Bonus Sorusu

### 6.1 Kuvvet kümesinin tanımı

Bir $X$ kümesinin kuvvet kümesi (power set) $\mathcal{P}(X)$, $X$'in bütün alt kümelerinden oluşan kümedir. Hoca $X = \{1, 2, 3\}$ için kuvvet kümesini adım adım kurdu:

- Boş küme bir elemandır: $\emptyset$.
- Tek elemanlı alt kümeler: $\{1\}, \{2\}, \{3\}$.
- İkili kombinasyonlar: $\{1, 2\}, \{1, 3\}, \{2, 3\}$.
- Üçlü kombinasyon: $\{1, 2, 3\}$.

$$\mathcal{P}(X) = \{\emptyset, \{1\}, \{2\}, \{3\}, \{1,2\}, \{1,3\}, \{2,3\}, \{1,2,3\}\}$$

Kümede 3 eleman olduğu için kuvvet kümesinin eleman sayısı $2^3 = 8$'dir. Genel olarak:

$$|X| = n \Rightarrow |\mathcal{P}(X)| = 2^n$$

Hoca sonra kümeye 4 eklendiğini düşündü. Bu durumda $\{4\}$, $\{1,4\}$, $\{2,4\}$, $\{3,4\}$, sonra $\{1,2,4\}$, $\{1,3,4\}$, $\{2,3,4\}$ ve $\{1,2,3,4\}$ eklenir. Toplam $2^4 = 16$ alt küme olur. Hoca listeyi sayarken 15'te kaldı ve hangisinin eksik olduğunu sordu; eksik olan $\{1, 2, 3, 4\}$ idi.

Özetle kuvvet kümesi; boş küme, tek elemanlı, iki elemanlı, ..., $n$ elemanlı bütün alt kümelerden oluşur.

### 6.2 Diğer kuvvet kümesi örnekleri

Hoca slayttaki örneklerin üzerinden hızlıca geçti:

- $\mathcal{P}(\{a\}) = \{\emptyset, \{a\}\}$: boş küme ve $a$'nın kendisi.
- $\mathcal{P}(\{a, b\}) = \{\emptyset, \{a\}, \{b\}, \{a, b\}\}$: $2^2 = 4$ eleman.
- $\mathcal{P}(\emptyset) = \{\emptyset\}$: yazılabilecek tek eleman boş kümedir.
- $\mathcal{P}(\{\emptyset, \{\emptyset\}\}) = \{\emptyset, \{\emptyset\}, \{\{\emptyset\}\}, \{\emptyset, \{\emptyset\}\}\}$: kümenin birinci elemanı $\emptyset$, ikinci elemanı $\{\emptyset\}$'dir. Alt kümeler boş küme, her elemanın tek başına küme işaretine alınmış hali ve ikisinin birlikte olduğu kümedir.

Hoca son örneği tahtaya yazarken bir an karıştırdı, sildi ve baştan yazdı.

<!-- BELİRSİZ: 00:44:59'da kuvvet kümesinin slayttaki gösterimi altyazıda "250S" diye bozuk geçiyor; büyük olasılıkla $\mathcal{P}(S)$ ya da $2^S$ gösterimidir. -->

### 6.3 Kuvvet kümesini bulan algoritma

Hoca sonra şu soruyu sordu: Bir küme girdi olarak verildiğinde kuvvet kümesini bulan algoritmayı nasıl yazarız? En basit ve en kolay şekilde nasıl yazabiliriz?

Hoca önce akla gelebilecek zorlukları sıraladı. Çıktıda $\emptyset$, $\{1\}$, $\{1, 2\}$ gibi gösterimleri yazdırmak için "stringlerle işlem yapmayı bilmiyorum" diye düşünülebilir. Sayısal düşünülürse de çok fazla kontrol, çok fazla `if` gerekir. Hoca bunları kenara bıraktı ve şu soruyu sordu: Bu derste şimdiye kadar gördüklerimizle bu problemi çözebilir miyiz?

Çözüm fikri, önceki derslerde görülen doğruluk tablosudur. 3 değişkenin $2^3 = 8$ farklı durumu vardır. Bu durumlar ikilik (binary) olarak yazılır: son sütunda 0 ve 1 dönüşümlü, ortadaki sütunda ikişer 0 ve ikişer 1, ilk sütunda dört 0 ve dört 1. Her sütun bir elemana karşılık gelir: birinci sütun 1, ikinci sütun 2, üçüncü sütun 3.

| Satır | 1 | 2 | 3 | Alt küme |
| :-: | :-: | :-: | :-: | :-- |
| 0 | 0 | 0 | 0 | $\emptyset$ |
| 1 | 0 | 0 | 1 | $\{3\}$ |
| 2 | 0 | 1 | 0 | $\{2\}$ |
| 3 | 0 | 1 | 1 | $\{2, 3\}$ |
| 4 | 1 | 0 | 0 | $\{1\}$ |
| 5 | 1 | 0 | 1 | $\{1, 3\}$ |
| 6 | 1 | 1 | 0 | $\{1, 2\}$ |
| 7 | 1 | 1 | 1 | $\{1, 2, 3\}$ |

Üç bit de 0 ise hiçbir eleman yoktur; bu boş kümedir. Hangi gözde 1 varsa o gözün elemanı yazdırılır. Sekiz satırın hepsi birlikte kuvvet kümesini oluşturur.

Algoritma şöyledir: $n$ elemanlı küme için 0'dan $2^n - 1$'e kadar sayıları ikilik tabana çeviren bir fonksiyon yazmak yeterlidir. Her sayının 1 olan bitleri, o alt kümedeki elemanları gösterir.

> **Ders sonrası not:** Hoca 3 değişken için önce "0'dan 8'e kadar" dedi, hemen ardından "0'dan 7'ye kadar" diye düzeltti. Doğrusu 0'dan $2^3 - 1 = 7$'ye kadardır.

Hoca bu yöntemin gücünü 6 elemanlı bir kümeyle gösterdi. Kuvvet kümesini doğrudan kodlamaya çalışan biri, 3 eleman için yazdığı kodun 6 eleman için de doğru çalıştığını kontrol etmekte bile zorlanır. Oysa ikilik yöntemde 0'dan $2^6 - 1$'e kadar sayılar ikiliğe çevrilir ve 1 olan bitler o sıradaki elemana karşılık gelir.

> **Ders sonrası not:** Hoca 6 eleman için "32, 64; 0'dan 65'e kadar" dedi. Doğrusu $2^6 = 64$ alt küme vardır; sayılar 0'dan 63'e kadardır.

Hoca bir uygulama varyasyonu da anlattı. Elemanlar bir dizide tutulur: $[1, 2, 3]$. Bir sayının ikilik karşılığı ayrı bir dizide tutulur; örneğin 6 için $[1, 1, 0]$. İki dizi eleman eleman çarpılır (AND'lenir): $1 \cdot 1 = 1$, $2 \cdot 1 = 2$, $3 \cdot 0 = 0$. Sıfırdan farklı sonuçlar o elemanın alt kümede olduğunu gösterir. Sonuç $\{1, 2\}$'dir. Hoca burada her türlü varyasyonun yapılabileceğini, bunun tamamen algoritmik düşünceye bağlı olduğunu söyledi.

> **Hocanın vurgusu:** Bu derste gördüğünüz her şey tek başına bir anlam ifade etmeyebilir, ama mutlaka bir başka problemin içinde yardımcı olur. Gördüklerimiz "kenarda kalmasın"; bir problemi çözerken "pat diye" kullanılsın. Hoca örnek olarak Karnaugh haritalarında görülen Gray kodunu verdi: Aynı anda yalnız bir bitin değiştiği bu kodlama, ileride başka bir problemin çözümünde kullanılabilir.

**Bonus sorusu:** Bu mantığı kullanarak, hangi dilde olursa olsun, en az kod satırıyla (line of code) kuvvet kümesini bulan algoritmayı yazın ve çıktıları gösterin. Hoca kodun çok kısa olması gerektiğini, uzun bir kaynak kodun istenen şeyi yapmadığı anlamına geleceğini söyledi. Kodu okuyarak doğru çalışıp çalışmadığını anlayacağını, kodu çalıştırmayacağını belirtti. Çözüm Örnek Sorular bölümündedir.

> **Ek bilgi (derste anlatılmadı):** Bu yöntemde $k$ sayısının $i$. bitine bakmak için bit kaydırma ve AND kullanılır: `(k >> i) & 1`. Böylece ikilik dizgiye çevirme adımına bile gerek kalmaz. Kuvvet kümesi algoritmasının çalışma süresi, üretilen alt küme sayısı yüzünden en az $2^n$ ile orantılıdır.

## 7. Küme İşlemleri ve Venn Şemaları

Hoca, kümelerle işlem yaparken Venn şemalarını kullanmanın en kolay yol olduğunu söyledi. İki küme üzerinde şu işlemler yapılabilir: birleşim (union), kesişim (intersection), fark (difference), simetrik fark (symmetric difference) ve tümleyen (complement). Hoca simetrik farkı belki daha önce duymadığımızı belirtti.

### 7.1 Birleşim

$$X \cup Y = \{x \mid x \in X \lor x \in Y\}$$

> **Hocanın vurgusu:** Küçük $x$ ile büyük $X$ aynı şey değildir. Kümelerde kullanılan semboller büyük-küçük harfe duyarlıdır (case sensitive). Kümenin elemanları küçük, kümenin adı büyük harfle yazılır.

Birleşim, $X$ kümesinin ya da $Y$ kümesinin elemanı olan $x$'lerden oluşur. Bool cebrinde birleşim OR'a, yani toplama işlemine karşılık gelir. Venn şemasında iki kümenin tamamı taranır.

Örnek: $X = \{\text{Ayşe}, \text{Lale}, \text{Zeynep}\}$, $Y = \{\text{Lale}, \text{Deniz}\}$ ise

$$X \cup Y = \{\text{Ayşe}, \text{Lale}, \text{Zeynep}, \text{Deniz}\}$$

Lale iki kümede de olduğu için bir kez alınır.

<!-- BELİRSİZ: Birleşim, kesişim ve kartezyen çarpım örneklerindeki adların bir kısmı altyazıda yanlışlıkla maskelenmiş; adlar kısa nottan alındı. -->

### 7.2 Kesişim

$$X \cap Y = \{x \mid x \in X \land x \in Y\}$$

Kesişim, hem $X$'in hem de $Y$'nin elemanı olan $x$'lerden oluşur. Venn şemasında iki kümenin ortak bölgesidir. Aynı örnekte ortak eleman Lale'dir: $X \cap Y = \{\text{Lale}\}$.

> **Hocanın vurgusu:** Bu yazılımları unutmayın: birleşimde OR, kesişimde AND.

### 7.3 Ayrık kümeler

İki kümenin kesişimi boş kümeyse bu kümelere ayrık kümeler (disjoint sets) denir. "Pairwise" olarak da geçebilir:

$$X \cap Y = \emptyset$$

Hoca kitaptan alınan, kendi deyişiyle "biraz garip" bir örnek verdi: $X$ kümesinde "$z$ rektördür" ifadesini sağlayan elemanlar, $Y$ kümesinde "$z$ bu sınıfta oturuyor" ifadesini sağlayan elemanlar var. Burada $z$ bir öğrenciyi temsil ediyorsa, rektör hiçbir zaman öğrenci olmayacağı için kesişim boş kümedir. Hoca bu örneğin saçma olduğunu, zaten bu yüzden koyduğunu, isterseniz hiç düşünmeyin dedi. Önemli olan tanımdır.

Sayılarla örnekler:

- Tek sayılar ve çift sayılar ayrıktır.
- Tek sayılar ve asal sayılar ayrık değildir. Örneğin 3, 5, 7 iki kümede de vardır.
- Çift sayılar ve asal sayılar da ayrık değildir. "Hayırı bozan" tek eleman 2'dir.

### 7.4 Tümleyen

Bir kümenin tümleyeni (complement), o kümenin elemanları dışında kalanlardır. Hoca önce sözlü bir örnek verdi: $X$ uzun boylulardan oluşuyorsa tümleyeni uzun boylu olmayanlardır. Ama böyle cümle olarak verildiğinde anlamsız geldiğini söyleyip sayısal bir örnek verdi: Evrensel küme tam sayılar, $X$ çift sayılar ise $\overline{X}$ tek sayılardır.

$$\overline{X} = \{z \in U \mid z \notin X\}$$

Ayrıca:

$$\overline{\emptyset} = U, \qquad \overline{U} = \emptyset$$

Boş küme ile evrensel küme birbirinin tümleyenidir. Venn şemasında $\overline{A}$, evrensel kümeden $A$ çıkarıldığında kalan bölgedir.

### 7.5 Fark

$$X - Y = \{x \mid x \in X \land x \notin Y\}$$

$X - Y$, $X$'in elemanı olup $Y$'nin elemanı olmayan $x$'lerden oluşur. Hoca Venn şemasında bunu şöyle taradı: Önce $X$'in bütün elemanlarının olduğu bölge alınır. Sonra "$Y$'nin elemanı olmayacak" kuralı gereği $Y$ kümesi olduğu gibi çıkarılır. Geriye kalan, $X$'in $Y$ ile kesişmeyen kısmıdır.

Örnek: $X = \{1, 2, 3, 4, 5\}$, $Y = \{2, 5, 7, 10\}$.

- Ortak elemanlar 2 ve 5'tir.
- $X$'ten bunlar çıkarılır.
- $X - Y = \{1, 3, 4\}$

### 7.6 Simetrik fark

$$X \oplus Y = (X - Y) \cup (Y - X)$$

Hoca simetrik farkın işaretinin, Bool cebrinde XOR (dışlayan veya) için gösterdiği işaretle aynı olduğunu hatırlattı. XOR'un doğruluk tablosunda girişler aynıysa çıkış 0, farklıysa 1'dir. Hoca XOR'u yine "çıkarma" ile ilişkilendirdi: Çıkarma işleminde de girişler aynıysa sonuç 0'dır.

> **Ders sonrası not:** XOR yalnız çıkarmaya özgü değildir. İki bitin ikilik toplamındaki toplam biti de, çıkarmadaki fark biti de XOR'dur. Bu derste önemli olan, simetrik farkın XOR'un 1 olduğu durumlara karşılık gelmesidir.

Tanım açıldığında:

$$X \oplus Y = \{z \mid (z \in X \land z \notin Y) \lor (z \in Y \land z \notin X)\}$$

Birleşim yerine OR konur. Yani $z$, $X$'te var $Y$'de yok, ya da $Y$'de var $X$'te yok. Bunlar tam olarak XOR'un 1 olduğu satırlardır (girişler 1-0 ve 0-1).

> **Ders sonrası not:** Hoca tanımı açarken ikinci parçayı "Z, Y'nin elemanı ve Z, Y'nin elemanı değil" diye okudu. Doğrusu $z \in Y \land z \notin X$'tir.

Venn şemasında: $X$'ten $Y$ çıkarılınca yalnız $X$'e ait bölge, $Y$'den $X$ çıkarılınca yalnız $Y$'ye ait bölge kalır. İkisinin birleşimi simetrik farktır. Kesişim bölgesi dışarıda kalır.

Örnek olarak bölüm 7.5'teki kümeler için (ara adım eklendi): $X - Y = \{1, 3, 4\}$, $Y - X = \{7, 10\}$, dolayısıyla $X \oplus Y = \{1, 3, 4, 7, 10\}$.

Hoca XOR'u hatırlamaya gerek olmadığını da ekledi: Simetrik farkın "$X$'in $Y$'den farkı ile $Y$'nin $X$'ten farkının birleşimi" olduğunu bilmek yeterlidir.

## 8. Küme İşlemlerinin Özellikleri

Aradan sonra hoca küme işlemlerinin özelliklerine geçti. Bunların Bool cebrinde görülenlerle hemen hemen aynı olduğunu söyledi. Venn şeması göz önüne getirilerek hepsi rahatça takip edilebilir.

| Özellik | Birleşim için | Kesişim için |
| :-- | :-- | :-- |
| Birleşme | $(A \cup B) \cup C = A \cup (B \cup C)$ | $(A \cap B) \cap C = A \cap (B \cap C)$ |
| Değişme | $A \cup B = B \cup A$ | $A \cap B = B \cap A$ |
| Dağılma | $A \cup (B \cap C) = (A \cup B) \cap (A \cup C)$ | $A \cap (B \cup C) = (A \cap B) \cup (A \cap C)$ |
| Özdeşlik | $A \cup \emptyset = A$ | $A \cap U = A$ |
| Tümleme | $A \cup \overline{A} = U$ | $A \cap \overline{A} = \emptyset$ |
| Eşgüçlülük (idempotent) | $A \cup A = A$ | $A \cap A = A$ |
| Sınır (bound) | $A \cup U = U$ | $A \cap \emptyset = \emptyset$ |
| Yutma (absorption) | $A \cup (A \cap B) = A$ | $A \cap (A \cup B) = A$ |
| De Morgan | $\overline{A \cup B} = \overline{A} \cap \overline{B}$ | $\overline{A \cap B} = \overline{A} \cup \overline{B}$ |

Ayrıca $\overline{\overline{A}} = A$, $\overline{\emptyset} = U$ ve $\overline{U} = \emptyset$'dir.

Hoca bazı özellikleri ayrıca açıkladı:

- **Tümleme:** Bir kümenin tümleyeni $U$'dan kendisi çıkarılmış haliydi. Bu yüzden küme ile tümleyeninin birleşimi $U$'yu, kesişimi boş kümeyi verir.
- **Eşgüçlülük:** Bool cebrinde $A + A = A$ ve $A \cdot A = A$ idi. Kümede de bir kümenin kendisiyle birleşimi ve kesişimi yine kendisidir.
- **Sınır kanunu:** Hoca bazı terimleri Türkçeye çevirmekte zorlandığını söyledi. $A$ kümesi mutlaka $U$'nun içindedir; bu yüzden $A \cup U = U$'dur. Boş kümede kesiştirilecek bir şey yoktur; bu yüzden $A \cap \emptyset = \emptyset$'dir.
- **De Morgan:** Parantezin tümleyeni alınırken her kümenin tümleyeni alınır ve ortadaki işlem tersine çevrilir; birleşimse kesişim olur. Kural Bool cebrindekiyle aynı işler.

### 8.1 Yutma özelliğinin Venn şemasıyla gösterilmesi

Hoca, Bool cebrinde özdeşlikleri kullanarak bir ifadenin doğruluğunu ispatladığımız gibi, kümelerde de Venn şeması çizerek ispat yapılabileceğini gösterdi.

**$A \cup (A \cap B) = A$:** $A \cap B$, iki kümenin ortak bölgesidir. Bu bölge zaten $A$'nın içindedir. $A$ ile birleşimi $A$'nın kendisi olur.

**$A \cap (A \cup B) = A$:** $A \cup B$, iki kümenin tamamıdır. Bunun $A$ ile kesişimi alınır. İki kez taranmış bölge yalnızca $A$'dır. Sonuç $A$'dır.

Hoca bu sonuçların, aynı Bool cebrindeki ispatlar gibi, önceki slaytlarda verilen özellikler kullanılarak da çıkarılabileceğini söyledi.

## 9. Kartezyen Çarpım

İki kümenin kartezyen çarpımı (Cartesian product), sıralı ikililerden oluşur:

$$A \times B = \{(a, b) \mid a \in A \land b \in B\}$$

Birinci eleman $A$'dan, ikinci eleman $B$'den alınır. Hoca "product" kelimesinin geçen haftaki slaytlarda AND için de geçtiğini hatırlattı.

İki temel özellik:

- Kartezyen çarpımda değişme özelliği yoktur: $A \times B \neq B \times A$.
- $|A \times B| = |A| \cdot |B|$.

**Örnek:** $A = \{\text{Celal}, \text{Lale}, \text{Lamia}\}$, $B = \{\text{Banu}, \text{Vedat}\}$.

$A$'nın ilk elemanı $B$'nin bütün elemanlarıyla, sonra ikinci elemanı $B$'nin bütün elemanlarıyla eşlenir:

$$A \times B = \{(\text{Celal}, \text{Banu}), (\text{Celal}, \text{Vedat}), (\text{Lale}, \text{Banu}), (\text{Lale}, \text{Vedat}), (\text{Lamia}, \text{Banu}), (\text{Lamia}, \text{Vedat})\}$$

$B \times A$ yazılsaydı (Banu, Celal), (Banu, Lale), (Banu, Lamia), (Vedat, Celal), (Vedat, Lale), (Vedat, Lamia) olurdu. Eleman sayıları aynıdır, ama ikililer tam terstir. Bu yüzden $A \times B \neq B \times A$.

Eleman sayısı: $|A| = 3$, $|B| = 2$, $|A \times B| = 3 \cdot 2 = 6$. Hoca listeyi sayarak da 6 buldu.

> **Ders sonrası not:** $A \times B \neq B \times A$ genel kuraldır. İstisnalar: $A = B$ ise ya da kümelerden biri boşsa iki çarpım eşittir.

## 10. Genelleştirilmiş Birleşim, Kesişim ve İçerme-Dışarma

### 10.1 Genelleştirilmiş birleşim ve kesişim

$n$ tane kümenin birleşimi ve kesişimi tek bir sembolle yazılabilir. Slaytta bunlar toplam ve çarpım sembolleriyle gösterilmişti. Hoca bunu Bool cebriyle açıkladı: Birleşim OR, yani toplamadır; bu yüzden $\Sigma$ kullanılmış. Kesişim AND, yani çarpmadır; bu yüzden $\Pi$ kullanılmış. $A_1$ ile $A_2$ birleşir, sonra $A_3$, ..., $A_n$'e kadar gider.

> **Ders sonrası not:** Slayttaki $\sum_{i=1}^n A_i$ ve $\prod_{i=1}^n A_i$ gösterimi Bool benzetmesine dayanıyor. Standart gösterim $\bigcup_{i=1}^{n} A_i$ ve $\bigcap_{i=1}^{n} A_i$'dir. Kaynaklarda bu gösterimle karşılaşırsınız.

### 10.2 İki kümenin birleşiminin eleman sayısı

$$|A \cup B| = |A| + |B| - |A \cap B|$$

$|A|$ ile $|B|$ toplandığında iki kümede ortak olan elemanlar iki kez sayılır. Birleşimde her eleman bir kez yer aldığı için ortak elemanlar ($A \cap B$) bir kez çıkarılır.

**Örnek:** Bilgisayar bilimleri bölümünde 217 öğrenci var. 157 kişi 125 kodlu dersi, 145 kişi 173 kodlu dersi alıyor. 98 kişi iki dersi de alıyor. Kaç kişi bu iki dersten hiçbirini almıyor?

Hoca soruyu bölüme uyarladı: Sanki 157 kişi BBG'yi, 145 kişi Ayrık Matematik'i alıyor. Bir öğrenci cevabı 13 olarak buldu. Hoca çözümü formülle gösterdi:

- $|A| = 157$, $|B| = 145$, $|A \cap B| = 98$.
- 98 kişi hem 157'nin hem de 145'in içinde sayılmıştır.
- $|A \cup B| = 157 + 145 - 98 = 204$. Bu, iki dersten en az birini alanların sayısıdır; "ikisini birden alan" sayısı değildir.
- Hiçbirini almayan: $217 - 204 = 13$.

Hoca bu 13 kişi için "kantinde oturuyor ya da evde duruyor ya da bu dersi geçmiş" diye şaka yaptı.

Venn şemasında bölgeler:

- Yalnız birinci dersi alan: $157 - 98 = 59$
- İki dersi de alan: $98$
- Yalnız ikinci dersi alan: $145 - 98 = 47$
- $59 + 98 = 157$, $98 + 47 = 145$. Toplam $59 + 98 + 47 = 204$; $217 - 204 = 13$.

### 10.3 Üç kümenin birleşiminin eleman sayısı

$$|A \cup B \cup C| = |A| + |B| + |C| - |A \cap B| - |A \cap C| - |B \cap C| + |A \cap B \cap C|$$

Hoca bunu Venn şemasıyla anlattı:

- Önce $A$, $B$ ve $C$'nin tamamındaki eleman sayıları eklenir.
- İki kümenin kesiştiği bölgeler iki kez sayılmıştır. Ortadaki üçlü kesişim bölgesi ise hem $A$'da, hem $B$'de, hem $C$'de vardır.
- Sonra ikili kesişimler $|A \cap B|$, $|A \cap C|$, $|B \cap C|$ çıkarılır.
- Bu çıkarmalar ortadaki bölgeyi de silmiş olur. Bu yüzden $|A \cap B \cap C|$ yeniden eklenir.

> **Ders sonrası not:** Hoca bir yerde formülü sözlü özetlerken "sonra 3. kesişim var, o çıkarılacak" dedi. Doğrusu, üçlü kesişim **eklenir**. Hoca slayttaki anlatımda da ortadaki bölgeyi "yeniden katıyorum" dedi. Ayrıca ortadaki bölge "iki kere gitmiş" değildir: önce 3 kez eklenir, ikili kesişimlerle 3 kez çıkarılır, yani hiç sayılmamış olur. Bu yüzden bir kez eklenir.

Hoca dört küme için de formülün aynı mantıkla türetildiğini ve bölüm sonundaki slaytlarda bunlarla ilgili örnekler olduğunu söyledi.

**Soru:** Kartezyen çarpımda $|A|$ gösterimi kümenin eleman sayısını ifade ediyor. Kuvvet kümesinde de aynı gösterim vardı; orada alt küme sayısını ifade etmiyor muydu? Farkı nasıl anlayacağız? **Cevap:** İkisi de eleman sayısıdır. $|\mathcal{P}(X)|$, kuvvet kümesinin eleman sayısıdır. Kuvvet kümesinin elemanları da $X$'in alt kümeleri olduğu için bu sayı alt küme sayısına eşittir. $X$'in 3 elemanı varsa $|\mathcal{P}(X)| = 2^3 = 8$ olur.

## 11. Küme İşlemlerini Bit Dizisiyle Programlamak

Hoca bu kısmın çok önemli olduğunu söyledi. Amaç yine aynıydı: Gördüğümüz şeyleri başka bir uygulamada kullanabilmek.

Soru şöyledir: Bir evrensel küme ve iki küme verilmiş. Bu iki kümenin birleşimini ve kesişimini bulun. Hoca bu tür soruları BBG (Bilgisayar Bilimlerine Giriş) dersinde çözmüş olabileceğimizi söyledi.

### 11.1 Yöntem

Evrensel kümede 6 eleman var: $U = \{x_1, x_2, x_3, x_4, x_5, x_6\}$. Her küme 6 gözlü bir diziyle gösterilir. Eleman kümede varsa o göze 1, yoksa 0 yazılır.

- $A$'da $x_1$ var (1), $x_2$ yok (0), $x_3$ var (1), $x_4$ yok (0), $x_5$ ve $x_6$ var (1).
- $B$'de yalnız $x_2$, $x_3$ ve $x_6$ var.

Birleşim OR, kesişim AND işlemidir:

| | $x_1$ | $x_2$ | $x_3$ | $x_4$ | $x_5$ | $x_6$ |
| :-- | :-: | :-: | :-: | :-: | :-: | :-: |
| $A$ | 1 | 0 | 1 | 0 | 1 | 1 |
| $B$ | 0 | 1 | 1 | 0 | 0 | 1 |
| $A \cup B$ (OR) | 1 | 1 | 1 | 0 | 1 | 1 |
| $A \cap B$ (AND) | 0 | 0 | 1 | 0 | 0 | 1 |

OR satırında $x_4$ dışında her şey 1'dir: $A \cup B = \{x_1, x_2, x_3, x_5, x_6\}$. $x_3$ iki kümede de olduğu halde bir kez yazılır.

AND satırında yalnız $x_3$ ve $x_6$ 1'dir: $A \cap B = \{x_3, x_6\}$.

Hoca, bu yöntemle bir kümenin kesişimini ve birleşimini çok az kod satırıyla alabileceğimizi vurguladı.

### 11.2 Diğer yöntemlerle karşılaştırma

Bu şekilde düşünmeden birleşim alınsaydı ne yapılırdı? $A$'dan $x_1$ alınır, $B$'de var mı diye aranır; yoksa yazılır. Sonra $x_3$ alınır, $B$'de var mı diye bakılır; varsa $B$'den silinir ve yazılır. $x_5$, $x_6$ için aynısı yapılır. En sonda $B$'de tek başına kalan $x_2$ yazılır. Hoca "kaç tane karşılaştırma, kaç tane `if` yaptın?" diye sordu.

İkinci yol, kümeleri önce sıralamaktır. Sıralı kümelerde aranan eleman geçildiği an arama durdurulabilir. Örneğin $x_1$ aranırken $B$'nin ilk elemanı $x_2$ ise, $x_1 < x_2$ olduğu için $B$'nin gerisine bakılmaz. $x_3$ aranırken $x_3$ bulununca gerisine bakılmaz, çünkü sonraki sayılar $x_3$'ten büyüktür. $x_5$ aranırken kalınan yerden devam edilir. Kesişimde de aynı mantık işler. Hoca bunun için bir itiraz da öngördü: "Sıralama için de emek harcayacağım." Bu doğrudur; örneğin quicksort ile daha kısa sürede sıralama yapılabilir, ama hangi sıralama algoritmasının kullanıldığı önemlidir.

Hoca sonuçta bir soruyu çözmenin çok farklı yolları olduğunu söyledi: sıralamadan, sıralayarak ya da tamamen Bool cebrini kullanarak.

> **Hocanın vurgusu:** Ödevde doğrudan "kesişimi ve birleşimi bul" deniyorsa, hazır `intersection` ya da `union` kütüphanesini kullanan sıfır puan alır. Bu işlemler büyük bir problemin içinde yapılması gereken alt işlemlerse kütüphane kullanılabilir. Hoca bunu bir benzetmeyle anlattı: Bir araba yapılırken tekerleği yeniden icat etmeye gerek yoktur. Ama sizden "bu tekerleğe benzer yeni bir tekerlek yap" denirse kütüphaneyi kullanmamalısınız.

> **Ek bilgi (derste anlatılmadı):** Bu yöntemde her küme bir bit vektörü (bit vector) olarak saklanır. Tümleyen NOT ile, fark $A \land \neg B$ ile, simetrik fark XOR ile aynı şekilde hesaplanır. Evrensel küme küçükse bütün küme tek bir tam sayının bitlerine sığar ve bir işlem tek bir makine komutuyla yapılır.

**Soru:** Dizinin gözlerine 0 ya da 1 yazmak için de önce $x_1$'in $B$'de olup olmadığını bir kez aramak gerekmiyor mu? **Cevap:** Hoca kısa bir örnekle açıkladı. $A = \{1, 3\}$, $B = \{4, 5\}$ olsun. En büyük eleman 5 olduğu için 5 gözlü bir dizi açılır. $A$'da 1 var: dizinin 1. gözüne 1 konur. $A$'da 3 var: 3. indise 1 konur. $B$ için ayrı bir dizi açılır: 4 ve 5 numaralı gözlere 1 konur. Elemanın değeri doğrudan dizinin indis numarası olarak kullanılır; arama gerekmez. Kümenin elemanlarını bir diziye yerleştirmenin başka yolu da yoktur. Sonra işlem yapılır.

## 12. Diziler (Sequences)

Hoca bu kısmın "biraz sıkıcı, biraz anlamsız gibi" gelebileceğini ama kitapta olan bir bölüm olduğunu söyledi.

### 12.1 Tanım ve örnekler

Dizi (sequence), sıralı bir listeyi göstermek için kullanılan ayrık yapıdır. $n$ elemanlı bir dizi şöyle gösterilir:

$$s_1, s_2, s_3, \dots, s_n$$

$s_1$ dizinin birinci elemanı, $s_2$ ikinci elemanı, $s_3$ üçüncü elemanıdır. Önemli olan, dizinin genel teriminden elemanları çıkarabilmektir.

- $s_n = \dfrac{1}{n}$, $n \in \mathbb{N}$: $n = 1$ için 1, $n = 2$ için $\frac{1}{2}$, $n = 3$ için $\frac{1}{3}$, $n = 4$ için $\frac{1}{4}$, ...
- $s_n = n^2 + 1$, $n \in \mathbb{N}$: $s_1 = 1^2 + 1 = 2$, $s_2 = 2^2 + 1 = 5$, $s_3 = 10$, ...

Hoca $n$'nin doğal sayılardan başka tek sayılar, çift sayılar gibi farklı biçimlerde de tanımlanabileceğini, önemli olanın elemanları sırasıyla yerine koymak olduğunu söyledi.

### 12.2 Artan ve azalan diziler

- Artan (increasing) dizi: her $n$ için $s_n \le s_{n+1}$. Bir sonraki eleman öncekinden ya büyük ya da ona eşittir.
- Azalan (decreasing) dizi: her $n$ için $s_n \ge s_{n+1}$. Bir sonraki eleman öncekinden ya küçük ya da ona eşittir.

Örnekler:

- $s_n = 4 - 2n$: $n = 1, 2, 3, 4$ için $2, 0, -2, -4, \dots$ Bu dizi azalandır.
- $s_n = 2n - 1$: $n = 1, 2, 3$ için $1, 3, 5, \dots$ Bu dizi artandır.

> **Ders sonrası not:** Altyazıda azalan dizi "$4 - n$" diye geçiyor. Hocanın hesapladığı değerler ($2, 0, -2, -4$) $s_n = 4 - 2n$'ye aittir. Hoca $s_n = 2n - 1$ dizisi için de "azalan bir dizi" dedi. Doğrusu artandır: $1 < 3 < 5 < \dots$

### 12.3 Alt dizi

Artan ve azalan dizilerin bizi götürdüğü kavram alt dizidir (subsequence). $s_n$ dizisinin alt dizisi $t_n$ ile gösterilsin.

> **Hocanın vurgusu:** Sıralama düzeni aynı kalmak şartıyla $s$ dizisinin elemanlarından elde edilen diziye alt dizi denir. Sıralama kesinlikle bozulmayacak. Bozulursa alt dizi kavramı hatalı olur.

Örnekler:

- $1, 2, 3, 4, 5$ dizisinden $1, 5, 3$ alt dizi olamaz, çünkü sıra bozulmuştur; ana dizide 3, 5'ten önce gelir. $1, 3, 5$ ise alt dizidir.
- $s_n = n$ dizisinin elemanları $1, 2, 3, 4, 5, \dots$'tir. $t_n = 2n$ çift sayılardan oluşur: $2, 4, 6, 8, 10, 12, \dots$ Bu elemanlar $s$'den sıra bozulmadan alınmıştır. Bu yüzden $t_n$, $s_n$'in alt dizisidir.

## 13. Toplam ve Çarpım Gösterimi

$\Sigma$ (sigma) toplama işaretidir. Hoca bunun Yunan alfabesinde S harfine karşılık geldiğini, "toplam" anlamının oradan geldiğini söyledi. $a_m$'den $a_n$'e kadar terimlerin toplamı:

$$\sum_{i=m}^{n} a_i = a_m + a_{m+1} + \dots + a_n$$

$\Pi$ (pi) ise çarpım işaretidir; Yunan alfabesinde P harfine karşılık gelir. Dizinin elemanlarının çarpımı:

$$\prod_{i=m}^{n} a_i = a_m \cdot a_{m+1} \cdots a_n$$

### 13.1 Örnek: $\sum_{k=4}^{8} (-1)^k$

Hoca soruyu sorup cevap bekledi. Bir öğrenci cevabı 1 olarak verdi ve gerekçesini şöyle açıkladı: İlk terim pozitifle başlar, terimler birbirini götürür, en sonda yine pozitif terim kalır.

$$\sum_{k=4}^{8} (-1)^k = (-1)^4 + (-1)^5 + (-1)^6 + (-1)^7 + (-1)^8 = 1 - 1 + 1 - 1 + 1 = 1$$

### 13.2 Örnek: $\sum_{i=1}^{4} \sum_{j=1}^{3} ij$

Hoca bu soruyu sessiz kalan öğrencilere yöneltti. Cevap gelmeyince kendisi çözdü. İç içe toplamları iç içe parantez gibi düşünmek gerekir; önce içteki toplam hesaplanır:

$$\sum_{j=1}^{3} ij = i \cdot 1 + i \cdot 2 + i \cdot 3 = i + 2i + 3i = 6i$$

Sonra dıştaki toplam:

$$\sum_{i=1}^{4} 6i = 6 + 12 + 18 + 24 = 60$$

### 13.3 Örnek: $\prod_{i=1}^{3} 2i$

Slaytta bir de çarpım sorusu olması gerekiyordu; hoca bir tane kendisi verdi. Önce üst sınırı 5 yazacakken 3'e değiştirdi:

$$\prod_{i=1}^{3} 2i = (2 \cdot 1)(2 \cdot 2)(2 \cdot 3) = 2 \cdot 4 \cdot 6 = 48$$

Ara adım: $2 \cdot 4 = 8$, $8 \cdot 6 = 48$.

### 13.4 Dersi derste dinlemek üzerine

Toplam sorusu sırasında bir öğrencinin uyuduğu anlaşıldı. Hoca bunun üzerine derse dair bir konuşma yaptı. Ders zor değildir; ders derste dinlenirse yapamamak diye bir şey olmaz. Her şey vizeden önceki geceye bırakılırsa çok fazla konu tek gecede geçilmeye çalışılır; bu gerçekten zordur. Hoca ayrıca öğrencilere işlerinin dışında mutlaka bir hobi, bir ilgi alanı edinmelerini ve üçüncü sınıfta yönelmek istedikleri alanı seçtiklerinde o alandaki çevrim içi kursları takip etmelerini önerdi. Dar açıdan bakmakla geniş açıdan bakmanın çok farklı olduğunu söyledi.

## 14. Dizgiler ve Düzenli İfadeler

### 14.1 Dizgi

Hoca bu kısmın programlama dillerindeki `string` değişkenine benzediğini söyledi. Bir değişkeni string olarak tanımladığınızda onun bir maksimum uzunluğu vardır ve o uzunluk geçilemez.

$X = \{a, b, c\}$ bir alfabe olsun. Bu alfabeyle istenen her türlü dizgi (string) yazılabilir. Örnek:

$$\alpha = bbaccc$$

Bu dizgi üstel biçimde daha kısa gösterilebilir:

$$\alpha = b^2 a c^3$$

Dizginin uzunluğu da kardinalite gibi $|\alpha|$ ile gösterilir. Üstel gösterimde üsler toplanır: $2 + 1 + 3 = 6$, yani $|\alpha| = 6$. Hiç eleman içermeyen dizgiye boş dizgi (null string) denir ve $\lambda$ ile gösterilir.

### 14.2 Düzenli ifadelere giriş

Hoca düzenli ifadelerin (regular expressions) slaytta olmadığını, ama genel kültür olarak biraz anlatacağını söyledi. İlerleyen yıllarda projelerde kullanılması gerekecek. "Regex" adlı, düzenli ifadeleri kullanan bir dil vardır ve büyük kolaylıklar sağlar.

Hocanın verdiği kullanım örnekleri:

- Bir doküman ya da HTML sayfaları içinde bütün e-posta adreslerini bulmak.
- Yerli, yabancı, cep ya da sabit hat; farklı biçimlerde yazılmış bütün telefon numaralarını bulmak.
- Çok farklı formatlarda yazılan ev adreslerini bulmak.

Düzenli ifade ne kadar iyi yazılırsa o kadar çok şey bulur; ne kadar eksik yazılırsa o kadar eksik bulur.

Regex'te iki temel işlem vardır:

- `*` (yıldız): ya hiç ya da olabildiği kadar. `a*` ile hiç `a` yazılmayabilir, bir `a`, iki `a`, üç `a`, ... yazılabilir; üst sınır yoktur.
- `+` (artı): en az bir kez ya da olabildiği kadar. `a+` ile en az bir `a` mutlaka vardır; boş durum yoktur.

> **Ders sonrası not:** Hoca yıldızın "hiç" durumunu "sigma, lambda, boş küme" diye andı. Doğrusu: `a*` boş dizgiyi ($\lambda$ ya da $\varepsilon$) üretebilir. Boş dizgi bir dizgidir, boş küme ($\emptyset$) ise elemanı olmayan kümedir; ikisi farklıdır.

Hoca bölüm sonunda bu farkı kendisi de özetledi: Yıldız boş durum dahil her şeyi kapsar; artı, her şeyin içinden boş durumu çıkarır, en az bir kez olacaktır.

### 14.3 $bbaccc$ için düzenli ifade

$bbaccc$ dizgisi düzenli ifadeyle `b+ac+` diye yazılabilir. Hoca önce `b*` diyecekken düzeltti ve artı koydu. Anlamı:

- `b+`: en az bir `b`; 2, 3, 4 `b` de olabilir.
- `a`: tam bir `a`, her zaman vardır.
- `c+`: en az bir `c`; 2, 3, 4 `c` de olabilir.

Hoca kendisine şu itirazın gelebileceğini söyledi: "$a$'nın bir kez olduğunu nereden biliyorsunuz?" Dizgi $bbbbaaaccc$ gibi birden çok `a` içerebilseydi bu ifade yanlış olurdu; `a`'ya da artı koymak gerekirdi: `b+a+c+`. Bu durumda harfler en az bir kez gelir, ama hep bu sırayla (`b`, `a`, `c`) gelir. `a`, `c`, `b` sırası tamamen yanlış olur.

Başlarına yıldız konursa, örneğin `b*a*c*`, `a` hiç gelmeyebilir: iki `b` ve yalnız `c`'lerden oluşan dizgi de yazılabilir. Kısacası düzenli ifadeyi yazabilmek için kuralların verilmesi gerekir: "Bu kümeden yazacağın bütün dizgilerde $a$, $b$, $c$ olabilir" ya da "$a$ en az bir kez gelecek, $b$ ve $c$ şu kadar olabilir" gibi.

### 14.4 Üç dizgiyi üreten düzenli ifade

Alfabe $\{a, b, c\}$ olsun ve üç dizgi verilsin:

- $\alpha_1 = a$
- $\alpha_2 = baa$
- $\alpha_3 = baccc$

Bu üç dizgiyi de üreten bir düzenli ifade yazılacak. Hoca adım adım kurdu:

1. Dizgilerin çoğu `b` ile başlıyor. $\alpha_1$'de `b` yok; bu yüzden `b`'ye yıldız konur: `b*`.
2. `a` her dizgide en az bir kez geçiyor, $\alpha_2$'de iki kez. Hiç gelmeme durumu yok; bu yüzden artı konur: `a+`.
3. `c` birinci ve ikinci dizgide yok, üçüncüde üç tane var; yıldız konur: `c*`.

Sonuç: `b*a+c*`. Kontrol:

- $\alpha_1 = a$: `b*`'den hiç almaz ($\lambda$), bir `a` alır, `c*`'den hiç almaz.
- $\alpha_2 = baa$: bir `b`, iki `a`, `c` yok.
- $\alpha_3 = baccc$: bir `b`, bir `a`, üç `c`.

Hoca sonra ifadeyi sağlamayan dizgiler sordu:

| Dizgi | `b*a+c*` sağlar mı? | Gerekçe |
| :-- | :-: | :-- |
| $cb$ | Hayır | En az bir `a` olmalı; `a` yok. |
| $acb$ | Hayır | `b` yok, bir `a`, bir `c` alınır; ama ifade bitti ve sonda kalan `b` ifadede yok. |

<!-- BELİRSİZ: 02:29:58–02:31:28 arasında hoca iki ayrı "a içermeyen" dizgi soruyor ($\alpha_4$ ve $\alpha_5$); altyazıda yalnız birinin "C ve B" içerdiği anlaşılıyor, diğerinin tam içeriği çıkmıyor. -->

Hoca iki yönlü çalışılabileceğini söyledi: Ya verilen düzenli ifadeye uyan dizgiler yazılır ya da verilen dizgileri sağlayan düzenli ifade yazılır. Tek bir yazımla onlarca, yüzlerce dizgi ifade edilebilir. Ama her dizgi her kuralı sağlamaz.

### 14.5 Bütün dizgileri üreten "tembel" ifade

Alfabedeki bütün dizgileri üreten bir kural yazmak istenirse:

```text
(a*b*c*)*
```

Hoca bunun nasıl çalıştığını gösterdi. Örneğin $c$ yazmak için parantezin içine bir kez girilir, `a` ve `b` hiç alınmaz, `c` alınır. $cb$ için: içeri girilir, yalnız `c` alınır, çıkılır; dıştaki yıldız sayesinde parantezin içine yeniden girilir, bu kez yalnız `b` alınır. $acb$ için: içeri girilir, `a` ve `c` alınır, çıkılır; yeniden girilir, yalnız `b` alınır.

> **Hocanın vurgusu:** Bu, "bütün üşengeç ve tembellerin kullanacağı" bir notasyondur; her şey yazılır. Genelde bir olay ya da onun karşılıkları verilir ve bunları sağlayan dar bir ifadenin yazılması istenir.

### 14.6 Dizgi birleştirme

İki dizgi art arda birleştirilebilir (concatenation). $\alpha$ ve $\beta$ birleştirildiğinde $\alpha\beta$ yazılır. Uzunluğu:

$$|\alpha\beta| = |\alpha| + |\beta|$$

Hocanın örneğinde $|\alpha| = 6$, $|\beta| = 5$ idi; birleştirilmiş dizginin uzunluğu $6 + 5 = 11$ oldu. Hoca bunu birleştirilmiş dizgideki üsleri toplayarak da kontrol etti ve yine 11 buldu.

<!-- BELİRSİZ: 02:34:49'da slayttaki $\alpha$ ve $\beta$ dizgilerinin üstel gösterimi altyazıdan çıkmıyor; yalnız uzunluklar (6 ve 5) anlaşılıyor. -->

## 15. Sayı Sistemleri

Hoca sayı sistemlerini herkesin bildiğini düşündüğünü, sıfırdan anlatmak yerine hatırlatmak amacıyla yüzeysel geçeceğini söyledi. Hoca bu konunun BBG'de görülmüş olmasını umduğunu da belirtti.

### 15.1 Tabanlar ve kullanım yerleri

- Günlük hayatta 10 tabanı (decimal) kullanılır.
- Lojik ve mantıkta 2 tabanı (binary) kullanılır.
- Assembly gibi alçak seviyeli dillerde ya da bir kod makine dilinde izlenirken (trace, debug) 16 tabanı (hexadecimal) görülür. Hoca bu dönem alınan assembly dersinde kod debug edilirken onaltılık karşılıkların görüleceğini söyledi.
- 8 tabanı (octal) da vardır. Hoca bunun genelde fen alanlarında kullanıldığını, bizimle pek ilişkisi olmadığını söyledi.

Her taban vardır: 2, 3, 4, 5, 6, 7, 8, ... Bazıları bazı alanlarda sık kullanıldığı için özel adlar almıştır.

> **Ders sonrası not:** Sekizlik taban bilgisayar biliminde de kullanılır. Büyük olasılıkla en bilinen örnek Unix dosya izinleridir (`chmod 755`); her sekizlik rakam üç izin bitine karşılık gelir.

### 15.2 Basamak değeri ve taban kuralı

Slayttaki sayı 45238'dir. Hoca slaytta sayının "45,238" diye virgülle yazıldığını, bunun kitaptan alındığı için öyle kaldığını söyledi. Türkçede basamaklar nokta ile, küsurat virgülle ayrılır; İngilizcede tam tersidir. Bu sayı "45 virgül 238" değildir.

10 tabanında her basamak 10'un bir kuvvetiyle çarpılır:

$$45238_{10} = 4 \cdot 10^4 + 5 \cdot 10^3 + 2 \cdot 10^2 + 3 \cdot 10^1 + 8 \cdot 10^0$$
$$= 40000 + 5000 + 200 + 30 + 8 = 45238$$

> **Hocanın vurgusu:** Her taban, kendisinden küçük rakamlarla ifade edilir. 45238 sayısı 8 tabanında olamaz, çünkü içinde 8 var. 7 tabanında da olamaz. En az 9 tabanında olabilir. 10 tabanı denmesinin sebebi, 0 ile 9 arasındaki rakamlardan oluşmasıdır.

### 15.3 İkilikten onluğa çevirme

Örnek: $1101011_2$. En sağdaki basamak $2^0$, sonra $2^1$, $2^2$, ..., en soldaki basamak $2^6$ ile çarpılır:

$$1101011_2 = 1 \cdot 2^6 + 1 \cdot 2^5 + 0 \cdot 2^4 + 1 \cdot 2^3 + 0 \cdot 2^2 + 1 \cdot 2^1 + 1 \cdot 2^0$$
$$= 64 + 32 + 0 + 8 + 0 + 2 + 1 = 107_{10}$$

> **Ders sonrası not:** Hoca basamakları sırayla okurken üçüncü basamak için bir kez "2'nin 4. kuvveti" dedi. Doğru sıra $2^0, 2^1, 2^2, \dots, 2^6$'dır. Sonuç olan 107 doğrudur.

### 15.4 Onluktan ikiliğe çevirme

Tersini yapmak için işlemin tersi yapılır: Çarpma yerine bölme. Sayı 2'ye art arda bölünür, kalanlar sondan başa okunur.

Örnek: $73_{10}$.

| Bölünen | Bölüm | Kalan |
| :-: | :-: | :-: |
| 73 | 36 | 1 |
| 36 | 18 | 0 |
| 18 | 9 | 0 |
| 9 | 4 | 1 |
| 4 | 2 | 0 |
| 2 | 1 | 0 |
| 1 | 0 | 1 |

Kalanlar sondan başa okunur: $73_{10} = 1001001_2$.

Kontrol: $1 \cdot 2^6 + 1 \cdot 2^3 + 1 \cdot 2^0 = 64 + 8 + 1 = 73$.

Hoca genel kuralı şöyle verdi: 10 tabanından hangi tabana çevrilecekse o tabana bölünür ve kalanlar sondan başa yazılır. Örneğin 73'ü 3 tabanına çevirmek için 3'e bölünürdü. Başka bir tabandan 10 tabanına çevirmek için de basamaklar o tabanın kuvvetleriyle çarpılıp toplanır.

### 15.5 Sekizlikten ikiliğe çevirme

Soru: $17_8$'in 2 tabanındaki karşılığı nedir? Hoca önce 8 tabanından 10 tabanına, sonra 10 tabanından 2 tabanına geçileceğini söyledi; 10 tabanı arada kullanılan bir tabandır. Çözüm Örnek Sorular bölümündedir.

### 15.6 İkilik toplama

İkilik toplamada $1 + 1 = 2$'dir, ama 2 tabanında "2" yazılamaz. 0 yazılır, elde 1 olur. Burada 0 toplam (sum), 1 elde (carry) olur. $1 + 1 + 1 = 3$ olduğunda 3'ten 2 çıkarılır, 1 yazılır, elde 1 olur. Hoca bunu onluk tabana benzetti: 9 ile 2 toplanınca 11 olur, 10 çıkarılır, 1 yazılır, elde 1 olur.

Hoca slayttaki toplama işaretinin XOR işaretiyle karıştırılmaması gerektiğini, burada bir XOR işlemi olmadığını, işaretin kitaptan geldiğini söyledi. Yine de "girişler aynıysa sıfır" kısmı XOR'a benzer; fark, burada bir de elde oluşmasıdır.

Slayttaki ikilik toplamayı hoca sağdan sola şöyle yaptı:

- 1. sütun: $1 + 1 = 2$; 0 yaz, elde 1.
- 2. sütun: $0 + 1 = 1$, elde 1 ile 2; 0 yaz, elde 1.
- 3. sütun: $1 + 0 = 1$, elde 1 ile 2; 0 yaz, elde 1.
- 4. sütun: $0 + 0 = 0$, elde 1 ile 1; 1 yaz, elde yok.
- 5. sütun: $0 + 1 = 1$; 1 yaz.
- 6. sütun: $1 + 1 = 2$; 0 yaz, elde 1 en sola yazılır.

Sonuç $1011000_2$'dir. Sütunlardaki rakamlar $100101_2 + 110011_2$ toplamına uyar: $37 + 51 = 88 = 1011000_2$.

<!-- BELİRSİZ: Slayttaki iki toplananın kendisi altyazıda okunmuyor; sütun sütun söylenen rakamlardan 100101 ve 110011 olarak kuruldu. Hangi rakamın hangi satırda olduğu kesin değil, toplam aynıdır. -->

### 15.7 Onaltılık sayılar

Onaltılık (hexadecimal) sayılar 16 tabanındadır. 0'dan 15'e kadar rakamlar vardır. Ama 0 ile 15 arasındaki her değerin tek bir sembolle ifade edilmesi gerekir. Bu yüzden 9'dan sonra harfler kullanılır:

| A | B | C | D | E | F |
| :-: | :-: | :-: | :-: | :-: | :-: |
| 10 | 11 | 12 | 13 | 14 | 15 |

Hoca küçük bir toplama örneği verdi: $F + 2$. $F = 15$, $15 + 2 = 17$. 16 tabanında işlem yapıldığı için 17'den 16 çıkarılır, 1 yazılır, elde 1 olur. Sonuç $11_{16}$'dır. Kontrol: $1 \cdot 16^1 + 1 \cdot 16^0 = 16 + 1 = 17$.

### 15.8 Onaltılıktan onluğa çevirme

Örnek: $3A0B_{16}$. Basamaklar sağdan sola $16^0$, $16^1$, $16^2$, $16^3$ ile çarpılır. $A = 10$, $B = 11$'dir.

$$3A0B_{16} = 3 \cdot 16^3 + 10 \cdot 16^2 + 0 \cdot 16^1 + 11 \cdot 16^0$$
$$= 12288 + 2560 + 0 + 11 = 14859_{10}$$

> **Ders sonrası not:** Altyazıda ara toplamlardan biri "2506" diye geçiyor. $10 \cdot 16^2 = 2560$'tır. Sonuç olan 14859 doğrudur.

Tersi için 14859, 16'ya art arda bölünür ve kalanlar sondan başa okunur.

### 15.9 Onluktan onaltılığa çevirme

Örnek: $2345_{10}$.

| Bölünen | Bölüm | Kalan |
| :-: | :-: | :-: |
| 2345 | 146 | 9 |
| 146 | 9 | 2 |
| 9 | 0 | 9 |

9, 16'dan küçük olduğu için artık bölünmez. Sondan başa okunur: $2345_{10} = 929_{16}$. Bütün rakamlar 16'dan küçüktür.

Kontrol (ara adım eklendi): $9 \cdot 16^2 + 2 \cdot 16 + 9 = 2304 + 32 + 9 = 2345$.

### 15.10 Onaltılık toplama

Örnek: $23A_{16} + 8F_{16}$.

- En sağ sütun: $A + F = 10 + 15 = 25$. 16 tabanında işlem yapıldığı için 16 çıkarılır: $25 - 16 = 9$. 9 yazılır, elde 1.
- Orta sütun: $3 + 8 = 11$, elde 1 ile 12. $12 = C$.
- Sol sütun: 2 aşağı iner.

Sonuç: $23A_{16} + 8F_{16} = 2C9_{16}$.

Kontrol (ara adım eklendi): $23A_{16} = 570$, $8F_{16} = 143$, $570 + 143 = 713 = 2C9_{16}$.

> **Ek bilgi (derste anlatılmadı):** Onaltılık ve sekizlik tabanların bilgisayarda sevilmesinin sebebi, ikilikle doğrudan bağlantılı olmalarıdır. Her onaltılık rakam tam 4 bite, her sekizlik rakam tam 3 bite karşılık gelir. Bu yüzden ikilikten onaltılığa geçmek için 10 tabanına uğramak gerekmez; bitler sağdan dörderli gruplanır.

## Örnek Sorular

Bu derste video karesi yoktur. Aşağıdaki sorular hocanın derste sözlü olarak sorduğu sorulardır.

**Soru 1** (derste sözlü, 00:18:44) Aşağıdaki kümelerin eleman sayıları nedir?

- $S = \{a, b, c\}$
- $S = \{3, 3, 3, 3, 3\}$
- $S = \emptyset$
- $S = \{\emptyset, 2, \{1, 2\}\}$

> **Çözüm:** Sırasıyla 3, 1, 0 ve 3. Aynı eleman kümede bir kez sayılır. Son kümede elemanlar $\emptyset$, $2$ ve $\{1, 2\}$'dir; iç kümenin elemanları ayrıca sayılmaz.

**Soru 2** (derste sözlü, 00:32:48) $X = \{1, 2, 3\}$ ise $X$'in kuvvet kümesi nedir? Kümede 4. eleman olsaydı hangi alt kümeler eklenirdi?

> **Çözüm:** $\mathcal{P}(X) = \{\emptyset, \{1\}, \{2\}, \{3\}, \{1,2\}, \{1,3\}, \{2,3\}, \{1,2,3\}\}$, $2^3 = 8$ eleman. 4 eklenirse $\{4\}$, $\{1,4\}$, $\{2,4\}$, $\{3,4\}$, $\{1,2,4\}$, $\{1,3,4\}$, $\{2,3,4\}$, $\{1,2,3,4\}$ eklenir; toplam $2^4 = 16$. Hocanın listesinde eksik kalan $\{1,2,3,4\}$ idi.

**Soru 3** (derste sözlü, bonus sorusu, 00:43:14) Bir küme verildiğinde, kuvvet kümesini 0'dan $2^n - 1$'e kadar sayıların ikilik karşılıklarını kullanarak bulan algoritmayı en az kod satırıyla yazın ve çıktıyı gösterin.

> **Çözüm (derste verilmedi):** Derste yalnız fikir verildi: $k$ sayısının ikilik karşılığında 1 olan bitler, alt kümedeki elemanları gösterir. Aşağıdaki Python kodu bu fikri uygular. Bitler, derste çizilen tablodaki gibi soldan sağa okunur. Kod çalıştırılıp çıktısı kontrol edildi.

```python
def kuvvet_kumesi(eleman):
    n = len(eleman)
    return [[eleman[i] for i in range(n) if k >> (n - 1 - i) & 1] for k in range(2 ** n)]

print(kuvvet_kumesi([1, 2, 3]))
# [[], [3], [2], [2, 3], [1], [1, 3], [1, 2], [1, 2, 3]]
```

**Soru 4** (derste sözlü, 00:52:23) $X$ tek sayılardan, $Y$ asal sayılardan oluşuyor. $X$ ve $Y$ ayrık kümeler midir? $X$ çift sayılardan oluşsaydı?

> **Çözüm:** İki durumda da ayrık değildir. Tek sayılarla asal sayıların ortak elemanları vardır (3, 5, 7, ...). Çift sayılarla asal sayıların tek ortak elemanı 2'dir; "hayırı bozan" 2'dir.

**Soru 5** (derste sözlü, 01:28:55) Bilgisayar bilimlerinde 217 öğrenci var. 157 kişi 125 kodlu dersi, 145 kişi 173 kodlu dersi alıyor. 98 kişi iki dersi de alıyor. Kaç kişi bu iki dersten hiçbirini almıyor?

> **Çözüm:** $|A \cup B| = 157 + 145 - 98 = 204$. Hiçbirini almayan: $217 - 204 = 13$. Yalnız birinci dersi alan 59, yalnız ikinci dersi alan 47 kişidir.

**Soru 6** (derste sözlü, 01:54:19) $\displaystyle\sum_{k=4}^{8} (-1)^k$ kaçtır?

> **Çözüm:** $1 - 1 + 1 - 1 + 1 = 1$.

**Soru 7** (derste sözlü, 01:57:04) $\displaystyle\sum_{i=1}^{4} \sum_{j=1}^{3} ij$ kaçtır?

> **Çözüm:** İçteki toplam $i + 2i + 3i = 6i$. Dıştaki toplam $6 + 12 + 18 + 24 = 60$.

**Soru 8** (derste sözlü, 02:06:26) $\displaystyle\prod_{i=1}^{3} 2i$ kaçtır?

> **Çözüm:** $2 \cdot 4 \cdot 6 = 48$.

**Soru 9** (derste sözlü, 02:26:52) $\alpha_1 = a$, $\alpha_2 = baa$, $\alpha_3 = baccc$ dizgilerinin üçünü de üreten bir düzenli ifade yazın. $cb$ ve $acb$ dizgileri bu ifadeyi sağlar mı?

> **Çözüm:** `b*a+c*`. $cb$ sağlamaz, çünkü en az bir `a` gerekir. $acb$ sağlamaz, çünkü `c*`'den sonra ifade biter ve sondaki `b` ifadede yoktur. Python `re.fullmatch` ile kontrol edildi.

**Soru 10** (derste sözlü, 02:38:35) 45238 sayısı hangi tabanlarda olabilir?

> **Çözüm:** İçinde 8 rakamı olduğu için 8 ya da daha küçük tabanda olamaz. En az 9 tabanında olabilir.

**Soru 11** (derste sözlü, 02:43:10) $17_8$'in 2 tabanındaki karşılığı nedir?

> **Çözüm (derste verilmedi):** Hoca yalnız yöntemi söyledi: önce 10 tabanına, sonra 2 tabanına. $17_8 = 1 \cdot 8 + 7 = 15_{10}$. 15, 2'ye art arda bölünür: kalanlar 1, 1, 1, 1. Sonuç $1111_2$. Python ile kontrol edildi.

## Dersin Toparlaması

Bu derste kitabın 4. bölümüne başlandı. Önce kümelerin liste ve tanım gösterimi, sonlu ve sonsuz kümeler, boş ve evrensel küme, eleman sayısı, alt küme, eşitlik ve öz alt küme görüldü. Kuvvet kümesinin $2^n$ elemanı olduğu gösterildi ve kuvvet kümesini üretmek için doğruluk tablosunun, yani 0'dan $2^n - 1$'e ikilik saymanın kullanılabileceği anlatıldı. Ardından birleşim, kesişim, tümleyen, fark ve simetrik fark tanımlandı; bunların OR, AND, NOT ve XOR ile karşılığı kuruldu. Küme işlemlerinin özelliklerinin Bool cebrindeki özdeşliklerle aynı olduğu, kartezyen çarpımın değişmeli olmadığı ve içerme-dışarma ilkesiyle iki ve üç kümenin birleşiminin eleman sayısının bulunduğu görüldü.

Dersin ortak mesajı, görülen bir kavramın başka bir problemde araç olarak kullanılmasıydı: kuvvet kümesi için ikilik sayma, birleşim ve kesişim için bit dizisi üzerinde OR ve AND. Dersin ikinci yarısında diziler, alt dizi, toplam ve çarpım gösterimi, dizgiler ve düzenli ifadelere giriş, son olarak da sayı sistemleri ve taban dönüşümleri işlendi. Hoca önümüzdeki hafta fonksiyonlarla devam edeceğini ve bölümün kalan slaytlarını bitireceğini söyledi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
