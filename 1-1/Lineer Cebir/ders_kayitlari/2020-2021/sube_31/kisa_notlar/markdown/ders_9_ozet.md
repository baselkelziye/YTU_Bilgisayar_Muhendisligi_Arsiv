# Ders 9 Çalışma Özeti

## Genel Konular

- Cramer Kuralı ile Doğrusal Denklem Sistemlerinin Çözümü (Cramer's Rule)
  - Cramer kuralı **yalnızca** denklem sayısı ile bilinmeyen sayısı birbirine eşit ($n$ bilinmeyenli $n$ denklem, yani katsayılar matrisi $A$ kare matris) ve katsayılar matrisinin determinantı sıfırdan farklı ($\det(A) \neq 0$, yani $A$ tekil olmayan / nonsingular) olan $AX = b$ doğrusal denklem sistemlerine uygulanabilir (ekrandan, 00:13:00).
  - $\det(A) \neq 0$ olduğunda sistemin tek bir çözümü (unique solution) vardır ve bilinmeyenler şu formülle bulunur (ekrandan, 00:22:00):
    $$x_1 = \frac{\det(A_1)}{\det(A)}, \quad x_2 = \frac{\det(A_2)}{\det(A)}, \quad \dots, \quad x_n = \frac{\det(A_n)}{\det(A)}$$
  - Burada $A_i$ matrisi, $A$ katsayılar matrisinin $i$. sütununun silinip yerine sağ taraftaki $b$ sabitler sütun vektörünün yazılmasıyla elde edilen $n \times n$ boyutlu matristir.
  - Bilinmeyen sayısı $n \ge 4$ olduğunda yüksek boyutlu çok sayıda determinant hesaplamak gerektiğinden Cramer kuralı verimsiz (inefficient) hale gelir; bu durumda Gauss veya Gauss-Jordan eliminasyon yöntemi tercih edilmelidir.
- Tersinir (Nonsingular) Matrisler İçin Denk İfadeler Özeti (Equivalent Statements for an $n \times n$ Matrix)
  - Bir $n \times n$ boyutlu $A$ kare matrisi için aşağıdaki beş ifade birbirine denktir (biri doğruysa diğer dördü de doğrudur) (ekrandan, 00:27:30):
    1. $A$ tekil olmayan (nonsingular / tersinir / invertible) bir matristir.
    2. $AX = 0$ homojen sisteminin yalnızca aşikar (trivial / sıfır: $x_1 = x_2 = \dots = x_n = 0$) çözümü vardır.
    3. $A$ matrisi $I_n$ birim matrisine satırca (veya sütunca) denktir ($\text{RREF}(A) = I_n$).
    4. $AX = b$ doğrusal denklem sisteminin her $n \times 1$ boyutlu $b$ matrisi için tek bir çözümü (unique solution) vardır.
    5. $\det(A) \neq 0$.
- Ters Matris Yöntemiyle Doğrusal Denklem Sistemi Çözümü (Inverse Matrix Method)
  - $n$ bilinmeyenli $n$ denklemden oluşan $AX = b$ sisteminde $\det(A) \neq 0$ ise $A$ tekil değildir ve $A^{-1}$ mevcuttur. Denklemin her iki tarafı **soldan** $A^{-1}$ ile çarpıldığında (ekrandan, 00:31:00):
    $$A^{-1}(AX) = A^{-1}b \implies (A^{-1}A)X = A^{-1}b \implies I_n X = A^{-1}b \implies X = A^{-1}b$$
    bulunur. Yani $A^{-1} = \frac{1}{\det(A)}\text{adj}(A)$ hesaplanıp sağ taraftaki $b$ sütun matrisiyle çarpılarak $X$ bilinmeyenler vektörü doğrudan elde edilir (ekrandan, 00:42:30).
- $4 \times 4$ Vandermonde Tipi Determinant ve Vize Sınavı Sorularının Çözümü (4x4 Determinant & Midterm Exam Questions)
  - $F = \begin{bmatrix} a & a^2 & a^3 & a^4 \\ b & b^2 & b^3 & b^4 \\ c & c^2 & c^3 & c^4 \\ d & d^2 & d^3 & d^4 \end{bmatrix}$ matrisinin determinantı satırlardan $a, b, c, d$ ortak çarpanları çıkarılıp satır farkları ve Laplace açılımı kullanılarak $|F| = abcd(b-a)(c-a)(d-a)(c-b)(d-b)(d-c)$ olarak bulunur; $b = [a, b, c, d]^T$ için $Fx = b$ sistemi Cramer kuralıyla çözüldüğünde $F_1 = F$ olduğundan $x_1 = 1$, $F_2, F_3, F_4$ matrislerinde ise ikişer sütun aynı olduğundan $x_2 = x_3 = x_4 = 0$ elde edilir (ekrandan, 00:51:45 ve 00:56:30).
  - Vize sınavında sorulan matris boyutu ve çarpımı ($XA = Y$), polinom denkleminden ters matris bulma ($A^3 - 15A + 4I = 0$), determinant yardımıyla $3 \times 3$ matrisin rankını bulma, eşit elemanlı matriste Laplace açılımı, değişmeli Hermityen / ters Hermityen matrisler ve temel determinant/ek matris önermeleri çözülmüştür (ekrandan, 01:05:30–01:28:55).

## Hocanın Özellikle Vurguladığı Kısımlar

- Cramer Kuralının Uygulanabilme Koşulları
  - Cramer kuralını kullanabilmek için iki temel şart vardır: 1) Denklem sayısı bilinmeyen sayısına eşit olmalıdır ($A$ kare matris olmalıdır), 2) Katsayılar matrisinin determinantı sıfırdan farklı olmalıdır ($\det(A) \neq 0$). Ayrıca $n \ge 4$ için Cramer kuralı çok fazla determinant hesabı gerektirdiğinden pratikte kullanışsızdır.
