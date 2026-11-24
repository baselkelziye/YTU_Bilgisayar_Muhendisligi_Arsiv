# Ders 5 Genişletilmiş Notu: Değişkenli Karnaugh Haritaları, Diziler, Bağıntılar ve Fonksiyonlar

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Bir Alt Dereceden Karnaugh Haritasıyla Çözüm
- 2. Dört Değişkenli Örneğin İki Yolla Çözümü
- 3. Beş Değişkenli Örnek
- 4. Quine-McCluskey (Tablo) Yöntemi
- 5. Diziler ve Toplam Gösterimi
- 6. Dizgiler (Strings)
- 7. Sayı Sistemleri ve Taban Aritmetiği
- 8. Bağıntılar ve Özellikleri
- 9. Denklik ve Sıralama Bağıntıları, Hasse Diyagramı
- 10. Kapanış ve Warshall Algoritması
- 11. Bağıntıların Matrisle Gösterimi
- 12. Fonksiyonlar
- Örnek Sorular
- Dersin Toparlaması

## 1. Bir Alt Dereceden Karnaugh Haritasıyla Çözüm

Ders, önceki haftadan kalan bir konuyla başladı: 5 değişkenli bir fonksiyonu 4 değişkenli bir Karnaugh haritasıyla çözmek. Hoca bu yöntemin genel adının "bir alt dereceden Karnaugh haritası kullanmak" olduğunu söyledi. Buna göre 5 değişkenli bir fonksiyon 4 değişkenli, 4 değişkenli bir fonksiyon 3 değişkenli, 3 değişkenli bir fonksiyon 2 değişkenli haritayla çözülebilir. Hoca bu yöntemi kaynak kitaplarda pek görmediğini, eski ders notlarından tekrar çalıştığını belirtti.

### 1.1 Isınma: İki Değişkenli Fonksiyon

$f(a,b)$ yalnız $ab=01$ ve $ab=10$ iken 1 olsun (ekrandan, 00:15:00). Normal $2\times 2$ haritada bu iki 1 çaprazdır. Çapraz gruplama yapılamaz (grup için 4 hücre gerekir), bu yüzden ikisi ayrı ayrı tekli gruplanır: $f=\overline{a}b+a\overline{b}$.

Aynı sonuç "bir alt dereceden" bakarak da bulunur:

- $a=0$ iken: $b=0$ için $f=0$, $b=1$ için $f=1$. Demek ki bu durumda $f=b$.
- $a=1$ iken: $b=0$ için $f=1$, $b=1$ için $f=0$. Demek ki bu durumda $f=\overline{b}$.
- Sonuç: $f=\overline{a}\cdot b + a\cdot\overline{b}$.

Hoca iki değişkenli bir fonksiyonda bunun anlamsız olduğunu, yalnız fikri göstermek için yaptığını söyledi.

### 1.2 Hücreye Değişken Yazmak

Bu yöntemin ana fikri şudur: Karnaugh haritasının hücrelerinde yalnız 0, 1 ya da "don't care" olmak zorunda değildir; bir değişken de yazılabilir. Doğruluk tablosunda son değişken dışındaki bitleri aynı olan iki satır alınır ve son değişkene göre $f$'nin davranışına bakılır:

- İkisinde de $f=0$ ise hücreye 0 yazılır.
- İkisinde de $f=1$ ise hücreye 1 yazılır.
- Son değişken 0 iken 0, 1 iken 1 ise hücreye o değişken (örneğin $d$) yazılır.
- Son değişken 0 iken 1, 1 iken 0 ise hücreye değişkenin tümleyeni ($\overline{d}$) yazılır.

### 1.3 Gray Kodu ile Etiketleme

Hoca, bazı öğrencilerin "bazı hocalar sütunları farklı yazıyor" sorusuna da değindi. Bazı kaynaklarda sütun etiketleri $\overline{c}\,\overline{d}$, $\overline{c}d$, $cd$, $c\overline{d}$ biçiminde yazılır. Hoca bunun yerine 00, 01, 11, 10 biçimindeki Gray kodunu daha genel buluyor. Değişken adları değişince (örneğin $c,d$ yerine $x,y$) harfli gösterimi dönüştürmek zorlaşabilir; Gray kodunda yalnız bir bitin değişmesi yeterlidir.

### 1.4 Dörtlü Grupların Çakışması

Önceki derste bir öğrenci "dörtlü gruplar iki kez çakışamaz" diye bir kural duyduğunu söylemişti. Hoca bunu incelediğini ve böyle bir kural olmadığını belirtti: gruplar istenildiği kadar çakışabilir.

## 2. Dört Değişkenli Örneğin İki Yolla Çözümü

Hoca 4 değişkenli bir doğruluk tablosu yazdı (ekrandan, 00:25:00 ve 00:30:00). Fonksiyon şu satırlarda 1'dir:

| $abcd$ | $f$ |
|---|---|
| 0001 | 1 |
| 0010 | 1 |
| 0011 | 1 |
| 0110 | 1 |
| 1011 | 1 |
| 1111 | 1 |

Diğer bütün satırlarda $f=0$. Yani $f=\sum m(1,2,3,6,11,15)$. Hoca değerlerin rastgele seçildiğini, gerçek bir problemden gelmediğini söyledi.

### 2.1 Dört Değişkenli Haritayla

Haritada ($ab$ satır, $cd$ sütun) dörtlü bir grup kurulamıyor, bu yüzden ikili gruplar seçildi. Açıkta 1 kalmayacak şekilde üç grup yeterli:

- $m(1,3)$: $a=0$, $b=0$, $d=1$ sabit; $c$ değişiyor. Terim: $\overline{a}\,\overline{b}d$.
- $m(2,6)$: $a=0$, $c=1$, $d=0$ sabit; $b$ değişiyor. Terim: $\overline{a}c\overline{d}$.
- $m(11,15)$: $a=1$, $c=1$, $d=1$ sabit; $b$ değişiyor. Terim: $acd$.

Sonuç (ekrandan, 00:30:00):

$$f=\overline{a}\,\overline{b}d+\overline{a}c\overline{d}+acd$$

Hoca ekranda terimleri $1\cdot\overline{a}\,\overline{b}d$ gibi yazdı: 1'ler gruplandığı için bu aslında 1 ile çarpmadır.

### 2.2 Üç Değişkenli Haritayla

Şimdi $d$ kullanılmadan $a,b,c$ ile 3 değişkenli bir harita kuruldu. İlk üç biti aynı olan satır çiftleri incelendi (ekrandan, 00:30:00):

| $abc$ | $d=0$ | $d=1$ | Hücre |
|---|---|---|---|
| 000 | 0 | 1 | $d$ |
| 001 | 1 | 1 | 1 |
| 010 | 0 | 0 | 0 |
| 011 | 1 | 0 | $\overline{d}$ |
| 100 | 0 | 0 | 0 |
| 101 | 0 | 1 | $d$ |
| 110 | 0 | 0 | 0 |
| 111 | 0 | 1 | $d$ |

Harita ($a$ satır, $bc$ sütun: 00, 01, 11, 10):

