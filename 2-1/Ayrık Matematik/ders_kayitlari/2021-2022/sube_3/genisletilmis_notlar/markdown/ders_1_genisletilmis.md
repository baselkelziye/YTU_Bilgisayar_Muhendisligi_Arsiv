# Ders 1 Genişletilmiş Notu: Önermeler Mantığı: Bağlaçlar, Koşullu Önermeler, Totoloji, De Morgan ve Niceleyiciler

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Mantık Neden Gerekli?
- 2. Önerme ve Doğruluk Tablosu
- 3. Temel Bağlaçlar: AND, OR, NOT
- 4. XOR (Ya Da)
- 5. Birden Fazla Önermenin Birleştirilmesi
- 6. Koşullu Önerme (İse)
- 7. Karşıt, Ters ve Devrik
- 8. Gereklilik ve Yeterlilik, Mantıksal Denklik
- 9. Ancak ve Ancak (Çift Yönlü Koşullu Önerme)
- 10. Totoloji ve Çelişki
- 11. De Morgan Kanunu
- 12. Niceleyiciler
- Örnek Sorular
- Dersin Toparlaması

## 1. Mantık Neden Gerekli?

Ders Zoom üzerinden yapıldı; hoca PowerPoint'te slaytları gösterdi ve kalem ile siyah zeminli boş slaytlara yazarak anlattı. Konu "Mantık ve İspat" bölümüdür.

Mantık, doğru çıkarım (inference) yapmayla ilgilenir. Matematikte en çok ispatlarda kullanılır. Hoca örnek olarak $1 + 2 + \dots + n = \frac{n(n+1)}{2}$ eşitliğini verdi: bu eşitliğin doğru olup olmadığını göstermek için ispat tekniklerine, ispat tekniklerini öğrenmek için de mantığa ihtiyaç vardır.

Bilgisayar biliminde mantık, bir programın kendisinden bekleneni üretip üretmediğini incelemekte ve koşullu ya da tekrarlı yapılarda yazılan mantıksal ifadelerde karşımıza çıkar. Önermeler hem donanım düzeyinde hem yazılım düzeyinde analiz ve algoritma geliştirmede kullanılır.

## 2. Önerme ve Doğruluk Tablosu

### 2.1 Önerme

Önerme (proposition), bir hüküm içeren ve sonucu ya doğru ya yanlış olan ifadedir. Burada olasılığa yer yoktur. "Cüneyt programcıdır" bir önermedir: Cüneyt gerçekten programcıysa doğru, değilse yanlıştır. Hüküm içermeyen bir ifade ise önerme değildir.

Tek bir önerme çoğu zaman yeterli olmaz. Hocanın örneğinde bir öğrencinin geçip kalmasına hem devamsızlık hem not birlikte karar veriyorsa iki önermeyi bir arada kullanmak gerekir:

- $p$: "Öğrencinin devamsızlığı 20'den azdır."
- $q$: "Öğrencinin dönem sonu notu 40'tan büyük ya da eşittir."

Önermeler $p, q, r, s, t$ gibi harflerle gösterilir. Önermeleri birleştiren işlemlere bağlaç (connective) denir.

### 2.2 Doğruluk tablosu

İki önermenin her biri doğru ya da yanlış olabileceğinden dört farklı durum vardır. Bütün durumların incelendiği tabloya doğruluk tablosu (truth table) denir. Hoca önce T/F ile, sonra T = 1, F = 0 kodlamasıyla yazdı (ekrandan, 00:20:00) ve bit gösterimini daha kolay bulduğunu söyledi.

| $p$ | $q$ |
|:-:|:-:|
| 0 | 0 |
| 0 | 1 |
| 1 | 0 |
| 1 | 1 |

Tablo ikilik sayma düzeniyle kurulur: en sağdaki sütun her satırda, bir soldaki iki satırda bir, bir sonraki dört satırda bir değişir; yani basamak değerleri $2^0, 2^1, 2^2$'dir. $p, q, r$ için $r$ sütunu $0,1,0,1,0,1,0,1$, $q$ sütunu $0,0,1,1,0,0,1,1$, $p$ sütunu $0,0,0,0,1,1,1,1$ olur. $n$ önerme için $2^n$ satır vardır.

> **Hocanın vurgusu:** Slaytlardaki tablolar T T'den (1 1'den) başlıyor. Hoca sınavlarda kolaylık için tabloyu 0 0'dan başlatmayı önerdi; lojik devreler dersinde Karnaugh haritalarında da bu düzen kullanılacak.

## 3. Temel Bağlaçlar: AND, OR, NOT

### 3.1 AND (ve, conjunction)

$p \land q$, ancak iki önerme de doğruysa doğrudur; en az biri yanlışsa sonuç yanlıştır.

| $p$ | $q$ | $p \land q$ |
|:-:|:-:|:-:|
| 0 | 0 | 0 |
| 0 | 1 | 0 |
| 1 | 0 | 0 |
| 1 | 1 | 1 |

Hoca bunu bir elektrik devresiyle anlattı: $S_1, S_2, \dots, S_n$ anahtarları seri bağlı olsun. $n$ anahtar için $2^n$ durum incelenmelidir. Akımın geçmesi (lambanın yanması) için

$$I \iff (S_1 = 1) \land (S_2 = 1) \land \dots \land (S_n = 1)$$

olmalıdır. $00\dots0$'dan $11\dots1$'e kadar olan $2^n$ durumdan yalnız sonuncusu 1 verir.

Slayttaki örnek: "Kaplan vahşi bir hayvandır" doğru, "Balina bir sürüngendir" yanlış; bu yüzden ikisinin AND'i yanlıştır. Bu tür sorularda sözel önermeler verilip mantıksal ifadesinin yazılması istenebilir.

### 3.2 OR (veya, inclusive or, disjunction)

$p \lor q$, önermelerden en az biri doğruysa doğrudur; hepsi yanlışsa yanlıştır. AND'e göre daha "gevşek" bir bağlaçtır.

| $p$ | $q$ | $p \lor q$ |
|:-:|:-:|:-:|
| 0 | 0 | 0 |
| 0 | 1 | 1 |
| 1 | 0 | 1 |
| 1 | 1 | 1 |