- Sütunların Aynı Olması Durumunda Cramer Kuralında Pratiklik
  - $Fx = b$ sisteminde sağ taraftaki $b$ vektörü, katsayılar matrisi $F$'nin 1. sütunu ile aynıysa ($b = [a, b, c, d]^T$), Cramer kuralında $F_1$ matrisi doğrudan $F$'ye eşit olur ve $|F|$'nin değerini bilmeye bile gerek kalmadan $x_1 = \frac{\det(F_1)}{\det(F)} = \frac{\det(F)}{\det(F)} = 1$ bulunur. Diğer $F_2, F_3, F_4$ matrislerinde ise 1. sütun ile $i$. sütun birbirinin aynısı olacağından determinantları doğrudan $0$ olur ve $x_2 = x_3 = x_4 = 0$ bulunur (ekrandan, 00:56:30).
- Kare Olmayan Matrislerin Çarpım Denklemlerinde Ters Matris Kullanılamaması
  - $XA = Y$ gibi bir matris denkleminde $X$ matrisi $3 \times 2$ boyutluysa kare matris olmadığı için **$X$'in tersi ($X^{-1}$) yoktur**; dolayısıyla "iki tarafı soldan $X^{-1}$ ile çarpayım" denilemez ve "tersi yok o halde $A$ mevcut değildir" hatasına düşülmemelidir. Bunun yerine boyut uyumundan $A$'nın $2 \times 2$ boyutlu $\begin{bmatrix} a & b \\ c & d \end{bmatrix}$ matrisi olduğu belirlenip çarpım yapılarak elemanlar bulunur (ekrandan, 01:05:30).
- Laplace Açılımının Köşegen Boyunca Yapılamayacağı
  - Laplace (kofaktör) açılımı yalnızca bir **satır** veya bir **sütun** boyunca yapılabilir; esas köşegen veya yedek köşegen elemanları kendi kofaktörleriyle çarpılıp toplanarak ($a_{11}A_{11} + a_{22}A_{22} + a_{33}A_{33}$) determinant **hesaplanamaz** (ekrandan, 01:18:15).

## Kısa Tekrar Notları

