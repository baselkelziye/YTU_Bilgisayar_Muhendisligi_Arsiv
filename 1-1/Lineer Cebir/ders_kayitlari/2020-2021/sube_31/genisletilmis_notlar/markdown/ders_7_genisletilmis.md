# Ders 7 Genişletilmiş Notu: Matris Türleri, Matris Çarpımı ve Determinant Özellikleri Üzerine Soru Çözümü

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Ortogonal Matrisler ve Transpozun Determinantı (Soru 1A)
- 2. Simetrik, Ters Simetrik ve Hermityen Matrisler (Soru 6A ve Soru 14)
  - 2.1 $B = A + A^T$ ve $C = A - A^T$ Matrislerinin Özellikleri (Soru 6A)
  - 2.2 İki Kompleks Hermityen Matrisin Toplamı ve Çarpımı (Soru 14)
- 3. Determinant Özellikleri ve Çarpanlara Ayırma Soruları (Soru 7A, Soru 16 ve Soru 20A)
  - 3.1 Vandermonde Tipi Determinantın Çarpanlarına Ayrılması (Soru 7A)
  - 3.2 Satır/Sütun İşlemleri ve Transpoz ile Determinant Hesabı (Soru 16)
  - 3.3 Skaler Çarpım, Transpoz ve Ters Matrisin Determinantı (Soru 20A)
- 4. Ters Matris ve İç Çarpım ile Matris Çarpımının Belirli Bir Elemanını Bulma (Soru 15 ve Soru 1)
  - 4.1 $A$ ve $AB$ Verildiğinde $B$ Matrisinin $(2, 4)$ Elemanını Bulma (Soru 15)
  - 4.2 Kuralı Verilen Matrislerin Çarpımında $c_{44}$ Elemanını Bulma (Soru 1)
- Örnek Sorular
- Dersin Toparlaması

## 1. Ortogonal Matrisler ve Transpozun Determinantı (Soru 1A)

Hoca bu derste ilk beş haftanın konularını (matris cebiri, özel matris türleri, ters matris ve determinant özellikleri) kapsayan örnek sınav sorularını adım adım çözdü.

- **Soru (ekrandan, 00:12:40):**
  $A$ ve $B$ sıfırdan farklı reel bileşenli ortogonal matrisler (orthogonal matrices with all real entries) olmak üzere, aşağıdaki ifadelerden hangisi ya da hangileri **her zaman** doğrudur?
  1. $\det(A^T(A + B)B^T) = \det(A + B)$
  2. $\det(A^T + B) = \det(A + B^T)$
  3. $\det(A^T + B^T) = \det(A + B)^T$ (veya $\det((A + B)^T)$)

- **Çözüm ve Açıklama:**
  Öncelikle **ortogonal matris** (orthogonal matrix) tanımını hatırlayalım: Bir $A$ kare matrisi kendi transpozu ile çarpıldığında birim matrisi veriyorsa, yani:
  $$A A^T = A^T A = I_n$$
  eşitliği sağlanıyorsa $A$'ya ortogonal matris denir. Bu eşitliğin her iki tarafını soldan $A^{-1}$ ile çarparsak ortogonal matrislerin temel özelliğini elde ederiz:
  $$A^T = A^{-1}$$
  Soruda hem $A$ hem de $B$ ortogonal verildiğinden $A^T = A^{-1}$ ($A^T A = I_n$) ve $B^T = B^{-1}$ ($B B^T = I_n$) eşitlikleri geçerlidir.

  1. **I. İfadenin İncelenmesi:**
     Determinantın içindeki $A^T(A + B)B^T$ matris çarpımını açalım. Önce soldaki $A^T$'yi parantezin içine dağıtalım:
     $$A^T(A + B)B^T = (A^T A + A^T B)B^T$$
     $A$ ortogonal olduğundan $A^T A = I_n$ birim matrisidir:
     $$= (I_n + A^T B)B^T$$
     Şimdi sağdaki $B^T$'yi parantezin içine sağdan dağıtalım:
     $$= I_n B^T + A^T B B^T$$
     Birim matrisle çarpılan $I_n B^T = B^T$ olur; $B$ de ortogonal olduğundan $B B^T = I_n$ birim matrisidir ve $A^T I_n = A^T$ olur:
     $$= B^T + A^T = A^T + B^T = (A + B)^T$$
     Bir matrisin transpozunun determinantı kendisinin determinantına eşit olduğundan ($\det(M^T) = \det(M)$):
     $$\det(A^T(A + B)B^T) = \det((A + B)^T) = \det(A + B)$$
     elde edilir. Dolayısıyla **I. ifade her zaman doğrudur**.

  2. **II. İfadenin İncelenmesi:**
     Yine $\det(M) = \det(M^T)$ özelliğini $\det(A^T + B)$ ifadesine uygularsak, içerideki $(A^T + B)$ matrisinin transpozunu aldığımızda determinant değişmez:
     $$\det(A^T + B) = \det((A^T + B)^T) = \det((A^T)^T + B^T) = \det(A + B^T)$$
     Burada $(A^T)^T = A$ özelliğini kullandık. Dolayısıyla **II. ifade de her zaman doğrudur** (üstelik bu özellik $A$ ve $B$ ortogonal olmasa bile her kare matris çifti için doğrudur).

  3. **III. İfadenin İncelenmesi:**
     Toplamın transpozu özelliğinden $A^T + B^T = (A + B)^T$ olduğundan:
     $$\det(A^T + B^T) = \det((A + B)^T) = \det(A + B)$$
     olur ve **III. ifade de her zaman doğrudur**. (Hoca deneme sınavındaki şıklarda dizgi hatası nedeniyle yalnız "I ve III" yazıldığını, ancak üç öncülün de I, II ve III olarak her zaman doğru olduğunu belirtti.)

