# Ders 4 Çalışma Özeti

## Genel Konular

- Elementer Satır İşlemleriyle Matrisin Tersini Bulma (Finding an Inverse Using Elementary Row Operations)
  - Bir $n \times n$ kare matris $A$ için şu iki ifade birbirine denktir (ekrandan, 00:08:00):
    1. $A$ tekil olmayan (nonsingular / tersinir / invertible) bir matristir, yani $A^{-1}$ mevcuttur.
    2. $A$ matrisi $I_n$ birim matrisine satırca (veya sütunca) denktir; başka bir deyişle $A$'nın indirgenmiş satır eşelon formu (RREF) $I_n$ birim matrisidir.
  - $A$ matrisinin tersi mevcutsa, $A$'yı $I_n$ birim matrisine indirgeyen bir dizi elementer satır işlemi vardır. $A^{-1}$ matrisini bulmak için $A$ ile $I_n$ yan yana yazılarak $[A \mid I_n]$ genişletilmiş matrisi oluşturulur ve sol taraftaki $A$ matrisini $I_n$'e dönüştüren elementer satır işlemleri tüm satıra uygulandığında sağ tarafta $A^{-1}$ elde edilir: $[A \mid I_n] \xrightarrow{\text{Elementer satır işlemleri}} [I_n \mid A^{-1}]$ (ekrandan, 00:12:55).
- Tekil (Singular) Matrisler ve Matrisin Rankı (Singular Matrices and Rank of a Matrix)
  - Bir $n \times n$ kare matris $A$'nın tekil (singular / tersinir olmayan / non-invertible) olması için gerek ve yeter şart, $A$'nın tamamen sıfırlardan oluşan bir satıra (zero row) sahip bir matrise satırca denk olmasıdır.
  - Dolayısıyla $[A \mid I_n]$ üzerinde satır işlemleri yapılırken sol taraftaki matriste herhangi bir adımda tamamen sıfırlardan oluşan bir satır ortaya çıkarsa işlem durdurulur ve $A^{-1}$'in mevcut olmadığı ($A$'nın tekil olduğu) sonucuna varılır.
  - Matrisin rankı (rank of a matrix): Bir matrisin satır eşelon formundaki (REF) veya indirgenmiş satır eşelon formundaki (RREF) sıfırdan farklı satırların (non-zero rows) sayısına o matrisin rankı denir.
- Determinant Kavramı: $1 \times 1$, $2 \times 2$ ve $3 \times 3$ Matrislerin Determinantı (Determinants and Rule of Sarrus)
  - $n$. mertebeden bir $A = [a_{ij}]_{n \times n}$ kare matrisinin determinantı $\det(A)$ veya $|A|$ ile gösterilir (ekrandan, 00:39:00):
    - $n = 1$ için $A = [a]_{1 \times 1} \implies \det(A) = a$.
    - $n = 2$ için $A = \begin{pmatrix} a_{11} & a_{12} \\ a_{21} & a_{22} \end{pmatrix}_{2 \times 2} \implies \det(A) = a_{11}a_{22} - a_{12}a_{21}$ (esas köşegen elemanlarının çarpımından diğer köşegen elemanlarının çarpımı çıkarılır).
    - $n = 3$ için 1. satıra göre açılımla $\det(A) = a_{11}\begin{vmatrix} a_{22} & a_{23} \\ a_{32} & a_{33} \end{vmatrix} - a_{12}\begin{vmatrix} a_{21} & a_{23} \\ a_{31} & a_{33} \end{vmatrix} + a_{13}\begin{vmatrix} a_{21} & a_{22} \\ a_{31} & a_{32} \end{vmatrix}$ formülüyle hesaplanır (ekrandan, 00:44:00).
  - Sarrus Kuralı (Rule of Sarrus): Yalnızca $3 \times 3$ boyutlu kare matrislerin determinantını hesaplamak için kullanılan pratik bir yöntemdir. Matrisin ilk iki satırı matrisin altına (veya ilk iki sütunu matrisin sağına) tekrar yazılır; soldan sağa inen üç köşegen üzerindeki elemanların çarpımlarının toplamından, sağdan sola inen üç köşegen üzerindeki elemanların çarpımlarının toplamı çıkarılır (ekrandan, 00:50:00):
    $$|A| = a_{11}a_{22}a_{33} + a_{21}a_{32}a_{13} + a_{31}a_{12}a_{23} - a_{13}a_{22}a_{31} - a_{23}a_{32}a_{11} - a_{33}a_{12}a_{21}$$