(ekrandan, 00:25:00)

**Soru:** Bunu elektrik devresiyle göstermek için öncekinden neyi değiştirmeliyiz? **Cevap:** Anahtarları paralel bağlamalıyız. Bu durumda $(S_1 = 1) \lor (S_2 = 1) \lor \dots \lor (S_n = 1)$ ise akım geçer ve lamba yanar.

Slayttaki örnek: "Cüneyt bir programcıdır veya Zeynep avukattır." Biri doğruysa bileşik önerme doğrudur; ikisi de yanlışsa yanlıştır.

### 3.3 NOT (değil, negation)

NOT, tek bir operand alan (unary) bir işlemdir; doğruysa yanlış, yanlışsa doğru yapar. AND ve OR ise iki ya da daha çok operand alabilir. Gösterimleri $\lnot p$, $\sim p$, $\bar{p}$ ve $p'$ biçimindedir.

| $p$ | $\lnot p$ |
|:-:|:-:|
| 0 | 1 |
| 1 | 0 |

> **Hocanın vurgusu:** Değil alırken ifadenin mantıksal olarak tamamen tersi alınmalıdır. $p$: "$x > 2$" ise $\lnot p$: "$x \le 2$"dir. Hatalar genelde bu tür nüanslardan yapılır.

### 3.4 Bağlaçların birlikte kullanımı: $\lnot p \lor q$

İşlem önceliğinde NOT önce gelir, sonra OR uygulanır. İsterseniz $\lnot p$ ara sütun olarak yazılabilir:

| $p$ | $q$ | $\lnot p$ | $\lnot p \lor q$ |
|:-:|:-:|:-:|:-:|
| 0 | 0 | 1 | 1 |
| 0 | 1 | 1 | 1 |
| 1 | 0 | 0 | 0 |
| 1 | 1 | 0 | 1 |

Devamsızlık örneğine dönersek, bu ifade "devamsızlık 20 ya da daha fazla veya not 40'tan büyük ya da eşit" anlamına gelir.

Hoca AND, OR ve NOT'ı mantığın üç temel bağlacı olarak tanımladı. XOR, ise (implication) ve ancak ve ancak (double implication) bunlardan türetilir.

### 3.5 AND ve OR özdeşlikleri

Hoca öğrencilerle birlikte şunları buldu:

- $p \land 0 = 0$ (bir tane 0 yeterli), $p \land 1 = p$, $p \land p = p$, $p \land \lnot p = 0$.
- $p \lor 1 = 1$, $p \lor 0 = p$, $p \lor p = p$, $p \lor \lnot p = 1$.
- $p \land q = q \land p$, $p \lor q = q \lor p$.

**Soru:** $p \land q$ ile $q \land p$ eşit midir? **Cevap (bir öğrenci):** Evet, çarpma gibi olduğu için yer değiştirebilir. Hoca bunu onayladı: anahtarların ya da önermelerin yerinin değişmesi sonucu değiştirmez; bu bağlaçlar değişme özelliğini sağlar.

## 4. XOR (Ya Da)

### 4.1 Tanım

XOR (exclusive or) $\veebar$ ya da $\oplus$ ile gösterilir (ekrandan, 00:30:00). Girişler aynıysa sonuç 0, farklıysa 1'dir. Türkçe karşılığı "ya da"dır: ya şu ya bu, ikisi birden değil. Hoca bunu kümelerdeki simetrik farka benzetti.

| $p$ | $q$ | $p \oplus q$ | $(\lnot p \land q) \lor (p \land \lnot q)$ |
|:-:|:-:|:-:|:-:|
| 0 | 0 | 0 | 0 |
| 0 | 1 | 1 | 1 |
| 1 | 0 | 1 | 1 |
| 1 | 1 | 0 | 0 |

(ekrandan, 00:35:00)

### 4.2 XOR'un temel bağlaçlarla yazılışı

Tablodaki 0'lar göz ardı edilir ve 1 veren satırlara bakılır. $p=0, q=1$ satırı $\lnot p \land q$, $p=1, q=0$ satırı $p \land \lnot q$ ile ifade edilir. Bu iki durumdan biri olması yeterli olduğu için aralarına OR konur:

$$p \oplus q \equiv (\lnot p \land q) \lor (p \land \lnot q)$$

İki ifadenin tablo sonuçları birebir aynı olduğundan bunlar mantıksal olarak denktir (logically equivalent). Böylece XOR, temel AND, OR ve NOT bağlaçlarıyla yazılmış olur. Hoca sağdaki ifadenin tablosunu doldurmayı öğrencilere bıraktı; yukarıdaki son sütun bu doğrulamadır (python ile kontrol edildi).

**Soru:** Bu ifadenin Karnaugh haritasıyla bulunmuş daha sade bir hâli var mı? **Cevap:** Yok, en sade hâli budur; Karnaugh haritasında da bu çıkar.

### 4.3 Kriptografide XOR

Mesaj 0 ve 1'lerden oluşsun ve mesaj uzunluğunda bir anahtar (key) olsun (ekrandan, 00:35:00):

- Şifreli mesaj $=$ mesaj $\oplus$ anahtar
- Çözülmüş mesaj $=$ şifreli mesaj $\oplus$ anahtar

Şifreli mesaj aynı anahtarla tekrar XOR'lanınca özgün mesaj elde edilir. Bu yüzden XOR kriptolojide çok kullanılan bir işlemdir.

> **Ek bilgi (derste anlatılmadı):** Bunun nedeni $m \oplus k \oplus k = m \oplus (k \oplus k) = m \oplus 0 = m$ olmasıdır; XOR birleşme özelliğini sağlar ve her bit kendisiyle XOR'lanınca 0 olur.

Hoca XOR için iki konumlu anahtarlarla bir devre çizmeye çalıştı; bağlantıyı tam kuramadı ve daha uygun bir çizimi sonra paylaşacağını söyledi. Devrenin özelliği girişler aynıyken çıkışın 0, farklıyken 1 olmasıdır.

### 4.4 XOR özdeşlikleri

Ekrandaki liste (ekrandan, 00:40:00):

