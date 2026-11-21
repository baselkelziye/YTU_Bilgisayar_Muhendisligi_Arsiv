# Ders 2 Çalışma Özeti

## Genel Konular

- İki Vektörün İç Çarpımı ve Matris Çarpımı (Inner / Dot Product and Matrix Multiplication)
  - $\mathbb{R}^n$ uzayındaki iki $n$-vektörün ($n \times 1$ matrisin) $a = [a_1\ a_2\ \dots\ a_n]^T$ ve $b = [b_1\ b_2\ \dots\ b_n]^T$ nokta çarpımı veya iç çarpımı (dot product / inner product), karşılıklı bileşenlerin çarpımlarının toplamı olarak tanımlanır: $a \cdot b = a_1 b_1 + a_2 b_2 + \dots + a_n b_n$ (ekrandan, 00:04:40).
  - $A = [a_{ij}]$ bir $m \times p$ matris ve $B = [b_{ij}]$ bir $p \times n$ matris olmak üzere, $A$ ve $B$'nin çarpımı $C = AB = [c_{ij}]$ ile gösterilen $m \times n$ boyutlu bir matristir (ekrandan, 00:11:20).
  - Çarpım matrisinin $c_{ij}$ elemanı, $A$ matrisinin $i$. satırı ile $B$ matrisinin $j$. sütununun iç çarpımı alınarak hesaplanır: $c_{ij} = a_{i1}b_{1j} + a_{i2}b_{2j} + \dots + a_{ip}b_{pj} = \sum_{k=1}^{p} a_{ik}b_{kj}$.
- Matris Çarpımının Özellikleri ve $AB$ ile $BA$ Karşılaştırması (Properties of Matrix Multiplication)
  - Matris çarpımı genel olarak değişme özelliğine sahip değildir (not commutative); yani genel durumda $AB \neq BA$.
  - $A$ bir $m \times p$ ve $B$ bir $p \times n$ matris olduğunda $AB$ çarpımı $m \times n$ boyutludur; $BA$ çarpımı için ise dört durum söz konusudur (ekrandan, 00:30:10):
    - $n \neq m$ ise $BA$ çarpımı tanımlı değildir.
    - $n = m$ ancak $m \neq p$ ise $BA$ tanımlıdır ve $p \times p$ boyutludur, buna karşılık $AB$ ise $m \times m$ boyutludur (boyutları farklıdır).
    - $AB$ ve $BA$ aynı boyutta ($m = n = p$) olsa bile birbirine eşit olabilirler ($AB = BA$) veya eşit olmayabilirler ($AB \neq BA$).
  - Çarpma ve toplama işlemleri tanımlı olmak şartıyla birleşme özelliği $(AB)C = A(BC)$ (associative law) geçerlidir ve bir matrisin sıfır matrisiyle çarpımı yine sıfır matrisidir (ekrandan, 00:30:10).
- Devrik, İz ve Tersinir Matris Özellikleri (Transpose, Trace, and Invertible Matrices)
  - $A$ ve $B$, $n \times n$ kare matrisler ve $k$ bir skaler olmak üzere iz (trace) işleminin temel özellikleri şunlardır (ekrandan, 00:40:45):
    - $\text{Tr}(A + B) = \text{Tr}(A) + \text{Tr}(B)$
    - $\text{Tr}(A^T) = \text{Tr}(A)$
    - $\text{Tr}(kA) = k\,\text{Tr}(A)$
    - $\text{Tr}(AB) = \text{Tr}(BA)$
  - Tersinir (regüler / tekil olmayan) matris (invertible / nonsingular / regular matrix): $n \times n$ kare matrisler için $AB = BA = I$ (birim matris / identity matrix) eşitliğini sağlayan bir $B$ matrisi varsa $A$ matrisine tersinir matris, $B$'ye ise $A$'nın tersi (inverse of $A$) denir ve $B = A^{-1}$ ile gösterilir.
  - $A$ ve $B$ tersinir matrisler ise çarpımları $AB$ de tersinirdir ve tersi alınırken çarpım sırası tersine döner: $(AB)^{-1} = B^{-1}A^{-1}$. Genel olarak $(A_1 A_2 \dots A_k)^{-1} = A_k^{-1} \dots A_2^{-1} A_1^{-1}$ eşitliği geçerlidir (ekrandan, 00:44:25).
