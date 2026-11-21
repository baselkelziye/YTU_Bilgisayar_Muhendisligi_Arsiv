# Ders 1 Genişletilmiş Notu: Matris Tanımı, Özel Matrisler, Temel Matris İşlemleri ve Devrik Matris

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Matris Kavramı ve Temel Gösterimler
- 2. Özel Matris Türleri ve Vektörler
- 3. Matrislerin Eşitliği
- 4. Matrisin İzi (Trace)
- 5. Temel Matris İşlemleri: Toplama, Skaler Çarpma ve Çıkarma
- 6. Toplam Sembolü (Summation Notation)
- 7. Matrisin Devriği (Transpose of a Matrix)
- Örnek Sorular
- Dersin Toparlaması

## 1. Matris Kavramı ve Temel Gösterimler

Hoca derse, doğrusal denklem sistemlerini (linear equations) çözmede matrislerin (matrices) çok önemli bir araç olduğunu belirterek başladı. Doğrusal denklem sistemlerini çözmeye geçmeden önce matris kavramının ve matrisler üzerindeki temel işlemlerin tanımlanması gerekir.

Bir $m \times n$ ($m$ by $n$) matris $A$, $m$ adet yatay satır (row) ve $n$ adet dikey sütun (column) halinde düzenlenmiş $m \cdot n$ adet reel (real) veya karmaşık (complex) sayıdan oluşan dikdörtgensel bir sayı dizisidir (rectangular array). Matrisler genellikle $A, B, C$ gibi büyük harflerle gösterilir (ekrandan, 00:16:30):

$$A = \begin{bmatrix} a_{11} & a_{12} & \dots & a_{1n} \\ a_{21} & a_{22} & \dots & a_{2n} \\ \vdots & \vdots & \ddots & \vdots \\ a_{m1} & a_{m2} & \dots & a_{mn} \end{bmatrix}$$

### 1.1 Satır, Sütun ve Eleman İndisleri

Bir $A$ matrisinde yatay dizilere satır (row), dikey dizilere ise sütun (column) denir. $A$ matrisinin $i$. satırı (i-th row) ve $j$. sütunu (j-th column) ayrı ayrı şu şekilde gösterilir (ekrandan, 00:16:30):

- **$i$. satır:** $\begin{bmatrix} a_{i1} & a_{i2} & \dots & a_{in} \end{bmatrix}$ ($1 \le i \le m$)
- **$j$. sütun:** $\begin{bmatrix} a_{1j} \\ a_{2j} \\ \vdots \\ a_{mj} \end{bmatrix}$ ($1 \le j \le n$)

$m$ satırı ve $n$ sütunu olan bir $A$ matrisinin boyutunun $m \times n$ ($m$ by $n$) olduğu söylenir. Matrisin $i$. satırı ve $j$. sütununun kesişiminde bulunan $a_{ij}$ sayısına $A$'nın $i, j$. elemanı ($ij$-th element / $(i, j)$ entry of $A$) denir ve matris kısaca $A = [a_{ij}]$ biçiminde yazılır (ekrandan, 00:23:45).

> **Hocanın vurgusu:** Matrisin boyutu veya bir elemanın indisi yazılırken her zaman **önce satır (row), sonra sütun (column)** yazılır. Dolayısıyla $2 \times 3$ boyutlu bir matris ile $3 \times 2$ boyutlu bir matris aynı şey değildir.

## 2. Özel Matris Türleri ve Vektörler

### 2.1 Kare Matris ve Esas Köşegen

Bir $A$ matrisinde satır sayısı sütun sayısına eşitse ($m = n$), bu matrise **kare matris** (square matrix) veya $n$. mertebeden kare matris (square matrix of order $n$) denir. $n$. mertebeden bir kare matriste satır ve sütun indisi birbirine eşit olan $a_{11}, a_{22}, \dots, a_{nn}$ (yani $a_{ii}$ biçimindeki) elemanların oluşturduğu köşegene matrisin **esas köşegeni** (main diagonal) adı verilir.

