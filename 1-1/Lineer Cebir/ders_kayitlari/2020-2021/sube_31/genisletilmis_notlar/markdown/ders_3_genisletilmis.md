# Ders 3 Genişletilmiş Notu: Dik Matrisler, Karmaşık Matrisler (Hermityen ve Üniter), Satır Eşelon Formu ve Elementer Satır İşlemleri

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dik (Orthogonal) Matrisler
- 2. Karmaşık Matrisler, Eşlenik ve Eşlenik Devrik ($A^H = A^*$)
- 3. Hermityen, Ters Hermityen ve Üniter Matrisler
- 4. Matrisin Eşelon Formu: İndirgenmiş Satır Eşelon Formu (RREF) ve Satır Eşelon Formu (REF)
- 5. Elementer Satır İşlemleri (Elementary Row Operations) ve Satır Denkliği
- 6. Bir Matrisi REF ve RREF Formuna İndirgeme Yöntemi (Pivot Kavramı)
- Örnek Sorular
- Dersin Toparlaması

## 1. Dik (Orthogonal) Matrisler

Hoca derse geçen hafta özel kare matrislerin incelendiğini hatırlatarak ve o konunun devamı olan **dik matrisler** (orthogonal matrices) ile başladı (ekrandan, 00:12:10):

- **Tanım:** Elemanları reel sayılar olan bir $A$ matrisinin devriği (transpose) kendi tersine (inverse) eşitse, yani
  $$A^T = A^{-1}$$
  koşulunu sağlıyorsa $A$ matrisine **dik matris** (orthogonal matrix) denir.

$A^T = A^{-1}$ eşitliğinin her iki tarafı sağdan (veya soldan) $A$ ile çarpıldığında, $A^{-1} A = I$ olduğundan dik matris koşulu

$$A A^T = A^T A = I$$

biçiminde ifade edilir. Bu tanımdan dolayı bir dik matris zorunlu olarak **kare matris** ve **tersinir** (invertible) olmalıdır.

### 1.1 Dik Matris Örneği

Hoca, verilen bir matrisin dik olup olmadığının nasıl kontrol edileceğini şu örnek üzerinde gösterdi (ekrandan, 00:12:10):

- **Verilen:**
  $$A = \begin{pmatrix} \cos\theta & \sin\theta \\ -\sin\theta & \cos\theta \end{pmatrix}$$
  matrisinin dik (orthogonal) olup olmadığını kontrol ediniz.
- **Çözüm:**
  1. Önce $A$ matrisinin satırları ile sütunları yer değiştirilerek devriği ($A^T$) bulunur:
     $$A^T = \begin{pmatrix} \cos\theta & -\sin\theta \\ \sin\theta & \cos\theta \end{pmatrix}$$
  2. Her iki matris de $2 \times 2$ kare matris olduğundan $A$ ile $A^T$ çarpılır:
     $$A A^T = \begin{pmatrix} \cos\theta & \sin\theta \\ -\sin\theta & \cos\theta \end{pmatrix} \begin{pmatrix} \cos\theta & -\sin\theta \\ \sin\theta & \cos\theta \end{pmatrix}$$
     - 1. satır 1. sütun: $\cos^2\theta + \sin^2\theta = 1$
     - 1. satır 2. sütun: $-\cos\theta\sin\theta + \sin\theta\cos\theta = 0$
     - 2. satır 1. sütun: $-\sin\theta\cos\theta + \cos\theta\sin\theta = 0$
     - 2. satır 2. sütun: $\sin^2\theta + \cos^2\theta = 1$
     $$A A^T = \begin{pmatrix} 1 & 0 \\ 0 & 1 \end{pmatrix} = I_2$$
  3. **Sonuç:** $A A^T = I_2$ eşitliği sağlandığından $A$ bir dik (orthogonal) matristir.

## 2. Karmaşık Matrisler, Eşlenik ve Eşlenik Devrik ($A^H = A^*$)

### 2.1 Karmaşık Sayılar ve Eşlenik Hatırlatması

Karmaşık matrisleri tanımlamadan önce karmaşık sayılar kümesi ($\mathbb{C}$) hatırlatılır:

$$\mathbb{C} = \{a + bi \mid a, b \in \mathbb{R},\ i^2 = -1\}$$

Bir $c = a + bi$ karmaşık sayısında $a$ reel kısımdır (real part), $b$ ise sanal kısımdır (imaginary part). $c = a + bi$ karmaşık sayısının **eşleniği** (conjugate of $c$), $\bar{c}$ ile gösterilir ve yalnızca sanal kısmın işaretinin değiştirilmesiyle elde edilir:

$$\bar{c} = a - bi$$

**Soru:** Eğer bir sayıda sanal kısım yoksa (yani sayı bir reel sayı ise) eşleniği nedir?
**Cevap:** Sanal kısmı olmayan bir sayı reel sayıdır ($b = 0$) ve her reel sayının karmaşık eşleniği kendisine eşittir ($\bar{a} = a$).

### 2.2 Karmaşık Matrisin Eşleniği ve Eşlenik Devriği

