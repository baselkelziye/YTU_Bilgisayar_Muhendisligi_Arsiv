# Ders 7 Genişletilmiş Notu: Bağlamdan Bağımsız Gramerler, Türetim Ağaçları ve Belirsizlik

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Düzenli Dillerden Bağlamdan Bağımsız Dillere
- 2. Gramer Kavramı: İngilizce Örneği
- 3. Üretimler, Değişkenler ve Uç Simgeler
- 4. Kısaltma Gösterimleri
- 5. Bağlamdan Bağımsız Gramerin Biçimsel Tanımı ve Dili
- 6. Gramer Örnekleri
- 7. En Soldan ve En Sağdan Türetim
- 8. Türetim Ağaçları
- 9. Belirsizlik (Ambiguity)
- 10. Belirsizliği Kaldırma ve Doğası Gereği Belirsiz Diller
- 11. Sonlu Otomattan Gramer Yazma
- 12. Bir Dil Bağlamdan Bağımsız mı?
- Örnek Sorular

## 1. Düzenli Dillerden Bağlamdan Bağımsız Dillere

Önceki derslerde düzenli ifadeler, düzenli diller, NFA ve DFA görüldü. Bu derste bağlamdan bağımsız diller (context-free languages, CFL) başlıyor. Hoca, bu konunun sonraki sınavlarda ve finalde soruların önemli bir kısmını oluşturacağını söyledi.

Düzenli dil, bir NFA ya da DFA tarafından tanınan (kabul edilen) dildir. Her düzenli dil bir düzenli ifadeyle anlatılabilir. Slayttaki şemada düzenli diller, bağlamdan bağımsız dillerin içinde küçük bir küme olarak çizilmiştir (ekrandan, 00:05:00):

- Düzenli diller: $a^*b^*$ ve $(a+b)^*$.
- Bağlamdan bağımsız ama düzenli olmayan diller: $\{a^nb^n : n\ge 0\}$ ve $\{ww^R\}$.

$a^*b^*$, önce $a$'lardan sonra $b$'lerden oluşan dizgilerdir. Bu ifadeler için NFA ya da DFA tasarlanabilir. $\{a^nb^n\}$ ise daha karmaşıktır. Makinenin önce $a$'ları tanıması, sonra $a$'ların ardından gelen $b$'leri tanıması ve ayrıca sayılarının eşit olduğunu da anlaması gerekir. $a$ sayısı ile $b$ sayısı arasındaki bu ilişkiye hoca "bağlam" (context) diyor. $\{ww^R\}$ dilinde de dizginin ilk yarısı ile ikinci yarısı arasında bir bağlam vardır: ikinci yarı, ilk yarının tersidir. Makinenin kaynakları, özellikle belleği sınırlı olduğu için bu ilişkiler NFA/DFA ile denetlenemez; bu diller düzenli ifadeyle de anlatılamaz.

Bağlamdan bağımsız dillerde:

- Düzenli ifade yerine **bağlamdan bağımsız gramer** (context-free grammar, CFG) kullanılır.
- NFA/DFA yerine **yığıtlı otomat** (pushdown automaton, PDA) kullanılır. Bir PDA iki parçadan oluşur: bir otomat (NFA/DFA gibi) ve bir yığıt (stack).

## 2. Gramer Kavramı: İngilizce Örneği

Her dilin bir grameri vardır. Türkçenin de İngilizcenin de grameri vardır ve iletişim için cümleleri grameri izleyerek kurarız. Slayttaki İngilizce gramer örneği (ekrandan, 00:10:00):

$$\langle sentence\rangle \to \langle noun\_phrase\rangle\ \langle predicate\rangle$$
$$\langle noun\_phrase\rangle \to \langle article\rangle\ \langle noun\rangle$$
$$\langle predicate\rangle \to \langle verb\rangle$$

Bunlara ek olarak $\langle article\rangle \to a$, $\langle article\rangle \to the$, $\langle noun\rangle \to cat$, $\langle noun\rangle \to dog$, $\langle verb\rangle \to runs$, $\langle verb\rangle \to sleeps$ kuralları vardır.

"the dog sleeps" cümlesinin türetimi şöyledir:

$$\langle sentence\rangle \Rightarrow \langle noun\_phrase\rangle\langle predicate\rangle \Rightarrow \langle noun\_phrase\rangle\langle verb\rangle \Rightarrow \langle article\rangle\langle noun\rangle\langle verb\rangle$$
$$\Rightarrow the\ \langle noun\rangle\langle verb\rangle \Rightarrow the\ dog\ \langle verb\rangle \Rightarrow the\ dog\ sleeps$$

Her adımda bir kural uygulanır ve cümle bir sonraki biçime dönüşür. "a cat runs" da aynı biçimde türetilir.

Gramerin dili, bu gramerle üretilebilen bütün cümlelerin (dizgilerin) kümesidir (ekrandan, 00:15:00):

$$L = \{\text{a cat runs},\ \text{a cat sleeps},\ \text{the cat runs},\ \text{the cat sleeps},\ \text{a dog runs},\ \text{a dog sleeps},\ \text{the dog runs},\ \text{the dog sleeps}\}$$

İki tanımlık, iki isim ve iki fiil olduğu için $2\cdot2\cdot2 = 8$ cümle vardır; dilin büyüklüğü 8'dir.

**Soru (hoca):** Bu gramerin dili düzenli midir? **Cevap (bir öğrenci):** Düzenlidir, çünkü sonludur. Hoca bunu onayladı ve hatırlattı: düzenli diller bağlamdan bağımsız dillerin alt kümesidir. Düzenli diller için hem düzenli ifade hem de bağlamdan bağımsız gramer yazılabilir. Ama her bağlamdan bağımsız dilin bir grameri olduğu halde düzenli ifadesi yoktur; örneğin $\{a^nb^n\}$ için düzenli ifade yoktur.

## 3. Üretimler, Değişkenler ve Uç Simgeler

