# Ders 12 Çalışma Özeti

## Genel Konular

- Doğrusal Denklem Sistemlerinin Çözüm Yöntemleri ve Rank Analizi Genel Tekrarı (Review of Linear Equation Systems & Rank Analysis)
  - $m$ denklem ve $n$ bilinmeyenden oluşan $AX = b$ doğrusal denklem sisteminin katsayılar matrisi $A = [a_{ij}]_{m \times n}$ ve genişletilmiş (ilaveli) matrisi $[A \mid b]$ olmak üzere sistemin çözümünde üç temel yöntem kullanılır:
    1. **Gauss-Jordan İndirgeme Yöntemi (Gauss-Jordan Reduction Method):** $[A \mid b]$ genişletilmiş matrisi elementer satır işlemleriyle (yalnızca satır işlemleri kullanılır) satırca indirgenmiş eşelon forma (RREF) veya satır eşelon forma (REF) getirilir. Sıfırdan farklı satır sayısına bakılarak $\text{rank}(A)$ ve $\text{rank}[A \mid b]$ belirlenir (ekrandan, 00:18:30):
       - $\text{rank}[A \mid b] \neq \text{rank}(A)$ ise sistemin **çözümü yoktur** (tutarsız / inconsistent).
       - $\text{rank}[A \mid b] = \text{rank}(A) = r$ ise sistemin **çözümü vardır** (tutarlı / consistent). Bu durumda:
         - $r = n$ (rank bilinmeyen sayısına eşit) ise sistemin **tek bir çözümü** (unique solution) vardır.
         - $r < n$ (rank bilinmeyen sayısından küçük) ise sistemin **$n - r$ tane keyfi değişkene (parametreye) bağlı sonsuz çoklukta çözümü** (infinitely many solutions) vardır.
    2. **Cramer Kuralı ve Ters Matris Yöntemi ($X = A^{-1}b$):** Her iki yöntemin uygulanabilmesi için iki zorunlu şart vardır: 1) Denklem sayısı bilinmeyen sayısına eşit olmalıdır ($n$ bilinmeyenli $n$ denklem, yani $A$ kare matris olmalıdır), 2) Katsayılar matrisinin determinantı sıfırdan farklı olmalıdır ($\det(A) \neq 0$). $\det(A) \neq 0$ olduğunda sistemin tek çözümü vardır ve Cramer kuralıyla $x_i = \frac{\det(A_i)}{\det(A)}$ veya ters matris yöntemiyle $X = A^{-1}b$ formülüyle bulunur. Eğer $\det(A) = 0$ çıkarsa bu iki yöntem kullanılamaz; sistem Gauss-Jordan yöntemiyle çözülmelidir (ekrandan, 00:18:30 ve 00:38:30).
  - **Homojen Doğrusal Denklem Sistemleri ($AX = 0$ — Homogeneous Systems):** Sağ taraftaki tüm sabitler sıfır ($b_1 = b_2 = \dots = b_m = 0$) olduğundan her zaman $\text{rank}[A \mid 0] = \text{rank}(A) = r$ eşitliği sağlanır; bu yüzden homojen bir sistemin **her zaman en az bir çözümü vardır** (ekrandan, 00:38:30):
    1. $r = n$ ise homojen sistemin **yalnızca sıfır (aşikar / trivial) çözümü** ($x_1 = x_2 = \dots = x_n = 0$) vardır.
    2. $r < n$ ise sistemin $n - r$ keyfi değişkene bağlı **sonsuz çoklukta (sıfırdan farklı / aşikar olmayan / nontrivial) çözümü** vardır.
