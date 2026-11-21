# Ders 11 Genişletilmiş Notu: Doğrusal Sistem Çözüm Yöntemlerinin İşlem Karmaşıklığı, Reel Vektör Uzayları ve Alt Vektör Uzayları (Altuzaylar)

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Doğrusal Denklem Sistemi Çözüm Yöntemlerinin İşlem Sayısı (Verimlilik) Karşılaştırması
- 2. Reel Vektör Uzayları (Real Vector Spaces)
  - 2.1 Vektör Uzayı Kavramına Giriş
  - 2.2 Reel Vektör Uzayı Tanımı ve 10 Temel Özelliği (Definition 172)
  - 2.3 Temel Terminoloji: Vektörler, Skalerler, Sıfır Vektörü ve Teklik
- 3. Temel Vektör Uzayı Örnekleri
  - 3.1 $\mathbb{R}^n$ Sütun Vektörleri Uzayı (Örnek 173)
  - 3.2 $M_{m \times n}$ Matrisler Uzayı, $\mathbb{R}$ Reel Sayılar Uzayı ve $R_n$ Satır Vektörleri Uzayı (Örnek 174, 175 ve 176)
  - 3.3 İzi Sıfır Olan $2 \times 2$ Matrisler Uzayı (Örnek 177)
  - 3.4 Derecesi En Çok $n$ Olan Polinomlar Uzayı $P_n$ (Örnek 178)
  - 3.5 Sürekli Fonksiyonlar Uzayı $C(-\infty, \infty)$ (Örnek 179)
- 4. Vektör Uzayı Olmayan Kümeler ve Kontrol Sırası (Checklist)
  - 4.1 Çıkarma İşlemiyle Tanımlı Reel Sayılar Kümesi (Örnek 180)
  - 4.2 Tam Sayılar Kümesi $\mathbb{Z}$ (Örnek 181)
  - 4.3 Bir Kümenin Vektör Uzayı Olup Olmadığını Kontrol Etme Sırası (Remark 182)
- 5. Alt Vektör Uzayları / Altuzaylar (Subspaces)
  - 5.1 Altuzay Tanımı ve İki Koşullu Altuzay Teoremi (Definition 183 & Theorem 184)
  - 5.2 Sıfır Altuzayı ve Polinom Altuzayları (Örnek 185, 186 ve 187)
  - 5.3 $\mathbb{R}^3$, $M_{2 \times 2}(\mathbb{R})$ ve $\mathbb{R}^2$ İçinde Altuzay Örnekleri ve Altuzay Olmayan Küme Örneği
- Örnek Sorular
- Dersin Toparlaması

## 1. Doğrusal Denklem Sistemi Çözüm Yöntemlerinin İşlem Sayısı (Verimlilik) Karşılaştırması

Hoca derse başlamadan önce, önceki haftalarda $Ax = b$ doğrusal denklem sistemlerini çözmek için öğrendiğimiz yöntemlerin (Gauss eliminasyonu, Gauss-Jordan eliminasyonu, ters matris yöntemi ve Cramer kuralı) hesaplama maliyetlerini karşılaştıran bir tablo paylaştı (ekrandan, 00:05:30):

