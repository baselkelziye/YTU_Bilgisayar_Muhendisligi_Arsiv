# Ders 11 Çalışma Özeti

## Genel Konular

- Doğrusal Denklem Sistemi Çözüm Yöntemlerinin İşlem Sayısı (Verimlilik) Karşılaştırması (Approximate Operation Counts for $Ax = b$)
  - Tersinir bir $n \times n$ boyutlu $A$ matrisi ve büyük $n$ değerleri için $Ax = b$ doğrusal denklem sistemini çözerken kullanılan yöntemlerin yaklaşık toplama (additions) ve çarpma (multiplications) işlem sayıları şöyledir (ekrandan, 00:05:30):
    1. **Gauss-Jordan eliminasyonu veya Gauss eliminasyonu (veya satır indirgemeyle $\det(A)$ hesabı):** yaklaşık $\frac{n^3}{3}$ toplama ve $\frac{n^3}{3}$ çarpma işlemi.
    2. **$[A \mid I]$ matrisini $[I \mid A^{-1}]$ biçimine indirgeyerek veya $x = A^{-1}b$ ters matris yöntemiyle çözüm:** yaklaşık $n^3$ toplama ve $n^3$ çarpma işlemi (Gauss eliminasyonunun $3$ katı işlem gerektirir).
    3. **Cramer kuralı ile çözüm:** yaklaşık $\frac{n^4}{3}$ toplama ve $\frac{n^4}{3}$ çarpma işlemi.
  - Büyük $n$ değerleri için $Ax = b$ sistemini çözmede **en iyi (en verimli) yöntem** Gauss veya Gauss-Jordan eliminasyonudur; **en kötü (en yavaş) yöntem** ise Cramer kuralıdır.
- Reel Vektör Uzayı Tanımı ve 10 Aksiyomu (Real Vector Spaces — Definition 172)
  - Bir **reel vektör uzayı** (real vector space), üzerinde **vektör toplama** ($\oplus$, vector addition) ve **skalerle çarpma** ($\odot$, scalar multiplication) adı verilen iki işlem tanımlı olan ve aşağıdaki **2 kapalılık koşulu ile 8 aksiyomu (toplam 10 şartı)** sağlayan boş olmayan bir $V$ kümesidir (ekrandan, 00:15:30 ve 00:19:45):
    - **a) Toplamaya Göre Kapalılık (Closure under $\oplus$):** Her $\mathbf{u}, \mathbf{v} \in V$ için $\mathbf{u} \oplus \mathbf{v} \in V$ olmalıdır.
      1. **Değişme Özelliği (Commutative):** Her $\mathbf{u}, \mathbf{v} \in V$ için $\mathbf{u} \oplus \mathbf{v} = \mathbf{v} \oplus \mathbf{u}$.
      2. **Birleşme Özelliği (Associative):** Her $\mathbf{u}, \mathbf{v}, \mathbf{w} \in V$ için $\mathbf{u} \oplus (\mathbf{v} \oplus \mathbf{w}) = (\mathbf{u} \oplus \mathbf{v}) \oplus \mathbf{w}$.
      3. **Toplamsal Birim / Sıfır Vektörü (Additive Identity / Zero Vector):** Her $\mathbf{u} \in V$ için $\mathbf{u} \oplus \mathbf{0} = \mathbf{0} \oplus \mathbf{u} = \mathbf{u}$ olacak biçimde tek bir $\mathbf{0} \in V$ sıfır vektörü vardır.
      4. **Toplamsal Ters / Negatif Vektör (Additive Inverse / Negative of $\mathbf{u}$):** Her $\mathbf{u} \in V$ için $\mathbf{u} \oplus (-\mathbf{u}) = (-\mathbf{u}) \oplus \mathbf{u} = \mathbf{0}$ olacak biçimde tek bir $-\mathbf{u} \in V$ elemanı vardır.
    - **b) Skalerle Çarpmaya Göre Kapalılık (Closure under $\odot$):** Her $\mathbf{u} \in V$ ve her $c \in \mathbb{R}$ skaleri için $c \odot \mathbf{u} \in V$ olmalıdır.
      5. **Vektör Toplamı Üzerine Dağılma:** Her $\mathbf{u}, \mathbf{v} \in V$ ve $c \in \mathbb{R}$ için $c \odot (\mathbf{u} \oplus \mathbf{v}) = (c \odot \mathbf{u}) \oplus (c \odot \mathbf{v})$.
      6. **Skaler Toplamı Üzerine Dağılma:** Her $\mathbf{u} \in V$ ve $c, d \in \mathbb{R}$ için $(c + d) \odot \mathbf{u} = (c \odot \mathbf{u}) \oplus (d \odot \mathbf{u})$.
      7. **Skaler Çarpım Birleşme Özelliği:** Her $\mathbf{u} \in V$ ve $c, d \in \mathbb{R}$ için $c \odot (d \odot \mathbf{u}) = (cd) \odot \mathbf{u}$.
      8. **Çarpımsal Birim Özelliği:** Her $\mathbf{u} \in V$ için $1 \odot \mathbf{u} = \mathbf{u}$.
