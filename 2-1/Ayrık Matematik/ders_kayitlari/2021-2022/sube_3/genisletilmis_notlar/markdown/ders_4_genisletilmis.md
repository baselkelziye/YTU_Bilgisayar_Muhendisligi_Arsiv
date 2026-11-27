# Ders 4 Genişletilmiş Notu: Karnaugh Haritalarının Uygulamaları, Kümeler, Diziler, Bağıntılar ve Fonksiyonlar

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Karnaugh Haritasında Etiketleme
- 2. Tek Tür Kapıyla Gerçekleme: SOP, POS, NAND ve NOR
- 3. Beş Değişkenli Fonksiyonlar İçin e / e' Yöntemi
- 4. Yöntemin Üç Değişkenli Bir Örnekle Sağlaması
- 5. Önemsiz Durumlar (Don't Care)
- 6. Gray Kod Üretimi ve İkili-Gray Dönüştürücü
- 7. Kümeler
- 8. Diziler, Toplam ve Çarpım Sembolleri
- 9. Karakter Katarları
- 10. Sayı Sistemleri
- 11. Bağıntılar
- 12. Fonksiyonlar
- Örnek Sorular
- Dersin Toparlaması

## 1. Karnaugh Haritasında Etiketleme

Ders, önceki haftanın konusu olan Karnaugh haritalarının kalan birkaç ayrıntısıyla başladı. Bazı kaynaklarda haritanın satır ve sütunları $\overline{C}\,\overline{D}$, $\overline{C}D$, $CD$, $C\overline{D}$ gibi harflerle de etiketlenir. Hoca buna gerek olmadığını söyledi: satır ve sütunları doğrudan Gray kodla ($00, 01, 11, 10$) etiketlemek yeterlidir. Gruplamada zaten kural şudur: grup içinde değeri değişen değişken terime girmez, değişmeyen değişken girer (değeri $0$ ise tümleyeni, $1$ ise kendisi). Harf etiketleri yalnızca kafa karıştırır.

## 2. Tek Tür Kapıyla Gerçekleme: SOP, POS, NAND ve NOR

### 2.1 Entegre ve maliyet

Hoca bir NAND entegresinin (7400) görselini açtı: bir entegrenin içinde dört tane iki girişli NAND kapısı bulunur. Denklemde ikişer girişli işlemler varsa bu dört kapının hepsi kullanılabilir.

Bir fonksiyon $x + \overline{x}y$ gibi AND ve OR'un düzensiz karıştığı bir biçimde çıkarsa, devreyi kurmak için birden fazla türde kapı, yani birden fazla entegre gerekir. Kapı sayısı aynı kalsa bile entegre sayısı artar; bu da maliyeti artırır. Hesap yalnızca kapı sayısına göre değil, kullanılan entegrelerin tek tip olmasına göre de yapılır.

### 2.2 İki kez tümleyen alma

Bir ifadenin iki kez tümleyeni kendisidir: $\overline{\overline{F}} = F$. Bu özellik, ifadeyi tek tür kapıyla yazmanın anahtarıdır. İçteki tümleyen De Morgan kuralıyla açılır, dıştaki tümleyen kapının kendisine ait olur.

Örnek (ekrandan, 00:30:00): $f = xyz$ ifadesi yalnız NOR kapılarıyla isteniyor.

$$xyz = \overline{\overline{xyz}} = \overline{\overline{x} + \overline{y} + \overline{z}}$$

NOR kapısı girişlerini önce OR'lar, sonra çıkışı tümler. Bu yüzden $\overline{x}, \overline{y}, \overline{z}$ üç girişli tek bir NOR kapısına verilirse çıkış $xyz$ olur. Girişlerin tümleyenleri de NOR kapılarıyla alınabilir. Aynı düşünce NAND için de geçerlidir.

**Soru:** Bu ifadede kaç kapı kullanmamız gerekiyor? **Cevap:** Üç girişli kapı kullanılırsa dört kapı yeter: üç tümleme ve bir NOR. Ama asıl önemli olan, hepsinin tek tür kapı olması ve tek bir entegreyle kurulabilmesidir.

### 2.3 SOP biçimi ve NAND

Haritada birler gruplanınca SOP (çarpımların toplamı) biçimi elde edilir. Hocanın örneğinde iki ikili gruptan $BD + BC$ çıktı. Bu ifade $B(D + C)$ diye daha kısa yazılabilir, ama bu biçim hem AND hem OR içerdiği için NAND'e dönüştürmek zordur. SOP biçimi ise kolayca NAND'e çevrilir:

$$BD + BC = \overline{\overline{BD + BC}} = \overline{\overline{BD}\cdot\overline{BC}}$$

$B$ ve $D$ bir NAND kapısına, $B$ ve $C$ ikinci bir NAND kapısına girer; bu iki çıkış üçüncü bir NAND kapısına verilir. Böylece üç NAND kapısıyla, tek entegrede devre kurulur.

### 2.4 POS biçimi ve NOR

NOR ile kurmak için haritada birler değil sıfırlar gruplanır ve sonuç POS (toplamların çarpımı) biçiminde yazılır. Hoca önce sıfırları küçük gruplarla topladı; bir öğrenci bir grubun sekizli yapılabileceğini hatırlattı ve hoca düzeltti. Sonuçta bir sekizli ve bir dörtlü grup kaldı:

- Sekizli grup ($B=0$ olan bütün hücreler): $B$
- Dörtlü grup ($CD = 00$ sütunu): $C + D$

Sıfırlar gruplanırken değişken $0$ ise kendisi, $1$ ise tümleyeni yazılır. Sonuç $F = B\,(C + D)$ olur; bu, SOP'taki $BD + BC$ ile aynı fonksiyondur. İki kez tümleyen alınınca

$$B(C+D) = \overline{\overline{B} + \overline{C + D}}$$

elde edilir: $C$ ve $D$ bir NOR kapısına girer, $B$'nin tümleyeni de bir NOR ile alınır, bu iki çıkış son bir NOR kapısına verilir. <!-- BELİRSİZ: hocanın çizdiği NOR devresinin son hâlini gösteren kare yok; devre altyazıdan kuruldu. -->

Hoca bu kısmın mantık devreleri dersine faydası olsun diye anlatıldığını, bu derste bundan sorumlu olunmayacağını söyledi.

## 3. Beş Değişkenli Fonksiyonlar İçin e / e' Yöntemi

### 3.1 Neden ayrı bir yöntem

Beş değişkenli ($a, b, c, d, e$) bir fonksiyonun doğruluk tablosu 32 satırdır. Önceki derste anlatılan yolla $e=0$ ve $e=1$ için iki ayrı dört değişkenli harita çizilir ve gruplama yapılırken bu iki harita üst üste düşünülür. Bu üç boyutlu düşünmeyi gerektirdiği için zordur. Hoca kitaplarda pek bulunmayan ama mantığı öğrenmek için sevdiği alternatif bir yöntem gösterdi.

### 3.2 Tablonun çiftlere ayrılması

Doğruluk tablosu, yalnızca son değişken $e$'nin farklı olduğu ikili satırlara ayrılır. Her çiftte $a, b, c, d$ ortaktır. Çiftin çıkışlarına göre o $abcd$ hücresine şu değer yazılır:

| $e=0$ çıkışı | $e=1$ çıkışı | Hücreye yazılan |
|---|---|---|
| 0 | 0 | 0 |
| 0 | 1 | $e$ |
| 1 | 0 | $e'$ |
| 1 | 1 | 1 |

Hocanın tablosu ve bu kurala göre doldurulan dört değişkenli harita (ekrandan, 00:40:00 ve 00:45:00; satırlar $ab$, sütunlar $cd$):

| $ab \backslash cd$ | 00 | 01 | 11 | 10 |
|---|---|---|---|---|
| 00 | $e$ | 0 | $e'$ | $e$ |
| 01 | $e'$ | $e$ | 0 | 1 |
| 11 | 1 | $e$ | $e'$ | 0 |
| 10 | 1 | 0 | $e'$ | $e$ |

Hoca tabloyu doldururken iki satırın çıkışını sonradan değiştirdi ve $0111$ ile $1110$ hücreleri $0$ kaldı. Bu tabloya göre fonksiyonun $1$ olduğu girişler ($abcde$): $00001, 00101, 00110, 01000, 01011, 01100, 01101, 10000, 10001, 10101, 10110, 11000, 11001, 11011, 11110$.

### 3.3 Gruplama kuralları

- $1$ hücresi $e + e'$ demektir; yani hem $e$'yi hem $e'$'yi içerir.
- $e$'ler kendi aralarında, ikinin kuvvetleri büyüklüğünde, olabildiğince büyük gruplanır. $e$ grubuna $1$ hücreleri katılabilir.
- $e'$'ler de aynı şekilde gruplanır; $e'$ grubuna da $1$ hücreleri katılabilir.
- $e$ grubunun içine $e'$ hücresi giremez (tersi de geçerli).
- Açıkta hiçbir $e$, $e'$ ya da $1$ kalmamalıdır. Bir $1$ hücresi yalnız $e$ grubuna katıldıysa $e'$ yarısı da bir şekilde başka bir gruba alınmalıdır.
- Her grubun terimi, grubun etiketiyle ($e$, $e'$ ya da $1$) çarpılarak yazılır.

### 3.4 Grupların bulunması

Hocanın grupları (ekrandan, 00:55:00):

- Dört köşedeki üç $e$ ve köşedeki bir $1$ ($0000, 0010, 1000, 1010$): $a$ ve $c$ değişiyor, $b=0$ ve $d=0$ sabit → $e\,\overline{b}\,\overline{d}$.
- $0101$ ve $1101$'deki $e$'ler: $a$ değişiyor, $b=1, c=0, d=1$ sabit → $e\,b\,\overline{c}\,d$.
- $1111$ ve $1011$'deki $e'$'ler: $b$ değişiyor → $\overline{e}\,acd$.
- $0011$ ve $1011$'deki $e'$'ler: $a$ değişiyor → $\overline{e}\,\overline{b}cd$.
- $0100$'daki açıkta kalan $e'$, $0110$'daki $1$ ile: $c$ değişiyor → $\overline{e}\,\overline{a}b\overline{d}$.
- $1000$ ve $1100$'deki $1$'ler: $b$ değişiyor → $1\cdot a\overline{c}\,\overline{d}$.
- $0110$'daki $1$'in $e$ yarısı açıkta kalmıştı. Bir öğrenci bunu sorunca hoca bu hücreyi $0010$'daki $e$ ile grupladı → $\overline{a}c\overline{d}$.

**Soru:** $0110$ hücresindeki $1$'i yalnız $e'$ ile gruplamışız; böyle bırakabilir miyiz? **Cevap:** Hayır. Bu $1$'in $e$ yarısı açıkta kaldı, onun için bir terim daha gerekir. On altı hücreli tabloda iş uzadığı için çok dikkatli olmak lazım: açıkta $e$ ya da $e'$ kalmamalı.

Ekrandaki sonuç:

$$F = e\,\overline{b}\,\overline{d} + e\,b\,\overline{c}\,d + \overline{e}\,acd + \overline{e}\,\overline{b}cd + \overline{e}\,\overline{a}b\overline{d} + 1\cdot a\overline{c}\,\overline{d} + 1\cdot\overline{a}c\overline{d}$$

> **Ders sonrası not:** Ekranda son terim $1\cdot\overline{a}c\overline{d}$ diye yazılmış. Bu grup $0010$ hücresini de kapsıyor, ama o hücrede yalnız $e$ var. Terim $1$ ile çarpılırsa $abcde = 00100$ girişinde fonksiyon yanlışlıkla $1$ olur. Grup bir $e$ hücresi içerdiği için terim $e$ ile çarpılmalıdır: $e\,\overline{a}c\overline{d}$. Düzeltilmiş ifade 32 girişin hepsinde haritayla aynı sonucu veriyor (python ile kontrol edildi):
>
> $$F = e\,\overline{b}\,\overline{d} + e\,b\,\overline{c}\,d + \overline{e}\,acd + \overline{e}\,\overline{b}cd + \overline{e}\,\overline{a}b\overline{d} + a\overline{c}\,\overline{d} + e\,\overline{a}c\overline{d}$$

Sonuç zaten SOP biçimindedir; terimlerin içi AND, terimler arası OR'dur.

## 4. Yöntemin Üç Değişkenli Bir Örnekle Sağlaması

Hoca yöntemin doğru sonuç verdiğini göstermek için üç değişkenli ($a, b, c$) bir örnek kurdu. Önce bir tablo yazdı (ekrandan, 00:50:00), sonra işi kolaylaştırmak için birlerin yerini değiştirdi ki haritada bir dörtlü ve bir ikili grup çıksın. Son tablo: çıkış $000, 010, 100, 101, 110$ girişlerinde $1$, diğerlerinde $0$.

**Klasik üç değişkenli harita ile:**

| $a \backslash bc$ | 00 | 01 | 11 | 10 |
|---|---|---|---|---|
| 0 | 1 | 0 | 0 | 1 |
| 1 | 1 | 1 | 0 | 1 |

- $c=0$ sütunlarının dördü (dörtlü grup): $a$ ve $b$ değişiyor → $\overline{c}$.
- $100$ ve $101$ (ikili grup): $a=1$, $b=0$ sabit → $a\overline{b}$.
- Sonuç: $F = \overline{c} + a\overline{b}$.

**$c$ değişkenine göre e / e' yöntemiyle:** satırlar $c$'ye göre çiftlenir ve iki değişkenli ($a,b$) haritaya yazılır.

| $ab$ | $c=0$ | $c=1$ | Hücre |
|---|---|---|---|
| 00 | 1 | 0 | $c'$ |
| 01 | 1 | 0 | $c'$ |
| 10 | 1 | 1 | 1 |
| 11 | 1 | 0 | $c'$ |

- $c'$'ler ve $1$ birlikte dörtlü grup olur: dörtlü grubun $a,b$ kısmı $1$ olduğundan terim $\overline{c}\cdot 1 = \overline{c}$.
- $10$ hücresindeki $1$'in $c$ yarısı açıkta kaldı. Tek başına gruplanır: $c\cdot a\overline{b}$. <!-- BELİRSİZ: hoca bu terimi "1 çarpı a b'nin değili" diye okudu; tahtadaki son hâli ($c'+ab'$) küçük önizlemede görünüyor. -->
- Sonuç: $F = \overline{c} + a\overline{b}c$, ve $\overline{c} + a\overline{b}c = \overline{c} + a\overline{b}$ olduğundan iki yöntem aynı fonksiyonu verir.

> **Ek bilgi (derste anlatılmadı):** $\overline{c} + a\overline{b}c = \overline{c} + a\overline{b}$ eşitliği, $x + \overline{x}y = x + y$ kuralının ($x = \overline{c}$, $y = a\overline{b}$) bir uygulamasıdır.

## 5. Önemsiz Durumlar (Don't Care)

Bazı giriş birleşimleri hiç oluşmaz ya da çıkışın ne olduğu önemli değildir. Bu durumlar tabloda $x$ ile gösterilir; haritaya da $x$ olarak yerleştirilir.

Örnek: $a,b,c$ girişlerinde çıkış $001, 010, 100$ için $1$; $101$ ve $110$ için önemsiz ($x$); diğerlerinde $0$.

| $a \backslash bc$ | 00 | 01 | 11 | 10 |
|---|---|---|---|---|
| 0 | 0 | 1 | 0 | 1 |
| 1 | 1 | $x$ | 0 | $x$ |

$x$ hem $0$ hem $1$ olabildiği için, işimize gelirse $1$ sayarız: gruptaki eleman sayısı artar, terimdeki literal sayısı azalır.

- $100$ ve $110$: $a=1$, $c=0$ → $a\overline{c}$.
- $001$ ve $101$: $b=0$, $c=1$ → $\overline{b}c$.
- $010$ ve $110$: $b=1$, $c=0$ → $b\overline{c}$.
- Sonuç: $F = a\overline{c} + \overline{b}c + b\overline{c}$.

Hoca önce ilk gruptan yalnız $a$ geleceğini söyledi, sonra düzeltip $a\overline{c}$ olduğunu belirtti. $x$ kullanılmasaydı $100$ hücresi tek başına kalacak ve $a\overline{b}\,\overline{c}$ gibi daha karmaşık bir terim çıkacaktı. Sonuç python ile kontrol edildi: $1$ olması gereken girişlerde $1$, $0$ olması gerekenlerde $0$ veriyor.

**Soru:** Tabloda neden $x$ yazdık? **Cevap:** O girişte çıkış $0$ da olabilir $1$ de; önemli değil. $1$ saymak işimize gelir, çünkü birleri içeren grubun eleman sayısını artırır. Örneğin trafik ışıklarında hangi lambaların birlikte yanacağına dair davranışlarda bu tür önemsiz durumlar vardır.

## 6. Gray Kod Üretimi ve İkili-Gray Dönüştürücü

### 6.1 Aynalama yöntemi

Gray kodun özelliği, ardışık iki kod arasında yalnız bir bitin değişmesidir. Hoca tabloyu kısa yoldan üretmeyi gösterdi:

1. En alt bit için $0, 1$ yazılır.
2. Elde edilen liste aynalanır (tersten kopyalanır): $0, 1, 1, 0$. Üst yarıya $0$, alt yarıya $1$ eklenir: $00, 01, 11, 10$.
3. Yine aynalanır: $10, 11, 01, 00$ eklenir; üstteki dörtlüye $0$, alttaki dörtlüye $1$ yazılır.

3 bitlik Gray kod: $000, 001, 011, 010, 110, 111, 101, 100$. Her adımda liste $2^1, 2^2, \dots$ uzunluğa ulaştıkça aynalanır.

### 6.2 3 bitlik ikili koddan Gray koda dönüştüren devre

Problem (ekrandan, 01:00:00): 3 bitlik ikili kodu 3 bitlik Gray koda dönüştüren devrenin fonksiyonlarını bulun. Giriş $abc$ (ikili), çıkış $XYZ$ (Gray). Üç giriş ve üç çıkışlı bir devredir; her çıkış için ayrı bir harita çizilir.

| $abc$ | $XYZ$ |
|---|---|
| 000 | 000 |
| 001 | 001 |
| 010 | 011 |
| 011 | 010 |
| 100 | 110 |
| 101 | 111 |
| 110 | 101 |
| 111 | 100 |

Haritalar (ekrandan, 01:05:00):

- $X$: $a=1$ satırının dört hücresi $1$. $a$ değişmiyor, $b$ ve $c$ değişiyor → $X = a$.
- $Y$: $1$'ler $010, 011, 100, 101$'de. İki ikili grup: $\overline{a}b$ ve $a\overline{b}$ → $Y = a\overline{b} + \overline{a}b$. (Bir öğrenci hocanın bir hücreyi yanlış yere yazdığını fark etti; hoca düzeltti.)
- $Z$: $1$'ler $001, 010, 101, 110$'da. İki ikili grup: $\overline{b}c$ ve $b\overline{c}$ → $Z = \overline{b}c + b\overline{c}$.

Kontrol: $abc = 110$ için $X = 1$; $Y = 1\cdot\overline{1} + \overline{1}\cdot 1 = 0$; $Z = \overline{1}\cdot 0 + 1\cdot\overline{0} = 1$. Sonuç $101$, tabloyla aynı.

Devre: $X$ doğrudan $a$'ya bağlanır (bir tampon gösterilebilir). $Y$ için $a$ ile $\overline{b}$ bir AND'e, $\overline{a}$ ile $b$ ikinci bir AND'e girer, iki çıkış OR'lanır. $Z$ benzer şekilde kurulur. Bir devrenin tek çıkışlı olması gerekmez.

> **Ek bilgi (derste anlatılmadı):** $Y = a \oplus b$ ve $Z = b \oplus c$ olduğu için dönüştürücü iki XOR kapısıyla da kurulabilir. Genel olarak $n$ bitlik ikili sayının Gray karşılığı $g = n \oplus (n \gg 1)$ ile bulunur.

Hoca bu konunun ayrıntılarının donanım derslerinde işleneceğini söyledi: işlemcideki toplama, taşıma ve atama gibi komutların devreleri ve RAM'deki hafıza elemanları bu kapılardan tasarlanır.

## 7. Kümeler

Aradan sonra yeni konuya geçildi. Hoca bu konudaki slaytların çok olduğunu ama çoğunun bilinen şeyler olduğunu, hızlı geçeceğini söyledi. Ayrık matematik ayrık nesnelerle uğraşır; ayrık nesnelerin bilinen ilk örneklerinden biri kümelerdir. Bağıntı, fonksiyon, işlem, grup gibi kavramlar bunun üzerine kurulur; daha genel hâli soyut matematikte anlatılır.

### 7.1 Temel tanımlar

- **Küme:** ayrık nesnelerden oluşan topluluk. Ortak özellikle gösterimde ":" ya da "|" işareti "öyle ki" (such that) anlamına gelir.
- **Sonlu ve sonsuz küme:** eleman sayısı sabit ve sayılabilir olan küme sonlu (finite), eleman sayısı sonsuz olan küme sonsuz (infinite) kümedir.
- **Boş küme:** elemanı olmayan küme; $\emptyset$ ya da $\{\}$ ile gösterilir (null set, void set).
- **Evrensel küme:** üzerinde çalıştığımız uzayın bütün elemanlarını içeren küme. Örneğin rakamlar kümesi evrensel küme alınırsa tek rakamlar, çift rakamlar, asal rakamlar onun alt kümeleridir.
- $\{\emptyset\}$ ile $\emptyset$ farklıdır: $\{\emptyset\}$ bir elemanlı bir kümedir, $\emptyset$ ise hiç elemanı olmayan kümedir.
- **Kardinalite:** kümenin eleman sayısı, $|A|$ ile gösterilir. Sonsuz kümeler sayılabilir (doğal sayılar gibi) ya da sayılamaz olabilir. Boş kümenin kardinalitesi $0$'dır; aynı elemanın tekrarı kardinaliteyi artırmaz.

### 7.2 Alt küme ve kuvvet kümesi

- $x \in S$: "$x$, $S$ kümesinin bir elemanıdır"; $x \notin S$: "eleman değildir"; $A \subseteq B$: "$A$, $B$'nin alt kümesidir" (ekrandan, 01:30:00). Mantık diliyle: $\forall x\,((x \in A) \rightarrow (x \in B))$.
- İki küme eşitse $X \subseteq Y$ ve $Y \subseteq X$ birlikte doğrudur.
- $X$, $Y$'nin alt kümesi ama $Y$, $X$'in alt kümesi değilse $X$, $Y$'nin öz alt kümesidir ($X \subset Y$).
- **Kuvvet kümesi** $P(S)$: $S$'nin bütün alt kümelerinin kümesi. $|S| = n$ ise $|P(S)| = 2^n$. Bu, doğruluk tablosundaki mantıkla aynıdır: $n$ bitin $2^n$ farklı durumu vardır.
- Örnekler: $P(\{a\}) = \{\emptyset, \{a\}\}$; $P(\emptyset) = \{\emptyset\}$ ($2^0 = 1$ eleman); $P(\{\emptyset\})$ iki elemanlıdır: $\emptyset$ ve $\{\emptyset\}$.

### 7.3 Venn diyagramları ve küme işlemleri

Venn diyagramları kümeler arasındaki ilişkileri gösterir. Hoca bunların veri tabanı dersinde varlıklar (entity) ve aralarındaki ilişkiler (örneğin kitap ve yazar) için çok kullanılacağını söyledi.

- **Birleşim** (OR): iki kümeden herhangi birinde olan elemanlar.
- **Kesişim** (AND): iki kümede de olan elemanlar.
- **Ayrık kümeler:** kesişimi boş olan kümeler. Hocanın şakalı örneği: "rektör olanlar" ile "bu sınıfta oturanlar" kümelerinin kesişimi boştur.
- **Tümleyen:** evrensel kümeden kümenin çıkarılmasıyla kalan elemanlar. Örneğin $X$ üzerinde $\{x : x > 3\}$ kümesinin tümleyeni $\{x : x \le 3\}$'tür. Boş kümenin tümleyeni evrensel küme, evrensel kümenin tümleyeni boş kümedir.
- **Fark:** $X - Y$, $X$'te olup $Y$'de olmayan elemanlar.
- **Simetrik fark** (XOR, ekrandan, 01:35:00):
  $$X \oplus Y = (X - Y)\cup(Y - X) = \{z : (z\in X \wedge z\notin Y)\vee(z\in Y \wedge z\notin X)\}$$
  Hocanın örneği: "ikinizden biri gelsin" dendiğinde ikisinin birlikte gelmesi de, hiçbirinin gelmemesi de olmaz.

Hoca XOR'u bir anahtar devresiyle de gösterdi: iki konumlu iki anahtar ($S_1$, $S_2$), bir üreteç ve bir lamba. Lamba, $S_1 = 0$ iken $S_2 = 1$ ya da $S_1 = 1$ iken $S_2 = 0$ olduğunda yanar. <!-- BELİRSİZ: anahtar devresinin çizimini gösteren kare yok. -->

### 7.4 Küme özdeşlikleri

Küme özdeşlikleri Boole cebri kurallarıyla aynıdır; evrensel küme $1$, boş küme $0$ gibi düşünülür, birleşim OR, kesişim AND'dir:

- Birleşme (associative) ve değişme (commutative) özellikleri.
- Dağılma: $A\cap(B\cup C) = (A\cap B)\cup(A\cap C)$ ve $A\cup(B\cap C) = (A\cup B)\cap(A\cup C)$.
- Özdeşlik: $A \cap U = A$, $A \cup \emptyset = A$.
- Tümleyen: $A \cup \overline{A} = U$, $A \cap \overline{A} = \emptyset$.
- Eş güçlülük: $A \cup A = A$, $A \cap A = A$.
- Sınır (yutan eleman): $A \cup U = U$, $A \cap \emptyset = \emptyset$.
- Yutma (absorption): $A \cup (A \cap B) = A$, $A \cap (A \cup B) = A$.
- Çift tümleme (involution): $\overline{\overline{A}} = A$.
- $0/1$ kuralı: $\overline{\emptyset} = U$, $\overline{U} = \emptyset$.
- De Morgan: $\overline{A \cup B} = \overline{A} \cap \overline{B}$, $\overline{A \cap B} = \overline{A} \cup \overline{B}$.

### 7.5 Kartezyen çarpım

İki kümeden alınan elemanlarla kurulan sıralı ikililerin kümesidir: $A \times B = \{(a,b) : a\in A, b\in B\}$. Üç ya da daha çok küme için de tanımlanır. $|A\times B| = |A|\cdot|B|$. Sıralı ikili olduğu için değişme özelliği yoktur: $A\times B \ne B\times A$.

Slayttaki örnek (ekrandan, 01:40:00): üç elemanlı bir $A$ kümesi ile iki elemanlı bir $B$ kümesinin Kartezyen çarpımı $3\cdot 2 = 6$ sıralı ikiliden oluşur (slaytta kişi adlarıyla verilmişti).

**Soru:** Reel sayılar ile pozitif sayıların, ya da reel sayılarla reel sayıların Kartezyen çarpımı yapılabilir mi? Bir öğrenci sonsuzluk yüzünden yapılamayacağını düşündü. **Cevap:** Yapılabilir. $3.2 + 5.8$ gibi bir toplama bir işlemdir; işlem bir fonksiyondan, fonksiyon da Kartezyen çarpımdan türer. Kartezyen çarpım yapılamasaydı reel sayıları toplayamazdık. Kartezyen çarpım bir kümedir; altında fonksiyonlar, onların altında işlemler tanımlanır.

### 7.6 Genelleştirilmiş birleşim ve kesişim, içerme-dışlama

$n$ kümenin birleşimi $\bigcup_{i=1}^{n} A_i$, kesişimi $\bigcap_{i=1}^{n} A_i$ ile gösterilir; hoca bunları toplam ($\Sigma$, OR) ve çarpım ($\Pi$, AND) benzetmesiyle anlattı.

İki küme için:
$$|A\cup B| = |A| + |B| - |A\cap B|$$
Kesişim iki kez sayıldığı için bir kez çıkarılır.

Örnek: 217 öğrencinin 157'si bir dersi, 198'i başka bir dersi alıyor; iki dersi de almayan öğrenci sayısı soruluyor. Evrensel kümeden $|A\cup B|$ çıkarılır; derste sonuç 13 öğrenci olarak verildi. <!-- BELİRSİZ: iki dersi birlikte alan öğrenci sayısı altyazıda geçmiyor; sayılar sesten alındı, kare yok. -->

> **Ders sonrası not:** Sonucun 13 çıkması için $|A\cup B| = 217 - 13 = 204$ ve dolayısıyla iki dersi birlikte alan öğrenci sayısı $157 + 198 - 204 = 151$ olmalıdır (büyük olasılıkla slayttaki veri budur).

Üç küme için:
$$|A\cup B\cup C| = |A|+|B|+|C| - |A\cap B| - |A\cap C| - |B\cap C| + |A\cap B\cap C|$$
İkili kesişimler çıkarılırken üçlü kesişim fazladan çıkarıldığı için bir kez geri eklenir.

### 7.7 Kümelerin bit dizisiyle gösterimi

Evrensel küme $U = \{x_1, \dots, x_n\}$ sıralı bir alfabe olarak alınır. Bir alt küme, her elemanın varlığına $1$, yokluğuna $0$ yazılarak bir bit dizisiyle kodlanır (örneğin $A$'da $x_1, x_3, x_5, x_6$ varsa bu konumlar $1$ olur). Birleşim bit düzeyinde OR, kesişim bit düzeyinde AND ile bulunur. Hoca bunun doğal dil işleme ve metin işlemede kullanılan basit bir yöntem olduğunu söyledi.

## 8. Diziler, Toplam ve Çarpım Sembolleri

### 8.1 Diziler

Dizi (sequence) ayrık bir yapıdır; $s_n$ ile gösterilir ve $n$ tam sayı değerleri alan indeks değişkenidir. Sinyaller ve sistemlerde $f(t) = t^2 + 5$ gibi bir fonksiyonda $t$ bütün reel sayıları alır; dizide ise yalnız tam sayı indeksler vardır. C'deki dizilerden farkı yoktur; indeks bazen $0$'dan başlar.

Düzenli dizi örnekleri (ekrandan, 01:45:00):

- $s_n = 1/n$, $n = 1, 2, 3, \dots$: $1, \tfrac12, \tfrac13, \tfrac14, \tfrac15, \tfrac16, \dots$
- $s_n = n^2 + 1$, $n = 1, 2, 3, \dots$: $2, 5, 10, 17, 26, 37, 50, \dots$

Bu diziler deterministiktir: $n$ yerine aynı değer yazıldığında her zaman aynı sonuç çıkar. Rastgele (stokastik) bir dizide bu garanti yoktur.

- **Artan dizi:** her $n$ için $s_{n+1} \ge s_n$. **Azalan dizi:** her $n$ için $s_{n+1} \le s_n$. Kuralı bozan tek bir durum varsa dizi ne artan ne azalandır.
- **Alt dizi:** $s$ dizisinin bazı elemanları, sıraları korunarak alınır ve $t_n$ ile gösterilir. Bir alt kümeden farkı, sıralamanın korunmasıdır.

### 8.2 Toplam ve çarpım sembolleri

$\sum_{k=1}^{m} a_k = a_1 + a_2 + \dots + a_m$. Çarpım sembolü $\prod$ aynı şekilde çarpmayı gösterir. Hoca bu sembollerin özellikle algoritmaların karmaşıklık analizinde gerekli olduğunu söyledi. İndeks kaydırılabilir: alt sınıra $1$ eklenirse üst sınıra da $1$ eklenir ve terimdeki indeks buna göre düzeltilir.

Örnekler:

- Sabit terim: hoca "$k=1$'den $10$'a kadar $2$" ifadesini sordu. Bir öğrenci önce $20$, sonra $2^{10}$ dedi; hoca $2\cdot2\cdots2$ (10 kez) yani $2^{10}$ olduğunu söyledi. <!-- BELİRSİZ: bu ifadenin slaytta toplam mı çarpım sembolüyle yazıldığı görülemedi. -->

> **Ders sonrası not:** Sembol $\prod_{k=1}^{10} 2$ ise sonuç $2^{10} = 1024$'tür. Sembol $\sum_{k=1}^{10} 2$ ise sonuç $10\cdot 2 = 20$ olur. Hocanın "on kez çarpılır" açıklaması çarpım sembolü için doğrudur.

- $\sum_{k=4}^{8} (-1)^k = 1 - 1 + 1 - 1 + 1 = 1$. Çift $k$'lerde $+1$, tek $k$'lerde $-1$ gelir; beş terim olduğu ve son terim çift $k$'ye denk geldiği için sonuç $+1$'dir.
- $\sum_{i=1}^{4}\sum_{j=1}^{3} ij$: önce içteki toplam çözülür: $\sum_{j=1}^{3} ij = i + 2i + 3i = 6i$. Sonra $\sum_{i=1}^{4} 6i = 6\cdot\frac{4\cdot5}{2} = 6\cdot 10 = 60$.

## 9. Karakter Katarları

Karakter katarı (string), bir alfabe (örneğin $\{a, b, c\}$) üzerinde tanımlanan sonlu karakter dizisidir. C'de ayrı bir string türü yoktur ama karakter dizileri string olarak kullanılır.

- Kısaltılmış yazım: $bbaccc = b^2ac^3$. Bu katarların kurallı yazılması, ileride otomata dersinde ele alınacak.
- Uzunluk $|\alpha|$ ile gösterilir; eleman sayısıdır.
- Boş katar $\lambda$ ile gösterilir (null string). Boş katar da bir bilgi taşır; hoca otomat makinelerinde boş girişin de bir anlamı olduğunu örnek verdi.
- $X^*$: $X$ alfabesi üzerindeki boş katar dahil bütün katarlar (Kleene yıldızı).
- $X^+ = X^* - \{\lambda\}$: boş olmayan bütün katarlar.
- **Birleştirme (concatenation):** $\alpha$'nın arkasına $\beta$ eklenir. Örnek (ekrandan, 01:50:00): $\alpha = bbaccc$, $\beta = caaba$ ise $\alpha\beta = bbaccccaaba = b^2ac^4a^2ba$. Uzunluk: $|\alpha\beta| = |\alpha| + |\beta|$.

## 10. Sayı Sistemleri

Bilgisayar ikili sistemi kullanır, ama kolaylık için sekizlik, onluk ve onaltılık sistemlere de ihtiyaç vardır. Basamak değerleri tabanın kuvvetleridir: onlukta birler, onlar, yüzler; sekizlikte $1, 8, 64$; ikilikte $1, 2, 4, 8, 16$.

- **İkilikten onluğa:** her bit $2^0, 2^1, 2^2, \dots$ ile çarpılıp toplanır. Slayttaki örnekte sonuç $107$ çıktı. <!-- BELİRSİZ: ikili sayı slaytta, kare yok; büyük olasılıkla $1101011_2$. -->
- **Dönüşüm yolları:** ikilikten onaltılığa, sekizliğe ve onluğa doğrudan dönüşüm kolaydır. Onaltılıktan onluğa dönüşüm zorsa önce ikiliğe çevrilebilir; onluktan onaltılığa için de önce ikiliğe çevirmek bir yoldur.
- **İkilikten onaltılığa:** en düşük anlamlı bitten başlayarak dörder bit gruplanır ve her grubun onaltılık karşılığı yazılır. Slayttaki örnekte gruplar $9$ ve $4$ verdi, sonuç $49_{16}$. <!-- BELİRSİZ: ikili sayı slaytta, kare yok; hoca bir grubu "1, 2, 4, 4" diye okudu. -->
- **İkili toplama:** $0+0=0$, $0+1=1$, $1+0=1$, $1+1=0$ elde $1$. Yarım ve tam toplayıcıdaki gibi, her basamaktan artan elde bir sonraki basamağa eklenir.
- **Onaltılık rakamlar:** $A=10, B=11, C=12, D=13, E=14, F=15$; bunların ikili karşılıkları iyi bilinmelidir. Örnek: $14 = 8 + 4 + 2$ → $1110_2$; $15 = 1111_2$.
- **Onluktan onaltılığa:** sayı sürekli $16$'ya bölünür ve kalanlar sondan başa doğru yazılır. Örnek: $2345 \div 16 = 146$ kalan $9$; $146 \div 16 = 9$ kalan $2$; $9$ artık bölünmez. Sonuç $929_{16}$ (kontrol: $9\cdot256 + 2\cdot16 + 9 = 2345$).
- **Onaltılık toplama** (ekrandan, 01:55:00): $23A_{16} + 8F_{16}$.
  - En sağ basamak: $A + F = 10 + 15 = 25$; $25 - 16 = 9$, yaz $9$, elde $1$.
  - Orta basamak: $3 + 8 + 1 = 12 = C$.
  - Sol basamak: $2$.
  - Sonuç $2C9_{16}$ (kontrol: $570 + 143 = 713 = 2C9_{16}$). $12$ için "$1$ ve $2$" yazılmaz, doğrudan $C$ yazılır.

## 11. Bağıntılar

### 11.1 Tanım

İkili bağıntı (binary relation), Kartezyen çarpımın bir alt kümesidir ve $x$ ile $y$ arasında bir ilişkinin varlığını gösterir. Hoca bunu bir yol ağı örneğiyle anlattı: $A$, $B$, $C$ noktaları (şehirler) olsun; $A$ ile $B$ arasında ve $A$ ile $C$ arasında yol var. Şehirler kümesinin kendisiyle Kartezyen çarpımı $3\cdot3 = 9$ ikiliden oluşur. Bağıntı, bunlardan yol olanları alır: $(A,B), (B,A), (A,C), (C,A)$. Yön önemliyse dört ikili yazılır; yönlü ve yönsüz yapılar çizge konusunda tekrar ele alınacak. Bağıntıdan da fonksiyon üretilir.

İki farklı küme arasında da bağıntı tanımlanabilir: $X = \{1,2,3\}$ ve $Y = \{a,b\}$ için Kartezyen çarpımda $3\cdot2 = 6$ ikili vardır; bağıntı bunların bir alt kümesidir.

- **Tanım kümesi (domain):** bağıntıdaki ikililerin ilk elemanlarının kümesi.
- **Değer kümesi (range):** ikinci elemanların kümesi.

Örnek: $R = \{(1,a), (1,b), (2,b)\}$ gibi bir bağıntıda tanım kümesi $\{1,2\}$, değer kümesi $\{a,b\}$'dir; $3$ hiçbir ikilide yer almaz. <!-- BELİRSİZ: slayttaki bağıntının elemanları kare olmadan tam okunamadı; hoca "2A gibi bir bağıntı yok" dedi. --> Bağıntılar okla iki küme arasında ya da graf olarak da gösterilebilir.

### 11.2 Yansıma özellikleri

$R$, $A$ kümesi üzerinde bir bağıntı, yani $A\times A$'nın alt kümesi olsun (ekrandan, 02:00:00):

- **Yansıyan (reflexive):** her $x\in A$ için $(x,x)\in R$. $A=\{1,2,3\}$ ise $(1,1), (2,2), (3,3)$ hepsi bulunmalı. Yol örneğinde "her şehirden kendisine yol var" demektir.
- **Yansımayan (nonreflexive):** bazı $x\in A$ için $(x,x)\notin R$. Örneğin $(1,1)$ ve $(2,2)$ var ama $(3,3)$ yok.
- **Hiç yansımayan (irreflexive):** her $x\in A$ için $(x,x)\notin R$.

Hoca bu terimlerin Türkçe karşılıklarından emin olmadığını, kaynaklara bakılabileceğini söyledi.

### 11.3 Simetri, ters simetri, geçişkenlik

- **Simetrik:** $(x,y)\in R$ iken $(y,x)\in R$.
- **Ters simetrik (antisymmetric):** $(x,y)\in R$ ve $(y,x)\in R$ ise $x = y$. Yani karşılıklı ikililer yalnız $x = y$ durumunda bulunabilir.
- **Geçişken (transitive):** $(x,y)\in R$ ve $(y,z)\in R$ iken $(x,z)\in R$.

**Örnek:** $A = \{1,2,3,4\}$ üzerinde $R = \{(a,b) : a = b^2\}$. $A\times A$'nın 16 ikilisinden yalnız ikisi koşulu sağlar: $R = \{(1,1), (4,2)\}$.

- Yansıyan mı? $(1,1)$ var ama $(2,2), (3,3), (4,4)$ yok; yansıyan değil. En az bir $(x,x)$ olduğu için hiç yansımayan da değil; yansımayan (nonreflexive).
- Simetrik mi? $(4,2)$ varken $(2,4)$ yok; simetrik değil.
- Ters simetrik mi? Evet: $x \ne y$ olan karşılıklı ikili yok.
- Geçişken mi? $(1,1)$ ile başlayıp $1$ ile devam eden tek ikili yine $(1,1)$. $(4,2)$'den sonra $2$ ile başlayan ikili yok. Koşulu bozan durum olmadığı için geçişkendir. Eğer $(2,3)$ olsaydı $(4,3)$'ü arayacaktık.

**Soru:** Boş bağıntı geçişken midir? **Cevap:** Evet. Geçişkenlik "$(x,y)$ ve $(y,z)$ varsa $(x,z)$ de olmalı" der; hiç ikili yoksa koşulu bozan bir durum da yoktur.

### 11.4 Bağıntının tersi

$X$'ten $Y$'ye bir $R$ bağıntısının tersi $Y$'den $X$'e bir bağıntıdır (ekrandan, 02:05:00):
$$R^{-1} = \{(y,x) \mid (x,y)\in R\}$$
Örnek: $R = \{(1,a), (1,d), (2,a), (2,b), (2,c)\}$ ise $R^{-1} = \{(a,1), (d,1), (a,2), (b,2), (c,2)\}$. Grafik gösterimde bu, eksenlerin yer değiştirmesidir (bir tür transpoz).

### 11.5 Bağıntının bileşkesi

Tanım (ekrandan, 02:15:00): $R^1 = R$, $R^2 = R\circ R$, $R^3 = R^2\circ R$, ..., $R^n = R^{n-1}\circ R$.

Örnek: $R = \{(1,1), (2,1), (3,2), (4,3)\}$ için $R^2$ ve $R^3$:

- $R^2$: her $(x,y)\in R$ için $(y,z)\in R$ aranır ve $(x,z)$ yazılır.
  - $(1,1)$ ve $(1,1)$ → $(1,1)$
  - $(2,1)$ ve $(1,1)$ → $(2,1)$
  - $(3,2)$ ve $(2,1)$ → $(3,1)$
  - $(4,3)$ ve $(3,2)$ → $(4,2)$
  - $R^2 = \{(1,1), (2,1), (3,1), (4,2)\}$
- $R^3 = R^2\circ R$:
  - $(1,1)\to(1,1)$, $(2,1)\to(2,1)$, $(3,1)\to(3,1)$, $(4,2)$ ve $(2,1)$ → $(4,1)$
  - $R^3 = \{(1,1), (2,1), (3,1), (4,1)\}$

Sonuçlar python ile kontrol edildi.

### 11.6 Özellik inceleme örneği

Hoca bir başka bağıntıda özellikleri kontrol etti: $(2,2)$ var ama $(1,1)$ yok, bu yüzden yansıyan değil. $(2,3)$ varken $(3,2)$ var, ama $(2,4)$ varken $(4,2)$ yok; simetrik değil. Geçişkenlik için $2$ ile başlayan ikililer tek tek denendi ve bozan durum bulunmadı. Ayrıca hiç $(x,x)$ ikilisi içermeyen başka bir bağıntı için "yansımayan değil, hiç yansımayandır" dedi. <!-- BELİRSİZ: bu örneklerin bağıntı kümeleri slaytta, kare yok; hocanın ters simetri yorumu altyazıda net değil. -->

> **Hocanın vurgusu:** Sınavda bir bağıntı verilip yansıma, simetri, ters simetri ve geçişkenlik özelliklerinden hangilerinin olduğu sorulabilir; bu konuda örnek çözmek gerekir.

### 11.7 Denklik bağıntısı

Bir bağıntı yansıyan, simetrik ve geçişken ise denklik bağıntısıdır (equivalence relation).

Örnek (ekrandan, 02:20:00): $R = \{(1,1), (2,2), (3,3), (1,2), (2,1), (1,3), (3,1), (2,3), (3,2)\}$.

- Yansıyan: $(1,1), (2,2), (3,3)$ var.
- Simetrik: $(1,2)$–$(2,1)$, $(1,3)$–$(3,1)$, $(2,3)$–$(3,2)$ hepsi var.
- Geçişken: örneğin $(1,2)$ ve $(2,1)$ → $(1,1)$ var; $(2,1)$ ve $(1,3)$ → $(2,3)$ var. Bütün durumlar tek tek kontrol edilmeli; tek bir bozan durum geçişkenliği bozar. Hoca bunun algoritmik olarak iç içe üç döngü gerektirdiğini söyledi.
- Ters simetrik değil: $x\ne y$ olan karşılıklı ikililer var.
- Sonuç: denklik bağıntısıdır.

Hoca sonra tam sayılar üzerinde tanımlı bir bağıntının denklik bağıntısı olup olmadığını inceledi; seçilen $(1,6)$ gibi tek bir ikilinin yansıma ve simetri sağlamadığını gösterdi, bir sonraki örneğin ise denklik bağıntısı çıkacağını, bütün koşullar kontrol edilerek bulunabileceğini söyledi. <!-- BELİRSİZ: bu iki örneğin bağıntı tanımları slaytta, kare yok. -->

### 11.8 Sıralama bağıntısı ve Hasse diyagramı

$X$ kümesi üzerindeki bir $R$ bağıntısı yansıyan, ters simetrik ve geçişken ise sıralama bağıntısıdır (kısmi sıra, partial order).

$A = \{1,2,3,4\}$ üzerindeki bir sıralama bağıntısı yönlü bir çizgeyle gösterildi. Hasse diyagramına geçmek için (ekrandan, 02:25:00):

1. Önce yansıma özelliği çıkarılır: her düğümdeki kendine dönen döngüler silinir.
2. Sonra geçişkenlik özelliği çıkarılır: $1\to2$ ve $2\to3$ varken $1\to3$ geçişkenlikten gelir, silinir; aynı şekilde $1\to4$ ve $2\to4$ de silinir.

Ekrandaki çizimde başlangıç çizgesinde $1\to2$, $2\to3$, $3\to4$, $1\to3$, $1\to4$, $2\to4$ okları vardı; sonuçta düz bir zincir kaldı:

```text
4
|
3
|
2
|
1
```

> **Ders sonrası not:** Hoca bağıntıyı "$x$, $y$'yi tam böler" diye tanıttı. Ama ekrandaki çizimde $2\to3$ oku var ve sonuç tam bir zincir; bu, $A=\{1,2,3,4\}$ üzerindeki "$\le$" bağıntısına uyar. Bölünebilme bağıntısında $2$, $3$'ü bölmediği için Hasse diyagramı $1\to2\to4$ ve $1\to3$ dallarından oluşurdu (büyük olasılıkla slayttaki örnek "$\le$" bağıntısıdır).

### 11.9 Kapanış ve Warshall algoritması

Bir bağıntıda yansıma, simetri ya da geçişkenlik yoksa, bağıntıyı bu özelliğe sahip olacak şekilde genişletmeye kapanış (closure) denir. Geçişken kapanış için Warshall algoritması kullanılır.

Slayttaki örnekte $A, B, C, D$ düğümleri üzerinde bir bağıntı yönlü çizge olarak çizildi (sıralı ikililer olduğu için çizge yönlüdür). Bağıntı matrisi kurulur: satır ve sütunlar $A, B, C, D$'dir; $x$'ten $y$'ye ilişki varsa ilgili hücre $1$, yoksa $0$ olur. Algoritma iç içe üç döngüyle çalışır ve her $k = 1, 2, \dots, n$ adımında $W[i][j] \leftarrow W[i][j] \vee (W[i][k] \wedge W[k][j])$ işlemini uygular. Dört düğüm için dört adım sonunda matrise eksik $1$'ler eklenmiş ve bağıntı geçişken hâle gelmiş olur. <!-- BELİRSİZ: örnek bağıntının elemanları ve ara matrisler slaytta, kare yok. -->

Hoca bir uygulama da gösterdi: farklı ülkelerden kişiler ve bildikleri diller bir kişi-dil matrisiyle gösterilir. Matrisin transpozu, hangi dilin kimler tarafından konuşulduğunu verir. Kişi-dil matrisi ($6\times5$) ile transpozu ($5\times6$) çarpılınca $6\times6$'lık bir matris çıkar; bu matris kimin kimle konuşabileceğini gösterir.

### 11.10 Bağıntı matrisi

$X$'ten $Y$'ye bir bağıntı, satırları $X$'in, sütunları $Y$'nin elemanları olan bir $0$–$1$ matrisiyle gösterilir: $x$ ile $y$ arasında ilişki varsa hücre $1$, yoksa $0$. Örnek: $\{1,2,3\}$ ile $\{a,b,c,d\}$ arasında $3\times4$'lük bir matris. Bir küme üzerindeki simetrik bir bağıntının matrisi köşegene göre simetriktir.

## 12. Fonksiyonlar

### 12.1 Tanım

Kartezyen çarpımın bir alt kümesi bağıntıdır; bağıntıların bir alt kümesi de fonksiyondur. $f: X\to Y$ bir fonksiyon olması için iki kural vardır (ekrandan, 02:30:00):

1. Tanım kümesinde boşta eleman kalmaz; her eleman eşlenir.
2. Tanım kümesindeki her eleman yalnız bir elemana gider; $(1,a)$ ve $(1,b)$ birlikte olamaz.

Slayttaki örnek: $\text{Dom}(f) = X = \{a,b,c,d\}$, $Y = \{1,2,3,4,5\}$, $f(a) = f(b) = 3$, $f(c) = 5$, $f(d) = 1$. Bu bir fonksiyondur. İki fonksiyonun toplamı ve çarpımı da fonksiyondur, ama tanımlı oldukları aralıklara dikkat edilmelidir.

Bir eleman iki farklı yere giderse (örneğin $1\to a$ ve $1\to b$) bağıntı fonksiyon olmaz.

### 12.2 Birebir, örten, birebir ve örten

- **Birebir (injective, one-to-one):** farklı $x$'ler farklı $y$'lere gider. Örnek: $2^x$ birebirdir. $x^2$ birebir değildir, çünkü $-2$ ve $2$'nin karesi aynı $4$'e gider (çift fonksiyon).
- **Örten (surjective, onto):** değer kümesindeki her $y$ için en az bir $x$ vardır; değer kümesinde boşta eleman kalmaz.
- **Birebir ve örten (bijective):** iki özellik birlikte. Örnek olarak doğrusal fonksiyonlar verildi.

Hoca ok diyagramlarıyla şu durumları gösterdi: birebir ama örten değil (değer kümesinde boşta eleman var); örten ama birebir değil (iki eleman aynı yere gidiyor); birebir ve örten; ne birebir ne örten (bir elemana iki ok geliyor, başka bir elemana hiç gelmiyor); ve bir elemandan iki ok çıktığı için fonksiyon olmayan bir bağıntı.

### 12.3 Ters fonksiyon

$f: X\to Y$ ise $f^{-1}$, $Y$'den $X$'e götürür. $f^{-1}$'in fonksiyon olması gerekmez; yalnız $f$ birebir ve örten ise tersi de fonksiyondur.

Örnekler (ekrandan, 02:35:00):

| $f$ | $f^{-1}$ |
|---|---|
| $\{(1,a), (2,c), (3,b)\}$ | $\{(a,1), (c,2), (b,3)\}$ |
| $f(x) = x + 1$ | $f^{-1}(x) = x - 1$ |
| $f(x) = ax + b$ | $f^{-1}(x) = \frac{x - b}{a}$ |
| $f(x) = \frac{ax + b}{cx + d}$ | $f^{-1}(x) = \frac{-dx + b}{cx - a}$ |
| $f(x) = ax^2 + bx + c$ | $x$ yalnız bırakılarak bulunur |

Kural: $y = f(x)$ yazılır, $x$ yalnız bırakılır, sonra $x$ ile $y$ yer değiştirir.

### 12.4 Bileşke, üstel ve logaritmik fonksiyonlar

$(f\circ g)(x) = f(g(x))$: $f$'de $x$ gördüğümüz yere $g(x)$ yazılır. Hocanın örneğinde $g(x) = 3x^2 - 1$ $f$'nin içine yazıldı. <!-- BELİRSİZ: örnekteki $f$ fonksiyonu ve sonuç slaytta, kare yok. -->

Üstel ve logaritmik fonksiyonlar birbirinin tersidir: $f(x) = 2^x$ ise $f^{-1}(x) = \log_2 x$. Sağlaması:

- $f(g(x)) = 2^{\log_2 x} = x$
- $g(f(x)) = \log_2 2^x = x\log_2 2 = x$

### 12.5 Katarın tersi

Bir katar fonksiyon gibi düşünülürse tersi, karakterlerin tersten yazılmasıdır. Hoca bir katar ile tersinin birleştirilmesinin boş katarı verdiğini söyledi. <!-- BELİRSİZ: bu ifade altyazıda bu şekilde geçiyor; katarın ters sırada yazılması ile birleştirme işlemine göre ters eleman farklı kavramlardır, slayttaki tanım görülemedi. -->

### 12.6 Taban ve tavan fonksiyonları

- **Taban (floor), $\lfloor x\rfloor$:** $x$'ten büyük olmayan en büyük tam sayı. $\lfloor 8.3\rfloor = 8$, $\lfloor 1/2\rfloor = 0$, $\lfloor -8.7\rfloor = -9$.
- **Tavan (ceiling), $\lceil x\rceil$:** $x$'ten küçük olmayan en küçük tam sayı. <!-- BELİRSİZ: tavan örneklerinin değerleri altyazıda net değil. -->

## Örnek Sorular

**Soru 1** (ekrandan, 00:30:00): $f = xyz$ fonksiyonunu yalnız NOR kapılarıyla gerçekleyin.

> **Çözüm:** $xyz = \overline{\overline{xyz}} = \overline{\overline{x}+\overline{y}+\overline{z}}$. $\overline{x}, \overline{y}, \overline{z}$ girişleri tek bir üç girişli NOR kapısına verilir; tümleyenler de NOR ile alınır.

**Soru 2** (ekrandan, 00:40:00 ve 00:45:00): Beş değişkenli bir fonksiyon, $e$'ye göre çiftlenmiş tablodan elde edilen ve Bölüm 3.2'deki haritayla veriliyor. Fonksiyonu e / e' yöntemiyle sadeleştirin.

> **Çözüm:** Bölüm 3.4'teki gruplarla
> $F = e\,\overline{b}\,\overline{d} + e\,b\,\overline{c}\,d + \overline{e}\,acd + \overline{e}\,\overline{b}cd + \overline{e}\,\overline{a}b\overline{d} + a\overline{c}\,\overline{d} + e\,\overline{a}c\overline{d}$.
> Son terim ekranda $1\cdot\overline{a}c\overline{d}$ yazılmıştı; doğrusu $e\,\overline{a}c\overline{d}$ (Bölüm 3.4'teki ders sonrası nota bakın).

**Soru 3** (derste sözlü, 00:55:13): $a,b,c$ girişlerinde çıkış $001, 010, 100$ için $1$; $101$ ve $110$ önemsiz. Fonksiyonu sadeleştirin.

> **Çözüm:** $F = a\overline{c} + \overline{b}c + b\overline{c}$.

**Soru 4** (ekrandan, 01:00:00): 3 bitlik ikili kodu 3 bitlik Gray koda dönüştüren devrenin çıkış fonksiyonlarını bulun.

> **Çözüm:** $X = a$, $Y = a\overline{b} + \overline{a}b$, $Z = \overline{b}c + b\overline{c}$ (ekrandan, 01:05:00).

**Soru 5** (derste sözlü, 01:39:39): Reel sayılar ile reel sayıların Kartezyen çarpımı yapılabilir mi?

> **Çözüm:** Evet. Toplama gibi işlemler $\mathbb{R}\times\mathbb{R}\to\mathbb{R}$ fonksiyonlarıdır; fonksiyon da Kartezyen çarpımın alt kümesi olarak tanımlanır.

**Soru 6** (derste sözlü, 01:47:23): $\sum_{k=4}^{8} (-1)^k$ ve $\sum_{i=1}^{4}\sum_{j=1}^{3} ij$ değerlerini bulun.

> **Çözüm:** Birincisi $1$; ikincisi $\sum_{i=1}^{4} 6i = 60$.

**Soru 7** (ekrandan, 01:55:00): $23A_{16} + 8F_{16}$ toplamını bulun.

> **Çözüm:** $2C9_{16}$.

**Soru 8** (derste sözlü, 02:01:18): $A = \{1,2,3,4\}$ üzerinde $R = \{(a,b) : a = b^2\}$ bağıntısını yazın; yansıma, simetri, ters simetri ve geçişkenlik özelliklerini inceleyin.

> **Çözüm:** $R = \{(1,1), (4,2)\}$; yansımayan (nonreflexive), simetrik değil, ters simetrik, geçişken.

**Soru 9** (ekrandan, 02:15:00): $R = \{(1,1), (2,1), (3,2), (4,3)\}$ için $R^2$ ve $R^3$'ü bulun.

> **Çözüm:** $R^2 = \{(1,1), (2,1), (3,1), (4,2)\}$, $R^3 = \{(1,1), (2,1), (3,1), (4,1)\}$.

**Soru 10** (ekrandan, 02:20:00): $R = \{(1,1), (2,2), (3,3), (1,2), (2,1), (1,3), (3,1), (2,3), (3,2)\}$ yansıyan, simetrik, geçişken, ters simetrik mi? Denklik bağıntısı mı?

> **Çözüm:** Yansıyan, simetrik ve geçişken; ters simetrik değil. Denklik bağıntısıdır.

**Soru 11** (ekrandan, 02:35:00): $f(x) = \frac{ax+b}{cx+d}$ fonksiyonunun tersini bulun.

> **Çözüm:** $y(cx + d) = ax + b \Rightarrow x(cy - a) = b - dy \Rightarrow x = \frac{-dy + b}{cy - a}$; yani $f^{-1}(x) = \frac{-dx + b}{cx - a}$.

## Dersin Toparlaması

Dersin ilk yarısında Karnaugh haritaları tamamlandı. Sadeleştirilmiş ifadenin SOP ya da POS biçiminde yazılması, iki kez tümleyen alma ve De Morgan ile devrenin tek tür kapıyla (NAND ya da NOR) ve az entegreyle kurulmasını sağlar. Beş değişkenli fonksiyonlar için son değişkene göre çiftleme yapan e / e' yöntemi gösterildi ve üç değişkenli bir örnekle doğrulandı. Önemsiz durumların grupları büyütmek için nasıl kullanıldığı, Gray kodun aynalama yöntemiyle üretilmesi ve ikili-Gray dönüştürücünün çok çıkışlı bir devre olarak tasarlanması görüldü.

İkinci yarıda ayrık yapıların temelleri hızlıca tekrar edildi: kümeler ve işlemleri, içerme-dışlama, diziler ve toplam/çarpım sembolleri, karakter katarları, sayı sistemleri. Ardından bağıntılar (yansıma, simetri, ters simetri, geçişkenlik, ters, bileşke, denklik ve sıralama bağıntıları, Hasse diyagramı, Warshall algoritması, bağıntı matrisi) ve fonksiyonlar (birebir, örten, ters fonksiyon, bileşke, üstel ve logaritmik fonksiyonlar, taban ve tavan) anlatıldı. Hoca sonraki derste bağıntı özellikleri, denklik ve sıralama bağıntılarıyla ilgili örnekler çözüleceğini söyledi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
