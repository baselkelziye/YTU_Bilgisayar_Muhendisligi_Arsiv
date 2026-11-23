# Ders 8 Genişletilmiş Notu: Yığıtlı Otomatların Biçimsel Tanımı ve Bağlamdan Bağımsız Gramerlerle Denkliği

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Yığıtlı otomatların tekrarı
- 2. Geçişlerde dizgi itme ve çekme
- 3. PDA'nın biçimsel tanımı
- 4. Anlık tanım, hesaplama ve PDA'nın dili
- 5. PDA ile bağlamdan bağımsız gramerlerin denkliği
- 6. Bağlamdan bağımsız gramerden PDA'ya dönüşüm
- 7. PDA'dan bağlamdan bağımsız gramere dönüşüm
- Örnek Sorular

## 1. Yığıtlı otomatların tekrarı

Ders, bir önceki derste görülen yığıtlı otomatların (pushdown automata, PDA) tekrarıyla başladı. PDA'lar daha önce görülen otomatlara benzer: bir dizi durum (state) ve bir girdi vardır. Fark, otomatın bir de yığıtı (stack) olmasıdır. Yığıt, elemanların tepeden eklendiği (push) ve yine tepeden çıkarıldığı (pop) bir yapıdır. Başlangıçta yığıtın en altında özel bir sembol olduğu varsayılır; derste bu sembol $\$$ ile gösterilir ve yığıtın sonuna gelindiğini bildirir.

### 1.1 Geçişlerin yazılışı

PDA'da bir geçişin üzerine okunan girdi sembolü ile birlikte yığıttan ne çekildiği ve yığıta ne itildiği de yazılır. $a, b \to c$ geçişi şu anlama gelir: girdiden $a$ okunur, yığıtın tepesindeki $b$ çekilir ve yerine $c$ itilir. Yani yığıtta $b$, $c$ ile değiştirilmiş olur. Bir şey çekmek ya da itmek zorunlu değildir:

- Bir şey çekilmeyecekse çekme yerine $\varepsilon$ yazılır.
- Bir şey itilmeyecekse itme yerine $\varepsilon$ yazılır.
- İkisine birden $\varepsilon$ yazılabilir; bu "yığıta dokunma" demektir.

### 1.2 Deterministik olmayış

PDA'lar deterministik değildir (ekrandan, 00:15:00). Slaytta $q_1$'den iki ayrı geçiş vardır: ikisi de $a, b \to c$ etiketlidir, biri $q_2$'ye, öteki $q_3$'e gider. Koşul sağlandığında otomat iki duruma birden, paralel olarak geçer. Bu, deterministik olmayan sonlu otomatlara (NFA) benzer. Ayrıca PDA'lar $\varepsilon$-geçişlerine de izin verir: $q_1 \xrightarrow{\varepsilon, b \to c} q_2$ geçişinde girdiden hiçbir şey okunmadan geçiş yapılır. Bu iki özellik birlikte PDA'yı deterministik olmayan yapar.

### 1.3 Kabul ve red

Bir PDA bir dizgiyi şu iki koşul sağlanınca kabul eder:

- Girdinin tamamı okunmuş olmalıdır.
- Otomat bir kabul durumunda olmalıdır.

Yığıtın içeriği önemli değildir: yığıt tamamen boşalmış olabilir ya da olmayabilir. Örneğin $a^n b^n$ PDA'sında bir $b$ eksik olan girdide son $b$ okunduktan sonra $q_2$'de kalınır; $q_2$ kabul durumu olmadığı için dizgi reddedilir.

Bir PDA'ya bakınca deneyimli biri ne yaptığını kabaca kestirebilir: örneğin bir döngü $a$ gördükçe yığıta $a$ iter, başka bir döngü $b$ gördükçe bu $a$'ları çeker. Tam anlamak için ise birkaç örnek üzerinde çalışmasını izlemek gerekir.

### 1.4 $v v^R$ dilini kabul eden PDA

Slayttaki PDA $L(M) = \{v v^R : v \in \{a,b\}^*\}$ dilini kabul eder (ekrandan, 00:20:00). Geçişleri tablo olarak:

| Kaynak | Hedef | Geçiş |
|---|---|---|
| $q_0$ (başlangıç) | $q_0$ | $a, \varepsilon \to a$ |
| $q_0$ | $q_0$ | $b, \varepsilon \to b$ |
| $q_0$ | $q_1$ | $\varepsilon, \varepsilon \to \varepsilon$ |
| $q_1$ | $q_1$ | $a, a \to \varepsilon$ |
| $q_1$ | $q_1$ | $b, b \to \varepsilon$ |
| $q_1$ | $q_2$ (kabul) | $\varepsilon, \$ \to \$$ |

İlk döngü, $a$ ya da $b$ hangi sembolü okursa onu doğrudan yığıta iter; yani dizginin ilk yarısını okuyup sırayla yığıta koyar. Bu sırada sıra tersine döner, çünkü ilk itilen en son çıkar. İkinci döngü, okunan sembolün aynısını yığıtın tepesinde görmek ister: $a$ okunduysa tepede $a$ olmalı ve çekilmeli, $b$ okunduysa tepede $b$ olmalı ve çekilmelidir. Geçişin olması için hem doğru sembolün okunması hem de yığıtın tepesinde doğru sembolün bulunması gerekir. Böylece ikinci döngü yeni gelen girdiyi daha önce yığıta konan sembollerle eşler; yığıt sırayı çevirdiği için eşleşme tersle yapılır. Sonunda yığıtta yalnız $\$$ kalmışsa yığıt tükenmiş, girdi de tükenmiştir; demek ki girdinin ikinci yarısı ilk yarısının tersiyle eşleşmiştir ve dizgi kabul edilir. Slayttaki red örneğinde ikinci yarıda $a$ gelmesi gereken yerde $b$ geldiği için (dizgi bir palindrom olmadığı için) dizgi reddedilir. <!-- BELİRSİZ: red örneğindeki girdi dizgisi karelerde görülmedi. -->