- Vektörler, Üçgen/Paralelkenar Alanı, Prizma Hacmi ve Düzlemsellik Tekrarı (Review of Vectors, Area, Volume & Coplanarity)
  - $\mathbb{R}^3$'te $P(a_0, b_0, c_0)$ ve $Q(a_1, b_1, c_1)$ noktaları arasındaki vektör $\vec{PQ} = (a_1 - a_0, \, b_1 - b_0, \, c_1 - c_0)$ ve normu $\|\vec{PQ}\| = \sqrt{(a_1 - a_0)^2 + (b_1 - b_0)^2 + (c_1 - c_0)^2}$'dir. Birim vektör $\frac{\vec{v}}{\|\vec{v}\|}$'dir.
  - **İç Çarpım ($\mathbb{R}^n$):** $\vec{u} \cdot \vec{v} = \sum_{i=1}^n u_i v_i = \|\vec{u}\| \|\vec{v}\| \cos\theta \in \mathbb{R}$. Diklik koşulu: $\vec{u} \perp \vec{v} \iff \vec{u} \cdot \vec{v} = 0$.
  - **Vektörel Çarpım ($\mathbb{R}^3$):** $\vec{u} \times \vec{v}$ hem $\vec{u}$'ya hem $\vec{v}$'ye dik bir vektördür. Komşu kenarları $\vec{u}$ ve $\vec{v}$ olan **paralelkenarın alanı** $A = \|\vec{u} \times \vec{v}\| = \|\vec{u}\| \|\vec{v}\| \sin\theta$, komşu kenarları $\vec{u}$ ve $\vec{v}$ olan **üçgenin alanı** ise paralelkenarın alanının yarısıdır: $B = \frac{1}{2}\|\vec{u} \times \vec{v}\|$ (ekrandan, 01:19:30).
  - **Karma Çarpım ve Aynı Düzlemde Bulunma (Coplanarity) Koşulu ($\mathbb{R}^3$):** Komşu ayrıtları $\vec{u}, \vec{v}, \vec{w}$ olan paralelkenar prizmanın hacmi $V = |\vec{u} \cdot (\vec{v} \times \vec{w})|$'dir. Üç vektörün **aynı düzlemde yer alması** (coplanar / lie in the same plane) için gerek ve yeter şart oluşturdukları paralelkenar prizmanın hacminin (yani karma çarpımlarının) sıfır olmasıdır (ekrandan, 01:23:00):
    $$\vec{u}, \vec{v}, \vec{w} \text{ aynı düzlemdedir} \iff \vec{u} \cdot (\vec{v} \times \vec{w}) = \begin{vmatrix} u_1 & u_2 & u_3 \\ v_1 & v_2 & v_3 \\ w_1 & w_2 & w_3 \end{vmatrix} = 0$$
- Vektör Uzayları, Rasyonel Sayılar Kümesi ve Örnek Sınav Sorularının Çözümü (Vector Spaces & Sample Exam Questions)
  - Rasyonel sayılar kümesi $(\mathbb{Q}, +, \cdot)$ olağan toplama ve çarpma altında bir reel vektör uzayı **değildir**; çünkü $c = \sqrt{2} \in \mathbb{R}$ skaleri ile $q \in \mathbb{Q} \setminus \{0\}$ çarpıldığında $\sqrt{2}q \notin \mathbb{Q}$ olur (skalerle çarpmaya göre kapalı değildir) (ekrandan, 01:31:00).
  - Derste $4 \times 4$ sistemlerde Cramer kuralı, $3 \times 3$ sistemlerde ters matris yöntemi, parametreli sistemlerde tutarlılık ($a + 3b - 7c = 0$) ve çözüm durumu ($t$ parametresi analizi), üç vektörün düzlemselliği ve üç noktadan geçen düzleme dik vektör bulma üzerine örnek sınav soruları çözülmüştür (ekrandan, 00:44:30–01:26:30).

## Hocanın Özellikle Vurguladığı Kısımlar

- Genişletilmiş Matrisin Rankının Katsayılar Matrisinin Rankına Her Zaman Eşit Olmaması
  - $\text{rank}[A \mid b] = \text{rank}(A)$ eşitliği **yalnızca homojen sistemlerde ($b = 0$)** her zaman doğrudur. Homojen olmayan genel bir $AX = b$ sisteminde $A$'nın son satırı tamamen sıfırken $b$'nin son satırındaki eleman sıfırdan farklıysa $\text{rank}[A \mid b] \neq \text{rank}(A)$ olur ve sistemin çözümü olmaz (derste sözlü, 00:34:09).