## 2. Simetrik, Ters Simetrik ve Hermityen Matrisler (Soru 6A ve Soru 14)

### 2.1 $B = A + A^T$ ve $C = A - A^T$ Matrislerinin Özellikleri (Soru 6A)

- **Soru (ekrandan, 00:19:15):**
  $A$, sıfırdan farklı $n \times n$ boyutlu bir matris ve $B = A + A^T$, $C = A - A^T$ olsun. Bu durumda aşağıdaki ifadelerden hangisi ya da hangileri doğrudur?
  - I. $B$ simetriktir ($B$ is symmetric).
  - II. $B$ ters simetriktir ($B$ is skew-symmetric).
  - III. $C$ Hermityendir ($C$ is Hermitian).
  - IV. $C$ ters simetriktir ($C$ is skew-symmetric).

- **Çözüm ve Açıklama:**
  1. **I. ve II. Öncüller ($B$ simetrik mi, ters simetrik mi?):**
     Bir $B$ matrisinin **simetrik** (symmetric) olması demek $B^T = B$ olması demektir. $B = A + A^T$ olarak tanımlandığına göre her iki tarafın transpozunu alalım:
     $$B^T = (A + A^T)^T = A^T + (A^T)^T = A^T + A = A + A^T = B$$
     $B^T = B$ çıktığı için **$B$ matrisi simetriktir** (I. öncül doğrudur). Sıfırdan farklı simetrik bir matris aynı zamanda ters simetrik olamayacağından **II. öncül yanlıştır**.

  2. **IV. Öncül ($C$ ters simetrik mi?):**
     Bir $C$ matrisinin **ters simetrik** (skew-symmetric) olması demek, transpozunun kendi eksilisine eşit olması ($C^T = -C$) demektir. $C = A - A^T$ matrisinin transpozunu alırsak:
     $$C^T = (A - A^T)^T = A^T - (A^T)^T = A^T - A = -(A - A^T) = -C$$
     $C^T = -C$ sağlandığından **$C$ matrisi ters simetriktir** (IV. öncül doğrudur).

  3. **III. Öncül ($C$ Hermityen mi?):**
     Kompleks bir $C$ matrisinin **Hermityen** (Hermitian) olması için eşleniğinin transpozunun (conjugate transpose) kendisine eşit olması gerekir:
     $$(\overline{C})^T = C$$
     $C = A - A^T$ matrisinin önce kompleks eşleniğini (conjugate) alalım:
     $$\overline{C} = \overline{A - A^T} = \overline{A} - \overline{A^T} = \overline{A} - (\overline{A})^T$$
     Şimdi bu ifadenin transpozunu alalım:
     $$(\overline{C})^T = \left(\overline{A} - (\overline{A})^T\right)^T = (\overline{A})^T - \overline{A}$$
     Oysa $C = A - A^T$ idi. $(\overline{A})^T - \overline{A}$ ifadesi genel olarak $A - A^T$'ye eşit olmadığından **$C$ Hermityen değildir** (III. öncül yanlıştır).
     Sonuç olarak **I ve IV** doğrudur (Cevap: c).

### 2.2 İki Kompleks Hermityen Matrisin Toplamı ve Çarpımı (Soru 14)

- **Soru (ekrandan, 00:37:50):**
  $A$ ve $B$, $n \times n$ boyutlu kompleks bileşenli Hermityen matrisler (complex Hermitian matrices) olmak üzere:
  $$C_1 = A + B, \quad C_2 = (3 + 2i)A + iB, \quad C_3 = AB$$
  matrislerinden hangisi ya da hangileri Hermityendir?
  a) $C_1$ $\quad$ b) $C_2$ $\quad$ c) $C_3$ $\quad$ d) Hepsi

