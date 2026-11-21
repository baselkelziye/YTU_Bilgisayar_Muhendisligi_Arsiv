# Ders 6 Çalışma Özeti

## Genel Konular

- Doğrusal Denklem ve Doğrusal Denklem Sistemleri (Linear Equations and Systems of Linear Equations)
  - $x_1, x_2, \dots, x_n$ bilinmeyenler (unknowns) ve $a_1, a_2, \dots, a_n, b$ bilinen sabitler (constants) olmak üzere $a_1 x_1 + a_2 x_2 + \dots + a_n x_n = b$ biçimindeki denkleme **doğrusal (lineer) denklem** (linear equation) denir.
  - $x_1 = s_1, x_2 = s_2, \dots, x_n = s_n$ yazıldığında denklemi sağlayan $s_1, s_2, \dots, s_n$ sayı dizisine denklemin bir **çözümü** (solution) denir.
  - $n$ bilinmeyenli ($x_1, x_2, \dots, x_n$) $m$ adet doğrusal denklemden oluşan kümeye **doğrusal denklem sistemi** veya kısaca **lineer sistem** (system of linear equations / linear system) denir (ekrandan, 00:18:30):
    $$\begin{cases} a_{11}x_1 + a_{12}x_2 + \dots + a_{1n}x_n = b_1 \\ a_{21}x_1 + a_{22}x_2 + \dots + a_{2n}x_n = b_2 \\ \qquad \vdots \\ a_{m1}x_1 + a_{m2}x_2 + \dots + a_{mn}x_n = b_m \end{cases}$$
  - Tutarlı ve Tutarsız Sistemler (Consistent and Inconsistent Systems): Bir lineer sistemin hiç çözümü yoksa sisteme **tutarsız** (inconsistent), en az bir çözümü varsa sisteme **tutarlı** (consistent) denir.
- Homojen Doğrusal Denklem Sistemleri (Homogeneous Linear Systems)
  - Sağ taraftaki sabit terimlerin tamamı sıfır ($b_1 = b_2 = \dots = b_m = 0$) olan lineer sisteme **homojen sistem** (homogeneous system) denir (ekrandan, 00:26:00 ve 01:20:30).
  - Her homojen sistemde $x_1 = x_2 = \dots = x_n = 0$ daima bir çözümdür; bu çözüme **aşikar (trivial) çözüm** veya **sıfır çözümü** (zero solution) denir.
  - Bilinmeyenlerin tamamının sıfır olmadığı ($x_1, \dots, x_n$ içinden en az birinin sıfırdan farklı olduğu) çözümlere ise **aşikar olmayan (non-trivial) çözüm** denir (ekrandan, 00:26:00).
- Lineer Sistemin Matris Gösterimi ve Genişletilmiş Matris (Matrix Form and Augmented Matrix)
  - Katsayılar matrisi (coefficient matrix) $A = [a_{ij}]_{m \times n}$, bilinmeyenler sütun vektörü $X = [x_1, x_2, \dots, x_n]^T$ ve sabitler sütun vektörü $b = [b_1, b_2, \dots, b_m]^T$ olmak üzere lineer sistem matris formunda $AX = b$ olarak yazılır (ekrandan, 00:34:00).
  - Katsayılar matrisi $A$'nın sağına $b$ sütun matrisinin eklenmesiyle elde edilen $[A \mid b]$ matrisine sistemin **genişletilmiş matrisi** (augmented matrix) denir; homojen sistem için genişletilmiş matris $[A \mid 0]$ biçimindedir (ekrandan, 00:37:30).