- Temel Vektör Uzayı Örnekleri ve Vektör Uzayı Olmayan Kümeler (Examples and Non-Examples of Vector Spaces)
  - **Vektör Uzayı Olan Kümeler:** $\mathbb{R}^n$ ($n \times 1$ sütun matrisleri uzayı), $R_n$ ($1 \times n$ satır matrisleri uzayı), $M_{m \times n}$ ($m \times n$ boyutlu tüm reel matrisler uzayı), $\mathbb{R}$ (olağan toplama ve çarpmayla reel sayılar kümesi), izi sıfır olan $2 \times 2$ matrisler kümesi ($V = \{A \in M_{2 \times 2} \mid \text{Tr}(A) = a + d = 0\}$), derecesi en çok $n$ olan polinomlar ile sıfır polinomunun kümesi ($P_n$) ve $\mathbb{R}$ üzerinde tanımlı tüm reel değerli sürekli fonksiyonlar uzayı ($C(-\infty, \infty)$) standart toplama ve skalerle çarpma işlemleri altında birer vektör uzayıdır (ekrandan, 00:34:30, 00:39:30, 00:50:30 ve 00:57:30).
  - **Vektör Uzayı Olmayan Kümeler:** $\mathbf{u} \oplus \mathbf{v} = u - v$ (olağan çıkarma) ve $c \odot \mathbf{u} = cu$ ile tanımlı $V = \mathbb{R}$ kümesi (1, 2, 3, 4 ve 6. özellikler sağlanmaz) ve olağan toplama/çarpmayla tüm tam sayılar kümesi $V = \mathbb{Z}$ ($c = \sqrt{3} \in \mathbb{R}$ için $\sqrt{3}u \notin \mathbb{Z}$, yani skalerle çarpmaya göre kapalı değildir) birer reel vektör uzayı **değildir** (ekrandan, 01:03:30 ve 01:08:30).
- Alt Vektör Uzayı (Altuzay) Tanımı ve Teoremi (Subspaces — Definition 183 & Theorem 184)
  - Bir $(V, \oplus, \odot)$ vektör uzayının boş olmayan bir $W \subseteq V$ alt kümesi, $V$ üzerindeki aynı $\oplus$ ve $\odot$ işlemleri altında kendi başına bir vektör uzayı oluyorsa $W$'ye $V$'nin bir **alt vektör uzayı (altuzayı / subspace)** denir.
  - **Teorem 184 (Altuzay Kriteri):** Boş olmayan bir $W \subseteq V$ alt kümesinin $V$'nin bir altuzayı olması için gerek ve yeter şart yalnızca şu **iki kapalılık koşulunun** sağlanmasıdır (ekrandan, 01:15:30):
    - **a)** Her $\mathbf{u}, \mathbf{v} \in W$ için $\mathbf{u} \oplus \mathbf{v} \in W$ (toplamaya göre kapalılık),
    - **b)** Her $c \in \mathbb{R}$ skaleri ve her $\mathbf{u} \in W$ için $c \odot \mathbf{u} \in W$ (skalerle çarpmaya göre kapalılık).

## Hocanın Özellikle Vurguladığı Kısımlar

