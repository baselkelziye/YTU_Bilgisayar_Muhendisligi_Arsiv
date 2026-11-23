# Ders 6 Genişletilmiş Notu: Pompalama Önsavı Uygulamaları ve Bağlamdan Bağımsız Gramerler

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Düzensiz Diller ve İspat Sorunu
- 2. Güvercin Yuvası İlkesi ve DFA'da Durum Tekrarı
- 3. Pompalama Önsavı
- 4. Önsavla Düzensizlik İspatının Adımları
- 5. Örnek: $a^n b^n$
- 6. Örnek: $v v^R$
- 7. Örnek: $a^n b^l c^{n+l}$
- 8. Örnek: $a^{n!}$
- 9. Bağlamdan Bağımsız Diller
- 10. Gramer Kavramı ve İlk Örnekler
- 11. Biçimsel Tanım ve Bir Gramerin Dili
- 12. Diğer Gramer Örnekleri
- 13. Türetme Sırası
- 14. Türetme Ağaçları
- 15. Belirsizlik

## 1. Düzensiz Diller ve İspat Sorunu

Hoca derse geçen haftanın tekrarıyla başladı. Düzenli dillerin yanında düzenli olmayan (düzensiz, non-regular) diller de vardır; $\{a^n b^n : n \ge 0\}$ ve $\{v v^R\}$ bu tür dillere örnektir.

Bir dilin **düzenli olduğunu** ispatlamak kolaydır: o dili kabul eden bir DFA ya da NFA yazılır, ya da onu üreten bir düzenli ifade (regular expression) yazılır. Bir dilin **düzenli olmadığını** ispatlamak ise bu yolla yapılamaz. Böyle bir dil için DFA ya da NFA yoktur; olmayan otomatı gösteremeyiz. Var olan DFA'ların sayısı sonsuz olduğundan, hepsini tek tek gösterip hiçbirinin dili kabul etmediğini söylemek de mümkün değildir. Düzensizlik, **pompalama önsavı** (pumping lemma) denen bir önsav yardımıyla ispatlanır.

## 2. Güvercin Yuvası İlkesi ve DFA'da Durum Tekrarı

Pompalama önsavı **güvercin yuvası ilkesine** (pigeonhole principle) dayanır. İlke çok basittir: 4 güvercin ve 3 yuva varsa, güvercinler yuvalara dağıtıldığında en az bir yuvada en az iki güvercin olur, çünkü yuva sayısı güvercin sayısından azdır. Bu mantık matematikte birçok yerde kullanılır.

Otomatlarda kullanımı şöyledir. 4 durumlu bir DFA, uzunluğu 4 ya da daha fazla olan bir dizgiyi kabul ediyor olsun. Bütün durumlar birer kez kullanılırsa tekrarsız yalnız 3 geçiş yapılabilir; oysa dizgide 4 ya da daha fazla sembol, yani o kadar geçiş vardır. Bu yüzden durumlardan en az biri birden fazla kez ziyaret edilmek zorundadır. Burada güvercinler bütün geçişler (her sembol bir geçiştir), yuvalar ise tekrar etmeyen geçişlerdir.

Slayttaki örnekte durumları $q_1, q_2, q_3, q_4$ olan ($q_4$ kabul durumu) bir DFA'da $aaaab$ dizgisinin yürüyüşü (walk) şöyledir (ekrandan, 00:05:00):

```text
q1 --a--> q2 --a--> q3 --a--> q2 --a--> q3 --b--> q4
```

Bu yürüyüşte $q_2$ (ve ardından $q_3$) tekrar eder.

## 3. Pompalama Önsavı

Önsav yalnız **sonsuz** diller için anlamlıdır. Dil sonluysa, örneğin içinde 500 kelime varsa, bu 500 kelimeyi kabul eden bir DFA ya da NFA hemen yazılır. Yani **sonlu bütün diller düzenlidir**. Düzensiz olabilecek diller sonsuz dillerdir.

Sonsuz bir $L$ dilinin düzenli olduğunu, yani onu kabul eden $p$ durumlu bir DFA bulunduğunu varsayalım. Uzunluğu $p$'den büyük bir $w$ dizgisinin yürüyüşünde bir döngü vardır, yani en az bir durum tekrar eder. İlk tekrar eden durum $q$ olsun. $w$ üç parçaya ayrılır (ekrandan, 00:10:00):

- $x$: döngüden önceki kısım, yani başlangıçtan $q$'ya ilk varışa kadar okunan semboller.
- $y$: ilk döngüde okunan semboller. Birden fazla döngü olabilir; $y$ ilk döngüdür.
- $z$: döngüden sonraki kısım. $z$'nin biçimi bizi ilgilendirmez; içinde geri dönüşler ve başka döngüler olabilir.

Bu bölmenin iki özelliği vardır:

- $|xy| \le p$: $q$'ya ikinci kez varılana kadar $q$ dışında hiçbir durum tekrar etmemiştir. Bu yüzden $xy$ okunurken en fazla $p$ sembol okunur.
- $|y| \ge 1$: döngüde en az bir geçiş, dolayısıyla $y$'de en az bir sembol vardır.

Şimdi döngünün kaç kez dönüldüğüne bakalım. $y$ tamamen çıkarılırsa ($xz$) otomat yine kabul durumuna varır. $y$ iki kez dönülürse ($xyyz$), üç kez dönülürse ya da on binlerce kez dönülürse de kabul eder. Yani $y$'nin kaç kez tekrarlandığı fark etmez: her $i = 0, 1, 2, \dots$ için $x y^i z \in L$ olur.

Bu gözlemler önsavı verir:

> **Pompalama önsavı:** $L$ sonsuz bir düzenli dilse, öyle bir $p$ tam sayısı (kritik uzunluk, critical length) vardır ki $|w| \ge p$ olan her $w \in L$ dizgisi $w = xyz$ biçiminde, $|xy| \le p$ ve $|y| \ge 1$ olacak şekilde yazılabilir ve her $i = 0, 1, 2, \dots$ için $x y^i z \in L$ olur.