- **Tablo: Büyük $n$ Değerleri İçin Tersinir Bir $n \times n$ Boyutlu $A$ Matrisinde Yaklaşık İşlem Sayıları (Approximate Operation Counts for an Invertible $n \times n$ Matrix $A$ for Large $n$)**
  1. **$Ax = \mathbf{b}$ sistemini Gauss-Jordan eliminasyonu ile çözmek:**
     - Yaklaşık toplama sayısı (Number of Additions): $\approx \frac{n^3}{3}$
     - Yaklaşık çarpma sayısı (Number of Multiplications): $\approx \frac{n^3}{3}$
  2. **$Ax = \mathbf{b}$ sistemini Gauss eliminasyonu (Gaussian elimination) ile çözmek:**
     - Yaklaşık toplama sayısı: $\approx \frac{n^3}{3}$
     - Yaklaşık çarpma sayısı: $\approx \frac{n^3}{3}$
  3. **$[A \mid I]$ matrisini $[I \mid A^{-1}]$ biçimine indirgeyerek $A^{-1}$ ters matrisini bulmak:**
     - Yaklaşık toplama sayısı: $\approx n^3$
     - Yaklaşık çarpma sayısı: $\approx n^3$
  4. **$Ax = \mathbf{b}$ sistemini $\mathbf{x} = A^{-1}\mathbf{b}$ ters matris yöntemiyle çözmek:**
     - Yaklaşık toplama sayısı: $\approx n^3$
     - Yaklaşık çarpma sayısı: $\approx n^3$
  5. **Satır indirgeme (row reduction) ile $\det(A)$ determinantını bulmak:**
     - Yaklaşık toplama sayısı: $\approx \frac{n^3}{3}$
     - Yaklaşık çarpma sayısı: $\approx \frac{n^3}{3}$
  6. **$Ax = \mathbf{b}$ sistemini Cramer kuralı (Cramer's rule) ile çözmek:**
     - Yaklaşık toplama sayısı: $\approx \frac{n^4}{3}$
     - Yaklaşık çarpma sayısı: $\approx \frac{n^4}{3}$

> **Hocanın vurgusu:** Bu tablodan açıkça görüldüğü üzere, büyük $n$ değerleri için ($n$ bilinmeyenli $n$ denklemli bir doğrusal sistemde) $Ax = \mathbf{b}$ sistemini çözmenin **en iyi (en verimli) yöntemi Gauss eliminasyonu veya Gauss-Jordan eliminasyonudur** ($\approx \frac{n^3}{3}$ işlem). Ters matrisle çarpma yöntemi ($\mathbf{x} = A^{-1}\mathbf{b}$) bundan çok daha kötüdür çünkü $3$ katı kadar ($\approx n^3$) işlem gerektirir. Dört yöntem arasında **en kötü (en verimsiz) yöntem ise Cramer kuralıdır** ($\approx \frac{n^4}{3}$ işlem).

## 2. Reel Vektör Uzayları (Real Vector Spaces)

### 2.1 Vektör Uzayı Kavramına Giriş

Lineer cebirde çok önemli bir sınıflandırma şeması (classification scheme) vardır ve bunun ilk temel kavramı **vektör uzayı** (vector space) kavramıdır. Bu derste yalnızca **reel vektör uzaylarını** (real vector spaces) inceleyeceğimiz için ders boyunca kısaca "vektör uzayı" dediğimizde her zaman "reel vektör uzayı" anlaşılacaktır.

"Vektör uzayı" adı ilk duyulduğunda düzlemdeki veya uzaydaki yönlü doğru parçalarını (okları) çağrıştırsa da, soyut matematikte bir vektör uzayı **bir nesneler kümesi (set of objects)** ile bu nesneler üzerinde tanımlanmış **iki işlemden (two operations)** oluşur. Özel vektör uzaylarında kümenin elemanları alışılmış yönlü doğru parçalarından çok farklı nesneler (örneğin matrisler, polinomlar veya sürekli fonksiyonlar) olabilir ve üzerindeki iki işlem de her zaman alışılmış toplama veya çarpma olmak zorunda değildir.

### 2.2 Reel Vektör Uzayı Tanımı ve 10 Temel Özelliği (Definition 172)

- **Tanım 172 (Reel Vektör Uzayı — ekrandan, 00:15:30 ve 00:19:45):**
  Bir **reel vektör uzayı** (real vector space), üzerinde $\oplus$ (vektör toplama) ve $\odot$ (skalerle çarpma) adı verilen iki işlem tanımlanmış olan ve aşağıdaki özellikleri sağlayan elemanlardan oluşan boş olmayan bir $V$ kümesidir:

  - **a) Birinci İşlem ($\oplus$) İçin Kapalılık ve 4 Aksiyom:**
    **Kapalılık (Closure under $\oplus$):** Eğer $\mathbf{u}$ ve $\mathbf{v}$, $V$ kümesinin herhangi iki elemanı ise, $\mathbf{u} \oplus \mathbf{v}$ de $V$ kümesinin bir elemanıdır ($\forall \mathbf{u}, \mathbf{v} \in V \implies \mathbf{u} \oplus \mathbf{v} \in V$). Bu koşul sağlandığında "$V$ kümesi $\oplus$ işlemi altında **kapalıdır** (closed under $\oplus$)" denir.
    1. **Değişme Özelliği (Commutative Law):** $V$'deki tüm $\mathbf{u}, \mathbf{v}$ elemanları için:
       $$\mathbf{u} \oplus \mathbf{v} = \mathbf{v} \oplus \mathbf{u}$$
    2. **Birleşme Özelliği (Associative Law):** $V$'deki tüm $\mathbf{u}, \mathbf{v}, \mathbf{w}$ elemanları için:
       $$\mathbf{u} \oplus (\mathbf{v} \oplus \mathbf{w}) = (\mathbf{u} \oplus \mathbf{v}) \oplus \mathbf{w}$$
    3. **Toplamsal Birim Eleman / Sıfır Vektörü (Additive Identity):** $V$ kümesinde öyle bir $\mathbf{0} \in V$ elemanı vardır ki, $V$'deki her $\mathbf{u}$ elemanı için:
       $$\mathbf{u} \oplus \mathbf{0} = \mathbf{0} \oplus \mathbf{u} = \mathbf{u}$$
       Yani bir vektör uzayı mutlaka toplamsal birim elemanı (sıfır elemanını) içermek zorundadır.
    4. **Toplamsal Ters Eleman (Additive Inverse):** $V$'deki her $\mathbf{u}$ elemanı için, $V$ kümesinde öyle bir $-\mathbf{u} \in V$ elemanı vardır ki:
       $$\mathbf{u} \oplus (-\mathbf{u}) = (-\mathbf{u}) \oplus \mathbf{u} = \mathbf{0}$$
       Yani bir vektör uzayı her elemanının toplamsal tersini de kendi içinde barındırmak zorundadır.

  - **b) İkinci İşlem ($\odot$) İçin Kapalılık ve 4 Aksiyom:**
    **Kapalılık (Closure under $\odot$):** Eğer $\mathbf{u}$, $V$ kümesinin herhangi bir elemanı ve $c \in \mathbb{R}$ herhangi bir reel sayı (skaler / sabit) ise, $c \odot \mathbf{u}$ da $V$ kümesinin bir elemanıdır ($\forall \mathbf{u} \in V, \, \forall c \in \mathbb{R} \implies c \odot \mathbf{u} \in V$). Yani $V$ kümesi $\odot$ skalerle çarpma işlemi altında **kapalıdır** (closed under $\odot$).
    5. **Skaler Çarpımın Vektör Toplamı Üzerine Dağılma Özelliği (Distributive Law):** $V$'deki her $\mathbf{u}, \mathbf{v}$ ve her $c \in \mathbb{R}$ reel sayısı için:
       $$c \odot (\mathbf{u} \oplus \mathbf{v}) = (c \odot \mathbf{u}) \oplus (c \odot \mathbf{v})$$
    6. **Reel Sayı Toplamının Skaler Çarpım Üzerine Dağılma Özelliği:** $V$'deki her $\mathbf{u}$ ve her $c, d \in \mathbb{R}$ reel sayıları için (burada $c + d$ reel sayıların olağan toplamıdır):
       $$(c + d) \odot \mathbf{u} = (c \odot \mathbf{u}) \oplus (d \odot \mathbf{u})$$
    7. **Skaler Çarpımda Birleşme Özelliği (Associative Property):** $V$'deki her $\mathbf{u}$ ve her $c, d \in \mathbb{R}$ reel sayıları için:
       $$c \odot (d \odot \mathbf{u}) = (cd) \odot \mathbf{u}$$
    8. **Çarpımsal Birim Eleman Özelliği (Multiplicative Identity):** $V$'deki her $\mathbf{u}$ için:
       $$1 \odot \mathbf{u} = \mathbf{u}$$

### 2.3 Temel Terminoloji: Vektörler, Skalerler, Sıfır Vektörü ve Teklik

Yukarıdaki tanım çerçevesinde kullanılan temel terimler şunlardır (ekrandan, 00:19:45):
- $V$ kümesinin elemanlarına **vektör** (vectors), $\mathbb{R}$ reel sayılar kümesinin elemanlarına ise **skaler** (scalars) denir.
- $\oplus$ işlemine **vektör toplama** (vector addition), $\odot$ işlemine ise **skalerle çarpma** (scalar multiplication) adı verilir.
- Özellik (3)'teki $\mathbf{0}$ vektörüne **sıfır vektörü** (zero vector), Özellik (4)'teki $-\mathbf{u}$ vektörüne ise **$\mathbf{u}$'nun negatifi** (negative of $\mathbf{u}$ / toplamsal tersi) denir.
- Bir vektör uzayında sıfır vektörü $\mathbf{0}$ ve her bir vektörün negatifi $-\mathbf{u}$ **tektir** (unique).
- Pratik gösterimde özel bir karışıklık olmadıkça $\mathbf{u} \oplus \mathbf{v}$ yerine doğrudan $\mathbf{u} + \mathbf{v}$ ve $c \odot \mathbf{u}$ yerine $c\mathbf{u}$ yazılır.

## 3. Temel Vektör Uzayı Örnekleri

Bir kümenin vektör uzayı olduğunu kanıtlamak için Tanım 172'deki tüm 10 koşulun (a, b kapalılıkları ve 1–8 özellikleri) sağlandığını göstermek gerekir.