Gramerdeki kurallara **üretim** (production) ya da kural denir. Örnekte $\langle noun\rangle$, $\langle sentence\rangle$ gibi öğeler **değişkendir** (variable). $cat$, $dog$, $runs$, $sleeps$ ise **uç simgedir** (terminal): $\langle noun\rangle$ $cat$'e dönüşebilir ama $cat$ başka bir şeye dönüşemez, türetim orada biter. $\langle sentence\rangle \to \langle noun\_phrase\rangle\langle predicate\rangle$ kuralında sağ taraf iki değişkenin bitiştirmesidir (concatenation). Sonunda her değişken bir uç simge dizisiyle sonlandırılır.

Soyut bir örnek:

$$S \to aSb \qquad S \to \varepsilon$$

Burada büyük harf $S$ değişkendir; $a$ ve $b$ uç simgelerdir, alfabe $\{a,b\}$'dir. $\varepsilon$ boş dizgidir.

$ab$ dizgisinin türetimi: $S \Rightarrow aSb \Rightarrow ab$. Birinci adımda birinci üretim ($S$ yerine $aSb$), ikinci adımda ikinci üretim ($S$ yerine $\varepsilon$) kullanıldı.

$aabb$ dizgisinin türetimi: $S \Rightarrow aSb \Rightarrow aaSbb \Rightarrow aabb$. Birinci üretim iki kez, sonra ikinci üretim bir kez kullanıldı.

Aynı şekilde $S \Rightarrow aSb \Rightarrow aaSbb \Rightarrow aaaSbbb \Rightarrow aaabbb$ elde edilir (ekrandan, 00:20:00). Bu gramer $\{a^nb^n : n\ge 0\}$ dilinin grameridir. Dil düzenli değildir ama bu gramerle dilin bütün elemanları üretilebilir.

## 4. Kısaltma Gösterimleri

### 4.1 Yıldızlı türetim

Uzun türetim zincirlerini her seferinde yazmak zaman alır ve karmaşıklaşır. Bunun yerine şu yazılır (ekrandan, 00:20:00):

$$S \overset{*}{\Rightarrow} aaabbb$$

Bu, $S$'den bir ya da daha çok türetim adımıyla $aaabbb$'ye ulaşıldığı anlamına gelir; $S\Rightarrow aSb\Rightarrow aaSbb\Rightarrow aaaSbbb\Rightarrow aaabbb$ yerine kullanılır.

Genel olarak $w_1 \overset{*}{\Rightarrow} w_n$ yazmak, $w_1 \Rightarrow w_2 \Rightarrow \cdots \Rightarrow w_n$ biçiminde bir türetim dizisi olduğunu söyler. Ayrıca her dizgi için $w \overset{*}{\Rightarrow} w$ de doğrudur; bu durumda kullanılan üretim sayısı sıfırdır.

Örnek gramerde mümkün türetimler: $S \overset{*}{\Rightarrow} \varepsilon$, $S \overset{*}{\Rightarrow} ab$, $S \overset{*}{\Rightarrow} aaabbb$.

### 4.2 Dikey çizgi

$S \to aSb$ ve $S \to \varepsilon$ üretimleri tek satırda birleştirilir:

$$S \to aSb \mid \varepsilon$$

Dikey çizgi "ya da" anlamındadır. İngilizce örnekteki $\langle article\rangle \to a$ ve $\langle article\rangle \to the$ de $\langle article\rangle \to a \mid the$ olarak yazılır.

## 5. Bağlamdan Bağımsız Gramerin Biçimsel Tanımı ve Dili

Bütün üretimler $A \to x$ biçimindedir: sol tarafta tek bir değişken, sağ tarafta değişken ve uç simgelerden oluşan bir dizgi. Bir gramer dörtlü olarak yazılır (ekrandan, 00:25:00):

$$G = (V, T, S, P)$$

- $V$: değişkenler kümesi,
- $T$: uç simgeler kümesi,
- $S$: başlangıç değişkeni,
- $P$: üretimler kümesi.

$S \to aSb \mid \varepsilon$ için: $P = \{S \to aSb,\ S \to \varepsilon\}$ iki elemanlıdır, $V = \{S\}$, $T = \{a, b\}$, başlangıç değişkeni $S$'dir. Uç simgeler alfabeyi belirler. $\varepsilon$ boş dizgidir, alfabenin elemanı değildir.

Başlangıç değişkeni $S$ olan bir $G$ gramerinin dili:

$$L(G) = \{\, w : S \overset{*}{\Rightarrow} w,\ w \in T^* \,\}$$

Yani $S$'den başlayıp birçok üretim uygulandıktan sonra ulaşılan ve uç simgelerin Kleene yıldızının elemanı olan dizgiler. Örnek gramer için $w \in \{a,b\}^*$ olmak üzere:

$$L(G) = \{\, a^nb^n : n \ge 0 \,\}$$

**Tanım:** Bir $L$ dili bağlamdan bağımsızdır, eğer $L = L(G)$ olacak biçimde bağlamdan bağımsız bir $G$ grameri varsa (ekrandan, 00:30:00). Bu yüzden her düzenli dil bağlamdan bağımsızdır: her düzenli dilin bir grameri vardır. Tersi doğru değildir. $\{a^nb^n : n\ge 0\}$ bağlamdan bağımsızdır, çünkü onu üreten bir gramer var.

## 6. Gramer Örnekleri

### 6.1 $S \to aSa \mid bSb \mid \varepsilon$

Tablette yazılan örnek (ekrandan, 00:35:00). Bu satırda üç üretim vardır: $S \to aSa$, $S \to bSb$, $S \to \varepsilon$. Biçimsel olarak:

$$G = (\{S\},\ \{a,b\},\ S,\ \{S \to aSa,\ S \to bSb,\ S \to \varepsilon\})$$

Örnek türetim: önce $S \to aSa$, sonra ortadaki $S$ yerine $bSb$, sonra $aSa$, en son $\varepsilon$:

$$S \Rightarrow aSa \Rightarrow abSba \Rightarrow abaSaba \Rightarrow abaaba$$

$abaaba$ dizgisinde ilk yarı $aba$, ikinci yarı da onun tersi $aba$'dır. Hoca başka bir türetimle de aynı yapıyı gösterdi: dizgi $w$ ile $w^R$'nin bitiştirmesidir. Gramerin dili:

$$L(G) = \{\, ww^R : w \in \{a,b\}^* \,\}$$

Hoca, bir gramerin dilini bulmak için grameri inceleyip birkaç örnek dizgi üretmeyi ve dili bu örneklerden yazmayı önerdi.

### 6.2 Eşleşen parantezler

Slayttaki türetimler (ekrandan, 00:40:00):

$$S \Rightarrow SS \Rightarrow aSbS \Rightarrow abS \Rightarrow ab$$
$$S \Rightarrow SS \Rightarrow aSbS \Rightarrow abS \Rightarrow abaSb \Rightarrow abab$$

<!-- BELİRSİZ: Gramerin üretim satırı karede görünmüyor. Türetimlerden S → aSb | SS | ε olduğu anlaşılıyor; bu gramerin 6 uzunluğa kadar tam olarak dengeli parantez dizgilerini ürettiği python ile denetlendi. -->

Gramerin dili:

$$L(G) = \{\, w : n_a(w) = n_b(w) \text{ ve her } v \text{ öneki için } n_a(v) \ge n_b(v) \,\}$$

$n_a(w)$, $w$'deki $a$ sayısıdır. Hoca bunu "$a$ sayısı $b$ sayısına eşit" diye özetledi; slayttaki ikinci koşul, hiçbir önekte kapanan parantezin açılandan fazla olmamasını ister. $a = ($ ve $b = )$ alınırsa dil, doğru eşleşmiş parantez dizilerini anlatır: örneğin $()((()))(())$.

Hoca bunu Türkçe şöyle açıkladı: yazılımda açılan her parantez kapatılmalıdır. C'de bir if bloğu ya da bir aritmetik ifade yazarken açılan parantez kapanmalı, açık ya da kapanmamış parantez kalmamalıdır. Bir C programındaki bütün karakterleri atıp yalnız parantezleri bıraksanız, kalan dizi bu dil ailesine uymalıdır.

## 7. En Soldan ve En Sağdan Türetim

Bir dizgi değişkenlerden türetilirken iki sıra izlenebilir:

- **En soldan türetim** (leftmost derivation): her adımda en soldaki değişken açılır.
- **En sağdan türetim** (rightmost derivation): her adımda en sağdaki değişken açılır.

Örnek gramer (ekrandan, 00:45:00):

$$1.\ S \to AB \qquad 2.\ A \to aaA \qquad 3.\ A \to \varepsilon \qquad 4.\ B \to Bb \qquad 5.\ B \to \varepsilon$$

### 7.1 $aab$ için en soldan türetim

$S$ başlangıç değişkeni olduğu için önce 1. üretim kullanılır: $AB$. Sonra en soldaki değişken $A$'dır; $aab$ üretmek istediğimiz için 2. üretim seçilir: $aaAB$. Yine en soldaki değişken $A$'dır, bu kez 3. üretim: $aaB$. Artık tek değişken $B$ kaldı, o yüzden en soldaki odur: 4. üretimle $aaBb$, 5. üretimle $aab$.

$$S \overset{1}{\Rightarrow} AB \overset{2}{\Rightarrow} aaAB \overset{3}{\Rightarrow} aaB \overset{4}{\Rightarrow} aaBb \overset{5}{\Rightarrow} aab$$

### 7.2 $aab$ için en sağdan türetim

$S$'den $AB$; en sağdaki değişken $B$, 4. üretim: $ABb$. Yine en sağdaki $B$, 5. üretim: $Ab$. Tek değişken $A$ kaldı: 2. üretim $aaAb$, 3. üretim $aab$ (ekrandan, 00:45:00).

$$S \overset{1}{\Rightarrow} AB \overset{4}{\Rightarrow} ABb \overset{5}{\Rightarrow} Ab \overset{2}{\Rightarrow} aaAb \overset{3}{\Rightarrow} aab$$

Hoca, genelde en soldan ya da en sağdan türetimden birinin kullanılması gerektiğini, bazen karışık sıranın da kullanılabildiğini söyledi. Aradan sonra Türkçe olarak şunu ekledi: bazı gramerlerde soldan ve sağdan türetim aynı dizgiyi verir; ama soldan türetilebilen bir dizginin sağdan türetimle elde edilemediği gramerler de olabilir, buna dikkat edilmeli.

> **Ek bilgi (derste anlatılmadı):** Bağlamdan bağımsız bir gramerde bir dizgi türetilebiliyorsa onun hem en soldan hem en sağdan türetimi vardır; ikisi de aynı türetim ağacından okunabilir. Bu yüzden hocanın "soldan türetilip sağdan türetilemeyen" dizgi uyarısı büyük olasılıkla türetim sırasının farklı ağaçlar verebileceğini anlatmak içindir.

## 8. Türetim Ağaçları

Türetim, bir ağaç olarak da gösterilebilir. $S \to AB$ üretimi, kökü $S$ olan ve çocukları $A$ ile $B$ olan bir düğüm olarak çizilir. $S \Rightarrow AB \Rightarrow aaAB \Rightarrow aaABb \Rightarrow aaBb \Rightarrow aab$ türetiminin ağacı (ekrandan, 00:50:00):

```text
            S
          /   \
         A     B
       / | \   | \
      a  a  A  B  b
            |  |
            ε  ε
```

Ağacın yapraklarını soldan sağa okumak dizgiyi verir: $aa\varepsilon\varepsilon b = aab$. Buna ağacın ürünü (yield) denir. Ağacın her alt düzeyi, bir üstteki değişkenin hangi sembollerin bitiştirmesine dönüştüğünü gösterir.