Elemanları karmaşık sayılar olan bir $A = [a_{ij}]$ matrisine **karmaşık matris** (complex matrix) denir. $A$ matrisinin eşleniği (conjugate of $A$), $\bar{A}$ ile gösterilir ve $A$'nın her bir elemanının eşleniği alınarak bulunur:

$$\bar{A} = [\bar{a}_{ij}]$$

Bir matrisin devriğini alma (transposition) ve eşleniğini alma (conjugation) işlemleri birbiriyle değişmelidir (commute). Yani önce matrisin eşleniğini alıp sonra devriğini almak ile önce devriğini alıp sonra eşleniğini almak aynı sonucu verir. Bu birleşik işlem $A^H$ veya $A^*$ ile gösterilir (ekrandan, 00:22:35):

$$A^H = A^* = (\bar{A})^T = \overline{(A^T)}$$

**Soru:** Burada $A^H$ (veya $A^*$) ile ifade edilen şey tam olarak karmaşık matrisin kendisini mi yoksa eşleniğini mi ifade ediyor?
**Cevap:** $A^H = A^* = (\bar{A})^T = \overline{(A^T)}$ eşitliğinden görüldüğü üzere, $A^H$ (veya $A^*$) doğrudan $A$ matrisinin **eşleniğinin devriğini** (veya devriğinin eşleniğini) ifade eder.

### 2.3 Eşlenik Devrik ($A^H = A^*$) Hesaplama Örneği

Hoca $A^H = A^*$ matrisinin nasıl bulunduğunu şu örnekle gösterdi (ekrandan, 00:22:35):

- **Verilen:**
  $$A = \begin{pmatrix} 2+8i & 5-3i & 4-7i \\ 6i & 1-4i & 3+2i \end{pmatrix}$$
  matrisi için $A^H = A^*$ matrisini bulunuz.