### 3.1 $\mathbb{R}^n$ Sütun Vektörleri Uzayı (Örnek 173)

- **Tanım ve İşlemler (ekrandan, 00:22:00–00:32:50):**
  Reel elemanlı tüm $n \times 1$ boyutlu sütun matrislerinin kümesi olan $\mathbb{R}^n$ kümesini ele alalım.
  - Birinci işlem ($\oplus$): Standart **matris toplama** (matrix addition),
  - İkinci işlem ($\odot$): Bir matrisin bir reel sayıyla çarpımı olan standart **skalerle çarpma** (scalar multiplication) olarak tanımlansın.
- **Doğrulama:**
  1. **$\oplus$ Altında Kapalılık ve (1)–(4) Özellikleri:**
     $\mathbf{u} = \begin{bmatrix} a_1 \\ a_2 \\ \vdots \\ a_n \end{bmatrix} \in \mathbb{R}^n$ ve $\mathbf{v} = \begin{bmatrix} b_1 \\ b_2 \\ \vdots \\ b_n \end{bmatrix} \in \mathbb{R}^n$ iki eleman olsun. Matris toplamı:
     $$\mathbf{u} \oplus \mathbf{v} = \begin{bmatrix} a_1 + b_1 \\ a_2 + b_2 \\ \vdots \\ a_n + b_n \end{bmatrix}$$
     Sonuç yine $n \times 1$ boyutlu bir matris olduğundan $\mathbf{u} \oplus \mathbf{v} \in \mathbb{R}^n$'dir; yani $\mathbb{R}^n$, $\oplus$ işlemi altında **kapalıdır**.
     - **Özellik 1 (Değişme):** Matris toplamasının değişme özelliğinden $\mathbf{u} \oplus \mathbf{v} = \mathbf{v} \oplus \mathbf{u}$ sağlanır.
     - **Özellik 2 (Birleşme):** Matris toplamasının birleşme özelliğinden $\mathbf{u} \oplus (\mathbf{v} \oplus \mathbf{w}) = (\mathbf{u} \oplus \mathbf{v}) \oplus \mathbf{w}$ sağlanır.
     - **Özellik 3 (Sıfır Vektörü):** Bu kümenin sıfır elemanı (toplamsal birimi), tüm elemanları $0$ olan $n \times 1$ boyutlu sıfır matrisidir: $\mathbf{0} = \begin{bmatrix} 0 \\ \vdots \\ 0 \end{bmatrix}_{n \times 1} \in \mathbb{R}^n$.
     - **Özellik 4 (Toplamsal Ters):** Her $\mathbf{u} = \begin{bmatrix} a_1 \\ \vdots \\ a_n \end{bmatrix} \in \mathbb{R}^n$ için $-\mathbf{u} = \begin{bmatrix} -a_1 \\ \vdots \\ -a_n \end{bmatrix} \in \mathbb{R}^n$ elemanı mevcuttur ve $\mathbf{u} \oplus (-\mathbf{u}) = (-\mathbf{u}) \oplus \mathbf{u} = \mathbf{0}$ eşitliğini sağlar (ekrandan, 00:31:30).
  2. **$\odot$ Altında Kapalılık ve (5)–(8) Özellikleri:**
     Herhangi bir $\lambda \in \mathbb{R}$ skaleri ve $\mathbf{u} \in \mathbb{R}^n$ için $\lambda \odot \mathbf{u} = \begin{bmatrix} \lambda a_1 \\ \vdots \\ \lambda a_n \end{bmatrix}$ yine $n \times 1$ boyutlu bir reel matris olduğundan $\mathbb{R}^n$'dedir ($\odot$ altında kapalıdır). Matrislerde skalerle çarpmanın dağılma, birleşme ve $1 \odot \mathbf{u} = \mathbf{u}$ özellikleri de doğrudan sağlandığından $(\mathbb{R}^n, +, \cdot)$ bir vektör uzayıdır.

### 3.2 $M_{m \times n}$ Matrisler Uzayı, $\mathbb{R}$ Reel Sayılar Uzayı ve $R_n$ Satır Vektörleri Uzayı (Örnek 174, 175 ve 176)

- **Örnek 174 ($m \times n$ Matrisler Uzayı $M_{m \times n}$ — ekrandan, 00:33:05):**
  Tüm $m \times n$ boyutlu reel matrislerin kümesi, birinci işlem ($\oplus$) matris toplama ve ikinci işlem ($\odot$) matrisin bir reel sayıyla çarpımı olmak üzere bir vektör uzayıdır ve $M_{m \times n}$ ile gösterilir.
- **Örnek 175 (Reel Sayılar Uzayı $(\mathbb{R}, +, \cdot)$ — ekrandan, 00:34:30):**
  Tüm reel sayıların kümesi $\mathbb{R}$, birinci işlem ($\oplus$) reel sayıların olağan toplaması (usual addition) ve ikinci işlem ($\odot$) reel sayıların olağan çarpması (usual multiplication) olmak üzere bir vektör uzayıdır. Bu özel durumda reel sayılar **hem vektör hem de skaler** şeklinde ikili bir rol (dual roles) oynar; ayrıca bu uzay Örnek 173'teki $\mathbb{R}^n$ uzayının $n = 1$ özel durumudur.
- **Örnek 176 ($1 \times n$ Satır Matrisleri Uzayı $R_n$ — ekrandan, 00:34:30):**
  Tüm $1 \times n$ boyutlu $\begin{bmatrix} a_1 & a_2 & \dots & a_n \end{bmatrix}$ satır matrislerinin kümesi olan $R_n$, bileşen bazında matris toplama ve skalerle çarpma işlemleri altında bir vektör uzayıdır ($M_{m \times n}$ uzayının $m = 1$ özel halidir).

### 3.3 İzi Sıfır Olan $2 \times 2$ Matrisler Uzayı (Örnek 177)

- **Verilen (ekrandan, 00:34:30 ve 00:39:30):**
  $V$ kümesi, **izi (trace) sıfıra eşit olan** tüm $2 \times 2$ boyutlu matrislerin kümesi olsun:
  $$V = \left\{ A = \begin{bmatrix} a & b \\ c & d \end{bmatrix} \in M_{2 \times 2} \,\middle|\, \text{Tr}(A) = a + d = 0 \right\}$$
  Bir matrisin izi ($\text{Tr}(A)$), esas köşegen (main diagonal) üzerindeki elemanların toplamıdır. $\oplus$ standart matris toplama ve $\odot$ standart skalerle çarpma olmak üzere $V$'nin bir vektör uzayı olduğunu gösteriniz (Tanım 172'deki (a), (3), (4), (b) ve (7) özelliklerini doğrulayalım).