| $a \backslash bc$ | 00 | 01 | 11 | 10 |
|---|---|---|---|---|
| 0 | $d$ | 1 | $\overline{d}$ | 0 |
| 1 | 0 | $d$ | $d$ | 0 |

Gruplama kuralları:

- $d$, $d$ ile ya da 1 ile gruplanabilir. Çünkü 1 aslında $d+\overline{d}$ demektir.
- $\overline{d}$, $\overline{d}$ ile ya da 1 ile gruplanabilir.
- $d$ ile $\overline{d}$ birlikte gruplanmaz.
- Grubun terimi, değişmeyen harita değişkenleri ile hücredeki değişkenin çarpımıdır.

Gruplar:

- $d$ (000) ile 1 (001): $a=0$, $b=0$ sabit, $c$ değişiyor. Terim: $\overline{a}\,\overline{b}\cdot d$. Dörtlü bir gruba genişletilemez.
- İki $d$ (101 ve 111): $a=1$, $c=1$ sabit, $b$ değişiyor. Terim: $ac\cdot d$. $\overline{d}$ ile birleşemediği için ikili kalır.
- $\overline{d}$ (011) ile 1 (001): $a=0$, $c=1$ sabit, $b$ değişiyor. Terim: $\overline{a}c\cdot\overline{d}$.

Toplam $f=\overline{a}\,\overline{b}d+acd+\overline{a}c\overline{d}$, yani dört değişkenli haritayla bulunan sonucun aynısı.

Ortadaki 1 ayrıca gruplanmadı. Hoca bunun nedenini şöyle açıkladı: bu 1 hem $d$'li bir grupla hem $\overline{d}$'li bir grupla kapsandı, yani $d+\overline{d}$ parçalarının ikisi de alındı. Tek başına gruplansaydı $\overline{a}\,\overline{b}c$ terimi eklenirdi; ortak paranteze alınınca bu terim diğerleriyle sadeleşip giderdi, yani gereksizdir.

**Soru:** Aşağıdaki iki $d$'den biri $\overline{d}$ olsaydı nasıl gruplanacaktı? **Cevap:** $\overline{d}$ ancak $\overline{d}$ ile (ya da 1 ile) gruplanır. O durumda haritayı baştan, yeni bir örnek çözer gibi incelemek gerekir.

## 3. Beş Değişkenli Örnek

Bu örnekte 5 değişkenli bir fonksiyon, $a,b,c,d$ ile kurulan 4 değişkenli bir haritaya $e$ yazılarak verildi (ekrandan, 00:35:00):

| $ab \backslash cd$ | 00 | 01 | 11 | 10 |
|---|---|---|---|---|
| 00 | 0 | 0 | 0 | 0 |
| 01 | 0 | 0 | $e$ | 0 |
| 11 | $e$ | 1 | 1 | 1 |
| 10 | 0 | 0 | 1 | $e$ |

Hoca, bu fonksiyon 5 değişkenli doğruluk tablosundan cebirsel kurallarla ya da tablo yöntemiyle sadeleştirilseydi şu sonucun çıkacağını yazdı: ilk üç terim $e$'li gruplardan, son üç terim 1'lerin gruplarından gelir.

### 3.1 $e$'li Gruplar

Her $e$, olabildiğince büyük bir gruba alındı (ekrandan, 00:40:00):

- $abcd=1100$'deki $e$: 11 satırının tamamıyla (1100, 1101, 1111, 1110) dörtlü grup. $a$ ve $b$ değişmiyor, $c$ ve $d$ değişiyor. Terim: $abe$.
- $abcd=1010$'daki $e$: 1111, 1110, 1011, 1010 ile dörtlü grup. $a=1$ ve $c=1$ değişmiyor. Terim: $ace$.
- $abcd=0111$'deki $e$: yalnız altındaki 1111 ile ikili grup. $b$, $c$, $d$ değişmiyor, $a$ değişiyor. Terim: $bcde$.

### 3.2 1'lerin Ayrıca Gruplanması

Burada 1'ler yalnız $e$'li gruplarda kullanıldı. Hoca mantığını şöyle anlattı: büyük dörtgende 1 alınırken aslında 1'in içindeki $e$ parçası alındı; $\overline{e}$ parçası açıkta kaldı. Bu yüzden 1'ler kendi aralarında tekrar gruplanır:

- 1101 ile 1111: $a$, $b$, $d$ sabit. Terim: $abd$.
- 1111 ile 1110: $a$, $b$, $c$ sabit. Terim: $abc$.
- 1111 ile 1011: $a$, $c$, $d$ sabit. Terim: $acd$.

Bu terimlerin sonunda aslında 1 çarpanı vardır. Sonuç:

$$F=abe+ace+bcde+abd+abc+acd$$

Bu sonuç python ile 32 satırlık doğruluk tablosu üzerinde kontrol edildi ve haritadaki fonksiyonla aynı çıktı.

Hoca iki örnek arasındaki farkı vurguladı: Bölüm 2'deki örnekte 1, hem $d$ hem $\overline{d}$ ile gruplandığı için ayrıca gruplanmadı. Burada 1'ler $\overline{e}$ ile hiç gruplanmadığı için ayrıca gruplanmak zorundadır. Hoca yöntemin kafada soru işareti bırakan yerinin bu olduğunu, ama doğru hâlinin bu olduğunu söyledi.

> **Hocanın vurgusu:** $d$ ile $\overline{d}$ birlikte gruplanmaz. Bir 1'in hangi parçasının ($d$ mi $\overline{d}$ mi) kapsandığına bakılır; açıkta kalan parça varsa 1'ler ayrıca gruplanır.

Hoca bu yöntemi sınavda sormayacaklarını, ama 5 değişkenli bir soruda tablo yöntemini hatırlamayan biri için işe yarayacağını söyledi. 6 ve daha çok değişkende iki boyutlu haritalar (3 bitlik Gray kodu ya da birden fazla harita) kullanılabilir, ama ortak gruplar bulmak çok zorlaşır. Bu durumda tablo yöntemine geçilir.

## 4. Quine-McCluskey (Tablo) Yöntemi

Hoca tablo yöntemini kısaca tekrar özetledi. Yöntem şu sadeleştirmeye dayanır:

$$ABCD\overline{E}+ABCDE = ABCD(\overline{E}+E)=ABCD$$

Yani yalnız bir biti farklı iki terimden o bit atılabilir. Bunun için terimlerdeki 1 sayısına bakılır: dört 1'i olan terimler ile beş 1'i olan terimler arasında ortaklık aranır. Yöntem doğrudan bir algoritma olarak kullanılabilir. Kitaplarda tablolar uzamasın diye örnekler genelde 4 değişkenlidir, ama 7-8 değişkene de uygulanabilir.

### 4.1 Slayttaki Örnek

Ekranda açılan kaynaktaki örnek $f=\sum m(0,1,2,5,6,7,8,9,10,14)$ idi (ekrandan, 00:45:00).

**Sütun I (1 sayısına göre gruplar):**

| Grup | Mintermler |
|---|---|
| 0 | 0 (0000) |
| 1 | 1 (0001), 2 (0010), 8 (1000) |
| 2 | 5 (0101), 6 (0110), 9 (1001), 10 (1010) |
| 3 | 7 (0111), 14 (1110) |