## 2. Geçişlerde dizgi itme ve çekme

Geçişlerde tek sembol yerine dizgi de yazılabilir: bir dizgi çekilir ve bir dizgi itilir. Örneğin bir geçişte önce $eb$ çekilir, sonra $cdf$ itilir. Bu yalnızca bir kısaltmadır. Arka planda semboller tek tek çekilir ve itilir: önce $e$, sonra $b$ çekilir; ardından önce $f$, sonra $d$, en son $c$ itilir. Böylece $c$ yığıtın tepesinde kalır. Aslında bu tek geçiş beş ayrı geçişe karşılık gelir.

### 2.1 $n_a(w) = n_b(w)$ dilini kabul eden PDA

Slayttaki PDA, $a$ sayısı ile $b$ sayısı eşit olan dizgilerin dilini kabul eder: $L(M) = \{w \in \{a,b\}^* : n_a(w) = n_b(w)\}$ (ekrandan, 00:25:00). Geçişler:

| Kaynak | Hedef | Geçiş |
|---|---|---|
| $q_1$ (başlangıç) | $q_1$ | $a, \$ \to 0\$$ |
| $q_1$ | $q_1$ | $a, 0 \to 00$ |
| $q_1$ | $q_1$ | $a, 1 \to \varepsilon$ |
| $q_1$ | $q_1$ | $b, \$ \to 1\$$ |
| $q_1$ | $q_1$ | $b, 1 \to 11$ |
| $q_1$ | $q_1$ | $b, 0 \to \varepsilon$ |
| $q_1$ | $q_2$ (kabul) | $\varepsilon, \$ \to \$$ |

Burada $0\$$, $00$, $1\$$, $11$ gibi iki sembollük dizgiler yığıta itilir. Bu örnek iki şeyi gösterir: birincisi, dizgi itilip çekilebilir; ikincisi, $a$ okununca yığıta $a$ itmek gerekmez, onun yerine $0$ itilebilir. Burada $0$'lar $a$'yı, $1$'ler $b$'yi temsil eder. Otomat oldukça basittir: son adım dışında hep $q_1$'de kalınır.

Girdi $abbbaa$ için adım adım çalışma (ekrandan, 00:30:00):

- Başlangıç: yığıtta yalnız $\$$ vardır, $q_1$ etkindir. $\varepsilon, \$ \to \$$ geçişiyle hiçbir şey okunmadan $q_2$ de etkin olur; $q_2$ kabul durumu olduğu için boş dizgi kabul edilir.
- $a$ okunur. Üç $a$ geçişinden hangisinin uygulanacağı yığıtın tepesine bağlıdır. Tepe $\$$ olduğu için $a, \$ \to 0\$$ uygulanır; yığıt $0\$$ olur.
- $b$ okunur, tepe $0$'dır: $b, 0 \to \varepsilon$ ile $0$ çekilir; yığıt $\$$ olur. Bir $a$ bir $b$ ile eşleşmiştir.
- $b$ okunur, tepe $\$$'dır: $b, \$ \to 1\$$; yığıt $1\$$ olur.
- $b$ okunur, tepe $1$'dir: $b, 1 \to 11$; yığıt $11\$$ olur. Üç $b$ okunduğu hâlde yığıtta iki $1$ vardır, çünkü ilk $b$ ilk $a$'nın $0$'ı ile eşleşmişti.
- $a$ okunur, tepe $1$'dir: $a, 1 \to \varepsilon$; yığıt $1\$$ olur.
- $a$ okunur, tepe $1$'dir: $a, 1 \to \varepsilon$; yığıt $\$$ olur.
- Girdi bitmiştir ve yığıtta yalnız $\$$ vardır. $\varepsilon$-geçişiyle $q_2$ etkin olur ve dizgi kabul edilir.

## 3. PDA'nın biçimsel tanımı

### 3.1 Geçiş fonksiyonu

Geçiş fonksiyonu $\delta$; o anki durumu ($q_1$), girdiden okunacak sembolü ($a$) ve yığıtta görülmek istenen kısmı ($w_1$) alır. Sonuç, yeni durum ile yığıta itilecek kısımdan oluşan çiftlerin kümesidir:

$$\delta(q_1, a, w_1) = \{(q_2, w_2), (q_3, w_3)\}$$

Sonucun küme olmasının nedeni, aynı kuraldan aynı anda birden fazla duruma gidilebilmesidir. $q_1$'deyken girdiden $a$ okunur ve yığıtın tepesinde $w_1$ varsa makine hem $q_2$'ye geçip $w_2$'yi iter hem de aynı anda $q_3$'e geçip $w_3$'ü iter. Bu NFA'ya çok benzer: tek bir geçiş için bir sonuç durumları kümesi vardır.

### 3.2 Yedili tanım

PDA biçimsel olarak şöyle tanımlanır (ekrandan, 00:35:00):

$$M = (Q, \Sigma, \Gamma, \delta, q_0, z, F)$$

- $Q$: durumlar kümesi.
- $\Sigma$: girdi alfabesi; girdide kullanılabilecek semboller.
- $\Gamma$: yığıt alfabesi; yığıtta kullanılabilecek semboller. Girdi alfabesinden farklı olabilir.
- $\delta$: geçiş fonksiyonu; bir tablo gibi düşünülebilir.
- $q_0$: başlangıç durumu.
- $z$: yığıt başlangıç sembolü (özel sembol).
- $F$: kabul durumları kümesi.

