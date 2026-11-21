# Ders 1 Çalışma Özeti

## Genel Konular

- Matris Tanımı ve Temel Gösterimler (Matrix Definition and Basic Notations)
  - Matris (matrix), $m$ adet yatay satır (row) ve $n$ adet dikey sütundan (column) oluşan, elemanları reel veya karmaşık sayılar olan dikdörtgensel bir sayı dizisidir ($m \times n$ boyutlu matris).
  - Matrisler büyük harflerle ($A, B, C, \dots$), elemanları (entry / element) ise bulundukları satır ve sütun indisleriyle küçük harflerle ($a_{ij}$) gösterilir; kısaca $A = [a_{ij}]$ biçiminde yazılır.
  - Bir $m \times n$ matrisin $i$. satırı $[a_{i1}\ a_{i2}\ \dots\ a_{in}]$ ($1 \times n$ matris), $j$. sütunu ise $\begin{bmatrix} a_{1j} \\ a_{2j} \\ \vdots \\ a_{mj} \end{bmatrix}$ ($m \times 1$ matris) biçimindedir (ekrandan, 00:16:30).
- Özel Matris Türleri ve Vektörler (Special Types of Matrices and Vectors)
  - Kare matris (square matrix): Satır sayısı sütun sayısına eşit olan ($m = n$) matristir ve $n$. mertebeden kare matris (square matrix of order $n$) olarak adlandırılır.
  - Esas köşegen (main diagonal): Yalnızca kare matrislerde tanımlı olup satır ve sütun indisi eşit olan $a_{11}, a_{22}, \dots, a_{nn}$ ($a_{ii}$) elemanlarının oluşturduğu köşegendir.
  - Karmaşık matris (complex matrix): Elemanları arasında karmaşık sayılar bulunan matristir; örneğin $B = \begin{bmatrix} 1+i & 4i \\ 2-3i & -3 \end{bmatrix}$ bir $2 \times 2$ karmaşık kare matristir (ekrandan, 00:28:15).
  - Vektör (vector): Tek sütundan oluşan $m \times 1$ boyutlu matrislere sütun vektörü veya $m$-vektör ($m$-vector), tek satırdan oluşan $1 \times n$ boyutlu matrislere ise satır vektörü (row vector / row matrix) denir.
  - Sıfır matrisi ve sıfır vektörü (zero matrix and zero vector): Tüm elemanları $0$ olan matrise sıfır matrisi, tüm elemanları $0$ olan vektöre ise sıfır vektörü denir ve $0$ ile gösterilir (ekrandan, 00:36:15).
- Matrislerin Eşitliği ve Matrisin İzi (Equality of Matrices and Trace of a Matrix)
  - Aynı boyuttaki ($m \times n$) iki matris $A = [a_{ij}]$ ve $B = [b_{ij}]$, yalnızca karşılıklı tüm elemanları birbirine eşitse ($a_{ij} = b_{ij}$, her $i = 1, \dots, m$ ve $j = 1, \dots, n$ için) birbirine eşittir ($A = B$) (ekrandan, 00:42:15).
  - Matrisin izi (trace of a matrix): $A$ bir $n \times n$ kare matris olmak üzere, esas köşegen üzerindeki tüm elemanların toplamına $A$ matrisinin izi denir ve $\text{Tr}(A) = a_{11} + a_{22} + \dots + a_{nn}$ ile gösterilir (ekrandan, 00:46:00).
- Temel Matris İşlemleri (Basic Matrix Operations)
  - Matris toplamı (matrix addition): Aynı boyuttaki ($m \times n$) $A = [a_{ij}]$ ve $B = [b_{ij}]$ matrislerinin toplamı, karşılıklı elemanların toplanmasıyla elde edilen $C = A + B = [c_{ij}]$ ($c_{ij} = a_{ij} + b_{ij}$) matrisidir (ekrandan, 00:56:15).
  - Skaler ile çarpma (scalar multiplication): Bir $A = [a_{ij}]$ ($m \times n$) matrisinin bir $r$ reel sayısı (skaler / sabit) ile çarpımı, matrisin her bir elemanının $r$ ile çarpılmasıyla elde edilen $C = rA = [c_{ij}]$ ($c_{ij} = r \cdot a_{ij}$) matrisidir (ekrandan, 01:06:00).
  - Matris farkı (difference of matrices): Aynı boyuttaki $A$ ve $B$ matrislerinin farkı, $B$ matrisinin $-1$ skaleri ile çarpılıp $A$ ile toplanmasıyla tanımlanır: $A - B = A + (-1)B$ (ekrandan, 01:10:05).