**Sütun II:** Komşu gruplardan yalnız bir biti farklı olan çiftler birleştirilir, farklı bit "$-$" olur. Örneğin 0 ve 1: ilk üç bit aynı, dördüncü bit değişiyor, $000-$. 0 ve 2: $00-0$. 0 ve 8: $-000$. Sonra grup 1 ile grup 2 (1-5, 1-9, 2-6, 2-10, 8-9, 8-10), grup 2 ile grup 3 (5-7, 6-7, 6-14, 10-14) karşılaştırılır. İki bit farklı olanlar yazılmaz; örneğin 9 ile 7 arasında birden fazla bit farkı vardır. Ekrandaki sütun:

```text
0,1   000-      1,5   0-01      5,7   01-1
0,2   00-0      1,9   -001      6,7   011-
0,8   -000      2,6   0-10      6,14  -110
                2,10  -010      10,14 1-10
                8,9   100-
                8,10  10-0
```

**Sütun III:** Aynı yerde "$-$" bulunan ve bir biti farklı olan terimler tekrar birleştirilir. Tekrar edenler (örneğin 0,8,1,9 ile 0,1,8,9) bir kez yazılır:

```text
0,1,8,9     -00-
0,2,8,10    -0-0
2,6,10,14   --10
```

Birleşemeyen terimler (1,5), (5,7), (6,7) gibi asal çarpanlar olarak kalır. Asal çarpanlar $\overline{a}\,\overline{c}d$ (1,5), $\overline{a}bd$ (5,7), $\overline{a}bc$ (6,7), $\overline{b}\,\overline{c}$ (0,1,8,9), $\overline{b}\,\overline{d}$ (0,2,8,10), $c\overline{d}$ (2,6,10,14) olarak ekranda listelendi. Son adımda bu terimlerle bir tablo kurulur ve bütün mintermleri kapsayan en az terim seçilir. Sonuç:

$$f=\overline{a}bd+\overline{b}\,\overline{c}+c\overline{d}$$

(Sonuç python ile kontrol edildi.)

### 4.2 Terim Seçimi

Hoca ikinci bir kaynak örneği üzerinden son adımı anlattı: önce en çok minterm kapsayan asal çarpan seçilir, sonra açıkta kalan mintermler için diğer terimler eklenir. Başka terimlerle zaten kapsanan mintermleri içeren bir terimi seçmeye gerek kalmaz. <!-- BELİRSİZ: ikinci örneğin (w, x, y, z değişkenli) minterm listesi ve sonucu altyazıdan net çıkmıyor; ekran karesi yok. -->

Hoca ayrıca önceki derste anlatılan yalnız NAND ve yalnız NOR kapılarıyla devre kurma konusunun da çalışılmasını önerdi.

## 5. Diziler ve Toplam Gösterimi

Bundan sonra slaytlara dönüldü. Kümeler ve kartezyen çarpım önceki derste bitmişti.

### 5.1 Dizi Tanımı

Slayttaki tanım (ekrandan, 00:50:00): Düzenli dizi (sequence), sıralı bir listeyi göstermek için kullanılan ayrık yapıdır. $s_n$, $n$'nin bir fonksiyonudur ve $n=1,2,3,\dots$ olur. $s_1$ birinci, $s_2$ ikinci, $s_n$ $n$. elemanı gösterir. $\{n\}$ dizinin indeksidir; doğal sayılardan ya da onların sonlu bir alt kümesinden oluşur.

Hoca diziyi programlamadaki diziler gibi düşünebileceğimizi söyledi. Dizi aslında bir fonksiyondur, ama sürekli değildir: $f(x)$'te $x$ gerçel sayı olabilirken dizide indis $n$ doğal sayıdır. Bu yüzden dizi, fonksiyonların birçok özelliğine sahiptir.

### 5.2 Artan, Azalan ve Alt Dizi

- Bütün $n$ için $s_n < s_{n+1}$ ise dizi artandır; $s_n > s_{n+1}$ ise azalandır.
- Kural bir yerde bozuluyorsa (örneğin artıp artıp bir anda düşüyorsa) dizi ne artan ne azalandır.
- Alt dizi (subsequence): $s$ dizisinin elemanlarından, sıralama korunarak elde edilen dizidir. Örnek: $s_n=n$ (sayma sayıları) ve $t_n=2n$ (çift sayılar). $t$, $s$'nin bir alt dizisidir.

### 5.3 Toplam ve Çarpım Gösterimi

$\sum_{i=m}^{n} a_i = a_m+a_{m+1}+\dots+a_n$ bir alt sınırdan üst sınıra kadar terimleri bir kurala göre toplar. $\prod$ aynı işin çarpma versiyonudur. Hoca bu gösterimin algoritma analizinde çok kullanılacağını söyledi: `for (i = 0; i < n; i++)` gibi bir döngünün adım sayısı bir toplam olarak yazılır ve adım sayısına bağlı bir $f(n)$ fonksiyonu elde edilir.

Ekrandaki iki örnek (ekrandan, 00:55:00):

$$\sum_{k=4}^{8}(-1)^k = (-1)^4+(-1)^5+(-1)^6+(-1)^7+(-1)^8 = 1-1+1-1+1 = 1$$

Ardışık terimler birbirini götürür ve geriye $+1$ kalır.

$$\sum_{i=1}^{4}\sum_{j=1}^{3} ij$$

- Önce içteki toplam: $j=1,2,3$ için $i+2i+3i=6i$.
- Sonra dıştaki: $\sum_{i=1}^{4}6i = 6\sum_{i=1}^{4} i = 6\cdot\frac{4\cdot 5}{2} = 6\cdot 10 = 60$.
- Ekrandaki açık hâli: $6+12+18+24=60$.

## 6. Dizgiler (Strings)

Diziler yalnız sayılardan oluşmaz; karakterlerden de oluşabilir. Bir alfabeden (kümeden) belli bir kurala göre farklı uzunlukta dizgiler yazılabilir. Hoca bu konunun ileride düzenli ifadeler (regular expressions) konusunda tekrar geleceğini söyledi.

- $|\alpha|$: dizginin uzunluğu, yani karakter sayısı.
- $\lambda$: boş dizgi. Hoca bunun boşluk karakteri (space) olmadığını, "hiçbir şey" demek olduğunu vurguladı; C'deki `\0` sonlandırıcısına benzetti.
- $X^*$ (Kleene yıldızı): boş dizgi dahil, $X$ üzerindeki bütün dizgilerin kümesi.
- $X^+$: $X^*$'tan yalnız boş dizginin çıkarılmasıyla elde edilen, boş olmayan dizgiler.
- Birleştirme (concatenation): bir dizgiyi diğerinin sonuna eklemek. $|\alpha\beta|=|\alpha|+|\beta|$.

### 6.1 Run Length Encoding