- $p \oplus q = q \oplus p$ (değişme)
- $p \oplus p = 0$: iki giriş aynı olduğundan.
- $p \oplus \lnot p = 1$: girişler hep farklı olduğundan.
- $p \oplus 1 = \lnot p$: $p=0$ iken sonuç 1, $p=1$ iken 0. Bir bit dizisini 1'lerle XOR'lamak onu ters çevirir (inverse). Örneğin $010111$ dizisi $111111$ ile XOR'lanınca $101000$ olur.
- $p \oplus 0 = p$: kendisini kopyalama (aynalama, mirror).

**Soru:** $p \oplus 1$ neden $\lnot p$'dir? Bir öğrenci "1'in tam tersi olması lazım" dedi; hoca açıklamayı düzeltti: $p$ 0 olabilir ya da 1 olabilir. $p=0$ iken sonuç 1, $p=1$ iken sonuç 0 olur; yani sonuç her durumda $\lnot p$'dir.

## 5. Birden Fazla Önermenin Birleştirilmesi

Slaytta $p, q, r$ basit önermeleri ile kurulan birleşik önerme örnekleri vardı (ekrandan, 00:45:00): $(p \lor q) \land r$, $p \lor (q \land r)$, $(\lnot p) \lor (\lnot q)$, $(p \lor q) \land (\lnot r)$. Bu tür sorularda $p, q, r$ sözel olarak verilip ifadenin sözel hâlinin yazılması ya da bir cümleden ifadenin çıkarılması istenebilir.

### 5.1 Örnek: $(p \lor q) \land r$

Üç değişken olduğu için $2^3 = 8$ durum vardır. Hoca tabloyu iki adımda doldurdu:

1. $r = 0$ olan bütün satırlar doğrudan 0'dır, çünkü AND'de bir tane 0 yeterlidir.
2. $r = 1$ olan satırlarda sonuç $p \lor q$'nun değerine eşittir; yalnız $p = q = 0$ satırı 0 kalır.

| $p$ | $q$ | $r$ | $p \lor q$ | $(p \lor q) \land r$ |
|:-:|:-:|:-:|:-:|:-:|
| 0 | 0 | 0 | 0 | 0 |
| 0 | 0 | 1 | 0 | 0 |
| 0 | 1 | 0 | 1 | 0 |
| 0 | 1 | 1 | 1 | 1 |
| 1 | 0 | 0 | 1 | 0 |
| 1 | 0 | 1 | 1 | 1 |
| 1 | 1 | 0 | 1 | 0 |
| 1 | 1 | 1 | 1 | 1 |

Slayttaki tablo $111$'den $000$'a doğru sıralanmıştı; yukarıda hocanın önerdiği 0'dan başlayan sırayla verildi (python ile kontrol edildi). Hoca $p \lor (q \land r)$ tablosunu da denemeyi önerdi.

## 6. Koşullu Önerme (İse)

### 6.1 Tanım

Koşullu bağlaçların (conditional operators) tek yönlü olanı "ise"dir (if, implication, ima), $p \Rightarrow q$ biçiminde yazılır (ekrandan, 00:50:00). $p$ hipotez, $q$ sonuçtur; sonucun olması hipoteze bağlıdır. İspat yöntemlerinde bu bağlaçtan çok yararlanılır.

| $p$ | $q$ | $p \Rightarrow q$ |
|:-:|:-:|:-:|
| 0 | 0 | 1 |
| 0 | 1 | 1 |
| 1 | 0 | 0 |
| 1 | 1 | 1 |

(ekrandan, 00:55:00)

Hocanın örneği: "Seçilirsem maaşlara zam yaparım."

- Seçilmedim, zam yapmadım: tutarsızlık yok, 1.
- Seçilmedim ama zam yaptım: yine 1.
- Seçildim ve zam yaptım: tutarlı, 1.
- Seçildim ama zam yapmadım: 0.

> **Hocanın vurgusu:** Tabloyu kısa yoldan öğrenmek için yalnız "1 ise 0" durumunu hatırlayın: hipotez gerçekleşmiş ama sonuç gerçekleşmemişse sonuç 0'dır, diğer üç durum 1'dir.

Hipotez ve sonuç için başka adlar da kullanılır: hipotez için antecedent, sonuç için consequent ya da conclusion.

**Soru:** Sonuç doğruysa hipotezin doğru olup olmaması önemli midir? **Cevap:** Değildir; $q=1$ olan iki satırda da sonuç 1'dir. Ancak hipotez doğruyken sonuç yanlış olabilir ve bu durumda önerme yanlıştır (ekrandaki not: "Sonuç doğruysa hipotez önemli değil; hipotez doğruyken sonuç yanlış olabilir").

### 6.2 $p \Rightarrow q$ ile $q \Rightarrow p$ denk değildir

**Soru:** $p \Rightarrow q$, $q \Rightarrow p$'ye mantıksal olarak denk midir? **Cevap (bir öğrenci):** Hayır; yerler değişince $01$ satırındaki sonuç $10$ satırına kayar. Hoca örnekle açıkladı: "Seçilirsem zam yaparım" önermesi, "zam yaptıysam seçilmişimdir" anlamına gelmez, çünkü seçilmeden zam yapma durumu da vardır. Hipotez ve sonuç yer değiştiremez; bu bağlaç AND ve OR gibi değişme özelliği sağlamaz.

### 6.3 İse bağlacının temel bağlaçlarla yazılışı

Bir öğrenci önerdi, hoca onayladı:

$$p \Rightarrow q \equiv \lnot p \lor q$$

Türetme: Sonucun 0 olduğu tek satır $p=1, q=0$, yani $p \land \lnot q$'dur. Önermenin geri kalan bütün durumlarda 1 olması, bu satırın değilinin alınmasıyla ifade edilir: $p \Rightarrow q \equiv \lnot(p \land \lnot q)$ (ekranda $(p \land q')'$). De Morgan kuralıyla açılınca $\lnot p \lor q$ bulunur.

> **Hocanın vurgusu:** Bu dönüşümü bilmek çok önemlidir. "İse" gördüğünüzde $\lnot p \lor q$ biçimine çevirerek, $\lnot p \lor q$ gördüğünüzde de "ise" biçimini düşünerek problem çözebilirsiniz. Bir cümlede "ise" anlamı gizli olabilir.

