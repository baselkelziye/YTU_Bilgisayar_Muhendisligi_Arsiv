# Ders 7 Çalışma Özeti

## Genel Konular

- Ortogonal Matrisler ve Transpozun Determinantı Üzerine Soru Çözümü (Orthogonal Matrices and Determinant of Transpose)
  - Bir $A$ kare matrisi için $A A^T = A^T A = I_n$ eşitliği sağlanıyorsa $A$'ya **ortogonal matris** (orthogonal matrix) denir; bu durumda $A^T = A^{-1}$ olur (ekrandan, 00:12:40).
  - $A$ ve $B$ ortogonal matrisler ($A^T A = I_n$ ve $B B^T = I_n$) olduğunda:
    $$A^T(A + B)B^T = (A^T A + A^T B)B^T = (I_n + A^T B)B^T = B^T + A^T B B^T = B^T + A^T I_n = B^T + A^T = (A + B)^T$$
    elde edilir. $\det(M^T) = \det(M)$ özelliği gereği:
    - $\det(A^T(A + B)B^T) = \det((A + B)^T) = \det(A + B)$
    - $\det(A^T + B) = \det((A^T + B)^T) = \det((A^T)^T + B^T) = \det(A + B^T)$
    - $\det(A^T + B^T) = \det((A + B)^T) = \det(A + B)$
    ifadelerinin üçü de her zaman doğrudur (ekrandan, 00:12:40).
- Simetrik, Ters Simetrik ve Hermityen Matris Özellikleri (Symmetric, Skew-Symmetric, and Hermitian Matrices)
  - Sıfırdan farklı herhangi bir $n \times n$ boyutlu $A$ kare matrisi için $B = A + A^T$ ve $C = A - A^T$ tanımlandığında (ekrandan, 00:19:15):
    - $B^T = (A + A^T)^T = A^T + (A^T)^T = A^T + A = B$ olduğundan $B$ daima **simetrik** (symmetric) bir matristir ($B \neq 0$ iken aynı anda ters simetrik olamaz).
    - $C^T = (A - A^T)^T = A^T - (A^T)^T = A^T - A = -(A - A^T) = -C$ olduğundan $C$ daima **ters simetrik** (skew-symmetric) bir matristir.
    - Kompleks bir $M$ matrisinin **Hermityen** (Hermitian) olması için eşleniğinin transpozunun kendisine eşit olması ($(\overline{M})^T = M$) gerekir. $C = A - A^T$ için $(\overline{C})^T = (\overline{A})^T - \overline{A} \neq A - A^T$ olduğundan $C$ genel olarak Hermityen değildir.
  - $A$ ve $B$ matrisleri $n \times n$ boyutlu kompleks Hermityen matrisler ($(\overline{A})^T = A$ ve $(\overline{B})^T = B$) olmak üzere (ekrandan, 00:37:50):
    - $C_1 = A + B$ için $(\overline{C_1})^T = (\overline{A + B})^T = (\overline{A})^T + (\overline{B})^T = A + B = C_1$ olduğundan iki Hermityen matrisin toplamı daima Hermityendir.
    - $C_3 = AB$ için $(\overline{C_3})^T = (\overline{AB})^T = (\overline{B})^T (\overline{A})^T = BA$ olur; matris çarpımında genel olarak değişme özelliği olmadığından ($AB \neq BA$), iki Hermityen matrisin çarpımı genel olarak Hermityen değildir.
- Determinant Özellikleriyle Vandermonde Tipi ve Satır/Sütun İşlemli Determinant Soruları (Determinant Factorization and Row/Column Operations)
  - $\begin{vmatrix} 1 & 1 & 1 \\ a & b & c \\ a^2 & b^2 & c^2 \end{vmatrix}$ determinantında $-c_1 + c_2 \to c_2$ ve $-c_1 + c_3 \to c_3$ sütun işlemleri uygulanıp 2. sütun $(b-a)$, 3. sütun $(c-a)$ ortak çarpan parantezine alındıktan sonra 1. satıra göre Laplace açılımı yapıldığında sonuç $(b-a)(c-a)(c-b)$ olarak çarpanlarına ayrılır (ekrandan, 00:27:10).
  - Elementer satır/sütun işlemleri, satır yer değiştirme (işaret değiştirir), bir satır veya sütundan skaler çarpan çıkarma ve $\det(M^T) = \det(M)$ özellikleri birlikte kullanılarak karmaşık bir determinant bilinen bir determinant cinsinden ifade edilebilir (ekrandan, 00:54:00 ve 01:04:35).
  - $A, B \in M_3(\mathbb{R})$ ($3 \times 3$ boyutlu reel matrisler) için $\det(kA) = k^3 \det(A)$, $\det(A^T) = \det(A)$, $\det(AB) = \det(A)\det(B)$ ve $\det(M^{-1}) = \frac{1}{\det(M)}$ kurallarıyla bileşik matris ifadelerinin determinantı hesaplanır (ekrandan, 01:37:55).