- Matrisin Rankı ve Gauss-Jordan Eliminasyon Yöntemi (Rank of a Matrix and Gauss-Jordan Elimination Method)
  - Bir $A$ matrisinin satır eşelon formundaki (REF) veya indirgenmiş satır eşelon formundaki (RREF) sıfırdan farklı satırların (nonzero rows) sayısına $A$'nın **rankı** denir ve $\text{rank}(A)$ ile gösterilir (ekrandan, 00:46:20 ve 00:50:45).
  - Gauss-Jordan eliminasyon yönteminde sistemin $[A \mid b]$ genişletilmiş matrisi elementer satır işlemleriyle indirgenmiş satır eşelon formuna (RREF) getirilir ve $\text{rank}(A)$ ile $\text{rank}([A \mid b])$ karşılaştırılır ($n$: bilinmeyen sayısı) (ekrandan, 00:58:15):
    1. **Çözüm Yok (No Solution / Inconsistent):** $\text{rank}(A) \neq \text{rank}([A \mid b])$ ise sistem tutarsızdır ve çözümü yoktur.
    2. **Tek Çözüm (Unique Solution):** $\text{rank}(A) = \text{rank}([A \mid b]) = n$ ise sistem tutarlıdır ve tek bir çözümü vardır.
    3. **Sonsuz Çoklukta Çözüm (Infinitely Many Solutions):** $\text{rank}(A) = \text{rank}([A \mid b]) = r < n$ ise sistem tutarlıdır ve $n - r$ tane keyfi parametreye (serbest değişkene) bağlı sonsuz çoklukta çözümü vardır.
  - Homojen sistemlerde ($AX = 0$) her zaman $\text{rank}(A) = \text{rank}([A \mid 0])$ olduğundan sistem **daima tutarlıdır** ($\text{rank}(A) = n$ ise yalnız sıfır çözümü vardır; $\text{rank}(A) = r < n$ ise $n - r$ parametreye bağlı sonsuz çözümü vardır) (ekrandan, 01:20:30).

## Hocanın Özellikle Vurguladığı Kısımlar

- Katsayılar Matrisini Yazmadan Önce Bilinmeyenleri Sıraya Dizme Zorunluluğu
  - Bir lineer sistemde denklemler karışık sırada verilmiş olabilir (örneğin dersteki örnekte 2. denklem $y = -2x + 5$ ve 3. denklem $9z - x - 5y + 7 = 0$ olarak verilmiştir). Genişletilmiş matrisi ($[A \mid b]$) yazmadan önce **tüm denklemlerde bilinmeyenler aynı sırayla** ($x, y, z$ veya $x_1, x_2, \dots, x_n$ sırasıyla) sol tarafa, sabit sayılar ise sağ tarafa yazılıp düzenlenmelidir; bir denklemde yer almayan bilinmeyenin katsayısı matrise $0$ olarak yazılır (ekrandan, 01:02:15).
- $\text{rank}(A)$ ile $\text{rank}([A \mid b])$ Ayrımı
  - İndirgenmiş satır eşelon formuna getirilen $[A \mid b]$ matrisinde $\text{rank}(A)$ bulunurken yalnızca dikey çizginin solundaki $A$ katsayılar matrisinin sıfırdan farklı satırları sayılır; $\text{rank}([A \mid b])$ bulunurken ise sağdaki $b$ sütununu da içeren tüm genişletilmiş matrisin sıfırdan farklı satırları sayılır (ekrandan, 01:11:15).
- Serbest Değişkenin (Keyfi Parametrenin) Seçimi
  - $\text{rank}(A) = r < n$ olduğunda $n - r$ adet bilinmeyen diğer bilinmeyenlere bağlı değildir (öncü $1$ içermeyen sütuna karşılık gelir). Örneğin $x = 2 - z$ ve $y = 1 + 2z$ sisteminde hem $x$ hem de $y$, $z$ değişkenine bağlıdır; ancak $z$'yi kısıtlayan hiçbir denklem yoktur. Bu nedenle $z = t \in \mathbb{R}$ keyfi bir parametre (arbitrary parameter) olarak seçilir ve çözüm kümesi $t$ cinsinden vektörel formda yazılır (ekrandan, 01:18:25).

## Kısa Tekrar Notları