- Bir Kümenin Vektör Uzayı Olup Olmadığını Kontrol Etme Sırası (Checklist — Remark 182)
  - Verilen bir $V$ kümesinin vektör uzayı olup olmadığını incelerken 10 özelliği rastgele kontrol etmek yerine şu kontrol listesi (checklist) izlenmelidir (ekrandan, 01:03:30 ve 01:08:30):
    1. Önce **a) $\oplus$ işlemine göre kapalılık** ve **b) $\odot$ skalerle çarpma işlemine göre kapalılık** kontrol edilir. İkisinden biri bile sağlanmıyorsa (örneğin tam sayılar kümesi $\mathbb{Z}$'de $\sqrt{3} \cdot u \notin \mathbb{Z}$ olması gibi) küme vektör uzayı değildir; diğer özelliklere bakmaya gerek kalmaz.
    2. Kapalılıklar sağlanıyorsa hemen **3. özellik olan sıfır vektörünün ($\mathbf{0} \in V$) varlığı** ve ardından **4. özellik olan toplamsal tersin ($-\mathbf{u} \in V$) kümede olup olmadığı** kontrol edilir. Sıfır elemanı yoksa küme vektör uzayı değildir.
- Negatif (Toplamsal Ters) Elemanın da Küme Koşulunu Sağlaması Gerektiği
  - İzi sıfır olan $2 \times 2$ matrisler uzayında ($V = \{A \in M_{2 \times 2} \mid \text{Tr}(A) = 0\}$) 4. özelliği (toplamsal ters) gösterirken yalnızca $A + (-A) = 0$ yazmak yeterli değildir; $-A$ matrisinin de gerçekten $V$ kümesine ait olduğu, yani $\text{Tr}(-A) = -a + (-d) = -(a+d) = 0$ olduğu mutlaka gösterilmelidir (ekrandan, 00:42:40).
- Derecesi En Çok $n$ Olan Polinomlar ($P_n$) ile Derecesi Tam $2$ Olan Polinomların Farkı
  - Derecesi $\le n$ olan polinomlar ile sıfır polinomundan oluşan $P_n$ kümesi tüm polinomlar uzayı $P$'nin bir **altuzayıdır** (ve $P_n$, $P_{n+1}$'in altuzayıdır). Buna karşılık derecesi **tam olarak $2$'ye eşit** olan polinomlar kümesi $V$ bir altuzay **değildir**; çünkü $2t^2 + 3t + 1 \in V$ ile $-2t^2 + t + 2 \in V$ polinomlarının toplamı $4t + 3$ olup derecesi $1$'dir ($V$'de değildir, toplamaya göre kapalı değildir) (ekrandan, 01:15:30 ve 01:24:30).
- Altuzay Testinde Sıfır Vektörü ve Negatif Skaler ($c = -1$) Kullanımı
  - Bir $W \subseteq V$ alt kümesinin altuzay olduğunu kanıtlamak için Teorem 184'teki iki kapalılık koşulunu ($\mathbf{u} \oplus \mathbf{v} \in W$ ve $c \odot \mathbf{u} \in W$) göstermek yeterlidir; sıfır vektörünü ayrıca kontrol etmeye gerek yoktur ($c = 0$ alındığında $0 \odot \mathbf{u} = \mathbf{0} \in W$ otomatik sağlanır). Ancak bir kümenin altuzay **olmadığını** hızlıca görmek için $\mathbf{0} \in W$ olup olmadığına veya $c = -1$ gibi negatif bir skalerle çarpıldığında küme dışına çıkıp çıkmadığına bakılır. Örneğin $W = \{(a, b, c) \in \mathbb{R}^3 \mid a \ge 0\}$ kümesinde $c = -1$ alınırsa $(-a, -b, -c) \notin W$ olduğundan $W$ skalerle çarpmaya göre kapalı değildir ve altuzay değildir (ekrandan, 01:36:30).

## Kısa Tekrar Notları

- İşlem karmaşıklığı ($n \times n$ tersinir $A$ için $Ax = b$): Gauss / Gauss-Jordan $\approx \frac{n^3}{3}$ (en iyi), Ters matris ($x = A^{-1}b$) $\approx n^3$, Cramer kuralı $\approx \frac{n^4}{3}$ (en kötü).
- Vektör uzayı $(V, \oplus, \odot)$: $V$'nin elemanlarına **vektör** (vectors), $\mathbb{R}$'nin elemanlarına **skaler** (scalars) denir. Sıfır vektörü $\mathbf{0}$ ve her $\mathbf{u}$'nun negatifi $-\mathbf{u}$ **tektir** (unique).
- Polinom derecesi: Sıfırdan farklı katsayıya sahip en yüksek kuvvetli terimin üssüdür. $\deg(2t + 1) = 1$, sıfırdan farklı sabit polinomun derecesi $\deg(p(t) = 3) = 0$'dır; **sıfır polinomunun ($p(t) = 0$) derecesi yoktur (has no degree)** (ekrandan, 00:50:30).
- $P_n$: Derecesi $\le n$ olan polinomlar ile sıfır polinomunun kümesidir ve vektör uzayıdır.
- Her $V$ vektör uzayının en az iki aşikar (trivial) altuzayı vardır: kendisi ($V$) ve yalnızca sıfır vektöründen oluşan **sıfır altuzayı** (zero subspace, $\{\mathbf{0}\}$).
- Teorem 184: $\emptyset \neq W \subseteq V$ altuzaydır $\iff$ (a) $\forall \mathbf{u}, \mathbf{v} \in W \implies \mathbf{u} \oplus \mathbf{v} \in W$ ve (b) $\forall c \in \mathbb{R}, \forall \mathbf{u} \in W \implies c \odot \mathbf{u} \in W$.

## Detaylı Açıklamalar

- **İzi Sıfır Olan $2 \times 2$ Matrisler Kümesinin Vektör Uzayı Olduğunun Gösterilmesi (Örnek 177 — ekrandan, 00:34:30 ve 00:39:30):**
  $V = \left\{ A = \begin{bmatrix} a & b \\ c & d \end{bmatrix} \in M_{2 \times 2} \,\middle|\, \text{Tr}(A) = a + d = 0 \right\}$ kümesi standart matris toplama ($\oplus$) ve skalerle çarpma ($\odot$) işlemleri altında bir vektör uzayıdır. Seçilmiş özelliklerin doğrulaması:
  - **Özellik (a) — Toplamaya Göre Kapalılık:** $A = \begin{bmatrix} a & b \\ c & d \end{bmatrix} \in V$ ve $B = \begin{bmatrix} r & s \\ t & p \end{bmatrix} \in V$ olsun. Bu durumda $\text{Tr}(A) = a + d = 0$ ve $\text{Tr}(B) = r + p = 0$'dır. Toplam matrisi $A \oplus B = \begin{bmatrix} a+r & b+s \\ c+t & d+p \end{bmatrix}$ için:
    $$\text{Tr}(A \oplus B) = (a + r) + (d + p) = (a + d) + (r + p) = 0 + 0 = 0$$
    olduğundan $A \oplus B \in V$'dir ($V$ toplamaya göre kapalıdır).
  - **Özellik (3) — Sıfır Vektörü:** $2 \times 2$ sıfır matrisi $\mathbf{0} = \begin{bmatrix} 0 & 0 \\ 0 & 0 \end{bmatrix}$ için $\text{Tr}(\mathbf{0}) = 0 + 0 = 0$ olduğundan $\mathbf{0} \in V$'dir ve $A \oplus \mathbf{0} = \mathbf{0} \oplus A = A$ şartını sağlar.
  - **Özellik (4) — Toplamsal Ters:** $A \in V$ ($\text{Tr}(A) = a + d = 0$) için $C = -A = \begin{bmatrix} -a & -b \\ -c & -d \end{bmatrix}$ matrisinin izi $\text{Tr}(C) = -a + (-d) = -(a + d) = 0$ olduğundan $-A \in V$'dir ve $A \oplus (-A) = (-A) \oplus A = \mathbf{0}$ şartını sağlar.
  - **Özellik (b) — Skalerle Çarpmaya Göre Kapalılık:** Her $k \in \mathbb{R}$ ve $A \in V$ için $k \odot A = \begin{bmatrix} ka & kb \\ kc & kd \end{bmatrix}$ matrisinin izi $\text{Tr}(k \odot A) = ka + kd = k(a + d) = k \cdot 0 = 0$ olduğundan $k \odot A \in V$'dir.

- **Vektör Uzayı Olmayan Küme Örnekleri (Örnek 180 ve 181 — ekrandan, 00:57:30, 01:03:30 ve 01:08:30):**
  1. **Örnek 180 ($u \oplus v = u - v$ Çıkarma İşlemli Reel Sayılar Kümesi):**
     $V = \mathbb{R}$ üzerinde $\mathbf{u} \oplus \mathbf{v} = u - v$ (olağan çıkarma) ve $c \odot \mathbf{u} = cu$ (olağan çarpma) tanımlansın.
     - İki reel sayının farkı ve çarpımı yine reel sayı olduğundan (a) ve (b) kapalılık şartları ile (5), (7), (8) özellikleri sağlanır.
     - Ancak **1. özellik (değişme)** sağlanmaz: $\mathbf{u} \oplus \mathbf{v} = u - v \neq v - u = \mathbf{v} \oplus \mathbf{u}$.
     - **3. özellik (sıfır elemanı)** sağlanmaz: $\mathbf{u} \oplus \mathbf{v} = \mathbf{u}$ ve $\mathbf{v} \oplus \mathbf{u} = \mathbf{u}$ şartını aynı anda sağlayan bir $v$ yoktur ($v = 0$ alınsa $u - 0 = u$ olur ama $0 - u = -u \neq u$ olur). Benzer şekilde (2) ve (4) de sağlanmaz.
     - **6. özellik** de sağlanmaz: $(c + d) \odot \mathbf{u} = (c + d)u = cu + du$ iken $(c \odot \mathbf{u}) \oplus (d \odot \mathbf{u}) = cu \oplus du = cu - du$ olur ve birbirine eşit değildir. Dolayısıyla $V$ bir vektör uzayı değildir.
  2. **Örnek 181 (Tam Sayılar Kümesi $V = \mathbb{Z}$):**
     $V = \mathbb{Z}$ üzerinde olağan toplama ve olağan çarpma tanımlansın. Sıfırdan farklı bir $u \in \mathbb{Z}$ (örneğin $u = 1$) ve $c = \sqrt{3} \in \mathbb{R}$ skaleri alındığında $c \odot u = \sqrt{3}u \notin \mathbb{Z}$ olur. Yani (b) skalerle çarpmaya göre kapalılık şartı sağlanmadığından $(\mathbb{Z}, +, \cdot)$ bir reel vektör uzayı değildir.

- **Alt Vektör Uzayı (Subspace) Örnekleri (ekrandan, 01:24:30, 01:27:30, 01:31:30, 01:34:30 ve 01:36:30):**
  1. **$\mathbb{R}^3$'ün Altuzayı (Örnek 188 — ekrandan, 01:27:30):**
     $W = \left\{ \begin{bmatrix} a \\ b \\ a+b \end{bmatrix} \,\middle|\, a, b \in \mathbb{R} \right\} \subseteq \mathbb{R}^3$ (3. bileşeni ilk iki bileşeninin toplamı olan vektörler kümesi).
     - $\mathbf{u} = \begin{bmatrix} a_1 \\ b_1 \\ a_1+b_1 \end{bmatrix}, \mathbf{v} = \begin{bmatrix} a_2 \\ b_2 \\ a_2+b_2 \end{bmatrix} \in W$ için $\mathbf{u} \oplus \mathbf{v} = \begin{bmatrix} a_1+a_2 \\ b_1+b_2 \\ (a_1+a_2)+(b_1+b_2) \end{bmatrix} \in W$ (toplamaya göre kapalı).
     - $c \in \mathbb{R}$ için $c \odot \mathbf{u} = \begin{bmatrix} ca_1 \\ cb_1 \\ ca_1+cb_1 \end{bmatrix} \in W$ (skalerle çarpmaya göre kapalı). O halde Teorem 184 gereği $W$, $\mathbb{R}^3$'ün bir altuzayıdır.
  2. **$M_{2 \times 2}(\mathbb{R})$'nin Altuzayı (ekrandan, 01:31:30):**
     $B = \left\{ \begin{bmatrix} a & b \\ 0 & c \end{bmatrix} \,\middle|\, c = a + b, \, a, b, c \in \mathbb{R} \right\} \subseteq M_{2 \times 2}(\mathbb{R})$ kümesi için:
     - İki elemanın toplamı $\begin{bmatrix} a & b \\ 0 & c \end{bmatrix} + \begin{bmatrix} x & y \\ 0 & z \end{bmatrix} = \begin{bmatrix} a+x & b+y \\ 0 & c+z \end{bmatrix}$ olup $c+z = (a+b) + (x+y) = (a+x) + (b+y)$ şartını sağladığından $B$'dedir.
     - $r \in \mathbb{R}$ ile çarpımı $\begin{bmatrix} ra & rb \\ 0 & rc \end{bmatrix}$ olup $rc = r(a+b) = ra + rb$ şartını sağladığından $B$'dedir. Dolayısıyla $B$, $M_{2 \times 2}(\mathbb{R})$'nin bir altuzayıdır.
  3. **$\mathbb{R}^2$'nin Altuzayı ($x$-Ekseni — ekrandan, 01:34:30):**
     $A = \{(x, 0) \mid x \in \mathbb{R}\} \subseteq \mathbb{R}^2$ kümesi, $\mathbf{u} + \mathbf{v} = (x, 0) + (y, 0) = (x+y, 0) \in A$ ve $c\mathbf{u} = (cx, 0) \in A$ olduğundan $\mathbb{R}^2$'nin bir altuzayıdır.
  4. **Altuzay Olmayan Küme Örneği (ekrandan, 01:36:30):**
     $W = \{(a, b, c) \mid a \ge 0 \text{ ve } a, b, c \in \mathbb{R}\} \subseteq \mathbb{R}^3$ kümesi $\mathbb{R}^3$'ün altuzayı **değildir**. Çünkü $a > 0$ olan bir $\mathbf{u} = (a, b, c) \in W$ vektörü $c = -1 \in \mathbb{R}$ skaleri ile çarpıldığında $(-1)\mathbf{u} = (-a, -b, -c)$ elde edilir ve birinci bileşen $-a < 0$ olduğundan $(-1)\mathbf{u} \notin W$ olur (skalerle çarpmaya göre kapalı değildir).

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
