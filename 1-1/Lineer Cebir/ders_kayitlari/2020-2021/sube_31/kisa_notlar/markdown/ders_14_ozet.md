# Ders 14 Çalışma Özeti

## Genel Konular

- Baz Değişimi, Koordinat Vektörleri ve Geçiş Matrisleri (Change of Basis, Coordinate Vectors & Transition Matrices)
  - $n$-boyutlu bir $V$ vektör uzayında $\mathcal{B}_1 = \{\vec{v}_1, \vec{v}_2, \dots, \vec{v}_n\}$ ve $\mathcal{B}_2 = \{\vec{w}_1, \vec{w}_2, \dots, \vec{w}_n\}$ iki sıralı baz (ordered bases) olsun. $\mathcal{B}_1$ bazındaki her bir $\vec{v}_j$ vektörü, $\mathcal{B}_2$ bazındaki vektörlerin tek bir doğrusal birleşimi olarak yazılabilir (ekrandan, 00:08:30):
    $$\vec{v}_j = a_{1j}\vec{w}_1 + a_{2j}\vec{w}_2 + \dots + a_{nj}\vec{w}_n \implies [\vec{v}_j]_{\mathcal{B}_2} = \begin{bmatrix} a_{1j} \\ a_{2j} \\ \vdots \\ a_{nj} \end{bmatrix}$$
  - Bu $[\vec{v}_1]_{\mathcal{B}_2}, [\vec{v}_2]_{\mathcal{B}_2}, \dots, [\vec{v}_n]_{\mathcal{B}_2}$ koordinat vektörlerinin sırasıyla sütunlara yerleştirilmesiyle elde edilen $n \times n$ boyutlu tekil olmayan (nonsingular) matrise **$\mathcal{B}_1$ bazından $\mathcal{B}_2$ bazına geçiş matrisi** (transition matrix / coordinates transformation matrix from basis $\mathcal{B}_1$ to $\mathcal{B}_2$) denir ve $[M]_{\mathcal{B}_1}^{\mathcal{B}_2}$ veya $P_{\mathcal{B}_1 \to \mathcal{B}_2}$ ile gösterilir.
  - **Teorem (Geçiş Matrisi ve Koordinat Dönüşümü Bağıntıları — ekrandan, 00:09:40):**
    1. $\mathcal{B}_2$'den $\mathcal{B}_1$'e geçiş matrisi, $\mathcal{B}_1$'den $\mathcal{B}_2$'ye geçiş matrisinin tersidir:
       $$\left([M]_{\mathcal{B}_1}^{\mathcal{B}_2}\right) \left([M]_{\mathcal{B}_2}^{\mathcal{B}_1}\right) = I_n \implies [M]_{\mathcal{B}_2}^{\mathcal{B}_1} = \left([M]_{\mathcal{B}_1}^{\mathcal{B}_2}\right)^{-1}$$
    2. Her $\vec{u}, \vec{v} \in V$ vektörü için koordinat dönüşüm formülleri:
       $$[\vec{u}]_{\mathcal{B}_1} = [M]_{\mathcal{B}_2}^{\mathcal{B}_1} [\vec{u}]_{\mathcal{B}_2} \quad \text{ve} \quad [\vec{v}]_{\mathcal{B}_2} = [M]_{\mathcal{B}_1}^{\mathcal{B}_2} [\vec{v}]_{\mathcal{B}_1}$$
  - Pratik hesaplamada üç sistemi ayrı ayrı çözmek yerine $[\vec{w}_1 \;\; \vec{w}_2 \;\; \vec{w}_3 \mid \vec{v}_1 \;\; \vec{v}_2 \;\; \vec{v}_3]$ matrisi elementer satır işlemleriyle $[I_3 \mid [M]_{\mathcal{B}_1}^{\mathcal{B}_2}]$ (RREF) biçimine indirgenerek geçiş matrisi tek seferde bulunur (ekrandan, 00:22:30).