Hoca, kurallı dizgilerin kısa yazılmasına örnek olarak run length encoding (RLE) yöntemini anlattı: peş peşe gelen aynı karakterler, karakter ve tekrar sayısıyla (üs olarak) yazılır. Örneğin $bbaccccaaba$ dizgisi $b^2ac^4a^2ba$ olarak yazılır. <!-- BELİRSİZ: slayttaki dizgi altyazıdan kuruldu, ekran karesi yok. --> Dört $c$ iki sembolle yazıldığı için o kısım yarıya iner. Hoca yöntemin özellikle 3 ve daha uzun tekrarlarda işe yaradığını, 2 tekrarda pek kazanç olmadığını, tek karakterde hiç anlamı olmadığını söyledi.

## 7. Sayı Sistemleri ve Taban Aritmetiği

Hoca ikili, sekizli, onlu ve onaltılı sistemlerin ve aralarındaki dönüşümlerin başka derslerde de görüldüğünü, bu yüzden ayrıntıya girmeyeceğini ama çok iyi bilinmesi gerektiğini söyledi (ekrandan, 01:00:00).

Onlu sistemde $45238 = 4\cdot 10^4+5\cdot 10^3+2\cdot 10^2+3\cdot 10+8$ biçiminde basamak değerleriyle yazılır (slayttaki örnek, ekrandan, 01:00:00).

> **Hocanın vurgusu:** $x$ tabanındaki bir sayıda bütün basamaklar için $a_i < x$ olmalıdır. Bunu hâlâ unutanlar var.

### 7.1 Elde Mantığı

Hoca her zaman verdiği örneği hatırlattı: $38+76$ toplamında $8+6=14$, "14'ün 4'ü, elde 1" denir. Burada aslında $14-10=4$ yapılır; çıkarılan 10 tabandır. Onaltılı sistemde aynı işlem 16 ile yapılır. Hatırlatma: $A=10$, $B=11$, ..., $F=15$.

### 7.2 Onaltılı Toplama Örneği

$2EF6_{16}+32EB_{16}$ (ekrandan, 01:05:00):

- Birler: $6+B=6+11=17$. $17-16=1$, yaz 1, elde 1.
- Onaltılar: $F+E+1=15+14+1=30$. $30-16=14=E$, yaz $E$, elde 1.
- Sonraki: $E+2+1=14+2+1=17$. $17-16=1$, yaz 1, elde 1.
- Son: $2+3+1=6$.
- Sonuç: $61E1_{16}$.

Onaltılı toplama zor gelirse sayılar ikiliye çevrilip toplanabilir: her onaltılı basamak 4 bittir ($2=0010$, $E=1110$, $F=1111$, $6=0110$, $3=0011$, $B=1011$). İkili toplamın sonucu tekrar dörder bitlik gruplara ayrılır ve aynı sonuç $61E1$ bulunur. Hoca sağlamayı ekranda bu yolla yaptı.

### 7.3 İkili Toplama, Elde ve Taşma

İkili toplamada $0+0=0$, $0+1=1$, $1+0=1$, $1+1=10$ olur. $1+1$'de oluşan bit elde bitidir; işlemcide durum yazmacındaki (status register) elde bayrağı (carry flag) bu durumda 1 olur. İşaretsiz sayılarda sonuç buna göre yorumlanır. İşaretli sayılarda ise taşma bayrağı (overflow flag) son bitlerdeki elde aktarımına bakarak negatif ile pozitif arasında geçiş olup olmadığını kontrol eder. Hoca ayrıntıların Assembly, bilgisayar donanımı, mantık devreleri ve mikroişlemciler derslerinde görüleceğini söyledi.

### 7.4 Slayttaki Onaltılı Toplama

$23A_{16}+8F_{16}$ (ekrandan, 01:20:00):

- $A+F=10+15=25$. $25-16=9$, yaz 9, elde 1.
- $3+8+1=12=C$. 16'dan küçük olduğu için elde yok.
- $2$ aynen iner.
- Sonuç: $2C9_{16}$.

## 8. Bağıntılar ve Özellikleri

### 8.1 Tanım

$A$ ve $B$ kümelerinin elemanlarından yazılabilecek bütün sıralı ikililer kartezyen çarpımı oluşturur: $A\times B=\{(a,b)\mid a\in A,\ b\in B\}$. Kartezyen çarpımın her alt kümesine bir bağıntı denir: $R\subseteq X\times Y$ ise $R$, $X$'ten $Y$'ye bir ikili bağıntıdır.

Slayttaki örnekte $X\times Y$ altı elemanlıdır ve bunun bir alt kümesi olan $\{(1,a),(1,b),(2,b),(3,a)\}$ bir bağıntıdır. Sıralı ikililerde sıra önemlidir: $X\times Y \ne Y\times X$.

- Tanım kümesi (domain): bağıntıda ilk bileşen olarak görünen $x$'ler.
- Değer kümesi (range): ikinci bileşen olarak görünen $y$'ler.

Hoca bağıntıların daha çok matrislerde ve çizgelerde kullanılacağını söyledi. Bir bağıntı koordinat düzleminde de gösterilebilir: yatay eksende tanım, dikey eksende değer kümesi; ilişki olan yere bir nokta ya da 1 konur.

### 8.2 Yansıma (Reflexivity)

- **Refleksif:** kümedeki her $x$ için $(x,x)\in R$.
- **Non-refleksif:** bazı elemanlar için $(x,x)$ var, bazıları için yok.
- **İrrefleksif:** hiçbir $x$ için $(x,x)$ yok.

### 8.3 Simetri ve Antisimetri

Slayttaki tanım (ekrandan, 01:25:00): $R$ simetriktir, eğer $(x,y)\in R$ olduğunda $(y,x)\in R$ ise (ya da $(x,y)\notin R$ iken $(y,x)\notin R$ ise ya da $x=y$ ise). Hoca önemli noktayı şöyle vurguladı: $(x,y)$ yokken $(y,x)$ varsa bağıntı simetrik olmaz. Bu kuralı bozan bağıntılar için antisimetri tanımına bakılır.

> **Ek bilgi (derste anlatılmadı):** Antisimetri, simetrinin değillemesi değildir. $R$ antisimetriktir, eğer $(x,y)\in R$ ve $(y,x)\in R$ olduğunda $x=y$ ise. Bir bağıntı hem simetrik hem antisimetrik olabilir (örneğin yalnız $(x,x)$ ikililerinden oluşan bağıntı), ya da ikisi de olmayabilir.

### 8.4 Geçişme (Transitivity)

$(x,y)\in R$ ve $(y,z)\in R$ olduğunda $(x,z)\in R$ de varsa bağıntı geçişkendir. Hoca geçişkenliği veritabanından bir örnekle anlattı: öğrenciler bir tabloda, dersler başka bir tabloda tutulur. Öğrencinin derse kaydı için arada bir ara tablo (öğrenci kimliği, ders kimliği) oluşturulur. Bu tablo sayesinde bir öğrencinin ders listesi çıkarılabilir; üç tablo arasında bu tür bir geçişkenlik ilişkisi vardır.

### 8.5 Örnek: $a=b^2$

$A=\{1,2,3,4\}$ üzerinde $(a,b)\in R \iff a=b^2$ (ekrandan, 01:30:00). Bağıntı: $R=\{(1,1),(4,2)\}$. ($b=2$ için $a=4$; $b=3,4$ için $a$ kümede yok.)