- Parametreli Doğrusal Sistemlerde Gauss-Jordan / Satır İndirgeme Yönteminin Tercih Edilmesi
  - Sağ tarafta $a, b, c$ parametreleri içeren bir sistemin tutarlı (çözümlü) olma koşulunu bulurken veya katsayılarda $t$ parametresi bulunan bir sistemin hangi $t$ değerleri için çözümsüz, tek çözümlü ya da sonsuz çözümlü olduğunu belirlerken Cramer kuralı yerine **Gauss-Jordan / satır eşelon indirgemesi** kullanılmalıdır; böylece son satırdaki katsayı ile sağ taraf sabiti aynı anda incelenerek $\text{rank}(A)$ ile $\text{rank}[A \mid b]$ doğrudan karşılaştırılabilir (ekrandan, 00:57:00 ve 01:02:30).
- Rank Hesabında RREF Zorunluluğunun Olmaması
  - Bir matrisin rankı, satır eşelon formdaki (REF) veya satırca indirgenmiş eşelon formdaki (RREF) sıfırdan farklı satır sayısıdır (veya determinantı sıfırdan farklı olan en büyük kare alt matrisin boyutudur). Bu nedenle yalnızca rankı belirlemek için matrisi tam RREF formuna getirmek şart değildir; normal satır eşelon formuna (REF) getirmek rankı görmek için yeterlidir (derste sözlü, 01:06:49).
- Üçgenin Alanı ile Paralelkenarın Alanı Arasındaki $\frac{1}{2}$ Çarpanı ve Düzlemsellik
  - Komşu kenarları $\vec{u}$ ve $\vec{v}$ olan paralelkenarın alanı $\|\vec{u} \times \vec{v}\|$ iken, **üçgenin alanı** bunun yarısı olan $\frac{1}{2}\|\vec{u} \times \vec{v}\|$'dir. Üç vektörün aynı düzlemde olması ise karma çarpımlarının sıfır olması ($\vec{u} \cdot (\vec{v} \times \vec{w}) = 0$) demektir (ekrandan, 01:19:30 ve 01:23:00).

## Kısa Tekrar Notları

- $AX = b$ sisteminde ($A \in M_{m \times n}$):
  - $\text{rank}[A \mid b] \neq \text{rank}(A) \implies$ Çözüm yok (tutarsız / inconsistent).
  - $\text{rank}[A \mid b] = \text{rank}(A) = r = n \implies$ Tek çözüm (unique solution).
  - $\text{rank}[A \mid b] = \text{rank}(A) = r < n \implies n - r$ parametreye bağlı sonsuz çözüm.
- Homojen sistem $AX = 0$: Her zaman $\text{rank}[A \mid 0] = \text{rank}(A) = r$ olduğundan daima çözümlüdür. $r = n \implies$ yalnız sıfır çözümü ($X = 0$); $r < n \implies$ sonsuz (sıfırdan farklı) çözüm.
- Üçgen alanı: $B = \frac{1}{2}\|\vec{u} \times \vec{v}\|$. Paralelkenar alanı: $A = 2B = \|\vec{u} \times \vec{v}\|$.
- Paralelkenar prizma hacmi: $V = |\vec{u} \cdot (\vec{v} \times \vec{w})|$. Aynı düzlemde olma (coplanarity): $\vec{u} \cdot (\vec{v} \times \vec{w}) = 0$.
- Üç noktadan ($P, Q, R$) geçen düzleme dik vektör: $\vec{n} = \vec{PQ} \times \vec{PR}$.

## Detaylı Açıklamalar