### 6.4 İse özdeşlikleri

Ekranda yazılanlar (ekrandan, 01:00:00):

- $p \Rightarrow p \equiv 1$: $p$ ve $p$ ya $00$ ya $11$ olur, iki durumda da sonuç 1'dir. "Seçildiysem seçilmişimdir" gibi.
- $p \Rightarrow \lnot p \equiv \lnot p$: $p=0$ iken $0 \Rightarrow 1 = 1$, $p=1$ iken $1 \Rightarrow 0 = 0$.
- $p \Rightarrow 1 \equiv 1$: sonuç 1 olduğunda önerme her zaman 1'dir.
- $p \Rightarrow 0 \equiv \lnot p$: $0 \Rightarrow 0 = 1$, $1 \Rightarrow 0 = 0$.

Derste bir öğrenci $p \Rightarrow 1$ için önce "$p$" dedi, sonra düzeltti; hoca iki durumu tek tek yazarak sonucun her zaman 1 olduğunu gösterdi. $p \Rightarrow 0$ için de bir öğrenci "$p$" dedi; hoca sonucun $\lnot p$ olduğunu gösterdi.

## 7. Karşıt, Ters ve Devrik

$p \Rightarrow q$ önermesinden üç önerme türetilir (ekrandan, 01:15:00):

- Converse (karşıt): $q \Rightarrow p$
- Inverse (ters): $\lnot p \Rightarrow \lnot q$
- Contrapositive (devrik): $\lnot q \Rightarrow \lnot p$; yer değiştirip ikisinin de değili alınır.

Örnek: $p$: "Bugün cumartesi", $q$: "Yarın pazar"; önerme "Bugün cumartesi ise yarın pazardır."

- Karşıt: "Yarın pazar ise bugün cumartesidir."
- Ters: "Bugün cumartesi değilse yarın pazar değildir."
- Devrik: "Yarın pazar değilse bugün cumartesi değildir."

Derste öğrencilerin ilk denemeleri karışınca hoca, önce $p$ ve $q$'nun ne olduğunu belirleyip sonra kalıba yerleştirmeyi önerdi. Bu türevler ispat konusunda kullanılacak.

Devrik önermenin tablosu (ekrandan, 01:25:00):

| $p$ | $q$ | $p \Rightarrow q$ | $\lnot q \Rightarrow \lnot p$ |
|:-:|:-:|:-:|:-:|
| T | T | T | T |
| T | F | F | F |
| F | T | T | T |
| F | F | T | T |

Dört durumun dördünde de sonuç aynı olduğundan devrik önerme, özgün önermeye mantıksal olarak denktir. Örnekte de böyledir: yarın pazar değilse, örneğin cumaysa, bugün perşembedir; yani cumartesi değildir. Karşıt önermede ise $01$ ve $10$ satırları farklı sonuç verdiğinden denklik yoktur.

## 8. Gereklilik ve Yeterlilik, Mantıksal Denklik

### 8.1 Sözel kalıplar

Slaytta "Cüneyt programcıysa Zeynep avukattır" örneği vardı. Bunu doğru kabul edersek, Zeynep'in avukat olması Cüneyt'in programcı olmasına bağlıdır; Zeynep gerçekte avukat değilse önerme yanlış olabilir. Slaytta "p only if q" ifadesinin "if p then q" ile aynı anlamda olduğu belirtiliyordu.

<!-- BELİRSİZ: 01:18:53-01:19:13 arasında slayttaki diğer sözel kalıplar (only if vb.) altyazıda net değil ve bu anın karesine bakılmadı. -->

### 8.2 Gerekli ve yeterli koşul

Hoca üniversitenin bir duyurusundaki "yıl içi değerlendirme için bir ara sınav yapılması gerekli ve yeterlidir" ifadesini örnek verdi: bir sınav yapılmak zorundadır, fazlası zorunlu değildir.

- Gerekli koşul (necessary condition) sonuç tarafıdır.
- Yeterli koşul (sufficient condition) hipotez tarafıdır.

"Cüneyt programcıysa Zeynep avukattır" önermesinde ($p \Rightarrow q$) Cüneyt'in programcı olması yeterli koşul, Zeynep'in avukat olması gerekli koşuldur.

Bir öğrenci konunun çok karıştığını söyleyince hoca, mantığın daha ileri düzeyde çok derin konuları olduğunu söyledi.

### 8.3 Mantıksal denklik

Bir önermeyle ilgili başka bir önerme verildiğinde, iki önermenin doğruluk tablosundaki sonuç sütunları tamamen aynıysa bunlar mantıksal olarak denktir (logically equivalent). Örnekler: $p \Rightarrow q \equiv \lnot p \lor q$ ve $p \Rightarrow q \equiv \lnot q \Rightarrow \lnot p$. Karşıt önerme ise denk değildir.

## 9. Ancak ve Ancak (Çift Yönlü Koşullu Önerme)

### 9.1 Tanım

"İse" bağlacı bir açıdan sıkı değildir: hipotez gerçekleşmeden sonuç gerçekleşirse önerme yine doğrudur. Bunu sıkılaştırmak için "if and only if" (IFF, ancak ve ancak) kullanılır. Hoca İngilizce gramerdeki bu kalıbı sordu; bir öğrenci "ancak ve ancak" diye cevap verdi.

$p \Leftrightarrow q$, iki değer aynıysa 1, farklıysa 0'dır (ekrandan, 01:30:00):

| $p$ | $q$ | $p \Leftrightarrow q$ | $q \Leftrightarrow p$ |
|:-:|:-:|:-:|:-:|
| 0 | 0 | 1 | 1 |
| 0 | 1 | 0 | 0 |
| 1 | 0 | 0 | 0 |
| 1 | 1 | 1 | 1 |

Bu tablo XOR'un tam tersidir. (Bir öğrenci bunun XNOR olup olmadığını sordu; hoca soruyu sonraki konuyla birlikte ele alacağını söyledi.)

> **Ek bilgi (derste anlatılmadı):** $p \Leftrightarrow q \equiv \lnot(p \oplus q)$ olduğundan bu bağlaca lojik devrelerde XNOR denir.

### 9.2 Özdeşlikler

