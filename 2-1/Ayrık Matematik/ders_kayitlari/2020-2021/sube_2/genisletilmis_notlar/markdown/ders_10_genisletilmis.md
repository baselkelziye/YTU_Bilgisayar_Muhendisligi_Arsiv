# Ders 10 Genişletilmiş Notu: Ağaçlar, İfade Ağaçları, Ağaç Gezinme Yöntemleri, Huffman Kodlama ve Kapsayan Ağaçlar

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Bağıntılardan Graflara, Graflardan Ağaçlara
- 2. Ağaç Kavramı ve Köklü Ağaçlar
- 3. Ağaç Terminolojisi
- 4. Ağaçların Karakteristiği ve İkili Ağaçlar
- 5. İfade Ağaçları: Infix, Prefix ve Postfix
- 6. Infix İfadeden Ağaç Kurma Örnekleri
- 7. Postfix ve Prefix İfadeden Ağaç Kurma
- 8. İkili Ağaç Türleri ve Dengeli Ağaç
- 9. İkili Arama Ağacı ve Dizide Saklama
- 10. Ağaç Gezinme Yöntemleri
- 11. Huffman Kodlama
- 12. Kapsayan Ağaç, BFS ve DFS
- Örnek Sorular
- Dersin Toparlaması

## 1. Bağıntılardan Graflara, Graflardan Ağaçlara

Önceki derste algoritmalarla ilgili slaytlar bitmişti; bu derste ağaçlara geçildi. Hoca, konuya doğrudan ağaçlarla başlamak yerine önce bağıntı, graf ve ağaç arasındaki bağı kurmayı tercih etti: ağaçlar graflardan, graflar da ikili bağıntılardan türer.

Kümeler konusundan sonra ikili bağıntılar (binary relation) görülmüştü. Bir ikili bağıntı üç biçimde gösterilebiliyordu: sıralı ikililerden oluşan küme gösterimi, 0-1 matris gösterimi (iki eleman arasında ilişki varsa 1, yoksa 0) ve yönlü graf (directed graph, digraph) gösterimi. Yönlü grafta hangi elemandan hangi elemana ilişki varsa ok ile gösterilir. Graf gösterimi, bağıntının daha genel halidir.

### 1.1 Graf tanımı

Slayttaki tanım şöyledir (ekrandan, 00:10:00): Bir $G=(V,E)$ grafı, boş olmayan bir $V$ köşe (düğüm, vertex) kümesinden ve bir $E$ kenar (edge) kümesinden oluşur. Her kenarın uç noktaları adı verilen, kendisiyle ilişkili bir ya da iki köşesi vardır. Bir kenar, graftaki köşeleri birbirine bağlayan ve iki köşe arasında bir ilişkiyi gösteren elemandır. Slayttaki örnek dört köşeli ($a,b,c,d$) ve beş kenarlı bir graftır: $a$–$b$, $a$–$c$, $b$–$c$, $b$–$d$, $c$–$d$.

Hoca graf kavramını günlük örneklerle somutlaştırdı. $A$'dan $B$'ye bir kenar, $A$ şehrinden $B$ şehrine bir yol olabilir. Bilgisayar mühendisliği açısından, sosyal medyada iki kişi arasındaki arkadaşlık ilişkisi bir kenardır. İki öğrenci arasındaki benzerlik de bir kenar olarak düşünülebilir; bu durumda kenarın üzerine bir sayı yazılır (örneğin 0 ile 100 arasında bir benzerlik değeri). Kod benzerliği, ödev benzerliği, çalışma alanlarının benzerliği ya da aynı dersi alan öğrenciler arasındaki ilişki hep grafın uygulamalarıdır. Grafların ayrıntısı bir sonraki bölümde işlenecektir.

### 1.2 Ağaç, döngüsüz graftır

Bir graf birçok kapalı çevrim (döngü) içerebilir. Grafın kapalı çevrim içermeyen özel haline ağaç denir. Yani her ağaç bir graftır; farkı, kapalı çevrim içermemesidir. Kapalı çevrim varsa yapı ağaç olmaz.

## 2. Ağaç Kavramı ve Köklü Ağaçlar

Hoca ağaçların bilgisayar bilimindeki önemini vurguladı. En basit örneği ikili arama ağaçlarıdır (binary search tree). Genel olarak ağaç, bir kök (root) düğümü olan, kökten alt düğümlere geçişi sağlayan kenarları bulunan ve belli bir derinliği olan genel bir veri yapısıdır. Bunun en önemli özel hali ikili ağaçtır (binary tree): her düğümün en fazla iki çocuğu vardır.

Bu dersteki amaç ağaç terminolojisini öğrenmek ve bazı uygulamalara bakmaktır. En bilinen uygulama, önceki derste yığın (stack) ile yapılan infix, prefix ve postfix dönüşümleridir. Yığında yalnız ekleme ve çıkarma yapılabildiği için hareket kabiliyeti azdır; ağaç üzerinde hareket kabiliyeti daha fazladır, bu yüzden dönüşümler ağaçla daha kolaydır. İkili ağaçların uygulamalı (kodlu) tarafı yapısal programlama dersinde, asıl analizleri ise veri yapıları ve algoritma analizi derslerinde işlenir.

### 2.1 Ağaç ve kapalı çevrimlerin kaldırılması

Slayttaki tanıma göre ağaç, düğüm çiftleri arasında tek bir yol bulunan basit bir graftır. $v$'den $w$'ye tek bir yol vardır ve yapı dairesel (döngüsel) değildir; bir düğümden ötekine giderken bir çevrimle karşılaşılmaz.

Kapalı çevrim içeren bir grafı ağaca çevirmek için her adımda döngüyü oluşturan kenarlardan biri silinir. Bütün kapalı çevrimler yok olana kadar bu sürdürülürse elde edilen yapı bir ağaçtır.

### 2.2 Köklü ağaç

Köksüz bir ağaçta düğümler arasında bir alt-üst ilişkisi doğrudan görülemeyebilir; hangi düğümün daha üst seviyede olduğunu belirlemek zordur. Bir düğüm en üst düzey (kök) olarak seçildiğinde bu belirsizlik kalkar: her düğümün bir atası olur ve düğümler arasında seviyeler oluşur. Belli bir düğümden türetilmiş ve o düğümün en üst seviye olarak belirlendiği ağaçlara köklü ağaç (rooted tree) denir.

### 2.3 Düğüm seviyesi ve ağacın yüksekliği

Slayttaki tanımlar (ekrandan, 00:20:00): $T$ köklü bir ağaç olsun.

- Bir düğümün seviyesi $l(v)$, o düğümün bulunduğu yerden ağacın köküne olan yolun uzunluğudur.
- Bir ağacın yüksekliği, maksimum seviyeye sahip düğümün seviyesidir: $h=\max_{v\in V(T)} l(v)$.

Örneğin bir düğümden bir adımda bir üst düğüme, bir adımda da köke ulaşılıyorsa o düğümün seviyesi 2'dir. Slayttaki ağaçta seviyeler 1, 2 ve 3'tür; en büyüğü 3 olduğu için ağacın yüksekliği 3'tür. Yükseklik, en derinde kaç kenar bulunduğunu söyler.

**Soru:** Düğümler arasındaki çizgilerin uzunluklarının bir anlamı var mı? **Cevap:** Ağaçlarda yok. Graflarda da asıl anlam çizginin uzunluğunda değil, kenar üzerine yazılan sayısal değerdedir (örneğin yol uzunluğu olarak 3, 8, 6 birim). Ağırlıklı kenarlar graflarda görülür; ağaçlarda böyle bir anlam yüklenmez.

## 3. Ağaç Terminolojisi

Hoca, ağaçların veri yapılarında, işletim sistemlerinde ve bilgisayar biliminin birçok yerinde karşımıza çıkacağını, problem çözerken ve algoritma geliştirirken neyin ne olduğunu bilmek gerektiğini söyledi.