> **Soru-Cevap (derste sözlü, 00:44:17):**
> **Soru:** Bir kümenin vektör uzayı olması için her zaman matris izinin sıfır olması ($\text{Tr}(A) = 0$) gibi bir şart mı var?
> **Cevap:** Hayır, genel olarak vektör uzaylarında izle ilgili bir şart yoktur; yalnızca bu örnekte $V$ kümesi özel olarak "izi sıfır olan $2 \times 2$ matrisler" biçiminde tanımlandığı için bir matrisin $V$'ye ait olup olmadığını izinin sıfır olup olmadığıyla kontrol ediyoruz.

- **Adım Adım Doğrulama (ekrandan, 00:39:30–00:45:45):**
  1. **Özellik (a) — Toplamaya Göre Kapalılık:**
     $A = \begin{bmatrix} a & b \\ c & d \end{bmatrix} \in V$ ve $B = \begin{bmatrix} r & s \\ t & p \end{bmatrix} \in V$ herhangi iki eleman olsun. $A, B \in V$ olduğundan:
     $$\text{Tr}(A) = a + d = 0 \quad \text{ve} \quad \text{Tr}(B) = r + p = 0$$
     eşitlikleri sağlanır. Şimdi $A \oplus B$ toplamına bakalım:
     $$A \oplus B = \begin{bmatrix} a+r & b+s \\ c+t & d+p \end{bmatrix}$$
     Bu matris $2 \times 2$ boyutludur. $V$'de olup olmadığını anlamak için izini hesaplayalım:
     $$\text{Tr}(A \oplus B) = (a + r) + (d + p) = (a + d) + (r + p) = 0 + 0 = 0$$
     İzi $0$ çıktığından $A \oplus B \in V$'dir; yani $V$ kümesi $\oplus$ işlemi altında **kapalıdır**.
  2. **Özellik (3) — Sıfır Vektörü (Toplamsal Birim):**
     $A \oplus C = C \oplus A = A$ koşulunu sağlayan tek $2 \times 2$ matris, sıfır matrisi olan $\mathbf{0} = \begin{bmatrix} 0 & 0 \\ 0 & 0 \end{bmatrix}$ matrisidir. Bu matrisin izi $\text{Tr}(\mathbf{0}) = 0 + 0 = 0$ olduğundan $\mathbf{0} \in V$'dir ve Özellik (3) sağlanır.
  3. **Özellik (4) — Toplamsal Ters (Additive Inverse):**
     $A = \begin{bmatrix} a & b \\ c & d \end{bmatrix} \in V$ ($\text{Tr}(A) = a + d = 0$) için $A \oplus C = C \oplus A = \mathbf{0}$ şartını sağlayan matris $C = -A = \begin{bmatrix} -a & -b \\ -c & -d \end{bmatrix}$ matrisidir. Ancak $C = -A$ matrisinin de $V$'ye ait olduğunu mutlaka kontrol etmeliyiz:
     $$\text{Tr}(C) = -a + (-d) = -(a + d) = -0 = 0$$
     olduğundan $C = -A \in V$'dir ve Özellik (4) sağlanır.
  4. **Özellik (b) — Skalerle Çarpmaya Göre Kapalılık:**
     Herhangi bir $k \in \mathbb{R}$ skaleri ve $A \in V$ için:
     $$k \odot A = \begin{bmatrix} ka & kb \\ kc & kd \end{bmatrix}$$
     İzini kontrol edelim:
     $$\text{Tr}(k \odot A) = ka + kd = k(a + d) = k \cdot 0 = 0$$
     olduğundan $k \odot A \in V$'dir; yani $V$ kümesi $\odot$ altında **kapalıdır**.
  5. **Özellik (7) — Skaler Çarpımda Birleşme:**
     $k, m \in \mathbb{R}$ ve $A \in V$ için:
     $$k \odot (m \odot A) = k \odot \begin{bmatrix} ma & mb \\ mc & md \end{bmatrix} = \begin{bmatrix} k(ma) & k(mb) \\ k(mc) & k(md) \end{bmatrix} = \begin{bmatrix} (km)a & (km)b \\ (km)c & (km)d \end{bmatrix} = (km) \odot A$$
     Diğer özellikler de standart matris işlemlerinden sağlandığından $V$ bir vektör uzayıdır.

### 3.4 Derecesi En Çok $n$ Olan Polinomlar Uzayı $P_n$ (Örnek 178)

Vektör uzaylarının bir diğer çok önemli kaynağı **polinom kümeleridir** (sets of polynomials) (ekrandan, 00:50:30):

- **Polinom ve Polinomun Derecesi (Degree of a Polynomial):**
  $t$ değişkenine bağlı bir polinom, $a_0, a_1, \dots, a_n \in \mathbb{R}$ reel sayılar ve $n$ negatif olmayan bir tam sayı olmak üzere:
  $$p(t) = a_n t^n + a_{n-1} t^{n-1} + \dots + a_1 t + a_0$$
  biçiminde ifade edilebilen özel bir fonksiyondur. Eğer $a_n \neq 0$ ise $p(t)$ polinomunun **derecesi $n$'dir** (degree $n$) denir.
  - Bir polinomun derecesi, **sıfırdan farklı katsayıya sahip olan en yüksek kuvvetli terimin üssüdür**. Örneğin $p(t) = 2t + 1$ polinomunun derecesi $1$'dir; sıfırdan farklı sabit polinomun ($p(t) = 3$) derecesi $0$'dır.
  - **Sıfır Polinomu (Zero Polynomial):** Tüm katsayıları sıfır olan ve $\mathbf{0}$ ile gösterilen sıfır polinomunun ($p(t) = 0$) **derecesi yoktur (has no degree / tanımsızdır)**.