### 2.2 Sayısal Matris Örnekleri ve Boyut İncelemesi

Hoca, matris türlerini ve eleman indislerini somutlaştırmak için altı farklı matris örneği yazdı (ekrandan, 00:28:15):

$$A = \begin{bmatrix} 1 & 2 & 3 \\ -1 & 0 & 1 \end{bmatrix}_{2 \times 3}, \quad B = \begin{bmatrix} 1+i & 4i \\ 2-3i & -3 \end{bmatrix}_{2 \times 2}, \quad C = \begin{bmatrix} 1 \\ 1 \\ 2 \end{bmatrix}_{3 \times 1}$$

$$D = \begin{bmatrix} 1 & 1 & 0 \\ 2 & 0 & 1 \\ 3 & -1 & 2 \end{bmatrix}_{3 \times 3}, \quad E = [3]_{1 \times 1}, \quad F = \begin{bmatrix} -1 & 0 & 2 \end{bmatrix}_{1 \times 3}$$

Bu matrislerin özellikleri adım adım şöyle incelendi:

- **$A$ matrisi:** $2$ satırı ve $3$ sütunu olduğundan $2 \times 3$ boyutlu bir matristir. Elemanları konumlarına göre $a_{11} = 1$, $a_{12} = 2$ (1. satır, 2. sütun), $a_{13} = 3$ (1. satır, 3. sütun), $a_{21} = -1$ (2. satır, 1. sütun), $a_{22} = 0$ ve $a_{23} = 1$ değerleridir.
- **$B$ matrisi:** Elemanları arasında karmaşık sayılar (complex numbers) bulunduğu için **karmaşık matris** (complex matrix) olarak adlandırılır. Aynı zamanda $2$ satırı ve $2$ sütunu olduğundan $2 \times 2$ boyutlu bir kare matristir.
- **$C$ matrisi:** $3$ satırı ve yalnızca $1$ sütunu olduğundan $3 \times 1$ boyutlu bir matristir.
- **$D$ matrisi:** $3$ satırı ve $3$ sütunu olan $3 \times 3$ boyutlu ($3$. mertebeden) bir kare matristir. Esas köşegeni sol üstten sağ alta inen $a_{11}=1, a_{22}=0, a_{33}=2$ elemanlarından oluşur.
- **$E$ matrisi:** Yalnızca tek bir elemanı vardır; $1 \times 1$ boyutlu bir matristir.
- **$F$ matrisi:** Yalnızca $1$ satırı ve $3$ sütunu vardır; $1 \times 3$ boyutlu bir matristir.

Bu örneklerin incelenmesi sırasında öğrencilerle hoca arasında şu soru-cevaplar gerçekleşti:

**Soru:** İlk matris ($A$) $3 \times 2$ değil midir? Önce sütun sonra satır söylenmez mi?
**Cevap:** Hayır, her zaman önce satır, ardından sütun yazılır. $A$ matrisinin $2$ satırı ve $3$ sütunu olduğu için boyutu $2 \times 3$'tür ve bu $3 \times 2$ matrisle aynı değildir.

**Soru:** Satır ve sütun sayısı çok fazla olduğunda (örneğin iki basamaklı sayılar olduğunda) indisler nasıl yazılır?
**Cevap:** Karışıklığı önlemek için satır ve sütun indislerinin arasına virgül konulur. Örneğin $3$. satır ve $32$. sütundaki eleman $a_{3,32}$ biçiminde yazılır (ekrandan, 00:28:15).

**Soru:** $D$ matrisi örneğinde esas köşegen olarak diğer köşegeni ($0, 0, 3$ elemanlarını) seçebilir miyiz?
**Cevap:** Hayır, esas köşegen (main diagonal) tanım gereği satır ve sütun indisi aynı olan ($a_{11}, a_{22}, a_{33}$) elemanlardan oluşur.

**Soru:** $0 \times 0$ boyutunda bir matris var mıdır?
**Cevap:** Hayır, $0 \times 0$ matris diye bir şey yoktur.