- Özel Kare Matrisler: Periyodik, İdempotent, Nilpotent ve İnvolütif Matrisler (Special Square Matrices)
  - Periyodik matris (periodic matrix): Bir $A$ kare matrisi için $A^{k+1} = A$ eşitliğini sağlayan pozitif bir $k$ tam sayısı varsa $A$'ya periyodik matris, bu koşulu sağlayan en küçük pozitif $k$ tam sayısına ise $A$'nın periyodu (period of $A$) denir (ekrandan, 00:53:45).
  - İdempotent matris (idempotent matrix): Periyodik matris tanımında $k = 1$ özel durumu olan, yani $A^2 = A$ eşitliğini sağlayan kare matristir.
  - Nilpotent matris (nilpotent matrix): Bir $A$ kare matrisi için $A^k = 0$ (sıfır matrisi) eşitliğini sağlayan pozitif bir $k$ tam sayısı varsa $A$'ya nilpotent matris, bu eşitliği sağlayan en küçük pozitif $k$ tam sayısına ise nilpotentlik indisi (nilpotency index) denir.
  - İnvolütif matris (involute / involutory matrix): Karesi birim matrise eşit olan ($A^2 = I$) kare matristir (ekrandan, 00:59:40).
- Köşegen, Skaler, Üçgensel, Simetrik ve Ters Simetrik Matrisler (Diagonal, Scalar, Triangular, Symmetric, and Skew-Symmetric Matrices)
  - Köşegen matris (diagonal matrix): Esas köşegeni dışındaki tüm elemanları sıfır olan ($i \neq j$ için $d_{ij} = 0$) kare matristir ve kısaca $D = \text{diag}(d_{11}, d_{22}, \dots, d_{nn})$ ile gösterilir (ekrandan, 01:09:35).
  - Skaler matris (scalar matrix): Birim matrisin bir $k$ skaleri ile katı olan $kI_n$ biçimindeki kare matristir; esas köşegen dışındaki elemanları $0$ olduğu için her skaler matris aynı zamanda bir köşegen matristir (ekrandan, 01:09:35).
  - Üst ve alt üçgensel matris (upper and lower triangular matrix): Esas köşegenin altındaki tüm elemanları sıfır olan ($i > j$ için $a_{ij} = 0$) kare matrise üst üçgensel matris (upper triangular matrix), esas köşegenin üstündeki tüm elemanları sıfır olan ($i < j$ için $a_{ij} = 0$) kare matrise ise alt üçgensel matris (lower triangular matrix) denir (ekrandan, 01:16:50).
  - Simetrik matris (symmetric matrix): Devriği kendisine eşit olan ($A^T = A$, yani her $i, j$ için $a_{ij} = a_{ji}$) kare matristir (ekrandan, 01:29:15).
  - Ters simetrik (skew-symmetric) matris: Devriği kendisinin negatifine eşit olan ($A^T = -A$, yani her $i, j$ için $a_{ij} = -a_{ji}$) kare matristir; bu koşul gereği esas köşegen üzerindeki tüm elemanları sıfır olmak zorundadır ($a_{ii} = 0$) (ekrandan, 01:29:15).

## Hocanın Özellikle Vurguladığı Kısımlar

- Matris Çarpımında Boyut Uyumu Kuralı
  - İki matrisin çarpılabilmesi ($AB$) için birinci matrisin sütun sayısı ($p$), ikinci matrisin satır sayısına ($p$) eşit olmak zorundadır. Çarpım sonucunda elde edilen $AB$ matrisinin boyutu ise birinci matrisin satır sayısı ile ikinci matrisin sütun sayısından oluşan $m \times n$ boyutudur (ekrandan, 00:11:20).
- Matris Çarpımında Değişme Özelliğinin Olmaması ve İz Eşitliği
  - Matris çarpımında değişme özelliği yoktur ($AB \neq BA$). Ancak $A$ ve $B$ aynı boyutta kare matrisler olduğunda çarpımlarının izleri birbirine eşittir: $\text{Tr}(AB) = \text{Tr}(BA)$. Hoca iz teoremindeki 4. maddenin ($\text{Tr}(AB) = \text{Tr}(BA)$) en önemli özellik olduğunu özellikle vurgulamıştır (ekrandan, 00:40:45).
  - Benzer şekilde çarpımın tersi alınırken sıra tersine döner: $(AB)^{-1} = B^{-1}A^{-1}$ (ekrandan, 00:44:25).