- **1. Adım (Eşlenik matris $\bar{A}$'nın bulunması):** Her bir elemanın sanal kısmının işareti değiştirilir:
  - $\overline{2+8i} = 2-8i$, $\overline{5-3i} = 5+3i$, $\overline{4-7i} = 4+7i$
  - $\overline{6i} = -6i$, $\overline{1-4i} = 1+4i$, $\overline{3+2i} = 3-2i$
  $$\bar{A} = \begin{bmatrix} 2-8i & 5+3i & 4+7i \\ -6i & 1+4i & 3-2i \end{bmatrix}$$
- **2. Adım ($\bar{A}$ matrisinin devriğinin alınması):** $\bar{A}$'nın satırları sütun olarak yazılır:
  $$A^H = A^* = (\bar{A})^T = \begin{bmatrix} 2-8i & -6i \\ 5+3i & 1+4i \\ 4+7i & 3-2i \end{bmatrix}$$

## 3. Hermityen, Ters Hermityen ve Üniter Matrisler

Reel kare matrislerdeki simetrik, ters simetrik ve dik matris kavramlarının karmaşık matrislerdeki karşılıkları Hermityen, ters Hermityen ve üniter matrislerdir.

### 3.1 Hermityen Matris (Hermitian Matrix)

Bir $A$ karmaşık kare matrisinin eşleniğinin devriği kendisine eşitse, yani

$$A^H = A^* = A$$

ise $A$ matrisine **Hermityen matris** (Hermitian matrix) denir (ekrandan, 00:34:05).

Bir $n \times n$ boyutlu $A = [a_{ij}]$ matrisinde $A = A^*$ eşitliğini eleman bazında incelersek:
1. **Esas köşegen elemanları ($i = j$):** Devrik alma işlemi esas köşegeni değiştirmediğinden, köşegen üzerinde $a_{11} = \bar{a}_{11}, a_{22} = \bar{a}_{22}, \dots, a_{nn} = \bar{a}_{nn}$ (genel olarak $a_{ii} = \bar{a}_{ii}$) eşitliği sağlanmalıdır. Bir sayının kendi eşleniğine eşit olması yalnızca o sayının **reel sayı** olmasıyla mümkündür. Dolayısıyla bir Hermityen matrisin esas köşegeni üzerindeki tüm elemanlar **reel sayı** olmak zorundadır.
2. **Köşegen dışındaki elemanlar ($i \neq j$):** Her $i$ ve $j$ için simetrik konumdaki elemanlar birbirinin karmaşık eşleniğidir:
   $$a_{ij} = \bar{a}_{ji}$$

### 3.2 Ters Hermityen Matris (Skew-Hermitian Matrix)

Bir $A$ karmaşık kare matrisinin eşleniğinin devriği kendisinin negatifine eşitse, yani

$$A^H = A^* = -A$$

ise $A$ matrisine **ters Hermityen matris** (skew-Hermitian matrix) denir (ekrandan, 00:34:05).

Bu koşul eleman bazında incelendiğinde iki temel şart ortaya çıkar:
1. **Esas köşegen elemanları ($i = j$):** Her $i$ için $a_{ii} = -\bar{a}_{ii}$ olmalıdır. Bu eşitliği sağlayan bir $a_{ii}$ sayısı ya **$0$** olmalıdır ($0 = -0$) ya da **yalnızca sanal kısımdan oluşan (pür sanal / complex number with only imaginary part)** bir karmaşık sayı olmalıdır (örneğin $a_{11} = i$ ise $\bar{a}_{11} = -i$ ve $-\bar{a}_{11} = -(-i) = i = a_{11}$ olur). Esas köşegen üzerinde sıfırdan farklı bir reel sayı bulunamaz.
2. **Köşegen dışındaki elemanlar ($i \neq j$):** Her $i$ ve $j$ için
   $$a_{ij} = -\bar{a}_{ji}$$
   koşulu sağlanmalıdır.

### 3.3 Üniter Matris (Unitary Matrix)

Bir $A$ karmaşık kare matrisinin kendi eşlenik devriği ($A^*$) ile çarpımı birim matrisi veriyorsa, yani

$$A^* A = A A^* = I \quad (\text{veya } A^* = A^{-1})$$

koşulu sağlanıyorsa $A$ matrisine **üniter matris** (unitary matrix) denir.

### 3.4 Karmaşık Matris Örneklerinin İncelenmesi

Hoca slayttaki iki karmaşık matrisi Hermityen, ters Hermityen ve üniterlik açısından inceledi (ekrandan, 00:38:30):

$$A = \begin{pmatrix} 3 & 1-2i & 4+7i \\ 1+2i & -4 & -2i \\ 4-7i & 2i & 5 \end{pmatrix}, \quad B = \frac{1}{2}\begin{pmatrix} 1 & -i & -1+i \\ i & 1 & 1+i \\ 1+i & -1+i & 0 \end{pmatrix}$$

- **$A$ matrisinin incelenmesi:**
  1. Esas köşegen üzerindeki elemanlar $3, -4$ ve $5$'tir; üçü de reel sayıdır (1. şart sağlandı).
  2. Köşegen dışındaki simetrik elemanlara bakıldığında:
     - $a_{21} = 1+2i$ ve $\bar{a}_{12} = \overline{1-2i} = 1+2i \implies a_{21} = \bar{a}_{12}$
     - $a_{31} = 4-7i$ ve $\bar{a}_{13} = \overline{4+7i} = 4-7i \implies a_{31} = \bar{a}_{13}$
     - $a_{32} = 2i$ ve $\bar{a}_{23} = \overline{-2i} = 2i \implies a_{32} = \bar{a}_{23}$
  Tüm $i, j$ için $a_{ij} = \bar{a}_{ji}$ sağlandığından $A$ matrisi **Hermityen bir matristir**.

- **$B$ matrisinin incelenmesi:**
  - **Soru:** $B$ matrisi neden ters Hermityen veya Hermityen değildir?
  - **Cevap:**
    1. Ters Hermityen (skew-Hermitian) olabilmesi için esas köşegen elemanlarının $0$ veya pür sanal sayı olması gerekir. Oysa $B$'nin esas köşegeninde $\frac{1}{2}$ (yani parantez içinde $1$) gibi sıfırdan farklı reel sayılar vardır; bu yüzden ters Hermityen değildir.
    2. Hermityen olabilmesi için esas köşegen elemanları reeldir ($1, 1, 0$) ve $b_{21} = i = \overline{-i} = \bar{b}_{12}$ koşulu sağlanır; ancak 1. satır 3. sütundaki $-1+i$ elemanının eşleniği $-1-i$ iken, 3. satır 1. sütundaki eleman $1+i$'dir ($1+i \neq -1-i$). Dolayısıyla $B$ Hermityen de değildir.
    3. Buna karşılık $B^* B = I_3$ çarpımı yapıldığında birim matris elde edilir; yani $B$ bir **üniter matristir** (unitary matrix). Hoca $B^* B = I_3$ çarpımının açık olarak doğrulanmasını öğrencilere alıştırma olarak bıraktı.

## 4. Matrisin Eşelon Formu: İndirgenmiş Satır Eşelon Formu (RREF) ve Satır Eşelon Formu (REF)

Özel kare matrisler tamamlandıktan sonra doğrusal denklem sistemlerinin çözümünde temel rol oynayan **eşelon form** (echelon form) konusuna geçildi. "Echelon" kelimesi merdiven basamağı (staircase) anlamına gelir.

### 4.1 İndirgenmiş Satır Eşelon Formu (Reduced Row Echelon Form - RREF)

Bir $m \times n$ boyutlu $A$ matrisi aşağıdaki dört özelliği sağlıyorsa **indirgenmiş satır eşelon formunda** (reduced row echelon form, kısaca RREF) olduğu söylenir (ekrandan, 00:47:15):

- **a)** Tamamen sıfırlardan oluşan satırlar (zero rows) varsa, bunlar matrisin **en altında** (at the bottom of the matrix) yer alır.
- **b)** Sıfırdan farklı her satırın soldan ilk sıfırdan farklı elemanı **$1$**'dir. Bu elemana o satırın **öncü $1$'i** (leading one) denir.
- **c)** Sıfırdan farklı her satırda öncü $1$, kendisinden önceki (üstteki) satırlarda bulunan tüm öncü $1$'lerin **daha sağında ve altında** yer alır (sol üstten sağ alta doğru inen bir merdiven / staircase görünümü oluşturur).
- **d)** Bir sütunda öncü $1$ (leading one) varsa, o sütundaki **diğer tüm elemanlar sıfırdır** (hem öncü $1$'in altındaki hem de üstündeki elemanlar $0$'dır).

