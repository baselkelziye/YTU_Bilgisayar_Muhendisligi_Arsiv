# Ders 13 Çalışma Özeti

## Genel Konular

- Vektörlerin Doğrusal (Lineer) Bağımlılığı ve Bağımsızlığı (Linear Dependence and Independence of Vectors)
  - $V$ bir reel vektör uzayı, $\vec{v}_1, \vec{v}_2, \dots, \vec{v}_n \in V$ vektörler ve $x_1, x_2, \dots, x_n \in \mathbb{R}$ skalerler olsun.
    $$x_1 \vec{v}_1 + x_2 \vec{v}_2 + \dots + x_n \vec{v}_n = \vec{0}$$
    vektör denklemi (homojen doğrusal denklem sistemi) kurulduğunda (ekrandan, 00:11:30):
    1. **Doğrusal Bağımlılık (Linear Dependence):** Eğer bu denklemi sağlayan, **hepsi birden sıfır olmayan** (not all of them zero, yani en az bir $x_i \neq 0$ olan) $x_1, x_2, \dots, x_n \in \mathbb{R}$ skalerleri varsa (homojen sistemin sonsuz çözümü varsa), $\vec{v}_1, \vec{v}_2, \dots, \vec{v}_n$ vektörlerine **doğrusal bağımlı** (linearly dependent) denir.
    2. **Doğrusal Bağımsızlık (Linear Independence):** Eğer bu denklemi yalnızca **tümü sıfır olan** ($x_1 = x_2 = \dots = x_n = 0$, yani homojen sistemin yalnızca sıfır / aşikar çözümü varsa) skalerler sağlıyorsa, $\vec{v}_1, \vec{v}_2, \dots, \vec{v}_n$ vektörlerine **doğrusal bağımsız** (linearly independent) denir.
  - $S = \{\vec{v}_1, \vec{v}_2, \dots, \vec{v}_n\}$ kümesi de içindeki vektörler doğrusal bağımlı ise doğrusal bağımlı küme, doğrusal bağımsız ise doğrusal bağımsız küme olarak adlandırılır.
- Vektörlerin Doğrusal (Lineer) Birleşimi (Linear Combination of Vectors)
  - $V$ vektör uzayında bir $\vec{v} \in V$ vektörü, bazı $a_1, a_2, \dots, a_k \in \mathbb{R}$ reel sayıları (skalerleri) için:
    $$\vec{v} = a_1 \vec{v}_1 + a_2 \vec{v}_2 + \dots + a_k \vec{v}_k = \sum_{j=1}^k a_j \vec{v}_j$$
    biçiminde yazılabiliyorsa, $\vec{v}$ vektörüne $\vec{v}_1, \vec{v}_2, \dots, \vec{v}_k$ vektörlerinin bir **doğrusal birleşimi** (linear combination) denir (ekrandan, 00:38:30).
  - Bir $\vec{w}$ vektörünün verilen vektörlerin doğrusal birleşimi olup olmadığını belirlemek için kurulan doğrusal denklem sistemi çözülür: sistem tutarlıysa (çözümü varsa) $\vec{w}$ doğrusal birleşimdir; sistem tutarsızsa ($\text{rank}(A) \neq \text{rank}[A \mid b]$, çözümü yoksa) doğrusal birleşim olarak yazılamaz (ekrandan, 00:42:30 ve 00:46:30).