- Özdeğerler, Özvektörler ve Karakteristik Polinom (Eigenvalues, Eigenvectors & Characteristic Polynomial)
  - $A$, $n \times n$ boyutlu bir kare matris olsun. Eğer $A\vec{x} = \lambda \vec{x}$ denklemini sağlayan **sıfırdan farklı** (nontrivial / $\vec{x} \neq \vec{0}$) bir $\vec{x}$ vektörü varsa, $\lambda$ skalerine $A$ matrisinin bir **özdeğeri** (eigenvalue / characteristic value), bu $\vec{x} \neq \vec{0}$ vektörüne ise $\lambda$ özdeğerine karşılık gelen bir **özvektör** (eigenvector corresponding to / associated with $\lambda$) denir (ekrandan, 00:39:00).
  - **Teorem (Tersinirlik ve Sıfır Özdeğeri):** Bir özvektör asla sıfır vektörü ($\vec{0}$) olamaz; ancak bir matrisin özdeğeri $\lambda = 0 \in \mathbb{R}$ olabilir. $n \times n$ boyutlu bir $A$ kare matrisinin **tersinir (invertible / nonsingular)** olması için gerek ve yeter şart **$0$'ın $A$ matrisinin bir özdeğeri olmamasıdır** ($\lambda = 0$ özdeğeri varsa $A$ tekildir / tersinir değildir) (ekrandan, 00:39:00).
  - **Karakteristik Denklem ve Polinom (ekrandan, 00:56:00):**
    $$A\vec{x} = \lambda \vec{x} \iff (A - \lambda I_n)\vec{x} = \vec{0}$$
    homojen sisteminin sıfırdan farklı ($\vec{x} \neq \vec{0}$) çözüme sahip olması için gerek ve yeter şart katsayılar matrisinin determinantının sıfır olmasıdır:
    $$\det(A - \lambda I_n) = 0$$
    Bu denkleme $A$'nın **karakteristik denklemi** (characteristic equation), $P_A(\lambda) = \det(A - \lambda I_n) = (-1)^n \lambda^n + (-1)^{n-1}\text{Tr}(A)\lambda^{n-1} + \dots + \det(A)$ polinomuna ise **karakteristik polinomu** (characteristic polynomial) denir. Özel olarak $2 \times 2$ boyutlu bir $A$ matrisi için:
    $$P_A(\lambda) = \lambda^2 - \text{Tr}(A)\lambda + \det(A)$$
- Üçgensel Matrislerin Özdeğerleri ve Cayley-Hamilton Teoremi (Triangular Matrices & Cayley-Hamilton Theorem)
  - Bir **üçgensel matrisin** (triangular matrix — alt veya üst üçgensel ya da köşegen matrisin) özdeğerleri, doğrudan **esas köşegeni (main diagonal) üzerindeki elemanlardır** (ekrandan, 00:59:45).
  - **Cayley-Hamilton Teoremi (ekrandan, 01:23:45):** Her $A$ kare matrisi kendi karakteristik denklemini sağlar (kendi karakteristik polinomunun bir köküdür):
    $$P_A(A) = A^n + a_{n-1}A^{n-1} + \dots + a_1 A + a_0 I_n = O_{n \times n}$$
  - Cayley-Hamilton teoremi kullanılarak tersinir bir matrisin tersi ($a_0 \neq 0$ için $A^{-1} = -\frac{1}{a_0}(A^{n-1} + a_{n-1}A^{n-2} + \dots + a_1 I_n)$) ve bir matrisin yüksek kuvvetleri ($A^3, A^4, A^5, \dots$) çok kolay hesaplanır (ekrandan, 01:23:45 ve 01:36:30).

## Hocanın Özellikle Vurguladığı Kısımlar

- Baz Vektörleri Açıkça Verilmeden Doğrusal Bağıntı Üzerinden Geçiş Matrisi Bulma
  - Sınavda çıkma olasılığı çok yüksek olan soru tipinde $\mathcal{B}_1 = \{\vec{v}_1, \vec{v}_2, \vec{v}_3\}$ ve $\mathcal{B}_2 = \{\vec{w}_1, \vec{w}_2, \vec{w}_3\}$ bazlarının vektör koordinatları verilmez; yalnızca $\vec{v}_1, \vec{v}_2, \vec{v}_3$ vektörlerinin $\vec{w}_1, \vec{w}_2, \vec{w}_3$ cinsinden eşitlikleri verilir. Tanım gereği $\vec{v}_j$ vektörünün $\mathcal{B}_2$ bazındaki katsayıları $[M]_{\mathcal{B}_1}^{\mathcal{B}_2}$ geçiş matrisinin $j$. sütununu oluşturduğundan, hiçbir denklem çözmeden katsayılar doğrudan sütunlara yazılarak $[M]_{\mathcal{B}_1}^{\mathcal{B}_2}$ elde edilir; tersi alınarak $[M]_{\mathcal{B}_2}^{\mathcal{B}_1}$ bulunur (ekrandan, 00:28:00 ve 00:32:30).