- Minör, Kofaktör ve Laplace (Kofaktör) Açılımı (Minors, Cofactors, and Laplace Expansion)
  - Minör (minor): $n \times n$ boyutlu bir $A$ matrisinin $i$. satırı ve $j$. sütununun silinmesiyle elde edilen $(n-1) \times (n-1)$ boyutlu alt matrisin determinantına $a_{ij}$ elemanının $(i, j)$. minörü denir (slaytta $\det(M_{ij})$ veya $M_{ij}$ ile gösterilir) (ekrandan, 01:03:20).
  - Kofaktör (cofactor): $a_{ij}$ elemanının $(i, j)$. kofaktörü $A_{ij}$ ile gösterilir ve $A_{ij} = (-1)^{i+j} \det(M_{ij})$ formülüyle tanımlanır (ekrandan, 01:03:20).
  - Laplace Açılımı (Laplace / cofactor expansion): Herhangi bir $n \times n$ kare matrisin determinantı, seçilen herhangi bir $i$. satırın veya $j$. sütunun elemanlarının kendi kofaktörleriyle çarpımlarının toplamına eşittir:
    $$\det(A) = \sum_{k=1}^{n} a_{ik}A_{ik} = a_{i1}A_{i1} + a_{i2}A_{i2} + \dots + a_{in}A_{in} \quad (\text{veya } j\text{. sütun boyunca } \det(A) = \sum_{k=1}^{n} a_{kj}A_{kj})$$
  - Bir satırın (veya sütunun) elemanları, **başka** bir satırın (veya sütunun) kofaktörleriyle çarpılıp toplanırsa sonuç daima sıfırdır: $i \neq j$ için $\sum_{k=1}^{n} a_{ik}A_{jk} = 0$ ve $\sum_{k=1}^{n} a_{ki}A_{kj} = 0$ (ekrandan, 01:08:30).

## Hocanın Özellikle Vurguladığı Kısımlar

- Ters Matris Hesabında Satır ve Sütun İşlemlerini Karıştırmama ve Sağlama Yapma
  - $[A \mid I_n]$ yöntemiyle ters matris bulurken aynı problem içinde hem satır hem sütun işlemi bir arada **asla kullanılamaz**; bir satır bir sütuna eklenemez. Hoca her zaman yalnızca elementer satır işlemlerinin kullanılmasını önermektedir.
  - Bulunan $A^{-1}$ matrisinin doğruluğu, $A A^{-1} = I_n$ çarpımı yapılarak kolayca kontrol edilebilir.
  - Ters matris hesabı sırasında sol tarafta tamamen sıfırlardan oluşan bir satır elde edilirse matrisin tekil (singular) olduğu anlaşılır ve işlem hemen sonlandırılır.
- Sarrus Kuralının Yalnızca $3 \times 3$ Matrislerde Geçerli Olması
  - Sarrus kuralı (ilk iki satırı alta veya ilk iki sütunu sağa ekleme yöntemi) **yalnızca $3 \times 3$ matrisler için** geçerlidir; $4 \times 4$ veya daha büyük matrislerde uygulanamaz.
- Laplace Açılımında En Çok Sıfır İçeren Satır veya Sütunun Seçilmesi
  - Laplace (kofaktör) açılımı hangi satır veya sütun seçilirse seçilsin aynı determinant değerini verir. Ancak hesaplama kolaylığı açısından **en fazla sıfır ($0$) içeren satır veya sütunun seçilmesi** en iyi yoldur; çünkü $a_{ij} = 0$ olan elemanlar kofaktörüyle çarpıldığında $0$ vereceğinden o elemanların kofaktörlerini ($A_{ij}$) hesaplamaya gerek kalmaz.