- **Çözüm ve Açıklama:**
  $A$ ve $B$ matrisleri Hermityen olduğuna göre tanım gereği şu iki eşitliği biliyoruz:
  $$(\overline{A})^T = A \quad \text{ve} \quad (\overline{B})^T = B$$

  1. **$C_1 = A + B$ Matrisinin Kontrolü:**
     $C_1$'in eşlenik transpozunu hesaplayalım. Eşlenik ve transpoz işlemleri toplama üzerine dağılır:
     $$(\overline{C_1})^T = (\overline{A + B})^T = (\overline{A} + \overline{B})^T = (\overline{A})^T + (\overline{B})^T$$
     $A$ ve $B$ Hermityen olduğundan $(\overline{A})^T = A$ ve $(\overline{B})^T = B$ yerine yazılırsa:
     $$(\overline{C_1})^T = A + B = C_1$$
     bulunur. Yani **$C_1$ matrisi Hermityendir**.

  2. **$C_3 = AB$ Matrisinin Kontrolü:**
     Şıklarda "Hepsi" seçeneği de bulunduğu için $C_3 = AB$ matrisini kontrol edelim. Çarpımın eşleniği, eşleniklerin çarpımına eşittir ($\overline{AB} = \overline{A}\cdot\overline{B}$); ancak **çarpımın transpozu alındığında çarpılan matrislerin sırası yer değiştirir** ($(XY)^T = Y^T X^T$):
     $$(\overline{C_3})^T = (\overline{AB})^T = (\overline{A}\cdot\overline{B})^T = (\overline{B})^T (\overline{A})^T$$
     $A$ ve $B$ Hermityen olduğundan $(\overline{B})^T = B$ ve $(\overline{A})^T = A$ yazılırsa:
     $$(\overline{C_3})^T = BA$$
     bulunur. Matris çarpımında genel olarak değişme özelliği olmadığından ($AB \neq BA$), $BA \neq C_3$ olur ve **$C_3$ genel olarak Hermityen değildir**. (Benzer şekilde $C_2$'de kompleks katsayıların eşleniği alındığında $3+2i \to 3-2i$ ve $i \to -i$ olacağından $C_2$ de Hermityen değildir.) Dolayısıyla yalnız **$C_1$** Hermityendir (Cevap: a).

## 3. Determinant Özellikleri ve Çarpanlara Ayırma Soruları (Soru 7A, Soru 16 ve Soru 20A)

### 3.1 Vandermonde Tipi Determinantın Çarpanlarına Ayrılması (Soru 7A)

- **Soru (ekrandan, 00:19:15 ve 00:27:10):**
  $$\begin{vmatrix} 1 & 1 & 1 \\ a & b & c \\ a^2 & b^2 & c^2 \end{vmatrix}$$
  determinantının değeri aşağıdakilerden hangisidir?
  a) $(b+a)(c+a)(c+b)$
  b) $(a-b)(c-a)(c-b)$
  c) $(b-a)(a-c)(c-b)$
  d) $(b-a)(c-a)(c-b)$
  e) $(b-a)(c-a)(b-c)$

- **Çözüm (ekrandan, 00:27:10):**
  Bu determinantı Sarrus kuralıyla açarsak çarpanlarına ayrılması zor, karmaşık bir polinom elde ederiz. Oysa şıklar çarpanlarına ayrılmış (factorized) biçimde verildiğinden determinant özelliklerini kullanmak en doğru yoldur:
  1. **1. Satırda Sıfırlar Oluşturma:**
     1. satır $(1\ \ 1\ \ 1)$ elemanlarından oluşmaktadır. 1. sütunu $-1$ ile çarpıp 2. sütuna eklersek ($-c_1 + c_2 \to c_2$) ve yine 1. sütunu $-1$ ile çarpıp 3. sütuna eklersek ($-c_1 + c_3 \to c_3$) determinantın değeri değişmez:
     $$\begin{vmatrix} 1 & 1 & 1 \\ a & b & c \\ a^2 & b^2 & c^2 \end{vmatrix} \xrightarrow[\ -c_1 + c_3 \to c_3\ ]{-c_1 + c_2 \to c_2} \begin{vmatrix} 1 & 0 & 0 \\ a & b-a & c-a \\ a^2 & b^2-a^2 & c^2-a^2 \end{vmatrix}$$
  2. **Sütunları Ortak Çarpan Parantezine Alma:**
     İki kare farkı özdeşliğinden:
     $$b^2 - a^2 = (b-a)(b+a) \quad \text{ve} \quad c^2 - a^2 = (c-a)(c+a)$$
     olduğunu biliyoruz. Dolayısıyla 2. sütunun elemanları $0 = (b-a)\cdot 0$, $(b-a)\cdot 1$ ve $(b-a)(b+a)$ olup tamamı $(b-a)$'nın katıdır. Aynı şekilde 3. sütunun tüm elemanları $(c-a)$'nın katıdır. 2. sütundan $(b-a)$'yı, 3. sütundan $(c-a)$'yı determinantın dışına çarpan olarak çıkarırsak:
     $$= (b-a)(c-a) \begin{vmatrix} 1 & 0 & 0 \\ a & 1 & 1 \\ a^2 & b+a & c+a \end{vmatrix}$$
  3. **1. Satıra Göre Laplace Açılımı:**
     1. satırda iki adet sıfır bulunduğundan 1. satır boyunca Laplace (kofaktör) açılımı uygularız:
     $$= (b-a)(c-a) \cdot 1 \cdot (-1)^{1+1} \begin{vmatrix} 1 & 1 \\ b+a & c+a \end{vmatrix}$$
     Burada $(-1)^2 = +1$ ve $2 \times 2$ determinantın değeri $1\cdot(c+a) - 1\cdot(b+a) = c + a - b - a = c - b$ olduğundan:
     $$= (b-a)(c-a)(c-b)$$
     bulunur (Cevap: d).