Hoca ağacın düzey düzey nasıl büyüdüğünü de gösterdi. En soldan türetimde ağacın sol kolu derinleşir (sol taraf düzey 2'ye inerken sağ taraf düzey 1'de kalır). Sol ve sağ adımlar sırayla yapıldığında iki kol aynı düzeyde ilerler.

**Bazen türetim sırası önemli değildir** (ekrandan, 00:55:00): $aab$ için

- en soldan türetim $S \Rightarrow AB \Rightarrow aaAB \Rightarrow aaB \Rightarrow aaBb \Rightarrow aab$,
- en sağdan türetim $S \Rightarrow AB \Rightarrow ABb \Rightarrow Ab \Rightarrow aaAb \Rightarrow aab$

aynı türetim ağacını verir.

## 9. Belirsizlik (Ambiguity)

### 9.1 Matematiksel ifadeler için gramer

Slayttaki gramer (ekrandan, 01:10:00):

$$E \to E + E \mid E * E \mid (E) \mid a$$

Örnek dizgi: $(a+a)*a+(a+a*(a+a))$. Slayta göre $a$ herhangi bir sayıyı temsil eder.

Hoca bu kısmı Türkçe olarak özellikle vurguladı. Buradaki $+$ toplama işareti değil, bir semboldür; $*$ da çarpma değil, bir semboldür; parantezler de matematiksel parantez değil, sembollerdir. Bu gramerle üretilen şey bir dizgidir, matematiksel bir işlem değildir.

> **Hocanın vurgusu:** Dil, dizgilerin kümesidir. $a+a*a$ gibi bir ifade parantez, $a$, artı ve yıldız sembollerinden oluşan bir dizgidir. Geçmişte bazı öğrenciler bu dizgiyi hesaplayıp "$a$'ya 1 verirsem sonuç şu olur" gibi yorumlar yapmıştı; bu yanlıştır. Bu derste dillerle uğraşıyoruz.

### 9.2 $a+a*a$ için en soldan türetim

Slayttaki türetim (ekrandan, 01:15:00):

$$E \Rightarrow E+E \Rightarrow a+E \Rightarrow a+E*E \Rightarrow a+a*E \Rightarrow a+a*a$$

Önce $E \to E+E$ kullanılır. En soldaki $E$ açılır ve $a$ olur. Sonra kalan tek değişken açılır: $E \to E*E$. Şimdi iki değişken vardır, en soldaki açılır ($a$), en son kalan da $a$ olur. Ağacı:

```text
          E
        / | \
       E  +  E
       |   / | \
       a  E  *  E
          |     |
          a     a
```

Hoca sınavda böyle ağaçların çizilmesinin istenebileceğini söyledi.

**Soru (bir öğrenci):** İkinci adımda $E$'yi doğrudan $a$'ya çevirip $a+E$ yazdık. Başka yerde $E*E$ ile başlayan bir türetim de görüyoruz. Burada da öyle ilerleyemez miydik, bu bir tercih mi yoksa zorunluluk mu? **Cevap:** Burada hep soldan türetim yapıyoruz, ama ilk adımda başka bir üretimle de başlanabilir. Hoca bunu tablette birlikte yaptı:

$$E \Rightarrow E*E \Rightarrow E+E*E \Rightarrow a+E*E \Rightarrow a+a*E \Rightarrow a+a*a$$

Yine aynı dizgi elde edildi, ama türetim farklıdır ve bu da farklı bir ağaç demektir.

### 9.3 İki farklı türetim ağacı

$a+a*a$ dizgisinin iki türetim ağacı (ekrandan, 01:20:00):

```text
  Ağaç 1 (kökte +)              Ağaç 2 (kökte *)
          E                             E
        / | \                         / | \
       E  +  E                       E  *  E
       |   / | \                   / | \    |
       a  E  *  E                 E  +  E   a
          |     |                 |     |
          a     a                 a     a
```

Programlama dillerinde belli bir dizgiyi üreten her zaman tek bir ağaç olmalıdır. Aynı dizgiyi üreten birden çok soldan türetimli ağaç varsa gramer belirsizdir (ambiguous). Hoca Türkçe karşılık olarak "belirsizlik, ikilemlik" dedi.

Neden sorun olduğu $a = 2$ alınarak gösterildi. Bilgisayarda bu sembollere sonradan anlam yüklenir: $+$ işaretine "aritmetik mantık biriminde iki sayıyı topla", $*$ işaretine "çarp" denir. İşlem CPU'ya gitmeden önce ifadenin ayrıştırılması (parse edilmesi) gerekir. Kullanıcı $2+2*2$ girdiyse:

- Ağaç 1 ile (alttan yukarı): önce $2*2 = 4$, sonra $2 + 4 = 6$.
- Ağaç 2 ile: önce $2+2 = 4$, sonra $4 * 2 = 8$.

Matematikte önce çarpma yapılır, doğru sonuç 6'dır. Yani Ağaç 1 doğru, Ağaç 2 yanlış yorumdur. Bu gramerde işlem önceliği (precedence) tanımlı değildir; bu yüzden gramer belirsizdir ve belirsizliğin kaldırılması gerekir.

> **Ders sonrası not:** Hoca anlatırken bir an iki ağacın verdiği sonuçları karıştırdı; hemen ardından soldaki ağacın 6, sağdakinin 8 verdiğini söyledi. Doğrusu budur.

Derleyicilerde ifadeler değerlendirilirken her dizginin tek bir türetim ağacı olmalıdır. Hoca bir dizginin hem en soldan hem en sağdan türetimi olabileceğini, sorun olmadığını; ama tek bir ağaç (tek bir en soldan türetim) olması gerektiğini vurguladı.

### 9.4 Belirsiz gramerin tanımı