**Soru:** $4 \times 3$ gibi kare olmayan bir matriste esas köşegen var mıdır?
**Cevap:** Hayır, esas köşegen yalnızca kare matrisler (square matrices) için tanımlıdır; kare olmayan matrislerin esas köşegeni yoktur.

### 2.3 Vektörler ($m$-Vektör) ve Sıfır Matrisi

Tek sütundan oluşan $m \times 1$ boyutlu matrislere genellikle **$m$-vektör** ($m$-vector) veya sütun vektörü denir. Örneğin yukarıdaki $C$ matrisi $3 \times 1$ boyutlu bir matris olduğundan aynı zamanda bir vektör (veya $3$-vektör) olarak adlandırılır. Benzer şekilde yalnızca tek bir satırdan oluşan yatay matrislere ($1 \times n$) de satır vektörü (row vector / row matrix) denir.

> **Hocanın vurgusu:** $A$ bir $m \times n$ matris ise, $A$'nın her bir sütunu $m \times 1$ boyutlu bir matris (sütun vektörü), her bir satırı ise $1 \times n$ boyutlu bir matristir (satır vektörü) (ekrandan, 00:36:15).

Tüm elemanları $0$ olan bir matrise **sıfır matrisi** (zero matrix), tüm elemanları $0$ olan bir $m$-vektöre ise **sıfır vektörü** (zero vector) denir ve her ikisi de $0$ sembolüyle gösterilir. Sıfır matrisi dikdörtgen veya kare olabilir (ekrandan, 00:36:15):

$$0 = \begin{bmatrix} 0 & 0 & 0 \\ 0 & 0 & 0 \end{bmatrix}_{2 \times 3} \text{ (2x3 sıfır matrisi)}, \quad 0 = \begin{bmatrix} 0 & 0 \\ 0 & 0 \end{bmatrix}_{2 \times 2} \text{ (2x2 kare sıfır matrisi)}$$

$$0 = \begin{bmatrix} 0 \\ 0 \\ 0 \end{bmatrix} \text{ (3 uzunluklu sıfır sütun vektörü)}, \quad 0 = \begin{bmatrix} 0 & 0 & 0 \end{bmatrix} \text{ (sıfır satır vektörü)}$$

## 3. Matrislerin Eşitliği

İki matrisin birbirine eşit olması için aynı boyutta olmaları ve karşılıklı tüm elemanlarının birebir aynı olması gerekir (ekrandan, 00:42:15):

- **Tanım:** Aynı boyuttaki ($m \times n$) iki matris $A = [a_{ij}]$ ve $B = [b_{ij}]$, her $i = 1, 2, \dots, m$ ve $j = 1, 2, \dots, n$ için $a_{ij} = b_{ij}$ koşulunu sağlıyorsa (yani eleman eleman uyuşuyorsa / agree entry by entry) birbirine eşittir ($A = B$).

### 3.1 Matris Eşitliği Örneği

Hoca, matris eşitliğini göstermek için şu sayısal örneği çözdü (ekrandan, 00:42:15):

- **Verilen:**
  $$A = \begin{bmatrix} 1 & 2 & -1 \\ 2 & -3 & 4 \\ 0 & -4 & 5 \end{bmatrix}_{3 \times 3}, \quad B = \begin{bmatrix} 1 & 2 & w \\ 2 & x & 4 \\ y & -4 & z \end{bmatrix}_{3 \times 3}$$
  $A = B$ olduğuna göre $x, y, z$ ve $w$ değerlerini bulunuz.
- **Çözüm:**
  1. Öncelikle her iki matrisin de $3$ satırı ve $3$ sütunu vardır; yani ikisi de $3 \times 3$ boyutlu ($3$. mertebeden kare) matristir ve boyutları eşittir.
  2. $A = B$ olduğundan karşılıklı elemanlar birbirine eşit olmalıdır ($a_{ij} = b_{ij}$):
     - $1$. satır $1$. sütun: $a_{11} = b_{11} = 1$ ve $1$. satır $2$. sütun: $a_{12} = b_{12} = 2$.
     - $1$. satır $3$. sütun: $b_{13} = a_{13} \implies w = -1$.
     - $2$. satır $2$. sütun: $b_{22} = a_{22} \implies x = -3$.
     - $3$. satır $1$. sütun: $b_{31} = a_{31} \implies y = 0$.
     - $3$. satır $3$. sütun: $b_{33} = a_{33} \implies z = 5$.
  3. **Sonuç:** $w = -1$, $x = -3$, $y = 0$, $z = 5$.