- Doğrusal Bağımlılık ve Bağımsızlık Teoremleri, Rank ve Determinant Kriterleri (Theorems on Linear Independence)
  - **Teorem 1:** $\vec{v}_1, \vec{v}_2, \dots, \vec{v}_m \in V$ doğrusal bağımsız $m$ vektör olsun. Eğer $\vec{v}_1, \vec{v}_2, \dots, \vec{v}_m, \vec{v}_{m+1}$ vektörleri doğrusal bağımlı ise, $\vec{v}_{m+1}$ vektörü $\vec{v}_1, \vec{v}_2, \dots, \vec{v}_m$ vektörlerinin bir doğrusal birleşimi olarak yazılabilir (ekrandan, 00:53:30).
  - **Teorem 2 (Alt Küme / Üst Küme İlişkisi):** $S_1 \subseteq S_2 \subseteq V$ olmak üzere:
    - a) Küçük küme $S_1$ doğrusal bağımlı ise, onu kapsayan büyük küme $S_2$ de **doğrusal bağımlıdır** ($r < m$ için $m$ vektörün içindeki $r$ vektör doğrusal bağımlıysa tüm $m$ vektör de doğrusal bağımlıdır).
    - b) Büyük küme $S_2$ doğrusal bağımsız ise, onun alt kümesi olan küçük küme $S_1$ de **doğrusal bağımsızdır** (ekrandan, 00:53:30).
  - **Teorem 3 (Rank ve Determinant Kriteri):** $\vec{v}_1, \dots, \vec{v}_m \in \mathbb{R}^n$ vektörlerinin satırlara (veya sütunlara) yazılmasıyla oluşan $A$ matrisinde $\text{rank}(A) = r$ ise, bu $m$ vektörün içinden $r$ tanesi doğrusal bağımsızdır ve kalan $m - r$ vektör bu $r$ vektörün doğrusal birleşimi olarak yazılabilir. Özel olarak **$n = m$ (vektör sayısı boyuta eşit, $A$ kare matris) ise**:
    $$m \text{ vektör doğrusal bağımsızdır} \iff \det(A) = |A| \neq 0$$
    ($|A| = 0$ ise vektörler doğrusal bağımlıdır) (ekrandan, 00:55:30).
  - **Temel Özellikler (ekrandan, 00:59:30–01:04:30):**
    1. Yalnızca sıfır vektöründen oluşan $S = \{\vec{0}\}$ kümesi **doğrusal bağımlıdır** (çünkü $5 \cdot \vec{0} = \vec{0}$ gibi $a_1 \neq 0$ skalerleri vardır).
    2. Sıfır vektörünü ($\vec{0}$) içeren herhangi bir $S$ vektör kümesi **doğrusal bağımlıdır**.
    3. Sıfırdan farklı tek bir vektörden oluşan $S = \{\vec{v}\}$ ($\vec{v} \neq \vec{0}$) kümesi **doğrusal bağımsızdır**.
    4. Bir vektör kümesinde iki vektör birbirine eşitse vektörler **doğrusal bağımlıdır**. Dolayısıyla doğrusal bağımsız bir kümedeki tüm vektörler birbirinden farklı (distinct) ve sıfırdan farklı (nonzero) olmak zorundadır.
- Germe Kümeleri / Geren Küme (Spanning Sets)
  - $V$ vektör uzayının bir $S = \{\vec{v}_1, \vec{v}_2, \dots, \vec{v}_r\} \subseteq V$ alt kümesi verildiğinde, $S$'deki vektörlerin **olası tüm doğrusal birleşimlerinin kümesine** $S$ tarafından **gerilen küme** (set spanned by $S$) denir ve $\text{span}(S)$ veya $\langle S \rangle$ ile gösterilir (ekrandan, 01:17:00):
    $$\text{span}(S) = \{k_1 \vec{v}_1 + k_2 \vec{v}_2 + \dots + k_r \vec{v}_r \mid k_1, k_2, \dots, k_r \in \mathbb{R}\}$$
  - $\text{span}(S)$ kümesi her zaman $V$ vektör uzayının bir **alt vektör uzayıdır (altuzayıdır / subspace)**.

## Hocanın Özellikle Vurguladığı Kısımlar