- **$P_n$ Polinomlar Kümesinin Tanımı ve Vektör Uzayı Olması (ekrandan, 00:50:30–00:56:45):**
  **$P_n$ kümesi**, derecesi $n$'den küçük veya $n$'ye eşit ($\le n$) olan tüm polinomlar ile **sıfır polinomunun** birleşiminden oluşan küme olarak tanımlanır.
  $p(t), q(t) \in P_n$ iki eleman olsun:
  $$p(t) = a_n t^n + a_{n-1} t^{n-1} + \dots + a_1 t + a_0, \quad q(t) = b_n t^n + b_{n-1} t^{n-1} + \dots + b_1 t + b_0$$
  - **Birinci İşlem ($\oplus$ — Polinom Toplama):** Aynı dereceli terimlerin katsayılarının toplanmasıyla tanımlanır:
    $$p(t) \oplus q(t) = (a_n + b_n)t^n + (a_{n-1} + b_{n-1})t^{n-1} + \dots + (a_1 + b_1)t + (a_0 + b_0)$$
  - **İkinci İşlem ($\odot$ — Polinomun Skalerle Çarpımı):** $c \in \mathbb{R}$ için tüm katsayıların $c$ ile çarpılmasıyla tanımlanır:
    $$c \odot p(t) = (ca_n)t^n + (ca_{n-1})t^{n-1} + \dots + (ca_1)t + (ca_0)$$
  - **Kapalılık ve Aksiyomların Doğrulanması:**
    - Derecesi $\le n$ olan iki polinom (veya sıfır polinomu) toplandığında yine derecesi $\le n$ olan bir polinom veya sıfır polinomu elde edilir ($p(t) \oplus q(t) \in P_n$, toplamaya göre kapalıdır).
    - Bir polinom $c \in \mathbb{R}$ ile çarpıldığında derecesi değişmez (veya $c=0$ ise sıfır polinomu olur), dolayısıyla $c \odot p(t) \in P_n$'dir (skalerle çarpmaya göre kapalıdır).
    - Reel sayı toplaması değişmeli ($a_i + b_i = b_i + a_i$) ve birleşmeli olduğundan Özellik (1) ($p(t) \oplus q(t) = q(t) \oplus p(t)$) ve Özellik (2) sağlanır.
    - Kümenin sıfır vektörü **sıfır polinomudur**: $\mathbf{0}(t) = 0t^n + \dots + 0t + 0 \in P_n$ (Özellik 3).
    - Her $p(t) \in P_n$ polinomunun toplamsal tersi $-p(t) = (-a_n)t^n + \dots + (-a_0) \in P_n$ polinomudur (Özellik 4).
    - Özellik (6) için: $(c + d) \odot p(t) = (c+d)a_n t^n + \dots + (c+d)a_0 = (ca_n t^n + \dots + ca_0) + (da_n t^n + \dots + da_0) = (c \odot p(t)) \oplus (d \odot p(t))$ eşitliği sağlanır. Diğer özellikler de benzer biçimde sağlandığından **$P_n$ bir vektör uzayıdır**.

### 3.5 Sürekli Fonksiyonlar Uzayı $C(-\infty, \infty)$ (Örnek 179)

- **Tanım (ekrandan, 00:57:30):**
  $V$ kümesi, $\mathbb{R}$ üzerinde tanımlı tüm reel değerli sürekli fonksiyonların (real-valued continuous functions defined on $\mathbb{R}$) kümesi olsun. $f, g \in V$ ve $c \in \mathbb{R}$ için:
  $$(f \oplus g)(t) = f(t) + g(t) \quad \text{ve} \quad (c \odot f)(t) = c f(t)$$
  olarak tanımlandığında $V$ bir vektör uzayıdır ve **$C(-\infty, \infty)$** ile gösterilir.

## 4. Vektör Uzayı Olmayan Kümeler ve Kontrol Sırası (Checklist)

Buraya kadar hep vektör uzayı olan örnekler gördük. Şimdi tüm kümelerin ve işlemlerin vektör uzayı oluşturmadığını gösteren iki karşıt örnek inceleyelim.

### 4.1 Çıkarma İşlemiyle Tanımlı Reel Sayılar Kümesi (Örnek 180)

- **Verilen (ekrandan, 00:57:30 ve 01:03:30):**
  $V = \mathbb{R}$ (tüm reel sayılar kümesi) üzerinde birinci işlem olağan çıkarma ($\mathbf{u} \oplus \mathbf{v} = u - v$) ve ikinci işlem olağan çarpma ($c \odot \mathbf{u} = cu$) olarak tanımlansın. $V$ bir vektör uzayı mıdır? Değilse Tanım 172'deki hangi özellikler sağlanmaz?
- **Çözüm:**
  1. **Kapalılık Kontrolü (a ve b):** İki reel sayının farkı ($u - v \in \mathbb{R}$) ve çarpımı ($cu \in \mathbb{R}$) yine birer reel sayı olduğundan **(a) ve (b) kapalılık koşulları sağlanır**.
  2. **Özellik (1) — Değişme Özelliği (Sağlanmaz):**
     $$\mathbf{u} \oplus \mathbf{v} = u - v \quad \text{ve} \quad \mathbf{v} \oplus \mathbf{u} = v - u$$
     Genel olarak $u - v \neq v - u$ olduğundan değişme özelliği **sağlanmaz**. (Tek bir özelliğin bile sağlanmaması $V$'nin vektör uzayı olmadığını söylemek için yeterlidir).
  3. **Özellik (3) — Sıfır Elemanı (Sağlanmaz):**
     Sıfır elemanı $\mathbf{v}$ öyle bir eleman olmalıdır ki her $\mathbf{u} \in V$ için $\mathbf{u} \oplus \mathbf{v} = \mathbf{u}$ ve aynı zamanda $\mathbf{v} \oplus \mathbf{u} = \mathbf{u}$ olsun. Burada $\mathbf{u} \oplus \mathbf{v} = u - v$ ve $\mathbf{v} \oplus \mathbf{u} = v - u$'dur. Eğer $v = 0$ seçersek $u - 0 = u$ sağlanır fakat $0 - u = -u \neq u$ olur! Dolayısıyla her iki taraftan da birim eleman olan bir **sıfır elemanı yoktur**; Özellik (3) (ve buna bağlı olarak Özellik 2 ve 4) **sağlanmaz**.
  4. **Özellik (6) — Skaler Toplamının Dağılması (Sağlanmaz):**
     Özellik (5), (7) ve (8) sağlansa da Özellik (6) sağlanmaz; çünkü:
     $$(c + d) \odot \mathbf{u} = (c + d)u = cu + du$$
     iken, sağ taraf:
     $$(c \odot \mathbf{u}) \oplus (d \odot \mathbf{u}) = cu \oplus du = cu - du$$
     olur ve genel olarak $cu + du \neq cu - du$'dur. Sonuç olarak $(V, \oplus, \odot)$ **bir vektör uzayı değildir**.

### 4.2 Tam Sayılar Kümesi $\mathbb{Z}$ (Örnek 181)

- **Verilen (ekrandan, 01:08:30):**
  $V = \mathbb{Z}$ tüm tam sayılar kümesi (set of all integers) olsun. $\oplus$ olağan toplama ve $\odot$ olağan çarpma olarak tanımlansın. $V = (\mathbb{Z}, +, \cdot)$ bir reel vektör uzayı mıdır?
- **Çözüm:**
  Hayır, **bir vektör uzayı değildir**. Çünkü $V = \mathbb{Z}$ kümesinden sıfırdan farklı herhangi bir tam sayı $\mathbf{u} \in \mathbb{Z}$ (örneğin $u = 1$) ve $\mathbb{R}$'den irrasyonel bir skaler olan $c = \sqrt{3} \in \mathbb{R}$ aldığımızda:
  $$c \odot \mathbf{u} = \sqrt{3}u \notin \mathbb{Z}$$
  olur (bir tam sayının $\sqrt{3}$ katı tam sayı değildir). Dolayısıyla **(b) skalerle çarpmaya göre kapalılık koşulu sağlanmaz** ve $V = \mathbb{Z}$ bir reel vektör uzayı değildir.

### 4.3 Bir Kümenin Vektör Uzayı Olup Olmadığını Kontrol Etme Sırası (Remark 182)

> **Hocanın vurgusu (Kontrol Listesi / Checklist — ekrandan, 01:03:30 ve 01:08:30):**
> Verilen bir $(V, \oplus, \odot)$ yapısının reel vektör uzayı olup olmadığını kontrol ederken 10 özelliği baştan sona rastgele incelemek yerine şu sıra takip edilmelidir:
> 1. **İlk Adım (Kapalılık):** Önce $V$'nin **(a) $\oplus$ işlemi altında** ve **(b) $\odot$ işlemi altında kapalı olup olmadığını** kontrol edin. Eğer küme bu iki işlemden birine göre bile kapalı değilse (Örnek 181'deki $\mathbb{Z}$ gibi), diğer hiçbir özelliğe bakmadan "vektör uzayı değildir" diyebilirsiniz.
> 2. **İkinci Adım (Sıfır Elemanı ve Toplamsal Ters):** Hem (a) hem (b) kapalılıkları sağlanıyorsa, hemen **Özellik (3)'ü (sıfır elemanının $\mathbf{0} \in V$ varlığını)** ve ardından **Özellik (4)'ü (toplamsal tersin $-\mathbf{u} \in V$ varlığını)** kontrol edin. Eğer Özellik (3) sağlanmıyorsa küme vektör uzayı değildir ve kalan özellikleri kontrol etmeye gerek kalmaz.

