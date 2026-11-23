# Ders 5 Genişletilmiş Notu: Düzenli İfadeler, NFA'dan Düzenli İfadeye Dönüşüm ve Pompalama Önsavına Giriş

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Önceki Dersin Tekrarı: Düzenli Dillerin Kapanış Özellikleri
- 2. Düzenli İfadeler (Regular Expressions)
- 3. Düzenli İfadelerin Özyinelemeli Tanımı
- 4. Bir Düzenli İfadenin Dili
- 5. Düzenli İfade Örnekleri
- 6. Denk Düzenli İfadeler
- 7. Teorem: Düzenli İfadelerin Dilleri ile Düzenli Diller Aynıdır
- 8. İspatın 1. Kısmı: Her Düzenli İfadenin Dili Düzenlidir
- 9. İspatın 2. Kısmı: NFA'dan Düzenli İfadeye Dönüşüm
- 10. Düzenli Dillerin Standart Gösterimleri
- 11. Düzenli Olmayan Diller ve Pompalama Önsavına Giriş
- 12. Güvercin Yuvası İlkesi ve DFA Yürüyüşleri
- 13. Pompalama Önsavı
- 14. Pompalama Önsavı ile İspatın Genel Mantığı

## 1. Önceki Dersin Tekrarı: Düzenli Dillerin Kapanış Özellikleri

Hoca derse geçen haftanın konusunu hatırlatarak başladı: düzenli dillerin (regular languages) özellikleri. Bir dil zaten bir kümedir. Düzenli diller **birleşim** (union), **birleştirme** (concatenation), **yıldız** (Kleene star), **ters çevirme** (reverse), **tümleyen** (complement) ve **kesişim** (intersection) işlemlerine sokulduğunda sonuç yine düzenli bir dildir. Bu yüzden "düzenli diller bu işlemler altında kapalıdır" denir.

Bu özellikler ispatlanırken dilleri kabul eden DFA ya da NFA'ların bir tür birleşimi, kesişimi, birleştirmesi de kurulmuştu. Örneğin iki makinenin "birleşimi", o makinelerin dillerinin birleşimini kabul eden makinedir. Bu hafta **düzenli ifadelere** (regular expressions) geçildi.

## 2. Düzenli İfadeler (Regular Expressions)

Hoca, "düzenli" sözcüğünün bu derste çok geçtiğini, düzenli dil ile düzenli ifadenin karıştırılmaması gerektiğini söyledi. Düzenli ifadeler programlamada sık kullanılır: belirli özelliklere sahip metinleri bulmak, metinleri eşlemek (matching) ya da bir metnin içinden belirli kısımları çıkarmak için.

Düzenli ifadeler düzenli dilleri tarif eder. Slayttaki örnek (ekrandan, 00:10:00):

$$(a + b \cdot c)^* \quad \text{ifadesi} \quad \{a, bc\}^* = \{\varepsilon, a, bc, aa, abc, bca, \dots\}$$

dilini tarif eder. Okuma kuralları şöyledir:

- $+$ "veya" diye okunur: $a + b\cdot c$, "$a$ ya da $bc$" demektir.
- $\cdot$ birleştirmedir (concatenation): $b \cdot c = bc$.
- Parantez ifadeleri gruplar.
- $^*$ Kleene yıldızıdır ve önceki derslerdeki anlamıyla aynıdır: içindeki ifadenin sıfır ya da istenen sayıda tekrarı.

Yıldız boş dizgiyi de eşlediği için dilde $\varepsilon$ vardır. Sonra istenen sayıda $a$ ($a$, $aa$, $aaa$, ...) ve istenen sayıda $bc$ ($bc$, $bcbc$, ...) gelir. Yıldız birleştirme de yaptığı için bunların karışımları da dildedir: $abc$, $bca$, $aabcbc$ gibi.

## 3. Düzenli İfadelerin Özyinelemeli Tanımı

Düzenli ifadeler özyinelemeli (recursive) olarak tanımlanır. Başlangıç noktası **ilkel** (primitive) düzenli ifadelerdir; "ilkel" daha küçük parçalara bölünemeyen demektir:

- $\emptyset$ (boş küme),
- $\varepsilon$ (boş dizgi, null string),
- tek bir sembol: $a$, $b$, $c$ gibi.

$r_1$ ve $r_2$ düzenli ifade ise şunlar da düzenli ifadedir:

- $r_1 + r_2$ (artı işlemi),
- $r_1 \cdot r_2$ (birleştirme),
- $r_1^*$ (Kleene yıldızı),
- $(r_1)$ (gruplama).

İlkel ifadelerden başlayıp bu işlemler uygulandığında yine bir düzenli ifade elde edilir.

Hoca bir örnekle tanıma uyan ve uymayan ifadeyi gösterdi. $(a + b\cdot c)^* \cdot (c + \emptyset)$ düzenli bir ifadedir: bütün parçalar ya tek sembol ya da $\emptyset$'dir; işlemler artı, nokta, yıldız ve gruplamadır. $(a + b +)$ ise düzenli ifade değildir, çünkü artı işlemi iki işlenen ister; $b$ birinci işlenendir ama artıdan sonra ikinci işlenen eksiktir.

<!-- BELİRSİZ: Bu iki örnek ifade altyazıdaki anlatımdan kuruldu; o slaytın karesi yok. -->

## 4. Bir Düzenli İfadenin Dili

$L(r)$, $r$ düzenli ifadesinin dilidir: $r$'yi eşleyen bütün dizgilerin kümesi (ekrandan, 00:15:00). Örneğin

$$L\big((a+b\cdot c)^*\big) = \{\varepsilon, a, bc, aa, abc, bca, \dots\}.$$

$aa$ bu dildedir, çünkü ifadede $a$ var ve yıldız sayesinde $a$ iki kez tekrar edebilir.

