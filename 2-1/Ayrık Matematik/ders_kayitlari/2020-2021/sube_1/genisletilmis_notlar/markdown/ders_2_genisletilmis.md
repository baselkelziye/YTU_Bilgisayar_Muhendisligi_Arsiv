# Ders 2 Genişletilmiş Notu: Mantıksal Denklik, Niceleyiciler, İspat Yöntemleri ve Tümevarım

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Önceki Dersin Tekrarı
- 2. Mantıksal Denklik
- 3. Karşıt ve Karşıt Ters
- 4. Çift Yönlü Koşullu Önerme
- 5. Totoloji ve Çelişki
- 6. De Morgan Kuralları ve Bir Alıştırma
- 7. Niceleyiciler ve Tanım Kümesi
- 8. Evrensel Niceleyici
- 9. Bir Cümleyi Önermelerle Yazmak: Roller Coaster
- 10. Varoluşsal Niceleyici
- 11. Cümleleri Niceleyicilerle Yazmak
- 12. Karşı Örnek ve Niceleyiciler için De Morgan Kuralı
- 13. İspatın Yapı Taşları
- 14. Doğrudan İspat ve Karşıt Tersle İspat
- 15. Tümevarımla İspat
- 16. Bölüm Sonu Soru-Cevapları

## 1. Önceki Dersin Tekrarı

Ders Zoom üzerinden yapıldı. Hoca konuya girmeden önce ilk haftada ve geçen hafta görülenleri kısaca özetledi. Birinci bölümde ayrık matematiğin ne olduğu ve bize nasıl yardımcı olacağı konuşulmuştu. İkinci bölüm "mantık ve ispat" bölümüydü. Mantığın matematikteki yeri ve önermeler (proposition) anlatılmıştı.

### 1.1 Önerme

Hocanın tekrarına göre önerme, cevabı evet ya da hayır, yani doğru (true) ya da yanlış (false) olan bir ifadedir. Cevabı olmayan bir ifade önerme değildir. Önermeler $p, q, r, s, \dots$ diye harflerle adlandırılır.

Hoca önermelerin "her zaman pozitif" yazılacağını hatırlattı. Olumsuz bir önerme doğrudan tanımlanmaz. Olumsuzluk gerekiyorsa, olumlu önerme tanımlanır ve olumsuzluk işlemiyle (negation) ters çevrilir. Önermeler AND, OR, XOR, NOT, "ise" ve "ancak ve ancak" bağlaçlarıyla birleştirilir. Böylece bir metindeki her ifade bir önerme kabul edilip metnin anlattığı şey önermelerle yazılabilir.

<!-- BELİRSİZ: 00:07:43'te önerme olmayan örnek olarak "Bağınlı gözlük duvaran kaç?" gibi bozuk bir soru geçiyor; büyük olasılıkla hocanın kendisiyle ilgili sayısal bir soru (ör. gözlük numarası). -->

> **Ders sonrası not:** Tekrarda "Bugün hava güneşli mi?" ve "Okullar açılacak mı?" önerme sayıldı. Soru cümleleri önerme değildir. Önerme, doğru ya da yanlış olan bir bildirme cümlesidir. "Bugün hava güneşli" bir önermedir; aynı şeyin soru biçimi değildir.

### 1.2 Bağlaçlar ve Akılda Tutma Yolları

Hoca her bağlaç için aritmetikten bir benzetme kullandı:

- **AND (ve):** Çarpma gibi düşünülür. Çarpmada 0 yutan elemandır. Girişlerden biri bile false ise çıkış false olur.
- **OR (veya):** Toplama gibi düşünülür. Toplamada 0 etkisiz elemandır. İki giriş de false ise çıkış false, en az bir giriş true ise çıkış true olur.
- **XOR (dışlayan veya):** Çıkarma (subtraction) gibi düşünülür. İki giriş aynıysa birbirinden çıkarınca 0 kalır, çıkış false olur. Girişler farklıysa çıkış true olur. Hoca bunun en sevdiği operatör olduğunu söyledi.
- **NOT (değil):** Girişin tersini verir. Tilda ($\sim p$), kesme işareti ($p'$) ya da $\lnot p$ ile gösterilir.

### 1.3 Doğruluk Tablosu Nasıl Kurulur?

$n$ önerme varsa $2^n$ farklı durum vardır. İki önerme için $2^2 = 4$, üç önerme için $2^3 = 8$ satır yazılır. Satırlar rastgele yazılmaz. En sağdaki sütun $2^0 = 1$ basamağıdır: true, false, true, false diye tek tek değişir. Bir soldaki sütun $2^1 = 2$ basamağıdır: iki true, iki false. Üçüncü sütun $2^2 = 4$: dört true, dört false. Dördüncü bir değişken olsaydı sekiz true, sekiz false diye giderdi.

Hoca bu satırların ikili (binary) sayılar gibi okunabileceğini söyledi. Örneğin iki değişkenli tabloda "1 1" satırı onluk tabanda 3'e, "0 0" satırı 0'a karşılık gelir. Bu konuya sayı teorisinde yeniden dönülecek.

### 1.4 İşlem Önceliği

Aritmetikteki gibi önce parantezler yapılır. Parantezin önünde bir olumsuzluk varsa (ileride görülecek De Morgan kuralı), AND ve OR'dan önce o uygulanır. Sonra AND ve OR işlemleri gelir.

### 1.5 Koşullu Önerme

Koşullu önerme $p \rightarrow q$ biçimindedir ve "$p$ ise $q$", "if $p$ then $q$" diye okunur. $p$ hipotez (hypothesis), $q$ sonuçtur (conclusion). Hoca bunun programlama dillerindeki "if $p$ doğruysa şunu yap" yapısıyla karıştırılmamasını istedi. Öyle olsaydı doğruluk tablosu da ona göre kurulurdu.

$p \rightarrow q$ yalnız bir durumda false olur: hipotez true, sonuç false iken. Diğer üç durumda true olur. Hoca bazı kaynakların aynı ifadeyi "$p$ only if $q$" diye yazdığını da söyledi.

## 2. Mantıksal Denklik

Doğruluk tablosundaki çıkış değerleri aynı olan iki önerme arasında mantıksal denklik (logical equivalence) vardır. Gösterimi üç çizgili $\equiv$ işaretidir.

Hoca bunu iki birleşik önermeyle gösterdi: $p \rightarrow q$ ve $\lnot p \lor q$. İkinci ifade için önce $\lnot p$ sütunu yazılır, sonra $q$ ile OR yapılır.

| $p$ | $q$ | $\lnot p$ | $\lnot p \lor q$ | $p \rightarrow q$ |
| :---: | :---: | :---: | :---: | :---: |
| 1 | 1 | 0 | 1 | 1 |
| 1 | 0 | 0 | 0 | 0 |
| 0 | 1 | 1 | 1 | 1 |
| 0 | 0 | 1 | 1 | 1 |

İki ifade birbirinden çok farklı yazılmıştır. Birinde $p$'nin değili var, ötekinde yok. Birinde OR, ötekinde "ise" kullanılıyor. Ama aynı girişlere aynı çıkışları veriyorlar. Bu yüzden $p \rightarrow q \equiv \lnot p \lor q$ yazılabilir.

### 2.1 Neden Önemli? Lojik Kapılar

Hoca bunu lojik devreler dersiyle ilişkilendirdi. Elinizde OR kapısı olmayabilir ama başka kapılar vardır. "OR'un verdiği çıkışı elimdeki diğer kapılarla elde edebilir miyim?" sorusunun cevabı mantıksal denkliktir. İki devre denkse biri yerine öbürü kullanılabilir.

Basit bir örnek olarak $A$'nın devriği (tümleyeni, complement) verildi. $A = 0$ ise devriği 1, $A = 1$ ise devriği 0'dır. Devriğin devriği alınırsa yine $A$ elde edilir. Yani $\lnot(\lnot A) \equiv A$'dır ve sadeleştirilince karşımıza $A$ çıkar.

### 2.2 Hocanın Benzetmeleri

Hoca mantıksal denkliği kendi üzerinden anlattı: Kafasına şapka taksa, gözlüğünü çıkarsa, saçını sarıya boyasa da yine aynı kişidir. Kimliğini soran herkes aynı adı alır. Görünüş değişir, taşınan bilgi aynı kalır.

İkinci benzetme kesirlerdi: $\frac{2}{4}$ neyse $\frac{1}{2}$ de odur. Görünüşleri farklıdır ama ikisi de bir bütünün yarısıdır. Yapılan şey sadeleştirmedir.

Hoca ileride bu bölüm içinde Karnaugh diyagramlarının görüleceğini söyledi. Doğruluk tablosundaki değerler Karnaugh diyagramına yerleştirilip sadeleştirilince denk ve daha basit bir ifade elde edilecek.

## 3. Karşıt ve Karşıt Ters

### 3.1 Karşıt (Converse)

$p \rightarrow q$ ifadesinin karşıtı (converse) $q \rightarrow p$'dir. Hoca buna "yer değiştirme" dedi: hipotez sonuç, sonuç hipotez olur. Bunun olumsuzlukla bir ilişkisi yoktur. Olumsuzluk tek bir değişkene uygulanır, karşıt ise "ise" ifadesi için kullanılır.

$q \rightarrow p$'nin tablosu kurulurken artık hipotez $q$'dur. $q$'nun true, $p$'nin false olduğu satır aranır. Yalnız o satır false, diğerleri true olur.

### 3.2 Karşıt Ters (Contrapositive)

Karşıt ters (contrapositive), karşıtı alınmış ifadenin iki tarafının da değilinin alınmasıdır: $\lnot q \rightarrow \lnot p$. Hoca bunun Türkçede "devrik" diye de çevrildiğini söyledi. Tabloda önce $\lnot q$ sütunu (0, 1, 0, 1), sonra $\lnot p$ sütunu (0, 0, 1, 1) yazılır. Sonra "ise" uygulanır: hipotez tarafı 1, sonuç tarafı 0 olan satır 0, diğerleri 1 olur.

| $p$ | $q$ | $p \rightarrow q$ | $q \rightarrow p$ | $\lnot q$ | $\lnot p$ | $\lnot q \rightarrow \lnot p$ |
| :---: | :---: | :---: | :---: | :---: | :---: | :---: |
| 1 | 1 | 1 | 1 | 0 | 0 | 1 |
| 1 | 0 | 0 | 1 | 1 | 0 | 0 |
| 0 | 1 | 1 | 0 | 0 | 1 | 1 |
| 0 | 0 | 1 | 1 | 1 | 1 | 1 |

Sonuç:

- $p \rightarrow q$ ile karşıtı $q \rightarrow p$ **denk değildir**. Sütunlar farklıdır.
- $p \rightarrow q$ ile karşıt tersi $\lnot q \rightarrow \lnot p$ **denktir**. Sütunlar aynıdır.

Bu sonuç ispatlar bölümünde yeniden kullanılacak.

## 4. Çift Yönlü Koşullu Önerme

Çift yönlü koşullu önerme (biconditional) $p \leftrightarrow q$ diye çift taraflı okla gösterilir. "$p$ ancak ve ancak $q$", "$p$ if and only if $q$" diye okunur. Hoca klavyede bu oku yazmak zor olduğu için sınavda ya da bir yerde "if and only if" diye yazılabileceğini, ama elle yazarken herkesin sembolü kullandığını söyledi.

### 4.1 XOR'un Tersi

Hoca $\leftrightarrow$'nun tablosunu XOR'la yan yana kurdu. XOR çıkarmaydı: girişler aynıysa 0, farklıysa 1. $\leftrightarrow$'nun sonucu bunun tam tersidir: girişler aynıysa 1, farklıysa 0.

> **Hocanın vurgusu:** "Ancak ve ancak"ı aklınızda tutmak için XOR'un tam tersi diye düşünün. XOR'u hatırlıyorsanız tabloyu hemen kurarsınız.

### 4.2 İki Koşullu Önermeyle Yazmak

Hoca aynı tabloya bir sütun daha ekledi: $(p \rightarrow q) \land (q \rightarrow p)$. $p \rightarrow q$ yalnız 2. satırda, $q \rightarrow p$ yalnız 3. satırda 0'dır. İkisi AND ile bağlanınca (çarpma gibi) bu iki satır 0, diğerleri 1 olur.

| $p$ | $q$ | $p \oplus q$ | $p \leftrightarrow q$ | $p \rightarrow q$ | $q \rightarrow p$ | $(p \rightarrow q) \land (q \rightarrow p)$ |
| :---: | :---: | :---: | :---: | :---: | :---: | :---: |
| 1 | 1 | 0 | 1 | 1 | 1 | 1 |
| 1 | 0 | 1 | 0 | 0 | 1 | 0 |
| 0 | 1 | 1 | 0 | 1 | 0 | 0 |
| 0 | 0 | 0 | 1 | 1 | 1 | 1 |

Son iki sonuç sütunu aynıdır. Bu yüzden $p \leftrightarrow q \equiv (p \rightarrow q) \land (q \rightarrow p)$ yazılabilir. Biri karşımıza çıktığında öbürüyle değiştirilebilir. Hangisinin daha sade olduğunu ileride Karnaugh diyagramları gösterecek.

## 5. Totoloji ve Çelişki

**Totoloji (tautology):** Girişler ne olursa olsun, birleşik önerme hangi biçimde verilirse verilsin, çıkış sütununun hepsi true (1) ise o önerme bir totolojidir.

**Çelişki (contradiction):** Çıkış sütununun hepsi false (0) ise önerme bir çelişkidir.

Hoca slayttaki örneklerin tek değişkenli olmasına aldanılmamasını istedi. Tablo iki değişkenli (4 satır) ya da üç değişkenli (8 satır) olabilir. Bakılacak tek şey çıkış sütunudur.

Hoca De Morgan'a geçmeden kısa bir özet yaptı: Aynı girişe aynı çıkışı veren önermeler denktir. Karşıt $q \rightarrow p$'dir, karşıt ters $\lnot q \rightarrow \lnot p$'dir. Çift yönlü koşullu önerme XOR'un tersidir. Bütün çıkışlar true ise totoloji, bütün çıkışlar false ise çelişki vardır.

## 6. De Morgan Kuralları ve Bir Alıştırma

### 6.1 Kural

Hoca De Morgan kuralını üniversite öncesinden bildiğimizi hatırlattı. Bir ifadenin üzerinde devrik (olumsuzluk) işareti varsa: her önermenin tersi alınır ve aradaki işlem de tersine döner. AND'in tersi OR, OR'un tersi AND'dir.

$$\lnot(p \lor q) \equiv \lnot p \land \lnot q, \qquad \lnot(p \land q) \equiv \lnot p \lor \lnot q$$

Slaytta bu iki satır arasında ok kullanılmıştı. Hoca bu okların "ise" anlamında olmadığını, De Morgan'ın sonucunu gösterdiğini belirtti. Doğru gösterim $\equiv$'dir.

### 6.2 Alıştırma

Hoca kâğıt kalem istedi ve tahtaya şu ifadeyi yazdı:

$$\Big(\lnot(p \land q) \rightarrow (p \lor q)\Big)'$$

Yani $\lnot\big(\lnot(p \land q) \rightarrow (p \lor q)\big)$. Soru: $p = 1, q = 0$ iken ve $p = 1, q = 1$ iken sonuç nedir? İki öğrenciyle birlikte çözüldü.

<!-- BELİRSİZ: Tahtadaki ifade altyazıdan tam okunmuyor ("P, Q'nun değil ise P veya Q'nun ... parantez ... değili"); yazım kısa nottaki biçime ve sözlü çözüm adımlarına göre kuruldu. -->

**$p = 1, q = 0$:**

- $p \land q = 1 \land 0 = 0$.
- $\lnot(p \land q) = 1$.
- $p \lor q = 1 \lor 0 = 1$.
- $1 \rightarrow 1 = 1$.
- Dıştaki olumsuzluk: $\lnot 1 = 0$. Sonuç **0**.

**$p = 1, q = 1$:**

- $p \land q = 1$, $\lnot(p \land q) = 0$.
- $p \lor q = 1$.
- $0 \rightarrow 1 = 1$.
- $\lnot 1 = 0$. Sonuç **0**.

Bu ifadenin tam tablosu (Python ile kontrol edildi): yalnız $(p, q) = (0, 0)$ satırı 1, diğer üç satır 0'dır.

> **Hocanın vurgusu:** "Hoca hangi satırı soracak?" diye düşünmeyin. Hemen doğruluk tablosunu kurun ve ifadeyi sütun sütun doldurun. Üçüncü bir değişken gelse 8 satır olur, yine aynı şeyi yaparsınız. Sonra hangi değerler sorulursa sorulsun cevabı o satırdan okursunuz.

Hoca bu sırada Zoom'a bağlanıp bilgisayarın başında olmamanın, bir arkadaşının yerine yoklamaya imza atmak gibi olduğunu ve bunu hoş karşılamadığını söyledi. Ardından 10 dakikalık ara verildi.

Aradan dönüşte sohbet penceresinde bir öğrencinin XNOR yazımıyla ilgili bir notu konuşuldu. Hoca lojikte XNOR diye ayrı bir kapı olduğunu ama burada ondan bahsetmediklerini söyledi.

<!-- BELİRSİZ: 01:02:16'daki sohbet mesajının içeriği ("Exnor. İkisi de sıfır mı? Cevap sıfır") altyazıdan net değil. -->

## 7. Niceleyiciler ve Tanım Kümesi

Aradan sonra niceleyiciler (quantifiers) konusuna geçildi. Bir önermenin doğru ya da yanlış olması bazen içindeki bir değişkene bağlıdır. Niceleyiciler, bu değişkenin hangi değerleri için önermenin doğru olduğunu söylemenin yoludur.

### 7.1 Önerme Fonksiyonu ve Tanım Kümesi

$P(x)$, $x$ değişkenine bağlı bir önerme olsun. Örneğin $P(x)$: "$x$ bir çift tam sayıdır." $x$ belli olunca bu ifade ya true ya false olur.

$x$'in alabileceği değerlerin kümesine $D$ denir. $D$ kümesinin her elemanı $P(x)$'i bir önerme yapar. Bu kümeye İngilizcede domain of discourse denir. Türkçeye "ayrıntılı bilgi alanı" diye de çevrilmiştir.

### 7.2 Örnek: $n^2 + 2n$ Tek Sayıdır

$P(n)$: "$n^2 + 2n$ tek sayıdır." $D$ pozitif tam sayılar kümesi olsun. Bu önermeye doğru ya da yanlış diyebilmek için $n$'in ne olduğunu bilmek gerekir.

- $n$ tek olsun, örneğin $n = 3$: $3^2 + 2 \cdot 3 = 9 + 6 = 15$, tektir. Hoca bütün tek $n$'ler için sonucun tek olduğunu, bunun ispatının ileride yapılacağını söyledi.
- $n$ çift olsun, örneğin $n = 2$: $2^2 + 2 \cdot 2 = 4 + 4 = 8$, çifttir. Önerme yanlış olur.

Yani $D$'nin elemanları önermeyi doğru ya da yanlış yapanlar diye ayrılabilir: tek sayılar doğru, çift sayılar yanlış yapar.

Hoca bir de sınıf örneği verdi: "Bu sınıftaki herkes 18 yaşından büyüktür." Sınıfta 18 yaşından küçük biri varsa önerme yanlış, herkes 18'den büyükse doğrudur. "For every" ve "for some" ifadeleri, önermenin sınıftaki herkese mi yoksa en az bir kişiye mi bağlı olduğunu söylemek için kullanılacak.

## 8. Evrensel Niceleyici

Matematikte ve bilgisayar bilimlerinde "her" (every) ve "bazı" (some) kavramları sık karşımıza çıkar. Örneğin: "For every triangle $T$, the sum of the angles of $T$ is $180°$." Her üçgenin iç açıları toplamı 180 derecedir. Bu önerme her zaman doğrudur, çünkü iç açıları toplamı 180 dereceden farklı bir üçgen yoktur.

### 8.1 Gösterim

"Her" kavramı evrensel niceleyici (universal quantifier) ile yazılır. Ters A işaretiyle gösterilir:

$$\forall x\, P(x)$$

"For all $x$, $P(x)$", "for every $x$, $P(x)$" ya da "her $x$ için $P(x)$" diye okunur. Buradaki $x$'ler $D$ kümesinin elemanlarıdır.

Örnek: "Every student in the class has studied calculus." Burada $P(x)$: "$x$ has studied calculus" ve $x$, sınıftaki her öğrencidir. Önerme $\forall x\, P(x)$ olarak yazılır.

### 8.2 Sonlu Kümede AND

$D = \{x_1, x_2, \dots, x_n\}$ sonlu bir küme olsun. O zaman $\forall x\, P(x)$, bütün önermelerin AND ile bağlanmış hâlidir:

$$\forall x\, P(x) \equiv P(x_1) \land P(x_2) \land \dots \land P(x_n)$$

$P(x_1), \dots, P(x_n)$'nin hepsi true ise $\forall x\, P(x)$ true olur. Biri bile false ise AND'in sonucu false olur.

Hocanın örneği: Sınıf $D$ kümesi olsun ve önerme "herkes ayrık matematik dersini alıyor" olsun. Herkes dersi alıyorsa her biri true'dur, hepsi AND'lenince sonuç true olur. Ama biri dersi almadan misafir olarak oturuyorsa sonuç false olur.

### 8.3 $n^2 + 2n$ Örneğine Dönüş

$\forall n\, P(n)$ yazıp $n$'i tek ya da çift diye ayırmazsak, yani bütün pozitif tam sayılar için iddia edersek, önerme false olur (çift $n$'ler yüzünden). Yalnız tek $n$'ler için söylenirse doğru, yalnız çift $n$'ler için söylenirse yanlıştır. "Her" yerine "bazı" denirse önerme doğru olur.