## 4. Matrisin İzi (Trace)

Kare matrisler için tanımlanan bir diğer önemli kavram matrisin izidir (trace of a matrix) (ekrandan, 00:46:00):

- **Tanım:** $A$ matrisi $n$. mertebeden ($n \times n$ boyutlu) bir kare matris olmak üzere, $A$'nın esas köşegeni (main diagonal) üzerindeki tüm elemanların toplamına $A$ matrisinin **izi** (trace of $A$) denir ve $\text{Tr}(A)$ ile gösterilir:
  $$\text{Tr}(A) = a_{11} + a_{22} + \dots + a_{nn}$$

$$A = \begin{bmatrix} a_{11} & a_{12} & \dots & a_{1n} \\ a_{21} & a_{22} & \dots & a_{2n} \\ \vdots & \vdots & \ddots & \vdots \\ a_{n1} & a_{n2} & \dots & a_{nn} \end{bmatrix} \implies \text{Tr}(A) = a_{11} + a_{22} + \dots + a_{nn}$$

## 5. Temel Matris İşlemleri: Toplama, Skaler Çarpma ve Çıkarma

Doğrusal denklem sistemleriyle uğraşırken denklemleri tekrar tekrar yazmak yerine ortaya çıkan matrisleri cebirsel olarak işlemek (manipulate) için matris işlemleri kullanılır.

### 5.1 Matris Toplamı (Matrix Addition)

$A = [a_{ij}]$ ve $B = [b_{ij}]$ aynı boyutta ($m \times n$) iki matris olsun. Bu iki matrisin toplamı olan $A + B$, her $i = 1, \dots, m$ ve $j = 1, \dots, n$ için karşılıklı elemanların toplanmasıyla tanımlanan $m \times n$ boyutlu $C = [c_{ij}]$ matrisidir:

$$c_{ij} = a_{ij} + b_{ij}$$

Açık matris formunda toplam işlemi şu şekildedir (ekrandan, 00:56:15):

$$A + B = \begin{bmatrix} a_{11}+b_{11} & a_{12}+b_{12} & \dots & a_{1n}+b_{1n} \\ a_{21}+b_{21} & a_{22}+b_{22} & \dots & a_{2n}+b_{2n} \\ \vdots & \vdots & \ddots & \vdots \\ a_{m1}+b_{m1} & a_{m2}+b_{m2} & \dots & a_{mn}+b_{mn} \end{bmatrix}$$

> **Hocanın vurgusu:** İki matrisin toplamı ($A + B$), **yalnızca** $A$ ve $B$ matrisleri aynı satır sayısına ve aynı sütun sayısına sahipse (yani aynı boyuttaysa) tanımlıdır. Boyutları farklı olan iki matris toplanamaz. Aynı boyutta olmak şartıyla üç, beş veya daha fazla matris de toplanabilir.

#### Matris Toplamı Örneği

Hoca matris toplamı için şu örneği çözdü (ekrandan, 00:56:15):

- **Verilen:**
  $$A = \begin{bmatrix} 1 & -2 & 3 \\ 2 & -1 & 4 \end{bmatrix}_{2 \times 3}, \quad B = \begin{bmatrix} 0 & 2 & 1 \\ 1 & 3 & -4 \end{bmatrix}_{2 \times 3}$$
- **İşlem:** Her iki matris de $2 \times 3$ boyutlu olduğundan karşılıklı elemanlar toplanır:
  $$A + B = \begin{bmatrix} a_{11}+b_{11} & a_{12}+b_{12} & a_{13}+b_{13} \\ a_{21}+b_{21} & a_{22}+b_{22} & a_{23}+b_{23} \end{bmatrix} = \begin{bmatrix} 1+0 & -2+2 & 3+1 \\ 2+1 & -1+3 & 4+(-4) \end{bmatrix}$$