- Refleksif mi? Hayır: $(1,1)$ var ama $(2,2)$, $(3,3)$, $(4,4)$ yok.
- Non-refleksif mi? Evet, $(1,1)$ var.
- İrrefleksif mi? Hayır, en az bir eleman ($(1,1)$) sağlıyor.
- Simetrik mi? Hayır: $(4,2)$ var ama $(2,4)$ yok.
- Antisimetrik mi? Evet.
- Geçişken mi? Evet. $(1,1)$'den sonra 1 ile başlayan başka ikili, $(4,2)$'den sonra 2 ile başlayan ikili yok; koşul hiç tetiklenmiyor. Örneğin $(2,3)$ olsaydı $(4,3)$'ün de olması gerekirdi.

> **Ders sonrası not:** Hoca antisimetriyi "simetri özelliğini sağlamadığı için" diye gerekçelendirdi. Sonuç doğrudur, ama gerekçe şudur: $(x,y)$ ve $(y,x)$'in ikisinin birden bulunduğu, $x\ne y$ olan bir çift yoktur.

Hoca boş bağıntının da geçişken olduğunu ekledi: koşulu bozacak hiçbir ikili yoktur.

### 8.6 Ters Bağıntı ve Bileşke

- Ters bağıntı: sıralı ikililerin bileşenleri yer değiştirir. Ters bağıntı genelde bağıntıyla aynı değildir.
- Bileşke: bir bağıntının başka bir bağıntıyla (ya da kendisiyle) birleşerek yeni bir bağıntı oluşturması. Slaytta $R^2=R\circ R$ ve $R^3$ bulundu. <!-- BELİRSİZ: slayttaki R ve R^2 elemanları altyazıdan tam çıkmıyor; ekran karesi yok. -->

### 8.7 Örnek: Farklı Bağıntıların Özellikleri

$A=\{1,2,3,4\}$ üzerinde (ekrandan, 01:35:00; R: refleksif, NR: non-refleksif, S: simetrik, NS: simetrik değil, NAS: antisimetrik değil, T: geçişken):

**$\{(2,2),(2,3),(2,4),(3,2),(3,3),(3,4)\}$ → NR, NS, NAS, T**

- $(2,2)$ ve $(3,3)$ var ama $(1,1)$ ve $(4,4)$ yok: non-refleksif.
- $(2,3)$ ve $(3,2)$ var, ama $(2,4)$ varken $(4,2)$ yok: simetrik değil.
- $(2,3)$ ve $(3,2)$'nin ikisi birden olduğu için antisimetrik de değil.
- Geçişken: örneğin $(2,3),(3,2)\Rightarrow(2,2)$ var; $(2,3),(3,4)\Rightarrow(2,4)$ var.

**$\{(1,1),(1,2),(2,1),(2,2),(3,3),(4,4)\}$ → R, S, NAS, T**

- Bütün $(x,x)$ var: refleksif.
- $(1,2)$ varken $(2,1)$ var: simetrik.
- Geçişken: $(1,2),(2,1)\Rightarrow(1,1)$; $(1,2),(2,2)\Rightarrow(1,2)$ zaten var.

> **Ders sonrası not:** Hoca bu bağıntı için bir yerde "asimetrik oluyor" dedi. Slayttaki doğru sınıflama "simetrik ve antisimetrik değil" (S, NAS) şeklindedir. Her iki bağıntının özellikleri python ile kontrol edildi.

Hoca $\{(2,4),(4,2)\}$, $\{(1,2),(2,3),(3,4)\}$, $\{(1,1),(2,2),(3,3),(4,4)\}$ ve $\{(1,3),(1,4),(2,3),(2,4),(3,1),(3,4)\}$ bağıntılarını çalışmaya bıraktı.

## 9. Denklik ve Sıralama Bağıntıları, Hasse Diyagramı

### 9.1 Denklik Bağıntısı

Bir bağıntı refleksif, simetrik ve geçişken ise denklik bağıntısıdır (equivalence relation). Hoca bu kısıtların fonksiyon tanımına giden yolda karşımıza çıktığını söyledi: her bağıntı fonksiyon değildir.

Slayttaki ilk örnek $\{1,2,3\}$ üzerinde tanımlıydı ve $(1,1),(2,2),(3,3)$ ile $(1,2),(2,1),(1,3),(3,1),(2,3),(3,2)$ ikililerini içeriyordu. Refleksif, simetrik ve geçişkendir (örneğin $(1,2),(2,1)\Rightarrow(1,1)$); bu yüzden denklik bağıntısıdır.

İkinci örnekte $x-y=5$ koşuluyla verilen bağıntı incelendi. Örneğin $(6,1)$ bu koşulu sağlar. $(1,1)$ ve $(6,6)$ bulunmadığı için refleksif değildir; $(6,1)$ varken $(1,6)$ olmadığı için simetrik değildir. Bu yüzden denklik bağıntısı değildir. <!-- BELİRSİZ: bu bağıntının tanımlandığı küme altyazıdan net çıkmıyor; ekran karesi yok. -->

### 9.2 Örnek: Denklik Bağıntısı mı?

$X=\{1,2,3,4,5,6\}$ üzerinde (ekrandan, 01:40:00):

$$R=\{(1,1),(1,3),(1,5),(3,1),(3,3),(3,5),(5,1),(5,3),(5,5),(2,2),(2,6),(6,2),(6,6),(4,4)\}$$

- Refleksif: $(1,1)$, $(2,2)$, $(3,3)$, $(4,4)$, $(5,5)$, $(6,6)$ var.
- Simetrik: $(1,3)$–$(3,1)$, $(1,5)$–$(5,1)$, $(2,6)$–$(6,2)$, $(3,5)$–$(5,3)$ çiftleri var.
- Geçişken: $(1,5)$ için 5 ile başlayan bütün ikililere bakılır. $(5,1)\Rightarrow(1,1)$ var, $(5,3)\Rightarrow(1,3)$ var, $(5,5)\Rightarrow(1,5)$ var. Diğerleri de benzer şekilde sağlanır.
- Sonuç: **Evet**, denklik bağıntısıdır (python ile kontrol edildi).

Hoca geçişkenliği elle kontrol etmenin yorucu olduğunu, her $(x,y)$ için $y$ ile başlayan bütün ikililere bakmak gerektiğini söyledi.

> **Ek bilgi (derste anlatılmadı):** Bu bağıntı $X$'i $\{1,3,5\}$, $\{2,6\}$, $\{4\}$ denklik sınıflarına ayırır. Her sınıfın içindeki bütün ikililer bağıntıdadır, sınıflar arasında ikili yoktur.

### 9.3 Sıralama Bağıntısı

Bir bağıntı refleksif, antisimetrik ve geçişken ise sıralama bağıntısıdır (partial order). Denklik bağıntısından farkı, simetrik yerine antisimetrik olmasıdır.

Hoca bağıntılardan fonksiyonların, fonksiyonlardan işlemlerin (operation) türetildiğini söyledi. Bu dersin ilk açıldığı yıllarda soyut matematik kapsamında cebirsel yapılar (grup, Abel grubu, halka) da anlatılıyordu. Örneğin mod 26'da her elemanın çarpmaya göre tersi olmadığı için çarpma bir Abel grubu oluşturmaz, toplama oluşturur. Hoca bunun bir bilgisayar mühendisi için çok gerekli olmadığını, ama kriptoloji çalışacak olanların cebirsel yapılardan haberdar olması gerektiğini söyledi; kriptolojide sonlu uzaylar üzerinde çalışılır.