### 8.4 Sözlü Sorular

Hoca öğrencilere sırayla gerçel sayılar üzerinde üç soru sordu.

**1) $\forall x \in \mathbb{R},\ x^2 \geq 0$**

Cevap: Doğru. $x$ negatif de olsa pozitif de olsa karesi sıfırdan küçük olamaz.

**2) $\forall x \in \mathbb{R},\ x > 1 \rightarrow x + 1 > 1$**

Bütün gerçel sayılar, negatifler de dahil. Ama bir şart var: $x > 1$. Cevap: Doğru. $x > 1$ ise $x + 1 > 2 > 1$'dir.

**3) $\forall x \in \mathbb{R},\ x \geq 0 \rightarrow x + 1 > 1$**

Cevap: Yanlış. Bir öğrenci örnek olarak $x = 0$'ı verdi: $0 \geq 0$ sağlanır ama $0 + 1 = 1$, $1 > 1$ değildir.

Hoca burada karşı örnek (counterexample) kavramını ilk kez andı: Bir ifadeyi yanlış yapan tek bir değer bulmak yeter. Bu değere karşı örnek denir.

### 8.5 $n^2 + n + 19$ Örneği

Soru: Her çift pozitif tam sayı $n$ için $n^2 + n + 19$ asal mıdır?

Bunun doğru olduğunu göstermek için bütün çift $n$'leri denemek gerekir. Oysa iddia "her" diyor. Asal olmayan bir tane değer bulunursa iddia yanlış olur. Bir öğrenci $n = 2$'yi önerdi:

$$2^2 + 2 + 19 = 4 + 2 + 19 = 25 = 5 \cdot 5$$

25 asal değildir. Önerme **yanlıştır**. (Python ile kontrol edildi: $n = 4$ için $39 = 3 \cdot 13$ de bir karşı örnektir.)

> **Ders sonrası not:** Hoca bu yöntemi "olmayana ergi metodu" diye andı. Burada yapılan, evrensel bir önermeyi tek bir karşı örnekle çürütmektir. Olmayana ergi (proof by contradiction) farklı bir ispat yöntemidir; bkz. Bölüm 14.

## 9. Bir Cümleyi Önermelerle Yazmak: Roller Coaster

Hoca sınavlarda "verilen cümleyi mantıksal ifadelerle yazınız" türünde soruların gelebileceğini söyledi. Cümleler İngilizce de, Türkçe de verilebilir. Bu örnek kitaptan alındığı için İngilizcedir:

> "You cannot ride the roller coaster if you are under 4 feet tall unless you are older than 16 years old."

Roller coaster lunaparklardaki, inip çıkan, insanların bağırarak indiği raylı trendir. Cümlenin anlamı: Boyun 4 fitin altındaysa binemezsin, ama 16 yaşından büyüksen bu fark etmez. 16 yaşından küçüksen binebilmek için boyunun 4 fitin üzerinde olması gerekir.

### 9.1 Önermeleri Belirlemek

İlk adım cümlede kaç bilgi olduğunu bulmaktır. Bir öğrenci üç tane dedi. Öğrenci ilk önermeyi "you cannot ride" diye söyledi. Hoca bunu düzeltti: önermeler olumsuz yazılmaz. Olumlu biçim alınır:

- $q$: You can ride the roller coaster.
- $r$: You are under 4 feet tall.
- $s$: You are older than 16 years old.

### 9.2 Önermeyle Yazmak

Hoca birkaç dakika süre verdi ve bir çözümün tek olmak zorunda olmadığını hatırlattı. Farklı çözümler doğruysa birbirine mantıksal olarak denk olmalıdır.

Slayttaki ifade:

$$(r \land \lnot s) \rightarrow \lnot q$$

Okunuşu: Boyun 4 fitin altındaysa **ve** 16 yaşından büyük değilsen, roller coaster'a binemezsin. İki şart birlikte sağlanmalıdır.

Hoca ikinci bir yazım da gösterdi:

$$(\lnot r \lor s) \rightarrow q$$

Okunuşu: Boyun 4 fitin altında değilse **veya** 16 yaşından büyüksen binebilirsin.

### 9.3 Nasıl Kontrol Edilir?

Hoca kontrol yolunu anlattı: $q, r, s$ için 8 satırlık tablo kurulur, ifadenin sonucu her satıra yazılır. Sonra 1 çıkan satırların gerçekten cümleyi sağlayıp sağlamadığına bakılır. Başka bir ifade bulduysanız onun sütununu da yazarsınız. İki sütun aynıysa iki ifade denktir.

Hoca iki yazım arasında tercih konusunda da bir not düştü: birincide bir NOT, ikincide iki NOT var. Tek NOT kullanmak daha pratik, daha az eleman demektir. Ama şu an optimizasyonla uğraşılmıyor; önemli olan, yazılan ifadenin cümlenin anlamını verip vermediğidir. Hoca bu tabloyu dersin sonunda yapamayanların mutlaka yapmasını istedi.

> **Ders sonrası not:** İki ifade denk değildir. Python ile 8 satır kontrol edildi; 4 satırda sonuçlar farklı. $(\lnot r \lor s) \rightarrow q$, ilk ifadenin tersidir (inverse). Örneğin boyu uzun ($r = 0$) ama binemeyen ($q = 0$) biri asıl kuralı ihlal etmez, ama ikinci ifade bu satırda false verir. Cümle yalnız kimin binemeyeceğini söyler; kimin kesin binebileceğini söylemez. Doğru çeviri $(r \land \lnot s) \rightarrow \lnot q$'dur.

| $q$ | $r$ | $s$ | $(r \land \lnot s) \rightarrow \lnot q$ | $(\lnot r \lor s) \rightarrow q$ |
| :---: | :---: | :---: | :---: | :---: |
| 1 | 1 | 1 | 1 | 1 |
| 1 | 1 | 0 | 0 | 1 |
| 1 | 0 | 1 | 1 | 1 |
| 1 | 0 | 0 | 1 | 1 |
| 0 | 1 | 1 | 1 | 0 |
| 0 | 1 | 0 | 1 | 1 |
| 0 | 0 | 1 | 1 | 0 |
| 0 | 0 | 0 | 1 | 0 |

> **Ek bilgi (derste anlatılmadı):** $p \rightarrow q$'nun tersi (inverse) $\lnot p \rightarrow \lnot q$'dur. Tersi, karşıtla ($q \rightarrow p$) denktir ama asıl önermeyle denk değildir. Bu yüzden bir kuralın tersini yazmak çoğu zaman yanlış çeviriye yol açar.

## 10. Varoluşsal Niceleyici

Evrensel niceleyicinin yanında varoluşsal niceleyici (existential quantifier) vardır. Ters E işaretiyle gösterilir:

$$\exists x\, P(x)$$

"For some $x$, $P(x)$", "$P(x)$'i doğru yapan bir $x$ vardır" ya da "en az bir $x$ için $P(x)$" diye okunur.