Bağlamdan bağımsız bir $G$ grameri belirsizdir, eğer $L(G)$'de iki farklı türetim ağacı ya da iki farklı en soldan türetimi olan bir $w$ dizgisi varsa (ekrandan, 01:25:00). Slayttaki not: iki farklı türetim ağacı iki farklı en soldan türetim verir ve tersi de doğrudur. $E \to E+E \mid E*E \mid (E) \mid a$ belirsizdir, çünkü $a+a*a$ için iki ağaç vardır.

### 9.5 if-then-else örneği

Tablette yazılan üretimler (ekrandan, 01:30:00):

$$IF\_STMT \to if\ EXPR\ then\ STMT$$
$$IF\_STMT \to if\ EXPR\ then\ STMT\ else\ STMT$$

Bu gramer belirsiz midir? Hoca iki türetim yazdı (ekrandan, 01:35:00):

1. $STMT \Rightarrow if\ EXPR\ then\ STMT \Rightarrow if\ EXPR\ then\ if\ EXPR\ then\ STMT\ else\ STMT$: önce birinci üretim, sonra içteki $STMT$ ikinci üretimle açılır. $else$ içteki (ikinci) $if$'e aittir.
2. $STMT \Rightarrow if\ EXPR\ then\ STMT\ else\ STMT \Rightarrow if\ EXPR\ then\ if\ EXPR\ then\ STMT\ else\ STMT$: önce ikinci üretim, sonra $then$'den sonraki $STMT$ birinci üretimle açılır. $else$ dıştaki (birinci) $if$'e aittir.

İki dizgi aynıdır ama sondaki $else\ STMT$ farklı $if$'lere bağlanır. Bu, gramerde belirsizlik olduğunu gösterir. Hoca, programlama dillerinde böyle bir yapı göremeyeceğinizi söyledi. Belirsizliği kaldırmak için bir "end" işareti konabilir ya da parantez açılıp kapatılabilir: end işareti, bir $STMT$'nin hangi $if$'e ait olduğunu söyler. C ya da Java'da `if (a == 5) { ... }` yazarken kullanılan süslü parantezler bu işi görür; aksi halde içerideki işlemlerin hangi $if$'e ait olduğu bilinemez. Slayttaki dizgi: "if expr1 then if expr2 then stmt1 else stmt2".

> **Ek bilgi (derste anlatılmadı):** Bu sorun derleyici kitaplarında "dangling else" (sarkan else) diye bilinir. Birçok dil, blok işaretleri kullanılmadığında $else$'i en yakın eşleşmemiş $if$'e bağlama kuralını benimser.

## 10. Belirsizliği Kaldırma ve Doğası Gereği Belirsiz Diller

### 10.1 Başarılı bir örnek

Slaytta solda belirsiz gramer, sağda ona eşdeğer belirsiz olmayan gramer var (ekrandan, 01:40:00):

| Belirsiz gramer | Eşdeğer, belirsiz olmayan gramer |
|---|---|
| $E \to E+E$ | $E \to E+T \mid T$ |
| $E \to E*E$ | $T \to T*F \mid F$ |
| $E \to (E)$ | $F \to (E) \mid a$ |
| $E \to a$ | |

Hocanın açıklaması: belirsiz gramerde $+$ ve $*$ işlemleri aynı değişkenler ($E$ ve $E$) üzerinde uygulanıyor; aynı dizgide aynı değişkenlerin kullanılması belirsizliğe yol açıyor. Yeni gramerde $E+T$ yazılır, $T$ farklı bir değişkendir. Her işlem için ayrı bir değişken tanımlanarak üretimler birbirinden ayrılır; parantezler en sona ($F$ düzeyine) konur: $T$, $F$'ye; $F$ de $(E)$'ye gider. İki gramer eşdeğerdir, yani aynı dili üretir. Bu gramerle bir dizginin türetim ağacı tektir; örneğin slayttaki türetim için ikinci bir ağaç yoktur, bu yüzden gramer belirsiz değildir.

> **Hocanın vurgusu:** Bir dilin birden çok grameri olabilir. Bazı gramerler belirsiz, bazıları belirsiz olmayabilir. Hoca bunun çok güzel bir doğru-yanlış sorusu olduğunu söyledi.

> **Ek bilgi (derste anlatılmadı):** Sağdaki gramerde $*$ işlemi $T$ düzeyinde, $+$ işlemi $E$ düzeyinde üretildiği için $*$ ağaçta her zaman $+$'dan daha aşağıda kalır; çarpmanın önceliği böylece gramere işlenmiş olur. $E \to E+T$ biçimindeki sol özyineleme de aynı öncelikteki işlemlerin soldan sağa gruplanmasını sağlar.

### 10.2 Başarısız bir örnek: doğası gereği belirsiz dil

Slayttaki dil (ekrandan, 01:45:00):

$$L = \{a^nb^nc^m\} \cup \{a^nb^mc^m\}, \qquad n, m \ge 0$$

Hoca dile bakarak grameri tablette yazdı:

$$S \to AC \mid DB$$
$$A \to aAb \mid \varepsilon \qquad C \to cC \mid \varepsilon$$
$$D \to aD \mid \varepsilon \qquad B \to bBc \mid \varepsilon$$

Gramerin kuruluşu:

- Birinci kümede $a$ sayısı $b$ sayısına eşittir ve ardından sayısı $a$, $b$'ye bağlı olmayan $c$'ler gelir. Bu yüzden $AC$ bitiştirmesi kullanılır. $A \to aAb$ her adımda bir $a$'yı sola, bir $b$'yi sağa ekler; böylece sayılar birlikte artar, $A \to \varepsilon$ türetimi sonlandırır. $C \to cC \mid \varepsilon$ istenen sayıda $c$ üretir.
- İkinci kümede $b$ sayısı $c$ sayısına eşittir, önündeki $a$'ların sayısı bağımsızdır. Bu yüzden $DB$ kullanılır: $D$ istenen sayıda $a$, $B \to bBc$ eşit sayıda $b$ ve $c$ üretir.
- Birleşim (union) $S \to AC \mid DB$ ile, yani "ya da" ile kurulur.