> **Hocanın vurgusu:** Bu biçimsel tanımı ezberlemek gerekmez. Ama PDA kullanan bir program yazılacaksa bu bileşenlerin büyük olasılıkla programın başında bir yerde tanımlanması gerekir.

## 4. Anlık tanım, hesaplama ve PDA'nın dili

### 4.1 Anlık tanım

PDA'yı düşünürken işe yarayan bir araç anlık tanımdır (instantaneous description). Anlık tanım o anı betimleyen bir üçlüdür:

$$(q, u, s)$$

İlk eleman o anki durum, ikinci eleman kalan girdi, üçüncü eleman yığıtın o anki içeriğidir.

Örnek olarak $a^n b^n$ PDA'sı kullanıldı (ekrandan, 00:40:00):

| Kaynak | Hedef | Geçiş |
|---|---|---|
| $q_0$ (başlangıç, kabul) | $q_1$ | $\varepsilon, \varepsilon \to \varepsilon$ |
| $q_1$ | $q_1$ | $a, \varepsilon \to a$ |
| $q_1$ | $q_2$ | $b, a \to \varepsilon$ |
| $q_2$ | $q_2$ | $b, a \to \varepsilon$ |
| $q_2$ | $q_3$ (kabul) | $\varepsilon, \$ \to \$$ |

Girdi $aaabbb$ iken, üç $a$ okunmuş olan anda otomat $q_1$'dedir, kalan girdi $bbb$'dir ve yığıtta $aaa\$$ vardır. Bu an $(q_1, bbb, aaa\$)$ olarak yazılır. Bir sonraki adımda bir $b$ okunup bir $a$ çekilir ve $(q_2, bb, aa\$)$ elde edilir. Her zaman adımı için resim çizmek yerine bu üçlüyü yazmak yeterlidir. İki anlık tanım arasındaki bir adım $\succ$ ile yazılır: $(q_1, bbb, aaa\$) \succ (q_2, bb, aa\$)$.

### 4.2 Hesaplama

Anlık tanımlar art arda yazılarak bütün hesaplama (computation) gösterilebilir (ekrandan, 00:40:00):

$$(q_0, aaabbb, \$) \succ (q_1, aaabbb, \$) \succ (q_1, aabbb, a\$) \succ (q_1, abbb, aa\$) \succ (q_1, bbb, aaa\$) \succ$$
$$(q_2, bb, aa\$) \succ (q_2, b, a\$) \succ (q_2, \varepsilon, \$) \succ (q_3, \varepsilon, \$)$$

Hesaplama $q_3$'te biter. Kalan girdi $\varepsilon$'dur, yani girdinin hepsi tüketilmiştir ve yığıtta yalnız özel sembol vardır. Bu dizi, makinenin bir dalının nasıl çalışabileceğini gösterir.

Çoğu zaman bütün adımları yazmak istenmez; asıl ilgilenilen başlangıç ve bitiş tanımlarıdır. O zaman $\succ$ sembolünün üstüne yıldız konur: $(q_0, aaabbb, \$) \overset{*}{\succ} (q_3, \varepsilon, \$)$. Bu, aradaki bütün hesaplamanın kısaltmasıdır ("sonuçlanır" diye okunabilir).

### 4.3 PDA'nın dili

Bir $M$ PDA'sının dili, $M$'nin kabul ettiği dildir:

$$L(M) = \{w : (q_0, w, z) \overset{*}{\succ} (q_f, \varepsilon, s),\ q_f \in F\}$$

Yani başlangıç durumundan, girdi $w$ ve yığıtta yalnız $z$ varken başlanır; bir hesaplamadan sonra bir kabul durumu $q_f$'ye varılır ve girdinin tamamı tüketilmiştir (kalan girdi $\varepsilon$). Yığıtta başka şeyler kalabilir ($s$); bununla ilgilenilmez. Önemli olan iki şeydir: kabul durumuna varılmalı ve girdi tüketilmelidir. Bu koşulları sağlayan $w$'lerin kümesi PDA'nın dilidir.

Örnekte $(q_0, aaabbb, \$) \overset{*}{\succ} (q_3, \varepsilon, \$)$ olduğu ve $q_3$ kabul durumu olduğu için $aaabbb \in L(M)$'dir. Aynı sayıda $a$'nın hemen ardından aynı sayıda $b$ geldiğinde hesaplama hep böyle kabul eden bir tanımla biter (ekrandan, 00:45:00):

$$(q_0, a^n b^n, \$) \overset{*}{\succ} (q_3, \varepsilon, \$) \Rightarrow a^n b^n \in L(M)$$

Bu yüzden makinenin dili $L(M) = \{a^n b^n : n \ge 0\}$ olarak yazılır.

## 5. PDA ile bağlamdan bağımsız gramerlerin denkliği

Aradan sonra yeni bir konuya geçildi. Teorem şudur: PDA'ların kabul ettiği dillerin kümesi, bağlamdan bağımsız gramerlerin (context-free grammars) üretebildiği dillerin kümesiyle aynıdır.

İki kümenin eşit olduğunu söyleyen bir teorem iki parçaya bölünerek ispatlanır: önce birinci kümenin ikincinin alt kümesi olduğu, sonra üst kümesi olduğu gösterilir. Burada da aynısı yapılır ve ispat yapıcıdır (by construction):

- Birinci adım: her bağlamdan bağımsız gramer bir PDA'ya dönüştürülür. Bu, gramerlerin dillerinin PDA dillerinin alt kümesi olduğunu gösterir.
- İkinci adım: her PDA bir bağlamdan bağımsız gramere dönüştürülür.