Fark şudur: $\forall$'da $D$'deki bütün değerlerin önermeyi doğru yapması gerekir. $\exists$'de en az bir $x$ değerinin önermeyi doğru yapması yeterlidir. En az bir dendiği için 2, 3, 4 ya da daha fazla eleman da olabilir.

### 10.1 Sonlu Kümede OR

$D = \{x_1, \dots, x_n\}$ ise $\exists x\, P(x)$ önermelerin OR ile bağlanmış hâlidir:

$$\exists x\, P(x) \equiv P(x_1) \lor P(x_2) \lor \dots \lor P(x_n)$$

Bunlardan biri 1, diğerleri 0 ise toplam yine 1'dir. Hepsi 1 olsa da toplam 1'dir.

> **Ders sonrası not:** Hoca bir yerde "kümedeki bütün elemanlar sağlarsa o zaman false olur", bir başka yerde de "o zaman for every olur ve yanlış sonuç verir" dedi. Bu yanlıştır. $\exists x\, P(x)$ için en az bir eleman yeter; bütün elemanlar sağlıyorsa da önerme doğrudur. Hoca OR benzetmesinde ("hepsi 1 olunca da toplam 1") ve ders sonundaki bir öğrenci sorusunda bunu doğru biçimde söyledi (bkz. Bölüm 16.8).

### 10.2 Sözlü Sorular

**1) $\exists x \in \mathbb{R},\ \dfrac{x}{x^2 + 1} = \dfrac{2}{5}$**

Hoca bir öğrenciden önermeyi doğru yapan bir $x$ istedi. Öğrenci $x = 2$ dedi:

$$\frac{2}{2^2 + 1} = \frac{2}{5}$$

Bir değer bulundu, başka aramaya gerek yok. Önerme **doğrudur**. (Python ile kontrol edildi: $x = \frac{1}{2}$ de sağlar, $\frac{1/2}{5/4} = \frac{2}{5}$.)

**2) Bazı asal $n$ pozitif tam sayıları için $n+1$, $n+2$, $n+3$ ve $n+4$ asal değildir.**

Hoca asalı hatırlattı: yalnız 1'e ve kendisine bölünebilen sayı. Bir öğrenci önce 1'i, sonra 2'yi önerdi. 1 asal değildir, şart da $n$'in asal olmasıdır. 2 için $n + 1 = 3$ asaldır, olmaz. Hoca dört sayının AND ile bağlandığını, hepsinin asal olmaması gerektiğini vurguladı. Sonunda $n = 23$ bulundu:

- 23 asaldır.
- 24, 25, 26, 27'nin hiçbiri asal değildir.

Tek bir örnek önermeyi **doğru** yapar. (Python ile kontrol edildi: 23 bu özelliği taşıyan en küçük asaldır; 31, 47, 53 de sağlar.)

## 11. Cümleleri Niceleyicilerle Yazmak

### 11.1 "Everyone has exactly one best friend."

Herkesin tam olarak bir tane en iyi arkadaşı vardır. İki, üç olmaz; bir tanedir.

$B(x, y)$: "$y$, $x$'in en iyi arkadaşıdır" olsun. Hoca cümleyi adım adım kurdu:

- "Herkes" için $\forall x$ yazılır. $x$ dünyadaki herhangi bir kişidir.
- Her $x$ için en iyi arkadaş olan bir $y$ vardır. "En az bir" olduğu için $\exists y$ yazılır.
- Dünya yalnız $x$ ve $y$'den oluşmaz. $y$'den farklı her $z$ için, $z$ $x$'in en iyi arkadaşı olamaz. Bu kısım "tam olarak bir"i sağlar. "Her" olduğu için $\forall z$ yazılır.

$$\forall x\, \exists y\, \Big(B(x, y) \land \forall z\, \big((z \neq y) \rightarrow \lnot B(x, z)\big)\Big)$$

Hoca kontrolü de yaptı: $y$, $x$'in en iyi arkadaşıysa $B(x,y) = 1$. $z \neq y$ ise $\lnot B(x,z) = 1$. $1 \land 1 = 1$, ifade cümleyi sağlar.

### 11.2 "If somebody is female and is a parent, then this person is someone's mother."

- $F(x)$: $x$ kadındır (female).
- $P(x)$: $x$ ebeveyndir (parent).
- $M(x, y)$: $x$, $y$'nin annesidir.

Cümlede "ve" (and) var, bu AND olarak taşınır. Cümle bütün kişiler için söylendiğinden başa $\forall x$ gelir. "Birinin annesi" denince herkesin değil, en az bir kişinin annesi kastedilir; bu yüzden $\exists y$ kullanılır:

$$\forall x\, \Big(\big(F(x) \land P(x)\big) \rightarrow \exists y\, M(x, y)\Big)$$

> **Ders sonrası not:** Derste "parent" kelimesi "evli" diye çevrildi. Doğrusu "ebeveyn"dir. Cümlenin anlamı "bir kadın ebeveynse birinin annesidir" olur; evlilikle ilgisi yoktur.

## 12. Karşı Örnek ve Niceleyiciler için De Morgan Kuralı

### 12.1 Karşı Örnek

$D$'deki bir $x$ değeri $P(x)$'i yanlış yapıyorsa $\forall x\, P(x)$ de yanlıştır. Bir ifadeyi yanlış yapan en az bir $x$ değerine karşı örnek (counterexample) denir.

Hocanın örneği: "Her tam sayı $x$ asaldır." 4 asal değildir. Başka örnek aramaya gerek yok; akla gelen ilk örnek karşı örnek olabilir.

### 12.2 Genelleştirilmiş De Morgan Kuralı

De Morgan kuralında olumsuzluk her parçaya dağılır ve işlem tersine döner. Niceleyicilerde de aynısı olur: $\forall$'nın tersi $\exists$, $\exists$'nin tersi $\forall$'dır.

$$\lnot \forall x\, P(x) \equiv \exists x\, \lnot P(x)$$

$$\lnot \exists x\, P(x) \equiv \forall x\, \lnot P(x)$$

### 12.3 Calculus Örneği

"Every student in the class has taken a course in calculus." Burada $\forall x\, P(x)$ var; $P(x)$: "$x$ has taken a course in calculus."

İngilizcede bir cümleyi olumsuz yapmanın kalıbı "it is not the case that ..." ifadesidir: "hiçbir durumda böyle değildir", "söz konusu değildir". Yani "Sınıftaki her öğrencinin calculus dersi almış olması söz konusu değildir."

De Morgan uygulanınca "every student" "there is a student" olur ve $P(x)$'in değili alınır:

> "There is a student in this class who has not taken a course in calculus."

Sınıfta calculus dersi almamış en az bir öğrenci vardır: $\exists x\, \lnot P(x)$.

Öbür yön: "There is a student in this class who has taken a course in calculus" ($\exists x\, Q(x)$). Olumsuzu "It is not the case that there is a student ..." olur. De Morgan ile $\forall x\, \lnot Q(x)$: "Every student in this class has not taken a course in calculus", yani sınıftaki hiçbir öğrenci calculus almamıştır.

### 12.4 Olumsuzlar Ne Zaman Doğru?

Hoca slayttaki özeti anlattı:

| İfade | Ne zaman true? | Ne zaman false? |
| :--- | :--- | :--- |
| $\lnot \exists x\, P(x) \equiv \forall x\, \lnot P(x)$ | Her $x$ için $P(x)$ false ise | $P(x)$'i true yapan en az bir $x$ varsa |
| $\lnot \forall x\, P(x) \equiv \exists x\, \lnot P(x)$ | $P(x)$'i false yapan en az bir $x$ varsa | Her $x$ için $P(x)$ true ise |

Ardından ispatlar bölümüne geçmeden önce 10 dakikalık bir ara daha verildi.

## 13. İspatın Yapı Taşları

Hoca bu kısmın "biraz laf" olduğunu, hızlı geçeceğini söyledi. Bir matematiksel sistem tanımlanmamış terimlerden, tanımlardan ve aksiyomlardan oluşur.

- **Tanımlanmamış terim:** Sistemin başlangıç kavramı olarak kabul edilir. Örneğin nokta ve doğru. Her şey bir nokta ve bir doğruyla başlar, üstüne kurulur.
- **Tanım:** Yeni bir kavram yaratmak için önceden kabul edilmiş kavramlar ve tanımlanmamış terimlerle bir önerme kurmaktır. Öklid geometrisinden örnekler: İki üçgenin karşılıklı kenarları ve açıları aynıysa bu üçgenler eştir. İki açının toplamı 180 derece ise bu açılar birbirini tamamlayan (bütünler) açılardır.
- **Aksiyom:** Sistem içinde ispat yapılmadan doğru kabul edilen önermedir. Örnekler: İki nokta verildiğinde bu noktalardan geçen bir doğru her zaman vardır. Bir doğru ve üzerinde olmayan bir nokta verildiğinde, bu noktadan geçen doğrulardan biri verilen doğruya mutlaka paraleldir.
- **Teorem:** Önceden ispatlanmış teoremler, aksiyomlar ve tanımlar kullanılarak ve $p$'nin doğru olduğu varsayılarak doğruluğu gösterilen $p \rightarrow q$ biçimindeki önermedir.

Bu bölümde yapılacak iş, $p \rightarrow q$ biçimindeki önermeleri ispatlamaktır.

## 14. Doğrudan İspat ve Karşıt Tersle İspat

Hoca ispat çeşitlerini ikiye ayırdı: doğrudan ispat ve dolaylı ispat. Dolaylı ispatı "olmayana ergi" ve "indirect proof" diye de andı.

- **Doğrudan ispat (direct proof):** $p$'nin doğru olduğu kabul edilir. İspatlanmış teoremler ve aksiyomlar kullanılarak $q$'nun doğru olduğu gösterilir.
- **Dolaylı ispat:** $p \rightarrow q$ yerine karşıt tersi $\lnot q \rightarrow \lnot p$ ispatlanır. Yani hem karşıtı alınır hem de iki tarafın değili alınır.