- $p \Leftrightarrow q \equiv q \Leftrightarrow p$: yerler değişince sonuç değişmez (ekrandan, 01:30:00).
- $p \Leftrightarrow p \equiv 1$: iki değer hep aynıdır.
- $p \Leftrightarrow \lnot p \equiv 0$: iki değer hep farklıdır.
- $p \Leftrightarrow 1 \equiv p$: $0 \Leftrightarrow 1 = 0$, $1 \Leftrightarrow 1 = 1$.
- $p \Leftrightarrow 0 \equiv \lnot p$: $0 \Leftrightarrow 0 = 1$, $1 \Leftrightarrow 0 = 0$.

### 9.3 Temel bağlaçlarla yazılışı

"Ancak ve ancak $p$ ise $q$", "$p$ ise $q$" ile "$q$ ise $p$"nin birlikte olmasıdır:

$$p \Leftrightarrow q \equiv (p \Rightarrow q) \land (q \Rightarrow p) \equiv (\lnot p \lor q) \land (\lnot q \lor p)$$

Hoca özdeşliklerin bu açılımla da gösterilebileceğini örnekledi. $q = 1$ konursa $(\lnot p \lor 1) \land (0 \lor p) = 1 \land p = p$ olur; yani $p \Leftrightarrow 1 \equiv p$. Aynısı $q = 0$ için yapılabilir.

> **Hocanın vurgusu:** Bu biçimleri birbirine dönüştürmek önemlidir; bazen bir biçimi görüp diğerine çevirmeniz gerekir.

## 10. Totoloji ve Çelişki

### 10.1 Totoloji

Doğruluk tablosunda önermelerin her bir durumu ($n$ önerme için $2^n$ durum) için doğru sonuç elde edilirse birleşik önerme (compound proposition) bir totolojidir (ekrandan, 01:35:00).

Örnek: $p \Rightarrow (p \lor q)$.

| $p$ | $q$ | $p \lor q$ | $p \Rightarrow (p \lor q)$ |
|:-:|:-:|:-:|:-:|
| 0 | 0 | 0 | 1 |
| 0 | 1 | 1 | 1 |
| 1 | 0 | 1 | 1 |
| 1 | 1 | 1 | 1 |

Bütün satırlar 1 olduğundan bu bir totolojidir. Hoca $p \lor q$ sütununu "geçici bellek" gibi yazdığını, akılda tutulabiliyorsa yazmanın zorunlu olmadığını söyledi.

### 10.2 Çelişki

Bütün durumlarda sonuç yanlışsa buna çelişki (contradiction) denir. Örnek: $p \land \lnot p$; $p$ doğru da olsa yanlış da olsa sonuç yanlıştır.

> **Ders sonrası not:** Hoca $p \land \lnot p$'yi anlatırken bir yerde "o zaman totoloji diyoruz" dedi; doğrusu "çelişki"dir.

## 11. De Morgan Kanunu

### 11.1 Küme gösterimiyle sezgi

De Morgan kuralı kümelerden bilinir. $A$ ile $B$'nin kesişiminin değili, kesişim dışında kalan bütün bölgedir; bu bölge $A$'nın dışı ile $B$'nin dışının birleşimidir (ekrandan, 01:40:00):

$$(A \land B)' = A' \lor B'$$

Kural uygulanırken değil içeri dağıtılır: her operand değillenir ve AND ile OR yer değiştirir. Slayttaki denklikler:

- $\lnot(p \lor q) \equiv (\lnot p) \land (\lnot q)$
- $\lnot(p \land q) \equiv (\lnot p) \lor (\lnot q)$

"İse" ve "ancak ve ancak" için böyle doğrudan bir dağıtım yoktur. Örneğin $\lnot(A \Rightarrow B)$ önce $\lnot(\lnot A \lor B)$ biçimine getirilip sonra açılabilir; yani dolaylı yoldan açılır.

### 11.2 Programlamada kullanımı

C'de `if (!((A) && (B)))` biçiminde yazılan bir koşul (ekrandan, 01:40:00) De Morgan ile `if (!(A) || !(B))` biçiminde yazılabilir. Hoca iki yazımdaki işlem sayılarını karşılaştırdı: ilkinde iki karşılaştırma, bir AND ve bir değil; ikincisinde iki karşılaştırma, iki değil ve bir OR vardır. Hangi biçimin daha az işlem gerektirdiğine bakılarak koşul daha kısa yazılabilir.

