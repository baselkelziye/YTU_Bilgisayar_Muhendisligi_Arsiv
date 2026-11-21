# Ders 5 Çalışma Özeti

## Genel Konular

- Determinantın Temel Özellikleri (Properties of Determinants)
  - Birim matrisin determinantı $1$'dir: $\det(I) = 1$ (ekrandan, 00:06:30).
  - Bir matrisin herhangi iki satırının veya iki sütununun yeri değiştirilirse determinantın işareti tersine döner (pozitifse negatif, negatifse pozitif olur): $i \neq j$ için $\det(A_{r_i \leftrightarrow r_j}) = -\det(A)$ (ekrandan, 00:06:30 ve 00:31:30).
  - Bir matrisin tek bir satırı (veya tek bir sütunu) bir $t \in \mathbb{R}$ skaleri ile çarpılırsa determinant da $t$ ile çarpılmış olur: $\det(A_{k r_i \to r_i}) = k \det(A)$. Örneğin $\begin{vmatrix} ta & tb \\ c & d \end{vmatrix} = t \begin{vmatrix} a & b \\ c & d \end{vmatrix}$ (ekrandan, 00:06:30 ve 00:31:30).
  - Determinant satırlar (veya sütunlar) üzerinde doğrusal (lineer) bir fonksiyon gibi davranır; bir satırı iki terimin toplamı şeklinde olan determinant, diğer satırları aynı kalan iki ayrı determinantın toplamı olarak ayrıştırılabilir.
  - Bir matrisin iki satırı veya iki sütunu birbirine eşitse determinantı sıfırdır (ekrandan, 00:12:25).
  - Bir matrisin bir satırının (veya sütununun) $k$ katı başka bir satıra (veya sütuna) eklenirse determinant değişmez: $i \neq j$ için $\det(A_{k r_i + r_j \to r_j}) = \det(A)$ (ekrandan, 00:23:10 ve 00:31:30).
  - Tamamen sıfırlardan oluşan bir satırı veya sütunu bulunan matrisin determinantı sıfırdır.
  - Üçgensel (alt veya üst üçgensel) bir matrisin determinantı, esas köşegen (main diagonal) üzerindeki elemanların çarpımına eşittir.
- Çarpım, Ters, Kuvvet, Skaler Çarpım ve Transpozun Determinantı (Determinants of Matrix Operations)
  - Aynı boyuttaki iki kare matrisin çarpımının determinantı, determinantlarının çarpımına eşittir: $\det(AB) = \det(A)\det(B)$ (ekrandan, 00:23:10).
  - Tersinir (nonsingular) bir $A$ matrisinin tersinin determinantı: $\det(A^{-1}) = \frac{1}{\det(A)}$ ($A^{-1}A = I$ olduğundan). Eğer $A$ tekil (singular) ise $A^{-1}$ mevcut değildir ve $\det(A^{-1})$ tanımsızdır.
  - Bir $A$ kare matrisinin karesinin determinantı: $\det(A^2) = (\det(A))^2$.
  - $n \times n$ boyutlu bir $A$ kare matrisinin $k$ skaleri ile çarpımının determinantı: $k$ çarpanı matrisin tüm $n$ satırını (veya sütununu) çarptığından her satırdan bir $k$ dışarı çıkar ve $\det(kA) = k^n \det(A)$ olur.
  - Bir matrisin transpozunun determinantı kendisinin determinantına eşittir: $\det(A^T) = \det(A)$.