- Ters Matris ve İç Çarpım ile Matris Çarpımının Belirli Bir Elemanını Bulma (Finding Specific Entries in Matrix Multiplication)
  - $A$ ve $AB = C$ matrisleri verildiğinde $B$ matrisini bulmak için eşitlik **soldan** $A^{-1}$ ile çarpılır: $A^{-1}(AB) = (A^{-1}A)B = I B = B$ (ekrandan, 00:48:50).
  - Bir $C = X Y$ çarpım matrisinin yalnızca belirli bir $c_{ij}$ elemanı sorulduğunda tüm matris çarpımını hesaplamaya gerek yoktur; yalnızca ilk matrisin $i$. satırı ile ikinci matrisin $j$. sütununun iç çarpımı (dot product) alınır: $c_{ij} = \text{row}_i(X)^T \cdot \text{col}_j(Y)$ (ekrandan, 00:48:50 ve 01:21:50).

## Hocanın Özellikle Vurguladığı Kısımlar

- Çarpım ve Eşlenik Transpoz Kuralları
  - Matris çarpımının transpozu alınırken sıra tersine döner: $(AB)^T = B^T A^T$. Aynı kural eşlenik transpoz için de geçerlidir: $(\overline{AB})^T = (\overline{B})^T (\overline{A})^T$ (ekrandan, 00:37:50).
- Matris Denklemlerinde Ters Matrisle Çarpma Yönü (Soldan vs. Sağdan Çarpma)
  - Matris çarpımında değişme özelliği ($AB = BA$) yoktur. Bu nedenle $AB = C$ denkleminden $B$'yi yalnız bırakmak için her iki taraf **soldan** $A^{-1}$ ile çarpılmalıdır ($B = A^{-1}C$). Eğer $BA = C$ verilmiş olsaydı, o zaman sağdan $A^{-1}$ ile çarpılırdı ($B = C A^{-1}$) (ekrandan, 00:48:50).
- Determinantta Ortak Çarpan Parantezine Alma Kuralı
  - Bir determinantta bir satır veya sütundan ortak çarpan dışarı alınırken, o çarpanın **ilgili satırdaki veya sütundaki tüm elemanların** ortak çarpanı olması şarttır (sıfır sayısı her sayının katı olduğundan $0 = (b-a)\cdot 0$ olarak ortak çarpanı bozmaz) (ekrandan, 00:27:10).
- $\det((2B)^{-1})$ Hesabında Skalerin Kuvveti
  - $3 \times 3$ boyutlu bir $B$ matrisi için $\det((2B)^{-1}) = \frac{1}{\det(2B)}$ olup paydadaki $\det(2B)$ hesaplanırken $2$ çarpanı $2^3 = 8$ olarak dışarı çıkar: $\det(2B) = 2^3 \det(B) = 8\det(B)$ (ekrandan, 01:37:55).

## Kısa Tekrar Notları