## 6. Bağlamdan bağımsız gramerden PDA'ya dönüşüm

### 6.1 Dönüşüm yöntemi

Yöntem oldukça basittir (ekrandan, 01:00:00). Geçiş grafiği her zaman aynıdır: $q_0$, $q_1$ ve $q_2$ durumları vardır.

| Kaynak | Hedef | Geçiş |
|---|---|---|
| $q_0$ (başlangıç) | $q_1$ | $\varepsilon, \varepsilon \to S$ |
| $q_1$ | $q_1$ | gramerin her $A \to w$ kuralı için $\varepsilon, A \to w$ |
| $q_1$ | $q_1$ | gramerin her uç sembolü $a$ için $a, a \to \varepsilon$ |
| $q_1$ | $q_2$ (kabul) | $\varepsilon, \$ \to \$$ |

$q_0$'dan hiçbir şey okumadan ve yığıta bakmadan başlangıç değişkeni $S$ itilip $q_1$'e geçilir ($S$ gramerlerde başlangıç değişkenidir). Gramerdeki her $A \to w$ kuralı için, girdiden bir şey okumadan $A$ değişkenini çekip $w$'yi iten $\varepsilon, A \to w$ geçişi $q_1$ döngüsüne eklenir. Her uç sembol $a$ için de girdide $a$ görülüp yığıtın tepesinde $a$ varsa onu çeken $a, a \to \varepsilon$ eklenir. $q_1$'den, hiçbir şey okumadan, yığıtta yalnız özel sembol kaldıysa $q_2$'ye geçilir ve $q_2$ kabul durumudur.

### 6.2 Örnek

Gramer (ekrandan, 01:05:00):

$$S \to aSTb, \quad S \to b, \quad T \to Ta, \quad T \to \varepsilon$$

Gramerde $S$ ve $T$ değişkenleri vardır. Dönüşümle elde edilen PDA'nın $q_1$ döngüsündeki geçişler:

- Değişken kuralları: $\varepsilon, S \to aSTb$; $\varepsilon, S \to b$; $\varepsilon, T \to Ta$; $\varepsilon, T \to \varepsilon$.
- Uç semboller: $a, a \to \varepsilon$; $b, b \to \varepsilon$.

Gösterimin doğrudan kurala karşılık geldiğine dikkat edilmelidir: $S \to aSTb$ kuralı "hiçbir şey okumadan $S$'yi çek, $aSTb$'yi it" geçişi olur. Başta yığıtta yalnız $\$$ olduğu için $q_1$'den $q_2$'ye geçiş koşulu ilk anda sağlanmaz, çünkü $q_0$'dan çıkarken $S$ itilmiştir.

### 6.3 PDA en soldan türetmeyi taklit eder

Bu PDA, gramerin en soldan türetmelerini (leftmost derivations) taklit eder (ekrandan, 01:10:00). En soldan türetme $S$ ile başlar. PDA tarafında başlangıç anlık tanımı $(q_0, \sigma_1 \cdots \sigma_n, \$)$'dır: başlangıç durumu, girdinin tamamı ve yığıtta yalnız $\$$. Hiçbir şey okunmadan $S$ itilip $q_1$'e geçilir: $(q_1, \sigma_1 \cdots \sigma_n, S\$)$.

Sonra $q_1$ döngüsündeki geçişler kullanılır. Bir noktada PDA yine $q_1$'dedir; girdinin bir kısmı ($\sigma_1 \cdots \sigma_k$) tüketilmiş, bir kısmı ($\sigma_{k+1} \cdots \sigma_n$) duruyordur ve yığıtta $X_1 \cdots X_m \$$ vardır. Tüketilen kısım ile yığıtın $\$$ dışındaki içeriği yan yana yazılınca türetmenin o adımı elde edilir:

$$S \Rightarrow \cdots \Rightarrow \sigma_1 \cdots \sigma_k X_1 \cdots X_m \quad \leftrightarrow \quad (q_1, \sigma_{k+1} \cdots \sigma_n, X_1 \cdots X_m \$)$$

Sonunda türetme $\sigma_1 \cdots \sigma_n$'ye ulaşır; PDA da $q_2$'de, kalan girdi boş ve yığıtta yalnız $\$$ ile biter: $(q_2, \varepsilon, \$)$.