## 4. Önsavla Düzensizlik İspatının Adımları

Sonsuz bir dilin düzensiz olduğunu ispatlamak için **olmayana ergi** (contradiction) yöntemi kullanılır:

- Önce tersi varsayılır: $L$ düzenlidir. O hâlde önsav $L$ için geçerli olmalıdır.
- Sonra önsavın $L$ için geçerli olup olmadığına bakılır ve geçerli olmadığı gösterilir.
- Önsav geçerli değilse çelişkiye varılmıştır; demek ki $L$ düzenli değildir.

Çelişkiye ulaşmanın adımları slaytta şöyle verildi (ekrandan, 00:15:00):

1. $p$, $L$ için kritik uzunluk olsun.
2. $w \in L$ olan ve $|w| \ge p$ uzunluk koşulunu sağlayan belirli bir dizgi seçilir.
3. $w = xyz$ yazılır.
4. Bazı $i \ne 1$ için $w' = x y^i z \notin L$ olduğu gösterilir.
5. Bu bir çelişkidir, çünkü önsava göre $w' = x y^i z \in L$ olmalıydı.

$i = 1$ dizginin kendisidir, o zaten dildedir. $i$ sıfır, iki, üç, beş gibi başka bir değer olabilir.

> **Hocanın vurgusu:** $p$'ye sayı verilmez. Sınavlarda ve uygulamalarda öğrencilerin en sık yaptığı hata "$p$'yi 5 aldım hocam, 5 durum var, bakın olmuyor" demektir. Bu kabul edilmez; ispat genel $p$ için yapılmalıdır.

Seçilen dizgi genelde $p$'yi içerir; $p$ çoğunlukla sembollerin üslerinde yer alır. Ayrıca çelişki için **tek bir dizgi yeterlidir**: bir $w \in L$ için çelişki göstermek yeter, her $w \in L$ için göstermek gerekmez.

## 5. Örnek: $a^n b^n$

> **Teorem:** $L = \{a^n b^n : n \ge 0\}$ dili düzenli değildir (ekrandan, 00:30:00).

Bu dil $ab$, $aabb$, $aaabbb$ gibi, $a$ sayısı ile $b$ sayısı eşit olan dizgilerden oluşur.

**İspat.** Çelişki için $L$'nin düzenli olduğunu varsayalım. $n$ sıfırdan sonsuza gidebildiği için $L$ sonsuzdur; pompalama önsavı uygulanabilir (ekrandan, 00:20:00).

$p$ kritik uzunluk olsun. $w \in L$ ve $|w| \ge p$ olan bir dizgi seçmeliyiz. $p$'yi içeren bir seçim:

$$w = a^p b^p, \qquad |w| = 2p \ge p.$$

Önsava göre $w = xyz$ yazılabilir; $|xy| \le p$ ve $|y| \ge 1$ (ekrandan, 00:25:00):

```text
w = a...aa...aa...ab...b
    |_x_||_y_||____z____|
    <------ p ------><-p->
```

Seçilen dizgi $a^p$ ile başladığından ve $|xy| \le p$ olduğundan, $x$ ve $y$ içinde hiç $b$ olamaz. $|y| \ge 1$ olduğundan $y$ en az bir $a$ içerir. Dolayısıyla

$$y = a^k, \qquad 1 \le k \le p.$$

En küçük durumda $y$ tek bir $a$'dır ($k = 1$). En büyük durumda $k = p$ olur: bu durumda $x$ boştur, yani döngü okumaya başlar başlamaz başlar ve $xy$ yalnız $y$'den oluşur. $z$, $y$'nin boyuna göre birkaç $a$ içerebilir ya da hiç içermeyebilir, ama bütün $b$'ler $z$'dedir. $|xy| \le p$ koşulu yüzünden başka bir bölme yolu yoktur; bu koşul pompalama önsavında işimizi çok kolaylaştırır.

Şimdi $i = 2$ alalım (yukarı pompalama). Bir $y$ daha eklemek $k$ tane yeni $a$ eklemek demektir; $b$ sayısı $p$ olarak kalır:

$$x y^2 z = a^{p+k} b^p.$$

Önsava göre bu dizgi $L$'de olmalıdır. Ama $L$'de olmak için $a$ sayısı ile $b$ sayısı eşit olmalıdır; $k \ge 1$ olduğundan $p + k \ne p$, yani $a^{p+k} b^p \notin L$. Bu aradığımız çelişkidir. Demek ki $L$'nin düzenli olduğu varsayımı yanlıştır; **$L$ düzenli değildir.**

**Soru:** Bu kısmı kısaca Türkçe de anlatır mısınız? **Cevap:** Hoca ispatı Türkçe tekrar etti: $w = a^p b^p$ seçilir, uzunluğu $2p$ olduğu için işe yarar. Bölerken iki koşul göz önünde tutulur: $y$'de en az bir karakter olmalıdır ve $x$ ile $y$'nin toplam boyu $p$'yi geçmemelidir. Bu yüzden $x$ ve $y$ yalnız $a$'lardan oluşur, $b$'lerin hepsi $z$'de kalır. $y$ biraz artırılınca $a$'ların sayısı artar ama $b$'lerin sayısı artmaz; sayılar farklılaşır ve dizgi dilden çıkar. $i$'yi sıfır yapıp aşağı da pompalayabiliriz (pump down), iki, üç, dört yapıp yukarı da pompalayabiliriz (pump up); burada en basiti 2'dir.

> **Ders sonrası not:** Hoca Türkçe tekrarda bir yerde "$X$ ve $Y$'nin boyutu en azından $P$ olmalı" dedi (00:30:41); doğrusu "en fazla $p$" ($|xy| \le p$). Hemen ardından "en fazla buraya kadar gelir" diyerek doğru biçimi kullandı. Yine aynı yerde "$B$'lerin sayısı artacak" ifadesi geçiyor; anlam gereği doğrusu "artmayacak"tır.