- **Sonuç:**
  $$A + B = \begin{bmatrix} 1 & 0 & 4 \\ 3 & 2 & 0 \end{bmatrix}_{2 \times 3}$$

**Soru:** Bir matrisin kendi içindeki satırlarını ve sütunlarını birbiriyle toplayabilir miyiz?
**Cevap:** Evet, matrisin satırları ve sütunları üzerinde işlemler yapabiliriz ancak bunu şimdi değil, ilerleyen derslerde (satır/sütun işlemlerinde) göreceğiz.

### 5.2 Skaler ile Çarpma (Scalar Multiplication)

$A = [a_{ij}]$ bir $m \times n$ matris ve $r$ bir reel sayı (skaler / sabit) olsun. $A$ matrisinin $r$ ile skaler çarpımı olan $rA$, $A$'nın her bir elemanının $r$ ile çarpılmasıyla elde edilen $m \times n$ boyutlu $C = [c_{ij}]$ matrisidir (ekrandan, 01:06:00):

$$c_{ij} = r \cdot a_{ij}$$

$$rA = \begin{bmatrix} r a_{11} & r a_{12} & \dots & r a_{1n} \\ \vdots & \vdots & \ddots & \vdots \\ r a_{m1} & r a_{m2} & \dots & r a_{mn} \end{bmatrix}$$

**Soru:** İki matrisi birbiriyle çarpabilir miyiz? Ayrıca skaler çarpımda negatif sayılar veya kesirli (rasyonel) sayılar kullanılabilir mi?
**Cevap:** İki matrisi birbiriyle çarpabiliriz ancak şu an yalnızca bir sayı (skaler) ile matrisin çarpımını tanımlıyoruz; matris çarpımını daha sonra tanımlayacağız. Skaler çarpımda kullanılan $r$ sayısı pozitif, negatif, tam sayı veya kesirli (fractional) herhangi bir reel sayı olabilir.

#### Skaler ile Çarpma Örneği

Hoca skaler çarpım için şu örneği çözdü (ekrandan, 01:06:00):

- **Verilen:**
  $$A = \begin{bmatrix} 4 & -2 & -3 \\ 7 & -3 & 2 \end{bmatrix}_{2 \times 3}$$
  matrisi için $-2A$ matrisini bulunuz.
- **İşlem:** $A$ matrisinin her bir elemanı $r = -2$ skaleri ile çarpılır:
  $$-2A = \begin{bmatrix} (-2)\cdot 4 & (-2)\cdot (-2) & (-2)\cdot (-3) \\ (-2)\cdot 7 & (-2)\cdot (-3) & (-2)\cdot 2 \end{bmatrix}$$
- **Sonuç:**
  $$-2A = \begin{bmatrix} -8 & 4 & 6 \\ -14 & 6 & -4 \end{bmatrix}_{2 \times 3}$$
  Görüldüğü gibi $A$ matrisi $2 \times 3$ boyutlu olduğunda $rA$ matrisi de yine $2 \times 3$ boyutludur.

### 5.3 İki Matrisin Farkı (Difference of Matrices)

Matris toplamı ve skaler ile çarpma tanımlandıktan sonra aynı boyuttaki ($m \times n$) iki matrisin farkı da bu iki işlem üzerinden tanımlanır (ekrandan, 01:10:05):

- **Tanım:** $A$ ve $B$ aynı boyutta iki matris olmak üzere, $A$ ile $B$ arasındaki fark $A - B$ ile gösterilir ve
  $$A - B = A + (-1)B$$
  olarak tanımlanır. Yani $B$ matrisi $-1$ skaleri ile çarpılıp $A$ matrisiyle toplanır (karşılıklı elemanlar birbirinden çıkarılır).

#### Matris Farkı Örneği

Hoca matris çıkarma işlemi için şu örneği çözdü (ekrandan, 01:10:05):

