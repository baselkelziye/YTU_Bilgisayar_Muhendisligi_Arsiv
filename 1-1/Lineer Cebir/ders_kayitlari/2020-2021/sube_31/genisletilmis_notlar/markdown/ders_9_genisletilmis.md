# Ders 9 Genişletilmiş Notu: Cramer Kuralı, Ters Matris Yöntemiyle Lineer Sistem Çözümü ve Vize Sınavı Sorularının Çözümü

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Cramer Kuralı ile Doğrusal Denklem Sistemlerinin Çözümü (Cramer's Rule)
  - 1.1 Cramer Kuralının Uygulanabilme Koşulları ve Verimlilik Sınırı
  - 1.2 Cramer Kuralı Teoremi ve Formülü
  - 1.3 Cramer Kuralı ile $3 \times 3$ Lineer Sistem Çözümü Örneği
- 2. Tersinir (Nonsingular) Matrisler İçin Beş Denk İfade Özeti
- 3. Ters Matris Yöntemiyle Doğrusal Denklem Sistemi Çözümü (Inverse Matrix Method)
  - 3.1 $X = A^{-1}b$ Formülünün Çıkarılışı
  - 3.2 Ters Matris Yöntemiyle $3 \times 3$ Lineer Sistem Çözümü Örneği
- 4. $4 \times 4$ Vandermonde Tipi Determinant ve Cramer Kuralı Uygulaması
- 5. Vize Sınavı Sorularının Ayrıntılı Çözümleri
  - 5.1 Vize Sorusu 1: Kare Olmayan Matris Çarpım Denklemi ($XA = Y$)
  - 5.2 Vize Sorusu 2: Matris Polinom Denkleminden Ters Matris Bulma
  - 5.3 Vize Sorusu 3: Determinant Çarpanlı $3 \times 3$ Matrisin Rankı
  - 5.4 Vize Sorusu 4: Eşit Elemanlı Matriste Laplace Açılımı
  - 5.5 Vize Sorusu 5: Değişmeli Hermityen ve Ters Hermityen Matrisler
  - 5.6 Vize Sorusu 6: Determinant ve Ek Matris Önermeleri
- Örnek Sorular
- Dersin Toparlaması

## 1. Cramer Kuralı ile Doğrusal Denklem Sistemlerinin Çözümü (Cramer's Rule)

Hoca bir önceki derste doğrusal denklem sistemlerini çözmek için Gauss-Jordan eliminasyon yöntemini öğrendiğimizi hatırlatarak, bu derste doğrusal denklem sistemlerini çözmek için iki yeni yöntem daha işleyeceğimizi belirtti: **Cramer kuralı** (Cramer's rule) ve **ters matris yöntemi** (inverse matrix method).

### 1.1 Cramer Kuralının Uygulanabilme Koşulları ve Verimlilik Sınırı

Cramer kuralına geçmeden önce bu kuralın hangi sistemlere uygulanabileceğini belirten iki kritik not vurgulanmıştır:

1. **Uygulanabilme Koşulu:** Cramer kuralı **yalnızca** bilinmeyen sayısı ile denklem sayısı birbirine eşit olan ($n$ bilinmeyenli ve $n$ denklemli, yani katsayılar matrisi $A$ bir $n \times n$ kare matris olan) ve katsayılar matrisi $A$ **tekil olmayan** (nonsingular / invertible, yani $\det(A) \neq 0$) doğrusal denklem sistemlerine uygulanabilir.
2. **Verimlilik Sınırı ($n \ge 4$ Durumu):** Eğer bilinmeyen ve denklem sayısı $n \ge 4$ ise (veya $n > 4$ ise) Cramer kuralı **verimsiz** (inefficient) hale gelir; çünkü $4 \times 4$ ve daha büyük boyutlu çok sayıda determinant hesaplamak oldukça zordur. Bu nedenle $n \ge 4$ olan sistemlerde Cramer kuralı yerine Gauss eliminasyonu veya Gauss-Jordan indirgeme yöntemi kullanılmalıdır. $n < 4$ ($2 \times 2$ veya $3 \times 3$) boyutlu sistemlerde ise Cramer kuralı rahatlıkla kullanılabilir.

### 1.2 Cramer Kuralı Teoremi ve Formülü

$n$ bilinmeyenli ($x_1, x_2, \dots, x_n$) ve $n$ denklemli bir doğrusal denklem sistemi matris formunda:
$$AX = b$$
olarak yazılsın (ekrandan, 00:13:00). Burada $A = [a_{ij}]_{n \times n}$ katsayılar matrisi, $X = [x_1, x_2, \dots, x_n]^T$ bilinmeyenler vektörü ve $b = [b_1, b_2, \dots, b_n]^T$ sabitler vektörüdür.

- **Teorem (Cramer Kuralı):** $AX = b$ doğrusal denklem sisteminin **tek bir çözüme** (unique solution) sahip olması için gerek ve yeter şart $\det(A) \neq 0$ olmasıdır. Bu durumda sistemin tek çözümü olan $x_1, x_2, \dots, x_n$ bilinmeyenleri şu formüllerle bulunur:
  $$x_1 = \frac{\det(A_1)}{\det(A)}, \quad x_2 = \frac{\det(A_2)}{\det(A)}, \quad \dots, \quad x_n = \frac{\det(A_n)}{\det(A)}$$
  Burada **$A_i$ matrisi** ($i = 1, 2, \dots, n$), $A$ katsayılar matrisinin **$i$. sütununun silinip yerine sağ taraftaki $b$ sabitler sütun matrisinin yazılmasıyla** elde edilen $n \times n$ boyutlu matristir. Örneğin $A_1$ matrisi, $A$'nın 1. sütununa $b$ sütununun yazılmasıyla; $A_2$ matrisi ise $A$'nın 2. sütununa $b$ sütununun yazılmasıyla elde edilir.

### 1.3 Cramer Kuralı ile $3 \times 3$ Lineer Sistem Çözümü Örneği

- **Verilen (ekrandan, 00:22:00 ve 00:42:30):**
  $$\begin{cases} 2x_1 + 3x_2 + x_3 = 1 \\ x_1 - x_2 + 2x_3 = -3 \\ -3x_1 + 4x_2 - x_3 = 4 \end{cases}$$
  doğrusal denklem sistemini Cramer kuralını kullanarak çözünüz.

- **1. Adım (Katsayılar Matrisi $A$ ve $\det(A)$'nın Hesaplanması):**
  Sistemin katsayılar matrisi $A$ ve sağ taraf sabitler matrisi $b$ şöyledir:
  $$A = \begin{bmatrix} 2 & 3 & 1 \\ 1 & -1 & 2 \\ -3 & 4 & -1 \end{bmatrix}, \quad b = \begin{bmatrix} 1 \\ -3 \\ 4 \end{bmatrix}$$
  $A$ matrisi $3 \times 3$ boyutlu olduğundan determinantını Sarrus kuralıyla hesaplayalım:
  - Soldan sağa köşegen çarpımları: $(2)(-1)(-1) + (1)(4)(1) + (-3)(3)(2) = 2 + 4 - 18 = -12$
  - Sağdan sola köşegen çarpımları: $(1)(-1)(-3) + (2)(4)(2) + (-1)(3)(1) = 3 + 16 - 3 = 16$
  $$\det(A) = -12 - 16 = -28 \neq 0$$
  $\det(A) = -28 \neq 0$ olduğundan bu lineer sistemin **tek bir çözümü** (unique solution) vardır ve Cramer kuralı uygulanabilir.

- **2. Adım ($A_1, A_2, A_3$ Matrislerinin Determinantlarının Bulunması):**
  - **$A_1$ matrisi** ($A$'nın 1. sütunu yerine $b = [1, -3, 4]^T$ yazılır):
    $$\det(A_1) = \begin{vmatrix} 1 & 3 & 1 \\ -3 & -1 & 2 \\ 4 & 4 & -1 \end{vmatrix}$$
    Sarrus kuralıyla:
    - Soldan sağa: $(1)(-1)(-1) + (-3)(4)(1) + (4)(3)(2) = 1 - 12 + 24 = 13$
    - Sağdan sola: $(1)(-1)(4) + (2)(4)(1) + (-1)(3)(-3) = -4 + 8 + 9 = 13$
    $$\det(A_1) = 13 - 13 = 0$$
  - **$A_2$ matrisi** ($A$'nın 2. sütunu yerine $b = [1, -3, 4]^T$ yazılır):
    $$\det(A_2) = \begin{vmatrix} 2 & 1 & 1 \\ 1 & -3 & 2 \\ -3 & 4 & -1 \end{vmatrix} = (6 + 4 - 6) - (9 + 16 - 1) = 4 - 24 = -20$$
  - **$A_3$ matrisi** ($A$'nın 3. sütunu yerine $b = [1, -3, 4]^T$ yazılır):
    $$\det(A_3) = \begin{vmatrix} 2 & 3 & 1 \\ 1 & -1 & -3 \\ -3 & 4 & 4 \end{vmatrix} = (-8 + 4 + 27) - (3 - 24 + 12) = 23 - (-9) = 32$$

- **3. Adım ($x_1, x_2, x_3$ Bilinmeyenlerinin Hesaplanması — ekrandan, 00:22:00):**
  $$\begin{aligned}
  x_1 &= \frac{\det(A_1)}{\det(A)} = \frac{0}{-28} = 0 \\
  x_2 &= \frac{\det(A_2)}{\det(A)} = \frac{-20}{-28} = \frac{5}{7} \\
  x_3 &= \frac{\det(A_3)}{\det(A)} = \frac{32}{-28} = -\frac{8}{7}
  \end{aligned}$$

## 2. Tersinir (Nonsingular) Matrisler İçin Beş Denk İfade Özeti

Hoca özellikle çoktan seçmeli sınav sorularını çözerken büyük kolaylık sağlayan aşağıdaki denklik teoremini özet olarak yazdırdı (ekrandan, 00:27:30):

> **Hocanın vurgusu (Özet — Denk İfadeler):** Bir $n \times n$ boyutlu $A$ kare matrisi için aşağıdaki beş ifade birbirine **denktir** (are equivalent); yani bir tanesi doğruysa diğer dördü de otomatik olarak doğrudur:
> 1. $A$ **tekil olmayan** (nonsingular / tersinir / invertible) bir matristir.
> 2. $AX = 0$ homojen doğrusal denklem sisteminin **yalnızca aşikar (trivial / sıfır: $x_1 = 0 = \dots = x_n$) çözümü** vardır.
> 3. $A$ matrisi $I_n$ birim matrisine **satırca (veya sütunca) denktir** ($\text{RREF}(A) = I_n$).
> 4. $AX = b$ doğrusal denklem sisteminin her $n \times 1$ boyutlu $b$ matrisi için **tek bir çözümü** (unique solution) vardır.
> 5. $\det(A) \neq 0$.

Örneğin bir homojen sistemde katsayılar matrisinin determinantını hesaplayıp $\det(A) \neq 0$ bulursanız, hiçbir satır işlemi yapmadan sistemin yalnızca sıfır çözümüne ($X = 0$) sahip olduğunu hemen söyleyebilirsiniz.

## 3. Ters Matris Yöntemiyle Doğrusal Denklem Sistemi Çözümü (Inverse Matrix Method)

### 3.1 $X = A^{-1}b$ Formülünün Çıkarılışı

$n$ bilinmeyenli $n$ denklemden oluşan doğrusal denklem sisteminin matris gösterimi $AX = b$ olsun (ekrandan, 00:31:00). Eğer $\det(A) \neq 0$ ise $A$ tekil olmayan (nonsingular) bir matristir ve tersi ($A^{-1}$) mevcuttur.

$AX = b$ eşitliğinin her iki tarafını **soldan** $A^{-1}$ ile çarparsak:
$$A^{-1}(AX) = A^{-1}b$$
Matris çarpımının birleşme özelliğinden $(A^{-1}A)X = I_n X = X$ olduğundan:
$$X = A^{-1}b$$
formülü elde edilir. Yani bilinmeyenler matrisi $X$'i bulmak için katsayılar matrisinin tersi olan $A^{-1}$'i sağ taraftaki $b$ sabitler sütunuyla soldan çarpmak yeterlidir. Bu yönteme **ters matris yöntemi** (inverse matrix method) denir.

### 3.2 Ters Matris Yöntemiyle $3 \times 3$ Lineer Sistem Çözümü Örneği

Hoca Bölüm 1.3'te Cramer kuralıyla çözdüğü sistemi bu kez ters matris yöntemiyle çözdü (ekrandan, 00:42:30):

- **Verilen:**
  $$\begin{cases} 2x_1 + 3x_2 + x_3 = 1 \\ x_1 - x_2 + 2x_3 = -3 \\ -3x_1 + 4x_2 - x_3 = 4 \end{cases}$$
  sistemini ters matris yöntemiyle çözünüz.

- **1. Adım ($\det(A)$ Kontrolü):**
  $$A = \begin{bmatrix} 2 & 3 & 1 \\ 1 & -1 & 2 \\ -3 & 4 & -1 \end{bmatrix}, \quad b = \begin{bmatrix} 1 \\ -3 \\ 4 \end{bmatrix}$$
  Önceki örnekte Sarrus kuralıyla $\det(A) = -28 \neq 0$ bulmuştuk; dolayısıyla $A^{-1}$ mevcuttur.

- **2. Adım (Kofaktörlerin ve Ek Matrisin $\text{adj}(A)$ Hesaplanması):**
  $$A^{-1} = \frac{1}{\det(A)} \text{adj}(A), \quad \text{adj}(A) = \begin{bmatrix} A_{11} & A_{21} & A_{31} \\ A_{12} & A_{22} & A_{32} \\ A_{13} & A_{23} & A_{33} \end{bmatrix}$$
  - **1. Sütun ($A_{11}, A_{12}, A_{13}$):**
    - $A_{11} = (-1)^{1+1}\begin{vmatrix} -1 & 2 \\ 4 & -1 \end{vmatrix} = +(1 - 8) = -7$
    - $A_{12} = (-1)^{1+2}\begin{vmatrix} 1 & 2 \\ -3 & -1 \end{vmatrix} = -(-1 + 6) = -5$
    - $A_{13} = (-1)^{1+3}\begin{vmatrix} 1 & -1 \\ -3 & 4 \end{vmatrix} = +(4 - 3) = 1$
  - **2. Sütun ($A_{21}, A_{22}, A_{23}$):**
    - $A_{21} = (-1)^{2+1}\begin{vmatrix} 3 & 1 \\ 4 & -1 \end{vmatrix} = -(-3 - 4) = 7$
    - $A_{22} = (-1)^{2+2}\begin{vmatrix} 2 & 1 \\ -3 & -1 \end{vmatrix} = +(-2 + 3) = 1$
    - $A_{23} = (-1)^{2+3}\begin{vmatrix} 2 & 3 \\ -3 & 4 \end{vmatrix} = -(8 + 9) = -17$
  - **3. Sütun ($A_{31}, A_{32}, A_{33}$):**
    - $A_{31} = (-1)^{3+1}\begin{vmatrix} 3 & 1 \\ -1 & 2 \end{vmatrix} = +(6 + 1) = 7$
    - $A_{32} = (-1)^{3+2}\begin{vmatrix} 2 & 1 \\ 1 & 2 \end{vmatrix} = -(4 - 1) = -3$
    - $A_{33} = (-1)^{3+3}\begin{vmatrix} 2 & 3 \\ 1 & -1 \end{vmatrix} = +(-2 - 3) = -5$

  Böylece $\text{adj}(A)$ ve $A^{-1} = \frac{1}{-28}\text{adj}(A)$ şu şekilde bulunur:
  $$\text{adj}(A) = \begin{bmatrix} -7 & 7 & 7 \\ -5 & 1 & -3 \\ 1 & -17 & -5 \end{bmatrix} \implies A^{-1} = \begin{bmatrix} \frac{1}{4} & -\frac{1}{4} & -\frac{1}{4} \\ \frac{5}{28} & -\frac{1}{28} & \frac{3}{28} \\ -\frac{1}{28} & \frac{17}{28} & \frac{5}{28} \end{bmatrix}$$

- **3. Adım ($X = A^{-1}b$ Çarpımının Yapılması — ekrandan, 00:42:30):**
  $$X = \begin{bmatrix} x_1 \\ x_2 \\ x_3 \end{bmatrix} = A^{-1}b = \begin{bmatrix} \frac{1}{4} & -\frac{1}{4} & -\frac{1}{4} \\ \frac{5}{28} & -\frac{1}{28} & \frac{3}{28} \\ -\frac{1}{28} & \frac{17}{28} & \frac{5}{28} \end{bmatrix} \begin{bmatrix} 1 \\ -3 \\ 4 \end{bmatrix}$$
  - $x_1 = \left(\frac{1}{4}\right)(1) + \left(-\frac{1}{4}\right)(-3) + \left(-\frac{1}{4}\right)(4) = \frac{1}{4} + \frac{3}{4} - \frac{4}{4} = 0$
  - $x_2 = \left(\frac{5}{28}\right)(1) + \left(-\frac{1}{28}\right)(-3) + \left(\frac{3}{28}\right)(4) = \frac{5 + 3 + 12}{28} = \frac{20}{28} = \frac{5}{7}$
  - $x_3 = \left(-\frac{1}{28}\right)(1) + \left(\frac{17}{28}\right)(-3) + \left(\frac{5}{28}\right)(4) = \frac{-1 - 51 + 20}{28} = -\frac{32}{28} = -\frac{8}{7}$

**Soru:** Ters matrisi bulurken ek matris yöntemi yerine yanına birim matris yazıp ($[A \mid I_3] \to [I_3 \mid A^{-1}]$) satır işlemleriyle bulsak olmaz mı?
**Cevap:** İsteyen o yöntemle de yapabilir; ancak $3 \times 3$ matriste determinantı zaten hesapladığımız için ek matris (adjoint) yöntemiyle ters matrisi bulmak kesirli satır işlemleriyle uğraşmaktan çok daha pratik ve avantajlıdır.

## 4. $4 \times 4$ Vandermonde Tipi Determinant ve Cramer Kuralı Uygulaması

Hoca önceki yıl sınavda da sorulmuş olan iki şıklı önemli bir örnek çözdü (ekrandan, 00:51:45 ve 00:56:30):

- **Verilen:**
  $$F = \begin{bmatrix} a & a^2 & a^3 & a^4 \\ b & b^2 & b^3 & b^4 \\ c & c^2 & c^3 & c^4 \\ d & d^2 & d^3 & d^4 \end{bmatrix}$$
  matrisinin determinantı $|F| \neq 0$ olmak üzere:
  1. Determinantın özelliklerini kullanarak $|F|$ determinantını bulunuz.
  2. $\mathbf{x} = \begin{bmatrix} x_1 \\ x_2 \\ x_3 \\ x_4 \end{bmatrix}$ ve $\mathbf{b} = \begin{bmatrix} a \\ b \\ c \\ d \end{bmatrix}$ için $F\mathbf{x} = \mathbf{b}$ sistemini Cramer kuralıyla çözünüz.

- **1. Şıkkın Çözümü ($|F|$ Determinantının Bulunması — ekrandan, 00:51:45):**
  1. $F$ matrisi $4 \times 4$ boyutludur. İlk olarak 1. satır $a$'nın, 2. satır $b$'nin, 3. satır $c$'nin ve 4. satır $d$'nin katı olduğundan bu dört çarpanı satırlardan determinantın dışına çıkarırız:
     $$|F| = abcd \begin{vmatrix} 1 & a & a^2 & a^3 \\ 1 & b & b^2 & b^3 \\ 1 & c & c^2 & c^3 \\ 1 & d & d^2 & d^3 \end{vmatrix}$$
  2. 1. sütundaki ilk $1$'in altındaki üç adet $1$'i sıfırlamak için 1. satırı $-1$ ile çarpıp sırasıyla 2., 3. ve 4. satırlara ekleriz ($-r_1 + r_2 \to r_2$, $-r_1 + r_3 \to r_3$, $-r_1 + r_4 \to r_4$):
     $$|F| = abcd \begin{vmatrix} 1 & a & a^2 & a^3 \\ 0 & b-a & b^2-a^2 & b^3-a^3 \\ 0 & c-a & c^2-a^2 & c^3-a^3 \\ 0 & d-a & d^2-a^2 & d^3-a^3 \end{vmatrix}$$
  3. Çarpanlara ayırma özdeşliklerinden $x^2 - a^2 = (x-a)(x+a)$ ve $x^3 - a^3 = (x-a)(x^2 + ax + a^2)$ olduğundan, 2. satırdan $(b-a)$, 3. satırdan $(c-a)$ ve 4. satırdan $(d-a)$ ortak çarpanlarını dışarı alırız ve 1. sütuna göre Laplace açılımı uygularız ($r = abcd(b-a)(c-a)(d-a)$ diyelim):
     $$|F| = \underbrace{abcd(b-a)(c-a)(d-a)}_{r} \begin{vmatrix} 1 & b+a & b^2+ab+a^2 \\ 1 & c+a & c^2+ac+a^2 \\ 1 & d+a & d^2+ad+a^2 \end{vmatrix}$$
  4. Elde edilen $3 \times 3$ determinantta yine 1. satırı $-1$ ile çarpıp 2. ve 3. satırlara ekleriz:
     $$= r \begin{vmatrix} 1 & b+a & b^2+ab+a^2 \\ 0 & c-b & c^2-b^2+a(c-b) \\ 0 & d-b & d^2-b^2+a(d-b) \end{vmatrix}$$
     Burada $c^2-b^2+a(c-b) = (c-b)(c+b+a)$ ve $d^2-b^2+a(d-b) = (d-b)(d+b+a)$ olduğundan 2. satırdan $(c-b)$ ve 3. satırdan $(d-b)$ ortak çarpanları dışarı alınır ve 1. sütuna göre Laplace açılımı yapılır:
     $$= r(c-b)(d-b) \begin{vmatrix} 1 & c+b+a \\ 1 & d+b+a \end{vmatrix} = r(c-b)(d-b)((d+b+a) - (c+b+a))$$
     $$|F| = abcd(b-a)(c-a)(d-a)(c-b)(d-b)(d-c)$$

- **2. Şıkkın Çözümü ($F\mathbf{x} = \mathbf{b}$ Sisteminin Cramer Kuralıyla Çözümü — ekrandan, 00:56:30):**
  > **Hocanın vurgusu:** Bu sorunun ikinci kısmı çok daha ilginçtir ve aslında birinci kısımdaki uzun determinant sonucunu kullanmaya bile gerek kalmadan çözülür!
  Cramer kuralına göre $x_i = \frac{\det(F_i)}{\det(F)}$'dir. Sağ taraftaki sabitler vektörü $\mathbf{b} = \begin{bmatrix} a & b & c & d \end{bmatrix}^T$, dikkat edilirse $F$ matrisinin **1. sütununun birebir aynısıdır**.
  - **$x_1$ için:** $F$ matrisinin 1. sütununu silip yerine $\mathbf{b} = [a, b, c, d]^T$ yazdığımızda elde edilen $F_1$ matrisi yine $F$ matrisinin kendisi olur ($F_1 = F$). Dolayısıyla:
    $$x_1 = \frac{\det(F_1)}{\det(F)} = \frac{\det(F)}{\det(F)} = 1$$
  - **$x_2$ için:** $F$ matrisinin 2. sütunu yerine $\mathbf{b} = [a, b, c, d]^T$ yazdığımızda:
    $$F_2 = \begin{bmatrix} a & a & a^3 & a^4 \\ b & b & b^3 & b^4 \\ c & c & c^3 & c^4 \\ d & d & d^3 & d^4 \end{bmatrix}$$
    matrisinin 1. sütunu ile 2. sütunu birbirine eşit olur. İki sütunu eşit olan matrisin determinantı sıfır olduğundan $\det(F_2) = 0$ ve:
    $$x_2 = \frac{\det(F_2)}{\det(F)} = \frac{0}{\det(F)} = 0$$
  - **$x_3$ ve $x_4$ için:** Aynı şekilde $\mathbf{b}$ sütunu 3. sütuna yazıldığında 1. ve 3. sütunlar eşit ($\det(F_3) = 0$), 4. sütuna yazıldığında 1. ve 4. sütunlar eşit ($\det(F_4) = 0$) olacağından:
    $$x_3 = 0, \quad x_4 = 0$$
    bulunur. Böylece çözüm $(x_1, x_2, x_3, x_4) = (1, 0, 0, 0)$'dır.

## 5. Vize Sınavı Sorularının Ayrıntılı Çözümleri

Dersin son yarım saatinde hoca yapılan 1. vize sınavının sorularını ekrana yansıtarak tek tek çözdü.

### 5.1 Vize Sorusu 1: Kare Olmayan Matris Çarpım Denklemi ($XA = Y$)

- **Soru (ekrandan, 01:05:30):**
  $$X = \begin{bmatrix} 1 & 5 \\ 7 & 0 \\ 8 & 4 \end{bmatrix} \quad \text{ve} \quad Y = \begin{bmatrix} -3 & 15 \\ 14 & 0 \\ 12 & 12 \end{bmatrix}$$
  matrisleri verilsin. $XA = Y$ eşitliğini sağlayan $A = [a_{ij}]$ matrisi mevcutsa tüm $a_{ij}$ elemanlarının toplamı kaçtır?
  A) $A$ mevcut değildir ($A$ does not exist) $\quad$ B) $2$ $\quad$ C) $3$ $\quad$ D) $4$ $\quad$ E) $5$

- **Çözüm:**
  Birçok öğrenci $XA = Y$ denklemini görünce her iki tarafı soldan $X^{-1}$ ile çarpmayı düşünmüş ve $X$ matrisi $3 \times 2$ boyutlu olduğu (kare olmadığı) için tersi alınamayacağından yanılarak "A mevcut değildir" şıkkını işaretlemiştir. Oysa $X$'in tersinin olmaması $A$ matrisinin olmadığı anlamına gelmez!
  - **Boyut Analizi:** $X$ matrisi $3 \times 2$ boyutludur, sonuç matrisi $Y$ de $3 \times 2$ boyutludur. Matris çarpımının tanımlı olması için $A$'nın satır sayısı $X$'in sütun sayısına ($2$), $A$'nın sütun sayısı ise $Y$'nin sütun sayısına ($2$) eşit olmalıdır. Yani $A$ matrisi $2 \times 2$ boyutlu bir matristir:
    $$A = \begin{bmatrix} a & b \\ c & d \end{bmatrix}$$
  - **Denklemlerin Kurulması ve Çözümü:**
    $$\begin{bmatrix} 1 & 5 \\ 7 & 0 \\ 8 & 4 \end{bmatrix} \begin{bmatrix} a & b \\ c & d \end{bmatrix} = \begin{bmatrix} -3 & 15 \\ 14 & 0 \\ 12 & 12 \end{bmatrix}$$
    - 1. ve 2. satırların $A$'nın 1. sütunu $\begin{bmatrix} a \\ c \end{bmatrix}$ ile çarpımından:
      $$\begin{cases} 1\cdot a + 5\cdot c = -3 \\ 7\cdot a + 0\cdot c = 14 \end{cases} \implies 7a = 14 \implies a = 2$$
      $a = 2$ ilk denklemde yerine yazılırsa $2 + 5c = -3 \implies 5c = -5 \implies c = -1$. (3. satırda da $8(2) + 4(-1) = 16 - 4 = 12$ sağlandığı görülür.)
    - 1. ve 2. satırların $A$'nın 2. sütunu $\begin{bmatrix} b \\ d \end{bmatrix}$ ile çarpımından:
      $$\begin{cases} 1\cdot b + 5\cdot d = 15 \\ 7\cdot b + 0\cdot d = 0 \end{cases} \implies 7b = 0 \implies b = 0$$
      $b = 0$ ilk denklemde yerine yazılırsa $0 + 5d = 15 \implies d = 3$. (3. satırda da $8(0) + 4(3) = 12$ sağlanır.)
  - **Elemanların Toplamı:**
    $$a + b + c + d = 2 + 0 + (-1) + 3 = 4$$
    bulunur (Cevap: D).

### 5.2 Vize Sorusu 2: Matris Polinom Denkleminden Ters Matris Bulma

- **Soru (ekrandan, 01:09:15):**
  Tersinir (invertible) bir $A$ matrisi için $A^3 - 15A + 4I = 0$ denklemi sağlanmaktadır. Eğer
  $$A^2 = \begin{bmatrix} 7 & 4 \\ 12 & 7 \end{bmatrix}$$
  ise aşağıdakilerden hangisi $A^{-1}$ matrisidir?

- **Çözüm:**
  $A$ matrisi tersinir (invertible) olduğundan $A^{-1}$ mevcuttur. Verilen $A^3 - 15A + 4I = 0$ denkleminin her iki tarafını soldan $A^{-1}$ ile çarpalım:
  $$A^{-1}(A^3 - 15A + 4I) = A^{-1} \cdot 0 = 0$$
  Burada $A^{-1}A^3 = A^2$, $A^{-1}A = I_2$ ve $A^{-1}I = A^{-1}$ olduğundan:
  $$A^2 - 15I_2 + 4A^{-1} = 0 \implies 4A^{-1} = 15I_2 - A^2$$
  $I_2 = \begin{bmatrix} 1 & 0 \\ 0 & 1 \end{bmatrix}$ ve verilen $A^2$ matrisi yerine yazılırsa:
  $$4A^{-1} = \begin{bmatrix} 15 & 0 \\ 0 & 15 \end{bmatrix} - \begin{bmatrix} 7 & 4 \\ 12 & 7 \end{bmatrix} = \begin{bmatrix} 8 & -4 \\ -12 & 8 \end{bmatrix}$$
  Tüm elemanlar $4$'e bölündüğünde:
  $$A^{-1} = \begin{bmatrix} 2 & -1 \\ -3 & 2 \end{bmatrix}$$
  elde edilir (Cevap: A).

### 5.3 Vize Sorusu 3: Determinant Çarpanlı $3 \times 3$ Matrisin Rankı

- **Soru (ekrandan, 01:13:30):**
  $$\begin{vmatrix} 3 & 1 & 2 \\ 1 & 4 & 1 \\ 7 & 2 & -3 \end{vmatrix} \begin{bmatrix} -1 & 0 & 0 \\ 2 & -1 & 12 \\ -1 & 2 & 4 \end{bmatrix}$$
  matrisinin rankı kaçtır?
  A) $2$ $\quad$ B) $3$ $\quad$ C) $4$ $\quad$ D) $5$ $\quad$ E) Bu matrisin rankı hesaplanamaz.