Örnek: $\{1,2,3,4\}$ üzerinde "$x$, $y$'yi böler" bağıntısı $\{(1,1),(2,2),(3,3),(4,4),(1,2),(1,3),(1,4),(2,4)\}$'tür.

- Refleksif: bütün $(x,x)$ var.
- Antisimetrik: $(1,2)$ varken $(2,1)$ yok, $(1,3)$ varken $(3,1)$ yok, $(1,4)$ varken $(4,1)$ yok.
- Geçişken: örneğin $(1,2),(2,4)\Rightarrow(1,4)$ var.
- Sonuç: sıralama bağıntısıdır.

### 9.4 Hasse Diyagramı

Sıralama bağıntılarını grafiksel gösteren diyagramdır. Örnek (ekrandan, 01:45:00): $X=\{1,2,3,4\}$ üzerinde $a\le b$ bağıntısı

$$R=\{(1,1),(2,2),(3,3),(4,4),(1,2),(1,3),(1,4),(2,3),(2,4),(3,4)\}$$

- Eşitlik içerdiği için refleksiftir.
- $(1,2)$ varken hiçbir zaman $(2,1)$ olmaz: antisimetriktir.
- $(1,2),(2,3)\Rightarrow(1,3)$, $(1,3),(3,4)\Rightarrow(1,4)$: geçişkendir.

Bağıntının yönlü grafiği çizildiğinde her düğümde kendine dönen bir döngü (refleksiflik) vardır. Elemanlar küçükten büyüğe dizildiğinde bütün oklar aynı yöne (yukarı) gider; bir kısmı aşağı, bir kısmı yukarı gitmez. Hasse diyagramı için:

- Refleksiflikten gelen döngüler silinir.
- Geçişkenlikten gelen oklar (örneğin $1\to3$, $1\to4$, $2\to4$) silinir.
- Geriye $1\to2\to3\to4$ zinciri kalır.

## 10. Kapanış ve Warshall Algoritması

Bir bağıntıda refleksif, simetrik ya da geçişken özellik yoksa, bağıntıya ikililer ekleyerek bu özelliği kazandırma işlemine kapanış (closure) denir. Geçişken kapanış için Warshall algoritması kullanılır.

Slayttaki örnekte $\{a,b,c,d\}$ üzerindeki bağıntı geçişken değildi: örneğin $(b,a)$ ve $(a,d)$ var ama $(b,d)$ yok. Bağıntı matrisle yazıldı: satır ve sütunlara $a,b,c,d$ konur, ilişki varsa 1, yoksa 0.

Algoritma (ekrandan, 01:50:00):

```text
procedure warshall
  W = M_R
  for k = 1, n
    for i = 1, n
      for j = 1, n
        W_ij = W_ij ∨ (W_ik ∧ W_kj)
      end
    end
  end
```

Hoca ilk adımda $i=j=k=1$ için $W_{11}=0\lor(0\land 0)=0$ olduğunu gösterdi: 0 olan hücre, yol bulunamazsa 0 kalır. Ekrandaki ara matrisler:

$$W_1=\begin{bmatrix}0&0&0&1\\1&0&1&1\\1&0&0&1\\0&0&1&0\end{bmatrix},\qquad W_2=\begin{bmatrix}0&0&0&1\\1&0&1&1\\1&0&0&1\\0&0&1&0\end{bmatrix}$$

$k=1$ adımında $b$ satırına $(b,d)$ eklendi ($b\to a\to d$). Bir hücreye 1 eklemek, iki eleman arasına bir yol (bağıntı) eklemek demektir. Hoca bunun matrisin karesini almaya benzediğini ve ayrıntısının çizgeler konusunda görüleceğini söyledi.

> **Ders sonrası not:** Derste yalnız $W_1$ ve $W_2$ gösterildi. Başlangıç matrisi büyük olasılıkla $M_R$'de $b$ satırı $1010$ olan matristir ($W_1$'den geriye doğru kuruldu). Bu matrisle algoritma python ile sonuna kadar çalıştırıldığında $W_4$'te bütün satırlar $1011$ çıkar; yani geçişken kapanışta her eleman $a$, $c$ ve $d$'ye ulaşır, $b$'ye hiçbir eleman ulaşmaz.

### 10.1 Diller Örneği

Slayttaki örnekte farklı ülkelerden kişiler ($A_1,\dots$) ve beş dil ($B_1,\dots,B_5$) vardı. "Kim hangi dili konuşuyor" bağıntısı bir matrisle, "hangi dil kimler tarafından konuşuluyor" bağıntısı bunun tersiyle (satır ve sütunlar yer değiştirmiş hâliyle) gösterilir. İki matris çarpılırsa "kim kiminle konuşabilir" bağıntısı bulunur. Örneğin $A_3$, $B_3$ ve $B_5$ dillerini biliyor; bu dilleri bilen $A_4$ ve $A_6$ ile (ve kendisiyle) konuşabilir. Hoca ders kaydı örneğindeki ara tablonun da benzer bir mantıkla çalıştığını söyledi.

Hoca yapısal programlama dersi için alıştırma önerdi: bir bağıntıyı dizilerde saklayıp yansıma, simetri, antisimetri ve geçişme özelliklerini kontrol eden bir kod yazmak. Böylece hem C hem bu ders çalışılmış olur.

## 11. Bağıntıların Matrisle Gösterimi

İkili bağıntılar matrisle gösterilebilir; bu, bilgisayarcı bakış açısına çok uygundur ve çizgelerde ya da başka veri yapılarında kullanılır. Bir küme satırlara, diğeri sütunlara yazılır; ilişki varsa 1, yoksa 0 konur.

Slayttaki örnekte $\{1,2,3\}$'ten $\{a,b,c,d\}$'ye bir bağıntı $3\times 4$'lük bir matrisle gösterildi: $(1,a)$, $(1,d)$, $(2,a)$, $(2,b)$, $(2,c)$ gibi ikililerin yerine 1 yazıldı. Hoca satır ve sütunları diller ve konuşanlar ya da şehirler ve aralarındaki yollar olarak düşünmeyi önerdi: hangi şehirden hangisine tek seferde gidilebildiği, tek komşulu ve çift komşulu iller gibi ilişkiler buradan çıkar.

- Bir kümeden kendisine tanımlı bağıntının matrisi kare matristir.
- Bağıntı refleksifse matrisin köşegeni 1'dir.

## 12. Fonksiyonlar

### 12.1 Tanım

Fonksiyon, bağıntının özel bir hâlidir (ekrandan, 02:10:00). $f: X\to Y$ yazılır; $X$ tanım kümesi (domain), $Y$ değer kümesidir (range). İngilizce tanım: $A$'nın her elemanına $B$'nin tam bir elemanının atanmasıdır. İki şart vardır:

- Tanım kümesinde hiçbir eleman boşta kalmaz (bağıntıda kalabilir).
- Bir eleman karşı tarafta en fazla bir elemanla eşleşir. İki eleman aynı elemana gidebilir, ama bir eleman iki elemana gidemez.

Slayttaki örnek: $X=\{a,b,c,d\}$, $Y=\{1,2,3,4,5\}$, $f(a)=f(b)=3$, $f(c)=5$, $f(d)=1$. Değer kümesinin alt kümesi olan $\{1,3,5\}$'e görüntü kümesi denir.

Grafikle düşünülürse: bir fonksiyonun grafiğini dikey bir doğru en fazla bir noktada keser. Bir $x$'e iki görüntü düşüyorsa fonksiyon değildir.

Bağıntının fonksiyon olup olmadığına bakan örneklerde:

- $\{(1,a),(2,b),(3,a)\}$: fonksiyondur; 3'ün $a$'ya gitmesi sorun değil.
- $\{(1,a),(2,b),(3,c),(1,b)\}$: fonksiyon değildir; 1 iki farklı yere gidiyor.

### 12.2 Birebir, Örten ve Bijektif Fonksiyonlar

- **Birebir (one-to-one):** her $y$ en fazla bir $x$'in görüntüsüdür. Eşdeğer tanım (çift yönlü "ancak ve ancak"): $x_1\ne x_2$ ise $f(x_1)\ne f(x_2)$. Örnek: $\mathbb{R}\to\mathbb{R}$, $f(x)=2^x$ birebirdir. $f(x)=x^2$ birebir değildir, çünkü $2$ ve $-2$ aynı yere (4'e) gider.
- **Örten (onto):** değer kümesindeki her $y$ için en az bir $x$ vardır; değer kümesinde boşta eleman kalmaz, yani değer kümesi görüntü kümesine eşittir.
- **Bijektif (birebir ve örten):** her iki şartı sağlar (ekrandan, 02:15:00). Örnekler: gerçel sayılardan gerçel sayılara $f(x)=ax+b$ (doğrusal, afin fonksiyon) ve $f(x)=x^3$.

Ok diyagramı örneklerinde: bir diyagramda her elemanın ayrı görüntüsü vardı ama değer kümesinde boşta eleman kalıyordu (birebir, örten değil). Diğerinde iki eleman aynı yere gidiyordu ama boşta eleman yoktu (örten, birebir değil). Bir diyagram hem birebir hem örtendi, bir diyagram ikisi de değildi. Son diyagramda bir eleman iki yere gittiği için fonksiyon değildi.

### 12.3 Ters Fonksiyon

Ters fonksiyon $f^{-1}$, tanım kümesi ile görüntü kümesinin yer değiştirmesidir. Tersin fonksiyon olması gerekmez: $f(x)=x^2$ için $f^{-1}(4)=\pm 2$ olur. Bijektif bir fonksiyonun tersi de fonksiyondur; doğrusal ve afin fonksiyonların tersi de fonksiyondur.

Ters fonksiyonu bulma adımları:

- $y=f(x)$ yaz.
- $x$'i yalnız bırak.
- $x$ ile $y$'nin yerini değiştir.

Örnekler:

- $y=x+1$: $x=y-1$, yer değiştirince $f^{-1}(x)=x-1$.
- $y=ax+b$: $x=\frac{y-b}{a}$, yer değiştirince $f^{-1}(x)=\frac{x-b}{a}$.

İkinci dereceden $y=ax^2+bx+c$ için de aynı yol izlenir; slaytta adım adım çözüm vardı.

### 12.4 Bileşke, Üstel ve Logaritmik Fonksiyonlar

- Bileşke: $f: X\to Y$ ve $g: Y\to Z$ ise $X$'ten doğrudan $Z$'ye geçiş. $f\circ g$'de $f$'nin içinde $x$ görülen yere $g(x)$ yazılır; örneğin $x$ yerine $x^2-1$.
- Bileşkede birleşme özelliği vardır: $(f\circ g)\circ h=f\circ(g\circ h)$. Değişme özelliği yoktur.
- Üstel ve logaritmik fonksiyonlar birbirinin tersidir: $2^{\log_2 x}=x$ ve $\log_2 2^x=x$. Bilgisayarda en çok 2 ve $e$ tabanı kullanılır.
- Bir dizginin tersi, dizginin sondan başa yazılmasıdır.

### 12.5 Taban ve Tavan Fonksiyonları

Taban (floor) $\lfloor x\rfloor$, $x$'ten küçük ya da eşit en büyük tam sayıdır; tavan (ceiling) $\lceil x\rceil$, $x$'ten büyük ya da eşit en küçük tam sayıdır. Slayttaki taban örnekleri: $\lfloor 8.3\rfloor=8$, $\lfloor 1/2\rfloor=0$, $\lfloor 7\rfloor=7$, $\lfloor -1/2\rfloor=-1$; negatif bir ondalıklı sayının tabanı bir alttaki tam sayıdır ($-9$ gibi). <!-- BELİRSİZ: slayttaki sayıların bir kısmı altyazıdan tam okunmuyor; ekran karesi yok. -->

## Örnek Sorular

**Soru 1** (ekrandan, 00:25:00 - 00:30:00): $f=\sum m(1,2,3,6,11,15)$ fonksiyonunu önce 4 değişkenli, sonra $a,b,c$ ile 3 değişkenli (hücrelerine $d$ yazılan) Karnaugh haritasıyla sadeleştirin.

> **Çözüm:** İki yolla da $f=\overline{a}\,\overline{b}d+\overline{a}c\overline{d}+acd$ (Bölüm 2).

**Soru 2** (ekrandan, 00:35:00): Hücreleri $abcd=0111, 1100, 1010$ için $e$; $1101, 1111, 1110, 1011$ için 1; diğerleri 0 olan 4 değişkenli haritadaki 5 değişkenli fonksiyonu sadeleştirin.

> **Çözüm:** $F=abe+ace+bcde+abd+abc+acd$ (Bölüm 3).

**Soru 3** (ekrandan, 00:45:00): $f=\sum m(0,1,2,5,6,7,8,9,10,14)$ fonksiyonunu Quine-McCluskey yöntemiyle sadeleştirin.

> **Çözüm:** $f=\overline{a}bd+\overline{b}\,\overline{c}+c\overline{d}$ (Bölüm 4).

**Soru 4** (ekrandan, 00:55:00): $\sum_{k=4}^{8}(-1)^k$ ve $\sum_{i=1}^{4}\sum_{j=1}^{3} ij$ değerlerini bulun.

> **Çözüm:** $1$ ve $60$ (Bölüm 5.3).

**Soru 5** (ekrandan, 01:20:00): $23A_{16}+8F_{16}$ toplamını bulun.

> **Çözüm:** $2C9_{16}$ (Bölüm 7.4).

**Soru 6** (ekrandan, 01:30:00): $A=\{1,2,3,4\}$ üzerinde $(a,b)\in R \iff a=b^2$. Bağıntıyı yazın ve hangi özelliklerin olduğunu söyleyin.

> **Çözüm:** $R=\{(1,1),(4,2)\}$; refleksif değil, non-refleksif, irrefleksif değil, simetrik değil, antisimetrik, geçişken (Bölüm 8.5).