- Kare Katsayılar Matrisi Durumunda ($n = m$) Determinant ile Doğrusal Bağımsızlık Testi
  - $\mathbb{R}^n$ uzayında $n$ tane vektör verildiğinde ($n$ bilinmeyenli $n$ denklemli homojen sistem oluştuğunda), vektörler bir matrisin sütunlarına (veya satırlarına) yazılıp doğrudan determinantına bakılır: $\det(A) \neq 0$ ise homojen sistemin yalnızca sıfır çözümü vardır ve vektörler **doğrusal bağımsızdır**; $\det(A) = 0$ ise sistemin sonsuz çözümü vardır ve vektörler **doğrusal bağımlıdır** (ekrandan, 00:24:30 ve 00:55:30).
- Sıfır Vektörünün ($\{\vec{0}\}$) Doğrusal Bağımlı Olması
  - Öğrencilerin sıkça karıştırdığı noktalardan biri $S = \{\vec{0}\}$ kümesinin doğrusal bağımlı mı bağımsız mı olduğudur. $a_1 \vec{v}_1 = \vec{0}$ denkleminde $\vec{v}_1 = \vec{0}$ olduğunda $a_1 \cdot \vec{0} = \vec{0}$ eşitliği $a_1 = 5 \neq 0$ gibi sıfırdan farklı her reel sayı için sağlandığından $\{\vec{0}\}$ kümesi (ve sıfır vektörünü içeren her vektör kümesi) **doğrusal bağımlıdır** (derste sözlü ve ekrandan, 00:57:10–01:02:50).
- Küçük Küme ile Büyük Kümenin Doğrusal Bağımlılık/Bağımsızlık İlişkisi ($S_1 \subseteq S_2$)
  - $S_1 \subseteq S_2$ iken: **küçük küme ($S_1$) doğrusal bağımlıysa büyük küme ($S_2$) de doğrusal bağımlıdır**; buna karşılık **büyük küme ($S_2$) doğrusal bağımsızsa küçük küme ($S_1$) de doğrusal bağımsızdır** (ekrandan, 00:53:30).

## Kısa Tekrar Notları

- Doğrusal bağımsızlık tanımı: $a_1 \vec{v}_1 + a_2 \vec{v}_2 + \dots + a_n \vec{v}_n = \vec{0} \implies a_1 = a_2 = \dots = a_n = 0$. En az bir $a_i \neq 0$ bulunabiliyorsa doğrusal bağımlıdır.
- $\mathbb{R}^3$'te standart baz vektörleri $\vec{e}_1 = (1, 0, 0), \, \vec{e}_2 = (0, 1, 0), \, \vec{e}_3 = (0, 0, 1)$ doğrusal bağımsızdır.
- Doğrusal birleşim: $\vec{w} = x_1 \vec{v}_1 + \dots + x_k \vec{v}_k$ sisteminin çözümü varsa ($\text{rank}(A) = \text{rank}[A \mid b]$) $\vec{w}$ doğrusal birleşimdir; çözümü yoksa ($\text{rank}(A) \neq \text{rank}[A \mid b]$) değildir.
- $S_1 \subseteq S_2$: $S_1$ bağımlı $\implies S_2$ bağımlı; $S_2$ bağımsız $\implies S_1$ bağımsız.
- $\{\vec{0}\}$ bağımlıdır; $\vec{0} \in S \implies S$ bağımlıdır; $\vec{v} \neq \vec{0} \implies \{\vec{v}\}$ bağımsızdır.
- $\text{span}(S) = \langle S \rangle = \{k_1 \vec{v}_1 + \dots + k_r \vec{v}_r \mid k_i \in \mathbb{R}\}$ her zaman $V$'nin bir altuzayıdır.

## Detaylı Açıklamalar