- **Verilen:**
  $$A = \begin{bmatrix} 2 & 3 & -5 \\ 4 & 2 & 1 \end{bmatrix}_{2 \times 3}, \quad B = \begin{bmatrix} 2 & -1 & 3 \\ 3 & 5 & -2 \end{bmatrix}_{2 \times 3}$$
- **İşlem:** Karşılıklı elemanların farkı alınır:
  $$A - B = \begin{bmatrix} 2-2 & 3-(-1) & -5-3 \\ 4-3 & 2-5 & 1-(-2) \end{bmatrix}$$
- **Sonuç:**
  $$A - B = \begin{bmatrix} 0 & 4 & -8 \\ 1 & -3 & 3 \end{bmatrix}_{2 \times 3}$$

## 6. Toplam Sembolü (Summation Notation)

Hoca, ilerleyen konulardaki matris hesaplamalarında (özellikle matris çarpımında) kullanılacağı için toplam sembolünü (summation notation) hatırlattı (ekrandan, 01:13:30):

$$\sum_{i=1}^{n} a_i = a_1 + a_2 + \dots + a_n$$

Burada Yunan harfi $\Sigma$ (sigma) toplamı, $i$ harfi ise **toplam indisini** (index of summation) gösterir. Toplam indisi $1$'den başlayıp $n$'ye kadar değer alan bir takma değişkendir (dummy variable) ve $j$ veya $k$ gibi başka bir harfle değiştirildiğinde toplamın değeri değişmez:

$$\sum_{i=1}^{n} u_i = \sum_{j=1}^{n} u_j = \sum_{k=1}^{n} u_k$$

Örneğin $n = 4$ için açılım şu şekildedir (ekrandan, 01:13:30):

$$\sum_{i=1}^{4} a_i = a_1 + a_2 + a_3 + a_4$$

## 7. Matrisin Devriği (Transpose of a Matrix)

Dersin son ana konusu matrisin devriğidir (transpose of a matrix) (ekrandan, 01:15:30):

- **Tanım:** $A = [a_{ij}]$ bir $m \times n$ matris ise, $A$'nın **devriği** (transpose of $A$), $A^T = [a_{ij}^T]$ ile gösterilen ve
  $$a_{ij}^T = a_{ji}$$
  kuralıyla tanımlanan $n \times m$ boyutlu matristir.

Başka bir deyişle, $A^T$ matrisi, $A$ matrisinin satırları ile sütunlarının yer değiştirmesiyle (interchanging rows and columns) elde edilir: $A$'nın 1. satırı $A^T$'nin 1. sütunu, $A$'nın 2. satırı $A^T$'nin 2. sütunu olur.

**Soru:** Sadece tek bir sayı dizisinden oluşan matrisin (satır veya sütun matrisinin) devriği nasıl alınır?
**Cevap:** Yalnızca tek satırdan oluşan bir satır matrisinin ($1 \times n$) devriği alındığında tek sütundan oluşan bir sütun matrisi ($n \times 1$) elde edilir. Tersine, bir sütun matrisinin ($m \times 1$) devriği alındığında bir satır matrisi ($1 \times m$) elde edilir.

### 7.1 Devrik Matris Örnekleri

Hoca beş farklı matris vererek her birinin devriğini adım adım buldu (ekrandan, 01:24:20):

1. **$2 \times 3$ boyutlu $A$ matrisi:**
   $$A = \begin{bmatrix} 4 & -2 & 3 \\ 0 & 5 & -2 \end{bmatrix}_{2 \times 3}$$
   $A$ matrisi $2 \times 3$ boyutlu olduğundan devriği olan $A^T$ matrisi $3 \times 2$ boyutlu olur. $A$'nın 1. satırı $[4\ -2\ 3]$, $A^T$'nin 1. sütunu; 2. satırı $[0\ 5\ -2]$ ise $A^T$'nin 2. sütunu olarak yazılır:
   $$A^T = \begin{bmatrix} 4 & 0 \\ -2 & 5 \\ 3 & -2 \end{bmatrix}_{3 \times 2}$$

