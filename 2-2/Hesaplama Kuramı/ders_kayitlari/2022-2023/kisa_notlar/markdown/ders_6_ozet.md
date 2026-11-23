# Ders 6 Çalışma Özeti

## Genel Konular

- Bir dilin düzenli olmadığını ispatlama sorunu
  - Bir dilin düzenli olduğu bir DFA, bir NFA ya da bir düzenli ifade yazılarak gösterilir. Düzenli olmadığını göstermek için bu yol işe yaramaz, çünkü sonsuz sayıdaki DFA'nın hiçbirinin dili kabul etmediğini tek tek göstermek mümkün değildir.
  - Bunun için pompalama önsavı (pumping lemma) kullanılır. Önsav güvercin yuvası ilkesine (pigeonhole principle) dayanır.
- Güvercin yuvası ilkesi ve DFA'da durum tekrarı
  - 4 güvercin 3 yuvaya dağıtılırsa en az bir yuvada iki güvercin olur.
  - $p$ durumlu bir DFA, uzunluğu $p$ ya da daha fazla olan bir dizgiyi kabul ediyorsa, dizginin yürüyüşünde (walk) en az bir durum tekrar eder; yani yürüyüşte bir döngü vardır. Slayttaki örnekte 4 durumlu bir DFA'da $aaaab$ dizgisinin yürüyüşü $q_1 \to q_2 \to q_3 \to q_2 \to q_3 \to q_4$ biçimindedir ve $q_2$ tekrar eder (ekrandan, 00:05:00).
- Pompalama önsavı
  - Sonlu her dil düzenlidir (sonlu sayıda kelimeyi kabul eden bir otomat hemen yazılır). Bu yüzden önsav sonsuz düzenli diller için kullanılır.
  - Önsav: $L$ sonsuz bir düzenli dilse, öyle bir $p$ tam sayısı (kritik uzunluk) vardır ki $|w| \ge p$ olan her $w \in L$ dizgisi $w = xyz$ biçiminde yazılabilir; burada $|xy| \le p$, $|y| \ge 1$ ve her $i = 0, 1, 2, \dots$ için $x y^i z \in L$ olur (ekrandan, 00:25:00).
  - $x$ döngüden önceki kısım, $y$ ilk döngüdeki semboller, $z$ döngüden sonraki kısımdır. $|xy| \le p$ olur, çünkü ilk tekrar eden duruma gelinene kadar hiçbir durum tekrar etmez (ekrandan, 00:10:00). $z$'nin biçimi önemli değildir; içinde başka döngüler olabilir.
- Düzensizlik ispatının adımları (ekrandan, 00:15:00)
  - $L$'nin düzenli olduğu varsayılır (olmayana ergi, contradiction). $L$ sonsuz olduğu için önsav uygulanabilir.
  - $p$ kritik uzunluk olsun; $p$'ye sayı verilmez.
  - $w \in L$ ve $|w| \ge p$ olan belirli bir dizgi seçilir; genelde $p$ dizginin üslerinde yer alır.
  - $w = xyz$ yazılır ve bazı $i \ne 1$ için $x y^i z \notin L$ olduğu gösterilir. Bu, önsavla çelişir; demek ki $L$ düzenli değildir.
  - Çelişki için tek bir $w$ yeterlidir; her $w$ için çelişki göstermek gerekmez.
- Dört düzensizlik ispatı
  - $L = \{a^n b^n : n \ge 0\}$: $w = a^p b^p$ seçilir. $|xy| \le p$ olduğu için $y = a^k$, $1 \le k \le p$. $x y^2 z = a^{p+k} b^p \notin L$ (ekrandan, 00:25:00).
  - $L = \{v v^R : v \in \Sigma^*\}$: $w = a^p b^p b^p a^p$ seçilir ($|w| = 4p$). $y = a^k$ olur. $x y^2 z = a^{p+k} b^p b^p a^p \notin L$ (ekrandan, 00:50:00).
  - $L = \{a^n b^l c^{n+l} : n, l \ge 0\}$: $w = a^p b^p c^{2p}$ seçilir. $y = a^k$ olur. Aşağı pompalama ($i = 0$) ile $xz = a^{p-k} b^p c^{2p} \notin L$ (ekrandan, 01:00:00).
  - $L = \{a^{n!} : n \ge 0\}$: $w = a^{p!}$ seçilir. $y = a^k$ olur. $x y^2 z = a^{p!+k}$; ama $p! < p! + k < (p+1)!$ olduğu için $p! + k$ hiçbir sayının faktöriyeli olamaz (ekrandan, 01:05:00).