### 4.2 Satır Eşelon Formu (Row Echelon Form - REF)

Bir $m \times n$ matris, yukarıdaki dört özellikten yalnızca **ilk üçünü (a, b ve c özelliklerini)** sağlıyorsa bu matrisin **satır eşelon formunda** (row echelon form, kısaca REF) olduğu söylenir.

- Yani satır eşelon formunda (REF) yine sıfır satırları en alttadır, sıfırdan farklı her satırın ilk elemanı öncü $1$'dir ve öncü $1$'ler merdiven gibi sağa kayarak iner (dolayısıyla her öncü $1$'in **altındaki** elemanlar sıfırdır); ancak d özelliği şart olmadığı için öncü $1$'lerin **üstündeki** elemanlar sıfırdan farklı sayılar olabilir.
- İndirgenmiş satır eşelon formundaki (RREF) her matris aynı zamanda satır eşelon formundadır (REF), ancak tersi her zaman doğru değildir.

> **Hocanın vurgusu:** Benzer şekilde sütun eşelon formu (column echelon form) da tanımlanabilir; ancak hesaplamalarda karışıklığa yol açmamak için sütun eşelon formunu ve sütun işlemlerini **kullanmayacağız**, yalnızca satır eşelon formunu ve satır işlemlerini kullanacağız.

### 4.3 RREF ve REF Tanıma Örnekleri

Hoca, hangi matrislerin RREF veya REF olduğunu ayırt etmek için çeşitli örnekler inceledi:

1. **RREF Olan Matrisler (ekrandan, 00:53:20):**
   $$A = \begin{pmatrix} 1 & 0 & 0 & 0 \\ 0 & 1 & 0 & 0 \\ 0 & 0 & 1 & 0 \\ 0 & 0 & 0 & 1 \end{pmatrix}, \quad B = \begin{pmatrix} 1 & 0 & 0 & 0 & -2 & 4 \\ 0 & 1 & 0 & 0 & 4 & 8 \\ 0 & 0 & 0 & 1 & 7 & -2 \\ 0 & 0 & 0 & 0 & 0 & 0 \\ 0 & 0 & 0 & 0 & 0 & 0 \end{pmatrix}, \quad C = \begin{pmatrix} 1 & 2 & 0 & 0 & 1 \\ 0 & 0 & 1 & 2 & 3 \\ 0 & 0 & 0 & 0 & 0 \end{pmatrix}$$
   - $A$ matrisinde hiç sıfır satırı yoktur, her satırın ilk sıfırdan farklı elemanı $1$'dir, öncü $1$'ler merdiven şeklinde sağa-aşağı ilerler ve öncü $1$ içeren her sütundaki diğer tüm elemanlar $0$'dır.
   - $B$ matrisinde iki adet sıfır satırı en alttadır; 1., 2. ve 3. satırların ilk sıfırdan farklı elemanları $1$'dir (1., 2. ve 4. sütunlarda), merdiven yapısındadır ve öncü $1$'lerin bulunduğu 1., 2. ve 4. sütunlardaki diğer tüm elemanlar $0$'dır. (Öncü $1$ içermeyen 5. ve 6. sütunlarda $-2, 4, 7$ gibi sayıların bulunması RREF özelliğini bozmaz.)
   - $C$ matrisinde de sıfır satırı en alttadır, öncü $1$'ler 1. ve 3. sütundadır ve bu sütunlardaki diğer elemanlar $0$'dır (2. sütunda öncü $1$ olmadığı için oradaki $2$ sayısı kuralı bozmaz). Dolayısıyla $A, B, C$ matrislerinin üçü de **indirgenmiş satır eşelon formundadır (RREF)**.

2. **Eşelon Formda Olmayan veya Yalnızca REF Olan Matrisler (ekrandan, 00:56:15):**
   - **$D$ matrisi:** İkinci satırı tamamen sıfırlardan oluştuğu halde üçüncü satırında sıfırdan farklı elemanlar bulunduğu için (sıfır satırı en altta olmadığından, yani **a özelliğini sağlamadığından**) eşelon formda değildir.
   - **$E$ matrisi:** İkinci satırındaki soldan ilk sıfırdan farklı eleman $1$ değil $2$ olduğu için (**b özelliğini sağlamadığından**) eşelon formda değildir.
   - **$F$ matrisi:**
     $$F = \begin{pmatrix} 1 & 0 & 3 & 4 \\ 0 & 1 & -2 & 5 \\ 0 & 1 & 2 & 2 \\ 0 & 0 & 0 & 0 \end{pmatrix}$$
     3. satırdaki öncü $1$, 2. satırdaki öncü $1$'in sağında değil tam altında (aynı sütunda) yer aldığı için (**c ve d özelliklerini sağlamadığından**) eşelon formda değildir.
   - **$G$ ve $H$ matrisleri:**
     $$G = \begin{pmatrix} 1 & 2 & 3 & 4 \\ 0 & 1 & -2 & 5 \\ 0 & 0 & 1 & 2 \\ 0 & 0 & 0 & 0 \end{pmatrix}, \quad H = \begin{pmatrix} 1 & 5 & 0 & 2 & -2 & 4 \\ 0 & 1 & 0 & 3 & 4 & 8 \\ 0 & 0 & 0 & 1 & 7 & -2 \\ 0 & 0 & 0 & 0 & 0 & 0 \end{pmatrix}$$
     Bu iki matriste sıfır satırları en alttadır, sıfırdan farklı her satırın ilk elemanı $1$'dir ve öncü $1$'ler sağa doğru basamak (staircase) oluşturur; yani a, b ve c koşulları sağlanır. Ancak örneğin $G$ matrisinde 2. satır 2. sütundaki öncü $1$'in üstünde $2$ sayısı (ve 3. sütundaki öncü $1$'in üstünde $3$ ve $-2$ sayıları) vardır, yani $0$ değildir (d koşulu sağlanmaz). Bu nedenle $G$ ve $H$ matrisleri **indirgenmiş satır eşelon formunda (RREF) değildir**, yalnızca **satır eşelon formundadır (REF)**.