- Özvektörün Sıfır Vektörü Olamaması ve Çoktan Seçmeli Sınavlarda Parametre Seçimi
  - Özvektör tanım gereği sıfırdan farklı ($\vec{x} \neq \vec{0}$) bir vektördür. Bir $\lambda$ özdeğerine karşılık gelen özvektörler $(A - \lambda I_n)\vec{x} = \vec{0}$ homojen sisteminin sonsuz çözüm ailesi olarak (örneğin $r \in \mathbb{R} \setminus \{0\}$ parametresine bağlı $\vec{x} = r(1, 1)^T$ veya $\vec{x} = (-r/2, \, r/2, \, r)^T$ biçiminde) bulunur. Sınav şıklarında $r = 1$ veya kesirleri yok etmek için $r = 2$ seçilerek elde edilen özel bir özvektör (örneğin $(1, 1)^T$, $(2, 2)^T$ veya $(-1, 1, 2)^T$) yer alır (ekrandan, 00:48:35 ve 01:16:30).
- $2 \times 2$ Matrisin Karakteristik Polinomu İçin İz ve Determinant Kısayolu
  - $2 \times 2$ boyutlu bir $A$ kare matrisinin karakteristik polinomu her zaman $P_A(\lambda) = \lambda^2 - \text{Tr}(A)\lambda + \det(A)$ formundadır; burada $\text{Tr}(A)$ esas köşegen elemanlarının toplamıdır (ekrandan, 00:56:00).
- Cayley-Hamilton Teoreminde Sabit Terimin Yanına Birim Matris ($I_n$) Yazılması
  - Karakteristik polinom $P_A(\lambda) = \lambda^2 - 4\lambda - 5 = 0$ denkleminde $\lambda$ yerine $A$ matrisi yazılırken sabit sayının ($-5$) yanına mutlaka **$I_n$ birim matrisi** konularak $A^2 - 4A - 5I_2 = O$ yazılmalıdır; çünkü bir matrisle bir skaler doğrudan toplanıp çıkarılamaz. Ayrıca $A^k$ kuvvetleri hesaplanırken iki taraf $A$ ile çarpıldığında $cI_2$ teriminin $cA$'ya dönüştüğüne dikkat edilmelidir (ekrandan, 01:29:15 ve 01:36:30).

## Kısa Tekrar Notları

- Geçiş matrisi $[M]_{\mathcal{B}_1}^{\mathcal{B}_2} = \big[ [\vec{v}_1]_{\mathcal{B}_2} \;\; [\vec{v}_2]_{\mathcal{B}_2} \;\; \dots \;\; [\vec{v}_n]_{\mathcal{B}_2} \big]$ ve $[M]_{\mathcal{B}_2}^{\mathcal{B}_1} = \left([M]_{\mathcal{B}_1}^{\mathcal{B}_2}\right)^{-1}$.
- Koordinat dönüşümü: $[\vec{u}]_{\mathcal{B}_2} = [M]_{\mathcal{B}_1}^{\mathcal{B}_2}[\vec{u}]_{\mathcal{B}_1}$ ve $[\vec{u}]_{\mathcal{B}_1} = [M]_{\mathcal{B}_2}^{\mathcal{B}_1}[\vec{u}]_{\mathcal{B}_2}$.
- Özdeğer ve özvektör: $A\vec{x} = \lambda \vec{x}$ ($\vec{x} \neq \vec{0}$). Karakteristik denklem: $\det(A - \lambda I_n) = 0$.
- $A$ tersinirdir $\iff \det(A) \neq 0 \iff \lambda = 0$, $A$'nın özdeğeri değildir.
- $2 \times 2$ matriste karakteristik polinom: $P_A(\lambda) = \lambda^2 - \text{Tr}(A)\lambda + \det(A)$.
- Üçgensel matriste özdeğerler: esas köşegen elemanları ($\lambda_i = a_{ii}$).
- Cayley-Hamilton teoremi: $P_A(A) = O_{n \times n}$.