## 5. Alt Vektör Uzayları / Altuzaylar (Subspaces)

### 5.1 Altuzay Tanımı ve İki Koşullu Altuzay Teoremi (Definition 183 & Theorem 184)

Bir vektör uzayının yapısını incelerken, verilen bir vektör uzayının içinde yer alan ve aynı işlemler altında kendi başına da bir vektör uzayı oluşturan alt kümelerine özel bir isim verilir:

- **Tanım 183 (Alt Vektör Uzayı / Altuzay — ekrandan, 01:12:00):**
  $V$ bir vektör uzayı ve $W$, $V$'nin boş olmayan bir alt kümesi ($\emptyset \neq W \subseteq V$) olsun. Eğer $W$ kümesi, $V$ üzerinde tanımlı olan aynı $\oplus$ ve $\odot$ işlemlerine göre kendi başına bir vektör uzayı ise, $W$'ye $V$'nin bir **alt vektör uzayı (altuzayı / subspace)** denir.

Pratikte bir $W \subseteq V$ alt kümesinin altuzay olup olmadığını anlamak için Tanım 172'deki 10 özelliğin tamamını baştan kontrol etmeyiz; çünkü değişme, birleşme, dağılma gibi özellikler üst uzay $V$'den otomatik olarak miras alınır. Bunun yerine aşağıdaki çok önemli teoremi kullanırız:

- **Teorem 184 (Altuzay Teoremi — ekrandan, 01:15:30):**
  $V$, $\oplus$ ve $\odot$ işlemleriyle bir vektör uzayı ve $W$, $V$'nin boş olmayan bir alt kümesi ($W \subseteq (V, \oplus, \odot)$) olsun. $W$'nin $V$'nin bir **altuzayı (subspace)** olması için gerek ve yeter şart aşağıdaki **iki kapalılık koşulunun** sağlanmasıdır:
  - **(a) Toplamaya Göre Kapalılık:** $\mathbf{u}$ ve $\mathbf{v}$, $W$ içinde herhangi iki vektör ise, $\mathbf{u} \oplus \mathbf{v}$ de $W$ içindedir ($\forall \mathbf{u}, \mathbf{v} \in W \implies \mathbf{u} \oplus \mathbf{v} \in W$).
  - **(b) Skalerle Çarpmaya Göre Kapalılık:** $c \in \mathbb{R}$ herhangi bir reel sayı ve $\mathbf{u}$, $W$ içinde herhangi bir vektör ise, $c \odot \mathbf{u}$ da $W$ içindedir ($\forall c \in \mathbb{R}, \, \forall \mathbf{u} \in W \implies c \odot \mathbf{u} \in W$).

> **Hocanın vurgusu (Sıfır Vektörü Koşulu Hakkında Not):** Bazı kaynaklarda 3. bir koşul olarak "sıfır vektörünün alt kümeye ait olması ($\mathbf{0} \in W$)" da yazılır. Boş olmayan bir $W$ kümesinde (a) ve (b) koşulları sağlandığında ($c = 0$ alınırsa $0 \odot \mathbf{u} = \mathbf{0} \in W$ olacağından) bu iki koşul altuzay olduğunu kanıtlamak için tek başına yeterlidir. Ancak bir kümenin **altuzay olmadığını** hızlıca göstermek istediğimizde, önce sıfır vektörünün kümede olup olmadığına ($\mathbf{0} \in W$?) bakmak çok pratiktir; sıfır vektörü kümede yoksa o küme kesinlikle altuzay değildir.

### 5.2 Sıfır Altuzayı ve Polinom Altuzayları (Örnek 185, 186 ve 187)

- **Örnek 185 (Aşikar Altuzaylar ve Sıfır Altuzayı — ekrandan, 01:15:30):**
  Her $V$ vektör uzayının en az iki altuzayı vardır:
  1. Kendisi ($V$),
  2. Yalnızca sıfır vektöründen oluşan $\{\mathbf{0}\}$ alt kümesi. Çünkü her vektör uzayında $\mathbf{0} \oplus \mathbf{0} = \mathbf{0} \in \{\mathbf{0}\}$ ve $c \odot \mathbf{0} = \mathbf{0} \in \{\mathbf{0}\}$ olduğundan $\{\mathbf{0}\}$ her iki işlem altında kapalıdır. $\{\mathbf{0}\}$ altuzayına $V$'nin **sıfır altuzayı** (zero subspace) denir.

- **Örnek 186 ($P_2$ ve $P_n$ Polinom Altuzayları — ekrandan, 01:15:30):**
  $P$, tüm polinomların oluşturduğu vektör uzayı ve $P_2 \subseteq P$, derecesi $\le 2$ olan tüm polinomlar ile sıfır polinomundan oluşan alt küme olsun. Derecesi en çok $2$ olan iki polinomun toplamı ve bir reel sayıyla çarpımı yine derecesi en çok $2$ olan bir polinom (veya sıfır polinomu) olduğundan $P_2$, $\oplus$ ve $\odot$ altında kapalıdır; dolayısıyla $P_2$, $P$'nin bir **altuzayıdır**.
  Genel olarak derecesi $\le n$ olan polinomlar ile sıfır polinomunun kümesi olan **$P_n$, tüm polinomlar uzayı $P$'nin bir altuzayıdır; ayrıca $P_n$, $P_{n+1}$'in de bir altuzayıdır**.