**Soru:** Bir sütunda $0$, $b-a$ ve $b^2-a^2$ varken $(b-a)$ üç elemanın da ortak çarpanı olmadığı halde nasıl dışarıya paranteze alabildik?
**Cevap:** $(b-a)$ aslında o sütundaki **üç elemanın da** ortak çarpanıdır; çünkü $0$ sayısı her sayının çarpanıdır ($0 = (b-a)\cdot 0$). İkinci eleman $(b-a)\cdot 1$, üçüncü eleman ise $(b-a)(b+a)$'dır. Dolayısıyla sütunun tamamında $(b-a)$ ortak çarpandır ve dışarı alındığında sütunda sırasıyla $0$, $1$ ve $b+a$ kalır. Eğer sütundaki elemanların tamamında ortak olmasaydı (örneğin sıfır yerine başka bir $d$ terimi olsaydı) dışarıya çarpan olarak alamazdık.

### 3.2 Satır/Sütun İşlemleri ve Transpoz ile Determinant Hesabı (Soru 16)

- **Soru (ekrandan, 00:54:00 ve 01:04:35):**
  $$A = \begin{bmatrix} 3c_1 & -3c_2 & 3c_3 \\ a_1 + 9c_1 & -a_2 - 9c_2 & a_3 + 9c_3 \\ -b_1 & b_2 & -b_3 \end{bmatrix}$$
  matrisinin determinantı $12$ ise,
  $$B = \begin{bmatrix} a_1 & b_1 & c_1 \\ a_2 & b_2 & c_2 \\ a_3 & b_3 & c_3 \end{bmatrix}$$
  matrisinin determinantı kaçtır?
  a) $4$ $\quad$ b) $-4$ $\quad$ c) $36$ $\quad$ d) $-36$ $\quad$ e) $27$

- **Çözüm (ekrandan, 01:00:00 ve 01:04:35):**
  Amacımız $\det(A) = 12$ eşitliğinden başlayıp determinant özelliklerini kullanarak $A$ matrisinin determinantını $B$ matrisinin determinantı cinsinden yazmaktır:
  1. **2. Satırdaki $9c_i$ Terimlerini Yok Etme:**
     $A$ matrisinin 1. satırını $-3$ ile çarpıp 2. satıra eklersek ($-3r_1 + r_2 \to r_2$), bir satırın katını başka bir satıra eklemek determinantı değiştirmeyeceğinden determinant yine $12$'ye eşittir ve 2. satırdaki $9c_1, -9c_2, 9c_3$ terimleri birbirini götürür:
     $$\det(A) = \begin{vmatrix} 3c_1 & -3c_2 & 3c_3 \\ a_1 & -a_2 & a_3 \\ -b_1 & b_2 & -b_3 \end{vmatrix} = 12$$
  2. **Satırların Sırasını Düzenleme ($a$'lar 1. satıra, $b$'ler 2. satıra, $c$'ler 3. satıra):**
     Hedefimizdeki $B$ matrisinin transpozunda 1. satırda $a$'lar, 2. satırda $b$'ler, 3. satırda $c$'ler yer almaktadır.
     - Önce 1. satır ile 2. satırın yerini değiştirelim ($r_1 \leftrightarrow r_2$). İki satır yer değiştirdiğinde determinant işaret değiştirir (önüne $-$ gelir):
       $$= -\begin{vmatrix} a_1 & -a_2 & a_3 \\ 3c_1 & -3c_2 & 3c_3 \\ -b_1 & b_2 & -b_3 \end{vmatrix}$$
     - Şimdi de 2. satır ile 3. satırın yerini değiştirelim ($r_2 \leftrightarrow r_3$). Bir kez daha işaret değişeceğinden ($- \cdot - = +$) determinantın önündeki işaret tekrar pozitif olur:
       $$= +\begin{vmatrix} a_1 & -a_2 & a_3 \\ -b_1 & b_2 & -b_3 \\ 3c_1 & -3c_2 & 3c_3 \end{vmatrix}$$
  3. **3. Satırdan $3$ Çarpanını Dışarı Alma:**
     3. satırdaki tüm elemanlar $3$'ün katı olduğundan $3$'ü determinantın dışına çıkarırız:
     $$= 3 \begin{vmatrix} a_1 & -a_2 & a_3 \\ -b_1 & b_2 & -b_3 \\ c_1 & -c_2 & c_3 \end{vmatrix}$$
  4. **Eksi İşaretlerini Yok Etme:**
     Hedef matriste hiç negatif işaret yoktur.
     - Önce 2. sütunu $-1$ ile çarpalım (veya 2. sütundan $-1$ parantezine alalım); bu işlem determinantı $-1$ ile çarpar ve dışarıdaki katsayı $-3$ olur:
       $$= -3 \begin{vmatrix} a_1 & a_2 & a_3 \\ -b_1 & -b_2 & -b_3 \\ c_1 & c_2 & c_3 \end{vmatrix}$$
     - Şimdi 2. satırın tamamı negatif olduğu için 2. satırı da $-1$ ile çarpalım; dışarıdaki $-3$ katsayısı tekrar $(-3)(-1) = +3$ olur:
       $$= 3 \begin{vmatrix} a_1 & a_2 & a_3 \\ b_1 & b_2 & b_3 \\ c_1 & c_2 & c_3 \end{vmatrix}$$
  5. **Transpoz Özelliğini Kullanma:**
     Elde ettiğimiz matris, soruda determinantı istenen $B$ matrisinin transpozudur ($B^T$). $\det(B^T) = \det(B)$ olduğundan:
     $$3 \begin{vmatrix} a_1 & b_1 & c_1 \\ a_2 & b_2 & c_2 \\ a_3 & b_3 & c_3 \end{vmatrix} = 12 \implies 3 \det(B) = 12 \implies \det(B) = 4$$
     bulunur (Cevap: a).

### 3.3 Skaler Çarpım, Transpoz ve Ters Matrisin Determinantı (Soru 20A)

- **Soru (ekrandan, 01:00:00 ve 01:37:55):**
  $A, B \in M_3(\mathbb{R})$ ($3 \times 3$ boyutlu reel matrisler) için $\det(A) = 2$ ve $\det(B) = -1$ olsun. Buna göre:
  $$\det\left[-A^T(2B)^{-1}\right]$$
  ifadesinin değeri aşağıdakilerden hangisidir?
  a) $1/4$ $\quad$ b) $1/2$ $\quad$ c) $2$ $\quad$ d) $4$ $\quad$ e) $-1/4$