## Detaylı Açıklamalar

- **Baz Değişimi ve Geçiş Matrisi Örnekleri (ekrandan, 00:11:30, 00:22:30, 00:28:00 ve 00:32:30):**
  1. **Örnek 1 ($\mathbb{R}^3$'te İki Baz Arasında Geçiş Matrisi — ekrandan, 00:11:30 ve 00:22:30):**
     $\mathcal{B}_1 = \{\vec{v}_1 = (1, 2, 0), \, \vec{v}_2 = (2, 0, 1), \, \vec{v}_3 = (1, 2, 1)\}$ ve $\mathcal{B}_2 = \{\vec{w}_1 = (0, 2, 1), \, \vec{w}_2 = (-1, 0, 1), \, \vec{w}_3 = (-1, 3, 0)\}$ bazları ve $\vec{u} = (2, 3, 5)$ vektörü için $[\vec{w}_1 \;\; \vec{w}_2 \;\; \vec{w}_3 \mid \vec{v}_1 \;\; \vec{v}_2 \;\; \vec{v}_3]$ matrisi RREF formuna indirgendiğinde:
     $$\begin{bmatrix} 0 & -1 & -1 & \mid & 1 & 2 & 1 \\ 2 & 0 & 3 & \mid & 2 & 0 & 2 \\ 1 & 1 & 0 & \mid & 0 & 1 & 1 \end{bmatrix} \sim \begin{bmatrix} 1 & 0 & 0 & \mid & 1 & 9/5 & 8/5 \\ 0 & 1 & 0 & \mid & -1 & -4/5 & -3/5 \\ 0 & 0 & 1 & \mid & 0 & -6/5 & -2/5 \end{bmatrix} \implies [M]_{\mathcal{B}_1}^{\mathcal{B}_2} = \begin{bmatrix} 1 & 9/5 & 8/5 \\ -1 & -4/5 & -3/5 \\ 0 & -6/5 & -2/5 \end{bmatrix}$$
     (Not: Hoca tahtada $4 - 12/5 = 8/5$ işlemini yaparken 1. satır 3. sütuna sehven $-8/5$ yazmıştır, doğrusu $8/5$'tir). Ayrıca $\vec{u} = (2, 3, 5)$ için $[\vec{u}]_{\mathcal{B}_1} = (-3, 0, 5)^T$ ve $[\vec{u}]_{\mathcal{B}_2} = [M]_{\mathcal{B}_1}^{\mathcal{B}_2}[\vec{u}]_{\mathcal{B}_1} = (5, -11/5, -2)^T$ bulunur.
  2. **Örnek 2 (Bağıntıları Verilen İki Baz Arasında Geçiş Matrisi — ekrandan, 00:28:00 ve 00:32:30):**
     $\mathcal{B}_1 = \{\vec{v}_1, \vec{v}_2, \vec{v}_3\}$ ve $\mathcal{B}_2 = \{\vec{w}_1, \vec{w}_2, \vec{w}_3\}$ sıralı bazları arasında:
     $$\begin{cases} \vec{v}_1 = \vec{w}_1 + \vec{w}_2 - \vec{w}_3 \\ \vec{v}_2 = 2\vec{w}_1 - \vec{w}_2 + \vec{w}_3 \\ \vec{v}_3 = \vec{w}_1 + 2\vec{w}_3 \end{cases}$$
     bağıntıları veriliyor. $[\vec{u}]_{\mathcal{B}_1} = (1, 0, 3)^T$ olduğuna göre $[M]_{\mathcal{B}_1}^{\mathcal{B}_2}$ geçiş matrisini ve $[\vec{u}]_{\mathcal{B}_2}$ koordinat vektörünü bulunuz.
     - Katsayılar doğrudan sütunlara yazılarak:
       $$[M]_{\mathcal{B}_1}^{\mathcal{B}_2} = \begin{pmatrix} 1 & 2 & 1 \\ 1 & -1 & 0 \\ -1 & 1 & 2 \end{pmatrix}$$
     - Koordinat dönüşüm formülünden:
       $$[\vec{u}]_{\mathcal{B}_2} = [M]_{\mathcal{B}_1}^{\mathcal{B}_2} [\vec{u}]_{\mathcal{B}_1} = \begin{pmatrix} 1 & 2 & 1 \\ 1 & -1 & 0 \\ -1 & 1 & 2 \end{pmatrix} \begin{pmatrix} 1 \\ 0 \\ 3 \end{pmatrix} = \begin{pmatrix} 4 \\ 1 \\ 5 \end{pmatrix}$$

- **$2 \times 2$ ve $3 \times 3$ Matrislerde Özdeğer ve Özvektör Hesabı (ekrandan, 00:45:30, 01:02:00, 01:10:30, 01:16:30 ve 01:19:30):**
  1. **$2 \times 2$ Matris Örneği ($A = \begin{bmatrix} 1 & 1 \\ -2 & 4 \end{bmatrix}$ — ekrandan, 00:45:30 ve 00:52:30):**
     - Karakteristik denklem:
       $$\det(A - \lambda I_2) = \begin{vmatrix} 1 - \lambda & 1 \\ -2 & 4 - \lambda \end{vmatrix} = (1 - \lambda)(4 - \lambda) + 2 = \lambda^2 - 5\lambda + 6 = (\lambda - 2)(\lambda - 3) = 0$$
       Özdeğerler: $\lambda_1 = 2$ ve $\lambda_2 = 3$.
     - $\lambda_1 = 2$ için özvektörler: $(A - 2I_2)\vec{x} = \vec{0} \implies -x_1 + x_2 = 0 \implies x_1 = x_2 = r \implies \vec{x}_1 = \begin{bmatrix} r \\ r \end{bmatrix} = r\begin{bmatrix} 1 \\ 1 \end{bmatrix}$ ($r \in \mathbb{R} \setminus \{0\}$).
     - $\lambda_2 = 3$ için özvektörler: $(A - 3I_2)\vec{x} = \vec{0} \implies -2x_1 + x_2 = 0 \implies x_1 = \frac{1}{2}x_2$. $x_2 = r$ alınırsa $\vec{x}_2 = \begin{bmatrix} r/2 \\ r \end{bmatrix}$ (veya $r = 2$ için $\begin{bmatrix} 1 \\ 2 \end{bmatrix}$).
  2. **$3 \times 3$ Matris Örneği ($A = \begin{bmatrix} 1 & 2 & -1 \\ 1 & 0 & 1 \\ 4 & -4 & 5 \end{bmatrix}$ — ekrandan, 01:02:00, 01:10:30 ve 01:16:30):**
     - Karakteristik denklem:
       $$\det(A - \lambda I_3) = \begin{vmatrix} 1-\lambda & 2 & -1 \\ 1 & -\lambda & 1 \\ 4 & -4 & 5-\lambda \end{vmatrix} = -\lambda^3 + 6\lambda^2 - 11\lambda + 6 = 0 \iff \lambda^3 - 6\lambda^2 + 11\lambda - 6 = 0$$
     - Sabit terim $-6$'nın çarpanlarından $\lambda_1 = 1$ denendiğinde $1 - 6 + 11 - 6 = 0$ sağlandığından $\lambda_1 = 1$ bir köktür. Polinom $\lambda - 1$'e bölündüğünde:
       $$\lambda^3 - 6\lambda^2 + 11\lambda - 6 = (\lambda - 1)(\lambda^2 - 5\lambda + 6) = (\lambda - 1)(\lambda - 2)(\lambda - 3) = 0$$
       bulunur; özdeğerler $\lambda_1 = 1, \, \lambda_2 = 2, \, \lambda_3 = 3$'tür.
     - $\lambda_1 = 1$ için özvektör: $(A - I_3)\vec{x} = \vec{0}$ sisteminden $\begin{cases} 2x_2 - x_3 = 0 \\ x_1 - x_2 + x_3 = 0 \\ 4x_1 - 4x_2 + 4x_3 = 0 \end{cases} \implies x_2 = \frac{1}{2}x_3$ ve $x_1 = x_2 - x_3 = -\frac{1}{2}x_3$. $x_3 = r$ için $\vec{x}_1 = \begin{bmatrix} -r/2 \\ r/2 \\ r \end{bmatrix}$ (veya $r = 2$ için $\vec{x}_1 = \begin{bmatrix} -1 \\ 1 \\ 2 \end{bmatrix}$) bulunur.
  3. **Üst Üçgensel $3 \times 3$ Matris Örneği ($A = \begin{pmatrix} 3 & 6 & -8 \\ 0 & 0 & 6 \\ 0 & 0 & 2 \end{pmatrix}$ — ekrandan, 01:10:30 ve 01:19:30):**
     $A$ bir üst üçgensel matris olduğundan özdeğerleri doğrudan esas köşegen üzerindeki elemanlardır: $\lambda_1 = 3, \, \lambda_2 = 0, \, \lambda_3 = 2$. Karakteristik polinomu $P_A(\lambda) = (3 - \lambda)(-\lambda)(2 - \lambda) = -\lambda(\lambda - 3)(\lambda - 2)$'dir.

- **Cayley-Hamilton Teoremi ile $A^{-1}$ ve $A^5$ Hesabı Örneği (ekrandan, 01:25:00, 01:28:15 ve 01:36:30):**
  $A = \begin{pmatrix} 1 & 4 \\ 2 & 3 \end{pmatrix}$ matrisi için karakteristik polinomu, özdeğerleri, özvektörleri ve Cayley-Hamilton teoremini kullanarak $A^{-1}$ ile $A^5$ matrislerini bulunuz.
  1. **Karakteristik Polinom, Özdeğerler ve Özvektör:**
     $$P_A(\lambda) = \begin{vmatrix} 1-\lambda & 4 \\ 2 & 3-\lambda \end{vmatrix} = (1-\lambda)(3-\lambda) - 8 = \lambda^2 - 4\lambda - 5 = (\lambda - 5)(\lambda + 1) = 0$$
     Özdeğerler: $\lambda_1 = -1$ ve $\lambda_2 = 5$.
     $\lambda_1 = -1$ için $(A + I_2)\vec{x} = \begin{pmatrix} 2 & 4 \\ 2 & 4 \end{pmatrix}\begin{pmatrix} x_1 \\ x_2 \end{pmatrix} = \begin{pmatrix} 0 \\ 0 \end{pmatrix} \implies 2x_1 + 4x_2 = 0 \implies x_1 = -2x_2$. $x_2 = r$ için $\vec{x}_1 = \begin{pmatrix} -2r \\ r \end{pmatrix} = r\begin{pmatrix} -2 \\ 1 \end{pmatrix}$.
  2. **Cayley-Hamilton Teoremi ile $A^{-1}$ Hesabı:**
     $P_A(A) = A^2 - 4A - 5I_2 = O \implies A^2 - 4A = 5I_2$. Her iki taraf $A^{-1}$ ile çarpılırsa:
     $$5A^{-1} = A - 4I_2 = \begin{pmatrix} 1 & 4 \\ 2 & 3 \end{pmatrix} - \begin{pmatrix} 4 & 0 \\ 0 & 4 \end{pmatrix} = \begin{pmatrix} -3 & 4 \\ 2 & -1 \end{pmatrix} \implies A^{-1} = \begin{pmatrix} -3/5 & 4/5 \\ 2/5 & -1/5 \end{pmatrix}$$
  3. **Cayley-Hamilton Teoremi ile $A^5$ Hesabı:**
     $A^2 = 4A + 5I_2$ bağıntısını ardışık olarak $A$ ile çarpıp her adımda $A^2$ yerine $4A + 5I_2$ yazalım:
     - $A^3 = 4A^2 + 5A = 4(4A + 5I_2) + 5A = 21A + 20I_2$
     - $A^4 = 21A^2 + 20A = 21(4A + 5I_2) + 20A = 104A + 105I_2$
     - $A^5 = 104A^2 + 105A = 104(4A + 5I_2) + 105A = 416A + 520I_2 + 105A = 521A + 520I_2$

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