- **Örnek Sınav Sorusu 1 — $4 \times 4$ Sistemde Cramer Kuralıyla Tek Bir Bilinmeyenin Bulunması (ekrandan, 00:44:30):**
  $$\begin{cases} x - 2z + t = 2 \\ 2x - y + 3t = 1 \\ 4x + y - 2z = 5 \\ 3x - y + 2t = -1 \end{cases}$$
  sisteminde sadece $t$ bilinmeyenini Cramer yöntemiyle bulunuz.
  - Bilinmeyenler sırasıyla $x, y, z, t$ ($x_1, x_2, x_3, x_4$) olduğundan olmayan terimlerin katsayısına $0$ yazılarak katsayılar matrisinin determinantı kurulur:
    $$\Delta = \det(A) = \begin{vmatrix} 1 & 0 & -2 & 1 \\ 2 & -1 & 0 & 3 \\ 4 & 1 & -2 & 0 \\ 3 & -1 & 0 & 2 \end{vmatrix} = 14 \neq 0$$
  - $t$ dördüncü bilinmeyen ($x_4$) olduğundan $A$'nın 4. sütununa $b = [2, 1, 5, -1]^T$ sabitler sütunu yazılarak $\det(A_4)$ hesaplanır:
    $$\det(A_4) = \begin{vmatrix} 1 & 0 & -2 & 2 \\ 2 & -1 & 0 & 1 \\ 4 & 1 & -2 & 5 \\ 3 & -1 & 0 & -1 \end{vmatrix} = 28 \implies t = \frac{\det(A_4)}{\det(A)} = \frac{28}{14} = 2$$

- **Örnek Sınav Sorusu 2 — $4 \times 4$ Sistemde Cramer Kuralıyla $y$ Bilinmeyeninin Bulunması (ekrandan, 00:51:25 ve 00:52:15):**
  Katsayılar matrisi $A = \begin{bmatrix} 1 & 1 & 3 & 0 \\ 0 & 1 & 2 & -1 \\ 0 & 1 & 0 & -5 \\ 2 & 0 & -1 & -2 \end{bmatrix}$ ve sağ taraf vektörü $b = \begin{bmatrix} 4 \\ 4 \\ 0 \\ 2 \end{bmatrix}$ olan doğrusal sistemde $y$ ($x_2$) bilinmeyenini Cramer kuralıyla bulunuz.
  - $-2R_1 + R_4 \to R_4$ satır işlemi ve 1. sütuna göre Laplace açılımıyla $\det(A) = \begin{vmatrix} 1 & 2 & -1 \\ 1 & 0 & -5 \\ -2 & -7 & -2 \end{vmatrix} = 16$ bulunur (Not: Çözüm kağıdında $-2(3) + (-1) = -7$ doğru yazılmış, $-2(1) + 0 = -2$ yerine sehven $-4$ yazılıp yine de $2(-22) - 4(-7) = -16$ ve $(-1)^{2+1}(-16) = 16$ elde edilmiştir).
  - 2. sütuna $b = [4, 4, 0, 2]^T$ yazılınca $\det(A_2) = \begin{vmatrix} 1 & 4 & 3 & 0 \\ 0 & 4 & 2 & -1 \\ 0 & 0 & 0 & -5 \\ 2 & 2 & -1 & -2 \end{vmatrix} = -80 \implies y = \frac{\det(A_2)}{\det(A)} = \frac{-80}{16} = -5$ bulunur.