- Toplam Sembolü ve Matrisin Devriği (Summation Notation and Transpose of a Matrix)
  - Toplam sembolü (summation notation): $\sum_{i=1}^{n} a_i = a_1 + a_2 + \dots + a_n$ biçiminde tanımlanır; buradaki $i$ toplam indisidir (index of summation) ve takma değişken (dummy variable) olduğundan $j$ veya $k$ gibi başka bir harfle değiştirilebilir (ekrandan, 01:13:30).
  - Matrisin devriği / transpozu (transpose of a matrix): $A = [a_{ij}]$ bir $m \times n$ matris olmak üzere, satırları ile sütunlarının yer değiştirmesiyle ($a_{ij}^T = a_{ji}$) elde edilen $n \times m$ boyutlu matrise $A$'nın devriği denir ve $A^T$ ile gösterilir (ekrandan, 01:15:30).

## Hocanın Özellikle Vurguladığı Kısımlar

- Boyut Yazımında Satır ve Sütun Sırası
  - Matris boyutu veya eleman indisi yazılırken her zaman önce satır (row), ardından sütun (column) numarası yazılır ($m \times n$ ve $a_{ij}$). $2 \times 3$ boyutlu bir matris ile $3 \times 2$ boyutlu bir matris aynı değildir.
  - Satır veya sütun sayısı çift basamaklı olduğunda karışıklığı önlemek için indisler arasına virgül konulur; örneğin 3. satır 32. sütundaki eleman $a_{3,32}$ olarak yazılır (ekrandan, 00:28:15).
- Esas Köşegenin Yalnızca Kare Matrislerde Tanımlı Olması
  - Esas köşegen (main diagonal) ve buna bağlı olan matrisin izi ($\text{Tr}(A)$) yalnızca kare matrisler ($n \times n$) için tanımlıdır. Kare olmayan (örneğin $4 \times 3$ boyutlu) bir matrisin esas köşegeni yoktur ve kare matriste sol üstten sağ alta inen $a_{ii}$ köşegeni dışındaki diğer köşegen esas köşegen olarak seçilemez.
  - $0 \times 0$ boyutunda bir matris tanımlı değildir; en küçük boyutlu matris tek elemanlı $1 \times 1$ matristir.
- Matris Toplama ve Çıkarma İşlemlerinde Boyut Şartı
  - İki veya daha fazla matrisin toplanabilmesi ya da çıkarılabilmesi için boyutlarının (hem satır hem sütun sayılarının) birebir aynı olması şarttır. Farklı boyutlu matrisler toplanamaz.
- Devrik (Transpose) İşleminde Boyut Değişimi
  - $m \times n$ boyutlu bir matrisin devriği alındığında boyutu $n \times m$ olur. Özel olarak bir satır matrisinin ($1 \times n$) devriği bir sütun matrisi ($n \times 1$), bir sütun matrisinin ($m \times 1$) devriği ise bir satır matrisi ($1 \times m$) olur.

## Kısa Tekrar Notları

- $A = [a_{ij}]_{m \times n}$ matrisinde $m$ satır sayısını, $n$ sütun sayısını, $a_{ij}$ ise $i$. satır ve $j$. sütundaki elemanı gösterir.
- $m = n$ ise $A$ matrisi $n$. mertebeden kare matristir (square matrix of order $n$).
- $n \times n$ kare matriste esas köşegen (main diagonal) elemanları $a_{11}, a_{22}, \dots, a_{nn}$ olup iz (trace) formülü $\text{Tr}(A) = \sum_{i=1}^{n} a_{ii} = a_{11} + a_{22} + \dots + a_{nn}$ şeklindedir.
- $m \times 1$ matris bir sütun vektörü ($m$-vector), $1 \times n$ matris ise bir satır vektörüdür (row vector).
- İki matrisin eşitliği: $A_{m \times n} = B_{m \times n} \iff a_{ij} = b_{ij}$ (tüm $i, j$ çiftleri için).
- Matris toplamı ve farkı: $(A \pm B)_{ij} = a_{ij} \pm b_{ij}$ (yalnızca aynı boyutlu matrisler için tanımlıdır).
- Skaler çarpım: $(rA)_{ij} = r \cdot a_{ij}$ ($r \in \mathbb{R}$, sonuç matrisi $A$ ile aynı boyuttadır).
- Toplam sembolünde indis değişimi: $\sum_{i=1}^{n} u_i = \sum_{j=1}^{n} u_j = \sum_{k=1}^{n} u_k$ (ekrandan, 01:13:30).
- Devrik (transpose): $A$ matrisi $m \times n$ ise $A^T$ matrisi $n \times m$ boyutludur ve $(A^T)_{ij} = a_{ji}$ kuralıyla satır ve sütunların yer değiştirmesiyle bulunur.