## Kısa Tekrar Notları

- $n \times n$ kare matris $A$ tersinirdir ($A^{-1}$ vardır) $\iff \text{RREF}(A) = I_n \iff \text{rank}(A) = n$.
- $n \times n$ kare matris $A$ tekildir (singular, $A^{-1}$ yoktur) $\iff \text{RREF}(A)$ en az bir sıfır satırı içerir ($\text{rank}(A) < n$).
- Gauss-Jordan ters matris yöntemi: $[A \mid I_n] \xrightarrow{\text{RREF}} [I_n \mid A^{-1}]$.
- $\text{rank}(A) =$ $A$'nın REF veya RREF formundaki sıfırdan farklı satır sayısı.
- $2 \times 2$ determinant: $\det\begin{pmatrix} a_{11} & a_{12} \\ a_{21} & a_{22} \end{pmatrix} = a_{11}a_{22} - a_{12}a_{21}$.
- Minör ve Kofaktör: $M_{ij}$, $i$. satır ve $j$. sütun silinerek kalan $(n-1) \times (n-1)$ matris olmak üzere $a_{ij}$'nin minörü $\det(M_{ij})$, kofaktörü ise $A_{ij} = (-1)^{i+j}\det(M_{ij})$'dir.
- İşaret tablosu: $(-1)^{i+j}$ çarpanı nedeniyle kofaktör işaretleri $+, -, +, -$ şeklinde dama tahtası düzeninde değişir.
- Laplace açılımı: $\det(A) = \sum_{k=1}^{n} a_{ik}A_{ik}$ ($i$. satıra göre) veya $\det(A) = \sum_{k=1}^{n} a_{kj}A_{kj}$ ($j$. sütuna göre).
- Farklı satır/sütun kofaktör toplamı: $i \neq j \implies \sum_{k=1}^{n} a_{ik}A_{jk} = 0$ ve $\sum_{k=1}^{n} a_{ki}A_{kj} = 0$ (ekrandan, 01:08:30).

## Detaylı Açıklamalar

- **Elementer Satır İşlemleriyle Ters Matris Bulma Örneği:**
  Derste $A = \begin{pmatrix} 3 & 3 & 6 \\ 2 & 3 & 0 \\ 0 & 0 & 1 \end{pmatrix}$ matrisinin tersi $[A \mid I_3]$ genişletilmiş matrisi kurularak adım adım hesaplanmıştır (ekrandan, 00:19:15 ve 00:24:00):
  1. Başlangıç matrisi yazılır ve 1. satır $\frac{1}{3}$ ile çarpılır ($\frac{1}{3}r_1 \to r_1$):
     $$\left[\begin{array}{ccc|ccc} 3 & 3 & 6 & 1 & 0 & 0 \\ 2 & 3 & 0 & 0 & 1 & 0 \\ 0 & 0 & 1 & 0 & 0 & 1 \end{array}\right] \xrightarrow{\frac{1}{3}r_1 \to r_1} \left[\begin{array}{ccc|ccc} 1 & 1 & 2 & \frac{1}{3} & 0 & 0 \\ 2 & 3 & 0 & 0 & 1 & 0 \\ 0 & 0 & 1 & 0 & 0 & 1 \end{array}\right]$$
  2. 1. sütundaki öncü $1$'in altındaki $2$'yi sıfırlamak için 1. satırın $-2$ katı 2. satıra eklenir ($-2r_1 + r_2 \to r_2$):
     $$\xrightarrow{-2r_1 + r_2 \to r_2} \left[\begin{array}{ccc|ccc} 1 & 1 & 2 & \frac{1}{3} & 0 & 0 \\ 0 & 1 & -4 & -\frac{2}{3} & 1 & 0 \\ 0 & 0 & 1 & 0 & 0 & 1 \end{array}\right]$$
  3. 2. sütundaki öncü $1$'in üstündeki $1$'i sıfırlamak için 2. satırın $-1$ katı 1. satıra eklenir ($-r_2 + r_1 \to r_1$):
     $$\xrightarrow{-r_2 + r_1 \to r_1} \left[\begin{array}{ccc|ccc} 1 & 0 & 6 & 1 & -1 & 0 \\ 0 & 1 & -4 & -\frac{2}{3} & 1 & 0 \\ 0 & 0 & 1 & 0 & 0 & 1 \end{array}\right]$$
  4. 3. sütundaki öncü $1$'in üstündeki $-4$ ve $6$'yı sıfırlamak için 3. satırın $4$ katı 2. satıra ($4r_3 + r_2 \to r_2$) ve $-6$ katı 1. satıra ($-6r_3 + r_1 \to r_1$) eklenir:
     $$\xrightarrow[\ -6r_3 + r_1 \to r_1\ ]{4r_3 + r_2 \to r_2} \left[\begin{array}{ccc|ccc} 1 & 0 & 0 & 1 & -1 & -6 \\ 0 & 1 & 0 & -\frac{2}{3} & 1 & 4 \\ 0 & 0 & 1 & 0 & 0 & 1 \end{array}\right]$$
  Sol tarafta $I_3$ birim matrisi elde edildiğinden sağ taraftaki matris $A^{-1}$'dir. Hoca ardından $A A^{-1}$ çarpımını açıkça yaparak sonucun $I_3$ olduğunu doğrulamış ve ayrıca $\text{RREF}(A) = I_3$ içinde sıfırdan farklı $3$ satır bulunduğundan $\text{rank}(A) = 3$ olduğunu göstermiştir (ekrandan, 00:28:00 ve 00:35:45).