- **Örnek Sınav Sorusu 3 — Ters Matris Yöntemiyle $3 \times 3$ Sistem Çözümü (ekrandan, 00:48:45, 00:49:10 ve 00:53:30):**
  $$\begin{cases} 2x + y - z = 5 \\ x - y + z = 1 \\ x + y - 2z = 4 \end{cases}$$
  sistemini katsayılar matrisinin tersini kullanarak çözünüz.
  - $A = \begin{bmatrix} 2 & 1 & -1 \\ 1 & -1 & 1 \\ 1 & 1 & -2 \end{bmatrix}$ ve $b = \begin{bmatrix} 5 \\ 1 \\ 4 \end{bmatrix}$ için $\det(A) = 3 \neq 0$ ve $\text{adj}(A) = \begin{bmatrix} 1 & 1 & 0 \\ 3 & -3 & -3 \\ 2 & -1 & -3 \end{bmatrix}$ (Not: Çözüm kağıdında $A_{13} = 1 - (-1) = 2$ kofaktörü ek matrisin $(3,1)$ elemanına sehven $-2$ olarak yazılmıştır; kağıttaki matrisle çarpıldığında $X = \frac{1}{3}\begin{bmatrix} 1 & 1 & 0 \\ 3 & -3 & -3 \\ -2 & -1 & -3 \end{bmatrix}\begin{bmatrix} 5 \\ 1 \\ 4 \end{bmatrix} = \begin{bmatrix} 2 \\ 0 \\ -23/3 \end{bmatrix}$, doğru $A_{13}=2$ ile çarpıldığında ise $X = \begin{bmatrix} 2 \\ 0 \\ -1 \end{bmatrix}$ bulunur).
  - Benzer şekilde $\begin{cases} 3x - y + 2z = -2 \\ 7x + y + 3z = 2 \\ 2x + 5y - 3z = 7 \end{cases}$ sistemi de $A = \begin{bmatrix} 3 & -1 & 2 \\ 7 & 1 & 3 \\ 2 & 5 & -3 \end{bmatrix}$ ve $B = \begin{bmatrix} -2 \\ 2 \\ 7 \end{bmatrix}$ yazılıp $X = A^{-1}B$ ile çözülür (ekrandan, 00:50:30).

- **Örnek Sınav Sorusu 4 — Sistemin Tutarlı (Consistent) Olması İçin $a, b, c$ Arasındaki Bağıntı (ekrandan, 00:57:00):**
  $$\begin{cases} x + 2y - 3z = a \\ 2x - 3y + z = b \\ x - y = c \end{cases}$$
  sisteminin tutarlı (çözümlü) olması için $a, b, c$ arasındaki bağıntıyı bulunuz.
  - Genişletilmiş matris elementer satır işlemleriyle eşelon forma indirgendiğinde:
    $$[A \mid b] = \begin{bmatrix} 1 & 2 & -3 & \mid & a \\ 2 & -3 & 1 & \mid & b \\ 1 & -1 & 0 & \mid & c \end{bmatrix} \sim \begin{bmatrix} 1 & 2 & -3 & \mid & a \\ 0 & 1 & -1 & \mid & (2a - b)/7 \\ 0 & 0 & 0 & \mid & (a + 3b - 7c)/21 \end{bmatrix}$$
  - Burada $\text{rank}(A) = 2$'dir. Sistemin tutarlı olması için $\text{rank}[A \mid b] = \text{rank}(A) = 2$ olmalıdır; bunun için 3. satırın sağ tarafındaki eleman sıfır olmalıdır:
    $$\frac{a + 3b - 7c}{21} = 0 \implies a + 3b - 7c = 0$$