- **Örnek 187 (Derecesi Tam Olarak $2$ Olan Polinomlar Kümesi — ekrandan, 01:15:30 ve 01:24:30):**
  - **Soru:** $V$, derecesi **tam olarak $2$'ye eşit olan** ($\deg(p) = 2$) tüm polinomların kümesi olsun ($V \subseteq P$). $V$, tüm polinomlar uzayı $P$'nin bir altuzayı mıdır?
  - **Çözüm:** Hayır, **$V$ bir altuzay değildir**. Çünkü $V$ kümesinden derecesi $2$ olan şu iki polinomu alalım:
    $$p(t) = 2t^2 + 3t + 1 \in V \quad \text{ve} \quad q(t) = -2t^2 + t + 2 \in V$$
    Bu iki polinomu topladığımızda $t^2$'li terimler birbirini götürür:
    $$p(t) + q(t) = (2t^2 + 3t + 1) + (-2t^2 + t + 2) = 4t + 3$$
    Toplam polinomu olan $4t + 3$'ün derecesi $1$'dir ($2$ değildir); dolayısıyla $p(t) + q(t) \notin V$'dir. $V$ kümesi toplamaya göre kapalı olmadığından $P$'nin bir altuzayı değildir.

### 5.3 $\mathbb{R}^3$, $M_{2 \times 2}(\mathbb{R})$ ve $\mathbb{R}^2$ İçinde Altuzay Örnekleri ve Altuzay Olmayan Küme Örneği

#### Örnek 1: $\mathbb{R}^3$ İçinde Bir Altuzay (Örnek 188)

- **Verilen (ekrandan, 01:27:30):**
  $a$ ve $b$ herhangi iki reel sayı olmak üzere $\mathbb{R}^3$ içindeki:
  $$W = \left\{ \begin{bmatrix} a \\ b \\ a+b \end{bmatrix} \,\middle|\, a, b \in \mathbb{R} \right\} \subseteq \mathbb{R}^3$$
  (üçüncü bileşeni ilk iki bileşeninin toplamına eşit olan vektörler) kümesinin $\mathbb{R}^3$'ün bir altuzayı olduğunu gösteriniz.
- **Çözüm:**
  Teorem 184'ün (a) ve (b) koşullarını kontrol edelim. $W$ içinde herhangi iki vektör alalım:
  $$\mathbf{u} = \begin{bmatrix} a_1 \\ b_1 \\ a_1 + b_1 \end{bmatrix} \in W \quad \text{ve} \quad \mathbf{v} = \begin{bmatrix} a_2 \\ b_2 \\ a_2 + b_2 \end{bmatrix} \in W$$
  1. **Toplamaya Göre Kapalılık (a):**
     $$\mathbf{u} \oplus \mathbf{v} = \begin{bmatrix} a_1 + a_2 \\ b_1 + b_2 \\ (a_1 + b_1) + (a_2 + b_2) \end{bmatrix} = \begin{bmatrix} a_1 + a_2 \\ b_1 + b_2 \\ (a_1 + a_2) + (b_1 + b_2) \end{bmatrix}$$
     (Not: Ders notunda sağdaki matrisin 2. satırında sehven $b_1 + a_2$ baskı hatası vardır, doğrusu soldaki gibi $b_1 + b_2$'dir). Burada $c_1 = a_1 + a_2 \in \mathbb{R}$ ve $c_2 = b_1 + b_2 \in \mathbb{R}$ dersek 3. bileşen $c_1 + c_2$ formundadır; dolayısıyla $\mathbf{u} \oplus \mathbf{v} \in W$'dir.
  2. **Skalerle Çarpmaya Göre Kapalılık (b):**
     Herhangi bir $c \in \mathbb{R}$ skaleri için:
     $$c \odot \mathbf{u} = c \odot \begin{bmatrix} a_1 \\ b_1 \\ a_1 + b_1 \end{bmatrix} = \begin{bmatrix} ca_1 \\ cb_1 \\ c(a_1 + b_1) \end{bmatrix} = \begin{bmatrix} ca_1 \\ cb_1 \\ ca_1 + cb_1 \end{bmatrix}$$
     Burada $x = ca_1$ ve $y = cb_1$ dersek 3. bileşen $x + y$ olduğundan $c \odot \mathbf{u} \in W$'dir. Her iki koşul da sağlandığından **$W$, $\mathbb{R}^3$'ün bir altuzayıdır**.

#### Örnek 2: $M_{2 \times 2}(\mathbb{R})$ İçinde Üst Üçgensel Özel Bir Altuzay

- **Verilen (ekrandan, 01:31:30):**
  $$B = \left\{ \begin{bmatrix} a & b \\ 0 & c \end{bmatrix} \,\middle|\, c = a + b, \, a, b, c \in \mathbb{R} \right\} \subseteq M_{2 \times 2}(\mathbb{R})$$
  kümesi $M_{2 \times 2}(\mathbb{R})$ vektör uzayının bir altuzayı mıdır?
- **Çözüm:**
  1. **Toplamaya Göre Kapalılık:** $B$'den iki matris alalım: $\begin{bmatrix} a & b \\ 0 & c \end{bmatrix} \in B$ ($c = a + b$) ve $\begin{bmatrix} x & y \\ 0 & z \end{bmatrix} \in B$ ($z = x + y$). Toplamları:
     $$\begin{bmatrix} a & b \\ 0 & c \end{bmatrix} + \begin{bmatrix} x & y \\ 0 & z \end{bmatrix} = \begin{bmatrix} a+x & b+y \\ 0 & c+z \end{bmatrix}$$
     Burada sağ alt eleman $c + z = (a + b) + (x + y) = (a + x) + (b + y)$ olup 1. satırdaki iki elemanın toplamına eşittir ve sol alt eleman $0$'dır. O halde toplam matrisi $B$'dedir.
  2. **Skalerle Çarpmaya Göre Kapalılık:** Her $r \in \mathbb{R}$ ve $\begin{bmatrix} a & b \\ 0 & c \end{bmatrix} \in B$ için:
     $$r \begin{bmatrix} a & b \\ 0 & c \end{bmatrix} = \begin{bmatrix} ra & rb \\ 0 & rc \end{bmatrix}$$
     $c = a + b$ olduğundan $rc = r(a + b) = ra + rb$ eşitliği sağlanır; dolayısıyla çarpım matrisi de $B$'dedir. (Ayrıca sıfır matrisi $\begin{bmatrix} 0 & 0 \\ 0 & 0 \end{bmatrix} \in B$'dir). Sonuç olarak **$B$, $M_{2 \times 2}(\mathbb{R})$'nin bir altuzayıdır**.

#### Örnek 3: $\mathbb{R}^2$ Düzleminde $x$-Ekseni Altuzayı

