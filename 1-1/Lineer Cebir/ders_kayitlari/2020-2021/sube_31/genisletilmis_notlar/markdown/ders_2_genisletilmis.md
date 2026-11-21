# Ders 2 Genişletilmiş Notu: Matris Çarpımı, İz ve Ters Matris Özellikleri, Özel Kare Matrisler

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. İki Vektörün İç Çarpımı (Dot / Inner Product)
- 2. Matris Çarpımı (Matrix Multiplication)
- 3. Matris Çarpımında Değişme Özelliği ve $AB$ ile $BA$ Karşılaştırması
- 4. Matrisin İzi (Trace) ve Tersinir (Invertible) Matrisler
- 5. Kuvvetlerine Göre Özel Kare Matrisler: Periyodik, İdempotent, Nilpotent ve İnvolütif
- 6. Yapılarına Göre Özel Kare Matrisler: Köşegen, Skaler ve Üçgensel Matrisler
- 7. Simetrik ve Ters Simetrik (Skew-Symmetric) Matrisler
- Örnek Sorular
- Dersin Toparlaması

## 1. İki Vektörün İç Çarpımı (Dot / Inner Product)

Hoca derse geçen hafta matrislerin, matris toplamının ve temel özelliklerin tanıtıldığını hatırlatarak başladı. Bu haftanın konusu matris çarpımı (matrix multiplication) ve bazı özel kare matrislerdir (special square matrices).

Matris çarpımını tanımlamadan önce $\mathbb{R}^n$ uzayındaki iki $n$-vektörün ($n \times 1$ boyutlu matrislerin) **nokta çarpımı** veya **iç çarpımı** (dot product / inner product) tanımlanır. Elemanları reel sayılar olan iki $n$-vektör $a$ ve $b$ şu şekilde verilsin (ekrandan, 00:04:40):

$$a = \begin{bmatrix} a_1 \\ a_2 \\ \vdots \\ a_n \end{bmatrix}, \quad b = \begin{bmatrix} b_1 \\ b_2 \\ \vdots \\ b_n \end{bmatrix}$$

Bu iki vektörün iç çarpımı bir nokta ($\cdot$) ile gösterilir ve karşılıklı elemanların çarpımlarının toplamı olarak tanımlanır:

$$a \cdot b = a_1 b_1 + a_2 b_2 + \dots + a_n b_n$$

## 2. Matris Çarpımı (Matrix Multiplication)

İki vektörün iç çarpımı tanımlandıktan sonra iki matrisin çarpımı bu kavram üzerine kurulur. $A = [a_{ij}]$ bir $m \times p$ matris ve $B = [b_{ij}]$ bir $p \times n$ matris olsun. Bu durumda $A$ ve $B$'nin çarpımı olan $AB$, boyutu $m \times n$ olan $C = [c_{ij}]$ matrisidir.

Çarpım matrisinin $(i, j)$ konumundaki $c_{ij}$ elemanı, birinci matris $A$'nın $i$. satırı ile ikinci matris $B$'nin $j$. sütununun iç çarpımı (dot product) alınarak bulunur:

$$c_{ij} = a_{i1}b_{1j} + a_{i2}b_{2j} + \dots + a_{ip}b_{pj} = \sum_{k=1}^{p} a_{ik}b_{kj}$$

### 2.1 Matris Çarpımında Boyut Şartı

İki matrisi çarpabilmek için **birinci matrisin sütun sayısı, ikinci matrisin satır sayısına eşit olmalıdır**. Hoca bu kuralı boyut şeması üzerinde şöyle gösterdi (ekrandan, 00:11:20):

$$\underset{m \times p}{A} \times \underset{p \times n}{B} = \underset{m \times n}{AB}$$

Burada içteki iki boyut ($p$ ve $p$) birbirine eşit olmak zorundadır (the same); dıştaki iki boyut ($m$ ve $n$) ise çarpım sonucunda oluşan $AB$ matrisinin boyutunu ($m \times n$) verir.