Ders bundan sonra şu soruya yöneldi: düzenli ifadelerin dilleri düzenli midir?

### 4.1 İlkel ifadelerin dilleri

İlkel ifadelerin dilleri (ekrandan, 00:20:00):

$$L(\emptyset) = \emptyset, \qquad L(\varepsilon) = \{\varepsilon\}, \qquad L(a) = \{a\}.$$

**Soru:** Son örnekte $L(a)$ kümesinde neden boş dizgi (epsilon) yok? **Cevap:** Çünkü yıldız yok. Önceki örneklerde $\varepsilon$'u getiren Kleene yıldızıydı; yıldız boş dizgiyi de eşler, yani hiçbir şey olmasa da eşleşme olur. Yıldız yoksa tek bir sembol yalnız kendisini eşler.

### 4.2 İşlemlerin dilleri

$r_1$ ve $r_2$ düzenli ifadeleri için (ekrandan, 01:05:00):

$$L(r_1 + r_2) = L(r_1) \cup L(r_2)$$
$$L(r_1 \cdot r_2) = L(r_1)\,L(r_2)$$
$$L(r_1^*) = \big(L(r_1)\big)^*$$
$$L\big((r_1)\big) = L(r_1)$$

Artı işlemi dillerin birleşimini, nokta dillerin (kümelerin) birleştirmesini, yıldız dilin yıldızını verir. Kümelerin birleşimi, birleştirmesi ve yıldızı önceki haftalarda görülmüştü. Gruplama yeni bir dil üretmez; dil aynı kalır.

### 4.3 Örnek: $L((a+b)\cdot a^*)$

Her düzenli ifade yalnız bu dört işlemi içerebildiği için dil, bu kurallarla dıştan içe parçalanarak bulunur (ekrandan, 00:25:00):

$$
\begin{aligned}
L((a+b)\cdot a^*) &= L((a+b))\,L(a^*) \\
&= L(a+b)\,L(a^*) \\
&= \big(L(a)\cup L(b)\big)\,\big(L(a)\big)^* \\
&= \big(\{a\}\cup\{b\}\big)\,\big(\{a\}\big)^* \\
&= \{a,b\}\,\{\varepsilon, a, aa, aaa, \dots\} \\
&= \{a, aa, aaa, \dots, b, ba, baa, \dots\}
\end{aligned}
$$

Adımlar: önce nokta (birleştirme) ayrılır; gruplama dili değiştirmediği için parantez kalkar; artı birleşime dönüşür; yıldız dilin yıldızına dönüşür; ilkel ifadelerin dilleri yerine konur; son olarak iki kümenin birleştirmesi alınır. Sonuç: tek bir $a$ ya da tek bir $b$ ile başlayan, ardından istenen sayıda $a$ gelen dizgiler.

Hoca burada bir sezgi verdi: düzenli ifade, dilin elemanlarının nasıl göründüğünü bir resim gibi gösterir. Bu örnekte "tek bir $a$ ya da tek bir $b$, sonra istenen kadar $a$".

## 5. Düzenli İfade Örnekleri

### 5.1 $(a+b)^*(a+bb)$

Slayttaki örnek (ekrandan, 00:35:00):

$$r = (a+b)^*(a+bb), \qquad L(r) = \{a, bb, aa, abb, ba, bbb, \dots\}.$$

İlk kısımda yıldız olduğu için $a$ ve $b$'ler her sırada ve sayıda (boş dahil) gelebilir; bu kısım önemli değildir. Son kısım ise dizginin ya tek bir $a$ ile ya da $bb$ ile bitmesini zorunlu kılar. Yani bu ifade **$a$ ile ya da $bb$ ile biten bütün dizgileri** eşler.

> **Ders sonrası not:** Hoca bir yerde "a ya da b ile biten" dedi; slayttaki ifadeye göre doğrusu "$a$ ya da $bb$ ile biten"dir.

**Soru:** Bu örneğin dili de $a^n b^m$ gibi üstel bir gösterimle yazılabilir mi? **Cevap:** Hoca her dilin böyle güzel bir biçimde yazılamayacağını söyledi ve sınıfla birlikte denedi. Sorun ilk kısımdadır: $(a+b)^*$, $a$ ve $b$'leri istenen sırada birleştirir. $(ab)^*$ yazmak yetmez, çünkü o yalnız $ab\,ab\,ab\dots$ demektir. Tahtada $a^n b^m a^k b^p \dots$ biçiminde bir deneme yapıldı (ekrandan, 00:35:00), ama bu da örneğin $b$'lerle başlayıp $a$, $b$, $a$ diye sürekli değişen dizgileri tam ifade etmiyor. Hoca bunu üstel bir ifadeyle yazmanın çok zor olduğunu, kendisinin bulamadığını söyledi.

**Soru:** Bu dil düzensiz (irregular) olmuyor mu? **Cevap:** Hayır, düzenlidir. Düzenli ifadeler düzenli dilleri eşler; bu, düzenli dilleri tarif etmenin üçüncü yoludur. Bir DFA bir dilin dizgilerini kabul ediyorsa o dil düzenlidir; bir NFA kabul ediyorsa yine düzenlidir; şimdi de bir düzenli ifade onu eşliyorsa düzenlidir. Bir dilin üstel gösterimle yazılamaması onu düzensiz yapmaz.

<!-- BELİRSİZ: Altyazıda cevap "İrregular oluyor" diye geçiyor; bağlama göre hocanın kastettiği "düzenli oluyor"dur. -->

### 5.2 $(aa)^*(bb)^*b$

Slayttaki örnek (ekrandan, 00:30:00):

$$r = (aa)^*(bb)^*b, \qquad L(r) = \{a^{2n} b^{2m} b : n, m \ge 0\}.$$