> **Hocanın vurgusu:** Pompalama önsavı sınavlarda bir şekilde çıkar. Birkaç dil bulup düzensiz olduklarını kendiniz pompalama önsavıyla ispatlayın.

## 6. Örnek: $v v^R$

> **Teorem:** $L = \{v v^R : v \in \Sigma^*\}$ dili düzenli değildir.

Bu dil bir dizgi ile onun tersinin birleştirilmesinden oluşur ($abba$, $aabbaa$ gibi).

**İspat.** Çelişki için $L$'nin düzenli olduğunu varsayalım. $L$ sonsuz olduğundan önsav geçerli olmalıdır. $p$ kritik uzunluk olsun. Farklı dizgiler seçilebilir; burada şu seçilir (ekrandan, 00:50:00):

$$w = a^p b^p b^p a^p, \qquad |w| = 4p \ge p.$$

$|xy| \le p$ olduğundan $x$ ve $y$ yalnız ilk $a^p$ bölümünde olabilir. Önceki örnekteki gibi

$$y = a^k, \qquad 1 \le k \le p.$$

$k = p$ ise ilk $a$'ların hepsi $y$'dir ve $x$ boş dizgidir. Geri kalan her şey, yani $b^p b^p a^p$ kesinlikle $z$'dedir. Bu koşul yüzünden başka bir bölme yolu yoktur.

$i = 2$ alınınca $k$ tane $a$ daha eklenir:

$$x y^2 z = a^{p+k} b^p b^p a^p.$$

Dilde olmak için baştaki semboller ile sondaki semboller birbirinin aynası olmalıdır; burada baştaki $a$ sayısı $p + k$, sondaki $a$ sayısı $p$'dir. Dizgi dilde değildir, çelişki elde edilir. **$L$ düzenli değildir.**

**Soru:** Pompalama önsavıyla bir dilin düzenli olduğunu nasıl kanıtlarız? **Cevap:** Düzenli olduğu pompalama önsavıyla kanıtlanmaz. Düzenlilik üç yolla kanıtlanır: dil için bir DFA, bir NFA ya da bir düzenli ifade yazılır. Bunlardan biri yazılabiliyorsa dil düzenlidir. Pompalama önsavı, bir dilin düzenli olmadığını ispatlamak istendiğinde kullanılır.

## 7. Örnek: $a^n b^l c^{n+l}$

> **Teorem:** $L = \{a^n b^l c^{n+l} : n, l \ge 0\}$ dili düzenli değildir.

Bu dilde $c$ sayısı, $a$ sayısı ile $b$ sayısının toplamına eşittir.

**İspat.** Çelişki için $L$'nin düzenli olduğunu varsayalım. $L$ sonsuzdur, önsav uygulanır. $p$ kritik uzunluk olsun ve şu dizgi seçilsin:

$$w = a^p b^p c^{2p}, \qquad |w| = 4p \ge p.$$

$|xy| \le p$ koşulu yine çok işe yarar: $xy$ yalnız ilk bölümde, $a$'ların içinde kalır; $xy$'de hiç $b$ ya da $c$ yoktur. Yani

$$y = a^k, \qquad 1 \le k \le p.$$

$k$'nın en küçük değeri $|y| \ge 1$ koşulundan 1'dir; en büyük değeri $x$ boş verildiğinde $p$'dir.

Bu kez **aşağı pompalama** (pumping down) yapılır, yani $y$'lerin sayısı azaltılır: $i = 0$. Önsava göre $xz$ dilde olmalıdır. $y$ çıkarılınca dizgiden $k$ tane $a$ çıkar (ekrandan, 01:00:00):

```text
xz = a...aa...ab...bc...cc...c
     <-p-k-><-p-><---2p--->
     |_x_||________z________|
```

$$xz = a^{p-k} b^p c^{2p}.$$

Dilde olmak için $a$ sayısı ile $b$ sayısının toplamı $c$ sayısına eşit olmalıdır. Burada $(p - k) + p = 2p - k \ne 2p$, çünkü $k \ge 1$. Dolayısıyla $a^{p-k} b^p c^{2p} \notin L$; bu bir çelişkidir. **$L$ düzenli değildir.**

Hoca, buraya kadarki üç örneğin birbirine çok benzediğine dikkat çekti: üçünde de $|xy| \le p$ koşulu sayesinde $y = a^k$ çıkar ve tek bir bölme yolu kalır.

## 8. Örnek: $a^{n!}$

> **Teorem:** $L = \{a^{n!} : n \ge 0\}$ dili düzenli değildir.

Bu dilde yalnız $a$ sembolü vardır ve $a$ sayısı bir faktöriyeldir; $n! = 1 \cdot 2 \cdots (n-1) \cdot n$.

**İspat.** Çelişki için $L$'nin düzenli olduğunu varsayalım. $L$ sonsuzdur, önsav uygulanır. $p$ kritik uzunluk olsun. Faktöriyel çok hızlı büyüdüğü için yeterince büyük her $p$ için $p! \ge p$ olur; bu yüzden şu dizgi seçilebilir:

$$w = a^{p!}.$$

$|xy| \le p$ koşulu yine yardım eder: $y = a^k$, $1 \le k \le p$.

$i = 2$ alınınca $k$ tane yeni $a$ gelir ve $a$ sayısı $p! + k$ olur (ekrandan, 01:05:00):

$$x y^2 z = a^{p!+k} \in L \text{ olmalı}, \qquad 1 \le k \le p.$$

$L = \{a^{n!}\}$ olduğundan, bu dizginin dilde olması için $p! + k = z!$ olacak bir $z$ bulunmalıdır. Bu mümkün değildir, çünkü $k$ en fazla $p$ olabilir ve $p > 1$ için

$$p! + k \;\le\; p! + p \;\le\; p! + p! \;<\; p!\,p + p! \;=\; p!(p+1) \;=\; (p+1)!$$