- **Çözüm (ekrandan, 01:37:55):**
  1. **Çarpımın Determinantı:**
     $\det(XY) = \det(X)\det(Y)$ özelliğinden:
     $$\det\left[-A^T(2B)^{-1}\right] = \det(-A^T) \cdot \det\left((2B)^{-1}\right)$$
  2. **$\det(-A^T)$ İfadesinin Hesaplanması:**
     $n \times n$ boyutlu bir $M$ matrisi ve $k$ skaleri için $\det(kM) = k^n \det(M)$ kuralı geçerlidir. Burada $A \in M_3(\mathbb{R})$ olduğundan matrisin boyutu $n = 3$ ve skaler $k = -1$'dir. Ayrıca $\det(A^T) = \det(A)$ olduğundan:
     $$\det(-A^T) = (-1)^3 \det(A^T) = (-1) \cdot \det(A) = -1 \cdot 2 = -2$$
  3. **$\det\left((2B)^{-1}\right)$ İfadesinin Hesaplanması:**
     Ters matrisin determinantı kuralından ($\det(M^{-1}) = \frac{1}{\det(M)}$):
     $$\det\left((2B)^{-1}\right) = \frac{1}{\det(2B)}$$
     Paydadaki $\det(2B)$ ifadesinde $B$ matrisi de $3 \times 3$ boyutlu ($n = 3$) olduğundan $k = 2$ çarpanı $2^3 = 8$ olarak dışarı çıkar:
     $$\det(2B) = 2^3 \det(B) = 8 \cdot (-1) = -8 \implies \det\left((2B)^{-1}\right) = -\frac{1}{8}$$
  4. **Sonuç:**
     $$\det\left[-A^T(2B)^{-1}\right] = (-2) \cdot \left(-\frac{1}{8}\right) = \frac{2}{8} = \frac{1}{4}$$
     bulunur (Cevap: a).

## 4. Ters Matris ve İç Çarpım ile Matris Çarpımının Belirli Bir Elemanını Bulma (Soru 15 ve Soru 1)

### 4.1 $A$ ve $AB$ Verildiğinde $B$ Matrisinin $(2, 4)$ Elemanını Bulma (Soru 15)

- **Soru (ekrandan, 00:48:50):**
  Eğer
  $$A = \begin{bmatrix} 3 & 4 \\ 1 & 1 \end{bmatrix} \quad \text{ve} \quad AB = \begin{bmatrix} 1 & 0 & -2 & 5 \\ 4 & -1 & 0 & 3 \end{bmatrix}$$
  ise $B$ matrisinin $(2, 4)$ elemanı ($b_{24}$) aşağıdakilerden hangisidir?
  a) $-2$ $\quad$ b) $-4$ $\quad$ c) $3$ $\quad$ d) $8$ $\quad$ e) $11$