- Köşegen ve Üçgensel Matrislerde Sıfır Matrisi ve Kesişim Özellikleri
  - Bir matrisin köşegen (diagonal) olması için esas köşegen dışındaki elemanlarının $0$ olması yeterlidir; esas köşegen üzerindeki elemanların bazıları veya tamamı da $0$ olabilir. Bu nedenle $n \times n$ kare sıfır matrisi (zero matrix) de bir köşegen matristir.
  - Her köşegen matris (ve dolayısıyla her skaler matris ve birim matris), hem alt üçgensel (lower triangular) hem de üst üçgensel (upper triangular) bir matristir.
- Ters Simetrik Matrislerde Esas Köşegenin Sıfır Olma Zorunluluğu
  - Simetrik veya ters simetrik matris mutlaka kare matris olmalıdır. Ters simetrik ($A^T = -A$) bir matriste esas köşegen elemanları $a_{ii} = -a_{ii} \implies 2a_{ii} = 0 \implies a_{ii} = 0$ eşitliğini sağlamak zorunda olduğundan, esas köşegen üzerindeki tüm elemanlar daima $0$'dır. Bir matrisin ters simetrik olup olmadığını kontrol ederken ilk olarak esas köşegen elemanlarının $0$ olup olmadığına bakılır.

## Kısa Tekrar Notları

- İç çarpım (inner / dot product): $a, b \in \mathbb{R}^n$ için $a \cdot b = \sum_{k=1}^{n} a_k b_k$.
- Matris çarpımı: $A_{m \times p} \cdot B_{p \times n} = C_{m \times n}$ ve $c_{ij} = \sum_{k=1}^{p} a_{ik} b_{kj}$.
- Genel durumda $AB \neq BA$; ancak kare matrisler için $\text{Tr}(AB) = \text{Tr}(BA)$.
- Tersinir matris: $AB = BA = I_n \iff B = A^{-1}$. Çarpımın tersi: $(AB)^{-1} = B^{-1}A^{-1}$.
- Periyodik matris: $A^{k+1} = A$ (en küçük $k \in \mathbb{Z}^+$ periyottur).
- İdempotent matris: $A^2 = A$ ($k=1$ periyodik durumu; tüm pozitif kuvvetleri için $A^m = A$ olduğundan sıfırdan farklı bir idempotent matris aynı zamanda nilpotent olamaz).
- Nilpotent matris: $A^k = 0$ (en küçük $k \in \mathbb{Z}^+$ nilpotentlik indisidir).
- İnvolütif matris (involute / involutory): $A^2 = I$.
- Köşegen matris: $i \neq j \implies d_{ij} = 0$, gösterimi $D = \text{diag}(d_{11}, d_{22}, \dots, d_{nn})$.
- Skaler matris: $kI_n = \text{diag}(k, k, \dots, k)$ (özel bir köşegen matristir).
- Üst üçgensel matris: $i > j \implies a_{ij} = 0$ (köşegen altı sıfır). Alt üçgensel matris: $i < j \implies a_{ij} = 0$ (köşegen üstü sıfır).
- Simetrik matris: $A^T = A \iff a_{ij} = a_{ji}$.
- Ters simetrik (skew-symmetric) matris: $A^T = -A \iff a_{ij} = -a_{ji}$ ve $a_{ii} = 0$.

## Detaylı Açıklamalar

