# Ders 14 Genişletilmiş Notu: Baz Değişimi ve Geçiş Matrisleri, Özdeğerler ve Özvektörler, Karakteristik Polinom ve Cayley-Hamilton Teoremi

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Baz Değişimi, Koordinat Vektörleri ve Geçiş Matrisleri (Change of Basis and Coordinate Transformations)
  - 1.1 Koordinat Vektörü ve Geçiş Matrisi (Transition Matrix) Tanımı
  - 1.2 Geçiş Matrisinin Tersinirliği ve Koordinat Dönüşüm Teoremi
  - 1.3 $\mathbb{R}^3$ Uzayında İki Sıralı Baz Arasında Geçiş Matrisi ve Koordinat Dönüşümü Örneği
  - 1.4 Baz Vektörleri Arasındaki Doğrusal Bağıntıdan Geçiş Matrisi ve Koordinat Vektörü Bulma Örneği
- 2. Özdeğerler ve Özvektörler (Eigenvalues and Eigenvectors)
  - 2.1 Özdeğer ve Özvektör Tanımı
  - 2.2 Sıfır Özdeğeri ile Matrisin Tersinirliği Arasındaki İlişki
  - 2.3 $2 \times 2$ Matris İçin Tanımdan Özdeğer ve Özvektör Bulma Örneği
- 3. Karakteristik Denklem, Karakteristik Polinom ve Özdeğer/Özvektör Bulma Algoritması
  - 3.1 Karakteristik Denklem ($\det(A - \lambda I_n) = 0$) ve $2 \times 2$ Matris İçin İz-Determinant Formülü
  - 3.2 Özdeğer ve Özvektör Bulma Adımları, Katlı Özdeğerler ve Üçgensel Matrisler
  - 3.3 $3 \times 3$ Matrisin Karakteristik Polinomunun Polinom Bölmesiyle Çarpanlarına Ayrılması ve Özvektör Hesabı
  - 3.4 Üst Üçgensel $3 \times 3$ Matrisin Özdeğerleri ve Karakteristik Polinomu
- 4. Cayley-Hamilton Teoremi ve Uygulamaları (Cayley-Hamilton Theorem)
  - 4.1 Cayley-Hamilton Teoremi ve Matrisin Tersini / Kuvvetlerini Hesaplama Formülleri
  - 4.2 Cayley-Hamilton Teoremi ile $A^{-1}$ ve $A^5$ Hesabı Örneği
- Örnek Sorular
- Dersin Toparlaması

## 1. Baz Değişimi, Koordinat Vektörleri ve Geçiş Matrisleri (Change of Basis and Coordinate Transformations)

Hoca dönemin bu son dersine, cumartesi günü yapılan ek derste işlenen **geçiş matrisleri** (transition matrices) ve **koordinat vektörleri** (coordinate vectors) konusunun kısa bir özeti ve iki kapsamlı örneğiyle başladı.

### 1.1 Koordinat Vektörü ve Geçiş Matrisi (Transition Matrix) Tanımı

$n$-boyutlu bir $V$ vektör uzayında ($n$-space):
$$\mathcal{B}_1 = \{\vec{v}_1, \vec{v}_2, \dots, \vec{v}_n\} \quad \text{ve} \quad \mathcal{B}_2 = \{\vec{w}_1, \vec{w}_2, \dots, \vec{w}_n\}$$
gibi iki **sıralı baz** (ordered bases) verilsin (ekrandan, 00:08:30). $\mathcal{B}_1$ ve $\mathcal{B}_2$ birer baz olduğundan, $V$ vektör uzayındaki herhangi bir $\vec{v} \in V$ vektörü baz vektörlerinin **tek bir (unique) doğrusal birleşimi** olarak yazılabilir.

Özel olarak, birinci baz $\mathcal{B}_1$'in elemanları olan $\vec{v}_1, \vec{v}_2, \dots, \vec{v}_n$ vektörleri de $V$ vektör uzayının elemanları olduğundan, her bir $\vec{v}_j$ vektörünü ikinci baz $\mathcal{B}_2$'deki $\vec{w}_1, \vec{w}_2, \dots, \vec{w}_n$ vektörlerinin tek bir doğrusal birleşimi olarak yazabiliriz:
$$\begin{aligned}
\vec{v}_1 &= a_{11}\vec{w}_1 + a_{21}\vec{w}_2 + \dots + a_{n1}\vec{w}_n \\
\vec{v}_2 &= a_{12}\vec{w}_1 + a_{22}\vec{w}_2 + \dots + a_{n2}\vec{w}_n \\
&\;\;\vdots \\
\vec{v}_n &= a_{1n}\vec{w}_1 + a_{2n}\vec{w}_2 + \dots + a_{nn}\vec{w}_n
\end{aligned}$$

- **Koordinat Vektörü:** Yukarıdaki ilk denklemdeki katsayılardan oluşan sütun vektörüne, $\vec{v}_1$ vektörünün $\mathcal{B}_2$ bazına göre **koordinat vektörü** (coordinate vector of $\vec{v}_1$ with respect to the basis $\mathcal{B}_2$) denir ve $[\vec{v}_1]_{\mathcal{B}_2}$ ile gösterilir:
  $$[\vec{v}_1]_{\mathcal{B}_2} = \begin{bmatrix} a_{11} \\ a_{21} \\ \vdots \\ a_{n1} \end{bmatrix}, \quad [\vec{v}_2]_{\mathcal{B}_2} = \begin{bmatrix} a_{12} \\ a_{22} \\ \vdots \\ a_{n2} \end{bmatrix}, \quad \dots, \quad [\vec{v}_n]_{\mathcal{B}_2} = \begin{bmatrix} a_{1n} \\ a_{2n} \\ \vdots \\ a_{nn} \end{bmatrix}$$
- **Geçiş Matrisi (Transition Matrix):** Bu $[\vec{v}_1]_{\mathcal{B}_2}, [\vec{v}_2]_{\mathcal{B}_2}, \dots, [\vec{v}_n]_{\mathcal{B}_2}$ koordinat vektörlerini sırasıyla 1. sütuna, 2. sütuna, ..., $n$. sütuna yazarak oluşturduğumuz $n \times n$ boyutlu matrise **$\mathcal{B}_1$ bazından $\mathcal{B}_2$ bazına geçiş matrisi** (transition matrix / coordinates transformation matrix from basis $\mathcal{B}_1$ to basis $\mathcal{B}_2$) denir ve $[M]_{\mathcal{B}_1}^{\mathcal{B}_2}$ veya $P_{\mathcal{B}_1 \to \mathcal{B}_2}$ ile gösterilir:
  $$[M]_{\mathcal{B}_1}^{\mathcal{B}_2} = \begin{bmatrix} a_{11} & a_{12} & \dots & a_{1n} \\ a_{21} & a_{22} & \dots & a_{2n} \\ \vdots & \vdots & \ddots & \vdots \\ a_{n1} & a_{n2} & \dots & a_{nn} \end{bmatrix} = \Big[ [\vec{v}_1]_{\mathcal{B}_2} \;\; [\vec{v}_2]_{\mathcal{B}_2} \;\; \dots \;\; [\vec{v}_n]_{\mathcal{B}_2} \Big]$$

### 1.2 Geçiş Matrisinin Tersinirliği ve Koordinat Dönüşüm Teoremi