- **$\mathbb{R}^3$ ve $M_{2 \times 2}$ Uzaylarında Doğrusal Bağımlılık/Bağımsızlık Örnekleri (ekrandan, 00:18:30, 00:24:30, 00:27:30 ve 00:33:30):**
  1. **Standart Baz Vektörleri ($\mathbb{R}^3$):** $\vec{e}_1 = (1, 0, 0), \, \vec{e}_2 = (0, 1, 0), \, \vec{e}_3 = (0, 0, 1)$ için $x_1\vec{e}_1 + x_2\vec{e}_2 + x_3\vec{e}_3 = (x_1, x_2, x_3) = (0, 0, 0) \implies x_1 = x_2 = x_3 = 0$ olduğundan **doğrusal bağımsızdır**.
  2. **$\mathbb{R}^3$'te Üç Vektörün Doğrusal Bağımlılığı:** $\{\vec{v}_1 = (1, 2, 0), \, \vec{v}_2 = (2, 0, 1), \, \vec{v}_3 = (3, 2, 1)\} \subset \mathbb{R}^3$ kümesi için $x_1\vec{v}_1 + x_2\vec{v}_2 + x_3\vec{v}_3 = (0, 0, 0)$ denklemi kurulduğunda katsayılar matrisinin determinantı:
     $$\begin{vmatrix} 1 & 2 & 3 \\ 2 & 0 & 2 \\ 0 & 1 & 1 \end{vmatrix} = (0 + 0 + 6) - (0 + 2 + 4) = 6 - 6 = 0$$
     çıkar (veya satır indirgemeyle $x_3 = r$ için $x_1 = x_2 = -r$ sonsuz çözümü bulunur). Dolayısıyla bu üç vektör **doğrusal bağımlıdır**.
  3. **$M_{2 \times 2}$ Matris Uzayında Doğrusal Bağımlılık/Bağımsızlık (ekrandan, 00:33:30):**
     $v_1 = \begin{bmatrix} 2 & 1 \\ 0 & 1 \end{bmatrix}, \, v_2 = \begin{bmatrix} 1 & 2 \\ 1 & 0 \end{bmatrix}, \, v_3 = \begin{bmatrix} 0 & -3 \\ -2 & 1 \end{bmatrix} \in M_{2 \times 2}$ matrisleri için $a_1 v_1 + a_2 v_2 + a_3 v_3 = \begin{bmatrix} 0 & 0 \\ 0 & 0 \end{bmatrix}$ denklemi kurulduğunda $3$ bilinmeyenli $4$ homojen denklem elde edilir:
     $$\begin{cases} 2a_1 + a_2 = 0 \\ a_1 + 2a_2 - 3a_3 = 0 \\ a_2 - 2a_3 = 0 \\ a_1 + a_3 = 0 \end{cases}$$
     3. denklemden $a_2 = 2a_3$ ve 4. denklemden $a_1 = -a_3$ ilk iki denklemde yerine yazıldığında $2(-a_3) + 2a_3 = 0$ ve $(-a_3) + 4a_3 - 3a_3 = 0$ özdeş olarak sağlanır ($a_3 = r \in \mathbb{R}$ serbest değişkendir, örneğin $v_1 - 2v_2 - v_3 = 0$). Sistemin sonsuz çözümü olduğundan $v_1, v_2, v_3$ matrisleri **doğrusal bağımlıdır** (Not: Hoca derste $m > n$ yani denklem sayısı bilinmeyen sayısından büyük olduğu için sonsuz çözüm çıktığını söylemiştir; ancak genel olarak $m > n$ olan bir homojen sistemde $\text{rank}(A) = n$ ise tek sıfır çözümü de çıkabilir, burada $\text{rank}(A) = 2 < 3$ olduğu için sonsuz çözüm vardır).