- **Matris Çarpımı ve Değişme Özelliğinin İncelenmesi:** İki matrisin çarpımı, birinci matrisin satır vektörleri ile ikinci matrisin sütun vektörlerinin iç çarpımına (dot product) dayanır.
  - **Örnek 1 (Farklı boyutlu iki matrisin çarpımı):** $A$ ($2 \times 2$) ve $B$ ($2 \times 3$) matrisleri verildiğinde $A$'nın sütun sayısı ($2$) ile $B$'nin satır sayısı ($2$) eşit olduğundan $AB$ çarpımı tanımlıdır ve boyutu $2 \times 3$ olur (ekrandan, 00:18:30):
    $$A = \begin{pmatrix} 1 & 3 \\ 2 & -1 \end{pmatrix}_{2 \times 2}, \quad B = \begin{pmatrix} 2 & 0 & -4 \\ 5 & -2 & 6 \end{pmatrix}_{2 \times 3}$$
    $$AB = \begin{pmatrix} (1)(2)+(3)(5) & (1)(0)+(3)(-2) & (1)(-4)+(3)(6) \\ (2)(2)+(-1)(5) & (2)(0)+(-1)(-2) & (2)(-4)+(-1)(6) \end{pmatrix} = \begin{pmatrix} 17 & -6 & 14 \\ -1 & 2 & -14 \end{pmatrix}_{2 \times 3}$$
  - **Örnek 2 ($AB \neq BA$ gösterimi):** İki adet $2 \times 2$ kare matris için hem $AB$ hem de $BA$ tanımlıdır (ekrandan, 00:22:05):
    $$A = \begin{pmatrix} 1 & 2 \\ 3 & 4 \end{pmatrix}, \quad B = \begin{pmatrix} 5 & 6 \\ 0 & -2 \end{pmatrix}$$
    $$AB = \begin{pmatrix} 1 & 2 \\ 3 & 4 \end{pmatrix} \begin{pmatrix} 5 & 6 \\ 0 & -2 \end{pmatrix} = \begin{pmatrix} 5+0 & 6-4 \\ 15+0 & 18-8 \end{pmatrix} = \begin{pmatrix} 5 & 2 \\ 15 & 10 \end{pmatrix}$$
    $$BA = \begin{pmatrix} 5 & 6 \\ 0 & -2 \end{pmatrix} \begin{pmatrix} 1 & 2 \\ 3 & 4 \end{pmatrix} = \begin{pmatrix} 5+18 & 10+24 \\ 0-6 & 0-8 \end{pmatrix} = \begin{pmatrix} 23 & 34 \\ -6 & -8 \end{pmatrix}$$
    Buradan açıkça $AB \neq BA$ olduğu, yani matris çarpımının değişme özelliğine sahip olmadığı görülür. (Ayrıca bu örnek üzerinde $\text{Tr}(AB) = 5 + 10 = 15$ ve $\text{Tr}(BA) = 23 + (-8) = 15$ olduğu da doğrulanabilir.)

- **Kuvvet Özelliğine Göre Özel Kare Matrisler (Periyodik, İdempotent, Nilpotent, İnvolütif):**
  - **Periyodik Matris Örneği:** $A^{k+1} = A$ koşulunu sağlayan en küçük pozitif $k$ tam sayısına matrisin periyodu denir. Derste verilen $3 \times 3$ boyutlu $A$ matrisinin periyodu adım adım hesaplanmıştır (ekrandan, 00:53:45):
    $$A = \begin{pmatrix} 1 & -2 & -6 \\ -3 & 2 & 9 \\ 2 & 0 & -3 \end{pmatrix}$$
    Önce $A^2 = A \cdot A$ bulunur:
    $$A^2 = \begin{pmatrix} 1 & -2 & -6 \\ -3 & 2 & 9 \\ 2 & 0 & -3 \end{pmatrix} \begin{pmatrix} 1 & -2 & -6 \\ -3 & 2 & 9 \\ 2 & 0 & -3 \end{pmatrix} = \begin{pmatrix} 1+6-12 & -2-4+0 & -6-18+18 \\ -3-6+18 & 6+4+0 & 18+18-27 \\ 2+0-6 & -4+0+0 & -12+0+9 \end{pmatrix} = \begin{pmatrix} -5 & -6 & -6 \\ 9 & 10 & 9 \\ -4 & -4 & -3 \end{pmatrix}$$
    Ardından $A^3 = A^2 \cdot A$ hesaplanır:
    $$A^3 = \begin{pmatrix} -5 & -6 & -6 \\ 9 & 10 & 9 \\ -4 & -4 & -3 \end{pmatrix} \begin{pmatrix} 1 & -2 & -6 \\ -3 & 2 & 9 \\ 2 & 0 & -3 \end{pmatrix} = \begin{pmatrix} -5+18-12 & 10-12+0 & 30-54+18 \\ 9-30+18 & -18+20+0 & -54+90-27 \\ -4+12-6 & 8-8+0 & 24-36+9 \end{pmatrix} = \begin{pmatrix} 1 & -2 & -6 \\ -3 & 2 & 9 \\ 2 & 0 & -3 \end{pmatrix} = A$$
    $A^3 = A^{2+1} = A$ olduğundan $A$ matrisi periyodu $k = 2$ olan bir periyodik matristir.
  - **İdempotent, Nilpotent ve İnvolütif Matrisler:** $A^2 = A$ ise matris idempotent, $A^k = 0$ ise nilpotent, $A^2 = I$ ise involütif (involute / involutory) matristir. Derste verilen involütif matris örneği şudur (ekrandan, 00:59:40):
    $$A = \begin{pmatrix} -5 & -8 & 0 \\ 3 & 5 & 0 \\ 1 & 2 & -1 \end{pmatrix} \implies A^2 = I_3 = \begin{pmatrix} 1 & 0 & 0 \\ 0 & 1 & 0 \\ 0 & 0 & 1 \end{pmatrix}$$
    Ayrıca derste bir öğrencinin "Bir matris aynı zamanda hem idempotent hem nilpotent olabilir mi?" sorusu üzerine hoca, idempotent bir matriste $A^1 = A$, $A^2 = A$, $A^3 = A^2 \cdot A = A \cdot A = A^2 = A$ ve tümevarımla her kuvvetin yine $A$'ya eşit olduğunu, dolayısıyla (sıfır matrisi dışında) hiçbir kuvvetinin $0$ olamayacağını göstererek yanıtın "hayır" olduğunu kanıtlamıştır.