- Ortogonal matris: $A A^T = A^T A = I_n \iff A^T = A^{-1}$.
- Simetrik matris: $B^T = B$ (Her $A$ kare matrisi için $A + A^T$ simetriktir).
- Ters simetrik (Skew-symmetric) matris: $C^T = -C$ (Her $A$ kare matrisi için $A - A^T$ ters simetriktir).
- Hermityen (Hermitian) matris: $(\overline{A})^T = A$ ($A$ ve $B$ Hermityen ise $A + B$ Hermityendir; ancak $AB$ genel olarak Hermityen değildir çünkü $(\overline{AB})^T = BA$).
- $3 \times 3$ Vandermonde determinantı: $\begin{vmatrix} 1 & 1 & 1 \\ a & b & c \\ a^2 & b^2 & c^2 \end{vmatrix} = (b-a)(c-a)(c-b)$.
- $2 \times 2$ ters matris: $A = \begin{bmatrix} a & b \\ c & d \end{bmatrix} \implies A^{-1} = \frac{1}{ad - bc} \begin{bmatrix} d & -b \\ -c & a \end{bmatrix}$ (esas köşegen elemanları yer değiştirir, diğer köşegen elemanları işaret değiştirir).
- Çarpım matrisinin $(i, j)$ elemanı: $C = AB \implies c_{ij} = \text{row}_i(A)^T \cdot \text{col}_j(B) = \sum_{k=1}^{m} a_{ik}b_{kj}$.
- $A, B \in M_n(\mathbb{R})$ için: $\det(-A^T (2B)^{-1}) = (-1)^n \det(A) \cdot \frac{1}{2^n \det(B)}$.

## Detaylı Açıklamalar

- **Vandermonde Determinantının Çarpanlarına Ayrılması (ekrandan, 00:27:10):**
  $$\begin{vmatrix} 1 & 1 & 1 \\ a & b & c \\ a^2 & b^2 & c^2 \end{vmatrix}$$
  determinantını hesaplamak için 1. satırdaki ilk $1$'i kullanarak diğer iki $1$'i sıfırlayalım. Bunun için 1. sütunun $-1$ katını 2. sütuna ($-c_1 + c_2 \to c_2$) ve 3. sütuna ($-c_1 + c_3 \to c_3$) ekleyelim:
  $$= \begin{vmatrix} 1 & 0 & 0 \\ a & b-a & c-a \\ a^2 & b^2-a^2 & c^2-a^2 \end{vmatrix}$$
  İki kare farkından $b^2 - a^2 = (b-a)(b+a)$ ve $c^2 - a^2 = (c-a)(c+a)$ olduğundan, 2. sütundaki tüm elemanlar $(b-a)$'nın katı, 3. sütundaki tüm elemanlar ise $(c-a)$'nın katıdır. Bu ortak çarpanlar dışarı alındığında ve ardından 1. satıra göre Laplace açılımı uygulandığında:
  $$= (b-a)(c-a) \begin{vmatrix} 1 & 0 & 0 \\ a & 1 & 1 \\ a^2 & b+a & c+a \end{vmatrix} = (b-a)(c-a) \cdot 1 \cdot (-1)^{1+1} \begin{vmatrix} 1 & 1 \\ b+a & c+a \end{vmatrix}$$
  $$= (b-a)(c-a)((c+a) - (b+a)) = (b-a)(c-a)(c-b)$$
  bulunur.

- **Ters Matris ve İç Çarpım Yardımıyla Bilinmeyen Matrisin Tek Bir Elemanını Bulma (ekrandan, 00:48:50):**
  $A = \begin{bmatrix} 3 & 4 \\ 1 & 1 \end{bmatrix}$ ve $AB = \begin{bmatrix} 1 & 0 & -2 & 5 \\ 4 & -1 & 0 & 3 \end{bmatrix}$ verildiğinde $B$ matrisinin $(2, 4)$ konumundaki $b_{24}$ elemanını bulmak için:
  1. Önce $A^{-1}$ bulunur: $\det(A) = 3(1) - 4(1) = -1$ ve $\text{adj}(A) = \begin{bmatrix} 1 & -4 \\ -1 & 3 \end{bmatrix}$ olduğundan:
     $$A^{-1} = \frac{1}{-1} \begin{bmatrix} 1 & -4 \\ -1 & 3 \end{bmatrix} = \begin{bmatrix} -1 & 4 \\ 1 & -3 \end{bmatrix}$$
  2. $B = A^{-1}(AB)$ çarpımında tüm $B$ matrisini hesaplamak yerine yalnızca 2. satır ve 4. sütundaki $b_{24}$ elemanı arandığından, $A^{-1}$ matrisinin 2. satırı olan $[1\ \ -3]$ ile $AB$ matrisinin 4. sütunu olan $\begin{bmatrix} 5 \\ 3 \end{bmatrix}$ iç çarpıma sokulur:
     $$b_{24} = \text{row}_2(A^{-1})^T \cdot \text{col}_4(AB) = \begin{bmatrix} 1 & -3 \end{bmatrix} \begin{bmatrix} 5 \\ 3 \end{bmatrix} = 1(5) + (-3)(3) = 5 - 9 = -4$$