- **Çözüm:**
  1. İfadenin solundaki $\begin{vmatrix} 3 & 1 & 2 \\ 1 & 4 & 1 \\ 7 & 2 & -3 \end{vmatrix}$ bir matris değil, bir **determinanttır**, yani tek bir reel sayıdır (skalerdir). Eğer bu reel sayı $0$ olsaydı çarpım sıfır matrisi olurdu ve rank $0$ çıkardı; ancak şıklarda $0$ bulunmadığından bu determinantın sıfırdan farklı olduğu açıktır ve onu hesaplamaya bile gerek yoktur (hesaplanırsa $-36+7+4-(56+6-3)=-84\neq 0$).
  2. Sağdaki matris $3 \times 3$ boyutlu bir matristir. $3 \times 3$ boyutlu bir matrisin rankı en fazla $3$ olabilir; bu nedenle C ($4$), D ($5$) ve E şıkları hemen elenir.
  3. Sağdaki $3 \times 3$ matrisin rankının $3$ mü yoksa $2$ mi olduğunu anlamak için determinantına bakarız: Eğer $3 \times 3$ matrisin determinantı sıfırdan farklıysa matris tersinirdir ve rankı $3$'tür. 1. satırda iki adet sıfır bulunduğundan 1. satıra göre Laplace açılımı yaparsak:
     $$\begin{vmatrix} -1 & 0 & 0 \\ 2 & -1 & 12 \\ -1 & 2 & 4 \end{vmatrix} = (-1)\cdot(-1)^{1+1}\begin{vmatrix} -1 & 12 \\ 2 & 4 \end{vmatrix} = -1 \cdot (-4 - 24) = (-1)(-28) = 28 \neq 0$$
     Determinant sıfırdan farklı olduğundan matrisin rankı **$3$**'tür (Cevap: B).