- **Yapısına Göre Özel Kare Matrisler (Köşegen, Üçgensel, Simetrik ve Ters Simetrik):**
  - **Köşegen ve Skaler Matrisler:** Esas köşegen dışındaki tüm elemanları $0$ olan kare matrise köşegen matris denir. Örneğin (ekrandan, 01:09:35):
    $$\begin{pmatrix} 3 & 0 & 0 \\ 0 & -7 & 0 \\ 0 & 0 & 2 \end{pmatrix}, \quad \begin{pmatrix} 4 & 0 \\ 0 & -5 \end{pmatrix}, \quad \begin{pmatrix} 6 & & & \\ & 0 & & \\ & & -9 & \\ & & & 8 \end{pmatrix}$$
    matrisleri birer köşegen matristir (bazen köşegen dışındaki sıfırlar yazılmadan boş bırakılabilir veya $\text{diag}(d_{11}, \dots, d_{nn})$ biçiminde yazılır). Birim matrisin skaler katı olan $kI_n = \text{diag}(k, k, \dots, k)$ skaler matrisleri ve tüm elemanları $0$ olan kare sıfır matrisi de birer köşegen matristir.
  - **Üçgensel Matrisler:** Esas köşegenin altındaki tüm elemanlar sıfır ise ($i > j$ için $a_{ij} = 0$) üst üçgensel (upper triangular), esas köşegenin üstündeki tüm elemanlar sıfır ise ($i < j$ için $a_{ij} = 0$) alt üçgensel (lower triangular) matristir (ekrandan, 01:16:50).
  - **Simetrik ve Ters Simetrik Matris Örneği:** Derste üç matris incelenmiştir (ekrandan, 01:29:15):
    $$A = \begin{pmatrix} 2 & -3 & 5 \\ -3 & 6 & 7 \\ 5 & 7 & -8 \end{pmatrix}, \quad B = \begin{pmatrix} 0 & 3 & -4 \\ -3 & 0 & 5 \\ 4 & -5 & 0 \end{pmatrix}, \quad C = \begin{pmatrix} 1 & 0 & 0 \\ 0 & 0 & 1 \end{pmatrix}$$
    - $A$ matrisi $3 \times 3$ kare matristir ve esas köşegene göre simetrik konumdaki tüm elemanları birbirine eşittir ($a_{12}=a_{21}=-3$, $a_{13}=a_{31}=5$, $a_{23}=a_{32}=7$), yani $A^T = A$ olduğundan **simetrik matristir**.
    - $B$ matrisi $3 \times 3$ kare matristir, esas köşegen üzerindeki tüm elemanları sıfırdır ($0, 0, 0$) ve köşegen dışındaki karşılıklı elemanları birbirinin ters işaretlisidir ($b_{12}=3, b_{21}=-3$; $b_{13}=-4, b_{31}=4$; $b_{23}=5, b_{32}=-5$), yani $B^T = -B$ ($a_{ij} = -a_{ji}$) olduğundan **ters simetrik (skew-symmetric) matristir**.
    - $C$ matrisi $2 \times 3$ boyutlu olup kare matris olmadığı için **ne simetrik ne de ters simetriktir** (neither symmetric nor skew-symmetric).

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