2. **$3 \times 3$ boyutlu $B$ kare matrisi:**
   $$B = \begin{bmatrix} 6 & 2 & -4 \\ 3 & -1 & 2 \\ 0 & 4 & 3 \end{bmatrix}_{3 \times 3}$$
   $B$'nin 1. sütunu $B^T$'nin 1. satırı, 2. sütunu $B^T$'nin 2. satırı ve 3. sütunu $B^T$'nin 3. satırı yapılarak yazılır:
   $$B^T = \begin{bmatrix} 6 & 3 & 0 \\ 2 & -1 & 4 \\ -4 & 2 & 3 \end{bmatrix}_{3 \times 3}$$

3. **$3 \times 2$ boyutlu $C$ matrisi:**
   $$C = \begin{bmatrix} 5 & 4 \\ -3 & 2 \\ 2 & -3 \end{bmatrix}_{3 \times 2}$$
   $C$'nin 1. sütunu $C^T$'nin 1. satırı, 2. sütunu ise $C^T$'nin 2. satırı yapılır:
   $$C^T = \begin{bmatrix} 5 & -3 & 2 \\ 4 & 2 & -3 \end{bmatrix}_{2 \times 3}$$

> **Ders sonrası not:** Hoca $C^T$ matrisinin ikinci satırını sözlü olarak okurken "4, 2, 3" demiş, ancak tahtaya doğru biçimde $4, 2, -3$ yazmıştır (ekrandan, 01:24:20).

4. **$1 \times 3$ boyutlu $D$ satır matrisi:**
   $$D = \begin{bmatrix} 3 & -5 & 1 \end{bmatrix}_{1 \times 3} \implies D^T = \begin{bmatrix} 3 \\ -5 \\ 1 \end{bmatrix}_{3 \times 1}$$

5. **$3 \times 1$ boyutlu $E$ sütun matrisi:**
   $$E = \begin{bmatrix} 2 \\ -1 \\ 3 \end{bmatrix}_{3 \times 1} \implies E^T = \begin{bmatrix} 2 & -1 & 3 \end{bmatrix}_{1 \times 3}$$

## Örnek Sorular

### Soru 1: Matris Eşitliğinden Bilinmeyenleri Bulma (ekrandan, 00:42:15)

**Soru:**
$$A = \begin{bmatrix} 1 & 2 & -1 \\ 2 & -3 & 4 \\ 0 & -4 & 5 \end{bmatrix}, \quad B = \begin{bmatrix} 1 & 2 & w \\ 2 & x & 4 \\ y & -4 & z \end{bmatrix}$$
matrisleri için $A = B$ ise $x, y, z$ ve $w$ değerlerini bulunuz.

**Çözüm:**
Her iki matris de $3 \times 3$ boyutludur. İki matrisin eşitliği tanımı gereği karşılıklı elemanlar birbirine eşittir ($a_{ij} = b_{ij}$):
- $b_{13} = a_{13} \implies w = -1$
- $b_{22} = a_{22} \implies x = -3$
- $b_{31} = a_{31} \implies y = 0$
- $b_{33} = a_{33} \implies z = 5$

### Soru 2: Matris Toplamı (ekrandan, 00:56:15)

**Soru:**
$$A = \begin{bmatrix} 1 & -2 & 3 \\ 2 & -1 & 4 \end{bmatrix}, \quad B = \begin{bmatrix} 0 & 2 & 1 \\ 1 & 3 & -4 \end{bmatrix}$$
matrislerinin toplamı olan $A + B$ matrisini hesaplayınız.

**Çözüm:**
Her iki matris de $2 \times 3$ boyutlu olduğundan karşılıklı elemanlar toplanır:
$$A + B = \begin{bmatrix} 1+0 & -2+2 & 3+1 \\ 2+1 & -1+3 & 4+(-4) \end{bmatrix} = \begin{bmatrix} 1 & 0 & 4 \\ 3 & 2 & 0 \end{bmatrix}$$

### Soru 3: Skaler ile Çarpma (ekrandan, 01:06:00)