## 5. Elementer Satır İşlemleri (Elementary Row Operations) ve Satır Denkliği

Her matris, belirli satır işlemleri uygulanarak satır eşelon formuna (REF) veya indirgenmiş satır eşelon formuna (RREF) dönüştürülebilir. Bir $A$ matrisi üzerindeki **elementer satır işlemleri** (elementary row operations) üç tiptir (ekrandan, 01:02:15):

1. **Tip I (Type I - İki satırın yer değiştirmesi):** Matrisin herhangi iki satırı ($i$. ve $j$. satırları) birbiriyle yer değiştirilir.
   - Gösterim: $r_i \leftrightarrow r_j$ (sütun için $c_i \leftrightarrow c_j$)
2. **Tip II (Type II - Bir satırın sıfırdan farklı bir sayıyla çarpılması):** Matrisin $i$. satırı sıfırdan farklı bir $k$ skaleri ile çarpılarak yine $i$. satırın yerine yazılır.
   - Gösterim: $k r_i \to r_i$ ($k \neq 0$)
3. **Tip III (Type III - Bir satırın bir katının başka bir satıra eklenmesi):** Matrisin $i$. satırı bir $k$ skaleri ile çarpılıp $j$. satıra eklenir ve sonuç $j$. satırın yerine yazılır ($i$. satırın kendisi değişmez).
   - Gösterim: $k r_i + r_j \to r_j$

### 5.1 Üç Elementer Satır İşleminin Sayısal Örneği

Hoca aynı $A$ başlangıç matrisi üzerinde üç tip işlemi ayrı ayrı uygulayarak gösterdi (ekrandan, 01:08:30):

$$A = \begin{pmatrix} 0 & 0 & 1 & 2 \\ 2 & 3 & 0 & -2 \\ 3 & 3 & 6 & -9 \end{pmatrix}$$

- **Tip I Örneği ($A$ matrisinin 1. ve 3. satırlarının yer değiştirilmesi, $r_1 \leftrightarrow r_3$):**
  $$B = A_{r_1 \leftrightarrow r_3} = \begin{bmatrix} 3 & 3 & 6 & -9 \\ 2 & 3 & 0 & -2 \\ 0 & 0 & 1 & 2 \end{bmatrix}$$
- **Tip II Örneği ($A$ matrisinin 3. satırının $\frac{1}{3}$ ile çarpılması, $\frac{1}{3}r_3 \to r_3$):**
  $$C = A_{\frac{1}{3}r_3 \to r_3} = \begin{bmatrix} 0 & 0 & 1 & 2 \\ 2 & 3 & 0 & -2 \\ 1 & 1 & 2 & -3 \end{bmatrix}$$
- **Tip III Örneği ($A$ matrisinin 2. satırının $-2$ katının 3. satırına eklenmesi, $-2r_2 + r_3 \to r_3$):**
  1. ve 2. satırlar olduğu gibi kalır; 3. satır elemanları $(-2)(2)+3 = -1$, $(-2)(3)+3 = -3$, $(-2)(0)+6 = 6$, $(-2)(-2)+(-9) = 4 - 9 = -5$ olarak güncellenir:
  $$D = A_{-2r_2 + r_3 \to r_3} = \begin{bmatrix} 0 & 0 & 1 & 2 \\ 2 & 3 & 0 & -2 \\ -1 & -3 & 6 & -5 \end{bmatrix}$$

> **Ders sonrası not:** Hoca $D$ matrisinin 3. satır 1. sütun elemanını hesaplarken sözlü olarak "minus 4 plus 3, 1" demiş ve ilk başta $1$ yazmıştır; işlemin sonucu $(-2)(2) + 3 = -1$ olup ekranda önünde kısa bir çizgi/işaret bulunmaktadır (ekrandan, 01:08:30).

### 5.2 Satır Denkliği (Row Equivalence)

