# Ders 4 Genişletilmiş Notu: Elementer Satır İşlemleriyle Ters Matris Bulma, Tekil Matrisler, Determinant, Sarrus Kuralı ve Laplace Açılımı

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Elementer Satır İşlemleriyle Matrisin Tersini Bulma
- 2. Tekil (Singular) Matrisler ve Matrisin Rankı
- 3. Determinant Kavramı: $1 \times 1$, $2 \times 2$ ve $3 \times 3$ Matrislerin Determinantı
- 4. Sarrus Kuralı (Rule of Sarrus)
- 5. Minör (Minor) ve Kofaktör (Cofactor) Kavramları
- 6. Laplace (Kofaktör) Açılımı (Laplace Expansion)
- Örnek Sorular
- Dersin Toparlaması

## 1. Elementer Satır İşlemleriyle Matrisin Tersini Bulma

Hoca derse geçen hafta matrislerin satır eşelon formunun (REF) ve indirgenmiş satır eşelon formunun (RREF) tanımlandığını ve her matrisin elementer satır işlemleri kullanılarak bu özel forma dönüştürülebildiğini hatırlatarak başladı. Bu derste ilk olarak elementer satır işlemleri yardımıyla bir kare matrisin tersinin ($A^{-1}$) nasıl bulunacağı ele alındı.

Bir $n \times n$ boyutlu $A$ kare matrisi için aşağıdaki iki ifade birbirine denktir (ekrandan, 00:08:00):

1. $A$ matrisi **tekil olmayan** (nonsingular) bir matristir; yani $A$ tersinirdir (invertible) ve $A^{-1}$ mevcuttur.
2. $A$ matrisi $I_n$ birim matrisine satırca (veya sütunca) denktir (row/column equivalent to $I_n$); başka bir deyişle **$A$ matrisinin indirgenmiş satır eşelon formu (RREF) $I_n$ birim matrisidir**.

Bu denklikten şu sonuç çıkar: Eğer bir $n \times n$ boyutlu $A$ kare matrisinin tersi ($A^{-1}$) mevcutsa, $A$ matrisini $I_n$ birim matrisine indirgeyen bir dizi elementer satır işlemi vardır.

### 1.1 $[A \mid I_n]$ Yöntemi

Tekil olmayan (nonsingular) bir $A$ matrisinin tersini bulmak için $A$ matrisi ile aynı boyuttaki $I_n$ birim matrisi yan yana (side-by-side) yazılarak $[A \mid I_n]$ matrisi oluşturulur. Ardından elementer satır işlemleri kullanılarak sol taraftaki $A$ matrisi indirgenmiş satır eşelon formuna, yani $I_n$ birim matrisine dönüştürülür. Sol tarafa uygulanan her satır işlemi eşzamanlı olarak sağ tarafa da uygulandığında, sol taraf $I_n$ olduğunda sağ tarafta $A^{-1}$ matrisi elde edilir (ekrandan, 00:12:55):

$$[A \mid I_n] \xrightarrow{\text{Elementer satır işlemleri}} [I_n \mid A^{-1}]$$

**Soru:** Bu işlemleri yaparken satırları sütunlara ekleyebilir miyiz veya hem satır hem sütun işlemi kullanabilir miyiz?
**Cevap:** Hayır. Bir işlemde yalnızca satır işlemleri (veya yalnızca sütun işlemleri) kullanılabilir; hem satır hem sütun işlemleri aynı anda kesinlikle kullanılamaz ve bir satır bir sütuna eklenemez. Karışıklığı önlemek için yalnızca elementer satır işlemlerini kullanmanız önerilir.

### 1.2 Elementer Satır İşlemleriyle Ters Matris Bulma Örneği

Hoca yöntemin nasıl çalıştığını göstermek için $3 \times 3$ boyutlu bir matrisin tersini adım adım hesapladı ve sağlamasını yaptı (ekrandan, 00:19:15, 00:24:00 ve 00:28:00):

- **Verilen:**
  $$A = \begin{pmatrix} 3 & 3 & 6 \\ 2 & 3 & 0 \\ 0 & 0 & 1 \end{pmatrix}$$
  matrisinin tersini ($A^{-1}$) elementer satır işlemlerini kullanarak bulunuz.