Bu gramerin 6 uzunluğa kadar tam olarak $L$'yi ürettiği python ile denetlendi.

Neden belirsiz? $abc$ dizgisi hem birinci kümenin ($n=1, m=1$) hem ikinci kümenin ($n=1, m=1$) elemanıdır. Bu dizgi $S \Rightarrow AC$ yoluyla da $S \Rightarrow DB$ yoluyla da türetilir, yani iki farklı ağacı vardır. Slayta göre $L$ doğası gereği belirsizdir (inherently ambiguous): bu dili üreten her gramer belirsizdir. Aradan sonra hoca da aynı sonucu vurguladı: bu dizgi iki dilin de elemanı olduğu için farklı ağaçlar ortaya çıkıyor ve dilin kendisi belirsizdir.

> **Ders sonrası not:** Hoca anlatım sırasında, sembolleri değiştirerek (iki kümede farklı harfler kullanarak) belirsizliğin kaldırılabileceğini söyledi. Bu artık aynı dil değildir; slaytın da belirttiği gibi $L$'nin kendisi için belirsiz olmayan bir gramer yazılamaz.

## 11. Sonlu Otomattan Gramer Yazma

### 11.1 NFA $M_1$

Tablette çizilen NFA (ekrandan, 01:50:00 ve 01:55:00). Durumlar $S$ (başlangıç), $B$ (kabul durumu), $C$:

| Durum | $a$ | $b$ | $c$ |
|---|---|---|---|
| $\to S$ | $B$ | — | — |
| $*B$ | $B$ | $C$ | — |
| $C$ | $C$ | — | $S$ |

Bu makinenin dili düzenlidir; düzenli diller bağlamdan bağımsız dillerin alt kümesi olduğu için bağlamdan bağımsızdır ve bir grameri vardır. Hoca durumlara ad verip her durumu bir değişken yaptı: $S$'de $a$ okununca $B$'ye gidilir ($S \to aB$); $B$'de $a$ okununca aynı durumda kalınır ($B \to aB$), $b$ ile $C$'ye gidilir ($B \to bC$); $C$'de $a$ ile $C$'de kalınır, $c$ ile $S$'ye dönülür. $B$ kabul durumu olduğu için $B \to \varepsilon$ eklenir:

$$S \to aB \qquad B \to aB \mid bC \mid \varepsilon \qquad C \to aC \mid cS$$

### 11.2 NFA $M_2$

Durumlar $S$ (başlangıç ve kabul) ve $A$ (ekrandan, 01:55:00):

| Durum | $a$ | $b$ |
|---|---|---|
| $\to *S$ | $S$ | $A$ |
| $A$ | $A$ | $S$ |

$S$ kabul durumu olduğu için $S \to \varepsilon$ de vardır:

$$S \to aS \mid \varepsilon \mid bA \qquad A \to aA \mid bS$$

### 11.3 $L(M_1)\cdot L(M_2)$ için gramer

Soru: "Find the grammar for $L(M_1)\cdot L(M_2)$" (ekrandan, 01:55:00). Bitiştirme için yeni bir başlangıç değişkeni $S$ alınır ve iki gramerin başlangıç değişkenleri arka arkaya konur: $S \to S_1S_2$. İki gramerde de $S$ değişkeni olduğu için birinin $S_1$, diğerinin $S_2$ olarak yeniden adlandırılması gerekir. $A$ yalnız $M_2$'de kullanıldığı için değiştirilmesine gerek yoktur.

$$S \to S_1S_2$$
$$S_1 \to aB_1 \qquad B_1 \to aB_1 \mid bC_1 \mid \varepsilon \qquad C_1 \to aC_1 \mid cS_1$$
$$S_2 \to aS_2 \mid \varepsilon \mid bA \qquad A \to aA \mid bS_2$$

Hoca dikkat çekti: $C_1$'in kuralında $cS$ değil $cS_1$ yazılmalıdır. Bu gramerin 5 uzunluğa kadar tam olarak $L(M_1)L(M_2)$'yi ürettiği python ile denetlendi.

### 11.4 Bir DFA'nın grameri ve düzenli ifadesi

Aradan sonra hoca $\{0,1\}$ alfabesinde bir DFA çizdi (ekrandan, 02:15:00 ve 02:20:00):

| Durum | $0$ | $1$ |
|---|---|---|
| $\to *A$ | $A$ | $B$ |
| $B$ | $B$ | $C$ |
| $*C$ | $C$ | $A$ |

Tablette yazılan gramer:

$$A \to 0A \mid 1B \qquad B \to 0B \mid 1C \qquad C \to 0C \mid 1A$$

> **Ders sonrası not:** $A$ ve $C$ kabul durumları olduğu için gramere $A \to \varepsilon$ ve $C \to \varepsilon$ de eklenmelidir. Bunlar olmadan hiçbir türetim uç simgelerle bitmez ve gramerin dili boş olur.

Ardından hoca düzenli ifadeyi sordu ve Türkçe olarak kurdu. İki kabul durumu olduğu için en az iki terim olacak: $A$'da kalan dizgiler ve $C$'ye ulaşan dizgiler. $0^*$ ile $A$'da kalınır; $0^*10^*10^*$ ile $C$'ye ulaşılır. $C$'den $A$'ya ya da $C$'ye dönülebilir; bu döngüler yıldızla yazılır. Ekranda yazılan ifade:

$$0^*(\varepsilon + 0^*10^*10^* + 0^*10^*10^*10^*)^* + 0^*10^*10^*(\varepsilon + 0^*10^* + 0^*10^*10^*10^*)^*$$

(ekrandan, 02:20:00; ikinci satırın başındaki $0^*$ tablette kırmızıyla karalanmış.) Hoca, böyle bir otomat için gramer yazmanın düzenli ifade yazmaktan daha kolay olduğunu söyledi.

Örnekler (ekrandan, 02:20:00): $0 \in L(M)$, $00 \in L(M)$, $1 \notin L(M)$; hoca sözlü olarak $11$'in elemanı olduğunu söyledi.