Bir $A$ matrisinden sonlu sayıda elementer satır işlemi uygulanarak bir $B$ matrisi elde edilebiliyorsa, $A$ ve $B$ matrislerine **satırca denk** (row equivalent) matrisler denir (ve bazen $A \sim B$ ile gösterilir).

Hoca satır denkliği için şu zincirleme örneği de gösterdi (ekrandan, 01:11:30):

$$A = \begin{pmatrix} 1 & 2 & 4 & 3 \\ 2 & 1 & 3 & 2 \\ 1 & -2 & 2 & 3 \end{pmatrix}$$

1. $A$'nın 3. satırının $2$ katı 2. satırına eklenirse ($2r_3 + r_2 \to r_2$):
   $$B = A_{2r_3 + r_2 \to r_2} = \begin{pmatrix} 1 & 2 & 4 & 3 \\ 4 & -3 & 7 & 8 \\ 1 & -2 & 2 & 3 \end{pmatrix}$$
   elde edilir; dolayısıyla $B$ matrisi $A$'ya satırca denktir.
2. Ardından $B$ matrisinin 1. satırı $2$ ile çarpılırsa ($2r_1 \to r_1$), 1. satırı $(2\ \ 4\ \ 8\ \ 6)$ olan $C$ matrisi elde edilir. $C$ matrisi $B$'ye satırca denktir; dolayısıyla geçişlilik gereği $C$ matrisi başlangıçtaki $A$ matrisine de satırca denktir.

## 6. Bir Matrisi REF ve RREF Formuna İndirgeme Yöntemi (Pivot Kavramı)

Hoca, bir matrisin eşelon forma indirgenmesiyle ilgili iki temel teoremi ve pivot tanımını verdi (ekrandan, 01:14:40):

- **Teorem 1:** Sıfırdan farklı her $m \times n$ boyutlu $A = [a_{ij}]$ matrisi, satır eşelon formundaki (REF) bir matrise satırca denktir.
- **Teorem 2:** Bir matrisin indirgenmiş satır eşelon formu (RREF) **tektir** (unique).
- **Pivot Sütunu ve Pivot Tanımı:** Herhangi bir matriste, soldan bakıldığında sıfırdan farklı eleman içeren ilk sütuna **pivot sütunu** (pivot column), pivot sütunundaki ilk sıfırdan farklı elemana ise **pivot** adı verilir.

### 6.1 Adım Adım REF ve RREF Bulma Örneği

Hoca dersin son bölümünde bir matrisin hem satır eşelon formunu (REF) hem de indirgenmiş satır eşelon formunu (RREF) adım adım buldu (ekrandan, 01:14:40 ve 01:26:50):

- **Verilen:**
  $$A = \begin{pmatrix} 0 & 0 & 1 & 2 \\ 2 & 3 & 0 & -2 \\ 3 & 3 & 6 & -9 \end{pmatrix}$$
  matrisinin REF ve RREF formlarını bulunuz.

- **1. Adım (1. sütunda ve 1. satırda öncü $1$ oluşturma):**
  $A$ matrisinin sıfırdan farklı eleman içeren ilk sütunu 1. sütundur (pivot sütunu). 1. satır 1. sütundaki eleman $0$ olduğu için 1. satıra sıfırdan farklı bir eleman taşımamız gerekir. 2. satırı da kullanabiliriz ancak 3. satırdaki $(3\ \ 3\ \ 6\ \ -9)$ elemanlarının hepsi $3$'e tam bölündüğü için kesirli sayılarla uğraşmamak adına 1. satır ile 3. satırı yer değiştirmek ($r_1 \leftrightarrow r_3$) çok daha kolaydır:
  $$B = A_{r_1 \leftrightarrow r_3} = \begin{pmatrix} 3 & 3 & 6 & -9 \\ 2 & 3 & 0 & -2 \\ 0 & 0 & 1 & 2 \end{pmatrix}$$
  Şimdi 1. satırı $\frac{1}{3}$ ile çarparak ($\frac{1}{3}r_1 \to r_1$) sol üst köşede ilk öncü $1$'i (leading one) elde ederiz:
  $$C = B_{\frac{1}{3}r_1 \to r_1} = \begin{pmatrix} 1 & 1 & 2 & -3 \\ 2 & 3 & 0 & -2 \\ 0 & 0 & 1 & 2 \end{pmatrix}$$

- **2. Adım (1. sütundaki öncü $1$'in altını sıfırlama ve REF elde etme):**
  1. sütundaki öncü $1$'in altında bulunan $2$ elemanını sıfırlamak için $C$ matrisinin 1. satırını $-2$ ile çarpıp 2. satıra ekleriz ($-2r_1 + r_2 \to r_2$):
  - 2. satırın yeni elemanları: $(-2)(1)+2 = 0$, $(-2)(1)+3 = 1$, $(-2)(2)+0 = -4$, $(-2)(-3)+(-2) = 6 - 2 = 4$.
  $$D = C_{-2r_1 + r_2 \to r_2} = \begin{pmatrix} 1 & 1 & 2 & -3 \\ 0 & 1 & -4 & 4 \\ 0 & 0 & 1 & 2 \end{pmatrix}$$
  $D$ matrisine bakıldığında: 1., 2. ve 3. satırların ilk sıfırdan farklı elemanları $1$'dir (öncü $1$'ler) ve her biri üsttekinin sağında olup altları tamamen sıfırdır. Dolayısıyla $D$ matrisi **satır eşelon formundadır (REF)**.