İstenen sayıda $aa$ gelir, sonra istenen sayıda $bb$ gelir; $aa$'lar $bb$'lerden önce gelmek zorundadır ve son sembol $b$'dir. $a$'ların sayısı çifttir ($0, 2, 4, \dots$); başta tek bir $a$ olamaz. Aynı dil hem düzenli ifadeyle hem de bu küme gösterimiyle yazılabilir.

> **Ders sonrası not:** Hoca "$a$'ların ve $b$'lerin sayısı çift" dedi. $a$'ların sayısı çifttir ($2n$), ama sondaki fazladan $b$ yüzünden toplam $b$ sayısı tektir ($2m+1$).

### 5.3 $00$ alt dizgisini içeren dizgiler

$(0+1)^*00(0+1)^*$ ifadesi $00$ alt dizgisini içeren bütün dizgileri eşler. Baştaki ve sondaki yıldızlı kısımlarda $0$ ve $1$'lerin her türlü birleştirmesi olabilir, ama ortadaki $00$'ın yıldızı yoktur; dolayısıyla dizginin bir yerinde mutlaka $00$ bulunmalıdır.

<!-- BELİRSİZ: Bu slaytın karesi yok; ifade altyazıdaki anlatımdan kuruldu. -->

### 5.4 $00$ alt dizgisini içermeyen dizgiler

Slayttaki örnek (ekrandan, 00:40:00):

$$r = (1+01)^*(0+\varepsilon), \qquad L(r) = \{\text{00 alt dizgisini içermeyen bütün dizgiler}\}.$$

Hoca bunun ilk bakışta açık olmadığını, üzerinde çalışıp $00$'ı nasıl engellediğini görmek gerektiğini söyledi. $(1+01)^*$ kısmından $101$, $0101$ gibi dizgiler gelir: bazı $1$'ler, bazı $01$'ler. Bu kısımdan gelen her $0$ tektir ve hemen ardından bir $1$ gelir. Sonda en fazla bir $0$ daha eklenebilir. Böylece iki $0$ hiçbir zaman yan yana gelmez.

Hoca sınıfa sondaki $\varepsilon$'un neden gerekli olduğunu sordu.

**Soru (hocanın sorusu):** Sondaki boş dizgi neden var? **Cevap (bir öğrenci):** $\varepsilon$ olmasaydı ifade hep $0$ ile bitmek zorunda kalırdı; örneğin $1111$ kabul edilmezdi. Hoca da bunu onayladı: $\varepsilon$ sayesinde $(1+01)^*$ kısmından sonra dizgi bitirilebilir, böylece $1$ ile biten dizgiler de eşlenir.

## 6. Denk Düzenli İfadeler

$r_1$ ve $r_2$ düzenli ifadelerinin dilleri aynıysa ($L(r_1) = L(r_2)$) bu ifadeler **denktir** (equivalent).

Örnek: $L = \{00 \text{ alt dizgisini içermeyen dizgiler}\}$ için (ekrandan, 00:55:00)

$$r_1 = (1+01)^*(0+\varepsilon)$$
$$r_2 = (1^*011^*)^*(0+\varepsilon) + 1^*(0+\varepsilon)$$

$r_2$'de istenen sayıda $1$, sonra $01$, sonra yine istenen sayıda $1$ gelir ve bunun tamamı yıldızlıdır; ardından ya bir $0$ ya da hiçbir şey gelir. İkinci terim ise istenen sayıda $1$ ve ardından bir $0$ ya da hiçbir şeydir. Düşünüldüğünde $r_2$ de $r_1$ ile aynı dizgileri eşler. $r_1$ daha kısa ve derli topludur, ama sonuçta $L(r_1) = L(r_2) = L$ olduğundan $r_1$ ve $r_2$ denk düzenli ifadelerdir.

## 7. Teorem: Düzenli İfadelerin Dilleri ile Düzenli Diller Aynıdır

Teorem:

$$\{\text{düzenli ifadelerin ürettiği diller}\} = \{\text{düzenli diller}\}.$$

Bu bir teoremdir, ispat gerekir. Bir küme eşitliği ispatlanırken ispat ikiye bölünür: önce birinci kümenin ikincinin alt kümesi olduğu ($\subseteq$), sonra birinci kümenin ikincinin üst kümesi olduğu ($\supseteq$) gösterilir.

- 1. kısım: $\{\text{düzenli ifade dilleri}\} \subseteq \{\text{düzenli diller}\}$. Düz bir dille: bir düzenli ifadeniz varsa onun dili düzenlidir.
- 2. kısım: $\{\text{düzenli diller}\} \subseteq \{\text{düzenli ifade dilleri}\}$. Yani her düzenli dil için bir düzenli ifade yazılabilir.

## 8. İspatın 1. Kısmı: Her Düzenli İfadenin Dili Düzenlidir

Her düzenli ifade $r$ için $L(r)$'nin düzenli olduğu, ifadenin boyutu üzerinde **tümevarımla** (proof by induction) ispatlanır.

### 8.1 Tümevarım tabanı

Taban üç ilkel ifadedir. Her biri için kolayca bir NFA yazılabilir, dolayısıyla dilleri düzenlidir (ekrandan, 01:00:00):

- $M_1$: yalnız bir başlangıç durumu var, kabul durumu yok. Hiçbir şeyi kabul etmez: $L(M_1) = \emptyset = L(\emptyset)$.
- $M_2$: başlangıç durumu aynı zamanda kabul durumudur, geçiş yoktur. Yalnız boş dizgiyi kabul eder: $L(M_2) = \{\varepsilon\} = L(\varepsilon)$.
- $M_3$: başlangıç durumundan $a$ ile bir kabul durumuna geçilir. Yalnız o tek sembolü kabul eder: $L(M_3) = \{a\} = L(a)$.