**Soru 7** (ekrandan, 01:40:00): $X=\{1,\dots,6\}$ üzerindeki $R=\{(1,1),(1,3),(1,5),(3,1),(3,3),(3,5),(5,1),(5,3),(5,5),(2,2),(2,6),(6,2),(6,6),(4,4)\}$ bir denklik bağıntısı mıdır?

> **Çözüm:** Evet; refleksif, simetrik ve geçişkendir (Bölüm 9.2).

**Soru 8** (derste sözlü, 02:23:22): Verilen $A$, $B$, $C$ kümeleri için $A\cup B$, $B-A$, $\overline{U}$, $A\cup U$ ve $\overline{B}\cap(C-A)$ kümelerini bulun. <!-- BELİRSİZ: kümelerin elemanları altyazıdan çıkmıyor; ekran karesi yok. -->

> **Çözüm (derste):** $\overline{U}=\varnothing$, $A\cup U=U$. Derste $\overline{B}=\{2,4,6,8\}$ ve $C-A$ ile kesişimi $\{6,8\}$ bulundu.

**Soru 9** (ekrandan, 02:25:00): Venn diyagramında $A\cap\overline{B}$ ve $((C\cap A)-\overline{(B-A)})\cap C$ kümelerini taralayın.

> **Çözüm:** $A\cap\overline{B}$, $A$'nın $B$ dışında kalan kısmıdır. İkinci ifadeyi hoca diyagram üzerinde adım adım taradı ve sonucun tekrar kontrol edilmesi gerektiğini söyledi.

> **Ders sonrası not:** $\overline{(B-A)}=\overline{B}\cup A$ olduğundan $(C\cap A)-\overline{(B-A)} = C\cap A\cap B\cap\overline{A}=\varnothing$. Yani ikinci ifadenin sonucu boş kümedir; diyagramda taranacak bölge yoktur (python ile 8 bölge üzerinden kontrol edildi). Hoca diyagramda bir bölge bırakmıştı.

**Soru 10** (derste sözlü, 02:26:09): $X$, $Y$, $Z$ evrensel kümenin alt kümeleridir. $(X\cap Y)\cup(Y-X)=X$ doğru mudur?

> **Çözüm (derste):** Yanlış. $X\cap Y$ ile $Y-X$'in birleşimi $Y$'ye eşittir, $X$'e değil.

**Soru 11** (derste sözlü, 02:27:27): $a_i=i^2-3i+3$ için $\sum_{i=1}^{4}a_i$ ve $\prod_{i=3}^{4}a_i$ değerlerini bulun. <!-- BELİRSİZ: dizinin kuralı ve çarpımın sınırları altyazıdaki hesaptan kuruldu; ekran karesi yok. -->

> **Çözüm (derste):** $\sum i^2 - 3\sum i + 3\cdot 4 = (1+4+9+16) - 3\cdot 10 + 12 = 30-30+12=12$. Hoca $\sum_{i=1}^{n} i^2=\frac{n(n+1)(2n+1)}{6}$ formülünü hatırlattı. Çarpım: $(9-9+3)\cdot(16-12+3)=3\cdot 7=21$.

**Soru 12** (ekrandan, 02:30:00): $y_i=2^i-1$ ve $z_i=i(i-1)$ dizileri için $\left(\sum_{i=1}^{3}y_i\right)\left(\sum_{i=1}^{3}z_i\right)$ değerini bulun.

> **Çözüm (derste verilmedi):** $y_1,y_2,y_3=1,3,7$, toplam 11. $z_1,z_2,z_3=0,2,6$, toplam 8. Sonuç $11\cdot 8=88$ (python ile kontrol edildi).

**Soru 13** (derste sözlü, 02:30:23): Verilen bir sayı ikili, sekizli, onlu ve onaltılı sistemde bir sayı olabilir mi? <!-- BELİRSİZ: sayının basamakları altyazıdan tam okunmuyor; içinde 9 rakamı var. -->

> **Çözüm (derste):** İkili olamaz (yalnız 0 ve 1 olur). Sekizli olamaz (basamaklar en fazla 7 olur). Onlu ve onaltılı olabilir.

**Soru 14** (ekrandan, 02:35:00): $\{1,2,3,4\}$ üzerinde refleksif, simetrik ve geçişken olmayan bir bağıntı örneği verin.

> **Çözüm (derste):** $R=\{(1,1),(2,2),(3,3),(4,4),(1,2),(2,1),(2,3),(3,2)\}$. Refleksif ve simetriktir. $(1,2)$ ve $(2,3)$ var ama $(1,3)$ yok; benzer şekilde $(3,2),(2,1)$ var ama $(3,1)$ yok. Geçişkenliği bozan tek bir örnek bulmak yeterlidir (python ile kontrol edildi).

**Soru 15** (derste sözlü, 02:36:52): $R$ ve $S$ antisimetrik ise $R\cup S$ antisimetrik midir? Yanlışsa karşı örnek verin.

> **Çözüm (derste):** Yanlış. Örneğin $(1,2)\in R$, $(2,1)\in S$ olsun. İkisi ayrı ayrı antisimetrik olabilir, ama birleşimde $(1,2)$ ve $(2,1)$ birlikte bulunur.

**Soru 16** (derste sözlü, 02:38:58): Verilen birebir fonksiyonların terslerini bulun. <!-- BELİRSİZ: fonksiyonların kendisi altyazıda okunmadı, yalnız cevaplar söylendi. -->

> **Çözüm (derste):** Birinin tersi $\frac{x-2}{4}$, diğerinin tersi $\frac{1}{x-3}$ olarak söylendi (büyük olasılıkla fonksiyonlar $4x+2$ ve $3+\frac{1}{x}$).

## Dersin Toparlaması

Dersin ilk bölümünde Boole fonksiyonlarının sadeleştirilmesi tamamlandı. Bir fonksiyonun son değişkeni hücreye yazılarak bir alt dereceden Karnaugh haritasıyla çözülebileceği gösterildi. Burada asıl dikkat edilecek nokta, $d$ ile $\overline{d}$'nin birlikte gruplanmaması ve 1'lerin açıkta kalan parçalarının ayrıca gruplanmasıdır. Ardından çok değişkenli durumlar için algoritmik bir yol olan Quine-McCluskey yöntemi tekrar edildi.

İkinci bölümde diziler, toplam gösterimi, dizgiler ve sayı sistemleri hızlıca geçildi. Ardından bağıntıların yansıma, simetri, antisimetri ve geçişme özellikleri; denklik ve sıralama bağıntıları; Hasse diyagramı; Warshall algoritmasıyla geçişken kapanış ve bağıntıların matrisle gösterimi işlendi. Son olarak fonksiyonların türleri (birebir, örten, bijektif), ters fonksiyon ve bileşke anlatıldı, kümeler, diziler ve bağıntılar üzerine alıştırmalar çözüldü. Hoca, sayılar kuramı ve kriptolojiye giriş konusunun geçileceğini, sonraki derslerde algoritmaların analizi, karmaşıklık sınıfları, asimptotik gösterimler ve ağaçlar gibi algoritma ağırlıklı konulara başlanacağını söyledi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