<!-- BELİRSİZ: 01:39:34-01:41:19 arasında hocanın işlem sayıları (4'e karşı 5, "iki birime karşı üç birim") sözlü olarak karışık; hangi biçimin daha ucuz olduğu altyazıdan kesin çıkmıyor. -->

> **Hocanın vurgusu:** Koşul yazarken "bunu daha kısa yazabilir miyim?" diye düşündüğünüzde aklınıza De Morgan gelsin.

## 12. Niceleyiciler

### 12.1 Önerme fonksiyonu ve tanım kümesi

$P(x)$ klasik bir önerme değil, $x$ değişkenine bağlı bir önermedir. Örneğin $P(x)$: "$2x$ çift tam sayıdır". $x$'in alındığı $D$ kümesine $P(x)$'in tanım kümesi (domain of discourse, derste "ayrıntılı bilgi alanı") denir. Önermenin $D$'deki her $x$ için mi, yoksa bazı $x$ değerleri için mi doğru olduğunu ifade etmek gerekebilir; bu yüzden iki niceleyici vardır.

Hocanın örneği: $D$ bu sınıftaki öğrenciler olsun. "Bu sınıftaki her öğrenci 18 yaşından büyüktür" yanlış olabilirken, "bu sınıftaki bazı öğrenciler 18 yaşından büyüktür" doğru olabilir.

<!-- BELİRSİZ: 02:22:18'deki örnek önerme altyazıda "Pn eşittir n kare artı iken tek sayıdır" diye geçiyor; hoca ve bir öğrenci n tek/çift durumlarını karıştırdı ve bu anın karesine bakılmadı. Önerme büyük olasılıkla "$n^2+1$ çifttir" ya da "$n^2+1$ tektir"; iki durumda da $\forall n$ önermesi yanlıştır, çünkü n'nin bir paritesi karşı örnek verir ($n=1$ için $n^2+1=2$, $n=2$ için $5$). -->

### 12.2 Evrensel niceleyici

"Her" (for every, for all) $\forall$ ile gösterilir. Slayttaki örnek (ekrandan, 02:25:00):

- "Every student in this class has studied calculus"
- $P(x)$: "$x$ has studied calculus"
- $\forall x\, P(x)$

$\forall x\, P(x)$, $D$'deki bütün $x$'ler için $P(x)$ doğruysa doğrudur; bir tane bile çalışmamış öğrenci varsa yanlıştır. Hoca bunu bir AND zincirine benzetti: $P(x_1) \land P(x_2) \land \dots$

"Her asal sayı tektir" gibi bir önermenin yanlışlığını göstermek için tek bir karşı örnek yeterlidir; 2 çift bir asal sayıdır. "Her üçgenin iç açıları toplamı 180 derecedir" gibi bir önermenin doğruluğu ise ispatla gösterilir.

Slayttaki örnekler (ekrandan, 02:30:00):

- Her gerçel $x$ için $x^2 \ge 0$: doğru.
- Her gerçel $x$ için $x > 1$ ise $x + 1 > 1$: doğru. $x$ 1'den biraz büyük olsa bile $x+1 > 2 > 1$ olur.
- Her gerçel $x$ için $x \ge 0$ ise $x + 1 > 1$: yanlış. Karşı örnek $x = 0$: $1 > 1$ yanlıştır.
- Her pozitif tam sayı $n$ için, $n$ çift ise $n^2 + n + 19$ asaldır: bkz. Örnek Sorular.

### 12.3 Bir cümleyi önermelerle yazmak: roller coaster

"You cannot ride the roller coaster if you are under 4 feet tall unless you are older than 16 years old." $q$: "roller coaster'a binebilirsin", $r$: "4 feet'in altındasın", $s$: "16 yaşından büyüksün" olsun. Çözüm Örnek Sorular bölümündedir.

### 12.4 Varoluşsal niceleyici

"Bazı", "en az bir" (there exists, for some) $\exists$ ile gösterilir. $\exists x\, P(x)$, $P(x)$'i doğru yapan en az bir $x$ varsa doğrudur. Hoca bunu bir OR zincirine benzetti: $P(x_1) \lor P(x_2) \lor \dots$

Slayttaki bir örnekte bazı gerçel sayılar için verilen bir önermeyi $x = 2$ sağladığı için önerme doğrudur; tek örnek yeterlidir.

<!-- BELİRSİZ: 02:35:34'teki varoluşsal örnekteki ifade altyazıda okunmuyor ve bu anın karesine bakılmadı. -->

Asal sayıyla ilgili varoluşsal örnek Örnek Sorular bölümündedir. Hoca bunun "güzel bir for döngüsü sorusu" olduğunu, bu şartı sağlayan en küçük $n$'yi bulmanın bir while döngüsüyle daha güzel yazılacağını söyledi.

### 12.5 Cümleleri niceleyicilerle yazmak

**Herkesin tam olarak bir en iyi arkadaşı vardır.** $B(x, y)$: "$y$, $x$'in en iyi arkadaşıdır" olsun. Cümle şöyle kurulur: her $x$ kişisi için bir $y$ kişisi vardır; $y$, $x$'in en iyi arkadaşıdır ve her $z$ kişisi için, $z$ $y$'den farklıysa $z$, $x$'in en iyi arkadaşı değildir. Hoca bunu önce parçalara ayırıp sonra AND ve "ise" ile birleştirdi.

$$\forall x\, \exists y\, \forall z\, \big( B(x,y) \land ((z \ne y) \Rightarrow \lnot B(x,z)) \big)$$

<!-- BELİRSİZ: 02:37:31-02:39:19 arasındaki slaytın karesine bakılmadı; formül hocanın anlatımına uyan standart biçimle yazıldı. -->

**Kadın ve ebeveyn olan biri, birinin annesidir** (ekrandan, 02:40:00). $F(x)$: "$x$ kadındır", $P(x)$: "$x$ ebeveyndir", $M(x,y)$: "$x$, $y$'nin annesidir".

$$\forall x\, \big( (F(x) \land P(x)) \Rightarrow \exists y\, M(x,y) \big)$$

Her $x$ için, kişi hem kadın hem ebeveynse, en az bir $y$ için $x$, $y$'nin annesidir. "Herkes herkesin annesidir" denmediği için $y$ için $\exists$ kullanılır.

### 12.6 Karşı örnek

$\forall x\, P(x)$ önermesindeki $P(x)$'i yanlış yapan bir $x$ değerine karşı örnek (counterexample) denir. Örneğin "her tam sayı $x$ asaldır" önermesi için 4 (ya da 1) bir karşı örnektir.

### 12.7 Niceleyiciler için De Morgan kuralı

De Morgan'da AND ile OR yer değiştiriyordu; $\forall$ AND'e, $\exists$ OR'a karşılık geldiği için burada da $\forall$ ile $\exists$ yer değiştirir:

$$\lnot \forall x\, P(x) \equiv \exists x\, \lnot P(x), \qquad \lnot \exists x\, P(x) \equiv \forall x\, \lnot P(x)$$

Örnekler:

- "Sınıftaki herkesin kalkülüs dersini almış olması söz konusu değildir" $= \lnot \forall x\, P(x)$. Bu, "kalkülüs dersini almamış bazı öğrenciler vardır" $= \exists x\, \lnot P(x)$ demektir.
- "There is a student in this class who is taking calculus" $= \exists x\, Q(x)$. Bunun değili $\lnot \exists x\, Q(x)$, "sınıftaki bütün öğrenciler kalkülüs dersini almıyor" $= \forall x\, \lnot Q(x)$ demektir.

> **Hocanın vurgusu:** Cümlelerin vurgusu önemlidir. "Bütün $x$'ler için $P(x)$ doğru değildir" ile "$P(x)$ bazı $x$'ler için doğru değildir" aynı anlamdadır; ilkinde vurgu "bütün" kelimesindedir, ikincisinde $P(x)$'tedir.

## Örnek Sorular

### Soru 1: "not" kullanmadan olumsuz yazma

(ekrandan, 01:45:00) Write the negation of each of the following propositions without using any form of the word "not":

a) Today is Thursday.
b) $2 + 1 = 3$
c) There is no wind in Illinois.