Böylece $\emptyset$, $\varepsilon$ ve tek sembol ifadelerinin dilleri düzenlidir.

### 8.2 Tümevarım hipotezi ve adımı

**Hipotez:** $r_1$ ve $r_2$ düzenli ifadeleri için $L(r_1)$ ve $L(r_2)$ düzenli dillerdir. Bu ispatlanmaz, varsayılır.

**Adım:** Bütün olası birleşimlerin dillerinin düzenli olduğu ispatlanır. Düzenli ifadeler artı, nokta, yıldız ve gruplama ile birleştirilebilir. Tanım gereği:

- $L(r_1 + r_2) = L(r_1) \cup L(r_2)$,
- $L(r_1 \cdot r_2) = L(r_1)L(r_2)$,
- $L(r_1^*) = (L(r_1))^*$,
- $L((r_1)) = L(r_1)$.

Geçen hafta düzenli dillerin birleşim, birleştirme ve yıldız altında kapalı olduğu görülmüştü. Hipotez gereği $L(r_1)$ ve $L(r_2)$ düzenli olduğundan bunların birleşimi, birleştirmesi ve yıldızı da düzenlidir. Gruplama ise doğrudan hipotezden düzenlidir (trivially regular). Bu, ispatın 1. kısmının sonudur.

Hoca ispatı baştan bir kez daha özetledi: tabanda ilkel ifadelerin dillerinin düzenli olduğu görüldü; hipotezde $r_1$, $r_2$'nin dillerinin düzenli olduğu varsayıldı; adımda tanım ve kapanış özellikleriyle işlemlerin dillerinin düzenli olduğu gösterildi. Bu dillere karşılık gelen NFA'lar da kolayca birleştirilebilir; örneğin artı birleşime karşılık gelir ve iki dilin birleşimini kabul eden NFA'nın nasıl kurulacağı geçen hafta görülmüştü. Bu yüzden derste tekrar edilmedi. İlkellerden başlayarak her düzenli ifade için bir NFA kurulabilir.

## 9. İspatın 2. Kısmı: NFA'dan Düzenli İfadeye Dönüşüm

Her düzenli dil $L$ için $L(r) = L$ olan bir düzenli ifade $r$ bulunduğu gösterilecek. Bunun için $L$'yi kabul eden bir NFA bir düzenli ifadeye dönüştürülür. Bütün düzenli diller bir NFA tarafından kabul edildiğinden, her NFA düzenli ifadeye çevrilebiliyorsa her düzenli dil için bir düzenli ifade vardır.

### 9.1 Tek kabul durumu ve genelleştirilmiş geçiş grafiği

$L$ düzenli olduğu için onu kabul eden bir NFA $M$ vardır. $M$'nin tek bir kabul durumu olduğu varsayılır; birden çok kabul durumu varsa tek kabul durumlu eşdeğer bir makine kurulabilir (geçen hafta görülmüştü).

$M$'den, geçiş etiketleri düzenli ifade olan eşdeğer bir **genelleştirilmiş geçiş grafiği** (generalized transition graph) kurulur. Basit örnek (ekrandan, 01:15:00):

```text
M:                                  Genelleştirilmiş geçiş grafiği:
başlangıç --a--> başlangıç (döngü)  başlangıç --a--> başlangıç (döngü)
başlangıç --a,b--> kabul            başlangıç --a+b--> kabul
kabul --c--> kabul (döngü)          kabul --c--> kabul (döngü)
```

Tek sembollü geçişler ($a$, $c$) değişmez. "$a, b$" etiketi (a ya da b ile geçiş) $a + b$ düzenli ifadesine çevrilir.

### 9.2 Örnek: ara durumu eleme

İkinci örnekteki NFA şöyledir (ekrandan, 01:20:00):

| Durum | $a$ | $b$ |
|---|---|---|
| $\to q_0$ | — | $q_1$ |
| $q_1$ | $q_0$, $q_2$ | $q_1$, $q_2$ |
| $q_2$ (kabul) | — | $q_2$ |

Genelleştirilmiş grafikte $q_1 \to q_2$ geçişinin "$a,b$" etiketi $a+b$ olur; diğer etiketler aynen kalır.

Genelleştirilmiş geçiş grafiğinde sonunda yalnız iki durum kalmalıdır: tek bir başlangıç ve tek bir kabul durumu. Burada üç durum var, bu yüzden $q_1$ elenmelidir. Bunun için $q_1$'den geçen bütün yollar düşünülüp yeni etiket olarak eklenir.

- **$q_0 \to q_1 \to q_0$ yolu:** Hoca önce bunu $(ba)^*$ olarak yazdı ($b$ ile $q_1$'e, $a$ ile $q_0$'a dönülür; döngü olduğu için yıldız). Bir öğrenci $q_1$'deki $b$ döngüsünün de hesaba katılması gerektiğini belirtti. Doğrusu: bir $b$ ile $q_1$'e gelinir, $q_1$'de istenen kadar $b$ okunur (hâlâ $q_1$'deyiz), sonra $a$ ile $q_0$'a dönülür. Bu, $q_0$ üzerinde $bb^*a$ döngüsü verir.
- **$q_0 \to q_1 \to q_2$ yolu:** bir $b$, sonra $q_1$'deki döngüden istenen kadar $b$, sonra $a+b$ ile $q_2$'ye geçiş: $bb^*(a+b)$.

$q_1$ kaldırılınca iki yeni düzenli ifade üretilmiş olur. Son grafik (ekrandan, 01:25:00):

```text
q0 --bb*a--> q0 (döngü)
q0 --bb*(a+b)--> q2
q2 --b--> q2 (döngü)
başlangıç: q0, kabul: q2
```

Son genelleştirilmiş grafikten düzenli ifade yazmak kolaydır: $q_0$'daki döngü gruplanıp yıldızlanır, sonra $q_0 \to q_2$ geçişi, sonra $q_2$'deki $b$ döngüsünün yıldızı:

$$r = (bb^*a)^*\,bb^*(a+b)\,b^*, \qquad L(r) = L(M) = L.$$

Böylece bir düzenli dilden (NFA'dan) başlanıp bir düzenli ifadeye ulaşıldı. Bu ifadenin NFA ile aynı dili verdiği, 12 uzunluğa kadar bütün dizgiler denenerek python ile kontrol edildi.

### 9.3 Genel durum eleme: iki komşu

Genel prosedürdeki en zor kısım bir durumu elemektir, çünkü sonunda yalnız iki durum (başlangıç ve kabul) kalmalıdır. Genel kural: elenen durumdan geçen bütün olası yollar düşünülür ve her biri için bir düzenli ifade yazılır.

İki komşulu durum için slayttaki genel durum (ekrandan, 01:30:00):

```text
Elenecek durum q, komşuları qi ve qj:
qi --a--> q        q --d--> qi
qj --c--> q        q --b--> qj
q  --e--> q (döngü)
```

$q$ elenince oluşan yeni etiketler:

| Yol | Yeni etiket |
|---|---|
| $q_i \to q \to q_i$ (döngü) | $ae^*d$ |
| $q_j \to q \to q_j$ (döngü) | $ce^*b$ |
| $q_i \to q \to q_j$ | $ae^*b$ |
| $q_j \to q \to q_i$ | $ce^*d$ |

Her yolda $q$'ya girilir, $q$'daki $e$ döngüsü istenen kadar kullanılır ($e^*$), sonra $q$'dan çıkılır. Durumlar tek tek elenir ve yollar bu şekilde birleştirilir.

Hoca bu iki durumlu sonuçtan ($q_i$ başlangıç, $q_j$ kabul) tek bir düzenli ifade yazmayı derste doğrudan denedi. Tahtada $(ae^*d)^*$ ile başlayıp $ae^*b$, $(ce^*b)^*$, $ce^*d$ parçalarını gruplayıp yıldızlayan çok uzun bir ifade oluştu (ekrandan, 01:30:00). Hoca ifadenin "çok büyük" olduğunu söyledi ve bu tür dönüşüm için kitaptan ya da internetten örnek bulup alıştırma yapılmasını önerdi.

<!-- BELİRSİZ: Tahtadaki elle yazılmış ifade tamamlanmadı ve karede tam okunmuyor; aşağıdaki sonuç 9.4'teki genel formülün uygulanmasıdır. -->

Bu grafiğe 9.4'teki genel formül $r_1 = ae^*d$, $r_2 = ae^*b$, $r_3 = ce^*d$, $r_4 = ce^*b$ ile uygulanırsa (ara adım eklendi):

$$r = (ae^*d)^*\,ae^*b\,\big(ce^*b + ce^*d\,(ae^*d)^*\,ae^*b\big)^*.$$

Bu ifadenin üç durumlu grafikle aynı dili verdiği python ile kontrol edildi.

**Üç komşu:** $q$'nun $q_i$, $q_k$, $q_j$ gibi üç komşusu varsa da aynı mantıkla $q$'dan geçen bütün yollar düşünülür.

<!-- BELİRSİZ: Üç komşu anlatımı (yaklaşık 01:31:30–01:32:25) altyazıda bozuk; ayrıntı aktarılamadı. -->

### 9.4 İki durum kalınca: genel düzenli ifade

Bu işlem yalnız iki durum kalana kadar tekrarlanır: başlangıç grafiğindeki bütün ara durumlar elenir. Sonuçta kalan genel grafik şöyledir (ekrandan, 01:35:00):

```text
q0 --r1--> q0 (döngü)
q0 --r2--> qf
qf --r3--> q0
qf --r4--> qf (döngü)
başlangıç: q0, kabul: qf
```

Bundan elde edilen düzenli ifade:

$$r = r_1^*\, r_2\, (r_4 + r_3 r_1^* r_2)^*, \qquad L(r) = L(M) = L.$$

Bu, yapıcı bir ispattır (proof by construction): NFA'ların düzenli ifadelere dönüştürülebildiği gösterilmiştir.

Hoca formülü dikkatlice tekrar okudu:

- $r_1^*$: başlangıç durumundaki döngü.
- $r_2$: kabul durumuna ($q_f$) geçiş.
- Kabul durumuna gelindikten sonra oradaki döngüler düşünülür. İki tür döngü vardır: doğrudan $r_4$ döngüsü (hâlâ kabul durumundayız) ve $r_3$ ile başlangıca dönüp orada istenen kadar $r_1$ yapıp $r_2$ ile tekrar kabul durumuna gelmek ($r_3 r_1^* r_2$).
- Bu ikisinin artısı (birleşimi) alınır ve üzerine yıldız konur; böylece iki tür döngü istenen sırada ve sayıda karıştırılabilir. Son işlem bu yıldızdır.

**Soru:** $r_4$'e de yıldız gerekmez mi? **Cevap:** Gerekmez, çünkü en dıştaki yıldız $r_4$'ün istenen sayıda tekrarlanmasını zaten sağlar.

> **Hocanın vurgusu:** Bu formülü ezberlemeyin, en azından mantığını anlayın. Hoca az önce elle yapmaya çalışırken zorlandığını, bu prosedür akılda olmadan elde edilen ifadenin gereğinden karmaşık olduğunu söyledi; ifade farklı biçimlerde yazılabilir ama slaytlardaki bu biçim en derli toplu olanıdır ve hoca da bunu önerir.

### 9.5 Teoremin tamamlanması

Bütün düzenli dillerin bir NFA'sı vardır ve her NFA bir düzenli ifadeye çevrilebilir. Demek ki her düzenli dil için onu üreten bir düzenli ifade bulunur: düzenli diller kümesi, düzenli ifade dilleri kümesinin alt kümesidir. Önceki adımda ters yönü de ispatlanmıştı. İki küme hem birbirinin alt kümesi hem de üst kümesi olduğuna göre denktir. Hoca, kümelerin denkliğinin böyle, iki yön de ispatlanarak gösterildiğini vurguladı.

## 10. Düzenli Dillerin Standart Gösterimleri

Düzenli diller şimdiye kadar üç şeyle gösterildi: DFA'lar, NFA'lar ve bu derste öğrenilen düzenli ifadeler. "Bize düzenli bir dil $L$ verildi" denildiğinde, $L$'nin standart bir gösterimle, yani bir DFA, NFA ya da düzenli ifade olarak verildiği kastedilir.

## 11. Düzenli Olmayan Diller ve Pompalama Önsavına Giriş

Aradan sonra yeni bir bölüme, **pompalama önsavına** (pumping lemma) geçildi.

Şimdiye kadar bir dilin düzenli olduğunu ispatlamak öğrenildi: o dil için bir NFA ya da DFA çizilir veya bir düzenli ifade yazılır. Bunu yapabiliyorsak dil düzenlidir. Peki bir dilin düzenli **olmadığı** nasıl ispatlanır?

Slayttaki şemada düzenli diller kümesi ($a^*b$, $b^*c+a$, $b+c(a+b)^*$ gibi) daha geniş bir dil evreni içinde gösterilir (ekrandan, 02:00:00). Bazı diller düzenli değildir:

- $\{a^n b^n : n \ge 0\}$: önce bazı $a$'lar, sonra bazı $b$'ler, ama $a$ ve $b$ sayısı eşit ($ab$, $aabb$, $aaabbb$, ...). Bunun için DFA ya da NFA yazılamaz.
- Bir dizginin ardından tersinin geldiği dizgiler: $abba$, $aabbaa$ gibi. Bu da düzenli değildir.

Bir dilin düzenli olmadığını, onu kabul eden hiçbir DFA, NFA ya da düzenli ifade bulunmadığını göstererek ispatlamak kolay değildir, çünkü sonsuz sayıda DFA ve NFA vardır. Hoca bunu şöyle anlattı: bir NFA yazıp "bu uymuyor", bir tane daha yazıp "bu da uymuyor" demek gerekirdi; sonsuz sayıda NFA'nın hepsini yazıp hiçbirinin dili kabul etmediğini göstermek mümkün değildir. Burada pompalama önsavı yardımcı olur.

## 12. Güvercin Yuvası İlkesi ve DFA Yürüyüşleri

### 12.1 Güvercin yuvası ilkesi

Pompalama önsavı çok basit bir ilkeye dayanır: **güvercin yuvası ilkesi** (pigeonhole principle). Örneğin dört güvercin ve yalnız üç güvercin yuvası olsun. Güvercinler yuvalara dağıtılırsa en az bir yuvada en az iki güvercin bulunur. Güvercin sayısı yuva sayısından fazladır.

### 12.2 4 durumlu bir DFA'da yürüyüş

Derste kullanılan DFA'nın geçişleri (ekrandan, 02:05:00 ve 02:10:00):

| Durum | $a$ | $b$ |
|---|---|---|
| $\to q_1$ | $q_2$ | $q_1$ |
| $q_2$ | $q_3$ | $q_2$ |
| $q_3$ | $q_2$ | $q_4$ |
| $q_4$ (kabul) | $q_3$ | $q_4$ |

Uzunluğu durum sayısından (4) fazla olan "uzun" bir dizgi düşünülür: $aaaab$ (5 sembol). Bir dizginin **yürüyüşü** (walk), semboller okundukça hangi geçişlerin olduğu, yani hangi durumlardan geçildiğidir:

$$q_1 \xrightarrow{a} q_2 \xrightarrow{a} q_3 \xrightarrow{a} q_2 \xrightarrow{a} q_3 \xrightarrow{b} q_4$$

İlk $a$ ile $q_2$'ye gelinir (ilk ziyaret), ikinci $a$ ile $q_3$'e, üçüncü $a$ ile tekrar $q_2$'ye (ikinci ziyaret), dördüncü $a$ ile $q_3$'e, son $b$ ile kabul durumu $q_4$'e. $q_2$ tekrar etmiştir ($q_3$ de tekrar eder, ama yalnız $q_2$'ye odaklanılır).