### 5.4 Vize Sorusu 4: Eşit Elemanlı Matriste Laplace Açılımı

- **Soru (ekrandan, 01:18:15):**
  $a_{23} = a_{31}$ ve $a_{11} = a_{22}$ koşullarını sağlayan
  $$A = \begin{bmatrix} a_{11} & a_{12} & a_{13} \\ a_{21} & a_{22} & a_{23} \\ a_{31} & a_{32} & a_{33} \end{bmatrix}$$
  matrisinin determinantını hesaplamak için aşağıdakilerden hangisi **kullanılamaz**? ($A_{ij}$, $a_{ij}$ elemanının kofaktörünü göstermektedir.)
  - A) $a_{21}A_{21} + a_{22}A_{22} + a_{23}A_{23}$
  - B) $a_{12}A_{12} + a_{11}A_{22} + a_{32}A_{32}$
  - C) $a_{22}A_{11} + a_{21}A_{21} + a_{23}A_{31}$
  - D) $a_{11}A_{11} + a_{22}A_{22} + a_{33}A_{33}$
  - E) $a_{23}A_{31} + a_{32}A_{32} + a_{33}A_{33}$

- **Çözüm:**
  Soruda verilen $a_{23} = a_{31}$ ve $a_{11} = a_{22}$ eşitliklerini şıklarda yerine koyarak hangilerinin geçerli bir satır veya sütun Laplace açılımı olduğuna bakalım:
  - **A şıkkı:** $a_{21}A_{21} + a_{22}A_{22} + a_{23}A_{23}$ doğrudan **2. satır boyunca** Laplace açılımıdır; doğrudur.
  - **B şıkkı:** Ortadaki terimde $a_{11} = a_{22}$ olduğundan $a_{11}$ yerine $a_{22}$ yazarsak $a_{12}A_{12} + a_{22}A_{22} + a_{32}A_{32}$ olur ki bu **2. sütun boyunca** Laplace açılımıdır; doğrudur.
  - **C şıkkı:** $a_{22} = a_{11}$ ve $a_{23} = a_{31}$ eşitliklerini yerine koyarsak ifade $a_{11}A_{11} + a_{21}A_{21} + a_{31}A_{31}$ olur ki bu **1. sütun boyunca** Laplace açılımıdır; doğrudur.
  - **E şıkkı:** İlk terimde $a_{23} = a_{31}$ yerine konulursa $a_{31}A_{31} + a_{32}A_{32} + a_{33}A_{33}$ olur ki bu da **3. satır boyunca** Laplace açılımıdır; doğrudur.
  - **D şıkkı:** $a_{11}A_{11} + a_{22}A_{22} + a_{33}A_{33}$ ifadesi esas köşegen (main diagonal) elemanlarıyla yazılmıştır. Laplace açılımı yalnızca bir satır veya bir sütun boyunca yapılabilir, **köşegen boyunca yapılamaz**. Dolayısıyla D kullanılamaz (Cevap: D).