**Soru:**
$$A = \begin{bmatrix} 4 & -2 & -3 \\ 7 & -3 & 2 \end{bmatrix}$$
matrisi için $-2A$ matrisini bulunuz.

**Çözüm:**
$A$ matrisinin tüm elemanları $-2$ ile çarpılır:
$$-2A = \begin{bmatrix} (-2)(4) & (-2)(-2) & (-2)(-3) \\ (-2)(7) & (-2)(-3) & (-2)(2) \end{bmatrix} = \begin{bmatrix} -8 & 4 & 6 \\ -14 & 6 & -4 \end{bmatrix}$$

### Soru 4: İki Matrisin Farkı (ekrandan, 01:10:05)

**Soru:**
$$A = \begin{bmatrix} 2 & 3 & -5 \\ 4 & 2 & 1 \end{bmatrix}, \quad B = \begin{bmatrix} 2 & -1 & 3 \\ 3 & 5 & -2 \end{bmatrix}$$
matrisleri için $A - B$ fark matrisini hesaplayınız.

**Çözüm:**
$A - B = A + (-1)B$ tanımına göre karşılıklı elemanlar birbirinden çıkarılır:
$$A - B = \begin{bmatrix} 2-2 & 3-(-1) & -5-3 \\ 4-3 & 2-5 & 1-(-2) \end{bmatrix} = \begin{bmatrix} 0 & 4 & -8 \\ 1 & -3 & 3 \end{bmatrix}$$

### Soru 5: Matrislerin Devriğini (Transpose) Bulma (ekrandan, 01:24:20)

**Soru:**
Aşağıdaki matrislerin devriklerini ($A^T, B^T, C^T, D^T, E^T$) bulunuz:
$$A = \begin{bmatrix} 4 & -2 & 3 \\ 0 & 5 & -2 \end{bmatrix}, \quad B = \begin{bmatrix} 6 & 2 & -4 \\ 3 & -1 & 2 \\ 0 & 4 & 3 \end{bmatrix}, \quad C = \begin{bmatrix} 5 & 4 \\ -3 & 2 \\ 2 & -3 \end{bmatrix}, \quad D = \begin{bmatrix} 3 & -5 & 1 \end{bmatrix}, \quad E = \begin{bmatrix} 2 \\ -1 \\ 3 \end{bmatrix}$$

**Çözüm:**
Her matrisin satırları ile sütunları yer değiştirilir:
$$A^T = \begin{bmatrix} 4 & 0 \\ -2 & 5 \\ 3 & -2 \end{bmatrix}_{3 \times 2}, \quad B^T = \begin{bmatrix} 6 & 3 & 0 \\ 2 & -1 & 4 \\ -4 & 2 & 3 \end{bmatrix}_{3 \times 3}, \quad C^T = \begin{bmatrix} 5 & -3 & 2 \\ 4 & 2 & -3 \end{bmatrix}_{2 \times 3}$$
$$D^T = \begin{bmatrix} 3 \\ -5 \\ 1 \end{bmatrix}_{3 \times 1}, \quad E^T = \begin{bmatrix} 2 & -1 & 3 \end{bmatrix}_{1 \times 3}$$

## Dersin Toparlaması

Bu derste doğrusal denklem sistemlerinin çözümüne temel oluşturmak üzere matris kavramı, $m \times n$ matris boyutu, satır ve sütun gösterimleri, kare matris, esas köşegen (main diagonal), $m$-vektör (sütun ve satır vektörleri) ve sıfır matrisi tanımlandı. Ardından iki matrisin eşitliği, bir kare matrisin izi ($\text{Tr}(A)$), aynı boyutlu matrislerde toplama ve çıkarma işlemleri, bir matrisin reel bir skalerle çarpımı, toplam sembolü ($\Sigma$) ve bir matrisin satırları ile sütunlarının yer değiştirmesiyle elde edilen devriği ($A^T$) sayısal örneklerle işlendi. Bir sonraki derste matrislerin birbiriyle çarpımı (matrix multiplication) konusuyla devam edileceği belirtildi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