- Bağlamdan bağımsız diller (context-free languages)
  - Düzenli diller, bağlamdan bağımsız dillerin alt kümesidir.
  - Bağlamdan bağımsız diller, yığıtlı otomatlarla (pushdown automata) kabul edilir (NFA/DFA'ya benzer) ve bağlamdan bağımsız gramerlerle (context-free grammars) üretilir (düzenli ifadeye benzer). Bu derste gramerler işlendi; yığıtlı otomatlar sonraki derslere kaldı.
- Gramer kavramı
  - İngilizce gramer örneği: $\langle sentence \rangle \to \langle noun\_phrase \rangle \langle predicate \rangle$, $\langle noun\_phrase \rangle \to \langle article \rangle \langle noun \rangle$, $\langle predicate \rangle \to \langle verb \rangle$, $\langle article \rangle \to a \mid the$, $\langle noun \rangle \to cat \mid dog$, $\langle verb \rangle \to runs \mid sleeps$ (ekrandan, 01:25:00). Bu gramerin dili 8 cümleden oluşan sonlu bir dildir.
  - Her kural (üretim, production) okla yazılır: solda bir değişken (variable), sağda değişken ve uç sembollerden (terminal) oluşan bir dizgi bulunur. Sağ taraf boş dizgi $\varepsilon$ da olabilir.
- Biçimsel tanım
  - Gramer bir dörtlüdür: $G = (V, T, S, P)$; $V$ değişkenler, $T$ uç semboller, $S$ başlangıç değişkeni, $P$ üretim kümesidir (ekrandan, 01:35:00).
  - Bağlamdan bağımsız gramerde her üretim $A \to s$ biçimindedir: $A$ tek bir değişken, $s$ değişken ve uç sembollerden oluşan bir dizgidir.
  - $w_1 \overset{*}{\Rightarrow} w_n$: $w_1$'den sıfır ya da daha fazla türetme adımıyla $w_n$'ye ulaşılır. $w \overset{*}{\Rightarrow} w$ her zaman doğrudur.
  - Dil: $L(G) = \{w \in T^* : S \overset{*}{\Rightarrow} w\}$. Bir dil için bağlamdan bağımsız bir gramer yazılabiliyorsa o dil bağlamdan bağımsızdır.
- Gramer örnekleri
  - $S \to aSb \mid \varepsilon$: $S \Rightarrow aSb \Rightarrow ab$, $S \Rightarrow aSb \Rightarrow aaSbb \Rightarrow aabb$. Dil: $\{a^n b^n : n \ge 0\}$ (ekrandan, 01:30:00). Bu dil düzenli değildir ama bağlamdan bağımsızdır.
  - $S \to aSa \mid bSb \mid \varepsilon$: dil $\{w w^R : w \in \{a,b\}^*\}$, yani çift uzunluklu palindromlar (ekrandan, 01:40:00).
  - $S \to aSb \mid SS \mid \varepsilon$: dil, $a$ ve $b$ sayıları eşit olan ve her önekinde $a$ sayısı $b$ sayısından az olmayan dizgilerdir; $a = ($, $b = )$ alınırsa eşleşen parantezleri tarif eder (ekrandan, 01:45:00).
- Türetme sırası (derivation order)
  - Gramer: 1. $S \to AB$, 2. $A \to aaA$, 3. $A \to \varepsilon$, 4. $B \to Bb$, 5. $B \to \varepsilon$ (ekrandan, 02:00:00).
  - En soldan türetme (leftmost): her adımda en soldaki değişken değiştirilir: $S \Rightarrow AB \Rightarrow aaAB \Rightarrow aaB \Rightarrow aaBb \Rightarrow aab$.
  - En sağdan türetme (rightmost): her adımda en sağdaki değişken değiştirilir: $S \Rightarrow AB \Rightarrow ABb \Rightarrow Ab \Rightarrow aaAb \Rightarrow aab$.
- Türetme ağacı (derivation tree, parse tree)
  - Kök başlangıç değişkenidir; her üretim bir düğümün çocuklarını verir; yapraklar soldan sağa okunduğunda türetilen dizgi elde edilir.
  - $aab$ için en soldan ve en sağdan türetmeler aynı ağacı verir: $S$'nin çocukları $A$, $B$; $A$'nın çocukları $a$, $a$, $A$; alttaki $A \to \varepsilon$; $B$'nin çocukları $B$, $b$; alttaki $B \to \varepsilon$ (ekrandan, 02:05:00).
- Belirsizlik (ambiguity)
  - Bir gramer, dilindeki bir $w$ dizgisi için iki farklı türetme ağacı (ya da iki farklı en soldan türetme) varsa belirsizdir.
  - $E \to E + E \mid E * E \mid (E) \mid a$ grameri belirsizdir: $a + a * a$ için biri $+$ ile, biri $*$ ile başlayan iki ağaç vardır. $a = 2$ alınırsa ağaçlara göre değer 6 ya da 8 çıkar (ekrandan, 02:10:00).
  - Belirsizlik ifade değerlendirmede ve derleyicilerde sorun çıkarır; derleyici kodu türetme ağacına göre anlamlandırır.
  - "if-then-else" grameri ($\langle stmt \rangle \to if\ \langle expr \rangle\ then\ \langle stmt \rangle \mid if\ \langle expr \rangle\ then\ \langle stmt \rangle\ else\ \langle stmt \rangle$) belirsizdir: "if expr1 then if expr2 then stmt1 else stmt2" iki farklı ağaçla türetilir (ekrandan, 02:15:00). Programlama dillerinde süslü parantezler bu belirsizliği programcının gidermesini sağlar.
  - Bazen belirsiz bir gramerin belirsiz olmayan denk bir grameri bulunabilir (ifade grameri için $E$, $T$, $F$ değişkenleriyle). Bazen bulunamaz: $L = \{a^n b^n c^m\} \cup \{a^n b^m c^m\}$, $n, m \ge 0$ dili doğası gereği belirsizdir (inherently ambiguous); bu dili üreten her gramer belirsizdir (ekrandan, 02:20:00).

## Hocanın Özellikle Vurguladığı Kısımlar

- Pompalama önsavı sınavlarda sorulur.
  - Tipik soru: bir dil verilir, düzenli olup olmadığı sorulur. Düzenli deniyorsa DFA, NFA ya da düzenli ifade yazılır; düzenli değil deniyorsa pompalama önsavıyla ispatlanır. Kitaptaki örnekler kendi başına çözülmelidir.
- $p$'ye sayı verilmez.
  - Öğrencilerin en sık yaptığı hata "$p$'yi 5 aldım" demektir. İspat genel $p$ için yapılmalıdır.
- $|xy| \le p$ koşulu ispatı çok kolaylaştırır.
  - Seçilen dizgi $a^p$ ile başlıyorsa $x$ ve $y$ yalnız $a$'lardan oluşur, $y = a^k$ ($1 \le k \le p$) olmak zorundadır; başka bölme yolu yoktur.
- Pompalama önsavı yalnız düzensizliği ispatlamak için kullanılır.
  - Düzenlilik önsavla ispatlanmaz; DFA, NFA ya da düzenli ifade yazılarak gösterilir.
- Belirsizlik kötüdür ve giderilmek istenir.
  - Derleyici, belirsiz bir kodun anlamını bilemez.

## Kısa Tekrar Notları

- Düzenli: DFA / NFA / düzenli ifade yaz. Düzenli değil: pompalama önsavı.
- Önsav: sonsuz düzenli $L$ için kritik uzunluk $p$ var; $|w| \ge p$ ise $w = xyz$, $|xy| \le p$, $|y| \ge 1$, her $i \ge 0$ için $x y^i z \in L$.
- İspat şablonu: düzenli varsay, $p$ al, $w$ seç, $y = a^k$ ($1 \le k \le p$) bul, $i = 2$ (yukarı pompalama) ya da $i = 0$ (aşağı pompalama) ile $L$ dışına çık, çelişki.
- Seçilen dizgiler: $a^n b^n \to a^p b^p$; $v v^R \to a^p b^p b^p a^p$; $a^n b^l c^{n+l} \to a^p b^p c^{2p}$; $a^{n!} \to a^{p!}$.
- Faktöriyel örneğinde kilit eşitsizlik: $p! + k \le p! + p < p! \cdot p + p! = (p+1)!$.
- Bağlamdan bağımsız gramer: $G = (V, T, S, P)$, üretimler $A \to s$.
- $S \to aSb \mid \varepsilon$ dili $a^n b^n$; $S \to aSa \mid bSb \mid \varepsilon$ dili $w w^R$; $S \to aSb \mid SS \mid \varepsilon$ eşleşen parantezler.
- En soldan / en sağdan türetme: her adımda en soldaki / en sağdaki değişken değiştirilir.
- Belirsiz gramer: aynı dizgi için iki farklı türetme ağacı. Doğası gereği belirsiz dil: her grameri belirsiz.

## Detaylı Açıklamalar

- Pompalama önsavının sezgisi: $L$ düzenliyse onu kabul eden $p$ durumlu bir DFA vardır. Uzunluğu en az $p$ olan bir dizgi okunurken $p$ ya da daha fazla geçiş yapılır, ama tekrarsız yalnız $p - 1$ geçiş yapılabilir; bu yüzden bir durum ($q$) tekrar eder ve yürüyüşte bir döngü oluşur. Döngüden önce okunan kısım $x$, ilk döngüde okunan kısım $y$, gerisi $z$ olur. Döngü hiç dönülmezse ($xz$), iki kez dönülürse ($xyyz$) ya da binlerce kez dönülürse otomat yine aynı yoldan kabul durumuna varır. Bu yüzden her $i \ge 0$ için $x y^i z \in L$ olur. $y$ boş olamaz, çünkü döngüde en az bir geçiş vardır.
- $a^n b^n$ ispatı: $L$'nin düzenli olduğunu varsayalım. $L$ sonsuzdur, önsav uygulanır. $p$ kritik uzunluk olsun ve $w = a^p b^p$ seçilsin ($|w| = 2p \ge p$). $|xy| \le p$ olduğu için $xy$ ilk $p$ sembolün, yani $a$'ların içinde kalır; $y = a^k$, $1 \le k \le p$ ($k = p$ ise $x$ boştur). Önsava göre $x y^2 z = a^{p+k} b^p \in L$ olmalıdır. Ama $k \ge 1$ olduğundan $a$ sayısı $b$ sayısından fazladır, dizgi dilde değildir. Çelişki: $L$ düzenli değildir.
- $v v^R$ ispatı: aynı yolla $w = a^p b^p b^p a^p$ seçilir. $y = a^k$ olur ve $x y^2 z = a^{p+k} b^p b^p a^p$ elde edilir. Bu dizgi bir dizginin kendisi ile tersinin birleştirmesi olamaz (baştaki ve sondaki $a$ sayıları farklıdır), dolayısıyla dilde değildir.
- $a^n b^l c^{n+l}$ ispatı: $w = a^p b^p c^{2p}$ seçilir ($|w| = 4p$). $y = a^k$ olur. Bu kez aşağı pompalama yapılır: $i = 0$ için $xz = a^{p-k} b^p c^{2p}$. $a$ ve $b$ sayılarının toplamı $2p - k$, $c$ sayısı $2p$ olduğu için dizgi dilde değildir.
- $a^{n!}$ ispatı: $w = a^{p!}$ seçilir; $p!$, $p$'den hızlı büyüdüğü için $|w| \ge p$ olur. $y = a^k$, $1 \le k \le p$. $x y^2 z = a^{p!+k}$ dilde olsaydı bir $z$ için $p! + k = z!$ olurdu. Ama $p > 1$ için $p! + k \le p! + p \le p! + p! < p! \cdot p + p! = p!(p+1) = (p+1)!$ (ekrandan, 01:05:00). Yani $p! + k$, $p!$ ile $(p+1)!$ arasında kalır ve bir faktöriyel olamaz. Hocanın sayısal örneği: $p = 5$ için $5! = 120$, en fazla $5$ eklenince $125$ olur; $6! = 720$'dir, sonraki faktöriyele ulaşılamaz.
- Gramerle türetme: başlangıç değişkeninden başlanır, her adımda bir değişkenin yerine kurallarından birinin sağ tarafı yazılır, değişken kalmayınca türetilen dizgi elde edilir. Bir kural sınırsız sayıda kullanılabildiği için sonsuz diller üretilebilir; düzenli dillerle üretilemeyen $a^n b^n$ gibi diller de üretilir.
- İfade gramerinin belirsizliği: $E \to E + E \mid E * E \mid (E) \mid a$ ile $a + a * a$ dizgisi iki farklı en soldan türetmeyle elde edilir. İlkinde kökte $E + E$ kullanılır ve çarpma alt ağaçta kalır; $a = 2$ için değer $2 + (2 \cdot 2) = 6$ olur (doğru ağaç). İkincisinde kökte $E * E$ kullanılır ve toplama alt ağaçta kalır; değer $(2 + 2) \cdot 2 = 8$ olur (yanlış ağaç). Ağacın kökündeki işlem en son yapılan işlemdir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