> **Ders sonrası not:** Ekranda $001 \in L(M)$ yazıyor; $001$ okununca $A \to A \to A \to B$ izlenir ve $B$ kabul durumu değildir, yani $001 \notin L(M)$. Ayrıca DFA'nın dili, 1 sayısı 3'e bölündüğünde kalanı 0 ya da 2 olan dizgilerdir. Ekrandaki ifade yıldızın içinde "iki 1" bloğunu tekrarlattığı için örneğin $1111$'i (dört tane 1, $B$'de biter) de kabul ediyor. Doğru bir ifade $0^*(10^*10^*10^*)^*(\varepsilon + 10^*10^*)$ olur. İkisi de python ile 9 uzunluğa kadar DFA'ya karşı denetlendi.

## 12. Bir Dil Bağlamdan Bağımsız mı?

Hoca bağlamdan bağımsız diller için de bir pompalama önsavı (pumping lemma) olduğunu söyledi: biri düzenli diller için, diğeri bağlamdan bağımsız diller için. Bağlamdan bağımsız olmayan diller de vardır. Önsava geçmeden önce, sezgisel bir yolla birkaç dili tartıştı. Ölçütü şuydu: dilde kaç tane "bağlam" (sınırsız sayı ilişkisi) olduğuna bakılır; tek bir bağlam varsa dil bağlamdan bağımsızdır, birbirine bağlı birden çok bağlam varsa değildir.

Tartışılan diller (ekrandan, 02:25:00 ve 02:30:00):

- $\{a^nb^n\}$: $a$ sayısı $b$ sayısına eşit, CFL. $a$ sayısının $b$ sayısından bir eksik olduğu dil de CFL.
- $\{a^nb^ma^n : n \ge 0, m \ge 0\}$: CFL. Baştaki $a$'larla sondaki $a$'ların sayısı eşit olacak; tek bir bağıntı var. **Soru (bir öğrenci):** Context-free değildir diyebilir miyim? **Cevap:** Hayır; burada yalnız bir bağıntı var.
- $\{a^nb^na^n : n \ge 0\}$: CFL değil. Baştaki $a$'lar $b$'lerle, $b$'ler de sondaki $a$'larla eşit olacak; bağlam sayısı birden fazla.
- $\{a^nb^mc^k : k = \max(m,n)\}$: Hoca önce tereddüt etti; bir öğrencinin itirazı üzerine şöyle açıkladı: $a$ ve $b$ sayılarını bulup maksimumunu almak bir bağlam, bunun $c$ sayısına eşit olması ayrı bir bağlam; bu yüzden CFL değil. Hoca öğrencinin şüphesinin doğru olduğunu söyledi. <!-- BELİRSİZ: O anki karede (02:25:00) bu dilin yanında "CFL" yazıyor ve üstü çizili değil; sözlü sonuç "CFL değil". Doğrusu CFL değildir. -->
- $\{a^nb^mc^k : n > k,\ m > k\}$: CFL değil; $a$ sayısının $c$'den, $b$ sayısının da $c$'den fazla olması iki ayrı bağlamdır.
- Altı elemanlı sonlu bir dil: $\{\varepsilon, abc, aabbcc, aaabbbccc, aaaabbbbcccc, aaaaabbbbbccccc\}$ (ekrandan, 02:30:00). Öğrenciler "değildir" dedi; hoca eleman sayısının sonlu olduğunu, bu yüzden dilin hem düzenli hem bağlamdan bağımsız olduğunu söyledi. <!-- BELİRSİZ: Dilin tanımı (koşulu) karede görünmüyor; elemanlar ekranda yazılı. -->
- $\{a^mb^nc^k : m, n \ge 0,\ k = \min(m,5)\}$: Ekranda "regular and CFL" yazıyor (ekrandan, 02:30:00). $a$ sayısı ile $c$ sayısı 5'e kadar eşit, sonra $c$ sayısı 5'te kalıyor; bu ilişki sonlu sayıda (6 tane) durumla sınırlı.
- $\{a^mb^mc^k : k = \min(m,5)\}$: Bir öğrenci üç bağıntı olduğunu düşündü ($a$-$b$, $a$-$c$, $b$-$c$). Hoca şöyle açıkladı: $c$ sayısı bir yerden sonra değişmez. 1 $a$ varsa 1 $c$, 2 $a$ varsa 2 $c$, ..., 5 $a$ varsa 5 $c$; 100 ya da bir milyon $a$ varsa yine 5 $c$. $a$ ile $c$ arasındaki ilişki sonlu olduğu için bir "bağlam" sayılmaz; geriye yalnız $a$-$b$ eşitliği kalır, dil CFL'dir. Ama $a^mb^m$ kısmı yüzünden düzenli değildir; bir önceki dil ise düzenliydi. Hoca küçük değişikliklerin dilin sınıfını tamamen değiştirebildiğini vurguladı.
- Ardından $c$ sayısının $m$'ye sınırsız bağlı olduğu bir değişken tartışıldı: $a$ ile $c$ sayısı da eşit olacağı için bağlam sayısı birden fazla, CFL değil. <!-- BELİRSİZ: Bu son dilin tam tanımı karede görünmüyor. --> Bir sonraki örnek ($n = k!$ gibi bir koşulla) zaman bittiği için tamamlanmadı.

> **Ek bilgi (derste anlatılmadı):** "Bağlam sayma" bir ispat değil, sezgidir. Bir dilin bağlamdan bağımsız olmadığını kesin olarak göstermek için bağlamdan bağımsız diller için pompalama önsavı kullanılır; hoca bu önsava sonraki derste devam edeceğini belirtti.

## Örnek Sorular

**Soru 1** (derste sözlü, 00:13:46): İngilizce örnek gramerin ürettiği 8 cümlelik dil düzenli midir?

> **Çözüm (derste verildi):** Evet. Dil sonludur; her sonlu dil düzenlidir (ve dolayısıyla bağlamdan bağımsızdır).