**Değişken kuralı.** En soldan türetmede o ana kadar bazı uç semboller ($x$), ardından en soldaki değişken $A$, onun ardından değişken ve uç sembollerin karışımı ($y$) vardır: $xAy$. $A \to \sigma_i \cdots \sigma_j B z$ kuralı uygulanırsa ($\sigma$'lar uç semboller, $B$ bir değişken, $z$ karışık bir dizgi) türetme $x \sigma_i \cdots \sigma_j B z y$ olur. PDA tarafında bu adımdan önce anlık tanım $(q_1, \sigma_i \cdots \sigma_n, Ay\$)$'dır. $q_1$'de $\varepsilon, A \to \sigma_i \cdots \sigma_j B z$ geçişi uygulanır: $A$ çekilir, yerine $\sigma_i \cdots \sigma_j B z$ itilir ve anlık tanım $(q_1, \sigma_i \cdots \sigma_n, \sigma_i \cdots \sigma_j B z y \$)$ olur.

**Uç sembol kuralı.** Uç sembol kuralında girdiden tek bir sembol okunur ve yığıttan da aynı sembol çekilir (ekrandan, 01:15:00). Gramer bu adımda bir şey yapmaz, çünkü bunlar uç sembollerdir; ama PDA'nın onları yığıttan çekmesi gerekir. $\sigma_i, \sigma_i \to \varepsilon$ uygulanınca hem girdiden hem yığıttan bir $\sigma_i$ silinir: ilk $\sigma_i$ girdiden, ikincisi yığıttan gelir. Anlık tanım $(q_1, \sigma_{i+1} \cdots \sigma_n, \sigma_{i+1} \cdots \sigma_j B z y \$)$ olur. Son uç sembol $\sigma_j$ de çekilince yığıtta uç sembol kalmaz, bu uç sembollerden oluşan kısım girdiden de silinmiş olur ve tepeye $B$ gelir. Bundan sonra $B$ için bir kural uygulanır ve süreç böyle devam eder.

### 6.4 $abab$ girdisiyle adım adım örnek

Girdi $abab$, yığıtta yalnız $\$$ ve gramer yukarıdaki gramerdir.

- Zaman 0: hiçbir şey okunmamıştır, otomat $q_0$'dadır.
- Zaman 1: yine hiçbir şey okunmadan $\varepsilon, \varepsilon \to S$ ile $S$ yığıta konur ve $q_1$'e geçilir. Yığıt $S\$$ olur. $q_2$ etkin değildir, çünkü $q_2$'ye geçmek için yığıtta yalnız $\$$ kalmış olmalıdır; burada tepede $S$ vardır.

> **Ders sonrası not:** Hoca önce bu adımda $q_2$'nin de etkin olacağını söyledi, hemen ardından düzeltti: tepede $S$ olduğu için $q_2$ etkin değildir.

- Zaman 2: $S$ başlangıç değişkenidir ve iki kuralı vardır ($S \to aSTb$, $S \to b$). PDA deterministik olmadığı için aynı girdi ve yığıt içeriğiyle iki kural da paralel uygulanır ve makine kendini ikiye kopyalar (ekrandan, 01:25:00). Hoca bunu slayt üzerine çizerek gösterdi: $(q_1, S\$)$ tanımından bir kopya $(q_1, aSTb\$)$'a, öteki $(q_1, b\$)$'a gider. Slayt yalnız yaşayan yolu gösterir; öbür kopyayı göstermez. $\varepsilon$-geçişleri bitince artık girdiden okumak gerekir.
- Zaman 3: ilk okunacak sembol $a$'dır. $a$'yı okuyabilmek için yığıtın tepesinde $a$ olmalıdır. Tepesinde $b$ olan kopya bu $a$'yı tüketemez ve ölür. Tepesinde $a$ olan kopyada $a, a \to \varepsilon$ uygulanır; yığıt $STb\$$ olur. Türetmede bu $a$ için bir şey yapılmaz, ama PDA'nın $a$'yı çekmesi gerekir.
- Zaman 4: tepe yine $S$'dir; iki kural yine birlikte etkinleşir, biri yaşar biri ölür. Sonra okunacak sembol $b$ olduğu için yığıta bir $b$ koyan $\varepsilon, S \to b$ kopyası yaşar. Bu, türetmedeki değişken yerine koymaya karşılık gelir: $aSTb \Rightarrow abTb$. Yığıt $bTb\$$ olur.
- Zaman 5: tepede bir uç sembol vardır; girdiden bir sembol okunur ve eşleşirse yığıttan çekilir. $b$ okunur, $b, b \to \varepsilon$ uygulanır; yığıt $Tb\$$ olur.
- Zaman 6: tepe $T$'dir ve türetmede de sıradaki en soldaki değişken $T$'dir (ekrandan, 01:30:00). İki kuraldan biri seçilmelidir. Sıradaki girdi $a$ olduğu için $\varepsilon, T \to Ta$ kullanılan kopya yaşar; türetme $abTb \Rightarrow abTab$ olur, yığıt $Tab\$$ olur.
- Zaman 7: $\varepsilon, T \to \varepsilon$ ile $T$ silinir; yığıt $ab\$$ olur. Bu, türetmede $T$'den kurtulmaya karşılık gelir ve türetme $abab$ ile son dizgiye ulaşır.
- Zaman 8-9: PDA'nın devam edip kalan uç sembolleri çekmesi gerekir: $a$ okunup çekilir, $b$ okunup çekilir; yığıt $\$$ olur.
- Zaman 10: $\varepsilon, \$ \to \$$ ile $q_2$'ye geçilir ve dizgi kabul edilir.

Özetle en soldan türetme

$$S \Rightarrow aSTb \Rightarrow abTb \Rightarrow abTab \Rightarrow abab$$

PDA'daki şu hesaplamaya karşılık gelir (ara adımlar python ile doğrulandı):

$$(q_0, abab, \$) \succ (q_1, abab, S\$) \succ (q_1, abab, aSTb\$) \succ (q_1, bab, STb\$) \succ (q_1, bab, bTb\$) \succ (q_1, ab, Tb\$)$$
$$\succ (q_1, ab, Tab\$) \succ (q_1, ab, ab\$) \succ (q_1, b, b\$) \succ (q_1, \varepsilon, \$) \succ (q_2, \varepsilon, \$)$$

Örneğin $abTab$ türetme adımı, tüketilen $ab$ ile yığıttaki $Tab$'ın yan yana yazılmasıdır. Genel olarak $G$ gramerinin $w$'yi üretmesi ancak ve ancak PDA'nın $w$'yi kabul etmesiyle olur; yani $L(G) = L(M)$.

## 7. PDA'dan bağlamdan bağımsız gramere dönüşüm

Amaç, keyfi bir PDA $M$'yi alıp $L(M) = L(G)$ olacak biçimde bir bağlamdan bağımsız gramer $G$'ye dönüştürmektir (ekrandan, 01:35:00). Bunun için PDA önce epeyce değiştirilir:

- PDA'nın tek bir kabul durumu olacak.
- Yeni bir yığıt başlangıç sembolü kullanılacak.
- Bir dizgi kabul edildiğinde yığıtta yalnız yeni yığıt başlangıç sembolü bulunacak.
- Her geçiş ya bir sembol itecek ya bir sembol çekecek; ikisini birlikte yapmayacak.

### 7.1 Değişiklik 1: tek kabul durumu

Asıl PDA $M$'nin birden fazla kabul durumu varsa, eski kabul durumlarının her biri sıradan (kabul etmeyen) duruma çevrilir. Her birinden yeni kabul durumu $q_f$'ye bir $\varepsilon$-geçişi konur. Elde edilen PDA'ya $M_1$ denir.

### 7.2 Değişiklik 2: yeni yığıt başlangıç sembolü $\#$

$Z$, $M_1$'in özgün yığıt başlangıç sembolü olsun. Yığıtın altına bir yardımcı yığıt sembolü $@$ ve yeni yığıt başlangıç sembolü $\#$ konur (ekrandan, 01:40:00). Yığıt tepeden aşağı şöyle olur:

| Yığıt (tepeden) | Anlamı |
|---|---|
| $Z$ | $M$'nin yığıt başlangıç sembolü |
| $@$ | yardımcı yığıt sembolü (auxiliary) |
| $\#$ | yeni yığıt başlangıç sembolü |

Bunun için $M_1$'e girmeden önce iki yeni durum eklenir. Yeni başlangıç durumu $\varepsilon, \varepsilon \to @$ ile yardımcı sembolü iter; ondan $\varepsilon, \varepsilon \to Z$ ile özgün sembol $Z$ itilip $M_1$'in başlangıç durumuna geçilir. $M_1$ hâlâ $Z$'yi yığıtın tabanı sanır ve hiçbir zaman $Z$'nin altına inmez; dolayısıyla $@$ ile $\#$'i hiç görmez. Bu PDA'ya $M_2$ denir.

### 7.3 Değişiklik 3: kabulde yığıtta yalnız $\#$

Kabul anında yığıtta yalnız $\#$ kalması istenir; bu yüzden $Z$ ile $@$'nin (ve üstlerinde kalan her şeyin) çekilmesi gerekir. $M_2$'ye iki yeni durum eklenir ve eski kabul durumu kabul etmeyen duruma çevrilir. Eski kabul durumundan ilk yeni duruma bir $\varepsilon$-geçişi konur. Bu yeni durumda bir döngü vardır: $@$ ve $\#$ dışındaki her $x$ yığıt sembolü için $\varepsilon, x \to \varepsilon$; yani $\#$ ve $@$ dışındaki her şey çekilir. Son adımda $\varepsilon, @ \to \varepsilon$ ile $@$ de çekilip yeni kabul durumuna geçilir; yığıtta yalnız $\#$ kalır. Bu PDA'ya $M_3$ denir.

### 7.4 Değişiklik 4: her geçiş ya iter ya çeker

Hem çeken hem iten bir geçiş varsa, araya yeni bir durum konarak ikiye bölünür: $q_i$'den önce $a$ çekilerek yeni duruma geçilir, sonra yeni durumdan $b$ itilerek $q_j$'ye geçilir. Böylece itme ve çekme ayrılır.

Ne çeken ne iten bir geçiş varsa, yine araya yeni bir durum konur: önce herhangi bir yığıt sembolü (örneğin yığıt alfabesindeki ilk sembol) itilir, sonra aynı sembol çekilir. Böylece yeni PDA'da her geçiş ya iter ya çeker. <!-- BELİRSİZ: bölünen geçişte girdi sembolünün iki parçadan hangisinde okunduğu karelerde görülmedi. -->

Elde edilen $M_4$ son değiştirilmiş PDA'dır. Yeni yığıt başlangıç sembolü $\#$ hiçbir geçişte kullanılmaz (ekrandan, 01:45:00).

### 7.5 Değiştirilmiş PDA örneği: $M_4$

Hoca, basit bir özgün PDA'ya bu değişiklikler uygulanınca $M_4$'ün epey büyüdüğünü gösterdi. <!-- BELİRSİZ: özgün PDA M'nin slaytı karelerde görülmedi. --> $M_4$'ün geçişleri (ekrandan, 01:55:00):

| Kaynak | Hedef | Geçiş | Tür |
|---|---|---|---|
| $q_0$ (başlangıç) | $q_1$ | $\varepsilon, \varepsilon \to @$ | push |
| $q_1$ | $q_2$ | $\varepsilon, \varepsilon \to Z$ | push |
| $q_2$ | $q_2$ | $a, \varepsilon \to a$ | push |
| $q_2$ | $q_2$ | $b, a \to \varepsilon$ | pop |
| $q_2$ | $q_3$ | $\varepsilon, \varepsilon \to a$ | push |
| $q_3$ | $q_4$ | $\varepsilon, a \to \varepsilon$ | pop |
| $q_4$ | $q_4$ | $\varepsilon, a \to \varepsilon$ | pop |
| $q_4$ | $q_4$ | $\varepsilon, b \to \varepsilon$ | pop |
| $q_4$ | $q_4$ | $\varepsilon, Z \to \varepsilon$ | pop |
| $q_4$ | $q_5$ (kabul) | $\varepsilon, @ \to \varepsilon$ | pop |

Önce $@$, sonra $Z$ itilir. $q_2$–$q_3$–$q_4$ yolu, özgün PDA'daki yığıta dokunmayan bir $\varepsilon$-geçişinin ikiye bölünmüş hâlidir: önce $a$ itilir, sonra geri çekilir. $q_4$'te $\#$ ve $@$ dışındaki her şey yığıttan boşaltılır; son geçiş $@$'yi de çeker, yığıtta yalnız $\#$ kalır ve kabul durumu $q_5$'e geçilir.

### 7.6 Gramerin kurulması

Artık gramer elde etmek kolaydır. PDA'daki her $q_i$ ve $q_j$ durum çifti için bir $A_{q_i q_j}$ değişkeni tanımlanır ve üç tür kural eklenir:

- **Birinci tür:** her $q$ durumu için $A_{qq} \to \varepsilon$. Yani bir durumdan kendisine giden değişken boş dizgiyi üretir.
- **İkinci tür:** her üç durum $p$, $q$, $r$ için $A_{pq} \to A_{pr} A_{rq}$.
- **Üçüncü tür:** $p \xrightarrow{a, \varepsilon \to t} r$ ve $s \xrightarrow{b, t \to \varepsilon} q$ biçiminde, birincisi bir $t$ sembolünü iten, ikincisi aynı $t$ sembolünü çeken her geçiş çifti için (ekrandan, 01:50:00):

$$A_{pq} \to a A_{rs} b$$

- Başlangıç değişkeni: PDA'nın başlangıç durumu $q_0$ ve kabul durumu $q_f$ ise $A_{q_0 q_f}$.

Üçüncü türde kuralı yazarken dikkat edilmelidir: itme her zaman birinci, çekme ikinci geçiştir. İtme geçişinde okunan girdi ($a$) başa, çekme geçişinde okunan girdi ($b$) sona yazılır. Değişkenin alt indisi itme geçişinin ilk durumu ($p$) ile çekme geçişinin son durumudur ($q$); ortadaki değişkenin alt indisi itme geçişinin son durumu ($r$) ile çekme geçişinin ilk durumudur ($s$). İtilen sembolün kendisi ($t$) kuralda görünmez.

**Örnek $M_4$ için birinci tür.** Altı durum ($q_0$–$q_5$) olduğu için $A_{q_0q_0} \to \varepsilon$, $A_{q_1q_1} \to \varepsilon$, ..., $A_{q_5q_5} \to \varepsilon$ eklenir.

**İkinci tür.** Örneğin $q_0$'dan $q_1$'e, önce $q_0$'dan $q_2$'ye, sonra $q_2$'den $q_1$'e gidilerek varılabilir: $A_{q_0q_1} \to A_{q_0q_2} A_{q_2q_1}$. $r$ olarak $p$ ya da $q$'nun kendisi de alınır: $A_{q_0q_1} \to A_{q_0q_0} A_{q_0q_1}$ ve $A_{q_0q_1} \to A_{q_0q_1} A_{q_1q_1}$. Böylece döngüler de hesaba katılmış olur. Her $p, q$ çifti için olası bütün ara durumlar eklendiğinden büyük bir graf için çok sayıda kural çıkar.

**Üçüncü tür.** $M_4$'te bütün itme–çekme çiftlerinden çıkan kurallar (ekrandan, 01:55:00; kurallar python ile geçiş tablosundan yeniden üretilerek doğrulandı):

| İtme geçişi | Çekme geçişi | Kural |
|---|---|---|
| $q_0 \xrightarrow{\varepsilon, \varepsilon \to @} q_1$ | $q_4 \xrightarrow{\varepsilon, @ \to \varepsilon} q_5$ | $A_{q_0q_5} \to A_{q_1q_4}$ |
| $q_1 \xrightarrow{\varepsilon, \varepsilon \to Z} q_2$ | $q_4 \xrightarrow{\varepsilon, Z \to \varepsilon} q_4$ | $A_{q_1q_4} \to A_{q_2q_4}$ |
| $q_2 \xrightarrow{a, \varepsilon \to a} q_2$ | $q_4 \xrightarrow{\varepsilon, a \to \varepsilon} q_4$ | $A_{q_2q_4} \to aA_{q_2q_4}$ |
| $q_2 \xrightarrow{a, \varepsilon \to a} q_2$ | $q_2 \xrightarrow{b, a \to \varepsilon} q_2$ | $A_{q_2q_2} \to aA_{q_2q_2}b$ |
| $q_2 \xrightarrow{a, \varepsilon \to a} q_2$ | $q_3 \xrightarrow{\varepsilon, a \to \varepsilon} q_4$ | $A_{q_2q_4} \to aA_{q_2q_3}$ |
| $q_2 \xrightarrow{\varepsilon, \varepsilon \to a} q_3$ | $q_2 \xrightarrow{b, a \to \varepsilon} q_2$ | $A_{q_2q_2} \to A_{q_3q_2}b$ |
| $q_2 \xrightarrow{\varepsilon, \varepsilon \to a} q_3$ | $q_3 \xrightarrow{\varepsilon, a \to \varepsilon} q_4$ | $A_{q_2q_4} \to A_{q_3q_3}$ |
| $q_2 \xrightarrow{\varepsilon, \varepsilon \to a} q_3$ | $q_4 \xrightarrow{\varepsilon, a \to \varepsilon} q_4$ | $A_{q_2q_4} \to A_{q_3q_4}$ |

Örneğin $q_2$'deki $a, \varepsilon \to a$ ile $a$ itilir ve $q_2$'deki $b, a \to \varepsilon$ ile bu $a$ çekilir; $p = r = s = q = q_2$, girdi başta $a$ sonda $b$ olduğundan $A_{q_2q_2} \to aA_{q_2q_2}b$ çıkar. $q_2 \to q_3$ itme geçişinde girdi $\varepsilon$ olduğu için kuralın başında uç sembol yoktur; derste vurgulandığı gibi $\varepsilon$ girdiler de hesaba katılmalıdır. Başlangıç değişkeni $A_{q_0q_5}$'tir.

> **Ders sonrası not:** Hoca $@$ sembolünü iten ve çeken çift için kuralın slaytta yazılmadığını, bunun yardımcı sembol olmasından kaynaklandığını düşündüğünü söyledi. Oysa slaytta sol sütundaki $A_{q_0q_5} \to A_{q_1q_4}$ kuralı tam bu çiftten çıkar; $A_{q_1q_4} \to A_{q_2q_4}$ de $Z$'yi iten ve çeken çiftten çıkar.

Bu işlem karmaşık görünür, çok sayıda adım içerir, ama tamamen mekaniktir. Böylece gramerleri PDA'ya ve PDA'ları gramere dönüştüren iki yöntem öğrenilmiş oldu; bu da PDA'ların ve bağlamdan bağımsız gramerlerin aynı dil kümesini tanımladığı anlamına gelir.

## Örnek Sorular

**Soru 1** (ekrandan, 00:30:00): $L = \{w \in \{a,b\}^* : n_a(w) = n_b(w)\}$ dilini kabul eden PDA'nın ($a, \$ \to 0\$$; $a, 0 \to 00$; $a, 1 \to \varepsilon$; $b, \$ \to 1\$$; $b, 1 \to 11$; $b, 0 \to \varepsilon$; $q_1 \xrightarrow{\varepsilon, \$ \to \$} q_2$) $abbbaa$ girdisindeki çalışmasını izleyin.

> **Çözüm (derste verildi):** Yığıt sırasıyla $\$ \to 0\$ \to \$ \to 1\$ \to 11\$ \to 1\$ \to \$$ olur. Girdi bitince yığıtta yalnız $\$$ kalır, $\varepsilon, \$ \to \$$ ile $q_2$'ye geçilir ve dizgi kabul edilir.

**Soru 2** (ekrandan, 00:40:00): $a^n b^n$ PDA'sının $aaabbb$ girdisi için hesaplamasını anlık tanımlarla yazın.

> **Çözüm (derste verildi):** $(q_0, aaabbb, \$) \succ (q_1, aaabbb, \$) \succ (q_1, aabbb, a\$) \succ (q_1, abbb, aa\$) \succ (q_1, bbb, aaa\$) \succ (q_2, bb, aa\$) \succ (q_2, b, a\$) \succ (q_2, \varepsilon, \$) \succ (q_3, \varepsilon, \$)$. $q_3$ kabul durumu ve girdi tükendiği için $aaabbb \in L(M)$.

**Soru 3** (ekrandan, 01:05:00): $S \to aSTb \mid b$, $T \to Ta \mid \varepsilon$ gramerini PDA'ya dönüştürün ve $abab$ girdisinin kabulünü en soldan türetmeyle karşılaştırarak gösterin.

> **Çözüm (derste verildi):** $q_0 \xrightarrow{\varepsilon,\varepsilon\to S} q_1 \xrightarrow{\varepsilon,\$\to\$} q_2$; $q_1$ döngüsünde $\varepsilon, S \to aSTb$; $\varepsilon, S \to b$; $\varepsilon, T \to Ta$; $\varepsilon, T \to \varepsilon$; $a, a \to \varepsilon$; $b, b \to \varepsilon$. Türetme $S \Rightarrow aSTb \Rightarrow abTb \Rightarrow abTab \Rightarrow abab$; hesaplama 6.4'teki gibidir ve $(q_2, \varepsilon, \$)$ ile biter.

**Soru 4** (ekrandan, 01:55:00): 7.5'teki $M_4$ için üçüncü tür (itme–çekme çiftlerinden gelen) gramer kurallarını yazın.

> **Çözüm (derste verildi):** $A_{q_0q_5} \to A_{q_1q_4}$, $A_{q_1q_4} \to A_{q_2q_4}$, $A_{q_2q_4} \to aA_{q_2q_4}$, $A_{q_2q_2} \to aA_{q_2q_2}b$, $A_{q_2q_4} \to aA_{q_2q_3}$, $A_{q_2q_2} \to A_{q_3q_2}b$, $A_{q_2q_4} \to A_{q_3q_3}$, $A_{q_2q_4} \to A_{q_3q_4}$.

## Dersin Toparlaması

Bu derste önce yığıtlı otomatlar tekrar edildi: geçişlerin $a, b \to c$ biçiminde yazılışı, deterministik olmayış ve $\varepsilon$-geçişleri, kabulün yalnız girdinin tükenmesi ve kabul durumunda olmaya bağlı olması. $v v^R$ ve $n_a = n_b$ örnekleri üzerinden yığıtın eşleme için nasıl kullanıldığı ve geçişlerde dizgi itilip çekilebileceği görüldü. Ardından PDA'nın yedili biçimsel tanımı, geçiş fonksiyonunun küme değerli olması, anlık tanımlar, $\succ$ ve $\overset{*}{\succ}$ gösterimiyle hesaplama ve PDA'nın dili tanımlandı; $a^n b^n$ PDA'sının dili bu tanımla yazıldı.

Dersin ikinci yarısında PDA'lar ile bağlamdan bağımsız gramerlerin aynı dil sınıfını tanımladığı iki yönlü yapıcı ispatla gösterildi. Gramerden PDA'ya dönüşümde sabit üç durumlu bir grafiğin $q_1$ döngüsüne kural ve uç sembol geçişleri eklenir ve PDA en soldan türetmeyi taklit eder. PDA'dan gramere dönüşümde önce PDA dört adımda $M_4$'e getirilir, sonra $A_{pq}$ değişkenleri için üç tür kural yazılır. Böylece bağlamdan bağımsız diller konusu, düzenli dillerden başlayarak işlenen konularla birlikte tamamlanmış oldu.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