- Cramer kuralı ($A \in M_{n \times n}$, $\det(A) \neq 0$): $x_i = \frac{\det(A_i)}{\det(A)}$ ($A_i$: $A$'nın $i$. sütununa $b$ yazılmış hali).
- Ters matris yöntemi ($A \in M_{n \times n}$, $\det(A) \neq 0$): $AX = b \implies X = A^{-1}b = \frac{1}{\det(A)}\text{adj}(A)b$.
- Tersinirlik denklikleri ($A \in M_{n \times n}$): $A$ tersinirdir $\iff \det(A) \neq 0 \iff \text{rank}(A) = n \iff \text{RREF}(A) = I_n \iff AX = 0$ yalnız $X = 0$ çözümüne sahiptir $\iff AX = b$ her $b$ için tek çözümlüdür.
- $n \times n$ kare matriste $\det(A) \neq 0 \implies \text{rank}(A) = n$.
- Polinom denkleminden $A^{-1}$ bulma: $A^3 - 15A + 4I = 0$ denklemi $A^{-1}$ ile çarpılırsa $A^2 - 15I + 4A^{-1} = 0 \implies A^{-1} = \frac{1}{4}(15I - A^2)$ (ekrandan, 01:09:15).
- Ters Hermityen (Skew-Hermitian) matris: $(\overline{B})^T = -B$.
- Her $A$ kare matrisi için $A \cdot \text{adj}(A) = \det(A) I_n$ bir skaler matristir ve her skaler matris aynı zamanda bir **köşegen matristir** (diagonal matrix).

## Detaylı Açıklamalar

- **Cramer Kuralı ve Ters Matris Yöntemiyle Aynı Sistemin Çözümü (ekrandan, 00:22:00 ve 00:42:30):**
  Derste aşağıdaki $3$ bilinmeyenli $3$ denklemli sistem hem Cramer kuralıyla hem de ters matris yöntemiyle çözülmüştür:
  $$\begin{cases} 2x_1 + 3x_2 + x_3 = 1 \\ x_1 - x_2 + 2x_3 = -3 \\ -3x_1 + 4x_2 - x_3 = 4 \end{cases}$$
  Katsayılar matrisi $A = \begin{bmatrix} 2 & 3 & 1 \\ 1 & -1 & 2 \\ -3 & 4 & -1 \end{bmatrix}$ ve sabitler vektörü $b = \begin{bmatrix} 1 \\ -3 \\ 4 \end{bmatrix}$'tür. Sarrus kuralıyla $\det(A) = (2 - 18 + 4) - (3 + 16 - 3) = -12 - 16 = -28 \neq 0$ bulunur; sistemin tek çözümü vardır.
  1. **Cramer Kuralı ile Çözüm (ekrandan, 00:22:00):**
     - $A$'nın 1. sütununa $b$ yazılarak: $\det(A_1) = \begin{vmatrix} 1 & 3 & 1 \\ -3 & -1 & 2 \\ 4 & 4 & -1 \end{vmatrix} = (1 + 24 - 12) - (-4 + 8 + 9) = 13 - 13 = 0 \implies x_1 = \frac{0}{-28} = 0$.
     - $A$'nın 2. sütununa $b$ yazılarak: $\det(A_2) = \begin{vmatrix} 2 & 1 & 1 \\ 1 & -3 & 2 \\ -3 & 4 & -1 \end{vmatrix} = -20 \implies x_2 = \frac{-20}{-28} = \frac{5}{7}$.
     - $A$'nın 3. sütununa $b$ yazılarak: $\det(A_3) = \begin{vmatrix} 2 & 3 & 1 \\ 1 & -1 & -3 \\ -3 & 4 & 4 \end{vmatrix} = 32 \implies x_3 = \frac{32}{-28} = -\frac{8}{7}$.
  2. **Ters Matris Yöntemi ile Çözüm (ekrandan, 00:42:30):**
     $A$ matrisinin kofaktörleri hesaplandığında:
     - $A_{11} = -7, \quad A_{21} = 7, \quad A_{31} = 7$
     - $A_{12} = -5, \quad A_{22} = 1, \quad A_{32} = -3$
     - $A_{13} = 1, \quad A_{23} = -17, \quad A_{33} = -5$
     Ek matris $\text{adj}(A) = [A_{ij}]^T$ yazılıp $\det(A) = -28$'e bölündüğünde:
     $$A^{-1} = \frac{1}{-28} \begin{bmatrix} -7 & 7 & 7 \\ -5 & 1 & -3 \\ 1 & -17 & -5 \end{bmatrix} = \begin{bmatrix} \frac{1}{4} & -\frac{1}{4} & -\frac{1}{4} \\ \frac{5}{28} & -\frac{1}{28} & \frac{3}{28} \\ -\frac{1}{28} & \frac{17}{28} & \frac{5}{28} \end{bmatrix}$$
     Buradan $X = A^{-1}b$ çarpımı yapıldığında:
     $$X = \begin{bmatrix} x_1 \\ x_2 \\ x_3 \end{bmatrix} = \begin{bmatrix} \frac{1}{4} & -\frac{1}{4} & -\frac{1}{4} \\ \frac{5}{28} & -\frac{1}{28} & \frac{3}{28} \\ -\frac{1}{28} & \frac{17}{28} & \frac{5}{28} \end{bmatrix} \begin{bmatrix} 1 \\ -3 \\ 4 \end{bmatrix} = \begin{bmatrix} \frac{1}{4} + \frac{3}{4} - \frac{4}{4} \\ \frac{5}{28} + \frac{3}{28} + \frac{12}{28} \\ -\frac{1}{28} - \frac{51}{28} + \frac{20}{28} \end{bmatrix} = \begin{bmatrix} 0 \\ \frac{20}{28} \\ -\frac{32}{28} \end{bmatrix} = \begin{bmatrix} 0 \\ \frac{5}{7} \\ -\frac{8}{7} \end{bmatrix}$$
     olarak aynı sonuç elde edilir.

- **Vize Sınavı Sorularının Çözümleri (ekrandan, 01:05:30–01:28:55):**
  1. **Soru 1 — Kare Olmayan Matris Çarpım Denklemi (ekrandan, 01:05:30):**
     $X = \begin{bmatrix} 1 & 5 \\ 7 & 0 \\ 8 & 4 \end{bmatrix}_{3 \times 2}$ ve $Y = \begin{bmatrix} -3 & 15 \\ 14 & 0 \\ 12 & 12 \end{bmatrix}_{3 \times 2}$ için $XA = Y$ eşitliğini sağlayan $A = [a_{ij}]$ matrisinin elemanları toplamı kaçtır?
     - $X$ ($3 \times 2$) ve $Y$ ($3 \times 2$) olduğundan çarpımın tanımlı olması için $A$ matrisi $2 \times 2$ boyutlu olmalıdır: $A = \begin{bmatrix} a & b \\ c & d \end{bmatrix}$.
     - 1. sütun çarpımlarından: $a + 5c = -3$ ve $7a + 0c = 14 \implies a = 2$, yerine yazılınca $2 + 5c = -3 \implies c = -1$.
     - 2. sütun çarpımlarından: $b + 5d = 15$ ve $7b + 0d = 0 \implies b = 0$, yerine yazılınca $5d = 15 \implies d = 3$.
     - Elemanlar toplamı: $a + b + c + d = 2 + 0 + (-1) + 3 = 4$.
  2. **Soru 2 — Polinom Denkleminden Ters Matris Bulma (ekrandan, 01:09:15):**
     Tersinir bir $A$ matrisi $A^3 - 15A + 4I = 0$ denklemini sağlıyor. $A^2 = \begin{bmatrix} 7 & 4 \\ 12 & 7 \end{bmatrix}$ ise $A^{-1}$ nedir?
     - Denklem $A^{-1}$ ile çarpılırsa: $A^{-1}(A^3 - 15A + 4I) = 0 \implies A^2 - 15I_2 + 4A^{-1} = 0$.
     - $4A^{-1} = 15I_2 - A^2 = \begin{bmatrix} 15 & 0 \\ 0 & 15 \end{bmatrix} - \begin{bmatrix} 7 & 4 \\ 12 & 7 \end{bmatrix} = \begin{bmatrix} 8 & -4 \\ -12 & 8 \end{bmatrix} \implies A^{-1} = \begin{bmatrix} 2 & -1 \\ -3 & 2 \end{bmatrix}$.
  3. **Soru 3 — Determinantlı Matrisin Rankı (ekrandan, 01:13:30):**
     $M = \begin{vmatrix} 3 & 1 & 2 \\ 1 & 4 & 1 \\ 7 & 2 & -3 \end{vmatrix} \begin{bmatrix} -1 & 0 & 0 \\ 2 & -1 & 12 \\ -1 & 2 & 4 \end{bmatrix}$ matrisinin rankı kaçtır?
     - Baştaki $3 \times 3$ determinant sıfırdan farklı bir reel sayıdır (skalerdir); şıklarda $0$ olmadığı için bu determinantın sıfır olmadığı anlaşılır. Sağdaki $3 \times 3$ matrisin determinantı 1. satıra göre Laplace açılımıyla $(-1)(-1)^{1+1}\begin{vmatrix} -1 & 12 \\ 2 & 4 \end{vmatrix} = -1(-4 - 24) = 28 \neq 0$ olduğundan rankı $3$'tür.
  4. **Soru 4 — Eşit Elemanlı Matriste Laplace Açılımı (ekrandan, 01:18:15):**
     $a_{23} = a_{31}$ ve $a_{11} = a_{22}$ koşullarını sağlayan $3 \times 3$ boyutlu $A = [a_{ij}]$ matrisinin determinantını hesaplamak için aşağıdakilerden hangisi **kullanılamaz**?
     - A) $a_{21}A_{21} + a_{22}A_{22} + a_{23}A_{23}$ (2. satır açılımı, kullanılır).
     - B) $a_{12}A_{12} + a_{11}A_{22} + a_{32}A_{32}$ ($a_{11}=a_{22}$ olduğundan 2. sütun açılımıdır, kullanılır).
     - C) $a_{22}A_{11} + a_{21}A_{21} + a_{23}A_{31}$ ($a_{22}=a_{11}$ ve $a_{23}=a_{31}$ olduğundan 1. sütun açılımıdır, kullanılır).
     - E) $a_{23}A_{31} + a_{32}A_{32} + a_{33}A_{33}$ ($a_{23}=a_{31}$ olduğundan 3. satır açılımıdır, kullanılır).
     - D) $a_{11}A_{11} + a_{22}A_{22} + a_{33}A_{33}$ esas köşegen boyunca yazılmıştır; Laplace açılımı köşegen boyunca yapılamayacağından D kullanılamaz.
  5. **Soru 5 — Değişmeli Hermityen ve Ters Hermityen Matrisler (ekrandan, 01:24:45):**
     $AB = BA$ (değişmeli), $A$ Hermityen ($(\overline{A})^T = A$) ve $B$ ters Hermityen ($(\overline{B})^T = -B$) ise $AB + B$ matrisinin eşlenik transpozu:
     $$(\overline{AB + B})^T = (\overline{B})^T(\overline{A})^T + (\overline{B})^T = (-B)(A) - B = -BA - B = -AB - B = -(AB + B)$$
     olduğundan $AB + B$ **ters Hermityendir** (skew-Hermitian).
  6. **Soru 6 — Her Zaman Doğru Olan Determinant ve Matris Önermeleri (ekrandan, 01:28:55):**
     - I. $\det(A B^T A^{-1}) = \det(A)\det(B^T)\det(A^{-1}) = \det(A)\det(B)\frac{1}{\det(A)} = \det(B)$ (Her zaman doğru).
     - II. $\det(A + B) = \det(A) + \det(B)$ (Genel olarak yanlış).
     - III. Her $A$ kare matrisi için $A \cdot \text{adj}(A)$ bir köşegen matristir: $A \cdot \text{adj}(A) = \det(A) I_n$ bir skaler matristir ve her skaler matris aynı zamanda bir köşegen matris olduğundan her zaman doğrudur.
     - IV. İki tekil olmayan matrisin toplamı tekildir (Her zaman doğru değildir; toplam tekil de olabilir, tekil olmayan da olabilir).
     Dolayısıyla yalnız **I ve III** her zaman doğrudur.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