### 5.5 Vize Sorusu 5: Değişmeli Hermityen ve Ters Hermityen Matrisler

- **Soru (ekrandan, 01:24:45):**
  $A$ ve $B$, çarpmaya göre değişmeli (commutative: $AB = BA$) $n \times n$ boyutlu matrisler olsun. Eğer $A$ **Hermityen** (Hermitian) ve $B$ **ters Hermityen** (skew-Hermitian) ise aşağıdakilerden hangisi **ters Hermityen** bir matristir?
  A) $AB + A$ $\quad$ B) $-AB + A$ $\quad$ C) $BA + A^T$ $\quad$ D) $AB + B$ $\quad$ E) $-AB + A^T$

- **Çözüm:**
  Verilen bilgileri matematiksel olarak yazalım:
  - $A$ ve $B$ değişmeli: $AB = BA$
  - $A$ Hermityen: $(\overline{A})^T = A$
  - $B$ ters Hermityen: $(\overline{B})^T = -B$

  Bir $M$ matrisinin ters Hermityen olması için $(\overline{M})^T = -M$ şartını sağlaması gerekir.
  - **A şıkkını ($AB + A$) kontrol edelim:**
    $$(\overline{AB + A})^T = (\overline{AB})^T + (\overline{A})^T = (\overline{B})^T(\overline{A})^T + A = (-B)A + A = -AB + A \neq -(AB + A)$$
    Dolayısıyla A şıkkı ters Hermityen değildir.
  - **D şıkkını ($AB + B$) kontrol edelim:**
    $$(\overline{AB + B})^T = (\overline{B})^T(\overline{A})^T + (\overline{B})^T = (-B)(A) + (-B) = -BA - B$$
    $A$ ve $B$ değişmeli ($BA = AB$) olduğundan:
    $$= -AB - B = -(AB + B)$$
    elde edilir. Eşlenik transpozu kendi eksilisine eşit olduğundan **$AB + B$ ters Hermityendir** (Cevap: D).