- **Determinant Özellikleriyle Bilinmeyen Determinant Hesabı (ekrandan, 00:54:00 ve 01:04:35):**
  $$\begin{vmatrix} 3c_1 & -3c_2 & 3c_3 \\ a_1+9c_1 & -a_2-9c_2 & a_3+9c_3 \\ -b_1 & b_2 & -b_3 \end{vmatrix} = 12 \quad \text{ise} \quad \det(B) = \begin{vmatrix} a_1 & b_1 & c_1 \\ a_2 & b_2 & c_2 \\ a_3 & b_3 & c_3 \end{vmatrix} = ?$$
  1. Verilen determinantta 1. satırın $-3$ katı 2. satıra eklenir ($-3r_1 + r_2 \to r_2$); bu işlem determinantı değiştirmez ve 2. satırdaki $9c_i$ terimleri sadeleşir:
     $$\begin{vmatrix} 3c_1 & -3c_2 & 3c_3 \\ a_1 & -a_2 & a_3 \\ -b_1 & b_2 & -b_3 \end{vmatrix} = 12$$
  2. $a$'ları 1. satıra, $b$'leri 2. satıra, $c$'leri 3. satıra getirmek için önce 1. ve 2. satır yer değiştirilir ($r_1 \leftrightarrow r_2$, önüne $-$ gelir), ardından 2. ve 3. satır yer değiştirilir ($r_2 \leftrightarrow r_3$, bir $-$ daha gelir ve işaret tekrar $+$ olur):
     $$\xrightarrow{r_1 \leftrightarrow r_2} -\begin{vmatrix} a_1 & -a_2 & a_3 \\ 3c_1 & -3c_2 & 3c_3 \\ -b_1 & b_2 & -b_3 \end{vmatrix} \xrightarrow{r_2 \leftrightarrow r_3} +\begin{vmatrix} a_1 & -a_2 & a_3 \\ -b_1 & b_2 & -b_3 \\ 3c_1 & -3c_2 & 3c_3 \end{vmatrix}$$
  3. 3. satırdaki $3$ ortak çarpanı dışarı alınır, ardından işaretleri düzeltmek için 2. sütun $-1$ ile ve 2. satır $-1$ ile çarpılır (iki kez $-1$ çarpanı geldiğinden $(-1)(-1) = +1$ olur):
     $$= 3 \begin{vmatrix} a_1 & -a_2 & a_3 \\ -b_1 & b_2 & -b_3 \\ c_1 & -c_2 & c_3 \end{vmatrix} = -3 \begin{vmatrix} a_1 & a_2 & a_3 \\ -b_1 & -b_2 & -b_3 \\ c_1 & c_2 & c_3 \end{vmatrix} = 3 \begin{vmatrix} a_1 & a_2 & a_3 \\ b_1 & b_2 & b_3 \\ c_1 & c_2 & c_3 \end{vmatrix}$$
  4. Elde edilen matris, sorulan $B$ matrisinin transpozudur ve $\det(B^T) = \det(B)$ olduğundan:
     $$3 \begin{vmatrix} a_1 & b_1 & c_1 \\ a_2 & b_2 & c_2 \\ a_3 & b_3 & c_3 \end{vmatrix} = 12 \implies \det(B) = \frac{12}{3} = 4$$
     bulunur.

- **Bileşik Matris İfadesinin Determinantı (ekrandan, 01:37:55):**
  $A, B \in M_3(\mathbb{R})$ için $\det(A) = 2$ ve $\det(B) = -1$ verildiğinde $\det[-A^T(2B)^{-1}]$ ifadesi:
  - $\det[-A^T(2B)^{-1}] = \det(-A^T) \cdot \det((2B)^{-1})$
  - Matrisler $3 \times 3$ boyutlu ($n = 3$) olduğundan $\det(-A^T) = (-1)^3 \det(A^T) = -1 \cdot \det(A) = -2$.
  - $\det((2B)^{-1}) = \frac{1}{\det(2B)} = \frac{1}{2^3 \det(B)} = \frac{1}{8(-1)} = -\frac{1}{8}$.
  - Çarpım: $(-2) \cdot \left(-\frac{1}{8}\right) = \frac{1}{4}$.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