- **Minör, Kofaktör ve Laplace Açılımı Örnekleri:**
  - **Minör ve Kofaktör Hesabı Örneği:**
    $$A = \begin{pmatrix} 1 & 2 & 3 \\ 4 & 5 & 6 \\ 7 & 8 & 9 \end{pmatrix}$$
    matrisinde $a_{23} = 6$ elemanının minörünü ve kofaktörünü bulmak için 2. satır ve 3. sütun silinerek $M_{23} = \begin{pmatrix} 1 & 2 \\ 7 & 8 \end{pmatrix}$ alt matrisi elde edilir (ekrandan, 01:03:20).
    - Minör: $\det(M_{23}) = (1)(8) - (2)(7) = 8 - 14 = -6$.
    - Kofaktör: $A_{23} = (-1)^{2+3}\det(M_{23}) = (-1)^5(-6) = (-1)(-6) = 6$.
  - **Laplace Açılımı ile Determinant Hesabı Örneği:**
    $$A = \begin{pmatrix} 2 & 1 & 3 \\ -1 & 2 & 1 \\ -2 & 2 & 3 \end{pmatrix}$$
    matrisinde hiç sıfır eleman bulunmadığından 1. satır seçilerek Laplace açılımı uygulanmıştır (ekrandan, 01:18:20):
    $$\det(A) = a_{11}A_{11} + a_{12}A_{12} + a_{13}A_{13}$$
    - $A_{11} = (-1)^{1+1}\begin{vmatrix} 2 & 1 \\ 2 & 3 \end{vmatrix} = (+1)(6 - 2) = 4$
    - $A_{12} = (-1)^{1+2}\begin{vmatrix} -1 & 1 \\ -2 & 3 \end{vmatrix} = (-1)(-3 - (-2)) = (-1)(-1) = 1$
    - $A_{13} = (-1)^{1+3}\begin{vmatrix} -1 & 2 \\ -2 & 2 \end{vmatrix} = (+1)(-2 - (-4)) = 2$
    Buradan $a_{11}=2, a_{12}=1, a_{13}=3$ değerleri yerine konulduğunda:
    $$\det(A) = 2 \cdot 4 + 1 \cdot 1 + 3 \cdot 2 = 8 + 1 + 6 = 15$$
    bulunur. (Aynı örnekte 2. satır elemanları 1. satırın kofaktörleriyle çarpılıп toplanırsa $a_{21}A_{11} + a_{22}A_{12} + a_{23}A_{13} = (-1)(4) + (2)(1) + (1)(2) = -4 + 2 + 2 = 0$ olduğu da görülür.)

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