### 5.6 Vize Sorusu 6: Determinant ve Ek Matris Önermeleri

- **Soru (ekrandan, 01:28:55):**
  Aşağıdaki ifadelerden hangisi ya da hangileri **her zaman** doğrudur?
  - I. $\det(A B^T A^{-1}) = \det(B)$
  - II. $\det(A + B) = \det(A) + \det(B)$
  - III. Her $A$ kare matrisi için $A \cdot \text{adj}(A)$ bir köşegen matristir (diagonal matrix).
  - IV. İki tekil olmayan (non-singular) $n \times n$ matrisin toplamı tekildir (singular).

- **Çözüm:**
  1. **I. Öncül:** Determinantın çarpım, transpoz ve ters matris özelliklerinden:
     $$\det(A B^T A^{-1}) = \det(A) \cdot \det(B^T) \cdot \det(A^{-1}) = \det(A) \cdot \det(B) \cdot \frac{1}{\det(A)} = \det(B)$$
     olup **her zaman doğrudur**.
  2. **II. Öncül:** Toplamın determinantı genel olarak determinantların toplamına eşit değildir ($\det(A+B) \neq \det(A) + \det(B)$); **yanlıştır**.
  3. **III. Öncül:** Teoremden her $A$ kare matrisi için:
     $$A \cdot \text{adj}(A) = \det(A) I_n = \begin{bmatrix} \det(A) & 0 & \cdots & 0 \\ 0 & \det(A) & \cdots & 0 \\ \vdots & \vdots & \ddots & \vdots \\ 0 & 0 & \cdots & \det(A) \end{bmatrix}$$
     olduğunu biliyoruz. Bu matris bir skaler matristir ve esas köşegeni dışındaki tüm elemanları sıfır olduğu için aynı zamanda bir **köşegen matristir** (diagonal matrix). Dolayısıyla **her zaman doğrudur**.
  4. **IV. Öncül:** İki tekil olmayan matrisin toplamı tekil de olabilir (örneğin $I_n + (-I_n) = 0$), tekil olmayan da olabilir (örneğin $I_n + I_n = 2I_n$). "Her zaman doğrudur" diye sorulduğu için **yanlıştır**.
  Sonuç olarak yalnız **I ve III** her zaman doğrudur (Cevap: A).