Slayttaki eşleme (ekrandan, 02:10:00): güvercinler yürüyüşteki durumlardır, yuvalar otomatın durumlarıdır. Yürüyüşte 6 durum var, otomatta 4 durum var; bu yüzden en az bir durum (burada $q_2$ ve $q_3$) birden fazla ziyaret edilir.

Hoca derste bu slaytı düzeltmeye çalıştı: yuvaların durumlar değil "tekil geçişler" olması gerektiğini söyledi. 4 durum arasında (döngüler sayılmazsa) 3 ayrı geçiş vardır, her sembol bir geçiş ister; 4 sembol varsa bir geçiş ya da döngü tekrar kullanılmak zorundadır. Döngüler bu sayıma katılmaz, çünkü döngü kullanıldığında zaten o durum tekrar edilmiş olur.

> **Ders sonrası not:** Slayttaki ilk eşleme (güvercin = yürüyüşteki durumlar, yuva = otomat durumları) kendi başına doğrudur ve standart olanıdır: $|w|$ sembollük bir dizginin yürüyüşünde $|w|+1$ durum vardır; $|w| \ge p$ ise $|w|+1 > p$ olur ve güvercin yuvası ilkesiyle bir durum tekrar eder.

İkinci örnekte aynı DFA'da dört sembollü $aabb$ dizgisi kullanılır. Yürüyüş (python ile kontrol edildi):