olur. Yani $p! < p! + k < (p+1)!$: $p! + k$ bir sonraki faktöriyele bile ulaşamaz ve iki ardışık faktöriyelin arasında kaldığı için hiçbir $z$ için $p! + k = z!$ olamaz. $a^{p!+k} \notin L$, çelişki. **$L$ düzenli değildir.**

**Soru:** Buradaki eşitsizlik geçişi ($p! + p! < p!\,p + p!$) nasıl yapıldı? **Cevap:** Bir öğrenci $p \ge 2$ iken $p!$'ın $p$ ile çarpılınca daha büyük olacağını söyledi; hoca da amacın sağ tarafta $p!$ parantezine alıp $(p+1)!$'e ulaşmak olduğunu açıkladı: $p!\,p + p! = p!(p + 1) = (p+1)!$. Böylece $p! + k < (p+1)!$ gösterilmiş olur.

Hoca sayısal bir örnek verdi: $p = 5$ olsun. $5! = 120$'dir. $k$ en fazla 5 olabildiği için en fazla $120 + 5 = 125$'e çıkılır. Bir sonraki faktöriyel $6! = 120 \cdot 6 = 720$'dir. Biri 125'te kalırken öbürü 720'ye sıçrar; $p! + k$ bir faktöriyel olamaz.

> **Hocanın vurgusu:** Pompalama önsavı önemlidir, sınavlarda sorulur. Tipik soru şöyledir: bir dil verilir, düzenli mi değil mi söylenmesi istenir. Düzenli deniyorsa ilgili NFA, DFA ya da düzenli ifade yazılarak gösterilmelidir; düzenli değil deniyorsa pompalama önsavıyla ispatlanmalıdır. Kitapta örnekler vardır; pompalama önsavını kendiniz uygulamayı öğrenin.

## 9. Bağlamdan Bağımsız Diller

Dersin ikinci yarısında yeni bir dil ailesine geçildi: **bağlamdan bağımsız diller** (context-free languages). Düzenli diller, bağlamdan bağımsız dillerin bir alt kümesidir; bağlamdan bağımsız diller düzenli dillerin bir üst kümesidir.

Düzenli dillerde DFA, NFA ve düzenli ifadeler olduğu gibi, bağlamdan bağımsız dillerin de iki tarif biçimi vardır:

- **Yığıtlı otomatlar** (pushdown automata): bağlamdan bağımsız dilleri kabul eder; NFA ve DFA'ların karşılığıdır. Sonraki derslerde işlenecek.
- **Bağlamdan bağımsız gramerler** (context-free grammars): dilin dizgilerini türetir, üretir; düzenli ifadelerin karşılığıdır. Bu derste işlendi.

## 10. Gramer Kavramı ve İlk Örnekler

### 10.1 İngilizce gramer örneği

Gramerler dilleri ifade eder. Hoca örnek olarak küçük bir İngilizce grameri verdi (ekrandan, 01:25:00):

$$\langle sentence \rangle \to \langle noun\_phrase \rangle\ \langle predicate \rangle$$
$$\langle noun\_phrase \rangle \to \langle article \rangle\ \langle noun \rangle$$
$$\langle predicate \rangle \to \langle verb \rangle$$
$$\langle article \rangle \to a, \qquad \langle article \rangle \to the$$
$$\langle noun \rangle \to cat, \qquad \langle noun \rangle \to dog$$
$$\langle verb \rangle \to runs, \qquad \langle verb \rangle \to sleeps$$

Bir cümle, bir isim öbeği (noun phrase) ile onu izleyen bir yüklemden (predicate) oluşur. İsim öbeği bir tanımlık (article) ve bir isimdir; yüklem bir fiildir.

Bu gramerle "the dog sleeps" şöyle türetilir:

$$\langle sentence \rangle \Rightarrow \langle noun\_phrase \rangle \langle predicate \rangle \Rightarrow \langle noun\_phrase \rangle \langle verb \rangle \Rightarrow \langle article \rangle \langle noun \rangle \langle verb \rangle$$
$$\Rightarrow the\ \langle noun \rangle \langle verb \rangle \Rightarrow the\ dog\ \langle verb \rangle \Rightarrow the\ dog\ sleeps$$

"the" tanımlıktan, "dog" isimden, "sleeps" fiilden gelir. Benzer şekilde "a cat runs" da türetilir. Bu gramerin türetebildiği bütün cümleler listelenirse bir dizgi kümesi elde edilir; bu küme **gramerin dilidir**. Burada dil sonludur: 2 tanımlık, 2 isim ve 2 fiil olduğu için $2 \cdot 2 \cdot 2 = 8$ cümle vardır ("a cat runs", "a cat sleeps", "the cat runs", "the cat sleeps" ve "dog" ile kurulan dört cümle).

### 10.2 Üretim kuralları

Her kural ya da **üretim** (production) bir okla gösterilir. Okun solunda bir **değişken** (variable) bulunur; örneğin $\langle noun \rangle$ ve $\langle sentence \rangle$ değişkendir. Sağda bir dizi **uç sembol** (terminal) bulunabilir; örneğin $cat$'teki $c$, $a$, $t$ uç semboldür. Uç sembol, değişken olmayan semboldür; küçük $a$ okun soluna yazılamaz. Sağ tarafta değişkenler de olabilir ($\langle sentence \rangle$'in sağ tarafı bir değişken dizisidir) ve değişkenlerle uç semboller karışık da kullanılabilir. Sağ taraf boş dizgi $\varepsilon$ da olabilir.

Hoca Türkçe özetinde "terminal" için "soncul" sembol karşılığını önerdi.

### 10.3 $S \to aSb \mid \varepsilon$

Tek değişkenli bir gramer (ekrandan, 01:30:00):

$$S \to aSb, \qquad S \to \varepsilon$$

Burada $S$ değişken, $a$ ve $b$ uç semboldür. Türetmeye her zaman en üstte, solda yazan değişkenden, yani **başlangıç değişkeninden** başlanır.

$ab$ dizgisinin türetilmesi: önce ilk kural, sonra ikinci kural uygulanır:

$$S \Rightarrow aSb \Rightarrow ab.$$

$aabb$ dizgisinin türetilmesi: ilk kural iki kez uygulanır, sonra $S$'den kurtulmak için ikinci kural kullanılır:

$$S \Rightarrow aSb \Rightarrow aaSbb \Rightarrow aabb.$$

Aynı yolla $aaabbb$, $aaaabbbb$ da türetilir. Bu gramer $n$ tane $a$ ve onu izleyen $n$ tane $b$ üretir:

$$L(G) = \{a^n b^n : n \ge 0\}.$$

$n = 0$ durumu, hemen ikinci kural uygulanınca elde edilen boş dizgidir. Dersin ilk yarısında bu dilin düzenli olmadığı ispatlanmıştı; demek ki gramerler düzenli dillerden daha güçlüdür.

## 11. Biçimsel Tanım ve Bir Gramerin Dili

### 11.1 Türetme gösterimi

$S \overset{*}{\Rightarrow} aaabbb$ gösterimi, $S$'nin sıfır ya da daha fazla türetme adımıyla bu dizgiyi ürettiği anlamına gelir; ara adımları tek tek yazmak yerine kullanılır. Genel olarak, kurallar uygulanarak $w_1$'den başlanıp $w_n$'ye ulaşılabiliyorsa

$$w_1 \overset{*}{\Rightarrow} w_n$$

yazılır ("$w_1$, $w_n$'yi üretir"). Önemsiz olarak $w \overset{*}{\Rightarrow} w$ her zaman doğrudur. Örnek gramer için $S \overset{*}{\Rightarrow} \varepsilon$, $S \overset{*}{\Rightarrow} ab$, $S \overset{*}{\Rightarrow} aaabbb$ yazılabilir; üretilen şeyin son dizgi olması da gerekmez, $S \overset{*}{\Rightarrow} aaSbb$ gibi değişken içeren bir dizgi de olabilir.

Aynı değişkenin kuralları "veya" çizgisiyle birlikte yazılabilir: $S \to aSb \mid \varepsilon$, "$S$, $aSb$ ya da $\varepsilon$ üretir" demektir. Bu yalnız kullanışlı bir kısaltmadır.

### 11.2 Gramerin dörtlü tanımı

Bir gramer dört bileşenden oluşur (ekrandan, 01:35:00):

$$G = (V, T, S, P)$$

- $V$: değişkenler kümesi.
- $T$: uç semboller kümesi.
- $S$: başlangıç değişkeni.
- $P$: üretimler kümesi.

**Bağlamdan bağımsız gramerde** $P$'deki bütün üretimler $A \to s$ biçimindedir: $A$ bir değişken, $s$ değişkenlerden ve uç sembollerden oluşan bir dizgidir.

$S \to aSb \mid \varepsilon$ grameri için: $V = \{S\}$, $T = \{a, b\}$, başlangıç değişkeni $S$, $P = \{S \to aSb,\ S \to \varepsilon\}$.

**Soru:** Boş dizgi uç semboller kümesinde mi? $S$ boş dizgi üretebiliyordu. **Cevap:** Hoca önce emin olmadığını söyledi; hemen sonraki slayttaki örnekte $T = \{a, b\}$ yazıyordu ve hoca buradan boş dizginin uç semboller kümesinde olmadığını gösterdi.

> **Ek bilgi (derste anlatılmadı):** $\varepsilon$ bir sembol değil, uzunluğu sıfır olan dizgidir. Bu yüzden $T$ alfabesinin elemanı sayılmaz; $S \to \varepsilon$ kuralı yalnız sağ tarafın boş dizgi olduğunu söyler.

### 11.3 Bir gramerin dili

Başlangıç değişkeni $S$ olan bir $G$ grameri için

$$L(G) = \{w : S \overset{*}{\Rightarrow} w,\ w \in T^*\}.$$

$w \in T^*$ koşulu, $w$'de hiç değişken kalmaması, yalnız uç sembollerden oluşması demektir. Bütün değişkenlerden kurtulunarak elde edilebilen dizgilerin kümesi o gramerin dilidir. Örnek gramer için her $n \ge 0$ için $a^n b^n$ türetilebildiğinden $L(G) = \{a^n b^n : n \ge 0\}$.

**Bağlamdan bağımsız dil**, kendisi için bağlamdan bağımsız bir gramer bulunan dildir: $L = L(G)$ olacak bir bağlamdan bağımsız $G$ grameri varsa $L$ bağlamdan bağımsızdır. $\{a^n b^n\}$ dili, onu üreten $G$ grameri olduğu için bağlamdan bağımsızdır.

## 12. Diğer Gramer Örnekleri

### 12.1 $S \to aSa \mid bSb \mid \varepsilon$

Yine tek değişken ve üç kural vardır (ekrandan, 01:40:00). Örnek türetmeler:

$$S \Rightarrow aSa \Rightarrow abSba \Rightarrow abba$$
$$S \Rightarrow aSa \Rightarrow abSba \Rightarrow abaSaba \Rightarrow abaaba$$

Dizginin ikinci yarısı ilk yarısının tersidir. Bu gramerin dili

$$L(G) = \{w w^R : w \in \{a, b\}^*\}$$

yani **çift uzunluklu palindromlardır**.

### 12.2 $S \to aSb \mid SS \mid \varepsilon$

Örnek türetmeler (ekrandan, 01:45:00):

$$S \Rightarrow SS \Rightarrow aSbS \Rightarrow abS \Rightarrow ab$$
$$S \Rightarrow SS \Rightarrow aSbS \Rightarrow abS \Rightarrow abaSb \Rightarrow abab$$

Bu gramerin dili:

$$L(G) = \{w : n_a(w) = n_b(w) \text{ ve her } v \text{ öneki için } n_a(v) \ge n_b(v)\}.$$