- **Kök (root) / ebeveyn (parent):** En üst düzeydeki düğüm köktür ve tektir. Bir düğüm, kendi alt düğümlerinin ebeveynidir (örneğin üç kardeşin ebeveyni).
- **Ata (ancestor):** Hoca bunu bir düğümün üst düğümü olarak anlattı.
- **Çocuk (child):** Bir alt seviyede, bir düğüme bağlı düğümler.
- **Torun / alt düğüm (descendant):** Hoca bunu alt seviyelerdeki düğümler olarak anlattı.
- **Kardeş (sibling):** Aynı ebeveyne bağlı düğümler (örneğin iki kardeş, üç kardeş).
- **Uç düğüm / yaprak (terminal, leaf):** Hiç çocuğu olmayan düğüm; genellikle en alttaki düğümler.
- **Ara düğüm (internal):** En az bir çocuğu olan düğüm. Kök de en az bir çocuğu varsa bir ara düğümdür.
- **Alt ağaç (subtree):** Bir kenar koparıldığında oluşan yeni ağaç. Alt ağaç kavramı aritmetik ifadelerde ve ağaç gezme işlemlerinde çok kullanılır.

Bir $T$ ağacının alt ağacı $T'$ ise $V(T')\subseteq V(T)$ ve $E(T')\subseteq E(T)$ olur; yani alt ağacın düğümleri ve kenarları, ana ağacın düğümlerinin ve kenarlarının alt kümesidir.

> **Ders sonrası not:** Hoca kardeşleri "aynı seviyedeki, köke uzaklığı aynı olan düğümler" diye de tanımladı. Doğrusu, kardeşler aynı ebeveyne sahip düğümlerdir; aynı seviyede olup ebeveynleri farklı olan düğümler kardeş değildir (kuzen gibidir). Benzer biçimde ata, yalnız bir üst düğüm değil, düğümden köke giden yol üzerindeki bütün düğümlerdir; bir üst düğüme özel olarak ebeveyn denir. Alt düğüm (descendant) de bir düğümün altındaki bütün düğümleri kapsar, yalnız en alt seviyeyi değil.

## 4. Ağaçların Karakteristiği ve İkili Ağaçlar

### 4.1 Ağaç olma koşulları

Slayttaki teorem (ekrandan, 00:25:00): $T$, $n$ düğümlü bir graf ise aşağıdakiler denktir:

- (a) $T$ bir ağaçtır.
- (b) $T$ bağlantılıdır (connected) ve döngü içermez (acyclic).
- (c) $T$ bağlantılıdır ve $n-1$ kenara sahiptir.
- (d) $T$ döngüsüzdür ve $n-1$ kenara sahiptir.

Bu, bir grafın ağaç olup olmadığını kontrol etmenin yoludur. Örneğin üç düğüm için üç kenar çizilirse yapı ağaç olmaktan çıkar; üç düğümlü bir ağacın iki kenarı olmalıdır.

**Soru:** Bir ağaç için en az kaç düğüm gerekir? **Cevap:** Düğüm sayısının bir sınırı yoktur, istenildiği kadar düğüm eklenebilir; sınırlı olan, düğüm sayısına göre kenar sayısıdır. Tek düğümde alt-üst ilişkisi olmadığı için, ağaç yapısını görmek adına en az iki düğüm gerektiği söylenebilir.

### 4.2 İkili ağaç

İkili ağaçta (binary tree) her düğümün en fazla iki çocuğu vardır; bir düğüm 0, 1 ya da 2 çocuğa sahip olabilir. Bilgisayar bilimi bunun üzerine birçok uygulama geliştirmiştir.

Slayttaki örnekte $A$ köktür ve aynı zamanda $B$ ile $C$'nin ebeveynidir. $B$, $A$'nın sol çocuğu (left child), $C$ sağ çocuğudur (right child). $D$'nin yalnız sol çocuğu, $H$'nin yalnız sağ çocuğu vardır. Uç düğümlere yaprak denir.

## 5. İfade Ağaçları: Infix, Prefix ve Postfix

### 5.1 Üç gösterimin hatırlatılması

Ekranda yazılanlar (ekrandan, 00:30:00):

- $A+B$ → infix (operatör ortada)
- $+AB$ → prefix (operatör başta; "pre" ön demektir)
- $AB+$ → postfix (operatör sonda; "post" son demektir)

Ağaca yerleştirme (adding into tree) infix ifade üzerinden yapılır. Derleyici kuramında buna ayrıştırma (parsing) denir: "parsing of mathematical statements". Yalnız matematiksel ifadeler değil, programlama dilindeki her deyim de ayrıştırılır. Örneğin `a = a + 5` deyiminde önce $a+5$ hesaplanır, sonra atama yapılır.

Infix ifadeleri doğrudan değerlendirmek zordur; önceki derste infix bir ifade iki yığınla değerlendirilmişti. Bu yüzden prefix ya da postfix kullanılır, bunun için de dönüşüm gerekir. Bu dönüşüm yığınla zordur, ikili ağaçla daha kolaydır.

### 5.2 Ağaca yerleştirme kuralı

İfade ağacında operatörler ebeveyn (ara) düğümlerde, kök de dahil olmak üzere yer alır; operandlar çocuk düğümlerde, yani yapraklarda (terminal düğümlerde) bulunur. $A+B$ için $+$ kök, $A$ sol çocuk, $B$ sağ çocuktur.

Örneğin $A+B-C$ ifadesinde iki operatör ve üç operand vardır: ağaçta iki ebeveyn (ara düğüm) ve üç çocuk (yaprak) bulunur (ekrandan, 00:35:00). Ara düğümler operatör, yapraklar operand olacak şekilde düzenleme, ağaç üzerinden dönüşüm yapabilmenin şartıdır.

### 5.3 Gezinme sırası ve ezberlememe tavsiyesi

Kitaplarda genellikle şu sıralar ezberletilir (ekrandan, 00:35:00):

- Infix: sol – kök – sağ
- Prefix: kök – sol – sağ → $+AB$
- Postfix: sol – sağ – kök → $AB+$
- Hocanın tahtaya "ters postfix" diye yazdığı sıra: sağ – sol – kök → $BA+$

> **Hocanın vurgusu:** Bunları ezberlemeye gerek yok. $A+B$'nin mantığını öğrenin: artı yukarıda, $A$ solda, $B$ sağda. Normal yazım düzenimiz budur. $+AB$ prefix'in, $AB+$ postfix'in kalıbıdır; diğer her şey buradan türetilir.

Bu kural özyinelemelidir (recursive): bir çocuğun kendisi de alt çocukları olan bir alt ağaçsa, aynı kural o alt ağaca da uygulanır. Örneğin kökü $+$ olan, sol alt ağacı $A-B$, sağ alt ağacı $C*D$ olan bir ağaç verilip prefix ya da postfix gösterimi istenebilir (ekrandan, 00:35:00).

Postfix için $A+B$ ağacında: önce sola gidilir; sol düğümün çocuğu var mı diye bakılır, yoksa $A$ yazılır. Sonra sağa gidilir; çocuğu yoksa $B$ yazılır. Sonra köke gelinir, $+$ yazılır: $AB+$. Ters sıra (sağ-sol-kök) $BA+$ verir.

> **Ders sonrası not:** Hoca postfix gösterimi için "Polish notation demiştik" dedi ve tahtada postfix'in yanına "(RN)" yazdı. Doğrusu: prefix gösterim Polonya gösterimi (Polish notation), postfix gösterim ters Polonya gösterimi (Reverse Polish Notation, RPN) olarak bilinir. Sağ-sol-kök sırasıyla elde edilen dizi ($BA+$), prefix dizisinin ($+AB$) tersten okunmuş halidir.

### 5.4 Ağacın ezberlenmeden kurulması: $(A-B)*(C*D)$ benzeri ifade

Hoca, ağaç verilmeseydi ne yapılacağını şöyle anlattı: $A-B$ varsa $A$ sol, $B$ sağ, $-$ bunların kökü olur. Ağacın bir tarafı budur. Sonra araya bir çarpı geliyorsa ve sağda başka bir terim varsa, çarpı bu iki tarafın atası olur. Sağ taraf kendi içinde bir başka matematiksel ifadeyse önce o kendi içinde ağaca yerleştirilir: $C$ sol, $D$ sağ ve aralarındaki operatör kök olur.

## 6. Infix İfadeden Ağaç Kurma Örnekleri

### 6.1 Sınav örneği: $(a+b-c)\sqrt[n]{x}$

Bir öğrencinin önerisi üzerine geçmiş bir sınavdaki soru ele alındı (ekrandan, 00:45:00). İfade $(a+b-c)\sqrt[n]{x}$'tir. Kök ifadesi üs olarak yazılır: $\sqrt[n]{x}=x^{1/n}$.

Kuruluş adımları:

- $a+b$: $+$ kök, $a$ sol, $b$ sağ.
- Ardından $-c$ geliyor. Aynı düğümün yanına üçüncü bir operand eklenemez; bu yüzden $a+b$ alt ağacı yeni bir $-$ düğümünün sol çocuğu olur, $c$ sağ çocuğu olur.
- $x^{1/n}$: önce $x$ yazılır; bunun bir üst işlemi üs ($\uparrow$, şapka) işlemidir. Üssün sol çocuğu $x$, sağ çocuğu $1/n$'dir. $1/n$ için bölme düğümünün sol çocuğu $1$, sağ çocuğu $n$'dir.

**Soru:** Çarpmanın altında üs işareti gelmeyecek mi? **Cevap:** Evet; önce $x$, onun üstünde üs işlemi, üssün sağında $1/n$ alt ağacı kurulur, sonra bu sonuç çarpılır.

Ağacın kökü en son yapılacak işlem olan $*$'dır. Kökün solunda $(a+b)-c$, sağında $x\uparrow(1/n)$ vardır:

```text
            *
         /     \
        -       ↑
       / \     / \
      +   c   x   /
     / \         / \
    a   b       1   n
```

**Prefix çıkarma.** Prefix'te önce kök yazılır, sonra sol alt ağaca, sonra sağ alt ağaca geçilir. Kök $*$ yazılır. Sol çocuk $-$'nin çocukları var, kendisi bir kök: $-$ yazılır. Onun solu $+$'nın da çocukları var: $+$ yazılır. $+$'nın solunda $a$ var, çocuğu yok: $a$ yazılır; sonra sağ $b$. $+$ alt ağacı bitince, $-$'nin sağı $c$ yazılır. Sol taraf bitti, kökün sağına geçilir: $\uparrow$ bir kök, yazılır; solu $x$; sağı $/$ bir kök, yazılır; solu $1$, sağı $n$.

- Prefix: `* - + a b c ↑ x / 1 n` (ekrandan, 00:50:00)

**Postfix çıkarma.** Gidebildiğin kadar sola in, sonra sağa, en son kökü yaz. Kökten sola, sola, sola inilir ve $a$'ya ulaşılır: $a$, sonra $b$, sonra kökleri $+$. Bu alt ağaç bir üst kökün solu sayılır; o kökün sağı $c$ yazılır, sonra kökü $-$. Ana kökün sağına geçilir: $\uparrow$'ın solu $x$; sağı $/$'nin solu $1$, sağı $n$, kökü $/$; sonra $\uparrow$; en son ana kök $*$.

- Postfix: `a b + c - x 1 n / ↑ *` (ekrandan, 00:50:00)

Hoca cevapları sınav cevap anahtarıyla karşılaştırdı; ikisi de aynı çıktı.

### 6.2 Öğrenci örneği: $(a+b)*(a-c)*2\wedge2-(b/c)$

Bir öğrencinin yazdığı ifade ağaca yerleştirildi (ekrandan, 00:55:00). Hoca ağacı yapraklardan köke doğru kurdu:

- $a+b$ ve $a-c$ ayrı alt ağaçlardır; aralarındaki $*$ bunları birleştirir.
- Sonra $2\wedge2$ gelir ($\uparrow$ kökü, iki yaprağı 2 ve 2). Bunu soldaki çarpımla birleştiren ikinci bir $*$ düğümü oluşur.
- Sonra $-(b/c)$ gelir. Önce $b/c$ yazılır. İşlem önceliğine göre çarpmalar ve bölme, çıkarmadan önce yapılır; en son işlem çıkarmadır, bu yüzden kök $-$'dir.

```text
                 -
              /     \
             *       /
           /   \    / \
          *     ↑  b   c
         / \   / \
        +   - 2   2
       / \ / \
      a  b a  c
```

**Prefix** (ekrandan, 01:00:00): kök $-$; sol çocuk $*$ bir kök; onun solu yine $*$; onun solu $+$: $a$, $b$; sonra sağdaki $-$: $a$, $c$; sonra $\uparrow$: $2$, $2$; sonra kökün sağındaki $/$: $b$, $c$.

- Prefix: `- * * + a b - a c ↑ 2 2 / b c`

**Sayısal kontrol** ($a=2,\ b=2,\ c=1$): Hoca sonucu ağaç üzerinde hesaplarken birkaç kez hata yapıp düzeltti; doğru adımlar şunlardır (ekrandan, 01:05:00):

- $a+b=2+2=4$
- $a-c=2-1=1$
- $4\cdot1=4$
- $2^2=4$
- $4\cdot4=16$
- $b/c=2/1=2$
- $16-2=14$

**Prefix'i tarayarak değerlendirme.** Prefix ifadede soldan taranır; bir operatörün hemen ardından iki operand gelmişse o işlem yapılır ve ifade küçültülür. `- * * + 2 2 - 2 1 ↑ 2 2 / 2 1` için: $+\,2\,2\to4$, ifade `- * * 4 - 2 1 ↑ 2 2 / 2 1` olur; $-\,2\,1\to1$, `- * * 4 1 ↑ 2 2 / 2 1`; $*\,4\,1\to4$; $\uparrow 2\,2\to4$; $*\,4\,4\to16$; $/\,2\,1\to2$; $-\,16\,2\to14$. Aynı sonuç bulunur. Hoca, kısa yoldan taramada hata olasılığının çok daha yüksek olduğunu, genelde ağacı kullanmanın istendiğini söyledi.

**Postfix** (ekrandan, 01:05:00): gidebildiğin kadar sola: $a$, $b$, $+$; sağdaki alt ağaç: $a$, $c$, $-$; kökleri $*$; sonra $2$, $2$, $\uparrow$; kökleri $*$; sonra $b$, $c$, $/$; en son $-$.

- Postfix: `a b + a c - * 2 2 ↑ * b c / -`

Python ile her iki gösterimin değeri de 14 olarak doğrulandı.

### 6.3 Aynı ifadede çarpı yerine çıkarma: $(a+b)*(a-c)-2\wedge2-(b/c)$

Hoca, $2\wedge2$'den önceki operatör çıkarma olsaydı ağacın farklı çıkacağını gösterdi (ekrandan, 01:30:00). Bu kez $(a+b)(a-c)$ hesaplanır, sonra $2^2$ çıkarılır, sonra $b/c$ çıkarılır. Aynı seviyeye üçüncü bir düğüm eklenemeyeceği için ilk çıkarmanın sonucu ikinci çıkarmanın sol çocuğu olur:

```text
                   -
                /     \
               -       /
            /     \   / \
           *       ↑ b   c
          / \     / \
         +   -   2   2
        / \ / \
       a  b a  c
```

$a=2,\ b=2,\ c=1$ için: $2+2=4$, $2-1=1$, $4\cdot1=4$, $2^2=4$, $4-4=0$, $2/1=2$, $0-2=-2$. Kök düğüm $-$ olur ve sonuç $-2$'dir.

> **Hocanın vurgusu:** Ağaca yerleştirme her gösterim için aynıdır. Bu denklemi infix, prefix ya da postfix olarak versem de ağaç aynı çıkar; farklı olan yalnız ağaç üzerinde dolaşma biçimidir.

Hoca ayrıca kendi yazacağı bir programda bir matematiksel ifadeyi değerlendirmek isteyen biri için, ifadeyi prefix ya da postfix'e dönüştürüp öyle değerlendirmenin daha doğru olduğunu söyledi. Derleyicilerin değerlendirme tarafında da çoğunlukla ağaç kullanılır: infix ifade ayrıştırma ağacına yerleştirilir, postfix hali elde edilir ve postfix ifade değerlendirilir.

## 7. Postfix ve Prefix İfadeden Ağaç Kurma

### 7.1 Postfix ifadeden ağaç

Geçmiş sınavdan bir postfix soru ele alındı (ekrandan, 01:40:00). Soru $m=1$, $n=2$ değerleri için verilmişti; değişkenlerin yerine değerler yazılınca ifade şu hale gelir:

- `2 2 ↑ 2 1 * + 3 ↑ 2 *`

**Elle değerlendirme.** Postfix'te baştan taranır; ilk operatör görülünce ondan önceki iki operand işleme girer, ilki sol, ikincisi sağ operanddır:

- `2 2 ↑` → $2^2=4$; ifade `4 2 1 * + 3 ↑ 2 *`
- `2 1 *` → $2$; ifade `4 2 + 3 ↑ 2 *`
- `4 2 +` → $6$ (işlem $4+2$'dir; çıkarma olsaydı sıra önemli olurdu)
- `6 3 ↑` → $6^3=216$
- `216 2 *` → $432$

**Ağaç kurma.** Mantık aynıdır. İki operand okunur ($2$, $2$): biri sol, öbürü sağ çocuk olur. Ardından bir operatör ($\uparrow$) okunur: bu ikisinin kökü olur. Sonra yine iki operand ($2$, $1$) ve operatörleri $*$ okunur; bu ikinci alt ağaçtır. Sonra $+$ okunur: kendinden önceki iki alt ağacın üstüne kök olarak gelir; sol çocuğu $\uparrow$ alt ağacı, sağ çocuğu $*$ alt ağacıdır. Sonra $3$ okunur; ardından $\uparrow$ geldiği için $+$ alt ağacı bu üssün sol çocuğu, $3$ sağ çocuğu olur. Sonra $2$ ve $*$ gelir: üs alt ağacı sol, $2$ sağ çocuk olur.

```text
                  *
                /   \
               ↑     2
             /   \
            +     3
          /   \
         ↑     *
        / \   / \
       2   2 2   1
```

**Infix.** Ağaçtan infix çok kolay yazılır; her düğümde parantez kullanmak işlem önceliğini korur:

- $\big(((2\uparrow2)+(2*1))\uparrow3\big)*2$

Hoca, $\uparrow3$'ün yalnız $2*1$'e değil, $+$ alt ağacının tamamına ait olduğunu vurguladı: önce toplama yapılır, sonra küp alınır. Değer: $4+2=6$, $6^3=216$, $216\cdot2=432$.

**Prefix.** Kök $*$, sonra sol tarafta operatörler toplanır: $\uparrow$, $+$, $\uparrow$; sonra $2$, $2$; sonra $+$'nın sağındaki $*$, $2$, $1$; sonra $3$; en son $2$:

- Prefix: `* ↑ + ↑ 2 2 * 2 1 3 2`

Elle kontrol: `↑ 2 2` → 4, `* 2 1` → 2; ifade `* ↑ + 4 2 3 2`; `+ 4 2` → 6; `↑ 6 3` → 216; `* 216 2` → 432. Python ile doğrulandı.

> **Hocanın vurgusu:** Postfix'ten üretilen ağaç, infix ağacıyla aynıdır. İfade infix ya da prefix olarak verilseydi de aynı ağaç çıkardı; yalnız dolaşma farklıdır.

### 7.2 Prefix ifadeden ağaç

Yine geçmiş sınavdan bir prefix soru (ekrandan, 01:45:00), $b=4$, $a=2$ için:

- `+ * + ↑ 3 2 a / b a 3`

**Ağaç kurma.** Prefix'te de baştan bakılır; kalıp $+AB$'dir: ilk operatör kök, ardından sol, sonra sağ gelir. İlk $+$ köktür. Ardından gelen $*$ bunun sol çocuğudur ve kendisi de bir köktür. Ardından gelen $+$ çarpının sol çocuğudur. Ardından gelen $\uparrow$ bu artının sol çocuğudur; $\uparrow$'ın sol çocuğu $3$, sağ çocuğu $2$'dir. $\uparrow$ alt ağacı tamamlanınca iç $+$'nın sağ çocuğu $a$ olur. Sonra $/$ gelir: bu, $*$'ın sağ çocuğudur; sol çocuğu $b$, sağ çocuğu $a$'dır. En son $3$, kökteki $+$'nın sağ çocuğudur.

```text
              +
            /   \
           *     3
         /   \
        +     /
       / \   / \
      ↑   a b   a
     / \
    3   2
```

**Değer** ($a=2$, $b=4$): $3^2=9$, $9+2=11$, $4/2=2$, $11\cdot2=22$, $22+3=25$.

**Prefix'i tarayarak değerlendirme.** `+ * + ↑ 3 2 2 / 4 2 3`: operatörün ardından iki operand gelen ilk yer `↑ 3 2` → 9; `+ 9 2` → 11; ifade `+ * 11 / 4 2 3`; burada $*$'ın ardından iki operand yok, `/ 4 2` → 2; `+ * 11 2 3`; `* 11 2` → 22; `+ 22 3` → 25.

**Infix:** $\big((3\uparrow2)+a\big)*(b/a)+3$; parantezler işlem önceliğini sağlamak için konur.

**Postfix:** gidebildiğin kadar sola inilir ve önce $3$ görülür; sonra $2$, kökü $\uparrow$; sonra $a$, kökü $+$; sonra sağdaki $b$, $a$, $/$; kökleri $*$; sonra $3$; en son $+$:

- Postfix: `3 2 ↑ a + b a / * 3 +`

Python ile prefix, postfix ve infix değerlerinin üçünün de 25 olduğu doğrulandı.

> **Hocanın vurgusu:** Yaprakta kesinlikle operandlar, ara düğümlerde operatörler olur. Sınavda bir infix, postfix ya da prefix ifade verilip belli değerler için çözülmesi istenirse istediğiniz yöntemi kullanabilirsiniz; ağaç yığından daha kısa sürer. Bu konuda birkaç alıştırma yapmanız faydalı olur.

### 7.3 Slayttaki kısa örnekler

Hoca slayttaki kısa örnekleri hızlıca kontrol etti. $A-B/C$ ağaca yerleştirilirken $A$ solda, $-$ kökte olur; sağda $B/C$ alt ağacı yer alır. Bir başka örnekte $(A-B)*C$ için postfix `A B - C *` olur: $A$ ve $B$ sol ve sağ operand, kökleri $-$; bu alt ağaç sol, $C$ sağ, kök $*$.

## 8. İkili Ağaç Türleri ve Dengeli Ağaç

### 8.1 Aynı düğüm sayısına sahip farklı ikili ağaçlar

Slayttaki örnek (ekrandan, 01:50:00): aynı sayıda düğümle farklı yükseklikte ikili ağaçlar kurulabilir.

- $n=0$: boş ağaç
- $n=1$: 1 ağaç
- $n=2$: 2 ağaç (tek çocuk solda ya da sağda)
- $n=3$: 5 ağaç

Bu farklılık, örneğin operatör önceliklerinde ortaya çıkar: ağaca yerleştirme farklı olunca farklı ağaçlar elde edilir. Her düğümün tek çocuğu olduğu ağaç da bir ağaçtır ve doğrusal bir liste gibidir; bu durum ikili arama ağaçlarında karşımıza çıkar.

> **Ek bilgi (derste anlatılmadı):** $n$ düğümlü farklı ikili ağaçların sayısı Catalan sayısı $C_n=\frac{1}{n+1}\binom{2n}{n}$ ile verilir; $n=0,1,2,3$ için $1,1,2,5$ değerleri slayttaki sayılarla uyumludur.

### 8.2 Tam ikili ağaç

Uç düğümler hariç her düğümün iki çocuğu varsa ağaca tam (full) ikili ağaç denir. Slaytta verilen özellikler:

- $t$ adet uç düğüm varsa yükseklik için $\log_2 t\le h$ olur.
- $i$ adet ara düğüm varsa $i+1$ adet uç düğüm vardır ve toplam düğüm sayısı $2i+1$'dir.

Hocanın örneğinde 4 ara düğüm ve 5 uç düğüm vardı; toplam $4+5=9=2\cdot4+1$ düğüm.

### 8.3 Dengeli ağaç

Yüksekliği $h$ olan bir ağacın bütün yapraklarının seviyesi $h$ ya da $h-1$ ise ağaç dengelidir. Slayttaki ilk ağacın yüksekliği 3'tür ve yaprakları 3 ya da 2 seviyesindedir; bu yüzden dengelidir. İkinci ağacın yüksekliği 4'tür ama seviyesi 2 olan bir yaprağı vardır; $4-2=2$ olduğu için dengesizdir. Kısa daldaki yaprağın altına bir düğüm eklenirse ağaç daha dengeli hale gelir.

## 9. İkili Arama Ağacı ve Dizide Saklama

### 9.1 Ekleme kuralı

İkili arama ağacının (binary search tree) özelliği: kök düğümden küçük olanlar sola, büyük olanlar sağa yerleştirilir. Genel kural budur, ama tersi (büyükleri sola) de tercih edilebilir. Veri sayı olabileceği gibi karakterlerin ASCII karşılıkları gibi karşılaştırılabilen değerler de olabilir.

İlk eleman her zaman köktür; sonrakiler köke göre yerleşir. Örnek: $4,3,8,9$.

- 4 kök olur.
- 3, 4'ten küçüktür: sola.
- 8, 4'ten büyüktür: sağa.
- 9, 4'ten büyük, 8'den de büyüktür: 8'in sağına.

Sıralı veri ($1,2,3,4,5,\ldots$) eklenirse her eleman bir öncekinin sağına gelir ve ağaç bir bağlı liste (doğrusal liste) gibi olur; sol işaretçiler hep boş kalır. Bu, dengesiz ağacın uç örneğidir. Böyle ağaçları dengeli hale getiren yapılar (örneğin B-ağaçları) veri yapıları dersinde görülür.

### 9.2 Slayttaki tartışmalı örnek

Slayttaki "Binary Search Tree Oluşturma" örneğinde $1,3,4,5,6,10,16,17,19$ dizisi için ağacın kökünün adım adım değiştiği gösteriliyordu (ekrandan, 01:55:00, 02:00:00). Hoca bunun standart ikili arama ağacı ekleme algoritması olmadığını söyledi: kuralda düğümler yer değiştirmez, büyükse sağa, küçükse sola eklenir. Bunu bir çevrim içi görselleştirme aracında göstererek $1,3,4,5,6$ eklendiğinde ağacın sağa doğru bir zincir olduğunu, silme işleminin de aynı karşılaştırma mantığıyla arama yaparak çalıştığını gösterdi. B-ağacı görselleştirmesinde düğümlerin bölünüp kökün değiştiğini de denedi; slayttaki şekil buna da tam uymadı. Hoca bu iki slaydın atlanmasını istedi.

> **Ek bilgi (derste anlatılmadı):** Ekleme sırasında kökü değişen ve ağacı dengede tutan yapılar kendini dengeleyen arama ağaçlarıdır (örneğin AVL ağaçları döndürme işlemiyle, B-ağaçları düğüm bölme ile dengeyi korur). Slayttaki şekil büyük olasılıkla böyle bir dengeleme algoritmasından alınmıştır.

### 9.3 Uygun sırayla verilen dizi ve ağacın dizide saklanması

Slayttaki ikinci örnek (ekrandan, 02:05:00): $23,13,19,47,11,43,7,29,52$ dizisi ikili arama kuralına göre ağaca yerleştirilir.

- 23 köktür.
- 13 < 23: sola.
- 19 < 23, 19 > 13: 13'ün sağına.
- 47 > 23: sağa.
- 11 < 23, 11 < 13: 13'ün soluna.
- 43 > 23, 43 < 47: 47'nin soluna.
- 7 < 23, 7 < 13, 7 < 11: 11'in soluna.
- 29 > 23, 29 < 47, 29 < 43: 43'ün soluna.
- 52 > 23, 52 > 47: 47'nin sağına.

```text
               23
            /      \
          13        47
         /  \      /  \
       11    19  43    52
       /         /
      7         29
```

Ağaç bir dizide saklanmak istenirse kök 1. indise konur; $i$ indisindeki düğümün sol çocuğu $2i$, sağ çocuğu $2i+1$ indisine yerleşir. Boş kalan konumlar 0 ile gösterilir:

| İndis | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 | 12 | 13 | 14 | 15 |
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
| Değer | 23 | 13 | 47 | 11 | 19 | 43 | 52 | 7 | 0 | 0 | 0 | 29 | 0 | 0 | 0 |

Örneğin 11 (indis 4) düğümünün sol çocuğu 7, indis 8'dedir; 43 (indis 6) düğümünün sol çocuğu 29, indis 12'dedir. Tablo python ile ağaç kurulup indislenerek doğrulandı. Sınavda dizi verilip ağaç şekli ya da ağaç verilip dizi şekli istenebilir; önce ağaç kurulur, sonra dizi çıkarılır.

> **Ders sonrası not:** Hoca indis formülünü anlatırken önce "$i+1$, $i+2$" dedi, sonra "bunun bir denklem hali vardır, şimdilik gerek yok" diyerek geçti. Slayttaki numaralar (1; 2, 3; 4, 5, 6, 7; 8, 12) sol çocuk için $2i$, sağ çocuk için $2i+1$ kuralıyla uyumludur.

## 10. Ağaç Gezinme Yöntemleri

Ağaç düğümlerinin listelenmesi (traversal), prefix, infix ve postfix ile aynı mantıktadır: preorder prefix'e, inorder infix'e, postorder postfix'e karşılık gelir.

### 10.1 İkili ağaç örnekleri

Slayttaki ilk ağaçta düğümler preorder sırasına göre numaralanmıştır: kök 1; sol çocuğu 2 (çocukları 3 ve 4); sağ çocuğu 5 (çocukları 6 ve 7).

- Preorder: önce kökler toplanır. 1, sonra 2, sonra 3; başka kök kalmadı, sağa 4; sonra kökün sağı 5, 6, 7 → $1,2,3,4,5,6,7$.
- Inorder ($A+B$ mantığı): $3,2,4,1,6,5,7$.
- Postorder: $3,4,2,6,7,5,1$.

İkinci ağaçta düğümler inorder sırasına göre numaralanmıştır: kök 4; sol çocuğu 2 (çocukları 1 ve 3); sağ çocuğu 6 (çocukları 5 ve 7).

- Inorder: $1,2,3,4,5,6,7$.
- Preorder: 4 yazılır; sola gelinir, 2 de kök olduğu için yazılır; sonra 1, 3; sağda 6, 5, 7 → $4,2,1,3,6,5,7$.
- Postorder: $1,3,2,5,7,6,4$.

Bu sıralar python ile doğrulandı. Hoca, "ters postorder" için de aynı mantığın kullanılabileceğini, $A+B$ ağacında tersten bir sıralama elde edildiğini söyledi.

> **Ders sonrası not:** Bu kısımda hoca ters sırayı bir yerde "$+BA$" (kök-sağ-sol) olarak, derse başlarken ise "$BA+$" (sağ-sol-kök) olarak yazdı. Kök-sağ-sol sırası postorder dizisinin tersten okunmuş halidir; sağ-sol-kök sırası ise preorder dizisinin tersten okunmuş halidir.

> **Hocanın vurgusu:** $A+B$ ile burada çözemeyeceğiniz soru yok; yalnız özyinelemeli düşünüp algoritmayı zihninizde çalıştırmanız gerekir.

### 10.2 Çok çocuklu ağaçta gezinme

Slaytta ikiden fazla çocuğu olan düğümler için tanımlar verilir (ekrandan, 02:10:00, 02:15:00). Kökü $r$, alt ağaçları soldan sağa $T_1,T_2,\ldots,T_n$ olan bir ağaçta:

- Preorder: $r\,T_1\,T_2\ldots T_n$ ($+ABC\ldots$ gibi)
- Inorder: $T_1\,r\,T_2\ldots T_n$ ($A+B$ gibi; kök ilk alt ağaçtan sonra yazılır)
- Postorder: $T_1\,T_2\ldots T_n\,r$

Hoca, üçlü ya da daha çok çocuklu ağaçlarda $AB$ sırasına gelince $ABC$ diye devam edileceğini söyledi. Çocuklar arasında büyüklük-küçüklük sırası yoktur; uygulamada her düğüm birden çok işaretçi tutar ve çocuklar soldan sağa sıralanır.

Slayttaki ağaç:

```text
                     a
          /          |          \
         b           c           d
       /   \                  /  |  \
      e     f                g   h   i
     / \                    / \
    j   k                  l   m
      / | \
     n  o  p
```

**Preorder.** $a$ köktür. Sol çocuk $b$ de bir kök, yazılır; onun solu $e$ de bir kök; $e$'nin solu $j$; sonra $e$'nin sağındaki $k$ bir kök: $k$, sonra çocukları $n,o,p$. $e$ alt ağacı bitince $b$'nin sağı $f$; sonra $a$'nın ikinci çocuğu $c$; sonra $d$, onun ilk çocuğu $g$, $g$'nin çocukları $l,m$; sonra $h$, $i$.

- Preorder: `a b e j k n o p f c d g l m h i`

Hoca ilk denemede $f$'yi atlayınca bir öğrenci $c$'den önce $f$ gelmesi gerektiğini hatırlattı; sıra düzeltildi.

> **Hocanın vurgusu:** $B$'den sonra $C$ yazılmaz, çünkü $B$ bir köktür ve altında başka kökler vardır. Kök öncelikli gidilir: $C$'yi görmeden önce $B$'nin altındaki bütün düğümler alınır.

**Inorder.** En sola inilir: $j$; sonra kökü $e$; sonra $e$'nin sağındaki $k$ alt ağacında yine önce en sol: $n$, sonra kök $k$, sonra $o$, $p$. Bu bitince $b$, sonra $f$; sonra $a$; sonra $c$; sonra $d$ alt ağacında önce $g$ alt ağacı: $l$, $g$, $m$; sonra $d$; sonra $h$, $i$.

- Inorder: `j e n k o p b f a c l g m d h i` (ekrandan, 02:15:00)

Hoca $k$ düğümüne $o$'dan sonra yeniden dönüldüğünü, $a$'ya da $c$'den sonra yeniden ulaşıldığını, ama bir kez ziyaret edilen düğümün ikinci kez yazılmadığını belirtti. Örneğin $k$ bir işlem olsaydı $n\ k\ o\ k\ p$ gibi bir matematiksel anlam taşıyabilirdi; yine de aynı görünen düğüm bir daha yazılmaz.

**Soru:** $n$, $o$, $p$ kendi aralarında nasıl sıralanıyor? **Cevap:** Soldan sağa, $A+B$ mantığıyla. Burada büyüklük-küçüklük sırası yoktur; uygulamada düğüm üç işaretçi tutar ve veri hangi kurala göre eklendiyse ona göre (keyfi de olabilir) sıralanır. Inorder dolaşırken en soldaki düğümden başlanıp sağa doğru gidilir. Bu bir ikili arama ağacı değildir, çünkü ikili bir yapı yoktur.

**Postorder.** Sola, sola, sola inilir: $j$; sonra $k$'nın çocukları $n,o,p$, sonra $k$; sonra $e$; sonra $f$, $b$; sonra $c$; sonra $d$ alt ağacında $l,m$, $g$, sonra $h,i$, $d$; en son $a$.

- Postorder: `j n o p k e f b c l m g h i d a`

> **Ders sonrası not:** Hoca postorder sırasını sesli okurken "$J, O, N, O, P, K, \ldots$" dedi. Doğru sıra yukarıdaki gibidir: `j n o p k e f b c l m g h i d a` (python ile doğrulandı).

Aritmetik ifadeler de aynı notasyonla gezilir; slayttaki bir ifadenin prefix ve postfix formları verilmişti, hoca daha zor örnekleri çözdüğü için onu geçti.

## 11. Huffman Kodlama

### 11.1 Fikir

Huffman kodlama verileri sıkıştırmada kullanılan bir algoritmadır. En sık kullanılan karaktere en az sayıda bit, az geçen karaktere daha fazla bit atar. Örneğin metinde en fazla $A$ geçiyorsa $A$'ya daha az bit verilir. Algoritmanın ayrıntısı daha çok veri yapılarının konusudur.

Huffman ağacında bütün karakterler yapraklarda bulunur. Kökten itibaren her düğümde sola gidince 0, sağa gidince 1 eklenir; bir karakterin kodu, kökten o yaprağa giden yoldaki bitlerdir.

### 11.2 "rate" kelimesinin kodlanması

Slayttaki iki ağaç (ekrandan, 02:20:00):

- Sol ağaç: $a=000$, $r=001$, $c=010$, $t=011$, $e=100$.
- Sağ ağaç: $a=000$, $t=001$, $c=01$, $e=10$, $r=11$.

"rate" kelimesi sol ağaçla `001 000 011 100`, sağ ağaçla `11 000 001 10` olarak kodlanır. Sağ ağaç karakter sıklıklarına göre oluşturulduğundan bazı karakterlere daha kısa kod verir. Hoca, ağacın karakterlerin alfabetik sırasına göre değil sıklıklarına göre kurulduğunu vurguladı.

### 11.3 Çevrim içi görselleştirme

Hoca bir Huffman görselleştirme aracında küçük bir metinle ağacın nasıl kurulduğunu gösterdi: en küçük sıklıklı iki sembol alınıp bir ağaç oluşturulur, sonra sıradaki en küçükler eklenir, en sonunda bütün alt ağaçlar tek ağaçta birleşir; ardından sağ dallara 1, sol dallara 0 verilir. Bir sembolün sıklığı çok artırıldığında o sembolün 1 bitle, ötekilerin 2 ya da 3 bitle kodlandığı görüldü. <!-- BELİRSİZ: araçta girilen metin ve sıklıklar altyazıda tutarsız (A,A,B,B,C,C,C,D,D yazıldı ama A=3, B=3, C=4, D=2 okundu); ilgili ana ait kare yok. -->

Hoca sıkıştırmanın kazancını şöyle anlattı: normalde ASCII tablosunda her karakter sabit uzunlukta yer kaplar; Huffman ile sık geçen karaktere 1 bit verildiğinde, örneğin 8 tekrar 1 bayta sığar. Sonuçta yine 0 ve 1'lerle saklanır, ama toplam bit sayısı azalır.

> **Ders sonrası not:** Hoca hesapta "her karakter 8 byte" dedi. Doğrusu, ASCII'de bir karakter 8 bit (1 bayt) yer kaplar; 10 karakterlik metin sabit kodlamayla 80 bit (10 bayt) eder.

### 11.4 Slayt örneği: $a,e,k,l,m,z$

Slayttaki problem (ekrandan, 02:25:00): $a,e,k,l,m$ ve $z$ sembolleri sırasıyla 25, 14, 8, 7, 4 ve 2 adet bulunsun. Her sembol için Huffman kodu bulunacak.

- **Adım 1:** Sembollerin kullanım sıklıkları küçükten büyüğe sıralanır: $2\ 4\ 7\ 8\ 14\ 25$.
- **Adım 2:** Soldan başlanarak sıradaki iki sıklık değerinin toplamı, sıralamayı bozmayacak şekilde diziye yerleştirilir:

  $2\ \ 4\ \ {-6}\ \ 7\ \ 8\ \ {-13}\ \ 14\ \ {-21}\ \ 25\ \ {-35}\ \ {-60}$

Toplam değerler slaytta kırmızıyla gösterilir; eksi işareti değerin bir ara toplam olduğunu söyler. $n$ sembol varsa genişletilmiş dizi $2n-1$ elemanlıdır (burada $2\cdot6-1=11$).

Bir öğrenci eksi değerlerin anlamını sorunca, slayttaki "eksi değer ara toplamdır" notu birlikte okundu. Toplamalar sırasıyla şöyledir: $2+4=6$; $6+7=13$; $13+8=21$; $21+14=35$; $35+25=60$. Hoca ilk okumada 60'ın nereden geldiğini karıştırdı; bir öğrencinin hatırlatmasıyla toplamın 21 ile 14'ten (35), sonra 35 ile 25'ten (60) geldiği netleşti.

**Ağacın kurulması** (ekrandan, 02:30:00): sondan geriye gelinir. $-60$ köktür; eksili olan (ara toplam) bir tarafa, artılı olan (yaprak) öbür tarafa konur. $-60$'ın çocukları $-35$ ve 25; $-35$'in çocukları $-21$ ve 14; $-21$'in çocukları $-13$ ve 8; $-13$'ün çocukları 7 ve $-6$; $-6$'nın çocukları 4 ve 2.

```text
                 -60
                /    \
             -35      25 (a)
            /    \
         -21      14 (e)
        /    \
     -13      8 (k)
    /    \
  7 (l)   -6
         /   \
      4 (m)   2 (z)
```

Sol dallara 0, sağ dallara 1 verilince kodlar şöyle olur (ara adım eklendi):

| Sembol | Sıklık | Kod | Bit sayısı | Toplam bit |
|---|---|---|---|---|
| a | 25 | 1 | 1 | 25 |
| e | 14 | 01 | 2 | 28 |
| k | 8 | 001 | 3 | 24 |
| l | 7 | 0000 | 4 | 28 |
| m | 4 | 00010 | 5 | 20 |
| z | 2 | 00011 | 5 | 10 |

Hoca, 25 kez geçen karakterin toplam 25 bitlik, 14 kez geçenin 28 bitlik alan kapladığını söyledi; bu tablo ile uyumludur. Toplam $135$ bit eder; 6 sembolü sabit uzunlukta kodlamak sembol başına 3 bit, yani $60\cdot3=180$ bit gerektirirdi (python ile hesaplandı).

Hoca, $-6$ ile 7'nin yerleri değiştirilse de bit sayısı açısından bir şey değişmeyeceğini, ağacın başka biçimlerde de kurulabileceğini söyledi. Ayrıca slayttaki yöntemin, toplamı diziye "kafaya göre" yerleştirmek yerine her adımda en küçük iki değeri birleştiren daha kolay bir yolunun olduğunu belirtti.

> **Ek bilgi (derste anlatılmadı):** Standart Huffman algoritmasında her adımda o an kalan bütün düğümler arasından en küçük sıklıklı iki düğüm birleştirilir (genellikle öncelik kuyruğu kullanılır). Bu örnekte 13 ile 8 birleştikten sonra en küçük iki değer 14 ve 21 olduğundan sonuç slayttaki ağaçla aynı çıkar.

## 12. Kapsayan Ağaç, BFS ve DFS

### 12.1 Kapsayan ağaç (spanning tree)

Bir graf üzerinde ulaşılabilecek bütün düğümleri işaretleyen, bütün düğümleri içeren bir alt ağaç kurmak istenebilir. Örneğin bir kargo şirketi güzergahındaki bütün noktaları tek bir yol ağıyla, gereksiz kenar eklemeden göstermek ister. Bütün düğümleri içeren bu alt ağaca kapsayan ağaç (spanning tree) denir. Bu kavram graflara ait olduğu için hoca, graflardan sonra anlatmanın daha mantıklı olacağını söyledi.

Hoca bunu bir dizi üzerinden anlattı: $A,B,C,D,E,F,G$ düğümleri için her kenar eklendiğinde yeni bir düğüme ulaşılır ve o düğüm ziyaret edildi (1) olarak işaretlenir. Dizinin bütün elemanları 1 olana kadar kenar eklenirse bir kapsayan ağaç bulunur.

Ağırlıklı graflarda (örneğin kenarlar 4, 8, 3 birim olsun) hangi kenarların seçildiği toplam maliyeti değiştirir. Bir graf için farklı kapsayan ağaçlar kurulabilir (slayttaki örneklerde farklı ağırlık kombinasyonları); hepsi döngüsüzdür ve bütün düğümleri içerir. Bunların en az maliyetlisine minimum kapsayan ağaç (minimum spanning tree) denir.

### 12.2 Oluşturma yöntemleri

Slayttaki iki temel yöntem (ekrandan, 02:35:00):

- Genişlik öncelikli arama (breadth-first search): düğümleri seviye seviye ziyaret eder.
- Derinlik öncelikli arama (depth-first search, backtracking): bir daldan gidebildiği kadar derine iner, sonra geri dönüp başka dala geçer.

BFS kuyruk (queue), DFS yığın (stack) kullanır. DFS'te en son kalınan noktayı unutmamak için yığın tutulur.

### 12.3 DFS örneği

Slayttaki örnekte $A$'dan başlanır. $A$'nın komşuları arasında $D$, $H$ ve $B$; $D$'nin komşusu $F$; $B$'nin komşuları $E$ ve $C$ vardır. <!-- BELİRSİZ: DFS slaydının karesi yok; graf yapısı altyazıdaki anlatımdan kuruldu. -->

- $A$ yığına konur ve ziyaret edilir. İlk komşu $D$ yığına konur; $D$'nin komşusu $F$ yığına konur.
- $F$'nin gidilmemiş komşusu yoktur, yığından çıkarılır; yığın sayesinde $D$'de kalındığı hatırlanır. $D$'nin de başka komşusu yoktur, çıkarılır.
- $A$'nın başka komşuları olduğu için $A$ çıkarılmaz; $H$'ye gidilir. $H$'nin başka komşusu yoktur, çıkarılır.
- $A$'dan $B$'ye gidilir, $B$'den $E$'ye. $E$ çıkarılınca $B$'ye dönülür, $C$ eklenir. $C$ çıkarılır, sonra $B$, en son $A$; yığın boşalır.
- Ziyaret sırası (çıktı): $A, D, F, H, B, E, C$.

Hoca, $B$'nin $C$ komşusuna bakılmadan önce $E$'nin derinliğine inildiğini vurguladı. Yığına ilk kez eklenen düğüm çıktıya yazılır; yazarken düğümün daha önce ziyaret edilip edilmediğine dikkat edilir. İşin sonunda yığın boş olmalıdır.

### 12.4 BFS örneği

Slayttaki BFS özellikleri (ekrandan, 02:40:00): düğümleri seviye bazında ziyaret eder; kök düğümden başlar ve düğümleri düzey düzey ziyaret eder; bir sonraki seviyeye geçmeden önce bulunduğu seviyedeki tüm düğümleri ziyaret eder; kuyruk veri yapısını kullanır. Kuyrukta ekleme arkadan, çıkarma önden yapılır.

Graf: $A$–$B$, $A$–$C$, $B$–$F$, $C$–$E$, $C$–$D$, $D$–$H$, $H$–$J$. Başlangıç $A$. Slayttaki tablo:

| Adım | Eklenen | Çıkan | Kuyruk | Çıktı |
|---|---|---|---|---|
| 1 | A | - | A | A |
| 2 | B-C | A | B-C | B-C |
| 3 | F | B | C-F | F |
| 4 | E-D | C | F-E-D | E-D |
| 5 | - | F | E-D | - |
| 6 | - | E | D | - |
| 7 | H | D | H | H |
| 8 | J | H | J | J |
| 9 | - | J | - | - |

Çıktı: `A-B-C-F-E-D-H-J`.

Komşuların hangi sırayla eklendiği önemli değildir; $A$'nın komşuları bir veri yapısında $B,C$ sırasıyla saklanıyorsa o sırayla eklenir. Slaytta $C$'nin komşularından önce $E$, sonra $D$ eklenmiştir; önce $D$ eklenseydi çıktı $A,B,C,F,D,E,H,J$ olurdu. Hoca kuyruğu yeniden yazarken bu ikinci sırayı ($D$ önce) kullandı.

**Soru:** $C$'den sonra $D$ eklenirse $H$'ye hemen gidilmez mi? **Cevap:** Hayır. BFS'te kuyruk sırası korunur: $C$'nin komşuları $D$ ve $E$ eklendikten sonra önce kuyrukta bekleyen $F$ işlenir, sonra $D$ (onun komşusu $H$ kuyruğa girer), sonra $E$, sonra $H$ (komşusu $J$ girer), en son $J$. Hemen $H$'ye inmek derinlik öncelikli aramaya benzer.

### 12.5 Bina benzetmesi ve kör arama

Hoca BFS ve DFS'i bir fakülte binasında bir hocanın odasını arama örneğiyle anlattı. Bina dört bloktan (A, B, C, D) ve her blok dört kattan oluşsun; katlar arasında bloklar arası geçiş de olsun.

- Bir yol, A bloğunun 1, 2, 3, 4. katlarını gezmek, bulamazsanız B bloğunun dört katını gezmek ve böyle devam etmektir: A1-A2-A3-A4, B1-B2-B3-B4, ... Bu derinlemesine aramadır.
- Öbür yol, önce bütün blokların birinci katlarını (A1, B1, C1, D1), sonra ikinci katlarını (A2, B2, C2, D2), sonra üçüncü ve dördüncü katlarını gezmektir. Bu genişlemesine aramadır.

> **Ders sonrası not:** Hoca ikinci yolu anlatırken bir yerde "depth first search yapmak da şu demektir" dedi. Doğrusu, önce bütün birinci katları sonra bütün ikinci katları gezmek, seviye seviye ilerleyen genişlik öncelikli aramadır (BFS); bir bloğu baştan sona bitirmek derinlik öncelikli aramadır (DFS).

Bunlar kör arama (blind search) algoritmalarıdır: arama yapılırken hedef hakkında herhangi bir bilgiye sahip olunmaz; bulunana kadar ya da bulunamayana kadar gezilir. BFS ve DFS minimum kapsayan ağacı vermez. Aramayı daha bilgili yapmak ve en az maliyetli ağacı bulmak için Prim ve Kruskal algoritmaları kullanılır; bunlar bir sonraki derste graflarla birlikte işlenecektir.

## Örnek Sorular

**Soru 1** (ekrandan, 00:45:00): $(a+b-c)\sqrt[n]{x}$ ifadesini ikili ağaca yerleştirip prefix ve postfix gösterimlerini yazınız.

> **Çözüm:** $\sqrt[n]{x}=x^{1/n}$ yazılır. Kök $*$; sol alt ağaç $(a+b)-c$, sağ alt ağaç $x\uparrow(1/n)$. Prefix: `* - + a b c ↑ x / 1 n`. Postfix: `a b + c - x 1 n / ↑ *` (ekrandan, 00:50:00).

**Soru 2** (ekrandan, 00:55:00): $(a+b)*(a-c)*2\wedge2-(b/c)$ ifadesini ağaca yerleştirin; prefix ve postfix gösterimlerini yazın ve $a=2$, $b=2$, $c=1$ için değerini bulun.

> **Çözüm:** Kök $-$; solunda $((a+b)*(a-c))*(2\uparrow2)$, sağında $b/c$. Prefix: `- * * + a b - a c ↑ 2 2 / b c`. Postfix: `a b + a c - * 2 2 ↑ * b c / -` (ekrandan, 01:05:00). Değer: $4\cdot1\cdot4-2=14$.

**Soru 3** (ekrandan, 01:30:00): Aynı ifadede ikinci çarpı yerine çıkarma olsaydı, yani $(a+b)*(a-c)-2\wedge2-(b/c)$ için ağaç nasıl olurdu ve değeri ne olurdu?

> **Çözüm:** Kök $-$; sol çocuğu $((a+b)(a-c))-(2\uparrow2)$ alt ağacı, sağ çocuğu $b/c$. Değer: $4-4-2=-2$.

**Soru 4** (ekrandan, 01:40:00): $m=1$, $n=2$ iken değişkenleri yerine konmuş haliyle `2 2 ↑ 2 1 * + 3 ↑ 2 *` postfix ifadesinin değerini bulun, ağacını çizin, infix ve prefix gösterimlerini yazın.

> **Çözüm:** Değer 432. Infix: $\big(((2\uparrow2)+(2*1))\uparrow3\big)*2$. Prefix: `* ↑ + ↑ 2 2 * 2 1 3 2`.

**Soru 5** (ekrandan, 01:45:00): $b=4$, $a=2$ iken `+ * + ↑ 3 2 a / b a 3` prefix ifadesinin ağacını çizin, değerini bulun, infix ve postfix gösterimlerini yazın.

> **Çözüm:** Değer 25. Infix: $\big((3\uparrow2)+a\big)*(b/a)+3$. Postfix: `3 2 ↑ a + b a / * 3 +`.

**Soru 6** (ekrandan, 02:05:00): $23,13,19,47,11,43,7,29,52$ dizisini ikili arama kuralına göre ağaca yerleştirip ağacı bir dizide saklayın.

> **Çözüm:** Kök 23; ağaç 9. bölümdeki gibidir. Dizi (indis 1–15): `23 13 47 11 19 43 52 7 0 0 0 29 0 0 0`.

**Soru 7** (ekrandan, 02:10:00, 02:15:00): Kökü $a$ olan çok çocuklu ağacın ($a$: $b,c,d$; $b$: $e,f$; $e$: $j,k$; $k$: $n,o,p$; $d$: $g,h,i$; $g$: $l,m$) preorder, inorder ve postorder sıralarını yazın.

> **Çözüm:** Preorder: `a b e j k n o p f c d g l m h i`. Inorder: `j e n k o p b f a c l g m d h i`. Postorder: `j n o p k e f b c l m g h i d a`.

**Soru 8** (ekrandan, 02:25:00): $a,e,k,l,m,z$ sembolleri sırasıyla 25, 14, 8, 7, 4 ve 2 adet olsun. Her sembol için Huffman kodunu bulun.

> **Çözüm:** Genişletilmiş dizi $2\ 4\ {-6}\ 7\ 8\ {-13}\ 14\ {-21}\ 25\ {-35}\ {-60}$. Sola 0, sağa 1 verilince: $a=1$, $e=01$, $k=001$, $l=0000$, $m=00010$, $z=00011$ (kodlar slayttaki son ağaçtan çıkarıldı; ara adım eklendi). Toplam 135 bit.

**Soru 9** (ekrandan, 02:40:00): Verilen grafta $A$'dan başlayarak BFS uygulayın; her adımda kuyruğu ve çıktıyı gösterin.

> **Çözüm:** Tablo 12.4'tedir. Çıktı: `A-B-C-F-E-D-H-J`.

## Dersin Toparlaması

Bu derste ağaçlar, bağıntı ve graf kavramlarının devamı olarak ele alındı. Ağaç, döngüsüz ve bağlantılı bir graftır; $n$ düğümlü bir ağacın $n-1$ kenarı vardır. Köklü ağaçlarda seviye, yükseklik, ebeveyn, çocuk, kardeş, yaprak, ara düğüm ve alt ağaç kavramları tanımlandı. Dersin en uzun bölümü ifade ağaçlarına ayrıldı: ara düğümlerde operatörler, yapraklarda operandlar bulunur; ağaç bir kez kurulduktan sonra prefix (kök-sol-sağ), infix (sol-kök-sağ) ve postfix (sol-sağ-kök) gösterimler yalnız dolaşma sırası değiştirilerek elde edilir. Geçmiş sınavlardan infix, postfix ve prefix örnekleri ağaç üzerinden çözüldü ve sayısal değerleri kontrol edildi.

Ardından ikili ağaç türleri (tam ve dengeli ağaç), ikili arama ağacına ekleme ve ağacın $2i$, $2i+1$ kuralıyla dizide saklanması, çok çocuklu ağaçlarda preorder, inorder ve postorder gezinme, sıklığa dayalı Huffman kodlama ve kapsayan ağaç kurmak için BFS (kuyruk) ile DFS (yığın) yöntemleri görüldü. Bir sonraki derste graflar ayrıntılı olarak ele alınacak ve minimum kapsayan ağaç için Prim ve Kruskal algoritmaları işlenecektir.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