- **1. Adım ($[A \mid I_3]$ matrisinin kurulması ve 1. satırda öncü $1$ elde edilmesi):**
  Sol tarafa $A$, sağ tarafa $3 \times 3$ boyutlu $I_3$ birim matrisi yazılır:
  $$\left[\begin{array}{ccc|ccc} 3 & 3 & 6 & 1 & 0 & 0 \\ 2 & 3 & 0 & 0 & 1 & 0 \\ 0 & 0 & 1 & 0 & 0 & 1 \end{array}\right]$$
  Sol tarafı birim matrise dönüştürmek istiyoruz. 3. satırın sol tarafı zaten $(0\ \ 0\ \ 1)$ biçimindedir. Sol üst köşede ($a_{11}$ konumunda) $1$ elde etmek için 1. satırın tamamı $\frac{1}{3}$ ile çarpılır ($\frac{1}{3}r_1 \to r_1$):
  $$\xrightarrow{\frac{1}{3}r_1 \to r_1} \left[\begin{array}{ccc|ccc} 1 & 1 & 2 & \frac{1}{3} & 0 & 0 \\ 2 & 3 & 0 & 0 & 1 & 0 \\ 0 & 0 & 1 & 0 & 0 & 1 \end{array}\right]$$

- **2. Adım (1. sütundaki pivotun altındaki $2$ elemanını sıfırlama):**
  1. satır $-2$ ile çarpılıp 2. satıra eklenir ($-2r_1 + r_2 \to r_2$).
  - 2. satırın sol tarafı: $(-2)(1)+2 = 0$, $(-2)(1)+3 = 1$, $(-2)(2)+0 = -4$.
  - 2. satırın sağ tarafı: $(-2)(\frac{1}{3})+0 = -\frac{2}{3}$, $(-2)(0)+1 = 1$, $(-2)(0)+0 = 0$.
  $$\xrightarrow{-2r_1 + r_2 \to r_2} \left[\begin{array}{ccc|ccc} 1 & 1 & 2 & \frac{1}{3} & 0 & 0 \\ 0 & 1 & -4 & -\frac{2}{3} & 1 & 0 \\ 0 & 0 & 1 & 0 & 0 & 1 \end{array}\right]$$