## Detaylı Açıklamalar

- **Matris Kavramı, Boyut ve Örnekler:** Doğrusal denklem sistemlerini (linear equations) çözerken denklemleri tekrar tekrar yazmak yerine matrislerden ve matris işlemlerinden yararlanılır. Bir $m \times n$ matris $A$, $m$ adet yatay satır ve $n$ adet dikey sütun halinde düzenlenmiş $m \cdot n$ adet reel veya karmaşık sayıdan oluşan dikdörtgensel bir tablodur. Derste incelenen temel matris örnekleri şunlardır (ekrandan, 00:28:15):
  $$A = \begin{bmatrix} 1 & 2 & 3 \\ -1 & 0 & 1 \end{bmatrix}_{2 \times 3}, \quad B = \begin{bmatrix} 1+i & 4i \\ 2-3i & -3 \end{bmatrix}_{2 \times 2}, \quad C = \begin{bmatrix} 1 \\ 1 \\ 2 \end{bmatrix}_{3 \times 1}$$
  $$D = \begin{bmatrix} 1 & 1 & 0 \\ 2 & 0 & 1 \\ 3 & -1 & 2 \end{bmatrix}_{3 \times 3}, \quad E = [3]_{1 \times 1}, \quad F = \begin{bmatrix} -1 & 0 & 2 \end{bmatrix}_{1 \times 3}$$
  Burada $A$ matrisinin elemanları incelendiğinde $a_{11}=1, a_{12}=2, a_{13}=3, a_{21}=-1, a_{22}=0, a_{23}=1$ olduğu görülür. $B$ matrisi karmaşık sayılar içerdiği için karmaşık matris (complex matrix) ve aynı zamanda $2 \times 2$ boyutlu bir kare matristir. $C$ matrisi tek sütunlu ($3 \times 1$) olduğundan bir $3$-vektördür (sütun vektörü). $D$ matrisi $3$. mertebeden bir kare matristir ve esas köşegen (main diagonal) elemanları sırasıyla $1, 0, 2$'dir. $E$ tek elemanlı $1 \times 1$ kare matris, $F$ ise $1 \times 3$ boyutlu bir satır matrisidir (veya satır vektörü). Tüm elemanları sıfır olan matrislere örnek olarak $2 \times 3$ ve $2 \times 2$ sıfır matrisleri ile $3 \times 1$ ve $1 \times 3$ sıfır vektörleri verilmiştir (ekrandan, 00:36:15):
  $$0 = \begin{bmatrix} 0 & 0 & 0 \\ 0 & 0 & 0 \end{bmatrix}_{2 \times 3}, \quad 0 = \begin{bmatrix} 0 & 0 \\ 0 & 0 \end{bmatrix}_{2 \times 2}, \quad 0 = \begin{bmatrix} 0 \\ 0 \\ 0 \end{bmatrix}, \quad 0 = \begin{bmatrix} 0 & 0 & 0 \end{bmatrix}$$

- **Matrislerin Eşitliği ve Matrisin İzi:** İki matrisin eşit olabilmesi için öncelikle aynı boyutta olmaları, ardından aynı konumdaki tüm elemanlarının birebir eşit olması ($a_{ij} = b_{ij}$) gerekir. Derste çözülen örnekte iki adet $3 \times 3$ matris verilmiştir (ekrandan, 00:42:15):
  $$A = \begin{bmatrix} 1 & 2 & -1 \\ 2 & -3 & 4 \\ 0 & -4 & 5 \end{bmatrix}_{3 \times 3}, \quad B = \begin{bmatrix} 1 & 2 & w \\ 2 & x & 4 \\ y & -4 & z \end{bmatrix}_{3 \times 3}$$
  $A = B$ eşitliğinden karşılıklı elemanlar eşitlenerek $w = a_{13} = -1$, $x = a_{22} = -3$, $y = a_{31} = 0$ ve $z = a_{33} = 5$ bulunur. Matrisin izi (trace) ise yalnızca $n \times n$ kare matrisler için tanımlanır ve esas köşegen üzerindeki elemanların toplamına eşittir: $\text{Tr}(A) = a_{11} + a_{22} + \dots + a_{nn}$ (ekrandan, 00:46:00).