**Soru 2** (ekrandan, 00:45:00; derste sözlü, 00:45:30): $S \to AB$, $A \to aaA \mid \varepsilon$, $B \to Bb \mid \varepsilon$ gramerinde $aab$ için verilen türetim en soldan mı, en sağdan mı?

> **Çözüm (derste verildi):** Slayttaki $S \Rightarrow AB \Rightarrow aaAB \Rightarrow aaB \Rightarrow aaBb \Rightarrow aab$ türetiminde her adımda en soldaki değişken açılıyor; türetim en soldandır. <!-- BELİRSİZ: Sorunun sorulduğu andaki türetim karede görünmüyor; cevap "leftmost" olarak verildi. -->

**Soru 3** (ekrandan, 01:20:00): $E \to E+E \mid E*E \mid (E) \mid a$ gramerinde $a+a*a$ için iki farklı türetim ağacı çizin. $a = 2$ alınırsa ağaçlar hangi değerleri verir?

> **Çözüm (derste verildi):** Bölüm 9.3'teki iki ağaç. Kökte $+$ olan ağaç $2+(2\cdot2) = 6$, kökte $*$ olan ağaç $(2+2)\cdot2 = 8$ verir. Gramer belirsizdir.

**Soru 4** (ekrandan, 01:30:00): $IF\_STMT \to if\ EXPR\ then\ STMT \mid if\ EXPR\ then\ STMT\ else\ STMT$ grameri belirsiz midir?

> **Çözüm (derste verildi):** Evet. "if expr1 then if expr2 then stmt1 else stmt2" dizgisinde $else$ hem içteki hem dıştaki $if$'e bağlanacak biçimde iki türetim vardır (Bölüm 9.5).

**Soru 5** (ekrandan, 01:45:00): $L = \{a^nb^nc^m\} \cup \{a^nb^mc^m\}$, $n, m \ge 0$ için gramer yazın. Gramer belirsiz midir?

> **Çözüm (derste verildi):** $S \to AC \mid DB$, $A \to aAb \mid \varepsilon$, $C \to cC \mid \varepsilon$, $D \to aD \mid \varepsilon$, $B \to bBc \mid \varepsilon$. $abc$ iki farklı yoldan türetildiği için belirsizdir; dil doğası gereği belirsizdir.

**Soru 6** (ekrandan, 01:55:00): $M_1$ ve $M_2$ NFA'ları için $L(M_1)\cdot L(M_2)$ dilinin gramerini bulun.

> **Çözüm (derste verildi):** Bölüm 11.3'teki gramer: $S \to S_1S_2$; $S_1 \to aB_1$; $B_1 \to aB_1 \mid bC_1 \mid \varepsilon$; $C_1 \to aC_1 \mid cS_1$; $S_2 \to aS_2 \mid \varepsilon \mid bA$; $A \to aA \mid bS_2$.

**Soru 7** (ekrandan, 02:20:00; derste sözlü, 02:15:02): Bölüm 11.4'teki DFA için gramer ve düzenli ifade yazın.

> **Çözüm (derste verildi, düzeltmeyle):** Gramer $A \to 0A \mid 1B \mid \varepsilon$, $B \to 0B \mid 1C$, $C \to 0C \mid 1A \mid \varepsilon$ (derste $\varepsilon$ kuralları yazılmadı). Doğru bir düzenli ifade: $0^*(10^*10^*10^*)^*(\varepsilon + 10^*10^*)$ (ekrandaki ifade fazla dizgi kabul ediyor; bkz. Bölüm 11.4).

**Soru 8** (ekrandan, 02:25:00 ve 02:30:00): Aşağıdaki diller bağlamdan bağımsız mıdır?

- $\{a^nb^ma^n : n, m \ge 0\}$
- $\{a^nb^na^n : n \ge 0\}$
- $\{a^nb^mc^k : k = \max(m,n)\}$
- $\{a^nb^mc^k : n > k,\ m > k\}$
- $\{a^mb^nc^k : m, n \ge 0,\ k = \min(m,5)\}$
- $\{a^mb^mc^k : k = \min(m,5)\}$

> **Çözüm (derste verildi):** Sırasıyla: CFL; CFL değil; CFL değil; CFL değil; hem düzenli hem CFL; CFL ama düzenli değil (Bölüm 12).

## Dersin Toparlaması

Bu derste düzenli dillerin ötesine geçilerek bağlamdan bağımsız diller tanıtıldı. Bu dillerde semboller arasında sınırsız bir sayı ilişkisi (bağlam) vardır; bu yüzden sonlu otomatlarla tanınamazlar ve düzenli ifadeyle anlatılamazlar. Bunun yerine bağlamdan bağımsız gramerler $G = (V, T, S, P)$ kullanılır. $S \to aSb \mid \varepsilon$, $S \to aSa \mid bSb \mid \varepsilon$ ve eşleşen parantez grameri gibi örneklerle gramerin dili $L(G) = \{w \in T^* : S \overset{*}{\Rightarrow} w\}$ incelendi. En soldan ve en sağdan türetimler, türetim ağaçları ve ağacın ürünü gösterildi.

Dersin ikinci yarısının ana konusu belirsizlikti: bir dizginin iki farklı türetim ağacı varsa gramer belirsizdir. $E \to E+E \mid E*E \mid (E) \mid a$ ve if-then-else örnekleri bunun derleyicilerde neden sorun olduğunu gösterdi; $E/T/F$ grameri belirsizliğin öncelik düzeyleriyle kaldırılabildiğini, $\{a^nb^nc^m\} \cup \{a^nb^mc^m\}$ ise bazı dillerin doğası gereği belirsiz olduğunu gösterdi. Son bölümde sonlu otomatlardan gramer yazıldı ve dillerin bağlamdan bağımsız olup olmadığı sezgisel olarak tartışıldı. Hoca, bağlamdan bağımsız diller için pompalama önsavına devam edileceğini söyledi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