- Lineer sistemin matris formu: $AX = b$ ($A$: $m \times n$ katsayılar matrisi, $X$: $n \times 1$ bilinmeyenler matrisi, $b$: $m \times 1$ sabitler matrisi).
- Genişletilmiş matris (Augmented matrix): $[A \mid b]$ (homojen sistemde $[A \mid 0]$).
- $\text{rank}(A) =$ $A$'nın REF veya RREF formundaki sıfırdan farklı satır sayısı.
- Rouché-Capelli / Gauss-Jordan çözüm kriterleri ($n$: bilinmeyen sayısı) (ekrandan, 00:58:15):
  - $\text{rank}(A) \neq \text{rank}([A \mid b]) \implies$ Çözüm yok (tutarsız / inconsistent).
  - $\text{rank}(A) = \text{rank}([A \mid b]) = n \implies$ Tek çözüm (unique solution).
  - $\text{rank}(A) = \text{rank}([A \mid b]) = r < n \implies n - r$ parametreye bağlı sonsuz çözüm (infinitely many solutions).
- Homojen sistem ($AX = 0$): Daima $\text{rank}(A) = \text{rank}([A \mid 0])$ olduğundan her zaman çözümü vardır.
  - $\text{rank}(A) = n \implies$ Yalnız aşikar (sıfır) çözüm ($X = 0$).
  - $\text{rank}(A) = r < n \implies n - r$ parametreye bağlı sonsuz (aşikar olmayan / non-trivial) çözüm.

## Detaylı Açıklamalar

- **Matrisin Rankını Bulma Örneği (ekrandan, 00:46:20 ve 00:50:45):**
  $$A = \begin{pmatrix} 1 & 0 & 1 & 0 & 1 \\ 2 & 0 & 2 & 0 & 2 \\ 1 & -1 & 0 & 1 & 0 \\ 2 & -2 & 0 & 2 & 0 \end{pmatrix} \sim C = \begin{pmatrix} 1 & 0 & 1 & 0 & 1 \\ 0 & 1 & 1 & -1 & 1 \\ 0 & 0 & 0 & 0 & 0 \\ 0 & 0 & 0 & 0 & 0 \end{pmatrix}$$
  $A$ matrisi elementer satır işlemleriyle indirgenmiş satır eşelon formu (RREF) olan $C$ matrisine dönüştürüldüğünde, $C$ matrisinde sıfırdan farklı yalnızca $2$ satır bulunduğu görülür. Dolayısıyla $\text{rank}(A) = 2$'dir.