- **Teorem (ekrandan, 00:09:40):** $V$, $\mathcal{B}_1 = \{\vec{v}_1, \dots, \vec{v}_n\}$ ve $\mathcal{B}_2 = \{\vec{w}_1, \dots, \vec{w}_n\}$ sıralı bazlarına sahip $n$-boyutlu bir vektör uzayı olsun. $A = [M]_{\mathcal{B}_1}^{\mathcal{B}_2}$ ($\mathcal{B}_1$'den $\mathcal{B}_2$'ye geçiş matrisi) ve $B = [M]_{\mathcal{B}_2}^{\mathcal{B}_1}$ ($\mathcal{B}_2$'den $\mathcal{B}_1$'e geçiş matrisi) olmak üzere aşağıdaki iki temel özellik sağlanır:
  1. **Tersinirlik Özelliği:** Her geçiş matrisi tekil olmayan (nonsingular / tersinir) bir matristir ve bir geçiş matrisinin tersi, ters yöndeki geçiş matrisine eşittir:
     $$AB = I_n \quad \text{veya} \quad B = A^{-1}, \quad \text{yani} \quad \left([M]_{\mathcal{B}_1}^{\mathcal{B}_2}\right) \left([M]_{\mathcal{B}_2}^{\mathcal{B}_1}\right) = I_n \iff [M]_{\mathcal{B}_2}^{\mathcal{B}_1} = \left([M]_{\mathcal{B}_1}^{\mathcal{B}_2}\right)^{-1}$$
  2. **Koordinat Dönüşüm Formülleri:** $V$ uzayındaki tüm $\vec{u}, \vec{v} \in V$ vektörleri için:
     $$[\vec{u}]_{\mathcal{B}_1} = [M]_{\mathcal{B}_2}^{\mathcal{B}_1} [\vec{u}]_{\mathcal{B}_2} \quad \text{ve} \quad [\vec{v}]_{\mathcal{B}_2} = [M]_{\mathcal{B}_1}^{\mathcal{B}_2} [\vec{v}]_{\mathcal{B}_1}$$

### 1.3 $\mathbb{R}^3$ Uzayında İki Sıralı Baz Arasında Geçiş Matrisi ve Koordinat Dönüşümü Örneği

- **Verilen (ekrandan, 00:11:30, 00:22:30 ve 00:26:30):**
  $\mathbb{R}^3$ vektör uzayında:
  $$\mathcal{B}_1 = \{\vec{v}_1 = (1, 2, 0), \, \vec{v}_2 = (2, 0, 1), \, \vec{v}_3 = (1, 2, 1)\}$$
  $$\mathcal{B}_2 = \{\vec{w}_1 = (0, 2, 1), \, \vec{w}_2 = (-1, 0, 1), \, \vec{w}_3 = (-1, 3, 0)\}$$
  iki sıralı baz ve $\vec{u} = (2, 3, 5)$ standart baza göre koordinatları verilen bir vektör olsun.
  1. $A = [M]_{\mathcal{B}_1}^{\mathcal{B}_2}$ ($\mathcal{B}_1$'den $\mathcal{B}_2$'ye geçiş matrisini),
  2. $B = [M]_{\mathcal{B}_2}^{\mathcal{B}_1}$ ($\mathcal{B}_2$'den $\mathcal{B}_1$'e geçiş matrisini),
  3. $[\vec{u}]_{\mathcal{B}_1}$ ve $[\vec{u}]_{\mathcal{B}_2}$ koordinat vektörlerini bulunuz ve $[\vec{u}]_{\mathcal{B}_1} = [M]_{\mathcal{B}_2}^{\mathcal{B}_1} [\vec{u}]_{\mathcal{B}_2}$ bağıntısını doğrulayınız.