$n_a$ $a$ sayısını, $n_b$ $b$ sayısını gösterir. Dizgide $a$ ve $b$ sayıları eşittir ve herhangi bir önekte $a$ sayısı $b$ sayısından az değildir. Bu dil aslında **eşleşen parantezleri** tarif eder: $a$ yerine sol parantez "(", $b$ yerine sağ parantez ")" düşünülürse $()\ ((()))\ (())$ gibi dizgiler üretilir. Hoca bu örnekle gramerlerin çok güçlü olduğunu, düzenli dillerden daha güçlü olduğunu vurguladı.

### 12.3 Türkçe özet

Hoca bu bölümü Türkçe şöyle özetledi: Gramerde değişkenler solda yer alır, sağa o değişkenin ne ürettiği yazılır; değişkenler başka değişkenler ya da uç (soncul) semboller üretebilir. Üretim kuralları istenildiği kadar, sınırsız sayıda kullanılabildiği için sonsuz uzunlukta dizgiler üretilebilir. Düzenli dillerle üretilemeyen bazı diller de bu gramerlerle üretilir; bu dillere bağlamdan bağımsız diller, gramerlere bağlamdan bağımsız gramerler denir.

## 13. Türetme Sırası

Şu gramer ele alındı; beş kuralı vardır (ekrandan, 02:00:00):

| No | Kural |
|---|---|
| 1 | $S \to AB$ |
| 2 | $A \to aaA$ |
| 3 | $A \to \varepsilon$ |
| 4 | $B \to Bb$ |
| 5 | $B \to \varepsilon$ |

### 13.1 En soldan türetme

**En soldan türetmede** (leftmost derivation) her adımda en soldaki değişken değiştirilir. $aab$ dizgisi için: $S$'nin tek kuralı vardır, $AB$ yazılır. Şimdi $A$ ya da $B$ değiştirilebilir; en soldan türetmede en soldaki değişken $A$ seçilmelidir. $A$ yerine $aaA$ yazılır, sonra bu $A$ boş dizgiyle silinir. Ardından $B$ ile çalışılır: $B$ yerine $Bb$ yazılır ve $B$ silinir.

$$S \overset{1}{\Rightarrow} AB \overset{2}{\Rightarrow} aaAB \overset{3}{\Rightarrow} aaB \overset{4}{\Rightarrow} aaBb \overset{5}{\Rightarrow} aab$$

### 13.2 En sağdan türetme

**En sağdan türetmede** (rightmost derivation) her adımda en sağdaki değişken değiştirilir. $S$'den $AB$ elde edilir; önce $B$, sonra yeni çıkan $B$ işlenir, en son $A$'ya geçilir:

$$S \overset{1}{\Rightarrow} AB \overset{4}{\Rightarrow} ABb \overset{5}{\Rightarrow} Ab \overset{2}{\Rightarrow} aaAb \overset{3}{\Rightarrow} aab$$

Yani $aab$'yi elde etmenin en az iki yolu vardır; başka türetme sıraları da olabilir.

## 14. Türetme Ağaçları

Aynı gramer, $A$ ve $B$ kuralları "veya" ile birleştirilerek yazıldı: $S \to AB$, $A \to aaA \mid \varepsilon$, $B \to Bb \mid \varepsilon$. Türetme adım adım bir ağaç olarak çizilebilir. $S \Rightarrow AB$ adımında $S$'nin iki dalı olur: $A$ ve $B$. $A \to aaA$ uygulanınca $A$'nın altına $a$, $a$, $A$ gelir ve ağacın yaprakları $aaAB$ verir. Sonra $B \to Bb$ uygulanınca yapraklar $aaABb$ olur. Hoca bu sıranın ne en soldan ne en sağdan olduğunu, herhangi bir türetme olduğunu belirtti, çünkü $A$ ile devam edilmedi. Son iki adımda $A$ ve $B$ boş dizgiyle silinir ve ağacın yaprakları $aab$ verir.

Bu ağaca **türetme ağacı** (derivation tree) ya da **ayrıştırma ağacı** (parse tree) denir. $aab$ için son ağaç şöyledir (ekrandan, 02:05:00):

```text
S
├── A
│   ├── a
│   ├── a
│   └── A
│       └── ε
└── B
    ├── B
    │   └── ε
    └── b
```

Yaprakları soldan sağa okuyunca $a\,a\,\varepsilon\,\varepsilon\,b = aab$ elde edilir.

Bazen türetme sırası ağaç açısından önemli değildir: bu örnekte en soldan ve en sağdan türetmeler **aynı türetme ağacını** verir. Ama bazen farklı ağaçlar çıkar; buna **belirsizlik** (ambiguity) denir.

## 15. Belirsizlik

### 15.1 İfade grameri örneği

Toplama, çarpma ve gruplama (parantez) içeren matematiksel ifadeler için tek değişkenli ($E$) ve tek uç sembollü ($a$) bir gramer ele alındı:

$$E \to E + E \mid E * E \mid (E) \mid a$$

<!-- BELİRSİZ: Gramerin slaytı (02:05:50 civarı) karelerde yok; kurallar altyazıdaki "toplama, çarpma, gruplama ve tek sembol a" anlatımından ve 02:10:00 karesindeki ağaçlardan kuruldu. -->

$a$ burada 2, 3, 4 gibi herhangi bir sayı olabilir. $a + a * a$ dizgisinin bir en soldan türetmesi şöyledir: $E$ önce $E + E$ olur, soldaki $E$ yerine $a$ yazılır, sağdaki $E$ yerine $E * E$ yazılır, sonra iki $E$ de $a$ olur:

$$E \Rightarrow E + E \Rightarrow a + E \Rightarrow a + E * E \Rightarrow a + a * E \Rightarrow a + a * a$$

Bir başka en soldan türetme ise $E + E$ ile değil $E * E$ ile başlar:

$$E \Rightarrow E * E \Rightarrow E + E * E \Rightarrow a + E * E \Rightarrow a + a * E \Rightarrow a + a * a$$