$$q_1 \xrightarrow{a} q_2 \xrightarrow{a} q_3 \xrightarrow{b} q_4 \xrightarrow{b} q_4$$

İlk üç sembol üç farklı geçiş kullanır; dördüncü sembol için bir geçiş daha gerekir ve bu $q_4$'teki döngüyle olur. Burada $q_4$ tekrar eder. Yani dizgi uzunluğu durum sayısına eşit ya da daha büyükse en az bir durum tekrar eder.

### 12.3 Genel durum

Genel olarak (ekrandan, 02:15:00): $|w| \ge$ DFA'nın durum sayısı ise, güvercin yuvası ilkesiyle $w$'nin yürüyüşünde bir durum tekrar eder. $w = \sigma_1 \sigma_2 \cdots \sigma_k$ olsun; her sembol bir geçişin üzerine yazılır. Dizgi kabul ediliyorsa yürüyüşte bir $q_i$ tekrar eder: başta bazı semboller okunur, $q_i$'ye gelinir, belki başka durumlardan geçilerek (ya da geçilmeden) $q_i$ üzerinde bir döngü yapılır, sonra devam edilip bir kabul durumunda bitirilir.

Sembollerle: $p$ DFA'nın durum sayısı olsun. $|w| \ge p$ ise yürüyüşte yer alan durum sayısı en az $p+1$'dir ve bir durum tekrar eder.

## 13. Pompalama Önsavı

### 13.1 Sonsuz düzenli dil ve $w = xyz$ ayrışımı

Sonsuz bir düzenli dil $L$ alınır. Sonsuz demek elemanlarının sayısının sonsuz olması demektir; dolayısıyla dilde çok uzun dizgiler vardır. $L$'yi kabul eden ve $p$ durumu olan bir DFA olsun. $L$'den $|w| \ge p$ olan bir $w$ dizgisi alınırsa $w$'nin yürüyüşünde en az bir durum tekrar eder. Birden fazla durum tekrar edebilir; $q$ **ilk tekrar eden** durum olsun.

$q$'nun ikinci kez görülmesine kadar durumlar tekildir, çünkü $q$ ilk tekrardır. Buna göre $w$ üç parçaya ayrılır (ekrandan, 02:20:00):

- $x = \sigma_1 \cdots \sigma_i$: başlangıçtan $q$'nun ilk görülüşüne kadar okunan semboller,
- $y = \sigma_{i+1} \cdots \sigma_j$: $q$'nun ilk ve ikinci görülüşü arasındaki semboller,
- $z = \sigma_{j+1} \cdots \sigma_k$: geri kalan semboller; son sembol okununca kabul durumuna ulaşılır.

$y$, $q$'dan $q$'ya dönen bir döngüdür; bu yüzden tekrarlanabilir. $y$ tekrarlandığında yine $q$'ya dönülür ve $z$ okununca kabul durumuna ulaşılır.

### 13.2 Gözlemler

- $|xy| \le p$: $q$ ilk tekrar eden durum olduğu için, $q$'nun ikinci görülüşüne kadar kullanılan sembol sayısı en fazla $p$'dir.
- $|y| \ge 1$: bir döngü için en az bir sembol gerekir. Doğrudan bir döngüde $|y| = 1$, başka durumlardan geçen bir döngüde daha uzundur.
- $z$'nin biçimi önemli değildir: $z$, $x$ ve $y$'nin yollarıyla çakışabilir; $z$ okunurken yine $x$'in durumlarına dönülebilir, $y$ yeniden tekrarlanabilir ya da $y$'den sonra başka döngüler olabilir (ekrandan, 02:25:00).

### 13.3 Pompalama

- $y$ hiç kullanılmazsa ($xz$): $x$ ile $q$'ya gelinir, kalan $z$ ile kabul durumuna ulaşılır; $xz$ kabul edilir.
- $y$ iki kez kullanılırsa ($xyyz$): $x$ ile $q$'ya, $y$ ile $q$'ya, ikinci $y$ ile yine $q$'ya gelinir; $z$ ile kabul durumuna ulaşılır.
- Genel olarak sıfır, bir, iki, on, istenen sayıda $y$ kullanılsa da $q$'da kalınır ve $z$ ile kabul durumuna varılır.

Dolayısıyla $xy^iz$ biçimindeki bütün dizgiler, $i = 0, 1, 2, \dots$ için, DFA'nın dilindedir.

### 13.4 Önsavın ifadesi

> **Hocanın vurgusu:** Pompalama önsavının bu ifadesini bilmeniz gerekiyor.

Slayttaki ifade (ekrandan, 02:30:00):

- Sonsuz bir düzenli dil $L$ verilsin.
- Bir $p$ tamsayısı (kritik uzunluk) vardır öyle ki
- $|w| \ge p$ uzunluğundaki her $w \in L$ dizgisi için
- $w = xyz$ yazılabilir,
- öyle ki $|xy| \le p$ ve $|y| \ge 1$,
- ve $xy^iz \in L$, $i = 0, 1, 2, \dots$

## 14. Pompalama Önsavı ile İspatın Genel Mantığı

Pompalama önsavı neden öğrenildi ve nasıl kullanılır?

Önce, sonlu (sonsuz olmayan) her dil düzenlidir; böyle bir dili kabul eden DFA ya da NFA kolayca kurulabilir. Bu yüzden sonlu diller dikkate alınmaz. Bunun sonucu: bir dil düzenli değilse sonsuzdur.

Sonsuz bir $L$ dilinin düzenli olmadığı ispatlanmak istensin. Bunun için **olmayana ergi** (proof by contradiction) kullanılır:

1. İspatlanmak istenen "$L$ düzenli değildir" olduğu için tersi varsayılır: $L$ düzenlidir.
2. Pompalama önsavının bu dil için sağlanıp sağlanmadığına bakılır; önsav kullanılarak bir çelişki elde edilmeye çalışılır.
3. Çelişki bulununca: başta $L$ düzenli varsayılmıştı, ama çelişki çıktı; dolayısıyla $L$ düzenli değildir.