- **Matris Toplamı, Skalerle Çarpma ve Matris Farkı:** Aynı boyuttaki iki matris toplanırken veya çıkarılırken karşılıklı elemanlar kendi aralarında toplanır veya çıkarılır.
  - Toplama örneği (ekrandan, 00:56:15):
    $$A = \begin{bmatrix} 1 & -2 & 3 \\ 2 & -1 & 4 \end{bmatrix}, \quad B = \begin{bmatrix} 0 & 2 & 1 \\ 1 & 3 & -4 \end{bmatrix}$$
    $$A + B = \begin{bmatrix} 1+0 & -2+2 & 3+1 \\ 2+1 & -1+3 & 4+(-4) \end{bmatrix} = \begin{bmatrix} 1 & 0 & 4 \\ 3 & 2 & 0 \end{bmatrix}$$
  - Skaler ile çarpma işleminde matrisin her elemanı $r \in \mathbb{R}$ skaleri (pozitif, negatif veya kesirli herhangi bir reel sayı) ile çarpılır. Dersteki örnekte $A$ ($2 \times 3$) matrisi $r = -2$ ile çarpılmıştır (ekrandan, 01:06:00):
    $$A = \begin{bmatrix} 4 & -2 & -3 \\ 7 & -3 & 2 \end{bmatrix} \implies -2A = \begin{bmatrix} (-2)(4) & (-2)(-2) & (-2)(-3) \\ (-2)(7) & (-2)(-3) & (-2)(2) \end{bmatrix} = \begin{bmatrix} -8 & 4 & 6 \\ -14 & 6 & -4 \end{bmatrix}$$
  - Matris farkı $A - B = A + (-1)B$ olarak tanımlanır. Dersteki çıkarma örneği (ekrandan, 01:10:05):
    $$A = \begin{bmatrix} 2 & 3 & -5 \\ 4 & 2 & 1 \end{bmatrix}, \quad B = \begin{bmatrix} 2 & -1 & 3 \\ 3 & 5 & -2 \end{bmatrix}$$
    $$A - B = \begin{bmatrix} 2-2 & 3-(-1) & -5-3 \\ 4-3 & 2-5 & 1-(-2) \end{bmatrix} = \begin{bmatrix} 0 & 4 & -8 \\ 1 & -3 & 3 \end{bmatrix}$$

- **Matrisin Devriği (Transpose of a Matrix):** $m \times n$ boyutlu bir $A = [a_{ij}]$ matrisinin satırları ile sütunlarının yer değiştirmesiyle elde edilen $n \times m$ boyutlu matrise $A$'nın devriği denir ve $A^T = [a_{ij}^T]$ ($a_{ij}^T = a_{ji}$) ile gösterilir. Derste beş farklı matrisin devriği adım adım hesaplanmıştır (ekrandan, 01:24:20):
  - $A = \begin{bmatrix} 4 & -2 & 3 \\ 0 & 5 & -2 \end{bmatrix}_{2 \times 3}$ matrisinin 1. satırı 1. sütun, 2. satırı 2. sütun yapılarak $A^T = \begin{bmatrix} 4 & 0 \\ -2 & 5 \\ 3 & -2 \end{bmatrix}_{3 \times 2}$ bulunur.
  - $B = \begin{bmatrix} 6 & 2 & -4 \\ 3 & -1 & 2 \\ 0 & 4 & 3 \end{bmatrix}_{3 \times 3}$ kare matrisinin devriği $B^T = \begin{bmatrix} 6 & 3 & 0 \\ 2 & -1 & 4 \\ -4 & 2 & 3 \end{bmatrix}_{3 \times 3}$ olur.
  - $C = \begin{bmatrix} 5 & 4 \\ -3 & 2 \\ 2 & -3 \end{bmatrix}_{3 \times 2}$ matrisinin devriği $C^T = \begin{bmatrix} 5 & -3 & 2 \\ 4 & 2 & -3 \end{bmatrix}_{2 \times 3}$ olur (hoca sözlü okurken son elemanı $3$ diye telaffuz etmiş ancak tahtaya $-3$ yazmıştır).
  - $D = \begin{bmatrix} 3 & -5 & 1 \end{bmatrix}_{1 \times 3}$ satır matrisinin devriği $D^T = \begin{bmatrix} 3 \\ -5 \\ 1 \end{bmatrix}_{3 \times 1}$ sütun matrisidir.
  - $E = \begin{bmatrix} 2 \\ -1 \\ 3 \end{bmatrix}_{3 \times 1}$ sütun matrisinin devriği ise $E^T = \begin{bmatrix} 2 & -1 & 3 \end{bmatrix}_{1 \times 3}$ satır matrisidir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