- **Doğrusal Birleşim (Linear Combination) Örnekleri (ekrandan, 00:42:30, 00:46:30 ve 00:49:15):**
  1. **Örnek 1:** $\vec{u} = (1, 2, -1)$ ve $\vec{v} = (6, 4, 2) \in \mathbb{R}^3$ vektörleri için $\vec{w} = (9, 2, 7)$ vektörünün bir doğrusal birleşim olduğunu, $\vec{w}' = (4, -1, 8)$ vektörünün ise olmadığını gösteriniz.
     - $\vec{w} = x_1\vec{u} + x_2\vec{v}$ için genişletilmiş matris indirgendiğinde:
       $$\begin{pmatrix} 1 & 6 & 9 \\ 2 & 4 & 2 \\ -1 & 2 & 7 \end{pmatrix} \sim \begin{pmatrix} 1 & 0 & -3 \\ 0 & 1 & 2 \\ 0 & 0 & 0 \end{pmatrix} \implies x_1 = -3, \, x_2 = 2$$
       bulunur; yani $\vec{w} = -3\vec{u} + 2\vec{v}$ bir doğrusal birleşimdir.
     - $\vec{w}' = x_1\vec{u} + x_2\vec{v}$ için genişletilmiş matris indirgendiğinde (Not: Slaytta 2. satırın sağ tarafında $-1$ yerine sehven $-2$ yazılmıştır, ancak her iki durumda da 3. satırda $0 = 1$ çelişkisi çıkar):
       $$\begin{pmatrix} 1 & 6 & \mid & 4 \\ 2 & 4 & \mid & -1 \\ -1 & 2 & \mid & 8 \end{pmatrix} \sim \begin{pmatrix} 1 & 0 & \mid & 0 \\ 0 & 1 & \mid & 0 \\ 0 & 0 & \mid & 1 \end{pmatrix}$$
       Burada $\text{rank}(A) = 2 \neq \text{rank}[A \mid b] = 3$ olduğundan sistem tutarsızdır (çözümü yoktur); $\vec{w}'$ vektörü $\vec{u}$ ve $\vec{v}$'nin doğrusal birleşimi olarak **yazılamaz**.
  2. **Örnek 2 ($k$ Parametresinin Bulunması — ekrandan, 00:49:15):**
     $\vec{w} = (1, -2, k) \in \mathbb{R}^3$ vektörünün $\vec{u} = (3, 0, -2)$ ve $\vec{v} = (2, -1, 5)$ vektörlerinin bir doğrusal birleşimi olarak yazılabilmesi için $k$ hangi değeri almalıdır?
     - $\vec{w} = a_1\vec{u} + a_2\vec{v} \implies \begin{cases} 3a_1 + 2a_2 = 1 \\ -a_2 = -2 \\ -2a_1 + 5a_2 = k \end{cases}$
     - 2. denklemden $a_2 = 2$ bulunur. 1. denklemde yerine yazılırsa $3a_1 + 4 = 1 \implies 3a_1 = -3 \implies a_1 = -1$ elde edilir.
     - 3. denklemde $a_1 = -1$ ve $a_2 = 2$ yerine yazılırsa: $k = -2(-1) + 5(2) = 2 + 10 = 12$ bulunur.