**Çözüm (derste verildi):**

a) Today is Monday or Tuesday or Wednesday or Friday or Saturday or Sunday. Bir öğrencinin önerdiği "bugün çarşambadır" yeterli değildir; $x > 2$'nin değilinin $x \le 2$ olması gibi, perşembe dışındaki bütün olasılıklar yazılmalıdır.
b) $2 + 1 < 3$ or $2 + 1 > 3$.
c) Illinois is windy. Önerme zaten olumsuzluk içerdiği için olumsuzu "not" kullanmadan yazılabilir.

<!-- BELİRSİZ: 01:45:11-01:45:54 arasındaki dördüncü madde karede görülmedi; hoca "hot"un tersi "cold", ıslak/çamurlu olanın tersi "dry" diye yorumladı. Büyük olasılıkla bir yerin "hot and wet/muddy" olduğunu söyleyen bir önerme; olumsuzu "cold or dry" biçimindedir. -->

### Soru 2: Cümleleri $p, q, r$ ile yazma

(derste sözlü ve ekrandan, 01:46:00-01:53:00) $p$: "Finalde A aldın.", $q$: "Kitaptaki her alıştırmayı yaptın.", $r$: "Bu derste A aldın." Aşağıdakileri $p, q, r$ ve bağlaçlarla yazın.

a) Dersten A aldın ama kitaptaki her alıştırmayı yapmadın.
b) Finalde A aldın, kitaptaki her alıştırmayı yaptın ve dersten A aldın.
c) To get an A in this class, it is necessary for you to get an A on the final (ekrandan, 01:50:00).
d) Finalde A aldın ama kitaptaki her alıştırmayı yapmadın; yine de dersten A aldın.
e) Finalde A almak ve kitaptaki her alıştırmayı yapmak, dersten A almak için yeterlidir.
f) Dersten A alırsın ancak ve ancak ya kitaptaki her alıştırmayı yaparsın ya da finalde A alırsın.

**Çözüm (derste verildi):**

a) $r \land \lnot q$ (bir öğrencinin cevabı). Finalle ilgili bir şey söylenmediği için $p$ kullanılmaz.
b) $p \land q \land r$
c) Gereklilik, tek yönlü koşulla ifade edilir; "ancak ve ancak" için cümlede "if and only if" gibi bir ifade bulunmalıdır.
d) $p \land \lnot q \land r$
e) $(p \land q) \Rightarrow r$
f) $r \Leftrightarrow (q \lor p)$. İki yönlü olduğu için tersten de yazılabilir.

> **Ders sonrası not:** (c) maddesinde hoca ifadeyi "$p$ ise $r$" diye yazdı. Gerekli koşul sonuç tarafında olduğundan ("dersten A almak için finalde A almak gereklidir"), doğrusu $r \Rightarrow p$'dir: dersten A aldıysan finalde A almışsındır.

### Soru 3: "if p then q" biçimine getirme

(ekrandan, 01:55:00) Restate each proposition in the form (if p then q) of a conditional proposition.

a) Joey will pass the discrete mathematics exam if he studies hard.
b) A sufficient condition for Katrina to take the algorithms course is that she pass discrete mathematics.

**Çözüm (derste verildi):**

a) If Joey studies hard then he will pass the discrete math exam.
b) If Katrina passes discrete mathematics, then she can take the algorithms course. Ayrık matematikten geçmek yeterli koşul olduğu için hipotez tarafına yazılır.

Hoca (a)'nın karşıtını da sordu: "Matematik sınavını geçtiyse çok çalışmıştır." Ancak çalışmadan geçmek de mümkündür; tablodaki $01$ satırı 1'dir. Bu, tek yönlü "ise"nin anlamını iyi gösterir.

### Soru 4: Verilen doğruluk değerleriyle hesaplama

(derste sözlü, 01:56:56-01:59:52) $p$ doğru, $q$ yanlış ve $r$'nin doğruluk değeri bilinmiyor. Aşağıdakilerin doğruluk değerini belirleyin.

**Çözüm (derste verildi):**

- $p \lor r$: $1 \lor r = 1$; $r$ ne olursa olsun doğrudur.
- $q \Rightarrow r$: $0 \Rightarrow r$; "1 ise 0" durumu oluşamayacağından her zaman doğrudur.
- $(p \land r) \Leftrightarrow r$: $1 \land r = r$ ve $r \Leftrightarrow r = 1$; doğrudur.
- Dördüncü ifade: $q \land r = 0 \land r = 0$ ve $q \lor r = 0 \lor r = r$ hesaplandı; sonuç bir önceki maddeyle aynı çıktı.

<!-- BELİRSİZ: Bu sorudaki ifadeler karede görülmedi; ikinci ve dördüncü ifadenin tam biçimi altyazıdan kesin çıkmıyor. Hoca ikinci maddede önce "R'dir" dedi, sonra sonucun her durumda 1 olduğunu açıkladı. -->

### Soru 5: Sembollerle yazma

(derste sözlü, 02:11:16-02:14:37) "4 < 2" önermesi $p$, "7 < 10" önermesi $q$ ve "6 < 6" önermesi $r$ olsun. "4 < 2 ancak ve ancak (7 < 10 ve 6, 6'dan küçük değildir)" cümlesini sembollerle yazın.

**Çözüm (derste verildi):** Bir öğrenci "$p$ ancak ve ancak, $q$ ve $r$ parantez içinde" dedi; hoca cümlede "is not less than" olduğu için $r$'nin değilinin alınacağını ekledi: $p \Leftrightarrow (q \land \lnot r)$. Hoca "6 is not less than 6" kısmı doğrudan $r$ diye tanımlansaydı $r$ yazmanın da kabul edilebileceğini, bunun varsayıma bağlı olduğunu söyledi.

<!-- BELİRSİZ: Bu sorunun ekrandaki tam metni karede görülmedi; sayılar altyazıdaki "4 küçüktür 2 ise 7 küçüktür 10" ve "is not less than altı" ifadelerinden kuruldu. Aynı slayttaki sonraki madde ($p$: "Bugün pazartesi", $q$: "Yağmur yağıyor", $r$: "Hava sıcak" ile sembollerden cümle kurma) de altyazıda net değil. -->