## Örnek Sorular

### Soru 1: Cramer Kuralı ve Ters Matris Yöntemiyle Sistem Çözümü (ekrandan, 00:22:00 ve 00:42:30)

**Soru:**
$$\begin{cases} 2x_1 + 3x_2 + x_3 = 1 \\ x_1 - x_2 + 2x_3 = -3 \\ -3x_1 + 4x_2 - x_3 = 4 \end{cases}$$
doğrusal denklem sistemini hem Cramer kuralıyla hem de ters matris yöntemiyle çözünüz.

**Çözüm:**
- **Cramer Kuralı:** $\det(A) = -28$, $\det(A_1) = 0$, $\det(A_2) = -20$, $\det(A_3) = 32$ hesaplanarak:
  $$x_1 = \frac{0}{-28} = 0, \quad x_2 = \frac{-20}{-28} = \frac{5}{7}, \quad x_3 = \frac{32}{-28} = -\frac{8}{7}$$
- **Ters Matris Yöntemi:**
  $$A^{-1} = \frac{1}{-28}\text{adj}(A) = \begin{bmatrix} \frac{1}{4} & -\frac{1}{4} & -\frac{1}{4} \\ \frac{5}{28} & -\frac{1}{28} & \frac{3}{28} \\ -\frac{1}{28} & \frac{17}{28} & \frac{5}{28} \end{bmatrix} \implies X = A^{-1}b = \begin{bmatrix} 0 \\ \frac{5}{7} \\ -\frac{8}{7} \end{bmatrix}$$