- **Çözüm (ekrandan, 00:48:50):**
  1. **$B$ Matrisini Yalnız Bırakma:**
     Elave edilen eşitlik $AB = C$ biçimindedir. $B$ matrisini bulmak için eşitliğin her iki tarafını **soldan** $A^{-1}$ ile çarparız (matris çarpımında değişme özelliği olmadığı için çarpma yönü çok önemlidir):
     $$A^{-1}(AB) = (A^{-1}A)B = I_2 B = B$$
  2. **$A^{-1}$ Matrisinin Bulunması:**
     $A = \begin{bmatrix} 3 & 4 \\ 1 & 1 \end{bmatrix}$ matrisinin determinantı:
     $$\det(A) = 3 \cdot 1 - 4 \cdot 1 = 3 - 4 = -1$$
     Kofaktörlerinden ek matrisi ($\text{adj}(A)$) yazarsak: $A_{11} = 1$, $A_{12} = -1$, $A_{21} = -4$, $A_{22} = 3$ olup transpozu:
     $$\text{adj}(A) = \begin{bmatrix} A_{11} & A_{21} \\ A_{12} & A_{22} \end{bmatrix} = \begin{bmatrix} 1 & -4 \\ -1 & 3 \end{bmatrix}$$
     (veya $2 \times 2$ matrisler için pratik kuralla: esas köşegendeki $3$ ile $1$'in yeri değiştirilir, yedek köşegendeki $4$ ile $1$'in işareti değiştirilir). Buradan:
     $$A^{-1} = \frac{1}{\det(A)}\text{adj}(A) = \frac{1}{-1} \begin{bmatrix} 1 & -4 \\ -1 & 3 \end{bmatrix} = \begin{bmatrix} -1 & 4 \\ 1 & -3 \end{bmatrix}$$
  3. **Yalnızca $b_{24}$ Elemanının İç Çarpımla Hesaplanması:**
     $$B = A^{-1}(AB) = \begin{bmatrix} -1 & 4 \\ 1 & -3 \end{bmatrix} \begin{bmatrix} 1 & 0 & -2 & 5 \\ 4 & -1 & 0 & 3 \end{bmatrix}$$
     > **Hocanın vurgusu:** Sınavda $B$ matrisinin tüm elemanlarını tek tek çarpıp bulmanıza gerek yoktur! Matris çarpımının tanımından bildiğimiz üzere, çarpım matrisinin $(i, j)$ konumundaki elemanı, birinci matrisin $i$. satırı ile ikinci matrisin $j$. sütununun iç çarpımına (dot product) eşittir.
     Bizden yalnızca 2. satır ve 4. sütundaki $b_{24}$ elemanı istendiğine göre, ilk matris olan $A^{-1}$'in **2. satırı** ile ikinci matris olan $AB$'nin **4. sütununu** çarpmamız yeterlidir:
     $$b_{24} = \text{row}_2(A^{-1})^T \cdot \text{col}_4(AB) = \begin{bmatrix} 1 & -3 \end{bmatrix} \begin{bmatrix} 5 \\ 3 \end{bmatrix} = (1)(5) + (-3)(3) = 5 - 9 = -4$$
     bulunur (Cevap: b).

### 4.2 Kuralı Verilen Matrislerin Çarpımında $c_{44}$ Elemanını Bulma (Soru 1)

- **Soru (ekrandan, 01:09:45 ve 01:21:50):**
  $$A = [a_{ij}]_{n \times m}, \quad a_{ij} = \begin{cases} i + j, & i \le j \\ i - j, & i > j \end{cases} \quad \text{ve} \quad B = [b_{ij}]_{m \times r}, \quad b_{ij} = \begin{cases} 2i - j, & i < j \\ j + 1, & i \ge j \end{cases}$$
  matrisleri verilsin. $n = 15, m = 7$ ve $r = 6$ için $AB = C = [c_{ij}]$ olmak üzere $i = 4$ ve $j = 4$ için $C$ matrisinin $c_{44}$ elemanını bulunuz.