### Soru 6: Totoloji mi?

(ekrandan, 02:15:00) Use a truth table to determine whether the following is a tautology: $(\lnot p \land (p \Rightarrow q)) \Rightarrow \lnot q$

**Çözüm (derste verildi):** Hoca önce sadeleştirme yolunu denedi: $p \Rightarrow q$ yerine $\lnot p \lor q$ yazdı ve dağılma özelliğiyle ilerlemeye çalıştı, sonra bir öğrencinin önerisiyle dıştaki "ise"yi de açtı; ancak bu yol sonuca ulaşmadı. Doğruluk tablosu yolu daha kolaydır:

| $p$ | $q$ | $\lnot p$ | $p \Rightarrow q$ | $\lnot p \land (p \Rightarrow q)$ | $\lnot q$ | Sonuç |
|:-:|:-:|:-:|:-:|:-:|:-:|:-:|
| 0 | 0 | 1 | 1 | 1 | 1 | 1 |
| 0 | 1 | 1 | 1 | 1 | 0 | 0 |
| 1 | 0 | 0 | 0 | 0 | 1 | 1 |
| 1 | 1 | 0 | 1 | 0 | 0 | 1 |

Bir satırda sonuç 0 olduğu için ifade totoloji değildir. Hocanın sonucu da buydu: "bir tane false var". Tablo python ile kontrol edildi.

### Soru 7: Evrensel önerme ve karşı örnek

(ekrandan, 02:30:00) For every positive integer $n$, if $n$ is even then $n^2 + n + 19$ is prime. Doğru mu?

Derste önce $n$ tek gibi okunup $n = 1$ denendi: $1 + 1 + 19 = 21 = 3 \cdot 7$, asal değil. Sonra hoca koşulun "çift" olduğunu fark ettiği için $n = 1$ örneğinden vazgeçti ve soru derste tamamlanmadı.

> **Çözüm (derste verilmedi):** $n = 2$ için $2^2 + 2 + 19 = 25 = 5^2$ asal değildir. Bu bir karşı örnektir, bu yüzden önerme yanlıştır. (python ile kontrol edildi; $n = 4$ için de $39 = 3 \cdot 13$ olur.)

### Soru 8: Roller coaster

(derste sözlü, 02:30:50-02:34:46) "You cannot ride the roller coaster if you are under 4 feet tall unless you are older than 16 years old." $q$: "You can ride the roller coaster", $r$: "You are under 4 feet tall", $s$: "You are older than 16 years old". Cümleyi mantıksal ifadeyle yazın.

**Çözüm (derste verildi):** Koşul kısmı "4 feet'in altındasın" ($r$) ve "16 yaşından büyük değilsin"dir; "unless" olumsuzluk getirdiği için $s$'nin değili alınır. Sonuç "binemezsin" ($\lnot q$) olur:

$$(r \land \lnot s) \Rightarrow \lnot q$$

Hoca denk bir yazım da gösterdi: "ise"nin devriği alınırsa ve De Morgan uygulanırsa $q \Rightarrow (\lnot r \lor s)$ elde edilir. Sözel anlamı: "Roller coaster'a biniyorsan ya 4 feet'in altında değilsindir ya da 16 yaşından büyüksündür."

> **Ders sonrası not:** Altyazıda bir yerde "40 feet" geçiyor; cümledeki değer 4 feet'tir (hoca da "dört" dedi).

### Soru 9: Varoluşsal önerme

(derste sözlü, 02:35:52-02:37:15) Bazı $n$ sayıları için: $n$ asal ise ondan sonraki ardışık sayılar ($n+1, n+2, \dots$) asal değildir. Bunu sağlayan bir $n$ bulun.

**Çözüm (derste verildi):** Tek örnek yeterlidir. Hoca $n$'leri sırayla denedi: $n = 3$ için 4 asal değil ama 5 asal; $n = 5$ için 6 asal değil ama 7 asal; $n = 7$ için 8, 9, 10 asal değil ama 11 asal. Böyle ilerleyerek $n = 23$'e gelinir: 24, 25, 26, 27, 28 asal değildir. Bu yüzden önerme doğrudur.

<!-- BELİRSİZ: Soru metni karede görülmedi; kaç ardışık sayının istendiği altyazıdan kesin çıkmıyor. Büyük olasılıkla $n+1, \dots, n+5$; bu durumda python ile en küçük $n$'nin 23 olduğu doğrulandı (23'ten sonraki asal 29). -->

## Dersin Toparlaması

Bu derste mantık konusu baştan sona işlendi. Önerme, doğru ya da yanlış olan bir hüküm cümlesidir; birden çok önerme AND, OR ve NOT temel bağlaçlarıyla, bunlardan türetilen XOR, "ise" ve "ancak ve ancak" bağlaçlarıyla birleştirilir. Her bağlacın doğruluk tablosu, elektrik devresi karşılığı ve özdeşlikleri verildi. Bunlardan $p \oplus q \equiv (\lnot p \land q) \lor (p \land \lnot q)$, $p \Rightarrow q \equiv \lnot p \lor q$ ve $p \Leftrightarrow q \equiv (p \Rightarrow q) \land (q \Rightarrow p)$ dönüşümleri özellikle vurgulandı. Karşıt, ters ve devrik önermelerden yalnız devriğin özgün önermeye denk olduğu, gerekli koşulun sonuç ve yeterli koşulun hipotez tarafında olduğu gösterildi. Totoloji, çelişki ve De Morgan kanunu ile birlikte çeşitli alıştırmalar çözüldü.

Son bölümde niceleyicilere geçildi: $\forall$ bir AND zinciri, $\exists$ bir OR zinciri gibi düşünülür; $\forall$ önermesini yanlış yapmak için tek bir karşı örnek, $\exists$ önermesini doğru yapmak için tek bir örnek yeterlidir. Niceleyiciler için De Morgan kuralı da verildi. Hoca, bu derste öğrenilenlerin bir sonraki derste ispat (proof) konusunda kullanılacağını ve ispatla ilgili bazı kavramların yazarak anlatılacağını söyledi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