İki türetmenin ağaçları farklıdır. İlkinde kökteki işlem toplamadır, ikincisinde çarpmadır. $a = 2$ alınıp ağaç aşağıdan yukarı hesaplanırsa (ekrandan, 02:10:00):

- **İyi ağaç:** kökte $E + E$; sol çocuk 2, sağ çocuk $2 * 2 = 4$; sonuç $2 + 4 = 6$. Okulda öğrendiğimiz işlem önceliğine uyan değer budur.
- **Kötü ağaç:** kökte $E * E$; sol çocuk $2 + 2 = 4$, sağ çocuk 2; sonuç $4 \cdot 2 = 8$.

### 15.2 Belirsizlik neden sorundur

İki farklı türetme ağacı, türetme ağaçlarını kullanan uygulamalarda sorun çıkarır:

- **İfade değerlendirme:** yukarıdaki ifadenin değeri 6 mı, 8 mi?
- **Derleyiciler:** C, C++, Python, Java gibi dillerin derleyicileri kodu bu tür gramerlerle ayrıştırır ve elde edilen ağaca göre koda anlam verir. Kod belirsizse derleyici ne yapacağını bilemez.

**Tanım:** Bir $G$ grameri, $L(G)$'de iki farklı türetme ağacı (ya da iki farklı en soldan türetme) olan bir $w$ dizgisi varsa **belirsizdir** (ambiguous). Önceki ifade grameri belirsizdir.

### 15.3 if-then-else örneği

Programlama dillerinde çok yaygın bir gramer parçası:

$$\langle stmt \rangle \to if\ \langle expr \rangle\ then\ \langle stmt \rangle$$
$$\langle stmt \rangle \to if\ \langle expr \rangle\ then\ \langle stmt \rangle\ else\ \langle stmt \rangle$$

Burada $\langle stmt \rangle$ ve $\langle expr \rangle$ değişken; $if$, $then$, $else$ uç semboldür. Şu dizgi ele alınsın:

```text
if expr1 then if expr2 then stmt1 else stmt2
```

Bu dizginin iki türetme ağacı vardır (ekrandan, 02:15:00):

```text
Ağaç 1 (önce kural 1, içte kural 2; else içteki if'e bağlı):
STMT
├── if  expr1  then
└── STMT
    └── if  expr2  then  stmt1  else  stmt2

Ağaç 2 (önce kural 2, içte kural 1; else dıştaki if'e bağlı):
STMT
├── if  expr1  then
├── STMT
│   └── if  expr2  then  stmt1
└── else  stmt2
```

Slaytta birinci ağaç için "dillerde kullanılan ağaç budur" notu vardı. İki ağaç farklı olduğu için dizgi belirsizdir; derleyici ne yapacağını bilemeyebilir ya da rastgele bir şey yapabilir. Programlama dillerinde bu genelde süslü parantezlerle çözülür: programcı istediği yapıyı parantezlerle belirtir ve dizgi belirsiz olmaktan çıkar. Yani burada belirsizliği gidermek programcının işidir; parantez kullanılmazsa dizginin kendisi belirsizdir.

### 15.4 Belirsizliği gidermek

Genel olarak belirsizlik kötüdür ve giderilmek istenir. Bazen bu mümkündür, bazen değildir.

İfade grameri için belirsiz olmayan denk bir gramer yazılabilir. Bu gramerde üç değişken vardır: $E$, $T$ ve $F$. $E$ bir $T$ ya da bir toplama üretir; $T$ bir $F$ ya da bir çarpma üretir; $F$ bir gruplama ya da uç sembol üretir:

$$E \to E + T \mid T, \qquad T \to T * F \mid F, \qquad F \to (E) \mid a$$

<!-- BELİRSİZ: Bu slayt karelerde yok. Hoca bir yerde "E, T ya da T + E üretir", hemen ardından "E yalnız E + T olur" dedi; kurallar ikinci ifadeye ve standart biçime göre yazıldı. -->

Bu gramerle $a + a * a$ yalnız tek bir en soldan türetmeyle elde edilir, böylece anlam belirsiz olmaz. Başlangıç değişkeni $E$'dir; $T$ ya da $F$ ile başlanamaz. $E$ önce $E + T$'ye bölünür; yani ağacın üst kısmında önce toplamaya göre bölme yapılır. Bölmeden sonra $T$'ler elde edilir ve istenirse bunların altında çarpma oluşturulur; en altta uç semboller gelir.

> **Ders sonrası not:** Hoca burada "toplamanın çarpmaya göre önceliği var" dedi (02:18:33). Kastedilen, ağaçta önce (üstte) toplamaya göre bölündüğüdür; işlem önceliği açısından doğrusu bunun tersidir: çarpma toplamadan önce yapılır, bu yüzden toplama ağacın kökünde, çarpma alt ağaçta yer alır.

### 15.5 Doğası gereği belirsiz dil

Bazı diller için belirsiz olmayan bir gramer bulmak mümkün değildir (ekrandan, 02:20:00):

$$L = \{a^n b^n c^m\} \cup \{a^n b^m c^m\}, \qquad n, m \ge 0$$

Birinci kümede $a$ sayısı ile $b$ sayısı, ikinci kümede $b$ sayısı ile $c$ sayısı eşittir. Bu dil **doğası gereği belirsizdir** (inherently ambiguous): onu üreten her gramer belirsizdir.

Slayttaki (belirsiz) gramer şöyledir:

$$S \to S_1 \mid S_2$$
$$S_1 \to S_1 c \mid A, \qquad A \to aAb \mid \varepsilon$$
$$S_2 \to aS_2 \mid B, \qquad B \to bBc \mid \varepsilon$$

$S_1$ birinci kümeyi, $S_2$ ikinci kümeyi üretir. Üç sayının da eşit olduğu $a^n b^n c^n$ biçimindeki dizgiler her iki kümede de vardır. Bu dizgiler hem $S_1$ yoluyla hem $S_2$ yoluyla türetilebilir; birleşimde sıra yoktur, ve en baştaki $S \to S_1 \mid S_2$ seçimi her zaman iki farklı yol açar. Bu yüzden bu dizgilerin her zaman iki farklı türetmesi vardır.