- **3. Adım (2. sütundaki öncü $1$'in üstünü sıfırlama):**
  İndirgenmiş satır eşelon formuna (RREF) ulaşmak için her öncü $1$'in bulunduğu sütundaki üst elemanları da sıfırlamalıyız. 2. satır 2. sütundaki öncü $1$'in altı zaten $0$'dır; üstündeki $1$ elemanını sıfırlamak için $D$ matrisinin 2. satırını $-1$ ile çarpıp 1. satıra ekleriz ($-r_2 + r_1 \to r_1$):
  - 1. satırın yeni elemanları: $0+1 = 1$, $-1+1 = 0$, $-(-4)+2 = 6$, $-4+(-3) = -7$.
  $$E = D_{-r_2 + r_1 \to r_1} = \begin{pmatrix} 1 & 0 & 6 & -7 \\ 0 & 1 & -4 & 4 \\ 0 & 0 & 1 & 2 \end{pmatrix}$$

- **4. Adım (3. sütundaki öncü $1$'in üstünü sıfırlama ve RREF elde etme):**
  3. satır 3. sütundaki öncü $1$'in üstünde bulunan $-4$ ve $6$ elemanlarını sıfırlamak için:
  - 3. satırın $4$ katını 2. satıra ekleriz ($4r_3 + r_2 \to r_2$): 2. satırın 3. elemanı $4(1) + (-4) = 0$, 4. elemanı $4(2) + 4 = 12$ olur.
  - 3. satırın $-6$ katını 1. satıra ekleriz ($-6r_3 + r_1 \to r_1$): 1. satırın 3. elemanı $(-6)(1) + 6 = 0$, 4. elemanı $(-6)(2) + (-7) = -12 - 7 = -19$ olur.
  $$\text{RREF}(A) = \begin{pmatrix} 1 & 0 & 0 & -19 \\ 0 & 1 & 0 & 12 \\ 0 & 0 & 1 & 2 \end{pmatrix}$$
  Böylece öncü $1$ içeren tüm sütunlardaki (1., 2. ve 3. sütunlar) diğer tüm elemanlar sıfırlanmış ve $A$'nın **indirgenmiş satır eşelon formu (RREF)** elde edilmiştir (ekrandan, 01:26:50).

## Örnek Sorular

### Soru 1: Dik (Orthogonal) Matris Kontrolü (ekrandan, 00:12:10)

**Soru:**
$$A = \begin{pmatrix} \cos\theta & \sin\theta \\ -\sin\theta & \cos\theta \end{pmatrix}$$
matrisinin dik (orthogonal) bir matris olduğunu gösteriniz.

**Çözüm:**
$A^T = \begin{pmatrix} \cos\theta & -\sin\theta \\ \sin\theta & \cos\theta \end{pmatrix}$ olup $A$ ile $A^T$ çarpıldığında:
$$A A^T = \begin{pmatrix} \cos^2\theta+\sin^2\theta & -\cos\theta\sin\theta+\sin\theta\cos\theta \\ -\sin\theta\cos\theta+\cos\theta\sin\theta & \sin^2\theta+\cos^2\theta \end{pmatrix} = \begin{pmatrix} 1 & 0 \\ 0 & 1 \end{pmatrix} = I_2$$
elde edilir. $A A^T = I_2$ (yani $A^T = A^{-1}$) olduğundan $A$ dik bir matristir.

### Soru 2: Karmaşık Matrisin Eşlenik Devriğini ($A^H = A^*$) Bulma (ekrandan, 00:22:35)

**Soru:**
$$A = \begin{pmatrix} 2+8i & 5-3i & 4-7i \\ 6i & 1-4i & 3+2i \end{pmatrix}$$
karmaşık matrisi için $A^H = A^*$ matrisini bulunuz.

**Çözüm:**
Önce tüm elemanların eşleniği alınarak $\bar{A}$ bulunur, ardından devriği alınır:
$$\bar{A} = \begin{bmatrix} 2-8i & 5+3i & 4+7i \\ -6i & 1+4i & 3-2i \end{bmatrix} \implies A^H = A^* = (\bar{A})^T = \begin{bmatrix} 2-8i & -6i \\ 5+3i & 1+4i \\ 4+7i & 3-2i \end{bmatrix}$$

### Soru 3: Hermityen ve Üniter Matris Kontrolü (ekrandan, 00:38:30)

**Soru:**
$$A = \begin{pmatrix} 3 & 1-2i & 4+7i \\ 1+2i & -4 & -2i \\ 4-7i & 2i & 5 \end{pmatrix}, \quad B = \frac{1}{2}\begin{pmatrix} 1 & -i & -1+i \\ i & 1 & 1+i \\ 1+i & -1+i & 0 \end{pmatrix}$$
matrislerinden $A$'nın Hermityen olduğunu, $B$'nin ise üniter (unitary) olduğunu gösteriniz.

**Çözüm:**
- **$A$ matrisi için:** Esas köşegen elemanları ($3, -4, 5$) reeldir ve köşegen dışındaki tüm elemanlar için $a_{ij} = \bar{a}_{ji}$ ($1+2i = \overline{1-2i}$, $4-7i = \overline{4+7i}$, $2i = \overline{-2i}$) eşitliği sağlandığından $A^* = A$'dır; yani $A$ Hermityen matristir.

> **Çözüm ($B$ matrisinin üniterliği derste ödev olarak bırakıldı):**
> $B$ matrisinin eşlenik devriği $B^* = (\bar{B})^T$ yazılıp $B^* B$ çarpımı hesaplanırsa:
> $$B^* = \frac{1}{2}\begin{pmatrix} 1 & -i & 1-i \\ i & 1 & -1-i \\ -1-i & 1-i & 0 \end{pmatrix}$$
> $$B^* B = \frac{1}{4}\begin{pmatrix} 1 & -i & 1-i \\ i & 1 & -1-i \\ -1-i & 1-i & 0 \end{pmatrix} \begin{pmatrix} 1 & -i & -1+i \\ i & 1 & 1+i \\ 1+i & -1+i & 0 \end{pmatrix} = \frac{1}{4}\begin{pmatrix} 1+1+2 & -i-i+2i & (-1+i)+(-i+1)+0 \\ i-i+0 & 1+1+2 & (-i-1)+(1+i)+0 \\ (-1-i)+(i-1)+0 & (i-1)+(1-i)+0 & 2+2+0 \end{pmatrix} = \frac{1}{4}\begin{pmatrix} 4 & 0 & 0 \\ 0 & 4 & 0 \\ 0 & 0 & 4 \end{pmatrix} = I_3$$
> $B^* B = I_3$ sağlandığından $B$ üniter bir matristir.

### Soru 4: Matrisin REF ve RREF Formlarını Bulma (ekrandan, 01:14:40 ve 01:26:50)

**Soru:**
$$A = \begin{pmatrix} 0 & 0 & 1 & 2 \\ 2 & 3 & 0 & -2 \\ 3 & 3 & 6 & -9 \end{pmatrix}$$
matrisinin satır eşelon formunu (REF) ve indirgenmiş satır eşelon formunu (RREF) bulunuz.

**Çözüm:**
1. $r_1 \leftrightarrow r_3$ işlemi uygulanır:
   $$B = \begin{pmatrix} 3 & 3 & 6 & -9 \\ 2 & 3 & 0 & -2 \\ 0 & 0 & 1 & 2 \end{pmatrix}$$
2. $\frac{1}{3}r_1 \to r_1$ işlemi uygulanır:
   $$C = \begin{pmatrix} 1 & 1 & 2 & -3 \\ 2 & 3 & 0 & -2 \\ 0 & 0 & 1 & 2 \end{pmatrix}$$
3. $-2r_1 + r_2 \to r_2$ işlemi uygulanarak **satır eşelon formu (REF)** elde edilir:
   $$D = \text{REF}(A) = \begin{pmatrix} 1 & 1 & 2 & -3 \\ 0 & 1 & -4 & 4 \\ 0 & 0 & 1 & 2 \end{pmatrix}$$
4. $-r_2 + r_1 \to r_1$ işlemi uygulanır:
   $$E = \begin{pmatrix} 1 & 0 & 6 & -7 \\ 0 & 1 & -4 & 4 \\ 0 & 0 & 1 & 2 \end{pmatrix}$$
5. $4r_3 + r_2 \to r_2$ ve $-6r_3 + r_1 \to r_1$ işlemleri uygulanarak **indirgenmiş satır eşelon formu (RREF)** elde edilir:
   $$\text{RREF}(A) = \begin{pmatrix} 1 & 0 & 0 & -19 \\ 0 & 1 & 0 & 12 \\ 0 & 0 & 1 & 2 \end{pmatrix}$$

## Dersin Toparlaması

Bu derste ilk olarak reel kare matrislerde devriği tersine eşit olan ($A^T = A^{-1}$) dik (orthogonal) matrisler işlendi. Ardından karmaşık matrisler, karmaşık eşlenik ($\bar{A}$), eşlenik devrik ($A^H = A^* = (\bar{A})^T$) tanımlanarak karmaşık kare matrislerde Hermityen ($A^* = A$), ters Hermityen ($A^* = -A$) ve üniter ($A^* A = I$) matris türleri esas köşegen ve simetri özellikleriyle birlikte incelendi. Dersin ikinci yarısında ise matrislerin satır eşelon formu (REF) ve indirgenmiş satır eşelon formu (RREF) tanımlandı; üç tip elementer satır işlemi ($r_i \leftrightarrow r_j$, $k r_i \to r_i$, $k r_i + r_j \to r_j$), satır denkliği ve pivot kavramı kullanılarak bir matrisin adım adım REF ve RREF formlarına nasıl indirgendiği gösterildi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