- **Çözüm Yöntemi (ekrandan, 01:21:50):**
  1. **Boyut Analizi ve İç Çarpım Formülü:**
     $A$ matrisi $15 \times 7$, $B$ matrisi $7 \times 6$ boyutludur; çarpımları olan $C = AB$ matrisi ise $15 \times 6$ boyutludur. $C$ matrisinin 4. satır ve 4. sütunundaki $c_{44}$ elemanı, $A$ matrisinin 4. satırı ile $B$ matrisinin 4. sütununun iç çarpımına eşittir:
     $$c_{44} = \text{row}_4(A)^T \cdot \text{col}_4(B) = \sum_{k=1}^{7} a_{4k} b_{k4}$$
  2. **$A$ Matrisinin 4. Satırının ($\text{row}_4(A)$) Bulunması:**
     $A$ matrisinin $7$ sütunu olduğundan 4. satırı $[a_{41}, a_{42}, a_{43}, a_{44}, a_{45}, a_{46}, a_{47}]$ elemanlarından oluşur:
     - $j = 1, 2, 3$ için $i = 4 > j$ olduğundan $a_{4j} = i - j$ kuralı uygulanır:
       - $a_{41} = 4 - 1 = 3$
       - $a_{42} = 4 - 2 = 2$
       - $a_{43} = 4 - 3 = 1$
     - $j = 4, 5, 6, 7$ için $i = 4 \le j$ olduğundan $a_{4j} = i + j$ kuralı uygulanır:
       - $a_{44} = 4 + 4 = 8$ (Not: Hoca sözlü anlatırken önce $7$ demiş, tahtaya ise doğru olarak $8$ yazmıştır.)
       - $a_{45} = 4 + 5 = 9$
       - $a_{46} = 4 + 6 = 10$
       - $a_{47} = 4 + 7 = 11$
     $$\text{row}_4(A) = \begin{bmatrix} 3 & 2 & 1 & 8 & 9 & 10 & 11 \end{bmatrix}$$
  3. **$B$ Matrisinin 4. Sütununun ($\text{col}_4(B)$) Bulunması:**
     $B$ matrisinin $7$ satırı olduğundan 4. sütunu $[b_{14}, b_{24}, b_{34}, b_{44}, b_{54}, b_{64}, b_{74}]^T$ elemanlarından oluşur (Not: Hoca tahtada önce sehven $b_{41}, \dots, b_{47}$ yazmış, bir öğrencinin uyarısıyla 4. sütun indislerinin $b_{14}, b_{24}, \dots, b_{74}$ olması gerektiğini belirterek düzeltmiştir):
     - $i = 1, 2, 3$ için $i < j = 4$ olduğundan $b_{i4} = 2i - j = 2i - 4$ kuralı uygulanır:
       - $b_{14} = 2(1) - 4 = -2$
       - $b_{24} = 2(2) - 4 = 0$
       - $b_{34} = 2(3) - 4 = 2$
     - $i = 4, 5, 6, 7$ için $i \ge j = 4$ olduğundan $b_{i4} = j + 1 = 4 + 1 = 5$ kuralı uygulanır:
       - $b_{44} = b_{54} = b_{64} = b_{74} = 5$
     $$\text{col}_4(B) = \begin{bmatrix} -2 & 0 & 2 & 5 & 5 & 5 & 5 \end{bmatrix}^T$$
  4. **İç Çarpımın Hesaplanması:**
     $$c_{44} = 3(-2) + 2(0) + 1(2) + 8(5) + 9(5) + 10(5) + 11(5) = -6 + 0 + 2 + 40 + 45 + 50 + 55 = 186$$
     (Hoca soru kağıdındaki şıklarda $(-27, 27, 31, 33, -33)$ basım hatası olduğunu belirterek yöntemin bu şekilde uygulandığını vurgulamıştır.)

## Örnek Sorular

### Soru 1: Ortogonal Matrisler ve Determinant (ekrandan, 00:12:40)

**Soru:** $A$ ve $B$ sıfırdan farklı reel ortogonal matrisler olmak üzere:
- I. $\det(A^T(A + B)B^T) = \det(A + B)$
- II. $\det(A^T + B) = \det(A + B^T)$
- III. $\det(A^T + B^T) = \det((A + B)^T)$

ifadelerinden hangileri her zaman doğrudur?

**Çözüm:**
$A^T A = I_n$ ve $B B^T = I_n$ olduğundan $A^T(A + B)B^T = (I_n + A^T B)B^T = B^T + A^T = (A + B)^T$ olur ve $\det((A + B)^T) = \det(A + B)$ olduğundan I doğrudur. $\det(M) = \det(M^T)$ özelliğinden $\det(A^T + B) = \det((A^T + B)^T) = \det(A + B^T)$ olup II doğrudur. $A^T + B^T = (A + B)^T$ olduğundan III de doğrudur. Üç ifade de her zaman doğrudur.

### Soru 2: Simetrik ve Ters Simetrik Matrisler (ekrandan, 00:19:15)

**Soru:** $A$ sıfırdan farklı $n \times n$ boyutlu bir matris, $B = A + A^T$ ve $C = A - A^T$ olsun. $B$ ve $C$ matrislerinin simetri özelliklerini belirleyiniz.

**Çözüm:**
- $B^T = (A + A^T)^T = A^T + A = B$ olduğundan $B$ **simetrik** bir matristir.
- $C^T = (A - A^T)^T = A^T - A = -(A - A^T) = -C$ olduğundan $C$ **ters simetrik** (skew-symmetric) bir matristir.

### Soru 3: Vandermonde Determinantı (ekrandan, 00:27:10)

**Soru:**
$$\begin{vmatrix} 1 & 1 & 1 \\ a & b & c \\ a^2 & b^2 & c^2 \end{vmatrix}$$
determinantını çarpanlarına ayırarak hesaplayınız.

**Çözüm:**
$-c_1 + c_2 \to c_2$ ve $-c_1 + c_3 \to c_3$ sütun işlemleri uygulanıp 2. sütundan $(b-a)$, 3. sütundan $(c-a)$ çarpanları dışarı alınır:
$$\begin{vmatrix} 1 & 0 & 0 \\ a & b-a & c-a \\ a^2 & b^2-a^2 & c^2-a^2 \end{vmatrix} = (b-a)(c-a) \begin{vmatrix} 1 & 0 & 0 \\ a & 1 & 1 \\ a^2 & b+a & c+a \end{vmatrix} = (b-a)(c-a)(c+a - (b+a)) = (b-a)(c-a)(c-b)$$

### Soru 4: Kompleks Hermityen Matrisler (ekrandan, 00:37:50)