> **Hocanın vurgusu:** Aklınızda şöyle kalsın: doğrudan ispat $p \rightarrow q$, dolaylı ispat $\lnot q \rightarrow \lnot p$.

Hoca bir de genel bir gözlem yaptı: Bir şeyin doğruluğunu ispatlamak, bütün şartlarda doğru olduğunu göstermektir. Bir şeyin yanlış olduğunu göstermek çok daha kolaydır; onu yanlış yapan bir tane örnek bulmak yeter.

> **Ders sonrası not:** Derste karşıt tersle ispat "olmayana ergi" adıyla da anıldı. Bunlar farklı yöntemlerdir. Karşıt tersle ispatta (proof by contraposition) $\lnot q \rightarrow \lnot p$ doğrudan ispatlanır. Olmayana ergide (proof by contradiction) $p \land \lnot q$ varsayılır ve bir çelişkiye ulaşılır.

> **Ek bilgi (derste anlatılmadı):** Karşıt tersle ispatın geçerli olmasının sebebi Bölüm 3'teki tablodur: $p \rightarrow q \equiv \lnot q \rightarrow \lnot p$. Olmayana ergi ise $\lnot q$'yu varsayıp $p$ ile çelişen bir sonuç bulmaya dayanır. Ayrıca evrensel bir iddiayı karşı örnekle çürütmek bir ispat yöntemi değil, iddianın yanlış olduğunu göstermektir.

### 14.1 Doğrudan İspat Ne Zaman Kullanılır?

Hocanın verdiği doğrudan ispat örnekleri:

- $n$ tek sayı ise $n^2$ tektir. Burada $p$: "$n$ tektir", $q$: "$n^2$ tektir".
- $m$ ve $n$ çift sayı ise $m + n$ de çifttir. $m$ ve $n$'in çift olduğu kabul edilip $m + n$'nin çift olduğu gösterilir.

Hoca önemli bir not ekledi: $p$ tarafındaki önerme "$n$ çift" gibi sade olmalıdır. $p$ tarafında $n^2$ ya da $m + n$ gibi ifadeler varsa doğrudan ispat yapılamaz. Örneğin "$n^2$ tek ise $n$ tektir" doğrudan ispatla yapılamaz; dolaylı ispat kullanılır.

> **Ders sonrası not:** "$p$ tarafı karmaşıksa doğrudan ispat yapılamaz" bir kural değildir. Böyle durumlarda doğrudan ispat genellikle zordur, karşıt ters daha kolaydır. Ama doğrudan ispat imkânsız değildir.

### 14.2 Doğrudan İspat: $n$ Çift ise $n^2$ Çifttir

Doğrudan ispatın adımları: $p$ doğru kabul edilir, $q$'nun doğruluğu gösterilmeye çalışılır, gösterilirse $p \rightarrow q$ doğrudur.

$p$: "$n$ çift sayıdır". $q$: "$n^2$ çift sayıdır".

1. $p$'yi doğru kabul ediyoruz. Çift sayı $2k$ biçiminde yazılır: $n = 2k$, $k \in \mathbb{Z}$. Böyle yazınca $n$'in çift olduğu kesindir.
2. $q$'yu gösterelim. $n$ yerine $2k$ konur:

$$n^2 = (2k)^2 = 4k^2 = 2 \cdot (2k^2)$$

3. $2k^2$ yerine yeni bir tam sayı değişkeni konur: $u = 2k^2$. Böylece $n^2 = 2u$ olur. $u$ ne olursa olsun 2 ile çarpıldığı için $n^2$ çifttir.

> **Ders sonrası not:** Hoca bu ispatın sonunda "ispatımı dolaylı ispatla yaptım" dedi. Bu örnek doğrudan ispattır. Ayrıca slaytta değişken büyük $P$ yazılmıştı; hoca bunun küçük harf olması gerektiğini söyledi.

### 14.3 Bir Yanlış Örnek: $m + n$

Hoca $p$ tarafının neden sade olması gerektiğini göstermek için "$m + n$ çift ise $m$ ve $n$ çifttir" önermesini andı. $m = 4$, $n = 2$ için $m + n = 6$; üçü de çifttir. Ama hoca bunun doğrudan ispatla gösterilemeyeceğini, dolaylı ispata geçmek gerektiğini söyledi. Benzer bir örnek olarak "$m + n$ tek ise $m$ ve $n$ tektir" önermesi de anıldı.

> **Ders sonrası not:** Bu iki önerme yanlıştır, hiçbir yöntemle ispatlanamaz. "$m + n$ çift ise $m$ ve $n$ çifttir" için karşı örnek $m = 1, n = 3$: toplam 4 çifttir ama sayılar tektir. "$m + n$ tek ise $m$ ve $n$ tektir" ise hiçbir zaman sağlanmaz: iki tek sayının toplamı her zaman çifttir. Toplam tekse sayılardan biri tek, öbürü çifttir. Python ile kontrol edildi.

### 14.4 Karşıt Tersle İspat: $n^2$ Tek ise $n$ Tektir

$p$: "$n^2$ tektir", $q$: "$n$ tektir". $p$ tarafında $n^2$ olduğu için hoca bunu doğrudan yapmadı.

1. Karşıt ters alınır. $\lnot p$: "$n^2$ çifttir". $\lnot q$: "$n$ çifttir".
2. Yeni önerme $\lnot q \rightarrow \lnot p$: "$n$ çift ise $n^2$ çifttir."
3. Artık $p$ tarafı tek bir değişkendir. Doğrudan ispat yapılır: $n = 2k$, $n^2 = 4k^2 = 2 \cdot (2k^2)$. Bu çifttir.

Karşıt ters doğru olduğuna göre asıl önerme de doğrudur. Hoca dolaylı ispatın aslında doğrudan ispatla yapıldığını vurguladı: önce karşıt ters alınır, sonra karşıt ters doğrudan ispatlanır.

**Soru (bir öğrenci, aradan sonra):** Slaytta bir hata yok mu? $u = 2k$ dendi; o zaman $u^2 = 4k^2$ olur, 2 ile çarpınca $8k^2$ çıkar.

**Cevap:** Hoca önce $n^2 = 4k^2 = 2 \cdot 2k^2$ adımında anlaştıklarını teyit etti. Sonra öğrencinin haklı olduğunu kabul etti: $2k$'ya $u$ denirse kare yalnız $k$'nın üzerindedir, $2u^2$ yazılamaz. Hoca slayt numarasını (49) not aldı ve düzeltmeyi e-postayla göndereceğini söyledi.

> **Ders sonrası not:** Slayt 49'da $u = 2k$ için $n^2 = 2 \cdot 2k^2 = 2u^2$ yazıyor. $u = 2k$ ise $2u^2 = 8k^2$ olur, $n^2 = 4k^2$ ile eşit değildir. Doğrusu: $u = 2k^2$ alınır ve $n^2 = 2u$ yazılır (Bölüm 14.2'deki gibi). Python ile kontrol edildi.

### 14.5 Karşıt Tersle İspat: $3n + 2$ Tek ise $n$ Tektir

$n$ bir tam sayı olsun. $3n + 2$ tek ise $n$'in tek olduğunu ispatlayın.

Hoca önce doğrudan denedi. Tek sayı $2k + 1$ ile gösterilir: $3n + 2 = 2k + 1$, yani $3n + 1 = 2k$. Buradan $n$'in tek olduğu gösterilemez. Çünkü $p$ tarafında $m + n$ gibi birleşik bir ifade var.

Karşıt ters: $\lnot q$: "$n$ çifttir", $\lnot p$: "$3n + 2$ çifttir". Yeni önerme: "$n$ çift ise $3n + 2$ çifttir."

1. $n = 2k$ yazılır.
2. $3n + 2 = 3(2k) + 2 = 6k + 2$.
3. 2 ortak paranteze alınır: $6k + 2 = 2(3k + 1)$.
4. $3k + 1$ ne olursa olsun önünde 2 çarpanı olduğu için $3n + 2$ çifttir.

Koşullu önermenin sonucu yanlışsa hipotezin de yanlış olması gerekir. Karşıt ters doğru olduğuna göre asıl koşullu önerme de doğrudur.

> **Ders sonrası not:** Derste ortak parantez sözlü olarak karıştı ("buraya 6k artı 2 olur"). Doğru adım $6k + 2 = 2(3k + 1)$'dir.

Hoca sonunda özet yaptı: Doğrudan ispatta $p$ doğru kabul edilip $q$ ispatlanır. $p$ tek başına değilse, bir toplam, bir çarpım ya da $n^2$ gibi verilmişse karşıt ters alınır: $\lnot q \rightarrow \lnot p$ yazılır ve ispatlanır. O doğruysa asıl önerme de doğrudur.

## 15. Tümevarımla İspat

Hoca bir başka ispat türü olarak tümevarımla ispatı (mathematical induction) anlattı. Üç adım vardır:

1. **Taban adımı (basis step):** Önermeye alabileceği ilk değer konur ($n = 1$) ve doğru olduğu gösterilir.
2. **Tümevarım adımı (inductive step):** Keyfî bir pozitif tam sayı alınır. $S_k$'nin doğru olduğu varsayılır ve bundan $S_{k+1}$'in de doğru olduğu gösterilir.
3. **Sonuç:** İki adım sağlanıyorsa önerme bütün pozitif tam sayılar için doğrudur.

Hoca $n$ yerine $k$ yazmasının sebebini "eller karışmasın diye" açıkladı.