- **Gauss-Jordan Eliminasyon Yöntemiyle Homojen Olmayan Lineer Sistem Çözümü (ekrandan, 01:02:15, 01:11:15 ve 01:18:25):**
  Derste $x - y + 3z = 1$, $y = -2x + 5$ ve $9z - x - 5y + 7 = 0$ denklemlerinden oluşan sistem adım adım çözülmüştür:
  1. **Denklemlerin Sıraya Dizilmesi:** Bilinmeyenler her denklemde $x, y, z$ sırasıyla sol tarafa, sabitler sağ tarafa yazılır (ekrandan, 01:02:15):
     $$\begin{cases} x - y + 3z = 1 \\ 2x + y + 0z = 5 \quad (\text{veya } -2x - y = -5) \\ -x - 5y + 9z = -7 \end{cases}$$
  2. **Genişletilmiş Matrisin Yazılması ve RREF'e İndirgenmesi (ekrandan, 01:11:15):**
     $$[A \mid b] = \left[\begin{array}{ccc|c} 1 & -1 & 3 & 1 \\ 2 & 1 & 0 & 5 \\ -1 & -5 & 9 & -7 \end{array}\right] \xrightarrow[\ r_1 + r_3 \to r_3\ ]{-2r_1 + r_2 \to r_2} \left[\begin{array}{ccc|c} 1 & -1 & 3 & 1 \\ 0 & 3 & -6 & 3 \\ 0 & -6 & 12 & -6 \end{array}\right]$$
     2. satırda öncü $1$ elde etmek için $\frac{1}{3}r_2 \to r_2$ uygulanır ve ardından 2. sütundaki diğer elemanları sıfırlamak için $r_2 + r_1 \to r_1$ ile $6r_2 + r_3 \to r_3$ işlemleri yapılır:
     $$\xrightarrow{\frac{1}{3}r_2 \to r_2} \left[\begin{array}{ccc|c} 1 & -1 & 3 & 1 \\ 0 & 1 & -2 & 1 \\ 0 & -6 & 12 & -6 \end{array}\right] \xrightarrow[\ 6r_2 + r_3 \to r_3\ ]{r_2 + r_1 \to r_1} \left[\begin{array}{ccc|c} 1 & 0 & 1 & 2 \\ 0 & 1 & -2 & 1 \\ 0 & 0 & 0 & 0 \end{array}\right]$$
  3. **Rank Analizi:** İndirgenmiş matriste hem $A$ kısmında hem de $[A \mid b]$ tamamında sıfırdan farklı $2$ satır vardır: $\text{rank}(A) = \text{rank}([A \mid b]) = 2$. Sistem tutarlıdır. Bilinmeyen sayısı $n = 3$ olduğundan ve $r = 2 < 3$ olduğundan sistemin $n - r = 3 - 2 = 1$ parametreye bağlı **sonsuz çoklukta çözümü** vardır.
  4. **Çözüm Kümesinin Yazılması (ekrandan, 01:18:25):**
     RREF matrisinin 1. satırından $x + z = 2 \implies x = 2 - z$, 2. satırından $y - 2z = 1 \implies y = 1 + 2z$ elde edilir. Keyfi parametre olarak $z = t \in \mathbb{R}$ seçildiğinde:
     $$x = 2 - t, \quad y = 1 + 2t, \quad z = t \implies \mathbf{x} = \begin{bmatrix} x \\ y \\ z \end{bmatrix} = \begin{bmatrix} 2 \\ 1 \\ 0 \end{bmatrix} + t \begin{bmatrix} -1 \\ 2 \\ 1 \end{bmatrix} \quad (t \in \mathbb{R})$$

- **Homojen Lineer Sistem Çözümü Örneği (ekrandan, 01:20:30 ve 01:28:00):**
  Yukarıdaki sistemin sağ tarafı sıfır yapılarak elde edilen homojen sistem çözülmüştür:
  $$\begin{cases} x - y + 3z = 0 \\ 2x + y = 0 \\ -x - 5y + 9z = 0 \end{cases}$$
  Aynı elementer satır işlemleri $[A \mid 0]$ matrisine uygulandığında:
  $$[A \mid 0] = \left[\begin{array}{ccc|c} 1 & -1 & 3 & 0 \\ 2 & 1 & 0 & 0 \\ -1 & -5 & 9 & 0 \end{array}\right] \sim \left[\begin{array}{ccc|c} 1 & 0 & 1 & 0 \\ 0 & 1 & -2 & 0 \\ 0 & 0 & 0 & 0 \end{array}\right]$$
  elde edilir (ekrandan, 01:28:00). Burada $\text{rank}(A) = \text{rank}([A \mid 0]) = 2 < 3$ olduğundan $3 - 2 = 1$ parametreye bağlı sonsuz çözüm vardır. İlk satırdan $x + z = 0 \implies x = -z$, ikinci satırdan $y - 2z = 0 \implies y = 2z$ bulunur. $z = t \in \mathbb{R}$ alındığında genel çözüm:
  $$\mathbf{x} = \begin{bmatrix} x \\ y \\ z \end{bmatrix} = \begin{bmatrix} -t \\ 2t \\ t \end{bmatrix} = t \begin{bmatrix} -1 \\ 2 \\ 1 \end{bmatrix} \quad (t \in \mathbb{R})$$
  biçimindedir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