- **Örnek Sınav Sorusu 5 — $t$ Parametresine Göre Çözümsüz, Tek Çözümlü ve Sonsuz Çözümlü Olma Durumu (ekrandan, 00:59:30, 01:02:30 ve 01:05:15):**
  $$\begin{cases} 3x + 4y - 2tz = 0 \\ 2x + 3y - tz = 1 \\ tx + (t+1)y - 6z = -1 \end{cases}$$
  sisteminin a) Çözümsüz, b) Tek çözümlü, c) Sonsuz çözümlü olması için tüm $t$ değerlerini belirleyiniz.
  - Genişletilmiş matris elementer satır işlemleriyle eşelon forma indirgendiğinde:
    $$[A \mid B] = \begin{bmatrix} 3 & 4 & -2t & \mid & 0 \\ 2 & 3 & -t & \mid & 1 \\ t & t+1 & -6 & \mid & -1 \end{bmatrix} \sim \begin{bmatrix} 1 & 1 & -t & \mid & -1 \\ 0 & 1 & t & \mid & 3 \\ 0 & 0 & t^2 - t - 6 & \mid & t - 4 \end{bmatrix} = \begin{bmatrix} 1 & 1 & -t & \mid & -1 \\ 0 & 1 & t & \mid & 3 \\ 0 & 0 & (t - 3)(t + 2) & \mid & t - 4 \end{bmatrix}$$
  - **a) Çözümsüz (Inconsistent) Olması ($\text{rank}(A) \neq \text{rank}[A \mid B]$):** $(t - 3)(t + 2) = 0$ ve $t - 4 \neq 0$ olmalıdır. Yani **$t = -2$ veya $t = 3$** için $\text{rank}(A) = 2 \neq \text{rank}[A \mid B] = 3$ olur ve çözüm yoktur.
  - **b) Tek Çözümlü (Unique Solution) Olması ($\text{rank}(A) = \text{rank}[A \mid B] = n = 3$):** $(t - 3)(t + 2) \neq 0$ olmalıdır. Yani **$t \in \mathbb{R} \setminus \{-2, 3\}$** ($t \neq -2$ ve $t \neq 3$) için tek çözüm vardır.
  - **c) Sonsuz Çözümlü Olması ($\text{rank}(A) = \text{rank}[A \mid B] = r < 3$):** Hem $(t - 3)(t + 2) = 0$ hem de $t - 4 = 0$ şartını aynı anda sağlayan bir $t$ değeri olmalıdır. Ancak $t = 4$ sağ tarafı sıfır yaparken $(t-3)(t+2)$'yi sıfır yapmaz; $t = -2$ ve $t = 3$ ise $t - 4$'ü sıfır yapmaz. Dolayısıyla sistemi sonsuz çözümlü yapan **hiçbir $t$ değeri yoktur** ($t \in \emptyset$).

- **Örnek Sınav Sorusu 6 ve 7 — Üç Vektörün Aynı Düzlemde Olması ve Düzleme Dik Vektör Bulma (ekrandan, 01:24:30 ve 01:26:30):**
  1. **Soru 4 (Düzlemsellik / Coplanarity):** $\vec{a} = (1, 4, -7)$, $\vec{b} = (2, -1, 4)$ ve $\vec{c} = (0, -9, 18)$ vektörlerinin aynı düzlemde (lie in the same plane) olup olmadığını belirleyiniz.
     - Paralelkenar prizmanın hacmi (karma çarpım):
       $$\vec{a} \cdot (\vec{b} \times \vec{c}) = \begin{vmatrix} 1 & 4 & -7 \\ 2 & -1 & 4 \\ 0 & -9 & 18 \end{vmatrix} = 1(-18 - (-36)) - 2(72 - 63) + 0 = 18 - 18 = 0$$
     - Hacim (karma çarpım) $0$ çıktığından bu üç vektör **aynı düzlemde yer alır**.
  2. **Soru 5 (Üç Noktayı İçeren Düzleme Dik Vektör):** $P = (3, 0, 1)$, $Q = (4, -2, 1)$ ve $R = (5, 3, -1)$ noktalarını içeren düzleme dik (orthogonal) bir vektör bulunuz.
     - Önce düzleme paralel olan (düzlem içindeki) iki vektör oluşturulur:
       $$\vec{PQ} = Q - P = (4 - 3, \, -2 - 0, \, 1 - 1) = (1, -2, 0)$$
       $$\vec{PR} = R - P = (5 - 3, \, 3 - 0, \, -1 - 1) = (2, 3, -2)$$
     - İki vektörün vektörel çarpımı her iki vektöre (dolayısıyla düzleme) dik olduğundan:
       $$\vec{PQ} \times \vec{PR} = \begin{vmatrix} \vec{i} & \vec{j} & \vec{k} \\ 1 & -2 & 0 \\ 2 & 3 & -2 \end{vmatrix} = (4 - 0)\vec{i} - (-2 - 0)\vec{j} + (3 - (-4))\vec{k} = 4\vec{i} + 2\vec{j} + 7\vec{k} = (4, 2, 7)$$

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