- **Verilen (ekrandan, 01:34:30):**
  $A = \{(x, 0) \mid x \in \mathbb{R}\} \subseteq \mathbb{R}^2$ kümesi $\mathbb{R}^2$'nin bir altuzayı mıdır?
- **Çözüm:**
  $\mathbf{u} = (x, 0) \in A$ ve $\mathbf{v} = (y, 0) \in A$ için:
  1. $\mathbf{u} + \mathbf{v} = (x, 0) + (y, 0) = (x + y, 0)$. Burada $z = x + y \in \mathbb{R}$ dersek $(z, 0) \in A$ olur.
  2. Her $c \in \mathbb{R}$ için $c\mathbf{u} = c(x, 0) = (cx, 0) \in A$ ($cx \in \mathbb{R}$ olduğundan).
  Her iki kapalılık şartı sağlandığından **$A$, $\mathbb{R}^2$'nin bir altuzayıdır**.

#### Örnek 4: $\mathbb{R}^3$ İçinde Altuzay Olmayan Küme ($a \ge 0$ Koşulu)

- **Verilen (ekrandan, 01:36:30):**
  $$W = \{(a, b, c) \mid a \ge 0 \text{ ve } a, b, c \in \mathbb{R}\} \subseteq \mathbb{R}^3$$
  kümesinin neden $\mathbb{R}^3$'ün bir altuzayı **olmadığını** açıklayınız.
- **Çözüm:**
  Negatif bir skaler, örneğin $k = -1 \in \mathbb{R}$ seçelim. $W$ kümesinden birinci bileşeni pozitif ($a > 0$) olan bir $\mathbf{u} = (a, b, c) \in W$ vektörü aldığımızda:
  $$k\mathbf{u} = (-1)(a, b, c) = (-a, -b, -c)$$
  elde edilir. Burada $a > 0$ olduğu için $-a < 0$ olur ve birinci bileşen negatif çıktığından $(-a, -b, -c) \notin W$'dir. Yani $W$ kümesi **skalerle çarpmaya göre kapalı değildir** ve bu nedenle $\mathbb{R}^3$'ün bir altuzayı değildir.

## Örnek Sorular

1. **Çıkarma İşlemli Reel Sayılar Kümesinin Vektör Uzayı Olup Olmadığının İncelenmesi** (ekrandan, 00:57:30 ve 01:03:30)
   - **Soru:** $V = \mathbb{R}$ kümesi üzerinde $\mathbf{u} \oplus \mathbf{v} = u - v$ (olağan çıkarma) ve $c \odot \mathbf{u} = cu$ (olağan çarpma) işlemleri tanımlanıyor. $(V, \oplus, \odot)$ bir vektör uzayı mıdır? Değilse hangi aksiyomlar sağlanmaz?
   - **Çözüm (derste verildi):** Vektör uzayı değildir. (a) ve (b) kapalılık koşulları ile (5), (7), (8) özellikleri sağlansa da:
     - Özellik (1) (değişme) sağlanmaz: $u \oplus v = u - v \neq v - u = v \oplus u$.
     - Özellik (2) (birleşme), Özellik (3) (sıfır vektörü: $u - v = v - u = u$ şartını sağlayan bir $v$ yoktur) ve Özellik (4) (toplamsal ters) sağlanmaz.
     - Özellik (6) sağlanmaz: $(c + d) \odot u = cu + du \neq cu - du = (c \odot u) \oplus (d \odot u)$.

2. **Derecesi Tam Olarak $2$ Olan Polinomlar Kümesinin Altuzay Testi** (ekrandan, 01:15:30 ve 01:24:30)
   - **Soru:** Tüm polinomlar vektör uzayı $P$ içinde, derecesi tam olarak $2$'ye eşit olan polinomların kümesi $V$ bir altuzay mıdır?
   - **Çözüm (derste verildi):** Hayır, altuzay değildir. Örneğin $p(t) = 2t^2 + 3t + 1 \in V$ ve $q(t) = -2t^2 + t + 2 \in V$ polinomlarının her ikisi de $2$. derecedendir; ancak toplamları $p(t) + q(t) = 4t + 3$ olup $1$. dereceden bir polinomdur ($V$'ye ait değildir). Toplamaya göre kapalı olmadığından altuzay değildir.

3. **Birinci Bileşeni Negatif Olmayan Vektörler Kümesinin Altuzay Testi** (ekrandan ve derste sözlü, 01:36:30)
   - **Soru:** $W = \{(a, b, c) \mid a \ge 0 \text{ ve } a, b, c \in \mathbb{R}\} \subseteq \mathbb{R}^3$ kümesi neden $\mathbb{R}^3$'ün bir altuzayı değildir?
   - **Çözüm (derste verildi):** $W$ kümesi skalerle çarpmaya göre kapalı değildir. Örneğin $a > 0$ olan bir $\mathbf{u} = (a, b, c) \in W$ vektörü $c = -1 \in \mathbb{R}$ skaleri ile çarpıldığında $(-1)\mathbf{u} = (-a, -b, -c)$ vektörünün birinci bileşeni $-a < 0$ olur ve $W$ kümesinin dışına çıkar.

## Dersin Toparlaması

Bu derste ilk olarak $Ax = b$ doğrusal denklem sistemlerini çözmek için kullanılan Gauss/Gauss-Jordan eliminasyonu ($\approx n^3/3$ işlem), ters matris yöntemi ($\approx n^3$ işlem) ve Cramer kuralının ($\approx n^4/3$ işlem) büyük $n$ değerleri için işlem karmaşıklıkları karşılaştırılmış ve en verimli yöntemin Gauss/Gauss-Jordan eliminasyonu olduğu vurgulanmıştır. Ardından soyut lineer cebirin temel yapı taşı olan **reel vektör uzayı** (real vector space) kavramı ve 10 aksiyomu (2 kapalılık koşulu + 8 özellik) tanımlanmış; $\mathbb{R}^n$, $M_{m \times n}$, $\mathbb{R}$, $R_n$, izi sıfır olan $2 \times 2$ matrisler kümesi, derecesi $\le n$ olan polinomlar uzayı $P_n$ ve sürekli fonksiyonlar uzayı $C(-\infty, \infty)$ örnekleri ayrıntılı olarak incelenmiştir. Çıkarma işlemli $\mathbb{R}$ ve tam sayılar kümesi $\mathbb{Z}$ üzerinden vektör uzayı olmayan yapılar ve kontrol sırası (checklist) gösterildikten sonra, **alt vektör uzayı (altuzay / subspace)** kavramına geçilmiş ve bir alt kümenin altuzay olması için yalnızca toplamaya ve skalerle çarpmaya göre kapalı olmasının (Teorem 184) yeterli olduğu kanıtlanarak polinom, matris ve $\mathbb{R}^n$ alt kümeleri üzerinde uygulamalar yapılmıştır.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