### Soru 2: $4 \times 4$ Determinant ve Cramer Kuralı (ekrandan, 00:51:45 ve 00:56:30)

**Soru:**
$$F = \begin{bmatrix} a & a^2 & a^3 & a^4 \\ b & b^2 & b^3 & b^4 \\ c & c^2 & c^3 & c^4 \\ d & d^2 & d^3 & d^4 \end{bmatrix}, \quad |F| \neq 0$$
olmak üzere $|F|$ determinantını çarpanlarına ayırınız ve $\mathbf{b} = [a, b, c, d]^T$ için $F\mathbf{x} = \mathbf{b}$ sistemini Cramer kuralıyla çözünüz.

**Çözüm:**
1. Satırlardan $a, b, c, d$ çarpanları dışarı alınıp Vandermonde indirgemesi yapıldığında:
   $$|F| = abcd(b-a)(c-a)(d-a)(c-b)(d-b)(d-c)$$
2. $\mathbf{b}$ sütunu $F$'nin 1. sütunuyla aynı olduğundan $F_1 = F \implies x_1 = \frac{\det(F)}{\det(F)} = 1$. $i = 2, 3, 4$ için $F_i$ matrisinin 1. ve $i$. sütunları eşit olduğundan $\det(F_i) = 0 \implies x_2 = x_3 = x_4 = 0$.