### 15.1 Örnek 1: $1 + 2 + \dots + n = \dfrac{n(n+1)}{2}$

"Bize hep böyle öğretildi. Acaba doğru mu? Bakalım."

**Taban adımı:**

- $n = 1$: $\dfrac{1 \cdot 2}{2} = 1$. Bir elemanın toplamı 1. Doğru.
- Hoca örnek olsun diye $n = 2$'yi de denedi: $\dfrac{2 \cdot 3}{2} = 3$. İlk iki sayının toplamı $1 + 2 = 3$. Doğru. ($n = 1$ yeterlidir; bu ek kontrol yalnız örnek içindir.)

**Varsayım:** $n = k$ için doğru olsun:

$$1 + 2 + \dots + k = \frac{k(k+1)}{2}$$

**Tümevarım adımı:** $n = k + 1$ için gösterelim. Sol tarafa $(k+1)$'inci terim eklenir. Sağ tarafta her $n$ yerine $k + 1$ konur:

$$1 + 2 + \dots + k + (k+1) \stackrel{?}{=} \frac{(k+1)(k+2)}{2}$$

İlk $k$ terimin toplamı yerine varsayım konur:

$$\frac{k(k+1)}{2} + (k+1) = \frac{k(k+1) + 2(k+1)}{2} = \frac{k^2 + k + 2k + 2}{2} = \frac{k^2 + 3k + 2}{2}$$

$k^2 + 3k + 2$ çarpanlarına ayrılır: çarpımı 2, toplamı 3 olan sayılar 1 ve 2'dir.

$$\frac{k^2 + 3k + 2}{2} = \frac{(k+1)(k+2)}{2}$$

Sol taraf sağ tarafa eşittir. İspat tamamdır.

Hoca eşitlik sağlanmasaydı verilen ifadenin doğru olmayacağını söyledi ve bir alıştırma bıraktı: Formülü $\frac{n(n+2)}{2}$ diye değiştirip aynı ispatı yapmayı deneyin; çıkmadığını göreceksiniz. (Çözüm Örnek Sorular bölümündedir.)

### 15.2 Örnek 2: İlk $n$ Tek Sayının Toplamı $n^2$'dir

Hoca slaytta bir eksik olduğunu, toplamın $1 + 3 + 5 + \dots$ diye gitmesi gerektiğini söyledi ve slayt 55'i de düzeltilecekler listesine yazdı.

$$1 + 3 + 5 + \dots + (2n - 1) = n^2$$

**Taban adımı:**

- $n = 1$: $1^2 = 1$. Bir elemanın toplamı 1. Doğru.
- $n = 2$: $2^2 = 4$. İlk iki terimin toplamı $1 + 3 = 4$. Doğru.

**Varsayım:** $n = k$ için doğru olsun. $k$'ıncı tek sayı $2k - 1$'dir:

$$1 + 3 + \dots + (2k - 1) = k^2$$

**Tümevarım adımı:** Sonraki terim, $2k - 1$'de $k$ yerine $k + 1$ konarak bulunur: $2(k+1) - 1$.

$$\underbrace{1 + 3 + \dots + (2k-1)}_{k^2} + \big(2(k+1) - 1\big) = k^2 + 2k + 2 - 1 = k^2 + 2k + 1$$

Sağ taraf: $(k+1)^2 = k^2 + 2k + 1$. İki taraf aynıdır. İspat tamamdır.

> **Ders sonrası not:** Derste bir yerde sonuç "$2k^2 + 2k + 1$" diye okundu. Doğrusu $k^2 + 2k + 1 = (k+1)^2$'dir. Python ile kontrol edildi.

### 15.3 Örnek 3: $n^3 - n$, 3'e Bölünür

$n$ pozitif bir tam sayı iken $n^3 - n$'nin 3'e tam bölündüğünü ispatlayın. Hoca bunun $(n^3 - n) \bmod 3 = 0$ demek olduğunu belirtti.

**Taban adımı:**

- $n = 1$: $1^3 - 1 = 0$, $0 / 3 = 0$. Tam bölünür.
- $n = 2$: $8 - 2 = 6$, $6 / 3 = 2$. Tam bölünür.

**Varsayım:** $k^3 - k$, 3'e tam bölünsün.

**Tümevarım adımı:** $n = k + 1$ için $(k+1)^3 - (k+1)$'e bakılır. Küp, binom katsayıları (1, 3, 3, 1) ile açılır:

$$(k+1)^3 - (k+1) = k^3 + 3k^2 + 3k + 1 - k - 1$$

$+1$ ve $-1$ birbirini götürür. Kalan terimler gruplanır: $k^3 - k$ bir paranteze, $3k^2 + 3k$ başka bir paranteze alınır.

$$= (k^3 - k) + (3k^2 + 3k) = (k^3 - k) + 3(k^2 + k)$$

- $k^3 - k$ bilerek bu biçimde bırakılmıştır, çünkü varsayım gereği 3'e tam bölünür.
- $3(k^2 + k)$, 3'ün katıdır, 3'e tam bölünür.
- 3'e bölünen iki sayının toplamı da 3'e bölünür.

Öyleyse $(k+1)^3 - (k+1)$ de 3'e bölünür. İspat tamamdır. (Python ile $n \leq 500$ için ve adım özdeşliği için kontrol edildi.)

## 16. Bölüm Sonu Soru-Cevapları

Hoca bölümün soru-cevap slaytlarını AVESİS'ten açtı. Sorular kitaptan alınmıştır. Cevaplar AVESİS'te slaytlarla birlikte vardır. Hoca bazı soruları atladı ve onlara öğrencilerin kendisinin bakmasını istedi.

### 16.1 "not" Kullanmadan Olumsuzunu Yazmak

Verilen önermelerin olumsuzu "not" kelimesi kullanılmadan yazılacak.

- **"Today is Thursday."** Bir öğrenci "bugün Perşembe dışında herhangi bir gün" dedi. Hoca bunun OR ile yazılacağını gösterdi: "Today is Monday or Tuesday or Wednesday ..." Burada OR, gördüğümüz mantıksal bağlaçtır. Hoca "not" ile yazmanın daha kolay olduğunu da ekledi.
- **"$2 + 1 = 3$."** Bir öğrenci: "$2 + 1 < 3$ or $2 + 1 > 3$." Hoca: aynen böyle.
- **"There is no wind in Illinois."** Cevap: "There is wind in Illinois" (Illinois rüzgârlıdır).
- **"The summer in Champaign is hot and muggy."** Hoca yıllar önce "Champaign"i "şampanya" diye okuduğunu, oysa büyük harfle yazılmış bir yer adı (Amerika'da bir şehir) olduğunu anlattı. Öğrencilerin cevabından sonra sıfatların tam karşılığının verilemeyebileceğini, bunun önemli olmadığını söyledi.

> **Ders sonrası not:** "Today is Thursday" olumsuzu altı günün hepsini içermelidir: "Today is Monday or Tuesday or Wednesday or Friday or Saturday or Sunday." Sözlü cevapta yalnız ilk üç gün sayıldı.

> **Ders sonrası not:** "Hot and muggy" olumsuzu De Morgan ister: "not hot **or** not muggy". "not" kullanmadan, örneğin: "The summer in Champaign is cool or it is dry." Zıt kelimeleri "and" ile bağlamak ("cool and dry") yanlış olur.

<!-- BELİRSİZ: 02:38:16'daki öğrenci cevabı ("Şampaynı kısım ve sınır") altyazıdan okunmuyor. -->

### 16.2 Final, Alıştırmalar ve Dersten A

Üç önerme verildi:

- $p$: Finalden A almak.
- $q$: Kitaptaki her alıştırmayı yapmak.
- $r$: Dersten A ile geçmek.

Hoca dersten A ile geçmekle finalden A almanın farklı önermeler olduğunu vurguladı.

**a) "Dersten A aldın ama kitaptaki her alıştırmayı yapmadın."**

Bir öğrenci $\lnot q \rightarrow r$ dedi. Hoca neden "ise" kullanıldığını sordu ve düzeltti: Cümlede "ise" yok, "but" (ama) var. Dersten A ile geçmenin sebebi alıştırmaları yapmamış olmak olsaydı "ise" olurdu. Burada iki olgu birlikte söyleniyor. "But" AND demektir.

$$r \land \lnot q$$

Hoca bu sorunun yanıltmak için böyle sorulduğunu söyledi.

**b) "Finalden A aldın, kitaptaki her alıştırmayı yaptın ve dersten A ile geçtin."**

Öğrenci doğru cevap verdi: $p \land q \land r$.

**c) Dersten A ile finalden A arasındaki koşul.**

Bir öğrenci $p \rightarrow r$ dedi. Gerekçesi: "$r$'nin şartı $p$'ye bağlı." Hoca kabul edip devam etti.

<!-- BELİRSİZ: Bu şıkkın cümlesi altyazıda okunmuyor. Kısa nota göre slayttaki cümle "To get an A in this class, it is necessary for you to get an A on the final." ve slayttaki cevap $p \rightarrow r$. -->

> **Ders sonrası not:** Kısa nottaki cümle doğruysa, "gerekli" (necessary) koşul sonuç tarafına gider. "Dersten A almak için finalden A almak gereklidir" cümlesinin doğru çevirisi $r \rightarrow p$'dir: dersten A aldıysan finalden A almışsındır. $p \rightarrow r$ ise "finalden A almak yeterlidir" anlamına gelir.

**d) "Finalden A aldın ama her alıştırmayı yapmadın; yine de (nevertheless) dersten A aldın."**

Aynı öğrenci önce Türkçeye çevirdi, sonra $(p \land \lnot q) \rightarrow r$ dedi. Hoca yine "ise" olmadığını söyledi. "But" AND'dir; "nevertheless" (yine de) da üç olgunun birlikte olduğunu söyler:

$$p \land \lnot q \land r$$

> **Hocanın vurgusu:** Cümlede "if ... then", "only if", "necessary", "sufficient", "if and only if" gibi kalıplar yoksa "ise" kullanmayın. Bu soruları "ise" olmadan çözebiliyoruz.

Hoca bir sonraki şıklarda "is sufficient for getting" (yeterlidir) ve "if and only if" kalıplarının geçtiğini gösterdi. "If and only if" varsa $\leftrightarrow$ kullanılmalıdır. Hoca bu tür ifadeleri İngilizce okuyup Türkçe düşündüğümüz için zorlandığımızı, ama sınavda soruların Türkçe sorulacağını söyledi.

<!-- BELİRSİZ: "sufficient" ve "if and only if" şıklarının tam cümleleri ve cevapları altyazıda okunmuyor. -->

### 16.3 "if $p$ then $q$" Biçimine Çevirmek

- "Joey will pass the discrete exam if he studies hard." → "If Joey studies hard, then he will pass the discrete exam."
- Catherine'in algoritma dersini alması için şart, ayrık matematikten geçmesidir. → "If Catherine passes discrete mathematics, then she will take the algorithms course."

<!-- BELİRSİZ: Catherine cümlesinin slayttaki tam İngilizce metni altyazıda yok; çeviri hocanın sözlü açıklamasından kuruldu. -->

Hoca "write the converse of the first proposition" kısmını önemli bulmadığı için geçti.

### 16.4 Değeri Bilinmeyen Önerme

> **Hocanın vurgusu:** "Bu önemli, bir yerlere yazın."

$p$ true, $q$ false, $r$'nin değeri bilinmiyor (unknown). Bilinmiyor demek, $r$ true da olabilir false da. Verilen ifadeler true mu, false mu?

Yöntem: $r$'ye hem 1 hem 0 verilir. İki durumda da sonuç aynıysa ifadenin değeri bellidir. Hoca bu yolla üç ifadenin de true olduğunu gösterdi. İkinci ifadede $\leftrightarrow$ vardı; hoca XOR'un tersi olarak çalıştığını hatırlattı.

Örneğin $p \lor r$: $p = 1$ olduğu için $r$ ne olursa olsun $1 \lor r = 1$'dir.

<!-- BELİRSİZ: Slayttaki üç ifade altyazıda okunmuyor. $p \lor r$ kısa nottan alındı; diğer iki ifade (biri $\leftrightarrow$ içeriyor) bilinmiyor. -->

### 16.5 Sembolik İfadeye ve Kelimelere Çevirmek

Hoca "represent the given statement symbolically" sorusunu önemli bulmadı ama bir örneği çözdü. $p$: "$4 < 2$", $q$: "$7 < 10$", $r$: "$6 < 6$". Cümlede "if and only if" ve içinde "and" var, ikinci önerme olumsuz. Sonuç:

$$q \leftrightarrow (p \land \lnot r)$$

<!-- BELİRSİZ: $r$ önermesinin tam metni ("6'dan küçük olma") ve cümlenin İngilizcesi altyazıdan net değil. -->

Ters yönde, sembolik bir ifadenin kelimelerle yazılması istendi. $p$: "Today is Monday", $q$: "It is raining". Başta bir olumsuzluk varsa İngilizcede "it is not the case that ..." kalıbı kullanılır. Ortada "if and only if" vardı, sonra $r$ ile ilgili olumsuz bir ifade geliyordu.

<!-- BELİRSİZ: Bu ifadenin tam sembolik biçimi ve $r$'nin metni altyazıda okunmuyor. -->

### 16.6 Totoloji mi?

Soru: $\big(\lnot p \land (p \rightarrow q)\big) \rightarrow \lnot q$ bir totoloji midir?

Hoca tabloyu anlattı: iki değişken, dört satır. Önce $\lnot p$, sonra $p \rightarrow q$, sonra $\lnot q$ sütunu. Ortadaki parantez açılır. Son olarak parantezle $\lnot q$ arasındaki "ise" uygulanır.

| $p$ | $q$ | $\lnot p$ | $p \rightarrow q$ | $\lnot p \land (p \rightarrow q)$ | $\lnot q$ | Sonuç |
| :---: | :---: | :---: | :---: | :---: | :---: | :---: |
| 1 | 1 | 0 | 1 | 0 | 0 | 1 |
| 1 | 0 | 0 | 0 | 0 | 1 | 1 |
| 0 | 1 | 1 | 1 | 1 | 0 | 0 |
| 0 | 0 | 1 | 1 | 1 | 1 | 1 |

Totoloji olması için bütün satırların 1 olması gerekir. $p = 0, q = 1$ satırı 0'dır. Totoloji **değildir**.

<!-- BELİRSİZ: İfadenin kendisi altyazıda okunmuyor; kısa nottaki biçim alındı. Hocanın anlattığı sütun sırası bu biçimle uyumlu. -->

### 16.7 Tam Sayılarda Karşı Örnek

Tanım kümesi tam sayılardır. Hoca karşı örneği yeniden tanımladı: verilen önermeyi yanlış yapan en az bir değer.

**a) $\forall x\, \exists y\, (x = 1/y)$**

Hoca bunu kendisi çözdü. $x = 0$ verilirse $1/y = 0$ yapan bir $y$ yoktur. Karşı örnek $x = 0$'dır.

**b) $\forall x\, \exists y\, (y^2 - x < 100)$**

Hoca $x$'in $-100$'den küçük olması gerektiğini söyledi, sonra sayılarla denerken karıştı ($y = 10$ ve $x = 0$ için $100 < 100$ olmadığını söyledi).

> **Ders sonrası not:** $y^2 - x < 100$ demek $y^2 < 100 + x$ demektir. $x = 0$ için $y = 0$ seçilirse $0 < 100$ sağlanır; yani $x = 0$ karşı örnek değildir. $x \leq -100$ ise $100 + x \leq 0$ olur ve $y^2 < 100 + x \leq 0$ hiçbir tam sayı $y$ için sağlanmaz. Karşı örnek $x = -100$ (ya da daha küçük bir tam sayı). Python ile kontrol edildi: $x = -99$ için $y = 0$ sağlar, $x = -100$ için hiçbir $y$ sağlamaz.

**c) $\forall x\, \forall y\, (x^2 \neq y^3)$**

Hoca: $x = y = 0$ verilirse $0 = 0$ olur, eşittir. $x = y = 1$ verilirse $1 = 1$. İkisi de karşı örnektir. (Python ile $(x, y) = (8, 4)$ ve $(-8, 4)$'ün de karşı örnek olduğu görüldü.)

### 16.8 $n$ Çift $\leftrightarrow$ $7n + 4$ Çift

$n$ pozitif bir tam sayı olsun. "$n$ çifttir ancak ve ancak $7n + 4$ çifttir." Doğrudan ispat yapılabilir mi?

Hoca: Evet. $p$: "$n$ çifttir". $n = 2k$ alınır:

$$7n + 4 = 7(2k) + 4 = 14k + 4 = 2(7k + 2)$$

Önünde 2 çarpanı olduğu için sonuç çifttir.

Hoca tek sayı durumunu da sözlü andı: $n$ tek denseydi $n = 2k + 1$ konur ve sonucun "çift sayı artı 1" biçiminde olup olmadığına bakılırdı.

> **Ders sonrası not:** "Ancak ve ancak" için iki yön de ispatlanmalıdır. Derste yalnız "$n$ çift ise $7n + 4$ çift" yönü yazıldı. Diğer yön ("$7n + 4$ çift ise $n$ çift") karşıt tersle ispatlanır: $n = 2k + 1$ ise $7n + 4 = 14k + 11 = 2(7k + 5) + 1$ tektir. Python ile kontrol edildi.

### 16.9 Sherlock Holmes Paragrafı

Hoca dersin uzayacağını, bu konuyu bitirmek istediğini söyledi. Bir paragraf verilmişti: Sherlock Holmes başarılıysa profesör yakalanır; Dr. Watson hata yapmazsa (slip up) Holmes kayıp ipucunu bulur; Holmes ipucunu bulursa başarılı olur; Watson hata yapmaz; öyleyse profesör yakalanır.

Hoca metni ezberlemenin gerekmediğini, önemli olanın önermeleri bulmak olduğunu söyledi. Paragraftan dört önerme çıkar:

- $p$: Sherlock Holmes başarılıdır.
- $q$: Profesör yakalanır (apprehended).
- $r$: Dr. Watson hata yapar (slip up). Olumsuz kullanılmadığı için olumlu tanımlanır.
- $s$: Holmes kayıp ipucunu bulur.

Paragraf önermelerle:

$$p \rightarrow q, \quad \lnot r \rightarrow s, \quad s \rightarrow p, \quad \lnot r; \quad \text{öyleyse } q$$

<!-- BELİRSİZ: Profesörün adı altyazıda "Albert" diye geçiyor; slayttaki ad doğrulanamadı. -->

### 16.10 Gerçel Sayılarda Niceleyiciler

Hoca örneklerde "for every" ile "for some"ın sonucun true ya da false olmasını çok etkilediğine dikkat çekti.

**a) $\forall x\, (x^2 > x)$**

$x = 1$ için $1^2 = 1$, $1 > 1$ değildir. Yanlış. 1 bir karşı örnektir. Slaytta karşı örnek olarak $x = \frac{1}{2}$ verilmişti.

> **Ders sonrası not:** Hoca $x = \frac{1}{2}$ için "1/4, 1/2'den büyüktür" dedi. Doğrusu $\frac{1}{4} < \frac{1}{2}$'dir; yani $x^2 > x$ sağlanmaz ve $\frac{1}{2}$ bu yüzden karşı örnektir.