Çelişkinin önsavla tam olarak nasıl elde edileceği ve örnekler bir sonraki derse bırakıldı.

## Örnek Sorular

**Soru 1** (ekrandan, 00:25:00): $L((a+b)\cdot a^*)$ dilini bulunuz.

> **Çözüm (derste verildi):** $L((a+b))L(a^*) = (L(a)\cup L(b))(L(a))^* = \{a,b\}\{\varepsilon,a,aa,\dots\} = \{a, aa, aaa, \dots, b, ba, baa, \dots\}$. Tek bir $a$ ya da tek bir $b$, ardından istenen sayıda $a$.

**Soru 2** (ekrandan, 00:35:00): $r = (a+b)^*(a+bb)$ düzenli ifadesinin dili nedir?

> **Çözüm (derste verildi):** $a$ ile ya da $bb$ ile biten bütün dizgiler: $\{a, bb, aa, abb, ba, bbb, \dots\}$. Bu, 10 uzunluğa kadar bütün dizgiler denenerek python ile kontrol edildi.

**Soru 3** (derste sözlü, 00:31:00): Soru 2'deki dil $a^n b^m$ gibi üstel bir gösterimle yazılabilir mi?

> **Cevap (derste verildi):** Kolayca yazılamaz; $(a+b)^*$ kısmı $a$ ve $b$'leri istenen sırada karıştırdığı için $a^n b^m a^k b^p\dots$ türü denemeler bütün dizgileri kapsamaz. Hoca böyle bir gösterim bulamadığını söyledi. Bu, dilin düzensiz olduğu anlamına gelmez; düzenli ifadesi olduğu için dil düzenlidir.

**Soru 4** (ekrandan, 00:30:00): $r = (aa)^*(bb)^*b$ ifadesinin dilini küme gösterimiyle yazınız.

> **Çözüm (derste verildi):** $L(r) = \{a^{2n} b^{2m} b : n, m \ge 0\}$.

**Soru 5** (derste sözlü, 00:38:36): $r = (1+01)^*(0+\varepsilon)$ ifadesinde sondaki $\varepsilon$ neden gereklidir?

> **Cevap (derste verildi):** $\varepsilon$ olmasaydı eşlenen her dizgi $0$ ile bitmek zorunda kalırdı ve örneğin $1111$ eşlenmezdi. $\varepsilon$, $1$ ile biten dizgilerin de eşlenmesini sağlar.

**Soru 6** (ekrandan, 00:55:00): $r_1 = (1+01)^*(0+\varepsilon)$ ve $r_2 = (1^*011^*)^*(0+\varepsilon) + 1^*(0+\varepsilon)$ denk midir?

> **Çözüm (derste verildi):** Evet. İkisi de $00$ alt dizgisini içermeyen bütün dizgileri eşler, yani $L(r_1) = L(r_2)$. Python ile 12 uzunluğa kadar bütün ikili dizgiler denenerek iki ifadenin de bu dili verdiği doğrulandı.

**Soru 7** (ekrandan, 01:20:00): 9.2'deki NFA'yı ($q_0 \xrightarrow{b} q_1$, $q_1 \xrightarrow{a} q_0$, $q_1$'de $b$ döngüsü, $q_1 \xrightarrow{a,b} q_2$, $q_2$'de $b$ döngüsü; kabul $q_2$) düzenli ifadeye çeviriniz.

> **Çözüm (derste verildi):** "$a,b$" → $a+b$. $q_1$ elenince $q_0$ üzerinde $bb^*a$ döngüsü, $q_0 \to q_2$ için $bb^*(a+b)$ oluşur. Sonuç $r = (bb^*a)^*bb^*(a+b)b^*$ (ekrandan, 01:25:00).

**Soru 8** (ekrandan, 02:05:00): 12.2'deki DFA'da $aaaab$ dizgisinin yürüyüşünü yazınız; hangi durum tekrar eder?

> **Çözüm (derste verildi):** $q_1 \to q_2 \to q_3 \to q_2 \to q_3 \to q_4$. $q_2$ ve $q_3$ tekrar eder; dizgi kabul edilir.

## Dersin Toparlaması

Bu derste düzenli ifadeler tanıtıldı: ilkel ifadeler ($\emptyset$, $\varepsilon$, tek sembol) ve artı, birleştirme, yıldız, gruplama işlemleriyle özyinelemeli olarak tanımlandılar; her ifadenin dili dört kuralla dıştan içe parçalanarak bulundu. Ardından düzenli ifadelerin dilleriyle düzenli dillerin aynı küme olduğu iki yönlü ispatlandı: bir yönde ifade boyutu üzerinde tümevarım ve kapanış özellikleri, diğer yönde NFA'yı genelleştirilmiş geçiş grafiğine çevirip ara durumları eleyerek $r = r_1^* r_2 (r_4 + r_3 r_1^* r_2)^*$ biçimine indirgeyen yapıcı ispat kullanıldı. Böylece düzenli dillerin üç standart gösterimi (DFA, NFA, düzenli ifade) tamamlandı.

Son bölümde bir dilin düzenli olmadığını göstermek için pompalama önsavına giriş yapıldı. Güvercin yuvası ilkesinden yola çıkılarak uzun bir dizginin DFA yürüyüşünde bir durumun tekrar etmesi gerektiği, bundan $w = xyz$ ayrışımı ve $xy^iz \in L$ sonucu çıkarıldı. Önsavı kullanarak olmayana ergi ile bir dilin (örneğin $a^n b^n$) düzenli olmadığını ispatlama yöntemi ve örnekleri bir sonraki derste ele alınacak.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