### Soru 3: Kare Olmayan Matris Çarpım Denklemi (ekrandan, 01:05:30)

**Soru:**
$$X = \begin{bmatrix} 1 & 5 \\ 7 & 0 \\ 8 & 4 \end{bmatrix} \quad \text{ve} \quad Y = \begin{bmatrix} -3 & 15 \\ 14 & 0 \\ 12 & 12 \end{bmatrix}$$
için $XA = Y$ denklemini sağlayan $A$ matrisinin elemanları toplamı kaçtır?

**Çözüm:**
$A = \begin{bmatrix} a & b \\ c & d \end{bmatrix}_{2 \times 2}$ olmak üzere $a + 5c = -3$, $7a = 14 \implies a = 2, c = -1$; $b + 5d = 15$, $7b = 0 \implies b = 0, d = 3$. Toplam: $2 + 0 - 1 + 3 = 4$.

### Soru 4: Polinom Denkleminden Ters Matris Bulma (ekrandan, 01:09:15)

**Soru:** Tersinir $A$ matrisi $A^3 - 15A + 4I = 0$ denklemini sağlıyor ve $A^2 = \begin{bmatrix} 7 & 4 \\ 12 & 7 \end{bmatrix}$ ise $A^{-1}$ matrisini bulunuz.

**Çözüm:**
Denklem $A^{-1}$ ile çarpılırsa $A^2 - 15I_2 + 4A^{-1} = 0 \implies A^{-1} = \frac{1}{4}(15I_2 - A^2) = \frac{1}{4}\begin{bmatrix} 8 & -4 \\ -12 & 8 \end{bmatrix} = \begin{bmatrix} 2 & -1 \\ -3 & 2 \end{bmatrix}$.

## Dersin Toparlaması

Bu derste doğrusal denklem sistemlerinin çözümüne yönelik iki yöntem daha tamamlandı: katsayılar matrisi $n \times n$ kare ve $\det(A) \neq 0$ olan sistemlerde $x_i = \frac{\det(A_i)}{\det(A)}$ formülüyle uygulanan Cramer kuralı ve $X = A^{-1}b$ formülüyle uygulanan ters matris yöntemi. Ayrıca bir $n \times n$ kare matris için tersinirlik, $\det(A) \neq 0$, birim matrise satırca denklik, $AX = 0$ homojen sisteminin yalnız sıfır çözümüne sahip olması ve $AX = b$ sisteminin her $b$ için tek çözümlü olması ifadelerinin birbirine denk olduğu özetlendi. Dersin son bölümünde ise 1. vize sınavının soruları çözülerek kare olmayan matris denklemleri, matris polinomlarıyla ters matris hesabı, determinant ile rank ilişkisi, Laplace açılımı ve Hermityen/ters Hermityen matris özellikleri tekrar edildi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