**Soru:** $A$ ve $B$, $n \times n$ boyutlu kompleks Hermityen matrisler olmak üzere $C_1 = A + B$ ve $C_3 = AB$ matrislerinin Hermityen olup olmadığını inceleyiniz.

**Çözüm:**
$(\overline{A})^T = A$ ve $(\overline{B})^T = B$'dir.
- $(\overline{C_1})^T = (\overline{A + B})^T = (\overline{A})^T + (\overline{B})^T = A + B = C_1 \implies C_1$ Hermityendir.
- $(\overline{C_3})^T = (\overline{AB})^T = (\overline{B})^T (\overline{A})^T = BA \neq AB \implies C_3$ genel olarak Hermityen değildir.

### Soru 5: Ters Matris ve İç Çarpım ile Matris Elemanı Bulma (ekrandan, 00:48:50)

**Soru:**
$$A = \begin{bmatrix} 3 & 4 \\ 1 & 1 \end{bmatrix} \quad \text{ve} \quad AB = \begin{bmatrix} 1 & 0 & -2 & 5 \\ 4 & -1 & 0 & 3 \end{bmatrix}$$
ise $B$ matrisinin $(2, 4)$ elemanı ($b_{24}$) kaçtır?

**Çözüm:**
$\det(A) = 3 - 4 = -1$ olup $A^{-1} = \begin{bmatrix} -1 & 4 \\ 1 & -3 \end{bmatrix}$ bulunur. $B = A^{-1}(AB)$ olduğundan:
$$b_{24} = \text{row}_2(A^{-1})^T \cdot \text{col}_4(AB) = \begin{bmatrix} 1 & -3 \end{bmatrix} \begin{bmatrix} 5 \\ 3 \end{bmatrix} = 5 - 9 = -4$$

### Soru 6: Satır/Sütun İşlemleriyle Determinant Hesabı (ekrandan, 00:54:00 ve 01:04:35)

**Soru:**
$$\begin{vmatrix} 3c_1 & -3c_2 & 3c_3 \\ a_1 + 9c_1 & -a_2 - 9c_2 & a_3 + 9c_3 \\ -b_1 & b_2 & -b_3 \end{vmatrix} = 12 \quad \text{ise} \quad \begin{vmatrix} a_1 & b_1 & c_1 \\ a_2 & b_2 & c_2 \\ a_3 & b_3 & c_3 \end{vmatrix}$$
determinantı kaçtır?

**Çözüm:**
$-3r_1 + r_2 \to r_2$ işlemi, iki kez satır yer değiştirme ($r_1 \leftrightarrow r_2$ ve $r_2 \leftrightarrow r_3$), 3. satırdan $3$ çarpanını çıkarma, 2. sütun ve 2. satırı $-1$ ile çarpma ve transpoz alma işlemleri sonucunda:
$$3 \begin{vmatrix} a_1 & b_1 & c_1 \\ a_2 & b_2 & c_2 \\ a_3 & b_3 & c_3 \end{vmatrix} = 12 \implies \begin{vmatrix} a_1 & b_1 & c_1 \\ a_2 & b_2 & c_2 \\ a_3 & b_3 & c_3 \end{vmatrix} = 4$$

### Soru 7: Determinant Özellikleri (ekrandan, 01:37:55)

**Soru:** $A, B \in M_3(\mathbb{R})$ matrisleri için $\det(A) = 2$ ve $\det(B) = -1$ olduğuna göre $\det\left[-A^T(2B)^{-1}\right]$ değeri kaçtır?

**Çözüm:**
$$\det\left[-A^T(2B)^{-1}\right] = \det(-A^T)\cdot\det\left((2B)^{-1}\right) = (-1)^3\det(A) \cdot \frac{1}{2^3\det(B)} = (-2)\cdot\left(-\frac{1}{8}\right) = \frac{1}{4}$$

## Dersin Toparlaması

Bu derste ilk beş haftada işlenen matris cebiri ve determinant konularını pekiştirmek amacıyla yedi kapsamlı örnek sınav sorusu çözüldü. Sorular üzerinden ortogonal matrislerde $A^T = A^{-1}$ ve $A^T A = I_n$ özdeşliğinin kullanımı, her kare matris için $A + A^T$'nin simetrik ve $A - A^T$'nin ters simetrik olduğu, kompleks Hermityen matrislerde $(\overline{A})^T = A$ tanımı ile çarpımın eşlenik transpozunda sıranın tersine döndüğü ($(\overline{AB})^T = (\overline{B})^T(\overline{A})^T$), sütun ve satır işlemleriyle Vandermonde tipi determinantların çarpanlarına ayrılması, $AB = C$ tipindeki matris denklemlerinde soldan $A^{-1}$ ile çarpma ve yalnızca istenen $b_{ij}$ elemanını tek bir satır-sütun iç çarpımıyla bulma tekniği ile $\det(kA) = k^n\det(A)$, $\det(A^T) = \det(A)$ ve $\det(A^{-1}) = 1/\det(A)$ kurallarının birlikte uygulanışı ayrıntılı biçimde gösterildi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