- **Adım Adım Çözüm:**
  1. **$A = [M]_{\mathcal{B}_1}^{\mathcal{B}_2}$ Geçiş Matrisinin Bulunması (ekrandan, 00:14:15–00:23:35):**
     $\mathcal{B}_1$'deki $\vec{v}_1, \vec{v}_2, \vec{v}_3$ vektörlerini $\mathcal{B}_2$'deki $\vec{w}_1, \vec{w}_2, \vec{w}_3$ vektörlerinin doğrusal birleşimi olarak yazmamız gerekir:
     $$\vec{v}_1 = a_{11}\vec{w}_1 + a_{21}\vec{w}_2 + a_{31}\vec{w}_3, \quad \vec{v}_2 = a_{12}\vec{w}_1 + a_{22}\vec{w}_2 + a_{32}\vec{w}_3, \quad \vec{v}_3 = a_{13}\vec{w}_1 + a_{23}\vec{w}_2 + a_{33}\vec{w}_3$$
     Bu üç doğrusal denklem sisteminin katsayılar matrisi aynı ($\vec{w}_1, \vec{w}_2, \vec{w}_3$ sütunlarından oluşan matris) olduğu için, üç sistemi ayrı ayrı çözmek yerine sol tarafa $\vec{w}_1, \vec{w}_2, \vec{w}_3$ sütunlarını, sağ tarafa ise $\vec{v}_1, \vec{v}_2, \vec{v}_3$ sütunlarını yazarak $3 \times 6$ boyutlu birleştirilmiş genişletilmiş matrisi kurarız:
     $$\big[ \vec{w}_1 \;\; \vec{w}_2 \;\; \vec{w}_3 \;\big|\; \vec{v}_1 \;\; \vec{v}_2 \;\; \vec{v}_3 \big] = \begin{bmatrix} 0 & -1 & -1 & \mid & 1 & 2 & 1 \\ 2 & 0 & 3 & \mid & 2 & 0 & 2 \\ 1 & 1 & 0 & \mid & 0 & 1 & 1 \end{bmatrix}$$
     Elementer satır işlemleriyle sol taraftaki $3 \times 3$ bloğu $I_3$ birim matrisine (yani matrisi RREF formuna) dönüştürelim:
     - İlk olarak sol üst köşede öncü $1$ (leading 1) elde etmek için 1. satır ile 3. satırı yer değiştirelim ($R_1 \leftrightarrow R_3$):
       $$\begin{bmatrix} 1 & 1 & 0 & \mid & 0 & 1 & 1 \\ 2 & 0 & 3 & \mid & 2 & 0 & 2 \\ 0 & -1 & -1 & \mid & 1 & 2 & 1 \end{bmatrix}$$
     - 1. satırı $-2$ ile çarpıp 2. satıra ekleyelim ($-2R_1 + R_2 \to R_2$):
       $$\begin{bmatrix} 1 & 1 & 0 & \mid & 0 & 1 & 1 \\ 0 & -2 & 3 & \mid & 2 & -2 & 0 \\ 0 & -1 & -1 & \mid & 1 & 2 & 1 \end{bmatrix}$$
     - Kesirlerle erken uğraşmamak için 3. satırı $-3$ ile çarpıp 2. satıra ekleyerek $(2, 2)$ elemanını $+1$ yapalım ($-3R_3 + R_2 \to R_2$):
       $$\begin{bmatrix} 1 & 1 & 0 & \mid & 0 & 1 & 1 \\ 0 & 1 & 6 & \mid & -1 & -8 & -3 \\ 0 & -1 & -1 & \mid & 1 & 2 & 1 \end{bmatrix}$$
     - 2. satırı 3. satıra ekleyelim ($R_2 + R_3 \to R_3$) ve 2. satırı $-1$ ile çarpıp 1. satıra ekleyelim ($-R_2 + R_1 \to R_1$):
       $$\begin{bmatrix} 1 & 0 & -6 & \mid & 1 & 9 & 4 \\ 0 & 1 & 6 & \mid & -1 & -8 & -3 \\ 0 & 0 & 5 & \mid & 0 & -6 & -2 \end{bmatrix}$$
     - 3. satırı $\frac{1}{5}$ ile çarpalım ($\frac{1}{5}R_3 \to R_3$):
       $$\begin{bmatrix} 1 & 0 & -6 & \mid & 1 & 9 & 4 \\ 0 & 1 & 6 & \mid & -1 & -8 & -3 \\ 0 & 0 & 1 & \mid & 0 & -6/5 & -2/5 \end{bmatrix}$$
     - Son olarak 3. satırı $-6$ ile çarpıp 2. satıra ekleyelim ($-6R_3 + R_2 \to R_2$) ve 3. satırı $+6$ ile çarpıp 1. satıra ekleyelim ($6R_3 + R_1 \to R_1$):
       $$\begin{bmatrix} 1 & 0 & 0 & \mid & 1 & 9/5 & 8/5 \\ 0 & 1 & 0 & \mid & -1 & -4/5 & -3/5 \\ 0 & 0 & 1 & \mid & 0 & -6/5 & -2/5 \end{bmatrix}$$
       (Not: Hoca tahtada $4 + 6(-2/5) = 4 - 12/5 = 8/5$ işlemini sağ alt köşede yaparken matrisin 1. satır 3. sütununa sehven $-8/5$ yazmıştır; doğru değer $+8/5$'tir).
     Böylece sağ taraftaki $3 \times 3$ blok doğrudan $[M]_{\mathcal{B}_1}^{\mathcal{B}_2}$ geçiş matrisini verir:
     $$A = [M]_{\mathcal{B}_1}^{\mathcal{B}_2} = \begin{bmatrix} 1 & 9/5 & 8/5 \\ -1 & -4/5 & -3/5 \\ 0 & -6/5 & -2/5 \end{bmatrix}$$
     (Aynı sonuç üç sistemi ayrı ayrı çözerek $[\vec{v}_1]_{\mathcal{B}_2} = (1, -1, 0)^T$, $[\vec{v}_2]_{\mathcal{B}_2} = (9/5, -4/5, -6/5)^T$, $[\vec{v}_3]_{\mathcal{B}_2} = (8/5, -3/5, -2/5)^T$ sütunlarını bulup yan yana yazarak da elde edilir).

  2. **Koordinat Vektörleri ve Dönüşüm Bağıntısının Doğrulanması (ekrandan, 00:25:00–00:26:40):**
     - $\vec{u} = (2, 3, 5)$ vektörünü $\mathcal{B}_1$ bazında $\vec{u} = y_1\vec{v}_1 + y_2\vec{v}_2 + y_3\vec{v}_3$ olarak yazıp çözdüğümüzde $[\vec{u}]_{\mathcal{B}_1} = (-3, 0, 5)^T$ bulunur.
     - Benzer şekilde $\vec{u} = (2, 3, 5) = x_1\vec{w}_1 + x_2\vec{w}_2 + x_3\vec{w}_3$ sistemini çözdüğümüzde (veya $[\vec{u}]_{\mathcal{B}_2} = [M]_{\mathcal{B}_1}^{\mathcal{B}_2}[\vec{u}]_{\mathcal{B}_1}$ çarpımını yaptığımızda) $[\vec{u}]_{\mathcal{B}_2} = (5, -11/5, -2)^T$ elde edilir ve $[\vec{u}]_{\mathcal{B}_1} = [M]_{\mathcal{B}_2}^{\mathcal{B}_1}[\vec{u}]_{\mathcal{B}_2}$ eşitliği doğrulanır. (Not: Slaytta 71. sayfada $\vec{u} = (2, 3, 5)$ için denklem kurulurken ilk satırda $-x_2 - x_3 = 2$ yerine sehven $-x_2 - x_3 = 1$ yazıldığı için slaytta $(24/5, 1/5, -11/5)^T$ çıkmıştır; sağ taraftaki matriste $2$ ile doğru indirgeme yapıldığında $(5, -11/5, -2)^T$ çıkar).

### 1.4 Baz Vektörleri Arasındaki Doğrusal Bağıntıdan Geçiş Matrisi ve Koordinat Vektörü Bulma Örneği

> **Hocanın vurgusu (ekrandan, 00:26:45 ve 00:28:00):** Hoca bu örneğin çok önemli olduğunu ve final sınavında buna çok benzer bir soruyla karşılaşabileceğimizi özellikle vurgulamıştır.

- **Verilen (ekrandan, 00:28:00 ve 00:32:30):**
  Bir $V$ vektör uzayının iki sıralı bazı $\mathcal{B}_1 = \{\vec{v}_1, \vec{v}_2, \vec{v}_3\}$ ve $\mathcal{B}_2 = \{\vec{w}_1, \vec{w}_2, \vec{w}_3\}$ olsun. Bu örnekte baz vektörlerinin kendileri (koordinatları) verilmemiş, yalnızca aralarındaki şu bağıntılar verilmiştir:
  $$\begin{aligned}
  \vec{v}_1 &= \vec{w}_1 + \vec{w}_2 - \vec{w}_3 \\
  \vec{v}_2 &= 2\vec{w}_1 - \vec{w}_2 + \vec{w}_3 \\
  \vec{v}_3 &= \vec{w}_1 + 2\vec{w}_3
  \end{aligned}$$
  1. $[M]_{\mathcal{B}_1}^{\mathcal{B}_2}$ ($\mathcal{B}_1$'den $\mathcal{B}_2$'ye geçiş matrisini),
  2. $[M]_{\mathcal{B}_2}^{\mathcal{B}_1}$ ($\mathcal{B}_2$'den $\mathcal{B}_1$'e geçiş matrisini),
  3. $[\vec{u}]_{\mathcal{B}_1} = \begin{pmatrix} 1 \\ 0 \\ 3 \end{pmatrix}$ olarak verilen $\vec{u}$ vektörünün $\mathcal{B}_2$ bazına göre koordinat vektörü $[\vec{u}]_{\mathcal{B}_2}$'yi bulunuz.

- **Adım Adım Çözüm:**
  1. **$[M]_{\mathcal{B}_1}^{\mathcal{B}_2}$ Geçiş Matrisinin Bulunması:**
     Geçiş matrisinin tanımını hatırlayalım: $\mathcal{B}_1$'den $\mathcal{B}_2$'ye geçiş matrisi $[M]_{\mathcal{B}_1}^{\mathcal{B}_2}$'yi bulmak demek, $\mathcal{B}_1$'deki her bir $\vec{v}_1, \vec{v}_2, \vec{v}_3$ vektörünü $\mathcal{B}_2$'deki $\vec{w}_1, \vec{w}_2, \vec{w}_3$ vektörlerinin doğrusal birleşimi olarak yazıp katsayıları sütunlara yerleştirmek demektir! Soruda bu doğrusal birleşimler zaten hazır olarak verilmiştir:
     - $\vec{v}_1 = 1\vec{w}_1 + 1\vec{w}_2 - 1\vec{w}_3 \implies$ 1. sütun: $\begin{pmatrix} 1 \\ 1 \\ -1 \end{pmatrix}$
     - $\vec{v}_2 = 2\vec{w}_1 - 1\vec{w}_2 + 1\vec{w}_3 \implies$ 2. sütun: $\begin{pmatrix} 2 \\ -1 \\ 1 \end{pmatrix}$
     - $\vec{v}_3 = 1\vec{w}_1 + 0\vec{w}_2 + 2\vec{w}_3$ ($\vec{w}_2$ terimi olmadığı için katsayısı $0$'dır) $\implies$ 3. sütun: $\begin{pmatrix} 1 \\ 0 \\ 2 \end{pmatrix}$
     Bu üç sütunu yan yana yazdığımızda geçiş matrisini hiçbir denklem çözmeden doğrudan elde ederiz:
     $$[M]_{\mathcal{B}_1}^{\mathcal{B}_2} = \begin{pmatrix} 1 & 2 & 1 \\ 1 & -1 & 0 \\ -1 & 1 & 2 \end{pmatrix}$$
  2. **$[M]_{\mathcal{B}_2}^{\mathcal{B}_1}$ Geçiş Matrisinin Bulunması:**
     $\mathcal{B}_2$'den $\mathcal{B}_1$'e geçiş matrisi, yukarıda bulduğumuz matrisin tersidir:
     $$[M]_{\mathcal{B}_2}^{\mathcal{B}_1} = \left([M]_{\mathcal{B}_1}^{\mathcal{B}_2}\right)^{-1} = \begin{pmatrix} 1 & 2 & 1 \\ 1 & -1 & 0 \\ -1 & 1 & 2 \end{pmatrix}^{-1} = -\frac{1}{5} \begin{pmatrix} -2 & -3 & 1 \\ -2 & 3 & 1 \\ 0 & -3 & -3 \end{pmatrix} = \begin{pmatrix} 2/5 & 3/5 & -1/5 \\ 2/5 & -3/5 & -1/5 \\ 0 & 3/5 & 3/5 \end{pmatrix}$$
     (ek matris ve determinant formülüyle $\det([M]_{\mathcal{B}_1}^{\mathcal{B}_2}) = -5$ üzerinden kolayca bulunur; ara adım eklendi).
  3. **$[\vec{u}]_{\mathcal{B}_2}$ Koordinat Vektörünün Bulunması (ekrandan, 00:32:30):**
     Teoremdeki koordinat dönüşüm formülünü uygularsak:
     $$[\vec{u}]_{\mathcal{B}_2} = [M]_{\mathcal{B}_1}^{\mathcal{B}_2} [\vec{u}]_{\mathcal{B}_1} = \begin{pmatrix} 1 & 2 & 1 \\ 1 & -1 & 0 \\ -1 & 1 & 2 \end{pmatrix} \begin{pmatrix} 1 \\ 0 \\ 3 \end{pmatrix} = \begin{pmatrix} 1(1) + 2(0) + 1(3) \\ 1(1) - 1(0) + 0(3) \\ -1(1) + 1(0) + 2(3) \end{pmatrix} = \begin{pmatrix} 4 \\ 1 \\ 5 \end{pmatrix}$$
     (Benzer şekilde $[\vec{v}]_{\mathcal{B}_2}$ verilip $[\vec{v}]_{\mathcal{B}_1}$ istendiğinde $[\vec{v}]_{\mathcal{B}_1} = [M]_{\mathcal{B}_2}^{\mathcal{B}_1} [\vec{v}]_{\mathcal{B}_2}$ çarpımı yapılır).

## 2. Özdeğerler ve Özvektörler (Eigenvalues and Eigenvectors)

Hoca bu bölümde **özdeğerler ve özvektörler** (eigenvalues and eigenvectors) ile **Cayley-Hamilton teoremini** işleyeceğimizi; ders notlarında yer alan "Benzer Matrisler ve Köşegenleştirme" (Similar matrices and diagonalization) alt başlıklarından ise sınavda sorumlu olmadığımızı belirtti.

### 2.1 Özdeğer ve Özvektör Tanımı

- **Tanım (Özdeğer ve Özvektör — ekrandan, 00:39:00):**
  $A$, $n \times n$ boyutlu bir kare matris olsun. Eğer:
  $$A\vec{x} = \lambda \vec{x}$$
  denklemini sağlayan **sıfırdan farklı** (nontrivial solution, $\vec{x} \neq \vec{0}$) bir $\vec{x}$ vektörü varsa, $\lambda$ skalerine $A$ matrisinin bir **özdeğeri** (eigenvalue veya bazı kitaplarda karakteristik değeri / characteristic value) denir. Bu denklemi sağlayan sıfırdan farklı $\vec{x}$ vektörüne ise $\lambda$ özdeğerine karşılık gelen (associated with / corresponding to $\lambda$) bir **özvektör** (eigenvector) denir.
  (Tarihsel/Dilsel Not: "Eigen" kelimesi Almancada "öz / kendine ait / uygun" (proper) anlamına gelir).

### 2.2 Sıfır Özdeğeri ile Matrisin Tersinirliği Arasındaki İlişki

> **Hocanın vurgusu (Önemli Not ve Teorem — ekrandan, 00:39:00):**
> 1. **Özvektör Sıfır Vektörü Olamaz ($\vec{x} \neq \vec{0}$):** Bir özvektör asla $\vec{0}$ sıfır vektörü olamaz! Çünkü $\vec{x} = \vec{0}$ için $A\vec{0} = \lambda \vec{0} = \vec{0}$ denklemi her matris ve her $\lambda$ için zaten aşikar olarak sağlanır ve hiçbir anlam taşımaz. Bu yüzden tanımda $\vec{x}$'in sıfırdan farklı (nontrivial) bir çözüm olması şarttır.
> 2. **Özdeğer Sıfır Olabilir ($\lambda = 0 \in \mathbb{R}$):** Buna karşılık bir matrisin özdeğeri $\lambda = 0$ reel sayısı olabilir! Eğer $\lambda = 0$, $A$ matrisinin bir özdeğeri ise, $A\vec{x} = 0\vec{x} = \vec{0}$ homojen sistemini sağlayan sıfırdan farklı (nontrivial) bir $\vec{x} \neq \vec{0}$ vektörü var demektir. Homojen sistemin sıfırdan farklı çözümü olması ise $\det(A) = 0$ olması, yani **$A$ matrisinin tersinir olmaması (tekil / singular / non-invertible olması)** anlamına gelir.
> 3. **Teorem:** $n \times n$ boyutlu bir $A$ kare matrisinin **tersinir (invertible)** olması için gerek ve yeter şart **$0$'ın $A$ matrisinin bir özdeğeri olmamasıdır**.

### 2.3 $2 \times 2$ Matris İçin Tanımdan Özdeğer ve Özvektör Bulma Örneği

- **Verilen (ekrandan, 00:45:30 ve 00:52:30):**
  $A = \begin{bmatrix} 1 & 1 \\ -2 & 4 \end{bmatrix}$ matrisinin tüm özdeğerlerini ve özvektörlerini bulunuz.

- **Adım Adım Çözüm:**
  1. **$A\vec{x} = \lambda \vec{x}$ Denkleminin Kurulması ve Özdeğerlerin Bulunması:**
     $A$ matrisi $2 \times 2$ boyutlu olduğundan özvektörü $\vec{x} = \begin{bmatrix} x_1 \\ x_2 \end{bmatrix}$ olarak alalım:
     $$\begin{bmatrix} 1 & 1 \\ -2 & 4 \end{bmatrix} \begin{bmatrix} x_1 \\ x_2 \end{bmatrix} = \lambda \begin{bmatrix} x_1 \\ x_2 \end{bmatrix} \implies \begin{cases} x_1 + x_2 = \lambda x_1 \\ -2x_1 + 4x_2 = \lambda x_2 \end{cases}$$
     Sağ taraftaki terimleri sol tarafa atıp $x_1$ ve $x_2$ parantezine aldığımızda şu homojen doğrusal denklem sistemini elde ederiz:
     $$\begin{cases} (1 - \lambda)x_1 + x_2 = 0 \\ -2x_1 + (4 - \lambda)x_2 = 0 \end{cases}$$
     Bu homojen sistemin **sıfırdan farklı (nontrivial) çözüme** sahip olmasını istiyoruz (çünkü özvektör $\vec{x} \neq \vec{0}$ olmalıdır). Bir kare homojen sistemin sıfırdan farklı çözüme sahip olması için katsayılar matrisinin determinantı sıfır olmalıdır:
     $$\begin{vmatrix} 1 - \lambda & 1 \\ -2 & 4 - \lambda \end{vmatrix} = 0$$
     Determinantı açalım:
     $$(1 - \lambda)(4 - \lambda) - (1)(-2) = 0 \implies (1 - \lambda)(4 - \lambda) + 2 = 0$$
     $$\lambda^2 - 5\lambda + 4 + 2 = 0 \implies \lambda^2 - 5\lambda + 6 = 0$$
     Polinomu çarpanlarına ayırdığımızda:
     $$(\lambda - 2)(\lambda - 3) = 0 \implies \lambda_1 = 2, \quad \lambda_2 = 3$$
     olarak $A$ matrisinin özdeğerleri bulunur.

  2. **$\lambda_1 = 2$ Özdeğerine Karşılık Gelen Özvektörlerin Bulunması:**
     $A\vec{x} = 2\vec{x}$ (veya yukarıdaki homojen sistemde $\lambda = 2$) yazalım:
     $$\begin{cases} x_1 + x_2 = 2x_1 \\ -2x_1 + 4x_2 = 2x_2 \end{cases} \implies \begin{cases} -x_1 + x_2 = 0 \\ -2x_1 + 2x_2 = 0 \end{cases} \implies x_1 = x_2$$
     Sistemin sonsuz çözümü vardır. $x_2 = r \in \mathbb{R} \setminus \{0\}$ dersek $x_1 = r$ olur ve $\lambda_1 = 2$ özdeğerine karşılık gelen özvektör ailesi:
     $$\vec{x}_1 = \begin{bmatrix} r \\ r \end{bmatrix} = r\begin{bmatrix} 1 \\ 1 \end{bmatrix} \quad (r \in \mathbb{R} \setminus \{0\})$$
     olarak bulunur. (Sınavda çoktan seçmeli şıklarda $r = 1$ için $\begin{bmatrix} 1 \\ 1 \end{bmatrix}$, $r = 2$ için $\begin{bmatrix} 2 \\ 2 \end{bmatrix}$ veya genel $\begin{bmatrix} r \\ r \end{bmatrix}$ formu verilebilir).

  3. **$\lambda_2 = 3$ Özdeğerine Karşılık Gelen Özvektörlerin Bulunması (ekrandan, 00:52:30):**
     $A\vec{x} = 3\vec{x}$ (veya homojen sistemde $\lambda = 3$) yazalım:
     $$\begin{cases} x_1 + x_2 = 3x_1 \\ -2x_1 + 4x_2 = 3x_2 \end{cases} \implies \begin{cases} -2x_1 + x_2 = 0 \\ -2x_1 + x_2 = 0 \end{cases} \implies x_1 = \frac{1}{2}x_2$$
     $x_2 = r \in \mathbb{R} \setminus \{0\}$ seçilirse $x_1 = \frac{r}{2}$ olur ve $\lambda_2 = 3$ özdeğerine karşılık gelen özvektör:
     $$\vec{x}_2 = \begin{bmatrix} r/2 \\ r \end{bmatrix} \quad (\text{veya } r = 2 \text{ seçilirse } \vec{x}_2 = \begin{bmatrix} 1 \\ 2 \end{bmatrix})$$
     olarak elde edilir.

## 3. Karakteristik Denklem, Karakteristik Polinom ve Özdeğer/Özvektör Bulma Algoritması

### 3.1 Karakteristik Denklem ($\det(A - \lambda I_n) = 0$) ve $2 \times 2$ Matris İçin İz-Determinant Formülü

$A$, $n \times n$ boyutlu bir kare matris olsun. $A\vec{x} = \lambda \vec{x}$ denkleminde sağ tarafı sola alıp $\lambda \vec{x} = \lambda I_n \vec{x}$ yazarak $\vec{x}$ sağdan ortak çarpan parantezine alınırsa (ekrandan, 00:56:00):
$$A\vec{x} = \lambda \vec{x} \implies A\vec{x} - \lambda \vec{x} = \vec{0} \implies A\vec{x} - \lambda I_n \vec{x} = \vec{0} \implies (A - \lambda I_n)\vec{x} = \vec{0}$$
homojen sistemi elde edilir. Sıfırdan farklı ($\vec{x} \neq \vec{0}$) özvektörler aradığımız için bu homojen sistemin aşikar olmayan (nontrivial) çözüme sahip olması gerekir; bunun gerek ve yeter şartı ise determinantın sıfır olmasıdır:

- **Karakteristik Denklem (Characteristic Equation):**
  $$\det(A - \lambda I_n) = 0$$
  denklemine $A$ matrisinin **karakteristik denklemi** denir. Bir $\lambda$ skalerinin $A$'nın özdeğeri olması için gerek ve yeter şart bu karakteristik denklemi sağlamasıdır (yani karakteristik polinomun bir kökü olmasıdır).
- **Karakteristik Polinom (Characteristic Polynomial):**
  $P_A(\lambda) = \det(A - \lambda I_n)$ determinantının açılmasıyla elde edilen $n$. dereceden polinoma $A$'nın **karakteristik polinomu** denir ve genel formu şöyledir:
  $$P_A(\lambda) = (-1)^n \lambda^n + (-1)^{n-1}\text{Tr}(A)\lambda^{n-1} + \dots + \det(A)$$
- **$2 \times 2$ Boyutlu Kare Matris İçin Özel Formül (Çok Önemli — ekrandan, 00:56:00):**
  $n = 2$ olduğunda $(-1)^2 = 1$ ve $(-1)^{2-1} = -1$ olduğundan, herhangi bir $2 \times 2$ boyutlu $A$ kare matrisinin karakteristik polinomu doğrudan matrisin izi ($\text{Tr}(A)$) ve determinantı ($\det(A)$) kullanılarak şu formülle yazılabilir:
  $$P_A(\lambda) = \lambda^2 - \text{Tr}(A)\lambda + \det(A)$$
  (Örneğin Bölüm 2.3'teki $A = \begin{bmatrix} 1 & 1 \\ -2 & 4 \end{bmatrix}$ matrisinde $\text{Tr}(A) = 1 + 4 = 5$ ve $\det(A) = 4 - (-2) = 6$ olduğundan karakteristik polinom hiç determinant açmadan doğrudan $P_A(\lambda) = \lambda^2 - 5\lambda + 6$ olarak yazılabilir).

### 3.2 Özdeğer ve Özvektör Bulma Adımları, Katlı Özdeğerler ve Üçgensel Matrisler

Bir $A$ matrisinin özdeğer ve özvektörlerini bulmak için izlenen algoritma ve iki kritik özellik şunlardır (ekrandan, 00:59:45):

1. $A$ matrisinin karakteristik polinomu $P_A(\lambda) = |A - \lambda I_n|$ bulunur.
2. $P_A(\lambda) = 0$ karakteristik denkleminin kökleri bulunarak $A$'nın özdeğerleri ($\lambda$) elde edilir.
3. Bulunan her bir $\lambda$ özdeğeri için:
   - a) $A$'nın esas köşegen elemanlarından $\lambda$ çıkarılarak $M = A - \lambda I_n$ matrisi oluşturulur.
   - b) $MX = (A - \lambda I_n)\vec{x} = \vec{0}$ homojen sistemi çözülerek o özdeğere karşılık gelen özvektörler bulunur.

> **Hocanın vurgusu (İki Önemli Not — ekrandan, 00:59:45):**
> - **Not 1 (Üçgensel Matrislerin Özdeğerleri):** Bir **üçgensel matrisin** (triangular matrix — üst üçgensel, alt üçgensel veya köşegen matrisin) özdeğerleri, doğrudan matrisin **esas köşegeni (main diagonal) üzerindeki elemanlardır**! Çünkü $A - \lambda I_n$ de üçgensel bir matristir ve determinantı köşegen elemanlarının çarpımı olan $(a_{11} - \lambda)(a_{22} - \lambda)\cdots(a_{nn} - \lambda) = 0$'a eşittir.
> - **Not 2 (Katlı Kökler / Katlı Özdeğerler):** Karakteristik polinom $P_A(\lambda)$'nın katlı kökleri (multiple roots) varsa matrisin katlı özdeğerleri vardır. Örneğin karakteristik denklem $(\lambda - 2)^2 = 0$ çıkarsa $\lambda_1 = \lambda_2 = 2$ (iki katlı özdeğer) olur.

### 3.3 $3 \times 3$ Matrisin Karakteristik Polinomunun Polinom Bölmesiyle Çarpanlarına Ayrılması ve Özvektör Hesabı

- **Verilen (ekrandan, 01:02:00, 01:10:30 ve 01:16:30):**
  $$A = \begin{bmatrix} 1 & 2 & -1 \\ 1 & 0 & 1 \\ 4 & -4 & 5 \end{bmatrix}$$
  matrisinin tüm özdeğerlerini ve $\lambda_1 = 1$ özdeğerine karşılık gelen özvektörünü bulunuz.

- **Adım Adım Çözüm:**
  1. **Karakteristik Polinomun Hesaplanması (ekrandan, 01:02:00–01:05:50):**
     Esas köşegen elemanlarından $\lambda$ çıkararak $\det(A - \lambda I_3) = 0$ determinantını kuralım:
     $$\det(A - \lambda I_3) = \begin{vmatrix} 1 - \lambda & 2 & -1 \\ 1 & -\lambda & 1 \\ 4 & -4 & 5 - \lambda \end{vmatrix} = 0$$
     Sarrus kuralıyla (veya Laplace açılımıyla) determinantı hesaplayalım:
     - Soldan sağa köşegen çarpımları:
       $$(1 - \lambda)(-\lambda)(5 - \lambda) + (1)(-4)(-1) + (4)(2)(1) = -\lambda(1 - \lambda)(5 - \lambda) + 4 + 8 = -\lambda(\lambda^2 - 6\lambda + 5) + 12$$
     - Sağdan sola köşegen çarpımları (çıkarılanlar):
       $$-\left[ (-1)(-\lambda)(4) + (1)(-4)(1 - \lambda) + (5 - \lambda)(2)(1) \right] = -4\lambda + 4(1 - \lambda) - 2(5 - \lambda) = -4\lambda + 4 - 4\lambda - 10 + 2\lambda = -6\lambda - 6$$
     Topladığımızda:
     $$P_A(\lambda) = -\lambda^3 + 6\lambda^2 - 5\lambda + 12 - 6\lambda - 6 = -\lambda^3 + 6\lambda^2 - 11\lambda + 6 = 0$$
     Denklemi $-1$ ile çarparsak:
     $$\lambda^3 - 6\lambda^2 + 11\lambda - 6 = 0$$
     üçüncü dereceden karakteristik denklemini elde ederiz.

  2. **$3$. Dereceden Polinomun Polinom Bölmesiyle Çarpanlarına Ayrılması (ekrandan, 01:10:30):**
     $3$. dereceden bir polinomu çarpanlarına ayırmak için önce sabit terimin ($-6$'nın) tam sayı bölenlerini ($\pm 1, \pm 2, \pm 3, \pm 6$) deneyerek bir kök buluruz:
     - $\lambda = 1$ yazarsak: $1^3 - 6(1)^2 + 11(1) - 6 = 1 - 6 + 11 - 6 = 0$!
     O halde **$\lambda_1 = 1$** karakteristik polinomun bir köküdür (dolayısıyla ilk özdeğerdir).
     Diğer iki kökü bulmak için $\lambda^3 - 6\lambda^2 + 11\lambda - 6$ polinomunu $(\lambda - 1)$'e polinom bölmesiyle böleriz:
     - $\lambda^3$'ü elde etmek için $\lambda - 1$'i $\lambda^2$ ile çarparız: $(\lambda^3 - 6\lambda^2 + 11\lambda - 6) - (\lambda^3 - \lambda^2) = -5\lambda^2 + 11\lambda - 6$.
     - $-5\lambda^2$'yi elde etmek için $\lambda - 1$'i $-5\lambda$ ile çarparız: $(-5\lambda^2 + 11\lambda - 6) - (-5\lambda^2 + 5\lambda) = 6\lambda - 6$.
     - $6\lambda - 6$'yı elde etmek için $\lambda - 1$'i $+6$ ile çarparız: $(6\lambda - 6) - (6\lambda - 6) = 0$.
     Böylece polinom şu şekilde çarpanlarına ayrılır:
     $$\lambda^3 - 6\lambda^2 + 11\lambda - 6 = (\lambda - 1)(\lambda^2 - 5\lambda + 6) = (\lambda - 1)(\lambda - 2)(\lambda - 3) = 0$$
     Buradan matrisin üç özdeğeri:
     $$\lambda_1 = 1, \quad \lambda_2 = 2, \quad \lambda_3 = 3$$
     olarak bulunur.

  3. **$\lambda_1 = 1$ Özdeğerine Karşılık Gelen Özvektörün Bulunması (ekrandan, 01:16:30):**
     $(A - \lambda_1 I_3)\vec{x} = (A - I_3)\vec{x} = \vec{0}$ homojen sistemini kuralım. $A$'nın esas köşegeninden $1$ çıkardığımızda:
     $$\begin{bmatrix} 1-1 & 2 & -1 \\ 1 & 0-1 & 1 \\ 4 & -4 & 5-1 \end{bmatrix} \begin{bmatrix} x_1 \\ x_2 \\ x_3 \end{bmatrix} = \begin{bmatrix} 0 & 2 & -1 \\ 1 & -1 & 1 \\ 4 & -4 & 4 \end{bmatrix} \begin{bmatrix} x_1 \\ x_2 \\ x_3 \end{bmatrix} = \begin{bmatrix} 0 \\ 0 \\ 0 \end{bmatrix}$$
     Denklemleri yazalım:
     $$\begin{cases} 0x_1 + 2x_2 - x_3 = 0 \\ x_1 - x_2 + x_3 = 0 \\ 4x_1 - 4x_2 + 4x_3 = 0 \end{cases}$$
     - 1. denklemden: $2x_2 - x_3 = 0 \implies x_2 = \frac{1}{2}x_3$.
     - 2. denklemden (3. denklem 2. denklemin $4$ katıdır):
       $$x_1 = x_2 - x_3 = \frac{1}{2}x_3 - x_3 = -\frac{1}{2}x_3$$
     - $x_3 = r \in \mathbb{R} \setminus \{0\}$ parametresi seçilirse $\lambda_1 = 1$ özdeğerine karşılık gelen özvektör ailesi:
       $$\vec{x}_1 = \begin{bmatrix} -r/2 \\ r/2 \\ r \end{bmatrix}$$
       olarak bulunur. Kesirlerden kurtulmak için özel olarak $r = 2$ seçersek:
       $$\vec{x}_1 = \begin{bmatrix} -1 \\ 1 \\ 2 \end{bmatrix}$$
       özvektörünü elde ederiz. ($\lambda_2 = 2$ ve $\lambda_3 = 3$ için de özvektörler tamamen aynı yolla bulunur).

### 3.4 Üst Üçgensel $3 \times 3$ Matrisin Özdeğerleri ve Karakteristik Polinomu

- **Verilen (ekrandan, 01:10:30 ve 01:19:30):**
  $$A = \begin{pmatrix} 3 & 6 & -8 \\ 0 & 0 & 6 \\ 0 & 0 & 2 \end{pmatrix}$$
  matrisinin karakteristik polinomunu ve özdeğerlerini bulunuz.
- **Çözüm:**
  $A$ matrisi esas köşegeninin altındaki tüm elemanlar sıfır olduğundan bir **üst üçgensel matristir** (upper triangular matrix).
  - **Özdeğerler:** Üçgensel bir matrisin özdeğerleri doğrudan esas köşegeni üzerindeki elemanlar olduğundan hiçbir işlem yapmadan özdeğerler:
    $$\lambda_1 = 3, \quad \lambda_2 = 0, \quad \lambda_3 = 2$$
    olarak yazılır. (Dikkat edilirse $\lambda_2 = 0$ özdeğeri olduğu için bu $A$ matrisi tekildir / tersinir değildir).
  - **Karakteristik Polinom:**
    $$P_A(\lambda) = \det(A - \lambda I_3) = \begin{vmatrix} 3-\lambda & 6 & -8 \\ 0 & -\lambda & 6 \\ 0 & 0 & 2-\lambda \end{vmatrix} = (3 - \lambda)(-\lambda)(2 - \lambda) = -\lambda(\lambda - 3)(\lambda - 2)$$
    (veya $-\lambda^3 + 5\lambda^2 - 6\lambda$).

## 4. Cayley-Hamilton Teoremi ve Uygulamaları (Cayley-Hamilton Theorem)

### 4.1 Cayley-Hamilton Teoremi ve Matrisin Tersini / Kuvvetlerini Hesaplama Formülleri

- **Teorem (Cayley-Hamilton Teoremi — ekrandan, 01:23:45):**
  **Her $A$ kare matrisi kendi karakteristik polinomunun bir köküdür** (yani kendi karakteristik denklemini sağlar):
  $$P_A(A) = O_{n \times n}$$
  Açık olarak, eğer $n \times n$ boyutlu $A$ matrisinin karakteristik denklemi:
  $$P_A(\lambda) = \lambda^n + a_{n-1}\lambda^{n-1} + \dots + a_1 \lambda + a_0 = 0$$
  ise, $\lambda$ yerine $A$ matrisi ve sabit terim $a_0$'ın yanına $I_n$ birim matrisi yazıldığında:
  $$P_A(A) = A^n + a_{n-1}A^{n-1} + \dots + a_1 A + a_0 I_n = O_{n \times n}$$
  matris eşitliği her zaman sağlanır.

- **Cayley-Hamilton Teoreminin İki Temel Uygulaması (ekrandan, 01:23:45):**
  1. **Matrisin Kuvvetlerini ($A^n, A^{n+1}, \dots$) Hesaplama:**
     Yukarıdaki denklemden en yüksek kuvvet olan $A^n$ yalnız bırakılırsa:
     $$A^n = -\left(a_{n-1}A^{n-1} + \dots + a_1 A + a_0 I_n\right)$$
     elde edilir. Böylece $A$'nın yüksek kuvvetleri, matrisi defalarca kendisiyle çarpmak yerine daha düşük kuvvetlerin doğrusal birleşimi cinsinden kolayca hesaplanır.
  2. **Tersinir Bir Matrisin Tersini ($A^{-1}$) Hesaplama:**
     Eğer $a_0 = \det(A) \neq 0$ ise ($A$ tersinir ise), $a_0 I_n$ terimi yalnız bırakılıp $A$ ortak çarpanına alındığında:
     $$I_n = A \left[ -\frac{1}{a_0} \left(A^{n-1} + a_{n-1}A^{n-2} + \dots + a_1 I_n\right) \right]$$
     veya her iki taraf $A^{-1}$ ile çarpıldığında doğrudan:
     $$A^{-1} = -\frac{1}{a_0} \left(A^{n-1} + a_{n-1}A^{n-2} + \dots + a_1 I_n\right)$$
     formülüyle $A^{-1}$ ters matrisi elde edilir.

### 4.2 Cayley-Hamilton Teoremi ile $A^{-1}$ ve $A^5$ Hesabı Örneği

- **Verilen (ekrandan, 01:25:00, 01:28:15 ve 01:36:30):**
  $$A = \begin{pmatrix} 1 & 4 \\ 2 & 3 \end{pmatrix}$$
  matrisi için:
  1. Karakteristik polinomu, özdeğerleri ve $\lambda_1 = -1$ özdeğerine karşılık gelen özvektörü bulunuz.
  2. Cayley-Hamilton teoremini kullanarak $A^{-1}$ ters matrisini ve $A^5$ (beşinci kuvvet) matrisini bulunuz.

- **Adım Adım Çözüm:**
  1. **Karakteristik Polinom, Özdeğerler ve Özvektör (ekrandan, 01:28:15):**
     - Karakteristik denklem:
       $$\det(A - \lambda I_2) = \begin{vmatrix} 1 - \lambda & 4 \\ 2 & 3 - \lambda \end{vmatrix} = (1 - \lambda)(3 - \lambda) - 8 = 0$$
       $$\lambda^2 - 4\lambda + 3 - 8 = 0 \implies \lambda^2 - 4\lambda - 5 = 0$$
       (Not: $2 \times 2$ kısayol formülüyle de $\text{Tr}(A) = 1 + 3 = 4$ ve $\det(A) = 3 - 8 = -5$ olduğundan doğrudan $P_A(\lambda) = \lambda^2 - 4\lambda - 5$ bulunur).
     - Özdeğerler:
       $$(\lambda - 5)(\lambda + 1) = 0 \implies \lambda_1 = -1, \quad \lambda_2 = 5$$
     - $\lambda_1 = -1$ için özvektör: $(A - (-1)I_2)\vec{x} = (A + I_2)\vec{x} = \vec{0}$ sistemini kuralım:
       $$\begin{pmatrix} 1+1 & 4 \\ 2 & 3+1 \end{pmatrix} \begin{pmatrix} x_1 \\ x_2 \end{pmatrix} = \begin{pmatrix} 2 & 4 \\ 2 & 4 \end{pmatrix} \begin{pmatrix} x_1 \\ x_2 \end{pmatrix} = \begin{pmatrix} 0 \\ 0 \end{pmatrix} \implies 2x_1 + 4x_2 = 0 \implies x_1 = -2x_2$$
       $x_2 = r \in \mathbb{R} \setminus \{0\}$ seçilirse $x_1 = -2r$ olur ve özvektör:
       $$\vec{x}_1 = \begin{pmatrix} -2r \\ r \end{pmatrix} = r\begin{pmatrix} -2 \\ 1 \end{pmatrix}$$
       olarak bulunur.

  2. **Cayley-Hamilton Teoremi ile $A^{-1}$ Ters Matrisinin Bulunması (ekrandan, 01:29:00–01:31:45 ve 01:36:30):**
     Karakteristik denklem $\lambda^2 - 4\lambda - 5 = 0$ olduğundan, Cayley-Hamilton teoremi gereği $A$ matrisi bu denklemi sağlar:
     $$P_A(A) = A^2 - 4A - 5I_2 = O$$
     Sabit birim matrisli terimi ($5I_2$) eşitliğin diğer tarafına atalım:
     $$5I_2 = A^2 - 4A$$
     Her iki tarafı $A^{-1}$ ile çarpalım ($A^{-1}I_2 = A^{-1}$, $A^{-1}A^2 = A$ ve $A^{-1}A = I_2$ olduğundan):
     $$5A^{-1} = A - 4I_2$$
     $A$ ve $4I_2$ matrislerini yerine yazalım:
     $$5A^{-1} = \begin{pmatrix} 1 & 4 \\ 2 & 3 \end{pmatrix} - \begin{pmatrix} 4 & 0 \\ 0 & 4 \end{pmatrix} = \begin{pmatrix} -3 & 4 \\ 2 & -1 \end{pmatrix}$$
     Her iki tarafı $5$'e böldüğümüzde $A^{-1}$ ters matrisi bulunur:
     $$A^{-1} = \frac{1}{5}\begin{pmatrix} -3 & 4 \\ 2 & -1 \end{pmatrix} = \begin{pmatrix} -3/5 & 4/5 \\ 2/5 & -1/5 \end{pmatrix}$$

  3. **Cayley-Hamilton Teoremi ile $A^5$ Matrisinin Hesaplanması (ekrandan, 01:32:00–01:36:30):**
     $A^2 - 4A - 5I_2 = O$ denkleminden $A^2$'yi yalnız bırakalım:
     $$A^2 = 4A + 5I_2$$
     Şimdi adım adım her iki tarafı $A$ ile çarparak ve her ortaya çıkan $A^2$ yerine $4A + 5I_2$ yazarak $A^5$'e ulaşalım:
     - **$A^3$ hesabı:** $A^2 = 4A + 5I_2$ eşitliğinin iki tarafını $A$ ile çarpalım:
       $$A^3 = 4A^2 + 5A = 4(4A + 5I_2) + 5A = 16A + 20I_2 + 5A = 21A + 20I_2$$
     - **$A^4$ hesabı:** $A^3 = 21A + 20I_2$ eşitliğinin iki tarafını $A$ ile çarpalım:
       $$A^4 = 21A^2 + 20A = 21(4A + 5I_2) + 20A = 84A + 105I_2 + 20A = 104A + 105I_2$$
     - **$A^5$ hesabı:** $A^4 = 104A + 105I_2$ eşitliğinin iki tarafını $A$ ile çarpalım:
       $$A^5 = 104A^2 + 105A = 104(4A + 5I_2) + 105A = 416A + 520I_2 + 105A = 521A + 520I_2$$
     Böylece $A$ matrisini beş kez yan yana çarpmak yerine, $A^5$ matrisini $A$'nın birinci kuvveti ve $I_2$ birim matrisinin doğrusal birleşimi olarak $A^5 = 521A + 520I_2$ biçiminde elde etmiş oluruz (istenirse $A = \begin{pmatrix} 1 & 4 \\ 2 & 3 \end{pmatrix}$ ve $I_2 = \begin{pmatrix} 1 & 0 \\ 0 & 1 \end{pmatrix}$ yerine koyularak elemanları da hemen toplanabilir).

## Örnek Sorular

1. **Baz Vektörleri Arasındaki Bağıntıdan Geçiş Matrisi ve Koordinat Vektörü Bulma** (ekrandan, 00:28:00 ve 00:32:30)
   - **Soru:** Bir $V$ vektör uzayının $\mathcal{B}_1 = \{\vec{v}_1, \vec{v}_2, \vec{v}_3\}$ ve $\mathcal{B}_2 = \{\vec{w}_1, \vec{w}_2, \vec{w}_3\}$ sıralı bazları arasında $\vec{v}_1 = \vec{w}_1 + \vec{w}_2 - \vec{w}_3$, $\vec{v}_2 = 2\vec{w}_1 - \vec{w}_2 + \vec{w}_3$ ve $\vec{v}_3 = \vec{w}_1 + 2\vec{w}_3$ bağıntıları veriliyor. $[M]_{\mathcal{B}_1}^{\mathcal{B}_2}$ geçiş matrisini ve $[\vec{u}]_{\mathcal{B}_1} = (1, 0, 3)^T$ için $[\vec{u}]_{\mathcal{B}_2}$ koordinat vektörünü bulunuz.
   - **Çözüm (derste verildi):**
     $$\vec{v}_1, \vec{v}_2, \vec{v}_3 \text{ vektörlerinin } \mathcal{B}_2 \text{'deki katsayıları sütunlara yazılırsa: } [M]_{\mathcal{B}_1}^{\mathcal{B}_2} = \begin{pmatrix} 1 & 2 & 1 \\ 1 & -1 & 0 \\ -1 & 1 & 2 \end{pmatrix}$$
     $$[\vec{u}]_{\mathcal{B}_2} = [M]_{\mathcal{B}_1}^{\mathcal{B}_2}[\vec{u}]_{\mathcal{B}_1} = \begin{pmatrix} 1 & 2 & 1 \\ 1 & -1 & 0 \\ -1 & 1 & 2 \end{pmatrix}\begin{pmatrix} 1 \\ 0 \\ 3 \end{pmatrix} = \begin{pmatrix} 4 \\ 1 \\ 5 \end{pmatrix}$$

2. **$3 \times 3$ Matrisin Özdeğer ve Özvektörlerinin Bulunması** (ekrandan, 01:02:00, 01:10:30 ve 01:16:30)
   - **Soru:** $A = \begin{bmatrix} 1 & 2 & -1 \\ 1 & 0 & 1 \\ 4 & -4 & 5 \end{bmatrix}$ matrisinin özdeğerlerini ve $\lambda_1 = 1$ özdeğerine karşılık gelen özvektörünü bulunuz.
   - **Çözüm (derste verildi):**
     - Karakteristik denklem $\det(A - \lambda I_3) = -\lambda^3 + 6\lambda^2 - 11\lambda + 6 = 0 \iff \lambda^3 - 6\lambda^2 + 11\lambda - 6 = 0$'dır. $\lambda_1 = 1$ kökü bulunup polinom $\lambda - 1$'e bölündüğünde $(\lambda - 1)(\lambda^2 - 5\lambda + 6) = (\lambda - 1)(\lambda - 2)(\lambda - 3) = 0$ elde edilir; özdeğerler $\lambda_1 = 1, \lambda_2 = 2, \lambda_3 = 3$'tür.
     - $\lambda_1 = 1$ için $(A - I_3)\vec{x} = \vec{0}$ sisteminden $2x_2 - x_3 = 0$ ve $x_1 - x_2 + x_3 = 0 \implies x_2 = \frac{1}{2}x_3, \, x_1 = -\frac{1}{2}x_3$ bulunur. $x_3 = r = 2$ seçilirse özvektör $\vec{x}_1 = (-1, 1, 2)^T$ olur.

3. **Cayley-Hamilton Teoremi ile $A^{-1}$ ve $A^5$ Hesabı** (ekrandan, 01:25:00, 01:28:15 ve 01:36:30)
   - **Soru:** $A = \begin{pmatrix} 1 & 4 \\ 2 & 3 \end{pmatrix}$ matrisinin karakteristik polinomunu bulunuz ve Cayley-Hamilton teoremini kullanarak $A^{-1}$ ile $A^5$ matrislerini hesaplayınız.
   - **Çözüm (derste verildi):**
     - $P_A(\lambda) = \lambda^2 - \text{Tr}(A)\lambda + \det(A) = \lambda^2 - 4\lambda - 5 = 0$.
     - Cayley-Hamilton teoreminden $A^2 - 4A - 5I_2 = O \implies 5I_2 = A^2 - 4A$. İki taraf $A^{-1}$ ile çarpılırsa $5A^{-1} = A - 4I_2 = \begin{pmatrix} -3 & 4 \\ 2 & -1 \end{pmatrix} \implies A^{-1} = \begin{pmatrix} -3/5 & 4/5 \\ 2/5 & -1/5 \end{pmatrix}$.
     - $A^2 = 4A + 5I_2$ bağıntısından ardışık olarak $A^3 = 4(4A+5I_2)+5A = 21A + 20I_2$, $A^4 = 21(4A+5I_2)+20A = 104A + 105I_2$ ve $A^5 = 104(4A+5I_2)+105A = 521A + 520I_2$ bulunur.

## Dersin Toparlaması

Dönemin bu son dersinde ilk olarak bir vektör uzayındaki iki sıralı baz ($\mathcal{B}_1$ ve $\mathcal{B}_2$) arasındaki **geçiş matrisi** ($[M]_{\mathcal{B}_1}^{\mathcal{B}_2}$) ve **koordinat dönüşüm bağıntıları** ($[\vec{u}]_{\mathcal{B}_2} = [M]_{\mathcal{B}_1}^{\mathcal{B}_2}[\vec{u}]_{\mathcal{B}_1}$ ve $[M]_{\mathcal{B}_2}^{\mathcal{B}_1} = ([M]_{\mathcal{B}_1}^{\mathcal{B}_2})^{-1}$) hem koordinatları verilen bazlar üzerinde RREF indirgemesiyle hem de koordinatları verilmeden doğrudan baz vektörleri arasındaki doğrusal bağıntılar üzerinden örneklerle işlenmiştir. İkinci bölümde kare matrisler için **özdeğer ve özvektör** ($A\vec{x} = \lambda \vec{x}, \, \vec{x} \neq \vec{0}$) kavramları, $0$'ın özdeğer olmaması ile matrisin tersinirliği arasındaki denklik, **karakteristik denklem** ($\det(A - \lambda I_n) = 0$), $2 \times 2$ matrisler için $P_A(\lambda) = \lambda^2 - \text{Tr}(A)\lambda + \det(A)$ formülü, üçgensel matrislerin özdeğerlerinin esas köşegen elemanları olması ve $3 \times 3$ matrislerde polinom bölmesiyle özdeğer/özvektör hesabı ele alınmıştır. Son olarak her kare matrisin kendi karakteristik denklemini sağladığını ifade eden **Cayley-Hamilton teoremi** ($P_A(A) = O$) incelenmiş ve bu teorem yardımıyla bir matrisin tersinin ($A^{-1}$) ve yüksek kuvvetlerinin ($A^5$) nasıl hesaplandığı gösterilerek Lineer Cebir dersi tamamlanmıştır.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