**Soru:** Ortak boyut olan $p$ tam sayısının diğer boyutlardan ($m$ ve $n$'den) büyük veya küçük olması durumu değiştirir mi?
**Cevap:** Hayır, $p$ bir pozitif tam sayıdır; diğer boyutlardan büyük veya küçük olması hiçbir şeyi değiştirmez. Tek şart birinci matrisin sütun sayısının ikinci matrisin satır sayısına eşit olmasıdır.

### 2.2 Matris Çarpımı Sayısal Örneği

Hoca matris çarpımının adım adım nasıl yapıldığını göstermek için şu örneği çözdü (ekrandan, 00:18:30):

- **Verilen:**
  $$A = \begin{pmatrix} 1 & 3 \\ 2 & -1 \end{pmatrix}_{2 \times 2}, \quad B = \begin{pmatrix} 2 & 0 & -4 \\ 5 & -2 & 6 \end{pmatrix}_{2 \times 3}$$
  matrisleri için $AB$ çarpımını bulunuz.
- **Boyut Kontrolü:** $A$ matrisi $2 \times 2$, $B$ matrisi ise $2 \times 3$ boyutludur. $A$'nın sütun sayısı ($2$) ile $B$'nin satır sayısı ($2$) eşit olduğundan $AB$ çarpımı tanımlıdır ve sonuç matrisi $C = AB$ bir $2 \times 3$ matristir.
- **İşlem:** $A$'nın her bir satırı ile $B$'nin her bir sütununun iç çarpımı alınır:
  - **1. satır elemanları ($c_{11}, c_{12}, c_{13}$):**
    - $c_{11}$ ($A$'nın 1. satırı ile $B$'nin 1. sütunu): $1 \cdot 2 + 3 \cdot 5 = 2 + 15 = 17$
    - $c_{12}$ ($A$'nın 1. satırı ile $B$'nin 2. sütunu): $1 \cdot 0 + 3 \cdot (-2) = 0 - 6 = -6$
    - $c_{13}$ ($A$'nın 1. satırı ile $B$'nin 3. sütunu): $1 \cdot (-4) + 3 \cdot 6 = -4 + 18 = 14$
  - **2. satır elemanları ($c_{21}, c_{22}, c_{23}$):**
    - $c_{21}$ ($A$'nın 2. satırı ile $B$'nin 1. sütunu): $2 \cdot 2 + (-1) \cdot 5 = 4 - 5 = -1$
    - $c_{22}$ ($A$'nın 2. satırı ile $B$'nin 2. sütunu): $2 \cdot 0 + (-1) \cdot (-2) = 0 + 2 = 2$
    - $c_{23}$ ($A$'nın 2. satırı ile $B$'nin 3. sütunu): $2 \cdot (-4) + (-1) \cdot 6 = -8 - 6 = -14$
- **Sonuç:**
  $$AB = \begin{pmatrix} 17 & -6 & 14 \\ -1 & 2 & -14 \end{pmatrix}_{2 \times 3}$$

## 3. Matris Çarpımında Değişme Özelliği ve $AB$ ile $BA$ Karşılaştırması

Hoca, iki kare matrisin çarpımında sıranın önemli olup olmadığını görmek için ikinci bir örnek çözdü (ekrandan, 00:22:05):

- **Verilen:**
  $$A = \begin{pmatrix} 1 & 2 \\ 3 & 4 \end{pmatrix}_{2 \times 2}, \quad B = \begin{pmatrix} 5 & 6 \\ 0 & -2 \end{pmatrix}_{2 \times 2}$$
  Her iki matris de $2 \times 2$ boyutlu kare matris olduğundan hem $AB$ hem de $BA$ çarpımı tanımlıdır ve ikisi de $2 \times 2$ boyutludur.
- **$AB$ Çarpımı:**
  $$AB = \begin{pmatrix} 1 & 2 \\ 3 & 4 \end{pmatrix} \begin{pmatrix} 5 & 6 \\ 0 & -2 \end{pmatrix} = \begin{pmatrix} 1\cdot 5 + 2\cdot 0 & 1\cdot 6 + 2\cdot(-2) \\ 3\cdot 5 + 4\cdot 0 & 3\cdot 6 + 4\cdot(-2) \end{pmatrix} = \begin{pmatrix} 5 & 2 \\ 15 & 10 \end{pmatrix}$$
- **$BA$ Çarpımı:**
  $$BA = \begin{pmatrix} 5 & 6 \\ 0 & -2 \end{pmatrix} \begin{pmatrix} 1 & 2 \\ 3 & 4 \end{pmatrix} = \begin{pmatrix} 5\cdot 1 + 6\cdot 3 & 5\cdot 2 + 6\cdot 4 \\ 0\cdot 1 + (-2)\cdot 3 & 0\cdot 2 + (-2)\cdot 4 \end{pmatrix} = \begin{pmatrix} 23 & 34 \\ -6 & -8 \end{pmatrix}$$
- **Sonuç:** $AB \neq BA$.

> **Hocanın vurgusu:** Bu örnekten görüldüğü üzere, genel olarak matris çarpımının **değişme özelliği yoktur** (matrix multiplication does not have a commutative property). Ayrıca bir matris sıfır matrisiyle çarpıldığında sonuç yine sıfır matrisidir.

### 3.1 $AB$ Tanımlı İken $BA$ İçin Dört Olası Durum

$A$ bir $m \times p$ matris ve $B$ bir $p \times n$ matris olsun. Bu durumda $AB$ çarpımı tanımlıdır ve $m \times n$ boyutlu bir matristir. Ters sıradaki $BA$ çarpımı için ise dört farklı durum ortaya çıkabilir (ekrandan, 00:30:10):

1. **$BA$ tanımlı olmayabilir (may not be defined):** $B$ matrisi $p \times n$ ve $A$ matrisi $m \times p$ boyutlu olduğundan, $BA$'nın tanımlı olması için $B$'nin sütun sayısının ($n$) $A$'nın satır sayısına ($m$) eşit olması gerekir. Eğer $n \neq m$ ise $BA$ çarpımı tanımlı değildir.
2. **$BA$ tanımlı olabilir ancak $AB$ ile farklı boyutta olabilir:** Eğer $n = m$ ise $BA$ çarpımı tanımlıdır. Bu durumda $BA$ matrisi $p \times p$ boyutlu bir kare matris iken, $AB$ matrisi $m \times m$ boyutlu bir kare matristir. Eğer $m \neq p$ ise $AB$ ve $BA$'nın boyutları birbirinden farklıdır.
3. **$AB$ ve $BA$ aynı boyutta ($m = n = p$) olup birbirine eşit olabilir ($AB = BA$).**
4. **$AB$ ve $BA$ aynı boyutta ($m = n = p$) olup birbirinden farklı olabilir ($AB \neq BA$).** (Yukarıdaki $2 \times 2$ örneğinde olduğu gibi.)

**Soru:** İkinci durumda $n = m$ olduğunda $AB$'nin boyutu $m \times m$ mi yoksa $m \times n$ mi olur?
**Cevap:** Normalde $AB$'nin boyutu $m \times n$'dir; ancak ikinci durumda $BA$'nın tanımlı olabilmesi için $n = m$ şartı sağlandığından $AB$'nin boyutu $m \times m$ (veya $n \times n$), $BA$'nın boyutu ise $p \times p$ olur.

Ayrıca matris çarpımları ve toplamları tanımlı olduğu sürece çarpmanın **birleşme özelliği** (associative law) geçerlidir (ekrandan, 00:30:10):

$$(AB)C = A(BC)$$

## 4. Matrisin İzi (Trace) ve Tersinir (Invertible) Matrisler

### 4.1 Matrisin İzinin Özellikleri

Hoca geçen hafta tanımlanan devrik matrisi ($A^T$), kare matrisi ve kare matrisin esas köşegen elemanlarının toplamı olan izi ($\text{Tr}(A)$) kısaca hatırlattıktan sonra iz işleminin özelliklerini veren teoremi sundu (ekrandan, 00:40:45):

- **Teorem:** $A = [a_{ij}]$ ve $B = [b_{ij}]$, $n \times n$ boyutlu kare matrisler ve $k$ bir skaler olsun. Bu durumda:
  1. $\text{Tr}(A + B) = \text{Tr}(A) + \text{Tr}(B)$
  2. $\text{Tr}(A^T) = \text{Tr}(A)$
  3. $\text{Tr}(kA) = k\,\text{Tr}(A)$
  4. $\text{Tr}(AB) = \text{Tr}(BA)$

> **Hocanın vurgusu:** Bu teoremdeki 4. özellik ($\text{Tr}(AB) = \text{Tr}(BA)$) en önemli özelliktir; çünkü matris çarpımında genel olarak $AB \neq BA$ olmasına rağmen, $AB$ ve $BA$ çarpımlarının izleri birbirine eşittir.

### 4.2 Tersinir (Tekil Olmayan / Regüler) Matrisler

Bir $A$ kare matrisi için

$$AB = BA = I$$

(burada $I$ birim matristir / identity matrix) eşitliğini sağlayan bir $B$ kare matrisi varsa, $A$ matrisine **tersinir** (invertible) veya **tekil olmayan** (nonsingular) matris (bazı Türkçe kaynaklarda **regüler matris**) denir. Bu durumda $B$ matrisine $A$'nın **tersi** (inverse of $A$) adı verilir ve $B = A^{-1}$ biçiminde gösterilir. Aynı şekilde $A$ da $B$'nin tersidir ($A = B^{-1}$) ve $B$ de tersinir bir matristir.

> **Hocanın vurgusu:** $A$ ve $B$ tersinir matrisler olduğunda çarpımları olan $AB$ matrisi de tersinirdir ve çarpımın tersi alınırken matrislerin çarpım sırası tersine döner (ekrandan, 00:44:25):
> $$(AB)^{-1} = B^{-1}A^{-1}$$
> Daha genel olarak, $A_1, A_2, \dots, A_k$ tersinir matrisler ise çarpımlarının tersi, terslerinin ters sırada çarpımına eşittir:
> $$(A_1 A_2 \dots A_k)^{-1} = A_k^{-1} \dots A_2^{-1} A_1^{-1}$$

## 5. Kuvvetlerine Göre Özel Kare Matrisler: Periyodik, İdempotent, Nilpotent ve İnvolütif

### 5.1 Periyodik Matris (Periodic Matrix)

$A$ bir kare matris olsun. Eğer bazı pozitif $k$ tam sayıları için

$$A^{k+1} = A$$

eşitliği sağlanıyorsa $A$ matrisine **periyodik matris** (periodic matrix) denir. Bu koşulu sağlayan **en küçük pozitif $k$ tam sayısına** (the least / smallest positive integer) $A$ matrisinin **periyodu** (period of $A$) adı verilir (ekrandan, 00:53:45).

#### Periyodik Matris Örneği

Hoca, bir matrisin periyodik olduğunu ve periyodunun nasıl bulunduğunu göstermek için şu örneği adım adım çözdü (ekrandan, 00:53:45):

- **Verilen:**
  $$A = \begin{pmatrix} 1 & -2 & -6 \\ -3 & 2 & 9 \\ 2 & 0 & -3 \end{pmatrix}$$
  matrisi için $A^3$ kuvvetini ve periyodunu bulunuz.
- **1. Adım ($A^2 = A \cdot A$ hesabı):**
  $$A^2 = \begin{pmatrix} 1 & -2 & -6 \\ -3 & 2 & 9 \\ 2 & 0 & -3 \end{pmatrix} \begin{pmatrix} 1 & -2 & -6 \\ -3 & 2 & 9 \\ 2 & 0 & -3 \end{pmatrix}$$
  Satır ve sütunların iç çarpımları tek tek hesaplanır:
  - 1. satır:
    - $(1)(1) + (-2)(-3) + (-6)(2) = 1 + 6 - 12 = -5$
    - $(1)(-2) + (-2)(2) + (-6)(0) = -2 - 4 + 0 = -6$
    - $(1)(-6) + (-2)(9) + (-6)(-3) = -6 - 18 + 18 = -6$ (Hoca ilk başta $+6$ yazmış, bir öğrencinin uyarısıyla $-6$ olarak düzeltmiştir.)
  - 2. satır:
    - $(-3)(1) + (2)(-3) + (9)(2) = -3 - 6 + 18 = 9$
    - $(-3)(-2) + (2)(2) + (9)(0) = 6 + 4 + 0 = 10$
    - $(-3)(-6) + (2)(9) + (9)(-3) = 18 + 18 - 27 = 9$
  - 3. satır:
    - $(2)(1) + (0)(-3) + (-3)(2) = 2 + 0 - 6 = -4$
    - $(2)(-2) + (0)(2) + (-3)(0) = -4 + 0 + 0 = -4$
    - $(2)(-6) + (0)(9) + (-3)(-3) = -12 + 0 + 9 = -3$
  Böylece $A^2$ matrisi elde edilir:
  $$A^2 = \begin{pmatrix} -5 & -6 & -6 \\ 9 & 10 & 9 \\ -4 & -4 & -3 \end{pmatrix}$$
- **2. Adım ($A^3 = A^2 \cdot A$ hesabı):**
  $$A^3 = \begin{pmatrix} -5 & -6 & -6 \\ 9 & 10 & 9 \\ -4 & -4 & -3 \end{pmatrix} \begin{pmatrix} 1 & -2 & -6 \\ -3 & 2 & 9 \\ 2 & 0 & -3 \end{pmatrix}$$
  - 1. satır:
    - $(-5)(1) + (-6)(-3) + (-6)(2) = -5 + 18 - 12 = 1$
    - $(-5)(-2) + (-6)(2) + (-6)(0) = 10 - 12 + 0 = -2$
    - $(-5)(-6) + (-6)(9) + (-6)(-3) = 30 - 54 + 18 = -6$
  - 2. satır (ara adım eklendi):
    - $(9)(1) + (10)(-3) + (9)(2) = 9 - 30 + 18 = -3$
    - $(9)(-2) + (10)(2) + (9)(0) = -18 + 20 + 0 = 2$
    - $(9)(-6) + (10)(9) + (9)(-3) = -54 + 90 - 27 = 9$
  - 3. satır (ara adım eklendi):
    - $(-4)(1) + (-4)(-3) + (-3)(2) = -4 + 12 - 6 = 2$
    - $(-4)(-2) + (-4)(2) + (-3)(0) = 8 - 8 + 0 = 0$
    - $(-4)(-6) + (-4)(9) + (-3)(-3) = 24 - 36 + 9 = -3$
  $$A^3 = \begin{pmatrix} 1 & -2 & -6 \\ -3 & 2 & 9 \\ 2 & 0 & -3 \end{pmatrix} = A$$
- **Sonuç:** $A^3 = A^{2+1} = A$ eşitliği sağlandığından, $A$ matrisi periyodu $k = 2$ olan bir periyodik matristir.

**Soru:** Bir matrisin periyodik olması için herhangi bir kuvvetinin kendisine eşit olması yeterli midir?
**Cevap:** Evet, matrisin kendisinden sonraki bir kuvveti ($A^{k+1}$) yine kendisine ($A$'ya) eşit oluyorsa o matris periyodiktir.

### 5.2 İdempotent Matris (Idempotent Matrix)

Periyodik matris tanımında $k = 1$ alınırsa $A^{1+1} = A^2 = A$ olur. Karesi kendisine eşit olan ($A^2 = A$) bir $A$ kare matrisine **idempotent matris** (idempotent matrix) denir. Yani bir $A$ matrisi kendisiyle çarpıldığında yine $A$ matrisini veriyorsa idempotenttir.

### 5.3 Nilpotent Matris (Nilpotent Matrix)

$A$ bir kare matris olsun. Eğer bazı pozitif $k$ tam sayıları için

$$A^k = 0$$

(burada $0$, aynı boyuttaki sıfır matrisidir) eşitliği sağlanıyorsa $A$'ya **nilpotent matris** denir. $A^k = 0$ koşulunu sağlayan **en küçük pozitif $k$ tam sayısına** ise $A$'nın **nilpotentlik indisi** (nilpotency index of $A$) adı verilir. Örneğin sıfırdan farklı bir $A$ matrisi kendisiyle çarpıldığında sıfır matrisini veriyorsa ($A^2 = 0$), nilpotentlik indisi $2$ olan bir nilpotent matristir.

### 5.4 İnvolütif Matris (Involute / Involutory Matrix)

Bir $A$ kare matrisinin karesi uygun boyuttaki birim matrise eşitse ($A^2 = I$), bu matrise **involütif matris** (involute / involutory matrix) denir. Slaytta verilen örnek şudur (ekrandan, 00:59:40):

$$A = \begin{pmatrix} -5 & -8 & 0 \\ 3 & 5 & 0 \\ 1 & 2 & -1 \end{pmatrix} \implies A^2 = I_3$$

olduğundan bu $A$ matrisi involütif bir matristir.

**Soru:** Bir matris aynı anda hem nilpotent hem de idempotent olabilir mi?
**Cevap:** $A$ matrisinin idempotent olduğunu varsayalım; bu durumda $A^2 = A$ olur. Nilpotent olması için ise bir $k$ pozitif tam sayısı için $A^k = 0$ olması gerekir. Oysa idempotent bir matrisin kuvvetlerine bakıldığında:
$$A^1 = A, \quad A^2 = A, \quad A^3 = A^2 \cdot A = A \cdot A = A^2 = A$$
ve aynı şekilde devam edildiğinde her kuvveti yine $A$'ya eşit çıkar. Dolayısıyla (matrisin kendisi sıfır matrisi olmadığı sürece) hiçbir kuvveti sıfır matrisine eşit olamaz; yani yanıt **hayır**dır.

## 6. Yapılarına Göre Özel Kare Matrisler: Köşegen, Skaler ve Üçgensel Matrisler

### 6.1 Köşegen Matris (Diagonal Matrix) ve Skaler Matris (Scalar Matrix)

$D = [d_{ij}]$ bir $n \times n$ kare matris olsun. Eğer esas köşegen dışındaki tüm elemanları sıfır ise ($i \neq j$ için $d_{ij} = 0$), bu matrise **köşegen matris** (diagonal matrix) denir. Köşegen matrisler bazen yalnızca esas köşegen elemanları yazılarak

$$D = \text{diag}(d_{11}, d_{22}, \dots, d_{nn})$$

biçiminde gösterilir veya matris içinde köşegen dışındaki sıfırlar hiç yazılmadan boş bırakılır. Burada esas köşegen üzerindeki $d_{ii}$ elemanlarının bazıları veya tamamı sıfır olabilir. Slaytta verilen köşegen matris örnekleri şunlardır (ekrandan, 01:09:35):

$$\begin{pmatrix} 3 & 0 & 0 \\ 0 & -7 & 0 \\ 0 & 0 & 2 \end{pmatrix}, \quad \begin{pmatrix} 4 & 0 \\ 0 & -5 \end{pmatrix}, \quad \begin{pmatrix} 6 & & & \\ & 0 & & \\ & & -9 & \\ & & & 8 \end{pmatrix}$$

**Soru:** $n \times n$ boyutlu sıfır matrisi (zero matrix) bir köşegen matris midir?
**Cevap:** Evet. Köşegen matris tanımında önemli olan esas köşegen dışındaki tüm elemanların $0$ olmasıdır; esas köşegen üzerindeki elemanlar $0$ da olabilir, sıfırdan farklı da olabilir. Dolayısıyla kare sıfır matrisi de bir köşegen matristir.

**Soru:** Köşegen matris mutlaka kare matris olmak zorunda mıdır?
**Cevap:** Evet, esas köşegen yalnızca kare matrislerde tanımlı olduğu için köşegen matrisler mutlaka kare matris olmalıdır.

**Soru:** Birim matrisin ($I_n$) bir $k$ skaleri ile çarpımı olan skaler matrisler (scalar matrices) köşegen matris midir?
**Cevap:** Evet. Bir skaler matris

$$kI_n = \begin{bmatrix} k & 0 & \dots & 0 \\ 0 & k & \dots & 0 \\ \vdots & \vdots & \ddots & \vdots \\ 0 & 0 & \dots & k \end{bmatrix}$$

biçimindedir (ekrandan, 01:09:35). Esas köşegen dışındaki tüm elemanları $0$ olduğu için her skaler matris aynı zamanda bir köşegen matristir.

### 6.2 Üçgensel Matrisler (Triangular Matrices)

$A = [a_{ij}]$ bir $n \times n$ kare matris olsun (ekrandan, 01:16:50):

- **Üst Üçgensel Matris (Upper Triangular Matrix):** Esas köşegenin **altındaki** tüm elemanları sıfır olan, yani $i > j$ için $a_{ij} = 0$ koşulunu sağlayan kare matristir. Bu matrislerde sıfırdan farklı elemanlar yalnızca esas köşegen üzerinde ve esas köşegenin üstünde bulunabilir:
  $$\begin{pmatrix} a_{11} & a_{12} \\ 0 & a_{22} \end{pmatrix}, \quad \begin{pmatrix} b_{11} & b_{12} & b_{13} \\ 0 & b_{22} & b_{23} \\ 0 & 0 & b_{33} \end{pmatrix}$$
- **Alt Üçgensel Matris (Lower Triangular Matrix):** Esas köşegenin **üstündeki** tüm elemanları sıfır olan, yani $i < j$ için $a_{ij} = 0$ koşulunu sağlayan kare matristir. Bu matrislerde sıfırdan farklı elemanlar yalnızca esas köşegen üzerinde ve esas köşegenin altında bulunabilir.

**Soru:** Bir köşegen matris ile üst üçgensel matris arasındaki fark nedir? Köşegen matris üst üçgensel midir yoksa alt üçgensel midir?
**Cevap:** Köşegen matriste hem esas köşegenin altındaki hem de üstündeki tüm elemanlar sıfırdır. Bu nedenle bir köşegen matris **hem alt üçgensel hem de üst üçgensel** bir matristir. Buna karşılık bir üst üçgensel matriste (örneğin $2 \times 2$ boyutlu üst üçgensel matriste) esas köşegenin üstündeki $a_{12}$ elemanı sıfırdan farklıysa, bu matris üst üçgenseldir ama köşegen matris değildir.

## 7. Simetrik ve Ters Simetrik (Skew-Symmetric) Matrisler

### 7.1 Simetrik Matris (Symmetric Matrix)

Bir $A$ kare matrisinin devriği (transpose) kendisine eşitse, yani

$$A^T = A$$

ise $A$ matrisine **simetrik matris** (symmetric matrix) denir. Bir matrisin devriği alındığında satır ve sütun sayıları yer değiştirdiği için, $A^T = A$ eşitliğinin sağlanabilmesi adına $A$'nın mutlaka bir **kare matris** ($n \times n$) olması gerekir.

Devrik alındığında esas köşegen elemanları ($a_{11}, a_{22}, \dots, a_{nn}$) yer değiştirmez. Köşegen dışındaki elemanlar için ise $A^T = A$ koşulu, her $i$ ve $j$ için

$$a_{ij} = a_{ji}$$

olması anlamına gelir (örneğin $a_{12} = a_{21}$, $a_{13} = a_{31}$). Yani elemanlar esas köşegene göre simetriktir.

### 7.2 Ters Simetrik Matris (Skew-Symmetric Matrix)

Bir $A$ kare matrisinin devriği kendisinin negatifine ($-1$ ile çarpımına) eşitse, yani

$$A^T = -A$$

ise $A$ matrisine **ters simetrik matris** (skew-symmetric matrix) denir. Bu tanımdan her $i$ ve $j$ için

$$a_{ij} = -a_{ji}$$

koşulu elde edilir. Özel olarak esas köşegen üzerindeki elemanlar ($i = j$) için devrik alındığında konumları değişmediğinden

$$a_{11} = -a_{11}, \quad a_{22} = -a_{22}, \quad \dots, \quad a_{nn} = -a_{nn}$$

yani genel olarak $a_{ii} = -a_{ii} \implies 2a_{ii} = 0 \implies a_{ii} = 0$ olmak zorundadır.

> **Hocanın vurgusu:** Ters simetrik (skew-symmetric) bir matriste:
> 1. $a_{ij} = -a_{ji}$ eşitliği sağlanır.
> 2. Esas köşegen üzerindeki tüm elemanlar **sıfır olmak zorundadır** ($a_{ii} = 0$).
> Bu nedenle bir matrisin simetrik mi yoksa ters simetrik mi olduğunu belirlerken ilk olarak kare matris olup olmadığına ve esas köşegenine bakılır.

### 7.3 Simetrik ve Ters Simetrik Matris Örnekleri

Hoca dersin sonunda üç matris örneği üzerinde simetri ve ters simetri kontrolü yaptı (ekrandan, 01:29:15):

$$A = \begin{pmatrix} 2 & -3 & 5 \\ -3 & 6 & 7 \\ 5 & 7 & -8 \end{pmatrix}, \quad B = \begin{pmatrix} 0 & 3 & -4 \\ -3 & 0 & 5 \\ 4 & -5 & 0 \end{pmatrix}, \quad C = \begin{pmatrix} 1 & 0 & 0 \\ 0 & 0 & 1 \end{pmatrix}$$

- **$A$ matrisinin incelenmesi:** $A$ bir $3 \times 3$ kare matristir. Esas köşegene ($2, 6, -8$) göre karşılıklı elemanlara bakıldığında $a_{12} = a_{21} = -3$, $a_{13} = a_{31} = 5$ ve $a_{23} = a_{32} = 7$ olduğu görülür. Tüm elemanlar esas köşegene göre simetrik olduğundan ($A^T = A$), $A$ **simetrik bir matristir**.
- **$B$ matrisinin incelenmesi:** $B$ bir $3 \times 3$ kare matristir ve esas köşegen üzerindeki tüm elemanları sıfırdır ($0, 0, 0$); dolayısıyla ters simetrik matris olmaya adaydır. Köşegen dışındaki elemanlara bakıldığında $b_{12} = 3$ iken $b_{21} = -3$, $b_{13} = -4$ iken $b_{31} = 4$ ve $b_{23} = 5$ iken $b_{32} = -5$ olduğu, yani her $i, j$ için $b_{ij} = -b_{ji}$ ($B^T = -B$) sağlandığı görülür. Dolayısıyla $B$ **ters simetrik (skew-symmetric) bir matristir**.
- **$C$ matrisinin incelenmesi:** $C$ matrisi $2 \times 3$ boyutludur ve kare matris değildir. Kare olmadığı için **ne simetrik ne de ters simetriktir** (neither symmetric nor skew-symmetric).

## Örnek Sorular

### Soru 1: Farklı Boyutlu İki Matrisin Çarpımı (ekrandan, 00:18:30)

**Soru:**
$$A = \begin{pmatrix} 1 & 3 \\ 2 & -1 \end{pmatrix}, \quad B = \begin{pmatrix} 2 & 0 & -4 \\ 5 & -2 & 6 \end{pmatrix}$$
matrisleri için $AB$ çarpımını bulunuz.

**Çözüm:**
$A$ matrisi $2 \times 2$ ve $B$ matrisi $2 \times 3$ boyutlu olduğundan $AB$ çarpımı tanımlıdır ve boyutu $2 \times 3$'tür:
$$AB = \begin{pmatrix} 1\cdot 2 + 3\cdot 5 & 1\cdot 0 + 3\cdot(-2) & 1\cdot(-4) + 3\cdot 6 \\ 2\cdot 2 + (-1)\cdot 5 & 2\cdot 0 + (-1)\cdot(-2) & 2\cdot(-4) + (-1)\cdot 6 \end{pmatrix} = \begin{pmatrix} 17 & -6 & 14 \\ -1 & 2 & -14 \end{pmatrix}$$

### Soru 2: $AB$ ve $BA$ Çarpımlarının Karşılaştırılması (ekrandan, 00:22:05)

**Soru:**
$$A = \begin{pmatrix} 1 & 2 \\ 3 & 4 \end{pmatrix}, \quad B = \begin{pmatrix} 5 & 6 \\ 0 & -2 \end{pmatrix}$$
matrisleri için $AB$ ve $BA$ çarpımlarını hesaplayarak karşılaştırınız.

**Çözüm:**
$$AB = \begin{pmatrix} 1 & 2 \\ 3 & 4 \end{pmatrix} \begin{pmatrix} 5 & 6 \\ 0 & -2 \end{pmatrix} = \begin{pmatrix} 5 & 2 \\ 15 & 10 \end{pmatrix}$$
$$BA = \begin{pmatrix} 5 & 6 \\ 0 & -2 \end{pmatrix} \begin{pmatrix} 1 & 2 \\ 3 & 4 \end{pmatrix} = \begin{pmatrix} 23 & 34 \\ -6 & -8 \end{pmatrix}$$
Sonuçlardan görüldüğü üzere $AB \neq BA$'dır.

### Soru 3: Periyodik Matrisin Periyodunu Bulma (ekrandan, 00:53:45)

**Soru:**
$$A = \begin{pmatrix} 1 & -2 & -6 \\ -3 & 2 & 9 \\ 2 & 0 & -3 \end{pmatrix}$$
matrisinin periyodik bir matris olduğunu gösteriniz ve periyodunu bulunuz.

**Çözüm:**
Önce $A^2 = A \cdot A$ hesaplanır:
$$A^2 = \begin{pmatrix} 1 & -2 & -6 \\ -3 & 2 & 9 \\ 2 & 0 & -3 \end{pmatrix} \begin{pmatrix} 1 & -2 & -6 \\ -3 & 2 & 9 \\ 2 & 0 & -3 \end{pmatrix} = \begin{pmatrix} -5 & -6 & -6 \\ 9 & 10 & 9 \\ -4 & -4 & -3 \end{pmatrix}$$
Sonra $A^3 = A^2 \cdot A$ hesaplanır:
$$A^3 = \begin{pmatrix} -5 & -6 & -6 \\ 9 & 10 & 9 \\ -4 & -4 & -3 \end{pmatrix} \begin{pmatrix} 1 & -2 & -6 \\ -3 & 2 & 9 \\ 2 & 0 & -3 \end{pmatrix} = \begin{pmatrix} 1 & -2 & -6 \\ -3 & 2 & 9 \\ 2 & 0 & -3 \end{pmatrix} = A$$
$A^3 = A^{2+1} = A$ eşitliğini sağlayan en küçük pozitif tam sayı $k = 2$ olduğundan, $A$ periyodu $2$ olan periyodik bir matristir.

### Soru 4: İdempotent ve Nilpotent Matris Özelliği (derste sözlü, 00:59:52)

**Soru:**
Sıfırdan farklı bir $A$ kare matrisi aynı zamanda hem idempotent hem de nilpotent olabilir mi?

**Çözüm:**
$A$ idempotent ise $A^2 = A$ eşitliğini sağlar. Bu durumda $A^3 = A^2 \cdot A = A \cdot A = A^2 = A$ ve genel olarak her $k \ge 1$ pozitif tam sayısı için $A^k = A$ olur. Dolayısıyla $A \neq 0$ iken hiçbir $k$ pozitif tam sayısı için $A^k = 0$ olamaz; yani sıfırdan farklı bir matris aynı anda hem idempotent hem nilpotent olamaz.

### Soru 5: Kare Sıfır Matrisi ve Skaler Matrisin Köşegenliği (derste sözlü, 01:05:08 ve 01:07:48)

**Soru:**
1. $n \times n$ boyutlu sıfır matrisi bir köşegen (diagonal) matris midir?
2. $kI_n$ biçimindeki skaler matrisler birer köşegen matris midir?

**Çözüm:**
1. Evet. Köşegen matris tanımı yalnızca esas köşegen dışındaki elemanların $0$ olmasını şart koşar; esas köşegen üzerindeki elemanlar da $0$ olabilir. Bu nedenle $n \times n$ sıfır matrisi bir köşegen matristir.
2. Evet. $kI_n = \text{diag}(k, k, \dots, k)$ matrisinde esas köşegen dışındaki tüm elemanlar $0$ olduğundan her skaler matris aynı zamanda bir köşegen matristir.

### Soru 6: Simetrik ve Ters Simetrik Matrisleri Belirleme (ekrandan, 01:29:15)

**Soru:**
$$A = \begin{pmatrix} 2 & -3 & 5 \\ -3 & 6 & 7 \\ 5 & 7 & -8 \end{pmatrix}, \quad B = \begin{pmatrix} 0 & 3 & -4 \\ -3 & 0 & 5 \\ 4 & -5 & 0 \end{pmatrix}, \quad C = \begin{pmatrix} 1 & 0 & 0 \\ 0 & 0 & 1 \end{pmatrix}$$
matrislerinin simetrik veya ters simetrik (skew-symmetric) olup olmadıklarını belirleyiniz.

**Çözüm:**
- $A$ matrisi $3 \times 3$ kare matristir ve her $i, j$ için $a_{ij} = a_{ji}$ ($A^T = A$) sağlandığından **simetrik** matristir.
- $B$ matrisi $3 \times 3$ kare matristir, esas köşegen elemanları $0$'dır ve her $i, j$ için $b_{ij} = -b_{ji}$ ($B^T = -B$) sağlandığından **ters simetrik** (skew-symmetric) matristir.
- $C$ matrisi $2 \times 3$ boyutlu olup kare matris olmadığından **ne simetrik ne de ters simetriktir**.

## Dersin Toparlaması

Bu derste ilk olarak $\mathbb{R}^n$'deki vektörlerin iç çarpımı (dot product) üzerinden iki matrisin çarpımı ($AB$) tanımlandı, boyut uyum şartı ($m \times p$ ile $p \times n$) incelendi ve matris çarpımının genel olarak değişme özelliğine sahip olmadığı ($AB \neq BA$) sayısal örneklerle gösterildi. Ardından iz (trace) fonksiyonunun özellikleri ($\text{Tr}(AB) = \text{Tr}(BA)$ dahil) ve tersinir (invertible / nonsingular) matrislerde çarpımın tersi kuralı ($(AB)^{-1} = B^{-1}A^{-1}$) ele alındı. Dersin ikinci yarısında ise özel kare matris türleri olan periyodik ($A^{k+1} = A$), idempotent ($A^2 = A$), nilpotent ($A^k = 0$), involütif ($A^2 = I$), köşegen (diagonal), skaler ($kI_n$), üst ve alt üçgensel (upper / lower triangular), simetrik ($A^T = A$) ve ters simetrik ($A^T = -A$) matrisler tanımlanarak örneklerle incelendi. Bir sonraki derste dik (orthogonal) matrislerle devam edileceği belirtildi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