**b) $\exists x\, (x > 1 \rightarrow x^2 > x)$**

"For some" var. Doğru yapan bir $x$ bulmak yeter. $x > 1$ olduğu sürece $x^2 > x$'tir. Yanlış yapan bir değer bulunamaz. Doğru.

**c) Son şık**

Hoca son şıkta bütün $x$'ler ve bütün $y$'ler için $x^2 + y^2 \geq 0$ olduğunu, kareler alındığı için bunun her zaman doğru olduğunu ve karşı örnek bulunamayacağını söyledi.

<!-- BELİRSİZ: Hoca son şıkkı "for some x, for every y" diye okuyup "bütün x'ler ve bütün y'ler için" diye açıkladı; niceleyicilerin slayttaki biçimi net değil. Kısa notta bu slayt için başka şıklar da var ($\forall x\, \forall y\, (x^2 < y + 1)$, $\exists x\, \exists y\, (x^2 + y^2 = 9)$); altyazıda bunlar okunmuyor. -->

**Soru:** (b) şıkkında "for some" deniyor ama hiçbir hatalı değer yok, her $x$ zaten sağlıyor. Bu durumda önermeye yanlış diyebilir miyiz, yoksa "every" demeye gerek yok mu?

**Cevap:** $x$ birden büyükse $x^2$ her zaman $x$'ten büyüktür. "For some" ile de "for every" ile de sonuç true olurdu. Yani "for some"da hepsinin sağlaması da olabilir. Karşı örnek için illa "for every" ya da "for some" gerekmez; şart öyle konabilir ki onu sağlamayan bir durum oluşur. Böyle bir kural yoktur.

### 16.11 "Hot and Muggy" Sorusu

**Soru:** İlk slayttaki "The summer in Champaign is hot and muggy" cümlesinin olumsuzu "isn't hot and muggy" olmalı değil mi?

**Cevap:** Soru "not kullanmadan yazın" dediği için kelimelerin zıtları kullanıldı.

(Doğru olumsuz için Bölüm 16.1'deki ders sonrası nota bakın.)

Hoca bir slaytta bir değişiklik, bir slaytta da bir hata olduğunu, bunlara bakıp öğrencilere bilgi göndereceğini söyleyerek dersi bitirdi.

## Örnek Sorular

Bu dersin videosu ve karesi olmadığı için sorular yalnız derste sözlü sorulanlardan alındı.

**1. (derste sözlü, 00:38:19)** $\lnot\big(\lnot(p \land q) \rightarrow (p \lor q)\big)$ ifadesinin değeri $p = 1, q = 0$ ve $p = 1, q = 1$ için nedir?

> **Çözüm:** İki durumda da sonuç 0'dır. Adımlar Bölüm 6.2'de. Tam tabloda yalnız $(0, 0)$ satırı 1'dir.

**2. (derste sözlü, 01:13:17 - 01:15:00)** Gerçel sayılarda şunlar doğru mu? (a) $\forall x\, (x^2 \geq 0)$ (b) $\forall x\, (x > 1 \rightarrow x + 1 > 1)$ (c) $\forall x\, (x \geq 0 \rightarrow x + 1 > 1)$

> **Çözüm:** (a) Doğru. (b) Doğru. (c) Yanlış; karşı örnek $x = 0$, çünkü $1 > 1$ değildir.

**3. (derste sözlü, 01:15:28)** Her çift pozitif tam sayı $n$ için $n^2 + n + 19$ asal mıdır?

> **Çözüm:** Hayır. $n = 2$ için $25 = 5 \cdot 5$.

**4. (derste sözlü, 01:17:30)** "You cannot ride the roller coaster if you are under 4 feet tall unless you are older than 16 years old." cümlesini önermelerle yazın.

> **Çözüm:** $q$: binebilirsin, $r$: boyun 4 fitin altında, $s$: 16 yaşından büyüksün. $(r \land \lnot s) \rightarrow \lnot q$. Derste gösterilen $(\lnot r \lor s) \rightarrow q$ denk değildir (Bölüm 9.3).

**5. (derste sözlü, 01:28:45)** $\exists x \in \mathbb{R},\ \frac{x}{x^2+1} = \frac{2}{5}$ doğru mu?

> **Çözüm:** Doğru. $x = 2$ (ya da $x = \frac{1}{2}$).

**6. (derste sözlü, 01:29:20)** Bazı asal $n$'ler için $n+1, n+2, n+3, n+4$ asal değildir. Doğru mu?

> **Çözüm:** Doğru. $n = 23$: 24, 25, 26, 27 asal değildir.

**7. (derste sözlü, 02:26:15)** $1 + 2 + \dots + n = \frac{n(n+2)}{2}$ formülünü tümevarımla ispatlamayı deneyin; neden çıkmadığını gösterin.

> **Çözüm (derste verilmedi):** Taban adımı tutmaz: $n = 1$ için $\frac{1 \cdot 3}{2} = \frac{3}{2} \neq 1$. Tümevarım adımı da tutmaz: $\frac{k(k+2)}{2} + (k+1) = \frac{k^2 + 4k + 2}{2}$, oysa $\frac{(k+1)(k+3)}{2} = \frac{k^2 + 4k + 3}{2}$. Fark her zaman $\frac{1}{2}$'dir. Formül yanlıştır. Python ile kontrol edildi.

**8. (derste sözlü, 02:35:07)** "not" kullanmadan olumsuzunu yazın: "Today is Thursday", "$2 + 1 = 3$", "There is no wind in Illinois".

> **Çözüm:** "Today is Monday or Tuesday or Wednesday or Friday or Saturday or Sunday." / "$2 + 1 < 3$ or $2 + 1 > 3$." / "There is wind in Illinois."

**9. (derste sözlü, 02:38:46)** $p$: finalden A, $q$: her alıştırmayı yapmak, $r$: dersten A. (a) "Dersten A aldın ama her alıştırmayı yapmadın." (b) "Finalden A aldın, her alıştırmayı yaptın ve dersten A aldın." (c) "Finalden A aldın ama her alıştırmayı yapmadın; yine de dersten A aldın."

> **Çözüm:** (a) $r \land \lnot q$ (b) $p \land q \land r$ (c) $p \land \lnot q \land r$.

**10. (derste sözlü, 02:46:17)** $p$ true, $q$ false, $r$ bilinmiyor. Verilen ifadeler true mu, false mu?

> **Çözüm:** $r$'ye hem 1 hem 0 verilir. Derste üç ifade de true çıktı. Örneğin $p \lor r = 1$. <!-- BELİRSİZ: diğer iki ifade altyazıda okunmuyor. -->

**11. (derste sözlü, 02:50:34)** $\big(\lnot p \land (p \rightarrow q)\big) \rightarrow \lnot q$ totoloji midir?

> **Çözüm:** Değildir. $p = 0, q = 1$ satırında 0'dır (Bölüm 16.6).

**12. (derste sözlü, 02:51:16)** Tam sayılarda karşı örnek bulun: (a) $\forall x\, \exists y\, (x = 1/y)$ (b) $\forall x\, \exists y\, (y^2 - x < 100)$ (c) $\forall x\, \forall y\, (x^2 \neq y^3)$

> **Çözüm:** (a) $x = 0$. (b) $x = -100$ (derste karıştı; bkz. Bölüm 16.7). (c) $x = y = 0$ ya da $x = y = 1$.

**13. (derste sözlü, 02:54:20)** $n$ pozitif tam sayı ise "$n$ çift $\leftrightarrow$ $7n + 4$ çift" önermesini ispatlayın.

> **Çözüm:** $n = 2k$ ise $7n + 4 = 2(7k + 2)$ çifttir. Diğer yön karşıt tersle: $n = 2k + 1$ ise $7n + 4 = 2(7k + 5) + 1$ tektir. İkinci yön derste yazılmadı.

**14. (derste sözlü, 02:58:34)** Gerçel sayılarda: (a) $\forall x\, (x^2 > x)$ (b) $\exists x\, (x > 1 \rightarrow x^2 > x)$

> **Çözüm:** (a) Yanlış; karşı örnek $x = 1$ ya da $x = \frac{1}{2}$. (b) Doğru.

## Dersin Toparlaması

Bu derste önermeler mantığından niceleyicilere ve ispat yöntemlerine geçildi. Mantıksal denklik, iki birleşik önermenin aynı doğruluk tablosunu vermesi olarak tanımlandı. Bu fikirle $p \rightarrow q \equiv \lnot p \lor q$, $p \rightarrow q \equiv \lnot q \rightarrow \lnot p$ ve $p \leftrightarrow q \equiv (p \rightarrow q) \land (q \rightarrow p)$ gösterildi; karşıtın ise denk olmadığı görüldü. Totoloji ve çelişki çıkış sütununa bakılarak tanındı. De Morgan kuralı önce önermelere, sonra niceleyicilere uygulandı: $\lnot \forall x\, P(x) \equiv \exists x\, \lnot P(x)$. Evrensel niceleyicinin sonlu kümede AND, varoluşsal niceleyicinin OR gibi davrandığı ve evrensel bir iddiayı çürütmek için tek bir karşı örneğin yettiği vurgulandı.

İspat kısmında doğrudan ispat ile karşıt tersle ispat ayrıldı. Karşıt tersle ispatın geçerliliği dersin başındaki denklik tablosuna dayanır. Tümevarımla ispatta taban adımı ve tümevarım adımı üç örnekle uygulandı. Hoca derste ileride Karnaugh diyagramlarıyla sadeleştirme yapılacağını, sayı teorisinde de doğruluk tablosu satırlarının ikili sayı karşılığına dönüleceğini söyledi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