<!-- BELİRSİZ: Hoca 02:19:49'da birinci kümeyi "a üzeri n, b üzeri n, c üzeri n" diye okudu, ama hemen ardından yalnız a ve b sayılarının eşit olduğunu söyledi; kümeler slayttaki biçimiyle (c üzeri m) yazıldı. -->

Hoca kitapta bu konuda alıştırmalar olabileceğini, onların çözülmesini önerdi.

## Örnek Sorular

**Soru 1** (ekrandan, 00:30:00): $L = \{a^n b^n : n \ge 0\}$ dilinin düzenli olmadığını pompalama önsavıyla ispatlayın.

> **Çözüm:** Düzenli olduğu varsayılır; $p$ kritik uzunluk, $w = a^p b^p$. $|xy| \le p$ olduğundan $y = a^k$, $1 \le k \le p$. $x y^2 z = a^{p+k} b^p \notin L$. Çelişki; $L$ düzenli değildir. (Ayrıntı: Bölüm 5.)

**Soru 2** (ekrandan, 00:50:00): $L = \{v v^R : v \in \Sigma^*\}$ dilinin düzenli olmadığını ispatlayın.

> **Çözüm:** $w = a^p b^p b^p a^p$ seçilir. $y = a^k$, $1 \le k \le p$. $x y^2 z = a^{p+k} b^p b^p a^p \notin L$. Çelişki. (Ayrıntı: Bölüm 6.)

**Soru 3** (ekrandan, 00:55:00): $L = \{a^n b^l c^{n+l} : n, l \ge 0\}$ dilinin düzenli olmadığını ispatlayın.

> **Çözüm:** $w = a^p b^p c^{2p}$ seçilir. $y = a^k$, $1 \le k \le p$. Aşağı pompalama: $xz = a^{p-k} b^p c^{2p}$; $(p-k) + p \ne 2p$ olduğundan $xz \notin L$. Çelişki. (Ayrıntı: Bölüm 7.)

**Soru 4** (ekrandan, 01:05:00): $L = \{a^{n!} : n \ge 0\}$ dilinin düzenli olmadığını ispatlayın.

> **Çözüm:** $w = a^{p!}$ seçilir. $y = a^k$, $1 \le k \le p$. $x y^2 z = a^{p!+k}$; $p > 1$ için $p! < p! + k \le p! + p < (p+1)!$ olduğundan $p! + k$ bir faktöriyel değildir, $a^{p!+k} \notin L$. Çelişki. (Ayrıntı: Bölüm 8.)

**Soru 5** (derste sözlü, 00:54:36): Pompalama önsavıyla bir dilin düzenli olduğu kanıtlanabilir mi?

> **Çözüm:** Hayır. Önsav yalnız düzensizliği ispatlamak için kullanılır. Düzenlilik bir DFA, bir NFA ya da bir düzenli ifade yazılarak gösterilir.

**Soru 6** (ekrandan, 01:40:00): $S \to aSa \mid bSb \mid \varepsilon$ grameri için $L(G)$ nedir?

> **Çözüm:** $L(G) = \{w w^R : w \in \{a, b\}^*\}$, yani çift uzunluklu palindromlar. Örnek: $S \Rightarrow aSa \Rightarrow abSba \Rightarrow abba$.

**Soru 7** (ekrandan, 01:45:00): $S \to aSb \mid SS \mid \varepsilon$ grameri hangi dili üretir?

> **Çözüm:** $L(G) = \{w : n_a(w) = n_b(w)$ ve her $v$ öneki için $n_a(v) \ge n_b(v)\}$; $a = ($, $b = )$ alınırsa eşleşen parantezler.

**Soru 8** (ekrandan, 02:10:00): $E \to E + E \mid E * E \mid (E) \mid a$ gramerinde $a = 2$ için $a + a * a$ ifadesinin iki türetme ağacına göre değeri nedir?

> **Çözüm:** Kökte toplama olan ağaçta $2 + (2 \cdot 2) = 6$; kökte çarpma olan ağaçta $(2 + 2) \cdot 2 = 8$. Aynı dizgi için iki farklı ağaç olduğundan gramer belirsizdir.

## Dersin Toparlaması

Dersin ilk yarısında bir dilin düzenli olmadığını ispatlamanın aracı olan pompalama önsavı işlendi. Önsav, güvercin yuvası ilkesi yüzünden $p$ durumlu bir DFA'da uzun her dizginin yürüyüşünde bir döngü bulunmasına dayanır: $w = xyz$, $|xy| \le p$, $|y| \ge 1$ ve her $i \ge 0$ için $x y^i z \in L$. Düzensizlik ispatı olmayana ergi ile yapılır: dil düzenli varsayılır, genel $p$ için uygun bir $w$ seçilir, $|xy| \le p$ koşulu sayesinde $y = a^k$ bulunur ve yukarı ya da aşağı pompalama ile dilin dışına çıkılır. Bu şablon $a^n b^n$, $v v^R$, $a^n b^l c^{n+l}$ ve $a^{n!}$ dillerine uygulandı.

İkinci yarıda düzenli dillerin üst kümesi olan bağlamdan bağımsız dillere geçildi. Bu diller bağlamdan bağımsız gramerlerle üretilir ve yığıtlı otomatlarla kabul edilir. Gramerin biçimsel tanımı $G = (V, T, S, P)$, gramerin dili, $a^n b^n$, çift uzunluklu palindromlar ve eşleşen parantezler gibi örnekler, en soldan ve en sağdan türetme sırası, türetme (ayrıştırma) ağaçları ve belirsizlik öğrenildi. Belirsizliğin ifade değerlendirmede ve derleyicilerde sorun çıkardığı, bazen denk bir belirsiz olmayan gramerle giderilebildiği, bazı dillerin ise doğası gereği belirsiz olduğu görüldü. Sonraki derslerde yığıtlı otomatlar işlenecek.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