- Üçgensel Matrise İndirgeyerek Determinant Hesaplama ve Sarrus Kuralı Tekrarı (Reduction to Triangular Matrix and Sarrus' Rule)
  - Elementer satır (veya sütun) işlemleri ve ortak çarpan parantezine alma özellikleri kullanılarak bir matris üst (veya alt) üçgensel forma indirgenebilir; bu durumda determinant esas köşegen elemanlarının çarpımıyla kolayca bulunur (ekrandan, 00:49:30).
  - Sarrus Kuralı (Sarrus' Rule): Yalnızca $3 \times 3$ boyutlu matrislerde ilk iki sütunun sağa (veya ilk iki satırın alta) tekrar yazılıp soldan sağa köşegen çarpımlarının toplamından sağdan sola köşegen çarpımlarının toplamının çıkarılmasıyla uygulanır (ekrandan, 00:57:45).
- Ek Matris (Adjoint / Adjugate Matrix) ve Determinant Yardımıyla Ters Matris Bulma (Finding Inverse Matrices Using Adjoint Matrices)
  - $A = [a_{ij}]$ bir $n \times n$ kare matris ve $A_{ij}$ de $a_{ij}$ elemanının kofaktörü olmak üzere, $A$'nın kofaktörler matrisinin transpozuna $A$'nın **ek matrisi** (adjoint veya adjugate of $A$) denir ve $\text{adj}(A)$ ile gösterilir (ekrandan, 01:03:45):
    $$\text{adj}(A) = [A_{ij}]^T = \begin{pmatrix} A_{11} & A_{21} & \cdots & A_{n1} \\ A_{12} & A_{22} & \cdots & A_{n2} \\ \vdots & \vdots & \ddots & \vdots \\ A_{1n} & A_{2n} & \cdots & A_{nn} \end{pmatrix}$$
    Yani $\text{adj}(A)$ matrisinin $(i, j)$ konumundaki elemanı, $a_{ji}$ elemanının kofaktörü olan $A_{ji}$'dir.
  - Her $n \times n$ kare matris $A$ için şu temel özdeşlik geçerlidir:
    $$A \cdot \text{adj}(A) = \text{adj}(A) \cdot A = \det(A) I_n$$
  - Eğer $\det(A) \neq 0$ ise ($A$ tekil değilse / nonsingular ise), $A$ matrisinin tersi ek matris formülüyle şu şekilde bulunur (ekrandan, 01:25:55):
    $$A^{-1} = \frac{1}{\det(A)} \text{adj}(A)$$

## Hocanın Özellikle Vurguladığı Kısımlar

- Matrisin Skalerle Çarpımında $\det(kA) = k^n \det(A)$ Kuralı
  - Bir determinantın tek bir satırı veya sütunu $k$ ile çarpıldığında determinant $k$ katına çıkar ($\det(A_{k r_i \to r_i}) = k \det(A)$); ancak $n \times n$ boyutlu bir $A$ matrisinin tamamı $k$ skaleri ile çarpıldığında ($kA$), matrisin bütün elemanları —dolayısıyla $n$ satırının tamamı— $k$ ile çarpılmış olur. Bu nedenle her satırdan bir $k$ çarpanı dışarı çıkar ve $\det(kA) = k \cdot k \cdots k \det(A) = k^n \det(A)$ elde edilir.
- Determinant Hesabında Hem Satır Hem Sütun İşlemlerinin Kullanılabilmesi
  - Ters matris bulma veya denklem sistemi çözmede satır ve sütun işlemleri birbirine karıştırılamazken, $\det(A^T) = \det(A)$ özelliği sayesinde **determinant hesaplamalarında** hem elementer satır işlemleri hem de elementer sütun işlemleri aynı problem içinde serbestçe kullanılabilir (ekrandan, 00:41:40).
- Büyük Boyutlu Matrislerde Üçgensel Matrise İndirgeme Yöntemi
  - Sarrus kuralı yalnızca $3 \times 3$ matrisler için geçerlidir. Boyutu $3$'ten büyük ($4 \times 4$ vb.) matrislerin determinantını hesaplarken veya sembolik ifadeleri çarpanlarına ayırırken, elementer satır/sütun işlemleriyle matrisi üçgensel matris (triangular matrix) formuna indirgeyip esas köşegen elemanlarını çarpmak çok daha pratiktir (ekrandan, 00:49:30).
- Ek Matriste ($\text{adj}(A)$) Transpoz Almayı Unutmama ve Tersinirlik Şartı
  - $\text{adj}(A)$ yazılırken kofaktörler hesaplandıktan sonra matrisin **transpozunun** alınması ($[A_{ij}]^T$) kritik önem taşır; 1. satırın kofaktörleri ($A_{11}, A_{12}, A_{13}$) ek matrisin 1. satırına değil, **1. sütununa** yazılır (ekrandan, 01:03:45 ve 01:11:15).
  - Ek matris yöntemiyle $A^{-1}$ sorulduğunda **ilk önce $\det(A)$ hesaplanmalıdır**. Eğer $\det(A) = 0$ çıkarsa matris tekildir (singular) ve tersi yoktur; bu durumda kofaktörleri ve ek matrisi hesaplamaya gerek kalmaz.

## Kısa Tekrar Notları

- Elementer satır işlemlerinin determinanta etkisi (ekrandan, 00:31:30):
  - $\det(A_{r_i \leftrightarrow r_j}) = -\det(A) \quad (i \neq j)$
  - $\det(A_{k r_i \to r_i}) = k \det(A)$
  - $\det(A_{k r_i + r_j \to r_j}) = \det(A) \quad (i \neq j)$
- Sıfır determinant durumları: İki satırı (veya sütunu) eşit olan, bir satırı (veya sütunu) diğerinin katı olan ya da tamamen sıfırdan oluşan bir satırı (veya sütunu) bulunan matrisin determinantı $0$'dır.
- Üçgensel matris determinantı: Alt veya üst üçgensel $A = [a_{ij}]_{n \times n}$ için $\det(A) = a_{11}a_{22}\cdots a_{nn}$.
- Temel determinant özdeşlikleri ($A, B \in M_{n \times n}$):
  - $\det(I_n) = 1$
  - $\det(AB) = \det(A)\det(B)$
  - $\det(A^{-1}) = \frac{1}{\det(A)}$ ($\det(A) \neq 0$ ise)
  - $\det(A^2) = (\det(A))^2$
  - $\det(kA) = k^n \det(A)$
  - $\det(A^T) = \det(A)$
- Ek matris (Adjoint matrix): $A_{ij} = (-1)^{i+j}\det(M_{ij})$ kofaktör olmak üzere $\text{adj}(A) = [A_{ij}]^T = [A_{ji}]$.
- Temel ek matris bağıntısı: $A \cdot \text{adj}(A) = \text{adj}(A) \cdot A = \det(A) I_n$.
- Ek matris ile ters matris formülü: $\det(A) \neq 0 \iff A$ tersinirdir ve $A^{-1} = \frac{1}{\det(A)}\text{adj}(A)$ (ekrandan, 01:25:55).

## Detaylı Açıklamalar

- **Determinant Özellikleriyle Ortak Çarpan Parantezine Alma ve Çarpanlara Ayırma Örnekleri:**
  - **Sayısal Çarpanlarına Ayırma Örneği (ekrandan, 00:12:25 ve 00:16:15):**
    $$\begin{vmatrix} 2 & 6 \\ 1 & 12 \end{vmatrix} = 2 \begin{vmatrix} 1 & 3 \\ 1 & 12 \end{vmatrix} = 2 \cdot 3 \begin{vmatrix} 1 & 1 \\ 1 & 4 \end{vmatrix} = 2 \cdot 3 \cdot (4 - 1) = 2 \cdot 3 \cdot 3 = 18$$
    Burada önce 1. satır $2$'nin katı olduğundan $2$ çarpanı dışarı alınmış, ardından kalan matrisin 2. sütunu $3$'ün katı olduğundan $3$ çarpanı dışarı alınmıştır.
    Benzer şekilde $\begin{vmatrix} 1 & 2 & 3 \\ 1 & 5 & 3 \\ 2 & 8 & 6 \end{vmatrix}$ determinantında 3. sütun $3$ parantezine alındığında $3 \begin{vmatrix} 1 & 2 & 1 \\ 1 & 5 & 1 \\ 2 & 8 & 2 \end{vmatrix}$ elde edilir; 1. ve 3. sütunlar birbirine eşit olduğundan determinant doğrudan $0$ bulunur.
  - **Harfli (Sembolik) Determinantı Çarpanlarına Ayırma Örneği (ekrandan, 00:41:40):**
    $$\begin{vmatrix} x+y & z & t \\ z & x+y & t \\ z & t & x+y \end{vmatrix}$$
    determinantını özellikler yardımıyla çarpanlarına ayırmak için önce 2. ve 3. sütunlar 1. sütuna eklenir ($c_1 + c_2 + c_3 \to c_1$). Bu işlem determinantı değiştirmez ve 1. sütunun tüm elemanları $x+y+z+t$ olur:
    $$\xrightarrow{c_1+c_2+c_3 \to c_1} \begin{vmatrix} x+y+z+t & z & t \\ x+y+z+t & x+y & t \\ x+y+z+t & t & x+y \end{vmatrix} = (x+y+z+t) \begin{vmatrix} 1 & z & t \\ 1 & x+y & t \\ 1 & t & x+y \end{vmatrix}$$
    Ardından 1. sütundaki $1$'in altındaki elemanları sıfırlamak için $-r_1 + r_2 \to r_2$ ve $-r_1 + r_3 \to r_3$ satır işlemleri uygulanır:
    $$= (x+y+z+t) \begin{vmatrix} 1 & z & t \\ 0 & x+y-z & 0 \\ 0 & t-z & x+y-t \end{vmatrix}$$
    Elde edilen matris alt üçgensel formda olduğundan (veya 1. sütuna göre Laplace açılımı yapıldığında) determinant esas köşegen elemanlarının çarpımına eşittir:
    $$\det = (x+y+z+t)(x+y-z)(x+y-t)$$

- **Üçgensel Matrise İndirgeme (Reduction to Triangular Matrix) ile Determinant Hesabı (ekrandan, 00:49:30):**
  Geçen derste Laplace açılımıyla determinantı $15$ bulunan $A = \begin{pmatrix} 2 & 1 & 3 \\ -1 & 2 & 1 \\ -2 & 2 & 3 \end{pmatrix}$ matrisinin determinantı bu kez üst üçgensel matrise indirgenerek hesaplanmıştır:
  1. 1. sütundaki $2$'nin altındaki $-1$ ve $-2$'yi sıfırlamak için $\frac{1}{2}r_1 + r_2 \to r_2$ ve $r_1 + r_3 \to r_3$ işlemleri uygulanır (bu işlemler determinantı değiştirmez):
     $$\begin{vmatrix} 2 & 1 & 3 \\ -1 & 2 & 1 \\ -2 & 2 & 3 \end{vmatrix} \xrightarrow[\ r_1 + r_3 \to r_3\ ]{\frac{1}{2}r_1 + r_2 \to r_2} \begin{vmatrix} 2 & 1 & 3 \\ 0 & \frac{5}{2} & \frac{5}{2} \\ 0 & 3 & 6 \end{vmatrix}$$
  2. 2. satır $\frac{5}{2}$'nin katı, 3. satır ise $3$'ün katı olduğundan bu çarpanlar determinantın dışına alınır:
     $$= \frac{5}{2} \cdot 3 \begin{vmatrix} 2 & 1 & 3 \\ 0 & 1 & 1 \\ 0 & 1 & 2 \end{vmatrix}$$
  3. Son olarak $-r_2 + r_3 \to r_3$ işlemiyle matris üst üçgensel forma getirilir ve esas köşegen elemanları çarpılır:
     $$\xrightarrow{-r_2 + r_3 \to r_3} \frac{5}{2} \cdot 3 \begin{vmatrix} 2 & 1 & 3 \\ 0 & 1 & 1 \\ 0 & 0 & 1 \end{vmatrix} = \frac{5}{2} \cdot 3 \cdot (2 \cdot 1 \cdot 1) = 15$$

- **Ek Matris ($\text{adj}(A)$) ve Ters Matris ($A^{-1}$) Hesaplama Örnekleri:**
  - **Örnek 1 — Ek Matris Hesabı ve $A \cdot \text{adj}(A) = \det(A)I$ Özelliği (ekrandan, 01:11:15):**
    $$A = \begin{pmatrix} 3 & -2 & 1 \\ 5 & 6 & 2 \\ 1 & 0 & -3 \end{pmatrix}$$
    matrisinin tüm elemanlarının kofaktörleri hesaplandığında:
    - $A_{11} = (-1)^{1+1}\begin{vmatrix} 6 & 2 \\ 0 & -3 \end{vmatrix} = -18$, $\quad A_{12} = (-1)^{1+2}\begin{vmatrix} 5 & 2 \\ 1 & -3 \end{vmatrix} = -(-15-2) = 17$, $\quad A_{13} = (-1)^{1+3}\begin{vmatrix} 5 & 6 \\ 1 & 0 \end{vmatrix} = -6$
    - $A_{21} = (-1)^{2+1}\begin{vmatrix} -2 & 1 \\ 0 & -3 \end{vmatrix} = -6$, $\quad A_{22} = (-1)^{2+2}\begin{vmatrix} 3 & 1 \\ 1 & -3 \end{vmatrix} = -10$, $\quad A_{23} = (-1)^{2+3}\begin{vmatrix} 3 & -2 \\ 1 & 0 \end{vmatrix} = -2$
    - $A_{31} = (-1)^{3+1}\begin{vmatrix} -2 & 1 \\ 6 & 2 \end{vmatrix} = -10$, $\quad A_{32} = (-1)^{3+2}\begin{vmatrix} 3 & 1 \\ 5 & 2 \end{vmatrix} = -1$, $\quad A_{33} = (-1)^{3+3}\begin{vmatrix} 3 & -2 \\ 5 & 6 \end{vmatrix} = 28$
    Kofaktör matrisinin transpozu alınarak (satır kofaktörleri sütunlara yazılarak) ek matris elde edilir:
    $$\text{adj}(A) = \begin{pmatrix} -18 & -6 & -10 \\ 17 & -10 & -1 \\ -6 & -2 & 28 \end{pmatrix}$$
    $A$ ile $\text{adj}(A)$ çarpıldığında $A \cdot \text{adj}(A) = \begin{pmatrix} -94 & 0 & 0 \\ 0 & -94 & 0 \\ 0 & 0 & -94 \end{pmatrix} = -94 I_3$ bulunur ki buradan $\det(A) = -94$ olduğu görülür.
  - **Örnek 2 — Ek Matris Yardımıyla Ters Matris Bulma (ekrandan, 01:24:30 ve 01:25:55):**
    $$A = \begin{pmatrix} 2 & 3 & 1 \\ 0 & 1 & 2 \\ 1 & 2 & 0 \end{pmatrix}$$
    matrisinin tersini bulmak için önce determinantı hesaplanır: $\det(A) = (0 + 6 + 0) - (1 + 8 + 0) = 6 - 9 = -3 \neq 0$. Determinant sıfırdan farklı olduğundan $A$ tersinirdir.
    Kofaktörler:
    - $A_{11} = -4, \quad A_{12} = 2, \quad A_{13} = -1$
    - $A_{21} = 2, \quad A_{22} = -1, \quad A_{23} = -1$
    - $A_{31} = 5, \quad A_{32} = -4, \quad A_{33} = 2$
    Kofaktörlerin transpozu alınarak ek matris ve ardından $A^{-1} = \frac{1}{\det(A)}\text{adj}(A)$ yazılır:
    $$\text{adj}(A) = \begin{pmatrix} -4 & 2 & 5 \\ 2 & -1 & -4 \\ -1 & -1 & 2 \end{pmatrix} \implies A^{-1} = \frac{1}{-3} \begin{pmatrix} -4 & 2 & 5 \\ 2 & -1 & -4 \\ -1 & -1 & 2 \end{pmatrix} = \begin{pmatrix} \frac{4}{3} & -\frac{2}{3} & -\frac{5}{3} \\ -\frac{2}{3} & \frac{1}{3} & \frac{4}{3} \\ \frac{1}{3} & \frac{1}{3} & -\frac{2}{3} \end{pmatrix}$$

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