- **$\mathbb{R}^4$ Uzayında Doğrusal Bağımsızlık ve Doğrusal Birleşim Örneği (ekrandan, 01:09:30 ve 01:10:45):**
  $\vec{a} = (1, 0, 0, 1), \, \vec{b} = (0, -1, 2, 1), \, \vec{c} = (1, 2, 2, 1), \, \vec{d} = (-2, 1, 0, 0) \in \mathbb{R}^4$ vektörleri veriliyor.
  1. **Doğrusal Bağımsızlık Testi:** Vektörleri sütunlara yazıp $-R_1 + R_4 \to R_4$ işlemi ve 1. sütuna göre Laplace açılımı uyguladığımızda:
     $$\begin{vmatrix} 1 & 0 & 1 & -2 \\ 0 & -1 & 2 & 1 \\ 0 & 2 & 2 & 0 \\ 1 & 1 & 1 & 0 \end{vmatrix} = \begin{vmatrix} 1 & 0 & 1 & -2 \\ 0 & -1 & 2 & 1 \\ 0 & 2 & 2 & 0 \\ 0 & 1 & 0 & 2 \end{vmatrix} = 1\cdot(-1)^{1+1}\begin{vmatrix} -1 & 2 & 1 \\ 2 & 2 & 0 \\ 1 & 0 & 2 \end{vmatrix} = -4 - 2 - 8 = -14 \neq 0$$
     Determinant $-14 \neq 0$ olduğundan $\vec{a}, \vec{b}, \vec{c}, \vec{d}$ vektörleri **doğrusal bağımsızdır**.
  2. **$\vec{u} = (1, -1, 2, 1)$ Vektörünü $\vec{a}, \vec{b}, \vec{c}, \vec{d}$'nin Doğrusal Birleşimi Olarak Yazma:**
     $c_1\vec{a} + c_2\vec{b} + c_3\vec{c} + c_4\vec{d} = (1, -1, 2, 1)$ sisteminin genişletilmiş matrisi Gauss-Jordan yöntemiyle RREF formuna indirgendiğinde:
     $$[A \mid \mathbf{b}] = \begin{pmatrix} 1 & 0 & 1 & -2 & 1 \\ 0 & -1 & 2 & 1 & -1 \\ 0 & 2 & 2 & 0 & 2 \\ 1 & 1 & 1 & 0 & 1 \end{pmatrix} \sim \begin{pmatrix} 1 & 0 & 0 & 0 & 0 \\ 0 & 1 & 0 & 0 & \frac{6}{7} \\ 0 & 0 & 1 & 0 & \frac{1}{7} \\ 0 & 0 & 0 & 1 & -\frac{3}{7} \end{pmatrix}$$
     Buradan $c_1 = 0, \, c_2 = \frac{6}{7}, \, c_3 = \frac{1}{7}, \, c_4 = -\frac{3}{7}$ bulunur (slaytta son katsayı sehven $c_3 = -3/7$ olarak basılmıştır, doğrusu $c_4 = -3/7$'dir); yani $\vec{u} = 0\vec{a} + \frac{6}{7}\vec{b} + \frac{1}{7}\vec{c} - \frac{3}{7}\vec{d}$'dir.

- **Germe Kümesi (Spanning Set) Örnekleri (ekrandan, 01:17:00 ve 01:19:15):**
  1. **$M_{2 \times 3}$ Uzayında Gerilen Küme:**
     $S = \left\{ v_1 = \begin{bmatrix} 1 & 0 & 0 \\ 0 & 0 & 0 \end{bmatrix}, \, v_2 = \begin{bmatrix} 0 & 1 & 0 \\ 0 & 0 & 0 \end{bmatrix}, \, v_3 = \begin{bmatrix} 0 & 0 & 0 \\ 0 & 1 & 0 \end{bmatrix}, \, v_4 = \begin{bmatrix} 0 & 0 & 0 \\ 0 & 0 & 1 \end{bmatrix} \right\} \subset M_{2 \times 3}$ kümesinin gerdiği altuzay:
     $$\text{span}(S) = \{a v_1 + b v_2 + c v_3 + d v_4 \mid a, b, c, d \in \mathbb{R}\} = \left\{ \begin{bmatrix} a & b & 0 \\ 0 & c & d \end{bmatrix} \,\middle|\, a, b, c, d \in \mathbb{R} \right\}$$
  2. **$\mathbb{R}^4$ Uzayında Gerilen Küme:**
     $S = \{\vec{u} = (1, -2, 1, 3), \, \vec{v} = (0, 2, -1, 0)\} \subset \mathbb{R}^4$ kümesinin gerdiği altuzay:
     $$\text{span}(S) = \{a(1, -2, 1, 3) + b(0, 2, -1, 0) \mid a, b \in \mathbb{R}\} = \{(a, \, -2a + 2b, \, a - b, \, 3a) \mid a, b \in \mathbb{R}\}$$

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