- **3. Adım (2. sütundaki öncü $1$'in üstündeki $1$ elemanını sıfırlama):**
  2. satır $-1$ ile çarpılıp 1. satıra eklenir ($-r_2 + r_1 \to r_1$):
  - 1. satırın sol tarafı: $0+1 = 1$, $-1+1 = 0$, $-(-4)+2 = 6$.
  - 1. satırın sağ tarafı: $-(-\frac{2}{3})+\frac{1}{3} = \frac{3}{3} = 1$, $-1+0 = -1$, $0+0 = 0$.
  $$\xrightarrow{-r_2 + r_1 \to r_1} \left[\begin{array}{ccc|ccc} 1 & 0 & 6 & 1 & -1 & 0 \\ 0 & 1 & -4 & -\frac{2}{3} & 1 & 0 \\ 0 & 0 & 1 & 0 & 0 & 1 \end{array}\right]$$

- **4. Adım (3. sütundaki öncü $1$'in üstündeki $-4$ ve $6$ elemanlarını sıfırlama):**
  3. satır $4$ ile çarpılıp 2. satıra eklenir ($4r_3 + r_2 \to r_2$) ve 3. satır $-6$ ile çarpılıp 1. satıra eklenir ($-6r_3 + r_1 \to r_1$):
  - 2. satır: sol taraf $(0\ \ 1\ \ 0)$, sağ taraf $(-\frac{2}{3}\ \ 1\ \ 4)$.
  - 1. satır: sol taraf $(1\ \ 0\ \ 0)$, sağ taraf $(1\ \ -1\ \ -6)$.
  $$\xrightarrow[\ -6r_3 + r_1 \to r_1\ ]{4r_3 + r_2 \to r_2} \left[\begin{array}{ccc|ccc} 1 & 0 & 0 & 1 & -1 & -6 \\ 0 & 1 & 0 & -\frac{2}{3} & 1 & 4 \\ 0 & 0 & 1 & 0 & 0 & 1 \end{array}\right]$$
  Sol tarafta $I_3$ birim matrisi elde edildiğinden sağ taraftaki matris $A^{-1}$ matrisidir:
  $$A^{-1} = \begin{pmatrix} 1 & -1 & -6 \\ -\frac{2}{3} & 1 & 4 \\ 0 & 0 & 1 \end{pmatrix}$$

- **5. Adım (Sağlama - $A A^{-1} = I_3$ Kontrolü):**
  Hoca bulunan matrisin gerçekten $A$'nın tersi olup olmadığını kontrol etmek için $A$ ile $A^{-1}$ matrisini çarptı (ekrandan, 00:28:00):
  $$A A^{-1} = \begin{pmatrix} 3 & 3 & 6 \\ 2 & 3 & 0 \\ 0 & 0 & 1 \end{pmatrix} \begin{pmatrix} 1 & -1 & -6 \\ -\frac{2}{3} & 1 & 4 \\ 0 & 0 & 1 \end{pmatrix}$$
  - 1. satır:
    - $(3)(1) + (3)(-\frac{2}{3}) + (6)(0) = 3 - 2 + 0 = 1$
    - $(3)(-1) + (3)(1) + (6)(0) = -3 + 3 + 0 = 0$
    - $(3)(-6) + (3)(4) + (6)(1) = -18 + 12 + 6 = 0$
  - 2. satır:
    - $(2)(1) + (3)(-\frac{2}{3}) + (0)(0) = 2 - 2 + 0 = 0$
    - $(2)(-1) + (3)(1) + (0)(0) = -2 + 3 + 0 = 1$
    - $(2)(-6) + (3)(4) + (0)(1) = -12 + 12 + 0 = 0$
  - 3. satır:
    - $(0)(1) + (0)(-\frac{2}{3}) + (1)(0) = 0$
    - $(0)(-1) + (0)(1) + (1)(0) = 0$
    - $(0)(-6) + (0)(4) + (1)(1) = 1$
  $$A A^{-1} = \begin{pmatrix} 1 & 0 & 0 \\ 0 & 1 & 0 \\ 0 & 0 & 1 \end{pmatrix} = I_3$$
  Sonuç birim matris olduğundan işlem doğrudur.

## 2. Tekil (Singular) Matrisler ve Matrisin Rankı

### 2.1 Tekil Matris Teoremi

Bir matrisin tersi yoksa (non-invertible) o matrise **tekil matris** (singular matrix) denir.

- **Teorem:** Bir $n \times n$ boyutlu $A$ kare matrisinin tekil (singular) olması için gerek ve yeter şart (if and only if), $A$ matrisinin **tamamen sıfırlardan oluşan bir satıra (a row of zeros) sahip bir $B$ matrisine satırca denk olmasıdır**.

> **Hocanın vurgusu:** Bir $A$ matrisinin tersini alıp alamayacağımızı başlangıçta bilmiyor olabiliriz. $[A \mid I_n]$ matrisini yazıp $A^{-1}$'i hesaplamaya başladığımızda, işlemlerin herhangi bir adımında sol tarafta tamamen sıfırlardan oluşan bir satır (zero row) ortaya çıkarsa hesaplamayı hemen durdururuz ve $A^{-1}$'in mevcut olmadığını, yani $A$'nın **tekil (singular)** bir matris olduğunu söyleriz.

### 2.2 Matrisin Rankı (Rank of a Matrix)

Bir matrisin satır eşelon formundaki (REF) veya indirgenmiş satır eşelon formundaki (RREF) **sıfırdan farklı satırların sayısına** (the number of non-zero rows) o matrisin **rankı** (rank of the matrix) denir.

Örneğin yukarıdaki örnekte $3 \times 3$ boyutlu $A$ matrisinin indirgenmiş satır eşelon formu $I_3 = \begin{pmatrix} 1 & 0 & 0 \\ 0 & 1 & 0 \\ 0 & 0 & 1 \end{pmatrix}$ olarak bulunmuştu. Bu formda sıfırdan farklı $3$ satır bulunduğundan $\text{rank}(A) = 3$'tür (ekrandan, 00:35:45).

## 3. Determinant Kavramı: $1 \times 1$, $2 \times 2$ ve $3 \times 3$ Matrislerin Determinantı

Determinantlar doğrusal denklem sistemlerinin çözümünde ortaya çıkan, kare matrislerin satırları üzerinde tanımlı özel fonksiyonlardır. $n$. mertebeden bir $A = [a_{ij}]_{n \times n}$ kare matrisinin determinantı $\det(A)$ veya $|A|$ (mutlak değer çizgileri arasında $A$) ile gösterilir (ekrandan, 00:39:00):

- **$n = 1$ ($1 \times 1$ kare matris) için:**
  Tek elemanlı $A = [a]_{1 \times 1}$ matrisinin determinantı kendi elemanına eşittir:
  $$\det(A) = a$$

- **$n = 2$ ($2 \times 2$ kare matris) için:**
  $$A = \begin{pmatrix} a_{11} & a_{12} \\ a_{21} & a_{22} \end{pmatrix}_{2 \times 2} \implies \det(A) = a_{11}a_{22} - a_{12}a_{21}$$
  Yani önce esas köşegen üzerindeki elemanlar çarpılır ($a_{11}a_{22}$) ve bu çarpımdan diğer köşegen üzerindeki elemanların çarpımı ($a_{12}a_{21}$) çıkarılır.

- **$n = 3$ ($3 \times 3$ kare matris) için:**
  $$A = \begin{pmatrix} a_{11} & a_{12} & a_{13} \\ a_{21} & a_{22} & a_{23} \\ a_{31} & a_{32} & a_{33} \end{pmatrix}_{3 \times 3}$$
  matrisinin determinantı 1. satır elemanları kullanılarak $2 \times 2$ determinantlar cinsinden şöyle yazılır (ekrandan, 00:44:00):
  1. İlk eleman $a_{11}$ yazılır; $a_{11}$'in bulunduğu 1. satır ve 1. sütun silinerek kalan $2 \times 2$ matrisin determinantıyla çarpılır.
  2. İkinci eleman $a_{12}$'nin önüne eksi işareti konulur ($-a_{12}$); 1. satır ve 2. sütun silinerek kalan $2 \times 2$ matrisin determinantıyla çarpılır.
  3. Üçüncü eleman $a_{13}$'ün önüne artı işareti konulur ($+a_{13}$); 1. satır ve 3. sütun silinerek kalan $2 \times 2$ matrisin determinantıyla çarpılır:
  $$\det(A) = a_{11}\begin{vmatrix} a_{22} & a_{23} \\ a_{32} & a_{33} \end{vmatrix} - a_{12}\begin{vmatrix} a_{21} & a_{23} \\ a_{31} & a_{33} \end{vmatrix} + a_{13}\begin{vmatrix} a_{21} & a_{22} \\ a_{31} & a_{32} \end{vmatrix}$$
  $$= a_{11}(a_{22}a_{33} - a_{23}a_{32}) - a_{12}(a_{21}a_{33} - a_{23}a_{31}) + a_{13}(a_{21}a_{32} - a_{22}a_{31})$$

Buradaki $+, -, +$ işaret örüntüsü, elemanların satır ve sütun indislerinin toplamından gelen $(-1)^{1+1} = +1$, $(-1)^{1+2} = -1$ ve $(-1)^{1+3} = +1$ çarpanlarından kaynaklanır (ekrandan, 00:44:00).

## 4. Sarrus Kuralı (Rule of Sarrus)

$n > 3$ boyutlu matrislere geçmeden önce hoca, **yalnızca $3 \times 3$ boyutlu matrislerin** determinantını hesaplamak için kullanılan **Sarrus kuralını** (Rule of Sarrus) anlattı (ekrandan, 00:50:00):

1. $3 \times 3$ boyutlu $A$ matrisinin **1. ve 2. satırları matrisin altına** tekrar yazılır:
   $$\begin{matrix} a_{11} & a_{12} & a_{13} \\ a_{21} & a_{22} & a_{23} \\ a_{31} & a_{32} & a_{33} \\ a_{11} & a_{12} & a_{13} \\ a_{21} & a_{22} & a_{23} \end{matrix}$$
2. Soldan sağa (sol üstten sağ alta) doğru inen üç tam köşegen üzerindeki elemanların çarpımları toplanır ($+$ işaretli terimler):
   $$+(a_{11}a_{22}a_{33} + a_{21}a_{32}a_{13} + a_{31}a_{12}a_{23})$$
3. Sağdan sola (sağ üstten sol alta) doğru inen üç tam köşegen üzerindeki elemanların çarpımları bu toplamdan çıkarılır ($-$ işaretli terimler):
   $$-(a_{13}a_{22}a_{31} + a_{23}a_{32}a_{11} + a_{33}a_{12}a_{21})$$
4. Böylece $3 \times 3$ matrisin determinantı elde edilir:
   $$|A| = a_{11}a_{22}a_{33} + a_{21}a_{32}a_{13} + a_{31}a_{12}a_{23} - a_{13}a_{22}a_{31} - a_{23}a_{32}a_{11} - a_{33}a_{12}a_{21}$$

Aynı kural, ilk iki satırı matrisin altına yazmak yerine **ilk iki sütunu matrisin sağına** tekrar yazıp yine soldan sağa köşegen çarpımlarını toplayarak ve sağdan sola köşegen çarpımlarını çıkararak da uygulanabilir.

> **Hocanın vurgusu:** Sarrus kuralı **yalnızca $3 \times 3$ boyutlu matrisler için** kullanılabilir; $4 \times 4$ veya daha yüksek mertebeli matrislerde geçerli değildir.

## 5. Minör (Minor) ve Kofaktör (Cofactor) Kavramları

Herhangi bir $n \times n$ matrisin determinantını hesaplayabilen genel yöntem olan Laplace açılımını tanımlamak için önce bir elemanın **minörü** ve **kofaktörü** tanımlanır (ekrandan, 01:03:20):

- **Alt Matris ($M_{ij}$) ve Minör Tanımı:** $A = [a_{ij}]$ bir $n \times n$ kare matris olsun. $A$ matrisinin $i$. satırı ve $j$. sütunu silinerek (deleting the $i$-th row and $j$-th column) elde edilen $(n-1) \times (n-1)$ boyutlu matrise $M_{ij}$ diyelim. Bu $M_{ij}$ matrisinin determinantına $a_{ij}$ elemanının **$(i, j)$. minörü** ($(i, j)$-th minor) denir.
- **Kofaktör Tanımı:** $a_{ij}$ elemanının **$(i, j)$. kofaktörü** ($(i, j)$-th cofactor) büyük $A_{ij}$ harfi ile gösterilir ve
  $$A_{ij} = (-1)^{i+j}\det(M_{ij})$$
  olarak tanımlanır.

> **Ders sonrası not:** Hoca slayttaki tanımda hem alt matrisin hem de onun determinantı olan minörün $M_{ij}$ ile gösterilmesinin bir dizgi hatası (typo) olduğunu belirterek, $M_{ij}$'yi $(n-1) \times (n-1)$ boyutlu alt matris, $\det(M_{ij})$'yi ise $a_{ij}$'nin minörü olarak yazmıştır (ekrandan, 01:03:20).

### 5.1 Minör ve Kofaktör Bulma Örneği

Hoca minör ve kofaktör hesabını şu örnek üzerinde gösterdi (ekrandan, 01:03:20):

- **Verilen:**
  $$A = \begin{pmatrix} 1 & 2 & 3 \\ 4 & 5 & 6 \\ 7 & 8 & 9 \end{pmatrix}$$
  matrisinde $a_{23}$ elemanının minörünü ve kofaktörünü bulunuz.
- **Çözüm:**
  1. $A$ matrisinin 2. satırı ve 3. sütunu silinerek $2 \times 2$ boyutlu $M_{23}$ alt matrisi oluşturulur:
     $$M_{23} = \begin{pmatrix} 1 & 2 \\ 7 & 8 \end{pmatrix}$$
  2. $a_{23}$ elemanının minörü, $M_{23}$ matrisinin determinantıdır:
     $$\text{Minör}(a_{23}) = \det(M_{23}) = \det\begin{pmatrix} 1 & 2 \\ 7 & 8 \end{pmatrix} = (1)(8) - (2)(7) = 8 - 14 = -6$$
  3. $a_{23}$ elemanının kofaktörü ($A_{23}$), minörün $(-1)^{2+3}$ ile çarpımıdır:
     $$A_{23} = (-1)^{2+3}\det(M_{23}) = (-1)^5(-6) = (-1)(-6) = 6$$

## 6. Laplace (Kofaktör) Açılımı (Laplace Expansion)

Minör ve kofaktör tanımlandıktan sonra $2 \times 2$, $3 \times 3$, $4 \times 4$ ve genel olarak herhangi bir $n \times n$ kare matrisin determinantını hesaplamak için **Laplace açılımı** (Laplace expansion / cofactor expansion) kullanılır:

1. Matrisin herhangi bir satırı veya sütunu seçilir.
2. Seçilen satır veya sütundaki her bir $a_{ij}$ elemanı için $A_{ij}$ kofaktörü hesaplanır.
3. Seçilen satır veya sütundaki her bir $a_{ij}$ elemanı kendi $A_{ij}$ kofaktörü ile çarpılıp toplanır:
   - **$i$. satır boyunca Laplace açılımı:**
     $$\det(A) = \sum_{k=1}^{n} a_{ik}A_{ik} = a_{i1}A_{i1} + a_{i2}A_{i2} + \dots + a_{in}A_{in}$$
   - **$j$. sütun boyunca Laplace açılımı:**
     $$\det(A) = \sum_{k=1}^{n} a_{kj}A_{kj} = a_{1j}A_{1j} + a_{2j}A_{2j} + \dots + a_{nj}A_{nj}$$

> **Hocanın vurgusu:** Laplace açılımında hangi satırı veya sütunu seçerseniz seçin aynı determinant sonucunu bulursunuz. Ancak işlem kolaylığı açısından **en fazla sayıda sıfır ($0$) içeren satırı veya sütunu seçmek** en doğrusudur. Çünkü $a_{ij} = 0$ olan bir eleman kendi kofaktörü $A_{ij}$ ile çarpıldığında sonuç $0$ olacağından, sıfır olan elemanların kofaktörlerini hesaplamaya gerek kalmaz.

### 6.1 Farklı Satır veya Sütunun Kofaktörleriyle Çarpım Özelliği

Hoca, ileride ek matris (adjoint matrix) yardımıyla ters matris bulurken kullanılacak çok önemli bir özelliği vurguladı (ekrandan, 01:08:30):

- **Not:** Eğer bir $i$. satırın elemanları, kendi kofaktörleri yerine **farklı bir $j$. satırın** ($i \neq j$) kofaktörleri ile çarpılıp toplanırsa (veya $i$. sütunun elemanları farklı bir $j$. sütunun kofaktörleriyle çarpılıp toplanırsa) sonuç daima **sıfır** olur:
  $$i \neq j \text{ için:} \quad \sum_{k=1}^{n} a_{ik}A_{jk} = 0 \quad \text{ve} \quad \sum_{k=1}^{n} a_{ki}A_{kj} = 0$$

### 6.2 Laplace Açılımı ile Determinant Hesaplama Örneği

Hoca dersin son örneği olarak $3 \times 3$ boyutlu bir matrisin determinantını Laplace açılımıyla hesapladı (ekrandan, 01:18:20):

- **Verilen:**
  $$A = \begin{pmatrix} 2 & 1 & 3 \\ -1 & 2 & 1 \\ -2 & 2 & 3 \end{pmatrix}$$
  matrisinin determinantını Laplace açılımı ile bulunuz.
- **Satır Seçimi:** Matrise bakıldığında hiçbir satır veya sütunda $0$ elemanı yoktur; bu nedenle istediğimiz herhangi bir satır veya sütunu seçebiliriz. 1. satırı (first row) seçelim:
  $$\det(A) = a_{11}A_{11} + a_{12}A_{12} + a_{13}A_{13}$$
  Burada 1. satır elemanları $a_{11} = 2$, $a_{12} = 1$ ve $a_{13} = 3$'tür.
- **Kofaktörlerin Hesaplanması:**
  - $A_{11}$ (1. satır ve 1. sütun silinir):
    $$A_{11} = (-1)^{1+1}\begin{vmatrix} 2 & 1 \\ 2 & 3 \end{vmatrix} = (+1)\cdot(2\cdot 3 - 1\cdot 2) = 6 - 2 = 4$$
  - $A_{12}$ (1. satır ve 2. sütun silinir):
    $$A_{12} = (-1)^{1+2}\begin{vmatrix} -1 & 1 \\ -2 & 3 \end{vmatrix} = (-1)\cdot((-1)(3) - (1)(-2)) = (-1)\cdot(-3 + 2) = (-1)(-1) = 1$$
  - $A_{13}$ (1. satır ve 3. sütun silinir):
    $$A_{13} = (-1)^{1+3}\begin{vmatrix} -1 & 2 \\ -2 & 2 \end{vmatrix} = (+1)\cdot((-1)(2) - (2)(-2)) = -2 - (-4) = 2$$
- **Determinantın Hesaplanması:**
  $$\det(A) = a_{11}A_{11} + a_{12}A_{12} + a_{13}A_{13} = 2 \cdot 4 + 1 \cdot 1 + 3 \cdot 2 = 8 + 1 + 6 = 15$$
- **$i \neq j$ Özelliğinin Doğrulanması:**
  Eğer 2. satırın elemanlarını ($a_{21}=-1, a_{22}=2, a_{23}=1$) 1. satırın kofaktörleriyle ($A_{11}=4, A_{12}=1, A_{13}=2$) çarpıp toplarsak:
  $$a_{21}A_{11} + a_{22}A_{12} + a_{23}A_{13} = (-1)(4) + (2)(1) + (1)(2) = -4 + 2 + 2 = 0$$
  olduğu görülür.

## Örnek Sorular

### Soru 1: Elementer Satır İşlemleriyle Ters Matris ve Rank Bulma (ekrandan, 00:19:15 ve 00:24:00)

**Soru:**
$$A = \begin{pmatrix} 3 & 3 & 6 \\ 2 & 3 & 0 \\ 0 & 0 & 1 \end{pmatrix}$$
matrisinin tersini ($A^{-1}$) elementer satır işlemlerini kullanarak bulunuz ve $A$ matrisinin rankını belirtiniz.

**Çözüm:**
$[A \mid I_3]$ matrisi yazılıp sol taraf birim matrise indirgenir:
$$\left[\begin{array}{ccc|ccc} 3 & 3 & 6 & 1 & 0 & 0 \\ 2 & 3 & 0 & 0 & 1 & 0 \\ 0 & 0 & 1 & 0 & 0 & 1 \end{array}\right] \xrightarrow{\frac{1}{3}r_1 \to r_1} \left[\begin{array}{ccc|ccc} 1 & 1 & 2 & \frac{1}{3} & 0 & 0 \\ 2 & 3 & 0 & 0 & 1 & 0 \\ 0 & 0 & 1 & 0 & 0 & 1 \end{array}\right] \xrightarrow{-2r_1 + r_2 \to r_2} \left[\begin{array}{ccc|ccc} 1 & 1 & 2 & \frac{1}{3} & 0 & 0 \\ 0 & 1 & -4 & -\frac{2}{3} & 1 & 0 \\ 0 & 0 & 1 & 0 & 0 & 1 \end{array}\right]$$
$$\xrightarrow{-r_2 + r_1 \to r_1} \left[\begin{array}{ccc|ccc} 1 & 0 & 6 & 1 & -1 & 0 \\ 0 & 1 & -4 & -\frac{2}{3} & 1 & 0 \\ 0 & 0 & 1 & 0 & 0 & 1 \end{array}\right] \xrightarrow[\ -6r_3 + r_1 \to r_1\ ]{4r_3 + r_2 \to r_2} \left[\begin{array}{ccc|ccc} 1 & 0 & 0 & 1 & -1 & -6 \\ 0 & 1 & 0 & -\frac{2}{3} & 1 & 4 \\ 0 & 0 & 1 & 0 & 0 & 1 \end{array}\right]$$
Buradan
$$A^{-1} = \begin{pmatrix} 1 & -1 & -6 \\ -\frac{2}{3} & 1 & 4 \\ 0 & 0 & 1 \end{pmatrix}$$
bulunur. $A$'nın indirgenmiş satır eşelon formu olan $I_3$'te sıfırdan farklı $3$ satır olduğu için $\text{rank}(A) = 3$'tür.

### Soru 2: Minör ve Kofaktör Hesaplama (ekrandan, 01:03:20)

**Soru:**
$$A = \begin{pmatrix} 1 & 2 & 3 \\ 4 & 5 & 6 \\ 7 & 8 & 9 \end{pmatrix}$$
matrisinin $a_{23}$ elemanının minörünü ve kofaktörünü ($A_{23}$) bulunuz.

**Çözüm:**
2. satır ve 3. sütun silindiğinde kalan alt matris $M_{23} = \begin{pmatrix} 1 & 2 \\ 7 & 8 \end{pmatrix}$ olur.
- Minör: $\det(M_{23}) = 1 \cdot 8 - 2 \cdot 7 = 8 - 14 = -6$.
- Kofaktör: $A_{23} = (-1)^{2+3}\det(M_{23}) = (-1)^5(-6) = 6$.

### Soru 3: Laplace Açılımı ile Determinant Hesaplama (ekrandan, 01:18:20)

**Soru:**
$$A = \begin{pmatrix} 2 & 1 & 3 \\ -1 & 2 & 1 \\ -2 & 2 & 3 \end{pmatrix}$$
matrisinin determinantını 1. satır boyunca Laplace açılımı kullanarak hesaplayınız.

**Çözüm:**
1. satır kofaktörleri:
- $A_{11} = (-1)^{1+1}\begin{vmatrix} 2 & 1 \\ 2 & 3 \end{vmatrix} = 1 \cdot (6 - 2) = 4$
- $A_{12} = (-1)^{1+2}\begin{vmatrix} -1 & 1 \\ -2 & 3 \end{vmatrix} = -1 \cdot (-3 - (-2)) = 1$
- $A_{13} = (-1)^{1+3}\begin{vmatrix} -1 & 2 \\ -2 & 2 \end{vmatrix} = 1 \cdot (-2 - (-4)) = 2$
Determinant:
$$\det(A) = a_{11}A_{11} + a_{12}A_{12} + a_{13}A_{13} = 2(4) + 1(1) + 3(2) = 8 + 1 + 6 = 15$$

## Dersin Toparlaması

Bu derste ilk olarak bir kare matrisin tersinir (nonsingular) olmasının birim matrise ($I_n$) satırca denk olmasıyla eşdeğer olduğu gösterildi ve $[A \mid I_n] \to [I_n \mid A^{-1}]$ genişletilmiş matris yöntemiyle ters matrisin adım adım nasıl bulunduğu incelendi. İndirgeme sırasında tamamen sıfırlardan oluşan bir satır elde edilirse matrisin tekil (singular) olduğu ve tersinin bulunmadığı vurgulandı; ayrıca eşelon formdaki sıfırdan farklı satır sayısı olarak matrisin rankı tanımlandı. Dersin ikinci bölümünde ise determinant kavramına geçilerek $1 \times 1$, $2 \times 2$ ve $3 \times 3$ matrislerin determinant formülleri, $3 \times 3$ matrisler için Sarrus kuralı, alt matrislerin determinantı olan minör ($\det(M_{ij})$), işaretli minör olan kofaktör ($A_{ij} = (-1)^{i+j}\det(M_{ij})$) ve genel $n \times n$ matrisler için Laplace (kofaktör) açılımı sayısal örneklerle işlendi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
